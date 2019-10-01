function fib(n){
  if(n<=1){
    return n;
  }else{
    return fib(n-1)+fib(n-2);
  }
}

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  
  console.log("js");
  var start = Date.now();
  console.log(fib(42));
  console.log(Date.now()-start);

  console.log("wasm");
  start = Date.now();
  console.log(exports.fib(42));
  console.log(Date.now()-start);
  
}).catch(console.error);
