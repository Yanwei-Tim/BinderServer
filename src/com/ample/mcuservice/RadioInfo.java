package android.zhonghong.mcuservice;

import android.os.Parcel;
import android.os.Parcelable;

public class RadioInfo implements Parcelable {

	//可以扩张，但是这个值必须和c++服务端的值一致
	//	
	public static final int RADIO_DOMAIN = 1;
	public static final int RADIO_ST = 2;
	public static final int RADIO_LOC = 3;
	public static final int RADIO_FREQ = 4;
	public static final int RADIO_SEARCH = 5;  	//浏览
	public static final int RADIO_STIND = 6;   	//双环
	public static final int RADIO_SCAN = 7; 	//扫描
	public static final int RADIO_SEARCH_LEFT = 8; 
	public static final int RADIO_SEARCH_RIGHT = 9; 	
	public static final int RADIO_BAND = 10;
	public static final int RADIO_AREA = 11;
	
	boolean st;
	boolean loc;
	boolean search;
	boolean scan;
	boolean stind;
	int freq;
	int band;
	int area;
	boolean hasLegalFreq;
	public boolean isHasLegalFreq() {
		return hasLegalFreq;
	}

	public void setHasLegalFreq(boolean hasLegalFreq) {
		this.hasLegalFreq = hasLegalFreq;
	}

	public int getLegalFreq() {
		return legalFreq;
	}

	public void setLegalFreq(int legalFreq) {
		this.legalFreq = legalFreq;
	}

	int legalFreq;
	
	public int getArea() {
		return area;
	}

	public void setArea(int area) {
		this.area = area;
	}

	public int getBand() {
		return band;
	}

	public void setBand(int band) {
		this.band = band;
	}

	public boolean isSt() {
		return st;
	}

	public void setSt(boolean st) {
		this.st = st;
	}

	public boolean isLoc() {
		return loc;
	}

	public void setLoc(boolean loc) {
		this.loc = loc;
	}

	public boolean isSearch() {
		return search;
	}

	public void setSearch(boolean search) {
		this.search = search;
	}

	public boolean isScan() {
		return scan;
	}

	public void setScan(boolean scan) {
		this.scan = scan;
	}

	public boolean isStInd() {
		return stind;
	}

	public void setStInd(boolean stind) {
		this.stind = stind;
	}

	public int getFreq() {
		return freq;
	}

	public void setFreq(int freq) {
		this.freq = freq;
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
		parcel.writeInt(freq);
		parcel.writeInt(st?1:0);
		parcel.writeInt(loc?1:0);
		parcel.writeInt(search?1:0);
		parcel.writeInt(scan?1:0);
		parcel.writeInt(stind?1:0);
		parcel.writeInt(getArea());
		parcel.writeInt(isHasLegalFreq()?1:0);
		parcel.writeInt(getLegalFreq());
		
	}

	public static final Parcelable.Creator<RadioInfo> CREATOR = new Creator<RadioInfo>() {

		@Override
		public RadioInfo createFromParcel(Parcel source) {
			// TODO Auto-generated method stub
			//java端的解包必须和c++服务端的封包一致。
			RadioInfo radio = new RadioInfo();
			radio.setFreq(source.readInt());
			radio.setSt(source.readInt() == 1);
			radio.setLoc(source.readInt() == 1);
			radio.setSearch(source.readInt() == 1);
			radio.setScan(source.readInt() == 1);
			radio.setStInd(source.readInt() == 1);
			radio.setArea(source.readInt());
			radio.setHasLegalFreq(source.readInt()==1);
			radio.setLegalFreq(source.readInt());
			return radio;
		}

		@Override
		public RadioInfo[] newArray(int arg0) {
			// TODO Auto-generated method stub
			return new RadioInfo[arg0];
		} 
	};

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "RadioInfo:st="+st+",loc="+loc+",freq="+freq+",hasLegalFreq="+hasLegalFreq+",legalFreq="+legalFreq;
	}
	
	
}
