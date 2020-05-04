/*fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(instance.exports.main());
}).catch(console.error); //run code */



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


function compile() { // Compiles to .wat file

// Reset all values
var editor = document.getElementById("editor");
var contents = editor.innerText;
var lines = contents.split("\n");
var command = "";
var commandOffset = 0;
var scope = "";
var greaterScope = "";
var variables = [];
var headerOutput = ['(func (export "main") ', '(result i32) '];
var stackOutput = "";
var exportOutput = ""; // delete
if(cln) {
  cln = 0;
}
if(cwn) {
  cwn = 0;
}


for(var cln = 0; cln <= lines.length-1; cln++) { // checks and compiles each line
  // cln = currentLineNumber
  let currentLineText = lines[cln];
  let words = currentLineText.split(" ");
  for(var cwn = 0; cwn <= words.length-1; cwn++) { // checks and compiles each word
    let currentWord = words[cwn];
    /**
     * number x = num1
     * Creates a number variable.
     */
    if(currentWord == "number" && command !="comment") {
      command = "number";
      scope = "variable";
      commandOffset = cwn;
    }
    /**
     * add n1 n2
     * Adds two numbers. Can be constants or variables.
     */
    else if(currentWord == "add" && command !="comment") {
      command = "add";
      commandOffset = cwn;
    }
    /**
     * subtract n1 n2
     * Subtracts the first number from the second. Can be constants or variables.
     */
    else if (currentWord == "subtract" && command !="comment") {
      command = "subtract";
      commandOffset = cwn;
    } 
    /**
     * multiply n1 n2
     * Multiplies the two numbers. Can be constants or variables.
     */
    else if (currentWord == "multiply" && command !="comment") {
      command = "multiply";
      commandOffset = cwn;
    }
    /**
     * divide n1 n2
     * divide the first number from the second. Can be constants or variables.
     */
    else if (currentWord == "divide" && command !="comment") {
      command = "divide";
      commandOffset = cwn;
    } 
    /**
     * // && /; e.g. // comment /;
     * Allows for commenting. // is start, /; is end. All comments are "multiline" in a sense.
     */
    else if (currentWord == "//") {
      command = "comment";
      commandOffset = cwn;
    }
    else if (currentWord == "/;") {
      if(command == "comment") {
        command = "";
      } else {
        console.warn("Comment end provided but no comment was started. Line " + cln + ", word "+ cwn + ".")
      }
    }
    /**
     * ;
     * Ends a command. Use after all commands except commands where there are other ways to stop them (e.g. comment).
     */
    else if (currentWord == ";" && command !="comment") {// makes sure comments are not unintentionally ended
        command = "";
        commandOffset = 0;
    }
    else if(currentWord == " " || currentWord == "\n" || currentWord == "") {
      // this is a thing that most browser do to the end of editable pre elements. This is the best way around it.
    }
    /**
     * Runs if the current word is not a starting word. Could be a constant or variable name
     */
    else { // not a starting word
      if(command == "") {
        console.error("The command at line " + cln + ", word "+ cwn + " is not a valid command.");
        console.log(currentWord);
      } else if(command == "add") {
        if(cwn-commandOffset > 2) { // Too many arguments
          console.error("Error: Two arguments expected for add command, but got more.")
        } else {
          if(isNaN(parseInt(currentWord))) { // is string
            if(variables.includes(currentWord)) { // is variable
            // come back to
            } else {
              console.error(currentWord + " is not a variable. Declare it before using it."); // assumes not a typo
            }
          } else { // is constant
            stackOutput += (`i32.const `+currentWord+"\n");
            if(cwn-commandOffset == 2) {
              stackOutput += (`i32.add` + "\n");
            }
          }
        }
        
      }

      if(scope == "variable") {
        /**
         * Checks to see if part of an equality, otherwise creates variable
         */
        if(currentWord == "=") {
          if(command.includes("equal")) { // proper equality use

          } else {
            console.error("The equal sign at line "+cln+" word "+cwn+" is not used in the right place.")
          }
        }
        if(command == "number") {
          /**
           * Create a new number (int) variable. Checks if variable already exists. If variable already exists, throws warning but still runs equation
           */
          if (!variables.includes(currentWord)) { // New variable
          // check if allowed ie starts with a number
          if(isNan(parseInt(currentWord.substring(0,1)))) { // does not start with a number
            command = "number-equal";
            headerOutput.push("(local $"+currentWord+" i32)");
            variables.push(currentWord);
          } else { // starts with number
            console.error("Error: variables cannot start with a number. Line "+cln+" word "+cwn+".")
          }
            
          } else { // existing variable, throws warning as described above
            console.warn("There is already a variable named "+ currentWord +". Line "+cln+" word "+cwn+". Running anyway...")
            command = "number-equal";
          }
          
        }
      }
      
    }
    

  }
}

/**
 * Exporting/Compiling
 */
var finalOutput = "";
finalOutput += "(module \n" + headerOutput.join('')+"\n"+stackOutput+"))";
//console.log(finalOutput);
document.getElementById("compiled").innerText = finalOutput;



/**
* Checks if there is an unending comment. Warning because unending commebts are technically legal though advised against heavily.
*/
if(command == "comment") {
  console.warn("Unending comment found at line " + cln + ", word "+ cwn + ".");
}


}


/* Example code for adding
(func (param $p i32)
  local.get $p
  local.get $p
  i32.add)

*/
