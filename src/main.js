(async () => {
  const REG = [self, 'console', 'log', 'hello wasm: '];

  const ffi = {
    put_i(_dst, i) {
      REG[_dst] = i;
    },

    get_i(_src) {
      return REG[_src];
    },

    print(_val) {
      console.log(_val);
    },

    prop_get(_dst, _obj, _key) {
      const obj = REG[_obj];
      const key = REG[_key];
      REG[_dst] = obj[key];
    },

    prop_call_1_void(_obj, _key, _arg1) {
      const obj = REG[_obj];
      const key = REG[_key];
      const arg1 = REG[_arg1];
      obj[key](arg1);
    },

    add_by(_dst, _src) {
      REG[_dst] += REG[_src];
    },

    add_to(_dst, _src1, _src2) {
      REG[_dst] = REG[_src1] + REG[_src2];
    },
  }

  const res = await fetch('../out/main.wasm');
  const ret = await WebAssembly.instantiateStreaming(res, {
    env: ffi,
  });

  const ins = ret.instance;
  ins.exports.logic();
})();
