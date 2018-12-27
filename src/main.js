function time(func){
  start = new Date().getTime();
  func();
  diff = new Date().getTime() - start;
  return diff;
}
function test(func1, func2){
  let n = 100000000;
  let results = [];
  results.push(`n=${n}`);
  let time1 = time(()=>{
      func1(n);
  })
  results.push(`time1=${time1}`);
  let time2 = time(()=>{
      func2(n);
  })
  results.push(`time2=${time2}`);
  return results.join('\n');

}
function add(x,y){
  return x+y;
}
function performTest(n){
  let value = 0.0;
  for(let i = 0; i < n; i++){
    value = add(i,1);
  }
  return value;
}


WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(msg, file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + test(exports.performTest,performTest) ;
}).catch(console.error);
