/**
 * @file nesGraphic.h
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Graphic
 */
#pragma once
#include "nesGlobal.h"
#include "nesDataStruct.h"

/** @name Macro Define */
//@{
#define NES_GRP_TICKS			g_nNesPPULineCycles						///< PPU cycles per line
#define NES_GRP_MAP_AUTO		0										///< Name Table Mapping - Card Auto Control
#define NES_GRP_MAP_HORI		1										///< Name Table Mapping - Horizontal Mirroring
#define NES_GRP_MAP_VERT		2										///< Name Table Mapping - Vertical Mirroring
#define NES_GRP_MAP_SINGLE0		3										///< Name Table Mapping - Single Screen 0
#define NES_GRP_MAP_SINGLE1		4										///< Name Table Mapping - Single Screen 1
#define NES_GRP_MAP_EXTEND		5										///< Name Table Mapping - CARD Extend Control
#define NES_GRP_BG_NORMAL		0										///< BG Render Mode - Normal
#define NES_GRP_BG_LATCH		1										///< BG Render Mode - Latch
#define NES_GRP_BG_MMC5			2										///< BG Render Mode - MMC5
#define	NES_GRP_SAVEDATA_MAX	10										///< Graphic Save Data Max Count

#define	NES_GRP_TEX_OFFSET		8

//@}

/** @name Global Variable */
//@{
extern s32						g_nNesPPULineCycles;					///< PPU cycles per line
extern u32						g_nNesGrpLines;							///< Current Scanline
extern u32						g_bNesGrpSPRChange;						///< Sprite Change Flag
extern u8*						g_pNesGrpNameTab[5];					///< Name Table and Attribute Table
extern nesSGrpRegCtrl1*			g_pNesGrpReg2000;						///< PPU Control Register 1
extern nesSGrpRegCtrl2*			g_pNesGrpReg2001;						///< PPU Control Register 2
extern nesSGrpRegStatus*		g_pNesGrpReg2002;						///< PPU Status Register
extern u32						g_nNesGrpPatternTabBG;					///< Pattern Tab for BG
extern u32						g_nNesGrpBGMode;						///< BG Render Mode Flag
extern u32						g_nNesGrpNameTabMapping;				///< Name Table and Attribute Table Mapping
extern u32						g_nNesGrpEnable;						///< Video Enable
extern u32						g_bNesGrpSPRChange;						///< Sprite Change Flag
extern u32						g_nNesGrpSaveData;						///< Graphic Save Data Count
extern trlSEmuShellResume		g_sNesGrpSaveData[NES_GRP_SAVEDATA_MAX];///< Graphic Save Data

extern u16						g_nNesGrpPalTable[0x40];
extern u16						g_nNesGrpPalTable_Origin[0x40];
//@}

/** @brief Initialize Graphic */
void nesGrpInit();
/** @brief Reset Graphic */
void nesGrpReset();
/** @brief Resume Graphic */
void nesGrpResume();
/** @brief Exit Graphic */
void nesGrpExit();
/** @brief Update Ticks */
void nesGrpUpdate();
/** @brief Read Data From PPU Register */
u8 nesGrpRegRead(u8 nAddr);
/** @brief Write Data to PPU Register */
void nesGrpRegWrite(u8 nAddr, u8 nValue);
/** @brief Change the Name Table Mapping */
void nesGrpChangeNameTabMap(u32 nMapping);
/** @brief Change the BG Render */
void nesGrpChangeRenderBG(u32 nMode);
