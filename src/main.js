var output = document.querySelector("#output");
var input = document.querySelector("#input");

function clear() {
  output.value = "";
}

function print(message) {
  output.value += message;
  output.scrollTop = output.scrollHeight;
}

print("Code loaded!");

var moved_mouse = false;

output.addEventListener("mousedown", event => {
  moved_mouse = false;
});
output.addEventListener("mousemove", event => {
  if (output.selectionEnd - output.selectionStart > 0)
    moved_mouse = true;
});
output.addEventListener("mouseup", event => {
  if (!moved_mouse)
    input.focus();
});

var cursorInterval = 0;

input.addEventListener("focus", event => output.scrollTop = output.scrollHeight);
input.addEventListener("blur", )
var cursor = false;
setInterval(() => {
  clear();
  cursor = !cursor;
  if (cursor)
    print("█");
}, 450);

WebAssembly.instantiateStreaming(fecth('../out/main.wasm')).then((response) => {
  let instance = results.instance;
}).catch(console.error);
