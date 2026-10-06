// Native entry points exported by libbhshell.so (blockheads shell32 shim).
// Class name must stay "BhShell" so the symbols Java_BhShell_* resolve.
public class BhShell {
    public static native long ping();
    public static native int regFramework();
}
