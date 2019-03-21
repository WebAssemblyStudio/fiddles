import "allocator/arena";


class BigInt extends Uint8Array { 
  sub(other: BigInt): BigInt {
    return new BigInt([]);
  } 
  add(other: BigInt): BigInt {
    return new BigInt([]);
  } 
}

declare namespace vm {
  namespace registers {
    type Identifier = Uint8Array;
    function getIdentifier(account: Account, name: string): Identifier;
    function getBigInt(identifier: Identifier): BigInt
    function setBigInt(identifier: Identifier, value: BigInt): void;

  }
  namespace context {
    function enter(name: string): void;
    function leave(): void;
  }
}

///
/// withContext('x', () => {
///   /* ... */
/// })
function withContext(name: string, f: () => void): void {
  vm.context.enter(name)
  f()
  vm.context.leave()
}

class Account {}

class Register {
  private readonly identifier: vm.registers.Identifier;

  constructor(account: Account, name: string) {
    this.identifier = vm.registers.getIdentifier(account, name)
  }

  setBigInt(value: BigInt): void {
    vm.registers.setBigInt(this.identifier, value)
  }

  getBigInt(): BigInt {
    return vm.registers.getBigInt(this.identifier)
  }
}


///

export function getBalanceRegister(account: Account): Register {
  return new Register(account, 'balance')
}

export function transfer(from: Account, to: Account, value: BigInt): void {
  const fromBalance = getBalanceRegister(from)
  fromBalance.setBigInt(fromBalance.getBigInt().sub(value))
  const toBalance = getBalanceRegister(to)
  toBalance.setBigInt(toBalance.getBigInt().add(value))
}
