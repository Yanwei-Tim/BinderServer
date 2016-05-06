package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.Parcelable;
import android.os.Parcelable.Creator;

public class BTInfo implements Parcelable {
	
	//可以扩张，但是这个值必须和c++服务端的值一致
	//
	public static final int BT_DOMAIN = 100;
	public static final int BT_STATUS = 101;
	public static final int BT_NAME = 102;
	public static final int BT_NUMBER = 103;
	
	int bt_status;
	boolean bt_name;
	int number;
	
	public int getBt_status() {
		return bt_status;
	}
	public void setBt_status(int bt_status) {
		this.bt_status = bt_status;
	}
	public boolean isBt_name() {
		return bt_name;
	}
	public void setBt_name(boolean bt_name) {
		this.bt_name = bt_name;
	}
	public int getNumber() {
		return number;
	}
	public void setNumber(int number) {
		this.number = number;
	}
	
	@Override
	public int describeContents() {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public void writeToParcel(Parcel to, int arg1) {
		// TODO Auto-generated method stub
		//parcel 4 字节对齐，最小的写入单位是4个字节
		to.writeInt(bt_status);
		to.writeInt(bt_name?1:0);
		to.writeInt(number);
	}
	
	public static final Parcelable.Creator<BTInfo> CREATOR = new Creator<BTInfo>() {

		@Override
		public BTInfo createFromParcel(Parcel source) {
			// TODO Auto-generated method stub
			//java端的解包必须和c++服务端的封包一致。
			int status = (source.readInt());
			boolean name = (source.readInt() == 1);
			int number = source.readInt();
			BTInfo bt = new BTInfo();
			bt.setBt_status(status);
			bt.setBt_name(name);
			bt.setNumber(number);
			return bt;
		}

		@Override
		public BTInfo[] newArray(int arg0) {
			// TODO Auto-generated method stub
			return new BTInfo[arg0];
		}
	};
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "BTInfo:bt_status="+bt_status+",bt_name="+bt_name+",number="+number;
	}
}
