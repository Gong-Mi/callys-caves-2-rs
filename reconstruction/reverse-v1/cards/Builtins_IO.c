/* cally 逆向卡：Builtins_IO（原版 libyoyo.so，armv7）—— 随机 4 个 + 文件 2 个 + ini 2 个 + 鼠标 1 个
 * 节: 9 个 @func 小节，顺序 = F_IRandomRange / F_Random / F_Randomize / F_RandomRange /
 *     F_FileDelete / F_FileExists / F_IniReadReal / F_IniWriteReal / F_MouseClear
 *     （= 索引文件的段落顺序，不是 GML 字典序）
 * 索引: asm/index-builtins_io_all.tsv —— 223 条，9 段互不连续的区间，一段一个函数
 *   0x110dec..0x110e7c  37 条  F_IRandomRange   size 148
 *   0x10dddc..0x10de30  22 条  F_Random         size 88
 *   0x10e284..0x10e2d4  21 条  F_Randomize      size 84   (池 0x10e2d4, 1 字)
 *   0x110efc..0x110f44  19 条  F_RandomRange    size 76
 *   0x138474..0x138504  37 条  F_FileDelete     size 148  (池 0x138504, 1 字)
 *   0x137acc..0x137b28  24 条  F_FileExists     size 96
 *   0x13bba4..0x13bbfc  23 条  F_IniReadReal    size 92
 *   0x13bca0..0x13bce8  19 条  F_IniWriteReal   size 76
 *   0x127618..0x127668  21 条  F_MouseClear     size 84
 * 级别: 正文（9 个函数 223 条锚点全部逐条落地、语义推到指令级；被调 helper 只钉签名/调用点/可读常量，
 *       其内部不在本卡 —— 每处都标了边界）
 * 符号（.dynsym 完整签名）:
 *   _Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_   _Z8F_RandomR6RValueP9CInstanceS2_iPS_
 *   _Z11F_RandomizeR6RValueP9CInstanceS2_iPS_      _Z14F_RandomRangeR6RValueP9CInstanceS2_iPS_
 *   _Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_     _Z12F_FileExistsR6RValueP9CInstanceS2_iPS_
 *   _Z14F_IniReadRealR6RValueP9CInstanceS2_iPS_    _Z15F_IniWriteRealR6RValueP9CInstanceS2_iPS_
 *   _Z12F_MouseClearR6RValueP9CInstanceS2_iPS_
 * 形参约定（9 个一致）: r0 = RValue& ret, r1 = self, r2 = other, r3 = int argc, 入口 [sp+0] = RValue* args
 *   —— 9 个函数**没有一个是读 argc 的**（r3 在首屏被覆盖或根本没用到）；缺参不由被调方兜底。
 *
 * ── 随机族：一套 16 字状态 + 一个下标（本卡新增，四条链全部落地）──────────────────
 *   YYRandom() 0x0c44ec（39 条，函数体在 cards/auto/bank_0004.c，本卡边界外）
 *     state: u32[16] 0x479a88（GOT 槽 0x3ed96c，R_ARM_RELATIVE 指向它）
 *     idx:   int      0x479a84（GOT 槽 0x3ed974）—— 与 state 相邻，正好在 state[0] 前一字
 *     poly:  u32      0x3f2004，镜像初值 0xda442d24（.data，不是 .bss：一开始就不是 0）
 *     每次调用（下标**减一**，mod 16；一次写两个字 state[i] 和 state[i-1]）:
 *       i = idx; j = (i+13)&15; k = (i+9)&15; n = (i+15)&15;     // 滞后 3 / 7 / 1
 *       a = (state[i] ^ (state[i]<<16) ^ state[j]) ^ (state[j]<<15);
 *       b = state[k] ^ (state[k]>>11);
 *       v = b ^ a;              state[i] = v;
 *       out = (state[n] ^ (state[n]<<2)) ^ a ^ v ^ (a<<18) ^ (b<<28) ^ (poly & (v<<5));
 *       state[n] = out;  idx = n;  return out;
 *     ⚠ 三个易错点：① (a<<18) 用的是 a 不是 v；② 掩码只作用在 (v<<5) 上，不是整个 out；
 *       ③ state[n] 在写入前是 i-1 的旧值（i 位置刚被 v 覆盖，n != i）。
 *   InitRandom(u32 seed) 0x0c4438（29 条）
 *     state[t] = ((s*214013 + 2531011) >> 16) & 0x7fffffff，s 递推（经典 MSVC rand 常数
 *     0x343fd / 0x269ec3）；开头 *idx = seed（0x0c4460），结尾 *idx = 0（0x0c4498）
 *     ⇒ 结束后下标恒为 0，开头那次 "= seed" 是死写（随后被清零）。
 *   fYYRandom(double d) 0x0c4598：d == 1.0 走同一个常数分支；返回 (double)(u32)YYRandom() * 2^-32 [* d]
 *     常数取池 0x0c45f8 = {0x00000000, 0x3df00000} = 0x3df0000000000000 = 2^-32（两个分支同一个池字）。
 *   YYRandom(int n) 0x0c4600：YYRandom() 与 |n| 做 __aeabi_uidivmod 取余 ⇒ [0,|n|-1]。
 *   iScript_Randomx(int64 n) 0x110d18（32 条）：**一次消耗两个** YYRandom()，
 *     x = (u64)(second & 0x7fffffff) << 32 | first（63 位非负），再 __aeabi_ldivmod(x,|n|)；
 *     n<0 时把余数取负 —— 本卡两个调用点都传正数，负分支只静态存在。
 *   版本开关: ChangeToOldPoly(bool) 0x0c44ac 改 0x3f2004 —— false→0xda442d24（默认），true→0xda442d20
 *     （两者只差 bit2）；唯一调用者 F_RandomUseOldVersion 0x10e24c（arg>0 → true）。
 *   旁证（不在本卡 9 个之内）: F_RandomSetSeed 0x10e220 → InitRandom(YYGetUint32(args,0))。
 *
 * ── 范围语义（本卡最要紧的三条；边界开闭是**实现**结论，不是文档）──────────────
 *   irandom_range(a,b) = min + (x % (|a-b|+1))，x 63 位非负 ⇒ **[min,max] 两端都闭**，a==b 恒为 a
 *     （0x110e20..0x110e3c 先做 64 位有符号比较再换位：a<b → base=a、n=b-a+1；a>=b → base=b、n=a-b+1）
 *   random_range(a,b)  = min + t*|a-b|，t = u32*2^-32 ∈ [0,1) ⇒ **[min,max) 上端开**（跨度>0 时取不到 max）
 *   random(n)          = t*n ⇒ [0,n)（n>0）；n<0 时 (n,0]
 *   三者都不做额外圆整：irandom_range 用 __floatdidf 把整数值搬成 double；random* 用 vmul/vmla 一步到位。
 *
 * ── 文件族：两条完全不同的后端（"统一走 JNI/AAsset"这个前提要修正）────────────
 *   file_exists = BundleFileExists(name) || SaveFileExists(name)（先 bundle 后 save，短路）
 *     BundleFileExists 0x18f8ac：_GetBundleFileName(buf,2048,name)（前缀 GetFilePrePend() = "assets/"，.rodata 0x352a80）
 *       → _FileExists 0x18f6c0 → zip_fopen(zip, path, 1) / zip_fclose（0x2a44b8 / 0x2a4388）
 *     SaveFileExists 0x18fb6c：_GetSaveFileName(buf,2048,name) → fopen(path,"rb") / fclose（模式串 0x337c00 = "rb"）
 *     _GetSaveFileName 0x18f964：GetSavePrePend() + name；name 以 '/' 或 '\' 开头则直接用；结果里 '\'→'/'。
 *       GetSavePrePend 0x28fd6c 用 "%s/%s/"（0x35816c）拼 base + 子目录并缓存 ⇒ save 侧是**普通文件路径**。
 *   file_delete(name)：**先 SaveFileExists 才动** ⇒ 只存在于 bundle（assets/）里的文件删不掉；
 *     存在 → _GetSaveFileName → RemoveSaveFile（0x18ffb0）= GetSaveFileName + remove()
 *     返回码映射：ret = 1 - remove()，若 >1 则 0 ⇒ remove 成功(0)→1、remove 返回 1→0、remove 失败(-1)→2
 *     （前两者常见；2 是从 0x18fff0 rsbs / 0x18fff4 movlo 直读出来的，不是推测）
 *
 * ── ini 族：值一律以字符串进表，写用 "%f" ─────────────────────────────────────
 *   g_ini: IniFile* 0x483cc4（.bss；GOT 槽 0x3ef298）—— 全族唯一的"当前打开的 ini"槽
 *   ini_read_real(section,key,def)：ini 未开 → Error_Show_Action 报串后返回 def（把 def 原样写回）；
 *     键不存在 → 静默返回 def；命中 → node = IniFile::GetKey(section,key)，值串在 node+8，strtod 转 double。
 *   ini_write_real(section,key,value)：ini 未开 → 同一条错误串（串文本是 "Trying to read ..."，写入路径也用它，
 *     0x340270，与 read 共用）+ 不写；否则 snprintf(buf,256,"%f",value) → IniFile::SetKey(section,key,buf)。
 *     "%f" = 0x3403bc ⇒ 固定 6 位小数：1/3 落盘成 0.333333，再读回来已经不是原值（精度损失在写侧）。
 *   落盘格式（IniFile::WriteIniFile 0x235d3c，逐字节可读）:
 *     "[<section>]\r\n" + 每条 "<key>=\"<value>\"\r\n"   —— **值带双引号**
 *     （'[' 0x5b / ']' 0x5d / '=' 0x3d / '"' 0x22 / CR 13 / LF 10 六个立即数在 0x235d90..0x235e58 内）
 *   ini_open 0x13baac：若已有 ini 先 WriteIniFile() + 析构 + 释放，再 new IniFile(name,false)（28 字节）。
 *
 * ── 三处「不写返回槽」（真正的不写，不是"写了 0"）──────────────────────────────
 *   ini_write_real、mouse_clear 全函数不碰 ret；file_delete 只在删除路径写 +0/+4，也不写 +0xc（tag）。
 *   ⇒ 这三处的返回值语义由调用方（DoCall）预置的 RValue 决定，本卡未取证（open 5）。
 *   反过来 file_exists（0x137ae4）与 ini_read_real（0x13bbe0）都**先置 tag=0 再写值**，说明 VM 并不保证
 *   tag 已被清 —— 同一张卡里的天然对照组。
 *
 * ── open ─────────────────────────────────────────────────────────────────
 *   1. YYGetInt64/YYGetReal/YYGetString/YYGetInt32/YYGetUint32 的转换细则（字符串/tag/越界）不在本卡。
 *   2. 0x3f2004 的 poly 掩码在数学上是什么多项式未命名；只证它是被 and 进 (v<<5) 的常量，
 *      ChangeToOldPoly(true)=0xda442d20 与默认值只差 bit2，两条序列的实测对照未做。
 *   3. 0x479a84 的镜像初值是 0x3181bd（不是 0）；谁在启动期调 InitRandom（是否自动 randomize）未证。
 *   4. zip_fopen 背后是 AAsset 还是自解 zip 索引未展开；IniFile::SetKey/GetKey 的链表结构未展开。
 *   5. file_delete 的 ret 只在删除路径写、且不写 tag —— 调用方预置规则未证（见上节）。
 *   6. mouse_clear 落到 IO_Button_Clear(0x18c1b0) 的三张 byte 表（0x18c1e8/0x18c1f0/0x18c1f4，
 *      按 [10][3] 排：off = index*3 + button-1）语义未命名；只证"三张表同一下标被清 0"。
 */

/* ══ 1/9  F_IRandomRange  0x110dec  size 148  37 条
 * @func 0x110dec 0x110e80  size 148  37 条
 * 符号 _Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_   GML: irandom_range(n1,n2) → real（值必为整数）
 * 参数: args = [sp+0x18]（push 6 字后）；argc(r3) 不读
 *
 *   a = YYGetInt64(args,0);                       // 0x110dfc..0x110e08
 *   b = YYGetInt64(args,1);                       // 0x110e0c..0x110e1c
 *   if (a < b) {                                  // 0x110e20 cmp r6,r4 / 0x110e24 sbcs r3,r7,r5 / 0x110e28 blt
 *     n = (b - a) + 1;  base = a;                 // 0x110e5c..0x110e78（r2:r3 = b-a；r4:r5 = a；n = b-a+1）
 *     goto tail;                                  // 0x110e7c b 0x110e3c
 *   }
 *   n = (a - b) + 1;  base = b;                   // 0x110e2c..0x110e38（r6:r7 = a-b；r4:r5 仍是 b；n = a-b+1）
 * tail:
 *   ret.tag = 0;                                  // 0x110e3c / 0x110e40
 *   ret.v = (double)(iScript_Randomx(n) + base);  // 0x110e44 bl / 0x110e48 adds / 0x110e4c adc
 *                                                 // 0x110e50 bl __floatdidf / 0x110e54 stm
 *
 * 三条实现事实：
 *   · 换位是"先比较再选 base/n"，不是先交换参数：两条路的 n 都是 |a-b|+1，base 都是 min。
 *   · n 含两端（+1）⇒ 返回区间 [min,max] 闭区间；a==b 时 n=1，rand%1=0，结果恒为 a。
 *   · 返回值是 double，但两个端点都是整数值（__floatdidf 之后没有任何缩放）。
 */

/* ---- 1/9 F_IRandomRange 代码 0x110dec..0x110e7c ---- */
/* @0x110dec push {r4, r5, r6, r7, r8, lr}  —— 6 寄存器 + 返回址；本函数不读 argc */
/* @0x110df0 mov r1, #0 */
/* @0x110df4 ldr r4, [sp, #0x18]  —— args = [sp+0x18]（push 6 字后） */
/* @0x110df8 mov r8, r0 */
/* @0x110dfc mov r0, r4 */
/* @0x110e00 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>  —— a = YYGetInt64(args,0) → r6:r7 */
/* @0x110e04 mov r6, r0 */
/* @0x110e08 mov r7, r1 */
/* @0x110e0c mov r0, r4 */
/* @0x110e10 mov r1, #1 */
/* @0x110e14 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>  —— b = YYGetInt64(args,1) → r4:r5 */
/* @0x110e18 mov r4, r0 */
/* @0x110e1c mov r5, r1 */
/* @0x110e20 cmp r6, r4  —— cmp+sbcs = 64 位有符号比较 a 与 b */
/* @0x110e24 sbcs r3, r7, r5 */
/* @0x110e28 blt 0x110e5c <_Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_+0x70>  —— a < b 才跳到 0x110e5c；落空 = a>=b 段 */
/* @0x110e2c subs r6, r6, r4  —— n = a-b（a>=b 段） */
/* @0x110e30 sbc r7, r7, r5 */
/* @0x110e34 adds r0, r6, #1  —— n = (a-b)+1 ⇒ 含两端 */
/* @0x110e38 adc r1, r7, #0 */
/* @0x110e3c mov r3, #0  —— ret.tag = 0（real） */
/* @0x110e40 str r3, [r8, #0xc] */
/* @0x110e44 bl 0x110d18 <_Z14iScript_Randomx>  —— iScript_Randomx(n)：x % n */
/* @0x110e48 adds r0, r0, r4  —— + base（此段 base = b，r4:r5 从未被覆盖） */
/* @0x110e4c adc r1, r1, r5 */
/* @0x110e50 bl 0x319164 <__floatdidf>  —— int64 → double（__floatdidf） */
/* @0x110e54 stm r8, {r0, r1}  —— 返回值 = 8 字节 double */
/* @0x110e58 pop {r4, r5, r6, r7, r8, pc} */
/* @0x110e5c mov r2, r0  —— a<b 段：r2:r3 = b（r0:r1 仍是第二次取值的结果） */
/* @0x110e60 mov r3, r1 */
/* @0x110e64 subs r2, r2, r6  —— n = b-a */
/* @0x110e68 sbc r3, r3, r7 */
/* @0x110e6c mov r4, r6  —— base = a（r4:r5 = r6:r7） */
/* @0x110e70 adds r0, r2, #1  —— n = (b-a)+1 ⇒ 含两端 */
/* @0x110e74 mov r5, r7 */
/* @0x110e78 adc r1, r3, #0 */
/* @0x110e7c b 0x110e3c <_Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_+0x50>  —— 换位段落地后跳回公共尾（0x110e3c） */

/* ══ 2/9  F_Random  0x10dddc  size 88  22 条
 * @func 0x10dddc 0x10de34  size 88  22 条
 * 符号 _Z8F_RandomR6RValueP9CInstanceS2_iPS_   GML: random(n) → real
 * 参数: args = [sp+0x18]（push 4 寄存器 + vpush {d8} = 24 字节）；argc 不读
 *
 *   ret.tag = 0;                      // 0x10ddf0 str r5,[r0,#0xc]（r5 在 0x10dde8 置 0）
 *   t = fYYRandom(1.0);               // 0x10ddf4/0x10ddf8 组 1.0（高 0x3ff00000 / 低 0）
 *                                     // 0x10de00 bl 0x0c4598；d==1.0 走"不乘 d"的快分支
 *   x = YYGetReal(args,0);            // 0x10de04..0x10de10
 *   ret.v = t * x;                    // 0x10de18 vmul.f64 d7,d8,d7
 *                                     // 0x10de1c..0x10de28（低字走 s14，高字走 r1 —— 同一个 d7 的两半）
 * ⇒ random(n) = t*n，t ∈ [0,1)；n>0 时结果 [0,n)，取不到 n；n<0 时 (n,0]。
 * ⚠ 0x10de20 的 vmov r2,s14 是**低半**（s14 = d7 低 32 位）；高字用 r1 —— 8 字节写回没有错位。
 */

/* ---- 2/9 F_Random 代码 0x10dddc..0x10de30 ---- */
/* @0x10dddc push {r4, r5, r6, lr}  —— 本函数不读 argc */
/* @0x10dde0 vpush {d8} */
/* @0x10dde4 mov r4, r0 */
/* @0x10dde8 mov r5, #0 */
/* @0x10ddec mov r1, #0 */
/* @0x10ddf0 str r5, [r0, #0xc]  —— ret.tag = 0（r5=0） */
/* @0x10ddf4 movt r1, #0x3ff0  —— 1.0 的高字 0x3ff00000 */
/* @0x10ddf8 mov r0, #0  —— 1.0 的低字 0 ⇒ d0 = 1.0 */
/* @0x10ddfc ldr r6, [sp, #0x18]  —— args = [sp+0x18] */
/* @0x10de00 bl 0xc4598 <_Z9fYYRandomd>  —— t = fYYRandom(1.0) */
/* @0x10de04 vmov d8, r0, r1 */
/* @0x10de08 mov r0, r6 */
/* @0x10de0c mov r1, r5 */
/* @0x10de10 bl 0xceb24 <_Z9YYGetRealPK6RValuei>  —— x = YYGetReal(args,0) */
/* @0x10de14 vmov d7, r0, r1 */
/* @0x10de18 vmul.f64 d7, d8, d7  —— t * x（d8 = t，d7 = x） */
/* @0x10de1c vmov r0, r1, d7  —— 低字：r0 已经是 d7 低字，r2 = s14（d7 低半） */
/* @0x10de20 vmov r2, s14 */
/* @0x10de24 mov r3, r1 */
/* @0x10de28 stm r4, {r2, r3}  —— 8 字节写回；tag 已在 0x10ddf0 置 0 */
/* @0x10de2c vpop {d8} */
/* @0x10de30 pop {r4, r5, r6, pc} */

/* ══ 3/9  F_Randomize  0x10e284  size 84  21 条  (池 0x10e2d4 一字)
 * @func 0x10e284 0x10e2d8  size 84  21 条（20 条指令 + 1 个池字）
 * 符号 _Z11F_RandomizeR6RValueP9CInstanceS2_iPS_   GML: randomize() → real（本次种子）
 * 参数: 不读 args、不读 argc —— 9 个里唯一真正无参的
 *
 *   ret.tag = 0;                            // 0x10e288/0x10e28c
 *   u64 t = Timing_Time();                  // 0x10e294 bl 0x215148
 *   u64 c = *(u64*)0x755280;                // 0x10e298/0x10e29c → GOT 0x3ee254（R_ARM_RELATIVE → 0x755280）
 *   c += t;                                 // 0x10e2a0 ldrd / 0x10e2a4 adds / 0x10e2a8 adc
 *   u32 s = (c_hi + c_lo) ^ ror(c_lo,16);   // 0x10e2ac add r0,r3,r2（32 位加，不带进位）
 *                                           // 0x10e2b0 eor r0,r0,r2,ror #16
 *   InitRandom(s);                          // 0x10e2b4 bl 0x0c4438（void；叶子实现未覆写 r0）
 *   ret.v = (double)(u32)s;                 // 0x10e2b8..0x10e2cc
 *
 * Timing_Time（0x215148，27 条，边界外）实测：clock_gettime(CLOCK_MONOTONIC=1) → (sec*1e9 + nsec)/1000
 *   → __fixdfdi 取整 → 减基准 ⇒ **微秒**整数；池字 0x2151a0 = 1e9、0x2151a8 = 1000。
 * 0x755280 是 .bss 里的 64 位全局（本卡只证"读-加-写回"的用法，名字与初值不可见）。
 * 返回槽最终写的是 vcvt.f64.u32(s)：种子当实数返回，不是 0（和 random_set_seed 形成对照）。
 */

/* ---- 3/9 F_Randomize 代码 0x10e284..0x10e2d4 ---- */
/* @0x10e284 push {r4, lr}  —— 本函数不读 argc、不读 args */
/* @0x10e288 mov r3, #0 */
/* @0x10e28c str r3, [r0, #0xc]  —— ret.tag = 0 */
/* @0x10e290 mov r4, r0 */
/* @0x10e294 bl 0x215148 <Timing_Time>  —— Timing_Time()：clock_gettime(1) → (s*1e9+ns)/1000，减基准 = 微秒 */
/* @0x10e298 ldr r3, [pc, #0x34]  —— 池字 0x10e2d4 = 0x002dffb0（PC 相对偏移，非指令） */
/* @0x10e29c ldr r3, [pc, r3]  —— GOT 0x3ee254（R_ARM_RELATIVE）→ 0x755280 的 64 位全局 */
/* @0x10e2a0 ldrd r2, r3, [r3]  —— c = *(u64*)0x755280（64 位全局，用途未证） */
/* @0x10e2a4 adds r2, r2, r0  —— c += Timing_Time()（64 位加） */
/* @0x10e2a8 adc r3, r3, r1 */
/* @0x10e2ac add r0, r3, r2  —— r0 = c_hi + c_lo（32 位加，不带进位） */
/* @0x10e2b0 eor r0, r0, r2, ror #16  —— s = r0 ^ (c_lo ror 16) */
/* @0x10e2b4 bl 0xc4438 <_Z10InitRandomj>  —— InitRandom(s)（void；r0 因叶子实现未覆写而仍是 s） */
/* @0x10e2b8 vmov s15, r0  —— 返回槽 = (double)(u32)s */
/* @0x10e2bc vcvt.f64.u32 d7, s15 */
/* @0x10e2c0 vmov r0, r1, d7 */
/* @0x10e2c4 vmov r2, s14 */
/* @0x10e2c8 mov r3, r1 */
/* @0x10e2cc stm r4, {r2, r3} */
/* @0x10e2d0 pop {r4, pc} */
/* @0x10e2d4 .word 0x002dffb0  —— 字面池 0x002dffb0，非指令（objdump 渲染成 .word） */

/* ══ 4/9  F_RandomRange  0x110efc  size 76  19 条
 * @func 0x110efc 0x110f48  size 76  19 条
 * 符号 _Z14F_RandomRangeR6RValueP9CInstanceS2_iPS_   GML: random_range(n1,n2) → real
 * 参数: args = [sp+0x18]；argc 不读
 *
 *   ret.tag = 0;                                 // 0x110f0c
 *   a = YYGetReal(args,0);                       // 0x110f10..0x110f18
 *   b = YYGetReal(args,1);                       // 0x110f20..0x110f2c
 *   ret.v = YYGML_random_range(a,b);             // 0x110f3c bl 0x110eb0 / 0x110f40 stm
 *
 * YYGML_random_range（0x110eb0，19 条，本卡边界外）逐条读法:
 *   d8=a, d7=b; vcmpe d8,d7; pl → d9=a-b、d8=b；mi → d9=b-a（d8 保持 a）
 *   ⇒ d8 = min(a,b)、d9 = |a-b|；t = fYYRandom(1.0)；result = d8 + t*d9（0x110ee4..0x110eec vmla）
 * ⇒ **半开 [min,max)**：t 最大是 (2^32-1)*2^-32 = 1-2^-32，跨度非 0 时永远取不到 max。
 *   跟 irandom_range 只差一个 "+1"，边界语义就不同 —— 这两条是本卡最容易被"想当然"写错的地方。
 */

/* ---- 4/9 F_RandomRange 代码 0x110efc..0x110f44 ---- */
/* @0x110efc push {r3, r4, r5, r6, r7, lr}  —— 本函数不读 argc */
/* @0x110f00 mov r1, #0 */
/* @0x110f04 ldr r7, [sp, #0x18] */
/* @0x110f08 mov r6, r0 */
/* @0x110f0c str r1, [r0, #0xc]  —— ret.tag = 0 */
/* @0x110f10 mov r0, r7 */
/* @0x110f14 bl 0xceb24 <_Z9YYGetRealPK6RValuei>  —— a = YYGetReal(args,0) */
/* @0x110f18 mov r4, r0 */
/* @0x110f1c mov r5, r1 */
/* @0x110f20 mov r0, r7 */
/* @0x110f24 mov r1, #1 */
/* @0x110f28 bl 0xceb24 <_Z9YYGetRealPK6RValuei>  —— b = YYGetReal(args,1) */
/* @0x110f2c mov r2, r0 */
/* @0x110f30 mov r3, r1 */
/* @0x110f34 mov r0, r4 */
/* @0x110f38 mov r1, r5 */
/* @0x110f3c bl 0x110eb0 <_Z18YYGML_random_rangedd>  —— YYGML_random_range(a,b)（0x110eb0，19 条，边界外） */
/* @0x110f40 stm r6, {r0, r1}  —— 8 字节写回 */
/* @0x110f44 pop {r3, r4, r5, r6, r7, pc} */

/* ══ 5/9  F_FileDelete  0x138474  size 148  37 条  (池 0x138504 一字)
 * @func 0x138474 0x138508  size 148  37 条（36 条指令 + 1 个池字；含 2048 字节栈缓冲）
 * 符号 _Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_   GML: file_delete(fname) → real
 * 参数: args = [sp,#0x818]（16 + 2048 + 8 帧）；argc 不读
 *
 *   name = YYGetString(args,0);              // 0x138490 ldr r0,[sp,#0x818] / 0x13849c bl
 *   if (SaveFileExists(name)) {              // 0x1384a4 bl 0x18fb6c / 0x1384a8 cmp / 0x1384ac beq done
 *     _GetSaveFileName(buf,2048,name);       // 0x1384b0..0x1384c0（buf = sp+4，canary = sp+0x804）
 *     rc = RemoveSaveFile(buf);              // 0x1384c8 bl 0x18ffb0
 *     ret.v = (double)(int)rc;               // 0x1384cc vcvt.f64.s32 … 0x1384e0 stm
 *   }                                        //   ← 只写 +0/+4，**不写 +0xc（tag）**
 * done:
 *   canary 校验                               // 0x1384e4..0x1384fc；不等 → 0x138500 __stack_chk_fail
 *
 * ⚠ 两个不对称：① 不存在的文件走 beq 直跳，返回槽一个字节都不写（连"失败=0"都不给）；
 *   ② 存在性只查 save 侧 ⇒ bundle（assets/）里的文件根本进不了删除路径。
 * RemoveSaveFile（0x18ffb0，25 条）：GetSaveFileName → remove() → rsbs r0,r0,#1 / movlo r0,#0
 *   ⇒ 返回 1-rc（rc>1 时 0）：remove 成功→1、rc==1→0、失败(-1)→2。
 */

/* ---- 5/9 F_FileDelete 代码 0x138474..0x138504 ---- */
/* @0x138474 push {r4, r5, r6, lr}  —— 4 寄存器；本函数不读 argc */
/* @0x138478 sub sp, sp, #2048  —— 2048 字节路径缓冲 */
/* @0x13847c ldr r4, [pc, #0x80] */
/* @0x138480 sub sp, sp, #8  —— +8 → canary 落在 [sp,#0x804] */
/* @0x138484 mov r1, #0 */
/* @0x138488 mov r5, r0 */
/* @0x13848c ldr r4, [pc, r4]  —— GOT 槽 0x3ed958 = __stack_chk_guard（R_ARM_GLOB_DAT） */
/* @0x138490 ldr r0, [sp, #0x818]  —— args = [sp,#0x818]（16+2048+8 帧） */
/* @0x138494 ldr r3, [r4] */
/* @0x138498 str r3, [sp, #0x804] */
/* @0x13849c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— name = YYGetString(args,0) */
/* @0x1384a0 mov r6, r0 */
/* @0x1384a4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>  —— SaveFileExists(name)（0x18fb6c） */
/* @0x1384a8 cmp r0, #0 */
/* @0x1384ac beq 0x1384e4 <_Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_+0x70>  —— 不存在 → 直跳 0x1384e4：ret 一个字节都不写 */
/* @0x1384b0 mov r2, r6 */
/* @0x1384b4 add r6, sp, #4 */
/* @0x1384b8 mov r1, #2048 */
/* @0x1384bc mov r0, r6 */
/* @0x1384c0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>  —— _GetSaveFileName(buf,2048,name)（0x18f964） */
/* @0x1384c4 mov r0, r6 */
/* @0x1384c8 bl 0x18ffb0 <_ZN8LoadSave14RemoveSaveFileEPKc>  —— RemoveSaveFile(path)（0x18ffb0）→ 0/1/2 */
/* @0x1384cc vmov s15, r0  —— int → double */
/* @0x1384d0 vcvt.f64.s32 d7, s15 */
/* @0x1384d4 vmov r0, r1, d7 */
/* @0x1384d8 vmov r2, s14 */
/* @0x1384dc mov r3, r1 */
/* @0x1384e0 stm r5, {r2, r3}  —— 只写 +0/+4；+0xc（tag）不写 */
/* @0x1384e4 ldr r2, [sp, #0x804] */
/* @0x1384e8 ldr r3, [r4] */
/* @0x1384ec cmp r2, r3 */
/* @0x1384f0 bne 0x138500 <_Z12F_FileDeleteR6RValueP9CInstanceS2_iPS_+0x8c>  —— canary 校验 */
/* @0x1384f4 add sp, sp, #2048 */
/* @0x1384f8 add sp, sp, #8 */
/* @0x1384fc pop {r4, r5, r6, pc} */
/* @0x138500 bl 0xb65d4 <__stack_chk_fail@plt>  —— canary 失败（__stack_chk_fail） */
/* @0x138504 eoreq r5, r11, r4, asr #9  —— 字面池 0x002b54c4，非指令（objdump 按指令渲染） */

/* ══ 6/9  F_FileExists  0x137acc  size 96  24 条
 * @func 0x137acc 0x137b2c  size 96  24 条
 * 符号 _Z12F_FileExistsR6RValueP9CInstanceS2_iPS_   GML: file_exists(fname) → real(0/1)
 * 参数: args = [sp,#0x18]（push 6 字）；argc 不读
 *
 *   name = YYGetString(args,0);            // 0x137ad8/0x137ae0
 *   ret.tag = 0;                            // 0x137ae4（r5 在 0x137ad4 置 0）
 *   if (BundleFileExists(name)) goto one;   // 0x137aec bl 0x18f8ac / 0x137af0 subs / 0x137afc bne
 *   if (SaveFileExists(name)) goto one;     // 0x137b00..0x137b0c bl 0x18fb6c / cmp
 *   ret.v = {low=0, high=0};                // 0x137b18 moveq r3,r5（r5=0）
 *   goto store;                             // 0x137b1c/0x137b20
 * one:
 *   ret.v = {low=0, high=0x3ff00000};       // 0x137af4/0x137af8 或 0x137b10/0x137b14 ⇒ 1.0
 * store:
 *   str low [r4]; str high [r4,#4];         // 0x137b20/0x137b24
 *
 * ⇒ 语义 = 先 assets（zip）后 save（文件），命中任一即 1.0；两条链都是"能打开就算存在"，
 *   不查零字节、不查是否目录。路径拼法见头部"文件族"节（bundle 加 "assets/"，save 走 GetSavePrePend）。
 */

/* ---- 6/9 F_FileExists 代码 0x137acc..0x137b28 ---- */
/* @0x137acc push {r3, r4, r5, r6, r7, lr}  —— 6 寄存器；不读 argc */
/* @0x137ad0 mov r1, #0 */
/* @0x137ad4 mov r4, r0 */
/* @0x137ad8 ldr r0, [sp, #0x18]  —— args = [sp,#0x18] */
/* @0x137adc mov r5, r1 */
/* @0x137ae0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— name = YYGetString(args,0) */
/* @0x137ae4 str r5, [r4, #0xc]  —— ret.tag = 0 */
/* @0x137ae8 mov r6, r0 */
/* @0x137aec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>  —— BundleFileExists(name)（0x18f8ac） */
/* @0x137af0 subs r7, r0, #0  —— 短路：bundle 命中直接 1.0 */
/* @0x137af4 movne r3, #0  —— 1.0 的高字 0x3ff00000 */
/* @0x137af8 movtne r3, #0x3ff0 */
/* @0x137afc bne 0x137b20 <_Z12F_FileExistsR6RValueP9CInstanceS2_iPS_+0x54>  —— 跳 0x137b20 写回 */
/* @0x137b00 mov r0, r6 */
/* @0x137b04 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>  —— SaveFileExists(name)（0x18fb6c） */
/* @0x137b08 cmp r0, #0  —— 直接比较 SaveFileExists 的返回值 */
/* @0x137b0c moveq r5, r0 */
/* @0x137b10 movne r3, #0  —— ne → 高字 0x3ff00000（1.0） */
/* @0x137b14 movtne r3, #0x3ff0 */
/* @0x137b18 moveq r3, r5  —— eq → 高字取 r5=0（0.0） */
/* @0x137b1c movne r5, r7 */
/* @0x137b20 str r5, [r4]  —— 写低字 */
/* @0x137b24 str r3, [r4, #0x4]  —— 写高字 */
/* @0x137b28 pop {r3, r4, r5, r6, r7, pc} */

/* ══ 7/9  F_IniReadReal  0x13bba4  size 92  23 条
 * @func 0x13bba4 0x13bc00  size 92  23 条
 * 符号 _Z14F_IniReadRealR6RValueP9CInstanceS2_iPS_   GML: ini_read_real(section,key,def) → real
 * 参数: args = [sp,#0x18]（push 6 字）；argc 不读
 *
 *   section = YYGetString(args,0);        // 0x13bbb8
 *   key     = YYGetString(args,1);        // 0x13bbc8
 *   def     = YYGetReal(args,2);          // 0x13bbd8
 *   ret.tag = 0;                          // 0x13bbe0（先置 tag 再调用：错误路径也不会漏写）
 *   ret.v   = YYGML_ini_read_real(section,key,def);   // 0x13bbf4 bl 0x13bb34 / 0x13bbf8 stm
 *
 * YYGML_ini_read_real（0x13bb34，28 条）三条分支:
 *   g = *(IniFile**)0x483cc4（GOT 0x3ef298）
 *   if (!g) { Error_Show_Action("Trying to read from undefined INI file", false); return def; }
 *   node = g->GetKey(section,key);         // 0x13bb64 bl 0x235ad0
 *   if (!node) return def;                 // 0x13bb6c beq 0x13bb90
 *   return strtod(*(char**)(node+8), 0);   // 0x13bb70 ldr r0,[r0,#8] / 0x13bb7c tail strtod
 * 错误串 0x340270（池 0x13bba0 + pc 0x13bb90）；第二实参 false = 非致命（0x13bb80 mov r1,r0，r0=0）。
 */

/* ---- 7/9 F_IniReadReal 代码 0x13bba4..0x13bbfc ---- */
/* @0x13bba4 push {r3, r4, r5, r6, r7, lr}  —— 6 寄存器；不读 argc */
/* @0x13bba8 mov r1, #0 */
/* @0x13bbac ldr r4, [sp, #0x18]  —— args = [sp,#0x18] */
/* @0x13bbb0 mov r5, r0 */
/* @0x13bbb4 mov r0, r4 */
/* @0x13bbb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— section = YYGetString(args,0) */
/* @0x13bbbc mov r1, #1 */
/* @0x13bbc0 mov r7, r0 */
/* @0x13bbc4 mov r0, r4 */
/* @0x13bbc8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— key = YYGetString(args,1) */
/* @0x13bbcc mov r1, #2 */
/* @0x13bbd0 mov r6, r0 */
/* @0x13bbd4 mov r0, r4 */
/* @0x13bbd8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>  —— def = YYGetReal(args,2) */
/* @0x13bbdc mov r12, #0 */
/* @0x13bbe0 str r12, [r5, #0xc]  —— ret.tag = 0（先置 tag 再调用） */
/* @0x13bbe4 mov r2, r0 */
/* @0x13bbe8 mov r3, r1 */
/* @0x13bbec mov r0, r7 */
/* @0x13bbf0 mov r1, r6 */
/* @0x13bbf4 bl 0x13bb34 <_Z19YYGML_ini_read_realPKcS0_d>  —— YYGML_ini_read_real(section,key,def)（0x13bb34，28 条） */
/* @0x13bbf8 stm r5, {r0, r1}  —— 8 字节写回 */
/* @0x13bbfc pop {r3, r4, r5, r6, r7, pc} */

/* ══ 8/9  F_IniWriteReal  0x13bca0  size 76  19 条
 * @func 0x13bca0 0x13bcec  size 76  19 条
 * 符号 _Z15F_IniWriteRealR6RValueP9CInstanceS2_iPS_   GML: ini_write_real(section,key,value)
 * 参数: args = [sp,#0x10]（push 4 字）；argc 不读
 *
 *   section = YYGetString(args,0);   // 0x13bcb0
 *   key     = YYGetString(args,1);   // 0x13bcc0
 *   value   = YYGetReal(args,2);     // 0x13bcd0
 *   return YYGML_ini_write_real(section,key,value);   // 0x13bce4 弹帧 / 0x13bce8 b 0x13bc00（尾跳）
 * ⇒ 本函数**不写 ret**（没有 tag、没有 stm）；返回值由调用方预置，见 open 5。
 *
 * YYGML_ini_write_real（0x13bc00，40 条）:
 *   char buf[256] @ sp+12；canary @ sp+0x10c；double value @ sp（0x13bc34 strd r2,r3,[sp]）
 *   if (!g_ini) { Error_Show_Action(同一条 "Trying to read from undefined INI file", false); goto done; }
 *   snprintf(buf,256,"%f",value);     // 0x13bc3c 池 0x13bc98 → 0x3403bc = "%f"；0x13bc4c bl snprintf
 *   g_ini->SetKey(section,key,buf);   // 0x13bc60 bl 0x235edc
 * done: canary 校验（0x13bc64..0x13bc70 / 0x13bc8c）
 * ⇒ 值先被 "%f" 成 6 位小数的字符串再进表：1/3 写进去就是 0.333333，读回来已不是原值。
 *   缓冲 256 ⇒ 极端大数（十进制展开 >255 字符）会被 snprintf 截断。
 */

/* ---- 8/9 F_IniWriteReal 代码 0x13bca0..0x13bce8 ---- */
/* @0x13bca0 push {r4, r5, r6, lr}  —— 4 寄存器；不读 argc */
/* @0x13bca4 mov r1, #0 */
/* @0x13bca8 ldr r4, [sp, #0x10]  —— args = [sp,#0x10] */
/* @0x13bcac mov r0, r4 */
/* @0x13bcb0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— section = YYGetString(args,0) */
/* @0x13bcb4 mov r1, #1 */
/* @0x13bcb8 mov r6, r0 */
/* @0x13bcbc mov r0, r4 */
/* @0x13bcc0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>  —— key = YYGetString(args,1) */
/* @0x13bcc4 mov r1, #2 */
/* @0x13bcc8 mov r5, r0 */
/* @0x13bccc mov r0, r4 */
/* @0x13bcd0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>  —— value = YYGetReal(args,2) */
/* @0x13bcd4 mov r2, r0 */
/* @0x13bcd8 mov r3, r1 */
/* @0x13bcdc mov r0, r6 */
/* @0x13bce0 mov r1, r5 */
/* @0x13bce4 pop {r4, r5, r6, lr}  —— 弹帧 */
/* @0x13bce8 b 0x13bc00 <_Z20YYGML_ini_write_realPKcS0_d>  —— 尾跳 YYGML_ini_write_real(section,key,value)：本函数不写 ret */

/* ══ 9/9  F_MouseClear  0x127618  size 84  21 条
 * @func 0x127618 0x12766c  size 84  21 条
 * 符号 _Z12F_MouseClearR6RValueP9CInstanceS2_iPS_   GML: mouse_clear(button)
 * 参数: args = [sp,#8]（push 2 字）；argc 不读
 *
 *   ProcessMessages();                    // 0x127620 bl 0x28fe64 —— 本体 4 字节 bx lr（本平台空实现）
 *   button = YYGetInt32(args,0);          // 0x127628/0x12762c
 *   if (button == -1) {                   // 0x127630 cmn r0,#1 / 0x127634 beq
 *     IO_Button_Clear(1,0);               // 0x127644..0x12764c bl
 *     IO_Button_Clear(2,0);               // 0x127650..0x127658 bl
 *     IO_Button_Clear(3,0);               // 0x12765c..0x127668 尾跳
 *     return;
 *   }
 *   IO_Button_Clear(button,0);            // 0x127638 mov r1,#0 / 0x12763c pop / 0x127640 b
 * ⇒ 本函数**不写 ret**；-1（mb_any）只展开成 1/2/3 三个键，index 恒 0。
 *
 * IO_Button_Clear（0x18c1b0，23 条，边界外）:
 *   if ((unsigned)(button-1) > 2) return;     // 0x18c1b0..0x18c1bc
 *   if ((unsigned)index > 9) return;          // 0x18c1c0..0x18c1c4
 *   off = index*3 + (button-1);               // 0x18c1cc add r1,r1,r1,lsl #1 / 0x18c1d4 add
 *   tbl0[off] = tbl1[off] = tbl2[off] = 0;    // 0x18c1ec/0x18c1f0/0x18c1f4 strb #0
 * ⇒ button 只认 1..3（0 和 -1 直接进这里都是 no-op，-1 由 F_MouseClear 自己展开成三次）；
 *   三张表按 [10][3] 排（各 30 字节），同一下标一起清。
 */

/* ---- 9/9 F_MouseClear 代码 0x127618..0x127668 ---- */
/* @0x127618 push {r4, lr}  —— 2 寄存器；不读 argc */
/* @0x12761c ldr r4, [sp, #0x8] */
/* @0x127620 bl 0x28fe64 <_Z15ProcessMessagesv>  —— ProcessMessages()（0x28fe64 本体 4 字节 bx lr ⇒ 本平台空实现） */
/* @0x127624 mov r1, #0 */
/* @0x127628 mov r0, r4  —— args = [sp,#8] */
/* @0x12762c bl 0xce870 <_Z10YYGetInt32PK6RValuei>  —— button = YYGetInt32(args,0) */
/* @0x127630 cmn r0, #1  —— cmn r0,#1 ⇒ button == -1（mb_any） */
/* @0x127634 beq 0x127644 <_Z12F_MouseClearR6RValueP9CInstanceS2_iPS_+0x2c>  —— 是 → 走 1/2/3 三连清 */
/* @0x127638 mov r1, #0  —— 否 → 单清：r1 = 0（index） */
/* @0x12763c pop {r4, lr}  —— 弹帧 */
/* @0x127640 b 0x18c1b0 <_Z15IO_Button_Clearii>  —— 尾跳 IO_Button_Clear(button,0) */
/* @0x127644 mov r0, #1  —— mb_any 路：button 1 */
/* @0x127648 mov r1, #0 */
/* @0x12764c bl 0x18c1b0 <_Z15IO_Button_Clearii> */
/* @0x127650 mov r0, #2  —— button 2 */
/* @0x127654 mov r1, #0 */
/* @0x127658 bl 0x18c1b0 <_Z15IO_Button_Clearii> */
/* @0x12765c mov r0, #3  —— button 3（尾跳） */
/* @0x127660 mov r1, #0 */
/* @0x127664 pop {r4, lr}  —— 弹帧后尾跳 */
/* @0x127668 b 0x18c1b0 <_Z15IO_Button_Clearii>  —— 尾跳 IO_Button_Clear(3,0) */
