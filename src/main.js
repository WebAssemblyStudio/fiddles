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

  // exports.test(3);
  testMultiply(exports);


}).catch(console.error);


const count = 50000;

function testOneMultiply(exports) {
    var x = getRandom(2);
    var y = getRandom(2);
    var r = exports.multiply(x, y);
    console.log(x + " * " + y + " = " + r);
}

function testMultiply(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    // var x = getRandom(2);
    // var y = getRandom(2);
    var r = exports.multiply(0.2, 0.1);
    if (i % 1000 === 0) {
      //console.log(x + " * " + y + " = " + r);
      console.log(r);
    }
  }
  var end = new Date();
  console.log(end.getTime() - start.getTime());
}

function testAdd(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = exports.add(0.2, 0.1);
    if (i % 1000 === 0) {
      console.log(">> " + r);
    }
  }
  var end = new Date();
  console.log(end.getTime() - start.getTime());
}

function testSubtract(exports) {
  var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = exports.subtract(0.2, 0.1);
    if (i % 1000 === 0) {
      console.log(">> " + r);
    }
  }
  var end = new Date();
  console.log(end.getTime() - start.getTime());
}

function testDivide(exports) {
var start = new Date();
  for (var i = 0; i < count; i++) {
    var r = exports.divide(100, 200.123456);
    if (i % 1000 === 0) {
      console.log(">> " + r);
    }
  }
  var end = new Date();
  console.log(end.getTime() - start.getTime());
}

function getRandom(x){
  return Math.random().toFixed(x);
};