const width = 640;
const height = 360;

// Contains the actual webassembly
const base64data = 'AGFzbQEAAAABBQFgAAF/AhIBA2VudgZtZW1vcnkCAYACgAIDAgEABwsBB19yZW5kZXIAAApJAUcBA38DQCAAQaAGbCECQQAhAQNAIAEgAmpBAnRBgAhqQf+BgHg2AgAgAUEBaiIBQaAGRw0ACyAAQQFqIgBBkANHDQALQYAICw==';

const decode = (b64) => {
  const str = window.atob(b64);
  const array = new Uint8Array(str.length);
  for (let i = 0; i < str.length; i += 1) {
    array[i] = str.charCodeAt(i);
  }
  return array.buffer;
};

const memSize = 256;
const memory = new WebAssembly.Memory({ initial: memSize, maximum: memSize });

const instance = new WebAssembly.Instance(
  new WebAssembly.Module(new Uint8Array(decode(base64data))),
  { env: { memory } }
);

// Get 2d drawing context
const ctx = document.getElementById('c').getContext('2d');
const pointer = instance.exports._render();
const data = new Uint8ClampedArray(memory.buffer, pointer, width * height * 4);
const img = new ImageData(data, width, height);
ctx.putImageData(img, 0, 0);
