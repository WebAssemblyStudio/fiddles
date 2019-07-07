WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(_msg, _file, line, column) {
      console.error("abort called at main.ts:" + line + ":" + column);
      console.log(_msg, _file, line, column)
    }
  },
  /* 
    console: {
    log: (value) => {
      console.log(value);
    }
  }-
   */
}).then(result => {
  const exp = result.instance.exports;
  // document.getElementById("container").textContent = "Result: " + exp.add(19, 23);
  console.log(result)
  console.log(result.instance)
  //console.log(exp)

  console.error('INIT')
  const canvasW = 20, canvasH = 20;
  let offset = 0
  /*
  const pixelPuffer = new Uint8ClampedArray(new ArrayBuffer(canvasH * canvasW * 4))
  const pixel = new Uint8ClampedArray(exp.memory.buffer, offset).set(pixelPuffer);
  console.log({pixelPuffer})
  console.log({pixel})
  console.log(exp.init(0, 200, 200))
  offset += pixelPuffer.length
  
*/
  console.log({ offset })
  // dummy img with own buffer
  const imgBuffer = new Uint8ClampedArray([
    46, 38, 23, 255, 112, 103, 69, 255, 90, 79, 36, 255, 113,
    103, 68, 255, 125, 120, 100, 255, 134, 141, 90, 255, 142, 157, 60,
    255, 121, 131, 45, 255, 98, 107, 41, 255, 74, 86, 37,
    255, 71, 69, 35, 255, 132, 117, 94, 255, 103, 92, 52,
    255, 113, 105, 69, 255, 124, 115, 93, 255, 101, 103, 72,
    255, 75, 89, 36, 255, 62, 77, 31, 255, 56, 69, 32, 255, 54, 69, 32, 255,
    81, 81, 45, 255, 82, 68, 48, 255, 107, 110,
    74, 255, 115, 105, 73, 255, 82, 69, 42, 255, 85,
    78, 60, 255, 80, 79, 54, 255, 52, 72, 31, 255, 47, 70,
    28, 255, 47, 67, 27, 255, 76, 71, 42, 255, 63, 58, 43,
    255, 102, 108, 82, 255, 82, 93, 57, 255, 66, 58, 37, 255,
    96, 85, 56, 255, 123, 104, 75, 255, 86, 94,
    54, 255, 48, 77, 32, 255, 50, 69, 27, 255, 75, 69, 41,
    255, 78, 93, 67, 255, 72, 72, 58, 255, 73, 86, 51, 255, 77, 73, 37, 255,
    138, 127, 90, 255, 164, 152, 117, 255, 104, 110, 72, 255, 55, 79, 44,
    255, 55, 73, 37, 255, 81, 70, 43, 255, 74, 91, 57, 255, 40, 48, 30, 255,
    95, 93, 61, 255, 68, 70, 24, 255, 98, 94, 49, 255, 137, 130, 80, 255, 117, 123, 74, 255,
    54, 76, 41, 255, 54, 72, 36, 255, 87, 76, 50, 255, 55, 67, 35, 255, 6, 15, 0, 255, 85,
    85, 67, 255, 67, 68, 32, 255, 70, 68, 24, 255, 95, 87, 36, 255, 105, 107, 59, 255, 50, 70, 35, 255, 51, 67, 30, 255,
  ])
  const img = new ImageData(imgBuffer, 7, 10);
  console.log({ img });
  // size of img buffer
  // console.log(img.data)
  console.log('IMG Bytes: ', img.data.byteLength)

  const checkSum = img.data.reduce((a, e) => a + e, 0)
  console.log({ checkSum })

  // console.log(exp.memory.buffer)
  // add img buffer to memory: Crete a view over the buffer and set use the viewer to set the data
  new Uint8ClampedArray(exp.memory.buffer, offset).set(img.data);
  
  // console.log(exp.memory.buffer)
  console.log(img.width, img.height, offset)
  const addNode1 = exp.addNode(img.width, img.height, offset);
  console.log({ addNode1 })

  const count1 = exp.count();
  console.log({ count1 })
  const realSum1 = exp.checkSum(0)
  console.log({ realSum1 })


  /// SECOND IMAGE


  // create 2. image
  const img2 = new ImageData(imgBuffer, 7, 10);
  console.log({ img2 })

  // change first value (46) to 45
  // wichtig: img 1 wird auch verändert, da der selbe imgBuffer zugrunde liegt und der direkt über den view verändert wird
  img2.data[0] = 45
  console.log('IMG Bytes: ', img2.data.byteLength)
  const checkSum2 = img2.data.reduce((a, e) => a + e, 0)
  console.log({ checkSum2 })

  // update offset 
  offset += img2.data.byteLength
  new Uint8ClampedArray(exp.memory.buffer, offset).set(img2.data);
  // console.log(exp.memory.buffer)
  console.log(img2.width, img2.height, offset)
  const addNode2 = exp.addNode(img2.width, img2.height, offset);
  console.log({ addNode2 })
  const count2 = exp.count();
  console.log({ count2 })
  const realSum2 = exp.checkSum(1)
  console.log({ realSum2 })


}).catch(console.error);
