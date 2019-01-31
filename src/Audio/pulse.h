#ifndef PULSE_H
#define	PULSE_H
#include "sounddefine.h"
#include "soundtype.h"
#include "table.h"

#define PULSE_BIAS (-0.064103)

extern const f32 VOLTABLE_HVCPULSE[16+1];
extern const u8 VOLTABLE_VRCPULSE[32];

const f32 VOLTABLE_HVCPULSE[16+1]= {
	0.000000f,
	0.080128f,0.157051f,0.224359f,0.294872f,
	0.365385f,0.435897f,0.506410f,0.592949f,
	0.657051f,0.730769f,0.801282f,0.865385f,
	0.929487f,0.993590f,1.064103f,1.064103f
};

const u8 VOLTABLE_VRCPULSE[32]=
{
	 0,  2,  4,  6,  8, 10, 12, 14,
	16, 18, 20, 22, 24, 26, 28, 30,
	32, 33, 34, 35, 36, 37, 38, 39,
	40, 41, 42, 43, 44, 45, 46, 47,
};

#define SND_HI 1
#define SND_LO 0
s8 g_pWavePulse[13][32] =
{
	//DUTY_0
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO
	},
	//DUTY_1
	{
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO
	},
	//DUTY_2
	{
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO
	},
	//DUTY_3
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_00
	{
		SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_01
	{
		SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_02
	{
		SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_03
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_04
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_05
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_06
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_07
	{
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO, SND_LO,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
	//VRC6 DUTY_08
	{
		SND_LO, SND_LO, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI,
		SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI, SND_HI
	},
};

s32 __GetSamplesPerPitch(u32 pitch)
{
	if(pitch==0)
		return 0;
	return (s32)(32 * 65536/pitch);
}

s8 __GetWave_Pulse(s32 type,s32 counter)
{
	return g_pWavePulse[type][counter];
}

u32 __GetWave_Pulse2(s32 type,u32 *counter,u32 pitch)
{
	u8 total = 0;
	//zhfang
	//the temp....if didn't use the temp, and use the below format
	//...have some strange wrong, maybe is compiler bad...
	u32 temp = *counter;
	u32 i;
	for(i = 0 ; i < 16 ;i++)
	{
		temp += pitch;
		total += g_pWavePulse[type][((temp >> 20) & 0x0000001F)];
	}
	*counter = temp;
	return 4095* total/16;
}

u32 __PitchTo32_VRC_C(u16 pitch)
{
	f32 freq=HVC_CPU_CLOCK/2.0f/(f32)((s32)pitch+1);
	u32 cc=(u32)(freq/PITCH_CONST*32768.0f);
	return(cc);
}

u32 __PitchTo32_VRC_PULSE(u16 pitch)
{
	f32 freq=HVC_CPU_CLOCK/16.0f/(f32)((s32)pitch+1);
	u32 cc=(u32)(freq/PITCH_CONST*32768.0f);
	return(cc);
}

u32 __PitchTo32_HVC(u16 pitch)
{
	f32 freq=HVC_CPU_CLOCK/8.0f/(f32)((s32)pitch+1);
	u32 cc=(u32)(freq/PITCH_CONST*32768.0f);
	return(cc);
}

u32 __SoundSweepRateTo32(u16 rate)
{
	return SOUND_INT_ONE*(OUTPUT_RATE*rate/SOUND_SWEEP_FREQ);
}

u32 __SoundEnvelopeRateTo32(u16 rate)
{
	return SOUND_INT_ONE*(OUTPUT_RATE*rate/SOUND_ENVELOPE_FREQ);
}

#endif
