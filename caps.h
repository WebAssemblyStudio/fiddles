#ifndef LIB_CAPS_H
#define LIB_CAPS_H

#include "data.h"

/* Same limit in FORTRAN */
#define TO_VII_LEN 20
#define TO_VIR_LEN 70
#define TO_VOI_LEN 25
#define TO_VOR_LEN 200

#define SC_VII_LEN 20
#define SC_VIR_LEN 35
#define SC_VOI_LEN 6
#define SC_VOR_LEN 60
#define SCCRE_VIR_LEN 45

#define LD_VII_LEN 20
#define LD_VIR_LEN 70
#define LD_VOI_LEN 25
#define LD_VOR_LEN 200

#define MS_VII_LEN 10
#define MS_VIR_LEN 30
#define MS_SSII_ROW 5
#define MS_SSII_COL 5
#define MS_SSIR_ROW 20
#define MS_SSIR_COL 5
#define MS_GGII_ROW 5
#define MS_GGII_COL 6
#define MS_GGIR_ROW 5
#define MS_GGIR_COL 6
#define MS_FFII_ROW 20
#define MS_FFII_COL 60
#define MS_FFIR_ROW 35
#define MS_FFIR_COL 60
#define MS_VVOI_LEN 6
#define MS_VVOR_LEN 20
#define MS_SSOR_ROW 10
#define MS_SSOR_COL 5
#define MS_GGOR_ROW 3
#define MS_GGOR_COL 6
#define MS_FFOI_ROW 6
#define MS_FFOI_COL 60
#define MS_FFOR_ROW 60
#define MS_FFOR_COL 60

long FARTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long MILTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long TACTO(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
// VOR[ALT MIN | ALT MAX | V2VS MIN | V2VS MAX]
long FARTO_LIM(const char *PVIC, const char *PVID, float *VOR);
long MILTO_LIM(const char *PVIC, const char *PVID, float *VOR);

long SCCLI(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long SCCRU(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long SCCRI(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long SCCRE(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
long SCDES(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);

long LAND(const char *PVIC, const char *PVID, long *VII, float *VIR, long *VOI, float *VOR);
// VII[MIL TYPE] VOR[ALT MIN | ALT MAX]
long LAND_LIM(const char *PVIC, const char *PVID, long *VII, float *VOR);

long MISS(const char *PVIC, const char *PVID, long *VII, float *VIR, long *SSII, float *SSIR, long *GGII, float *GGIR, 
		long *FFII, float *FFIR, long *VVOI, float *VVOR, float *SSOR, float *GGOR, long *FFOI, float *FFOR);

long calc_takeoff (struct input_takeoff *input, struct output_takeoff *output);
long calc_climb (struct input_climb *input, struct output_climb *output);
long calc_cruise (struct input_cruise *input, struct output_cruise *output);
long calc_descent (struct input_descent *input, struct output_descent *output);
long calc_landing (struct input_landing *input, struct output_landing *output);
long calc_mission (struct input_mission *input, struct output_mission *output);

void errorMessageTakeoff(int error, char* msg);
void errorMessageLanding(int error, char* msg);
void errorMessageMision(int error, char* msg);

float calcOew(struct internal_config intConfig, struct stores_external_config extConfig[3]);
float calcExternalOew(struct stores_external_config extConfig[3]);
int calcAvdi1(struct plane_model plane, struct stores_external_config extConfig[3]);
int calcAvdi2(struct plane_model plane, struct stores_external_config extConfig[3]);
float calcCbr(int state);
float calcWind(float wind, float direction, float orientation);
float calcXWind(float wind, float direction, float orientation);
float getIntergrad(float g0, float g100, float g200, int di1);
float calcFuel (struct runway rw, struct plane_model plane, struct internal_config intConfig, struct stores_external_config extConfig[3], float fixedFuel, struct infofuel f, float errorFuel);
float calcMaxFuel (int valPl, struct input_takeoff infoTakeoff, struct input_taxiout infoTaxiOut, float fuelCalculated, float oew);
float calcMaxPl (int valFuel, struct input_takeoff infoTakeoff, struct input_taxiout infoTaxiOut, float oew);
float pressure (float alt);
float pressAlt (float press);
float calcTrim (float cg, int numberTrimPoints, struct trim_point trimLimits[10]);
float calcIsa(float altitude);

#endif /* LIB_CAPS_H */
