/* SCAD.F -- translated by f2c (version 20100827).
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
    real zhw[40]	/* was [20][2] */, xww[1000]	/* was [500][2] */, 
	    ytw[1000]	/* was [500][2] */, xtwi[20]	/* was [10][2] */, 
	    ytwi[20]	/* was [10][2] */, xtwj[20]	/* was [10][2] */, 
	    ywwj[20]	/* was [10][2] */, zhfc1[40]	/* was [20][2] */, 
	    xtfc1[1000]	/* was [500][2] */, ygfc1[1000]	/* was [500][2] */, 
	    zgfc2[30]	/* was [15][2] */, xwfc2[1000]	/* was [500][2] */, 
	    ygfc2[1000]	/* was [500][2] */, zgfc3[10]	/* was [5][2] */, 
	    xrfc3[20]	/* was [10][2] */, ygfc3[20]	/* was [10][2] */, 
	    xtfi[20]	/* was [10][2] */, ytfi[20]	/* was [10][2] */, 
	    zhg21[40]	/* was [20][2] */, xtg21[1000]	/* was [500][2] */, 
	    yg21[1000]	/* was [500][2] */, zg22[60]	/* was [30][2] */, 
	    xwg22[1500]	/* was [750][2] */, yg22[1500]	/* was [750][2] */, 
	    xtg2i[20]	/* was [10][2] */, ytg2i[20]	/* was [10][2] */, 
	    xgg[30]	/* was [15][2] */, ycg[30]	/* was [15][2] */, 
	    dgrs1[2], drcs1[2], zhw21[40]	/* was [20][2] */, xww21[1000]
	    	/* was [500][2] */, ytw21[1000]	/* was [500][2] */, zgw22[60]	
	    /* was [30][2] */, xww22[600]	/* was [300][2] */, yww22[600]
	    	/* was [300][2] */, xtw2i[20]	/* was [10][2] */, ytw2i[20]	
	    /* was [10][2] */;
    integer grw[2], nzw[2], nw[40]	/* was [20][2] */, grwi[2], nwi[2], 
	    grwj[2], nwj[2], grfc1[2], nzfc1[2], nfc1[40]	/* was [20][2]
	     */, grfc2[2], nzfc2[2], nfc2[30]	/* was [15][2] */, grfc3[2], 
	    nzfc3[2], nfc3[10]	/* was [5][2] */, grfi[2], nfi[2], indg2, 
	    grg21[2], nzg21[2], ng21[40]	/* was [20][2] */, grg22[2], 
	    nzg22[2], ng22[60]	/* was [30][2] */, grg2i[2], ng2i[2], grg[2], 
	    ng[2], grw21[2], nzw21[2], nw21[40]	/* was [20][2] */, grw22[2], 
	    nzw22[2], nw22[60]	/* was [30][2] */, grw2i[2], nw2i[2];
    real zwc[120]	/* was [15][4][2] */, xwc[800]	/* was [100][4][2] */,
	     ywc[800]	/* was [100][4][2] */, zfcc[120]	/* was [15][4]
	    [2] */, xfcc[800]	/* was [100][4][2] */, yfcc[800]	/* 
	    was [100][4][2] */, zg2c[120]	/* was [15][4][2] */, xg2c[
	    800]	/* was [100][4][2] */, yg2c[800]	/* was [100][
	    4][2] */;
    integer grwc[8]	/* was [4][2] */, nzwc[8]	/* was [4][2] */, nwc[
	    120]	/* was [15][4][2] */, grfcc[8]	/* was [4][2] */, 
	    nzfcc[8]	/* was [4][2] */, nfcc[120]	/* was [15][4][2] */, 
	    grg2c[8]	/* was [4][2] */, nzg2c[8]	/* was [4][2] */, 
	    ng2c[120]	/* was [15][4][2] */, pwc[30]	/* was [15][2] */, 
	    pfcc[30]	/* was [15][2] */, pg2c[30]	/* was [15][2] */;
    real zgc[120]	/* was [15][4][2] */, xgc[800]	/* was [100][4][2] */,
	     ygc[120]	/* was [15][4][2] */, zdgrs1c[120]	/* was [15][4]
	    [2] */, xdgrs1c[800]	/* was [100][4][2] */, ydgrs1c[800]	
	    /* was [100][4][2] */, zdrcs1c[120]	/* was [15][4][2] */, xdrcs1c[
	    800]	/* was [100][4][2] */, ydrcs1c[800]	/* was [100][
	    4][2] */;
    integer pgc[30]	/* was [15][2] */, grgc[8]	/* was [4][2] */, 
	    nzgc[8]	/* was [4][2] */, ngc[120]	/* was [15][4][2] */, 
	    pdgrs1c[30]	/* was [15][2] */, grdgrs1c[8]	/* was [4][2] */, 
	    nzdgrs1c[8]	/* was [4][2] */, ndgrs1c[120]	/* was [15][4][2] */, 
	    pdrcs1c[30]	/* was [15][2] */, grdrcs1c[8]	/* was [4][2] */, 
	    nzdrcs1c[8]	/* was [4][2] */, ndrcs1c[120]	/* was [15][4][2] */;
    real zw2c[120]	/* was [15][4][2] */, xw2c[800]	/* was [100][4][2] */,
	     yw2c[800]	/* was [100][4][2] */;
    integer pw2c[30]	/* was [15][2] */, grw2c[8]	/* was [4][2] */, 
	    nzw2c[8]	/* was [4][2] */, nw2c[120]	/* was [15][4][2] */, 
	    igam;
} dato1_;

#define dato1_1 dato1_

struct {
    real ztod[300]	/* was [15][10][2] */, xtod[1500]	/* was [75][
	    10][2] */, ytod[1500]	/* was [75][10][2] */, zasd[300]	
	    /* was [15][10][2] */, xasd[1500]	/* was [75][10][2] */, yasd[
	    1500]	/* was [75][10][2] */, ztor[300]	/* was [15][
	    10][2] */, xtor[1500]	/* was [75][10][2] */, ytor[1500]	
	    /* was [75][10][2] */, zhwd1[40]	/* was [20][2] */, xtwd1[1000]
	    	/* was [500][2] */, ywwd1[1000]	/* was [500][2] */, zdwd2[50]	
	    /* was [25][2] */, xwwd2[400]	/* was [200][2] */, ywwd2[400]
	    	/* was [200][2] */, xtwdi[30]	/* was [15][2] */, ytwdi[30]	
	    /* was [15][2] */, zsv1r[40]	/* was [20][2] */, xsv1r[100]	
	    /* was [50][2] */, ysv1r[100]	/* was [50][2] */, masd[30]	
	    /* was [15][2] */, mtor[30]	/* was [15][2] */, mtod[30]	/* 
	    was [15][2] */;
    integer grtod[20]	/* was [10][2] */, nztod[20]	/* was [10][2] */, 
	    ntod[300]	/* was [15][10][2] */, grasd[20]	/* was [10][2]
	     */, nzasd[20]	/* was [10][2] */, nasd[300]	/* was [15][
	    10][2] */, grtor[20]	/* was [10][2] */, nztor[20]	/* 
	    was [10][2] */, ntor[300]	/* was [15][10][2] */, grwd1[2], 
	    nzwd1[2], nwd1[40]	/* was [20][2] */, grwd2[2], nzwd2[2], nwd2[
	    50]	/* was [25][2] */, grwdi[2], nwdi[2], grv1r[2], nzv1r[2], 
	    nv1r[40]	/* was [20][2] */, ptod[30]	/* was [15][2] */, 
	    pasd[30]	/* was [15][2] */, ptor[30]	/* was [15][2] */;
} dato2_;

#define dato2_1 dato2_

struct {
    real zhgr1[40]	/* was [20][2] */, xdgr1[1000]	/* was [500][2] */, 
	    ytgr1[1000]	/* was [500][2] */, zwgr2[40]	/* was [20][2] */, 
	    xdgr2[1000]	/* was [500][2] */, ydgr2[1000]	/* was [500][2] */, 
	    zgrc[400]	/* was [20][10][2] */, xgrc[3000]	/* was [150][
	    10][2] */, ygrc[3000]	/* was [150][10][2] */, zhtd1[40]	
	    /* was [20][2] */, xdtd1[1000]	/* was [500][2] */, yttd1[
	    1000]	/* was [500][2] */, zwtd2[40]	/* was [20][2] */, 
	    xdtd2[1000]	/* was [500][2] */, ydtd2[1000]	/* was [500][2] */, 
	    ztdc[240]	/* was [15][8][2] */, xtdc[2400]	/* was [150][
	    8][2] */, ytdc[2400]	/* was [150][8][2] */, zfda1[20]	
	    /* was [10][2] */, xgda1[400]	/* was [200][2] */, ydda1[400]
	    	/* was [200][2] */;
    integer grgr1[2], nzgr1[2], ngr1[40]	/* was [20][2] */, grgr2[2], 
	    nzgr2[2], ngr2[40]	/* was [20][2] */, grgrc[20]	/* was [10][2]
	     */, nzgrc[20]	/* was [10][2] */, ngrc[400]	/* was [20][
	    10][2] */, grtd1[2], nztd1[2], ntd1[40]	/* was [20][2] */, 
	    grtd2[2], nztd2[2], ntd2[40]	/* was [20][2] */, grtdc[16]	
	    /* was [8][2] */, nztdc[16]	/* was [8][2] */, ntdc[240]	/* 
	    was [15][8][2] */, pgrc[30]	/* was [15][2] */, ptdc[30]	/* 
	    was [15][2] */, grda1[2], nzda1[2], nda1[20]	/* was [10][2]
	     */, pda1c[30]	/* was [15][2] */, grda1c[8]	/* was [4][2] 
	    */, nzda1c[8]	/* was [4][2] */, nda1c[120]	/* was [15][4]
	    [2] */;
    real zda1c[120]	/* was [15][4][2] */, xda1c[800]	/* was [100][
	    4][2] */, yda1c[800]	/* was [100][4][2] */;
} dato3_;

#define dato3_1 dato3_

struct {
    real zhvr1[40]	/* was [20][2] */, xtvr1[1000]	/* was [500][2] */, 
	    ysvr1[1000]	/* was [500][2] */, zdvr2[40]	/* was [20][2] */, 
	    xsvr2[1000]	/* was [500][2] */, ysvr2[1000]	/* was [500][2] */, 
	    zwvr3[20]	/* was [10][2] */, xsvr3[400]	/* was [200][2] */, 
	    ysvr3[400]	/* was [200][2] */, zvrc[480]	/* was [30][8][2] */, 
	    xvrc[6400]	/* was [400][8][2] */, yvrc[6400]	/* was [400][
	    8][2] */;
    integer grvr1[2], nzvr1[2], nvr1[40]	/* was [20][2] */, grvr2[2], 
	    nzvr2[2], nvr2[40]	/* was [20][2] */, grvr3[2], nzvr3[2], nvr3[
	    20]	/* was [10][2] */, grvrc[16]	/* was [8][2] */, nzvrc[16]	
	    /* was [8][2] */, nvrc[480]	/* was [30][8][2] */, pvrc[30]	/* 
	    was [15][2] */;
} dato4_;

#define dato4_1 dato4_

struct {
    real zhvt[40]	/* was [20][2] */, xtvt[1000]	/* was [500][2] */, 
	    ysvt[1000]	/* was [500][2] */, zwvro2[32]	/* was [16][2] */, 
	    xsvro2[1000]	/* was [500][2] */, ysvro2[1000]	/* 
	    was [500][2] */, xwvro3[100]	/* was [50][2] */, ysvro3[100]
	    	/* was [50][2] */, xwv22[100]	/* was [50][2] */, ysv22[100]	
	    /* was [50][2] */, ysvrf1[32]	/* was [16][2] */, ysvrf2[32]	
	    /* was [16][2] */, ysvfto[32]	/* was [16][2] */, xtvti[32]	
	    /* was [16][2] */, ytvti[32]	/* was [16][2] */, zhvmg[40]	
	    /* was [20][2] */, xtvmg[1000]	/* was [500][2] */, ysvmg[
	    1000]	/* was [500][2] */;
    integer grvt[2], nzvt[2], nvt[40]	/* was [20][2] */, grvro2[2], nzvro2[
	    2], nvro2[32]	/* was [16][2] */, grvro3[2], nvro3[2], grv22[
	    2], nv22[2], grvrf1[2], grvrf2[2], grvfto[2], grvti[2], nvti[2];
    real dfret[2], dvrf1[2], dvrf2[2], dvfto[2];
    integer nzvmg[20], nvmg[40]	/* was [20][2] */, grvmg[2];
    real zwvro1[30]	/* was [15][2] */, xsvro1[1000]	/* was [500][2] */, 
	    ysvro1[1000]	/* was [500][2] */, zwv21[30]	/* was [15][2]
	     */, xsv21[1000]	/* was [500][2] */, ysv21[1000]	/* was [500][
	    2] */;
    integer grvro1[2], nzvro1[2], nvro1[30]	/* was [15][2] */, grv21[2], 
	    nzv21[2], nv21[30]	/* was [15][2] */;
    real zvroc[90]	/* was [15][3][2] */, xvroc[600]	/* was [100][
	    3][2] */, yvroc[600]	/* was [100][3][2] */, zv2c[90]	/* 
	    was [15][3][2] */, xv2c[600]	/* was [100][3][2] */, yv2c[
	    600]	/* was [100][3][2] */;
    integer pvroc[30]	/* was [15][2] */, grvroc[6]	/* was [3][2] */, 
	    nzvroc[6]	/* was [3][2] */, nvroc[90]	/* was [15][3][2] */, 
	    pv2c[30]	/* was [15][2] */, grv2c[6]	/* was [3][2] */, 
	    nzv2c[6]	/* was [3][2] */, nv2c[90]	/* was [15][3][2] */;
    real xdvrf1c[20]	/* was [10][2] */, ydvrf1c[20]	/* was [10][2] */, 
	    xdvrf2c[20]	/* was [10][2] */, ydvrf2c[20]	/* was [10][2] */, 
	    xdvftoc[20]	/* was [10][2] */, ydvftoc[20]	/* was [10][2] */;
    integer grdvrf1c[2], grdvrf2c[2], grdvftoc[2], ndvrf1c[2], ndvrf2c[2], 
	    ndvftoc[2];
} dato5_;

#define dato5_1 dato5_

struct {
    real zgfp1[200]	/* was [100][2] */, xdfp1[3000]	/* was [1500][2] */, 
	    yhfp1[3000]	/* was [1500][2] */, zdfp2[120]	/* was [60][2] */, 
	    xdfp2[1000]	/* was [500][2] */, yvfp2[1000]	/* was [500][2] */, 
	    xgfq[60]	/* was [30][2] */, ydfq0[60]	/* was [30][2] */, 
	    ydfq1[60]	/* was [30][2] */, ydfq2[60]	/* was [30][2] */, 
	    ydfq3[60]	/* was [30][2] */, ydfq4[60]	/* was [30][2] */, 
	    yhfq5[60]	/* was [30][2] */, yhfq6[60]	/* was [30][2] */, 
	    yhfq7[60]	/* was [30][2] */, yhfq8[60]	/* was [30][2] */, 
	    yhfq9[60]	/* was [30][2] */, xgac[60]	/* was [30][2] */, 
	    yhac[60]	/* was [30][2] */, zgfpa1[60]	/* was [30][2] */, 
	    xdfpa1[1100]	/* was [550][2] */, yhfpa1[1100]	/* 
	    was [550][2] */, zdfpa2[32]	/* was [16][2] */, xdfpa2[300]	/* 
	    was [150][2] */, yvfpa2[300]	/* was [150][2] */, xgfqa[60]	
	    /* was [30][2] */, ydfqa0[60]	/* was [30][2] */, ydfqa1[60]	
	    /* was [30][2] */, ydfqa2[60]	/* was [30][2] */, ydfqa3[60]	
	    /* was [30][2] */, ydfqa4[60]	/* was [30][2] */, yhfqa5[60]	
	    /* was [30][2] */, yhfqa6[60]	/* was [30][2] */, yhfqa7[60]	
	    /* was [30][2] */, yhfqa8[60]	/* was [30][2] */, yhfqa9[60]	
	    /* was [30][2] */, xgaca[60]	/* was [30][2] */, yhaca[60]	
	    /* was [30][2] */;
    integer nsen[2], grfp1[2], nzfp1[2], nfp1[200]	/* was [100][2] */, 
	    grfp2[2], nzfp2[2], nfp2[120]	/* was [60][2] */, nfq[2], 
	    grfq0[2], grfq1[2], grfq2[2], grfq3[2], grfq4[2], grfq5[2], grfq6[
	    2], grfq7[2], grfq8[2], grfq9[2], grac[2], nac[2], nzfpa1[2], 
	    grfpa1[2], nfpa1[60]	/* was [30][2] */, grfpa2[2], nzfpa2[
	    2], nfpa2[32]	/* was [16][2] */, nfqa[2], grfqa0[2], grfqa1[
	    2], grfqa2[2], grfqa3[2], grfqa4[2], grfqa5[2], grfqa6[2], grfqa7[
	    2], grfqa8[2], grfqa9[2], graca[2], naca[2];
    real zacc[200]	/* was [25][4][2] */, xacc[2400]	/* was [300][
	    4][2] */, yacc[2400]	/* was [300][4][2] */, zacac[200]	
	    /* was [25][4][2] */, xacac[2400]	/* was [300][4][2] */, yacac[
	    2400]	/* was [300][4][2] */;
    integer pacc[30]	/* was [15][2] */, gracc[8]	/* was [4][2] */, 
	    nzacc[8]	/* was [4][2] */, nacc[200]	/* was [25][4][2] */, 
	    pacac[30]	/* was [15][2] */, gracac[8]	/* was [4][2] */, 
	    nzacac[8]	/* was [4][2] */, nacac[200]	/* was [25][4][2] */;
} dato6_;

#define dato6_1 dato6_

struct {
    real zsen1[20], xwen1[200], yeen1[200], zeen2[20], xhen2[200], yeen2[200],
	     zeen3[20], xten3[200], yeen3[200], zeenc1[15], xpenc1[200], 
	    yeenc1[200], zeenc2[15], xvenc2[200], yeenc2[200];
    integer gren1, nzen1, nen1[20], gren2, nzen2, nen2[20], gren3, nzen3, 
	    nen3[20], grenc1, nzenc1, nenc1[15], grenc2, nzenc2, nenc2[15];
} dato7_;

#define dato7_1 dato7_

struct {
    integer mil, curve, obs_crit__, ierb, ierd, iere, ierf, ierv, ifc, ifr, 
	    ifa;
    real asdc, torc, todc, grad1, gradc, dd1, ddc, dist, vrc, vvc, vvmc, 
	    tod_obs__, grad_obs__, vrot1, rcc, cfl1, cflc, tod1, vre1, vel, 
	    vcef, togr1;
} resto_;

#define resto_1 resto_

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

/* Table of constant values */

static real c_b3 = 1.f;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__0 = 0;
static real c_b19 = 35.f;
static integer c__3 = 3;
static integer c__100 = 100;
static integer c__15 = 15;
static real c_b44 = 50.f;
static integer c__10 = 10;
static integer c_n1 = -1;
static integer c__180 = 180;
static integer c__20 = 20;

doublereal malla_(real *v)
{
    /* System generated locals */
    real ret_val, r__1, r__2, r__3, r__4, r__5, r__6, r__7, r__8, r__9, r__10,
	     r__11, r__12;

    /* Local variables */
    static real d__, dff;

    d__ = resto_1.ddc / 1e3f;
    if (resto_1.curve == 1) {
/* Computing 2nd power */
	r__1 = d__;
/* Computing 2nd power */
	r__2 = *v;
/* Computing 2nd power */
	r__3 = d__;
/* Computing 2nd power */
	r__4 = *v;
/* Computing 3rd power */
	r__5 = d__;
/* Computing 3rd power */
	r__6 = *v;
/* Computing 3rd power */
	r__7 = d__;
/* Computing 2nd power */
	r__8 = d__;
/* Computing 2nd power */
	r__9 = *v;
/* Computing 3rd power */
	r__10 = *v;
/* Computing 4th power */
	r__11 = d__, r__11 *= r__11;
/* Computing 4th power */
	r__12 = *v, r__12 *= r__12;
	dff = dato2_1.masd[ini2_1.ifl * 15 - 15] + dato2_1.masd[ini2_1.ifl * 
		15 - 14] * d__ + dato2_1.masd[ini2_1.ifl * 15 - 13] * *v + 
		dato2_1.masd[ini2_1.ifl * 15 - 12] * d__ * *v + dato2_1.masd[
		ini2_1.ifl * 15 - 11] * (r__1 * r__1) + dato2_1.masd[
		ini2_1.ifl * 15 - 10] * (r__2 * r__2) + dato2_1.masd[
		ini2_1.ifl * 15 - 9] * (r__3 * r__3) * *v + dato2_1.masd[
		ini2_1.ifl * 15 - 8] * d__ * (r__4 * r__4) + dato2_1.masd[
		ini2_1.ifl * 15 - 7] * (r__5 * (r__5 * r__5)) + dato2_1.masd[
		ini2_1.ifl * 15 - 6] * (r__6 * (r__6 * r__6)) + dato2_1.masd[
		ini2_1.ifl * 15 - 5] * (r__7 * (r__7 * r__7)) * *v + 
		dato2_1.masd[ini2_1.ifl * 15 - 4] * (r__8 * r__8) * (r__9 * 
		r__9) + dato2_1.masd[ini2_1.ifl * 15 - 3] * d__ * (r__10 * (
		r__10 * r__10)) + dato2_1.masd[ini2_1.ifl * 15 - 2] * (r__11 *
		 r__11) + dato2_1.masd[ini2_1.ifl * 15 - 1] * (r__12 * r__12);
    } else if (resto_1.curve == 2) {
/* Computing 2nd power */
	r__1 = d__;
/* Computing 2nd power */
	r__2 = *v;
/* Computing 2nd power */
	r__3 = d__;
/* Computing 2nd power */
	r__4 = *v;
/* Computing 3rd power */
	r__5 = d__;
/* Computing 3rd power */
	r__6 = *v;
/* Computing 3rd power */
	r__7 = d__;
/* Computing 2nd power */
	r__8 = d__;
/* Computing 2nd power */
	r__9 = *v;
/* Computing 3rd power */
	r__10 = *v;
/* Computing 4th power */
	r__11 = d__, r__11 *= r__11;
/* Computing 4th power */
	r__12 = *v, r__12 *= r__12;
	dff = dato2_1.mtor[ini2_1.ifl * 15 - 15] + dato2_1.mtor[ini2_1.ifl * 
		15 - 14] * d__ + dato2_1.mtor[ini2_1.ifl * 15 - 13] * *v + 
		dato2_1.mtor[ini2_1.ifl * 15 - 12] * d__ * *v + dato2_1.mtor[
		ini2_1.ifl * 15 - 11] * (r__1 * r__1) + dato2_1.mtor[
		ini2_1.ifl * 15 - 10] * (r__2 * r__2) + dato2_1.mtor[
		ini2_1.ifl * 15 - 9] * (r__3 * r__3) * *v + dato2_1.mtor[
		ini2_1.ifl * 15 - 8] * d__ * (r__4 * r__4) + dato2_1.mtor[
		ini2_1.ifl * 15 - 7] * (r__5 * (r__5 * r__5)) + dato2_1.mtor[
		ini2_1.ifl * 15 - 6] * (r__6 * (r__6 * r__6)) + dato2_1.mtor[
		ini2_1.ifl * 15 - 5] * (r__7 * (r__7 * r__7)) * *v + 
		dato2_1.mtor[ini2_1.ifl * 15 - 4] * (r__8 * r__8) * (r__9 * 
		r__9) + dato2_1.mtor[ini2_1.ifl * 15 - 3] * d__ * (r__10 * (
		r__10 * r__10)) + dato2_1.mtor[ini2_1.ifl * 15 - 2] * (r__11 *
		 r__11) + dato2_1.mtor[ini2_1.ifl * 15 - 1] * (r__12 * r__12);
    } else {
/* Computing 2nd power */
	r__1 = d__;
/* Computing 2nd power */
	r__2 = *v;
/* Computing 2nd power */
	r__3 = d__;
/* Computing 2nd power */
	r__4 = *v;
/* Computing 3rd power */
	r__5 = d__;
/* Computing 3rd power */
	r__6 = *v;
/* Computing 3rd power */
	r__7 = d__;
/* Computing 2nd power */
	r__8 = d__;
/* Computing 2nd power */
	r__9 = *v;
/* Computing 3rd power */
	r__10 = *v;
/* Computing 4th power */
	r__11 = d__, r__11 *= r__11;
/* Computing 4th power */
	r__12 = *v, r__12 *= r__12;
	dff = dato2_1.mtod[ini2_1.ifl * 15 - 15] + dato2_1.mtod[ini2_1.ifl * 
		15 - 14] * d__ + dato2_1.mtod[ini2_1.ifl * 15 - 13] * *v + 
		dato2_1.mtod[ini2_1.ifl * 15 - 12] * d__ * *v + dato2_1.mtod[
		ini2_1.ifl * 15 - 11] * (r__1 * r__1) + dato2_1.mtod[
		ini2_1.ifl * 15 - 10] * (r__2 * r__2) + dato2_1.mtod[
		ini2_1.ifl * 15 - 9] * (r__3 * r__3) * *v + dato2_1.mtod[
		ini2_1.ifl * 15 - 8] * d__ * (r__4 * r__4) + dato2_1.mtod[
		ini2_1.ifl * 15 - 7] * (r__5 * (r__5 * r__5)) + dato2_1.mtod[
		ini2_1.ifl * 15 - 6] * (r__6 * (r__6 * r__6)) + dato2_1.mtod[
		ini2_1.ifl * 15 - 5] * (r__7 * (r__7 * r__7)) * *v + 
		dato2_1.mtod[ini2_1.ifl * 15 - 4] * (r__8 * r__8) * (r__9 * 
		r__9) + dato2_1.mtod[ini2_1.ifl * 15 - 3] * d__ * (r__10 * (
		r__10 * r__10)) + dato2_1.mtod[ini2_1.ifl * 15 - 2] * (r__11 *
		 r__11) + dato2_1.mtod[ini2_1.ifl * 15 - 1] * (r__12 * r__12);
    }
    ret_val = dff * 1e3f - resto_1.dist;
    return ret_val;
} /* malla_ */

/* Subroutine */ int v1vr_(real *v1m, real *v1v, integer *ie)
{
    static real vl1;
    static integer ier;
    extern doublereal malla_(real *);
    static integer cifsig, itemax;
    static real error;
    extern /* Subroutine */ int zfalse1_(E_fp, real *, integer *, real *, 
	    real *, real *, integer *, integer *);

    *ie = 0;
    if (resto_1.curve == 1 && malla_(&c_b3) < 0.f || resto_1.curve != 1 && 
	    malla_(&c_b3) > 0.f) {
	*v1v = 1.1f;
    } else {
	vl1 = *v1m;
L10:
	if (resto_1.curve == 1 && malla_(&vl1) > 0.f || resto_1.curve != 1 && 
		malla_(&vl1) < 0.f) {
	    vl1 += -.2f;
	    if (vl1 > 0.f) {
		goto L10;
	    }
	    vl1 = 0.f;
	}
	if (vl1 <= 0.f) {
	    *v1v = .1f;
	} else {
	    error = .01f;
	    cifsig = 4;
	    itemax = 100;
	    zfalse1_((E_fp)malla_, &error, &cifsig, &vl1, &c_b3, v1v, &itemax,
		     &ier);
	    if (ier > 0) {
		*ie = 510;
		return 0;
	    }
	}
    }
    return 0;
} /* v1vr_ */

doublereal bfl_(real *vv)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer nxasd, nuasd, nxtod, nutod;
    static real dis1, dis2, disc;
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *);
    static integer ie;
    extern doublereal malla_(real *);

    nxtod = 75;
    nxasd = 75;
    nuasd = 15;
    nutod = 15;
    resto_1.curve = 1;
    resto_1.dist = 0.f;
    disc = malla_(vv);
    corr_(&ie, &c__1, &dis1, &disc, ini2_1.x, &dato2_1.pasd[ini2_1.ifl * 15 - 
	    15], &nxasd, &nuasd, &dato2_1.grasd[ini2_1.ifl * 10 - 10], &
	    dato2_1.nzasd[ini2_1.ifl * 10 - 10], &dato2_1.nasd[(ini2_1.ifl * 
	    10 + 1) * 15 - 165], &dato2_1.xasd[(ini2_1.ifl * 10 + 1) * 75 - 
	    825], &dato2_1.yasd[(ini2_1.ifl * 10 + 1) * 75 - 825], &
	    dato2_1.zasd[(ini2_1.ifl * 10 + 1) * 15 - 165]);
    if (ie == 2) {
	goto L10000;
    }
    resto_1.curve = 3;
    disc = malla_(vv);
    corr_(&ie, &c__1, &dis2, &disc, ini2_1.x, &dato2_1.ptod[ini2_1.ifl * 15 - 
	    15], &nxtod, &nutod, &dato2_1.grtod[ini2_1.ifl * 10 - 10], &
	    dato2_1.nztod[ini2_1.ifl * 10 - 10], &dato2_1.ntod[(ini2_1.ifl * 
	    10 + 1) * 15 - 165], &dato2_1.xtod[(ini2_1.ifl * 10 + 1) * 75 - 
	    825], &dato2_1.ytod[(ini2_1.ifl * 10 + 1) * 75 - 825], &
	    dato2_1.ztod[(ini2_1.ifl * 10 + 1) * 15 - 165]);
    if (ie == 2) {
	goto L10000;
    }
    ret_val = dis1 - dis2;
    resto_1.dist = dis1;
    resto_1.ierb = 0;
    return ret_val;
L10000:
    ret_val = 0.f;
    resto_1.dist = 0.f;
    resto_1.ierb = 2;
    return ret_val;
} /* bfl_ */

doublereal fdisw_(real *wx)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer icur;
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , vrspeed_(real *, real *, real *, real *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *, real *, real *, real *, integer *, integer *, real *,
	     real *), v1vr_(real *, real *, integer *);
    static integer ie;
    extern doublereal malla_(real *);

    ret_val = 0.f;
    icur = resto_1.curve;
    manual3r_(&c__5, dato2_1.grwd2, dato2_1.xwwd2, dato2_1.ywwd2, 
	    dato2_1.zdwd2, dato2_1.nwd2, dato2_1.nzwd2, wx, &resto_1.dd1, &
	    resto_1.ddc, &ie);
    if (ie == 2) {
	goto L10000;
    }
    vrspeed_(&resto_1.vrot1, &ini2_1.vmcg[ini2_1.ind - 1], wx, &resto_1.vrc, &
	    ie, &dato5_1.grvro1[ini2_1.ifl - 1], &dato5_1.nzvro1[ini2_1.ifl - 
	    1], &dato5_1.nvro1[ini2_1.ifl * 15 - 15], &dato5_1.zwvro1[
	    ini2_1.ifl * 15 - 15], &dato5_1.xsvro1[ini2_1.ifl * 500 - 500], &
	    dato5_1.ysvro1[ini2_1.ifl * 500 - 500], &dato5_1.grvro2[
	    ini2_1.ifl - 1], &dato5_1.nzvro2[ini2_1.ifl - 1], &dato5_1.nvro2[(
	    ini2_1.ifl << 4) - 16], &dato5_1.zwvro2[(ini2_1.ifl << 4) - 16], &
	    dato5_1.xsvro2[ini2_1.ifl * 500 - 500], &dato5_1.ysvro2[
	    ini2_1.ifl * 500 - 500], &dato5_1.grvro3[ini2_1.ifl - 1], &
	    dato5_1.nvro3[ini2_1.ifl - 1], &dato5_1.xwvro3[ini2_1.ifl * 50 - 
	    50], &dato5_1.ysvro3[ini2_1.ifl * 50 - 50]);
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__2, &dato2_1.grv1r[ini2_1.ifl - 1], &dato2_1.xsv1r[
	    ini2_1.ifl * 50 - 50], &dato2_1.ysv1r[ini2_1.ifl * 50 - 50], &
	    dato2_1.zsv1r[ini2_1.ifl * 20 - 20], &dato2_1.nv1r[ini2_1.ifl * 
	    20 - 20], &dato2_1.nzv1r[ini2_1.ifl - 1], &resto_1.vrc, &
	    ini2_1.vmcg[ini2_1.ind - 1], &resto_1.vvmc, &ie);
    if (ie == 2) {
	goto L10000;
    }
    resto_1.curve = 1;
    resto_1.dist = resto_1.asdc;
    if (icur == 1) {
	resto_1.vvc = resto_1.vvmc;
    } else {
	v1vr_(&resto_1.vvmc, &resto_1.vvc, &resto_1.ierf);
	if (resto_1.ierf > 0) {
	    return ret_val;
	}
	if (resto_1.vvc > 1.f) {
	    resto_1.vvc = 1.f;
	}
	if (icur == 2) {
	    resto_1.curve = 2;
	    resto_1.dist = resto_1.torc;
	} else {
	    resto_1.curve = 3;
	    resto_1.dist = resto_1.todc;
	}
    }
    ret_val = malla_(&resto_1.vvc);
    resto_1.curve = icur;
    resto_1.ierf = 0;
    return ret_val;
L10000:
    resto_1.ierf = 2;
    return ret_val;
} /* fdisw_ */

doublereal difobsf_(real *vvx)
{
    /* System generated locals */
    real ret_val, r__1;

    /* Local variables */
    static integer npa, nxtod, nutod;
    static real xpa[20], ypa[20], todold;
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *), fpath_(integer *, real *, 
	    real *, real *, real *, real *, real *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    , integer *, real *, integer *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, integer *
	    , real *, integer *, real *, integer *, real *, integer *, real *,
	     integer *, real *, integer *, real *, real *, integer *), 
	    obscrit_(real *, integer *, real *, real *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, real *, real *, 
	    integer *);
    static integer ie, np;
    static real xp[20], yp[20], vl1;
    extern doublereal malla_(real *);

    nxtod = 75;
    nutod = 15;
    todold = resto_1.tod_obs__;
    if (resto_1.tod_obs__ <= 0.f) {
	resto_1.curve = 3;
	resto_1.dist = 0.f;
	vl1 = malla_(vvx);
	corr_(&ie, &c__1, &resto_1.tod_obs__, &vl1, ini2_1.x, &dato2_1.ptod[
		ini2_1.ifl * 15 - 15], &nxtod, &nutod, &dato2_1.grtod[
		ini2_1.ifl * 10 - 10], &dato2_1.nztod[ini2_1.ifl * 10 - 10], &
		dato2_1.ntod[(ini2_1.ifl * 10 + 1) * 15 - 165], &dato2_1.xtod[
		(ini2_1.ifl * 10 + 1) * 75 - 825], &dato2_1.ytod[(ini2_1.ifl *
		 10 + 1) * 75 - 825], &dato2_1.ztod[(ini2_1.ifl * 10 + 1) * 
		15 - 165]);
	if (ie == 2) {
	    goto L10000;
	}
    }
    r__1 = resto_1.grad_obs__ - .8f;
    fpath_(&c__0, &ini2_1.x[5], &r__1, &c_b19, &dato6_1.xdfp1[ini2_1.ifl * 
	    1500 - 1500], &dato6_1.yhfp1[ini2_1.ifl * 1500 - 1500], &
	    dato6_1.zgfp1[ini2_1.ifl * 100 - 100], &dato6_1.grfp1[ini2_1.ifl 
	    - 1], &dato6_1.nfp1[ini2_1.ifl * 100 - 100], &dato6_1.nzfp1[
	    ini2_1.ifl - 1], &dato6_1.xdfp2[ini2_1.ifl * 500 - 500], &
	    dato6_1.yvfp2[ini2_1.ifl * 500 - 500], &dato6_1.zdfp2[ini2_1.ifl *
	     60 - 60], &dato6_1.grfp2[ini2_1.ifl - 1], &dato6_1.nfp2[
	    ini2_1.ifl * 60 - 60], &dato6_1.nzfp2[ini2_1.ifl - 1], &
	    dato6_1.nfq[ini2_1.ifl - 1], &dato6_1.xgfq[ini2_1.ifl * 30 - 30], 
	    &dato6_1.grfq0[ini2_1.ifl - 1], &dato6_1.ydfq0[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq1[ini2_1.ifl - 1], &dato6_1.ydfq1[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq2[ini2_1.ifl - 1], &dato6_1.ydfq2[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq3[ini2_1.ifl - 1], &
	    dato6_1.ydfq3[ini2_1.ifl * 30 - 30], &dato6_1.grfq4[ini2_1.ifl - 
	    1], &dato6_1.ydfq4[ini2_1.ifl * 30 - 30], &dato6_1.grfq5[
	    ini2_1.ifl - 1], &dato6_1.yhfq5[ini2_1.ifl * 30 - 30], &
	    dato6_1.grfq6[ini2_1.ifl - 1], &dato6_1.yhfq6[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq7[ini2_1.ifl - 1], &dato6_1.yhfq7[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq8[ini2_1.ifl - 1], &dato6_1.yhfq8[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq9[ini2_1.ifl - 1], &
	    dato6_1.yhfq9[ini2_1.ifl * 30 - 30], &np, xp, yp, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato6_1.nsen[ini2_1.ifl - 1] == 2) {
	r__1 = resto_1.grad_obs__ - .8f;
	fpath_(&c__0, &ini2_1.x[5], &r__1, &c_b19, &dato6_1.xdfpa1[ini2_1.ifl 
		* 550 - 550], &dato6_1.yhfpa1[ini2_1.ifl * 550 - 550], &
		dato6_1.zgfpa1[ini2_1.ifl * 30 - 30], &dato6_1.grfpa1[
		ini2_1.ifl - 1], &dato6_1.nfpa1[ini2_1.ifl * 30 - 30], &
		dato6_1.nzfpa1[ini2_1.ifl - 1], &dato6_1.xdfpa2[ini2_1.ifl * 
		150 - 150], &dato6_1.yvfpa2[ini2_1.ifl * 150 - 150], &
		dato6_1.zdfpa2[(ini2_1.ifl << 4) - 16], &dato6_1.grfpa2[
		ini2_1.ifl - 1], &dato6_1.nfpa2[(ini2_1.ifl << 4) - 16], &
		dato6_1.nzfpa2[ini2_1.ifl - 1], &dato6_1.nfqa[ini2_1.ifl - 1],
		 &dato6_1.xgfqa[ini2_1.ifl * 30 - 30], &dato6_1.grfqa0[
		ini2_1.ifl - 1], &dato6_1.ydfqa0[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa1[ini2_1.ifl - 1], &dato6_1.ydfqa1[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa2[ini2_1.ifl - 1], &dato6_1.ydfqa2[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa3[ini2_1.ifl - 1], &
		dato6_1.ydfqa3[ini2_1.ifl * 30 - 30], &dato6_1.grfqa4[
		ini2_1.ifl - 1], &dato6_1.ydfqa4[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa5[ini2_1.ifl - 1], &dato6_1.yhfqa5[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa6[ini2_1.ifl - 1], &dato6_1.yhfqa6[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa7[ini2_1.ifl - 1], &
		dato6_1.yhfqa7[ini2_1.ifl * 30 - 30], &dato6_1.grfqa8[
		ini2_1.ifl - 1], &dato6_1.yhfqa8[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa9[ini2_1.ifl - 1], &dato6_1.yhfqa9[ini2_1.ifl * 
		30 - 30], &npa, xpa, ypa, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	npa = 0;
    }
    obscrit_(&resto_1.tod_obs__, &np, xp, yp, &npa, xpa, ypa, &vl1, &
	    ini2_1.senda[ini2_1.ind - 1], &resto_1.obs_crit__, &ini2_1.nfp[
	    ini2_1.ind - 1], &ini2_1.xfp[(ini2_1.ind << 4) - 16], &ini2_1.hfp[
	    (ini2_1.ind << 4) - 16], &ie);
    if (ie > 0) {
	goto L10000;
    }
    ret_val = vl1;
    resto_1.ierd = 0;
    if (todold <= 0.f) {
	resto_1.tod_obs__ = -999.f;
    }
    return ret_val;
L10000:
    ret_val = 0.f;
    resto_1.ierd = 2;
    return ret_val;
} /* difobsf_ */

doublereal difobsf1_(real *wx)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer nxtod, nutod;
    extern doublereal fdisw_(real *), difobsf_(real *);
    static integer nxg2c, nug2c;
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , corr_(integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *);
    static integer ie;
    static real vl1;

    nxg2c = 100;
    nug2c = 15;
    manual3r_(&c__1, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
	    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 750], &
	    dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[ini2_1.ifl * 30 
	    - 30], &dato1_1.nzg22[ini2_1.ifl - 1], wx, &vl1, &resto_1.grad1, &
	    ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &resto_1.grad_obs__, ini2_1.x, &dato1_1.pg2c[
	    ini2_1.ifl * 15 - 15], &nxg2c, &nug2c, &dato1_1.grg2c[(ini2_1.ifl 
	    << 2) - 4], &dato1_1.nzg2c[(ini2_1.ifl << 2) - 4], &dato1_1.ng2c[(
	    (ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.xg2c[((ini2_1.ifl << 
	    2) + 1) * 100 - 500], &dato1_1.yg2c[((ini2_1.ifl << 2) + 1) * 100 
	    - 500], &dato1_1.zg2c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
    if (ie == 2) {
	goto L10000;
    }
    nxtod = 75;
    nutod = 15;
    resto_1.curve = 3;
    vl1 = fdisw_(wx) + resto_1.todc;
    corr_(&ie, &c__1, &resto_1.tod_obs__, &vl1, ini2_1.x, &dato2_1.ptod[
	    ini2_1.ifl * 15 - 15], &nxtod, &nutod, &dato2_1.grtod[ini2_1.ifl *
	     10 - 10], &dato2_1.nztod[ini2_1.ifl * 10 - 10], &dato2_1.ntod[(
	    ini2_1.ifl * 10 + 1) * 15 - 165], &dato2_1.xtod[(ini2_1.ifl * 10 
	    + 1) * 75 - 825], &dato2_1.ytod[(ini2_1.ifl * 10 + 1) * 75 - 825],
	     &dato2_1.ztod[(ini2_1.ifl * 10 + 1) * 15 - 165]);
    if (ie == 2) {
	goto L10000;
    }
    vl1 = difobsf_(&resto_1.vvc);
    if (resto_1.ierd > 0) {
	goto L10000;
    }
    ret_val = vl1;
    resto_1.ierd = 0;
    return ret_val;
L10000:
    resto_1.ierd = 2;
    ret_val = 0.f;
    return ret_val;
} /* difobsf1_ */

doublereal vrfu_(real *w)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , corr_(integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *);
    static real vl1, vl2;
    static integer mxvrc, mzvrc;

    mxvrc = 400;
    mzvrc = 30;
    resto_1.ierv = 0;
    ret_val = 0.f;
    manual3r_(&c__3, &dato4_1.grvr2[resto_1.ifr - 1], &dato4_1.xsvr2[
	    resto_1.ifr * 500 - 500], &dato4_1.ysvr2[resto_1.ifr * 500 - 500],
	     &dato4_1.zdvr2[resto_1.ifr * 20 - 20], &dato4_1.nvr2[resto_1.ifr 
	    * 20 - 20], &dato4_1.nzvr2[resto_1.ifr - 1], &vl1, &resto_1.vre1, 
	    &resto_1.dist, &resto_1.ierv);
    if (resto_1.ierv == 2) {
	return ret_val;
    }
    manual3r_(&c__1, &dato4_1.grvr3[resto_1.ifr - 1], &dato4_1.xsvr3[
	    resto_1.ifr * 200 - 200], &dato4_1.ysvr3[resto_1.ifr * 200 - 200],
	     &dato4_1.zwvr3[resto_1.ifr * 10 - 10], &dato4_1.nvr3[resto_1.ifr 
	    * 10 - 10], &dato4_1.nzvr3[resto_1.ifr - 1], &vl1, &vl2, w, &
	    resto_1.ierv);
    if (resto_1.ierv == 2) {
	return ret_val;
    }
    corr_(&resto_1.ierv, &c__0, &vl2, &vl1, ini2_1.x, &dato4_1.pvrc[
	    resto_1.ifr * 15 - 15], &mxvrc, &mzvrc, &dato4_1.grvrc[(
	    resto_1.ifr << 3) - 8], &dato4_1.nzvrc[(resto_1.ifr << 3) - 8], &
	    dato4_1.nvrc[((resto_1.ifr << 3) + 1) * 30 - 270], &dato4_1.xvrc[(
	    (resto_1.ifr << 3) + 1) * 400 - 3600], &dato4_1.yvrc[((
	    resto_1.ifr << 3) + 1) * 400 - 3600], &dato4_1.zvrc[((resto_1.ifr 
	    << 3) + 1) * 30 - 270]);
    if (resto_1.ierv == 2) {
	return ret_val;
    }
    ret_val = vl1 - resto_1.vel;
    return ret_val;
} /* vrfu_ */

doublereal difobsm_(real *wx)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *), manual3r_(integer *, integer *
	    , real *, real *, real *, integer *, integer *, real *, real *, 
	    real *, integer *), manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), fpath_(integer *, real *
	    , real *, real *, real *, real *, real *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    , integer *, real *, integer *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, integer *
	    , real *, integer *, real *, integer *, real *, integer *, real *,
	     integer *, real *, integer *, real *, real *, integer *), 
	    obscrit_(real *, integer *, real *, real *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, real *, real *, 
	    integer *);
    static integer ie, np;
    static real xp[20], yp[20], vl1, vl2, dif;
    static integer npa;
    static real xpa[20], ypa[20];
    static integer nug2c, nxg2c, mxgrc, mzgrc;

    mxgrc = 150;
    mzgrc = 20;
    nxg2c = 100;
    nug2c = 15;
    corr_(&ie, &c__1, &vl1, wx, ini2_1.x, &dato1_1.pg2c[ini2_1.ifl * 15 - 15],
	     &nxg2c, &nug2c, &dato1_1.grg2c[(ini2_1.ifl << 2) - 4], &
	    dato1_1.nzg2c[(ini2_1.ifl << 2) - 4], &dato1_1.ng2c[((ini2_1.ifl 
	    << 2) + 1) * 15 - 75], &dato1_1.xg2c[((ini2_1.ifl << 2) + 1) * 
	    100 - 500], &dato1_1.yg2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
	    dato1_1.zg2c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__5, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
	    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 750], &
	    dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[ini2_1.ifl * 30 
	    - 30], &dato1_1.nzg22[ini2_1.ifl - 1], &vl1, &resto_1.grad1, &
	    resto_1.gradc, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato1_1.indg2 == 1) {
	manual2r_(&c__1, &resto_1.gradc, &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[ini2_1.ifl - 
		1], &dato1_1.ng[ini2_1.ifl - 1], &resto_1.rcc, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	resto_1.rcc = resto_1.gradc;
	manual2r_(&c__2, &resto_1.gradc, &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[ini2_1.ifl - 
		1], &dato1_1.ng[ini2_1.ifl - 1], &resto_1.rcc, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    }
    manual3r_(&c__1, &dato3_1.grgr2[resto_1.ifc - 1], &dato3_1.xdgr2[
	    resto_1.ifc * 500 - 500], &dato3_1.ydgr2[resto_1.ifc * 500 - 500],
	     &dato3_1.zwgr2[resto_1.ifc * 20 - 20], &dato3_1.ngr2[resto_1.ifc 
	    * 20 - 20], &dato3_1.nzgr2[resto_1.ifc - 1], &resto_1.cfl1, &vl1, 
	    wx, &ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &resto_1.cflc, ini2_1.x, &dato3_1.pgrc[
	    resto_1.ifc * 15 - 15], &mxgrc, &mzgrc, &dato3_1.grgrc[
	    resto_1.ifc * 10 - 10], &dato3_1.nzgrc[resto_1.ifc * 10 - 10], &
	    dato3_1.ngrc[(resto_1.ifc * 10 + 1) * 20 - 220], &dato3_1.xgrc[(
	    resto_1.ifc * 10 + 1) * 150 - 1650], &dato3_1.ygrc[(resto_1.ifc * 
	    10 + 1) * 150 - 1650], &dato3_1.zgrc[(resto_1.ifc * 10 + 1) * 20 
	    - 220]);
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__1, &dato3_1.grda1[resto_1.ifa - 1], &dato3_1.xgda1[
	    resto_1.ifa * 200 - 200], &dato3_1.ydda1[resto_1.ifa * 200 - 200],
	     &dato3_1.zfda1[resto_1.ifa * 10 - 10], &dato3_1.nda1[resto_1.ifa 
	    * 10 - 10], &dato3_1.nzda1[resto_1.ifa - 1], &resto_1.gradc, &vl1,
	     &ini2_1.x[1], &ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &vl2, ini2_1.x, &dato3_1.pda1c[ini2_1.ifl * 15 - 
	    15], &c__100, &c__15, &dato3_1.grda1c[(ini2_1.ifl << 2) - 4], &
	    dato3_1.nzda1c[(ini2_1.ifl << 2) - 4], &dato3_1.nda1c[((
	    ini2_1.ifl << 2) + 1) * 15 - 75], &dato3_1.xda1c[((ini2_1.ifl << 
	    2) + 1) * 100 - 500], &dato3_1.yda1c[((ini2_1.ifl << 2) + 1) * 
	    100 - 500], &dato3_1.zda1c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
    if (ie == 2) {
	goto L10000;
    }
    resto_1.todc = resto_1.cflc + vl2;
    fpath_(&c__1, &ini2_1.x[5], &resto_1.gradc, &c_b44, &dato6_1.xdfp1[
	    ini2_1.ifl * 1500 - 1500], &dato6_1.yhfp1[ini2_1.ifl * 1500 - 
	    1500], &dato6_1.zgfp1[ini2_1.ifl * 100 - 100], &dato6_1.grfp1[
	    ini2_1.ifl - 1], &dato6_1.nfp1[ini2_1.ifl * 100 - 100], &
	    dato6_1.nzfp1[ini2_1.ifl - 1], &dato6_1.xdfp2[ini2_1.ifl * 500 - 
	    500], &dato6_1.yvfp2[ini2_1.ifl * 500 - 500], &dato6_1.zdfp2[
	    ini2_1.ifl * 60 - 60], &dato6_1.grfp2[ini2_1.ifl - 1], &
	    dato6_1.nfp2[ini2_1.ifl * 60 - 60], &dato6_1.nzfp2[ini2_1.ifl - 1]
	    , &dato6_1.nfq[ini2_1.ifl - 1], &dato6_1.xgfq[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq0[ini2_1.ifl - 1], &dato6_1.ydfq0[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq1[ini2_1.ifl - 1], &dato6_1.ydfq1[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq2[ini2_1.ifl - 1], &
	    dato6_1.ydfq2[ini2_1.ifl * 30 - 30], &dato6_1.grfq3[ini2_1.ifl - 
	    1], &dato6_1.ydfq3[ini2_1.ifl * 30 - 30], &dato6_1.grfq4[
	    ini2_1.ifl - 1], &dato6_1.ydfq4[ini2_1.ifl * 30 - 30], &
	    dato6_1.grfq5[ini2_1.ifl - 1], &dato6_1.yhfq5[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq6[ini2_1.ifl - 1], &dato6_1.yhfq6[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq7[ini2_1.ifl - 1], &dato6_1.yhfq7[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq8[ini2_1.ifl - 1], &
	    dato6_1.yhfq8[ini2_1.ifl * 30 - 30], &dato6_1.grfq9[ini2_1.ifl - 
	    1], &dato6_1.yhfq9[ini2_1.ifl * 30 - 30], &np, xp, yp, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato6_1.nsen[ini2_1.ifl - 1] == 2) {
	fpath_(&c__1, &ini2_1.x[5], &resto_1.gradc, &c_b44, &dato6_1.xdfpa1[
		ini2_1.ifl * 550 - 550], &dato6_1.yhfpa1[ini2_1.ifl * 550 - 
		550], &dato6_1.zgfpa1[ini2_1.ifl * 30 - 30], &dato6_1.grfpa1[
		ini2_1.ifl - 1], &dato6_1.nfpa1[ini2_1.ifl * 30 - 30], &
		dato6_1.nzfpa1[ini2_1.ifl - 1], &dato6_1.xdfpa2[ini2_1.ifl * 
		150 - 150], &dato6_1.yvfpa2[ini2_1.ifl * 150 - 150], &
		dato6_1.zdfpa2[(ini2_1.ifl << 4) - 16], &dato6_1.grfpa2[
		ini2_1.ifl - 1], &dato6_1.nfpa2[(ini2_1.ifl << 4) - 16], &
		dato6_1.nzfpa2[ini2_1.ifl - 1], &dato6_1.nfqa[ini2_1.ifl - 1],
		 &dato6_1.xgfqa[ini2_1.ifl * 30 - 30], &dato6_1.grfqa0[
		ini2_1.ifl - 1], &dato6_1.ydfqa0[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa1[ini2_1.ifl - 1], &dato6_1.ydfqa1[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa2[ini2_1.ifl - 1], &dato6_1.ydfqa2[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa3[ini2_1.ifl - 1], &
		dato6_1.ydfqa3[ini2_1.ifl * 30 - 30], &dato6_1.grfqa4[
		ini2_1.ifl - 1], &dato6_1.ydfqa4[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa5[ini2_1.ifl - 1], &dato6_1.yhfqa5[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa6[ini2_1.ifl - 1], &dato6_1.yhfqa6[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa7[ini2_1.ifl - 1], &
		dato6_1.yhfqa7[ini2_1.ifl * 30 - 30], &dato6_1.grfqa8[
		ini2_1.ifl - 1], &dato6_1.yhfqa8[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa9[ini2_1.ifl - 1], &dato6_1.yhfqa9[ini2_1.ifl * 
		30 - 30], &npa, xpa, ypa, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	npa = 0;
    }
    obscrit_(&resto_1.todc, &np, xp, yp, &npa, xpa, ypa, &dif, &ini2_1.senda[
	    ini2_1.ind - 1], &resto_1.obs_crit__, &ini2_1.nfp[ini2_1.ind - 1],
	     &ini2_1.xfp[(ini2_1.ind << 4) - 16], &ini2_1.hfp[(ini2_1.ind << 
	    4) - 16], &ie);
    if (ie > 0) {
	goto L10000;
    }
    ret_val = dif;
    resto_1.ierd = 0;
    return ret_val;
L10000:
    resto_1.ierd = 2;
    ret_val = 0.f;
    return ret_val;
} /* difobsm_ */

/* Subroutine */ int ebrk_(integer *icod, real *tow, real *ener, real *vbrk)
{
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer ie;
    static real vl1, vl2;

    if (*icod == 0) {
	manual3r_(&c__1, &dato7_1.gren1, dato7_1.xwen1, dato7_1.yeen1, 
		dato7_1.zsen1, dato7_1.nen1, &dato7_1.nzen1, tow, &vl1, vbrk, 
		&ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__1, &dato7_1.gren2, dato7_1.xhen2, dato7_1.yeen2, 
		dato7_1.zeen2, dato7_1.nen2, &dato7_1.nzen2, &ini1_1.hp, &vl2,
		 &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__1, &dato7_1.gren3, dato7_1.xten3, dato7_1.yeen3, 
		dato7_1.zeen3, dato7_1.nen3, &dato7_1.nzen3, &ini2_1.oat2, &
		vl1, &vl2, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__1, &dato7_1.grenc1, dato7_1.xpenc1, dato7_1.yeenc1, 
		dato7_1.zeenc1, dato7_1.nenc1, &dato7_1.nzenc1, &ini2_1.x[4], 
		&vl2, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__1, &dato7_1.grenc2, dato7_1.xvenc2, dato7_1.yeenc2, 
		dato7_1.zeenc2, dato7_1.nenc2, &dato7_1.nzenc2, &ini2_1.x[5], 
		ener, &vl2, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	manual3r_(&c__2, &dato7_1.grenc2, dato7_1.xvenc2, dato7_1.yeenc2, 
		dato7_1.zeenc2, dato7_1.nenc2, &dato7_1.nzenc2, &ini2_1.x[5], 
		ener, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato7_1.grenc1, dato7_1.xpenc1, dato7_1.yeenc1, 
		dato7_1.zeenc1, dato7_1.nenc1, &dato7_1.nzenc1, &ini2_1.x[4], 
		&vl1, &vl2, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato7_1.gren3, dato7_1.xten3, dato7_1.yeen3, 
		dato7_1.zeen3, dato7_1.nen3, &dato7_1.nzen3, &ini2_1.oat2, &
		vl2, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato7_1.gren2, dato7_1.xhen2, dato7_1.yeen2, 
		dato7_1.zeen2, dato7_1.nen2, &dato7_1.nzen2, &ini1_1.hp, &vl1,
		 &vl2, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato7_1.gren1, dato7_1.xwen1, dato7_1.yeen1, 
		dato7_1.zsen1, dato7_1.nen1, &dato7_1.nzen1, tow, &vl2, vbrk, 
		&ie);
	if (ie == 2) {
	    goto L10000;
	}
    }
    resto_1.iere = 0;
    return 0;
L10000:
    resto_1.iere = 2;
    return 0;
} /* ebrk_ */

doublereal fbrk_(real *w)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , corr_(integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *), ebrk_(integer *, real *, real *, real *);
    static integer ie;
    static real vl1, ener;
    extern doublereal vrfu_(real *);
    static integer mxgrc, mzgrc;

    mxgrc = 150;
    mzgrc = 20;
    manual3r_(&c__1, &dato3_1.grgr2[resto_1.ifc - 1], &dato3_1.xdgr2[
	    resto_1.ifc * 500 - 500], &dato3_1.ydgr2[resto_1.ifc * 500 - 500],
	     &dato3_1.zwgr2[resto_1.ifc * 20 - 20], &dato3_1.ngr2[resto_1.ifc 
	    * 20 - 20], &dato3_1.nzgr2[resto_1.ifc - 1], &resto_1.cfl1, &vl1, 
	    w, &ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &resto_1.cflc, ini2_1.x, &dato3_1.pgrc[
	    resto_1.ifc * 15 - 15], &mxgrc, &mzgrc, &dato3_1.grgrc[
	    resto_1.ifc * 10 - 10], &dato3_1.nzgrc[resto_1.ifc * 10 - 10], &
	    dato3_1.ngrc[(resto_1.ifc * 10 + 1) * 20 - 220], &dato3_1.xgrc[(
	    resto_1.ifc * 10 + 1) * 150 - 1650], &dato3_1.ygrc[(resto_1.ifc * 
	    10 + 1) * 150 - 1650], &dato3_1.zgrc[(resto_1.ifc * 10 + 1) * 20 
	    - 220]);
    if (ie == 2) {
	goto L10000;
    }
    resto_1.dist = resto_1.cflc;
    resto_1.vel = 0.f;
    resto_1.vcef = vrfu_(w);
    if (resto_1.ierv == 2) {
	goto L10000;
    }
    if (resto_1.vcef < ini2_1.vmcg[ini2_1.ind - 1]) {
	resto_1.vcef = ini2_1.vmcg[ini2_1.ind - 1];
    }
    ebrk_(&c__0, w, &ener, &resto_1.vcef);
    if (resto_1.iere == 2) {
	goto L10000;
    }
    ret_val = dagen3_1.limene[0] - ener;
    resto_1.ierb = 0;
    return ret_val;
L10000:
    resto_1.ierb = 2;
    ret_val = 0.f;
    return ret_val;
} /* fbrk_ */

doublereal difobst_(real *wx)
{
    /* System generated locals */
    real ret_val, r__1;

    /* Local variables */
    static integer npa, mxgrc, mzgrc, mxtdc, mztdc;
    static real oatc, xpa[20], ypa[20], togrc, dairc, grad1m, rc1m;
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , corr_(integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *), manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), fpath_(integer *, real *
	    , real *, real *, real *, real *, real *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    , integer *, real *, integer *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, integer *
	    , real *, integer *, real *, integer *, real *, integer *, real *,
	     integer *, real *, integer *, real *, real *, integer *), 
	    obscrit_(real *, integer *, real *, real *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, real *, real *, 
	    integer *);
    static integer ie, np;
    static real xp[20], yp[20], vl1, vl2, dif;

    mxtdc = 150;
    mxgrc = 150;
    mztdc = 15;
    mzgrc = 20;
    if (dato3_1.nzda1[ini2_1.ifl - 1] == 0) {
	manual3r_(&c__1, &dato3_1.grtd2[ini2_1.ifl - 1], &dato3_1.xdtd2[
		ini2_1.ifl * 500 - 500], &dato3_1.ydtd2[ini2_1.ifl * 500 - 
		500], &dato3_1.zwtd2[ini2_1.ifl * 20 - 20], &dato3_1.ntd2[
		ini2_1.ifl * 20 - 20], &dato3_1.nztd2[ini2_1.ifl - 1], &
		resto_1.tod1, &vl1, wx, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__0, &vl1, &resto_1.todc, ini2_1.x2, &dato3_1.ptdc[
		ini2_1.ifl * 15 - 15], &mxtdc, &mztdc, &dato3_1.grtdc[(
		ini2_1.ifl << 3) - 8], &dato3_1.nztdc[(ini2_1.ifl << 3) - 8], 
		&dato3_1.ntdc[((ini2_1.ifl << 3) + 1) * 15 - 135], &
		dato3_1.xtdc[((ini2_1.ifl << 3) + 1) * 150 - 1350], &
		dato3_1.ytdc[((ini2_1.ifl << 3) + 1) * 150 - 1350], &
		dato3_1.ztdc[((ini2_1.ifl << 3) + 1) * 15 - 135]);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	manual3r_(&c__1, &dato3_1.grgr2[ini2_1.ifl - 1], &dato3_1.xdgr2[
		ini2_1.ifl * 500 - 500], &dato3_1.ydgr2[ini2_1.ifl * 500 - 
		500], &dato3_1.zwgr2[ini2_1.ifl * 20 - 20], &dato3_1.ngr2[
		ini2_1.ifl * 20 - 20], &dato3_1.nzgr2[ini2_1.ifl - 1], &
		resto_1.togr1, &vl1, wx, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__0, &vl1, &togrc, ini2_1.x2, &dato3_1.pgrc[ini2_1.ifl * 
		15 - 15], &mxgrc, &mzgrc, &dato3_1.grgrc[ini2_1.ifl * 10 - 10]
		, &dato3_1.nzgrc[ini2_1.ifl * 10 - 10], &dato3_1.ngrc[(
		ini2_1.ifl * 10 + 1) * 20 - 220], &dato3_1.xgrc[(ini2_1.ifl * 
		10 + 1) * 150 - 1650], &dato3_1.ygrc[(ini2_1.ifl * 10 + 1) * 
		150 - 1650], &dato3_1.zgrc[(ini2_1.ifl * 10 + 1) * 20 - 220]);
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__1, &vl1, wx, ini2_1.x, &dato1_1.pg2c[ini2_1.ifl * 15 - 
		15], &c__100, &c__15, &dato1_1.grg2c[(ini2_1.ifl << 2) - 4], &
		dato1_1.nzg2c[(ini2_1.ifl << 2) - 4], &dato1_1.ng2c[((
		ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.xg2c[((ini2_1.ifl 
		<< 2) + 1) * 100 - 500], &dato1_1.yg2c[((ini2_1.ifl << 2) + 1)
		 * 100 - 500], &dato1_1.zg2c[((ini2_1.ifl << 2) + 1) * 15 - 
		75]);
	if (ie == 2) {
	    goto L10000;
	}
	if (ini1_1.gs <= 20.f) {
	    manual3r_(&c__5, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
		    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 
		    750], &dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[
		    ini2_1.ifl * 30 - 30], &dato1_1.nzg22[ini2_1.ifl - 1], &
		    vl1, &resto_1.grad1, &grad1m, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    manual3r_(&c__5, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
		    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 
		    750], &dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[
		    ini2_1.ifl * 30 - 30], &dato1_1.nzg22[ini2_1.ifl - 1], &
		    vl1, &resto_1.grad1, &rc1m, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__1, &vl2, &rc1m, ini2_1.x, &dato1_1.pgc[ini2_1.ifl *
		     15 - 15], &c__100, &c__15, &dato1_1.grgc[(ini2_1.ifl << 
		    2) - 4], &dato1_1.nzgc[(ini2_1.ifl << 2) - 4], &
		    dato1_1.ngc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.xgc[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.ygc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.zgc[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual2r_(&c__2, &grad1m, &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		    dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[
		    ini2_1.ifl - 1], &dato1_1.ng[ini2_1.ifl - 1], &vl2, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	}
	r__1 = (real) ini1_1.flaps;
	manual3r_(&c__1, &dato3_1.grda1[ini2_1.ifl - 1], &dato3_1.xgda1[
		ini2_1.ifl * 200 - 200], &dato3_1.ydda1[ini2_1.ifl * 200 - 
		200], &dato3_1.zfda1[ini2_1.ifl * 10 - 10], &dato3_1.nda1[
		ini2_1.ifl * 10 - 10], &dato3_1.nzda1[ini2_1.ifl - 1], &
		grad1m, &vl1, &r__1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__0, &vl1, &dairc, ini2_1.x, &dato3_1.pda1c[ini2_1.ifl * 
		15 - 15], &c__100, &c__15, &dato3_1.grda1c[(ini2_1.ifl << 2) 
		- 4], &dato3_1.nzda1c[(ini2_1.ifl << 2) - 4], &dato3_1.nda1c[(
		(ini2_1.ifl << 2) + 1) * 15 - 75], &dato3_1.xda1c[((
		ini2_1.ifl << 2) + 1) * 100 - 500], &dato3_1.yda1c[((
		ini2_1.ifl << 2) + 1) * 100 - 500], &dato3_1.zda1c[((
		ini2_1.ifl << 2) + 1) * 15 - 75]);
	if (ie == 2) {
	    goto L10000;
	}
	resto_1.todc = togrc + dairc;
    }
    oatc = ini2_1.oat1;
    if (ini2_1.x2[2] != 0.f) {
	manual2r_(&c__1, &ini2_1.oat1, &dato1_1.xtw2i[ini2_1.ifl * 10 - 10], &
		dato1_1.ytw2i[ini2_1.ifl * 10 - 10], &dato1_1.grw2i[
		ini2_1.ifl - 1], &dato1_1.nw2i[ini2_1.ifl - 1], &oatc, &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__3, &dato1_1.grw21[ini2_1.ifl - 1], &dato1_1.xww21[
	    ini2_1.ifl * 500 - 500], &dato1_1.ytw21[ini2_1.ifl * 500 - 500], &
	    dato1_1.zhw21[ini2_1.ifl * 20 - 20], &dato1_1.nw21[ini2_1.ifl * 
	    20 - 20], &dato1_1.nzw21[ini2_1.ifl - 1], &vl1, &oatc, &ini1_1.hp,
	     &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato1_1.igam == 1) {
	corr_(&ie, &c__1, &vl2, wx, ini2_1.x, &dato1_1.pw2c[ini2_1.ifl * 15 - 
		15], &c__100, &c__15, &dato1_1.grw2c[(ini2_1.ifl << 2) - 4], &
		dato1_1.nzw2c[(ini2_1.ifl << 2) - 4], &dato1_1.nw2c[((
		ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.xw2c[((ini2_1.ifl 
		<< 2) + 1) * 100 - 500], &dato1_1.yw2c[((ini2_1.ifl << 2) + 1)
		 * 100 - 500], &dato1_1.zw2c[((ini2_1.ifl << 2) + 1) * 15 - 
		75]);
    } else if (dato1_1.igam == 2) {
	corr_(&ie, &c__1, &vl2, wx, ini2_1.x2, &dato1_1.pw2c[ini2_1.ifl * 15 
		- 15], &c__100, &c__15, &dato1_1.grw2c[(ini2_1.ifl << 2) - 4],
		 &dato1_1.nzw2c[(ini2_1.ifl << 2) - 4], &dato1_1.nw2c[((
		ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.xw2c[((ini2_1.ifl 
		<< 2) + 1) * 100 - 500], &dato1_1.yw2c[((ini2_1.ifl << 2) + 1)
		 * 100 - 500], &dato1_1.zw2c[((ini2_1.ifl << 2) + 1) * 15 - 
		75]);
    }
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__2, &dato1_1.grw22[ini2_1.ifl - 1], &dato1_1.xww22[
	    ini2_1.ifl * 300 - 300], &dato1_1.yww22[ini2_1.ifl * 300 - 300], &
	    dato1_1.zgw22[ini2_1.ifl * 30 - 30], &dato1_1.nw22[ini2_1.ifl * 
	    30 - 30], &dato1_1.nzw22[ini2_1.ifl - 1], &vl1, &vl2, &
	    resto_1.gradc, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (resto_1.gradc > dato6_1.xgfq[dato6_1.nfq[ini2_1.ifl - 1] + ini2_1.ifl 
	    * 30 - 31]) {
	resto_1.gradc = dato6_1.xgfq[dato6_1.nfq[ini2_1.ifl - 1] + ini2_1.ifl 
		* 30 - 31];
    }
    fpath_(&c__1, &ini2_1.x2[5], &resto_1.gradc, &c_b44, &dato6_1.xdfp1[
	    ini2_1.ifl * 1500 - 1500], &dato6_1.yhfp1[ini2_1.ifl * 1500 - 
	    1500], &dato6_1.zgfp1[ini2_1.ifl * 100 - 100], &dato6_1.grfp1[
	    ini2_1.ifl - 1], &dato6_1.nfp1[ini2_1.ifl * 100 - 100], &
	    dato6_1.nzfp1[ini2_1.ifl - 1], &dato6_1.xdfp2[ini2_1.ifl * 500 - 
	    500], &dato6_1.yvfp2[ini2_1.ifl * 500 - 500], &dato6_1.zdfp2[
	    ini2_1.ifl * 60 - 60], &dato6_1.grfp2[ini2_1.ifl - 1], &
	    dato6_1.nfp2[ini2_1.ifl * 60 - 60], &dato6_1.nzfp2[ini2_1.ifl - 1]
	    , &dato6_1.nfq[ini2_1.ifl - 1], &dato6_1.xgfq[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq0[ini2_1.ifl - 1], &dato6_1.ydfq0[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq1[ini2_1.ifl - 1], &dato6_1.ydfq1[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq2[ini2_1.ifl - 1], &
	    dato6_1.ydfq2[ini2_1.ifl * 30 - 30], &dato6_1.grfq3[ini2_1.ifl - 
	    1], &dato6_1.ydfq3[ini2_1.ifl * 30 - 30], &dato6_1.grfq4[
	    ini2_1.ifl - 1], &dato6_1.ydfq4[ini2_1.ifl * 30 - 30], &
	    dato6_1.grfq5[ini2_1.ifl - 1], &dato6_1.yhfq5[ini2_1.ifl * 30 - 
	    30], &dato6_1.grfq6[ini2_1.ifl - 1], &dato6_1.yhfq6[ini2_1.ifl * 
	    30 - 30], &dato6_1.grfq7[ini2_1.ifl - 1], &dato6_1.yhfq7[
	    ini2_1.ifl * 30 - 30], &dato6_1.grfq8[ini2_1.ifl - 1], &
	    dato6_1.yhfq8[ini2_1.ifl * 30 - 30], &dato6_1.grfq9[ini2_1.ifl - 
	    1], &dato6_1.yhfq9[ini2_1.ifl * 30 - 30], &np, xp, yp, &ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato6_1.nsen[ini2_1.ifl - 1] == 2) {
	fpath_(&c__1, &ini2_1.x2[5], &resto_1.gradc, &c_b44, &dato6_1.xdfpa1[
		ini2_1.ifl * 550 - 550], &dato6_1.yhfpa1[ini2_1.ifl * 550 - 
		550], &dato6_1.zgfpa1[ini2_1.ifl * 30 - 30], &dato6_1.grfpa1[
		ini2_1.ifl - 1], &dato6_1.nfpa1[ini2_1.ifl * 30 - 30], &
		dato6_1.nzfpa1[ini2_1.ifl - 1], &dato6_1.xdfpa2[ini2_1.ifl * 
		150 - 150], &dato6_1.yvfpa2[ini2_1.ifl * 150 - 150], &
		dato6_1.zdfpa2[(ini2_1.ifl << 4) - 16], &dato6_1.grfpa2[
		ini2_1.ifl - 1], &dato6_1.nfpa2[(ini2_1.ifl << 4) - 16], &
		dato6_1.nzfpa2[ini2_1.ifl - 1], &dato6_1.nfqa[ini2_1.ifl - 1],
		 &dato6_1.xgfqa[ini2_1.ifl * 30 - 30], &dato6_1.grfqa0[
		ini2_1.ifl - 1], &dato6_1.ydfqa0[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa1[ini2_1.ifl - 1], &dato6_1.ydfqa1[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa2[ini2_1.ifl - 1], &dato6_1.ydfqa2[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa3[ini2_1.ifl - 1], &
		dato6_1.ydfqa3[ini2_1.ifl * 30 - 30], &dato6_1.grfqa4[
		ini2_1.ifl - 1], &dato6_1.ydfqa4[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa5[ini2_1.ifl - 1], &dato6_1.yhfqa5[ini2_1.ifl * 
		30 - 30], &dato6_1.grfqa6[ini2_1.ifl - 1], &dato6_1.yhfqa6[
		ini2_1.ifl * 30 - 30], &dato6_1.grfqa7[ini2_1.ifl - 1], &
		dato6_1.yhfqa7[ini2_1.ifl * 30 - 30], &dato6_1.grfqa8[
		ini2_1.ifl - 1], &dato6_1.yhfqa8[ini2_1.ifl * 30 - 30], &
		dato6_1.grfqa9[ini2_1.ifl - 1], &dato6_1.yhfqa9[ini2_1.ifl * 
		30 - 30], &npa, xpa, ypa, &ie);
	if (ie == 2) {
	    goto L10000;
	}
    } else {
	npa = 0;
    }
    obscrit_(&resto_1.todc, &np, xp, yp, &npa, xpa, ypa, &dif, &ini2_1.senda[
	    ini2_1.ind - 1], &resto_1.obs_crit__, &ini2_1.nfp[ini2_1.ind - 1],
	     &ini2_1.xfp[(ini2_1.ind << 4) - 16], &ini2_1.hfp[(ini2_1.ind << 
	    4) - 16], &ie);
    if (ie > 0) {
	goto L10000;
    }
    ret_val = dif;
    resto_1.ierd = 0;
    return ret_val;
L10000:
    resto_1.ierd = 2;
    ret_val = 0.f;
    return ret_val;
} /* difobst_ */

/* Subroutine */ int ldspeed_(real *flp, real *wx, real *vthx, integer *ie)
{
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), manual3r_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, integer *);
    static real vl1, vthmin;
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *);

    resld_1.codv = 0;
    manual3r_(&c__3, dald3_1.grvr1, dald3_1.xsvr1, dald3_1.ysvr1, 
	    dald3_1.zwvr1, dald3_1.nvr1, dald3_1.nzvr1, &vl1, &resld_1.vth1, 
	    wx, ie);
    if (*ie == 2) {
	return 0;
    }
    corr_(ie, &c__0, &vl1, &vthmin, ini2_1.x, &dald3_1.pvr1c[ini2_1.ifl * 15 
	    - 15], &c__100, &c__10, &dald3_1.grvr1c[ini2_1.ifl * 3 - 3], &
	    dald3_1.nzvr1c[ini2_1.ifl * 3 - 3], &dald3_1.nvr1c[(ini2_1.ifl * 
	    3 + 1) * 10 - 40], &dald3_1.xvr1c[(ini2_1.ifl * 3 + 1) * 100 - 
	    400], &dald3_1.yvr1c[(ini2_1.ifl * 3 + 1) * 100 - 400], &
	    dald3_1.zvr1c[(ini2_1.ifl * 3 + 1) * 10 - 40]);
    if (*ie == 2) {
	return 0;
    }
    if (resld_1.iopice == 0) {
	manual3r_(&c__1, dald3_1.grvr2, dald3_1.xwvr2, dald3_1.ysvr2, 
		dald3_1.zfvr2, dald3_1.nvr2, dald3_1.nzvr2, wx, &vl1, flp, ie)
		;
	if (*ie == 2) {
	    return 0;
	}
	*vthx = vthmin;
	if (vl1 > *vthx) {
	    *vthx = vl1;
	}
    } else {
	manual3r_(&c__1, dald3_1.grvr3, dald3_1.xwvr3, dald3_1.ysvr3, 
		dald3_1.zfvr3, dald3_1.nvr3, dald3_1.nzvr3, wx, &vl1, flp, ie)
		;
	if (*ie == 2) {
	    return 0;
	}
	*vthx = vthmin;
	if (vl1 > *vthx) {
	    *vthx = vl1;
	}
	resld_1.codv = 2;
    }
    ini2_1.x[8] = 0.f;
    if (resld_1.mil > 0 && ini1_1.xwind > 0.f && resld_1.vthc < resld_1.vthr 
	    && resld_1.iopxw != 0) {
	if (resld_1.vthc + resld_1.add < resld_1.vthr) {
	    ini2_1.x[8] = resld_1.add;
	    resld_1.vthc += resld_1.add;
	} else {
	    ini2_1.x[8] = resld_1.vthr - resld_1.vthc;
	    resld_1.vthc = resld_1.vthr;
	}
	if (resld_1.codv == 2) {
	    resld_1.codv = 3;
	} else {
	    resld_1.codv = 1;
	}
    }
    manual2r_(&c__1, flp, dagen3_1.dff, dagen3_1.limdff, &c_n1, &
	    dagen3_1.ndff, &vl1, ie);
    if (*ie == 2) {
	return 0;
    }
    if (*vthx > vl1) {
	*ie = 600;
	return 0;
    }
    *ie = 0;
    return 0;
} /* ldspeed_ */

doublereal ldist_(real *wx)
{
    /* System generated locals */
    real ret_val, r__1;

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer ie;
    static real vl1;
    extern /* Subroutine */ int corr_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *), ldspeed_(real *, real *, real 
	    *, integer *);

    r__1 = (real) ini2_1.fld;
    ldspeed_(&r__1, wx, &resld_1.vthc, &ie);
    if (ie > 0) {
	goto L10000;
    }
    ini2_1.x[0] = ini1_1.dind;
    if (dald2_1.indgr[ini2_1.ifl - 1] == 0) {
	manual3r_(&c__1, &dald2_1.grgr2[ini2_1.ifl - 1], &dald2_1.xgr2[
		ini2_1.ifl * 500 - 500], &dald2_1.ydgr2[ini2_1.ifl * 500 - 
		500], &dald2_1.zgr2[ini2_1.ifl * 20 - 20], &dald2_1.ngr2[
		ini2_1.ifl * 20 - 20], &dald2_1.nzgr2[ini2_1.ifl - 1], wx, &
		vl1, &resld_1.lgr1, &ie);
    } else if (dald2_1.indgr[ini2_1.ifl - 1] == 1) {
	manual3r_(&c__1, &dald2_1.grgr1[ini2_1.ifl - 1], &dald2_1.xgr1[
		ini2_1.ifl * 500 - 500], &dald2_1.ydgr1[ini2_1.ifl * 500 - 
		500], &dald2_1.zhgr1[ini2_1.ifl * 20 - 20], &dald2_1.ngr1[
		ini2_1.ifl * 20 - 20], &dald2_1.nzgr1[ini2_1.ifl - 1], wx, &
		vl1, &ini1_1.hp, &ie);
    } else {
	manual3r_(&c__3, &dald2_1.grgr2[ini2_1.ifl - 1], &dald2_1.xgr2[
		ini2_1.ifl * 500 - 500], &dald2_1.ydgr2[ini2_1.ifl * 500 - 
		500], &dald2_1.zgr2[ini2_1.ifl * 20 - 20], &dald2_1.ngr2[
		ini2_1.ifl * 20 - 20], &dald2_1.nzgr2[ini2_1.ifl - 1], &vl1, &
		resld_1.lgr1, wx, &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &resld_1.lgrc, ini2_1.x, &dald2_1.pgrc[ini2_1.ifl 
	    * 15 - 15], &c__180, &c__20, &dald2_1.grgrc[(ini2_1.ifl << 3) - 8]
	    , &dald2_1.nzgrc[(ini2_1.ifl << 3) - 8], &dald2_1.ngrc[((
	    ini2_1.ifl << 3) + 1) * 20 - 180], &dald2_1.xgrc[((ini2_1.ifl << 
	    3) + 1) * 180 - 1620], &dald2_1.ygrc[((ini2_1.ifl << 3) + 1) * 
	    180 - 1620], &dald2_1.zgrc[((ini2_1.ifl << 3) + 1) * 20 - 180]);
    if (ie == 2) {
	goto L10000;
    }
    resld_1.lgrc += ini2_1.delcbr;
    if (dald2_1.indld[ini2_1.ifl - 1] == 0) {
	manual3r_(&c__1, &dald2_1.grld2[ini2_1.ifl - 1], &dald2_1.xld2[
		ini2_1.ifl * 500 - 500], &dald2_1.ydld2[ini2_1.ifl * 500 - 
		500], &dald2_1.zld2[ini2_1.ifl * 20 - 20], &dald2_1.nld2[
		ini2_1.ifl * 20 - 20], &dald2_1.nzld2[ini2_1.ifl - 1], wx, &
		vl1, &resld_1.ldt1, &ie);
    } else if (dald2_1.indld[ini2_1.ifl - 1] == 1) {
	manual3r_(&c__1, &dald2_1.grld1[ini2_1.ifl - 1], &dald2_1.xld1[
		ini2_1.ifl * 500 - 500], &dald2_1.ydld1[ini2_1.ifl * 500 - 
		500], &dald2_1.zhld1[ini2_1.ifl * 20 - 20], &dald2_1.nld1[
		ini2_1.ifl * 20 - 20], &dald2_1.nzld1[ini2_1.ifl - 1], wx, &
		vl1, &ini1_1.hp, &ie);
    } else {
	manual3r_(&c__3, &dald2_1.grld2[ini2_1.ifl - 1], &dald2_1.xld2[
		ini2_1.ifl * 500 - 500], &dald2_1.ydld2[ini2_1.ifl * 500 - 
		500], &dald2_1.zld2[ini2_1.ifl * 20 - 20], &dald2_1.nld2[
		ini2_1.ifl * 20 - 20], &dald2_1.nzld2[ini2_1.ifl - 1], &vl1, &
		resld_1.ldt1, wx, &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &resld_1.ldtc, ini2_1.x, &dald2_1.pldc[ini2_1.ifl 
	    * 15 - 15], &c__180, &c__20, &dald2_1.grldc[(ini2_1.ifl << 3) - 8]
	    , &dald2_1.nzldc[(ini2_1.ifl << 3) - 8], &dald2_1.nldc[((
	    ini2_1.ifl << 3) + 1) * 20 - 180], &dald2_1.xldc[((ini2_1.ifl << 
	    3) + 1) * 180 - 1620], &dald2_1.yldc[((ini2_1.ifl << 3) + 1) * 
	    180 - 1620], &dald2_1.zldc[((ini2_1.ifl << 3) + 1) * 20 - 180]);
    if (ie == 2) {
	goto L10000;
    }
    resld_1.ldtc += ini2_1.delcbr;
    if (ini1_1.del_rwy__ >= 0.f) {
	if (ini1_1.del_rwy__ > 0.f && ini1_1.del_rwy__ <= 1.f) {
	    resld_1.lflc = resld_1.ldtc / ini1_1.del_rwy__;
	} else {
	    resld_1.lflc = resld_1.ldtc + ini1_1.del_rwy__;
	}
	ret_val = resld_1.ldtc - resld_1.dist;
    } else {
	vl1 = dabs(ini1_1.del_rwy__);
	if (vl1 <= 1.f) {
	    resld_1.lflc = resld_1.lgrc / vl1;
	} else {
	    resld_1.lflc = resld_1.lgrc + vl1;
	}
	ret_val = resld_1.lgrc - resld_1.dist;
    }
    resld_1.ierd = 0;
    ini2_1.x[0] = ini1_1.dind1;
    return ret_val;
L10000:
    resld_1.ierd = ie;
    ini2_1.x[0] = ini1_1.dind1;
    ret_val = 0.f;
    return ret_val;
} /* ldist_ */

/* Subroutine */ int vldin_(integer *flp, integer *segl, real *vmcl1, real *
	vga1, real *grad1, real *grad2, integer *ie)
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), manual3r_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, integer *);
    static real vl1, oatc;

    r__1 = (real) (*flp);
    manual2r_(&c__1, &r__1, dagen3_1.dff, dagen3_1.segdff, &c_n1, &
	    dagen3_1.ndff, &vl1, ie);
    if (*ie == 2) {
	return 0;
    }
    *segl = i_nint(&vl1);
    oatc = ini2_1.oat1;
    if (ini1_1.system[1] == 1) {
	manual2r_(&c__1, &ini2_1.oat1, &dald3_1.xtvti[ini2_1.ifl * 10 - 10], &
		dald3_1.ytvti[ini2_1.ifl * 10 - 10], &dald3_1.grvti[
		ini2_1.ifl - 1], &dald3_1.nvti[ini2_1.ifl - 1], &oatc, ie);
    }
    if (*ie == 2) {
	return 0;
    }
    manual3r_(&c__1, &dald3_1.grvt[ini2_1.ifl - 1], &dald3_1.xtvt[ini2_1.ifl *
	     500 - 500], &dald3_1.ysvt[ini2_1.ifl * 500 - 500], &dald3_1.zhvt[
	    ini2_1.ifl * 20 - 20], &dald3_1.nvt[ini2_1.ifl * 20 - 20], &
	    dald3_1.nzvt[ini2_1.ifl - 1], &oatc, vmcl1, &ini1_1.hp, ie);
    if (*ie == 2) {
	return 0;
    }
    resld_1.vth1 = *vmcl1;
    *vga1 = *vmcl1;
    *ie = 0;
    oatc = ini2_1.oat2;
    if (ini1_1.system[1] == 1) {
	manual2r_(&c__1, &ini2_1.oat2, &dald1_1.xtgai[ini2_1.ifl * 10 - 10], &
		dald1_1.ytgai[ini2_1.ifl * 10 - 10], &dald1_1.grgai[
		ini2_1.ifl - 1], &dald1_1.ngai[ini2_1.ifl - 1], &oatc, ie);
    }
    if (*ie == 2) {
	return 0;
    }
    manual3r_(&c__1, &dald1_1.grga1[ini2_1.ifl - 1], &dald1_1.xtga1[
	    ini2_1.ifl * 500 - 500], &dald1_1.yga1[ini2_1.ifl * 500 - 500], &
	    dald1_1.zhga1[ini2_1.ifl * 20 - 20], &dald1_1.nga1[ini2_1.ifl * 
	    20 - 20], &dald1_1.nzga1[ini2_1.ifl - 1], &oatc, grad1, &
	    ini1_1.hp, ie);
    if (*ie == 2) {
	return 0;
    }
    *ie = 0;
    oatc = ini2_1.oat2;
    if (ini1_1.system[1] == 1) {
	manual2r_(&c__1, &ini2_1.oat2, &dald1_1.xtbli[ini2_1.ifl * 10 - 10], &
		dald1_1.ytbli[ini2_1.ifl * 10 - 10], &dald1_1.grbli[
		ini2_1.ifl - 1], &dald1_1.nbli[ini2_1.ifl - 1], &oatc, ie);
    }
    if (*ie == 2) {
	return 0;
    }
    manual3r_(&c__1, &dald1_1.grbl1[ini2_1.ifl - 1], &dald1_1.xtbl1[
	    ini2_1.ifl * 500 - 500], &dald1_1.ybl1[ini2_1.ifl * 500 - 500], &
	    dald1_1.zhbl1[ini2_1.ifl * 20 - 20], &dald1_1.nbl1[ini2_1.ifl * 
	    20 - 20], &dald1_1.nzbl1[ini2_1.ifl - 1], &oatc, grad2, &
	    ini1_1.hp, ie);
    if (*ie == 2) {
	return 0;
    }
    if (dald2_1.indgr[ini2_1.ifl - 1] != 1) {
	manual3r_(&c__1, &dald2_1.grgr1[ini2_1.ifl - 1], &dald2_1.xgr1[
		ini2_1.ifl * 500 - 500], &dald2_1.ydgr1[ini2_1.ifl * 500 - 
		500], &dald2_1.zhgr1[ini2_1.ifl * 20 - 20], &dald2_1.ngr1[
		ini2_1.ifl * 20 - 20], &dald2_1.nzgr1[ini2_1.ifl - 1], &
		ini2_1.oat2, &resld_1.lgr1, &ini1_1.hp, ie);
	if (*ie == 2) {
	    return 0;
	}
    }
    if (dald2_1.indld[ini2_1.ifl - 1] != 1) {
	manual3r_(&c__1, &dald2_1.grld1[ini2_1.ifl - 1], &dald2_1.xld1[
		ini2_1.ifl * 500 - 500], &dald2_1.ydld1[ini2_1.ifl * 500 - 
		500], &dald2_1.zhld1[ini2_1.ifl * 20 - 20], &dald2_1.nld1[
		ini2_1.ifl * 20 - 20], &dald2_1.nzld1[ini2_1.ifl - 1], &
		ini2_1.oat2, &resld_1.ldt1, &ini1_1.hp, ie);
	if (*ie == 2) {
	    return 0;
	}
    }
    *ie = 0;
    return 0;
} /* vldin_ */

