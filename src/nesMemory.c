/**
 * @file nesMemory.cpp
 * @author Chentian
 * @date 2010.06.24
 * @brief NES Emulate For CTR - Memory Map
 */
#include "nesMemory.h"
#include "nesGraphic.h"
#include "nesSound.h"
#include "nesCard.h"
#include "nesInput.h"

/** @name Macro Define */
//@{
//@}

/** @name Global Variable */
//@{
u32					g_nNesMemSaveData;							///< Memory Save Data Count
trlSEmuShellResume	g_sNesMemSaveData[NES_MEM_SAVEDATA_MAX];	///< Memory Save Data
//@}

/** @brief Initialize Memory */
void nesMemInit()
{
#if 0
	g_pNesWRAM = (u8*)trlMemAlloc(0x800);
	g_pNesVRAM = (u8*)trlMemAlloc(0x800);
	g_pNesSPRRAM = (u8*)trlMemAlloc(0x100);
	g_pNesPALRAM = (u8*)trlMemAlloc(0x20);
#else
	g_pNesWRAM = &g_pYosHeap[YOS_NESWRAM];
	g_pNesVRAM = &g_pYosHeap[YOS_NESVRAM];
	g_pNesSPRRAM = &g_pYosHeap[YOS_NESSPRRAM];
	g_pNesPALRAM = &g_pYosHeap[YOS_NESPALRAM];
#endif

	g_pNesROMHeader = (nesSROMHeader*)g_pNesEmuBuf->pRomBuf;

	if(g_pNesROMHeader->nPRGBanks)
	{
		g_pNesPRGROM = &((u8*)g_pNesEmuBuf->pRomBuf)[sizeof(nesSROMHeader)];
		g_nNesCardPRGBankMask = g_pNesROMHeader->nPRGBanks - 1;
	}
	else
	{
		//g_pNesPRGROM = (u8*)trlMemAlloc(0x8000);
		g_pNesPRGROM = &g_pYosHeap[YOS_PRGROM];
		g_nNesCardPRGBankMask = 0x03;
	}

	if(g_pNesROMHeader->nCHRBanks)
	{
		g_pNesCHRROM = g_pNesPRGROM + 0x2000 * g_pNesROMHeader->nPRGBanks;
		g_nNesCardCHRBankMask = g_pNesROMHeader->nCHRBanks * 8 - 1;
	}
	else
	{
		//modify by yuans: change 8K --> 16K
		//g_pNesCHRROM = (u8*)trlMemAlloc(0x2000);
		g_pNesCHRROM = &g_pYosHeap[YOS_CHRROM];
		//end of modify
		g_nNesCardCHRBankMask = 0x7;
	}

	// Save Data
	g_nNesMemSaveData = 0;
	trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesWRAM, 0x800, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesVRAM, 0x800, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesSPRRAM, 0x100, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesPALRAM, 0x20, 1, 0);
	if(g_pNesROMHeader->nCHRBanks == 0){
		//modify by yuans: change 8K --> 16K
		trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesCHRROM, 0x2000, 1, 0);
		//end of modify	
	}
	if(g_pNesROMHeader->nPRGBanks == 0)
		trlSEmuShellResumeSetData(&g_sNesMemSaveData[g_nNesMemSaveData++],g_pNesPRGROM, 0x8000, 1, 0);

	nesMemReset();
}

/** @brief Reset Memory */
void nesMemReset()
{
	{
		u8 wramvalue = 0;
		trlMemSet(g_pNesWRAM, wramvalue, 0x800);
	}
	trlMemSet(g_pNesVRAM, 0, 0x800);
	trlMemSet(g_pNesSPRRAM, 0, 0x100);
	trlMemSet(g_pNesPALRAM, 0, 0x20);
	if(!g_pNesROMHeader->nPRGBanks)
		trlMemSet(g_pNesPRGROM, 0, 0x8000);
	if(!g_pNesROMHeader->nCHRBanks)
		//modify by yuans: change 8K --> 16K
		trlMemSet(g_pNesCHRROM, 0, 0x2000);
		//endof modify
}

/** @brief Resume Memory */
void nesMemResume()
{
}

/** @brief Exit Memory */
void nesMemExit()
{
	trlMemFree(g_pNesWRAM);
	trlMemFree(g_pNesVRAM);
	trlMemFree(g_pNesSPRRAM);
	trlMemFree(g_pNesPALRAM);
	if(!g_pNesROMHeader->nPRGBanks)
		trlMemFree(g_pNesPRGROM);
	if(!g_pNesROMHeader->nCHRBanks)
		trlMemFree(g_pNesCHRROM);
}

/** @brief Read Data From Memory Map - 8 Bits */
u8 nesMemRead8(u16 nAddr)
{
	switch(nAddr >> 13)
	{
	case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
		return g_pNesWRAM[nAddr&0x7FF];
	case 0x1:				// 2000h-2007h   Internal PPU Registers (mirrored to 2008h-3FFFh)
		return nesGrpRegRead(nAddr&0x7);
	case 0x2:		
		if(nAddr<0x4018)	// 4000h-4017h   Internal APU Registers
		{
			switch(nAddr)
			{
			case 0x4015:		// 4015h - DMC/IRQ/length counter status
				return ((( SoundE.interrupt ) << 7) | (( SoundE.activity ) << 4) | (( SoundD.activity ) << 3) | (( SoundC.activity ) << 2) | (( SoundB.activity ) << 1) | (( SoundA.activity ) << 0));
			case 0x4016:		// 4016h - Joypad #1/3
				return nesInputRegisterRead(0) | 0x40 | g_nNesInputMic;
			case 0x4017:		// 4017h - Joypad #2/4
				return nesInputRegisterRead(1);
			default:
				return 0x00;
			}
		}
		else if(nesCardRegisterRead)	// 4018h-5FFFh   Cartridge Expansion Area almost 8K
			return nesCardRegisterRead(nAddr);
		return 0xFF;
	case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
		if(g_nNesCardSRAMEnable==1)
			return g_pNesSRAMBank[nAddr&0x1FFF];
		else
			return 0xFF;
	case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
		return g_pNesPRGBank[0][nAddr&0x1FFF];
	case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
		return g_pNesPRGBank[1][nAddr&0x1FFF];
	case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
		return g_pNesPRGBank[2][nAddr&0x1FFF];
	case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
		return g_pNesPRGBank[3][nAddr&0x1FFF];
	}
	return 0xFF;
}

/** @brief Read Data From Memory Map - 16 Bits */
u16 nesMemRead16(u16 nAddr)
{
	switch(nAddr >> 13)
	{
	case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
		return *((u16*)&g_pNesWRAM[nAddr&0x7FF]);
	case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
		if(g_nNesCardSRAMEnable==1)
			return *((u16*)&g_pNesSRAMBank[nAddr&0x1FFF]);
		else
			return 0xFFFF;
	case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
		return *((u16*)&g_pNesPRGBank[0][nAddr&0x1FFF]);
	case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
		return *((u16*)&g_pNesPRGBank[1][nAddr&0x1FFF]);
	case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
		return *((u16*)&g_pNesPRGBank[2][nAddr&0x1FFF]);
	case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
		return *((u16*)&g_pNesPRGBank[3][nAddr&0x1FFF]);
	}
	return 0xFFFF;
}

/** @brief Direct Write Data to PPU Memory Map - 8 Bits */
void nesPpuMemDirectWrite8(u16 nAddr, u8 nValue)
{
	g_pNesVRAM[nAddr&0x3FFF] = nValue;
}

/** @brief Write Data to Memory Map - 8 Bits */
void nesMemWrite8(u16 nAddr, u8 nValue)
{
	//trlTraceMemWrite(nAddr, nValue);
	switch(nAddr >> 13)
	{
	case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
		g_pNesWRAM[nAddr&0x7FF] = nValue;
		break;
	case 0x1:				// 2000h-2007h   Internal PPU Registers (mirrored to 2008h-3FFFh)
		nesGrpRegWrite(nAddr&0x7, nValue);
		break;
	case 0x2:
		if(nAddr<0x4018)	// 4000h-4017h   Internal APU Registers
		{
			switch(nAddr)
			{	
			case 0x4014:		// 4014h - SPR-RAM DMA Register
				{
					u16 nDestAddr = nValue * 0x100;
					u8* pAddr = NULL;
					switch(nDestAddr >> 13)
					{
					case 0x0:				// 0000h-07FFh   Internal 2K Work RAM (mirrored to 800h-1FFFh)
						pAddr = g_pNesWRAM + (nDestAddr&0x7FF);
						break;
					case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
						if(g_nNesCardSRAMEnable==1)
							pAddr = g_pNesSRAMBank + (nDestAddr&0x1FFF);
						break;
					case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
						pAddr = g_pNesPRGBank[0] + (nDestAddr&0x1FFF);
						break;
					case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
						pAddr = g_pNesPRGBank[1] + (nDestAddr&0x1FFF);
						break;
					case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
						pAddr = g_pNesPRGBank[2] + (nDestAddr&0x1FFF);
						break;
					case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
						pAddr = g_pNesPRGBank[3] + (nDestAddr&0x1FFF);
						break;
					}
					if(pAddr)
					{
						trlMemCopy(g_pNesSPRRAM, pAddr, 0x100);
						g_bNesGrpSPRChange = 1;
						g_nNesCpuTicks += 512;
					}
				}
				break;	
			case 0x4016:		// 4016h - Joypad Output Register
				g_nNesInputReg = nValue;
				nesInputRegisterWrite();
				break;
			default:
				nesSndRegWrite(nAddr - 0x4000, nValue);
			}
		}
		else if(nesCardRegisterWrite)	// 4018h-5FFFh   Cartridge Expansion Area almost 8K
			nesCardRegisterWrite(nAddr, nValue);
		break;
	case 0x3:				// 6000h-7FFFh   Cartridge SRAM Area 8K
		switch(g_nNesCardSRAMEnable)
		{
		case 1:
			g_pNesSRAMBank[nAddr&0x1FFF] = nValue;
			if(g_pNesROMHeader->nBattery)
				g_pNesEmuBuf->nSaveUpdate |= 1;
			break;
		case 2:
			nesCardRegister(nAddr, nValue);
			break;
		}
		break;
	default:				// 8000h-FFFFh   Cartridge Register Area 32K
		if(nesCardRegister)
			nesCardRegister(nAddr, nValue);
		break;
	}
}
