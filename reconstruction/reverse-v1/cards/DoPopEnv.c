/* cally 逆向卡：DoPopEnv（原版 libyoyo.so，armv7）
 * @func 0xd3840 0xd3968  size 296  74 条指令
 * 级别: 骨架（74 条全部解码；记录形态与每个返回点已定，0xF0 记录的产生方与 with 循环的字节码协议未定）
 * 符号: _Z8DoPopEnvjPhPKhP6VMExec → uchar* DoPopEnv(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   form = (arg >> 16) & 0xFF；form == 0xF0 → 0xF0 记录形态    ; d3840 / d3844 / d3850
 *   否则 w0 = *(uint32_t*)sp：-1 → 堆数组迭代；0 → 两字记录；其它 → 一字记录   ; d3854 / d3858 / d3860 / d3868
 *   一字记录：env1(exec+0x14) = w0；code = (exec[0x44]-4) + arg*4；entry = exec[0x5c][code>>2] → exec[0x48]；返回 sp+4
 *                                                  ; d386c..d38a0
 *     arg*4 = (arg<<9) asr 7；code>>2 用 "若负先加 3" 做零向取整（(code + (code<0?3:0)) asr 2）
 *                                                  ; d3870 / d3880 / d3888 / d3890 / d3894
 *   两字记录 [0, X]：env2(exec+0x18) = [sp]（=0），env1 = [sp+4]，返回 sp+8      ; d3928..d393c
 *   堆数组记录 [-1, end, base]：end = [sp+4]，base = [sp+8]，*--end
 *       非 0 → env1 = 该值，end 写回 [sp+4]，然后走一字记录的 code 回填，返回 sp+4     ; d38f4..d3908
 *       == 0 → MemoryManager::Free(base)，再 env2 = [sp+12]、env1 = [sp+16]、返回 sp+20 ; d390c..d3924 + d3928
 *   0xF0 记录：w0 = [sp]
 *       w0 == -1 → Free([sp+8])，再 env2 = [sp+12]、env1 = [sp+16]、返回 sp+20   ; d38ac..d38b8 / d3948..d3964
 *       w0 == 0  → env2 = [sp+4]、env1 = [sp+8]、返回 sp+12                      ; d38c4..d38e8
 *       w0 != 0/-1 → 从 sp+4 起逐字前进，跳过非 0 字，停在第一个 0 字 r0；env2 = [r0]、env1 = [r0+4]、返回 r0+8
 *                                                  ; d38bc..d38e8
 *   sp-8 的两个字只作跨 MemoryManager::Free 的 (exec, sp) 暂存        ; d384c / d3914 / d3918 / d3950 / d3954
 *
 * 结论：
 *   1. DoPopEnv 只做三件事：恢复 env1/env2（exec+0x14/+0x18）、把 exec[0x44]/[0x48]（码指针 + 当前表项）回填到
 *      操作数指定的位置、按记录形态决定消费 4/8/12/20 B。
 *   2. 记录形态由栈顶字自描述（-1 / 0 / 其它），只有 0xF0 形态需要操作数高位预告知 —— 这是全函数唯一读 arg 高 8 位的地方。
 *   3. `-1` 记录带堆数组，是 with 的"多实例"迭代面：每次只弹一个实例（end 递减写回），耗尽才 Free 并恢复外层 env；
 *      与 DoPushEnv 的 d5324/d5398 两处 Alloc 生成的 [-1, end, base] 记录严格互为逆操作。
 *   4. `0xF0` 与 [0, env2, env1] 三字记录一一对应：0xF0 恢复两个 env 字并消费 12 B，正好等于 DoPushEnv 从 sp-8 压出的那条。
 * open：谁产生 0xF0 记录（DoPushEnv 全函数没有写 0xF0 字面量）；0xF0 + w0∉{0,-1} 时"扫到 0 字"的分支对应哪种 with 形态；
 *       数组 [0]=0 的填充语义（DoPushEnv d5368 存的是上一轮的 r6，不是当前实例）。
 */

/* ── 段 1 · 序言 / form 位域（0xd3840..0xd3850） ── */
/* @0xd3840 ubfx r2, r0, #0x10, #0x8 */
/* @0xd3844 cmp r2, #240 */
/* @0xd3848 push {r4, lr} */
/* @0xd384c sub sp, sp, #8 */
/* @0xd3850 beq 0xd38ac <_Z8DoPopEnvjPhPKhP6VMExec+0x6c> */

/* ── 段 2 · 主分派：w0 = -1 / 0 / 其它（0xd3854..0xd38a8） ── */
/* @0xd3854 ldr r2, [r1] */
/* @0xd3858 cmn r2, #1 */
/* @0xd385c beq 0xd38f4 <_Z8DoPopEnvjPhPKhP6VMExec+0xb4> */
/* @0xd3860 cmp r2, #0 */
/* @0xd3864 add r1, r1, #4 */
/* @0xd3868 beq 0xd3928 <_Z8DoPopEnvjPhPKhP6VMExec+0xe8> */
/* @0xd386c ldr r4, [r3, #0x44] */
/* @0xd3870 lsl r0, r0, #9 */
/* @0xd3874 str r2, [r3, #0x14] */
/* @0xd3878 sub r4, r4, #4 */
/* @0xd387c ldr r12, [r3, #0x5c] */
/* @0xd3880 add r0, r4, r0, asr #7 */
/* @0xd3884 str r0, [r3, #0x44] */
/* @0xd3888 add r2, r0, #3 */
/* @0xd388c cmp r0, #0 */
/* @0xd3890 movlt r0, r2 */
/* @0xd3894 asr r0, r0, #2 */
/* @0xd3898 ldr r2, [r12, r0, lsl #2] */
/* @0xd389c mov r0, r1 */
/* @0xd38a0 str r2, [r3, #0x48] */
/* @0xd38a4 add sp, sp, #8 */
/* @0xd38a8 pop {r4, pc} */

/* ── 段 3 · 0xF0 记录形态 + 堆数组释放（0xd38ac..0xd38f0） ── */
/* @0xd38ac ldr r0, [r1] */
/* @0xd38b0 cmn r0, #1 */
/* @0xd38b4 bne 0xd38c4 <_Z8DoPopEnvjPhPKhP6VMExec+0x84> */
/* @0xd38b8 b 0xd3948 <_Z8DoPopEnvjPhPKhP6VMExec+0x108> */
/* @0xd38bc ldr r0, [r1, #0x4] */
/* @0xd38c0 mov r1, r2 */
/* @0xd38c4 cmp r0, #0 */
/* @0xd38c8 add r2, r1, #4 */
/* @0xd38cc mov r0, r2 */
/* @0xd38d0 bne 0xd38bc <_Z8DoPopEnvjPhPKhP6VMExec+0x7c> */
/* @0xd38d4 ldr r2, [r0] */
/* @0xd38d8 add r1, r0, #8 */
/* @0xd38dc str r2, [r3, #0x18] */
/* @0xd38e0 ldr r2, [r0, #0x4] */
/* @0xd38e4 mov r0, r1 */
/* @0xd38e8 str r2, [r3, #0x14] */
/* @0xd38ec add sp, sp, #8 */
/* @0xd38f0 pop {r4, pc} */

/* ── 段 4 · 堆数组迭代（-1 记录）：弹一个实例 / 耗尽则 Free（0xd38f4..d3924） ── */
/* @0xd38f4 ldr r12, [r1, #0x4] */
/* @0xd38f8 ldr r4, [r1, #0x8] */
/* @0xd38fc ldr r2, [r12, #-0x4]! */
/* @0xd3900 cmp r2, #0 */
/* @0xd3904 str r12, [r1, #0x4] */
/* @0xd3908 bne 0xd386c <_Z8DoPopEnvjPhPKhP6VMExec+0x2c> */
/* @0xd390c mov r0, r4 */
/* @0xd3910 add r1, r1, #12 */
/* @0xd3914 str r3, [sp] */
/* @0xd3918 str r1, [sp, #0x4] */
/* @0xd391c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3920 ldr r1, [sp, #0x4] */
/* @0xd3924 ldr r3, [sp] */

/* ── 段 5 · 两字记录收尾 + 0xF0 的 -1 分支（0xd3928..d3964） ── */
/* @0xd3928 ldr r2, [r1] */
/* @0xd392c add r1, r1, #8 */
/* @0xd3930 str r2, [r3, #0x18] */
/* @0xd3934 ldr r2, [r1, #-0x4] */
/* @0xd3938 mov r0, r1 */
/* @0xd393c str r2, [r3, #0x14] */
/* @0xd3940 add sp, sp, #8 */
/* @0xd3944 pop {r4, pc} */
/* @0xd3948 ldr r0, [r1, #0x8] */
/* @0xd394c str r1, [sp, #0x4] */
/* @0xd3950 str r3, [sp] */
/* @0xd3954 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd3958 ldr r1, [sp, #0x4] */
/* @0xd395c ldr r3, [sp] */
/* @0xd3960 add r0, r1, #12 */
/* @0xd3964 b 0xd38d4 <_Z8DoPopEnvjPhPKhP6VMExec+0x94> */
