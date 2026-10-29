/* cally 逆向卡：Builtins_DsString（原版 libyoyo.so，armv7）—— ds_map 5 个 + 字符串 3 个 + 数学 3 个
 * 节: 11 个 @func 小节，顺序 = ds_map_create / ds_map_destroy / ds_map_find_value / ds_map_replace /
 *     ds_map_secure_save / string / string_format / string_digits / max / min / choose
 *     （= 索引文件的段落顺序，不是 GML 字典序）
 * 索引: asm/index-builtins_ds_string_all.tsv —— 1230 条，11 段互不连续的区间，一段一个函数
 *   0x1000f4..0x1001a4   45 条  F_DsMapCreate      size 180   (池 0x1001a0..0x1001a4, 2 字)
 *   0x0fec90..0x0fed3c   44 条  F_DsMapDestroy     size 176   (池 0x0fed34..0x0fed3c, 3 字)
 *   0x106bcc..0x106ee0  198 条  F_DsMapFindValue   size 792   (池 0x106ed8..0x106ee0, 3 字)
 *   0x0ff49c..0x0ff560   50 条  F_DsMapReplace     size 200   (池 0x0ff558..0x0ff560, 3 字)
 *   0x0fb1c0..0x0fb348   99 条  F_DsMapSecureSave  size 396   (池 0x0fb344..0x0fb348, 2 字)
 *   0x10ec98..0x10ed3c   42 条  F_String           size 168   (池 0x10ed38..0x10ed3c, 2 字)
 *   0x10f7e4..0x10f8b4   53 条  F_StringFormat     size 212   (池 0x10f8b0..0x10f8b4, 2 字)
 *   0x10ff6c..0x110020   46 条  F_StringDigits     size 184   (池 0x110020, 1 字)
 *   0x1135a8..0x113970  243 条  F_Max              size 972   (无池)
 *   0x1131d8..0x1135a0  243 条  F_Min              size 972   (无池)
 *   0x113978..0x113c10  167 条  F_Choose           size 668   (池 0x113c10, 1 字 = 0.0f)
 * 级别: 正文（11 个函数的形参落位、注册表/表结构、错误路径、返回值写槽全部逐条落锚；
 *       被调 helper 的内部按节标注边界；tag 的「语言类型名」属推断，代码形态全部实测）
 * 符号（全部取到 .dynsym 完整签名）:
 *   _Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_      _Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_
 *   _Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_   _Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_
 *   _Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_  _Z8F_StringR6RValueP9CInstanceS2_iPS_
 *   _Z14F_StringFormatR6RValueP9CInstanceS2_iPS_     _Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_
 *   _Z5F_MinR6RValueP9CInstanceS2_iPS_               _Z5F_MaxR6RValueP9CInstanceS2_iPS_
 *   _Z8F_ChooseR6RValueP9CInstanceS2_iPS_
 * 形参约定（11 个一致）: r0 = RValue& ret, r1 = self, r2 = other, r3 = int argc, 入口 [sp+0] = RValue* args
 *
 * ── ds_map 的表结构（本卡新增；四条链全部落锚）────────────────────────────
 *   全局注册表（.bss 相邻两字，全部经 GOT 间接取）:
 *     0x4836ac  int                槽数（高水位，只增不减；destroy 不清零）   GOT 槽 0x3edc80
 *     0x4836b0  { +0 int capacity, +4 CDS_Map** items }                     GOT 槽 0x3ed944
 *   CDS_Map（operator new(4)，只装一个指针）→ 内层 12 字节表:
 *     +0  Node** buckets（8 字节/槽，桶首指针）   +4 int mask（槽数-1）   +8 int count
 *     默认 ctor 0x203624: Alloc(2048) = 256 槽、mask=255、count=0
 *     带参 ctor 0x203680: Alloc(size*8)、mask=size-1、count=0
 *   链节点: +0x04 next、+0x08 u32 crc32、+0x0c RValue* key；**值在 key+0x10**（key/value 连体 32 字节）
 *   桶下标 = crc & mask；链上先比 +0x08 == crc，再 YYCompareVal(节点 key, 参数 key, eps 全局) 复核
 *     （CDS_Map::Find 0x2034e4: 0x203554 取 impl、0x203558 取 mask、0x20355c 取 buckets、
 *      0x203564 ldr r4,[r3,r2,lsl #3]、0x203580 比 crc、0x2035a0 bl YYCompareVal）
 *   key 的哈希（0x2034e4 开头的 6 路 tag 分派）:
 *     tag 1（字符串）      → CalcCRC_string(_RefThing->text)           0x203520..0x20352c
 *     tag 0（实数）        → 8 字节 double 拷到栈上 CalcCRC(&d, 8)      0x2035d8..0x2035f4
 *     tag 2,3,4,6,8,9,11   → CalcCRC(RValue*, 8)（取前 8 字节）        0x20350c/0x2035c4/0x203600
 *     tag 5,7,10 及其它    → REAL_RValue_Ex 转 double 后同上            0x2035d0/0x203614
 *     tag 0x00FFFFFF（变量引用标记）→ hash = 0                         0x203544..0x203550
 *   ⚠ 这条纠正「ds_map = CHashMap<string,RValue>」的旧说法：**键是 RValue，不是字符串**；
 *     字符串只是其中一种可哈希形态。命中判定是 YYCompareVal（带 eps 的通用比较），不是 strcmp。
 *
 * ── ds_map 的三个共享件 ──────────────────────────────────────────────
 *   DS_AutoMutex：create / destroy / find_value / replace **四个**在函数体首尾成对调用；
 *     secure_save 全函数**没有**取这把锁（0x0fb1c0..0x0fb348 里没有 bl 0x0fec18/0x0fec6c，
 *     它的表访问发生在 DSMapToJSON 内部）—— 锁覆盖的是「注册表 + 表操作」，不是所有 ds_map API。
 *     ctor 0x0fec18（槽里没有 Mutex 就 malloc(8)+Mutex::Init，再 Mutex::Lock）
 *     dtor 0x0fec6c（Mutex::Unlock）—— 是**整族 ds_* 共用的全局锁**，不是 per-map。
 *   错误串：.rodata 0x337c04 "Data structure with index does not exist."
 *     （destroy / find_value / replace 三处各有一份 pc 相对池字，都指向同一条）
 *   返回值写槽三种范式：不写（destroy）、按 tag 分派带引用计数写（find_value）、
 *     预置 real 0.0 后按结果写 0.0/1.0（replace）或恒 0.0（secure_save）。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1. 链节点 +0x00 字段未被 Find/Replace 读（本卡只证 +4/+8/+0xc）。
 *   2. CalcCRC / CalcCRC_string（0x27dfa0/0x27dfa8）的多项式与表未展开；eps 全局的具体值未取。
 *   3. CDS_Map::Replace（0x20bc44）的扩容/再哈希策略未展开（本卡只证调用点与返回值用法）。
 *   4. ds_map_create 的 1 参形态（cmp r7,#1 → CDS_Map(int)）在 GML 侧对应什么，静态只能证分支存在。
 *   5. ds_map_secure_save 的前缀 helper（0x0fae18，落在 F_DsQueueCreate 之后）只证到
 *      「取 YYUDID、按字符奇偶异或 41/154、拼进模板」；完整前缀格式未解。
 *   6. YYRandom()（0x0c44ec）的 16 字状态种子/丢弃策略未展开。
 */

/* ══ 1/11  F_DsMapCreate  0x1000f4  size 180  45 条  (池 0x1001a0, 0x1001a4 两字)
 * @func 0x1000f4 0x1001a8  size 180  45 条（43 条指令 + 2 个池字 0x1001a0/0x1001a4）
 * 符号 _Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_    GML: ds_map_create() → real id
 * 参数: args = [sp+0x20]（0x10016c 只在 1 参路用）；argc 在 r3（0x100104 mov r7,r3）
 *       —— **本族唯一读 argc 的函数**
 *
 *   DS_AutoMutex __m(sp+4);                       // 0x10010c bl 0x0fec18
 *   idx = FindFreeDsMapIndex();                   // 0x100110 bl 0x100014
 *   if (argc == 1)                                // 0x100114 cmp r7,#1 / 0x100118 mov r6 / 0x10011c beq 0x100168
 *     map = new CDS_Map(YYGetInt32(args,0));      // 0x100168..0x100174 取值（r0=args、r1=0）
 *                                                 // 0x100178 new(4) / 0x100188 bl 0x203680（带参 ctor）
 *   else
 *     map = new CDS_Map();                        // 0x100120 new(4) / 0x10012c bl 0x203624（默认 ctor）
 *   items[idx] = map;                             // 0x100130..0x10013c；1 参路同段 0x10018c..0x100198
 *                                                 //   items = *(*(0x4836b0)+4)（GOT 槽 0x3ed944）
 *   ret = real(idx);                              // 0x100140 vmov s15,r6 / 0x100150 vcvt.f64.s32
 *                                                 // 0x100154 vmov r2,r3,d7 / 0x100158 stm r4,{r2,r3}
 *                                                 // 0x10014c str 0,[r4,#0xc]（tag 0 = real）
 *   ~DS_AutoMutex; return;                        // 0x10015c / 0x100160..0x100164
 *
 * 两条 ctor 路的差别（都逐指令读过）:
 *   CDS_Map()      0x203624: new(12) → {+0 buf=Alloc(2048), +4 mask=255, +8 count=0}（= 256 槽哈希表）
 *   CDS_Map(int n) 0x203680: new(12) → {+0 buf=Alloc(n*8), +4 mask=n-1, +8 count=0}
 *   两者最后都把内层表指针存进 4 字节的 CDS_Map 外壳（0x203670 / 0x2036d4 的 str r4,[r5]）。
 * FindFreeDsMapIndex（0x100014, 45 条，本卡边界外）实测：先线性扫 items[0..count-1] 找空槽
 *   （0x10004c..0x100078，命中即返回下标）；全满时 idx = count，capacity > count 则直接 count++
 *   （0x10007c..0x100094），否则 SetLength(&items,(count+16)*4) 后 capacity += 16、count++
 *   （0x1000ac..0x1000dc）⇒ **先复用空槽、满则 +16 扩容**。
 * 返回槽形态唯一：real(idx)（8 字节 double + tag 0），0x100154 的 vmov r2,r3,d7 是双精度互证。
 */

/* ---- 1/11 F_DsMapCreate 代码 0x1000f4..0x10019c ---- */
/* @0x1000f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1000f8 sub sp, sp, #8 */
/* @0x1000fc add r5, sp, #4 */
/* @0x100100 mov r4, r0 */
/* @0x100104 mov r7, r3 */
/* @0x100108 mov r0, r5 */
/* @0x10010c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x100110 bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x100114 cmp r7, #1 */
/* @0x100118 mov r6, r0 */
/* @0x10011c beq 0x100168 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x100120 mov r0, #4 */
/* @0x100124 bl 0x27c524 <_Znwj> */
/* @0x100128 mov r7, r0 */
/* @0x10012c bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x100130 ldr r3, [pc, #0x68] */
/* @0x100134 ldr r3, [pc, r3] */
/* @0x100138 ldr r3, [r3, #0x4] */
/* @0x10013c str r7, [r3, r6, lsl #2] */
/* @0x100140 vmov s15, r6 */
/* @0x100144 mov r1, #0 */
/* @0x100148 mov r0, r5 */
/* @0x10014c str r1, [r4, #0xc] */
/* @0x100150 vcvt.f64.s32 d7, s15 */
/* @0x100154 vmov r2, r3, d7 */
/* @0x100158 stm r4, {r2, r3} */
/* @0x10015c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x100160 add sp, sp, #8 */
/* @0x100164 pop {r4, r5, r6, r7, r8, pc} */
/* @0x100168 mov r1, #0 */
/* @0x10016c ldr r0, [sp, #0x20] */
/* @0x100170 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x100174 mov r8, r0 */
/* @0x100178 mov r0, #4 */
/* @0x10017c bl 0x27c524 <_Znwj> */
/* @0x100180 mov r1, r8 */
/* @0x100184 mov r7, r0 */
/* @0x100188 bl 0x203680 <_ZN7CDS_MapC2Ei> */
/* @0x10018c ldr r3, [pc, #0x10] */
/* @0x100190 ldr r3, [pc, r3] */
/* @0x100194 ldr r3, [r3, #0x4] */
/* @0x100198 str r7, [r3, r6, lsl #2] */
/* @0x10019c b 0x100140 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_+0x4c> */
/* ---- pool：2 字（两处 GOT 偏移，同指向 0x4836b0） ---- */
/* @0x1001a0 eoreq sp, lr, r8, lsl #16 */
/* @0x1001a4 eoreq sp, lr, r12, lsr #15 */
/* ══ 2/11  F_DsMapDestroy  0x0fec90  size 176  44 条  (池 0x0fed34..0x0fed3c 三字)
 * @func 0xfec90 0xfed40  size 176  44 条（41 条指令 + 3 个池字 0x0fed34..0x0fed3c）
 * 符号 _Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_    GML: ds_map_destroy(id)
 * 参数: args = [sp+0x20]（0xfec9c）
 *
 *   DS_AutoMutex __m(sp+4);                     // 0xfeca4 bl 0x0fec18
 *   id = YYGetInt32(args,0);                    // 0xfecac mov r0,r5 / 0xfecb0 bl
 *   if (id < 0) goto err;                       // 0xfecb4 subs / 0xfecb8 blt → 0xfed14
 *   if (id >= *(int*)0x4836ac) goto err;        // 0xfecbc..0xfeccc（GOT 0x3edc80 → 0x4836ac，取 *）
 *                                               //   界用的是**槽数**，不是 capacity、也不是 items[id]!=0
 *   map = items[id];                            // 0xfecd0..0xfecdc（GOT 0x3ed944 → 0x4836b0，取 +4）
 *   if (map != 0) {                             // 0xfece0 cmp / 0xfece4 beq → 0xfed04（界内空槽静默跳过）
 *     CDS_Map::~CDS_Map(map);                   // 0xfecec bl 0x20d9e8
 *     operator delete(map);                     // 0xfecf4 bl 0x27d1d0
 *     items[id] = 0;                            // 0xfecf8..0xfed00
 *   }
 *   ~DS_AutoMutex; return;                      // 0xfed04..0xfed10
 * err:
 *   Error_Show_Action("Data structure with index does not exist.", 0);   // 0xfed14..0xfed20（r1=0）
 *   ~DS_AutoMutex; return;                      // 0xfed24..0xfed30
 *
 * ret 从头到尾没被读、也没被写 —— ds_map_destroy 无返回值（与 replace 的「先预置 0.0」形成对照）。
 * 三个出口都先析构 __m 再走，锁不漏；错误出口不长期停留（Error_Show_Action 只是置标志，见 VMError 卡）。
 * 槽数不回收 ⇒ 销毁后再 destroy 同一个 id 不会报错（只要 id < 槽数），只是空转。
 */

/* ---- 2/11 F_DsMapDestroy 代码 0x0fec90..0x0fed30 ---- */
/* @0xfec90 push {r4, r5, r6, r7, lr} */
/* @0xfec94 sub sp, sp, #12 */
/* @0xfec98 add r4, sp, #4 */
/* @0xfec9c ldr r5, [sp, #0x20] */
/* @0xfeca0 mov r0, r4 */
/* @0xfeca4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfeca8 mov r1, #0 */
/* @0xfecac mov r0, r5 */
/* @0xfecb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfecb4 subs r5, r0, #0 */
/* @0xfecb8 blt 0xfed14 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfecbc ldr r3, [pc, #0x70] */
/* @0xfecc0 ldr r3, [pc, r3] */
/* @0xfecc4 ldr r3, [r3] */
/* @0xfecc8 cmp r5, r3 */
/* @0xfeccc bge 0xfed14 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfecd0 ldr r6, [pc, #0x60] */
/* @0xfecd4 ldr r6, [pc, r6] */
/* @0xfecd8 ldr r3, [r6, #0x4] */
/* @0xfecdc ldr r7, [r3, r5, lsl #2] */
/* @0xfece0 cmp r7, #0 */
/* @0xfece4 beq 0xfed04 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfece8 mov r0, r7 */
/* @0xfecec bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0xfecf0 mov r0, r7 */
/* @0xfecf4 bl 0x27d1d0 <_ZdlPv> */
/* @0xfecf8 ldr r3, [r6, #0x4] */
/* @0xfecfc mov r2, #0 */
/* @0xfed00 str r2, [r3, r5, lsl #2] */
/* @0xfed04 mov r0, r4 */
/* @0xfed08 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfed0c add sp, sp, #12 */
/* @0xfed10 pop {r4, r5, r6, r7, pc} */
/* @0xfed14 ldr r0, [pc, #0x20] */
/* @0xfed18 mov r1, #0 */
/* @0xfed1c add r0, pc, r0 */
/* @0xfed20 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfed24 mov r0, r4 */
/* @0xfed28 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfed2c add sp, sp, #12 */
/* @0xfed30 pop {r4, r5, r6, r7, pc} */
/* ---- pool：3 字（槽数 GOT 偏移 / 注册表 GOT 偏移 / 错误串偏移） ---- */
/* @0xfed34 .word 0x002eefb8 */
/* @0xfed38 eoreq lr, lr, r8, ror #24 */
/* @0xfed3c eoreq r8, r3, r0, ror #29 */
/* ══ 3/11  F_DsMapFindValue  0x106bcc  size 792  198 条  (池 0x106ed8..0x106ee0 三字)
 * @func 0x106bcc 0x106ee4  size 792  198 条（195 条指令 + 3 个池字 0x106ed8..0x106ee0）
 * 符号 _Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_   GML: ds_map_find_value(id, key)
 * 参数: args = [sp+0x30]（0x106bdc：push 20 + sub 28）
 *
 *   DS_AutoMutex __m(sp+4);                          // 0x106be4
 *   id = YYGetInt32(args,0);                         // 0x106bf0
 *   三闸（同一个错误出口 0x106cec）:
 *     id < 0                                          // 0x106bf4 cmp / 0x106bf8 blt
 *     id >= *(int*)0x4836ac                           // 0x106bfc..0x106c0c（GOT 0x3edc80）
 *     items[id] == 0                                  // 0x106c10..0x106c24（GOT 0x3ed944）
 *   node = CDS_Map::Find(items[id], &args[1]);        // 0x106c1c ldr r0,[r3,r0,lsl #2]（map）
 *                                                     // 0x106c28 add r1,r6,#16（= &args[1]）
 *                                                     // 0x106c2c bl 0x2034e4
 *   if (!node) {                                      // 0x106c30 cmp / 0x106c34 beq → 0x106d38
 *     ret = {0, 0, tag 5};                            // 0x106d38..0x106d44：str r0,[r4] / str r0,[r4,#4]
 *                                                     //   / str 5,[r4,#0xc]  ⇒ 键不存在 = undefined(tag 5)
 *   } else {
 *     v = *(RValue*)(node + 0x10);                    // 0x106c38 mov r3,r0 / 0x106c40 ldr r0,[r3,#0x10]!
 *                                                     // 0x106c50..0x106c5c 再把 +0x14/+0x18/+0x1c 三字读出
 *                                                     // stm r12!（r12 = sp+8）⇒ 16 字节落到本地槽
 *     v.tag &= 0x00FFFFFF;                            // 0x106c60 ldr r2,[sp,#0x14] / 0x106c64 bic #-16777216
 *                                                     // 0x106c68 str（清 tag 最高字节，同 DoConv 的 idiom）
 *     旧 ret 释放:                                    // 0x106c3c ldr r6,[r4,#0xc]（旧 tag）→ 0x106c48 bic
 *       tag==1 → _RefThing 归零链                    // 0x106c6c beq → 0x106d4c..0x106d80
 *         （LOCK → --refcnt → 0 则 YYFree(text)/清零/再 dec/delete，最后 [r4]=0）
 *       tag==2 → FREE_RValue__Pre(ret)                // 0x106c70..0x106c88 → 0x106e34
 *       （**只有 1 和 2 两档被清**；3/4 不清 —— 与 DoConv 的 tag1..4 通用模板不同）
 *     ret 头部三字先写: tag / 0 / v[8]                // 0x106c8c..0x106ca0
 *     15 路 tag 分派写 ret                           // 0x106ca4 cmp #14 / 0x106ca8 addls（表体 0x106cb0..0x106ce8）
 *   }
 *   ~DS_AutoMutex; return;
 *
 * 分派表（k = tag & 0x00FFFFFF）—— 表项地址 → 落点 → 实际动作：
 *   k=0  → 0x106d28  两个数据字整拷（8 字节）             k=1  → 0x106dac  _RefThing refcnt++ 后只存指针
 *   k=2  → 0x106dd0  数组引用计数（[v+0]==count++；[v+8]==0 时回填 &ret）  k=3 → 0x106d0c 只存指针
 *   k=4  → 0x106d14  只写 tag                            k=5  → 0x106d14  只写 tag
 *   k=6  → 0x106d84  存指针 + GetContextStackTop + DeterminePotentialRoot（GC 根登记）
 *   k=7  → 0x106d0c  只存指针                            k=8,9→ 0x106d14  只写 tag
 *   k=10 → 0x106d28  8 字节整拷                          k=11,12 → 0x106d14  只写 tag
 *   k=13 → 0x106d28  8 字节整拷                          k=14 → 0x106d0c  只存指针
 *   与 DoConv 卡钉死的常量对齐：0=real、1=string、10=int64、13=bool 都落在「8 字节整拷/加引用」档，
 *   4/5/8/9/11/12 的「只写 tag」说明它们的数据字没有别名语义（bool 走 13 而不是 4 是同一个证据）。
 * 结论: ds_map_find_value = 「键缺失 → undefined(tag 5)；命中 → 把表里的 RValue 按引用语义搬出来」。
 *   搬出动作是**逐 tag 手工做的**（不是 memcpy）：字符串加引用、数组登记、6 号 tag 登记 GC 根。
 */

/* ---- 3/11 F_DsMapFindValue 代码 0x106bcc..0x106ed4 ---- */
/* @0x106bcc push {r4, r5, r6, r7, lr} */
/* @0x106bd0 sub sp, sp, #28 */
/* @0x106bd4 add r5, sp, #4 */
/* @0x106bd8 mov r4, r0 */
/* @0x106bdc ldr r6, [sp, #0x30] */
/* @0x106be0 mov r0, r5 */
/* @0x106be4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x106be8 mov r1, #0 */
/* @0x106bec mov r0, r6 */
/* @0x106bf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x106bf4 cmp r0, #0 */
/* @0x106bf8 blt 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106bfc ldr r3, [pc, #0x2d4] */
/* @0x106c00 ldr r3, [pc, r3] */
/* @0x106c04 ldr r3, [r3] */
/* @0x106c08 cmp r0, r3 */
/* @0x106c0c bge 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106c10 ldr r3, [pc, #0x2c4] */
/* @0x106c14 ldr r3, [pc, r3] */
/* @0x106c18 ldr r3, [r3, #0x4] */
/* @0x106c1c ldr r0, [r3, r0, lsl #2] */
/* @0x106c20 cmp r0, #0 */
/* @0x106c24 beq 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106c28 add r1, r6, #16 */
/* @0x106c2c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x106c30 cmp r0, #0 */
/* @0x106c34 beq 0x106d38 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x106c38 mov r3, r0 */
/* @0x106c3c ldr r6, [r4, #0xc] */
/* @0x106c40 ldr r0, [r3, #0x10]! */
/* @0x106c44 add r12, sp, #8 */
/* @0x106c48 bic lr, r6, #-16777216 */
/* @0x106c4c cmp lr, #1 */
/* @0x106c50 ldr r2, [r3, #0x8] */
/* @0x106c54 ldr r1, [r3, #0x4] */
/* @0x106c58 ldr r3, [r3, #0xc] */
/* @0x106c5c stm r12!, {r0, r1, r2, r3} */
/* @0x106c60 ldr r2, [sp, #0x14] */
/* @0x106c64 bic r2, r2, #-16777216 */
/* @0x106c68 str r2, [sp, #0x14] */
/* @0x106c6c beq 0x106d4c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x106c70 cmp lr, #2 */
/* @0x106c74 bne 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106c78 sub r6, r6, #1 */
/* @0x106c7c bic r6, r6, #-16777216 */
/* @0x106c80 bic r6, r6, #3 */
/* @0x106c84 cmp r6, #0 */
/* @0x106c88 beq 0x106e34 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x106c8c ldr r1, [sp, #0x10] */
/* @0x106c90 bic r3, r2, #-16777216 */
/* @0x106c94 str r2, [r4, #0xc] */
/* @0x106c98 mov r2, #0 */
/* @0x106c9c str r2, [r4] */
/* @0x106ca0 str r1, [r4, #0x8] */
/* @0x106ca4 cmp r3, #14 */
/* @0x106ca8 addls pc, pc, r3, lsl #2 */
/* @0x106cac b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cb0 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106cb4 b 0x106dac <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x106cb8 b 0x106dd0 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x106cbc b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cc0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cc4 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cc8 b 0x106d84 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x106ccc b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cd0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cd4 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cd8 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106cdc b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106ce0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106ce4 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106ce8 b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cec ldr r0, [pc, #0x1ec] */
/* @0x106cf0 mov r1, #0 */
/* @0x106cf4 add r0, pc, r0 */
/* @0x106cf8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x106cfc mov r0, r5 */
/* @0x106d00 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x106d04 add sp, sp, #28 */
/* @0x106d08 pop {r4, r5, r6, r7, pc} */
/* @0x106d0c ldr r2, [sp, #0x8] */
/* @0x106d10 str r2, [r4] */
/* @0x106d14 str r3, [r4, #0xc] */
/* @0x106d18 mov r0, r5 */
/* @0x106d1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x106d20 add sp, sp, #28 */
/* @0x106d24 pop {r4, r5, r6, r7, pc} */
/* @0x106d28 ldr r1, [sp, #0x8] */
/* @0x106d2c ldr r2, [sp, #0xc] */
/* @0x106d30 stm r4, {r1, r2} */
/* @0x106d34 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106d38 mov r2, #5 */
/* @0x106d3c str r0, [r4] */
/* @0x106d40 str r0, [r4, #0x4] */
/* @0x106d44 str r2, [r4, #0xc] */
/* @0x106d48 b 0x106d18 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x106d4c ldr r6, [r4] */
/* @0x106d50 cmp r6, #0 */
/* @0x106d54 beq 0x106d78 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x106d58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106d5c ldr r7, [r6, #0x4] */
/* @0x106d60 sub r7, r7, #1 */
/* @0x106d64 str r7, [r6, #0x4] */
/* @0x106d68 cmp r7, #0 */
/* @0x106d6c beq 0x106dfc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x106d70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106d74 ldr r2, [sp, #0x14] */
/* @0x106d78 mov r3, #0 */
/* @0x106d7c str r3, [r4] */
/* @0x106d80 b 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106d84 ldr r2, [sp, #0x8] */
/* @0x106d88 cmp r2, #0 */
/* @0x106d8c str r2, [r4] */
/* @0x106d90 beq 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106d94 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x106d98 ldr r1, [sp, #0x8] */
/* @0x106d9c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x106da0 ldr r3, [r4, #0xc] */
/* @0x106da4 bic r3, r3, #-16777216 */
/* @0x106da8 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106dac ldr r2, [sp, #0x8] */
/* @0x106db0 cmp r2, #0 */
/* @0x106db4 beq 0x106d10 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x106db8 ldr r3, [r2, #0x4] */
/* @0x106dbc add r3, r3, #1 */
/* @0x106dc0 str r3, [r2, #0x4] */
/* @0x106dc4 ldr r3, [r4, #0xc] */
/* @0x106dc8 bic r3, r3, #-16777216 */
/* @0x106dcc b 0x106d10 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x106dd0 ldr r2, [sp, #0x8] */
/* @0x106dd4 cmp r2, #0 */
/* @0x106dd8 str r2, [r4] */
/* @0x106ddc beq 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106de0 ldr r0, [r2, #0x8] */
/* @0x106de4 ldr r1, [r2] */
/* @0x106de8 cmp r0, #0 */
/* @0x106dec streq r4, [r2, #0x8] */
/* @0x106df0 add r1, r1, #1 */
/* @0x106df4 str r1, [r2] */
/* @0x106df8 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106dfc ldr r0, [r6] */
/* @0x106e00 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e04 str r7, [r6] */
/* @0x106e08 str r7, [r6, #0x8] */
/* @0x106e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e10 ldr r7, [r6, #0x4] */
/* @0x106e14 sub r7, r7, #1 */
/* @0x106e18 str r7, [r6, #0x4] */
/* @0x106e1c cmp r7, #0 */
/* @0x106e20 beq 0x106e44 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x106e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106e28 mov r0, r6 */
/* @0x106e2c bl 0x27d1d0 <_ZdlPv> */
/* @0x106e30 b 0x106d70 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x106e34 mov r0, r4 */
/* @0x106e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x106e3c ldr r2, [sp, #0x14] */
/* @0x106e40 b 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106e44 ldr r0, [r6] */
/* @0x106e48 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e4c str r7, [r6] */
/* @0x106e50 str r7, [r6, #0x8] */
/* @0x106e54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e58 ldr r7, [r6, #0x4] */
/* @0x106e5c sub r7, r7, #1 */
/* @0x106e60 str r7, [r6, #0x4] */
/* @0x106e64 cmp r7, #0 */
/* @0x106e68 beq 0x106e7c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x106e6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106e70 mov r0, r6 */
/* @0x106e74 bl 0x27d1d0 <_ZdlPv> */
/* @0x106e78 b 0x106e24 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x106e7c ldr r0, [r6] */
/* @0x106e80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e84 str r7, [r6] */
/* @0x106e88 str r7, [r6, #0x8] */
/* @0x106e8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e90 ldr r3, [r6, #0x4] */
/* @0x106e94 sub r3, r3, #1 */
/* @0x106e98 str r3, [r6, #0x4] */
/* @0x106e9c cmp r3, #0 */
/* @0x106ea0 bne 0x106ec8 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x106ea4 ldr r0, [r6] */
/* @0x106ea8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106eac mov r3, #0 */
/* @0x106eb0 mov r0, r6 */
/* @0x106eb4 str r3, [r6] */
/* @0x106eb8 str r3, [r6, #0x8] */
/* @0x106ebc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x106ec0 mov r0, r6 */
/* @0x106ec4 bl 0x27d1d0 <_ZdlPv> */
/* @0x106ec8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106ecc mov r0, r6 */
/* @0x106ed0 bl 0x27d1d0 <_ZdlPv> */
/* @0x106ed4 b 0x106e6c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* ---- pool：3 字（同上三项） ---- */
/* @0x106ed8 eoreq r7, lr, r8, ror r0 */
/* @0x106edc eoreq r6, lr, r8, lsr #26 */
/* @0x106ee0 eoreq r0, r3, r8, lsl #30 */
/* ══ 4/11  F_DsMapReplace  0x0ff49c  size 200  50 条  (池 0x0ff558..0x0ff560 三字)
 * @func 0xff49c 0xff564  size 200  50 条（47 条指令 + 3 个池字 0x0ff558..0x0ff560）
 * 符号 _Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_    GML: ds_map_replace(id, key, value) → 0/1
 * 参数: args = [sp+0x20]（0xff4ac）
 *
 *   ret = {0, 0, tag 0};                        // 0xff4bc str 0,[r5,#0xc] / 0xff4c0 str 0,[r5]
 *                                               // 0xff4c8 str 0,[r5,#4]  ⇒ **先预置 real 0.0，再取参**
 *   DS_AutoMutex __m(sp+4);                     // 0xff4b8
 *   id = YYGetInt32(args,0);                    // 0xff4cc
 *   三闸同 destroy（id<0 0xff4d4/0xff4d8；id>=槽数 0xff4dc..0xff4ec；items[id]==0 0xff4f0..0xff504）
 *     → 错误出口 0xff538
 *   ok = CDS_Map::Replace(items[id], &args[1], &args[2]);   // 0xff508 add r1,r7,#16；0xff50c add r2,r7,#32
 *                                                          // 0xff510 bl 0x20bc44
 *   if (ok) { ret[0]=0; ret[4]=0x3ff00000; }               // 0xff514 cmp / 0xff51c strne 0,[r5]
 *                                                          // 0xff520..0xff528 movtne #0x3ff0 ⇒ real 1.0
 *   ~DS_AutoMutex; return;                                 // 0xff52c..0xff534
 * err:
 *   Error_Show_Action("Data structure with index does not exist.", 0);   // 0xff538..0xff544
 *   ~DS_AutoMutex; return;                                 // 0xff548..0xff554
 *
 * 语义（由 0xff514 的 strne 组证明）：返回值 = 「有没有替换掉一个已存在的键」。
 *   键不存在不是错误 —— CDS_Map::Replace 返回 0、ret 保持 0.0；只有 id 非法才报错。
 *   tag 在 0xff4bc 就写成 0（real），两条出口都不再改 tag ⇒ 调用方永远拿到 real。
 * 对照 find_value：这里只写 1.0/0.0，不做任何引用计数搬运（值由 CDS_Map::Replace 自己拷）。
 */

/* ---- 4/11 F_DsMapReplace 代码 0x0ff49c..0x0ff554 ---- */
/* @0xff49c push {r4, r5, r6, r7, lr} */
/* @0xff4a0 sub sp, sp, #12 */
/* @0xff4a4 add r6, sp, #4 */
/* @0xff4a8 mov r5, r0 */
/* @0xff4ac ldr r7, [sp, #0x20] */
/* @0xff4b0 mov r4, #0 */
/* @0xff4b4 mov r0, r6 */
/* @0xff4b8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff4bc str r4, [r5, #0xc] */
/* @0xff4c0 str r4, [r5] */
/* @0xff4c4 mov r0, r7 */
/* @0xff4c8 str r4, [r5, #0x4] */
/* @0xff4cc mov r1, r4 */
/* @0xff4d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff4d4 cmp r0, #0 */
/* @0xff4d8 blt 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff4dc ldr r3, [pc, #0x74] */
/* @0xff4e0 ldr r3, [pc, r3] */
/* @0xff4e4 ldr r3, [r3] */
/* @0xff4e8 cmp r0, r3 */
/* @0xff4ec bge 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff4f0 ldr r3, [pc, #0x64] */
/* @0xff4f4 ldr r3, [pc, r3] */
/* @0xff4f8 ldr r3, [r3, #0x4] */
/* @0xff4fc ldr r0, [r3, r0, lsl #2] */
/* @0xff500 cmp r0, r4 */
/* @0xff504 beq 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff508 add r1, r7, #16 */
/* @0xff50c add r2, r7, #32 */
/* @0xff510 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_> */
/* @0xff514 cmp r0, #0 */
/* @0xff518 mov r0, r6 */
/* @0xff51c strne r4, [r5] */
/* @0xff520 movne r3, #0 */
/* @0xff524 movtne r3, #0x3ff0 */
/* @0xff528 strne r3, [r5, #0x4] */
/* @0xff52c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff530 add sp, sp, #12 */
/* @0xff534 pop {r4, r5, r6, r7, pc} */
/* @0xff538 ldr r0, [pc, #0x20] */
/* @0xff53c mov r1, #0 */
/* @0xff540 add r0, pc, r0 */
/* @0xff544 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff548 mov r0, r6 */
/* @0xff54c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff550 add sp, sp, #12 */
/* @0xff554 pop {r4, r5, r6, r7, pc} */
/* ---- pool：3 字（同上三项） ---- */
/* @0xff558 mlaeq lr, r8, r7, lr */
/* @0xff55c eoreq lr, lr, r8, asr #8 */
/* @0xff560 .word 0x002386bc */
/* ══ 5/11  F_DsMapSecureSave  0x0fb1c0  size 396  99 条  (池 0x0fb344, 0x0fb348 两字)
 * @func 0xfb1c0 0xfb34c  size 396  99 条（97 条指令 + 2 个池字 0x0fb344/0x0fb348）
 * 符号 _Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_  GML: ds_map_secure_save(id, filename)
 * 参数: args = [sp+0x28]（0xfb1d0：push 32 + sub 8）
 *
 *   ⚠ 本函数**不取 DS_AutoMutex**（对照同族四个函数），锁的缺失是实测：全函数无 0x0fec18/0x0fec6c 调用。
 *   ret = {0, 0, tag 0};                        // 0xfb1cc str 0,[r0,#0xc] / 0xfb1d8 / 0xfb1dc ⇒ real 0.0
 *   id       = YYGetInt32(args,0)  → r6;        // 0xfb1e4
 *   filename = YYGetString(args,1) → r9;        // 0xfb1f4（返回 char*，非 RValue）
 *   prefix   = helper_0xfae18();   → r5;        // 0xfb1fc（设备派生前缀，见下）
 *   buf = 0;                                    // 0xfb200 add r1,sp,#8 / 0xfb204 str r4,[r1,#-4]! ⇒ [sp+4]=0
 *   DSMapToJSON(id, &buf);                      // 0xfb20c mov r0,r6 / 0xfb210 bl 0x13c1d8
 *   fail = (buf == 0);                          // 0xfb214 ldr r0,[sp,#4] / 0xfb218 subs / 0xfb21c rsbs
 *                                               // 0xfb220 adcs ⇒ r7 = C of (0 - buf) = (buf == 0)
 *   if (fail) { buf = "{ }"; size = 9; }        // 0xfb224 cmp / 0xfb228 bne → 0xfb330..0xfb340
 *                                               //   池字 0x0fb348 → .rodata 0x337bfc 实为 "{ }"（3 字节）
 *   else size = ((strlen(buf)+1)*4)/3 + 4;      // 0xfb22c..0xfb248（umull 魔数 0xAAAAAAAB = 除以 3）
 *   b64 = Alloc(size);                          // 0xfb24c..0xfb260
 *   base64_encode(buf, strlen(buf)+1, b64);     // 0xfb268..0xfb280（**含结尾 NUL 一起编码**）
 *   n = strlen(prefix) + strlen(b64);           // 0xfb284..0xfb2a4
 *   blob = Alloc(n);                            // 0xfb2ac
 *   memcpy(blob, prefix, strlen(prefix));       // 0xfb2b4..0xfb2c8
 *   memcpy(blob+strlen(prefix), b64, strlen(b64));   // 0xfb2cc..0xfb2ec
 *   LoadSave::WriteFile(filename, blob, n);     // 0xfb2fc bl 0x18fa3c
 *   Free(prefix); Free(buf if !fail); Free(b64); Free(blob);   // 0xfb300 / 0xfb308..0xfb314 / 0xfb318 / 0xfb320
 *   return;                                     // 0xfb328..0xfb32c（ret 始终 real 0.0，**不反映写盘成败**）
 *
 * 载荷形态（实测三段拼接）：prefix ++ base64(JSON 文本 ++ '\0')。
 *   ⚠ base64 的长度参数是 strlen+1 ⇒ 尾零也进了密文，解码方按 NUL 截断即可还原 JSON。
 *   ⚠ JSON 失败（DSMapToJSON 回 0）时不是报错，而是把 "{ }" 当 JSON 存 —— 静默降级。
 * helper_0xfae18（0x0fae18，落在 F_DsQueueCreate 之后，本卡边界外）实测：取 YYUDID（0x15f574），
 *   strlen 后按 i%2 选异或键（偶 41 / 奇 154），sprintf 进模板，再 memcpy UDID 原文 → 返回堆串。
 *   完整前缀格式未解（open 5）；但「与设备 ID 绑定」这一点由 YYUDID 调用点直接证明。
 * 释放顺序与 r7 的关系：只有 fail==0（buf 是堆块）才 Free(buf)，fallback 的 "{ }" 是 .rodata 常量不释放。
 */

/* ---- 5/11 F_DsMapSecureSave 代码 0x0fb1c0..0x0fb340 ---- */
/* @0xfb1c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb1c4 sub sp, sp, #8 */
/* @0xfb1c8 mov r4, #0 */
/* @0xfb1cc str r4, [r0, #0xc] */
/* @0xfb1d0 ldr r5, [sp, #0x28] */
/* @0xfb1d4 mov r1, r4 */
/* @0xfb1d8 str r4, [r0] */
/* @0xfb1dc str r4, [r0, #0x4] */
/* @0xfb1e0 mov r0, r5 */
/* @0xfb1e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb1e8 mov r1, #1 */
/* @0xfb1ec mov r6, r0 */
/* @0xfb1f0 mov r0, r5 */
/* @0xfb1f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfb1f8 mov r9, r0 */
/* @0xfb1fc bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0xfb200 add r1, sp, #8 */
/* @0xfb204 str r4, [r1, #-0x4]! */
/* @0xfb208 mov r5, r0 */
/* @0xfb20c mov r0, r6 */
/* @0xfb210 bl 0x13c1d8 <_Z11DSMapToJSONiPPc> */
/* @0xfb214 ldr r0, [sp, #0x4] */
/* @0xfb218 subs r3, r0, r4 */
/* @0xfb21c rsbs r7, r3, #0 */
/* @0xfb220 adcs r7, r7, r3 */
/* @0xfb224 cmp r7, r4 */
/* @0xfb228 bne 0xfb330 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0xfb22c bl 0xb6538 <strlen@plt> */
/* @0xfb230 movw r3, #0xaaab */
/* @0xfb234 movt r3, #0xaaaa */
/* @0xfb238 add r0, r0, #1 */
/* @0xfb23c lsl r0, r0, #2 */
/* @0xfb240 umull r2, r0, r3, r0 */
/* @0xfb244 lsr r0, r0, #1 */
/* @0xfb248 add r0, r0, #4 */
/* @0xfb24c ldr r6, [pc, #0xf0] */
/* @0xfb250 mov r3, #1 */
/* @0xfb254 movw r2, #0x71b */
/* @0xfb258 add r6, pc, r6 */
/* @0xfb25c mov r1, r6 */
/* @0xfb260 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb264 ldr r8, [sp, #0x4] */
/* @0xfb268 mov r4, r0 */
/* @0xfb26c mov r0, r8 */
/* @0xfb270 bl 0xb6538 <strlen@plt> */
/* @0xfb274 mov r2, r4 */
/* @0xfb278 add r1, r0, #1 */
/* @0xfb27c mov r0, r8 */
/* @0xfb280 bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0xfb284 mov r0, r5 */
/* @0xfb288 bl 0xb6538 <strlen@plt> */
/* @0xfb28c mov r8, r0 */
/* @0xfb290 mov r0, r4 */
/* @0xfb294 bl 0xb6538 <strlen@plt> */
/* @0xfb298 mov r3, #1 */
/* @0xfb29c mov r1, r6 */
/* @0xfb2a0 mov r2, #1824 */
/* @0xfb2a4 add r8, r0, r8 */
/* @0xfb2a8 mov r0, r8 */
/* @0xfb2ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb2b0 mov r6, r0 */
/* @0xfb2b4 mov r0, r5 */
/* @0xfb2b8 bl 0xb6538 <strlen@plt> */
/* @0xfb2bc mov r1, r5 */
/* @0xfb2c0 mov r2, r0 */
/* @0xfb2c4 mov r0, r6 */
/* @0xfb2c8 bl 0xb65bc <memcpy@plt> */
/* @0xfb2cc mov r0, r5 */
/* @0xfb2d0 bl 0xb6538 <strlen@plt> */
/* @0xfb2d4 mov r10, r0 */
/* @0xfb2d8 mov r0, r4 */
/* @0xfb2dc bl 0xb6538 <strlen@plt> */
/* @0xfb2e0 mov r1, r4 */
/* @0xfb2e4 mov r2, r0 */
/* @0xfb2e8 add r0, r6, r10 */
/* @0xfb2ec bl 0xb65bc <memcpy@plt> */
/* @0xfb2f0 mov r1, r6 */
/* @0xfb2f4 mov r2, r8 */
/* @0xfb2f8 mov r0, r9 */
/* @0xfb2fc bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0xfb300 mov r0, r5 */
/* @0xfb304 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb308 cmp r7, #0 */
/* @0xfb30c bne 0xfb318 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0xfb310 ldr r0, [sp, #0x4] */
/* @0xfb314 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb318 mov r0, r4 */
/* @0xfb31c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb320 mov r0, r6 */
/* @0xfb324 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb328 add sp, sp, #8 */
/* @0xfb32c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfb330 ldr r3, [pc, #0x10] */
/* @0xfb334 mov r0, #9 */
/* @0xfb338 add r3, pc, r3 */
/* @0xfb33c str r3, [sp, #0x4] */
/* @0xfb340 b 0xfb24c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x8c> */
/* ---- pool：2 字（Alloc 的 file 串偏移 / "{ }" 串偏移） ---- */
/* @0xfb344 eoreq r12, r3, r4, asr #18 */
/* @0xfb348 .word 0x0023c8bc */
/* ══ 6/11  F_String  0x10ec98  size 168  42 条  (池 0x10ed38, 0x10ed3c 两字)
 * @func 0x10ec98 0x10ed40  size 168  42 条（40 条指令 + 2 个池字 0x10ed38/0x10ed3c）
 * 符号 _Z8F_StringR6RValueP9CInstanceS2_iPS_           GML: string(val) → string
 * 参数: args = [sp+0x28]（0x10ecc4：push 12 + sub 28）
 *
 *   ret.tag = 1;                                // 0x10ecb4 str r3,[r0,#0xc]（r3 = 1）—— 先占位
 *   buf = Alloc(256);                           // 0x10ecbc mov r0,r12(=256) / 0x10ecc8 bl 0x27ce78
 *   [sp+0x10] = buf（base）; [sp+0x14] = buf（cur）; [sp+0xc] = 256（remaining）;
 *   buf[0] = 0;                                 // 0x10ece0 / 0x10ece4 / 0x10ecc0 / 0x10ece8
 *   STRING_RValue(&cur, &base, &remaining, args);    // 0x10ecf0 r0=sp+0x14 r1=sp+0x10 r2=sp+0xc r3=args
 *   len = (cur - base) + 1;                     // 0x10ecf4..0x10ed10
 *   buf2 = ReAlloc(base, len);                  // 0x10ed14 bl 0x27cedc（第 4 参 74 = 行号，第 5 参 0）
 *   YYCreateString(ret, buf2);                  // 0x10ed24 bl 0xe5258
 *   Free(buf2);                                 // 0x10ed2c（YYCreateString 已经拷过一份）
 *   return;
 *
 * 结论：string(x) = 走通用 RValue→char* 转换器 STRING_RValue，再重新造一个字符串 RValue。
 *   tag 先写 1 是关键细节：即使 STRING_RValue 中途失败，ret 也是「空串」而不是脏 tag。
 *   256 字节起步、按 cur-base+1 精确 ReAlloc 收紧（两次内存操作，第一次是临时缓冲）。
 */

/* ---- 6/11 F_String 代码 0x10ec98..0x10ed34 ---- */
/* @0x10ec98 ldr r1, [pc, #0x98] */
/* @0x10ec9c mov r12, #256 */
/* @0x10eca0 push {r4, r5, lr} */
/* @0x10eca4 sub sp, sp, #28 */
/* @0x10eca8 mov r4, r0 */
/* @0x10ecac mov r3, #1 */
/* @0x10ecb0 add r1, pc, r1 */
/* @0x10ecb4 str r3, [r0, #0xc] */
/* @0x10ecb8 movw r2, #0x621 */
/* @0x10ecbc mov r0, r12 */
/* @0x10ecc0 str r12, [sp, #0xc] */
/* @0x10ecc4 ldr r5, [sp, #0x28] */
/* @0x10ecc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10eccc add r1, sp, #16 */
/* @0x10ecd0 mov r3, r5 */
/* @0x10ecd4 mov r5, #0 */
/* @0x10ecd8 mov r2, r0 */
/* @0x10ecdc add r0, sp, #24 */
/* @0x10ece0 str r2, [sp, #0x10] */
/* @0x10ece4 str r2, [r0, #-0x4]! */
/* @0x10ece8 strb r5, [r2] */
/* @0x10ecec add r2, sp, #12 */
/* @0x10ecf0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x10ecf4 ldr r0, [sp, #0x10] */
/* @0x10ecf8 ldr r1, [sp, #0x14] */
/* @0x10ecfc mov r3, #74 */
/* @0x10ed00 ldr r2, [pc, #0x34] */
/* @0x10ed04 rsb r1, r0, r1 */
/* @0x10ed08 str r5, [sp] */
/* @0x10ed0c add r2, pc, r2 */
/* @0x10ed10 add r1, r1, #1 */
/* @0x10ed14 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10ed18 mov r5, r0 */
/* @0x10ed1c mov r0, r4 */
/* @0x10ed20 mov r1, r5 */
/* @0x10ed24 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10ed28 mov r0, r5 */
/* @0x10ed2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x10ed30 add sp, sp, #28 */
/* @0x10ed34 pop {r4, r5, pc} */
/* ---- pool：2 字（Alloc/ReAlloc 的 file 串偏移） ---- */
/* @0x10ed38 mlaeq r2, r4, r1, r10 */
/* @0x10ed3c eoreq r2, r2, r4, lsr #6 */
/* ══ 7/11  F_StringFormat  0x10f7e4  size 212  53 条  (池 0x10f8b0, 0x10f8b4 两字)
 * @func 0x10f7e4 0x10f8b8  size 212  53 条（51 条指令 + 2 个池字 0x10f8b0/0x10f8b4）
 * 符号 _Z14F_StringFormatR6RValueP9CInstanceS2_iPS_    GML: string_format(val, total, dec) → string
 * 参数: args = [sp+0x1a8]（0x10f7f4：push 28 + sub 396）
 * 栈保护: canary 从 GOT 取（0x10f7ec/0x10f7fc/0x10f80c → [sp+0x184]），尾校验 0x10f884..0x10f88c
 *         （不等 → 0x10f8ac bl __stack_chk_fail）—— 本卡唯一带 canary 的函数。
 *
 *   if (args[0].tag == 1) {                     // 0x10f800 ldr r2,[r7,#0xc] / 0x10f80c cmp r2,#1
 *     ret = YYCreateString(YYGetString(args,0)); // 0x10f814 beq → 0x10f898 / 0x10f8a4
 *   } else {
 *     val   = YYGetReal(args,0)  → r4:r5;       // 0x10f818 bl 0xceb24（double 走 r0:r1）
 *     total = YYGetInt32(args,1) → r9;          // 0x10f82c
 *     dec   = YYGetInt32(args,2) → r3;          // 0x10f83c
 *     sprintf(buf1, "%%%d.%df", total + dec, dec);      // 0x10f840..0x10f858
 *                                                //   池字 0x10f8b4 → .rodata 0x338fa8 = "%%%d.%df"
 *     sprintf(buf2, buf1, val);                  // 0x10f85c..0x10f870（buf1 当格式串，val 是 double）
 *     ret = YYCreateString(buf2);                // 0x10f87c
 *   }
 *   return;
 *
 * 结论：string_format 是**两次 sprintf**：先造格式串 "%<total+dec>.<dec>f"，再用它格式化 val。
 *   ⇒ 实际宽度 = total + dec（不是 total），小数位 = dec。
 *   两个缓冲都在栈上：buf1 = [sp+4]（128 字节可用），buf2 = [sp+132]（264 字节可用），
 *   **没有任何长度校验**；total/dec 由 GML 侧给，超大值会直接踩栈（canary 是唯一的兜底）。
 *   args[0] 是字符串时整段跳过（直接原样返回），说明它兼作 string_format 的「字符串快路」。
 */

/* ---- 7/11 F_StringFormat 代码 0x10f7e4..0x10f8ac ---- */
/* @0x10f7e4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10f7e8 sub sp, sp, #396 */
/* @0x10f7ec ldr r6, [pc, #0xbc] */
/* @0x10f7f0 mov r8, r0 */
/* @0x10f7f4 ldr r7, [sp, #0x1a8] */
/* @0x10f7f8 mov r1, #0 */
/* @0x10f7fc ldr r6, [pc, r6] */
/* @0x10f800 ldr r2, [r7, #0xc] */
/* @0x10f804 mov r0, r7 */
/* @0x10f808 ldr r3, [r6] */
/* @0x10f80c cmp r2, #1 */
/* @0x10f810 str r3, [sp, #0x184] */
/* @0x10f814 beq 0x10f898 <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10f818 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x10f81c mov r4, r0 */
/* @0x10f820 mov r5, r1 */
/* @0x10f824 mov r0, r7 */
/* @0x10f828 mov r1, #1 */
/* @0x10f82c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f830 mov r1, #2 */
/* @0x10f834 mov r9, r0 */
/* @0x10f838 mov r0, r7 */
/* @0x10f83c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10f840 add r7, sp, #4 */
/* @0x10f844 ldr r1, [pc, #0x68] */
/* @0x10f848 add r1, pc, r1 */
/* @0x10f84c mov r3, r0 */
/* @0x10f850 add r2, r9, r0 */
/* @0x10f854 mov r0, r7 */
/* @0x10f858 bl 0xb6550 <sprintf@plt> */
/* @0x10f85c mov r2, r4 */
/* @0x10f860 add r4, sp, #132 */
/* @0x10f864 mov r1, r7 */
/* @0x10f868 mov r3, r5 */
/* @0x10f86c mov r0, r4 */
/* @0x10f870 bl 0xb6550 <sprintf@plt> */
/* @0x10f874 mov r0, r8 */
/* @0x10f878 mov r1, r4 */
/* @0x10f87c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10f880 ldr r2, [sp, #0x184] */
/* @0x10f884 ldr r3, [r6] */
/* @0x10f888 cmp r2, r3 */
/* @0x10f88c bne 0x10f8ac <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x10f890 add sp, sp, #396 */
/* @0x10f894 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x10f898 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10f89c mov r1, r0 */
/* @0x10f8a0 mov r0, r8 */
/* @0x10f8a4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10f8a8 b 0x10f880 <_Z14F_StringFormatR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x10f8ac bl 0xb65d4 <__stack_chk_fail@plt> */
/* ---- pool：2 字（canary 的 GOT 偏移 / 格式串 "%%%d.%df" 偏移） ---- */
/* @0x10f8b0 eoreq lr, sp, r4, asr r1 */
/* @0x10f8b4 eoreq r9, r2, r8, asr r7 */
/* ══ 8/11  F_StringDigits  0x10ff6c  size 184  46 条  (池 0x110020 一字)
 * @func 0x10ff6c 0x110024  size 184  46 条（45 条指令 + 1 个池字 0x110020）
 * 符号 _Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_    GML: string_digits(str) → string
 * 参数: args = [sp+0x20]（0x10ff7c：push 20 + sub 12）
 *
 *   s = YYGetString(args,0);                    // 0x10ff80 bl 0xd04d0
 *   len = s ? strlen(s)+1 : 1;                  // 0x10ff84 subs / 0x10ff88 moveq r0,#1
 *                                               // 0x10ff90 strlen / 0x10ff94 add r0,r0,#1
 *   buf = Alloc(len);                           // 0x10ffac bl 0x27ce78
 *   [sp] = s（游标）; [sp+4] = buf（输出句柄）;   // 0x10ffb0 / 0x10ffbc（r5 = sp+4）
 *   for (;;) {
 *     c = *cur;                                 // 0x10ffd8 ldr r3,[sp] / 0x10ffdc ldrb r1,[r3]
 *     if (!c) break;                            // 0x10ffe4 cmp r1,#0 / 0x10ffe8 bne → 0x10ffc4
 *     cp = utf8_extract_char(&cur);             // 0x10ffc4 bl 0x10fb38（r0 = sp）
 *     if ((uint16)(cp - 48) <= 9)               // 0x10ffc8 sub r3,r0,#48 / 0x10ffcc uxth
 *                                               // 0x10ffd0 cmp r3,#9 / 0x10ffd4 bls → 0x110010
 *       utf8_add_char(&out, cp);                // 0x110010 r1 = cp / 0x110014 bl 0x10fe28
 *   }
 *   utf8_add_char(&out, 0);                     // 0x10ffec（补 NUL）
 *   ret = YYCreateString(buf);                  // 0x10fff4..0x10fffc
 *   YYFree(buf);                                // 0x110004 bl 0xcef90（注意这里是 YYFree，不是 MemoryManager::Free）
 *
 * 结论：string_digits = 「按 UTF-8 码点过滤，只留 ASCII 0-9」—— 不是按字节过滤
 *   （utf8_extract_char/utf8_add_char 成对出现，多字节字符被整枚丢弃而不是拆成半截）。
 *   空/非字符串实参：len = 1，输出空串。
 */

/* ---- 8/11 F_StringDigits 代码 0x10ff6c..0x11001c ---- */
/* @0x10ff6c push {r4, r5, r6, r7, lr} */
/* @0x10ff70 sub sp, sp, #12 */
/* @0x10ff74 mov r7, r0 */
/* @0x10ff78 mov r1, #0 */
/* @0x10ff7c ldr r0, [sp, #0x20] */
/* @0x10ff80 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10ff84 subs r4, r0, #0 */
/* @0x10ff88 moveq r0, #1 */
/* @0x10ff8c beq 0x10ff98 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10ff90 bl 0xb6538 <strlen@plt> */
/* @0x10ff94 add r0, r0, #1 */
/* @0x10ff98 ldr r1, [pc, #0x80] */
/* @0x10ff9c mov r3, #1 */
/* @0x10ffa0 movw r2, #0x86d */
/* @0x10ffa4 add r5, sp, #8 */
/* @0x10ffa8 add r1, pc, r1 */
/* @0x10ffac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10ffb0 str r4, [sp] */
/* @0x10ffb4 mov r3, r4 */
/* @0x10ffb8 mov r6, r0 */
/* @0x10ffbc str r0, [r5, #-0x4]! */
/* @0x10ffc0 b 0x10ffdc <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x10ffc4 bl 0x10fb38 <utf8_extract_char> */
/* @0x10ffc8 sub r3, r0, #48 */
/* @0x10ffcc uxth r3, r3 */
/* @0x10ffd0 cmp r3, #9 */
/* @0x10ffd4 bls 0x110010 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x10ffd8 ldr r3, [sp] */
/* @0x10ffdc ldrb r1, [r3] */
/* @0x10ffe0 mov r0, sp */
/* @0x10ffe4 cmp r1, #0 */
/* @0x10ffe8 bne 0x10ffc4 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x10ffec mov r0, r5 */
/* @0x10fff0 bl 0x10fe28 <utf8_add_char> */
/* @0x10fff4 mov r0, r7 */
/* @0x10fff8 mov r1, r6 */
/* @0x10fffc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x110000 mov r0, r6 */
/* @0x110004 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x110008 add sp, sp, #12 */
/* @0x11000c pop {r4, r5, r6, r7, pc} */
/* @0x110010 mov r1, r0 */
/* @0x110014 mov r0, r5 */
/* @0x110018 bl 0x10fe28 <utf8_add_char> */
/* @0x11001c b 0x10ffd8 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x6c> */
/* ---- pool：1 字（Alloc 的 file 串偏移） ---- */
/* @0x110020 mlaeq r2, r12, lr, r8 */
/* ══ 9/11  F_Max  0x1135a8  size 972  243 条（无 literal pool；两张 15 路 tag 表都在代码流里）
 * @func 0x1135a8 0x113974  size 972  243 条（243 条指令，无池）
 * 符号 _Z5F_MaxR6RValueP9CInstanceS2_iPS_             GML: max(v0, v1, ...) → 夺得最大者的原 RValue
 * 参数: args = [sp+0x40]（0x1135f8：push 36 + vpush 16 + sub 12）；argc 在 r3（0x1135b0 subs r9,r3,#0）
 *
 *   ret = {0, 0, tag 0};                        // 0x1135b8..0x1135cc（三条 str 0）
 *   if (argc == 0) return;                      // 0x1135d0 beq → 0x11373c
 *   ret = args[0];                              // 0x1135d4..0x1135e4 取 tag/数据字、0x1135e8..0x1135f0 分派头
 *                                               // 0x1135f8..0x113630 第一张 15 路表（首个落点 0x113634）
 *   best = YYGetReal(args,0) → d9;              // 0x11363c..0x11364c
 *   if (argc <= 1) return;                      // 0x113650 cmp #1 / 0x113654 ble → 0x11373c
 *   for (i = 1; i < argc; i++) {                // 0x113660..0x113668（r5 = i、r6 = args+(i-1)*16）
 *     v = YYGetReal(args,i) → d8;               // 0x11366c
 *     if (!(v > best)) continue;                // 0x113670 vcmpe.f64 d8,d9 / 0x113674 vmrs
 *                                               // 0x113678 addle r7,r6,#16 / 0x11367c ble → 0x11372c
 *     ret = args[i]（先释放旧值再按 tag 搬运）;  // 0x113680..0x113720（旧值释放 0x113794/0x11380c、
 *                                               //   第二张 15 路表 0x1136e4..0x11371c）
 *     best = v;                                 // 0x113720 vmov.f64 d9,d8
 *   }
 *   return;
 *
 * ⚠ 与 F_Min 的关系（本卡的跨函数硬事实）：两函数逐条同构，243 条里**只有 2 条不同** ——
 *   0x113678 addle / 0x11367c ble  ↔  F_Min 的 0x1132a8 addpl / 0x1132ac bpl。
 *   逐条比 32 位指令字：**217 条完全相同**、24 条只有分支位移不同（同 mnemonic、同条件码）、只有上述 2 条是真差异。
 *   两张 tag 表、旧值释放链、尾跳一字不差 ⇒ 原版是同一份模板生成的两个函数。
 *   ⇒ 原版是同一份模板生成的两个函数，唯一差别是「更新条件取反」。
 * 比较语义：vcmpe 后接 ble（Z==1 或 N!=V 即「不大于」就跳过）⇒ 只有严格更大才夺位；
 *   NaN（无序：Z=0,N=0,V=1）→ N!=V 成立 → 跳过 ⇒ **NaN 永不夺位**，与 min 一致。
 */

/* ---- 9/11 F_Max 0x1135a8..0x113970（无池） ---- */
/* @0x1135a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1135ac vpush {d8, d9} */
/* @0x1135b0 subs r9, r3, #0 */
/* @0x1135b4 sub sp, sp, #12 */
/* @0x1135b8 mov r3, #0 */
/* @0x1135bc mov r4, r0 */
/* @0x1135c0 str r3, [r0, #0xc] */
/* @0x1135c4 ldr r8, [sp, #0x40] */
/* @0x1135c8 str r3, [r0] */
/* @0x1135cc str r3, [r0, #0x4] */
/* @0x1135d0 beq 0x11373c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1135d4 ldr r1, [r8, #0xc] */
/* @0x1135d8 ldr r2, [r8, #0x8] */
/* @0x1135dc str r1, [r0, #0xc] */
/* @0x1135e0 ldr r3, [r8, #0xc] */
/* @0x1135e4 str r2, [r0, #0x8] */
/* @0x1135e8 bic r3, r3, #-16777216 */
/* @0x1135ec cmp r3, #14 */
/* @0x1135f0 addls pc, pc, r3, lsl #2 */
/* @0x1135f4 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1135f8 b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x1135fc b 0x1138a4 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x113600 b 0x1138bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x113604 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113608 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11360c b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113610 b 0x1138e8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x113614 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113618 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11361c b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113620 b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113624 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113628 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11362c b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113630 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113634 ldr r3, [r8] */
/* @0x113638 str r3, [r4] */
/* @0x11363c mov r0, r8 */
/* @0x113640 mov r1, #0 */
/* @0x113644 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113648 cmp r9, #1 */
/* @0x11364c vmov d9, r0, r1 */
/* @0x113650 ble 0x11373c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113654 mov r6, r8 */
/* @0x113658 mov r5, #1 */
/* @0x11365c mov r10, #0 */
/* @0x113660 mov r0, r8 */
/* @0x113664 mov r1, r5 */
/* @0x113668 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11366c vmov d8, r0, r1 */
/* @0x113670 vcmpe.f64 d8, d9 */
/* @0x113674 vmrs APSR_nzcv, fpscr */
/* @0x113678 addle r7, r6, #16 */
/* @0x11367c ble 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x113680 ldr r2, [r4, #0xc] */
/* @0x113684 add r7, r6, #16 */
/* @0x113688 bic r3, r2, #-16777216 */
/* @0x11368c cmp r3, #1 */
/* @0x113690 beq 0x113794 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x113694 cmp r3, #2 */
/* @0x113698 bne 0x1136bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x11369c sub r2, r2, #1 */
/* @0x1136a0 bic r2, r2, #-16777216 */
/* @0x1136a4 bic r2, r2, #3 */
/* @0x1136a8 cmp r2, #0 */
/* @0x1136ac beq 0x11384c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x1136b0 mov r3, #5 */
/* @0x1136b4 str r10, [r4, #0x8] */
/* @0x1136b8 str r3, [r4, #0xc] */
/* @0x1136bc str r10, [r4] */
/* @0x1136c0 ldr r3, [r6, #0x1c] */
/* @0x1136c4 str r3, [r4, #0xc] */
/* @0x1136c8 ldr r3, [r6, #0x18] */
/* @0x1136cc str r3, [r4, #0x8] */
/* @0x1136d0 ldr r3, [r6, #0x1c] */
/* @0x1136d4 bic r3, r3, #-16777216 */
/* @0x1136d8 cmp r3, #14 */
/* @0x1136dc addls pc, pc, r3, lsl #2 */
/* @0x1136e0 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136e4 b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x1136e8 b 0x1137ec <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x1136ec b 0x11375c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x1136f0 b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x1136f4 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136f8 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136fc b 0x1137c4 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x113700 b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113704 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113708 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11370c b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113710 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113714 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113718 b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x11371c b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113720 vmov.f64 d9, d8 */
/* @0x113724 ldr r3, [r6, #0x10] */
/* @0x113728 str r3, [r4] */
/* @0x11372c add r5, r5, #1 */
/* @0x113730 mov r6, r7 */
/* @0x113734 cmp r5, r9 */
/* @0x113738 bne 0x113660 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x11373c add sp, sp, #12 */
/* @0x113740 vpop {d8, d9} */
/* @0x113744 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x113748 ldr r2, [r7] */
/* @0x11374c vmov.f64 d9, d8 */
/* @0x113750 ldr r3, [r7, #0x4] */
/* @0x113754 stm r4, {r2, r3} */
/* @0x113758 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11375c ldr r3, [r6, #0x10] */
/* @0x113760 cmp r3, #0 */
/* @0x113764 str r3, [r4] */
/* @0x113768 beq 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11376c ldr r1, [r3, #0x8] */
/* @0x113770 ldr r2, [r3] */
/* @0x113774 cmp r1, #0 */
/* @0x113778 streq r4, [r3, #0x8] */
/* @0x11377c add r2, r2, #1 */
/* @0x113780 str r2, [r3] */
/* @0x113784 vmoveq.f64 d9, d8 */
/* @0x113788 beq 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11378c vmov.f64 d9, d8 */
/* @0x113790 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x113794 ldr r11, [r4] */
/* @0x113798 cmp r11, #0 */
/* @0x11379c beq 0x1137bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1137a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1137a4 ldr r2, [r11, #0x4] */
/* @0x1137a8 sub r2, r2, #1 */
/* @0x1137ac str r2, [r11, #0x4] */
/* @0x1137b0 cmp r2, #0 */
/* @0x1137b4 beq 0x11380c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1137b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1137bc str r10, [r4] */
/* @0x1137c0 b 0x1136bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1137c4 ldr r3, [r6, #0x10] */
/* @0x1137c8 str r3, [r4] */
/* @0x1137cc ldr r3, [r6, #0x10] */
/* @0x1137d0 cmp r3, #0 */
/* @0x1137d4 beq 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1137d8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1137dc ldr r1, [r6, #0x10] */
/* @0x1137e0 vmov.f64 d9, d8 */
/* @0x1137e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1137e8 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1137ec ldr r3, [r6, #0x10] */
/* @0x1137f0 vmov.f64 d9, d8 */
/* @0x1137f4 cmp r3, #0 */
/* @0x1137f8 ldrne r2, [r3, #0x4] */
/* @0x1137fc addne r2, r2, #1 */
/* @0x113800 strne r2, [r3, #0x4] */
/* @0x113804 str r3, [r4] */
/* @0x113808 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11380c ldr r0, [r11] */
/* @0x113810 str r2, [sp, #0x4] */
/* @0x113814 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113818 ldr r2, [sp, #0x4] */
/* @0x11381c str r2, [r11] */
/* @0x113820 str r2, [r11, #0x8] */
/* @0x113824 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113828 ldr r2, [r11, #0x4] */
/* @0x11382c sub r2, r2, #1 */
/* @0x113830 str r2, [r11, #0x4] */
/* @0x113834 cmp r2, #0 */
/* @0x113838 beq 0x113864 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x11383c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113840 mov r0, r11 */
/* @0x113844 bl 0x27d1d0 <_ZdlPv> */
/* @0x113848 b 0x1137b8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x11384c mov r0, r4 */
/* @0x113850 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113854 b 0x1136b0 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113858 ldm r8, {r2, r3} */
/* @0x11385c stm r0, {r2, r3} */
/* @0x113860 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113864 ldr r0, [r11] */
/* @0x113868 str r2, [sp, #0x4] */
/* @0x11386c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113870 ldr r2, [sp, #0x4] */
/* @0x113874 str r2, [r11] */
/* @0x113878 str r2, [r11, #0x8] */
/* @0x11387c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113880 ldr r2, [r11, #0x4] */
/* @0x113884 sub r2, r2, #1 */
/* @0x113888 str r2, [r11, #0x4] */
/* @0x11388c cmp r2, #0 */
/* @0x113890 beq 0x11390c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x364> */
/* @0x113894 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113898 mov r0, r11 */
/* @0x11389c bl 0x27d1d0 <_ZdlPv> */
/* @0x1138a0 b 0x11383c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x1138a4 ldr r3, [r8] */
/* @0x1138a8 cmp r3, #0 */
/* @0x1138ac ldrne r2, [r3, #0x4] */
/* @0x1138b0 addne r2, r2, #1 */
/* @0x1138b4 strne r2, [r3, #0x4] */
/* @0x1138b8 b 0x113638 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1138bc ldr r3, [r8] */
/* @0x1138c0 cmp r3, #0 */
/* @0x1138c4 str r3, [r0] */
/* @0x1138c8 beq 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138cc ldr r1, [r3, #0x8] */
/* @0x1138d0 ldr r2, [r3] */
/* @0x1138d4 cmp r1, #0 */
/* @0x1138d8 streq r0, [r3, #0x8] */
/* @0x1138dc add r2, r2, #1 */
/* @0x1138e0 str r2, [r3] */
/* @0x1138e4 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138e8 ldr r3, [r8] */
/* @0x1138ec str r3, [r0] */
/* @0x1138f0 ldr r3, [r8] */
/* @0x1138f4 cmp r3, #0 */
/* @0x1138f8 beq 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138fc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113900 ldr r1, [r8] */
/* @0x113904 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113908 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11390c ldr r0, [r11] */
/* @0x113910 str r2, [sp, #0x4] */
/* @0x113914 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113918 ldr r2, [sp, #0x4] */
/* @0x11391c str r2, [r11] */
/* @0x113920 str r2, [r11, #0x8] */
/* @0x113924 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113928 ldr r2, [r11, #0x4] */
/* @0x11392c sub r2, r2, #1 */
/* @0x113930 str r2, [r11, #0x4] */
/* @0x113934 cmp r2, #0 */
/* @0x113938 bne 0x113964 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x11393c ldr r0, [r11] */
/* @0x113940 str r2, [sp, #0x4] */
/* @0x113944 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113948 ldr r2, [sp, #0x4] */
/* @0x11394c mov r0, r11 */
/* @0x113950 str r2, [r11] */
/* @0x113954 str r2, [r11, #0x8] */
/* @0x113958 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x11395c mov r0, r11 */
/* @0x113960 bl 0x27d1d0 <_ZdlPv> */
/* @0x113964 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113968 mov r0, r11 */
/* @0x11396c bl 0x27d1d0 <_ZdlPv> */
/* @0x113970 b 0x113894 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* ══ 10/11  F_Min  0x1131d8  size 972  243 条（无 literal pool）
 * @func 0x1131d8 0x1135a4  size 972  243 条（243 条指令，无池）
 * 符号 _Z5F_MinR6RValueP9CInstanceS2_iPS_             GML: min(v0, v1, ...) → 夺得最小者的原 RValue
 * 参数: args = [sp+0x40]（0x1131f4：push 36 + vpush {d8,d9} 16 + sub 12）；argc 在 r3（0x1131e0 subs r9,r3,#0）
 *
 *   ret = {0, 0, tag 0};                        // 0x1131e8 mov r3,#0 / 0x1131f0 / 0x1131f8 / 0x1131fc
 *   if (argc == 0) return;                      // 0x113200 beq → 0x11336c（结果 real 0.0）
 *   ret = args[0];                              // 0x113204 ldr r1,[r8,#0xc]（tag）/ 0x113208 ldr r2,[r8,#8]
 *                                               // 0x11320c str tag / 0x113214 str 数据字
 *   switch (tag & 0x00FFFFFF) {                 // 0x113218 bic / 0x11321c cmp #14 / 0x113220 addls
 *                                               //   表体 0x113228..0x113260
 *     case 0,10,13: ldm r8,{r2,r3}; stm r0,{r2,r3}            // 0x113488：8 字节整拷
 *     case 1:  refcnt++ 后只存指针                            // 0x1134d4 → 0x113268
 *     case 2:  数组引用计数（[v]==count++、[v+8] 回填 &ret）   // 0x1134ec
 *     case 3,7,14: 只存指针                                   // 0x113264
 *     case 6:  只存指针 + GetContextStackTop + DeterminePotentialRoot   // 0x113518（GC 根登记）
 *     case 4,5,8,9,11,12: 只写 tag                            // 0x11326c
 *   }
 *   best = YYGetReal(args,0) → d9;              // 0x11326c mov r0,r8 / 0x113274 mov r1,#0 / 0x11327c vmov d9
 *   if (argc <= 1) return;                      // 0x113278 cmp r9,#1 / 0x113280 ble → 0x11336c
 *   for (i = 1; i < argc; i++) {                // 0x113288 r5=1 / 0x11328c r10=0 / 0x113290..0x113298
 *     v = YYGetReal(args,i) → d8;               // 0x11329c vmov d8
 *     if (!(v < best)) continue;                // 0x1132a0 vcmpe.f64 d8,d9 / 0x1132a4 vmrs
 *                                               // 0x1132a8 addpl / 0x1132ac bpl → 0x11335c
 *     释放旧 ret（只清 tag 1 与 tag 2）:         // 0x1132b0 ldr r2,[r4,#0xc] / 0x1132b8 bic
 *                                               // 0x1132bc cmp #1 → 0x1133c4..0x11347c（_RefThing 归零链）
 *                                               // 0x1132c4 cmp #2 → 0x11347c FREE_RValue__Pre
 *     ret = args[i];                            // 0x1132e0..0x1132ec 先清 [r4] / 0x1132f0 取 tag / 0x1132fc 取数据
 *                                               // 0x113304..0x113310 第二张 15 路表（0x113314..0x11334c）
 *     best = v;                                 // 0x113350 vmov.f64 d9,d8（只在该 tag 的落点里执行）
 *   }
 *   return;
 *
 * 第二张表（替换路）与第一张表逐项同构，落点：0/10/13→0x113378（8 字节）、1→0x11341c（refcnt++）、
 *   2→0x11338c（数组计数）、3/7/14→0x113350（只存指针 + 更新 best）、6→0x1133f4（GC 根）、
 *   4/5/8/9/11/12→0x1133bc（只更新 best）。
 * ⚠ 循环里的旧值释放只覆盖 tag 1（字符串专用链）和 tag 2（FREE_RValue__Pre）；3/4 不清
 *   —— 与 find_value 的旧值释放判据完全相同（两处独立落锚）。
 * NaN：vcmpe 后 bpl（N==0 即跳）⇒ 无序同样跳过 ⇒ NaN 永不夺位。
 * 返回值是**夺得者的原 RValue**（含类型），不是 double —— 这是 min/max 在本版 runner 里的关键语义。
 */

/* ---- 10/11 F_Min 0x1131d8..0x1135a0（无池） ---- */
/* @0x1131d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1131dc vpush {d8, d9} */
/* @0x1131e0 subs r9, r3, #0 */
/* @0x1131e4 sub sp, sp, #12 */
/* @0x1131e8 mov r3, #0 */
/* @0x1131ec mov r4, r0 */
/* @0x1131f0 str r3, [r0, #0xc] */
/* @0x1131f4 ldr r8, [sp, #0x40] */
/* @0x1131f8 str r3, [r0] */
/* @0x1131fc str r3, [r0, #0x4] */
/* @0x113200 beq 0x11336c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113204 ldr r1, [r8, #0xc] */
/* @0x113208 ldr r2, [r8, #0x8] */
/* @0x11320c str r1, [r0, #0xc] */
/* @0x113210 ldr r3, [r8, #0xc] */
/* @0x113214 str r2, [r0, #0x8] */
/* @0x113218 bic r3, r3, #-16777216 */
/* @0x11321c cmp r3, #14 */
/* @0x113220 addls pc, pc, r3, lsl #2 */
/* @0x113224 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113228 b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x11322c b 0x1134d4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x113230 b 0x1134ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x113234 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113238 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11323c b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113240 b 0x113518 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x113244 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113248 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11324c b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113250 b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113254 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113258 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11325c b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113260 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113264 ldr r3, [r8] */
/* @0x113268 str r3, [r4] */
/* @0x11326c mov r0, r8 */
/* @0x113270 mov r1, #0 */
/* @0x113274 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113278 cmp r9, #1 */
/* @0x11327c vmov d9, r0, r1 */
/* @0x113280 ble 0x11336c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113284 mov r6, r8 */
/* @0x113288 mov r5, #1 */
/* @0x11328c mov r10, #0 */
/* @0x113290 mov r0, r8 */
/* @0x113294 mov r1, r5 */
/* @0x113298 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11329c vmov d8, r0, r1 */
/* @0x1132a0 vcmpe.f64 d8, d9 */
/* @0x1132a4 vmrs APSR_nzcv, fpscr */
/* @0x1132a8 addpl r7, r6, #16 */
/* @0x1132ac bpl 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1132b0 ldr r2, [r4, #0xc] */
/* @0x1132b4 add r7, r6, #16 */
/* @0x1132b8 bic r3, r2, #-16777216 */
/* @0x1132bc cmp r3, #1 */
/* @0x1132c0 beq 0x1133c4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x1132c4 cmp r3, #2 */
/* @0x1132c8 bne 0x1132ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1132cc sub r2, r2, #1 */
/* @0x1132d0 bic r2, r2, #-16777216 */
/* @0x1132d4 bic r2, r2, #3 */
/* @0x1132d8 cmp r2, #0 */
/* @0x1132dc beq 0x11347c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x1132e0 mov r3, #5 */
/* @0x1132e4 str r10, [r4, #0x8] */
/* @0x1132e8 str r3, [r4, #0xc] */
/* @0x1132ec str r10, [r4] */
/* @0x1132f0 ldr r3, [r6, #0x1c] */
/* @0x1132f4 str r3, [r4, #0xc] */
/* @0x1132f8 ldr r3, [r6, #0x18] */
/* @0x1132fc str r3, [r4, #0x8] */
/* @0x113300 ldr r3, [r6, #0x1c] */
/* @0x113304 bic r3, r3, #-16777216 */
/* @0x113308 cmp r3, #14 */
/* @0x11330c addls pc, pc, r3, lsl #2 */
/* @0x113310 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113314 b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113318 b 0x11341c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x11331c b 0x11338c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x113320 b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113324 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113328 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11332c b 0x1133f4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x113330 b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113334 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113338 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11333c b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113340 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113344 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113348 b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x11334c b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113350 vmov.f64 d9, d8 */
/* @0x113354 ldr r3, [r6, #0x10] */
/* @0x113358 str r3, [r4] */
/* @0x11335c add r5, r5, #1 */
/* @0x113360 mov r6, r7 */
/* @0x113364 cmp r5, r9 */
/* @0x113368 bne 0x113290 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x11336c add sp, sp, #12 */
/* @0x113370 vpop {d8, d9} */
/* @0x113374 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x113378 ldr r2, [r7] */
/* @0x11337c vmov.f64 d9, d8 */
/* @0x113380 ldr r3, [r7, #0x4] */
/* @0x113384 stm r4, {r2, r3} */
/* @0x113388 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11338c ldr r3, [r6, #0x10] */
/* @0x113390 cmp r3, #0 */
/* @0x113394 str r3, [r4] */
/* @0x113398 beq 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11339c ldr r1, [r3, #0x8] */
/* @0x1133a0 ldr r2, [r3] */
/* @0x1133a4 cmp r1, #0 */
/* @0x1133a8 streq r4, [r3, #0x8] */
/* @0x1133ac add r2, r2, #1 */
/* @0x1133b0 str r2, [r3] */
/* @0x1133b4 vmoveq.f64 d9, d8 */
/* @0x1133b8 beq 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1133bc vmov.f64 d9, d8 */
/* @0x1133c0 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1133c4 ldr r11, [r4] */
/* @0x1133c8 cmp r11, #0 */
/* @0x1133cc beq 0x1133ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1133d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1133d4 ldr r2, [r11, #0x4] */
/* @0x1133d8 sub r2, r2, #1 */
/* @0x1133dc str r2, [r11, #0x4] */
/* @0x1133e0 cmp r2, #0 */
/* @0x1133e4 beq 0x11343c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1133e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1133ec str r10, [r4] */
/* @0x1133f0 b 0x1132ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1133f4 ldr r3, [r6, #0x10] */
/* @0x1133f8 str r3, [r4] */
/* @0x1133fc ldr r3, [r6, #0x10] */
/* @0x113400 cmp r3, #0 */
/* @0x113404 beq 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113408 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x11340c ldr r1, [r6, #0x10] */
/* @0x113410 vmov.f64 d9, d8 */
/* @0x113414 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113418 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11341c ldr r3, [r6, #0x10] */
/* @0x113420 vmov.f64 d9, d8 */
/* @0x113424 cmp r3, #0 */
/* @0x113428 ldrne r2, [r3, #0x4] */
/* @0x11342c addne r2, r2, #1 */
/* @0x113430 strne r2, [r3, #0x4] */
/* @0x113434 str r3, [r4] */
/* @0x113438 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11343c ldr r0, [r11] */
/* @0x113440 str r2, [sp, #0x4] */
/* @0x113444 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113448 ldr r2, [sp, #0x4] */
/* @0x11344c str r2, [r11] */
/* @0x113450 str r2, [r11, #0x8] */
/* @0x113454 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113458 ldr r2, [r11, #0x4] */
/* @0x11345c sub r2, r2, #1 */
/* @0x113460 str r2, [r11, #0x4] */
/* @0x113464 cmp r2, #0 */
/* @0x113468 beq 0x113494 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x11346c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113470 mov r0, r11 */
/* @0x113474 bl 0x27d1d0 <_ZdlPv> */
/* @0x113478 b 0x1133e8 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x11347c mov r0, r4 */
/* @0x113480 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113484 b 0x1132e0 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113488 ldm r8, {r2, r3} */
/* @0x11348c stm r0, {r2, r3} */
/* @0x113490 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113494 ldr r0, [r11] */
/* @0x113498 str r2, [sp, #0x4] */
/* @0x11349c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1134a0 ldr r2, [sp, #0x4] */
/* @0x1134a4 str r2, [r11] */
/* @0x1134a8 str r2, [r11, #0x8] */
/* @0x1134ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1134b0 ldr r2, [r11, #0x4] */
/* @0x1134b4 sub r2, r2, #1 */
/* @0x1134b8 str r2, [r11, #0x4] */
/* @0x1134bc cmp r2, #0 */
/* @0x1134c0 beq 0x11353c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x364> */
/* @0x1134c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1134c8 mov r0, r11 */
/* @0x1134cc bl 0x27d1d0 <_ZdlPv> */
/* @0x1134d0 b 0x11346c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x1134d4 ldr r3, [r8] */
/* @0x1134d8 cmp r3, #0 */
/* @0x1134dc ldrne r2, [r3, #0x4] */
/* @0x1134e0 addne r2, r2, #1 */
/* @0x1134e4 strne r2, [r3, #0x4] */
/* @0x1134e8 b 0x113268 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1134ec ldr r3, [r8] */
/* @0x1134f0 cmp r3, #0 */
/* @0x1134f4 str r3, [r0] */
/* @0x1134f8 beq 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1134fc ldr r1, [r3, #0x8] */
/* @0x113500 ldr r2, [r3] */
/* @0x113504 cmp r1, #0 */
/* @0x113508 streq r0, [r3, #0x8] */
/* @0x11350c add r2, r2, #1 */
/* @0x113510 str r2, [r3] */
/* @0x113514 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113518 ldr r3, [r8] */
/* @0x11351c str r3, [r0] */
/* @0x113520 ldr r3, [r8] */
/* @0x113524 cmp r3, #0 */
/* @0x113528 beq 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11352c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113530 ldr r1, [r8] */
/* @0x113534 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113538 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11353c ldr r0, [r11] */
/* @0x113540 str r2, [sp, #0x4] */
/* @0x113544 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113548 ldr r2, [sp, #0x4] */
/* @0x11354c str r2, [r11] */
/* @0x113550 str r2, [r11, #0x8] */
/* @0x113554 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113558 ldr r2, [r11, #0x4] */
/* @0x11355c sub r2, r2, #1 */
/* @0x113560 str r2, [r11, #0x4] */
/* @0x113564 cmp r2, #0 */
/* @0x113568 bne 0x113594 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x11356c ldr r0, [r11] */
/* @0x113570 str r2, [sp, #0x4] */
/* @0x113574 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113578 ldr r2, [sp, #0x4] */
/* @0x11357c mov r0, r11 */
/* @0x113580 str r2, [r11] */
/* @0x113584 str r2, [r11, #0x8] */
/* @0x113588 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x11358c mov r0, r11 */
/* @0x113590 bl 0x27d1d0 <_ZdlPv> */
/* @0x113594 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113598 mov r0, r11 */
/* @0x11359c bl 0x27d1d0 <_ZdlPv> */
/* @0x1135a0 b 0x1134c4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* ══ 11/11  F_Choose  0x113978  size 668  167 条  (池 0x113c10 一字 = 0x00000000)
 * @func 0x113978 0x113c14  size 668  167 条（166 条指令 + 1 个池字 0x113c10）
 * 符号 _Z8F_ChooseR6RValueP9CInstanceS2_iPS_          GML: choose(v0, v1, ...) → 随机取一个实参
 * 参数: args = [sp+0x20]（0x113988：push 32）；argc 在 r3（0x11397c subs r5,r3,#0）
 *
 *   ret = {0, 0, tag 0};                        // 0x113980 mov r2,#0 / 0x11398c / 0x113990 / 0x113994
 *   if (argc == 0) return;                      // 0x113998 popeq（连帧都不拆，直接返回 0.0）
 *   n = YYRandom(argc);                         // 0x11399c mov r0,r5 / 0x1139a0 bl 0x0c4600
 *   i = (int)floor((float)(uint32)n + 0.0f);    // 0x1139a4 vldr s15,[pc,#612] → 池字 0x113c10 = 0.0f
 *                                               // 0x1139a8 vmov s12,r0 / 0x1139ac vcvt.f32.u32
 *                                               // 0x1139b0 vadd.f32 / 0x1139b4 vcvt.f64.f32
 *                                               // 0x1139bc bl floor / 0x1139cc vcvt.s32.f64 / 0x1139d0
 *   if (argc <= i) i = argc - 1;                // 0x1139d4 cmp r5,r0 / 0x1139d8 suble r0,r5,#1（越界钳位）
 *   sel = args + i*16;                          // 0x1139e0 lsl r7,r0,#4 / 0x1139e4 add r5,r6,r7
 *   旧 ret 释放（tag 1/2）; ret = *sel;         // 0x1139e8..0x113a14 旧值释放（0x113a9c..0x113b70）
 *                                               // 0x113a18..0x113a3c 头部三字 + 15 路表（表体 0x113a44..0x113a7c）
 *   return;                                     // 各 tag 落点直接 pop 返回（0x113a88 等）
 *
 * 表的落点：0/10/13→0x113a8c（8 字节整拷）、1→0x113af4（refcnt++）、2→0x113b0c（数组计数）、
 *   3/7/14→0x113a80（只存指针）、6→0x113ad0（GC 根）、4/5/8/9/11/12→0x113a88（只写 tag）。
 * ⚠ 池字 0x113c10 是 **0.0f**（TSV 渲染成 andeq r0,r0,r0 = 0x00000000），不是 0.5f
 *   ⇒ 「加 0.5 再 floor」的圆整在整数输入上是恒等；i 实际就是 YYRandom(argc) 的返回值。
 * ⚠ 旧值释放链 0x113a9c..0x113b70 在本函数内**不可达**：入口已把 tag 写成 0（0x11398c），
 *   而这两条释放在此之前没有别的写入者 ⇒ 编译器为通用赋值模板发的死代码（静态可达性结论）。
 * YYRandom(int) 本体（0x0c4600）：YYRandom() 取一个 32 位整数，再与 |n| 做
 *   __aeabi_uidivmod 取余 ⇒ 返回值 ∈ [0, |n|-1]；负数 n 走 (n^sign)-sign 取绝对值。
 *   YYRandom()（0x0c44ec）是 16 字状态的整数发生器（+一个状态下标全局），本卡不展开（open 6）。
 */

/* ---- 11/11 F_Choose 代码 0x113978..0x113c0c ---- */
/* @0x113978 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11397c subs r5, r3, #0 */
/* @0x113980 mov r2, #0 */
/* @0x113984 mov r4, r0 */
/* @0x113988 ldr r6, [sp, #0x20] */
/* @0x11398c str r2, [r0, #0xc] */
/* @0x113990 str r2, [r0] */
/* @0x113994 str r2, [r0, #0x4] */
/* @0x113998 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x11399c mov r0, r5 */
/* @0x1139a0 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1139a4 vldr s15, [pc, #612] */
/* @0x1139a8 vmov s12, r0 */
/* @0x1139ac vcvt.f32.u32 s14, s12 */
/* @0x1139b0 vadd.f32 s15, s14, s15 */
/* @0x1139b4 vcvt.f64.f32 d6, s15 */
/* @0x1139b8 vmov r0, r1, d6 */
/* @0x1139bc bl 0xb6598 <floor@plt> */
/* @0x1139c0 ldr r2, [r4, #0xc] */
/* @0x1139c4 bic r3, r2, #-16777216 */
/* @0x1139c8 vmov d7, r0, r1 */
/* @0x1139cc vcvt.s32.f64 s15, d7 */
/* @0x1139d0 vmov r0, s15 */
/* @0x1139d4 cmp r5, r0 */
/* @0x1139d8 suble r0, r5, #1 */
/* @0x1139dc cmp r3, #1 */
/* @0x1139e0 lsl r7, r0, #4 */
/* @0x1139e4 add r5, r6, r7 */
/* @0x1139e8 beq 0x113a9c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1139ec cmp r3, #2 */
/* @0x1139f0 bne 0x113a18 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1139f4 sub r2, r2, #1 */
/* @0x1139f8 bic r2, r2, #-16777216 */
/* @0x1139fc bic r2, r2, #3 */
/* @0x113a00 cmp r2, #0 */
/* @0x113a04 beq 0x113b70 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x113a08 mov r2, #0 */
/* @0x113a0c mov r3, #5 */
/* @0x113a10 str r2, [r4, #0x8] */
/* @0x113a14 str r3, [r4, #0xc] */
/* @0x113a18 ldr r3, [r5, #0xc] */
/* @0x113a1c mov r1, #0 */
/* @0x113a20 ldr r2, [r5, #0x8] */
/* @0x113a24 str r1, [r4] */
/* @0x113a28 str r3, [r4, #0xc] */
/* @0x113a2c ldr r3, [r5, #0xc] */
/* @0x113a30 str r2, [r4, #0x8] */
/* @0x113a34 bic r3, r3, #-16777216 */
/* @0x113a38 cmp r3, #14 */
/* @0x113a3c addls pc, pc, r3, lsl #2 */
/* @0x113a40 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a44 b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a48 b 0x113af4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x113a4c b 0x113b0c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113a50 b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a54 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a58 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a5c b 0x113ad0 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x113a60 b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a64 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a68 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a6c b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a70 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a74 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a78 b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a7c b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a80 ldr r3, [r6, r7] */
/* @0x113a84 str r3, [r4] */
/* @0x113a88 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113a8c ldr r2, [r6, r7] */
/* @0x113a90 ldr r3, [r5, #0x4] */
/* @0x113a94 stm r4, {r2, r3} */
/* @0x113a98 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113a9c ldr r8, [r4] */
/* @0x113aa0 cmp r8, #0 */
/* @0x113aa4 beq 0x113ac4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x113aa8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113aac ldr r9, [r8, #0x4] */
/* @0x113ab0 sub r9, r9, #1 */
/* @0x113ab4 str r9, [r8, #0x4] */
/* @0x113ab8 cmp r9, #0 */
/* @0x113abc beq 0x113b38 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x113ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113ac4 mov r3, #0 */
/* @0x113ac8 str r3, [r4] */
/* @0x113acc b 0x113a18 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x113ad0 ldr r3, [r6, r7] */
/* @0x113ad4 str r3, [r4] */
/* @0x113ad8 ldr r3, [r6, r7] */
/* @0x113adc cmp r3, #0 */
/* @0x113ae0 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113ae4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113ae8 ldr r1, [r6, r7] */
/* @0x113aec pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x113af0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113af4 ldr r3, [r6, r7] */
/* @0x113af8 cmp r3, #0 */
/* @0x113afc ldrne r2, [r3, #0x4] */
/* @0x113b00 addne r2, r2, #1 */
/* @0x113b04 strne r2, [r3, #0x4] */
/* @0x113b08 b 0x113a84 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x113b0c ldr r3, [r6, r7] */
/* @0x113b10 cmp r3, #0 */
/* @0x113b14 str r3, [r4] */
/* @0x113b18 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113b1c ldr r1, [r3, #0x8] */
/* @0x113b20 ldr r2, [r3] */
/* @0x113b24 cmp r1, #0 */
/* @0x113b28 streq r4, [r3, #0x8] */
/* @0x113b2c add r2, r2, #1 */
/* @0x113b30 str r2, [r3] */
/* @0x113b34 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113b38 ldr r0, [r8] */
/* @0x113b3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113b40 str r9, [r8] */
/* @0x113b44 str r9, [r8, #0x8] */
/* @0x113b48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113b4c ldr r9, [r8, #0x4] */
/* @0x113b50 sub r9, r9, #1 */
/* @0x113b54 str r9, [r8, #0x4] */
/* @0x113b58 cmp r9, #0 */
/* @0x113b5c beq 0x113b7c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x113b60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113b64 mov r0, r8 */
/* @0x113b68 bl 0x27d1d0 <_ZdlPv> */
/* @0x113b6c b 0x113ac0 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x113b70 mov r0, r4 */
/* @0x113b74 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113b78 b 0x113a08 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x113b7c ldr r0, [r8] */
/* @0x113b80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113b84 str r9, [r8] */
/* @0x113b88 str r9, [r8, #0x8] */
/* @0x113b8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113b90 ldr r9, [r8, #0x4] */
/* @0x113b94 sub r9, r9, #1 */
/* @0x113b98 str r9, [r8, #0x4] */
/* @0x113b9c cmp r9, #0 */
/* @0x113ba0 beq 0x113bb4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x113ba4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113ba8 mov r0, r8 */
/* @0x113bac bl 0x27d1d0 <_ZdlPv> */
/* @0x113bb0 b 0x113b60 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x113bb4 ldr r0, [r8] */
/* @0x113bb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113bbc str r9, [r8] */
/* @0x113bc0 str r9, [r8, #0x8] */
/* @0x113bc4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113bc8 ldr r9, [r8, #0x4] */
/* @0x113bcc sub r9, r9, #1 */
/* @0x113bd0 str r9, [r8, #0x4] */
/* @0x113bd4 cmp r9, #0 */
/* @0x113bd8 beq 0x113bec <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x113bdc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113be0 mov r0, r8 */
/* @0x113be4 bl 0x27d1d0 <_ZdlPv> */
/* @0x113be8 b 0x113ba4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x113bec ldr r0, [r8] */
/* @0x113bf0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113bf4 mov r0, r8 */
/* @0x113bf8 str r9, [r8] */
/* @0x113bfc str r9, [r8, #0x8] */
/* @0x113c00 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x113c04 mov r0, r8 */
/* @0x113c08 bl 0x27d1d0 <_ZdlPv> */
/* @0x113c0c b 0x113bdc <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x264> */
/* ---- pool：1 字 = 0x00000000（choose 里的 0.0f） ---- */
/* @0x113c10 andeq r0, r0, r0 */
