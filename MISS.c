/* MISS.F -- translated by f2c (version 20100827).
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

struct {
    integer sii[25]	/* was [5][5] */, gii[30]	/* was [5][6] */, fii[
	    1200]	/* was [20][60] */, nsec, ngrp, rsec, walt, nfas, fl[
	    68]	/* was [17][4] */;
    real sir[100]	/* was [20][5] */, gir[30]	/* was [5][6] */, fir[
	    2100]	/* was [35][60] */, oew, stores, mzfw, mtow, mrw, 
	    mfuel, crpor, crtim, rcmin, rdcab, mhcab, mhac, rsvp, rsvf, timp, 
	    ifuel;
} inm1_;

#define inm1_1 inm1_

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

/* Table of constant values */

static real c_b5 = 0.f;
static integer c__180 = 180;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__2 = 2;
static real c_b41 = 5e3f;
static integer c__3 = 3;
static real c_b62 = -1.f;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__0 = 0;

/* MS$ATTRIBUTES ALIAS: 'MISS' :: MISS */
/* MS$ATTRIBUTES ALIAS: 'SCCLI' :: SCCLI */
/* MS$ATTRIBUTES ALIAS: 'SCCRU' :: SCCRU */
/* MS$ATTRIBUTES ALIAS: 'SCDES' :: SCDES */
/* MS$ATTRIBUTES ALIAS: 'SCCRI' :: SCCRI */
/* MS$ATTRIBUTES ALIAS: 'SCCRE' :: SCCRE */
/* Subroutine */ int miss_(char *vic, char *vid, integer *vii, real *vir, 
	integer *ssii, real *ssir, integer *ggii, real *ggir, integer *ffii, 
	real *ffir, integer *vvoi, real *vvor, real *ssor, real *ggor, 
	integer *ffoi, real *ffor, integer *iierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int lectm_(char *, integer *, ftnlen), inim_(
	    integer *, real *, integer *, real *, integer *, real *, integer *
	    , real *, integer *, real *, real *, real *, integer *, real *, 
	    integer *), zfalse_(E_fp, real *, integer *, real *, real *, real 
	    *, integer *, integer *);
    static real fuel_min__, time_min__;
    static integer i__, k, ie;
    static real vl1;
    static integer ihp1, ihp2, ihp3;
    static char vici[200];
    extern doublereal fmis_(real *);
    static integer fase_in__, cifsig, itemax;
    static real plmax, plmin, error;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen);

/* MS$ATTRIBUTES DLLEXPORT :: MISS */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
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
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, iierr, (ftnlen)200);
	if (*iierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, iierr, (ftnlen)200);
	if (*iierr > 0) {
	    return 0;
	}
    }
    inm2_1.sec_mlw__ = 0;
    inm2_1.sec_pl__ = 0;
    inm2_1.cont = 0;
    inm1_1.ifuel = 0.f;
    if (ssii[7] == 0) {
	inm1_1.ifuel = vir[9];
    }
    inim_(&vii[1], &vir[1], &ssii[6], &ssir[21], &ggii[6], &ggir[6], &ffii[21]
	    , &ffir[36], &vvoi[1], &vvor[1], &ssor[11], &ggor[4], &ffoi[7], &
	    ffor[61], iierr);
    *iierr = inm2_1.ierr;
    if (*iierr > 0) {
	return 0;
    }
L15:
    time_min__ = 999999.f;
    fuel_min__ = 999999.f;
    for (ihp1 = inm2_1.nhpb[0]; ihp1 >= 1; --ihp1) {
	inm2_1.ihp[0] = ihp1;
	for (ihp2 = inm2_1.nhpb[1]; ihp2 >= 1; --ihp2) {
	    inm2_1.ihp[1] = ihp2;
	    for (ihp3 = inm2_1.nhpb[2]; ihp3 >= 1; --ihp3) {
		inm2_1.ihp[2] = ihp3;
		for (i__ = 1; i__ <= 3; ++i__) {
		    if (inm2_1.ihp[i__ - 1] < inm2_1.nhpb[i__ - 1] && 
			    inm2_1.hpb[inm2_1.ihp[i__ - 1] + i__ * 100 - 101] 
			    >= inm2_1.for__[inm2_1.fase_hpb__[i__ - 1] * 60 - 
			    53]) {
			goto L100;
		    }
		}
		vl1 = fmis_(&c_b5);
		if (inm2_1.ierr > 0 && inm2_1.ierr < 999 || inm2_1.ierr > 
			1099) {
		    goto L1000;
		}
L25:
		inm2_1.sec_mlw__ = 0;
		fase_in__ = 1;
		i__1 = inm1_1.nsec;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    if (i__ > 1) {
			fase_in__ += inm1_1.sii[(i__ - 1) * 5 - 5];
		    }
		    i__2 = fase_in__ + inm1_1.sii[i__ * 5 - 5] - 1;
		    for (k = fase_in__; k <= i__2; ++k) {
			if (inm1_1.fii[k * 20 - 20] == 12 && inm2_1.for__[k * 
				60 - 57] > inm1_1.fir[k * 35 - 31]) {
			    inm2_1.sec_mlw__ = i__;
			    goto L50;
			}
		    }
		}
L50:
		if (inm2_1.sec_mlw__ > 0) {
		    plmax = inm2_1.sor[inm2_1.sec_mlw__ * 10 - 4];
		    plmin = 0.f;
		    error = .01f;
		    cifsig = 6;
		    itemax = 100;
		    zfalse_((E_fp)fmis_, &error, &cifsig, &plmin, &plmax, &
			    vl1, &itemax, &ie);
		    if (ie == 129) {
			*iierr = inm2_1.sec_mlw__ + 2000;
			return 0;
		    }
		    if (ie > 0) {
			*iierr = 2564;
			return 0;
		    }
		    goto L25;
		}
L75:
		if (inm2_1.sec_pl__ > 0) {
		    inm1_1.sii[inm2_1.sec_pl__ * 5 - 4] = 0;
		    plmax = inm2_1.sor[inm2_1.sec_pl__ * 10 - 4];
		    plmin = 0.f;
		    error = .2f;
		    cifsig = 5;
		    itemax = 100;
		    zfalse_((E_fp)fmis_, &error, &cifsig, &plmin, &plmax, &
			    vl1, &itemax, &ie);
		    if (ie == 129) {
			i__1 = inm1_1.nsec;
			for (i__ = 1; i__ <= i__1; ++i__) {
			    if (inm1_1.sii[i__ * 5 - 4] > 0) {
				inm2_1.sec_pl__ = i__;
				goto L75;
			    }
			}
			i__1 = inm1_1.nsec;
			for (i__ = 1; i__ <= i__1; ++i__) {
			    inm1_1.sii[i__ * 5 - 4] = 0;
			    inm1_1.sir[i__ * 20 - 20] = 0.f;
			}
			i__1 = inm1_1.nfas;
			for (i__ = 1; i__ <= i__1; ++i__) {
			    inm1_1.fir[i__ * 35 - 15] = ffir[i__ * 35 + 21];
			    inm1_1.fir[i__ * 35 - 14] = ffir[i__ * 35 + 22];
			}
			inm2_1.sec_pl__ = 0;
			vl1 = fmis_(&c_b5);
			if (inm2_1.vor[6] < inm1_1.mfuel) {
			    *iierr = 2022;
			} else {
			    *iierr = 2020;
			}
			return 0;
		    }
		    if (ie > 0 || inm2_1.vor[6] > inm1_1.mfuel) {
			*iierr = 2564;
			return 0;
		    }
		}
		if (inm2_1.fase_hpb__[0] > 0) {
		    if (inm1_1.fii[inm2_1.fase_hpb__[0] * 20 - 18] == 1 && 
			    inm2_1.vor[6] < fuel_min__ || inm1_1.fii[
			    inm2_1.fase_hpb__[0] * 20 - 18] == 2 && 
			    inm2_1.vor[1] < time_min__) {
			fuel_min__ = inm2_1.vor[6];
			time_min__ = inm2_1.vor[1];
			for (i__ = 1; i__ <= 3; ++i__) {
			    inm2_1.hpsel[i__ - 1] = inm2_1.hpb[inm2_1.ihp[i__ 
				    - 1] + i__ * 100 - 101];
			}
		    }
		}
		if (inm2_1.vor[10] < -.1f) {
		    inm2_1.ierr = 2040;
		}
L100:
		;
	    }
	}
    }
    if (inm2_1.nhpb[0] > 1 || inm2_1.nhpb[1] > 1 || inm2_1.nhpb[2] > 1) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    inm2_1.nhpb[i__ - 1] = 1;
	    inm2_1.hpb[i__ * 100 - 100] = inm2_1.hpsel[i__ - 1];
	}
	goto L15;
    }
L1000:
    for (i__ = 1; i__ <= 6; ++i__) {
	vvoi[i__] = inm2_1.voi[i__ - 1];
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	vvor[i__] = inm2_1.vor[i__ - 1];
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	for (k = 1; k <= 5; ++k) {
	    ssor[i__ + k * 10] = inm2_1.sor[i__ + k * 10 - 11];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (k = 1; k <= 6; ++k) {
	    ggor[i__ + k * 3] = inm2_1.gor[i__ + k * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	for (k = 1; k <= 60; ++k) {
	    ffoi[i__ + k * 6] = inm2_1.foi[i__ + k * 6 - 7];
	}
    }
    for (i__ = 1; i__ <= 60; ++i__) {
	for (k = 1; k <= 60; ++k) {
	    ffor[i__ + k * 60] = inm2_1.for__[i__ + k * 60 - 61];
	}
    }
    *iierr = inm2_1.ierr;
    return 0;
} /* miss_ */

doublereal fmis_(real *pload_dat__)
{
    /* System generated locals */
    integer i__1, i__2;
    real ret_val, r__1, r__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_nint(real *);

    /* Local variables */
    extern /* Subroutine */ int inim_(integer *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, real *, 
	    real *, integer *, real *, integer *), sctra_(integer *, real *, 
	    integer *, real *, integer *), sccli_(char *, char *, integer *, 
	    real *, integer *, real *, integer *, ftnlen, ftnlen), redalt_(
	    integer *, integer *, real *, integer *, integer *, integer *), 
	    sccri_(char *, char *, integer *, real *, integer *, real *, 
	    integer *, ftnlen, ftnlen), scdes_(char *, char *, integer *, 
	    real *, integer *, real *, integer *, ftnlen, ftnlen), mtxeq_(
	    real *, integer *, integer *, integer *, real *, integer *, 
	    integer *);
    static real fuel_old__, ploadmax, peso_ini__;
    static integer c__;
    static real ploadmax1;
    static integer i__, j, k, l;
    static real ff;
    static integer ie, ij;
    static real ve;
    static integer is;
    static real vl1;
    static integer vl2[10];
    static real vl3[30], vl4;
    static integer nec, isc;
    static real com, tim, dis, pll[60];
    static char char1[1], char6[6];
    static integer niter, nred, fase_in__, ialti[60], ialtf[60];
    static real xjac[32580]	/* was [180][181] */, fuelb, fuelt, vmzfw, 
	    vmrw, vmtow, vmzfw1, vmtow1, vftx, fuel, fuelmax, vfuel, pload, 
	    pload_f__, hpff[60], hpif[60], fovrlp;

/*      POINTER(CHAR1,CHAR1) */
/*      POINTER(CHAR6,CHAR6) */
/*      CHAR1=MALLOC(1) */
/*      CHAR6=MALLOC(6) */
    *(unsigned char *)char1 = ' ';
    s_copy(char6, afm_1.afm, (ftnlen)6, (ftnlen)6);
    ++inm2_1.cont;
    if (inm2_1.cont > 1) {
	if (inm2_1.cont > 10000) {
	    inm2_1.ierr = 2560;
	    goto L10000;
	}
	inim_(vl2, vl3, inm1_1.sii, inm1_1.sir, inm1_1.gii, inm1_1.gir, 
		inm1_1.fii, inm1_1.fir, inm2_1.voi, inm2_1.vor, inm2_1.sor, 
		inm2_1.gor, inm2_1.foi, inm2_1.for__, &inm2_1.ierr);
	if (inm2_1.ierr > 0) {
	    goto L10000;
	}
    }
    fuelmax = 999999.f;
    vl1 = inm1_1.mfuel;
    if (vl1 < fuelmax) {
	fuelmax = vl1;
    }
    vl4 = 0.f;
    if (inm1_1.sii[1] == 2) {
	vl4 = inm1_1.sir[0];
    }
    if (vl4 < 0.f) {
	vl4 = 0.f;
    }
    vmrw = inm1_1.mrw;
    if (inm1_1.fii[0] == 1 && inm1_1.fir[4] > 0.f) {
	vmrw = inm1_1.fir[4];
    }
    vl1 = vmrw - inm1_1.oew - inm1_1.stores - vl4;
    if (vl1 < fuelmax) {
	fuelmax = vl1;
    }
    if (inm1_1.fii[0] == 11) {
	k = 1;
    } else if (inm1_1.fii[20] == 11) {
	k = 2;
    } else {
	inm2_1.ierr = 2134;
	goto L10000;
    }
    vmtow = inm1_1.fir[inm1_1.walt + 5 + k * 35 - 36];
    if (inm1_1.walt == 1 && inm1_1.fir[k * 35 - 31] < inm1_1.fir[k * 35 - 30])
	     {
	vmtow = inm1_1.fir[k * 35 - 31];
    }
    if (inm1_1.mtow < vmtow) {
	inm2_1.ierr = 2134;
	goto L10000;
    }
    vftx = inm2_1.cole[0];
    if (inm1_1.fii[0] == 1 && inm1_1.fir[0] <= 0.f) {
	inm1_1.fir[3] = vmtow;
	sctra_(inm1_1.fii, inm1_1.fir, inm2_1.foi, inm2_1.for__, &ie);
	if (ie > 0) {
	    inm2_1.voi[0] = 1;
	    inm2_1.ierr = ie;
	    if (ie >= 1100) {
		goto L10000;
	    }
	}
	vftx = inm2_1.for__[0];
    }
    vl1 = vmtow - inm1_1.oew - inm1_1.stores - vl4 + vftx;
    if (vl1 < fuelmax) {
	fuelmax = vl1;
    }
    if (inm1_1.sii[1] == 2 || inm1_1.sii[1] == 4) {
	fuel = fuelmax;
    } else if (inm1_1.sii[1] == 0 && inm1_1.ifuel != 0.f) {
	fuel = inm1_1.ifuel;
    } else {
	fuel = fuelmax * .3f;
    }
    if (inm2_1.grp_f__ > 0) {
	if (inm1_1.sii[1] >= 2) {
	    inm1_1.gir[inm2_1.grp_f__ * 5 - 5] = fuelmax;
	}
	if (inm1_1.gir[inm2_1.grp_f__ * 5 - 5] > fuelmax) {
	    inm1_1.gir[inm2_1.grp_f__ * 5 - 5] = fuelmax;
	}
    }
    nred = 0;
    niter = 0;
    i__1 = inm1_1.nfas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inm1_1.fir[i__ * 35 - 29] = inm1_1.rcmin;
	inm1_1.fir[i__ * 35 - 28] = inm1_1.rdcab;
	inm1_1.fir[i__ * 35 - 27] = inm1_1.mhcab;
	inm1_1.fir[i__ * 35 - 18] = inm1_1.mhac;
	pll[i__ - 1] = inm1_1.fir[i__ * 35 - 22];
	hpif[i__ - 1] = inm1_1.fir[i__ * 35 - 15];
	hpff[i__ - 1] = inm1_1.fir[i__ * 35 - 14];
	ialti[i__ - 1] = 0;
	ialtf[i__ - 1] = 0;
    }
L10:
    ++niter;
    if (niter > 40) {
	inm2_1.ierr = 2562;
	goto L10000;
    }
    i__1 = inm1_1.nfas;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ialti[i__ - 1] != 4) {
	    ialti[i__ - 1] = 0;
	}
	if (ialtf[i__ - 1] != 4) {
	    ialtf[i__ - 1] = 0;
	}
	if (ialti[i__ - 1] == 0) {
	    inm1_1.fir[i__ * 35 - 15] = hpif[i__ - 1];
	}
	if (ialtf[i__ - 1] == 0) {
	    inm1_1.fir[i__ * 35 - 14] = hpff[i__ - 1];
	}
    }
    fuel_old__ = fuel;
    i__1 = inm2_1.necu;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = inm2_1.necu;
	for (j = 1; j <= i__2; ++j) {
	    xjac[i__ + j * 180 - 181] = 0.f;
	}
    }
    ij = 0;
    nec = 0;
    fase_in__ = 1;
    is = 0;
    vfuel = fuel;
    i__1 = inm1_1.nfas;
    for (k = 1; k <= i__1; ++k) {
	com = inm2_1.cole[ij];
	tim = inm2_1.cole[ij + 1];
	dis = inm2_1.cole[ij + 2];
	if (k == fase_in__) {
	    ++is;
	    if (is < inm1_1.nsec) {
		fase_in__ += inm1_1.sii[is * 5 - 5];
	    }
	    if (is == inm1_1.nsec && inm1_1.rsec == 1) {
		pload = pload_f__;
		if (inm1_1.fii[k * 20 - 8] > 0 && inm1_1.fii[k * 20 - 8] < k) 
			{
		    i__2 = inm1_1.fii[k * 20 - 8] + 1;
		    for (i__ = k - 1; i__ >= i__2; --i__) {
			vfuel += inm2_1.for__[i__ * 60 - 60];
		    }
		}
	    } else {
		vmzfw = inm1_1.sir[is * 20 - 19];
		if (is == 1 && inm1_1.walt == 1) {
		    vmzfw = inm1_1.sir[2];
		}
		vmrw = inm1_1.mrw;
		vftx = 0.f;
		if (inm1_1.fii[k * 20 - 20] == 1) {
		    if (inm1_1.fir[k * 35 - 31] > 0.f) {
			vmrw = inm1_1.fir[k * 35 - 31];
		    }
		    if (inm1_1.fir[k * 35 - 35] <= 0.f) {
			inm1_1.fir[k * 35 - 32] = vmrw;
			sctra_(&inm1_1.fii[k * 20 - 20], &inm1_1.fir[k * 35 - 
				35], &inm2_1.foi[k * 6 - 6], &inm2_1.for__[k *
				 60 - 60], &ie);
			if (ie > 0) {
			    inm2_1.voi[0] = k;
			    inm2_1.ierr = ie;
			    if (ie >= 1100) {
				goto L10000;
			    }
			}
			vftx = inm2_1.for__[k * 60 - 60];
		    } else {
			vftx = inm1_1.fir[k * 35 - 35];
		    }
		}
		if (inm1_1.fii[k * 20 - 20] == 11) {
		    vmtow = inm1_1.fir[k * 35 - 31];
		    if (is == 1 && inm1_1.walt == 1 && inm1_1.fir[k * 35 - 30]
			     < inm1_1.fir[k * 35 - 31]) {
			vmtow = inm1_1.fir[k * 35 - 30];
		    }
		} else if (k + 1 < fase_in__ && inm1_1.fii[(k + 1) * 20 - 20] 
			== 11) {
		    vmtow = inm1_1.fir[(k + 1) * 35 - 31];
		    if (is == 1 && inm1_1.walt == 1 && inm1_1.fir[(k + 1) * 
			    35 - 30] < inm1_1.fir[(k + 1) * 35 - 31]) {
			vmtow = inm1_1.fir[(k + 1) * 35 - 30];
		    }
		} else {
		    inm2_1.ierr = 2134;
		    goto L10000;
		}
		ploadmax = 999999.f;
		vl1 = vmzfw - inm1_1.oew - inm1_1.stores;
		if (vl1 < ploadmax) {
		    ploadmax = vl1;
		}
		vl4 = vfuel;
		if (is == 1 && inm1_1.sii[is * 5 - 4] == 3) {
		    vl4 = 0.f;
		}
		vl1 = vmrw - inm1_1.oew - inm1_1.stores - vl4;
		if (vl1 < ploadmax) {
		    ploadmax = vl1;
		}
		vl1 = vmtow - inm1_1.oew - inm1_1.stores - vl4 + vftx;
		if (vl1 < ploadmax) {
		    ploadmax = vl1;
		}
		if (is > 1 && inm1_1.sir[is * 20 - 18] > vmzfw && (inm1_1.sii[
			is * 5 - 4] == 1 || inm1_1.sii[is * 5 - 4] >= 3 || 
			inm1_1.sii[is * 5 - 4] == 0 && pload > ploadmax || 
			inm1_1.sii[is * 5 - 4] == 2 && pload > ploadmax)) {
		    vmzfw1 = inm1_1.sir[is * 20 - 18];
		    if (inm1_1.fii[k * 20 - 20] == 11) {
			vmtow1 = inm1_1.fir[k * 35 - 30];
		    }
		    if (k + 1 < fase_in__ && inm1_1.fii[(k + 1) * 20 - 20] == 
			    11) {
			vmtow1 = inm1_1.fir[(k + 1) * 35 - 30];
		    }
		    ploadmax1 = 999999.f;
		    vl1 = vmzfw1 - inm1_1.oew - inm1_1.stores;
		    if (vl1 < ploadmax1) {
			ploadmax1 = vl1;
		    }
		    vl1 = vmrw - inm1_1.oew - inm1_1.stores - vl4;
		    if (vl1 < ploadmax1) {
			ploadmax1 = vl1;
		    }
		    vl1 = vmtow1 - inm1_1.oew - inm1_1.stores - vl4 + vftx;
		    if (vl1 < ploadmax1) {
			ploadmax1 = vl1;
		    }
		    if (vmtow1 < vmtow && ploadmax1 > ploadmax) {
			ploadmax = ploadmax1;
			vmzfw = vmzfw1;
			vmtow = vmtow1;
		    }
		}
		if (is == inm2_1.sec_mlw__ || is == inm2_1.sec_pl__) {
		    pload = *pload_dat__;
		} else {
		    if (inm1_1.sii[is * 5 - 4] == 1 || inm1_1.sii[is * 5 - 4] 
			    >= 3) {
			pload = ploadmax;
		    } else {
			pload = inm1_1.sir[is * 20 - 20];
			if (pload > ploadmax) {
			    pload = ploadmax;
			}
		    }
		}
		if (is == 1 && inm1_1.sii[is * 5 - 4] == 3) {
		    vl1 = vmrw - inm1_1.oew - inm1_1.stores - pload;
		    fuelmax = vl1;
		    vl1 = vmtow - inm1_1.oew - inm1_1.stores - pload + vftx;
		    if (vl1 < fuelmax) {
			fuelmax = vl1;
		    }
		    if (inm1_1.mfuel < fuelmax) {
			fuelmax = inm1_1.mfuel;
		    }
		    fuel = fuelmax;
		    inm1_1.gir[inm2_1.grp_f__ * 5 - 5] = fuelmax;
		    fuel_old__ = fuel;
		    vfuel = fuel;
		    if (fuel < 1.f) {
			inm2_1.ierr = 2015;
			goto L10000;
		    }
		}
	    }
	    peso_ini__ = inm1_1.oew + inm1_1.stores + pload + vfuel;
	    inm2_1.sor[is * 10 - 4] = pload;
	    inm2_1.sor[is * 10 - 3] = vfuel;
	    pload_f__ = pload;
	    vl1 = 0.f;
	    j = 0;
	    l = 0;
	    i__2 = fase_in__ - 1;
	    for (i__ = k; i__ <= i__2; ++i__) {
		if (inm1_1.fir[i__ * 35 - 22] > 0.f) {
		    vl1 += inm1_1.fir[i__ * 35 - 22];
		    ++j;
		    if (j == 1) {
			l = i__;
		    }
		}
	    }
	    if (j >= 1 && vl1 > pload) {
		if (j == 1) {
		    inm1_1.fir[l * 35 - 22] = pload;
		} else {
		    inm2_1.ierr = 2140;
		    goto L10000;
		}
	    }
	}
	inm1_1.fir[k * 35 - 32] = peso_ini__;
	if (inm1_1.fii[k * 20 - 20] < 30) {
	    sctra_(&inm1_1.fii[k * 20 - 20], &inm1_1.fir[k * 35 - 35], &
		    inm2_1.foi[k * 6 - 6], &inm2_1.for__[k * 60 - 60], &ie);
	} else if (inm1_1.fii[k * 20 - 20] == 31) {
	    if (inm1_1.fii[(k + 1) * 20 - 20] > 40) {
		inm1_1.fii[k * 20 - 17] = inm1_1.fii[(k + 1) * 20 - 17];
	    }
	    for (i__ = 1; i__ <= 3; ++i__) {
		if (k + 1 == inm2_1.fase_hpb__[i__ - 1]) {
		    inm1_1.fir[k * 35 - 14] = inm2_1.hpb[inm2_1.ihp[i__ - 1] 
			    + i__ * 100 - 101];
		}
	    }
	    sccli_(char1, char6, &inm1_1.fii[k * 20 - 20], &inm1_1.fir[k * 35 
		    - 35], &inm2_1.foi[k * 6 - 6], &inm2_1.for__[k * 60 - 60],
		     &ie, (ftnlen)1, (ftnlen)6);
	    if (inm2_1.foi[k * 6 - 6] != 0) {
		redalt_(&k, &inm2_1.foi[k * 6 - 6], &inm2_1.for__[k * 60 - 53]
			, ialti, ialtf, &ie);
		if (ie > 0) {
		    inm2_1.ierr = 2543;
		    goto L10000;
		}
	    }
	} else if (inm1_1.fii[k * 20 - 20] == 41 || inm1_1.fii[k * 20 - 20] ==
		 42) {
	    for (i__ = 1; i__ <= 3; ++i__) {
		if (k == inm2_1.fase_hpb__[i__ - 1] && inm2_1.foi[(k - 1) * 6 
			- 6] == 0) {
		    inm1_1.fir[k * 35 - 15] = inm2_1.hpb[inm2_1.ihp[i__ - 1] 
			    + i__ * 100 - 101];
		}
	    }
	    inm1_1.fir[k * 35 - 35] = com;
	    sccri_(char1, char6, &inm1_1.fii[k * 20 - 20], &inm1_1.fir[k * 35 
		    - 35], &inm2_1.foi[k * 6 - 6], &inm2_1.for__[k * 60 - 60],
		     &ie, (ftnlen)1, (ftnlen)6);
	    inm1_1.fir[k * 35 - 35] = 0.f;
	    if (inm1_1.fii[k * 20 - 20] == 42) {
		inm2_1.for__[k * 60 - 58] = 0.f;
	    }
	} else {
	    for (i__ = 1; i__ <= 3; ++i__) {
		if (k - 1 == inm2_1.fase_hpb__[i__ - 1]) {
		    inm1_1.fir[k * 35 - 15] = inm2_1.for__[(k - 1) * 60 - 53];
		}
	    }
	    scdes_(char1, char6, &inm1_1.fii[k * 20 - 20], &inm1_1.fir[k * 35 
		    - 35], &inm2_1.foi[k * 6 - 6], &inm2_1.for__[k * 60 - 60],
		     &ie, (ftnlen)1, (ftnlen)6);
	}
	com = inm2_1.for__[k * 60 - 60];
	tim = inm2_1.for__[k * 60 - 59];
	dis = inm2_1.for__[k * 60 - 58];
	inm2_1.foi[k * 6 - 3] = ie;
	if (inm1_1.fii[k * 20 - 20] != 41 && inm1_1.fii[k * 20 - 20] != 42) {
	    inm2_1.coli[nec] = tim;
	}
	if (ie > 0) {
	    inm2_1.voi[0] = k;
	    inm2_1.ierr = ie;
	    if (ie >= 1100) {
		goto L10000;
	    }
	}
	if (tim == 0.f) {
	    tim = .001f;
	}
	ve = dis / tim;
	ff = com / tim;
	peso_ini__ = peso_ini__ - com - inm1_1.fir[k * 35 - 22];
	vfuel -= com;
	pload_f__ -= inm1_1.fir[k * 35 - 22];
	if (inm2_1.ind[nec] > 0) {
	    ++nec;
	    xjac[nec + (ij + inm2_1.ind[nec - 1]) * 180 - 181] = 1.f;
	}
	++nec;
	xjac[nec + (ij + 1) * 180 - 181] = 0.f;
	xjac[nec + (ij + 2) * 180 - 181] = ve;
	xjac[nec + (ij + 3) * 180 - 181] = -1.f;
	++nec;
	xjac[nec + (ij + 1) * 180 - 181] = -1.f;
	xjac[nec + (ij + 2) * 180 - 181] = ff;
	xjac[nec + (ij + 3) * 180 - 181] = 0.f;
	ij += 3;
    }
    ij = 0;
    i__1 = inm1_1.ngrp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ != ij && inm2_1.ind[nec] > 100 && inm2_1.ind[nec] < 200) {
	    ++nec;
	    l = inm2_1.ind[nec - 1] - 100;
	    i__2 = inm1_1.gii[i__ * 5 - 4];
	    for (k = inm1_1.gii[i__ * 5 - 5]; k <= i__2; ++k) {
		xjac[nec + (k * 3 + l - 3) * 180 - 181] = 1.f;
		if (l == 1 && i__ == inm2_1.grp_f__ && inm1_1.fii[k * 20 - 8] 
			== 1) {
		    xjac[nec + (k * 3 + l - 3) * 180 - 181] = 0.f;
		}
	    }
	    if (i__ == inm2_1.grp_f__) {
		inm2_1.coli[nec - 1] = inm1_1.gir[i__ * 5 - 5] - inm1_1.rsvf 
			- inm2_1.vor[9];
	    }
	} else if (inm2_1.ind[nec] > 200) {
	    ++nec;
	    l = inm2_1.ind[nec - 1] - 200;
	    i__2 = inm1_1.ngrp;
	    for (j = i__ + 1; j <= i__2; ++j) {
		if (inm1_1.gir[l + j * 5 - 6] < -.001f) {
		    ij = j;
		}
	    }
	    i__2 = inm1_1.gii[i__ * 5 - 4];
	    for (k = inm1_1.gii[i__ * 5 - 5]; k <= i__2; ++k) {
		xjac[nec + (k * 3 + l - 3) * 180 - 181] = 1.f;
	    }
	    i__2 = inm1_1.gii[ij * 5 - 4];
	    for (k = inm1_1.gii[ij * 5 - 5]; k <= i__2; ++k) {
		xjac[nec + (k * 3 + l - 3) * 180 - 181] = -1.f;
	    }
	}
    }
    mtxeq_(inm2_1.coli, &c__180, &inm2_1.necu, &c__1, xjac, &c__180, &ie);
    if (ie > 0) {
	inm2_1.ierr = 2555;
	goto L10000;
    }
    i__1 = inm2_1.necu;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inm2_1.cole[i__ - 1] = xjac[i__ + (inm2_1.necu + 1) * 180 - 181];
    }
    fuel = 0.f;
    fuelb = 0.f;
    fuelt = 0.f;
    fovrlp = 0.f;
    ij = 1;
    fase_in__ = 1;
    i__1 = inm1_1.nsec;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inm2_1.sor[i__ * 10 - 8] = 0.f;
	if (i__ > 1) {
	    fase_in__ += inm1_1.sii[(i__ - 1) * 5 - 5];
	}
	i__2 = fase_in__ + inm1_1.sii[i__ * 5 - 5] - 1;
	for (k = fase_in__; k <= i__2; ++k) {
	    if (i__ > 1 || k > 1) {
		ij += 3;
	    }
	    fuel += inm2_1.cole[ij - 1];
	    if (i__ == inm1_1.nsec - 1 && inm1_1.rsec == 1 && inm1_1.fii[k * 
		    20 - 8] == 1) {
		fuel -= inm2_1.cole[ij - 1];
	    }
	    if (i__ < inm1_1.nsec || i__ == inm1_1.nsec && inm1_1.rsec == 0) {
		if (inm1_1.fii[k * 20 - 20] != 42) {
		    fuelb += inm2_1.cole[ij - 1];
		}
		if (inm1_1.fii[k * 20 - 20] != 42 && inm1_1.fii[k * 20 - 20] 
			> 2) {
		    fuelt += inm2_1.cole[ij - 1];
		}
		if (inm1_1.fii[k * 20 - 8] == 1) {
		    fovrlp = inm2_1.cole[ij - 1] + fovrlp;
		}
	    }
	    inm2_1.sor[i__ * 10 - 8] += inm2_1.cole[ij + 1];
	}
    }
    inm2_1.vor[9] = 0.f;
    if (inm1_1.rsvp > 0.f) {
	inm2_1.vor[9] = inm1_1.rsvp * fuelt / 100.f;
    } else if (inm1_1.rsvp < 0.f) {
	inm2_1.vor[9] = -inm1_1.rsvp * fuelb / 100.f;
    }
    fuel = fuel + inm1_1.rsvf + inm2_1.vor[9];
    if (inm1_1.sii[1] == 0 && inm1_1.ifuel != 0.f) {
	fuel = inm1_1.ifuel;
	goto L30;
    }
    if ((r__1 = fuel - fuel_old__, dabs(r__1)) / fuel > .001f || (r__2 = fuel 
	    - fuel_old__, dabs(r__2)) > .6f) {
	goto L10;
    }
L30:
    if (niter < 4) {
	goto L10;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	inm2_1.vor[i__ - 1] = 0.f;
    }
    inm2_1.vor[6] = fuel;
    inm2_1.vor[7] = inm2_1.vor[9] + inm1_1.rsvf;
    isc = 0;
    ij = 0;
    fase_in__ = 1;
    i__1 = inm1_1.nsec;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inm2_1.sor[i__ * 10 - 10] = 0.f;
	inm2_1.sor[i__ * 10 - 9] = 0.f;
	inm2_1.sor[i__ * 10 - 8] = 0.f;
	inm2_1.sor[i__ * 10 - 7] = 0.f;
	inm2_1.sor[i__ * 10 - 6] = 0.f;
	if (i__ > 1) {
	    fase_in__ += inm1_1.sii[(i__ - 1) * 5 - 5];
	}
	i__2 = fase_in__ + inm1_1.sii[i__ * 5 - 5] - 1;
	for (k = fase_in__; k <= i__2; ++k) {
	    if (i__ == inm2_1.sec_mlw__ && inm1_1.fii[k * 20 - 20] == 12) {
		isc = k;
	    }
	    for (l = 1; l <= 3; ++l) {
		++ij;
		if (i__ < inm1_1.nsec || i__ == inm1_1.nsec && inm1_1.rsec == 
			0) {
		    if (inm1_1.fii[k * 20 - 20] != 42) {
			inm2_1.sor[l + i__ * 10 - 11] += inm2_1.cole[ij - 1];
			inm2_1.vor[l - 1] += inm2_1.cole[ij - 1];
		    } else {
			if (l == 1) {
			    inm2_1.vor[7] += inm2_1.cole[ij - 1];
			}
		    }
		    if (l != 3 && inm1_1.fii[k * 20 - 20] != 42 && inm1_1.fii[
			    k * 20 - 20] > 2) {
			inm2_1.sor[l + 3 + i__ * 10 - 11] += inm2_1.cole[ij - 
				1];
			inm2_1.vor[l + 2] += inm2_1.cole[ij - 1];
		    }
		} else {
		    inm2_1.sor[l + i__ * 10 - 11] += inm2_1.cole[ij - 1];
		    if (l != 3 && inm1_1.fii[k * 20 - 20] > 2) {
			inm2_1.sor[l + 3 + i__ * 10 - 11] += inm2_1.cole[ij - 
				1];
		    }
		    if (l == 1) {
			inm2_1.vor[7] += inm2_1.cole[ij - 1];
		    }
		}
	    }
	}
    }
    if (inm1_1.timp != 0.f) {
	k = inm1_1.nsec;
	if (inm1_1.rsec == 1) {
	    k = inm1_1.nsec - 1;
	}
	i__1 = k;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inm1_1.timp > 0.f) {
		vl1 = inm1_1.timp * inm2_1.sor[i__ * 10 - 6] / 100.f;
		inm2_1.sor[i__ * 10 - 6] += vl1;
		inm2_1.sor[i__ * 10 - 9] += vl1;
		inm2_1.vor[4] += vl1;
		inm2_1.vor[1] += vl1;
	    } else {
		vl1 = -inm1_1.timp * inm2_1.sor[i__ * 10 - 9] / 100.f;
		inm2_1.sor[i__ * 10 - 9] += vl1;
		inm2_1.vor[1] += vl1;
	    }
	}
    }
    i__1 = inm1_1.ngrp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inm2_1.gor[i__ * 3 - 3] = 0.f;
	inm2_1.gor[i__ * 3 - 2] = 0.f;
	inm2_1.gor[i__ * 3 - 1] = 0.f;
	i__2 = inm1_1.gii[i__ * 5 - 4];
	for (k = inm1_1.gii[i__ * 5 - 5]; k <= i__2; ++k) {
	    inm2_1.gor[i__ * 3 - 3] += inm2_1.for__[k * 60 - 60];
	    inm2_1.gor[i__ * 3 - 2] += inm2_1.for__[k * 60 - 59];
	    inm2_1.gor[i__ * 3 - 1] += inm2_1.for__[k * 60 - 58];
	}
    }
    fase_in__ = 1;
    i__1 = inm1_1.nsec;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (inm1_1.crpor >= 0.f) {
	    vl1 = inm1_1.crpor / 100.f * inm2_1.sor[i__ * 10 - 8];
	    vl4 = 0.f;
	} else {
	    vl1 = 0.f;
	    vl4 = (r__1 = inm1_1.crpor / 100.f, dabs(r__1)) * inm2_1.sor[i__ *
		     10 - 6];
	}
	if (i__ > 1) {
	    fase_in__ += inm1_1.sii[(i__ - 1) * 5 - 5];
	}
	i__2 = fase_in__ + inm1_1.sii[i__ * 5 - 5] - 1;
	for (k = fase_in__; k <= i__2; ++k) {
	    if (inm1_1.fii[k * 20 - 20] == 41 && (inm2_1.grp_c__[k - 1] == 0 
		    || inm2_1.grp_c__[k - 1] > 0 && inm2_1.for__[k * 60 - 59] 
		    < 0.f) && (inm2_1.for__[k * 60 - 59] < inm1_1.crtim || 
		    inm2_1.for__[k * 60 - 59] < vl4 || inm2_1.for__[k * 60 - 
		    58] < vl1)) {
		++nred;
		if (inm1_1.fii[k * 20 - 17] < 0) {
		    vl1 = (real) ((integer) (inm2_1.for__[k * 60 - 53] / 
			    500.f)) * 500.f;
		    if (vl1 == inm2_1.for__[k * 60 - 53]) {
			vl1 = inm2_1.for__[k * 60 - 53] - 500.f;
		    }
		} else if (inm1_1.fii[k * 20 - 17] == 0) {
		    vl1 = (real) ((integer) (inm2_1.for__[k * 60 - 53] / 1e3f)
			    ) * 1e3f;
		    if (vl1 == inm2_1.for__[k * 60 - 53]) {
			vl1 = inm2_1.for__[k * 60 - 53] - 1e3f;
		    }
		} else {
		    vl1 = 0.f;
		    for (j = 17; j >= 1; --j) {
			vl4 = (real) inm1_1.fl[j + inm1_1.fii[k * 20 - 17] * 
				17 - 18] * 100.f;
			if (vl1 == 0.f && vl4 < inm2_1.for__[k * 60 - 53]) {
			    vl1 = vl4;
			}
		    }
		}
		if (vl1 <= 0.f) {
		    inm2_1.ierr = 2165;
		    if (inm2_1.grp_f__ > 0) {
			inm2_1.ierr = 2030;
		    }
		    goto L10000;
		}
		redalt_(&k, &c__4, &vl1, ialti, ialtf, &ie);
		if (ie > 0) {
		    inm2_1.ierr = 2165;
		    if (inm2_1.grp_f__ > 0) {
			inm2_1.ierr = 2030;
		    }
		    goto L10000;
		}
		niter = 0;
		goto L10;
	    }
	}
    }
    if (inm2_1.sec_pl__ == 0 && i_nint(&fuel) > i_nint(&fuelmax)) {
	i__1 = inm1_1.nsec;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inm1_1.sii[i__ * 5 - 4] > 0) {
		inm2_1.sec_pl__ = i__;
		ret_val = 0.f;
		return ret_val;
	    }
	}
	inm2_1.ierr = 2010;
	ret_val = 0.f;
	return ret_val;
    }
    if (inm2_1.sec_pl__ == 0) {
	i__1 = inm1_1.nfas;
	for (k = 1; k <= i__1; ++k) {
	    inm1_1.fir[k * 35 - 15] = hpif[k - 1];
	    inm1_1.fir[k * 35 - 14] = hpff[k - 1];
	}
    }
    i__1 = inm1_1.nfas;
    for (k = 1; k <= i__1; ++k) {
	inm1_1.fir[k * 35 - 22] = pll[k - 1];
	inm1_1.fir[k * 35 - 29] = 0.f;
	inm1_1.fir[k * 35 - 28] = 0.f;
	inm1_1.fir[k * 35 - 27] = 0.f;
	inm1_1.fir[k * 35 - 18] = 0.f;
    }
    inm2_1.vor[10] = inm1_1.ifuel;
    if (inm1_1.sii[1] == 0 && inm1_1.ifuel != 0.f) {
	i__1 = inm1_1.nfas;
	for (c__ = 1; c__ <= i__1; ++c__) {
	    inm2_1.vor[10] -= inm2_1.for__[c__ * 60 - 60];
	}
	inm2_1.vor[10] += fovrlp;
    } else {
	inm2_1.vor[10] = 0.f;
    }
    ret_val = 0.f;
    if (isc > 0) {
	ret_val = inm1_1.fir[isc * 35 - 31] - inm2_1.for__[isc * 60 - 57];
    }
    if (inm2_1.sec_pl__ > 0) {
	ret_val = fuel - fuelmax;
    }
    return ret_val;
L10000:
    ret_val = 0.f;
    return ret_val;
} /* fmis_ */

/* Subroutine */ int sccli_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_nint(real *);
    double r_mod(real *, real *);

    /* Local variables */
    extern /* Subroutine */ int escric_(integer *, integer *, real *, integer 
	    *, integer *), manual3r_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, real *, real *, real *, integer *);
    static integer i__, j, ie, il;
    static real hp;
    static integer is, iv;
    static real we[2], vl1, dif;
    static integer itq;
    static real weq[2], wee, fui, tmi, dii, fuf, tmf, fuv[8], tiv[8], div[8], 
	    wet, fut, tmt, dit;
    static char vici[200];
    static integer ninter, verc;
    static real fact, dvel, fsfu, fsti, fsdi, hpcab;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), inic_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), sctec_(real *, 
	    real *, real *, real *, real *, real *, integer *, integer *), 
	    int2r_(real *, real *, real *, integer *, integer *, real *, 
	    integer *), supint_(integer *, integer *, real *, integer *, real 
	    *, real *, integer *, real *, real *, integer *, real *, real *, 
	    real *, integer *);

/* MS$ATTRIBUTES DLLEXPORT :: SCCLI */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    inic_(&c__1, &dams1_1.sley, &dams1_1.sinop[vii[2] - 1], &vii[1], &vir[1], 
	    &voi[1], &vor[1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    sctec_(&inj1_1.peso_0__, &inj1_1.hpf, &inj2_1.hpc, &inj2_1.rcfi, &
	    inj2_1.tech, &hpcab, &inj2_1.ialt, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (ie == 1120) {
	*ierr = ie;
	return 0;
    }
    if (inj1_1.hpi < 0.f && inj1_1.hpf < 0.f) {
	if (inj2_1.ialt == 1) {
	    inj2_1.hpc = (real) ((integer) (inj2_1.tech / 10.f) * 10);
	    inj2_1.rcfi = inj1_1.rcmin;
	}
	goto L350;
    }
    if (inj1_1.hpi < 0.f && inj1_1.hpf >= 0.f) {
	goto L350;
    }
    if (dams1_1.nsisa[inj1_1.ley - 1] <= 0) {
	*ierr = 1110;
	return 0;
    }
    il = inj1_1.ley;
    fsfu = 1.f;
    fsti = 1.f;
    fsdi = 1.f;
    if (dams1_1.scod[inj1_1.ley - 1] != 0) {
	int2r_(&inj1_1.isa, &dams1_1.sisa[inj1_1.ley * 9 - 9], &dams1_1.ysfu[
		inj1_1.ley * 4000 - 4000], &c__1, &dams1_1.nsisa[inj1_1.ley - 
		1], &fsfu, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	int2r_(&inj1_1.isa, &dams1_1.sisa[inj1_1.ley * 9 - 9], &dams1_1.ysti[
		inj1_1.ley * 4000 - 4000], &c__1, &dams1_1.nsisa[inj1_1.ley - 
		1], &fsti, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	int2r_(&inj1_1.isa, &dams1_1.sisa[inj1_1.ley * 9 - 9], &dams1_1.ysdi[
		inj1_1.ley * 4000 - 4000], &c__1, &dams1_1.nsisa[inj1_1.ley - 
		1], &fsdi, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	il = dams1_1.scod[inj1_1.ley - 1];
    }
    iv = 0;
    itq = 0;
    supint_(&dams1_1.grsfu[il * 9 - 9], &dams1_1.nzsfu[il * 9 - 9], &
	    dams1_1.zsfu[il * 150 - 150], &dams1_1.nsfu[il * 150 - 150], &
	    dams1_1.xsfu[il * 4000 - 4000], &dams1_1.ysfu[il * 4000 - 4000], &
	    dams1_1.npmsfu[il * 9 - 9], &inj1_1.hpi, &inj1_1.peso_0__, &
	    dams1_1.nsisa[il - 1], &dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &
	    fui, &ie);
    if (ie == 2) {
	goto L10000;
    }
    we[0] = inj1_1.peso_0__ - fui;
    weq[0] = inj1_1.peso_0__;
    r__1 = (fui + 100.f) / 100.f;
    weq[1] = inj1_1.peso_0__ + i_nint(&r__1) * 100.f;
    if (weq[1] > dagen3_1.limw[5]) {
	weq[1] = inj1_1.peso_0__ - 100.f;
    }
    supint_(&dams1_1.grsfu[il * 9 - 9], &dams1_1.nzsfu[il * 9 - 9], &
	    dams1_1.zsfu[il * 150 - 150], &dams1_1.nsfu[il * 150 - 150], &
	    dams1_1.xsfu[il * 4000 - 4000], &dams1_1.ysfu[il * 4000 - 4000], &
	    dams1_1.npmsfu[il * 9 - 9], &inj1_1.hpi, &weq[1], &dams1_1.nsisa[
	    il - 1], &dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &fui, &ie);
    if (ie == 2) {
	goto L10000;
    }
    we[1] = weq[1] - fui;
    int2r_(&inj1_1.peso_0__, we, weq, &c__1, &c__2, &wee, &ie);
    if (ie == 2) {
	goto L10000;
    }
    fui = wee - inj1_1.peso_0__;
    supint_(&dams1_1.grsti[il * 9 - 9], &dams1_1.nzsti[il * 9 - 9], &
	    dams1_1.zsti[il * 150 - 150], &dams1_1.nsti[il * 150 - 150], &
	    dams1_1.xsti[il * 4000 - 4000], &dams1_1.ysti[il * 4000 - 4000], &
	    dams1_1.npmsti[il * 9 - 9], &inj1_1.hpi, &wee, &dams1_1.nsisa[il 
	    - 1], &dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &tmi, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams1_1.grsdi[il * 9 - 9], &dams1_1.nzsdi[il * 9 - 9], &
	    dams1_1.zsdi[il * 150 - 150], &dams1_1.nsdi[il * 150 - 150], &
	    dams1_1.xsdi[il * 4000 - 4000], &dams1_1.ysdi[il * 4000 - 4000], &
	    dams1_1.npmsdi[il * 9 - 9], &inj1_1.hpi, &wee, &dams1_1.nsisa[il 
	    - 1], &dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &dii, &ie);
    if (ie == 2) {
	goto L10000;
    }
    hp = inj2_1.hpc;
    if (inj2_1.hpc == inj1_1.hpi) {
	*ierr = 1010;
	goto L350;
    }
    if (inj2_1.hpc < inj1_1.hpi) {
	*ierr = 1141;
	return 0;
    }
L90:
    supint_(&dams1_1.grsfu[il * 9 - 9], &dams1_1.nzsfu[il * 9 - 9], &
	    dams1_1.zsfu[il * 150 - 150], &dams1_1.nsfu[il * 150 - 150], &
	    dams1_1.xsfu[il * 4000 - 4000], &dams1_1.ysfu[il * 4000 - 4000], &
	    dams1_1.npmsfu[il * 9 - 9], &hp, &wee, &dams1_1.nsisa[il - 1], &
	    dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &fuf, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams1_1.grsti[il * 9 - 9], &dams1_1.nzsti[il * 9 - 9], &
	    dams1_1.zsti[il * 150 - 150], &dams1_1.nsti[il * 150 - 150], &
	    dams1_1.xsti[il * 4000 - 4000], &dams1_1.ysti[il * 4000 - 4000], &
	    dams1_1.npmsti[il * 9 - 9], &hp, &wee, &dams1_1.nsisa[il - 1], &
	    dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &tmf, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams1_1.grsdi[il * 9 - 9], &dams1_1.nzsdi[il * 9 - 9], &
	    dams1_1.zsdi[il * 150 - 150], &dams1_1.nsdi[il * 150 - 150], &
	    dams1_1.xsdi[il * 4000 - 4000], &dams1_1.ysdi[il * 4000 - 4000], &
	    dams1_1.npmsdi[il * 9 - 9], &hp, &wee, &dams1_1.nsisa[il - 1], &
	    dams1_1.sisa[il * 9 - 9], &inj1_1.isa, &dif, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (inj2_1.ialt == 1) {
	fut = fuf - fui;
	for (j = 1; j <= 15; ++j) {
	    if (dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 0.f) {
		goto L95;
	    }
	    if (inj2_1.x[(integer) dams2_1.spc[j + (il * 5 + 1) * 5 - 31] - 1]
		     > 0.f) {
		fact = 1.f;
		if (dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 1.f) {
		    fact = inj2_1.x[0] / 50.f;
		}
		if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] == -100.f) {
		    *ierr = 1120;
		    return 0;
		} else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -100.f && 
			dams2_1.spc[j + (il * 5 + 2) * 5 - 31] > -200.f) {
		    is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 
			    - 31], dabs(r__1)) - 100.f);
		    manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			    dams2_1.xsc[(is + il * 10) * 50 - 550], &
			    dams2_1.ysc[(is + il * 10) * 50 - 550], &
			    dams2_1.zsc[(is + il * 10) * 5 - 55], &
			    dams2_1.nsc[(is + il * 10) * 5 - 55], &
			    dams2_1.nzsc[is + il * 10 - 11], &fut, &vl1, &
			    inj1_1.isa, &ie);
		    fut = vl1;
		    if (ie == 2) {
			goto L10000;
		    }
		} else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -200.f) {
		    is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 
			    - 31], dabs(r__1)) - 200.f);
		    manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			    dams2_1.xsc[(is + il * 10) * 50 - 550], &
			    dams2_1.ysc[(is + il * 10) * 50 - 550], &
			    dams2_1.zsc[(is + il * 10) * 5 - 55], &
			    dams2_1.nsc[(is + il * 10) * 5 - 55], &
			    dams2_1.nzsc[is + il * 10 - 11], &fut, &vl1, 
			    inj2_1.x, &ie);
		    fut = vl1;
		    if (ie == 2) {
			goto L10000;
		    }
		} else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] > 1.6f || 
			dams2_1.spc[j + (il * 5 + 2) * 5 - 31] <= 0.f) {
		    fut += dams2_1.spc[j + (il * 5 + 2) * 5 - 31] * fact;
		} else {
		    fut *= fact * (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] - 
			    1.f) + 1.f;
		}
	    }
	}
L95:
	fut *= fsfu;
	fut *= inj1_1.fff / 100.f + 1.f;
	wet = inj1_1.peso_0__ - fut;
	sctec_(&wet, &inj1_1.hpf, &vl1, &inj2_1.rcfi, &inj2_1.tech, &hpcab, &
		inj2_1.ialt, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (vl1 < inj2_1.hpc) {
	    *ierr = 1557;
	    return 0;
	} else if (vl1 > inj2_1.hpc) {
	    inj2_1.hpc = vl1;
	    hp = inj2_1.hpc;
	    goto L90;
	}
    }
    fut = fuf - fui;
    tmt = tmf - tmi;
    dit = dif - dii;
    for (j = 1; j <= 15; ++j) {
	if (dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 0.f) {
	    goto L100;
	}
	if (inj2_1.x[(integer) dams2_1.spc[j + (il * 5 + 1) * 5 - 31] - 1] > 
		0.f) {
	    if ((integer) dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 3 && 
		    inj2_1.x[(integer) dams2_1.spc[j + (il * 5 + 1) * 5 - 31] 
		    - 1] == 1.f) {
		itq = (integer) dams2_1.spc[j + (il * 5 + 5) * 5 - 31];
	    }
	    fact = 1.f;
	    if (dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 1.f) {
		fact = inj2_1.x[0] / 50.f;
	    }
	    if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -100.f && 
		    dams2_1.spc[j + (il * 5 + 2) * 5 - 31] > -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 - 31]
			, dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &fut, &vl1, &
			inj1_1.isa, &ie);
		fut = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 - 31]
			, dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &fut, &vl1, inj2_1.x,
			 &ie);
		fut = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] > 1.6f || 
		    dams2_1.spc[j + (il * 5 + 2) * 5 - 31] <= 0.f) {
		fut += dams2_1.spc[j + (il * 5 + 2) * 5 - 31] * fact;
	    } else {
		fut *= fact * (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] - 1.f) 
			+ 1.f;
	    }
	    if (dams2_1.spc[j + (il * 5 + 3) * 5 - 31] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams2_1.spc[j + (il * 5 + 3) * 5 - 31] < -100.f && 
		    dams2_1.spc[j + (il * 5 + 3) * 5 - 31] > -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 3) * 5 - 31]
			, dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &tmt, &vl1, &
			inj1_1.isa, &ie);
		tmt = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 - 31]
			, dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &tmt, &vl1, inj2_1.x,
			 &ie);
		tmt = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 3) * 5 - 31] > 1.6f || 
		    dams2_1.spc[j + (il * 5 + 3) * 5 - 31] <= 0.f) {
		tmt += dams2_1.spc[j + (il * 5 + 3) * 5 - 31] * fact;
	    } else {
		tmt *= fact * (dams2_1.spc[j + (il * 5 + 3) * 5 - 31] - 1.f) 
			+ 1.f;
	    }
	    if (dams2_1.spc[j + (il * 5 + 4) * 5 - 31] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams2_1.spc[j + (il * 5 + 4) * 5 - 31] < -100.f && 
		    dams2_1.spc[j + (il * 5 + 4) * 5 - 31] > -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 4) * 5 - 31]
			, dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &dit, &vl1, &
			inj1_1.isa, &ie);
		dit = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 2) * 5 - 31] < -200.f) {
		is = (integer) ((r__1 = dams2_1.spc[j + (il * 5 + 2) * 5 - 31]
			, dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams2_1.grsc[is + il * 10 - 11], &
			dams2_1.xsc[(is + il * 10) * 50 - 550], &dams2_1.ysc[(
			is + il * 10) * 50 - 550], &dams2_1.zsc[(is + il * 10)
			 * 5 - 55], &dams2_1.nsc[(is + il * 10) * 5 - 55], &
			dams2_1.nzsc[is + il * 10 - 11], &dit, &vl1, inj2_1.x,
			 &ie);
		dit = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams2_1.spc[j + (il * 5 + 4) * 5 - 31] > 1.6f || 
		    dams2_1.spc[j + (il * 5 + 4) * 5 - 31] <= 0.f) {
		dit += dams2_1.spc[j + (il * 5 + 4) * 5 - 31] * fact;
	    } else {
		dit *= fact * (dams2_1.spc[j + (il * 5 + 4) * 5 - 31] - 1.f) 
			+ 1.f;
	    }
	}
    }
L100:
    fut *= fsfu;
    tmt *= fsti;
    dit *= fsdi;
    dit -= inj1_1.wind * tmt / 60.f;
    fut *= inj1_1.fff / 100.f + 1.f;
    if (iv == 0) {
	inj2_1.fuel = fut;
	inj2_1.time = tmt;
	inj2_1.dist = dit;
	i__1 = inj1_1.npin;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inj1_1.dis[i__ - 1] <= dit) {
		++inj2_1.npinv;
		inj2_1.di[i__ - 1] = inj1_1.dis[i__ - 1];
	    }
	}
    }
    if (inj2_1.npinv > 0) {
	if (iv == 0) {
	    r__1 = inj2_1.hpc - inj1_1.hpi;
	    if (r_mod(&r__1, &c_b41) != 0.f) {
		ninter = (integer) ((inj2_1.hpc - inj1_1.hpi) / 5e3f);
	    } else {
		ninter = (integer) ((inj2_1.hpc - inj1_1.hpi) / 5e3f) - 1;
	    }
	    for (i__ = 1; i__ <= 8; ++i__) {
		fuv[i__ - 1] = 0.f;
		tiv[i__ - 1] = 0.f;
		div[i__ - 1] = 0.f;
	    }
	    iv = 1;
	}
	if (iv == 1) {
	    fuv[iv - 1] = 0.f;
	    tiv[iv - 1] = 0.f;
	    div[iv - 1] = 0.f;
	} else {
	    fuv[iv - 1] = fut;
	    tiv[iv - 1] = tmt;
	    div[iv - 1] = dit;
	}
	if (iv < ninter + 1) {
	    hp = inj1_1.hpi + (real) iv * 5e3f;
	    ++iv;
	    goto L90;
	}
	fuv[ninter + 1] = inj2_1.fuel;
	tiv[ninter + 1] = inj2_1.time;
	div[ninter + 1] = inj2_1.dist;
	i__1 = inj2_1.npinv;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = ninter + 2;
	    int2r_(&inj2_1.di[i__ - 1], div, fuv, &c__1, &i__2, &inj2_1.fu[
		    i__ - 1], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    i__2 = ninter + 2;
	    int2r_(&inj2_1.di[i__ - 1], div, tiv, &c__1, &i__2, &inj2_1.ti[
		    i__ - 1], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	}
    }
    manual3r_(&c__3, &dams2_1.grsv[il - 1], &dams2_1.xssv[il * 50 - 50], &
	    dams2_1.yhsv[il * 50 - 50], &dams2_1.zwsv[il * 15 - 15], &
	    dams2_1.nsv[il * 10 - 10], &dams2_1.nzsv[il - 1], &inj2_1.vini, &
	    inj1_1.hpi, &inj1_1.peso_0__, &ie);
    if (ie == 2) {
	goto L10000;
    }
    r__1 = inj1_1.peso_0__ - inj2_1.fuel;
    manual3r_(&c__3, &dams2_1.grsv[il - 1], &dams2_1.xssv[il * 50 - 50], &
	    dams2_1.yhsv[il * 50 - 50], &dams2_1.zwsv[il * 15 - 15], &
	    dams2_1.nsv[il * 10 - 10], &dams2_1.nzsv[il - 1], &inj2_1.vfin, &
	    inj2_1.hpc, &r__1, &ie);
    if (ie == 2) {
	goto L10000;
    }
    dvel = 0.f;
    manual3r_(&c__1, &dams2_1.grsdv[il - 1], &dams2_1.xwsdv[il * 20 - 20], &
	    dams2_1.yssdv[il * 20 - 20], &dams2_1.zrsdv[il * 6 - 6], &
	    dams2_1.nsdv[il * 6 - 6], &dams2_1.nzsdv[il - 1], &
	    inj1_1.peso_0__, &dvel, inj2_1.x, &ie);
    if (ie == 2) {
	goto L10000;
    }
    inj2_1.vini += dvel;
    inj2_1.vfin += dvel;
    inj2_1.vgmd = inj2_1.dist / inj2_1.time * 60.f;
    itq = dams2_1.indtqs[inj1_1.ley - 1] + itq;
    if (itq > 0) {
	manual3r_(&c__1, &dams2_1.grtqs[itq - 1], &dams2_1.xttqs[itq * 600 - 
		600], &dams2_1.yqtqs[itq * 600 - 600], &dams2_1.zhtqs[itq * 
		35 - 35], &dams2_1.ntqs[itq * 35 - 35], &dams2_1.nztqs[itq - 
		1], &inj1_1.isa, &inj2_1.tqin, &inj1_1.hpi, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__1, &dams2_1.grtqs[itq - 1], &dams2_1.xttqs[itq * 600 - 
		600], &dams2_1.yqtqs[itq * 600 - 600], &dams2_1.zhtqs[itq * 
		35 - 35], &dams2_1.ntqs[itq * 35 - 35], &dams2_1.nztqs[itq - 
		1], &inj1_1.isa, &inj2_1.tqfi, &inj2_1.hpc, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    }
    if (inj2_1.ialt != 1) {
	r__1 = inj1_1.peso_0__ - inj2_1.fuel;
	sctec_(&r__1, &inj1_1.hpf, &vl1, &inj2_1.rcfi, &inj2_1.tech, &hpcab, &
		i__, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    }
L350:
    inj2_1.peso_i__ = inj1_1.peso_0__;
    inj2_1.peso_f__ = inj1_1.peso_0__ - inj2_1.fuel;
    escric_(&c__1, &voi[1], &vor[1], &verc, &dagen3_1.verd[3]);
    return 0;
L10000:
    *ierr = 1500;
    return 0;
} /* sccli_ */

/* Subroutine */ int sccru_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer j, ic, ie;
    static real vl1, mach;
    static char vici[200];
    static integer verc;
    static real fact, hpcab;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), inic_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), sctec_(real *, 
	    real *, real *, real *, real *, real *, integer *, integer *), 
	    supint_(integer *, integer *, real *, integer *, real *, real *, 
	    integer *, real *, real *, integer *, real *, real *, real *, 
	    integer *), convel_(real *, real *, real *, real *, real *, real *
	    , integer *, real *, real *, real *, real *, real *, real *, real 
	    *, integer *), escric_(integer *, integer *, real *, integer *, 
	    integer *);

/* MS$ATTRIBUTES DLLEXPORT :: SCCRU */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    if (inj1_1.intcru != 0) {
	goto L60;
    }
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    inic_(&c__2, &dams5_1.cley, &dams5_1.cinop[vii[2] - 1], &vii[1], &vir[1], 
	    &voi[1], &vor[1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
L60:
    sctec_(&inj1_1.peso_0__, &inj1_1.hpi, &inj2_1.hpc, &inj2_1.rcfi, &
	    inj2_1.tech, &hpcab, &inj2_1.ialt, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (ie == 1120) {
	*ierr = ie;
	return 0;
    }
    supint_(&dams5_1.grcff[inj1_1.ley * 9 - 9], &dams5_1.nzcff[inj1_1.ley * 9 
	    - 9], &dams5_1.zcff[inj1_1.ley * 150 - 150], &dams5_1.ncff[
	    inj1_1.ley * 150 - 150], &dams5_1.xcff[inj1_1.ley * 4000 - 4000], 
	    &dams5_1.ycff[inj1_1.ley * 4000 - 4000], &dams5_1.npmcff[
	    inj1_1.ley * 9 - 9], &inj2_1.hpc, &inj1_1.peso_0__, &
	    dams5_1.ncisa[inj1_1.ley - 1], &dams5_1.cisa[inj1_1.ley * 9 - 9], 
	    &inj1_1.isa, &inj2_1.ffl, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams5_1.grcve[inj1_1.ley * 9 - 9], &dams5_1.nzcve[inj1_1.ley * 9 
	    - 9], &dams5_1.zcve[inj1_1.ley * 150 - 150], &dams5_1.ncve[
	    inj1_1.ley * 150 - 150], &dams5_1.xcve[inj1_1.ley * 4000 - 4000], 
	    &dams5_1.ycve[inj1_1.ley * 4000 - 4000], &dams5_1.npmcve[
	    inj1_1.ley * 9 - 9], &inj2_1.hpc, &inj1_1.peso_0__, &
	    dams5_1.ncisa[inj1_1.ley - 1], &dams5_1.cisa[inj1_1.ley * 9 - 9], 
	    &inj1_1.isa, &inj2_1.veas, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams6_1.grctq[inj1_1.ley * 9 - 9], &dams6_1.nzctq[inj1_1.ley * 9 
	    - 9], &dams6_1.zctq[inj1_1.ley * 150 - 150], &dams6_1.nctq[
	    inj1_1.ley * 150 - 150], &dams6_1.xctq[inj1_1.ley * 4000 - 4000], 
	    &dams6_1.yctq[inj1_1.ley * 4000 - 4000], &dams6_1.npmctq[
	    inj1_1.ley * 9 - 9], &inj2_1.hpc, &inj1_1.peso_0__, &
	    dams5_1.ncisa[inj1_1.ley - 1], &dams5_1.cisa[inj1_1.ley * 9 - 9], 
	    &inj1_1.isa, &inj2_1.tqin, &ie);
    if (ie == 2) {
	goto L10000;
    }
    for (j = 1; j <= 15; ++j) {
	if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 1) * 5 - 26] == 0.f) {
	    goto L100;
	}
	if (inj2_1.x[(integer) dams6_1.cpc[j + ((inj1_1.ley << 2) + 1) * 5 - 
		26] - 1] > 0.f) {
	    fact = 1.f;
	    if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 1) * 5 - 26] == 1.f) {
		fact = inj2_1.x[0] / 50.f;
	    }
	    if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] < 
		    -100.f && dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 
		    26] > -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			2) * 5 - 26], dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.ffl, 
			&vl1, &inj1_1.isa, &ie);
		inj2_1.ffl = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] < 
		    -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			2) * 5 - 26], dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.ffl, 
			&vl1, inj2_1.x, &ie);
		inj2_1.ffl = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] > 
		    1.6f || dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] 
		    <= 0.f) {
		inj2_1.ffl += dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) * 5 - 
			26] * fact;
	    } else {
		inj2_1.ffl *= fact * (dams6_1.cpc[j + ((inj1_1.ley << 2) + 2) 
			* 5 - 26] - 1.f) + 1.f;
	    }
	    if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] < 
		    -100.f && dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 
		    26] > -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			3) * 5 - 26], dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.veas,
			 &vl1, &inj1_1.isa, &ie);
		inj2_1.veas = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] < 
		    -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			3) * 5 - 26], dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.veas,
			 &vl1, inj2_1.x, &ie);
		inj2_1.veas = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] > 
		    1.6f || dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] 
		    <= 0.f) {
		inj2_1.veas += dams6_1.cpc[j + ((inj1_1.ley << 2) + 3) * 5 - 
			26] * fact;
	    } else {
		inj2_1.veas *= fact * (dams6_1.cpc[j + ((inj1_1.ley << 2) + 3)
			 * 5 - 26] - 1.f) + 1.f;
	    }
	    if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] < 
		    -100.f && dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 
		    26] > -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			4) * 5 - 26], dabs(r__1)) - 100.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.tqin,
			 &vl1, &inj1_1.isa, &ie);
		inj2_1.tqin = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] < 
		    -200.f) {
		ic = (integer) ((r__1 = dams6_1.cpc[j + ((inj1_1.ley << 2) + 
			4) * 5 - 26], dabs(r__1)) - 200.f);
		manual3r_(&c__1, &dams6_1.grcc[ic + inj1_1.ley * 10 - 11], &
			dams6_1.xcc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.ycc[(ic + inj1_1.ley * 10) * 50 - 550], &
			dams6_1.zcc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.ncc[(ic + inj1_1.ley * 10) * 5 - 55], &
			dams6_1.nzcc[ic + inj1_1.ley * 10 - 11], &inj2_1.tqin,
			 &vl1, inj2_1.x, &ie);
		inj2_1.tqin = vl1;
		if (ie == 2) {
		    goto L10000;
		}
	    } else if (dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] > 
		    1.6f || dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] 
		    <= 0.f) {
		inj2_1.tqin += dams6_1.cpc[j + ((inj1_1.ley << 2) + 4) * 5 - 
			26] * fact;
	    } else {
		inj2_1.tqin *= fact * (dams6_1.cpc[j + ((inj1_1.ley << 2) + 4)
			 * 5 - 26] - 1.f) + 1.f;
	    }
	}
    }
L100:
    convel_(&c_b62, &inj1_1.isa, &inj2_1.hpc, &inj1_1.peso_0__, &c_b5, &
	    inj1_1.wind, &c__1, &inj2_1.veas, &vl1, &inj2_1.vcas, &mach, &
	    inj2_1.vtas, &inj2_1.vgmd, &inj2_1.vini, &ie);
    if (ie > 500) {
	*ierr = ie + 1000;
	return 0;
    }
    if (ie > 0) {
	goto L10000;
    }
    manual3r_(&c__1, &dams6_1.grnp[inj1_1.ley - 1], &dams6_1.xhnp[inj1_1.ley *
	     60 - 60], &dams6_1.ynp[inj1_1.ley * 60 - 60], &dams6_1.ztnp[
	    inj1_1.ley * 9 - 9], &dams6_1.nnp[inj1_1.ley * 9 - 9], &
	    dams6_1.nznp[inj1_1.ley - 1], &inj2_1.hpc, &inj2_1.rev, &
	    inj1_1.isa, &ie);
    if (ie == 2) {
	goto L10000;
    }
    inj2_1.ffl *= inj1_1.fff / 100.f + 1.f;
    inj2_1.alc = inj2_1.vgmd / inj2_1.ffl;
    inj2_1.ffl /= (real) inj2_1.nmot;
    if (inj1_1.intcru == 0) {
	inj2_1.peso_i__ = inj1_1.peso_0__;
	inj2_1.peso_f__ = inj1_1.peso_0__;
	escric_(&c__2, &voi[1], &vor[1], &verc, &dagen3_1.verd[3]);
    }
    return 0;
L10000:
    *ierr = 1500;
    return 0;
} /* sccru_ */

/* Subroutine */ int scdes_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_nint(real *);
    double r_mod(real *, real *);

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *);
    static integer i__, j, ie;
    static real hp, we[2];
    static integer iv;
    static real hp1, dif, weq[2], wee, fui, tmi, dii, fuf, tmf, fuv[8], tiv[8]
	    , div[8], fut, tmt, dit;
    static char vici[200];
    static integer ninter, verc;
    static real fact, isac;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), inic_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), supint_(
	    integer *, integer *, real *, integer *, real *, real *, integer *
	    , real *, real *, integer *, real *, real *, real *, integer *), 
	    int2r_(real *, real *, real *, integer *, integer *, real *, 
	    integer *), escric_(integer *, integer *, real *, integer *, 
	    integer *);

/* MS$ATTRIBUTES DLLEXPORT :: SCDES */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    inic_(&c__3, &dams7_1.dley, &dams7_1.dinop[vii[2] - 1], &vii[1], &vir[1], 
	    &voi[1], &vor[1], ierr);
    if (*ierr == 1010) {
	goto L350;
    }
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    iv = 0;
L80:
    isac = inj1_1.isa;
    if (dams7_1.ndisa[inj1_1.ley - 1] == 1) {
	isac = dams7_1.disa[inj1_1.ley * 9 - 9];
    }
    supint_(&dams7_1.grdfu[inj1_1.ley * 9 - 9], &dams7_1.nzdfu[inj1_1.ley * 9 
	    - 9], &dams7_1.zdfu[inj1_1.ley * 50 - 50], &dams7_1.ndfu[
	    inj1_1.ley * 50 - 50], &dams7_1.xdfu[inj1_1.ley * 1500 - 1500], &
	    dams7_1.ydfu[inj1_1.ley * 1500 - 1500], &dams7_1.npmdfu[
	    inj1_1.ley * 9 - 9], &inj1_1.hpi, &inj1_1.peso_0__, &
	    dams7_1.ndisa[inj1_1.ley - 1], &dams7_1.disa[inj1_1.ley * 9 - 9], 
	    &isac, &fui, &ie);
    if (ie == 2) {
	goto L10000;
    }
    we[0] = inj1_1.peso_0__ - fui;
    weq[0] = inj1_1.peso_0__;
    r__1 = (fui + 100.f) / 100.f;
    weq[1] = inj1_1.peso_0__ + i_nint(&r__1) * 100.f;
    supint_(&dams7_1.grdfu[inj1_1.ley * 9 - 9], &dams7_1.nzdfu[inj1_1.ley * 9 
	    - 9], &dams7_1.zdfu[inj1_1.ley * 50 - 50], &dams7_1.ndfu[
	    inj1_1.ley * 50 - 50], &dams7_1.xdfu[inj1_1.ley * 1500 - 1500], &
	    dams7_1.ydfu[inj1_1.ley * 1500 - 1500], &dams7_1.npmdfu[
	    inj1_1.ley * 9 - 9], &inj1_1.hpi, &weq[1], &dams7_1.ndisa[
	    inj1_1.ley - 1], &dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &fui, &
	    ie);
    if (ie == 2) {
	goto L10000;
    }
    we[1] = weq[1] - fui;
    int2r_(&inj1_1.peso_0__, we, weq, &c__1, &c__2, &wee, &ie);
    if (ie == 2) {
	goto L10000;
    }
    fui = wee - inj1_1.peso_0__;
    supint_(&dams7_1.grdti[inj1_1.ley * 9 - 9], &dams7_1.nzdti[inj1_1.ley * 9 
	    - 9], &dams7_1.zdti[inj1_1.ley * 50 - 50], &dams7_1.ndti[
	    inj1_1.ley * 50 - 50], &dams7_1.xdti[inj1_1.ley * 1500 - 1500], &
	    dams7_1.ydti[inj1_1.ley * 1500 - 1500], &dams7_1.npmdti[
	    inj1_1.ley * 9 - 9], &inj1_1.hpi, &wee, &dams7_1.ndisa[inj1_1.ley 
	    - 1], &dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &tmi, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams7_1.grddi[inj1_1.ley * 9 - 9], &dams7_1.nzddi[inj1_1.ley * 9 
	    - 9], &dams7_1.zddi[inj1_1.ley * 50 - 50], &dams7_1.nddi[
	    inj1_1.ley * 50 - 50], &dams7_1.xddi[inj1_1.ley * 1500 - 1500], &
	    dams7_1.yddi[inj1_1.ley * 1500 - 1500], &dams7_1.npmddi[
	    inj1_1.ley * 9 - 9], &inj1_1.hpi, &wee, &dams7_1.ndisa[inj1_1.ley 
	    - 1], &dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &dii, &ie);
    if (ie == 2) {
	goto L10000;
    }
    hp = inj1_1.hpf;
L90:
    supint_(&dams7_1.grdfu[inj1_1.ley * 9 - 9], &dams7_1.nzdfu[inj1_1.ley * 9 
	    - 9], &dams7_1.zdfu[inj1_1.ley * 50 - 50], &dams7_1.ndfu[
	    inj1_1.ley * 50 - 50], &dams7_1.xdfu[inj1_1.ley * 1500 - 1500], &
	    dams7_1.ydfu[inj1_1.ley * 1500 - 1500], &dams7_1.npmdfu[
	    inj1_1.ley * 9 - 9], &hp, &wee, &dams7_1.ndisa[inj1_1.ley - 1], &
	    dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &fuf, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams7_1.grdti[inj1_1.ley * 9 - 9], &dams7_1.nzdti[inj1_1.ley * 9 
	    - 9], &dams7_1.zdti[inj1_1.ley * 50 - 50], &dams7_1.ndti[
	    inj1_1.ley * 50 - 50], &dams7_1.xdti[inj1_1.ley * 1500 - 1500], &
	    dams7_1.ydti[inj1_1.ley * 1500 - 1500], &dams7_1.npmdti[
	    inj1_1.ley * 9 - 9], &hp, &wee, &dams7_1.ndisa[inj1_1.ley - 1], &
	    dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &tmf, &ie);
    if (ie == 2) {
	goto L10000;
    }
    supint_(&dams7_1.grddi[inj1_1.ley * 9 - 9], &dams7_1.nzddi[inj1_1.ley * 9 
	    - 9], &dams7_1.zddi[inj1_1.ley * 50 - 50], &dams7_1.nddi[
	    inj1_1.ley * 50 - 50], &dams7_1.xddi[inj1_1.ley * 1500 - 1500], &
	    dams7_1.yddi[inj1_1.ley * 1500 - 1500], &dams7_1.npmddi[
	    inj1_1.ley * 9 - 9], &hp, &wee, &dams7_1.ndisa[inj1_1.ley - 1], &
	    dams7_1.disa[inj1_1.ley * 9 - 9], &isac, &dif, &ie);
    if (ie == 2) {
	goto L10000;
    }
    fut = fuf - fui;
    tmt = tmf - tmi;
    dit = dif - dii;
    for (j = 1; j <= 15; ++j) {
	if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 1) * 5 - 26] == 0.f) {
	    goto L100;
	}
	if (inj2_1.x[(integer) dams7_1.dpc[j + ((inj1_1.ley << 2) + 1) * 5 - 
		26] - 1] > 0.f) {
	    fact = 1.f;
	    if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 1) * 5 - 26] == 1.f) {
		fact = inj2_1.x[0] / 50.f;
	    }
	    if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] > 
		    1.6f || dams7_1.dpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] 
		    <= 0.f) {
		fut += dams7_1.dpc[j + ((inj1_1.ley << 2) + 2) * 5 - 26] * 
			fact;
	    } else {
		fut *= fact * (dams7_1.dpc[j + ((inj1_1.ley << 2) + 2) * 5 - 
			26] - 1.f) + 1.f;
	    }
	    if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] > 
		    1.6f || dams7_1.dpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] 
		    <= 0.f) {
		tmt += dams7_1.dpc[j + ((inj1_1.ley << 2) + 3) * 5 - 26] * 
			fact;
	    } else {
		tmt *= fact * (dams7_1.dpc[j + ((inj1_1.ley << 2) + 3) * 5 - 
			26] - 1.f) + 1.f;
	    }
	    if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] == -100.f) {
		*ierr = 1120;
		return 0;
	    } else if (dams7_1.dpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] > 
		    1.6f || dams7_1.dpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] 
		    <= 0.f) {
		dit += dams7_1.dpc[j + ((inj1_1.ley << 2) + 4) * 5 - 26] * 
			fact;
	    } else {
		dit *= fact * (dams7_1.dpc[j + ((inj1_1.ley << 2) + 4) * 5 - 
			26] - 1.f) + 1.f;
	    }
	}
    }
L100:
    dit -= inj1_1.wind * tmt / 60.f;
    fut *= inj1_1.fff / 100.f + 1.f;
    if (inj1_1.rdcab > 0.f) {
	if (dagen3_1.nlpr > 0) {
	    manual2r_(&c__2, &hp1, dagen3_1.xhlpr, dagen3_1.yhlpr, &
		    dagen3_1.grlpr, &dagen3_1.nlpr, &inj1_1.hpi, &ie);
	} else {
	    hp1 = inj1_1.hpi;
	}
	if (ie == 2) {
	    goto L10000;
	}
	hp1 -= inj1_1.rdcab * tmt;
	if (hp1 > inj1_1.hpf) {
	    *ierr = 1040;
	    if (inj1_1.ley == 1) {
		*ierr = 1042;
	    } else {
		--inj1_1.ley;
		goto L80;
	    }
	}
    }
    if (iv == 0) {
	inj2_1.fuel = fut;
	inj2_1.time = tmt;
	inj2_1.dist = dit;
	inj2_1.npinv = 0;
	i__1 = inj1_1.npin;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (inj1_1.dis[i__ - 1] <= dit) {
		++inj2_1.npinv;
	    }
	    inj2_1.di[i__ - 1] = inj1_1.dis[i__ - 1];
	}
    }
    if (inj2_1.npinv > 0) {
	if (iv == 0) {
	    r__1 = inj1_1.hpi - inj1_1.hpf;
	    if (r_mod(&r__1, &c_b41) != 0.f) {
		ninter = (integer) ((inj1_1.hpi - inj1_1.hpf) / 5e3f);
	    } else {
		ninter = (integer) ((inj1_1.hpi - inj1_1.hpf) / 5e3f) - 1;
	    }
	    for (i__ = 1; i__ <= 8; ++i__) {
		fuv[i__ - 1] = 0.f;
		tiv[i__ - 1] = 0.f;
		div[i__ - 1] = 0.f;
	    }
	    iv = 1;
	}
	if (iv == 1) {
	    fuv[iv - 1] = 0.f;
	    tiv[iv - 1] = 0.f;
	    div[iv - 1] = 0.f;
	} else {
	    fuv[iv - 1] = fut;
	    tiv[iv - 1] = tmt;
	    div[iv - 1] = dit;
	}
	if (iv < ninter + 1) {
	    hp = inj1_1.hpi - (real) iv * 5e3f;
	    ++iv;
	    goto L90;
	}
	fuv[ninter + 1] = inj2_1.fuel;
	tiv[ninter + 1] = inj2_1.time;
	div[ninter + 1] = inj2_1.dist;
	i__1 = inj2_1.npinv;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = ninter + 2;
	    int2r_(&inj2_1.di[i__ - 1], div, fuv, &c__1, &i__2, &inj2_1.fu[
		    i__ - 1], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    i__2 = ninter + 2;
	    int2r_(&inj2_1.di[i__ - 1], div, tiv, &c__1, &i__2, &inj2_1.ti[
		    i__ - 1], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	}
    }
    manual2r_(&c__2, &inj2_1.vini, &dams7_1.xsdv[inj1_1.ley * 50 - 50], &
	    dams7_1.yhdv[inj1_1.ley * 50 - 50], &dams7_1.grdv[inj1_1.ley - 1],
	     &dams7_1.ndv[inj1_1.ley - 1], &inj1_1.hpi, &ie);
    if (ie == 2) {
	goto L10000;
    }
    manual2r_(&c__2, &inj2_1.vfin, &dams7_1.xsdv[inj1_1.ley * 50 - 50], &
	    dams7_1.yhdv[inj1_1.ley * 50 - 50], &dams7_1.grdv[inj1_1.ley - 1],
	     &dams7_1.ndv[inj1_1.ley - 1], &inj1_1.hpf, &ie);
    if (ie == 2) {
	goto L10000;
    }
    inj2_1.vgmd = inj2_1.dist * 60.f / inj2_1.time;
L350:
    inj2_1.peso_i__ = inj1_1.peso_0__;
    inj2_1.peso_f__ = inj1_1.peso_0__ - inj2_1.fuel;
    inj2_1.hpc = inj1_1.hpf;
    escric_(&c__3, &voi[1], &vor[1], &verc, &dagen3_1.verd[3]);
    return 0;
L10000:
    *ierr = 1500;
    return 0;
} /* scdes_ */

/* Subroutine */ int sccri_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, n, ie;
    static real vi[30];
    static integer nw;
    static real tq[30], xw[30], vl1, vl2, vl3, yff[30], ysr[30], mach;
    static char vici[200];
    static integer verc;
    static real tech_ci__, rcfi_ci__, rev_ci__, ialt_ci__;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), inic_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), sccru_(char *, 
	    char *, integer *, real *, integer *, real *, integer *, ftnlen, 
	    ftnlen), bart_(real *, real *, real *, real *, integer *, integer 
	    *, real *, integer *), int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), convel_(real *, real *, real *, 
	    real *, real *, real *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, integer *), escric_(integer *, integer *,
	     real *, integer *, integer *);

/* MS$ATTRIBUTES DLLEXPORT :: SCCRI */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    inic_(&c__5, &dams5_1.cley, &dams5_1.cinop[vii[2] - 1], &vii[1], &vir[1], 
	    &voi[1], &vor[1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    inj2_1.peso_i__ = inj1_1.peso_0__;
    inj2_1.peso_f__ = inj1_1.peso_0__ - inj1_1.fuel_0__;
    nw = 2;
    xw[0] = inj2_1.peso_i__;
    xw[1] = (integer) (inj2_1.peso_i__ / 1e3f) * 1e3f;
    if (xw[0] <= xw[1]) {
	xw[1] += -500.f;
    }
L50:
    if (xw[nw - 1] > inj2_1.peso_f__) {
	++nw;
	if (nw > 30) {
	    *ierr = 2010;
	    return 0;
	}
	xw[nw - 1] = xw[nw - 2] - 500.f;
	goto L50;
    }
    i__1 = nw;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inj1_1.peso_0__ = xw[i__ - 1];
	sccru_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (ftnlen)
		200, (ftnlen)10);
	if (*ierr > 0) {
	    return 0;
	}
	yff[i__ - 1] = -60.f / inj2_1.ffl / (real) inj2_1.nmot;
	ysr[i__ - 1] = -inj2_1.alc;
	vi[i__ - 1] = inj2_1.vini;
	tq[i__ - 1] = inj2_1.tqin;
	if (i__ == 1) {
	    ialt_ci__ = (real) inj2_1.ialt;
	    tech_ci__ = inj2_1.tech;
	    rcfi_ci__ = inj2_1.rcfi;
	    rev_ci__ = inj2_1.rev;
	    inj1_1.hpi = inj2_1.hpc;
	}
    }
    n = (integer) (inj1_1.fuel_0__ / 100.f);
    if (n < 2) {
	n = 2;
    }
    bart_(&inj2_1.peso_i__, &inj2_1.peso_f__, xw, yff, &nw, &n, &inj2_1.time, 
	    &ie);
    if (ie == 2) {
	goto L10000;
    }
    bart_(&inj2_1.peso_i__, &inj2_1.peso_f__, xw, ysr, &nw, &n, &inj2_1.dist, 
	    &ie);
    if (ie == 2) {
	goto L10000;
    }
    inj1_1.peso_0__ = inj2_1.peso_i__;
    inj2_1.ialt = ialt_ci__;
    inj2_1.fuel = inj1_1.fuel_0__;
    inj2_1.tech = tech_ci__;
    inj2_1.vini = vi[0];
    int2r_(&inj2_1.peso_f__, xw, vi, &c__1, &nw, &inj2_1.vfin, &ie);
    if (ie > 2) {
	goto L10000;
    }
    inj2_1.vgmd = inj2_1.dist * 60.f / inj2_1.time;
    inj2_1.vtas = inj2_1.vgmd + inj1_1.wind;
    convel_(&c_b62, &inj1_1.isa, &inj1_1.hpi, &inj1_1.peso_0__, &c_b5, &
	    inj1_1.wind, &c__4, &inj2_1.vtas, &inj2_1.veas, &inj2_1.vcas, &
	    mach, &vl1, &vl2, &vl3, &ie);
    if (ie > 500) {
	*ierr = ie + 1000;
	return 0;
    }
    if (ie > 0) {
	goto L10000;
    }
    inj2_1.rcfi = rcfi_ci__;
    inj2_1.tqin = tq[0];
    int2r_(&inj2_1.peso_f__, xw, tq, &c__1, &nw, &inj2_1.tqfi, &ie);
    if (ie > 2) {
	goto L10000;
    }
    inj2_1.rev = rev_ci__;
    escric_(&c__5, &voi[1], &vor[1], &verc, &dagen3_1.verd[3]);
    inj1_1.intcru = 0;
    return 0;
L10000:
    *ierr = 1500;
    return 0;
} /* sccri_ */

/* Subroutine */ int sctra_(integer *vii, real *vir, integer *voi, real *vor, 
	integer *ierr)
{
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer ie;
    static real vl1, fmi, fma, oat;
    static integer verc, fase;
    static real height, ffto, fuel_c__, time_c__, dist_c__, oat_std__;
    extern /* Subroutine */ int inic_(integer *, integer *, integer *, 
	    integer *, real *, integer *, real *, integer *), escric_(integer 
	    *, integer *, real *, integer *, integer *);

    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    inic_(&c__6, &c__0, &c__0, &vii[1], &vir[1], &voi[1], &vor[1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    fmi = .2f;
    fma = 3.5f;
    fase = vii[1];
    height = 0.f;
    if (vii[1] == 11) {
	fase = 3;
	height = inj1_1.hpf - inj1_1.hpi;
    } else if (vii[1] == 12) {
	fase = 4;
	height = inj1_1.hpi - inj1_1.hpf;
    } else if (vii[1] == 21) {
	fase = 5;
	height = inj1_1.hpf - inj1_1.hpi;
    }
    if (fase <= 0 || fase > 5) {
	*ierr = 2524;
	return 0;
    }
    if (height < -.01f) {
	*ierr = 1140;
	return 0;
    }
    if (height < .01f) {
	height = 0.f;
    }
    if (height > 2e3f) {
	height = 2e3f;
    }
    height /= 1e3f;
    inj2_1.time = vir[2];
    if (inj2_1.time < 0.f) {
	inj2_1.time = 0.f;
    }
    if (fase > 2) {
	time_c__ = dams8_1.time_0__[fase - 1] + dams8_1.time_h__[fase - 1] * 
		height;
	if (time_c__ < .3f && height <= 0.f) {
	    time_c__ = .3f;
	}
	if (inj2_1.time <= 0.f) {
	    inj2_1.time = time_c__;
	} else if (inj2_1.time < fmi * time_c__ || inj2_1.time > fma * 
		time_c__) {
	    *ierr = 2160;
	    return 0;
	}
    }
    oat_std__ = 15.f - inj1_1.hpi * 1.98f / 1e3f;
    oat = inj1_1.isa + oat_std__;
    if (inj1_1.system[1] == 0) {
	manual3r_(&c__1, &dagen1_1.grfft, dagen1_1.xtfft, dagen1_1.yfft, 
		dagen1_1.zhfft, dagen1_1.nfft, &dagen1_1.nzfft, &oat, &ffto, &
		inj1_1.hpi, &ie);
    } else {
	if (dagen1_1.nzffti > 1) {
	    manual3r_(&c__1, &dagen1_1.grffti, dagen1_1.xffti, dagen1_1.yffti,
		     dagen1_1.zffti, dagen1_1.nffti, &dagen1_1.nzffti, &oat, &
		    ffto, &inj1_1.hpi, &ie);
	    if (dagen1_1.nzffti <= 3) {
		if (ie == 2) {
		    goto L10000;
		}
		vl1 = ffto;
		manual3r_(&c__1, &dagen1_1.grffti, dagen1_1.xffti, 
			dagen1_1.yffti, dagen1_1.zffti, dagen1_1.nffti, &
			dagen1_1.nzffti, &vl1, &ffto, dagen1_1.zffti, &ie);
	    }
	} else {
	    manual3r_(&c__1, &dagen1_1.grffti, dagen1_1.xffti, dagen1_1.yffti,
		     dagen1_1.zffti, dagen1_1.nffti, &dagen1_1.nzffti, &oat, &
		    vl1, dagen1_1.zffti, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual3r_(&c__1, &dagen1_1.grfft, dagen1_1.xtfft, dagen1_1.yfft, 
		    dagen1_1.zhfft, dagen1_1.nfft, &dagen1_1.nzfft, &vl1, &
		    ffto, &inj1_1.hpi, &ie);
	}
    }
    if (ie == 2) {
	goto L10000;
    }
    ffto = ffto * .4536f / 60.f;
    inj2_1.fuel = inj1_1.fuel_0__;
    if (inj2_1.fuel < 0.f) {
	inj2_1.fuel = 0.f;
    }
    fuel_c__ = (real) inj2_1.nmot * dams8_1.fuel_f__[fase - 1] * ffto * (
	    inj1_1.fff / 100.f + 1.f) * inj2_1.time;
    if (inj2_1.fuel <= 0.f) {
	inj2_1.fuel = fuel_c__;
    } else if (inj2_1.fuel < fmi * fuel_c__ || inj2_1.fuel > fma * fuel_c__) {
	*ierr = 2160;
	return 0;
    }
    inj2_1.dist = vir[3];
    if (inj2_1.dist < 0.f) {
	inj2_1.dist = 0.f;
    }
    if (fase <= 2) {
	inj2_1.dist = 0.f;
    } else if (fase > 2 && inj1_1.credit > 0) {
	dist_c__ = dams8_1.dist_0__[fase - 1] + dams8_1.dist_h__[fase - 1] * 
		height;
	if (inj2_1.dist <= 0.f) {
	    inj2_1.dist = dist_c__;
	} else if (inj2_1.dist < fmi * dist_c__ || inj2_1.dist > fma * 
		dist_c__) {
	    *ierr = 2160;
	    return 0;
	}
    }
    inj2_1.peso_i__ = vir[4];
    inj2_1.peso_f__ = vir[4] - inj2_1.fuel;
    inj2_1.hpc = inj1_1.hpf;
    if (fase <= 2) {
	inj2_1.hpc = inj1_1.hpi;
    }
    escric_(&c__6, &voi[1], &vor[1], &verc, &dagen3_1.verd[3]);
    return 0;
L10000:
    *ierr = 1500;
    return 0;
} /* sctra_ */

/* Subroutine */ int sccre_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static real d__, f, t;
    static integer ie;
    static char vici[200];
    static real f_dat__, d_dat__, t_dat__, delta_f__;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), sccri_(char *, char *, integer *, 
	    real *, integer *, real *, integer *, ftnlen, ftnlen), sccru_(
	    char *, char *, integer *, real *, integer *, real *, integer *, 
	    ftnlen, ftnlen);

/* MS$ATTRIBUTES DLLEXPORT :: SCCRE */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0 || s_cmp(
	    afm_1.afm, afm_1.afm_ms__, (ftnlen)6, (ftnlen)6) != 0) {
	lectm_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    delta_f__ = .5f;
    f_dat__ = vir[1];
    d_dat__ = vir[40];
    t_dat__ = vir[41];
    if (f_dat__ != 0.f && t_dat__ == 0.f && d_dat__ == 0.f) {
	sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (ftnlen)
		200, (ftnlen)10);
    } else if (d_dat__ != 0.f && f_dat__ != 0.f) {
	d__ = 0.f;
	f = 0.f;
	while(d__ < d_dat__) {
	    f += delta_f__;
	    vir[1] = f;
	    sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
		    ftnlen)200, (ftnlen)10);
	    d__ = vor[3];
	    if (f > f_dat__) {
		vir[1] = f_dat__;
		sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
			ftnlen)200, (ftnlen)10);
		*ierr = 1215;
		return 0;
	    }
	}
    } else if (t_dat__ != 0.f && f_dat__ != 0.f) {
	t = 0.f;
	f = 0.f;
	while(t < t_dat__) {
	    f += delta_f__;
	    vir[1] = f;
	    sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
		    ftnlen)200, (ftnlen)10);
	    t = vor[2];
	    if (f > f_dat__) {
		vir[1] = f_dat__;
		sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
			ftnlen)200, (ftnlen)10);
		*ierr = 1215;
		return 0;
	    }
	}
    } else if (f_dat__ == 0.f && d_dat__ == 0.f && t_dat__ == 0.f) {
	sccru_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (ftnlen)
		200, (ftnlen)10);
    } else {
	*ierr = 1110;
    }
    return 0;
} /* sccre_ */

