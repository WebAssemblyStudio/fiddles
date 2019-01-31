#ifndef SOUNDQ_H
#define	SOUNDQ_H
#include "sounddefine.h"
#include "soundtype.h"

static s32	vol_table[0x20];
static s32	cycle_rate;

// Envelope tables
static u8	envelope_pulse0[] = {
	0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18,
	0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
	0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
	0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00
};
static u8	envelope_pulse1[] = {
	      0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x00
};
static u8	envelope_pulse2[] = {
	0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18,
	0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
	0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
	0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x1F
};
static u8	envelope_pulse3[] = {
	      0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x1F
};
static s8	envstep_pulse[] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0
};

static u8	envelope_sawtooth0[] = {
	0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18,
	0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
	0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
	0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00
};
static u8	envelope_sawtooth1[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
};
static s8	envstep_sawtooth[] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, -15
};

static u8	envelope_triangle0[] = {
	0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18,
	0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
	0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
	0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
};
static u8	envelope_triangle1[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18,
	0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
	0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
	0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00
};
static s8	envstep_triangle[] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, -31
};


static u8*	envelope_table[16] = {
	envelope_pulse0,    envelope_pulse0, envelope_pulse0,    envelope_pulse0,
	envelope_pulse1,    envelope_pulse1, envelope_pulse1,    envelope_pulse1,
	envelope_sawtooth0, envelope_pulse0, envelope_triangle0, envelope_pulse2,
	envelope_sawtooth1, envelope_pulse3, envelope_triangle1, envelope_pulse1
};

static s8* envstep_table[16] = {
	envstep_pulse,    envstep_pulse, envstep_pulse,    envstep_pulse,
	envstep_pulse,    envstep_pulse, envstep_pulse,    envstep_pulse,
	envstep_sawtooth, envstep_pulse, envstep_triangle, envstep_pulse,
	envstep_sawtooth, envstep_pulse, envstep_triangle, envstep_pulse
};

#define	APU_CLOCK		1789772.5f

static void	APU_FME7_Setup( f32 fClock, s32 nRate )
{
	//cpu_clock = fClock;
	cycle_rate = (s32)((fClock/16.0f)*(1<<16)/nRate);
}

static void	APU_FME7_Reset( f32 fClock, s32 nRate )
{
	s32	i;
	double	out = 0x1FFF;

	trlMemSet(&SoundQ, 0, sizeof(Sound_FME7_));

	// Volume to voltage
	for( i = 31; i > 1; i-- ) {
		vol_table[i] = (s32)(out+0.5);
		out /= 1.188502227;	/* = 10 ^ (1.5/20) = 1.5dB */
	}
	vol_table[1] = 0;
	vol_table[0] = 0;

	APU_FME7_Setup( fClock, nRate );
}

void __Sound_Init_FME7(void)
{
	APU_FME7_Reset( APU_CLOCK, OUTPUT_RATE );
}

static void EnvelopeRender()
{
	if( !SoundQ.envelope.freq )
		return;
	SoundQ.envelope.phaseacc -= cycle_rate;
	if( SoundQ.envelope.phaseacc >= 0 )
		return;
	while( SoundQ.envelope.phaseacc < 0 ) {
		SoundQ.envelope.phaseacc += SoundQ.envelope.freq;
		SoundQ.envelope.envadr += SoundQ.envelope.envstep[SoundQ.envelope.envadr];
	}
	SoundQ.envelope.volume = SoundQ.envelope.envtbl[SoundQ.envelope.envadr];
}

static void NoiseRender()
{
	if( !SoundQ.noise.freq )
		return;
	SoundQ.noise.phaseacc -= cycle_rate;
	if( SoundQ.noise.phaseacc >= 0 )
		return;
	while( SoundQ.noise.phaseacc < 0 ) {
		SoundQ.noise.phaseacc += SoundQ.noise.freq;
		if( (SoundQ.noise.noiserange+1) & 0x02 )
			SoundQ.noise.noiseout = ~SoundQ.noise.noiseout;
		if( SoundQ.noise.noiserange & 0x01 )
			SoundQ.noise.noiserange ^= 0x28000;
		SoundQ.noise.noiserange >>= 1;
	}
}

void __ProcessSoundQ_Env()
{
	EnvelopeRender();
	NoiseRender();
}

static s32 ChannelRender( SOUND_Q_CHANNEL *ch )
{
	s32 output, volume;

	if( ch->enable )
		return	0;
	if( !ch->freq )
		return	0;

	ch->phaseacc -= cycle_rate;
	while( ch->phaseacc < 0 ) {
		ch->phaseacc += ch->freq;
		ch->adder++;
	}

	output = volume = 0;
	volume = ch->env_on?vol_table[SoundQ.envelope.volume]:vol_table[ch->volume+1];

	if( ch->adder & 0x01 ) {
		output += volume;
	} else {
		output -= volume;
	}
	if( !ch->noise_on ) {
		if( SoundQ.noise.noiseout )
			output += volume;
		else
			output -= volume;
	}

	ch->output_vol = output;

	return	ch->output_vol;
}


s32 __ProcessSoundQ( s32 channel )
{
	return ChannelRender(&SoundQ.op[channel]);
}

#define	INT2FIX(x)	((x)<<16)

void __Sound_Write_FME7(u16 addr, u8 data)
{
	s32 i;

	if( addr == 0xC000 ) {
		SoundQ.address = data;
	} else if( addr == 0xE000 ) {
		u8	chaddr = SoundQ.address;
		switch( chaddr ) {
			case	0x00: 
			case	0x01:
			case	0x02: 
			case	0x03:
			case	0x04: 
			case	0x05:
				{
				SOUND_Q_CHANNEL* ch = &(SoundQ.op[chaddr>>1]);
				ch->reg[chaddr&0x01] = data;
				ch->freq = INT2FIX(((s32)(ch->reg[1]&0x0F)<<8)+ch->reg[0]+1);
				}
				break;
			case	0x06:
				SoundQ.noise.freq = INT2FIX((s32)(data&0x1F)+1);
				break;
			case	0x07:
				{
				for( i = 0; i < 3; i++ ) {
					SoundQ.op[i].enable   = data&(1<<i);
					SoundQ.op[i].noise_on = data&(8<<i);
				}
				}
				break;
			case	0x08:
			case	0x09:
			case	0x0A:
				{
				SOUND_Q_CHANNEL* ch = &(SoundQ.op[chaddr&3]);
				ch->reg[2] = data;
				ch->env_on = data & 0x10;
				ch->volume = (data&0x0F)*2;
				}
				break;
			case	0x0B:
			case	0x0C:
				SoundQ.envelope.reg[chaddr-0x0B] = data;
				SoundQ.envelope.freq = INT2FIX(((s32)(SoundQ.envelope.reg[1]&0x0F)<<8)+SoundQ.envelope.reg[0]+1);
				break;
			case	0x0D:
				SoundQ.envelope.envtbl  = envelope_table[data&0x0F];
				SoundQ.envelope.envstep = envstep_table [data&0x0F];
				SoundQ.envelope.envadr  = 0;
				break;
		}
	}
}
#endif
