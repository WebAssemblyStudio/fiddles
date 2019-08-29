fetch('../out/main.wasm')
  .then(response =>response.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes))
  .then(result => {
    const module = result.module;
    const instance = result.instance;
    
    const width = 2;
    const height = 2;
    const size = width * height * 4;

    const input = new Uint8ClampedArray(size);
    const output = new Uint8ClampedArray(size);

    const colorFrom = new Uint8ClampedArray(3);
    const colorTo = new Uint8ClampedArray(3);

    colorFrom[0] = 12;
    colorFrom[1] = 115;
    colorFrom[2] = 97;

    colorTo[0] = 123;
    colorTo[1] = 87;
    colorTo[2] = 111;

    console.log(module._malloc);
    console.log(instance);

    const r = instance
      .exports
      .remap(width, height, input, output, colorFrom, colorTo);

    console.log(input);
    console.log(output);

    console.log(r);
  })
  .catch(console.error);
