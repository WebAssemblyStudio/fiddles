#[no_mangle]
use std::io;
//use rand::Rng;
use std::{thread, time};
use std::cmp::Ordering;
fn getguess() -> i32 {
    let mut guess = String::new();
    io::stdin().read_line(&mut guess)
    .expect("bruh im dead af");
    let guess: i32 = guess.trim().parse()
    .expect("bruh im dead af");
    return guess;
}
fn main (){
    println!("Guess the number between 1 and 100");
    let secret_number = 15;
    println!("Input the Guess");
    loop {
        let guess = getguess();
        match guess.cmp(&secret_number) {
            Ordering::Less => println!{"too small"},
            Ordering::Greater => println!("too big"),
            Ordering::Equal => {
                println!("You got it! {} was the answer!", guess);
                break;
            }
        }
    }
    thread::sleep(time::Duration::from_millis(2000));
}

