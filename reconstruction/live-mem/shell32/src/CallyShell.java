import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import com.vdogames.callyscaves2.RunnerActivity;
import com.yoyogames.runner.RunnerJNILib;
import java.io.File;
import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;

// CallyShell: bare dalvikvm32 harness for the original GameMaker runner
// (com.vdogames.callyscaves2). No Activity, no window: an ES2 context on a
// PBuffer drives libyoyo exactly like DemoGLSurfaceView's render thread does
// (RenderSplash -> Startup -> Process loop), with the real classes.dex on
// the classpath so libyoyo's JNI_OnLoad and Java callbacks resolve natively.
//
// Framework natives (SystemProperties, MessageQueue, EGLImpl, GLES20, Log...)
// are not registered by bare dalvikvm32, so we reuse the blockheads shell32
// shim: load the 32-bit libandroid_runtime.so, then libbhshell.so, then call
// BhShell.regFramework() (Java_BhShell_regFramework export) which invokes the
// real per-module register_* entry points.
public class CallyShell {
    static EGL10 egl;
    static EGLDisplay disp;
    static EGLSurface surf;
    static EGLContext ctx;

    public static void main(String[] args) {
        Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
            @Override public void run() {
                System.out.println("[shell] SHUTDOWN-HOOK (Java-initiated exit)");
                System.out.flush();
            }
        }, "shutdown-hook"));
        try {
            realMain(args);
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(2);
        }
    }

    static void realMain(String[] args) throws Exception {
        final String apkPath = args[0];
        final String workDir = args[1];
        final int W = Integer.parseInt(args[2]);
        final int H = Integer.parseInt(args[3]);

        new File(workDir, "files").mkdirs();
        new File(workDir, "cache").mkdirs();
        new File(workDir, "home").mkdirs();

        // Framework natives must be registered before ANY framework class
        // with static natives initializes (Looper <clinit> reads
        // SystemProperties; Log prints via println_native).
        System.load("/system/lib/libandroid_runtime.so");
        System.load(workDir + "/libs/libbhshell.so");
        int reg = BhShell.regFramework();
        Log.i("shell", "regFramework -> " + reg);

        // Main thread = UI-proxy looper (RunnerActivity.ViewHandler target).
        Looper.prepare();
        RunnerActivity.ViewHandler = new Handler(Looper.myLooper());
        RunnerJNILib.ms_context = new BhCtx(workDir, apkPath);
        // Process calls back RunnerJNILib.HasVsyncHandler() which dereferences
        // RunnerActivity.CurrentActivity.vsyncHandler. Allocate the real
        // RunnerActivity without running its (Activity-bound) constructor.
        try {
            Class<?> unsafeClass = Class.forName("sun.misc.Unsafe");
            java.lang.reflect.Field tu = unsafeClass.getDeclaredField("theUnsafe");
            tu.setAccessible(true);
            Object unsafe = tu.get(null);
            java.lang.reflect.Method alloc = unsafeClass.getMethod("allocateInstance", Class.class);
            java.lang.reflect.Field f = RunnerActivity.class.getDeclaredField("vsyncHandler");
            f.setAccessible(true);
            Object ra = alloc.invoke(unsafe, RunnerActivity.class);
            f.set(ra, null);
            RunnerActivity.CurrentActivity = (RunnerActivity) ra;
            Log.i("shell", "CurrentActivity allocated via Unsafe");
        } catch (Throwable t) {
            Log.i("shell", "Unsafe CurrentActivity failed: " + t);
        }
        RunnerActivity.DisplayWidth = W;
        RunnerActivity.DisplayHeight = H;
        RunnerActivity.Orientation = 0;
        RunnerActivity.FocusOverride = true;
        RunnerActivity.HasFocus = true;

        System.load(workDir + "/libs/libopenal.so");
        System.load(workDir + "/libs/libyoyo.so");
        Log.i("shell", "libs loaded");

        // Control channel: work/cmd.txt lines drive the runner from outside
        //   touch <action> <id> <x> <y>   -> RunnerJNILib.TouchEvent
        //   key <type> <keyCode>           -> RunnerJNILib.KeyEvent
        // Consumed lines are deleted; unknown lines are logged and removed.
        final String cmdFile = workDir + "/cmd.txt";
        Thread ctl = new Thread(new Runnable() {
            @Override public void run() {
                java.io.File f = new java.io.File(cmdFile);
                while (true) {
                    try {
                        if (f.exists() && f.length() > 0) {
                            // claim-then-execute: move the file away first so a
                            // hung native call cannot lose queued commands
                            java.io.File tmp = new java.io.File(cmdFile + ".run");
                            if (!f.renameTo(tmp)) { Thread.sleep(20); continue; }
                            java.io.BufferedReader br = new java.io.BufferedReader(
                                    new java.io.FileReader(tmp));
                            StringBuilder keep = new StringBuilder();
                            String line;
                            while ((line = br.readLine()) != null) {
                                line = line.trim();
                                if (line.isEmpty()) continue;
                                String[] t = line.split(" ");
                                try {
                                    if (t[0].equals("touch") && t.length == 5) {
                                        Log.i("shell", "CTL enter " + line);
                                        RunnerJNILib.TouchEvent(Integer.parseInt(t[1]),
                                                Integer.parseInt(t[2]),
                                                Float.parseFloat(t[3]), Float.parseFloat(t[4]));
                                        Log.i("shell", "CTL done touch " + line);
                                    } else if (t[0].equals("key") && t.length == 3) {
                                        RunnerJNILib.KeyEvent(Integer.parseInt(t[1]),
                                                Integer.parseInt(t[2]));
                                        Log.i("shell", "CTL key " + line);
                                    } else {
                                        Log.i("shell", "CTL unknown (consumed): " + line);
                                    }
                                } catch (Throwable te) {
                                    Log.i("shell", "CTL error on '" + line + "': " + te);
                                }
                            }
                            br.close();
                            tmp.delete();
                            if (keep.length() > 0) {
                                java.io.FileWriter fw = new java.io.FileWriter(f, true);
                                fw.write(keep.toString());
                                fw.close();
                            }
                        }
                    } catch (Throwable te) {
                        Log.i("shell", "CTL loop: " + te);
                    }
                    try { Thread.sleep(100); } catch (InterruptedException ie) { return; }
                }
            }
        }, "shell-ctl");
        ctl.setDaemon(true);
        ctl.start();

        Thread gl = new Thread(new Runnable() {
            @Override public void run() {
                try {
                    setupEgl(W, H);
                    // Mirror DemoRenderer.onSurfaceCreated's SetKeyValue batch.
                    RunnerJNILib.SetKeyValue(0, 0, "");                    // not tablet
                    RunnerJNILib.SetKeyValue(1, 0, workDir + "/cache");    // cache dir
                    RunnerJNILib.SetKeyValue(2, 0, "en");                  // language
                    RunnerJNILib.SetKeyValue(3, 320, "");                  // density dpi
                    RunnerJNILib.SetKeyValue(4, 320, "");
                    RunnerJNILib.SetKeyValue(5, Build.VERSION.SDK_INT, Build.VERSION.RELEASE);
                    RunnerJNILib.SetKeyValue(8, 0, "zz");                  // country

                    String saveDir = workDir + "/files/";
                    System.out.println("[shell] SHELL calling RenderSplash");
                    RunnerJNILib.RenderSplash(apkPath, "assets/splash.png", W, H, 0, 0, 0, 0);
                    System.out.println("[shell] SHELL splash returned");
                    RunnerJNILib.Startup(apkPath, saveDir, "com.vdogames.callyscaves2", 0);
                    System.out.println("[shell] SHELL startup returned");
                    processLoop(W, H, workDir);
                } catch (Throwable t) {
                    t.printStackTrace();
                    System.exit(3);
                }
            }
        }, "shell-gl");
        gl.start();

        Looper.loop();
    }

    static void setupEgl(int w, int h) {
        egl = (EGL10) EGLContext.getEGL();
        disp = egl.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);
        int[] ver = new int[2];
        if (!egl.eglInitialize(disp, ver))
            throw new RuntimeException("eglInitialize failed");
        Log.i("shell", "egl " + ver[0] + "." + ver[1]);

        int ES2_BIT = 4; // EGL_OPENGL_ES2_BIT
        int[] cfgSpec = {
            EGL10.EGL_RED_SIZE, 5,
            EGL10.EGL_GREEN_SIZE, 6,
            EGL10.EGL_BLUE_SIZE, 5,
            EGL10.EGL_DEPTH_SIZE, 16,
            EGL10.EGL_SURFACE_TYPE, EGL10.EGL_WINDOW_BIT | EGL10.EGL_PBUFFER_BIT,
            EGL10.EGL_RENDERABLE_TYPE, ES2_BIT,
            EGL10.EGL_NONE
        };
        EGLConfig[] cfgs = new EGLConfig[8];
        int[] num = new int[1];
        if (!egl.eglChooseConfig(disp, cfgSpec, cfgs, cfgs.length, num) || num[0] < 1)
            throw new RuntimeException("eglChooseConfig failed, err=" + egl.eglGetError());
        Log.i("shell", "egl configs: " + num[0]);

        int EGL_CONTEXT_CLIENT_VERSION = 0x3098;
        ctx = egl.eglCreateContext(disp, cfgs[0], EGL10.EGL_NO_CONTEXT,
                new int[] { EGL_CONTEXT_CLIENT_VERSION, 2, EGL10.EGL_NONE });
        if (ctx == null || ctx == EGL10.EGL_NO_CONTEXT)
            throw new RuntimeException("eglCreateContext failed, err=" + egl.eglGetError());

        surf = egl.eglCreatePbufferSurface(disp, cfgs[0],
                new int[] { EGL10.EGL_WIDTH, w, EGL10.EGL_HEIGHT, h, EGL10.EGL_NONE });
        if (surf == null || surf == EGL10.EGL_NO_SURFACE)
            throw new RuntimeException("eglCreatePbufferSurface failed, err=" + egl.eglGetError());

        if (!egl.eglMakeCurrent(disp, surf, surf, ctx))
            throw new RuntimeException("eglMakeCurrent failed, err=" + egl.eglGetError());
        Log.i("shell", "egl ready " + w + "x" + h);
    }

    static void processLoop(int w, int h, String workDir) {
        java.io.File paced = new java.io.File(workDir + "/paced");
        for (int i = 0; ; i++) {
            if (paced.exists()) {
                long ms = 30;
                try {
                    java.io.File pm = new java.io.File(workDir + "/pace_ms");
                    if (pm.exists()) {
                        java.io.BufferedReader r = new java.io.BufferedReader(new java.io.FileReader(pm));
                        String line = r.readLine(); r.close();
                        if (line != null) { long v = Long.parseLong(line.trim()); if (v > 0 && v < 5000) ms = v; }
                    }
                } catch (Throwable te) { /* keep default */ }
                try { Thread.sleep(ms); } catch (InterruptedException ie) { return; }
            }
            int ret = RunnerJNILib.Process(w, h, 0f, 0f, 0f, 0, 0, 60.0f);
            if (ret == 0) {
                Log.i("shell", "Process returned 0 (exit)");
                System.exit(0);
            } else if (ret == 2) {
                Log.i("shell", "Process requested restart; ignoring, continuing");
            }
            if (RunnerJNILib.canFlip()) {
                egl.eglSwapBuffers(disp, surf);
            }
            if (i % 300 == 0) Log.i("shell", "process iteration " + i);
        }
    }
}
