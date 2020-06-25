/*fetch('../out/main.wasm').then(response =>
  response.arrayBuffer()
).then(bytes => WebAssembly.instantiate(bytes)).then(results => {
  instance = results.instance;
  var wasm = instance.exports;
  var memory = new Uint8Array(wasm.memory.buffer);
  var program = wasm.program;
}).catch(console.error);*/

//Wat commands
const programStart = `(module
  (func $program (param i32 $inputSize) (local i32 $pointer)`;
loopHeader = (i => ` (local i32 $loop_`+i+`)`);
const loopStart = `
    (block 
      (loop`;
const loopEnd = (i => `
        get_local $loop_`+i+`
        i32.const 1
        i32.add
        set_local $loop_`+i+`
        get_local $loop_`+i+`
        get_local $inputSize
        i32.eq
        br_if 1
        br 0
      )
    )
`);
const commands = {
  '>':`
    get_local $pointer
    i32.const 4
    i32.add
    set_local $pointer`,
  '<':`
    get_local $pointer
    i32.const 4
    i32.sub
    set_local $pointer`,
  '+':`
    get_local $pointer
    get_local $pointer
    i32.load
    i32.const 1
    i32.add
    i32.store`,
  '-':`
    get_local $pointer
    get_local $pointer
    i32.load
    i32.const 1
    i32.sub
    i32.store`,
  '[':`
    get_local $pointer
    i32.load
    (if
      (then`,
  ']':`
      )
    )`
};
const programEnd = `)
  (memory $memory 1)

  (export "memory" (memory $memory))
  (export "program" (func $program))
)`
const command = (c => commands[c]);
const programStartLoops = (i => 
  programStart 
  + Array.apply(null, {length: i}).map(Number.call, Number).map(loopHeader).join('')
  + new Array(i+1).join(loopStart)
  )
const programEndLoops = (i => 
  Array.apply(null, {length: i}).map(Number.call, Number).map(loopEnd).join('')
  + programEnd
  )

const programCenter = (Bprogram => Bprogram.split('').map(command).join(''));
const program = ((Bprogram,i) => 
  programStartLoops(i) + 
  programCenter(Bprogram) +
  programEndLoops(i)
)
console.log('hey');
console.log(program('++[-<>]',5));
