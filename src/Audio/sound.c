#include "sound.h"

////////////////////////////////////////
//const
////////////////////////////////////////
u32 DISK_FRAME_SAMPLE = (OUTPUT_RATE/60);
u32 FRAME_SAMPLE 	=  (OUTPUT_RATE/60);
u32 PHASE_SAMPLE 	=  (OUTPUT_RATE/240);

f32 HVC_CPU_CLOCK    = (f32)(CPUCLOCK_NTSC);
u32 FRAME_DIVIDER    = 60;


////////////////////////////////////////

Sound_HVCpulse_    SoundA, SoundB, SoundC, SoundD;
Sound_HVCdeltamod_ SoundE;
Sound_HVCpulse_    SoundX, SoundY, SoundZ;  /* for VRC6(X,Y,Z) & MMC5(X,Y) */
Sound_HVCdiskfm_   SoundF;				   /* for DISKSYSTEM */
Sound_Pcm_		   SoundP;				   /* for JALECO     */
Sound_FME7_		   SoundQ;					/* for Gimmick! */

Sound_buffer_ sbuffer={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

u32 delta_counter;
s32 delta_sign;
s32 bias_move;
s32 bias;
f32 voltage;
f32 voltage_out;

u8  NOISE_PULSE         = 0x60;
u32 NOISE_SHIFT_COUNTER = 0x00010000;
u8  NOISE_OUTPUT        = 0;

Pcmh_  *PCMH;
Pcmh2_ PCMH2;

u8 DISKFM_TABLE[64];
u8 DISKSUB_TABLE[32];
s16 disksubwave[64];
s32 __sound_write_disk_shiftr=0;
