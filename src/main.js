fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  let table = document.getElementById("t");
  thead = table.createTHead();
  row = thead.insertRow()
  for (key of ["Javascript", "WebAssembly native"]) {
    let th = document.createElement("th");
    th.appendChild(document.createTextNode(key));
    row.appendChild(th);
  }
  for (let i=-1; i<=2; i+= 0.1) {
    row = thead.insertRow();
    let td = document.createElement("td");
    td.appendChild(document.createTextNode(instance.exports.exp2(i)));
    row.appendChild(td);
    td = document.createElement("td");
    td.appendChild(document.createTextNode(2**i));
    row.appendChild(td);
  }
}).catch(console.error);
