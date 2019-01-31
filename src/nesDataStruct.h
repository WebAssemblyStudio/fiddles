/**
 * @file nesDataStruct.h
 * @author Chentian
 * @date 2010.06.25
 * @brief NES Emulate For CTR - Data Structs
 */
#pragma once
#include "nesGlobal.h"

/** @name Macro Define */
//@{
//@}

/** @name Global Variable */
//@{
//@}

/**
 * @struct nesSGrpRegCtrl1
 * @brief PPU REG: 2000 - PPU Control Register 1 (W)
 */
typedef struct
{
	u8				rNameTabH		:1;		///< Bit 0:		Name Table Scroll Address         (Horizontal Scroll by 256)
	u8				rNameTabV		:1;		///< Bit 1:		Name Table Scroll Address         (Vertical Scroll by 240)
	u8				rVRAMAddrInc	:1;		///< Bit 2:		Port 2007h VRAM Address Increment (0=Increment by 1, 1=Increment by 32)
	u8				rPatternTabSPR	:1;		///< Bit 3:		Pattern Table Address 8x8 Sprites (0=VRAM 0000h, 1=VRAM 1000h)
	u8				rPatternTabBG	:1;		///< Bit 4:		Pattern Table Address Background  (0=VRAM 0000h, 1=VRAM 1000h)
	u8				rSPRSize		:1;		///< Bit 5:		Sprite Size                       (0=8x8, 1=8x16)
	u8				rPPUMode		:1;		///< Bit 6:		PPU Master/Slave Selection        (0=Master, 1=Slave) (Not used in NES)
	u8				rNMI			:1;		///< Bit 7:		Execute NMI on VBlank             (0=Disabled, 1=Enabled)
}nesSGrpRegCtrl1;

/**
 * @struct nesSGrpPPURegCtrl2
 * @brief PPU REG: 2001 - PPU Control Register 2 (W)
 */
typedef struct
{
	u8				rColorMode		:1;		///< Bit 0:		Monochrome Mode                   (0=Color, 1=Monochrome)
	u8				rBGClip			:1;		///< Bit 1:		Background Clipping               (0=Hide in left 8-pixel column, 1=No clipping)
	u8				rSPRClip		:1;		///< Bit 2:		Sprite Clipping                   (0=Hide in left 8-pixel column, 1=No clipping)
	u8				rBGEnable		:1;		///< Bit 3:		Background Visibility             (0=Not displayed, 1=Displayed)
	u8				rSPREnable		:1;		///< Bit 4:		Sprite Visibility                 (0=Not displayed, 1=Displayed)
	u8				rBGColor		:3;		///< Bit 5-7:	Color Emphasis		              (0=Normal, 1-7=Emphasis)
}nesSGrpRegCtrl2;

/**
 * @struct nesSGrpRegStatus
 * @brief PPU REG: 2002 - PPU Status Register (R)
 */
typedef struct
{
	u8				rUnused			:4;		///< Bit 0-3:	Not used                          (Undefined garbage)
	u8				rVRAMWrite		:1;		///< Bit 4:		VRAM Write Flag                   (0=Writes to VRAM are respected, 1=Writes to VRAM are ignored)
	u8				rSPRLost		:1;		///< Bit 5:		Lost Sprites                      (1=More than 8 sprites in 1 scanline)
	u8				rSPRHit			:1;		///< Bit 6:		Sprite 0 Hit                      (1=Background-to-Sprite0 collision)
	u8				rVBlank			:1;		///< Bit 7:		VBlank Flag                       (1=VBlank)
}nesSGrpRegStatus;

/**
 * @struct nesSGrpSprAttr
 * @brief Sprite Attributes
 */
typedef struct
{
	u8				nY;						///< Y Coordinate Minus 1                         (FFh,00h..EEh=Scanline 0..239, EFh..FEh=Not displayed)
	u8				nTile;					///< Tile Number
	u8				rPal			:2;		///< Bit 0-1:	Sprite Palette                    (0-3=Sprite Palette 0-3)
	u8				rUnused			:3;		///< Bit 2-4:	Not used                          (Always zero when reading from SPR-RAM)
	u8				rPrio			:1;		///< Bit 5:		Background Priority               (0=Sprite In front of BG, 1=Sprite Behind BG)
	u8				rHFlip			:1;		///< Bit 6:		Vertical Flip                     (0=Normal, 1=Mirror)
	u8				rVFlip			:1;		///< Bit 7:		Horizontal Flip                   (0=Normal, 1=Mirror)
	u8				nX;						///< X Coordinate                                 (00h..FFh)
}nesSGrpSprAttr;

/**
 * @struct nesSGrpSprData
 * @brief Sprite Data
 */
typedef struct
{
	u32				nID;			///< Index
	u32				nX;				///< X Coordinate
	u32				nY;				///< Y Coordinate
	u32				nTile;			///< Tile Number
	u32				nPal;			///< Sprite Palette
	u32				nPrio;			///< Background Priority
	u32				nHFlip;			///< Vertical Flip
	u32				nVFlip;			///< Horizontal Flip
	u16				nBitData[16];	///< Bit Data
}nesSGrpSprData;
