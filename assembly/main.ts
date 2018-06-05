import "allocator/arena";

declare function sayHello(): void;

type AccountName = u64;

class Account {
  static get(name: AccountName): Account {
    // in real contract:
    // return <Account>db.get(name);

    // just as stub
    return new Account(name, U64.wrap(100));
  }
  
  // @primary
  owner: AccountName
  constructor(
    owner: AccountName,
    public balance: U64,
  ) {
    this.owner = owner;
  }

  @operator(">>")
  static transferFrom(name: Account, quantity: U64): U64 {
    updateBalance(name, -quantity.value);
    return quantity;
  }
}

function updateBalance(to: Account, quantity: i64): void {
  // work with db
}

// Just wrapper. In future releases of AssemblyScript not needed
class U64 {
  static wrap(value: u64): U64 {
    return new U64(value);
  }

  constructor(public value: u64) {}

  @operator(">>")
  static transferTo(quantity: U64, name: Account): U64 {
    updateBalance(name, quantity.value);
    return quantity;
  }
}

/*
 * Magic is here ⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇
 */

// @action
export function transfer(from: AccountName, to: AccountName, quantity: u64): void {
  Account.get(from) >> U64.wrap(quantity) >> Account.get(to);

  /* 
  * In future it will be simpler, just:
  *
  * Account.get(to) >> quantity >> Account.get(from);
  */
}

/*
 * Magic is here ⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆
 */