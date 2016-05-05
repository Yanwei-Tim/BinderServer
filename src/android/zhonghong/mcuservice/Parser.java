package android.zhonghong.mcuservice;

import android.os.Handler;
import android.util.Log;

/**
 * Pauser类用于：<br>
 * 1、分析can发送过来的数据包<br>
 * 2、封装数据包发送给can
 * 
 * @author leo
 * @version V3.0
 */
public abstract class Parser {
	
	/**
	 * 解析数据�Dbr>
	 * <font color="red">该函数式虚函数，必须继承该函�D/font>
	 * 
	 * @param buff can发�D过来的buff，注意：buff.length = 128
	 * @param len can发�D过来的buff的实际长�D
	 */
	abstract public void parsePacket(byte[] buff, int len);
	
	/**
	 * 组装数据�Dbr>
	 * <font color="red">该函数式虚函数，必须继承该函�D/font>
	 * 
	 * @param cmd 自定义的cmd，根据cmd封装成不同的数据包�D
	 * @param b0 封装到数据包里面的数据�D
	 * @param b1 封装到数据包里面的数据�D
	 * @param b2 封装到数据包里面的数据�D
	 * @param b3 封装到数据包里面的数据�D
	 */
	abstract public byte[] encapsulatePacket(int cmd, byte b0, byte b1, byte b2, byte b3);
	
	private static byte SENDONCE = (byte)0xC0;
	private static byte SENDLOOP = (byte)0xC1;
	protected Handler parserHandler = null;
	void setHandler(Handler h) {
		// TODO Auto-generated method stub
		parserHandler = h;
	}
	public static final short BIT0 = 1;
	public static final short BIT1 = 2;
	public static final short BIT2 = 4;
	public static final short BIT3 = 8;
	public static final short BIT4 = 16;
	public static final short BIT5 = 32;
	public static final short BIT6 = 64;
	public static final short BIT7 = 128;
	
	/**
	 * 将can传过来的byte转换成java的byte�Dbr>
	 * can的byte�D��是无符号的，范围�D~255<br>
	 * java的byte是有符号的，范围�D128~127.
	 * 
	 * @parma bit �D��转换的byte
	 */
	public static short toUnsigned(byte b)
	{
		return (short)(b&0xff);
	}
	
	/**
	 * 把byte中的某一位转�D��boolean
	 * 
	 * @param b �D��的byte
	 * @param bit �D��获取的第几位，如BIT4则传4，BIT0则传0
	 */
	public static boolean getBooleanByBit(byte b, int bit)
	{
		if(bit > 7
			||bit <0)
		{
			Log.i("liujg", "getBooleanByBit():parameter error!!");
			return false;
		}
		short bb = toUnsigned(b);
		
		return (((bb>>bit)&1)==0?false:true);
	}
	
	/**
	 * 获取byte中连续几个bit位的int�D
	 * 
	 * @param b �D��的byte
	 * @parma bit �D��获取�D��位是第几位，如BIT5和BIT4则传4，BIT0、BIT1和BIT2则传0
	 * @param len 是需要获取几位的值，BIT5和BIT4则传2，BIT0、BIT1和BIT2则传3
	 */
	public int getIntByBits(byte b, int bit, int len)
	{
		if(bit > 7||len > 8)
		{
			Log.i("liujg", "getIntByBits():param error!!!!!!!!!!!!");
			return 0;
		}
		short bb = ((short)(b&0xff));
		return ((bb>>bit)&((int)(Math.pow(2, len)-1)));
	}
	
	/**
	 * 重载函数<br>
	 * �D��can数据包的�D��和是否正�D
	 * 
	 * @param b �D��的byte
	 * @parma start_index �D���D
	 * @param len �D��几位的和来检查校验和
	 * @param checksum_index �D��和在第几�D
	 * 
	 */
	public static boolean isLegalCheckSumByLen(byte[] b, int start_index, int len, int checksum_index)
	{
		if(start_index < 0
				|| start_index+len>=b.length
				||checksum_index>=b.length)
		{
			Log.i("liujg","isLegalCheckSumByIndex():param is error!!!!!!!!!!!!!");
			return false;
		}
		int sum = 0;
		for(int ii=start_index; ii<start_index+len; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		if(((sum&255)^255) == toUnsigned(b[checksum_index]))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	/**
	 * 重载函数<br>
	 * �D��can数据包的�D��和是否正�D
	 * 
	 * @param b �D��的byte
	 * @parma start_index �D��位�D
	 * @param end_index 结束�D
	 * @param checksum_index �D��和在第几�D
	 */
	public static boolean isLegalCheckSumByIndex(byte[] b, int start_index, int end_index, int checksum_index)
	{
		if(start_index < 0
				|| end_index>=b.length
				||checksum_index>=b.length)
		{
			Log.i("liujg","isLegalCheckSumByIndex():param is error!!!!!!!!!!!!!");
			return false;
		}
		int sum = 0;
		for(int ii=start_index; ii<=end_index; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		if(((sum&255)^255) == toUnsigned(b[checksum_index]))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	/**
	 * 获取can数据包的�D���Dbr>
	 * 用于封装数据包发生给can
	 * 
	 * @param b �D��的byte
	 * @parma int start_index�D��位�D
	 * @param int end_index结束�D
	 * 
	 */
	public static byte getCheckSumByIndex(byte[] b, int start_index, int end_index)
	{
		if(start_index < 0
				|| end_index>=b.length)
		{
			Log.i("liujg","getCheckSumByIndex():param is error!!!!!!!!!!!!!");
			return 0;
		}
		int sum = 0;
		for(int ii=start_index; ii<=end_index; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		
		return (byte)((sum&255)^255);
	}
	
	/**
	 * 重载函数<br>
	 * 获取can数据包的�D���Dbr>
	 * 用于封装数据包发生给can
	 * 
	 * @param b �D��的byte
	 * @parma start_index �D���D
	 * @param len �D���D��多少位和来计算校验和
	 */
	public static byte getCheckSumByLen(byte[] b, int start_index, int len)
	{
		if(start_index < 0
				|| start_index+len>=b.length)
		{
			Log.i("liujg","getCheckSumByLen():param is error!!!!!!!!!!!!!");
			return 0;
		}
		int sum = 0;
		for(int ii=start_index; ii<start_index+len; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		return (byte)((sum&255)^255);
	}
	
	/**
	 * 获取can数据包的�D���Dbr>
	 * 用于封装数据包发生给can
	 * 
	 * @param b �D��的byte
	 * @parma start_index �D���D
	 * @param len �D���D��多少位和来计算校验和
	 * @param check_index �D��和放在哪�D��
	 */
	public static byte[] completeCheckSum(byte[] b, int start_index, int len, int checksum_index)
	{
		if(start_index < 0
				|| start_index+len>=b.length
				||checksum_index<0
				||checksum_index>=b.length)
		{
			Log.i("liujg","completeCheckSum():param is error!!!!!!!!!!!!!");
			return null;
		}
		int sum = 0;
		for(int ii=start_index; ii<start_index+len; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		b[checksum_index] =  (byte)((sum&255)^255);
		return b;
	}
	
	/**
	 * 获取can数据包的�D���Dbr>
	 * 用于封装数据包发生给can
	 * 
	 * @param b �D��的byte
	 * @parma start_index �D��位�D
	 * @param len �D���D��多少位和来计算校验和
	 * 
	 */
	public static byte[] completeCheckSum(byte[] b, int start_index, int len)
	{
		if(start_index < 0
				|| start_index+len>=b.length)
		{
			Log.i("liujg","completeCheckSum():param is error!!!!!!!!!!!!!");
			return null;
		}
		int sum = 0;
		for(int ii=start_index; ii<start_index+len; ii++)
        {
        	sum+=toUnsigned(b[ii]);
        }
		b[b.length-1] =  (byte)((sum&255)^255);
		return b;
	}
	
	/**
	 * 获取mcu发�D�D��数据包给can
	 * 
	 * @param canPacket can的数据包 
	 * 
	 */
	public static byte[] getSendOncePacket(byte[] canPacket)
	{
		if(canPacket == null
				||canPacket.length == 0)
		{
			Log.i("liujg","getSendOncePacket():param is error!!!!!!!!!!!!!");
			return null;
		}
		byte[] b = new byte[canPacket.length+6];
		b[0] = (byte)0xFF;
		b[1] = (byte)0xAA;
		b[2] = SENDONCE;
		b[3] = (byte)(canPacket.length+6);
		b[4] = 0;
		for(int ii=0; ii<canPacket.length; ii++)
        {
        	b[5+ii] = canPacket[ii];
        }
		b[b.length-1] = (byte)0x0A;
		return b;
	}
	
	/**
	 * 获取循环发给can的数据包<br>
	 * app发�D�D��给mcu，mcu会记住这个包，每隔一定时间循环发送�D
	 * 
	 * @param canPacket:can 的数据包
	 * 
	 */
	public static byte[] getSendLoopPacket(byte[] canPacket, int millsec)
	{
		if(canPacket == null
				||canPacket.length == 0)
		{
			Log.i("liujg","getSendOncePacket():param is error!!!!!!!!!!!!!");
			return null;
		}
		byte[] b = new byte[canPacket.length+7];
		b[0] = (byte)0xFF;
		b[1] = (byte)0xAA;
		b[2] = SENDLOOP;
		b[3] = (byte)(canPacket.length+7);
		b[4] = 0;
		b[5] = (byte)millsec;
		for(int ii=0; ii<canPacket.length; ii++)
        {
        	b[6+ii] = canPacket[ii];
        }
		b[b.length-1] = (byte)0x0A;
		return b;
	}
	
	/**
	 * 获取cancle循环发给can的数据包<br>
	 * app发�D�D��给mcu，mcu会记住这个包，每隔一定时间循环发送�D
	 * 
	 * @param canPacket can 的数据包
	 * 
	 */
	public static byte[] getCancleLoopPacket(byte[] canPacket)
	{
		if(canPacket == null
				||canPacket.length == 0)
		{
			Log.i("liujg","getCancleLoopPacket():param is error!!!!!!!!!!!!!");
			return null;
		}
		byte[] b = new byte[canPacket.length+7];
		b[0] = (byte)0xFF;
		b[1] = (byte)0xAA;
		b[2] = SENDLOOP;
		b[3] = (byte)(canPacket.length+7);
		b[4] = 0;
		b[5] = 0;
		for(int ii=0; ii<canPacket.length; ii++)
        {
        	b[6+ii] = canPacket[ii];
        }
		b[b.length-1] = (byte)0x0A;
		return b;
	}
}

