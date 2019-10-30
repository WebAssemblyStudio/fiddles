/* SLECU.F -- translated by f2c (version 20100827).
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

static integer c__3 = 3;
static integer c__1 = 1;
static integer c__15 = 15;
static integer c__500 = 500;
static integer c__20 = 20;
static integer c__35 = 35;
static integer c__10 = 10;
static integer c__4 = 4;
static integer c__2 = 2;
static integer c__100 = 100;
static integer c__750 = 750;
static integer c__30 = 30;
static integer c__300 = 300;
static integer c__75 = 75;
static integer c__200 = 200;
static integer c__25 = 25;
static integer c__50 = 50;
static integer c__150 = 150;
static integer c__400 = 400;
static integer c__16 = 16;
static integer c__1500 = 1500;
static integer c__60 = 60;
static integer c__550 = 550;
static integer c__5 = 5;
static integer c__180 = 180;
static integer c__8 = 8;
static integer c__6 = 6;
static integer c__600 = 600;
static integer c__9 = 9;
static integer c__12 = 12;

/* Subroutine */ int lectg_(char *vic, integer *ier, ftnlen vic_len)
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3], i__2, i__3;
    char ch__1[210];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, ie, if__, npt, jerr;
    extern /* Subroutine */ int datgraf2_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, real *, real *
	    , integer *);

    /* Fortran I/O blocks */
    static cilist io___3 = { 1, 15, 0, 0, 0 };
    static cilist io___4 = { 1, 15, 0, 0, 0 };
    static cilist io___7 = { 1, 15, 0, 0, 0 };
    static cilist io___8 = { 1, 15, 0, 0, 0 };


    *ier = 0;
    i__ = i_indx(vic, "  ", (ftnlen)200, (ftnlen)2) - 1;
    o__1.oerr = 1;
    o__1.ounit = 15;
    o__1.ofnmlen = i__ + 10;
/* Writing concatenation */
    i__1[0] = i__, a__1[0] = vic;
    i__1[1] = 6, a__1[1] = afm_1.afm;
    i__1[2] = 4, a__1[2] = ".UNF";
    s_cat(ch__1, a__1, i__1, &c__3, (ftnlen)210);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    jerr = f_open(&o__1);
    i__2 = s_rsue(&io___3);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, afm_1.afm_dat__, (ftnlen)6);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___4);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.verd[2], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grtq, &dagen1_1.nztq, 
	    dagen1_1.zhtq, dagen1_1.ntq, dagen1_1.xttq, dagen1_1.yqtq, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grtqi, &dagen1_1.nztqi,
	     dagen1_1.zhtqi, dagen1_1.ntqi, dagen1_1.xttqi, dagen1_1.yqtqi, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__35, &npt, &dagen1_1.grtqm, &dagen1_1.nztqm,
	     dagen1_1.zhtqm, dagen1_1.ntqm, dagen1_1.xttqm, dagen1_1.yqtqm, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__35, &npt, &dagen1_1.grtqmi, &
	    dagen1_1.nztqmi, dagen1_1.zhtqmi, dagen1_1.ntqmi, dagen1_1.xttqmi,
	     dagen1_1.yqtqmi, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grit, &dagen1_1.nzit, 
	    dagen1_1.zhit, dagen1_1.nit, dagen1_1.xtit, dagen1_1.ytit, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.griti, &dagen1_1.nziti,
	     dagen1_1.zhiti, dagen1_1.niti, dagen1_1.xtiti, dagen1_1.ytiti, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grtqg, &dagen1_1.nztqg,
	     dagen1_1.zhtqg, dagen1_1.ntqg, dagen1_1.xttqg, dagen1_1.yqtqg, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grtqgi, &
	    dagen1_1.nztqgi, dagen1_1.zhtqgi, dagen1_1.ntqgi, dagen1_1.xttqgi,
	     dagen1_1.yqtqgi, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grfft, &dagen1_1.nzfft,
	     dagen1_1.zhfft, dagen1_1.nfft, dagen1_1.xtfft, dagen1_1.yfft, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__20, &npt, &dagen1_1.grffti, &
	    dagen1_1.nzffti, dagen1_1.zffti, dagen1_1.nffti, dagen1_1.xffti, 
	    dagen1_1.yffti, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___7);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen2_1.nfcal, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen2_1.nfcal > 5) {
	goto L1500;
    }
    i__2 = s_rsue(&io___8);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen2_1.nfcal;
    for (if__ = 1; if__ <= i__3; ++if__) {
	i__2 = do_uio(&c__1, (char *)&dagen2_1.fcal[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = dagen2_1.nfcal;
    for (if__ = 1; if__ <= i__2; ++if__) {
	datgraf2_(&c__15, &c__500, &c__10, &npt, &dagen2_1.grcal[if__ - 1], &
		dagen2_1.nzcal[if__ - 1], &dagen2_1.zwcal[if__ * 10 - 10], &
		dagen2_1.ncal[if__ * 10 - 10], &dagen2_1.xscal[if__ * 500 - 
		500], &dagen2_1.yscal[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L1500:
    *ier = 402;
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* lectg_ */

/* Subroutine */ int lecto_(char *vic, integer *ier, ftnlen vic_len)
{
    /* System generated locals */
    address a__1[4];
    integer i__1[4], i__2, i__3;
    char ch__1[212];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, jerr, j;
    extern /* Subroutine */ int datgraf2_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *, real *, real *
	    , integer *), datgraf1_(integer *, integer *, integer *, integer *
	    , real *, real *, integer *), datgraf3_(integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer ie, if__, npt;

    /* Fortran I/O blocks */
    static cilist io___12 = { 1, 15, 0, 0, 0 };
    static cilist io___13 = { 1, 15, 0, 0, 0 };
    static cilist io___14 = { 1, 15, 0, 0, 0 };
    static cilist io___15 = { 1, 15, 0, 0, 0 };
    static cilist io___16 = { 1, 15, 0, 0, 0 };
    static cilist io___17 = { 1, 15, 0, 0, 0 };
    static cilist io___18 = { 1, 15, 0, 0, 0 };
    static cilist io___19 = { 1, 15, 0, 0, 0 };
    static cilist io___20 = { 1, 15, 0, 0, 0 };
    static cilist io___21 = { 1, 15, 0, 0, 0 };
    static cilist io___22 = { 1, 15, 0, 0, 0 };
    static cilist io___25 = { 1, 15, 0, 0, 0 };
    static cilist io___26 = { 1, 15, 0, 0, 0 };
    static cilist io___27 = { 1, 15, 0, 0, 0 };
    static cilist io___28 = { 1, 15, 0, 0, 0 };
    static cilist io___29 = { 1, 15, 0, 0, 0 };
    static cilist io___30 = { 1, 15, 0, 0, 0 };
    static cilist io___31 = { 1, 15, 0, 0, 0 };
    static cilist io___32 = { 1, 15, 0, 0, 0 };
    static cilist io___33 = { 1, 15, 0, 0, 0 };
    static cilist io___34 = { 1, 15, 0, 0, 0 };
    static cilist io___35 = { 1, 15, 0, 0, 0 };
    static cilist io___36 = { 1, 15, 0, 0, 0 };
    static cilist io___37 = { 1, 15, 0, 0, 0 };
    static cilist io___39 = { 1, 15, 0, 0, 0 };
    static cilist io___41 = { 1, 15, 0, 0, 0 };
    static cilist io___42 = { 1, 15, 0, 0, 0 };
    static cilist io___43 = { 1, 15, 0, 0, 0 };
    static cilist io___44 = { 1, 15, 0, 0, 0 };
    static cilist io___45 = { 1, 15, 0, 0, 0 };
    static cilist io___46 = { 1, 15, 0, 0, 0 };
    static cilist io___47 = { 1, 15, 0, 0, 0 };
    static cilist io___48 = { 1, 15, 0, 0, 0 };
    static cilist io___49 = { 1, 15, 0, 0, 0 };
    static cilist io___50 = { 1, 15, 0, 0, 0 };
    static cilist io___51 = { 1, 15, 0, 0, 0 };
    static cilist io___52 = { 1, 15, 0, 0, 0 };
    static cilist io___53 = { 1, 15, 0, 0, 0 };
    static cilist io___54 = { 1, 15, 0, 0, 0 };
    static cilist io___55 = { 1, 15, 0, 0, 0 };
    static cilist io___56 = { 1, 15, 0, 0, 0 };
    static cilist io___57 = { 1, 15, 0, 0, 0 };
    static cilist io___58 = { 1, 15, 0, 0, 0 };
    static cilist io___59 = { 1, 15, 0, 0, 0 };
    static cilist io___60 = { 1, 15, 0, 0, 0 };
    static cilist io___61 = { 1, 15, 0, 0, 0 };
    static cilist io___62 = { 1, 15, 0, 0, 0 };
    static cilist io___63 = { 1, 15, 0, 0, 0 };
    static cilist io___64 = { 1, 15, 0, 0, 0 };
    static cilist io___65 = { 1, 15, 0, 0, 0 };
    static cilist io___66 = { 1, 15, 0, 0, 0 };
    static cilist io___67 = { 1, 15, 0, 0, 0 };
    static cilist io___68 = { 1, 15, 0, 0, 0 };
    static cilist io___69 = { 1, 15, 0, 0, 0 };


    s_copy(afm_1.afm_far__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_mil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_tac__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_taf__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lfar__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lmil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_ltac__, "      ", (ftnlen)6, (ftnlen)6);
    *ier = 0;
    i__ = i_indx(vic, "  ", (ftnlen)200, (ftnlen)2) - 1;
    if (resto_1.mil == 0) {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "T";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "F.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_far__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    } else if (resto_1.mil == 1) {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "T";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "M.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_mil__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    } else if (resto_1.mil == 2) {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "T";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "T.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_tac__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    } else {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "T";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "S.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_taf__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    }
    i__2 = s_rsue(&io___12);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.verd[0], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___13);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___14);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___15);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___16);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwin[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwin[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
/*     READ (15,ERR=1500)LIMXWIN */
    i__2 = s_rsue(&io___17);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limslp[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limslp[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___18);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___19);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___20);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limv2vs[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limv2vs[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___21);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.ndf[0], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen3_1.ndf[0] > 2 || dagen3_1.ndf[0] < 1) {
	goto L1500;
    }
    i__2 = s_rsue(&io___22);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.df[i__ - 1], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__20, &c__2, &npt, &dagen3_1.grcw, &dagen3_1.nzcw, 
	    dagen3_1.zfcw, dagen3_1.ncw, dagen3_1.xscw, dagen3_1.yvcw, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___25);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoatg[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___26);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwing[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___27);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limene[0], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___28);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrfip[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___29);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcrp[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___30);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrfi[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___31);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcr[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___32);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcru[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___33);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.grcbr[0], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___34);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.ncbr[0], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen3_1.ncbr[0] > 10) {
	goto L1500;
    }
    i__2 = s_rsue(&io___35);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ncbr[0];
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.xcbr[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___36);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ncbr[0];
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.ymcbr[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___37);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.segm[i__ - 1], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = dagen3_1.ndf[0];
    for (if__ = 1; if__ <= i__2; ++if__) {
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato1_1.grw[if__ - 1], &
		dato1_1.nzw[if__ - 1], &dato1_1.zhw[if__ * 20 - 20], &
		dato1_1.nw[if__ * 20 - 20], &dato1_1.xww[if__ * 500 - 500], &
		dato1_1.ytw[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___39);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pwc[i__ + if__ * 15 - 16], (
		    ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grwc[j + (if__ 
		    << 2) - 5], &dato1_1.nzwc[j + (if__ << 2) - 5], &
		    dato1_1.zwc[(j + (if__ << 2)) * 15 - 75], &dato1_1.nwc[(j 
		    + (if__ << 2)) * 15 - 75], &dato1_1.xwc[(j + (if__ << 2)) 
		    * 100 - 500], &dato1_1.ywc[(j + (if__ << 2)) * 100 - 500],
		     &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dato1_1.grwi[if__ - 1], &dato1_1.nwi[if__ 
		- 1], &dato1_1.xtwi[if__ * 10 - 10], &dato1_1.ytwi[if__ * 10 
		- 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dato1_1.grwj[if__ - 1], &dato1_1.nwj[if__ 
		- 1], &dato1_1.xtwj[if__ * 10 - 10], &dato1_1.ywwj[if__ * 10 
		- 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato1_1.grfc1[if__ - 1], &
		dato1_1.nzfc1[if__ - 1], &dato1_1.zhfc1[if__ * 20 - 20], &
		dato1_1.nfc1[if__ * 20 - 20], &dato1_1.xtfc1[if__ * 500 - 500]
		, &dato1_1.ygfc1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__15, &npt, &dato1_1.grfc2[if__ - 1], &
		dato1_1.nzfc2[if__ - 1], &dato1_1.zgfc2[if__ * 15 - 15], &
		dato1_1.nfc2[if__ * 15 - 15], &dato1_1.xwfc2[if__ * 500 - 500]
		, &dato1_1.ygfc2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___41);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pfcc[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grfcc[j + (if__ 
		    << 2) - 5], &dato1_1.nzfcc[j + (if__ << 2) - 5], &
		    dato1_1.zfcc[(j + (if__ << 2)) * 15 - 75], &dato1_1.nfcc[(
		    j + (if__ << 2)) * 15 - 75], &dato1_1.xfcc[(j + (if__ << 
		    2)) * 100 - 500], &dato1_1.yfcc[(j + (if__ << 2)) * 100 - 
		    500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dato1_1.grfi[if__ - 1], &dato1_1.nfi[if__ 
		- 1], &dato1_1.xtfi[if__ * 10 - 10], &dato1_1.ytfi[if__ * 10 
		- 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___42);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato1_1.indg2, (ftnlen)sizeof(integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato1_1.grg21[if__ - 1], &
		dato1_1.nzg21[if__ - 1], &dato1_1.zhg21[if__ * 20 - 20], &
		dato1_1.ng21[if__ * 20 - 20], &dato1_1.xtg21[if__ * 500 - 500]
		, &dato1_1.yg21[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__750, &c__30, &npt, &dato1_1.grg22[if__ - 1], &
		dato1_1.nzg22[if__ - 1], &dato1_1.zg22[if__ * 30 - 30], &
		dato1_1.ng22[if__ * 30 - 30], &dato1_1.xwg22[if__ * 750 - 750]
		, &dato1_1.yg22[if__ * 750 - 750], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___43);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pg2c[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grg2c[j + (if__ 
		    << 2) - 5], &dato1_1.nzg2c[j + (if__ << 2) - 5], &
		    dato1_1.zg2c[(j + (if__ << 2)) * 15 - 75], &dato1_1.ng2c[(
		    j + (if__ << 2)) * 15 - 75], &dato1_1.xg2c[(j + (if__ << 
		    2)) * 100 - 500], &dato1_1.yg2c[(j + (if__ << 2)) * 100 - 
		    500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dato1_1.grg2i[if__ - 1], &dato1_1.ng2i[
		if__ - 1], &dato1_1.xtg2i[if__ * 10 - 10], &dato1_1.ytg2i[
		if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__15, &dato1_1.grg[if__ - 1], &dato1_1.ng[if__ - 
		1], &dato1_1.xgg[if__ * 15 - 15], &dato1_1.ycg[if__ * 15 - 15]
		, &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___44);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pgc[i__ + if__ * 15 - 16], (
		    ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grgc[j + (if__ 
		    << 2) - 5], &dato1_1.nzgc[j + (if__ << 2) - 5], &
		    dato1_1.zgc[(j + (if__ << 2)) * 15 - 75], &dato1_1.ngc[(j 
		    + (if__ << 2)) * 15 - 75], &dato1_1.xgc[(j + (if__ << 2)) 
		    * 100 - 500], &dato1_1.ygc[(j + (if__ << 2)) * 15 - 75], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	i__3 = s_rsue(&io___45);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato1_1.dgrs1[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___46);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pdgrs1c[i__ + if__ * 15 - 
		    16], (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grdgrs1c[j + (
		    if__ << 2) - 5], &dato1_1.nzdgrs1c[j + (if__ << 2) - 5], &
		    dato1_1.zdgrs1c[(j + (if__ << 2)) * 15 - 75], &
		    dato1_1.ndgrs1c[(j + (if__ << 2)) * 15 - 75], &
		    dato1_1.xdgrs1c[(j + (if__ << 2)) * 100 - 500], &
		    dato1_1.ydgrs1c[(j + (if__ << 2)) * 100 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	i__3 = s_rsue(&io___47);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato1_1.drcs1[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___48);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pdrcs1c[i__ + if__ * 15 - 
		    16], (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grdrcs1c[j + (
		    if__ << 2) - 5], &dato1_1.nzdrcs1c[j + (if__ << 2) - 5], &
		    dato1_1.zdrcs1c[(j + (if__ << 2)) * 15 - 75], &
		    dato1_1.ndrcs1c[(j + (if__ << 2)) * 15 - 75], &
		    dato1_1.xdrcs1c[(j + (if__ << 2)) * 100 - 500], &
		    dato1_1.ydrcs1c[(j + (if__ << 2)) * 100 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	i__3 = s_rsue(&io___49);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato1_1.igam, (ftnlen)sizeof(integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato1_1.grw21[if__ - 1], &
		dato1_1.nzw21[if__ - 1], &dato1_1.zhw21[if__ * 20 - 20], &
		dato1_1.nw21[if__ * 20 - 20], &dato1_1.xww21[if__ * 500 - 500]
		, &dato1_1.ytw21[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__300, &c__30, &npt, &dato1_1.grw22[if__ - 1], &
		dato1_1.nzw22[if__ - 1], &dato1_1.zgw22[if__ * 30 - 30], &
		dato1_1.nw22[if__ * 30 - 30], &dato1_1.xww22[if__ * 300 - 300]
		, &dato1_1.yww22[if__ * 300 - 300], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___50);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato1_1.pw2c[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato1_1.grw2c[j + (if__ 
		    << 2) - 5], &dato1_1.nzw2c[j + (if__ << 2) - 5], &
		    dato1_1.zw2c[(j + (if__ << 2)) * 15 - 75], &dato1_1.nw2c[(
		    j + (if__ << 2)) * 15 - 75], &dato1_1.xw2c[(j + (if__ << 
		    2)) * 100 - 500], &dato1_1.yw2c[(j + (if__ << 2)) * 100 - 
		    500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dato1_1.grw2i[if__ - 1], &dato1_1.nw2i[
		if__ - 1], &dato1_1.xtw2i[if__ * 10 - 10], &dato1_1.ytw2i[
		if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    if (resto_1.mil == 0) {
	i__2 = dagen3_1.ndf[0];
	for (if__ = 1; if__ <= i__2; ++if__) {
	    i__3 = s_rsue(&io___51);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.ptod[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 6; ++j) {
		datgraf2_(&c__15, &c__75, &c__15, &npt, &dato2_1.grtod[j + 
			if__ * 10 - 11], &dato2_1.nztod[j + if__ * 10 - 11], &
			dato2_1.ztod[(j + if__ * 10) * 15 - 165], &
			dato2_1.ntod[(j + if__ * 10) * 15 - 165], &
			dato2_1.xtod[(j + if__ * 10) * 75 - 825], &
			dato2_1.ytod[(j + if__ * 10) * 75 - 825], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    i__3 = s_rsue(&io___52);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.pasd[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 6; ++j) {
		datgraf2_(&c__15, &c__75, &c__15, &npt, &dato2_1.grasd[j + 
			if__ * 10 - 11], &dato2_1.nzasd[j + if__ * 10 - 11], &
			dato2_1.zasd[(j + if__ * 10) * 15 - 165], &
			dato2_1.nasd[(j + if__ * 10) * 15 - 165], &
			dato2_1.xasd[(j + if__ * 10) * 75 - 825], &
			dato2_1.yasd[(j + if__ * 10) * 75 - 825], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    i__3 = s_rsue(&io___53);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.ptor[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 6; ++j) {
		datgraf2_(&c__15, &c__75, &c__15, &npt, &dato2_1.grtor[j + 
			if__ * 10 - 11], &dato2_1.nztor[j + if__ * 10 - 11], &
			dato2_1.ztor[(j + if__ * 10) * 15 - 165], &
			dato2_1.ntor[(j + if__ * 10) * 15 - 165], &
			dato2_1.xtor[(j + if__ * 10) * 75 - 825], &
			dato2_1.ytor[(j + if__ * 10) * 75 - 825], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    i__3 = s_rsue(&io___54);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.masd[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___55);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.mtor[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___56);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato2_1.mtod[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato2_1.grwd1[if__ - 1],
		     &dato2_1.nzwd1[if__ - 1], &dato2_1.zhwd1[if__ * 20 - 20],
		     &dato2_1.nwd1[if__ * 20 - 20], &dato2_1.xtwd1[if__ * 500 
		    - 500], &dato2_1.ywwd1[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__200, &c__25, &npt, &dato2_1.grwd2[if__ - 1],
		     &dato2_1.nzwd2[if__ - 1], &dato2_1.zdwd2[if__ * 25 - 25],
		     &dato2_1.nwd2[if__ * 25 - 25], &dato2_1.xwwd2[if__ * 200 
		    - 200], &dato2_1.ywwd2[if__ * 200 - 200], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf1_(&c__15, &c__15, &dato2_1.grwdi[if__ - 1], &dato2_1.nwdi[
		    if__ - 1], &dato2_1.xtwdi[if__ * 15 - 15], &dato2_1.ytwdi[
		    if__ * 15 - 15], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__50, &c__20, &npt, &dato2_1.grv1r[if__ - 1], 
		    &dato2_1.nzv1r[if__ - 1], &dato2_1.zsv1r[if__ * 20 - 20], 
		    &dato2_1.nv1r[if__ * 20 - 20], &dato2_1.xsv1r[if__ * 50 - 
		    50], &dato2_1.ysv1r[if__ * 50 - 50], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
    } else {
	i__2 = dagen3_1.ndf[0];
	for (if__ = 1; if__ <= i__2; ++if__) {
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato3_1.grgr1[if__ - 1],
		     &dato3_1.nzgr1[if__ - 1], &dato3_1.zhgr1[if__ * 20 - 20],
		     &dato3_1.ngr1[if__ * 20 - 20], &dato3_1.xdgr1[if__ * 500 
		    - 500], &dato3_1.ytgr1[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato3_1.grgr2[if__ - 1],
		     &dato3_1.nzgr2[if__ - 1], &dato3_1.zwgr2[if__ * 20 - 20],
		     &dato3_1.ngr2[if__ * 20 - 20], &dato3_1.xdgr2[if__ * 500 
		    - 500], &dato3_1.ydgr2[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___57);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato3_1.pgrc[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 10; ++j) {
		datgraf2_(&c__15, &c__150, &c__20, &npt, &dato3_1.grgrc[j + 
			if__ * 10 - 11], &dato3_1.nzgrc[j + if__ * 10 - 11], &
			dato3_1.zgrc[(j + if__ * 10) * 20 - 220], &
			dato3_1.ngrc[(j + if__ * 10) * 20 - 220], &
			dato3_1.xgrc[(j + if__ * 10) * 150 - 1650], &
			dato3_1.ygrc[(j + if__ * 10) * 150 - 1650], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato3_1.grtd1[if__ - 1],
		     &dato3_1.nztd1[if__ - 1], &dato3_1.zhtd1[if__ * 20 - 20],
		     &dato3_1.ntd1[if__ * 20 - 20], &dato3_1.xdtd1[if__ * 500 
		    - 500], &dato3_1.yttd1[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato3_1.grtd2[if__ - 1],
		     &dato3_1.nztd2[if__ - 1], &dato3_1.zwtd2[if__ * 20 - 20],
		     &dato3_1.ntd2[if__ * 20 - 20], &dato3_1.xdtd2[if__ * 500 
		    - 500], &dato3_1.ydtd2[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___58);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato3_1.ptdc[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 8; ++j) {
		datgraf2_(&c__15, &c__150, &c__15, &npt, &dato3_1.grtdc[j + (
			if__ << 3) - 9], &dato3_1.nztdc[j + (if__ << 3) - 9], 
			&dato3_1.ztdc[(j + (if__ << 3)) * 15 - 135], &
			dato3_1.ntdc[(j + (if__ << 3)) * 15 - 135], &
			dato3_1.xtdc[(j + (if__ << 3)) * 150 - 1350], &
			dato3_1.ytdc[(j + (if__ << 3)) * 150 - 1350], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    datgraf2_(&c__15, &c__200, &c__10, &npt, &dato3_1.grda1[if__ - 1],
		     &dato3_1.nzda1[if__ - 1], &dato3_1.zfda1[if__ * 10 - 10],
		     &dato3_1.nda1[if__ * 10 - 10], &dato3_1.xgda1[if__ * 200 
		    - 200], &dato3_1.ydda1[if__ * 200 - 200], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___59);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato3_1.pda1c[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 4; ++j) {
		datgraf2_(&c__15, &c__100, &c__15, &npt, &dato3_1.grda1c[j + (
			if__ << 2) - 5], &dato3_1.nzda1c[j + (if__ << 2) - 5],
			 &dato3_1.zda1c[(j + (if__ << 2)) * 15 - 75], &
			dato3_1.nda1c[(j + (if__ << 2)) * 15 - 75], &
			dato3_1.xda1c[(j + (if__ << 2)) * 100 - 500], &
			dato3_1.yda1c[(j + (if__ << 2)) * 100 - 500], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	}
    }
    if (resto_1.mil == 1 || resto_1.mil == 3) {
	i__2 = dagen3_1.ndf[0];
	for (if__ = 1; if__ <= i__2; ++if__) {
	    datgraf2_(&c__15, &c__500, &c__20, &npt, &dato4_1.grvr1[if__ - 1],
		     &dato4_1.nzvr1[if__ - 1], &dato4_1.zhvr1[if__ * 20 - 20],
		     &dato4_1.nvr1[if__ * 20 - 20], &dato4_1.xtvr1[if__ * 500 
		    - 500], &dato4_1.ysvr1[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__100, &c__20, &npt, &dato4_1.grvr2[if__ - 1],
		     &dato4_1.nzvr2[if__ - 1], &dato4_1.zdvr2[if__ * 20 - 20],
		     &dato4_1.nvr2[if__ * 20 - 20], &dato4_1.xsvr2[if__ * 500 
		    - 500], &dato4_1.ysvr2[if__ * 500 - 500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__200, &c__10, &npt, &dato4_1.grvr3[if__ - 1],
		     &dato4_1.nzvr3[if__ - 1], &dato4_1.zwvr3[if__ * 10 - 10],
		     &dato4_1.nvr3[if__ * 10 - 10], &dato4_1.xsvr3[if__ * 200 
		    - 200], &dato4_1.ysvr3[if__ * 200 - 200], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___60);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato4_1.pvrc[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 8; ++j) {
		datgraf2_(&c__15, &c__400, &c__30, &npt, &dato4_1.grvrc[j + (
			if__ << 3) - 9], &dato4_1.nzvrc[j + (if__ << 3) - 9], 
			&dato4_1.zvrc[(j + (if__ << 3)) * 30 - 270], &
			dato4_1.nvrc[(j + (if__ << 3)) * 30 - 270], &
			dato4_1.xvrc[(j + (if__ << 3)) * 400 - 3600], &
			dato4_1.yvrc[(j + (if__ << 3)) * 400 - 3600], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	}
    }
    i__2 = dagen3_1.ndf[0];
    for (if__ = 1; if__ <= i__2; ++if__) {
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato5_1.grvt[if__ - 1], &
		dato5_1.nzvt[if__ - 1], &dato5_1.zhvt[if__ * 20 - 20], &
		dato5_1.nvt[if__ * 20 - 20], &dato5_1.xtvt[if__ * 500 - 500], 
		&dato5_1.ysvt[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__15, &npt, &dato5_1.grvro1[if__ - 1], &
		dato5_1.nzvro1[if__ - 1], &dato5_1.zwvro1[if__ * 15 - 15], &
		dato5_1.nvro1[if__ * 15 - 15], &dato5_1.xsvro1[if__ * 500 - 
		500], &dato5_1.ysvro1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__16, &npt, &dato5_1.grvro2[if__ - 1], &
		dato5_1.nzvro2[if__ - 1], &dato5_1.zwvro2[(if__ << 4) - 16], &
		dato5_1.nvro2[(if__ << 4) - 16], &dato5_1.xsvro2[if__ * 500 - 
		500], &dato5_1.ysvro2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__50, &dato5_1.grvro3[if__ - 1], &dato5_1.nvro3[
		if__ - 1], &dato5_1.xwvro3[if__ * 50 - 50], &dato5_1.ysvro3[
		if__ * 50 - 50], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___61);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato5_1.pvroc[i__ + if__ * 15 - 16],
		     (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 3; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato5_1.grvroc[j + if__ 
		    * 3 - 4], &dato5_1.nzvroc[j + if__ * 3 - 4], &
		    dato5_1.zvroc[(j + if__ * 3) * 15 - 60], &dato5_1.nvroc[(
		    j + if__ * 3) * 15 - 60], &dato5_1.xvroc[(j + if__ * 3) * 
		    100 - 400], &dato5_1.yvroc[(j + if__ * 3) * 100 - 400], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf2_(&c__15, &c__500, &c__15, &npt, &dato5_1.grv21[if__ - 1], &
		dato5_1.nzv21[if__ - 1], &dato5_1.zwv21[if__ * 15 - 15], &
		dato5_1.nv21[if__ * 15 - 15], &dato5_1.xsv21[if__ * 500 - 500]
		, &dato5_1.ysv21[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__50, &dato5_1.grv22[if__ - 1], &dato5_1.nv22[
		if__ - 1], &dato5_1.xwv22[if__ * 50 - 50], &dato5_1.ysv22[
		if__ * 50 - 50], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___62);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato5_1.pv2c[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 3; ++j) {
	    datgraf2_(&c__15, &c__100, &c__15, &npt, &dato5_1.grv2c[j + if__ *
		     3 - 4], &dato5_1.nzv2c[j + if__ * 3 - 4], &dato5_1.zv2c[(
		    j + if__ * 3) * 15 - 60], &dato5_1.nv2c[(j + if__ * 3) * 
		    15 - 60], &dato5_1.xv2c[(j + if__ * 3) * 100 - 400], &
		    dato5_1.yv2c[(j + if__ * 3) * 100 - 400], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf3_(&c__15, &c__16, &dato5_1.grvrf1[if__ - 1], &dato5_1.nv22[
		if__ - 1], &dato5_1.ysvrf1[(if__ << 4) - 16], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__16, &dato5_1.grvrf2[if__ - 1], &dato5_1.nv22[
		if__ - 1], &dato5_1.ysvrf2[(if__ << 4) - 16], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__16, &dato5_1.grvfto[if__ - 1], &dato5_1.nv22[
		if__ - 1], &dato5_1.ysvfto[(if__ << 4) - 16], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__16, &dato5_1.grvti[if__ - 1], &dato5_1.nvti[
		if__ - 1], &dato5_1.xtvti[(if__ << 4) - 16], &dato5_1.ytvti[(
		if__ << 4) - 16], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___63);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato5_1.dfret[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___64);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato5_1.dvrf1[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___65);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato5_1.dvrf2[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___66);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato5_1.dvfto[if__ - 1], (ftnlen)sizeof(
		real));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dato5_1.grdvrf1c[if__ - 1], &
		dato5_1.ndvrf1c[if__ - 1], &dato5_1.xdvrf1c[if__ * 10 - 10], &
		dato5_1.ydvrf1c[if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dato5_1.grdvrf2c[if__ - 1], &
		dato5_1.ndvrf2c[if__ - 1], &dato5_1.xdvrf2c[if__ * 10 - 10], &
		dato5_1.ydvrf2c[if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dato5_1.grdvftoc[if__ - 1], &
		dato5_1.ndvftoc[if__ - 1], &dato5_1.xdvftoc[if__ * 10 - 10], &
		dato5_1.ydvftoc[if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dato5_1.grvmg[if__ - 1], &
		dato5_1.nzvmg[if__ - 1], &dato5_1.zhvmg[if__ * 20 - 20], &
		dato5_1.nvmg[if__ * 20 - 20], &dato5_1.xtvmg[if__ * 500 - 500]
		, &dato5_1.ysvmg[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    i__2 = dagen3_1.ndf[0];
    for (if__ = 1; if__ <= i__2; ++if__) {
	i__3 = s_rsue(&io___67);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dato6_1.nsen[if__ - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__1500, &c__100, &npt, &dato6_1.grfp1[if__ - 1], &
		dato6_1.nzfp1[if__ - 1], &dato6_1.zgfp1[if__ * 100 - 100], &
		dato6_1.nfp1[if__ * 100 - 100], &dato6_1.xdfp1[if__ * 1500 - 
		1500], &dato6_1.yhfp1[if__ * 1500 - 1500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__60, &npt, &dato6_1.grfp2[if__ - 1], &
		dato6_1.nzfp2[if__ - 1], &dato6_1.zdfp2[if__ * 60 - 60], &
		dato6_1.nfp2[if__ * 60 - 60], &dato6_1.xdfp2[if__ * 500 - 500]
		, &dato6_1.yvfp2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__30, &dato6_1.grfq0[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.xgfq[if__ * 30 - 30], &dato6_1.ydfq0[if__ * 30 
		- 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq1[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.ydfq1[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq2[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.ydfq2[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq3[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.ydfq3[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq4[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.ydfq4[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq5[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.yhfq5[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq6[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.yhfq6[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq7[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.yhfq7[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq8[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.yhfq8[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf3_(&c__15, &c__30, &dato6_1.grfq9[if__ - 1], &dato6_1.nfq[if__ 
		- 1], &dato6_1.yhfq9[if__ * 30 - 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__30, &dato6_1.grac[if__ - 1], &dato6_1.nac[if__ 
		- 1], &dato6_1.xgac[if__ * 30 - 30], &dato6_1.yhac[if__ * 30 
		- 30], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___68);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dato6_1.pacc[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 4; ++j) {
	    datgraf2_(&c__15, &c__300, &c__25, &npt, &dato6_1.gracc[j + (if__ 
		    << 2) - 5], &dato6_1.nzacc[j + (if__ << 2) - 5], &
		    dato6_1.zacc[(j + (if__ << 2)) * 25 - 125], &dato6_1.nacc[
		    (j + (if__ << 2)) * 25 - 125], &dato6_1.xacc[(j + (if__ <<
		     2)) * 300 - 1500], &dato6_1.yacc[(j + (if__ << 2)) * 300 
		    - 1500], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	if (dato6_1.nsen[if__ - 1] > 1) {
	    datgraf2_(&c__15, &c__550, &c__30, &npt, &dato6_1.grfpa1[if__ - 1]
		    , &dato6_1.nzfpa1[if__ - 1], &dato6_1.zgfpa1[if__ * 30 - 
		    30], &dato6_1.nfpa1[if__ * 30 - 30], &dato6_1.xdfpa1[if__ 
		    * 550 - 550], &dato6_1.yhfpa1[if__ * 550 - 550], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__150, &c__16, &npt, &dato6_1.grfpa2[if__ - 1]
		    , &dato6_1.nzfpa2[if__ - 1], &dato6_1.zdfpa2[(if__ << 4) 
		    - 16], &dato6_1.nfpa2[(if__ << 4) - 16], &dato6_1.xdfpa2[
		    if__ * 150 - 150], &dato6_1.yvfpa2[if__ * 150 - 150], &ie)
		    ;
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf1_(&c__15, &c__30, &dato6_1.grfqa0[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.xgfqa[if__ * 30 - 30], &
		    dato6_1.ydfqa0[if__ * 30 - 30], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa1[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.ydfqa1[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa2[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.ydfqa2[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa3[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.ydfqa3[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa4[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.ydfqa4[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa5[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.yhfqa5[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa6[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.yhfqa6[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa7[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.yhfqa7[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa8[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.yhfqa8[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf3_(&c__15, &c__30, &dato6_1.grfqa9[if__ - 1], &
		    dato6_1.nfqa[if__ - 1], &dato6_1.yhfqa9[if__ * 30 - 30], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf1_(&c__15, &c__30, &dato6_1.graca[if__ - 1], &dato6_1.naca[
		    if__ - 1], &dato6_1.xgaca[if__ * 30 - 30], &dato6_1.yhaca[
		    if__ * 30 - 30], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___69);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 15; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dato6_1.pacac[i__ + if__ * 15 - 
			16], (ftnlen)sizeof(integer));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (j = 1; j <= 4; ++j) {
		datgraf2_(&c__15, &c__300, &c__25, &npt, &dato6_1.gracac[j + (
			if__ << 2) - 5], &dato6_1.nzacac[j + (if__ << 2) - 5],
			 &dato6_1.zacac[(j + (if__ << 2)) * 25 - 125], &
			dato6_1.nacac[(j + (if__ << 2)) * 25 - 125], &
			dato6_1.xacac[(j + (if__ << 2)) * 300 - 1500], &
			dato6_1.yacac[(j + (if__ << 2)) * 300 - 1500], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	}
    }
    datgraf2_(&c__15, &c__200, &c__20, &npt, &dato7_1.gren1, &dato7_1.nzen1, 
	    dato7_1.zsen1, dato7_1.nen1, dato7_1.xwen1, dato7_1.yeen1, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__200, &c__20, &npt, &dato7_1.gren2, &dato7_1.nzen2, 
	    dato7_1.zeen2, dato7_1.nen2, dato7_1.xhen2, dato7_1.yeen2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__200, &c__20, &npt, &dato7_1.gren3, &dato7_1.nzen3, 
	    dato7_1.zeen3, dato7_1.nen3, dato7_1.xten3, dato7_1.yeen3, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__200, &c__15, &npt, &dato7_1.grenc1, &dato7_1.nzenc1,
	     dato7_1.zeenc1, dato7_1.nenc1, dato7_1.xpenc1, dato7_1.yeenc1, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__200, &c__15, &npt, &dato7_1.grenc2, &dato7_1.nzenc2,
	     dato7_1.zeenc2, dato7_1.nenc2, dato7_1.xvenc2, dato7_1.yeenc2, &
	    ie);
    if (ie > 0) {
	goto L1500;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L1500:
    if (resto_1.mil == 0) {
	*ier = 408;
    } else if (resto_1.mil == 1) {
	*ier = 404;
    } else if (resto_1.mil == 2) {
	*ier = 406;
    } else {
	*ier = 407;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* lecto_ */

/* Subroutine */ int lectl_(char *vic, integer *ier, ftnlen vic_len)
{
    /* System generated locals */
    address a__1[4];
    integer i__1[4], i__2, i__3;
    char ch__1[212];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, j, ie, if__, npt, jerr;
    extern /* Subroutine */ int datgraf1_(integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), datgraf2_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___72 = { 1, 15, 0, 0, 0 };
    static cilist io___73 = { 1, 15, 0, 0, 0 };
    static cilist io___74 = { 1, 15, 0, 0, 0 };
    static cilist io___75 = { 1, 15, 0, 0, 0 };
    static cilist io___76 = { 1, 15, 0, 0, 0 };
    static cilist io___77 = { 1, 15, 0, 0, 0 };
    static cilist io___78 = { 1, 15, 0, 0, 0 };
    static cilist io___79 = { 1, 15, 0, 0, 0 };
    static cilist io___80 = { 1, 15, 0, 0, 0 };
    static cilist io___81 = { 1, 15, 0, 0, 0 };
    static cilist io___82 = { 1, 15, 0, 0, 0 };
    static cilist io___83 = { 1, 15, 0, 0, 0 };
    static cilist io___84 = { 1, 15, 0, 0, 0 };
    static cilist io___85 = { 1, 15, 0, 0, 0 };
    static cilist io___86 = { 1, 15, 0, 0, 0 };
    static cilist io___87 = { 1, 15, 0, 0, 0 };
    static cilist io___88 = { 1, 15, 0, 0, 0 };
    static cilist io___89 = { 1, 15, 0, 0, 0 };
    static cilist io___90 = { 1, 15, 0, 0, 0 };
    static cilist io___91 = { 1, 15, 0, 0, 0 };
    static cilist io___92 = { 1, 15, 0, 0, 0 };
    static cilist io___93 = { 1, 15, 0, 0, 0 };
    static cilist io___94 = { 1, 15, 0, 0, 0 };
    static cilist io___95 = { 1, 15, 0, 0, 0 };
    static cilist io___96 = { 1, 15, 0, 0, 0 };
    static cilist io___97 = { 1, 15, 0, 0, 0 };
    static cilist io___98 = { 1, 15, 0, 0, 0 };
    static cilist io___99 = { 1, 15, 0, 0, 0 };
    static cilist io___100 = { 1, 15, 0, 0, 0 };
    static cilist io___101 = { 1, 15, 0, 0, 0 };
    static cilist io___102 = { 1, 15, 0, 0, 0 };
    static cilist io___106 = { 1, 15, 0, 0, 0 };
    static cilist io___108 = { 1, 15, 0, 0, 0 };
    static cilist io___109 = { 1, 15, 0, 0, 0 };
    static cilist io___110 = { 1, 15, 0, 0, 0 };
    static cilist io___111 = { 1, 15, 0, 0, 0 };
    static cilist io___112 = { 1, 15, 0, 0, 0 };
    static cilist io___113 = { 1, 15, 0, 0, 0 };
    static cilist io___114 = { 1, 15, 0, 0, 0 };
    static cilist io___115 = { 1, 15, 0, 0, 0 };
    static cilist io___116 = { 1, 15, 0, 0, 0 };
    static cilist io___117 = { 1, 15, 0, 0, 0 };
    static cilist io___118 = { 1, 15, 0, 0, 0 };
    static cilist io___119 = { 1, 15, 0, 0, 0 };


    s_copy(afm_1.afm_far__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_mil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_tac__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lfar__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lmil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_ltac__, "      ", (ftnlen)6, (ftnlen)6);
    *ier = 0;
    i__ = i_indx(vic, "  ", (ftnlen)200, (ftnlen)2) - 1;
    if (resld_1.mil == 0) {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "L";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "F.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_lfar__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    } else if (resld_1.mil == 1) {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "L";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "M.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_lmil__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    } else {
	o__1.oerr = 1;
	o__1.ounit = 15;
	o__1.ofnmlen = i__ + 12;
/* Writing concatenation */
	i__1[0] = i__, a__1[0] = vic;
	i__1[1] = 1, a__1[1] = "L";
	i__1[2] = 6, a__1[2] = afm_1.afm;
	i__1[3] = 5, a__1[3] = "T.UNF";
	s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)212);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	jerr = f_open(&o__1);
	s_copy(afm_1.afm_ltac__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    }
    i__2 = s_rsue(&io___72);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.verd[1], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___73);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___74);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___75);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___76);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwin[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwin[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___77);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limslp[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limslp[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___78);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___79);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[2], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[3], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___80);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.ndf[1], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen3_1.ndf[1] > 2 || dagen3_1.ndf[1] < 1) {
	goto L1500;
    }
    i__2 = s_rsue(&io___81);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.df[i__ + 1], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___82);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoatg[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___83);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limwing[1], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___84);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcrp[i__ + 19], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___85);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcr[i__ + 19], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___86);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.vrcru[i__ + 9], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___87);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.grcbr[1], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___88);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.ncbr[1], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen3_1.ncbr[1] > 10) {
	goto L1500;
    }
    i__2 = s_rsue(&io___89);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ncbr[1];
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.xcbr[i__ + 9], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___90);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ncbr[1];
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.ydcbr[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___91);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.ndff, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dagen3_1.ndff > 8) {
	goto L1500;
    }
    i__2 = s_rsue(&io___92);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.dff[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___93);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.limdff[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___94);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.apdff[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___95);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.gadff[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___96);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.segdff[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___97);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dagen3_1.ndff;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.madff[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___98);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limlg, (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___99);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limty, (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___100);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 2; i__ <= 3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.limene[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___101);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dagen3_1.limdfk[i__ - 1], (ftnlen)
		sizeof(integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___102);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.iopk, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__50, &c__5, &npt, &dagen3_1.grcrw1, &dagen3_1.nzcrw1,
	     dagen3_1.zfcrw1, dagen3_1.ncrw1, dagen3_1.xvcrw1, 
	    dagen3_1.yscrw1, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__50, &c__5, &npt, &dagen3_1.grcrw2, &dagen3_1.nzcrw2,
	     dagen3_1.zfcrw2, dagen3_1.ncrw2, dagen3_1.xvcrw2, 
	    dagen3_1.yscrw2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf1_(&c__15, &c__10, &dagen3_1.grcrdf1, &dagen3_1.ncrdf1, 
	    dagen3_1.xvcrdf1, dagen3_1.yfcrdf1, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf1_(&c__15, &c__10, &dagen3_1.grcrdf2, &dagen3_1.ncrdf2, 
	    dagen3_1.xvcrdf2, dagen3_1.yfcrdf2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = dagen3_1.ndf[1];
    for (if__ = 1; if__ <= i__2; ++if__) {
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald1_1.grw[if__ - 1], &
		dald1_1.nzw[if__ - 1], &dald1_1.zhw[if__ * 20 - 20], &
		dald1_1.nw[if__ * 20 - 20], &dald1_1.xww[if__ * 500 - 500], &
		dald1_1.ytw[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___106);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald1_1.pwc[i__ + if__ * 15 - 16], (
		    ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 5; ++j) {
	    datgraf2_(&c__15, &c__50, &c__5, &npt, &dald1_1.grwc[j + if__ * 5 
		    - 6], &dald1_1.nzwc[j + if__ * 5 - 6], &dald1_1.zwc[(j + 
		    if__ * 5) * 5 - 30], &dald1_1.nwc[(j + if__ * 5) * 5 - 30]
		    , &dald1_1.xwc[(j + if__ * 5) * 50 - 300], &dald1_1.ywc[(
		    j + if__ * 5) * 50 - 300], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dald1_1.grwi[if__ - 1], &dald1_1.nwi[if__ 
		- 1], &dald1_1.xtwi[if__ * 10 - 10], &dald1_1.ytwi[if__ * 10 
		- 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dald1_1.grwj[if__ - 1], &dald1_1.nwj[if__ 
		- 1], &dald1_1.xtwj[if__ * 10 - 10], &dald1_1.ywwj[if__ * 10 
		- 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___108);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dald1_1.indga[if__ - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald1_1.grga1[if__ - 1], &
		dald1_1.nzga1[if__ - 1], &dald1_1.zhga1[if__ * 20 - 20], &
		dald1_1.nga1[if__ * 20 - 20], &dald1_1.xtga1[if__ * 500 - 500]
		, &dald1_1.yga1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__30, &npt, &dald1_1.grga2[if__ - 1], &
		dald1_1.nzga2[if__ - 1], &dald1_1.zgga2[if__ * 30 - 30], &
		dald1_1.nga2[if__ * 30 - 30], &dald1_1.xwga2[if__ * 500 - 500]
		, &dald1_1.yga2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___109);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald1_1.pgac[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 5; ++j) {
	    datgraf2_(&c__15, &c__50, &c__5, &npt, &dald1_1.grgac[j + if__ * 
		    5 - 6], &dald1_1.nzgac[j + if__ * 5 - 6], &dald1_1.zgac[(
		    j + if__ * 5) * 5 - 30], &dald1_1.ngac[(j + if__ * 5) * 5 
		    - 30], &dald1_1.xgac[(j + if__ * 5) * 50 - 300], &
		    dald1_1.ygac[(j + if__ * 5) * 50 - 300], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dald1_1.grgai[if__ - 1], &dald1_1.ngai[
		if__ - 1], &dald1_1.xtgai[if__ * 10 - 10], &dald1_1.ytgai[
		if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__15, &dald1_1.grg[if__ - 1], &dald1_1.ng[if__ - 
		1], &dald1_1.xgg[if__ * 15 - 15], &dald1_1.ycg[if__ * 15 - 15]
		, &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___110);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dald1_1.indbl[if__ - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald1_1.grbl1[if__ - 1], &
		dald1_1.nzbl1[if__ - 1], &dald1_1.zhbl1[if__ * 20 - 20], &
		dald1_1.nbl1[if__ * 20 - 20], &dald1_1.xtbl1[if__ * 500 - 500]
		, &dald1_1.ybl1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__30, &npt, &dald1_1.grbl2[if__ - 1], &
		dald1_1.nzbl2[if__ - 1], &dald1_1.zgbl2[if__ * 30 - 30], &
		dald1_1.nbl2[if__ * 30 - 30], &dald1_1.xwbl2[if__ * 500 - 500]
		, &dald1_1.ybl2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___111);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald1_1.pblc[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 5; ++j) {
	    datgraf2_(&c__15, &c__50, &c__5, &npt, &dald1_1.grblc[j + if__ * 
		    5 - 6], &dald1_1.nzblc[j + if__ * 5 - 6], &dald1_1.zblc[(
		    j + if__ * 5) * 5 - 30], &dald1_1.nblc[(j + if__ * 5) * 5 
		    - 30], &dald1_1.xblc[(j + if__ * 5) * 50 - 300], &
		    dald1_1.yblc[(j + if__ * 5) * 50 - 300], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf1_(&c__15, &c__10, &dald1_1.grbli[if__ - 1], &dald1_1.nbli[
		if__ - 1], &dald1_1.xtbli[if__ * 10 - 10], &dald1_1.ytbli[
		if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    i__2 = dagen3_1.ndf[1];
    for (if__ = 1; if__ <= i__2; ++if__) {
	i__3 = s_rsue(&io___112);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dald2_1.indgr[if__ - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald2_1.grgr1[if__ - 1], &
		dald2_1.nzgr1[if__ - 1], &dald2_1.zhgr1[if__ * 20 - 20], &
		dald2_1.ngr1[if__ * 20 - 20], &dald2_1.xgr1[if__ * 500 - 500],
		 &dald2_1.ydgr1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald2_1.grgr2[if__ - 1], &
		dald2_1.nzgr2[if__ - 1], &dald2_1.zgr2[if__ * 20 - 20], &
		dald2_1.ngr2[if__ * 20 - 20], &dald2_1.xgr2[if__ * 500 - 500],
		 &dald2_1.ydgr2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___113);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald2_1.pgrc[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 8; ++j) {
	    datgraf2_(&c__15, &c__180, &c__20, &npt, &dald2_1.grgrc[j + (if__ 
		    << 3) - 9], &dald2_1.nzgrc[j + (if__ << 3) - 9], &
		    dald2_1.zgrc[(j + (if__ << 3)) * 20 - 180], &dald2_1.ngrc[
		    (j + (if__ << 3)) * 20 - 180], &dald2_1.xgrc[(j + (if__ <<
		     3)) * 180 - 1620], &dald2_1.ygrc[(j + (if__ << 3)) * 180 
		    - 1620], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	i__3 = s_rsue(&io___114);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dald2_1.indld[if__ - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald2_1.grld1[if__ - 1], &
		dald2_1.nzld1[if__ - 1], &dald2_1.zhld1[if__ * 20 - 20], &
		dald2_1.nld1[if__ * 20 - 20], &dald2_1.xld1[if__ * 500 - 500],
		 &dald2_1.ydld1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald2_1.grld2[if__ - 1], &
		dald2_1.nzld2[if__ - 1], &dald2_1.zld2[if__ * 20 - 20], &
		dald2_1.nld2[if__ * 20 - 20], &dald2_1.xld2[if__ * 500 - 500],
		 &dald2_1.ydld2[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___115);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald2_1.pldc[i__ + if__ * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 8; ++j) {
	    datgraf2_(&c__15, &c__180, &c__20, &npt, &dald2_1.grldc[j + (if__ 
		    << 3) - 9], &dald2_1.nzldc[j + (if__ << 3) - 9], &
		    dald2_1.zldc[(j + (if__ << 3)) * 20 - 180], &dald2_1.nldc[
		    (j + (if__ << 3)) * 20 - 180], &dald2_1.xldc[(j + (if__ <<
		     3)) * 180 - 1620], &dald2_1.yldc[(j + (if__ << 3)) * 180 
		    - 1620], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
    }
    i__2 = dagen3_1.ndf[1];
    for (if__ = 1; if__ <= i__2; ++if__) {
	datgraf2_(&c__15, &c__500, &c__20, &npt, &dald3_1.grvt[if__ - 1], &
		dald3_1.nzvt[if__ - 1], &dald3_1.zhvt[if__ * 20 - 20], &
		dald3_1.nvt[if__ * 20 - 20], &dald3_1.xtvt[if__ * 500 - 500], 
		&dald3_1.ysvt[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__10, &dald3_1.grvti[if__ - 1], &dald3_1.nvti[
		if__ - 1], &dald3_1.xtvti[if__ * 10 - 10], &dald3_1.ytvti[
		if__ * 10 - 10], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__500, &c__15, &npt, &dald3_1.grvr1[if__ - 1], &
		dald3_1.nzvr1[if__ - 1], &dald3_1.zwvr1[if__ * 15 - 15], &
		dald3_1.nvr1[if__ * 15 - 15], &dald3_1.xsvr1[if__ * 500 - 500]
		, &dald3_1.ysvr1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___116);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald3_1.pvr1c[i__ + if__ * 15 - 16],
		     (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 3; ++j) {
	    datgraf2_(&c__15, &c__100, &c__3, &npt, &dald3_1.grvr1c[j + if__ *
		     3 - 4], &dald3_1.nzvr1c[j + if__ * 3 - 4], &
		    dald3_1.zvr1c[(j + if__ * 3) * 10 - 40], &dald3_1.nvr1c[(
		    j + if__ * 3) * 10 - 40], &dald3_1.xvr1c[(j + if__ * 3) * 
		    100 - 400], &dald3_1.yvr1c[(j + if__ * 3) * 100 - 400], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
	datgraf2_(&c__15, &c__500, &c__15, &npt, &dald3_1.grvg1[if__ - 1], &
		dald3_1.nzvg1[if__ - 1], &dald3_1.zwvg1[if__ * 15 - 15], &
		dald3_1.nvg1[if__ * 15 - 15], &dald3_1.xsvg1[if__ * 500 - 500]
		, &dald3_1.ysvg1[if__ * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___117);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dald3_1.pvg1c[i__ + if__ * 15 - 16],
		     (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 3; ++j) {
	    datgraf2_(&c__15, &c__100, &c__3, &npt, &dald3_1.grvg1c[j + if__ *
		     3 - 4], &dald3_1.nzvg1c[j + if__ * 3 - 4], &
		    dald3_1.zvg1c[(j + if__ * 3) * 10 - 40], &dald3_1.nvg1c[(
		    j + if__ * 3) * 10 - 40], &dald3_1.xvg1c[(j + if__ * 3) * 
		    100 - 400], &dald3_1.yvg1c[(j + if__ * 3) * 100 - 400], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
    }
    datgraf2_(&c__15, &c__500, &c__8, &npt, dald3_1.grvr2, dald3_1.nzvr2, 
	    dald3_1.zfvr2, dald3_1.nvr2, dald3_1.xwvr2, dald3_1.ysvr2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__8, &npt, dald3_1.grvg2, dald3_1.nzvg2, 
	    dald3_1.zfvg2, dald3_1.nvg2, dald3_1.xwvg2, dald3_1.ysvg2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__8, &npt, dald3_1.grvr3, dald3_1.nzvr3, 
	    dald3_1.zfvr3, dald3_1.nvr3, dald3_1.xwvr3, dald3_1.ysvr3, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__8, &npt, dald3_1.grvg3, dald3_1.nzvg3, 
	    dald3_1.zfvg3, dald3_1.nvg3, dald3_1.xwvg3, dald3_1.ysvg3, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___118);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dald3_1.dvapp, (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___119);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dald3_1.dvman, (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L1500:
    if (resld_1.mil == 0) {
	*ier = 414;
    } else if (resld_1.mil == 1) {
	*ier = 410;
    } else {
	*ier = 412;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* lectl_ */

/* Subroutine */ int lectm_(char *vic, integer *ier, ftnlen vic_len)
{
    /* System generated locals */
    address a__1[4];
    integer i__1[4], i__2, i__3, i__4;
    char ch__1[211];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, j, j1, k1, k2, j2, k3, j3, ie, il, iq, ir, is, cont, 
	    jerr;
    extern /* Subroutine */ int datgraf1_(integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), datgraf2_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___122 = { 1, 15, 0, 0, 0 };
    static cilist io___123 = { 1, 15, 0, 0, 0 };
    static cilist io___124 = { 1, 15, 0, 0, 0 };
    static cilist io___125 = { 1, 15, 0, 0, 0 };
    static cilist io___126 = { 1, 15, 0, 0, 0 };
    static cilist io___127 = { 1, 15, 0, 0, 0 };
    static cilist io___129 = { 1, 15, 0, 0, 0 };
    static cilist io___131 = { 1, 15, 0, 0, 0 };
    static cilist io___132 = { 1, 15, 0, 0, 0 };
    static cilist io___133 = { 1, 15, 0, 0, 0 };
    static cilist io___134 = { 1, 15, 0, 0, 0 };
    static cilist io___144 = { 1, 15, 0, 0, 0 };
    static cilist io___145 = { 1, 15, 0, 0, 0 };
    static cilist io___146 = { 1, 15, 0, 0, 0 };
    static cilist io___147 = { 1, 15, 0, 0, 0 };
    static cilist io___148 = { 1, 15, 0, 0, 0 };
    static cilist io___149 = { 1, 15, 0, 0, 0 };
    static cilist io___150 = { 1, 15, 0, 0, 0 };
    static cilist io___152 = { 1, 15, 0, 0, 0 };
    static cilist io___153 = { 1, 15, 0, 0, 0 };
    static cilist io___154 = { 1, 15, 0, 0, 0 };
    static cilist io___155 = { 1, 15, 0, 0, 0 };
    static cilist io___157 = { 1, 15, 0, 0, 0 };
    static cilist io___158 = { 1, 15, 0, 0, 0 };
    static cilist io___159 = { 1, 15, 0, 0, 0 };
    static cilist io___160 = { 1, 15, 0, 0, 0 };
    static cilist io___161 = { 1, 15, 0, 0, 0 };
    static cilist io___162 = { 1, 15, 0, 0, 0 };
    static cilist io___163 = { 1, 15, 0, 0, 0 };
    static cilist io___164 = { 1, 15, 0, 0, 0 };
    static cilist io___165 = { 1, 15, 0, 0, 0 };
    static cilist io___166 = { 1, 15, 0, 0, 0 };
    static cilist io___167 = { 1, 15, 0, 0, 0 };
    static cilist io___168 = { 1, 15, 0, 0, 0 };
    static cilist io___169 = { 1, 15, 0, 0, 0 };
    static cilist io___170 = { 1, 15, 0, 0, 0 };
    static cilist io___171 = { 1, 15, 0, 0, 0 };
    static cilist io___172 = { 1, 15, 0, 0, 0 };
    static cilist io___173 = { 1, 15, 0, 0, 0 };
    static cilist io___174 = { 1, 15, 0, 0, 0 };
    static cilist io___175 = { 1, 15, 0, 0, 0 };
    static cilist io___176 = { 1, 15, 0, 0, 0 };
    static cilist io___177 = { 1, 15, 0, 0, 0 };


    s_copy(afm_1.afm_far__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_mil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_tac__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lfar__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_lmil__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_ltac__, "      ", (ftnlen)6, (ftnlen)6);
    s_copy(afm_1.afm_ms__, "     ", (ftnlen)6, (ftnlen)5);
    *ier = 0;
    i__ = i_indx(vic, "  ", (ftnlen)200, (ftnlen)2) - 1;
    o__1.oerr = 1;
    o__1.ounit = 15;
    o__1.ofnmlen = i__ + 11;
/* Writing concatenation */
    i__1[0] = i__, a__1[0] = vic;
    i__1[1] = 1, a__1[1] = "M";
    i__1[2] = 6, a__1[2] = afm_1.afm;
    i__1[3] = 4, a__1[3] = ".UNF";
    s_cat(ch__1, a__1, i__1, &c__4, (ftnlen)211);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    jerr = f_open(&o__1);
    s_copy(afm_1.afm_ms__, afm_1.afm, (ftnlen)6, (ftnlen)6);
    i__2 = s_rsue(&io___122);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.verd[3], (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___123);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[4], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limalt[5], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___124);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[4], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoat[5], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___125);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[4], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limoati[5], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___126);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[4], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limdi[5], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___127);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[4], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dagen3_1.limw[5], (ftnlen)sizeof(real));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    datgraf1_(&c__15, &c__10, &dagen3_1.grlpr, &dagen3_1.nlpr, dagen3_1.xhlpr,
	     dagen3_1.yhlpr, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___129);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams1_1.sley, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams1_1.sley > 12) {
	goto L1500;
    }
    i__2 = dams1_1.sley;
    for (il = 1; il <= i__2; ++il) {
	i__3 = s_rsue(&io___131);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams1_1.scod[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___132);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams1_1.sinop[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___133);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams1_1.nsisa[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	if (dams1_1.nsisa[il - 1] == 0) {
	    goto L50;
	}
	if (dams1_1.nsisa[il - 1] > 9) {
	    goto L1500;
	}
	if (dams1_1.scod[il - 1] == 0) {
	    i__3 = s_rsue(&io___134);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__4 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams1_1.sisa[i__ + il * 9 - 10],
			 (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    j1 = 1;
	    k1 = 1;
	    j2 = 1;
	    k2 = 1;
	    j3 = 1;
	    k3 = 1;
	    i__3 = dams1_1.nsisa[il - 1];
	    for (is = 1; is <= i__3; ++is) {
		if (il > 12) {
		    goto L1500;
		}
		datgraf2_(&c__15, &c__1500, &c__50, &dams1_1.npmsfu[is + il * 
			9 - 10], &dams1_1.grsfu[is + il * 9 - 10], &
			dams1_1.nzsfu[is + il * 9 - 10], &dams1_1.zsfu[k1 + 
			il * 150 - 151], &dams1_1.nsfu[k1 + il * 150 - 151], &
			dams1_1.xsfu[j1 + il * 4000 - 4001], &dams1_1.ysfu[j1 
			+ il * 4000 - 4001], &ie);
		if (ie > 0) {
		    goto L1500;
		}
		j1 += dams1_1.npmsfu[is + il * 9 - 10];
		k1 += dams1_1.nzsfu[is + il * 9 - 10];
		datgraf2_(&c__15, &c__1500, &c__50, &dams1_1.npmsti[is + il * 
			9 - 10], &dams1_1.grsti[is + il * 9 - 10], &
			dams1_1.nzsti[is + il * 9 - 10], &dams1_1.zsti[k2 + 
			il * 150 - 151], &dams1_1.nsti[k2 + il * 150 - 151], &
			dams1_1.xsti[j2 + il * 4000 - 4001], &dams1_1.ysti[j2 
			+ il * 4000 - 4001], &ie);
		if (ie > 0) {
		    goto L1500;
		}
		j2 += dams1_1.npmsti[is + il * 9 - 10];
		k2 += dams1_1.nzsti[is + il * 9 - 10];
		datgraf2_(&c__15, &c__1500, &c__50, &dams1_1.npmsdi[is + il * 
			9 - 10], &dams1_1.grsdi[is + il * 9 - 10], &
			dams1_1.nzsdi[is + il * 9 - 10], &dams1_1.zsdi[k3 + 
			il * 150 - 151], &dams1_1.nsdi[k3 + il * 150 - 151], &
			dams1_1.xsdi[j3 + il * 4000 - 4001], &dams1_1.ysdi[j3 
			+ il * 4000 - 4001], &ie);
		if (ie > 0) {
		    goto L1500;
		}
		j3 += dams1_1.npmsdi[is + il * 9 - 10];
		k3 += dams1_1.nzsdi[is + il * 9 - 10];
	    }
	    if (j1 > 4000) {
		goto L1500;
	    }
	    if (k1 > 150) {
		goto L1500;
	    }
	    if (j2 > 4000) {
		goto L1500;
	    }
	    if (k2 > 150) {
		goto L1500;
	    }
	    if (j3 > 4000) {
		goto L1500;
	    }
	    if (k3 > 150) {
		goto L1500;
	    }
	    cont = 0;
	    for (j = 1; j <= 5; ++j) {
		i__3 = s_rsue(&io___144);
		if (i__3 != 0) {
		    goto L1500;
		}
		for (i__ = 1; i__ <= 5; ++i__) {
		    i__3 = do_uio(&c__1, (char *)&dams2_1.spc[j + (i__ + il * 
			    5) * 5 - 31], (ftnlen)sizeof(real));
		    if (i__3 != 0) {
			goto L1500;
		    }
		}
		i__3 = e_rsue();
		if (i__3 != 0) {
		    goto L1500;
		}
		for (i__ = 2; i__ <= 4; ++i__) {
		    if (dams2_1.spc[j + (i__ + il * 5) * 5 - 31] < -100.f) {
			if (dams2_1.spc[j + (i__ + il * 5) * 5 - 31] == 
				dams2_1.spc[j + (i__ - 1 + il * 5) * 5 - 31]) 
				{
			    cont = cont;
			} else {
			    ++cont;
			}
		    }
		}
		if (dams2_1.spc[j + (il * 5 + 1) * 5 - 31] == 0.f) {
		    goto L140;
		}
	    }
L140:
	    i__3 = cont;
	    for (j = 1; j <= i__3; ++j) {
		datgraf2_(&c__15, &c__50, &c__5, &dams2_1.npmsc[j + il * 10 - 
			11], &dams2_1.grsc[j + il * 10 - 11], &dams2_1.nzsc[j 
			+ il * 10 - 11], &dams2_1.zsc[(j + il * 10) * 5 - 55],
			 &dams2_1.nsc[(j + il * 10) * 5 - 55], &dams2_1.xsc[(
			j + il * 10) * 50 - 550], &dams2_1.ysc[(j + il * 10) *
			 50 - 550], &ie);
		if (ie > 0) {
		    goto L1500;
		}
	    }
	    datgraf2_(&c__15, &c__50, &c__15, &dams2_1.npmsv[il - 1], &
		    dams2_1.grsv[il - 1], &dams2_1.nzsv[il - 1], &
		    dams2_1.zwsv[il * 15 - 15], &dams2_1.nsv[il * 10 - 10], &
		    dams2_1.xssv[il * 50 - 50], &dams2_1.yhsv[il * 50 - 50], &
		    ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    datgraf2_(&c__15, &c__20, &c__6, &dams2_1.npmsdv[il - 1], &
		    dams2_1.grsdv[il - 1], &dams2_1.nzsdv[il - 1], &
		    dams2_1.zrsdv[il * 6 - 6], &dams2_1.nsdv[il * 6 - 6], &
		    dams2_1.xwsdv[il * 20 - 20], &dams2_1.yssdv[il * 20 - 20],
		     &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	} else {
	    i__3 = s_rsue(&io___145);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__4 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams1_1.sisa[i__ + il * 9 - 10],
			 (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___146);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__4 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams1_1.ysfu[i__ + il * 4000 - 
			4001], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___147);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__4 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams1_1.ysti[i__ + il * 4000 - 
			4001], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = s_rsue(&io___148);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__4 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams1_1.ysdi[i__ + il * 4000 - 
			4001], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    i__3 = dams1_1.nsisa[il - 1];
	    for (i__ = 1; i__ <= i__3; ++i__) {
		dams1_1.npmsfu[i__ + il * 9 - 10] = dams1_1.nsisa[il - 1];
		dams1_1.nsfu[i__ + il * 150 - 151] = 1;
		dams1_1.grsfu[i__ + il * 9 - 10] = 0;
		dams1_1.nzsfu[i__ + il * 9 - 10] = 1;
		dams1_1.zsfu[i__ + il * 150 - 151] = 1.f;
		dams1_1.xsfu[i__ + il * 4000 - 4001] = 1.f;
		dams1_1.npmsti[i__ + il * 9 - 10] = dams1_1.nsisa[il - 1];
		dams1_1.nsti[i__ + il * 150 - 151] = 1;
		dams1_1.grsti[i__ + il * 9 - 10] = 0;
		dams1_1.nzsti[i__ + il * 9 - 10] = 1;
		dams1_1.zsti[i__ + il * 150 - 151] = 1.f;
		dams1_1.xsti[i__ + il * 4000 - 4001] = 1.f;
		dams1_1.npmsdi[i__ + il * 9 - 10] = dams1_1.nsisa[il - 1];
		dams1_1.nsdi[i__ + il * 150 - 151] = 1;
		dams1_1.grsdi[i__ + il * 9 - 10] = 0;
		dams1_1.nzsdi[i__ + il * 9 - 10] = 1;
		dams1_1.zsdi[i__ + il * 150 - 151] = 1.f;
		dams1_1.xsdi[i__ + il * 4000 - 4001] = 1.f;
	    }
	}
L50:
	i__3 = s_rsue(&io___149);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams2_1.indtqs[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
    }
    i__2 = s_rsue(&io___150);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams2_1.ntbtqs, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams2_1.ntbtqs > 5) {
	goto L1500;
    }
    i__2 = dams2_1.ntbtqs;
    for (iq = 1; iq <= i__2; ++iq) {
	datgraf2_(&c__15, &c__600, &c__35, &dams2_1.npmtqs[iq - 1], &
		dams2_1.grtqs[iq - 1], &dams2_1.nztqs[iq - 1], &dams2_1.zhtqs[
		iq * 35 - 35], &dams2_1.ntqs[iq * 35 - 35], &dams2_1.xttqs[iq 
		* 600 - 600], &dams2_1.yqtqs[iq * 600 - 600], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    i__2 = s_rsue(&io___152);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams3_1.indrc, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams3_1.indrc != 1) {
	goto L150;
    }
    datgraf2_(&c__15, &c__500, &c__35, &dams3_1.npmrcm1, &dams3_1.grrcm1, &
	    dams3_1.nzrcm1, dams3_1.zrcm1, dams3_1.nrcm1, dams3_1.xrcm1, 
	    dams3_1.yrcm1, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__15, &dams3_1.npmrcm2, &dams3_1.grrcm2, &
	    dams3_1.nzrcm2, dams3_1.zrcm2, dams3_1.nrcm2, dams3_1.xrcm2, 
	    dams3_1.yrcm2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___153);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 15; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams3_1.prcmc[i__ - 1], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    for (j = 1; j <= 5; ++j) {
	datgraf2_(&c__15, &c__150, &c__15, &dams3_1.npmrcmc[j - 1], &
		dams3_1.grrcmc[j - 1], &dams3_1.nzrcmc[j - 1], &dams3_1.zrcmc[
		j * 15 - 15], &dams3_1.nrcmc[j * 15 - 15], &dams3_1.xrcmc[j * 
		150 - 150], &dams3_1.yrcmc[j * 150 - 150], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	if (dams3_1.nzrcmc[j - 1] == 0) {
	    goto L150;
	}
    }
L150:
    i__2 = s_rsue(&io___154);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams3_1.nrc, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams3_1.nrc > 3) {
	goto L1500;
    }
    i__2 = s_rsue(&io___155);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dams3_1.nrc;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams3_1.rccln[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = dams3_1.nrc;
    for (ir = 1; ir <= i__2; ++ir) {
	datgraf2_(&c__15, &c__500, &c__9, &dams3_1.npmcln[ir - 1], &
		dams3_1.grcln[ir - 1], &dams3_1.nzcln[ir - 1], &dams3_1.zcln[
		ir * 9 - 9], &dams3_1.ncln[ir * 9 - 9], &dams3_1.xcln[ir * 
		500 - 500], &dams3_1.ycln[ir * 500 - 500], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___157);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dams3_1.pclnc[i__ + ir * 15 - 16], (
		    ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 5; ++j) {
	    datgraf2_(&c__15, &c__150, &c__15, &dams3_1.npmclnc[j + ir * 15 - 
		    16], &dams3_1.grclnc[j + ir * 15 - 16], &dams3_1.nzclnc[j 
		    + ir * 15 - 16], &dams3_1.zclnc[(j + ir * 15) * 15 - 240],
		     &dams3_1.nclnc[(j + ir * 15) * 15 - 240], &dams3_1.xclnc[
		    (j + ir * 15) * 150 - 2400], &dams3_1.yclnc[(j + ir * 15) 
		    * 150 - 2400], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    if (dams3_1.nzclnc[j + ir * 15 - 16] == 0) {
		goto L160;
	    }
	}
L160:
	datgraf1_(&c__15, &c__9, &dams3_1.grdh[ir - 1], &dams3_1.ndh[ir - 1], 
		&dams3_1.xtdh[ir * 9 - 9], &dams3_1.yhdh[ir * 9 - 9], &ie);
	if (ie > 0) {
	    goto L1500;
	}
    }
    i__2 = s_rsue(&io___158);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams4_1.indrcf, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams4_1.indrcf != 1) {
	goto L151;
    }
    datgraf2_(&c__15, &c__500, &c__35, &dams4_1.npmrcmf1, &dams4_1.grrcmf1, &
	    dams4_1.nzrcmf1, dams4_1.zrcmf1, dams4_1.nrcmf1, dams4_1.xrcmf1, 
	    dams4_1.yrcmf1, &ie);
    if (ie > 0) {
	goto L1500;
    }
    datgraf2_(&c__15, &c__500, &c__15, &dams4_1.npmrcmf2, &dams4_1.grrcmf2, &
	    dams4_1.nzrcmf2, dams4_1.zrcmf2, dams4_1.nrcmf2, dams4_1.xrcmf2, 
	    dams4_1.yrcmf2, &ie);
    if (ie > 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___159);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 15; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams4_1.prcmfc[i__ - 1], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    for (j = 1; j <= 5; ++j) {
	datgraf2_(&c__15, &c__150, &c__15, &dams4_1.npmrcmfc[j - 1], &
		dams4_1.grrcmfc[j - 1], &dams4_1.nzrcmfc[j - 1], &
		dams4_1.zrcmfc[j * 15 - 15], &dams4_1.nrcmfc[j * 15 - 15], &
		dams4_1.xrcmfc[j * 150 - 150], &dams4_1.yrcmfc[j * 150 - 150],
		 &ie);
	if (ie > 0) {
	    goto L1500;
	}
	if (dams4_1.nzrcmfc[j - 1] == 0) {
	    goto L151;
	}
    }
L151:
    i__2 = s_rsue(&io___160);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams4_1.nrcf, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams4_1.nrcf > 3) {
	goto L1500;
    }
    i__2 = s_rsue(&io___161);
    if (i__2 != 0) {
	goto L1500;
    }
    i__3 = dams4_1.nrcf;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams4_1.rcclnf[i__ - 1], (ftnlen)sizeof(
		real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = dams4_1.nrcf;
    for (ir = 1; ir <= i__2; ++ir) {
	datgraf2_(&c__15, &c__500, &c__9, &dams4_1.npmclnf[ir - 1], &
		dams4_1.grclnf[ir - 1], &dams4_1.nzclnf[ir - 1], &
		dams4_1.zclnf[ir * 9 - 9], &dams4_1.nclnf[ir * 9 - 9], &
		dams4_1.xclnf[ir * 500 - 500], &dams4_1.yclnf[ir * 500 - 500],
		 &ie);
	if (ie > 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___162);
	if (i__3 != 0) {
	    goto L1500;
	}
	for (i__ = 1; i__ <= 15; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dams4_1.pclnfc[i__ + ir * 15 - 16], 
		    (ftnlen)sizeof(integer));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	for (j = 1; j <= 5; ++j) {
	    datgraf2_(&c__15, &c__150, &c__15, &dams4_1.npmclnfc[j + ir * 15 
		    - 16], &dams4_1.grclnfc[j + ir * 15 - 16], &
		    dams4_1.nzclnfc[j + ir * 15 - 16], &dams4_1.zclnfc[(j + 
		    ir * 15) * 15 - 240], &dams4_1.nclnfc[(j + ir * 15) * 15 
		    - 240], &dams4_1.xclnfc[(j + ir * 15) * 150 - 2400], &
		    dams4_1.yclnfc[(j + ir * 15) * 150 - 2400], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    if (dams4_1.nzclnfc[j + ir * 15 - 16] == 0) {
		goto L161;
	    }
	}
L161:
	datgraf1_(&c__15, &c__9, &dams4_1.grdhf[ir - 1], &dams4_1.ndhf[ir - 1]
		, &dams4_1.xtdhf[ir * 9 - 9], &dams4_1.yhdhf[ir * 9 - 9], &ie)
		;
	if (ie > 0) {
	    goto L1500;
	}
    }
    i__2 = s_rsue(&io___163);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams5_1.cley, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams5_1.cley > 12) {
	goto L1500;
    }
    i__2 = dams5_1.cley;
    for (il = 1; il <= i__2; ++il) {
	i__3 = s_rsue(&io___164);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams5_1.cinop[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___165);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams5_1.ncisa[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	if (dams5_1.ncisa[il - 1] > 9) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___166);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__4 = dams5_1.ncisa[il - 1];
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dams5_1.cisa[i__ + il * 9 - 10], (
		    ftnlen)sizeof(real));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	j1 = 1;
	k1 = 1;
	j2 = 1;
	k2 = 1;
	j3 = 1;
	k3 = 1;
	i__3 = dams5_1.ncisa[il - 1];
	for (is = 1; is <= i__3; ++is) {
	    datgraf2_(&c__15, &c__1500, &c__15, &dams5_1.npmcff[is + il * 9 - 
		    10], &dams5_1.grcff[is + il * 9 - 10], &dams5_1.nzcff[is 
		    + il * 9 - 10], &dams5_1.zcff[k1 + il * 150 - 151], &
		    dams5_1.ncff[k1 + il * 150 - 151], &dams5_1.xcff[j1 + il *
		     4000 - 4001], &dams5_1.ycff[j1 + il * 4000 - 4001], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j1 += dams5_1.npmcff[is + il * 9 - 10];
	    k1 += dams5_1.nzcff[is + il * 9 - 10];
	    datgraf2_(&c__15, &c__1500, &c__15, &dams5_1.npmcve[is + il * 9 - 
		    10], &dams5_1.grcve[is + il * 9 - 10], &dams5_1.nzcve[is 
		    + il * 9 - 10], &dams5_1.zcve[k2 + il * 150 - 151], &
		    dams5_1.ncve[k2 + il * 150 - 151], &dams5_1.xcve[j2 + il *
		     4000 - 4001], &dams5_1.ycve[j2 + il * 4000 - 4001], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j2 += dams5_1.npmcve[is + il * 9 - 10];
	    k2 += dams5_1.nzcve[is + il * 9 - 10];
	    datgraf2_(&c__15, &c__1500, &c__15, &dams6_1.npmctq[is + il * 9 - 
		    10], &dams6_1.grctq[is + il * 9 - 10], &dams6_1.nzctq[is 
		    + il * 9 - 10], &dams6_1.zctq[k3 + il * 150 - 151], &
		    dams6_1.nctq[k3 + il * 150 - 151], &dams6_1.xctq[j3 + il *
		     4000 - 4001], &dams6_1.yctq[j3 + il * 4000 - 4001], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j3 += dams6_1.npmctq[is + il * 9 - 10];
	    k3 += dams6_1.nzctq[is + il * 9 - 10];
	}
	if (j1 > 4000) {
	    goto L1500;
	}
	if (k1 > 150) {
	    goto L1500;
	}
	if (j2 > 4000) {
	    goto L1500;
	}
	if (k2 > 150) {
	    goto L1500;
	}
	if (j3 > 4000) {
	    goto L1500;
	}
	if (k3 > 150) {
	    goto L1500;
	}
	datgraf2_(&c__15, &c__60, &c__12, &dams6_1.npmnp[il - 1], &
		dams6_1.grnp[il - 1], &dams6_1.nznp[il - 1], &dams6_1.ztnp[il 
		* 9 - 9], &dams6_1.nnp[il * 9 - 9], &dams6_1.xhnp[il * 60 - 
		60], &dams6_1.ynp[il * 60 - 60], &ie);
	if (ie > 0) {
	    goto L1500;
	}
	cont = 0;
	for (j = 1; j <= 5; ++j) {
	    i__3 = s_rsue(&io___167);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams6_1.cpc[j + (i__ + (il << 2)
			) * 5 - 26], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 2; i__ <= 4; ++i__) {
		if (dams6_1.cpc[j + (i__ + (il << 2)) * 5 - 26] < -100.f) {
		    if (dams6_1.cpc[j + (i__ + (il << 2)) * 5 - 26] == 
			    dams6_1.cpc[j + (i__ - 1 + (il << 2)) * 5 - 26]) {
			cont = cont;
		    } else {
			++cont;
		    }
		}
	    }
	    if (dams6_1.cpc[j + ((il << 2) + 1) * 5 - 26] == 0.f) {
		goto L170;
	    }
	}
L170:
	i__3 = cont;
	for (j = 1; j <= i__3; ++j) {
	    datgraf2_(&c__15, &c__50, &c__12, &dams6_1.npmcc[j + il * 10 - 11]
		    , &dams6_1.grcc[j + il * 10 - 11], &dams6_1.nzcc[j + il * 
		    10 - 11], &dams6_1.zcc[(j + il * 10) * 5 - 55], &
		    dams6_1.ncc[(j + il * 10) * 5 - 55], &dams6_1.xcc[(j + il 
		    * 10) * 50 - 550], &dams6_1.ycc[(j + il * 10) * 50 - 550],
		     &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
    }
    i__2 = s_rsue(&io___168);
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = do_uio(&c__1, (char *)&dams7_1.dley, (ftnlen)sizeof(integer));
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    if (dams7_1.dley > 12) {
	goto L1500;
    }
    i__2 = dams7_1.dley;
    for (il = 1; il <= i__2; ++il) {
	i__3 = s_rsue(&io___169);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams7_1.dinop[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___170);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = do_uio(&c__1, (char *)&dams7_1.ndisa[il - 1], (ftnlen)sizeof(
		integer));
	if (i__3 != 0) {
	    goto L1500;
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	if (dams7_1.ndisa[il - 1] > 9) {
	    goto L1500;
	}
	i__3 = s_rsue(&io___171);
	if (i__3 != 0) {
	    goto L1500;
	}
	i__4 = dams7_1.ndisa[il - 1];
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__3 = do_uio(&c__1, (char *)&dams7_1.disa[i__ + il * 9 - 10], (
		    ftnlen)sizeof(real));
	    if (i__3 != 0) {
		goto L1500;
	    }
	}
	i__3 = e_rsue();
	if (i__3 != 0) {
	    goto L1500;
	}
	j1 = 1;
	k1 = 1;
	j2 = 1;
	k2 = 1;
	j3 = 1;
	k3 = 1;
	i__3 = dams7_1.ndisa[il - 1];
	for (is = 1; is <= i__3; ++is) {
	    datgraf2_(&c__15, &c__1500, &c__50, &dams7_1.npmdfu[is + il * 9 - 
		    10], &dams7_1.grdfu[is + il * 9 - 10], &dams7_1.nzdfu[is 
		    + il * 9 - 10], &dams7_1.zdfu[k1 + il * 50 - 51], &
		    dams7_1.ndfu[k1 + il * 50 - 51], &dams7_1.xdfu[j1 + il * 
		    1500 - 1501], &dams7_1.ydfu[j1 + il * 1500 - 1501], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j1 += dams7_1.npmdfu[is + il * 9 - 10];
	    k1 += dams7_1.nzdfu[is + il * 9 - 10];
	    datgraf2_(&c__15, &c__1500, &c__50, &dams7_1.npmdti[is + il * 9 - 
		    10], &dams7_1.grdti[is + il * 9 - 10], &dams7_1.nzdti[is 
		    + il * 9 - 10], &dams7_1.zdti[k2 + il * 50 - 51], &
		    dams7_1.ndti[k2 + il * 50 - 51], &dams7_1.xdti[j2 + il * 
		    1500 - 1501], &dams7_1.ydti[j2 + il * 1500 - 1501], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j2 += dams7_1.npmdti[is + il * 9 - 10];
	    k2 += dams7_1.nzdti[is + il * 9 - 10];
	    datgraf2_(&c__15, &c__1500, &c__50, &dams7_1.npmddi[is + il * 9 - 
		    10], &dams7_1.grddi[is + il * 9 - 10], &dams7_1.nzddi[is 
		    + il * 9 - 10], &dams7_1.zddi[k3 + il * 50 - 51], &
		    dams7_1.nddi[k3 + il * 50 - 51], &dams7_1.xddi[j3 + il * 
		    1500 - 1501], &dams7_1.yddi[j3 + il * 1500 - 1501], &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	    j3 += dams7_1.npmddi[is + il * 9 - 10];
	    k3 += dams7_1.nzddi[is + il * 9 - 10];
	}
	if (j1 > 1500) {
	    goto L1500;
	}
	if (k1 > 51) {
	    goto L1500;
	}
	if (j2 > 1500) {
	    goto L1500;
	}
	if (k2 > 51) {
	    goto L1500;
	}
	if (j3 > 1500) {
	    goto L1500;
	}
	if (k3 > 51) {
	    goto L1500;
	}
	datgraf1_(&c__15, &c__35, &dams7_1.grdv[il - 1], &dams7_1.ndv[il - 1],
		 &dams7_1.xsdv[il * 50 - 50], &dams7_1.yhdv[il * 50 - 50], &
		ie);
	if (ie > 0) {
	    goto L1500;
	}
	cont = 0;
	for (j = 1; j <= 5; ++j) {
	    i__3 = s_rsue(&io___172);
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 1; i__ <= 4; ++i__) {
		i__3 = do_uio(&c__1, (char *)&dams7_1.dpc[j + (i__ + (il << 2)
			) * 5 - 26], (ftnlen)sizeof(real));
		if (i__3 != 0) {
		    goto L1500;
		}
	    }
	    i__3 = e_rsue();
	    if (i__3 != 0) {
		goto L1500;
	    }
	    for (i__ = 2; i__ <= 4; ++i__) {
		if (dams7_1.dpc[j + (i__ + (il << 2)) * 5 - 26] < -100.f) {
		    ++cont;
		}
	    }
	    if (dams7_1.dpc[j + ((il << 2) + 1) * 5 - 26] == 0.f) {
		goto L180;
	    }
	}
L180:
	i__3 = cont;
	for (j = 1; j <= i__3; ++j) {
	    datgraf2_(&c__15, &c__30, &c__12, &dams7_1.npmdc[j + il * 10 - 11]
		    , &dams7_1.grdc[j + il * 10 - 11], &dams7_1.nzdc[j + il * 
		    10 - 11], &dams7_1.zdc[(j + il * 10) * 9 - 99], &
		    dams7_1.ndc[(j + il * 10) * 9 - 99], &dams7_1.xdc[(j + il 
		    * 10) * 30 - 330], &dams7_1.ydc[(j + il * 10) * 30 - 330],
		     &ie);
	    if (ie > 0) {
		goto L1500;
	    }
	}
    }
    i__2 = s_rsue(&io___173);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams8_1.fuel_f__[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___174);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams8_1.time_0__[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___175);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams8_1.time_h__[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___176);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams8_1.dist_0__[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    i__2 = s_rsue(&io___177);
    if (i__2 != 0) {
	goto L1500;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	i__2 = do_uio(&c__1, (char *)&dams8_1.dist_h__[i__ - 1], (ftnlen)
		sizeof(real));
	if (i__2 != 0) {
	    goto L1500;
	}
    }
    i__2 = e_rsue();
    if (i__2 != 0) {
	goto L1500;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 15;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L1500:
    *ier = 420;
    return 0;
} /* lectm_ */

/* Subroutine */ int datgraf1_(integer *uni, integer *mx, integer *grint, 
	integer *npcur, real *xpu, real *ypu, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___178 = { 1, 0, 0, 0, 0 };
    static cilist io___179 = { 1, 0, 0, 0, 0 };
    static cilist io___180 = { 1, 0, 0, 0, 0 };
    static cilist io___182 = { 1, 0, 0, 0, 0 };


    /* Parameter adjustments */
    --ypu;
    --xpu;

    /* Function Body */
    *ier = 0;
    io___178.ciunit = *uni;
    i__1 = s_rsue(&io___178);
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = do_uio(&c__1, (char *)&(*grint), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    io___179.ciunit = *uni;
    i__1 = s_rsue(&io___179);
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = do_uio(&c__1, (char *)&(*npcur), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    if (*npcur > *mx) {
	*ier = 1;
	return 0;
    }
    if (*npcur <= 0) {
	return 0;
    }
    io___180.ciunit = *uni;
    i__1 = s_rsue(&io___180);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *npcur;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&xpu[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    io___182.ciunit = *uni;
    i__1 = s_rsue(&io___182);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *npcur;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&ypu[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    return 0;
L1500:
    *ier = 1;
    return 0;
} /* datgraf1_ */

/* Subroutine */ int datgraf2_(integer *uni, integer *mx, integer *mz, 
	integer *nx, integer *grint, integer *nz, real *zcur, integer *npcur, 
	real *xpu, real *ypu, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__, k;

    /* Fortran I/O blocks */
    static cilist io___183 = { 1, 0, 0, 0, 0 };
    static cilist io___184 = { 1, 0, 0, 0, 0 };
    static cilist io___185 = { 1, 0, 0, 0, 0 };
    static cilist io___187 = { 1, 0, 0, 0, 0 };
    static cilist io___189 = { 1, 0, 0, 0, 0 };
    static cilist io___190 = { 1, 0, 0, 0, 0 };


    /* Parameter adjustments */
    --ypu;
    --xpu;
    --npcur;
    --zcur;

    /* Function Body */
    *ier = 0;
    io___183.ciunit = *uni;
    i__1 = s_rsue(&io___183);
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = do_uio(&c__1, (char *)&(*grint), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    io___184.ciunit = *uni;
    i__1 = s_rsue(&io___184);
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = do_uio(&c__1, (char *)&(*nz), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    if (*nz > *mz) {
	*ier = 1;
	return 0;
    }
    if (*nz <= 0) {
	return 0;
    }
    io___185.ciunit = *uni;
    i__1 = s_rsue(&io___185);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *nz;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&zcur[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    io___187.ciunit = *uni;
    i__1 = s_rsue(&io___187);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *nz;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&npcur[i__], (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    *nx = npcur[1];
    i__1 = *nz;
    for (k = 2; k <= i__1; ++k) {
	*nx += npcur[k];
    }
    if (*nx > *mx) {
	*ier = 1;
	return 0;
    }
    io___189.ciunit = *uni;
    i__1 = s_rsue(&io___189);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *nx;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&xpu[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    io___190.ciunit = *uni;
    i__1 = s_rsue(&io___190);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *nx;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&ypu[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    return 0;
L1500:
    *ier = 1;
    return 0;
} /* datgraf2_ */

/* Subroutine */ int datgraf3_(integer *uni, integer *mx, integer *grint, 
	integer *npcur, real *ypu, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___191 = { 1, 0, 0, 0, 0 };
    static cilist io___192 = { 1, 0, 0, 0, 0 };


    /* Parameter adjustments */
    --ypu;

    /* Function Body */
    *ier = 0;
    io___191.ciunit = *uni;
    i__1 = s_rsue(&io___191);
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = do_uio(&c__1, (char *)&(*grint), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L1500;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    if (*npcur > *mx) {
	*ier = 1;
	return 0;
    }
    if (*npcur <= 0) {
	return 0;
    }
    io___192.ciunit = *uni;
    i__1 = s_rsue(&io___192);
    if (i__1 != 0) {
	goto L1500;
    }
    i__2 = *npcur;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&ypu[i__], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L1500;
	}
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L1500;
    }
    return 0;
L1500:
    *ier = 1;
    return 0;
} /* datgraf3_ */

