import 'allocator/arena'

let oldTime : f64 = 0
let game : Game

declare namespace engine {
  const width : i32
  const height : i32
  function now() : f64
  function tick(callback: () => void) : void
  function fixedTick(callback: (time: f64) => void) : void
}

declare namespace draw {
  function clear() : void
  function rectFill(color : string) : void
  function rect(x : i32, y : i32, w : i32, h : i32) : void
  function font(font) : void
  function text(x : i32, y : i32, color : string, text : string) : void
}

declare namespace console {
  function log(x: string) : void
  function logf(x: f64) : void
}

class Rect {
  x : i32
  y : i32
  w : i32
  h : i32
  destX : i32 | null
  destY : i32 | null

  constructor(x : i32, y : i32, w : i32, h : i32) {
    this.x = x
    this.y = y
    this.w = w
    this.h = h
    this.destX = null
    this.destY = null
  }

  move() : void {
    if (!this.destX && !this.destY) {
      this.x++
      if (this.x > engine.width) this.x = -20
    } else {
      if (this.x < this.destX) this.x++
      if (this.x > this.destX) this.x--

      if (this.y < this.destY) this.y++
      if (this.y > this.destY) this.y--
    }
  }

  draw() : void {
    draw.rect(this.x, this.y, this.w, this.h)
  }
}

class Game {
  player : Rect

  constructor() {
    this.player = new Rect(10, 10, 20, 20)
    draw.rectFill('black')

    this.tick()
    this.fixedTick(0, engine.now())
  }

  tick() : void {
    draw.clear()
    this.player.draw()

    engine.tick(() : void => {
      game.tick()
    })
  }

  update() : void {
    this.player.move()
  }

  fixedTick(ticks: f64, time : f64): void {
    if (isNaN(ticks)) ticks = 10

    while (ticks >= 10) {
      this.update()
      ticks -= 10
    }

    oldTime = time - ticks
    engine.fixedTick((newTime : f64) : void => {
      game.fixedTick(newTime - oldTime, newTime)
    })
  }
}

export function click(x : i32, y: i32) : void {
  game.player.destX = x
  game.player.destY = y
}

game = new Game()
