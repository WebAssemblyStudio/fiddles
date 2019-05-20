#include <stdint.h>
#define WASM_EXPORT __attribute__((visibility("default")))

int CONCAT11(int8_t var1, int8_t var2) {
  return var1*0x100+var2;
}

int MOVE_LIST_4046[29] = {0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x76, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0
}; 

int BYTE_ram_4337[127] = {0x80, 0x8, 0xA9, 0xB7, 
0xAD, 0x76, 0x1D,  0x8, 
0x37, 0x33, 0x27, 0x30, 
0x36, 0x27, 0x33, 0x37, 
0x76, 0x1E, 0x8, 0x35, 
0x35, 0x35, 0x35, 0x80, 
0x35, 0x35, 0x35, 0x76, 
0x1F, 0x8, 0x0, 0x80, 
0x0, 0x80, 0x35, 0x80, 
0x0, 0x80, 0x76, 0x20, 
0x8, 0x80, 0x0, 0x80, 
0x0, 0x80, 0x0, 0x80, 
0x0, 0x76, 0x21, 0x8, 
0x0, 0x80, 0x0, 0x80, 
0x0, 0x80, 0x0, 0x80, 
0x76, 0x22, 0x8, 0x80, 
0x0, 0x80, 0x0, 0x80, 
0x0, 0x80, 0x0, 0x76, 
0x23, 0x8, 0xB5, 0xB5, 
0xB5, 0xB5, 0xB5, 0xB5, 
0xB5, 0xB5, 0x76, 0x24, 
0x8, 0xB7, 0xB3, 0xA7, 
0xB0, 0xB6, 0xA7, 0xB3, 
0xB7, 0x76, 0x8, 0x8, 
0x2D, 0x2C, 0x2B, 0x2A, 
0x29, 0x28, 0x27, 0x26, 
0x76, 0x8, 0x8, 0x8, 
0x8, 0x8, 0x76, 0x76, 
0x76, 0x76, 0x76, 0x76, 
0x76, 0x76, 0x76, 0x76, 
0x7D, 0x8F, 0x4, 0xE, 
0x0,  0x0, 0x80};

/* this routine takes the board address and determines whether the contents are: 
different from the current mover-colour;
empty; 
the board surround or the same colour as the current mover.
0-DIFF, 1-EMPTY, 2-WALL, 3-SAME
*/
int8_t STR(int8_t idx) {
  int8_t result = 1;
  int8_t piece = BYTE_ram_4337[idx] & 0x7f;
  if ((((piece != 0) && (result = 2, piece != 0x76)) && (0x26 < piece)) &&
     (result = 3, (BYTE_ram_4337[idx] + BYTE_ram_4337[0] & 0x80) != 0)) {
    result = 0;
  }
  return result;
}


/* adds to the current legal move list another entry on the end. */
void ALIST(int8_t uParm1) {
  MOVE_LIST_4046[0] = MOVE_LIST_4046[0] + 1;
  MOVE_LIST_4046[MOVE_LIST_4046[0]] = uParm1;
  return;
}

void PIECE(int8_t *pbParm1, int8_t bParm2){
  int8_t bVar1;
  uint8_t uVar2;
  int8_t bVar3;
  char cVar4;
  int8_t *pbVar5;
  char *pcVar6;
  
                    /* sets up pointers to possible move
                       tables and number of steps and directions */
  MOVE_LIST_4046[0] = 0;
  bVar3 = *pbParm1 & 0x7f;
  if (bVar3 == 0x35) {
                    /* produces a list of all possible legal
                       moves including initial double moves */
    pcVar6 = (char *)0x40e4;
    if ((*pbParm1 & 0x80) == 0) {
      pcVar6 = (char *)0x40f1;
    }
    cVar4 = 3;
LAB_ram_415e:
    do {
      bVar3 = bParm2;
      bParm2 = bVar3 + *pcVar6;
      if ((0x3e < bParm2) && (bParm2 < 0x94)) {
        bVar1 = bParm2;
        STR();
        if (bVar1 == 0) {
          if (cVar4 != 1) {
            ALIST();
          }
        }
        else {
          if (((bVar1 == 1) && (cVar4 == 1)) && ((ALIST(), bVar3 < 0x52 || (0x7d < bVar3))))
          goto LAB_ram_415e;
        }
      }
      pcVar6 = pcVar6 + -1;
      cVar4 = cVar4 + -1;
      bParm2 = bVar3;
      if (cVar4 == 0) {
        return;
      }
    } while( true );
  }
  uVar2 = 0x801;
  pbVar5 = BYTE_ARRAY_ram_40e7;
  bVar1 = bParm2;
  if ((((bVar3 != 0x33) && (pbVar5 = TABLES, bVar1 = bParm2, bVar3 != 0x30)) &&
      (uVar2 = 0x808, bVar1 = bParm2, bVar3 != 0x36)) &&
     ((uVar2 = 0x408, bVar1 = bParm2, bVar3 != 0x37 &&
      (pbVar5 = (byte *)0x40e3, bVar1 = bParm2, bVar3 != 0x27)))) {
    MOVE_LIST_4046[0] = 0;
    return;
  }
LAB_ram_4124:
  do {
    bVar1 = bVar1 + *pbVar5;
    if ((0x3e < bVar1) && (bVar1 < 0x94)) {
      bVar3 = bVar1;
      STR();
      if ((bVar3 < 2) && ((ALIST(), bVar3 != 0 && ((char)uVar2 != 1)))) goto LAB_ram_4124;
    }
    pbVar5 = pbVar5 + 1;
    bVar3 = (char)(uVar2 >> 8) - 1;
    uVar2 = uVar2 & 0xff | (ushort)bVar3 << 8;
    bVar1 = bParm2;
    if (bVar3 == 0) {
      return;
    }
  } while( true );
}




WASM_EXPORT
int main() {
  return STR(2);
}

