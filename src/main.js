let x = '../out/main.wasm';

let instance = null;
let memoryStates = new WeakMap();

/**
 * Converters bytes to different formats.
 */

const MAX_SIGNIFICANT_SIZE = 127;

/**
 * Converts a series of bytes to an unsigned 32-bit integer.
 *
 * @param  {Uint8Array} byteArray - array to read from.
 * @param  {Number} start - starting position.
 * @param  {Number} count - number of bytes to read.
 * @return {Number} 32-bit unsigned integer.
 */
function bytesToUint32(byteArray, start, count) {
  if (count > 4) {
    throw new Error('Length cannot be greater than 4');
  }

  let position = start;
  let value = 0;

  if (count === 4) {
    let sigValue = byteArray[position];

    if (sigValue > MAX_SIGNIFICANT_SIZE) {
      value += MAX_SIGNIFICANT_SIZE << 24;
      sigValue -= MAX_SIGNIFICANT_SIZE;
    }
    value += sigValue << 24;
    position++;
  }

  for (let i = position; i < start + count; i++) {
    value += byteArray[i] << (8 * (count - (i - start) - 1));
  }

  return value;
}

/**
 * Converts a series of bytes to a string.
 *
 * @param  {Uint8Array} byteArray - array to read from.
 * @param  {Number} start - starting position.
 * @param  {Number} count - number of bytes to read.
 * @return {String} the bytes as a string.
 */
function bytesToString(byteArray, start, count) {
  let result = '';
  for (let i = start; i < start + count; i++) {
    const byte = byteArray[i];

    if (byte === 0) {
      result += '00';
    } else if (byte < 10) {
      result += `0${byte.toString()}`;
    } else {
      result += byte.toString();
    }
  }

  return result;
}

function getData(url)
{
  var ret = [];
  fetch(url).then(response => response.arrayBuffer()
  ).then(bytes => ret[0] = bytes)
  return ret;
}
function checkSignature(data)
{
  const signature = [137, 80, 78, 71, 13, 10, 26, 10, 0, 0, 0, 13, 73, 72, 68, 82];

  for (let i = 0; i < signature.length; i++) {  
      if (data[i] !== signature[i]) {
        return false;
      }
  }
}

function syscall(instance, n, args) {
  switch (n) {
    default:
      console.log("Syscall " + n + " NYIA.");
      break;
    case /* brk */ 45:  console.log("Syscall " + n + " NYIB."); return 0;
    case /* writev */ 146:
      console.log("Syscall " + n + " NYIC.");
      return instance.exports.writev_c(args[0], args[1], args[2]);
    case /* mmap2 */ 192:
      console.log("Syscall " + n + " NYID.");
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
var data = [];
let s = "";
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
      putc_js: function (c) {
        c = String.fromCharCode(c);
        if (c == "\n") {
          console.log(s);
          s = "";
        } else {
          s += c;
        }
      }
    }
  })
).then(results => {
  data = getData('../out/foo.png');
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  document.getElementById("container2").textContent = data;
}).catch(console.error);
