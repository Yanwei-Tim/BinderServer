#ifndef _ARMCOM_H_
#define _ARMCOM_H_
 
// 此协议不允许轻易修改
/************MCU==>ARM START**************/
//ZH_011 add start
#define ARM_CMD_CHECK_VER			0x05		//在第@次上电的时候发送版本号给ARM,达到和ARM同步
//ZH_011 add end


/***********************************收音机信息***********************************/
#define ARM_CMD_RADIO_BAND				0x20		//Radio波段
#define ARM_CMD_RADIO_FREQ				0x21		//Radio主频率
#define ARM_CMD_RADIO_SUBFREQ			0x22		//Radio子频率表
#define ARM_CMD_RADIO_LOC				0x23		//Radio LOC标志
#define ARM_CMD_RADIO_STMODE			0x24		//Radio ST标志
#define ARM_DATA_RADIO_STMODE_ON			0x01		//有
#define ARM_DATA_RADIO_STMODE_OFF			0x00		//无
#define ARM_CMD_RADIO_ST				0x25		//Radio 双环标志
#define ARM_DATA_RADIO_ST_ON				0x01		//有
#define ARM_DATA_RADIO_ST_OFF				0x00		//无
#define ARM_CMD_RADIO_PS				0x26		//Radio RDS电台名称
#define ARM_CMD_RADIO_AFMODE			0x27		//Radio RDS电台AF标志
#define ARM_CMD_RADIO_TPINFO			0x28		//Radio RDS电台TP信息
#define ARM_CMD_RADIO_TAMODE			0x29		//Radio RDS电台TA标志
#define ARM_CMD_RADIO_EON				0x2A		//Radio RDS电台EON标志
#define ARM_CMD_RADIO_TP				0x2B		//Radio RDS电台TP标志
#define ARM_CMD_RADIO_PTY				0x2C		//Radio RDS电台PTY信息
#define ARM_CMD_NEW_RADIO_INFO			0x2D		//新收音机通知消息
#define ARM_DATA_RADIO_HAVE_SIG				0x01		//有台，后面附带频率
#define ARM_CMD_RADIO_SCAN				0x2E		//Radio扫描状态
#define ARM_CMD_RADIO_INTRO				0x2F		//Radio浏览状态
/***********************************收音机信息***********************************/

#define ARM_CMD_DVD_FF_REW_RATE			0x30		//DVD快进快退倍数
#define ARM_CMD_DVD_LOAD_SCHEDULE		0x31		//DVD 加载进度
#define ARM_CMD_DVD_TOUCH				0x32		//DVD是否支持触摸
#define ARM_DATA_DVD_TOUCH_ON			0x01		//不支持
#define ARM_DATA_DVD_TOUCH_OFF			0x00		//支持
/************以下部分暂时没使用或者无意义**************/
#define ARM_CMD_DVD_SIG					0x33		//DVD视频稳定标志
#define ARM_DATA_DVD_SIG_ON				0x01		//已经稳定
#define ARM_DATA_DVD_SIG_OFF			0x00		//切换中
/************以上部分暂时没使用或者无意义**************/
#define ARM_CMD_CARBREAK				0x34		//汽车运行标志
#define ARM_DATA_CARBREAK_ON				0x01		//行驶
#define ARM_DATA_CARBREAK_OFF				0x00		//停车
#define ARM_CMD_CARILL					0x35		//汽车大灯标志
#define ARM_DATA_CARILL_ON					0x01		//打开
#define ARM_DATA_CARILL_OFF				0x00		//关闭
/************以下部分暂时没使用或者无意义**************/
#define ARM_CMD_VIDEO_STD				0x36		//CVBS视频制式
#define ARM_CMD_VIDEO_STD_NTSC			0x00		//NTSC制式
#define ARM_CMD_VIDEO_STD_PAL				0x01		//PAL制式
/************以上部分暂时没使用或者无意义**************/
#define ARM_CMD_PLAY_MODE				0x37		//DVD的播放模式
/************以下部分暂时没使用**************/
#define ARM_CMD_VIDEO_PLAY_MOVIE		0x38
/************以上部分暂时没使用或者无意义**************/
#define ARM_CMD_MEDIA_TYPE				0x39		//DVD碟片类型
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
#define ARM_CMD_DVD_PLAY_TIME			0x3A		//DVD当前播放时间
#define ARM_CMD_CLEAR_DVD_STATE		0x3B		//清除DVD信息
#define ARM_CMD_DVD_TOUCH_INVLID		0x3C		//DVD触摸响应
#define ARM_CMD_DVD_PLAY_STATE		0x3D		//DVD播放状态
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
#define ARM_CMD_DVD_MP3_MENU			0x3E		//DVD媒体界面类型
#define ARM_CMD_DVD_FILE_ERR			0x3F		//DVD错误标志

#define ARM_CMD_CDC_PLAY_STATE			0x40		//CDC播放状态
#define ARM_CMD_CDC_PLAY_DISC			0x41		//CDC播放的碟片序号
#define ARM_CMD_CDC_PLAY_TRACK			0x42		//CDC 正播放的曲目序号
#define ARM_CMD_CDC_PLAY_MIN			0x43		//CDC 播放曲目的分钟
#define ARM_CMD_CDC_PLAY_SEC			0x44		//CDC 播放曲目的秒钟
#define ARM_CMD_CDC_PLAY_MODE			0x45		//CDC 的播放模式
#define ARM_CMD_CDC_TOTAL_TRACK		0x47		//CDC 正播放的总曲目数
#define ARM_CMD_DVD_LOAD_TOTAL_FILE	0x48    // 总曲目数,ARM使用
#define ARM_CMD_DVD_LOAD_CURRENT_FILE	0x49    // 当前曲目数,ARM使用
#define ARM_CMD_IPOD_CON_STATE			0x4A    // 当前ARM连接状态
#define ARM_CMD_IPOD_PLAYING_STATE		0x4B    // 当前ipod列表dvd界面状态

#define ARM_CMD_CAN_DATA				0x50		//MCU转发CAN数据的头码
#define ARM_CMD_HOOK_DVD_DATA			0x51

#define ARM_CMD_NEWRADAR_DATA			0x52


#define ARM_CMD_TV_BAR_INFO				0x60
#define ARM_CMD_TV_CHANNEL				0x61
#define ARM_CMD_TV_NP					0x62
#define ARM_CMD_TV_SCAN					0x63
#define ARM_CMD_TV_VIDEO_DISPLAY		0x64

// TPMS的协议还未定
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
/************以下部分暂时没使用或者无意义**************/
#define ARM_CMD_DISP_SYSINFO			0x81
/************以上部分暂时没使用或者无意义**************/


/*********************************系统信息*************************************/
#define ARM_CMD_UPDATE_SYSINFO			0x82
#define ARM_DATA_YEAR						0x01		//年
#define ARM_DATA_MONTH						0x02		//月
#define ARM_DATA_DAY						0x03		//日
#define ARM_DATA_HOUR						0x04		//时
#define ARM_DATA_MINUTE						0x05		//分
#define ARM_DATA_SECOND						0x06		//秒
#define ARM_DATA_TIME12H					0x07		//时间制式
#define ARM_DATA_VOL						0x08		//音量
#define ARM_DATA_BASS						0x09		//低音
#define ARM_DATA_TREB						0x0A		//高音
#define ARM_DATA_FADE						0x0B		//前后平衡
#define ARM_DATA_BAL						0x0C		//左右平衡
#define ARM_DATA_AUDIOMODE					0x0D		//EQ模式
#define ARM_DATA_MUTE						0x0E		//静音
#define ARM_DATA_BRIGHT						0x0F		//亮度
#define ARM_DATA_CONTRAST					0x10		//色度
#define ARM_DATA_COLOR						0x11		//对比度
#define ARM_DATA_VIDEOMODE					0x12		//显示模式
#define ARM_DATA_TUNERSYS					0x13
#define ARM_DATA_TVSYS						0x14
#define ARM_DATA_BEEP						0x15		//Beep声开关
#define ARM_DATA_MID						0x16		//中音
#define ARM_DATA_SYSFLAG					0x17		//系统设置
#define ARM_DATA_TRUBASS            		0x18
#define ARM_DATA_SRSFOCUS           		0x19
#define ARM_DATA_DEFINITION             	0x1A
#define ARM_DATA_LIMITER             		0x1B
#define ARM_DATA_TRUBASS_FREQ       		0x1C
#define ARM_DATA_BTVOL						0x1D		//蓝牙音量
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
#define ARM_DATA_GPSVOL						0x2D		//GPS混音比例
#define ARM_DATA_SYSFLAG2					0x2E		//系统设置
#define ARM_DATA_DEFVOL						0x2F		//ACC ON默认音量
#define ARM_DATA_ARMSAVE1					0x30		//保存数据
#define ARM_DATA_ARMSAVE2					0x31		//保存数据
#define ARM_DATA_ARMSAVE3					0x32		//保存数据
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
#define ARM_DATA_LOW_FO						0x5A	//低频中心频率
#define ARM_DATA_MID_FO						0x5B
#define ARM_DATA_HIGH_FO					0x5C
#define ARM_DATA_ADJ_BACKVOL                0x60	//倒车音量大小
#define ARM_DATA_USER_BRIGHT				0x73		//
#define ARM_DATA_USER_CONTRAST				0x74		//
#define ARM_DATA_USER_COLOR					0x75		//
#define ARM_DATA_USER_BASS					0x76		//
#define ARM_DATA_USER_TREB					0x77		//
#define ARM_DATA_USER_MID					0x78		//
#define ARM_DATA_LAMP_VAL					0x79		//背光
#define ARM_DATA_CAMARAMIX					0x80		//
#define ARM_DATA_CCDTYPE					0x81		//
#define ARM_DATA_PANELTYPE					0x82		//
#define ARM_DATA_RDS_PTYTYPE				0x83
#define ARM_DATA_RADIO_SENDKEY				0x84
#define ARM_DATA_NEW_RADIO					0x84
#define ARM_DATA_RADIO_BAND					0x85

/**********************************系统信息*************************************/


#define ARM_CMD_POWER_SW				0x83		//电源打开标志
#define ARM_DATA_POWER_OFF					0x00		//关
#define ARM_DATA_POWER_ON					0x01		//开
#define ARM_CMD_EXTKEY0_CHANGE			0x84		//学习弄方控Key0值
#define ARM_CMD_EXTKEY1_CHANGE			0x85		//学习弄方控Key1值
#define ARM_CMD_EXTKEY0_MAX				0x86		//学习弄方控Key0最大值
#define ARM_CMD_EXTKEY1_MAX				0x87		//学习弄方控Key1最大值
#define ARM_CMD_MCU_VER					0x88		//版本号



/*******************************工厂设置*********************************/
#define ARM_CMD_SYSSETUP				0x89		//工厂设置
#define ARM_DATA_RADIO_AREA					0x00		//收音区域
#define ARM_DATA_LANG_SEL					0x01		//语言
#define ARM_DATA_FM_STOP_VAL				0x02		//FM门限
#define ARM_DATA_AM_STOP_VAL				0x03		//AM门限
#define ARM_DATA_CAN_COMPANY				0x04		//CAN公司
#define ARM_DATA_CAN_LOGO					0x05		//CAN车品牌
#define ARM_DATA_CAN_TYPE					0x06		//CAN车型
#define ARM_DATA_DSP_SEL					0x07		//SRS车型
#define ARM_DATA_RESET_SYS					0x08		//恢复工厂设置
#define ARM_DATA_LED_TYPE					0X09		//led 颜色
#define ARM_DATA_LED_TIME					0X0A		//led 延时 
#define ARM_DATA_RDS_ONOFF					0x0B
#define ARM_DATA_BACK_BRIGHT				0x0C
#define ARM_DATA_BACK_CONST					0x0D
#define ARM_DATA_BACK_COLOR					0x0F
#define ARM_DATA_TIME_AREA					0x10
#define ARM_DATA_BT_MODULE					0x11
#define ARM_DATA_OTHER_APP_ACCOFF			0x12
#define ARM_DATA_REBOOTMODE		    		0x13 //系统是断b+还是accoff30秒起来
#define ARM_DATA_BACK_SET					0x14//倒车书画设定
#define ARM_DATA_DARAR_SW		    		0x14 //dadar switch
#define ARM_DATA_BACK_CAN_CTRL_SIDEVIEW		0x15//主机完全控制SideView(有CAN)
#define ARM_DATA_HAVE_SIDEVIEW_SIGN			0x16//提供倒车影像给SideView
/*******************************工厂设置*********************************/










#define ARM_CMD_EQ_INFO             			0x8A
#define ARM_CMD_SRS_INFO             		0x8B
#define ARM_CMD_USER_EQ_INFO             	0x8C
#define ARM_CMD_USER_SRS_INFO             	0x8D

/*******************/
//VRITUAL DISC START
#define ARM_CMD_VMDVD_INFO  		  	0x8E	//虚拟6碟
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
#define ARM_CMD_USER_SAVE_DATA			0x8F		//arm发送给mcu的记忆数据
//0x90--0x91
#define ARM_CMD_SYS_RADIO_MODE       	0x90
#define ARM_CMD_SYS_CLEAR_PTY       	0x91

#define ARM_CMD_REQ_BEEP       	0x92		//  请求ARM发BEEP
#define ARM_RECEIVE_UPDATA_FLAG    0xAD			//ARM升级请求
#define ARM_RECEIVE_RESUME_REQ    0xAE			//ARM升级请求

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


#define ARM_CMD_EXTKEY2_CHANGE		0xDE		//学习弄方控Key3值
#define ARM_CMD_EXTKEY2_MAX			0xE2		//学习弄方控Key3最大值

#define ARM_RECEIVE_GPSRESET_CTL		0xE3		//GPS 复位控制
	

#define ARM_CMD_DVD_TRACK				0xE8
/************MCU==>ARM END**************/



/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

/************ARM==>MCU START**************/
#define ARM_RECEIVE_INIT				0x80		//APP已经启动
#define ARM_RECEIVE_INIT_OK			0x81		//APP可以接收指令
#define ARM_RECEIVE_TOUCH_DOWN		0x83		//当前触摸坐标
/************以下部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_TOUCH_MOVE		0x84		//
#define ARM_RECEIVE_TOUCH_UP			0x85		//
/************以上部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_CARDEVICE_VALID		0x87		//原车设备有效字节
//Bit0:CarUsb,Bit1:CarIpod
#define ARM_RECEIVE_KEY					0x88		//按键值
#define ARM_RECEIVE_REQ_BEEP			0x89		//请求MCU发出Beep声
#define ARM_RECEIVE_UPDATE_SYSINFO	0x8B		//系统信息
#define ARM_RECEIVE_SOURCE				0x8D		//源
#define ARM_RECEIVE_AUDIO_CH			0x8E		//声音

#define ARM_RECEIVE_DVBT_PAGE 		0x8F	//数字电视页面
	#define DVBT_PAGE_ENTER	1
	#define DVBT_PAGE_EXIT	0

#define ARM_RECEIVE_SUB_BACK_AUDIO			0x90  // 减小后台声音

#define ARM_RECEIVE_GPS_TIP			0x91		//GPS播报状态
#define ARM_RECEIVE_DVD_POS			0x92		//ARM发送dvd跳动的位置
#define ARM_RECEIVE_STEER_STUDY		0x93		//学习方控开始
/************以下部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_ENTER_SLEEP		0x94		//
#define ARM_RECEIVE_EXIT_SLEEP		0x95		//
/************以上部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_BT_POWER			0x96		//BT电源控制
#define ARM_RECEIVE_TELTALKING_STATE	0x97		//蓝牙通话状态
#define ARM_RECEIVE_REQ_MUTE1S		0x99		//ARM请求MCU Mute 1 秒
#define ARM_RECEIVE_TFT_OFF			0x9A		//关背光
/************以下部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_GPS_RUN			0x9B		//
/************以上部分暂时没使用或者无意义**************/
#define ARM_RECEIVE_RESET_REQ			0x9C		//ARM请求复位
#define ARM_RECEIVE_REQ_VER			0x9D		//ARM请求MCU版本号
#define ARM_RECEIVE_ERR_RESET			0x9E		//心跳包数据
#define ARM_RECEIVE_MCU_VER			0x9F
#define ARM_RECEIVE_UPDATE_SYSSETUP	0xA0		//工厂设置
#define ARM_RECEIVE_IPOD_ITEM_NUM	0xA4		// IPOD item 选择 新增
#define ARM_RECEIVE_DVD_FILE			0xA5		//DVD当前选择文件序号
#define ARM_RECEIVE_DVD_FOLDER		0xA6		//DVD当前选择文件夹序号
#define ARM_RECEIVE_DVD_SEL_TYPE		0xA7		//DVD当前选择媒体类型
#define ARM_RECEIVE_GPS_TIME_REQ		0xA8		//ARM请求MCU发送时间
#define ARM_RECEIVE_GPS_INFO_REQ		0xA9		//ARM请求复位
#define ARM_RECEIVE_OPEN_BLACK_REQ	0xAA		//ARM请求MCU打开背光
#define ARM_RECEIVE_UPDATA_FLAG    0xAD			//ARM升级请求
#define ARM_RECEIVE_DTV_COMMAND 0xAB //ARM下发DTV的命令
#define ARM_RECEIVE_CLOSE_BLACK_REQ	0xAC 	//恢复出厂设置时，ARM请求MCU关闭背光

#define ARM_RECEIVE_DTV_RST    0xAE			//ARM请求升级DTV

#define ARM_RECEIVE_RADIO_FREQ		0xB1	//ARM发送收音频率
#define ARM_RECEIVE_BT_INCOME		0xB2		//蓝牙来电

#define ARM_RECEIVE_RADIO_SEL_CH2				0xbd
#define ARM_RECEIVE_RADIO_SEL_CH				0xb7	//选择子频
#define ARM_RECEIVE_RADIO_ADD_CH				0xb8	//保存当前频率到指定子频(指定频道)
#define ARM_RECEIVE_RADIO_DEL_CH				0xb9	//删除子频
#define ARM_RECEIVE_RADIO_DEL_ALLCH			0xbA	//删除所以子频

#define ARM_RECEIVE_IPOD_STATE			0xbb	//arm解IPOD状态


#define ARM_RECEIVE_CAN_DATA_ONCE	0xC0		//ARM将要发送的CAN数据发过来
#define ARM_RECEIVE_CAN_DATA_LOOP 	0xC1		//ARM将要循环发送的CAN数据发过来
#define ARM_RECEIVE_CAN_SAVE_ID		0xC7
#define ARM_RECEIVE_USER_SAVEDATA	0xC8
#define ARM_RECEIVE_UART_TRAN		0xC9


//define ARM REC TPMS
#define ARM_RECEIVE_TPMS_REQ			0xC2	//TPMS
#define ARM_RECEIVE_TPMS_SP_SET			0xC3
#define ARM_RECEIVE_TPMS_T_SET			0xC4
#define ARM_RECEIVE_TPMS_EXCHANG		0xC5
#define ARM_RECEIVE_VMDVD_INFO			0xC6	//虚拟6碟接收

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
/************以下  部分 是不同源的音量类型定义   **************/
#ifdef IndependentVolAdjust
#define ARM_RECEIVE_VOLUMETYPE_INFO 	0xFA//不同源的声音 arm 发给mcu
   #define VOLUMETYPE_INFO_RADIO			0x00
   #define VOLUMETYPE_INFO_DVD				0x01	
   #define VOLUMETYPE_INFO_AUX				0x02
   #define VOLUMETYPE_INFO_IPOD				0x03
   #define VOLUMETYPE_INFO_DVBT				0x04
//备注:其他的arm  出来音量 还是用系统音量0X8B, 0X08, DATA

#define ARM_UPDATE_VOLUMETYPE_INFO 	0xFB	// mcu 发给arm
#endif
/************以上部分暂时没使用或者无意义**************/

/************ARM==>MCU END**************/

#endif


