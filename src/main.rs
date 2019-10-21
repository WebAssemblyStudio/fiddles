#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    let  mut   z = 0;
    let mut primos_por_mostrar=x;

    let mut n = 2;
    while primos_por_mostrar > 0 {

        /* determinar si n es primo */
        let mut es_primo = true;
        let mut d = 2;
        while  d < n  {

            if n % d == 0 {
                es_primo = false;
                break;
            }
            d+=1;
        }

        /* mostrar el numero
         * y actualizar el contador */
        if es_primo {
            z+=n;
            primos_por_mostrar-=1;
        }
        n+=1;
    }
    return z
}