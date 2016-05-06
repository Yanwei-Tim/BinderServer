package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.Parcelable;
import android.os.Parcelable.Creator;

public class SettingsInfo implements Parcelable {

	//可以扩张，但是这个值必须和c++服务端的值一致
	//
	public static final int SETTINGS_DOMAIN = 200;
	public static final int SETTINGS_BRIGHTNESS = 201;
	public static final int SETTINGS_KEY_SOUND = 202;
	public static final int SETTINGS_NAVI_MAX = 203;
	public static final int SETTINGS_VOL = 204;
	public static final int SETTINGS_TREB = 205;
	public static final int SETTINGS_MID = 206;
	public static final int SETTINGS_BASS = 207;
	public static final int SETTINGS_FADE = 208;
	public static final int SETTINGS_BAL = 209;
	public static final int SETTINGS_MUTE = 210;
	public static final int SETTINGS_BTVOL = 211;
	public static final int SETTINGS_GPSVOL = 212;
	public static final int SETTINGS_DEFVOL = 213;
	public static final int SETTINGS_AUDIOMODE = 214;
	
	int brightness;
	boolean key_sound;
	int navi_max;
	int vol;
	int treb;
	int mid;
	int bass;
	int fade;
	int bal;
	boolean bMute;
	int btVol;
	int gpsVol;
	int defVol;
	int audiomode;

	public int getAudiomode() {
		return audiomode;
	}
	public void setAudiomode(int audiomode) {
		this.audiomode = audiomode;
	}
	public int getBrightness() {
		return brightness;
	}
	public void setBrightness(int brightness) {
		this.brightness = brightness;
	}
	public boolean isKey_sound() {
		return key_sound;
	}
	public void setKey_sound(boolean key_sound) {
		this.key_sound = key_sound;
	}
	public int getNavi_max() {
		return navi_max;
	}
	public void setNavi_max(int navi_max) {
		this.navi_max = navi_max;
	}
	public int getVol() {
		return vol;
	}
	public void setVol(int vol) {
		this.vol = vol;
	}
	public int getTreb() {
		return treb;
	}
	public void setTreb(int treb) {
		this.treb = treb;
	}
	public int getMid() {
		return mid;
	}
	public void setMid(int mid) {
		this.mid = mid;
	}
	public int getBass() {
		return bass;
	}
	public void setBass(int bass) {
		this.bass = bass;
	}
	public int getFade() {
		return fade;
	}
	public void setFade(int fade) {
		this.fade = fade;
	}
	public int getBal() {
		return bal;
	}
	public void setBal(int bal) {
		this.bal = bal;
	}
	public boolean isbMute() {
		return bMute;
	}
	public void setbMute(boolean bMute) {
		this.bMute = bMute;
	}
	public int getBtVol() {
		return btVol;
	}
	public void setBtVol(int btVol) {
		this.btVol = btVol;
	}
	public int getGpsVol() {
		return gpsVol;
	}
	public void setGpsVol(int gpsVol) {
		this.gpsVol = gpsVol;
	}
	public int getDefVol() {
		return defVol;
	}
	public void setDefVol(int defVol) {
		this.defVol = defVol;
	}
	
	@Override
	public int describeContents() {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public void writeToParcel(Parcel to, int arg1) {
		// TODO Auto-generated method stub
		to.writeInt(brightness);
		to.writeInt(key_sound?1:0);
		to.writeInt(navi_max);
	}
	
	public static final Parcelable.Creator<SettingsInfo> CREATOR = new Creator<SettingsInfo>() {
		@Override
		public SettingsInfo createFromParcel(Parcel from) {
			// TODO Auto-generated method stub
			SettingsInfo settings = new SettingsInfo();
			settings.setBrightness(from.readInt());
			settings.setVol(from.readInt());
			settings.setKey_sound(from.readInt()==1);
			settings.setTreb(from.readInt());
			settings.setMid(from.readInt());
			settings.setBass(from.readInt());
			settings.setFade(from.readInt());
			settings.setBal(from.readInt());
			settings.setbMute(from.readInt() == 1);
			settings.setBtVol(from.readInt());
			settings.setGpsVol(from.readInt());
			settings.setDefVol(from.readInt());
			settings.setAudiomode(from.readInt());
			return settings;
		}

		@Override
		public SettingsInfo[] newArray(int arg0) {
			// TODO Auto-generated method stub
			return new SettingsInfo[arg0];
		}
	};
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "SettingsInfo:brightness="+brightness+",key_sound="+key_sound+",navi_max="+navi_max;
	}
}
