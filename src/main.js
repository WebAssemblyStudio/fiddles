var chat = document.getElementById("chat");

var colors = {
  "0": "#000000",
  "1": "#0000BF",
  "2": "#00BF00",
  "3": "#00BFBF",
  "4": "#BF0000",
  "5": "#BF00BF",
  "6": "#BFBF00",
  "7": "#BFBFBF",
  "8": "#404040",
  "9": "#4040FF",
  "a": "#40FF40",
  "b": "#40FFFF",
  "c": "#FF4040",
  "d": "#FF40FF",
  "e": "#FFFF40",
  "f": "#FFFFFF"
};

function getFormattedMessage(text) {
  var sanitized = "";

  for (var i = 0; i < text.length; i++) {
    var code = text.charCodeAt(i);
    if (code < 31 || code > 127)
      code = 63;
    else if (code == 37)
      code = 38;
    
    sanitized += String.fromCharCode(code);
  }

  sanitized += "\n&";

  var spans = [];

  var color = colors["f"];
  var index = sanitized.indexOf("&");
  while (index > -1) {
    var segment = sanitized.substring(0, index);

    if (segment.length > 0) {
      var span = document.createElement("span");
      span.style.color = color;
      span.innerText = segment;
      spans.push(span);
    }

    if (sanitized.length <= index + 1)
      break;

    var code = sanitized[index + 1].toLowerCase();
    color = colors[code] || color;

    sanitized = sanitized.substring(index + 2);
    index = sanitized.indexOf("&");
  }

  return spans;
}

function clearMessages() {
  while (chat.firstChild)
    chat.removeChild(chat.firstChild);
}

function addMessage(text) {
  var children = getFormattedMessage(text);

  while (children.length > 0)
    chat.appendChild(children.shift());

  chat.scrollTop = chat.scrollHeight;
}

var text = document.getElementById("text");
var submit = document.getElementById("submit");
var clear = document.getElementById("clear");

/* Placeholder for export */
function sendMessage(message) {
  addMessage("&0Galaxtone: &f" + message);
}

var textHistory = [];
var historyIndex = 0;
var currentText;

text.addEventListener("keydown", function(event) {
  if (event.key == "Enter") {
    if (text.value.length > 0) {
      sendMessage(text.value);

      textHistory.push(text.value);
      historyIndex = textHistory.length;

      text.value = "";
    }
  } else if (event.key == "ArrowUp") {
    if (historyIndex > 0) {
      if (historyIndex == textHistory.length)
        currentText = text.value;
      
      historyIndex--;

      text.value = textHistory[historyIndex];

      event.preventDefault();
    }
  } else if (event.key == "ArrowDown") {
    if (historyIndex < textHistory.length) {
      historyIndex++;

      if (historyIndex == textHistory.length)
        text.value = currentText;
      else
        text.value = textHistory[historyIndex];
      text.selectionStart = text.value.length;

      event.preventDefault();
    }
  }
});

submit.addEventListener("click", function() {
  if (text.value.length > 0) {
    sendMessage(text.value);

    history.push(text.value);
    historyIndex = textHistory.length;

    text.value = "";
  }
});

clear.addEventListener("click", function() {
  clearMessages();
});

throw "Error";

WebAssembly.instantiateStreaming(fetch("../out/main.wasm"), {
  main: {
    sayHello() {
      console.log("Hello from WebAssembly!");
    }
  },
  env: {
    abort(message, file, line, column) {
      alert("Abort! \"" + file + "\" (" + line + ":" + column + "):" + message);
    }
  },
}).then(result => {
  const exports = result.instance.exports;
  document.getElementById("container").textContent = "Result: " + exports.add(19, 23);
}).catch(console.error);
