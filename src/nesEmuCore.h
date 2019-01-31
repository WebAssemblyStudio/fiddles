/**
 * @file nesEmuCore.h
 * @author chentian
 * @date 2010.06.24
 * @brief TRL Emulate For CTR - Emu Core NES
 */
#pragma once
#include "nesGlobal.h"

/** @name Macro Define */
//@{
//@}

/** @brief EmuCore Initialize */
void nesEmuCoreInit(trlSEmuShellBuffer* pBuf);
/** @brief EmuCore Run One Frame */
void nesEmuCoreRunOneFrame();
/** @brief EmuCore Reset */
void nesEmuCoreReset();
/** @brief EmuCore Resume */
void nesEmuCoreResume();
/** @brief EmuCore Exit */
void nesEmuCoreExit();
/** @brief EmuCore Patch */
void nesEmuCorePatch(trlSEmuShellPatch* pPatch);
/** @brief EmuCore Initialize */
void nesEmuCoreConfig();
/** @brief Single Mode Swap Player */
u32 nesEmuCoreSwapPlayer(s32 nMode);
