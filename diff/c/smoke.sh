#!/bin/sh
# diff/c/smoke.sh — vm_ref 的 6 条自测用例（协议里程碑 1 的最小自检）
#
#   ./smoke.sh        # 建 → 跑 → 逐字节比 → 流式检查，退出码 0 = 全过
#
# 六条覆盖：int32+int32 / real+real / string+string 拼接 / 除零 / undefined 参与 /
#           tag 与声明类型不匹配（RValue 槽里放 Malformed tag）。
# 期望值是按逆向卡手算的，不是拿 vm_ref 自己的输出回填的：
#   cases/DoAdd.c    0x22→tag 7、0x00→tag 0、0x66→tag 1、0x25→Malformed variable
#   cases/DoDiv.c    整数除零 → VMError("DoDiv :: Divide by zero")，只写 tag 不写值
#   结果落点 sp = 右宽 + 左宽 - 结果宽（DoAdd 卡「结果落点」段）
set -u

cd "$(dirname "$0")" || exit 2
make -s || { echo "smoke: build failed"; exit 2; }

WORK=$(mktemp -d "${TMPDIR:-/tmp}/vmref-smoke.XXXXXX") || exit 2
trap 'rm -rf "$WORK"' EXIT INT TERM

# ── 输入：a=左操作数、b=右操作数、type=(左类<<4)|右类 ───────────────────────────
cat > "$WORK/cases.jsonl" <<'CASES'
{"id":1,"op":"add","mode":0,"type":34,"a":{"bytes":"07000000000000000000000007000000","tag":7},"b":{"bytes":"23000000000000000000000007000000","tag":7}}
{"id":2,"op":"add","mode":0,"type":0,"a":{"bytes":"000000000000f83f0000000000000000","tag":0},"b":{"bytes":"00000000000002400000000000000000","tag":0}}
{"id":3,"op":"add","mode":0,"type":102,"a":{"bytes":"31320000000000000000000001000000","tag":1},"b":{"bytes":"61626300000000000000000001000000","tag":1}}
{"id":4,"op":"div","mode":0,"type":34,"a":{"bytes":"0a000000000000000000000007000000","tag":7},"b":{"bytes":"00000000000000000000000007000000","tag":7}}
{"id":5,"op":"add","mode":0,"type":85,"a":{"bytes":"00000000000000000000000005000000","tag":5},"b":{"bytes":"00000000000000000000000005000000","tag":5}}
{"id":6,"op":"add","mode":0,"type":37,"a":{"bytes":"01000000000000000000000007000000","tag":7},"b":{"bytes":"00000000000000000000000004000000","tag":4}}
CASES

# ── 期望输出（逐字节，含 sp）─────────────────────────────────────────────────
cat > "$WORK/expected.jsonl" <<'EXPECTED'
{"id":1,"ok":true,"sp":4,"result":{"bytes":"2a000000000000000000000007000000","tag":7}}
{"id":2,"ok":true,"sp":8,"result":{"bytes":"0000000000000e400000000000000000","tag":0}}
{"id":3,"ok":true,"sp":-8,"result":{"bytes":"31326162630000000000000001000000","tag":1}}
{"id":4,"ok":false,"sp":0,"error":"DoDiv :: Divide by zero"}
{"id":5,"ok":false,"sp":0,"error":"DoAdd :: undefined value"}
{"id":6,"ok":false,"sp":0,"error":"DoAdd :: Malformed variable"}
EXPECTED

./vm_ref < "$WORK/cases.jsonl" > "$WORK/out.jsonl"
rc=$?
if [ "$rc" -ne 0 ]; then
    echo "smoke: vm_ref exited $rc"
    exit 1
fi

echo "== input (6 cases) =="
cat "$WORK/cases.jsonl"
echo
echo "== vm_ref stdout =="
cat "$WORK/out.jsonl"
echo
echo "== diff (expected vs actual) =="
if ! diff -u "$WORK/expected.jsonl" "$WORK/out.jsonl"; then
    echo "smoke: FAIL — 输出与手算期望不一致"
    exit 1
fi

lines=$(wc -l < "$WORK/out.jsonl" | tr -d ' ')
if [ "$lines" -ne 6 ]; then
    echo "smoke: FAIL — 期望 6 行输出，实际 $lines 行"
    exit 1
fi
echo "smoke: 6/6 PASS"

# ── 流式检查：只写一行、不关 stdin，结果必须在 1 s 内出现（不能缓冲到结束）──────
first=$(sed -n 1p "$WORK/cases.jsonl")
if ( printf '%s\n' "$first"; sleep 3 ) | timeout 1 ./vm_ref 2>/dev/null \
        | head -1 | grep -q '"ok":true'; then
    echo "smoke: streaming OK — 首行在 EOF 之前就已输出"
else
    echo "smoke: FAIL — 输出被缓冲到 stdin 结束"
    exit 1
fi

exit 0
