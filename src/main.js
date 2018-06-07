
(async () => {
  const config = {
    env: {
        DYNAMICTOP_PTR: 0,
        STACKTOP: 0,
        STACK_MAX: 0,
        abort: function() {},
        enlargeMemory: function() {},
        getTotalMemory: function() {},
        abortOnCannotGrowMemory: function() {},
        ___lock: function() {},
        ___syscall6: function() {},
        ___setErrNo: function() {},
        ___syscall140: function() {},
        _emscripten_memcpy_big: function() {},
        ___syscall54: function() {},
        ___unlock: function() {},
        ___syscall146: function() {},
        _gmtime: function() {},
        _ftime: function() {},
        ___syscall20: function() {},
        ___assert_fail: function() {},

        memory: new WebAssembly.Memory({initial: 512, maximum: 512}),
        table: new WebAssembly.Table({initial: 14, element: 'anyfunc', maximum: 14}),
        memoryBase: 0,
        tableBase: 0,
    }
  }
  const fetchPromise = fetch('bin.wasm');
  const {instance} = await WebAssembly.instantiateStreaming(fetchPromise, config);
  const result = instance.exports._cryptonight_hash(1);
  console.log(result);
  return result;
})(); 