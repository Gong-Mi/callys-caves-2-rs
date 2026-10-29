/* cally 逆向卡：DoSub —— GML 减法的数值塔（原版 libyoyo.so，armv7）
 * @func 0xdd500 0xddd68  size 2152  538 条
 * 级别: 正文（四条路径的算术指令、类型门、装箱写回偏移逐条落锚；非数值路径与错误串 open）
 * 符号 _Z5DoSubjPhPKhP6VMExec（arg, sp, base, VMExec*）—— 处理器签名与 DoAdd/DoMul 同型
 *
 * ── 已证的算术路径（2026-10-29 更正：实数路与整数路并存）───────────────
 *   A 实-实快路   0xdd918 vldr d6,[r10] / 0xdd91c vldr d7,[r9] / 0xdd920 vsub.f64 / 0xdd928 vstr → 结果 double
 *   B/C 单侧 int32 0xdd97c / 0xdd9b8 vcvt.f64.s32 → vsub.f64 → vstr（该支把 int32 提升成 double）
 *   D int64→double 0xdd9a4 / 0xdd9e0 vmov d,r0,r1 → vsub.f64
 *   E **整数路（64 位、带借位、会回绕）**：
 *        0xdd950 subs r4,r4,r2 / 0xdd954 sbc r5,r5,r3 / 0xdd958 strd r4,r5,[r8]   ← int64 - int64
 *        0xdda18 subs r2,r2,r1 / 0xdda1c sbc r3,r3,r1,asr #31 / 0xdda20 strd       ← int64 - sext32
 *        两处都先 mov r12,#10 ⇒ 结果 tag=10
 *   ⚠ 本卡第一版写「减法没有整型指令、整数一律提升成 double」是**错的**（只 grep 了 v*/助手，漏内联 subs/sbc）。
 *     已在指令现场更正（claims SUB-002 refuted）。
/* @0xdd500 ubfx r2, r0, #0x8, #0x4 */
/* @0xdd504 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdd508 cmp r2, #1 */
/* @0xdd50c lsr r5, r0, #16 */
/* @0xdd510 sub sp, sp, #68 */
/* @0xdd514 mov r9, r1 */
/* @0xdd518 mov r11, r3 */
/* @0xdd51c uxtb r4, r5 */
/* @0xdd520 beq 0xdda70 <_Z5DoSubjPhPKhP6VMExec+0x570> */
/* @0xdd524 and r2, r4, #15 */
/* @0xdd528 cmp r2, #6 */
/* @0xdd52c addls pc, pc, r2, lsl #2 */
/* @0xdd530 b 0xddd10 <_Z5DoSubjPhPKhP6VMExec+0x810> */
/* @0xdd534 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd538 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd53c b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd540 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd544 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd548 b 0xdd8c4 <_Z5DoSubjPhPKhP6VMExec+0x3c4> */
/* @0xdd54c b 0xdd550 <_Z5DoSubjPhPKhP6VMExec+0x50> */
/* @0xdd550 ldr r1, [pc, #0x7cc] */
/* @0xdd554 mov r0, r3 */
/* @0xdd558 mov r5, r4 */
/* @0xdd55c mov r10, r9 */
/* @0xdd560 add r1, pc, r1 */
/* @0xdd564 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd568 asr r2, r5, #4 */
/* @0xdd56c cmp r2, #6 */
/* @0xdd570 addls pc, pc, r2, lsl #2 */
/* @0xdd574 b 0xddd1c <_Z5DoSubjPhPKhP6VMExec+0x81c> */
/* @0xdd578 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd57c b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd580 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd584 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd588 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd58c b 0xdd854 <_Z5DoSubjPhPKhP6VMExec+0x354> */
/* @0xdd590 b 0xdd594 <_Z5DoSubjPhPKhP6VMExec+0x94> */
/* @0xdd594 ldr r1, [pc, #0x78c] */
/* @0xdd598 mov r0, r11 */
/* @0xdd59c mov r6, r10 */
/* @0xdd5a0 add r1, pc, r1 */
/* @0xdd5a4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd5a8 cmp r4, #101 */
/* @0xdd5ac addls pc, pc, r4, lsl #2 */
/* @0xdd5b0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5b4 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5b8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5bc b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5c0 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd5c4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5c8 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd5cc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5d8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5dc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5e8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5ec b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5f8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd5fc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd600 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd604 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd608 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd60c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd610 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd614 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd618 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd61c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd620 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd624 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd628 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd62c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd630 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd634 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd638 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd63c b 0xdd74c <_Z5DoSubjPhPKhP6VMExec+0x24c> */
/* @0xdd640 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd644 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd648 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd64c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd650 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd654 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd658 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd65c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd660 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd664 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd668 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd66c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd670 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd674 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd678 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd67c b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd680 b 0xdd844 <_Z5DoSubjPhPKhP6VMExec+0x344> */
/* @0xdd684 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd688 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd68c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd690 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd694 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd698 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd69c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6a8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6ac b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6b8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6bc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6c8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6cc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6d8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6dc b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e4 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6e8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6ec b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6f0 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6f4 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd6f8 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd6fc b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd700 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd704 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd708 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd70c b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd710 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd714 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd718 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd71c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd720 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd724 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd728 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd72c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd730 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd734 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd738 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd73c b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd740 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd744 b 0xdd90c <_Z5DoSubjPhPKhP6VMExec+0x40c> */
/* @0xdd748 b 0xdd834 <_Z5DoSubjPhPKhP6VMExec+0x334> */
/* @0xdd74c sub r6, r6, #4 */
/* @0xdd750 mov r7, #0 */
/* @0xdd754 mov r8, r6 */
/* @0xdd758 cmp r5, #51 */
/* @0xdd75c addls pc, pc, r5, lsl #2 */
/* @0xdd760 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd764 b 0xdd918 <_Z5DoSubjPhPKhP6VMExec+0x418> */
/* @0xdd768 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd76c b 0xdd9b4 <_Z5DoSubjPhPKhP6VMExec+0x4b4> */
/* @0xdd770 b 0xdd994 <_Z5DoSubjPhPKhP6VMExec+0x494> */
/* @0xdd774 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd778 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd77c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd780 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd784 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd788 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd78c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd790 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd794 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd798 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd79c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7a8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7ac b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7b8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7bc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7c8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7cc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7d8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7dc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7e0 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7e4 b 0xdd978 <_Z5DoSubjPhPKhP6VMExec+0x478> */
/* @0xdd7e8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7ec b 0xdd960 <_Z5DoSubjPhPKhP6VMExec+0x460> */
/* @0xdd7f0 b 0xdd9f0 <_Z5DoSubjPhPKhP6VMExec+0x4f0> */
/* @0xdd7f4 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7f8 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd7fc b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd800 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd804 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd808 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd80c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd810 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd814 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd818 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd81c b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd820 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd824 b 0xdd9d0 <_Z5DoSubjPhPKhP6VMExec+0x4d0> */
/* @0xdd828 b 0xdda28 <_Z5DoSubjPhPKhP6VMExec+0x528> */
/* @0xdd82c b 0xdda0c <_Z5DoSubjPhPKhP6VMExec+0x50c> */
/* @0xdd830 b 0xdd944 <_Z5DoSubjPhPKhP6VMExec+0x444> */
/* @0xdd834 sub r7, r6, #16 */
/* @0xdd838 mov r8, r7 */
/* @0xdd83c mov r6, r7 */
/* @0xdd840 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd844 sub r6, r6, #8 */
/* @0xdd848 mov r7, #0 */
/* @0xdd84c mov r8, r6 */
/* @0xdd850 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd854 ldr r3, [r10, #0xc] */
/* @0xdd858 cmp r3, #13 */
/* @0xdd85c addls pc, pc, r3, lsl #2 */
/* @0xdd860 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd864 b 0xddc88 <_Z5DoSubjPhPKhP6VMExec+0x788> */
/* @0xdd868 b 0xddc74 <_Z5DoSubjPhPKhP6VMExec+0x774> */
/* @0xdd86c b 0xddc60 <_Z5DoSubjPhPKhP6VMExec+0x760> */
/* @0xdd870 b 0xddc4c <_Z5DoSubjPhPKhP6VMExec+0x74c> */
/* @0xdd874 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd878 b 0xddc38 <_Z5DoSubjPhPKhP6VMExec+0x738> */
/* @0xdd87c b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd880 b 0xddc2c <_Z5DoSubjPhPKhP6VMExec+0x72c> */
/* @0xdd884 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd888 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd88c b 0xddc1c <_Z5DoSubjPhPKhP6VMExec+0x71c> */
/* @0xdd890 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd894 b 0xddcb8 <_Z5DoSubjPhPKhP6VMExec+0x7b8> */
/* @0xdd898 b 0xddc88 <_Z5DoSubjPhPKhP6VMExec+0x788> */
/* @0xdd89c add r6, r10, #4 */
/* @0xdd8a0 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8a4 add r6, r10, #8 */
/* @0xdd8a8 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8ac add r10, r1, #8 */
/* @0xdd8b0 mov r5, r4 */
/* @0xdd8b4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8b8 add r10, r1, #4 */
/* @0xdd8bc mov r5, r4 */
/* @0xdd8c0 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8c4 ldr r3, [r1, #0xc] */
/* @0xdd8c8 cmp r3, #13 */
/* @0xdd8cc addls pc, pc, r3, lsl #2 */
/* @0xdd8d0 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8d4 b 0xddc14 <_Z5DoSubjPhPKhP6VMExec+0x714> */
/* @0xdd8d8 b 0xddbfc <_Z5DoSubjPhPKhP6VMExec+0x6fc> */
/* @0xdd8dc b 0xddbe4 <_Z5DoSubjPhPKhP6VMExec+0x6e4> */
/* @0xdd8e0 b 0xddbcc <_Z5DoSubjPhPKhP6VMExec+0x6cc> */
/* @0xdd8e4 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8e8 b 0xddbb4 <_Z5DoSubjPhPKhP6VMExec+0x6b4> */
/* @0xdd8ec b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8f0 b 0xddba8 <_Z5DoSubjPhPKhP6VMExec+0x6a8> */
/* @0xdd8f4 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8f8 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd8fc b 0xddb98 <_Z5DoSubjPhPKhP6VMExec+0x698> */
/* @0xdd900 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd904 b 0xddca0 <_Z5DoSubjPhPKhP6VMExec+0x7a0> */
/* @0xdd908 b 0xddc14 <_Z5DoSubjPhPKhP6VMExec+0x714> */
/* @0xdd90c mov r8, #0 */
/* @0xdd910 mov r7, r8 */
/* @0xdd914 b 0xdd758 <_Z5DoSubjPhPKhP6VMExec+0x258> */
/* @0xdd918 vldr d6, [r10] */
/* @0xdd91c vldr d7, [r9] */
/* @0xdd920 vsub.f64 d7, d6, d7 */
/* @0xdd924 mov r12, #0 */
/* @0xdd928 vstr d7, [r8] */
/* @0xdd92c cmp r7, #0 */
/* @0xdd930 beq 0xdda64 <_Z5DoSubjPhPKhP6VMExec+0x564> */
/* @0xdd934 mov r0, r6 */
/* @0xdd938 str r12, [r7, #0xc] */
/* @0xdd93c add sp, sp, #68 */
/* @0xdd940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdd944 ldrd r4, r5, [r10] */
/* @0xdd948 mov r12, #10 */
/* @0xdd94c ldrd r2, r3, [r9] */
/* @0xdd950 subs r4, r4, r2 */
/* @0xdd954 sbc r5, r5, r3 */
/* @0xdd958 strd r4, r5, [r8] */
/* @0xdd95c b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd960 ldr r2, [r10] */
/* @0xdd964 mov r12, #7 */
/* @0xdd968 ldr r3, [r9] */
/* @0xdd96c rsb r3, r3, r2 */
/* @0xdd970 str r3, [r8] */
/* @0xdd974 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd978 vldr s14, [r10] */
/* @0xdd97c vcvt.f64.s32 d7, s14 */
/* @0xdd980 vldr d6, [r9] */
/* @0xdd984 mov r12, #0 */
/* @0xdd988 vsub.f64 d7, d7, d6 */
/* @0xdd98c vstr d7, [r8] */
/* @0xdd990 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd994 ldrd r0, r1, [r9] */
/* @0xdd998 bl 0x319164 <__floatdidf> */
/* @0xdd99c vldr d7, [r10] */
/* @0xdd9a0 mov r12, #0 */
/* @0xdd9a4 vmov d5, r0, r1 */
/* @0xdd9a8 vsub.f64 d7, d7, d5 */
/* @0xdd9ac vstr d7, [r8] */
/* @0xdd9b0 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9b4 vldr s14, [r9] */
/* @0xdd9b8 vcvt.f64.s32 d7, s14 */
/* @0xdd9bc vldr d6, [r10] */
/* @0xdd9c0 mov r12, #0 */
/* @0xdd9c4 vsub.f64 d7, d6, d7 */
/* @0xdd9c8 vstr d7, [r8] */
/* @0xdd9cc b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9d0 ldrd r0, r1, [r10] */
/* @0xdd9d4 bl 0x319164 <__floatdidf> */
/* @0xdd9d8 vldr d7, [r9] */
/* @0xdd9dc mov r12, #0 */
/* @0xdd9e0 vmov d6, r0, r1 */
/* @0xdd9e4 vsub.f64 d7, d6, d7 */
/* @0xdd9e8 vstr d7, [r8] */
/* @0xdd9ec b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdd9f0 ldr r1, [r10] */
/* @0xdd9f4 mov r12, #10 */
/* @0xdd9f8 ldrd r2, r3, [r9] */
/* @0xdd9fc rsbs r2, r2, r1 */
/* @0xdda00 rsc r3, r3, r1, asr #31 */
/* @0xdda04 strd r2, r3, [r8] */
/* @0xdda08 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda0c ldr r1, [r9] */
/* @0xdda10 mov r12, #10 */
/* @0xdda14 ldrd r2, r3, [r10] */
/* @0xdda18 subs r2, r2, r1 */
/* @0xdda1c sbc r3, r3, r1, asr #31 */
/* @0xdda20 strd r2, r3, [r8] */
/* @0xdda24 b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda28 ldr r1, [pc, #0x2fc] */
/* @0xdda2c mov r0, r11 */
/* @0xdda30 add r1, pc, r1 */
/* @0xdda34 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdda38 mov r12, #0 */
/* @0xdda3c b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda40 ldr r0, [pc, #0x2e8] */
/* @0xdda44 add r0, pc, r0 */
/* @0xdda48 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdda4c ldr r3, [sp, #0x2c] */
/* @0xdda50 sub r3, r3, #1 */
/* @0xdda54 bic r3, r3, #-16777216 */
/* @0xdda58 bic r3, r3, #3 */
/* @0xdda5c cmp r3, #0 */
/* @0xdda60 beq 0xddc90 <_Z5DoSubjPhPKhP6VMExec+0x790> */
/* @0xdda64 mov r0, r6 */
/* @0xdda68 add sp, sp, #68 */
/* @0xdda6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdda70 add r5, sp, #16 */
/* @0xdda74 mov r2, r1 */
/* @0xdda78 and r1, r4, #15 */
/* @0xdda7c mov r0, r5 */
/* @0xdda80 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdda84 lsr r1, r4, #4 */
/* @0xdda88 mov r2, r0 */
/* @0xdda8c mov r0, sp */
/* @0xdda90 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdda94 ldr r3, [sp, #0xc] */
/* @0xdda98 mvn r12, #-16777216 */
/* @0xdda9c and r3, r3, r12 */
/* @0xddaa0 cmp r3, r12 */
/* @0xddaa4 mov r6, r0 */
/* @0xddaa8 beq 0xddce0 <_Z5DoSubjPhPKhP6VMExec+0x7e0> */
/* @0xddaac ldr r3, [sp, #0x1c] */
/* @0xddab0 bic r3, r3, #-16777216 */
/* @0xddab4 cmp r3, r12 */
/* @0xddab8 beq 0xddccc <_Z5DoSubjPhPKhP6VMExec+0x7cc> */
/* @0xddabc add r4, sp, #32 */
/* @0xddac0 mov r1, sp */
/* @0xddac4 mov r2, #0 */
/* @0xddac8 mov r3, #0 */
/* @0xddacc mov r0, r4 */
/* @0xddad0 str r12, [sp, #0x2c] */
/* @0xddad4 str r12, [sp, #0x3c] */
/* @0xddad8 mov r12, #0 */
/* @0xddadc strd r2, r3, [sp, #32] */
/* @0xddae0 strd r2, r3, [sp, #48] */
/* @0xddae4 str r12, [sp, #0x28] */
/* @0xddae8 str r12, [sp, #0x38] */
/* @0xddaec bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xddaf0 cmp r0, #1 */
/* @0xddaf4 beq 0xddcf4 <_Z5DoSubjPhPKhP6VMExec+0x7f4> */
/* @0xddaf8 cmp r0, #0 */
/* @0xddafc bne 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddb00 add r7, sp, #48 */
/* @0xddb04 mov r1, r5 */
/* @0xddb08 mov r0, r7 */
/* @0xddb0c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xddb10 cmp r0, #1 */
/* @0xddb14 beq 0xdda40 <_Z5DoSubjPhPKhP6VMExec+0x540> */
/* @0xddb18 cmp r0, #0 */
/* @0xddb1c bne 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddb20 str r0, [r6, #-0x4] */
/* @0xddb24 sub r5, r6, #16 */
/* @0xddb28 vldr d6, [sp, #32] */
/* @0xddb2c vldr d7, [sp, #48] */
/* @0xddb30 vsub.f64 d5, d6, d7 */
/* @0xddb34 ldr r1, [sp, #0x2c] */
/* @0xddb38 sub r1, r1, #1 */
/* @0xddb3c bic r1, r1, #-16777216 */
/* @0xddb40 bic r1, r1, #3 */
/* @0xddb44 cmp r1, #0 */
/* @0xddb48 vmov r2, r3, d5 */
/* @0xddb4c vstr s10, [r6, #-16] */
/* @0xddb50 str r3, [r6, #-0xc] */
/* @0xddb54 beq 0xddd04 <_Z5DoSubjPhPKhP6VMExec+0x804> */
/* @0xddb58 ldr r1, [sp, #0x3c] */
/* @0xddb5c mov r3, #0 */
/* @0xddb60 str r3, [sp, #0x28] */
/* @0xddb64 mov r2, #5 */
/* @0xddb68 sub r1, r1, #1 */
/* @0xddb6c str r3, [sp, #0x20] */
/* @0xddb70 bic r3, r1, #-16777216 */
/* @0xddb74 str r2, [sp, #0x2c] */
/* @0xddb78 bic r3, r3, #3 */
/* @0xddb7c cmp r3, #0 */
/* @0xddb80 movne r0, r5 */
/* @0xddb84 bne 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddb88 mov r0, r7 */
/* @0xddb8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddb90 mov r0, r5 */
/* @0xddb94 b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddb98 and r5, r5, #240 */
/* @0xddb9c orr r5, r5, #3 */
/* @0xddba0 add r10, r9, #16 */
/* @0xddba4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xddba8 and r5, r5, #240 */
/* @0xddbac orr r5, r5, #2 */
/* @0xddbb0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbb4 ldr r1, [pc, #0x178] */
/* @0xddbb8 mov r0, r11 */
/* @0xddbbc mov r5, r4 */
/* @0xddbc0 add r1, pc, r1 */
/* @0xddbc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbc8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbcc ldr r1, [pc, #0x164] */
/* @0xddbd0 mov r0, r11 */
/* @0xddbd4 mov r5, r4 */
/* @0xddbd8 add r1, pc, r1 */
/* @0xddbdc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbe0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbe4 ldr r1, [pc, #0x150] */
/* @0xddbe8 mov r0, r11 */
/* @0xddbec mov r5, r4 */
/* @0xddbf0 add r1, pc, r1 */
/* @0xddbf4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbf8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbfc ldr r1, [pc, #0x13c] */
/* @0xddc00 mov r0, r11 */
/* @0xddc04 mov r5, r4 */
/* @0xddc08 add r1, pc, r1 */
/* @0xddc0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc10 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddc14 and r5, r4, #240 */
/* @0xddc18 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddc1c and r5, r5, #15 */
/* @0xddc20 orr r5, r5, #48 */
/* @0xddc24 add r6, r10, #16 */
/* @0xddc28 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xddc2c and r5, r5, #15 */
/* @0xddc30 orr r5, r5, #32 */
/* @0xddc34 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc38 ldr r1, [pc, #0x104] */
/* @0xddc3c mov r0, r11 */
/* @0xddc40 add r1, pc, r1 */
/* @0xddc44 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc48 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc4c ldr r1, [pc, #0xf4] */
/* @0xddc50 mov r0, r11 */
/* @0xddc54 add r1, pc, r1 */
/* @0xddc58 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc5c b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc60 ldr r1, [pc, #0xe4] */
/* @0xddc64 mov r0, r11 */
/* @0xddc68 add r1, pc, r1 */
/* @0xddc6c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc70 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc74 ldr r1, [pc, #0xd4] */
/* @0xddc78 mov r0, r11 */
/* @0xddc7c add r1, pc, r1 */
/* @0xddc80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc84 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc88 and r5, r5, #15 */
/* @0xddc8c b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc90 mov r0, r4 */
/* @0xddc94 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddc98 mov r0, r6 */
/* @0xddc9c b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddca0 ldr r1, [pc, #0xac] */
/* @0xddca4 mov r0, r11 */
/* @0xddca8 mov r5, r4 */
/* @0xddcac add r1, pc, r1 */
/* @0xddcb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcb4 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddcb8 ldr r1, [pc, #0x98] */
/* @0xddcbc mov r0, r11 */
/* @0xddcc0 add r1, pc, r1 */
/* @0xddcc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcc8 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddccc ldr r0, [pc, #0x88] */
/* @0xddcd0 add r0, pc, r0 */
/* @0xddcd4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcd8 mov r0, r6 */
/* @0xddcdc b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddce0 ldr r0, [pc, #0x78] */
/* @0xddce4 add r0, pc, r0 */
/* @0xddce8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcec mov r0, r6 */
/* @0xddcf0 b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddcf4 ldr r0, [pc, #0x68] */
/* @0xddcf8 add r0, pc, r0 */
/* @0xddcfc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xddd00 b 0xdda4c <_Z5DoSubjPhPKhP6VMExec+0x54c> */
/* @0xddd04 mov r0, r4 */
/* @0xddd08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xddd0c b 0xddb58 <_Z5DoSubjPhPKhP6VMExec+0x658> */
/* @0xddd10 mov r5, r4 */
/* @0xddd14 mov r10, r1 */
/* @0xddd18 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xddd1c mov r6, r10 */
/* @0xddd20 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xddd24 eoreq r5, r5, r12, asr #22 */
/* @0xddd28 eoreq r5, r5, r12, lsl #22 */
/* @0xddd2c eoreq r5, r5, r8, lsr #15 */
/* @0xddd30 eoreq r5, r5, r0, lsr #12 */
/* @0xddd34 eoreq r5, r5, r8, asr #10 */
/* @0xddd38 eoreq r5, r5, r0, lsl r5 */
/* @0xddd3c eoreq r5, r5, r4, lsr r5 */
/* @0xddd40 eoreq r5, r5, r4, lsr #9 */
/* @0xddd44 eoreq r5, r5, r0, asr #10 */
/* @0xddd48 eoreq r5, r5, r12, lsl #10 */
/* @0xddd4c eoreq r5, r5, r4, lsr r5 */
/* @0xddd50 eoreq r5, r5, r0, lsr r4 */
/* @0xddd54 mlaeq r5, r4, r4, r5 */
/* @0xddd58 .word 0x002554f8 */
/* @0xddd5c eoreq r5, r5, r8, lsr #6 */
/* @0xddd60 .word 0x002552f0 */
/* @0xddd64 eoreq r5, r5, r4, lsr #6 */
