#ifndef SOUNDE_H
#define	SOUNDE_H
#include "../nesMemory.h"
#include "sounddefine.h"
#include "soundtype.h"

void __ClearSoundEVoltage(void)
{
	delta_counter=0;
	bias = 0;
	bias_move=0;
	voltage = 0;
	voltage_out = 0;
}

void MoveDeltaCounter(u8 input_sample)
{
	if (input_sample)
	{
		//if (delta_counter < 63)
		{
			delta_counter++;
			delta_sign++;
		}
	}
	else
	{
		//if (delta_counter > 0)
		{
			delta_counter--;
			delta_sign--;
		}
	}
}

void MoveBias(void)
{
	s32 old=bias;

	bias+=delta_sign*2;
	if (bias > 127) bias=127;
	if (bias < 0) bias=0;
	bias_move += (bias-old);
	delta_sign=0;
}

void WriteBias(u16 nbias)
{
	bias_move = ((s16)nbias-(s16)bias);
	bias = nbias;
}

s16 MoveVoltage(void)
{
	voltage = voltage * SOUNDE_DOWNCOEF;
	voltage = voltage + (f32)bias_move;
	bias_move =0;

	// Limitter
	if (voltage > 127)
		voltage=127;
	if (voltage < -127)
		voltage=-127;

	voltage_out += (voltage-voltage_out)/4;
	return ((s16)(voltage_out*SOUNDE_OUTPUT_GAIN));
}

u32 __PitchTo32_HVC_E(u16 clock)
{
	return (DMOD_TABLE[clock]);
}

void __Sound_Write_E(u16 reg, u8 value)
{
	(void)value;
	switch(reg)
	{
	case 0x10:
		SoundE.pitch=__PitchTo32_HVC_E(sbuffer.sr.R_4010.clock);
		break;
	case 0x11:
		SoundE.dacsample=(s16)((sbuffer.sr.R_4011) & 0x7F);
		WriteBias( (u16)(SoundE.dacsample) );
		break;
	case 0x12:
		SoundE.baseaddr=( (u16)(sbuffer.sr.R_4012 << 6) );
		break;
	case 0x13:
		SoundE.basecounter=( (u32)(sbuffer.sr.R_4013 << 4) );
		break;
	}
}

void StartE(void)
{
	SoundE.activity=1;
	SoundE.counter=(SoundE.basecounter+1)*8;
	SoundE.fcounter.fc32=0;
	SoundE.lastpointer=0x0;
	SoundE.interrupt=0;

	delta_counter=0;
	bias_move=0;
}

s16 __ProcessSoundE(void)
{
	s16 sample;
	u16 offset;
	u8 read;
	u32 bit,v;

	if (SoundE.activity==0)
		goto SoundE_Exit;

	for(v = 0; v < 2; v++)
	{
		SoundE.fcounter.fc32+=SoundE.pitch;
		if (SoundE.fcounter.fc.high != SoundE.lastpointer)
		{
			offset=(u16)(SoundE.lastpointer >> 3);
			bit =(u32)(SoundE.lastpointer & 0x07);

			if (bit==0)
			{
				u32 ofs = (u32)(SoundE.baseaddr + offset);

				//SoundE.data = nesMemRead8(0xC000 + ofs);
				if(ofs < 0x2000)
					SoundE.data = g_pNesPRGBank[2][ofs&0x1FFF];
				else
					SoundE.data = g_pNesPRGBank[3][ofs&0x1FFF];
				
			}
			read=(u8)((SoundE.data >> bit) & 0x01);

			MoveDeltaCounter(read);

			SoundE.lastpointer=SoundE.fcounter.fc.high;

			if (SoundE.counter!=0)
				SoundE.counter--;
			if (SoundE.counter==0)
			{
				switch(sbuffer.sr.R_4010.repeat)
				{
				case 0:
					SoundE.activity=0;
					if (sbuffer.sr.R_4010.interrupt==1)
						SoundE.interrupt=1;
					break;
				case 1:
					SoundE.counter=(SoundE.basecounter+1)*8;
					SoundE.fcounter.fc.high=0;
					SoundE.lastpointer=0;
					break;
				}
			}
		}
	}

SoundE_Exit:
	MoveBias();
	sample = MoveVoltage();
	sample = (s16)(sample * g_bNesSndE);
	return(sample);
}
#endif
