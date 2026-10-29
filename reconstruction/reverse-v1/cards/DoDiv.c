/* cally 逆向卡：DoDiv —— GML 除法的数值塔（原版 libyoyo.so，armv7）
 * @func 0xddd68 0xde5e4  size 2172  543 条
 * 级别: 正文（四条算术路径与它们的调用目标逐条落锚；错误串与除零处理 open）
 * 符号 _Z5DoDivjPhPKhP6VMExec
 *
 * ── **与 DoSub 的关键差异：除法保留整型路径** ─────────────────────────────
 *   DoSub 全程只有 vsub.f64（int32/int64 都提升成 double，见 cards/DoSub.c），
 *   而 DoDiv 同时存在整型除法与浮点除法：
 *     int32  / int32   0xde19c bl __divsi3                ← 无浮点、截断式整型除
 *     int64  / int64   0xde17c / 0xde1e0 / 0xde204 bl __aeabi_ldivmod
 *     int64  → double  0xde1b0 / 0xde218 bl __floatdidf 后再 vdiv.f64
 *     任一侧为 real    0xde148 / 0xde1c0 / 0xde228 / 0xde244 / 0xde260 / 0xde374 vdiv.f64
 *   ⇒ 「减法把整数提升成 double、除法保持整数除法」是不对称的，Rust VM 不能把四则运算统一成一个 f64 路径
 *
 * ── 字符串操作数 ───────────────────────────────────────────────────────
 *   0xde2c4 / 0xde2d4 bl boxType（先归一 RValue 类型）→ 0xde330 / 0xde350 bl F_JS_ToNumber
 *   ⇒ 含字符串时走 JS ToNumber 转换，再进上面四条数值路径
 *
 * ── 错误面（19 个 throw/error 站点）──────────────────────────────────────
 *   15 处 bl VMError(VMExec*, char const*, ...)：0xdddcc 0xdde0c 0xde278 0xde3e8 0xde420 0xde438 0xde450
 *        0xde468 0xde4a0 0xde4b4 0xde4c8 0xde4dc 0xde50c 0xde520 0xde548
 *   2 处 bl JSThrowTypeError(0xde28c, 0xde570)／2 处 bl JSThrowReferenceError(0xde530, 0xde55c)
 *   3 处 bl FREE_RValue__Pre(0xde3d0, 0xde4f0, 0xde57c) —— 出错/收尾时释放临时 RValue
 *   ⚠ 字符串表里确有按算子分开的文案（"...of '*' operator to a number"、"...subtraction operator..."、
 *     "Divide by zero" @0x332979），但**哪一个被本函数的哪个 VMError 用掉尚未证到**（VMError 的格式串在
 *     调用前不是简单的 pc 相对 ldr，回溯没解出来）——列入 open，不按名字猜。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1 15 个 VMError 各自的格式串与触发条件（除零走哪一条）
 *   2 类型门用到的 tag 立即数与 0x532/0x5xx 之类常量
 *   3 int32 除法在除数为 0 时的行为（__divsi3 的 libgcc 语义 vs GML 语义）
 */
/* @0xddd68 ubfx r2, r0, #0x8, #0x4 */
/* @0xddd6c lsr r0, r0, #16 */
/* @0xddd70 cmp r2, #1 */
/* @0xddd74 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xddd78 mov r10, r1 */
/* @0xddd7c sub sp, sp, #64 */
/* @0xddd80 mov r9, r3 */
/* @0xddd84 uxtb r4, r0 */
/* @0xddd88 beq 0xde2b4 <_Z5DoDivjPhPKhP6VMExec+0x54c> */
/* @0xddd8c and r3, r4, #15 */
/* @0xddd90 cmp r3, #6 */
/* @0xddd94 addls pc, pc, r3, lsl #2 */
/* @0xddd98 b 0xde584 <_Z5DoDivjPhPKhP6VMExec+0x81c> */
/* @0xddd9c b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xddda0 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda4 b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xddda8 b 0xde0d4 <_Z5DoDivjPhPKhP6VMExec+0x36c> */
/* @0xdddac b 0xde0e0 <_Z5DoDivjPhPKhP6VMExec+0x378> */
/* @0xdddb0 b 0xde0ec <_Z5DoDivjPhPKhP6VMExec+0x384> */
/* @0xdddb4 b 0xdddb8 <_Z5DoDivjPhPKhP6VMExec+0x50> */
/* @0xdddb8 ldr r1, [pc, #0x7d8] */
/* @0xdddbc mov r0, r9 */
/* @0xdddc0 mov r5, r4 */
/* @0xdddc4 mov r7, r10 */
/* @0xdddc8 add r1, pc, r1 */
/* @0xdddcc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdddd0 asr r3, r5, #4 */
/* @0xdddd4 cmp r3, #6 */
/* @0xdddd8 addls pc, pc, r3, lsl #2 */
/* @0xddddc b 0xde590 <_Z5DoDivjPhPKhP6VMExec+0x828> */
/* @0xddde0 b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xddde4 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xddde8 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddec b 0xde0cc <_Z5DoDivjPhPKhP6VMExec+0x364> */
/* @0xdddf0 b 0xde0c4 <_Z5DoDivjPhPKhP6VMExec+0x35c> */
/* @0xdddf4 b 0xde07c <_Z5DoDivjPhPKhP6VMExec+0x314> */
/* @0xdddf8 b 0xdddfc <_Z5DoDivjPhPKhP6VMExec+0x94> */
/* @0xdddfc ldr r1, [pc, #0x798] */
/* @0xdde00 mov r0, r9 */
/* @0xdde04 mov r6, r7 */
/* @0xdde08 add r1, pc, r1 */
/* @0xdde0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdde10 cmp r4, #85 */
/* @0xdde14 addls pc, pc, r4, lsl #2 */
/* @0xdde18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde1c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde24 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde28 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xdde2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde30 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xdde34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde5c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde64 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde68 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde70 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde74 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde78 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde7c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde80 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde84 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde88 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde8c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde90 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde94 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde98 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdde9c b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddea0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddea4 b 0xddf74 <_Z5DoDivjPhPKhP6VMExec+0x20c> */
/* @0xddea8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeac b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddeb4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddeb8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddebc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddec8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddecc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xdded8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddedc b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee0 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddee4 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddee8 b 0xde06c <_Z5DoDivjPhPKhP6VMExec+0x304> */
/* @0xddeec b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef0 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddef4 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddef8 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddefc b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf00 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf04 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf08 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf0c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf10 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf14 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf18 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf1c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf20 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf24 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf28 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf2c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf30 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf34 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf38 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf3c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf40 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf44 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf48 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf4c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf50 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf54 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf58 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf5c b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf60 b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf64 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf68 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf6c b 0xde134 <_Z5DoDivjPhPKhP6VMExec+0x3cc> */
/* @0xddf70 b 0xde05c <_Z5DoDivjPhPKhP6VMExec+0x2f4> */
/* @0xddf74 sub r6, r6, #4 */
/* @0xddf78 mov r4, #0 */
/* @0xddf7c mov r8, r6 */
/* @0xddf80 cmp r5, #51 */
/* @0xddf84 addls pc, pc, r5, lsl #2 */
/* @0xddf88 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf8c b 0xde140 <_Z5DoDivjPhPKhP6VMExec+0x3d8> */
/* @0xddf90 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddf94 b 0xde234 <_Z5DoDivjPhPKhP6VMExec+0x4cc> */
/* @0xddf98 b 0xde214 <_Z5DoDivjPhPKhP6VMExec+0x4ac> */
/* @0xddf9c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfa8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfac b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfb8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfbc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfc8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfcc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfd8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfdc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfe8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddfec b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff0 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff4 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddff8 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xddffc b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde000 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde004 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde008 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde00c b 0xde250 <_Z5DoDivjPhPKhP6VMExec+0x4e8> */
/* @0xde010 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde014 b 0xde18c <_Z5DoDivjPhPKhP6VMExec+0x424> */
/* @0xde018 b 0xde1cc <_Z5DoDivjPhPKhP6VMExec+0x464> */
/* @0xde01c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde020 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde024 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde028 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde02c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde030 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde034 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde038 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde03c b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde040 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde044 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde048 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde04c b 0xde1ac <_Z5DoDivjPhPKhP6VMExec+0x444> */
/* @0xde050 b 0xde26c <_Z5DoDivjPhPKhP6VMExec+0x504> */
/* @0xde054 b 0xde1f0 <_Z5DoDivjPhPKhP6VMExec+0x488> */
/* @0xde058 b 0xde16c <_Z5DoDivjPhPKhP6VMExec+0x404> */
/* @0xde05c sub r4, r6, #16 */
/* @0xde060 mov r8, r4 */
/* @0xde064 mov r6, r4 */
/* @0xde068 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde06c sub r6, r6, #8 */
/* @0xde070 mov r4, #0 */
/* @0xde074 mov r8, r6 */
/* @0xde078 b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde07c ldr r3, [r7, #0xc] */
/* @0xde080 cmp r3, #13 */
/* @0xde084 addls pc, pc, r3, lsl #2 */
/* @0xde088 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde08c b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde090 b 0xde4d0 <_Z5DoDivjPhPKhP6VMExec+0x768> */
/* @0xde094 b 0xde4bc <_Z5DoDivjPhPKhP6VMExec+0x754> */
/* @0xde098 b 0xde4a8 <_Z5DoDivjPhPKhP6VMExec+0x740> */
/* @0xde09c b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a0 b 0xde494 <_Z5DoDivjPhPKhP6VMExec+0x72c> */
/* @0xde0a4 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0a8 b 0xde488 <_Z5DoDivjPhPKhP6VMExec+0x720> */
/* @0xde0ac b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b0 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0b4 b 0xde478 <_Z5DoDivjPhPKhP6VMExec+0x710> */
/* @0xde0b8 b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0bc b 0xde514 <_Z5DoDivjPhPKhP6VMExec+0x7ac> */
/* @0xde0c0 b 0xde4e4 <_Z5DoDivjPhPKhP6VMExec+0x77c> */
/* @0xde0c4 add r6, r7, #4 */
/* @0xde0c8 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0cc add r6, r7, #8 */
/* @0xde0d0 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde0d4 add r7, r1, #8 */
/* @0xde0d8 mov r5, r4 */
/* @0xde0dc b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0e0 add r7, r1, #4 */
/* @0xde0e4 mov r5, r4 */
/* @0xde0e8 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde0ec ldr r3, [r1, #0xc] */
/* @0xde0f0 cmp r3, #13 */
/* @0xde0f4 addls pc, pc, r3, lsl #2 */
/* @0xde0f8 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde0fc b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde100 b 0xde458 <_Z5DoDivjPhPKhP6VMExec+0x6f0> */
/* @0xde104 b 0xde440 <_Z5DoDivjPhPKhP6VMExec+0x6d8> */
/* @0xde108 b 0xde428 <_Z5DoDivjPhPKhP6VMExec+0x6c0> */
/* @0xde10c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde110 b 0xde410 <_Z5DoDivjPhPKhP6VMExec+0x6a8> */
/* @0xde114 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde118 b 0xde404 <_Z5DoDivjPhPKhP6VMExec+0x69c> */
/* @0xde11c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde120 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde124 b 0xde3f4 <_Z5DoDivjPhPKhP6VMExec+0x68c> */
/* @0xde128 b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde12c b 0xde4fc <_Z5DoDivjPhPKhP6VMExec+0x794> */
/* @0xde130 b 0xde470 <_Z5DoDivjPhPKhP6VMExec+0x708> */
/* @0xde134 mov r8, #0 */
/* @0xde138 mov r4, r8 */
/* @0xde13c b 0xddf80 <_Z5DoDivjPhPKhP6VMExec+0x218> */
/* @0xde140 vldr d6, [r7] */
/* @0xde144 vldr d7, [r10] */
/* @0xde148 vdiv.f64 d7, d6, d7 */
/* @0xde14c mov r3, #0 */
/* @0xde150 vstr d7, [r8] */
/* @0xde154 cmp r4, #0 */
/* @0xde158 beq 0xde2a8 <_Z5DoDivjPhPKhP6VMExec+0x540> */
/* @0xde15c mov r0, r6 */
/* @0xde160 str r3, [r4, #0xc] */
/* @0xde164 add sp, sp, #64 */
/* @0xde168 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde16c ldrd r2, r3, [r10] */
/* @0xde170 orrs r1, r2, r3 */
/* @0xde174 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde178 ldrd r0, r1, [r7] */
/* @0xde17c bl 0x319414 <__aeabi_ldivmod> */
/* @0xde180 mov r3, #10 */
/* @0xde184 strd r0, r1, [r8] */
/* @0xde188 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde18c ldr r1, [r10] */
/* @0xde190 cmp r1, #0 */
/* @0xde194 beq 0xde53c <_Z5DoDivjPhPKhP6VMExec+0x7d4> */
/* @0xde198 ldr r0, [r7] */
/* @0xde19c bl 0x318d10 <__divsi3> */
/* @0xde1a0 mov r3, #7 */
/* @0xde1a4 str r0, [r8] */
/* @0xde1a8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1ac ldrd r0, r1, [r7] */
/* @0xde1b0 bl 0x319164 <__floatdidf> */
/* @0xde1b4 vldr d7, [r10] */
/* @0xde1b8 mov r3, #0 */
/* @0xde1bc vmov d6, r0, r1 */
/* @0xde1c0 vdiv.f64 d7, d6, d7 */
/* @0xde1c4 vstr d7, [r8] */
/* @0xde1c8 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1cc ldrd r2, r3, [r10] */
/* @0xde1d0 orrs r1, r2, r3 */
/* @0xde1d4 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1d8 ldr r0, [r7] */
/* @0xde1dc asr r1, r0, #31 */
/* @0xde1e0 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde1e4 mov r3, #10 */
/* @0xde1e8 strd r0, r1, [r8] */
/* @0xde1ec b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde1f0 ldr r2, [r10] */
/* @0xde1f4 cmp r2, #0 */
/* @0xde1f8 beq 0xde3dc <_Z5DoDivjPhPKhP6VMExec+0x674> */
/* @0xde1fc ldrd r0, r1, [r7] */
/* @0xde200 asr r3, r2, #31 */
/* @0xde204 bl 0x319414 <__aeabi_ldivmod> */
/* @0xde208 mov r3, #10 */
/* @0xde20c strd r0, r1, [r8] */
/* @0xde210 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde214 ldrd r0, r1, [r10] */
/* @0xde218 bl 0x319164 <__floatdidf> */
/* @0xde21c vldr d7, [r7] */
/* @0xde220 mov r3, #0 */
/* @0xde224 vmov d5, r0, r1 */
/* @0xde228 vdiv.f64 d7, d7, d5 */
/* @0xde22c vstr d7, [r8] */
/* @0xde230 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde234 vldr s14, [r10] */
/* @0xde238 vcvt.f64.s32 d7, s14 */
/* @0xde23c vldr d6, [r7] */
/* @0xde240 mov r3, #0 */
/* @0xde244 vdiv.f64 d7, d6, d7 */
/* @0xde248 vstr d7, [r8] */
/* @0xde24c b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde250 vldr s14, [r7] */
/* @0xde254 vcvt.f64.s32 d7, s14 */
/* @0xde258 vldr d6, [r10] */
/* @0xde25c mov r3, #0 */
/* @0xde260 vdiv.f64 d7, d7, d6 */
/* @0xde264 vstr d7, [r8] */
/* @0xde268 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde26c ldr r1, [pc, #0x32c] */
/* @0xde270 mov r0, r9 */
/* @0xde274 add r1, pc, r1 */
/* @0xde278 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde27c mov r3, #0 */
/* @0xde280 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde284 ldr r0, [pc, #0x318] */
/* @0xde288 add r0, pc, r0 */
/* @0xde28c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde290 ldr r3, [sp, #0x2c] */
/* @0xde294 sub r3, r3, #1 */
/* @0xde298 bic r3, r3, #-16777216 */
/* @0xde29c bic r3, r3, #3 */
/* @0xde2a0 cmp r3, #0 */
/* @0xde2a4 beq 0xde4ec <_Z5DoDivjPhPKhP6VMExec+0x784> */
/* @0xde2a8 mov r0, r6 */
/* @0xde2ac add sp, sp, #64 */
/* @0xde2b0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xde2b4 add r5, sp, #16 */
/* @0xde2b8 mov r2, r1 */
/* @0xde2bc and r1, r4, #15 */
/* @0xde2c0 mov r0, r5 */
/* @0xde2c4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2c8 lsr r1, r4, #4 */
/* @0xde2cc mov r2, r0 */
/* @0xde2d0 mov r0, sp */
/* @0xde2d4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xde2d8 ldr r3, [sp, #0xc] */
/* @0xde2dc mvn r12, #-16777216 */
/* @0xde2e0 and r3, r3, r12 */
/* @0xde2e4 cmp r3, r12 */
/* @0xde2e8 mov r6, r0 */
/* @0xde2ec beq 0xde554 <_Z5DoDivjPhPKhP6VMExec+0x7ec> */
/* @0xde2f0 ldr r3, [sp, #0x1c] */
/* @0xde2f4 bic r3, r3, #-16777216 */
/* @0xde2f8 cmp r3, r12 */
/* @0xde2fc beq 0xde528 <_Z5DoDivjPhPKhP6VMExec+0x7c0> */
/* @0xde300 add r4, sp, #32 */
/* @0xde304 mov r1, sp */
/* @0xde308 mov r2, #0 */
/* @0xde30c mov r3, #0 */
/* @0xde310 mov r0, r4 */
/* @0xde314 str r12, [sp, #0x2c] */
/* @0xde318 str r12, [sp, #0x3c] */
/* @0xde31c mov r12, #0 */
/* @0xde320 strd r2, r3, [sp, #32] */
/* @0xde324 strd r2, r3, [sp, #48] */
/* @0xde328 str r12, [sp, #0x28] */
/* @0xde32c str r12, [sp, #0x38] */
/* @0xde330 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde334 cmp r0, #1 */
/* @0xde338 beq 0xde568 <_Z5DoDivjPhPKhP6VMExec+0x800> */
/* @0xde33c cmp r0, #0 */
/* @0xde340 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde344 add r7, sp, #48 */
/* @0xde348 mov r1, r5 */
/* @0xde34c mov r0, r7 */
/* @0xde350 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xde354 cmp r0, #1 */
/* @0xde358 beq 0xde284 <_Z5DoDivjPhPKhP6VMExec+0x51c> */
/* @0xde35c cmp r0, #0 */
/* @0xde360 bne 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde364 str r0, [r6, #-0x4] */
/* @0xde368 sub r5, r6, #16 */
/* @0xde36c vldr d6, [sp, #32] */
/* @0xde370 vldr d7, [sp, #48] */
/* @0xde374 vdiv.f64 d5, d6, d7 */
/* @0xde378 ldr r1, [sp, #0x2c] */
/* @0xde37c sub r1, r1, #1 */
/* @0xde380 bic r1, r1, #-16777216 */
/* @0xde384 bic r1, r1, #3 */
/* @0xde388 cmp r1, #0 */
/* @0xde38c vmov r2, r3, d5 */
/* @0xde390 vstr s10, [r6, #-16] */
/* @0xde394 str r3, [r6, #-0xc] */
/* @0xde398 beq 0xde578 <_Z5DoDivjPhPKhP6VMExec+0x810> */
/* @0xde39c ldr r1, [sp, #0x3c] */
/* @0xde3a0 mov r3, #0 */
/* @0xde3a4 str r3, [sp, #0x28] */
/* @0xde3a8 mov r2, #5 */
/* @0xde3ac sub r1, r1, #1 */
/* @0xde3b0 str r3, [sp, #0x20] */
/* @0xde3b4 bic r3, r1, #-16777216 */
/* @0xde3b8 str r2, [sp, #0x2c] */
/* @0xde3bc bic r3, r3, #3 */
/* @0xde3c0 cmp r3, #0 */
/* @0xde3c4 movne r0, r5 */
/* @0xde3c8 bne 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3cc mov r0, r7 */
/* @0xde3d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde3d4 mov r0, r5 */
/* @0xde3d8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde3dc ldr r1, [pc, #0x1c4] */
/* @0xde3e0 mov r0, r9 */
/* @0xde3e4 add r1, pc, r1 */
/* @0xde3e8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde3ec mov r3, #10 */
/* @0xde3f0 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde3f4 and r0, r0, #240 */
/* @0xde3f8 orr r5, r0, #3 */
/* @0xde3fc add r7, r10, #16 */
/* @0xde400 b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde404 and r0, r0, #240 */
/* @0xde408 orr r5, r0, #2 */
/* @0xde40c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde410 ldr r1, [pc, #0x194] */
/* @0xde414 mov r0, r9 */
/* @0xde418 mov r5, r4 */
/* @0xde41c add r1, pc, r1 */
/* @0xde420 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde424 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde428 ldr r1, [pc, #0x180] */
/* @0xde42c mov r0, r9 */
/* @0xde430 mov r5, r4 */
/* @0xde434 add r1, pc, r1 */
/* @0xde438 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde43c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde440 ldr r1, [pc, #0x16c] */
/* @0xde444 mov r0, r9 */
/* @0xde448 mov r5, r4 */
/* @0xde44c add r1, pc, r1 */
/* @0xde450 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde454 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde458 ldr r1, [pc, #0x158] */
/* @0xde45c mov r0, r9 */
/* @0xde460 mov r5, r4 */
/* @0xde464 add r1, pc, r1 */
/* @0xde468 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde46c b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde470 and r5, r4, #240 */
/* @0xde474 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde478 and r5, r5, #15 */
/* @0xde47c orr r5, r5, #48 */
/* @0xde480 add r6, r7, #16 */
/* @0xde484 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde488 and r5, r5, #15 */
/* @0xde48c orr r5, r5, #32 */
/* @0xde490 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde494 ldr r1, [pc, #0x120] */
/* @0xde498 mov r0, r9 */
/* @0xde49c add r1, pc, r1 */
/* @0xde4a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4a4 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4a8 ldr r1, [pc, #0x110] */
/* @0xde4ac mov r0, r9 */
/* @0xde4b0 add r1, pc, r1 */
/* @0xde4b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4b8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4bc ldr r1, [pc, #0x100] */
/* @0xde4c0 mov r0, r9 */
/* @0xde4c4 add r1, pc, r1 */
/* @0xde4c8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4cc b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4d0 ldr r1, [pc, #0xf0] */
/* @0xde4d4 mov r0, r9 */
/* @0xde4d8 add r1, pc, r1 */
/* @0xde4dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde4e0 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4e4 and r5, r5, #15 */
/* @0xde4e8 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde4ec mov r0, r4 */
/* @0xde4f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde4f4 mov r0, r6 */
/* @0xde4f8 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde4fc ldr r1, [pc, #0xc8] */
/* @0xde500 mov r0, r9 */
/* @0xde504 mov r5, r4 */
/* @0xde508 add r1, pc, r1 */
/* @0xde50c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde510 b 0xde3fc <_Z5DoDivjPhPKhP6VMExec+0x694> */
/* @0xde514 ldr r1, [pc, #0xb4] */
/* @0xde518 mov r0, r9 */
/* @0xde51c add r1, pc, r1 */
/* @0xde520 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde524 b 0xde480 <_Z5DoDivjPhPKhP6VMExec+0x718> */
/* @0xde528 ldr r0, [pc, #0xa4] */
/* @0xde52c add r0, pc, r0 */
/* @0xde530 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde534 mov r0, r6 */
/* @0xde538 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde53c ldr r1, [pc, #0x94] */
/* @0xde540 mov r0, r9 */
/* @0xde544 add r1, pc, r1 */
/* @0xde548 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xde54c mov r3, #7 */
/* @0xde550 b 0xde154 <_Z5DoDivjPhPKhP6VMExec+0x3ec> */
/* @0xde554 ldr r0, [pc, #0x80] */
/* @0xde558 add r0, pc, r0 */
/* @0xde55c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xde560 mov r0, r6 */
/* @0xde564 b 0xde164 <_Z5DoDivjPhPKhP6VMExec+0x3fc> */
/* @0xde568 ldr r0, [pc, #0x70] */
/* @0xde56c add r0, pc, r0 */
/* @0xde570 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xde574 b 0xde290 <_Z5DoDivjPhPKhP6VMExec+0x528> */
/* @0xde578 mov r0, r4 */
/* @0xde57c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xde580 b 0xde39c <_Z5DoDivjPhPKhP6VMExec+0x634> */
/* @0xde584 mov r5, r4 */
/* @0xde588 mov r7, r1 */
/* @0xde58c b 0xdddd0 <_Z5DoDivjPhPKhP6VMExec+0x68> */
/* @0xde590 mov r6, r7 */
/* @0xde594 b 0xdde10 <_Z5DoDivjPhPKhP6VMExec+0xa8> */
/* @0xde598 eoreq r5, r5, r12, asr #9 */
/* @0xde59c eoreq r5, r5, r12, lsl #9 */
/* @0xde5a0 eoreq r5, r5, r0, lsr #3 */
/* @0xde5a4 eoreq r4, r5, r12, asr #31 */
/* @0xde5a8 eoreq r5, r5, r8, lsl r0 */
/* @0xde5ac .word 0x00254ed4 */
/* @0xde5b0 mlaeq r5, r12, lr, r4 */
/* @0xde5b4 .word 0x00254efc */
/* @0xde5b8 eoreq r4, r5, r8, lsr #29 */
/* @0xde5bc eoreq r4, r5, r8, lsl #30 */
/* @0xde5c0 .word 0x00254ed4 */
/* @0xde5c4 .word 0x00254efc */
/* @0xde5c8 .word 0x00254dbc */
/* @0xde5cc eoreq r4, r5, r12, asr lr */
/* @0xde5d0 eoreq r4, r5, r0, asr #29 */
/* @0xde5d4 eoreq r4, r5, r4, asr #25 */
/* @0xde5d8 .word 0x00254eb8 */
/* @0xde5dc mlaeq r5, r8, r12, r4 */
/* @0xde5e0 eoreq r4, r5, r8, lsr #25 */
