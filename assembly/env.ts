declare function revert(err: i32): void;

declare function transfer_to_account(
  target_ptr: i32,
  target_size: i32,
  amount_ptr: i32,
  amount_size: i32
): i32;

function make_public_key(): Uint8Array {
  var public_key = new Uint8Array(36);
  public_key[0] = 32;
  for(var i = 1; i<35; i++){
    public_key[i] = 0;
  }
  public_key[35] = 255;
  return public_key;
}

function make_amount(): Uint8Array {
  var value = new Uint8Array(3);
  value[0] = 2;
  value[1] = 0;
  value[2] = 1;
  return value;
}

export function call(): void {
  var public_key = make_public_key();
  var amount = make_amount();
  transfer_to_account(
    public_key.byteOffset,
    public_key.byteLength,
    amount.byteOffset,
    amount.byteLength
  )
}
 