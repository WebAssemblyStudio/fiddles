/**
 * @file nesCPUOpcode.h
 * @author chentian, zhfang
 * @date 2010.06.25
 * @brief NES Emulate For CTR - CPU Opcode
 */
{
u16 nAddr;
s16 nTemp16;
u8 nTemp8,nOpcode;
//switch(nesMemRead8(PC))
LB_NES_CPU_GETOPCODE:
nOpcode = *pNesCpuPC;

LB_NES_CPU_OPCODE:
switch(nOpcode)
{
//Interrupts, Exceptions, Breakpoints
case 0x00: //Break
	P |= NES_CPU_BFLAG;
	STACK_PUSHPC(2);
	STACK_PUSH(P);
	P |= NES_CPU_IFLAG;
	PC = *((u16*)&g_pNesPRGBank[3][0x1FFE]);
	NES_CPU_UPDATE_PC();
	SET_TICK(7);
	break;

//Register to Register Transfer
case 0xA8:	//TAY
	Y = A;
	SET_NZ(Y);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0xAA:	//TAX
	X = A;
	SET_NZ(X);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0xBA:	//TSX
	X = S;
	SET_NZ(X);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x98:	//TYA
	A = Y;
	SET_NZ(A);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x8A:	//TXA
	A = X;
	SET_NZ(A);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x9A:	//TXS
	S = X;
	SET_PC(1);
	SET_TICK(2);
	break;

//Load Register from Memory
case 0xA9:	//LDA #nn
	A = GET_IMMEDIATE();
	SET_NZ(A);
	SET_TICK(2);
	break;
case 0xA5:	//LDA nn
	A = GET_ZEROPAGE();
	SET_NZ(A);
	SET_TICK(3);
	break;
case 0xB5:	//LDA nn,X
	A = GET_ZEROPAGE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xAD:	//LDA nnnn
	A = GET_ABSOLUTE();
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xBD:	//LDA nnnn,X
	A = GET_ABSOLUTE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xB9:	//LDA nnnn,Y
	A = GET_ABSOLUTE_(Y);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xA1:	//LDA (nn,X)
	A = GET_INDIRECT_X();
	SET_NZ(A);
	SET_TICK(6);
	break;
case 0xB1:	//LDA (nn),Y
	A = GET_INDIRECT_Y();
	SET_NZ(A);
	SET_TICK(5);
	break;

case 0xA2:	//LDX #nn
	X = GET_IMMEDIATE();
	SET_NZ(X);
	SET_TICK(2);
	break;
case 0xA6:	//LDX nn
	X = GET_ZEROPAGE();
	SET_NZ(X);
	SET_TICK(3);
	break;
case 0xB6:	//LDX nn,Y
	X = GET_ZEROPAGE_(Y);
	SET_NZ(X);
	SET_TICK(4);
	break;
case 0xAE:	//LDX nnnn
	X = GET_ABSOLUTE();
	SET_NZ(X);
	SET_TICK(4);
	break;
case 0xBE:	//LDX nnnn,Y
	X = GET_ABSOLUTE_(Y);
	SET_NZ(X);
	SET_TICK(4);
	break;

case 0xA0:	//LDY #nn
	Y = GET_IMMEDIATE();
	SET_NZ(Y);
	SET_TICK(2);
	break;
case 0xA4:	//LDY nn
	Y = GET_ZEROPAGE();
	SET_NZ(Y);
	SET_TICK(3);
	break;
case 0xB4:	//LDY nn,X
	Y = GET_ZEROPAGE_(X);
	SET_NZ(Y);
	SET_TICK(4);
	break;
case 0xAC:	//LDY nnnn
	Y = GET_ABSOLUTE();
	SET_NZ(Y);
	SET_TICK(4);
	break;
case 0xBC:	//LDY nnnn,X
	Y = GET_ABSOLUTE_(X);
	SET_NZ(Y);
	SET_TICK(4);
	break;

//Store Register in Memory
case 0x85:	//STA nn
	SET_ZEROPAGE(A);
	SET_TICK(3);
	break;
case 0x95:	//STA nn,X
	SET_ZEROPAGE_(X,A);
	SET_TICK(4);
	break;
case 0x8D:	//STA nnnn
	SET_TICK(4);
	SET_ABSOLUTE(A);
	break;
case 0x9D:	//STA nnnn,X
	SET_TICK(5);
	SET_ABSOLUTE_(X,A);
	break;
case 0x99:	//STA nnnn,Y
	SET_TICK(5);
	SET_ABSOLUTE_(Y,A);
	break;
case 0x81:	//STA (nn,X)
	SET_TICK(6);
	SET_INDIRECT_X(A);
	break;
case 0x91:	//STA (nn),Y
	SET_TICK(6);
	SET_INDIRECT_Y(A);
	break;

case 0x86:	//STX nn
	SET_ZEROPAGE(X);
	SET_TICK(3);
	break;
case 0x96:	//STX nn,Y
	SET_ZEROPAGE_(Y, X);
	SET_TICK(4);
	break;
case 0x8E:	//STX nnnn
	SET_TICK(4);
	SET_ABSOLUTE(X);
	break;

case 0x84:	//STY nn
	SET_ZEROPAGE(Y);
	SET_TICK(3);
	break;
case 0x94:	//STY nn,X
	SET_ZEROPAGE_(X, Y);
	SET_TICK(4);
	break;
case 0x8C:	//STY nnnn
	SET_TICK(4);
	SET_ABSOLUTE(Y);
	break;

//Push/Pull
case 0x48:	//PHA
	STACK_PUSH(A);
	SET_PC(1);
	SET_TICK(3);
	break;
case 0x08:	//PHP
//	P |= NES_CPU_BFLAG;
	STACK_PUSH(P|NES_CPU_BFLAG);
	SET_PC(1);
	SET_TICK(3);
	break;
case 0x68:	//PLA
	STACK_PULL(A);
	SET_NZ(A);
	SET_PC(1);
	SET_TICK(4);
	break;
case 0x28:	//PLP
	nTemp8 = P & (NES_CPU_BFLAG|NES_CPU_UFLAG);
	STACK_PULL(P);
	P |= nTemp8;
	SET_PC(1);
	SET_TICK(4);
	break;

//Add memory to accumulator with carry
case 0x69:	//ADC #nn
	nTemp8 = GET_IMMEDIATE();
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(2);
	break;
case 0x65:	//ADC nn
	nTemp8 = GET_ZEROPAGE();
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(3);
	break;
case 0x75:	//ADC nn,X
	nTemp8 = GET_ZEROPAGE_(X);
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0x6D:	//ADC nnnn
	nTemp8 = GET_ABSOLUTE();
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0x7D:	//ADC nnnn,X
	nTemp8 = GET_ABSOLUTE_(X);
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0x79:	//ADC nnnn,Y
	nTemp8 = GET_ABSOLUTE_(Y);
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0x61:	//ADC (nn,X)
	nTemp8 = GET_INDIRECT_X();
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(6);
	break;
case 0x71:	//ADC (nn), Y
	nTemp8 = GET_INDIRECT_Y();
	nTemp16 = A + nTemp8 + GET_CFLAG();
	SET_NVZC_ADD(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(5);
	break;

//Subtract memory from accumulator with borrow
case 0xE9:	//SBC #nn
	nTemp8 = GET_IMMEDIATE();
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(2);
	break;
case 0xE5:	//SBC nn
	nTemp8 = GET_ZEROPAGE();
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(3);
	break;
case 0xF5:	//SBC nn,X
	nTemp8 = GET_ZEROPAGE_(X);
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0xED:	//SBC nnnn
	nTemp8 = GET_ABSOLUTE();
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0xFD:	//SBC nnnn,X
	nTemp8 = GET_ABSOLUTE_(X);
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0xF9:	//SBC nnnn,Y
	nTemp8 = GET_ABSOLUTE_(Y);
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(4);
	break;
case 0xE1:	//SBC (nn,X)
	nTemp8 = GET_INDIRECT_X();
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(6);
	break;
case 0xF1:	//SBC (nn), Y
	nTemp8 = GET_INDIRECT_Y();
	nTemp16 = A - 1 - nTemp8 + GET_CFLAG();
	SET_NVZC_SUB(nTemp8, nTemp16);
	A = (u8)nTemp16;
	SET_TICK(5);
	break;

//Logical AND memory with accumulator
case 0x29:	//AND #nn
	A &= GET_IMMEDIATE();
	SET_NZ(A);
	SET_TICK(2);
	break;
case 0x25:	//AND nn
	A &= GET_ZEROPAGE();
	SET_NZ(A);
	SET_TICK(3);
	break;
case 0x35:	//AND nn,X
	A &= GET_ZEROPAGE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x2D:	//AND nnnn
	A &= GET_ABSOLUTE();
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x3D:	//AND nnnn,X
	A &= GET_ABSOLUTE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x39:	//AND nnnn,Y
	A &= GET_ABSOLUTE_(Y);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x21:	//AND (nn,X)
	A &= GET_INDIRECT_X();
	SET_NZ(A);
	SET_TICK(6);
	break;
case 0x31:	//AND (nn),Y
	A &= GET_INDIRECT_Y();
	SET_NZ(A);
	SET_TICK(5);
	break;

//Exclusive-OR memory with accumulator
case 0x49:	//EOR #nn
	A ^= GET_IMMEDIATE();
	SET_NZ(A);
	SET_TICK(2);
	break;
case 0x45:	//EOR nn
	A ^= GET_ZEROPAGE();
	SET_NZ(A);
	SET_TICK(3);
	break;
case 0x55:	//EOR nn,X
	A ^= GET_ZEROPAGE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x4D:	//EOR nnnn
	A ^= GET_ABSOLUTE();
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x5D:	//EOR nnnn,X
	A ^= GET_ABSOLUTE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x59:	//EOR nnnn,Y
	A ^= GET_ABSOLUTE_(Y);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x41:	//EOR (nn,X)
	A ^= GET_INDIRECT_X();
	SET_NZ(A);
	SET_TICK(6);
	break;
case 0x51:	//EOR (nn),Y
	A ^= GET_INDIRECT_Y();
	SET_NZ(A);
	SET_TICK(5);
	break;

//Logical OR memory with accumulator
case 0x09:	//ORA #nn
	A |= GET_IMMEDIATE();
	SET_NZ(A);
	SET_TICK(2);
	break;
case 0x05:	//ORA nn
	A |= GET_ZEROPAGE();
	SET_NZ(A);
	SET_TICK(3);
	break;
case 0x15:	//ORA nn,X
	A |= GET_ZEROPAGE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x0D:	//ORA nnnn
	A |= GET_ABSOLUTE();
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x1D:	//ORA nnnn,X
	A |= GET_ABSOLUTE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x19:	//ORA nnnn,Y
	A |= GET_ABSOLUTE_(Y);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0x01:	//ORA (nn,X)
	A |= GET_INDIRECT_X();
	SET_NZ(A);
	SET_TICK(6);
	break;
case 0x11:	//ORA (nn),Y
	A |= GET_INDIRECT_Y();
	SET_NZ(A);
	SET_TICK(5);
	break;

//Compare
case 0xC9:	//CMP #nn
	nTemp16 = A - GET_IMMEDIATE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(2);
	break;
case 0xC5:	//CMP nn
	nTemp16 = A - GET_ZEROPAGE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(3);
	break;
case 0xD5:	//CMP nn,X
	nTemp16 = A - GET_ZEROPAGE_(X);
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;
case 0xCD:	//CMP nnnn
	nTemp16 = A - GET_ABSOLUTE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;
case 0xDD:	//CMP nnnn,X
	nTemp16 = A - GET_ABSOLUTE_(X);
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;
case 0xD9:	//CMP nnnn,Y
	nTemp16 = A - GET_ABSOLUTE_(Y);
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;
case 0xC1:	//CMP (nn,X)
	nTemp16 = A - GET_INDIRECT_X();
	SET_NZC_CMP(nTemp16);
	SET_TICK(6);
	break;
case 0xD1:	//CMP (nn),Y
	nTemp16 = A - GET_INDIRECT_Y();
	SET_NZC_CMP(nTemp16);
	SET_TICK(5);
	break;

case 0xE0:	//CPX #nn
	nTemp16 = X - GET_IMMEDIATE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(2);
	break;
case 0xE4:	//CPX nn
	nTemp16 = X - GET_ZEROPAGE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(3);
	break;
case 0xEC:	//CPX nnnn
	nTemp16 = X - GET_ABSOLUTE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;
case 0xC0:	//CPY #nn
	nTemp16 = Y - GET_IMMEDIATE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(2);
	break;
case 0xC4:	//CPY nn
	nTemp16 = Y - GET_ZEROPAGE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(3);
	break;
case 0xCC:	//CPY nnnn
	nTemp16 = Y - GET_ABSOLUTE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(4);
	break;

//Bit Test
case 0x24:	//BIT nn
	nTemp8 = GET_ZEROPAGE();
	P = (P&0x3D) | (nTemp8&0xC0) | CHECK_Z((nTemp8&A));
	SET_TICK(3);
	break;
case 0x2C:	//BIT nnnn
	nTemp8 = GET_ABSOLUTE();
	P = (P&0x3D) | (nTemp8&0xC0) | CHECK_Z((nTemp8&A));
	SET_TICK(4);
	break;

//Increment by one
case 0xE6:	//INC nn
	nTemp8 = ++GET_ZEROPAGE();
	SET_NZ(nTemp8);
	SET_TICK(5);
	break;
case 0xF6:	//INC nn,X
	nTemp8 = ++GET_ZEROPAGE_(X);
	SET_NZ(nTemp8);
	SET_TICK(6);
	break;
case 0xEE:	//INC nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp8 = nesMemRead8(nAddr) + 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_NZ(nTemp8);
	SET_PC(3);
	break;
case 0xFE:	//INC nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp8 = nesMemRead8(nAddr) + 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_NZ(nTemp8);
	SET_PC(3);
	break;
case 0xE8:	//INC X
	++X;
	SET_NZ(X);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0xC8:	//INC Y
	++Y;
	SET_NZ(Y);
	SET_PC(1);
	SET_TICK(2);
	break;

//Decrement by one
case 0xC6:	//DEC nn
	nTemp8 = --GET_ZEROPAGE();
	SET_NZ(nTemp8);
	SET_TICK(5);
	break;
case 0xD6:	//DEC nn,X
	nTemp8 = --GET_ZEROPAGE_(X);
	SET_NZ(nTemp8);
	SET_TICK(6);
	break;
case 0xCE:	//DEC nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp8 = nesMemRead8(nAddr) - 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_NZ(nTemp8);
	SET_PC(3);
	break;
case 0xDE:	//DEC nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp8 = nesMemRead8(nAddr) - 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_NZ(nTemp8);
	SET_PC(3);
	break;
case 0xCA:	//DEC X
	--X;
	SET_NZ(X);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x88:	//DEC Y
	--Y;
	SET_NZ(Y);
	SET_PC(1);
	SET_TICK(2);
	break;

//Shift Left
case 0x0A:	//ASL A
	nTemp16 = A << 1;
	SET_NZC_LEFT(nTemp16);
	A = (u8)nTemp16;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x06:	//ASL nn
	nAddr = GET_PCCODE_8();
	nTemp16 = g_pNesWRAM[nAddr] << 1;
	SET_NZC_LEFT(nTemp16);
	g_pNesWRAM[nAddr] = (u8)nTemp16;
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x16:	//ASL nn,X
	nAddr = GET_PCCODE_8() + X;
	nTemp16 = g_pNesWRAM[nAddr] << 1;
	SET_NZC_LEFT(nTemp16);
	g_pNesWRAM[nAddr] = (u8)nTemp16;
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x0E:	//ASL nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp16 = nesMemRead8(nAddr) << 1;
	SET_NZC_LEFT(nTemp16);
	nesMemWrite8(nAddr, (u8)nTemp16);	
	SET_PC(3);
	break;
case 0x1E:	//ASL nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp16 = nesMemRead8(nAddr) << 1;
	SET_NZC_LEFT(nTemp16);
	nesMemWrite8(nAddr, (u8)nTemp16);	
	SET_PC(3);
	break;

//Shift Right
case 0x4A:	//LSR A
	SET_NZC_RIGHT(A);
	A >>= 1;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x46:	//LSR nn
	nAddr = GET_PCCODE_8();
	nTemp8 = g_pNesWRAM[nAddr];
	SET_NZC_RIGHT(nTemp8);
	nTemp8 >>= 1;
	g_pNesWRAM[nAddr] = nTemp8;
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x56:	//LSR nn,X
	nAddr = GET_PCCODE_8() + X;
	nTemp8 = g_pNesWRAM[nAddr];
	SET_NZC_RIGHT(nTemp8);
	nTemp8 >>= 1;
	g_pNesWRAM[nAddr] = nTemp8;
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x4E:	//LSR nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp8 = nesMemRead8(nAddr);
	SET_NZC_RIGHT(nTemp8);
	nTemp8 >>= 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_PC(3);
	break;
case 0x5E:	//LSR nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp8 = nesMemRead8(nAddr);
	SET_NZC_RIGHT(nTemp8);
	nTemp8 >>= 1;
	nesMemWrite8(nAddr, nTemp8);
	SET_PC(3);
	break;

//Rotate Left through Carry
case 0x2A:	//ROL A
	nTemp16 = (A<<1) | GET_CFLAG();
	A = (u8)nTemp16;
	SET_NZC_LEFT(nTemp16);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x26:	//ROL nn
	nAddr = GET_PCCODE_8();
	nTemp16 = (g_pNesWRAM[nAddr]<<1) | GET_CFLAG();
	g_pNesWRAM[nAddr] = (u8)nTemp16;
	SET_NZC_LEFT(nTemp16);
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x36:	//ROL nn,X
	nAddr = GET_PCCODE_8() + X;
	nTemp16 = (g_pNesWRAM[nAddr]<<1) | GET_CFLAG();
	g_pNesWRAM[nAddr] = (u8)nTemp16;
	SET_NZC_LEFT(nTemp16);
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x2E:	//ROL nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp16 = (nesMemRead8(nAddr)<<1) | GET_CFLAG();
	nesMemWrite8(nAddr, (u8)nTemp16);
	SET_NZC_LEFT(nTemp16);
	SET_PC(3);
	break;
case 0x3E:	//ROL nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp16 = (nesMemRead8(nAddr)<<1) | GET_CFLAG();
	nesMemWrite8(nAddr, (u8)nTemp16);
	SET_NZC_LEFT(nTemp16);
	SET_PC(3);
	break;

//Rotate Right through Carry
case 0x6A:	//ROR A
	nTemp16 = A | (GET_CFLAG() << 8);
	A = (u8)(nTemp16>>1);
	SET_NZC_RIGHTC(nTemp16);
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x66:	//ROR nn
	nAddr = GET_PCCODE_8();
	nTemp16 = g_pNesWRAM[nAddr] | (GET_CFLAG() << 8);
	g_pNesWRAM[nAddr] = (u8)(nTemp16>>1);
	SET_NZC_RIGHTC(nTemp16);
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x76:	//ROR nn,X
	nAddr = GET_PCCODE_8() + X;
	nTemp16 = g_pNesWRAM[nAddr] | (GET_CFLAG() << 8);
	g_pNesWRAM[nAddr] = (u8)(nTemp16>>1);
	SET_NZC_RIGHTC(nTemp16);
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x6E:	//ROR nnnn
	SET_TICK(6);
	nAddr = GET_PCCODE_16();
	nTemp16 = nesMemRead8(nAddr) | (GET_CFLAG() << 8);
	nesMemWrite8(nAddr, (u8)(nTemp16>>1));
	SET_NZC_RIGHTC(nTemp16);
	SET_PC(3);
	break;
case 0x7E:	//ROR nnnn,X
	SET_TICK(7);
	nAddr = GET_PCCODE_16() + X;
	nTemp16 = nesMemRead8(nAddr) | (GET_CFLAG() << 8);
	nesMemWrite8(nAddr, (u8)(nTemp16>>1));
	SET_NZC_RIGHTC(nTemp16);
	SET_PC(3);
	break;

//Normal Jumps
case 0x4C:	//JMP nnnn
	PC = GET_PCCODE_16();
	NES_CPU_UPDATE_PC();
	SET_TICK(3);
	break;
case 0x6C:	//JMP (nnnn)
	nAddr = GET_PCCODE_16();
	if((nAddr&0xFF) == 0xFF)
		PC = nesMemRead8(nAddr) + nesMemRead8(nAddr&0xFF00)*0x100;
	else
		PC = nesMemRead16(nAddr);
	NES_CPU_UPDATE_PC();
	SET_TICK(5);
	break;
case 0x20:	//JSR nnnn
	STACK_PUSHPC(2);
	PC = GET_PCCODE_16();
	NES_CPU_UPDATE_PC();
	SET_TICK(6);
	break;
case 0x40:	//RTI
//	nTemp8 = P & (NES_CPU_BFLAG|NES_CPU_UFLAG);
	STACK_PULL(P);
//	P |= nTemp8;
	STACK_PULLPC(0);
	SET_TICK(6);
	break;
case 0x60:	//RTS
	STACK_PULLPC(1);
	SET_TICK(6);
	break;

//Conditional Branches
case 0x10:	//BPL disp
	if(!(P & NES_CPU_NFLAG))
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0x30:	//BMI disp
	if(P & NES_CPU_NFLAG)
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0x50:	//BVC disp
	if(!(P & NES_CPU_VFLAG))
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0x70:	//BVS disp
	if(P & NES_CPU_VFLAG)
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0x90:	//BCC disp
	if(!(P & NES_CPU_CFLAG))
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0xB0:	//BCS disp
	if(P & NES_CPU_CFLAG)
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0xD0:	//BNE disp
	if(!(P & NES_CPU_ZFLAG))
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;
case 0xF0:	//BEQ disp
	if(P & NES_CPU_ZFLAG)
	{
		nAddr = PC + 2;
		nTemp16 = (s8)GET_PCCODE_8() + 2;
		SET_PC(nTemp16);
		if((nAddr^PC)&0x100)
			SET_TICK(4);
		else
			SET_TICK(3);
	}
	else
	{
		SET_PC(2);
		SET_TICK(2);
	}
	break;

//CPU Control
case 0x18:	//CLC
	P &= ~NES_CPU_CFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x58:	//CLI
	P &= ~NES_CPU_IFLAG;
	SET_PC(1);
	SET_TICK(2);
	g_nNesCpuEventTicks = nNesCpuTicks;
	break;
case 0xD8:	//CLD
	P &= ~NES_CPU_DFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0xB8:	//CLV
	P &= ~NES_CPU_VFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;

case 0x38:	//SEC
	P |= NES_CPU_CFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x78:	//SEI
	P |= NES_CPU_IFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;
case 0xF8:	//SED
	P |= NES_CPU_DFLAG;
	SET_PC(1);
	SET_TICK(2);
	break;

//No Operation
case 0xEA:	//NOP
	SET_PC(1);
	SET_TICK(2);
	break;

// CPU Illegal Opcodes //
//SAX=STA+STX
case 0x87:	//SAX nn
	nTemp8 = A & X;
	SET_ZEROPAGE(nTemp8);
	SET_TICK(3);
	break;
case 0x97:	//SAX nn,Y
	nTemp8 = A & X;
	SET_ZEROPAGE_(Y, nTemp8);
	SET_TICK(4);
	break;
case 0x8F:	//SAX nnnn
	SET_TICK(4);
	nTemp8 = A & X;
	SET_ABSOLUTE(nTemp8);
	break;
case 0x83:	//SAX (nn,X)
	SET_TICK(6);
	nTemp8 = A & X;
	SET_INDIRECT_X(nTemp8);
	break;

//LAX=LDA+LDX
case 0xA7:	//LAX nn
	A = X = GET_ZEROPAGE();
	SET_NZ(A);
	SET_TICK(3);
	break;
case 0xB7:	//LAX nn,Y
	A = X = GET_ZEROPAGE_(Y);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xAF:	//LAX nnnn
	A = X = GET_ABSOLUTE();
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xBF:	//LAX nnnn,X
	A = X = GET_ABSOLUTE_(X);
	SET_NZ(A);
	SET_TICK(4);
	break;
case 0xA3:	//LAX (nn,X)
	A = X = GET_INDIRECT_X();
	SET_NZ(A);
	SET_TICK(6);
	break;
case 0xB3:	//LAX (nn),Y
	A = X = GET_INDIRECT_Y();
	SET_NZ(A);
	SET_TICK(5);
	break;

//KIL/JAM/HLT
case 0x02:	//KIL
case 0x12:
case 0x22:
case 0x32:
case 0x42:
case 0x52:
case 0x62:
case 0x72:
case 0x92:
case 0xB2:
case 0xD2:
case 0xF2:
	SET_TICK(0xFF);
	break;

//NUL/NOP
case 0x1A:	//NOP
case 0x3A:
case 0x5A:
case 0x7A:
case 0xDA:
case 0xFA:
	SET_PC(1);
	SET_TICK(2);
	break;
case 0x80:	//NOP #nn
case 0x82:
case 0x89:
case 0xC2:
case 0xE2:
	SET_PC(2);
	SET_TICK(2);
	break;
case 0x04:	//NOP nn
case 0x44:
case 0x64:
	SET_PC(2);
	SET_TICK(3);
	break;
case 0x14:	//NOP nn,X
case 0x34:
case 0x54:
case 0x74:
case 0xD4:
case 0xF4:
	SET_PC(2);
	SET_TICK(4);
	break;
case 0x0C:	//NOP nnnn
	SET_PC(3);
	SET_TICK(4);
	break;
case 0x1C:	//NOP nnnn,X
case 0x3C:
case 0x5C:
case 0x7C:
case 0xDC:
case 0xFC:
	SET_PC(3);
	SET_TICK(4);
	break;

case 0x0B:	//ANC #nn
case 0x2B:	//ANC #nn
case 0x4B:	//ALR #nn
case 0x6B:	//ARR #nn
case 0x8B:	//XAA #nn
case 0xAB:	//LAX #nn
case 0xCB:	//AXS #nn
case 0xEB:	//SBC #nn
	SET_PC(2);
	SET_TICK(2);
	break;
case 0x93:	//AHX (nn),Y
	SET_PC(2);
	SET_TICK(6);
	break;

case 0x9F:	//AHX nnnn,Y
case 0x9C:	//SHY nnnn,X
case 0x9E:	//SHX nnnn,Y
case 0x9B:	//TAS nnnn,Y
	SET_PC(3);
	SET_TICK(5);
	break;
case 0xBB:	//LAS nnnn,Y
	SET_PC(3);
	SET_TICK(4);
	break;

//Combined ALU-Opcodes
//SLO=ASL+ORA
case 0x07:	//SLO nn
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x17:	//SLO nn,X
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x03:	//SLO (nn,X)
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x13:	//SLO (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x0F:	//SLO nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0x1F:	//SLO nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0x1B:	//SLO nnnn,Y
	SET_PC(3);
	SET_TICK(7);
	break;

//RLA=ROL+AND
case 0x27:	//RLA nn
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x37:	//RLA nn,X
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x23:	//RLA (nn,X)
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x33:	//RLA (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x2F:	//RLA nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0x3F:	//RLA nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0x3B:	//RLA nnnn,Y
	SET_PC(3);
	SET_TICK(7);
	break;

//SRE=LSR+EOR
case 0x47:	//SRE nn
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x57:	//SRE nn,X
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x43:	//SRE (nn,X)
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x53:	//SRE (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x4F:	//SRE nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0x5F:	//SRE nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0x5B:	//SRE nnnn,Y
	SET_PC(3);
	SET_TICK(7);
	break;

//RRA=ROR+ADC
case 0x67:	//RRA nn
	SET_PC(2);
	SET_TICK(5);
	break;
case 0x77:	//RRA nn,X
	SET_PC(2);
	SET_TICK(6);
	break;
case 0x63:	//RRA (nn,X)
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x73:	//RRA (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0x6F:	//RRA nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0x7F:	//RRA nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0x7B:	//RRA nnnn,Y
	SET_PC(3);
	SET_TICK(7);
	break;

//DCP=DEC+CMP
case 0xC7:	//DCP nn
	SET_PC(2);
	SET_TICK(5);
	break;
case 0xD7:	//DCP nn,X
	SET_PC(2);
	SET_TICK(6);
	break;
case 0xC3:	//DCP (nn,X)
	SET_PC(2);
	SET_TICK(8);
	break;
case 0xD3:	//DCP (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0xCF:	//DCP nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0xDF:	//DCP nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0xDB:	//DCP nnnn,Y
	SET_PC(3);
	SET_TICK(7);
	break;

//ISC=INC+SBC
case 0xE7:	//ISC nn		- FDS Read File for TRL
	nesCardDiskSystemRead();
	nNesCpuRegP = g_nNesCpuRegP;
	// 0x60: RTS
	STACK_PULLPC(1);
	SET_PC(4);
	SET_TICK(6);
	break;
case 0xF7:	//ISC nn,X		- FDS Write File for TRL
	nesCardDiskSystemWrite();
	nNesCpuRegP = g_nNesCpuRegP;
	// 0x60: RTS
	STACK_PULLPC(1);
	SET_PC(4);
	SET_TICK(6);
	break;
case 0xE3:	//ISC (nn,X)	- FDS Switch Disk for TRL
	// 0xE0: CPX #nn
	nTemp16 = X - GET_IMMEDIATE();
	SET_NZC_CMP(nTemp16);
	SET_TICK(2);
	break;
case 0xF3:	//ISC (nn),Y
	SET_PC(2);
	SET_TICK(8);
	break;
case 0xEF:	//ISC nnnn
	SET_PC(3);
	SET_TICK(6);
	break;
case 0xFF:	//ISC nnnn,X
	SET_PC(3);
	SET_TICK(7);
	break;
case 0xFB:	//ISC nnnn,Y	- Patch
	{
		g_pNesCpuPC = pNesCpuPC;
		g_nNesCpuRegPC = nNesCpuRegPC;
		g_nNesCpuRegP = nNesCpuRegP;
		nOpcode = nesCpuPatch();
		nNesCpuRegP = g_nNesCpuRegP;
		if(nOpcode != 0xFB)
			goto LB_NES_CPU_OPCODE;
		else
		{
			SET_PC(3);
			SET_TICK(4);
			goto LB_NES_CPU_GETOPCODE;
		}
	}
}
}
