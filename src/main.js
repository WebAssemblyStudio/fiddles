let x = '../out/main.wasm';

let instance = null;

fetch(x).then(response =>
  response.arrayBuffer()
).then(bytes =>
  WebAssembly.instantiate(bytes, {})
  ).then(results => {
    instance = results.instance;

    let input = "0.08940260803879663 0.09962092287444801 * 0.6920041141655995 0.6569222200054086 / % 0.6111459872093206 0.39936837361607935 % 0.3930335417665036 0.6339621622551936 - * - 0.7786311226920244 0.8261514098315526 * 0.3450333077390928 0.12613561134253226 - + 0.31326932136144015 0.6068731570654884 % 0.0815287169860921 0.7508722857964791 / / * + =";

    input.split(' ').forEach(c => {
      if (!isNaN(c)) {
        instance.exports.pushFloat(Number(c));
      } else {
        instance.exports.pushByte(c.charCodeAt(0));
      }
    });

    instance.exports.start();
    console.log(instance.exports.update());

    // document.getElementById("container").innerText = instance.exports.main();
  });
