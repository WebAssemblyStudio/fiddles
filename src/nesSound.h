/**
 * @file nesSound.h
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Sound
 */
#ifndef NESSOUND_H
#define	NESSOUND_H

#include "nesGlobal.h"
#include "Audio/sound.h"

/** @name Macro Define */
//@{
#define	NES_SND_SAVEDATA_MAX	20										///< Sound Save Data Max Count
#define	NES_SND_COUNT			8										///< Sound Count
#define	NES_SND_TICKS			300										///< Sound Interval Ticks	//NES_SND_COUNT*(1789772/32728)
//@}

/** @name Global Variable */
//@{
extern u32						g_nNesSndSaveData;							///< Sound Save Data Count
extern trlSEmuShellResume		g_sNesSndSaveData[NES_SND_SAVEDATA_MAX];	///< Sound Save Data
extern u8						(*nesSndRegReadCard)(u16 nAddr);			///< Read Data From Card Register
extern void						(*nesSndRegWriteCard)(u16 nAddr, u8 nValue);///< Write Data to Card Register

extern f32 g_fNesSndScaleA;
extern f32 g_fNesSndScaleB;
extern f32 g_fNesSndScaleC;
extern f32 g_fNesSndScaleD;
extern f32 g_fNesSndScaleE;
extern f32 g_fNesSndScaleF;
extern f32 g_fNesSndScale5A;
extern f32 g_fNesSndScale5B;
extern f32 g_fNesSndScaleZ;

extern u32 g_bNesSndA;
extern u32 g_bNesSndB;
extern u32 g_bNesSndC;
extern u32 g_bNesSndD;
extern u32 g_bNesSndE;
extern u32 g_bNesSndF;
extern u32 g_bNesSnd5A;
extern u32 g_bNesSnd5B;
extern u32 g_bNesSndZ;
//@}

/** @brief Initialize Sound */
void nesSndInit();
/** @brief Reset Sound */
void nesSndReset();
/** @brief Resume Sound */
void nesSndResume();
/** @brief Update Ticks */
void nesSndUpdate();
/** @brief Write Data to APU Register */
void nesSndRegWrite(u16 nAddr, u8 nValue);

#define TRL_SOUND_REG_LOG_MAX 512
extern u16 g_pNesSndRegWriteLog_Addr[];
extern u8  g_pNesSndRegWriteLog_Value[];
extern u32 g_pNesSndRegWriteLog_Ticks[];
extern u8  g_pNesSndRegWriteLog_Type[];
extern u32 g_pNesSndRegWriteLog_Ct;
extern u32 g_pNesSndRegWriteLog_Run;
extern u32 g_nNesSndRegWriteLog_Ticks;

extern u32 nRegWriteLog_ticks;
extern u32 nRegWriteLog_tickspersample;
extern u32 nRegWriteLog_ct;

void nesSndRegWriteLog_LogRunOneSample();

void nesSndRegWriteLog_LogRun();
void nesSndRegWriteLog_LogBegin();
void nesSndRegWriteLog_LogTicksAdd(u32);

#endif
