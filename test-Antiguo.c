#include <stdio.h>
#include "caps.h"

void test_to_far();
void test_to_mil();
void test_to_tac();
void test_sc_climb();
void test_sc_cruise_u();
void test_sc_cruise_i();
void test_sc_descend();
void test_land_far();
void test_land_mil();
void test_limits();
void test_ms_miss();

int main(void)
{
//	printf("### TO FAR ###\n");
//	test_to_far();
//	printf("### TO MIL ###\n");
//	test_to_mil();
//	printf("### TO TAC ###\n");
//	test_to_tac();
//	printf("### SC CLIMB ###\n");
//	test_sc_climb();
//	printf("### SC CRUISE POINT ###\n");
//	test_sc_cruise_u();
//	printf("### SC CRUISE INTEGRATED ###\n");
//	test_sc_cruise_i();
//	printf("### SC DESCEND ###\n");
//	test_sc_descend();
	printf("### LAND FAR ###\n");
	test_land_far();
//	printf("### LAND MIL ###\n");
//	test_land_mil();
//	printf("### LIMITS ###\n");
//	test_limits();
//	printf("### MS MISSION ###\n");
//	test_ms_miss();
	return 0;
}

void test_to_far()
{
	/* PARAMS */	
	long VII[TO_VII_LEN] = {};
	float VIR[TO_VIR_LEN] = {};

	long VOI[TO_VOI_LEN];
	float VOR[TO_VOR_LEN];
	
	/* Integer */
	VII[3] = 10;
	VII[6] = 1;
	VII[12] = 1;
	VII[13] = 1;
	/* Float */
	VIR[0] = 12150.0f;
	VIR[1] = 21000.0f;
	VIR[2] = 18000.0f;
	VIR[3] = 0.5f;
	VIR[4] = 1.5f;
	VIR[6] = 2.4f;
	VIR[9] = 35.0f;
	VIR[10] = 1.13f;
	VIR[14] = 7710.0f;
	VIR[15] = 197.0f;
	VIR[16] = 197.0f;
	VIR[17] = 0.27f;
	VIR[18] = 33.0f;
	VIR[20] = 1998.0f;

	long IERR = FARTO("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<TO_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
        
        printf("VOR = ");
        for (i=0; i<TO_VOR_LEN; i++) {
            printf("\nVOR[%d] = %f",i, VOR[i]);
        }
	}
}

void test_to_mil()
{
	/* PARAMS */	
	long VII[TO_VII_LEN] = {};
	float VIR[TO_VIR_LEN] = {};

	long VOI[TO_VOI_LEN];
	float VOR[TO_VOR_LEN];
	
	/* Integer */
	VII[3] = 10;
	VII[12] = 1;
	VII[13] = 1;
	/* Float */
	VIR[0] = 11150.0f;
	VIR[1] = 21000.0f;
	VIR[2] = 18000.0f;
	VIR[3] = 0.5f;
	VIR[4] = 1.5f;
	VIR[6] = 1.8f;
	VIR[9] = 35.0f;
	VIR[10] = 1.13f;
	VIR[14] = 12140.0f;
	VIR[15] = 163.0f;
	VIR[16] = 327.0f;
	VIR[17] = 0.1f;
	VIR[18] = 33.0f;
	VIR[20] = 1998.0f;

	long IERR = MILTO("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<TO_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_to_tac()
{
	/* PARAMS */	
	long VII[TO_VII_LEN] = {};
	float VIR[TO_VIR_LEN] = {};

	long VOI[TO_VOI_LEN];
	float VOR[TO_VOR_LEN];
	
	/* Integer */
	VII[1] = 1;
	VII[3] = 10;
	VII[12] = 1;
	VII[13] = 1;
	/* Float */
	VIR[0] = 11150.0f;
	VIR[1] = 21000.0f;
	VIR[2] = 18000.0f;
	VIR[3] = 1.0f;
	VIR[4] = 1.0f;
	VIR[6] = 1.7f;
	VIR[8] = 300.0f;
	VIR[14] = 12140.0f;
	VIR[15] = 163.0f;
	VIR[16] = 327.0f;
	VIR[17] = 0.1f;
	VIR[18] = 33.0f;
	VIR[20] = 1998.0f;

	long IERR = TACTO("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<TO_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

//PRUEBA WINGLETS
void test_sc_climb()
{
	/* PARAMS */	
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};

	long VOI[SC_VOI_LEN];
	float VOR[SC_VOR_LEN];
	
	/* Integer */
	VII[1] = 1;
	VII[10] = 1;
	/* Float */
	VIR[3] = 16000;
	VIR[6] = 300;
	VIR[8] = 16000;
	VIR[9] = 5;
	VIR[21] = 25000;
    
	long IERR = SCCLI("../tables/", "14178A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
    int i;
    printf("VOI = ");
    for (i=0; i<SC_VOI_LEN; i++) {
        printf("%ld", VOI[i]);
        if (i < (TO_VOI_LEN - 1))
            printf(", ");
    }
    printf("\n");
	}
    
    printf("Error: %ld", IERR);
}

void test_sc_cruise_u()
{
	/* PARAMS */	
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};

	long VOI[SC_VOI_LEN];
	float VOR[SC_VOR_LEN];
	
//	/* Integer */
//	VII[1] = 2;
//	VII[3] = 1;
//	VII[7] = 1;
//	VII[10] = 1;
//	/* Float */
//	VIR[0] = 20;
//	VIR[3] = 18000;
//	VIR[6] = 100;
//	VIR[8] = 1000;
//	VIR[9] = 20;
//	VIR[18] = -10;
//	VIR[19] = -20;
//	VIR[20] = 1000;
    
    VII[1] = 1;
    VII[3] = -2;
    VII[10] = 1;
    
    VIR[0] = 1000;
    VIR[3] = 13200;
    VIR[6] = 300;
    VIR[8] = 10000;
    VIR[17] = 30000;
    VIR[18] = -20;
    VIR[20] = 10000;

	long IERR = SCCRU("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<SC_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_sc_cruise_i()
{
	/* PARAMS */	
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};

	long VOI[SC_VOI_LEN];
	float VOR[SC_VOR_LEN];
	
	/* Integer */
	VII[1] = 2;
	VII[3] = 1;
	VII[7] = 1;
	VII[10] = 1;
	/* Float */
	VIR[0] = 20;
	VIR[3] = 18000;
	VIR[6] = 100;
	VIR[8] = 1000;
	VIR[9] = 20;
	VIR[18] = -10;
	VIR[19] = -20;
	VIR[20] = 1000;

	long IERR = SCCRI("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<SC_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_sc_descend()
{
	/* PARAMS */	
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};

	long VOI[SC_VOI_LEN];
	float VOR[SC_VOR_LEN];
	
	/* Integer */
	VII[1] = 3;
	VII[7] = 1;
	VII[10] = 1;
	/* Float */
	VIR[3] = 18000;
	VIR[7] = 1000;
	VIR[9] = 20;
	VIR[18] = -10;
	VIR[19] = -20;
	VIR[20] = 1000;
	VIR[21] = 100;

	long IERR = SCDES("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<SC_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_land_far()
{
	/* PARAMS */	
	long VII[LD_VII_LEN] = {};
	float VIR[LD_VIR_LEN] = {};

	long VOI[LD_VOI_LEN];
	float VOR[LD_VOR_LEN];
	
	/* Integer */
	VII[0] = 1;
	VII[3] = 23;
	VII[6] = 1;
	VII[12] = 1;
	VII[13] = 1;
	/* Float */
	VIR[0] = 11900;
	VIR[1] = 20700;
	VIR[2] = 17000;
	VIR[3] = 0.5;
	VIR[4] = 1.5;
	VIR[6] = 2.1;
	VIR[8] = 0.6;
    VIR[14] = 8320;
    VIR[17] = 0.06;
	VIR[20] = 8;
    
	long IERR = LAND("../tables/", "14178A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<LD_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_land_mil()
{
	/* PARAMS */	
	long VII[LD_VII_LEN] = {};
	float VIR[LD_VIR_LEN] = {};

	long VOI[LD_VOI_LEN];
	float VOR[LD_VOR_LEN];
	
	/* Integer */
	VII[0] = 2;
	VII[3] = 23;
	VII[6] = 1;
	VII[8] = 1;
	VII[12] = 1;
	VII[13] = 2;
	/* Float */
	VIR[0] = 12150;
	VIR[1] = 23200;
	VIR[2] = 18000;
	VIR[3] = 0.5;
	VIR[4] = 1.5;
	VIR[6] = 1.6;
	VIR[8] = 500;
	VIR[14] = 12140;
	VIR[17] = 0.1;
	VIR[18] = 33;
	VIR[19] = 9.848078;
	VIR[20] = 1998;
	VIR[21] = 1.736482;

	long IERR = LAND("../tables/", "99503A", VII, VIR, VOI, VOR);
	printf("IERR = %ld\n", IERR);
	
	/* print VOI values */
	if (!IERR) {
		int i;
		printf("VOI = ");
		for (i=0; i<LD_VOI_LEN; i++) {
			printf("%ld", VOI[i]);
			if (i < (TO_VOI_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

void test_limits()
{
	float VOR[4];
	long IERR = FARTO_LIM("../tables/", "99503A", VOR);
	printf("IERR = %ld\n", IERR);
	if (!IERR)
		printf("FAR LIMALT: %f, %f, LIMV2: %f, %f\n", VOR[0], VOR[1], VOR[2], VOR[3]);
	
	IERR = MILTO_LIM("../tables/", "99503A", VOR);
	printf("IERR = %ld\n", IERR);
	if (!IERR)
		printf("MIL LIMALT: %f, %f, LIMV2: %f, %f\n", VOR[0], VOR[1], VOR[2], VOR[3]);
	
	long VII[1];
	VII[0] = 1;
	IERR = LAND_LIM("../tables/", "99503A", VII, VOR);
	printf("IERR = %ld\n", IERR);
	if (!IERR)
		printf("LAND FAR LIMALT: %f, %f\n", VOR[0], VOR[1]);
	
	VII[0] = 2;
	IERR = LAND_LIM("../tables/", "99503A", VII, VOR);
	printf("IERR = %ld\n", IERR);
	if (!IERR)
		printf("LAND MIL LIMALT: %f, %f\n", VOR[0], VOR[1]);
}

static void initializei(long *m, int len)
{
	int i;
	for (i=0; i<len; i++) {
		m[i] = 0;
	}
}

static void initializef(float *m, int len)
{
	int i;
	for (i=0; i<len; i++) {
		m[i] = 0.0f;
	}
}

void test_ms_miss()
{
	/* PARAMS */	
	long VII[MS_VII_LEN] = {};
	float VIR[MS_VIR_LEN] = {};
	long SII[MS_SSII_ROW][MS_SSII_COL];
	float SIR[MS_SSIR_ROW][MS_SSIR_COL];
	long GII[MS_GGII_ROW][MS_GGII_COL];
	float GIR[MS_GGIR_ROW][MS_GGIR_COL];
	long FII[MS_FFII_ROW][MS_FFII_COL];
	float FIR[MS_FFIR_ROW][MS_FFIR_COL];

	long VVOI[MS_VVOI_LEN];
	float VVOR[MS_VVOR_LEN];
	float SSOR[MS_SSOR_ROW][MS_SSOR_COL];
	float GGOR[MS_GGOR_ROW][MS_GGOR_COL];
	long FFOI[MS_FFOI_ROW][MS_FFOI_COL];
	float FFOR[MS_FFOR_ROW][MS_FFOR_COL];

	// transport mission:
	// 1000 NM
	// reserve: holding 45
	VII[0] = 2;
	VII[1] = 1;
	VII[2] = 1;

	VIR[0] = 11900;
	VIR[4] = 20700;
	VIR[5] = 23200;
	VIR[6] = 23250;
	VIR[7] = 6301.8;
	VIR[8] = 4000;
	VIR[12] = 5;
	VIR[16] = 300;
	VIR[17] = 600;
	VIR[18] = 8000;
	VIR[19] = 30000;

	initializei(&SII[0][0], MS_SSII_ROW * MS_SSII_COL);
	SII[0][0] = 7;
	SII[0][1] = 1;

	initializef(&SIR[0][0], MS_SSIR_ROW * MS_SSIR_COL);
	SIR[0][0] = 3000;
	SIR[1][0] = 20700;

	initializei(&GII[0][0], MS_GGII_ROW * MS_GGII_COL);
	GII[0][0] = 1;
	GII[1][0] = 7;

	initializef(&GIR[0][0], MS_GGIR_ROW * MS_GGIR_COL);
	GIR[2][0] = 1000;

	initializei(&FII[0][0], MS_FFII_ROW * MS_FFII_COL);	
	FII[0][0] = 1;
	FII[0][1] = 11;
	FII[0][2] = 31;
	FII[0][3] = 41;
	FII[0][4] = 32;
	FII[0][5] = 12;
	FII[0][6] = 2;
	FII[0][7] = 42;
	FII[1][2] = 1;
	FII[1][3] = 3;
	FII[1][4] = 1;
	FII[1][7] = 1;
	FII[3][7] = -1;
	FII[10][0] = 1;
	FII[10][1] = 1;
	FII[10][2] = 1;
	FII[10][3] = 1;
	FII[10][4] = 1;
	FII[10][5] = 1;
	FII[10][6] = 1;
	FII[10][7] = 1;

	initializef(&FIR[0][0], MS_FFIR_ROW * MS_FFIR_COL);
	FIR[0][0] = -1;
	FIR[0][1] = -1;
	FIR[0][2] = 0;
	FIR[0][3] = 0;
	FIR[0][4] = 0;
	FIR[0][5] = -1;
	FIR[0][6] = -1;
	FIR[0][7] = -1;
	FIR[1][0] = 5;
	FIR[1][1] = 2;
	FIR[1][5] = 5;
	FIR[1][6] = 5;
	FIR[1][7] = 45;
	FIR[2][0] = -1;
	FIR[2][1] = -1;
	FIR[2][5] = -1;
	FIR[2][6] = -1;
	FIR[2][7] = -1;
	FIR[4][0] = 23250;
	FIR[4][1] = 23200;
	FIR[4][5] = 23200;
	FIR[14][3] = -1;
	FIR[14][7] = -1;
	FIR[15][3] = -1;
	FIR[15][7] = -1;
	FIR[18][0] = 15;
	FIR[18][1] = 15;
	FIR[18][5] = 15;
	FIR[18][6] = 15;
	FIR[20][2] = 1500;
	FIR[20][3] = 30000;
	FIR[20][4] = 30000;
	FIR[20][5] = 1500;
	FIR[20][7] = 5000;
	FIR[21][1] = 1500;
	FIR[21][2] = 30000;
	FIR[21][3] = 30000;
	FIR[21][4] = 1500;
	FIR[21][7] = 5000;

	long IERR = MISS("../tables/", "99503A", VII, VIR, &SII[0][0], &SIR[0][0], &GII[0][0], &GIR[0][0], &FII[0][0], &FIR[0][0],
			VVOI, VVOR, &SSOR[0][0], &GGOR[0][0], &FFOI[0][0], &FFOR[0][0]);
	printf("IERR = %ld\n", IERR);
	
	/* print VOR values */
	if (!IERR) {
		int i;
		printf("VOR = ");
		for (i=0; i<MS_VVOR_LEN; i++) {
			printf("%f", VVOR[i]);
			if (i < (MS_VVOR_LEN - 1))
				printf(", ");
		}
		printf("\n");
	}
}

