const { main } = wasm_bindgen;

function runApp() {
    main();
}

const old = WebAssembly.instantiate;
WebAssembly.instantiate = (x, y) =>
    old(
        x,
        Object.assign(
            {
                env: {
                    struct_: (a, b) => {
                        alert(`${a} ${b}`);
                    },
                    enum_: (a, b, c, d) => {
                        alert(`${a} ${b} ${c} ${d}`);
                    },
                }
            },
            y
        )
    );

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
