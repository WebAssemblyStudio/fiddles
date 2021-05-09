#define WASM_EXPORT __attribute__((visibility("default")))

long fib[] = {12,5,18,4,24,0,38,12,11,13,1,6,0,2,18,21,0,-1,12,11,21,0,-2,12,11,1,15,13,1,14,1,1,999999};

enum InstructionType {BIPUSH, 			// push const arg on stack
                      IADD,   			// add top 2 elements of stack
                      ISUB,   			// sub top 2 elements of stack
                      IMULT,   			// mult top 2 elements of stack
                      IDIV,   			// div top 2 elements of stack
                      IMOD,   			// mod top 2 elements of stack
                      IFLTLV, 			// branch if arg arg0 on stack is less then arg1 to label arg2
                      IFEQ, 			// branch if top = 0
                      IFNEQ, 			// branch if top != 0
                      IFLT, 			// branch if top < 0
                      IFLE, 			// branch if top <= 0
                      IFCMP, 			// branch if top = stack[sp-1]
                      CALL,             // arg0: nr args (args + local), arg1: label of func
                      IRETURN, 			// return from call, result should be on top of stack
                      IRETURN_CONST, 	// return from call, push arg0 on stack
                      INC,				// increment top of stack
                      DEC,				// decrement top of stack
                      DUP,				// dupplicate top of stack
                      PRINT,   			// print top of stack: arg0 0: single line, arg0 1: space after result
                      LOAD, 			// load var arg0 to top of stack
                      STORE, 			// store top of stack in var arg0
                      LOADADD, 			// load var arg0 to top of stack and add arg1 - optimized instruction
                      SWAP,             // exchange top 2 element
                      UPDSP,            // update sp with arg0 - also update stack base to new value!
                      STOP,             // stop execution
                      CREATE,           // create array of size (<=2) arg0 of type arg1 and fill it from the stack
                      PUSHFUNCNR,		// like PUSHFUNC but included check nr
                      GET,              // get arg0 element from array
                      GETN,             // get from array stack[sp-1] element index stack[sp]
                      UPDATE,           // set array stack[sp-2]  index stack[sp-1] to stack[sp]
                      GETALL,           // push all elements from array on stack
                      EVAL,             // evaluate tos (ico closure) until a value occurs
                      BOX,         		// box a value
                      CCREATE,			// create Cons cell of size > 1 arg0 of type arg1 en case arg2,fill from stack
                      DEBUG,			// reserved
                      JMP,				// jump to arg0
                      TAILCALL,			// slice stack: keep args above hv and remove arg0 before and jump to arg1
                      JMPT,				// jump to one of arg0 (size) labels lbl 1, lbl 2, depending  on constructor, push args on stack!
                      STRCREATE,		// string operation
                      STROP,			// string operation
                      FADD,				// float addition
                      FSUB,				// float
                      FMULT,			// float
                      FDIV,				// float
                      FLOATOP,			// arg0  operation = {Sin,Cos,Tan,ASin,ACos,ATan,Log,Log10,Exp,Sqrt,Floor}
                      POW,				// float
                      _AUX,				// {IsValue,GetType,NewArray,IsType,JMPTable,GetMeta,Apply,SetJMP,GoJMP}
                      EOP,				// end of program
                     };

 int run(long* program) {
 	//printf("started\n");
    long  stack [5000];
    long  cstack[5000];

    long pc = 0;

    long  sp  = -1;
    long csp  = -1;
    long mark = 0, hv   =  0;
    long top;
    int na;

 while (1) {
 	switch(program[pc]) {
	 case BIPUSH:
		 top = stack[++sp] = program[pc+1] << 1;
		 pc += 2;
		 break;
	 case IADD:
		 pc++;
		 top = stack[--sp] += top;
		 break;
	 case IFLTLV:
     if (stack[hv - program[pc + 1]] < (program[pc + 2] << 1))
       pc += program[pc + 3];
		 else pc += 4;
		 break;
	 case LOAD:
     top = stack[++sp] = stack[hv - program[pc + 1]];
		 pc += 2;
		 break;
	 case LOADADD:
		 top = stack[++sp] = stack[hv-program[pc+1]] + (program[pc+2] << 1);
		 pc += 3;
		 break;
	 case CALL:
		 cstack[++csp]  = pc + 2;
		 cstack[++csp] = hv;
		 hv   = mark    = sp;
     pc = program[pc+1];
		 break;
	 case IRETURN:
     sp = hv - program[pc + 1] + 1;
     stack[sp] = top;
     hv = mark = cstack[csp--];
     pc = cstack[csp--];
		 break;
	 case IRETURN_CONST:
     sp = hv - program[pc + 1] + 1;
     top = stack[sp] = program[pc + 2] << 1;
     hv = mark = cstack[csp--];
     pc = cstack[csp--];
		 break;
	 case PRINT:
     na = top>>1;
     //printf("res: ");printf("%ld ",top>>1);
		 top = stack[--sp];
		 pc += 2;
     return na;
		 break;
	 case INC:
		 pc++;
		 top = stack[sp] += 2;
		 break;
	 case STOP:
		 //printf("stop\n");
		 return 0;
    }
  }
}

WASM_EXPORT
int main() {
    fib[6] = 38;
    return run(fib);
}

