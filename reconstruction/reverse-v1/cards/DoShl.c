/* cally 逆向卡：DoShl（原版 libyoyo.so，armv7）
 * @func 0xe0cec 0xe1564 size 2172  543 条指令（含 literal 词）
 * 级别: 骨架（arg 位域 / 双格式码分派 / 7 条内核（组合合并）/ 全部错误分支已证；返回值口径未定，不升正文）
 * 符号: _Z5DoShljPhPKhP6VMExec → uchar* DoShl(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   慢路径开关 = bits[11:8] 任一非零：@0xe0cec tst r0, #3840 —— tst 0xF00；@0xe0d04 bne 0xe0d38 <_Z5DoShljPhPKhP6VMExec+0x4c> —— bne 0xe0d38
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt（高 nibble=A）：@0xe0cf4 lsr r5, r0, #16 —— arg>>16；@0xe0d08 uxtb r4, r5 —— uxtb；@0xe0d0c and r2, r4, #15 —— 取低 nibble（B）
 *   表1 按 B 的格式码定 A 的地址：@0xe0d10 cmp r2, #6 —— 上界 6；@0xe0d14 addls pc, pc, r2, lsl #2 —— 7 项表；@0xe0dd8 add r8, r1, #8 —— B 8 字节 → A=arg2+8；@0xe10e4 add r8, r1, #4 —— B 4 字节 → A=arg2+4
 *   表2 按 A 的格式码算 r6=A+4 / A+8：@0xe0de0 asr r2, r5, #4 —— asr #4；@0xe0de8 addls pc, pc, r2, lsl #2 —— 第二级表；@0xe10dc add r6, r8, #8 —— r6=A+8
 *   操作数分工：r8=A（被移位值）、r7=arg2（位移量 B）：@0xe1290 ldr r3, [r7] —— 位移量从 [r7]=arg2 取；@0xe1288 ldr r2, [r8] —— 被移位值从 [r8]=A 取
 *   表3 按整字节（0..85）→ dest：@0xe0e20 cmp r4, #85 —— 上界 85；@0xe0e24 addls pc, pc, r4, lsl #2 —— 86 项表；等价于 dest=A+size(A)−max(size(A),size(B))
 *   表4 按同一字节（0..51）→ 7 条内核（组合被合并）：@0xe0f90 cmp r5, #51 —— 上界 51；@0xe0f94 addls pc, pc, r5, lsl #2 —— 52 项表
 *   结果 tag：0=double、7=int32、10=int64，只在 r4≠0 时写 [r4+0xc]：@0xe1194 str r12, [r4, #0xc] —— 条件写
 *   int32×int32 直接 lsl，**无 &63/&31 掩码**：@0xe1288 ldr r2, [r8] —— 入口；@0xe1294 lsl r3, r2, r3 —— lsl r3,r2,r3；@0xe128c mov r12, #7 —— tag=7
 *   int64 路径是双字移位（sub/rsb 造 n-32、32-n）：@0xe11a0 ldr r3, [r8, #0x4] —— 入口；@0xe11b4 lsl r3, r3, r2 —— 高字左移；@0xe11c4 orr r3, r3, r1, lsr r0 —— 用 lsr 补低位
 *   real 结果三条来源：A=real 先 __fixdfdi：@0xe1158 bl 0x3194a0 <__fixdfdi> —— A 截断；B=real 时用 __fixdfdi 得当位移量：@0xe1220 bl 0x3194a0 <__fixdfdi>；结果一律 __floatdidf：@0xe117c bl 0x319164 <__floatdidf>
 *   慢路径 = boxType×2 + F_JS_ToInt32×2，且**只有这里**显式掩码：@0xe0d38 add r4, sp, #16 —— box；@0xe0db8 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> —— 第一次 ToInt32；@0xe1344 and r3, r3, #31 —— and #31；@0xe1348 lsl r2, r2, r3 —— lsl
 *   非法类型（字符串/未发射组合）→ VMError('DoShl :: Execution Error')，tag 0：@0xe12d8 ldr r1, [pc, #0x250] —— VMError 调用点
 *
 * 结论（新增 4 条硬事实）：
 *   1. DoShl 的表4 把组合合并了：(real,int32) 与 (real,int64) 共用 0xe1154、(int64,int32) 与 (int64,int64) 共用 0xe11a0、
 *      (real,real) 单独 0xe11dc——因为移位只用到位移量的低位字，B 的高位无关。
 *   2. 移位量在**快路径完全不掩码**：int32 走 `lsl`（ARM 用 count&0xFF，n≥32 结果为 0），int64 走 sub/rsb 双字移位
 *      （正确区间 0..63）；只有慢路径（bits[11:8] 非零，JS 强制转换）才 `and #31`。所以同一表达式在两条路径下
 *      a<<40 的结果可能不同——这是原版的真实差异，不是转写误差。
 *   3. 实数参与的移位一律先截断成整数（A→__fixdfdi、B→__fixdfdi 得位移量），结果再 __floatdidf 回 double 并写 tag 0。
 *   4. 错误分支（含字符串组合）只写 tag 0 不写值，然后统一返回 r6。
 * 备注：本卡把**高 nibble**(bits[23:20]) 记为 A（左操作数）、低 nibble(bits[19:16]) 记为 B。这个左右顺序不是猜的——
 *   减法用 rsb/subs 取 A−B、除法用 vdiv 取 A/B、取余用 __divsi3(A,B)、移位用 lsl 把 A 当被移位值，四处非对称指令
 *   一起把方向钉死；同批 DoShr/DoMul/DoMod/DoOr 的卡因运算符可交换而把低位 nibble 记作 opA，两者描述的是同一组槽位。
 * open：
 *   · 0xe14dc/0xe14fc 两条 JS 文案写的是 "DoOr - could not convert …"（复制粘贴自按位或），与实际运算不符。
 *   · int32 路径 lsl 的 n≥32 行为是否与原版 GML 的 << 语义一致（GML 文档说 int32 移位），未做运行期核对。
 *   · 5 路径（16 字节 RValue）在 0xe13ac 处把 16 加到 r6，与 DoSub 加到 r10 不同，A 的落点未统一解释。
 *   · 返回值是"新 sp"还是"新 ip"未定；尾部 0xe1524..0xe1568 是 literal pool（objdump 译成 eoreq/mla），逐字保留。
 */
/* @0xe0cec tst r0, #3840 */
/* @0xe0cf0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe0cf4 lsr r5, r0, #16 */
/* @0xe0cf8 sub sp, sp, #64 */
/* @0xe0cfc mov r7, r1 */
/* @0xe0d00 mov r10, r3 */
/* @0xe0d04 bne 0xe0d38 <_Z5DoShljPhPKhP6VMExec+0x4c> */
/* @0xe0d08 uxtb r4, r5 */
/* @0xe0d0c and r2, r4, #15   ——取 B 的 nibble */
/* @0xe0d10 cmp r2, #6 */
/* @0xe0d14 addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xe0dd8, 1-2→0xe10e4, 3→0xe0dd8, 4→0xe10e4, 5→0xe10f0, 6→0xe1138 */
/* @0xe0d18 b 0xe1510 <_Z5DoShljPhPKhP6VMExec+0x824> */
/* @0xe0d1c b 0xe0dd8 <_Z5DoShljPhPKhP6VMExec+0xec> */
/* @0xe0d20 b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d24 b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d28 b 0xe0dd8 <_Z5DoShljPhPKhP6VMExec+0xec> */
/* @0xe0d2c b 0xe10e4 <_Z5DoShljPhPKhP6VMExec+0x3f8> */
/* @0xe0d30 b 0xe10f0 <_Z5DoShljPhPKhP6VMExec+0x404> */
/* @0xe0d34 b 0xe1138 <_Z5DoShljPhPKhP6VMExec+0x44c> */
/* @0xe0d38 add r4, sp, #16 */
/* @0xe0d3c uxtb r5, r5 */
/* @0xe0d40 mov r2, r1 */
/* @0xe0d44 and r1, r5, #15 */
/* @0xe0d48 mov r0, r4 */
/* @0xe0d4c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0d50 lsr r1, r5, #4 */
/* @0xe0d54 mov r2, r0 */
/* @0xe0d58 mov r0, sp */
/* @0xe0d5c bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0d60 ldr r3, [sp, #0xc] */
/* @0xe0d64 mvn r12, #-16777216 */
/* @0xe0d68 and r3, r3, r12 */
/* @0xe0d6c cmp r3, r12 */
/* @0xe0d70 mov r6, r0 */
/* @0xe0d74 beq 0xe14c8 <_Z5DoShljPhPKhP6VMExec+0x7dc> */
/* @0xe0d78 ldr r3, [sp, #0x1c] */
/* @0xe0d7c bic r3, r3, #-16777216 */
/* @0xe0d80 cmp r3, r12 */
/* @0xe0d84 beq 0xe12c4 <_Z5DoShljPhPKhP6VMExec+0x5d8> */
/* @0xe0d88 add r5, sp, #32 */
/* @0xe0d8c mov r1, sp */
/* @0xe0d90 mov r2, #0 */
/* @0xe0d94 mov r3, #0 */
/* @0xe0d98 mov r0, r5 */
/* @0xe0d9c str r12, [sp, #0x2c] */
/* @0xe0da0 str r12, [sp, #0x3c] */
/* @0xe0da4 mov r12, #0 */
/* @0xe0da8 strd r2, r3, [sp, #32] */
/* @0xe0dac strd r2, r3, [sp, #48] */
/* @0xe0db0 str r12, [sp, #0x28] */
/* @0xe0db4 str r12, [sp, #0x38] */
/* @0xe0db8 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe0dbc cmp r0, #1 */
/* @0xe0dc0 beq 0xe14dc <_Z5DoShljPhPKhP6VMExec+0x7f0> */
/* @0xe0dc4 cmp r0, #0 */
/* @0xe0dc8 beq 0xe12f0 <_Z5DoShljPhPKhP6VMExec+0x604> */
/* @0xe0dcc mov r0, r6 */
/* @0xe0dd0 add sp, sp, #64 */
/* @0xe0dd4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe0dd8 add r8, r1, #8   ——Bfmt 0/3 → A=arg2+8 */
/* @0xe0ddc mov r5, r4 */
/* @0xe0de0 asr r2, r5, #4   ——取 A 的 nibble */
/* @0xe0de4 cmp r2, #6 */
/* @0xe0de8 addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xe10dc, 1-2→0xe10d4, 3→0xe10dc, 4→0xe10d4, 5→0xe108c, 6→0xe0e0c */
/* @0xe0dec b 0xe151c <_Z5DoShljPhPKhP6VMExec+0x830> */
/* @0xe0df0 b 0xe10dc <_Z5DoShljPhPKhP6VMExec+0x3f0> */
/* @0xe0df4 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0df8 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0dfc b 0xe10dc <_Z5DoShljPhPKhP6VMExec+0x3f0> */
/* @0xe0e00 b 0xe10d4 <_Z5DoShljPhPKhP6VMExec+0x3e8> */
/* @0xe0e04 b 0xe108c <_Z5DoShljPhPKhP6VMExec+0x3a0> */
/* @0xe0e08 b 0xe0e0c <_Z5DoShljPhPKhP6VMExec+0x120> */
/* @0xe0e0c ldr r1, [pc, #0x710]   ——Afmt=6 → VMError */
/* @0xe0e10 mov r0, r10 */
/* @0xe0e14 mov r6, r8 */
/* @0xe0e18 add r1, pc, r1 */
/* @0xe0e1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0e20 cmp r4, #85 */
/* @0xe0e24 addls pc, pc, r4, lsl #2   ——表：按 r4 0→0xe107c, 1→0xe11d0, 2-3→0xe107c, 4→0xe11d0, 5→0xe106c, 6-31→0xe11d0, 32→0xe107c, 33→0xe11d0, 34→0xe0f84, 35→0xe107c, 36→0xe11d0, 37→0xe106c, 38-47→0xe11d0, 48→0xe107c, 49→0xe11d0, 50-51→0xe107c, 52-67→0xe11d0, 68→0xe0f84, 69-79→0xe11d0, 80→0xe106c, 81→0xe11d0, 82→0xe106c, 83-84→0xe11d0, 85→0xe106c */
/* @0xe0e28 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e2c b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e30 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e34 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e38 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0e3c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e40 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0e44 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e48 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e4c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e50 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e54 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e58 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e5c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e60 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e64 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e68 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e6c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e70 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e74 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e78 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e7c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e80 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e84 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e88 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e8c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e90 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e94 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e98 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0e9c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ea8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eac b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0eb0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eb4 b 0xe0f84 <_Z5DoShljPhPKhP6VMExec+0x298> */
/* @0xe0eb8 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ebc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ec0 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0ec4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ec8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ecc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ed8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0edc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee4 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ee8 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0eec b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ef0 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0ef4 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0ef8 b 0xe107c <_Z5DoShljPhPKhP6VMExec+0x390> */
/* @0xe0efc b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f00 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f04 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f08 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f0c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f10 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f14 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f18 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f1c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f20 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f24 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f28 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f2c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f30 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f34 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f38 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f3c b 0xe0f84 <_Z5DoShljPhPKhP6VMExec+0x298> */
/* @0xe0f40 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f44 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f48 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f4c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f50 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f54 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f58 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f5c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f60 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f64 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f68 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f6c b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f70 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f74 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f78 b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f7c b 0xe11d0 <_Z5DoShljPhPKhP6VMExec+0x4e4> */
/* @0xe0f80 b 0xe106c <_Z5DoShljPhPKhP6VMExec+0x380> */
/* @0xe0f84 sub r6, r6, #4   ——dest=r6-4 */
/* @0xe0f88 mov r4, #0 */
/* @0xe0f8c mov r9, r6 */
/* @0xe0f90 cmp r5, #51 */
/* @0xe0f94 addls pc, pc, r5, lsl #2   ——表：按 r5 0→0xe11dc, 1→0xe12d8, 2-3→0xe1154, 4-31→0xe12d8, 32→0xe12a0, 33→0xe12d8, 34→0xe1288, 35→0xe1254, 36-47→0xe12d8, 48→0xe121c, 49→0xe12d8, 50-51→0xe11a0 */
/* @0xe0f98 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0f9c b 0xe11dc <_Z5DoShljPhPKhP6VMExec+0x4f0> */
/* @0xe0fa0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fa4 b 0xe1154 <_Z5DoShljPhPKhP6VMExec+0x468> */
/* @0xe0fa8 b 0xe1154 <_Z5DoShljPhPKhP6VMExec+0x468> */
/* @0xe0fac b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fb8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fbc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fc8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fcc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fd8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fdc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fe8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0fec b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff0 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff4 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ff8 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe0ffc b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1000 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1004 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1008 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe100c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1010 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1014 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1018 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe101c b 0xe12a0 <_Z5DoShljPhPKhP6VMExec+0x5b4> */
/* @0xe1020 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1024 b 0xe1288 <_Z5DoShljPhPKhP6VMExec+0x59c> */
/* @0xe1028 b 0xe1254 <_Z5DoShljPhPKhP6VMExec+0x568> */
/* @0xe102c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1030 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1034 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1038 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe103c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1040 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1044 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1048 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe104c b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1050 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1054 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1058 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe105c b 0xe121c <_Z5DoShljPhPKhP6VMExec+0x530> */
/* @0xe1060 b 0xe12d8 <_Z5DoShljPhPKhP6VMExec+0x5ec> */
/* @0xe1064 b 0xe11a0 <_Z5DoShljPhPKhP6VMExec+0x4b4> */
/* @0xe1068 b 0xe11a0 <_Z5DoShljPhPKhP6VMExec+0x4b4> */
/* @0xe106c sub r4, r6, #16   ——dest=r6-16（r4 写 tag） */
/* @0xe1070 mov r9, r4 */
/* @0xe1074 mov r6, r4 */
/* @0xe1078 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe107c sub r6, r6, #8   ——dest=r6-8（r4=0） */
/* @0xe1080 mov r4, #0 */
/* @0xe1084 mov r9, r6 */
/* @0xe1088 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe108c ldr r3, [r8, #0xc]   ——Afmt 5：读 [A+0xc] 的 tag */
/* @0xe1090 cmp r3, #13 */
/* @0xe1094 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xe13dc, 1→0xe13c8, 2→0xe13b4, 3→0xe13f8, 4→0xe149c, 5→0xe13e4, 6→0xe149c, 7→0xe140c, 8-9→0xe149c, 10→0xe13a4, 11-12→0xe149c, 13→0xe13dc */
/* @0xe1098 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe109c b 0xe13dc <_Z5DoShljPhPKhP6VMExec+0x6f0> */
/* @0xe10a0 b 0xe13c8 <_Z5DoShljPhPKhP6VMExec+0x6dc> */
/* @0xe10a4 b 0xe13b4 <_Z5DoShljPhPKhP6VMExec+0x6c8> */
/* @0xe10a8 b 0xe13f8 <_Z5DoShljPhPKhP6VMExec+0x70c> */
/* @0xe10ac b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10b0 b 0xe13e4 <_Z5DoShljPhPKhP6VMExec+0x6f8> */
/* @0xe10b4 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10b8 b 0xe140c <_Z5DoShljPhPKhP6VMExec+0x720> */
/* @0xe10bc b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10c0 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10c4 b 0xe13a4 <_Z5DoShljPhPKhP6VMExec+0x6b8> */
/* @0xe10c8 b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10cc b 0xe149c <_Z5DoShljPhPKhP6VMExec+0x7b0> */
/* @0xe10d0 b 0xe13dc <_Z5DoShljPhPKhP6VMExec+0x6f0> */
/* @0xe10d4 add r6, r8, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xe10d8 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe10dc add r6, r8, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xe10e0 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe10e4 add r8, r1, #4   ——Bfmt 1/2/4 → A=arg2+4 */
/* @0xe10e8 mov r5, r4 */
/* @0xe10ec b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe10f0 ldr r3, [r1, #0xc]   ——Bfmt 5：读 [arg2+0xc] 的 tag */
/* @0xe10f4 cmp r3, #13 */
/* @0xe10f8 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xe144c, 1→0xe1434, 2→0xe1418, 3→0xe1484, 4→0xe14b0, 5→0xe146c, 6→0xe14b0, 7→0xe1460, 8-9→0xe14b0, 10→0xe1454, 11-12→0xe14b0, 13→0xe144c */
/* @0xe10fc b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1100 b 0xe144c <_Z5DoShljPhPKhP6VMExec+0x760> */
/* @0xe1104 b 0xe1434 <_Z5DoShljPhPKhP6VMExec+0x748> */
/* @0xe1108 b 0xe1418 <_Z5DoShljPhPKhP6VMExec+0x72c> */
/* @0xe110c b 0xe1484 <_Z5DoShljPhPKhP6VMExec+0x798> */
/* @0xe1110 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1114 b 0xe146c <_Z5DoShljPhPKhP6VMExec+0x780> */
/* @0xe1118 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe111c b 0xe1460 <_Z5DoShljPhPKhP6VMExec+0x774> */
/* @0xe1120 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1124 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1128 b 0xe1454 <_Z5DoShljPhPKhP6VMExec+0x768> */
/* @0xe112c b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1130 b 0xe14b0 <_Z5DoShljPhPKhP6VMExec+0x7c4> */
/* @0xe1134 b 0xe144c <_Z5DoShljPhPKhP6VMExec+0x760> */
/* @0xe1138 ldr r1, [pc, #0x3e8]   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xe113c mov r0, r3 */
/* @0xe1140 mov r5, r4 */
/* @0xe1144 mov r8, r7 */
/* @0xe1148 add r1, pc, r1 */
/* @0xe114c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1150 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe1154 ldrd r0, r1, [r8]   ——内核 (real,int32|int64)：A 截断成 int64 后左移，回 double，tag 0 */
/* @0xe1158 bl 0x3194a0 <__fixdfdi> */
/* @0xe115c ldr r3, [r7] */
/* @0xe1160 sub lr, r3, #32 */
/* @0xe1164 rsb r12, r3, #32 */
/* @0xe1168 mov r2, r0 */
/* @0xe116c lsl r1, r1, r3 */
/* @0xe1170 orr r1, r1, r2, lsl lr */
/* @0xe1174 lsl r0, r0, r3 */
/* @0xe1178 orr r1, r1, r2, lsr r12 */
/* @0xe117c bl 0x319164 <__floatdidf> */
/* @0xe1180 mov r12, #0 */
/* @0xe1184 strd r0, r1, [r9] */
/* @0xe1188 cmp r4, #0   ——共享尾：r4≠0 才写 tag */
/* @0xe118c beq 0xe0dcc <_Z5DoShljPhPKhP6VMExec+0xe0> */
/* @0xe1190 mov r0, r6   ——返回 r6 */
/* @0xe1194 str r12, [r4, #0xc] */
/* @0xe1198 add sp, sp, #64 */
/* @0xe119c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe11a0 ldr r3, [r8, #0x4]   ——内核 (int64,int32|int64)：双字左移，tag 10 */
/* @0xe11a4 mov r12, #10 */
/* @0xe11a8 ldr r2, [r7] */
/* @0xe11ac ldr r1, [r8] */
/* @0xe11b0 sub r5, r2, #32 */
/* @0xe11b4 lsl r3, r3, r2 */
/* @0xe11b8 rsb r0, r2, #32 */
/* @0xe11bc orr r3, r3, r1, lsl r5 */
/* @0xe11c0 lsl r2, r1, r2 */
/* @0xe11c4 orr r3, r3, r1, lsr r0 */
/* @0xe11c8 stm r9, {r2, r3} */
/* @0xe11cc b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe11d0 mov r9, #0   ——无 dest 出口 */
/* @0xe11d4 mov r4, r9 */
/* @0xe11d8 b 0xe0f90 <_Z5DoShljPhPKhP6VMExec+0x2a4> */
/* @0xe11dc ldrd r0, r1, [r8]   ——内核 (real,real)：两个 __fixdfdi → 双字左移 → __floatdidf，tag 0 */
/* @0xe11e0 bl 0x3194a0 <__fixdfdi> */
/* @0xe11e4 mov r5, r0 */
/* @0xe11e8 mov r8, r1 */
/* @0xe11ec ldrd r0, r1, [r7] */
/* @0xe11f0 bl 0x3194a0 <__fixdfdi> */
/* @0xe11f4 sub r2, r0, #32 */
/* @0xe11f8 lsl r1, r8, r0 */
/* @0xe11fc orr r1, r1, r5, lsl r2 */
/* @0xe1200 rsb r2, r0, #32 */
/* @0xe1204 orr r1, r1, r5, lsr r2 */
/* @0xe1208 lsl r0, r5, r0 */
/* @0xe120c bl 0x319164 <__floatdidf> */
/* @0xe1210 mov r12, #0 */
/* @0xe1214 strd r0, r1, [r9] */
/* @0xe1218 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe121c ldrd r0, r1, [r7]   ——内核 (int64,real)：位移量 __fixdfdi(B)，tag 0 */
/* @0xe1220 bl 0x3194a0 <__fixdfdi> */
/* @0xe1224 ldr r3, [r8, #0x4] */
/* @0xe1228 ldr r2, [r8] */
/* @0xe122c sub r12, r0, #32 */
/* @0xe1230 lsl r3, r3, r0 */
/* @0xe1234 orr r3, r3, r2, lsl r12 */
/* @0xe1238 rsb r1, r0, #32 */
/* @0xe123c orr r1, r3, r2, lsr r1 */
/* @0xe1240 lsl r0, r2, r0 */
/* @0xe1244 bl 0x319164 <__floatdidf> */
/* @0xe1248 mov r12, #0 */
/* @0xe124c strd r0, r1, [r9] */
/* @0xe1250 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe1254 ldr r1, [r8]   ——内核 (int32,int64)：A 符号扩展成 64 位再左移，tag 10 */
/* @0xe1258 mov r12, #10 */
/* @0xe125c ldr r0, [r7] */
/* @0xe1260 asr r3, r1, #31 */
/* @0xe1264 sub r5, r0, #32 */
/* @0xe1268 rsb r2, r0, #32 */
/* @0xe126c lsl r3, r3, r0 */
/* @0xe1270 lsl r0, r1, r0 */
/* @0xe1274 orr r3, r3, r1, lsl r5 */
/* @0xe1278 str r0, [r9] */
/* @0xe127c orr r3, r3, r1, lsr r2 */
/* @0xe1280 str r3, [r9, #0x4] */
/* @0xe1284 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe1288 ldr r2, [r8]   ——内核 (int32,int32)：lsl（未掩码），tag 7 */
/* @0xe128c mov r12, #7 */
/* @0xe1290 ldr r3, [r7] */
/* @0xe1294 lsl r3, r2, r3 */
/* @0xe1298 str r3, [r9] */
/* @0xe129c b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12a0 ldrd r0, r1, [r7]   ——内核 (int32,real)：lsl 后 vcvt 回 double，tag 0 */
/* @0xe12a4 bl 0x3194a0 <__fixdfdi> */
/* @0xe12a8 ldr r3, [r8] */
/* @0xe12ac mov r12, #0 */
/* @0xe12b0 lsl r0, r3, r0 */
/* @0xe12b4 vmov s11, r0 */
/* @0xe12b8 vcvt.f64.s32 d7, s11 */
/* @0xe12bc vstr d7, [r9] */
/* @0xe12c0 b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12c4 ldr r0, [pc, #0x260]   ——VMError/JSThrow 文案："could not find variable after '<<'" */
/* @0xe12c8 add r0, pc, r0 */
/* @0xe12cc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe12d0 mov r0, r6 */
/* @0xe12d4 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe12d8 ldr r1, [pc, #0x250]   ——非法组合 → VMError('DoShl :: Execution Error')，tag 0 */
/* @0xe12dc mov r0, r10 */
/* @0xe12e0 add r1, pc, r1 */
/* @0xe12e4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe12e8 mov r12, #0 */
/* @0xe12ec b 0xe1188 <_Z5DoShljPhPKhP6VMExec+0x49c> */
/* @0xe12f0 add r7, sp, #48 */
/* @0xe12f4 mov r1, r4 */
/* @0xe12f8 mov r0, r7 */
/* @0xe12fc bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe1300 cmp r0, #1 */
/* @0xe1304 beq 0xe14fc <_Z5DoShljPhPKhP6VMExec+0x810> */
/* @0xe1308 cmp r0, #0 */
/* @0xe130c bne 0xe0dcc <_Z5DoShljPhPKhP6VMExec+0xe0> */
/* @0xe1310 vldr d6, [sp, #48] */
/* @0xe1314 str r0, [r6, #-0x4] */
/* @0xe1318 vcvt.s32.f64 s11, d6 */
/* @0xe131c vldr d7, [sp, #32] */
/* @0xe1320 ldr r1, [sp, #0x2c] */
/* @0xe1324 sub r4, r6, #16 */
/* @0xe1328 sub r1, r1, #1 */
/* @0xe132c bic r1, r1, #-16777216 */
/* @0xe1330 bic r1, r1, #3 */
/* @0xe1334 cmp r1, #0 */
/* @0xe1338 vcvt.s32.f64 s13, d7 */
/* @0xe133c vmov r3, s11 */
/* @0xe1340 vmov r2, s13 */
/* @0xe1344 and r3, r3, #31 */
/* @0xe1348 lsl r2, r2, r3 */
/* @0xe134c vmov s15, r2 */
/* @0xe1350 vcvt.f64.s32 d7, s15 */
/* @0xe1354 vmov r2, r3, d7 */
/* @0xe1358 vstr s14, [r6, #-16] */
/* @0xe135c str r3, [r6, #-0xc] */
/* @0xe1360 beq 0xe14f0 <_Z5DoShljPhPKhP6VMExec+0x804> */
/* @0xe1364 ldr r1, [sp, #0x3c] */
/* @0xe1368 mov r3, #0 */
/* @0xe136c str r3, [sp, #0x28] */
/* @0xe1370 mov r2, #5 */
/* @0xe1374 sub r1, r1, #1 */
/* @0xe1378 str r3, [sp, #0x20] */
/* @0xe137c bic r3, r1, #-16777216 */
/* @0xe1380 str r2, [sp, #0x2c] */
/* @0xe1384 bic r3, r3, #3 */
/* @0xe1388 cmp r3, #0 */
/* @0xe138c movne r0, r4 */
/* @0xe1390 bne 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe1394 mov r0, r7 */
/* @0xe1398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe139c mov r0, r4 */
/* @0xe13a0 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe13a4 and r5, r5, #15 */
/* @0xe13a8 orr r5, r5, #48 */
/* @0xe13ac add r6, r8, #16   ——5 路径：A=arg2+16 */
/* @0xe13b0 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe13b4 ldr r1, [pc, #0x178]   ——VMError/JSThrow 文案：'DoShl :2: illegal array use' */
/* @0xe13b8 mov r0, r10 */
/* @0xe13bc add r1, pc, r1 */
/* @0xe13c0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13c4 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13c8 ldr r1, [pc, #0x168]   ——VMError/JSThrow 文案：'DoShl :2: Execution Engine - Cannot operate on string type' */
/* @0xe13cc mov r0, r10 */
/* @0xe13d0 add r1, pc, r1 */
/* @0xe13d4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13d8 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13dc and r5, r5, #15 */
/* @0xe13e0 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13e4 ldr r1, [pc, #0x150]   ——VMError/JSThrow 文案：'DoShl :2: undefined value' */
/* @0xe13e8 mov r0, r10 */
/* @0xe13ec add r1, pc, r1 */
/* @0xe13f0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe13f4 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe13f8 ldr r1, [pc, #0x140]   ——VMError/JSThrow 文案：'DoShl :2: illegal pointer use' */
/* @0xe13fc mov r0, r10 */
/* @0xe1400 add r1, pc, r1 */
/* @0xe1404 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1408 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe140c and r5, r5, #15 */
/* @0xe1410 orr r5, r5, #32 */
/* @0xe1414 b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe1418 ldr r1, [pc, #0x124]   ——VMError/JSThrow 文案：'DoShl :: illegal array use' */
/* @0xe141c mov r0, r10 */
/* @0xe1420 mov r5, r4 */
/* @0xe1424 add r1, pc, r1 */
/* @0xe1428 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe142c add r8, r7, #16 */
/* @0xe1430 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe1434 ldr r1, [pc, #0x10c]   ——VMError/JSThrow 文案：'DoShl :: Execution Engine - Cannot operate on string type' */
/* @0xe1438 mov r0, r10 */
/* @0xe143c mov r5, r4 */
/* @0xe1440 add r1, pc, r1 */
/* @0xe1444 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1448 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe144c and r5, r4, #240 */
/* @0xe1450 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1454 and r5, r5, #240 */
/* @0xe1458 orr r5, r5, #3 */
/* @0xe145c b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1460 and r5, r5, #240 */
/* @0xe1464 orr r5, r5, #2 */
/* @0xe1468 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe146c ldr r1, [pc, #0xd8]   ——VMError/JSThrow 文案：'DoShl :: undefined value' */
/* @0xe1470 mov r0, r10 */
/* @0xe1474 mov r5, r4 */
/* @0xe1478 add r1, pc, r1 */
/* @0xe147c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1480 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe1484 ldr r1, [pc, #0xc4]   ——VMError/JSThrow 文案：'DoShl :: illegal pointer use' */
/* @0xe1488 mov r0, r10 */
/* @0xe148c mov r5, r4 */
/* @0xe1490 add r1, pc, r1 */
/* @0xe1494 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe1498 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe149c ldr r1, [pc, #0xb0]   ——VMError/JSThrow 文案：'DoShl :2: Malformed variable' */
/* @0xe14a0 mov r0, r10 */
/* @0xe14a4 add r1, pc, r1 */
/* @0xe14a8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe14ac b 0xe13ac <_Z5DoShljPhPKhP6VMExec+0x6c0> */
/* @0xe14b0 ldr r1, [pc, #0xa0]   ——VMError/JSThrow 文案：'DoShl :: Malformed variable' */
/* @0xe14b4 mov r0, r10 */
/* @0xe14b8 mov r5, r4 */
/* @0xe14bc add r1, pc, r1 */
/* @0xe14c0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe14c4 b 0xe142c <_Z5DoShljPhPKhP6VMExec+0x740> */
/* @0xe14c8 ldr r0, [pc, #0x8c]   ——VMError/JSThrow 文案："could not find variable before '<<'" */
/* @0xe14cc add r0, pc, r0 */
/* @0xe14d0 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe14d4 mov r0, r6 */
/* @0xe14d8 b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe14dc ldr r0, [pc, #0x7c]   ——VMError/JSThrow 文案：'DoOr - could not convert lhs expr to a number' */
/* @0xe14e0 add r0, pc, r0 */
/* @0xe14e4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe14e8 mov r0, r6 */
/* @0xe14ec b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe14f0 mov r0, r5 */
/* @0xe14f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe14f8 b 0xe1364 <_Z5DoShljPhPKhP6VMExec+0x678> */
/* @0xe14fc ldr r0, [pc, #0x60]   ——VMError/JSThrow 文案：'DoOr - could not convert rhs expr to a number' */
/* @0xe1500 add r0, pc, r0 */
/* @0xe1504 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe1508 mov r0, r6 */
/* @0xe150c b 0xe0dd0 <_Z5DoShljPhPKhP6VMExec+0xe4> */
/* @0xe1510 mov r5, r4 */
/* @0xe1514 mov r8, r1 */
/* @0xe1518 b 0xe0de0 <_Z5DoShljPhPKhP6VMExec+0xf4> */
/* @0xe151c mov r6, r8 */
/* @0xe1520 b 0xe0e20 <_Z5DoShljPhPKhP6VMExec+0x134> */
/* @0xe1524 .word 0x002531b0   ——literal pool：+0x2531b0 → 0x333fd0 (非指令) 'DoShl :2: Execution Engine - Cannot operate on string type' */
/* @0xe1528 .word 0x00252dd0   ——literal pool：+0x252dd0 → 0x333f20 (非指令) 'DoShl :: Execution Engine - Cannot operate on string type' */
/* @0xe152c eoreq r2, r5, r12, lsr #24   ——literal pool：+0x252c2c → 0x333efc (非指令) "could not find variable after '<<'" */
/* @0xe1530 mlaeq r5, r12, sp, r2   ——literal pool：+0x252d9c → 0x334084 (非指令) 'DoShl :: Execution Error' */
/* @0xe1534 eoreq r2, r5, r4, lsl #25   ——literal pool：+0x252c84 → 0x334048 (非指令) 'DoShl :2: illegal array use' */
/* @0xe1538 .word 0x00252bf8   ——literal pool：+0x252bf8 → 0x333fd0 (非指令) 'DoShl :2: Execution Engine - Cannot operate on string type' */
/* @0xe153c eoreq r2, r5, r8, lsr r12   ——literal pool：+0x252c38 → 0x33402c (非指令) 'DoShl :2: undefined value' */
/* @0xe1540 eoreq r2, r5, r4, lsl #24   ——literal pool：+0x252c04 → 0x33400c (非指令) 'DoShl :2: illegal pointer use' */
/* @0xe1544 eoreq r2, r5, r12, ror #22   ——literal pool：+0x252b6c → 0x333f98 (非指令) 'DoShl :: illegal array use' */
/* @0xe1548 .word 0x00252ad8   ——literal pool：+0x252ad8 → 0x333f20 (非指令) 'DoShl :: Execution Engine - Cannot operate on string type' */
/* @0xe154c .word 0x00252afc   ——literal pool：+0x252afc → 0x333f7c (非指令) 'DoShl :: undefined value' */
/* @0xe1550 eoreq r2, r5, r4, asr #21   ——literal pool：+0x252ac4 → 0x333f5c (非指令) 'DoShl :: illegal pointer use' */
/* @0xe1554 .word 0x00252bb8   ——literal pool：+0x252bb8 → 0x334064 (非指令) 'DoShl :2: Malformed variable' */
/* @0xe1558 .word 0x00252af0   ——literal pool：+0x252af0 → 0x333fb4 (非指令) 'DoShl :: Malformed variable' */
/* @0xe155c eoreq r2, r5, r4, lsl #20   ——literal pool：+0x252a04 → 0x333ed8 (非指令) "could not find variable before '<<'" */
/* @0xe1560 eoreq r2, r5, r0, asr #8   ——literal pool：+0x252440 → 0x333928 (非指令) 'DoOr - could not convert lhs expr to a number' */
/* @0xe1564 eoreq r2, r5, r0, asr r4   ——literal pool：+0x252450 → 0x333958 (非指令) 'DoOr - could not convert rhs expr to a number' */
