// Carrega o código WebAssembly compilado
fetch('../out/main.wasm')
  // Acessa o código carregado como um ArrayBuffer
  .then(response => response.arrayBuffer())

  // Instancia a máquina virtual com o código carregado
  .then(bytes => WebAssembly.instantiate(bytes, { env: {} }))

  // Executa a função "calculate" escrita em C, escrevendo
  // o resultado em um elemento do DOM
  .then(({ instance }) => {
    const result = instance.exports.calculate(2, 3);
    document.getElementById("result").textContent = "result = " + result;
  })

  .catch(console.error);
