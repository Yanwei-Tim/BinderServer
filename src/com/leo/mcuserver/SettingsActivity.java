package com.leo.mcuserver;


import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import android.app.Activity;
import android.content.ComponentName;
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
import android.widget.SeekBar;
import android.widget.TextView;
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

public class SettingsActivity extends Activity implements View.OnClickListener, SeekBar.OnSeekBarChangeListener {

	
	protected static final String TAG = "leo";
	RadioProxy radioProxy = new RadioProxy();
	BTProxy btProxy = new BTProxy();
	SettingsProxy settingsProxy = new SettingsProxy();
	
	
	SeekBar vol, defvol, btvol, gpsvol, fade, bal, treb, mid, bass;
	TextView vol_t, defvol_t, btvol_t, gpsvol_t, fade_t, bal_t, treb_t, mid_t, bass_t;
	
	Button mute, audiomode, regist;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.settings);
	
		vol = (SeekBar)this.findViewById(R.id.vol);
		defvol = (SeekBar)this.findViewById(R.id.defvol);
		btvol = (SeekBar)this.findViewById(R.id.btvol);
		gpsvol = (SeekBar)this.findViewById(R.id.gpsvol);
		fade = (SeekBar)this.findViewById(R.id.fade);
		bal = (SeekBar)this.findViewById(R.id.bal);
		treb = (SeekBar)this.findViewById(R.id.treb);
		mid = (SeekBar)this.findViewById(R.id.mid);
		bass = (SeekBar)this.findViewById(R.id.bass);
		
		vol.setOnSeekBarChangeListener(this);
		defvol.setOnSeekBarChangeListener(this);
		btvol.setOnSeekBarChangeListener(this);
		gpsvol.setOnSeekBarChangeListener(this);
		fade.setOnSeekBarChangeListener(this);
		bal.setOnSeekBarChangeListener(this);
		treb.setOnSeekBarChangeListener(this);
		mid.setOnSeekBarChangeListener(this);
		bass.setOnSeekBarChangeListener(this);
		
		vol_t = (TextView)this.findViewById(R.id.vol_t);
		defvol_t = (TextView)this.findViewById(R.id.defvol_t);
		btvol_t = (TextView)this.findViewById(R.id.btvol_t);
		gpsvol_t = (TextView)this.findViewById(R.id.gpsvol_t);
		fade_t = (TextView)this.findViewById(R.id.fade_t);
		bal_t = (TextView)this.findViewById(R.id.bal_t);
		treb_t = (TextView)this.findViewById(R.id.treb_t);
		mid_t = (TextView)this.findViewById(R.id.mid_t);
		bass_t = (TextView)this.findViewById(R.id.bass_t);
		
		mute = (Button)this.findViewById(R.id.mute);
		((Button)this.findViewById(R.id.radio)).setOnClickListener(this);
		((Button)this.findViewById(R.id.unregist)).setOnClickListener(this);
		audiomode = (Button)this.findViewById(R.id.audiomode);
		regist = (Button)this.findViewById(R.id.regist);
		regist.setOnClickListener(this);
		mute.setOnClickListener(this);
		audiomode.setOnClickListener(this);
		
		SettingsInfo s = settingsProxy.getSettingsInfo();
		handler.sendMessage(handler.obtainMessage(0, s));
		
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
				SettingsInfo radio = (SettingsInfo)(msg.obj);
				initSettingsInfo(radio);
				break;
			}
		}
	};
	
	void initSettingsInfo(SettingsInfo settings)
	{
		vol.setProgress(settings.getVol());
		vol_t.setText(settings.getVol()+"");
		
		defvol.setProgress(settings.getDefVol());
		defvol_t.setText(settings.getDefVol()+"");
		
		btvol.setProgress(settings.getBtVol());
		btvol_t.setText(settings.getBtVol()+"");
		
		gpsvol.setProgress(settings.getGpsVol());
		gpsvol_t.setText(settings.getGpsVol()+"");
		
		fade.setProgress(settings.getFade());
		fade_t.setText(settings.getFade()+"");
		
		bal.setProgress(settings.getBal());
		bal_t.setText(settings.getBal()+"");
		
		treb.setProgress(settings.getTreb());
		treb_t.setText(settings.getTreb()+"");
		
		mid.setProgress(settings.getMid());
		mid_t.setText(settings.getMid()+"");
		
		bass.setProgress(settings.getBass());
		bass_t.setText(settings.getBass()+"");
		
		mute.setText("mute:"+settings.isbMute());
		audiomode.setText("audiomode:"+settings.getAudiomode());
	
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
			handler.sendMessage(handler.obtainMessage(0, settings));
		}
	};
	ISettingsInfoChangedListener settings2 = new ISettingsInfoChangedListener()
	{
		@Override
		public void notify(int[] changeCMDs, SettingsInfo settings) {
			// TODO Auto-generated method stub
			Log.i("leo", settings.toString());
			handler.sendMessage(handler.obtainMessage(0, settings));
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
		case R.id.regist:
			settingsProxy.registSettingsInfoChangedListener(settings);
			
			settingsProxy.registSettingsInfoChangedListener(settings2);
			break;
		case R.id.mute:
			String m[] = mute.getText().toString().split(":");
			boolean bm = Boolean.parseBoolean(m[1]);
			settingsProxy.setMute(!bm);
			break;
		case R.id.audiomode:
			String t[] = audiomode.getText().toString().split(":");
			int mode = Integer.parseInt(t[1]);
			mode ++;
			if(mode > 7)
			{
				mode = 0;
			}
			settingsProxy.setAudioMode(mode);
			break;
		case R.id.radio:
			Intent intent = new Intent(Intent.ACTION_MAIN);
			intent.setComponent(new ComponentName("com.zhonghong.mcuserver", "com.zhonghong.mcuserver.SettingsActivity"));
			intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			this.startActivity(intent);
			Log.i(TAG, "start settings.........");
			break;
		case R.id.unregist:
			settingsProxy.unregistSettingsInfoChangedListener(settings);
			settingsProxy.unregistSettingsInfoChangedListener(settings2);
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

	@Override
	public void onProgressChanged(SeekBar arg0, int arg1, boolean arg2) {
		// TODO Auto-generated method stub
		if(arg2)
		{
			int p = arg0.getProgress();
			switch(arg0.getId())
			{
			case R.id.fade:
				settingsProxy.setFade(p);
				break;
			case R.id.bal:
				settingsProxy.setBal(p);
				break;
			case R.id.treb:
				settingsProxy.setTreb(p);
				break;
			case R.id.mid:
				settingsProxy.setMid(p);
				break;
			case R.id.bass:
				settingsProxy.setBass(p);
				break;
			case R.id.vol:
				settingsProxy.setVol(p);
				break;
			case R.id.defvol:
				settingsProxy.setDefVol(p);
				break;
			case R.id.btvol:
				settingsProxy.setBTVol(p);
				break;
			case R.id.gpsvol:
				settingsProxy.setGPSVol(p);
				break;
			}
		}
	}

	@Override
	public void onStartTrackingTouch(SeekBar arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onStopTrackingTouch(SeekBar arg0) {
		// TODO Auto-generated method stub
		
	}
	
}
