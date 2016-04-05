#ifndef _MCU_DATA_H_
#define _MCU_DATA_H_
 

typedef struct
{
	u_c* ptr;
	//parse_data parse_single_cmd;
	int ptr_length;
	int consumed_index;
} parse_state;


#define MCUDATA_EXT extern

#define BIT0             (0x01<<0)
#define BIT1             (0x01<<1)
#define BIT2             (0x01<<2)
#define BIT3             (0x01<<3)
#define BIT4             (0x01<<4)
#define BIT5             (0x01<<5)
#define BIT6             (0x01<<6)
#define BIT7             (0x01<<7)
#define BIT8             (0x01<<8)
#define BIT9             (0x01<<9)
#define BIT10            (0x01<<10)
#define BIT11            (0x01<<11)
#define BIT12            (0x01<<12)
#define BIT13            (0x01<<13)
#define BIT14            (0x01<<14)
#define BIT15            (0x01<<15)
#define BIT16            (0x01<<16)
#define BIT17            (0x01<<17)
#define BIT18            (0x01<<18)
#define BIT19            (0x01<<19)
#define BIT20            (0x01<<20)
#define BIT21            (0x01<<21)
#define BIT22            (0x01<<22)
#define BIT23            (0x01<<23)
#define BIT24            (0x01<<24)
#define BIT25            (0x01<<25)
#define BIT26            (0x01<<26)
#define BIT27            (0x01<<27)
#define BIT28            (0x01<<28)
#define BIT29            (0x01<<29)
#define BIT30            (0x01<<30)
#define BIT31            (0x01<<31)

#define MAX_MAIN_KEY_NUM      	30
#define MAX_MP3_INFO_NUM      	30
#define MAX_IPOD_INFO_NUM      	30
#define MAX_MP3_NAME_NUM      	1000
#define MAX_PLAYLIST_NUM      	10

#define MAX_PACKAGE_NUM			100
#define MAX_PATH				260


typedef struct  
{
	bool bRefresh;
	bool bCtrlRefresh;
	bool bSysRefresh;
	bool bVideoRefresh;
	bool bRadioRefresh;
	bool bBtRefresh;
	bool bCdcRefresh;
	bool bCanInfoRefresh;
	bool bHaveKey;
	bool bDeveiceChange;
}S_MCU_DATA_CTRL;


typedef struct  
{
	int sourceValidFlag;
	int SourceSetBit;
	int IconSetBit;
	int lastDeveiceChange;
	int key;
	bool bMcuReqEnterAcc;
	bool bMcuDateInitOk;

	bool bCarRun;
	bool bIllOn;
	bool bParking;

	bool bPowerBeforMcuInit;
	int extKey0Value;
	int extKey1Value;
	int extKey0Max;
	int extKey1Max;
	BYTE mcuVer[8];
	int RdsSel;//0:rds off.1:rds On
	int display_x;
	int display_y;
}S_MCU_DATA_DEVEICE;

typedef struct  
{
	int band;
	int freq;
	int currentCh;
	int subFreq[18];
	bool bLoc;
	bool bSt;
	bool bStInd;
	int radioArea;
	bool bSearch;
	bool bManu;
	bool hasLegalFreq;
	int legalFreq; 

	//RDS
	WORD PsName[9];
	WORD tpInfo[9];
	bool bAF;
	bool bPTY;
	bool bTA;
	bool bEON;
	bool bTraffic;
	int ptyType;
	bool bAps;
	
}S_MCU_DATA_RADIO;


typedef struct  
{
	int loadPos;
	bool bEnableTouch;
	bool bVideoLock;
	int videoSystem;
	bool bMoveVideo;
	int bTouchNotHit;
	int dvdPlayState;
	int dvdPlayMode;
	int mediaType;
	int ffrewState;
	bool bMp3Wnd;	// 1��ʾ�б�����mp3���Ž��棬2��ʾͼƬ����Ƶ���Ž���
	bool bFileErrFlag;
	bool bInvalidStateFlag;
	bool bHaveSig;
	int videoFormat;
}S_MCU_DATA_VIDEO;


typedef struct  
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	bool b12H;
	int vol;
	int bass;
	int mid;
	int treb;
	int fade;
	int bal;
	int audioMode;
	bool bMute;
	int bright;
	int contrast;
	int color;
	int videoMode;
	int tunerSys;
	int tvSys;
	bool bBeep;
	
	int sysFlag;
	int subwoof;
	int backBright;
	
	int srsFlag;
	int srsFocus;
	int srsTB;
	int srsSur;
	int srsAGC;

	int btVol;

	int freq30;
	int freq60;
	int freq125;
	int freq250;
	int freq500;
	int freq1K;
	int freq2K;
	int freq4K;
	int freq8K;
	int freq16K;

//AKEDA 5.1 audio
//	int geqAudioMode;
	int geqfreq30;
	int geqfreq60;
	int geqfreq125;
	int geqfreq250;
	int geqfreq500;	
		
	int lowFo;
	int midFo;
	int highFo;

	bool bDsp1;
	bool bDsp2;
	bool bDsp3;
	int gpsVol;

	int sysFlag2;
	int defVol;
	int save1;
	int save2;
	int save3;
	int save4;
	int test786;
	int parkvol;
	bool parkccd;
	int userBass;
	int userMid;
	int userTreb;
	BYTE mcuVer[30];
	BYTE dvdVer[33];
	BYTE gdcVer[32];
	BYTE rtkVer[30];
	bool bSrsOn;
	int trubass;
	int focus;
	int defintion;
	int limiter;
	int trubassfreq;
	int space;
	int center;
	BYTE radarSwitch;
	bool bInAJX;  
	char customer_id[20];
}S_MCU_DATA_SETTINGS;

typedef struct 
{
	bool accon;
	int source;
	int state;

} S_MCU_DATA_SYSTEM;

typedef struct 
{
	int cdcType;
	int cdcVideo;
	int discNo;
	int track;
	int minute;
	int second;
	int playMode;
	int playState;
}S_MCU_DATA_CDC;

typedef struct  
{


	int keyType;
	int carType;
	int powerKeyType;
	int parkType;
	int fmStopVal;
	int amStopVal;
	int tvType;
	int canType;
	
	int btModule;
	int RadioModule;
	int SourceValidBit;
	int IconSW;  //LOAD_ACTIVATION_FUNCICON
	int RdsSel;//0:rds off.1:rds On
}S_MCU_DATA_EXTINFO;
enum{
	E_BT_MODULE_BC3_JYT = 0,
	E_BT_MODULE_BC3_NOMAL,
	E_BT_MODULE_BC6_WENQ,
};
typedef struct
{
	int tvNP;
	int tvScanFlag;
	int tvFreq;
	int tvProgress;
	int tvDisplayFalg;
	int tvCH;
	int tvSigCheck;
}S_MCU_DATA_TVINFO;

typedef struct  
{
	int curTrack;
	int totalTrack;
	int curTime;
	int totalTime;

}S_MCU_DATA_CDEXTINFO;

typedef struct
{
	int trubass;
	int focus;
	int defintion;
	int limiter;
	int center;
	int space;
	int trubassfreq;
	int input;
	int output;
	
	int srsOrEqchange;
	bool loud;
}S_MCU_DATA_SRSINFO;

typedef struct  
{
	int  RADIO_AREA;            
	int  LANG_SEL;               
	int  FM_STOP_VAL;           
	int  AM_STOP_VAL;          
	int  TV_SEL;                  
	int  FUNC_SEL;                
	int  MODE_SEL;              
	int  CAR_SEL;                 
	int  DSP_SEL; 

	int  temp[50];

}S_MCU_DATA_FACTORY;

typedef struct
{
	BYTE bSave0;
	BYTE bSave1;
	BYTE bSave2;
	BYTE bSave3;
	BYTE bSave4;
	BYTE bSave5;
	BYTE bSave6;
	BYTE bSave7;
}S_MCU_ARMSAVE_DATA_INFO;


typedef struct
{
	int carType;	
	int canType;
}S_MCU_CAN_DATA_INFO;


typedef struct  
{
	S_MCU_DATA_CTRL sCtrl;
	S_MCU_DATA_DEVEICE sDeveice;
	S_MCU_DATA_RADIO sRadio;
	S_MCU_CAN_DATA_INFO sCanInfo;
	//S_MCU_DATA_VIDEO sVideo;
	S_MCU_DATA_SETTINGS sSettins;
	S_MCU_DATA_SYSTEM sSystem;
	//S_MCU_DATA_MEDIA sArmMedia;
	S_MCU_DATA_CDC sCdc;
	S_MCU_ARMSAVE_DATA_INFO sArmSaveData;
		
	int currentSource;
	int currentState;
	int bMainMenuDlg;
	int bAndroidAudio;
	int extType;
	int extTime;
	int appData[10];
	S_MCU_DATA_EXTINFO sExtInfo;
	//S_MCU_DATA_CANINFO sCanInfo;
	S_MCU_DATA_TVINFO sTVInfo;
	S_MCU_DATA_SRSINFO sSrsInfo;
	S_MCU_DATA_FACTORY sFactoryInfo;
	
	int backBright;
	int illControl;
	bool bAccOnOrPowerOn;  //0=b+ 1=ACC On
	bool bSRSOnOrOff;	 //0=off 1=on
	bool bUpdateAvInfo;
	WORD savePath[MAX_PATH];
	int nLanguage;
	int nCarFlag;
	bool bLogoCustom;
	bool bQibla;
	bool bInputASR;
	bool bInputBand;
	bool bMP4alpha;
	bool bFastPark;
	bool _3gTalking;	// 3Gͨ��״?
	bool bBTTalking;
	int btTalkState;
	int ledtype;
	int ledtime;
	int nDiscNumber;
	int nPlayTrack;
	int iSrsType;
	bool CarTimeChange;
}S_MCU_DATA_ALLINFO;

#define MAX_KEY_ONE_LINE   15
typedef struct  
{
	int wheelType;
	int maxRes0;
	int maxRes1;
	int key0ResTab[MAX_KEY_ONE_LINE];
	int key1ResTab[MAX_KEY_ONE_LINE];
	int keyValTab[MAX_KEY_ONE_LINE*2];
}S_WHEEL_ATTR;

typedef struct
{
	WORD gpsPath[MAX_PATH];
	bool bGpsRun;
	int curMainPage;
	int mainPageKeyTab[MAX_MAIN_KEY_NUM];
	WORD curStatePath[2];
	int curStateID;
	bool bWheelStudy;
	S_WHEEL_ATTR wheelAttr;
	WORD backPhotoPath[MAX_PATH];
	WORD logoPath[MAX_PATH];
	bool bTftLampOn;
	bool bGPSAutoSetTime;
	int nTimeArea;	//will
	int loadCalibration_flag;
	WORD g_btLocalName[30];// = _T("CARBT");
	WORD g_btLocalCode[30];// = _T("0000");
	//SYSTEMTIME settime; 
	
	bool apkRefresh;							//����ˢ��
	int apkNum;									//������
	char apkName[MAX_PACKAGE_NUM][MAX_PATH];	//androidӦ�ð���
	int applicationNum;									//������
	char applicationName[MAX_PACKAGE_NUM][MAX_PATH];	//androidӦ�ð���
	int sysflag;
}S_MCU_SET_ALLINFO; 


typedef struct 
{
	int vmCurDiscTotalNum;		// ��ǰ������Ŀ
	int vmCurPlayDisc;			// ��ǰ���ŵ�
	int vmCurRecoingInfo;		// ��ǰ¼����Ϣ
	int vmPlayDiscTotalTime;	// ������ʱ��
	int vmCurRecDiscNum;		// ¼�Ƶĵ�Ƭ��
	int vmRecodeDiscInfo;		// ��¼�Ƶ�Ƭ����Ϣ
	int vmDiscRecState;			// ¼��״̬
	int vmCurRecTrack;			// ��ǰ¼����Ŀ
	int vmDiscRecPet;			// ¼�ưٷֱ�
	int vmDiscFormatInfo;		// ��ʽ����Ϣ
	int vmRecDiscTotalTrack;	//¼�Ƶ�����Ŀ
	int vmCurSeletDelDisc;
	int vmCurSeletRecDisc;
	int vmAllDiscInfo[16];		//���е�Ƭ��Ϣ
	int vmCurPlayTarck;
	int vmotherDiscInfo[9];	//������Ϣ
	int vmDiscFormatPet;//��ʽ���ٷֱ�
}S_MCU_VMDISC_INFO;

typedef struct
{
	bool bDirLoadFlag;	
	bool bFileLoadFlag;
	int mp3Num;
	int mp4Num;
	int jepgNum;
	int totalTime;
	int currentTime;
	int PlayWindowType;	
	int currentDir;
	int currentFile;
	int nCurPlayItem;   //��ʾ��ǰ����
	int loadSchnedule;	
	int loadDirNum;
	int loadFolderNum;
	int loadFileNum;
	bool bFolderRefresh;
	bool bFileRefresh;
	WORD currentSong[MAX_MP3_INFO_NUM];
	WORD currentArtist[MAX_MP3_INFO_NUM];
	WORD currentAlbum[MAX_MP3_INFO_NUM]; 
}S_MCU_MP3_ALLINFO; 


typedef struct 
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}S_ENVENT_TIME;



typedef struct{
	bool bHaveMediaCard;
	bool bHaveGpsCard;
	bool bHaveUsbStorage;
	bool bHaveHDD;
}S_DEV_STATE;


#define MAX_TELNO_LEN     25
#define MAX_TELNAME_LEN   25
#define MAX_TELPINYIN_LEN 25
#define MAX_TELBOOK_NUM   1000
#define MAX_TELRECORD_NUM 100

enum
{
	TELTYPE_CALLOUT = 0,
	TELTYPE_RECEIVED,
	TELTYPE_MISSED,
	TELTYPE_ALL,
};

enum
{
	DVDTYPE_NULL = 0,
	DVDTYPE_MP3,
	DVDTYPE_JEPG,
	DVDTYPE_OTHER,
};

enum
{
	DVDDISPLAY_NULL = 0,
	DVDDISPLAY_MP3,
	DVDDISPLAY_JEPG,
	DVDDISPLAY_OTHER,
};
typedef struct  
{
	WORD telNo[MAX_TELNO_LEN];
	int telType;
	S_ENVENT_TIME time;
	DWORD talkTime;
}S_TELRECORD_DATA;

typedef struct 
{
	WORD telNo[MAX_TELNO_LEN];
	WORD name[MAX_TELNAME_LEN];
	WORD pinyin[MAX_TELPINYIN_LEN];
}S_TELBOOK_DATA;

typedef struct  
{
	WORD telNo[MAX_TELNO_LEN];
	WORD name[MAX_TELNAME_LEN];
	int TotalNumber;
}S_TELBOOK_DATA_EX;

typedef struct  
{
	WORD telNo[MAX_TELNO_LEN];
	WORD name[MAX_TELNAME_LEN];
	WORD pinyin[MAX_TELPINYIN_LEN];
}S_PAIRING_DATA;

typedef struct  
{
	int btHfState;
	int btAvState;
	int btHfForceState;
	BYTE btDunState;
	bool bBookUpdate;
	bool bBookNeedSave;
	bool bBookOnSimCard;
	bool bDownLoad;
	int btSendPaWait;
	int btAutoAnswerWait;
	WORD btStateInfoStr[30];
	WORD btInComingStr[30];
	WORD btInComingName[30];
	WORD btAddr[30];
	int btEncodeType;
	bool bDownloadOK;
	bool bHasTalkingRecord;
	S_TELRECORD_DATA btCurTalkingRecord;
	WORD btVer[30];
	char btdialnumber[30];
	int btrecorddelone;
	char btaddr1[30];
	S_TELBOOK_DATA_EX sItemBtData[MAX_MP3_NAME_NUM];
	int TotalNumber;
	int btsysFlag;
}S_BT_DATA_ALLINFO;

 
typedef struct
{
	int totalFolder;
	int totalFile;
	int curFolderSelNum;	//��ǰ������Ŀ
	int curFileSelNum;		//��ǰ������Ŀ
	WORD folderPath[MAX_PATH];		//�ļ���·��
	WORD filePath[MAX_PATH];		//�ļ�·��
	double playTime;
	double FavplayTime;
	double totalTime;
	bool bResume;		//����״̬
	bool bDocument;		//���ļ�����򿪽��벥��
	int playMode;
	//LONGLONG fileSize;
	bool bInsert;		//��ʾ�п����ȥ
	WORD cardName[MAX_PATH];	//��������
	bool bPlayFav;		//�����ҵ��
}S_AV_DATA_INFO;

typedef struct
{
	S_AV_DATA_INFO audio;
	S_AV_DATA_INFO video;
	S_AV_DATA_INFO photo;
}S_AV_DATA_ALLINFO;

#define SYS_SOURCE_RADIO 0
#define SYS_SOURCE_CD    1
#define SYS_SOURCE_USB   2
#define SYS_SOURCE_SD    3     //no longer int use
#define SYS_SOURCE_CDC   4     //no longer int use
#define SYS_SOURCE_CARUSB      3   //ԭ��USB
#define SYS_SOURCE_CARIPOD     4  //ԭ��IPOD

#define SYS_SOURCE_TV    5
#define SYS_SOURCE_AUX   6
#define SYS_SOURCE_AUX2  7
#define SYS_SOURCE_IPOD  8
#define SYS_SOURCE_DVBT  9
#define SYS_SOURCE_MP3  10
#define SYS_SOURCE_MEDIAPLAY 11
#define SYS_SOURCE_CMMB  12
#define SYS_SOURCE_BTMUSIC  13
#define SYS_SOURCE_NET_RADIO 14
#define SYS_SOURCE_VMDISC  14
#define SYS_SOURCE_POWER_OFF 15
#define SYS_SOURCE_OTHER_APP 16  //������Ӧ�� 


#define EXIT_SYS_EXIT_POWEROFF	1
#define EXIT_SYS_EXIT_CD			2
#define EXIT_SYS_EXIT_IPOD	3
#define EXIT_SYS_EXIT_GPS	4
#define EXIT_SYS_EXIT_3GANDBT	5
#define EXIT_SYS_EXIT_BTTALK	6
#define EXIT_SYS_EXIT_3GTALK	7
#define EXIT_SYS_EXIT_TFTOFF	8
#define EXIT_SYS_EXIT_MP3		9
#define EXIT_SYS_EXIT_PARK		10
#define EXIT_SYS_HAVE_MP3STORAGE	11
#define EXIT_SYS_HAVE_MP3USB	12
#define EXIT_SYS_NO_MP3STORAGE	13
#define EXIT_SYS_NO_MP3USB		14
#define EXIT_SYS_EXIT_CDFINSH	15
#define EXIT_SYS_PAUSE_MP3		16
#define EXIT_SYS_PLAY_MP3		17
#define EXIT_SYS_EXIT_RADIOKEYBOARD	18
#define EXIT_SYS_EXIT_CDNOFINSH	19
#define EXIT_SYS_ENTER_TFTOFF	20
#define EXIT_SYS_EXIT_TFTOFF1	21
#define EXIT_SYS_MODE_PLAYMP3	22
#define EXIT_SYS_MODE_PAUSEMP3	23
#define EXIT_SYS_EXIT_SETUP		24
#define EXIT_SYS_TEST_786		25
#define EXIT_SYS_EXIT_POWEROFF1	26
#define EXIT_SYS_PLAY_VIDEO		27
#define EXIT_SYS_EXIT_ACCOFF		28
#define EXIT_SYS_EXIT_RDS		29
#define EXIT_SYS_CLOSE			30



#define USER_STATE_NORMAL     0
#define USER_STATE_SETUP      1
#define USER_STATE_BT         2
#define USER_STATE_BT_TALKING 3
#define USER_STATE_GPS        4
#define USER_STATE_CCD        5
#define USER_STATE_BACKSIGHT  6
#define USER_STATE_PHOTO      7
#define USER_STATE_EBOOK      8
#define USER_STATE_TFT_OFF    9
#define USER_STATE_LAUNCH       10
#define USER_STATE_THREEAPP   11
#define USER_STATE_CAR_BT     12  //car bt
#define USER_STATE_APP4       13
#define USER_STATE_APP5       14  //��
#define USER_STATE_APP6       15  
#define USER_STATE_APP7       16  
#define USER_STATE_APP8       17
#define USER_STATE_APP9       18
#define USER_STATE_APP10      19
#define USER_STATE_3G_TALKING 20
#define USER_STATE_VOICE_APP  21
#define USER_STATE_FOLDER	  22
#define USER_STATE_CAN		  23
#define USER_STATE_ONE_KEY_NAVI	  24
#define USER_STATE_3G		  25
#define USER_STATE_WIFI		  26
#define USER_STATE_SMS		  27

#define USER_STATE_RDS		28

#define USER_STATE_MAX        29



#define MSGD_DEVEICE_DISCIN    0x01
#define MSGD_DEVEICE_DISCOUT   0x02
#define MSGD_DEVEICE_USBIN     0x03
#define MSGD_DEVEICE_USBOUT    0x04
#define MSGD_DEVEICE_SDIN      0x05
#define MSGD_DEVEICE_SDOUT     0x06
#define MSGD_DEVEICE_IPODIN    0x07
#define MSGD_DEVEICE_IPODOUT   0x08
#define MSGD_DEVEICE_DISCOUT2  0x09
#define MSGD_DEVEICE_CDCIN     0x10
#define MSGD_DEVEICE_CDCOUT    0x11

#define DVD_STATE_LOADING       0
#define DVD_STATE_PLAY          1
#define DVD_STATE_PAUSE         2
#define DVD_STATE_FF            3
#define DVD_STATE_REW           4
#define DVD_STATE_STOP          5
#define DVD_STATE_REAL_STOP     6
#define DVD_STATE_ROOT          7
#define DVD_STATE_TITLE         8
#define DVD_STATE_SETUP         9
#define DVD_STATE_UPGRADE       0x0A
#define DVD_STATE_EJECT         0x0B
#define DVD_STATE_PGM_SET       0x0C
#define DVD_STATE_PGM_PLAY      0x0D
#define DVD_STATE_PGM_OFF       0x0E
#define DVD_STATE_ERR           0x0F
#define DVD_STATE_PRE_STOP     0x10

//#define DVD_STATE_DISC_LOADING  0x10
#define DVD_STATE_USB_LOADING   0x11
#define DVD_STATE_SD_LOADING    0x12

#define DVD_DISC_TYPE_LOADING		0
#define DVD_DISC_TYPE_ERR			1
#define DVD_DISC_TYPE_CDDA			2
#define DVD_DISC_TYPE_HDCD		3
#define DVD_DISC_TYPE_VCD			4
#define DVD_DISC_TYPE_SVCD			5
#define DVD_DISC_TYPE_DVD			6
#define DVD_DISC_TYPE_DVD_AUDIO	7
#define DVD_DISC_TYPE_MP3			8
#define DVD_DISC_TYPE_WMA			9
#define DVD_DISC_TYPE_PHOTO		0x0A
#define DVD_DISC_TYPE_MP4			0x0B
#define DVD_DISC_TYPE_MIX			0x0C
#define DVD_DISC_TYPE_CD_ROM		0x0D
#define DVD_DISC_TYPE_UNKNOW		0x0E


#define SYSFLAG_BDISTIME         BIT0
#define SYSFLAG_BAUTOANSWER      BIT1
#define SYSFLAG_BBTPOWEROFF      BIT2
#define SYSFLAG_BDISBREACK       BIT3
#define SYSFLAG_BDISBACKSIGHT    BIT4
#define SYSFLAG_BGPSMONITOR      BIT5  //0->��GPS������GPS����  1->GPS����ʱ��GPS����
#define SYSFLAG_BPIP             BIT6
#define SYSFLAG_BALLKEYPOWERON   BIT7

#define BIT_SETUPKEY_ST_DVD     BIT0
#define BIT_SETUPKEY_IFLY_DVD   BIT1
#define BIT_SETUPKEY_LOUD_NAVI  BIT2
#define BIT_SETUPKEY_APS_TEL    BIT4
#define BIT_SETUPKEY_TEL_360    BIT6

#define SRSFLAG_BSRS             BIT0
#define SRSFLAG_BAGC             BIT1
#define SRSFLAG_B2P1             BIT2

#define SYSFLAG2_BGPSSOUNDMODE   BIT0  //GPS������ʽ 0->���� 1->�л�
#define SYSFLAG2_BBACKMUTE       BIT1  //����ʱ����
#define SYSFLAG2_BDEFVOL         BIT2  //ACC ONʱʹ��Ĭ������ 

#define SYS_EQ_USER              0
#define SYS_EQ_POP               1
#define SYS_EQ_CLASSIC           2
#define SYS_EQ_ROCK              3
#define SYS_EQ_JAZZ              4
#define SYS_EQ_CLUB              5
#define SYS_EQ_COUNTRY           6
#define SYS_EQ_DANCE             7
#define SYS_EQ_SOFT              8
#define SYS_EQ_FLAT              9
#define SYS_EQ_CINEMA			 10
#define SYS_EQ_STANDARD			 15

#define SYS_EQ_SW_MAX            10

#define SYS_EQ_NOUSE			9

#define SYS_VIDEO_USER			0
#define SYS_VIDEO_NORMAL		1
#define SYS_VIDEO_BRIGHT		2
#define SYS_VIDEO_SOFT			3

//AKEDA 5.1 audio add by liujg
#define SYS_PEQ_FL               0  //ǰ��
#define SYS_PEQ_FR               1  //ǰ��
#define SYS_PEQ_BL               2  //����
#define SYS_PEQ_BR               3  //����
#define SYS_PEQ_C                4	//����
#define SYS_PEQ_W                5  //�ص���

/************************************************************************/
/*                       CAN ��������                                   */
/************************************************************************/
//command head
#define ARM_COMMAND_CAN_DATA_ONCE			0xC0		//ֻ����D��
#define ARM_COMMAND_CAN_DATA_RPT			0xC1		//ѭ������
#define ARM_COMMAND_CAN_SEL_SAVE_ID			0xC7		//MCU������Ҫ��������� //ZH_018 Add



//MCUDATA_EXT S_MCU_DATA_ALLINFO *g_pMcuData;
MCUDATA_EXT S_BT_DATA_ALLINFO *g_pBtData;
MCUDATA_EXT BYTE *g_pBackData;
//MCUDATA_EXT S_MCU_SET_ALLINFO *g_pMcuSetData;
//MCUDATA_EXT S_AV_DATA_ALLINFO *g_pAvData;
//MCUDATA_EXT S_MCU_MP3_ALLINFO *g_pMcuMp3Data;
//MCUDATA_EXT S_IPOD_ALLINFO *g_piPodData;
//MCUDATA_EXT S_NET_DATA_ALL_INFO *g_pNetData;

#define MCU_REFRESH_SYSINFO    BIT0
#define MCU_REFRESH_BTINFO     BIT1
#define MCU_REFRESH_HAVE_KEY   BIT2
#define MCU_REFRESH_DEVEICE    BIT3




#define BT_HF_STATE_INIT         0
#define BT_HF_STATE_IDLE         1
#define BT_HF_STATE_CONNECTING   2
#define BT_HF_STATE_CONNECTED    3
#define BT_HF_STATE_OUTGOING     4
#define BT_HF_STATE_INCOMING     5
#define BT_HF_STATE_TALKING      6
#define BT_HF_STATE_TALKING_END      7

#define BT_AV_STATE_INIT         0
#define BT_AV_STATE_IDLE         1
#define BT_AV_STATE_CONNECTING   2
#define BT_AV_STATE_CONNECTED    3
#define BT_AV_STATE_PLAYING      4
#define BT_AV_STATE_AVRCP_CONNECTED    5


#define BT_DUN_STATE_INIT        0
#define BT_DUN_STATE_IDLE        1
#define BT_DUN_STATE_CONNECTING  2
#define BT_DUN_STATE_CONNECTED   3
#define BT_DUN_STATE_INLINE      4

#define TEL_TYPE_INCOMING        0
#define TEL_TYPE_OUTGOING        1
#define TEL_TYPE_NO_TALKING      2

#define _3G_TALKING_STATE_HANGUP		0
#define _3G_TALKING_STATE_OUTGOING		1
#define _3G_TALKING_STATE_INCOMING		2
#define _3G_TALKING_STATE_PICKUP		3


MCUDATA_EXT void InitMcuData();

//MCUDATA_EXT CString g_appCmdLine;
#ifdef CAN_INFO_COMMUNICATION
//def CANCOMM_LIB
//#include "mcuAPI.h"
/*************************************************************************/
/*                   ������������                                        */
/*************************************************************************/
//factory command head
//0x89 command  MCU->ARM 
#define ARM_COMMAND_FACTORY				0x89	//������������
//0xA0 ARM->MCU
#define MCU_COMMAND_FACTORY				0xA0	//����������

/*****************************************************************/
//factory command end
/*******************************************************************/

/************************************************************************/
/*                       CAN ��������                                   */
/************************************************************************/
//command head
#define ARM_COMMAND_CAN_DATA_ONCE			0xC0		//ֻ����D��
#define ARM_COMMAND_CAN_DATA_RPT			0xC1		//ѭ������
#define ARM_COMMAND_CAN_SEL_SAVE_ID			0xC7		//MCU������Ҫ��������� //ZH_018 Add

/************************************************************************/
/*							  ������״̬                                */
/************************************************************************/

/*�ΰ�˹*/ 
#define	ONSTAR_STATE_DICONNECTED	 0x00   //δ����
#define ONSTAR_STATE_CONNECTED		 0x01	//������  ����  
#define ONSTAR_STATE_INCOMING		 0x02   //����    ����
#define ONSTAR_STATE_OUTGOING		 0x03	//����
#define ONSTAR_STATE_TALKING		 0x04	//ͨ����
//add by pxz for BK   end
#define DVD_STATE_DISC_LOADING  0x10
//#define DVD_STATE_DISC_LOADING  0x10
#define DVD_STATE_NO_SUPPORT    0x11
#define DVD_STATE_SD_LOADING    0x12


#define MSGD_DEVEICE_CARIPODIN     0x14
#define MSGD_DEVEICE_CARIPODOUT    0x15
#define MSGD_DEVEICE_CARUSBIN      0x16
#define MSGD_DEVEICE_CARUSBOUT     0x17

#define USER_STATE_CARBT	  23//ԭ�������豸(��ӱ�־408)
#define USER_STATE_CARINFO	  23//20
#define USER_STATE_CARDOOR	  21

#endif
#endif

