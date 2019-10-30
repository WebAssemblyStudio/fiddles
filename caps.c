#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "caps.h"
#include "f2c.h"

extern void My_DEBUG(const char *str);
/* Methods to transpose arrays between C and Fortran */
static void transposei(long *mt, long *mi, int rows, int cols) {
	int i, j;
	for (i=0; i<rows; i++) {
		for (j=0; j<cols; j++) {
			mt[j * rows + i] = mi[i * cols + j];
		}
	}
}

static void transposef(float *mt, float *mi, int rows, int cols) {
	int i, j;
	for (i=0; i<rows; i++) {
		for (j=0; j<cols; j++) {
			mt[j * rows + i] = mi[i * cols + j];
		}
	}
}

/* SUBROUTINE FARTO(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int farto_(char *vic, char *vid, integer *vii, real *vir, integer *voi, real *vor, integer *ierr);
long FARTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	farto_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE MILTO(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int milto_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long MILTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	milto_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE TACTO(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int tacto_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long TACTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	tacto_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE FARTO_LIM(PVIC,PVID,VOR,IERR) */
extern int farto_lim__(char *PVIC, char *PVID, real *VOR, integer *IERR);
long FARTO_LIM(const char *PVIC, const char *PVID, float *VOR)
{
	long IERR;
	farto_lim__((char*)PVIC, (char*)PVID, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE MILTO_LIM(PVIC,PVID,VOR,IERR) */
extern int milto_lim__(char *PVIC, char *PVID, real *VOR, integer *IERR);
long MILTO_LIM(const char *PVIC, const char *PVID, float *VOR)
{
	long IERR;
	milto_lim__((char*)PVIC, (char*)PVID, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE SCCLI(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int sccli_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long SCCLI(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	sccli_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE SCCRU(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int sccru_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long SCCRU(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	sccru_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE SCCRI(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int sccri_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long SCCRI(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	sccri_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE SCCRE(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int sccre_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long SCCRE(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	sccre_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE SCDES(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int scdes_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long SCDES(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	scdes_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE LAND(PVIC,PVID,VII,VIR,VOI,VOR,IERR) */
extern int land_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *VOI, real *VOR, integer *IERR);
long LAND(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR)
{
	long IERR;
	land_((char*)PVIC, (char*)PVID, VII, VIR, VOI, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE LAND_LIM(PVIC,PVID,VII,VOR,IERR) */
extern int land_lim__(const char *PVIC, const char *PVID, integer *VII, real *VOR, integer *IERR);
long LAND_LIM(const char *PVIC, const char *PVID, long *VII, float *VOR)
{
	long IERR;
	land_lim__((char*)PVIC, (char*)PVID, VII, VOR, &IERR);
	return IERR;
}

/* SUBROUTINE MISS (PVIC,PVID,VII,VIR,SSII,SSIR,GGII,GGIR,FFII,FFIR,VVOI,VVOR,SSOR,GGOR,FFOI,FFOR,IIERR) */
extern int miss_(char *PVIC, char *PVID, integer *VII, real *VIR, integer *SSII, real *SSIR, integer *GGII, real *GGIR, 
		integer *FFII, real *FFIR, integer *VVOI, real *VVOR, real *SSOR, real *GGOR, integer *FFOI, real *FFOR, integer *IIERR);
long MISS(const char *PVIC, const char *PVID, long *VII, float *VIR, long *SSII, float *SSIR, long *GGII, float *GGIR, 
		long *FFII, float *FFIR, long *VVOI, float *VVOR, float *SSOR, float *GGOR, long *FFOI, float *FFOR)
{
	long IERR;
	
	// Between C and Fortran transpose the dim 2 arrays
	
	// IN
	long SSIIT[MS_SSII_ROW * MS_SSII_COL];
	transposei(SSIIT, SSII, MS_SSII_ROW, MS_SSII_COL);
	float SSIRT[MS_SSIR_ROW * MS_SSIR_COL];
	transposef(SSIRT, SSIR, MS_SSIR_ROW, MS_SSIR_COL);
	long GGIIT[MS_GGII_ROW * MS_GGII_COL];
	transposei(GGIIT, GGII, MS_GGII_ROW, MS_GGII_COL);
	float GGIRT[MS_GGIR_ROW * MS_GGIR_COL];
	transposef(GGIRT, GGIR, MS_GGIR_ROW, MS_GGIR_COL);
	long FFIIT[MS_FFII_ROW * MS_FFII_COL];
	transposei(FFIIT, FFII, MS_FFII_ROW, MS_FFII_COL);
	float FFIRT[MS_FFIR_ROW * MS_FFIR_COL];
	transposef(FFIRT, FFIR, MS_FFIR_ROW, MS_FFIR_COL);

	// OUT
	float SSORT[MS_SSOR_ROW * MS_SSOR_COL];
	float GGORT[MS_GGOR_ROW * MS_GGOR_COL];
	long FFOIT[MS_FFOI_ROW * MS_FFOI_COL];
	float FFORT[MS_FFOR_ROW * MS_FFOR_COL];

	miss_((char*)PVIC, (char*)PVID, VII, VIR, SSIIT, SSIRT, GGIIT, GGIRT, FFIIT, FFIRT, VVOI, VVOR, SSORT, GGORT, FFOIT, FFORT, &IERR);
	
	// Transpose the solution arrays
	transposef(SSOR, SSORT, MS_SSOR_ROW, MS_SSOR_COL);
	transposef(GGOR, GGORT, MS_GGOR_ROW, MS_GGOR_COL);
	transposei(FFOI, FFOIT, MS_FFOI_ROW, MS_FFOI_COL);
	transposef(FFOR, FFORT, MS_FFOR_ROW, MS_FFOR_COL);

	return IERR;
}

long calc_takeoff(struct input_takeoff *input, struct output_takeoff *output)
{
    long VII[TO_VII_LEN] = {};
	float VIR[TO_VIR_LEN] = {};
    long VOI[TO_VOI_LEN];
	float VOR[TO_VOR_LEN];
    long IERR = 0;
    
    if (strcmp(input->takeoff.takeoffType, "TAC") == 0 || strcmp(input->takeoff.takeoffType, "TAC CEF") == 0)
        VII[1] = 1;
    VII[3] = input->takeoff.codflap;
    VII[6] = input->antiskid;
    VII[7] = input->antiicing;
    VII[11] = input->runway.obstacles.numobstacles;
    VII[12] = input->runway.codType;
    if (strcmp(input->runway.type, "Paved") == 0)
        VII[13] = input->runway.condition;
    else {
        VII[14] = input->runway.condition;
        VII[15] = input->runway.smoth;
    }
    
    VIR[0] = calcOew(input->internalconfig, input->externalconfig);
    VIR[1] = (strcmp(input->runway.type, "Paved") == 0) ? input->operation.mtow : input->operation.mtowunp;
    VIR[2] = input->grossw;
    VIR[3] = input->takeoff.wfhead;
    VIR[4] = input->takeoff.wftail;
    
    float interGrad = getIntergrad(input->takeoff.gradi0, input->takeoff.gradi100, input->takeoff.gradi200, input->plane.avdi1);
    
    if (input->takeoff.minGrad < interGrad) {
        input->takeoff.minGrad = interGrad;
    //VIR[6] = getIntergrad(input->takeoff.gradi0, input->takeoff.gradi100, input->takeoff.gradi200, input->plane.avdi1);
    }
    VIR[6] = input->takeoff.minGrad;
    VIR[8] = input->takeoff.rwymargin;
    VIR[9] = input->takeoff.obstaclear;
    VIR[10] = input->takeoff.suplement;
    VIR[11] = input->plane.avdi1;
    VIR[12] = input->plane.avdi2;
    VIR[13] = input->runway.hardness;
    VIR[14] = input->runway.tora;
    VIR[15] = input->runway.asda - input->runway.tora;
    VIR[16] = input->runway.toda - input->runway.tora;
    VIR[17] = input->runway.slope;
    VIR[18] = input->runway.oat;
    VIR[19] = input->runway.wind;
    VIR[20] = input->runway.elevation;
    VIR[21] = input->runway.xWind;
    
    for (long x = 0; x < input->runway.obstacles.numobstacles; x ++) {
        VIR[30 + 2 * x] = input->runway.obstacles.obstacles[x].distance / 1000;
        VIR[31 + 2 * x] = input->runway.obstacles.obstacles[x].height;
    }
    
    if (strcmp(input->operation.oper, "FAR") == 0)
        IERR = FARTO(input->path, input->file, VII, VIR, VOI, VOR);
    else if (strcmp(input->takeoff.takeoffType, "NORM") == 0 || strcmp(input->takeoff.takeoffType, "TAC CEF") == 0)
        IERR = MILTO(input->path, input->file, VII, VIR, VOI, VOR);
    else if (strcmp(input->takeoff.takeoffType, "TAC") == 0)
        IERR = TACTO(input->path, input->file, VII, VIR, VOI, VOR);
    
    if (IERR != 0)
        return IERR;
    else {
        
        // HACK for PG version (vid = 01503A).
//        if (strcmp(input->file,"01503A") == 0) {
//            
//            if (VOR[2] != 0) {
//                VOR[2] = VOR[2] - 1;
//            }
//            
//            if (VOR[102] != 0) {
//                VOR[102] = VOR[102] - 1;
//            }
//            
//            if (VOR[27] != 0) {
//                VOR[27] = VOR[27] - 1;
//            }
//            
//            if (VOR[127] != 0) {
//                VOR[127] = VOR[127] - 1;
//            }
//            
//            if (VOR[32] != 0) {
//                VOR[32] = VOR[32] - 1;
//            }
//            
//            if (VOR[132] != 0) {
//                VOR[132] = VOR[132] - 1;
//            }
//            
//            if (VOR[37] != 0) {
//                VOR[37] = VOR[37] - 1;
//            }
//            
//            if (VOR[137] != 0) {
//                VOR[137] = VOR[137] - 1;
//            }
//        }
        
        output->trim = calcTrim(input->cg, input->plane.numberTrimPoints, input->plane.trimLimits);
        output->errMtow = VOI[0];
        
        if (strcmp(input->takeoff.v1crit, "BFL") == 0 || strcmp(input->takeoff.v1crit, "INT") == 0) {
            output->todM = VOR[35];
            output->asdM = VOR[33];
            output->torM = VOR[34];
            output->v1M = VOR[32];
            output->fV1M = !(VOI[2] == 0 || VOI[2] == 1 || VOI[2] == 6);
            output->todA = VOR[135];
            output->asdA = VOR[133];
            output->torA = VOR[134];
            output->v1A = VOR[132];
            output->fV1A = !(VOI[7] == 0 || VOI[7] == 1 || VOI[7] == 6);
            
        } else if (strcmp(input->takeoff.v1crit, "CFL") == 0 || strcmp(input->takeoff.v1crit, "MIN") == 0) {
            output->todM = VOR[30];
            output->asdM = VOR[28];
            output->torM = VOR[29];
            output->v1M = VOR[27];
            output->fV1M = !(VOI[1] == 0 || VOI[1] == 1 || VOI[1] == 6);
            output->todA = VOR[130];
            output->asdA = VOR[128];
            output->torA = VOR[129];
            output->v1A = VOR[127];
            output->fV1A = !(VOR[6] == 0 || VOR[6] == 1 || VOR[6] == 6);
            
        } else if (strcmp(input->takeoff.v1crit, "MAX") == 0) {
            output->todM = VOR[40];
            output->asdM = VOR[38];
            output->torM = VOR[39];
            output->v1M = VOR[37];
            output->fV1M = !(VOI[3] == 0 || VOI[3] == 1 || VOI[3] == 6);
            output->todA = VOR[140];
            output->asdA = VOR[138];
            output->torA = VOR[139];
            output->v1A = VOR[137];
            output->fV1A = !(VOR[8] == 0 || VOR[8] == 1 || VOR[8] == 6);
            
        } else {
            output->todM = VOR[40];
            output->asdM = 0;
            output->torM = VOR[39];
            output->v1M = 0;
            output->fV1M = 0;
            output->todA = VOR[140];
            output->asdA = 0;
            output->torA = VOR[139];
            output->v1A = 0;
            output->fV1A = 0;
        }
        output->mtow = VOR[0];
        
        
        
        if (strcmp(input->takeoff.oper, "FAR") == 0) {
            strcpy(output->titleVtod, "VIEW TAKE OFF DISTANCES - FAR");
            strcpy(output->strTor, "TOR");
            
        } else if (strcmp(input->takeoff.takeoffType, "NORM") == 0) {
            strcpy(output->titleVtod, "VIEW TAKE OFF DISTANCES - NORMAL MILITARY");
            strcpy(output->strTor, "TOGR");
            
        } else if (strcmp(input->takeoff.takeoffType, "TAC CEF") == 0) {
            strcpy(output->titleVtod, "VIEW TAKE OFF DISTANCES - TACTICAL CEF");
            strcpy(output->strTor, "TOGR");
            
        } else if (strcmp(input->takeoff.takeoffType, "TAC") == 0) {
            strcpy(output->titleVtod, "VIEW TAKE OFF DISTANCES - TACTICAL AEO");
            strcpy(output->strTor, "TOGR");
        }
        
        
        output->totalRunwayLongitude = input->runway.toda;
        if (output->todM > output->totalRunwayLongitude)
            output->totalRunwayLongitude = output->todM;
        if (output->todA > output->totalRunwayLongitude)
            output->totalRunwayLongitude = output->todA;
        
        
        
        strcpy(output->titleProf, "NET TAKEOFF FLIGHT PATHS");
        
        float vInitialM = output->todM / 1000;
        float vInterM = 0;
        if (strcmp(input->takeoff.oper, "FAR") == 0)
            vInterM = (2 * output->torM - output->todM) / 1000;
        else
            vInterM = output->torM / 1000;
        output->numValuesM = VOI[16] + 2;
        output->valuesXM[0] = 0;
        output->valuesXM[1] = vInterM;
        output->valuesYM[0] = 0;
        output->valuesYM[1] = 0;
        for (long i = 1; i < VOI[16] + 1; i ++) {
            output->valuesXM[i + 1] = VOR[50 + 2 * i - 2] + vInitialM;
            output->valuesYM[i + 1] = VOR[50 + 2 * i - 1] + vInitialM;
        }
        
        float vInitialA = output->todA / 1000;
        float vInterA = 0;
        if (strcmp(input->takeoff.oper, "FAR") == 0)
            vInterA = (2 * output->torA - output->todA) / 1000;
        else
            vInterA = output->torA / 1000;
        output->numValuesA = VOI[17] + 2;
        output->valuesXA[0] = 0;
        output->valuesXA[1] = vInterA;
        output->valuesYA[0] = 0;
        output->valuesYA[1] = 0;
        for (long i = 1; i < VOI[17] + 1; i ++) {
            output->valuesXA[i + 1] = VOR[150 + 2 * i - 2] + vInitialA;
            output->valuesYA[i + 1] = VOR[150 + 2 * i - 1] + vInitialA;
        }
        
        
        
        output->asdAp = VIR[14] + VIR[15];
        output->torAp = VIR[14];
        output->todAp = VIR[14] + VIR[16];
        
        output->tot = VOR[23];
        output->toitt = VOR[25];
        
        output->mctA = VOR[124] + 0.5;
        output->mctM = VOR[24] + 0.5;
        output->accA = VOI[11];
        output->accM = VOI[10];
        if (VOI[12] == 1) {
            strcpy(output->grd, "1st Seg Gr");
            if (input->grossw)
                output->grdA = VOR[111];
            else
                output->grdA = 0;
            output->grdM = VOR[11];
        } else if (VOI[12] == 2) {
            strcpy(output->grd, "2nd Seg Gr");
            if (input->grossw)
                output->grdA = VOR[115];
            else
                output->grdA = 0;
            output->grdM = VOR[15];
        } else if (VOI[12] == 3) {
            strcpy(output->grd, "Final Seg Gr");
            if (input->grossw)
                output->grdA = VOR[119];
            else
                output->grdA = 0;
            output->grdM = VOR[19];
        }
        strcpy(output->rc, "");
        if (strcmp(input->takeoff.oper, "FAR") != 0) {
            if (VOI[12] == 1) {
                strcpy(output->rc, "1st Seg R/C");
                output->rcA = VOR[112];
                output->rcM = VOR[12];
            } else if (VOI[12] == 2) {
                strcpy(output->rc, "2nd Seg R/C");
                output->rcA = VOR[116];
                output->rcM = VOR[16];
            } else if (VOI[12] == 3) {
                strcpy(output->rc, "Final Seg R/C");
                output->rcA = VOR[120];
                output->rcM = VOR[20];
            } else {
                output->rcA = 0;
                output->rcM = 0;
            }
        }
        
        output->vrA = VOR[102];
        output->vrM = VOR[2];
        output->v2A = VOR[103];
        output->v2M = VOR[3];
        output->vrfA1 = VOR[104];
        output->vrfM1 = VOR[4];
        char *flap = malloc(sizeof(char) * 10);
        if (VOR[7] != 0) {
            getFlapCh(input->dbPathPlanes, input->plane.afm, VII[3], flap);
            strcpy(output->vr1, flap);
            strcat(output->vr1, " -> ");
            getFlapCh(input->dbPathPlanes, input->plane.afm, VOR[7], flap);
            strcat(output->vr1, flap);
            
            getFlapCh(input->dbPathPlanes, input->plane.afm, VOR[7], flap);
            strcpy(output->vr2, flap);
            strcpy(output->vr2, " -> ");
            getFlapCh(input->dbPathPlanes, input->plane.afm, 0, flap);
            strcat(output->vr2, flap);
            
            output->vrfA2 = VOR[105];
            output->vrfM2 = VOR[5];
        } else {
            getFlapCh(input->dbPathPlanes, input->plane.afm, VII[3], flap);
            strcpy(output->vr1, flap);
            strcat(output->vr1, " -> ");
            getFlapCh(input->dbPathPlanes, input->plane.afm, 0, flap);
            strcat(output->vr1, flap);
            
            strcpy(output->vr2, "");
            output->vrfA2 = 0;
            output->vrfM2 = 0;
        }
        free(flap);
        output->vftoA = VOR[109];
        output->vftoM = VOR[9];
        
        long IERR2 = 0;
        
        float windSpeedHT = VIR[19];
        float oat = VIR[18];
        long k = 0;
        for (long j = 1; j < 4; j++) {
            VIR[2] = 0;
            VIR[19] = windSpeedHT - (2 - j) * 5;
            output->wind[j - 1] = VIR[19];
            
            for (long i = 1; i < 6; i++) {
                VIR[18] = oat - (3 - i) * 5;
                output->oat[i - 1] = VIR[18];
                
                if (strcmp(input->operation.oper, "FAR") == 0)
                    IERR2 = FARTO(input->path, input->file, VII, VIR, VOI, VOR);
                else if (strcmp(input->takeoff.takeoffType, "NORM") == 0 || strcmp(input->takeoff.takeoffType, "TAC CEF") == 0)
                    IERR2 = MILTO(input->path, input->file, VII, VIR, VOI, VOR);
                else if (strcmp(input->takeoff.takeoffType, "TAC") == 0)
                    IERR2 = TACTO(input->path, input->file, VII, VIR, VOI, VOR);
                
                if (IERR2 != 0) {
                    output->errorMtowSen[k] = 1;
                    output->mtowSen[k] = IERR2;
                    output->filterMtowSen[k] = 1;
                } else {
                    output->errorMtowSen[k] = 0;
                    output->mtowSen[k] = VOR[0];
                    output->filterMtowSen[k] = (output->mtowSen[k] < input->grossw);
                }
                
                k++;
            }
        }
    }
    
    return IERR;
}

long calc_climb(struct input_climb *input, struct output_climb *output)
{
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};
	long VOI[SC_VOI_LEN] = {};
	float VOR[SC_VOR_LEN] = {};
	long IERR = 0;
    
    VII[1] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "SUBIDA", input->type);
    VII[7] = input->antiicing;
    VII[10] = input->ecs;
    
    VIR[3] = input->grossw;
    VIR[6] = input->rcmin;
    VIR[8] = input->maxcabinalt;
    VIR[9] = input->fffactor;
    VIR[11] = input->plane.avdi2;
    VIR[12] = input->plane.avdi1;
    if (strcmp(input->oper, "") != 0) VIR[17] = getMaxAlt(input->dbPathPlanes, input->plane.afm, input->oper);
    VIR[18] = input->isa;
    VIR[19] = input->wind;
    VIR[20] = input->initialalt;
    VIR[21] = input->finalalt;
    
    /*
     * ####### PARA DEBUGG EN CONSOLA
     */
    
//    char tmp[1024];
//    
//    int i;
//    for (i = 0; i < SC_VII_LEN; i ++) {
//        sprintf(tmp, "VII[%d]: %d",i,VII[i]);
//        My_DEBUG(tmp);
//    }
//    for (i = 0; i < SC_VIR_LEN; i ++) {
//        sprintf(tmp, "VIR[%d]: %f",i,VIR[i]);
//        My_DEBUG(tmp);
//    }
    /*
     * ####### FIN-PARA DEBUGG EN CONSOLA
     */
    
    IERR = SCCLI(input->path, input->file, VII, VIR, VOI, VOR);
    
    if (IERR != 0)
        return IERR;
    else {
        switch (VOI[0]) {
            case 1:
		strcpy(output->limit, "A/C R/C");
                break;
            case 2:
                strcpy(output->limit, "CAB ALT");
                break;
            case 3:
                strcpy(output->limit, "MAX ALT");
                break;
            default:
                strcpy(output->limit, "");
                break;
        }
        output->altitudeCompleted = (VIR[20] >= 0 && VIR[21] >= 0) ? 1 : 0;
        output->initialWeight = VIR[3];
        output->fuel = VOR[0];
        output->time = VOR[1];
        output->distance = VOR[2];
        output->finalWeight = VOR[4];
        output->finalAlt = VOR[7];
        output->initiaV = VOR[10];
        output->finalV = VOR[11];
        output->rtcClimb = VOR[16];
        output->initialTq = VOR[20];
        if ((VIR[20] < 0 && VIR[21] >= 0) || (VIR[20] >= 0 && VIR[21] < 0))
            strcpy(output->ceiling, "Altitude");
        else
            strcpy(output->ceiling, "Ceiling");
    }
    
    return IERR;
}

long calc_cruise(struct input_cruise *input, struct output_cruise *output)
{
	long VII[SC_VII_LEN] = {};
	float VIR[SCCRE_VIR_LEN] = {};
	long VOI[SC_VOI_LEN] = {};
	float VOR[SC_VOR_LEN] = {};
	long IERR = 0;

	VII[1] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "CRUCERO", input->type);
	VII[3] = input->cruisinglevels;
	VII[7] = input->antiicing;
	VII[10] = input->ecs;

	VIR[0] = input->fuel;
	VIR[3] = input->grossw;
	VIR[6] = input->rcmin;
	VIR[8] = input->maxcabinalt;
	VIR[9] = input->fffactor;
	VIR[11] = input->plane.avdi2;
	VIR[12] = input->plane.avdi1;
	if (strcmp(input->oper, "") != 0)
		VIR[17] = getMaxAlt(input->dbPathPlanes, input->plane.afm, input->oper);
	VIR[18] = input->isa;
	VIR[19] = input->wind;
	VIR[20] = input->altitude;
	VIR[39] = input->distance;
	VIR[40] = input->time;

	IERR = SCCRE(input->path, input->file, VII, VIR, VOI, VOR);
	// return on error
	if (IERR != 0 && IERR != 1215)
		return IERR;

	switch (VOI[0]) {
		case 1:
			strcpy(output->limit, "A/C R/C");
			break;
		case 2:
			strcpy(output->limit, "CAB ALT");
			break;
		case 3:
			strcpy(output->limit, "MAX ALT");
			break;
		default:
			strcpy(output->limit, "");
			break;
	}
	output->initialWeight = VIR[3];
	output->fuel = (input->fuel > 0) ? VOR[0] : 0;
	output->time = VOR[1];
	output->distance = VOR[2];
	output->finalWeight = VOR[4];
	output->initiaAirspeed = VOR[10];
	output->finalAirspeed = (input->fuel > 0) ? VOR[11] : VOR[13];
	output->initialTq = VOR[20];
	output->pressureAltitude = VOR[7];
	output->altitude = VIR[20];
	output->wind = VIR[19];
	output->ff = VOR[0];
	output->sr = VOR[2];
	output->tq = VOR[20];

	return IERR;
}

long calc_descent (struct input_descent *input, struct output_descent *output)
{
	long VII[SC_VII_LEN] = {};
	float VIR[SC_VIR_LEN] = {};
	long VOI[SC_VOI_LEN] = {};
	float VOR[SC_VOR_LEN] = {};
	long IERR = 0;
    
    VII[1] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "DESCENSO", input->type);
    VII[7] = input->antiicing;
    VII[10] = input->ecs;
    
    VIR[3] = input->grossw;
    VIR[7] = input->maxcabinrate;
    VIR[9] = input->fffactor;
    VIR[11] = input->plane.avdi2;
    VIR[12] = input->plane.avdi1;
    if (strcmp(input->oper, "") != 0) VIR[17] = getMaxAlt(input->dbPathPlanes, input->plane.afm, input->oper);
    VIR[18] = input->isa;
    VIR[19] = input->wind;
    VIR[20] = input->initialalt;
    VIR[21] = input->finalalt;
    /*
     * ####### PARA DEBUGG EN CONSOLA
     */
//            char tmp[1024];
//    
//            int i;
//            for (i = 0; i < SC_VII_LEN; i ++) {
//                sprintf(tmp, "VII[%d]: %d",i,VII[i]);
//                My_DEBUG(tmp);
//            }
//            for (i = 0; i < SC_VIR_LEN; i ++) {
//                sprintf(tmp, "VIR[%d]: %f",i,VIR[i]);
//                My_DEBUG(tmp);
//            }
    /*
     * ####### FIN-PARA DEBUGG EN CONSOLA
     */
    
    IERR = SCDES(input->path, input->file, VII, VIR, VOI, VOR);
    
    if (IERR != 0)
        return IERR;
    else {
        output->initialWeight = VIR[3];
        output->fuel = VOR[0];
        output->time = VOR[1];
        output->distance = VOR[2];
        output->initiaV = VOR[10];
        output->finalV = VOR[11];
    }
    
    return IERR;
}

long calc_landing(struct input_landing *input, struct output_landing *output)
{
	long VII[LD_VII_LEN] = {};
	float VIR[LD_VIR_LEN] = {};
	long VOI[LD_VOI_LEN];
	float VOR[LD_VOR_LEN];
	long IERR = 0;
    
    if (strcmp(input->landing.oper, "FAR") == 0) VII[0] = 1;
    else VII[0] = (strcmp(input->landing.landingType, "NORM") == 0) ? 2 : 3;
    VII[3] = input->landing.codflap;
    VII[6] = input->antiskid;
    VII[7] = input->antiicing;
    VII[8] = input->ground;
    VII[12] = input->runway.codType;
    if (strcmp(input->runway.type, "Paved") == 0) VII[13] = input->runway.condition;
    else {
        VII[14] = input->runway.condition;
        VII[15] = input->runway.smoth;
    }
    
    VIR[0] = calcOew(input->internalconfig, input->externalconfig);;
    VIR[1] = (strcmp(input->runway.type, "Paved") == 0) ? input->operation.mlw : input->operation.mlwunp;
    VIR[2] = input->grossw;
    VIR[3] = input->landing.wfhead;
    VIR[4] = input->landing.wftail;
    
    float interGrad = getIntergrad(input->landing.gradi0, input->landing.gradi100, input->landing.gradi200, input->plane.avdi1);
    
    if (input->landing.minGrad < interGrad)
        input->landing.minGrad = interGrad;
    
    VIR[6] = input->landing.minGrad;
    
    VIR[8] = (input->alternative == 1) ? input->landing.rwymarginalt : input->landing.rwymargindes;
    VIR[11] = input->plane.avdi1;
    VIR[12] = input->plane.avdi2;
    VIR[13] = calcCbr(input->runway.hardness);
    VIR[14] = input->runway.tora;
    VIR[17] = input->runway.slope;
    VIR[18] = input->runway.oat;
    VIR[19] = input->runway.wind;
    VIR[20] = input->runway.elevation;
    VIR[21] = input->runway.xWind;
    
    /*
     * ####### PARA DEBUGG EN CONSOLA
     */
    
//        char tmp[1024];
//    
//        int i;
//        for (i = 0; i < LD_VII_LEN; i ++) {
//            sprintf(tmp, "VII[%d]: %d",i,VII[i]);
//            My_DEBUG(tmp);
//        }
//        for (i = 0; i < LD_VIR_LEN; i ++) {
//            sprintf(tmp, "VIR[%d]: %f",i,VIR[i]);
//            My_DEBUG(tmp);
//        }
    /*
     * ####### FIN-PARA DEBUGG EN CONSOLA
     */
    
    IERR = LAND(input->path, input->file, VII, VIR, VOI, VOR);
    
    if (IERR != 0)
        return IERR;
    else {
        output->mlw = VOR[0];
        output->alw = VOR[50];
        output->lflm = VOR[31];
        output->lgrm = VOR[29];
        output->ldm = VOR[30];
        output->lfla = VOR[81];
        output->lgra = VOR[79];
        output->lda = VOR[80];
        output->ldaValue = VIR[14];
        
        
        if (strcmp(input->landing.oper, "FAR") == 0)
            strcpy(output->titleVld, "VIEW LANDING DISTANCES - FAR");
        else if (strcmp(input->landing.landingType, "NORM") == 0)
            strcpy(output->titleVld, "VIEW LANDING DISTANCES - NORMAL MILITARY");
        else if (strcmp(input->landing.landingType, "TAC") == 0)
            strcpy(output->titleVld, "VIEW LANDING DISTANCES - TACTICAL");
        output->ld = VIR[14];
        output->totalRunwayLongitude = VOR[50];
        
        
        output->avlb = VIR[14];
        if (strcmp(input->operation.oper, "FAR") == 0) {
            VOR[29] = 0;
            VOR[79] = 0;
        }
        output->gat = VOR[19];
        output->mct = VOR[20];
        if (VOI[12] == 1) {
            strcpy(output->lbApp, "App Gr");
            output->appm = VOR[11];
            output->appa = VOR[61];
        } else if (VOI[12] == 2) {
            strcpy(output->lbApp, "Ldng Gr");
            output->appm = VOR[13];
            output->appa = VOR[63];
        } else
            strcpy(output->lbApp, "");
        
        getFlapCh(input->dbPathPlanes, input->plane.afm, VOI[9], output->vmanf);
        getFlapCh(input->dbPathPlanes, input->plane.afm, VOI[10], output->vthf);
        getFlapCh(input->dbPathPlanes, input->plane.afm, VOI[11], output->gaf);
        output->vmana = VOR[52];
        output->vappa = VOR[53];
        output->vtha = VOR[54];
        output->gaa = VOR[56];
        output->vmanm = VOR[2];
        output->vappm = VOR[3];
        output->vthm = VOR[4];
        output->gam = VOR[6];
        strcpy(output->vth, (VOI[8] == 0) ? "VTH" : "VREF");
        
        
        float windSpeedHT = VIR[19];
        float oat = VIR[18];
        long k = 0;
        
        for (long j = 1; j < 4; j ++) {
            for (long i = 1; i < 6; i ++) {
                
                if (VOR[k + 130] > 0 && VOR[k + 130] <= VIR[14]) {
                    output->filterLdSen[k] = 1;
                    output->ldSen[k] = VOR[k + 130];
                    output->errorLdSen[k] = 0;
                } else if (VOR[k + 130] > 0 && VOR[k + 130] > VIR[14]) {
                    output->filterLdSen[k] = 0;
                    output->ldSen[k] = VOR[k + 130];
                    output->errorLdSen[k] = 0;
                } else {
                    output->filterLdSen[k] = 1;
                    output->ldSen[k] = VOR[k + 130] * -1;
                    output->errorLdSen[k] = 1;
                }
                k ++;
            }
        }
        k = 0;
        long IERR2 = 0;
        
        for (long j = 1; j < 4; j ++) {
            VIR[2] = 0;
            VIR[19] = windSpeedHT - (2 - j) * 5;
            output->wind[j - 1] = VIR[19];
            
            for (long i = 1; i < 6; i ++) {
                VIR[18] = oat - (3 - i) * 5;
                output->oat[i - 1] = VIR[18];
                
                IERR2 = LAND(input->path, input->file, VII, VIR, VOI, VOR);
                
                if (IERR2 == 0) {
                    output->mlwSen[k] = VOR[0];
                    output->errorMlwSen[k] = 0;
                    if (VOR[0] >= output->alw)
                        output->filterMlwSen[k] = 1;
                    else
                        output->filterMlwSen[k] = 0;
                } else {
                    output->mlwSen[k] = IERR2;
                    output->errorMlwSen[k]= 1;
                    output->filterMlwSen[k] = 0;
                }
                k ++;
            }
        }
    }
    
    return IERR;
}

long calc_mission(struct input_mission *input, struct output_mission *output)
{
	long VII[MS_VII_LEN] = {};
	long SII[MS_SSII_ROW][MS_SSII_COL] = {};
	long GII[MS_GGII_ROW][MS_GGII_COL] = {};
	long FII[MS_FFII_ROW][MS_FFII_COL] = {};
	float VIR[MS_VIR_LEN] = {};
	float SIR[MS_SSIR_ROW][MS_SSIR_COL] = {};
	float GIR[MS_GGIR_ROW][MS_GGIR_COL] = {};
	float FIR[MS_FFIR_ROW][MS_FFIR_COL] = {};
	long VOI[MS_VVOI_LEN] = {};
	long FOI[MS_FFOI_ROW][MS_FFOI_COL] = {};
	float VOR[MS_VVOR_LEN] = {};
	float SOR[MS_SSOR_ROW][MS_SSOR_COL] = {};
	float GOR[MS_GGOR_ROW][MS_GGOR_COL] = {};
	float FOR[MS_FFOR_ROW][MS_FFOR_COL] = {};
	long IERR = 0;
    
    struct input_taxiout firstTaxiout = *(struct input_taxiout*)input->phases[0];
    struct input_takeoff firstTakeoff = *(struct input_takeoff*)input->phases[1];
    long runwayNone = (firstTakeoff.runway.tora == 10000 && firstTakeoff.runway.asda == 10000 && firstTakeoff.runway.toda == 10000) ? 1 : 0;
    
    VII[0] = input->numSectors;
    VII[1] = 0;
    long fasesTotales = 0;
    for (long x = 0; x < input->numSectors; x ++) {
        VII[1] += input->sectors[x].numGroups;
        fasesTotales += input->sectors[x].numPhases;
    }
    VII[2] = 1;
    VII[4] = (firstTakeoff.operation.mtowalt > 0);
    
    if (input->fuel > 0) {
        VII[1] ++;
        strcpy(output->groups[VII[1] - 1].groupName, "MAX fuel");
        GII[0][VII[1] - 1] = 1;
        GII[1][VII[1] - 1] = fasesTotales;
        GIR[0][VII[1] - 1] = input->fuel;
    }
    
    VIR[0] = input->internalconfig.oew;
    VIR[1] = calcOew(input->internalconfig, input->externalconfig) - input->internalconfig.oew;
    VIR[4] = firstTakeoff.operation.mzfw;
    VIR[6] = firstTakeoff.operation.mrw;
    VIR[7] = calcMaxFuel(0, firstTakeoff, firstTaxiout, calcFuel(firstTakeoff.runway, input->plane, input->internalconfig, input->externalconfig, input->fixedFuelValue, input->infoFuel, input->refuelingError), calcOew(input->internalconfig, input->externalconfig));
    // To compute extra fuel
    if (input->fuel > 0)
	    VIR[8] = input->fuel;
    if (input->minimumCruisePortion == 2) VIR[12] = input->time;
    else VIR[11] = (input->minimumCruisePortion == 0) ? input->time : input->time * -1;
    VIR[16] = input->rcmin;
    VIR[17] = input->maxcabinrate;
    VIR[18] = input->maxcabinalt;
    VIR[19] = getMaxAlt(input->dbPathPlanes, input->plane.afm, firstTakeoff.takeoff.oper);
    VIR[21] = (input->sectors[input->numSectors - 1].fuelType == 0) ? input->sectors[input->numSectors - 1].fuelValue : input->sectors[input->numSectors - 1].fuelValue * -1;
    VIR[22] = input->sectors[input->numSectors - 1].fixed;
    VIR[24] = (input->sectors[input->numSectors - 1].timeType == 0) ? input->sectors[input->numSectors - 1].timeValue : input->sectors[input->numSectors - 1].timeValue * -1;
    
    long nGrupo = 0;
    long gruposAcumulados = 1;
    long nFase = 0;
    for (long i = 0; i < input->numSectors; i ++) {
        struct input_taxiout *datosTaxiOut = NULL;
        struct input_takeoff *datosTakeOff = NULL;
        if (i < input->numSectors - 1) {
            datosTaxiOut = (struct input_taxiout*)input->phases[nFase];
            datosTakeOff = (struct input_takeoff*)input->phases[nFase + 1];
        }
        
        SII[0][i] = input->sectors[i].numPhases;
        SII[1][i] = (i == 0 || i == input->numSectors - 1) ? input->optionMaxima : datosTaxiOut->optionMaxima;
        
        SIR[0][i] = (i == input->numSectors - 1) ? 0 : (datosTaxiOut->pl < 0) ? input->pl : datosTaxiOut->pl;
        SIR[1][i] = (i == input->numSectors - 1) ? 0 : datosTakeOff->operation.mzfw;
        SIR[2][i] = (i == input->numSectors - 1) ? 0 : datosTakeOff->operation.mzfwalt;
        
        for (long j = 0; j < input->sectors[i].numGroups; j ++) {
            strcpy(output->groups[nGrupo].groupName, input->sectors[i].groups[j].groupName);
            GII[0][nGrupo] = input->sectors[i].groups[j].initialPhase + gruposAcumulados;
            GII[1][nGrupo] = input->sectors[i].groups[j].finalPhase + gruposAcumulados;
            if (input->sectors[i].groups[j].type == 0)
                GIR[0][nGrupo] = (input->sectors[i].groups[j].value > 0) ? input->sectors[i].groups[j].value : -1;
            else if (input->sectors[i].groups[j].type == 1)
                GIR[1][nGrupo] = (input->sectors[i].groups[j].value > 0) ? input->sectors[i].groups[j].value : -1;
            else if (input->sectors[i].groups[j].type == 2)
                GIR[2][nGrupo] = (input->sectors[i].groups[j].value > 0) ? input->sectors[i].groups[j].value : -1;
            nGrupo ++;
        }
        gruposAcumulados += input->sectors[i].numPhases;
        
        for (long k = 0; k < input->sectors[i].numPhases; k ++) {
            struct input_taxiout iTo;
            struct input_takeoff iTk;
            struct output_takeoff oTk;
            struct input_climb iCl;
            struct input_cruise iCr;
            struct input_descent iDs;
            struct input_landing iLd;
            struct output_landing oLd;
            struct input_taxiin iTi;
            struct input_holding iHl;
            struct input_goaround iGa;
            switch (input->phasesTypes[nFase]) {
                case 0:
                    iTo = *(struct input_taxiout*)input->phases[nFase];
                    iTk = *(struct input_takeoff*)input->phases[nFase + 1];
                    
                    FII[0][nFase] = 1;
                    FII[7][nFase] = iTo.antiicing;
                    FII[10][nFase] = iTo.ecs;
                    
                    FIR[0][nFase] = (iTo.fuelType == 1) ? iTo.fuelValue : -1;
                    FIR[1][nFase] = iTo.time;
                    FIR[2][nFase] = -1;
                    FIR[4][nFase] = iTk.operation.mrw;
                    FIR[9][nFase] = (iTo.fuelType == 0) ? iTo.fuelValue : input->fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iTk.runway.oat;
                    FIR[20][nFase] = FIR[21][nFase] = iTk.runway.elevation;
                    break;
                    
                case 1:
                    iTk = *(struct input_takeoff*)input->phases[nFase];
                    iTo = *(struct input_taxiout*)input->phases[nFase - 1];
                    long errorTk = calc_takeoff(&iTk, &oTk);
                    if (errorTk != 0)
                        return errorTk;
                    
                    FII[0][nFase] = 11;
                    FII[7][nFase] = iTk.antiicing;
                    FII[10][nFase] = iTo.ecs;
                    
                    FIR[0][nFase] = (iTk.fuelType == 1) ? iTk.fuelValue : -1;
                    FIR[1][nFase] = iTk.time;
                    FIR[2][nFase] = -1;
                    if (runwayNone == 0 || memcmp(input->plane.plane, "C-295", 5) != 0)
                        FIR[4][nFase] = oTk.mtow;
                    else
                        FIR[4][nFase] = iTk.operation.mtow;
                    if (i == 0)
                        VIR[5] = FIR[4][nFase];
                    FIR[5][nFase] = iTk.operation.mtowalt;
                    FIR[9][nFase] = (iTk.fuelType == 0) ? iTk.fuelValue : input->fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iTk.runway.oat;
                    FIR[19][nFase] = iTk.runway.wind;
                    FIR[20][nFase] = iTk.runway.elevation;
                    FIR[21][nFase] = iTk.runway.elevation + iTk.heightGained;
                    break;
                    
                case 2:
                    iCl = *(struct input_climb*)input->phases[nFase];
                    
                    FII[0][nFase] = 31;
                    FII[1][nFase] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "SUBIDA", iCl.type);
                    FII[7][nFase] = iCl.antiicing;
                    FII[10][nFase] = iCl.ecs;
                    
                    FIR[9][nFase] = iCl.fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iCl.isa;
                    FIR[19][nFase] = iCl.wind;
                    FIR[20][nFase] = FIR[21][nFase-1];
                    break;
                    
                case 3:
                    iCr = *(struct input_cruise*)input->phases[nFase];
                    if (input->phasesTypes[nFase + 1] == 5)
                        iLd = *(struct input_landing*)input->phases[nFase + 1];
                    else if (input->phasesTypes[nFase - 1] == 1)
                        iTk = *(struct input_takeoff*)input->phases[nFase - 1];
                    
                    FII[0][nFase] = 41;
                    FII[1][nFase] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "CRUCERO", iCr.type);
                    FII[2][nFase] = (iCr.typeAltitude == 1) ? 2 : (iCr.typeAltitude == 2) ? 1 : 0;
                    FII[3][nFase] = iCr.cruisinglevels;
                    FII[7][nFase] = iCr.antiicing;
                    FII[10][nFase] = iCr.ecs;
                    
                    FIR[9][nFase] = iCr.fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[13][nFase] = (input->internalconfig.airdrop == 1) ? iCr.loadLaunched : 0;
                    FIR[14][nFase] = -1;
                    FIR[15][nFase] = -1;
                    FIR[18][nFase] = iCr.isa;
                    FIR[19][nFase] = iCr.wind;
                    if (iCr.typeAltitude == 0)
                        FIR[20][nFase] = FIR[21][nFase] = iCr.altitude;
                    else if (iCr.typeAltitude == 3) {
                        if (input->phasesTypes[nFase + 1] == 5) {
                            FIR[20][nFase] = FIR[21][nFase] = iCr.altitude + iLd.runway.elevation;
                            if (iLd.initialHeight + iLd.runway.elevation != FIR[20][nFase])
                                iLd.initialHeight = FIR[20][nFase] - iLd.runway.elevation;
                        } else if (input->phasesTypes[nFase - 1] == 1)
                            FIR[20][nFase] = FIR[21][nFase] = iCr.altitude + iTk.runway.elevation;
                        else
                            FIR[20][nFase] = FIR[21][nFase] = iCr.altitude;
                    } else {
                        FIR[14][nFase] = (iCr.altitude > 0) ? iCr.altitude : -1;
                        FIR[15][nFase] = (iCr.altitude2 > 0) ? iCr.altitude2 : -1;
                    }
                    
                    if (input->phasesTypes[nFase - 1] == 2 || input->phasesTypes[nFase - 1] == 4)
                        FIR[21][nFase - 1] = FIR[20][nFase];
                    break;
                    
                case 4:
                    iDs = *(struct input_descent*)input->phases[nFase];
                    
                    FII[0][nFase] = 32;
                    FII[1][nFase] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "DESCENSO", iDs.type);
                    FII[7][nFase] = iDs.antiicing;
                    FII[10][nFase] = iDs.ecs;
                    
                    FIR[9][nFase] = iDs.fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iDs.isa;
                    FIR[19][nFase] = iDs.wind;
                    FIR[20][nFase] = FIR[21][nFase-1];
                    break;
                    
                case 5:
                    iLd = *(struct input_landing*)input->phases[nFase];
                    iTi = *(struct input_taxiin*)input->phases[nFase + 1];
                    long errorLd = calc_landing(&iLd, &oLd);
                    if (errorLd != 0)
                        return errorLd;
                    
                    FII[0][nFase] = 12;
                    FII[7][nFase] = iLd.antiicing;
                    FII[10][nFase] = iTi.ecs;
                    FII[12][nFase] = iLd.fuelTaken;
                    FII[13][nFase] = (iLd.distanceType == 2) ? 0 : 1;
                    
                    FIR[0][nFase] = (iLd.fuelType == 1) ? iLd.fuelValue : -1;
                    FIR[1][nFase] = iLd.time;
                    FIR[2][nFase] = (iLd.distanceType == 1) ? iLd.distanceValue : -1;
                    FIR[4][nFase] = oLd.mlw;
                    FIR[9][nFase] = (iLd.fuelType == 0) ? iLd.fuelValue : input->fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iLd.runway.oat;
                    FIR[19][nFase] = iLd.runway.wind;
                    FIR[20][nFase] = iLd.runway.elevation + iLd.initialHeight;
                    FIR[21][nFase] = iLd.runway.elevation;
                    
                    if (input->phasesTypes[nFase - 1] == 2 || input->phasesTypes[nFase - 1] == 4)
                        FIR[21][nFase - 1] = FIR[20][nFase];
                    break;
                    
                case 6:
                    iTi = *(struct input_taxiin*)input->phases[nFase];
                    iLd = *(struct input_landing*)input->phases[nFase - 1];
                    
                    FII[0][nFase] = 2;
                    FII[7][nFase] = iTi.antiicing;
                    FII[10][nFase] = iTi.ecs;
                    FII[12][nFase] = iTi.fuelTaken;
                    
                    FIR[0][nFase] = (iTi.fuelType == 1) ? iTi.fuelValue : -1;
                    FIR[1][nFase] = iTi.time;
                    FIR[2][nFase] = -1;
                    FIR[9][nFase] = (iTi.fuelValue == 0) ? iTi.fuelValue : input->fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = iLd.runway.oat;
                    FIR[20][nFase] = FIR[21][nFase] = iLd.runway.elevation;
                    break;
                    
                case 7:
                    iHl = *(struct input_holding*)input->phases[nFase];
                    if (k < input->sectors[i].numPhases - 1 && input->phasesTypes[nFase + 1] == 5)
                        iLd = *(struct input_landing*)input->phases[nFase + 1];
                    else if (k > input->sectors[i].numPhases && input->phasesTypes[nFase - 1] == 1)
                        iTk = *(struct input_takeoff*)input->phases[nFase - 1];
                    
                    FII[0][nFase] = 42;
                    FII[1][nFase] = getCodTypeCliCruDes(input->dbPathPlanes, input->plane.afm, "CRUCERO", iHl.type);
                    FII[2][nFase] = (iHl.typeAltitude == 1) ? 2 : (iHl.typeAltitude == 2) ? 1 : 0;
                    FII[3][nFase] = iHl.cruisinglevels;
                    FII[7][nFase] = iHl.antiicing;
                    FII[10][nFase] = iHl.ecs;
                    
                    FIR[0][nFase] = -1;
                    FIR[1][nFase] = iHl.time;
                    FIR[2][nFase] = -1;
                    FIR[9][nFase] = iHl.fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[13][nFase] = (input->internalconfig.airdrop == 1) ? iHl.loadLaunched : 0;
                    FIR[14][nFase] = -1;
                    FIR[15][nFase] = -1;
                    FIR[18][nFase] = iHl.isa;
                    FIR[19][nFase] = iHl.wind;
                    if (iHl.typeAltitude == 0)
                        FIR[20][nFase] = FIR[21][nFase] = iHl.altitude;
                    else if (iHl.typeAltitude == 3) {
                        if (k < input->sectors[i].numPhases - 1 && input->phasesTypes[nFase + 1] == 5) {
                            FIR[20][nFase] = FIR[21][nFase] = iHl.altitude + iLd.runway.elevation;
                            if (iLd.initialHeight + iLd.runway.elevation != FIR[20][nFase])
                                iLd.initialHeight = FIR[20][nFase] - iLd.runway.elevation;
                        } else if (k > input->sectors[i].numPhases && input->phasesTypes[nFase - 1] == 1)
                            FIR[20][nFase] = FIR[21][nFase] = iLd.initialHeight + iTk.runway.elevation;
                        else
                            FIR[20][nFase] = FIR[21][nFase] = iLd.initialHeight;
                    } else {
                        FIR[14][nFase] = (iHl.altitude > 0) ? iHl.altitude : -1;
                        FIR[15][nFase] = (iHl.altitude2 > 0) ? iHl.altitude2 : -1;
                    }
                    
                    if (input->phasesTypes[nFase - 1] == 2 || input->phasesTypes[nFase - 1] == 4)
                        FIR[21][nFase - 1] = FIR[20][nFase];
                    break;
                    
                case 8:
                    iGa = *(struct input_goaround*)input->phases[nFase];
                    //misAux = sectores[i-1];
                    
                    FII[0][nFase] = 21;
                    FII[7][nFase] = iGa.antiicing;
                    FII[10][nFase] = iGa.ecs;
                    FII[12][nFase] = nFase + 1 - (input->sectors[i - 1].numPhases - input->sectors[i].start);
                    FII[13][nFase] = (iGa.distanceType == 2) ? 0 : 1;
                    
                    FIR[0][nFase] = (iGa.fuelType == 1) ? iGa.fuelValue : -1;
                    FIR[1][nFase] = iGa.time;
                    FIR[2][nFase] = (iGa.distanceType == 1) ? iGa.distanceValue : -1;
                    FIR[9][nFase] = (iGa.fuelType == 0) ? iGa.fuelValue : input->fffactor;
                    FIR[11][nFase] = input->plane.avdi2;
                    FIR[12][nFase] = input->plane.avdi1;
                    FIR[18][nFase] = FIR[18][nFase-1];
                    FIR[20][nFase] = FIR[21][nFase - (input->sectors[i - 1].numPhases - input->sectors[i].start)];
                    FIR[21][nFase] = FIR[20][nFase] + iGa.heightGained;
                    break;
                default:
                    break;
            }
            nFase ++;
        }
    }
    
    IERR = MISS(input->path, input->file, VII, VIR, *SII, *SIR, *GII, *GIR, *FII, *FIR, VOI, VOR, *SOR, *GOR, *FOI, *FOR);
    
    if (IERR != 0)
        return IERR;
    else {
        output->oew = calcOew(input->internalconfig, input->externalconfig);
        output->payloadFirstSector = SOR[6][0];
        output->fuelLoaded = VOR[6];
        output->rampWeight = FOR[3][0];
        output->distance = VOR[2];
        output->time = VOR[1];
        output->fuelBurnt = VOR[0];
        output->fuelReserve = VOR[7];
	output->fuelExtra = VOR[10];
        
        output->numSectors = VII[0];
        output->numGroups = VII[1];
        output->numPhases = 0;
        
        for (long z = 0; z < output->numGroups; z ++) {
            output->groups[z].f = GOR[0][z];
            output->groups[z].t = GOR[1][z];
            output->groups[z].d = GOR[2][z];
        }
        
        long numFase = 0;
        for (long x = 0; x < output->numSectors; x ++) {
            if (x < output->numSectors - 1) {
                switch (SII[1][x]) {
                    case 0:
                        strcpy(output->sectors[x].maximum, "None");
                        break;
                    case 1:
                        strcpy(output->sectors[x].maximum, "Maximum Payload");
                        break;
                    case 2:
                        strcpy(output->sectors[x].maximum, "Maximum Fuel");
                        break;
                    case 3:
                        strcpy(output->sectors[x].maximum, "Maximum Payload and Fuel");
                        break;
                    case 4:
                        strcpy(output->sectors[x].maximum, "Maximum Fuel and Payload");
                        break;
                    default:
                        break;
                }
            }
            
            strcpy(output->sectors[x].sectorName, input->sectors[x].sectorName);
            output->sectors[x].blockF = SOR[0][x];
            output->sectors[x].blockT = SOR[1][x];
            output->sectors[x].d = SOR[2][x];
            output->sectors[x].payload = SOR[6][x];
            output->sectors[x].temp = FIR[18][0];
            
            output->sectors[x].numPhases = input->sectors[x].numPhases;
            
            for (long y = 0; y < input->sectors[x].numPhases; y++) {
                output->phases[output->numPhases].fffactor = FIR[9][numFase];
                output->phases[output->numPhases].f = FOR[0][numFase];
                output->phases[output->numPhases].initialAltitude = FOR[6][numFase];
                output->phases[output->numPhases].finalAltitude = FOR[7][numFase];
                output->phases[output->numPhases].t = FOR[1][numFase];
                output->phases[output->numPhases].d = FOR[2][numFase];
                output->phases[output->numPhases].initialWeight = FOR[3][numFase];
                output->phases[output->numPhases].initialAirspeed = FOR[10][numFase];
                output->phases[output->numPhases].finalAirspeed = FOR[11][numFase];
                output->phases[output->numPhases].wind = FIR[19][numFase];
                output->phases[output->numPhases].temp = FIR[18][numFase];
                
                switch (input->phasesTypes[numFase]) {
                    case 0:
                        strcpy(output->phases[output->numPhases].phaseName, "Taxi-Out");
                        break;
                    case 1:
                        strcpy(output->phases[output->numPhases].phaseName, "Takeoff");
                        output->sectors[x].tow = FOR[3][numFase];
                        break;
                    case 2:
                        strcpy(output->phases[output->numPhases].phaseName, "Climb");
                        break;
                    case 3:
                        strcpy(output->phases[output->numPhases].phaseName, "Cruise");
                        break;
                    case 4:
                        strcpy(output->phases[output->numPhases].phaseName, "Descent");
                        break;
                    case 5:
                        strcpy(output->phases[output->numPhases].phaseName, "Land");
                        output->sectors[x].lw = FOR[3][numFase];
                        break;
                    case 6:
                        strcpy(output->phases[output->numPhases].phaseName, "Taxi-In");
                        break;
                    case 7:
                        strcpy(output->phases[output->numPhases].phaseName, "Holding");
                        break;
                    case 8:
                        strcpy(output->phases[output->numPhases].phaseName, "Go-Around");
                        break;
                    default:
                        break;
                }
                
                if (numFase > 0 && FIR[18][numFase] != FIR[18][numFase - 1])
                    output->sectors[x].temp = 1000;
                
                numFase ++;
                output->numPhases ++;
            }
            
            strcpy(output->phases[output->numPhases].phaseName, input->sectors[x].sectorName);
            output->phases[output->numPhases].f = output->sectors[x].blockF;
            output->phases[output->numPhases].t = output->sectors[x].blockT;
            output->phases[output->numPhases].d = output->sectors[x].d;
            output->phases[output->numPhases].initialWeight = 0;
            output->phases[output->numPhases].initialAltitude = 0;
            output->phases[output->numPhases].finalAltitude = 0;
            output->phases[output->numPhases].initialAirspeed = 0;
            output->phases[output->numPhases].finalAirspeed = 0;
            output->phases[output->numPhases].temp = 0;
            output->phases[output->numPhases].wind = 0;
            output->phases[output->numPhases].fffactor = 0;
            
            output->numPhases ++;
        }
        
        strcpy(output->phases[output->numPhases].phaseName, input->missionName);
        output->phases[output->numPhases].f = output->fuelBurnt;
        output->phases[output->numPhases].t = output->time;
        output->phases[output->numPhases].d = output->distance;
        output->phases[output->numPhases].initialWeight = 0;
        output->phases[output->numPhases].initialAltitude = 0;
        output->phases[output->numPhases].finalAltitude = 0;
        output->phases[output->numPhases].initialAirspeed = 0;
        output->phases[output->numPhases].finalAirspeed = 0;
        output->phases[output->numPhases].temp = 0;
        output->phases[output->numPhases].wind = 0;
        output->phases[output->numPhases].fffactor = 0;
        
        output->numPhases ++;
    }
    
    return IERR;
}

void errorMessageTakeoff(int error, char *msg)
{
    switch (error) {
        case 10:
            strcpy(msg, "Take Off not possible... MTOW < OEW");
            break;
        case 20:
            strcpy(msg, "Take Off not possible... ATOW > MTOW");
            break;
        case 30:
            strcpy(msg, "Take Off not possible... ATOW < OEW");
            break;
        case 100:
            strcpy(msg, "AFM not included in the Data Base");
            break;
        case 102:
            strcpy(msg, "Takeoff general data file can not be opened");
            break;
        case 104:
            strcpy(msg, "Military take off data file can not be opened");
            break;
        case 106:
            strcpy(msg, "Tactical take off data file can not be opened");
            break;
        case 108:
            strcpy(msg, "Civil type take off data file can not be opened");
            break;
        case 110:
            strcpy(msg, "Invalid flap deflection");
            break;
        case 114:
            strcpy(msg, "None information available with ice accreted");
            break;
        case 120:
            strcpy(msg, "Take off data not available for required runway surface");
            break;
        case 122:
            strcpy(msg, "Invalid CBR value");
            break;
        case 130:
            strcpy(msg, "RWY length not valid.");
            break;
        case 150:
            strcpy(msg, "Invalid Wind factors");
            break;
        case 152:
            strcpy(msg, "Invalid safety margin for runway length");
            break;
        case 154:
            strcpy(msg, "Invalid obstacle clearance height");
            break;
        case 156:
            strcpy(msg, "Invalid obstacle position (distance or height).");
            break;
        case 158:
            strcpy(msg, "Invalid obstacle-profile data.");
            break;
        case 160:
            strcpy(msg, "Obstacles data out of AFM chart bounds");
            break;
        case 210:
            strcpy(msg, "Airfield pressure-altitude out of bound");
            break;
        case 220:
            strcpy(msg, "Airfield ambient temperature out of bound");
            break;
        case 230:
            strcpy(msg, "Invalid airfield ambient temperature for a takeoff with engine anti-icing ON");
            break;
        case 240:
            strcpy(msg, "Wind value out of bound");
            break;
        case 242:
            strcpy(msg, "XW value out of bound");
            break;
        case 250:
            strcpy(msg, "Runway slope out of bound");
            break;
        case 260:
            strcpy(msg, "Drag Index value out of bound");
            break;
        case 270:
            strcpy(msg, "Invalid input data for climb gradient or rate of climb");
            break;
        default:
            snprintf(msg, 200, "Error: %d. A major error was detected during execution of takeoff performance software. Please contact Airbus Military Operations Support", error);
            break;
    }
}

void errorMessageLanding(int error, char *msg)
{
    switch (error) {
        case 10:
            strcpy(msg, "Landing not possible... MLW < OEW");
            break;
        case 20:
            strcpy(msg, "Landing not possible... ALW > MLW");
            break;
        case 30:
            strcpy(msg, "Landing not possible... ALW < OEW");
            break;
        case 100:
            strcpy(msg, "AFM not included in the Data Base");
            break;
        case 102:
            strcpy(msg, "Landing general data file can not be opened");
            break;
        case 104:
            strcpy(msg, "Military landing data file can not be opened");
            break;
        case 106:
            strcpy(msg, "Tactical landing data file can not be opened");
            break;
        case 108:
            strcpy(msg, "Civil type landing data file can not be opened");
            break;
        case 110:
            strcpy(msg, "Invalid flap deflection");
            break;
        case 112:
            strcpy(msg, "Civil landing with reverse thrust not available");
            break;
        case 114:
            strcpy(msg, "None information available with ice accreted");
            break;
        case 116:
            strcpy(msg, "Tactical landing can not be conducted with ice accreted &/or strong crosswind. Try again with normal landing");
            break;
        case 120:
            strcpy(msg, "Landing data not available for required runway surface");
            break;
        case 122:
            strcpy(msg, "Invalid CBR value");
            break;
        case 130:
            strcpy(msg, "RWY length not valid.");
            break;
        case 150:
            strcpy(msg, "Invalid Wind factors");
            break;
        case 152:
            strcpy(msg, "Invalid safety margin for runway length");
            break;
        case 210:
            strcpy(msg, "Airfield pressure-altitude out of bound");
            break;
        case 220:
            strcpy(msg, "Airfield ambient temperature out of bound");
            break;
        case 230:
            strcpy(msg, "Invalid airfield ambient temperature for a landing with engine anti-icing ON");
            break;
        case 240:
            strcpy(msg, "Wind value out of bound");
            break;
        case 242:
            strcpy(msg, "XW value out of bound");
            break;
        case 250:
            strcpy(msg, "Runway slope out of bound");
            break;
        case 260:
            strcpy(msg, "Drag Index value out of bound");
            break;
        case 270:
            strcpy(msg, "Invalid input data for climb gradient or rate of climb");
            break;
        default:
            snprintf(msg, 200, "Error: %d. A major error was detected during execution of landing performance software. Please contact Airbus Military Operations Support", error);
            break;
    }
}

void errorMessageMision(int error, char *msg)
{
    switch (error) {
        case 1010:
            strcpy(msg, "A climb or descent phase does not exist");
            break;
        case 1040:
        case 1042:
            strcpy(msg, "Maximum cabin rate of descent is exceeded");
            break;
        case 1110:
            strcpy(msg, "Selected climb, cruise or descent type not found");
            break;
        case 1120:
            strcpy(msg, "Performance data not available for required case (DI, A/I, ice...)");
            break;
        case 1125:
            strcpy(msg, "Invalid data for cruise altitude option");
            break;
        case 1140:
            strcpy(msg, "Invalid altitude data");
            break;
        case 1141:
            strcpy(msg, "Final altitude of a phase is limited by ceiling and it is below the initial altitude");
            break;
        case 1148:
            strcpy(msg, "Wind value out of bound");
            break;
        case 1162:
            strcpy(msg, "Fuel flow increase percentage out of bound");
            break;
        case 1190:
            strcpy(msg, "Value of minimum rate of climb at top of climb out of bound");
            break;
        case 1192:
            strcpy(msg, "Value of cabin rate of descent not valid");
            break;
        case 1195:
            strcpy(msg, "Maximum number of navigation points is exceeded");
            break;
        case 1196:
            strcpy(msg, "Navigation points are not ordered");
            break;
        case 1210:
            strcpy(msg, "Altitude out of bound");
            break;
        case 1215:
            strcpy(msg, "Calculation limits of aircrafts gross weight are exceeded");
            break;
        case 1220:
            strcpy(msg, "Ambient temperature out of bound");
            break;
        case 1230:
            strcpy(msg, "Ambient temperature out of bound with engine anti-icing ON");
            break;
        case 1260:
            strcpy(msg, "Drag index value out of bound");
            break;
        case 2001:
        case 2002:
        case 2003:
        case 2004:
        case 2005:
            snprintf(msg, 200, "Mission can not be accomplished. Landing weight in sector %d is always greater than MLW", error - 2000);
            break;
        case 2010:
        case 2020:
            strcpy(msg, "Mission can not be accomplished. Fuel required exceeds the maximum allowable");
            break;
        case 2014:
            strcpy(msg, "Maximum P/L and fuel option can not be selected in this case because MTOW is lesser than MZFW");
            break;
        case 2022:
            strcpy(msg, "Mission can not be calculated because the fuel required exceeds the maximum allowable");
            break;
        case 2030:
            strcpy(msg, "Mission can not be calculated because the solution is not unique");
            break;
        case 2101:
            strcpy(msg, "Redundant data in a cruise or holding phase");
            break;
        case 2110:
            strcpy(msg, "Invalid number of sectors");
            break;
        case 2112:
            strcpy(msg, "Invalid sector global data");
            break;
        case 2114:
            strcpy(msg, "Invalid number of phases");
            break;
        case 2116:
            strcpy(msg, "There is a sector without phases");
            break;
        case 2117:
            strcpy(msg, "Maximum number of phases is exceeded. Try to simplify the mission profile");
            break;
        case 2118:
            strcpy(msg, "Maximum number of cruise altitudes to optimize the exceeded");
            break;
        case 2122:
            strcpy(msg, "If varius cruise altitudes have to be optimized, the parameter to minimize (time or fuel) has to be the same");
            break;
        case 2124:
            strcpy(msg, "Mission profile too complicated for optimization. Try to simplify the mission profile");
            break;
        case 2125:
            strcpy(msg, "Invalid data for cruise altitude option");
            break;
        case 2130:
            strcpy(msg, "Empty weight (OEW) not defined. Select an internal configuration");
            break;
        case 2132:
            strcpy(msg, "MZFW value (operation type) for first Take Off not define or too low");
            break;
        case 2134:
            strcpy(msg, "MTOW value (operation type) for first Take Off not define or too low");
            break;
        case 2136:
            strcpy(msg, "Maximum fuel capacity not defined");
            break;
        case 2140:
            strcpy(msg, "Load to be launched has to be reduced. CAPS can not do it because there is more than one launching phases");
            break;
        case 2160:
            strcpy(msg, "Fuel, time or distance data in a taxi, Take Off, go-around or landing phase not valid");
            break;
        case 2165:
            strcpy(msg, "Fuel, time or distance data in a group or sector not valid");
            break;
        case 2190:
            strcpy(msg, "Value of minimum rate of climb at top of climb out of bound");
            break;
        case 2192:
            strcpy(msg, "Value of cabin rate of descent not valid");
            break;
        case 2250:
            strcpy(msg, "Resundant data to solve the mission. Review sectors of global data");
            break;
        case 2252:
            strcpy(msg, "Missing data to solve the mission. Review sectors global data. Perhaps a new distance or time data required");
            break;
        default:
            snprintf(msg, 200, "Error: %d. A major error was detected during execution of CAPS. Please contact Airbus Military Operations Support", error);
            break;
    }
}

float calcOew(struct internal_config intConfig, struct stores_external_config extConfig[3])
{
    int oew = 0;
    if (strcmp(intConfig.desig, "") != 0)
        oew = intConfig.oew;
    for (int x = 0; x < 3; x ++) {
        if (strcmp(extConfig[x].store, "") != 0)
            oew += extConfig[x].deltaOEW;
    }
    
    return oew;
}

float calcExternalOew(struct stores_external_config extConfig[3])
{
    int oew = 0;
    for (int x = 0; x < 3; x ++) {
        if (strcmp(extConfig[x].store, "") != 0)
            oew += extConfig[x].deltaOEW;
    }
    
    return oew;
}

int calcAvdi1(struct plane_model plane, struct stores_external_config extConfig[3])
{
    int avdi1 = 0;
    for (int x = 0; x < 3; x ++) {
        if (strcmp(extConfig[x].store, "") != 0)
            avdi1 += extConfig[x].deltaDIOEI;
    }
    avdi1 += plane.basicdi;
    
    return avdi1;
}

int calcAvdi2(struct plane_model plane, struct stores_external_config extConfig[3])
{
    int avdi1 = 0;
    for (int x = 0; x < 3; x ++) {
        if (strcmp(extConfig[x].store, "") != 0)
            avdi1 += extConfig[x].deltaDIAEO;
    }
    avdi1 += plane.basicdi;
    
    return avdi1;
}

float calcCbr(int state)
{
    if (state == 0) return 0;
    else return 7 - (state - 1);
}

float calcWind(float wind, float direction, float orientation)
{
    return wind * cosf(3.14159265f / 180.f * (direction - orientation));
}

float calcXWind(float wind, float direction, float orientation)
{
    return fabsf(wind * sinf(3.14159265f / 180.f * (direction - orientation)));
}

float getIntergrad(float g0, float g100, float g200, int di1)
{
    if (di1 <= 100)
        return g0 + (g100 - g0) * di1 / (100 - 0);
    else
        return g100 + (g200 - g100) * di1 / (200 - 100);
}

float calcFuel(struct runway rw, struct plane_model plane, struct internal_config intConfig, struct stores_external_config extConfig[3], float fixedFuel, struct infofuel f, float errorFuel)
{    
    int fuel = plane.basicfuel;
    for (int x = 0; x < 3; x ++) {
        if (strcmp(extConfig[x].store, "") != 0)
            fuel += extConfig[x].fuelExt;
    }
    fuel += intConfig.fuelint;
    
    float densidad = 0;
    
    if (fixedFuel == -1) {
        densidad = f.densidadini + ((rw.oat - f.tempini) / (f.tempfin - f.tempini)) * (f.densidadfin - f.densidadini);
    } else
        densidad = fixedFuel;
    
    return densidad * (fuel - errorFuel);
}

float calcMaxFuel(int valPl, struct input_takeoff infoTakeoff, struct input_taxiout infoTaxiOut, float fuelCalculated, float oew)
{
    if (strcmp(infoTakeoff.operation.afm, "") != 0) {
        int mtowSeleccionado, mzfwSeleccionado;
        float valor, valorMaximo = 9999999;
        
        if (infoTakeoff.operation.mtowalt > 0) {
            mtowSeleccionado = infoTakeoff.operation.mtowalt;
            mzfwSeleccionado = infoTakeoff.operation.mzfwalt;
        } else {
            mtowSeleccionado = infoTakeoff.operation.mtow;
            mzfwSeleccionado = infoTakeoff.operation.mzfw;
        }
        
        if (mtowSeleccionado == 0 || fuelCalculated == 0 || infoTakeoff.operation.mrw == 0)
            return 0;
        
        valor = fuelCalculated;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        valor = infoTakeoff.operation.mrw - oew - valPl;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        valor = mtowSeleccionado - oew - valPl + infoTaxiOut.fuelValue;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        return valorMaximo;
    }
    
    return 0;
}

float calcMaxPl(int valFuel, struct input_takeoff infoTakeoff, struct input_taxiout infoTaxiOut, float oew)
{
    if (strcmp(infoTakeoff.operation.afm, "") != 0) {
        int mtowSeleccionado, mzfwSeleccionado, valor, valorMaximo = 9999999;
        
        if (infoTakeoff.operation.mtowalt > 0) {
            mtowSeleccionado = infoTakeoff.operation.mtowalt;
            mzfwSeleccionado = infoTakeoff.operation.mzfwalt;
        } else {
            mtowSeleccionado = infoTakeoff.operation.mtow;
            mzfwSeleccionado = infoTakeoff.operation.mzfw;
        }
        
        if (mtowSeleccionado == 0 || mzfwSeleccionado == 0 || infoTakeoff.operation.mrw == 0)
            return 0;
        
        valor = mzfwSeleccionado - oew;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        valor = infoTakeoff.operation.mrw - oew - valFuel;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        valor = mtowSeleccionado - oew - valFuel + infoTaxiOut.fuelValue;
        if (valor < valorMaximo)
            valorMaximo = valor;
        
        return valorMaximo;
    }
    
    return 0;
}

float pressure(float alt)
{
    return 1013.25 * pow((1 - 0.0000225569 * alt *0.3048), 5.2558797);
}

float pressAlt(float press)
{
    return (1 / (0.0000225569 * 0.3048)) * (1 - pow((press / 1013.25),0.19026));
}

float calcTrim(float cg, int numberTrimPoints, struct trim_point trimLimits[10])
{
    float trim = 0;
    for (int x = 0; x < numberTrimPoints - 1; x ++) {
        if (cg >= trimLimits[x].cg && cg <= trimLimits[x + 1].cg) {
            float m = (trimLimits[x].trim - trimLimits[x + 1].trim) / (trimLimits[x].cg - trimLimits[x + 1].cg);
            float n = trimLimits[x].trim - trimLimits[x].cg * m;
            trim = cg * m + n;
            break;
        }
    }
    
    return trim;
}

float calcIsa(float altitude)
{
    return 288.15 - 0.0065 * altitude;
}
