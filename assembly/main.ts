class Obj {
  type: string = "Object"
}

class Camera extends Obj {
  type: string = "Camera"
}

const camera = new Camera();
assert(camera.type == "Camera");