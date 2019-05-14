const { fibonacci, slow } = wasm_bindgen

function runApp() {
  const target = 71
  console.log('Starting run...................................')
  let t1 = null
  let t2 = null
  let r = null

  //wasm with memoization
  t1 = performance.now()
  r = fibonacci(target)
  t2 = performance.now()
  console.log(`wasm: ${r} - time: ${t2 - t1}`)

  //es6 with tail recursion
  t1 = performance.now()
  r = fibTailRecursion(target)
  t2 = performance.now()
  console.log(`es6 tail: ${r} - time: ${t2 - t1}`)

  //es6 with memoization
  t1 = performance.now()
  r = fibMemoized(target)
  t2 = performance.now()
  console.log(`es6 memo: ${r} - time: ${t2 - t1}`)

  //wasm with nested loops
  const slowTarget = 100
  t1 = performance.now()
  r = slow(slowTarget)
  t2 = performance.now()
  console.log(`wasm O(n^3): ${r} - time: ${t2 - t1}`)

   //es6 with nested loops
  t1 = performance.now()
  r = slowJs(slowTarget)
  t2 = performance.now()
  console.log(`es6 O(n^3): ${r} - time: ${t2 - t1}`)
}

function fibTailRecursion(n, a=0, b=1) {
  if (n === 0) {
    return a
  }
  if (n === 1) {
    return b
  }
  return fibTailRecursion(n-1, b, a+b)
}

function fibMemoized(n) {
  const f = [0, 1];
  for (let i=2; i<=n; i++) {
    f.push(f[i-1] + f[i-2])
  }
  return f.pop()
}

function slowJs(n) {
  let m = 0
  for (let i=0; i<n; i++) {
    for (let o=0; o<n; o++) {
      for (let p=0; p<n; p++) {
        m++;
      }
    }
  }
  return m;
}

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error)
