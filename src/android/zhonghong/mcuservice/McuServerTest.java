package android.zhonghong.mcuservice;

import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

public class McuServerTest {

	protected static final String TAG = "leo";
	private McuServerTest()
	{
		
	}
	private static McuServerTest test;
	public synchronized static McuServerTest getInstance()
	{
		if(test == null) test = new McuServerTest();
		return test;
	}
	
	
	
	
	public void test()
	{
		
	}
	
	
	
	
}



