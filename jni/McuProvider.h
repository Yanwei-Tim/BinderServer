//============================================================================
// Name        : BTProvider.h
// Author      : liujg
// Description : provider virous of methods to get bt info
//============================================================================



#ifndef MCU_PROVIDER_H
#define MCU_PROVIDER_H

#include <binder/Parcel.h>
using android::Parcel;


#include "UartProxy.h"
#include "IncludeAll.h"


class McuProvider
{
public:
	McuProvider();
	virtual ~McuProvider();
	S_MCU_DATA_ALLINFO* getMcuDataPtr();
	S_MCU_DATA_ALLINFO* getLastMcuDataPtr();
	
	bool is_mcu_beep_enabled();

	//radio commands
	bool checkRadioInfoChanged();
	bool get_radio_info(Parcel& to);
	int get_radio_st();
	int get_radio_loc();
	int get_radio_freq();
	int get_radio_search();
	int get_radio_scan();
	int get_radio_stind();
	int get_radio_area();
	bool get_radio_has_legal_freq();
	int get_radio_legal_freq();
	void set_radio_st(int st);
	void set_radio_loc(int loc);
	void set_radio_freq(int freq);
	void set_radio_search(int search);
	void set_radio_scan(int scan);
	void set_radio_stind(int stind);
	void set_radio_area(int area);
	void set_radio_has_legal_freq(bool enabled);
	void set_radio_legal_freq(int freq);

	//settings commands
	bool checkSettingsInfoChanged();
	bool get_settings_info(Parcel& to);
	int get_settings_brightness();
	int get_settings_navi_max();
	int get_settings_volume();
	int get_settings_btvol();
	int get_settings_gpsvol();
	int get_settings_defvol();
	int get_settings_key_sound();

	int get_settings_treb();
	int get_settings_mid();
	int get_settings_bass();
	
	int get_settings_fade(); 
	int get_settings_bal(); 
	int get_settings_mute();
	int get_settings_audio_mode();
	
	
	void set_settings_brightness(int brightness);
	void set_settings_navi_max(int max);
	void set_settings_volume(int volume);
	void set_settings_btvol(int vol);
	void set_settings_gpsvol(int vol);
	void set_settings_defvol(int vol);
	void set_settings_key_sound(bool enabled);

	void set_settings_treb(int tred);
	void set_settings_mid(int mid);
	void set_settings_bass(int bass);
	
	void set_settings_fade(int fade); 
	void set_settings_bal(int bal); 
	void set_settings_mute(bool enabled);
	void set_settings_audio_mode(int mode);


	
private:
	S_MCU_DATA_ALLINFO m_pMcuData;
	S_MCU_DATA_ALLINFO m_pLastMcuData;
	
};




#endif


