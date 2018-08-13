const module = {
  memory: false,
  table: false
}

// const memory  = new WebAssembly.Memory({initial: 1})
// const table   = new WebAssembly.Table({initial: 1, element: 'anyfunc'})

const canvas  = document.getElementById('canvas')
const context = canvas.getContext('2d')

const stringDecode = (buf, off, len = new Int8Array(buf, off, 1)[0]) =>
  (new TextDecoder('utf-16')).decode(new Uint8Array(buf, off + 4, len * 2))

const engine = {
  width: 480,
  height: 480,
  now: () => performance.now(),
  tick: f => {
    !module.table ?
      setTimeout(() => engine.tick(f), 10) :
      requestAnimationFrame(() => module.table.get(f)())
  },
  fixedTick: f => {
    !module.table ?
      setTimeout(() => engine.fixedTick(f), 10) :
      setTimeout(() => module.table.get(f)(performance.now()), 10)
  }
}

const draw = {
  clear() {
    context.beginPath()
    context.clearRect(0, 0, 1280, 720)
  },
  rectFill(c) {
    if (module.memory) context.fillStyle = stringDecode(module.memory.buffer, c)
  },
  rect(x, y, w, h) {
    context.fillRect(x, y, w, h)
  },
  font(font) {
    if (module.memory) context.font = stringDecode(module.memory.buffer, f)
  },
  text(x, y, color, text) {
    if (module.memory) {
      context.fillStyle = stringDecode(module.memory.buffer, c)
      context.fillText(stringDecode(module.memory.buffer, t), x, y)
    }
  }
}

canvas.width = engine.width
canvas.height = engine.height

WebAssembly.instantiateStreaming(fetch('../out/main.wasm'), {
  env: {
    // memory,
    // table
            'memoryBase': 0,
            'tableBase': 0,
            'memory': new WebAssembly.Memory({initial: 256}),
            'table': new WebAssembly.Table({initial: 256, element: 'anyfunc'}),
  },
  console: {
    log(d) {
      console.log(stringDecode(module.memory.buffer, d));
    },
    logf: f => console.log(f)
  },
  engine,
  draw
})
.then(module => module.instance.exports)
.then(m => {
  module.table = m.table
  module.memory = m.memory

  canvas.addEventListener('mousedown', event => {
    m.click(
      parseInt(event.clientX / canvas.offsetWidth * engine.width),
      parseInt(event.clientY / canvas.offsetHeight * engine.height)
    )
  }, true)
})

// class Game {
//   constructor() {
//     let i = 10
//
//     this.tick(performance.now())
//     this.fixedTick()
//   }
//
//   tick() {
//     this.draw()
//     requestAnimationFrame(() => this.tick())
//   }
//
//   fixedTick(lastTime = 0) {
//     const time = performance.now()
//
//     for (let t = time - lastTime | 0; t > 0; t--) {
//       this.balls.forEach(b => b.move())
//
//       this.balls.forEach((b, i) => b.collide(this.balls.slice(i + 1)))
//     }
//
//     setTimeout(() => this.fixedTick(time + (time - lastTime) % 1), 10)
//   }
//
//   draw() {
//     draw.clear()
//
//     this.balls
//       .filter(o => o.vi)
//       .forEach(o => o.draw())
//   }
// }
//


  // console.log(exports)
  //
  // console.log(exports.getStrOffset());
  //
  // console.log(stringDecode(exports.memory.buffer, exports.getStrOffset() + 2, 40));
  //
  //
  // console.log(stringDecode(memory.buffer, 0, 100));


  // Update about 30 times a second
  // (function update() {
  //   setTimeout(update, 30);
  //   exports.step();
  //   mem.copyWithin(0, s, S); // copy output at [s, S] to input at [0, s]
  // })();

  // Keep rendering the output at [s, S]
  // (function render() {
  //   requestAnimationFrame(render);
  //   ctx.fillStyle = "rgba(238,238,238,0.67)";
  //   ctx.fillRect(0, 0, w << 1, h << 1);
  //   ctx.fillStyle = "#333";
  //   for (var y = 0; y < h; ++y)
  //     for (var x = 0; x < w; ++x)
  //       if (mem[s + y * w + x])
  //         ctx.fillRect(x << 1, y << 1, 2, 2);
  // })();

// todo na dziś: wyswietlanie postaci i po kliknieciu ona się porusza, osobne przesuwanie mapy
