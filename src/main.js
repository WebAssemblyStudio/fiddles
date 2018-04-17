const Foo = new ffi.Struct({
  a: 'u32',
  b: 'u8',
  c: 'u16',
});

const lib = new ffi.Wrapper({
  add: ['number', ['number', 'number']],
  make_string: ['string', ['number']],
  str_length: ['number', ['string']],
  make_foo: [Foo],
  add_foo: ['number', [Foo]],
  sum: ['number', ['array']],
}, {
  dialect: 'assemblyscript'
});

lib.fetch('/out/main.wasm').then(() => {
  console.log('basic numbers, lib.add(1, 2): ' + lib.add(1, 2));

  console.log('make_string: ' + lib.make_string(7));
  console.log('str_length of `9 letters`: ' + lib.str_length('9 letters'));

  const foo = lib.make_foo();
  console.log(`foo: ${foo}`);

  foo.a = 1;
  foo.b = 2;
  foo.c = 3;
  console.log(`foo mutated: ${foo}`);
  console.log("adding foo's fields: " + lib.add_foo(foo));

  const foo2 = new Foo({
    a: 4,
    b: 5,
    c: 6,
  });

  console.log(`made new class: ${foo2}`);
  console.log("dding foo2's fields: " + lib.add_foo(foo2));

  const arr = new Uint32Array([1, 2, 3, 4, 5]);
  console.log(`Sum of array (${arr}): ` + lib.sum(arr));

  console.log('Throwing error (check console):');
  lib.exports.throw_error();
});
