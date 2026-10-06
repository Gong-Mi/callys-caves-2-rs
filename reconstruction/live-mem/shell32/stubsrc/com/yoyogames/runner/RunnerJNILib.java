package com.yoyogames.runner;

// Compile-time-only stub. NOT shipped in the runtime dex: the real class
// comes from the original classes.dex on the classpath, and libyoyo's
// JNI_OnLoad RegisterNatives binds against it.
// Keep every declared member signature identical to the real class.

import android.content.Context;

public class RunnerJNILib {
    public static Context ms_context;
    public static boolean ms_exitcalled = false;
    public static String ms_versionName;

    public static native void SetKeyValue(int key, int value, String strValue);
    public static native void RenderSplash(String apkPath, String splashPath,
            int w, int h, int texRawW, int texRawH, int texW, int texH);
    public static native void Startup(String apkFilePath, String saveFilesDir,
            String packageName, int sleepMargin);
    public static native int Process(int width, int height,
            float accelX, float accelY, float accelZ,
            int keypadStatus, int orientation, float refreshRate);
    public static native boolean canFlip();
    public static native void Pause(int unused);
    public static native void Resume(int unused);
    public static native void TouchEvent(int action, int id, float x, float y);
    public static native void KeyEvent(int type, int keyCode);
    public static native void ExitApplication();
}
