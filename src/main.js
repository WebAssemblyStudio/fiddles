(async() => {
    const promise = fetch('../out/main.wasm');
    const { instance } = await WebAssembly.instantiateStreaming(promise);
    const form = document.querySelector('#form');
    const numero = document.querySelector('#numero');
    const output = document.querySelector('#output');

    form.onsubmit = (e) => {
      e.preventDefault();
      const esNatural = instance.exports.es_natural(numero.value);
      const resultado = !!parseInt(esNatural)

      output.textContent = resultado

      if(resultado)
        output.className = "alert alert-success"
      else
        output.className = "alert alert-danger"
    }
})()