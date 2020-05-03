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

var command = "";
var scope = "";
function compile() { // Compiles to .wat file

for(var cln = 0; cln <= lines.length-1; cln++) { // checks and compiles each line
  // cln = currentLineNumber
  let currentLineText = lines[cln];
  let words = currentLineText.split(" ");
  for(var cwn = 0; cwn <= words.length-1; cwn++) { // checks and compiles each word
    let currentWord = words[cwn];
    console.log(currentWord);
    /**
     * add n1 n2
     * Adds two numbers. Can be constants or variables.
     */
    if(currentWord == "add") {
      command = "add";
    }
    /**
     * subtract n1 n2
     * Subtracts the first number from the second. Can be constants or variables.
     */
    else if (currentWord == "subtract") {
      command = "subtract";
    } 
    /**
     * // && /; e.g. // comment /;
     * Allows for commenting. // is start, /; is end. All comments are "multiline" in a sense.
     */
    else if (currentWord == "//") {
      command = "comment";
    }
    else if (currentWord == "/;") {
      if(command == "comment") {
        command = "";
      } else {
        console.log("Comment end provided but no comment was started. Line" + cln + ", word "+ cwn + ".")
      }
    }
    /**
     * ;
     * Ends a command. Use after all commands except commands where there are other ways to stop them (e.g. comment).
     */
    else if (currentWord == ";") {
        command = "";
    }
    
    else {
      
    }
    if(command == "add") {
      //if()
    }
  }
}

}


/* Example code for adding
(func (param $p i32)
  local.get $p
  local.get $p
  i32.add)

*/
