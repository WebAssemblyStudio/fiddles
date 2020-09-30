
// 判斷是否支援，有支援才載入wasm，並在載入完成後替換掉原本較慢的方法
if ('WebAssembly' in window) {
  WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
    main: {
      log(s) {
        // console.log(s);
        alert(s);
      }
    },
    env: {
      abort(_msg, _file, line, column) {
        console.error("abort called at main.ts:" + line + ":" + column);
      }
    },
  }).then(result => {
    const exports = result.instance.exports;
    let testWasm = false;

    // for test
    if(testWasm) {
      // 有支援的瀏覽器則做替換
      MathUtil.decimal.add = exports.add;
      MathUtil.decimal.subtract = exports.subtract;
      MathUtil.decimal.multiply = exports.multiply;
      MathUtil.decimal.divide = exports.divide;
    }

    testAdd(exports);
    testSubtract(exports);
    testMultiply(exports);
    testDivide(exports);


  }).catch(console.error);
}

const count = 50000;


function testAdd(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.add(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  console.log("testAdd : " + (end.getTime() - start.getTime()) + " ms");
}

function testSubtract(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.subtract(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  console.log("testSubtract : " + (end.getTime() - start.getTime()) + " ms");
}

function testMultiply(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.multiply(0.2, 0.1);
    // if (i % 1000 === 0) {
    //   console.log(r);
    // }
  }
  var end = new Date();
  console.log("testMultiply : " + (end.getTime() - start.getTime()) + " ms");
}

function testDivide(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = MathUtil.decimal.divide(100, 200.123456);
    // if (i % 1000 === 0) {
    //   console.log(">> " + r);
    // }
  }
  var end = new Date();
  console.log("testDivide : " + (end.getTime() - start.getTime()) + " ms");
}

function getRandom(x) {
  return Math.random().toFixed(x);
};