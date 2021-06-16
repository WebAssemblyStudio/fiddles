(async function main() {
  console.log("starting");
  let results1 = await WebAssembly.instantiateStreaming(
    fetch('../out/core.wasm'),
    // dans cet objet, on passe les fonctions importées par main.wasm
    {
      env: {}
    }
  );

  let results2 = await WebAssembly.instantiateStreaming(
    fetch('../out/decorator.wasm'),
    // dans cet objet, on passe les fonctions importées par main.wasm
    {
      env: {
        core_store: results1.instance.exports.store,
        core_get: results1.instance.exports.get,
        core_inc: results1.instance.exports.inc,
        console_log_char_int: (c, i) => {
          console.log("decorator says " + String.fromCharCode(c) + " " + i);
        },
      }
    }
  );

  let { store, get, inc } = results2.instance.exports;
  store(41);
  inc();
  const answer = get();
  document.getElementById("container").textContent = "The answer is " + answer;

  console.log("done");


})().catch(console.error);
