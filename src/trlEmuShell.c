/**
* @file trlEmuShell.h
* @author zhfang, chentian
* @date 2009.11.24
* @brief TRL Emulate For PC - EmuShell Main
*/
#include<windows.h>
#include"nesGlobal.h"

/** @name Global Variable */
//@{
#define TRL_INPUT_BUTTON_VALUE				0
#define TRL_INPUT_BUTTON_TRIGGER			1
#define TRL_INPUT_BUTTON_RELEASE			2
#define TRL_INPUT_BUTTON_HOLD				3
#define TRL_INPUT_BUTTON_MAX				4

trlSEmuShellBuffer g_sEmuShellBuffer;
trlSEmuShellCore *g_pEmuShellCore = (trlSEmuShellCore *)NULL;
//trlSEmuShellConfig g_sEmuShellConfig;
//trlSEmuShellConfig g_sEmuShellPatch;
u32 g_bQuit = 0;
s32 g_sEmuShellRomIndex = 0;
s32 g_eTrlEmuShellState;
s32 g_bTrlEmuBootError;
//s32 g_bTrlEmuLayoutMenuShow = 0;
//s32 g_bTrlEmuLayoutMenuShow1 = 0;
//u32 g_nTrlEmuMenuDelay = 200;
//u32 g_nTrlEmuMenuSwitchGBColorDelay = 60;
//u32 g_nTrlEmuMenuCt = 0;
//u32 g_nTrlEmuMenuColorTime = 0;
//u32 g_nTrlEmuMenuDebugTime = 0;
//u32 g_nTrlEmuMenuSwitchGBColorTime = 0;
u32 g_nTrlEmuShellSwitchRom = 1;
//extern trlSEmuShellResumeInfo g_sEmuShellResumeInfo;
extern unsigned char HVCSM0A_042[];
u32 g_bStepRun = 0;
u32 g_nTrlInputButton[TRL_INPUT_BUTTON_MAX];
trlSEmuShellVideoMask	g_sTrlVideoMaskData;
HDC						g_hTrlVideoDC;
BITMAPV4HEADER			g_hTrlVideoBmi;
//@}

void trlEmuShellDataLoadRom(void)
{
	extern unsigned char HVCSM0A_042[];
	g_sEmuShellBuffer.pRomBuf = &g_pYosHeap[YOS_ROMDATA];
	g_sEmuShellBuffer.nRomBufSize = 0xA010;	//MARIO
	trlMemCopy(g_sEmuShellBuffer.pRomBuf,HVCSM0A_042,g_sEmuShellBuffer.nRomBufSize);

	// Choice ROM Type
	//g_sEmuShellBuffer.nRomType = TRL_EMUCORE_ROMTYPE_NES;
	g_sEmuShellBuffer.nRomSubType = 0;
}

/** @brief EmuShell Data Initialize */
void trlEmuShellDataInit(u32 nIndex)
{
	trlMemSet(&g_sEmuShellBuffer, 0, sizeof(trlSEmuShellBuffer));
	//trlMemSet(&g_sEmuShellConfig, 0, sizeof(trlSEmuShellConfig));
	//trlMemSet(&g_sEmuShellPatch, 0, sizeof(trlSEmuShellConfig));

	trlEmuShellDataLoadRom();
//	trlEmuShellDataLoadPatch();
//	trlEmuShellDataLoadConfig();

	{	//case TRL_EMUCORE_ROMTYPE_NES:
		g_pEmuShellCore = &g_sEmuCoreNES;
		g_sEmuShellBuffer.nWidth = 256;
		g_sEmuShellBuffer.nHeight = 240;
		g_sEmuShellBuffer.nSaveDataSize = 7;
		g_sEmuShellBuffer.nKeyMask = 0x000000FF;
	}
	if(g_sEmuShellBuffer.nSaveDataSize)
		g_sEmuShellBuffer.pSaveData = (trlSEmuShellResume*)&g_pYosHeap[YOS_RESUMESAVE];
		// trlMemAlloc(sizeof(trlSEmuShellResume)*g_sEmuShellBuffer.nSaveDataSize);
	//g_sEmuShellResumeInfo.pCapture = (u16*)trlMemAlloc(TRL_EMUCORE_TEX_X*TRL_EMUCORE_TEX_Y*2);
	//trlMemSet(g_sEmuShellResumeInfo.pCapture, 0, TRL_EMUCORE_TEX_X*TRL_EMUCORE_TEX_Y*2);

	g_sEmuShellBuffer.nSaveUpdate = 0;
	g_sEmuShellBuffer.nSaveFlag = 0;

	g_sEmuShellBuffer.nFrames = 0;
	g_sEmuShellBuffer.bFrameDelayEnable = 0;
	g_sEmuShellBuffer.nFrameMark = 0;
	g_sEmuShellBuffer.nFrameDelay = 0;
	g_sEmuShellBuffer.nFrameDouble = 0;
	g_sEmuShellBuffer.nPatchMask = 0xFFFFFFFF;
	g_sEmuShellBuffer.nPatchPalette = 0xFFFFFFFF;
	g_sEmuShellBuffer.nPatchActive = 0;
	trlMemSet(g_sEmuShellBuffer.sPatchActive, 0, sizeof(trlSEmuShellPatchActive)*TRL_EMUCORE_PATCH_ACTIVEMAX);

	g_sEmuShellBuffer.nVSyncEnable = 1;//TRL_VSYNC;
	//g_sEmuShellBuffer.funcSaveBackup = trlEmuShellDataSaveBackup;

	g_sEmuShellBuffer.nMotion2Frames = 0;
}

void trlEmuShellVideoMaskChangeMode(u32 nMode)
{
	g_sTrlVideoMaskData.nMode = nMode;
	g_sTrlVideoMaskData.pDarkEnable = &g_sTrlVideoMaskData.bDarkEnable[nMode];
	g_sTrlVideoMaskData.pReduceEnable = &g_sTrlVideoMaskData.bReduceEnable[nMode];
	g_sTrlVideoMaskData.pMotionBEnable = &g_sTrlVideoMaskData.bMotionBEnable[nMode];
	g_sTrlVideoMaskData.pDark = &g_sTrlVideoMaskData.nDark[nMode];
	g_sTrlVideoMaskData.pReduceColorR = &g_sTrlVideoMaskData.nReduceColorR[nMode];
	g_sTrlVideoMaskData.pReduceColorG = &g_sTrlVideoMaskData.nReduceColorG[nMode];
	g_sTrlVideoMaskData.pReduceColorB = &g_sTrlVideoMaskData.nReduceColorB[nMode];
	g_sTrlVideoMaskData.pMotionBlur = &g_sTrlVideoMaskData.nMotionBlur[nMode];
}

/** @brief Init */
void trlEmuShellVideoInit()
{
	g_sEmuShellBuffer.nTexWidth = TRL_EMUCORE_TEX_X;
	g_sEmuShellBuffer.nTexHeight = TRL_EMUCORE_TEX_Y;
	g_sEmuShellBuffer.pTextureBuf[0] = (void *)&g_pYosHeap[YOS_TEXBUF0];
	g_sEmuShellBuffer.pTextureBuf[1] = (void *)&g_pYosHeap[YOS_TEXBUF1];
	g_sEmuShellBuffer.pScreenBuf = g_sEmuShellBuffer.pTextureBuf[0];
	g_sEmuShellBuffer.nTexID = 0;
	trlMemSet(g_sEmuShellBuffer.pTextureBuf[0], 0, TRL_EMUCORE_TEX_X*TRL_EMUCORE_TEX_Y*2);
	trlMemSet(g_sEmuShellBuffer.pTextureBuf[1], 0, TRL_EMUCORE_TEX_X*TRL_EMUCORE_TEX_Y*2);

	memset(&g_hTrlVideoBmi, 0, sizeof(g_hTrlVideoBmi));
	g_hTrlVideoBmi.bV4Size			= sizeof(BITMAPV4HEADER);
	g_hTrlVideoBmi.bV4Width			= g_sEmuShellBuffer.nTexWidth;
	g_hTrlVideoBmi.bV4Height		= -g_sEmuShellBuffer.nTexHeight;
	g_hTrlVideoBmi.bV4Planes		= 1;
	g_hTrlVideoBmi.bV4BitCount		= 16;
	g_hTrlVideoBmi.bV4V4Compression = BI_BITFIELDS;
	g_hTrlVideoBmi.bV4ClrUsed		= 1;

	g_hTrlVideoBmi.bV4RedMask	  = 0xF800;
	g_hTrlVideoBmi.bV4GreenMask   = 0x07C0;
	g_hTrlVideoBmi.bV4BlueMask    = 0x003E;

	g_sEmuShellBuffer.funcChangeMaskMode = trlEmuShellVideoMaskChangeMode;

	// Init Mask
	g_sTrlVideoMaskData.bDarkEnable[0] = 0;
	g_sTrlVideoMaskData.bReduceEnable[0] = 0;
	g_sTrlVideoMaskData.bMotionBEnable[0] = 0;
	g_sTrlVideoMaskData.nDark[0] = 10;
	g_sTrlVideoMaskData.nReduceColorR[0] = 0;
	g_sTrlVideoMaskData.nReduceColorG[0] = 0;
	g_sTrlVideoMaskData.nReduceColorB[0] = 0;
	g_sTrlVideoMaskData.nMotionBlur[0] = 31;
	
	g_sTrlVideoMaskData.bDarkEnable[1] = 1;
	g_sTrlVideoMaskData.bReduceEnable[1] = 0;
	g_sTrlVideoMaskData.bMotionBEnable[1] = 1;
	g_sTrlVideoMaskData.nDark[1] = 7;
	g_sTrlVideoMaskData.nReduceColorR[1] = 0;
	g_sTrlVideoMaskData.nReduceColorG[1] = 0;
	g_sTrlVideoMaskData.nReduceColorB[1] = 0;
	g_sTrlVideoMaskData.nMotionBlur[1] = 8;

	trlEmuShellVideoMaskChangeMode(0);
}

void trlEmuShellVideoFrame()
{
	//SetDIBitsToDevice(g_hTrlVideoDC, -8,0,g_sEmuShellBuffer.nWidth+8,g_sEmuShellBuffer.nHeight,0,0,0,g_sEmuShellBuffer.nHeight, g_sEmuShellBuffer.pScreenBuf,(BITMAPINFO*)&g_hTrlVideoBmi,DIB_RGB_COLORS);
}

/** @brief EmuShell Input Init */
void trlEmuShellInputInit()
{
	trlMemSet(g_nTrlInputButton, 0, TRL_INPUT_BUTTON_MAX*sizeof(u32));
}

/** @brief EmuShell Input Update Button */
void trlEmuShellUpdateInput()
{
	extern unsigned short g_nKeyBuf;
	static u32 nLastPad = 0;
	u32 nPrev,nPad;
	nPrev = g_nTrlInputButton[TRL_INPUT_BUTTON_VALUE];
	g_nTrlInputButton[TRL_INPUT_BUTTON_VALUE] = (~g_nKeyBuf) & 0xFFFF;
	g_nTrlInputButton[TRL_INPUT_BUTTON_TRIGGER] = (g_nTrlInputButton[TRL_INPUT_BUTTON_VALUE] & ~nPrev);
	g_nTrlInputButton[TRL_INPUT_BUTTON_RELEASE] = (~g_nTrlInputButton[TRL_INPUT_BUTTON_VALUE] & nPrev);
	g_nTrlInputButton[TRL_INPUT_BUTTON_HOLD] = (g_nTrlInputButton[TRL_INPUT_BUTTON_VALUE] & nPrev);

	nPad = g_nTrlInputButton[TRL_INPUT_BUTTON_HOLD] & g_sEmuShellBuffer.nKeyMask;
	if(nLastPad != nPad){
		nLastPad = nPad;
		g_pEmuShellCore->trlEmuCoreInput(nPad);
	}
}

/** @brief EmuShell Init */
void trlEmuShellInit(void)
{
	trlEmuShellDataInit(g_sEmuShellRomIndex);
	trlEmuShellVideoInit();
	//trlEmuShellAudioInit();
	trlEmuShellInputInit();
	g_pEmuShellCore->trlEmuCoreInit(&g_sEmuShellBuffer);
	//trlEmuShellDataSaveDataInit();
	//if(g_sEmuShellBuffer.nBackupDataSize)
	//	trlEmuShellDataLoadBackup();

	//trlEmuShellAudioStart();
}

void trlEmuShellUpdate()
{
	trlEmuShellUpdateInput();
	if(g_bStepRun == 0 || g_bStepRun == 1)
	{
		if(g_bStepRun == 1)
			g_bStepRun = 2;
		g_pEmuShellCore->trlEmuCoreRunOneFrame();
	}

	// Patch
	//trlEmuShellPatch();

	// CTR Render
	trlEmuShellVideoFrame();

	// Auto Save
	//trlEmuShellDataUpdateAutoSave();

	//trlEmuShellAudioMain();
}
