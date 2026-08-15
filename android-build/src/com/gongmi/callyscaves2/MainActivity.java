package com.gongmi.callyscaves2;

import android.app.Activity;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
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
    private final Rect gameRect = new Rect();

    // input
    private boolean moveLeft, moveRight, jump, attack, switchWeapon;
    private volatile int jumpPulse, attackPulse;
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
            Rect bounds = gameRect;
            int w = bounds.width();
            int hh = bounds.height();
            if (w <= 0 || hh <= 0) return true;
            moveLeft = moveRight = jump = attack = false;
            int lifted = ev.getActionMasked() == MotionEvent.ACTION_POINTER_UP
                    ? ev.getActionIndex() : -1;
            for (int i = 0; i < ev.getPointerCount(); i++) {
                if (i == lifted) continue;
                float x = ev.getX(i) - bounds.left;
                float y = ev.getY(i) - bounds.top;
                if (x < 0 || y < 0 || x >= w || y >= hh) continue;
                if (y > hh * 0.55f) {
                    if (x < w * 0.20f) moveLeft = true;
                    else if (x < w * 0.40f) moveRight = true;
                    else if (x > w * 0.80f) { attack = true; attackPulse = 4; }
                    else if (x > w * 0.60f) { jump = true; jumpPulse = 4; }
                } else if (y < hh * 0.20f) {
                    switchWeapon = true;
                }
            }
            if (ev.getActionMasked() == MotionEvent.ACTION_UP ||
                    ev.getActionMasked() == MotionEvent.ACTION_CANCEL) {
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
        copyAsset("game.droid", out, 1000);
        File textureDir = new File(getFilesDir(), "textures");
        if (!textureDir.exists() && !textureDir.mkdirs()) {
            throw new RuntimeException("Failed to create texture directory");
        }
        for (int i = 0; i < 4; i++) {
            copyAsset("textures/texture_" + i + ".png",
                    new File(textureDir, "texture_" + i + ".png"), 1000);
        }
        return out.getAbsolutePath();
    }

    private void copyAsset(String assetName, File out, long minimumLength) {
        if (out.exists() && out.length() > minimumLength) return;
        AssetManager am = getAssets();
        try (InputStream in = am.open(assetName);
             FileOutputStream fos = new FileOutputStream(out)) {
            byte[] buf = new byte[64 * 1024];
            int n;
            while ((n = in.read(buf)) > 0) {
                fos.write(buf, 0, n);
            }
        } catch (IOException e) {
            throw new RuntimeException("Failed to unpack " + assetName, e);
        }
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

                boolean jumpNow = jump || jumpPulse > 0;
                boolean attackNow = attack || attackPulse > 0;
                nativeInput(
                    moveLeft ? 1 : 0,
                    moveRight ? 1 : 0,
                    jumpNow ? 1 : 0,
                    attackNow ? 1 : 0,
                    switchWeapon ? 1 : 0,
                    weapon
                );
                if (jumpPulse > 0) jumpPulse--;
                if (attackPulse > 0) attackPulse--;
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
                        Rect clip = c.getClipBounds();
                        float scale = Math.min(
                                clip.width() / (float) framebuffer.getWidth(),
                                clip.height() / (float) framebuffer.getHeight());
                        int drawW = Math.max(1, Math.round(framebuffer.getWidth() * scale));
                        int drawH = Math.max(1, Math.round(framebuffer.getHeight() * scale));
                        int left = clip.left + (clip.width() - drawW) / 2;
                        int top = clip.top + (clip.height() - drawH) / 2;
                        gameRect.set(left, top, left + drawW, top + drawH);
                        Paint paint = new Paint();
                        paint.setFilterBitmap(false);
                        c.drawBitmap(framebuffer, null, gameRect, paint);
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
