fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;

  const memory = instance.exports.memory;
  const n = 512;
  const arr1 = new Float32Array(n * n)
  const arr2 = new Float32Array(n * n)
  const memoryUsage = (3 * n * n * 4)
  console.log(memoryUsage);
  memory.grow(Math.ceil(memoryUsage / (65536)));
  const f32 = new Float32Array(memory.buffer);
  const p = performance.now();
  for(let run = 0; run < 50; run++) {
    const arr1Ptr = 0
    const arr2Ptr = arr1Ptr + arr1.length;  
    const resultPtr = arr2Ptr + arr2.length;

    f32.set(arr1, arr1Ptr);
    console.log(f32.slice(0, 32))
    f32.set(arr2, arr2Ptr);
    console.log(f32.slice(0, 32))
    
    const leftDim = n;
    const rightDim = n;
    const sharedDim = n;
    // 2 1 1 2

    const aOuterStep = n;
    const aInnerStep = 1;

    const bOuterStep = 1;
    const bInnerStep = n;

    const blockSize = 48;
    console.log(arr1Ptr, arr2Ptr, resultPtr);
    /* float* aValues, float* bValues, 
              unsigned int leftDim, unsigned int rightDim, 
            unsigned int sharedDim, unsigned int aOuterStep, unsigned int aInnerStep, 
            unsigned int bOuterStep,unsigned int bInnerStep,
            unsigned int blockSize,
            float* result */
    
    instance.exports.matmul(arr1Ptr * 4, arr2Ptr * 4, leftDim, rightDim, sharedDim, 
                            aOuterStep, aInnerStep, bOuterStep, bInnerStep,
                            blockSize, resultPtr * 4);

    const result = f32.slice(resultPtr, resultPtr + (128 * 128 * 4));

  }
  
  console.log((performance.now() - p) / 50);
  console.log(Object.keys(memory), memory.initial, memory.grow())
}).catch(console.error);
