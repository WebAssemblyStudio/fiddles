(async () => {
    let string = "";
    let string2 = "";
    const codePromise = fetch('../out/main.wasm');
    const {instance}  = await WebAssembly.instantiateStreaming(codePromise);
    //carrega o modulo do web assembly

    const buffer = new Uint8Array(instance.exports.memory.buffer);
    //carrega a memoria do web assembly

    const pointer = instance.exports.fatorial5();
    //o ponteiro onde se inicia a frase "fatorial(5)="
    
    for(let i=pointer; buffer[i]; i++){
      string += String.fromCharCode(buffer[i]);
    }
    const fat= instance.exports.fatorial(5);
    //escreve a frase
    string+=fat;
    //escreve o valor de fatorial(5)
    
    const pointer2 = instance.exports.fibonacci5();
    //o ponteiro para onde se inicia a frase "fibonacci(5)="
    for(let i=pointer2; buffer[i]; i++){
      string2 += String.fromCharCode(buffer[i]);
    }
    //escreve a frase
    string2+= instance.exports.fibonacci(5);
    //escreve o valor de fibonacci(5)


    document.getElementById('fatorial').textContent = string;
    document.getElementById('fibonacci').textContent = string2;
    //coloca as frases na tela
})()