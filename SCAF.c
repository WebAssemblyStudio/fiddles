/* SCAF.F -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    real zhtq[20], xttq[500], yqtq[500], zhtqi[20], xttqi[500], yqtqi[500], 
	    zhtqm[35], xttqm[500], yqtqm[500], zhtqmi[35], xttqmi[500], 
	    yqtqmi[500], zhit[20], xtit[500], ytit[500], zhiti[20], xtiti[500]
	    , ytiti[500], zhtqg[20], xttqg[500], yqtqg[500], zhtqgi[20], 
	    xttqgi[500], yqtqgi[500];
    integer np, grtq, nztq, ntq[20], grtqi, nztqi, ntqi[20], grtqm, nztqm, 
	    ntqm[35], grtqmi, nztqmi, ntqmi[35], grit, nzit, nit[20], griti, 
	    nziti, niti[20], grtqg, nztqg, ntqg[20], grtqgi, nztqgi, ntqgi[20]
	    ;
    real zhfft[20], xtfft[500], yfft[500], zffti[16], xffti[250], yffti[250];
    integer grfft, nzfft, nfft[20], grffti, nzffti, nffti[16];
} dagen1_;

#define dagen1_1 dagen1_

struct {
    real fcal[5], zwcal[50]	/* was [10][5] */, xscal[2500]	/* was [500][
	    5] */, yscal[2500]	/* was [500][5] */;
    integer nfcal, grcal[10], nzcal[10], ncal[50]	/* was [10][5] */;
} dagen2_;

#define dagen2_1 dagen2_

struct {
    integer ndf[2], df[4]	/* was [2][2] */;
    real limalt[6]	/* was [2][3] */, limoat[6]	/* was [2][3] */, 
	    limoatg[2], limoati[6]	/* was [2][3] */, limwin[4]	/* 
	    was [2][2] */, limwing[2], limslp[4]	/* was [2][2] */, 
	    limdi[6]	/* was [2][3] */, limw[6]	/* was [2][3] */, 
	    vrfi[20], vrcr[40]	/* was [20][2] */, vrcrp[40]	/* was [20][2]
	     */, vrfip[20], vrcru[20]	/* was [10][2] */;
    integer grcbr[2], ncbr[2];
    real xcbr[20]	/* was [10][2] */, ymcbr[10];
    integer segm[2];
    real ydcbr[10];
    integer verd[4], ndff;
    real dff[8], limdff[8], apdff[8], gadff[8], segdff[8], madff[8], limlg, 
	    limty, limene[3], xvcrdf1[10], yfcrdf1[10], xvcrdf2[10], yfcrdf2[
	    10];
    integer limdfk[2], iopk, grcrdf1, ncrdf1, grcrdf2, ncrdf2;
    real xhlpr[10], yhlpr[10];
    integer grlpr, nlpr;
    real limv2vs[2], zfcrw1[5], xvcrw1[50], yscrw1[50], zfcrw2[5], xvcrw2[50],
	     yscrw2[50];
    integer grcrw1, nzcrw1, ncrw1[5], grcrw2, nzcrw2, ncrw2[5];
    real zfcw[2], xscw[20], yvcw[20];
    integer grcw, nzcw, ncw[2];
} dagen3_;

#define dagen3_1 dagen3_

struct {
    char afm[6], afm_dat__[6], afm_far__[6], afm_mil__[6], afm_tac__[6], 
	    afm_lfar__[6], afm_lmil__[6], afm_ltac__[6], afm_ms__[6], 
	    afm_taf__[6];
} afm_;

#define afm_1 afm_

struct inm1_1_ {
    integer sii[25]	/* was [5][5] */, gii[30]	/* was [5][6] */, fii[
	    1200]	/* was [20][60] */, nsec, ngrp, rsec, walt, nfas, fl[
	    68]	/* was [17][4] */;
    real sir[100]	/* was [20][5] */, gir[30]	/* was [5][6] */, fir[
	    2100]	/* was [35][60] */, oew, stores, mzfw, mtow, mrw, 
	    mfuel, crpor, crtim, rcmin, rdcab, mhcab, mhac, rsvp, rsvf, timp, 
	    ifuel;
};

#define inm1_1 (*(struct inm1_1_ *) &inm1_)

struct {
    integer voi[6], foi[360]	/* was [6][60] */, ierr, ind[180], necu, cont,
	     sec_mlw__, sec_pl__, grp_f__, nhpb[3], fase_hpb__[3], ihp[3], 
	    grp_c__[60];
    real vor[20], sor[50]	/* was [10][5] */, gor[18]	/* was [3][6] 
	    */, for__[3600]	/* was [60][60] */, cole[180], coli[180], hpb[
	    300]	/* was [100][3] */, hpsel[3];
} inm2_;

#define inm2_1 inm2_

struct {
    integer ley, iopfl, system[5], npin, credit, intcru;
    real peso_0__, fuel_0__, rcmin, rdcab, mhcab, fff, dind, dind1, mhac, isa,
	     wind, hpi, hpf, dis[5];
} inj1_;

#define inj1_1 inj1_

struct {
    integer npinv, ialt, nmot;
    real fuel, time, dist, ffl, alc, peso_i__, peso_f__, tech, hpc, vcas, 
	    vini, vfin, veas, vtas, vgmd, rcfi, tqin, tqfi, rev, fu[5], ti[5],
	     di[5], x[15];
} inj2_;

#define inj2_1 inj2_

struct {
    real zsfu[1800]	/* was [150][12] */, xsfu[48000]	/* was [4000][
	    12] */, ysfu[48000]	/* was [4000][12] */, zsti[1800]	/* 
	    was [150][12] */, xsti[48000]	/* was [4000][12] */, ysti[
	    48000]	/* was [4000][12] */, zsdi[1800]	/* was [150][
	    12] */, xsdi[48000]	/* was [4000][12] */, ysdi[48000]	/* 
	    was [4000][12] */;
    integer sley, scod[9], sinop[9], nsisa[9];
    real sisa[108]	/* was [9][12] */;
    integer npmsfu[108]	/* was [9][12] */, grsfu[108]	/* was [9][12] */, 
	    nzsfu[108]	/* was [9][12] */, nsfu[1800]	/* was [150][12] */, 
	    npmsti[108]	/* was [9][12] */, grsti[108]	/* was [9][12] */, 
	    nzsti[108]	/* was [9][12] */, nsti[1800]	/* was [150][12] */, 
	    npmsdi[108]	/* was [9][12] */, grsdi[108]	/* was [9][12] */, 
	    nzsdi[108]	/* was [9][12] */, nsdi[1800]	/* was [150][12] */;
} dams1_;

#define dams1_1 dams1_

struct {
    real zwsv[225]	/* was [15][15] */, xssv[750]	/* was [50][15] */, 
	    yhsv[750]	/* was [50][15] */, spc[300]	/* was [5][5][12] */, 
	    zsc[600]	/* was [5][10][12] */, xsc[6000]	/* was [50][
	    10][12] */, ysc[6000]	/* was [50][10][12] */;
    integer npmsdv[12];
    real zrsdv[72]	/* was [6][12] */, xwsdv[240]	/* was [20][12] */, 
	    yssdv[240]	/* was [20][12] */, zhtqs[420]	/* was [35][12] */, 
	    xttqs[7200]	/* was [600][12] */, yqtqs[7200]	/* was [600][
	    12] */;
    integer npmsv[12], grsv[12], nzsv[15], nsv[150]	/* was [10][15] */, 
	    indtqs[12], npmsc[120]	/* was [10][12] */, grsc[120]	/* 
	    was [10][12] */, nzsc[120]	/* was [10][12] */, nsc[600]	/* 
	    was [5][10][12] */, grsdv[12], nzsdv[12], nsdv[72]	/* was [6][12]
	     */, ntbtqs, npmtqs[12], grtqs[12], nztqs[12], ntqs[420]	/* 
	    was [35][12] */;
} dams2_;

#define dams2_1 dams2_

struct {
    real zrcm1[35], xrcm1[500], yrcm1[500], zrcm2[10], xrcm2[500], yrcm2[500],
	     zrcmc[225]	/* was [15][15] */, xrcmc[2250]	/* was [150][15] */, 
	    yrcmc[2250]	/* was [150][15] */, rccln[3], zcln[27]	/* was [9][3] 
	    */, xcln[1500]	/* was [500][3] */, ycln[1500]	/* was [500][
	    3] */, zclnc[675]	/* was [15][15][3] */, xclnc[6750]	/* 
	    was [150][15][3] */, yclnc[6750]	/* was [150][15][3] */, xtdh[
	    27]	/* was [9][3] */, yhdh[27]	/* was [9][3] */;
    integer indrc, npmrcm1, grrcm1, nzrcm1, nrcm1[35], npmrcm2, grrcm2, 
	    nzrcm2, nrcm2[10], prcmc[15], npmrcmc[15], grrcmc[15], nzrcmc[15],
	     nrcmc[225]	/* was [15][15] */, nrc, npmcln[3], grcln[3], nzcln[3]
	    , ncln[27]	/* was [9][3] */, pclnc[45]	/* was [15][3] */, 
	    npmclnc[45]	/* was [15][3] */, grclnc[45]	/* was [15][3] */, 
	    nzclnc[45]	/* was [15][3] */, nclnc[675]	/* was [15][15][3] */,
	     grdh[3], ndh[3];
} dams3_;

#define dams3_1 dams3_

struct {
    real zrcmf1[35], xrcmf1[500], yrcmf1[500], zrcmf2[10], xrcmf2[500], 
	    yrcmf2[500], zrcmfc[225]	/* was [15][15] */, xrcmfc[2250]	
	    /* was [150][15] */, yrcmfc[2250]	/* was [150][15] */, rcclnf[3]
	    , zclnf[27]	/* was [9][3] */, xclnf[1500]	/* was [500][3] */, 
	    yclnf[1500]	/* was [500][3] */, zclnfc[675]	/* was [15][15][3] */,
	     xclnfc[6750]	/* was [150][15][3] */, yclnfc[6750]	/* 
	    was [150][15][3] */, xtdhf[27]	/* was [9][3] */, yhdhf[27]	
	    /* was [9][3] */;
    integer indrcf, npmrcmf1, grrcmf1, nzrcmf1, nrcmf1[35], npmrcmf2, grrcmf2,
	     nzrcmf2, nrcmf2[10], prcmfc[15], npmrcmfc[15], grrcmfc[15], 
	    nzrcmfc[15], nrcmfc[225]	/* was [15][15] */, nrcf, npmclnf[3], 
	    grclnf[3], nzclnf[3], nclnf[27]	/* was [9][3] */, pclnfc[45]	
	    /* was [15][3] */, npmclnfc[45]	/* was [15][3] */, grclnfc[45]
	    	/* was [15][3] */, nzclnfc[45]	/* was [15][3] */, nclnfc[675]
	    	/* was [15][15][3] */, grdhf[3], ndhf[3];
} dams4_;

#define dams4_1 dams4_

struct {
    real zcff[1800]	/* was [150][12] */, xcff[48000]	/* was [4000][
	    12] */, ycff[48000]	/* was [4000][12] */, zcve[1800]	/* 
	    was [150][12] */, xcve[48000]	/* was [4000][12] */, ycve[
	    48000]	/* was [4000][12] */;
    integer cley, cinop[9], ncisa[9];
    real cisa[108]	/* was [9][12] */;
    integer npmcff[108]	/* was [9][12] */, grcff[108]	/* was [9][12] */, 
	    nzcff[108]	/* was [9][12] */, ncff[1800]	/* was [150][12] */, 
	    npmcve[108]	/* was [9][12] */, grcve[108]	/* was [9][12] */, 
	    nzcve[108]	/* was [9][12] */, ncve[1800]	/* was [150][12] */;
} dams5_;

#define dams5_1 dams5_

struct {
    real zctq[1800]	/* was [150][12] */, xctq[48000]	/* was [4000][
	    12] */, yctq[48000]	/* was [4000][12] */, ztnp[108]	/* was [9][12]
	     */, xhnp[720]	/* was [60][12] */, ynp[720]	/* was [60][
	    12] */, cpc[240]	/* was [5][4][12] */, zcc[600]	/* was [5][10]
	    [12] */, xcc[6000]	/* was [50][10][12] */, ycc[6000]	/* 
	    was [50][10][12] */;
    integer npmctq[108]	/* was [9][12] */, grctq[108]	/* was [9][12] */, 
	    nzctq[108]	/* was [9][12] */, nctq[1800]	/* was [150][12] */, 
	    npmnp[9], grnp[9], nznp[9], nnp[81]	/* was [9][9] */, npmcc[120]	
	    /* was [10][12] */, grcc[120]	/* was [10][12] */, nzcc[120]	
	    /* was [10][12] */, ncc[600]	/* was [5][10][12] */;
} dams6_;

#define dams6_1 dams6_

struct {
    real zdfu[600]	/* was [50][12] */, xdfu[18000]	/* was [1500][12] */, 
	    ydfu[18000]	/* was [1500][12] */, zdti[600]	/* was [50][12] */, 
	    xdti[18000]	/* was [1500][12] */, ydti[18000]	/* was [1500][
	    12] */, zddi[600]	/* was [50][12] */, xddi[18000]	/* was [1500][
	    12] */, yddi[18000]	/* was [1500][12] */, xsdv[600]	/* was [50][
	    12] */, yhdv[600]	/* was [50][12] */, dpc[240]	/* was [5][4][
	    12] */, zdc[1080]	/* was [9][10][12] */, xdc[3600]	/* 
	    was [30][10][12] */, ydc[3600]	/* was [30][10][12] */;
    integer dley, dinop[12], ndisa[12];
    real disa[108]	/* was [9][12] */;
    integer npmdfu[108]	/* was [9][12] */, grdfu[108]	/* was [9][12] */, 
	    nzdfu[108]	/* was [9][12] */, ndfu[600]	/* was [50][12] */, 
	    npmdti[108]	/* was [9][12] */, grdti[108]	/* was [9][12] */, 
	    nzdti[108]	/* was [9][12] */, ndti[600]	/* was [50][12] */, 
	    npmddi[108]	/* was [9][12] */, grddi[108]	/* was [9][12] */, 
	    nzddi[108]	/* was [9][12] */, nddi[600]	/* was [50][12] */, 
	    grdv[12], ndv[35], npmdc[120]	/* was [10][12] */, grdc[120]	
	    /* was [10][12] */, nzdc[120]	/* was [10][12] */, ndc[1080]	
	    /* was [9][10][12] */;
} dams7_;

#define dams7_1 dams7_

struct {
    real fuel_f__[5], time_0__[5], time_h__[5], dist_0__[5], dist_h__[5];
} dams8_;

#define dams8_1 dams8_

/* Initialized data */

struct {
    integer fill_1[1260];
    integer e_2[68];
    integer fill_3[2246];
    } inm1_ = { {0}, 30, 50, 70, 90, 110, 130, 150, 170, 190, 210, 230, 250, 
	    270, 290, 330, 370, 410, 40, 60, 80, 100, 120, 140, 160, 180, 200,
	     220, 240, 260, 280, 310, 350, 390, 430, 35, 55, 75, 95, 115, 135,
	     155, 175, 195, 215, 235, 255, 275, 300, 340, 380, 420, 45, 65, 
	    85, 105, 125, 145, 165, 185, 205, 225, 245, 265, 285, 320, 360, 
	    400, 440 };


/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__150 = 150;
static integer c__15 = 15;
static integer c__2 = 2;

/* Subroutine */ int inim_(integer *vii, real *vir, integer *ssii, real *ssir,
	 integer *ggii, real *ggir, integer *ffii, real *ffir, integer *vvoi, 
	real *vvor, real *ssor, real *ggor, integer *ffoi, real *ffor, 
	integer *iierr)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    static integer i__, j, k, ij;
    static real vl1;
    static integer nec, dece, icla, unid;
    static real hmin, hmax;
    static integer equiv;

    /* Parameter adjustments */
    ffor -= 61;
    ffoi -= 7;
    ggor -= 4;
    ssor -= 11;
    --vvor;
    --vvoi;
    ffir -= 36;
    ffii -= 21;
    ggir -= 6;
    ggii -= 6;
    ssir -= 21;
    ssii -= 6;
    --vir;
    --vii;

    /* Function Body */
    for (i__ = 1; i__ <= 6; ++i__) {
	inm2_1.voi[i__ - 1] = 0;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	inm2_1.vor[i__ - 1] = 0.f;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	for (j = 1; j <= 5; ++j) {
	    inm2_1.sor[i__ + j * 10 - 11] = 0.f;
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 6; ++j) {
	    inm2_1.gor[i__ + j * 3 - 4] = 0.f;
	}
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	for (j = 1; j <= 60; ++j) {
	    inm2_1.foi[i__ + j * 6 - 7] = 0;
	}
    }
    for (i__ = 1; i__ <= 60; ++i__) {
	for (j = 1; j <= 60; ++j) {
	    inm2_1.for__[i__ + j * 60 - 61] = 0.f;
	}
    }
    inm2_1.ierr = 0;
    if (inm2_1.cont == 0) {
	inm1_1.nsec = vii[1];
	inm1_1.ngrp = vii[2];
	inm1_1.rsec = vii[3];
	inm1_1.walt = vii[5];
	inm1_1.nfas = 0;
	i__1 = inm1_1.nsec;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    inm1_1.nfas += ssii[i__ * 5 + 1];
	}
	inm1_1.oew = vir[1];
	inm1_1.stores = vir[2];
	inm1_1.mzfw = vir[5];
	inm1_1.mtow = vir[6];
	inm1_1.mrw = vir[7];
	inm1_1.mfuel = vir[8];
	inm1_1.crpor = vir[12];
	inm1_1.crtim = vir[13];
	inm1_1.rcmin = vir[17];
	inm1_1.rdcab = vir[18];
	inm1_1.mhcab = vir[19];
	inm1_1.mhac = vir[20];
	inm1_1.rsvp = vir[22];
	inm1_1.rsvf = vir[23];
	inm1_1.timp = vir[25];
	i__1 = inm1_1.nsec;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 5; ++j) {
		inm1_1.sii[j + i__ * 5 - 6] = ssii[j + i__ * 5];
	    }
	    for (j = 1; j <= 20; ++j) {
		inm1_1.sir[j + i__ * 20 - 21] = ssir[j + i__ * 20];
	    }
	}
	i__1 = inm1_1.ngrp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 5; ++j) {
		inm1_1.gii[j + i__ * 5 - 6] = ggii[j + i__ * 5];
		inm1_1.gir[j + i__ * 5 - 6] = ggir[j + i__ * 5];
	    }
	}
	for (i__ = 1; i__ <= 60; ++i__) {
	    for (j = 1; j <= 20; ++j) {
		inm1_1.fii[j + i__ * 20 - 21] = ffii[j + i__ * 20];
	    }
	    for (j = 1; j <= 35; ++j) {
		inm1_1.fir[j + i__ * 35 - 36] = ffir[j + i__ * 35];
	    }
	}
	for (i__ = 1; i__ <= 6; ++i__) {
	    vvoi[i__] = 0;
	}
	for (i__ = 1; i__ <= 20; ++i__) {
	    vvor[i__] = 0.f;
	}
	for (i__ = 1; i__ <= 10; ++i__) {
	    for (j = 1; j <= 5; ++j) {
		ssor[i__ + j * 10] = 0.f;
	    }
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    for (j = 1; j <= 6; ++j) {
		ggor[i__ + j * 3] = 0.f;
	    }
	}
	for (i__ = 1; i__ <= 6; ++i__) {
	    for (j = 1; j <= 60; ++j) {
		ffoi[i__ + j * 6] = 0;
	    }
	}
	for (i__ = 1; i__ <= 60; ++i__) {
	    for (j = 1; j <= 60; ++j) {
		ffor[i__ + j * 60] = 0.f;
	    }
	}
	*iierr = 0;
	if (inm1_1.nsec < 1 || inm1_1.nsec > 5) {
	    inm2_1.ierr = 2110;
	    return 0;
	}
	if (inm1_1.ngrp < 1 || inm1_1.ngrp > 6) {
	    inm2_1.ierr = 2112;
	    return 0;
	}
	if (inm1_1.nsec == 1 && inm1_1.rsec == 1) {
	    inm2_1.ierr = 2110;
	    return 0;
	}
	if (inm1_1.nfas < 1 || inm1_1.nfas > 60) {
	    inm2_1.ierr = 2114;
	    return 0;
	}
	i__1 = inm1_1.ngrp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 2; ++j) {
		if (inm1_1.gii[j + i__ * 5 - 6] < 0 || inm1_1.gii[j + i__ * 5 
			- 6] > inm1_1.nfas) {
		    inm2_1.ierr = 2112;
		    return 0;
		}
	    }
	    if (inm1_1.gii[i__ * 5 - 5] > inm1_1.gii[i__ * 5 - 4]) {
		inm2_1.ierr = 2112;
		return 0;
	    }
	}
	inm2_1.grp_f__ = 0;
	i__1 = inm1_1.ngrp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inm1_1.gii[i__ * 5 - 5] == 1 && inm1_1.gii[i__ * 5 - 4] == 
		    inm1_1.nfas && inm1_1.gir[i__ * 5 - 5] > 0.f) {
		inm2_1.grp_f__ = i__;
	    }
	}
	if (inm1_1.sii[1] >= 2 && inm2_1.grp_f__ == 0) {
	    inm2_1.ierr = 2522;
	    return 0;
	}
	i__1 = inm1_1.nfas;
	for (k = 1; k <= i__1; ++k) {
	    inm2_1.grp_c__[k - 1] = 0;
	    if (inm1_1.fii[k * 20 - 20] == 41 && (inm1_1.fir[k * 35 - 35] > 
		    0.f || inm1_1.fir[k * 35 - 34] > 0.f || inm1_1.fir[k * 35 
		    - 33] > 0.f) || inm1_1.fii[k * 20 - 20] == 42 && 
		    inm1_1.fir[k * 35 - 34] > 0.f) {
		inm2_1.grp_c__[k - 1] = 1;
	    }
	}
	i__1 = inm1_1.ngrp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    icla = 0;
	    i__2 = inm1_1.gii[i__ * 5 - 4];
	    for (k = inm1_1.gii[i__ * 5 - 5]; k <= i__2; ++k) {
		if (inm2_1.grp_c__[k - 1] == 0 && (inm1_1.fii[k * 20 - 20] == 
			41 || inm1_1.fii[k * 20 - 20] == 42)) {
		    ++icla;
		    if (inm1_1.gii[i__ * 5 - 5] == inm1_1.gii[i__ * 5 - 4]) {
			inm2_1.grp_c__[k - 1] = i__ + 100;
		    }
		}
	    }
	    if (icla <= 0) {
		inm2_1.ierr = 2112;
		return 0;
	    }
	}
	if (inm1_1.oew <= 0.f) {
	    inm2_1.ierr = 2130;
	    return 0;
	}
	if (inm1_1.mzfw <= 0.f) {
	    inm2_1.ierr = 2132;
	    return 0;
	}
	if (inm1_1.mzfw <= inm1_1.oew) {
	    inm2_1.ierr = 2132;
	    return 0;
	}
	if (inm1_1.mtow <= 0.f) {
	    inm2_1.ierr = 2134;
	    return 0;
	}
	if (inm1_1.mtow <= inm1_1.oew) {
	    inm2_1.ierr = 2134;
	    return 0;
	}
	if (inm1_1.mfuel <= 0.f) {
	    inm2_1.ierr = 2136;
	    return 0;
	}
	if (inm1_1.rcmin < 50.f || inm1_1.rcmin > 400.f) {
	    inm2_1.ierr = 2190;
	    return 0;
	}
	if (inm1_1.rdcab < 0.f || inm1_1.rdcab > 2e3f || inm1_1.rdcab > 0.f &&
		 inm1_1.rdcab < 150.f) {
	    inm2_1.ierr = 2192;
	    return 0;
	}
	i__1 = inm1_1.nfas;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inm1_1.fii[i__ * 20 - 18] > 0 && inm1_1.fii[i__ * 20 - 20] > 
		    40 && inm1_1.fir[i__ * 35 - 21] >= 0.f && inm1_1.fir[i__ *
		     35 - 20] >= 0.f && inm1_1.fir[i__ * 35 - 21] > 
		    inm1_1.fir[i__ * 35 - 20]) {
		inm2_1.ierr = 2125;
		return 0;
	    }
	}
	i__1 = inm1_1.nsec;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inm1_1.sii[i__ * 5 - 5] < 1) {
		inm2_1.ierr = 2116;
		return 0;
	    }
	}
	inm2_1.necu = inm1_1.nfas * 3;
	if (inm2_1.necu > 180) {
	    inm2_1.ierr = 2117;
	    return 0;
	}
	i__1 = inm1_1.nfas;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    r__1 = inm1_1.fii[i__ * 20 - 20] / 10.f;
	    dece = i_nint(&r__1);
	    r__1 = (inm1_1.fii[i__ * 20 - 20] / 10.f - (real) dece) * 10.f;
	    unid = i_nint(&r__1);
	    if (dece < 0 || dece > 4 || unid < 1 || unid > 2) {
		inm2_1.ierr = 2524;
		return 0;
	    }
	    if (inm1_1.fii[i__ * 20 - 20] == 22) {
		inm2_1.ierr = 2524;
		return 0;
	    }
	}
	unid = 0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    inm2_1.nhpb[i__ - 1] = 1;
	    inm2_1.fase_hpb__[i__ - 1] = 0;
	}
	i__1 = inm1_1.nfas;
	for (k = 1; k <= i__1; ++k) {
	    if (inm1_1.fii[k * 20 - 20] > 40 && inm1_1.fii[k * 20 - 18] > 0) {
		++unid;
		if (unid > 3) {
		    inm2_1.ierr = 2118;
		    return 0;
		}
		if (inm1_1.fii[k * 20 - 17] < -1 || inm1_1.fii[k * 20 - 17] > 
			4) {
		    inm2_1.ierr = 2125;
		    return 0;
		}
		if (unid > 1 && inm1_1.fii[k * 20 - 18] != inm1_1.fii[
			inm2_1.fase_hpb__[unid - 2] * 20 - 18]) {
		    inm2_1.ierr = 2122;
		    return 0;
		}
		if (inm1_1.fii[k * 20 - 20] == 41 && (inm1_1.fii[(k - 1) * 20 
			- 20] != 31 || inm1_1.fii[(k + 1) * 20 - 20] != 32)) {
		    inm2_1.ierr = 2124;
		    return 0;
		}
		if (inm1_1.fii[k * 20 - 20] == 42 && inm1_1.fii[k * 20 - 18] 
			!= 1) {
		    inm2_1.ierr = 2126;
		    return 0;
		}
		hmin = inm1_1.fir[k * 35 - 21];
		hmax = inm1_1.fir[k * 35 - 20];
		if (hmin < 0.f) {
		    hmin = 0.f;
		}
		if (hmax <= 0.f) {
		    hmax = inm1_1.mhac;
		}
		if (k > 1 && inm1_1.fii[(k - 1) * 20 - 20] == 31) {
		    if (hmin < inm1_1.fir[(k - 1) * 35 - 15]) {
			hmin = inm1_1.fir[(k - 1) * 35 - 15];
		    }
		    inm1_1.fir[(k - 1) * 35 - 14] = hmax;
		}
		if (k < inm1_1.nfas && inm1_1.fii[(k + 1) * 20 - 20] == 32) {
		    if (hmin < inm1_1.fir[(k + 1) * 35 - 14]) {
			hmin = inm1_1.fir[(k + 1) * 35 - 14];
		    }
		    inm1_1.fir[(k + 1) * 35 - 15] = hmax;
		}
		inm1_1.fir[k * 35 - 15] = hmax;
		inm2_1.nhpb[unid - 1] = 0;
		inm2_1.fase_hpb__[unid - 1] = k;
		if (inm1_1.fii[k * 20 - 17] == -1) {
		    for (i__ = 1; i__ <= 89; ++i__) {
			vl1 = (real) (i__ - 1) * 500.f;
			if (vl1 >= hmin && vl1 <= hmax) {
			    ++inm2_1.nhpb[unid - 1];
			    inm2_1.hpb[inm2_1.nhpb[unid - 1] + unid * 100 - 
				    101] = vl1;
			}
		    }
		} else if (inm1_1.fii[k * 20 - 17] == 0) {
		    for (i__ = 1; i__ <= 45; ++i__) {
			vl1 = (real) (i__ - 1) * 1e3f;
			if (vl1 >= hmin && vl1 <= hmax) {
			    ++inm2_1.nhpb[unid - 1];
			    inm2_1.hpb[inm2_1.nhpb[unid - 1] + unid * 100 - 
				    101] = vl1;
			}
		    }
		} else {
		    for (i__ = 1; i__ <= 17; ++i__) {
			vl1 = (real) inm1_1.fl[i__ + inm1_1.fii[k * 20 - 17] *
				 17 - 18] * 100.f;
			if (vl1 >= hmin && vl1 <= hmax) {
			    ++inm2_1.nhpb[unid - 1];
			    inm2_1.hpb[inm2_1.nhpb[unid - 1] + unid * 100 - 
				    101] = vl1;
			}
		    }
		}
	    }
	}
    }
    for (i__ = 1; i__ <= 180; ++i__) {
	inm2_1.cole[i__ - 1] = 0.f;
	inm2_1.coli[i__ - 1] = 0.f;
	inm2_1.ind[i__ - 1] = 0;
    }
    ij = 0;
    nec = 0;
    i__1 = inm1_1.nfas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	icla = 0;
	for (k = 1; k <= 3; ++k) {
	    ++ij;
	    if (inm1_1.fir[k + i__ * 35 - 36] < 0.f) {
		inm1_1.fir[k + i__ * 35 - 36] = 0.f;
	    }
	    if (inm1_1.fii[i__ * 20 - 20] != 41 && inm1_1.fii[i__ * 20 - 20] 
		    != 42) {
		inm2_1.cole[ij - 1] = inm1_1.fir[k + i__ * 35 - 36];
		if (k == 2) {
		    ++nec;
		    inm2_1.ind[nec - 1] = 2;
		}
	    } else if (inm1_1.fir[k + i__ * 35 - 36] > .001f && icla > 0) {
		inm2_1.ierr = 2101;
		return 0;
	    } else if (inm1_1.fir[k + i__ * 35 - 36] > .001f) {
		icla = 1;
		++nec;
		inm2_1.ind[nec - 1] = k;
		inm2_1.coli[nec - 1] = inm1_1.fir[k + i__ * 35 - 36];
		inm2_1.cole[ij - 1] = inm1_1.fir[k + i__ * 35 - 36];
	    } else {
		inm2_1.cole[ij - 1] = 100.f;
	    }
	}
	nec += 2;
    }
    equiv = 0;
    icla = 0;
    i__1 = inm1_1.ngrp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (k = 1; k <= 3; ++k) {
	    if (inm1_1.gir[k + i__ * 5 - 6] > .001f) {
		++nec;
		inm2_1.coli[nec - 1] = inm1_1.gir[k + i__ * 5 - 6];
		inm2_1.ind[nec - 1] = k + 100;
		if (k == 1 && inm1_1.gii[i__ * 5 - 5] == 1 && inm1_1.gii[i__ *
			 5 - 4] == inm1_1.nfas) {
		    inm2_1.vor[9] = dabs(inm1_1.rsvp) * inm1_1.gir[k + i__ * 
			    5 - 6] / 100.f;
		}
	    } else if (inm1_1.gir[k + i__ * 5 - 6] < -.001f) {
		++icla;
		if (icla == 1) {
		    ++nec;
		    inm2_1.ind[nec - 1] = k + 200;
		    equiv = nec;
		} else if (icla == 2 && k != inm2_1.ind[equiv - 1] - 200) {
		    inm2_1.ierr = 2520;
		    return 0;
		}
	    }
	}
    }
    if (icla == 1 || icla >= 3) {
	inm2_1.ierr = 2520;
	return 0;
    }
    if (nec > ij) {
	inm2_1.ierr = 2250;
    }
    if (nec < ij) {
	inm2_1.ierr = 2252;
    }
    return 0;
} /* inim_ */

/* Subroutine */ int mtxeq_(real *b, integer *nfilas1, integer *n, integer *k,
	 real *c__, integer *nfilas, integer *ier)
{
    /* Initialized data */

    static integer nmax = 200;
    static integer nkmax = 202;

    /* System generated locals */
    integer b_dim1, b_offset, c_dim1, c_offset, i__1, i__2;
    real r__1;

    /* Local variables */
    static integer i__, j, l, kp, np;
    static real rm;
    static integer ip1, np1, npj, npk, ito;
    static real piv[202], atpe;
    static integer ipiv, ifrom;

    /* Parameter adjustments */
    b_dim1 = *nfilas1;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    c_dim1 = *nfilas;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;

    /* Function Body */
    *ier = 0;
    np = *n;
    kp = *k;
    if (np <= 0 || np > nmax || kp <= 0 || np + kp > nkmax) {
	*ier = 1;
	return 0;
    }
    i__1 = kp;
    for (j = 1; j <= i__1; ++j) {
	npj = np + j;
	i__2 = np;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L20: */
	    c__[i__ + npj * c_dim1] = b[i__ + j * b_dim1];
	}
    }
    np1 = np + 1;
    npk = np + kp;
    i__2 = np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	ip1 = i__ + 1;
	atpe = 0.f;
	i__1 = np;
	for (j = i__; j <= i__1; ++j) {
	    if ((r__1 = c__[j + i__ * c_dim1], dabs(r__1)) - atpe >= 0.f) {
		goto L30;
	    } else {
		goto L40;
	    }
L30:
	    atpe = (r__1 = c__[j + i__ * c_dim1], dabs(r__1));
	    ipiv = j;
L40:
	    ;
	}
	if (atpe <= 0.f) {
	    goto L210;
	} else {
	    goto L50;
	}
L50:
	i__1 = npk;
	for (j = ip1; j <= i__1; ++j) {
/* L60: */
	    piv[j - 1] = c__[ipiv + j * c_dim1] / c__[ipiv + i__ * c_dim1];
	}
	ifrom = np;
	ito = np;
L70:
	if (ifrom - ipiv != 0) {
	    goto L80;
	} else {
	    goto L100;
	}
L80:
	rm = -c__[ifrom + i__ * c_dim1];
	i__1 = npk;
	for (j = ip1; j <= i__1; ++j) {
/* L90: */
	    c__[ito + j * c_dim1] = c__[ifrom + j * c_dim1] + rm * piv[j - 1];
	}
	--ito;
L100:
	--ifrom;
	if (ifrom - i__ >= 0) {
	    goto L70;
	} else {
	    goto L110;
	}
L110:
	i__1 = npk;
	for (j = ip1; j <= i__1; ++j) {
/* L120: */
	    c__[i__ + j * c_dim1] = piv[j - 1];
	}
    }
    i__ = np;
L130:
    ip1 = i__;
    --i__;
    if (i__ <= 0) {
	goto L160;
    } else {
	goto L140;
    }
L140:
    i__1 = npk;
    for (j = np1; j <= i__1; ++j) {
	i__2 = np;
	for (l = ip1; l <= i__2; ++l) {
/* L150: */
	    c__[i__ + j * c_dim1] -= c__[i__ + l * c_dim1] * c__[l + j * 
		    c_dim1];
	}
    }
    goto L130;
L160:
    return 0;
L210:
    *ier = 2;
    return 0;
} /* mtxeq_ */

/* Subroutine */ int redalt_(integer *k, integer *ialt, real *hp, integer *
	ialti, integer *ialtf, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, kf, ki;

    /* Parameter adjustments */
    --ialtf;
    --ialti;

    /* Function Body */
    ki = 1;
    i__1 = inm1_1.nsec;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ > 1) {
	    ki += inm1_1.sii[(i__ - 1) * 5 - 5];
	}
	kf = ki + inm1_1.sii[i__ * 5 - 5] - 1;
	if (*k >= ki && *k <= kf) {
	    goto L50;
	}
	kf = 0;
    }
L50:
    if (kf < ki || kf <= 0) {
	*ier = 1;
	return 0;
    }
    if (*ialt <= 0 || *ialt > 4 || *ialt == 4 && inm1_1.fii[*k * 20 - 20] != 
	    41) {
	*ier = 2;
	return 0;
    }
    if (inm1_1.fii[*k * 20 - 20] == 41 || inm1_1.fii[*k * 20 - 20] == 42) {
	if (inm1_1.fir[*k * 35 - 15] > *hp) {
	    inm1_1.fir[*k * 35 - 15] = *hp;
	}
	ialti[*k] = *ialt;
	ialtf[*k] = *ialt;
    } else if (inm1_1.fii[*k * 20 - 20] == 31) {
	if (inm1_1.fir[*k * 35 - 14] > *hp) {
	    inm1_1.fir[*k * 35 - 14] = *hp;
	}
	ialtf[*k] = *ialt;
    } else {
	*ier = 3;
	return 0;
    }
    i__1 = kf;
    for (i__ = *k + 1; i__ <= i__1; ++i__) {
	if (ialtf[i__ - 1] == 0) {
	    goto L100;
	} else if (inm1_1.fir[i__ * 35 - 15] > *hp) {
	    if (inm1_1.fii[i__ * 20 - 20] == 41 || inm1_1.fii[i__ * 20 - 20] 
		    == 42) {
		inm1_1.fir[i__ * 35 - 15] = *hp;
		ialti[i__] = *ialt;
		ialtf[i__] = *ialt;
	    } else if (inm1_1.fii[i__ * 20 - 20] == 31) {
		inm1_1.fir[i__ * 35 - 15] = *hp;
		ialti[i__] = *ialt;
		inm1_1.fir[i__ * 35 - 14] = *hp;
		ialtf[i__] = *ialt;
	    } else if (inm1_1.fii[i__ * 20 - 20] == 32) {
		inm1_1.fir[i__ * 35 - 15] = *hp;
		ialti[i__] = *ialt;
		if (inm1_1.fir[i__ * 35 - 14] > *hp) {
		    inm1_1.fir[i__ * 35 - 14] = *hp;
		    ialtf[i__] = *ialt;
		} else {
		    ialtf[i__] = 0;
		}
	    } else {
		*ier = 3;
		return 0;
	    }
	} else {
	    ialti[i__] = 0;
	    ialtf[i__] = 0;
	}
    }
L100:
    if (*ialt == 4) {
	i__1 = ki;
	for (i__ = *k - 1; i__ >= i__1; --i__) {
	    if (ialti[i__ + 1] == 0) {
		goto L200;
	    } else if (inm1_1.fir[i__ * 35 - 14] > *hp) {
		if (inm1_1.fii[i__ * 20 - 20] == 41 || inm1_1.fii[i__ * 20 - 
			20] == 42) {
		    inm1_1.fir[i__ * 35 - 15] = *hp;
		    inm1_1.fir[i__ * 35 - 14] = *hp;
		    ialti[i__] = *ialt;
		    ialtf[i__] = *ialt;
		} else if (inm1_1.fii[i__ * 20 - 20] == 31) {
		    inm1_1.fir[i__ * 35 - 14] = *hp;
		    ialtf[i__] = *ialt;
		    if (inm1_1.fir[i__ * 35 - 15] > *hp) {
			inm1_1.fir[i__ * 35 - 15] = *hp;
			ialti[i__] = *ialt;
		    } else {
			ialti[i__] = 0;
		    }
		} else if (inm1_1.fii[i__ * 20 - 20] == 32) {
		    inm1_1.fir[i__ * 35 - 14] = *hp;
		    ialtf[i__] = *ialt;
		    ialti[i__] = 0;
		} else {
		    *ier = 3;
		    return 0;
		}
	    } else {
		ialti[i__] = 0;
		ialtf[i__] = 0;
	    }
	}
    }
L200:
    *ier = 0;
    return 0;
} /* redalt_ */

/* Subroutine */ int supint_(integer *gr, integer *nz, real *z__, integer *n, 
	real *x, real *y, integer *npm, real *h__, real *w, integer *nisa, 
	real *xisa, real *isa, real *vres, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer i__, ie, ix, iz;
    static real vr[20], ind[20];
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *);
    static real indres;

    /* Parameter adjustments */
    --xisa;
    --npm;
    --y;
    --x;
    --n;
    --z__;
    --nz;
    --gr;

    /* Function Body */
    *ierr = 0;
    ix = 1;
    iz = 1;
    i__1 = *nisa;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ > 1) {
	    ix = npm[i__ - 1] + ix;
	}
	if (i__ > 1) {
	    iz = nz[i__ - 1] + iz;
	}
	manual3r_(&c__1, &gr[i__], &x[ix], &y[ix], &z__[iz], &n[iz], &nz[i__],
		 h__, &vr[i__ - 1], w, &ie);
	if (ie == 2) {
	    *ierr = 2;
	    return 0;
	} else {
	    ind[i__ - 1] = (real) ie;
	}
    }
    if (*nisa == 1 && *isa == xisa[1]) {
	*vres = vr[0];
    } else {
	int2r_(isa, &xisa[1], vr, &c__1, nisa, vres, &ie);
	if (ie == 2) {
	    *ierr = 2;
	    return 0;
	} else {
	    int2r_(isa, &xisa[1], ind, &c__1, nisa, &indres, &ie);
	    if (indres > .75f) {
		*ierr = 1;
	    }
	}
    }
    return 0;
} /* supint_ */

/* Subroutine */ int sctec_(real *wkg, real *hpdat, real *hpres, real *rcres, 
	real *tres, real *hpcab, integer *ind, integer *ierr)
{
    /* Initialized data */

    static integer fl[68]	/* was [17][4] */ = { 30,50,70,90,110,130,150,
	    170,190,210,230,250,270,290,330,370,410,40,60,80,100,120,140,160,
	    180,200,220,240,260,280,310,350,390,430,35,55,75,95,115,135,155,
	    175,195,215,235,255,275,300,340,380,420,45,65,85,105,125,145,165,
	    185,205,225,245,265,285,320,360,400,440 };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), manual3r_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, integer *);
    static integer j;
    static real dh;
    static integer ie;
    static real wc, vr[3], vl1, vl2;
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *), int2r_(real *, real *, real *,
	     integer *, integer *, real *, integer *);

    if (inj2_1.nmot == 2) {
	i__1 = dams3_1.nrc;
	for (j = 1; j <= i__1; ++j) {
	    corr_(&ie, &c__0, wkg, &wc, inj2_1.x, &dams3_1.pclnc[j * 15 - 15],
		     &c__150, &c__15, &dams3_1.grclnc[j * 15 - 15], &
		    dams3_1.nzclnc[j * 15 - 15], &dams3_1.nclnc[(j * 15 + 1) *
		     15 - 240], &dams3_1.xclnc[(j * 15 + 1) * 150 - 2400], &
		    dams3_1.yclnc[(j * 15 + 1) * 150 - 2400], &dams3_1.zclnc[(
		    j * 15 + 1) * 15 - 240]);
	    if (ie == 2) {
		goto L1000;
	    }
	    manual3r_(&c__1, &dams3_1.grcln[j - 1], &dams3_1.xcln[j * 500 - 
		    500], &dams3_1.ycln[j * 500 - 500], &dams3_1.zcln[j * 9 - 
		    9], &dams3_1.ncln[j * 9 - 9], &dams3_1.nzcln[j - 1], &wc, 
		    &vr[j - 1], &inj1_1.isa, &ie);
	    if (ie == 2) {
		goto L1000;
	    }
	    if (inj2_1.x[2] == 1.f) {
		manual2r_(&c__1, &inj1_1.isa, dams3_1.xtdh, dams3_1.yhdh, 
			dams3_1.grdh, dams3_1.ndh, &dh, &ie);
		if (ie == 2) {
		    goto L1000;
		}
		vr[j - 1] += dh;
	    }
	}
	if (dams3_1.nrc == 1 && inj1_1.rcmin == dams3_1.rccln[0]) {
	    *tres = vr[0];
	    *ierr = 0;
	} else if (dams3_1.nrc == 1 && inj1_1.rcmin != dams3_1.rccln[0]) {
	    *ierr = 1120;
	    return 0;
	} else {
	    int2r_(&inj1_1.rcmin, dams3_1.rccln, vr, &c__1, &dams3_1.nrc, 
		    tres, &ie);
	    if (ie == 2) {
		goto L1000;
	    }
	    *ierr = ie;
	}
    } else {
	i__1 = dams4_1.nrcf;
	for (j = 1; j <= i__1; ++j) {
	    corr_(&ie, &c__0, wkg, &wc, inj2_1.x, &dams4_1.pclnfc[j * 15 - 15]
		    , &c__150, &c__15, &dams4_1.grclnfc[j * 15 - 15], &
		    dams4_1.nzclnfc[j * 15 - 15], &dams4_1.nclnfc[(j * 15 + 1)
		     * 15 - 240], &dams4_1.xclnfc[(j * 15 + 1) * 150 - 2400], 
		    &dams4_1.yclnfc[(j * 15 + 1) * 150 - 2400], &
		    dams4_1.zclnfc[(j * 15 + 1) * 15 - 240]);
	    if (ie == 2) {
		goto L1000;
	    }
	    manual3r_(&c__1, &dams4_1.grclnf[j - 1], &dams4_1.xclnf[j * 500 - 
		    500], &dams4_1.yclnf[j * 500 - 500], &dams4_1.zclnf[j * 9 
		    - 9], &dams4_1.nclnf[j * 9 - 9], &dams4_1.nzclnf[j - 1], &
		    wc, &vr[j - 1], &inj1_1.isa, &ie);
	    if (ie == 2) {
		goto L1000;
	    }
	    if (inj2_1.x[2] == 1.f) {
		manual2r_(&c__1, &inj1_1.isa, dams4_1.xtdhf, dams4_1.yhdhf, 
			dams4_1.grdhf, dams4_1.ndhf, &dh, &ie);
		if (ie == 2) {
		    goto L1000;
		}
		vr[j - 1] += dh;
	    }
	}
	if (dams4_1.nrcf == 1 && inj1_1.rcmin == dams4_1.rcclnf[0]) {
	    *tres = vr[0];
	    *ierr = 0;
	} else if (dams4_1.nrcf == 1 && inj1_1.rcmin != dams4_1.rcclnf[0]) {
	    *ierr = 1120;
	    return 0;
	} else {
	    int2r_(&inj1_1.rcmin, dams4_1.rcclnf, vr, &c__1, &dams4_1.nrcf, 
		    tres, &ie);
	    if (ie == 2) {
		goto L1000;
	    }
	    *ierr = ie;
	}
    }
    *hpcab = 999999.f;
    if (inj1_1.mhcab >= 0.f && dagen3_1.nlpr > 0) {
	manual2r_(&c__1, &inj1_1.mhcab, dagen3_1.xhlpr, dagen3_1.yhlpr, &
		dagen3_1.grlpr, &dagen3_1.nlpr, hpcab, &ie);
	if (ie == 2) {
	    goto L1000;
	}
    } else if (inj1_1.mhcab >= 0.f && dagen3_1.nlpr == 0) {
	*hpcab = inj1_1.mhcab;
    }
    *ind = 0;
    *hpres = 999999.f;
    if (*hpdat >= 0.f) {
	*hpres = *hpdat;
    }
    if (*tres < *hpres) {
	*hpres = *tres;
	*ind = 1;
    }
    if (*hpcab < *hpres) {
	*hpres = *hpcab;
	*ind = 2;
    }
    if (inj1_1.mhac < *hpres) {
	*hpres = inj1_1.mhac;
	*ind = 3;
    }
    if ((real) (*ind) > 0.f) {
	if (inj1_1.iopfl == -2) {
	    *hpres = *hpres;
	} else if (inj1_1.iopfl < 0) {
	    *hpres = (real) ((integer) (*hpres / 500.f)) * 500.f;
	} else if (inj1_1.iopfl == 0) {
	    *hpres = (real) ((integer) (*hpres / 1e3f)) * 1e3f;
	} else {
	    for (j = 17; j >= 1; --j) {
		vl1 = (real) fl[j + inj1_1.iopfl * 17 - 18] * 100.f;
		if (vl1 < *hpres) {
		    *hpres = vl1;
		    goto L100;
		}
	    }
	    *ierr = 1525;
	    return 0;
	}
    }
L100:
    if (*hpres < 0.f) {
	*ierr = 1525;
	return 0;
    }
    if (dams3_1.indrc == 1 && inj2_1.nmot == 2) {
	manual3r_(&c__1, &dams3_1.grrcm1, dams3_1.xrcm1, dams3_1.yrcm1, 
		dams3_1.zrcm1, dams3_1.nrcm1, &dams3_1.nzrcm1, &inj1_1.isa, &
		vl1, hpres, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	manual3r_(&c__1, &dams3_1.grrcm2, dams3_1.xrcm2, dams3_1.yrcm2, 
		dams3_1.zrcm2, dams3_1.nrcm2, &dams3_1.nzrcm2, wkg, &vl2, &
		vl1, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	corr_(&ie, &c__0, &vl2, rcres, inj2_1.x, dams3_1.prcmc, &c__150, &
		c__15, dams3_1.grrcmc, dams3_1.nzrcmc, dams3_1.nrcmc, 
		dams3_1.xrcmc, dams3_1.yrcmc, dams3_1.zrcmc);
	if (ie == 2) {
	    goto L1000;
	}
	if (*ind == 1 && *rcres < inj1_1.rcmin) {
	    *rcres = inj1_1.rcmin;
	}
    } else if (dams4_1.indrcf == 1 && inj2_1.nmot == 1) {
	manual3r_(&c__1, &dams4_1.grrcmf1, dams4_1.xrcmf1, dams4_1.yrcmf1, 
		dams4_1.zrcmf1, dams4_1.nrcmf1, &dams4_1.nzrcmf1, &inj1_1.isa,
		 &vl1, hpres, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	manual3r_(&c__1, &dams4_1.grrcmf2, dams4_1.xrcmf2, dams4_1.yrcmf2, 
		dams4_1.zrcmf2, dams4_1.nrcmf2, &dams4_1.nzrcmf2, wkg, &vl2, &
		vl1, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	corr_(&ie, &c__0, &vl2, rcres, inj2_1.x, dams4_1.prcmfc, &c__150, &
		c__15, dams4_1.grrcmfc, dams4_1.nzrcmfc, dams4_1.nrcmfc, 
		dams4_1.xrcmfc, dams4_1.yrcmfc, dams4_1.zrcmfc);
	if (ie == 2) {
	    goto L1000;
	}
	if (*ind == 1 && *rcres < inj1_1.rcmin) {
	    *rcres = inj1_1.rcmin;
	}
    } else {
	*rcres = -999.f;
    }
    return 0;
L1000:
    *ierr = 2;
    return 0;
} /* sctec_ */

/* Subroutine */ int bart_(real *xi, real *xf, real *x, real *y, integer *nm, 
	integer *n, real *sum, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ie;
    static real dx, yf, yi, xl, yl, ys1, ys2;
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *);

    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    ys1 = 0.f;
    ys2 = 0.f;
    *sum = 0.f;
    dx = (*xf - *xi) / 2.f / (real) (*n);
    i__1 = (*n << 1) - 1;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	xl = *xi + (real) i__ * dx;
	int2r_(&xl, &x[1], &y[1], &c__2, nm, &yl, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	ys1 += yl;
    }
    i__1 = (*n << 1) - 2;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	xl = *xi + (real) i__ * dx;
	int2r_(&xl, &x[1], &y[1], &c__2, nm, &yl, &ie);
	if (ie == 2) {
	    goto L1000;
	}
	ys2 += yl;
    }
    int2r_(xi, &x[1], &y[1], &c__2, nm, &yi, &ie);
    if (ie == 2) {
	goto L1000;
    }
    int2r_(xf, &x[1], &y[1], &c__2, nm, &yf, &ie);
    if (ie == 2) {
	goto L1000;
    }
    *sum = (yi + yf + ys1 * 4.f + ys2 * 2.f) * dx / 3.f;
    *ierr = 0;
    return 0;
L1000:
    *ierr = 2;
    return 0;
} /* bart_ */

/* Subroutine */ int inic_(integer *indi, integer *nley, integer *inop, 
	integer *vii, real *vir, integer *voi, real *vor, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static real vl[2], vli;
    static integer nvl;
    static real vls, oati, oats, temp, oat_std__;

    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    inj1_1.ley = vii[2];
    inj1_1.iopfl = vii[4];
    inj2_1.nmot = vii[6];
    inj1_1.system[0] = vii[7];
    inj1_1.system[1] = vii[8];
    inj1_1.system[2] = vii[9];
    inj1_1.system[3] = vii[10];
    inj1_1.system[4] = vii[11];
    inj1_1.npin = vii[12];
    inj1_1.credit = vii[14];
    if (inj1_1.npin > 5) {
	*ierr = 1195;
	return 0;
    }
    if (inj1_1.iopfl < -2 || inj1_1.iopfl > 4) {
	*ierr = 1125;
	return 0;
    }
    if (*indi < 6 && (inj1_1.ley <= 0 || inj1_1.ley > *nley)) {
	*ierr = 1110;
	return 0;
    }
    if (*indi == 6 && (inj2_1.nmot <= 0 || inj2_1.nmot > 2)) {
	inj2_1.nmot = 2;
    } else if (*indi != 6) {
	inj2_1.nmot = 2 - *inop;
    }
    if (inj1_1.credit < 0) {
	inj1_1.credit = 0;
    }
    if (*indi == 6 && vii[1] < 10) {
	inj1_1.credit = 0;
    }
    inj1_1.fuel_0__ = vir[1];
    inj1_1.peso_0__ = vir[4];
    inj1_1.rcmin = vir[7];
    inj1_1.rdcab = vir[8];
    inj1_1.mhcab = vir[9];
    inj1_1.fff = vir[10];
    inj1_1.dind = vir[12];
    inj1_1.dind1 = vir[13];
    inj1_1.mhac = vir[18];
    if (inj1_1.mhac <= 0.f) {
	inj1_1.mhac = dagen3_1.limalt[5];
    }
    inj1_1.isa = vir[19];
    inj1_1.wind = vir[20];
    inj1_1.hpi = vir[21];
    inj1_1.hpf = vir[22];
    i__1 = inj1_1.npin;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inj1_1.dis[i__ - 1] = vir[i__ + 30];
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	voi[i__] = 0;
	vor[i__] = 0.f;
    }
    for (i__ = 7; i__ <= 60; ++i__) {
	vor[i__] = 0.f;
    }
    for (i__ = 1; i__ <= 15; ++i__) {
	inj2_1.x[i__ - 1] = 0.f;
    }
    inj2_1.npinv = 0;
    inj2_1.ialt = 0;
    inj2_1.fuel = 0.f;
    inj2_1.time = 0.f;
    inj2_1.dist = 0.f;
    inj2_1.ffl = 0.f;
    inj2_1.alc = 0.f;
    inj2_1.peso_i__ = 0.f;
    inj2_1.peso_f__ = 0.f;
    inj2_1.tech = 0.f;
    inj2_1.hpc = 0.f;
    inj2_1.vini = 0.f;
    inj2_1.vfin = 0.f;
    inj2_1.vcas = 0.f;
    inj2_1.veas = 0.f;
    inj2_1.vtas = 0.f;
    inj2_1.vgmd = 0.f;
    inj2_1.rcfi = 0.f;
    inj2_1.tqin = 0.f;
    inj2_1.tqfi = 0.f;
    inj2_1.rev = 0.f;
    for (i__ = 1; i__ <= 5; ++i__) {
	inj2_1.fu[i__ - 1] = 0.f;
	inj2_1.ti[i__ - 1] = 0.f;
	inj2_1.di[i__ - 1] = 0.f;
    }
    *ierr = 0;
    nvl = 0;
    if (*indi == 3) {
	if (inj1_1.hpi < inj1_1.hpf) {
	    *ierr = 1140;
	} else if (inj1_1.hpi == inj1_1.hpf) {
	    *ierr = 1010;
	} else if (inj1_1.hpi > dagen3_1.limalt[5] || inj1_1.hpi > 
		inj1_1.mhac) {
	    *ierr = 1210;
	} else if (inj1_1.hpf < -1e3f) {
	    *ierr = 1140;
	}
	vl[0] = inj1_1.hpi;
	vl[1] = inj1_1.hpf;
	nvl = 2;
    }
    if (*indi == 2 || *indi == 5) {
	if (inj1_1.hpi < 0.f) {
	    *ierr = 1140;
	}
	if (inj1_1.hpi > dagen3_1.limalt[5] || inj1_1.hpi > inj1_1.mhac) {
	    *ierr = 1210;
	}
	vl[0] = inj1_1.hpi;
	nvl = 1;
    }
    if (*indi == 1) {
	if (inj1_1.hpi >= 0.f && inj1_1.hpf >= 0.f) {
	    if (inj1_1.hpi > inj1_1.hpf) {
		*ierr = 1140;
	    } else if (inj1_1.hpi == inj1_1.hpf) {
		*ierr = 1010;
	    } else if (inj1_1.hpi < -1e3f) {
		*ierr = 1140;
	    }
	    if (inj1_1.hpf > dagen3_1.limalt[5] || inj1_1.hpf > inj1_1.mhac) {
		*ierr = 1210;
	    }
	    vl[0] = inj1_1.hpi;
	    vl[1] = inj1_1.hpf;
	    nvl = 2;
	} else if (inj1_1.hpf >= 0.f) {
	    if (inj1_1.hpf > dagen3_1.limalt[5] || inj1_1.hpf > inj1_1.mhac) {
		*ierr = 1210;
	    }
	    vl[0] = inj1_1.hpf;
	    nvl = 1;
	} else if (inj1_1.hpi >= 0.f) {
	    inj1_1.hpf = inj1_1.hpi;
	    inj1_1.hpi = -1.f;
	    if (inj1_1.hpf > dagen3_1.limalt[5] || inj1_1.hpf > inj1_1.mhac) {
		*ierr = 1210;
	    }
	    vl[0] = inj1_1.hpf;
	    nvl = 1;
	}
    }
    if (*indi == 6) {
	if (inj1_1.hpi < -1e3f) {
	    *ierr = 1140;
	}
	if (inj1_1.hpi > dagen3_1.limalt[5] || inj1_1.hpi > inj1_1.mhac) {
	    *ierr = 1210;
	}
	vl[0] = inj1_1.hpi;
	nvl = 1;
	if (inj1_1.hpf < inj1_1.hpi && (vii[1] == 11 || vii[1] == 21)) {
	    *ierr = 1140;
	}
	if (inj1_1.hpf > inj1_1.hpi && vii[1] == 12) {
	    *ierr = 1140;
	}
    }
    if (*ierr >= 1100) {
	return 0;
    }
    if (inj1_1.system[1] == 0) {
	vli = dagen3_1.limoat[4];
	vls = dagen3_1.limoat[5];
    } else {
	vli = dagen3_1.limoati[4];
	vls = dagen3_1.limoati[5];
    }
    i__1 = nvl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	oat_std__ = 15.f - vl[i__ - 1] * 1.98f / 1e3f;
	temp = inj1_1.isa + oat_std__;
	if (*indi == 6) {
	    temp = inj1_1.isa;
	}
	oati = vli;
	if (vli > 500.f) {
	    oati = vli - 1e3f + oat_std__;
	}
	oats = vls;
	if (vls > 500.f) {
	    oats = vls - 1e3f + oat_std__;
	}
	if (temp < oati || temp > oats) {
	    *ierr = 1220;
	    if (inj1_1.system[1] == 1) {
		*ierr = 1230;
	    }
	    return 0;
	}
    }
/* L30: */
    if (inj1_1.dind < dagen3_1.limdi[4] || inj1_1.dind > dagen3_1.limdi[5]) {
	*ierr = 1260;
	return 0;
    }
    if (inj1_1.dind1 < dagen3_1.limdi[4] || inj1_1.dind1 > dagen3_1.limdi[5]) 
	    {
	*ierr = 1260;
	return 0;
    }
    if ((real) vii[1] == 0.f) {
	if (inj1_1.peso_0__ < dagen3_1.limw[4] || inj1_1.peso_0__ > 
		dagen3_1.limw[5]) {
	    *ierr = 1215;
	    return 0;
	}
	if (*indi == 5 && inj1_1.peso_0__ - inj1_1.fuel_0__ < dagen3_1.limw[4]
		) {
	    *ierr = 1215;
	    return 0;
	}
    } else {
	if (inj1_1.peso_0__ < dagen3_1.limw[4] * .75f || inj1_1.peso_0__ > 
		dagen3_1.limw[5] * 1.25f) {
	    *ierr = 1215;
	    return 0;
	}
	if (*indi == 5 && inj1_1.peso_0__ - inj1_1.fuel_0__ < dagen3_1.limw[4]
		 * .5f) {
	    *ierr = 1215;
	    return 0;
	}
    }
    if (*indi != 3 && *indi != 6 && (inj1_1.rcmin < 50.f || inj1_1.rcmin > 
	    400.f)) {
	*ierr = 1190;
	return 0;
    }
    if (*indi == 3 && (inj1_1.rdcab < 0.f || inj1_1.rdcab > 2e3f || 
	    inj1_1.rdcab > 0.f && inj1_1.rdcab < 150.f)) {
	*ierr = 1192;
	return 0;
    }
    if (*indi >= 5 && (real) inj1_1.npin > 0.f) {
	*ierr = 1195;
	return 0;
    }
    if (dabs(inj1_1.fff) > 20.f) {
	*ierr = 1162;
	return 0;
    }
    if (dabs(inj1_1.wind) > 200.f) {
	*ierr = 1148;
	return 0;
    }
    i__1 = inj1_1.npin - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (inj1_1.dis[i__] < inj1_1.dis[i__ - 1]) {
	    *ierr = 1196;
	    return 0;
	}
    }
    inj2_1.x[0] = inj1_1.dind;
    if (inj2_1.nmot == 1) {
	inj2_1.x[0] = inj1_1.dind1;
    }
    inj2_1.x[1] = 0.f;
    inj2_1.x[2] = (real) inj1_1.system[1];
    inj2_1.x[3] = 0.f;
    inj2_1.x[4] = 0.f;
    inj2_1.x[5] = 0.f;
    inj2_1.x[6] = 0.f;
    inj2_1.x[7] = 0.f;
    inj2_1.x[8] = 0.f;
    inj2_1.x[9] = 0.f;
    inj2_1.x[10] = (real) inj1_1.system[3];
    inj2_1.x[11] = (real) inj1_1.system[4];
    inj2_1.x[12] = 0.f;
    inj2_1.x[13] = 0.f;
    inj2_1.x[14] = 0.f;
    inj1_1.intcru = 0;
    if (*indi == 5) {
	inj1_1.intcru = 1;
    }
    return 0;
} /* inic_ */

/* Subroutine */ int escric_(integer *indi, integer *voi, real *vor, integer *
	verc, integer *verd)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --vor;
    --voi;

    /* Function Body */
    voi[1] = inj2_1.ialt;
    voi[3] = inj2_1.npinv;
    voi[4] = *verc;
    voi[5] = *verd;
    if (*indi < 6) {
	voi[6] = inj1_1.ley;
    }
    if (*indi != 2) {
	vor[1] = inj2_1.fuel;
	vor[2] = inj2_1.time;
	vor[3] = inj2_1.dist;
    } else {
	vor[1] = inj2_1.ffl;
	vor[3] = inj2_1.alc * 100.f;
    }
    vor[4] = inj2_1.peso_i__;
    vor[5] = inj2_1.peso_f__;
    vor[6] = inj2_1.tech;
    vor[7] = inj1_1.hpi;
    if (*indi == 2 || *indi == 5) {
	vor[7] = inj2_1.hpc;
    }
    vor[8] = inj2_1.hpc;
    vor[10] = inj2_1.vcas;
    vor[11] = inj2_1.vini;
    vor[12] = inj2_1.vfin;
    vor[13] = inj2_1.veas;
    vor[14] = inj2_1.vtas;
    vor[15] = inj2_1.vgmd;
    vor[17] = inj2_1.rcfi;
    vor[21] = inj2_1.tqin;
    vor[22] = inj2_1.tqfi;
    vor[23] = inj2_1.rev;
    i__1 = inj2_1.npinv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vor[i__ + 30] = inj2_1.fu[i__ - 1];
	vor[i__ + 40] = inj2_1.ti[i__ - 1];
	vor[i__ + 50] = inj1_1.dis[i__ - 1];
    }
    return 0;
} /* escric_ */

