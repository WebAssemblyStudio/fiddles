const fs = require('fs')
const compiled = new WebAssembly.Module(fs.readFileSync(__dirname + '/build/optimized.wasm'))
const imports = {
  env: {
    seed: Date.now(),
    abort(_msg, _file, line, column) {
      console.error('abort called at index.ts:' + line + ':' + column)
    }
  }
}
// env.seed = env.seed || function seed() {
//   return Date.now
// }
Object.defineProperty(module, 'exports', {
  get: () => new WebAssembly.Instance(compiled, imports).exports
})
