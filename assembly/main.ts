import "allocator/arena";

declare function sayHello(): void;

type AccountName = u64;

class Account {
  static get(name: AccountName): Account {
    // return <Account>db.get(name);
    return new Account(name, 100);
  }
  
  // @primary
  owner: AccountName
  constructor(
    owner: AccountName,
    public balance: u64,
  ) {
    this.owner = owner;
  }

  /*
  @operator(">>")
  static transferBalance<T, Q>(a: T, b: Q): u64 {
    if (isReference<Account>(a) && isReference<u64>(b)) {
      let name = <Account>a;
      let quantity = <u64>b;
      // transfer to
      return quantity;
    } else if (isReference<Account>(b) && isReference<u64>(a)) {
      let name     = <Account>b;
      let quantity = <u64>a;
      // transfer from
      return quantity;
    }
    // else pass through
    return 0;
  }*/
  @operator(">>")
  static transferTo(name: Account, quantity: u64): u64 {
    return quantity;
  }
}

// @action
export function transfer(from: AccountName, to: AccountName, quantity: u64): void {
  Account.get(from) >> quantity;// >> Account.get(to);
  // or:
  // Account.get(to) << quantity << Account.get(from);
}
