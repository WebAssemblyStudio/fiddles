const { greet } = wasm_bindgen;

function showGreeting() {
  const containerElement = document.getElementById("container");

  const greeting = greet('JSConf Asia');
  containerElement.textContent = greeting;
}

wasm_bindgen('../out/main.wasm')
  .then(showGreeting)
  .catch(console.error);