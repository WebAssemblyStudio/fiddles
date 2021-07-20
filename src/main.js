function get_file_name_input() {
  return document.getElementById('file_name_input').value;
}

fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  document.getElementById("container").textContent = instance.exports.main();
  document.getElementById("create_file_btn").setAttribute("onclick", "instance.exports.create_file();");
  document.getElementById("file_form").setAttribute("action", "instance.exports.create_file();");
}).catch(console.error);

function display_text(text_str) {
  document.getElementById("container").textContent = String(text_str);
}
