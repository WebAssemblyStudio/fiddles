class Object3D {
  type: string = 'Object3D'
}

class Camera extends Object3D {
  type: string = 'Camera'
}

const camera = new Camera();
assert(camera.type == "Camera");