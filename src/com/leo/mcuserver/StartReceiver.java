package com.leo.mcuserver;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;


public class StartReceiver extends BroadcastReceiver {

    private String TAG = "StartReceiver";

    @Override
    public void onReceive(final Context context, Intent intent) {
        Log.e(TAG, "onReceive - " + intent.getAction());
        String action = intent.getAction();
        if("com.zhonghong.start.txzrecognition".equals(action))
        {
        	//TXZAsrManager.getInstance().triggerRecordButton();
        }
    }
}
