
function wait(n) {
	return new Promise( (resolve) => setTimeout(resolve, n));
}

const workers = [];

async function runWorker (output) {

  const worker = new Worker(URL.createObjectURL(await (await fetch('../src/worker.js')).blob()));
  worker.onerror = function (e) {
    alert(e);
  };
  worker.onmessage = function (e) {
    output.textContent = e.data.message;
  };

  const res = await fetch('../out/main.wasm');
  const buf = await res.arrayBuffer();
  const mod = await WebAssembly.compile(buf);
  worker.postMessage({
    module: mod
  })

  workers.push(worker);
}

window.onload = async function () {
  for (let i = 0; i < 8; i++) {
    const div = document.createElement('div');
    document.body.appendChild(div);
    runWorker(div);
  }
};