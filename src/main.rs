extern crate smart_contract_macros;
use smart_contract_macros::smart_contract;


#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}