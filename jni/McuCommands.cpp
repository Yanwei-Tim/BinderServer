#define LOG_TAG "mcu_commands"
#include <utils/Log.h>

#include "IncludeAll.h"

#include "McuCommands.h"

McuCommands::McuCommands(CMCUUart* mcu, sp<McuReader>& reader)
	:UartProxy(mcu)
{
	m_pMcuReader = reader;
}

McuCommands::~McuCommands()
{
	//parent destructor method will be called auto;
	//~UartProxy();
	if(m_pMcuReader != NULL)
	{
		m_pMcuReader->~McuReader();
	}
}

//add commands blow it
bool McuCommands::sendKeyToMcu(int keyVal)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x88,(u_c)keyVal,0x01,0x0A};
	return getUart()->writeUart(buffSendData,6);
}

/*************************radio command***************************/
void McuCommands::sendRadioSearchToMcu()
{
	sendKeyToMcu(C_KEY_APS);
}
void McuCommands::sendRadioScanToMcu()
{
	sendKeyToMcu(C_KEY_RADIO_INTRO);
}
void McuCommands::sendRadioSTToMcu()
{
	sendKeyToMcu(C_KEY_ST);
}
void McuCommands::sendRadioLocToMcu()
{
	sendKeyToMcu(C_KEY_LOC);
}
void McuCommands::sendSearchPrevToMcu()
{
	sendKeyToMcu(C_KEY_PRE);
}
void McuCommands::sendSearchNextToMcu()
{
	sendKeyToMcu(C_KEY_NEXT);
}
#if 0
void McuCommands::sendRadioBandToMcu()
{
	sendKeyToMcu(C_KEY_BAND);
}
void McuCommands::sendRadioBandToMcu(int band)
{
	sendSysInfoToMcu(ARM_DATA_RADIO_BAND,band);
}
#endif
void McuCommands::sendRadioAreaToMcu(int area)
{
	sendSysInfoToMcu(ARM_DATA_RADIO_AREA,area);
}
bool McuCommands::sendFreqToMcu(DWORD freq)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB1,(u_c)(freq>>8),(u_c)(freq),0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}




/**************************radio command**************************/


bool McuCommands::isHangLongCustomer()
{
	/*const char hanglong[] = "70900";
	string temp = g_pMcuData->sSystem.customer_id;
	if(temp.empty())
	{
		ALOGI("customer id is empty");
		return true;
	}
	if(strcmp(g_pMcuData->sSystem.customer_id,hanglong) == 0)
	{
		return true;
	}*/
	return false;
}


bool McuCommands::sendBeepToMcu(int beep)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x89,0x00,(u_c)beep,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendExitTaToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x42,0x01,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendMuteTel1S()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x99,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendUpdateAppOSRtkToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xAD,0x01,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::onlyUpgradMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xAD,0x81,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendVideoAlphaToMcu(u_c alpha)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA2,alpha,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendTVHaveSigToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8B,0x41,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendTVNoSigToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8B,0x41,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
void McuCommands::sendUpdateMucToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x9C,0xA0,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	ALOGI("\r\n sendUpdateMucToMcu \r\n");
}

void McuCommands::sendTest786ToMcu()
{
	u_c buffSendData[3] = {0xAA,0xA2,0x05};
	getUart()->writeUart(buffSendData,3);
}

void McuCommands::sendTest786ToMcu1()
{
	u_c buffSendData[3] = {0xAA,0x55,0x55};
	getUart()->writeUart(buffSendData,3);
}

void McuCommands::sendRtkFailToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xEE,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
//9c a0
void McuCommands::sendRtkUpdateMcuToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xED,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);

	/*u_c buffSendData1[6] = {0xFF,0xAA,0xF0,0x01,0x00,0x0A};
	getUart()->writeUart(buffSendData1,6);*/
}

void McuCommands::sendBtVolUnMuteToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB9,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendCCDNoSingToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB4,0x0B,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}

void McuCommands::sendCCDHaveSingToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB4,0x0B,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
}

bool McuCommands::sendLanguageInfoToMcu(u_c data1, u_c data2)//ÓïÑÔ¸ü¸Ä
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA0,data1,data2,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendParkCcdToMcu(u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8B,0x80,data1,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendledtypeToMcu(u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA0,0x09,data1,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendledtimeToMcu(u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA0,0x0A,data1,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendOtherAppDataToMcu(u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA0,0x12,data1,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendArmSaveData(u_c pData)
{
	int len = 13;
	u_c *pbuffSendData = new u_c[len];
	memset(pbuffSendData, 0, len);
	pbuffSendData[0] = 0xFF;
	pbuffSendData[1] = 0xAA;
	pbuffSendData[2] = 0xC8;
	pbuffSendData[3] = len;
	pbuffSendData[4] = pData;
	pbuffSendData[5] = 0x00;
	pbuffSendData[6] = 0x00;
	pbuffSendData[7] = 0x00;
	pbuffSendData[8] = 0x00;
	pbuffSendData[9] = 0x00;
	pbuffSendData[10] = 0x00;
	pbuffSendData[11] = 0x00;
	pbuffSendData[12] = 0x0A;
	getUart()->writeUart(pbuffSendData,len);
	if(pbuffSendData != NULL)
	{
		delete pbuffSendData;
		pbuffSendData = NULL;
	}
	return true;
}

bool McuCommands::sendDVDProgressToMcu(u_c data,u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x01,0xF4,0x00,0x0A};
	buffSendData[2] = data;
	buffSendData[3] = data1;
	getUart()->writeUart(buffSendData,6);
	return true;
}
bool McuCommands::sendTouchToMcu(DWORD point)
{
	int x = point>>16;
	int y = point&0xFFFF;
	if(m_pMcuReader->getMcuDataPtr()->sDeveice.display_y!=0&&m_pMcuReader->getMcuDataPtr()->sDeveice.display_x!=0)
	{
		x = x*256/m_pMcuReader->getMcuDataPtr()->sDeveice.display_x;
		y = y*256/m_pMcuReader->getMcuDataPtr()->sDeveice.display_y;
	}else
	{
		x = x*256/1024;
		y = y*256/600;
	}
	if(x > 255)
	{
		x = 255;
	}
	if(y > 255)
	{
		y = 255;
	}
	u_c buffSendData[6] = {0xFF,0xAA,0x83,(u_c)(x),(u_c)(y),0x0A};
	getUart()->writeUart(buffSendData,6);
	return true;
}


bool McuCommands::sendCMMBTouchToMcu(DWORD point)
{
	int x = point>>16;
	int y = point&0xFFFF;
	if(m_pMcuReader->getMcuDataPtr()->sDeveice.display_y!=0&&m_pMcuReader->getMcuDataPtr()->sDeveice.display_x!=0)
	{
		x = x*256/m_pMcuReader->getMcuDataPtr()->sDeveice.display_x;
		y = y*256/m_pMcuReader->getMcuDataPtr()->sDeveice.display_y;
	}else
	{
		x = x*256/800;
		y = y*256/480 -12; //CMMB 
	}
	if(x > 255)
	{
		x = 255;
	}
	if(y > 255)
	{
		y = 255;
	}
	u_c buffSendData[6] = {0xFF,0xAA,0x9F,(u_c)(x),(u_c)(y),0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendFreqMuteToMcu(void)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB0,0,0,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendRdsPtyTypeToMcu(DWORD freq)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB1,(u_c)(freq>>8),(u_c)(freq),0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendDvdFileNumToMcu(DWORD num)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA5,(u_c)(num>>8),(u_c)(num),0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendDvdFolderNumToMcu(DWORD num)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA6,(u_c)(num>>8),(u_c)(num),0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendSysInfoToMcu(u_c data1,u_c data2)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8B,data1,data2,0x0A};
	return getUart()->writeUart(buffSendData,6);
}
bool McuCommands::sendVolToMcu(int vol)
{
	return sendSysInfoToMcu(ARM_DATA_VOL, vol);
}
bool McuCommands::sendMuteToMcu(int mute)
{
	return sendSysInfoToMcu(ARM_DATA_MUTE, mute);
}
bool McuCommands::sendDefVolToMcu(int vol)
{
	return sendSysInfoToMcu(ARM_DATA_DEFVOL, vol);
}
bool McuCommands::sendBtVolToMcu(int vol)
{
	return sendSysInfoToMcu(ARM_DATA_BTVOL, vol);
}
bool McuCommands::sendGpsVolToMcu(int vol)
{
	return sendSysInfoToMcu(ARM_DATA_GPSVOL, vol);
}
bool McuCommands::sendFadeToMcu(int fade)
{
	return sendSysInfoToMcu(ARM_DATA_FADE, fade);
}
bool McuCommands::sendBalToMcu(int bal)
{
	return sendSysInfoToMcu(ARM_DATA_BAL, bal);
}
bool McuCommands::sendTrebToMcu(int treb)
{
	return sendSysInfoToMcu(ARM_DATA_TREB, treb);
}
bool McuCommands::sendMidToMcu(int mid)
{
	return sendSysInfoToMcu(ARM_DATA_MID, mid);
} 
bool McuCommands::sendBassToMcu(int bass)
{
	return sendSysInfoToMcu(ARM_DATA_BASS, bass);
}
bool McuCommands::sendAudioModeToMcu(int mode)
{
	return sendSysInfoToMcu(ARM_DATA_AUDIOMODE, mode);
}



bool McuCommands::sendPEQInfoToMcu(u_c data1,u_c data2,u_c data3)
{
	u_c buffSendData[10] = {0xFF,0xAA,0x70,0x0A,data1,data2,data3,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,10);
	return(0);
}

bool McuCommands::sendGEQInfoToMcu(u_c data1,u_c data2)
{
	u_c buffSendData[10] = {0xFF,0xAA,0x71,0x09,data1,data2,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,9);
	return(0);
}

bool McuCommands::sendRadioCmd(u_c cmd,WORD Data)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x00,0x00,0x00,0x0A};

	buffSendData[2] = cmd;
	buffSendData[3] = (Data >> 8)&0xFF;
	buffSendData[4] = Data&0xFF;
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendIpod_ArmPlayStateToMcu(u_c data1)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xB3,data1,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

bool McuCommands::sendSysSetupToMcu(u_c data1,u_c data2)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xA0,data1,data2,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}

void McuCommands::sendTftOnOffToMcu(bool bTftOn)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x9A,0x00,0x00,0x0A};
	if(bTftOn)
	{
		buffSendData[3] = 0x00;
	}
	else
	{
		buffSendData[3] = 0x01;
	}
	getUart()->writeUart(buffSendData,6);
}

void McuCommands::sendRevReqToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x9D,0x01,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
	ALOGI("===SendRevReqToMcu===");
}
void McuCommands::sendResetSettingToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8A,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendSourceSetBitMCU(int sourceBit)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xDD,0x00,0x00,0x0A};
	buffSendData[3] = (sourceBit>>8)&0xFF;
	buffSendData[4] = sourceBit&0xFF;
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendIconSetBitMCU(int iconBit)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xDE,0x00,0x00,0x0A};
	buffSendData[3] = (iconBit>>8)&0xFF;
	buffSendData[4] = iconBit&0xFF;
	getUart()->writeUart(buffSendData,6);
}

void McuCommands::sendReqWheelMax()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x93,0x01,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}

void McuCommands::sendSourceToMcu(int source)
{
	u_c buffSendData[6] = {0xFF,0xAA,ARM_RECEIVE_SOURCE,(u_c)source,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}

bool McuCommands::sendRESETARMInfoToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x9C,0x05,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
bool McuCommands::sendUpgradeInfoToMcu()
{

	u_c buffSendData[6] = {0xFF,0xAA,ARM_RECEIVE_RESUME_REQ,0xA0,0x01,0x0A};
	getUart()->writeUart(buffSendData,6);
	return(0);
}
//heartbeat packets
void McuCommands::sendHoldToMcu()
{
	//u_c buffSendData[6] = {0xFF,0xAA,0x9E,0x17,0x70,0x0A}; //1 min
	//u_c buffSendData[6] = {0xFF,0xAA,0x9E,0xEA,0x60,0x0A}; //10 min
	u_c buffSendData[6] = {0xFF,0xAA,0x9E,0x75,0x30,0x0A}; //5 min
	getUart()->writeUart(buffSendData,6);
}

void McuCommands::sendNaviTipOnToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x91,0x01,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendNaviTipOffToMcu()
{
	u_c buffSendData[6] = {0xFF,0xAA,0x91,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendvmDiscToMcu(u_c a,u_c b)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xC6,0x01,0xF4,0x0A};
	buffSendData[3] = a;
	buffSendData[4] = b;
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendvmDiscPlayTrackToMcu(u_c a,u_c b)
{
	u_c buffSendData[6] = {0xFF,0xAA,0xCA,0x01,0xF4,0x0A};
	buffSendData[3] = a;
	buffSendData[4] = b;
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendTelTlakingToMcu(bool bTlakingOn)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x97,0x00,0x00,0x0A};
	if(bTlakingOn)
	{
		buffSendData[3] = 0x01;
	}
	else
	{
		buffSendData[3] = 0x00;
	}
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendArmReqMute1s(void)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x99,0x00,0x00,0x0A};
	getUart()->writeUart(buffSendData,6);
}
bool McuCommands::sendCanSelSaveId(u_c *pData, int num)
{
	if(pData == NULL)
	{
		ALOGE("can data point null\r\n");
		return false;
	}
	int len = num+6;
	u_c* pbuffSendData = new u_c[len];
	memset(pbuffSendData, 0, len);
	pbuffSendData[0] = 0xff;
	pbuffSendData[1]=0xAA;
	pbuffSendData[2] = ARM_COMMAND_CAN_SEL_SAVE_ID;
	pbuffSendData[3] = len;
	pbuffSendData[4] = 0;
	memcpy(&pbuffSendData[5],pData,num);
	pbuffSendData[len-1] = 0x0A;
	
	getUart()->writeUart(pbuffSendData,len);
	delete pbuffSendData;
	return true;
}
bool McuCommands::sendCanDataOnce(u_c * pData,int num)
{
	if(pData == NULL)
	{
		ALOGE("can data point null\r\n");
		return false;
	}
	int len = num+6;
	u_c* pbuffSendData = new u_c[len];
	memset(pbuffSendData, 0, len);
	pbuffSendData[0] = 0xff;
	pbuffSendData[1]=0xAA;
	pbuffSendData[2] = ARM_COMMAND_CAN_DATA_ONCE;
	pbuffSendData[3] = len;
	pbuffSendData[4] = 0;
	memcpy(&pbuffSendData[5],pData,num);
	pbuffSendData[len-1] = 0x0A;
	
	getUart()->writeUart(pbuffSendData,len);
	//ALOGI("-----%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x"
	//	,pbuffSendData[0],pbuffSendData[1],pbuffSendData[2],pbuffSendData[3]
	//	,pbuffSendData[4],pbuffSendData[5],pbuffSendData[6],pbuffSendData[7]
	//	,pbuffSendData[8],pbuffSendData[9],pbuffSendData[10],pbuffSendData[11]
	//	);
	delete pbuffSendData;
	return true;
}

bool McuCommands::sendCanDataRpt(u_c *pData, int num, int Rpt100ms)
{
	if (pData == NULL)
	{
		ALOGE("can data point err!");
		return false;
	}
	
	//FF, AA, C0, len, rev, rpt time, can pkg..., 0x0A
	int len = num +7;
	u_c* pbuffSendData = new u_c[len];
	
	memset(pbuffSendData, 0, len);
	pbuffSendData[0] = 0xFF;
	pbuffSendData[1] = 0xAA;
	pbuffSendData[2] = ARM_COMMAND_CAN_DATA_RPT;
	pbuffSendData[3] = (u_c)len;
	pbuffSendData[4] = 0;	//±£Áô
	pbuffSendData[5] = (u_c)Rpt100ms;
	memcpy(&pbuffSendData[6], pData, num);
	pbuffSendData[len-1] = 0x0A;
	
	bool bOk = getUart()->writeUart(pbuffSendData, len);
	//ALOGI("-----%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x"
	//	,pbuffSendData[0],pbuffSendData[1],pbuffSendData[2],pbuffSendData[3]
	//	,pbuffSendData[4],pbuffSendData[5],pbuffSendData[6],pbuffSendData[7]
	//	,pbuffSendData[8],pbuffSendData[9],pbuffSendData[10],pbuffSendData[11]
	//	,pbuffSendData[12]);

	if (!bOk)
	{
		ALOGE("*********Error! Write Uart fail!*******");
	}
	
	delete pbuffSendData;
	
	return true;
}


bool McuCommands::sendMCUState(int state)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x8E,0x07,0x00,0x0A};
	buffSendData[3] = state;
	getUart()->writeUart(buffSendData,6);
	return true;
}


#ifdef CAN_INFO_COMMUNICATION//can
void McuCommands::sendCanType(u_c canType)
{
	u_c buffSendData[6] = {0xFF,0xAA,MCU_COMMAND_FACTORY,ARM_DATA_CAN_COMPANY,canType,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendCarLogo(u_c carLogo)
{
	u_c buffSendData[6] = {0xFF,0xAA,MCU_COMMAND_FACTORY,ARM_DATA_CAN_LOGO,carLogo,0x0A};
	getUart()->writeUart(buffSendData,6);
}
void McuCommands::sendCarType(u_c carType)
{
	u_c buffSendData[6] = {0xFF,0xAA,MCU_COMMAND_FACTORY,ARM_DATA_CAN_TYPE,carType,0x0A};
	getUart()->writeUart(buffSendData,6);
}
#endif

bool McuCommands::sendMainCtrlInitMSGToMcu()
{
	ALOGI("send main ctrl init ok msg to mcu!!!"); 
	u_c buffSendData[6] = {0xFF,0xAA,0x80,0x02,0x01,0x0A};//ACC debug
	getUart()->writeUart(buffSendData,6);
	buffSendData[2] = 0x81;
	getUart()->writeUart(buffSendData,6);
	getUart()->writeUart(buffSendData,6);
	getUart()->writeUart(buffSendData,6);
	return true;

}
void McuCommands::sendSourceVaildBitToMcu(u_c SourceVaildBit)
{
	u_c buffSendData[6] = {0xFF,0xAA,0x87,0x00,0x00,0x0A};
	buffSendData[3] = SourceVaildBit;
	getUart()->writeUart(buffSendData,6);
}




