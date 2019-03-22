/*
 * ****************************************************************************
 * Original Source: Copyright (c) 2009-2011 Luaj.org. All rights reserved.
 * Modifications: Copyright (c) 2015-2017 SquidDev, Copyright (c) 2019 Galaxtone
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * ****************************************************************************
 */

function arraycopy(src: i32[], srcPos: i32, dest: i32[], destPos: i32, length: i32): void {
  for (var i: i32 = 0; i < length; i++) {
    dest[destPos + i] = src[srcPos + i];
  }
}

class LuaValue {}

class LuaString extends LuaValue {
  static readonly RECENT_STRINGS_CACHE_SIZE: i32 = 128;
  static readonly RECENT_STRINGS_MAX_LENGTH: i32 = 32;
  
  private bytes: i32[];
  private length: i32;
  private offset: i32;
  
  private hashcode: i32;

  private static Cache = class Cache {
		readonly recentShortStrings: LuaString[] = new LuaString[LuaString.RECENT_STRINGS_CACHE_SIZE];

    get(s: LuaString): LuaString {
      var index: i32 = s.hashCode() & (LuaString.RECENT_STRINGS_CACHE_SIZE - 1);
			var cached: LuaString = this.recentShortStrings[index];
			if (cached != null && s.raweq(cached)) {
				return cached;
			}
			this.recentShortStrings[index] = s;
			return s;
		}

		static readonly instance: Cache = new Cache();
  }

  static valueOf(string: String): LuaString {
		var bytes: i32[] = new i32[string.length];
		this.encode(string, bytes, 0);
		return this.valueOf(bytes, 0, bytes.length);
	}

  static valueOf_0(bytes: i32[], off: i32, len: i32): LuaString {
		if (bytes.length < LuaString.RECENT_STRINGS_MAX_LENGTH) {
			return this.Cache.instance.get(new LuaString(bytes, off, len));
		} else if (len >= bytes.length / 2) {
			return new LuaString(bytes, off, len);
		} else {
			var b: i32[] = new i32[len];
			arraycopy(bytes, off, b, 0, len);
			var string: LuaString = new LuaString(b, 0, len);
			return len < LuaString.RECENT_STRINGS_MAX_LENGTH ? this.Cache.instance.get(string) : string;
		}
  }

  static valueOf_1(bytes: i32[]): LuaString {
		return this.valueOf_0(bytes, 0, bytes.length);
	}
}

class Buffer {
  private static readonly DEFAULT_CAPACITY: i32 = 64;
  private static readonly NO_BYTES: i8[] = new i8[0];
  
  private bytes: i32[];
  private length: i32;
  private offset: i32;

  private value: LuaString | null;

  constructor_0() {
    this.constructor_1(Buffer.DEFAULT_CAPACITY);
  }
  
  constructor_1(initialCapacity: i32) {
    this.bytes = new i32[initialCapacity];
    this.length = 0;
    this.offset = 0;
    this.value = null;
  }

  constructor_2(value: LuaString) {
    this.bytes = Buffer.NO_BYTES;
    this.length = 0;
    this.offset = 0;
    this.value = value;
  }

  getValue(): LuaValue {
    return this.value != null ? this.value : this.toLuaString();
  }

  setValue(value: LuaString): Buffer {
    this.bytes = Buffer.NO_BYTES;
    this.offset = 0;
    this.length = 0;
		this.value = value;

		return this;
	}

	toLuaString(): LuaString {
		this.realloc(length, 0);
		return LuaString.valueOf(this.bytes, this.offset, this.length);
	}

  toString(): String {
    return this.getValue().toString()
  }

	append_0(b: i32): Buffer {
		this.makeRoom(0, 1);
		this.bytes[this.offset + this.length] = b < 256 ? b : 63;
    this.length++;
		return this;
	}

  append_1(chars: i32[]): Buffer {
		var n: i32 = chars.length;
		this.makeRoom(0, n);
		LuaString.encode(chars, this.bytes, this.offset + this.length);
		this.length += n;
  }

  append_2(str: LuaString): Buffer {
		var n: i32 = str.length;
		this.makeRoom(0, n);
		str.copyTo(0, this.bytes, this.offset + this.length, n);
		this.length += n;
    
		return this;
  }

  append_3(str: String): Buffer {
		var n: i32 = str.length;
		this.makeRoom(0, n);
		LuaString.encode(str, this.bytes, this.offset + this.length);
		this.length += n;

		return this;
  }

  prepend(s: LuaString): Buffer {
  	var n: i32 = s.length;
		this.makeRoom(n, 0);
		arraycopy(s.bytes, s.offset, this.bytes, this.offset - n, n);
		this.offset -= n;
		this.length += n;
		this.value = null;
		return this;
	}

  makeRoom(nbefore: i32, nafter: i32): void {
    if (this.value != null) {
      var s: LuaString = this.value;
      this.value = null;
      this.length = s.length;
      this.offset = nbefore;
      this.bytes = new i32[nbefore + this.length + nafter];
			arraycopy(s.bytes, s.offset, this.bytes, this.offset, this.length);
		} else if (this.offset + this.length + nafter > this.bytes.length || this.offset < nbefore) {
			var n: i32 = nbefore + this.length + nafter;
			var m: i32 = n < 32 ? 32 : n < this.length * 2 ? this.length * 2 : n;
			this.realloc(m, nbefore == 0 ? 0 : m - this.length - nafter);
		}
	}
  
  private realloc(newSize: i32, newOffset: i32): void {
		if (newSize != this.bytes.length) {
			var newBytes: i32[] = new i32[newSize];
			arraycopy(this.bytes, this.offset, newBytes, newOffset, this.length);
			this.bytes = newBytes;
			this.offset = newOffset;
		}
	}
}