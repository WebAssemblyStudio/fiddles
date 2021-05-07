(async() => {
    const promise = fetch('../out/main.wasm');
    const { instance } = await WebAssembly.instantiateStreaming(promise);
    const form = document.querySelector('#form');
    const numero = document.querySelector('#numero');
    
    form.onsubmit = (e) => {
      e.preventDefault();
      const fibWasm = instance.exports.fibonacci(numero.value);
      document.getElementById("container").textContent = fibWasm
    }
})()

function fibonacci(n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}