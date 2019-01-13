let t;
let t2;

function create(x, y, z, w) {
  let out = new Float32Array(4);
  out[0] = x;
  out[1] = y;
  out[2] = w;
  out[3] = z;
  return out;
}

function add(out, a, b) {
  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  return out;
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello(x) {
      console.log("Hello from WebAssembly!", x);
      if (x == 2) {
        let a = create(1, 2, 3, 4);
        let b = create(1, 2, 3, 4);

        t2 = Date.now();
        for(let i=0;i<100000;i++){
          add(new Float32Array(4),a,b);
        }
        console.log(Date.now() - t2);
      }
    },
    time(x) {
      if (!t) {
        t = Date.now();
      } else {
        console.log(Date.now() - t);
      }
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
}).catch(console.error);
