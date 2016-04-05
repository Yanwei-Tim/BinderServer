package android.zhonghong.mcuservice;

import java.util.List;
import java.util.ArrayList;

import android.os.Parcel;
import android.os.RemoteException;
import android.util.Log;

public class RegistManager {

	public static final String TAG = "RegistManager";
	private RegistManager()
	{
		
	}
	
	private static RegistManager mInstance;
	public static RegistManager getInstance()
	{
		if(mInstance == null) mInstance = new RegistManager();
		return mInstance;
	}
	
	private List<IRadioInfoChangedListener> mRadioInfoChangedListeners = null;
	private List<IBTInfoChangedListener> mBtInfoChangedListeners = null;
	private List<ISettingsInfoChangedListener> mSettingsInfoChangedListeners = null;
	private List<ISystemInfoChangedListener> mSystemInfoChangedListeners = null;
	private List<IMcuHardKeyChangedListener> mMcuHardKeyInfoChangedListeners = null;
	private List<ICanInfoChangedListener> mCanInfoChangedListeners = null;
	
	
	//radio
	protected boolean addRadioInfoChangedListener(IRadioInfoChangedListener listener)
	{
		if(listener == null) return false;
		if(mRadioInfoChangedListeners == null)
		{
			mRadioInfoChangedListeners = new ArrayList<IRadioInfoChangedListener>();
			mRadioInfoChangedListeners.clear();
		}
		
		if(mRadioInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist this radio listener, so skip it");
		}
		else
		{
			mRadioInfoChangedListeners.add(listener);
			if(mRadioInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registRadioInfoChangedListener();
			}
		}
		
		return true;
	}
	protected boolean removeRadioInfoChangedListener(IRadioInfoChangedListener listener)
	{
		if(mRadioInfoChangedListeners != null)
		{
			for(int i=0; i<mRadioInfoChangedListeners.size(); i++)
			{
				if(mRadioInfoChangedListeners.get(i) == listener)
				{
					mRadioInfoChangedListeners.remove(i);
					if(mRadioInfoChangedListeners.size() == 0)
					{
						unregistRadioInfoChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	//bt info
	protected boolean addBTInfoChangedListener(IBTInfoChangedListener listener)
	{
		
		if(listener == null) return false;
		if(mBtInfoChangedListeners == null)
		{
			mBtInfoChangedListeners = new ArrayList<IBTInfoChangedListener>();
			mBtInfoChangedListeners.clear();
		}
		
		if(mBtInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist this bt listener, so skip it");
		}
		else
		{
			mBtInfoChangedListeners.add(listener);
			if(mBtInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registBTInfoChangedListener();
			}
		}
		
		return true;
	}
	protected boolean removeBTInfoChangedListener(IBTInfoChangedListener listener)
	{
		
		if(mBtInfoChangedListeners != null)
		{
			for(int i=0; i<mBtInfoChangedListeners.size(); i++)
			{
				
				if(mBtInfoChangedListeners.get(i) == listener)
				{
					mBtInfoChangedListeners.remove(i);
					if(mBtInfoChangedListeners.size() == 0)
					{
						mBtInfoChangedListeners = null;
						unregistBTInfoChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	//settings info
	protected boolean addSettingsInfoChangedListener(ISettingsInfoChangedListener listener)
	{
		if(listener == null) return false;
		if(mSettingsInfoChangedListeners == null)
		{
			mSettingsInfoChangedListeners = new ArrayList<ISettingsInfoChangedListener>();
			mSettingsInfoChangedListeners.clear();
		}
		
		if(mSettingsInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist this settings listener, so skip it");
		}
		else
		{
			mSettingsInfoChangedListeners.add(listener);
			if(mSettingsInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registSettingsInfoChangedListener();
			}
		}
		
		return true;
	}
	protected boolean removeSettingsInfoChangedListener(ISettingsInfoChangedListener listener)
	{
		if(mSettingsInfoChangedListeners != null)
		{
			for(int i=0; i<mSettingsInfoChangedListeners.size(); i++)
			{
				
				if(mSettingsInfoChangedListeners.get(i) == listener)
				{
					mSettingsInfoChangedListeners.remove(i);
					if(mSettingsInfoChangedListeners.size() == 0)
					{
						mSettingsInfoChangedListeners = null;
						unregistSettingsInfoChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	//system info
	protected boolean addSystemInfoChangedListener(ISystemInfoChangedListener listener)
	{
		if(listener == null) return false;
		if(mSystemInfoChangedListeners == null)
		{
			mSystemInfoChangedListeners = new ArrayList<ISystemInfoChangedListener>();
			mSystemInfoChangedListeners.clear();
		}
		
		if(mSystemInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist this system listener, so skip it");
		}
		else
		{
			mSystemInfoChangedListeners.add(listener);
			if(mSystemInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registSystemInfoChangedListener();
			}
		}
		
		return true;
	}
	protected boolean removeSystemInfoChangedListener(ISystemInfoChangedListener listener)
	{
		if(mSystemInfoChangedListeners != null)
		{
			for(int i=0; i<mSystemInfoChangedListeners.size(); i++)
			{
				
				if(mSystemInfoChangedListeners.get(i) == listener)
				{
					mSystemInfoChangedListeners.remove(i);
					if(mSystemInfoChangedListeners.size() == 0)
					{
						mSystemInfoChangedListeners = null;
						unregistSystemInfoChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	//mcu hard key info
	protected boolean addMcuHardKeyInfoChangedListener(IMcuHardKeyChangedListener listener)
	{
		if(listener == null) return false;
		if(mMcuHardKeyInfoChangedListeners == null)
		{
			mMcuHardKeyInfoChangedListeners = new ArrayList<IMcuHardKeyChangedListener>();
			mMcuHardKeyInfoChangedListeners.clear();
		}
		
		if(mMcuHardKeyInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist this radio listener, so skip it");
		}
		else
		{
			mMcuHardKeyInfoChangedListeners.add(listener);
			if(mMcuHardKeyInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registMcuHardKeyChangedListener();
			}
		}
		return true;
	}
	protected boolean removeMcuHardKeyInfoChangedListener(IMcuHardKeyChangedListener listener)
	{
		if(mMcuHardKeyInfoChangedListeners != null)
		{
			for(int i=0; i<mMcuHardKeyInfoChangedListeners.size(); i++)
			{
				if(mMcuHardKeyInfoChangedListeners.get(i) == listener)
				{
					mMcuHardKeyInfoChangedListeners.remove(i);
					if(mMcuHardKeyInfoChangedListeners.size() == 0)
					{
						unregistMcuHardKeyChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	// can info 
	protected boolean addCanInfoChangedListener(ICanInfoChangedListener listener)
	{
		if(listener == null) return false;
		if(mCanInfoChangedListeners == null)
		{
			mCanInfoChangedListeners = new ArrayList<ICanInfoChangedListener>();
			mCanInfoChangedListeners.clear();
		}
		
		if(mCanInfoChangedListeners.contains(listener))
		{
			Log.i(TAG, "already regist can info listener, so skip it");
		}
		else
		{
			mCanInfoChangedListeners.add(listener);
			if(mCanInfoChangedListeners.size() == 1)
			{
				//add first, then regist
				registCanInfoChangedListener();
			}
		}
		return true;
	}
	protected boolean removeCanInfoChangedListener(ICanInfoChangedListener listener)
	{
		if(mCanInfoChangedListeners != null)
		{
			for(int i=0; i<mCanInfoChangedListeners.size(); i++)
			{
				if(mCanInfoChangedListeners.get(i) == listener)
				{
					mCanInfoChangedListeners.remove(i);
					if(mCanInfoChangedListeners.size() == 0)
					{
						unregistCanInfoChangedListener();
					}
					return true;
				}
			}
		}
		return false;
	}
	
	
	
	DataChangedListener radioDataChangedListener = null;
	//only regist once from mcuserver
	private void registRadioInfoChangedListener()
	{
		if(radioDataChangedListener == null)
		{
			radioDataChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(RadioInfo.RADIO_DOMAIN, radioDataChangedListener);
	}
	
	private void unregistRadioInfoChangedListener()
	{
		if(radioDataChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(RadioInfo.RADIO_DOMAIN, radioDataChangedListener);
		}
	}
	
	DataChangedListener btDataChangedListener = null;
	//only regist once from mcuserver
	private void registBTInfoChangedListener()
	{
		if(btDataChangedListener == null)
		{
			btDataChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(BTInfo.BT_DOMAIN, btDataChangedListener);
	}
	private void unregistBTInfoChangedListener()
	{
		if(btDataChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(BTInfo.BT_DOMAIN, btDataChangedListener);
		}
	}
	
	
	DataChangedListener settingsDataChangedListener = null;
	//only regist once from mcuserver
	private void registSettingsInfoChangedListener()
	{
		if(settingsDataChangedListener == null)
		{
			settingsDataChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(SettingsInfo.SETTINGS_DOMAIN, settingsDataChangedListener);
	}
	private void unregistSettingsInfoChangedListener()
	{
		if(settingsDataChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(SettingsInfo.SETTINGS_DOMAIN, settingsDataChangedListener);
		}
	}
	
	DataChangedListener systemDataChangedListener = null;
	//only regist once from mcuserver
	private void registSystemInfoChangedListener()
	{
		if(systemDataChangedListener == null)
		{
			systemDataChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(SystemInfo.SYSTEM_DOMAIN, systemDataChangedListener);
	}
	private void unregistSystemInfoChangedListener()
	{
		if(systemDataChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(SystemInfo.SYSTEM_DOMAIN, systemDataChangedListener);
		}
	}
	
	DataChangedListener mcuHardKeyChangedListener = null;
	//only regist once from mcuserver
	private void registMcuHardKeyChangedListener()
	{
		if(mcuHardKeyChangedListener == null)
		{
			mcuHardKeyChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(McuHardKeyInfo.HARDKEY_DOMAIN, mcuHardKeyChangedListener);
	}
	
	private void unregistMcuHardKeyChangedListener()
	{
		if(mcuHardKeyChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(McuHardKeyInfo.HARDKEY_DOMAIN, mcuHardKeyChangedListener);
		}
	}
	
	DataChangedListener canInfoChangedListener = null;
	//only regist once from mcuserver
	private void registCanInfoChangedListener()
	{
		if(canInfoChangedListener == null)
		{
			canInfoChangedListener = new DataChangedListener();
		}
		McuManagerService.getInstance().registDataChangedListener(CanInfo.CANINFO_DOMAIN, canInfoChangedListener);
	}
	
	private void unregistCanInfoChangedListener()
	{
		if(canInfoChangedListener != null)
		{
			McuManagerService.getInstance().unregistDataChangedListener(CanInfo.CANINFO_DOMAIN, canInfoChangedListener);
		}
	}
	
	
	
	private void doNotify(int msg, int ext0, int ext1, Parcel parcel)
	{
		if(msg == RadioInfo.RADIO_DOMAIN)
		{
			RadioInfo radio = RadioInfo.CREATOR.createFromParcel(parcel);
			if(radio != null)
			{
				for(int i=0; mRadioInfoChangedListeners != null && i< mRadioInfoChangedListeners.size(); i++)
				{
					mRadioInfoChangedListeners.get(i).notify(null, radio);
				}
			}
		}
		else if(msg == BTInfo.BT_DOMAIN)
		{
			BTInfo bt = BTInfo.CREATOR.createFromParcel(parcel);
			if(bt != null)
			{
				for(int i=0; mBtInfoChangedListeners != null && i<mBtInfoChangedListeners.size(); i++)
				{
					mBtInfoChangedListeners.get(i).notify(null, bt);
				}
			}
		}
		else if(msg == SettingsInfo.SETTINGS_DOMAIN)
		{
			SettingsInfo settings = SettingsInfo.CREATOR.createFromParcel(parcel);
			if(settings != null)
			{
				for(int i=0; mSettingsInfoChangedListeners != null && i<mSettingsInfoChangedListeners.size(); i++)
				{
					mSettingsInfoChangedListeners.get(i).notify(null, settings);
				}
			}
		}
		else if(msg == McuHardKeyInfo.HARDKEY_DOMAIN)
		{
			McuHardKeyInfo info = McuHardKeyInfo.CREATOR.createFromParcel(parcel);
			if(info != null)
			{
				for(int i=0; mMcuHardKeyInfoChangedListeners != null && i<mMcuHardKeyInfoChangedListeners.size(); i++)
				{
					mMcuHardKeyInfoChangedListeners.get(i).notify(null, info);
				}
			}
		}
		else if(msg == CanInfo.CANINFO_DOMAIN)
		{
			short[] result = CanInfo.toShortArray(parcel);
			for(int i=0; mCanInfoChangedListeners != null && i<mCanInfoChangedListeners.size(); i++)
			{
				mCanInfoChangedListeners.get(i).notify(null, result);
			}
		}
	}
	
	//binder server callback this interface
	class DataChangedListener extends IDataChangedListener.Stub
	{
		@Override
		public void notify(int msg, int ext0, int ext1, Parcel parcel)
				throws RemoteException {
			// TODO Auto-generated method stub
			doNotify(msg, ext0, ext1, parcel);
		}
	}
	
	public interface IRadioInfoChangedListener {
		void notify(int[] changeCMDs, RadioInfo radio);
	}
	public interface IBTInfoChangedListener {
		void notify(int[] changeCMDs, BTInfo btinfo);
	}
	public interface ISettingsInfoChangedListener {
		void notify(int[] changeCMDs, SettingsInfo settings);
	}
	public interface ISystemInfoChangedListener {
		void notify(int[] changeCMDs, SystemInfo settings);
	}
	public interface IMcuHardKeyChangedListener {
		void notify(int[] changeCMDs, McuHardKeyInfo hardkey);
	}
	public interface ICanInfoChangedListener {
		void notify(int[] changeCMDs, short[] caninfo);
	}
	
}

