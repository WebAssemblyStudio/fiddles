const tracing: i32[] = [
  1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0
];
const arrayBuffer = new Array<i32[] | null>(2);

for ( let j = 0; j < 2; j++ ) {
  for (let i = 0; i < tracing.length; i++) {
    let id = tracing[i];
    let arr = arrayBuffer[id];
    if (!arr) arr = arrayBuffer[id] = [];
    arr.push(0);
  }
}
