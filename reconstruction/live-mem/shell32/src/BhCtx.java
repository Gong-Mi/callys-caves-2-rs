import android.app.Application;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.util.Log;
import java.io.File;

// Shell context: serves the runner's PackageManager / file-dir queries
// without an Activity. Everything is logged ("bhctx" tag) so each served
// call site is visible evidence.
public class BhCtx extends Application {
    static final String TAG = "bhctx";
    static String APK_PATH;
    static String WORK_DIR;
    static String PKG = "com.vdogames.callyscaves2";
    final BhPackageManager pm = new BhPackageManager();

    public BhCtx(String workDir, String apkPath) {
        APK_PATH = apkPath;
        WORK_DIR = workDir;
    }

    @Override
    public PackageManager getPackageManager() {
        Log.i(TAG, "getPackageManager");
        return pm;
    }

    @Override
    public ApplicationInfo getApplicationInfo() {
        Log.i(TAG, "getApplicationInfo");
        try {
            return pm.getApplicationInfo(PKG, 0);
        } catch (android.content.pm.PackageManager.NameNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public File getFilesDir() {
        File f = new File(WORK_DIR, "files");
        f.mkdirs();
        return f;
    }

    @Override
    public File getCacheDir() {
        File f = new File(WORK_DIR, "cache");
        f.mkdirs();
        return f;
    }

    @Override
    public File getDir(String name, int mode) {
        File f = new File(WORK_DIR, name);
        f.mkdirs();
        return f;
    }

    @Override
    public String getPackageName() {
        return PKG;
    }

    @Override
    public int checkCallingOrSelfPermission(String permission) {
        Log.i(TAG, "checkCallingOrSelfPermission " + permission);
        return PackageManager.PERMISSION_GRANTED;
    }

    @Override
    public int checkSelfPermission(String permission) {
        Log.i(TAG, "checkSelfPermission " + permission);
        return PackageManager.PERMISSION_GRANTED;
    }

    @Override
    public Object getSystemService(String name) {
        Log.i(TAG, "getSystemService " + name);
        return null;
    }

    @Override
    public android.content.Context getApplicationContext() {
        return this;
    }
}
