declare function jt_blockNumber(): i32;
declare function jt_getBalance(address:string, currency:string, issuer:string): i32;

export function blockNumber(): i32 {
  return jt_blockNumber();
}

export function root_balance(): i32 {
  return jt_getBalance("jHb9CJAWyB4jr91VRWn96DkukG4bwdtyTh", "", "");
}

export function add(x: i32, y: i32): i32 {
  return x + y;
}
