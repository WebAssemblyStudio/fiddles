const main = async () => {
  
  const response = await fetch('../out/main.wasm');
  const bytes = await response.arrayBuffer();
  const results = await WebAssembly.instantiate(bytes);
  const instance = results.instance;

  const prngseed = new Uint32Array(8);
  crypto.getRandomValues(prngseed);

  console.info(prngseed);

  const { seed, next } = instance.exports;

  seed(...prngseed);

  const numbs = [];

  console.time("xoshiro");

  let i = 1000;
  while (i--) {
    numbs.push(next());
  }

  console.timeEnd("xoshiro");
  console.time("chrome");
  i = 1000;
  while (i--) {
    numbs.push(Math.random());
  }

  console.timeEnd("chrome");

  console.log(numbs);
};

main().catch(console.error);