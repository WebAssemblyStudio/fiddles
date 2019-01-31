/**
 * @file nesInput.cpp
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Input
 */
#include<windows.h>
#include "nesGlobal.h"
#include "nesInput.h"

/** @name Macro Define */
//@{
//@}

/** @name Global Variable */
//@{
u32						g_nNesInputCount;								///< Input Count
u8						g_nNesInputReg;									///< Input Register
u8						g_nNesInputMic;									///< Input Mic
u8						g_nNesInputBit[2];								///< Bit Count
u8						g_nNesInputJoy[4];								///< Joypad Buffer
u8						g_nNesInputBuf[4];								///< Input Buffer
u32						g_nNesInputSaveData;							///< Input Save Data Count
trlSEmuShellResume		g_sNesInputSaveData[NES_INPUT_SAVEDATA_MAX];	///< Input Save Data
u32						g_nNesInputMask;								///< Input 2P Mask
extern u32				g_nNesEmuSwitchPlayer;							///< Switch Player
//@}

/** @brief Initialize */
void nesInputInit()
{
	g_nNesInputCount = 2;
	g_nNesInputMask = 0xF3;

	// Save Data
	g_nNesInputSaveData = 0;
	trlSEmuShellResumeSetData(&g_sNesInputSaveData[g_nNesInputSaveData++],&g_nNesInputReg, 1, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesInputSaveData[g_nNesInputSaveData++],&g_nNesInputBit, 2, 1, 0);
	trlSEmuShellResumeSetData(&g_sNesInputSaveData[g_nNesInputSaveData++],&g_nNesInputJoy, 4, 1, 0);

	nesInputReset();
}

/** @brief Reset */
void nesInputReset()
{
	u32 n;
	g_nNesInputMic = 0;
	g_nNesInputBit[0] = 0;
	g_nNesInputBit[1] = 0;
	for(n = 0; n < 4 ; n++)
	{
		g_nNesInputJoy[n] = 0;
		g_nNesInputBuf[n] = 0;
	}
}

/** @brief Resume */
void nesInputResume()
{
	u32 n;
	g_nNesInputMic = 0;
	for(n = 0 ; n < 4 ; n++)
		g_nNesInputBuf[n] = 0;
}

/** @brief Update */
void nesInputUpdate(u32 nKeyBuf)
{
	u32 n;

	if(g_nNesEmuSwitchPlayer)
	{
		nKeyBuf <<= 8;
	}

	for(n = 0 ; n < g_nNesInputCount ; n++)
	{
		g_nNesInputBuf[n] = nKeyBuf & 0xFF;
		nKeyBuf >>= 8;
	}
	g_nNesInputBuf[1] &= g_nNesInputMask;
	
	nesInputRegisterWrite();
}

/** @brief Joypads Register Write */
void nesInputRegisterWrite()
{
	if(g_nNesInputReg & 0x1)
	{
		u32 n;
		g_nNesInputBit[0] = 0;
		g_nNesInputBit[1] = 0;

		for(n = 0 ; n < g_nNesInputCount ; n++)
		{
			if(g_nNesInputBuf[n])
				g_nNesInputJoy[n] = (g_nNesInputBuf[n] & 0x0F) + ((g_nNesInputBuf[n]>>2) & 0x30) + ((g_nNesInputBuf[n]<<1) & 0x40) + ((g_nNesInputBuf[n]<<3) & 0x80);
			else
				g_nNesInputJoy[n] = 0;
		}
	}
}

/** @brief Joypads Register Read */
u8 nesInputRegisterRead(u32 nJoyID)
{
	u8 nData;

	if(g_nNesInputBit[nJoyID]>=8)
	{
		if(g_nNesInputCount > (nJoyID+2))
			return 3;
		if(g_nNesInputCount > nJoyID)
			return 1;
		return 0;
	}

	nData = (g_nNesInputJoy[nJoyID] >> g_nNesInputBit[nJoyID]) & 0x1;
	if(g_nNesInputCount > (nJoyID+2))
		nData |= ((g_nNesInputJoy[nJoyID+2] >> g_nNesInputBit[nJoyID]) & 0x1) << 1;
	g_nNesInputBit[nJoyID]++;
	return nData;
}
