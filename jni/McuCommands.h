#ifndef BT_COMMANDS_H
#define BT_COMMANDS_H

#include "UartProxy.h"
#include "McuReader.h"

using namespace android;

class McuCommands : public UartProxy
{
public:
	McuCommands(CMCUUart* mcu, sp<McuReader>& mcu_reader);
	virtual ~McuCommands();

	//add commands blow it
	bool sendKeyToMcu(int keyVal);
	/*************************radio command***************************/
	void sendRadioSearchToMcu();
	void sendRadioScanToMcu();
	void sendRadioSTToMcu();
	void sendRadioLocToMcu();
	void sendSearchPrevToMcu();
	void sendSearchNextToMcu();
	#if 0
	void sendRadioBandToMcu();
	void sendRadioBandToMcu(int band);
	#endif
	void sendRadioAreaToMcu(int area);
	/**************************radio command**************************/
	
	bool sendBeepToMcu(int beep);
	bool sendExitTaToMcu();
	bool sendMuteTel1S();
	bool sendUpdateAppOSRtkToMcu();
	bool onlyUpgradMcu();
	bool sendVideoAlphaToMcu(u_c alpha);
	bool sendTVHaveSigToMcu();
	bool sendTVNoSigToMcu();
	/*void sendLongHoldToMcu();*/
	void sendUpdateMucToMcu();
	void sendTest786ToMcu();
	void sendTest786ToMcu1();
	void sendRtkFailToMcu();
	void sendRtkUpdateMcuToMcu();
	void sendBtVolUnMuteToMcu();
	void sendCCDNoSingToMcu();
	void sendCCDHaveSingToMcu();
	bool sendLanguageInfoToMcu(u_c data1, u_c data2);
	bool sendParkCcdToMcu(u_c data1);
	bool sendledtypeToMcu(u_c data1);
	bool sendledtimeToMcu(u_c data1);
	bool sendOtherAppDataToMcu(u_c data1);
	bool sendArmSaveData(u_c pData);
	bool sendDVDProgressToMcu(u_c data,u_c data1);
	bool sendTouchToMcu(DWORD point);
	bool sendCMMBTouchToMcu(DWORD point);
	bool sendFreqMuteToMcu(void);
	bool sendFreqToMcu(DWORD freq);
	bool sendRdsPtyTypeToMcu(DWORD freq);
	bool sendDvdFileNumToMcu(DWORD num);
	bool sendDvdFolderNumToMcu(DWORD num);
	
	bool sendSysInfoToMcu(u_c data1,u_c data2);
	bool sendVolToMcu(int vol);
	bool sendMuteToMcu(int mute);
	bool sendFadeToMcu(int fade);
	bool sendBalToMcu(int bal);
	bool sendTrebToMcu(int treb);
	bool sendMidToMcu(int mid);
	bool sendBassToMcu(int bass);
	bool sendAudioModeToMcu(int mode);
	bool sendDefVolToMcu(int vol);
	bool sendBtVolToMcu(int vol);
	bool sendGpsVolToMcu(int vol);
	
	bool sendPEQInfoToMcu(u_c data1,u_c data2,u_c data3);
	bool sendGEQInfoToMcu(u_c data1,u_c data2);
	bool sendRadioCmd(u_c cmd,WORD Data);
	bool sendIpod_ArmPlayStateToMcu(u_c data1);
	bool sendSysSetupToMcu(u_c data1,u_c data2);
	void sendTftOnOffToMcu(bool bTftOn);
	void sendRevReqToMcu();
	void sendResetSettingToMcu();
	void sendSourceSetBitMCU(int sourceBit);
	void sendIconSetBitMCU(int iconBit);
	void sendReqWheelMax();
	bool sendRESETARMInfoToMcu();
	bool sendUpgradeInfoToMcu();
	void sendHoldToMcu();
	void sendNaviTipOnToMcu();
	void sendNaviTipOffToMcu();
	void sendvmDiscToMcu(u_c a,u_c b);
	void sendvmDiscPlayTrackToMcu(u_c a,u_c b);
	void sendTelTlakingToMcu(bool bTlakingOn);
	void sendArmReqMute1s(void);
	bool sendCanSelSaveId(u_c *pData, int num);
	bool sendCanDataOnce(u_c * pData,int num);
	bool sendCanDataRpt(u_c *pData, int num, int Rpt100ms);
	bool sendMCUState(int state);
	
#ifdef CAN_INFO_COMMUNICATION//can
	void sendCanType(u_c canType);
	void sendCarLogo(u_c carLogo);
	void sendCarType(u_c carType);
#endif
	bool sendMainCtrlInitMSGToMcu();
	void sendSourceVaildBitToMcu(u_c SourceVaildBit);
	bool isHangLongCustomer();
	void sendSourceToMcu(int source);
private:
	sp<McuReader> m_pMcuReader;
};


#endif

