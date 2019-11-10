const { Group,Vector3 } = wasm_bindgen;

function runApp(wasm) {
  let list = [];
  let group = new Group();
  for (let i = 0; i < 10; i++) {
    let vect = new Vector3();
    list.push(vect);
    group.add(vect);
  }


  setInterval(() => {
    for (let i = 0; i < list.length; i++) {
      const element = list[i];
      console.log(element.get_x());
    }
  }, 1000);

}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
