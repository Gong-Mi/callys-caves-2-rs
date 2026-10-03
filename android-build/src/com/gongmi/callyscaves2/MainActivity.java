package com.gongmi.callyscaves2;

import android.app.Activity;
import android.content.res.AssetManager;
import android.graphics.Rect;
import android.media.AudioAttributes;
import android.media.MediaPlayer;
import android.media.SoundPool;
import android.content.res.AssetFileDescriptor;
import android.os.Bundle;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.os.VibratorManager;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

public class MainActivity extends Activity {
    private static final String TAG = "CallysJava";
    // All 29 embedded wav SOND ids (identity permutation of AUDO 0..28); the
    // original runner preloads every embedded sound (SOND flags preload bit).
    private static final int[] REQUIRED_AUDIO_IDS = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    };
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
    // Full monotonic ns sample; native clock schedules ROOM-speed logic ticks.
    private native void nativeStep(long monotonicNs);
    private native void nativeSetClockPaused(boolean paused);
    private native void nativeInput(int moveLeft, int moveRight, int jump,
                                    int attack, int switchWeapon, int sword,
                                    int tap);
    private native void nativePointerRelease(float x, float y);
    private native int  nativeGetWidth();
    private native int  nativeGetHeight();
    private native void nativeBlitToIntArray(int[] pixels);
    private native int nativePollSound();
    private native int nativePollHaptic();

    private SurfaceView surface;
    private int[] pixelBuffer;
    private Thread renderThread;
    private volatile boolean running;
    private final GlesPresenter gles = new GlesPresenter();
    private final Rect gameRect = new Rect();
    private SoundPool soundPool;
    private Vibrator vibrator;
    private final Map<Integer, Integer> soundSamples = new ConcurrentHashMap<>();
    private final Set<Integer> loadedSamples = ConcurrentHashMap.newKeySet();

    // input
    private boolean moveLeft, moveRight, jump, attack, sword, switchWeapon;
    private volatile int jumpPulse, attackPulse, swordPulse, tapPulse;
    private final PointerReleaseQueue pointerReleases = new PointerReleaseQueue();
    private static final float LOGICAL_WIDTH = InputViewport.WIDTH;
    private static final float LOGICAL_HEIGHT = InputViewport.HEIGHT;

    private int logicalButton(float x, float y) {
        // Map 1136x640 logical screen coordinates to on-screen touch buttons.
        // View 0 (448x252, 2.5357x/2.5397x zoom) — the branch CODE 538 takes
        // at 1136x640, i.e. the original's real-device selection. Button
        // anchors on this canvas: left (vx-10, vy+190), right (vx+88,
        // vy+190), jump (vx+380, vy+190), shoot (vx+315, vy+190), sword
        // (vx+380, vy+125); the bands below are the same partitions the
        // view6 layout used, rescaled around those anchors.
        if (y >= 444.0f) {
            if (x < 225.0f) return 1;                  // left
            if (x >= 225.0f && x < 466.0f) return 2;   // right
            if (x >= 760.0f && x < 956.0f) return 4;   // shoot
            if (x >= 956.0f) return 3;                 // jump
        } else if (y >= 279.0f && y < 444.0f) {
            if (x >= 913.0f) return 5;                 // sword
        }
        return 0;
    }

    private void vibrateTouch(int button) {
        Vibrator v = vibrator;
        if (v == null || !v.hasVibrator() || button == 0) return;
        long duration = button == 1 || button == 2 ? 8L : 12L;
        int amplitude = button == 1 || button == 2 ? 70 : 110;
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                v.vibrate(VibrationEffect.createOneShot(duration, amplitude));
            } else {
                v.vibrate(duration);
            }
        } catch (RuntimeException e) {
            Log.w(TAG, "touch vibration failed", e);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(TAG, "onCreate start");
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            VibratorManager manager = (VibratorManager) getSystemService(VIBRATOR_MANAGER_SERVICE);
            vibrator = manager == null ? null : manager.getDefaultVibrator();
        } else {
            vibrator = (Vibrator) getSystemService(VIBRATOR_SERVICE);
        }

        surface = new SurfaceView(this);
        setContentView(surface);

        surface.getHolder().addCallback(new SurfaceLifecycle());

        surface.setOnTouchListener((v, ev) -> {
            Rect bounds = gameRect;
            int w = bounds.width();
            int hh = bounds.height();
            if (w <= 0 || hh <= 0) return true;
            moveLeft = moveRight = jump = attack = sword = false;
            int action = ev.getActionMasked();
            if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_DOWN) {
                int index = ev.getActionIndex();
                float logicalX = InputViewport.x(ev.getX(index) - bounds.left, w);
                float logicalY = InputViewport.y(ev.getY(index) - bounds.top, hh);
                vibrateTouch(logicalButton(logicalX, logicalY));
                if (action == MotionEvent.ACTION_DOWN) {
                    // Original GameMaker mb_left: any tap counts (prologue skip).
                    tapPulse = 4;
                    pointerReleases.down(ev.getPointerId(index));
                }
            }
            if (action == MotionEvent.ACTION_CANCEL) {
                pointerReleases.cancel();
            } else if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_POINTER_UP) {
                int index = ev.getActionIndex();
                pointerReleases.release(ev.getPointerId(index), ev.getX(index), ev.getY(index),
                        bounds.left, bounds.top, w, hh);
            }
            int lifted = action == MotionEvent.ACTION_POINTER_UP
                    ? ev.getActionIndex() : -1;
            for (int i = 0; i < ev.getPointerCount(); i++) {
                if (i == lifted) continue;
                float logicalX = InputViewport.x(ev.getX(i) - bounds.left, w);
                float logicalY = InputViewport.y(ev.getY(i) - bounds.top, hh);
                int button = logicalButton(logicalX, logicalY);
                if (button == 1) moveLeft = true;
                else if (button == 2) moveRight = true;
                else if (button == 3) jump = true;
                else if (button == 4) { attack = true; attackPulse = 4; }
                else if (button == 5) { sword = true; swordPulse = 4; }
                if (logicalY < 137.0f) switchWeapon = true;
            }
            if (ev.getActionMasked() == MotionEvent.ACTION_UP ||
                    ev.getActionMasked() == MotionEvent.ACTION_CANCEL) {
                moveLeft = moveRight = jump = attack = sword = false;
            }
            return true;
        });
    }

    private final class SurfaceLifecycle implements SurfaceHolder.Callback {
        @Override
        public void surfaceCreated(SurfaceHolder holder) {
            gles.setSurface(holder.getSurface());
            startEngine();
        }
        @Override
        public void surfaceChanged(SurfaceHolder holder, int fmt, int w, int hgt) {
            // The GLES3 presenter stretches the 1136x640 engine canvas (the
            // CODE 538 branch that selects view 0 — the original's real-device
            // canvas) onto the whole surface per axis, exactly like the
            // original runner's window-sized GL backbuffer. The full surface
            // is also the touch coordinate space.
            gameRect.set(0, 0, w, hgt);
            gles.setSurface(holder.getSurface());
        }
        @Override
        public void surfaceDestroyed(SurfaceHolder holder) {
            gles.setSurface(null);
            stopEngine();
        }
    }

    private boolean isPackageUpdated() {
        try {
            long lastUpdateTime = getPackageManager().getPackageInfo(getPackageName(), 0).lastUpdateTime;
            File stampFile = new File(getFilesDir(), "version.stamp");
            if (stampFile.exists()) {
                try (java.io.DataInputStream dis = new java.io.DataInputStream(new java.io.FileInputStream(stampFile))) {
                    if (dis.readLong() == lastUpdateTime) {
                        return false;
                    }
                } catch (IOException ignored) {}
            }
            return true;
        } catch (Exception e) {
            return true;
        }
    }

    private void recordPackageUpdated() {
        try {
            long lastUpdateTime = getPackageManager().getPackageInfo(getPackageName(), 0).lastUpdateTime;
            File stampFile = new File(getFilesDir(), "version.stamp");
            try (java.io.DataOutputStream dos = new java.io.DataOutputStream(new java.io.FileOutputStream(stampFile))) {
                dos.writeLong(lastUpdateTime);
            }
        } catch (Exception ignored) {}
    }

    /** Copy `assets/game.droid` from the APK onto the device so
     *  the Rust engine can mmap it. */
    private String prepareGameDroid() {
        boolean forceUpdate = isPackageUpdated();
        File out = new File(getFilesDir(), "game.droid");
        copyAsset("game.droid", out, 1000, forceUpdate);
        copyAsset("full_ir.json", new File(getFilesDir(), "full_ir.json"), 1000000, forceUpdate);
        File textureDir = new File(getFilesDir(), "textures");
        if (!textureDir.exists() && !textureDir.mkdirs()) {
            throw new RuntimeException("Failed to create texture directory");
        }
        for (int i = 0; i < 4; i++) {
            copyAsset("textures/texture_" + i + ".png",
                    new File(textureDir, "texture_" + i + ".png"), 1000, forceUpdate);
        }
        // SoundPool reads from files/sfx/; unpack every embedded wav the
        // original runner preloads (SOND flags preload bit).
        File soundDir = new File(getFilesDir(), "sfx");
        if (!soundDir.exists() && !soundDir.mkdirs()) {
            throw new RuntimeException("Failed to create sfx directory");
        }
        for (int audioId : REQUIRED_AUDIO_IDS) {
            copyAsset("audio/sound_" + audioId + ".wav",
                    new File(soundDir, "sound_" + audioId + ".wav"), 1000, forceUpdate);
        }
        if (forceUpdate) {
            recordPackageUpdated();
        }
        return out.getAbsolutePath();
    }

    private void copyAsset(String assetName, File out, long minimumLength, boolean forceUpdate) {
        if (!forceUpdate && out.exists() && out.length() > minimumLength) return;
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
        pointerReleases.reset();
        String assetPath = prepareGameDroid();
        nativeInit(assetPath);
        prepareSoundPool();

        int w = nativeGetWidth();
        int h = nativeGetHeight();
        if (w == 0 || h == 0) {
            w = surface.getWidth();
            h = surface.getHeight();
            nativeResize(w, h);
        }
        pixelBuffer = new int[w * h];

        nativeSetClockPaused(false);
        running = true;
        renderThread = new Thread(new RenderLoop(), "CallysRenderThread");
        renderThread.start();
    }

    private final class RenderLoop implements Runnable {
        @Override
        public void run() {
            while (running) {
                long now = System.nanoTime();

                boolean jumpNow = jump || jumpPulse > 0;
                boolean attackNow = attack || attackPulse > 0;
                boolean swordNow = sword || swordPulse > 0;
                nativeInput(
                    moveLeft ? 1 : 0,
                    moveRight ? 1 : 0,
                    jumpNow ? 1 : 0,
                    attackNow ? 1 : 0,
                    switchWeapon ? 1 : 0,
                    swordNow ? 1 : 0,
                    tapPulse > 0 ? 1 : 0
                );
                if (jumpPulse > 0) jumpPulse--;
                if (attackPulse > 0) attackPulse--;
                if (swordPulse > 0) swordPulse--;
                if (tapPulse > 0) tapPulse--;
                switchWeapon = false;
                PointerReleaseQueue.Release release;
                while ((release = pointerReleases.poll()) != null) {
                    nativePointerRelease(release.x, release.y);
                }
                nativeStep(now);
                playQueuedSounds();
                playQueuedHaptics();
                nativeBlitToIntArray(pixelBuffer);
                // Our own GLES3 presenter (EGL14 + GLES30): the engine frame
                // goes into an RGBA texture and is drawn as one quad stretched
                // per axis onto the whole surface. No framework Canvas / HWUI
                // in the path; sampling is explicitly GL_NEAREST.
                gles.present(pixelBuffer);
                long remainingNs = 16_666_667L - (System.nanoTime() - now);
                if (remainingNs > 0) {
                    try {
                        Thread.sleep(remainingNs / 1_000_000L,
                                (int) (remainingNs % 1_000_000L));
                    } catch (InterruptedException ignored) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
        }
    }

    private void prepareSoundPool() {
        if (soundPool != null) return;

        AudioAttributes attributes = new AudioAttributes.Builder()
                .setUsage(AudioAttributes.USAGE_GAME)
                .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                .build();
        SoundPool pool = new SoundPool.Builder()
                .setMaxStreams(8)
                .setAudioAttributes(attributes)
                .build();
        soundPool = pool;
        pool.setOnLoadCompleteListener((loadedPool, sampleId, status) -> {
            if (loadedPool != soundPool) return;
            if (status == 0) {
                loadedSamples.add(sampleId);
            } else {
                Log.w(TAG, "SoundPool failed to load sample " + sampleId
                        + " with status " + status);
            }
        });

        File soundDir = new File(getFilesDir(), "sfx");
        for (int audioId : REQUIRED_AUDIO_IDS) {
            File wav = new File(soundDir, "sound_" + audioId + ".wav");
            if (!wav.isFile()) {
                Log.w(TAG, "Exported sound is unavailable: " + wav);
                continue;
            }
            int sampleId = pool.load(wav.getAbsolutePath(), 1);
            if (sampleId != 0) {
                soundSamples.put(audioId, sampleId);
            } else {
                Log.w(TAG, "SoundPool rejected sound " + wav);
            }
        }
    }

    // SOND ids 29..53 are the external mus_* OGG music files (GMS Android
    // packaging: sfx embedded in AUDO, music streamed from APK assets).
    // Index = sond_id - 29; file names match the original APK's assets/.
    private static final String[] MUSIC_NAMES = {
        "mus_egc.ogg", "mus_sneaksbeat.ogg", "mus_new4.ogg", "mus_townmusic.ogg",
        "mus_searching.ogg", "mus_supertrip.ogg", "mus_cally2fez.ogg", "mus_atmospheric.ogg",
        "mus_acoustic.ogg", "mus_amdm7.ogg", "mus_arpdisast.ogg", "mus_happy.ogg",
        "mus_sunrise.ogg", "mus_mariokart.ogg", "mus_menumusic.ogg", "mus_newprogression.ogg",
        "mus_soundwall.ogg", "mus_strongtech.ogg", "mus_synthonic.ogg", "mus_techno.ogg",
        "mus_technoending.ogg", "mus_bosssongending.ogg", "mus_bosssong.ogg",
        "mus_blooddragon.ogg", "mus_cally3.ogg",
    };
    private static final int MUSIC_ID_BASE = 29;
    // SOND resource volumes (audio-sond.json): the original mixer preset per
    // sound. Applied at playback — the bytecode never carries volume.
    private static final float[] MUSIC_VOLUMES = {
        1.0f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    };
    private static final java.util.Map<Integer, Float> SFX_VOLUMES = new java.util.HashMap<>();
    static {
        // All 29 embedded wav SOND ids -> SOND resource volume (identity
        // permutation with AUDO). Author-damped entries: laser 0.28,
        // blade 0.30, rocket 0.70, shotgun 0.93; the rest at unity.
        SFX_VOLUMES.put(0, 1.0f);   // bee
        SFX_VOLUMES.put(1, 1.0f);   // flamethrower
        SFX_VOLUMES.put(2, 1.0f);   // bombgun
        SFX_VOLUMES.put(3, 1.0f);   // jump
        SFX_VOLUMES.put(4, 1.0f);   // meetnewenemy
        SFX_VOLUMES.put(5, 1.0f);   // weaponswap
        SFX_VOLUMES.put(6, 1.0f);   // crescentwave
        SFX_VOLUMES.put(7, 1.0f);   // explode
        SFX_VOLUMES.put(8, 1.0f);   // explode2
        SFX_VOLUMES.put(9, 1.0f);   // assaultrifle
        SFX_VOLUMES.put(10, 1.0f);  // fire
        SFX_VOLUMES.put(11, 0.93f); // shotgun, author-damped
        SFX_VOLUMES.put(12, 0.7f);  // rocket, author-damped
        SFX_VOLUMES.put(13, 1.0f);  // sword
        SFX_VOLUMES.put(14, 1.0f);  // sword2
        SFX_VOLUMES.put(15, 0.28f); // laser, author-damped
        SFX_VOLUMES.put(16, 1.0f);  // bow
        SFX_VOLUMES.put(17, 0.3f);  // blade, author-damped
        SFX_VOLUMES.put(18, 1.0f);  // ice
        SFX_VOLUMES.put(19, 1.0f);  // coin
        SFX_VOLUMES.put(20, 1.0f);  // coin3
        SFX_VOLUMES.put(21, 1.0f);  // enemyhit
        SFX_VOLUMES.put(22, 1.0f);  // impactsound1
        SFX_VOLUMES.put(23, 1.0f);  // impactsound2
        SFX_VOLUMES.put(24, 1.0f);  // impactsound5
        SFX_VOLUMES.put(25, 1.0f);  // levelup
        SFX_VOLUMES.put(26, 1.0f);  // youhavedied
        SFX_VOLUMES.put(27, 1.0f);  // pickupstinger
        SFX_VOLUMES.put(28, 1.0f);  // weaponlevelup
    }
    private static final int LOOP_BIT = 1 << 30;
    private static final int STOP_BIT = 1 << 29;
    private MediaPlayer bgmPlayer;

    private void playQueuedSounds() {
        int packed;
        while ((packed = nativePollSound()) != -1) {
            boolean isStop = (packed & STOP_BIT) != 0;
            boolean looping = (packed & LOOP_BIT) != 0;
            int audioId = packed & ~(LOOP_BIT | STOP_BIT);
            if (audioId >= MUSIC_ID_BASE) {
                handleMusicCommand(audioId, looping, isStop);
            } else if (!isStop) {
                SoundPool pool = soundPool;
                Integer sampleId = soundSamples.get(audioId);
                if (pool != null && sampleId != null && loadedSamples.contains(sampleId)) {
                    float vol = SFX_VOLUMES.containsKey(audioId) ? SFX_VOLUMES.get(audioId) : 1.0f;
                    pool.play(sampleId, vol, vol, 1, 0, 1.0f);
                }
            }
            // Non-music stop commands have no SoundPool teardown here: the IR
            // engine only voices mus_* with stop_sound in practice; sfx voices
            // retire by themselves after playback (see Rust drain_audio).
        }
    }

    private void playQueuedHaptics() {
        Vibrator v = vibrator;
        if (v == null || !v.hasVibrator()) return;
        int event;
        while ((event = nativePollHaptic()) != -1) {
            long duration;
            int amplitude;
            switch (event) {
                case 1: duration = 8; amplitude = 80; break;      // jump
                case 2: duration = 12; amplitude = 110; break;    // fire
                case 3: duration = 18; amplitude = 160; break;    // impact
                case 4: duration = 40; amplitude = 255; break;    // death/explode
                case 5: duration = 10; amplitude = 90; break;     // coin
                case 6: duration = 25; amplitude = 180; break;    // weapon pickup
                default: continue;
            }
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                v.vibrate(VibrationEffect.createOneShot(duration, amplitude));
            } else {
                v.vibrate(duration);
            }
        }
    }

    private void handleMusicCommand(int audioId, boolean looping, boolean isStop) {
        int idx = audioId - MUSIC_ID_BASE;
        if (idx < 0 || idx >= MUSIC_NAMES.length) return;
        if (isStop) {
            stopBgm();
            return;
        }
        // The original bytecode stops the old BGM before starting the next
        // (Rust queues stop commands ahead of plays); defensively teardown
        // any current player anyway so two tracks never overlap.
        stopBgm();
        try {
            MediaPlayer player = new MediaPlayer();
            AssetFileDescriptor afd = getAssets().openFd("music/" + MUSIC_NAMES[idx]);
            player.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());
            afd.close();
            player.setLooping(looping);
            int vidx = audioId - MUSIC_ID_BASE;
            if (vidx >= 0 && vidx < MUSIC_VOLUMES.length) {
                float v = MUSIC_VOLUMES[vidx];
                player.setVolume(v, v);
            }
            player.setOnCompletionListener(mp -> {
                if (bgmPlayer == mp) bgmPlayer = null;
                mp.release();
            });
            player.prepare();
            player.start();
            bgmPlayer = player;
        } catch (IOException | IllegalStateException e) {
            Log.w(TAG, "BGM playback failed for " + MUSIC_NAMES[idx] + ": " + e);
        }
    }

    private void stopBgm() {
        MediaPlayer player = bgmPlayer;
        bgmPlayer = null;
        if (player != null) {
            try {
                player.stop();
            } catch (IllegalStateException ignored) {
            }
            player.release();
        }
    }

    private void releaseSoundPool() {
        SoundPool pool = soundPool;
        soundPool = null;
        soundSamples.clear();
        loadedSamples.clear();
        if (pool != null) pool.release();
        stopBgm();
    }

    private void stopEngine() {
        running = false;
        // Covers Activity pause and Surface loss, including an in-flight loop.
        // Native resume starts a new baseline, never charging suspended time.
        nativeSetClockPaused(true);
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

    @Override
    protected void onDestroy() {
        stopEngine();
        gles.release();
        releaseSoundPool();
        super.onDestroy();
    }
}
