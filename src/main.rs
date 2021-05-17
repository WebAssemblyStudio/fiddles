use rand::Rng;

#[no_mangle]
pub extern "C" fn add_one(gg: i32) -> i32 {
        let mut rng = rand::thread_rng();
    let mut arr = [0i32; 1000];
    
    for x in &mut arr {
        *x = rng.gen_range(1..10000);
    }
    
    for i in 1..arr.len() {
        let mut j = i;
        while j > 0 && arr[j - 1] > arr[j] {
            arr.swap(j - 1, j);
            j -= 1;
        }
    }
    return 1; 
}