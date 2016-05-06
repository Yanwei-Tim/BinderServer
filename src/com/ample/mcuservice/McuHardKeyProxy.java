/** 
* @author leo
* @version 2016-05-06
* 硬按键信息帮助类，通过这个类可以获取硬按键的信息，最好使用静态对象。
* 只能通过回调来获取。
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

