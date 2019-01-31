#ifndef SOUNDMMC5_H
#define	SOUNDMMC5_H
#include "sounddefine.h"
#include "soundtype.h"
#include "../nesSound.h"

void __ProcessSoundXPitchOrg()
{
	if((SoundX.pitch_org <= 7) || (SoundX.pitch_org >= 0x800))
		SoundX.pitchover=1;
	else
		SoundX.pitchover=0;
}

void __ProcessSoundYPitchOrg()
{
	if((SoundY.pitch_org <= 7) || (SoundY.pitch_org >= 0x800))
		SoundY.pitchover=1;
	else
		SoundY.pitchover=0;
}

void __Sound_Write_MMC5(u16 reg, u8 value)
{
	Sound_HVCpulse_ *sd;
	u8 old;	
	s32 ch;
	MMC5pulse_ *v;
	(void)value;
	v = NULL;
#if TRL_SOUND_REG_LOG
	if(g_pNesSndRegWriteLog_Run == 0)
	{
		if(g_pNesSndRegWriteLog_Ct >= TRL_SOUND_REG_LOG_MAX)
		{
			return;
		}
		g_pNesSndRegWriteLog_Addr[g_pNesSndRegWriteLog_Ct] = reg;
		g_pNesSndRegWriteLog_Value[g_pNesSndRegWriteLog_Ct] = value;
		g_pNesSndRegWriteLog_Ticks[g_pNesSndRegWriteLog_Ct] = g_nNesSndRegWriteLog_Ticks;
		g_pNesSndRegWriteLog_Type[g_pNesSndRegWriteLog_Ct] = 1;
		g_pNesSndRegWriteLog_Ct++;
		return;
	}	
#endif

	sbuffer.buf[reg + 0xC0]=value; 

	sd = NULL;
	if (reg <= 0x03)
	{
		ch=0;
		sd=&SoundX; 
		v=(MMC5pulse_ *)&(sbuffer.buf[0xc0]);
	}
	else if (reg <= 0x07)
	{
		ch=1;
		sd=&SoundY;  
		v=(MMC5pulse_ *)&(sbuffer.buf[0xc4]);
	}
	else if (reg <= 0x11)
	{
		//MMC5-E Write is not support		
	}

	if (reg==0x11)
	{
		SoundZ.lastlevel = (u16)(value << 6);		//	8bit DA
		return;
	}

	if (reg==0x15)
	{		
		if ((value & 0x01 )==0) 
			SoundX.activity=0;
		else
			SoundX.activity=1;
		if ((value & 0x02 )==0)
			SoundY.activity=0;
		else
			SoundY.activity=1;
		return;
	}

	if (v==NULL) 
		return;

	switch(reg & 0x03)
	{
	case 0:
		sd->dutytype=v->R_4000.duty;
		old=sd->envactivity;

		sd->envactivity=(u8)((v->R_4000.envflag) ^1);
		sd->lenmode=(v->R_4000.cont);

		if ( sd->envactivity==0 )
		{
			sd->envgain_target = (u16)(v->R_4000.envgain << 8);		
		}
		else
		{			
			sd->envinterval=(u32)(v->R_4000.envgain+1);
			if( (old==0) && (sd->activity) )
			{
				sd->envgain_target = 15 << 8;
				sd->envcounter=0;
			}
		}		
		break;
	case 2:		
		sd->pitch_org= (u16)((sd->pitch_org & 0xf00) | (v->R_4002));
		if(ch == 0)
			__ProcessSoundXPitchOrg();
		else if(ch == 1)
			__ProcessSoundYPitchOrg();
		sd->pitch=__PitchTo32_HVC(sd->pitch_org);		
		break;
	case 3:		
		sd->pitch_org = (u16)((v->R_4003.freq << 8) | (v->R_4002));
		if(ch == 0)
			__ProcessSoundXPitchOrg();
		else if(ch == 1)
			__ProcessSoundYPitchOrg();
		if(ch == 1 && v->R_4002 != 0)
			ch = ch;
		sd->pitch=__PitchTo32_HVC(sd->pitch_org);
		sd->len_org=LEN_TABLE_HVC[v->R_4003.length];		
		sd->lencounter=sd->len_org*(LEN_SCALE)*2;

		{
			sd->fcounter.fc32=0;
			sd->oldc=0;
		}

		sd->lastlevel = 0;
		sd->envgain   = 0;

		if (ch==0) old=sbuffer.sr.R_40D5.soundX;
		if (ch==1) old=sbuffer.sr.R_40D5.soundY;

		if (old)
		{
			sd->activity=1;
		}
		if (v->R_4000.envflag==0)
		{
			//			sd->volume=(u8)(VOLTABLE_HVCPULSE[15]);
			sd->envgain_target = 15 << 8;
		}
		else
		{
			//			sd->volume=sd->volume_org;
			sd->envgain_target = (u16)(v->R_4000.envgain << 8);
		}
		sd->envcounter=0;
		sd->sweepcounter = 0;    /*** Sweep Interval Reset ***/
		sd->sweepswitch   = 0;
		sd->sweepactivity= 0;	 /* No Sweep */

		//OSReport( "vol=%d\n", sd->volume );
		// hogehoge( sd );
		break;
	}
}

//s16 __ProcessSoundMMC5(Sound_HVCpulse_ *sound, bool bA )
s16 __ProcessSoundMMC5(Sound_HVCpulse_ *sound, Bool bA )
{
	s32 sample;
	f32 wave;
	(void)bA;
	if (sound->activity==0) 
	{
		if(sound->lastlevel==0)
			return 0;		
	}


	/* - Envelope Process - */
	if (sound->envactivity)
	{
		sound->envcounter++;
		if ( (sound->envcounter % sound->envinterval) ==0)
		{
			switch(sound->lenmode)
			{
			case 0: 
				if (sound->envgain_target)
					sound->envgain_target-=0x100;
				else
				{				
					sound->activity=0;	/*** Stop ***/
				}
				break;
			case 1: 
				if (sound->envgain_target)	
					sound->envgain_target-=0x100;
				else						
					sound->envgain_target = 15 << 8;
				break;
			}			
		}
	}

	/* - length Mode - */
	if (sound->lenmode==0)
	{		
		if ((sound->lencounter))
			sound->lencounter--;
		if (sound->lencounter==0)		
			sound->activity=0;		
	}


	/* - Break Check   - */
	if ( sound->pitch_org <= 7)
	{
		sound->pitchover=1;
	}
	else if ( sound->pitch_org >= 0x800 ) 
	{
		sound->pitchover=1;
	}
	else
	{
		sound->pitchover=0;
	}

	sample=(s16)(s8)__GetWave_Pulse( (s32) ( sound->dutytype+DUTY_0 ), (s32)( sound->fcounter.fc.high ) );

	if (sound->pitchover)
	{
		sound->fcounter.fc32+=sound->lastpitch;
	}
	else
	{
		sound->fcounter.fc32+=sound->pitch;
		sound->lastpitch  = (u16)(sound->pitch); /*!!!!20060729*/
	}

	if (sound->fcounter.fc32 & 0xffe00000) 
	{
		sound->sweepswitch |=2;	//
	}

	sound->fcounter.fc32 &= 0x001fffff; /*** Upper 5 bit is active. ***/

	if ((sound->pitchover==1) || (sound->activity==0) )
	{
		if (sound->lastlevel > 0)
			sound->lastlevel--;
	}
	else
	{
		if (sound->lastlevel < 32)
			sound->lastlevel++;
		if (sound->lastlevel < 32)
			sound->lastlevel++;		
	}
	
	{
		f32 wave1,wave2;
		f32 ratio;
		ratio = (f32)(sound->envgain & 0xff) / 256.0f;
		wave1= VOLTABLE_HVCPULSE[sound->envgain >> 8];
		wave2= VOLTABLE_HVCPULSE[(sound->envgain >> 8) +1];
		wave = wave1*(1.0f-ratio) + wave2*ratio;
		
		if (sound->envgain != sound->envgain_target) 
		{
			u16 delta;		
			if (sound->envgain > sound->envgain_target)
			{
				delta = (u16)((sound->envgain -sound->envgain_target) >> 4);
				if (delta==0)
					sound->envgain = sound->envgain_target;
				else
					sound->envgain-= delta;
			}
			else
			{
				if (sound->envgain < sound->envgain_target)
				{
					delta = (u16)((sound->envgain_target -sound->envgain) >> 4);
					if (delta==0)
						sound->envgain = sound->envgain_target;
					else
						sound->envgain+= delta;
				}
			}
		}
	}
	switch(sample)
	{
	case 0:
		wave = (f32)(PULSE_BIAS);
		break;
	case 1:
		wave = (f32)(wave+PULSE_BIAS);
		break;
	}
	sample = (s16)( wave* 0x1000 );
	sample = (sample * sound->lastlevel) >> 5;
	if(sound == &SoundX)
		sample *= g_bNesSnd5A;
	else
		sample *= g_bNesSnd5B;
	return (s16)(sample);
}
#endif
