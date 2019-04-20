const { greet } = wasm_bindgen;

function runApp() {
  check_modify_and_return_baz_in_js = (baz) => {
      console.log(baz.field1);
      console.log(baz.field2());
      baz.field1 = 1.23;
      baz.setField2(314);
      return baz;
  };
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error);
