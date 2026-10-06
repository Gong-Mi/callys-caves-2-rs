#!/data/data/com.termux/files/usr/bin/sh
# CallyShell wrapper: run the original GameMaker runner headless under
# dalvikvm32 (no Activity/window). Recipe derived from blockheads shell32.
set -e
S=/data/data/com.termux/files/home/cally-work/shell32
W=$S/work
mkdir -p "$W/tmp" "$W/files" "$W/cache" "$W/home" "$W/android-data" "$W/logs"
BASEAPK=$S/apk/base.apk
JLP="$W/libs:/system/lib:/vendor/lib:/system_ext/lib:/odm/lib:/apex/com.android.art/lib:/apex/com.android.runtime/lib:/apex/com.android.i18n/lib"
export ANDROID_DATA="$W/android-data"
export HOME="$W/home"
export TMPDIR="$W/tmp"
BC="$W/bootsp.dex:${BOOTCLASSPATH:-}"
export BOOTCLASSPATH="$BC"
XBC="-Xbootclasspath:$BC"
XLOC="-Xbootclasspath-locations:$BC"
# Do NOT export a 32-bit LD_LIBRARY_PATH into this 64-bit shell; inject it
# into the dalvikvm32 child only.
exec /data/data/com.termux/files/usr/bin/bash -c "LD_LIBRARY_PATH=\"$W/libs\" exec -a callyscaves2-shell /apex/com.android.art/bin/dalvikvm32 -Xnoimage-dex2oat $XBC $XLOC -Djava.io.tmpdir=\"$W/tmp\" -Djava.library.path=\"$JLP\" -cp \"$S/build/shell.dex:$S/apk/classes.dex\" CallyShell \"$BASEAPK\" \"$W\" \"\${4:-1136}\" \"\${5:-640}\""
