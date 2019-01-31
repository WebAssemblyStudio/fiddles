#pragma once
#include "sounddefine.h"

//	=============================================== for Sound A/B/C/D
extern const u8 LEN_TABLE_HVC[32];
extern const s8 TRIANGLE_TABLE[32]; 

//	=============================================== for Sound D
extern const u32 NOISE_TABLE[16];
extern const u8 NOISE_PULSE_TABLE[];

//	=============================================== for Sound E 
extern const u32 DMOD_TABLE[16];
extern const u16 VOLTABLE_DELTAMOD[];

//	=============================================== for Sound F
extern const u8  VOLTABLE_DISKFM[33];
extern const u8  VOLTABLE_DISKFM_SUB[33];
extern const s8  DISK_SUB_GAIN[8];
extern const u32 DISKFM_GAINTABLE[4];


///////////////////////////
//	=============================================== for Sound A/B/C/D
const u8 LEN_TABLE_HVC[32]={
							 6, 126,  12,   1,   24,   2,  48,   3,
							96,   4,  36,   5,    8,   6,  16,   7,
							 6,   8,  12,   9,   24,  10,  48,  11,
							96,  12,  36,  13,    8,  14,  16,  15 };
//	=============================================== for Sound C
const s8 TRIANGLE_TABLE[32]={
							  0,  15,  30,  45,  60,  75,  90, 105,
							120, 105,  90,  75,  60,  45,  30,  15,
							  0,  15,  30,  45,  60,  75,  90, 105,
							120, 105,  90,  75,  60,  45,  30,  15 }; 

//	=============================================== for Sound D
// x cycle/persamplebyte
// 1789882/2
//------------*0x10000  =   y   soundE step for sample(44100)
// x*44100
//y = 1329951/X
/*const u32 NOISE_TABLE[16]={
							0xdf86a, 0x6fc35, 0x37e1a, 0x1bf0d,
							0xdf86,  0x9504,  0x6fc3,  0x5969,
							0x46d1,  0x3852,  0x25a5,  0x1c29,
							0x12c6,  0xe14,   0x708,   0x6fd };*/
#define SoundD_FREQ_COSNT  1329951
const u32 NOISE_TABLE[16] = {
									SoundD_FREQ_COSNT/0x002, SoundD_FREQ_COSNT/0x004, SoundD_FREQ_COSNT/0x008, SoundD_FREQ_COSNT/0x010,
									SoundD_FREQ_COSNT/0x020, SoundD_FREQ_COSNT/0x030, SoundD_FREQ_COSNT/0x040, SoundD_FREQ_COSNT/0x050,
									SoundD_FREQ_COSNT/0x065, SoundD_FREQ_COSNT/0x07F, SoundD_FREQ_COSNT/0x0BE, SoundD_FREQ_COSNT/0x0FE,
									SoundD_FREQ_COSNT/0x17D, SoundD_FREQ_COSNT/0x1FC, SoundD_FREQ_COSNT/0x3F9, SoundD_FREQ_COSNT/0x7F2
							  };


const u8 NOISE_PULSE_TABLE[] = {
							0x30, 0x32, 0x34, 0x38,
							0x3c, 0x3d, 0x3e, 0x3f,
							0x40, 0x42, 0x44, 0x46,
							0x48, 0x50, 0x60, 0x60 };

//	=============================================== for Sound E 
// x cycle/persamplebyte
// 1789882*8
//------------*0x10000  =   y   soundE step for sample(44100)
// x*44100
// y =  21279221.179501133786848072562358/x
//   3424>= x >= 432
//y = 21279221*x
//for more jingque,  /2 and fore sample(44100) step 2
#define SoundE_DMOD_COSNT 21279221/2
const u32 DMOD_TABLE[16]={
						 SoundE_DMOD_COSNT/0xD60, SoundE_DMOD_COSNT/0xBE0, SoundE_DMOD_COSNT/0xAA0, SoundE_DMOD_COSNT/0xA00,
						 SoundE_DMOD_COSNT/0x8F0, SoundE_DMOD_COSNT/0x7F0, SoundE_DMOD_COSNT/0x710, SoundE_DMOD_COSNT/0x6B0,
						 SoundE_DMOD_COSNT/0x5F0, SoundE_DMOD_COSNT/0x500, SoundE_DMOD_COSNT/0x470, SoundE_DMOD_COSNT/0x400,
						 SoundE_DMOD_COSNT/0x350, SoundE_DMOD_COSNT/0x2A8, SoundE_DMOD_COSNT/0x240, SoundE_DMOD_COSNT/0x1B0
						};

const u16 VOLTABLE_DELTAMOD[]=
{	
	0x0,0xff,0x1fc,0x2f7,0x3f0,0x4e7,0x5dc,0x6cf,0x7c0,0x8af,0x99c,0xa87,0xb70,0xc57,0xd3c,0xe1f,
	0xf00,0xfdf,0x10bc,0x1197,0x1270,0x1347,0x141c,0x14ef,0x15c0,0x168f,0x175c,0x1827,0x18f0,0x19b7,0x1a7c,0x1b3f,
	0x1c00,0x1cbf,0x1d7c,0x1e37,0x1ef0,0x1fa7,0x205c,0x210f,0x21c0,0x226f,0x231c,0x23c7,0x2470,0x2517,0x25bc,0x265f,
	0x2700,0x279f,0x283c,0x28d7,0x2970,0x2a07,0x2a9c,0x2b2f,0x2bc0,0x2c4f,0x2cdc,0x2d67,0x2df0,0x2e77,0x2efc,0x2f7f,
	0x3000,0x307f,0x30fc,0x3177,0x31f0,0x3267,0x32dc,0x334f,0x33c0,0x342f,0x349c,0x3507,0x3570,0x35d7,0x363c,0x369f,
	0x3700,0x375f,0x37bc,0x3817,0x3870,0x38c7,0x391c,0x396f,0x39c0,0x3a0f,0x3a5c,0x3aa7,0x3af0,0x3b37,0x3b7c,0x3bbf,
	0x3c00,0x3c3f,0x3c7c,0x3cb7,0x3cf0,0x3d27,0x3d5c,0x3d8f,0x3dc0,0x3def,0x3e1c,0x3e47,0x3e70,0x3e97,0x3ebc,0x3edf,
	0x3f00,0x3f1f,0x3f3c,0x3f57,0x3f70,0x3f87,0x3f9c,0x3faf,0x3fc0,0x3fcf,0x3fdc,0x3fe7,0x3ff0,0x3ff7,0x3ffc,0x3fff
};

//	=============================================== for Sound F

const u8  VOLTABLE_DISKFM[33]={
									 0,  1,  2,  3,  4,  6,  8, 10,
									12, 14, 16, 18, 20, 22, 24, 26,
									28, 30, 32, 34, 36, 38, 40, 42,
									44, 46, 48, 50, 52, 54, 56, 58, 60 };

const u8  VOLTABLE_DISKFM_SUB[33]={
									 0,  1,  2,  3,  4,  5,  6,  7,
									 8,  9, 10, 11, 12, 13, 14, 15,
									16, 17, 18, 19, 20, 21, 22, 23,
									24, 25, 26, 27, 28, 29, 30, 31, 32 };

const s8  DISK_SUB_GAIN[8]=   { 0, 1, 2, 4,  0, -4, -2, -1 };
const u32 DISKFM_GAINTABLE[4]= { 30, 20, 15, 12 };
