package android.zhonghong.mcuservice;

import android.os.Parcel;

public class SettingsProxy {
	
	public boolean registSettingsInfoChangedListener(RegistManager.ISettingsInfoChangedListener listener)
	{
		return RegistManager.getInstance().addSettingsInfoChangedListener(listener);
	}
	public boolean unregistSettingsInfoChangedListener(RegistManager.ISettingsInfoChangedListener listener)
	{
		return RegistManager.getInstance().removeSettingsInfoChangedListener(listener);
	}

	public SettingsInfo getSettingsInfo()
	{
		Parcel out = McuManagerService.getInstance().getPracel(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_DOMAIN);
		return SettingsInfo.CREATOR.createFromParcel(out);
	}
	public int getBrightness() {
		return McuManagerService.getInstance().getInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_BRIGHTNESS);
	}
	public boolean isKey_sound() {
		return McuManagerService.getInstance().getBoolean(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_KEY_SOUND);
	}
	public int getNavi_max() {
		return McuManagerService.getInstance().getInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_NAVI_MAX);
	}
	
	
	public boolean setNavi_max(int navi_max) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_NAVI_MAX, navi_max);
	}
	
	public boolean setBrightness(int bright) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_BRIGHTNESS, bright);
	}
	public boolean setVol(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_VOL, vol);
	}
	public boolean setKey_sound(boolean key_sound) {
		return McuManagerService.getInstance().sendBoolean(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_KEY_SOUND, key_sound);
	}
	public boolean setTreb(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_TREB, vol);
	}
	public boolean setMid(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_MID, vol);
	}
	public boolean setBass(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_BASS, vol);
	}
	public boolean setFade(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_FADE, vol);
	}
	public boolean setBal(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_BAL, vol);
	}
	public boolean setMute(boolean mute) {
		return McuManagerService.getInstance().sendBoolean(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_MUTE, mute);
	}
	public boolean setBTVol(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_BTVOL, vol);
	}
	public boolean setGPSVol(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_GPSVOL, vol);
	}
	public boolean setDefVol(int vol) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_DEFVOL, vol);
	}
	public boolean setAudioMode(int mode) {
		return McuManagerService.getInstance().sendInt(SettingsInfo.SETTINGS_DOMAIN, SettingsInfo.SETTINGS_AUDIOMODE, mode);
	}
	
}

