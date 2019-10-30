/* SCAC.F -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__100 = 100;
static integer c__15 = 15;
static integer c__5 = 5;
static integer c_n1 = -1;

/* Subroutine */ int corr_(integer *ierr, integer *meto, real *y, real *ycor, 
	real *x, integer *a, integer *nmx, integer *nmz, integer *gr, integer 
	*nz, integer *n, real *x1, real *y1, real *z1)
{
    /* System generated locals */
    integer n_dim1, n_offset, z1_dim1, z1_offset, x1_dim1, x1_offset, y1_dim1,
	     y1_offset;

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer i__, ie;
    static real yc, yz;

    /* Parameter adjustments */
    --x;
    --a;
    y1_dim1 = *nmx;
    y1_offset = 1 + y1_dim1;
    y1 -= y1_offset;
    x1_dim1 = *nmx;
    x1_offset = 1 + x1_dim1;
    x1 -= x1_offset;
    z1_dim1 = *nmz;
    z1_offset = 1 + z1_dim1;
    z1 -= z1_offset;
    n_dim1 = *nmz;
    n_offset = 1 + n_dim1;
    n -= n_offset;
    --gr;
    --nz;

    /* Function Body */
    *ierr = 0;
    if (*meto == 0) {
	yz = *y;
	if (a[1] > 0) {
	    for (i__ = 1; i__ <= 10; ++i__) {
		if (a[i__] > 0) {
		    manual3r_(&c__1, &gr[i__], &x1[i__ * x1_dim1 + 1], &y1[
			    i__ * y1_dim1 + 1], &z1[i__ * z1_dim1 + 1], &n[
			    i__ * n_dim1 + 1], &nz[i__], &x[a[i__]], &yc, &yz,
			     &ie);
		    if (ie == 2) {
			goto L1000;
		    }
		    yz = yc;
		}
	    }
	}
	*ycor = yz;
    } else if (*meto == 1) {
	yz = *ycor;
	if (a[1] > 0) {
	    for (i__ = 10; i__ >= 1; --i__) {
		if (a[i__] > 0) {
		    manual3r_(&c__2, &gr[i__], &x1[i__ * x1_dim1 + 1], &y1[
			    i__ * y1_dim1 + 1], &z1[i__ * z1_dim1 + 1], &n[
			    i__ * n_dim1 + 1], &nz[i__], &x[a[i__]], &yz, &yc,
			     &ie);
		    if (ie == 2) {
			goto L1000;
		    }
		    yz = yc;
		}
	    }
	}
	*y = yz;
    } else {
	goto L1000;
    }
    return 0;
L1000:
    *ierr = 2;
    return 0;
} /* corr_ */

/* Subroutine */ int vrspeed_(real *vin, real *vrm, real *tow, real *vro, 
	integer *ie, integer *gr1, integer *nz1, integer *n1, real *zw1, real 
	*xs1, real *ys1, integer *gr2, integer *nz2, integer *n2, real *zw2, 
	real *xs2, real *ys2, integer *gr3, integer *n3, real *xw3, real *ys3)
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static real var[5];
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , manual2r_(integer *, real *, real *, real *, integer *, integer 
	    *, real *, integer *), corr_(integer *, integer *, real *, real *,
	     real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *);

    /* Parameter adjustments */
    --ys3;
    --xw3;
    --ys2;
    --xs2;
    --zw2;
    --n2;
    --ys1;
    --xs1;
    --zw1;
    --n1;

    /* Function Body */
    manual3r_(&c__3, gr1, &xs1[1], &ys1[1], &zw1[1], &n1[1], nz1, var, vin, 
	    tow, ie);
    if (*ie == 2) {
	return 0;
    }
    manual3r_(&c__3, gr2, &xs2[1], &ys2[1], &zw2[1], &n2[1], nz2, &var[1], 
	    vin, tow, ie);
    if (*ie == 2) {
	return 0;
    }
    manual2r_(&c__1, tow, &xw3[1], &ys3[1], gr3, n3, &var[2], ie);
    if (*ie == 2) {
	return 0;
    }
    var[3] = dmax(var[1],var[2]);
    corr_(ie, &c__0, &var[3], &var[4], ini2_1.x, &dato5_1.pvroc[ini2_1.ifl * 
	    15 - 15], &c__100, &c__15, &dato5_1.grvroc[ini2_1.ifl * 3 - 3], &
	    dato5_1.nzvroc[ini2_1.ifl * 3 - 3], &dato5_1.nvroc[(ini2_1.ifl * 
	    3 + 1) * 15 - 60], &dato5_1.xvroc[(ini2_1.ifl * 3 + 1) * 100 - 
	    400], &dato5_1.yvroc[(ini2_1.ifl * 3 + 1) * 100 - 400], &
	    dato5_1.zvroc[(ini2_1.ifl * 3 + 1) * 15 - 60]);
    if (*ie == 2) {
	return 0;
    }
/* Computing MAX */
    r__1 = max(var[0],var[4]);
    *vro = dmax(r__1,*vrm);
    *ie = 0;
    return 0;
} /* vrspeed_ */

/* Subroutine */ int tospeed_(real *vin, real *tow, real *v2x, real *vfretx, 
	real *vftox, integer *ie, integer *gr1, integer *nz1, integer *n1, 
	real *zw1, real *xs1, real *ys1, integer *gr2, integer *n, real *xw, 
	real *ys2, integer *gr3, real *ys3, integer *gr4, real *ys4, integer *
	gr5, real *ys5, real *dvrf1x, real *dvrf2x, real *dvftox)
{
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    , manual2r_(integer *, real *, real *, real *, integer *, integer 
	    *, real *, integer *), corr_(integer *, integer *, real *, real *,
	     real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *);
    static real dv, va2[3], vl1;

    /* Parameter adjustments */
    --ys5;
    --ys4;
    --ys3;
    --ys2;
    --xw;
    --ys1;
    --xs1;
    --zw1;
    --n1;
    --vfretx;

    /* Function Body */
    manual3r_(&c__1, gr1, &ys1[1], &xs1[1], &zw1[1], &n1[1], nz1, vin, va2, 
	    tow, ie);
    if (*ie == 2) {
	return 0;
    }
    manual2r_(&c__1, tow, &xw[1], &ys2[1], gr2, n, &va2[1], ie);
    if (*ie == 2) {
	return 0;
    }
    corr_(ie, &c__0, &va2[1], &va2[2], ini2_1.x, &dato5_1.pv2c[ini2_1.ifl * 
	    15 - 15], &c__100, &c__15, &dato5_1.grv2c[ini2_1.ifl * 3 - 3], &
	    dato5_1.nzv2c[ini2_1.ifl * 3 - 3], &dato5_1.nv2c[(ini2_1.ifl * 3 
	    + 1) * 15 - 60], &dato5_1.xv2c[(ini2_1.ifl * 3 + 1) * 100 - 400], 
	    &dato5_1.yv2c[(ini2_1.ifl * 3 + 1) * 100 - 400], &dato5_1.zv2c[(
	    ini2_1.ifl * 3 + 1) * 15 - 60]);
    if (*ie == 2) {
	return 0;
    }
    *v2x = dmax(va2[0],va2[2]);
    manual2r_(&c__1, tow, &xw[1], &ys3[1], gr3, n, &vfretx[1], ie);
    if (*ie == 2) {
	return 0;
    }
    if (vfretx[1] != 0.f || *dvrf1x != 0.f) {
	vl1 = *v2x + *dvrf1x;
	if (vl1 > vfretx[1]) {
	    vfretx[1] = vl1;
	}
    }
    if (ini2_1.x[8] > 0.f) {
	manual2r_(&c__1, &ini2_1.x[8], dato5_1.xdvrf1c, dato5_1.ydvrf1c, 
		dato5_1.grdvrf1c, dato5_1.ndvrf1c, &dv, ie);
	if (*ie == 2) {
	    return 0;
	}
	vfretx[1] += dv;
    }
    manual2r_(&c__1, tow, &xw[1], &ys4[1], gr4, n, &vfretx[2], ie);
    if (*ie == 2) {
	return 0;
    }
    if (vfretx[2] != 0.f || *dvrf2x != 0.f) {
	vl1 = *v2x + *dvrf2x;
	if (vl1 > vfretx[2]) {
	    vfretx[2] = vl1;
	}
    }
    if (ini2_1.x[8] > 0.f) {
	manual2r_(&c__1, &ini2_1.x[8], dato5_1.xdvrf2c, dato5_1.ydvrf2c, 
		dato5_1.grdvrf2c, dato5_1.ndvrf2c, &dv, ie);
	if (*ie == 2) {
	    return 0;
	}
	vfretx[2] += dv;
    }
    manual2r_(&c__1, tow, &xw[1], &ys5[1], gr5, n, vftox, ie);
    if (*ie == 2) {
	return 0;
    }
    vl1 = *v2x + *dvftox;
    if (vl1 > *vftox) {
	*vftox = vl1;
    }
    if (ini2_1.x[8] > 0.f) {
	manual2r_(&c__1, &ini2_1.x[8], dato5_1.xdvftoc, dato5_1.ydvftoc, 
		dato5_1.grdvftoc, dato5_1.ndvftoc, &dv, ie);
	if (*ie == 2) {
	    return 0;
	}
	*vftox += dv;
    }
    *ie = 0;
    return 0;
} /* tospeed_ */

/* Subroutine */ int fpath_(integer *mil, real *wind, real *gref, real *hscr, 
	real *xfp1, real *yfp1, real *zfp1, integer *grfp1, integer *nfp1, 
	integer *nzfp1, real *xfp2, real *yfp2, real *zfp2, integer *grfp2, 
	integer *nfp2, integer *nzfp2, integer *nfq, real *xfq, integer *
	grfq0, real *yfq0, integer *grfq1, real *yfq1, integer *grfq2, real *
	yfq2, integer *grfq3, real *yfq3, integer *grfq4, real *yfq4, integer 
	*grfq5, real *yfq5, integer *grfq6, real *yfq6, integer *grfq7, real *
	yfq7, integer *grfq8, real *yfq8, integer *grfq9, real *yfq9, integer 
	*np, real *xp, real *hp, integer *ierr)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *), manual3r_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, integer *);
    static real d__[6];
    static integer i__, j, k;
    static real y[6];
    static integer k1;
    static real dc[6];
    static integer ie, nd;
    static real vl;
    static integer kx, nx[100];
    static real xx[10000], yx[10000], zx[100];
    static integer kx1;
    static real del;
    static integer grx, nzx;
    static real gcal, dniv;
    static integer intrc[6];

    /* Parameter adjustments */
    --hp;
    --xp;
    --yfq9;
    --yfq8;
    --yfq7;
    --yfq6;
    --yfq5;
    --yfq4;
    --yfq3;
    --yfq2;
    --yfq1;
    --yfq0;
    --xfq;
    --nfp2;
    --zfp2;
    --yfp2;
    --xfp2;
    --nfp1;
    --zfp1;
    --yfp1;
    --xfp1;

    /* Function Body */
    *ierr = 0;
    for (i__ = 1; i__ <= 6; ++i__) {
	d__[i__ - 1] = 0.f;
	dc[i__ - 1] = 0.f;
	y[i__ - 1] = 0.f;
    }
    gcal = *gref;
    del = zfp1[*nzfp1];
    if (del < zfp1[1]) {
	del = zfp1[1];
    }
    if (gcal > del) {
	gcal = del;
    }
    if (*mil == 1) {
	y[0] = *hscr;
	grx = *grfp1;
	nzx = *nzfp1;
	k = 0;
	kx = 0;
	kx1 = 0;
	k1 = 0;
	i__1 = *nzfp1;
	for (j = 1; j <= i__1; ++j) {
	    zx[j - 1] = zfp1[j];
	    dniv = -1.f;
	    i__ = 0;
	    while(dniv < 0.f && i__ < nfp1[j]) {
		++i__;
		if (yfp1[i__ + 1 + k1] == yfp1[i__ + k1]) {
		    dniv = xfp1[k1 + i__];
		}
	    }
	    if (dniv < 0.f) {
		dniv = xfp1[nfp1[j] + k1];
	    }
	    i__2 = nfp1[j];
	    for (i__ = 1; i__ <= i__2; ++i__) {
		++k;
		if (xfp1[k] <= dniv) {
		    ++kx;
		    ++kx1;
		    xx[kx - 1] = xfp1[k];
		    yx[kx - 1] = yfp1[k];
		}
	    }
	    nx[j - 1] = kx1;
	    kx1 = 0;
	    k1 += nfp1[j];
	}
	manual3r_(&c__3, &grx, xx, yx, zx, nx, &nzx, d__, hscr, &gcal, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (d__[0] < -1e-4f) {
	    *ierr = 3;
	    return 0;
	}
    } else {
	if (yfp1[1] != 0.f) {
	    if (yfp1[1] == *hscr) {
		y[0] = *hscr;
	    } else {
		*ierr = 3;
		return 0;
	    }
	}
    }
    ie = 0;
    if (yfq0[1] > 0.f) {
	manual2r_(&c__1, &gcal, &xfq[1], &yfq0[1], grfq0, nfq, &d__[1], &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    if (yfq1[1] > 0.f) {
	manual2r_(&c__1, &gcal, &xfq[1], &yfq1[1], grfq1, nfq, &d__[2], &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    if (yfq2[1] > 0.f) {
	manual2r_(&c__1, &gcal, &xfq[1], &yfq2[1], grfq2, nfq, &d__[3], &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    if (yfq3[1] > 0.f) {
	manual2r_(&c__1, &gcal, &xfq[1], &yfq3[1], grfq3, nfq, &d__[4], &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    if (yfq4[1] > 0.f) {
	manual2r_(&c__1, &gcal, &xfq[1], &yfq4[1], grfq4, nfq, &d__[5], &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    nd = 1;
    for (i__ = 2; i__ <= 6; ++i__) {
	if (d__[i__ - 1] > 0.f && d__[i__ - 1] > d__[i__ - 2]) {
	    ++nd;
	}
    }
    if (nd <= 1) {
	*ierr = 1;
	return 0;
    }
    i__1 = nd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ie = 0;
	if (i__ == 2) {
	    manual2r_(&c__1, &gcal, &xfq[1], &yfq5[1], grfq5, nfq, &y[1], &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (i__ == 3) {
	    manual2r_(&c__1, &gcal, &xfq[1], &yfq6[1], grfq6, nfq, &y[2], &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (i__ == 4) {
	    manual2r_(&c__1, &gcal, &xfq[1], &yfq7[1], grfq7, nfq, &y[3], &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (i__ == 5) {
	    manual2r_(&c__1, &gcal, &xfq[1], &yfq8[1], grfq8, nfq, &y[4], &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (i__ == 6) {
	    manual2r_(&c__1, &gcal, &xfq[1], &yfq9[1], grfq9, nfq, &y[5], &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (d__[i__ - 1] > 0.f) {
	    manual3r_(&c__5, grfp2, &xfp2[1], &yfp2[1], &zfp2[1], &nfp2[1], 
		    nzfp2, &d__[i__ - 1], wind, &dc[i__ - 1], &ie);
	}
	if (ie == 2) {
	    goto L10000;
	}
    }
    if (nd == 2) {
	intrc[0] = 14;
    }
    if (nd == 3) {
	intrc[0] = 7;
	intrc[1] = 6;
    }
    if (nd == 4) {
	intrc[0] = 4;
	intrc[1] = 4;
	intrc[2] = 4;
    }
    if (nd == 5) {
	intrc[0] = 3;
	intrc[1] = 3;
	intrc[2] = 3;
	intrc[3] = 2;
    }
    if (nd == 6) {
	for (i__ = 1; i__ <= 5; ++i__) {
	    intrc[i__ - 1] = 2;
	}
    }
    i__1 = nd - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (y[i__ - 1] == y[i__] || d__[i__] - d__[i__ - 1] < .5f) {
	    if (i__ == 1) {
		if (y[i__ - 1] == y[i__]) {
		    *ierr = 1;
		    return 0;
		}
	    } else {
		j = i__ - 1;
		while(intrc[i__ - 1] > 0) {
		    if (intrc[j - 1] > 0) {
			++intrc[j - 1];
			--intrc[i__ - 1];
		    }
		    --j;
		    if (j == 0) {
			j = i__ - 1;
		    }
		}
	    }
	}
    }
    *np = 1;
    xp[1] = dc[0];
    hp[1] = y[0];
    i__1 = nd;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (intrc[i__ - 2] > 0) {
	    del = (dc[i__ - 1] - dc[i__ - 2]) / (real) (intrc[i__ - 2] + 1);
	    i__2 = intrc[i__ - 2];
	    for (j = 1; j <= i__2; ++j) {
		++(*np);
		xp[*np] = xp[*np - 1] + del;
		manual3r_(&c__3, grfp2, &xfp2[1], &yfp2[1], &zfp2[1], &nfp2[1]
			, nzfp2, &vl, wind, &xp[*np], &ie);
		if (ie == 2) {
		    goto L10000;
		}
		manual3r_(&c__1, grfp1, &xfp1[1], &yfp1[1], &zfp1[1], &nfp1[1]
			, nzfp1, &vl, &hp[*np], &gcal, &ie);
		if (ie == 2) {
		    goto L10000;
		}
	    }
	}
	++(*np);
	xp[*np] = dc[i__ - 1];
	hp[*np] = y[i__ - 1];
    }
    xp[1] = 0.f;
    i__1 = *np;
    for (i__ = 2; i__ <= i__1; ++i__) {
	xp[i__] -= dc[0];
    }
    if (*mil != 1 && y[0] == 0.f) {
	i__1 = *np;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    hp[i__] += 35.f;
	}
    }
    return 0;
L10000:
    *ierr = 2;
    return 0;
} /* fpath_ */

/* Subroutine */ int init_(integer *indi, integer *mil, integer *nsenda, 
	integer *vii, real *vir, integer *voi, real *vor, integer *ierr)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *);
    static integer i__, ie, in;
    static real vl1;
    static integer npt;
    static real gaml;
    static integer imin, imax;
    static real oati, oats, wmax, vmax, vmin;
    extern /* Subroutine */ int agape_(real *, real *, real *, integer *, 
	    integer *, integer *);
    static real limwc, ewmin, oat_std__;

    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;
    --nsenda;

    /* Function Body */
    *ierr = 0;
    in = 2;
    if (*indi == 1) {
	in = 1;
    }
    if (*indi == 0) {
	goto L20;
    }
    ini1_1.flaps = vii[4];
    ini1_1.system[0] = vii[7];
    ini1_1.system[1] = vii[8];
    ini1_1.system[2] = vii[9];
    ini1_1.system[3] = vii[10];
    if (*indi == 1) {
	ini1_1.nobs = vii[12];
	ini1_1.nobp = vii[17];
	if (ini1_1.nobs < 0 || ini1_1.nobs > 30 || ini1_1.nobp < 0 || 
		ini1_1.nobp > 30) {
	    *ierr = 156;
	    return 0;
	}
    }
    ini1_1.sup[0] = vii[13];
    ini1_1.sup[1] = vii[14];
    ini1_1.sup[2] = vii[15];
    ini1_1.sup[3] = vii[16];
    ewmin = vir[1];
    ini1_1.emw = vir[2];
    ini1_1.aw = (real) i_nint(&vir[3]);
    ini1_1.fact[0] = vir[4];
    ini1_1.fact[1] = vir[5];
    ini1_1.gs = vir[7];
    ini1_1.del_rwy__ = vir[9];
    if (*indi == 1) {
	ini1_1.del_obs__ = vir[10];
    }
    ini1_1.dind = vir[12];
    ini1_1.dind1 = vir[13];
    ini1_1.cbr = vir[14];
    ini1_1.rwy = vir[15];
    if (*indi == 1) {
	ini1_1.swy = vir[16];
	ini1_1.cwy = vir[17];
    }
    ini1_1.slope = vir[18];
    ini1_1.temp = vir[19];
    ini1_1.wind = vir[20];
    ini1_1.hp = vir[21];
    ini1_1.xwind = dabs(vir[22]);
    if (*indi == 1) {
	if (ini1_1.nobs > 0) {
	    i__1 = ini1_1.nobs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		ini1_1.xobs[i__ - 1] = vir[(i__ << 1) + 29];
		ini1_1.hobs[i__ - 1] = vir[(i__ << 1) + 30];
	    }
	}
	if (ini1_1.nobs < 30) {
	    for (i__ = ini1_1.nobs + 1; i__ <= 30; ++i__) {
		ini1_1.xobs[i__ - 1] = 0.f;
		ini1_1.hobs[i__ - 1] = 0.f;
	    }
	}
	if (ini1_1.nobp > 0) {
	    i__1 = ini1_1.nobp;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		ini1_1.xobp[i__ - 1] = vir[(i__ << 1) + 49];
		ini1_1.hobp[i__ - 1] = vir[(i__ << 1) + 50];
	    }
	}
	if (ini1_1.nobp < 30) {
	    for (i__ = ini1_1.nobp + 1; i__ <= 30; ++i__) {
		ini1_1.xobp[i__ - 1] = 0.f;
		ini1_1.hobp[i__ - 1] = 0.f;
	    }
	}
    }
    for (i__ = 1; i__ <= 25; ++i__) {
	voi[i__] = 0;
	vor[i__] = 0.f;
    }
    for (i__ = 26; i__ <= 200; ++i__) {
	vor[i__] = 0.f;
    }
    ini2_1.mw = 0.f;
    if (*indi == 1) {
	for (i__ = 1; i__ <= 4; ++i__) {
	    for (ie = 1; ie <= 2; ++ie) {
		ini2_1.ilim[i__ + (ie << 2) - 5] = 0;
	    }
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    ini2_1.x[i__ - 1] = 0.f;
	    ini2_1.x2[i__ - 1] = 0.f;
	}
	for (i__ = 1; i__ <= 2; ++i__) {
	    ini2_1.altacc[i__ - 1] = 0.f;
	    ini2_1.senda[i__ - 1] = 0;
	    ini2_1.vmcg[i__ - 1] = 0.f;
	    ini2_1.vr[i__ - 1] = 0.f;
	    ini2_1.v2[i__ - 1] = 0.f;
	    ini2_1.fret[i__ - 1] = 0.f;
	    ini2_1.vfto[i__ - 1] = 0.f;
	    ini2_1.tqto[i__ - 1] = 0.f;
	    ini2_1.itt[i__ - 1] = 0.f;
	    ini2_1.tqmc[i__ - 1] = 0.f;
	}
	for (ie = 1; ie <= 3; ++ie) {
	    for (i__ = 1; i__ <= 2; ++i__) {
		ini2_1.v1[ie + i__ * 3 - 4] = 0.f;
		ini2_1.asd[ie + i__ * 3 - 4] = 0.f;
		ini2_1.tor[ie + i__ * 3 - 4] = 0.f;
		ini2_1.tod[ie + i__ * 3 - 4] = 0.f;
		ini2_1.grad[ie + i__ * 3 - 4] = 0.f;
		ini2_1.rc[ie + i__ * 3 - 4] = 0.f;
	    }
	}
	for (ie = 1; ie <= 2; ++ie) {
	    for (i__ = 1; i__ <= 2; ++i__) {
		ini2_1.vfret[ie + (i__ << 1) - 3] = 0.f;
	    }
	}
	for (ie = 1; ie <= 16; ++ie) {
	    for (i__ = 1; i__ <= 2; ++i__) {
		ini2_1.xfp[ie + (i__ << 4) - 17] = 0.f;
		ini2_1.hfp[ie + (i__ << 4) - 17] = 0.f;
	    }
	}
    } else {
	ini2_1.ilim[0] = 0;
	ini2_1.codef = 0;
	ini2_1.coded[0] = 0;
	ini2_1.coded[1] = 0;
	ini2_1.codev[0] = 0;
	ini2_1.codev[1] = 0;
	ini2_1.codet = 0;
	ini2_1.npc = 0;
	for (i__ = 1; i__ <= 2; ++i__) {
	    ini2_1.vman[i__ - 1] = 0.f;
	    ini2_1.vapp[i__ - 1] = 0.f;
	    ini2_1.vth[i__ - 1] = 0.f;
	    ini2_1.vga[i__ - 1] = 0.f;
	    ini2_1.grad[i__ * 3 - 3] = 0.f;
	    ini2_1.grad[i__ * 3 - 2] = 0.f;
	    ini2_1.tqga[i__ - 1] = 0.f;
	    ini2_1.tqmc[i__ - 1] = 0.f;
	    ini2_1.lgr[i__ - 1] = 0.f;
	    ini2_1.ld[i__ - 1] = 0.f;
	    ini2_1.lfl[i__ - 1] = 0.f;
	}
	for (i__ = 1; i__ <= 10; ++i__) {
	    ini2_1.cw[i__ - 1] = 0.f;
	    ini2_1.cv[i__ - 1] = 0.f;
	    ini2_1.cd[i__ - 1] = 0.f;
	}
	for (i__ = 11; i__ <= 15; ++i__) {
	    ini2_1.cd[i__ - 1] = 0.f;
	}
    }
    i__1 = dagen3_1.ndf[in - 1];
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ini1_1.flaps == dagen3_1.df[i__ + (in << 1) - 3]) {
	    ini2_1.ifl = i__;
	    goto L10;
	}
    }
    if (*indi > 1 && *mil != 2) {
	ini2_1.ifl = 1;
	goto L10;
    }
    *ierr = 110;
    return 0;
L10:
    if (ini1_1.hp < dagen3_1.limalt[(in << 1) - 2] || ini1_1.hp > 
	    dagen3_1.limalt[(in << 1) - 1]) {
	*ierr = 210;
	return 0;
    }
    if (ini1_1.fact[0] < 0.f || ini1_1.fact[0] > 1.f || ini1_1.fact[1] < 1.f) 
	    {
	*ierr = 150;
	return 0;
    }
    if (*mil == 0 && ini1_1.fact[0] != .5f && ini1_1.fact[1] != 1.5f) {
	*ierr = 150;
	return 0;
    }
L20:
    oat_std__ = 15.f - ini1_1.hp * 1.98f / 1e3f;
    if (ini1_1.system[1] == 0) {
	oati = dagen3_1.limoat[(in << 1) - 2];
	oats = dagen3_1.limoat[(in << 1) - 1];
    } else {
	oati = dagen3_1.limoati[(in << 1) - 2];
	oats = dagen3_1.limoati[(in << 1) - 1];
    }
    if (oati > 500.f) {
	oati = oati - 1e3f + oat_std__;
    }
    if (oats > 500.f) {
	oats = oats - 1e3f + oat_std__;
    }
    if (ini1_1.temp < oati || ini1_1.temp > oats) {
	*ierr = 220;
	if (ini1_1.system[1] == 1) {
	    *ierr = 230;
	}
	return 0;
    }
    ini2_1.oat1 = ini1_1.temp;
    ini2_1.oat2 = ini1_1.temp;
    if (ini1_1.temp < dagen3_1.limoatg[in - 1]) {
	ini2_1.oat2 = dagen3_1.limoatg[in - 1];
    }
    if (*mil != 0) {
	ini2_1.wind_c__ = ini1_1.fact[0] * ini1_1.wind;
	if (ini1_1.wind < 0.f) {
	    ini2_1.wind_c__ = ini1_1.fact[1] * ini1_1.wind;
	}
    } else {
	ini2_1.wind_c__ = ini1_1.wind;
    }
    if (ini2_1.wind_c__ > dagen3_1.limwing[in - 1]) {
	ini2_1.wind_c__ = dagen3_1.limwing[in - 1];
    }
    if (ini2_1.wind_c__ < dagen3_1.limwin[(in << 1) - 2] || ini2_1.wind_c__ > 
	    dagen3_1.limwin[(in << 1) - 1]) {
	*ierr = 240;
	return 0;
    }
    if (*indi == 1) {
/*      LIMWC=LIMXWIN */
	npt = 0;
	i__1 = dagen3_1.nzcw;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    npt += dagen3_1.ncw[i__ - 1];
	}
	agape_(dagen3_1.yvcw, &vmax, &vmin, &imax, &imin, &npt);
	limwc = vmax;
    } else {
	limwc = dagen3_1.xvcrdf1[dagen3_1.ncrdf1 - 1];
    }
    if (ini1_1.xwind > limwc) {
	*ierr = 242;
	return 0;
    }
    if (*indi == 1) {
	if (vir[11] < dagen3_1.limv2vs[0] || vir[11] > dagen3_1.limv2vs[1]) {
	    *ierr = 161;
	    return 0;
	}
    }
    if (*indi == 0) {
	ini2_1.x[5] = ini2_1.wind_c__;
	ini2_1.x2[5] = ini2_1.wind_c__;
	return 0;
    }
    if (*mil == 0 && ini1_1.system[2] == 1) {
	*ierr = 112;
	return 0;
    }
    if (ini1_1.system[3] == 1 && dagen3_1.iopk == 0) {
	*ierr = 114;
	return 0;
    }
    if (ini1_1.system[3] == 1 && *mil == 2) {
	*ierr = 116;
	return 0;
    }
    if (ini1_1.slope < dagen3_1.limslp[(in << 1) - 2] || ini1_1.slope > 
	    dagen3_1.limslp[(in << 1) - 1]) {
	*ierr = 250;
	return 0;
    }
    if (ini1_1.dind < dagen3_1.limdi[(in << 1) - 2] || ini1_1.dind > 
	    dagen3_1.limdi[(in << 1) - 1]) {
	*ierr = 260;
	return 0;
    }
    if (ini1_1.dind1 < dagen3_1.limdi[(in << 1) - 2] || ini1_1.dind1 > 
	    dagen3_1.limdi[(in << 1) - 1]) {
	*ierr = 260;
	return 0;
    }
    wmax = dagen3_1.limw[(in << 1) - 1];
    ini1_1.wmin = dagen3_1.limw[(in << 1) - 2];
    if (ewmin > ini1_1.wmin) {
	ini1_1.wmin = ewmin;
    }
    if (ini1_1.gs < 0.f) {
	*ierr = 270;
	return 0;
    }
    gaml = 2.1f;
    if (*indi == 1) {
	gaml = 2.4f;
    }
    if (*mil == 0 && ini1_1.gs < gaml) {
	*ierr = 270;
	return 0;
    }
    if (*mil == 0 && ini1_1.gs > 10.f) {
	*ierr = 270;
	return 0;
    }
    if (ini1_1.rwy <= 0.f || ini1_1.swy < 0.f || ini1_1.cwy < 0.f) {
	*ierr = 130;
	return 0;
    }
    if (*indi == 1) {
	if (ini1_1.del_rwy__ < 0.f) {
	    *ierr = 152;
	    return 0;
	}
	if (ini1_1.del_obs__ < 0.f) {
	    *ierr = 154;
	    return 0;
	}
	vl1 = 0.f;
	if (*mil == 0) {
	    vl1 = ini1_1.cwy;
	}
	i__1 = ini1_1.nobs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (ini1_1.xobs[i__ - 1] * 1e3f < ini1_1.rwy + vl1 || ini1_1.hobs[
		    i__ - 1] < 0.f) {
		*ierr = 156;
		return 0;
	    }
	}
	if (ini1_1.nobp == 1) {
	    *ierr = 158;
	    return 0;
	}
	if (ini1_1.nobp > 1) {
	    i__1 = ini1_1.nobp;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (ini1_1.xobp[i__ - 1] * 1e3f < ini1_1.rwy + vl1 || 
			ini1_1.hobp[i__ - 1] < 0.f) {
		    *ierr = 158;
		    return 0;
		}
	    }
	    i__1 = ini1_1.nobp;
	    for (i__ = 2; i__ <= i__1; ++i__) {
		if (ini1_1.xobp[i__ - 1] < ini1_1.xobp[i__ - 2]) {
		    *ierr = 158;
		    return 0;
		}
	    }
	}
	if (nsenda[ini2_1.ifl] <= 0 && (ini1_1.nobs > 0 || ini1_1.nobp > 0)) {
	    *ierr = 160;
	    return 0;
	}
    }
    ini2_1.delcbr = 0.f;
    if (ini1_1.sup[0] == 1) {
	if (ini1_1.sup[1] < 1 || ini1_1.sup[1] > 7) {
	    *ierr = 120;
	    return 0;
	}
	ini2_1.rfi = dagen3_1.vrfip[ini1_1.sup[1] - 1];
	ini2_1.rcr = dagen3_1.vrcrp[ini1_1.sup[1] + in * 20 - 21];
    } else if (ini1_1.sup[0] == 2) {
	if (ini1_1.sup[2] < 1 || ini1_1.sup[2] > 8) {
	    *ierr = 120;
	    return 0;
	}
	if (ini1_1.sup[3] < 1 || ini1_1.sup[3] > 2) {
	    *ierr = 120;
	    return 0;
	}
/* Computing MAX */
	r__1 = dagen3_1.vrcr[ini1_1.sup[2] + in * 20 - 21], r__2 = 
		dagen3_1.vrcru[ini1_1.sup[3] + in * 10 - 11];
	ini2_1.rcr = dmax(r__1,r__2);
	if (*indi == 1) {
	    if (ini1_1.cbr <= 0.f || ini1_1.cbr > dagen3_1.xcbr[dagen3_1.ncbr[
		    in - 1] + in * 10 - 11]) {
		ini2_1.rfi = dagen3_1.vrfi[ini1_1.sup[2] - 1];
	    } else if (ini1_1.cbr < dagen3_1.xcbr[in * 10 - 10]) {
		*ierr = 120;
		return 0;
	    } else {
		manual2r_(&c__1, &ini1_1.cbr, &dagen3_1.xcbr[in * 10 - 10], 
			dagen3_1.ymcbr, &dagen3_1.grcbr[in - 1], &
			dagen3_1.ncbr[in - 1], &ini2_1.rfi, &ie);
	    }
	} else {
	    ini2_1.rfi = 0.f;
	    if (ini1_1.cbr > 0.f && ini1_1.cbr < dagen3_1.xcbr[in * 10 - 10]) 
		    {
		*ierr = 120;
		return 0;
	    } else if (ini1_1.cbr >= dagen3_1.xcbr[in * 10 - 10] && 
		    ini1_1.cbr <= dagen3_1.xcbr[dagen3_1.ncbr[in - 1] + in * 
		    10 - 11]) {
		manual2r_(&c__1, &ini1_1.cbr, &dagen3_1.xcbr[in * 10 - 10], 
			dagen3_1.ydcbr, &dagen3_1.grcbr[in - 1], &
			dagen3_1.ncbr[in - 1], &ini2_1.delcbr, &ie);
	    }
	}
    } else {
	*ierr = 120;
	return 0;
    }
    if (ini2_1.rfi == 100.f || ini2_1.rcr == 100.f) {
	*ierr = 120;
	return 0;
    }
    ini2_1.x[0] = ini1_1.dind1;
    ini2_1.x[1] = (real) ini1_1.flaps;
    ini2_1.x[2] = (real) ini1_1.system[1];
    ini2_1.x[3] = (real) ini1_1.system[0];
    ini2_1.x[4] = ini1_1.slope;
    ini2_1.x[5] = ini2_1.wind_c__;
    ini2_1.x[6] = ini2_1.rcr;
    ini2_1.x[7] = ini2_1.rfi;
    ini2_1.x[8] = vir[11];
    ini2_1.x[9] = (real) ini1_1.system[2];
    ini2_1.x[10] = 0.f;
    ini2_1.x[11] = 0.f;
    ini2_1.x[12] = (real) (ini1_1.sup[1] - 1);
    ini2_1.x[13] = 0.f;
    ini2_1.x[14] = 0.f;
    ini2_1.x2[0] = ini1_1.dind;
    for (i__ = 2; i__ <= 15; ++i__) {
	ini2_1.x2[i__ - 1] = ini2_1.x[i__ - 1];
    }
    ini2_1.ind = 1;
    ini2_1.nfp[0] = -1;
    ini2_1.nfp[1] = -1;
    ini2_1.iobs[0] = 0;
    ini2_1.iobs[1] = 0;
    return 0;
} /* init_ */

/* Subroutine */ int escrit_(integer *voi, real *vor, integer *ierr, integer *
	segm, integer *verc, integer *verd)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer i_nint(real *);

    /* Local variables */
    static integer i__, j, ie;

    /* Parameter adjustments */
    --vor;
    --voi;

    /* Function Body */
    j = 2;
    if (ini2_1.mw == ini1_1.aw) {
	j = 1;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	voi[i__] = ini2_1.ilim[i__ - 1];
	voi[i__ + 5] = ini2_1.ilim[i__ + (j << 2) - 5];
	if (*ierr == 10) {
	    voi[i__ + 5] = ini2_1.ilim[i__ - 1];
	}
    }
    if (*ierr == 10) {
	return 0;
    }
    r__1 = ini2_1.altacc[0] / 10.f;
    voi[11] = i_nint(&r__1) * 10;
    r__1 = ini2_1.altacc[j - 1] / 10.f;
    voi[12] = i_nint(&r__1) * 10;
    voi[13] = *segm;
    voi[14] = *verc;
    voi[15] = *verd;
    voi[17] = ini2_1.nfp[0];
    voi[18] = ini2_1.nfp[j - 1];
    voi[19] = ini2_1.senda[0];
    voi[20] = ini2_1.senda[j - 1];
    vor[1] = ini2_1.mw;
    vor[101] = ini1_1.aw;
    for (i__ = 1; i__ <= 2; ++i__) {
	j = i__;
	if (i__ == 2 && ini2_1.mw == ini1_1.aw) {
	    j = 1;
	}
	ie = (i__ - 1) * 100 + 2;
	vor[ie] = ini2_1.vmcg[j - 1];
	vor[ie + 1] = ini2_1.vr[j - 1];
	vor[ie + 2] = ini2_1.v2[j - 1];
	vor[ie + 3] = ini2_1.vfret[(j << 1) - 2];
	vor[ie + 4] = ini2_1.vfret[(j << 1) - 1];
	vor[ie + 6] = ini2_1.fret[j - 1];
	vor[ie + 8] = ini2_1.vfto[j - 1];
	vor[ie + 10] = ini2_1.grad[j * 3 - 3];
	vor[ie + 11] = ini2_1.rc[j * 3 - 3];
	vor[ie + 14] = ini2_1.grad[j * 3 - 2];
	vor[ie + 15] = ini2_1.rc[j * 3 - 2];
	vor[ie + 18] = ini2_1.grad[j * 3 - 1];
	vor[ie + 19] = ini2_1.rc[j * 3 - 1];
	vor[ie + 22] = ini2_1.tqto[j - 1];
	vor[ie + 23] = ini2_1.tqmc[j - 1];
	vor[ie + 24] = ini2_1.itt[j - 1];
	vor[ie + 26] = ini2_1.v1[j * 3 - 3];
	vor[ie + 27] = ini2_1.asd[j * 3 - 3];
	vor[ie + 28] = ini2_1.tor[j * 3 - 3];
	vor[ie + 29] = ini2_1.tod[j * 3 - 3];
	vor[ie + 31] = ini2_1.v1[j * 3 - 2];
	vor[ie + 32] = ini2_1.asd[j * 3 - 2];
	vor[ie + 33] = ini2_1.tor[j * 3 - 2];
	vor[ie + 34] = ini2_1.tod[j * 3 - 2];
	vor[ie + 36] = ini2_1.v1[j * 3 - 1];
	vor[ie + 37] = ini2_1.asd[j * 3 - 1];
	vor[ie + 38] = ini2_1.tor[j * 3 - 1];
	vor[ie + 39] = ini2_1.tod[j * 3 - 1];
	vor[ie + 43] = ini2_1.rfi;
	vor[ie + 44] = ini2_1.rcr;
	i__1 = ini2_1.nfp[j - 1];
	for (ini2_1.ind = 1; ini2_1.ind <= i__1; ++ini2_1.ind) {
	    vor[ie + 47 + (ini2_1.ind << 1)] = ini2_1.xfp[ini2_1.ind + (j << 
		    4) - 17];
	    vor[ie + 48 + (ini2_1.ind << 1)] = ini2_1.hfp[ini2_1.ind + (j << 
		    4) - 17];
	}
    }
    return 0;
} /* escrit_ */

/* Subroutine */ int escril_(integer *voi, real *vor, integer *ierr, integer *
	infoice, integer *segm, integer *verc, integer *verd)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, ie;

    /* Parameter adjustments */
    --vor;
    --voi;

    /* Function Body */
    j = 2;
    if (ini2_1.mw == ini1_1.aw) {
	j = 1;
    }
    voi[1] = ini2_1.ilim[0];
    if (*ierr == 10) {
	return 0;
    }
    voi[2] = ini2_1.codef;
    voi[3] = ini2_1.codev[0];
    voi[4] = ini2_1.coded[0];
    voi[5] = ini2_1.codev[j - 1];
    voi[6] = ini2_1.coded[j - 1];
    voi[8] = *infoice;
    voi[9] = ini2_1.codet;
    voi[10] = ini2_1.fap;
    voi[11] = ini2_1.fld;
    voi[12] = ini2_1.fga;
    voi[13] = *segm;
    voi[14] = *verc;
    voi[15] = *verd;
    voi[20] = ini2_1.npc;
    vor[1] = ini2_1.mw;
    vor[51] = ini1_1.aw;
    for (i__ = 1; i__ <= 2; ++i__) {
	j = i__;
	if (i__ == 2 && ini1_1.aw == ini2_1.mw) {
	    j = 1;
	}
	ie = (i__ - 1) * 50 + 2;
	vor[ie + 1] = ini2_1.vman[j - 1];
	vor[ie + 2] = ini2_1.vapp[j - 1];
	vor[ie + 3] = ini2_1.vth[j - 1];
	vor[ie + 5] = ini2_1.vga[j - 1];
	vor[ie + 10] = ini2_1.grad[j * 3 - 3];
	vor[ie + 11] = ini2_1.rc[j * 3 - 3];
	vor[ie + 12] = ini2_1.grad[j * 3 - 2];
	vor[ie + 13] = ini2_1.rc[j * 3 - 2];
	vor[ie + 18] = ini2_1.tqga[j - 1];
	vor[ie + 19] = ini2_1.tqmc[j - 1];
	vor[ie + 28] = ini2_1.lgr[j - 1];
	vor[ie + 29] = ini2_1.ld[j - 1];
	vor[ie + 30] = ini2_1.lfl[j - 1];
	vor[ie + 44] = ini2_1.rcr;
    }
    i__1 = ini2_1.npc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vor[(i__ << 1) + 99] = ini2_1.cw[i__ - 1];
	vor[(i__ << 1) + 100] = ini2_1.cv[i__ - 1];
    }
    for (i__ = 1; i__ <= 15; ++i__) {
	vor[i__ + 130] = ini2_1.cd[i__ - 1];
    }
    return 0;
} /* escril_ */

/* Subroutine */ int obscrit_(real *ztod, integer *np, real *xp, real *yp, 
	integer *npa, real *xpa, real *ypa, real *dif, integer *senf, integer 
	*obsf, integer *nf, real *xf, real *hf, integer *ier)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    extern /* Subroutine */ int manual2r_(integer *, real *, real *, real *, 
	    integer *, integer *, real *, integer *);
    static integer i__, ie;
    static real vl1, vl2, dif1;
    static integer obs1;
    static real dif1a;
    static integer obs1a;

    /* Parameter adjustments */
    --hf;
    --xf;
    --ypa;
    --xpa;
    --yp;
    --xp;

    /* Function Body */
    if (*np <= 0) {
	*ier = 1;
	return 0;
    }
    *ier = 0;
    *senf = 1;
    dif1 = 99999.f;
    obs1 = 1;
    if (ini1_1.nobs == 0) {
	obs1 = 0;
    }
    i__1 = ini1_1.nobs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vl2 = ini1_1.xobs[i__ - 1] - *ztod / 1e3f;
	manual2r_(&c__1, &vl2, &xp[1], &yp[1], &c_n1, np, &vl1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (ie == 0 || vl2 < 0.f) {
	    vl1 = vl1 - ini1_1.hobs[i__ - 1] - ini1_1.del_obs__;
	    if (vl1 < dif1) {
		dif1 = vl1;
		obs1 = i__;
	    }
	}
    }
    *dif = dif1;
    *obsf = obs1;
    if (*npa > 0) {
	dif1a = 99999.f;
	i__1 = ini1_1.nobs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    vl2 = ini1_1.xobs[i__ - 1] - *ztod / 1e3f;
	    manual2r_(&c__1, &vl2, &xpa[1], &ypa[1], &c_n1, npa, &vl1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (ie == 0 || vl2 < 0.f) {
		vl1 = vl1 - ini1_1.hobs[i__ - 1] - ini1_1.del_obs__;
		if (vl1 < dif1a) {
		    dif1a = vl1;
		    obs1a = i__;
		}
	    }
	}
	if (dif1a > dif1) {
	    *senf = 2;
	    *dif = dif1a;
	    *obsf = obs1a;
	}
    }
    if (ini1_1.nobp > 0) {
	dif1 = 99999.f;
	i__1 = *np;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    r__1 = xp[i__] + *ztod / 1e3f;
	    manual2r_(&c__1, &r__1, ini1_1.xobp, ini1_1.hobp, &c_n1, &
		    ini1_1.nobp, &vl1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (ie == 0) {
		vl1 = yp[i__] - vl1 - ini1_1.del_obs__;
		if (vl1 < dif1) {
		    dif1 = vl1;
		}
	    }
	}
	i__1 = ini1_1.nobp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    vl2 = ini1_1.xobp[i__ - 1] - *ztod / 1e3f;
	    manual2r_(&c__1, &vl2, &xp[1], &yp[1], &c_n1, np, &vl1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    if (ie == 0 || vl2 < 0.f) {
		vl1 = vl1 - ini1_1.hobp[i__ - 1] - ini1_1.del_obs__;
		if (vl1 < dif1) {
		    dif1 = vl1;
		}
	    }
	}
	if (*npa <= 0) {
	    if (dif1 < *dif) {
		*obsf = 0;
		*dif = dif1;
	    }
	} else {
	    dif1a = 99999.f;
	    i__1 = *npa;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		r__1 = xpa[i__] + *ztod / 1e3f;
		manual2r_(&c__1, &r__1, ini1_1.xobp, ini1_1.hobp, &c_n1, &
			ini1_1.nobp, &vl1, &ie);
		if (ie == 2) {
		    goto L10000;
		}
		if (ie == 0) {
		    vl1 = ypa[i__] - vl1 - ini1_1.del_obs__;
		    if (vl1 < dif1a) {
			dif1a = vl1;
		    }
		}
	    }
	    i__1 = ini1_1.nobp;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		vl2 = ini1_1.xobp[i__ - 1] - *ztod / 1e3f;
		manual2r_(&c__1, &vl2, &xpa[1], &ypa[1], &c_n1, npa, &vl1, &
			ie);
		if (ie == 2) {
		    goto L10000;
		}
		if (ie == 0 || vl2 < 0.f) {
		    vl1 = vl1 - ini1_1.hobp[i__ - 1] - ini1_1.del_obs__;
		    if (vl1 < dif1a) {
			dif1a = vl1;
		    }
		}
	    }
	    if (dif1a > dif1) {
		if (dif1a < *dif) {
		    *senf = 2;
		    *obsf = 0;
		    *dif = dif1a;
		}
	    } else {
		if (dif1 < *dif) {
		    *senf = 1;
		    *obsf = 0;
		    *dif = dif1;
		}
	    }
	}
    }
    *obsf += 10;
    if (*senf == 1) {
	*nf = *np;
	i__1 = *np;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xf[i__] = xp[i__];
	    hf[i__] = yp[i__];
	}
    } else {
	*nf = *npa;
	i__1 = *npa;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xf[i__] = xpa[i__];
	    hf[i__] = ypa[i__];
	}
    }
    return 0;
L10000:
    *ier = 2;
    return 0;
} /* obscrit_ */

