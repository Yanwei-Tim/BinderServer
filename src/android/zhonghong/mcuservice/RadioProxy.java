package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.util.Log;


public class RadioProxy {

	private static final String TAG = "RadioProxy";
	
	
	public boolean registRadioInfoChangedListener(RegistManager.IRadioInfoChangedListener listener)
	{
		RegistManager.getInstance().addRadioInfoChangedListener(listener);
		return true;
	}
	
	public boolean unregistRadioInfoChangedListener(RegistManager.IRadioInfoChangedListener listener)
	{
		RegistManager.getInstance().removeRadioInfoChangedListener(listener);
		return true;
	}
	
	public RadioInfo getRadioInfo()
	{
		Parcel out = McuManagerService.getInstance().getPracel(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_DOMAIN);
		return RadioInfo.CREATOR.createFromParcel(out);
	}
	
	/**
	 * 收音频率，已经乘以了100使其变为整数，如频率是87.50，返回的是8750，108.0返回的是10800
	 * @return 收音屏率，四个字节，最高两位如果是00：表示FM波段，11：表示AM波段
	 */
	public int getFreq()
	{
		return McuManagerService.getInstance().getInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_FREQ);
	}
	
	public static final int RADIO_BAND_FM = 0;
	public static final int RADIO_BAND_AM = 3;
	/**
	 * @param band:只区分FM和AM， FM都传RADIO_BAND_FM， AM都传RADIO_BAND_AM
	 * @param freq：收音频率 同getFreq（），freq四个字节，最高两位如果是00：表示FM波段，11：表示AM波段
	 * 收音频率，已经乘以了100使其变为整数，如频率是87.50，返回的是8750，108.0返回的是10800
	 * @return 成功如否
	 */
	public boolean setFreq(int band, int freq)
	{
		if(band != RADIO_BAND_FM && band != RADIO_BAND_AM)
		{
			Log.e(TAG, "band only is RADIO_BAND_FM or RADIO_BAND_AM");
			return false;
		}
		int temp = ((band << 14)|(freq&0x3FFF));
		return McuManagerService.getInstance().sendInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_FREQ, temp);
	}
	
	public boolean getST()
	{
		return McuManagerService.getInstance().getBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_ST);
	}
	public boolean setST()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_ST, true);
	}
	
	public boolean getLOC()
	{
		return McuManagerService.getInstance().getBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_LOC);
	}
	public boolean setLOC()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_LOC, true);
	}
	
	public boolean getSearch()
	{
		return McuManagerService.getInstance().getBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SEARCH);
	}
	public boolean setSearch()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SEARCH, true);
	}
	public boolean getScan()
	{
		return McuManagerService.getInstance().getBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SCAN);
	}
	public boolean setScan()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SCAN, true);
	}
	
	public boolean getStInd()
	{
		return McuManagerService.getInstance().getBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_STIND);
	}
	
	//can not set StInd
	/*public boolean setStInd(boolean enabled)
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_STIND, enabled);
	}*/
	
	public boolean setSearchLeft()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SEARCH_LEFT, true);
	}
	public boolean setSearchRight()
	{
		return McuManagerService.getInstance().sendBoolean(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_SEARCH_RIGHT, true);
	}
	
	//useless for now, app has already remember band;
	/*public int getBand()
	{
		return McuManagerService.getInstance().getInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_BAND);
	}
	
	
	public boolean setBand(int band)
	{
		if(band >=0 && band <= 4)
		{
			return McuManagerService.getInstance().sendInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_BAND, band);
		}
		else
		{
			Log.e(TAG, "band is illealge!");
		}
		return false;
	}*/
	
	public boolean setArea(int area)
	{
		return McuManagerService.getInstance().sendInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_AREA, area);
	}
	public int getArea()
	{
		return McuManagerService.getInstance().getInt(RadioInfo.RADIO_DOMAIN, RadioInfo.RADIO_AREA);
	}
	
}
