package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.Parcelable;
import android.view.KeyEvent;

public class McuHardKeyInfo implements Parcelable {

	//可以扩张，但是这个值必须和c++服务端的值一致
	//
	public static final int HARDKEY_DOMAIN = 400;
	
	public static final int KEYCODE_MODE = 1001;
	public static final int KEYCODE_POWER = 1002;
	public static final int KEYCODE_TFTOFF = 1003;
	public static final int KEYCODE_NAVI = 1004;
	public static final int KEYCODE_RADIO = 1005;
	public static final int KEYCODE_HOME = 1006;
	public static final int KEYCODE_BACK = 1007;
	public static final int KEYCODE_MENU = 1008;
	public static final int KEYCODE_VOL_DEC = 1009;
	public static final int KEYCODE_VOL_INC = 1010;
	public static final int KEYCODE_PREV = 1011;
	public static final int KEYCODE_NEXT = 1012;
	public static final int KEYCODE_PLAY = 1013;
	
	int keyCode;
	int keyStatus;
	public int getKeyStatus() {
		return keyStatus;
	}

	public void setKeyStatus(int keystatus) {
		this.keyStatus = keystatus;
	}
	public int getKeyCode() {
		return keyCode;
	}

	public void setKeyCode(int keycode) {
		this.keyCode = keycode;
	}

	@Override
	public int describeContents() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public void writeToParcel(Parcel parcel, int arg1) {
		// TODO Auto-generated method stub
		//java端的封包必须和c++服务端的解包一致。暂时没有用到
		parcel.writeInt(getKeyCode());
		parcel.writeInt(getKeyStatus());
	}

	public static final Parcelable.Creator<McuHardKeyInfo> CREATOR = new Creator<McuHardKeyInfo>() {

		@Override
		public McuHardKeyInfo createFromParcel(Parcel source) {
			// TODO Auto-generated method stub
			//java端的解包必须和c++服务端的封包一致。
			McuHardKeyInfo key = new McuHardKeyInfo();
			key.setKeyCode(source.readInt());
			key.setKeyStatus(source.readInt());
			return key;
		}

		@Override
		public McuHardKeyInfo[] newArray(int arg0) {
			// TODO Auto-generated method stub
			return new McuHardKeyInfo[arg0];
		} 
	};

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "McuHardKeyInfo:keycode="+getKeyCode()+",keystatus="+getKeyStatus();
	}
}

