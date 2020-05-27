export class Product {
  id: u64;
  name: string;

  constructor(id: u64, name: string) {
    this.id = id;
    this.name = name;
  }

  doSomething(): i32 {
    return 123;
  }
}