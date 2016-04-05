package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.util.Log;


public class McuHardKeyProxy {

	private static final String TAG = "RadioProxy";
	
	
	public boolean registKeyInfoChangedListener(RegistManager.IMcuHardKeyChangedListener listener)
	{
		RegistManager.getInstance().addMcuHardKeyInfoChangedListener(listener);
		return true;
	}
	
	public boolean unregistKeyInfoChangedListener(RegistManager.IMcuHardKeyChangedListener listener)
	{
		RegistManager.getInstance().removeMcuHardKeyInfoChangedListener(listener);
		return true;
	}
}

