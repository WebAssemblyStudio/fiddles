#include <stdio.h>
using namespace std;

#define WASM_EXPORT __attribute__((visibility("default")))

char* mem; //Memory pointer
char* mapTarget = new char[0x1000]; //Reserve memory
char* asd;

/* Type definitions */
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;


/* Offsets */
#define VIEW_MATRIX 0x3997A00
#define ENTITY_LIST 0x6BE800
#define LOCAL_PLAYER_INDEX 0x61AB68
#define MAX_ENTITY_INDEX 0x6BE80C
#define ENTITY_ORIGIN 0x2C0
#define ENTITY_SIZE 0xBB8 //3k bytes
#define DATA_OFFSET 0x2B0 //Offset from start of the entity

/* My definitions */
#define MAX_PLAYERS 16


/* Structs */
struct Vector3 {
    float x;
    float y;
    float z;
};


struct entity_state_s {
    int entityType;
    int number;
    float msg_time;
    int msg_num;
    Vector3 origin;
    Vector3 rotation;
    int modelindex;
    char pad_0x007C[0x50];
    Vector3 mins;
    Vector3 maxs;
    char pad_0x00A4[0x10];
    int team;
    bool dormant; //Our own variable - not stored in game memory
};


struct view_matrix {
    float m[16];
};


/* JS definitions */
void extern printText(char* txt); //Print text to console
void extern printInt(int num); //Print an integer
void extern printFloat(float num); //Print a floating point
void extern mapMemory(unsigned int address, short size, unsigned int dstAddress); //Map memory
//void extern drawText();


/* Variables */
unsigned int localPlayerAddress = 0;
entity_state_s localPlayer;

entity_state_s playerEntities[MAX_PLAYERS]; //Allocate memory for players
bool updatedEntities[MAX_PLAYERS] = { false }; //Store indexes of updated players for checking

view_matrix viewMatrix; //view matrix

Vector3 screen_info = { 1920, 1080 }; //Resolution



/* Function definitions */
bool WorldToScreen(Vector3* pos, Vector3* out);



/* Get entity by index */
unsigned int getEntityByIndex(int index) {
	
    //Don't bother if index is negative
  	if(index < 0){
		    printText((char*)"Negative index provided!");
		    return 0;
	  };
	
    mapMemory(ENTITY_LIST, 0x10, 0);
    unsigned int entityBase = *(int*)mapTarget;
    int maxEntityIndex = *(int*)(0xC);
	
    //Entity at index 0
	  if(index == 0){
        mapMemory(0x6BE378, 0x4, 0);
		    unsigned int entityNull = *(int*)mapTarget;
        return entityNull;
	  };
	
    if(maxEntityIndex > index){
		    return entityBase + (index * ENTITY_SIZE);
    } else {
		    return 0;
	  };
};



/* Update local player info */
bool updateLocalPlayer(){

    mapMemory(LOCAL_PLAYER_INDEX, 4, 0);
    int playerIndex = *(int*)mapTarget;
    //printInt(playerIndex);

    mapMemory(ENTITY_LIST, 0x10, 0);
    unsigned int entityListBase = *(int*)mapTarget;
    int maxEntityIndex = *(int*)(0xC);
    //printInt(entityListBase);
    //printInt(maxEntityIndex);


    if (entityListBase != 0) {
        if (playerIndex > -2) {
            if (maxEntityIndex > (playerIndex + 1)) {
                localPlayerAddress = entityListBase + (playerIndex + 1) * ENTITY_SIZE;
            };
        } else {
            printText((char*)"LocalPlayer index is invalid! (index < -2)");
        }
    } else {
        printText((char*)"EntityList address is invalid!");
        localPlayerAddress = 0;
    };

    printInt(localPlayerAddress);


    //Read info
    mapMemory(localPlayerAddress + DATA_OFFSET, sizeof(entity_state_s), 0);
    localPlayer = *(entity_state_s*)mapTarget;
    printText((char*)"Local player position:");
    printFloat(localPlayer.origin.x);
    printFloat(localPlayer.origin.y);
    printFloat(localPlayer.origin.z);

    return true;
};



/* Update enemy info */
bool updateEntities(){
    
    for(int i = 0; i < MAX_PLAYERS; i++){
        unsigned int entityBase = getEntityByIndex(i);

        //Not valid or local entity
        if(entityBase == 0 || entityBase == localPlayerAddress){
            continue;
        };

        //Read info and update the list
        mapMemory(entityBase + DATA_OFFSET, sizeof(entity_state_s), 0);
        entity_state_s entityInfo = *(entity_state_s*)mapTarget;
        entityInfo.dormant = false;

        if(updatedEntities[i] == true){
            //Has entity been changed since last update?
            if(playerEntities[i].msg_time == entityInfo.msg_time){
                //Set dormant
                entityInfo.dormant = true;

                printText((char*)"Entity dormant: ");
                printInt(i);
            };
        };
        
        printText((char*)"Updated entity: ");
        printInt(i);

        playerEntities[i] = entityInfo;
        updatedEntities[i] = true;
    };

    return true;
};



/* Draw stuff on screen */
void drawEntities(){

    //Read view matrix
    mapMemory(VIEW_MATRIX, sizeof(viewMatrix), 0);
    viewMatrix = *(view_matrix*)mapTarget;

    Vector3 zeroPos = { 0.0f, 0.0f, 0.0f };
    Vector3 result = { 0.0f };

    if(!WorldToScreen(&zeroPos, &result)){
      
        //Transfrom to screen space
        result.x *= screen_info.x;
        result.y *= screen_info.y;

        printText((char*)"Projection success!");
        printFloat(result.x);
        printFloat(result.y);
        //printFloat(result.z);
    } else {
        printText((char*)"Projection failed!");
    };
};



/* Called every tick */
WASM_EXPORT
bool tick(){

    //Update local player info
    updateLocalPlayer();

    //Update entity info
    updateEntities();

    //Draw
    drawEntities();

    return true;
};



/* Main */
WASM_EXPORT
int main(){
    printText((char*)"Main called!");
    getEntityByIndex(0);
    //mapMemory(0x10, 0x40, 0x4);
    return 0;
};





//World to screen projection
bool WorldToScreen(Vector3* pos, Vector3* out) {
    float c = 0.0f;
    float d = 0.0f;
    float e = 0.0f;
    float f = 0.0f;
    float h = 0.0f;
    float i = 0.0f;
    float j = 0.0f;
    float k = 0.0f;
    float l = 0.0f;
			
    if (pos != nullptr & out != nullptr) {
        k = viewMatrix.m[4];
        j = viewMatrix.m[5];
        e = viewMatrix.m[6];
        l = viewMatrix.m[7];
        h = viewMatrix.m[12];
        d = viewMatrix.m[3];
        c = viewMatrix.m[14];
        i = viewMatrix.m[15];
        f = viewMatrix.m[3] + (viewMatrix.m[0] * pos->x + viewMatrix.m[1] * pos->y + viewMatrix.m[2] * pos->z);

        out->x = f;
        e = l + (k * pos->x + j * pos->y + e * pos->z);

        out->y = e;
        c = i + (h * pos->x + d * pos->y + c * pos->z);

        out->z = 0.0;
        d = c < 1.0000000474974513e-03f ? 1.0e5f : 1.0f / c;

        out->x = f * d;
        out->y = e * d;

        //printFloat(out->x);
        //printFloat(out->y);
        //printFloat(out->z);
        return c < 1.0000000474974513e-03f; //is hidden
    };
	
    return false;
};

