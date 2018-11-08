const { includes_static_for_1000_times } = wasm_bindgen;
const run = ()=> {
  
 runWasmFnOneTime(()=> includes_static_for_1000_times());
  
 runJsFnOneTime(()=>{ 
   for (let i = 0; i < 10000; ++i) {
   "helloWord".includes("hello");
   }
  });

};

wasm_bindgen('../out/main.wasm').then(() => run());

