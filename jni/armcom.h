#ifndef _ARMCOM_H_
#define _ARMCOM_H_
 
// ��Э�鲻���������޸�
/************MCU==>ARM START**************/
//ZH_011 add start
#define ARM_CMD_CHECK_VER			0x05		//�ڵ�@���ϵ��ʱ���Ͱ汾�Ÿ�ARM,�ﵽ��ARMͬ��
//ZH_011 add end


/***********************************��������Ϣ***********************************/
#define ARM_CMD_RADIO_BAND				0x20		//Radio����
#define ARM_CMD_RADIO_FREQ				0x21		//Radio��Ƶ��
#define ARM_CMD_RADIO_SUBFREQ			0x22		//Radio��Ƶ�ʱ�
#define ARM_CMD_RADIO_LOC				0x23		//Radio LOC��־
#define ARM_CMD_RADIO_STMODE			0x24		//Radio ST��־
#define ARM_DATA_RADIO_STMODE_ON			0x01		//��
#define ARM_DATA_RADIO_STMODE_OFF			0x00		//��
#define ARM_CMD_RADIO_ST				0x25		//Radio ˫����־
#define ARM_DATA_RADIO_ST_ON				0x01		//��
#define ARM_DATA_RADIO_ST_OFF				0x00		//��
#define ARM_CMD_RADIO_PS				0x26		//Radio RDS��̨����
#define ARM_CMD_RADIO_AFMODE			0x27		//Radio RDS��̨AF��־
#define ARM_CMD_RADIO_TPINFO			0x28		//Radio RDS��̨TP��Ϣ
#define ARM_CMD_RADIO_TAMODE			0x29		//Radio RDS��̨TA��־
#define ARM_CMD_RADIO_EON				0x2A		//Radio RDS��̨EON��־
#define ARM_CMD_RADIO_TP				0x2B		//Radio RDS��̨TP��־
#define ARM_CMD_RADIO_PTY				0x2C		//Radio RDS��̨PTY��Ϣ
#define ARM_CMD_NEW_RADIO_INFO			0x2D		//��������֪ͨ��Ϣ
#define ARM_DATA_RADIO_HAVE_SIG				0x01		//��̨�����渽��Ƶ��
#define ARM_CMD_RADIO_SCAN				0x2E		//Radioɨ��״̬
#define ARM_CMD_RADIO_INTRO				0x2F		//Radio���״̬
/***********************************��������Ϣ***********************************/

#define ARM_CMD_DVD_FF_REW_RATE			0x30		//DVD������˱���
#define ARM_CMD_DVD_LOAD_SCHEDULE		0x31		//DVD ���ؽ���
#define ARM_CMD_DVD_TOUCH				0x32		//DVD�Ƿ�֧�ִ���
#define ARM_DATA_DVD_TOUCH_ON			0x01		//��֧��
#define ARM_DATA_DVD_TOUCH_OFF			0x00		//֧��
/************���²�����ʱûʹ�û���������**************/
#define ARM_CMD_DVD_SIG					0x33		//DVD��Ƶ�ȶ���־
#define ARM_DATA_DVD_SIG_ON				0x01		//�Ѿ��ȶ�
#define ARM_DATA_DVD_SIG_OFF			0x00		//�л���
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_CMD_CARBREAK				0x34		//�������б�־
#define ARM_DATA_CARBREAK_ON				0x01		//��ʻ
#define ARM_DATA_CARBREAK_OFF				0x00		//ͣ��
#define ARM_CMD_CARILL					0x35		//������Ʊ�־
#define ARM_DATA_CARILL_ON					0x01		//��
#define ARM_DATA_CARILL_OFF				0x00		//�ر�
/************���²�����ʱûʹ�û���������**************/
#define ARM_CMD_VIDEO_STD				0x36		//CVBS��Ƶ��ʽ
#define ARM_CMD_VIDEO_STD_NTSC			0x00		//NTSC��ʽ
#define ARM_CMD_VIDEO_STD_PAL				0x01		//PAL��ʽ
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_CMD_PLAY_MODE				0x37		//DVD�Ĳ���ģʽ
/************���²�����ʱûʹ��**************/
#define ARM_CMD_VIDEO_PLAY_MOVIE		0x38
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_CMD_MEDIA_TYPE				0x39		//DVD��Ƭ����
#define ARM_DATA_MEDIA_TYPE_LOADING		0x00
#define ARM_DATA_MEDIA_TYPE_ERR			0x01
#define ARM_DATE_MEDIA_TYPE_CDDA			0x02
#define ARM_DATA_MEDIA_TYPE_HDCD			0x03
#define ARM_DATA_MEDIA_TYPE_VCD			0x04
#define ARM_DATA_MEDIA_TYPE_SVCD			0x05
#define ARM_DATA_MEDIA_TYPE_DVD			0x06
#define ARM_DATA_MEDIA_TYPE_DVD_AUDIO	0x07
#define ARM_DATE_MEDIA_TYPE_MP3			0x08
#define ARM_DATA_MEDIA_TYPE_WMA			0x09
#define ARM_DATA_MEDIA_TYPE_JPEG			0x0A
#define ARM_DATA_MEDIA_TYPE_MP4			0x0B
#define ARM_DATA_MEDIA_TYPE_MIX			0x0C
#define ARM_DATA_MEDIA_TYPE_CD_ROM		0x0D
#define ARM_DATA_MEDIA_TYPE_UNKNOW		0x0E
#define ARM_CMD_DVD_PLAY_TIME			0x3A		//DVD��ǰ����ʱ��
#define ARM_CMD_CLEAR_DVD_STATE		0x3B		//���DVD��Ϣ
#define ARM_CMD_DVD_TOUCH_INVLID		0x3C		//DVD������Ӧ
#define ARM_CMD_DVD_PLAY_STATE		0x3D		//DVD����״̬
#define ARM_DATA_DVD_STATE_LOADING		0x00
#define ARM_DATA_DVD_STATE_PLAY			0x01
#define ARM_DATA_DVD_STATE_PAUSE			0x02
#define ARM_DATA_DVD_STATE_FF				0x03
#define ARM_DATA_DVD_STATE_REW			0x04
#define ARM_DATA_DVD_STATE_STOP			0x05
#define ARM_DATA_DVD_STATE_REAL_STOP		0x06
#define ARM_DATA_DVD_STATE_ROOT			0x07
#define ARM_DATA_DVD_STATE_TITLE			0x08
#define ARM_DATA_DVD_STATE_SETUP			0x09
#define ARM_DATA_DVD_STATE_UPGRADE		0x0A
#define ARM_DATA_DVD_STATE_EJECT		0x0B
#define ARM_DATA_DVD_STATE_PGM_SET		0x0C
#define ARM_DATA_DVD_STATE_PGM_PLAY		0x0D
#define ARM_DATA_DVD_STATE_PGM_OFF		0x0E
#define ARM_DATA_DVD_STATE_ERR			0x0F
#define ARM_DATA_DVD_STATE_USBLOADING	0x10
#define ARM_DATA_DVD_STATE_NO_SUPPORT	0x11
#define ARM_DATA_DVD_STATE_SD_LOADING	0x12
#define ARM_CMD_DVD_MP3_MENU			0x3E		//DVDý���������
#define ARM_CMD_DVD_FILE_ERR			0x3F		//DVD�����־

#define ARM_CMD_CDC_PLAY_STATE			0x40		//CDC����״̬
#define ARM_CMD_CDC_PLAY_DISC			0x41		//CDC���ŵĵ�Ƭ���
#define ARM_CMD_CDC_PLAY_TRACK			0x42		//CDC �����ŵ���Ŀ���
#define ARM_CMD_CDC_PLAY_MIN			0x43		//CDC ������Ŀ�ķ���
#define ARM_CMD_CDC_PLAY_SEC			0x44		//CDC ������Ŀ������
#define ARM_CMD_CDC_PLAY_MODE			0x45		//CDC �Ĳ���ģʽ
#define ARM_CMD_CDC_TOTAL_TRACK		0x47		//CDC �����ŵ�����Ŀ��
#define ARM_CMD_DVD_LOAD_TOTAL_FILE	0x48    // ����Ŀ��,ARMʹ��
#define ARM_CMD_DVD_LOAD_CURRENT_FILE	0x49    // ��ǰ��Ŀ��,ARMʹ��
#define ARM_CMD_IPOD_CON_STATE			0x4A    // ��ǰARM����״̬
#define ARM_CMD_IPOD_PLAYING_STATE		0x4B    // ��ǰipod�б�dvd����״̬

#define ARM_CMD_CAN_DATA				0x50		//MCUת��CAN���ݵ�ͷ��
#define ARM_CMD_HOOK_DVD_DATA			0x51

#define ARM_CMD_NEWRADAR_DATA			0x52


#define ARM_CMD_TV_BAR_INFO				0x60
#define ARM_CMD_TV_CHANNEL				0x61
#define ARM_CMD_TV_NP					0x62
#define ARM_CMD_TV_SCAN					0x63
#define ARM_CMD_TV_VIDEO_DISPLAY		0x64

// TPMS��Э�黹δ��
#define ARM_CMD_360C           			0x64
#define ARM_DATA_360C_ON       			0x01
#define ARM_DATA_360C_OFF          		0x00


//TPMS ARM CMD define
#define ARM_CMD_TPMS_TWARN			0x65	//TPMS
#define ARM_CMD_TPMS_SP				0x66
#define ARM_CMD_TPMS_INFO				0x67
#define ARM_CMD_TPMS_STATE			0x68

#define ARM_CMD_RADAR_DATA			0x6A

#ifdef ENABLE_ADJ_GEQ
//MCU<<--->>ARM		
#define ARM_RECEIVE_PEQ_COEFFIC		0X70
#define ARM_RECEIVE_GEQ_COEFFIC		0X71
#define ARM_RECEIVE_CH_DELAY		0X72
#endif

#define ARM_CMD_SYS_DISP				0x80
#define ARM_DATA_SYS_DISP_NOP				0x00
#define ARM_DATA_SYS_DISP_AUTO				0x01
#define ARM_DATA_SYS_DISP_MANU				0x02
#define ARM_DATA_SYS_DISP_STD				0x03
/************���²�����ʱûʹ�û���������**************/
#define ARM_CMD_DISP_SYSINFO			0x81
/************���ϲ�����ʱûʹ�û���������**************/


/*********************************ϵͳ��Ϣ*************************************/
#define ARM_CMD_UPDATE_SYSINFO			0x82
#define ARM_DATA_YEAR						0x01		//��
#define ARM_DATA_MONTH						0x02		//��
#define ARM_DATA_DAY						0x03		//��
#define ARM_DATA_HOUR						0x04		//ʱ
#define ARM_DATA_MINUTE						0x05		//��
#define ARM_DATA_SECOND						0x06		//��
#define ARM_DATA_TIME12H					0x07		//ʱ����ʽ
#define ARM_DATA_VOL						0x08		//����
#define ARM_DATA_BASS						0x09		//����
#define ARM_DATA_TREB						0x0A		//����
#define ARM_DATA_FADE						0x0B		//ǰ��ƽ��
#define ARM_DATA_BAL						0x0C		//����ƽ��
#define ARM_DATA_AUDIOMODE					0x0D		//EQģʽ
#define ARM_DATA_MUTE						0x0E		//����
#define ARM_DATA_BRIGHT						0x0F		//����
#define ARM_DATA_CONTRAST					0x10		//ɫ��
#define ARM_DATA_COLOR						0x11		//�Աȶ�
#define ARM_DATA_VIDEOMODE					0x12		//��ʾģʽ
#define ARM_DATA_TUNERSYS					0x13
#define ARM_DATA_TVSYS						0x14
#define ARM_DATA_BEEP						0x15		//Beep������
#define ARM_DATA_MID						0x16		//����
#define ARM_DATA_SYSFLAG					0x17		//ϵͳ����
#define ARM_DATA_TRUBASS            		0x18
#define ARM_DATA_SRSFOCUS           		0x19
#define ARM_DATA_DEFINITION             	0x1A
#define ARM_DATA_LIMITER             		0x1B
#define ARM_DATA_TRUBASS_FREQ       		0x1C
#define ARM_DATA_BTVOL						0x1D		//��������
#define ARM_DATA_TIME_AREA					0x1E
#define ARM_DATA_FREQ30						0x20
#define ARM_DATA_FREQ60						0x21
#define ARM_DATA_FREQ125					0x22
#define ARM_DATA_FREQ250					0x23
#define ARM_DATA_FREQ500					0x24
#define ARM_DATA_FREQ1K						0x25
#define ARM_DATA_FREQ2K						0x26
#define ARM_DATA_FREQ4K						0x27
#define ARM_DATA_FREQ8K						0x28
#define ARM_DATA_FREQ16K					0x29
#define ARM_DATA_DSP1						0x2A
#define ARM_DATA_DSP2						0x2B
#define ARM_DATA_DSP3						0x2C
#define ARM_DATA_GPSVOL						0x2D		//GPS��������
#define ARM_DATA_SYSFLAG2					0x2E		//ϵͳ����
#define ARM_DATA_DEFVOL						0x2F		//ACC ONĬ������
#define ARM_DATA_ARMSAVE1					0x30		//��������
#define ARM_DATA_ARMSAVE2					0x31		//��������
#define ARM_DATA_ARMSAVE3					0x32		//��������
#define ARM_DATA_CAR_LOGO					0x3b		//
#define ARM_DATA_CAR_TYPE					0x3c		//
#define ARM_DATA_BRIGHT_1					0x3D		//
#define ARM_DATA_CONTRAST_1					0x3E		//
#define ARM_DATA_COLOR_1					0x3F		//
#define ARM_DATA_TVDVBT						0x40
#define ARM_DATA_TV_SIGNAL					0x41
#define ARM_DATA_LOUDNESS					0x42
#define ARM_DATA_SUBWOOF					0x51		//
#define ARM_DATA_CENTER						0x52
#define ARM_DATA_SPACE						0x53
#define ARM_DATA_SRS_INPUT					0x54
#define ARM_DATA_SRS_OUTPUT					0x55
#define ARM_DATA_SRS_SW						0x56
#define ARM_DATA_LOUD						0x57
#define ARM_DATA_DSP_RESET					0x58
#define ARM_DATA_DSP_SAVE					0x59
#define ARM_DATA_LOW_FO						0x5A	//��Ƶ����Ƶ��
#define ARM_DATA_MID_FO						0x5B
#define ARM_DATA_HIGH_FO					0x5C
#define ARM_DATA_ADJ_BACKVOL                0x60	//����������С
#define ARM_DATA_USER_BRIGHT				0x73		//
#define ARM_DATA_USER_CONTRAST				0x74		//
#define ARM_DATA_USER_COLOR					0x75		//
#define ARM_DATA_USER_BASS					0x76		//
#define ARM_DATA_USER_TREB					0x77		//
#define ARM_DATA_USER_MID					0x78		//
#define ARM_DATA_LAMP_VAL					0x79		//����
#define ARM_DATA_CAMARAMIX					0x80		//
#define ARM_DATA_CCDTYPE					0x81		//
#define ARM_DATA_PANELTYPE					0x82		//
#define ARM_DATA_RDS_PTYTYPE				0x83
#define ARM_DATA_RADIO_SENDKEY				0x84
#define ARM_DATA_NEW_RADIO					0x84
#define ARM_DATA_RADIO_BAND					0x85

/**********************************ϵͳ��Ϣ*************************************/


#define ARM_CMD_POWER_SW				0x83		//��Դ�򿪱�־
#define ARM_DATA_POWER_OFF					0x00		//��
#define ARM_DATA_POWER_ON					0x01		//��
#define ARM_CMD_EXTKEY0_CHANGE			0x84		//ѧϰŪ����Key0ֵ
#define ARM_CMD_EXTKEY1_CHANGE			0x85		//ѧϰŪ����Key1ֵ
#define ARM_CMD_EXTKEY0_MAX				0x86		//ѧϰŪ����Key0���ֵ
#define ARM_CMD_EXTKEY1_MAX				0x87		//ѧϰŪ����Key1���ֵ
#define ARM_CMD_MCU_VER					0x88		//�汾��



/*******************************��������*********************************/
#define ARM_CMD_SYSSETUP				0x89		//��������
#define ARM_DATA_RADIO_AREA					0x00		//��������
#define ARM_DATA_LANG_SEL					0x01		//����
#define ARM_DATA_FM_STOP_VAL				0x02		//FM����
#define ARM_DATA_AM_STOP_VAL				0x03		//AM����
#define ARM_DATA_CAN_COMPANY				0x04		//CAN��˾
#define ARM_DATA_CAN_LOGO					0x05		//CAN��Ʒ��
#define ARM_DATA_CAN_TYPE					0x06		//CAN����
#define ARM_DATA_DSP_SEL					0x07		//SRS����
#define ARM_DATA_RESET_SYS					0x08		//�ָ���������
#define ARM_DATA_LED_TYPE					0X09		//led ��ɫ
#define ARM_DATA_LED_TIME					0X0A		//led ��ʱ 
#define ARM_DATA_RDS_ONOFF					0x0B
#define ARM_DATA_BACK_BRIGHT				0x0C
#define ARM_DATA_BACK_CONST					0x0D
#define ARM_DATA_BACK_COLOR					0x0F
#define ARM_DATA_TIME_AREA					0x10
#define ARM_DATA_BT_MODULE					0x11
#define ARM_DATA_OTHER_APP_ACCOFF			0x12
#define ARM_DATA_REBOOTMODE		    		0x13 //ϵͳ�Ƕ�b+����accoff30������
#define ARM_DATA_BACK_SET					0x14//�����黭�趨
#define ARM_DATA_DARAR_SW		    		0x14 //dadar switch
#define ARM_DATA_BACK_CAN_CTRL_SIDEVIEW		0x15//������ȫ����SideView(��CAN)
#define ARM_DATA_HAVE_SIDEVIEW_SIGN			0x16//�ṩ����Ӱ���SideView
/*******************************��������*********************************/










#define ARM_CMD_EQ_INFO             			0x8A
#define ARM_CMD_SRS_INFO             		0x8B
#define ARM_CMD_USER_EQ_INFO             	0x8C
#define ARM_CMD_USER_SRS_INFO             	0x8D

/*******************/
//VRITUAL DISC START
#define ARM_CMD_VMDVD_INFO  		  	0x8E	//����6��
#define ARM_CMD_VDVD_DISC_NUM 			0x01
#define ARM_CMD_VDVD_CUR_DISC 			0x02
#define ARM_CMD_VDVD_DISC_STATE 		0x03
#define ARM_CMD_VDVD_RECORD_STATE 		0x04
#define ARM_CMD_VDVD_PLAY_STATE 		0x05
#define ARM_CMD_VDVD_PLAY_TRACK 		0x06
#define ARM_CMD_VDVD_RECORD_PET 		0x07
#define ARM_CMD_VDVD_FORMAT_INFO 		0x08
#define ARM_CMD_VDVD_DISC_INFO 			0x09
#define ARM_CMD_VDVD_PT_TRACK			0x0a
#define ARM_CMD_VDVD_RT_TRACK			0x0b
#define ARM_CMD_VDVD_TOTAL_TIME			0x0c
#define ARM_CMD_VDVD_CURPLAY_TRACK		0x0d
#define ARM_CMD_VDVD_RECODE_INFO		0x0e
//VRITUAL DISC END
/*******************/
#define ARM_CMD_USER_SAVE_DATA			0x8F		//arm���͸�mcu�ļ�������
//0x90--0x91
#define ARM_CMD_SYS_RADIO_MODE       	0x90
#define ARM_CMD_SYS_CLEAR_PTY       	0x91

#define ARM_CMD_REQ_BEEP       	0x92		//  ����ARM��BEEP
#define ARM_RECEIVE_UPDATA_FLAG    0xAD			//ARM��������
#define ARM_RECEIVE_RESUME_REQ    0xAE			//ARM��������

#define ARM_CMD_SYS_FINISH				0xD0
#define ARM_CMD_SYS_BACKSIGHT			0xD2
#define ARM_CMD_SYS_VALIDWND			0xD3
#define ARM_CMD_SYS_DEVCHANGE			0xD4
#define ARM_CMD_SYS_KEY					0xD5
#define ARM_CMD_SYS_REQ_EXIT			0xD7
#define ARM_CMD_SYS_REQ_ON				0xD8
#define ARM_CMD_SYS_INIT_OK				0xD9
#define ARM_CMD_SYS_REQ_SLEEP			0xDA
#define ARM_CMD_SYS_REQ_REM      	 	0xDb
#define ARM_CMD_SYS_REQ_ACK       		0xDc
#define ARM_CMD_SYS_FIRST_POWER_ON       		0xDD


#define ARM_CMD_EXTKEY2_CHANGE		0xDE		//ѧϰŪ����Key3ֵ
#define ARM_CMD_EXTKEY2_MAX			0xE2		//ѧϰŪ����Key3���ֵ

#define ARM_RECEIVE_GPSRESET_CTL		0xE3		//GPS ��λ����
	

#define ARM_CMD_DVD_TRACK				0xE8
/************MCU==>ARM END**************/



/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

/************ARM==>MCU START**************/
#define ARM_RECEIVE_INIT				0x80		//APP�Ѿ�����
#define ARM_RECEIVE_INIT_OK			0x81		//APP���Խ���ָ��
#define ARM_RECEIVE_TOUCH_DOWN		0x83		//��ǰ��������
/************���²�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_TOUCH_MOVE		0x84		//
#define ARM_RECEIVE_TOUCH_UP			0x85		//
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_CARDEVICE_VALID		0x87		//ԭ���豸��Ч�ֽ�
//Bit0:CarUsb,Bit1:CarIpod
#define ARM_RECEIVE_KEY					0x88		//����ֵ
#define ARM_RECEIVE_REQ_BEEP			0x89		//����MCU����Beep��
#define ARM_RECEIVE_UPDATE_SYSINFO	0x8B		//ϵͳ��Ϣ
#define ARM_RECEIVE_SOURCE				0x8D		//Դ
#define ARM_RECEIVE_AUDIO_CH			0x8E		//����

#define ARM_RECEIVE_DVBT_PAGE 		0x8F	//���ֵ���ҳ��
	#define DVBT_PAGE_ENTER	1
	#define DVBT_PAGE_EXIT	0

#define ARM_RECEIVE_SUB_BACK_AUDIO			0x90  // ��С��̨����

#define ARM_RECEIVE_GPS_TIP			0x91		//GPS����״̬
#define ARM_RECEIVE_DVD_POS			0x92		//ARM����dvd������λ��
#define ARM_RECEIVE_STEER_STUDY		0x93		//ѧϰ���ؿ�ʼ
/************���²�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_ENTER_SLEEP		0x94		//
#define ARM_RECEIVE_EXIT_SLEEP		0x95		//
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_BT_POWER			0x96		//BT��Դ����
#define ARM_RECEIVE_TELTALKING_STATE	0x97		//����ͨ��״̬
#define ARM_RECEIVE_REQ_MUTE1S		0x99		//ARM����MCU Mute 1 ��
#define ARM_RECEIVE_TFT_OFF			0x9A		//�ر���
/************���²�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_GPS_RUN			0x9B		//
/************���ϲ�����ʱûʹ�û���������**************/
#define ARM_RECEIVE_RESET_REQ			0x9C		//ARM����λ
#define ARM_RECEIVE_REQ_VER			0x9D		//ARM����MCU�汾��
#define ARM_RECEIVE_ERR_RESET			0x9E		//����������
#define ARM_RECEIVE_MCU_VER			0x9F
#define ARM_RECEIVE_UPDATE_SYSSETUP	0xA0		//��������
#define ARM_RECEIVE_IPOD_ITEM_NUM	0xA4		// IPOD item ѡ�� ����
#define ARM_RECEIVE_DVD_FILE			0xA5		//DVD��ǰѡ���ļ����
#define ARM_RECEIVE_DVD_FOLDER		0xA6		//DVD��ǰѡ���ļ������
#define ARM_RECEIVE_DVD_SEL_TYPE		0xA7		//DVD��ǰѡ��ý������
#define ARM_RECEIVE_GPS_TIME_REQ		0xA8		//ARM����MCU����ʱ��
#define ARM_RECEIVE_GPS_INFO_REQ		0xA9		//ARM����λ
#define ARM_RECEIVE_OPEN_BLACK_REQ	0xAA		//ARM����MCU�򿪱���
#define ARM_RECEIVE_UPDATA_FLAG    0xAD			//ARM��������
#define ARM_RECEIVE_DTV_COMMAND 0xAB //ARM�·�DTV������
#define ARM_RECEIVE_CLOSE_BLACK_REQ	0xAC 	//�ָ���������ʱ��ARM����MCU�رձ���

#define ARM_RECEIVE_DTV_RST    0xAE			//ARM��������DTV

#define ARM_RECEIVE_RADIO_FREQ		0xB1	//ARM��������Ƶ��
#define ARM_RECEIVE_BT_INCOME		0xB2		//��������

#define ARM_RECEIVE_RADIO_SEL_CH2				0xbd
#define ARM_RECEIVE_RADIO_SEL_CH				0xb7	//ѡ����Ƶ
#define ARM_RECEIVE_RADIO_ADD_CH				0xb8	//���浱ǰƵ�ʵ�ָ����Ƶ(ָ��Ƶ��)
#define ARM_RECEIVE_RADIO_DEL_CH				0xb9	//ɾ����Ƶ
#define ARM_RECEIVE_RADIO_DEL_ALLCH			0xbA	//ɾ��������Ƶ

#define ARM_RECEIVE_IPOD_STATE			0xbb	//arm��IPOD״̬


#define ARM_RECEIVE_CAN_DATA_ONCE	0xC0		//ARM��Ҫ���͵�CAN���ݷ�����
#define ARM_RECEIVE_CAN_DATA_LOOP 	0xC1		//ARM��Ҫѭ�����͵�CAN���ݷ�����
#define ARM_RECEIVE_CAN_SAVE_ID		0xC7
#define ARM_RECEIVE_USER_SAVEDATA	0xC8
#define ARM_RECEIVE_UART_TRAN		0xC9


//define ARM REC TPMS
#define ARM_RECEIVE_TPMS_REQ			0xC2	//TPMS
#define ARM_RECEIVE_TPMS_SP_SET			0xC3
#define ARM_RECEIVE_TPMS_T_SET			0xC4
#define ARM_RECEIVE_TPMS_EXCHANG		0xC5
#define ARM_RECEIVE_VMDVD_INFO			0xC6	//����6������

#define ARM_RECEIVE_ACK_INFO 			0xDC

#define ARM_RECEIVE_CONNECT_CMD			0xDF



#define ARM_RECEIVE_3G_POWER			0xE0
#define ARM_RECEIVE_HOOK_DVD_DATA_ONCE	0xE1



#ifdef ADJEQ_INFO
#define ARM_CMD_BASSINFO 			0xF2 
	#define ARM_DATA_BASSINFO_QFactor		0x00
	#define ARM_DATA_BASSINFO_Freq			0x01
#define ARM_RECEIVE_BASSINFO 		0xF3

#define ARM_CMD_MIDINFO 			0xF4
	#define ARM_DATA_MIDINFO_QFactor		0x00
	#define ARM_DATA_MIDINFO_Freq			0x01
#define ARM_RECEIVE_MIDINFO 		0xF5

#define ARM_CMD_TREBINFO 			0xF6
	#define ARM_DATA_TREBMIDINFO_QFactor	0x00
	#define ARM_DATA_TREBMIDINFO_Freq		0x01
#define ARM_RECEIVE_TREBINFO 		0xF7

#endif
/************����  ���� �ǲ�ͬԴ���������Ͷ���   **************/
#ifdef IndependentVolAdjust
#define ARM_RECEIVE_VOLUMETYPE_INFO 	0xFA//��ͬԴ������ arm ����mcu
   #define VOLUMETYPE_INFO_RADIO			0x00
   #define VOLUMETYPE_INFO_DVD				0x01	
   #define VOLUMETYPE_INFO_AUX				0x02
   #define VOLUMETYPE_INFO_IPOD				0x03
   #define VOLUMETYPE_INFO_DVBT				0x04
//��ע:������arm  �������� ������ϵͳ����0X8B, 0X08, DATA

#define ARM_UPDATE_VOLUMETYPE_INFO 	0xFB	// mcu ����arm
#endif
/************���ϲ�����ʱûʹ�û���������**************/

/************ARM==>MCU END**************/

#endif


