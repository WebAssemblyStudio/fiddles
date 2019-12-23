export class RandomObject {
    public child: Child|null = null;
}

export class Parent {
    public randomObject: RandomObject|null = null;
}

export class Child extends Parent { }

new Child();