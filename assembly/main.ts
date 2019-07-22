export class Contract {
  public static init(x: u8[]): Contract {
    return new Contract();
  };


  public add(x: i32, y: i32): i32 {
    return x + y;
  };
}

///@external('_contract_init')
export function _contract_init(x: u8[]): Contract {
  return Contract.init(x);
}