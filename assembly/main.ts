class A1 {
    private i32_0!: i32;

    private i32_1!: i32;

    private c1_0!: C1;

    private i32_2!: i32;

    private c1_1!: C1;
}

class A2 extends A1 {
}

class B1 {
    private a1!: A1;
}

class C1 {
    private a2!: A2;
}

let poolA: A2[] = new Array();
poolA.push( new A2() );

