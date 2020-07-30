declare function sayHello(): void;

sayHello();

export function fibonacci(n: i32): i32 {
    if (n == 1 || n == 2) {
        return 1
    };
    return fibonacci(n - 2) + fibonacci(n - 1);
}

