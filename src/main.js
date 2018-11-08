const { fibonacci_reccursive } = wasm_bindgen;
const run = ()=> {
  
 runWasmFnOneTime(()=> fibonacci_reccursive());
  
 runJsFnOneTime(()=>{ 
   fibonacci(40);
  });

};

const fibonacci = (num) => {
  if (num <= 1) return 1;

  return fibonacci(num - 1) + fibonacci(num - 2);
};

wasm_bindgen('../out/main.wasm').then(() => run());

