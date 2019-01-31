/**
 * @file nesMemory.h
 * @author Chentian
 * @date 2010.06.24
 * @brief NES Emulate For CTR - Memory Map
 */
#pragma once
#include "nesGlobal.h"

/** @name Macro Define */
//@{
#define NES_MEM_SAVEDATA_MAX	6											///< Memory Save Data Max Count
//@}

/** @name Global Variable */
//@{
extern u8*						g_pNesCurVRAM;								///< Current Video RAM Bank
extern u8*						g_pNesCurWRAM;								///< Current Work RAM Bank
extern u32						g_nNesMemSaveData;							///< Memory Save Data Count
extern trlSEmuShellResume		g_sNesMemSaveData[NES_MEM_SAVEDATA_MAX];	///< Memory Save Data
//@}

/** @brief Initialize Memory */
void nesMemInit();
/** @brief Reset Memory */
void nesMemReset();
/** @brief Resume Memory */
void nesMemResume();
/** @brief Exit Memory */
void nesMemExit();

/** @brief Read Data From Memory Map - 8 Bits */
u8 nesMemRead8(u16 nAddr);
/** @brief Read Data From Memory Map - 16 Bits */
u16 nesMemRead16(u16 nAddr);
/** @brief Write Data to Memory Map - 8 Bits */
void nesMemWrite8(u16 nAddr, u8 nValue);
/** @brief Direct Write Data to PPU Memory Map - 8 Bits */
void nesPpuMemDirectWrite8(u16 nAddr, u8 nValue);

