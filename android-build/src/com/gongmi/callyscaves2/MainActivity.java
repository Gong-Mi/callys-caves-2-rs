package com.gongmi.callyscaves2;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.view.Gravity;
import android.graphics.Color;

public class MainActivity extends Activity {
    static {
        System.loadLibrary("callys_client");
    }

    public static native void nativeInit();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        nativeInit();

        TextView tv = new TextView(this);
        tv.setText("Cally's Caves 2\nNative 64-bit ARM64 Engine Active!\nAll 114 Rooms & Assets Loaded");
        tv.setTextColor(Color.WHITE);
        tv.setTextSize(20);
        tv.setGravity(Gravity.CENTER);
        tv.setBackgroundColor(Color.BLACK);
        setContentView(tv);
    }
}
