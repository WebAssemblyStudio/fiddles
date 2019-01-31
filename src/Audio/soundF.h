#ifndef SOUNDF_H
#define	SOUNDF_H
#include "sounddefine.h"
#include "soundtype.h"
#include "../nesSound.h"

u8 __GetWave_Disk(s32 type, s32 counter)
{
	switch(type)
	{
	case DISKFM:
		return (DISKFM_TABLE[counter]);
	case DISKSUB:
		if (DISKSUB_TABLE[counter&0x1F]==4)
		{
			SoundF.subwave=0;
			SoundF.subbias = 0;
		}
		else
		{
			if (counter == SoundF.suboldcounter) 
			{
				return (u8)(SoundF.subwave);
			}
			SoundF.subwave = SoundF.subbias;
			while(counter != SoundF.suboldcounter)
			{
				SoundF.suboldcounter++;
				SoundF.suboldcounter=SoundF.suboldcounter & 0x3f;

				SoundF.subwave=(s8)(SoundF.subwave+disksubwave[SoundF.suboldcounter]);
				if (SoundF.subwave >=64)  SoundF.subwave= (s8)(-64+(SoundF.subwave-64));
				if (SoundF.subwave <=-64) SoundF.subwave= (s8)( 64+(SoundF.subwave+64));
			}
		}
		SoundF.subbias = SoundF.subwave;
		if ( (SoundF.subwave <= 64) && (SoundF.subwave >= -64) )
		{
			return (u8)(SoundF.subwave);
		}
		else
		{
			return (u8)(-32);
		}
	}

	return(0);
}

void  __CreateDiskSubWave(void)
{
	u32 i;
	s16 s=0;

	for (i=0 ; i < 32 ; i++)
	{
		s = DISK_SUB_GAIN[DISKSUB_TABLE[i]];

		disksubwave[i*2]=s;
		disksubwave[i*2+1]=s;
	}
}

u32 __PitchTo32_DISKFM(u16 pitch)
{
	f32 freq;
	u32 cc;

	freq=HVC_CPU_CLOCK/8.0f/(64.0f*4096.0f)*(f32)((s32)pitch);
	cc=(u32)(freq/PITCH_CONST_DISK*32768.0f);
	return(cc);
}

void __Sound_Write_Disk(u16 reg, u8 value)
{
	u8 old;
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
	sbuffer.buf[reg]=value;

	if (reg == 0x23)
	{
		if ((value & 0x02) == 0) 
		{
			SoundF.envgain=0;
			SoundF.envactivity=0;
		}
		return;
	}

	if ( (reg >= 0x40) && (reg <= 0x7f) )
	{
		DISKFM_TABLE[reg-0x40]=(u8)((sbuffer.sr.R_4040[reg-0x40]) & 0x3F);
	}
	else
	{
		switch(reg)
		{
		case 0x80:
			old=SoundF.envactivity;
			SoundF.envactivity=sbuffer.sr.R_4080.envflag;
			SoundF.envsign=sbuffer.sr.R_4080.envsign;

			if (SoundF.envactivity==1)
			{
				SoundF.envgain=sbuffer.sr.R_4080.envgain;
			}
			else
			{
				SoundF.envinterval=DISK_FRAME_SAMPLE*(sbuffer.sr.R_4080.envgain+1)/16;
			}

			if (SoundF.envactivity != old)
			{
				SoundF.envcounter=0;
			}
			break;
		case 0x82:
			SoundF.pitch_org = (u16)((sbuffer.sr.R_4083.freq << 8) | (sbuffer.sr.R_4082));
			SoundF.pitch=__PitchTo32_DISKFM(SoundF.pitch_org);
			break;
		case 0x83:
			SoundF.pitch_org = (u16)((sbuffer.sr.R_4083.freq << 8) | (sbuffer.sr.R_4082));
			SoundF.pitch=__PitchTo32_DISKFM(SoundF.pitch_org);			

			if (sbuffer.sr.R_4083.resetflag)    
			{
				SoundF.fcounter.fc32=0;				//2001.11.10
			}
			break;
		case 0x84:
			old=SoundF.subenvactivity;
			SoundF.subenvactivity=sbuffer.sr.R_4084.envflag;
			SoundF.subenvsign=sbuffer.sr.R_4084.envsign;

			if (SoundF.subenvactivity==1)
			{
				SoundF.subenvgain=sbuffer.sr.R_4084.envgain;
			}
			else
			{
				SoundF.subenvinterval=DISK_FRAME_SAMPLE*(sbuffer.sr.R_4084.envgain+1)/16;
			}

			if (SoundF.subenvactivity != old)
			{
				SoundF.subenvcounter=0;
			}

			break;
		case 0x85:
			SoundF.subbias=(s8)(sbuffer.sr.R_4085 & 0x7F);
			{
				if (SoundF.subbias & 0x40)
					SoundF.subbias |= 0x80;
			}
			SoundF.suboldcounter = -1;
			break;
		case 0x86:
			SoundF.subpitch_org = (u16)((sbuffer.sr.R_4087.freq << 8) | (sbuffer.sr.R_4086));
			SoundF.subpitch=__PitchTo32_DISKFM(SoundF.subpitch_org);
			break;
		case 0x87:
			old=sbuffer.sr.R_4087.writeflag;
			SoundF.subpitch_org = (u16)((sbuffer.sr.R_4087.freq << 8) | (sbuffer.sr.R_4086));
			SoundF.subpitch=__PitchTo32_DISKFM(SoundF.subpitch_org);
			SoundF.sub_writeflag=sbuffer.sr.R_4087.writeflag;

			if ( (sbuffer.sr.R_4087.writeflag == 0) && (old==1) ) 
			{
				__CreateDiskSubWave();
			}

			if (SoundF.sub_writeflag)
			{
				__sound_write_disk_shiftr=0;
				//SoundF.subwave=0;   /* Reset Wave */
			}
			//SoundF.suboldcounter = -1;
			SoundF.subfcounter.fc32=0;
			SoundF.subwave=0;
			break;
		case 0x88:
			if (__sound_write_disk_shiftr >= 32)
				break;
			DISKSUB_TABLE[__sound_write_disk_shiftr & 0x1f]=(u8)(value & 0x07);
			__sound_write_disk_shiftr++;
			if (__sound_write_disk_shiftr == 32)
				__CreateDiskSubWave();
			break;
		case 0x89:
			SoundF.dacgain=(u8)(DISKFM_GAINTABLE[sbuffer.sr.R_4089.gain]);
			SoundF.main_writeflag=sbuffer.sr.R_4089.writeflag;
			break;
		case 0x8A:
			SoundF.envspeed=sbuffer.sr.R_408A;
			break;
		}
	}
}

u16 __ProcessSoundF(void)
{
	f32 outfreq;
	s32 outvol,sub32;
	u16 sample;
	u8 envgain;
	s8 subsample;

	if (SoundF.sub_writeflag) 
		subsample=0;
	else if (SoundF.subpitch==0) 
		subsample=0;
	else
	{
		subsample=(s8)__GetWave_Disk(DISKSUB, SoundF.subfcounter.fc.high);
		SoundF.subbias = subsample;
		SoundF.subfcounter.fc32+=SoundF.subpitch;	
		SoundF.subfcounter.fc32 &= 0x003fffff; /*** Upper 6 bit is active. ***/
	}

	sub32 = (s32)subsample;

	if(SoundF.subenvgain < 0x20)
		outvol =VOLTABLE_DISKFM_SUB[SoundF.subenvgain];
	else
		outvol = 32;//VOLTABLE_DISKFM_SUB[SoundF.subenvgain];
	outvol=outvol * (sub32);			//  Vibrato Range Adjust (00/05/29)	outvol 0-64 sub32 -32-0-32

	if(outvol &0xF)
	{
		outvol /= 16;
		if(SoundF.subbias  >= 0)
			outvol += 2;
		else
			outvol -= 1;
	}
	else
		outvol /= 16;

	if(outvol  > 193)
		outvol -= 258;
	if(outvol < -64)
		outvol += 256;

	outfreq = ((f32)outvol + 64)/64.0f;
	sample=__GetWave_Disk(DISKFM, SoundF.fcounter.fc.high);

	SoundF.fcounter.fc32+=(s32)((f32)SoundF.pitch*outfreq);	
	SoundF.fcounter.fc32 &= 0x003fffff; /*** Upper 6 bit is active. ***/

	SoundF.lastlevel=SoundF.volume;
	SoundF.lastpitch=(u16)(SoundF.pitch); /*!!!!20060729*/

	sample = (u16)(sample*SoundF.volume);
	sample = (u16)(sample << 1);

	sample=(u16)((SoundF.lastsample+sample) >> 1);
	SoundF.lastsample=sample;


	/* - Envelope Process - */
	if (SoundF.envactivity==0)
	{
		SoundF.envcounter++;
		//if (SoundF.envinterval==0) return(sample);
		if (SoundF.envinterval!=0)
		{
			if ( (SoundF.envcounter % SoundF.envinterval) ==0)
			{
				switch(SoundF.envsign)
				{
				case 0: 
					if (SoundF.envgain)
						SoundF.envgain--;
					break;
				case 1: 
					if (SoundF.envgain < 32) 
						SoundF.envgain++;
					else 
						SoundF.envgain=32;
					break;
				}
				envgain = SoundF.envgain;
				if (envgain > 32) envgain =32;
				SoundF.volume=VOLTABLE_DISKFM[envgain];
			}
		}
	}
	else
	{
		envgain = SoundF.envgain;
		if (envgain > 32)
			envgain =32;		
		SoundF.volume=VOLTABLE_DISKFM[envgain];
	}

	if (SoundF.subenvactivity==0)
	{
		SoundF.subenvcounter++;

		if (SoundF.subenvinterval==0)
			return(sample);

		if ( (SoundF.subenvcounter % SoundF.subenvinterval) ==0)
		{
			switch(SoundF.subenvsign)
			{
			case 0: 
				if (SoundF.subenvgain > 0) SoundF.subenvgain--;
				else SoundF.subenvgain=0;
				break;
			case 1: 
				if (SoundF.subenvgain < 32) SoundF.subenvgain++;
				else SoundF.subenvgain=32;
				break;
			}
			envgain = SoundF.subenvgain;
			if (envgain > 32) 
				envgain =32;			
			SoundF.subvolume=VOLTABLE_DISKFM_SUB[envgain];
		}
	}
	else
	{
		envgain = SoundF.subenvgain;
		if (envgain > 32) 
			envgain = 32;		
		SoundF.subvolume=VOLTABLE_DISKFM_SUB[envgain];
	}
	sample = (s16)(sample * g_bNesSndF);
	return(sample);
}
#endif
