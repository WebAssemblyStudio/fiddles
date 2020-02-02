import { Object3D } from "./Object3D";

export class Camera extends Object3D {
  // type: string = 'Camera'
	constructor() {
		super()
		this.type = 'Camera'
	}
}

let camera = new Camera();
assert(camera.type == 'Camera');