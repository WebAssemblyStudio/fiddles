import "allocator/arena";

declare function log(value: i32): void;

class Base {
	say(): void {
		log(1);
	}
}

class Concrete extends Base {
	say(): void {
		log(2);
	}
}

function saySomething(base: Base): void {
	base.say();
}

export function say(): void {
	saySomething(new Base());
	saySomething(new Concrete());
}