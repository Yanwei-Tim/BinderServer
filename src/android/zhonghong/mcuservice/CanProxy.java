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
	 *	�������ݸ�can
	 *	һ����can app�������������
	 * 	@param data ���͸�can��byte������Ҫ����canЭ������װ��ͬʱҲҪ����mcu�����ݸ�ʽ
	 */
	public boolean sendCanData(byte[] data)
	{
		return McuManagerService.getInstance().sendByteArray(CanInfo.CANINFO_DOMAIN, CanInfo.CANINFO_SEND_CAN_DATA, data);
	}
	
}

