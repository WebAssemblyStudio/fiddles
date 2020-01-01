export function willFail(): void {
    const b = buildB();
    b.a.bs.push( b );
}

function buildB(): B {
    const a = new A();
    return new B( a );
}

export class A {
    public bs: B[] = [];
}

@unmanaged
export class B {
    public a: A;

    public constructor( a: A ) {
        this.a = a;
    }
}
