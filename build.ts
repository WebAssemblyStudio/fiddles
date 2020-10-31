CALC   START
       LD      GR1,   DATA1
       LD      GR2,   DATA2
LOOP
       CPL     GR2,   =1
       JZEE    FIN
       ADDA    GR1,   DATA1
       SUBA    GE2,   =1
       JUMP    LOOP
FIN
       ST      GR1,   ANS
       RET

DATA1  DC      15
DATA2  DC      3
ANS    DS      1
       END