#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "data.h"

//extern void My_DEBUG(const char *str);
void setDataBase(char *dbPath, char *query)
{
	sqlite3 *database;
	sqlite3_stmt *compiledStatement;
	if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
		if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
			while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
			}
			sqlite3_finalize(compiledStatement);
		} else {
			printf("Error whith statement. '%s'", sqlite3_errmsg(database));
			//char tmp[1024];
			//sprintf(tmp, "SQLITE_LOCKED");
			//My_DEBUG(tmp);
		}
		sqlite3_close(database);
	}
}

float getVersionData (char *dbPath) {
    
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    
    float version = 0;
    
    char tmp[1024];
    
    char query[100] = "SELECT Version FROM VersionData;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_double(compiledStatement, 0))
                    version = sqlite3_column_double(compiledStatement, 0);
            }
	    //sprintf(tmp, "VERSION");
            //My_DEBUG(tmp);
            sqlite3_finalize(compiledStatement);
        } else {
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
        }
        
        
        sqlite3_close(database);
    }

    return version;
}

void setVersionData (char *dbPath, float version) {
    
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    
    char query[100] = "UPDATE VersionData SET Version = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_double(compiledStatement, 1, version);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            sqlite3_finalize(compiledStatement);
        } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
        
        sqlite3_close(database);
    }
}


void getPlanes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Plane FROM AVTypes;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_close(database);
    }
    
}

void getAfms(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Distinct AFM FROM AVTypes;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_close(database);
    }
    
}

void getActivePlanes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Plane FROM AVTypes WHERE IsActive = 'true';";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_close(database);
    }
    
}

void setActivePlane(char *dbPath, char *plane)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int existePista = 0;
    char queryAlter[300] = "UPDATE AVTypes SET IsActive = 'true' WHERE Plane = ?";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, plane, -1, SQLITE_TRANSIENT);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        sqlite3_close(database);
    }
}

struct plane_model getDataPlane(char *dbPath, char *pl)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    struct plane_model plane;
    
    char query[200] = "SELECT DISTINCT Plane, AFM, Desig, Basicdi, Basicfuel, Description, ECS FROM AVTypes WHERE Plane = ?;";
    char query2[200] = "SELECT CG, TRIM FROM AVTrimLimits WHERE AFM = ? ORDER BY CG;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, pl, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(plane.plane, (char*) sqlite3_column_text(compiledStatement, 0));
                strcpy(plane.afm, (char*) sqlite3_column_text(compiledStatement, 1));
                strcpy(plane.desig, (char*) sqlite3_column_text(compiledStatement, 2));
                plane.basicdi = sqlite3_column_int(compiledStatement, 3);
                plane.basicfuel = sqlite3_column_int(compiledStatement, 4);
                strcpy(plane.description, (char*) sqlite3_column_text(compiledStatement, 5));
                plane.ecs = sqlite3_column_int(compiledStatement, 6);
                
                if (sqlite3_prepare_v2(database, query2, -1, &compiledStatement2, NULL) == SQLITE_OK) {
                    sqlite3_bind_text(compiledStatement2, 1, plane.afm, -1, SQLITE_TRANSIENT);
                    
                    plane.numberTrimPoints = 0;
                    while (sqlite3_step(compiledStatement2) == SQLITE_ROW) {
                        plane.trimLimits[plane.numberTrimPoints].cg = sqlite3_column_double(compiledStatement2, 0);
                        plane.trimLimits[plane.numberTrimPoints].trim = sqlite3_column_double(compiledStatement2, 1);
                        plane.numberTrimPoints ++;
                    }
                    
                } else
                    printf("Error whith statement. '%s'", sqlite3_errmsg(database));
                sqlite3_finalize(compiledStatement2);
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        sqlite3_finalize(compiledStatement);
        
        sqlite3_close(database);
    }
    return plane;
}

void getInternalConfig(char *dbPath, char *desig, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Configuration FROM AVInternalconfig WHERE Desig = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, desig, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct internal_config getDataInternalConfig(char *dbPath, char *desig, char *configuracion)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    struct internal_config ic;
    
    char query[200] = "SELECT Desig, Configuration, OEW, Fuelint, Airdrop FROM AVInternalconfig WHERE Desig = ? AND Configuration = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, configuracion, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(ic.desig, (char*) sqlite3_column_text(compiledStatement, 0));
                strcpy(ic.configuration, (char*) sqlite3_column_text(compiledStatement, 1));
                ic.oew = sqlite3_column_int(compiledStatement, 2);
                ic.fuelint = sqlite3_column_int(compiledStatement, 3);
                if (strcmp((const char*) sqlite3_column_text(compiledStatement, 4), "YES") == 0)
                    ic.airdrop = 1;
                else
                    ic.airdrop = 0;
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        sqlite3_finalize(compiledStatement);
        
        sqlite3_close(database);
    }
    
    return ic;
}

void getStationsExternalConfig(char *dbPath, char *desig, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Station FROM AVExternalconfig WHERE Desig = ? ORDER BY Station;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, desig, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getStoresExternalConfig(char *dbPath, char *desig, char *station, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Stores FROM AVExternalconfig WHERE Desig = ? AND Station = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, station, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct stores_external_config getDataExternalConfig(char *dbPath, char *desig, char *station, char *store)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    struct stores_external_config sec;
    
    char query[200] = "SELECT DISTINCT Stores, DeltaOEW, Fuelext, DeltaDI_AEO, DeltaDI_OEI FROM AVExternalconfig WHERE Desig = ? AND Station = ? AND Stores = ?";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, station, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, store, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(sec.store, (char*) sqlite3_column_text(compiledStatement, 0));
                sec.deltaOEW = sqlite3_column_int(compiledStatement, 1);
                sec.fuelExt = sqlite3_column_int(compiledStatement, 2);
                sec.deltaDIAEO = sqlite3_column_int(compiledStatement, 3);
                sec.deltaDIOEI = sqlite3_column_int(compiledStatement, 4);
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        sqlite3_finalize(compiledStatement);
        
        sqlite3_close(database);
    }
    
    return sec;
}

void getOperations(char *dbPath, char *afm, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Oper, Opertype FROM AVWeights WHERE AFM = ? ORDER BY Oper;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    char cad[20];
                    strcpy(cad, (char*)sqlite3_column_text(compiledStatement, 0));
                    if (sqlite3_column_text(compiledStatement, 1)) {
                        strcat(cad, " ");
                        strcat(cad, (char*)sqlite3_column_text(compiledStatement, 1));
                    }
                    callback(cad, NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct operation getDataOperation(char *dbPath, char *afm, char *oper, char *operTipo)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[500];
    struct operation op;
    if (operTipo)
        strcpy(query, "SELECT AFM, Oper, Opertype, MRW, MTOW, MLW, MZFW, MGW, MTOWUNP, MLWUNP, MTOWALT, MZFWALT FROM AVWeights WHERE AFM = ? AND Oper = ? AND Opertype = ?;");
    else
        strcpy(query, "SELECT AFM, Oper, Opertype, MRW, MTOW, MLW, MZFW, MGW, MTOWUNP, MLWUNP, MTOWALT, MZFWALT FROM AVWeights WHERE AFM = ? AND Oper = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char*) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (operTipo)
                sqlite3_bind_text(compiledStatement, 3, operTipo, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(op.afm, (char*) sqlite3_column_text(compiledStatement, 0));
                strcpy(op.oper, (char*) sqlite3_column_text(compiledStatement, 1));
                if (sqlite3_column_text(compiledStatement, 2))
                    strcpy(op.opertype, (char*) sqlite3_column_text(compiledStatement, 2));
                else
                    strcpy(op.opertype, "");
                op.mrw = sqlite3_column_int(compiledStatement, 3);
                op.mtow = sqlite3_column_int(compiledStatement, 4);
                op.mlw = sqlite3_column_int(compiledStatement, 5);
                op.mzfw = sqlite3_column_int(compiledStatement, 6);
                op.mgw = sqlite3_column_int(compiledStatement, 7);
                op.mtowunp = sqlite3_column_int(compiledStatement, 8);
                op.mlwunp = sqlite3_column_int(compiledStatement, 9);
                op.mtowalt = sqlite3_column_int(compiledStatement, 10);
                op.mzfwalt = sqlite3_column_int(compiledStatement, 11);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return op;
}

void getTakeoffTypes(char *dbPath, char *afm, char *oper, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Takeofftype FROM AVTakeoff WHERE AFM = ? AND Oper = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char*) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    char *cad = malloc(15 * sizeof(char));
                    if (strcmp((char *) sqlite3_column_text(compiledStatement, 0), "NORM") == 0)
                        strcpy(cad, "Normal");
                    else if (strcmp((char *) sqlite3_column_text(compiledStatement, 0), "TAC") == 0)
                        strcpy(cad, "Tactical AEO");
                    else if (strcmp((char *) sqlite3_column_text(compiledStatement, 0), "TAC CEF") == 0)
                        strcpy(cad, "Tactical CEF");
                    
                    callback(cad, NotUsed);
                    free(cad);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getLandingTypes(char *dbPath, char *afm, char *oper, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Landingtype FROM AVLanding WHERE AFM = ? AND Oper = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char*) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    char *cad = malloc(15 * sizeof(char));
                    if (strcmp((char *) sqlite3_column_text(compiledStatement, 0), "NORM") == 0)
                        strcpy(cad, "Normal");
                    else if (strcmp((char *) sqlite3_column_text(compiledStatement, 0), "TAC") == 0)
                        strcpy(cad, "Tactical");
                    
                    callback(cad, NotUsed);
                    free(cad);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getToTypes(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[100] = "";
    if (takeoffType)
        strcpy(query, "SELECT DISTINCT FLAP, Takeofftitu FROM AVTakeoff WHERE AFM = ? AND Oper = ? AND Takeofftype = ?;");
    else
        strcpy(query, "SELECT DISTINCT FLAP, Takeofftitu FROM AVTakeoff WHERE AFM = ? AND Oper = ?;");
    char query2[100] = "SELECT FLAPch FROM AVFlaps WHERE FLAPnum = ? and AFM = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (takeoffType) {
                if (strcmp(takeoffType, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical AEO") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical CEF") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC CEF", -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                char cad[50] = "";
                strcpy(cad, "Flap");
                int num = sqlite3_column_int(compiledStatement, 0);
                
                if (sqlite3_prepare_v2(database, query2, -1, &compiledStatement2, NULL) == SQLITE_OK) {
                    sqlite3_bind_int(compiledStatement2, 1, num);
                    sqlite3_bind_text(compiledStatement2, 2, (const char*) afm, -1, SQLITE_TRANSIENT);
                    while (sqlite3_step(compiledStatement2) == SQLITE_ROW) {
                        if (sqlite3_column_text(compiledStatement2, 0)) {
                            strcat(cad, " ");
                            strcat(cad, (char*)sqlite3_column_text(compiledStatement2, 0));
                        }
                    }
                }
                sqlite3_finalize(compiledStatement2);
                
                if (sqlite3_column_text(compiledStatement, 1)) {
                    strcat(cad, " ");
                    strcat(cad, (char*)sqlite3_column_text(compiledStatement, 1));
                }
                
                callback(cad, NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getToFlaps(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[300] = "";
    if (takeoffType)
        strcpy(query, "SELECT FLAPch FROM AVFlaps WHERE FLAPnum IN (SELECT DISTINCT FLAP FROM AVTakeoff WHERE AFM = ? AND Oper = ? AND Takeofftype = ?) and AFM = ?;");
    else
        strcpy(query, "SELECT FLAPch FROM AVFlaps WHERE FLAPnum IN (SELECT DISTINCT FLAP FROM AVTakeoff WHERE AFM = ? AND Oper = ?) and AFM = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (takeoffType) {
                if (strcmp(takeoffType, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical AEO") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical CEF") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC CEF", -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, (const char *) afm, -1, SQLITE_TRANSIENT);
            } else
                sqlite3_bind_text(compiledStatement, 3, (const char *) afm, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                char flap[15] = "Flap ";
                strcat(flap, (char*)sqlite3_column_text(compiledStatement, 0));
                callback(flap, NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getToV1Crit(char *dbPath, char *afm, char *oper, char *takeoffType, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[100] = "";
    if (takeoffType)
        strcpy(query, "SELECT DISTINCT Takeofftitu FROM AVTakeoff WHERE AFM = ? AND Oper = ? AND Takeofftype = ?;");
    else
        strcpy(query, "SELECT DISTINCT Takeofftitu FROM AVTakeoff WHERE AFM = ? AND Oper = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (takeoffType) {
                if (strcmp(takeoffType, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical AEO") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeoffType, "Tactical CEF") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC CEF", -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getLaTypes(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[100] = "";
    if (landtype)
        strcpy(query, "SELECT DISTINCT FLAP, Landingtitu FROM AVLanding WHERE AFM = ? AND Oper = ? AND Landingtype = ?;");
    else
        strcpy(query, "SELECT DISTINCT FLAP, Landingtitu FROM AVLanding WHERE AFM = ? AND Oper = ?;");
    char query2[100] = "SELECT FLAPch FROM AVFlaps WHERE FLAPnum = ? and AFM = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (landtype) {
                if (strcmp(landtype, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(landtype, "Tactical") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                char cad[50] = "";
                strcpy(cad, "Flap");
                int num = sqlite3_column_int(compiledStatement, 0);
                
                if (sqlite3_prepare_v2(database, query2, -1, &compiledStatement2, NULL) == SQLITE_OK) {
                    sqlite3_bind_int(compiledStatement2, 1, num);
                    sqlite3_bind_text(compiledStatement2, 2, afm, -1, SQLITE_TRANSIENT);
                    while (sqlite3_step(compiledStatement2) == SQLITE_ROW) {
                        if (sqlite3_column_text(compiledStatement2, 0)) {
                            strcat(cad, " ");
                            strcat(cad, (char*)sqlite3_column_text(compiledStatement2, 0));
                        }
                    }
                }
                sqlite3_finalize(compiledStatement2);
                
                if (sqlite3_column_text(compiledStatement, 1)) {
                    strcat(cad, " ");
                    strcat(cad, (char*)sqlite3_column_text(compiledStatement, 1));
                }
                
                callback(cad, NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getLaFlaps(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[300] = "";
    if (landtype)
        strcpy(query, "SELECT FLAPch FROM AVFlaps WHERE FLAPnum IN (SELECT DISTINCT FLAP FROM AVLanding WHERE AFM = ? AND Oper = ? AND Landingtype = ?) and AFM = ?;");
    else
        strcpy(query, "SELECT FLAPch FROM AVFlaps WHERE FLAPnum IN (SELECT DISTINCT FLAP FROM AVLanding WHERE AFM = ? AND Oper = ?) and AFM = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (landtype) {
                if (strcmp(landtype, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(landtype, "Tactical") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, (const char *) afm, -1, SQLITE_TRANSIENT);
            } else
                sqlite3_bind_text(compiledStatement, 3, (const char *) afm, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                char flap[15] = "Flap ";
                strcat(flap, (char*)sqlite3_column_text(compiledStatement, 0));
                callback(flap, NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getLaPerfMargin(char *dbPath, char *afm, char *oper, char *landtype, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement, *compiledStatement2;
    char query[100] = "";
    if (landtype)
        strcpy(query, "SELECT DISTINCT Landingtitu FROM AVLanding WHERE AFM = ? AND Oper = ? AND Landingtype = ?;");
    else
        strcpy(query, "SELECT DISTINCT Landingtitu FROM AVLanding WHERE AFM = ? AND Oper = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, (const char *) afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            if (landtype) {
                if (strcmp(landtype, "Normal") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(landtype, "Tactical") == 0)
                    sqlite3_bind_text(compiledStatement, 3, "TAC", -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, (const char *) afm, -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                callback((char*)sqlite3_column_text(compiledStatement, 0), NotUsed);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct takeoff getTakeoffData(char *dbPath, char *afm, char *oper, char *takeofftype, char *flap, char *takeofftitu)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[1000];
    struct takeoff to;
    if (takeofftype)
        strcpy(query, "SELECT AVTakeoff.AFM, AVTakeoff.Oper, AVTakeoff.Takeofftype, AVTakeoff.Takeofftitu, AVTakeoff.V1Crit, AVTakeoff.WFtail, AVTakeoff.WFhead, AVTakeoff.RWYmargin, AVTakeoff.Obstaclear, AVTakeoff.Suplement, AVTakeoff.Gradi0, AVTakeoff.Gradi100, AVTakeoff.Gradi200, AVFlaps.FLAPnum, AVFlaps.FLAPch FROM AVTakeoff LEFT OUTER JOIN AVFlaps ON AVTakeoff.FLAP = AVFlaps.FLAPnum AND AVTakeoff.AFM = AVFlaps.AFM WHERE AVTakeoff.AFM = ? AND AVTakeoff.Oper = ? AND AVFlaps.FLAPch = ? AND AVTakeoff.Takeofftitu = ? AND AVTakeoff.Takeofftype = ?;");
    else
        strcpy(query, "SELECT AVTakeoff.AFM, AVTakeoff.Oper, AVTakeoff.Takeofftype, AVTakeoff.Takeofftitu, AVTakeoff.V1Crit, AVTakeoff.WFtail, AVTakeoff.WFhead, AVTakeoff.RWYmargin, AVTakeoff.Obstaclear, AVTakeoff.Suplement, AVTakeoff.Gradi0, AVTakeoff.Gradi100, AVTakeoff.Gradi200, AVFlaps.FLAPnum, AVFlaps.FLAPch FROM AVTakeoff LEFT OUTER JOIN AVFlaps ON AVTakeoff.FLAP = AVFlaps.FLAPnum AND AVTakeoff.AFM = AVFlaps.AFM WHERE AVTakeoff.AFM = ? AND AVTakeoff.Oper = ? AND AVFlaps.FLAPch = ? AND AVTakeoff.Takeofftitu = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, flap, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 4, takeofftitu, -1, SQLITE_TRANSIENT);
            if (takeofftype) {
                if (strcmp(takeofftype, "Normal") == 0) sqlite3_bind_text(compiledStatement, 5, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeofftype, "Tactical AEO") == 0) sqlite3_bind_text(compiledStatement, 5, "TAC", -1, SQLITE_TRANSIENT);
                else if (strcmp(takeofftype, "Tactical CEF") == 0) sqlite3_bind_text(compiledStatement, 5, "TAC CEF", -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(to.afm, (char*) sqlite3_column_text(compiledStatement, 0));
                strcpy(to.oper, (char*) sqlite3_column_text(compiledStatement, 1));
                if (sqlite3_column_text(compiledStatement, 2))
                    strcpy(to.takeoffType, (char*) sqlite3_column_text(compiledStatement, 2));
                else
                    strcpy(to.takeoffType, "");
                strcpy(to.takeoffTitu, (char*) sqlite3_column_text(compiledStatement, 3));
                if (sqlite3_column_text(compiledStatement, 4))
                    strcpy(to.v1crit, (char*) sqlite3_column_text(compiledStatement, 4));
                else
                    strcpy(to.v1crit, "");
                to.wftail = sqlite3_column_double(compiledStatement, 5);
                to.wfhead = sqlite3_column_double(compiledStatement, 6);
                to.rwymargin = sqlite3_column_int(compiledStatement, 7);
                to.obstaclear = sqlite3_column_int(compiledStatement, 8);
                to.suplement = sqlite3_column_double(compiledStatement, 9);
                to.gradi0 = sqlite3_column_double(compiledStatement, 10);
                to.gradi100 = sqlite3_column_double(compiledStatement, 11);
                to.gradi200 = sqlite3_column_double(compiledStatement, 12);
                to.codflap = sqlite3_column_int(compiledStatement, 13);
                strcpy(to.flap, (char*) sqlite3_column_text(compiledStatement, 14));
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return to;
}

struct landing getLandingData(char *dbPath, char *afm, char *oper, char *landingType, char *flap, char *landingtitu)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[1000] = "";
    struct landing la;
    if (landingType)
        strcpy(query, "SELECT AVLanding.AFM, AVLanding.Oper, AVLanding.Landingtype, AVLanding.Landingtitu, AVLanding.WFtail, AVLanding.WFhead, AVLanding.RWYmargindes, AVLanding.RWYmarginalt, AVLanding.Gradi0, AVLanding.Gradi100, AVLanding.Gradi200, AVFlaps.FLAPnum, AVFlaps.FLAPch FROM AVLanding LEFT OUTER JOIN AVFlaps ON AVLanding.FLAP = AVFlaps.FLAPnum AND AVLanding.AFM = AVFlaps.AFM WHERE AVLanding.AFM = ? AND AVLanding.Oper = ? AND AVFlaps.FLAPch = ? AND AVLanding.Landingtitu = ? AND AVLanding.Landingtype = ?;");
    else
        strcpy(query, "SELECT AVLanding.AFM, AVLanding.Oper, AVLanding.Landingtype, AVLanding.Landingtitu, AVLanding.WFtail, AVLanding.WFhead, AVLanding.RWYmargindes, AVLanding.RWYmarginalt, AVLanding.Gradi0, AVLanding.Gradi100, AVLanding.Gradi200, AVFlaps.FLAPnum, AVFlaps.FLAPch FROM AVLanding LEFT OUTER JOIN AVFlaps ON AVLanding.FLAP = AVFlaps.FLAPnum AND AVLanding.AFM = AVFlaps.AFM WHERE AVLanding.AFM = ? AND AVLanding.Oper = ? AND AVFlaps.FLAPch = ? AND AVLanding.Landingtitu = ?;");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, flap, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 4, landingtitu, -1, SQLITE_TRANSIENT);
            if (landingType) {
                if (strcmp(landingType, "Normal") == 0) sqlite3_bind_text(compiledStatement, 5, "NORM", -1, SQLITE_TRANSIENT);
                else if (strcmp(landingType, "Tactical") == 0) sqlite3_bind_text(compiledStatement, 5, "TAC", -1, SQLITE_TRANSIENT);
            }
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(la.afm, (char*) sqlite3_column_text(compiledStatement, 0));
                strcpy(la.oper, (char*) sqlite3_column_text(compiledStatement, 1));
                if (sqlite3_column_text(compiledStatement, 2))
                    strcpy(la.landingType, (char*) sqlite3_column_text(compiledStatement, 2));
                else
                    strcpy(la.landingType, "");
                strcpy(la.landingtitu, (char*) sqlite3_column_text(compiledStatement, 3));
                la.wftail = sqlite3_column_double(compiledStatement, 4);
                la.wfhead = sqlite3_column_double(compiledStatement, 5);
                la.rwymargindes = sqlite3_column_double(compiledStatement, 6);
                la.rwymarginalt = sqlite3_column_double(compiledStatement, 7);
                la.gradi0 = sqlite3_column_double(compiledStatement, 8);
                la.gradi100 = sqlite3_column_double(compiledStatement, 9);
                la.gradi200 = sqlite3_column_double(compiledStatement, 10);
                la.codflap = sqlite3_column_int(compiledStatement, 11);
                strcpy(la.flap, (char*) sqlite3_column_text(compiledStatement, 12));
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return la;
}

void getFlapCh(char *dbPath, char *afm, int flapNum, char *flap)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT FLAPch FROM AVFlaps WHERE FLAPnum = ? and AFM = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_int(compiledStatement, 1, flapNum);
            sqlite3_bind_text(compiledStatement, 2, afm, -1, SQLITE_TRANSIENT);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0))
                    strcpy(flap, (char*) sqlite3_column_text(compiledStatement, 0));
            }
            
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getTypeCliCruDes(char *dbPath, char *afm, char *fase, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Description FROM AVLaw WHERE AFM = ? AND Fase = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, fase, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    char cad[50] = "";
                    strcpy(cad, (char*)sqlite3_column_text(compiledStatement, 0));
                    callback(cad, NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

int getCodTypeCliCruDes(char *dbPath, char *afm, char *fase, char *type)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int codType = 0;
    char query[100] = "SELECT Type FROM AVLaw WHERE AFM = ? AND Fase = ? AND Description = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, fase, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, type, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                codType = sqlite3_column_int(compiledStatement, 0);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return codType;
}

int getMaxAlt(char *dbPath, char *afm, char *oper)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int maxAlt = 0;
    char query[100] = "SELECT Maxalt FROM AVAltitude WHERE AFM = ? AND Oper = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, oper, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                maxAlt = sqlite3_column_int(compiledStatement, 0);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return maxAlt;
}

void getFuelTypes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[50] = "SELECT Nombre FROM AVFuel;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    char cad[10] = "";
                    strcpy(cad, (char*)sqlite3_column_text(compiledStatement, 0));
                    callback(cad, NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct infofuel getFuelData(char *dbPath, char *fuelType)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Tempini, Tempfin, Densidadini, Densidadfin FROM AVFuel WHERE Nombre = ?;";
    struct infofuel inf;
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, fuelType, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                inf.tempini = sqlite3_column_double(compiledStatement, 0);
                inf.tempfin = sqlite3_column_double(compiledStatement, 1);
                inf.densidadini = sqlite3_column_double(compiledStatement, 2);
                inf.densidadfin = sqlite3_column_double(compiledStatement, 3);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return inf;
}

void setPlaneModel(char *dbPath, struct plane_model *pm)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int planeExist = 0;
    char querySelect[100] = "SELECT * FROM AVTypes WHERE Plane = ?;";
    char queryAlter[300] = "UPDATE AVTypes SET AFM = ?, Desig = ?, Basicdi = ?, Basicfuel = ?, Description = ? WHERE Plane = ?;";
    char queryInsert[200] = "INSERT INTO AVTypes (Plane, AFM, Desig, Basicdi, Basicfuel, Description) VALUES (?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, pm->plane, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                planeExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (planeExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, pm->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, pm->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, pm->basicdi);
                sqlite3_bind_int(compiledStatement, 4, pm->basicfuel);
                sqlite3_bind_text(compiledStatement, 5, pm->description, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 6, pm->plane, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, pm->plane, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, pm->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, pm->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 4, pm->basicdi);
                sqlite3_bind_int(compiledStatement, 5, pm->basicfuel);
                sqlite3_bind_text(compiledStatement, 6, pm->description, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setAltitude(char *dbPath, struct altitude *al)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int altitudeExist = 0;
    char querySelect[100] = "SELECT * FROM AVAltitude WHERE AFM = ? AND Oper = ?;";
    char queryAlter[300] = "UPDATE AVAltitude SET Maxalt = ? WHERE AFM = ? AND Oper = ?;";
    char queryInsert[200] = "INSERT INTO AVAltitude (AFM, Oper, Maxalt) VALUES (?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, al->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, al->oper, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                altitudeExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (altitudeExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_int(compiledStatement, 1, al->maxAlt);
                sqlite3_bind_text(compiledStatement, 2, al->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, al->oper, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, al->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, al->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, al->maxAlt);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setExternalConfig(char *dbPath, struct stores_external_config *ec)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int externalConfigExist = 0;
    char querySelect[100] = "SELECT * FROM AVExternalconfig WHERE Desig = ? AND Stores = ? AND Station = ?;";
    char queryAlter[300] = "UPDATE AVExternalconfig SET DeltaOEW = ?, Fuelext = ?, DeltaDI_AEO = ?, DeltaDI_OEI = ? WHERE Desig = ? AND Stores = ? AND Station = ?;";
    char queryInsert[200] = "INSERT INTO AVExternalconfig (Desig, Stores, DeltaOEW, Fuelext, DeltaDI_AEO, Station, DeltaDI_OEI) VALUES (?, ?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, ec->desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, ec->store, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, ec->station, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                externalConfigExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (externalConfigExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_int(compiledStatement, 1, ec->deltaOEW);
                sqlite3_bind_int(compiledStatement, 2, ec->fuelExt);
                sqlite3_bind_int(compiledStatement, 3, ec->deltaDIAEO);
                sqlite3_bind_int(compiledStatement, 4, ec->deltaDIOEI);
                sqlite3_bind_text(compiledStatement, 5, ec->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 6, ec->store, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 7, ec->station, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, ec->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, ec->store, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, ec->deltaOEW);
                sqlite3_bind_int(compiledStatement, 4, ec->fuelExt);
                sqlite3_bind_int(compiledStatement, 5, ec->deltaDIAEO);
                sqlite3_bind_text(compiledStatement, 6, ec->station, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 7, ec->deltaDIOEI);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setFlaps(char *dbPath, struct flap *fl)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int flapExist = 0;
    char querySelect[100] = "SELECT * FROM AVFlaps WHERE AFM = ? AND FLAPnum = ?;";
    char queryAlter[300] = "UPDATE AVFlaps SET FLAPch = ? WHERE AFM = ? AND FLAPnum = ?;";
    char queryInsert[200] = "INSERT INTO AVFlaps (AFM, FLAPnum, FLAPch) VALUES (?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, fl->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, fl->flapNum, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                flapExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (flapExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, fl->flapCh, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, fl->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, fl->flapNum, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, fl->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, fl->flapNum, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, fl->flapCh, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setInternalConfig(char *dbPath, struct internal_config *ic)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int internalConfigExist = 0;
    char querySelect[100] = "SELECT * FROM AVInternalconfig WHERE Desig = ? AND Configuration = ?;";
    char queryAlter[300] = "UPDATE AVInternalconfig SET OEW = ?, Fuelint = ?, Airdrop = ? WHERE Desig = ? AND Configuration = ?;";
    char queryInsert[200] = "INSERT INTO AVInternalconfig (Desig, Configuration, OEW, Fuelint, Airdrop) VALUES (?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, ic->desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, ic->configuration, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                internalConfigExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (internalConfigExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_int(compiledStatement, 1, ic->oew);
                sqlite3_bind_int(compiledStatement, 2, ic->fuelint);
                sqlite3_bind_text(compiledStatement, 3, (ic->airdrop == 1) ? "YES" : "NO", -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, ic->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 5, ic->configuration, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, ic->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, ic->configuration, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, ic->oew);
                sqlite3_bind_int(compiledStatement, 4, ic->fuelint);
                sqlite3_bind_text(compiledStatement, 5, (ic->airdrop == 1) ? "YES" : "NO", -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setLanding(char *dbPath, struct landing *ld)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int landingExist = 0;
    char querySelect[200] = "SELECT * FROM AVLanding WHERE AFM = ? AND Oper = ? AND Landingtype = ? AND Landingtitu = ? AND FLAP = ?;";
    char queryAlter[300] = "UPDATE AVLanding SET WFtail = ?, WFhead = ?, RWYmargindes = ?, RWYmarginalt = ?, Gradi0 = ?, Gradi100 = ?, Gradi200 = ? WHERE AFM = ? AND Oper = ? AND Landingtype = ? AND Landingtitu = ? AND FLAP = ?;";
    char queryInsert[300] = "INSERT INTO AVLanding (AFM, Oper, Landingtype, Landingtitu, FLAP, WFtail, WFhead, RWYmargindes, RWYmarginalt, Gradi0, Gradi100, Gradi200) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, ld->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, ld->oper, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, ld->landingType, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 4, ld->landingtitu, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 5, ld->flap, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                landingExist = 1;
            }
        } else
            printf("Error whith statement SELECT in setLanding. '%s'\n", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (landingExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_double(compiledStatement, 1, ld->wftail);
                sqlite3_bind_double(compiledStatement, 2, ld->wfhead);
                sqlite3_bind_double(compiledStatement, 3, ld->rwymargindes);
                sqlite3_bind_double(compiledStatement, 4, ld->rwymarginalt);
                sqlite3_bind_double(compiledStatement, 5, ld->gradi0);
                sqlite3_bind_double(compiledStatement, 6, ld->gradi100);
                sqlite3_bind_double(compiledStatement, 7, ld->gradi200);
                sqlite3_bind_text(compiledStatement, 8, ld->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 9, ld->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 10, ld->landingType, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 11, ld->landingtitu, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 12, ld->flap, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement UPDATE in setLanding. '%s'\n", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, ld->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, ld->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, ld->landingType, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, ld->landingtitu, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 5, ld->flap, -1, SQLITE_TRANSIENT);
                sqlite3_bind_double(compiledStatement, 6, ld->wftail);
                sqlite3_bind_double(compiledStatement, 7, ld->wfhead);
                sqlite3_bind_double(compiledStatement, 8, ld->rwymargindes);
                sqlite3_bind_double(compiledStatement, 9, ld->rwymarginalt);
                sqlite3_bind_double(compiledStatement, 10, ld->gradi0);
                sqlite3_bind_double(compiledStatement, 11, ld->gradi100);
                sqlite3_bind_double(compiledStatement, 12, ld->gradi200);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement INSERT in setLanding. '%s'\n", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setLaw(char *dbPath, struct law *lw)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int lawExist = 0;
    char querySelect[100] = "SELECT * FROM AVLaw WHERE AFM = ? AND Fase = ? AND Type = ?;";
    char queryAlter[300] = "UPDATE AVLaw SET Description = ?, Acronyms = ? WHERE AFM = ? AND Fase = ? AND Type = ?;";
    char queryInsert[200] = "INSERT INTO AVLaw (AFM, Fase, Type, Description, Acronyms) VALUES (?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, lw->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, lw->fase, -1, SQLITE_TRANSIENT);
            sqlite3_bind_int(compiledStatement, 3, lw->type);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                lawExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (lawExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, lw->description, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, lw->acronyms, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, lw->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, lw->fase, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 5, lw->type);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, lw->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, lw->fase, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, lw->type);
                sqlite3_bind_text(compiledStatement, 4, lw->description, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 5, lw->acronyms, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setStation(char *dbPath, struct station *st)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int stationExist = 0;
    char querySelect[100] = "SELECT * FROM AVStation WHERE Desig = ? AND Station = ?;";
    char queryInsert[200] = "INSERT INTO AVStation (Desig, Station) VALUES (?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, st->desig, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, st->station, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                stationExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (stationExist == 0) {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, st->desig, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, st->station, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setTakeoff(char *dbPath, struct takeoff *to)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int takeoffExist = 0;
    char querySelect[200] = "SELECT * FROM AVTakeoff WHERE AFM = ? AND Oper = ? AND Takeofftype = ? AND Takeofftitu = ? AND FLAP = ?;";
    char queryAlter[300] = "UPDATE AVTakeoff SET V1Crit = ?, WFtail = ?, WFhead = ?, RWYmargin = ?, Obstaclear = ?, Suplement = ?, Gradi0 = ?, Gradi100 = ?, Gradi200 = ? WHERE AFM = ? AND Oper = ? AND Takeofftype = ? AND Takeofftitu = ? AND FLAP = ?;";
    char queryInsert[300] = "INSERT INTO AVTakeoff (AFM, Oper, Takeofftype, Takeofftitu, FLAP, V1Crit, WFtail, WFhead, RWYmargin, Obstaclear, Suplement, Gradi0, Gradi100, Gradi200) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, to->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, to->oper, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, to->takeoffType, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 4, to->takeoffTitu, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 4, to->flap, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                takeoffExist = 1;
            }
        } else
            printf("Error whith statement SELECT in Takeoff. '%s\n", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (takeoffExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, to->v1crit, -1, SQLITE_TRANSIENT);
                sqlite3_bind_double(compiledStatement, 2, to->wftail);
                sqlite3_bind_double(compiledStatement, 3, to->wfhead);
                sqlite3_bind_int(compiledStatement, 4, to->rwymargin);
                sqlite3_bind_int(compiledStatement, 5, to->obstaclear);
                sqlite3_bind_double(compiledStatement, 6, to->suplement);
                sqlite3_bind_double(compiledStatement, 7, to->gradi0);
                sqlite3_bind_double(compiledStatement, 8, to->gradi100);
                sqlite3_bind_double(compiledStatement, 9, to->gradi200);
                sqlite3_bind_text(compiledStatement, 10, to->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 11, to->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 12, to->takeoffType, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 13, to->takeoffTitu, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 14, to->flap, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement UPDATE in Takeoff. '%s\n", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, to->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, to->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, to->takeoffType, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 4, to->takeoffTitu, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 5, to->flap, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 6, to->v1crit, -1, SQLITE_TRANSIENT);
                sqlite3_bind_double(compiledStatement, 7, to->wftail);
                sqlite3_bind_double(compiledStatement, 8, to->wfhead);
                sqlite3_bind_int(compiledStatement, 9, to->rwymargin);
                sqlite3_bind_int(compiledStatement, 10, to->obstaclear);
                sqlite3_bind_double(compiledStatement, 11, to->suplement);
                sqlite3_bind_double(compiledStatement, 12, to->gradi0);
                sqlite3_bind_double(compiledStatement, 13, to->gradi100);
                sqlite3_bind_double(compiledStatement, 14, to->gradi200);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement INSERT in Takeoff. '%s\n", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void setWeights(char *dbPath, struct operation *op)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int weightsExist = 0;
    char querySelect[100] = "SELECT * FROM AVWeights WHERE AFM = ? AND Oper = ? AND Opertype = ?;";
    char queryAlter[300] = "UPDATE AVWeights SET MRW = ?, MTOW = ?, MLW = ?, MZFW = ?, MGW = ?, MTOWUNP = ?, MLWUNP = ?, MTOWALT = ?, MZFWALT = ? WHERE AFM = ? AND Oper = ? AND Opertype = ?;";
    char queryInsert[200] = "INSERT INTO AVWeights (AFM, Oper, Opertype, MRW, MTOW, MLW, MZFW, MGW, MTOWUNP, MLWUNP, MTOWALT, MZFWALT) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, op->afm, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, op->oper, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 3, op->opertype, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                weightsExist = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (weightsExist == 1) {
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_int(compiledStatement, 1, op->mrw);
                sqlite3_bind_int(compiledStatement, 2, op->mtow);
                sqlite3_bind_int(compiledStatement, 3, op->mlw);
                sqlite3_bind_int(compiledStatement, 4, op->mzfw);
                sqlite3_bind_int(compiledStatement, 5, op->mgw);
                sqlite3_bind_int(compiledStatement, 6, op->mtowunp);
                sqlite3_bind_int(compiledStatement, 7, op->mlwunp);
                sqlite3_bind_int(compiledStatement, 8, op->mtowalt);
                sqlite3_bind_int(compiledStatement, 9, op->mzfwalt);
                sqlite3_bind_text(compiledStatement, 10, op->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 11, op->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 12, op->opertype, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, op->afm, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, op->oper, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 3, op->opertype, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 4, op->mrw);
                sqlite3_bind_int(compiledStatement, 5, op->mtow);
                sqlite3_bind_int(compiledStatement, 6, op->mlw);
                sqlite3_bind_int(compiledStatement, 7, op->mzfw);
                sqlite3_bind_int(compiledStatement, 8, op->mgw);
                sqlite3_bind_int(compiledStatement, 9, op->mtowunp);
                sqlite3_bind_int(compiledStatement, 10, op->mlwunp);
                sqlite3_bind_int(compiledStatement, 11, op->mtowalt);
                sqlite3_bind_int(compiledStatement, 12, op->mzfwalt);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        sqlite3_close(database);
    }
}

void getIcaos(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT DISTINCT Icao FROM APPistas ORDER BY Icao;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    callback((char*) sqlite3_column_text(compiledStatement, 0), NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getRwy(char *dbPath, char *icao, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT RWY FROM APPistas WHERE Icao = ? ORDER BY RWY;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    callback((char*) sqlite3_column_text(compiledStatement, 0), NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}
struct runway getRwyUnique(char *dbPath, char *icao, char *rwy)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT RWY FROM APPistas WHERE Icao = ? AND RWY = ?";
    struct runway rw;
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(rw.rwy, (char*) sqlite3_column_text(compiledStatement, 0));
                
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

struct runway getRunwayData(char *dbPath, char *icao, char *rwy)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[500] = "SELECT APPistas.TORA, APPistas.ASDA, APPistas.TODA, APPistas.Slope, APPistas.Alt, APPistas.TrueBearing, APPistas.Type, APPistas.Metar, APTiposPistas.Descripcion FROM APPistas LEFT OUTER JOIN APTiposPistas ON APTiposPistas.Tipo = APPistas.Type WHERE Icao = ? and RWY = ?;";
    char queryObs[500] = "SELECT Height, Distance FROM APObstaculos WHERE Icao = ? and RWY = ?;";
    struct runway rw;
    rw.obstacles.numobstacles = 0;
    strcpy(rw.icao, "");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                strcpy(rw.icao, icao);
                strcpy(rw.rwy, rwy);
                rw.tora = sqlite3_column_int(compiledStatement, 0);
                rw.asda = sqlite3_column_int(compiledStatement, 1);
                rw.toda = sqlite3_column_int(compiledStatement, 2);
                rw.slope = sqlite3_column_double(compiledStatement, 3);
                rw.elevation = sqlite3_column_int(compiledStatement, 4);
                rw.trueBearing = sqlite3_column_double(compiledStatement, 5);
                rw.codType = sqlite3_column_int(compiledStatement, 6);
                rw.metar = sqlite3_column_int(compiledStatement, 7);
                if (sqlite3_column_text(compiledStatement, 8)) strcpy(rw.type, (char*) sqlite3_column_text(compiledStatement, 8));
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (sqlite3_prepare_v2(database, queryObs, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                rw.obstacles.obstacles[rw.obstacles.numobstacles].height = sqlite3_column_int(compiledStatement, 0);
                rw.obstacles.obstacles[rw.obstacles.numobstacles].distance = sqlite3_column_double(compiledStatement, 1);
                rw.obstacles.numobstacles ++;
                
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return rw;
}

void setRunwayData(char *dbPath, struct runway *rw)
{
//    char tmp[1024];
//    sprintf(tmp, "icao=%s", rw->icao);
//    My_DEBUG(tmp);
//    
//    char tmp2[1024];
//    sprintf(tmp2, "rwy=%s", rw->rwy);
//    My_DEBUG(tmp2);
//    
//    char tmp3[1024];
//    sprintf(tmp3, "tora=%d", rw->tora);
//    My_DEBUG(tmp3);
//    
//    char tmp1[1024];
//    sprintf(tmp1, "asda=%d", rw->asda);
//    My_DEBUG(tmp1);
//    
//    char tmp4[1024];
//    sprintf(tmp4, "toda=%d", rw->toda);
//    My_DEBUG(tmp4);
//    
//    char tmp5[1024];
//    sprintf(tmp5, "tora=%d", rw->tora);
//    My_DEBUG(tmp5);
//    
//    char tmp6[1024];
//    sprintf(tmp6, "slope=%f", rw->slope);
//    My_DEBUG(tmp6);
//    
//    char tmp7[1024];
//    sprintf(tmp7, "elevation=%d", rw->elevation);
//    My_DEBUG(tmp7);
//    
//    char tmp8[1024];
//    sprintf(tmp8, "true=%f", rw->trueBearing);
//    My_DEBUG(tmp8);
//    
//    char tmp9[1024];
//    sprintf(tmp9, "metar=%d", rw->metar);
//    My_DEBUG(tmp9);
//    
//    char tmp10[1024];
//    sprintf(tmp10, "tora=%d", rw->tora);
//    My_DEBUG(tmp10);
    
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int existePista = 0;
    char querySelect[100] = "SELECT * FROM APPISTAS WHERE Icao = ? and RWY = ?;";
    char queryAlter[500] = "UPDATE APPistas SET TORA = ?, ASDA = ?, TODA = ?, Slope = ?, Alt = ?, TrueBearing = ?, Type = (SELECT Tipo FROM APTiposPistas WHERE Descripcion = ?), Metar = ? WHERE Icao = ? and RWY = ?;";
    char queryInsert[200] = "INSERT INTO APPISTAS (Icao, RWY, TORA, ASDA, TODA, Slope, Alt, TrueBearing, Type, Metar) VALUES (?, ?, ?, ?, ?, ?, ?, ?, (SELECT Tipo FROM APTiposPistas WHERE Descripcion = ?), ?);";
    char deleteObs[300] = "DELETE FROM APObstaculos WHERE Icao = ? AND RWY = ?";
    char queryInsertObs[300] = "INSERT INTO APObstaculos (Icao, RWY, Height, Distance) VALUES (?, ?, ?, ?);";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        //My_DEBUG("sqlite_ok");
        if (sqlite3_prepare_v2(database, querySelect, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, rw->icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rw->rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                existePista = 1;
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        //My_DEBUG("1_finalize_statement_ok");
        if (existePista == 1) {
            //My_DEBUG("existe_pista");
            if (sqlite3_prepare_v2(database, queryAlter, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_int(compiledStatement, 1, rw->tora);
                sqlite3_bind_int(compiledStatement, 2, rw->asda);
                sqlite3_bind_int(compiledStatement, 3, rw->toda);
                sqlite3_bind_double(compiledStatement, 4, rw->slope);
                sqlite3_bind_int(compiledStatement, 5, rw->elevation);
                sqlite3_bind_double(compiledStatement, 6, rw->trueBearing);
                sqlite3_bind_text(compiledStatement, 7, rw->type, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement,8, rw->metar);
                sqlite3_bind_text(compiledStatement, 9, rw->icao, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 10, rw->rwy, -1, SQLITE_TRANSIENT);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
            
        } else {
            //My_DEBUG("no_existe_pista");
            if (sqlite3_prepare_v2(database, queryInsert, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, rw->icao, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, rw->rwy, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 3, rw->tora);
                sqlite3_bind_int(compiledStatement, 4, rw->asda);
                sqlite3_bind_int(compiledStatement, 5, rw->toda);
                sqlite3_bind_double(compiledStatement, 6, rw->slope);
                sqlite3_bind_int(compiledStatement, 7, rw->elevation);
                sqlite3_bind_double(compiledStatement, 8, rw->trueBearing);
                sqlite3_bind_text(compiledStatement, 9, rw->type, -1, SQLITE_TRANSIENT);
                sqlite3_bind_int(compiledStatement, 10, rw->metar);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
            sqlite3_finalize(compiledStatement);
        }
        
        if (sqlite3_prepare_v2(database, deleteObs, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, rw->icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rw->rwy, -1, SQLITE_TRANSIENT);
            //My_DEBUG("deleteObs");
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        //My_DEBUG("antes_del_for");
        
        for (int x = 0; x < rw->obstacles.numobstacles; x ++) {
            //My_DEBUG("for_obstaculos");
            if (sqlite3_prepare_v2(database, queryInsertObs, -1, &compiledStatement, NULL) == SQLITE_OK) {
                sqlite3_bind_text(compiledStatement, 1, rw->icao, -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(compiledStatement, 2, rw->rwy, -1, SQLITE_TRANSIENT);
                sqlite3_bind_double(compiledStatement, 3, rw->obstacles.obstacles[x].height);
                sqlite3_bind_int(compiledStatement, 4, rw->obstacles.obstacles[x].distance);
                
                while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                }
            } else
                printf("Error whith statement. '%s'", sqlite3_errmsg(database));
            
	    sqlite3_finalize(compiledStatement);
            //My_DEBUG("antes_de_cerrar_ultimo_statement");
            //My_DEBUG("Cierra");
        }
        
	//My_DEBUG("finalizar");
        sqlite3_close(database);
    }
}

void deleteRunway(char *dbPath, char *icao, char *rwy)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[300] = "DELETE FROM APPistas WHERE Icao = ? AND RWY = ?;";
    char queryObs[300] = "DELETE FROM APObstaculos WHERE Icao = ? AND RWY = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        
        if (sqlite3_prepare_v2(database, queryObs, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, icao, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(compiledStatement, 2, rwy, -1, SQLITE_TRANSIENT);
            
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getRunwayTypes(char *dbPath, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "SELECT Descripcion FROM APTiposPistas";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    callback((char*) sqlite3_column_text(compiledStatement, 0), NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

void getRunwayConditionTypes(char *dbPath, char *tipo, int (*callback)(char *string, void *NotUsed), void *NotUsed)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "";
    if (strcmp(tipo, "Paved") == 0)
        strcpy(query, "SELECT Descripcion FROM APEstadoPistasPavimentadas");
    else
        strcpy(query, "SELECT Descripcion FROM APEstadoPistasNoPavimentadas");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    callback((char*) sqlite3_column_text(compiledStatement, 0), NotUsed);
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

int getCodRunwayCondition(char *dbPath, char *condition, char *type)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int codCondition = 0;
    char query[100] = "";
    if (strcmp(type, "Paved") == 0)
        strcpy(query, "SELECT Estado FROM APEstadoPistasPavimentadas WHERE Descripcion = ?");
    else
        strcpy(query, "SELECT Estado FROM APEstadoPistasNoPavimentadas WHERE Descripcion = ?");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, condition, -1, SQLITE_TRANSIENT);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                codCondition = sqlite3_column_int(compiledStatement, 0);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return codCondition;
}

void getRunwayCondition(char *dbPath, int codCondition, char *type, char*condition)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    char query[100] = "";
    if (strcmp(type, "Paved") == 0)
        strcpy(query, "SELECT Descripcion FROM APEstadoPistasPavimentadas WHERE Estado = ?");
    else
        strcpy(query, "SELECT Descripcion FROM APEstadoPistasNoPavimentadas WHERE Estado = ?");
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_int(compiledStatement, 1, codCondition);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                if (sqlite3_column_text(compiledStatement, 0)) {
                    strcpy(condition, (char*) sqlite3_column_text(compiledStatement, 0));
                }
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
}

int getTypeRunwayCondition(char *dbPath, char *condition)
{
    sqlite3 *database;
    sqlite3_stmt *compiledStatement;
    int codType = 0;
    char query[100] = "SELECT Tipo FROM APTiposPistas WHERE Descripcion = ?;";
    
    if (sqlite3_open(dbPath, &database) == SQLITE_OK) {
        if (sqlite3_prepare_v2(database, query, -1, &compiledStatement, NULL) == SQLITE_OK) {
            sqlite3_bind_text(compiledStatement, 1, condition, -1, SQLITE_TRANSIENT);
            while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                codType = sqlite3_column_int(compiledStatement, 0);
            }
        } else
            printf("Error whith statement. '%s'", sqlite3_errmsg(database));
        
        sqlite3_finalize(compiledStatement);
        sqlite3_close(database);
    }
    
    return codType;
}
