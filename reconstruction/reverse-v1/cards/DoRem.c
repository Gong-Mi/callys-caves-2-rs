/* cally 逆向卡：DoRem（原版 libyoyo.so，armv7）
 * @func 0xd4304 0xd4a34  size 1840  460 条指令（含 literal 词）
 * 级别: 骨架（格式码分派 / 9 条内核 + 6 处除零检查 / 全部错误分支已证；"写回商"与函数名不符一处已记入 open，不升正文）
 * 符号: _Z5DoRemjPhPKhP6VMExec → uchar* DoRem(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   与 DoSub/DoDiv 最大的差别：**没有 bits[11:8] 慢路径**，第一条就取类型字节：@0xd4304 lsr r0, r0, #16 —— 函数入口无 tst/ubfx 开关
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt（高 nibble=A）：@0xd4310 uxtb r4, r0 —— uxtb；@0xd4318 and r3, r4, #15 —— 取低 nibble（B 的格式码）
 *   表1 按 B 的格式码定 A 的地址：B 8 字节(0/3)→A=arg2+8，4 字节(1/2/4)→A=arg2+4：@0xd4320 cmp r3, #6 —— 上界 6；@0xd4324 addls pc, pc, r3, lsl #2 —— 7 项表；@0xd46b8 add r8, r1, #8 —— A=arg2+8
 *   表2 按 A 的格式码算 r6=A+4 / A+8：@0xd4368 addls pc, pc, r3, lsl #2 —— 第二级表；@0xd4654 add r6, r8, #4 —— r6=A+4
 *   B（除数）固定读 [arg2]、A（被除数）读 arg2+4/arg2+8：@0xd46d0 ldrd r2, r3, [r11] —— ldrd r2,r3,[r11]，r11=arg2
 *   表3 按整字节（0..85）→ dest，逐项等价于 dest=A+size(A)−max(size(A),size(B))：@0xd43a0 cmp r4, #85 —— 上界 85；@0xd43a4 addls pc, pc, r4, lsl #2 —— 86 项表
 *   表4 按同一字节（0..51）→ 9 条内核：@0xd4510 cmp r5, #51 —— 上界 51；@0xd4514 addls pc, pc, r5, lsl #2 —— 52 项表
 *   结果 tag：0=double、7=int32、10=int64，只在 r7≠0 时写 [r7+0xc]：@0xd46f8 strne r3, [r7, #0xc] —— 条件写
 *   只有一个出口，且要 vpop d8：@0xd430c vpush {d8} —— vpush d8；@0xd46ec vpop {d8} —— 唯一返回点
 *   int32÷int32：判零后 __divsi3：@0xd478c cmp r1, #0 —— 判零；@0xd4790 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> —— 为零跳 0xd48ac；@0xd4798 bl 0x318d10 <__divsi3> —— 调 __divsi3
 *   int64÷int64：orrs 判两字后 __aeabi_ldivmod：@0xd46d4 orrs r1, r2, r3 —— 判零；@0xd46d8 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> —— 为零跳；@0xd46e0 bl 0x319414 <__aeabi_ldivmod> —— 调 __aeabi_ldivmod
 *   除零落地只写 tag 不写值：@0xd48ac ldr r1, [pc, #0x154] —— VMError('DoRem :: Divide by zero')；随后 tag=0
 *   实数除数的"零"是**截断后为 0**：先 vabs 再 vcvt.s32.f64 判零：@0xd4728 vabs.f64 d6, d7 —— vabs；@0xd472c vcvt.s32.f64 s12, d6 —— 转 int32 判零
 *
 * 结论（新增 4 条硬事实）：
 *   1. DoRem 是这六个里唯一**没有 JS 强制转换慢路径**的一个：无 bits[11:8] 分支，也不调 boxType / F_JS_ToNumber /
 *      F_JS_ToInt32；格式码 5 的变量直接靠 tag 表转成 real/int32/int64 或报错。
 *   2. 名字与实现不符：9 条内核写回的都是**商**——@0xd46e8 strd r0, r1, [r9] 取 __aeabi_ldivmod 的 r0:r1、int32 走 __divsi3、
 *      real 先 __fixdfdi 截断再整数除、最后转回 double。真正取余的应是同库的 DoMod(0xde5e8)。
 *   3. 除零判定按宽度分三级：int32 查 1 字、int64 用 orrs 查 2 字、real 先 vabs 再 vcvt.s32.f64 查"|B| 截断是否 0"，
 *      所以 |B|<1 的实数除数也被当除零报错（0.5 也算）。
 *   4. 所有失败汇到单一出口 0xd46ec：只写 tag(0)、不改结果值，然后 vpop d8 + pop 10 个寄存器返回。
 * 备注：本卡把**高 nibble**(bits[23:20]) 记为 A（左操作数）、低 nibble(bits[19:16]) 记为 B。这个左右顺序不是猜的——
 *   减法用 rsb/subs 取 A−B、除法用 vdiv 取 A/B、取余用 __divsi3(A,B)、移位用 lsl 把 A 当被移位值，四处非对称指令
 *   一起把方向钉死；同批 DoShr/DoMul/DoMod/DoOr 的卡因运算符可交换而把低位 nibble 记作 opA，两者描述的是同一组槽位。
 * open：
 *   · 既然写回商，DoRem 对应的应是 div 而不是 mod；DoMod(0xde5e8) 未在本轮取证，两者分工待定。
 *   · 格式码 5 路径里 A 的落点前后出现 arg2+16 与 arg2+4/+8 两种写法（0xd4928 vs 0xd46ac），未统一解释。
 *   · 返回值是"新 sp"还是"新 ip"未定；尾部 0xd49fc..0xd4a30 是 literal pool（objdump 译成 eoreq/strhteq），逐字保留。
 */
/* @0xd4304 lsr r0, r0, #16 */
/* @0xd4308 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd430c vpush {d8} */
/* @0xd4310 uxtb r4, r0 */
/* @0xd4314 mov r10, r3 */
/* @0xd4318 and r3, r4, #15 */
/* @0xd431c mov r11, r1 */
/* @0xd4320 cmp r3, #6   ——表1 上界 6 */
/* @0xd4324 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xd46b8, 1-2→0xd46ac, 3→0xd46b8, 4→0xd46ac, 5→0xd4664, 6→0xd4348 */
/* @0xd4328 b 0xd49e8 <_Z5DoRemjPhPKhP6VMExec+0x6e4> */
/* @0xd432c b 0xd46b8 <_Z5DoRemjPhPKhP6VMExec+0x3b4> */
/* @0xd4330 b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4334 b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4338 b 0xd46b8 <_Z5DoRemjPhPKhP6VMExec+0x3b4> */
/* @0xd433c b 0xd46ac <_Z5DoRemjPhPKhP6VMExec+0x3a8> */
/* @0xd4340 b 0xd4664 <_Z5DoRemjPhPKhP6VMExec+0x360> */
/* @0xd4344 b 0xd4348 <_Z5DoRemjPhPKhP6VMExec+0x44> */
/* @0xd4348 ldr r1, [pc, #0x6ac]   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xd434c mov r0, r10 */
/* @0xd4350 mov r5, r4 */
/* @0xd4354 mov r8, r11 */
/* @0xd4358 add r1, pc, r1 */
/* @0xd435c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4360 asr r3, r5, #4 */
/* @0xd4364 cmp r3, #6 */
/* @0xd4368 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xd465c, 1-2→0xd4654, 3→0xd465c, 4→0xd4654, 5→0xd460c, 6→0xd438c */
/* @0xd436c b 0xd49f4 <_Z5DoRemjPhPKhP6VMExec+0x6f0> */
/* @0xd4370 b 0xd465c <_Z5DoRemjPhPKhP6VMExec+0x358> */
/* @0xd4374 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd4378 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd437c b 0xd465c <_Z5DoRemjPhPKhP6VMExec+0x358> */
/* @0xd4380 b 0xd4654 <_Z5DoRemjPhPKhP6VMExec+0x350> */
/* @0xd4384 b 0xd460c <_Z5DoRemjPhPKhP6VMExec+0x308> */
/* @0xd4388 b 0xd438c <_Z5DoRemjPhPKhP6VMExec+0x88> */
/* @0xd438c ldr r1, [pc, #0x66c]   ——Afmt=6 → VMError */
/* @0xd4390 mov r0, r10 */
/* @0xd4394 mov r6, r8 */
/* @0xd4398 add r1, pc, r1 */
/* @0xd439c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd43a0 cmp r4, #85 */
/* @0xd43a4 addls pc, pc, r4, lsl #2   ——表：按 r4 0→0xd45fc, 1→0xd46c4, 2-3→0xd45fc, 4→0xd46c4, 5→0xd45ec, 6-31→0xd46c4, 32→0xd45fc, 33→0xd46c4, 34→0xd4504, 35→0xd45fc, 36→0xd46c4, 37→0xd45ec, 38-47→0xd46c4, 48→0xd45fc, 49→0xd46c4, 50-51→0xd45fc, 52→0xd46c4, 53→0xd45ec, 54-79→0xd46c4, 80→0xd45ec, 81→0xd46c4, 82-83→0xd45ec, 84→0xd46c4, 85→0xd45ec */
/* @0xd43a8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43ac b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43b0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43b4 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43b8 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd43bc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43c0 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd43c4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43c8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43cc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43d8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43dc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43e8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43ec b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43f8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd43fc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4400 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4404 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4408 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd440c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4410 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4414 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4418 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd441c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4420 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4424 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4428 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd442c b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4430 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4434 b 0xd4504 <_Z5DoRemjPhPKhP6VMExec+0x200> */
/* @0xd4438 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd443c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4440 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4444 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4448 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd444c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4450 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4454 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4458 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd445c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4460 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4464 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4468 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd446c b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4470 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4474 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd4478 b 0xd45fc <_Z5DoRemjPhPKhP6VMExec+0x2f8> */
/* @0xd447c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4480 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4484 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4488 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd448c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4490 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4494 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4498 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd449c b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44a8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44ac b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44b8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44bc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44c8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44cc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44d8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44dc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e4 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44e8 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44ec b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44f0 b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd44f4 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44f8 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd44fc b 0xd46c4 <_Z5DoRemjPhPKhP6VMExec+0x3c0> */
/* @0xd4500 b 0xd45ec <_Z5DoRemjPhPKhP6VMExec+0x2e8> */
/* @0xd4504 sub r6, r6, #4   ——dest=r6-4 */
/* @0xd4508 mov r7, #0 */
/* @0xd450c mov r9, r6 */
/* @0xd4510 cmp r5, #51 */
/* @0xd4514 addls pc, pc, r5, lsl #2   ——表：按 r5 0→0xd4840, 1→0xd4894, 2→0xd4810, 3→0xd47e4, 4-31→0xd4894, 32→0xd47a8, 33→0xd4894, 34→0xd4788, 35→0xd4764, 36-47→0xd4894, 48→0xd4724, 49→0xd4894, 50→0xd4700, 51→0xd46d0 */
/* @0xd4518 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd451c b 0xd4840 <_Z5DoRemjPhPKhP6VMExec+0x53c> */
/* @0xd4520 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4524 b 0xd4810 <_Z5DoRemjPhPKhP6VMExec+0x50c> */
/* @0xd4528 b 0xd47e4 <_Z5DoRemjPhPKhP6VMExec+0x4e0> */
/* @0xd452c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4530 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4534 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4538 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd453c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4540 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4544 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4548 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd454c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4550 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4554 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4558 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd455c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4560 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4564 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4568 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd456c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4570 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4574 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4578 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd457c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4580 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4584 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4588 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd458c b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4590 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4594 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd4598 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd459c b 0xd47a8 <_Z5DoRemjPhPKhP6VMExec+0x4a4> */
/* @0xd45a0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45a4 b 0xd4788 <_Z5DoRemjPhPKhP6VMExec+0x484> */
/* @0xd45a8 b 0xd4764 <_Z5DoRemjPhPKhP6VMExec+0x460> */
/* @0xd45ac b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45b8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45bc b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45c8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45cc b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d4 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45d8 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45dc b 0xd4724 <_Z5DoRemjPhPKhP6VMExec+0x420> */
/* @0xd45e0 b 0xd4894 <_Z5DoRemjPhPKhP6VMExec+0x590> */
/* @0xd45e4 b 0xd4700 <_Z5DoRemjPhPKhP6VMExec+0x3fc> */
/* @0xd45e8 b 0xd46d0 <_Z5DoRemjPhPKhP6VMExec+0x3cc> */
/* @0xd45ec sub r7, r6, #16   ——dest=r6-16（r7 写 tag） */
/* @0xd45f0 mov r9, r7 */
/* @0xd45f4 mov r6, r7 */
/* @0xd45f8 b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd45fc sub r6, r6, #8   ——dest=r6-8（r7=0） */
/* @0xd4600 mov r7, #0 */
/* @0xd4604 mov r9, r6 */
/* @0xd4608 b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd460c ldr r3, [r8, #0xc] */
/* @0xd4610 cmp r3, #13 */
/* @0xd4614 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xd48c4, 1→0xd48d0, 2→0xd48e4, 3→0xd48f8, 4→0xd49d4, 5→0xd490c, 6→0xd49d4, 7→0xd493c, 8-9→0xd49d4, 10→0xd4948, 11-12→0xd49d4, 13→0xd48c4 */
/* @0xd4618 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd461c b 0xd48c4 <_Z5DoRemjPhPKhP6VMExec+0x5c0> */
/* @0xd4620 b 0xd48d0 <_Z5DoRemjPhPKhP6VMExec+0x5cc> */
/* @0xd4624 b 0xd48e4 <_Z5DoRemjPhPKhP6VMExec+0x5e0> */
/* @0xd4628 b 0xd48f8 <_Z5DoRemjPhPKhP6VMExec+0x5f4> */
/* @0xd462c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4630 b 0xd490c <_Z5DoRemjPhPKhP6VMExec+0x608> */
/* @0xd4634 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4638 b 0xd493c <_Z5DoRemjPhPKhP6VMExec+0x638> */
/* @0xd463c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4640 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4644 b 0xd4948 <_Z5DoRemjPhPKhP6VMExec+0x644> */
/* @0xd4648 b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd464c b 0xd49d4 <_Z5DoRemjPhPKhP6VMExec+0x6d0> */
/* @0xd4650 b 0xd48c4 <_Z5DoRemjPhPKhP6VMExec+0x5c0> */
/* @0xd4654 add r6, r8, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xd4658 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd465c add r6, r8, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xd4660 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd4664 ldr r3, [r1, #0xc] */
/* @0xd4668 cmp r3, #13 */
/* @0xd466c addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xd4954, 1→0xd495c, 2→0xd4974, 3→0xd498c, 4→0xd49bc, 5→0xd49a4, 6→0xd49bc, 7→0xd4920, 8-9→0xd49bc, 10→0xd4930, 11-12→0xd49bc, 13→0xd4954 */
/* @0xd4670 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4674 b 0xd4954 <_Z5DoRemjPhPKhP6VMExec+0x650> */
/* @0xd4678 b 0xd495c <_Z5DoRemjPhPKhP6VMExec+0x658> */
/* @0xd467c b 0xd4974 <_Z5DoRemjPhPKhP6VMExec+0x670> */
/* @0xd4680 b 0xd498c <_Z5DoRemjPhPKhP6VMExec+0x688> */
/* @0xd4684 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4688 b 0xd49a4 <_Z5DoRemjPhPKhP6VMExec+0x6a0> */
/* @0xd468c b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4690 b 0xd4920 <_Z5DoRemjPhPKhP6VMExec+0x61c> */
/* @0xd4694 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd4698 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd469c b 0xd4930 <_Z5DoRemjPhPKhP6VMExec+0x62c> */
/* @0xd46a0 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd46a4 b 0xd49bc <_Z5DoRemjPhPKhP6VMExec+0x6b8> */
/* @0xd46a8 b 0xd4954 <_Z5DoRemjPhPKhP6VMExec+0x650> */
/* @0xd46ac add r8, r1, #4   ——Bfmt 1/2/4 → A=arg2+4 */
/* @0xd46b0 mov r5, r4 */
/* @0xd46b4 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd46b8 add r8, r1, #8   ——Bfmt 0/3 → A=arg2+8 */
/* @0xd46bc mov r5, r4 */
/* @0xd46c0 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd46c4 mov r9, #0 */
/* @0xd46c8 mov r7, r9 */
/* @0xd46cc b 0xd4510 <_Z5DoRemjPhPKhP6VMExec+0x20c> */
/* @0xd46d0 ldrd r2, r3, [r11] */
/* @0xd46d4 orrs r1, r2, r3 */
/* @0xd46d8 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd46dc ldrd r0, r1, [r8] */
/* @0xd46e0 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd46e4 mov r3, #10 */
/* @0xd46e8 strd r0, r1, [r9] */
/* @0xd46ec vpop {d8} */
/* @0xd46f0 cmp r7, #0 */
/* @0xd46f4 mov r0, r6 */
/* @0xd46f8 strne r3, [r7, #0xc] */
/* @0xd46fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd4700 ldr r2, [r11] */
/* @0xd4704 cmp r2, #0 */
/* @0xd4708 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd470c ldrd r0, r1, [r8] */
/* @0xd4710 asr r3, r2, #31 */
/* @0xd4714 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4718 mov r3, #7 */
/* @0xd471c str r0, [r9] */
/* @0xd4720 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4724 vldr d7, [r11] */
/* @0xd4728 vabs.f64 d6, d7 */
/* @0xd472c vcvt.s32.f64 s12, d6 */
/* @0xd4730 vmov r1, s12 */
/* @0xd4734 cmp r1, #0 */
/* @0xd4738 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd473c vmov r0, r1, d7 */
/* @0xd4740 bl 0x3194a0 <__fixdfdi> */
/* @0xd4744 mov r3, r1 */
/* @0xd4748 mov r2, r0 */
/* @0xd474c ldrd r0, r1, [r8] */
/* @0xd4750 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4754 bl 0x319164 <__floatdidf> */
/* @0xd4758 mov r3, #0 */
/* @0xd475c strd r0, r1, [r9] */
/* @0xd4760 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4764 ldrd r2, r3, [r11] */
/* @0xd4768 orrs r1, r2, r3 */
/* @0xd476c beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4770 ldr r0, [r8] */
/* @0xd4774 asr r1, r0, #31 */
/* @0xd4778 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd477c mov r3, #10 */
/* @0xd4780 strd r0, r1, [r9] */
/* @0xd4784 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4788 ldr r1, [r11] */
/* @0xd478c cmp r1, #0 */
/* @0xd4790 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4794 ldr r0, [r8] */
/* @0xd4798 bl 0x318d10 <__divsi3> */
/* @0xd479c mov r3, #7 */
/* @0xd47a0 str r0, [r9] */
/* @0xd47a4 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd47a8 vldr d7, [r11] */
/* @0xd47ac vabs.f64 d6, d7 */
/* @0xd47b0 vcvt.s32.f64 s12, d6 */
/* @0xd47b4 vmov r3, s12 */
/* @0xd47b8 cmp r3, #0 */
/* @0xd47bc beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd47c0 vcvt.s32.f64 s13, d7 */
/* @0xd47c4 ldr r0, [r8] */
/* @0xd47c8 vmov r1, s13 */
/* @0xd47cc bl 0x318d10 <__divsi3> */
/* @0xd47d0 mov r3, #0 */
/* @0xd47d4 vmov s13, r0 */
/* @0xd47d8 vcvt.f64.s32 d7, s13 */
/* @0xd47dc vstr d7, [r9] */
/* @0xd47e0 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd47e4 ldrd r4, r5, [r11] */
/* @0xd47e8 orrs r3, r4, r5 */
/* @0xd47ec beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd47f0 ldrd r0, r1, [r8] */
/* @0xd47f4 bl 0x3194a0 <__fixdfdi> */
/* @0xd47f8 mov r3, r5 */
/* @0xd47fc mov r2, r4 */
/* @0xd4800 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4804 mov r3, #10 */
/* @0xd4808 strd r0, r1, [r9] */
/* @0xd480c b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4810 ldr r4, [r11] */
/* @0xd4814 cmp r4, #0 */
/* @0xd4818 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd481c ldrd r0, r1, [r8] */
/* @0xd4820 bl 0x3194a0 <__fixdfdi> */
/* @0xd4824 asr r3, r4, #31 */
/* @0xd4828 mov r2, r4 */
/* @0xd482c bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4830 bl 0x319164 <__floatdidf> */
/* @0xd4834 mov r3, #0 */
/* @0xd4838 strd r0, r1, [r9] */
/* @0xd483c b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4840 vldr d8, [r11] */
/* @0xd4844 vabs.f64 d7, d8 */
/* @0xd4848 vcvt.s32.f64 s14, d7 */
/* @0xd484c vmov r1, s14 */
/* @0xd4850 cmp r1, #0 */
/* @0xd4854 beq 0xd48ac <_Z5DoRemjPhPKhP6VMExec+0x5a8> */
/* @0xd4858 ldrd r0, r1, [r8] */
/* @0xd485c bl 0x3194a0 <__fixdfdi> */
/* @0xd4860 mov r4, r0 */
/* @0xd4864 mov r5, r1 */
/* @0xd4868 vmov r0, r1, d8 */
/* @0xd486c bl 0x3194a0 <__fixdfdi> */
/* @0xd4870 mov r3, r1 */
/* @0xd4874 mov r2, r0 */
/* @0xd4878 mov r1, r5 */
/* @0xd487c mov r0, r4 */
/* @0xd4880 bl 0x319414 <__aeabi_ldivmod> */
/* @0xd4884 bl 0x319164 <__floatdidf> */
/* @0xd4888 mov r3, #0 */
/* @0xd488c strd r0, r1, [r9] */
/* @0xd4890 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd4894 ldr r1, [pc, #0x168]   ——VMError/JSThrow 文案：'DoRem :: Execution Error' */
/* @0xd4898 mov r0, r10 */
/* @0xd489c add r1, pc, r1 */
/* @0xd48a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48a4 mov r3, #0 */
/* @0xd48a8 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd48ac ldr r1, [pc, #0x154]   ——VMError/JSThrow 文案：'DoRem :: Divide by zero' */
/* @0xd48b0 mov r0, r10 */
/* @0xd48b4 add r1, pc, r1 */
/* @0xd48b8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48bc mov r3, #0 */
/* @0xd48c0 b 0xd46ec <_Z5DoRemjPhPKhP6VMExec+0x3e8> */
/* @0xd48c4 and r5, r5, #15 */
/* @0xd48c8 add r6, r8, #16 */
/* @0xd48cc b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd48d0 ldr r1, [pc, #0x134]   ——VMError/JSThrow 文案：'DoRem :: Execution Engine - Cannot operate on string type' */
/* @0xd48d4 mov r0, r10 */
/* @0xd48d8 add r1, pc, r1 */
/* @0xd48dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48e0 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd48e4 ldr r1, [pc, #0x124]   ——VMError/JSThrow 文案：'DoRem :2: illegal array use' */
/* @0xd48e8 mov r0, r10 */
/* @0xd48ec add r1, pc, r1 */
/* @0xd48f0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd48f4 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd48f8 ldr r1, [pc, #0x114]   ——VMError/JSThrow 文案：'DoRem :2: illegal pointer use' */
/* @0xd48fc mov r0, r10 */
/* @0xd4900 add r1, pc, r1 */
/* @0xd4904 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4908 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd490c ldr r1, [pc, #0x104]   ——VMError/JSThrow 文案：'DoRem :2: undefined value' */
/* @0xd4910 mov r0, r10 */
/* @0xd4914 add r1, pc, r1 */
/* @0xd4918 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd491c b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4920 and r0, r0, #240 */
/* @0xd4924 orr r5, r0, #2 */
/* @0xd4928 add r8, r11, #16   ——5 路径：A=arg2+16 */
/* @0xd492c b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd4930 and r0, r0, #240 */
/* @0xd4934 orr r5, r0, #3 */
/* @0xd4938 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd493c and r5, r5, #15 */
/* @0xd4940 orr r5, r5, #32 */
/* @0xd4944 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4948 and r5, r5, #15 */
/* @0xd494c orr r5, r5, #48 */
/* @0xd4950 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd4954 and r5, r4, #240 */
/* @0xd4958 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd495c ldr r1, [pc, #0xb8]   ——VMError/JSThrow 文案：'DoRem :1: Execution Engine - Cannot operate on string type' */
/* @0xd4960 mov r0, r10 */
/* @0xd4964 mov r5, r4 */
/* @0xd4968 add r1, pc, r1 */
/* @0xd496c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4970 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd4974 ldr r1, [pc, #0xa4]   ——VMError/JSThrow 文案：'DoRem :1: illegal array use' */
/* @0xd4978 mov r0, r10 */
/* @0xd497c mov r5, r4 */
/* @0xd4980 add r1, pc, r1 */
/* @0xd4984 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4988 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd498c ldr r1, [pc, #0x90]   ——VMError/JSThrow 文案：'DoRem :1: illegal pointer use' */
/* @0xd4990 mov r0, r10 */
/* @0xd4994 mov r5, r4 */
/* @0xd4998 add r1, pc, r1 */
/* @0xd499c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49a0 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49a4 ldr r1, [pc, #0x7c]   ——VMError/JSThrow 文案：'DoRem :1: undefined value' */
/* @0xd49a8 mov r0, r10 */
/* @0xd49ac mov r5, r4 */
/* @0xd49b0 add r1, pc, r1 */
/* @0xd49b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49b8 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49bc ldr r1, [pc, #0x68]   ——VMError/JSThrow 文案：'DoRem :1: Malformed variable' */
/* @0xd49c0 mov r0, r10 */
/* @0xd49c4 mov r5, r4 */
/* @0xd49c8 add r1, pc, r1 */
/* @0xd49cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49d0 b 0xd4928 <_Z5DoRemjPhPKhP6VMExec+0x624> */
/* @0xd49d4 ldr r1, [pc, #0x54]   ——VMError/JSThrow 文案：'DoRem :2: Malformed variable' */
/* @0xd49d8 mov r0, r10 */
/* @0xd49dc add r1, pc, r1 */
/* @0xd49e0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd49e4 b 0xd48c8 <_Z5DoRemjPhPKhP6VMExec+0x5c4> */
/* @0xd49e8 mov r5, r4 */
/* @0xd49ec mov r8, r1 */
/* @0xd49f0 b 0xd4360 <_Z5DoRemjPhPKhP6VMExec+0x5c> */
/* @0xd49f4 mov r6, r8 */
/* @0xd49f8 b 0xd43a0 <_Z5DoRemjPhPKhP6VMExec+0x9c> */
/* @0xd49fc eoreq lr, r5, r8, lsr #9   ——literal pool：+0x25e4a8 → 0x332808 (非指令) 'DoRem :: Execution Engine - Cannot operate on string type' */
/* @0xd4a00 eoreq lr, r5, r8, ror #8   ——literal pool：+0x25e468 → 0x332808 (非指令) 'DoRem :: Execution Engine - Cannot operate on string type' */
/* @0xd4a04 eoreq lr, r5, r4, ror #1   ——literal pool：+0x25e0e4 → 0x332988 (非指令) 'DoRem :: Execution Error' */
/* @0xd4a08 strhteq lr, [r5], -r4   ——literal pool：+0x25e0b4 → 0x332970 (非指令) 'DoRem :: Divide by zero' */
/* @0xd4a0c eoreq sp, r5, r8, lsr #30   ——literal pool：+0x25df28 → 0x332808 (非指令) 'DoRem :: Execution Engine - Cannot operate on string type' */
/* @0xd4a10 eoreq lr, r5, r0, asr #32   ——literal pool：+0x25e040 → 0x332934 (非指令) 'DoRem :2: illegal array use' */
/* @0xd4a14 .word 0x0025dff0   ——literal pool：+0x25dff0 → 0x3328f8 (非指令) 'DoRem :2: illegal pointer use' */
/* @0xd4a18 .word 0x0025dffc   ——literal pool：+0x25dffc → 0x332918 (非指令) 'DoRem :2: undefined value' */
/* @0xd4a1c eoreq sp, r5, r0, lsl pc   ——literal pool：+0x25df10 → 0x332880 (非指令) 'DoRem :1: Execution Engine - Cannot operate on string type' */
/* @0xd4a20 eoreq sp, r5, r4, lsr pc   ——literal pool：+0x25df34 → 0x3328bc (非指令) 'DoRem :1: illegal array use' */
/* @0xd4a24 eoreq sp, r5, r4, lsr #29   ——literal pool：+0x25dea4 → 0x332844 (非指令) 'DoRem :1: illegal pointer use' */
/* @0xd4a28 eoreq sp, r5, r12, lsr #29   ——literal pool：+0x25deac → 0x332864 (非指令) 'DoRem :1: undefined value' */
/* @0xd4a2c eoreq sp, r5, r8, lsl #30   ——literal pool：+0x25df08 → 0x3328d8 (非指令) 'DoRem :1: Malformed variable' */
/* @0xd4a30 eoreq sp, r5, r12, ror #30   ——literal pool：+0x25df6c → 0x332950 (非指令) 'DoRem :2: Malformed variable' */
