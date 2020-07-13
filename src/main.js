var instance = null;

function bench(name, f) {
    var start = Date.now();
    f();
    console.log(name, Date.now() - start, "ms");
}

function fib(n) {
    if (n < 2) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

function jsFib(n) {
    bench("JS:", function(){
        console.log(fib(n));
    });
}

function cFib(n) {
    bench("C:", function(){
        console.log(instance.exports.fib(n));
    });
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var hoge = document.getElementById("hoge");
  hoge.disabled = false;
  hoge.addEventListener("click", function() {
    var num = Number(document.getElementById("num").value);
    cFib(num);
    jsFib(num);
  });
}).catch(console.error);
