declare function sayHello(): void;

sayHello();

class Rotation {
  onChange(f: () => void): void {}
}

class Quaternion {
  setFromEuler(r: Rotation, u: boolean): void {}
}

class Object3D {
	readonly quaternion: Quaternion = new Quaternion()
  readonly rotation: Rotation = new Rotation()

	constructor() {
		this.rotation.onChange(this.onRotationChange)
	}

	onRotationChange: () => void = () => {
		this.quaternion.setFromEuler(this.rotation, false)
	}
}


export function add(x: i32, y: i32): i32 {
  let o = new Object3D()
  return x + y;
}