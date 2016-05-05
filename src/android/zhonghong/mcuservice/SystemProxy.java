package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.IBinder.DeathRecipient;

public class SystemProxy {

	public boolean registSystemInfoChangedListener(RegistManager.ISystemInfoChangedListener listener)
	{
		return RegistManager.getInstance().addSystemInfoChangedListener(listener);
	}
	
	public boolean unregistSystemInfoChangedListener(RegistManager.ISystemInfoChangedListener listener)
	{
		return RegistManager.getInstance().removeSystemInfoChangedListener(listener);
	}
	
	public SystemInfo getSystemInfo()
	{
		Parcel out = McuManagerService.getInstance().getPracel(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_DOMAIN);
		return SystemInfo.CREATOR.createFromParcel(out);
	}
	
	public boolean getAcconStatus() {
		return McuManagerService.getInstance().getBoolean(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_ACCON);
	}
	
	public boolean setMcuSource(int source)
	{
		return McuManagerService.getInstance().sendInt(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_SOURCE, source);
	}
	
	public int getMcuSource()
	{
		return McuManagerService.getInstance().getInt(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_SOURCE);
	}
	
	public boolean setMcuState(int state)
	{
		return McuManagerService.getInstance().sendInt(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_STATE, state);
	}
	
	public int getMcuState()
	{
		return McuManagerService.getInstance().getInt(SystemInfo.SYSTEM_DOMAIN, SystemInfo.SYSTEM_STATE);
	}
	
	// ע�����˽�������֪ͨ�� 
	public boolean registDeathRecipient(DeathRecipient deathCallback)
	{
		return McuManagerService.getInstance().registDeathListener(deathCallback);
	}
	//	ע������˽�������֪ͨ��
	public boolean unregistDeathRecipient(DeathRecipient deathCallback)
	{
		return McuManagerService.getInstance().unregistDeathListener(deathCallback);
	}
	
}

