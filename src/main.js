/*fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  //document.getElementById("container").textContent = instance.exports.add(1,1);
}).catch(console.error); //run code */

var editor = document.getElementById("editor");
var contents = editor.innerText;
var lines = contents.split("\n");

var headerOutput = ["(func "];
var stackOutput = "";
var exportOutput = "";

var log = document.querySelector('#output');

['log','warn','error'].forEach(function (verb) {
    console[verb] = (function (method, verb, log) {
        return function (text) {
            method(text);
            // handle distinguishing between methods any way you'd like
            var msg = document.createElement('code');
            msg.classList.add(verb);
            msg.textContent = "\n"+text;
            log.appendChild(msg);
        };
    })(console[verb].bind(console), verb, log);
});

compile(); // compiles default text

document.getElementById("run").onclick = ()=>{ // whenever compile is pressed compile the code
  compile();
}

function compile() { // Compiles to .wat file

for(var cln = 0; cln <= lines.length-1; cln++) { // checks and compiles each line
  // cln = currentLineNumber
  let currentLineText = lines[cln];
  let words = currentLineText.split(" ");
  console.log(words);
  for(var cwn = 0; cwn <= words.length-1; cwn++) { // checks and compiles each word
  let currentWordText = words[cwn];
    console.log(words[cwn]);
  }
}

}


/* Example code for adding
(func (param $p i32)
  local.get $p
  local.get $p
  i32.add)

*/
