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
	
}

