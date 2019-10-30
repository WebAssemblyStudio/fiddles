#ifndef LIB_DATA_H
#define LIB_DATA_H

struct altitude {
    char afm[10];
    char oper[5];
    int maxAlt;
};

struct obstacle {
    float height;
    float distance;
};

struct obstacles {
    int numobstacles;
    struct obstacle obstacles[10];
};

struct flap {
    char afm[10];
    char flapNum[5];
    char flapCh[10];
};

struct law {
    char afm[10];
    char fase[10];
    int type;
    char description[100];
    char acronyms[20];
};

struct station {
    char desig[10];
    char station[30];
};

struct internal_config {
    char desig[10];
    char configuration[50];
    int oew;
    int fuelint;
    int airdrop;
};

struct stores_external_config {
    char desig[10];
    char station[30];
    char store[50];
    int deltaOEW;
    int fuelExt;
    int deltaDIAEO;
    int deltaDIOEI;
};

struct trim_point {
    float cg;
    float trim;
};

struct plane_model {
    char afm[10];
    char plane[20];
    char desig[10];
    int basicdi;
    int basicfuel;
    char description[100];
    int oew;
    float avdi1;
    float avdi2;
    int numberTrimPoints;
    int ecs;
    struct trim_point trimLimits[10];
};

struct operation {
    char afm[10];
    char oper[5];
    char opertype[10];
    int mrw;
    int mtow;
    int mlw;
    int mzfw;
    int mgw;
    int mtowunp;
    int mlwunp;
    int mtowalt;
    int mzfwalt;
};

struct takeoff {
    char afm[10];
    char oper[5];
    char takeoffType[10];
    char flap[10];
    char takeoffTitu[20];
    char v1crit[5];
    float wftail;
    float wfhead;
    float suplement;
    float gradi0;
    float gradi100;
    float gradi200;
    int obstaclear;
    int rwymargin;
    int codflap;
    float minGrad;
};

struct landing {
    char afm[10];
    char oper[5];
    char landingType[10];
    char flap[10];
    char landingtitu[15];
    float wftail;
    float wfhead;
    float rwymargindes;
    float rwymarginalt;
    float gradi0;
    float gradi100;
    float gradi200;
    int codflap;
    float minGrad;
};

struct infofuel {
    float tempini;
    float tempfin;
    float densidadini;
    float densidadfin;
};

struct runway {
    char icao[5];
    char type[10];
    char rwy[10];
    int tora;
    int asda;
    int toda;
    float slope;
    int elevation;
    float trueBearing;
    int condition;
    int oat;
    float wind;
    float xWind;
    int hardness;
    int smoth;
    int codType;
    struct obstacles obstacles;
    float metar;
};

struct input_taxiout {
    int antiicing;
    int ecs;
    int fuelType;
    float fuelValue;
    float time;
    int optionMaxima;
    float pl;
};

struct input_takeoff {
    struct plane_model plane;
    struct internal_config internalconfig;
    struct stores_external_config externalconfig[3];
    struct takeoff takeoff;
    struct runway runway;
    struct operation operation;
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    int antiskid;
    int antiicing;
    float grossw;
    float heightGained;
    int fuelType;
    float fuelValue;
    float time;
    float cg;
};

struct input_climb {
    struct plane_model plane;
    struct stores_external_config externalconfig[3];
    char oper[5];
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    char type[100];
    int antiicing;
    int ecs;
    float grossw;
    float rcmin;
    float maxcabinalt;
    float fffactor;
    float isa;
    float wind;
    float initialalt;
    float finalalt;
};

struct input_cruise {
    struct plane_model plane;
    struct stores_external_config externalconfig[3];
    char oper[5];
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    char type[100];
    int antiicing;
    int ecs;
    float grossw;
    float rcmin;
    float maxcabinalt;
    float fffactor;
    float isa;
    float wind;
    int typeAltitude;
    float altitude;
    float altitude2;
    int cruisinglevels;
    float fuel;
    float loadLaunched;
    float distance;
    float time;
};

struct input_descent {
    struct plane_model plane;
    struct stores_external_config externalconfig[3];
    char oper[5];
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    char type[100];
    int antiicing;
    int ecs;
    float grossw;
    float maxcabinrate;
    float fffactor;
    float isa;
    float wind;
    float initialalt;
    float finalalt;
};

struct input_landing {
    struct plane_model plane;
    struct internal_config internalconfig;
    struct stores_external_config externalconfig[3];
    struct landing landing;
    struct runway runway;
    struct operation operation;
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    int antiskid;
    int antiicing;
    float grossw;
    int ground;
    int alternative;
    float initialHeight;
    int fuelType;
    float fuelValue;
    float time;
    int distanceType;
    float distanceValue;
    int fuelTaken;
};

struct input_taxiin {
    int antiicing;
    int ecs;
    int fuelType;
    float fuelValue;
    float time;
    int fuelTaken;
};

struct input_holding {
    char type[100];
    int antiicing;
    int ecs;
    float fffactor;
    float isa;
    float wind;
    int typeAltitude;
    float altitude;
    float altitude2;
    int cruisinglevels;
    float loadLaunched;
    float time;
};

struct input_goaround {
    int antiicing;
    int ecs;
    float heightGained;
    int fuelType;
    float fuelValue;
    float time;
    int distanceType;
    float distanceValue;
};

//                      Types of Groups
//
//                        Fuel = 0
//                        Time = 1
//                        Distance = 2

struct input_group {
    char groupName[100];
    int type;
    int initialPhase;
    int finalPhase;
    float value;
};

struct input_sector {
    int numGroups;
    struct input_group groups[6];
    int numPhases;
    char sectorName[100];
    float fuelType;
    float fuelValue;
    float fixed;
    int timeType;
    float timeValue;
    int start;
};

//                      Types of Phases
//
//                        TaxiOut = 0
//                        TakeOff = 1
//                        Climb = 2
//                        Cruise = 3
//                        Descent = 4
//                        Land = 5
//                        TaxiIn = 6
//                        Holding = 7
//                        GoAround = 8

struct input_mission {
    int numSectors;
    struct input_sector sectors[5];
    int numPhases;
    void* phases[60];
    int phasesTypes[60];
    struct plane_model plane;
    struct internal_config internalconfig;
    struct stores_external_config externalconfig[3];
    struct infofuel infoFuel;
    char path[200];
    char file [20];
    char dbPathPlanes[200];
    char missionName[100];
    float gdcFactor;
    float maxcabinalt;
    float rcmin;
    float maxcabinrate;
    int minimumCruisePortion;
    float time;
    float pl;
    float fuel;
    float isa;
    float fffactor;
    float wind;
    float fixedFuelValue;
    float refuelingError;
    int optionMaxima;
};

struct output_takeoff {
    int errMtow;
    float todM;
    float asdM;
    float torM;
    float v1M;
    int fV1M;
    float todA;
    float asdA;
    float torA;
    float v1A;
    int fV1A;
    float mtow;
    //View Runway
    char titleVtod[100];
    char strTor[5];
    int totalRunwayLongitude;
    //View Graphic
    char titleProf[100];
    int numValuesM;
    float valuesXM[100];
    float valuesYM[100];
    int numValuesA;
    float valuesXA[100];
    float valuesYA[100];
    //View Table
    float asdAp;
    float torAp;
    float todAp;
    float tot;
    float toitt;
    float mctA;
    float mctM;
    int accA;
    int accM;
    char grd[20];
    float grdA;
    float grdM;
    char rc[20];
    float rcA;
    float rcM;
    int filterV1A;
    int filterV1M;
    float vrA;
    float vrM;
    float v2A;
    float v2M;
    float vrfA1;
    float vrfM1;
    char vr1[15];
    char vr2[15];
    float vrfA2;
    float vrfM2;
    float vftoA;
    float vftoM;
    float oat[5];
    float wind[3];
    float mtowSen[15];
    int errorMtowSen[15];
    int filterMtowSen[15];
    float trim;
};

struct output_climb {
    int altitudeCompleted;
    float initialWeight;
    float fuel;
    float time;
    float distance;
    float finalWeight;
    float initiaV;
    float finalV;
    float initialTq;
    float finalAlt;
    float rtcClimb;
    char limit[10];
    char ceiling[10];
};

struct output_cruise {
    float initialWeight;
    float fuel;
    float time;
    float distance;
    float finalWeight;
    float initiaAirspeed;
    float finalAirspeed;
    float initialTq;
    float pressureAltitude;
    float altitude;
    float wind;
    float ff;
    float sr;
    float tq;
    char limit[10];
    int error;
};

struct output_descent {
    float initialWeight;
    float fuel;
    float time;
    float distance;
    float initiaV;
    float finalV;
};

struct output_landing {
    float mlw;
    float alw;
    float lflm;
    float lgrm;
    float ldm;
    float lfla;
    float lgra;
    float lda;
    float ldaValue;
    //View Runway
    char titleVld[100];
    float totalRunwayLongitude;
    float ld;
    //View Table
    float avlb;
    float gat;
    float mct;
    char lbApp[10];
    float appm;
    float appa;
    char vmanf[5];
    char vthf[5];
    char gaf[7];
    float vmana;
    float vappa;
    float vtha;
    float gaa;
    float vmanm;
    float vappm;
    float vthm;
    float gam;
    char vth[5];
    float oat[5];
    float wind[3];
    float ldSen[15];
    int errorLdSen[15];
    int filterLdSen[15];
    float mlwSen[15];
    int errorMlwSen[15];
    int filterMlwSen[15];
};

struct output_phase {
    char phaseName[100];
    int type;
    float f;
    float t;
    float d;
    float initialWeight;
    float initialAltitude;
    float finalAltitude;
    float initialAirspeed;
    float finalAirspeed;
    float temp;
    float wind;
    float fffactor;
};

struct output_sector {
    char sectorName[100];
    char maximum[30];
    int numPhases;
    float blockF;
    float blockT;
    float d;
    float payload;
    float tow;
    float lw;
    float temp;
    float cruise;
};

struct output_group {
    char groupName[100];
    float f;
    float t;
    float d;
};

struct output_mission {
    int numSectors;
    struct output_sector sectors[5];
    int numGroups;
    struct output_group groups[6];
    int numPhases;
    struct output_phase phases[66];
    float oew;
    float payloadFirstSector;
    float fuelLoaded;
    float rampWeight;
    float distance;
    float time;
    float fuelBurnt;
    float fuelReserve;
    float fuelExtra;
};

// Planes database
void setDataBase(char *dbPath, char *query);
float getVersionData(char *dbPath);
void setVersionData(char *dbPath, float version);
void getPlanes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getAfms(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getActivePlanes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void setActivePlane(char *dbPath, char *plane);
struct plane_model getDataPlane(char *dbPath, char *pl);
void getInternalConfig(char *dbPath, char *desig, int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct internal_config getDataInternalConfig(char *dbPath, char *desig, char *configuracion);
void getStationsExternalConfig(char *dbPath, char *desig, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getStoresExternalConfig(char *dbPath, char *desig, char *station, int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct stores_external_config getDataExternalConfig(char *dbPath, char *desig, char *station, char *store);
void getOperations(char *dbPath, char *afm, int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct operation getDataOperation(char *dbPath, char *afm, char *oper, char *operTipo);
void getTakeoffTypes(char *dbPath, char *afm, char *oper, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getLandingTypes(char *dbPath, char *afm, char *oper, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getToTypes(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getToFlaps(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getToV1Crit(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getLaTypes(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getLaFlaps(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getLaPerfMargin(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct takeoff getTakeoffData(char *dbPath, char *afm, char *oper, char *takeofftype, char *flap, char *takeofftitu);
struct landing getLandingData(char *dbPath, char *afm, char *oper, char *landingType, char *flap, char *landingtitu);
void getFlapCh(char *dbPath, char *afm, int flapNum, char *flap);
void getTypeCliCruDes(char *dbPath, char *afm, char *fase, int (*callback)(char *string, void *NotUsed), void *NotUsed);
int getCodTypeCliCruDes(char *dbPath, char *afm, char *fase, char *type);
int getMaxAlt(char *dbPath, char *afm, char *oper);
void getFuelTypes(char *dbPath,int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct infofuel getFuelData(char *dbPath, char *fuelType);
void setPlaneModel(char *dbPath, struct plane_model *pm);
void setAltitude(char *dbPath, struct altitude *al);
void setExternalConfig(char *dbPath, struct stores_external_config *ec);
void setFlaps(char *dbPath, struct flap *fl);
void setLanding(char *dbPath, struct landing *ld);
void setLaw(char *dbPath, struct law *lw);
void setStation(char *dbPath, struct station *st);
void setTakeoff(char *dbPath, struct takeoff *to);
void setWeights(char *dbPath, struct operation *op);

// Airports database
void getIcaos(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getRwy(char *dbPath, char *icao, int (*callback)(char *string, void *NotUsed), void *NotUsed);
struct runway getRunwayData(char *dbPath, char *icao, char *rwy);
void setRunwayData(char *dbPath, struct runway *rw);
void deleteRunway(char *dbPath, char *icao, char *rwy);
void getRunwayTypes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getTypesRWY(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed);
void getRunwayConditionTypes(char *dbPath, char *tipo, int (*callback)(char *string, void *NotUsed), void *NotUsed);
int getCodRunwayCondition(char *dbPath, char *condition, char *type);
void getRunwayCondition(char *dbPath, int codCondition, char *type, char*condition);
int getTypeRunwayCondition(char *dbPath, char *condition);
void setInternalConfig(char *dbPath, struct internal_config *ic);
int getTypeRunwayID(char *dbPath, char *condition);
#endif /* LIB_DATA_H */
