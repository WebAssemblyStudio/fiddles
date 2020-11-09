export class SubMap extends Map<string, i32> {
	get(key: string): i32 {
		let res: i32;

		if (!this.has(key)) this.set(key, (res = 1));
		else res = super.get(key);

		return res;
	}
}

let m = new SubMap();

m.set('1', 1);
m.set('2', 2);

assert(m.get('1') == 1);
assert(m.get('2') == 2);