const imports = {
    button: {
        updateClickCount: () => document.getElementById('numclicks').innerHTML = "Hello World"
    }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), imports)
    .then(obj => {

        const exports = obj.instance.exports;

        document.getElementById('click').addEventListener('click', () => {

            exports.onClick();
        });

    }).catch((err) => console.error(err));