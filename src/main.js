const { Universe } = wasm_bindgen;

const CELL_SIZE = 10;
const GRID_COLOR = "#CCCCCC";
const DEAD_COLOR = "#FFFFFF";
const ALIVE_COLOR = "#000000";

// These must match `Cell::Alive` and `Cell::Dead` in `src/lib.rs`.
const DEAD = 0;
const ALIVE = 1;

let universe;
let width;
let height;
const canvas = document.getElementById("game-of-life-canvas");
const ctx = canvas.getContext('2d');
const speed = document.getElementById('speed');
let fps = [];
let animationId = null;
let fuel = 0;
let lastRender = performance.now();
let memory;

wasm_bindgen('../out/main_bg.wasm').then(() => {
  universe = Universe.new();
  width = universe.width();
  height = universe.height();
  memory = wasm_bindgen.wasm.memory;

  // Initialize the canvas with room for all of our cells and a 1px border
  // around each of them.
  canvas.height = (CELL_SIZE + 1) * height + 1;
  canvas.width = (CELL_SIZE + 1) * width + 1;

  play();
});

const renderLoop = () => {
  const now = performance.now();
  const frameTime = now - lastRender;
  fps.push(1000 / frameTime);
  if (fps.length > 100)
    fps.shift();
  lastRender = now;

  draw();

  // const cps = Math.pow(1 / (Math.pow(8, speed.value / 100.0) - 1), 3);
  const gas = Math.pow(speed.value, 1.7);
  fuel += Math.min(gas, gas / (1000 / frameTime));
  document.getElementById('tps').innerHTML = Math.floor(gas);
  while (fuel >= 1) {
    universe.tick();
    fuel -= 1;
  }

  animationId = requestAnimationFrame(renderLoop);
};

setInterval(() => {
  let sum = 0;
  for (let i = 0; i < fps.length; i++) {
    sum += fps[i];
  }
  document.getElementById('fps').innerHTML = Math.floor(sum / fps.length);
}, 500);

const draw = () => {
  drawGrid();
  drawCells();
};

const drawGrid = () => {
  ctx.beginPath();
  //ctx.lineWidth = 1 / window.devicePixelRatio;
  ctx.lineWidth = 1;
  ctx.strokeStyle = GRID_COLOR;

  // Vertical lines.
  for (let i = 0; i <= width; i++) {
    ctx.moveTo(i * (CELL_SIZE + 1) + 1, 0);
    ctx.lineTo(i * (CELL_SIZE + 1) + 1, (CELL_SIZE + 1) * height + 1);
  }

  // Horizontal lines.
  for (let j = 0; j <= height; j++) {
    ctx.moveTo(0,                           j * (CELL_SIZE + 1) + 1);
    ctx.lineTo((CELL_SIZE + 1) * width + 1, j * (CELL_SIZE + 1) + 1);
  }

  ctx.stroke();
};

const getIndex = (row, column) => {
  return row * width + column;
};

let prev = [];

const drawCells = () => {
  const cellsPtr = universe.cells();
  const cells = new Uint8Array(memory.buffer, cellsPtr, width * height);

  ctx.beginPath();

  const color = (color, val) => {
    ctx.fillStyle = color;
    for (let row = 0; row < height; row++) {
      for (let col = 0; col < width; col++) {
        const idx = getIndex(row, col);
        if (cells[idx] !== val || prev[idx] === val)
          continue
        prev[idx] = val;
        ctx.fillRect(
          col * (CELL_SIZE + 1) + 1,
          row * (CELL_SIZE + 1) + 1,
          CELL_SIZE,
          CELL_SIZE
        );
      }
    }
  };

  color(DEAD_COLOR, DEAD);
  color(ALIVE_COLOR, ALIVE);

  ctx.stroke();
};

const playPauseButton = document.getElementById("play-pause");

const isPaused = () => {
  return animationId === null;
};

const play = () => {
  playPauseButton.textContent = "⏸";
  renderLoop();
};

const pause = () => {
  playPauseButton.textContent = "▶";
  draw();
  cancelAnimationFrame(animationId);
  animationId = null;
};

playPauseButton.addEventListener("click", event => {
  if (isPaused()) {
    play();
  } else {
    pause();
  }
});

canvas.addEventListener("click", event => {
  const relativeLeft = event.pageX - event.target.offsetLeft;
  const relativeTop = event.pageY - event.target.offsetTop;

  const row = Math.min(Math.floor(relativeTop / (event.target.clientHeight / height)), height - 1);
  const col = Math.min(Math.floor(relativeLeft / (event.target.clientWidth / width)), width - 1);

  if (event.shiftKey) {
    universe.add_glider(row, col);
  } else {
    universe.toggle_cell(row, col);
  }

  draw();
});

document.getElementById('clear').addEventListener("click", event => {
  universe.clear();
  draw();
});

document.getElementById('random').addEventListener("click", event => {
  universe.randomize();
  draw();
});

document.getElementById('tick').addEventListener("click", event => {
  universe.tick();
  draw();
});
