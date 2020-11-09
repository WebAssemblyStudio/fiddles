export class SubMap extends Map<string, i32> {
	get(key: string): i32 {
		return 1;
	}
}

let m = new SubMap();