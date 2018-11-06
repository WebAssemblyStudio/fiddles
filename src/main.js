const { includes } = wasm_bindgen;
const run = ()=> {
  
 runWasmFn100Times(()=> includes("helloWorld", "hello"));
  
 runJsFn100Times(()=>"helloWorld".includes("hello"));

};

wasm_bindgen('../out/main.wasm').then(() => run());

