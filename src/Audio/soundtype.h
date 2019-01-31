#pragma once
#include "sounddefine.h"

typedef struct
{
	u16 objects;
	u16 addr_offset;
	u16 size_offset;
	u16 info_offset;
} Pcmh_;

typedef struct
{
	u8  *mytop;
	u16 *addr_table;
	u16 *size_table;
	u16 *info_table;
}Pcmh2_;

typedef struct
{
	struct
	{
		u8  envgain  :4;
		u8  duty     :3;
		u8  gate     :1;
	}	    
	R_4000;
	u8  R_4001;
	u8	R_4002;
	struct
	{
		u8  freq     :4;
		u8  dummy    :3;
		u8  enable   :1;
	}
	R_4003;
}VRCpulse_;

typedef struct
{
	struct
	{
		u8  envgain  :4;
		u8  envflag  :1;
		u8  cont     :1;
		u8  duty     :2;
	}	    
	R_4000;
	u8  R_4001;
	u8	R_4002;
	struct
	{
		u8  freq     :3;
		u8  length   :5;
	}
	R_4003;
}MMC5pulse_;

enum WAVETYPE
{
	DUTY_0 = 0, 
	DUTY_1, 
	DUTY_2, 
	DUTY_3, 
	TRIANGLE, 
	DELTA_MOD, 
	NOISE, 
	FREE , 
	DISKFM, 
	DISKSUB, 
	MENUPCM, 
	VRCSAW, 
	VRC_DUTY_0 = 4, 
	VRC_DUTY_1, 
	VRC_DUTY_2, 
	VRC_DUTY_3, 
	VRC_DUTY_4, 
	VRC_DUTY_5, 
	VRC_DUTY_6, 
	VRC_DUTY_7
};


typedef struct
{
	u16 low;
	u16 high;
}Fcr_;

typedef union
{
	Fcr_      fc;
	u32	      fc32;
}Fcounter_;

typedef struct
{
	u16      left;
	//u16      right;
}Dac_;

typedef struct
{
	u8	  activity;
	u8	  volume;
	u8	  number;
	u8		paddinga;
	Fcounter_ fcounter;
	u32	  pitch32;	
	u16	  lastlevel;
	u16   paddingb;
	s8	  *datatop;
	s32	  datalen;
}Sound_Pcm_;

	typedef	struct {
		u8	reg[3];
		u8	volume;

		s32	freq;
		s32	phaseacc;
		s32	envadr;

		u8*	envtbl;
		s8*	envstep;
	} SOUND_Q_ENVELOPE;

	typedef	struct {
		s32	freq;
		s32	phaseacc;
		s32	noiserange;
		u8	noiseout;
	} SOUND_Q_NOISE;

	typedef	struct {
		u8	reg[3];
		u8	enable;
		u8	env_on;
		u8	noise_on;
		u8	adder;
		u8	volume;

		s32	freq;
		s32	phaseacc;

		s32	output_vol;
	} SOUND_Q_CHANNEL;

typedef struct
{
	SOUND_Q_ENVELOPE envelope;
	SOUND_Q_NOISE	noise;
	SOUND_Q_CHANNEL	op[3];

	u8	address;
} Sound_FME7_;

typedef struct
{
	u8	  activity;
	u8	  envactivity;
	u8	  sweepactivity;
	u8	  reinit;


	Fcounter_ fcounter;
	u32	  fc32;
	u32	  pitch;	/*** Upper 16,Lower 16 ***/
	u16	  pitch_org;	/*** Upper 16,Lower 16 ***/
	u16		paddinga;

	u32	  lencounter;
	u32	  lenmode;
	u32	  len_org;

	u8	  volume;
	u8	  volume_org;
	u16   paddingb;

	u32	  envcounter;
	u32	  envinterval;

	u16	  envgain;
	u16   envgain_target;

	u32	  sweepcounter;	    /*** Sample Counter (inc.) ***/
	u32	  sweepinterval;    /*** N samples . if (counter % interval) == 0 shift go.***/

	u8	  sweepshift;
	u8	  sweepsign;
	
	u8	  sweepswitch;

	u8	  dutytype;	/*** 0-3 ***/
	u16	  lastlevel;
	u16	  lastpitch;
	u16	  lastsample;

	
	u16	  envelope_delay;

	u16   oldc;

	u8	  pitchover;
	u8	  paddingc;
}Sound_HVCpulse_;

typedef struct
{
	u8	  activity;
	u8	  data;
	u8	  interrupt;
	u8	  paddinga;

	Fcounter_ fcounter;
	u32	  pitch;	/*** Upper 16,Lower 16 ***/
	
	u32	  basecounter;
	u32	  counter;

	u16	  pitch_org;	/*** Upper 16,Lower 16 ***/

	u16	  baseaddr;		/*** DeltaModulation Base ***/
	u16	  lastpointer;

	s16	  dacsample;
}Sound_HVCdeltamod_;

typedef struct
{
	u8	  activity;
	
	u8	  envactivity;
	u8	  envgain;
	u8	  envsign;


	Fcounter_ fcounter;
	Fcounter_ subfcounter;
	s32       suboldcounter;

	u32	  pitch;	/*** Upper 16,Lower 16 ***/
	u32	  subpitch;	/*** Upper 16,Lower 16 ***/

	u16	  pitch_org;	/*** Upper 16,Lower 16 ***/
	u16	  subpitch_org;	/*** Upper 16,Lower 16 ***/

	u8	  volume;
	u8	  volume_org;

	u8	  subvolume;
	u8	  subvolume_org;

	u32	  envcounter;
	u32	  envinterval;
	


	u32	  subenvcounter;
	u32	  subenvinterval;
	u8	  subenvactivity;
	u8	  subenvgain;
	u8	  subenvsign;
	u8	  paddinga;

	u16	  lastlevel;
	u16	  lastpitch;
	u16	  lastsample;

	u8	  pitchover;

	u8	  dacgain;
	s8	  subbias;

	u8	  main_writeflag;
	u8	  sub_writeflag;

	s8	  subwave;

	u8	  envspeed;
	u8		paddingb[3];
}Sound_HVCdiskfm_;

enum SOUND_HARDWARE_TARGET
{
	SOUND_MMC = 0,
	SOUND_VRC,
	SOUND_DISK,
	SOUND_OTHER
};

typedef struct
{
	struct
	{
		u8  envgain  :4;
		u8  envflag  :1;
		u8  cont     :1;
		u8  duty     :2;
	}	    
	R_4000;
	struct
	{
		u8  shift    :3;
		u8  sign     :1;
		u8  interval :3;
		u8  sweep    :1;
	}
	R_4001;
	u8	R_4002;
	struct
	{
		u8  freq     :3;
		u8  length   :5;
	}
	R_4003;

	struct
	{
		u8  envgain  :4;
		u8  envflag  :1;
		u8  cont     :1;
		u8  duty     :2;
	}	    
	R_4004;

	struct
	{
		u8  shift    :3;
		u8  sign     :1;
		u8  interval :3;
		u8  sweep    :1;
	}
	R_4005;
	u8	R_4006;
	struct
	{
		u8  freq     :3;
		u8  length   :5;
	}
	R_4007;

	struct
	{
		u8  length2  :7;
		u8  cont     :1;
	}	    
	R_4008;
	struct
	{
		u8  shift    :3;
		u8  add      :1;
		u8  interval :3;
		u8  sweep    :1;
	}
	R_4009;
	u8	R_400A;
	struct
	{
		u8  freq     :3;
		u8  length   :5;
	}
	R_400B;

	struct
	{
		u8  envgain  :4;
		u8  envflag  :1;
		u8  cont     :1;
		u8  duty     :2;
	}	    
	R_400C;
	u8 R_400D;

	struct
	{
		u8  clock    :4;
		u8  dummy    :3;
		u8  type     :1;
	}	    
	R_400E;

	struct
	{
		u8  freq     :3;
		u8  length   :5;
	}
	R_400F;

	struct
	{
		u8  clock      :4;
		u8  dummy      :2;
		u8  repeat     :1;
		u8  interrupt  :1;
	}
	R_4010;

	u8	R_4011;
	u8	R_4012;
	u8	R_4013;
	u8	R_4014;

	struct
	{
		u8	soundA : 1;
		u8	soundB : 1;
		u8	soundC : 1;
		u8	soundD : 1;
		u8	soundE : 1;
		u8	dummy  : 3;

	}
	R_4015;


	u8 R_4016to3F[0x3f-0x16+1];


	u8 R_4040[64];

	struct
	{
		u8	envgain : 6;
		u8	envsign : 1;
		u8	envflag : 1;
	}		
	R_4080;

	u8 R_4081;
	u8 R_4082;

	struct
	{
		u8	freq	  : 4;
		u8	dummy	  : 2;
		u8	testflag  : 1;
		u8	resetflag : 1;
	}		
	R_4083;

	struct
	{
		u8	envgain : 6;
		u8	envsign : 1;
		u8	envflag : 1;

	}		
	R_4084;

	u8 R_4085;
	u8 R_4086;

	struct
	{
		u8	freq	  : 4;
		u8	dummy	  : 2;
		u8	testflag  : 1;
		u8	writeflag : 1;
	}		
	R_4087;

	u8 R_4088;

	struct
	{
		u8	gain	  : 2;
		u8	dummy	  : 5;
		u8	writeflag : 1;

	}		
	R_4089;

	u8 R_408A;

	u8 R_408BtoBF[0xbf-0x8b+1];
	u8 R_40C0toD4[0xd4-0xc0+1];

	struct
	{
		u8	soundX : 1;
		u8	soundY : 1;
		u8	soundZ : 1;
		u8	dummy  : 5;

	}
	R_40D5;

	u8 R_40D6toFF[0xff-0xd6+1];
}Sound_register;

typedef union
{
	Sound_register sr;
	u8	           buf[0xff];
} Sound_buffer_;
