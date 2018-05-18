const { greet, Game } = wasm_bindgen;
let lastKey = 37;
let game = false;
let gameArea = null;
let gameAreaContext = null;

function setKey(event) {
  lastKey = event.keyCode;
  start_snake();
}

function getKey() {
  return lastKey;
}

function logValue(str) {
  console.log(str);
}
function drawFood(x, y) {
  var img = new Image()
  img.src = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAoAAAAKCAMAAAC67D+PAAAAD1BMVEUisUy5elftHCT/gID///8wiCrhAAAAMUlEQVR4AT3KwQkAUQxCQeOf/mteCGEfCHMwJAyWmWObaYm+btJn7SfSOywvcSLUzgc4DwENsWMNEAAAAABJRU5ErkJggg=="
  img.onload = () => gameAreaContext.drawImage(img, x - 5, y - 5);
}

function eraseDot(x, y, radius) {
  gameAreaContext.clearRect(x-6, y-6, radius + 2, radius + 2);
}

function getRandom() {
  
}

function drawDot(x, y, radius) {
  gameAreaContext.beginPath();
  gameAreaContext.arc(x, y, radius, 0, 2 * Math.PI);
  gameAreaContext.stroke();
}

function gameLoop() {
  if(game) {
    game.increment();
    setTimeout(gameLoop, 100)
  }
}

function startGame() {
  console.log('Starting Snake...')
  window.onkeydown = (event) => setKey(event);
  gameArea = document.getElementById("gameArea");
  gameAreaContext = gameArea.getContext("2d");

  if(game) {
    console.log('Game is already Running!');
    return;
  }

  game = Game.new();
  gameLoop();
}

function endGame() {
  console.log('Ending Snake...')
  if(!game) {
    console.log('Game is already Over!');
    return;
  }

  game = false;
}

// Load and instantiate the wasm file, and we specify the source of the wasm
// file here. Once the returned promise is resolved we're ready to go and
// use our imports.
wasm_bindgen('../out/main_bg.wasm').then(startGame);
