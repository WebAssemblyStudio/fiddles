/**
 * @file nesCpu.cpp
 * @author chentian, zhfang
 * @date 2010.06.25
 * @brief NES Emulate For CTR - CPU
 */
#include "nesCPU.h"
#include "nesGraphic.h"
#include "nesMemory.h"
#include "nesCard.h"

#define TRL_CPU_OPCODE_REG_FAST_TICK 1
#define TRL_CPU_OPCODE_REG_FAST_REGP 1
#define TRL_CPU_OPCODE_REG_FAST_REGPC 1
#define TRL_CPU_OPCODE_REG_FAST_REGA 0
#define TRL_CPU_OPCODE_REG_FAST_OPCODE 0

/** @name Macro Define */
//@{
#define NES_CPU_CFLAG		0x01
#define NES_CPU_ZFLAG		0x02
#define NES_CPU_IFLAG		0x04
#define NES_CPU_DFLAG		0x08
#define NES_CPU_BFLAG		0x10
#define NES_CPU_UFLAG		0x20
#define NES_CPU_VFLAG		0x40
#define NES_CPU_NFLAG		0x80

#define A_G					g_nNesCpuRegA
#define X					g_nNesCpuRegX
#define Y					g_nNesCpuRegY
#define S					g_nNesCpuRegS
#define P_G					g_nNesCpuRegP
#define PC_G				g_nNesCpuRegPC

#define P					nNesCpuRegP
#define PC					nNesCpuRegPC
#define A					g_nNesCpuRegA

#define	CHECK_Z(v)			((!v) << 1)
#define	CHECK_Z16(v)		((!(v&0xFF)) << 1)
#define	CHECK_N(v)			(v&0x80)

#define GET_CFLAG()			(P&NES_CPU_CFLAG)

#define SET_NZ(v)			(P = (P&0x7D) | CHECK_Z(v) | CHECK_N(v))
#define SET_NZC_CMP(v)		(P = (P&0x7C) | CHECK_Z16(v) | CHECK_N(v) | (v>=0))
#define SET_NZC_LEFT(v)		(P = (P&0x7C) | CHECK_Z16(v) | CHECK_N(v) | ((v&0x0100) >> 8))
#define SET_NZC_RIGHT(v)	(P = (P&0x7C) | CHECK_Z((v>>1)) | (v&0x01))
#define SET_NZC_RIGHTC(v)	(P = (P&0x7C) | CHECK_Z((v>>1)) | ((v&0x100)>>1) | (v&0x01))
#define SET_NVZC_ADD(w,v)	(P = (P&0x3C) | CHECK_Z16(v) | CHECK_N(v) | ((v>>8)&NES_CPU_CFLAG) | (((~(A^w))&(A^v)&0x80)>>1))
#define SET_NVZC_SUB(w,v)	(P = (P&0x3C) | CHECK_Z16(v) | CHECK_N(v) | (v>=0) | (((A^w)&(A^v)&0x80)>>1))

#define SET_PC_G(v)			(g_pNesCpuPC += v, PC += v)
#define SET_TICK_G(v)		(g_nNesCpuTicks += v)

#define SET_PC(v)			(pNesCpuPC += v, PC += v)

#define GET_PCCODE_8()		(*(pNesCpuPC+1))
#define GET_PCCODE_16()		(*((u16*)(pNesCpuPC+1)))


#define NES_CPU_UPDATE_PC() (g_nNesCpuRegPC = nNesCpuRegPC,pNesCpuPC = nesCpuUpdatePC())

#define SET_TICK(v)			(nNesCpuTicks += v)
#define CPU_TICKS			nNesCpuTicks

#define GET_IMMEDIATE()		GET_PCCODE_8();SET_PC(2)
#define GET_ZEROPAGE()		g_pNesWRAM[GET_PCCODE_8()];SET_PC(2)
#define GET_ZEROPAGE_(r)	g_pNesWRAM[(u8)(GET_PCCODE_8() + r)];SET_PC(2)
#define GET_ABSOLUTE()		nesMemRead8(GET_PCCODE_16());SET_PC(3)
#define GET_ABSOLUTE_(r)	nesMemRead8(nesCpuCheckCross(GET_PCCODE_16(), r, &CPU_TICKS));SET_PC(3)
#define GET_INDIRECT_X()	nesMemRead8(*((u16*)&g_pNesWRAM[(u8)(GET_PCCODE_8()+ X)]));SET_PC(2)
#define GET_INDIRECT_Y()	nesMemRead8(nesCpuCheckCross(*((u16*)&g_pNesWRAM[GET_PCCODE_8()]), Y, &CPU_TICKS));SET_PC(2)

//#define SET_ZEROPAGE(v)		trlTraceMemWrite(GET_PCCODE_8(), v);(g_pNesWRAM[GET_PCCODE_8()] = v);SET_PC(2)
//#define SET_ZEROPAGE_(r,v)	trlTraceMemWrite(GET_PCCODE_8() + r, v);(g_pNesWRAM[(u8)(GET_PCCODE_8() + r)] = v);SET_PC(2)
#define SET_ZEROPAGE(v)		(g_pNesWRAM[GET_PCCODE_8()] = v);SET_PC(2)
#define SET_ZEROPAGE_(r,v)	(g_pNesWRAM[(u8)(GET_PCCODE_8() + r)] = v);SET_PC(2)

#define SET_ABSOLUTE(v)		g_nNesCpuTicks=nNesCpuTicks;nesMemWrite8(GET_PCCODE_16(), v);nNesCpuTicks=g_nNesCpuTicks;SET_PC(3)
#define SET_ABSOLUTE_(r,v)	g_nNesCpuTicks=nNesCpuTicks;nesMemWrite8(GET_PCCODE_16() + r, v);nNesCpuTicks=g_nNesCpuTicks;SET_PC(3)

#define SET_INDIRECT_X(v)	nesMemWrite8(*((u16*)&g_pNesWRAM[(u8)(GET_PCCODE_8() + X)]), v);SET_PC(2)
#define SET_INDIRECT_Y(v)	nesMemWrite8(*((u16*)&g_pNesWRAM[GET_PCCODE_8()]) + Y, v);SET_PC(2)

#define STACK_PUSH(v)		(g_pNesWRAM[S+0x100] = v, --S)
#define STACK_PUSHPC(v)		(*(u16*)(g_pNesWRAM+S-1+0x100) = PC+v, S -= 2)
#define STACK_PUSHPC_G(v)	(*(u16*)(g_pNesWRAM+S-1+0x100) = PC_G+v, S -= 2)
#define STACK_PULL(v)		(++S, v = g_pNesWRAM[S+0x100])
#define STACK_PULLPC(v)		(S += 2, PC = *(u16*)(g_pNesWRAM+S-1+0x100) + v, NES_CPU_UPDATE_PC())
//@}

/** @name Global Variable */
//@{
s32							g_nNesCpuEventTicks;						///< Next Event Ticks
s32							g_nNesCpuTicks;								///< CPU Run Ticks
u16							g_nNesCpuRegPC;								///< CPU Registe PC
u8							g_nNesCpuRegA;								///< CPU Registe A
u8							g_nNesCpuRegX;								///< CPU Registe X
u8							g_nNesCpuRegY;								///< CPU Registe Y
u8							g_nNesCpuRegS;								///< CPU Registe S
u8							g_nNesCpuRegP;								///< CPU Registe P
u8							g_nNesCpuNMIFlag;							///< CPU NMI Flag
u8							g_nNesCpuIRQFlag;							///< CPU IRQ Flag
u8							g_nNesCpuRESETFlag;							///< CPU RESET Flag

u8*							g_pNesCpuPC;								///< CPU PC Pointer
u32							g_nNesCpuSaveData = 0;						///< CPU Save Data Count
trlSEmuShellResume			g_sNesCpuSaveData[NES_CPU_SAVEDATA_MAX];	///< CPU Save Data
//@}

/** @brief Initialize CPU */
void nesCpuInit()
{
	// Save Data
	g_nNesCpuSaveData = 0;
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuEventTicks, 4, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuTicks, 4, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegPC, 2, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegA, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegX, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegY, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegS, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRegP, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuNMIFlag, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuIRQFlag, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesCpuSaveData[g_nNesCpuSaveData++],&g_nNesCpuRESETFlag, 1, 3, 0);

	nesCpuReset();
}

/** @brief Update PC Pointer */
void nesCpuUpdatePC_G()
{
	switch(PC_G >> 13)
	{
	case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
		g_pNesCpuPC = &g_pNesWRAM[PC_G&0x7FF];
		return;
	case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
		if(g_pNesSRAMBank != NULL)
		{
			g_pNesCpuPC = &g_pNesSRAMBank[PC_G&0x1FFF];
			return;
		}
		break;
	case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[0][PC_G&0x1FFF];
		return;
	case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[1][PC_G&0x1FFF];
		return;
	case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[2][PC_G&0x1FFF];
		return;
	case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[3][PC_G&0x1FFF];
		return;
	}
	g_pNesEmuBuf->bError = 1;
}

/** @brief Update PC Pointer */
u8* nesCpuUpdatePC()
{
	switch(PC_G >> 13)
	{
	case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
		g_pNesCpuPC = &g_pNesWRAM[PC_G&0x7FF];
		return g_pNesCpuPC;
	case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
		if(g_pNesSRAMBank != NULL)
		{
			g_pNesCpuPC = &g_pNesSRAMBank[PC_G&0x1FFF];
			return g_pNesCpuPC;
		}
		break;
	case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[0][PC_G&0x1FFF];
		return g_pNesCpuPC;
	case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[1][PC_G&0x1FFF];
		return g_pNesCpuPC;
	case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[2][PC_G&0x1FFF];
		return g_pNesCpuPC;
	case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[3][PC_G&0x1FFF];
		return g_pNesCpuPC;
	}
	g_pNesEmuBuf->bError = 1;
	return g_pNesCpuPC;
}

/** @brief Reset CPU */
void nesCpuReset()
{
	A_G = 0x00;
	X = 0x00;
	Y = 0x00;
	S = 0xFF;
	P_G = NES_CPU_UFLAG | NES_CPU_ZFLAG | NES_CPU_IFLAG;
	PC_G = *((u16*)&g_pNesPRGBank[3][0x1FFC]);
	nesCpuUpdatePC_G();

	g_nNesCpuIRQFlag = 0;
	g_nNesCpuNMIFlag = 0;
	g_nNesCpuRESETFlag = 0;
	g_nNesCpuTicks = 0;
	g_nNesCpuEventTicks = 0;
}

/** @brief Resume CPU */
void nesCpuResume()
{
	nesCpuUpdatePC_G();
}

/** @brief Check Indexing Crosses a Page Boundary */
u16 nesCpuCheckCross(u16 nValue, u8 nReg, s32 *tick)
{
	u16 nAddr = nReg + nValue;
	if((nAddr^nValue)&0x100)
		(*tick)++;
	return nAddr;
}


/** @brief CPU Patch */
//return 0, normal  LB_NES_CPU_OPCODE
//return 1, go to  LB_NES_CPU_GETOPCODE
u8 nesCpuPatch()
{
	trlSEmuShellPatch *pPatch;
	u8 nopcode;
	u32 nAddress,nID;
	int i;

	nopcode = 0xEA;
	nAddress = g_pNesCpuPC - (u8*)g_pNesEmuBuf->pRomBuf;
		pPatch = g_pNesEmuBuf->pPatchData;
		for(nID = 0; nID < g_pNesEmuBuf->nPatchCount; ++nID, ++pPatch)
		{
			u32 nFind;
			nFind = 0;
			if(pPatch->sData.sA.nMemAddress != 0xFFFFFFFF)
			{
				if(pPatch->sData.sA.nMemAddress == PC_G)
					nFind = 1;
			}
			else
			{
				if(pPatch->sData.sA.nAddress == nAddress)
					nFind = 1;
			}
			if(nFind && pPatch->sData.sA.nConditionType != 0xFFFFFFFF)
			{
				if(pPatch->sData.sA.nConditionType == 0) //MemCheck
				{
					for(i = 0 ; i < pPatch->sData.sA.nConditionValueA/2 ; i++)
					{
						u16 addr,cond,value;
						addr  = pPatch->pConditionValueA[i*2] + (pPatch->pConditionValueA[i*2 + 1]<<8);
						cond  = pPatch->pConditionValueB[i*2] + (pPatch->pConditionValueB[i*2 + 1]<<8);
						value = pPatch->pConditionValueC[i*2] + (pPatch->pConditionValueC[i*2 + 1]<<8);
						if( 
							(cond == 0x0000 && !(nesMemRead8(addr) == value)) ||
							(cond == 0x0001 && !(nesMemRead8(addr) >  value)) ||
							(cond == 0x0002 && !(nesMemRead8(addr) <  value)) ||
							(cond == 0x0003 && !(nesMemRead8(addr) >= value)) ||
							(cond == 0x0004 && !(nesMemRead8(addr) <= value)) ||
							(cond == 0x0005 && !(nesMemRead8(addr) != value))
						)
						{
							nFind = 0;
							nopcode = (u8)pPatch->nOpcode;
							break;						
						}
					}
				}
				if(pPatch->sData.sA.nConditionType == 1) //VRAM Check rangelzhang add 2012/7/20
				{
					u16 begin_addr  = pPatch->pConditionValueA[0] + (pPatch->pConditionValueA[1]<<8);
					for(i = 0 ; i < pPatch->sData.sA.nConditionValueC ; i++)
					{
						if(pPatch->pConditionValueC[i]!=g_pNesVRAM[(begin_addr + i)&0x3FFF])
						{
							nFind = 0;
							nopcode = (u8)pPatch->nOpcode;
							break;						
						}
					}
				}
			}

			if(nFind)
			{
				nopcode = (u8)pPatch->nOpcode;
				#include "nesPatch.h"
				return nopcode;
			}
		}
		return nopcode;
}

/** @brief Run CPU */
void nesCpuRun()
{
	s32 nNesCpuTicks;
	u8 *pNesCpuPC,nNesCpuRegP;
	u16 nNesCpuRegPC;
	if(g_nNesCpuRESETFlag)
	{
		g_nNesCpuRESETFlag = 0;
		g_nNesCpuIRQFlag = 0;
		g_nNesCpuNMIFlag = 0;
		A_G = 0x00;
		X = 0x00;
		Y = 0x00;
		S = 0xFF;
		P_G = NES_CPU_UFLAG | NES_CPU_ZFLAG | NES_CPU_IFLAG;
		PC_G = *((u16*)&g_pNesPRGBank[3][0x1FFC]);
		nesCpuUpdatePC_G();
		SET_TICK_G(6);
	}
	else if(g_nNesCpuNMIFlag)
	{
		g_nNesCpuNMIFlag = 0;
		P_G &= ~NES_CPU_BFLAG;
		STACK_PUSHPC_G(0);
		STACK_PUSH(P_G);
		P_G |= NES_CPU_IFLAG;
		PC_G = *((u16*)&g_pNesPRGBank[3][0x1FFA]);
		nesCpuUpdatePC_G();
		SET_TICK_G(7);
	}
	else if(g_nNesCpuIRQFlag)
	{
		if( (P_G&NES_CPU_IFLAG) == 0)
		{
			P_G &= ~NES_CPU_BFLAG;
			STACK_PUSHPC_G(0);
			STACK_PUSH(P_G);
			P_G |= NES_CPU_IFLAG;
			PC_G = *((u16*)&g_pNesPRGBank[3][0x1FFE]);
			nesCpuUpdatePC_G();
			SET_TICK_G(7);
		}
	}

	pNesCpuPC = g_pNesCpuPC;
	nNesCpuTicks = g_nNesCpuTicks;
	nNesCpuRegP = g_nNesCpuRegP;
	nNesCpuRegPC = g_nNesCpuRegPC;

	while(nNesCpuTicks<g_nNesCpuEventTicks)
	{
		//trlTraceCPURUN_NES();
		#include "nesCPUOpcode.h"
		{
			if(g_nNesCpuTicks != nNesCpuTicks)
				g_nNesCpuTicks = nNesCpuTicks;
		}
	}
	g_nNesCpuRegP = nNesCpuRegP;
	g_nNesCpuRegPC = nNesCpuRegPC;
	g_pNesCpuPC = pNesCpuPC;
	g_nNesCpuTicks = nNesCpuTicks;

	g_nNesCpuTicks -= g_nNesCpuEventTicks;
}
