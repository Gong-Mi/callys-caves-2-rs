import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.FeatureInfo;
import android.content.pm.InstrumentationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PermissionGroupInfo;
import android.content.pm.PermissionInfo;
import android.content.pm.ProviderInfo;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.content.res.Resources;
import android.content.res.XmlResourceParser;
import android.graphics.drawable.Drawable;
import android.util.Log;
import java.util.List;

// Minimal PackageManager for the shell context. Every entry is logged so the
// runner's actual requirements surface in logcat ("bhctx" tag) instead of
// failing silently. Auto-generated default stubs + hand-written entries for
// the calls the runner is known to make.
public class BhPackageManager extends PackageManager {
    static final String TAG = "bhctx";

    @Override
    public android.content.pm.PackageInfo getPackageInfo(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getPackageInfo " + arg0 + " flags=" + arg1);
        String pkgName = (String) arg0;
        PackageInfo pi = new PackageInfo();
        pi.packageName = pkgName;
        pi.versionName = "2.1.9";
        pi.versionCode = 26;
        ApplicationInfo ai = new ApplicationInfo();
        ai.packageName = pkgName;
        ai.sourceDir = BhCtx.APK_PATH;
        ai.dataDir = BhCtx.WORK_DIR + "/files";
        ai.metaData = new android.os.Bundle();
        ai.flags = ApplicationInfo.FLAG_HAS_CODE;
        pi.applicationInfo = ai;
        return pi;    }

    @Override
    public android.content.pm.PackageInfo getPackageInfo(android.content.pm.VersionedPackage arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getPackageInfo(versioned) " + arg0 + " flags=" + arg1);
        String pkgName = arg0.getPackageName();
        PackageInfo pi = new PackageInfo();
        pi.packageName = pkgName;
        pi.versionName = "2.1.9";
        pi.versionCode = 26;
        ApplicationInfo ai = new ApplicationInfo();
        ai.packageName = pkgName;
        ai.sourceDir = BhCtx.APK_PATH;
        ai.dataDir = BhCtx.WORK_DIR + "/files";
        ai.metaData = new android.os.Bundle();
        ai.flags = ApplicationInfo.FLAG_HAS_CODE;
        pi.applicationInfo = ai;
        return pi;    }

    @Override
    public java.lang.String[] currentToCanonicalPackageNames(java.lang.String[] arg0)  {
        Log.i(TAG, "currentToCanonicalPackageNames");
        return new java.lang.String[0];
    }

    @Override
    public java.lang.String[] canonicalToCurrentPackageNames(java.lang.String[] arg0)  {
        Log.i(TAG, "canonicalToCurrentPackageNames");
        return new java.lang.String[0];
    }

    @Override
    public android.content.Intent getLaunchIntentForPackage(java.lang.String arg0)  {
        Log.i(TAG, "getLaunchIntentForPackage");
        return null;
    }

    @Override
    public android.content.Intent getLeanbackLaunchIntentForPackage(java.lang.String arg0)  {
        Log.i(TAG, "getLeanbackLaunchIntentForPackage");
        return null;
    }

    @Override
    public int[] getPackageGids(java.lang.String arg0)  throws NameNotFoundException {
        Log.i(TAG, "getPackageGids");
        return new int[0];
    }

    @Override
    public int[] getPackageGids(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getPackageGids");
        return new int[0];
    }

    @Override
    public int getPackageUid(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        return 10000;    }

    @Override
    public android.content.pm.PermissionInfo getPermissionInfo(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getPermissionInfo");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.PermissionInfo> queryPermissionsByGroup(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "queryPermissionsByGroup");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.PermissionGroupInfo getPermissionGroupInfo(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getPermissionGroupInfo");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.PermissionGroupInfo> getAllPermissionGroups(int arg0)  {
        Log.i(TAG, "getAllPermissionGroups");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.ApplicationInfo getApplicationInfo(java.lang.String arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getApplicationInfo " + arg0 + " flags=" + arg1);
        ApplicationInfo ai = new ApplicationInfo();
        ai.packageName = arg0;
        ai.sourceDir = BhCtx.APK_PATH;
        ai.publicSourceDir = BhCtx.APK_PATH;
        ai.dataDir = BhCtx.WORK_DIR + "/files";
        ai.metaData = new android.os.Bundle();
        ai.flags = ApplicationInfo.FLAG_HAS_CODE | ApplicationInfo.FLAG_ALLOW_CLEAR_USER_DATA;
        return ai;    }

    @Override
    public android.content.pm.ActivityInfo getActivityInfo(android.content.ComponentName arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getActivityInfo " + arg0);
        ActivityInfo i = new ActivityInfo();
        i.packageName = arg0.getPackageName();
        i.name = arg0.getClassName();
        i.applicationInfo = getApplicationInfo(arg0.getPackageName(), 0);
        return i;    }

    @Override
    public android.content.pm.ActivityInfo getReceiverInfo(android.content.ComponentName arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getReceiverInfo");
        return null;
    }

    @Override
    public android.content.pm.ServiceInfo getServiceInfo(android.content.ComponentName arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getServiceInfo");
        return null;
    }

    @Override
    public android.content.pm.ProviderInfo getProviderInfo(android.content.ComponentName arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getProviderInfo");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.PackageInfo> getInstalledPackages(int arg0)  {
        Log.i(TAG, "getInstalledPackages");
        return new java.util.ArrayList();
    }

    @Override
    public java.util.List<android.content.pm.PackageInfo> getPackagesHoldingPermissions(java.lang.String[] arg0, int arg1)  {
        Log.i(TAG, "getPackagesHoldingPermissions");
        return new java.util.ArrayList();
    }

    @Override
    public int checkPermission(java.lang.String arg0, java.lang.String arg1)  {
        Log.i(TAG, "checkPermission " + arg0);
        return PackageManager.PERMISSION_GRANTED;    }

    @Override
    public boolean isPermissionRevokedByPolicy(java.lang.String arg0, java.lang.String arg1)  {
        Log.i(TAG, "isPermissionRevokedByPolicy");
        return false;
    }

    @Override
    public boolean addPermission(android.content.pm.PermissionInfo arg0)  {
        Log.i(TAG, "addPermission");
        return false;
    }

    @Override
    public boolean addPermissionAsync(android.content.pm.PermissionInfo arg0)  {
        Log.i(TAG, "addPermissionAsync");
        return false;
    }

    @Override
    public void removePermission(java.lang.String arg0)  {
    }

    @Override
    public int checkSignatures(java.lang.String arg0, java.lang.String arg1)  {
        return PackageManager.SIGNATURE_MATCH;    }

    @Override
    public int checkSignatures(int arg0, int arg1)  {
        return PackageManager.SIGNATURE_MATCH;    }

    @Override
    public java.lang.String[] getPackagesForUid(int arg0)  {
        return new String[] { BhCtx.PKG };    }

    @Override
    public java.lang.String getNameForUid(int arg0)  {
        return BhCtx.PKG;    }

    @Override
    public java.util.List<android.content.pm.ApplicationInfo> getInstalledApplications(int arg0)  {
        Log.i(TAG, "getInstalledApplications");
        return new java.util.ArrayList();
    }

    @Override
    public boolean isInstantApp()  {
        Log.i(TAG, "isInstantApp");
        return false;
    }

    @Override
    public boolean isInstantApp(java.lang.String arg0)  {
        Log.i(TAG, "isInstantApp");
        return false;
    }

    @Override
    public int getInstantAppCookieMaxBytes()  {
        Log.i(TAG, "getInstantAppCookieMaxBytes");
        return 0;
    }

    @Override
    public byte[] getInstantAppCookie()  {
        Log.i(TAG, "getInstantAppCookie");
        return new byte[0];
    }

    @Override
    public void clearInstantAppCookie()  {
    }

    @Override
    public void updateInstantAppCookie(byte[] arg0)  {
    }

    @Override
    public java.lang.String[] getSystemSharedLibraryNames()  {
        Log.i(TAG, "getSystemSharedLibraryNames");
        return new java.lang.String[0];
    }

    @Override
    public java.util.List<android.content.pm.SharedLibraryInfo> getSharedLibraries(int arg0)  {
        Log.i(TAG, "getSharedLibraries");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.ChangedPackages getChangedPackages(int arg0)  {
        Log.i(TAG, "getChangedPackages");
        return null;
    }

    @Override
    public android.content.pm.FeatureInfo[] getSystemAvailableFeatures()  {
        Log.i(TAG, "getSystemAvailableFeatures");
        return new android.content.pm.FeatureInfo[0];
    }

    @Override
    public boolean hasSystemFeature(java.lang.String arg0)  {
        Log.i(TAG, "hasSystemFeature " + arg0);
        return true;    }

    @Override
    public boolean hasSystemFeature(java.lang.String arg0, int arg1)  {
        Log.i(TAG, "hasSystemFeature " + arg0 + " ver=" + arg1);
        return true;    }

    @Override
    public android.content.pm.ResolveInfo resolveActivity(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "resolveActivity");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.ResolveInfo> queryIntentActivities(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "queryIntentActivities");
        return new java.util.ArrayList();
    }

    @Override
    public java.util.List<android.content.pm.ResolveInfo> queryIntentActivityOptions(android.content.ComponentName arg0, android.content.Intent[] arg1, android.content.Intent arg2, int arg3)  {
        Log.i(TAG, "queryIntentActivityOptions");
        return new java.util.ArrayList();
    }

    @Override
    public java.util.List<android.content.pm.ResolveInfo> queryBroadcastReceivers(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "queryBroadcastReceivers");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.ResolveInfo resolveService(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "resolveService");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.ResolveInfo> queryIntentServices(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "queryIntentServices");
        return new java.util.ArrayList();
    }

    @Override
    public java.util.List<android.content.pm.ResolveInfo> queryIntentContentProviders(android.content.Intent arg0, int arg1)  {
        Log.i(TAG, "queryIntentContentProviders");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.ProviderInfo resolveContentProvider(java.lang.String arg0, int arg1)  {
        Log.i(TAG, "resolveContentProvider");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.ProviderInfo> queryContentProviders(java.lang.String arg0, int arg1, int arg2)  {
        Log.i(TAG, "queryContentProviders");
        return new java.util.ArrayList();
    }

    @Override
    public android.content.pm.InstrumentationInfo getInstrumentationInfo(android.content.ComponentName arg0, int arg1)  throws NameNotFoundException {
        Log.i(TAG, "getInstrumentationInfo");
        return null;
    }

    @Override
    public java.util.List<android.content.pm.InstrumentationInfo> queryInstrumentation(java.lang.String arg0, int arg1)  {
        Log.i(TAG, "queryInstrumentation");
        return new java.util.ArrayList();
    }

    @Override
    public android.graphics.drawable.Drawable getDrawable(java.lang.String arg0, int arg1, android.content.pm.ApplicationInfo arg2)  {
        Log.i(TAG, "getDrawable");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityIcon(android.content.ComponentName arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityIcon(android.content.Intent arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityBanner(android.content.ComponentName arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityBanner");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityBanner(android.content.Intent arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityBanner");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getDefaultActivityIcon()  {
        Log.i(TAG, "getDefaultActivityIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationIcon(android.content.pm.ApplicationInfo arg0)  {
        Log.i(TAG, "getApplicationIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationIcon(java.lang.String arg0)  throws NameNotFoundException {
        Log.i(TAG, "getApplicationIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationBanner(android.content.pm.ApplicationInfo arg0)  {
        Log.i(TAG, "getApplicationBanner");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationBanner(java.lang.String arg0)  throws NameNotFoundException {
        Log.i(TAG, "getApplicationBanner");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityLogo(android.content.ComponentName arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityLogo");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getActivityLogo(android.content.Intent arg0)  throws NameNotFoundException {
        Log.i(TAG, "getActivityLogo");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationLogo(android.content.pm.ApplicationInfo arg0)  {
        Log.i(TAG, "getApplicationLogo");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getApplicationLogo(java.lang.String arg0)  throws NameNotFoundException {
        Log.i(TAG, "getApplicationLogo");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getUserBadgedIcon(android.graphics.drawable.Drawable arg0, android.os.UserHandle arg1)  {
        Log.i(TAG, "getUserBadgedIcon");
        return null;
    }

    @Override
    public android.graphics.drawable.Drawable getUserBadgedDrawableForDensity(android.graphics.drawable.Drawable arg0, android.os.UserHandle arg1, android.graphics.Rect arg2, int arg3)  {
        Log.i(TAG, "getUserBadgedDrawableForDensity");
        return null;
    }

    @Override
    public java.lang.CharSequence getUserBadgedLabel(java.lang.CharSequence arg0, android.os.UserHandle arg1)  {
        Log.i(TAG, "getUserBadgedLabel");
        return null;
    }

    @Override
    public java.lang.CharSequence getText(java.lang.String arg0, int arg1, android.content.pm.ApplicationInfo arg2)  {
        Log.i(TAG, "getText");
        return null;
    }

    @Override
    public android.content.res.XmlResourceParser getXml(java.lang.String arg0, int arg1, android.content.pm.ApplicationInfo arg2)  {
        Log.i(TAG, "getXml");
        return null;
    }

    @Override
    public java.lang.CharSequence getApplicationLabel(android.content.pm.ApplicationInfo arg0)  {
        return "Cally's Caves 2";    }

    @Override
    public android.content.res.Resources getResourcesForActivity(android.content.ComponentName arg0)  throws NameNotFoundException {
        Log.i(TAG, "getResourcesForActivity");
        return null;
    }

    @Override
    public android.content.res.Resources getResourcesForApplication(android.content.pm.ApplicationInfo arg0)  throws NameNotFoundException {
        Log.i(TAG, "getResourcesForApplication");
        return null;
    }

    @Override
    public android.content.res.Resources getResourcesForApplication(java.lang.String arg0)  throws NameNotFoundException {
        Log.i(TAG, "getResourcesForApplication");
        return null;
    }

    @Override
    public void verifyPendingInstall(int arg0, int arg1)  {
    }

    @Override
    public void extendVerificationTimeout(int arg0, int arg1, long arg2)  {
    }

    @Override
    public void setInstallerPackageName(java.lang.String arg0, java.lang.String arg1)  {
    }

    @Override
    public java.lang.String getInstallerPackageName(java.lang.String arg0)  {
        return "com.android.vending";    }

    @Override
    public void addPackageToPreferred(java.lang.String arg0)  {
    }

    @Override
    public void removePackageFromPreferred(java.lang.String arg0)  {
    }

    @Override
    public java.util.List<android.content.pm.PackageInfo> getPreferredPackages(int arg0)  {
        Log.i(TAG, "getPreferredPackages");
        return new java.util.ArrayList();
    }

    @Override
    public void addPreferredActivity(android.content.IntentFilter arg0, int arg1, android.content.ComponentName[] arg2, android.content.ComponentName arg3)  {
    }

    @Override
    public void clearPackagePreferredActivities(java.lang.String arg0)  {
    }

    @Override
    public int getPreferredActivities(java.util.List<android.content.IntentFilter> arg0, java.util.List<android.content.ComponentName> arg1, java.lang.String arg2)  {
        Log.i(TAG, "getPreferredActivities");
        return 0;
    }

    @Override
    public void setComponentEnabledSetting(android.content.ComponentName arg0, int arg1, int arg2)  {
    }

    @Override
    public int getComponentEnabledSetting(android.content.ComponentName arg0)  {
        Log.i(TAG, "getComponentEnabledSetting");
        return 0;
    }

    @Override
    public void setApplicationEnabledSetting(java.lang.String arg0, int arg1, int arg2)  {
    }

    @Override
    public int getApplicationEnabledSetting(java.lang.String arg0)  {
        Log.i(TAG, "getApplicationEnabledSetting");
        return 0;
    }

    @Override
    public boolean isSafeMode()  {
        return false;    }

    @Override
    public void setApplicationCategoryHint(java.lang.String arg0, int arg1)  {
    }

    @Override
    public android.content.pm.PackageInstaller getPackageInstaller()  {
        Log.i(TAG, "getPackageInstaller");
        return null;
    }

    @Override
    public boolean canRequestPackageInstalls()  {
        Log.i(TAG, "canRequestPackageInstalls");
        return false;
    }
}
