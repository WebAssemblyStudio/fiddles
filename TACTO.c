/* TACTO.F -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__100 = 100;
static integer c__15 = 15;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__5 = 5;
static real c_b47 = 0.f;
static real c_b66 = 50.f;
static integer c__300 = 300;
static integer c__25 = 25;

/* Subroutine */ int tacto_(char *vic, char *vid, integer *vii, real *vir, 
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
    static integer i__, verc, cifsig, itemax, mxgrc, ie, mzgrc, mxtdc, mztdc;
    static real togrc, oatc, wxmin, error, dairc, vrxwind, mxwind;
    extern /* Subroutine */ int lectg_(char *, integer *, ftnlen), lecto_(
	    char *, integer *, ftnlen), init_(integer *, integer *, integer *,
	     integer *, real *, integer *, real *, integer *), manual2r_(
	    integer *, real *, real *, real *, integer *, integer *, real *, 
	    integer *), manual3r_(integer *, integer *, real *, real *, real *
	    , integer *, integer *, real *, real *, real *, integer *), corr_(
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *), vrspeed_(real *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    , integer *, integer *, real *, real *, real *, integer *, 
	    integer *, real *, real *), tospeed_(real *, real *, real *, real 
	    *, real *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *, integer *, real *, real *, integer *, 
	    real *, integer *, real *, integer *, real *, real *, real *, 
	    real *), zfalse_(E_fp, real *, integer *, real *, real *, real *, 
	    integer *, integer *), fpath_(integer *, real *, real *, real *, 
	    real *, real *, real *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, integer *, real *
	    , integer *, real *, integer *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *, real *, integer *
	    , real *, integer *, real *, integer *, real *, integer *, real *,
	     integer *, real *, real *, integer *), escrit_(integer *, real *,
	     integer *, integer *, integer *, integer *);
    static real vl1, vl2;
    static char vici[200];
    extern doublereal difobst_(real *);

/* MS$ATTRIBUTES DLLEXPORT :: TACTO */
/* MS$ATTRIBUTES ALIAS: 'TACTO' :: TACTO */
/*      POINTER(VIC,VIC) */
/*      POINTER(VID,VID) */
    /* Parameter adjustments */
    --vor;
    --voi;
    --vir;
    --vii;

    /* Function Body */
    mxtdc = 150;
    mxgrc = 150;
    mztdc = 15;
    mzgrc = 20;
    resto_1.mil = 2;
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
	    afm_1.afm, afm_1.afm_tac__, (ftnlen)6, (ftnlen)6) != 0) {
	lecto_(vici, ierr, (ftnlen)200);
	if (*ierr > 0) {
	    return 0;
	}
    }
    init_(&c__1, &resto_1.mil, dato6_1.nsen, &vii[1], &vir[1], &voi[1], &vor[
	    1], ierr);
    if (*ierr > 0) {
	return 0;
    }
    verc = 100;
    ie = 0;
    oatc = ini2_1.oat1;
    if (ini1_1.system[1] == 1) {
	manual2r_(&c__1, &ini2_1.oat1, &dato5_1.xtvti[(ini2_1.ifl << 4) - 16],
		 &dato5_1.ytvti[(ini2_1.ifl << 4) - 16], &dato5_1.grvti[
		ini2_1.ifl - 1], &dato5_1.nvti[ini2_1.ifl - 1], &oatc, &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__1, &dato5_1.grvt[ini2_1.ifl - 1], &dato5_1.xtvt[ini2_1.ifl *
	     500 - 500], &dato5_1.ysvt[ini2_1.ifl * 500 - 500], &dato5_1.zhvt[
	    ini2_1.ifl * 20 - 20], &dato5_1.nvt[ini2_1.ifl * 20 - 20], &
	    dato5_1.nzvt[ini2_1.ifl - 1], &oatc, &resto_1.vrot1, &ini1_1.hp, &
	    ie);
    if (ie == 2) {
	goto L10000;
    }
    if (dato6_1.nsen[ini2_1.ifl - 1] != 0) {
	if (ini1_1.gs > dato6_1.xgfq[dato6_1.nfq[ini2_1.ifl - 1] + ini2_1.ifl 
		* 30 - 31]) {
	    *ierr = 270;
	    return 0;
	}
    }
    if (ini1_1.gs > 20.f) {
	corr_(&ie, &c__1, &vl1, &ini1_1.gs, ini2_1.x, &dato1_1.pgc[ini2_1.ifl 
		* 15 - 15], &c__100, &c__15, &dato1_1.grgc[(ini2_1.ifl << 2) 
		- 4], &dato1_1.nzgc[(ini2_1.ifl << 2) - 4], &dato1_1.ngc[((
		ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.xgc[((ini2_1.ifl <<
		 2) + 1) * 100 - 500], &dato1_1.ygc[((ini2_1.ifl << 2) + 1) * 
		15 - 75], &dato1_1.zgc[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	if (ie == 2) {
	    goto L10000;
	}
	manual2r_(&c__2, &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] - 1], &
		dato1_1.xgg[ini2_1.ifl * 15 - 15], &dato1_1.ycg[ini2_1.ifl * 
		15 - 15], &dato1_1.grg[ini2_1.ifl - 1], &dato1_1.ng[
		ini2_1.ifl - 1], &vl1, &ie);
	if (ie == 1) {
	    *ierr = 270;
	    return 0;
	}
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 1] - 1] = ini1_1.gs;
    } else {
	manual2r_(&c__1, &ini1_1.gs, &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[ini2_1.ifl - 
		1], &dato1_1.ng[ini2_1.ifl - 1], &vl1, &ie);
	if (ie == 1) {
	    *ierr = 270;
	    return 0;
	}
	if (ie == 2) {
	    goto L10000;
	}
	corr_(&ie, &c__0, &vl1, &ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 1] - 1],
		 ini2_1.x, &dato1_1.pgc[ini2_1.ifl * 15 - 15], &c__100, &
		c__15, &dato1_1.grgc[(ini2_1.ifl << 2) - 4], &dato1_1.nzgc[(
		ini2_1.ifl << 2) - 4], &dato1_1.ngc[((ini2_1.ifl << 2) + 1) * 
		15 - 75], &dato1_1.xgc[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		dato1_1.ygc[((ini2_1.ifl << 2) + 1) * 15 - 75], &dato1_1.zgc[(
		(ini2_1.ifl << 2) + 1) * 15 - 75]);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] - 1] = ini1_1.gs;
    }
    if (dato1_1.indg2 == 1) {
	ini1_1.gs = ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] - 1];
    }
    if (dato1_1.indg2 == 2) {
	ini1_1.gs = ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 1] - 1];
    }
    oatc = ini2_1.oat1;
    ie = 0;
    if (ini1_1.system[1] != 0) {
	manual2r_(&c__1, &ini2_1.oat1, &dato1_1.xtg2i[ini2_1.ifl * 10 - 10], &
		dato1_1.ytg2i[ini2_1.ifl * 10 - 10], &dato1_1.grg2i[
		ini2_1.ifl - 1], &dato1_1.ng2i[ini2_1.ifl - 1], &oatc, &ie);
    }
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__1, &dato1_1.grg21[ini2_1.ifl - 1], &dato1_1.xtg21[
	    ini2_1.ifl * 500 - 500], &dato1_1.yg21[ini2_1.ifl * 500 - 500], &
	    dato1_1.zhg21[ini2_1.ifl * 20 - 20], &dato1_1.ng21[ini2_1.ifl * 
	    20 - 20], &dato1_1.nzg21[ini2_1.ifl - 1], &oatc, &resto_1.grad1, &
	    ini1_1.hp, &ie);
    if (ie == 2) {
	goto L10000;
    }
    manual3r_(&c__3, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
	    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 750], &
	    dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[ini2_1.ifl * 30 
	    - 30], &dato1_1.nzg22[ini2_1.ifl - 1], &vl1, &resto_1.grad1, &
	    ini1_1.gs, &ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &wxmin, ini2_1.x, &dato1_1.pg2c[ini2_1.ifl * 15 - 
	    15], &c__100, &c__15, &dato1_1.grg2c[(ini2_1.ifl << 2) - 4], &
	    dato1_1.nzg2c[(ini2_1.ifl << 2) - 4], &dato1_1.ng2c[((ini2_1.ifl 
	    << 2) + 1) * 15 - 75], &dato1_1.xg2c[((ini2_1.ifl << 2) + 1) * 
	    100 - 500], &dato1_1.yg2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
	    dato1_1.zg2c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
    if (ie == 2) {
	goto L10000;
    }
    ini2_1.ilim[0] = 6;
    if (wxmin < ini1_1.wmin) {
	*ierr = 10;
	goto L2000;
    }
    wxmin = dmin(ini1_1.emw,wxmin);
    if (wxmin == ini1_1.emw) {
	ini2_1.ilim[0] = 1;
	ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] - 1] = -999.f;
    }
    resto_1.todc = -999.f;
    manual3r_(&c__3, &dato3_1.grgr1[ini2_1.ifl - 1], &dato3_1.xdgr1[
	    ini2_1.ifl * 500 - 500], &dato3_1.ytgr1[ini2_1.ifl * 500 - 500], &
	    dato3_1.zhgr1[ini2_1.ifl * 20 - 20], &dato3_1.ngr1[ini2_1.ifl * 
	    20 - 20], &dato3_1.nzgr1[ini2_1.ifl - 1], &resto_1.togr1, &
	    ini2_1.oat2, &ini1_1.hp, &ie);
    if (ie == 2) {
	goto L10000;
    }
L500:
    manual3r_(&c__1, &dato3_1.grgr2[ini2_1.ifl - 1], &dato3_1.xdgr2[
	    ini2_1.ifl * 500 - 500], &dato3_1.ydgr2[ini2_1.ifl * 500 - 500], &
	    dato3_1.zwgr2[ini2_1.ifl * 20 - 20], &dato3_1.ngr2[ini2_1.ifl * 
	    20 - 20], &dato3_1.nzgr2[ini2_1.ifl - 1], &resto_1.togr1, &vl1, &
	    wxmin, &ie);
    if (ie == 2) {
	goto L10000;
    }
    corr_(&ie, &c__0, &vl1, &togrc, ini2_1.x2, &dato3_1.pgrc[ini2_1.ifl * 15 
	    - 15], &mxgrc, &mzgrc, &dato3_1.grgrc[ini2_1.ifl * 10 - 10], &
	    dato3_1.nzgrc[ini2_1.ifl * 10 - 10], &dato3_1.ngrc[(ini2_1.ifl * 
	    10 + 1) * 20 - 220], &dato3_1.xgrc[(ini2_1.ifl * 10 + 1) * 150 - 
	    1650], &dato3_1.ygrc[(ini2_1.ifl * 10 + 1) * 150 - 1650], &
	    dato3_1.zgrc[(ini2_1.ifl * 10 + 1) * 20 - 220]);
    if (ie == 2) {
	goto L10000;
    }
    if (togrc >= ini1_1.rwy - ini1_1.del_rwy__) {
	togrc = ini1_1.rwy - ini1_1.del_rwy__;
	ini2_1.ilim[(ini2_1.ind << 2) - 4] = 3;
	r__1 = ini1_1.rwy - ini1_1.del_rwy__;
	corr_(&ie, &c__1, &vl1, &r__1, ini2_1.x2, &dato3_1.pgrc[ini2_1.ifl * 
		15 - 15], &mxgrc, &mzgrc, &dato3_1.grgrc[ini2_1.ifl * 10 - 10]
		, &dato3_1.nzgrc[ini2_1.ifl * 10 - 10], &dato3_1.ngrc[(
		ini2_1.ifl * 10 + 1) * 20 - 220], &dato3_1.xgrc[(ini2_1.ifl * 
		10 + 1) * 150 - 1650], &dato3_1.ygrc[(ini2_1.ifl * 10 + 1) * 
		150 - 1650], &dato3_1.zgrc[(ini2_1.ifl * 10 + 1) * 20 - 220]);
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato3_1.grgr2[ini2_1.ifl - 1], &dato3_1.xdgr2[
		ini2_1.ifl * 500 - 500], &dato3_1.ydgr2[ini2_1.ifl * 500 - 
		500], &dato3_1.zwgr2[ini2_1.ifl * 20 - 20], &dato3_1.ngr2[
		ini2_1.ifl * 20 - 20], &dato3_1.nzgr2[ini2_1.ifl - 1], &
		resto_1.togr1, &vl1, &wxmin, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (wxmin < ini1_1.wmin) {
	    *ierr = 10;
	    if (ini2_1.ind == 2) {
		*ierr = 550;
		return 0;
	    }
	    goto L2000;
	}
	ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + ini2_1.ind * 3 - 4] = 
		-999.f;
    }
    ini2_1.tor[ini2_1.ind * 3 - 3] = togrc;
    if (ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + ini2_1.ind * 3 - 4] == 
	    -999.f) {
	corr_(&ie, &c__1, &vl1, &wxmin, ini2_1.x, &dato1_1.pg2c[ini2_1.ifl * 
		15 - 15], &c__100, &c__15, &dato1_1.grg2c[(ini2_1.ifl << 2) - 
		4], &dato1_1.nzg2c[(ini2_1.ifl << 2) - 4], &dato1_1.ng2c[((
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
		    vl1, &resto_1.grad1, &ini2_1.grad[dagen3_1.segm[
		    ini2_1.ifl - 1] + ini2_1.ind * 3 - 4], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual2r_(&c__1, &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + 
		    ini2_1.ind * 3 - 4], &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		    dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[
		    ini2_1.ifl - 1], &dato1_1.ng[ini2_1.ifl - 1], &vl2, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl2, &ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 1] 
		    + ini2_1.ind * 3 - 4], ini2_1.x, &dato1_1.pgc[ini2_1.ifl *
		     15 - 15], &c__100, &c__15, &dato1_1.grgc[(ini2_1.ifl << 
		    2) - 4], &dato1_1.nzgc[(ini2_1.ifl << 2) - 4], &
		    dato1_1.ngc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.xgc[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.ygc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.zgc[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    manual3r_(&c__5, &dato1_1.grg22[ini2_1.ifl - 1], &dato1_1.xwg22[
		    ini2_1.ifl * 750 - 750], &dato1_1.yg22[ini2_1.ifl * 750 - 
		    750], &dato1_1.zg22[ini2_1.ifl * 30 - 30], &dato1_1.ng22[
		    ini2_1.ifl * 30 - 30], &dato1_1.nzg22[ini2_1.ifl - 1], &
		    vl1, &resto_1.grad1, &ini2_1.rc[dagen3_1.segm[ini2_1.ifl 
		    - 1] + ini2_1.ind * 3 - 4], &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__1, &vl2, &ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 1] 
		    + ini2_1.ind * 3 - 4], ini2_1.x, &dato1_1.pgc[ini2_1.ifl *
		     15 - 15], &c__100, &c__15, &dato1_1.grgc[(ini2_1.ifl << 
		    2) - 4], &dato1_1.nzgc[(ini2_1.ifl << 2) - 4], &
		    dato1_1.ngc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.xgc[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.ygc[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.zgc[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual2r_(&c__2, &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + 
		    ini2_1.ind * 3 - 4], &dato1_1.xgg[ini2_1.ifl * 15 - 15], &
		    dato1_1.ycg[ini2_1.ifl * 15 - 15], &dato1_1.grg[
		    ini2_1.ifl - 1], &dato1_1.ng[ini2_1.ifl - 1], &vl2, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	}
    }
    if (dagen3_1.segm[ini2_1.ifl - 1] != 1) {
	corr_(&ie, &c__0, &dato1_1.dgrs1[ini2_1.ifl - 1], &vl1, ini2_1.x, &
		dato1_1.pdgrs1c[ini2_1.ifl * 15 - 15], &c__100, &c__15, &
		dato1_1.grdgrs1c[(ini2_1.ifl << 2) - 4], &dato1_1.nzdgrs1c[(
		ini2_1.ifl << 2) - 4], &dato1_1.ndgrs1c[((ini2_1.ifl << 2) + 
		1) * 15 - 75], &dato1_1.xdgrs1c[((ini2_1.ifl << 2) + 1) * 100 
		- 500], &dato1_1.ydgrs1c[((ini2_1.ifl << 2) + 1) * 100 - 500],
		 &dato1_1.zdgrs1c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.grad[ini2_1.ind * 3 - 3] = ini2_1.grad[dagen3_1.segm[
		ini2_1.ifl - 1] + ini2_1.ind * 3 - 4] + vl1;
	corr_(&ie, &c__0, &dato1_1.drcs1[ini2_1.ifl - 1], &vl1, ini2_1.x, &
		dato1_1.pdrcs1c[ini2_1.ifl * 15 - 15], &c__100, &c__15, &
		dato1_1.grdrcs1c[(ini2_1.ifl << 2) - 4], &dato1_1.nzdrcs1c[(
		ini2_1.ifl << 2) - 4], &dato1_1.ndrcs1c[((ini2_1.ifl << 2) + 
		1) * 15 - 75], &dato1_1.xdrcs1c[((ini2_1.ifl << 2) + 1) * 100 
		- 500], &dato1_1.ydrcs1c[((ini2_1.ifl << 2) + 1) * 100 - 500],
		 &dato1_1.zdrcs1c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.rc[ini2_1.ind * 3 - 3] = ini2_1.rc[dagen3_1.segm[ini2_1.ifl - 
		1] + ini2_1.ind * 3 - 4] + vl1;
    }
    vrspeed_(&resto_1.vrot1, &c_b47, &wxmin, &ini2_1.vr[ini2_1.ind - 1], &ie, 
	    &dato5_1.grvro1[ini2_1.ifl - 1], &dato5_1.nzvro1[ini2_1.ifl - 1], 
	    &dato5_1.nvro1[ini2_1.ifl * 15 - 15], &dato5_1.zwvro1[ini2_1.ifl *
	     15 - 15], &dato5_1.xsvro1[ini2_1.ifl * 500 - 500], &
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
    tospeed_(&resto_1.vrot1, &wxmin, &ini2_1.v2[ini2_1.ind - 1], &
	    ini2_1.vfret[(ini2_1.ind << 1) - 2], &ini2_1.vfto[ini2_1.ind - 1],
	     &ie, &dato5_1.grv21[ini2_1.ifl - 1], &dato5_1.nzv21[ini2_1.ifl - 
	    1], &dato5_1.nv21[ini2_1.ifl * 15 - 15], &dato5_1.zwv21[
	    ini2_1.ifl * 15 - 15], &dato5_1.xsv21[ini2_1.ifl * 500 - 500], &
	    dato5_1.ysv21[ini2_1.ifl * 500 - 500], &dato5_1.grv22[ini2_1.ifl 
	    - 1], &dato5_1.nv22[ini2_1.ifl - 1], &dato5_1.xwv22[ini2_1.ifl * 
	    50 - 50], &dato5_1.ysv22[ini2_1.ifl * 50 - 50], &dato5_1.grvrf1[
	    ini2_1.ifl - 1], &dato5_1.ysvrf1[(ini2_1.ifl << 4) - 16], &
	    dato5_1.grvrf2[ini2_1.ifl - 1], &dato5_1.ysvrf2[(ini2_1.ifl << 4) 
	    - 16], &dato5_1.grvfto[ini2_1.ifl - 1], &dato5_1.ysvfto[(
	    ini2_1.ifl << 4) - 16], &dato5_1.dvrf1[ini2_1.ifl - 1], &
	    dato5_1.dvrf2[ini2_1.ifl - 1], &dato5_1.dvfto[ini2_1.ifl - 1]);
    if (ie == 2) {
	goto L10000;
    }
    ini2_1.fret[ini2_1.ind - 1] = dato5_1.dfret[ini2_1.ifl - 1];
    if (resto_1.todc == -999.f) {
	if (dato3_1.nzda1[ini2_1.ifl - 1] == 0) {
	    manual3r_(&c__3, &dato3_1.grtd1[ini2_1.ifl - 1], &dato3_1.xdtd1[
		    ini2_1.ifl * 500 - 500], &dato3_1.yttd1[ini2_1.ifl * 500 
		    - 500], &dato3_1.zhtd1[ini2_1.ifl * 20 - 20], &
		    dato3_1.ntd1[ini2_1.ifl * 20 - 20], &dato3_1.nztd1[
		    ini2_1.ifl - 1], &resto_1.tod1, &ini2_1.oat2, &ini1_1.hp, 
		    &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    manual3r_(&c__1, &dato3_1.grtd2[ini2_1.ifl - 1], &dato3_1.xdtd2[
		    ini2_1.ifl * 500 - 500], &dato3_1.ydtd2[ini2_1.ifl * 500 
		    - 500], &dato3_1.zwtd2[ini2_1.ifl * 20 - 20], &
		    dato3_1.ntd2[ini2_1.ifl * 20 - 20], &dato3_1.nztd2[
		    ini2_1.ifl - 1], &resto_1.tod1, &vl1, &wxmin, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl1, &resto_1.todc, ini2_1.x2, &dato3_1.ptdc[
		    ini2_1.ifl * 15 - 15], &mxtdc, &mztdc, &dato3_1.grtdc[(
		    ini2_1.ifl << 3) - 8], &dato3_1.nztdc[(ini2_1.ifl << 3) - 
		    8], &dato3_1.ntdc[((ini2_1.ifl << 3) + 1) * 15 - 135], &
		    dato3_1.xtdc[((ini2_1.ifl << 3) + 1) * 150 - 1350], &
		    dato3_1.ytdc[((ini2_1.ifl << 3) + 1) * 150 - 1350], &
		    dato3_1.ztdc[((ini2_1.ifl << 3) + 1) * 15 - 135]);
	    if (ie == 2) {
		goto L10000;
	    }
	} else {
	    r__1 = (real) ini1_1.flaps;
	    manual3r_(&c__1, &dato3_1.grda1[ini2_1.ifl - 1], &dato3_1.xgda1[
		    ini2_1.ifl * 200 - 200], &dato3_1.ydda1[ini2_1.ifl * 200 
		    - 200], &dato3_1.zfda1[ini2_1.ifl * 10 - 10], &
		    dato3_1.nda1[ini2_1.ifl * 10 - 10], &dato3_1.nzda1[
		    ini2_1.ifl - 1], &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 
		    1] + ini2_1.ind * 3 - 4], &vl1, &r__1, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    corr_(&ie, &c__0, &vl1, &dairc, ini2_1.x, &dato3_1.pda1c[
		    ini2_1.ifl * 15 - 15], &c__100, &c__15, &dato3_1.grda1c[(
		    ini2_1.ifl << 2) - 4], &dato3_1.nzda1c[(ini2_1.ifl << 2) 
		    - 4], &dato3_1.nda1c[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato3_1.xda1c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato3_1.yda1c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato3_1.zda1c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	    if (ie == 2) {
		goto L10000;
	    }
	    resto_1.todc = togrc + dairc;
	}
    }
    ini2_1.tod[ini2_1.ind * 3 - 3] = resto_1.todc;
L1000:
    if (ini2_1.iobs[ini2_1.ind - 1] == 0) {
	ini2_1.iobs[ini2_1.ind - 1] = 1;
	if (ini1_1.nobs + ini1_1.nobp <= 0) {
	    goto L1000;
	}
	if (difobst_(&wxmin) > 0.f) {
	    goto L1000;
	}
	if (resto_1.ierd > 0) {
	    goto L10000;
	}
	if (ini2_1.ind == 2) {
	    ini2_1.ilim[(ini2_1.ind << 2) - 4] = resto_1.obs_crit__;
	    *ierr = 550;
	    return 0;
	}
	error = .01f;
	cifsig = 6;
	itemax = 100;
	zfalse_((E_fp)difobst_, &error, &cifsig, &ini1_1.wmin, &wxmin, &vl1, &
		itemax, &ie);
	if (resto_1.ierd > 0) {
	    goto L10000;
	}
	if (ie == 129) {
	    ini2_1.ilim[(ini2_1.ind << 2) - 4] = resto_1.obs_crit__;
	    *ierr = 10;
	    goto L2000;
	}
	if (ie > 0) {
	    *ierr = 520;
	    return 0;
	}
	wxmin = vl1;
	ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + ini2_1.ind * 3 - 4] = 
		-999.f;
	ini2_1.ilim[(ini2_1.ind << 2) - 4] = resto_1.obs_crit__;
	goto L500;
    }
    if (ini2_1.nfp[ini2_1.ind - 1] < 0 && dato6_1.nsen[ini2_1.ifl - 1] > 0) {
	oatc = ini2_1.oat1;
	if ((real) ini1_1.system[1] != 0.f) {
	    manual2r_(&c__1, &ini2_1.oat1, &dato1_1.xtw2i[ini2_1.ifl * 10 - 
		    10], &dato1_1.ytw2i[ini2_1.ifl * 10 - 10], &dato1_1.grw2i[
		    ini2_1.ifl - 1], &dato1_1.nw2i[ini2_1.ifl - 1], &oatc, &
		    ie);
	}
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__3, &dato1_1.grw21[ini2_1.ifl - 1], &dato1_1.xww21[
		ini2_1.ifl * 500 - 500], &dato1_1.ytw21[ini2_1.ifl * 500 - 
		500], &dato1_1.zhw21[ini2_1.ifl * 20 - 20], &dato1_1.nw21[
		ini2_1.ifl * 20 - 20], &dato1_1.nzw21[ini2_1.ifl - 1], &vl1, &
		oatc, &ini1_1.hp, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (dato1_1.igam == 1) {
	    corr_(&ie, &c__1, &vl2, &wxmin, ini2_1.x, &dato1_1.pw2c[
		    ini2_1.ifl * 15 - 15], &c__100, &c__15, &dato1_1.grw2c[(
		    ini2_1.ifl << 2) - 4], &dato1_1.nzw2c[(ini2_1.ifl << 2) - 
		    4], &dato1_1.nw2c[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.xw2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.yw2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.zw2c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	} else if (dato1_1.igam == 2) {
	    corr_(&ie, &c__1, &vl2, &wxmin, ini2_1.x2, &dato1_1.pw2c[
		    ini2_1.ifl * 15 - 15], &c__100, &c__15, &dato1_1.grw2c[(
		    ini2_1.ifl << 2) - 4], &dato1_1.nzw2c[(ini2_1.ifl << 2) - 
		    4], &dato1_1.nw2c[((ini2_1.ifl << 2) + 1) * 15 - 75], &
		    dato1_1.xw2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.yw2c[((ini2_1.ifl << 2) + 1) * 100 - 500], &
		    dato1_1.zw2c[((ini2_1.ifl << 2) + 1) * 15 - 75]);
	}
	if (ie == 2) {
	    goto L10000;
	}
	manual3r_(&c__2, &dato1_1.grw22[ini2_1.ifl - 1], &dato1_1.xww22[
		ini2_1.ifl * 300 - 300], &dato1_1.yww22[ini2_1.ifl * 300 - 
		300], &dato1_1.zgw22[ini2_1.ifl * 30 - 30], &dato1_1.nw22[
		ini2_1.ifl * 30 - 30], &dato1_1.nzw22[ini2_1.ifl - 1], &vl1, &
		vl2, &resto_1.gradc, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.senda[ini2_1.ind - 1] = 1;
	fpath_(&c__1, &ini2_1.x[5], &resto_1.gradc, &c_b66, &dato6_1.xdfp1[
		ini2_1.ifl * 1500 - 1500], &dato6_1.yhfp1[ini2_1.ifl * 1500 - 
		1500], &dato6_1.zgfp1[ini2_1.ifl * 100 - 100], &dato6_1.grfp1[
		ini2_1.ifl - 1], &dato6_1.nfp1[ini2_1.ifl * 100 - 100], &
		dato6_1.nzfp1[ini2_1.ifl - 1], &dato6_1.xdfp2[ini2_1.ifl * 
		500 - 500], &dato6_1.yvfp2[ini2_1.ifl * 500 - 500], &
		dato6_1.zdfp2[ini2_1.ifl * 60 - 60], &dato6_1.grfp2[
		ini2_1.ifl - 1], &dato6_1.nfp2[ini2_1.ifl * 60 - 60], &
		dato6_1.nzfp2[ini2_1.ifl - 1], &dato6_1.nfq[ini2_1.ifl - 1], &
		dato6_1.xgfq[ini2_1.ifl * 30 - 30], &dato6_1.grfq0[ini2_1.ifl 
		- 1], &dato6_1.ydfq0[ini2_1.ifl * 30 - 30], &dato6_1.grfq1[
		ini2_1.ifl - 1], &dato6_1.ydfq1[ini2_1.ifl * 30 - 30], &
		dato6_1.grfq2[ini2_1.ifl - 1], &dato6_1.ydfq2[ini2_1.ifl * 30 
		- 30], &dato6_1.grfq3[ini2_1.ifl - 1], &dato6_1.ydfq3[
		ini2_1.ifl * 30 - 30], &dato6_1.grfq4[ini2_1.ifl - 1], &
		dato6_1.ydfq4[ini2_1.ifl * 30 - 30], &dato6_1.grfq5[
		ini2_1.ifl - 1], &dato6_1.yhfq5[ini2_1.ifl * 30 - 30], &
		dato6_1.grfq6[ini2_1.ifl - 1], &dato6_1.yhfq6[ini2_1.ifl * 30 
		- 30], &dato6_1.grfq7[ini2_1.ifl - 1], &dato6_1.yhfq7[
		ini2_1.ifl * 30 - 30], &dato6_1.grfq8[ini2_1.ifl - 1], &
		dato6_1.yhfq8[ini2_1.ifl * 30 - 30], &dato6_1.grfq9[
		ini2_1.ifl - 1], &dato6_1.yhfq9[ini2_1.ifl * 30 - 30], &
		ini2_1.nfp[ini2_1.ind - 1], &ini2_1.xfp[(ini2_1.ind << 4) - 
		16], &ini2_1.hfp[(ini2_1.ind << 4) - 16], &ie);
	if (ie > 0) {
	    goto L10000;
	}
    }
    if (ini2_1.ind == 1 && ini1_1.nobs + ini1_1.nobp > 0) {
	i__1 = ini1_1.nobs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (ini1_1.hobs[i__ - 1] > ini2_1.hfp[ini2_1.nfp[ini2_1.ind - 1] 
		    + (ini2_1.ind << 4) - 17]) {
		*ierr = 160;
		return 0;
	    }
	}
	i__1 = ini1_1.nobp;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (ini1_1.hobp[i__ - 1] > ini2_1.hfp[ini2_1.nfp[ini2_1.ind - 1] 
		    + (ini2_1.ind << 4) - 17]) {
		*ierr = 160;
		return 0;
	    }
	}
    }
    if (ini2_1.senda[ini2_1.ind - 1] == 1) {
	manual2r_(&c__1, &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + 
		ini2_1.ind * 3 - 4], &dato6_1.xgac[ini2_1.ifl * 30 - 30], &
		dato6_1.yhac[ini2_1.ifl * 30 - 30], &dato6_1.grac[ini2_1.ifl 
		- 1], &dato6_1.nac[ini2_1.ifl - 1], &vl1, &ie);
	corr_(&ie, &c__0, &vl1, &ini2_1.altacc[ini2_1.ind - 1], ini2_1.x, &
		dato6_1.pacc[ini2_1.ifl * 15 - 15], &c__300, &c__25, &
		dato6_1.gracc[(ini2_1.ifl << 2) - 4], &dato6_1.nzacc[(
		ini2_1.ifl << 2) - 4], &dato6_1.nacc[((ini2_1.ifl << 2) + 1) *
		 25 - 125], &dato6_1.xacc[((ini2_1.ifl << 2) + 1) * 300 - 
		1500], &dato6_1.yacc[((ini2_1.ifl << 2) + 1) * 300 - 1500], &
		dato6_1.zacc[((ini2_1.ifl << 2) + 1) * 25 - 125]);
	if (ie == 2) {
	    goto L10000;
	}
    } else if (ini2_1.senda[ini2_1.ind - 1] == 2) {
	manual2r_(&c__1, &ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + 
		ini2_1.ind * 3 - 4], &dato6_1.xgaca[ini2_1.ifl * 30 - 30], &
		dato6_1.yhaca[ini2_1.ifl * 30 - 30], &dato6_1.graca[
		ini2_1.ifl - 1], &dato6_1.naca[ini2_1.ifl - 1], &vl1, &ie);
	corr_(&ie, &c__0, &vl1, &ini2_1.altacc[ini2_1.ind - 1], ini2_1.x, &
		dato6_1.pacac[ini2_1.ifl * 15 - 15], &c__300, &c__25, &
		dato6_1.gracac[(ini2_1.ifl << 2) - 4], &dato6_1.nzacac[(
		ini2_1.ifl << 2) - 4], &dato6_1.nacac[((ini2_1.ifl << 2) + 1) 
		* 25 - 125], &dato6_1.xacac[((ini2_1.ifl << 2) + 1) * 300 - 
		1500], &dato6_1.yacac[((ini2_1.ifl << 2) + 1) * 300 - 1500], &
		dato6_1.zacac[((ini2_1.ifl << 2) + 1) * 25 - 125]);
	if (ie == 2) {
	    goto L10000;
	}
    }
    if (ie == 2) {
	goto L10000;
    }
    oatc = ini2_1.oat1 - ini2_1.altacc[ini2_1.ind - 1] * 1.98f / 1e3f;
    if (ini1_1.system[1] == 0) {
	r__1 = ini1_1.hp + ini2_1.altacc[ini2_1.ind - 1];
	manual3r_(&c__1, &dagen1_1.grtqm, dagen1_1.xttqm, dagen1_1.yqtqm, 
		dagen1_1.zhtqm, dagen1_1.ntqm, &dagen1_1.nztqm, &oatc, &
		ini2_1.tqmc[ini2_1.ind - 1], &r__1, &ie);
    } else {
	if (dagen1_1.nztqmi > 1) {
	    r__1 = ini1_1.hp + ini2_1.altacc[ini2_1.ind - 1];
	    manual3r_(&c__1, &dagen1_1.grtqmi, dagen1_1.xttqmi, 
		    dagen1_1.yqtqmi, dagen1_1.zhtqmi, dagen1_1.ntqmi, &
		    dagen1_1.nztqmi, &oatc, &ini2_1.tqmc[ini2_1.ind - 1], &
		    r__1, &ie);
	} else {
	    manual3r_(&c__1, &dagen1_1.grtqmi, dagen1_1.xttqmi, 
		    dagen1_1.yqtqmi, dagen1_1.zhtqmi, dagen1_1.ntqmi, &
		    dagen1_1.nztqmi, &oatc, &vl1, dagen1_1.zhtqmi, &ie);
	    if (ie == 2) {
		goto L10000;
	    }
	    r__1 = ini1_1.hp + ini2_1.altacc[ini2_1.ind - 1];
	    manual3r_(&c__1, &dagen1_1.grtqm, dagen1_1.xttqm, dagen1_1.yqtqm, 
		    dagen1_1.zhtqm, dagen1_1.ntqm, &dagen1_1.nztqm, &vl1, &
		    ini2_1.tqmc[ini2_1.ind - 1], &r__1, &ie);
	}
    }
    if (ie == 2) {
	goto L10000;
    }
    if (ini2_1.ind == 1) {
	if (ini1_1.system[1] == 0) {
	    manual3r_(&c__1, &dagen1_1.grtq, dagen1_1.xttq, dagen1_1.yqtq, 
		    dagen1_1.zhtq, dagen1_1.ntq, &dagen1_1.nztq, &ini2_1.oat1,
		     &ini2_1.tqto[ini2_1.ind - 1], &ini1_1.hp, &ie);
	} else {
	    if (dagen1_1.nztqi > 1) {
		manual3r_(&c__1, &dagen1_1.grtqi, dagen1_1.xttqi, 
			dagen1_1.yqtqi, dagen1_1.zhtqi, dagen1_1.ntqi, &
			dagen1_1.nztqi, &ini2_1.oat1, &ini2_1.tqto[ini2_1.ind 
			- 1], &ini1_1.hp, &ie);
	    } else {
		manual3r_(&c__1, &dagen1_1.grtqi, dagen1_1.xttqi, 
			dagen1_1.yqtqi, dagen1_1.zhtqi, dagen1_1.ntqi, &
			dagen1_1.nztqi, &ini2_1.oat1, &oatc, dagen1_1.zhtqi, &
			ie);
		if (ie == 2) {
		    goto L10000;
		}
		manual3r_(&c__1, &dagen1_1.grtq, dagen1_1.xttq, dagen1_1.yqtq,
			 dagen1_1.zhtq, dagen1_1.ntq, &dagen1_1.nztq, &oatc, &
			ini2_1.tqto[ini2_1.ind - 1], &ini1_1.hp, &ie);
	    }
	}
	if (ie == 2) {
	    goto L10000;
	}
	if (ini1_1.system[1] == 0) {
	    manual3r_(&c__1, &dagen1_1.grit, dagen1_1.xtit, dagen1_1.ytit, 
		    dagen1_1.zhit, dagen1_1.nit, &dagen1_1.nzit, &ini2_1.oat1,
		     &ini2_1.itt[ini2_1.ind - 1], &ini1_1.hp, &ie);
	} else {
	    manual3r_(&c__1, &dagen1_1.griti, dagen1_1.xtiti, dagen1_1.ytiti, 
		    dagen1_1.zhiti, dagen1_1.niti, &dagen1_1.nziti, &
		    ini2_1.oat1, &ini2_1.itt[ini2_1.ind - 1], &ini1_1.hp, &ie)
		    ;
	}
	if (ie == 2) {
	    goto L10000;
	}
	ini2_1.mw = (real) i_nint(&wxmin);
	if (ini1_1.aw > 0.f) {
	    if (ini1_1.aw < ini1_1.wmin) {
		*ierr = 30;
	    } else if (ini1_1.aw > ini2_1.mw) {
		*ierr = 20;
	    } else if (ini1_1.aw < ini2_1.mw) {
		wxmin = ini1_1.aw;
		ini2_1.ind = 2;
		ini2_1.grad[dagen3_1.segm[ini2_1.ifl - 1] + 2] = -999.f;
		ini2_1.tqto[1] = ini2_1.tqto[0];
		ini2_1.itt[1] = ini2_1.itt[0];
		resto_1.todc = -999.f;
		goto L500;
	    }
	}
	ini2_1.nfp[1] = 0;
	ini2_1.senda[1] = 0;
    }
    if (*ierr < 100) {
	if (*ierr == 0) {
	    if (ini1_1.aw == 0.f) {
		vrxwind = ini2_1.vr[0];
	    } else {
/*      VRXWIND=VR(2) */
		if (ini1_1.aw == ini2_1.mw) {
		    vrxwind = ini2_1.vr[0];
		} else {
		    vrxwind = ini2_1.vr[1];
		}
	    }
	} else {
	    vrxwind = ini2_1.vr[0];
	}
	r__1 = (real) ini1_1.flaps;
	manual3r_(&c__1, &dagen3_1.grcw, dagen3_1.xscw, dagen3_1.yvcw, 
		dagen3_1.zfcw, dagen3_1.ncw, &dagen3_1.nzcw, &vrxwind, &
		mxwind, &r__1, &ie);
	if (ie == 2) {
	    goto L10000;
	}
	if (ini1_1.xwind > mxwind) {
	    *ierr = 242;
	}
    }
L2000:
    for (i__ = 1; i__ <= 2; ++i__) {
	ini2_1.tor[i__ * 3 - 2] = ini2_1.tor[i__ * 3 - 3];
	ini2_1.tor[i__ * 3 - 1] = ini2_1.tor[i__ * 3 - 3];
	ini2_1.tod[i__ * 3 - 2] = ini2_1.tod[i__ * 3 - 3];
	ini2_1.tod[i__ * 3 - 1] = ini2_1.tod[i__ * 3 - 3];
    }
    escrit_(&voi[1], &vor[1], ierr, &dagen3_1.segm[ini2_1.ifl - 1], &verc, 
	    dagen3_1.verd);
    if (s_cmp(vid, "01503A\000\177\000\000", (ftnlen)10, (ftnlen)10) == 0) {
	if (vor[2] != 0.f) {
	    --vor[2];
	}
	if (vor[102] != 0.f) {
	    --vor[102];
	}
	if (vor[3] != 0.f) {
	    --vor[3];
	}
	if (vor[103] != 0.f) {
	    --vor[103];
	}
	if (vor[28] != 0.f) {
	    --vor[28];
	}
	if (vor[128] != 0.f) {
	    --vor[128];
	}
	if (vor[33] != 0.f) {
	    --vor[33];
	}
	if (vor[133] != 0.f) {
	    --vor[133];
	}
	if (vor[38] != 0.f) {
	    --vor[38];
	}
	if (vor[138] != 0.f) {
	    --vor[138];
	}
    }
    return 0;
L10000:
    *ierr = 500;
    return 0;
} /* tacto_ */

