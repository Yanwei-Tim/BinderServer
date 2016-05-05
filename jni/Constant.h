#ifndef CONSTANT_H
#define CONSTANT_H


#ifndef u_t
typedef unsigned int u_t;
#endif

#ifndef UINT
typedef unsigned int UINT;
#endif

#ifndef u_c
typedef unsigned char u_c;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

#ifndef DWORD
typedef unsigned int DWORD;
#endif

#ifndef WORD
typedef unsigned short int WORD;
#endif




#define MCU_SERVIVE "zhonghong.mcu"

typedef struct {
	bool st;
	bool loc;
	int freq;
	int subfreqsize;
} RadioInfo;

typedef struct {
	int bt_status;
	bool name;
	int number;
} BTInfo;

typedef struct {
	int brightness;
	bool key_sound;
	char navi_max; 
} SettingsInfo;

enum {
	DOMAIN_RADIO = 1,
    CMD_RADIO_ST,
    CMD_RADIO_LOC,
    CMD_RADIO_FREQ,
    CMD_RADIO_SEARCH,
    CMD_RADIO_STIND,
    CMD_RADIO_SCAN,
    CMD_RADIO_SEARCH_PREV,
    CMD_RADIO_SEARCH_NEXT,
    CMD_RADIO_BAND,
    CMD_RADIO_AREA,
};

enum {
	DOMAIN_BT = 100,
    CMD_BT_STATUS,
    CMD_BT_NAME,
    CMD_BT_NUMBER,
};

enum {
	DOMAIN_SETTINGS = 200,
    CMD_SETTINGS_BRIGHTNESS,
    CMD_SETTINGS_KEY_SOUND,
    CMD_SETTINGS_NAVI_MAX,
    CMD_SETTINGS_VOL,
    CMD_SETTINGS_TRED,
    CMD_SETTINGS_MID,
    CMD_SETTINGS_BASS,
    CMD_SETTINGS_FADE,
    CMD_SETTINGS_BAL,
    CMD_SETTINGS_MUTE,
    CMD_SETTINGS_BTVOL,
    CMD_SETTINGS_GPSVOL,
    CMD_SETTINGS_DEFVOL,
    CMD_SETTINGS_AUDIO_MODE,
    
};

enum {
	DOMAIN_SYSTEM = 300,
    CMD_SYSTEM_ACCON,
    CMD_SYSTEM_SOURCE,
    CMD_SYSTEM_STATE,
};

enum {
	DOMAIN_MCUKEY = 400,
};
enum {
	DOMAIN_CANINFO = 500,
	CMD_SEND_CAN_DATA = 501,
};




#endif

