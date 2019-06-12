// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

// Here we're importing the `alert` function from the browser, using
// `#[wasm_bindgen]` to generate correct wrappers.
#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

enum Token {
  Value(f32),
  Plus,
  Minus,
  Times,
  Divide,
  OpenParen,
  CloseParen,
}

fn tokenize_non_value(c: char) -> Result<Token, String> {
  match c {
    '(' => Ok(Token::OpenParen),
    ')' => Ok(Token::CloseParen),
    '/' => Ok(Token::Divide),
    '*' => Ok(Token::Times),
    '+' => Ok(Token::Plus),
    '-' => Ok(Token::Minus),
    _ => Err("tokenizer failed".to_string())
  }
}

fn tokenize(text: &str) -> Result<Vec<Token>, String> {
  let mut buffer = String::new();
  let mut tokens: Vec<Token> = Vec::new();

  for c in text.chars() {
    match c {
      '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' | '.' => {
        buffer.push(c);
      },
      ' ' | '\t' => { /* do nothing */ },
      _ => {
        if buffer.len() > 0 {
          match buffer.parse() {
            Ok(value) => { tokens.push(Token::Value(value)) },
            Err(_) => return Err("tokenizer failed".to_string()),
          }
          buffer.clear();
        }
        let token = tokenize_non_value(c)?;
        tokens.push(token);
      }
    }
  }

  if buffer.len() > 0 {
    match buffer.parse() {
      Ok(value) => { tokens.push(Token::Value(value)) },
      Err(_) => return Err("tokenizer failed".to_string()),
    }
  }

  Ok(tokens)
}

struct Node {
  token: Token,
  left: Option<Node>,
  right: Option<Node>,
}

fn parse(tokens: &[Token]) -> Result<Node, String> {
  if tokens.len() == 0 {
    return Err("parser failed".to_string());
  }

  if tokens.len() == 1 {
    match tokens[0] {
      Token::Value(value) => return Ok(Node { token: Token::Value(value), left: None, right: None }),
      _ => return Err("parser failed".to_string());
    }
  }

  
}

#[wasm_bindgen]
pub fn compute(text: &str) -> f32 {
  return text.parse().unwrap();
}

#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello, {}! {}", name, tokenize("5.3+(7.7)").unwrap().len()));
}
