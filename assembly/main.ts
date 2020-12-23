declare function sayHello(): void;

sayHello();

export function add(x: i32, y: i32): i32 {
  return x + y;
}

export function sub(a: i32, b: i32): i32 {
  return a - b;
}

export function multiply(a: i32, b: i32): i32 {
  return a*b;
}

export function isPrime(x: u32): bool {
    if (x < 2) {
        return false;
    }

    for (let i: u32 = 2; i < x; i++) {
        if (x % i === 0) {
            return false;
        }
    }

    return true;
}

export function sumArray(arr: Int32Array): i32 {
	let sum: i32 = 0;
    for (let i: i32 = 0; i < arr.length; i++) {
    	sum = sum + arr[i];
    }
    return sum;
}

export function getGreeting(name: string): string {
	const hello = "hello "
	return hello + name;
}