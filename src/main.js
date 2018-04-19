(async () => {
  const DEC = new TextDecoder();
  const REG = [self];

  const env = {
    get_i(_src) {
      return REG[_src];
    },

    put_i(_dst, i) {
      REG[_dst] = i;
    },

    put_s(_dst, ptr, len) {
      const buf = arrU8.subarray(ptr, ptr + len);
      REG[_dst] = DEC.decode(buf);
    },

    print(_val) {
      console.log(_val);
    },

    // prop
    prop_get(_dst, _obj, _key) {
      const obj = REG[_obj];
      const key = REG[_key];
      REG[_dst] = obj[key];
    },

    prop_set(_obj, _key, _val) {
      const obj = REG[_obj];
      const key = REG[_key];
      const val = REG[_val];
      obj[key] = val;
    },

    prop_in(_dst, _obj, _key) {
      const obj = REG[_obj];
      const key = REG[_key];
      REG[_dst] = key in obj;
    },

    // prop call
    prop_call_0_void(_obj, _key) {
      const obj = REG[_obj];
      const key = REG[_key];
      obj[key]();
    },

    prop_call_1_void(_obj, _key, _arg1) {
      const obj = REG[_obj];
      const key = REG[_key];
      const arg1 = REG[_arg1];
      obj[key](arg1);
    },

    // ...

    prop_call_0(_dst, _obj, _key) {
      const obj = REG[_obj];
      const key = REG[_key];
      REG[_dst] = obj[key]();
    },

    prop_call_1(_dst, _obj, _key, _arg1) {
      const obj = REG[_obj];
      const key = REG[_key];
      const arg1 = REG[_arg1];
      REG[_dst] = obj[key](arg1);
    },

    // ...

    call_0_void(_fn) {
      const fn = REG[_fn];
      fn();
    },

    call_1_void(_fn, _arg1) {
      const fn = REG[_fn];
      const arg1 = REG[_arg1];
      fn(arg1);
    },

    // ...

    call_0(_dst, _fn) {
      const fn = REG[_fn];
      REG[_dst] = fn();
    },

    call_1(_dst, _fn, _arg1) {
      const fn = REG[_fn];
      const arg1 = REG[_arg1];
      REG[_dst] = fn(arg1);
    },

    // ...

    add_by(_dst, _src) {
      REG[_dst] += REG[_src];
    },

    add_to(_dst, _src1, _src2) {
      REG[_dst] = REG[_src1] + REG[_src2];
    },
  }

  const ret = await WebAssembly.instantiateStreaming(
    fetch('../out/main.wasm'),
    {env}
  );

  const {exports} = ret.instance;
  const {buffer} = exports.memory;
  const arrU8 = new Uint8Array(buffer);

  exports.init();
  exports.logic();
})();
