/**
 * @file nesEmuCore.cpp
 * @author chentian
 * @date 2010.06.24
 * @brief TRL Emulate For CTR - Emu Core NES
 */
#include "nesEmuCore.h"
#include "nesMemory.h"
#include "nesCard.h"
#include "nesGraphic.h"
#include "nesSound.h"
#include "nesCPU.h"
#include "nesInput.h"

/** @name Macro Define */
//@{
#define NES_EMU_SAVEDATA_MAX	8									///< EmuCore Save Data Max Count
//@}

/** @name Global Variable */
//@{
trlSEmuShellBuffer*		g_pNesEmuBuf = NULL;						///< Emu Engine Buffer Data
trlSEmuShellCore		g_sEmuCoreNES = {
	nesEmuCoreInit,
	nesEmuCoreRunOneFrame,
	nesEmuCoreReset,
	nesInputUpdate,
	nesEmuCoreResume,
	nesEmuCoreExit,
	nesEmuCorePatch,
	NULL,
	NULL,
	nesEmuCoreSwapPlayer,
	NULL };
u32						g_nNesEmuSaveData;							///< EmuCore Save Data Count
trlSEmuShellResume		g_sNesEmuSaveData[NES_EMU_SAVEDATA_MAX];	///< EmuCore Save Data
u32						g_nNesEmuSwitchPlayer;						///< EmuCore Switch Player
//@}

/** @brief EmuCore Initialize */
void nesEmuCoreInit(trlSEmuShellBuffer* pBuf)
{
	if(pBuf == NULL)
		return;

	g_pNesEmuBuf = pBuf;
	g_nNesEmuSwitchPlayer = 0;

	// Initialize
	nesMemInit();
	nesCardInit();
	nesGrpInit();
	nesSndInit();
	nesInputInit();
	nesCpuInit();

	// Save Data
	g_nNesEmuSaveData = 0;
	trlSEmuShellResumeSetData(&g_sNesEmuSaveData[g_nNesEmuSaveData++],&g_nNesEmuSwitchPlayer, 4, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesEmuSaveData[g_nNesEmuSaveData++],&g_pNesEmuBuf->nPatchMask, 4, 2, 0);
	trlSEmuShellResumeSetData(&g_sNesEmuSaveData[g_nNesEmuSaveData++],&g_pNesEmuBuf->nPatchPalette, 4, 2, 0);
	trlSEmuShellResumeSetData(&g_sNesEmuSaveData[g_nNesEmuSaveData++],&g_pNesEmuBuf->nPatchActive, 4, 2, 0);
	trlSEmuShellResumeSetData(&g_sNesEmuSaveData[g_nNesEmuSaveData++],g_pNesEmuBuf->sPatchActive, sizeof(trlSEmuShellPatchActive)*TRL_EMUCORE_PATCH_ACTIVEMAX, 2, 0);

	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[0],g_sNesEmuSaveData, g_nNesEmuSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[1],g_sNesMemSaveData, g_nNesMemSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[2],g_sNesCpuSaveData, g_nNesCpuSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[3],g_sNesInputSaveData, g_nNesInputSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[4],g_sNesGrpSaveData, g_nNesGrpSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[5],g_sNesSndSaveData, g_nNesSndSaveData, 1, 0);
	trlSEmuShellResumeSetData(&g_pNesEmuBuf->pSaveData[6],g_sNesCardSaveData, g_nNesCardSaveData, 1, 0);
}

/** @brief EmuCore Patch */
void nesEmuCorePatch(trlSEmuShellPatch* pPatch)
{
	extern void nesGrpUpdatePalA();
	u32 i;

	switch(pPatch->sData.sA.nMode)
	{
	case 7:
	case 4:
		switch(pPatch->sData.sA.nType)
		{
		case 0:		// Begin
			{
				for(i = 0 ; i < pPatch->sData.sA.nFixcode ; i++)
				{
					g_nNesGrpPalTable[pPatch->pFixcode[i]] = (u16)pPatch->nPalette[i];
				}
			}
			break;
		case 1:		// End
			{
				for(i = 0 ; i < 0x40 ; i++)
					g_nNesGrpPalTable[i] = g_nNesGrpPalTable_Origin[i];
			}
			break;
		}
		nesGrpUpdatePalA();
		break;
	}
}

/** @brief EmuCore RunOneFrame */
void nesEmuCoreRunOneFrame()
{
	extern trlSEmuShellVideoMask g_sTrlVideoMaskData;

	g_pNesEmuBuf->nTexID = 1 - g_pNesEmuBuf->nTexID;
	if(g_pNesEmuBuf->nMotion2Frames < 2)
		g_pNesEmuBuf->nMotion2Frames++;
	g_pNesEmuBuf->pScreenBuf = (u16*)(g_pNesEmuBuf->pTextureBuf[g_pNesEmuBuf->nTexID]) + g_pNesEmuBuf->nScreenBufOffset;

	//trlTraceFrameBegin();
	g_nNesBreakFlag = 0;

	nesSndRegWriteLog_LogBegin();

	while(1)
	{
		s32 nRunTicks,nGrpTicks;
		// Update CPU
		nesCpuRun();
	//	trlTraceTickAdd(g_nNesCpuEventTicks);
		nesSndRegWriteLog_LogTicksAdd(g_nNesCpuEventTicks);
		nRunTicks = g_nNesCpuEventTicks;
		g_nNesCpuEventTicks = 0xFFFFFF;

		// Update Card IRQ
		if(g_nNesCardIRQEnable == NES_CARD_IRQ_CPUCYCLE)
		{
			g_nNesCardIRQTicks -= nRunTicks;
			if(g_nNesCardIRQTicks <= 0)
				nesCardUpdateIRQ();
			if(g_nNesCpuEventTicks > g_nNesCardIRQTicks)
				g_nNesCpuEventTicks = g_nNesCardIRQTicks;
		}

		// Update Disk IRQ
		if(g_nNesCardIRQDiskTicks > 0)
		{
			g_nNesCardIRQDiskTicks -= nRunTicks;
			if(g_nNesCardIRQDiskTicks <= 0)
			{
				if(g_nNesCardIRQDiskEnable)
					g_nNesCpuIRQFlag |= 2;
			}
			else if(g_nNesCpuEventTicks > g_nNesCardIRQDiskTicks)
				g_nNesCpuEventTicks = g_nNesCardIRQDiskTicks;
		}

		// Update Graphic
		g_nNesGrpTicks -= nRunTicks * 3;
		while(g_nNesGrpTicks <= 0)
		{
			g_nNesGrpTicks += NES_GRP_TICKS;
			nesGrpUpdate();
		};
		nGrpTicks = (3 - g_nNesGrpTicks%3 + g_nNesGrpTicks) / 3;
		if(g_nNesCpuEventTicks > nGrpTicks)
			g_nNesCpuEventTicks = nGrpTicks;

		if(g_nNesBreakFlag)
		{
			nesSndRegWriteLog_LogRun();
			nesSndUpdate();
			g_pNesEmuBuf->nFrames++;
		//	trlTraceFrameEnd();
			return;
		}
	}
}

/** @brief EmuCore Reset */
void nesEmuCoreResetCold()
{
	nesCpuReset();
	nesMemReset();
	nesCardReset();
	nesGrpReset();
	nesSndReset();
	nesInputReset();
}


/** @brief EmuCore Reset */
void nesEmuCoreReset()
{
	int i;
	nesSndReset();
	g_nNesCpuRESETFlag = 1;
	for(i = 0 ; i <0x40 ; i++)
			g_nNesGrpPalTable[i] = g_nNesGrpPalTable_Origin[i];
}

/** @brief EmuCore Resume */
void nesEmuCoreResume()
{
	if(g_pNesEmuBuf->nPatchPalette != 0xFFFFFFFF)
	{
		trlSEmuShellPatch* pPatch = &g_pNesEmuBuf->pPatchData[g_pNesEmuBuf->nPatchPalette];
		nesEmuCorePatch(pPatch);
	}
	else
	{
		int i;
		for(i = 0 ; i < 0x40 ; i++)
			g_nNesGrpPalTable[i] = g_nNesGrpPalTable_Origin[i];
	}

	g_pNesEmuBuf->funcChangeMaskMode(0);
	nesMemResume();
	nesCardResume();
	nesInputResume();
	nesSndResume();
	nesGrpResume();
	nesCpuResume();
}

/** @brief EmuCore Exit */
void nesEmuCoreExit()
{
	nesGrpExit();
	nesCardExit();
	nesMemExit();
}

/** @brief EmuCore Config */
void nesEmuCoreConfig()
{
}

/** @brief Single Mode Swap Player */
u32 nesEmuCoreSwapPlayer(s32 nMode)
{
	switch(nMode)
	{
	case 2:
		g_nNesEmuSwitchPlayer = 1 - g_nNesEmuSwitchPlayer;
		break;
	}
	if(g_nNesEmuSwitchPlayer == 0)
		return 0;
	else
		return 2;
}
