

#define LOG_TAG "mcu_reader"
//#define LOG_NDEBUG 0
#include <utils/Log.h>

#include "IncludeAll.h"
#include "McuService.h"


#include "McuReader.h"

//using namespace android;

#define PARSE_DEBUG 0
#define MCU_READ_MAX 64

McuReader::McuReader(CMCUUart* mcu_uart)
	:UartProxy(mcu_uart)
{
	
}

McuReader::McuReader(CMCUUart* mcu_uart, McuService* ms)
	:UartProxy(mcu_uart),mMcuService(ms)
{
	
}

McuReader::~McuReader()
{
	ALOGI("mcu reader destory...");
}

void McuReader::start_read_mcu_data_loop()
{
	this->run("mcu_reader");
}
bool McuReader::threadLoop()
{
	static u_c read_buff[MCU_READ_MAX];
	static u_t read_len;
	
	if(getUart() != NULL && getUart()->isUartOpened())
	{
		getUart()->readUart(read_buff,read_len);
		if(read_len > 0)
		{
			if(PARSE_DEBUG)
			{
				ALOGI("read mcu data 0x%02x 0x%02x 0x%02x 0x%02x", read_buff[3], read_buff[4], read_buff[5], read_buff[6]);
			}
			start_parse_data(read_buff, read_len);
		}
	}
	return true;
}

void McuReader::start_parse_data(const u_c ptr[], int len)
{
	static u_c cache_buff[512];
	static int consumed_size = 0;
	static int size = 0;
	
	if(len <= 512-consumed_size)
	{
		memcpy(&cache_buff[size], ptr, len);
		size += len;
		
		parse_state state;
		state.ptr = cache_buff;
		state.ptr_length = size;
		state.consumed_index = consumed_size;
		
		if((size-consumed_size) < 6)
		{
			if(PARSE_DEBUG)
			ALOGI("cache buff is less than 6(unconsumed size[%d])", size-consumed_size);
			return;
		}

		while(1)
		{
			state.consumed_index = consumed_size;
			
			int consumed = parse_data_inner(state);
			consumed_size += consumed;

			if(PARSE_DEBUG)
			{
				ALOGI("consumed[%d]", consumed);
				ALOGI("consumed_size[%d]", consumed_size);
				ALOGI("size[%d]", size);
			}
			
			if(consumed == 0)
			{
				break;
			}
		}
		
		if((size-consumed_size) <= 0 && consumed_size >= 256)
		{
			ALOGI("already consume cache buff over, so clean cache buff(size[%d])", size);
			memset(cache_buff, 0, sizeof(cache_buff));
			consumed_size = 0;
			size = 0;
		}
	}
	else
	{
		ALOGE("consumed_size[%d]", consumed_size);
		ALOGE("error:receive buf is bigger than cache buff, you must create bigger catche buff");
	}
}

//return consumed size
int McuReader::parse_data_inner(parse_state& state)
{
	int consumed_index = 0;

	u_c* ptr = &state.ptr[state.consumed_index];

	//seek the head of frame,recursive
	//find first 0xFF 0xAA
	while((state.ptr_length-consumed_index-state.consumed_index) >= 6 && ptr[0] != 0xFF && ptr[1] != 0xAA)
	{
		consumed_index ++;
		ptr++;
	}

	//match the frame
	if((state.ptr_length-consumed_index-state.consumed_index) < 6)
	{
		if(PARSE_DEBUG)
			ALOGE("error: the frame is too short(less than 6)");
		
		return consumed_index;
	}
		
	if(ptr[0] == 0xFF
			&&ptr[1] == 0xAA)
	{
		int cmd_len = ptr[2];
		if(cmd_len <= (state.ptr_length-consumed_index-state.consumed_index))
		{
			if(ptr[cmd_len-1] == 0x0A)
			{
				u_c* cmd = ptr;
				int len = cmd_len;
				parse_single_cmd(cmd, len);
				if(cmd_len == (state.ptr_length-consumed_index-state.consumed_index))
				{
					if(PARSE_DEBUG)
					ALOGI("find the last cmd");
					
					consumed_index += cmd_len;
					return consumed_index;
				}
				else
				{
					//ALOGI("tip: find the next cmd...\r\n");
					consumed_index += cmd_len;
					return consumed_index;
				}
			}
			else
			{
				if(PARSE_DEBUG)
				ALOGE("error: can not find the end of frame(0x0A)!!");
				
				return consumed_index;
			}
		}
		else
		{
			if(PARSE_DEBUG)
			ALOGE("error:the frame is not complete!!");
			
			return consumed_index;
		}
	}
	else
	{
		ALOGE("error: can not find the head of frame(0xFF, 0xAA), almost do not happen");
		return consumed_index;
	}
}

//0xFF 0xAA len 0x82 data... 0x0A
void McuReader::parse_sysinfo(const BYTE *pBuff,int num)
{
	BYTE cmd = pBuff[3];
	switch(pBuff[4])
	{
	case ARM_DATA_YEAR :
		getMcuDataPtr()->sSettins.year = pBuff[5];
		ALOGI("year = %d", getMcuDataPtr()->sSettins.year); 		
		break;
	case ARM_DATA_MONTH :
		getMcuDataPtr()->sSettins.month = pBuff[5];
		ALOGI("month = %d", getMcuDataPtr()->sSettins.month); 		
		break;
	case ARM_DATA_DAY :
		getMcuDataPtr()->sSettins.day = pBuff[5];
		ALOGI("day = %d", getMcuDataPtr()->sSettins.day); 		
		break;
	case ARM_DATA_HOUR :
		getMcuDataPtr()->sSettins.hour = pBuff[5];
		ALOGI("hour = %d", getMcuDataPtr()->sSettins.hour);		
		break;
	case ARM_DATA_MINUTE :
		getMcuDataPtr()->sSettins.minute = pBuff[5];
		ALOGI("minute = %d", getMcuDataPtr()->sSettins.minute);			
		break;
	case ARM_DATA_SECOND :
		getMcuDataPtr()->sSettins.second = pBuff[5];
		ALOGI("second = %d", getMcuDataPtr()->sSettins.second); 		
		break;
	case ARM_DATA_TIME12H :
		getMcuDataPtr()->sSettins.b12H = pBuff[5];		
		ALOGI("b12H = %d", getMcuDataPtr()->sSettins.b12H); 
		break;
	case ARM_DATA_VOL: {
		int vol = pBuff[5];
		set_settings_volume(vol);
		ALOGI("vol = %d", vol); 	
	} break;
	case ARM_DATA_BASS: {
		int bass = pBuff[5];
		set_settings_bass(bass);
		ALOGI("bass = %d", bass);
	} break;
	case ARM_DATA_TREB: {
		int treb = pBuff[5];
		set_settings_treb(treb);
		ALOGI("treb = %d", treb);
	} break;
	case ARM_DATA_MID: {
		int mid = pBuff[5];
		set_settings_mid(mid);
		ALOGI("mid = %d", mid);
	} break;
	case ARM_DATA_FADE: {
		int fade = pBuff[5];
		set_settings_fade(fade);
		ALOGI("fade = %d", fade);
	} break;
	case ARM_DATA_BAL: {
		int bal = pBuff[5];
		set_settings_bal(bal);
		ALOGI("bal = %d", bal);
	} break;
	case ARM_DATA_AUDIOMODE: {
		int mode = pBuff[5];
		set_settings_audio_mode(mode);
		ALOGI("audioMode = %d", mode); 		
	} break;
	case ARM_DATA_MUTE: {
		bool bMute = (bool)pBuff[5];
		set_settings_mute(bMute);
		ALOGI("bMute = %d", bMute);
	} break;
	case ARM_DATA_BRIGHT: {
		bool bright = pBuff[5];
		set_settings_brightness(bright);
		ALOGI("bright = %d", bright);
	} break;
	case ARM_DATA_CONTRAST:
		getMcuDataPtr()->sSettins.contrast = pBuff[5];
		ALOGI("contrast = %d", getMcuDataPtr()->sSettins.contrast);			
		break;
	case ARM_DATA_COLOR :
		getMcuDataPtr()->sSettins.color = pBuff[5];
		ALOGI("color = %d", getMcuDataPtr()->sSettins.color);			
		break;
	case ARM_DATA_VIDEOMODE :
		getMcuDataPtr()->sSettins.videoMode = pBuff[5];
		ALOGI("videoMode = %d", getMcuDataPtr()->sSettins.videoMode); 
		break;
	case ARM_DATA_TUNERSYS :
		getMcuDataPtr()->sSettins.tunerSys = pBuff[5];	
		break;
	case ARM_DATA_TVSYS :
		getMcuDataPtr()->sSettins.tvSys = pBuff[5];			
		break;
	case ARM_DATA_BEEP: {
		bool beep = (bool)pBuff[5];
		set_settings_key_sound(beep);
		ALOGI("beep = %d", beep);
	} break;
	case ARM_DATA_SYSFLAG :
		getMcuDataPtr()->sSettins.sysFlag = pBuff[5];
		ALOGI("sysFlag = [%d]", getMcuDataPtr()->sSettins.sysFlag); 			
		break;
	case ARM_DATA_BTVOL: {
		int vol = pBuff[5];
		set_settings_btvol(vol);
		ALOGI("btvol = %d", vol);
	} break;
	case ARM_DATA_FREQ30 :
		getMcuDataPtr()->sSettins.freq30 = pBuff[5];
		ALOGI("freq30 = %d", getMcuDataPtr()->sSettins.freq30); 			
		break;
	case ARM_DATA_FREQ60 :
		getMcuDataPtr()->sSettins.freq60 = pBuff[5];
		ALOGI("freq60 = %d", getMcuDataPtr()->sSettins.freq60); 			
		break;
	case ARM_DATA_FREQ125 :
		getMcuDataPtr()->sSettins.freq125 = pBuff[5];
		ALOGI("freq125 = %d", getMcuDataPtr()->sSettins.freq125); 			
		break;
	case ARM_DATA_FREQ250 :
		getMcuDataPtr()->sSettins.freq250 = pBuff[5];
		ALOGI("freq250 = %d", getMcuDataPtr()->sSettins.freq250); 			
		break;
	case ARM_DATA_FREQ500 :
		getMcuDataPtr()->sSettins.freq500 = pBuff[5];
		ALOGI("freq500 = %d", getMcuDataPtr()->sSettins.freq500);
		break;
	case ARM_DATA_FREQ1K :
		getMcuDataPtr()->sSettins.freq1K = pBuff[5];
		ALOGI("freq1K = %d", getMcuDataPtr()->sSettins.freq1K); 			
		break;
	case ARM_DATA_FREQ2K :
		getMcuDataPtr()->sSettins.freq2K = pBuff[5];
		ALOGI("freq2K = %d", getMcuDataPtr()->sSettins.freq2K); 		
		break;
	case ARM_DATA_FREQ4K  :
		getMcuDataPtr()->sSettins.freq4K = pBuff[5];
		ALOGI("freq4K = %d", getMcuDataPtr()->sSettins.freq4K); 			
		break;
	case ARM_DATA_FREQ8K :
		getMcuDataPtr()->sSettins.freq8K = pBuff[5];
		ALOGI("freq8K = %d", getMcuDataPtr()->sSettins.freq8K); 		
		break;
	case ARM_DATA_FREQ16K :
		getMcuDataPtr()->sSettins.freq16K = pBuff[5];
		ALOGI("freq16K = %d", getMcuDataPtr()->sSettins.freq16K); 		
		break;
	case ARM_DATA_DSP1 :
		getMcuDataPtr()->sSettins.bDsp1 = pBuff[5];
		ALOGI("bDsp1 = %d", getMcuDataPtr()->sSettins.bDsp1); 			
		break;
	case ARM_DATA_DSP2 :
		getMcuDataPtr()->sSettins.bDsp2 = pBuff[5];
		ALOGI("bDsp2 = %d", getMcuDataPtr()->sSettins.bDsp2); 			
		break;
	case ARM_DATA_DSP3 :
		getMcuDataPtr()->sSettins.bDsp3 = pBuff[5];
		ALOGI("bDsp3 = %d", getMcuDataPtr()->sSettins.bDsp3);		
		break;
	case ARM_DATA_GPSVOL: {
		int vol = pBuff[5];
		set_settings_gpsvol(vol);
		ALOGI("gpsvol = %d", vol);
	} break;
	case ARM_DATA_SYSFLAG2 :
		getMcuDataPtr()->sSettins.sysFlag2 = pBuff[5];
		ALOGI("sysFlag2 = %d", getMcuDataPtr()->sSettins.sysFlag2); 			
		break;
	case ARM_DATA_DEFVOL: {
		int defvol = pBuff[5];
		set_settings_defvol(defvol);
		ALOGI("defvol = %d", defvol);
	} break;
	case ARM_DATA_ARMSAVE1 :
		getMcuDataPtr()->sSettins.save1 = pBuff[5];
		ALOGI("save1 = %d", getMcuDataPtr()->sSettins.save1); 
		break;
	case ARM_DATA_ARMSAVE2 :
		getMcuDataPtr()->sSettins.save2 = pBuff[5];
		break;
	case ARM_DATA_ARMSAVE3 :
		getMcuDataPtr()->sSettins.save3 = pBuff[5];
		break;
	case ARM_DATA_TV_SIGNAL:
		getMcuDataPtr()->sTVInfo.tvSigCheck=1;
		ALOGI("ARM_DATA_TVSINGCHECK  tvSigCheck = %d",getMcuDataPtr()->sTVInfo.tvSigCheck);
		break;		
	case ARM_DATA_SUBWOOF:
		getMcuDataPtr()->sSettins.subwoof = pBuff[5];
		ALOGI("subwoof = %d", getMcuDataPtr()->sSettins.subwoof);		
		break;
	case ARM_DATA_SRS_SW:
		getMcuDataPtr()->sSettins.bSrsOn = pBuff[5];
		ALOGI("bSrsOn = %d", getMcuDataPtr()->sSettins.bSrsOn);
		break;
	case ARM_DATA_LOW_FO :
		getMcuDataPtr()->sSettins.lowFo = pBuff[5];
		ALOGI("lowFo = %d", getMcuDataPtr()->sSettins.lowFo);		
		break;
	case ARM_DATA_MID_FO :
		getMcuDataPtr()->sSettins.midFo = pBuff[5];
		ALOGI("midFo = %d", getMcuDataPtr()->sSettins.midFo);		
		break;
	case ARM_DATA_HIGH_FO :
		getMcuDataPtr()->sSettins.highFo = pBuff[5];
		ALOGI("highFo = %d", getMcuDataPtr()->sSettins.highFo); 			
		break;
	case ARM_DATA_ADJ_BACKVOL:
		getMcuDataPtr()->sSettins.parkvol = pBuff[5];
		ALOGI("parkvol = %d", getMcuDataPtr()->sSettins.parkvol); 
		break;
	case ARM_DATA_CAMARAMIX:
		getMcuDataPtr()->sSettins.parkccd = pBuff[5];
		ALOGI("parkccd = %d", getMcuDataPtr()->sSettins.parkccd); 
		break;
	case ARM_DATA_USER_BASS:
		getMcuDataPtr()->sSettins.userBass = pBuff[5];
		ALOGI("userBass = %d", getMcuDataPtr()->sSettins.userBass); 
		break;
	case ARM_DATA_USER_MID:
		getMcuDataPtr()->sSettins.userMid = pBuff[5];
		ALOGI("userMid = %d", getMcuDataPtr()->sSettins.userMid); 
		break;
	case ARM_DATA_USER_TREB:
		getMcuDataPtr()->sSettins.userTreb = pBuff[5];
		ALOGI("userTreb = %d", getMcuDataPtr()->sSettins.userTreb); 
		break;
	default :
		ALOGI("the frame do not used"); 
		ALOGI("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x  Len:[%d]",pBuff[0],pBuff[1],pBuff[2],pBuff[3],pBuff[4],pBuff[5],pBuff[6],pBuff[7],pBuff[8],num);
		break;
	}
}

//0xFF 0xAA len 0x89 data... 0x0A
void McuReader::parse_setupinfo(const BYTE *pBuff,int num)
{
	switch(pBuff[4])
	{
	case ARM_DATA_RADIO_AREA: {
		int area = pBuff[5];
		set_radio_area(area);
		ALOGI("radioArea = %d", area);
	} break;
	case ARM_DATA_LANG_SEL:
		getMcuDataPtr()->nLanguage = pBuff[5];
		ALOGI("nLanguage = %d", getMcuDataPtr()->nLanguage);
		break;
	case ARM_DATA_FM_STOP_VAL :
		getMcuDataPtr()->sExtInfo.fmStopVal = pBuff[5];
		ALOGI("fmStopVal = %d", getMcuDataPtr()->sExtInfo.fmStopVal);	
		break;
	case ARM_DATA_AM_STOP_VAL :
		getMcuDataPtr()->sExtInfo.amStopVal = pBuff[5];
		ALOGI("amStopVal = %d", getMcuDataPtr()->sExtInfo.amStopVal);			
		break;
	case ARM_DATA_DSP_SEL:
		getMcuDataPtr()->iSrsType = pBuff[5];
		ALOGI("iSrsType = %d", getMcuDataPtr()->iSrsType);
		break;
	case ARM_DATA_LED_TYPE:
		getMcuDataPtr()->ledtype = pBuff[5];
		ALOGI("ledtype = %d", getMcuDataPtr()->ledtype);
		break;
	case ARM_DATA_LED_TIME:
		getMcuDataPtr()->ledtime = pBuff[5];
		ALOGI("ledtime = %d", getMcuDataPtr()->ledtime);
		break;
	case ARM_DATA_RDS_ONOFF:
		getMcuDataPtr()->sDeveice.RdsSel =  (bool)pBuff[5];
		ALOGI("RdsSel = %d", getMcuDataPtr()->sDeveice.RdsSel);
		break;
	case ARM_DATA_TIME_AREA:

		break;
	case ARM_DATA_BT_MODULE:
		getMcuDataPtr()->sExtInfo.btModule = pBuff[5];
		ALOGI("receive bt Modele:%d",getMcuDataPtr()->sExtInfo.btModule);
		break;
	case ARM_DATA_CAN_COMPANY:
		getMcuDataPtr()->sCanInfo.canType = pBuff[5];
		break;
	case ARM_DATA_CAN_LOGO:
		getMcuDataPtr()->sCanInfo.carType &= 0x00ff;		
		getMcuDataPtr()->sCanInfo.carType |= (pBuff[5]<<8);
		break;
	case ARM_DATA_CAN_TYPE:
		getMcuDataPtr()->sCanInfo.carType &= 0xff00;
		getMcuDataPtr()->sCanInfo.carType |= (pBuff[5]);
		ALOGI("Receive Car Type:%x,CanBus Compan:%d",getMcuDataPtr()->sCanInfo.carType,getMcuDataPtr()->sCanInfo.canType);
		break;
	case ARM_DATA_REBOOTMODE:
		//PostMessage(g_hWnd,MSG_SYSTEM_REBOOT_MODE,pBuff[5],0);
		break;
	case ARM_DATA_DARAR_SW:
		getMcuDataPtr()->sSettins.radarSwitch = pBuff[5];
		ALOGI("radar switch = %d", pBuff[5]);
		break;
	default:
		ALOGE("the frame do not used"); 
		ALOGE("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x  Len:[%d]",pBuff[0],pBuff[1],pBuff[2],pBuff[3],pBuff[4],pBuff[5],pBuff[6],pBuff[7],pBuff[8],num);
		break;
	}
}


//0xFF,0xAA,len,data0,data1,...,0x0A
void McuReader::parse_single_cmd(const u_c* pBuff, int num)
{
	static bool timeUpdateReq = 0;
	int temp;
	if(pBuff[0] != 0xFF || pBuff[1] != 0xAA || pBuff[num-1] != 0x0A ||  num < 6)
	{
		ALOGE("!!mcu com check sum err!!\r\n");
		return;
	}
	if(pBuff[0] == 0xFF && pBuff[1] == 0xAA && pBuff[3] == 0x95 && num == 6 )
	{
		return ;
	}
	ALOGI("arminfo is 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x  Len:[%d]",pBuff[0],pBuff[1],pBuff[2],pBuff[3],pBuff[4],pBuff[5],pBuff[6],pBuff[7],pBuff[8],num);

	BYTE cmd = pBuff[3];
	if(cmd >= 0xD0 && cmd < 0xDF)
	{
		switch(cmd)
		{
		case 0xD0:
			getMcuDataPtr()->sCtrl.bRefresh = true;
			if (getMcuDataPtr()->sCtrl.bRefresh) {
				getMcuDataPtr()->sCtrl.bRefresh = 0;
			}
			break;
		case ARM_CMD_SYS_BACKSIGHT :
			getMcuDataPtr()->sDeveice.bParking = pBuff[4];
			break;
		case ARM_CMD_SYS_VALIDWND :
			getMcuDataPtr()->sDeveice.sourceValidFlag = (WORD)(pBuff[4])*256 + pBuff[5];
			getMcuDataPtr()->sDeveice.sourceValidFlag |= BIT3; //car usb
			getMcuDataPtr()->sDeveice.sourceValidFlag |= BIT4; // car ipod
			break;
		case ARM_CMD_SYS_DEVCHANGE :
			getMcuDataPtr()->sDeveice.lastDeveiceChange = pBuff[4];
			break;
		case ARM_CMD_SYS_KEY : {
			int keycode = pBuff[4];
			if(keycode == C_KEY_VOL_INC      //vol+   
				|| keycode == C_KEY_VOL_DEC  //vol-
				|| keycode == C_KEY_MUTE     //mute
				|| keycode == C_KEY_FREQ_INC //freq+
				|| keycode == C_KEY_FREQ_DEC //freq-
				|| keycode == C_KEY_PLAY     //play or pause
				|| keycode == C_KEY_SEL      //setup
				|| keycode == C_KEY_ESC      //menu
				|| keycode == 0xCA      	 //long click menu 
				|| keycode == C_KEY_MODE     //mode or media
				|| keycode == C_KEY_RADIO    //radio
				|| keycode == C_KEY_BAND     //band
				|| keycode == C_KEY_GPS      //gps
				|| keycode == C_KEY_DIAL     //bt  or dial
				|| keycode == 0xCB           //prev
				|| keycode == 0xCC           //next
				|| keycode == C_KEY_REW      //long click prev, pew
				|| keycode == C_KEY_FF       //long click next, ff
				|| keycode == 0x2A       	 //long click up
				
				)
			{
				ALOGI("keycode[%d]", keycode);
				if(mMcuService != NULL)
				{
					mMcuService->notifyHardKey(keycode);
				}
			}
			else
			{
				ALOGI("else keycode[%d]", keycode);
			}
		} break;
		case ARM_CMD_SYS_REQ_EXIT: {
			set_system_acc_state(false);
		} break;
		case ARM_CMD_SYS_REQ_ON: {
			set_system_acc_state(true);
		} break;
		case ARM_CMD_SYS_INIT_OK : 
			//PostMessage(g_hWnd,UART_MCU_INIT_OK,pBuff[4],0);
			break; 
		/*case ARM_CMD_SOURCE_SETBIT:
			getMcuDataPtr()->sDeveice.SourceSetBit = (WORD)(pBuff[4])*256 + pBuff[5];//源设置开关参数
			break;
		case ARM_CMD_ICON_SETBIT:
			getMcuDataPtr()->sDeveice.IconSetBit = (WORD)(pBuff[4])*256 + pBuff[5];
			break;*/
		default :
			break;
		}
	}
	//mp3 dvd info
	else if(cmd >= 0xe0 && cmd <= 0xeF)
	{
		
	}
	//Radio Info
	else if(cmd >= 0x20 && cmd <= 0x2F)
	{
		switch(cmd)
		{
			case 0x20:
				break;
			case 0x21: {
				int freq = (WORD)(pBuff[4])*256 + (WORD)pBuff[5];
				set_radio_has_legal_freq(false);
				set_radio_freq(freq);
				ALOGI("0x21 :: freq = %d", freq);
			} break;
			case 0x22: {
			} break;
			case 0x23: {
				int loc = pBuff[4];
				set_radio_loc(loc);
				ALOGI("0x23 :: bLoc = %d", loc);
			} break;
			case 0x24: {
				int st = pBuff[4];
				set_radio_st(st);
				ALOGI("0x24 :: bSt = %d", st);
			} break;
			case 0x25: {
				int stind = pBuff[4];
				set_radio_stind(stind);
				ALOGI("0x25 :: bStInd = %d", stind);
			} break;
			case ARM_CMD_RADIO_PS :
				memset(getMcuDataPtr()->sRadio.PsName,0, sizeof(getMcuDataPtr()->sRadio.PsName));
				for(int i = 0;i < 8; i++)
				{
					if(pBuff[4+i] == 0)
					{
						break;
					}
					getMcuDataPtr()->sRadio.PsName[i] = pBuff[4+i];
				}
				ALOGI("[RDS]:Receive PS Info:%s\n",&pBuff[4]);
				break;
			case ARM_CMD_RADIO_AFMODE:
				getMcuDataPtr()->sRadio.bAF = (bool)pBuff[4];
				ALOGI("0x27 :: bAF = %d", getMcuDataPtr()->sRadio.bAF);		
				break;
			case ARM_CMD_RADIO_TPINFO :
				memset(getMcuDataPtr()->sRadio.tpInfo, 0, sizeof(getMcuDataPtr()->sRadio.tpInfo));
				for(int i = 0;i < 8; i++)
				{
					if(pBuff[4+i] == 0)
					{
						break;
					}
					getMcuDataPtr()->sRadio.tpInfo[i] = pBuff[4+i];
					ALOGI("[RDS]:Receive TP Info:%s\n",&pBuff[4]);
				}
				break;
			case ARM_CMD_RADIO_TAMODE :
				getMcuDataPtr()->sRadio.bTA = pBuff[4];
				ALOGI("[RDS]:Receive TA Flag:%d\n",pBuff[4]);
				break;
			case ARM_CMD_RADIO_EON :
				getMcuDataPtr()->sRadio.bEON= pBuff[4];
				ALOGI("[RDS]:Receive EON Flag:%d\n",pBuff[4]);
				break;
			case ARM_CMD_RADIO_TP :
				getMcuDataPtr()->sRadio.bPTY= pBuff[4];
				ALOGI("[RDS]:Receive TP Flag:%d\n",pBuff[4]);
				break;
			case ARM_CMD_RADIO_PTY :
				getMcuDataPtr()->sRadio.ptyType = pBuff[4]&0x3F;
				ALOGI("[RDS]:Receive PTY Type:%d\n",pBuff[4]&0x3F);
				break;
			case ARM_CMD_NEW_RADIO_INFO:
				if(pBuff[4] == ARM_DATA_RADIO_HAVE_SIG)
				{
					set_radio_has_legal_freq(true);
					int freq = pBuff[5]*256+pBuff[6];
					set_radio_legal_freq(freq);
					ALOGI("0x2D :: haslegalFreq = %d ",get_radio_has_legal_freq());
					ALOGI("0x2D :: legalFreq = %d ",freq);
				}
				else
				{
					set_radio_has_legal_freq(false);
				}
				break;
			case 0x2E: {
				int search = pBuff[4];
				set_radio_search(search);
				if(!search)
				{
					set_radio_has_legal_freq(false);
				}
				ALOGI("0x2E :: bSearch = %d", search);
			} break;
			case 0x2F : {
				int scan = pBuff[4];
				set_radio_scan(scan);
				ALOGI("0x2F :: bManu = %d", scan);
			} break;
		}
	}
	else if(cmd >= 0x30 && cmd <= 0x3F)
	{
		switch(cmd)
		{
			case 0x34 :
				getMcuDataPtr()->sDeveice.bCarRun = pBuff[4];
				break;
			case 0x35 :
				getMcuDataPtr()->sDeveice.bIllOn = pBuff[4];
				break;
		}
	}
	else if(cmd >= 0x40 && cmd <= 0x4F)
	{
		
	}
	//can info
	else if(cmd >= 0x50 && cmd <= 0x5F)
	{
		if(mMcuService != NULL)
		{
			mMcuService->notifyCanInfo(&pBuff[4], num-5);
		}
	}
	else if (cmd == ARM_CMD_TV_BAR_INFO)
	{
		
	}
	//0x82
	else if(cmd == ARM_CMD_UPDATE_SYSINFO)
	{
		parse_sysinfo(pBuff,num);
	}
	else if(cmd == 0x83)
	{
		getMcuDataPtr()->sDeveice.bPowerBeforMcuInit = pBuff[4];
		ALOGI("bPowerBeforMcuInit = %d", pBuff[4]);	
	}
	else if(cmd == 0x84)
	{
		//PostMessage(g_hWnd,UART_MCU_EXTKEY0_CHANGE,pBuff[4]*2560 + pBuff[5]*10,0);
	}
	else if(cmd == 0x85)
	{
		//PostMessage(g_hWnd,UART_MCU_EXTKEY1_CHANGE,pBuff[4]*2560 + pBuff[5]*10,0);
	}
	else if(cmd == 0x86)
	{
		//PostMessage(g_hWnd,UART_MCU_EXTKEY0_MAXRES,pBuff[4]*2560 + pBuff[5]*10,0);
	}
	else if(cmd == 0x87)
	{
		//PostMessage(g_hWnd,UART_MCU_EXTKEY1_MAXRES,pBuff[4]*2560 + pBuff[5]*10,0);
	}
	else if(cmd == 0x88)
	{
		memset(getMcuDataPtr()->sSettins.mcuVer, 0, sizeof(getMcuDataPtr()->sSettins.rtkVer));
		memcpy(getMcuDataPtr()->sSettins.mcuVer,&pBuff[4],9);
		ALOGI("mcuVer = %s", getMcuDataPtr()->sSettins.mcuVer);	
	}
	else if(ARM_CMD_SYSSETUP == cmd)
	{
		parse_setupinfo(pBuff,num);
	}
	else if(cmd == 0x8A)
	{

		getMcuDataPtr()->sSettins.freq30 = pBuff[4];
		getMcuDataPtr()->sSettins.freq60 = pBuff[5];
		getMcuDataPtr()->sSettins.freq125 = pBuff[6];
		getMcuDataPtr()->sSettins.freq250 = pBuff[7];
		getMcuDataPtr()->sSettins.freq500 = pBuff[8];
		getMcuDataPtr()->sSettins.freq1K= pBuff[9];
		getMcuDataPtr()->sSettins.freq2K= pBuff[10];
		getMcuDataPtr()->sSettins.freq4K= pBuff[11];
		getMcuDataPtr()->sSettins.freq8K= pBuff[12];
		getMcuDataPtr()->sSettins.freq16K= pBuff[13];
		ALOGI("0x8A = [%d]  [%d]  [%d]  [%d]  [%d]  [%d]  [%d] [%d]  [%d]  [%d]", getMcuDataPtr()->sSettins.freq30,
			getMcuDataPtr()->sSettins.freq60,getMcuDataPtr()->sSettins.freq125,getMcuDataPtr()->sSettins.freq250,getMcuDataPtr()->sSettins.freq500,
			getMcuDataPtr()->sSettins.freq1K,getMcuDataPtr()->sSettins.freq2K,getMcuDataPtr()->sSettins.freq4K,getMcuDataPtr()->sSettins.freq8K,
			getMcuDataPtr()->sSettins.freq16K); 
	}
	else if(cmd == 0x8b)
	{
		getMcuDataPtr()->sSettins.trubass = pBuff[4];
		getMcuDataPtr()->sSettins.focus = pBuff[5];
		getMcuDataPtr()->sSettins.defintion = pBuff[6];
		getMcuDataPtr()->sSettins.limiter = pBuff[7];
		getMcuDataPtr()->sSettins.trubassfreq = pBuff[8];
		getMcuDataPtr()->sSettins.space = pBuff[10];
		getMcuDataPtr()->sSettins.center = pBuff[11];
		ALOGI("0x8A = [%d]  [%d]  [%d]  [%d]  [%d]  [%d]  [%d] ", getMcuDataPtr()->sSettins.trubass,
			getMcuDataPtr()->sSettins.focus,getMcuDataPtr()->sSettins.defintion,getMcuDataPtr()->sSettins.limiter,getMcuDataPtr()->sSettins.trubassfreq,
			getMcuDataPtr()->sSettins.space,getMcuDataPtr()->sSettins.center); 
	}
	else if(cmd == 0x8c)
	{
		memset(getMcuDataPtr()->sSettins.rtkVer, 0, sizeof(getMcuDataPtr()->sSettins.rtkVer));
		memcpy(getMcuDataPtr()->sSettins.rtkVer,&pBuff[4],12);
		ALOGI("rtkVer = %s", getMcuDataPtr()->sSettins.rtkVer);
	}
	else if(cmd == 0xB5)
	{
	}
	else if (ARM_CMD_VMDVD_INFO == cmd)
	{

	}
	else if(ARM_CMD_USER_SAVE_DATA == cmd)
	{
		memcpy(&getMcuDataPtr()->sArmSaveData,&pBuff[4],8);
		ALOGI("[RDS ] enter RDS Tarffic Mode[%d]", (bool)pBuff[4]);
	}
	else if(ARM_CMD_SYS_RADIO_MODE == cmd)
	{
		getMcuDataPtr()->sRadio.bTraffic = (bool)pBuff[4];
		ALOGI("[RDS ] enter RDS Tarffic Mode[%d]", (bool)pBuff[4]);
	}
}


