const { fibonacci_rust } = wasm_bindgen;
const run = ()=> {
  
 runWasmFnOneTime(()=> fibonacci_rust(40));
  
 runJsFnOneTime(()=>{ 
   fibonacci(40);
  });

};

const fibonacci = (num) => {
  var a = 1, b = 0, temp;

  while (num >= 0){
    temp = a;
    a = a + b;
    b = temp;
    num--;
  }

  return b;
};

wasm_bindgen('../out/main.wasm').then(() => run());

