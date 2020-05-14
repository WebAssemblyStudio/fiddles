fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  console.log(instance.exports.main(4));
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
var controlScope = []; // if statements etc
var functionScope = ""; // function?

variables = []; // list of variables for highlighting and checking if something is a variable for errors
var options = []; // user-specified options- compiler use only
var outputType = "i32";
var headerOutput = ['(func (export "main") '];
var localHeaderOutput = [];
var stackOutput = "";
var delayedStackOutput = [];
var whileDelayedStackOutput = [];
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
    // CONTROL FLOW
    /**
     * if (condition) { }
     * Runs what is inside of the curly brackets if the condition is true. Condition can be expressed with >, >= etc or a boolean variable.
     */
    if(currentWord == "if" && command !="comment") {
      /*if(controlScope == "if") {
        console.error("Unrecoverable Compiler Error: If statements cannot be declared inside of if statements. Line "+cln+" word "+cwn+".");
      }*/
      command = "if";
      scope = "";
      //controlScope.push("if");
      commandOffset = cwn;
    }
    /**
     * else { }
     * Runs what is inside of the curly brackets if the condition in an above if is false. Must have an if condition above
     */
    else if(currentWord == "else" && command !="comment") {
      if(command != "possible-else") {
        console.error("Else statement must have if. Line "+cln+" word "+cwn+".");
      } else {
        command = "else-start";
        scope = "";
        //controlScope.push("else");
        commandOffset = cwn;
      }
    }
    else if(currentWord == "(" && command !="comment") {
      if(command == "if") {
        stackOutput += "(if\n";
        command = "if-condition";
        var ifConditionType = "none";
        var numOfIfConditionStackEnds = 0;
      } else if (command == "while") {
        stackOutput += "(block\n(loop\n"; // note that it opens two parentheses unlike if which only opens one
        command = "while-condition";
        var whileConditionType = "none";
        var numOfWhileConditionStackEnds = 0;
      } else if (command == "for") {
        stackOutput += ""; // nothing because it has to be added after initialization phase.
        command = "for-condition";
      }
      commandOffset = cwn;
    }
    else if(currentWord == "{" && command !="comment") {
      if(command.includes("start")) {
        if(command == "if-start") {
          stackOutput += " (then\n";
          command = "";
          controlScope.push("if");
        }
        if(command == "else-start") {
          stackOutput += " (else\n";
          command = "";
          controlScope.push("else");
        }
        if(command == "while-start") {
          command = ""; // rest is handled at end of )
        }
      } else {
        console.error("No check done for statement on line "+cln+" word "+cwn+".")
      }
      commandOffset = cwn;
    }
    else if(currentWord == "}" && command !="comment") {
      if(controlScope) {
          if(words[cwn+1] != "else") { // this is bad because no spaces but also I think this is the best way to do it come back to do come do later
            for(let x = controlScope.length-1; x>=0; x--) { // for everything in controlscope
              if(controlScope[x]!="for"||controlScope[x]!="while") {
                if(controlScope[x] == "if") {
                  stackOutput += " )\n)\n"; // ends the then and the if.
                  controlScope.pop();
                } else if (controlScope[x] == "else") {
                  stackOutput += " )\n)\n"; // ends the then and the if.
                  controlScope.pop();
                } else if (controlScope[x] == "while"||controlScope[x] == "for") { // same for for and while
                  stackOutput += "(br 0)\n)\n)\n"; // ends the block, loop and adds a branch at the end. 
                  controlScope.pop();
                } else {
                  stackOutput += "(; ERROR: Unknown controlScope value of "+controlScope[x]+" ;) )\n";
                  console.error("Unknown controlScope value of "+controlScope[x]+".");
                }
                
              } else {
                // do other stuff come do later
                // check if for or while, then add br_if and stuff like that
              }
            }
            //stackOutput += " )\n)\n"; // ends the then and the if.
          } else {
            stackOutput += " )\n"; // ends the then and the if.
            controlScope.pop();
            command = "possible-else";
          }
      } else {
        console.error("Control end given with no start provided. Line "+cln+" word "+cwn+".")
      }
      commandOffset = cwn;
    }
    /**
     * LOOPS
     */
    /**
     * while ( condition ) { }
     * Runs the code inside of the curly brackets while the condition is true.
     */
    else if(currentWord == "while" && command !="comment") {
      command = "while";
      scope = "";
      controlScope.push("while");
      commandOffset = cwn;
    }
    /**
     * for ( initialization ; condition ; do last ; ) { }
     * Runs the code inside of the curly brackets while the condition is true.
     * Example:
     * for ( number b = 0 ; b to 10 ; b = add b 1 ; ) { }
     */
    else if(currentWord == "for" && command !="comment") {
      command = "for";
      scope = "";
      controlScope.push("for");
      var semiForNum = 0;
      commandOffset = cwn;
    }
    // VARIABLES
    /**
     * number x = num1
     * Creates a number variable.
     */
    else if(currentWord == "number" && command !="comment") {
      command = "i32";
      scope = "variable";
      commandOffset = cwn;
    }
    /**
     * decimal x = num1
     * Creates a decimal variable.
     * NOT IMPLEMENTED YET
     * come back to
     */
    else if(currentWord == "decimal" && command !="comment") {
      command = "f64";
      scope = "variable";
      commandOffset = cwn;
    }
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
      if(!controlScope.includes("if")&&!controlScope.includes("while")) {
        command = "output";
        scope = "output";
        commandOffset = cwn;
      } else {
        if(!options.includes("output-warning")) { // respect compiler options
          console.warn("An output specified in a conditional statement will not run inside of the conditional statement. Line "+cln+" word "+cwn+".");
        }
      }
      
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
        if(command == "variable-set") { // not a decimal
          command = "input";
          localHeaderOutput.splice(localHeaderOutput.indexOf("(local $"+currentVariable+" "+variables[variables.indexOf(currentVariable)+1]+") "), 1);
          headerOutput.push("(param $"+currentVariable+" "+variables[variables.indexOf(currentVariable)+1]+") ");
          commandOffset = cwn;
        }
        
      } else {
        console.error("Fatal Error: Input command used outside of variable");
      }
    }
    /**
     * options_opt1_opt2_opt3
     * Sets compiler options
     */
    else if (currentWord.includes("options")) {
      if(currentWord.includes("output-warning")) {
        options.push("output-warning");
      }
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
        scope = "";
        currentVariable = "";
        
        if(controlScope[controlScope.length-1] == "for") {
          semiForNum += 1;
          if(semiForNum > 3) {
            console.error("Too many arguments for for conditional. Line "+cln+" word "+cwn+".");
          }
        }
    }
    else if(currentWord == " " || currentWord == "\n" || currentWord == "") {
      // this is a thing that most browser do to the end of editable pre elements. This is the best way around it.
    }
    /**
     * Runs if the current word is not a starting word. Could be a constant or variable name
     */
    else { // not a starting word
      if(command == "") {
        if(variables.includes(currentWord)) {
          scope="variable";
          currentVariable = currentWord;
          if(variables[variables.indexOf(currentWord)+1] == "i32"||variables[variables.indexOf(currentWord)+1] == "f64") {
            command = "variable-equal";
          }
        } else {
          console.error("The command "+currentWord+" at line " + cln + ", word "+ cwn + " is not a valid command.");
        }
        
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
              if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY CHANGE TO FUNCTION
                stackOutput += (`get_local $`+currentWord+"\n");
              } else { // No compatibility
                stackOutput += (`local.get $`+currentWord+"\n");
              }

            } else {
              console.error(currentWord + " is not a variable. Declare it before using it. Line "+cln+" word "+cwn+"."); // assumes not a typo
            }
          } else { // is constant
            stackOutput += (`i32.const `+currentWord+"\n");
          }
          if(cwn-commandOffset == 2) {
              /**
               * Checks if it should be a variable equality by checking if currentVariable is set.
               */
              if(!currentVariable) { // not in a variable, print last thing
                // This is equivalent to just outputting so it throws a warning
                if(scope != "output") {
                  console.warn("The add statement at line "+cln+" word "+cwn+" is not valid. Consider using the output keyword.");
                }
                if(controlScope.includes("if")) { // if statement output works weird
                  if(!options.includes("output-warning")) { // respect compiler options
                    console.error("A lone add command specified in an if statement will not run inside of the if statement. Consider using the output keyword. Line "+cln+" word "+cwn+".");
                  }
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
        
      } else if(command == "output") {
        /**
         * OUTPUT
         * 1. Checks if an output is already specified, if yes throws error (WHEN ADD MULTIPLE MODULES/FUNCTIONS IT SHOULD NOT ALWAYS THROW ERROR) come back to
         * 
         */
        if(exportOutput) {
          if(!options.includes("output-warning")) { // if output warning is turned on (default)
            console.warn("Warning: More than one output in a module can not be specified. Will use most recent call. Line "+cln+" word "+cwn+".");
          }
        }
        // Continues because it is a warning
        if(isNaN(parseInt(currentWord))) { // is string
          if(variables.includes(currentWord)) { // is a declared variable
            outputType = variables[variables.indexOf(currentWord)+1];
            if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
              exportOutput = "get_local $"+currentWord+"\n";
            } else { // NO COMPATIBILITY
              exportOutput = "local.get $"+currentWord+"\n";
            }
          } else {
            console.error(currentWord + " is not a variable. Declare it before using it."); // assumes not a typo
          }
        } else { // is constant
          if(!options.includes("output-warning")) { // if output warning is turned on (default)
            console.warn("An output specified as a constant has no purpose. Compiling anyway...");
          }
          if(currentWord.includes(".")) { // currentWord is a float/decimal, includes decimal point
            exportOutput = "f64.const "+currentWord+"\n";
            outputType = "f64";
          } else { // integer/number
            exportOutput = "i32.const "+currentWord+"\n";
            outputType = "i32";
          }
          
        }
        
      } else if (command == "if-condition") {
        if(currentWord == ")") {
          command = "if-start";
          delayedStackOutput.push(" "+")".repeat(numOfIfConditionStackEnds)+"\n"); // ends the check statement
          delayedStackOutput = delayedStackOutput.join('');
          stackOutput += delayedStackOutput;
          delayedStackOutput = [];
        } else {
          if(currentWord == ">"||currentWord == "<"||currentWord == ">="||currentWord == "<="||currentWord == "=="||currentWord == "!=") {
            /**
             * 1. Determine what WebAssembly command to use
             * 2. Splice the command at the front
             * When compiler sees ) it adds a ) to the end of the if statement so no issues
             */
            let toUnshift = " (";
            numOfIfConditionStackEnds += 1;
            toUnshift += ifConditionType+".";
            toUnshift += getComparisonOperator(currentWord);
            toUnshift += "\n"; // adds newline for readability
            delayedStackOutput.splice(delayedStackOutput.length-1, 0, toUnshift);
          } else if(currentWord == "&&"){ // both
            delayedStackOutput.unshift("("+ifConditionType+".and\n");
            delayedStackOutput.push(")\n");
            //numOfIfConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "||"){ // this or that and both
            delayedStackOutput.unshift("("+ifConditionType+".or\n");
            delayedStackOutput.push(")\n");
            //numOfIfConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "!|"){ // this or that but not both
            delayedStackOutput.unshift("("+ifConditionType+".xor\n");
            delayedStackOutput.push(")\n");
            //numOfIfConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "!"){ // only run if whatever is not true. MUST BE PUT AT END
            delayedStackOutput.unshift("("+ifConditionType+".eqz\n");
            numOfIfConditionStackEnds += 1;
          } else if (!isNaN(parseInt(currentWord.substring(0,1)))) { // is number
            if(currentWord.includes(".")) { // currentWord is a float/decimal, includes decimal point
              if(ifConditionType != "f64" && ifConditionType != "none") {
                console.error("Type mismatch in if statementent. Attempted to compare number with decimal. Line "+cln+" word "+cwn+".")
              }
              delayedStackOutput.push("   (f64.const "+currentWord+")\n");
              ifConditionType = "f64";
            } else { // integer/number
              delayedStackOutput.push("   (i32.const "+currentWord+")\n");
              if(ifConditionType != "i32" && ifConditionType != "none") {
                console.error("Type mismatch in if statementent. Attempted to compare number with decimal. Line "+cln+" word "+cwn+".")
              }
              ifConditionType = "i32";
            }
          } else if (isNaN(parseInt(currentWord.substring(0,1)))) { // might be a variable
            if(variables.includes(currentWord)) { // is a variable
              ifConditionType = variables[variables.indexOf(currentWord)+1]; // allows for checking of type
              if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
                delayedStackOutput.push("   (get_local $"+currentWord+")\n");
              } else { // NO COMPATIBILITY
                delayedStackOutput.push("   (local.get $"+currentWord+")\n");
              }
            } else {
              console.error(currentWord + " is not a variable. Declare it before using it."); // assumes not a typo
            }
          }
          //delayedStackOutput.push(currentWord);
        }

        
      } else if (command == "while-condition") { // TO DO: USE WHILEDELAYSTACKOUTPUT
        if(currentWord == ")") {
          command = "while-start";
          whileDelayedStackOutput.unshift("(br_if 1 (i32.eqz "); // i32 because all operations return i32
          whileDelayedStackOutput.push(")"+")".repeat(numOfWhileConditionStackEnds)+")\n"); // ends the eqz and other things
         
          whileDelayedStackOutput = whileDelayedStackOutput.join('');
          stackOutput += whileDelayedStackOutput;
          whileDelayedStackOutput = [];
        } else {
          if(currentWord == ">"||currentWord == "<"||currentWord == ">="||currentWord == "<="||currentWord == "=="||currentWord == "!=") {
            /**
             * 1. Determine what WebAssembly command to use
             * 2. Splice the command at the front
             * When compiler sees ) it adds a ) to the end of the if statement so no issues
             */
            //let toUnshift = "(br_if 1 (";
            let toUnshift = "(";
            toUnshift += whileConditionType+".";
            numOfWhileConditionStackEnds += 1;
            toUnshift += getComparisonOperator(currentWord);
            toUnshift += " " // adds space for readability
            whileDelayedStackOutput.splice(whileDelayedStackOutput.length-1, 0, toUnshift);
          } else if(currentWord == "&&"){ // both
            whileDelayedStackOutput.unshift("("+whileConditionType+".and ");
            whileDelayedStackOutput.push(") ");
            //numOfWhileConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "||"){ // this or that and both
            whileDelayedStackOutput.unshift("("+whileConditionType+".or ");
            whileDelayedStackOutput.push(") ");
            //numOfWhileConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "!|"){ // this or that but not both
            whileDelayedStackOutput.unshift("("+whileConditionType+".xor ");
            whileDelayedStackOutput.push(") ");
            //numOfWhileConditionStackEnds doesnt change because we also add a ) to stop the old command
          } else if(currentWord == "!"){ // only run if whatever is not true. MUST BE PUT AT END
            whileDelayedStackOutput.unshift("("+whileConditionType+".eqz ");
            numOfWhileConditionStackEnds += 1;
          } else if (!isNaN(parseInt(currentWord.substring(0,1)))) { // is number
            if(currentWord.includes(".")) { // currentWord is a float/decimal, includes decimal point
              if(whileConditionType != "f64" && whileConditionType != "none") {
                console.error("Type mismatch in while statementent. Attempted to compare number with decimal. Line "+cln+" word "+cwn+".")
              }
              whileDelayedStackOutput.push("(f64.const "+currentWord+")");
              whileConditionType = "f64";
            } else { // integer/number
              whileDelayedStackOutput.push("(i32.const "+currentWord+")");
              if(whileConditionType != "i32" && whileConditionType != "none") {
                console.error("Type mismatch in while statementent. Attempted to compare number with decimal. Line "+cln+" word "+cwn+".")
              }
              whileConditionType = "i32";
            }
          } else if (isNaN(parseInt(currentWord.substring(0,1)))) { // might be a variable
            if(variables.includes(currentWord)) { // is a variable
              whileConditionType = variables[variables.indexOf(currentWord)+1]; // allows for checking of type
              if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
                whileDelayedStackOutput.push("(get_local $"+currentWord+")");
              } else { // NO COMPATIBILITY
                whileDelayedStackOutput.push("(local.get $"+currentWord+")");
              }
            } else {
              console.error(currentWord + " is not a variable. Declare it before using it."); // assumes not a typo
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
            if(command == "variable-equal") { // allows for constants etc. to be recognized as equals.
              command = "variable-set";
            }
          } else {
            console.error("The equal sign at line "+cln+" word "+cwn+" is not used in the right place.");
          }
        }
        /**
         * Checks to see if it should be equaling a number constant or variable and then sets
         * 
         */
        if(command=="variable-set" && currentWord != "=") {
          if(variables.includes(currentVariable)) { // makes sure variable exists
          if(!isNaN(parseInt(currentWord.substring(0,1)))) { // is a constant
            if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
              stackOutput += "(set_local $"+currentVariable+" ("+variables[variables.indexOf(currentVariable)+1]+".const "+currentWord+"))\n";
            } else { // NO COMPATIBILITY
              stackOutput += "(local.set $"+currentVariable+" ("+variables[variables.indexOf(currentVariable)+1]+".const "+currentWord+"))\n";
            }
            if(currentWord.includes(".")) { // decimal/float variable
              if(variables[variables.indexOf(currentVariable)+1] == "i32") {
                console.error("Decimal constant put where number constant should be. Line "+cln+" word "+cwn+".");
              }
            }
          } else { // is a variable
            if(variables[variables.indexOf(currentWord)+1] != "i32") { // if a different type
              console.error("Error: Type mismatch. Variable "+currentWord+" is a decimal, not a number. Line "+cln+" word "+cwn+".")
            }
            if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
              stackOutput += "(set_local $"+currentVariable+" (get_local $"+currentWord+"))\n";
            } else { // NO COMPATIBILITY
              stackOutput += "(local.set $"+currentVariable+" (local.get $"+currentWord+"))\n";
            }
          }
            
          } else {
            console.error(currentWord + " is not a variable. Declare it before using it. Line "+cln+" word "+cwn+".");
          }
          
        }

        if (controlScope[controlScope.length-1] == "for") { //currently in a for loop
          if(currentWord == ")") {
            controlScope[controlScope.length-1] = "for-start";
            stackOutput += "(block\n(loop\n(br_if 1 (i32.eqz ("+forData[1]+".eq (";
            if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
              stackOutput+= "get_local $"
            } else {
              stackOutput+= "local.get $"
            }
            stackOutput+=forData[0]+" ) (";

            if(!isNaN(parseInt(forData[2].substring(0,1)))) { // is a constant
              stackOutput += forData[1]+".const "+forData[2];
            } else { // is variable
              if(document.getElementById("compatibility").checked == true) { // COMPATIBILITY
                stackOutput+= "get_local $"
              } else {
                stackOutput+= "local.get $"
              }
              stackOutput += " ";
            }
            stackOutput += "))))\n";

            if(semiForNum < 3) {
              console.error("Not enough arguments provided for for conditional. Line "+cln+" word "+cwn+".");
            }
          } else {
            if(words[cwn+1] == "to") { // next word is to
              var forData = ["","",""];
              if(!isNaN(parseInt(currentWord.substring(0,1)))) { // is a constant
                console.error("Left side of for conditional must be a variable. Line "+cln+" word "+cwn+".");
              } else {
                if(variables.includes(currentWord)) {
                  forData[0] = currentWord;
                } else {
                  console.error(currentWord + " is not a variable. Declare it before using it. Line "+cln+" word "+cwn+".");
                }
              }
            }
          }
        }

        if(command == "i32"||command == "f64") {
          /**
           * Create a new number (int) variable. Checks if variable already exists. If variable already exists, throws warning but still runs equation
           */
          if (!variables.includes(currentWord)) { // New variable
          // check if allowed ie starts with a number
            if(isNaN(parseInt(currentWord.substring(0,1)))) { // does not start with a number
              currentVariable = currentWord;
              localHeaderOutput.push("(local $"+currentWord+" "+command+") ");
              variables.push(currentWord);
              variables.push(command);
              command = "variable-equal";
            } else { // starts with number
              console.error("Error: variables cannot start with a number. Line "+cln+" word "+cwn+".");
            }
          } else { // existing variable, throws warning as described above
            console.warn("There is already a variable named "+ currentWord +". Line "+cln+" word "+cwn+". Running anyway...");
            command = "variable-equal";
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
headerOutput.push('(result '+outputType+') '); // makes sure params work right
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



function getComparisonOperator(curword) {
  if(curword == "==") { // EQUAL
    return "eq";
  } else if(curword == "!=") { // NOT EQUAL
    return "ne";
  } else if(curword == ">") { // GREATER THAN
    return "gt_s";
  } else if(curword == "<") { // LESS THAN
    return "lt_s";
  } else if(curword == ">=") { // GREATER THAN OR EQUAL TO
    return "ge_s";
  } else if(curword == "<=") { // LESS THAN OR EQUAL TO
    return "le_s";
  } else {
    console.error(curword+" is not an operator. Line "+cln+" word "+cwn+".");
  }
}

