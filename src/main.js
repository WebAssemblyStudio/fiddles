(async() => {
    const promise = fetch('../out/main.wasm')
    const { instance } = await WebAssembly.instantiateStreaming(promise)

    const form = document.querySelector("#form")

  const esNatural = instance.exports.es_natural(1)
    form.onsubmit(){
      document.getElementById("container").textContent = !!parseInt(esNatural)
    }
    
    //document.getElementById("container").textContent = !!parseInt(esNatural)
})()