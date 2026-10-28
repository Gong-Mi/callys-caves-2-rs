/* cally 逆向卡：DoSub（原版 libyoyo.so，armv7）
 * @func 0xdd500 0xddd64 size 2152  538 条指令（含 literal 词）
 * 级别: 骨架（arg 位域 / 双格式码分派 / 9 条算术内核 / 全部错误分支已证；返回值口径与 5 路径指针未定，不升正文）
 * 符号: _Z5DoSubjPhPKhP6VMExec → uchar* DoSub(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   慢路径开关 = bits[11:8] 恰等于 1（不是"非零"）：@0xdd500 ubfx r2, r0, #0x8, #0x4 —— bits[11:8]；@0xdd508 cmp r2, #1 —— 与 1 比较；@0xdd520 beq 0xdda70 <_Z5DoSubjPhPKhP6VMExec+0x570> —— 相等才跳 0xdda70
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt：**高 nibble 是 A（左操作数）的格式码，低 nibble 是 B 的**：@0xdd50c lsr r5, r0, #16 —— arg>>16；@0xdd51c uxtb r4, r5 —— uxtb 取整字节
 *   表1 按 **B 的格式码**（低 nibble）定 A 的地址：B 是 8 字节(0/3)→A=arg2+8，4 字节(1/2/4)→A=arg2+4：@0xdd524 and r2, r4, #15 —— 取低 nibble；@0xdd52c addls pc, pc, r2, lsl #2 —— 7 项表；@0xdd8ac add r10, r1, #8 —— A=arg2+8
 *   表2 按 **A 的格式码**（高 nibble）算 r6=A+4 / A+8（= A 槽的末尾）：@0xdd568 asr r2, r5, #4 —— asr #4；@0xdd570 addls pc, pc, r2, lsl #2 —— 第二级表；@0xdd89c add r6, r10, #4 —— r6=A+4
 *   B 永远从 [arg2] 读、A 从 arg2+4/arg2+8 读（[B][A] 背靠背）：@0xdd91c vldr d7, [r9] —— d7=[r9]=[arg2]=B
 *   表3 按整字节 (Afmt<<4)|Bfmt（0..101）→ dest：@0xdd5ac addls pc, pc, r4, lsl #2 —— 102 项表；逐项核对等价于 dest=A+size(A)−max(size(A),size(B))
 *   表4 按同一字节（0..51）→ 9 条算术内核；带 1（字符串）的组合一律 VMError：@0xdd75c addls pc, pc, r5, lsl #2 —— 52 项表
 *   结果 tag：0=double、7=int32（写 4 字节）、10=int64（写 8 字节），且只在 r7≠0 时写 [r7+0xc]：@0xdd938 str r12, [r7, #0xc] —— tag 写回
 *   三档宽度闭环：real→@0xdd920 vsub.f64 d7, d6, d7 —— vsub.f64；int32→@0xdd96c rsb r3, r3, r2 —— rsb 32 位；int64→@0xdd950 subs r4, r4, r2 —— 64 位相减低半
 *   格式码 5 = 该操作数是 16 字节带 tag 的 RValue，按 [X+0xc] 的 tag 改写另一侧的 nibble：@0xdd8cc addls pc, pc, r3, lsl #2 —— A 侧 14 项表
 *   慢路径 = boxType×2 + F_JS_ToNumber×2 + vsub：@0xdda80 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> —— boxType(sp+16,Bfmt,arg2)；@0xdda90 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> —— boxType(sp,Afmt,ret)
 *   未解析引用（tag & 0x00FFFFFF == 全 1）→ JSThrowReferenceError：@0xddaa0 cmp r3, r12 —— 与 0x00FFFFFF 比
 *
 * 结论（新增 4 条硬事实）：
 *   1. 二元算术处理器的 arg 是**两条 4 位格式码**：bits[23:20]=A、bits[19:16]=B；A 的地址由 B 的宽度决定、r6 由 A 的宽度决定，
 *      两者背靠背排布（[arg2]=B，[arg2+size(B)]=A），所以混合宽度不重叠。
 *   2. 同一字节再当**类型对**用（(Atype<<4)|Btype）：表4 只认 (0,0)(0,2)(0,3)(2,0)(2,2)(2,3)(3,0)(3,2)(3,3) 九组；
 *      类型码 0=real、2=int32、3=int64、1=string（直接报错）。格式码同时是宽度类（0/3=8 字节、1/2/4=4 字节、5=16 字节）。
 *   3. 表3 的 dest 偏移可逐项复算为 dest = A + size(A) − max(size(A),size(B))（size: 0→8、2→4、3→8、5→16），
 *      102 项全部命中；字符串与非法格式的组合落到 r8=r7=0 的无 dest 出口。
 *   4. 每个错误分支都是 VMError(exec,fmt) 之后**只写结果 tag、不写值**再返回，不 longjmp；只有慢路径两处 JSThrow* 是 JS 式抛出。
 * 备注：本卡把**高 nibble**(bits[23:20]) 记为 A（左操作数）、低 nibble(bits[19:16]) 记为 B。这个左右顺序不是猜的——
 *   减法用 rsb/subs 取 A−B、除法用 vdiv 取 A/B、取余用 __divsi3(A,B)、移位用 lsl 把 A 当被移位值，四处非对称指令
 *   一起把方向钉死；同批 DoShr/DoMul/DoMod/DoOr 的卡因运算符可交换而把低位 nibble 记作 opA，两者描述的是同一组槽位。
 * open：
 *   · 格式码 5（16 字节 RValue）路径里 r6/A 的落点在 DoSub 与 DoXor 中写法不同（0xddba0 加在 r10，0xe07b0 加在 r6），
 *     本卡只钉了"按 tag 改写 nibble"这一层，指针算术未统一。
 *   · 返回值是"新 sp"还是"新 ip"未定：本函数从不读 arg3(base)；VM::ExecRelease 装 r0=指令字、r1=exec[0x28] 再 blx，
 *     故 arg2 应是操作数栈顶，但快路径把 4/8 字节裸值当操作数、慢路径才 box 成 16 字节 RValue。
 *   · 尾部 0xddd24..0xddd64 是 literal pool（objdump 译成 eoreq/mla），逐字保留。
 */
/* @0xdd500 ubfx r2, r0, #0x8, #0x4 */
/* @0xdd504 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdd508 cmp r2, #1 */
/* @0xdd50c lsr r5, r0, #16 */
/* @0xdd510 sub sp, sp, #68 */
/* @0xdd514 mov r9, r1 */
/* @0xdd518 mov r11, r3 */
/* @0xdd51c uxtb r4, r5 */
/* @0xdd520 beq 0xdda70 <_Z5DoSubjPhPKhP6VMExec+0x570> */
/* @0xdd524 and r2, r4, #15   ——取 B 的 nibble */
/* @0xdd528 cmp r2, #6 */
/* @0xdd52c addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xdd8ac, 1-2→0xdd8b8, 3→0xdd8ac, 4→0xdd8b8, 5→0xdd8c4, 6→0xdd550 */
/* @0xdd530 b 0xddd10 <_Z5DoSubjPhPKhP6VMExec+0x810> */
/* @0xdd534 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd538 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd53c b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd540 b 0xdd8ac <_Z5DoSubjPhPKhP6VMExec+0x3ac> */
/* @0xdd544 b 0xdd8b8 <_Z5DoSubjPhPKhP6VMExec+0x3b8> */
/* @0xdd548 b 0xdd8c4 <_Z5DoSubjPhPKhP6VMExec+0x3c4> */
/* @0xdd54c b 0xdd550 <_Z5DoSubjPhPKhP6VMExec+0x50>   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xdd550 ldr r1, [pc, #0x7cc]   ——VMError/JSThrow 文案：'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xdd554 mov r0, r3 */
/* @0xdd558 mov r5, r4 */
/* @0xdd55c mov r10, r9 */
/* @0xdd560 add r1, pc, r1 */
/* @0xdd564 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd568 asr r2, r5, #4   ——取 A 的 nibble */
/* @0xdd56c cmp r2, #6 */
/* @0xdd570 addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xdd8a4, 1-2→0xdd89c, 3→0xdd8a4, 4→0xdd89c, 5→0xdd854, 6→0xdd594 */
/* @0xdd574 b 0xddd1c <_Z5DoSubjPhPKhP6VMExec+0x81c> */
/* @0xdd578 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd57c b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd580 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd584 b 0xdd8a4 <_Z5DoSubjPhPKhP6VMExec+0x3a4> */
/* @0xdd588 b 0xdd89c <_Z5DoSubjPhPKhP6VMExec+0x39c> */
/* @0xdd58c b 0xdd854 <_Z5DoSubjPhPKhP6VMExec+0x354> */
/* @0xdd590 b 0xdd594 <_Z5DoSubjPhPKhP6VMExec+0x94>   ——Afmt=6 → VMError */
/* @0xdd594 ldr r1, [pc, #0x78c]   ——VMError/JSThrow 文案：'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xdd598 mov r0, r11 */
/* @0xdd59c mov r6, r10 */
/* @0xdd5a0 add r1, pc, r1 */
/* @0xdd5a4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdd5a8 cmp r4, #101 */
/* @0xdd5ac addls pc, pc, r4, lsl #2   ——表：按 r4 0→0xdd844, 1→0xdd90c, 2-3→0xdd844, 4→0xdd90c, 5→0xdd834, 6-31→0xdd90c, 32→0xdd844, 33→0xdd90c, 34→0xdd74c, 35→0xdd844, 36→0xdd90c, 37→0xdd834, 38-47→0xdd90c, 48→0xdd844, 49→0xdd90c, 50-51→0xdd844, 52→0xdd90c, 53→0xdd834, 54-79→0xdd90c, 80→0xdd834, 81→0xdd90c, 82-83→0xdd834, 84→0xdd90c, 85-86→0xdd834, 87-100→0xdd90c, 101→0xdd834 */
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
/* @0xdd75c addls pc, pc, r5, lsl #2   ——表：按 r5 0→0xdd918, 1→0xdda28, 2→0xdd9b4, 3→0xdd994, 4-31→0xdda28, 32→0xdd978, 33→0xdda28, 34→0xdd960, 35→0xdd9f0, 36-47→0xdda28, 48→0xdd9d0, 49→0xdda28, 50→0xdda0c, 51→0xdd944 */
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
/* @0xdd85c addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xddc88, 1→0xddc74, 2→0xddc60, 3→0xddc4c, 4→0xddcb8, 5→0xddc38, 6→0xddcb8, 7→0xddc2c, 8-9→0xddcb8, 10→0xddc1c, 11-12→0xddcb8, 13→0xddc88 */
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
/* @0xdd89c add r6, r10, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xdd8a0 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8a4 add r6, r10, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xdd8a8 b 0xdd5a8 <_Z5DoSubjPhPKhP6VMExec+0xa8> */
/* @0xdd8ac add r10, r1, #8   ——Bfmt 0/3（B 8 字节）→ A=arg2+8 */
/* @0xdd8b0 mov r5, r4 */
/* @0xdd8b4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8b8 add r10, r1, #4   ——Bfmt 1/2/4（B 4 字节）→ A=arg2+4 */
/* @0xdd8bc mov r5, r4 */
/* @0xdd8c0 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xdd8c4 ldr r3, [r1, #0xc]   ——Bfmt 5：B 是 16 字节 RValue，读 [arg2+0xc] 的 tag */
/* @0xdd8c8 cmp r3, #13 */
/* @0xdd8cc addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xddc14, 1→0xddbfc, 2→0xddbe4, 3→0xddbcc, 4→0xddca0, 5→0xddbb4, 6→0xddca0, 7→0xddba8, 8-9→0xddca0, 10→0xddb98, 11-12→0xddca0, 13→0xddc14 */
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
/* @0xdda28 ldr r1, [pc, #0x2fc]   ——VMError/JSThrow 文案：'DoSub:: Execution Error' */
/* @0xdda2c mov r0, r11 */
/* @0xdda30 add r1, pc, r1 */
/* @0xdda34 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdda38 mov r12, #0 */
/* @0xdda3c b 0xdd92c <_Z5DoSubjPhPKhP6VMExec+0x42c> */
/* @0xdda40 ldr r0, [pc, #0x2e8]   ——VMError/JSThrow 文案：'Could not convert right-hand-side of subtraction operator to a n' */
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
/* @0xddb24 sub r5, r6, #16   ——慢路径：结果槽 = sp-16 */
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
/* @0xddba0 add r10, r9, #16   ——Bfmt=5 时 A 顺延到 arg2+16 */
/* @0xddba4 b 0xdd568 <_Z5DoSubjPhPKhP6VMExec+0x68> */
/* @0xddba8 and r5, r5, #240 */
/* @0xddbac orr r5, r5, #2 */
/* @0xddbb0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbb4 ldr r1, [pc, #0x178]   ——VMError/JSThrow 文案：'DoSub :1: undefined value' */
/* @0xddbb8 mov r0, r11 */
/* @0xddbbc mov r5, r4 */
/* @0xddbc0 add r1, pc, r1 */
/* @0xddbc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbc8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbcc ldr r1, [pc, #0x164]   ——VMError/JSThrow 文案：'DoSub :1: illegal pointer use' */
/* @0xddbd0 mov r0, r11 */
/* @0xddbd4 mov r5, r4 */
/* @0xddbd8 add r1, pc, r1 */
/* @0xddbdc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbe0 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbe4 ldr r1, [pc, #0x150]   ——VMError/JSThrow 文案：'DoSub :1: illegal array use' */
/* @0xddbe8 mov r0, r11 */
/* @0xddbec mov r5, r4 */
/* @0xddbf0 add r1, pc, r1 */
/* @0xddbf4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddbf8 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddbfc ldr r1, [pc, #0x13c]   ——VMError/JSThrow 文案：'DoSub :: Execution Engine - Cannot operate on string type' */
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
/* @0xddc38 ldr r1, [pc, #0x104]   ——VMError/JSThrow 文案：'DoSub :2: undefined value' */
/* @0xddc3c mov r0, r11 */
/* @0xddc40 add r1, pc, r1 */
/* @0xddc44 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc48 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc4c ldr r1, [pc, #0xf4]   ——VMError/JSThrow 文案：'DoSub :2: illegal pointer use' */
/* @0xddc50 mov r0, r11 */
/* @0xddc54 add r1, pc, r1 */
/* @0xddc58 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc5c b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc60 ldr r1, [pc, #0xe4]   ——VMError/JSThrow 文案：'DoSub :2: illegal array use' */
/* @0xddc64 mov r0, r11 */
/* @0xddc68 add r1, pc, r1 */
/* @0xddc6c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddc70 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddc74 ldr r1, [pc, #0xd4]   ——VMError/JSThrow 文案：'DoSub :: Execution Engine - Cannot operate on string type' */
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
/* @0xddca0 ldr r1, [pc, #0xac]   ——VMError/JSThrow 文案：'DoSub :1: Malformed variable' */
/* @0xddca4 mov r0, r11 */
/* @0xddca8 mov r5, r4 */
/* @0xddcac add r1, pc, r1 */
/* @0xddcb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcb4 b 0xddba0 <_Z5DoSubjPhPKhP6VMExec+0x6a0> */
/* @0xddcb8 ldr r1, [pc, #0x98]   ——VMError/JSThrow 文案：'DoSub :2: Malformed variable' */
/* @0xddcbc mov r0, r11 */
/* @0xddcc0 add r1, pc, r1 */
/* @0xddcc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xddcc8 b 0xddc24 <_Z5DoSubjPhPKhP6VMExec+0x724> */
/* @0xddccc ldr r0, [pc, #0x88]   ——VMError/JSThrow 文案："could not find variable after '-'" */
/* @0xddcd0 add r0, pc, r0 */
/* @0xddcd4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcd8 mov r0, r6 */
/* @0xddcdc b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddce0 ldr r0, [pc, #0x78]   ——VMError/JSThrow 文案："could not find variable before '-'" */
/* @0xddce4 add r0, pc, r0 */
/* @0xddce8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xddcec mov r0, r6 */
/* @0xddcf0 b 0xdd93c <_Z5DoSubjPhPKhP6VMExec+0x43c> */
/* @0xddcf4 ldr r0, [pc, #0x68]   ——VMError/JSThrow 文案：'Could not convert left-hand-side of subtraction operator to a nu' */
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
/* @0xddd24 eoreq r5, r5, r12, asr #22   ——literal pool：+0x255b4c → 0x3330b4 (非指令) 'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xddd28 eoreq r5, r5, r12, lsl #22   ——literal pool：+0x255b0c → 0x3330b4 (非指令) 'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xddd2c eoreq r5, r5, r8, lsr #15   ——literal pool：+0x2557a8 → 0x3331e0 (非指令) 'DoSub:: Execution Error' */
/* @0xddd30 eoreq r5, r5, r0, lsr #12   ——literal pool：+0x255620 → 0x33306c (非指令) 'Could not convert right-hand-side of subtraction operator to a n' */
/* @0xddd34 eoreq r5, r5, r8, asr #10   ——literal pool：+0x255548 → 0x333110 (非指令) 'DoSub :1: undefined value' */
/* @0xddd38 eoreq r5, r5, r0, lsl r5   ——literal pool：+0x255510 → 0x3330f0 (非指令) 'DoSub :1: illegal pointer use' */
/* @0xddd3c eoreq r5, r5, r4, lsr r5   ——literal pool：+0x255534 → 0x33312c (非指令) 'DoSub :1: illegal array use' */
/* @0xddd40 eoreq r5, r5, r4, lsr #9   ——literal pool：+0x2554a4 → 0x3330b4 (非指令) 'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xddd44 eoreq r5, r5, r0, asr #10   ——literal pool：+0x255540 → 0x333188 (非指令) 'DoSub :2: undefined value' */
/* @0xddd48 eoreq r5, r5, r12, lsl #10   ——literal pool：+0x25550c → 0x333168 (非指令) 'DoSub :2: illegal pointer use' */
/* @0xddd4c eoreq r5, r5, r4, lsr r5   ——literal pool：+0x255534 → 0x3331a4 (非指令) 'DoSub :2: illegal array use' */
/* @0xddd50 eoreq r5, r5, r0, lsr r4   ——literal pool：+0x255430 → 0x3330b4 (非指令) 'DoSub :: Execution Engine - Cannot operate on string type' */
/* @0xddd54 mlaeq r5, r4, r4, r5   ——literal pool：+0x255494 → 0x333148 (非指令) 'DoSub :1: Malformed variable' */
/* @0xddd58 .word 0x002554f8   ——literal pool：+0x2554f8 → 0x3331c0 (非指令) 'DoSub :2: Malformed variable' */
/* @0xddd5c eoreq r5, r5, r8, lsr #6   ——literal pool：+0x255328 → 0x333000 (非指令) "could not find variable after '-'" */
/* @0xddd60 .word 0x002552f0   ——literal pool：+0x2552f0 → 0x332fdc (非指令) "could not find variable before '-'" */
/* @0xddd64 eoreq r5, r5, r4, lsr #6   ——literal pool：+0x255324 → 0x333024 (非指令) 'Could not convert left-hand-side of subtraction operator to a nu' */
