const { fibonacci } = wasm_bindgen

function runApp() {
  const target = 71
  console.log('Starting run...................................')

  //wasm with memoization
  let t = performance.now()
  console.log(fibonacci(target))
  console.log(`wasm: ${performance.now() - t}`)

  //es6 with tail recursion
  t = performance.now()
  console.log(fibTailRecursion(target))
  console.log(`es6 tail: ${performance.now() - t}`)

  //es6 with memoization
  t = performance.now()
  console.log(fibMemoized(target))
  console.log(`es6 memo: ${performance.now() - t}`)
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

wasm_bindgen('../out/main_bg.wasm').then(runApp).catch(console.error)
