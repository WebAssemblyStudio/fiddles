import "allocator/arena";

class Base{
    age: number;
    constructor(age:number){
        this.age = age;
    }
}

class Concrete extends Base{
    constructor(age:number){
        super(age);
    }

    getAge():number{
        return this.age;
    }
}

export function getAge(): number {
  let concrete:Concrete = new Concrete(12);
  return concrete.getAge();
}
