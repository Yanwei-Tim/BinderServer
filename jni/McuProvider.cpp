
#include <string.h>

#include "McuProvider.h"


McuProvider::McuProvider()
{
	memset(&m_pMcuData, 0, sizeof(m_pMcuData));
	memset(&m_pLastMcuData, 0, sizeof(S_MCU_DATA_ALLINFO));
}
McuProvider::~McuProvider()
{
	//parent destructor method will be called;
	//~UartProxy();
}

S_MCU_DATA_ALLINFO* McuProvider::getMcuDataPtr()
{
	return &m_pMcuData;
}
S_MCU_DATA_ALLINFO* McuProvider::getLastMcuDataPtr()
{
	return &m_pLastMcuData;
}


bool McuProvider::is_mcu_beep_enabled()
{
	S_MCU_DATA_ALLINFO* mcup = getMcuDataPtr();
	return mcup->sSystem.bBeep;
}


//radio info providers
bool McuProvider::get_radio_info(Parcel& to)
{
	to.setDataPosition(0);
	to.writeInt32(getMcuDataPtr()->sRadio.freq);
	to.writeInt32(getMcuDataPtr()->sRadio.bSt);
	to.writeInt32(getMcuDataPtr()->sRadio.bLoc);
	to.writeInt32(getMcuDataPtr()->sRadio.bSearch);
	to.writeInt32(getMcuDataPtr()->sRadio.bManu);
	to.writeInt32(getMcuDataPtr()->sRadio.bStInd);
	to.writeInt32(get_radio_area());
	to.writeInt32(get_radio_has_legal_freq());
	to.writeInt32(get_radio_legal_freq());
	return true;
}
bool McuProvider::checkRadioInfoChanged()
{
	if(getLastMcuDataPtr()->sRadio.freq != getMcuDataPtr()->sRadio.freq
		|| getLastMcuDataPtr()->sRadio.bSt != getMcuDataPtr()->sRadio.bSt
		|| getLastMcuDataPtr()->sRadio.bLoc != getMcuDataPtr()->sRadio.bLoc
		|| getLastMcuDataPtr()->sRadio.bSearch != getMcuDataPtr()->sRadio.bSearch
		|| getLastMcuDataPtr()->sRadio.bManu != getMcuDataPtr()->sRadio.bManu
		|| getLastMcuDataPtr()->sRadio.bStInd != getMcuDataPtr()->sRadio.bStInd
		|| getLastMcuDataPtr()->sRadio.radioArea != get_radio_area()
		|| getLastMcuDataPtr()->sRadio.hasLegalFreq != get_radio_has_legal_freq()
		|| getLastMcuDataPtr()->sRadio.legalFreq != get_radio_legal_freq()
	)
	{

		getLastMcuDataPtr()->sRadio.freq = getMcuDataPtr()->sRadio.freq;
		getLastMcuDataPtr()->sRadio.bSt = getMcuDataPtr()->sRadio.bSt;
		getLastMcuDataPtr()->sRadio.bLoc = getMcuDataPtr()->sRadio.bLoc;
		getLastMcuDataPtr()->sRadio.bSearch = getMcuDataPtr()->sRadio.bSearch;
		getLastMcuDataPtr()->sRadio.bManu = getMcuDataPtr()->sRadio.bManu;
		getLastMcuDataPtr()->sRadio.bStInd = getMcuDataPtr()->sRadio.bStInd;
		getLastMcuDataPtr()->sRadio.radioArea = get_radio_area();
		getLastMcuDataPtr()->sRadio.hasLegalFreq= get_radio_has_legal_freq();
		getLastMcuDataPtr()->sRadio.legalFreq= get_radio_legal_freq();
		return true;
	}
	else
	{
		return false;
	}
}


int McuProvider::get_radio_st()
{
	return getMcuDataPtr()->sRadio.bSt;
}
int McuProvider::get_radio_loc()
{
	return getMcuDataPtr()->sRadio.bLoc; 
}
int McuProvider::get_radio_freq()
{
	return getMcuDataPtr()->sRadio.freq; 
}
int McuProvider::get_radio_search()
{
	return getMcuDataPtr()->sRadio.bSearch; 
}
int McuProvider::get_radio_scan()
{
	return getMcuDataPtr()->sRadio.bManu;
}
int McuProvider::get_radio_stind()
{
	return getMcuDataPtr()->sRadio.bStInd;
}
int McuProvider::get_radio_area()
{
	return getMcuDataPtr()->sRadio.radioArea;
}
bool McuProvider::get_radio_has_legal_freq()
{
	return getMcuDataPtr()->sRadio.hasLegalFreq;
}
int McuProvider::get_radio_legal_freq()
{
	return getMcuDataPtr()->sRadio.legalFreq;
}


void McuProvider::set_radio_st(int st)
{
	getMcuDataPtr()->sRadio.bSt = (bool)st;
}
void McuProvider::set_radio_loc(int loc)
{
	getMcuDataPtr()->sRadio.bLoc= (bool)loc;
}
void McuProvider::set_radio_freq(int freq)
{
	getMcuDataPtr()->sRadio.freq = freq;
}
void McuProvider::set_radio_search(int search)
{
	getMcuDataPtr()->sRadio.bSearch = search;
}
void McuProvider::set_radio_scan(int scan)
{
	getMcuDataPtr()->sRadio.bManu = scan;
}
void McuProvider::set_radio_stind(int stind)
{
	getMcuDataPtr()->sRadio.bStInd= stind;
}
void McuProvider::set_radio_area(int area)
{
	getMcuDataPtr()->sRadio.radioArea= area;
}
void McuProvider::set_radio_has_legal_freq(bool enabled)
{
	getMcuDataPtr()->sRadio.hasLegalFreq= enabled;
}
void McuProvider::set_radio_legal_freq(int freq)
{
	getMcuDataPtr()->sRadio.legalFreq= freq;
}





bool McuProvider::checkSettingsInfoChanged()
{
	if(getLastMcuDataPtr()->sSystem.bright != getMcuDataPtr()->sSystem.bright
		|| getLastMcuDataPtr()->sSystem.vol != getMcuDataPtr()->sSystem.vol
		|| getLastMcuDataPtr()->sSystem.bBeep != getMcuDataPtr()->sSystem.bBeep
		|| getLastMcuDataPtr()->sSystem.treb != getMcuDataPtr()->sSystem.treb
		|| getLastMcuDataPtr()->sSystem.mid != getMcuDataPtr()->sSystem.mid
		|| getLastMcuDataPtr()->sSystem.bass != getMcuDataPtr()->sSystem.bass
		|| getLastMcuDataPtr()->sSystem.fade != getMcuDataPtr()->sSystem.fade
		|| getLastMcuDataPtr()->sSystem.bal != getMcuDataPtr()->sSystem.bal
		|| getLastMcuDataPtr()->sSystem.bMute != getMcuDataPtr()->sSystem.bMute
		|| getLastMcuDataPtr()->sSystem.btVol != getMcuDataPtr()->sSystem.btVol
		|| getLastMcuDataPtr()->sSystem.gpsVol != getMcuDataPtr()->sSystem.gpsVol
		|| getLastMcuDataPtr()->sSystem.defVol != getMcuDataPtr()->sSystem.defVol
		|| getLastMcuDataPtr()->sSystem.audioMode != get_settings_audio_mode()
		)
	{

		getLastMcuDataPtr()->sSystem.bright = getMcuDataPtr()->sSystem.bright;
		getLastMcuDataPtr()->sSystem.vol = getMcuDataPtr()->sSystem.vol;
		getLastMcuDataPtr()->sSystem.bBeep = getMcuDataPtr()->sSystem.bBeep;
		getLastMcuDataPtr()->sSystem.treb = getMcuDataPtr()->sSystem.treb;
		getLastMcuDataPtr()->sSystem.mid = getMcuDataPtr()->sSystem.mid;
		getLastMcuDataPtr()->sSystem.bass = getMcuDataPtr()->sSystem.bass;
		getLastMcuDataPtr()->sSystem.fade = getMcuDataPtr()->sSystem.fade;
		getLastMcuDataPtr()->sSystem.bal = getMcuDataPtr()->sSystem.bal;
		getLastMcuDataPtr()->sSystem.bMute = getMcuDataPtr()->sSystem.bMute;
		getLastMcuDataPtr()->sSystem.btVol = getMcuDataPtr()->sSystem.btVol;
		getLastMcuDataPtr()->sSystem.gpsVol = getMcuDataPtr()->sSystem.gpsVol;
		getLastMcuDataPtr()->sSystem.defVol = get_settings_defvol();
		getLastMcuDataPtr()->sSystem.audioMode = get_settings_audio_mode();
		return true;
	}
	else
	{
		return false;
	}
}
bool McuProvider::get_settings_info(Parcel& to)
{
	to.setDataPosition(0);
	to.writeInt32(getMcuDataPtr()->sSystem.bright);
	to.writeInt32(getMcuDataPtr()->sSystem.vol);
	to.writeInt32(getMcuDataPtr()->sSystem.bBeep);
	to.writeInt32(getMcuDataPtr()->sSystem.treb);
	to.writeInt32(getMcuDataPtr()->sSystem.mid);
	to.writeInt32(getMcuDataPtr()->sSystem.bass);
	to.writeInt32(getMcuDataPtr()->sSystem.fade);
	to.writeInt32(getMcuDataPtr()->sSystem.bal);
	to.writeInt32(getMcuDataPtr()->sSystem.bMute);

	to.writeInt32(getMcuDataPtr()->sSystem.btVol);
	to.writeInt32(getMcuDataPtr()->sSystem.gpsVol);
	to.writeInt32(getMcuDataPtr()->sSystem.defVol);
	to.writeInt32(get_settings_audio_mode());
	return true;
}

int McuProvider::get_settings_brightness()
{
	return getMcuDataPtr()->sSystem.bright;
}
int McuProvider::get_settings_navi_max()
{
	return 1;
	//return getMcuDataPtr()->sSystem.;
}
int McuProvider::get_settings_volume()
{
	return getMcuDataPtr()->sSystem.vol;
}
int McuProvider::get_settings_btvol()
{
	return getMcuDataPtr()->sSystem.btVol;
}
int McuProvider::get_settings_gpsvol()
{
	return getMcuDataPtr()->sSystem.gpsVol;
}
int McuProvider::get_settings_defvol()
{
	return getMcuDataPtr()->sSystem.defVol;
}

int McuProvider::get_settings_key_sound()
{
	return getMcuDataPtr()->sSystem.bBeep;
}

int McuProvider::get_settings_treb()
{
	return getMcuDataPtr()->sSystem.treb;
}

int McuProvider::get_settings_mid()
{
	return getMcuDataPtr()->sSystem.mid;
}
int McuProvider::get_settings_bass()
{
	return getMcuDataPtr()->sSystem.bass;
}

int McuProvider::get_settings_fade() 
{
	return getMcuDataPtr()->sSystem.fade;
}
int McuProvider::get_settings_bal() 
{
	return getMcuDataPtr()->sSystem.bal;
}
int McuProvider::get_settings_mute()
{
	return getMcuDataPtr()->sSystem.bMute;
}
int McuProvider::get_settings_audio_mode()
{
	return getMcuDataPtr()->sSystem.audioMode;
}

void McuProvider::set_settings_brightness(int brightness)
{
	getMcuDataPtr()->sSystem.bright = brightness;
}
void McuProvider::set_settings_navi_max(int max)
{
	//getMcuDataPtr()->sSystem.bright
}

void McuProvider::set_settings_volume(int volume)
{
	getMcuDataPtr()->sSystem.vol = volume;
}
void McuProvider::set_settings_btvol(int vol)
{
	getMcuDataPtr()->sSystem.btVol= vol;
}
void McuProvider::set_settings_gpsvol(int vol)
{
	getMcuDataPtr()->sSystem.gpsVol= vol;
}

void McuProvider::set_settings_defvol(int vol)
{
	getMcuDataPtr()->sSystem.defVol = vol;
}

void McuProvider::set_settings_key_sound(bool enabled)
{
	getMcuDataPtr()->sSystem.bBeep = enabled;
}

void McuProvider::set_settings_treb(int treb)
{
	getMcuDataPtr()->sSystem.treb = treb; 
}
void McuProvider::set_settings_mid(int mid)
{
	getMcuDataPtr()->sSystem.mid = mid;
}
void McuProvider::set_settings_bass(int bass)
{
	getMcuDataPtr()->sSystem.bass = bass;
}

void McuProvider::set_settings_fade(int fade) 
{
	getMcuDataPtr()->sSystem.fade = fade;
}
void McuProvider::set_settings_bal(int bal) 
{
	getMcuDataPtr()->sSystem.bal = bal;
}
void McuProvider::set_settings_mute(bool enabled)
{
	getMcuDataPtr()->sSystem.bMute = enabled;
}
void McuProvider::set_settings_audio_mode(int mode)
{
	getMcuDataPtr()->sSystem.audioMode= mode;
}





