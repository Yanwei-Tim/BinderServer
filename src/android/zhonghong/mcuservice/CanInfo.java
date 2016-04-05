package android.zhonghong.mcuservice;

import android.os.Parcel;

public class CanInfo {

	public static final int CANINFO_DOMAIN = 500;
	
	public static short[] toShortArray(byte[] arr)
	{
		if(arr == null || arr.length == 0) return null;
		
		short[] result = new short[arr.length];
		for(int i=0; i<arr.length; i++)
		{
			result[i] = Parser.toUnsigned(arr[i]);
		}
		return result;
	}
	
	public static short[] toShortArray(Parcel p)
	{
		if(p == null) return null;
		
		int len = p.readInt();
		byte[] result = new byte[len];
		p.readByteArray(result);
		return toShortArray(result);
	}
}

