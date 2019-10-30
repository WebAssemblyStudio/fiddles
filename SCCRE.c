/* SCCRE.F -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__5 = 5;

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
    static real f_dat__, d_dat__, t_dat__;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectm_(
	    char *, integer *, ftnlen), inic_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), sccri_(char *, 
	    char *, integer *, real *, integer *, real *, integer *, ftnlen, 
	    ftnlen), sccru_(char *, char *, integer *, real *, integer *, 
	    real *, integer *, ftnlen, ftnlen);

/*      !MS$ATTRIBUTES DLLEXPORT :: CRUISE */
/*      !MS$ATTRIBUTES ALIAS: 'SCCRI' :: CRUISE */
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
    f_dat__ = vir[1];
    d_dat__ = vir[40];
    t_dat__ = vir[41];
    if (f_dat__ != 0.f) {
	sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (ftnlen)
		200, (ftnlen)10);
    } else if (d_dat__ != 0.f) {
	d__ = 0.f;
	f = 0.f;
	while(d__ < d_dat__) {
	    f += 1.f;
	    vir[1] = f;
	    sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
		    ftnlen)200, (ftnlen)10);
	    d__ = vor[3];
	    if (f > vir[4] - (dagen3_1.limw[4] + vir[42])) {
		vir[1] += -1.f;
		sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
			ftnlen)200, (ftnlen)10);
		*ierr = 1215;
		return 0;
	    }
	}
    } else if (t_dat__ != 0.f) {
	t = 0.f;
	f = 0.f;
	while(t < t_dat__) {
	    f += 1.f;
	    vir[1] = f;
	    sccri_(vic, vid, &vii[1], &vir[1], &voi[1], &vor[1], ierr, (
		    ftnlen)200, (ftnlen)10);
	    t = vor[2];
	    if (f > vir[4] - (dagen3_1.limw[4] + vir[42])) {
		vir[1] += -1.f;
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

