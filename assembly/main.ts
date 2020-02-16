class PackedCodeChildOp {
	public op:  u8  = 0b00000111; 
	public arg: u16 = 0;
}

type PackedCodeChild = Array<PackedCodeChildOp>;
type PackedCode      = Array<PackedCodeChild>;

const input = [
  [
    { op: 3, arg: 1 }, 
    { op: 7, arg: 1 }
  ], 
  [
    { op: 1, arg: 1 }, 
    { op: 4, arg: 1 }, 
    { op: 2, arg: 1 }, 
    { op: 0, arg: 1 }, 
    { op: 3, arg: 1 }
  ]
] as PackedCode

const bfMemory = new Array<u8>(65535);

let bfMemoryPointer: u16 = 0;

export function pointerForward(x:u16):void {
	bfMemoryPointer += x;
}

export function pointerBackward(x:u16):void {
	bfMemoryPointer -= x;
}

export function valueGet():u8 {
	return bfMemory[bfMemoryPointer];
}

export function valueSet(x: u8): void {
	bfMemory[bfMemoryPointer] = x;
}

export function valueInc(x: u8): void {
	bfMemory[bfMemoryPointer] += x;
}

export function valueDec(x: u8): void {
	bfMemory[bfMemoryPointer] -= x;
}

function runOp(op: u8, arg: u16, parent: PackedCode, depth: u16): void {
	switch(op) {
		case 0b00000000: {
			pointerBackward(arg);
		} break;
		case 0b00000001: {
			pointerForward(arg);
		} break;
		case 0b00000010: {
			valueInc(<u8>arg);
		} break;
		case 0b00000011: {
			valueDec(<u8>arg);
		} break;
		case 0b00000100: {
			// TODO: Import an output function.
		} break;
		case 0b00000101: {
			// TODO: Import an input function.
		} break;
		case 0b00000110: {
			runAstChild(parent[arg], parent, depth + 1);
		} break;
		case 0b00000111: {
			// NOP.
		} break;
	}
}

function runAstChild(child: PackedCodeChild, parent: PackedCode, depth: u16 = 0):void {
	for (let i = 0; i < child.length; i++) {
		runOp(child[i].op, child[i].arg, parent, depth);
	}

	if (valueGet() !== 0 && depth !== 0) {
		runAstChild(child, parent, depth);
	}
}

export function runAst(code:PackedCode):void {
	runAstChild(code[0], code);
}

export function run(): void {
  runAst(input);
}