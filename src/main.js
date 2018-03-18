let x = '../out/main.wasm';

let instance = null;

fetch(x)
  .then(response => response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, {}))
  .then(results => {
    instance = results.instance;

    let input = "0.08940260803879663 =";

    input.split(' ').forEach(c => {
      if (!isNaN(c)) {
        instance.exports.pushFloat(Number(c));
      } else {
        instance.exports.pushByte(c.charCodeAt(0));
      }
    });

    instance.exports.start();
    console.log('started');

    const MAX_ITER = 100 * 100;
    for (let i = 0; i < MAX_ITER; i++) {
      let result = {
        i,
        fitness: instance.exports.update()
      };
      printResults(result);
      if (!!result.fitness) {
        console.log('finished');
        break;
      }
    }
  });

function printResults(results) {
  console.log(JSON.stringify(results));
}
