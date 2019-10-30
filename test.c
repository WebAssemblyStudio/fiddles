#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "caps.h"

void print_usage();
void compare_errors(long IERR, long errorFile, long *VOI_AUX, long *VOI_AUX_RES, float *VOR_AUX, float *VOR_AUX_RES, int lenghtVOI, int lenghtVOR, int compare, char *testId, int debug);
void test_limits(char *tablesPath, char *table);
void test_ms_miss();

int main(int argc, char *argv[])
{
    // I/O arrays
    // Take off
    long VII_TO[TO_VII_LEN] = {};
    float VIR_TO[TO_VIR_LEN] = {};
    long VOI_TO[TO_VOI_LEN] = {};
    float VOR_TO[TO_VOR_LEN] = {};
    long VOI_TO_RES[TO_VOI_LEN];
    float VOR_TO_RES[TO_VOR_LEN];
    
    // Climb, Cruise, Descent
    long VII_SC[SC_VII_LEN] = {};
    float VIR_SC[SC_VIR_LEN] = {};
    float VIR_SCCRE[SCCRE_VIR_LEN] = {};
    long VOI_SC[SC_VOI_LEN] = {};
    float VOR_SC[SC_VOR_LEN] = {};
    long VOI_SC_RES[SC_VOI_LEN];
    float VOR_SC_RES[SC_VOR_LEN];
    
    // Landing
    long VII_LAN[LD_VII_LEN] = {};
    float VIR_LAN[LD_VIR_LEN] = {};
    long VOI_LAN[LD_VOI_LEN] = {};
    float VOR_LAN[LD_VOR_LEN] = {};
    long VOI_LAN_RES[LD_VOI_LEN];
    float VOR_LAN_RES[LD_VOR_LEN];
    
    // TODO: Mission
    
    // Test variables
    FILE *input_file;
    char line[100];
    char phase[10] = "";
    char table[10];
    char testId[200];
    long error;
    int i;
    long l;
    float f;
    
    char auxString[6];
    
    long IERR;
    
    int debug = 0;
    char tablesPath[200];
    char filePath[300];
    int compare = 0;
    int state;
    int calculateLimits = 0;
    
    long *VII_AUX;
    float *VIR_AUX;
    long *VOI_AUX;
    float *VOR_AUX;
    long *VOI_AUX_RES;
    float *VOR_AUX_RES;
    
    int lenghtVII;
    int lenghtVIR;
    int lenghtVOR;
    int lenghtVOI;
    
    long (*PerfoPhaseCbk)(const char *, const char *, long *, float *, long *, float *) = NULL;
    
    // Parse arguments
    if (argc < 3 || argc > 6) {
        print_usage();
        return 0;
    }
    // printf("\n----------1---------\n");
    strcpy(tablesPath, argv[1]);
    strcat(tablesPath, "/");
    strcpy(filePath, argv[2]);
    
    if (argc > 3) {
        debug = atoi(argv[3]);
        if (debug < 0 || debug > 1) {
            print_usage();
            return 0;
        }
    }
    // printf("\n----------2---------\n");
    if (argc > 4) {
        compare = atoi(argv[4]);
        if (compare < 0 || compare > 1) {
            print_usage();
            return 0;
        }
    }
    // printf("\n----------3---------\n");
    if (argc == 6) {
        calculateLimits = atoi(argv[5]);
        if (calculateLimits < 0 || calculateLimits > 1) {
            print_usage();
            return 0;
        }
    }
    // printf("\n----------4---------\n");
    // Initialize variables
    state = 0;
    IERR = 0;
    lenghtVII = 0;
    lenghtVIR = 0;
    lenghtVOR = 0;
    lenghtVOI = 0;
  
    
    // Parse file
    input_file = fopen(filePath, "r");
    if (!input_file) {
        printf("ERROR: the file path doesn`t exist\n");
        print_usage();
        return 0;
        // printf("\n----------5---------\n");
    }
    // printf("\n----------6---------\n");
    while (fgets(line, sizeof(line), input_file)) {
        switch (state) {
                case 0:
                if (sscanf(line, "TEST ID = %s", testId) == 1)
                state++;
                // printf("\n----------0.0---------\n");
                break;
                case 1:
                if (sscanf(line, "VID = %s", table) == 1) {
                    char *tmp = strstr(filePath, table);
                    // printf("\n----------0.0.1---------\n");
                    if (tmp) {
                        int i = tmp - filePath;
                        int n = (filePath[i - 1] == 'M')? 3 : 2;
                        strncpy(phase, testId, n);
                        if (n == 2)
                        strncat(phase, &filePath[i + strlen(table)], 1);
                        state++;
                        // printf("\n----------0.0.2---------\n");
                    }
                }
                // printf("\n----------1.1---------\n");
                break;
                case 2:
                if (strcmp(phase, "TOF") == 0 || strcmp(phase, "TOT") == 0 || strcmp(phase, "TOM") == 0 || strcmp(phase, "TOS") == 0) {
                    VII_AUX = VII_TO;
                    VIR_AUX = VIR_TO;
                    VOI_AUX = VOI_TO;
                    VOR_AUX = VOR_TO;
                    VOI_AUX_RES = VOI_TO_RES;
                    VOR_AUX_RES = VOR_TO_RES;
                    lenghtVII = TO_VII_LEN;
                    lenghtVIR = TO_VIR_LEN;
                    lenghtVOI = TO_VOI_LEN;
                    lenghtVOR = TO_VOR_LEN;
                    // printf("\n----------1.1.1---------\n");
                    if (strcmp(phase, "TOF") == 0){
                        // printf("\n----------1.1.2---------\n");
                        PerfoPhaseCbk = &FARTO;
                        
                    }
                    else if (strcmp(phase, "TOT") == 0){
                        // printf("\n----------1.1.2---------\n");
                        PerfoPhaseCbk = &TACTO;
                        
                    }
                    else if (strcmp(phase, "TOM") == 0 || strcmp(phase, "TOS") == 0){
                        // printf("\n----------1.1.3---------\n");
                        PerfoPhaseCbk = &MILTO;
                        
                    }
                } else if (strcmp(phase, "CLB") == 0 || strcmp(phase, "CRU") == 0 || strcmp(phase, "CRI") == 0 || strcmp(phase, "DES") == 0) {
                    VII_AUX = VII_SC;
                    VIR_AUX = VIR_SC;
                    VOI_AUX = VOI_SC;
                    VOR_AUX = VOR_SC;
                    VOI_AUX_RES = VOI_SC_RES;
                    VOR_AUX_RES = VOR_SC_RES;
                    lenghtVII = SC_VII_LEN;
                    lenghtVIR = SC_VIR_LEN;
                    lenghtVOI = SC_VOI_LEN;
                    lenghtVOR = SC_VOR_LEN;
                    // printf("\n----------1.1.4---------\n");
                    if (strcmp(phase, "CLB") == 0){
                        // printf("\n----------1.1.5---------\n");
                        PerfoPhaseCbk = &SCCLI;
                        
                    }
                    else if (strcmp(phase, "CRU") == 0){
                        
                        // printf("\n----------1.1.6---------\n");
                        PerfoPhaseCbk = &SCCRU;
                    }
                    else if (strcmp(phase, "CRI") == 0){
                        // printf("\n----------1.1.7---------\n");
                        PerfoPhaseCbk = &SCCRI;
                    }
                    else if (strcmp(phase, "DES") == 0){
                        // printf("\n----------1.1.8---------\n");
                        PerfoPhaseCbk = &SCDES;
                        
                    }
                } else if (strcmp(phase, "CRE") == 0) {
                    VII_AUX = VII_SC;
                    VIR_AUX = VIR_SCCRE;
                    VOI_AUX = VOI_SC;
                    VOR_AUX = VOR_SC;
                    VOI_AUX_RES = VOI_SC_RES;
                    VOR_AUX_RES = VOR_SC_RES;
                    lenghtVII = SC_VII_LEN;
                    lenghtVIR = SCCRE_VIR_LEN;
                    lenghtVOI = SC_VOI_LEN;
                    lenghtVOR = SC_VOR_LEN;
                    // printf("\n----------1.1.9---------\n");
                    PerfoPhaseCbk = &SCCRE;
                    
                } else if (strcmp(phase, "LDF") == 0 || strcmp(phase, "LDT") == 0 || strcmp(phase, "LDM") == 0) {
                    VII_AUX = VII_LAN;
                    VIR_AUX = VIR_LAN;
                    VOI_AUX = VOI_LAN;
                    VOR_AUX = VOR_LAN;
                    VOI_AUX_RES = VOI_LAN_RES;
                    VOR_AUX_RES = VOR_LAN_RES;
                    lenghtVII = LD_VII_LEN;
                    lenghtVIR = LD_VIR_LEN;
                    lenghtVOI = LD_VOI_LEN;
                    lenghtVOR = LD_VOR_LEN;
                    // printf("\n----------1.1.9---------\n");
                    PerfoPhaseCbk = &LAND;
                    
                }
                if (PerfoPhaseCbk)
                state++;
                // printf("\n----------2.2---------\n");
                break;
                case 3:
                // VII
                if (sscanf(line, "VII(%d) %s %ld", &i, auxString, &l) == 3) {
                    VII_AUX[i - 1] = l;
                    // printf("\n----------2.2---------\n");
                    if (i == lenghtVII)
                    state++;
                    
                    // printf("\n----------2.2.3---------\n");
                }
                // printf("\n----------3.3---------\n");
                break;
                case 4:
                // VIR
                if (sscanf(line, "VIR(%d) %s %f", &i, auxString, &f) == 3) {
                    VIR_AUX[i - 1] = f;
                    if (i == lenghtVIR)
                    state++;
                }
                // printf("\n----------4.4---------\n");
                break;
                case 5:
                // Error
                if (sscanf(line, "OUTPUT DATA %s %ld", auxString, &error) == 2)
                state++;
                // printf("\n----------5.5---------\n");
                break;
                case 6:
                // VOI
                if (sscanf(line, "VOI(%d) %s %ld", &i, auxString, &l) == 3) {
                    VOI_AUX[i - 1] = l;
                    if (i == lenghtVOI)
                    state++;
                }
                // printf("\n----------6.6---------\n");
                break;
                case 7:
                // VOR
                if (sscanf(line, "VOR(%d) %s %f", &i, auxString, &f) == 3) {
                    VOR_AUX[i - 1] = f;
                    if (i == lenghtVOR)
                    state++;
                }
                // printf("\n----------7.7---------\n");
                break;
        }
    }
    
    // Close file
    fclose(input_file);
    // printf("\n----------7---------\n");
    // Error parsing the file
    if (state < 8) {
        printf("[ERROR] parsing: %s, state: %d\n", filePath, state);
        return 0;
    }
    // printf("\n----------8---------\n");
    // Debug
    if (debug || compare) {
        printf("[TEST]: ID=%s PHASE=%s TABLE=%s\n", testId, phase, table);
    }
    // printf("\n----------9---------\n");
    // Phases
    if (PerfoPhaseCbk) {
        // printf("\n----------9.0---------\n");
        // printf("\n----------tablesPath---------: %s", tablesPath);
        // printf("\n----------table     ---------: %s", table);
        // printf("\n----------VII_AUX     ---------: %ld", VII_AUX);
        // printf("\n----------VIR_AUX     ---------: %ld", VIR_AUX);
        // printf("\n----------VOI_AUX_RES     ---------: %ld", VOI_AUX_RES);
        // printf("\n----------VOR_AUX_RES     ---------: %ld", VOR_AUX_RES);
        
        IERR = PerfoPhaseCbk(tablesPath, table, VII_AUX, VIR_AUX, VOI_AUX_RES, VOR_AUX_RES);
        // printf("\n----------9.0.1---------\n");
        compare_errors(IERR, error, VOI_AUX, VOI_AUX_RES, VOR_AUX, VOR_AUX_RES, lenghtVOI, lenghtVOR, compare, testId, debug);
        // printf("\n----------9.1---------\n");
    } else {
        printf("The phase doesn`t exist, check the test file.");
        // printf("\n----------9.2---------\n");
        return 0;
    }
    // printf("\n----------10---------\n");
    // Limits
    if (calculateLimits){
    test_limits(tablesPath, table);
    }
    // printf("\n----------11---------\n");
    return 0;
}

void print_usage()
{
    printf("[test usage]:\n");
    printf("test <arg1> <arg2> <arg3> <arg4> <arg5>\n");
    printf("\t<arg1>: tables folder\n");
    printf("\t<arg2>: test file path\n");
    printf("\t<arg3>: debug arrays: 0 => OFF (default), 1 => ON\n");
    printf("\t<arg4>: show discrepancies: 0 => OFF (default), 1 => ON\n");
    printf("\t<arg5>: compute limits: 0 => OFF (default), 1 => ON\n");
    
    // printf("\n----------12---------\n");
}

void compare_errors(long IERR, long errorFile, long *VOI_AUX, long *VOI_AUX_RES, float *VOR_AUX, float *VOR_AUX_RES, int lenghtVOI, int lenghtVOR, int compare, char *testId, int debug)
{
    // printf("\n----------13---------\n");
    int i;
    int dump;
    int error_counter = 0;
    // tolerance approx 0.1%
    float TOL = 0.001f;
    
    // output integer
    for (i = 0; i < lenghtVOI; i++) {
        dump = debug;
        // printf("\n----------13.1---------\n");
        if (fabs(VOI_AUX[i] -  VOI_AUX_RES[i]) > fabs(TOL * VOI_AUX[i])) {
            // printf("\n----------13.2---------\n");
            error_counter++;
            if (debug == 0 && compare == 1){
                dump = 1;
                // printf("\n----------13.3---------\n");
            }
        }
        if (dump){
            // printf("\n----------13.4---------\n");
            printf("\tVOI[%d]:%ld \t VOI_RES[%d]:%ld\n", i+1, VOI_AUX[i], i+1, VOI_AUX_RES[i]);
        }
        // printf("\n----------13.5---------\n");
    }
    // printf("\n----------14---------\n");
    // output real
    for(i = 0; i < lenghtVOR; i++) {
        dump = debug;
        if (fabs(VOR_AUX[i] - VOR_AUX_RES[i]) > fabs(TOL * VOR_AUX[i])) {
            error_counter++;
            if (debug == 0 && compare == 1)
            dump = 1;
        }
        if (dump)
        printf("\tVOR[%d]:%f \t VOR_RES[%d]:%f\n", i+1, VOR_AUX[i], i+1, VOR_AUX_RES[i]);
    }
    // printf("\n----------15---------\n");
    // check result
    printf("[%s]: ID=%s IERR=[%ld]%ld DIFF=%d\n", (IERR == errorFile && !error_counter)? "PASS" : "FAIL", testId, errorFile, IERR, error_counter);
}

void test_limits(char *tablesPath, char *table)
{
    // printf("\n----------16---------\n");
    long VII[1];
    float VOR[4];
    
    long IERR = FARTO_LIM(tablesPath, table, VOR);
    printf("[FARTO]: %s IERR=%ld, LIMALT=%f, %f, LIMV2: %f, %f\n", table, IERR, VOR[0], VOR[1], VOR[2], VOR[3]);
    // printf("\n----------17---------\n");
    IERR = MILTO_LIM(tablesPath,table, VOR);
    printf("[MILTO]: %s IERR=%ld, LIMALT=%f, %f, LIMV2: %f, %f\n", table, IERR, VOR[0], VOR[1], VOR[2], VOR[3]);
    // printf("\n----------18---------\n");
    VII[0] = 1;
    IERR = LAND_LIM(tablesPath, table, VII, VOR);
    printf("[LAND FAR]: %s IERR=%ld, LIMALT=%f, %f\n", table, IERR, VOR[0], VOR[1]);
    // printf("\n----------19---------\n");
    VII[0] = 2;
    IERR = LAND_LIM(tablesPath, table, VII, VOR);
    printf("[LAND MIL]: %s IERR=%ld, LIMALT=%f, %f\n", table, IERR, VOR[0], VOR[1]);
    // printf("\n----------20---------\n");
}

static void initializei(long *m, int len) {
    
    int i;
    for (i=0; i<len; i++) {
        m[i] = 0;
    }
    // printf("\n----------21---------\n");
}

static void initializef(float *m, int len) {
    
    int i;
    for (i=0; i<len; i++) {
        m[i] = 0.0f;
    }
    // printf("\n----------22---------\n");
}

void test_ms_miss()
{
    // printf("\n----------23---------\n");
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
        // printf("\n----------24---------\n");
    }
    // printf("\n----------25---------\n");
}

