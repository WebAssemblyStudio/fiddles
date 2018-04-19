(async () => {
  const dec = new TextDecoder();
  const REG = [self];

  const ffi = {
    put_i(_dst, i) {
      REG[_dst] = i;
    },

    put_s(_dst, ptr, len) {
      const buf = arrU8.subarray(ptr, ptr + len);
      REG[_dst] = dec.decode(buf);
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

  const {exports} = ret.instance;
  const {buffer} = exports.memory;
  const arrU8 = new Uint8Array(buffer);

  exports.logic();
})();
