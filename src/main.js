let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

function syscall(instance, n, args) {
  switch (n) {
    default:
      // console.log("Syscall " + n + " NYI.");
      break;
    case /* brk */ 45: return 0;
    case /* writev */ 146:
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      debugger;
      const memory = instance.exports.memory;
      let memoryState = memoryStates.get(instance);
      const requested = args[1];
      if (!memoryState) {
        memoryState = {
          object: memory,
          currentPosition: memory.buffer.byteLength,
        };
        memoryStates.set(instance, memoryState);
      }
      let cur = memoryState.currentPosition;
      if (cur + requested > memory.buffer.byteLength) {
        const need = Math.ceil((cur + requested - memory.buffer.byteLength) / 65536);
        memory.grow(need);
      }
      memoryState.currentPosition += requested;
      return cur;
  }
}

var BufferBuilder = (function() {
  function BufferBuilder(initCap, allocBy) {
    this._allocBy = allocBy || 4096;
    this._initCap = initCap || 1024;
    this._bytes = null;
    this._pos = 0;
  }
  BufferBuilder.prototype._ensureAvailable = function(numBytes) {
    if (numBytes === 0) return;
    if (!this._bytes || this._pos + numBytes > this._bytes.length) {
      var newLength = this._pos + numBytes + this._allocBy - 1;
      newLength -= newLength % this._allocBy;
      var newBytes = new Uint8Array(newLength);
      if (this._bytes) newBytes.set(this._bytes);
      this._bytes = newBytes;
    }
  };
  BufferBuilder.prototype.isEmpty = function() { return this._pos === 0; }
  BufferBuilder.prototype.isNotEmpty = function() { return this._pos !== 0; }
  BufferBuilder.prototype.size = function() { return this._pos; };
  BufferBuilder.prototype.write = function(bytes, offsetOpt, lengthOpt) {
    var offset = offsetOpt || 0;
    var length = lengthOpt || bytes.length - offset;
    if (length === 0) return;
    if (offset > 0 || length < bytes.length) {
      bytes = new Uint8Array(bytes.buffer, bytes.byteOffset + offset, length);
    }
    this._ensureAvailable(bytes.length);
    this._bytes.set(bytes, this._pos);
    this._pos += length;
  };
  BufferBuilder.prototype.writeByte = function(byte) {
    this._ensureAvailable(1);
    this._bytes[this._pos++] = byte;
  };
  BufferBuilder.prototype.toBuffer = function() {
    return this.toUint8Array().buffer;
  };
  BufferBuilder.prototype.toUint8Array = BufferBuilder.prototype.toByteArray = function() {
    if (this._pos === 0) return new Uint8Array(0);
    var result = new Uint8Array(this._pos);
    result.set(this._bytes);
    return result;
  };
  BufferBuilder.prototype.toBytesAndClear = function() {
    if (this._pos === 0) return new Uint8Array(0);
    var result = new Uint8Array(this._bytes.buffer, 0, this._pos);
    this._bytes = null;
    this._pos = 0;
    return result;
  };
  return BufferBuilder;
})();

function utf8ToString(bytes) {
  var len = bytes.length;
  var codes = new Uint16Array(bytes.length);
  var count = 0;
  for (var i = 0; i < len; ++i) {
    var b = bytes[i];
    if (b & 0x80) {
      if (b & 0x20) {
        if (b & 0x10) {
          // 1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx
          var cp = ((b & 0x03) << 18)
              | ((bytes[i + 1] & 0x3f) << 12)
              | ((bytes[i + 2] & 0x3f) << 6)
              | (bytes[i + 3] & 0x3f);
          if (cp < 0x10000) {
            codes[count++] = cp;
          } else {
            cp -= 0x10000;
            codes[count++] = ((cp >> 10) & 0x03ff) + 0xd800;
            codes[count++] = (cp & 0x03ff) + 0xdc00;
          }
          i += 3;
        } else {
          // 1110 xxxx  10xx xxxx  10xx xxxx
          codes[count++] = ((b & 0x0f) << 12) | ((bytes[i + 1] & 0x3f) << 6) | (bytes[i + 2] & 0x3f);
          i += 2;
        }
      } else {
        // 110x xxxx   10xx xxxx
        codes[count++] = ((b & 0x1f) << 6) | (bytes[i + 1] & 0x3f);
        ++i;
      }
    } else {
      codes[count++] = bytes[i];
    }
  }
  codes = new Uint16Array(codes.buffer, 0, count);
  return String.fromCharCode.apply(String, codes);
}

function byteView(bytes, relByteOffset, length) {
  if (typeof length !== "number") length = bytes.byteLength - relByteOffset;
  return new Uint8Array(bytes.buffer, bytes.byteOffset + relByteOffset, length);
}

let s = [new BufferBuilder(), new BufferBuilder(), new BufferBuilder()];
fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {
    env: {
      __syscall0: function __syscall0(n) { return syscall(instance, n, []); },
      __syscall1: function __syscall1(n, a) { return syscall(instance, n, [a]); },
      __syscall2: function __syscall2(n, a, b) { return syscall(instance, n, [a, b]); },
      __syscall3: function __syscall3(n, a, b, c) { return syscall(instance, n, [a, b, c]); },
      __syscall4: function __syscall4(n, a, b, c, d) { return syscall(instance, n, [a, b, c, d]); },
      __syscall5: function __syscall5(n, a, b, c, d, e) { return syscall(instance, n, [a, b, c, d, e]); },
      __syscall6: function __syscall6(n, a, b, c, d, e, f) { return syscall(instance, n, [a, b, c, d, e, f]); },
      putcs_js: function (fd, c, l) {
        let bytes = new Uint8Array(instance.exports.memory.buffer, c, l);
        let nl = bytes.indexOf(10); // '\n'
        while (nl >= 0) {
          let section = byteView(bytes, 0, nl);
          bytes = byteView(bytes, nl + 1);
          let line;
          if (s[fd].isNotEmpty()) {
            s[fd].write(section);
            line = utf8ToString(s[fd].toBytesAndClear());
          } else {
            line = utf8ToString(section);
          }
          let log = fd == 1 ? console.log : console.error;
          log.call(console, line);
          nl = bytes.indexOf("\n");
        }
        if (bytes.length > 0) s[fd].write(bytes);
      },
      putc_js: function (fd, c) {
        if (c === 10) {
          let log = fd == 1 ? console.log : console.error;
          log.call(console, utf8ToString(s[fd].toBytesAndClear()));
        } else {
          s[fd].writeByte(c);
        }
      }
    }
  })
).then(results => {
  instance = results.instance;
  document.getElementById("container").innerText = instance.exports.main();
}).catch(console.error);
