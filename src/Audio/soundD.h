#ifndef SOUNDD_H
#define	SOUNDD_H
#include "pulse.h"

s8 calcNoise(u32 pitch,u8 feedbit,u8 feedbit2,u32 loopbit)
{
	u32 i;
	u32 loops = pitch >> 16;
	u32 avg = 0;

	for (i=0; i < loops ; i++)
	{
		u8 out    = 1;
		u8 bit11  = ( u8 )( NOISE_SHIFT_COUNTER & feedbit );
		u8 bit13  = ( u8 )( NOISE_SHIFT_COUNTER & feedbit2 );

		// XOR
 		if (     bit11 && bit13     ) 	 out = 0;
		else
 		if ((bit11==0) && (bit13==0)) 	 out = 0;
		NOISE_OUTPUT = bit13;

		if (out) NOISE_SHIFT_COUNTER |= loopbit;
		NOISE_SHIFT_COUNTER >>= 1;
		if (NOISE_OUTPUT) avg++;
	}

	if (loops > 1)
	{
		s8 level = (s8)((f32)avg/(f32)loops * (f32)NOISE_PULSE);
  	    return level;
	}
	else
	{
		if (NOISE_OUTPUT)
			return (s8)( NOISE_PULSE);
		else
			return 0;
	}
}

s8 calcWhiteNoise(u32 pitch)
{
	return calcNoise(pitch, 0x08,0x1,0x20000);		// 130kbit
}

s8 calcPinkNoise(u32 pitch)
{
	return calcNoise(pitch, 0x40,0x01,0x8000);		// 95bit
}

u16 NoiseShift = 0x1;

s8 getNosieWaveNew(u32 pitch)
{
	int i;
	s32 step = (pitch>>16);
	int ct = 0;
	if (sbuffer.sr.R_400E.type==0)//white
	{
		for(i=0;i<step;i++)
		{
			//NoiseShift = WhiteNoiseNext[NoiseShift];
			switch(NoiseShift&0x6000)
			{
			case 0x0:
			case 0x6000:
				NoiseShift<<=1;
				break;
			default:
				NoiseShift<<=1;
				NoiseShift|=1;
			}
			ct += (NoiseShift>>14)&0x1;
		}
	}
	else //pink
	{
		for(i=0;i<step;i++)
		{
			//NoiseShift = PinkNoiseNext[NoiseShift];
			switch(NoiseShift&0x4100)
			{
			case 0x0:
			case 0x4100:
				NoiseShift<<=1;
				break;
			default:
				NoiseShift<<=1;
				NoiseShift|=1;
			}
			ct += (NoiseShift>>14)&0x1;
		}
	}
	if(step != 0)
	{
		return (s8)(0x60*(step -ct)/step);
	}
	else
	{
		if((NoiseShift & (1<<14)) != 0)
			return 0;
		else
			return 0x60;
	}
}

void initNoise()
{
	//initNoiseTable();
	//initNoiseTableNew();
	NoiseShift = 1;
	NOISE_SHIFT_COUNTER = 0x00010000;
	NOISE_OUTPUT        = 0;
}

void resetNoise()
{
	//g_nWhiteNoiseCt = 0;
	//g_nPinkNoiseCt = 0;
	NoiseShift = 1;
}

#define SOUNDD_LEVEL (16)

u32 __PitchTo32_HVC_D(u16 pitch)
{
    return NOISE_TABLE[pitch];
}

void __Sound_Write_D(u16 reg, u8 value)
{
	u8 old;

	(void)value;
	switch(reg)
	{
	case 0x0c:
		old=SoundD.envactivity;
		SoundD.envactivity=(u8)((sbuffer.sr.R_400C.envflag) ^1);
		SoundD.lenmode=(sbuffer.sr.R_400C.cont);
		SoundD.volume_org=(u8)(VOLTABLE_HVCPULSE[sbuffer.sr.R_400C.envgain]*SOUNDD_LEVEL);

		if (SoundD.envactivity==0)
		{
			SoundD.volume=SoundD.volume_org;
		}
		else
		{
			SoundD.envinterval=(u32)(sbuffer.sr.R_400C.envgain+1);
			SoundD.envinterval = __SoundEnvelopeRateTo32((u16)SoundD.envinterval);
			if (old==0)
			{
			    SoundD.envgain = 15;
			    SoundD.envcounter=0;
			}
		}
		break;

	case 0x0d:
		break;

	case 0x0e:
		SoundD.pitch_org =  (sbuffer.sr.R_400E.clock);
		if (sbuffer.sr.R_400E.type==1)
		{
			SoundD.pitch_org += 16;	/** Pink Noise **/
		}
		SoundD.pitch=__PitchTo32_HVC_D(((u16)(SoundD.pitch_org & 0x0F)));
		break;

	case 0x0f:
		old = ( u8 ) ( SoundD.pitch_org );

		SoundD.pitch_org =  (sbuffer.sr.R_400E.clock);
		if (sbuffer.sr.R_400E.type==1)
		{
			SoundD.pitch_org += 16;	/** Pink Noise **/
		}
	  	SoundD.pitch=__PitchTo32_HVC_D(((u16)(SoundD.pitch_org & 0x0F)));
		SoundD.len_org=LEN_TABLE_HVC[sbuffer.sr.R_400F.length];
		SoundD.lencounter=SoundD.len_org*OUTPUT_RATE_PER_FRAME;

		if (sbuffer.sr.R_4015.soundD) SoundD.activity = 1;
		if (sbuffer.sr.R_400C.envflag==0)
		{
			SoundD.volume=(u8)(VOLTABLE_HVCPULSE[15]*SOUNDD_LEVEL);
		}
		else
		{
			SoundD.volume=SoundD.volume_org;
		}

		SoundD.envgain = 15;
		SoundD.envcounter=0;
		break;
	}
}

s16 __ProcessSoundD(void)
{
	s16 sample;

	if (SoundD.activity==0)
	{
		if (SoundD.lastlevel==0) return(0);
			SoundD.lastlevel--;
		SoundD.volume=(u8)(SoundD.lastlevel);
	}

	SoundD.fcounter.fc32+=SoundD.pitch;
	sample = getNosieWaveNew(SoundD.fcounter.fc32);

//if(aho){TCHAR cz[44];wsprintf(cz,"(%d)",SoundD.fcounter.fc32);OutputDebugString(cz);}

	sample=(s16)(sample*SoundD.volume);

	SoundD.fcounter.fc.high=0;
	SoundD.lastlevel=SoundD.volume;

	/* - Envelope Process - */
	if (SoundD.envactivity)
	{
		SoundD.envcounter += SOUND_INT_ONE;
		if( SoundD.envcounter >= SoundD.envinterval)
		{
			SoundD.envcounter -= SoundD.envinterval;
			switch(SoundD.lenmode)
			{
			case 0:
				if (SoundD.envgain) SoundD.envgain--;
				else
				{
				    SoundD.activity=0;
				}
				break;
			case 1:
				if (SoundD.envgain)
					SoundD.envgain--;
				else
					SoundD.envgain=15;
				break;
			}
			SoundD.volume=(u8)(VOLTABLE_HVCPULSE[SoundD.envgain]*SOUNDD_LEVEL);			
		}
	}

	/* - length Mode - */
	if (SoundD.lenmode==0)
	{
		if(SoundD.lencounter > 0)
			SoundD.lencounter--;
		if (SoundD.lencounter==0)
		{
			SoundD.activity=0;
			SoundD.lastlevel = 0;
		}
	}
	sample = (s16)(sample * g_bNesSndD);
	return(sample);
}
#endif
