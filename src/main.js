const { draw } = wasm_bindgen;

// For more comments about what's going on here, check out the `hello_world`
// example at https://webassembly.studio/?f=gzubao6tg3
wasm_bindgen('../out/main_bg.wasm').then(() => {
  const canvas = document.getElementById('drawing');
  const ctx = canvas.getContext('2d');
  
  const realInput = document.getElementById('real');
  const imaginaryInput = document.getElementById('imaginary');
  const renderBtn = document.getElementById('render');

  renderBtn.addEventListener('click', () => {
    const real = parseFloat(realInput.value) || 0;
    const imaginary = parseFloat(imaginaryInput.value) || 0;
    draw(ctx, 600, 600, real, imaginary);
  });
  
  draw(ctx, 600, 600, -0.15, 0.65);
});