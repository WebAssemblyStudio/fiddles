/**
 * @file nesGlobal.cpp
 * @author Chentian
 * @date 2010.06.24
 * @brief NES Emulate For CTR - Global data
 */
#include "nesGlobal.h"

/** @name Macro Define */
//@{
//@}

/** @name Global Variable */
//@{
u8*				g_pNesPRGROM = NULL;							///< PRG Cartridge
u8*				g_pNesCHRROM = NULL;							///< CHR Cartridge
u8*				g_pNesWRAM = NULL;								///< Work RAM
u8*				g_pNesVRAM = NULL;								///< Video RAM
u8*				g_pNesSPRRAM = NULL;							///< Sprite Attribute Table
u8*				g_pNesPALRAM = NULL;							///< Palette RAM
u8*				g_pNesSRAM = NULL;								///< SRAM
u8*				g_pNesPRGBank[4] = {0,0,0,0};					///< PRG Banks
u8*				g_pNesCHRBank[12] = {0,0,0,0,0,0,0,0,0,0,0,0};	///< CHR Banks
u8*				g_pNesSRAMBank = NULL;							///< SRAM Bank

nesSROMHeader*	g_pNesROMHeader = NULL;							///< The Cartridge Header Data
u32				g_nNesBreakFlag = 0;							///< Break Flag

u8 g_pYosHeap[YOS_HEAPEND];

void trlSEmuShellResumeSetData(trlSEmuShellResume *p,void* _pValue, u32 _nSize, u32 _nVer, u32 _nDelVer)
{
	p->pValue = _pValue;
	p->nSize = _nSize;
	p->nVer = _nVer;
	p->nDelVer = _nDelVer;
}

void trlSEmuShellPatchActiveClear(trlSEmuShellPatchActive *p)
{
	p->nIndex = p->nDelay = p->nMode = p->nFade = 0;
	p->nValue = 0;
}

void trlMemCopy(void *d,void *s,unsigned long n)
{
	unsigned long n2;
	unsigned char *d3,*s3;
	n2 = n >> 2;
	if(n2){
		unsigned long *d2,*s2;
		d2 = (unsigned long *)d;
		s2 = (unsigned long *)s;
		for(;n2;n2--){
			*d2 = *s2;
			d2++;
			s2++;
		}
		d3 = (unsigned char *)d2;
		s3 = (unsigned char *)s2;
	}
	else{
		d3 = (unsigned char *)d;
		s3 = (unsigned char *)s;
	}
	n &= 3;
	if(n){
		for(;n;n--){
			*d3 = *s3;
			d3++;
			s3++;
		}
	}
}
void trlMemSet(void *d,unsigned long c,unsigned long n)
{
	unsigned long n2;
	unsigned char *d3;
	n2 = n >> 2;
	if(n2){
		unsigned long *d2;
		d2 = (unsigned long *)d;
		c = (c << 24)|(c << 16)|(c << 8)|c;
		for(;n2;n2--){
			*d2++ = c;
		}
		d3 = (unsigned char *)d2;
	}
	else{
		d3 = (unsigned char *)d;
	}
	n &= 3;
	if(n){
		for(;n;n--){
			*d3++ = (unsigned char)c;
		}
	}
}

void trlMemFree(void *p)
{
	(void *)p;
}

//@}
