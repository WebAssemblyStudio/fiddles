/**
 * @file nesCard.cpp
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Cartridge
 */
#include "nesCard.h"
#include "nesMemory.h"
#include "nesSound.h"
#include "nesGraphic.h"
#include "nesCPU.h"

/** @name Macro Define */
//@{
#define NES_CARD_DISKSYSTEM_CYCLE		64								///< Disk System I/O Clock Cycle
#define NES_CARD_DISKSYSTEM_DISKSIZE	65500							///< Disk System Disk Size
#define NES_CARD_DISKSYSTEM_SIDESIZE	0x10000							///< Disk System Side Size
#define NES_CARD_DISKSYSTEM_BIOSSIZE	0x2000							///< Disk System Bios Size
#define NES_CARD_DISKSYSTEM_SAVEMAX		8								///< Disk System Save Data Max Count
#define NES_CARD_DISKSYSTEM_DISKMAX		2								///< Disk System Disk Max Count
#define NES_CARD_DISKSYSTEM_SIDEMAX		NES_CARD_DISKSYSTEM_DISKMAX*2	///< Disk System Side Max Count
#define NES_CARD_DISKSYSTEM_LOADMAX		20								///< Disk System Load List Max Count
#define NES_CARD_DISKSYSTEM_FILEMAX		0x100							///< Disk System File Max Count
#define NES_CARD_BANKSIZE_PRG			0x2000							///< PRG Bank Size
#define NES_CARD_BANKSIZE_CHR			0x400							///< CHR Bank Size
#define NES_CARD_BANKSIZE_SRAM			0x2000							///< SRAM Bank Size
//@}

/** @name Global Variable */
//@{
void				(*nesCardRegister)(u16, u8);						///< Game Card RAM Register Function Pointer
void				(*nesCardRegisterWrite)(u16, u8);					///< Game Card RAM Register Expansion Write Function Pointer
u8					(*nesCardRegisterRead)(u16);						///< Game Card RAM Register Expansion Read Function Pointer
void				(*nesCardRegisterLatch)(u32);						///< Game Card RAM Register Latch Function Pointer
void				(*nesCardUpdateIRQ)();								///< Game Card RAM Update IRQ Function Pointer
s32					g_nNesCardIRQTicks;									///< IRQ Ticks
u32					g_nNesCardIRQEnable;								///< IRQ Enable Flag
s32					g_nNesCardIRQDiskTicks;								///< IRQ Ticks for Disk
u32					g_nNesCardIRQDiskEnable;							///< IRQ Enable Flag for Disk
u32					g_nNesCardLatch[2];									///< Latch Value
u32					g_nNesCardSRAMEnable;								///< SRAM Enable
u32					g_nNesCardPRGBankMask;								///< PRG-ROM Bank Mask
u32					g_nNesCardCHRBankMask;								///< CHR-ROM Bank Mask
u32					g_nNesCardSaveData;									///< Card Save Data Count
trlSEmuShellResume	g_sNesCardSaveData[NES_CARD_SAVEDATA_MAX];			///< Card Save Data
//@}

/** @brief Update PC Pointer */
void nesCardUpdatePC()
{
	switch(g_nNesCpuRegPC >> 13)
	{
	case 0x4:				// 8000h-9FFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[0][g_nNesCpuRegPC&0x1FFF];
		break;
	case 0x5:				// A000h-BFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[1][g_nNesCpuRegPC&0x1FFF];
		break;
	case 0x6:				// C000h-DFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[2][g_nNesCpuRegPC&0x1FFF];
		break;
	case 0x7:				// E000h-FFFFh   Cartridge PRG-ROM Area 8K
		g_pNesCpuPC = &g_pNesPRGBank[3][g_nNesCpuRegPC&0x1FFF];
		break;
	}
}

/** @brief Switch 8K PRG Bank */
void nesCardRegPRGBank8(u32 nBank, u32 nStartBank)
{
	nBank &= g_nNesCardPRGBankMask;
	g_pNesPRGBank[nStartBank] = g_pNesPRGROM + nBank * NES_CARD_BANKSIZE_PRG;
}

/** @brief Switch 16K PRG Bank */
void nesCardRegPRGBank16(u32 nBank, u32 nStartBank)
{
	nBank &= g_nNesCardPRGBankMask;
	g_pNesPRGBank[nStartBank] = g_pNesPRGROM + nBank * NES_CARD_BANKSIZE_PRG;
	g_pNesPRGBank[nStartBank+1] = g_pNesPRGBank[nStartBank] + NES_CARD_BANKSIZE_PRG;
}

/** @brief Switch 32K PRG Bank */
void nesCardRegPRGBank32(u32 nBank)
{
	nBank &= g_nNesCardPRGBankMask;
	g_pNesPRGBank[0] = g_pNesPRGROM + nBank * NES_CARD_BANKSIZE_PRG;
	g_pNesPRGBank[1] = g_pNesPRGBank[0] + NES_CARD_BANKSIZE_PRG;
	g_pNesPRGBank[2] = g_pNesPRGBank[1] + NES_CARD_BANKSIZE_PRG;
	g_pNesPRGBank[3] = g_pNesPRGBank[2] + NES_CARD_BANKSIZE_PRG;
}

/** @brief Switch 1K CHR Bank */
void nesCardRegCHRBank1(u32 nBank, u32 nStartBank)
{
	g_bNesGrpSPRChange |= 2;
	nBank &= g_nNesCardCHRBankMask;
	g_pNesCHRBank[nStartBank] = g_pNesCHRROM + nBank * NES_CARD_BANKSIZE_CHR;
}

/** @brief Switch 2K CHR Bank */
void nesCardRegCHRBank2(u32 nBank, u32 nStartBank)
{
	g_bNesGrpSPRChange |= 2;
	nBank &= g_nNesCardCHRBankMask;
	g_pNesCHRBank[nStartBank] = g_pNesCHRROM + nBank * NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[nStartBank+1] = g_pNesCHRBank[nStartBank] + NES_CARD_BANKSIZE_CHR;
}

/** @brief Switch 4K CHR Bank */
void nesCardRegCHRBank4(u32 nBank, u32 nStartBank)
{
	g_bNesGrpSPRChange |= 2;
	nBank &= g_nNesCardCHRBankMask;
	g_pNesCHRBank[nStartBank] = g_pNesCHRROM + nBank * NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[nStartBank+1] = g_pNesCHRBank[nStartBank] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[nStartBank+2] = g_pNesCHRBank[nStartBank] + NES_CARD_BANKSIZE_CHR * 2;
	g_pNesCHRBank[nStartBank+3] = g_pNesCHRBank[nStartBank] + NES_CARD_BANKSIZE_CHR * 3;
}

/** @brief Switch 8K CHR Bank */
void nesCardRegCHRBank8(u32 nBank)
{
	g_bNesGrpSPRChange |= 2;
	nBank &= g_nNesCardCHRBankMask;
	g_pNesCHRBank[0] = g_pNesCHRROM + nBank * NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[1] = g_pNesCHRBank[0] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[2] = g_pNesCHRBank[1] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[3] = g_pNesCHRBank[2] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[4] = g_pNesCHRBank[3] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[5] = g_pNesCHRBank[4] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[6] = g_pNesCHRBank[5] + NES_CARD_BANKSIZE_CHR;
	g_pNesCHRBank[7] = g_pNesCHRBank[6] + NES_CARD_BANKSIZE_CHR;
}

#define	SET_PPU_VROM_BANK(n)	(g_nPPUCHRRAM &= ~(0x1<<(n)))
#define	SET_PPU_VRAM_BANK(n)	(g_nPPUCHRRAM |= 0x1<<(n))

/** @brief Switch 8K SRAM Bank */
void nesCardRegSRAMBank(u32 nBank)
{
	g_pNesSRAMBank = g_pNesSRAM + nBank * NES_CARD_BANKSIZE_SRAM;
}

/** @name Mapper 1 - MMC-1 */
//@{
/**
 * @struct nesSCardRegMapper1
 * @brief MMC-1 Card Register
 */
typedef struct
{
	u32		nShift;				///< 5bit Shift Register
	u32		nData;				///< Data
	u32		nPRGMode;			///< PRG Switching Mode
	u32		nCHRMode;			///< CHR Switching Mode
	u32		nPRGBank;			///< PRG Bank
	u32		nCHR0Bank;			///< CHR0 Bank
	u32		nCHR1Bank;			///< CHR1 Bank
	u32		nSRAMBank;			///< SRAM Bank
	u32		nPRGBankExt;		///< Extern PRG Bank
	u32		nPRGBankFlag;		///< Extern PRG Bank Mode
}nesSCardRegMapper1;
nesSCardRegMapper1 g_sNesCardRegMapper1;

/** @brief Update PRG Bank - MMC-1 */
void nesCardRegUpdatePRGBankMapper1()
{
	switch(g_sNesCardRegMapper1.nPRGMode)
	{
	case 0:		// Switchable 32K Area at 8000h-FFFFh (via Register 3)
	case 1:
		nesCardRegPRGBank32(g_sNesCardRegMapper1.nPRGBank + g_sNesCardRegMapper1.nPRGBankExt);
		break;
	case 2:		// Switchable 16K Area at C000h-FFFFh (via Register 3) And Fixed  16K Area at 8000h-BFFFh (always 1st 16K)
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_sNesCardRegMapper1.nPRGBank + g_sNesCardRegMapper1.nPRGBankExt, 2);
		break;
	case 3:		// Switchable 16K Area at 8000h-BFFFh (via Register 3) And Fixed  16K Area at C000h-FFFFh (always last 16K)
		nesCardRegPRGBank16(g_sNesCardRegMapper1.nPRGBank + g_sNesCardRegMapper1.nPRGBankExt, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		break;
	}
}

/** @brief Write Data to Card Register - MMC-1 */
void nesCardRegMapper1(u16 nAddr, u8 nValue)
{
	if(nValue&0x80)
	{
		g_sNesCardRegMapper1.nShift = 0;
		g_sNesCardRegMapper1.nData = 0;
		return;
	}
	g_sNesCardRegMapper1.nData += (nValue&0x1) << g_sNesCardRegMapper1.nShift;
	++g_sNesCardRegMapper1.nShift;
	if(g_sNesCardRegMapper1.nShift==5)
	{
		switch(nAddr >> 13)
		{
		case 0x4:	// 8000h-9FFFh   Register 0 - Configuration Register
			switch(g_sNesCardRegMapper1.nData&0x3)
			{
			case 0:		// Single-Screen BLK0
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			case 1:		// Single-Screen BLK1
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			case 2:		// Two-Screen Vertical Mirroring
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
				break;
			case 3:		// Two-Screen Horizontal Mirroring
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
				break;
			}
			g_sNesCardRegMapper1.nPRGMode = (g_sNesCardRegMapper1.nData>>2) & 0x3;
			if(g_pNesROMHeader->nPRGBanks == 128)	// 1024K PRG ROM
			{
				g_sNesCardRegMapper1.nPRGBankFlag = (g_sNesCardRegMapper1.nPRGBankFlag & 0x3) + (g_sNesCardRegMapper1.nData & 0x10);
				if(g_sNesCardRegMapper1.nPRGBankFlag & 0x10)
					g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nPRGBankFlag & 0x3) * 32;
				else
					g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nPRGBankFlag & 0x1) * 64;
			}
			else
			{
				g_sNesCardRegMapper1.nCHRMode = (g_sNesCardRegMapper1.nData>>4) & 0x1;
				if(g_sNesCardRegMapper1.nCHRMode)	// Swap 4K of VROM at PPU 0000h and 1000h
				{
					nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR0Bank, 0);
					nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR1Bank, 4);
					g_nPPUCHRRAM = 0;
				}
				else							// Swap 8K of VROM at PPU 0000h
				{
					if(g_pNesROMHeader->nCHRBanks == 0){
						nesCardRegCHRBank8(0);
						g_nPPUCHRRAM = 0xFF;
					}
					else{
						nesCardRegCHRBank8(g_sNesCardRegMapper1.nCHR0Bank);
						g_nPPUCHRRAM = 0;
					}
				}
				
			}
			nesCardRegUpdatePRGBankMapper1();
			break;
		case 0x5:	// A000h-BFFFh   Register 1
			switch(g_pNesROMHeader->nPRGBanks)
			{
			case 64:	// 512K PRG ROM
				g_sNesCardRegMapper1.nCHR0Bank = (g_sNesCardRegMapper1.nData & 0x0F) * 4;
				g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nData >> 4) * 32;
				nesCardRegUpdatePRGBankMapper1();
				break;
			case 128:	// 1024K PRG ROM
				g_sNesCardRegMapper1.nCHR0Bank = (g_sNesCardRegMapper1.nData & 0x0F) * 4;
				g_sNesCardRegMapper1.nPRGBankFlag = (g_sNesCardRegMapper1.nPRGBankFlag & 0x12) + (g_sNesCardRegMapper1.nData >> 4);
				if(g_sNesCardRegMapper1.nPRGBankFlag & 0x10)
					g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nPRGBankFlag & 0x3) * 32;
				else
					g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nPRGBankFlag & 0x1) * 64;
				nesCardRegUpdatePRGBankMapper1();
				break;
			default:
				g_sNesCardRegMapper1.nCHR0Bank = g_sNesCardRegMapper1.nData * 4;
			}
			if(g_sNesCardRegMapper1.nCHRMode)	// Swap 4K of VROM at PPU 0000h
			{
				nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR0Bank, 0);
				g_nPPUCHRRAM &= 0xF0;
			}
			else								// Swap 8K of VROM at PPU 0000h
			{
				if(g_pNesROMHeader->nCHRBanks == 0){
					nesCardRegCHRBank8(0);
					g_nPPUCHRRAM = 0xFF;
				}
				else{
					nesCardRegCHRBank8(g_sNesCardRegMapper1.nCHR0Bank);
					g_nPPUCHRRAM = 0;
				}
				
			}
			break;
		case 0x6:	// C000h-DFFFh   Register 2
			if(g_pNesROMHeader->nPRGBanks == 128)	// 1024K PRG ROM
			{
				g_sNesCardRegMapper1.nCHR1Bank = (g_sNesCardRegMapper1.nData & 0x0F) * 4;
				g_sNesCardRegMapper1.nPRGBankFlag = (g_sNesCardRegMapper1.nPRGBankFlag & 0x11) + ((g_sNesCardRegMapper1.nData >> 3) & 0x2);
				if(g_sNesCardRegMapper1.nPRGBankFlag & 0x10)
					g_sNesCardRegMapper1.nPRGBankExt = (g_sNesCardRegMapper1.nPRGBankFlag & 0x3) * 32;
				nesCardRegUpdatePRGBankMapper1();
			}
			else
				g_sNesCardRegMapper1.nCHR1Bank = g_sNesCardRegMapper1.nData * 4;
			if(g_sNesCardRegMapper1.nCHRMode)	// Swap 4K of VROM at PPU 1000h
			{
				nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR1Bank, 4);
				g_nPPUCHRRAM &= 0x0F;
			}
			break;
		case 0x7:	// E000h-FFFFh   Register 3
			g_sNesCardRegMapper1.nPRGBank = (g_sNesCardRegMapper1.nData & 0xF) << 1;
			nesCardRegUpdatePRGBankMapper1();
			break;
		}
		g_sNesCardRegMapper1.nShift = 0;
		g_sNesCardRegMapper1.nData = 0;
	}
}
//@}

/** @name Mapper 2 - MMC-2 */
//@{
/**
 * @struct nesSCardRegMapper2
 * @brief MMC-2 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank[2][2];		///< CHR Bank
}nesSCardRegMapper2;
nesSCardRegMapper2 g_sNesCardRegMapper2;

/** @brief Write Data to Card Register - MMC-2 */
void nesCardRegMapper2(u16 nAddr, u8 nValue)
{
	switch(nAddr >> 12)
	{
	case 0xA:	// A000h-AFFFh  Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper2.nPRGBank = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper2.nPRGBank, 0);
		break;
	case 0xB:	// B000h-BFFFh  Select 4K VROM bank at PPU 0000h-0FFFh (used when latch0=FDh)
		g_sNesCardRegMapper2.nCHRBank[0][1] = nValue*4;
		if(g_nNesCardLatch[0] == 1)
			nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[0][1], 0);
		break;
	case 0xC:	// C000h-CFFFh  Select 4K VROM bank at PPU 0000h-0FFFh (used when latch0=FEh)
		g_sNesCardRegMapper2.nCHRBank[0][0] = nValue*4;
		if(g_nNesCardLatch[0] == 0)
			nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[0][0], 0);
		break;
	case 0xD:	// D000h-DFFFh  Select 4K VROM bank at PPU 1000h-1FFFh (used when latch1=FDh)
		g_sNesCardRegMapper2.nCHRBank[1][1] = nValue*4;
		if(g_nNesCardLatch[1] == 1)
			nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[1][1], 4);
		break;
	case 0xE:	// E000h-EFFFh  Select 4K VROM bank at PPU 1000h-1FFFh (used when latch1=FEh)
		g_sNesCardRegMapper2.nCHRBank[1][0] = nValue*4;
		if(g_nNesCardLatch[1] == 0)
			nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[1][0], 4);
		break;
	case 0xF:	// F000h-FFFFh  Mirroring Select (Bit0: 0=Vertical, 1=Horizontal mirroring)
		if(nValue&0x1)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	}
}

/** @brief Update Latch to Card Register - MMC-2 */
void nesCardRegMapper2Latch(u32 nIndex)
{
	nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[nIndex][g_nNesCardLatch[nIndex]], nIndex*4);
}
//@}

/** @name Mapper 3 - MMC-3 */
//@{
/**
 * @struct nesSCardRegMapper3
 * @brief MMC-3 Card Register
 */
typedef struct
{
	u32		nBankMode;			///< Bank Command Number
	u32		nPRGArea;			///< PRG Address Select
	u32		nCHRArea;			///< CHR Address Select
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	s32		nIRQCount;			///< IRQ Count Value
//	u32		nIRQReload;			///< IRQ Reload Flag
	u16		irq_preset;
	u16		irq_preset_vbl;
}nesSCardRegMapper3;
nesSCardRegMapper3 g_sNesCardRegMapper3;

/** @brief Write Data to Card Register - MMC-3 */
void nesCardRegMapper3(u16 nAddr, u8 nValue)
{
	u32 old_CHR;
	switch(nAddr & 0xE001)
	{
	case 0x8000:
		g_sNesCardRegMapper3.nBankMode = nValue & 0x7;
		g_sNesCardRegMapper3.nPRGArea = (nValue>>5) & 2;

		old_CHR=g_sNesCardRegMapper3.nCHRArea;
		g_sNesCardRegMapper3.nCHRArea = (nValue>>7) * 4;

		if(old_CHR!=g_sNesCardRegMapper3.nCHRArea){
			u32 oldCHRBank[8];
			int i;
			for(i = 0 ; i < 8 ; i++)
				oldCHRBank[i]=g_sNesCardRegMapper3.nCHRBank[i];

			g_sNesCardRegMapper3.nCHRBank[0]=oldCHRBank[4];
			g_sNesCardRegMapper3.nCHRBank[1]=oldCHRBank[5];
			g_sNesCardRegMapper3.nCHRBank[2]=oldCHRBank[6];
			g_sNesCardRegMapper3.nCHRBank[3]=oldCHRBank[7];
			g_sNesCardRegMapper3.nCHRBank[4]=oldCHRBank[0];
			g_sNesCardRegMapper3.nCHRBank[5]=oldCHRBank[1];
			g_sNesCardRegMapper3.nCHRBank[6]=oldCHRBank[2];
			g_sNesCardRegMapper3.nCHRBank[7]=oldCHRBank[3];

			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[0],0);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[1],1);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[2],2);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[3],3);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[4],4);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[5],5);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[6],6);
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[7],7);
		}
		nesCardRegPRGBank8(g_sNesCardRegMapper3.nPRGBank[0], g_sNesCardRegMapper3.nPRGArea);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks-2, 2-g_sNesCardRegMapper3.nPRGArea);
		break;
	case 0x8001:	// Data Register    (Indexed via Port 8000h)
		switch(g_sNesCardRegMapper3.nBankMode)
		{
		case 0:			// Select 2x1K VROM at PPU 0000h-07FFh (or 1000h-17FFh, if Bit7=1)
			nValue&=0xFE;
			g_sNesCardRegMapper3.nCHRBank[g_sNesCardRegMapper3.nCHRArea] = nValue;
			g_sNesCardRegMapper3.nCHRBank[g_sNesCardRegMapper3.nCHRArea+1] = nValue+1;
			nesCardRegCHRBank2(nValue, g_sNesCardRegMapper3.nCHRArea);
			/* MMC3 have VROM or VRAM. On carts with VROM, the first 8K of VROM is swapped into PPU $0000 on reset.
			On carts without VROM, as always, there is 8K of VRAM at PPU $0000.
			*/
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(g_sNesCardRegMapper3.nCHRArea);
				SET_PPU_VROM_BANK(g_sNesCardRegMapper3.nCHRArea+1);
			}
			break;
		case 1:			// Select 2x1K VROM at PPU 0800h-0FFFh (or 1800h-1FFFh, if Bit7=1)
			nValue&=0xFE;
			g_sNesCardRegMapper3.nCHRBank[g_sNesCardRegMapper3.nCHRArea+2] = nValue;
			g_sNesCardRegMapper3.nCHRBank[g_sNesCardRegMapper3.nCHRArea+3] = nValue+1;
			nesCardRegCHRBank2(nValue, g_sNesCardRegMapper3.nCHRArea+2);
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(g_sNesCardRegMapper3.nCHRArea+2);
				SET_PPU_VROM_BANK(g_sNesCardRegMapper3.nCHRArea+3);
			}
			break;
		case 2:			// Select 1K VROM at PPU 1000h-13FFh   (or 0000h-03FFh, if Bit7=1)
			g_sNesCardRegMapper3.nCHRBank[4-g_sNesCardRegMapper3.nCHRArea] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper3.nCHRArea);
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(4-g_sNesCardRegMapper3.nCHRArea);
			}
			break;
		case 3:			// Select 1K VROM at PPU 1400h-17FFh   (or 0400h-07FFh, if Bit7=1)
			g_sNesCardRegMapper3.nCHRBank[4-g_sNesCardRegMapper3.nCHRArea+1] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper3.nCHRArea+1);
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(4-g_sNesCardRegMapper3.nCHRArea+1);
			}
			break;
		case 4:			// Select 1K VROM at PPU 1800h-1BFFh   (or 0800h-0BFFh, if Bit7=1)
			g_sNesCardRegMapper3.nCHRBank[4-g_sNesCardRegMapper3.nCHRArea+2] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper3.nCHRArea+2);
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(4-g_sNesCardRegMapper3.nCHRArea+2);
			}
			break;
		case 5:			// Select 1K VROM at PPU 1C00h-1FFFh   (or 0C00h-0FFFh, if Bit7=1)
			g_sNesCardRegMapper3.nCHRBank[4-g_sNesCardRegMapper3.nCHRArea+3] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper3.nCHRArea+3);
			if(g_pNesROMHeader->nCHRBanks){
				SET_PPU_VROM_BANK(4-g_sNesCardRegMapper3.nCHRArea+3);
			}
			break;
		case 6:			// Select 8K ROM at 8000h-9FFFh (or C000h-DFFFh, if Bit6=1)
			g_sNesCardRegMapper3.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper3.nPRGBank[0], g_sNesCardRegMapper3.nPRGArea);
			break;
		case 7:			// Select 8K ROM at A000h-BFFFh
			g_sNesCardRegMapper3.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper3.nPRGBank[1], 1);
			break;
		}
		break;
	case 0xA000:	// Mirroring Select
		if(nValue&0x1)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	case 0xA001:	// SaveRAM Toggle   (Bit7: 0=Disable 6000h-7FFFh, 1=Enable 6000h-7FFFh)
		//g_nNesCardSRAMEnable = (nValue & 0x80) >> 7;
		break;
	case 0xC000:	// IRQ Counter Register - The IRQ countdown value is stored here.
		//latch...
		g_sNesCardRegMapper3.nIRQInit = nValue;
		break;
	case 0xC001:	// IRQ Latch Register - A temporary value is stored here.
		if( g_nNesGrpLines < 240) {
			g_sNesCardRegMapper3.nIRQCount |= 0x80;
			g_sNesCardRegMapper3.irq_preset = 0xFF;
		} else {
			g_sNesCardRegMapper3.nIRQCount |= 0x80;
			g_sNesCardRegMapper3.irq_preset_vbl = 0xFF;
			g_sNesCardRegMapper3.irq_preset = 0;
		}
		break;
	case 0xE000:	// IRQ Control Register 0 - Any value written here will disable IRQ's and copy the latch register to the actual IRQ counter register.		
		g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag = 0;
		//g_sNesCardRegMapper3.nIRQCount = g_sNesCardRegMapper3.nIRQInit+1;
		break;
	case 0xE001:	// IRQ Control Register 1 - Any value written here will enable IRQ's.
		g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINE;
		g_nNesCpuIRQFlag = 0;
		break;
	}
}

/** @brief Update Card IRQ - MMC-3 */
void nesCardUpdateIRQMapper3()
{
	//if(g_nNesGrpLines>=0 && g_nNesGrpLines<=239 && g_nNesGrpEnable){
			if( g_sNesCardRegMapper3.irq_preset_vbl ) {
				g_sNesCardRegMapper3.nIRQCount = g_sNesCardRegMapper3.nIRQInit;
				g_sNesCardRegMapper3.irq_preset_vbl = 0;
			}

			if( g_sNesCardRegMapper3.irq_preset ) {
				g_sNesCardRegMapper3.nIRQCount = g_sNesCardRegMapper3.nIRQInit;
				g_sNesCardRegMapper3.irq_preset = 0;
			} else if(g_sNesCardRegMapper3.nIRQCount > 0 ) {
				g_sNesCardRegMapper3.nIRQCount--;
			}

			if( g_sNesCardRegMapper3.nIRQCount == 0 ) {
				if(g_nNesCardIRQEnable == NES_CARD_IRQ_SCANLINE){
					g_nNesCpuIRQFlag = 1;
				}
				g_sNesCardRegMapper3.irq_preset = 0xFF;
			}
	//}
}

/** @name Mapper 4 - MMC-4 */
//@{
/**
 * @struct nesSCardRegMapper4
 * @brief MMC-4 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank[2][2];		///< CHR Bank
}nesSCardRegMapper4;
nesSCardRegMapper4 g_sNesCardRegMapper4;

/** @brief Write Data to Card Register - MMC-4 */
void nesCardRegMapper4(u16 nAddr, u8 nValue)
{
	switch(nAddr >> 12)
	{
	case 0xA:	// A000h-AFFFh  Select 16K ROM bank at 8000h-BFFFh
		g_sNesCardRegMapper4.nPRGBank = nValue * 2;
		nesCardRegPRGBank16(g_sNesCardRegMapper4.nPRGBank, 0);
		break;
	case 0xB:	// B000h-BFFFh  Select 4K VROM bank at PPU 0000h-0FFFh (used when latch0=FDh)
		g_sNesCardRegMapper4.nCHRBank[0][1] = nValue*4;
		if(g_nNesCardLatch[0] == 1)
			nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[0][1], 0);
		break;
	case 0xC:	// C000h-CFFFh  Select 4K VROM bank at PPU 0000h-0FFFh (used when latch0=FEh)
		g_sNesCardRegMapper4.nCHRBank[0][0] = nValue*4;
		if(g_nNesCardLatch[0] == 0)
			nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[0][0], 0);
		break;
	case 0xD:	// D000h-DFFFh  Select 4K VROM bank at PPU 1000h-1FFFh (used when latch1=FDh)
		g_sNesCardRegMapper4.nCHRBank[1][1] = nValue*4;
		if(g_nNesCardLatch[1] == 1)
			nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[1][1], 4);
		break;
	case 0xE:	// E000h-EFFFh  Select 4K VROM bank at PPU 1000h-1FFFh (used when latch1=FEh)
		g_sNesCardRegMapper4.nCHRBank[1][0] = nValue*4;
		if(g_nNesCardLatch[1] == 0)
			nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[1][0], 4);
		break;
	case 0xF:	// F000h-FFFFh  Mirroring Select (Bit0: 0=Vertical, 1=Horizontal mirroring)
		if(nValue&0x1)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	}
}

/** @brief Update Latch to Card Register - MMC-4 */
void nesCardRegMapper4Latch(u32 nIndex)
{
	nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[nIndex][g_nNesCardLatch[nIndex]], nIndex*4);
}
//@}

/** @name Mapper 5 - MMC-5 */
//@{
/**
 * @struct nesSCardRegMapper5
 * @brief MMC-5 Card Register
 */
typedef struct
{
	u32		nPRGBankMode;				///< PRG Bank Mode
	u32		nCHRBankMode;				///< CHR Bank Mode
	u32		nRAMWriteProtect;			///< RAM Write Protect Key
	u32		nPRGBank[4];				///< PRG Bank
	u32		nCHRBank[12];				///< CHR Bank
	u32		nSRAMBank;					///< SRAM Bank
	u32		nNameTabSelect;				///< Name Table Select
	u32		nFillTileNumber;			///< Name Table Fill-Mode Tile Number
	u32		nFillPalNumber;				///< Name Table Fill-Mode Palette Number
	u32		nEXRAMMode;					///< EXRAM Mode Setting
	u32		nIRQCount;					///< IRQ Count Value
	u32		nMultiply[2];				///< Multiply Unit
}nesSCardRegMapper5;
nesSCardRegMapper5 g_sNesCardRegMapper5;
u8*		g_pNesCardFILLRAMMapper5 = NULL;///< Fill Mode VRAM
u8*		g_pNesCardEXRAMMapper5 = NULL;	///< Expand RAM

/** @brief Update SRAM Bank - MMC-5 */
void nesCardRegUpdateSRAMBankMapper5(u8 nValue)
{
	switch(g_pNesROMHeader->nSRAMBanks)
	{
	case 2:			// 16K (two 8K chips)
		g_sNesCardRegMapper5.nSRAMBank = (nValue >> 2) & 0x1;
		break;
	case 4:
		g_sNesCardRegMapper5.nSRAMBank = nValue & 0x3;
		break;
	default:
		return;
	}
	nesCardRegSRAMBank(g_sNesCardRegMapper5.nSRAMBank);
}

/** @brief Write Data to Card Register - MMC-5 */
void nesCardRegMapper5Write(u16 nAddr, u8 nValue)
{
	u32 n;

	if(nAddr>=0x5C00)// 0x5C00h-5FFFh  EXRAM (1K)
	{
		if(g_sNesCardRegMapper5.nEXRAMMode != 3)
			g_pNesCardEXRAMMapper5[nAddr - 0x5C00] = nValue;
		//switch(g_sNesCardRegMapper5.nEXRAMMode)
		//{
		//case 0:
		//case 1:
		//	if(g_pNesGrpReg2002->rVBlank)
		//		g_pNesCardEXRAMMapper5[nAddr - 0x5C00] = nValue;
		//	break;
		//case 2:
		//	g_pNesCardEXRAMMapper5[nAddr - 0x5C00] = nValue;
		//	break;
		//}
		return;
	}
	switch(nAddr)
	{
	case 0x5000:	// Sound Channel 1 Pulse Control
	case 0x5002:	// Sound Channel 1 Frequency LSB
	case 0x5003:	// Sound Channel 1 Frequency MSB
	case 0x5004:	// Sound Channel 2 Pulse Control
	case 0x5006:	// Sound Channel 2 Frequency LSB
	case 0x5007:	// Sound Channel 2 Frequency MSB
	case 0x5010:	// Sound Channel 3 Enable
	case 0x5011:	// Sound Channel 4 Synthetic Voice business channel 2
	case 0x5015:	// Sound Channel 1 and 2 Enable
		nesSndRegWriteCard(nAddr-0x5000, nValue);
		break;
	case 0x5100:	// PRG Bank Size (Mode for Port 5114h-5117h)
		g_sNesCardRegMapper5.nPRGBankMode = nValue & 0x3;
		nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[1], 1);
		nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[2], 2);
		nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[3], 3);
		break;
	case 0x5101:	// CHR Bank Size
		g_sNesCardRegMapper5.nCHRBankMode = nValue & 0x3;
		if(g_sNesCardRegMapper5.nCHRBankMode)
			g_nNesGrpPatternTabBG = 8;
		else
			g_nNesGrpPatternTabBG = g_pNesGrpReg2000->rPatternTabBG * 4;
		break;
	case 0x5102:	// RAM Write Protect Key 1
		if(nValue)
			g_sNesCardRegMapper5.nRAMWriteProtect = (g_sNesCardRegMapper5.nRAMWriteProtect & 0x01) + 0x02;
		else
			g_sNesCardRegMapper5.nRAMWriteProtect &= 0x01;
		break;
	case 0x5103:	// RAM Write Protect Key 2
		if(nValue)
			g_sNesCardRegMapper5.nRAMWriteProtect = (g_sNesCardRegMapper5.nRAMWriteProtect & 0x02) + 0x01;
		else
			g_sNesCardRegMapper5.nRAMWriteProtect &= 0x02;
		break;
	case 0x5104:	// EXRAM Mode Setting
		g_sNesCardRegMapper5.nEXRAMMode = nValue;
		if(g_sNesCardRegMapper5.nEXRAMMode == 1)
			nesGrpChangeRenderBG(NES_GRP_BG_MMC5);
		else
			nesGrpChangeRenderBG(NES_GRP_BG_NORMAL);
		break;
	case 0x5105:	// Name Table Select
		g_sNesCardRegMapper5.nNameTabSelect = nValue;
		for(n = 0 ; n < 4; n++)
		{
			switch((g_sNesCardRegMapper5.nNameTabSelect>>(n*2)) & 0x3)
			{
			case 0:		// BLK0
				g_pNesGrpNameTab[n] = g_pNesVRAM;
				break;
			case 1:		// BLK1
				g_pNesGrpNameTab[n] = g_pNesVRAM + 0x400;
				break;
			case 2:		// EXRAM
				g_pNesGrpNameTab[n] = g_pNesCardEXRAMMapper5;
				break;
			case 3:		// FILLMODE
				g_pNesGrpNameTab[n] = g_pNesCardFILLRAMMapper5;
				break;
			}
		}
		nesGrpChangeNameTabMap(NES_GRP_MAP_EXTEND);
		break;
	case 0x5106:	// Name Table Fill-Mode Tile Number
		g_sNesCardRegMapper5.nFillTileNumber = nValue;
		trlMemSet(g_pNesCardFILLRAMMapper5, g_sNesCardRegMapper5.nFillTileNumber, 0x3C0);
		break;
	case 0x5107:	// Name Table Fill-Mode Palette Number
		nValue &= 0x3;
		g_sNesCardRegMapper5.nFillPalNumber = nValue + (nValue<<2) + (nValue<<4) + (nValue<<6);
		trlMemSet(&g_pNesCardFILLRAMMapper5[0x3C0], g_sNesCardRegMapper5.nFillPalNumber, 0x40);
		break;
	case 0x5113:	// SRAM Bank Selection Registers
		nesCardRegUpdateSRAMBankMapper5(nValue);
		break;
	case 0x5114:	// PRG\SRAM Bank Selection Registers
		if(nValue&0x80)
		{
			if(g_sNesCardRegMapper5.nPRGBankMode == 3)
			{
				g_sNesCardRegMapper5.nPRGBank[0] = nValue & 0x7F;
				nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[0], 0);
			}
		}
		else
			nesCardRegUpdateSRAMBankMapper5(nValue);
		break;
	case 0x5115:	// PRG\SRAM Bank Selection Registers
		if(nValue&0x80)
		{
			switch(g_sNesCardRegMapper5.nPRGBankMode)
			{
			case 1:
			case 2:
				g_sNesCardRegMapper5.nPRGBank[0] = nValue & 0x7E;
				g_sNesCardRegMapper5.nPRGBank[1] = g_sNesCardRegMapper5.nPRGBank[0] + 1;
				nesCardRegPRGBank16(g_sNesCardRegMapper5.nPRGBank[0], 0);
				break;
			case 3:
				g_sNesCardRegMapper5.nPRGBank[1] = nValue & 0x7F;
				nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[1], 1);
				break;
			}
		}
		else
			nesCardRegUpdateSRAMBankMapper5(nValue);
		break;
	case 0x5116:	// PRG\SRAM Bank Selection Registers
		if(nValue&0x80)
		{
			if(g_sNesCardRegMapper5.nPRGBankMode>=2)
			{
				g_sNesCardRegMapper5.nPRGBank[2] = nValue & 0x7F;
				nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[2], 2);
			}
		}
		else
			nesCardRegUpdateSRAMBankMapper5(nValue);
		break;
	case 0x5117:	// PRG Bank Selection Registers
		switch(g_sNesCardRegMapper5.nPRGBankMode)
		{
		case 0:
			g_sNesCardRegMapper5.nPRGBank[0] = nValue & 0x7C;
			g_sNesCardRegMapper5.nPRGBank[1] = g_sNesCardRegMapper5.nPRGBank[0] + 1;
			g_sNesCardRegMapper5.nPRGBank[2] = g_sNesCardRegMapper5.nPRGBank[1] + 1;
			g_sNesCardRegMapper5.nPRGBank[3] = g_sNesCardRegMapper5.nPRGBank[2] + 1;
			nesCardRegPRGBank32(g_sNesCardRegMapper5.nPRGBank[0]);
			break;
		case 1:
			g_sNesCardRegMapper5.nPRGBank[2] = nValue & 0x7E;
			g_sNesCardRegMapper5.nPRGBank[3] = g_sNesCardRegMapper5.nPRGBank[2] + 1;
			nesCardRegPRGBank16(g_sNesCardRegMapper5.nPRGBank[2], 2);
			break;
		case 2:
		case 3:
			g_sNesCardRegMapper5.nPRGBank[3] = nValue & 0x7F;
			nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[3], 3);
			break;
		}
		break;
	case 0x5120:	// CHR Bank Selection for Sprites and for CPU Access
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[0] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[0], 0);
		}
		break;
	case 0x5121:	// CHR Bank Selection for Sprites and for CPU Access
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 2:
			g_sNesCardRegMapper5.nCHRBank[0] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[1] = g_sNesCardRegMapper5.nCHRBank[0] + 1;
			nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[0], 0);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[1] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[1], 1);
			break;
		}
		break;
	case 0x5122:	// CHR Bank Selection for Sprites and for CPU Access
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[2] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[2], 2);
		}
		break;
	case 0x5123:	// CHR Bank Selection for Sprites and for CPU Access
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 1:
			g_sNesCardRegMapper5.nCHRBank[0] = nValue*4;
			g_sNesCardRegMapper5.nCHRBank[1] = g_sNesCardRegMapper5.nCHRBank[0] + 1;
			g_sNesCardRegMapper5.nCHRBank[2] = g_sNesCardRegMapper5.nCHRBank[1] + 1;
			g_sNesCardRegMapper5.nCHRBank[3] = g_sNesCardRegMapper5.nCHRBank[2] + 1;
			nesCardRegCHRBank4(g_sNesCardRegMapper5.nCHRBank[0], 0);
			break;
		case 2:
			g_sNesCardRegMapper5.nCHRBank[2] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[3] = g_sNesCardRegMapper5.nCHRBank[2] + 1;
			nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[2], 2);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[3] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[3], 3);
			break;
		}
		break;
	case 0x5124:	// CHR Bank Selection for Sprites and for CPU Access
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[4] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[4], 4);
		}
		break;
	case 0x5125:	// CHR Bank Selection for Sprites and for CPU Access
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 2:
			g_sNesCardRegMapper5.nCHRBank[4] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[5] = g_sNesCardRegMapper5.nCHRBank[4] + 1;
			nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[4], 4);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[5] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[5], 5);
			break;
		}
		break;
	case 0x5126:	// CHR Bank Selection for Sprites and for CPU Access
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[6] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[6], 6);
		}
		break;
	case 0x5127:	// CHR Bank Selection for Sprites and for CPU Access
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 0:
			g_sNesCardRegMapper5.nCHRBank[0] = nValue*8;
			for(n = 1 ; n < 8 ; n++)
				g_sNesCardRegMapper5.nCHRBank[n] = g_sNesCardRegMapper5.nCHRBank[n-1] + 1;
			nesCardRegCHRBank8(g_sNesCardRegMapper5.nCHRBank[0]);
			break;
		case 1:
			g_sNesCardRegMapper5.nCHRBank[4] = nValue*4;
			g_sNesCardRegMapper5.nCHRBank[5] = g_sNesCardRegMapper5.nCHRBank[4] + 1;
			g_sNesCardRegMapper5.nCHRBank[6] = g_sNesCardRegMapper5.nCHRBank[5] + 1;
			g_sNesCardRegMapper5.nCHRBank[7] = g_sNesCardRegMapper5.nCHRBank[6] + 1;
			nesCardRegCHRBank4(g_sNesCardRegMapper5.nCHRBank[4], 4);
			break;
		case 2:
			g_sNesCardRegMapper5.nCHRBank[6] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[7] = g_sNesCardRegMapper5.nCHRBank[6] + 1;
			nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[6], 6);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[7] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[7], 7);
			break;
		}
		break;
	case 0x5128:	// CHR Bank Selection for Background
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[8] = nValue;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[8], 8);
		}
		break;
	case 0x5129:	// CHR Bank Selection for Background
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 2:
			g_sNesCardRegMapper5.nCHRBank[8] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[9] = g_sNesCardRegMapper5.nCHRBank[8] + 1;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[8], 8);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[9] = nValue;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[9], 9);
			break;
		}
		break;
	case 0x512A:	// CHR Bank Selection for Background
		if(g_sNesCardRegMapper5.nCHRBankMode == 3)
		{
			g_sNesCardRegMapper5.nCHRBank[10] = nValue;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[10], 10);
		}
		break;
	case 0x512B:	// CHR Bank Selection for Background
		switch(g_sNesCardRegMapper5.nCHRBankMode)
		{
		case 0:
			g_sNesCardRegMapper5.nCHRBank[0] = nValue*8;
			for(n = 1 ; n < 8 ; n++)
				g_sNesCardRegMapper5.nCHRBank[n] = g_sNesCardRegMapper5.nCHRBank[n-1] + 1;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank8(g_sNesCardRegMapper5.nCHRBank[0]);
			break;
		case 1:
			g_sNesCardRegMapper5.nCHRBank[8] = nValue*4;
			g_sNesCardRegMapper5.nCHRBank[9] = g_sNesCardRegMapper5.nCHRBank[8] + 1;
			g_sNesCardRegMapper5.nCHRBank[10] = g_sNesCardRegMapper5.nCHRBank[9] + 1;
			g_sNesCardRegMapper5.nCHRBank[11] = g_sNesCardRegMapper5.nCHRBank[10] + 1;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank4(g_sNesCardRegMapper5.nCHRBank[8], 8);
			break;
		case 2:
			g_sNesCardRegMapper5.nCHRBank[10] = nValue*2;
			g_sNesCardRegMapper5.nCHRBank[11] = g_sNesCardRegMapper5.nCHRBank[10] + 1;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank2(g_sNesCardRegMapper5.nCHRBank[10], 10);
			break;
		case 3:
			g_sNesCardRegMapper5.nCHRBank[11] = nValue;
			if(g_sNesCardRegMapper5.nEXRAMMode != 1)
				nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[11], 11);
			break;
		}
		break;
	case 0x5130:	// Unknown
		break;
	case 0x5200:	// Horizontal Split Control
		break;
	case 0x5201:	// Horizontal Split Scroll Position
		break;
	case 0x5202:	// Horizontal Split CHR Bank Selection
		break;
	case 0x5203:	// Vertical IRQ Counter
		g_sNesCardRegMapper5.nIRQCount = nValue;
		break;
	case 0x5204:	// Vertical IRQ Control/Status (R/W)
		g_nNesCardIRQEnable = (nValue & 0x80) ? NES_CARD_IRQ_SCANLINE : 0;
		break;
	case 0x5205:	// Multiply unit input
		g_sNesCardRegMapper5.nMultiply[0] = nValue;
		break;
	case 0x5206:	// Multiply unit input
		g_sNesCardRegMapper5.nMultiply[1] = nValue;
		break;
	case 0x5800:	// Unknown
		break;
	}
}

/** @brief Read Data to Card Register - MMC-5 */
u8 nesCardRegMapper5Read(u16 nAddr)
{
	if(nAddr>=0x5C00)// 0x5C00h-5FFFh  EXRAM (1K)
		return g_pNesCardEXRAMMapper5[nAddr-0x5C00];
	//{
	//	switch(g_sNesCardRegMapper5.nEXRAMMode)
	//	{
	//	case 0:
	//	case 1:
	//		if(g_pNesGrpReg2002->rVBlank)
	//			return g_pNesCardEXRAMMapper5[nAddr-0x5C00];
	//		return 0x00;
	//	case 2:
	//	case 3:
	//		return g_pNesCardEXRAMMapper5[nAddr-0x5C00];
	//	}
	//}
	switch(nAddr)
	{
	case 0x5015:
		return (u8)((( SoundZ.activity ) << 2) | (( SoundY.activity ) << 1) | (( SoundX.activity ) << 0));
	case 0x5203:	// Vertical IRQ Counter
		return (u8)g_sNesCardRegMapper5.nIRQCount;
	case 0x5204:	// Vertical IRQ Control/Status (R/W)
		{
			u8 nData = g_nNesCpuIRQFlag ? 0x0 : 0x40;
			g_nNesCpuIRQFlag = 0;
			return nData;
		}
	case 0x5205:	// Multiply unit output (LSB)
		return (u8)(g_sNesCardRegMapper5.nMultiply[0] * g_sNesCardRegMapper5.nMultiply[1]);
	case 0x5206:	// Multiply unit output (MSB)
		return (u8)((g_sNesCardRegMapper5.nMultiply[0] * g_sNesCardRegMapper5.nMultiply[1]) >> 8);
	}
	return 0x00;
}

/** @brief Update Card IRQ - MMC-5 */
void nesCardUpdateIRQMapper5()
{
	if(g_sNesCardRegMapper5.nIRQCount <= 0)
	{
		g_nNesCpuIRQFlag = 1;
		g_nNesCardIRQEnable = 0;
	}
	else
		g_sNesCardRegMapper5.nIRQCount--;
}
//@}

/** @name Mapper 6 - UNROM */
//@{
/**
 * @struct nesSCardRegMapper6
 * @brief UNROM Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
}nesSCardRegMapper6;
nesSCardRegMapper6 g_sNesCardRegMapper6;

/** @brief Write Data to Card Register - UNROM */
void nesCardRegMapper6(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	g_sNesCardRegMapper6.nPRGBank = nValue << 1;
	nesCardRegPRGBank16(g_sNesCardRegMapper6.nPRGBank, 0);
}
//@}

/** @name Mapper 7 - CNROM */
//@{
/**
 * @struct nesSCardRegMapper7
 * @brief CNROM Card Register
 */
typedef struct
{
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper7;
nesSCardRegMapper7 g_sNesCardRegMapper7;

/** @brief Write Data to Card Register - CNROM */
void nesCardRegMapper7(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	g_sNesCardRegMapper7.nCHRBank = (nValue&0x03)*8;
	nesCardRegCHRBank8(g_sNesCardRegMapper7.nCHRBank);
	g_nPPUCHRRAM = 0;
}
//@}

/** @name Mapper 8 - GNROM */
//@{
/**
 * @struct nesSCardRegMapper8
 * @brief GNROM Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper8;
nesSCardRegMapper8 g_sNesCardRegMapper8;

/** @brief Write Data to Card Register - GNROM */
void nesCardRegMapper8(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	g_sNesCardRegMapper8.nPRGBank = ((nValue >> 4) & 0x03)*4;
	nesCardRegPRGBank32(g_sNesCardRegMapper8.nPRGBank);
	g_sNesCardRegMapper8.nCHRBank = (nValue & 0x03)*8;
	nesCardRegCHRBank8(g_sNesCardRegMapper8.nCHRBank);
}
//@}

/** @name Mapper 9 - RARE */
//@{
/**
 * @struct nesSCardRegMapper9
 * @brief RARE Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
}nesSCardRegMapper9;
nesSCardRegMapper9 g_sNesCardRegMapper9;

/** @brief Write Data to Card Register - RARE */
void nesCardRegMapper9(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	g_sNesCardRegMapper9.nPRGBank = (nValue&0x07)*4;
	nesCardRegPRGBank32(g_sNesCardRegMapper9.nPRGBank);
	if(nValue&0x10)
		nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
	else
		nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
	nesCardUpdatePC();
}
//@}

/** @name Mapper 10 - SUNSOFT1 */
//@{
/**
 * @struct nesSCardRegMapper10
 * @brief SUNSOFT1 Card Register
 */
typedef struct
{
	u32		nCHRBank0;			///< CHR Bank
	u32		nCHRBank1;			///< CHR Bank
}nesSCardRegMapper10;
nesSCardRegMapper10 g_sNesCardRegMapper10;

/** @brief Write Data to Card Register - SUNSOFT1 */
void nesCardRegMapper10(u16 nAddr, u8 nValue)
{
	if(nAddr == 0x6000)
	{
		switch(g_pNesROMHeader->nCHRBanks)
		{
		case 2:
			g_sNesCardRegMapper10.nCHRBank0 = (nValue & 0x03) * 4;
			g_sNesCardRegMapper10.nCHRBank1 = (nValue & 0x30) >> 2;
			break;
		case 4:
			g_sNesCardRegMapper10.nCHRBank0 = (nValue & 0x07) * 4;
			g_sNesCardRegMapper10.nCHRBank1 = (nValue & 0x70) >> 2;
			break;
		}
		nesCardRegCHRBank4(g_sNesCardRegMapper10.nCHRBank0, 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper10.nCHRBank1, 4);
	}
}
//@}

/** @name Mapper 11 - SUNSOFT2 */
//@{
/**
 * @struct nesSCardRegMapper11
 * @brief SUNSOFT2 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper11;
nesSCardRegMapper11 g_sNesCardRegMapper11;

/** @brief Write Data to Card Register - SUNSOFT2 */
void nesCardRegMapper11(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	g_sNesCardRegMapper11.nPRGBank = (nValue & 0x70) >> 3;
	g_sNesCardRegMapper11.nCHRBank = ((nValue & 0x07) | ((nValue>>4) & 0x08)) * 8;
	nesCardRegPRGBank16(g_sNesCardRegMapper11.nPRGBank, 0);
	nesCardRegCHRBank8(g_sNesCardRegMapper11.nCHRBank);
	nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0 + ((nValue & 0x08) >> 3));
}
//@}

/** @name Mapper 12 - SUNSOFT3 */
//@{
/**
 * @struct nesSCardRegMapper12
 * @brief SUNSOFT3 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank[4];		///< CHR Bank
	u32		nIRQToggle;			///< IRQ Toggle
}nesSCardRegMapper12;
nesSCardRegMapper12 g_sNesCardRegMapper12;

/** @brief Write Data to Card Register - SUNSOFT3 */
void nesCardRegMapper12(u16 nAddr, u8 nValue)
{
	if(nAddr == 0x8000)
	{
		g_nNesCpuIRQFlag = 0;
		return;
	}
	switch(nAddr & 0xF800)
	{
	case 0x8800:	// 8800h-8FFFh  Select 2K VROM bank at PPU 0000h-07FFh
		g_sNesCardRegMapper12.nCHRBank[0] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[0], 0);
		SET_PPU_VROM_BANK(0);
		SET_PPU_VROM_BANK(1);
		break;
	case 0x9800:	// 9800h-9FFFh  Select 2K VROM bank at PPU 0800h-0FFFh
		g_sNesCardRegMapper12.nCHRBank[1] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[1], 2);
		SET_PPU_VROM_BANK(2);
		SET_PPU_VROM_BANK(3);
		break;
	case 0xA800:	// A800h-AFFFh  Select 2K VROM bank at PPU 1000h-17FFh
		g_sNesCardRegMapper12.nCHRBank[2] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[2], 4);
		SET_PPU_VROM_BANK(4);
		SET_PPU_VROM_BANK(5);
		break;
	case 0xB800:	// B800h-BFFFh  Select 2K VROM bank at PPU 1800h-1FFFh
		g_sNesCardRegMapper12.nCHRBank[3] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[3], 6);
		SET_PPU_VROM_BANK(6);
		SET_PPU_VROM_BANK(7);
		break;
	case 0xC800:	// C800h-CFFFh  IRQ Counter (two writes: 1st=MSB, 2nd=LSB)
		if(g_sNesCardRegMapper12.nIRQToggle)
			g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0xFF00) + nValue;
		else
			g_nNesCardIRQTicks = (nValue<<8) + (g_nNesCardIRQTicks & 0x00FF);
		g_sNesCardRegMapper12.nIRQToggle ^= 1;
		break;
	case 0xD800:	// D800h-DFFFh  IRQ Control (Bit4: 0=Disable, 1=Enable)
		g_nNesCpuIRQFlag = 0;
		g_nNesCardIRQEnable = (nValue & 0x10) ? NES_CARD_IRQ_CPUCYCLE : 0;
		g_sNesCardRegMapper12.nIRQToggle = 0;
		break;
	case 0xE800:	// E800h-EFFFh  Mirroring control
		switch(nValue & 0x03)
		{
		case 0:
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
			break;
		case 1:
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
			break;
		case 2:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
			break;
		case 3:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			break;
		}
		break;
	case 0xF800:	// F800h-FFFFh  Select 16K ROM bank at 8000h-BFFFh
		g_sNesCardRegMapper12.nPRGBank = nValue * 2;
		nesCardRegPRGBank16(g_sNesCardRegMapper12.nPRGBank, 0);
		g_nPPUCHRRAM=0;
		break;
	}
}

/** @brief Update Card IRQ - SUNSOFT3 */
void nesCardUpdateIRQMapper12()
{
	g_nNesCardIRQTicks = 0x10000;
	g_nNesCardIRQEnable = 0;
	g_nNesCpuIRQFlag = 1;
}
//@}

/** @name Mapper 13 - SUNSOFT4 */
//@{
/**
 * @struct nesSCardRegMapper13
 * @brief SUNSOFT3 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank1[2];		///< CHR Bank
	u32		nCHRBank2[4];		///< CHR Bank
	u32		nCHRMode;			///< CHR Mode
	u32		nCHRNameTab;		///< CHR Name Table
}nesSCardRegMapper13;
nesSCardRegMapper13 g_sNesCardRegMapper13;

/** @brief Update Name Table - SUNSOFT4 */
void nesCardRegUpdateNameTable()
{
	switch(g_sNesCardRegMapper13.nCHRNameTab)
	{
	case 0:
		g_pNesGrpNameTab[0] = g_pNesGrpNameTab[2] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[0] * NES_CARD_BANKSIZE_CHR;
		g_pNesGrpNameTab[1] = g_pNesGrpNameTab[3] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[1] * NES_CARD_BANKSIZE_CHR;
		break;
	case 1:
		g_pNesGrpNameTab[0] = g_pNesGrpNameTab[1] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[0] * NES_CARD_BANKSIZE_CHR;
		g_pNesGrpNameTab[2] = g_pNesGrpNameTab[3] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[1] * NES_CARD_BANKSIZE_CHR;
		break;
	case 2:
		g_pNesGrpNameTab[0] = g_pNesGrpNameTab[1] = g_pNesGrpNameTab[2] = g_pNesGrpNameTab[3] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[0] * NES_CARD_BANKSIZE_CHR;
		break;
	case 3:
		g_pNesGrpNameTab[0] = g_pNesGrpNameTab[1] = g_pNesGrpNameTab[2] = g_pNesGrpNameTab[3] = g_pNesCHRROM + g_sNesCardRegMapper13.nCHRBank1[1] * NES_CARD_BANKSIZE_CHR;
		break;
	}
}

/** @brief Write Data to Card Register - SUNSOFT4 */
void nesCardRegMapper13(u16 nAddr, u8 nValue)
{
	switch(nAddr>>12)
	{
	case 0x8:	// 8000h  Select 2K VROM bank at PPU 0000h-07FFh
		g_sNesCardRegMapper13.nCHRBank2[0] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[0], 0);
		break;
	case 0x9:	// 9000h  Select 2K VROM bank at PPU 0800h-0FFFh
		g_sNesCardRegMapper13.nCHRBank2[1] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[1], 2);
		break;
	case 0xA:	// A000h  Select 2K VROM bank at PPU 1000h-17FFh
		g_sNesCardRegMapper13.nCHRBank2[2] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[2], 4);
		break;
	case 0xB:	// B000h  Select 2K VROM bank at PPU 1800h-1FFFh
		g_sNesCardRegMapper13.nCHRBank2[3] = nValue * 2;
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[3], 6);
		break;
	case 0xC:	// C000h  Select 1K VROM bank as BLK0 (in VROM Mode) (from LAST 128 banks)
		if(g_pNesROMHeader->nCHRBanks > 16)
			g_sNesCardRegMapper13.nCHRBank1[0] = (g_pNesROMHeader->nCHRBanks - 16) * 8 + nValue;
		else
			g_sNesCardRegMapper13.nCHRBank1[0] = nValue;
		if(g_sNesCardRegMapper13.nCHRMode)
			nesCardRegUpdateNameTable();
		break;
	case 0xD:	// D000h  Select 1K VROM bank as BLK1 (in VROM Mode) (from LAST 128 banks)
		if(g_pNesROMHeader->nCHRBanks > 16)
			g_sNesCardRegMapper13.nCHRBank1[1] = (g_pNesROMHeader->nCHRBanks - 16) * 8 + nValue;
		else
			g_sNesCardRegMapper13.nCHRBank1[1] = nValue;
		if(g_sNesCardRegMapper13.nCHRMode)
			nesCardRegUpdateNameTable();
		break;
	case 0xE:	// E000h  Name Table Control
		g_sNesCardRegMapper13.nCHRMode = nValue & 0x10;
		g_sNesCardRegMapper13.nCHRNameTab = nValue & 0x03;
		if(g_sNesCardRegMapper13.nCHRMode)
		{
			nesGrpChangeNameTabMap(NES_GRP_MAP_EXTEND);
			nesCardRegUpdateNameTable();
		}
		else
		{
			switch(g_sNesCardRegMapper13.nCHRNameTab)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
				break;
			case 1:
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
				break;
			case 2:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			case 3:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			}
		}
		break;
	case 0xF:	// F000h  Select 16K ROM bank at 8000h-BFFFh (initially 1st bank)
		g_sNesCardRegMapper13.nPRGBank = nValue * 2;
		nesCardRegPRGBank16(g_sNesCardRegMapper13.nPRGBank, 0);
		break;
	}
}
//@}

/** @name Mapper 14 - SUNSOFT5 */
//@{
/**
 * @struct nesSCardRegMapper14
 * @brief SUNSOFT3 Card Register
 */
typedef struct
{
	u32		nSRAMBank;			///< SRAM Bank
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nCMD;				///< Command Index
	u32		nPRGMode;			///< SRAM\PRG Mode
}nesSCardRegMapper14;
nesSCardRegMapper14 g_sNesCardRegMapper14;

/** @brief Write Data to Card Register - SUNSOFT5 */
void nesCardRegMapper14(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// 8000h  Index Register (4bit)
		g_sNesCardRegMapper14.nCMD = nValue & 0x0F;
		break;
	case 0xA000:	// A000h  Data Register
		switch(g_sNesCardRegMapper14.nCMD)
		{
		case 0x0:
		case 0x1:
		case 0x2:
		case 0x3:
		case 0x4:
		case 0x5:
		case 0x6:
		case 0x7:
			g_sNesCardRegMapper14.nCHRBank[g_sNesCardRegMapper14.nCMD] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper14.nCHRBank[g_sNesCardRegMapper14.nCMD], g_sNesCardRegMapper14.nCMD);
			SET_PPU_VROM_BANK(g_sNesCardRegMapper14.nCMD);
			break;
		case 0x8:
			if(nValue & 0x40)
			{
				if(nValue & 0x80)
				{
					g_pNesSRAMBank = g_pNesSRAM;
					g_sNesCardRegMapper14.nPRGMode = 0;
				}
			}
			else
			{
				g_sNesCardRegMapper14.nSRAMBank = nValue & 0x3F;
				g_pNesSRAMBank = g_pNesPRGROM + g_sNesCardRegMapper14.nSRAMBank * NES_CARD_BANKSIZE_SRAM;
				g_sNesCardRegMapper14.nPRGMode = 1;
			}
			break;
		case 0x9:
		case 0xA:
		case 0xB:
			{
				u32 nIndex = g_sNesCardRegMapper14.nCMD-9;
				g_sNesCardRegMapper14.nPRGBank[nIndex] = nValue;
				nesCardRegPRGBank8(g_sNesCardRegMapper14.nPRGBank[nIndex], nIndex);
			}
			break;
		case 0xC:
			switch(nValue & 0x03)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
				break;
			case 1:
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
				break;
			case 2:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			case 3:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			}
			break;
		case 0xD:
			switch(nValue)
			{
			case 0x00:
				g_nNesCpuIRQFlag = 0;
				g_nNesCardIRQEnable = 0;
				break;
			case 0x81:
				g_nNesCpuIRQFlag = 0;
				g_nNesCardIRQEnable = NES_CARD_IRQ_CPUCYCLE;
				break;
			}
			break;
		case 0xE:
			g_nNesCpuIRQFlag = 0;
			g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0xFF00) + nValue;
			break;
		case 0xF:
			g_nNesCpuIRQFlag = 0;
			g_nNesCardIRQTicks = (nValue<<8) + (g_nNesCardIRQTicks & 0x00FF);
			break;
		}
		break;
	case 0xC000:
	case 0xE000:
		nesSndRegWriteCard(nAddr, nValue);
	}
}

/** @brief Update Card IRQ - SUNSOFT5 */
void nesCardUpdateIRQMapper14()
{
	g_nNesCardIRQTicks += 0x10000;
	g_nNesCardIRQEnable = 0;
	g_nNesCpuIRQFlag = 1;
}
//@} 

/** @name Mapper 15 - BANDAI */
//@{
/**
 * @struct nesSCardRegMapper15
 * @brief BANDAI Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper15;
nesSCardRegMapper15 g_sNesCardRegMapper15;

/** @brief Write Data to Card Register - BANDAI */
void nesCardRegMapper15(u16 nAddr, u8 nValue)
{
	if((nAddr >= 0xC000) && (nAddr < 0xC100))
	{
		// Bit7    Name Table Select (0/1 = BLK0/BLK1)
		if(nValue & 0x80)
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);

		// Bit6-4  Select 16K ROM at 8000h-BFFFh
		g_sNesCardRegMapper15.nPRGBank = (nValue & 0x70) >> 3;
		nesCardRegPRGBank16(g_sNesCardRegMapper15.nPRGBank, 0);
		// Bit3-0  Select 8K VROM at PPU 0000h-1FFFh 
		g_sNesCardRegMapper15.nCHRBank = (nValue & 0x0F) * 8;
		nesCardRegCHRBank8(g_sNesCardRegMapper15.nCHRBank);
	}
}
//@}

/** @name Mapper 16 - VRC1 */
//@{
/**
 * @struct nesSCardRegMapper16
 * @brief VRC1 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[2];		///< CHR Bank
}nesSCardRegMapper16;
nesSCardRegMapper16 g_sNesCardRegMapper16;

/** @brief Write Data to Card Register - VRC1 */
void nesCardRegMapper16(u16 nAddr, u8 nValue)
{
	switch(nAddr >> 12)
	{
	case 0x8:	// Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper16.nPRGBank[0] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper16.nPRGBank[0], 0);
		break;
	case 0x9:	// Bit0: Mirroring, Bit1-2: MSBs of VROM banks
		g_sNesCardRegMapper16.nCHRBank[0] = ((nValue << 5) & 0x40) + (g_sNesCardRegMapper16.nCHRBank[0] & 0x3C);
		g_sNesCardRegMapper16.nCHRBank[1] = ((nValue << 4) & 0x40) + (g_sNesCardRegMapper16.nCHRBank[1] & 0x3C);
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[0], 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[1], 4);
		if(nValue & 0x01)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	case 0xA:	// Select 8K ROM at A000h-BFFFh
		g_sNesCardRegMapper16.nPRGBank[1] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper16.nPRGBank[1], 1);
		break;
	case 0xC:	// Select 8K ROM at C000h-DFFFh
		g_sNesCardRegMapper16.nPRGBank[2] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper16.nPRGBank[2], 2);
		break;
	case 0xE:	// Lower 4bit of 4K VROM bank at PPU 0000h-0FFFh (MSB in Bit1 of Register 9)
		g_sNesCardRegMapper16.nCHRBank[0] = (g_sNesCardRegMapper16.nCHRBank[0] & 0x40) + (nValue & 0x0F) * 4;
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[0], 0);
		break;
	case 0xF:	// Lower 4bit of 4K VROM bank at PPU 1000h-1FFFh (MSB in Bit2 of Register 9)
		g_sNesCardRegMapper16.nCHRBank[1] = (g_sNesCardRegMapper16.nCHRBank[1] & 0x40) + (nValue & 0x0F) * 4;
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[1], 4);
		break;
	}
}
//@}

/** @name Mapper 17 - VRC2A */
//@{
/**
 * @struct nesSCardRegMapper17
 * @brief VRC2A Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
}nesSCardRegMapper17;
nesSCardRegMapper17 g_sNesCardRegMapper17;

/** @brief Write Data to Card Register - VRC2A */
void nesCardRegMapper17(u16 nAddr, u8 nValue)
{
	switch(nAddr >> 12)
	{
	case 0x8:	// Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper17.nPRGBank[0] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper17.nPRGBank[0], 0);
		break;
	case 0x9:	// Bit1-0: Mirroring
		switch(nValue & 0x03)
		{
		case 0:
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
			break;
		case 1:
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
			break;
		case 2:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
			break;
		case 3:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			break;
		}
		break;
	case 0xA:	// Select 8K ROM at A000h-BFFFh
		g_sNesCardRegMapper17.nPRGBank[1] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper17.nPRGBank[1], 1);
		break;
	case 0xB:	// Select 1K VROM bank at PPU 0000h-03FFh ~ 0400h-07FFh
	case 0xC:	// Select 1K VROM bank at PPU 0800h-0BFFh ~ 0C00h-0FFFh
	case 0xD:	// Select 1K VROM bank at PPU 1000h-13FFh ~ 1400h-17FFh
	case 0xE:	// Select 1K VROM bank at PPU 1800h-1BFFh ~ 1C00h-1FFFh
		{
			u32 nIndex = ((nAddr-0xB000) >> 11) | (nAddr & 0x01);
			if(nAddr & 0x02)
				g_sNesCardRegMapper17.nCHRBank[nIndex] = ((nValue & 0x0F) << 3) + (g_sNesCardRegMapper17.nCHRBank[nIndex] & 0x07);
			else
				g_sNesCardRegMapper17.nCHRBank[nIndex] = ((nValue & 0x0F) >> 1) + (g_sNesCardRegMapper17.nCHRBank[nIndex] & 0x78);
			nesCardRegCHRBank1(g_sNesCardRegMapper17.nCHRBank[nIndex], nIndex);
		}
		break;
	}
}
//@}

/**
 * @struct nesSCardRegMapper18
 * @brief VRC2B Card Register
 */
typedef struct
{
	u32		nPRGMode;			///< PRG Mode
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	u32		nIRQCount;			///< IRQ Count Value
	u32		nIRQEnable;			///< IRQ Enable
}nesSCardRegMapper18;
nesSCardRegMapper18 g_sNesCardRegMapper18;

/** @brief Write Data to Card Register - VRC2B */
void nesCardRegMapper18(u16 nAddr, u8 nValue)
{
	nAddr |= ((nAddr>>2)&0x3) | ((nAddr>>4)&0x3) | ((nAddr>>6)&0x3);
	switch(nAddr >> 12)
	{
	case 0x8:	// Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper18.nPRGBank[0] = nValue & 0x0F;
		if(g_sNesCardRegMapper18.nPRGMode)
		{
			nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 0);
			nesCardRegPRGBank8(g_sNesCardRegMapper18.nPRGBank[0], 2);
		}
		else
		{
			nesCardRegPRGBank8(g_sNesCardRegMapper18.nPRGBank[0], 0);
			nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2);
		}
		break;
	case 0x9:	// Bit1-0: Mirroring
		if(nAddr & 0x02)
			g_sNesCardRegMapper18.nPRGMode = nValue & 0x02;
		else
		{
			if(nValue!=0xFF)
			{
				switch(nValue & 0x03)
				{
				case 0:
					nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
					break;
				case 1:
					nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
					break;
				case 2:
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
					break;
				case 3:
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
					break;
				}
			}
		}
		break;
	case 0xA:	// Select 8K ROM at A000h-BFFFh
		g_sNesCardRegMapper18.nPRGBank[1] = nValue & 0x0F;
		nesCardRegPRGBank8(g_sNesCardRegMapper18.nPRGBank[1], 1);
		break;
	case 0xB:	// Select 1K VROM bank at PPU 0000h-03FFh ~ 0400h-07FFh
	case 0xC:	// Select 1K VROM bank at PPU 0800h-0BFFh ~ 0C00h-0FFFh
	case 0xD:	// Select 1K VROM bank at PPU 1000h-13FFh ~ 1400h-17FFh
	case 0xE:	// Select 1K VROM bank at PPU 1800h-1BFFh ~ 1C00h-1FFFh
		{
			u32 nIndex = ((nAddr-0xB000) >> 11) | ((nAddr>>1) & 0x01);
			if(nAddr & 0x01)
				g_sNesCardRegMapper18.nCHRBank[nIndex] = ((nValue & 0x0F) << 4) + (g_sNesCardRegMapper18.nCHRBank[nIndex] & 0x0F);
			else
				g_sNesCardRegMapper18.nCHRBank[nIndex] = (nValue & 0x0F) + (g_sNesCardRegMapper18.nCHRBank[nIndex] & 0xF0);
			nesCardRegCHRBank1(g_sNesCardRegMapper18.nCHRBank[nIndex], nIndex);
			SET_PPU_VROM_BANK(nIndex);
		}
		break;
	case 0xF:
		g_nNesCpuIRQFlag = 0;
		switch(nAddr & 0x03)
		{
		case 0:
			g_sNesCardRegMapper18.nIRQInit = (g_sNesCardRegMapper18.nIRQInit & 0xF0) + (nValue & 0x0F);
			break;
		case 1:
			g_sNesCardRegMapper18.nIRQInit = (g_sNesCardRegMapper18.nIRQInit & 0x0F) + ((nValue & 0x0F) << 4);
			break;
		case 2:
			g_sNesCardRegMapper18.nIRQCount = g_sNesCardRegMapper18.nIRQInit;
			g_sNesCardRegMapper18.nIRQEnable = nValue & 0x03;
			g_nNesCardIRQEnable = (g_sNesCardRegMapper18.nIRQEnable & 0x2) ? NES_CARD_IRQ_SCANLINEV : 0;
			break;
		case 3:
			g_nNesCardIRQEnable = (g_sNesCardRegMapper18.nIRQEnable & 0x1) ? NES_CARD_IRQ_SCANLINEV : 0;
			break;
		}
		break;
	}
}

/** @brief Update Card IRQ - VRC2B */
void nesCardUpdateIRQMapper18()
{
	g_sNesCardRegMapper18.nIRQCount++;
	if(g_sNesCardRegMapper18.nIRQCount >= 0x100)
	{
		g_sNesCardRegMapper18.nIRQCount = g_sNesCardRegMapper18.nIRQInit;
		g_nNesCpuIRQFlag = 1;
	}
}
//@}

/** @name Mapper 19 - VRC3 */
//@{
/**
 * @struct nesSCardRegMapper19
 * @brief VRC3 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
}nesSCardRegMapper19;
nesSCardRegMapper19 g_sNesCardRegMapper19;

/** @brief Write Data to Card Register - VRC3 */
void nesCardRegMapper19(u16 nAddr, u8 nValue)
{
	switch(nAddr >> 12)
	{
	case 0x8:
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0xFFF0) + (0x0F - (nValue & 0x0F));
		break;
	case 0x9:
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0xFF0F) + ((0x0F - (nValue & 0x0F)) << 4);
		break;
	case 0xA:
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0xF0FF) + ((0x0F - (nValue & 0x0F)) << 8);
		break;
	case 0xB:
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0x0FFF) + ((0x0F - (nValue & 0x0F)) << 12);
		break;
	case 0xC:
		g_nNesCardIRQEnable = (nValue & 0x02) ? NES_CARD_IRQ_CPUCYCLE : 0;
		g_nNesCpuIRQFlag = 0;
		break;
	case 0xD:
		g_nNesCpuIRQFlag = 0;
		break;
	case 0xF:	// Select 16K ROM at 8000h-BFFFh
		g_sNesCardRegMapper19.nPRGBank = (nValue & 0x0F) * 2;
		nesCardRegPRGBank16(g_sNesCardRegMapper19.nPRGBank, 0);
		break;
	}
}

/** @brief Update Card IRQ - VRC3 */
void nesCardUpdateIRQMapper19()
{
	g_nNesCardIRQTicks += 0x10000;
	g_nNesCardIRQEnable = 0;
	g_nNesCpuIRQFlag = 1;
}
//@}

/** @name Mapper 20 - VRC4 */
//@{
/**
 * @struct nesSCardRegMapper20
 * @brief VRC4 Card Register
 */
typedef struct
{
	u32		nSubMapper;			///< Sub Mapper Type
	u32		nPRGBankMode;		///< PRG Mode
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	u32		nIRQCount;			///< IRQ Count Value
	u32		nIRQEnable;			///< IRQ Enable
}nesSCardRegMapper20;
nesSCardRegMapper20 g_sNesCardRegMapper20;

/** @brief Write Data to Card Register - VRC4 */
void nesCardRegMapper20(u16 nAddr, u8 nValue)
{
	u32 nAddrX = nAddr >> 12;
	u32 nAddrY;
	switch(g_sNesCardRegMapper20.nSubMapper)
	{
	case 0:	// VRC4A
		nAddrY = (nAddr >> 1) & 0x0003;
		break;
	case 1:	// VRC4B
		nAddrY = ((nAddr >> 1) & 0x0001) | ((nAddr << 1) & 0x0002);
		break;
	case 2:	// VRC4C
		nAddrY = (nAddr >> 6) & 0x0003;
		break;
	case 3:	// VRC4D
		nAddrY = ((nAddr >> 3) & 0x0001) | ((nAddr >> 1) & 0x0002);
		break;
	case 4:	// VRC4E
		nAddrY = (nAddr >> 2) & 0x0003;
		break;
	}
	switch(nAddrX)
	{
	case 0x8:	// Select 8K ROM at 8000h-9FFFh or C000h-DFFFh
		g_sNesCardRegMapper20.nPRGBank[g_sNesCardRegMapper20.nPRGBankMode] = nValue/* & 0x1F*/;
		nesCardRegPRGBank8(g_sNesCardRegMapper20.nPRGBank[g_sNesCardRegMapper20.nPRGBankMode], g_sNesCardRegMapper20.nPRGBankMode);
		break;
	case 0x9:	// Memory Control
		if(nAddrY)
		{
			u32 nMode;
			g_nNesCardSRAMEnable = nValue & 0x01;
			nMode = nValue & 0x02;
			if(g_sNesCardRegMapper20.nPRGBankMode != nMode)
			{
				nesCardRegPRGBank8(g_sNesCardRegMapper20.nPRGBank[nMode], nMode);
				nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, g_sNesCardRegMapper20.nPRGBankMode);
				g_sNesCardRegMapper20.nPRGBankMode = nMode;
			}
		}
		else
		{
			switch(nValue & 0x03)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
				break;
			case 1:
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
				break;
			case 2:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			case 3:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			}
		}
		break;
	case 0xA:	// Select 8K ROM at A000h-BFFFh
		g_sNesCardRegMapper20.nPRGBank[1] = nValue/* & 0x1F*/;
		nesCardRegPRGBank8(g_sNesCardRegMapper20.nPRGBank[1], 1);
		break;
	case 0xB:	// Select 1K VROM bank at PPU 0000h-03FFh ~ 0400h-07FFh
	case 0xC:	// Select 1K VROM bank at PPU 0800h-0BFFh ~ 0C00h-0FFFh
	case 0xD:	// Select 1K VROM bank at PPU 1000h-13FFh ~ 1400h-17FFh
	case 0xE:	// Select 1K VROM bank at PPU 1800h-1BFFh ~ 1C00h-1FFFh
		{
			u32 nIndex = ((nAddrX - 0xB) << 1) | (nAddrY>>1);
			if(nAddrY & 0x01)
				g_sNesCardRegMapper20.nCHRBank[nIndex] = ((nValue & 0x0F) << 4) + (g_sNesCardRegMapper20.nCHRBank[nIndex] & 0x0F);
			else
				g_sNesCardRegMapper20.nCHRBank[nIndex] = (nValue & 0x0F) + (g_sNesCardRegMapper20.nCHRBank[nIndex] & 0xF0);
			nesCardRegCHRBank1(g_sNesCardRegMapper20.nCHRBank[nIndex], nIndex);
			SET_PPU_VROM_BANK(nIndex);
		}
		break;
	case 0xF:	// IRQ Registers
		switch(nAddrY)
		{
		case 0:
			g_sNesCardRegMapper20.nIRQInit = (g_sNesCardRegMapper20.nIRQInit & 0xF0) + (nValue & 0x0F);
			break;
		case 1:
			g_sNesCardRegMapper20.nIRQInit = (g_sNesCardRegMapper20.nIRQInit & 0x0F) + ((nValue & 0x0F) << 4);
			break;
		case 2:
			g_sNesCardRegMapper20.nIRQCount = g_sNesCardRegMapper20.nIRQInit;
			g_sNesCardRegMapper20.nIRQEnable = nValue & 0x03;
			g_nNesCardIRQEnable = (g_sNesCardRegMapper20.nIRQEnable & 0x02) ? NES_CARD_IRQ_SCANLINEV : 0;
			g_nNesCpuIRQFlag = 0;
			break;
		case 3:
			g_nNesCardIRQEnable = (g_sNesCardRegMapper20.nIRQEnable & 0x01) ? NES_CARD_IRQ_SCANLINEV : 0;
			g_nNesCpuIRQFlag = 0;
			break;
		}
		break;
	}
}

/** @brief Update Card IRQ - VRC4 */
void nesCardUpdateIRQMapper20()
{
	g_sNesCardRegMapper20.nIRQCount++;
	if(g_sNesCardRegMapper20.nIRQCount >= 0x100)
	{
		g_sNesCardRegMapper20.nIRQCount = g_sNesCardRegMapper20.nIRQInit;
		g_nNesCpuIRQFlag = 1;
	}
}
//@}

/** @name Mapper 25 - VRC6 */
//@{
/**
 * @struct nesSCardRegMapper25
 * @brief VRC6 Card Register
 */
typedef struct
{
	u32		nSubMapper;			///< Sub Mapper Type
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	u32		nIRQCount;			///< IRQ Count Value
	u32		nIRQAuto;			///< IRQ Auto Restart Flag
}nesSCardRegMapper25;
nesSCardRegMapper25 g_sNesCardRegMapper25;

/** @brief Write Data to Card Register - VRC6 */
void nesCardRegMapper25(u16 nAddr, u8 nValue)
{
	u32 nAddrX = nAddr >> 12;
	u32 nAddrY;
	switch(g_sNesCardRegMapper25.nSubMapper)
	{
	case 0:	// VRC6A
		nAddrY = nAddr & 0x0003;
		break;
	case 1:	// VRC6B
		nAddrY = ((nAddr >> 1) & 0x0001) | ((nAddr << 1) & 0x0002);
		break;
	}
	switch(nAddrX)
	{
	case 0x8:	// Select 16K ROM at 8000h-BFFFh
		g_sNesCardRegMapper25.nPRGBank[0] = nValue *2;
		nesCardRegPRGBank16(g_sNesCardRegMapper25.nPRGBank[0], 0);
		break;
	case 0x9:
	case 0xA:
		nAddr = (u16)(((nAddrX << 12) | nAddrY) - 0x9000);
		nAddr = (u16)((nAddrX - 0x9)*4 + nAddrY);
		nesSndRegWriteCard(nAddr, nValue);
		break;
	case 0xB:	// Name Table Control
		if(nAddrY < 3)
		{
			//VRC
			nesSndRegWriteCard((u16)(nAddrY + 0x8), nValue);
		}
		else if(nAddrY == 3)
		{
			switch((nValue>>2) & 0x03)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
				break;
			case 1:
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
				break;
			case 2:
				if(nValue & 0x20)
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				else
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			case 3:
				if(nValue & 0x20)
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				else
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			}
			g_nNesCardSRAMEnable = (nValue & 0x80) >> 7;
		}
		else
		{
			nAddr = (u16)(((nAddrX << 12) | nAddrY) - 0x9000);
			nesSndRegWriteCard(nAddr, nValue);
		}
		break;
	case 0xC:	// Select 8K ROM at C000h-DFFFh
		g_sNesCardRegMapper25.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper25.nPRGBank[1], 2);
		break;
	case 0xD:	// VROM Bank Registers
 	case 0xE:
		nAddrY |= (nAddrX - 0xD) << 2;
		g_sNesCardRegMapper25.nCHRBank[nAddrY] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper25.nCHRBank[nAddrY], nAddrY);
		break;
	case 0xF:	// IRQ Registers
		switch(nAddrY)
		{
		case 0:
			g_sNesCardRegMapper25.nIRQInit = nValue;
			break;
		case 1:
			g_sNesCardRegMapper25.nIRQAuto = nValue & 0x03;
			if( g_sNesCardRegMapper25.nIRQAuto & 0x02 ) {
				g_sNesCardRegMapper25.nIRQCount = g_sNesCardRegMapper25.nIRQInit;
				g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINEV;
			}
			else
				g_nNesCardIRQEnable=0;
			break;
		case 2:
			g_sNesCardRegMapper25.nIRQAuto = (g_sNesCardRegMapper25.nIRQAuto & 0x1)*3;
			if( g_sNesCardRegMapper25.nIRQAuto & 0x02 )
				g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINEV;
			else
				g_nNesCardIRQEnable = 0;
			g_nNesCpuIRQFlag = 0;
			break;
		}
		break;
	}
}

/** @brief Update Card IRQ - VRC6 */
void nesCardUpdateIRQMapper25()
{
	if( g_sNesCardRegMapper25.nIRQAuto & 0x02 ) {
		if(g_sNesCardRegMapper25.nIRQCount == 0xFF)
		{
			g_nNesCpuIRQFlag = 1;
			g_sNesCardRegMapper25.nIRQCount = g_sNesCardRegMapper25.nIRQInit;
		}
		else
			g_sNesCardRegMapper25.nIRQCount++;
	}
}
//@}

/** @name Mapper 27 - VRC7 */
//@{
/**
 * @struct nesSCardRegMapper27
 * @brief VRC7 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	u32		nIRQCount;			///< IRQ Count Value
	u32		nIRQAuto;			///< IRQ Auto Restart Flag
}nesSCardRegMapper27;
nesSCardRegMapper27 g_sNesCardRegMapper27;

/** @brief Write Data to Card Register - VRC7 */
void nesCardRegMapper27(u16 nAddr, u8 nValue)
{
	u32 nAddrX = (nAddr & 0xF000) | ((nAddr >> 4) & 0x0001);
	switch(nAddrX)
	{
	case 0x8000:	// Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper27.nPRGBank[0] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper27.nPRGBank[0], 0);
		break;
	case 0x8001:	// Select 8K ROM at A000h-BFFFh
		g_sNesCardRegMapper27.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper27.nPRGBank[1], 1);
		break;
	case 0x9000:	// Select 8K ROM at C000h-DFFFh
		g_sNesCardRegMapper27.nPRGBank[2] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper27.nPRGBank[2], 2);
		break;
	case 0x9001:	// OPL2 Sound Registers
		if(((nAddr >> 5) & 0x0001))		// Data Register
		{
		}
		else							// Index Register
		{
		}
		break;
	case 0xA000:	// Select 1K VROM bank at PPU 0000h-03FFh
		g_sNesCardRegMapper27.nCHRBank[0] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[0], 0);
		break;
	case 0xA001:	// Select 1K VROM bank at PPU 0400h-07FFh
		g_sNesCardRegMapper27.nCHRBank[1] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[1], 1);
		break;
	case 0xB000:	// Select 1K VROM bank at PPU 0800h-0BFFh
		g_sNesCardRegMapper27.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[2], 2);
		break;
	case 0xB001:	// Select 1K VROM bank at PPU 0C00h-0FFFh
		g_sNesCardRegMapper27.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[3], 3);
		break;
	case 0xC000:	// Select 1K VROM bank at PPU 1000h-13FFh
		g_sNesCardRegMapper27.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[4], 4);
		break;
	case 0xC001:	// Select 1K VROM bank at PPU 1400h-17FFh
		g_sNesCardRegMapper27.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[5], 5);
		break;
	case 0xD000:	// Select 1K VROM bank at PPU 1800h-1BFFh
		g_sNesCardRegMapper27.nCHRBank[6] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[6], 6);
		break;
	case 0xD001:	// Select 1K VROM bank at PPU 1C00h-1FFFh
		g_sNesCardRegMapper27.nCHRBank[7] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[7], 7);
		break;
	case 0xE000:	// Name Table Control
		switch(nValue & 0x03)
		{
		case 0:
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
			break;
		case 1:
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
			break;
		case 2:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			break;
		case 3:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
			break;
		}
		break;
	case 0xE001:	// IRQ Reload value
		g_sNesCardRegMapper27.nIRQInit = nValue;
		break;
	case 0xF000:	// IRQ Control
		g_sNesCardRegMapper27.nIRQCount = g_sNesCardRegMapper27.nIRQInit;
		g_sNesCardRegMapper27.nIRQAuto = nValue & 0x02;
		g_nNesCardIRQEnable = (nValue & 0x03) ? NES_CARD_IRQ_SCANLINEV : 0;
		break;
	case 0xF001:	// IRQ Acknowledge
		g_nNesCpuIRQFlag = 0;
		break;
	}
}

/** @brief Update Card IRQ - VRC7 */
void nesCardUpdateIRQMapper27()
{
	g_sNesCardRegMapper27.nIRQCount++;
	if(g_sNesCardRegMapper27.nIRQCount >= 0x100)
	{
		g_sNesCardRegMapper27.nIRQCount &= 0xFF;
		g_nNesCpuIRQFlag = 1;
		if(g_sNesCardRegMapper27.nIRQAuto)
			g_sNesCardRegMapper27.nIRQCount = g_sNesCardRegMapper27.nIRQInit;
		else
			g_nNesCardIRQEnable = 0;
	}
}
//@}

/** @name Mapper 28 - JALECO-1 */
//@{
/**
 * @struct nesSCardRegMapper28
 * @brief JALECO-1 Card Register
 */
typedef struct
{
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper28;
nesSCardRegMapper28 g_sNesCardRegMapper28;

/** @brief Write Data to Card Register - JALECO-1 */
void nesCardRegMapper28(u16 nAddr, u8 nValue)
{
	if(nAddr == 0x6000)	// Select 8K VROM bank at PPU 0000h-1FFFh (Bit 1 used only)
	{
		g_sNesCardRegMapper28.nCHRBank = (nValue & 0x02) << 2;
		nesCardRegCHRBank8(g_sNesCardRegMapper28.nCHRBank);
	}
}
//@}

/** @name Mapper 29 - JALECO-2 */
//@{
/**
 * @struct nesSCardRegMapper29
 * @brief JALECO-2 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
	u32		nBankMode;			///< Bank Mode
}nesSCardRegMapper29;
nesSCardRegMapper29 g_sNesCardRegMapper29;

/** @brief Write Data to Card Register - JALECO-2 */
void nesCardRegMapper29(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	switch(nValue & 0xC0)
	{
	case 0x00:
		switch(g_sNesCardRegMapper29.nBankMode)
		{
		case 1:
			nesCardRegCHRBank8(g_sNesCardRegMapper29.nCHRBank);
			break;
		case 2:
			nesCardRegPRGBank16(g_sNesCardRegMapper29.nPRGBank, 0);
			break;
		}
		break;
	case 0x40:	// Select 16K ROM bank at 8000h-BFFFh
		g_sNesCardRegMapper29.nCHRBank = (nValue & 0x0F) * 8;
		g_sNesCardRegMapper29.nBankMode = 1;
		break;
	case 0x80:	// Select 8K VROM bank at PPU 0000h-1FFFh
		g_sNesCardRegMapper29.nPRGBank = (nValue & 0x0F) * 2;
		g_sNesCardRegMapper29.nBankMode = 2;
		break;
	case 0xC0:
		break;
	}
}
//@}

/** @name Mapper 30 - JALECO-3 */
//@{
/**
 * @struct nesSCardRegMapper30
 * @brief JALECO-3 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
	u32		nBankMode;			///< Bank Mode
}nesSCardRegMapper30;
nesSCardRegMapper30 g_sNesCardRegMapper30;

/** @brief Write Data to Card Register - JALECO-3 */
void nesCardRegMapper30(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	switch(nValue & 0xC0)
	{
	case 0x00:
		switch(g_sNesCardRegMapper30.nBankMode)
		{
		case 1:
			nesCardRegCHRBank8(g_sNesCardRegMapper30.nCHRBank);
			break;
		case 2:
			nesCardRegPRGBank16(g_sNesCardRegMapper30.nPRGBank, 2);
			break;
		}
		break;
	case 0x40:	// Select 8K VROM bank at PPU 0000h-1FFFh
		g_sNesCardRegMapper30.nCHRBank = (nValue & 0x0F) * 8;
		g_sNesCardRegMapper30.nBankMode = 1;
		break;
	case 0x80:	// Select 16K ROM bank at C000h-FFFFh
		g_sNesCardRegMapper30.nPRGBank = (nValue & 0x0F) * 2;
		g_sNesCardRegMapper30.nBankMode = 2;
		break;
	case 0xC0:
		break;
	}
}
//@}

/** @name Mapper 31 - JALECO-4 */
//@{
/**
 * @struct nesSCardRegMapper31
 * @brief JALECO-4 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper31;
nesSCardRegMapper31 g_sNesCardRegMapper31;

/** @brief Write Data to Card Register - JALECO-4 */
void nesCardRegMapper31(u16 nAddr, u8 nValue)
{
	if(nAddr == 0x6000)
	{
		// Bit6,1,0  Select 8K VROM bank at PPU 0000h-1FFFh
		g_sNesCardRegMapper31.nCHRBank = ((nValue & 0x03) | ((nValue>>4) & 0x04)) * 8;
		nesCardRegCHRBank8(g_sNesCardRegMapper31.nCHRBank);
		// Bit5,4    Select 32K ROM bank at 8000h-FFFFh
		g_sNesCardRegMapper31.nPRGBank = (nValue & 0x30) >> 2;
		nesCardRegPRGBank32(g_sNesCardRegMapper31.nPRGBank);
	}
	if(nAddr == 0x7000)
		nesSndRegWriteCard(nAddr, nValue);
}
//@}

/** @name Mapper 32 - JALECO-SS8806 */
//@{
/**
 * @struct nesSCardRegMapper32
 * @brief JALECO-SS8806 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	u32		nIRQWidth;			///< IRQ Count Bit Width
}nesSCardRegMapper32;
nesSCardRegMapper32 g_sNesCardRegMapper32;

/** @brief Write Data to Card Register - JALECO-SS8806 */
void nesCardRegMapper32(u16 nAddr, u8 nValue)
{
	nAddr &= 0xF003;
	switch(nAddr)
	{
	case 0x8000:	// Select 8K ROM at 8000h-9FFFh (Lower 4bits)
	case 0x8001:	// Select 8K ROM at 8000h-9FFFh (Upper 4bits)
	case 0x8002:	// Select 8K ROM at A000h-BFFFh (Lower 4bits)
	case 0x8003:	// Select 8K ROM at A000h-BFFFh (Upper 4bits)
	case 0x9000:	// Select 8K ROM at C000h-DFFFh (Lower 4bits)
	case 0x9001:	// Select 8K ROM at C000h-DFFFh (Upper 4bits)
		{
			u32 nID = ((nAddr - 0x8000) >> 11) + ((nAddr >> 1) & 0x01);
			if(nAddr & 0x01)
				g_sNesCardRegMapper32.nPRGBank[nID] = (g_sNesCardRegMapper32.nPRGBank[nID] & 0x0F) | ((nValue & 0x0F) << 4);
			else
				g_sNesCardRegMapper32.nPRGBank[nID] = (g_sNesCardRegMapper32.nPRGBank[nID] & 0xF0) | (nValue & 0x0F);
			nesCardRegPRGBank8(g_sNesCardRegMapper32.nPRGBank[nID], nID);
		}
		break;
	case 0x9002:	// Battery Back SRAM (Bit0: 0=Enable, 1=Disable)
		g_nNesCardSRAMEnable = !(nValue & 0x1);
		break;
	case 0x9003:	// Unknown
		break;
	case 0xA000:	// Select 1K VROM at PPU 0000h-03FFh (Lower 4bits)
	case 0xA001:	// Select 1K VROM at PPU 0000h-03FFh (Upper 4bits)
	case 0xA002:	// Select 1K VROM at PPU 0400h-07FFh (Lower 4bits)
	case 0xA003:	// Select 1K VROM at PPU 0400h-07FFh (Upper 4bits)
	case 0xB000:	// Select 1K VROM at PPU 0800h-0BFFh (Lower 4bits)
	case 0xB001:	// Select 1K VROM at PPU 0800h-0BFFh (Upper 4bits)
	case 0xB002:	// Select 1K VROM at PPU 0C00h-0FFFh (Lower 4bits)
	case 0xB003:	// Select 1K VROM at PPU 0C00h-0FFFh (Upper 4bits)
	case 0xC000:	// Select 1K VROM at PPU 1000h-13FFh (Lower 4bits)
	case 0xC001:	// Select 1K VROM at PPU 1000h-13FFh (Upper 4bits)
	case 0xC002:	// Select 1K VROM at PPU 1400h-17FFh (Lower 4bits)
	case 0xC003:	// Select 1K VROM at PPU 1400h-17FFh (Upper 4bits)
	case 0xD000:	// Select 1K VROM at PPU 1800h-1BFFh (Lower 4bits)
	case 0xD001:	// Select 1K VROM at PPU 1800h-1BFFh (Upper 4bits)
	case 0xD002:	// Select 1K VROM at PPU 1C00h-1FFFh (Lower 4bits)
	case 0xD003:	// Select 1K VROM at PPU 1C00h-1FFFh (Upper 4bits)
		{
			u32 nID = ((nAddr - 0xA000) >> 11) + ((nAddr >> 1) & 0x01);
			if(nAddr & 0x01)
				g_sNesCardRegMapper32.nCHRBank[nID] = (g_sNesCardRegMapper32.nCHRBank[nID] & 0x0F) | ((nValue & 0x0F) << 4);
			else
				g_sNesCardRegMapper32.nCHRBank[nID] = (g_sNesCardRegMapper32.nCHRBank[nID] & 0xF0) | (nValue & 0x0F);
			nesCardRegCHRBank1(g_sNesCardRegMapper32.nCHRBank[nID], nID);
		}
		break;
	case 0xE000:	// Lower 8bit of decrementing 16bit IRQ counter (Lower 4bits)
		g_sNesCardRegMapper32.nIRQInit = (g_sNesCardRegMapper32.nIRQInit & 0xFFF0) | (nValue & 0x0F);
		break;
	case 0xE001:	// Lower 8bit of decrementing 16bit IRQ counter (Upper 4bits)
		g_sNesCardRegMapper32.nIRQInit = (g_sNesCardRegMapper32.nIRQInit & 0xFF0F) | ((nValue & 0x0F) << 4);
		break;
	case 0xE002:	// Upper 8bit of decrementing 16bit IRQ counter (Lower 4bits)
		g_sNesCardRegMapper32.nIRQInit = (g_sNesCardRegMapper32.nIRQInit & 0xF0FF) | ((nValue & 0x0F) << 8);
		break;
	case 0xE003:	// Upper 8bit of decrementing 16bit IRQ counter (Upper 4bits)
		g_sNesCardRegMapper32.nIRQInit = (g_sNesCardRegMapper32.nIRQInit & 0x0FFF) | ((nValue & 0x0F) << 12);
		break;
	case 0xF000:	// IRQ Control Register 0
		g_nNesCardIRQTicks = g_sNesCardRegMapper32.nIRQInit & g_sNesCardRegMapper32.nIRQWidth;
		break;
	case 0xF001:	// IRQ Control Register 1
		g_nNesCpuIRQFlag = 0;
		g_nNesCardIRQEnable = (nValue & 0x1) * NES_CARD_IRQ_CPUCYCLE;
		switch((nValue >> 1) & 0x7)
		{
		case 0:	// 16bit
			g_sNesCardRegMapper32.nIRQWidth = 0xFFFF;
			break;
		case 1:	// 12bit
			g_sNesCardRegMapper32.nIRQWidth = 0x0FFF;
			break;
		case 2:	// 8bit
		case 3:
			g_sNesCardRegMapper32.nIRQWidth = 0x00FF;
			break;
		case 4:	// 4bit
		case 5:
		case 6:
		case 7:
			g_sNesCardRegMapper32.nIRQWidth = 0x000F;
			break;
		}
		g_nNesCardIRQTicks &= g_sNesCardRegMapper32.nIRQWidth;
		break;
	case 0xF002:	// Name Table Select (2bit)
		switch(nValue & 0x03)
		{
		case 0:
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
			break;
		case 1:
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
			break;
		case 2:
		case 3:
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
			break;
		}
		break;
	case 0xF003:	// Unused (or an External I/O Port which is unused?)
		break;
	}
}

/** @brief Update Card IRQ - JALECO-SS8806 */
void nesCardUpdateIRQMapper32()
{
	g_nNesCardIRQEnable = 0;
	g_nNesCpuIRQFlag = 1;
}
//@}

/** @name Mapper 33 - 74161 */
//@{
/**
 * @struct nesSCardRegMapper33
 * @brief 74161 Card Register
 */
typedef struct
{
	u32		nSubMapper;			///< Sub Mapper Type
	u32		nPRGBank;			///< PRG Bank
}nesSCardRegMapper33;
nesSCardRegMapper33 g_sNesCardRegMapper33;

/** @brief Write Data to Card Register - 74161 */
void nesCardRegMapper33(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	// Select 16K ROM at 8000h-BFFFh
	if(g_sNesCardRegMapper33.nSubMapper)
		g_sNesCardRegMapper33.nPRGBank = (nValue >> 1) & 0x0E;	// Senjou no Okami
	else
		g_sNesCardRegMapper33.nPRGBank = (nValue >> 3) & 0x0E;	// Fantasy Zone
	nesCardRegPRGBank16(g_sNesCardRegMapper33.nPRGBank, 0);
}
//@}

/** @name Mapper 35 - NAMCOT */
//@{
/**
 * @struct nesSCardRegMapper35
 * @brief NAMCOT Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank0[2];		///< CHR Bank
	u32		nCHRBank1[4];		///< CHR Bank
	u32		nCMD;				///< Command Index
}nesSCardRegMapper35;
nesSCardRegMapper35 g_sNesCardRegMapper35;

/** @brief Write Data to Card Register - NAMCOT */
void nesCardRegMapper35(u16 nAddr, u8 nValue)
{
	switch(nAddr & 0xE001)
	{
	case 0x8000:	// Index/Control (3bit)
		g_sNesCardRegMapper35.nCMD = nValue & 0x07;
		break;
	case 0x8001:	// Data Register (Indexed via Port 8000h)
		if(g_sNesCardRegMapper35.nCMD <= 5)
		{
			if(nValue & 0x20)
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			else
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
			nValue &= 0x1F;
		}
		switch(g_sNesCardRegMapper35.nCMD)
		{
		case 0:	// Select 2x1K VROM at PPU 0000h-07FFh
			g_sNesCardRegMapper35.nCHRBank0[0] = nValue;
			nesCardRegCHRBank2(g_sNesCardRegMapper35.nCHRBank0[0], 0);
			break;
		case 1:	// Select 2x1K VROM at PPU 0800h-0FFFh
			g_sNesCardRegMapper35.nCHRBank0[1] = nValue;
			nesCardRegCHRBank2(g_sNesCardRegMapper35.nCHRBank0[1], 2);
			break;
		case 2:	// Select 1K VROM at PPU 1000h-13FFh
			g_sNesCardRegMapper35.nCHRBank1[0] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper35.nCHRBank1[0], 4);
			break;
		case 3:	// Select 1K VROM at PPU 1400h-17FFh
			g_sNesCardRegMapper35.nCHRBank1[1] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper35.nCHRBank1[1], 5);
			break;
		case 4:	// Select 1K VROM at PPU 1800h-1BFFh
			g_sNesCardRegMapper35.nCHRBank1[2] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper35.nCHRBank1[2], 6);
			break;
		case 5:	// Select 1K VROM at PPU 1C00h-1FFFh
			g_sNesCardRegMapper35.nCHRBank1[3] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper35.nCHRBank1[3], 7);
			break;
		case 6:	// Select 8K ROM at 8000h-9FFFh
			g_sNesCardRegMapper35.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper35.nPRGBank[0], 0);
			break;
		case 7:	// Select 8K ROM at A000h-BFFFh
			g_sNesCardRegMapper35.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper35.nPRGBank[1], 1);
			break;
		}
		break;
	}
}
//@}

/** @name Mapper 36 - NAMCOT-106 */
//@{
/**
 * @struct nesSCardRegMapper36
 * @brief NAMCOT-106 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nCHRMode[2];		///< CHR Bank Mode
	u32		nNameTabMode[4];	///< Name Table Select
	u32		nSoundAddr;			///< Sound Register Address
	u32		nSoundAutoInc;		///< Sound Register Address Auto Increment
}nesSCardRegMapper36;
nesSCardRegMapper36 g_sNesCardRegMapper36;
u8*	g_pNesCardVRAMMapper36 = NULL;	///< VRAM

/** @brief Switch 1K CHR Bank - NAMCOT-106 */
void nesCardRegCHRBankMapper36(u32 nBank, u32 nStartBank)
{
	g_bNesGrpSPRChange |= 2;
	g_pNesCHRBank[nStartBank] = g_pNesCardVRAMMapper36 + nBank * NES_CARD_BANKSIZE_CHR;
}

/** @brief Write Data to Card Register - NAMCOT-106 */
void nesCardRegMapper36(u16 nAddr, u8 nValue)
{
	u32 n;
	u16 nIndex;
	nIndex = (nAddr >> 11) - 0x10;
	switch(nIndex)
	{
	case 0x0:	// Pattern Table Control:	8000h-87FFh  Select 1K VROM at PPU 0000h-03FFh
	case 0x1:	// Pattern Table Control:	8800h-8FFFh  Select 1K VROM at PPU 0400h-07FFh
	case 0x2:	// Pattern Table Control:	9000h-97FFh  Select 1K VROM at PPU 0800h-0BFFh
	case 0x3:	// Pattern Table Control:	9800h-9FFFh  Select 1K VROM at PPU 0C00h-0FFFh
	case 0x4:	// Pattern Table Control:	A000h-A7FFh  Select 1K VROM at PPU 1000h-13FFh
	case 0x5:	// Pattern Table Control:	A800h-AFFFh  Select 1K VROM at PPU 1400h-17FFh
	case 0x6:	// Pattern Table Control:	B000h-B7FFh  Select 1K VROM at PPU 1800h-1BFFh
	case 0x7:	// Pattern Table Control:	B800h-BFFFh  Select 1K VROM at PPU 1C00h-1FFFh
		g_sNesCardRegMapper36.nCHRBank[nIndex] = nValue;
		if(g_sNesCardRegMapper36.nCHRMode[nIndex>>2] || (nValue < 0xE0))
			nesCardRegCHRBank1(g_sNesCardRegMapper36.nCHRBank[nIndex], 0);
		else
			nesCardRegCHRBankMapper36(g_sNesCardRegMapper36.nCHRBank[nIndex] - 0xE0, 0);
		return;
	case 0x8:	// Name Table Control:		C000h-C7FFh  Select 1K VROM/VRAM at PPU 2000h-23FFh (E0h and up = VRAM)
	case 0x9:	// Name Table Control:		C800h-CFFFh  Select 1K VROM/VRAM at PPU 2400h-27FFh (E0h and up = VRAM)
	case 0xA:	// Name Table Control:		D000h-D7FFh  Select 1K VROM/VRAM at PPU 2800h-2BFFh (E0h and up = VRAM)
	case 0xB:	// Name Table Control:		D800h-DFFFh  Select 1K VROM/VRAM at PPU 2C00h-2FFFh (E0h and up = VRAM)
		nIndex -= 8;
		g_sNesCardRegMapper36.nNameTabMode[nIndex] = nValue;
		if(nValue < 0xE0)
			g_pNesGrpNameTab[nIndex] = g_pNesCHRROM + nValue * NES_CARD_BANKSIZE_CHR;
		else
			g_pNesGrpNameTab[nIndex] = g_pNesVRAM + (nValue & 0x1) * NES_CARD_BANKSIZE_CHR;
		return;
	case 0xC:	// CPU Memory Control:		E000h-E7FFh  Select 8K ROM at 8000h-9FFFh
		g_sNesCardRegMapper36.nPRGBank[0] = nValue & 0x3F;
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[0], 0);
		return;
	case 0xD:	// CPU Memory Control:		E800h-EFFFh  Select 8K ROM at A000h-BFFFh
		if(g_sNesCardRegMapper36.nCHRMode[0] != (nValue & 0x40))
		{
			g_sNesCardRegMapper36.nCHRMode[0] = nValue & 0x40;
			for(n=0; n<4; ++n)
			{
				if(g_sNesCardRegMapper36.nCHRMode[n] || (g_sNesCardRegMapper36.nCHRBank[n] < 0xE0))
					nesCardRegCHRBank1(g_sNesCardRegMapper36.nCHRBank[n], 0);
				else
					nesCardRegCHRBankMapper36(g_sNesCardRegMapper36.nCHRBank[n] - 0xE0, 0);
			}
		}
		if(g_sNesCardRegMapper36.nCHRMode[1] != (nValue & 0x80))
		{
			g_sNesCardRegMapper36.nCHRMode[1] = nValue & 0x80;
			for(n=4; n<8; ++n)
			{
				if(g_sNesCardRegMapper36.nCHRMode[n] || (g_sNesCardRegMapper36.nCHRBank[n] < 0xE0))
					nesCardRegCHRBank1(g_sNesCardRegMapper36.nCHRBank[n], 0);
				else
					nesCardRegCHRBankMapper36(g_sNesCardRegMapper36.nCHRBank[n] - 0xE0, 0);
			}
		}
		g_sNesCardRegMapper36.nPRGBank[1] = nValue & 0x3F;
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[1], 1);
		return;
	case 0xE:	// CPU Memory Control:		F000h-F7FFh  Select 8K ROM at C000h-DFFFh
		g_sNesCardRegMapper36.nPRGBank[2] = nValue & 0x3F;
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[2], 2);
		return;
	case 0xF:	// Sound Control:			F800h Expand I/O Address Register
		if(nAddr == 0xF800)
		{
			g_sNesCardRegMapper36.nSoundAutoInc = nValue & 0x80;
			g_sNesCardRegMapper36.nSoundAddr = nValue & 0x7F;
		}
		return;
	}
}

/** @brief Read Data to Card Register - NAMCOT-106 */
u8 nesCardRegMapper36Read(u16 nAddr)
{
	switch(nAddr & 0xF800)
	{
	case 0x5000:	// IRQ Control:			5000h-57FFh  Bit7-0: Lower 8bit of 15bit IRQ counter
		return g_nNesCardIRQTicks & 0xFF;
	case 0x5800:	// IRQ Control:			5800h-5FFFh  Bit6-0: Upper 7bit of 15bit IRQ counter
		return (g_nNesCardIRQTicks >> 8) & 0x7F;
	}
	return 0;
}

/** @brief Write Data to Card Register - NAMCOT-106 */
void nesCardRegMapper36Write(u16 nAddr, u8 nValue)
{
	switch(nAddr & 0xF800)
	{
	case 0x4800:	// Sound Control:		4800h Expand I/O Data Register
		if(nAddr == 0x4800)
		{
			// Sound Func............
			if(g_sNesCardRegMapper36.nSoundAutoInc)
			{
				g_sNesCardRegMapper36.nSoundAddr++;
				g_sNesCardRegMapper36.nSoundAddr &= 0x7F;
			}
		}
		return;
	case 0x5000:	// IRQ Control:			5000h-57FFh  Bit7-0: Lower 8bit of 15bit IRQ counter
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0x7F00) + nValue;
		g_nNesCpuIRQFlag = 0;
		return;
	case 0x5800:	// IRQ Control:			5800h-5FFFh  Bit6-0: Upper 7bit of 15bit IRQ counter  Bit7:   0=Disable IRQs, 1=Enable IRQs
		g_nNesCardIRQTicks = (g_nNesCardIRQTicks & 0x00FF) + ((nValue & 0x7F) << 8);
		g_nNesCardIRQEnable = (nValue & 0x80) ? NES_CARD_IRQ_CPUCYCLE : 0;
		g_nNesCpuIRQFlag = 0;
		return;
	}
}

/** @brief Update Card IRQ - NAMCOT-106 */
void nesCardUpdateIRQMapper36()
{
	g_nNesCardIRQTicks = 0x7FFF;
	g_nNesCardIRQEnable = 0;
	g_nNesCpuIRQFlag = 1;
}
//@}

/** @name Mapper 37 - NAMCO-109 */
//@{
/**
 * @struct nesSCardRegMapper37
 * @brief NAMCO-109 Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[4];		///< CHR Bank
	u32		nCMD;				///< Command Index
}nesSCardRegMapper37;
nesSCardRegMapper37 g_sNesCardRegMapper37;

/** @brief Write Data to Card Register - NAMCO-109 */
void nesCardRegMapper37(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Index/Control (3bit)
		g_sNesCardRegMapper37.nCMD = nValue & 0x07;
		break;
	case 0x8001:	// Data Register (Indexed via Port 8000h)
		switch(g_sNesCardRegMapper37.nCMD)
		{
		case 2:	// Select 2K VROM at PPU 0000h-07FFh
			g_sNesCardRegMapper37.nCHRBank[0] = nValue * 2;
			nesCardRegCHRBank2(g_sNesCardRegMapper37.nCHRBank[0], 0);
			break;
		case 3:	// Select 2K VROM at PPU 0800h-0FFFh
			g_sNesCardRegMapper37.nCHRBank[1] = nValue * 2;
			nesCardRegCHRBank1(g_sNesCardRegMapper37.nCHRBank[1], 2);
			break;
		case 4:	// Select 2K VROM at PPU 1000h-17FFh
			g_sNesCardRegMapper37.nCHRBank[2] = nValue * 2;
			nesCardRegCHRBank1(g_sNesCardRegMapper37.nCHRBank[2], 4);
			break;
		case 5:	// Select 2K VROM at PPU 1800h-1FFFh
			g_sNesCardRegMapper37.nCHRBank[3] = nValue * 2;
			nesCardRegCHRBank1(g_sNesCardRegMapper37.nCHRBank[3], 6);
			break;
		case 6:	// Select 8K ROM at 8000h-9FFFh
			g_sNesCardRegMapper37.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper37.nPRGBank[0], 0);
			break;
		case 7:	// Select 8K ROM at A000h-BFFFh
			g_sNesCardRegMapper37.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper37.nPRGBank[1], 1);
			break;
		}
		break;
	}
}
//@}

/** @name Mapper 38 - NAMCO-118 */
//@{
/**
 * @struct nesSCardRegMapper38
 * @brief NAMCO-118 Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank0[2];		///< CHR Bank
	u32		nCHRBank1[4];		///< CHR Bank
	u32		nCMD;				///< Command Index
}nesSCardRegMapper38;
nesSCardRegMapper38 g_sNesCardRegMapper38;

/** @brief Write Data to Card Register - NAMCO-118 */
void nesCardRegMapper38(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Index/Control (3bit)
		g_sNesCardRegMapper38.nCMD = nValue & 0x07;
		break;
	case 0x8001:	// Data Register (Indexed via Port 8000h)
		switch(g_sNesCardRegMapper38.nCMD)
		{
		case 0:	// Select 2x1K VROM at PPU 0000h-07FFh (Banks 0-63)
			g_sNesCardRegMapper38.nCHRBank0[0] = nValue;
			nesCardRegCHRBank2(g_sNesCardRegMapper38.nCHRBank0[0], 0);
			break;
		case 1:	// Select 2x1K VROM at PPU 0800h-0FFFh (Banks 0-63)
			g_sNesCardRegMapper38.nCHRBank0[1] = nValue;
			nesCardRegCHRBank2(g_sNesCardRegMapper38.nCHRBank0[1], 2);
			break;
		case 2:	// Select 1K VROM at PPU 1000h-13FFh   (Banks 64-127)
			g_sNesCardRegMapper38.nCHRBank1[0] = nValue + 64;
			nesCardRegCHRBank1(g_sNesCardRegMapper38.nCHRBank1[0], 4);
			break;
		case 3:	// Select 1K VROM at PPU 1400h-17FFh   (Banks 64-127)
			g_sNesCardRegMapper38.nCHRBank1[1] = nValue + 64;
			nesCardRegCHRBank1(g_sNesCardRegMapper38.nCHRBank1[1], 5);
			break;
		case 4:	// Select 1K VROM at PPU 1800h-1BFFh   (Banks 64-127)
			g_sNesCardRegMapper38.nCHRBank1[2] = nValue + 64;
			nesCardRegCHRBank1(g_sNesCardRegMapper38.nCHRBank1[2], 6);
			break;
		case 5:	// Select 1K VROM at PPU 1C00h-1FFFh   (Banks 64-127)
			g_sNesCardRegMapper38.nCHRBank1[3] = nValue + 64;
			nesCardRegCHRBank1(g_sNesCardRegMapper38.nCHRBank1[3], 7);
			break;
		case 6:	// Select 8K ROM at 8000h-9FFFh
			g_sNesCardRegMapper38.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper38.nPRGBank[0], 0);
			break;
		case 7:	// Select 8K ROM at A000h-BFFFh
			g_sNesCardRegMapper38.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper38.nPRGBank[1], 1);
			break;
		}
		break;
	}
}
//@}

/** @name Mapper 39 - MMC-3+TLS */
//@{
/**
 * @struct nesSCardRegMapper39
 * @brief MMC-3+TLS Card Register
 */
typedef struct
{
	u32		nBankMode;			///< Bank Command Number
	u32		nPRGArea;			///< PRG Address Select
	u32		nCHRArea;			///< CHR Address Select
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	s32		nIRQCount;			///< IRQ Count Value
}nesSCardRegMapper39;
nesSCardRegMapper39 g_sNesCardRegMapper39;

/** @brief Write Data to Card Register - MMC-3+TLS */
void nesCardRegMapper39(u16 nAddr, u8 nValue)
{
	switch(nAddr & 0xE001)
	{
	case 0x8000:
		g_sNesCardRegMapper39.nBankMode = nValue & 0x7;
		g_sNesCardRegMapper39.nPRGArea = (nValue>>5) & 2;
		g_sNesCardRegMapper39.nCHRArea = (nValue>>7) * 4;
		nesCardRegPRGBank8(g_sNesCardRegMapper39.nPRGBank[0], g_sNesCardRegMapper39.nPRGArea);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks-2, 2-g_sNesCardRegMapper39.nPRGArea);
		break;
	case 0x8001:	// Data Register    (Indexed via Port 8000h)

		//comment by yuans:
		// Mirroring Select
		if(g_sNesCardRegMapper39.nCHRArea)
		{
			if(g_sNesCardRegMapper39.nBankMode == 2)
			{
				if(nValue & 0x80)
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				else
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			}
		}
		else
		{
			if(g_sNesCardRegMapper39.nBankMode == 0)
			{
				if(nValue & 0x80)
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				else
					nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
			}
		}
		//end of comment

		switch(g_sNesCardRegMapper39.nBankMode)
		{
		case 0:			// Select 2x1K VROM at PPU 0000h-07FFh (or 1000h-17FFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[g_sNesCardRegMapper39.nCHRArea] = nValue;
			g_sNesCardRegMapper39.nCHRBank[g_sNesCardRegMapper39.nCHRArea+1] = nValue+1;
			nesCardRegCHRBank2(nValue, g_sNesCardRegMapper39.nCHRArea);
			break;
		case 1:			// Select 2x1K VROM at PPU 0800h-0FFFh (or 1800h-1FFFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[g_sNesCardRegMapper39.nCHRArea+2] = nValue;
			g_sNesCardRegMapper39.nCHRBank[g_sNesCardRegMapper39.nCHRArea+3] = nValue+1;
			nesCardRegCHRBank2(nValue, g_sNesCardRegMapper39.nCHRArea+2);
			break;
		case 2:			// Select 1K VROM at PPU 1000h-13FFh   (or 0000h-03FFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[4-g_sNesCardRegMapper39.nCHRArea] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper39.nCHRArea);
			break;
		case 3:			// Select 1K VROM at PPU 1400h-17FFh   (or 0400h-07FFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[4-g_sNesCardRegMapper39.nCHRArea+1] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper39.nCHRArea+1);
			break;
		case 4:			// Select 1K VROM at PPU 1800h-1BFFh   (or 0800h-0BFFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[4-g_sNesCardRegMapper39.nCHRArea+2] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper39.nCHRArea+2);
			break;
		case 5:			// Select 1K VROM at PPU 1C00h-1FFFh   (or 0C00h-0FFFh, if Bit7=1)
			g_sNesCardRegMapper39.nCHRBank[4-g_sNesCardRegMapper39.nCHRArea+3] = nValue;
			nesCardRegCHRBank1(nValue, 4-g_sNesCardRegMapper39.nCHRArea+3);
			break;
		case 6:			// Select 8K ROM at 8000h-9FFFh (or C000h-DFFFh, if Bit6=1)
			g_sNesCardRegMapper39.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper39.nPRGBank[0], g_sNesCardRegMapper39.nPRGArea);
			break;
		case 7:			// Select 8K ROM at A000h-BFFFh
			g_sNesCardRegMapper39.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper39.nPRGBank[1], 1);
			break;
		}
		break;

		/*
		//add by yuans: test
    case 0xA000:	// Mirroring Select
		if(nValue&0x1)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	case 0xA001:	// SaveRAM Toggle   (Bit7: 0=Disable 6000h-7FFFh, 1=Enable 6000h-7FFFh)
		g_nNesCardSRAMEnable = (nValue & 0x80) >> 7;
		break;
		//end of add
		*/

	case 0xC000:	// IRQ Counter Register - The IRQ countdown value is stored here.		
		g_sNesCardRegMapper39.nIRQCount = nValue;		
		break;
	case 0xC001:	// IRQ Latch Register - A temporary value is stored here.
		g_sNesCardRegMapper39.nIRQInit = nValue;
		break;
	case 0xE000:	// IRQ Control Register 0 - Any value written here will disable IRQ's and copy the latch register to the actual IRQ counter register.
		g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag = 0;
		g_sNesCardRegMapper39.nIRQCount = g_sNesCardRegMapper39.nIRQInit;		
		break;
	case 0xE001:	// IRQ Control Register 1 - Any value written here will enable IRQ's.
		g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINE;
		break;
	}
}

/** @brief Update Card IRQ - MMC-3+TLS */
void nesCardUpdateIRQMapper39()
{
	g_sNesCardRegMapper39.nIRQCount--;
	if(g_sNesCardRegMapper39.nIRQCount <= 0)
	{
		g_sNesCardRegMapper39.nIRQCount = g_sNesCardRegMapper39.nIRQInit;		
		g_nNesCpuIRQFlag = 1;
	}
}
//@}

/** @name Mapper 40 - TAITO-TC0190 */
//@{
/**
 * @struct nesSCardRegMapper40
 * @brief TAITO-TC0190 Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[6];		///< CHR Bank
}nesSCardRegMapper40;
nesSCardRegMapper40 g_sNesCardRegMapper40;

/** @brief Write Data to Card Register - TAITO-TC0190 */
void nesCardRegMapper40(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Select 8K ROM bank at 8000h-9FFFh, Bit6=Mirroring
		if(nValue & 0x40)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		g_sNesCardRegMapper40.nPRGBank[0] = nValue & 0x1F;
		nesCardRegPRGBank8(g_sNesCardRegMapper40.nPRGBank[0], 0);
		break;
	case 0x8001:	// Select 8K ROM bank at A000h-BFFFh
		g_sNesCardRegMapper40.nPRGBank[1] = nValue & 0x1F;
		nesCardRegPRGBank8(g_sNesCardRegMapper40.nPRGBank[1], 1);
		break;
	case 0x8002:	// Select 2K VROM bank at PPU 0000h-07FFh
		g_sNesCardRegMapper40.nCHRBank[0] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper40.nCHRBank[0], 0);
		break;
	case 0x8003:	// Select 2K VROM bank at PPU 0800h-0FFFh
		g_sNesCardRegMapper40.nCHRBank[1] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper40.nCHRBank[1], 2);
		break;
	case 0xA000:	// Select 1K VROM bank at PPU 1000h-13FFh
		g_sNesCardRegMapper40.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper40.nCHRBank[2], 4);
		break;
	case 0xA001:	// Select 1K VROM bank at PPU 1400h-17FFh
		g_sNesCardRegMapper40.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper40.nCHRBank[3], 5);
		break;
	case 0xA002:	// Select 1K VROM bank at PPU 1800h-1BFFh
		g_sNesCardRegMapper40.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper40.nCHRBank[4], 6);
		break;
	case 0xA003:	// Select 1K VROM bank at PPU 1C00h-1FFFh
		g_sNesCardRegMapper40.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper40.nCHRBank[5], 7);
		break;
	}
}
//@}

/** @name Mapper 41 - TAITO-TC0350 */
//@{
/**
 * @struct nesSCardRegMapper41
 * @brief TAITO-TC0350 Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[6];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Count Init Value
	s32		nIRQCount;			///< IRQ Count Value
}nesSCardRegMapper41;
nesSCardRegMapper41 g_sNesCardRegMapper41;

/** @brief Write Data to Card Register - TAITO-TC0350 */
void nesCardRegMapper41(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Select 8K ROM bank at 8000h-9FFFh
		g_sNesCardRegMapper41.nPRGBank[0] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper41.nPRGBank[0], 0);
		break;
	case 0x8001:	// Select 8K ROM bank at A000h-BFFFh
		g_sNesCardRegMapper41.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper41.nPRGBank[1], 1);
		break;
	case 0x8002:	// Select 2K VROM bank at PPU 0000h-07FFh
		g_sNesCardRegMapper41.nCHRBank[0] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper41.nCHRBank[0], 0);
		break;
	case 0x8003:	// Select 2K VROM bank at PPU 0800h-0FFFh
		g_sNesCardRegMapper41.nCHRBank[1] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper41.nCHRBank[1], 2);
		break;
	case 0xA000:	// Select 1K VROM bank at PPU 1000h-13FFh
		g_sNesCardRegMapper41.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper41.nCHRBank[2], 4);
		break;
	case 0xA001:	// Select 1K VROM bank at PPU 1400h-17FFh
		g_sNesCardRegMapper41.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper41.nCHRBank[3], 5);
		break;
	case 0xA002:	// Select 1K VROM bank at PPU 1800h-1BFFh
		g_sNesCardRegMapper41.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper41.nCHRBank[4], 6);
		break;
	case 0xA003:	// Select 1K VROM bank at PPU 1C00h-1FFFh
		g_sNesCardRegMapper41.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper41.nCHRBank[5], 7);
		break;
	case 0xC000:	// IRQ Counter
		g_sNesCardRegMapper41.nIRQCount = nValue;
		break;
	case 0xC001:	// IRQ Related
		g_sNesCardRegMapper41.nIRQInit = nValue;
		break;
	case 0xC002:	// IRQ Start/Enable
		g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINE;
		break;
	case 0xC003:	// IRQ Acknowledge/Stop
		g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag = 0;
		g_sNesCardRegMapper41.nIRQCount = g_sNesCardRegMapper41.nIRQInit;
		break;
	case 0xE000:	// Mirroring
		if(nValue & 0x40)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	}
}

/** @brief Update Card IRQ - TAITO-TC0350 */
void nesCardUpdateIRQMapper41()
{
	g_sNesCardRegMapper41.nIRQCount++;
	if(g_sNesCardRegMapper41.nIRQCount == 0x100)
	{
		g_nNesCardIRQEnable = 0;
		g_sNesCardRegMapper41.nIRQCount = g_sNesCardRegMapper41.nIRQInit;		
		g_nNesCpuIRQFlag = 1;
	}	
}
//@}

/** @name Mapper 42 - TAITO-TC190V */
//@{
/**
 * @struct nesSCardRegMapper42
 * @brief TAITO-TC190V Card Register
 */
typedef struct
{
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[6];		///< CHR Bank
	s32		nIRQCount;			///< IRQ Count Value
}nesSCardRegMapper42;
nesSCardRegMapper42 g_sNesCardRegMapper42;

/** @brief Write Data to Card Register - TAITO-TC190V */
void nesCardRegMapper42(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Select 8K ROM bank at 8000h-9FFFh, Bit6=Mirroring
		g_sNesCardRegMapper42.nPRGBank[0] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper42.nPRGBank[0], 0);
		break;
	case 0x8001:	// Select 8K ROM bank at A000h-BFFFh
		g_sNesCardRegMapper42.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper42.nPRGBank[1], 1);
		break;
	case 0x8002:	// Select 2K VROM bank at PPU 0000h-07FFh
		g_sNesCardRegMapper42.nCHRBank[0] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper42.nCHRBank[0], 0);
		break;
	case 0x8003:	// Select 2K VROM bank at PPU 0800h-0FFFh
		g_sNesCardRegMapper42.nCHRBank[1] = nValue*2;
		nesCardRegCHRBank2(g_sNesCardRegMapper42.nCHRBank[1], 2);
		break;
	case 0xA000:	// Select 1K VROM bank at PPU 1000h-13FFh
		g_sNesCardRegMapper42.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper42.nCHRBank[2], 4);
		break;
	case 0xA001:	// Select 1K VROM bank at PPU 1400h-17FFh
		g_sNesCardRegMapper42.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper42.nCHRBank[3], 5);
		break;
	case 0xA002:	// Select 1K VROM bank at PPU 1800h-1BFFh
		g_sNesCardRegMapper42.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper42.nCHRBank[4], 6);
		break;
	case 0xA003:	// Select 1K VROM bank at PPU 1C00h-1FFFh
		g_sNesCardRegMapper42.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper42.nCHRBank[5], 7);
		break;
	case 0xC000:	// IRQ Counter
		g_sNesCardRegMapper42.nIRQCount = nValue;
		g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag = 0;
		break;
	case 0xC001:	// IRQ Related
		g_sNesCardRegMapper42.nIRQCount = nValue;
		g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINE;
		break;
	case 0xE000:	// Mirroring
		if(nValue & 0x40)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		break;
	}
}

/** @brief Update Card IRQ - TAITO-TC190V */
void nesCardUpdateIRQMapper42()
{
	g_sNesCardRegMapper42.nIRQCount++;
	if(g_sNesCardRegMapper42.nIRQCount == 0x100)
	{
		g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag = 1;
	}	
}
//@}

/** @name Mapper 43 - TAITO-X-005 */
//@{
/**
 * @struct nesSCardRegMapper43
 * @brief TAITO-X-005 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[6];		///< CHR Bank
	u32		nMapFlag;			///< Name Table Map Flag
}nesSCardRegMapper43;
nesSCardRegMapper43 g_sNesCardRegMapper43;

/** @brief Write Data to Card Register - TAITO-X-005 */
void nesCardRegMapper43(u16 nAddr, u8 nValue)
{
	if(nAddr >= 0x7F00)
	{
		g_pNesSRAMBank[nAddr&0x1FFF] = nValue;
		if(g_pNesROMHeader->nBattery)
			g_pNesEmuBuf->nSaveUpdate |= 1;
	}
	else
	{
		switch(nAddr)
		{
		case 0x7EF0:	// Select 2x1K VROM at PPU 0000h-07FF
			g_sNesCardRegMapper43.nMapFlag = (g_sNesCardRegMapper43.nMapFlag & 0x02) | (nValue >> 7);
			switch(g_sNesCardRegMapper43.nMapFlag)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			case 3:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			}
			g_sNesCardRegMapper43.nCHRBank[0] = nValue & 0x7F;
			nesCardRegCHRBank2(g_sNesCardRegMapper43.nCHRBank[0], 0);
			break;
		case 0x7EF1:	// Select 2x1K VROM at PPU 0800h-0FFF
			g_sNesCardRegMapper43.nMapFlag = (g_sNesCardRegMapper43.nMapFlag & 0x01) | ((nValue >> 6) & 0x02);
			switch(g_sNesCardRegMapper43.nMapFlag)
			{
			case 0:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);
				break;
			case 3:
				nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);
				break;
			}
			g_sNesCardRegMapper43.nCHRBank[1] = nValue & 0x7F;
			nesCardRegCHRBank2(g_sNesCardRegMapper43.nCHRBank[1], 2);
			break;
		case 0x7EF2:	// Select 1K VROM at PPU 1000h-13FFh
			g_sNesCardRegMapper43.nCHRBank[2] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper43.nCHRBank[2], 4);
			break;
		case 0x7EF3:	// Select 1K VROM at PPU 1400h-17FFh
			g_sNesCardRegMapper43.nCHRBank[3] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper43.nCHRBank[3], 5);
			break;
		case 0x7EF4:	// Select 1K VROM at PPU 1800h-1BFFh
			g_sNesCardRegMapper43.nCHRBank[4] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper43.nCHRBank[4], 6);
			break;
		case 0x7EF5:	// Select 1K VROM at PPU 1C00h-1FFFh
			g_sNesCardRegMapper43.nCHRBank[5] = nValue;
			nesCardRegCHRBank1(g_sNesCardRegMapper43.nCHRBank[5], 7);
			break;
		case 0x7EF6:	// Name Table
			if(nValue & 0x01)
				nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
			else
				nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
			break;
		case 0x7EFA:	// Select 8K ROM 8000h-9FFFh
		case 0x7EFB:
			g_sNesCardRegMapper43.nPRGBank[0] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper43.nPRGBank[0], 0);
			break;
		case 0x7EFC:	// Select 8K ROM A000h-BFFFh
		case 0x7EFD:
			g_sNesCardRegMapper43.nPRGBank[1] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper43.nPRGBank[1], 1);
			break;
		case 0x7EFE:	// Select 8K ROM C000h-DFFFh
		case 0x7EFF:
			g_sNesCardRegMapper43.nPRGBank[2] = nValue;
			nesCardRegPRGBank8(g_sNesCardRegMapper43.nPRGBank[2], 2);
			break;
		}
	}
}
//@}

/** @name Mapper 44 - TAITO-X1-17 */
//@{
/**
 * @struct nesSCardRegMapper44
 * @brief TAITO-X1-17 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[6];		///< CHR Bank
	u32		nSwap;				///< Swap Flag
}nesSCardRegMapper44;
nesSCardRegMapper44 g_sNesCardRegMapper44;

/** @brief Write Data to Card Register - TAITO-X1-17 */
void nesCardRegMapper44(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x7EF0:	// Select 2x1K VROM at PPU 0000h-07FF
		g_sNesCardRegMapper44.nCHRBank[0] = nValue;
		nesCardRegCHRBank2(g_sNesCardRegMapper44.nCHRBank[0], 0+g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF1:	// Select 2x1K VROM at PPU 0800h-0FFF
		g_sNesCardRegMapper44.nCHRBank[1] = nValue;
		nesCardRegCHRBank2(g_sNesCardRegMapper44.nCHRBank[1], 2+g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF2:	// Select 1K VROM at PPU 1000h-13FFh
		g_sNesCardRegMapper44.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper44.nCHRBank[2], 4-g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF3:	// Select 1K VROM at PPU 1400h-17FFh
		g_sNesCardRegMapper44.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper44.nCHRBank[3], 5-g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF4:	// Select 1K VROM at PPU 1800h-1BFFh
		g_sNesCardRegMapper44.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper44.nCHRBank[4], 6-g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF5:	// Select 1K VROM at PPU 1C00h-1FFFh
		g_sNesCardRegMapper44.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper44.nCHRBank[5], 7-g_sNesCardRegMapper44.nSwap);
		break;
	case 0x7EF6:	// Name Table
		g_sNesCardRegMapper44.nSwap = (nValue & 0x02) * 2;
		if(nValue & 0x01)
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		break;
	case 0x7EFA:	// Select 8K ROM 8000h-9FFFh
		g_sNesCardRegMapper44.nPRGBank[0] = nValue>>2;
		nesCardRegPRGBank8(g_sNesCardRegMapper44.nPRGBank[0], 0);
		break;
	case 0x7EFB:	// Select 8K ROM A000h-BFFFh
		g_sNesCardRegMapper44.nPRGBank[1] = nValue>>2;
		nesCardRegPRGBank8(g_sNesCardRegMapper44.nPRGBank[1], 1);
		break;
	case 0x7EFC:	// Select 8K ROM C000h-DFFFh
		g_sNesCardRegMapper44.nPRGBank[2] = nValue>>2;
		nesCardRegPRGBank8(g_sNesCardRegMapper44.nPRGBank[2], 2);
		break;
	default:		// SRAM
		g_pNesSRAMBank[nAddr&0x1FFF] = nValue;
		if(g_pNesROMHeader->nBattery)
			g_pNesEmuBuf->nSaveUpdate |= 1;
		break;
	}
}
//@}

/** @name Mapper 45 - IREM-1 */
//@{
/**
 * @struct nesSCardRegMapper45
 * @brief IREM-1 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper45;
nesSCardRegMapper45 g_sNesCardRegMapper45;
u8*	g_pNesCardVRAMMapper45 = NULL;	///< VRAM

/** @brief Write Data to Card Register - IREM-1 */
void nesCardRegMapper45(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	// Bit0-2  Select 32K ROM bank at 8000h-FFFFh
	g_sNesCardRegMapper45.nPRGBank = (nValue & 0x7) * 4;
	nesCardRegPRGBank32(g_sNesCardRegMapper45.nPRGBank);
	nesCardUpdatePC();

	// Bit4-7  Select 2K VROM bank at PPU 0000h-07FFh
	g_sNesCardRegMapper45.nCHRBank = (nValue>>4) * 2;
	nesCardRegCHRBank2(g_sNesCardRegMapper45.nCHRBank, 0);
}
//@}

/** @name Mapper 46 - IREM-2 */
//@{
/**
 * @struct nesSCardRegMapper46
 * @brief IREM-2 Card Register
 */
typedef struct
{
	u32		nPRGBank;			///< PRG Bank
}nesSCardRegMapper46;
nesSCardRegMapper46 g_sNesCardRegMapper46;

/** @brief Write Data to Card Register - IREM-2 */
void nesCardRegMapper46(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	// Bit0-3  Select 16K ROM bank at C000h-FFFFh
	g_sNesCardRegMapper46.nPRGBank = (nValue & 0x0F) * 2;
	nesCardRegPRGBank16(g_sNesCardRegMapper46.nPRGBank, 2);

	// Bit7    Name Table Mirroring
	if( nValue & 0x80 )
		nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);		// Vertical Mirroring
	else
		nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);		// Horizontal Mirroring
}
//@}

/** @name Mapper 47 - IREM-74HC161/32 */
//@{
/**
 * @struct nesSCardRegMapper47
 * @brief IREM-74HC161/32 Card Register
 */
typedef struct
{
	u32		nSubMapper;			///< Sub Mapper Type
	u32		nPRGBank;			///< PRG Bank
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper47;
nesSCardRegMapper47 g_sNesCardRegMapper47;

/** @brief Write Data to Card Register - IREM-74HC161/32 */
void nesCardRegMapper47(u16 nAddr, u8 nValue)
{
	(void)nAddr;
	// Bit0-2 Select 16K ROM bank at 8000h-BFFFh
	g_sNesCardRegMapper47.nPRGBank = (nValue & 0x7) * 2;
	nesCardRegPRGBank16(g_sNesCardRegMapper47.nPRGBank, 0);

	// Bit3   Name Table Control
	if(g_sNesCardRegMapper47.nSubMapper)
	{
		if(nValue & 0x08)	// One-Screen
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE1);	// Single-Screen BLK1
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_SINGLE0);	// Single-Screen BLK0
	}
	else
	{
		if(nValue & 0x08)	// Two-Screen
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);		// Vertical Mirroring
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);		// Horizontal Mirroring
	}

	// Bit4-7 Select 8K VROM bank at PPU 0000h-1FFFh
	g_sNesCardRegMapper47.nCHRBank = (nValue>>4) * 8;
	nesCardRegCHRBank8(g_sNesCardRegMapper47.nCHRBank);
}
//@}

/** @name Mapper 49 - IREM-G-101 */
//@{
/**
 * @struct nesSCardRegMapper49
 * @brief IREM-G-101 Card Register
 */
typedef struct
{
	u32		nPRGMode;			///< PRG Switching Mode
	u32		nPRGBank[2];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
}nesSCardRegMapper49;
nesSCardRegMapper49 g_sNesCardRegMapper49;

/** @brief Write Data to Card Register - IREM-G-101 */
void nesCardRegMapper49(u16 nAddr, u8 nValue)
{
	switch( nAddr & 0xF000 )
	{
	case 0x8000:
		g_sNesCardRegMapper49.nPRGBank[0] = nValue;
		if(g_sNesCardRegMapper49.nPRGMode)	// Select 8K ROM bank at C000h-DFFFh
		{
			nesCardRegPRGBank8(0, 0);
			nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[0], 2);
		}
		else								// Select 8K ROM bank at 8000h-9FFFh
		{
			nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[0], 0);
			nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2);
		}
		break;
	case 0x9000:	// Control Register (Bit1,0)
		// Bit0 - Name Table Mirroring
		if(nValue & 0x01)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);		// Horizontal Mirroring
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);		// Vertical Mirroring
		// Bit1 - Port 8000h Switching Mode
		g_sNesCardRegMapper49.nPRGMode = nValue & 0x02;
		break;
	case 0xA000:	// Select 8K ROM bank at A000h-BFFFh
		g_sNesCardRegMapper49.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[1], 1);
		break;
	case 0xB000:	// Select 1K VROM bank
		nAddr &= 0x0007;
		g_sNesCardRegMapper49.nCHRBank[nAddr] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper49.nCHRBank[nAddr], nAddr);
		break;
	}
}
//@}

/** @name Mapper 50 - IREM-H-3001 */
//@{
/**
 * @struct nesSCardRegMapper50
 * @brief IREM-H-3001 Card Register
 */
typedef struct
{
	u32		nPRGBank[3];		///< PRG Bank
	u32		nCHRBank[8];		///< CHR Bank
	u32		nIRQInit;			///< IRQ Time Count Init Value
//	s32		nIRQCount;			///< IRQ Count Value
}nesSCardRegMapper50;
nesSCardRegMapper50 g_sNesCardRegMapper50;

/** @brief Write Data to Card Register - IREM-H-3001 */
void nesCardRegMapper50(u16 nAddr, u8 nValue)
{
	switch(nAddr)
	{
	case 0x8000:	// Select 8K ROM bank at 8000h-9FFFh
		g_sNesCardRegMapper50.nPRGBank[0] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper50.nPRGBank[0], 0);
		break;
	case 0x9000:	// Name Table Mirroring
		if( nValue & 0x40 )
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);		// Vertical Mirroring
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);		// Horizontal Mirroring
		break;
	case 0x9001:	// Name Table Mirroring
		//if( nValue & 0x80 )
		//	nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);		// Horizontal Mirroring
		//else
		//	nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);		// Vertical Mirroring
		break;
	case 0x9003:	// IRQ Control
		g_nNesCardIRQEnable = (nValue & 0x80) ? NES_CARD_IRQ_CPUCYCLE : 0;
		g_nNesCpuIRQFlag = 0;
		break;
	case 0x9004:	// IRQ Control
		g_nNesCardIRQTicks = g_sNesCardRegMapper50.nIRQInit;
		break;
	case 0x9005:	// IRQ Counter MSB of decrementing 16bit counter
		g_sNesCardRegMapper50.nIRQInit = (g_sNesCardRegMapper50.nIRQInit & 0x00FF) | (nValue<<8);
		//g_sNesCardRegMapper50.nIRQCount = nValue << 1;
		//g_nNesCpuIRQFlag = 0;
		break;
	case 0x9006:	// IRQ Counter LSB of decrementing 16bit counter
		g_sNesCardRegMapper50.nIRQInit = (g_sNesCardRegMapper50.nIRQInit & 0xFF00) | nValue;
//		g_nNesCardIRQEnable = NES_CARD_IRQ_SCANLINE;
		break;
	case 0xA000:	// Select 8K ROM bank at A000h-BFFFh
		g_sNesCardRegMapper50.nPRGBank[1] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper50.nPRGBank[1], 1);
		break;
	case 0xB000:	// Select 1K VROM bank at PPU 0000h-03FFh
		g_sNesCardRegMapper50.nCHRBank[0] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[0], 0);
		break;
	case 0xB001:	// Select 1K VROM bank at PPU 0400h-07FFh
		g_sNesCardRegMapper50.nCHRBank[1] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[1], 1);
		break;
	case 0xB002:	// Select 1K VROM bank at PPU 0800h-0BFFh
		g_sNesCardRegMapper50.nCHRBank[2] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[2], 2);
		break;
	case 0xB003:	// Select 1K VROM bank at PPU 0C00h-0FFFh
		g_sNesCardRegMapper50.nCHRBank[3] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[3], 3);
		break;
	case 0xB004:	// Select 1K VROM bank at PPU 1000h-13FFh
		g_sNesCardRegMapper50.nCHRBank[4] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[4], 4);
		break;
	case 0xB005:	// Select 1K VROM bank at PPU 1400h-17FFh
		g_sNesCardRegMapper50.nCHRBank[5] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[5], 5);
		break;
	case 0xB006:	// Select 1K VROM bank at PPU 1800h-1BFFh
		g_sNesCardRegMapper50.nCHRBank[6] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[6], 6);
		break;
	case 0xB007:	// Select 1K VROM bank at PPU 1C00h-1FFFh
		g_sNesCardRegMapper50.nCHRBank[7] = nValue;
		nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[7], 7);
		break;
	case 0xC000:	// Select 8K ROM bank at C000h-DFFFh
		g_sNesCardRegMapper50.nPRGBank[2] = nValue;
		nesCardRegPRGBank8(g_sNesCardRegMapper50.nPRGBank[2], 2);
		break;
	}
}

/** @brief Update Card IRQ - IREM-H-3001 */
void nesCardUpdateIRQMapper50()
{
	g_nNesCardIRQTicks += 0x10000;
	g_nNesCpuIRQFlag = 1;
	g_nNesCardIRQEnable = 0;
	//g_sNesCardRegMapper50.nIRQCount--;
	//if(g_sNesCardRegMapper50.nIRQCount <= 0)
	//{
	//	g_sNesCardRegMapper50.nIRQCount = g_sNesCardRegMapper50.nIRQInit;
	//	g_nNesCpuIRQFlag = 1;
	//}
}
//@}

//modify by yuans: test...

typedef struct
{
	u32		nCHRBank;			///< CHR Bank
}nesSCardRegMapper51;
nesSCardRegMapper51 g_sNesCardRegMapper51;

/** @brief Mapper 185: VROM-disable */
void nesCardRegMapper51(u16 nAddr, u8 nValue)
{
	Bool on;
	(void)nAddr;

	g_sNesCardRegMapper51.nCHRBank = (nValue&0x03)*8;
	on = (nValue&3)&&(nValue!=0x13);
	if(on)
		nesCardRegCHRBank8(g_sNesCardRegMapper51.nCHRBank);
	else
		nesCardRegCHRBank8(0);
}
//end of modify

/** @name Mapper 100 - Disk System */
//@{
/**
 * @struct nesSCardRegMapper100
 * @brief Disk System Register
 */
typedef struct
{
	u32		nSide;				///< Side ID
	s32		nIOPtr;				///< I/O Pointer
	u32		nIOMode;			///< I/O Mode
	u32		nIOSkip;			///< I/O Write Skip Bytes
	u32		nIOCRC;				///< I/O CRC Enable
	u32		nIOGAP;				///< I/O GAP Control
	u32		bIOEnable;			///< I/O Enable
	u32		nIRQRepeat;			///< IRQ Repeat
	u32		nIRQInit;			///< IRQ Time Count Init Value
	u32		bWriteStep;			///< Write Step
}nesSCardRegMapper100;
nesSCardRegMapper100 g_sNesCardRegMapper100;

/**
 * @struct nesSCardMapper100SaveHeader
 * @brief DiskSystem Save Header
 */
typedef struct
{
	u32		nAddr;				///< Data Addr
	u32		nSize;				///< Data Size
}nesSCardMapper100SaveHeader;

/**
 * @struct nesSCardMapper100FileInfo
 * @brief DiskSystem File Info
 */
typedef struct
{
	u8		nID;				///< File Index
	u8		bBoot;				///< Boot File
	u16		nArea;				///< Target Area
	u16		nTarget;			///< Target Address
	u16		nSize;				///< Data Size
	u32		nAddr;				///< Data Address
	u32		nHeader;			///< Header Address
}nesSCardMapper100FileInfo;

u8*	g_pNesCardMapper100DiskHeader;	///< Disk System I/O Disk Header Pointer
u8*	g_pNesCardMapper100Disk;		///< Disk System I/O Disk Pointer
u8	g_nNesCardMapper100File[NES_CARD_DISKSYSTEM_SIDEMAX];	///< Disk System File Count
nesSCardMapper100FileInfo g_sNesCardMapper100FileInfo[NES_CARD_DISKSYSTEM_SIDEMAX][NES_CARD_DISKSYSTEM_FILEMAX];	///< Disk System I/O File Info Pointer

/** @brief Save Data Access - Disk System */
void nesCardRegMapper100Save(u32 bIO)
{
	u32 n;
	u8 *pData;
	nesSCardMapper100SaveHeader* pHeader;

	pHeader = (nesSCardMapper100SaveHeader*)g_pNesSRAM;
	pData = g_pNesSRAM + sizeof(nesSCardMapper100SaveHeader)*NES_CARD_DISKSYSTEM_SAVEMAX;

	if(bIO)	// Write
	{
		for(n=0; n<g_pNesROMHeader->nSideNumber; ++n)
			g_pNesSRAM[NES_CARD_BANKSIZE_SRAM-NES_CARD_DISKSYSTEM_SIDEMAX+n] = g_nNesCardMapper100File[n];
		for(n=0; n<NES_CARD_DISKSYSTEM_SAVEMAX; ++n, ++pHeader)
		{
			if(!pHeader->nAddr)
				return;
			trlMemCopy(pData, &g_pNesCardMapper100DiskHeader[pHeader->nAddr], pHeader->nSize);
			pData += pHeader->nSize;
		}
	}
	else	// Read
	{
		for(n=0; n<g_pNesROMHeader->nSideNumber; ++n)
		{
			if(g_pNesSRAM[NES_CARD_BANKSIZE_SRAM-NES_CARD_DISKSYSTEM_SIDEMAX+n])
				g_pNesCardMapper100DiskHeader[57 + g_pNesROMHeader->nCRC + NES_CARD_DISKSYSTEM_SIDESIZE*n] = g_pNesSRAM[NES_CARD_BANKSIZE_SRAM-NES_CARD_DISKSYSTEM_SIDEMAX+n];
		}
		for(n=0; n<NES_CARD_DISKSYSTEM_SAVEMAX; ++n, ++pHeader)
		{
			if(!pHeader->nAddr)
				break;
			trlMemCopy(&g_pNesCardMapper100DiskHeader[pHeader->nAddr], pData, pHeader->nSize);
			pData += pHeader->nSize;
		}

		// Init File List
		trlMemSet(g_sNesCardMapper100FileInfo, 0, sizeof(nesSCardMapper100FileInfo)*NES_CARD_DISKSYSTEM_SIDEMAX*NES_CARD_DISKSYSTEM_FILEMAX);
		for(n=0; n<g_pNesROMHeader->nSideNumber; ++n)
		{
			nesSCardMapper100FileInfo *pInfo;
			u32 nFile,nPos;
			u8 *pDisk,nBoot;
			pDisk = g_pNesCardMapper100DiskHeader + NES_CARD_DISKSYSTEM_SIDESIZE*n;
			pInfo = g_sNesCardMapper100FileInfo[n];
			nBoot = pDisk[0x19];
			nFile = 0;
			for(nPos = 56+g_pNesROMHeader->nCRC ; nPos < NES_CARD_DISKSYSTEM_SIDESIZE;)
			{
				switch(pDisk[nPos])
				{
				case 0x02:	// File Number Block
					g_nNesCardMapper100File[n] = pDisk[nPos + 0x01];
					nPos += 2 + g_pNesROMHeader->nCRC;
					break;
				case 0x03:	// File Header Block
					if(nFile < g_nNesCardMapper100File[n])
					{
						pInfo->nID = pDisk[nPos + 0x02];
						pInfo->bBoot = (pInfo->nID <= nBoot) ? 1 : 0;
						pInfo->nTarget = *(u16*)(&pDisk[nPos + 0x0B]);
						pInfo->nSize = *(u16*)(&pDisk[nPos + 0x0D]);
						pInfo->nArea = pDisk[nPos + 0x0F];
						pInfo->nHeader = nPos + 2;
						nPos += 16 + g_pNesROMHeader->nCRC;
					}
					else
						nPos = NES_CARD_DISKSYSTEM_SIDESIZE;
					break;
				case 0x04:	// File Data Block
					if(nFile < g_nNesCardMapper100File[n])
					{
						pInfo->nAddr = nPos + 1;
						nPos += 1 + pInfo->nSize + g_pNesROMHeader->nCRC;
						pInfo++;
						nFile++;
					}
					else
						nPos = NES_CARD_DISKSYSTEM_SIDESIZE;
					break;
				default:
					++nPos;
				}
			}
		}
	}
}

/** @brief Disk System I/O - Get Data Pointer */
u8* nesCardDiskSystemGetPointer(u16 nArea, u16 nAddr)
{
	if(!nArea)	// WRAM
	{
		switch(nAddr >> 13)
		{
		case 0x0:							// 0000h-07FFh   Work RAM
			return g_pNesWRAM + (nAddr&0x7FF);
		case 0x7:							// E000h-FFFFh   BIOS Area
			return g_pNesCardMapper100DiskHeader + nAddr - NES_CARD_DISKSYSTEM_BIOSSIZE - 0xE000;
		default:							// 6000h-DFFFh   PRG-ROM Area
			return g_pNesPRGROM + nAddr - 0x6000;
		}
	}
	else		// VRAM
	{
		if(nAddr<0x2000)					// Pattern Table
			return g_pNesCHRROM + nAddr;
		else if(nAddr<0x3F00)				// Name Table and Attribute Table
			return &g_pNesGrpNameTab[(nAddr>>10)&0x3][nAddr&0x3FF];
		return &g_pNesPALRAM[nAddr & 0x1F];	// Palettes
	}
}

/** @brief Disk System I/O - Get Parameter */
u16 nesCardDiskSystemGetParameter(u16 nOffset)
{
	u16 nAddr = *(u16*)(&g_pNesWRAM[g_nNesCpuRegS+0x101]) + nOffset;
	switch(nAddr >> 13)
	{
	case 0x0:				// 0000h-07FFh   Work RAM
		return *(u16*)(g_pNesWRAM + (nAddr&0x7FF));
	case 0x7:				// E000h-FFFFh   BIOS Area
		return *(u16*)(g_pNesCardMapper100DiskHeader + nAddr - NES_CARD_DISKSYSTEM_BIOSSIZE - 0xE000);
	default:				// 6000h-DFFFh   PRG-ROM Area
		return *(u16*)(g_pNesPRGROM + nAddr - 0x6000);
	}
}

/** @brief Disk System Read File */
void nesCardDiskSystemRead()
{
	u32 m,n;
	u8 *pLoadList,*pDiskID,nFound;

	pDiskID = nesCardDiskSystemGetPointer(0, nesCardDiskSystemGetParameter(1));
	if(*pDiskID == 0xFF){
		g_sNesCardRegMapper100.nSide = 0;
		//if(g_sNesCardRegMapper100.nSide != 0)
		//	g_pNesEmuBuf->nSwitchDisk = 1;
	}
	else{
		//u32 old_side=g_sNesCardRegMapper100.nSide;
		u8 *thisDiskID;
		int i,j;
		for(i = 0 ; i < g_pNesROMHeader->nSideNumber ; i++)
		{
			g_sNesCardRegMapper100.nSide=i;
			g_pNesCardMapper100Disk = g_pNesCardMapper100DiskHeader + i * 0x10000;
			thisDiskID=g_pNesCardMapper100Disk+0xF;
			//if(memcmp(pDiskID, thisDiskID, 10)==0)break;
			for(j = 0 ; j < 10 ; j++){
				if(pDiskID[j] != thisDiskID[j])break;
			}
			if(j == 10)break;
		}
		//u32 now_side = pDiskID[0x07] * 2 + pDiskID[0x06];
		//g_sNesCardRegMapper100.nSide=now_side;
		//if(now_side != old_side)
		//	g_pNesEmuBuf->nSwitchDisk = 1;
		//if(g_sNesCardRegMapper100.nSide==0)
		//	g_pNesEmuBuf->nSwitchDisk = 1;
		//g_sNesCardRegMapper100.nSide=now_side;
	}
	g_pNesCardMapper100Disk = g_pNesCardMapper100DiskHeader + g_sNesCardRegMapper100.nSide * 0x10000;

	nFound = 0;
	pLoadList = nesCardDiskSystemGetPointer(0, nesCardDiskSystemGetParameter(3));
	if(*pLoadList == 0xFF)	// Load Boot Files
	{
		nesSCardMapper100FileInfo* pInfo = g_sNesCardMapper100FileInfo[g_sNesCardRegMapper100.nSide];
		for(n=0; n<g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide]; ++n, ++pInfo)
		{
			if(pInfo->bBoot)
			{
				trlMemCopy(nesCardDiskSystemGetPointer(pInfo->nArea, pInfo->nTarget), g_pNesCardMapper100Disk + pInfo->nAddr, pInfo->nSize);
				nFound++;
			}
		}
	}
	else
	{
		nesSCardMapper100FileInfo* pInfo = g_sNesCardMapper100FileInfo[g_sNesCardRegMapper100.nSide];
		for(n=0; n<g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide]; ++n, ++pInfo)
		{
			for(m=0; m<NES_CARD_DISKSYSTEM_LOADMAX; ++m)
			{
				if(pLoadList[m] == 0xFF)
					break;
				if(pLoadList[m] == g_pNesCardMapper100Disk[pInfo->nHeader])
				{
					trlMemCopy(nesCardDiskSystemGetPointer(pInfo->nArea, pInfo->nTarget), g_pNesCardMapper100Disk + pInfo->nAddr, pInfo->nSize);
					nFound++;
					break;
				}
			}
		}
	}
	g_nNesCpuRegA = 0x00;
	g_nNesCpuRegX = 0x00;
	g_nNesCpuRegY = nFound;
	g_nNesCpuRegP |= 0x02;
	g_pNesWRAM[0x0E] = nFound;
	g_pNesWRAM[0xFE] &= 0xE7;
	g_pNesGrpReg2001->rBGEnable = 0;
	g_pNesGrpReg2001->rSPREnable = 0;
	g_nNesGrpEnable = 0;
}

/** @brief Disk System Write File */
void nesCardDiskSystemWrite()
{
	nesSCardMapper100FileInfo *pInfo;
	nesSCardMapper100SaveHeader *pHeader;
	u8 *pFileInfo,*pDiskID;
	u16 nSrcAddr,nSrcArea;
	u32 n,nSize,nAddress,nLength;

	pDiskID = nesCardDiskSystemGetPointer(0, nesCardDiskSystemGetParameter(1));
	g_sNesCardRegMapper100.nSide = pDiskID[0x07] * 2 + pDiskID[0x06];
	g_pNesCardMapper100Disk = g_pNesCardMapper100DiskHeader + g_sNesCardRegMapper100.nSide * 0x10000;

	pFileInfo = nesCardDiskSystemGetPointer(0, nesCardDiskSystemGetParameter(3));
	nSrcAddr = *(u16*)(&pFileInfo[14]);
	nSrcArea = pFileInfo[16];
	pInfo = g_sNesCardMapper100FileInfo[g_sNesCardRegMapper100.nSide];
	if(g_nNesCpuRegA == 0xFF)	// Append
	{
		pInfo += g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide];
		pInfo->nID = *pFileInfo;
		pInfo->bBoot = (pInfo->nID <= g_pNesCardMapper100Disk[0x19]) ? 1 : 0;
		pInfo->nTarget = *(u16*)(&pFileInfo[0x09]);
		pInfo->nSize = *(u16*)(&pFileInfo[0x0B]);
		pInfo->nArea = pFileInfo[0x0D];
		pInfo->nHeader = nSrcAddr - 0x11 - g_pNesROMHeader->nCRC;
		//pInfo->nHeader=0xc2c6;
		pInfo->nAddr = nSrcAddr;
		//pInfo->nAddr=0xc2d7;
		g_pNesCardMapper100Disk[pInfo->nHeader-2] = 0x03;
		g_pNesCardMapper100Disk[pInfo->nHeader-1] = g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide];
		g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide]++;
	}
	else if(g_nNesCpuRegA>=g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide])
	{
		nesSCardMapper100FileInfo *pLastInfo;
		//the total file number is less or equal to g_nNesCpuRegA, we still add a file at the end of the file list.
		pInfo += g_nNesCpuRegA;
		pInfo->nID = *pFileInfo;
		pInfo->bBoot = (pInfo->nID <= g_pNesCardMapper100Disk[0x19]) ? 1 : 0;
		pInfo->nTarget = *(u16*)(&pFileInfo[0x09]);
		pInfo->nSize = *(u16*)(&pFileInfo[0x0B]);
		pInfo->nArea = pFileInfo[0x0D];

		pLastInfo = pInfo-1;

		pInfo->nHeader = pLastInfo->nAddr+pLastInfo->nSize+4;
		//pInfo->nHeader=0xc2c6;
		pInfo->nAddr = pInfo->nHeader+0x11;
		//pInfo->nAddr=0xc2d7;
		g_pNesCardMapper100Disk[pInfo->nHeader-2] = 0x03;
		g_pNesCardMapper100Disk[pInfo->nHeader-1] = g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide];
		g_nNesCardMapper100File[g_sNesCardRegMapper100.nSide]++;
	}
	else
	{
		pInfo += g_nNesCpuRegA;
	}

	trlMemCopy(g_pNesCardMapper100Disk + pInfo->nHeader, pFileInfo, 14);
	trlMemCopy(g_pNesCardMapper100Disk + pInfo->nAddr, nesCardDiskSystemGetPointer(nSrcArea, nSrcAddr), pInfo->nSize);

	g_nNesCpuRegA = 0x00;
	g_nNesCpuRegX = 0x00;
	g_nNesCpuRegP |= 0x02;

	// Update Save
	nSize = 0x11 + g_pNesROMHeader->nCRC;
	nAddress = g_sNesCardRegMapper100.nSide * 0x10000 + pInfo->nAddr - nSize;
	nLength = sizeof(nesSCardMapper100SaveHeader) * NES_CARD_DISKSYSTEM_SAVEMAX;
	pHeader = (nesSCardMapper100SaveHeader*)g_pNesSRAM;
	nSize += pInfo->nSize;
	for(n=0; n<NES_CARD_DISKSYSTEM_SAVEMAX; ++n, ++pHeader)
	{
		if(pHeader->nAddr == 0)
		{
			pHeader->nAddr = nAddress;
			pHeader->nSize = nSize;
			nAddress = 0;
		}
		else if(pHeader->nAddr == nAddress)
		{
			//if(pHeader->nSize != nSize)
			//	TRL_ERROR("Disk System Save Data Size Change!");
			pHeader->nSize = nSize;
			nAddress = 0;
		}
		if(!pHeader->nSize)
			break;
		nLength += pHeader->nSize;
		if(nAddress == 0)
			break;
	}
#if 0
	if(nAddress)
		TRL_ERROR("Disk System Save Data Overflow! (Addr)");
	if(nLength>NES_CARD_BANKSIZE_SRAM)
		TRL_ERROR("Disk System Save Data Overflow! (Size)");
#endif
	g_pNesEmuBuf->nSaveUpdate |= 1;
}

void nesCardDiskSystemReloadRom(void)
{
	//extern void trlEmuShellDataReloadRom(void);
	//trlEmuShellDataReloadRom();
}

/** @brief Write Data to Card Register - Disk System */
void nesCardRegMapper100(u16 nAddr, u8 nValue)
{
	// 8000h-DFFFh WRAM
	if(nAddr <= 0xDFFF)
		g_pNesPRGROM[nAddr - 0x6000] = nValue;
}

/** @brief Write Data to Card Register - Disk System */
void nesCardRegMapper100Write(u16 nAddr, u8 nValue)
{
	u32 n;

	switch(nAddr)
	{
	case 0x4020:	// Timer IRQ Counter Reload value LSB
		g_sNesCardRegMapper100.nIRQInit = (g_sNesCardRegMapper100.nIRQInit & 0xFF00) | nValue;
		break;
	case 0x4021:	// Timer IRQ Counter Reload value MSB
		g_sNesCardRegMapper100.nIRQInit = (g_sNesCardRegMapper100.nIRQInit & 0x00FF) | (nValue << 8);
		break;
	case 0x4022:	// Timer IRQ Enable/Disable
		g_sNesCardRegMapper100.nIRQRepeat = nValue & 0x01;
		g_nNesCardIRQEnable = (nValue & 0x02) ? NES_CARD_IRQ_CPUCYCLE : 0;
		if(g_nNesCardIRQEnable)
			g_nNesCardIRQTicks = g_sNesCardRegMapper100.nIRQInit;
		else
			g_nNesCpuIRQFlag &= ~0x01;
		break;
	case 0x4023:	// 2C33 I/O Control Port
		nesSndRegWriteCard(0x23, nValue);
		g_sNesCardRegMapper100.bIOEnable = nValue & 0x01;
		if(!g_sNesCardRegMapper100.bIOEnable)
			g_nNesCpuIRQFlag = 0;
		break;
	case 0x4024:	// Disk Data Write Register
		g_nNesCpuIRQFlag &= ~0x02;
		if(!g_sNesCardRegMapper100.nIOMode && g_sNesCardRegMapper100.bIOEnable)
		{
			if(g_sNesCardRegMapper100.nIOPtr < NES_CARD_DISKSYSTEM_DISKSIZE)
			{
				if(g_sNesCardRegMapper100.nIOSkip)
				{
					if(!g_sNesCardRegMapper100.nIOGAP)
					{
						switch(g_sNesCardRegMapper100.bWriteStep)
						{
						case 0:
							if(g_sNesCardRegMapper100.nIOPtr == 0x003A)
								g_sNesCardRegMapper100.bWriteStep = 1;
							break;
						case 1:
							{
								u32 nAddress,nSize;
								nesSCardMapper100SaveHeader *pHeader;
								
								nAddress = g_sNesCardRegMapper100.nSide * 0x10000 + g_sNesCardRegMapper100.nIOPtr;
								nSize = sizeof(nesSCardMapper100SaveHeader) * NES_CARD_DISKSYSTEM_SAVEMAX;
								pHeader = (nesSCardMapper100SaveHeader*)g_pNesSRAM;
								for(n = 0 ; n < NES_CARD_DISKSYSTEM_SAVEMAX ; ++n, ++pHeader)
								{
									if(nAddress)
									{
										if((pHeader->nAddr == 0) || (pHeader->nAddr == nAddress))
										{
											pHeader->nAddr = nAddress;
											pHeader->nSize = 0x11 + g_pNesROMHeader->nCRC + *(u16*)(&g_pNesCardMapper100Disk[g_sNesCardRegMapper100.nIOPtr+0x0D]);
											nAddress = 0;
										}
									}
									if(!pHeader->nSize)
										break;
									nSize += pHeader->nSize;
								}
#if 0
								if(nAddress)
									TRL_ERROR("Disk System Save Data Overflow (Addr)");
								if(nSize>NES_CARD_BANKSIZE_SRAM)
									TRL_ERROR("Disk System Save Data Overflow (Size)");
#endif
								g_sNesCardRegMapper100.bWriteStep = 2;
							}
							break;
						case 2:
							if(g_sNesCardRegMapper100.nIOPtr == 0x003A)
							{
								g_sNesCardRegMapper100.bWriteStep = 0;
								g_pNesEmuBuf->nSaveUpdate |= 1;
							}
							break;
						}
					}
					g_sNesCardRegMapper100.nIOSkip--;
				}
				else
					g_pNesCardMapper100Disk[g_sNesCardRegMapper100.nIOPtr-2] = nValue;
			}
		}
		break;
	case 0x4025:	// Disk Control Register
		// Bit0   Drive Motor         (0=On, 1=Off)
		// Bit1   \ = Set drive head to the start of the first track.
		if(nValue & 0x02)
			g_sNesCardRegMapper100.nIOPtr = 0;
		// Bit2   Disk Data Direction (0=Write, 1=Read)
		g_sNesCardRegMapper100.nIOMode = nValue & 0x04;
		if(g_sNesCardRegMapper100.nIOMode == 0)
			g_sNesCardRegMapper100.nIOSkip = 1;
		// Bit3   Screen Mirroring    (0=Vertical, 1=Horizontal Mirroring)
		if(nValue & 0x08)
			nesGrpChangeNameTabMap(NES_GRP_MAP_HORI);
		else
			nesGrpChangeNameTabMap(NES_GRP_MAP_VERT);
		// Bit4   Enable CRC Phase
		g_sNesCardRegMapper100.nIOCRC = nValue & 0x10;
		// Bit6   GAP Control
		g_sNesCardRegMapper100.nIOGAP = nValue & 0x40;
		// Bit7   Disk IRQs on every byte transfer
		g_nNesCardIRQDiskEnable = nValue & 0x80;
		if(!g_nNesCardIRQDiskEnable)
			g_nNesCpuIRQFlag &= ~0x02;
		g_nNesCardIRQDiskTicks = NES_CARD_DISKSYSTEM_CYCLE;
		break;
	case 0x4026:	// Disk External Connector Output
		break;
	default:		// Sound Register
		nesSndRegWriteCard(nAddr - 0x4000, nValue);
	}
}

/** @brief Read Data to Card Register - Disk System */
u8 nesCardRegMapper100Read(u16 nAddr)
{
	u8 nData;

	switch(nAddr)
	{
	case 0x4030:	// Disk Status Register 0
		{
			nData = (u8)g_nNesCpuIRQFlag | 0x80;
			g_nNesCpuIRQFlag = 0;
			return nData;
		}
	case 0x4031:	// Disk Data Read Register
		{
			nData = g_pNesCardMapper100Disk[g_sNesCardRegMapper100.nIOPtr];
			if(g_sNesCardRegMapper100.nIOPtr < NES_CARD_DISKSYSTEM_DISKSIZE)
				g_sNesCardRegMapper100.nIOPtr++;
			g_nNesCardIRQDiskTicks = NES_CARD_DISKSYSTEM_CYCLE;
			g_nNesCpuIRQFlag &= ~0x02;			
			return nData;
		}
	case 0x4032:	// Disk Status Register 1
		{
			nData = 0x40;
			if(g_pNesEmuBuf->nSwitchDisk>0)
			{
				nData |= 0x07;
				g_pNesEmuBuf->nSwitchDisk--;
				if(g_pNesEmuBuf->nSwitchDisk==0)
					g_sNesCardRegMapper100.nSide ^= 1;
			}
			else 
			if(!(g_pNesWRAM[0xFA] & 0x01) || (g_pNesWRAM[0xFA] & 0x02))
				nData |= 0x02;
			return nData;
		}
	case 0x4033:	// Disk External Connector Input
		return 0x80;
	case 0x4090:	// Current Volume Gain Level (6bit)
		return SoundF.envgain;
	case 0x4092:	// Current Sweep Gain Level (6bit)
		return SoundF.subenvgain;
	}
	if(nAddr>=0x4040 && nAddr<0x4080 )
		return DISKFM_TABLE[nAddr-0x4040];
	return 0xFF;
}

/** @brief Update Card IRQ - Disk System */
void nesCardUpdateIRQMapper100()
{
	// Time IRQ
	if(g_nNesCardIRQEnable == NES_CARD_IRQ_CPUCYCLE){
		if(g_sNesCardRegMapper100.nIRQRepeat)
			g_nNesCardIRQTicks = g_sNesCardRegMapper100.nIRQInit;
		else
			g_nNesCardIRQEnable = 0;
		g_nNesCpuIRQFlag |= 1;
	}
}
//@}

u8					g_nPPUCHRRAM;			///< PPU CHR RAM write enable flag

/** @brief Initialize Card */
void nesCardInit()
{
	u32 nRenderMode;
	// Initialize SRAM
	g_nNesCardSaveData = 0;
	g_nNesCardSRAMEnable = 0;
	g_pNesSRAM = NULL;
	if(g_pNesROMHeader->nSRAMBanks)
	{
		s32 nSRAMSize;
		nSRAMSize = g_pNesROMHeader->nSRAMBanks * NES_CARD_BANKSIZE_SRAM;
	//	g_pNesSRAM = (u8*)trlMemAlloc(nSRAMSize);
		g_pNesSRAM = &g_pYosHeap[YOS_SRAM];
		g_pNesSRAMBank = g_pNesSRAM;
		g_nNesCardSRAMEnable = 1;
		trlMemSet(g_pNesSRAM, 0, nSRAMSize);
		// Backup Data
		if(g_pNesROMHeader->nBattery)
		{
			g_pNesEmuBuf->nBackupDataSize = nSRAMSize;
			g_pNesEmuBuf->pBackupData = g_pNesSRAM;
		}
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],g_pNesSRAM, nSRAMSize, 1, 0);
	}

	nesCardRegister = NULL;
	nesCardRegisterWrite = NULL;
	nesCardRegisterRead = NULL;
	nesCardRegisterLatch = NULL;
	nesCardUpdateIRQ = NULL;
	nRenderMode = NES_GRP_BG_NORMAL;
	g_sEmuCoreNES.trlEmuCoreSave = NULL;

	g_nPPUCHRRAM = 0xFF;

	switch(g_pNesROMHeader->nMapper)
	{
	case 0:		// NROM - (No Mapper)
		g_nPPUCHRRAM = 0;
		break;
	case 1:		// MMC1 - PRG/32K/16K, VROM/8K/4K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper1, sizeof(nesSCardRegMapper1), 1, 0);
		nesCardRegister = nesCardRegMapper1;
		break;
	case 2:		// MMC2 - PRG/24K/8K, VROM/4K, NT, LATCH
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper2, sizeof(nesSCardRegMapper2), 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardLatch, 8, 1, 0);
		nesCardRegister = nesCardRegMapper2;
		nesCardRegisterLatch = nesCardRegMapper2Latch;
		nRenderMode = NES_GRP_BG_LATCH;
		break;
	case 3:		// MMC3 - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardSRAMEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper3, sizeof(nesSCardRegMapper3), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper3;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper3;
		break;
	case 4:		// MMC4 - PRG/16K, VROM/4K, NT, LATCH
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper4, sizeof(nesSCardRegMapper4), 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardLatch, 8, 1, 0);
		nesCardRegister = nesCardRegMapper4;
		nesCardRegisterLatch = nesCardRegMapper4Latch;
		nRenderMode = NES_GRP_BG_LATCH;
		break;
	case 5:		// MMC5 - BANKING, IRQ, SOUND, VIDEO, MULTIPLY, etc.
		//g_pNesCardFILLRAMMapper5 = (u8*)trlMemAlloc(0x400);
		//g_pNesCardEXRAMMapper5 = (u8*)trlMemAlloc(0x400);
		g_pNesCardFILLRAMMapper5 = &g_pYosHeap[YOS_NESCARD];
		g_pNesCardEXRAMMapper5 = &g_pYosHeap[YOS_NESCARD+0x400];
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],g_pNesCardEXRAMMapper5, 0x400, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper5, sizeof(nesSCardRegMapper5), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegisterWrite = nesCardRegMapper5Write;
		nesCardRegisterRead = nesCardRegMapper5Read;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper5;
		break;
	case 6:		// UNROM - PRG/16K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper6, sizeof(nesSCardRegMapper6), 1, 0);
		nesCardRegister = nesCardRegMapper6;
		break;
	case 7:		// CNROM - VROM/8K
		g_nNesCardSRAMEnable = 2;
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper7, sizeof(nesSCardRegMapper7), 1, 0);
		nesCardRegister = nesCardRegMapper7;
		g_nPPUCHRRAM=0;
		break;
	case 8:		// GNROM - PRG/32K, VROM/8K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper8, sizeof(nesSCardRegMapper8), 1, 0);
		nesCardRegister = nesCardRegMapper8;
		break;
	case 9:		// RARE - PRG/32K, Name Table Select
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper9, sizeof(nesSCardRegMapper9), 1, 0);
		nesCardRegister = nesCardRegMapper9;
		break;
	case 10:	// SUNSOFT1 - VROM/4K
		g_nNesCardSRAMEnable = 2;
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper10, sizeof(nesSCardRegMapper10), 1, 0);
		nesCardRegister = nesCardRegMapper10;
		break;
	case 11:	// SUNSOFT2 - PRG/16K, VROM/8K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper11, sizeof(nesSCardRegMapper11), 1, 0);
		nesCardRegister = nesCardRegMapper11;
		break;
	case 12:	// SUNSOFT3 - PRG/16K, VROM/2K, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQTicks, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper12, sizeof(nesSCardRegMapper12), 1, 0);
		g_nNesCardIRQTicks = 0;
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper12;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper12;
		break;
	case 13:	// SUNSOFT4 - PRG/16K, VROM/2K, NT-VROM
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper13, sizeof(nesSCardRegMapper13), 1, 0);
		nesCardRegister = nesCardRegMapper13;
		break;
	case 14:	// SUNSOFT5 - PRG/8K, VROM/1K, NT ctrl, SRAM, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQTicks, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper14, sizeof(nesSCardRegMapper14), 1, 0);
		g_nNesCardIRQTicks = 0;
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper14;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper14;
		break;
	case 15:	// BANDAI - PRG/16K, VROM/8K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper15, sizeof(nesSCardRegMapper15), 1, 0);
		nesCardRegister = nesCardRegMapper15;
		break;
	case 16:	// VRC1 - PRG/8K, VROM/4K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper16, sizeof(nesSCardRegMapper16), 1, 0);
		nesCardRegister = nesCardRegMapper16;
		break;
	case 17:	// VRC2A - PRG/8K, VROM/1K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper17, sizeof(nesSCardRegMapper17), 1, 0);
		nesCardRegister = nesCardRegMapper17;
		break;
	case 18:	// VRC2B - PRG/8K, VROM/1K, NT, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper18, sizeof(nesSCardRegMapper18), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper18;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper18;
		break;
	case 19:	// VRC3 - PRG/16K, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQTicks, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper19, sizeof(nesSCardRegMapper19), 1, 0);
		g_nNesCardIRQTicks = 0;
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper19;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper19;
		break;
	case 20:	// VRC4A - PRG/8K, VROM/1K, NT, IRQ
	case 21:	// VRC4B - PRG/8K, VROM/1K, NT, IRQ
	case 22:	// VRC4C - PRG/8K, VROM/1K, NT, IRQ
	case 23:	// VRC4D - PRG/8K, VROM/1K, NT, IRQ
	case 24:	// VRC4E - PRG/8K, VROM/1K, NT, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardSRAMEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper20, sizeof(nesSCardRegMapper20), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper20;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper20;
		break;
	case 25:	// VRC6A - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
	case 26:	// VRC6B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardSRAMEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper25, sizeof(nesSCardRegMapper25), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper25;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper25;
		break;
	case 27:	// VRC7A/B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper27, sizeof(nesSCardRegMapper27), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper27;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper27;
		break;
	case 28:	// JALECO-1 - VROM/8K
		g_nNesCardSRAMEnable = 2;
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper28, sizeof(nesSCardRegMapper28), 1, 0);
		nesCardRegister = nesCardRegMapper28;
		break;
	case 29:	// JALECO-2 - PRG-LO, VROM/8K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper29, sizeof(nesSCardRegMapper29), 1, 0);
		nesCardRegister = nesCardRegMapper29;
		break;
	case 30:	// JALECO-3 - PRG-HI, VROM/8K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper30, sizeof(nesSCardRegMapper30), 1, 0);
		nesCardRegister = nesCardRegMapper30;
		break;
	case 31:	// JALECO-4 - PRG/32K, VROM/8K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper31, sizeof(nesSCardRegMapper31), 1, 0);
		g_nNesCardSRAMEnable = 2;
		nesCardRegister = nesCardRegMapper31;
		break;
	case 32:	// JALECO-SS8806 - PRG/8K, VROM/1K, NT, IRQ, EXT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardSRAMEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQTicks, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper32, sizeof(nesSCardRegMapper32), 1, 0);
		g_nNesCardIRQTicks = 0;
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper32;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper32;
		break;
	case 33:	// 74161A - PRG/16K
	case 34:	// 74161B - PRG/16K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper33, sizeof(nesSCardRegMapper33), 1, 0);
		nesCardRegister = nesCardRegMapper33;
		break;
	case 35:	// NAMCOT - PRG/8K, VROM/2K/1K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper35, sizeof(nesSCardRegMapper35), 1, 0);
		nesCardRegister = nesCardRegMapper35;
		break;
	case 36:	// NAMCOT-106 - PRG/8K, VROM/1K/VRAM, IRQ, SOUND
		//g_pNesCardVRAMMapper36 = (u8*)trlMemAlloc(0x8000);
		g_pNesCardVRAMMapper36 = &g_pYosHeap[YOS_NESCARD];
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],g_pNesCardVRAMMapper36, 0x8000, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper36, sizeof(nesSCardRegMapper36), 1, 0);
		nesCardRegister = nesCardRegMapper36;
		nesCardRegisterWrite = nesCardRegMapper36Write;
		nesCardRegisterRead = nesCardRegMapper36Read;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper36;
		break;
	case 37:	// NAMCO-109 - PRG/8K, VROM/2K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper37, sizeof(nesSCardRegMapper37), 1, 0);
		nesCardRegister = nesCardRegMapper37;
		break;
	case 38:	// NAMCO-118
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper38, sizeof(nesSCardRegMapper38), 1, 0);
		nesCardRegister = nesCardRegMapper38;
		break;
	case 39:	// MMC-3+TLS - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper39, sizeof(nesSCardRegMapper39), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper39;

		nesCardUpdateIRQ = nesCardUpdateIRQMapper39;
		break;
	case 40:	// TAITO-TC0190 - PRG/8K, VROM/1K/2K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper40, sizeof(nesSCardRegMapper40), 1, 0);
		nesCardRegister = nesCardRegMapper40;
		break;
	case 41:	// TAITO-TC0350 - PRG/8K, VROM/1K/2K, NT, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper41, sizeof(nesSCardRegMapper41), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper41;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper41;
		break;
	case 42:	// TAITO-TC190V - PRG/8K, VROM/1K/2K, NT, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper42, sizeof(nesSCardRegMapper42), 1, 0);
		g_nNesCardIRQEnable = 0;
		nesCardRegister = nesCardRegMapper42;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper42;
		break;
	case 43:	// TAITO-X-005 - PRG/8K, VROM/2K/1K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper43, sizeof(nesSCardRegMapper43), 1, 0);
		g_nNesCardSRAMEnable = 2;
		nesCardRegister = nesCardRegMapper43;
		break;
	case 44:	// TAITO-X1-17 - PRG/8K, VROM/2K/1K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper44, sizeof(nesSCardRegMapper44), 1, 0);
		g_nNesCardSRAMEnable = 2;
		nesCardRegister = nesCardRegMapper44;
		break;
	case 45:	// IREM-1 - PRG/32K, VROM/2K, VRAM 6K+2K
		//g_pNesCardVRAMMapper45 = (u8*)trlMemAlloc(0x2000);
		g_pNesCardVRAMMapper45 = &g_pYosHeap[YOS_NESCARD];
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],g_pNesCardVRAMMapper45, 0x2000, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper45, sizeof(nesSCardRegMapper45), 1, 0);
		g_pNesCHRBank[2] = g_pNesCardVRAMMapper45;
		g_pNesCHRBank[3] = g_pNesCHRBank[2] + NES_CARD_BANKSIZE_CHR;
		g_pNesCHRBank[4] = g_pNesCHRBank[3] + NES_CARD_BANKSIZE_CHR;
		g_pNesCHRBank[5] = g_pNesCHRBank[4] + NES_CARD_BANKSIZE_CHR;
		g_pNesCHRBank[6] = g_pNesCHRBank[5] + NES_CARD_BANKSIZE_CHR;
		g_pNesCHRBank[7] = g_pNesCHRBank[6] + NES_CARD_BANKSIZE_CHR;
		g_pNesGrpNameTab[0] = g_pNesVRAM;
		g_pNesGrpNameTab[1] = g_pNesVRAM + 0x400;
		g_pNesGrpNameTab[2] = g_pNesCardVRAMMapper45 + 0x1800;
		g_pNesGrpNameTab[3] = g_pNesCardVRAMMapper45 + 0x1C00;
		nesGrpChangeNameTabMap(NES_GRP_MAP_EXTEND);
		nesCardRegister = nesCardRegMapper45;
		break;
	case 46:	// IREM-2 - PRG HI
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper46, sizeof(nesSCardRegMapper46), 1, 0);
		nesCardRegister = nesCardRegMapper46;
		break;
	case 47:	// IREM-74HC161 - PRG/16K, VROM/8K
	case 48:	// IREM-74HC32 - PRG/16K, VROM/8K
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper47, sizeof(nesSCardRegMapper47), 1, 0);
		nesCardRegister = nesCardRegMapper47;
		break;
	case 49:	// IREM-G-101 - PRG/8K, VROM/1K, NT
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper49, sizeof(nesSCardRegMapper49), 1, 0);
		nesCardRegister = nesCardRegMapper49;
		break;
	case 50:	// IREM-H-3001 - PRG/8K, VROM/1K, NT, IRQ
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper50, sizeof(nesSCardRegMapper50), 1, 0);
		nesCardRegister = nesCardRegMapper50;
		nesCardUpdateIRQ = nesCardUpdateIRQMapper50;
		break;

//add by yuans:
	case 51:	// Mapper 185: VROM-disable
		trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper51, sizeof(nesSCardRegMapper51), 1, 0);
//		g_pNesROMHeader->nNameTabMapping = NES_GRP_MAP_HORI;
		nesCardRegister = nesCardRegMapper51;

		g_nPPUCHRRAM = 0;

		break;
//end of add

	case 100:	// Disk System - PRG RAM, BIOS, DISK, IRQ, SOUND
		{
			//g_pNesSRAM = (u8*)trlMemAlloc(NES_CARD_BANKSIZE_SRAM);
			g_pNesSRAM = &g_pYosHeap[YOS_NESCARD];
			trlMemSet(g_pNesSRAM, 0, NES_CARD_BANKSIZE_SRAM);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQTicks, 4, 1, 0);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQEnable, 4, 1, 0);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQDiskTicks, 4, 1, 0);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_nNesCardIRQDiskEnable, 4, 1, 0);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],&g_sNesCardRegMapper100, sizeof(nesSCardRegMapper100), 1, 0);
			trlSEmuShellResumeSetData(&g_sNesCardSaveData[g_nNesCardSaveData++],g_pNesSRAM, NES_CARD_BANKSIZE_SRAM, 1, 0);
			g_pNesEmuBuf->nBackupDataSize = NES_CARD_BANKSIZE_SRAM;
			g_pNesEmuBuf->pBackupData = g_pNesSRAM;
			g_nNesCardSRAMEnable = 1;
			g_nNesCardIRQTicks = 0;
			g_nNesCardIRQEnable = 0;
			g_nNesCardIRQDiskTicks = 0;
			g_nNesCardIRQDiskEnable = 0;
			nesCardRegister = nesCardRegMapper100;
			nesCardRegisterWrite = nesCardRegMapper100Write;
			nesCardRegisterRead = nesCardRegMapper100Read;
			nesCardUpdateIRQ = nesCardUpdateIRQMapper100;
			g_sEmuCoreNES.trlEmuCoreSave = nesCardRegMapper100Save;
			g_pNesEmuBuf->nSwitchDisk = 0;
			g_pNesCardMapper100DiskHeader = (u8*)(g_pNesEmuBuf->pRomBuf) + sizeof(nesSROMHeader) + NES_CARD_DISKSYSTEM_BIOSSIZE;
		}
		break;
	}
	nesGrpChangeRenderBG(nRenderMode);

	nesCardReset();
}

/** @brief Reset Card */
void nesCardReset()
{
	u32 n;

	g_nNesCardIRQTicks = 0;
	g_nNesCardIRQEnable = 0;
	g_nNesCardIRQDiskTicks = 0;
	g_nNesCardIRQDiskEnable = 0;
	switch(g_pNesROMHeader->nMapper)
	{
	case 0:		// NROM - (No Mapper)
		g_nPPUCHRRAM = 0;
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		if(g_pNesCHRROM)
			nesCardRegCHRBank8(0);
		break;
	case 1:		// MMC1 - PRG/32K/16K, VROM/8K/4K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper1, 0, sizeof(nesSCardRegMapper1));
		g_sNesCardRegMapper1.nPRGMode = 3;
		break;
	case 2:		// MMC2 - PRG/24K/8K, VROM/4K, NT, LATCH
		nesCardRegPRGBank32(g_pNesROMHeader->nPRGBanks - 4);
		g_pNesPRGBank[0] = g_pNesPRGROM;
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper2, 0, sizeof(nesSCardRegMapper2));
		break;
	case 3:		// MMC3 - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper3, 0, sizeof(nesSCardRegMapper3));
		break;
	case 4:		// MMC4 - PRG/16K, VROM/4K, NT, LATCH
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper4, 0, sizeof(nesSCardRegMapper4));
		break;
	case 5:		// MMC5 - BANKING, IRQ, SOUND, VIDEO, MULTIPLY, etc.
		trlMemSet(g_pNesCardFILLRAMMapper5, 0, 0x400);
		trlMemSet(g_pNesCardEXRAMMapper5, 0, 0x400);
		g_pNesSRAMBank = g_pNesSRAM;
		trlMemSet(&g_sNesCardRegMapper5, 0, sizeof(nesSCardRegMapper5));
		g_pNesGrpNameTab[4] = g_pNesCardEXRAMMapper5;
		g_sNesCardRegMapper5.nPRGBankMode = 3;
		for(n = 0 ; n < 4; n++)
		{
			g_sNesCardRegMapper5.nPRGBank[n] = g_pNesROMHeader->nPRGBanks - 1;
			nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[n], n);
		}
		for(n = 0 ; n < 8 ; n++)
			g_sNesCardRegMapper5.nCHRBank[n] = n;
		nesCardRegCHRBank8(0);
		break;
	case 6:		// UNROM - PRG/16K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper6, 0, sizeof(nesSCardRegMapper6));
		break;
	case 7:		// CNROM - VROM/8K
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper7, 0, sizeof(nesSCardRegMapper7));
		g_nPPUCHRRAM=0;
		break;
	case 8:		// GNROM - PRG/32K, VROM/8K
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper8, 0, sizeof(nesSCardRegMapper8));
		break;
	case 9:		// RARE - PRG/32K, Name Table Select
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper9, 0, sizeof(nesSCardRegMapper9));
		break;
	case 10:	// SUNSOFT1 - VROM/4K
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper10, 0, sizeof(nesSCardRegMapper10));
		break;
	case 11:	// SUNSOFT2 - PRG/16K, VROM/8K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper11, 0, sizeof(nesSCardRegMapper11));
		break;
	case 12:	// SUNSOFT3 - PRG/16K, VROM/2K, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper12, 0, sizeof(nesSCardRegMapper12));
		break;
	case 13:	// SUNSOFT4 - PRG/16K, VROM/2K, NT-VROM
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper13, 0, sizeof(nesSCardRegMapper13));
		break;
	case 14:	// SUNSOFT5 - PRG/8K, VROM/1K, NT ctrl, SRAM, IRQ
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(n, n);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper14, 0, sizeof(nesSCardRegMapper14));
		break;
	case 15:	// BANDAI - PRG/16K, VROM/8K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper15, 0, sizeof(nesSCardRegMapper15));
		break;
	case 16:	// VRC1 - PRG/8K, VROM/4K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper16, 0, sizeof(nesSCardRegMapper16));
		break;
	case 17:	// VRC2A - PRG/8K, VROM/1K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper17, 0, sizeof(nesSCardRegMapper17));
		break;
	case 18:	// VRC2B - PRG/8K, VROM/1K, NT, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper18, 0, sizeof(nesSCardRegMapper18));
		break;
	case 19:	// VRC3 - PRG/16K, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper19, 0, sizeof(nesSCardRegMapper19));
		break;
	case 20:	// VRC4A - PRG/8K, VROM/1K, NT, IRQ
	case 21:	// VRC4B - PRG/8K, VROM/1K, NT, IRQ
	case 22:	// VRC4C - PRG/8K, VROM/1K, NT, IRQ
	case 23:	// VRC4D - PRG/8K, VROM/1K, NT, IRQ
	case 24:	// VRC4E - PRG/8K, VROM/1K, NT, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper20, 0, sizeof(nesSCardRegMapper20));
		g_sNesCardRegMapper20.nSubMapper = g_pNesROMHeader->nMapper - 20;
		break;
	case 25:	// VRC6A - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
	case 26:	// VRC6B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper25, 0, sizeof(nesSCardRegMapper25));
		g_sNesCardRegMapper25.nSubMapper = g_pNesROMHeader->nMapper - 25;
		break;
	case 27:	// VRC7A/B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper27, 0, sizeof(nesSCardRegMapper27));
		break;
	case 28:	// JALECO-1 - VROM/8K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper28, 0, sizeof(nesSCardRegMapper28));
		break;
	case 29:	// JALECO-2 - PRG-LO, VROM/8K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper29, 0, sizeof(nesSCardRegMapper29));
		break;
	case 30:	// JALECO-3 - PRG-HI, VROM/8K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper30, 0, sizeof(nesSCardRegMapper30));
		g_sNesCardRegMapper30.nPRGBank = g_pNesROMHeader->nPRGBanks - 2;
		break;
	case 31:	// JALECO-4 - PRG/32K, VROM/8K
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper31, 0, sizeof(nesSCardRegMapper31));
		break;
	case 32:	// JALECO-SS8806 - PRG/8K, VROM/1K, NT, IRQ, EXT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper32, 0, sizeof(nesSCardRegMapper32));
		g_sNesCardRegMapper32.nIRQWidth = 0xFFFF;
		break;
	case 33:	// 74161A - PRG/16K
	case 34:	// 74161B - PRG/16K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper33, 0, sizeof(nesSCardRegMapper33));
		g_sNesCardRegMapper33.nSubMapper = g_pNesROMHeader->nMapper - 33;
		break;
	case 35:	// NAMCOT - PRG/8K, VROM/2K/1K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper35, 0, sizeof(nesSCardRegMapper35));
		break;
	case 36:	// NAMCOT-106 - PRG/8K, VROM/1K/VRAM, IRQ, SOUND
		trlMemSet(g_pNesCardVRAMMapper36, 0, 0x8000);
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper36, 0, sizeof(nesSCardRegMapper36));
		break;
	case 37:	// NAMCO-109 - PRG/8K, VROM/2K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper37, 0, sizeof(nesSCardRegMapper37));
		break;
	case 38:	// NAMCO-118
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper38, 0, sizeof(nesSCardRegMapper38));
		break;
	case 39:	// MMC-3+TLS - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper39, 0, sizeof(nesSCardRegMapper39));
		break;
	case 40:	// TAITO-TC0190 - PRG/8K, VROM/1K/2K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper40, 0, sizeof(nesSCardRegMapper40));
		break;
	case 41:	// TAITO-TC0350 - PRG/8K, VROM/1K/2K, NT, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper41, 0, sizeof(nesSCardRegMapper41));
		break;
	case 42:	// TAITO-TC190V - PRG/8K, VROM/1K/2K, NT, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper42, 0, sizeof(nesSCardRegMapper42));
		break;
	case 43:	// TAITO-X-005 - PRG/8K, VROM/2K/1K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper43, 0, sizeof(nesSCardRegMapper43));
		break;
	case 44:	// TAITO-X1-17 - PRG/8K, VROM/2K/1K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank8(0, 2);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 1, 3);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper44, 0, sizeof(nesSCardRegMapper44));
		break;
	case 45:	// IREM-1 - PRG/32K, VROM/2K, VRAM 6K+2K
		trlMemSet(g_pNesCardVRAMMapper45, 0, 0x2000);
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper45, 0, sizeof(nesSCardRegMapper45));
		break;
	case 46:	// IREM-2 - PRG HI
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 0);
		nesCardRegPRGBank16(0, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper46, 0, sizeof(nesSCardRegMapper46));
		break;
	case 47:	// IREM-74HC161 - PRG/16K, VROM/8K
	case 48:	// IREM-74HC32 - PRG/16K, VROM/8K
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper47, 0, sizeof(nesSCardRegMapper47));
		g_sNesCardRegMapper47.nSubMapper = g_pNesROMHeader->nMapper - 47;
		break;
	case 49:	// IREM-G-101 - PRG/8K, VROM/1K, NT
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper49, 0, sizeof(nesSCardRegMapper49));
		break;
	case 50:	// IREM-H-3001 - PRG/8K, VROM/1K, NT, IRQ
		nesCardRegPRGBank16(0, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper50, 0, sizeof(nesSCardRegMapper50));
		break;
		//add by yuans
	case 51:	// Mapper 185: VROM-disable
		nesCardRegPRGBank32(0);
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper51, 0, sizeof(nesSCardRegMapper51));
		break;
		//end of add
	case 100:	// Disk System - PRG RAM, BIOS, DISK, IRQ, SOUND
		g_pNesSRAMBank = &g_pNesPRGROM[0];
		g_pNesPRGBank[0] = &g_pNesPRGROM[NES_CARD_BANKSIZE_PRG];
		g_pNesPRGBank[1] = &g_pNesPRGROM[NES_CARD_BANKSIZE_PRG*2];
		g_pNesPRGBank[2] = &g_pNesPRGROM[NES_CARD_BANKSIZE_PRG*3];
		g_pNesPRGBank[3] = g_pNesCardMapper100DiskHeader - NES_CARD_DISKSYSTEM_BIOSSIZE;
		nesCardRegCHRBank8(0);
		trlMemSet(&g_sNesCardRegMapper100, 0, sizeof(nesSCardRegMapper100));
		g_pNesCardMapper100Disk = g_pNesCardMapper100DiskHeader;
		break;
	}
}

/** @brief Resume Card */
void nesCardResume()
{
	u32 n;

	switch(g_pNesROMHeader->nMapper)
	{
	case 0:		// NROM - (No Mapper)
		g_nPPUCHRRAM = 0;
		break;
	case 1:		// MMC1 - PRG/32K/16K, VROM/8K/4K, NT
		nesCardRegUpdatePRGBankMapper1();
		if(g_sNesCardRegMapper1.nCHRMode)
		{
			nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR0Bank, 0);
			nesCardRegCHRBank4(g_sNesCardRegMapper1.nCHR1Bank, 4);
			g_nPPUCHRRAM = 0;
		}
		else{
			if(g_pNesROMHeader->nCHRBanks == 0){
				nesCardRegCHRBank8(0);
				g_nPPUCHRRAM = 0xFF;
			}
			else{
				nesCardRegCHRBank8(g_sNesCardRegMapper1.nCHR0Bank);
				g_nPPUCHRRAM = 0;
			}
		}
		
		break;
	case 2:		// MMC2 - PRG/24K/8K, VROM/4K, NT, LATCH
		nesCardRegPRGBank8(g_sNesCardRegMapper2.nPRGBank, 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[0][g_nNesCardLatch[0]], 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper2.nCHRBank[1][g_nNesCardLatch[1]], 4);
		break;
	case 3:		// MMC3 - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper3.nCHRBank[n], n);
		nesCardRegPRGBank8(g_sNesCardRegMapper3.nPRGBank[1], 1);
		nesCardRegPRGBank8(g_sNesCardRegMapper3.nPRGBank[0], g_sNesCardRegMapper3.nPRGArea);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2-g_sNesCardRegMapper3.nPRGArea);
		break;
	case 4:		// MMC4 - PRG/16K, VROM/4K, NT, LATCH
		nesCardRegPRGBank16(g_sNesCardRegMapper4.nPRGBank, 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[0][g_nNesCardLatch[0]], 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper4.nCHRBank[1][g_nNesCardLatch[1]], 4);
		break;
	case 5:		// MMC5 - BANKING, IRQ, SOUND, VIDEO, MULTIPLY, etc.
		for(n = 0 ; n < 4 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper5.nPRGBank[n], n);

		for(n = 0 ; n < (12 - g_sNesCardRegMapper5.nEXRAMMode*4) ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper5.nCHRBank[n], n);

		nesCardRegSRAMBank(g_sNesCardRegMapper5.nSRAMBank);
		for(n = 0 ; n < 4 ; n++)
		{
			switch((g_sNesCardRegMapper5.nNameTabSelect>>(n*2)) & 0x3)
			{
			case 0:		// BLK0
				g_pNesGrpNameTab[n] = g_pNesVRAM;
				break;
			case 1:		// BLK1
				g_pNesGrpNameTab[n] = g_pNesVRAM + 0x400;
				break;
			case 2:		// EXRAM
				g_pNesGrpNameTab[n] = g_pNesCardEXRAMMapper5;
				break;
			case 3:		// FILLMODE
				g_pNesGrpNameTab[n] = g_pNesCardFILLRAMMapper5;
				break;
			}
		}
		if(g_sNesCardRegMapper5.nEXRAMMode == 1)
			nesGrpChangeRenderBG(NES_GRP_BG_MMC5);
		else
			nesGrpChangeRenderBG(NES_GRP_BG_NORMAL);
		g_nNesGrpPatternTabBG = g_sNesCardRegMapper5.nCHRBankMode ? 8 : 0;
		trlMemSet(g_pNesCardFILLRAMMapper5, g_sNesCardRegMapper5.nFillTileNumber, 0x3C0);
		trlMemSet(&g_pNesCardFILLRAMMapper5[0x3C0], g_sNesCardRegMapper5.nFillPalNumber, 0x40);
		break;
	case 6:		// UNROM - PRG/16K
		nesCardRegPRGBank16(g_sNesCardRegMapper6.nPRGBank, 0);
		nesCardRegPRGBank16(g_pNesROMHeader->nPRGBanks - 2, 2);
		break;
	case 7:		// CNROM - VROM/8K
		nesCardRegCHRBank8(g_sNesCardRegMapper7.nCHRBank);
		break;
	case 8:		// GNROM - PRG/32K, VROM/8K
		nesCardRegPRGBank32(g_sNesCardRegMapper8.nPRGBank);
		nesCardRegCHRBank8(g_sNesCardRegMapper8.nCHRBank);
		break;
	case 9:		// RARE - PRG/32K, Name Table Select
		nesCardRegPRGBank32(g_sNesCardRegMapper9.nPRGBank);
		break;
	case 10:	// SUNSOFT1 - VROM/4K
		nesCardRegCHRBank4(g_sNesCardRegMapper10.nCHRBank0, 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper10.nCHRBank1, 4);
		break;
	case 11:	// SUNSOFT2 - PRG/16K, VROM/8K, NT
		nesCardRegPRGBank16(g_sNesCardRegMapper11.nPRGBank, 0);
		nesCardRegCHRBank8(g_sNesCardRegMapper11.nCHRBank);
		break;
	case 12:	// SUNSOFT3 - PRG/16K, VROM/2K, IRQ
		nesCardRegPRGBank16(g_sNesCardRegMapper12.nPRGBank, 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[1], 2);
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[2], 4);
		nesCardRegCHRBank2(g_sNesCardRegMapper12.nCHRBank[3], 6);
		break;
	case 13:	// SUNSOFT4 - PRG/16K, VROM/2K, NT-VROM
		nesCardRegPRGBank16(g_sNesCardRegMapper13.nPRGBank, 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[1], 2);
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[2], 4);
		nesCardRegCHRBank2(g_sNesCardRegMapper13.nCHRBank2[3], 6);
		if(g_sNesCardRegMapper13.nCHRMode)
			nesCardRegUpdateNameTable();
		break;
	case 14:	// SUNSOFT5 - PRG/8K, VROM/1K, NT ctrl, SRAM, IRQ
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper14.nPRGBank[n], n);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper14.nCHRBank[n], n);
		if(g_sNesCardRegMapper14.nPRGMode)
			g_pNesSRAMBank = g_pNesPRGROM + g_sNesCardRegMapper14.nSRAMBank * 0x2000;
		else
			g_pNesSRAMBank = g_pNesSRAM;
		break;
	case 15:	// BANDAI - PRG/16K, VROM/8K, NT
		nesCardRegPRGBank16(g_sNesCardRegMapper15.nPRGBank, 0);
		nesCardRegCHRBank8(g_sNesCardRegMapper15.nCHRBank);
		break;
	case 16:	// VRC1 - PRG/8K, VROM/4K, NT
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper16.nPRGBank[n], n);
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[0], 0);
		nesCardRegCHRBank4(g_sNesCardRegMapper16.nCHRBank[1], 4);
		break;
	case 17:	// VRC2A - PRG/8K, VROM/1K, NT
		nesCardRegPRGBank8(g_sNesCardRegMapper17.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper17.nPRGBank[1], 1);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper17.nCHRBank[n], n);
		break;
	case 18:	// VRC2B - PRG/8K, VROM/1K, NT, IRQ
		nesCardRegPRGBank8(g_sNesCardRegMapper18.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper18.nPRGBank[1], 1);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper18.nCHRBank[n], n);
		break;
	case 19:	// VRC3 - PRG/16K, IRQ
		nesCardRegPRGBank16(g_sNesCardRegMapper19.nPRGBank, 0);
		break;
	case 20:	// VRC4A - PRG/8K, VROM/1K, NT, IRQ
	case 21:	// VRC4B - PRG/8K, VROM/1K, NT, IRQ
	case 22:	// VRC4C - PRG/8K, VROM/1K, NT, IRQ
	case 23:	// VRC4D - PRG/8K, VROM/1K, NT, IRQ
	case 24:	// VRC4E - PRG/8K, VROM/1K, NT, IRQ
		nesCardRegPRGBank8(g_sNesCardRegMapper20.nPRGBank[g_sNesCardRegMapper20.nPRGBankMode], g_sNesCardRegMapper20.nPRGBankMode);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2 - g_sNesCardRegMapper20.nPRGBankMode);
		nesCardRegPRGBank8(g_sNesCardRegMapper20.nPRGBank[1], 1);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper20.nCHRBank[n], n);
		break;
	case 25:	// VRC6A - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
	case 26:	// VRC6B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		nesCardRegPRGBank16(g_sNesCardRegMapper25.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper25.nPRGBank[1], 2);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper25.nCHRBank[n], n);
		break;
	case 27:	// VRC7A/B - PRG/16K/8K, VROM/1K, NT, IRQ, SOUND
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper27.nPRGBank[n], n);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper27.nCHRBank[n], n);
		break;
	case 28:	// JALECO-1 - VROM/8K
		nesCardRegCHRBank8(g_sNesCardRegMapper28.nCHRBank);
		break;
	case 29:	// JALECO-2 - PRG-LO, VROM/8K
		nesCardRegPRGBank16(g_sNesCardRegMapper29.nPRGBank, 0);
		nesCardRegCHRBank8(g_sNesCardRegMapper29.nCHRBank);
		break;
	case 30:	// JALECO-3 - PRG-HI, VROM/8K
		nesCardRegPRGBank16(g_sNesCardRegMapper30.nPRGBank, 2);
		nesCardRegCHRBank8(g_sNesCardRegMapper30.nCHRBank);
		break;
	case 31:	// JALECO-4 - PRG/32K, VROM/8K
		nesCardRegPRGBank32(g_sNesCardRegMapper31.nPRGBank);
		nesCardRegCHRBank8(g_sNesCardRegMapper31.nCHRBank);
		break;
	case 32:	// JALECO-SS8806 - PRG/8K, VROM/1K, NT, IRQ, EXT
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper32.nPRGBank[n], n);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper32.nCHRBank[n], n);
		break;
	case 33:	// 74161A - PRG/16K
	case 34:	// 74161B - PRG/16K
		nesCardRegPRGBank16(g_sNesCardRegMapper33.nPRGBank, 0);
		break;
	case 35:	// NAMCOT - PRG/8K, VROM/2K/1K
		for(n = 0 ; n < 4 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper35.nCHRBank1[n], 4+n);
		for(n = 0 ; n < 2; n++)
		{
			nesCardRegCHRBank2(g_sNesCardRegMapper35.nCHRBank0[n], n);
			nesCardRegPRGBank8(g_sNesCardRegMapper35.nPRGBank[n], n);
		}
		break;
	case 36:	// NAMCOT-106 - PRG/8K, VROM/1K/VRAM, IRQ, SOUND
		for(n = 0 ; n < 8 ; n++)
		{
			if(g_sNesCardRegMapper36.nCHRMode[n>>2] || (g_sNesCardRegMapper36.nCHRBank[n] < 0xE0))
				nesCardRegCHRBank1(g_sNesCardRegMapper36.nCHRBank[n], 0);
			else
				nesCardRegCHRBankMapper36(g_sNesCardRegMapper36.nCHRBank[n] - 0xE0, 0);
		}
		for(n = 0 ; n < 4 ; n++)
		{
			if(g_sNesCardRegMapper36.nNameTabMode[n] < 0xE0)
				g_pNesGrpNameTab[n] = g_pNesCHRROM + g_sNesCardRegMapper36.nNameTabMode[n] * 0x400;
			else
				g_pNesGrpNameTab[n] = g_pNesVRAM + (g_sNesCardRegMapper36.nNameTabMode[n] & 0x1) * 0x400;
		}
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[1], 1);
		nesCardRegPRGBank8(g_sNesCardRegMapper36.nPRGBank[2], 2);
		break;
	case 37:	// NAMCO-109 - PRG/8K, VROM/2K
		nesCardRegCHRBank2(g_sNesCardRegMapper37.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper37.nCHRBank[1], 2);
		nesCardRegCHRBank2(g_sNesCardRegMapper37.nCHRBank[2], 4);
		nesCardRegCHRBank2(g_sNesCardRegMapper37.nCHRBank[3], 6);
		nesCardRegPRGBank8(g_sNesCardRegMapper37.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper37.nPRGBank[1], 1);
		break;
	case 38:	// NAMCO-118
		for(n = 0 ; n < 4 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper38.nCHRBank1[n], 4+n);
		for(n = 0 ; n < 2; n++)
		{
			nesCardRegCHRBank2(g_sNesCardRegMapper38.nCHRBank0[n], n);
			nesCardRegPRGBank8(g_sNesCardRegMapper38.nPRGBank[n], n);
		}
		break;
	case 39:	// MMC-3+TLS - PRG/8K, VROM/2K/1K, VT, SRAM, IRQ
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper39.nCHRBank[n], n);
		nesCardRegPRGBank8(g_sNesCardRegMapper39.nPRGBank[1], 1);
		nesCardRegPRGBank8(g_sNesCardRegMapper39.nPRGBank[0], g_sNesCardRegMapper39.nPRGArea);
		nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2-g_sNesCardRegMapper39.nPRGArea);
		break;
	case 40:	// TAITO-TC0190 - PRG/8K, VROM/1K/2K, NT
		nesCardRegPRGBank8(g_sNesCardRegMapper40.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper40.nPRGBank[1], 1);
		nesCardRegCHRBank2(g_sNesCardRegMapper40.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper40.nCHRBank[1], 2);
		for(n = 2 ; n < 6 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper40.nCHRBank[n], n+2);
		break;
	case 41:	// TAITO-TC0350 - PRG/8K, VROM/1K/2K, NT, IRQ
		nesCardRegPRGBank8(g_sNesCardRegMapper41.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper41.nPRGBank[1], 1);
		nesCardRegCHRBank2(g_sNesCardRegMapper41.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper41.nCHRBank[1], 2);
		for(n = 2 ; n < 6 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper41.nCHRBank[n], n+2);
		break;
	case 42:	// TAITO-TC190V - PRG/8K, VROM/1K/2K, NT, IRQ
		nesCardRegPRGBank8(g_sNesCardRegMapper42.nPRGBank[0], 0);
		nesCardRegPRGBank8(g_sNesCardRegMapper42.nPRGBank[1], 1);
		nesCardRegCHRBank2(g_sNesCardRegMapper42.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper42.nCHRBank[1], 2);
		for(n = 2 ; n < 6 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper42.nCHRBank[n], n+2);
		break;
	case 43:	// TAITO-X-005 - PRG/8K, VROM/2K/1K, NT
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper43.nPRGBank[n], n);
		nesCardRegCHRBank2(g_sNesCardRegMapper43.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper43.nCHRBank[1], 2);
		for(n = 2 ; n < 6 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper43.nCHRBank[n], n+2);
		break;
	case 44:	// TAITO-X1-17 - PRG/8K, VROM/2K/1K
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper44.nPRGBank[n], n);
		nesCardRegCHRBank2(g_sNesCardRegMapper44.nCHRBank[0], 0);
		nesCardRegCHRBank2(g_sNesCardRegMapper44.nCHRBank[1], 2);
		for(n = 2 ; n < 6 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper44.nCHRBank[n], n+2);
		break;
	case 45:	// IREM-1 - PRG/32K, VROM/2K, VRAM 6K+2K
		nesCardRegPRGBank32(g_sNesCardRegMapper45.nPRGBank);
		nesCardRegCHRBank2(g_sNesCardRegMapper45.nCHRBank, 0);
		break;
	case 46:	// IREM-2 - PRG HI
		nesCardRegPRGBank16(g_sNesCardRegMapper46.nPRGBank, 2);
		break;
	case 47:	// IREM-74HC161 - PRG/16K, VROM/8K
	case 48:	// IREM-74HC32 - PRG/16K, VROM/8K
		nesCardRegPRGBank16(g_sNesCardRegMapper47.nPRGBank, 0);
		nesCardRegCHRBank8(g_sNesCardRegMapper47.nCHRBank);
		break;
	case 49:	// IREM-G-101 - PRG/8K, VROM/1K, NT
		if(g_sNesCardRegMapper49.nPRGMode)
		{
			nesCardRegPRGBank8(0, 0);
			nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[0], 2);
		}
		else
		{
			nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[0], 0);
			nesCardRegPRGBank8(g_pNesROMHeader->nPRGBanks - 2, 2);
		}
		nesCardRegPRGBank8(g_sNesCardRegMapper49.nPRGBank[1], 1);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper49.nCHRBank[n], n);
		break;
	case 50:	// IREM-H-3001 - PRG/8K, VROM/1K, NT, IRQ
		for(n = 0 ; n < 3 ; n++)
			nesCardRegPRGBank8(g_sNesCardRegMapper50.nPRGBank[n], n);
		for(n = 0 ; n < 8 ; n++)
			nesCardRegCHRBank1(g_sNesCardRegMapper50.nCHRBank[n], n);
		break;

	case 51:
		nesCardRegCHRBank8(g_sNesCardRegMapper51.nCHRBank);
		break;

	case 100:	// Disk System - PRG RAM, BIOS, DISK, IRQ, SOUND
		nesCardDiskSystemReloadRom();
		g_pNesCardMapper100DiskHeader = (u8*)(g_pNesEmuBuf->pRomBuf) + sizeof(nesSROMHeader) + NES_CARD_DISKSYSTEM_BIOSSIZE;
		g_pNesCardMapper100Disk = g_pNesCardMapper100DiskHeader + g_sNesCardRegMapper100.nSide * 0x10000;
		nesCardRegMapper100Save(0);
		break;
	}
}

/** @brief Exit Card */
void nesCardExit()
{
	switch(g_pNesROMHeader->nMapper)
	{
	case 5:		// MMC5 - BANKING, IRQ, SOUND, VIDEO, MULTIPLY, etc.
		trlMemFree(g_pNesCardFILLRAMMapper5);
		trlMemFree(g_pNesCardEXRAMMapper5);
		break;
	case 36:	// NAMCOT-106 - PRG/8K, VROM/1K/VRAM, IRQ, SOUND
		trlMemFree(g_pNesCardVRAMMapper36);
		break;
	case 45:	// IREM-1 - PRG/32K, VROM/2K, VRAM 6K+2K
		trlMemFree(g_pNesCardVRAMMapper45);
		break;
	}
	if(g_pNesSRAM)
		trlMemFree(g_pNesSRAM);
}
