const stuffForRust = {
  env: {
    log
  }
};

function log(offset, length) {
  console.log(`received this from rust ${offset} ${length}`);
}

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), stuffForRust).then(
  obj => {
    const answer = obj.instance.exports.hello_world();
  }
);