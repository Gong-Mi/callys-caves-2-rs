/* cally 逆向卡：DoConv（原版 libyoyo.so，armv7）
 * @func 0xeb3f8 0xec104  size 3340  832 条（0xec008..0xec068 为 literal pool，objdump 译成指令，按规矩保留原写法）
 * 级别: 正文（src/dst 位域、103 项分派表、44 个叶子的转换式全部解码；3 条 open 见文末）
 * 符号: _Z6DoConvjPhPKhP6VMExec → uchar* DoConv(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * ── 参数位域（三条入口指令，全部实测）───────────────────────────────
 *   src   = arg[19:16]   @0xeb43c —— and r2, r4, #15（r4 = (uint8)(arg>>16)）
 *   dst   = arg[23:20]   @0xeb46c —— asr r4, r4, #4（同一个字节的高半字节）
 *   flags = arg[15:8]    @0xeb404 —— ubfx r0, r0, #0x8, #0x8
 *   base 是死参数：第 3 个入参 r2 在 @0xeb420 被 ldr r2,[r6] 直接覆盖，全函数没有读过它
 *         → 转换不带变量基址，与 DoPop/DoPush 的「位 30 = 附带变量基址」不是同一套编码
 *   帧 120 字节，canary 存 [sp+0x74]（@0xeb408 / @0xeb424），尾块 @0xeb6dc 校验后 pop
 *
 * ── flags 三路（@0xeb414..@0xeb438）──────────────────────────────
 *   (flags & 0xF) == 0     → 直通转换（@0xeb43c）
 *   flags & 1（bit 8）     → boxType + JS_ToBoolean（@0xeb6a0）
 *   flags & 2（bit 9）     → boxType + F_JS_ToNumber（@0xeb6f8）
 *   其余取值（4/8/12）落回直通转换：bit 10/11 参与「是否为 0」的短路，但没有独立分支
 *
 * ── 直通转换的两级跳转 ────────────────────────────────────────
 *   ① 目的指针 r7 = sp + a(src) - b(dst)，两个 7 路表：
 *      src 表 @0xeb444（表体 0xeb44c..0xeb464）: 0,3 → r7=sp+8；1,2,4,6 → r7=sp+4；5 → 动态重判(@0xeb64c)；>6 → @0xec0fc 令 r7=sp
 *      dst 表 @0xeb474（表体 0xeb47c..0xeb494）: 0,3 → r7-=8；5 → r7-=16；1,2,4,6 → r7-=4；>6 → 不调整
 *      a(0)=a(3)=8、a(5)=按 tag、其余 4；b(0)=b(3)=8、b(5)=16、其余 4
 *      ⇒ src 与 dst 同组时两常数抵消：目的槽 = 源槽（原地转换）；只有 src=5 的路径把 r7 先置 sp+16
 *   ② 主分派 @0xeb4a0 —— cmp r8,#102 + addls pc,pc,r8,lsl #2（表体 0xeb4a8..0xeb630，103 项 = 7×16，44 个不同叶子）
 *      越界/未支持组合（dst 7..15 全部 + (5,5)，共 55 项）→ @0xebe50 VMError("DoConv :: Execution Error")
 *
 * ── 类型码语义（由每个叶子实际读写宽度证明，不是猜的）────────────────────
 *   0 real     8 字节 double
 *   1 float32  4 字节单精度（(0,1) 用 vldr s14 读 4 字节，(1,0) 读 8 字节写 4 字节，双向互证）
 *   2 int32    4 字节
 *   3 int64    8 字节
 *   4 bool     4 字节 0/1
 *   5 动态     RValue 原样；只有 dst=5 的叶子写出显式 tag
 *   6 string   4 字节指针 → _RefThing<const char>{char* text; int refcnt; int len}（12 字节，@0xeb8a0..@0xeb8c8 构造）
 *   dst=5 的叶子把 tag 常量写进 [r7+0xc]，由此钉死四个 tag：real=0、string=1、int64=10、bool=13
 *
 * ── 动态源（src=5）：按 [sp+0xc] 的运行期 tag 改写成 src 码（@0xeb64c..@0xeb7e4）────
 *   tag 0 → src 0      tag 13 → src 0     tag 1  → src 6     tag 5,12 → src 4
 *   tag 7 → src 2      tag 10 → src 3
 *   tag 2 → VMError "DoConv :1: illegal array use"（@0xebec8）
 *   tag 3 → VMError "DoConv :1: illegal pointer use"（@0xeb778）
 *   tag 4/6/8/9/11 → VMError "DoConv :1: Malformed variable"（@0xebefc）
 *   tag 0x00FFFFFF（变量引用标记）→ VMError "DoConv :1: Could not find variable"（@0xeb7dc），返回 sp 不变
 *   改写后 @0xeb688 把 r7 置 sp+16，再回到 ① 的 dst 表调整
 *
 * ── flags 两条 JS 路（boxType 0xd7784 = 把栈上原始值装进 RValue）──────────────
 *   flag1 @0xeb6a0: boxType(&tmp=sp+36, arg&15, sp) → r4；[tmp+0xc]&0x00FFFFFF==0x00FFFFFF
 *         → JSThrowReferenceError("could not find lhs variable on conv")（@0xebe70），返回 r4
 *         → 否则 JS_ToBoolean(tmp)，结果写 [r4-4]，返回 r4-4
 *   flag2 @0xeb6f8: boxType(&tmp=sp+20, arg&15, sp) → r4；同样的 tag 检查（@0xebe84）
 *         → F_JS_ToNumber(&out=sp+36, &tmp)：返回 0 → [r4-4]=0、tmp+4/+8 抄到 [r4-0x10]/[r4-0xc]、返回 r4-16（16 字节 real 槽）
 *           返回 1 → JSThrowTypeError("DoConv - could not convert expr to a number")（@0xebf20）
 *           其它   → 返回 r4
 *
 * ── 叶子清单（44 个，按 dst←src 排；每行 = 目的类型 ← 源类型 : 地址 : 转换式）──────
 *   dst0 real   ← 0 0xebd18 ldrd/strd 8 字节原样         ← 1 0xebd28 vldr s14 → vcvt.s32.f32 → vcvt.f64.s32（经整数截断）
 *               ← 2 0xebdc8 vcvt.f64.s32                 ← 3 0xebddc __floatdidf
 *               ← 4 0xebc98 常量 1.0 / 0.0（0xec000=0.0） ← 5 0xebcb8 YYGetReal(rv,0) 后释放字符串
 *               ← 6 0xebce4 strtod(text,NULL)（空指针走 0xec0ac）
 *   dst1 f32    ← 0 0xebd04 vcvt.f32.f64                 ← 1 0xeb794 4 字节拷贝
 *               ← 2 0xebdb4 vcvt.f32.s32                 ← 3 0xebc18 __floatdisf
 *               ← 4 0xebc2c 常量 1.0f / 0.0f（0xec008=0.0f）← 5 0xebc6c YYGetFloat + 释放
 *               ← 6 0xebe18 strtod → vcvt.f32.f64
 *   dst2 i32    ← 0 0xebdf0 vcvt.s32.f64                 ← 1 0xebe04 vcvt.s32.f32
 *               ← 2 0xeb794 4 字节拷贝                   ← 3 0xeb794 4 字节拷贝（= 截断取低 32 位）
 *               ← 4 0xeb7a4 (v!=0) → 0/1                 ← 5 0xebb60 YYGetInt32(rv,0)
 *               ← 6 0xebb70 atoi(text) + 释放
 *   dst3 i64    ← 0 0xebb88 __fixdfdi                    ← 1 0xebc04 __fixsfdi
 *               ← 2 0xebbd0 asr #31 符号扩展后 strd       ← 3 0xebd18 8 字节原样
 *               ← 4 0xebbe4 {0/1, 0}                      ← 5 0xebb9c YYGetInt64(rv,0) + 释放
 *               ← 6 0xebc4c atol(text) + 符号扩展 + 释放
 *   dst4 bool   ← 0 0xeb7e8 d > 0.5                      ← 1 0xeb9b0 f > 0.5f
 *               ← 2 0xeb80c v > 0                        ← 3 0xeb828 64 位 >= 1（cmp r2,#1 + sbcs）
 *               ← 4 0xeb7a4 (v!=0) 归一化                 ← 5 0xeb8e0 tag==1 时 strcmp(text,"true")==0，否则 YYGetBool(rv,0)；随后源槽置 tag 5
 *               ← 6 0xeb948 strcmp(text,"true")==0 + 释放
 *   dst5 tag    ← 0 0xeb994 抄 8 字节 + tag 0            ← 1 0xeb9d4 f32→f64 + tag 0
 *               ← 2 0xeb9f4 s32→f64 + tag 0              ← 3 0xeba18 走 0xeb9f4 的尾部落 tag 10
 *               ← 4 0xeba24 (v!=0)?1.0:0.0 + tag 13      ← 6 0xeba54 抄指针 + tag 1
 *               ← 5 缺项 → VMError
 *   dst6 string ← 0 0xeba6c snprintf("%g") → Alloc/strcpy/new(12)/YYStrDup → tag 1
 *               ← 1 0xebaf0 f32→f64 后同上 "%g"          ← 2 0xebb2c snprintf("%d")
 *               ← 3 0xebd40 snprintf("%lld")             ← 4 0xeb848 常量 "true" / "false" 经 "%s"
 *               ← 5 0xebd8c tag==1 则保留并 refcnt++，否则 STRING_RValue
 *               ← 6 0xeb794 4 字节拷贝
 *   字符串→bool 是 strcmp 后 rsbs r0,r0,#1 + movlo r0,#0，等价于 (strcmp == 0)，不是「非空即真」。
 *   释放模板（字符串/对象槽通用）：tag-1 先清 bits31..24 再清 bits1..0 得 0（即 tag 1..4）才 FREE_RValue__Pre
 *   （@0xeb980..@0xeb988 / @0xec09c；DoCall 的实参释放循环是同一套判据）。
 *
 * 结论（新增四条硬事实）:
 *   1. DoConv 的 opcode 参数是 (dst<<4|src) 的**类型码对** + 8 位 flags，不同于 DoPop 的 [15:0]count/[19:16]kind：
 *      bits 19:16 = 源类型、bits 23:20 = 目的类型、bits 15:8 = 模式位；bit 30 在此完全没用到。
 *   2. 类型码空间是 7 个（0..6），配 103 项预解析分派表；不支持组合一律 VMError "DoConv :: Execution Error"，
 *      不会静默降级 —— 说明原版是靠编译器只发合法组合来保证的。
 *   3. RValue 的 tag 常量由 dst=5 叶子反推：real=0、string=1、int64=10、bool=13；bool 在 RValue 里就是
 *      8 字节 double 的 0.0/1.0 只换了 tag（boxType 的 type 3 分支同样写 tag 13，互证）。
 *   4. 运行期 tag 只有 0/1/5/7/10/12/13 是值类型，2/3 是数组/指针（报错），4/6/8/9/11 一律 Malformed。
 * open:
 *   1. r7 = sp + a(src) - b(dst) 这组常数的物理含义（槽内偏移 vs 栈上位置）没钉死；已知同组抵消为 sp。
 *   2. boxType(0xd7784) 的 eVM_Type 编号是 0=float32 1=int32 2=int64 3=bool 4=16B RValue 5=string 8=undefined，
 *      比 DoConv 类型码整体小 1；flags 路直接传 arg&15 存在 off-by-one 疑点（可能是 JS 路的死代码）。
 *   3. tag 5 与 tag 12 都映射到「bool」，而 5 在 DoCall 的实参释放循环与 boxType type 8 里是 undefined —— 语义待定。
 */
/* @0xeb3f8 push {r4, r5, r6, r7, r8, lr} */
/* @0xeb3fc lsr r12, r0, #16 */
/* @0xeb400 ldr r6, [pc, #0xc04] */
/* @0xeb404 ubfx r0, r0, #0x8, #0x8 */
/* @0xeb408 sub sp, sp, #120 */
/* @0xeb40c uxtb r4, r12 */
/* @0xeb410 ldr r6, [pc, r6] */
/* @0xeb414 tst r0, #15 */
/* @0xeb418 mov r5, r1 */
/* @0xeb41c mov r8, r4 */
/* @0xeb420 ldr r2, [r6] */
/* @0xeb424 str r2, [sp, #0x74] */
/* @0xeb428 beq 0xeb43c <_Z6DoConvjPhPKhP6VMExec+0x44> */
/* @0xeb42c tst r0, #1 */
/* @0xeb430 bne 0xeb6a0 <_Z6DoConvjPhPKhP6VMExec+0x2a8> */
/* @0xeb434 tst r0, #2 */
/* @0xeb438 bne 0xeb6f8 <_Z6DoConvjPhPKhP6VMExec+0x300> */
/* @0xeb43c and r2, r4, #15 */
/* @0xeb440 cmp r2, #6 */
/* @0xeb444 addls pc, pc, r2, lsl #2 */
/* @0xeb448 b 0xec0fc <_Z6DoConvjPhPKhP6VMExec+0xd04> */
/* @0xeb44c b 0xeb644 <_Z6DoConvjPhPKhP6VMExec+0x24c> */
/* @0xeb450 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb454 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb458 b 0xeb644 <_Z6DoConvjPhPKhP6VMExec+0x24c> */
/* @0xeb45c b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb460 b 0xeb64c <_Z6DoConvjPhPKhP6VMExec+0x254> */
/* @0xeb464 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb468 add r7, r5, #4 */
/* @0xeb46c asr r4, r4, #4 */
/* @0xeb470 cmp r4, #6 */
/* @0xeb474 addls pc, pc, r4, lsl #2 */
/* @0xeb478 b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb47c b 0xeb690 <_Z6DoConvjPhPKhP6VMExec+0x298> */
/* @0xeb480 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb484 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb488 b 0xeb690 <_Z6DoConvjPhPKhP6VMExec+0x298> */
/* @0xeb48c b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb490 b 0xeb698 <_Z6DoConvjPhPKhP6VMExec+0x2a0> */
/* @0xeb494 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb498 sub r7, r7, #4 */
/* @0xeb49c cmp r8, #102 */
/* @0xeb4a0 addls pc, pc, r8, lsl #2 */
/* @0xeb4a4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4a8 b 0xebd18 <_Z6DoConvjPhPKhP6VMExec+0x920> */
/* @0xeb4ac b 0xebd28 <_Z6DoConvjPhPKhP6VMExec+0x930> */
/* @0xeb4b0 b 0xebdc8 <_Z6DoConvjPhPKhP6VMExec+0x9d0> */
/* @0xeb4b4 b 0xebddc <_Z6DoConvjPhPKhP6VMExec+0x9e4> */
/* @0xeb4b8 b 0xebc98 <_Z6DoConvjPhPKhP6VMExec+0x8a0> */
/* @0xeb4bc b 0xebcb8 <_Z6DoConvjPhPKhP6VMExec+0x8c0> */
/* @0xeb4c0 b 0xebce4 <_Z6DoConvjPhPKhP6VMExec+0x8ec> */
/* @0xeb4c4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4c8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4cc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4dc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e8 b 0xebd04 <_Z6DoConvjPhPKhP6VMExec+0x90c> */
/* @0xeb4ec b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb4f0 b 0xebdb4 <_Z6DoConvjPhPKhP6VMExec+0x9bc> */
/* @0xeb4f4 b 0xebc18 <_Z6DoConvjPhPKhP6VMExec+0x820> */
/* @0xeb4f8 b 0xebc2c <_Z6DoConvjPhPKhP6VMExec+0x834> */
/* @0xeb4fc b 0xebc6c <_Z6DoConvjPhPKhP6VMExec+0x874> */
/* @0xeb500 b 0xebe18 <_Z6DoConvjPhPKhP6VMExec+0xa20> */
/* @0xeb504 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb508 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb50c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb510 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb514 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb518 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb51c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb520 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb524 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb528 b 0xebdf0 <_Z6DoConvjPhPKhP6VMExec+0x9f8> */
/* @0xeb52c b 0xebe04 <_Z6DoConvjPhPKhP6VMExec+0xa0c> */
/* @0xeb530 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb534 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb538 b 0xeb7a4 <_Z6DoConvjPhPKhP6VMExec+0x3ac> */
/* @0xeb53c b 0xebb60 <_Z6DoConvjPhPKhP6VMExec+0x768> */
/* @0xeb540 b 0xebb70 <_Z6DoConvjPhPKhP6VMExec+0x778> */
/* @0xeb544 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb548 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb54c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb550 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb554 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb558 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb55c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb560 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb564 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb568 b 0xebb88 <_Z6DoConvjPhPKhP6VMExec+0x790> */
/* @0xeb56c b 0xebc04 <_Z6DoConvjPhPKhP6VMExec+0x80c> */
/* @0xeb570 b 0xebbd0 <_Z6DoConvjPhPKhP6VMExec+0x7d8> */
/* @0xeb574 b 0xebd18 <_Z6DoConvjPhPKhP6VMExec+0x920> */
/* @0xeb578 b 0xebbe4 <_Z6DoConvjPhPKhP6VMExec+0x7ec> */
/* @0xeb57c b 0xebb9c <_Z6DoConvjPhPKhP6VMExec+0x7a4> */
/* @0xeb580 b 0xebc4c <_Z6DoConvjPhPKhP6VMExec+0x854> */
/* @0xeb584 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb588 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb58c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb590 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb594 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb598 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb59c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a8 b 0xeb7e8 <_Z6DoConvjPhPKhP6VMExec+0x3f0> */
/* @0xeb5ac b 0xeb9b0 <_Z6DoConvjPhPKhP6VMExec+0x5b8> */
/* @0xeb5b0 b 0xeb80c <_Z6DoConvjPhPKhP6VMExec+0x414> */
/* @0xeb5b4 b 0xeb828 <_Z6DoConvjPhPKhP6VMExec+0x430> */
/* @0xeb5b8 b 0xeb7a4 <_Z6DoConvjPhPKhP6VMExec+0x3ac> */
/* @0xeb5bc b 0xeb8e0 <_Z6DoConvjPhPKhP6VMExec+0x4e8> */
/* @0xeb5c0 b 0xeb948 <_Z6DoConvjPhPKhP6VMExec+0x550> */
/* @0xeb5c4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5c8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5cc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5dc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e8 b 0xeb994 <_Z6DoConvjPhPKhP6VMExec+0x59c> */
/* @0xeb5ec b 0xeb9d4 <_Z6DoConvjPhPKhP6VMExec+0x5dc> */
/* @0xeb5f0 b 0xeb9f4 <_Z6DoConvjPhPKhP6VMExec+0x5fc> */
/* @0xeb5f4 b 0xeba18 <_Z6DoConvjPhPKhP6VMExec+0x620> */
/* @0xeb5f8 b 0xeba24 <_Z6DoConvjPhPKhP6VMExec+0x62c> */
/* @0xeb5fc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb600 b 0xeba54 <_Z6DoConvjPhPKhP6VMExec+0x65c> */
/* @0xeb604 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb608 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb60c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb610 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb614 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb618 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb61c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb620 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb624 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb628 b 0xeba6c <_Z6DoConvjPhPKhP6VMExec+0x674> */
/* @0xeb62c b 0xebaf0 <_Z6DoConvjPhPKhP6VMExec+0x6f8> */
/* @0xeb630 b 0xebb2c <_Z6DoConvjPhPKhP6VMExec+0x734> */
/* @0xeb634 b 0xebd40 <_Z6DoConvjPhPKhP6VMExec+0x948> */
/* @0xeb638 b 0xeb848 <_Z6DoConvjPhPKhP6VMExec+0x450> */
/* @0xeb63c b 0xebd8c <_Z6DoConvjPhPKhP6VMExec+0x994> */
/* @0xeb640 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb644 add r7, r5, #8 */
/* @0xeb648 b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */
/* @0xeb64c ldr r2, [r5, #0xc] */
/* @0xeb650 cmp r2, #5 */
/* @0xeb654 beq 0xebef0 <_Z6DoConvjPhPKhP6VMExec+0xaf8> */
/* @0xeb658 ble 0xeb75c <_Z6DoConvjPhPKhP6VMExec+0x364> */
/* @0xeb65c cmp r2, #12 */
/* @0xeb660 beq 0xebef0 <_Z6DoConvjPhPKhP6VMExec+0xaf8> */
/* @0xeb664 bgt 0xeb7bc <_Z6DoConvjPhPKhP6VMExec+0x3c4> */
/* @0xeb668 cmp r2, #7 */
/* @0xeb66c andeq r12, r12, #240 */
/* @0xeb670 orreq r8, r12, #2 */
/* @0xeb674 beq 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xeb678 cmp r2, #10 */
/* @0xeb67c andeq r12, r12, #240 */
/* @0xeb680 orreq r8, r12, #3 */
/* @0xeb684 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb688 add r7, r5, #16 */
/* @0xeb68c b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */
/* @0xeb690 sub r7, r7, #8 */
/* @0xeb694 b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb698 sub r7, r7, #16 */
/* @0xeb69c b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb6a0 add r7, sp, #36 */
/* @0xeb6a4 and r1, r4, #15 */
/* @0xeb6a8 mov r2, r5 */
/* @0xeb6ac mov r0, r7 */
/* @0xeb6b0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xeb6b4 ldr r2, [sp, #0x30] */
/* @0xeb6b8 mvn r3, #-16777216 */
/* @0xeb6bc and r2, r2, r3 */
/* @0xeb6c0 cmp r2, r3 */
/* @0xeb6c4 mov r4, r0 */
/* @0xeb6c8 beq 0xebe68 <_Z6DoConvjPhPKhP6VMExec+0xa70> */
/* @0xeb6cc mov r0, r7 */
/* @0xeb6d0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0xeb6d4 sub r12, r4, #4 */
/* @0xeb6d8 str r0, [r4, #-0x4] */
/* @0xeb6dc ldr r2, [sp, #0x74] */
/* @0xeb6e0 mov r0, r12 */
/* @0xeb6e4 ldr r3, [r6] */
/* @0xeb6e8 cmp r2, r3 */
/* @0xeb6ec bne 0xec0f8 <_Z6DoConvjPhPKhP6VMExec+0xd00> */
/* @0xeb6f0 add sp, sp, #120 */
/* @0xeb6f4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xeb6f8 add r7, sp, #20 */
/* @0xeb6fc and r1, r4, #15 */
/* @0xeb700 mov r2, r5 */
/* @0xeb704 mov r0, r7 */
/* @0xeb708 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xeb70c ldr r2, [sp, #0x20] */
/* @0xeb710 mvn r3, #-16777216 */
/* @0xeb714 and r2, r2, r3 */
/* @0xeb718 cmp r2, r3 */
/* @0xeb71c mov r4, r0 */
/* @0xeb720 beq 0xebe7c <_Z6DoConvjPhPKhP6VMExec+0xa84> */
/* @0xeb724 mov r1, r7 */
/* @0xeb728 add r0, sp, #36 */
/* @0xeb72c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xeb730 cmp r0, #1 */
/* @0xeb734 beq 0xebf18 <_Z6DoConvjPhPKhP6VMExec+0xb20> */
/* @0xeb738 cmp r0, #0 */
/* @0xeb73c streq r0, [r4, #-0x4] */
/* @0xeb740 subeq r12, r4, #16 */
/* @0xeb744 ldreq r2, [sp, #0x24] */
/* @0xeb748 movne r12, r4 */
/* @0xeb74c ldreq r3, [sp, #0x28] */
/* @0xeb750 streq r2, [r4, #-0x10] */
/* @0xeb754 streq r3, [r4, #-0xc] */
/* @0xeb758 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb75c cmp r2, #1 */
/* @0xeb760 beq 0xebee4 <_Z6DoConvjPhPKhP6VMExec+0xaec> */
/* @0xeb764 ble 0xebe40 <_Z6DoConvjPhPKhP6VMExec+0xa48> */
/* @0xeb768 cmp r2, #2 */
/* @0xeb76c beq 0xebec8 <_Z6DoConvjPhPKhP6VMExec+0xad0> */
/* @0xeb770 cmp r2, #3 */
/* @0xeb774 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb778 ldr r1, [pc, #0x890] */
/* @0xeb77c mov r0, r3 */
/* @0xeb780 str r3, [sp, #0xc] */
/* @0xeb784 add r1, pc, r1 */
/* @0xeb788 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb78c ldr r3, [sp, #0xc] */
/* @0xeb790 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xeb794 ldr r3, [r5] */
/* @0xeb798 mov r12, r7 */
/* @0xeb79c str r3, [r7] */
/* @0xeb7a0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7a4 ldr r3, [r5] */
/* @0xeb7a8 mov r12, r7 */
/* @0xeb7ac adds r3, r3, #0 */
/* @0xeb7b0 movne r3, #1 */
/* @0xeb7b4 str r3, [r7] */
/* @0xeb7b8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7bc cmp r2, #13 */
/* @0xeb7c0 beq 0xebe48 <_Z6DoConvjPhPKhP6VMExec+0xa50> */
/* @0xeb7c4 mvn r1, #-16777216 */
/* @0xeb7c8 cmp r2, r1 */
/* @0xeb7cc bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb7d0 ldr r1, [pc, #0x83c] */
/* @0xeb7d4 mov r0, r3 */
/* @0xeb7d8 add r1, pc, r1 */
/* @0xeb7dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb7e0 mov r12, r5 */
/* @0xeb7e4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7e8 vmov.f64 d7, #5.000000e-01 */
/* @0xeb7ec vldr d6, [r5] */
/* @0xeb7f0 mov r12, r7 */
/* @0xeb7f4 vcmpe.f64 d6, d7 */
/* @0xeb7f8 vmrs APSR_nzcv, fpscr */
/* @0xeb7fc movle r3, #0 */
/* @0xeb800 movgt r3, #1 */
/* @0xeb804 str r3, [r7] */
/* @0xeb808 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb80c ldr r3, [r5] */
/* @0xeb810 mov r12, r7 */
/* @0xeb814 cmp r3, #0 */
/* @0xeb818 movle r3, #0 */
/* @0xeb81c movgt r3, #1 */
/* @0xeb820 str r3, [r7] */
/* @0xeb824 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb828 ldrd r2, r3, [r5] */
/* @0xeb82c mov r12, r7 */
/* @0xeb830 cmp r2, #1 */
/* @0xeb834 sbcs r1, r3, #0 */
/* @0xeb838 movlt r3, #0 */
/* @0xeb83c movge r3, #1 */
/* @0xeb840 str r3, [r7] */
/* @0xeb844 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb848 ldr r3, [r5] */
/* @0xeb84c cmp r3, #0 */
/* @0xeb850 beq 0xebf2c <_Z6DoConvjPhPKhP6VMExec+0xb34> */
/* @0xeb854 ldr r3, [pc, #0x7bc] */
/* @0xeb858 add r3, pc, r3 */
/* @0xeb85c add r5, sp, #52 */
/* @0xeb860 ldr r2, [pc, #0x7b4] */
/* @0xeb864 mov r1, #64 */
/* @0xeb868 add r2, pc, r2 */
/* @0xeb86c mov r0, r5 */
/* @0xeb870 bl 0xb65c8 <snprintf@plt> */
/* @0xeb874 mov r0, r5 */
/* @0xeb878 bl 0xb6538 <strlen@plt> */
/* @0xeb87c ldr r1, [pc, #0x79c] */
/* @0xeb880 movw r2, #0xf7e */
/* @0xeb884 add r1, pc, r1 */
/* @0xeb888 mov r3, #1 */
/* @0xeb88c add r0, r0, r3 */
/* @0xeb890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xeb894 mov r1, r5 */
/* @0xeb898 mov r4, r0 */
/* @0xeb89c bl 0xb65a4 <strcpy@plt> */
/* @0xeb8a0 mov r0, #12 */
/* @0xeb8a4 bl 0x27c524 <_Znwj> */
/* @0xeb8a8 mov r5, r0 */
/* @0xeb8ac subs r0, r4, #0 */
/* @0xeb8b0 beq 0xeb8b8 <_Z6DoConvjPhPKhP6VMExec+0x4c0> */
/* @0xeb8b4 bl 0xb6538 <strlen@plt> */
/* @0xeb8b8 str r0, [r5, #0x8] */
/* @0xeb8bc mov r0, r4 */
/* @0xeb8c0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xeb8c4 mov r3, #1 */
/* @0xeb8c8 stm r5, {r0, r3} */
/* @0xeb8cc mov r0, r4 */
/* @0xeb8d0 str r5, [r7] */
/* @0xeb8d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xeb8d8 mov r12, r7 */
/* @0xeb8dc b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb8e0 ldr r3, [r5, #0xc] */
/* @0xeb8e4 cmp r3, #1 */
/* @0xeb8e8 bne 0xebf5c <_Z6DoConvjPhPKhP6VMExec+0xb64> */
/* @0xeb8ec ldr r3, [r5] */
/* @0xeb8f0 ldr r1, [pc, #0x72c] */
/* @0xeb8f4 cmp r3, #0 */
/* @0xeb8f8 add r1, pc, r1 */
/* @0xeb8fc ldrne r0, [r3] */
/* @0xeb900 moveq r0, r3 */
/* @0xeb904 bl 0xb6574 <strcmp@plt> */
/* @0xeb908 rsbs r0, r0, #1 */
/* @0xeb90c movlo r0, #0 */
/* @0xeb910 str r0, [r7] */
/* @0xeb914 ldr r3, [r5, #0xc] */
/* @0xeb918 sub r3, r3, #1 */
/* @0xeb91c bic r3, r3, #-16777216 */
/* @0xeb920 bic r3, r3, #3 */
/* @0xeb924 cmp r3, #0 */
/* @0xeb928 beq 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xeb92c mov r3, #0 */
/* @0xeb930 mov r2, #5 */
/* @0xeb934 mov r12, r7 */
/* @0xeb938 str r3, [r5, #0x8] */
/* @0xeb93c str r3, [r5] */
/* @0xeb940 str r2, [r5, #0xc] */
/* @0xeb944 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb948 ldr r4, [r5] */
/* @0xeb94c cmp r4, #0 */
/* @0xeb950 beq 0xec088 <_Z6DoConvjPhPKhP6VMExec+0xc90> */
/* @0xeb954 ldr r1, [pc, #0x6cc] */
/* @0xeb958 ldr r0, [r4] */
/* @0xeb95c add r1, pc, r1 */
/* @0xeb960 bl 0xb6574 <strcmp@plt> */
/* @0xeb964 rsbs r0, r0, #1 */
/* @0xeb968 movlo r0, #0 */
/* @0xeb96c str r0, [r7] */
/* @0xeb970 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb974 ldr r5, [r4, #0x4] */
/* @0xeb978 sub r5, r5, #1 */
/* @0xeb97c str r5, [r4, #0x4] */
/* @0xeb980 cmp r5, #0 */
/* @0xeb984 beq 0xebe90 <_Z6DoConvjPhPKhP6VMExec+0xa98> */
/* @0xeb988 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb98c mov r12, r7 */
/* @0xeb990 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb994 ldr r2, [r5] */
/* @0xeb998 mov r1, #0 */
/* @0xeb99c ldr r3, [r5, #0x4] */
/* @0xeb9a0 mov r12, r7 */
/* @0xeb9a4 str r1, [r7, #0xc] */
/* @0xeb9a8 stm r7, {r2, r3} */
/* @0xeb9ac b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9b0 vmov.f32 s15, #5.000000e-01 */
/* @0xeb9b4 vldr s14, [r5] */
/* @0xeb9b8 mov r12, r7 */
/* @0xeb9bc vcmpe.f32 s14, s15 */
/* @0xeb9c0 vmrs APSR_nzcv, fpscr */
/* @0xeb9c4 movle r3, #0 */
/* @0xeb9c8 movgt r3, #1 */
/* @0xeb9cc str r3, [r7] */
/* @0xeb9d0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9d4 vldr s15, [r5] */
/* @0xeb9d8 vcvt.f64.f32 d6, s15 */
/* @0xeb9dc mov r1, #0 */
/* @0xeb9e0 mov r12, r7 */
/* @0xeb9e4 str r1, [r7, #0xc] */
/* @0xeb9e8 vmov r2, r3, d6 */
/* @0xeb9ec stm r7, {r2, r3} */
/* @0xeb9f0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9f4 ldr r2, [r5] */
/* @0xeb9f8 mov r3, #0 */
/* @0xeb9fc str r3, [r7, #0xc] */
/* @0xeba00 mov r12, r7 */
/* @0xeba04 vmov s13, r2 */
/* @0xeba08 vcvt.f64.s32 d6, s13 */
/* @0xeba0c vmov r2, r3, d6 */
/* @0xeba10 stm r7, {r2, r3} */
/* @0xeba14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba18 ldr r2, [r5] */
/* @0xeba1c mov r1, #10 */
/* @0xeba20 b 0xeb99c <_Z6DoConvjPhPKhP6VMExec+0x5a4> */
/* @0xeba24 ldr r3, [r5] */
/* @0xeba28 mov r12, r7 */
/* @0xeba2c cmp r3, #0 */
/* @0xeba30 movne r2, #0 */
/* @0xeba34 moveq r2, r3 */
/* @0xeba38 movne r3, r2 */
/* @0xeba3c movtne r2, #0x3ff0 */
/* @0xeba40 str r3, [r7] */
/* @0xeba44 mov r3, #13 */
/* @0xeba48 str r2, [r7, #0x4] */
/* @0xeba4c str r3, [r7, #0xc] */
/* @0xeba50 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba54 ldr r3, [r5] */
/* @0xeba58 mov r2, #1 */
/* @0xeba5c mov r12, r7 */
/* @0xeba60 str r2, [r7, #0xc] */
/* @0xeba64 str r3, [r7] */
/* @0xeba68 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba6c ldrd r2, r3, [r5] */
/* @0xeba70 add r4, sp, #52 */
/* @0xeba74 mov r1, #64 */
/* @0xeba78 mov r0, r4 */
/* @0xeba7c strd r2, r3, [sp] */
/* @0xeba80 ldr r2, [pc, #0x5a4] */
/* @0xeba84 add r2, pc, r2 */
/* @0xeba88 bl 0xb65c8 <snprintf@plt> */
/* @0xeba8c mov r0, r4 */
/* @0xeba90 bl 0xb6538 <strlen@plt> */
/* @0xeba94 ldr r1, [pc, #0x594] */
/* @0xeba98 movw r2, #0xf0d */
/* @0xeba9c add r1, pc, r1 */
/* @0xebaa0 mov r3, #1 */
/* @0xebaa4 add r0, r0, r3 */
/* @0xebaa8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebaac mov r1, r4 */
/* @0xebab0 mov r5, r0 */
/* @0xebab4 bl 0xb65a4 <strcpy@plt> */
/* @0xebab8 mov r0, #12 */
/* @0xebabc bl 0x27c524 <_Znwj> */
/* @0xebac0 mov r4, r0 */
/* @0xebac4 subs r0, r5, #0 */
/* @0xebac8 beq 0xebad0 <_Z6DoConvjPhPKhP6VMExec+0x6d8> */
/* @0xebacc bl 0xb6538 <strlen@plt> */
/* @0xebad0 str r0, [r4, #0x8] */
/* @0xebad4 mov r0, r5 */
/* @0xebad8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xebadc mov r3, #1 */
/* @0xebae0 mov r12, r7 */
/* @0xebae4 stm r4, {r0, r3} */
/* @0xebae8 str r4, [r7] */
/* @0xebaec b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebaf0 vldr s14, [r5] */
/* @0xebaf4 vcvt.f64.f32 d7, s14 */
/* @0xebaf8 add r5, sp, #52 */
/* @0xebafc ldr r2, [pc, #0x530] */
/* @0xebb00 mov r1, #64 */
/* @0xebb04 add r2, pc, r2 */
/* @0xebb08 mov r0, r5 */
/* @0xebb0c vstr d7, [sp] */
/* @0xebb10 bl 0xb65c8 <snprintf@plt> */
/* @0xebb14 mov r0, r5 */
/* @0xebb18 bl 0xb6538 <strlen@plt> */
/* @0xebb1c ldr r1, [pc, #0x514] */
/* @0xebb20 movw r2, #0xf43 */
/* @0xebb24 add r1, pc, r1 */
/* @0xebb28 b 0xeb888 <_Z6DoConvjPhPKhP6VMExec+0x490> */
/* @0xebb2c add r4, sp, #52 */
/* @0xebb30 ldr r2, [pc, #0x504] */
/* @0xebb34 mov r1, #64 */
/* @0xebb38 ldr r3, [r5] */
/* @0xebb3c add r2, pc, r2 */
/* @0xebb40 mov r0, r4 */
/* @0xebb44 bl 0xb65c8 <snprintf@plt> */
/* @0xebb48 mov r0, r4 */
/* @0xebb4c bl 0xb6538 <strlen@plt> */
/* @0xebb50 ldr r1, [pc, #0x4e8] */
/* @0xebb54 movw r2, #0xf28 */
/* @0xebb58 add r1, pc, r1 */
/* @0xebb5c b 0xebaa0 <_Z6DoConvjPhPKhP6VMExec+0x6a8> */
/* @0xebb60 mov r0, r5 */
/* @0xebb64 mov r1, #0 */
/* @0xebb68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xebb6c b 0xeb910 <_Z6DoConvjPhPKhP6VMExec+0x518> */
/* @0xebb70 ldr r4, [r5] */
/* @0xebb74 cmp r4, #0 */
/* @0xebb78 beq 0xec0c4 <_Z6DoConvjPhPKhP6VMExec+0xccc> */
/* @0xebb7c ldr r0, [r4] */
/* @0xebb80 bl 0xb66b8 <atoi@plt> */
/* @0xebb84 b 0xeb96c <_Z6DoConvjPhPKhP6VMExec+0x574> */
/* @0xebb88 ldrd r0, r1, [r5] */
/* @0xebb8c bl 0x3194a0 <__fixdfdi> */
/* @0xebb90 mov r12, r7 */
/* @0xebb94 strd r0, r1, [r7] */
/* @0xebb98 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebb9c mov r0, r5 */
/* @0xebba0 mov r1, #0 */
/* @0xebba4 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xebba8 ldr r3, [r5, #0xc] */
/* @0xebbac sub r3, r3, #1 */
/* @0xebbb0 bic r3, r3, #-16777216 */
/* @0xebbb4 bic r3, r3, #3 */
/* @0xebbb8 cmp r3, #0 */
/* @0xebbbc strd r0, r1, [r7] */
/* @0xebbc0 bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebbc4 mov r0, r5 */
/* @0xebbc8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xebbcc b 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebbd0 ldr r2, [r5] */
/* @0xebbd4 mov r12, r7 */
/* @0xebbd8 asr r3, r2, #31 */
/* @0xebbdc strd r2, r3, [r7] */
/* @0xebbe0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebbe4 ldr r3, [r5] */
/* @0xebbe8 mov r2, #0 */
/* @0xebbec mov r12, r7 */
/* @0xebbf0 str r2, [r7, #0x4] */
/* @0xebbf4 subs r3, r3, r2 */
/* @0xebbf8 movne r3, #1 */
/* @0xebbfc str r3, [r7] */
/* @0xebc00 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc04 ldr r0, [r5] */
/* @0xebc08 bl 0x319468 <__fixsfdi> */
/* @0xebc0c mov r12, r7 */
/* @0xebc10 strd r0, r1, [r7] */
/* @0xebc14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc18 ldrd r0, r1, [r5] */
/* @0xebc1c bl 0x319398 <__floatdisf> */
/* @0xebc20 mov r12, r7 */
/* @0xebc24 str r0, [r7] */
/* @0xebc28 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc2c vmov.f32 s15, #1.000000e+00 */
/* @0xebc30 ldr r3, [r5] */
/* @0xebc34 vldr s14, [pc, #972] */
/* @0xebc38 mov r12, r7 */
/* @0xebc3c cmp r3, #0 */
/* @0xebc40 vmoveq.f32 s15, s14 */
/* @0xebc44 vstr s15, [r7] */
/* @0xebc48 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc4c ldr r4, [r5] */
/* @0xebc50 cmp r4, #0 */
/* @0xebc54 beq 0xec070 <_Z6DoConvjPhPKhP6VMExec+0xc78> */
/* @0xebc58 ldr r0, [r4] */
/* @0xebc5c bl 0xb66c4 <atol@plt> */
/* @0xebc60 asr r1, r0, #31 */
/* @0xebc64 strd r0, r1, [r7] */
/* @0xebc68 b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebc6c mov r0, r5 */
/* @0xebc70 mov r1, #0 */
/* @0xebc74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xebc78 ldr r3, [r5, #0xc] */
/* @0xebc7c sub r3, r3, #1 */
/* @0xebc80 bic r3, r3, #-16777216 */
/* @0xebc84 bic r3, r3, #3 */
/* @0xebc88 cmp r3, #0 */
/* @0xebc8c str r0, [r7] */
/* @0xebc90 bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebc94 b 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xebc98 vmov.f64 d7, #1.000000e+00 */
/* @0xebc9c ldr r3, [r5] */
/* @0xebca0 vldr d6, [pc, #856] */
/* @0xebca4 mov r12, r7 */
/* @0xebca8 cmp r3, #0 */
/* @0xebcac vmoveq.f64 d7, d6 */
/* @0xebcb0 vstr d7, [r7] */
/* @0xebcb4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebcb8 mov r0, r5 */
/* @0xebcbc mov r1, #0 */
/* @0xebcc0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xebcc4 ldr r3, [r5, #0xc] */
/* @0xebcc8 sub r3, r3, #1 */
/* @0xebccc bic r3, r3, #-16777216 */
/* @0xebcd0 bic r3, r3, #3 */
/* @0xebcd4 cmp r3, #0 */
/* @0xebcd8 strd r0, r1, [r7] */
/* @0xebcdc bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebce0 b 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xebce4 ldr r4, [r5] */
/* @0xebce8 cmp r4, #0 */
/* @0xebcec beq 0xec0ac <_Z6DoConvjPhPKhP6VMExec+0xcb4> */
/* @0xebcf0 ldr r0, [r4] */
/* @0xebcf4 mov r1, #0 */
/* @0xebcf8 bl 0xb6658 <strtod@plt> */
/* @0xebcfc strd r0, r1, [r7] */
/* @0xebd00 b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebd04 vldr d7, [r5] */
/* @0xebd08 vcvt.f32.f64 s14, d7 */
/* @0xebd0c mov r12, r7 */
/* @0xebd10 vstr s14, [r7] */
/* @0xebd14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd18 ldrd r2, r3, [r5] */
/* @0xebd1c mov r12, r7 */
/* @0xebd20 strd r2, r3, [r7] */
/* @0xebd24 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd28 vldr s14, [r5] */
/* @0xebd2c vcvt.s32.f32 s14, s14 */
/* @0xebd30 mov r12, r7 */
/* @0xebd34 vcvt.f64.s32 d7, s14 */
/* @0xebd38 vstr d7, [r7] */
/* @0xebd3c b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd40 ldrd r4, r5, [r5] */
/* @0xebd44 add r8, sp, #52 */
/* @0xebd48 ldr r2, [pc, #0x2f4] */
/* @0xebd4c mov r1, #64 */
/* @0xebd50 mov r0, r8 */
/* @0xebd54 add r2, pc, r2 */
/* @0xebd58 strd r4, r5, [sp] */
/* @0xebd5c bl 0xb65c8 <snprintf@plt> */
/* @0xebd60 mov r0, r8 */
/* @0xebd64 bl 0xb6538 <strlen@plt> */
/* @0xebd68 ldr r1, [pc, #0x2d8] */
/* @0xebd6c mov r3, #1 */
/* @0xebd70 movw r2, #0xf5f */
/* @0xebd74 add r1, pc, r1 */
/* @0xebd78 add r0, r0, r3 */
/* @0xebd7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebd80 mov r1, r8 */
/* @0xebd84 mov r4, r0 */
/* @0xebd88 b 0xeb89c <_Z6DoConvjPhPKhP6VMExec+0x4a4> */
/* @0xebd8c ldr r3, [r5, #0xc] */
/* @0xebd90 cmp r3, #1 */
/* @0xebd94 bne 0xebf74 <_Z6DoConvjPhPKhP6VMExec+0xb7c> */
/* @0xebd98 ldr r3, [r5] */
/* @0xebd9c mov r12, r7 */
/* @0xebda0 ldr r2, [r3, #0x4] */
/* @0xebda4 str r3, [r7] */
/* @0xebda8 add r2, r2, #1 */
/* @0xebdac str r2, [r3, #0x4] */
/* @0xebdb0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdb4 vldr s15, [r5] */
/* @0xebdb8 vcvt.f32.s32 s15, s15 */
/* @0xebdbc mov r12, r7 */
/* @0xebdc0 vstr s15, [r7] */
/* @0xebdc4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdc8 vldr s14, [r5] */
/* @0xebdcc vcvt.f64.s32 d7, s14 */
/* @0xebdd0 mov r12, r7 */
/* @0xebdd4 vstr d7, [r7] */
/* @0xebdd8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebddc ldrd r0, r1, [r5] */
/* @0xebde0 bl 0x319164 <__floatdidf> */
/* @0xebde4 mov r12, r7 */
/* @0xebde8 strd r0, r1, [r7] */
/* @0xebdec b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdf0 vldr d7, [r5] */
/* @0xebdf4 vcvt.s32.f64 s14, d7 */
/* @0xebdf8 mov r12, r7 */
/* @0xebdfc vstr s14, [r7] */
/* @0xebe00 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe04 vldr s15, [r5] */
/* @0xebe08 vcvt.s32.f32 s15, s15 */
/* @0xebe0c mov r12, r7 */
/* @0xebe10 vstr s15, [r7] */
/* @0xebe14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe18 ldr r4, [r5] */
/* @0xebe1c cmp r4, #0 */
/* @0xebe20 beq 0xec0d8 <_Z6DoConvjPhPKhP6VMExec+0xce0> */
/* @0xebe24 ldr r0, [r4] */
/* @0xebe28 mov r1, #0 */
/* @0xebe2c bl 0xb6658 <strtod@plt> */
/* @0xebe30 vmov d6, r0, r1 */
/* @0xebe34 vcvt.f32.f64 s15, d6 */
/* @0xebe38 vstr s15, [r7] */
/* @0xebe3c b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebe40 cmp r2, #0 */
/* @0xebe44 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xebe48 and r8, r4, #240 */
/* @0xebe4c b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebe50 ldr r1, [pc, #0x1f4] */
/* @0xebe54 mov r0, r3 */
/* @0xebe58 add r1, pc, r1 */
/* @0xebe5c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebe60 mov r12, r7 */
/* @0xebe64 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe68 ldr r0, [pc, #0x1e0] */
/* @0xebe6c add r0, pc, r0 */
/* @0xebe70 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xebe74 mov r12, r4 */
/* @0xebe78 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe7c ldr r0, [pc, #0x1d0] */
/* @0xebe80 add r0, pc, r0 */
/* @0xebe84 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xebe88 mov r12, r4 */
/* @0xebe8c b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe90 ldr r0, [r4] */
/* @0xebe94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xebe98 str r5, [r4] */
/* @0xebe9c str r5, [r4, #0x8] */
/* @0xebea0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xebea4 ldr r5, [r4, #0x4] */
/* @0xebea8 sub r5, r5, #1 */
/* @0xebeac str r5, [r4, #0x4] */
/* @0xebeb0 cmp r5, #0 */
/* @0xebeb4 beq 0xebf38 <_Z6DoConvjPhPKhP6VMExec+0xb40> */
/* @0xebeb8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xebebc mov r0, r4 */
/* @0xebec0 bl 0x27d1d0 <_ZdlPv> */
/* @0xebec4 b 0xeb988 <_Z6DoConvjPhPKhP6VMExec+0x590> */
/* @0xebec8 ldr r1, [pc, #0x188] */
/* @0xebecc mov r0, r3 */
/* @0xebed0 str r3, [sp, #0xc] */
/* @0xebed4 add r1, pc, r1 */
/* @0xebed8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebedc ldr r3, [sp, #0xc] */
/* @0xebee0 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebee4 and r12, r12, #240 */
/* @0xebee8 orr r8, r12, #6 */
/* @0xebeec b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebef0 and r12, r12, #240 */
/* @0xebef4 orr r8, r12, #4 */
/* @0xebef8 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebefc ldr r1, [pc, #0x158] */
/* @0xebf00 mov r0, r3 */
/* @0xebf04 str r3, [sp, #0xc] */
/* @0xebf08 add r1, pc, r1 */
/* @0xebf0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebf10 ldr r3, [sp, #0xc] */
/* @0xebf14 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebf18 ldr r0, [pc, #0x140] */
/* @0xebf1c add r0, pc, r0 */
/* @0xebf20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xebf24 mov r12, r4 */
/* @0xebf28 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebf2c ldr r3, [pc, #0x130] */
/* @0xebf30 add r3, pc, r3 */
/* @0xebf34 b 0xeb85c <_Z6DoConvjPhPKhP6VMExec+0x464> */
/* @0xebf38 ldr r0, [r4] */
/* @0xebf3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xebf40 mov r0, r4 */
/* @0xebf44 str r5, [r4] */
/* @0xebf48 str r5, [r4, #0x8] */
/* @0xebf4c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xebf50 mov r0, r4 */
/* @0xebf54 bl 0x27d1d0 <_ZdlPv> */
/* @0xebf58 b 0xebeb8 <_Z6DoConvjPhPKhP6VMExec+0xac0> */
/* @0xebf5c mov r0, r5 */
/* @0xebf60 mov r1, #0 */
/* @0xebf64 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xebf68 mov r12, r7 */
/* @0xebf6c str r0, [r7] */
/* @0xebf70 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebf74 ldr r1, [pc, #0xec] */
/* @0xebf78 mov r12, #16 */
/* @0xebf7c mov r0, r12 */
/* @0xebf80 movw r2, #0xfef */
/* @0xebf84 add r1, pc, r1 */
/* @0xebf88 mov r3, #1 */
/* @0xebf8c str r12, [sp, #0x10] */
/* @0xebf90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebf94 mov r3, r5 */
/* @0xebf98 mov r1, #0 */
/* @0xebf9c mov r2, r0 */
/* @0xebfa0 add r0, sp, #120 */
/* @0xebfa4 str r2, [sp, #0x14] */
/* @0xebfa8 str r2, [r0, #-0x54]! */
/* @0xebfac strb r1, [r2] */
/* @0xebfb0 add r1, sp, #20 */
/* @0xebfb4 add r2, sp, #16 */
/* @0xebfb8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0xebfbc mov r0, #12 */
/* @0xebfc0 bl 0x27c524 <_Znwj> */
/* @0xebfc4 ldr r5, [sp, #0x14] */
/* @0xebfc8 mov r4, r0 */
/* @0xebfcc subs r0, r5, #0 */
/* @0xebfd0 beq 0xebfd8 <_Z6DoConvjPhPKhP6VMExec+0xbe0> */
/* @0xebfd4 bl 0xb6538 <strlen@plt> */
/* @0xebfd8 str r0, [r4, #0x8] */
/* @0xebfdc mov r0, r5 */
/* @0xebfe0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xebfe4 mov r3, #1 */
/* @0xebfe8 stm r4, {r0, r3} */
/* @0xebfec ldr r0, [sp, #0x14] */
/* @0xebff0 str r4, [r7] */
/* @0xebff4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xebff8 mov r12, r7 */
/* @0xebffc b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* ---- 以下 0xec00c..0xec068 是 literal pool：objdump 把数据字译成指令/字面量，
 *      按 README 规矩保留原写法，它们不是指令。
 *      池头 0xec000 (=0.0 双精度) 与 0xec008 (=0.0f) 被 asm_index 当 padding 跳过（索引从 ebffc 直接跳到 ec00c），
 *      它们的用途由 @0xebca0 vldr d6,[pc,#856] 与 @0xebc34 vldr s14,[pc,#972] 证明；其余字是字符串/GOT 偏移。 ---- */
/* @0xec00c eorseq r2, r0, r0, asr #10 */
/* @0xec010 .word 0x002492fc */
/* @0xec014 eoreq r9, r4, r8, ror #5 */
/* @0xec018 eoreq r9, r4, r8, asr #3 */
/* @0xec01c eoreq r9, r4, r0, lsr #5 */
/* @0xec020 .word 0x00246ef8 */
/* @0xec024 eoreq r9, r4, r8, lsr #2 */
/* @0xec028 eoreq r9, r4, r4, asr #1 */
/* @0xec02c eoreq r9, r4, r0, lsl #1 */
/* @0xec030 eoreq r6, r4, r0, ror #25 */
/* @0xec034 eoreq r9, r4, r0 */
/* @0xec038 eoreq r6, r4, r8, asr r12 */
/* @0xec03c .word 0x002469d0 */
/* @0xec040 eoreq r6, r4, r4, lsr #24 */
/* @0xec044 eoreq r6, r4, r4, lsr #15 */
/* @0xec048 eoreq r6, r4, r8, lsl #20 */
/* @0xec04c .word 0x00248cb4 */
/* @0xec050 eoreq r8, r4, r4, asr #23 */
/* @0xec054 .word 0x00248bb0 */
/* @0xec058 eoreq r8, r4, r12, asr #23 */
/* @0xec05c .word 0x00248bdc */
/* @0xec060 eoreq r8, r4, r8, lsr r11 */
/* @0xec064 .word 0x00248af8 */
/* @0xec068 .word 0x002467f8 */
/* @0xec06c mlaeq r4, r0, r9, r8 */
/* ---- literal pool 结束，代码在 0xec070 继续 ---- */
/* @0xec070 mov r0, r4 */
/* @0xec074 bl 0xb66c4 <atol@plt> */
/* @0xec078 mov r12, r7 */
/* @0xec07c asr r1, r0, #31 */
/* @0xec080 strd r0, r1, [r7] */
/* @0xec084 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec088 ldr r1, [pc, #-0x24] */
/* @0xec08c mov r0, r4 */
/* @0xec090 add r1, pc, r1 */
/* @0xec094 bl 0xb6574 <strcmp@plt> */
/* @0xec098 mov r12, r7 */
/* @0xec09c rsbs r0, r0, #1 */
/* @0xec0a0 movlo r0, #0 */
/* @0xec0a4 str r0, [r7] */
/* @0xec0a8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0ac mov r0, r4 */
/* @0xec0b0 mov r1, r4 */
/* @0xec0b4 bl 0xb6658 <strtod@plt> */
/* @0xec0b8 mov r12, r7 */
/* @0xec0bc strd r0, r1, [r7] */
/* @0xec0c0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0c4 mov r0, r4 */
/* @0xec0c8 bl 0xb66b8 <atoi@plt> */
/* @0xec0cc mov r12, r7 */
/* @0xec0d0 str r0, [r7] */
/* @0xec0d4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0d8 mov r0, r4 */
/* @0xec0dc mov r1, r4 */
/* @0xec0e0 bl 0xb6658 <strtod@plt> */
/* @0xec0e4 mov r12, r7 */
/* @0xec0e8 vmov d6, r0, r1 */
/* @0xec0ec vcvt.f32.f64 s15, d6 */
/* @0xec0f0 vstr s15, [r7] */
/* @0xec0f4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0f8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xec0fc mov r7, r5 */
/* @0xec100 b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */
