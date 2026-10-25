#!/data/data/com.termux/files/usr/bin/bash
# dev_smoke.sh — 项目重启后的快速冒烟：把"这台机器还能不能跑对"压到 ~1 分钟。
# 三件事，各自独立记 PASS/FAIL，最后给总耗时：
#   1. C 碰撞单测（clang 构建 + 107 checks）
#   2. mask-base oracle 探针（需 unicorn + libyoyo）
#   3. Rust 精确碰撞套件（nextest，单个测试二进制）
# 只读+构建到临时/既有 target，不改源码。
#
# 用法:  bash scripts/dev_smoke.sh
set -u
ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT" || exit 1
export PATH="$HOME/jvm/java-17-openjdk/bin:$HOME/android-tools/bin:$PATH"
export CALLY_LIBYOYO=${CALLY_LIBYOYO:-$HOME/cally/oracle/libyoyo.so}

fails=0
t0=$(date +%s)
TMP=${TMPDIR:-/data/data/com.termux/files/usr/tmp}
step() { printf '\n== %s ==\n' "$1"; }

step "1/3 C collision unit test"
if clang -std=c11 -O2 -Wall -Ic-recon/include \
    c-recon/src/host.c c-recon/src/collision.c c-recon/src/objects.c \
    c-recon/src/builtins2.c c-recon/gen/objects_data.c c-recon/gen/registry.c \
    c-recon/gen/gml_0012.c c-recon/gen/gml_0792.c c-recon/gen/sprites.c \
    c-recon/tests/collision_test.c -o "$ROOT/c-recon/build/collision_test" -lm 2>"$TMP/dev_smoke_c.log"; then
  out=$(./c-recon/build/collision_test | tail -1)
  echo "$out"
  case "$out" in *"0 failed") ;; *) fails=$((fails+1)) ;; esac
else
  echo "clang build FAILED (see $TMP/dev_smoke_c.log)"
  fails=$((fails+1))
fi

step "2/3 mask-base oracle probe"
if python3 c-recon/tools/oracle/base_probe.py 2>/dev/null | tail -3; then :; else
  echo "base_probe FAILED"
  fails=$((fails+1))
fi

step "3/3 Rust precise-collision suite (nextest)"
if cargo nextest run -p callys-core --test precise_collision_masks_ir \
      --cargo-profile ci-test --no-fail-fast 2>&1 | grep -E "^ *Summary" ; then :; else
  echo "nextest FAILED"
  fails=$((fails+1))
fi

dt=$(( $(date +%s) - t0 ))
echo
if [ "$fails" -eq 0 ]; then
  echo "dev_smoke: PASS (${dt}s)"
  exit 0
else
  echo "dev_smoke: FAIL (${fails} step(s), ${dt}s)"
  exit 1
fi
