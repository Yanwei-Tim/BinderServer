
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
	return mcup->sSettins.bBeep;
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
	if(getLastMcuDataPtr()->sSettins.bright != getMcuDataPtr()->sSettins.bright
		|| getLastMcuDataPtr()->sSettins.vol != getMcuDataPtr()->sSettins.vol
		|| getLastMcuDataPtr()->sSettins.bBeep != getMcuDataPtr()->sSettins.bBeep
		|| getLastMcuDataPtr()->sSettins.treb != getMcuDataPtr()->sSettins.treb
		|| getLastMcuDataPtr()->sSettins.mid != getMcuDataPtr()->sSettins.mid
		|| getLastMcuDataPtr()->sSettins.bass != getMcuDataPtr()->sSettins.bass
		|| getLastMcuDataPtr()->sSettins.fade != getMcuDataPtr()->sSettins.fade
		|| getLastMcuDataPtr()->sSettins.bal != getMcuDataPtr()->sSettins.bal
		|| getLastMcuDataPtr()->sSettins.bMute != getMcuDataPtr()->sSettins.bMute
		|| getLastMcuDataPtr()->sSettins.btVol != getMcuDataPtr()->sSettins.btVol
		|| getLastMcuDataPtr()->sSettins.gpsVol != getMcuDataPtr()->sSettins.gpsVol
		|| getLastMcuDataPtr()->sSettins.defVol != getMcuDataPtr()->sSettins.defVol
		|| getLastMcuDataPtr()->sSettins.audioMode != get_settings_audio_mode()
		)
	{

		getLastMcuDataPtr()->sSettins.bright = getMcuDataPtr()->sSettins.bright;
		getLastMcuDataPtr()->sSettins.vol = getMcuDataPtr()->sSettins.vol;
		getLastMcuDataPtr()->sSettins.bBeep = getMcuDataPtr()->sSettins.bBeep;
		getLastMcuDataPtr()->sSettins.treb = getMcuDataPtr()->sSettins.treb;
		getLastMcuDataPtr()->sSettins.mid = getMcuDataPtr()->sSettins.mid;
		getLastMcuDataPtr()->sSettins.bass = getMcuDataPtr()->sSettins.bass;
		getLastMcuDataPtr()->sSettins.fade = getMcuDataPtr()->sSettins.fade;
		getLastMcuDataPtr()->sSettins.bal = getMcuDataPtr()->sSettins.bal;
		getLastMcuDataPtr()->sSettins.bMute = getMcuDataPtr()->sSettins.bMute;
		getLastMcuDataPtr()->sSettins.btVol = getMcuDataPtr()->sSettins.btVol;
		getLastMcuDataPtr()->sSettins.gpsVol = getMcuDataPtr()->sSettins.gpsVol;
		getLastMcuDataPtr()->sSettins.defVol = get_settings_defvol();
		getLastMcuDataPtr()->sSettins.audioMode = get_settings_audio_mode();
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
	to.writeInt32(getMcuDataPtr()->sSettins.bright);
	to.writeInt32(getMcuDataPtr()->sSettins.vol);
	to.writeInt32(getMcuDataPtr()->sSettins.bBeep);
	to.writeInt32(getMcuDataPtr()->sSettins.treb);
	to.writeInt32(getMcuDataPtr()->sSettins.mid);
	to.writeInt32(getMcuDataPtr()->sSettins.bass);
	to.writeInt32(getMcuDataPtr()->sSettins.fade);
	to.writeInt32(getMcuDataPtr()->sSettins.bal);
	to.writeInt32(getMcuDataPtr()->sSettins.bMute);

	to.writeInt32(getMcuDataPtr()->sSettins.btVol);
	to.writeInt32(getMcuDataPtr()->sSettins.gpsVol);
	to.writeInt32(getMcuDataPtr()->sSettins.defVol);
	to.writeInt32(get_settings_audio_mode());
	return true;
}

int McuProvider::get_settings_brightness()
{
	return getMcuDataPtr()->sSettins.bright;
}
int McuProvider::get_settings_navi_max()
{
	return 1;
	//return getMcuDataPtr()->sSettins.;
}
int McuProvider::get_settings_volume()
{
	return getMcuDataPtr()->sSettins.vol;
}
int McuProvider::get_settings_btvol()
{
	return getMcuDataPtr()->sSettins.btVol;
}
int McuProvider::get_settings_gpsvol()
{
	return getMcuDataPtr()->sSettins.gpsVol;
}
int McuProvider::get_settings_defvol()
{
	return getMcuDataPtr()->sSettins.defVol;
}

int McuProvider::get_settings_key_sound()
{
	return getMcuDataPtr()->sSettins.bBeep;
}

int McuProvider::get_settings_treb()
{
	return getMcuDataPtr()->sSettins.treb;
}

int McuProvider::get_settings_mid()
{
	return getMcuDataPtr()->sSettins.mid;
}
int McuProvider::get_settings_bass()
{
	return getMcuDataPtr()->sSettins.bass;
}

int McuProvider::get_settings_fade() 
{
	return getMcuDataPtr()->sSettins.fade;
}
int McuProvider::get_settings_bal() 
{
	return getMcuDataPtr()->sSettins.bal;
}
int McuProvider::get_settings_mute()
{
	return getMcuDataPtr()->sSettins.bMute;
}
int McuProvider::get_settings_audio_mode()
{
	return getMcuDataPtr()->sSettins.audioMode;
}

void McuProvider::set_settings_brightness(int brightness)
{
	getMcuDataPtr()->sSettins.bright = brightness;
}
void McuProvider::set_settings_navi_max(int max)
{
	//getMcuDataPtr()->sSettins.bright
}

void McuProvider::set_settings_volume(int volume)
{
	getMcuDataPtr()->sSettins.vol = volume;
}
void McuProvider::set_settings_btvol(int vol)
{
	getMcuDataPtr()->sSettins.btVol= vol;
}
void McuProvider::set_settings_gpsvol(int vol)
{
	getMcuDataPtr()->sSettins.gpsVol= vol;
}

void McuProvider::set_settings_defvol(int vol)
{
	getMcuDataPtr()->sSettins.defVol = vol;
}

void McuProvider::set_settings_key_sound(bool enabled)
{
	getMcuDataPtr()->sSettins.bBeep = enabled;
}

void McuProvider::set_settings_treb(int treb)
{
	getMcuDataPtr()->sSettins.treb = treb; 
}
void McuProvider::set_settings_mid(int mid)
{
	getMcuDataPtr()->sSettins.mid = mid;
}
void McuProvider::set_settings_bass(int bass)
{
	getMcuDataPtr()->sSettins.bass = bass;
}

void McuProvider::set_settings_fade(int fade) 
{
	getMcuDataPtr()->sSettins.fade = fade;
}
void McuProvider::set_settings_bal(int bal) 
{
	getMcuDataPtr()->sSettins.bal = bal;
}
void McuProvider::set_settings_mute(bool enabled)
{
	getMcuDataPtr()->sSettins.bMute = enabled;
}
void McuProvider::set_settings_audio_mode(int mode)
{
	getMcuDataPtr()->sSettins.audioMode= mode;
}


bool McuProvider::check_system_info_changed(){	
	if(getLastMcuDataPtr()->sSystem.accon != get_system_acc_state()
		|| getLastMcuDataPtr()->sSystem.source != get_system_source()
		|| getLastMcuDataPtr()->sSystem.state != get_system_state()
	)
	{
		getLastMcuDataPtr()->sSystem.accon = get_system_acc_state();
		getLastMcuDataPtr()->sSystem.source = get_system_source();
		getLastMcuDataPtr()->sSystem.state = get_system_state();
		return true;
	}
	return false;
}
bool McuProvider::get_system_info(Parcel& to)
{
	to.setDataPosition(0);
	to.writeInt32(get_system_acc_state());

	return true;
}
void McuProvider::set_system_acc_state(bool accon)
{
	getMcuDataPtr()->sSystem.accon = accon;
}
bool McuProvider::get_system_acc_state()
{
	return getMcuDataPtr()->sSystem.accon;
}

void McuProvider::set_system_source(int source)
{
	getMcuDataPtr()->sSystem.source= source;
}
int McuProvider::get_system_source()
{
	return getMcuDataPtr()->sSystem.source;
}
void McuProvider::set_system_state(int state)
{
	getMcuDataPtr()->sSystem.state= state;
}
int McuProvider::get_system_state()
{
	return getMcuDataPtr()->sSystem.state;
}






