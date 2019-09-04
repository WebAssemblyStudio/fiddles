#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

// #[no_mangle] - Previene que el compilador elimine y cambie el nombre de la funcion
// pub extern "C" - Bloque publico, Asumimos que será llamado por un objetivo compilado en C