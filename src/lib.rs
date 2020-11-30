// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;


#[wasm_bindgen]
pub fn kind_of(bytes: &[u8]) -> u8 {
  bytes[0]
}

#[wasm_bindgen]
pub fn decode (bytes: &[u8]) -> NodeView {
  if bytes.len() == 0 {
    NodeView(Node::Absent)
  } else {
    match bytes[0] {
      0 => NodeView(Node::Null),
      1 => NodeView(Node::Boolean(if bytes[1] == 0 { true } else { false })),
      2 => NodeView(Node::Int(i32::from(bytes[1]))),
      3 => NodeView(Node::Float(f32::from(bytes[1]))),
      4 => NodeView(Node::String(bytes[1..].to_vec())),
      5 => NodeView(Node::Bytes(bytes[1..].to_vec())),
      6 => NodeView(Node::Link(bytes[1..].to_vec())),
      7 => NodeView(Node::List(bytes[1..].to_vec())),
      8 => NodeView(Node::Map(bytes[1..].to_vec())),
      _ => panic!()
    }
  }
}

#[wasm_bindgen]
#[derive(Copy, Clone)]
pub enum Kind {
  Absent,
  Null,
  Boolean,
  Int,
  Float,
  String,
  Bytes,
  Link,
  List,
  Map
}

enum Node {
  Absent,
  Null,
  Boolean(bool),
  Int(i32),
  Float(f32),
  String(Vec<u8>),
  Bytes(Vec<u8>),
  Link(Vec<u8>),
  List(Vec<u8>),
  Map(Vec<u8>)
}

#[wasm_bindgen]
pub struct NodeView(Node);


#[wasm_bindgen]
impl NodeView { 

  pub fn kind(&self) -> Kind {
    match self {
      NodeView(Node::Absent) => Kind::Absent,
      NodeView(Node::Null) => Kind::Null,
      NodeView(Node::Boolean(_)) => Kind::Boolean,
      NodeView(Node::Int(_)) => Kind::Int,
      NodeView(Node::Float(_)) => Kind::Float,
      NodeView(Node::String(_)) => Kind::String,
      NodeView(Node::Bytes(_)) => Kind::Bytes,
      NodeView(Node::Link(_)) => Kind::Link,
      NodeView(Node::List(_)) => Kind::List,
      NodeView(Node::Map(_)) => Kind::Map,
      _ => panic!()
    }
  }
  pub fn is_absent(&self) -> bool {
    match self {
      NodeView(Node::Absent) => true,
      _ => false
    }
  }
  pub fn is_null(&self) -> bool {
    match self {
      NodeView(Node::Null) => true,
      _ => false
    }
  }

  pub fn as_bool(&self) -> bool {
    match self {
      NodeView(Node::Boolean(true)) => true,
      NodeView(Node::Boolean(false)) => false,
      _ => panic!()
    }
  }
  pub fn as_int(&self) -> i32 {
    match self {
      NodeView(Node::Int(int)) => int.to_owned(),
      _ => panic!()
    }
  }
  pub fn as_float(&self) -> f32 {
    match self {
      NodeView(Node::Float(float)) => float.to_owned(),
      _ => panic!()
    }
  }
  pub fn as_string(&self) -> String {
    match self {
      NodeView(Node::String(bytes)) => String::from(std::str::from_utf8(bytes).unwrap()),
      _ => panic!()
    }
  }
  pub fn as_bytes(&self) -> Vec<u8> {
    match self {
      NodeView(Node::Bytes(bytes)) => bytes.to_owned(),
      _ => panic!()
    }
  }
  pub fn as_link(&self) -> Link {
    match self {
      NodeView(Node::Link(bytes)) => Link { bytes: bytes.to_owned() },
      _ => panic!()
    }
  }
  pub fn as_list(&self) -> ListView {
    match self {
      NodeView(Node::List(bytes)) => ListView { bytes: bytes.to_owned() },
      _ => panic!()
    }
  }
  
  pub fn as_map(&self) -> MapView {
    match self {
      NodeView(Node::List(bytes)) => MapView { bytes: bytes.to_owned() },
      _ => panic!()
    }
  }
}

#[wasm_bindgen]
pub struct MapView {
  bytes: Vec<u8>
}

#[wasm_bindgen]
pub struct ListView {
  bytes: Vec<u8>
}

#[wasm_bindgen]
pub struct Link {
  bytes: Vec<u8>
}