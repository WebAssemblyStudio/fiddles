/**
 * @file nesGlobal.h
 * @author Chentian
 * @date 2010.06.24
 * @brief NES Emulate For CTR - Global data
 */
#ifndef	NESGLOBAL_H
#define	NESGLOBAL_H
//#include "..\EmuShell\trlEmuShellStruct.h"
typedef unsigned long  u32;
typedef signed long    s32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;
typedef signed char    s8;
typedef float          f32;
typedef int            Bool;
#define false 0
#define true 1
/////////////////////////////////////////////////////////////////////////////
#define	YOS_ROMDATA		0x000000
#define	YOS_PRGROM		(YOS_ROMDATA+0x100010)
#define	YOS_CHRROM		(YOS_PRGROM+0x08000)
#define	YOS_TEXBUF0		(YOS_CHRROM+0x20000)
#define	YOS_TEXBUF1		(YOS_TEXBUF0+0x20000)
#define	YOS_WAVEBUF		(YOS_TEXBUF1+0x20000)
#define	YOS_NESWRAM		(YOS_WAVEBUF+0x08030)
#define	YOS_NESVRAM		(YOS_NESWRAM+0x00800)
#define	YOS_NESSPRRAM	(YOS_NESVRAM+0x00800)
#define	YOS_NESPALRAM	(YOS_NESSPRRAM+0x00100)
#define	YOS_NESGRPLINE	(YOS_NESPALRAM+0x00020)
#define	YOS_NESGRPPAL	(YOS_NESGRPLINE+0x00110)
#define	YOS_NESGRPFLIP	(YOS_NESGRPPAL+0x00040)
#define	YOS_NESCARD		(YOS_NESGRPFLIP+0x00100)
#define	YOS_SRAM		(YOS_NESCARD+0x08000)
#define	YOS_RESUMESAVE	(YOS_SRAM+0x010000)
#define	YOS_HEAPEND		(YOS_RESUMESAVE+0x0070)

#define	TRL_EMUCORE_TEX_X	256
#define	TRL_EMUCORE_TEX_Y	256

#define TRL_EMUCORE_PATCH_PALMAX		16							///< Patch Palette Max Count
#define TRL_EMUCORE_PATCH_ACTIVEMAX		8							///< Patch Active Max Count
#define TRL_EMUCORE_PATCH_DATAMAX		28							///< Patch Data Max Count
/**
 * @struct trlSEmuShellResume
 * @brief Emulate Shell Resume Data Struct
 */
typedef struct
{
	void*						pValue;								///< Value
	u32							nSize;								///< Value Size
	u32							nVer;								///< Create Version
	u32							nDelVer;							///< Delete Version
}trlSEmuShellResume;
extern void trlSEmuShellResumeSetData(trlSEmuShellResume *,void*,u32,u32,u32);

/**
 * @struct trlSEmuShellVideoMask
 * @brief Emulate Shell Video Mask Data
 */
typedef struct
{
	u32							nMode;								///< Mode
	u32							bDarkEnable[2];						///< Dark Enable
	u32							bReduceEnable[2];					///< Reduce Color Enable
	u32							bMotionBEnable[2];					///< MotionBlur Enable
	u32							nDark[2];							///< Dark Value
	u32							nReduceColorR[2];					///< Reduce Red Color
	u32							nReduceColorG[2];					///< Reduce Green Color
	u32							nReduceColorB[2];					///< Reduce Blue Color
	u32							nMotionBlur[2];						///< MotionBlur Value

	u32*						pDarkEnable;						///< Dark Enable Current Pointer
	u32*						pReduceEnable;						///< Reduce Color Enable Current Pointer
	u32*						pMotionBEnable;						///< MotionBlur Enable Current Pointer
	u32*						pDark;								///< Dark Value Current Pointer
	u32*						pReduceColorR;						///< Reduce Red Color Current Pointer
	u32*						pReduceColorG;						///< Reduce Green Color Current Pointer
	u32*						pReduceColorB;						///< Reduce Blue Color Current Pointer
	u32*						pMotionBlur;						///< MotionBlur Value Current Pointer
}trlSEmuShellVideoMask;

/**
 * @struct trlSEmuShellPatchData
 * @brief Emulate Shell Patch Data
 */
typedef union
{
	struct
	{
		u32							nMode;								///< Mode
		u32							nType;								///< Type
		u32							nIndex;								///< Index
		u32							nAddress;							///< ROM Address
		u32							nMemAddress;						///< RAM Address
		u32							nFixcode;							///< Patch Code
		u32							nDelayFrame;						///< Delay Frame
		u32							nFadeFrame;							///< Fade Frame
		u32							bDarkEnable[2];						///< Dark Enable
		u32							bReduceEnable[2];					///< Reduce Color Enable
		u32							bMotionBEnable[2];					///< MotionBlur Enable
		u32							nDark[2];							///< Dark Value
		u32							nReduceColorR[2];					///< Reduce Red Color
		u32							nReduceColorG[2];					///< Reduce Green Color
		u32							nReduceColorB[2];					///< Reduce Blue Color
		u32							nMotionBlur[2];						///< MotionBlur Value
		u32							nConditionType;
		u32							nConditionValueA;
		u32							nConditionValueB;
		u32							nConditionValueC;
	}sA;
	u32 nD[TRL_EMUCORE_PATCH_DATAMAX];			///< Data
}trlSEmuShellPatchData;

/**
 * @struct trlSEmuShellPatch
 * @brief Emulate Shell Patch Data
 */
typedef struct
{
	u32							nOpcode;							///< Opcode
	trlSEmuShellPatchData		sData;								///< Data
	u32							nValue;								///< Value
	u8*							pFixcode;							///< Patch Code Array
	u8*							pConditionValueA;
	u8*							pConditionValueB;
	u8*							pConditionValueC;
	u32							nPalette[TRL_EMUCORE_PATCH_PALMAX];	///< Palette
}trlSEmuShellPatch;

/**
 * @class trlSEmuShellPatchActive
 * @brief Emulate Shell Active Patch Data
 */
typedef struct
{
	/** @brief Clear Data */
	//void Clear() { nIndex = nDelay = nMode = nFade = nValue = 0; }

	u16							nIndex;								///< Index
	u16							nDelay;								///< Current Delay Frame
	u16							nMode;								///< Mode
	u16							nFade;								///< Current Fade Frame
	u32							nValue;								///< Value
}trlSEmuShellPatchActive;
extern void trlSEmuShellPatchActiveClear(trlSEmuShellPatchActive *);

typedef struct
{
	u32							nRomType;											///< Cartridge Type
	u32							nRomSubType;										///< Cartridge Sub Type
	u32							nBackupType;										///< Backup Type
	s32							nWidth;												///< Screen Width
	s32							nHeight;											///< Screen Height
	s32							nTexWidth;											///< Texture Width
	s32							nTexHeight;											///< Texture Height
	u32							nRomBufSize;										///< Cartridge Buffer Size
	void*						pRomBuf;											///< Cartridge Buffer Data
	u32							nSoundBufSize;										///< Sound Buffer Size
	void*						pSoundBuf;											///< Sound Buffer Data
	void*						pTextureBuf[2];										///< Texture Buffer Data
	void*						pScreenBuf;											///< Screen Buffer Data
	u32							nTexID;												///< Current Texture Buffer ID
	u32							nScreenBufOffset;									///< Screen Buffer Data Offset
	u32							nBackupDataSize;									///< Backup Buffer Size
	void*						pBackupData;										///< Backup Buffer Data
	u32							nKeyMask;											///< Input Key Mask
	u32							bInitFlag;											///< Init Flag
	u32							bError;												///< Error Flag

	u32							nSaveDataSize;										///< Save Data Size
	trlSEmuShellResume*			pSaveData;											///< Save Data
	s32							nSaveFlag;											///< Save Flag
	u32							nSaveFileSize;										///< Save File Size
	u32							nSaveTime;											///< Save Time Interval
	u32							nSaveUpdate;										///< Save Update Flag

//	u32							nDebugKey;											///< Debug Key Data
	u32							nVSyncEnable;										///< VSync Enable Flag

	u32							nSwitchDisk;										///< NES Switch Disk

	u32							nPatchMask;											///< Patch Mask Index
	u32							nPatchPalette;										///< Patch Palette Index
	u32							nPatchCount;										///< Patch Count
	trlSEmuShellPatch*			pPatchData;											///< Patch Data
	u32							nPatchActive;										///< Patch Active Count
	trlSEmuShellPatchActive		sPatchActive[TRL_EMUCORE_PATCH_ACTIVEMAX];			///< Patch Active Data

	u32							nFrames;											///< Frame Count
	u32							bFrameDelayEnable;									///< Frame Delay Enable Flag
	u32							nFrameMark;											///< Frame Mark
	s32							nFrameDelay;										///< Frame Delay Count
	u32							nFrameDouble;										///< Frame Double Mode Flag

	s32							nAudioSampleCurFrame;								///< Audio Sample Current Frame
	s32							nAudioSampleSkip;									///< Audio Sample Skip Frame
	u32							nAudioSampleOffset;									///< Audio Sample Offset Frame

//	u32							nVCMMode;											///< VCM Mode
//	u32							nVCMState;											///< VCM State: 0-Close, 1-Open, 2-Closing

	s32							(*funcSaveBackup)();								///< TRL Save Backup Func Pointer
	s32							(*funcSoundPlaySize)();								///< TRL Get Sound Play Size Func Pointer
	void						(*funcChangeMaskMode)(u32);							///< TRL Change Mask Mode Func Pointer
//	void						(*funcChangeFilterMode)(u32);						///< TRL Change Mono Filter Func Pointer
//	u32							(*funcConfigData)(const char*, const char*, u32);	///< TRL Get Config Data Func Pointer
	void						(*funcAudioRecord)(u8*, u32);						///< TRL Audio Record Func Pointer
	void*						pWaveBuf;											///< Wave Buffer Data (for PC)
	u32							nMotion2Frames;
}trlSEmuShellBuffer;

/**
 * @struct trlSEmuShellCore
 * @brief EmuCore Function Struct
 */
typedef struct
{
	void (*trlEmuCoreInit)(trlSEmuShellBuffer*);
	void (*trlEmuCoreRunOneFrame)();
	void (*trlEmuCoreReset)();
	void (*trlEmuCoreInput)(u32);
	void (*trlEmuCoreResume)();
	void (*trlEmuCoreExit)();
	void (*trlEmuCorePatch)(trlSEmuShellPatch*);
	u16 (*trlEmuCoreGetPalette)(u32);
	void (*trlEmuCoreSetPalette)(u32, u16, u32);
	u32 (*trlEmuCoreSwap)(s32);
	void (*trlEmuCoreSave)(u32);
}trlSEmuShellCore;

extern trlSEmuShellCore g_sEmuCoreNES;
extern u8 g_pYosHeap[];
extern void trlMemCopy(void *,void *,unsigned long);
extern void trlMemSet(void *,unsigned long,unsigned long);
extern void trlMemFree(void *);
extern void trlEmuShellInit(void);
extern void trlEmuShellUpdate(void);

#define	NULL ((void *)0)
/////////////////////////////////////////////////////////////////////////////
/** @name Macro Define */
//@{
//@}

/**
 * @class nesSROMHeader
 * @brief The Cartridge Header
 */
typedef struct
{
	u32		nFlag;						///< Flag "TNES"
	u8		nMapper;					///< Mapper Number
	u8		nPRGBanks;					///< Number of 8K PRG-ROM Banks
	u8		nCHRBanks;					///< Number of 8K CHR-ROM Banks
	u8		nSRAMBanks;					///< Number of 8K SRAM Banks
	u8		nNameTabMapping;			///< Name Table Mapping Type
	u8		nBattery;					///< Support Battery
	u8		nSideNumber;				///< Number of Sides
	u8		nCRC;						///< CRC Enable Flag
	u32		nPadding;
}nesSROMHeader;

/** @name Global Variable */
//@{
extern u8*					g_pNesPRGROM;		///< PRG Cartridge
extern u8*					g_pNesCHRROM;		///< CHR Cartridge
extern u8*					g_pNesWRAM;			///< Work RAM
extern u8*					g_pNesVRAM;			///< Video RAM
extern u8*					g_pNesSPRRAM;		///< Sprite Attribute Table
extern u8*					g_pNesPALRAM;		///< Palette RAM
extern u8*					g_pNesSRAM;			///< SRAM
extern u8*					g_pNesPRGBank[4];	///< PRG Banks
extern u8*					g_pNesCHRBank[12];	///< CHR Banks
extern u8*					g_pNesSRAMBank;		///< SRAM Bank

extern u8					g_nPPUCHRRAM;			///< PPU CHR RAM write enable flag

extern nesSROMHeader*		g_pNesROMHeader;	///< The Cartridge Header Data
extern trlSEmuShellBuffer*	g_pNesEmuBuf;		///< Emulate Shell Buffer
extern u32					g_nNesBreakFlag;	///< Break Flag

extern s32					g_nNesCpuEventTicks;///< Next Event Ticks
extern s32					g_nNesCpuTicks;		///< CPU Run Ticks
extern s32					g_nNesGrpTicks;		///< PPU Ticks
extern s32					g_nNesSndTicks;		///< APU Ticks
//@}

#endif
