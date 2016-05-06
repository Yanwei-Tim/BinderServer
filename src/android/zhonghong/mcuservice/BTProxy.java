/** 
* @author leo
* @version 2016-05-06
* 蓝牙信息帮助类，通过这个类可以获取蓝牙的信息，最好使用静态对象。
* 
*/

package android.zhonghong.mcuservice;

import android.os.Parcel;

public class BTProxy {

	public boolean registBTInfoChangedListener(RegistManager.IBTInfoChangedListener listener)
	{
		return RegistManager.getInstance().addBTInfoChangedListener(listener);
	}
	public BTInfo getBTInfo()
	{
		Parcel out = McuManagerService.getInstance().getPracel(BTInfo.BT_DOMAIN, BTInfo.BT_DOMAIN);
		return BTInfo.CREATOR.createFromParcel(out);
	}
	
	public int getBt_status() {
		return McuManagerService.getInstance().getInt(BTInfo.BT_DOMAIN, BTInfo.BT_STATUS);
	}
	public boolean setBt_status(int bt_status) {
		return McuManagerService.getInstance().sendInt(BTInfo.BT_DOMAIN, BTInfo.BT_STATUS, bt_status);
	}
	public boolean isBt_name() {
		return McuManagerService.getInstance().getBoolean(BTInfo.BT_DOMAIN, BTInfo.BT_NAME);
	}
	public boolean setBt_name(boolean bt_name) {
		return McuManagerService.getInstance().sendBoolean(BTInfo.BT_DOMAIN, BTInfo.BT_NAME, bt_name);
	}
	public int getNumber() {
		return McuManagerService.getInstance().getInt(BTInfo.BT_DOMAIN, BTInfo.BT_NUMBER);
	}
	public boolean setNumber(int number) {
		return McuManagerService.getInstance().sendInt(BTInfo.BT_DOMAIN, BTInfo.BT_NUMBER, number);
	}
	
}

