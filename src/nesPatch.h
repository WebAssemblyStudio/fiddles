/**
 * @file nesPatch.h
 * @author chentian, zhfang
 * @date 2011.08.11
 * @brief NES Emulate For CTR - Patch
 */
{
static Bool bg_lock=false;
static u32 hackWRAM05DE=0;
switch(pPatch->sData.sA.nMode)
{
case 2: // Fixvalue
	switch(pPatch->sData.sA.nIndex)
	{
	case 0:	// HVCWR0A.034: Design Menu
		if(g_pNesWRAM[0x44] == 3 || g_pNesWRAM[0x44] == 4)
			A_G &= ~(0x10);
		break;
	case 1:	// Metroid: Mother Brain Flash
		Y =g_pNesWRAM[0x98];
		if(Y != 4)
			goto LB_NES_PATCH_M2I1_ORIG;
		Y =g_pNesWRAM[0x99];
		if(Y == 0)
			goto LB_NES_PATCH_M2I1_PHASE0;
		if(Y == 6)
			goto LB_NES_PATCH_M2I1_PHASE6;
		Y--;
		if(Y == 0)
			goto LB_NES_PATCH_M2I1_PHASE1;
		A_G &= 0x10;
		if(A_G == 0)
			break;
	LB_NES_PATCH_M2I1_ONE:
		A_G = 0x2;
	LB_NES_PATCH_M2I1_ORIG:
		A_G &= 0x02;
		A_G >>=1;
		break;
	LB_NES_PATCH_M2I1_PHASE1:
		if(A_G < 9)
			goto LB_NES_PATCH_M2I1_ONE;
	LB_NES_PATCH_M2I1_PHASE0:
		if(A_G < 0x1E)
			goto LB_NES_PATCH_M2I1_ONE;
	LB_NES_PATCH_M2I1_PHASE6:
		A_G = 0;
		break;
	case 2:	// Metroid: Title Start
		A_G &= 0x03;
		if(g_pNesWRAM[0x140] == 0)
		{
			if(!A_G)
				g_pNesWRAM[0x140] = 1;
			else
				A_G = 0;
		}
		else
		{
			if(A_G)
				g_pNesWRAM[0x140] = 0;
		}
		break;
	case 3:	// TD Stage select
		{
			u8 max_stage=g_pNesWRAM[0x26];
			u8 cur_stage=g_pNesWRAM[0xc0];
			if(cur_stage>60){
				//max_stage=60;
				g_pNesWRAM[0xc0]=60;
				cur_stage=60;
			}
			if(cur_stage>max_stage){
				//cur_stage=max_stage;
				g_pNesWRAM[0x26]=cur_stage;
			}
			break;
		}
	case 4:
		//hack start
		hackWRAM05DE=1;
		break;
	case 5:
		//hack end
		hackWRAM05DE=0;
		break;
	case 6:
		//hact it!
		if(hackWRAM05DE){
			if(g_pNesWRAM[0x5de]==0x3F){
				hackWRAM05DE++;
				if(hackWRAM05DE&0x1){
					P_G|=0x80;
				}
				if(hackWRAM05DE==9)
					hackWRAM05DE = 0;
			}
			/*
			if(g_pNesWRAM[0x5de]==0x3F){
				hackWRAM05DE++;
				if(hackWRAM05DE&0x1){
					g_pNesWRAM[0x5de] = 0xFF;

				}
				if(hackWRAM05DE==9)
					hackWRAM05DE = 0;
				extern u16	g_nNesGrpVRAMAddr;
				g_nNesGrpVRAMAddr = 0;
			}

		//	P_G|=0x80;
		*/
		}
		break;
	case 7:
		//Mach Rider Save
		trlMemCopy(g_pNesSRAM,&g_pNesWRAM[0x700],0x80);
		g_pNesEmuBuf->nSaveUpdate |= 1;
		break;
	case 8:
		//Mach Rider Load
		trlMemCopy(&g_pNesWRAM[0x700],g_pNesSRAM,0x80);
		break;
	case 9:
		//SQFHJ0P_2007090A.291 Gold limit to 30000
		if(A_G<0xF0){
			if(((A_G<<8)+g_pNesWRAM[0xC0])>30000){
				g_pNesWRAM[0xC0]=0x30;
			//g_pNesWRAM[0xC1]=0x75;
				A_G=0x75;
			}
		}
		break;
		/*
	case 10:
		//for CBFH20A.246 crash bug.
		if(A_G==0xFF)
			break;
		else
			A_G++;
		break;
		*/
	}
	break;
case 6: // FixMemory  rangelzhang
		{
			int i;
			if(pPatch->sData.sA.nType==0){  //work memory write
				for(i = 0 ; i < pPatch->sData.sA.nFixcode ; i++)
								g_pNesWRAM[(pPatch->sData.sA.nIndex+i)&0x1FFF] = pPatch->pFixcode[i];
			}
			if(pPatch->sData.sA.nType==1){  //video memory write
				for(i = 0 ; i < pPatch->sData.sA.nFixcode ; i++)
								nesPpuMemDirectWrite8((u16)(pPatch->sData.sA.nIndex + i), pPatch->pFixcode[i]);
			}
				
			break;
		}	
case 8: //BG lock
	bg_lock = true;
	break;
case 9: //BG reset lock
	{
		if(bg_lock){
			bg_lock=false;
			nopcode = 0xFB;
			return nopcode;
		}
		break;
	}
	
case 11: //Gegister operate  //rangelzhang
	{
	u8 * pReg = NULL;
	if(pPatch->sData.sA.nType==0){ // operate A register
		pReg = &g_nNesCpuRegA;
	}else if(pPatch->sData.sA.nType==1){ // operate X register
		pReg = &g_nNesCpuRegX;
	}else if(pPatch->sData.sA.nType==2){ // operate Y register
		pReg = &g_nNesCpuRegY;
	}
	switch(pPatch->sData.sA.nIndex){
			case 1:			//LOAD
				*pReg = pPatch->pFixcode[0];
				break;
			case 2:          //shift right
				{
				int i;
				for(i = 0 ; i < pPatch->pFixcode[0] ; i++)
				{
					*pReg >>= 1;
				}
				}
				break;
			default:
				break;
	}
	break;
	}
case 3: // Mask
	if(pPatch->sData.sA.nIndex == 0)
	{
		// Link: BG Flash End
		if(Y != 0x4)
			goto LB_NES_PATCH_END;
	}
	else if(pPatch->sData.sA.nIndex == 1)
	{
		// NESAL0A.039: BG Flash End
		if(Y != 0x4)
			goto LB_NES_PATCH_END;
	}
	else if(pPatch->sData.sA.nIndex == 2)
	{
		//Link: BG Flash Begin NESAL0A.039: BG Flash Begin
		if(Y == 0x4)
			goto LB_NES_PATCH_END;
	}
default:
	trlSEmuShellPatchActiveClear(&g_pNesEmuBuf->sPatchActive[g_pNesEmuBuf->nPatchActive]);
	g_pNesEmuBuf->sPatchActive[g_pNesEmuBuf->nPatchActive].nIndex = (u16)nID;
	g_pNesEmuBuf->sPatchActive[g_pNesEmuBuf->nPatchActive].nMode = (u16)pPatch->sData.sA.nMode;
	g_pNesEmuBuf->nPatchActive++;
}
LB_NES_PATCH_END:
;
}
