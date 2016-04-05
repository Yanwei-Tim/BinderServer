package android.zhonghong.mcuservice;

import android.util.Log;

public class Constant {

	public static final String MCU_SERVICE = "zhonghong.mcu"; 
	
	
	public static final boolean DEBUG_BINDER_TRANSACT = true; 
	public static final String TAG_BINDER_TRANSACT = "binder_transact"; 
	
	public static void LOGB(String msg)
	{
		if(DEBUG_BINDER_TRANSACT)
		{
			Log.i(TAG_BINDER_TRANSACT, msg);
		}
	}
}

