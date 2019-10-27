var calculator = null;

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
 calculator = instance.exports;
}).catch(console.error);

function add()
{
  if(!calculator)
  {
    alert("Calculator not been load");
    return;
  }

  var x = document.querySelector("#x").value;
  var y = document.querySelector("#y").value;

  var result = calculator.add(x, y);

  document.querySelector("#result").value = result;

}

function sub()
{
  if(!calculator)
  {
    alert("Calculator not been load");
    return;
  }

  var x = document.querySelector("#x").value;
  var y = document.querySelector("#y").value;

  var result = calculator.sub(x, y);

  document.querySelector("#result").value = result;

}

function mul()
{
  if(!calculator)
  {
    alert("Calculator not been load");
    return;
  }

  var x = document.querySelector("#x").value;
  var y = document.querySelector("#y").value;

  var result = calculator.mul(x, y);

  document.querySelector("#result").value = result;

}

function div()
{
  if(!calculator)
  {
    alert("Calculator not been load");
    return;
  }

  var x = document.querySelector("#x").value;
  var y = document.querySelector("#y").value;

  var result = calculator.div(x, y);

  document.querySelector("#result").value = result;

}