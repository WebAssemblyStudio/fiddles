#ifndef SOUNDC_H
#define	SOUNDC_H
#include "pulse.h"

#define  C_RELEASE_LEVEL     (32)
#define  C_RELEASE_LEVEL_SHIFT (5)

s8 __GetWave_Triangle(s32 counter)
{	
	return(TRIANGLE_TABLE[counter]);	
}

u32 __PitchTo32_HVC_C(u16 pitch)
{
	f32 freq;
	u32 cc;

	if (pitch < 2) 
		return(0);
	freq=HVC_CPU_CLOCK/32.0f/(f32)((s32)pitch+1);
	cc=(u32)(freq/PITCH_CONST*32768.0f);
	return(cc);
}

void __Sound_Write_C(u16 reg, u8 value)
{
	u8 old;

	(void)value;
	switch(reg)
	{
	case 8:
		old = (u8)(SoundC.lenmode);		
		if (sbuffer.sr.R_4008.length2) 
		{
			SoundC.envinterval = __SoundEnvelopeRateTo32((sbuffer.sr.R_4008.length2+1));
		}
		else
			SoundC.envinterval=0;

		if ( (SoundC.activity) && (SoundC.reinit) )
		{			
			SoundC.lenmode     = sbuffer.sr.R_4008.cont;
			SoundC.envcounter  = SoundC.envinterval;
		}
		else if (SoundC.activity)
		{			
			if ( (old ) && (sbuffer.sr.R_4008.cont==0) )
			{
				SoundC.lenmode     = sbuffer.sr.R_4008.cont;
				SoundC.envcounter  = SoundC.envinterval;
				SoundC.reinit      = 128;
			}
			else if (old)
			{				
				SoundC.envcounter  = SoundC.envinterval;
			}
		}
		else
		{
			if (SoundC.reinit)
			{	
				SoundC.lenmode     = sbuffer.sr.R_4008.cont;
				SoundC.envcounter  = SoundC.envinterval;
				if (sbuffer.sr.R_4015.soundC) SoundC.activity = 1;
			}
		}
			
		if ( (sbuffer.sr.R_4008.length2 == 0) && (SoundC.lenmode==0) )
			SoundC.activity = 0;
		break;
	case 9:
		break;
	case 0x0a:
		SoundC.pitch_org=(u16)((sbuffer.sr.R_400B.freq << 8) | (sbuffer.sr.R_400A));
		SoundC.pitch=__PitchTo32_HVC_C(SoundC.pitch_org);		
		break;
	case 0x0b:
		SoundC.pitch_org=(u16)((sbuffer.sr.R_400B.freq << 8) | (sbuffer.sr.R_400A));
		SoundC.len_org=LEN_TABLE_HVC[sbuffer.sr.R_400B.length];
		SoundC.lencounter=SoundC.len_org*OUTPUT_RATE_PER_FRAME;	
	  
		if  ( (SoundC.activity==0) || (SoundC.envcounter==0) )
		{
			SoundC.fcounter.fc32=0;
			SoundC.oldc=0;	
			SoundC.volume  = (u8)(16+((0x7f - bias) >> 3));
		}
		SoundC.pitch=__PitchTo32_HVC_C(SoundC.pitch_org);
		SoundC.reinit=60;
		SoundC.lenmode     = sbuffer.sr.R_4008.cont;
		SoundC.envcounter  = SoundC.envinterval;

		if ( (sbuffer.sr.R_4015.soundC) && (sbuffer.sr.R_4008.length2) )
			SoundC.activity=1;
		else
			SoundC.activity= 0;
		break;
	}
}

s16 __ProcessSoundC(void)
{
	s16 sample;
	u16 pitch = (u16)(SoundC.pitch);

	if ( (SoundC.activity==0) || (SoundC.envcounter==0) )
	{
		if (SoundC.lastlevel > 0)
			SoundC.lastlevel--;
		if (SoundC.lastlevel==0)  
		{
		}
	}
	else
	{
		if (SoundC.lastlevel < C_RELEASE_LEVEL)
			SoundC.lastlevel++;
	}

	sample = (s16)(s8)__GetWave_Triangle(SoundC.fcounter.fc.high);

	SoundC.volume  = (u8)(16+((0x7f - bias) >> 3));

	sample=(s16)(sample*SoundC.volume);	

	SoundC.fcounter.fc32+=SoundC.pitch;
	SoundC.fcounter.fc32 &= 0x001fffff;	
	SoundC.lastpitch=pitch;

	if (SoundC.lenmode==0)
	{
		if(SoundC.lencounter)
			SoundC.lencounter--;
		if(SoundC.lencounter==0)
			SoundC.activity=0;

		if(SoundC.envcounter > 0)
			SoundC.envcounter-= SOUND_INT_ONE;
	}
	if (SoundC.reinit) SoundC.reinit--;
	sample = (s16)((sample * SoundC.lastlevel) >> C_RELEASE_LEVEL_SHIFT);
	sample = (s16)(sample * g_bNesSndC);
	return (sample);
}
#endif
