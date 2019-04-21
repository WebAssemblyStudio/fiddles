declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

///////////////////////////////////////////

type float = f64;

class Vector {
  constructor(public x: float, public y: float, public z: float) { }
  static times(k: float, v: Vector): Vector { return new Vector(k * v.x, k * v.y, k * v.z); }
  static minus(v1: Vector, v2: Vector): Vector { return new Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }
  static plus(v1: Vector, v2: Vector): Vector { return new Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
  static dot(v1: Vector, v2: Vector): float { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
  static mag(v: Vector): float { return Math.sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
  static norm(v: Vector): Vector {
    var mag = Vector.mag(v);
    var div = (mag === 0) ? Infinity : 1.0 / mag;
    return Vector.times(div, v);
  }
  static cross(v1: Vector, v2: Vector): Vector {
    return new Vector(v1.y * v2.z - v1.z * v2.y,
      v1.z * v2.x - v1.x * v2.z,
      v1.x * v2.y - v1.y * v2.x);
  }
}

class Color {
  constructor(public r: float, public g: float, public b: float) { }
  static scale(k: float, v: Color): Color { return new Color(k * v.r, k * v.g, k * v.b); }
  static plus(v1: Color, v2: Color): Color { return new Color(v1.r + v2.r, v1.g + v2.g, v1.b + v2.b); }
  static times(v1: Color, v2: Color): Color { return new Color(v1.r * v2.r, v1.g * v2.g, v1.b * v2.b); }
  static white: Color = new Color(1.0, 1.0, 1.0);
  static grey: Color = new Color(0.5, 0.5, 0.5);
  static black: Color = new Color(0.0, 0.0, 0.0);
  static background: Color = Color.black;
  static defaultColor: Color = Color.black;
  static toDrawingColor(c: Color): Color {
    var legalize = (d: float): float => d > 1 ? 1 : d;
    return {
      r: Math.floor(legalize(c.r) * 255),
      g: Math.floor(legalize(c.g) * 255),
      b: Math.floor(legalize(c.b) * 255)
    };
  }
}

class Camera {
  forward: Vector;
  right: Vector;
  up: Vector;

  constructor(public pos: Vector, lookAt: Vector) {
    const down = new Vector(0.0, -1.0, 0.0);
    this.forward = Vector.norm(Vector.minus(lookAt, this.pos));
    this.right = Vector.times(1.5, Vector.norm(Vector.cross(this.forward, down)));
    this.up = Vector.times(1.5, Vector.norm(Vector.cross(this.forward, this.right)));
  }
}

interface Ray {
  start: Vector;
  dir: Vector;
}

interface Intersection {
  thing: Thing;
  ray: Ray;
  dist: float;
}

interface Surface {
  diffuse(pos: Vector): Color;
  specular(pos: Vector): Color;
  reflect(pos: Vector): float;
  roughness: float;
}

interface Thing {
  intersect(ray: Ray): float;
  normal(pos: Vector): Vector;
  surface: Surface;
}

interface Light {
  pos: Vector;
  color: Color;
}

interface Scene {
  things: Thing[];
  lights: Light[];
  camera: Camera;
}

class Sphere implements Thing {
  radius2: float;

  constructor(public center: Vector, radius: float, public surface: Surface) {
    this.radius2 = radius * radius;
  }

  normal(pos: Vector): Vector { return Vector.norm(Vector.minus(pos, this.center)); }

  intersect(ray: Ray): float {
    var eo = Vector.minus(this.center, ray.start);
    var v = Vector.dot(eo, ray.dir);
    var dist = 0;
    if (v >= 0) {
      let disc = this.radius2 - (Vector.dot(eo, eo) - v * v);
      if (disc >= 0) {
        dist = v - Math.sqrt(disc);
      }
    }
    if (dist === 0) {
      return NaN;
    } else {
      return dist;
    }
  }
}

class Plane implements Thing {

  constructor(private norm: Vector, private offset: float, public surface: Surface) { }

  normal(pos: Vector): Vector { return this.norm; }

  intersect(ray: Ray): float {
    var denom = Vector.dot(this.norm, ray.dir);
    if (denom > 0) {
      return NaN;
    } else {
      let dist = (Vector.dot(this.norm, ray.start) + this.offset) / (-denom);
      return dist;
    }
  }
}

class Surfaces {
  static shiny: Surface = {
    diffuse: function (pos: Vector) { return Color.white; },
    specular: function (pos: Vector) { return Color.grey; },
    reflect: function (pos: Vector) { return 0.7; },
    roughness: 250
  };
  static checkerboard: Surface = {
    diffuse: function (pos: Vector) {
      if ((Math.floor(pos.z) + Math.floor(pos.x)) % 2 !== 0) {
        return Color.white;
      } else {
        return Color.black;
      }
    },
    specular: function (pos: Vector) { return Color.white; },
    reflect: function (pos: Vector) {
      if ((Math.floor(pos.z) + Math.floor(pos.x)) % 2 !== 0) {
        return 0.1;
      } else {
        return 0.7;
      }
    },
    roughness: 150
  };
}

class RayTracer {
  private maxDepth: float = 5;

  private intersections(ray: Ray, scene: Scene): Intersection {
    var closest: float = +Infinity;
    var closestThing: i32 = 0;
    for (let i = 0; i < scene.things.length; i++) {
      let dist = scene.things[i].intersect(ray);
      if (dist && dist < closest) {
        closestThing = i;
        closest = dist;
      }
    }
    return { thing: scene.things[closestThing], ray, dist: closest };
  }

  private testRay(ray: Ray, scene: Scene): float {
    var isect = this.intersections(ray, scene);
    return isect.dist;
  }

  private traceRay(ray: Ray, scene: Scene, depth: float): Color {
    var isect = this.intersections(ray, scene);
    if (isFinite(isect.dist)) {
      return this.shade(isect, scene, depth);
    } else {
      return Color.background;
    }
  }

  private shade(isect: Intersection, scene: Scene, depth: float): Color {
    var d = isect.ray.dir;
    var pos = Vector.plus(Vector.times(isect.dist, d), isect.ray.start);
    var normal = isect.thing.normal(pos);
    var reflectDir = Vector.minus(d, Vector.times(2, Vector.times(Vector.dot(normal, d), normal)));
    var naturalColor = Color.plus(Color.background,
      this.getNaturalColor(isect.thing, pos, normal, reflectDir, scene));
    var reflectedColor = (depth >= this.maxDepth) ? Color.grey :
      this.getReflectionColor(isect.thing, pos, normal, reflectDir, scene, depth);
    return Color.plus(naturalColor, reflectedColor);
  }

  private getReflectionColor(thing: Thing, pos: Vector, normal: Vector, rd: Vector, scene: Scene, depth: float): Color {
    return Color.scale(thing.surface.reflect(pos), this.traceRay({ start: pos, dir: rd }, scene, depth + 1));
  }

  private getNaturalColor(thing: Thing, pos: Vector, norm: Vector, rd: Vector, scene: Scene): Color {
    var addLight = (col: Color, light: Light): Color => {
      var ldis = Vector.minus(light.pos, pos);
      var livec = Vector.norm(ldis);
      var neatIsect = this.testRay({ start: pos, dir: livec }, scene);
      var isInShadow = isFinite(neatIsect) && (neatIsect <= Vector.mag(ldis));
      if (isInShadow) {
        return col;
      } else {
        let illum = Vector.dot(livec, norm);
        let lcolor = (illum > 0) ? Color.scale(illum, light.color)
          : Color.defaultColor;
        let specular = Vector.dot(livec, Vector.norm(rd));
        let scolor = (specular > 0) ? Color.scale(Math.pow(specular, thing.surface.roughness), light.color)
          : Color.defaultColor;
        return Color.plus(col, Color.plus(Color.times(thing.surface.diffuse(pos), lcolor),
          Color.times(thing.surface.specular(pos), scolor)));
      }
    };
    return scene.lights.reduce(addLight, Color.defaultColor);
  }

  render(scene: Scene, screenWidth: i32, screenHeight: i32): void {
    var getPoint = (x: float, y: float, camera: Camera): Vector => {
      const recenterX = (x: float): float => (x - (screenWidth / 2.0)) / 2.0 / screenWidth;
      const recenterY = (y: float): float => - (y - (screenHeight / 2.0)) / 2.0 / screenHeight;
      return Vector.norm(Vector.plus(camera.forward, Vector.plus(
        Vector.times(recenterX(x), camera.right), Vector.times(recenterY(y), camera.up))));
    };
    for (let y = 0; y < screenHeight; y++) {
      for (let x = 0; x < screenWidth; x++) {

        let color = this.traceRay({ start: scene.camera.pos, dir: getPoint(x, y, scene.camera) }, scene, 0);
        let c = Color.toDrawingColor(color);
        // ctx.fillStyle = "rgb(" + String(c.r) + ", " + String(c.g) + ", " + String(c.b) + ")";
        // ctx.fillRect(x, y, x + 1, y + 1);
        // todo: store<u16>()
      }
    }
  }
}

function defaultScene(): Scene {
  return {
    things: [new Plane(new Vector(0.0, 1.0, 0.0), 0.0, Surfaces.checkerboard),
    new Sphere(new Vector(0.0, 1.0, -0.25), 1.0, Surfaces.shiny),
    new Sphere(new Vector(-1.0, 0.5, 1.5), 0.5, Surfaces.shiny)],
    lights: [{ pos: new Vector(-2.0, 2.5, 0.0), color: new Color(0.49, 0.07, 0.07) },
    { pos: new Vector(1.5, 2.5, 1.5), color: new Color(0.07, 0.07, 0.49) },
    { pos: new Vector(1.5, 2.5, -1.5), color: new Color(0.07, 0.49, 0.071) },
    { pos: new Vector(0.0, 3.5, 0.0), color: new Color(0.21, 0.21, 0.35) }],
    camera: new Camera(new Vector(3.0, 2.0, 4.0), new Vector(-1.0, 0.5, 0.0))
  };
}
