#ifndef SOUNDA_H
#define	SOUNDA_H
#include "pulse.h"

void __ProcessSoundAPitchOrg()
{
	if ((SoundA.pitch_org <= 7) || (SoundA.pitch_org >= 0x800))
		SoundA.pitchover=1;
	else
		SoundA.pitchover=0;
}

void __Sound_Write_A(u16 reg, u8 value)
{
	u8 old;

	(void)value;
	switch(reg)
	{
	case 0:
		old = SoundA.envactivity;
		SoundA.dutytype=sbuffer.sr.R_4000.duty;
		SoundA.envactivity=(u8)((sbuffer.sr.R_4000.envflag) ^1);
		SoundA.lenmode=(sbuffer.sr.R_4000.cont);
		if (SoundA.envactivity==0)
			SoundA.envgain_target = (u16)(sbuffer.sr.R_4000.envgain << 8);
		else
		{
			SoundA.envinterval = __SoundEnvelopeRateTo32((u32)(sbuffer.sr.R_4000.envgain+1));
			if ((old==0) && (SoundA.activity))
			{
				SoundA.envgain_target = 15 << 8;
				SoundA.envcounter=0;
			}
		}
		break;
	case 1:
		SoundA.sweepinterval = __SoundSweepRateTo32((u32)((sbuffer.sr.R_4001.interval+1)));
		SoundA.sweepsign = (sbuffer.sr.R_4001.sign);
		SoundA.sweepshift = (sbuffer.sr.R_4001.shift);
		SoundA.sweepcounter = 0;
		SoundA.sweepswitch = 0;
		SoundA.sweepactivity = (sbuffer.sr.R_4001.sweep);
		break;
	case 2:
		SoundA.pitch_org = (u16)((SoundA.pitch_org & 0xf00) | (sbuffer.sr.R_4002));
		__ProcessSoundAPitchOrg();
		SoundA.pitch = __PitchTo32_HVC(SoundA.pitch_org);
		//stop sound
		if(!SoundA.sweepsign)
		{
			u16 shiftpitch = (u16)((SoundA.pitch_org >> SoundA.sweepshift));
			shiftpitch += SoundA.pitch_org;
			if(shiftpitch >= 0x800)
				SoundA.activity = 0;
		}
		break;
	case 3:
		SoundA.pitch_org = (u16)((sbuffer.sr.R_4003.freq << 8) | (sbuffer.sr.R_4002));
		__ProcessSoundAPitchOrg();
		SoundA.pitch = __PitchTo32_HVC(SoundA.pitch_org);
		SoundA.len_org = LEN_TABLE_HVC[sbuffer.sr.R_4003.length];
		SoundA.lencounter = SoundA.len_org*OUTPUT_RATE_PER_FRAME;
		SoundA.fc32=0;
		SoundA.oldc=0;
		SoundA.lastlevel = 0;
		SoundA.envgain = 0;

		if (sbuffer.sr.R_4015.soundA)
			SoundA.activity=1;

		if (sbuffer.sr.R_4000.envflag==0)
			SoundA.envgain_target = 15 << 8;
		else
			SoundA.envgain_target = (u16)(sbuffer.sr.R_4000.envgain << 8);

		SoundA.envcounter = 0;
		SoundA.sweepcounter = 0;
		SoundA.sweepswitch = 0;
		SoundA.sweepactivity = (sbuffer.sr.R_4001.sweep);

		//stop sound
		if(!SoundA.sweepsign)
		{
			u16 shiftpitch = (u16)((SoundA.pitch_org >> SoundA.sweepshift));
			shiftpitch += SoundA.pitch_org;
			if(shiftpitch >= 0x800)
				SoundA.activity = 0;
		}
		break;
	}
}

s16 __ProcessSoundA()
{
	u32 samplef32;
	s32 sample;
	f32 wave;

	/* - Sweep Process - */
	if (SoundA.sweepactivity)
	{
		SoundA.sweepcounter += SOUND_INT_ONE;
		if( SoundA.sweepcounter >= SoundA.sweepinterval)
		{
			u16 shiftpitch;
			SoundA.sweepcounter -= SoundA.sweepinterval;
			SoundA.sweepswitch=0;
			shiftpitch = (u16)((SoundA.pitch_org >> SoundA.sweepshift));
			if (SoundA.sweepshift==0)
				shiftpitch=0;

			switch(SoundA.sweepsign)
			{
			case 0:
				SoundA.pitch_org=(u16)(SoundA.pitch_org + shiftpitch);
				break;
			case 1:
				if (SoundA.sweepshift==0)
					shiftpitch=0;
				SoundA.pitch_org=(u16)(SoundA.pitch_org - shiftpitch);
				if ( (SoundA.pitch_org!=0) && (SoundA.sweepshift!=0) )
					SoundA.pitch_org--;
				break;
			}

			if (SoundA.pitch_org > 0x800)
				SoundA.pitch_org = 0x800;
			else
				SoundA.pitch=__PitchTo32_HVC(SoundA.pitch_org);
			__ProcessSoundAPitchOrg();
		}
	}

	if (SoundA.activity==0)
	{	
		if (SoundA.lastlevel==0)
			return(0);
	}

	/* - Envelope Process - */
	if (SoundA.envactivity)
	{
		SoundA.envcounter += SOUND_INT_ONE;
		if( SoundA.envcounter >= SoundA.envinterval)
		{
			SoundA.envcounter -= SoundA.envinterval;
			switch(SoundA.lenmode)
			{
			case 0:
				if (SoundA.envgain_target)
					SoundA.envgain_target-=0x100;
				else
					SoundA.activity=0; /*** Stop ***/
				break;
			case 1:
				if (SoundA.envgain_target)
					SoundA.envgain_target-=0x100;
				else
				{
					SoundA.envgain_target = 15 << 8;
					SoundA.envgain = 15 << 8;
					SoundA.fc32=0;
				}
				break;
			}
		}
	}

	/* - length Mode - */
	if (SoundA.lenmode==0)
	{
		if(SoundA.lencounter)
			SoundA.lencounter--;
		if (SoundA.lencounter==0)
			SoundA.activity=0;
	}

	samplef32 = __GetWave_Pulse2(SoundA.dutytype+DUTY_0, &(SoundA.fc32), SoundA.pitch);

	if (!SoundA.pitchover)
		SoundA.lastpitch = (u16)(SoundA.pitch);

	if ((SoundA.pitchover==1) || (SoundA.activity==0) )
	{
		if (SoundA.lastlevel > 0)
			SoundA.lastlevel--;
	}
	else
	{
		if (SoundA.lastlevel < 32)
			SoundA.lastlevel++;
		if (SoundA.lastlevel < 32)
			SoundA.lastlevel++;
	}

	wave = VOLTABLE_HVCPULSE[SoundA.envgain >> 8];
	if (SoundA.envgain != SoundA.envgain_target)
	{
		f32 ratio = (f32)(SoundA.envgain & 0xff) / 256.0f;
		f32 wave1= VOLTABLE_HVCPULSE[SoundA.envgain >> 8];
		f32 wave2= VOLTABLE_HVCPULSE[(SoundA.envgain >> 8) +1];
		wave = wave1*(1.0f-ratio) + wave2*ratio;

		if (SoundA.envgain > SoundA.envgain_target)
		{
			u16 delta = (u16)((SoundA.envgain -SoundA.envgain_target) >> 4);
			if (delta==0)
				SoundA.envgain = SoundA.envgain_target;
			else
				SoundA.envgain-= delta;
		}
		else
		{
			u16 delta = (u16)((SoundA.envgain_target -SoundA.envgain) >> 4);
			if (delta==0)
				SoundA.envgain = SoundA.envgain_target;
			else
				SoundA.envgain+= delta;
		}
	}

	sample = (s16)((f32)(wave) * samplef32);
	sample = (sample * SoundA.lastlevel) >> 5; //32
	sample *= g_bNesSndA;
	return (s16)(sample);
}
#endif
