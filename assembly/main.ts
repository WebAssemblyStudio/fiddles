
class Point {
    x: f64;
    y: f64;

    constructor(x: f64, y: f64) {
        this.x = x;
        this.y = y;
    }

    @operator('+')
    add(point: Point): Point {
        return new Point(this.x + point.x, this.y + point.y);
    }
}


var a = new Point(100, 100);
var b = new Point(100, 100);


export function add(): Point {
  var res = a+b;
  return res.x;
}
