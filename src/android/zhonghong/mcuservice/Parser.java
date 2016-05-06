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
	 * 解析数据包<br>
	 * <font color="red">该函数式虚函数，必须继承该函数</font>
	 * 
	 * @param buff can发送过来的buff，注意：buff.length = 128，但是实际长度不是这个
	 * @param len can发送过来的buff的实际长度
	 */
	abstract public void parsePacket(byte[] buff, int len);
	
	/**
	 * 组装数据包<br>
	 * <font color="red">该函数式虚函数，必须继承该函数</font>
	 * 
	 * @param cmd 自定义的cmd，根据cmd封装成不同的数据包
	 * @param b0 封装到数据包里面的数据包
	 * @param b1 封装到数据包里面的数据包
	 * @param b2 封装到数据包里面的数据包
	 * @param b3 封装到数据包里面的数据包
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
	 * 将can传过来的byte转换成java的byte<br>
	 * can的byte是无符号的，是c++那边发送过来的，范围是0~255<br>
	 * java的byte是有符号的，范围是-128~127.
	 * 
	 * @parma b 需要转换的byte
	 */
	public static short toUnsigned(byte b)
	{
		return (short)(b&0xff);
	}
	
	/**
	 * 把byte中的某一位转换成boolean， 等于0是FALSE，非零就是true
	 * 
	 * @param b 需要转换的byte
	 * @param bit 获取的第几位，如BIT4则传4，BIT0则传0
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
	 * 获取byte中连续几个bit位的int值
	 * 
	 * @param b 需要转换的byte
	 * @parma bit 开始获取位是第几位，如BIT5和BIT4则传4（开始位是4），BIT0、BIT1和BIT2则传0（开始位是0）
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
	 * 检查数据包的校验和是否正确
	 * 
	 * @param b 需要检查的byte
	 * @parma start_index 起始位
	 * @param len 需要用几位的和来检查校验和
	 * @param checksum_index 校验和在第几位
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
	 * 检查can数据包的校验和是否正确
	 * 
	 * @param b 需要检查的byte
	 * @parma start_index 起始位
	 * @param end_index 结束位
	 * @param checksum_index checksum在第几位。
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
	 * 获取can数据包的checksun<br>
	 * 用于封装数据包发生给can
	 * 
	 * @param b 需要的byte
	 * @parma int start_index 起始位
	 * @param int end_index结束位
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
	 * 获取can数据包的checksum<br>
	 * 用于封装数据包发生给can
	 * 
	 * @param b 需要的byte
	 * @parma start_index 起始位
	 * @param len 需要多少位和来计算校验和
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
	 * 获取can数据包的checksum<br>
	 * 用于封装数据包发生给can
	 * 
	 * @param b 需要用到的的byte
	 * @parma start_index 起始位
	 * @param len 需要多少位和来计算校验和
	 * @param check_index checksum要放在哪一位
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
	 * 获取can数据包的checksum<br>
	 * 用于封装数据包发生给can
	 * 
	 * @param b byte
	 * @parma start_index 起始位
	 * @param len 需要多少位和来计算校验和
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
	 * 获取mcu发送的数据包给can
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
	 * app发送给mcu，mcu会记住这个包，每隔一定时间循环发送
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
	 * 获取循环发给can的数据包<br>
	 * app发送给mcu，mcu会记住这个包，每隔一定时间循环发送
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

