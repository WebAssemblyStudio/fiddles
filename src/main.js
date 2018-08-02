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
        berry: { x: instance.exports.getBerryX(), y: instance.exports.getBerryY() },
        length: instance.exports.getLength(),
        body: []
      };

      for (let j = 0; j < result.length; j++) {
        result.body.unshift({
          x: instance.exports.getBodyX(j),
          y: instance.exports.getBodyY(j)
        });
      }

      result.fitness = instance.exports.update();

      printResults(result);
      if (!!result.fitness) {
        console.log('finished');
        break;
      }
    }
  });

function printResults(results) {
  console.log(JSON.stringify(results) + '\n');

  for (let row = 0; row < 10; row++) {
    let rowStr = '';
    for (let col = 0; col < 10; col++) {
      rowStr += results.body.some(b => b.x == col && b.y == row) ? '■' :
                results.berry.x == col && results.berry.y == row ? '¤' : '-';
      rowStr += ' ';
    }
    console.log(rowStr);
  }

  console.log('\n');
}
