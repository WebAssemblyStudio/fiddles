//#![feature(proc_macro, wasm_custom_section, wasm_import_module)]

extern crate wasm_bindgen;
//extern crate serde_json; // 1.0.24
#[macro_use]
extern crate serde_derive; // 1.0.70;


//use serde_json::Error;
use std::collections::HashMap;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet(name: &str) {
    alert(&format!("Hello Zee, {}!", name));
}


#[wasm_bindgen]
pub fn get_object() ->JsValue {
    let ob = Jsonformt::new();
    
    JsValue::from_serde(&ob).unwrap()
}

#[wasm_bindgen]
#[derive(Debug,Serialize,Deserialize)]
pub struct Jsonformt {
    _n: String,
    _a: HashMap<String, String>,
    //contact: Option<Box<Contact>>
    _c: Option<Box<Vec<Jsonformt>>>
}
#[wasm_bindgen]
impl Jsonformt {
   pub fn new() -> Jsonformt{
   	 Jsonformt {
   	 	_n: String::new(),
   	 	_a: HashMap::new(),
   	 	_c: Some(Box::new(Vec::new()))
   	 }
   }
   pub fn get_native_object() -> JsValue{
    	let mut attribute_field = HashMap::new();
    	attribute_field.insert(String::from("key"), String::from("value"));

    	let mut second_attr_field = HashMap::new();
    	second_attr_field.insert(String::from("childkey"), String::from("ChildValue"));

    	let child_object = Jsonformt {
    		_n: String::from("Dummy Object"),
    		_a: second_attr_field,
    		_c:None
    	};

    	let native_object = Jsonformt {
    		_n: String::from("First Native Object"),
    		_a: attribute_field,
    		_c: Some(Box::new(vec![child_object]))

    	};

    	JsValue::from_serde(&native_object).unwrap()
    }



    pub fn same_child(&self, jsobj:&JsValue, name: String) -> JsValue{
    	let mut current:Jsonformt = jsobj.into_serde().unwrap();
    	let js_val:JsValue = JsValue::from_serde(&current).unwrap();
    	//let mut some:JsValue = null;
    	if *name == current._n {
    		return js_val;
    	}else {

    		for entry in &mut current._c {
    			//let n:&String = name;
    			//let mut entry_js:&JsValue = &JsValue::from_serde(entry).unwrap();
    			//some = JsValue::from_serde(entry).unwrap();
    	    	//self.find_child(entry_js, name.clone());
    	    	let mut abc:&JsValue = &JsValue::from_serde(entry).unwrap();
    	    	//let other:Jsonformt = abc.into_serde().unwrap();
    	    	self.find_child(abc, name.clone());
    	    }
    	    return JsValue::from_serde(&Jsonformt::new()).unwrap();
    	    //return some;
    	}
    }

    pub fn find_child(&self, jsobj:&JsValue, name: String) -> JsValue{
    	let mut current:Jsonformt = jsobj.into_serde().unwrap();
    	let js_val:JsValue = JsValue::from_serde(&current).unwrap();
    	//let mut some:JsValue = null;
    	if *name == current._n {
    		return js_val;
    	}else {

    		for entry in &mut current._c {
    			//let n:&String = name;
    			//let mut entry_js:&JsValue = &JsValue::from_serde(entry).unwrap();
    			//some = JsValue::from_serde(entry).unwrap();
    	    	//self.find_child(entry_js, name.clone());
    	    	let mut abc:&JsValue = &JsValue::from_serde(entry).unwrap();
    	    	//let other:Jsonformt = abc.into_serde().unwrap();
    	    	self.same_child(abc, name.clone());
    	    }
    	    return JsValue::from_serde(&Jsonformt::new()).unwrap();
    	    //return some;
    	}
    }
}
