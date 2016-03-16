package com.leo.mcuserver;


import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Binder;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.zhonghong.mcuservice.BTInfo;
import android.zhonghong.mcuservice.BTProxy;
import android.zhonghong.mcuservice.IMcuService;
import android.zhonghong.mcuservice.McuServerTest;
import android.zhonghong.mcuservice.RadioInfo;
import android.zhonghong.mcuservice.RadioProxy;
import android.zhonghong.mcuservice.SettingsInfo;
import android.zhonghong.mcuservice.SettingsProxy;
import android.zhonghong.mcuservice.RegistManager.IBTInfoChangedListener;
import android.zhonghong.mcuservice.RegistManager.IRadioInfoChangedListener;
import android.zhonghong.mcuservice.RegistManager.ISettingsInfoChangedListener;

public class RadioActivity extends Activity implements View.OnClickListener {

	
	protected static final String TAG = "leo";
	RadioProxy radioProxy = new RadioProxy();
	BTProxy btProxy = new BTProxy();
	SettingsProxy settingsProxy = new SettingsProxy();
	
	
	Button st, loc, search, scan, stind, setfreq, setband;
	Button leftSearch, rightSearch;
	EditText freq,band;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		freq = (EditText)this.findViewById(R.id.button5);
		st = (Button)this.findViewById(R.id.button6);
		loc = (Button)this.findViewById(R.id.button7);
		search = (Button)this.findViewById(R.id.button8);
		scan = (Button)this.findViewById(R.id.button9);
		stind = (Button)this.findViewById(R.id.button10);
		
		leftSearch = (Button)this.findViewById(R.id.button11);
		rightSearch = (Button)this.findViewById(R.id.button12);
		
		band = (EditText)this.findViewById(R.id.editText0);
		setband = (Button)this.findViewById(R.id.button13);
		setfreq = (Button)this.findViewById(R.id.button14);
		
		st.setOnClickListener(this);
		loc.setOnClickListener(this);
		search.setOnClickListener(this);
		scan.setOnClickListener(this);
		stind.setOnClickListener(this);
		rightSearch.setOnClickListener(this);
		leftSearch.setOnClickListener(this);
		setfreq.setOnClickListener(this);
		setband.setOnClickListener(this);
		
		
		this.findViewById(R.id.button1).setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				
				
				String temp = "com.zhonghong.start.txzrecognition";
				RadioActivity.this.sendBroadcast(new Intent(temp));
				// TODO Auto-generated method stub
//				McuServerTest.getInstance().test();
				radioProxy.registRadioInfoChangedListener(radio);
				//btProxy.registBTInfoChangedListener(bt);
				//settingsProxy.registSettingsInfoChangedListener(settings);
			}
		});
		this.findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
//				McuServerTest.getInstance().test();
				Log.i(TAG, " before data = "+ (new SimpleDateFormat("SSS")).format(new Date()));
				Log.i(TAG, " obtain info st = "+ radioProxy.getST());
				Log.i(TAG, " end data = "+ (new SimpleDateFormat("SSS")).format(new Date()));
				Log.i(TAG, " obtain info loc = "+ radioProxy.getLOC());
				Log.i(TAG, " obtain info freq = "+ radioProxy.getFreq());
			}
		});
		
		
		this.findViewById(R.id.button3).setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
//				Log.i(TAG, " set  loc  true result="+radioProxy.setST());
//				Log.i(TAG, " set  st true result="+radioProxy.setLOC());
				Log.i(TAG, " set freq  8750 result="+radioProxy.setFreq(0,8950));
			}
		});
		
		this.findViewById(R.id.button4).setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
//				McuServerTest.getInstance().test();
				Log.i(TAG, " obtain radioinfo "+radioProxy.getRadioInfo());
				Log.i(TAG, " obtain btinfo "+btProxy.getBTInfo());
				Log.i(TAG, " obtain settingsProxy "+settingsProxy.getSettingsInfo());
				Intent intent = new Intent(RadioActivity.this, SettingsActivity.class);
				RadioActivity.this.startActivity(intent);
			}
		});
		
		this.findViewById(R.id.button15).setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				radioProxy.unregistRadioInfoChangedListener(radio);
			}
		});
		
		test();
	}
	
	Handler handler = new Handler()
	{

		@Override
		public void handleMessage(Message msg) {
			// TODO Auto-generated method stub
			super.handleMessage(msg);
			
			switch(msg.what)
			{
			case 0:
				RadioInfo radio = (RadioInfo)(msg.obj);
				initRadioInfo(radio);
				break;
			}
		}
	};
	
	void initRadioInfo(RadioInfo radio)
	{
		freq.setText("freq("+radio.getFreq()+")");
		st.setText("st("+radio.isSt()+")");
		loc.setText("loc("+radio.isLoc()+")");
		search.setText("search("+radio.isSearch()+")");
		scan.setText("scan("+radio.isScan()+")");
		stind.setText("stind("+radio.isStInd()+")");
		band.setText(radio.getBand()+"");
	}
	
	IRadioInfoChangedListener radio = new IRadioInfoChangedListener()
	{
		@Override
		public void notify(int[] changeCMDs, RadioInfo radio) {
			// TODO Auto-generated method stub
			Log.i("leo", radio.toString());
			handler.sendMessage(handler.obtainMessage(0, radio));
		}
	};
	
	ISettingsInfoChangedListener settings = new ISettingsInfoChangedListener()
	{
		@Override
		public void notify(int[] changeCMDs, SettingsInfo settings) {
			// TODO Auto-generated method stub
			Log.i("leo", settings.toString());
		}
	};
	
	IBTInfoChangedListener bt = new IBTInfoChangedListener()
	{
		@Override
		public void notify(int[] changeCMDs, BTInfo btinfo) {
			// TODO Auto-generated method stub
			Log.i("leo", btinfo.toString());
		}
	};

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	@Override
	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		
		switch(arg0.getId())
		{
		case R.id.button6:
			radioProxy.setST();
			break;
		case R.id.button7:
			radioProxy.setLOC();
			break;
		case R.id.button8:
			radioProxy.setSearch();
			break;
		case R.id.button9:
			radioProxy.setScan();
			break;
		case R.id.button10:
			break;
		case R.id.button11:
			radioProxy.setSearchLeft();
			break;
		case R.id.button12:
			radioProxy.setSearchRight();
			break;
		case R.id.button13:
			//set band
			int b = Integer.parseInt(band.getText().toString());
			//radioProxy.setBand(b);
			break;
		case R.id.button14:
			//set freq
			int f = Integer.parseInt(freq.getText().toString());
			radioProxy.setFreq(1, f);
			break;
		}
	}
	
	public void test()
	{
		final TelephonyManager tm = (TelephonyManager) getBaseContext().getSystemService(Context.TELEPHONY_SERVICE);

	    final String tmDevice, tmSerial, androidId;
	    tmDevice = "" + tm.getDeviceId();
	    tmSerial = "" + tm.getSimSerialNumber();
	    androidId = "" + android.provider.Settings.Secure.getString(getContentResolver(), android.provider.Settings.Secure.ANDROID_ID);
	    Log.i(TAG, "tmDevice="+tmDevice);
	    Log.i(TAG, "tmSerial="+tmSerial);
	    Log.i(TAG, "androidId="+androidId);
	}
	
}
