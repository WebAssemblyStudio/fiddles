/**
 * @file nesCPU.h
 * @author chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - CPU
 */
#pragma once
#include "nesGlobal.h"

/** @name Macro Define */
//@{
#define	NES_CPU_SAVEDATA_MAX	11											///< CPU Save Data Max Count
//@}

/** @name Global Variable */
//@{
extern u16						g_nNesCpuRegPC;								///< CPU Registe PC
extern u8						g_nNesCpuRegA;								///< CPU Registe A
extern u8						g_nNesCpuRegX;								///< CPU Registe X
extern u8						g_nNesCpuRegY;								///< CPU Registe Y
extern u8						g_nNesCpuRegS;								///< CPU Registe S
extern u8						g_nNesCpuRegP;								///< CPU Registe P
extern u8						g_nNesCpuNMIFlag;							///< CPU NMI Flag
extern u8						g_nNesCpuIRQFlag;							///< CPU IRQ Flag
extern u8						g_nNesCpuRESETFlag;							///< CPU RESET Flag
extern u8*						g_pNesCpuPC;								///< CPU PC Pointer
extern u32						g_nNesCpuSaveData;							///< CPU Save Data Count
extern trlSEmuShellResume		g_sNesCpuSaveData[NES_CPU_SAVEDATA_MAX];	///< CPU Save Data
//@}

/** @brief Initialize CPU */
void nesCpuInit();
/** @brief Reset CPU */
void nesCpuReset();
/** @brief Resume CPU */
void nesCpuResume();
/** @brief Run CPU */
void nesCpuRun();
