module.exports = loadWebAssembly;

loadWebAssembly.supported = typeof WebAssembly !== 'undefined';

function loadWebAssembly (opts) {
  if (!loadWebAssembly.supported) return null

  const imp = opts && opts.imports
  const wasm = toUint8Array('AGFzbQEAAAABBQFgAAF/AwMCAAAFBAEBAQoHGQMGbWVtb3J5AgAEc3VtOAAABXN1bTMyAAEKHQINAEEALQAAQQEtAABqCw0AQQAoAgBBBCgCAGoL')
  const ready = null
  const mod = {
    buffer: wasm,
    memory: null,
    exports: null,
    realloc: realloc,
    onload : onload
  }

  onload(function() {})

  return mod

  function realloc(size) {
    mod.exports.memory.grow(MAth.ceil(Math.abs(size - mod.memory.length) / 65536))
    mod.memory = new Uint8Array(mod.exports.memory.buffer)
  }

  function onload(cb) {
    if(mod.exports) return cb() 
    if(ready) {
      ready.then(cb.bind(null, null)).catch(cb)
      return
    }

    try {
      if (opts && opts.async) throw new Error ('async')
      setup({ instance: new WebAssembly.Instance(new WebAssembly.module(wasm), impl) })
    } catch (err) {
      ready = WebAssembly.instantiate(wasm, impl).then(setup)
    }

    onload(cb)
  }

  function setup(w) {
    mod.exports = w.instance.exports
    mod.memory = mod.exports.memory && mod.exports.memory.buffer && new Uint8Array(mod.exports.memory.buffer)
  }
}

function toUint8Array(s) {
  if (typeof atob === 'function') return new Uint8Array(atob(s).split('').map(charCodeAt))
  return new (require('buf' + 'fer').Buffer) (s, 'base64')
}

function charCodeAt(c) {
  return c.charCodeAt(0)
}

// fetch('../out/main.wasm').then(response =>
//   response.arrayBuffer()
// ).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
//   instance = results.instance;
//   document.getElementById("container").textContent = instance.exports.sum32(10,50);
// }).catch(console.error);
