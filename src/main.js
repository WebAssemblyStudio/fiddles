const { Universe } = wasm_bindgen;

const pre = document.getElementById("game-of-life-canvas");
let universe;

const renderLoop = () => {
    pre.textContent = universe.render();
    universe.tick();

    requestAnimationFrame(renderLoop);
};


// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(() => {
  universe = Universe.new();
  requestAnimationFrame(renderLoop);
});
