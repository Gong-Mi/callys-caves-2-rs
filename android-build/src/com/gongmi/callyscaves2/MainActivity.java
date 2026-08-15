package com.gongmi.callyscaves2;

import android.app.Activity;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends Activity {
    private static final String TAG = "CallysJava";
    static {
        try {
            System.loadLibrary("callys_client");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "loadLibrary(callys_client) failed", e);
            throw e;
        } catch (Throwable t) {
            Log.e(TAG, "loadLibrary(callys_client) crashed", t);
            throw t;
        }
    }

    private native void nativeInit(String assetPath);
    private native void nativeResize(int width, int height);
    private native void nativeStep(int dtMs);
    private native void nativeInput(int moveLeft, int moveRight, int jump,
                                    int attack, int switchWeapon, int weapon);
    private native int  nativeGetWidth();
    private native int  nativeGetHeight();
    private native void nativeBlitToIntArray(int[] pixels);

    private SurfaceView surface;
    private Bitmap framebuffer;
    private int[] pixelBuffer;
    private Thread renderThread;
    private volatile boolean running;

    // input
    private boolean moveLeft, moveRight, jump, attack, switchWeapon;
    private int weapon = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(TAG, "onCreate start");
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        surface = new SurfaceView(this);
        setContentView(surface);

        surface.getHolder().addCallback(new SurfaceLifecycle());

        surface.setOnTouchListener((v, ev) -> {
            float x = ev.getX();
            float y = ev.getY();
            int w = v.getWidth();
            int hh = v.getHeight();
            if (y > hh * 0.55f) {
                if (x < w * 0.30f) moveLeft = true;
                if (x > w * 0.70f) moveRight = true;
                if (y < hh * 0.75f) jump = true;
            } else {
                if (x > w * 0.60f && y < hh * 0.45f) attack = true;
                if (y < hh * 0.20f) switchWeapon = true;
            }
            if (ev.getAction() == MotionEvent.ACTION_UP) {
                moveLeft = moveRight = jump = attack = false;
            }
            return true;
        });
    }

    private final class SurfaceLifecycle implements SurfaceHolder.Callback {
        @Override
        public void surfaceCreated(SurfaceHolder holder) {
            startEngine();
        }
        @Override
        public void surfaceChanged(SurfaceHolder holder, int fmt, int w, int hgt) {
            // Keep the engine's logical framebuffer at 960x540. The
            // Canvas scales it to the physical Surface dimensions.
            // Do not call nativeResize(w,hgt): that would resize the
            // Rust buffer while the Java Bitmap/int[] still has the
            // old dimensions and would make JNI blit lengths diverge.
        }
        @Override
        public void surfaceDestroyed(SurfaceHolder holder) {
            stopEngine();
        }
    }

    /** Copy `assets/game.droid` from the APK onto the device so
     *  the Rust engine can mmap it. */
    private String prepareGameDroid() {
        File out = new File(getFilesDir(), "game.droid");
        if (out.exists() && out.length() > 1000) {
            return out.getAbsolutePath();
        }
        AssetManager am = getAssets();
        try (InputStream in = am.open("game.droid");
             FileOutputStream fos = new FileOutputStream(out)) {
            byte[] buf = new byte[64 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                fos.write(buf, 0, n);
            }
        } catch (IOException e) {
            throw new RuntimeException("Failed to unpack game.droid", e);
        }
        return out.getAbsolutePath();
    }

    private void startEngine() {
        if (running) {
            return;
        }
        String assetPath = prepareGameDroid();
        nativeInit(assetPath);

        int w = nativeGetWidth();
        int h = nativeGetHeight();
        if (w == 0 || h == 0) {
            w = surface.getWidth();
            h = surface.getHeight();
            nativeResize(w, h);
        }
        framebuffer = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888);
        pixelBuffer = new int[w * h];

        running = true;
        renderThread = new Thread(new RenderLoop(), "CallysRenderThread");
        renderThread.start();
    }

    private final class RenderLoop implements Runnable {
        @Override
        public void run() {
            long last = System.nanoTime();
            while (running) {
                long now = System.nanoTime();
                int dt = (int) ((now - last) / 1_000_000L);
                if (dt > 50) dt = 50;
                last = now;

                nativeInput(
                    moveLeft ? 1 : 0,
                    moveRight ? 1 : 0,
                    jump ? 1 : 0,
                    attack ? 1 : 0,
                    switchWeapon ? 1 : 0,
                    weapon
                );
                switchWeapon = false;
                nativeStep(dt);
                nativeBlitToIntArray(pixelBuffer);
                framebuffer.setPixels(pixelBuffer, 0, framebuffer.getWidth(), 0, 0,
                                       framebuffer.getWidth(), framebuffer.getHeight());

                SurfaceHolder holder = surface.getHolder();
                Canvas c = holder.lockCanvas();
                if (c != null) {
                    try {
                        c.drawColor(Color.BLACK);
                        c.drawBitmap(framebuffer, null, c.getClipBounds(), new Paint());
                    } finally {
                        holder.unlockCanvasAndPost(c);
                    }
                }
            }
        }
    }

    private void stopEngine() {
        running = false;
        if (renderThread != null) {
            try {
                renderThread.join(500);
            } catch (InterruptedException ignored) {
            }
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        stopEngine();
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (renderThread == null || !renderThread.isAlive()) {
            startEngine();
        }
    }
}
