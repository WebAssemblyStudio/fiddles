/**
 * @file nesCard.h
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Cartridge
 */
#ifndef NESCARD_H
#define	NESCARD_H

#include "nesGlobal.h"

/** @name Macro Define */
//@{
#define NES_CARD_IRQ_CPUCYCLE	0x01										///< IRQ: Clock Cycle 
#define NES_CARD_IRQ_SCANLINE	0x02										///< IRQ: Scan Line
#define NES_CARD_IRQ_SCANLINEV	0x03										///< IRQ: Scan Line include V-Blank
#define	NES_CARD_SAVEDATA_MAX	8											///< Card Save Data Max Count
//@}

/** @name Global Variable */
//@{
extern void						(*nesCardRegister)(u16, u8);				///< Game Card RAM Register Function Pointer
extern void						(*nesCardRegisterWrite)(u16, u8);			///< Game Card RAM Register Expansion Write Function Pointer
extern u8						(*nesCardRegisterRead)(u16);				///< Game Card RAM Register Expansion Read Function Pointer
extern void						(*nesCardRegisterLatch)(u32);				///< Game Card RAM Register Latch Function Pointer
extern void						(*nesCardUpdateIRQ)();						///< Game Card RAM Update IRQ Function Pointer
extern s32						g_nNesCardIRQTicks;							///< IRQ Ticks
extern u32						g_nNesCardIRQEnable;						///< IRQ Enable Flag
extern s32						g_nNesCardIRQDiskTicks;						///< IRQ Ticks for Disk
extern u32						g_nNesCardIRQDiskEnable;					///< IRQ Enable Flag for Disk
extern u32						g_nNesCardSRAMEnable;						///< SRAM Enable
extern u32						g_nNesCardLatch[2];							///< Latch Value
extern u32						g_nNesCardPRGBankMask;						///< PRG-ROM Bank Mask
extern u32						g_nNesCardCHRBankMask;						///< CHR-ROM Bank Mask
extern u32						g_nNesCardSaveData;							///< Card Save Data Count
extern trlSEmuShellResume		g_sNesCardSaveData[NES_CARD_SAVEDATA_MAX];	///< Card Save Data
//@}

/** @brief Initialize Card */
void nesCardInit();
/** @brief Reset Card */
void nesCardReset();
/** @brief Resume Card */
void nesCardResume();
/** @brief Exit Card */
void nesCardExit();
/** @brief Disk System Read File */
void nesCardDiskSystemRead();
/** @brief Disk System Write File */
void nesCardDiskSystemWrite();

#endif
