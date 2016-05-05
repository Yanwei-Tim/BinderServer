package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.Parcelable;
import android.os.Parcelable.Creator;

public class SystemInfo implements Parcelable {
	
	//�������ţ��������ֵ�����c++����˵�ֵһ��
	//
	public static final int SYSTEM_DOMAIN = 300;
	public static final int SYSTEM_ACCON = 301;
	public static final int SYSTEM_SOURCE = 302;
	public static final int SYSTEM_STATE = 303;
	
	boolean accon;
	int mcuSource;
	int mcuState;
	
	public boolean isAccon() {
		return accon;
	}
	public void setAccon(boolean accon) {
		this.accon = accon;
	}
	
	public int getMcuSource() {
		return mcuSource;
	}
	public void setMcuSource(int mcuSource) {
		this.mcuSource = mcuSource;
	}
	public int getMcuState() {
		return mcuState;
	}
	public void setMcuState(int mcuState) {
		this.mcuState = mcuState;
	}
	@Override
	public int describeContents() {
		// TODO Auto-generated method stub
		return 0;
	}
	@Override
	public void writeToParcel(Parcel to, int arg1) {
		// TODO Auto-generated method stub
		//java�˵ķ�������c++����˵Ľ��һ�¡���ʱû���õ�	
		to.writeInt(isAccon()?1:0);
		to.writeInt(getMcuSource());
		to.writeInt(getMcuState());
	}
	
	public static final Parcelable.Creator<SystemInfo> CREATOR = new Creator<SystemInfo>() {

		@Override
		public SystemInfo createFromParcel(Parcel source) {
			// TODO Auto-generated method stub
			//java�˵Ľ�������c++����˵ķ��һ�¡�	
			SystemInfo system = new SystemInfo();
			system.setAccon(source.readInt()==1);
			system.setMcuSource(source.readInt());
			system.setMcuState(source.readInt());
			return system;
		}

		@Override
		public SystemInfo[] newArray(int arg0) {
			// TODO Auto-generated method stub
			return new SystemInfo[arg0];
		}
	};
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "SystemInfo accon="+isAccon()+",source="+getMcuSource()+",state="+getMcuState();
	}
}

