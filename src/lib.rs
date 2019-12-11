#![no_std]
#![allow(non_snake_case)]
#![feature(proc_macro_hygiene)]

extern crate bithumb_chain_std;

use bithumb_chain_std::lib::*;

#[macro_use]
use bithumb_chain_abi_derive::bithumb_chain_abi;
use crate::bithumb_chain_std::abi::EndpointInterface;
use bithumb_chain_std::api::{ret, input};
use bithumb_chain_std::logger::debug;

#[bithumb_chain_abi(HelloEndpoint)]
pub trait HelloInterface {
    fn hello(&mut self, name: String) -> bool;
}

pub struct HelloContract;

impl HelloInterface for HelloContract {
    fn hello(&mut self, name: String) -> bool {
        let mut str1 = "hello,".to_string();
        str1.push_str(&name);
        debug(&str1);
        true
    }
}

#[no_mangle]
pub fn invoke() {
    let mut endpoint = HelloEndpoint::new(HelloContract {});
    ret(&endpoint.dispatch(&input()));
}
