/* SBAS.F -- translated by f2c (version 20100827).
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
    real ybartr, xtr[1000], ytr[1000];
    integer notr, mtr, iertr;
} com_difint2r__;

#define com_difint2r__1 com_difint2r__

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
    real xtr[10000], ytr[10000], ztr[100], ybartr, zbartr;
    integer nxtr[100], ngtr[2], nztr, iertr;
} com_difint3rm__;

#define com_difint3rm__1 com_difint3rm__

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static doublereal c_b57 = 10.;
static doublereal c_b58 = -3.;
static doublereal c_b63 = 1.2;
static doublereal c_b64 = 3.5;
static doublereal c_b65 = 2.;
static doublereal c_b71 = -2.5;
static doublereal c_b72 = .2857143;
static doublereal c_b74 = 2.5;
static doublereal c_b83 = 1.5;

/* Subroutine */ int agape_(real *a, real *aga, real *ape, integer *imax, 
	integer *imin, integer *np)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --a;

    /* Function Body */
    *aga = a[1];
    *imax = 1;
    i__1 = *np;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (a[i__] > *aga) {
	    *aga = a[i__];
	    *imax = i__;
	}
    }
    *imin = 1;
    *ape = a[1];
    i__1 = *np;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (a[i__] < *ape) {
	    *ape = a[i__];
	    *imin = i__;
	}
    }
    return 0;
} /* agape_ */

/* Subroutine */ int int2r_(real *xbar, real *x, real *y, integer *no, 
	integer *m, real *ybar, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;

    /* Local variables */
    static integer i__, j, k, n, i1, i2, nt, mdc;
    static real ell;
    static integer mon;

    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    mon = 0;
    i__ = 1;
    while(mon == 0 && i__ <= *m - 1) {
	if (x[i__ + 1] > x[i__]) {
	    mon = 1;
	}
	if (x[i__ + 1] < x[i__]) {
	    mon = -1;
	}
	++i__;
    }
    i__1 = *m - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (mon == 1) {
	    if (x[i__ + 1] <= x[i__]) {
		*ier = 2;
		return 0;
	    }
	} else if (mon == -1) {
	    if (x[i__ + 1] >= x[i__]) {
		*ier = 2;
		return 0;
	    }
	} else {
	    *ier = 2;
	    return 0;
	}
    }
    if (*m == 0) {
	*ybar = 0.f;
	return 0;
    }
    i1 = 1;
    *ier = 0;
    n = *no + 1;
    if (n > *m) {
	n = *m;
    }
    if ((i__1 = *m - 1) < 0) {
	goto L1;
    } else if (i__1 == 0) {
	goto L2;
    } else {
	goto L10;
    }
L1:
    *ier = 2;
    return 0;
L2:
    *ybar = y[1];
    if (*xbar != x[1]) {
	*ier = 2;
    }
    return 0;
L10:
    mdc = 0;
    if (x[*m] < x[1]) {
	mdc = 1;
    }
    if (i1 <= mdc) {
	i1 = mdc + 1;
    }
/* L43: */
    i__1 = *m;
    for (j = 2; j <= i__1; ++j) {
	if (i1 >= *m + mdc) {
	    i1 = mdc + 1;
	}
	i2 = i1 - mdc - mdc + 1;
	if (*xbar == x[i1]) {
	    *ybar = y[i1];
	    return 0;
	}
	if (*xbar > x[i1] && *xbar <= x[i2]) {
	    goto L40;
	}
/* L20: */
	++i1;
    }
    i1 = 1;
    if (mdc == 0 && *xbar >= x[*m] || mdc != 0 && *xbar <= x[*m]) {
	i1 = *m - 1;
    }
    i2 = i1 + 1;
    *ier = 1;
    if ((r__2 = x[i1] - x[i2], dabs(r__2)) > (r__1 = *xbar - x[i1], dabs(r__1)
	    ) * 1e-9f) {
	*ybar = y[i1] + (*xbar - x[i1]) * (y[i2] - y[i1]) / (x[i2] - x[i1]);
	return 0;
    } else {
	*ier = 2;
	goto L55;
    }
L40:
    if (n > 2) {
	goto L60;
    }
    if (n < 2) {
	goto L55;
    }
    *ybar = y[i1] + (*xbar - x[i1]) * (y[i2] - y[i1]) / (x[i2] - x[i1]);
    return 0;
L55:
    *ybar = y[i1];
    if ((r__1 = *xbar - x[i2], dabs(r__1)) < (r__2 = *xbar - x[i1], dabs(r__2)
	    )) {
	*ybar = y[i2];
    }
    return 0;
L60:
    j = i2 - n / 2;
    if (i2 <= n / 2 + 1) {
	j = 1;
    }
    if (i2 > *m - n / 2) {
	j = *m - n + 1;
    }
    nt = n + j - 1;
    *ybar = 0.f;
    i__1 = nt;
    for (i__ = j; i__ <= i__1; ++i__) {
	ell = 1.f;
	i__2 = nt;
	for (k = j; k <= i__2; ++k) {
	    if (k != i__) {
		ell = ell * (*xbar - x[k]) / (x[i__] - x[k]);
	    }
/* L70: */
	}
/* L80: */
	*ybar += ell * y[i__];
    }
    return 0;
} /* int2r_ */

/* Subroutine */ int int3r_(real *x, real *f, real *y, integer *nx, integer *
	ny, integer *ng, real *xbar, real *fbar, real *ybar, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, i2;
    static real ft[10];
    static integer is, nnn, mon, lox, loy, ierm;
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), buscain_(real *, real *, integer *,
	     integer *, integer *, integer *, integer *);

    /* Parameter adjustments */
    --ng;
    --nx;
    --y;
    --f;
    --x;

    /* Function Body */
    *fbar = 0.f;
    lox = ng[1];
    loy = ng[2];
    mon = 0;
    i__ = 1;
    while(mon == 0 && i__ <= *ny - 1) {
	if (y[i__ + 1] > y[i__]) {
	    mon = 1;
	}
	if (y[i__ + 1] < y[i__]) {
	    mon = -1;
	}
	++i__;
    }
    i__1 = *ny - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (mon == 1) {
	    if (y[i__ + 1] <= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else if (mon == -1) {
	    if (y[i__ + 1] >= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else {
	    *ier = 2;
	    return 0;
	}
    }
    buscain_(ybar, &y[1], ny, &loy, &k, &is, ier);
    if (*ier >= 2) {
	return 0;
    }
    nnn = 1;
    ierm = *ier;
    i__1 = is - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	nnn += nx[i__];
    }
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i2 = is + i__ - 1;
	int2r_(xbar, &x[nnn], &f[nnn], &lox, &nx[i2], &ft[i__ - 1], ier);
	if (*ier > ierm) {
	    ierm = *ier;
	}
/* L10: */
	nnn += nx[i2];
    }
    int2r_(ybar, &y[is], ft, &loy, &k, fbar, ier);
    *ier = ierm;
    return 0;
} /* int3r_ */

/* Subroutine */ int buscain_(real *ybar, real *y, integer *ny, integer *ng, 
	integer *k, integer *is, integer *ier)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Local variables */
    static integer j, n, i1, i2, mdc;

    /* Parameter adjustments */
    --y;

    /* Function Body */
    i1 = 1;
    *ier = 0;
    n = *ng + 1;
    if (n > *ny) {
	n = *ny;
    }
    if ((i__1 = *ny - 1) < 0) {
	goto L1;
    } else if (i__1 == 0) {
	goto L2;
    } else {
	goto L3;
    }
L1:
    *ier = 2;
    return 0;
L2:
    if (*ybar != y[1]) {
	*ier = 2;
    }
    *is = i1;
    *k = 1;
    return 0;
L3:
    *k = n;
    mdc = 0;
    if (y[*ny] < y[1]) {
	mdc = 1;
    }
    if (i1 <= mdc) {
	i1 = mdc + 1;
    }
    i__1 = *ny;
    for (j = 2; j <= i__1; ++j) {
	if (i1 >= *ny + mdc) {
	    i1 = mdc + 1;
	}
	i2 = i1 - (mdc << 1) + 1;
	if (*ybar == y[i1]) {
	    *k = 1;
	    *is = i1;
	    *ier = -1;
	    return 0;
	} else if (*ybar == y[i2]) {
	    *k = 1;
	    *is = i2;
	    *ier = -1;
	    return 0;
	} else if (*ybar > y[i1] && *ybar < y[i2]) {
	    *is = i1;
	    if (mdc == 1) {
		*is = i2;
	    }
	    if (*is + *k - 1 > *ny) {
		*k = 2;
	    }
	    return 0;
	}
/* L4: */
	++i1;
    }
    *is = 1;
    *k = 2;
    *ier = 1;
    if (mdc == 0 && *ybar >= y[*ny] || mdc != 0 && *ybar <= y[*ny]) {
	*is = *ny - 1;
    }
    if ((r__2 = y[*is] - y[*is + 1], dabs(r__2)) <= (r__1 = *ybar - y[*is], 
	    dabs(r__1)) * 1e-9f) {
	*ier = 2;
    }
    return 0;
} /* buscain_ */

/* Subroutine */ int zfalse_(E_fp f, real *eps, integer *nsig, real *xl, real 
	*xr, real *xapp, integer *itmax, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real ten = 10.f;
    static real half = .5f;

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double pow_ri(real *, integer *);

    /* Local variables */
    static integer ic;
    static real fxl, xll, fxr, xrr, epsp, fxapp, fprev;

    *ier = 0;
    ic = 0;
    xll = dmin(*xl,*xr);
    xrr = dmax(*xl,*xr);
    i__1 = -(*nsig);
    epsp = pow_ri(&ten, &i__1);
    fxl = (*f)(&xll);
    fprev = fxl;
    fxr = (*f)(&xrr);
    if (fxl == zero || fxr == zero) {
	goto L10;
    }
    if (fxl * fxr < 0.f) {
	goto L15;
    }
    *ier = 129;
    goto L40;
L10:
    *xapp = xrr;
    if (fxl == zero) {
	*xapp = xll;
    }
    goto L40;
L15:
    *xapp = xll + fxl * (xrr - xll) / (fxl - fxr);
    fxapp = (*f)(xapp);
    if (dabs(fxapp) > *eps) {
	goto L20;
    }
    goto L40;
L20:
    if (fxapp * fxl > zero) {
	goto L25;
    }
    xrr = *xapp;
    fxr = fxapp;
    if (fprev * fxr > zero) {
	fxl = half * fxl;
    }
    fprev = fxr;
    goto L30;
L25:
    xll = *xapp;
    fxl = fxapp;
    if (fprev * fxl > zero) {
	fxr = half * fxr;
    }
    fprev = fxl;
L30:
    if ((r__1 = xrr - xll, dabs(r__1)) > epsp * dabs(xrr)) {
	goto L35;
    }
    goto L40;
L35:
    ++ic;
    if (ic <= *itmax) {
	goto L15;
    }
    *ier = 130;
L40:
    *itmax = ic;
    return 0;
} /* zfalse_ */

/* Subroutine */ int zfalse1_(E_fp f, real *eps, integer *nsig, real *xl, 
	real *xr, real *xapp, integer *itmax, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real ten = 10.f;
    static real half = .5f;

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double pow_ri(real *, integer *);

    /* Local variables */
    static integer ic;
    static real fxl, xll, fxr, xrr, epsp, fxapp, fprev;

    *ier = 0;
    ic = 0;
    xll = dmin(*xl,*xr);
    xrr = dmax(*xl,*xr);
    i__1 = -(*nsig);
    epsp = pow_ri(&ten, &i__1);
    fxl = (*f)(&xll);
    fprev = fxl;
    fxr = (*f)(&xrr);
    if (fxl == zero || fxr == zero) {
	goto L10;
    }
    if (fxl * fxr < 0.f) {
	goto L15;
    }
    *ier = 129;
    goto L40;
L10:
    *xapp = xrr;
    if (fxl == zero) {
	*xapp = xll;
    }
    goto L40;
L15:
    *xapp = xll + fxl * (xrr - xll) / (fxl - fxr);
    fxapp = (*f)(xapp);
    if (dabs(fxapp) > *eps) {
	goto L20;
    }
    goto L40;
L20:
    if (fxapp * fxl > zero) {
	goto L25;
    }
    xrr = *xapp;
    fxr = fxapp;
    if (fprev * fxr > zero) {
	fxl = half * fxl;
    }
    fprev = fxr;
    goto L30;
L25:
    xll = *xapp;
    fxl = fxapp;
    if (fprev * fxl > zero) {
	fxr = half * fxr;
    }
    fprev = fxl;
L30:
    if ((r__1 = xrr - xll, dabs(r__1)) > epsp * dabs(xrr)) {
	goto L35;
    }
    goto L40;
L35:
    ++ic;
    if (ic <= *itmax) {
	goto L15;
    }
    *ier = 130;
L40:
    *itmax = ic;
    return 0;
} /* zfalse1_ */

/* Subroutine */ int zfalse2_(E_fp f, real *eps, integer *nsig, real *xl, 
	real *xr, real *xapp, integer *itmax, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real ten = 10.f;
    static real half = .5f;

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double pow_ri(real *, integer *);

    /* Local variables */
    static integer ic;
    static real fxl, xll, fxr, xrr, epsp, fxapp, fprev;

    *ier = 0;
    ic = 0;
    xll = dmin(*xl,*xr);
    xrr = dmax(*xl,*xr);
    i__1 = -(*nsig);
    epsp = pow_ri(&ten, &i__1);
    fxl = (*f)(&xll);
    if (com_difint2r__1.iertr == 2) {
	return 0;
    }
    fprev = fxl;
    fxr = (*f)(&xrr);
    if (com_difint2r__1.iertr == 2) {
	return 0;
    }
    if (fxl == zero || fxr == zero) {
	goto L10;
    }
    if (fxl * fxr < 0.f) {
	goto L15;
    }
    *ier = 129;
    goto L40;
L10:
    *xapp = xrr;
    if (fxl == zero) {
	*xapp = xll;
    }
    goto L40;
L15:
    *xapp = xll + fxl * (xrr - xll) / (fxl - fxr);
    fxapp = (*f)(xapp);
    if (com_difint2r__1.iertr == 2) {
	return 0;
    }
    if (dabs(fxapp) > *eps) {
	goto L20;
    }
    goto L40;
L20:
    if (fxapp * fxl > zero) {
	goto L25;
    }
    xrr = *xapp;
    fxr = fxapp;
    if (fprev * fxr > zero) {
	fxl = half * fxl;
    }
    fprev = fxr;
    goto L30;
L25:
    xll = *xapp;
    fxl = fxapp;
    if (fprev * fxl > zero) {
	fxr = half * fxr;
    }
    fprev = fxl;
L30:
    if ((r__1 = xrr - xll, dabs(r__1)) > epsp * dabs(xrr)) {
	goto L35;
    }
    goto L40;
L35:
    ++ic;
    if (ic <= *itmax) {
	goto L15;
    }
    *ier = 130;
L40:
    *itmax = ic;
    return 0;
} /* zfalse2_ */

/* Subroutine */ int convel_(real *tdato, real *dato, real *alt, real *pesokg,
	 real *flap, real *wind, integer *nleyd, real *vdat, real *vkeas, 
	real *vkcas, real *vmach, real *vktas, real *vktgs, real *vkias, 
	integer *ier)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static real ro, sig, vis, disa, rein, temp, pres, rvis, vson, delta;
    extern /* Subroutine */ int atmos_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, integer *), 
	    calias_(integer *, real *, real *, real *, real *, integer *), 
	    machcas_(real *, real *, real *, integer *, integer *);

    *vkeas = 0.f;
    *vkcas = 0.f;
    *vmach = 0.f;
    *vktas = 0.f;
    *vktgs = 0.f;
    *vkias = 0.f;
    if (*tdato < 1.f) {
	disa = *dato;
    }
    if (*tdato >= 1.f) {
	disa = *dato - (15.f - *alt * 1.98f / 1e3f);
    }
    atmos_(alt, &disa, &temp, &ro, &sig, &pres, &delta, &vson, &vis, &rvis, &
	    rein, &c__2);
    if (*nleyd == 1) {
	*vkeas = *vdat;
	*vktas = *vdat / sqrt(sig);
	*vmach = *vktas * .514444f / vson;
	machcas_(vmach, vkcas, &delta, &c__1, ier);
	if (*ier > 0) {
	    return 0;
	}
	*vktgs = *vktas - *wind;
    }
    if (*nleyd == 2) {
	*vkcas = *vdat;
	machcas_(vmach, vkcas, &delta, &c__2, ier);
	if (*ier > 0) {
	    return 0;
	}
	*vktas = *vmach * vson * 3.6f / 1.852f;
	*vkeas = *vktas * sqrt(sig);
	*vktgs = *vktas - *wind;
    }
    if (*nleyd == 3) {
	*vmach = *vdat;
	machcas_(vmach, vkcas, &delta, &c__1, ier);
	if (*ier > 0) {
	    return 0;
	}
	*vktas = *vmach * vson * 3.6f / 1.852f;
	*vkeas = *vktas * sqrt(sig);
	*vktgs = *vktas - *wind;
    }
    if (*nleyd == 4) {
	*vktas = *vdat;
	*vkeas = *vktas * sqrt(sig);
	*vktgs = *vktas - *wind;
	*vmach = *vktas * .514444f / vson;
	machcas_(vmach, vkcas, &delta, &c__1, ier);
	if (*ier > 0) {
	    return 0;
	}
    }
    if (*nleyd == 5) {
	*vktgs = *vdat;
	*vktas = *vktgs + *wind;
	*vkeas = *vktas * sqrt(sig);
	*vmach = *vktas * .514444f / vson;
	machcas_(vmach, vkcas, &delta, &c__1, ier);
	if (*ier > 0) {
	    return 0;
	}
    }
    if (*nleyd == 6) {
	*vkias = *vdat;
	calias_(&c__1, flap, pesokg, vkias, vkcas, ier);
	if (*ier > 0) {
	    return 0;
	}
	machcas_(vmach, vkcas, &delta, &c__2, ier);
	if (*ier > 0) {
	    return 0;
	}
	*vktas = *vmach * vson * 3.6f / 1.852f;
	*vkeas = *vktas * sqrt(sig);
	*vktgs = *vktas - *wind;
    }
    if (*nleyd != 6) {
	calias_(&c__2, flap, pesokg, vkcas, vkias, ier);
	if (*ier > 0) {
	    return 0;
	}
    }
    *ier = 0;
    return 0;
} /* convel_ */

/* Subroutine */ int calias_(integer *imod, real *flap, real *peso, real *vin,
	 real *vou, integer *ier)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    extern /* Subroutine */ int manual3r_(integer *, integer *, real *, real *
	    , real *, integer *, integer *, real *, real *, real *, integer *)
	    ;
    static integer i__, it, ifl;
    static real dvc, eps, vcas, vcas1;
    static integer itmax;

    i__1 = dagen2_1.nfcal;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*flap == dagen2_1.fcal[i__ - 1]) {
	    ifl = i__;
	    goto L5;
	}
    }
    *ier = 535;
    return 0;
L5:
    eps = pow_dd(&c_b57, &c_b58);
    it = 0;
    itmax = 100;
    if (*imod == 1) {
	manual3r_(&c__1, &dagen2_1.grcal[ifl - 1], &dagen2_1.xscal[ifl * 500 
		- 500], &dagen2_1.yscal[ifl * 500 - 500], &dagen2_1.zwcal[ifl 
		* 10 - 10], &dagen2_1.ncal[ifl * 10 - 10], &dagen2_1.nzcal[
		ifl - 1], vin, &dvc, peso, ier);
	if (*ier == 2) {
	    return 0;
	}
	*vou = *vin + dvc;
    } else {
	vcas = *vin;
L10:
	++it;
	if (it > itmax) {
	    *ier = 515;
	    return 0;
	}
	manual3r_(&c__1, &dagen2_1.grcal[ifl - 1], &dagen2_1.xscal[ifl * 500 
		- 500], &dagen2_1.yscal[ifl * 500 - 500], &dagen2_1.zwcal[ifl 
		* 10 - 10], &dagen2_1.ncal[ifl * 10 - 10], &dagen2_1.nzcal[
		ifl - 1], &vcas, &dvc, peso, ier);
	if (*ier == 2) {
	    return 0;
	}
	vcas1 = vcas + dvc;
	if ((r__1 = vcas1 - *vin, dabs(r__1)) > eps) {
	    vcas = *vin - dvc;
	    goto L10;
	}
	*vou = *vin - dvc;
    }
    *ier = 0;
    return 0;
} /* calias_ */

/* Subroutine */ int machcas_(real *vmach, real *vkcas, real *delta, integer *
	idato, integer *ier)
{
    /* System generated locals */
    real r__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);

    /* Local variables */
    static real a0, z0, x2, y2, z1, z2;
    static integer jj;
    static real zl, coef, yres, yres1;
    static integer iformu1, iformu2;
    static real errmach;

    errmach = 1e-4f;
    a0 = 661.479f;
    z0 = pow_dd(&c_b63, &c_b64) - 1.f;
    if (*idato == 1) {
	d__1 = (doublereal) (*vmach);
	x2 = pow_dd(&d__1, &c_b65);
	coef = *delta;
    } else {
	d__1 = (doublereal) (*vkcas / a0);
	x2 = pow_dd(&d__1, &c_b65);
	coef = 1.f / *delta;
    }
    d__1 = (doublereal) (x2 * .2f + 1.f);
    z1 = pow_dd(&d__1, &c_b64) - 1.f;
    zl = z1 * coef;
    iformu1 = 1;
    if (x2 <= 1.f) {
	if (zl <= z0) {
	    goto L10;
	}
	if (zl > z0) {
	    goto L20;
	}
    } else {
	d__1 = (doublereal) (x2 * 1.2f);
	d__2 = (doublereal) ((x2 - 1.f) * 1.1666666666666667f + 1.f);
	z2 = pow_dd(&d__1, &c_b64) * pow_dd(&d__2, &c_b71) - 1.f;
	zl = z2 * coef;
	iformu1 = 2;
	if (zl <= z0) {
	    goto L10;
	}
	if (zl > z0) {
	    goto L20;
	}
    }
L10:
    iformu2 = 1;
    d__1 = (doublereal) (zl + 1.f);
    y2 = (pow_dd(&d__1, &c_b72) - 1.f) * 5.f;
    yres = sqrt(y2);
    goto L100;
L20:
    iformu2 = 2;
    y2 = 1.f;
    yres = 1.f;
    for (jj = 1; jj <= 30; ++jj) {
	yres1 = yres;
	d__1 = (doublereal) (1.f - .14285714285714285f / y2);
	y2 = (zl + 1.f) / 1.28756f * pow_dd(&d__1, &c_b74);
	yres = sqrt(y2);
	if ((r__1 = yres - yres1, dabs(r__1)) < errmach) {
	    goto L100;
	}
    }
    *ier = 515;
    return 0;
L100:
    if (*idato == 1) {
	*vkcas = a0 * yres;
    } else {
	*vmach = yres;
    }
    *ier = 0;
    return 0;
} /* machcas_ */

/* Subroutine */ int atmos_(real *hm, real *dt, real *t, real *rhoh, real *
	sig, real *ph, real *delt, real *a, real *visdh, real *rvisd, real *
	rn, integer *ind)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), exp(doublereal), sqrt(
	    doublereal);

    /* Local variables */
    static real g, h__, r__, h11, cl, p11, t11, th, po, to, exp1, exp2, exp3, 
	    gama, rho11, rhoo, visdo;

    to = 288.15f;
    gama = 1.4f;
    t11 = 216.65f;
    h__ = *hm / 1e3f;
    if (*ind - 2 <= 0) {
	goto L1;
    } else {
	goto L3;
    }
L1:
    po = 101325.f;
    r__ = 287.05307f;
    g = 9.80665f;
    visdo = 1.7894e-5f;
    cl = 6.5f;
    h11 = 11.f;
    switch (*ind) {
	case 1:  goto L5;
	case 2:  goto L2;
    }
L2:
    h__ *= .3048f;
    goto L5;
L3:
    po = 2116.22f;
    r__ = 3089.8136f;
    g = 32.1741f;
    visdo = 3.73718e-7f;
    cl = 1.9812000000000001f;
    h11 = 36.089238845144358f;
L5:
    exp1 = g / cl / r__ * 1e3f - 1.f;
    exp2 = exp1 + 1.f;
    exp3 = g / r__ / t11;
    rhoo = po / r__ / to;
    d__1 = (doublereal) (1.f - cl * h11 / to);
    d__2 = (doublereal) exp1;
    rho11 = rhoo * pow_dd(&d__1, &d__2);
    d__1 = (doublereal) (1.f - cl * h11 / to);
    d__2 = (doublereal) exp2;
    p11 = po * pow_dd(&d__1, &d__2);
    if (h__ - h11 <= 0.f) {
	goto L6;
    } else {
	goto L7;
    }
L6:
    th = to - cl * h__;
    d__1 = (doublereal) (1.f - cl * h__ / to);
    d__2 = (doublereal) exp1;
    *rhoh = rhoo * pow_dd(&d__1, &d__2) * (1.f / (*dt / th + 1.f));
    d__1 = (doublereal) (1.f - cl * h__ / to);
    d__2 = (doublereal) exp2;
    *ph = po * pow_dd(&d__1, &d__2);
    d__1 = (doublereal) (1.f - cl * h__ / to);
    d__2 = (doublereal) exp1;
    *sig = pow_dd(&d__1, &d__2) * (1.f / (*dt / th + 1.f));
    d__1 = (doublereal) (1.f - cl * h__ / to);
    d__2 = (doublereal) exp2;
    *delt = pow_dd(&d__1, &d__2);
    goto L8;
L7:
    th = t11;
    *rhoh = rho11 * exp(-exp3 * (h__ - h11) * 1e3f) * (t11 / (t11 + *dt));
    *ph = p11 * exp(-exp3 * (h__ - h11) * 1e3f);
    *sig = *rhoh / rhoo;
    *delt = *ph / po;
L8:
    *t = th + *dt;
    *a = sqrt(gama * r__ * (th + *dt));
    d__1 = (doublereal) ((th + *dt) / to);
    *visdh = visdo * pow_dd(&d__1, &c_b83) * (to + 110.f) / (th + *dt + 110.f)
	    ;
    d__1 = (doublereal) ((th + *dt) / to);
    *rvisd = pow_dd(&d__1, &c_b83) * (to + 110.f) / (th + *dt + 110.f);
    *rn = *rhoh * *a / *visdh;
    return 0;
} /* atmos_ */

/* Subroutine */ int inv2r_(real *xbar, real *x, real *y, integer *no, 
	integer *m, real *ybar, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern doublereal difint2r_();
    static integer i__, ie;
    static real xl, xr, eps;
    static integer mon, imax, imin, nsig;
    static real xmin, ymin, xmax, ymax;
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), agape_(real *, real *, real *, 
	    integer *, integer *, integer *);
    static integer itmax;
    extern /* Subroutine */ int zfalse2_(E_fp, real *, integer *, real *, 
	    real *, real *, integer *, integer *);

    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    *ier = 0;
    if (*m > 1000) {
	*ier = 2;
	return 0;
    }
    mon = 0;
    i__ = 1;
    while(mon == 0 && i__ <= *m - 1) {
	if (y[i__ + 1] > y[i__]) {
	    mon = 1;
	}
	if (y[i__ + 1] < y[i__]) {
	    mon = -1;
	}
	++i__;
    }
    i__1 = *m - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (mon == 1) {
	    if (y[i__ + 1] <= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else if (mon == -1) {
	    if (y[i__ + 1] >= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else {
	    *ier = 2;
	    return 0;
	}
    }
    agape_(&y[1], &ymax, &ymin, &imax, &imin, m);
    if (*no == 1 || *ybar >= ymax || *ybar <= ymin) {
	int2r_(ybar, &y[1], &x[1], &c__1, m, xbar, ier);
	return 0;
    }
    com_difint2r__1.ybartr = *ybar;
    com_difint2r__1.notr = *no;
    com_difint2r__1.mtr = *m;
    com_difint2r__1.iertr = *ier;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	com_difint2r__1.xtr[i__ - 1] = x[i__];
	com_difint2r__1.ytr[i__ - 1] = y[i__];
    }
    eps = 1e-6f;
    nsig = 6;
    itmax = 100;
    agape_(&x[1], &xmax, &xmin, &imax, &imin, m);
    xl = xmin;
    xr = xmax;
    zfalse2_((E_fp)difint2r_, &eps, &nsig, &xl, &xr, xbar, &itmax, &ie);
    if (ie != 0) {
	*ier = 2;
	return 0;
    } else {
	*ier = com_difint2r__1.iertr;
    }
    return 0;
} /* inv2r_ */

doublereal difint2r_(real *xv)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static real yv;
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *);

    int2r_(xv, com_difint2r__1.xtr, com_difint2r__1.ytr, &
	    com_difint2r__1.notr, &com_difint2r__1.mtr, &yv, &
	    com_difint2r__1.iertr);
    if (com_difint2r__1.iertr == 2) {
	ret_val = 0.f;
    } else {
	ret_val = yv - com_difint2r__1.ybartr;
    }
    return ret_val;
} /* difint2r_ */

/* Subroutine */ int manual3r_(integer *ncal, integer *ng, real *xn, real *yn,
	 real *zn, integer *nx, integer *nz, real *x0, real *y0, real *z0, 
	integer *ierr)
{
    static integer nga[2];
    extern /* Subroutine */ int int3rm_(real *, real *, real *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *), inv3rm_(
	    real *, real *, real *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), int3rmz_(real *, real *, real *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );

    /* Parameter adjustments */
    --nx;
    --zn;
    --yn;
    --xn;

    /* Function Body */
    if (*nz == 0) {
	if (*ncal == 1 || *ncal == 4) {
	    *y0 = 0.f;
	    *ierr = 0;
	    return 0;
	} else if (*ncal == 2 || *ncal == 5) {
	    *z0 = 0.f;
	    *ierr = 0;
	    return 0;
	} else if (*ncal == 3 || *ncal == 6) {
	    *x0 = 0.f;
	    *ierr = 0;
	    return 0;
	} else {
	    *ierr = 2;
	    return 0;
	}
    }
    nga[1] = 1;
    nga[0] = -(*ng);
    if (*ncal == 1) {
	int3rm_(&xn[1], &yn[1], &zn[1], &nx[1], nz, nga, x0, y0, z0, ierr);
    } else if (*ncal == 2) {
	int3rmz_(&xn[1], &yn[1], &zn[1], &nx[1], nz, nga, x0, y0, z0, ierr);
    } else if (*ncal == 3) {
	nga[0] = -nga[0];
	int3rm_(&yn[1], &xn[1], &zn[1], &nx[1], nz, nga, y0, x0, z0, ierr);
    } else if (*ncal == 4) {
	nga[0] = -nga[0];
	inv3rm_(&yn[1], &xn[1], &zn[1], &nx[1], nz, nga, y0, x0, z0, ierr);
    } else if (*ncal == 5) {
	nga[0] = -nga[0];
	int3rmz_(&yn[1], &xn[1], &zn[1], &nx[1], nz, nga, y0, x0, z0, ierr);
    } else if (*ncal == 6) {
	inv3rm_(&xn[1], &yn[1], &zn[1], &nx[1], nz, nga, x0, y0, z0, ierr);
    } else {
	*ierr = 2;
	return 0;
    }
    return 0;
} /* manual3r_ */

/* Subroutine */ int int3rmz_(real *x, real *y, real *z__, integer *nx, 
	integer *nz, integer *gr, real *x0, real *y0, real *z0, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static real ya[1000], za[1000];
    static integer np;
    static real yv, zv;
    extern /* Subroutine */ int int2rm_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), int3rm_(real *, real *, real *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );

    /* Parameter adjustments */
    --gr;
    --nx;
    --z__;
    --y;
    --x;

    /* Function Body */
    np = 0;
    i__1 = *nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	zv = z__[i__];
	int3rm_(&x[1], &y[1], &z__[1], &nx[1], nz, &gr[1], x0, &yv, &zv, ier);
	if (*ier == 2) {
	    return 0;
	}
	if (*ier == 0) {
	    ++np;
	    ya[np - 1] = yv;
	    za[np - 1] = zv;
	}
    }
    i__1 = -gr[2];
    int2rm_(y0, ya, za, &i__1, &np, z0, ier);
    return 0;
} /* int3rmz_ */

/* Subroutine */ int zfalse3_(E_fp f, real *eps, integer *nsig, real *xl, 
	real *xr, real *xapp, integer *itmax, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real ten = 10.f;
    static real half = .5f;

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double pow_ri(real *, integer *);

    /* Local variables */
    static integer ic;
    static real fxl, xll, fxr, xrr, epsp, fxapp, fprev;

    *ier = 0;
    ic = 0;
    xll = dmin(*xl,*xr);
    xrr = dmax(*xl,*xr);
    i__1 = -(*nsig);
    epsp = pow_ri(&ten, &i__1);
    fxl = (*f)(&xll);
    if (com_difint3rm__1.iertr == 2) {
	return 0;
    }
    fprev = fxl;
    fxr = (*f)(&xrr);
    if (com_difint3rm__1.iertr == 2) {
	return 0;
    }
    if (fxl == zero || fxr == zero) {
	goto L10;
    }
    if (fxl * fxr < 0.f) {
	goto L15;
    }
    *ier = 129;
    goto L40;
L10:
    *xapp = xrr;
    if (fxl == zero) {
	*xapp = xll;
    }
    goto L40;
L15:
    *xapp = xll + fxl * (xrr - xll) / (fxl - fxr);
    fxapp = (*f)(xapp);
    if (com_difint3rm__1.iertr == 2) {
	return 0;
    }
    if (dabs(fxapp) > *eps) {
	goto L20;
    }
    goto L40;
L20:
    if (fxapp * fxl > zero) {
	goto L25;
    }
    xrr = *xapp;
    fxr = fxapp;
    if (fprev * fxr > zero) {
	fxl = half * fxl;
    }
    fprev = fxr;
    goto L30;
L25:
    xll = *xapp;
    fxl = fxapp;
    if (fprev * fxl > zero) {
	fxr = half * fxr;
    }
    fprev = fxl;
L30:
    if ((r__1 = xrr - xll, dabs(r__1)) > epsp * dabs(xrr)) {
	goto L35;
    }
    goto L40;
L35:
    ++ic;
    if (ic <= *itmax) {
	goto L15;
    }
    *ier = 130;
L40:
    *itmax = ic;
    return 0;
} /* zfalse3_ */

/* Subroutine */ int int2rm_(real *x0, real *x, real *y, integer *gr, integer 
	*nx, real *y0, integer *ier)
{
    static integer grp;
    extern /* Subroutine */ int int2r_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), inv2r_(real *, real *, real *, 
	    integer *, integer *, real *, integer *);

    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    *ier = 0;
    grp = abs(*gr);
    if (*gr > 0 || *gr == -1) {
	int2r_(x0, &x[1], &y[1], &grp, nx, y0, ier);
    } else {
	inv2r_(y0, &y[1], &x[1], &grp, nx, x0, ier);
    }
    return 0;
} /* int2rm_ */

/* Subroutine */ int manual2r_(integer *ncal, real *x0, real *xn, real *yn, 
	integer *ng, integer *nx, real *y0, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ng1;
    extern /* Subroutine */ int int2rm_(real *, real *, real *, integer *, 
	    integer *, real *, integer *);

    /* Parameter adjustments */
    --yn;
    --xn;

    /* Function Body */
    if (*nx == 0) {
	if (*ncal == 1) {
	    *y0 = 0.f;
	    *ierr = 0;
	    return 0;
	} else if (*ncal == 2) {
	    *x0 = 0.f;
	    *ierr = 0;
	    return 0;
	} else {
	    *ierr = 2;
	    return 0;
	}
    }
    ng1 = -(*ng);
    if (*ncal == 1) {
	int2rm_(x0, &xn[1], &yn[1], &ng1, nx, y0, ierr);
    } else if (*ncal == 2) {
	i__1 = -ng1;
	int2rm_(y0, &yn[1], &xn[1], &i__1, nx, x0, ierr);
    } else {
	*ierr = 2;
    }
    return 0;
} /* manual2r_ */

/* Subroutine */ int int3rm_(real *x, real *f, real *y, integer *nx, integer *
	ny, integer *ng, real *xbar, real *fbar, real *ybar, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, i2;
    static real ft[10];
    static integer is, nnn, mon, lox, loy, ierm;
    extern /* Subroutine */ int int2rm_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), buscain_(real *, real *, integer *,
	     integer *, integer *, integer *, integer *);

    /* Parameter adjustments */
    --ng;
    --nx;
    --y;
    --f;
    --x;

    /* Function Body */
    *fbar = 0.f;
    lox = abs(ng[1]);
    loy = abs(ng[2]);
    mon = 0;
    i__ = 1;
    while(mon == 0 && i__ <= *ny - 1) {
	if (y[i__ + 1] > y[i__]) {
	    mon = 1;
	}
	if (y[i__ + 1] < y[i__]) {
	    mon = -1;
	}
	++i__;
    }
    i__1 = *ny - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (mon == 1) {
	    if (y[i__ + 1] <= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else if (mon == -1) {
	    if (y[i__ + 1] >= y[i__]) {
		*ier = 2;
		return 0;
	    }
	} else {
	    *ier = 2;
	    return 0;
	}
    }
    buscain_(ybar, &y[1], ny, &loy, &k, &is, ier);
    if (*ier >= 2) {
	return 0;
    }
    nnn = 1;
    ierm = *ier;
    i__1 = is - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	nnn += nx[i__];
    }
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i2 = is + i__ - 1;
	int2rm_(xbar, &x[nnn], &f[nnn], &ng[1], &nx[i2], &ft[i__ - 1], ier);
	if (*ier == 2) {
	    return 0;
	}
	if (*ier > ierm) {
	    ierm = *ier;
	}
/* L10: */
	nnn += nx[i2];
    }
    int2rm_(ybar, &y[is], ft, &ng[2], &k, fbar, ier);
    *ier = ierm;
    return 0;
} /* int3rm_ */

/* Subroutine */ int inv3rm_(real *x, real *y, real *z__, integer *nx, 
	integer *nz, integer *ng, real *xbar, real *ybar, real *zbar, integer 
	*ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k;
    extern doublereal difint3rm_();
    static integer ie;
    static real xl, xr, eps;
    static integer mon, npt, imax, nsig, imin;
    static real xmin, xmax;
    extern /* Subroutine */ int agape_(real *, real *, real *, integer *, 
	    integer *, integer *);
    static integer itmax;
    extern /* Subroutine */ int int2rm_(real *, real *, real *, integer *, 
	    integer *, real *, integer *), zfalse3_(E_fp, real *, integer *, 
	    real *, real *, real *, integer *, integer *);

    /* Parameter adjustments */
    --ng;
    --nx;
    --z__;
    --y;
    --x;

    /* Function Body */
    *ier = 0;
    npt = 0;
    i__1 = *nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	npt += nx[i__];
    }
    if (npt > 10000) {
	*ier = 2;
	return 0;
    }
    if (*nz > 100) {
	*ier = 2;
	return 0;
    }
    k = 0;
    i__1 = *nz;
    for (j = 1; j <= i__1; ++j) {
	mon = 0;
	i__ = 1;
	while(mon == 0 && i__ <= nx[j] - 1) {
	    if (y[i__ + 1 + k] > y[i__ + k]) {
		mon = 1;
	    }
	    if (y[i__ + 1 + k] < y[i__ + k]) {
		mon = -1;
	    }
	    ++i__;
	}
	i__2 = nx[j] - 1;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (mon == 1) {
		if (y[i__ + 1 + k] <= y[i__ + k]) {
		    *ier = 2;
		    return 0;
		}
	    } else if (mon == -1) {
		if (y[i__ + 1 + k] >= y[i__ + k]) {
		    *ier = 2;
		    return 0;
		}
	    } else {
		*ier = 2;
		return 0;
	    }
	}
	k += nx[j];
    }
    k = 1;
    i__1 = *nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z__[i__] == *zbar) {
	    i__2 = -ng[1];
	    int2rm_(ybar, &y[k], &x[k], &i__2, &nx[i__], xbar, ier);
	    return 0;
	}
	k += nx[i__];
    }
    com_difint3rm__1.ybartr = *ybar;
    com_difint3rm__1.zbartr = *zbar;
    com_difint3rm__1.ngtr[0] = ng[1];
    com_difint3rm__1.ngtr[1] = ng[2];
    com_difint3rm__1.nztr = *nz;
    i__1 = *nz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	com_difint3rm__1.ztr[i__ - 1] = z__[i__];
	com_difint3rm__1.nxtr[i__ - 1] = nx[i__];
    }
    i__1 = npt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	com_difint3rm__1.xtr[i__ - 1] = x[i__];
	com_difint3rm__1.ytr[i__ - 1] = y[i__];
    }
    eps = 1e-6f;
    nsig = 6;
    itmax = 100;
    agape_(&x[1], &xmax, &xmin, &imax, &imin, &npt);
    xl = xmin - (xmax - xmin) * 2.f;
    xr = xmax + (xmax - xmin) * 2.f;
    zfalse3_((E_fp)difint3rm_, &eps, &nsig, &xl, &xr, xbar, &itmax, &ie);
    if (ie != 0) {
	*ier = 2;
	return 0;
    } else {
	*ier = com_difint3rm__1.iertr;
    }
    return 0;
} /* inv3rm_ */

doublereal difint3rm_(real *xv)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    static real yv;
    extern /* Subroutine */ int int3rm_(real *, real *, real *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *);

    int3rm_(com_difint3rm__1.xtr, com_difint3rm__1.ytr, com_difint3rm__1.ztr, 
	    com_difint3rm__1.nxtr, &com_difint3rm__1.nztr, 
	    com_difint3rm__1.ngtr, xv, &yv, &com_difint3rm__1.zbartr, &
	    com_difint3rm__1.iertr);
    if (com_difint3rm__1.iertr == 2) {
	ret_val = 0.f;
    } else {
	ret_val = yv - com_difint3rm__1.ybartr;
    }
    return ret_val;
} /* difint3rm_ */

