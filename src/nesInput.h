/**
 * @file nesInput.h
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Input
 */
#ifndef NESINPUT_H
#define	NESINPUT_H

#include "nesGlobal.h"

/** @name Macro Define */
//@{
#define	NES_INPUT_SAVEDATA_MAX	5												///< Input Save Data Count
//@}

/** @name Global Variable */
//@{
extern u32						g_nNesInputCount;								///< Input Count
extern u8						g_nNesInputReg;									///< Input Register
extern u8						g_nNesInputMic;									///< Input Mic
extern u8						g_nNesInputBit[2];								///< Bit Count
extern u8						g_nNesInputJoy[4];								///< Joypad Buffer
extern u8						g_nNesInputBuf[4];								///< Input Buffer
extern u32						g_nNesInputSaveData;							///< Input Save Data Count
extern trlSEmuShellResume		g_sNesInputSaveData[NES_INPUT_SAVEDATA_MAX];	///< Input Save Data
//@}

/** @brief Initialize */
void nesInputInit();
/** @brief Reset */
void nesInputReset();
/** @brief Resume */
void nesInputResume();
/** @brief Update */
void nesInputUpdate(u32 nKeyBuf);

void nesInputRegisterWrite();
u8 nesInputRegisterRead(u32);

#endif
