declare function printTime(x:string): void;


function fibonacci(x:i32):i32 {
  if (x < 2) {
    return x;
  }
  return fibonacci(x - 1) + fibonacci(x - 2);
}

function add():i32 {
  printTime('Started at: ');
  let x = fibonacci(22);
  printTime('Finished at: ');
  return x;
}
export {fibonacci, add}
