WebAssembly.instantiate(new Uint8Array([0,97,115,109,1,0,0,0,1,8,2,96,1,127,0,96,0,0,2,8,1,2,106,
115,1,95,0,0,3,2,1,1,8,1,1,10,9,1,7,0,65,185,10,16,0,11]),
{js:{_:console.log('Called from WebAssembly Hello world')}}).then(function(obj) {
  console.log('Called with instance ' + obj);
}).catch(function(err) {
  console.log('Called with error ' + err);
});