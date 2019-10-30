/* LAND.F -- translated by f2c (version 20100827).
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
    real zhw[40]	/* was [20][2] */, xww[1000]	/* was [500][2] */, 
	    ytw[1000]	/* was [500][2] */, zwc[50]	/* was [5][5][2] */, 
	    xwc[500]	/* was [50][5][2] */, ywc[500]	/* was [50][5][2] */, 
	    xtwi[20]	/* was [10][2] */, ytwi[20]	/* was [10][2] */, 
	    xtwj[20]	/* was [10][2] */, ywwj[20]	/* was [10][2] */, 
	    zhga1[40]	/* was [20][2] */, xtga1[1000]	/* was [500][2] */, 
	    yga1[1000]	/* was [500][2] */, zgga2[60]	/* was [30][2] */, 
	    xwga2[1000]	/* was [500][2] */, yga2[1000]	/* was [500][2] */, 
	    zgac[50]	/* was [5][5][2] */, xgac[500]	/* was [50][5][2] */, 
	    ygac[500]	/* was [50][5][2] */, xtgai[20]	/* was [10][2] */, 
	    ytgai[20]	/* was [10][2] */, xgg[30]	/* was [15][2] */, 
	    ycg[30]	/* was [15][2] */, zhbl1[40]	/* was [20][2] */, 
	    xtbl1[1000]	/* was [500][2] */, ybl1[1000]	/* was [500][2] */, 
	    zgbl2[60]	/* was [30][2] */, xwbl2[1000]	/* was [500][2] */, 
	    ybl2[1000]	/* was [500][2] */, zblc[50]	/* was [5][5][2] */, 
	    xblc[500]	/* was [50][5][2] */, yblc[500]	/* was [50][5][2] */, 
	    xtbli[20]	/* was [10][2] */, ytbli[20]	/* was [10][2] */;
    integer grw[2], nzw[2], nw[40]	/* was [20][2] */, grwc[10]	/* 
	    was [5][2] */, nzwc[10]	/* was [5][2] */, nwc[50]	/* 
	    was [5][5][2] */, pwc[30]	/* was [15][2] */, grwi[2], nwi[2], 
	    grwj[2], nwj[2], indga[2], grga1[2], nzga1[2], nga1[40]	/* 
	    was [20][2] */, grga2[2], nzga2[2], nga2[60]	/* was [30][2]
	     */, grgac[10]	/* was [5][2] */, nzgac[10]	/* was [5][2] 
	    */, ngac[50]	/* was [5][5][2] */, pgac[30]	/* was [15][2]
	     */, grgai[2], ngai[2], grg[2], ng[2], indbl[2], grbl1[2], nzbl1[
	    2], nbl1[40]	/* was [20][2] */, grbl2[2], nzbl2[2], nbl2[
	    60]	/* was [30][2] */, grblc[10]	/* was [5][2] */, nzblc[10]	
	    /* was [5][2] */, nblc[50]	/* was [5][5][2] */, pblc[30]	/* 
	    was [15][2] */, grbli[2], nbli[2];
} dald1_;

#define dald1_1 dald1_

struct {
    real zhgr1[40]	/* was [20][2] */, xgr1[1000]	/* was [500][2] */, 
	    ydgr1[1000]	/* was [500][2] */, zgr2[40]	/* was [20][2] */, 
	    xgr2[1000]	/* was [500][2] */, ydgr2[1000]	/* was [500][2] */, 
	    zgrc[320]	/* was [20][8][2] */, xgrc[2880]	/* was [180][
	    8][2] */, ygrc[2880]	/* was [180][8][2] */, zhld1[40]	
	    /* was [20][2] */, xld1[1000]	/* was [500][2] */, ydld1[
	    1000]	/* was [500][2] */, zld2[40]	/* was [20][2] */, 
	    xld2[1000]	/* was [500][2] */, ydld2[1000]	/* was [500][2] */, 
	    zldc[320]	/* was [20][8][2] */, xldc[2880]	/* was [180][
	    8][2] */, yldc[2880]	/* was [180][8][2] */;
    integer indgr[2], grgr1[2], nzgr1[2], ngr1[40]	/* was [20][2] */, 
	    grgr2[2], nzgr2[2], ngr2[40]	/* was [20][2] */, pgrc[30]	
	    /* was [15][2] */, grgrc[16]	/* was [8][2] */, nzgrc[16]	
	    /* was [8][2] */, ngrc[320]	/* was [20][8][2] */, indld[2], grld1[
	    2], nzld1[2], nld1[40]	/* was [20][2] */, grld2[2], nzld2[2],
	     nld2[40]	/* was [20][2] */, pldc[30]	/* was [15][2] */, 
	    grldc[16]	/* was [8][2] */, nzldc[16]	/* was [8][2] */, 
	    nldc[320]	/* was [20][8][2] */;
} dald2_;

#define dald2_1 dald2_

struct {
    real zhvt[40]	/* was [20][2] */, xtvt[1000]	/* was [500][2] */, 
	    ysvt[1000]	/* was [500][2] */, xtvti[20]	/* was [10][2] */, 
	    ytvti[20]	/* was [10][2] */, zfvr2[8], xwvr2[500], ysvr2[500], 
	    zfvg2[8], xwvg2[500], ysvg2[500], zfvr3[8], xwvr3[500], ysvr3[500]
	    , zfvg3[8], xwvg3[500], ysvg3[500], dvapp, dvman;
    integer grvt[2], nzvt[2], nvt[40]	/* was [20][2] */, grvti[2], nvti[2], 
	    grvr2[2], nvr2[16]	/* was [8][2] */, nzvr2[2], grvg2[2], nvg2[16]
	    	/* was [8][2] */, nzvg2[2], grvr3[2], nvr3[16]	/* was [8][2] 
	    */, nzvr3[2], grvg3[2], nvg3[16]	/* was [8][2] */, nzvg3[2];
    real xsvr1[1000]	/* was [500][2] */, ysvr1[1000]	/* was [500][2] */, 
	    zwvr1[30]	/* was [15][2] */, xsvg1[1000]	/* was [500][2] */, 
	    ysvg1[1000]	/* was [500][2] */, zwvg1[30]	/* was [15][2] */;
    integer grvr1[2], nzvr1[2], nvr1[30]	/* was [15][2] */, grvg1[2], 
	    nzvg1[2], nvg1[30]	/* was [15][2] */;
    real xvr1c[600]	/* was [100][3][2] */, yvr1c[600]	/* was [100][
	    3][2] */, zvr1c[60]	/* was [10][3][2] */, xvg1c[600]	/* 
	    was [100][3][2] */, yvg1c[600]	/* was [100][3][2] */, zvg1c[
	    60]	/* was [10][3][2] */;
    integer pvr1c[30]	/* was [15][2] */, grvr1c[6]	/* was [3][2] */, 
	    nzvr1c[6]	/* was [3][2] */, nvr1c[60]	/* was [10][3][2] */, 
	    pvg1c[30]	/* was [15][2] */, grvg1c[6]	/* was [3][2] */, 
	    nzvg1c[6]	/* was [3][2] */, nvg1c[60]	/* was [10][3][2] */;
} dald3_;

#define dald3_1 dald3_

struct {
    integer ierd, mil, iopxw, iopice, codv;
    real lgr1, ldt1, lgrc, ldtc, lflc, dist, vth1, vthc, vthm, vthr, add;
} resld_;

#define resld_1 resld_

struct {
    integer flaps, system[5], nobs, sup[4], nobp;
    real wmin, emw, aw, fact[2], gs, del_rwy__, del_obs__, dind, dind1, cbr, 
	    rwy, swy, cwy, slope, temp, wind, xwind, hp, xobs[30], hobs[30], 
	    xobp[30], hobp[30];
} ini1_;

#define ini1_1 ini1_

struct {
    integer ind, iobs[2], ifl, ilim[8]	/* was [4][2] */, nfp[2], senda[2], 
	    codef, coded[2], codev[2], codet, npc, fap, fld, fga;
    real x[15], wind_c__, oat1, oat2, mw, delcbr, vmcg[2], vr[2], v2[2], 
	    vfret[4]	/* was [2][2] */, fret[2], vfto[2], vman[2], vapp[2], 
	    vth[2], vga[2], grad[6]	/* was [3][2] */, rc[6]	/* was [3][2] 
	    */, tqto[2], itt[2], tqmc[2], tqga[2], v1[6]	/* was [3][2] 
	    */, asd[6]	/* was [3][2] */, tor[6]	/* was [3][2] */, tod[
	    6]	/* was [3][2] */, lgr[2], ld[2], lfl[2], cw[10], cv[10], cd[
	    15], xfp[32]	/* was [16][2] */, hfp[32]	/* was [16][2]
	     */, rcr, rfi, altacc[2], x2[15];
} ini2_;

#define ini2_1 ini2_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__50 = 50;
static integer c__5 = 5;
static integer c__100 = 100;
static integer c__10 = 10;
static real c_b63 = 1.f;
static integer c__6 = 6;

/* Subroutine */ int land_(char *vic, char *vid, integer *vii, real *vir, 
	integer *voi, real *vor, integer *ierr, ftnlen vic_len, ftnlen 
	vid_len)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_nint(real *);

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), manual3r_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, integer *);
    static integer i__, j, k, i1, n1, ie, kk[2];
    static real vl1, vl2, vl3, lda, gsr, vga1;
    static char vici[200];
    extern doublereal ldist_(real *);
    static integer verc, segl, cifsig, itemax;
    static real grad1, grad2, lgra, lgram, ldam, oatc, wxmin, error, vmcl, 
	    vkeas, vkcas, vmach, vktas, vktgs, vkias;
    static integer grcrw11, ncrw11, grcrw22, ncrw22;
    static real windref, xvcrw11[10], yscrw11[10], tempref, mlwreal, xvcrw22[
	    10], yscrw22[10], vgamin;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectl_(
	    char *, integer *, ftnlen), init_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), vldin_(integer 
	    *, integer *, real *, real *, real *, real *, integer *), corr_(
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *), zfalse_(E_fp, real *, integer *, real *, real *, real *, 
	    integer *, integer *), int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), ldspeed_(real *, real *, real *, 
	    integer *), convel_(real *, real *, real *, real *, real *, real *
	    , integer *, real *, real *, real *, real *, real *, real *, real 
	    *, integer *), escril_(integer *, real *, integer *, integer *, 
	    integer *, integer *, integer *);

/* MS$ATTRIBUTES DLLEXPORT :: LAND */
/* MS$ATTRIBUTES ALIAS: 'LAND' :: LAND */
/*      POINTER(PVIC,VIC) */
/*      POINTER(PVID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    *ierr = 0;
    resld_1.mil = vii[1] - 1;
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (resld_1.mil == 0 && s_cmp(afm_1.afm, afm_1.afm_lfar__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (resld_1.mil == 1 && s_cmp(afm_1.afm, afm_1.afm_lmil__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (resld_1.mil == 2 && s_cmp(afm_1.afm, afm_1.afm_ltac__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (*ierr > 0) {
	return 0;
    }
    init_(&c__2, &resld_1.mil, kk, &vii[1], &vir[1], &voi[1], &vor[1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    ini2_1.fld = ini1_1.flaps;
    resld_1.iopxw = 0;
    resld_1.iopice = 0;
    resld_1.vthm = 0.f;
    resld_1.vthr = 0.f;
    resld_1.add = 0.f;
    vldin_(&ini2_1.fld, &segl, &vmcl, &vga1, &grad1, &grad2, &ie);
    if (ie == 2) {
	goto L10000;
    }
    ini2_1.grad[0] = -999.f;
    ini2_1.grad[1] = -999.f;
    ini2_1.rc[0] = -999.f;
    ini2_1.rc[1] = -999.f;
    if (segl != 1 && segl != 0) {
	*ierr = 590;
	return 0;
    }
    if (segl == 0) {
	wxmin = 999999.f;
    } else if (resld_1.mil == 0 && ini1_1.gs == 2.1f) {
	ini2_1.grad[segl - 1] = 2.1f;
	ie = 0;
	oatc = ini2_1.oat1;
	if (ini1_1.system[1] == 1) {
	    manual2r_(&c__1, &ini2_1.oat1, &dald1_1.xtwi[ini2_1.ifl * 10 - 10]
		    , &dald1_1.ytwi[ini2_1.ifl * 10 - 10], &dald1_1.grwi[
		    ini2_1.ifl - 1], &dald1_1.nwi[ini2_1.ifl - 1], &oatc, &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__3, &dald1_1.grw[ini2_1.ifl - 1], &dald1_1.xww[
		ini2_1.ifl * 500 - 500], &dald1_1.ytw[ini2_1.ifl * 500 - 500],
		 &dald1_1.zhw[ini2_1.ifl * 20 - 20], &dald1_1.nw[ini2_1.ifl * 
		20 - 20], &dald1_1.nzw[ini2_1.ifl - 1], &vl1, &oatc, &
		ini1_1.hp, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__0, &vl1, &wxmin, ini2_1.x, &dald1_1.pwc[ini2_1.ifl * 
		15 - 15], &c__50, &c__5, &dald1_1.grwc[ini2_1.ifl * 5 - 5], &
		dald1_1.nzwc[ini2_1.ifl * 5 - 5], &dald1_1.nwc[(ini2_1.ifl * 
		5 + 1) * 5 - 30], &dald1_1.xwc[(ini2_1.ifl * 5 + 1) * 50 - 
		300], &dald1_1.ywc[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		dald1_1.zwc[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	if (ie == 2) {
	    goto L10000;
	}
	if (ini1_1.system[1] == 1) {
	    manual2r_(&c__1, &ini2_1.oat1, &dald1_1.xtwj[ini2_1.ifl * 10 - 10]
		    , &dald1_1.ywwj[ini2_1.ifl * 10 - 10], &dald1_1.grwj[
		    ini2_1.ifl - 1], &dald1_1.nwj[ini2_1.ifl - 1], &vl1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    wxmin += vl1;
	}
    } else if (ini1_1.gs <= 0.f) {
	wxmin = 999999.f;
    } else {
	ie = 0;
	if (ini1_1.gs > 20.f) {
	    manual2r_(&c__2, &ini2_1.grad[segl - 1], &dald1_1.xgg[ini2_1.ifl *
		     15 - 15], &dald1_1.ycg[ini2_1.ifl * 15 - 15], &
		    dald1_1.grg[ini2_1.ifl - 1], &dald1_1.ng[ini2_1.ifl - 1], 
		    &ini1_1.gs, &ie);
	    ini2_1.rc[segl - 1] = ini1_1.gs;
	} else if (ini1_1.gs > 0.f) {
	    manual2r_(&c__1, &ini1_1.gs, &dald1_1.xgg[ini2_1.ifl * 15 - 15], &
		    dald1_1.ycg[ini2_1.ifl * 15 - 15], &dald1_1.grg[
		    ini2_1.ifl - 1], &dald1_1.ng[ini2_1.ifl - 1], &ini2_1.rc[
		    segl - 1], &ie);
	    ini2_1.grad[segl - 1] = ini1_1.gs;
	}
	if (ie == 1) {
	    *ierr = 270;
	    return 0;
	}
	if (ie == 2) {
	    goto L10000;
	}
	gsr = ini2_1.grad[segl - 1];
	if (dald1_1.indga[ini2_1.ifl - 1] == 2) {
	    gsr = ini2_1.rc[segl - 1];
	}
	if (dald1_1.indga[ini2_1.ifl - 1] == 0) {
	    corr_(&ie, &c__1, &vl1, &gsr, ini2_1.x, &dald1_1.pgac[ini2_1.ifl *
		     15 - 15], &c__50, &c__5, &dald1_1.grgac[ini2_1.ifl * 5 - 
		    5], &dald1_1.nzgac[ini2_1.ifl * 5 - 5], &dald1_1.ngac[(
		    ini2_1.ifl * 5 + 1) * 5 - 30], &dald1_1.xgac[(ini2_1.ifl *
		     5 + 1) * 50 - 300], &dald1_1.ygac[(ini2_1.ifl * 5 + 1) * 
		    50 - 300], &dald1_1.zgac[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual3r_(&c__3, &dald1_1.grga2[ini2_1.ifl - 1], &dald1_1.xwga2[
		    ini2_1.ifl * 500 - 500], &dald1_1.yga2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgga2[ini2_1.ifl * 30 - 30], &dald1_1.nga2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzga2[ini2_1.ifl - 1], &
		    wxmin, &vl1, &grad1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	} else if (dald1_1.indga[ini2_1.ifl - 1] == 1 || dald1_1.indga[
		ini2_1.ifl - 1] == 2) {
	    manual3r_(&c__3, &dald1_1.grga2[ini2_1.ifl - 1], &dald1_1.xwga2[
		    ini2_1.ifl * 500 - 500], &dald1_1.yga2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgga2[ini2_1.ifl * 30 - 30], &dald1_1.nga2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzga2[ini2_1.ifl - 1], &
		    vl1, &grad1, &gsr, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl1, &wxmin, ini2_1.x, &dald1_1.pgac[
		    ini2_1.ifl * 15 - 15], &c__50, &c__5, &dald1_1.grgac[
		    ini2_1.ifl * 5 - 5], &dald1_1.nzgac[ini2_1.ifl * 5 - 5], &
		    dald1_1.ngac[(ini2_1.ifl * 5 + 1) * 5 - 30], &
		    dald1_1.xgac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.ygac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.zgac[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    *ierr = 560;
	    return 0;
	}
    }
    ini2_1.ilim[0] = 6;
    if (wxmin < ini1_1.wmin) {
	*ierr = 10;
	goto L2000;
    }
    wxmin = dmin(ini1_1.emw,wxmin);
    if (wxmin == ini1_1.emw) {
	ini2_1.ilim[0] = 1;
	ini2_1.grad[segl - 1] = -999.f;
    }
    if (ini1_1.del_rwy__ >= 0.f) {
	lgra = 999999.f;
	lgram = 999999.f;
	if (ini1_1.del_rwy__ == 0.f) {
	    lda = ini1_1.rwy;
	} else if (ini1_1.del_rwy__ <= 1.f) {
	    lda = ini1_1.rwy * ini1_1.del_rwy__;
	} else {
	    lda = ini1_1.rwy - ini1_1.del_rwy__;
	}
	ldam = ini1_1.rwy;
    } else {
	lda = 999999.f;
	ldam = 999999.f;
	vl1 = dabs(ini1_1.del_rwy__);
	if (vl1 <= 1.f) {
	    lgra = ini1_1.rwy * vl1;
	} else {
	    lgra = ini1_1.rwy - vl1;
	}
	lgram = ini1_1.rwy;
    }
    resld_1.dist = 0.f;
    vl1 = ldist_(&wxmin);
    if (resld_1.ierd == 2) {
	goto L10000;
    }
    if (resld_1.ierd == 600) {
	*ierr = 600;
	return 0;
    }
    ini2_1.lgr[ini2_1.ind - 1] = resld_1.lgrc;
    ini2_1.ld[ini2_1.ind - 1] = resld_1.ldtc;
    ini2_1.lfl[ini2_1.ind - 1] = resld_1.lflc;
    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
    error = .01f;
    cifsig = 5;
    itemax = 100;
    if (ini2_1.lgr[ini2_1.ind - 1] >= lgra || ini2_1.ld[ini2_1.ind - 1] >= 
	    lda) {
	ini2_1.grad[segl + ini2_1.ind * 3 - 4] = -999.f;
	ini2_1.ilim[0] = 3;
	if (ini2_1.lgr[ini2_1.ind - 1] >= lgra) {
	    resld_1.dist = lgra;
	    zfalse_((E_fp)ldist_, &error, &cifsig, &ini1_1.wmin, &wxmin, &vl1,
		     &itemax, &ie);
	    if (resld_1.ierd == 2) {
		goto L10000;
	    }
	    if (ie == 129) {
		if (ini2_1.ind == 2) {
		    *ierr = 550;
		    return 0;
		}
		*ierr = 10;
		goto L2000;
	    }
	    if (ie > 0) {
		*ierr = 510;
		return 0;
	    }
	    wxmin = vl1;
	    ini2_1.lgr[ini2_1.ind - 1] = lgra;
	    ini2_1.lfl[ini2_1.ind - 1] = ini1_1.rwy;
	    ini2_1.ld[ini2_1.ind - 1] = resld_1.ldtc;
	    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
	} else {
	    resld_1.dist = lda;
	    zfalse_((E_fp)ldist_, &error, &cifsig, &ini1_1.wmin, &wxmin, &vl1,
		     &itemax, &ie);
	    if (resld_1.ierd == 2) {
		goto L10000;
	    }
	    if (ie == 129) {
		if (ini2_1.ind == 2) {
		    *ierr = 550;
		    return 0;
		}
		*ierr = 10;
		goto L2000;
	    }
	    if (ie > 0) {
		*ierr = 510;
		return 0;
	    }
	    wxmin = vl1;
	    ini2_1.lgr[ini2_1.ind - 1] = resld_1.lgrc;
	    ini2_1.lfl[ini2_1.ind - 1] = ini1_1.rwy;
	    ini2_1.ld[ini2_1.ind - 1] = lda;
	    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
	}
    }
    if (ini1_1.aw >= ini1_1.wmin && ini1_1.aw < wxmin) {
	resld_1.dist = 0.f;
	vl1 = ldist_(&ini1_1.aw);
	if (resld_1.ierd == 2) {
	    goto L10000;
	}
	ini2_1.lfl[1] = resld_1.lflc;
    }
    if (ini1_1.xwind > 0.f) {
	resld_1.iopxw = 1;
	int2r_(&ini1_1.xwind, dagen3_1.xvcrdf1, dagen3_1.yfcrdf1, &c__1, &
		dagen3_1.ncrdf1, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if ((real) ini2_1.fld > vl1) {
	    ini2_1.fld = i_nint(&vl1);
	    ini2_1.codef = 1;
	}
	if (resld_1.mil > 0) {
	    grcrw11 = dagen3_1.grcrw1;
	    k = 1;
	    i__1 = dagen3_1.nzcrw1;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (i_nint(&dagen3_1.zfcrw1[i__ - 1]) == ini2_1.fld) {
		    k = i__;
		}
	    }
	    j = 0;
	    i__1 = k - 1;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		j += dagen3_1.ncrw1[i__ - 1];
	    }
	    ncrw11 = dagen3_1.ncrw1[k - 1];
	    i__1 = ncrw11;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		xvcrw11[i__ - 1] = dagen3_1.xvcrw1[j + i__ - 1];
		yscrw11[i__ - 1] = dagen3_1.yscrw1[j + i__ - 1];
	    }
	    grcrw22 = dagen3_1.grcrw2;
	    k = 1;
	    i__1 = dagen3_1.nzcrw2;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (i_nint(&dagen3_1.zfcrw2[i__ - 1]) == ini2_1.fld) {
		    k = i__;
		}
	    }
	    j = 0;
	    i__1 = k - 1;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		j += dagen3_1.ncrw2[i__ - 1];
	    }
	    ncrw22 = dagen3_1.ncrw2[k - 1];
	    i__1 = ncrw22;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		xvcrw22[i__ - 1] = dagen3_1.xvcrw2[j + i__ - 1];
		yscrw22[i__ - 1] = dagen3_1.yscrw2[j + i__ - 1];
	    }
	    if (ini1_1.xwind == xvcrw11[ncrw11 - 1]) {
		resld_1.vthm = yscrw11[ncrw11 - 1];
		if (xvcrw11[ncrw11 - 1] == xvcrw11[ncrw11 - 2]) {
		    resld_1.vthm = dagen3_1.yscrw1[ncrw11 - 2];
		}
	    } else if (ini1_1.xwind <= xvcrw11[0]) {
		resld_1.vthm = yscrw11[0];
	    } else {
		n1 = ncrw11;
		i1 = 1;
		if (xvcrw11[ncrw11 - 1] == xvcrw11[ncrw11 - 2]) {
		    --n1;
		}
		if (xvcrw11[0] == xvcrw11[1]) {
		    i1 = 2;
		    --n1;
		}
		int2r_(&ini1_1.xwind, &xvcrw11[i1 - 1], &yscrw11[i1 - 1], &
			c__1, &n1, &resld_1.vthm, &ie);
		if (ie == 2) {
		    goto L10000;
		}
	    }
	    if (ini1_1.xwind > xvcrw22[ncrw22 - 1]) {
		resld_1.vthr = 999.f;
	    } else if (ini1_1.xwind == xvcrw22[ncrw22 - 1]) {
		resld_1.vthr = yscrw22[ncrw22 - 1];
		if (xvcrw22[ncrw22 - 1] == xvcrw22[ncrw22 - 2]) {
		    resld_1.vthr = yscrw22[ncrw22 - 2];
		}
	    } else if (ini1_1.xwind <= xvcrw22[0]) {
		resld_1.vthr = yscrw22[0];
	    } else {
		n1 = ncrw22;
		i1 = 1;
		if (xvcrw22[ncrw22 - 1] == xvcrw22[ncrw22 - 2]) {
		    --n1;
		}
		if (xvcrw22[0] == xvcrw22[1]) {
		    i1 = 2;
		    --n1;
		}
		int2r_(&ini1_1.xwind, &xvcrw22[i1 - 1], &yscrw22[i1 - 1], &
			c__1, &n1, &resld_1.vthr, &ie);
		if (ie == 2) {
		    goto L10000;
		}
	    }
	}
	r__1 = (real) ini2_1.fld;
	int2r_(&r__1, dagen3_1.dff, dagen3_1.madff, &c__1, &dagen3_1.ndff, &
		resld_1.add, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	r__1 = (real) ini2_1.fld;
	ldspeed_(&r__1, &wxmin, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (ie == 600) {
	    *ierr = 600;
	    return 0;
	}
    }
    if (ini1_1.system[3] == 1) {
	resld_1.iopice = 1;
	ini2_1.x[10] = (real) ini1_1.system[3];
	if (ini2_1.codef == 1 && ini2_1.fld == dagen3_1.limdfk[0]) {
	    ini2_1.codef = 3;
	} else if (ini2_1.fld > dagen3_1.limdfk[0]) {
	    ini2_1.fld = dagen3_1.limdfk[0];
	    ini2_1.codef = 2;
	}
    }
    if (ini2_1.codef == 0) {
	if (ini1_1.xwind > 0.f) {
	    manual2r_(&c__1, &ini1_1.xwind, dagen3_1.xvcrdf2, 
		    dagen3_1.yfcrdf2, &dagen3_1.grcrdf2, &dagen3_1.ncrdf2, &
		    vl1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if ((real) ini2_1.fld > vl1) {
		ini2_1.codef = -1;
	    }
	}
	if (ini1_1.system[3] == 1) {
	    if (ini2_1.codef == -1 && ini2_1.fld > dagen3_1.limdfk[1]) {
		ini2_1.codef = -3;
	    } else if (ini2_1.fld > dagen3_1.limdfk[1]) {
		ini2_1.codef = -2;
	    }
	}
    }
    if (ini2_1.codef == 0 && ini1_1.system[3] == 0 && resld_1.codv == 0) {
	goto L1100;
    }
    if (ini2_1.codef > 0) {
	ini2_1.x[1] = (real) ini2_1.fld;
	i__1 = dagen3_1.ndf[1];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (ini2_1.fld == dagen3_1.df[i__ + 1]) {
		ini2_1.ifl = i__;
		goto L410;
	    }
	}
	if (resld_1.mil == 2) {
	    *ierr = 116;
	    return 0;
	}
	ini2_1.ifl = 1;
    }
L410:
    vldin_(&ini2_1.fld, &segl, &vmcl, &vga1, &grad1, &grad2, &ie);
    if (ie == 2) {
	goto L10000;
    }
L500:
    if (ini2_1.ind != 1 || ini2_1.ilim[0] != 6 || ini1_1.system[3] != 0) {
	ini2_1.grad[ini2_1.ind * 3 - 3] = -999.f;
	ini2_1.grad[ini2_1.ind * 3 - 2] = -999.f;
	ini2_1.rc[ini2_1.ind * 3 - 3] = -999.f;
	ini2_1.rc[ini2_1.ind * 3 - 2] = -999.f;
    }
    resld_1.dist = 0.f;
    vl1 = ldist_(&wxmin);
    if (resld_1.ierd == 2) {
	goto L10000;
    }
    if (resld_1.ierd == 600) {
	*ierr = 600;
	return 0;
    }
    ini2_1.lgr[ini2_1.ind - 1] = resld_1.lgrc;
    ini2_1.ld[ini2_1.ind - 1] = resld_1.ldtc;
    ini2_1.lfl[ini2_1.ind - 1] = resld_1.lflc;
    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
    ini2_1.codev[ini2_1.ind - 1] = resld_1.codv;
    if (ini1_1.del_rwy__ >= 0.f && ini2_1.ld[ini2_1.ind - 1] > lda || 
	    ini1_1.del_rwy__ < 0.f && ini2_1.lgr[ini2_1.ind - 1] > lgra) {
	ini2_1.coded[ini2_1.ind - 1] = 1;
	if (ini2_1.lgr[ini2_1.ind - 1] > lgram || ini2_1.ld[ini2_1.ind - 1] > 
		ldam) {
	    ini2_1.coded[ini2_1.ind - 1] = 2;
	    if (ini2_1.ind == 2) {
		if (ini1_1.xwind > 0.f && resld_1.mil != 0 && (r__1 = 
			ini2_1.vth[0] - ini2_1.vth[1], dabs(r__1)) < 3.f) {
		    ini2_1.lgr[1] = ini2_1.lgr[0];
		    ini2_1.ld[1] = ini2_1.ld[0];
		    ini2_1.lfl[1] = ini2_1.lfl[0];
		    ini2_1.codev[1] = ini2_1.codev[0];
		    ini2_1.coded[1] = ini2_1.coded[0];
		    goto L1100;
		} else {
		    *ierr = 550;
		}
	    }
	    if (resld_1.mil != 0) {
		error = .01f;
		cifsig = 5;
		itemax = 100;
		ini2_1.ilim[0] = 30;
		if (ini2_1.lgr[ini2_1.ind - 1] > lgram) {
		    resld_1.dist = lgram;
		    zfalse_((E_fp)ldist_, &error, &cifsig, &ini1_1.wmin, &
			    wxmin, &vl1, &itemax, &ie);
		    if (resld_1.ierd == 2) {
			goto L10000;
		    }
		    if (ie == 129) {
			*ierr = 10;
			goto L2000;
		    }
		    if (ie > 0) {
			*ierr = 510;
			return 0;
		    }
		    wxmin = vl1;
		    ini2_1.lgr[ini2_1.ind - 1] = lgram;
		    ini2_1.lfl[ini2_1.ind - 1] = lgram;
		    ini2_1.ld[ini2_1.ind - 1] = resld_1.ldtc;
		    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
		    ini2_1.codev[ini2_1.ind - 1] = resld_1.codv;
		} else {
		    resld_1.dist = ldam;
		    zfalse_((E_fp)ldist_, &error, &cifsig, &ini1_1.wmin, &
			    wxmin, &vl1, &itemax, &ie);
		    if (resld_1.ierd == 2) {
			goto L10000;
		    }
		    if (ie == 129) {
			*ierr = 10;
			goto L2000;
		    }
		    if (ie > 0) {
			*ierr = 510;
			return 0;
		    }
		    wxmin = vl1;
		    ini2_1.lgr[ini2_1.ind - 1] = resld_1.lgrc;
		    ini2_1.lfl[ini2_1.ind - 1] = ldam;
		    ini2_1.ld[ini2_1.ind - 1] = ldam;
		    ini2_1.vth[ini2_1.ind - 1] = resld_1.vthc;
		    ini2_1.codev[ini2_1.ind - 1] = resld_1.codv;
		}
	    }
	}
    }
L1100:
    if (ini2_1.grad[ini2_1.ind * 3 - 3] == -999.f && segl != 0 && ini1_1.gs > 
	    0.f && dald1_1.nzga1[ini2_1.ifl - 1] > 0) {
	if (ini1_1.system[3] == 1) {
	    for (i__ = 1; i__ <= 15; ++i__) {
		if (dald1_1.pgac[i__ + ini2_1.ifl * 15 - 16] == 11) {
		    goto L1200;
		}
	    }
	    goto L1220;
	}
L1200:
	if (dald1_1.indga[ini2_1.ifl - 1] == 0) {
	    manual3r_(&c__1, &dald1_1.grga2[ini2_1.ifl - 1], &dald1_1.xwga2[
		    ini2_1.ifl * 500 - 500], &dald1_1.yga2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgga2[ini2_1.ifl * 30 - 30], &dald1_1.nga2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzga2[ini2_1.ifl - 1], &
		    wxmin, &vl1, &grad1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl1, &ini2_1.grad[ini2_1.ind * 3 - 3], 
		    ini2_1.x, &dald1_1.pgac[ini2_1.ifl * 15 - 15], &c__50, &
		    c__5, &dald1_1.grgac[ini2_1.ifl * 5 - 5], &dald1_1.nzgac[
		    ini2_1.ifl * 5 - 5], &dald1_1.ngac[(ini2_1.ifl * 5 + 1) * 
		    5 - 30], &dald1_1.xgac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.ygac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.zgac[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (dald1_1.ng[ini2_1.ifl - 1] > 0) {
		manual2r_(&c__1, &ini2_1.grad[ini2_1.ind * 3 - 3], &
			dald1_1.xgg[ini2_1.ifl * 15 - 15], &dald1_1.ycg[
			ini2_1.ifl * 15 - 15], &dald1_1.grg[ini2_1.ifl - 1], &
			dald1_1.ng[ini2_1.ifl - 1], &ini2_1.rc[ini2_1.ind * 3 
			- 3], &ie);
	    }
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    corr_(&ie, &c__1, &vl1, &wxmin, ini2_1.x, &dald1_1.pgac[
		    ini2_1.ifl * 15 - 15], &c__50, &c__5, &dald1_1.grgac[
		    ini2_1.ifl * 5 - 5], &dald1_1.nzgac[ini2_1.ifl * 5 - 5], &
		    dald1_1.ngac[(ini2_1.ifl * 5 + 1) * 5 - 30], &
		    dald1_1.xgac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.ygac[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.zgac[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual3r_(&c__2, &dald1_1.grga2[ini2_1.ifl - 1], &dald1_1.xwga2[
		    ini2_1.ifl * 500 - 500], &dald1_1.yga2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgga2[ini2_1.ifl * 30 - 30], &dald1_1.nga2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzga2[ini2_1.ifl - 1], &
		    vl1, &grad1, &vl2, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (dald1_1.indga[ini2_1.ifl - 1] == 1) {
		ini2_1.grad[ini2_1.ind * 3 - 3] = vl2;
		if (dald1_1.ng[ini2_1.ifl - 1] > 0) {
		    manual2r_(&c__1, &ini2_1.grad[ini2_1.ind * 3 - 3], &
			    dald1_1.xgg[ini2_1.ifl * 15 - 15], &dald1_1.ycg[
			    ini2_1.ifl * 15 - 15], &dald1_1.grg[ini2_1.ifl - 
			    1], &dald1_1.ng[ini2_1.ifl - 1], &ini2_1.rc[
			    ini2_1.ind * 3 - 3], &ie);
		}
	    } else {
		ini2_1.rc[ini2_1.ind * 3 - 3] = vl2;
		if (dald1_1.ng[ini2_1.ifl - 1] > 0) {
		    manual2r_(&c__2, &ini2_1.grad[ini2_1.ind * 3 - 3], &
			    dald1_1.xgg[ini2_1.ifl * 15 - 15], &dald1_1.ycg[
			    ini2_1.ifl * 15 - 15], &dald1_1.grg[ini2_1.ifl - 
			    1], &dald1_1.ng[ini2_1.ifl - 1], &ini2_1.rc[
			    ini2_1.ind * 3 - 3], &ie);
		}
	    }
	    if (ie == 2) {
		goto L10000;
	    }
	}
    }
L1220:
    if (ini2_1.grad[ini2_1.ind * 3 - 2] == -999.f && segl != 0 && ini1_1.gs > 
	    0.f && dald1_1.nzbl1[ini2_1.ifl - 1] > 0) {
	if (ini1_1.system[3] == 1) {
	    for (i__ = 1; i__ <= 15; ++i__) {
		if (dald1_1.pblc[i__ + ini2_1.ifl * 15 - 16] == 11) {
		    goto L1240;
		}
	    }
	    goto L1300;
	}
L1240:
	ini2_1.x[0] = ini1_1.dind;
	if (dald1_1.indbl[ini2_1.ifl - 1] == 0) {
	    manual3r_(&c__1, &dald1_1.grbl2[ini2_1.ifl - 1], &dald1_1.xwbl2[
		    ini2_1.ifl * 500 - 500], &dald1_1.ybl2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgbl2[ini2_1.ifl * 30 - 30], &dald1_1.nbl2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzbl2[ini2_1.ifl - 1], &
		    wxmin, &vl1, &grad2, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl1, &ini2_1.grad[ini2_1.ind * 3 - 2], 
		    ini2_1.x, &dald1_1.pblc[ini2_1.ifl * 15 - 15], &c__50, &
		    c__5, &dald1_1.grblc[ini2_1.ifl * 5 - 5], &dald1_1.nzblc[
		    ini2_1.ifl * 5 - 5], &dald1_1.nblc[(ini2_1.ifl * 5 + 1) * 
		    5 - 30], &dald1_1.xblc[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.yblc[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.zblc[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	} else if (dald1_1.indbl[ini2_1.ifl - 1] == 1) {
	    corr_(&ie, &c__1, &vl1, &wxmin, ini2_1.x, &dald1_1.pblc[
		    ini2_1.ifl * 15 - 15], &c__50, &c__5, &dald1_1.grblc[
		    ini2_1.ifl * 5 - 5], &dald1_1.nzblc[ini2_1.ifl * 5 - 5], &
		    dald1_1.nblc[(ini2_1.ifl * 5 + 1) * 5 - 30], &
		    dald1_1.xblc[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.yblc[(ini2_1.ifl * 5 + 1) * 50 - 300], &
		    dald1_1.zblc[(ini2_1.ifl * 5 + 1) * 5 - 30]);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual3r_(&c__2, &dald1_1.grbl2[ini2_1.ifl - 1], &dald1_1.xwbl2[
		    ini2_1.ifl * 500 - 500], &dald1_1.ybl2[ini2_1.ifl * 500 - 
		    500], &dald1_1.zgbl2[ini2_1.ifl * 30 - 30], &dald1_1.nbl2[
		    ini2_1.ifl * 30 - 30], &dald1_1.nzbl2[ini2_1.ifl - 1], &
		    vl1, &grad2, &ini2_1.grad[ini2_1.ind * 3 - 2], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    *ierr = 560;
	    return 0;
	}
	ini2_1.x[0] = ini1_1.dind1;
    }
L1300:
    if (ini2_1.ind == 1) {
	r__1 = (real) ini2_1.fld;
	int2r_(&r__1, dagen3_1.dff, dagen3_1.apdff, &c__1, &dagen3_1.ndff, &
		vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.fap = i_nint(&vl1);
	r__1 = (real) ini2_1.fld;
	int2r_(&r__1, dagen3_1.dff, dagen3_1.gadff, &c__1, &dagen3_1.ndff, &
		vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.fga = i_nint(&vl1);
	ini2_1.codet = 0;
	if (resld_1.mil == 0) {
	    ini2_1.codet = 1;
	    if (ini2_1.codef > 0) {
		ini2_1.codet = 2;
	    }
	    vl1 = 0.f;
	    i__1 = dagen3_1.ndf[1];
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (ini2_1.fld == dagen3_1.df[i__ + 1]) {
		    vl1 = 1.f;
		}
	    }
	    if (vl1 == 0.f) {
		ini2_1.codet = 2;
	    }
	}
    }
    manual3r_(&c__3, dald3_1.grvg1, dald3_1.xsvg1, dald3_1.ysvg1, 
	    dald3_1.zwvg1, dald3_1.nvg1, dald3_1.nzvg1, &vl1, &vga1, &wxmin, &
	    ie);
    if (ie == 2) {
	return 0;
    }
    corr_(&ie, &c__0, &vl1, &vgamin, ini2_1.x, &dald3_1.pvg1c[ini2_1.ifl * 15 
	    - 15], &c__100, &c__10, &dald3_1.grvg1c[ini2_1.ifl * 3 - 3], &
	    dald3_1.nzvg1c[ini2_1.ifl * 3 - 3], &dald3_1.nvg1c[(ini2_1.ifl * 
	    3 + 1) * 10 - 40], &dald3_1.xvg1c[(ini2_1.ifl * 3 + 1) * 100 - 
	    400], &dald3_1.yvg1c[(ini2_1.ifl * 3 + 1) * 100 - 400], &
	    dald3_1.zvg1c[(ini2_1.ifl * 3 + 1) * 10 - 40]);
    if (ie == 2) {
	return 0;
    }
    if (ini1_1.system[3] == 0) {
	r__1 = (real) ini2_1.fga;
	manual3r_(&c__1, dald3_1.grvg2, dald3_1.xwvg2, dald3_1.ysvg2, 
		dald3_1.zfvg2, dald3_1.nvg2, dald3_1.nzvg2, &wxmin, &vl1, &
		r__1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.vga[ini2_1.ind - 1] = vgamin;
	if (vl1 > ini2_1.vga[ini2_1.ind - 1]) {
	    ini2_1.vga[ini2_1.ind - 1] = vl1;
	}
    } else {
	r__1 = (real) ini2_1.fga;
	manual3r_(&c__1, dald3_1.grvg3, dald3_1.xwvg3, dald3_1.ysvg3, 
		dald3_1.zfvg3, dald3_1.nvg3, dald3_1.nzvg3, &wxmin, &vl1, &
		r__1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.vga[ini2_1.ind - 1] = vgamin;
	if (vl1 > ini2_1.vga[ini2_1.ind - 1]) {
	    ini2_1.vga[ini2_1.ind - 1] = vl1;
	}
    }
    r__1 = (real) ini2_1.fap;
    ldspeed_(&r__1, &wxmin, &ini2_1.vapp[ini2_1.ind - 1], &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (ie == 600) {
	*ierr = 600;
	return 0;
    }
    ini2_1.vapp[ini2_1.ind - 1] += dald3_1.dvapp;
    if (ini2_1.codev[ini2_1.ind - 1] == 1 || ini2_1.codev[ini2_1.ind - 1] == 
	    3) {
	if (ini2_1.vapp[ini2_1.ind - 1] < ini2_1.vth[ini2_1.ind - 1]) {
	    ini2_1.vapp[ini2_1.ind - 1] = ini2_1.vth[ini2_1.ind - 1];
	}
    }
    ini2_1.vman[ini2_1.ind - 1] = ini2_1.vapp[ini2_1.ind - 1] + dald3_1.dvman;
    r__1 = (real) ini2_1.fap;
    int2r_(&r__1, dagen3_1.dff, dagen3_1.limdff, &c__1, &dagen3_1.ndff, &vl1, 
	    &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (ini2_1.vman[ini2_1.ind - 1] > vl1) {
	ini2_1.vman[ini2_1.ind - 1] = vl1;
    }
    r__1 = (real) ini2_1.fga;
    int2r_(&r__1, dagen3_1.dff, dagen3_1.limdff, &c__1, &dagen3_1.ndff, &vl1, 
	    &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (ini2_1.vga[ini2_1.ind - 1] > vl1) {
	if (ini2_1.vga[ini2_1.ind - 1] - vl1 < 5.f) {
	    ini2_1.vga[ini2_1.ind - 1] = vl1;
	} else {
	    *ierr = 600;
	    return 0;
	}
    }
    if (ini2_1.vman[ini2_1.ind - 1] > dagen3_1.limlg) {
	ini2_1.vman[ini2_1.ind - 1] = dagen3_1.limlg;
	if (ini2_1.vapp[ini2_1.ind - 1] > dagen3_1.limlg) {
	    if (ini2_1.vapp[ini2_1.ind - 1] - dagen3_1.limlg < 5.f) {
		ini2_1.vapp[ini2_1.ind - 1] = dagen3_1.limlg;
	    } else {
		*ierr = 600;
		return 0;
	    }
	}
	if (ini2_1.vth[ini2_1.ind - 1] > dagen3_1.limlg) {
	    if (ini2_1.vth[ini2_1.ind - 1] - dagen3_1.limlg < 5.f) {
		ini2_1.vth[ini2_1.ind - 1] = dagen3_1.limlg;
	    } else {
		*ierr = 600;
		return 0;
	    }
	}
	if (ini2_1.vga[ini2_1.ind - 1] > dagen3_1.limlg) {
	    if (ini2_1.vga[ini2_1.ind - 1] - dagen3_1.limlg < 5.f) {
		ini2_1.vga[ini2_1.ind - 1] = dagen3_1.limlg;
	    } else {
		*ierr = 600;
		return 0;
	    }
	}
    }
    if (dagen3_1.limty > 0.f) {
	r__1 = (real) ini2_1.fld;
	convel_(&c_b63, &ini2_1.oat1, &ini1_1.hp, &wxmin, &r__1, &ini1_1.wind,
		 &c__6, &ini2_1.vth[ini2_1.ind - 1], &vkeas, &vkcas, &vmach, &
		vktas, &vktgs, &vkias, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (ie > 0) {
	    *ierr = ie;
	    return 0;
	}
	vl1 = vktgs * .95f * 1.1516f;
    }
    if (ini2_1.vman[ini2_1.ind - 1] < ini2_1.vapp[ini2_1.ind - 1] || 
	    ini2_1.vman[ini2_1.ind - 1] < ini2_1.vth[ini2_1.ind - 1] || 
	    ini2_1.vapp[ini2_1.ind - 1] < ini2_1.vth[ini2_1.ind - 1]) {
	*ierr = 605;
	return 0;
    }
    if (ini2_1.vth[ini2_1.ind - 1] < resld_1.vthm) {
	*ierr = 242;
	return 0;
    }
    if (ini2_1.ind == 1) {
	if (ini1_1.system[1] == 0) {
	    manual3r_(&c__1, &dagen1_1.grtqg, dagen1_1.xttqg, dagen1_1.yqtqg, 
		    dagen1_1.zhtqg, dagen1_1.ntqg, &dagen1_1.nztqg, &
		    ini2_1.oat1, &ini2_1.tqga[ini2_1.ind - 1], &ini1_1.hp, &
		    ie);
	} else {
	    if (dagen1_1.nztqgi > 1) {
		manual3r_(&c__1, &dagen1_1.grtqgi, dagen1_1.xttqgi, 
			dagen1_1.yqtqgi, dagen1_1.zhtqgi, dagen1_1.ntqgi, &
			dagen1_1.nztqgi, &ini2_1.oat1, &ini2_1.tqga[
			ini2_1.ind - 1], &ini1_1.hp, &ie);
	    } else {
		manual3r_(&c__1, &dagen1_1.grtqgi, dagen1_1.xttqgi, 
			dagen1_1.yqtqgi, dagen1_1.zhtqgi, dagen1_1.ntqgi, &
			dagen1_1.nztqgi, &ini2_1.oat1, &vl1, dagen1_1.zhtqgi, 
			&ie);
		if (ie == 2) {
		    goto L10000;
		}
		manual3r_(&c__1, &dagen1_1.grtqg, dagen1_1.xttqg, 
			dagen1_1.yqtqg, dagen1_1.zhtqg, dagen1_1.ntqg, &
			dagen1_1.nztqg, &vl1, &ini2_1.tqga[ini2_1.ind - 1], &
			ini1_1.hp, &ie);
	    }
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (ini1_1.system[1] == 0) {
	    manual3r_(&c__1, &dagen1_1.grtqm, dagen1_1.xttqm, dagen1_1.yqtqm, 
		    dagen1_1.zhtqm, dagen1_1.ntqm, &dagen1_1.nztqm, &
		    ini2_1.oat1, &ini2_1.tqmc[ini2_1.ind - 1], &ini1_1.hp, &
		    ie);
	} else {
	    if (dagen1_1.nztqmi > 1) {
		manual3r_(&c__1, &dagen1_1.grtqmi, dagen1_1.xttqmi, 
			dagen1_1.yqtqmi, dagen1_1.zhtqmi, dagen1_1.ntqmi, &
			dagen1_1.nztqmi, &ini2_1.oat1, &ini2_1.tqmc[
			ini2_1.ind - 1], &ini1_1.hp, &ie);
	    } else {
		manual3r_(&c__1, &dagen1_1.grtqmi, dagen1_1.xttqmi, 
			dagen1_1.yqtqmi, dagen1_1.zhtqmi, dagen1_1.ntqmi, &
			dagen1_1.nztqmi, &ini2_1.oat1, &vl1, dagen1_1.zhtqmi, 
			&ie);
		if (ie == 2) {
		    goto L10000;
		}
		manual3r_(&c__1, &dagen1_1.grtqm, dagen1_1.xttqm, 
			dagen1_1.yqtqm, dagen1_1.zhtqm, dagen1_1.ntqm, &
			dagen1_1.nztqm, &vl1, &ini2_1.tqmc[ini2_1.ind - 1], &
			ini1_1.hp, &ie);
	    }
	}
	if (ie == 2) {
	    goto L10000;
	}
	r__1 = ini1_1.wmin / 1e3f;
	vl1 = i_nint(&r__1) * 1e3f;
	r__1 = ini1_1.emw / 500.f;
	vl2 = i_nint(&r__1) * 500.f;
	vl3 = 1e3f;
	if (vl2 - vl1 > 9e3f) {
	    vl3 = 2e3f;
	}
	ini2_1.npc = 0;
	for (i__ = 1; i__ <= 10; ++i__) {
	    if (i__ == 1) {
		ini2_1.cw[i__ - 1] = vl1;
	    } else {
		ini2_1.cw[i__ - 1] = ini2_1.cw[i__ - 2] + vl3;
	    }
	    if (ini2_1.cw[i__ - 1] > vl2) {
		if (ini2_1.cw[i__ - 2] == vl2) {
		    goto L1800;
		}
		ini2_1.cw[i__ - 1] = vl2;
	    }
	    ++ini2_1.npc;
	    r__1 = (real) dagen3_1.df[ini2_1.ifl + 1];
	    manual3r_(&c__1, dald3_1.grvr2, dald3_1.xwvr2, dald3_1.ysvr2, 
		    dald3_1.zfvr2, dald3_1.nvr2, dald3_1.nzvr2, &ini2_1.cw[
		    i__ - 1], &ini2_1.cv[i__ - 1], &r__1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (resld_1.vth1 > ini2_1.cv[i__ - 1]) {
		ini2_1.cv[i__ - 1] = resld_1.vth1;
	    }
	}
L1800:
	mlwreal = wxmin;
	ini2_1.mw = (real) i_nint(&wxmin);
	if (ini1_1.aw > 0.f) {
	    if (ini1_1.aw < ini1_1.wmin) {
		*ierr = 30;
	    } else if (ini1_1.aw > ini2_1.mw) {
		ini2_1.lfl[1] = 0.f;
		ini2_1.rc[3] = 0.f;
		ini2_1.rc[4] = 0.f;
		*ierr = 20;
	    } else if (ini1_1.aw < ini2_1.mw) {
		wxmin = ini1_1.aw;
		ini2_1.ind = 2;
		ini2_1.tqga[1] = ini2_1.tqga[0];
		ini2_1.tqmc[1] = ini2_1.tqmc[0];
		goto L500;
	    }
	}
    }
    windref = ini1_1.wind;
    tempref = ini1_1.temp;
    wxmin = mlwreal;
    if (*ierr == 0 && ini1_1.aw > 0.f && ini1_1.aw != ini2_1.mw) {
	wxmin = ini1_1.aw;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ini1_1.wind = windref + (real) (i__ - 2) * 5.f;
	for (j = 1; j <= 5; ++j) {
	    ini1_1.temp = tempref + (real) (j - 3) * 5.f;
	    init_(&c__0, &resld_1.mil, kk, &vii[1], &vir[1], &voi[1], &vor[1],
		     &ie);
	    if (ie > 0) {
		ini2_1.cd[(i__ - 1) * 5 + j - 1] = -((real) ie);
	    } else {
		vldin_(&ini2_1.fld, &segl, &vmcl, &vga1, &grad1, &grad2, &ie);
		if (ie == 2) {
		    goto L10000;
		}
		resld_1.dist = 0.f;
		vl1 = ldist_(&wxmin);
		if (resld_1.ierd == 2) {
		    goto L10000;
		}
		if (resld_1.ierd == 600) {
		    *ierr = 600;
		    return 0;
		}
		if (ini1_1.del_rwy__ >= 0.f) {
		    ini2_1.cd[(i__ - 1) * 5 + j - 1] = resld_1.ldtc;
		} else {
		    ini2_1.cd[(i__ - 1) * 5 + j - 1] = resld_1.lgrc;
		}
	    }
	}
    }
    ini1_1.wind = windref;
    ini1_1.temp = tempref;
    ie = 1;
    if (*ierr == 0 && ini1_1.aw > 0.f && ini1_1.aw != ini2_1.mw) {
	ie = 2;
	if (ini1_1.xwind > 0.f && resld_1.mil != 0 && ini2_1.lgr[0] == 
		ini2_1.lgr[1] && ini2_1.ld[0] == ini2_1.ld[1]) {
	    if (ini1_1.del_rwy__ >= 0.f) {
		vl1 = ini2_1.ld[0];
	    } else {
		vl1 = ini2_1.lgr[0];
	    }
	    vl1 -= ini2_1.cd[7];
	    for (i__ = 1; i__ <= 15; ++i__) {
		if (ini2_1.cd[i__ - 1] > 0.f) {
		    ini2_1.cd[i__ - 1] += vl1;
		}
	    }
	}
    }
    if (ini1_1.del_rwy__ >= 0.f) {
	vl1 = ini2_1.ld[ie - 1];
    } else {
	vl1 = ini2_1.lgr[ie - 1];
    }
    if ((r__1 = vl1 - ini2_1.cd[7], dabs(r__1)) > 1.f) {
	*ierr = 620;
	return 0;
    } else {
	ini2_1.cd[7] = vl1;
    }
L2000:
    escril_(&voi[1], &vor[1], ierr, &dagen3_1.iopk, &segl, &verc, &
	    dagen3_1.verd[1]);
    return 0;
L10000:
    *ierr = 500;
    return 0;
} /* land_ */

/* Subroutine */ int land_lim__(char *vic, char *vid, integer *vii, real *vor,
	 integer *ierr, ftnlen vic_len, ftnlen vid_len)
{
    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer ie;
    static char vici[200];
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lectl_(
	    char *, integer *, ftnlen);

    /* Parameter adjustments */
    --vor;
    --vii;

    /* Function Body */
    *ierr = 0;
    resld_1.mil = vii[1] - 1;
    ie = i_indx(vic, "\000", (ftnlen)200, (ftnlen)1) - 1;
    s_copy(vici, vic, (ftnlen)200, ie);
    s_copy(afm_1.afm, vid, (ftnlen)6, (ftnlen)6);
    if (s_cmp(afm_1.afm, afm_1.afm_dat__, (ftnlen)6, (ftnlen)6) != 0) {
	lectg_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    if (resld_1.mil == 0 && s_cmp(afm_1.afm, afm_1.afm_lfar__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (resld_1.mil == 1 && s_cmp(afm_1.afm, afm_1.afm_lmil__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (resld_1.mil == 2 && s_cmp(afm_1.afm, afm_1.afm_ltac__, (ftnlen)6, (
	    ftnlen)6) != 0) {
	lectl_(vici, ierr, (ftnlen)200);
    }
    if (*ierr > 0) {
	return 0;
    }
    *ierr = 0;
/*     LIMALT MIN(1,1) MAX(2,1) */
    vor[1] = dagen3_1.limalt[0];
    vor[2] = dagen3_1.limalt[1];
    return 0;
} /* land_lim__ */

