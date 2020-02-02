let self: Object3D | null = null

export class Object3D {
	type: string = 'Object3D'

	parent: Object3D | null = null
	children: Object3D[] = []

	constructor() {
		// super()
		self = this;
		// this.rotation.onChange(() => {
		//   self!.onRotationChange()
		// })
	}
}

export class Camera extends Object3D {
  // type: string = 'Camera'
	constructor() {
		super()
		this.type = 'Camera'
	}
}