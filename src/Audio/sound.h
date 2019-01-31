#pragma once
#include "sounddefine.h"
#include "soundtype.h"

extern u32 DISK_FRAME_SAMPLE;
extern u32 FRAME_SAMPLE;
extern u32 PHASE_SAMPLE;

extern u32 DEFAULT_SPEED;
extern f32 HVC_CPU_CLOCK ;
extern u32 FRAME_DIVIDER;

///////////////////////////////////////////////////////////////////////////////////////
extern Sound_HVCpulse_    SoundA, SoundB, SoundC, SoundD;
extern Sound_HVCdeltamod_ SoundE;
extern Sound_HVCpulse_    SoundX, SoundY, SoundZ;  /* for VRC6(X,Y,Z) & MMC5(X,Y) */
extern Sound_HVCdiskfm_   SoundF;				   /* for DISKSYSTEM */
extern Sound_Pcm_		  SoundP;				   /* for JALECO     */
extern Sound_FME7_		  SoundQ;				   /* for Gimmick! */

extern Sound_buffer_ sbuffer;

extern u32 delta_counter;
extern s32 delta_sign;

extern s32 bias_move;
extern s32 bias;

extern f32 voltage;
extern f32 voltage_out;

extern u32 NOISE_SHIFT_COUNTER;

extern u8 DISKFM_TABLE[64];
extern u8 DISKSUB_TABLE[32];
extern s16 disksubwave[64];
extern s32 __sound_write_disk_shiftr;

extern u8  NOISE_PULSE;

extern u8  NOISE_OUTPUT;

extern Pcmh_  *PCMH;
extern Pcmh2_ PCMH2;
