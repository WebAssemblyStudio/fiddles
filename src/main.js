fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  const start=performance.now();
  const r=instance.exports.add(1,1);
  const duration=performance.now()-start;
  document.getElementById("container").textContent = r+" time="+duration;

  const startj=performance.now();
  const rj=sum(1,1);
  const durationj=performance.now()-startj;
  document.getElementById("container").textContent += "<BR>"+r+" time="+durationj+"  "+(durationj/duration)+"倍速くなった";
  
}).catch(console.error);

function sum() {
  let i=0,s=0,max=100000;
  for(i=0;i<=max;i++) sum+=i;
  return sum;
}