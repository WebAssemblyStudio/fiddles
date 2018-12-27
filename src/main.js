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


fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let exports = instance.exports;
  document.getElementById("container").textContent = test(exports.performTest,performTest);
}).catch(console.error);
