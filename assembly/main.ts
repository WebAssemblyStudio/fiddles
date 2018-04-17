import 'allocator/buddy';

export function allocate(size: usize): usize {
    return allocate_memory(size);
}

export function deallocate(ptr: usize): void {
    free_memory(ptr);
}

export function add(x: i32, y: i32): i32 {
    return x + y;
}

export function make_string(count: usize): string {
    return 'na '.repeat(count) + 'batman!';
}

export function str_length(str: string): usize {
    return str.length;
}

class Foo {
    a: u32;
    b: u8;
    c: u16;

    constructor(a: u32, b: u8, c: u16) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    add(): usize {
        return this.a + this.b + this.c;
    }
}

export function make_foo(): Foo {
    return new Foo(1111, 222, 3333);
}

export function add_foo(foo: Foo): usize {
    let result = foo.add();
    free_memory(changetype<usize>(foo));

    return result;
}

export function sum(arr: ArrayBuffer): usize {
    let view_ptr = allocate_memory(12);
    store<usize>(view_ptr, changetype<usize>(arr)); // buffer
    store<usize>(view_ptr + 4, 0);                  // offset
    store<usize>(view_ptr + 8, arr.byteLength);     // byteLength

    let view = changetype<Uint32Array>(view_ptr);
    let result = 0;

    for (let i = 0; i < view.length; i++) {
        result += view[i];
    }

    return result;
}

export function throw_error(): void {
    throw new Error();
}
