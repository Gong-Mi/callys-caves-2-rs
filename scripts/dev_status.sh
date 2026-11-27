#!/data/data/com.termux/files/usr/bin/bash
# dev_status.sh — "项目重启"自检：一条命令回答"这台机器现在能不能干活"。
# 只读：不改任何文件、不构建。退出码 0=关键项齐全，1=有缺失。
#
# 用法:  bash scripts/dev_status.sh
set -u
ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT" || exit 1

ok=0
say() { printf '%-28s %s\n' "$1" "$2"; }
have() { command -v "$1" >/dev/null 2>&1; }
miss() { say "$1" "MISSING"; ok=1; }

echo "== repo =="
say "path" "$ROOT"
say "branch" "$(git rev-parse --abbrev-ref HEAD 2>/dev/null)"
say "head" "$(git log -1 --format='%h %cs %s' 2>/dev/null | cut -c1-70)"
say "dirty(src)" "$(git status --porcelain 2>/dev/null | grep -vcE 'android-build|\.log$' )"

echo "== rust =="
have cargo && say "cargo" "$(cargo --version 2>/dev/null)" || miss cargo
have rustc && say "rustc" "$(rustc --version 2>/dev/null)" || miss rustc
have cargo-nextest && say "cargo-nextest" "$(cargo nextest --version 2>/dev/null | head -1)" || miss cargo-nextest
have mold && say "mold" "$(mold --version 2>/dev/null | head -1)" || say "mold" "absent (host-link only, optional here)"

echo "== android/java =="
JAVA_HOME=${JAVA_HOME:-$HOME/jvm/java-17-openjdk}
if [ -x "$JAVA_HOME/bin/javac" ]; then say javac "$("$JAVA_HOME/bin/javac" -version 2>&1)"; else miss javac; fi
SDK=${ANDROID_SDK_ROOT:-$HOME/android-sdk}
for t in aapt2 zipalign apksigner; do
  if have "$t"; then say "$t" "$(command -v "$t")"
  elif [ -x "$HOME/android-tools/bin/$t" ]; then say "$t" "$HOME/android-tools/bin/$t"
  else miss "$t"; fi
done
[ -f "$SDK/platforms/android-36/android.jar" ] && say android.jar "$SDK/platforms/android-36/android.jar" || miss android.jar
[ -f "$HOME/.config/callyscaves2/debug.keystore" ] && say keystore "$HOME/.config/callyscaves2/debug.keystore" || miss keystore

echo "== oracle =="
LIBYOYO=${CALLY_LIBYOYO:-$HOME/cally/oracle/libyoyo.so}
if [ -f "$LIBYOYO" ]; then
  say libyoyo "$(sha256sum "$LIBYOYO" | cut -c1-16) $LIBYOYO"
else
  miss libyoyo
fi
python3 - <<'EOF' 2>/dev/null || ok=1
import unicorn
print(f"{'unicorn':<28} {unicorn.__version__}")
EOF
[ -f "$ROOT/c-recon/build/collision_test" ] && say c-collision_test "built" || say c-collision_test "not built (smoke builds it)"

echo "== last full run =="
if [ -f "$ROOT/nextest-prague.log" ]; then
  say summary "$(grep -E '^ *Summary' "$ROOT/nextest-prague.log" | tail -1 | sed 's/^ *//')"
else
  say summary "no nextest-prague.log yet"
fi

echo
[ "$ok" -eq 0 ] && echo "dev_status: READY" || echo "dev_status: MISSING ITEMS"
exit "$ok"
