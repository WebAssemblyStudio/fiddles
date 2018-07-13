function fetchAndInstantiate(url, imports = {}) {
  return WebAssembly.instantiateStreaming(fetch(url), imports).then(response => {
    return response.instance;
  }).catch(console.error);
}

async function main() {
  const main = await fetchAndInstantiate("../out/main.wasm");
  document.getElementById("container").innerHTML = main.exports.add(1, 2);

  const button = document.createElement("button");
  button.onclick = async function() {
    const lazy = await fetchAndInstantiate("../out/lazy.wasm", { main: main.exports });
    document.getElementById("container").innerHTML += "<br/>" + lazy.exports.get_add_result();
  }
}