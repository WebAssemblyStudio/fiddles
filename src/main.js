const { includes } = wasm_bindgen;
const run = ()=> {
  
 runWasmFn100Times(()=> includes("helloWord", "hello"));
  
 runJsFn100Times(()=>{ 
   "helloWord".includes("hello");   
  });

};

wasm_bindgen('../out/main.wasm').then(() => run());

