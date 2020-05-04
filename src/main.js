fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(instance.exports.main(11));
}).catch(console.error); //run code 



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
var command = ""; // command to execute
var commandOffset = 0; // allows commands to be executed anywhere in the spacing
var currentVariable = ""; // allows equalities to know what variable to operate on
var scope = ""; // number or decimal
var greaterScope = ""; // function?
variables = [];
var headerOutput = ['(func (export "main") '];
var localHeaderOutput = [];
var stackOutput = "";
var exportOutput = "";
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
    // VARIABLES
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
     * decimal x = num1
     * Creates a decimal variable.
     * NOT IMPLEMENTED YET
     * come back to
     */
    /*if(currentWord == "number" && command !="comment") {
      command = "number";
      scope = "variable";
      commandOffset = cwn;
    }*/
    // MATH
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
    // OTHER
    /**
     * ouput num1
     * outputs the variable specified. Constants cam be used, though there is no point. Note: Due to how WebAssembly (the compiled language) works, only one export can be specified per function.
     */
    else if (currentWord == "output") {
      command = "output";
      scope = "output";
      commandOffset = cwn;
    }
    /**
     * number x = input
     * Allows a variable to be input through javascript. If no input or too many inputs are specified during runtime, the code will fail, so use input only when you are certain
     * that an input will be used (you could check if it exists using an if statement if you are not sure if it will be used to get around this).
     * Note: inputs are managed in javascript in order, so suggested syntax is putting a comment which says what number input it is. Example:
     * number x = input // 0 /; ;
     */
    else if (currentWord == "input") {
      if(scope == "variable") {
        if(command == "number-set") { // not a decimal
          command = "input";
          localHeaderOutput.splice(localHeaderOutput.indexOf("(local $"+currentVariable+" i32) "), 1);
          headerOutput.push("(param $"+currentVariable+" i32) ");
          commandOffset = cwn;
        } else if(command == "decimal") {
          /*command = "input";
          headerOutput.push("(param $"+currentVariable+" f64) ");
          localHeaderOutput.splice(localHeaderOutput.indexOf("(local $"+currentVariable+" f64) "), 1, "(param $"+currentVariable+" f64) ");
          commandOffset = cwn;*/ // come do later
        }
        
      } else {
        console.error("Fatal Error: Input command used outside of variable");
      }
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
        scope = "";
        currentVariable = "";
        
    }
    else if(currentWord == " " || currentWord == "\n" || currentWord == "") {
      // this is a thing that most browser do to the end of editable pre elements. This is the best way around it.
    }
    /**
     * Runs if the current word is not a starting word. Could be a constant or variable name
     */
    else { // not a starting word
      if(command == "") {
        console.error("The command "+currentWord+" at line " + cln + ", word "+ cwn + " is not a valid command.");
      } 
      /**
       * Addition:
       * 1. Checks if two arguments
       * 2. Checks if it is a variable or a constant
       *  -if constant, adds.
       *  -if variable,
       * 3. checks if variable exists
       * 4. adds variable
       */
      else if(command == "add") {
        if(cwn-commandOffset > 2) { // Too many arguments
          console.error("Error: Two arguments expected for add command, but got more.")
        } else {
          if(isNaN(parseInt(currentWord))) { // is string
            if(variables.includes(currentWord)) { // is variable
              if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
                stackOutput += (`get_local $`+currentWord+"\n");
              } else { // No compatibility
                stackOutput += (`local.get $`+currentWord+"\n");
              }

            } else {
              console.error(currentWord + " is not a variable. Declare it before using it."); // assumes not a typo
            }
          } else { // is constant
            stackOutput += (`i32.const `+currentWord+"\n");
          }
          if(cwn-commandOffset == 2) {
              /**
               * Checks if it should be a variable equality by checking if currentVariable is set.
               */
              if(!currentVariable) { // not in a variable, print last thing
                if(scope == "output") {
                  exportOutput = (`i32.add` + "\n")
                } else {
                  stackOutput += (`i32.add` + "\n");
                }
                
              } else { // in a variable. set variable to addition problem
                if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
                  stackOutput += (`(set_local $` + currentVariable + " (i32.add))\n");
                } else { // NOT COMPATIBILITY
                  stackOutput += (`(local.set $` + currentVariable + " (i32.add))\n");
                }
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
            if(command == "number-equal") { // allows for constants etc. to be recognized as equals.
              command = "number-set";
            }
          } else {
            console.error("The equal sign at line "+cln+" word "+cwn+" is not used in the right place.");
          }
        }
        /**
         * Checks to see if it should be equaling a number constant
         * CONSTANT
         */
        if(command=="number-set" && !isNaN(parseInt(currentWord.substring(0,1)))) { // starts with a number- variables can't
          if(variables.includes(currentVariable)) { // makes sure variable exists
            if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
              stackOutput += "(set_local $"+currentVariable+" (i32.const "+currentWord+"))\n";
            } else { // NO COMPATIBILITY
              stackOutput += "(local.set $"+currentVariable+" (i32.const "+currentWord+"))\n";
            }
            
          } else {
            console.error("No variable with name"+currentVariable+"exists. Line "+cln+" word "+cwn+".");
          }
          
        }

        if(command == "number") {
          /**
           * Create a new number (int) variable. Checks if variable already exists. If variable already exists, throws warning but still runs equation
           */
          if (!variables.includes(currentWord)) { // New variable
          // check if allowed ie starts with a number
            if(isNaN(parseInt(currentWord.substring(0,1)))) { // does not start with a number
              command = "number-equal";
              currentVariable = currentWord;
              localHeaderOutput.push("(local $"+currentWord+" i32) ");
              variables.push(currentWord);
            } else { // starts with number
              console.error("Error: variables cannot start with a number. Line "+cln+" word "+cwn+".");
            }
          } else { // existing variable, throws warning as described above
            console.warn("There is already a variable named "+ currentWord +". Line "+cln+" word "+cwn+". Running anyway...");
            command = "number-equal";
            currentVariable = currentWord;
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
headerOutput.push('(result i32) '); // makes sure params work right
finalOutput += "(module \n" + headerOutput.join('') + localHeaderOutput.join('') + "\n"+stackOutput+exportOutput+"))";
//console.log(finalOutput);
document.getElementById("compiled").innerText = finalOutput;



/**
* Checks if there is an unending comment. Warning because unending commebts are technically legal though advised against heavily.
*/
if(command == "comment") {
  console.warn("Unending comment found at line " + cln + ", word "+ cwn + ".");
} 
/**
* Checks if there is an unending command. Errors because it can cause many issues.
*/
else if(command != "") {
  console.error("The command "+command+" is not ended.")
}


}


/* Example code for adding
(func (param $p i32)
  local.get $p
  local.get $p
  i32.add)

*/
