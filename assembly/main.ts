/*
 * [js-sha1]{@link https://github.com/emn178/js-sha1}
 *
 * @version 0.6.0
 * @author Chen, Yi-Cyuan [emn178@gmail.com]
 * @copyright Chen, Yi-Cyuan 2014-2017
 * @license MIT
 */
/*jslint bitwise: true */

import "allocator/arena";

// const HEX_CHARS = "0123456789abcdef".split("");
const HEX_CHARS: string[] = [
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'a', 'b', 'c', 'd', 'e', 'f'
];

const EXTRA: u32[] = [-2147483648, 8388608, 8388608, 32768, 128];
const SHIFT: u32[] = [24, 16, 8, 0];

var blocks = new Array<u32>(80);

export class Sha1 {
  private _blocks: Array<u32>;
  private _block: u32;
  private _start: i32;
  private _bytes: u64;
  private _hBytes: u32;
  private _finalized: bool;
  private _hashed: bool;

  private _h0: u32 = 0x67452301;
  private _h1: u32 = 0xefcdab89;
  private _h2: u32 = 0x98badcfe;
  private _h3: u32 = 0x10325476;
  private _h4: u32 = 0xc3d2e1f0;
  private _lastByteIndex: i32 = 0;

  constructor(sharedMemory: bool = false) {
    if (sharedMemory) {
      this._blocks = blocks.fill(0, 0, 17);
    } else {
      this._blocks = new Array<u32>(80);
    }

    this._h0 = 0x67452301;
    this._h1 = 0xefcdab89;
    this._h2 = 0x98badcfe;
    this._h3 = 0x10325476;
    this._h4 = 0xc3d2e1f0;

    this._block = 0;
    this._start = 0;
    this._bytes = 0;
    this._hBytes = 0;
    this._finalized = false;
    this._hashed = false;
  }

  update(data: string): void {
    if (this._finalized) {
      return;
    }
    // let notString = true;
    let message: string;
    /*if (data instanceof ArrayBuffer) {
      message = new Uint8Array(data);
    } else if (ArrayBuffer.isView(data)) {
      message = new Uint8Array(data.buffer);
    } else {
      notString = false;
      message = data;
    }*/
    message = data;
    let code: u32,
      index = 0,
      i: i32,
      start  = this._start,
      length = message.length,
      blocks = this._blocks;

    while (index < length) {
      if (this._hashed) {
        this._hashed = false;
        blocks[0] = this._block;
        blocks.fill(0, 1, 17);
      }

      /*if (notString) {
        for (i = start; index < length && i < 64; ++index) {
          blocks[i >> 2] |= message[index] << SHIFT[i++ & 3];
        }
      } else {*/
        for (i = start; index < length && i < 64; ++index) {
          code = message.charCodeAt(index);
          if (code < 0x80) {
            blocks[i >> 2] |= code << SHIFT[i++ & 3];
          } else if (code < 0x800) {
            blocks[i >> 2] |= (0xc0 | (code >> 6)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | (code & 0x3f)) << SHIFT[i++ & 3];
          } else if (code < 0xd800 || code >= 0xe000) {
            blocks[i >> 2] |= (0xe0 | (code >> 12)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | ((code >> 6) & 0x3f)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | (code & 0x3f)) << SHIFT[i++ & 3];
          } else {
            code =
              0x10000 +
              (((code & 0x3ff) << 10) | (message.charCodeAt(++index) & 0x3ff));
            blocks[i >> 2] |= (0xf0 | (code >> 18)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | ((code >> 12) & 0x3f)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | ((code >> 6) & 0x3f)) << SHIFT[i++ & 3];
            blocks[i >> 2] |= (0x80 | (code & 0x3f)) << SHIFT[i++ & 3];
          }
        }
      // }

      this._lastByteIndex = i;
      this._bytes += <u64>(i - start);
      if (i >= 64) {
        this._block = blocks[16];
        this._start = i - 64;
        this.hash();
        this._hashed = true;
      } else {
        this._start = i;
      }
    }
    if (this._bytes > 4294967295) {
      this._hBytes += <u32>(this._bytes / 4294967296);
    }
  }

  finalize(): void {
    if (this._finalized) {
      return;
    }
    this._finalized = true;
    let blocks = this._blocks,
      i = this._lastByteIndex;
    blocks[16] = this._block;
    blocks[i >> 2] |= EXTRA[i & 3];
    this._block = blocks[16];
    if (i >= 56) {
      if (!this._hashed) {
        this.hash();
      }
      blocks[0] = this._block;
      blocks.fill(0, 1, 17);
    }
    blocks[14] = (this._hBytes << 3) | (<u32>this._bytes >>> 29);
    blocks[15] = <u32>this._bytes << 3;
    this.hash();
  }

  hash(): void {
    var
      a = this._h0,
      b = this._h1,
      c = this._h2,
      d = this._h3,
      e = this._h4,
      f: u32,
      t: u32;

    var j: i32, blocks = this._blocks;

    for (j = 16; j < 80; ++j) {
      t = blocks[j - 3] ^ blocks[j - 8] ^ blocks[j - 14] ^ blocks[j - 16];
      blocks[j] = (t << 1) | (t >>> 31); // TODO replace to rotl
    }

    for (j = 0; j < 20; j += 5) {
      f = (b & c) | (~b & d);
      t = (a << 5) | (a >>> 27); // TODO replace to rotl
      e = (t + f + e + 1518500249 + blocks[j]) >>> 0;
      b = (b << 30) | (b >>> 2); // TODO replace to rotl

      f = (a & b) | (~a & c);
      t = (e << 5) | (e >>> 27);
      d = (t + f + d + 1518500249 + blocks[j + 1]) >>> 0;
      a = (a << 30) | (a >>> 2);

      f = (e & a) | (~e & b);
      t = (d << 5) | (d >>> 27);
      c = (t + f + c + 1518500249 + blocks[j + 2]) >>> 0;
      e = (e << 30) | (e >>> 2);

      f = (d & e) | (~d & a);
      t = (c << 5) | (c >>> 27);
      b = (t + f + b + 1518500249 + blocks[j + 3]) >>> 0;
      d = (d << 30) | (d >>> 2);

      f = (c & d) | (~c & e);
      t = (b << 5) | (b >>> 27);
      a = (t + f + a + 1518500249 + blocks[j + 4]) >>> 0;
      c = (c << 30) | (c >>> 2);
    }

    for (; j < 40; j += 5) {
      f = b ^ c ^ d;
      t = (a << 5) | (a >>> 27);
      e = (t + f + e + 1859775393 + blocks[j]) >>> 0;
      b = (b << 30) | (b >>> 2);

      f = a ^ b ^ c;
      t = (e << 5) | (e >>> 27);
      d = (t + f + d + 1859775393 + blocks[j + 1]) >>> 0;
      a = (a << 30) | (a >>> 2);

      f = e ^ a ^ b;
      t = (d << 5) | (d >>> 27);
      c = (t + f + c + 1859775393 + blocks[j + 2]) >>> 0;
      e = (e << 30) | (e >>> 2);

      f = d ^ e ^ a;
      t = (c << 5) | (c >>> 27);
      b = (t + f + b + 1859775393 + blocks[j + 3]) >>> 0;
      d = (d << 30) | (d >>> 2);

      f = c ^ d ^ e;
      t = (b << 5) | (b >>> 27);
      a = (t + f + a + 1859775393 + blocks[j + 4]) >>> 0;
      c = (c << 30) | (c >>> 2);
    }

    for (; j < 60; j += 5) {
      f = (b & c) | (b & d) | (c & d);
      t = (a << 5) | (a >>> 27);
      e = (t + f + e - 1894007588 + blocks[j]) >>> 0;
      b = (b << 30) | (b >>> 2);

      f = (a & b) | (a & c) | (b & c);
      t = (e << 5) | (e >>> 27);
      d = (t + f + d - 1894007588 + blocks[j + 1]) >>> 0;
      a = (a << 30) | (a >>> 2);

      f = (e & a) | (e & b) | (a & b);
      t = (d << 5) | (d >>> 27);
      c = (t + f + c - 1894007588 + blocks[j + 2]) >>> 0;
      e = (e << 30) | (e >>> 2);

      f = (d & e) | (d & a) | (e & a);
      t = (c << 5) | (c >>> 27);
      b = (t + f + b - 1894007588 + blocks[j + 3]) >>> 0;
      d = (d << 30) | (d >>> 2);

      f = (c & d) | (c & e) | (d & e);
      t = (b << 5) | (b >>> 27);
      a = (t + f + a - 1894007588 + blocks[j + 4]) >>> 0;
      c = (c << 30) | (c >>> 2);
    }

    for (; j < 80; j += 5) {
      f = b ^ c ^ d;
      t = (a << 5) | (a >>> 27);
      e = (t + f + e - 899497514 + blocks[j]) >>> 0;
      b = (b << 30) | (b >>> 2);

      f = a ^ b ^ c;
      t = (e << 5) | (e >>> 27);
      d = (t + f + d - 899497514 + blocks[j + 1]) >>> 0;
      a = (a << 30) | (a >>> 2);

      f = e ^ a ^ b;
      t = (d << 5) | (d >>> 27);
      c = (t + f + c - 899497514 + blocks[j + 2]) >>> 0;
      e = (e << 30) | (e >>> 2);

      f = d ^ e ^ a;
      t = (c << 5) | (c >>> 27);
      b = (t + f + b - 899497514 + blocks[j + 3]) >>> 0;
      d = (d << 30) | (d >>> 2);

      f = c ^ d ^ e;
      t = (b << 5) | (b >>> 27);
      a = (t + f + a - 899497514 + blocks[j + 4]) >>> 0;
      c = (c << 30) | (c >>> 2);
    }

    this._h0 += a;
    this._h1 += b;
    this._h2 += c;
    this._h3 += d;
    this._h4 += e;
  }

  hex(): string {
    this.finalize();

    let h0 = this._h0,
      h1 = this._h1,
      h2 = this._h2,
      h3 = this._h3,
      h4 = this._h4;

    return (
      HEX_CHARS[(h0 >> 28) & 0x0f] +
      HEX_CHARS[(h0 >> 24) & 0x0f] +
      HEX_CHARS[(h0 >> 20) & 0x0f] +
      HEX_CHARS[(h0 >> 16) & 0x0f] +
      HEX_CHARS[(h0 >> 12) & 0x0f] +
      HEX_CHARS[(h0 >>  8) & 0x0f] +
      HEX_CHARS[(h0 >>  4) & 0x0f] +
      HEX_CHARS[h0 & 0x0f] +
      HEX_CHARS[(h1 >> 28) & 0x0f] +
      HEX_CHARS[(h1 >> 24) & 0x0f] +
      HEX_CHARS[(h1 >> 20) & 0x0f] +
      HEX_CHARS[(h1 >> 16) & 0x0f] +
      HEX_CHARS[(h1 >> 12) & 0x0f] +
      HEX_CHARS[(h1 >>  8) & 0x0f] +
      HEX_CHARS[(h1 >>  4) & 0x0f] +
      HEX_CHARS[h1 & 0x0f] +
      HEX_CHARS[(h2 >> 28) & 0x0f] +
      HEX_CHARS[(h2 >> 24) & 0x0f] +
      HEX_CHARS[(h2 >> 20) & 0x0f] +
      HEX_CHARS[(h2 >> 16) & 0x0f] +
      HEX_CHARS[(h2 >> 12) & 0x0f] +
      HEX_CHARS[(h2 >>  8) & 0x0f] +
      HEX_CHARS[(h2 >>  4) & 0x0f] +
      HEX_CHARS[h2 & 0x0f] +
      HEX_CHARS[(h3 >> 28) & 0x0f] +
      HEX_CHARS[(h3 >> 24) & 0x0f] +
      HEX_CHARS[(h3 >> 20) & 0x0f] +
      HEX_CHARS[(h3 >> 16) & 0x0f] +
      HEX_CHARS[(h3 >> 12) & 0x0f] +
      HEX_CHARS[(h3 >>  8) & 0x0f] +
      HEX_CHARS[(h3 >>  4) & 0x0f] +
      HEX_CHARS[h3 & 0x0f] +
      HEX_CHARS[(h4 >> 28) & 0x0f] +
      HEX_CHARS[(h4 >> 24) & 0x0f] +
      HEX_CHARS[(h4 >> 20) & 0x0f] +
      HEX_CHARS[(h4 >> 16) & 0x0f] +
      HEX_CHARS[(h4 >> 12) & 0x0f] +
      HEX_CHARS[(h4 >>  8) & 0x0f] +
      HEX_CHARS[(h4 >>  4) & 0x0f] +
      HEX_CHARS[h4 & 0x0f]
    );
  }

  toString(): string {
    return this.hex();
  }

  digest(): Uint8Array {
    this.finalize();

    let
      h0 = this._h0,
      h1 = this._h1,
      h2 = this._h2,
      h3 = this._h3,
      h4 = this._h4;

    var arr = new Uint8Array(20);
    arr[0]  = (h0 >> 24) & 0xff;
    arr[1]  = (h0 >> 16) & 0xff;
    arr[2]  = (h0 >>  8) & 0xff;
    arr[3]  = h0 & 0xff;
    arr[4]  = (h1 >> 24) & 0xff;
    arr[5]  = (h1 >> 16) & 0xff;
    arr[6]  = (h1 >>  8) & 0xff;
    arr[7]  = h1 & 0xff;
    arr[8]  = (h2 >> 24) & 0xff;
    arr[9]  = (h2 >> 16) & 0xff;
    arr[10] = (h2 >>  8) & 0xff;
    arr[11] = h2 & 0xff;
    arr[12] = (h3 >> 24) & 0xff;
    arr[13] = (h3 >> 16) & 0xff;
    arr[14] = (h3 >>  8) & 0xff;
    arr[15] = h3 & 0xff;
    arr[16] = (h4 >> 24) & 0xff;
    arr[17] = (h4 >> 16) & 0xff;
    arr[18] = (h4 >>  8) & 0xff;
    arr[19] = h4 & 0xff;
    return arr;
  }

  array(): Uint8Array {
    return this.digest();
  }

  arrayBuffer(): ArrayBuffer {
    this.finalize();
    var arr = new Uint32Array(5);
    arr[0] = this._h0;
    arr[1] = this._h1;
    arr[2] = this._h2;
    arr[3] = this._h3;
    arr[4] = this._h4;
    return arr.buffer;
  }
}
