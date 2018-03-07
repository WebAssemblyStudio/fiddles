fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  let input = "s e * w + =";

  input.split(' ').forEach(c => {
    if (!isNaN(c)) {
      instance.exports.pushFloat(Number(c));
    } else {
      instance.exports.pushByte(c.charCodeAt(0));
    }
  });

  instance.exports.init(420);
  instance.exports.start();

  let state = { update = 0 };
  while (state.update == 0) {
    state.update = instance.exports.update();
    state.head = instance.exports.getHead();
    state.headX = instance.exports.getHeadX();
    state.headY = instance.exports.getHeadY();
    state.steps = instance.exports.getSteps();

    console.log(JSON.stringify(state));
  }
});