fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let input = "r =";

  input.split(' ').forEach(c => {
    if (!isNaN(c)) {
      instance.exports.pushFloat(Number(c));
    } else {
      instance.exports.pushByte(c.charCodeAt(0));
    }
  });

  let seed = Math.floor(Math.random() * 1000000);
  instance.exports.init(seed);
  instance.exports.start();

  let state = { update: 0 };
  let steps = 0;
  while (state.update == 0 && steps < 10) {
    steps++;
    state.update = instance.exports.update();
    state.head = instance.exports.getHead();
    state.headX = instance.exports.getHeadX();
    state.headY = instance.exports.getHeadY();
    state.steps = instance.exports.getSteps();

    console.log(JSON.stringify(state));
  }
});