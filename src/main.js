const imports = {
    button: {
        updateClickCount: (num) => document.getElementById('numclicks').innerHTML = num.toString()
    }
};

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), imports)
    .then(obj => {

        const exports = obj.instance.exports;

        document.getElementById('click').addEventListener('click', () => {

            exports.onClick();
        });

    }).catch((err) => console.error(err));