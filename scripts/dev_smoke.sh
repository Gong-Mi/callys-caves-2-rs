#!/data/data/com.termux/files/usr/bin/bash
# dev_smoke.sh — 项目重启后的快速冒烟：把"这台机器还能不能跑对"压到 ~1 分钟。
# 八个独立失败域：
#   1. C 碰撞单测
#   2. C 对象/创建/音频单测
#   3. C with 环境与销毁单测
#   4. C 房间数据与 room builtin 单测
#   5. 真实 CODE 的 C<->VM 环境场景差分
#   6. C<->VM Draw 命令流场景差分
#   7. mask-base oracle 探针（需 unicorn + libyoyo）
#   8. Rust 精确碰撞套件（nextest，单个测试二进制）
# 只读源码；编译产物写入 c-recon/build、target 或 $TMPDIR。
#
# 用法:  bash scripts/dev_smoke.sh [--deep]
set -u -o pipefail
ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT" || exit 1
export PATH="$HOME/jvm/java-17-openjdk/bin:$HOME/android-tools/bin:$PATH"
export CALLY_LIBYOYO=${CALLY_LIBYOYO:-$HOME/cally/oracle/libyoyo.so}

fails=0
t0=$(date +%s)
TMP=${TMPDIR:-/data/data/com.termux/files/usr/tmp}
step() { printf '\n== %s ==\n' "$1"; }
mkdir -p "$ROOT/c-recon/build"

# registry.c references every checked-in body; use the same glob for every test
# binary so adding a fixture body cannot silently leave a test with a stub dispatch.
C_SOURCES=(
  c-recon/src/host.c c-recon/src/collision.c c-recon/src/objects.c
  c-recon/src/builtins2.c c-recon/src/rooms.c c-recon/src/draw.c
  c-recon/gen/objects_data.c c-recon/gen/rooms_data.c c-recon/gen/registry.c
  c-recon/gen/gml_*.c c-recon/gen/sprites.c
)

run_c_test() {
  local label=$1 binary=$2 expected=$3 source=$4 log=$5
  step "$label"
  if ! clang -std=c11 -O2 -ffp-contract=off -Wall -Ic-recon/include \
      "${C_SOURCES[@]}" "$source" -o "$ROOT/c-recon/build/$binary" -lm 2>"$log"; then
    echo "$binary clang build FAILED (see $log)"
    return 1
  fi
  local out rc
  out=$("$ROOT/c-recon/build/$binary" | tail -1); rc=$?
  echo "$out"
  if [ "$rc" -ne 0 ] || [ "$out" != "$expected" ]; then
    echo "$binary FAILED (rc=$rc; want: $expected)"
    return 1
  fi
  return 0
}

if ! run_c_test "1/8 C collision unit test" collision_test \
    "collision_test: 109 checks, 0 failed" \
    c-recon/tests/collision_test.c "$TMP/dev_smoke_c.log"; then
  fails=$((fails+1))
fi

if ! run_c_test "2/8 C object unit test" objects_test \
    "checks: 140, failures: 0" \
    c-recon/tests/objects_test.c "$TMP/dev_smoke_objects.log"; then
  fails=$((fails+1))
fi

if ! run_c_test "3/8 C with/destroy unit test" env_test \
    "env checks: 142, failures: 0" \
    c-recon/tests/env_test.c "$TMP/dev_smoke_env.log"; then
  fails=$((fails+1))
fi

if ! run_c_test "4/8 C room data/builtin unit test" rooms_test \
    "room checks: 29, failures: 0" \
    c-recon/tests/rooms_test.c "$TMP/dev_smoke_rooms.log"; then
  fails=$((fails+1))
fi

step "5/8 C<->VM with/destroy scenarios"
if clang -std=c11 -O2 -ffp-contract=off -Wall -Ic-recon/include \
    c-recon/src/main.c "${C_SOURCES[@]}" -o "$ROOT/c-recon/build/state_dump" -lm \
    2>"$TMP/dev_smoke_state_dump.log"; then
  out=$(python3 scripts/env_fanout_diff.py --c-bin c-recon/build/state_dump \
          --work "$TMP/env_fanout" 2>&1); rc=$?
  printf '%s\n' "$out"
  if [ "$rc" -ne 0 ] \
     || ! printf '%s\n' "$out" | grep -qF '[env] 6 scenarios: identical=6 differ=0 failed=0' \
     || ! printf '%s\n' "$out" | grep -qF '[env] expectations: 101/101 met' \
     || ! printf '%s\n' "$out" | grep -qF '[env] PASS'; then
    echo "environment scenarios FAILED (rc=$rc)"
    fails=$((fails+1))
  fi
else
  echo "state_dump clang build FAILED (see $TMP/dev_smoke_state_dump.log)"
  fails=$((fails+1))
fi

step "6/8 C<->VM draw command scenarios"
out=$(python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/draw \
        --c-bin c-recon/build/state_dump --work "$TMP/draw_commands" 2>&1); rc=$?
printf '%s\n' "$out"
if [ "$rc" -ne 0 ] \
   || ! printf '%s\n' "$out" | grep -qF '[env] 15 scenarios: identical=15 differ=0 failed=0' \
   || ! printf '%s\n' "$out" | grep -qF '[env] expectations: 60/60 met' \
   || ! printf '%s\n' "$out" | grep -qF '[env] PASS'; then
  echo "draw command scenarios FAILED (rc=$rc)"
  fails=$((fails+1))
fi

step "7/8 mask-base oracle probe"
if python3 c-recon/tools/oracle/base_probe.py 2>/dev/null | tail -3; then :; else
  echo "base_probe FAILED"
  fails=$((fails+1))
fi

step "8/8 Rust precise-collision suite (nextest)"
out=$(cargo nextest run -p callys-core --test precise_collision_masks_ir \
        --cargo-profile ci-test --no-fail-fast 2>&1); rc=$?
printf '%s\n' "$out" | grep -E "^ *Summary"
nsummary=$(printf '%s\n' "$out" | grep -cE '^ *Summary .*6 tests run: 6 passed, 0 skipped')
if [ "$rc" -ne 0 ] || [ "$nsummary" -ne 1 ]; then
  echo "nextest FAILED (rc=$rc)"
  fails=$((fails+1))
fi

if [ "${1:-}" = "--deep" ]; then
  step "deep: boss chain C<->VM corpus (284/156/157, all objects, 3 ticks)"
  # This invocation requests exactly CODE 284/156/157. Require three actual
  # comparisons, not merely a positive requested-body total: not_built and
  # vm_reject are not execution, and a missing requested id must not shrink 3→1.
  out=$(python3 scripts/batch_diff.py --build-c --only 284,156,157 --all-objects \
          --sequence --ticks 3 --work "$TMP/deep_boss" 2>&1); rc=$?
  printf '%s\n' "$out" | grep -E '^ *(identical|differ|c_gap|c_only|vm_reject|c_fail|not_built) *: *[0-9]+$'
  deep_bad=0
  for counter in differ c_gap c_only vm_reject c_fail not_built; do
    n=$(printf '%s\n' "$out" | grep -cE "^ *${counter} *: *0$")
    if [ "$n" -ne 1 ]; then
      echo "deep counter $counter: expected exactly one zero line, got $n"
      deep_bad=1
    fi
  done
  nbodies=$(printf '%s\n' "$out" | grep -cE '^=== 3 bodies ===$')
  nidentical=$(printf '%s\n' "$out" | grep -cE '^ *identical: 3$')
  if [ "$nbodies" -ne 1 ] || [ "$nidentical" -ne 1 ]; then
    echo "deep coverage: expected exactly 3 bodies and 3 identical, got $nbodies/$nidentical marker(s)"
    deep_bad=1
  fi
  if [ "$rc" -ne 0 ] || [ "$deep_bad" -ne 0 ]; then
    echo "deep corpus FAILED (rc=$rc)"
    fails=$((fails+1))
  fi

  step "deep: room warp C<->VM scenarios (9)"
  # Reuse the full-corpus C driver built above: every RoomCC/Create body is
  # present, so room coverage cannot silently degrade into C_MISSING_BODY.
  out=$(python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/rooms \
          --c-bin "$TMP/deep_boss/state_dump" --work "$TMP/room_warp" 2>&1); rc=$?
  printf '%s\n' "$out"
  if [ "$rc" -ne 0 ] \
     || ! printf '%s\n' "$out" | grep -qF '[env] 9 scenarios: identical=9 differ=0 failed=0' \
     || ! printf '%s\n' "$out" | grep -qF '[env] expectations: 79/79 met' \
     || ! printf '%s\n' "$out" | grep -qF '[env] PASS'; then
    echo "room warp scenarios FAILED (rc=$rc)"
    fails=$((fails+1))
  fi

  step "deep: real-room Draw command scenarios (4)"
  out=$(python3 scripts/env_fanout_diff.py --fixtures c-recon/fixtures/draw_full \
          --c-bin "$TMP/deep_boss/state_dump" --work "$TMP/draw_full" 2>&1); rc=$?
  printf '%s\n' "$out"
  if [ "$rc" -ne 0 ] \
     || ! printf '%s\n' "$out" | grep -qF '[env] 4 scenarios: identical=4 differ=0 failed=0' \
     || ! printf '%s\n' "$out" | grep -qF '[env] expectations: 24/24 met' \
     || ! printf '%s\n' "$out" | grep -qF '[env] PASS'; then
    echo "real-room Draw scenarios FAILED (rc=$rc)"
    fails=$((fails+1))
  fi

  step "deep: all 118 Draw bodies C<->VM command census"
  python3 -c 'import json,sys; b=json.load(open("crates/core/src/generated/full_ir.json")); ids=sorted({c for o in b["objects"] for e in o["events"] if e["event_type"]==8 for c in e["codes"]}); open(sys.argv[1],"w").write("\n".join(map(str,ids))+"\n")' \
    "$TMP/draw_code_ids.txt"
  out=$(python3 scripts/batch_diff.py --c-bin "$TMP/deep_boss/state_dump" \
          --sequence --all-objects --code-file "$TMP/draw_code_ids.txt" \
          --work "$TMP/deep_draw" 2>&1); rc=$?
  printf '%s\n' "$out" | grep -E '^ *(identical|differ|c_gap|c_only|vm_reject|c_fail|not_built) *: *[0-9]+$'
  deep_bad=0
  for counter in differ c_gap c_only vm_reject c_fail not_built; do
    n=$(printf '%s\n' "$out" | grep -cE "^ *${counter} *: *0$")
    if [ "$n" -ne 1 ]; then
      echo "Draw counter $counter: expected exactly one zero line, got $n"
      deep_bad=1
    fi
  done
  nbodies=$(printf '%s\n' "$out" | grep -cE '^=== 118 bodies ===$')
  nidentical=$(printf '%s\n' "$out" | grep -cE '^ *identical: 118$')
  if [ "$nbodies" -ne 1 ] || [ "$nidentical" -ne 1 ]; then
    echo "Draw coverage: expected exactly 118 bodies and 118 identical, got $nbodies/$nidentical marker(s)"
    deep_bad=1
  fi
  if [ "$rc" -ne 0 ] || [ "$deep_bad" -ne 0 ]; then
    echo "Draw corpus FAILED (rc=$rc)"
    fails=$((fails+1))
  fi
  if ! python3 scripts/draw_corpus_summary.py --work "$TMP/deep_draw"; then
    echo "Draw census/negative controls FAILED"
    fails=$((fails+1))
  fi
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
