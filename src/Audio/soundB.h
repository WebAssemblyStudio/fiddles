#ifndef SOUNDB_H
#define	SOUNDB_H
#include "pulse.h"

void __ProcessSoundBPitchOrg()
{
	if ((SoundB.pitch_org <= 7) || (SoundB.pitch_org >= 0x800))
		SoundB.pitchover=1;
	else
		SoundB.pitchover=0;
}

void __Sound_Write_B(u16 reg, u8 value)
{
	u8 old;
	(void)value;
	reg = (u16)(reg - 4);
	switch(reg)
	{
	case 0:
		old=SoundB.envactivity;
		SoundB.dutytype=sbuffer.sr.R_4004.duty;
		SoundB.envactivity=(u8)((sbuffer.sr.R_4004.envflag) ^1);
		SoundB.lenmode=(sbuffer.sr.R_4004.cont);
		if (SoundB.envactivity==0) 
		{
			SoundB.envgain_target = (u16)(sbuffer.sr.R_4004.envgain << 8);
		}
		else
		{
			SoundB.envinterval=(u32)(sbuffer.sr.R_4004.envgain+1);
			SoundB.envinterval = __SoundEnvelopeRateTo32((u16)SoundB.envinterval);
			if ( (old==0) && (SoundB.activity) )
			{
				SoundB.envgain_target = 15 << 8;
				SoundB.envcounter=0;
			}
		}
		break;
	case 1:
		SoundB.sweepinterval=(u32)((sbuffer.sr.R_4005.interval+1));
		SoundB.sweepinterval = __SoundSweepRateTo32((u16)SoundB.sweepinterval);
		
		SoundB.sweepsign=(sbuffer.sr.R_4005.sign);
		SoundB.sweepshift=(sbuffer.sr.R_4005.shift);

		SoundB.sweepcounter = 0;
		SoundB.sweepswitch  = 0;

		SoundB.sweepactivity=(sbuffer.sr.R_4005.sweep);
		break;
	case 2:
		SoundB.pitch_org=(u16)((SoundB.pitch_org & 0xf00) | (sbuffer.sr.R_4006));
		__ProcessSoundBPitchOrg();
		SoundB.pitch=__PitchTo32_HVC(SoundB.pitch_org);
		
		if(!SoundB.sweepsign)
		{
			u16 shiftpitch;			
			shiftpitch=(u16)((SoundB.pitch_org >> SoundB.sweepshift));
			shiftpitch += SoundB.pitch_org;
			if(shiftpitch >= 0x800)
			{
				 SoundB.activity = 0;				 
			}
		}
		break;
	case 3:
		SoundB.pitch_org = (u16)((sbuffer.sr.R_4007.freq << 8) | (sbuffer.sr.R_4006));
		__ProcessSoundBPitchOrg();
		SoundB.pitch=__PitchTo32_HVC(SoundB.pitch_org);

		SoundB.len_org=LEN_TABLE_HVC[sbuffer.sr.R_4007.length];

		SoundB.lencounter=SoundB.len_org*OUTPUT_RATE_PER_FRAME;

		{
			SoundB.fcounter.fc32=0;
			SoundB.oldc=0;
		}

		SoundB.lastlevel = 0;
		SoundB.envgain   = 0;

		if (sbuffer.sr.R_4015.soundB)
		{
			SoundB.activity=1;
		}
		if (sbuffer.sr.R_4004.envflag==0)
		{			
			SoundB.envgain_target = 15 << 8;
		}
		else	
		{		
			SoundB.envgain_target = (u16)(sbuffer.sr.R_4004.envgain << 8);
		}
		SoundB.envcounter=0;
		SoundB.sweepcounter = 0;
		SoundB.sweepswitch  = 0;

		SoundB.sweepactivity=(sbuffer.sr.R_4005.sweep);

		//stop sound 
		if(!SoundB.sweepsign)
		{
			u16 shiftpitch;			
			shiftpitch=(u16)((SoundB.pitch_org >> SoundB.sweepshift));
			shiftpitch += SoundB.pitch_org;
			if(shiftpitch >= 0x800)
			{
				 SoundB.activity = 0;
			}
		}
		
		break;
	}
}

s16 __ProcessSoundB(void)
{
	s32 sample;
	u32 samplef32;
	f32 wave;


	/* - Sweep Process - */
	if (SoundB.sweepactivity)
	{
		SoundB.sweepcounter += SOUND_INT_ONE;
		if( SoundB.sweepcounter >= SoundB.sweepinterval)
		{
			u16 shiftpitch;
			SoundB.sweepcounter -= SoundB.sweepinterval;

			SoundB.sweepswitch=0;

			shiftpitch = (u16)(SoundB.pitch_org >> SoundB.sweepshift);
			if (SoundB.sweepshift==0) shiftpitch=0;

			switch(SoundB.sweepsign)
			{
			case 0: 
				SoundB.pitch_org=(u16)(SoundB.pitch_org + shiftpitch);
				break;
			case 1: 
				if (SoundB.sweepshift==0) shiftpitch=0;				
				SoundB.pitch_org=(u16)(SoundB.pitch_org - shiftpitch);
				break;
			}

			if (SoundB.pitch_org >= 0x800)
			{
				SoundB.pitch_org=0x800;				
			}	
			else
			{
				SoundB.pitch=__PitchTo32_HVC(SoundB.pitch_org);
			}
			__ProcessSoundBPitchOrg();
		}
	}

	if (SoundB.activity==0)
	{
		//if (SoundB.lastlevel==0) 
			return(0);		
	}


	/* - Envelope Process - */
	if (SoundB.envactivity)
	{
		SoundB.envcounter += SOUND_INT_ONE;
		if( SoundB.envcounter >= SoundB.envinterval)
		{
			SoundB.envcounter -= SoundB.envinterval;
			switch(SoundB.lenmode)
			{
			case 0: 
				if (SoundB.envgain_target) 
					SoundB.envgain_target-=0x100;
				else
				{					
					SoundB.activity=0;
				}
				break;
			case 1: 
				if (SoundB.envgain_target) SoundB.envgain_target-=0x100;
				else
				{
					SoundB.envgain_target = 15 << 8;
					SoundB.envgain = 15 << 8;
					SoundB.fcounter.fc32=0;
				}
				break;
			}			
		}
	}


	/* - length Mode - */
	if (SoundB.lenmode==0)
	{

		if(SoundB.lencounter)
			SoundB.lencounter--;
		if (SoundB.lencounter==0)		
			SoundB.activity=0;		
	}

	samplef32=__GetWave_Pulse2(SoundB.dutytype+DUTY_0, &(SoundB.fcounter.fc32), SoundB.pitch);

	if (!SoundB.pitchover)
		SoundB.lastpitch  = (u16)(SoundB.pitch);


	if ((SoundB.pitchover==1) || (SoundB.activity==0) )
	{
		if (SoundB.lastlevel > 0) SoundB.lastlevel--;
	}
	else
	{
		if (SoundB.lastlevel < 32) SoundB.lastlevel++;
		if (SoundB.lastlevel < 32) SoundB.lastlevel++;	
	}

	{	
		wave = VOLTABLE_HVCPULSE[SoundB.envgain >> 8];
		if (SoundB.envgain != SoundB.envgain_target)		
		{
			f32 wave1,wave2;
			f32 ratio;
			u16 delta;

			ratio = (f32)(SoundB.envgain & 0xff) / 256.0f;

			wave1= VOLTABLE_HVCPULSE[SoundB.envgain >> 8];
			wave2= VOLTABLE_HVCPULSE[(SoundB.envgain >> 8) +1];

			wave = wave1*(1.0f-ratio) + wave2*ratio;
			if (SoundB.envgain > SoundB.envgain_target)
			{
				delta = (u16)((SoundB.envgain -SoundB.envgain_target) >> 4);
				if (delta==0) SoundB.envgain = SoundB.envgain_target;
				else		  SoundB.envgain-= delta;
			}
			else
			{
				delta = (u16)((SoundB.envgain_target -SoundB.envgain) >> 4);
				if (delta==0) SoundB.envgain = SoundB.envgain_target;
				else		  SoundB.envgain+= delta;
			}			
		}
	}

	sample = (s16)((f32)(wave) * samplef32);
	sample = (sample * SoundB.lastlevel) >> 5;
	sample *= g_bNesSndB;
	return (s16)(sample);
}
#endif
