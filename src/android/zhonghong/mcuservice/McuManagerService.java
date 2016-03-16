package android.zhonghong.mcuservice;

import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;

public class McuManagerService {
	
	private McuManagerService()
	{
		getIMcuService();
	}
	
	private static McuManagerService mInstance;
	public static McuManagerService getInstance()
	{
		if(mInstance == null)
		{
			mInstance = new  McuManagerService();
		}
		return mInstance;
	}
	
	
	private IMcuService mcuService = null;
	public IMcuService getIMcuService()
	{
		if(mcuService == null)
		{
			IBinder b = ServiceManager.getService(Constant.MCU_SERVICE);
			mcuService = IMcuService.Stub.asInterface(b);
		}
		return mcuService;
	}
	
	public Parcel getPracel(int domain, int cmd)
	{
		Parcel p = Parcel.obtain();
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.obtainInfo(domain, cmd, p);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
//			p.recycle();
		}
		return p;
	}
	
	public int getInt(int domain, int cmd)
	{
		Parcel p = Parcel.obtain();
		int result = 0;
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.obtainInfo(domain, cmd, p);
			if(p != null && p.dataSize() > 0)
			{
				result = p.readInt();
			}
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			p.recycle();
		}
		return result;
	}
	public boolean getBoolean(int domain, int cmd)
	{
		Parcel p = Parcel.obtain();
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.obtainInfo(domain, cmd, p);
			if(p != null && p.dataSize() > 0)
			{
				return p.readInt() == 1;
			}
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			p.recycle();
		}
		return false;
	}
	public int[] getIntArray(int domain, int cmd)
	{
		int[] result = new int[16]; 
		Parcel p = Parcel.obtain();
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.obtainInfo(domain, cmd, p);
			if(p != null && p.dataSize() > 0)
			{
				
				p.readIntArray(result);
			}
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			p.recycle();
		}
		return result;
	}
	
	
	public boolean sendInt(int domain, int cmd, int data)
	{
		Parcel p = Parcel.obtain();
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			p.writeInt(data);
			boolean result  = mcuService.sendInfo(domain, cmd, p);
			return result;
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			p.recycle();
		}
		return false;
	}
	public boolean sendBoolean(int domain, int cmd, boolean data)
	{
		Parcel p = Parcel.obtain();
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			p.writeInt(data?1:0);
			boolean result  = mcuService.sendInfo(domain, cmd, p);
			return result;
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			p.recycle();
		}
		return false;
	}
	public boolean registDataChangedListener(int domain, IDataChangedListener listener)
	{
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.registDataChangedListener(domain, listener);
			return true;
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	public boolean unregistDataChangedListener(int domain, IDataChangedListener listener)
	{
		try {
			if(mcuService == null)
			{
				getIMcuService();
			}
			mcuService.unregistDataChangedListener(domain, listener);
			return true;
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
}
