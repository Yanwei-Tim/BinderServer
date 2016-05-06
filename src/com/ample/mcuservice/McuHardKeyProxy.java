/** 
* @author leo
* @version 2016-05-06
* Ӳ������Ϣ�����࣬ͨ���������Ի�ȡӲ��������Ϣ�����ʹ�þ�̬����
* ֻ��ͨ���ص�����ȡ��
*/

package android.zhonghong.mcuservice;


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

