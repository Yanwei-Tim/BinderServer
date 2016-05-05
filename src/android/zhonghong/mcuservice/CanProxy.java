package android.zhonghong.mcuservice;

import android.os.Parcel;

public class CanProxy {

	public boolean registCanInfoChangedListener(RegistManager.ICanInfoChangedListener listener)
	{
		return RegistManager.getInstance().addCanInfoChangedListener(listener);
	}
	
	public boolean unregistCanInfoChangedListener(RegistManager.ICanInfoChangedListener listener)
	{
		return RegistManager.getInstance().removeCanInfoChangedListener(listener);
	}
	
	/**
	 *	发送数据给can
	 *	一般是can app调用这个方法。
	 * 	@param data 发送给can的byte数组需要根据can协议来封装。同时也要符合mcu的数据格式
	 */
	public boolean sendCanData(byte[] data)
	{
		return McuManagerService.getInstance().sendByteArray(CanInfo.CANINFO_DOMAIN, CanInfo.CANINFO_SEND_CAN_DATA, data);
	}
	
}

