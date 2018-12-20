declare function pixel(i: u32, color: u32): void;

enum Direction {
    Left = 0,
    Up,
    Right,
    Down
}

class Vector {
  public readonly x: u32;
  public readonly y: u32;

  public static readonly ZERO:  Vector = new Vector(0,  0);
  public static readonly LEFT:  Vector = new Vector(-1, 0);
  public static readonly UP:    Vector = new Vector(0, -1);
  public static readonly RIGHT: Vector = new Vector(1,  0);
  public static readonly DOWN:  Vector = new Vector(0,  1);

  constructor(x: u32, y: u32) {
    this.x = x;
    this.y = y;
  }

  public static random(min: Vector, max: Vector) {
    var x: u32 = Math.random() * (max.x - min.x + 1) + min.x;
    var y: u32 = Math.random() * (max.y - min.y + 1) + min.y;

    return new Vector(x, y);
  }

  public add(other: Vector) {
    return new Vector(this.x + other.x, this.y + other.y);
  }

  public addDirection(direction: Direction) {
    switch (direction) {
      case Direction.Left:
        return this.add(Vector.LEFT);
      case Direction.Up:
        return this.add(Vector.UP);
      case Direction.Right:
        return this.add(Vector.RIGHT);
      case Direction.Down:
        return this.add(Vector.DOWN);
    }
  }

  public equals(other: Vector): boolean {
    return this.x == other.x && this.y == other.y;
  }
}

const DIMENSION = new Vector(48, 32);
const LENGTH = DIMENSION.x * DIMENSION.y;

const OLDBUFFER: u32[] = new u32[LENGTH];
const BUFFER:    u32[] = new u32[LENGTH];

class Snake {
  head: Vector;
  direction: Direction;

  tail: Vector[];
  length: u32;

  apples: Vector[];

  alive: boolean;

  constructor(head: Vector, direction: Direction, length: u32, apples: u32) {
    this.head = head;
    this.direction = direction;

    this.tail = new Vector[0];
    this.length = length;

    this.apples = new Vector[0];
    for (var i: u32 = 0; i < apples; i++)
      apples[i] = genApple();

    this.alive = true;
  }

  private genApple(): Vector {
    var apple: Vector;
    
    while (!apple) {
      apple = Vector.random(0, 0, WIDTH, HEIGHT);
  }

  public update(): boolean {
    this.tail.unshift(this.head);
    if (this.tail.length > this.length)
      this.tail.pop();
    
    this.head = this.head.addDirection(this.direction);
    for (var i: u32 = 0; i < this.tail.length; i++)
      if (this.head.equals(this.tail[i]))
        return this.alive = false;
    
    for (var i: u32 = 0; i < this.apples.length; i++)
      if (this.head.equals(this.apples[i]))
        apples[i] = genApple();
  }
}

var apples = Vector[];

export function key(): void {
  // Key
}

export function update(): void {
  // Update
}

export function draw(): void {
  for (var i: u32 = 0; i < LENGTH; i++)
    if (buffer[i] != oldBuffer[i]) {
      oldBuffer[i] = buffer[i];
      pixel(i, buffer[i]);
    }
}
