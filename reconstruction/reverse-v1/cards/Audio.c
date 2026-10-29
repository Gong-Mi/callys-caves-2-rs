/* cally 逆向卡：Audio.c —— Audio_/Sound_ 子系统 8 个主要函数（原版 libyoyo.so，armv7）
 * 选法: asm/functions.tsv 里 ^Audio_ 与非 COgg*/cAudio_*/cARRAY_* 的 ^Sound_ 全部 21+16 个，
 *       按 size 取前 8（本卡不含 F_Audio*/F_Sound* 的 GML 内建体 —— 那是 Builtins_AudioPart 卡的范围）
 * 节: 8 个 @func 小节，顺序 = size 降序（不是地址序：地址序是 Load < CreateBufferSound < Quit < …）
 *   1/8 Audio_Quit                 0x21a664  1704 B  426 条
 *   2/8 Audio_Tick                 0x21bc30  1520 B  380 条
 *   3/8 Audio_CreateBufferSound    0x2198a0  1232 B  308 条
 *   4/8 Audio_GetSoundSourceToPlay 0x21addc  1216 B  304 条
 *   5/8 Audio_StartRecording       0x21c700  1016 B  254 条
 *   6/8 Audio_Load                 0x219048   908 B  227 条
 *   7/8 Audio_PlaySoundOn          0x21b8c0   880 B  220 条
 *   8/8 Audio_PlaySoundAt          0x21b29c   828 B  207 条
 *   合计 2,326 条 = 8 段互不连续的区间
 * 索引: asm/index-Audio_<name>.tsv × 8 + 合并 asm/index-Audio_all.tsv（2,326 条）
 * 级别: 骨架（§1-2 是前一批逐条写成的正文级语义；§3-8 为结构+锚点，语义待展开）
 *       被调 helper 只在「本函数依赖它」的程度上标注，未展开者列入 open）
 *
 * ══ 两道门（沿用 Builtins_AudioPart 卡，本卡独立复核）══════════════════════════════
 *   0x755314 = 后端选择 u8：0 = 旧 Sound_ 后端，非 0 = CNoise 后端。本卡 8 个函数里
 *     Audio_Quit 0x21a678 与 Audio_Tick 读它（门在函数头）；其余 6 个**不读**，
 *     它们无条件跑 CNoise/OpenAL 路径 —— 谁来拦（F_Audio* GML 层）在 Builtins_AudioPart 卡里。
 *   0x755363 = 总开关 u8：本卡 8 个函数**一个都不读**（只在 F_Audio*/F_Sound* 里出现）
 *     ⇒ 8 个 Audio_* 是被 GML 层门过滤之后的纯执行体。
 *   id 空间 *(0x75530c)：本卡 Audio_Load 0x2193a8 用它做越界检查（id < 音源数）。
 *
 * ══ 本卡新增的坐标（0x75529c 一带）══════════════════════════════════════════════
 *   0x75529c = COggAudio 单例的 this 基址（§1 第 5 条指令把它交给 COggAudio::Quit）。
 *   成员表（每对 +off = count(int) / +(off+4) = items(T**)）:
 *     +0x20/+0x24 cAudio_Sound* 数组 A   0x7552bc/0x7552c0
 *     +0x28/+0x2c cAudio_Sound* 数组 B   0x7552c4/0x7552c8
 *     +0x30/+0x34 cAudio_Sound* 数组 C   0x7552cc/0x7552d0
 *     +0x38/+0x3c CNoise* 数组           0x7552d4/0x7552d8   （既有卡记作「CNoise 池」）
 *     +0x40/+0x44 裸对象指针数组          0x7552dc/0x7552e0   （元素 +0x34/+0x38 是内层数组）
 *     +0x48/+0x4c 已分配块数组            0x7552e4/0x7552e8   （IsAllocated 后 Free）
 *   兄弟全局:
 *     0x755304/0x755308  cAudio_Sound 数组 D（不在 0x75529c 内）
 *     0x755310  SoundHardware*（Audio_Init 写）
 *     0x755314  后端选择 0x755318 自增计数器 0x75531c 源名数组 0x755324 CAudioGroupMan*
 *     0x3f52c8  源总数 int（.data，GOT 0x3f13d8）
 *   毒值 0xFEEEFEEE = 本库「已析构对象」标记（§1 里 12 次 movw/movt 拼出，命中即跳过析构）。
 *
 * ══ 与既有卡的边界 ══════════════════════════════════════════════════════════
 *   Audio_Init 0x2166bc（288 B / 72 条）不在本卡 8 节内；0x2166f8 是它内部 strb 0x755363 的站点。
 *   Audio_Model 0x216998（5 条）不在 functions.tsv（紧接 Audio_GetListenerData 末条 0x216994）。
 *   两者与 F_Audio*/F_Sound* 的语义已落 Builtins_AudioPart 卡，本卡不重复。
 */

/* ══ 1/8  Audio_Quit  0x21a664  size 1704  426 条（0x21a664..0x21ad08；末 25 字是池）
 * @func 0x21a664 0x21ad0c  size 1704  426 条
 * 符号 _Z10Audio_Quitv   无参无返回（r0 在 0x21a66c 即被 ldr 覆写）
 *
 * 骨架（按地址序 5 步）:
 *   [门] 0x21a678 GOT 0x3eed38 → 0x755314，0x21a67c ldrb，0x21a680 cmp，#0 → 0x21a684 bne 0x21a690
 *        **==0 直接 0x21a688..0x21a68c 返回**：空转路径 11 条（0x21a664..0x21a68c）
 *        ⇒ 旧 Sound_ 后端时 Audio_Quit 是空函数（与 Audio_Init 写 0x755363 的方向无关）
 *   ① Audio_StopAll(true)                    0x21a694 mov r0,#1 / 0x21a698 bl 0x21a3bc
 *   ② COggAudio::Quit(this = 0x75529c)       0x21a690+0x21a69c 取 base（池 0x21ac9c = 0x0053abf8）
 *                                            0x21a6a0 mov r0,r7 / 0x21a6a4 bl 0x225fa4
 *      ⇒ 0x75529c 是 COggAudio 单例（0x225fa4 内部读 +0x00/+0x04/+0x10/+0x14 的线程表，
 *        与本函数的 +0x20..+0x4c 数组区不重叠 —— 同一个对象的两块成员）
 *   ③ CAudioGroupMan::Finalise(*(0x755324))  0x21a6ac GOT 0x3ef058 / 0x21a6b0 bl 0x21deb0
 *   ④ 一段「源名数组」先撤 OpenAL 侧           0x21a70c..0x21a774（详见下）
 *   ⑤ 6 组数组拆解 + 1 组（0x755304）          0x21a778..0x21ac20，见下表
 *
 * 数组拆解模板（同一段代码被内联 6 次，只有析构函数与偏移不同）:
 *     count = [base+oc]; if (count <= 0) next;
 *     items = [base+oc+4]; if (!items) { Free(0); items=0; ... }
 *     for (i=0; i<count; i++) {
 *         if (items[0] == (void*)0xFEEEFEEE) continue;     ← 循环头，只在 i 判定前查一次
 *         p = items[i]; if (!p) continue;
 *         if (*(void**)p != (void*)0xFEEEFEEE) { dtor(p); operator delete(p); }
 *         items[i] = 0;                                    ← 用 [base+oc+4] 重新取 items
 *     }
 *     MemoryManager::Free(items); [base+oc+4] = 0; [base+oc] = 0;
 *   ⚠ 「items[0] 与毒值比较」是**元素指针**比较（0x21a7b8 ldr r0,[r6]），
 *      「元素 vtable 与毒值比较」是**解引用后**比较（0x21a7ec ldr r12,[r7]）：两处不同层次的检查。
 *   ⚠ 6 次里 5 次是 items[0]-检查 + vtable-检查；0x40 组（0x21a6b4..0x21a708）**没有**模板：
 *      它只把元素 +0x38 起的 +0x34 个槽位写 0，既不 dtor 也不 Free（该内层数组的所有权在别处，见 open）
 *
 *   oc / items 偏移          元素类型（析构符号）              段地址
 *   0x40 / 0x44 (0x7552dc)  裸对象：+0x34 count, +0x38 items    0x21a6b4..0x21a708（只清槽）
 *   ——— 源名数组段 ———       0x75531c：alSourcei/alDeleteSources  0x21a70c..0x21a774
 *   0x20 / 0x24 (0x7552bc)  cAudio_Sound（0x218f24）            0x21a778..0x21a850
 *   0x38 / 0x3c (0x7552d4)  CNoise（0x21db28）                   0x21a854..0x21a92c
 *   0x48 / 0x4c (0x7552e4)  裸块：IsAllocated + MemoryManager::Free（无 dtor）  0x21a930..0x21a9b0
 *   0x28 / 0x2c (0x7552c4)  cAudio_Sound（0x218f24）            0x21a9b4..0x21aa90
 *   0x30 / 0x34 (0x7552cc)  cAudio_Sound（0x218f24）            0x21aa94..0x21ab6c
 *   0x755304 / 0x755308     cAudio_Sound（0x218f24，另一个对象） 0x21ab70..0x21ac20
 *   ⇒ 拆解顺序 ≠ 偏移序（0x28/0x30 排在 0x48 之后），是源码里 6 个独立成员函数的调用顺序。
 *
 * 源名数组段（0x21a70c..0x21a774）不套模板:
 *   if (!*(0x75531c)) skip;                      0x21a714/0x21a718
 *   n = *(int*)0x3f52c8;                         0x21a728（GOT 0x3f13d8；.data 里出厂即有值的 int）
 *   for (i=0;i<n;i++) alSourcei(src[i], 0x1009, 0);   0x21a740..0x21a75c   ← 0x1009 = AL 枚举常量
 *   alDeleteSources(src); operator delete(src); *(0x75531c) = 0;
 *   ⚠ 长度用 0x3f52c8 而不是别的计数字段 ⇒ 0x3f52c8 = OpenAL 源总数（Audio_CreateSources 的产物）。
 *   ⚠ 0x1009 按 OpenAL 1.1 枚举表 = AL_SAMPLE_OFFSET（AL_LOOPING 是 0x1007）⇒ 这一句是
 *      「把源的播放偏移拉回 0」，不是关循环；枚举→语义的对应标 inferred（本卡只证常量值）。
 *
 * 收尾: 0x21ac24 add sp,#12 / 0x21ac28 pop 9 寄存器 / 0x21ac28 之后是 25 字池。
 * 池 0x21ac94..0x21ad08 全是被 objdump 译成指令的数据字（按 README 规矩保留原样）。
 */

/* @0x21a664 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21a668 sub sp, sp, #12 */
/* @0x21a66c ldr r5, [pc, #0x620] */
/* @0x21a670 ldr r3, [pc, #0x620] */
/* @0x21a674 add r5, pc, r5 —— GOT 基址 = pc + 池字 0x21ac94(0x001d75dc) */
/* @0x21a678 ldr r3, [r5, r3] —— GOT 0x3eed38 → 0x755314（后端选择字节） */
/* @0x21a67c ldrb r3, [r3] —— 读后端字节 */
/* @0x21a680 cmp r3, #0 —— == 0 则空转 */
/* @0x21a684 bne 0x21a690 <_Z10Audio_Quitv+0x2c> —— 跳过全部清理 */
/* @0x21a688 add sp, sp, #12 —— 空转出口 1/2 */
/* @0x21a68c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 空转出口 2/2 */
/* @0x21a690 ldr r7, [pc, #0x604] */
/* @0x21a694 mov r0, #1 —— Audio_StopAll(true) */
/* @0x21a698 bl 0x21a3bc <_Z13Audio_StopAllb> —— bl Audio_StopAll 0x21a3bc */
/* @0x21a69c add r7, pc, r7 —— base = 0x75529c（池 0x21ac9c = 0x0053abf8） */
/* @0x21a6a0 mov r0, r7 —— this = base */
/* @0x21a6a4 bl 0x225fa4 <_ZN9COggAudio4QuitEv> —— bl COggAudio::Quit 0x225fa4 */
/* @0x21a6a8 ldr r3, [pc, #0x5f0] */
/* @0x21a6ac ldr r0, [r5, r3] —— GOT 0x3ef058 → 0x755324（CAudioGroupMan*） */
/* @0x21a6b0 bl 0x21deb0 <_ZN14CAudioGroupMan8FinaliseEv> —— bl CAudioGroupMan::Finalise 0x21deb0 */
/* @0x21a6b4 ldr r6, [r7, #0x40] —— count = [0x75529c+0x40] = 0x7552dc */
/* @0x21a6b8 cmp r6, #0 —— count <= 0 跳过整组 */
/* @0x21a6bc movgt r4, #0 */
/* @0x21a6c0 movgt r0, r7 */
/* @0x21a6c4 movgt lr, r4 */
/* @0x21a6c8 ble 0x21a70c <_Z10Audio_Quitv+0xa8> */
/* @0x21a6cc ldr r3, [r0, #0x44] —— items = [0x75529c+0x44] = 0x7552e0 */
/* @0x21a6d0 ldr r1, [r3, r4, lsl #2] */
/* @0x21a6d4 cmp r1, #0 */
/* @0x21a6d8 beq 0x21a700 <_Z10Audio_Quitv+0x9c> */
/* @0x21a6dc ldr r12, [r1, #0x34] —— 元素 +0x34 = 内层 count */
/* @0x21a6e0 cmp r12, #0 */
/* @0x21a6e4 ble 0x21a700 <_Z10Audio_Quitv+0x9c> */
/* @0x21a6e8 mov r3, #0 —— 内层槽位清 0（不 Free） */
/* @0x21a6ec ldr r2, [r1, #0x38] —— 元素 +0x38 = 内层 items */
/* @0x21a6f0 str lr, [r2, r3, lsl #2] */
/* @0x21a6f4 add r3, r3, #1 */
/* @0x21a6f8 cmp r3, r12 */
/* @0x21a6fc bne 0x21a6ec <_Z10Audio_Quitv+0x88> */
/* @0x21a700 add r4, r4, #1 */
/* @0x21a704 cmp r4, r6 */
/* @0x21a708 bne 0x21a6cc <_Z10Audio_Quitv+0x68> */
/* @0x21a70c ldr r3, [pc, #0x590] —— GOT 0x3f13d4 → 0x75531c（源名数组指针） */
/* @0x21a710 ldr r6, [r5, r3] */
/* @0x21a714 ldr r3, [r6] */
/* @0x21a718 cmp r3, #0 —— src 非空才继续 */
/* @0x21a71c beq 0x21a778 <_Z10Audio_Quitv+0x114> */
/* @0x21a720 ldr r2, [pc, #0x580] */
/* @0x21a724 ldr r7, [r5, r2] —— GOT 0x3f13d8 → 0x3f52c8（源总数 int） */
/* @0x21a728 ldr r0, [r7] —— count = *(0x3f52c8) */
/* @0x21a72c cmp r0, #0 */
/* @0x21a730 ble 0x21ac8c <_Z10Audio_Quitv+0x628> */
/* @0x21a734 mov r4, #0 */
/* @0x21a738 b 0x21a740 <_Z10Audio_Quitv+0xdc> */
/* @0x21a73c ldr r3, [r6] */
/* @0x21a740 ldr r0, [r3, r4, lsl #2] */
/* @0x21a744 movw r1, #0x1009 —— AL_LOOPING = 0x1009 */
/* @0x21a748 mov r2, #0 */
/* @0x21a74c add r4, r4, #1 */
/* @0x21a750 bl 0xb6a6c <alSourcei@plt> —— bl alSourcei@plt 0xb6a6c */
/* @0x21a754 ldr r0, [r7] */
/* @0x21a758 cmp r0, r4 */
/* @0x21a75c bgt 0x21a73c <_Z10Audio_Quitv+0xd8> */
/* @0x21a760 ldr r1, [r6] */
/* @0x21a764 bl 0xb6b20 <alDeleteSources@plt> —— bl alDeleteSources@plt 0xb6b20 */
/* @0x21a768 ldr r0, [r6] */
/* @0x21a76c bl 0x27d1d0 <_ZdlPv> —— delete src（operator delete 0x27d1d0） */
/* @0x21a770 mov r3, #0 */
/* @0x21a774 str r3, [r6] —— *(0x75531c) = 0 */
/* @0x21a778 ldr r9, [pc, #0x52c] */
/* @0x21a77c add r9, pc, r9 —— base = 0x75529c */
/* @0x21a780 ldr r3, [r9, #0x20] —— 数组 A count = 0x7552bc */
/* @0x21a784 cmp r3, #0 */
/* @0x21a788 beq 0x21a854 <_Z10Audio_Quitv+0x1f0> */
/* @0x21a78c ldr r6, [r9, #0x24] —— A items = 0x7552c0 */
/* @0x21a790 cmp r6, #0 */
/* @0x21a794 beq 0x21ac4c <_Z10Audio_Quitv+0x5e8> */
/* @0x21a798 cmp r3, #0 */
/* @0x21a79c ble 0x21a82c <_Z10Audio_Quitv+0x1c8> */
/* @0x21a7a0 ldr r11, [pc, #0x508] */
/* @0x21a7a4 mov r4, #0 */
/* @0x21a7a8 ldr r1, [pc, #0x504] */
/* @0x21a7ac mov r10, r4 */
/* @0x21a7b0 add r11, pc, r11 */
/* @0x21a7b4 add r1, pc, r1 */
/* @0x21a7b8 ldr r0, [r6] */
/* @0x21a7bc movw r3, #0xfeee —— 毒值 0xFEEEFEEE 低半 */
/* @0x21a7c0 movt r3, #0xfeee —— 毒值 0xFEEEFEEE 高半 */
/* @0x21a7c4 movw r2, #0xfeee */
/* @0x21a7c8 cmp r0, r3 */
/* @0x21a7cc movt r2, #0xfeee */
/* @0x21a7d0 lsl r8, r4, #2 */
/* @0x21a7d4 beq 0x21a81c <_Z10Audio_Quitv+0x1b8> */
/* @0x21a7d8 ldr r7, [r6, r4, lsl #2] */
/* @0x21a7dc add r3, r6, r8 */
/* @0x21a7e0 cmp r7, #0 */
/* @0x21a7e4 mov r0, r7 */
/* @0x21a7e8 beq 0x21a81c <_Z10Audio_Quitv+0x1b8> */
/* @0x21a7ec ldr r12, [r7] —— 元素 vtable */
/* @0x21a7f0 cmp r12, r2 */
/* @0x21a7f4 beq 0x21a814 <_Z10Audio_Quitv+0x1b0> */
/* @0x21a7f8 str r1, [sp, #0x4] */
/* @0x21a7fc bl 0x218f24 <_ZN12cAudio_SoundD2Ev> —— bl cAudio_Sound::~cAudio_Sound 0x218f24 */
/* @0x21a800 mov r0, r7 */
/* @0x21a804 bl 0x27d1d0 <_ZdlPv> —— bl operator delete 0x27d1d0 */
/* @0x21a808 ldr r1, [sp, #0x4] */
/* @0x21a80c ldr r3, [r1, #0x24] */
/* @0x21a810 add r3, r3, r8 */
/* @0x21a814 str r10, [r3] */
/* @0x21a818 ldr r6, [r11, #0x24] */
/* @0x21a81c ldr r3, [r9, #0x20] */
/* @0x21a820 add r4, r4, #1 */
/* @0x21a824 cmp r4, r3 */
/* @0x21a828 blt 0x21a7b8 <_Z10Audio_Quitv+0x154> */
/* @0x21a82c mov r0, r6 */
/* @0x21a830 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— bl MemoryManager::Free 0x27c2d0（items 本体） */
/* @0x21a834 ldr r3, [pc, #0x47c] */
/* @0x21a838 mov r2, #0 */
/* @0x21a83c add r3, pc, r3 */
/* @0x21a840 str r2, [r3, #0x24] —— A items = 0 */
/* @0x21a844 ldr r3, [pc, #0x470] */
/* @0x21a848 mov r2, #0 */
/* @0x21a84c add r3, pc, r3 */
/* @0x21a850 str r2, [r3, #0x20] —— A count = 0 */
/* @0x21a854 ldr r9, [pc, #0x464] */
/* @0x21a858 add r9, pc, r9 */
/* @0x21a85c ldr r3, [r9, #0x38] —— CNoise 数组 count = 0x7552d4 */
/* @0x21a860 cmp r3, #0 */
/* @0x21a864 beq 0x21a930 <_Z10Audio_Quitv+0x2cc> */
/* @0x21a868 ldr r6, [r9, #0x3c] —— CNoise items = 0x7552d8 */
/* @0x21a86c cmp r6, #0 */
/* @0x21a870 beq 0x21ac3c <_Z10Audio_Quitv+0x5d8> */
/* @0x21a874 cmp r3, #0 */
/* @0x21a878 ble 0x21a908 <_Z10Audio_Quitv+0x2a4> */
/* @0x21a87c ldr r11, [pc, #0x440] */
/* @0x21a880 mov r4, #0 */
/* @0x21a884 ldr r1, [pc, #0x43c] */
/* @0x21a888 mov r10, r4 */
/* @0x21a88c add r11, pc, r11 */
/* @0x21a890 add r1, pc, r1 */
/* @0x21a894 ldr r0, [r6] */
/* @0x21a898 movw r3, #0xfeee */
/* @0x21a89c movt r3, #0xfeee */
/* @0x21a8a0 movw r2, #0xfeee */
/* @0x21a8a4 cmp r0, r3 */
/* @0x21a8a8 movt r2, #0xfeee */
/* @0x21a8ac lsl r8, r4, #2 */
/* @0x21a8b0 beq 0x21a8f8 <_Z10Audio_Quitv+0x294> */
/* @0x21a8b4 ldr r7, [r6, r4, lsl #2] */
/* @0x21a8b8 add r3, r6, r8 */
/* @0x21a8bc cmp r7, #0 */
/* @0x21a8c0 mov r0, r7 */
/* @0x21a8c4 beq 0x21a8f8 <_Z10Audio_Quitv+0x294> */
/* @0x21a8c8 ldr r12, [r7] */
/* @0x21a8cc cmp r12, r2 */
/* @0x21a8d0 beq 0x21a8f0 <_Z10Audio_Quitv+0x28c> */
/* @0x21a8d4 str r1, [sp, #0x4] */
/* @0x21a8d8 bl 0x21db28 <_ZN6CNoiseD2Ev> —— bl CNoise::~CNoise 0x21db28 */
/* @0x21a8dc mov r0, r7 */
/* @0x21a8e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21a8e4 ldr r1, [sp, #0x4] */
/* @0x21a8e8 ldr r3, [r1, #0x3c] */
/* @0x21a8ec add r3, r3, r8 */
/* @0x21a8f0 str r10, [r3] */
/* @0x21a8f4 ldr r6, [r11, #0x3c] */
/* @0x21a8f8 ldr r3, [r9, #0x38] */
/* @0x21a8fc add r4, r4, #1 */
/* @0x21a900 cmp r4, r3 */
/* @0x21a904 blt 0x21a894 <_Z10Audio_Quitv+0x230> */
/* @0x21a908 mov r0, r6 —— Free(CNoise items) */
/* @0x21a90c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a910 ldr r3, [pc, #0x3b4] */
/* @0x21a914 mov r2, #0 */
/* @0x21a918 add r3, pc, r3 */
/* @0x21a91c str r2, [r3, #0x3c] —— CNoise items = 0 */
/* @0x21a920 ldr r3, [pc, #0x3a8] */
/* @0x21a924 mov r2, #0 */
/* @0x21a928 add r3, pc, r3 */
/* @0x21a92c str r2, [r3, #0x38] —— CNoise count = 0 */
/* @0x21a930 ldr r6, [pc, #0x39c] */
/* @0x21a934 add r6, pc, r6 */
/* @0x21a938 ldr r7, [r6, #0x4c] —— 组 0x48 items = 0x7552e8 */
/* @0x21a93c cmp r7, #0 */
/* @0x21a940 beq 0x21ac2c <_Z10Audio_Quitv+0x5c8> */
/* @0x21a944 ldr r3, [r6, #0x48] —— 组 0x48 count = 0x7552e4 */
/* @0x21a948 cmp r3, #0 */
/* @0x21a94c ble 0x21a99c <_Z10Audio_Quitv+0x338> */
/* @0x21a950 ldr r9, [pc, #0x380] */
/* @0x21a954 mov r4, #0 */
/* @0x21a958 mov r8, r4 */
/* @0x21a95c add r9, pc, r9 */
/* @0x21a960 ldr r0, [r7, r4, lsl #2] */
/* @0x21a964 lsl r7, r4, #2 */
/* @0x21a968 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> —— bl MemoryManager::IsAllocated 0x27c454 */
/* @0x21a96c cmp r0, #0 */
/* @0x21a970 beq 0x21a980 <_Z10Audio_Quitv+0x31c> */
/* @0x21a974 ldr r3, [r9, #0x4c] */
/* @0x21a978 ldr r0, [r3, r4, lsl #2] */
/* @0x21a97c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— bl MemoryManager::Free（逐元素） */
/* @0x21a980 ldr r2, [r6, #0x48] */
/* @0x21a984 add r4, r4, #1 */
/* @0x21a988 ldr r3, [r6, #0x4c] */
/* @0x21a98c cmp r4, r2 */
/* @0x21a990 str r8, [r3, r7] —— 槽位清 0 */
/* @0x21a994 ldr r7, [r6, #0x4c] */
/* @0x21a998 blt 0x21a960 <_Z10Audio_Quitv+0x2fc> */
/* @0x21a99c mov r0, r7 */
/* @0x21a9a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— Free(items) */
/* @0x21a9a4 ldr r3, [pc, #0x330] */
/* @0x21a9a8 mov r2, #0 */
/* @0x21a9ac add r3, pc, r3 */
/* @0x21a9b0 str r2, [r3, #0x4c] —— items = 0 */
/* @0x21a9b4 ldr r9, [pc, #0x324] */
/* @0x21a9b8 mov r4, #0 */
/* @0x21a9bc add r9, pc, r9 */
/* @0x21a9c0 ldr r3, [r9, #0x28] —— 数组 B count = 0x7552c4 */
/* @0x21a9c4 str r4, [r9, #0x48] —— 顺带把 0x48 组 count(0x7552e4) 清 0 */
/* @0x21a9c8 cmp r3, r4 */
/* @0x21a9cc beq 0x21aa94 <_Z10Audio_Quitv+0x430> */
/* @0x21a9d0 ldr r6, [r9, #0x2c] —— B items = 0x7552c8 */
/* @0x21a9d4 cmp r6, r4 */
/* @0x21a9d8 beq 0x21ac7c <_Z10Audio_Quitv+0x618> */
/* @0x21a9dc cmp r3, r4 */
/* @0x21a9e0 ble 0x21aa6c <_Z10Audio_Quitv+0x408> */
/* @0x21a9e4 ldr r11, [pc, #0x2f8] */
/* @0x21a9e8 mov r10, r4 */
/* @0x21a9ec ldr r1, [pc, #0x2f4] */
/* @0x21a9f0 add r11, pc, r11 */
/* @0x21a9f4 add r1, pc, r1 */
/* @0x21a9f8 ldr r0, [r6] */
/* @0x21a9fc movw r3, #0xfeee */
/* @0x21aa00 movt r3, #0xfeee */
/* @0x21aa04 movw r2, #0xfeee */
/* @0x21aa08 cmp r0, r3 */
/* @0x21aa0c movt r2, #0xfeee */
/* @0x21aa10 lsl r8, r4, #2 */
/* @0x21aa14 beq 0x21aa5c <_Z10Audio_Quitv+0x3f8> */
/* @0x21aa18 ldr r7, [r6, r4, lsl #2] */
/* @0x21aa1c add r3, r6, r8 */
/* @0x21aa20 cmp r7, #0 */
/* @0x21aa24 mov r0, r7 */
/* @0x21aa28 beq 0x21aa5c <_Z10Audio_Quitv+0x3f8> */
/* @0x21aa2c ldr r12, [r7] */
/* @0x21aa30 cmp r12, r2 */
/* @0x21aa34 beq 0x21aa54 <_Z10Audio_Quitv+0x3f0> */
/* @0x21aa38 str r1, [sp, #0x4] */
/* @0x21aa3c bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21aa40 mov r0, r7 */
/* @0x21aa44 bl 0x27d1d0 <_ZdlPv> */
/* @0x21aa48 ldr r1, [sp, #0x4] */
/* @0x21aa4c ldr r3, [r1, #0x2c] */
/* @0x21aa50 add r3, r3, r8 */
/* @0x21aa54 str r10, [r3] */
/* @0x21aa58 ldr r6, [r11, #0x2c] */
/* @0x21aa5c ldr r3, [r9, #0x28] */
/* @0x21aa60 add r4, r4, #1 */
/* @0x21aa64 cmp r4, r3 */
/* @0x21aa68 blt 0x21a9f8 <_Z10Audio_Quitv+0x394> */
/* @0x21aa6c mov r0, r6 */
/* @0x21aa70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— Free(B items) */
/* @0x21aa74 ldr r3, [pc, #0x270] */
/* @0x21aa78 mov r2, #0 */
/* @0x21aa7c add r3, pc, r3 */
/* @0x21aa80 str r2, [r3, #0x2c] */
/* @0x21aa84 ldr r3, [pc, #0x264] */
/* @0x21aa88 mov r2, #0 */
/* @0x21aa8c add r3, pc, r3 */
/* @0x21aa90 str r2, [r3, #0x28] */
/* @0x21aa94 ldr r9, [pc, #0x258] */
/* @0x21aa98 add r9, pc, r9 */
/* @0x21aa9c ldr r3, [r9, #0x30] —— 数组 C count = 0x7552cc */
/* @0x21aaa0 cmp r3, #0 */
/* @0x21aaa4 beq 0x21ab70 <_Z10Audio_Quitv+0x50c> */
/* @0x21aaa8 ldr r6, [r9, #0x34] —— C items = 0x7552d0 */
/* @0x21aaac cmp r6, #0 */
/* @0x21aab0 beq 0x21ac6c <_Z10Audio_Quitv+0x608> */
/* @0x21aab4 cmp r3, #0 */
/* @0x21aab8 ble 0x21ab48 <_Z10Audio_Quitv+0x4e4> */
/* @0x21aabc ldr r11, [pc, #0x234] */
/* @0x21aac0 mov r4, #0 */
/* @0x21aac4 ldr r1, [pc, #0x230] */
/* @0x21aac8 mov r10, r4 */
/* @0x21aacc add r11, pc, r11 */
/* @0x21aad0 add r1, pc, r1 */
/* @0x21aad4 ldr r0, [r6] */
/* @0x21aad8 movw r3, #0xfeee */
/* @0x21aadc movt r3, #0xfeee */
/* @0x21aae0 movw r2, #0xfeee */
/* @0x21aae4 cmp r0, r3 */
/* @0x21aae8 movt r2, #0xfeee */
/* @0x21aaec lsl r8, r4, #2 */
/* @0x21aaf0 beq 0x21ab38 <_Z10Audio_Quitv+0x4d4> */
/* @0x21aaf4 ldr r7, [r6, r4, lsl #2] */
/* @0x21aaf8 add r3, r6, r8 */
/* @0x21aafc cmp r7, #0 */
/* @0x21ab00 mov r0, r7 */
/* @0x21ab04 beq 0x21ab38 <_Z10Audio_Quitv+0x4d4> */
/* @0x21ab08 ldr r12, [r7] */
/* @0x21ab0c cmp r12, r2 */
/* @0x21ab10 beq 0x21ab30 <_Z10Audio_Quitv+0x4cc> */
/* @0x21ab14 str r1, [sp, #0x4] */
/* @0x21ab18 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21ab1c mov r0, r7 */
/* @0x21ab20 bl 0x27d1d0 <_ZdlPv> */
/* @0x21ab24 ldr r1, [sp, #0x4] */
/* @0x21ab28 ldr r3, [r1, #0x34] */
/* @0x21ab2c add r3, r3, r8 */
/* @0x21ab30 str r10, [r3] */
/* @0x21ab34 ldr r6, [r11, #0x34] */
/* @0x21ab38 ldr r3, [r9, #0x30] */
/* @0x21ab3c add r4, r4, #1 */
/* @0x21ab40 cmp r4, r3 */
/* @0x21ab44 blt 0x21aad4 <_Z10Audio_Quitv+0x470> */
/* @0x21ab48 mov r0, r6 */
/* @0x21ab4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ab50 ldr r3, [pc, #0x1a8] */
/* @0x21ab54 mov r2, #0 */
/* @0x21ab58 add r3, pc, r3 */
/* @0x21ab5c str r2, [r3, #0x34] */
/* @0x21ab60 ldr r3, [pc, #0x19c] */
/* @0x21ab64 mov r2, #0 */
/* @0x21ab68 add r3, pc, r3 */
/* @0x21ab6c str r2, [r3, #0x30] */
/* @0x21ab70 ldr r3, [pc, #0x190] —— 另一对象 0x755304 */
/* @0x21ab74 ldr r7, [r5, r3] —— GOT 0x3f13e0 → 0x755304 */
/* @0x21ab78 ldr r3, [r7] —— count = *(0x755304) */
/* @0x21ab7c cmp r3, #0 */
/* @0x21ab80 beq 0x21a688 <_Z10Audio_Quitv+0x24> */
/* @0x21ab84 ldr r5, [r7, #0x4] —— items = *(0x755308) */
/* @0x21ab88 cmp r5, #0 */
/* @0x21ab8c beq 0x21ac5c <_Z10Audio_Quitv+0x5f8> */
/* @0x21ab90 cmp r3, #0 */
/* @0x21ab94 ble 0x21ac0c <_Z10Audio_Quitv+0x5a8> */
/* @0x21ab98 mov r4, #0 */
/* @0x21ab9c mov r9, r4 */
/* @0x21aba0 ldr r1, [r5] —— items[0] 与毒值比较 */
/* @0x21aba4 movw r3, #0xfeee */
/* @0x21aba8 movt r3, #0xfeee */
/* @0x21abac movw r2, #0xfeee */
/* @0x21abb0 cmp r1, r3 */
/* @0x21abb4 movt r2, #0xfeee */
/* @0x21abb8 lsl r8, r4, #2 */
/* @0x21abbc beq 0x21abfc <_Z10Audio_Quitv+0x598> */
/* @0x21abc0 ldr r6, [r5, r4, lsl #2] */
/* @0x21abc4 add r3, r5, r8 */
/* @0x21abc8 cmp r6, #0 */
/* @0x21abcc mov r0, r6 */
/* @0x21abd0 beq 0x21abfc <_Z10Audio_Quitv+0x598> */
/* @0x21abd4 ldr r1, [r6] —— 元素 vtable 与毒值比较 */
/* @0x21abd8 cmp r1, r2 */
/* @0x21abdc beq 0x21abf4 <_Z10Audio_Quitv+0x590> */
/* @0x21abe0 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21abe4 mov r0, r6 */
/* @0x21abe8 bl 0x27d1d0 <_ZdlPv> */
/* @0x21abec ldr r3, [r7, #0x4] */
/* @0x21abf0 add r3, r3, r8 */
/* @0x21abf4 str r9, [r3] */
/* @0x21abf8 ldr r5, [r7, #0x4] */
/* @0x21abfc ldr r3, [r7] */
/* @0x21ac00 add r4, r4, #1 */
/* @0x21ac04 cmp r4, r3 */
/* @0x21ac08 blt 0x21aba0 <_Z10Audio_Quitv+0x53c> */
/* @0x21ac0c mov r0, r5 */
/* @0x21ac10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> —— Free(items) */
/* @0x21ac14 mov r3, #0 */
/* @0x21ac18 str r3, [r7, #0x4] —— items = 0 */
/* @0x21ac1c mov r3, #0 */
/* @0x21ac20 str r3, [r7] —— count = 0 */
/* @0x21ac24 add sp, sp, #12 */
/* @0x21ac28 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 正常出口 */
/* @0x21ac2c mov r0, r7 */
/* @0x21ac30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac34 str r7, [r6, #0x4c] */
/* @0x21ac38 b 0x21a9b4 <_Z10Audio_Quitv+0x350> */
/* @0x21ac3c mov r0, r6 */
/* @0x21ac40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac44 str r6, [r9, #0x3c] */
/* @0x21ac48 b 0x21a920 <_Z10Audio_Quitv+0x2bc> */
/* @0x21ac4c mov r0, r6 */
/* @0x21ac50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac54 str r6, [r9, #0x24] */
/* @0x21ac58 b 0x21a844 <_Z10Audio_Quitv+0x1e0> */
/* @0x21ac5c mov r0, r5 */
/* @0x21ac60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac64 str r5, [r7, #0x4] */
/* @0x21ac68 b 0x21ac1c <_Z10Audio_Quitv+0x5b8> */
/* @0x21ac6c mov r0, r6 */
/* @0x21ac70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac74 str r6, [r9, #0x34] */
/* @0x21ac78 b 0x21ab60 <_Z10Audio_Quitv+0x4fc> */
/* @0x21ac7c mov r0, r6 */
/* @0x21ac80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac84 str r6, [r9, #0x2c] */
/* @0x21ac88 b 0x21aa84 <_Z10Audio_Quitv+0x420> */
/* @0x21ac8c mov r1, r3 */
/* @0x21ac90 b 0x21a764 <_Z10Audio_Quitv+0x100> */
/* ---- pool：25 字（0x21ac94..0x21ad08，非指令；GOT 相对偏移与 pc 相对偏移） ---- */
/* @0x21ac94 ldrsbeq r7, [sp], -r12 */
/* @0x21ac98 .word 0xffffd0e0 */
/* @0x21ac9c ldrsheq r10, [r3], #-184 */
/* @0x21aca0 .word 0xffffd400 */
/* @0x21aca4 .word 0xfffff77c */
/* @0x21aca8 .word 0xfffff780 */
/* @0x21acac subseq r10, r3, r8, lsl r11 */
/* @0x21acb0 subseq r10, r3, r4, ror #21 */
/* @0x21acb4 subseq r10, r3, r0, ror #21 */
/* @0x21acb8 subseq r10, r3, r8, asr r10 */
/* @0x21acbc subseq r10, r3, r8, asr #20 */
/* @0x21acc0 subseq r10, r3, r12, lsr r10 */
/* @0x21acc4 subseq r10, r3, r8, lsl #20 */
/* @0x21acc8 subseq r10, r3, r4, lsl #20 */
/* @0x21accc subseq r10, r3, r12, ror r9 */
/* @0x21acd0 subseq r10, r3, r12, ror #18 */
/* @0x21acd4 subseq r10, r3, r0, ror #18 */
/* @0x21acd8 subseq r10, r3, r8, lsr r9 */
/* @0x21acdc subseq r10, r3, r8, ror #17 */
/* @0x21ace0 ldrsbeq r10, [r3], #-136 */
/* @0x21ace4 subseq r10, r3, r4, lsr #17 */
/* @0x21ace8 subseq r10, r3, r0, lsr #17 */
/* @0x21acec subseq r10, r3, r8, lsl r8 */
/* @0x21acf0 subseq r10, r3, r8, lsl #16 */
/* @0x21acf4 ldrsheq r10, [r3], #-124 */
/* @0x21acf8 subseq r10, r3, r8, asr #15 */
/* @0x21acfc subseq r10, r3, r4, asr #15 */
/* @0x21ad00 subseq r10, r3, r12, lsr r7 */
/* @0x21ad04 subseq r10, r3, r12, lsr #14 */
/* @0x21ad08 .word 0xfffff788 */

/* ══ 2/8  Audio_Tick  0x21bc30  size 1520  380 条（0x21bc30..0x21c21c；末 23 字是池）
 * @func 0x21bc30 0x21c220  size 1520  380 条
 * 符号 _Z10Audio_Tickv  无参无返回
 *
 * 两道门（本卡唯一同时读两道门的 Audio_* 函数，且两道门方向相反）:
 *   ① 0x21bc48 GOT 0x3eed38 → 0x755314 ; 0x21bc4c ldrb ; 0x21bc50 cmp ; 0x21bc54 beq 空转
 *   ② 0x21bc5c GOT 0x3f13f4 → 0x75530c ; 0x21bc60 ldrb ; 0x21bc64 cmp ; 0x21bc68 beq 0x21bc78
 *   ⇒ if (!*(u8*)0x755314) return;  if (*(u8*)0x75530c) return;
 *   ⚠ 0x75530c 在这里是**字节**（ldrb）。全 .text 里池字 0xfffff79c（= GOT 槽 0x3f13f4 相对
 *      GOT 基址 0x3f1c58 的偏移）只出现在 Audio_Tick 与 SoundHardware::Tick 0x221134，
 *      而后者同样是 ldrb + bne 返回（0x221150/0x221154/0x22115c）。⇒ 该字节读作「关闭/暂停」标志。
 *      既有卡把它记成「音源数 int / id 空间分界 0x75530c」——本卡的槽解析不支持那个读法（见 open 1）。
 *   空转出口 = 0x21bc6c..0x21bc74（3 条 + 前 4 条 = 7 条）
 *
 * 主体 10 段（按地址序）:
 *   ① 0x21bc78 CAudioGroupMan::Update(*(0x755324))              → bl 0x21e268
 *   ② 0x21bc84 CListener::Update(*(0x755320))  空指针跳过        → bl 0x215b48
 *   ③ 0x21bc9c checkAL("Audio_Tick Start")  0x3541c0            → bl 0x215fd0
 *   ④ 0x21bcb4 COggAudio::Tick(&(0x75529c+0x38))                → bl 0x226590
 *      0x21bcbc add r1, r0, #56 ⇒ **参数就是 CNoise 数组头 0x7552d4**（cARRAY_CLASS<CNoise*>*）
 *   ⑤ 0x21bcbc GLM 三族 cAudio_Sound 数组的增益斜坡推进（见下）
 *   ⑥ 0x21bd58 CNoise 数组逐条推进 + AL_GAIN 回写
 *   ⑦ 0x21be78 0x40 组的「宿主对象 → 源 位置/速度」同步（3D 音源）
 *   ⑧ 0x21bfe4 录音设备采样泵（alcGetIntegerv / alcCaptureSamples / 异步事件 73）
 *   ⑨ 0x21c140 音乐队列去队（id = 200000 + i）
 *   ⑩ 0x21c198 checkAL("Audio_Tick End") + 5 条返回
 *
 * ⑤ 三族数组（A/B/C = 0x7552bc / 0x7552c4 / 0x7552cc）:
 *   0x21bcd4 r3 = 0x3f52b8（.data 里三个 4 字节指针，实测 = {0x7552bc, 0x7552c4, 0x7552cc}）
 *   0x21bcd8 ldm r3,{r0,r1,r2} / 0x21bce0 stmdb → 拷到 sp+64 起，0x21bd50 cmp r12,lr 走满 3 次
 *   每族 a: count = a[0]; items = a[1]（间隔 4 字节，即 count/items 相邻）
 *   for each s in items: if (s && (n = s[+0x20]) > 0) {
 *        g = s[+0x04] + s[+0x1c];                    // 0x21bd14/0x21bd18/0x21bd1c
 *        if (g < 0) s[+0x04] = 0; else s[+0x04] = min(g, 1.0f);   // 0x21bd28 / 0x21bd38（1.0f 在 0x21bcc4）
 *        s[+0x20] = n - 1; }
 *   ⇒ 三族声音对象的形状相同：+0x04 当前增益(float) / +0x1c 每 tick 增量(float) / +0x20 剩余步数(int)
 *
 * ⑥ CNoise 数组（0x7552d4 count / 0x7552d8 items）逐条:
 *   n = items[i]; if (!n || !n[+0x05]) continue;                 // 0x21bdcc +0x05 = 已启动字节
 *   if (n[+0x08] != 0) {                                          // 0x21bdd8 +0x08 = 停止计数（int）
 *        k = ++n[+0x08]; if (k > 3) n[+0x08] = 0; else if (k == 3) Audio_StopSoundNoise(n, 1);
 *        continue; }                                              // 0x21bd94..0x21bda8 / 0x21c1b0
 *   if ((c = n[+0x2c]) > 0) { g = n[+0x24]+n[+0x28]; 负则 0、否则 min(g,1.0f); n[+0x2c] = c-1; }
 *   if (n[+0x10] < 0) continue;                                   // 0x21be24 +0x10 = AL 源下标
 *   gain = n[+0x24] * Audio_GetGainFromSoundID(n[+0x18]) * (n[+0x38] ? *(float*)(n[+0x38]+40) : 1.0f);
 *   alSourcef(src[n[+0x10]], 0x100a, gain);                        // 0x21be70
 *   ⚠ 停止计数 3 的路径**不**归零（只有 >3 才归零），所以是「到 3 立刻 Stop 并把计数留在 3」；
 *      >3 分支在正常流里到不了（3 已被 beq 截走），除非外部写 [+0x08] ≥ 4。
 *   ⚠ +0x38 是**对象指针**（0x21be3c 读、0x21be48 vldrne s14,[r3,#40] 取 +0x28 的 float）⇒ 与 ⑦ 的宿主同型。
 *
 * ⑦ 0x40 组（0x7552dc count / 0x7552e0 items）：元素 = 宿主对象
 *    字段: +0x00/+0x04/+0x08 位置(float×3)，+0x0c/+0x10/+0x14 速度(float×3)，
 *          +0x18 字节 enabled，+0x34 count，+0x38 items（CNoise*）
 *   for each obj: if (!obj || !obj[+0x18] || (k = obj[+0x34]) <= 0) continue;
 *     for i<k: n = obj[+0x38][i]; if (!n) continue;
 *       if (Audio_NoiseIsPlaying(n) == 0) { n[+0x05]=0; n[+0x08]=0; n[+0x0d]=0; n[+0x38]=0; obj[+0x38][i]=0; }
 *       else { alSource3f(src[n[+0x10]], 0x1004, obj[0],obj[4],obj[8]);
 *              alSource3f(src[n[+0x10]], 0x1006, obj[0xc],obj[0x10],obj[0x14]);
 *              if (alGetError()) 虚调用 [*(*(0x3eb70c))+0xc](); }
 *   ⇒ 这是「跟着对象走的 3D 音源」：每 tick 把宿主位姿灌进 OpenAL，播完就摘出数组并清标志。
 *   0x3eb70c 是 .data.rel.ro 里的接口指针，出厂 = 0x47a118（.bss 里的对象），虚表 +0xc。
 *
 * ⑧ 录音（0x7552ec count / 0x7552f0 items）: 元素 = 录音设备
 *    +0x00 int 采样率，+0x0c 字节 active，+0x10 ALCdevice*
 *   for each d: if (!d || !d[+0x0c]) continue;
 *     n = -1; alcGetIntegerv(d[+0x10], 0x312 /*ALC_CAPTURE_SAMPLES*/, 1, &n);   // 0x21c054/0x21c068
 *     if ((float)n / (float)d[0] <= 0.1f) continue;      // 0.1f = 池 0x21c1c0 的 0x3dcccccd
 *     b = CreateBuffer(2*n, 3, 0); ib = GetIBuffer(b);   // 0x21c098/0x21c09c/0x21c0a4
 *     alcCaptureSamples(d[+0x10], ib[+0x0c], n);         // 0x21c0bc
 *     ib[+0x20] = min(2*n, ib[+0x10]);                   // 0x21c0ec/0x21c0f0
 *     ds = CreateDsMap(3, ...); CreateAsynEventWithDSMapAndBuffer(73, b, ds);   // 0x21c124/0x21c130
 *   三个 .rodata 名: 0x353fcc "buffer_id" / 0x3541d4 "channel_index" / 0x3541e4 "data_len"
 *   传参落位（r0 = 3；r1 = "buffer_id"；[sp+4] = "channel_index"；[sp+0x14] = "data_len"；
 *     [sp]/[sp+0x10]/[sp+0x20] = 0；[sp+8] = (double)设备下标；[sp+0x18] = (double)(2n)；r2:r3 = 另一个 double）
 *   ⇒ 三对的「名 ↔ 值」配对无法从变参落位唯一确定，列入 open。
 *
 * ⑨ 音乐队列: 数组 C（0x7552cc count / 0x7552d0 items），id = 200000 + i（0x21c160/0x21c164）
 *   if (items[i]) { n = Audio_GetNoiseFromQueuedSoundID(id); Audio_Unqueue_Processed_Buffers(n, id, false); }
 *   ⇒ **独立证实音乐 id 段从 200000 起**，且 C 的下标 i ↔ id = 200000+i 一一对应。
 *
 * 池 0x21c1c0..0x21c218：23 字，全部是被 objdump 译成指令的数据（0x21c1c0 = 0x3dcccccd = 0.1f）。
 */

/* @0x21bc30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21bc34 vpush {d8} */
/* @0x21bc38 sub sp, sp, #84 */
/* @0x21bc3c ldr r9, [pc, #0x580] */
/* @0x21bc40 ldr r3, [pc, #0x580] */
/* @0x21bc44 add r9, pc, r9 —— GOT 基址 0x3f1c58 */
/* @0x21bc48 ldr r3, [r9, r3] —— GOT 0x3eed38 → 0x755314（门①后端选择） */
/* @0x21bc4c ldrb r3, [r3] —— ldrb */
/* @0x21bc50 cmp r3, #0 */
/* @0x21bc54 beq 0x21bc6c <_Z10Audio_Tickv+0x3c> —— == 0 → 空转 */
/* @0x21bc58 ldr r3, [pc, #0x56c] */
/* @0x21bc5c ldr r3, [r9, r3] —— GOT 0x3f13f4 → 0x75530c（门②） */
/* @0x21bc60 ldrb r3, [r3] —— ldrb（字节，不是 int） */
/* @0x21bc64 cmp r3, #0 */
/* @0x21bc68 beq 0x21bc78 <_Z10Audio_Tickv+0x48> —— 非 0 → 空转（与门①方向相反） */
/* @0x21bc6c add sp, sp, #84 —— 空转出口 3 条 */
/* @0x21bc70 vpop {d8} */
/* @0x21bc74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21bc78 ldr r3, [pc, #0x550] */
/* @0x21bc7c ldr r0, [r9, r3] —— GOT 0x3ef058 → 0x755324 */
/* @0x21bc80 bl 0x21e268 <_ZN14CAudioGroupMan6UpdateEv> —— bl CAudioGroupMan::Update 0x21e268 */
/* @0x21bc84 ldr r3, [pc, #0x548] */
/* @0x21bc88 ldr r3, [r9, r3] —— GOT 0x3f13e4 → 0x755320（CListener*） */
/* @0x21bc8c ldr r0, [r3] */
/* @0x21bc90 cmp r0, #0 —— 空则跳过 */
/* @0x21bc94 beq 0x21bc9c <_Z10Audio_Tickv+0x6c> */
/* @0x21bc98 bl 0x215b48 <_ZN9CListener6UpdateEv> —— bl CListener::Update 0x215b48 */
/* @0x21bc9c ldr r0, [pc, #0x534] */
/* @0x21bca0 add r2, sp, #64 —— 0x3541c0 "Audio_Tick Start" */
/* @0x21bca4 str r2, [sp, #0x3c] */
/* @0x21bca8 mov r4, #0 */
/* @0x21bcac add r0, pc, r0 */
/* @0x21bcb0 bl 0x215fd0 <_Z7checkALPKc> —— bl checkAL 0x215fd0 */
/* @0x21bcb4 ldr r0, [pc, #0x520] —— base = 0x75529c */
/* @0x21bcb8 add r0, pc, r0 ——  */
/* @0x21bcbc add r1, r0, #56 —— r1 = base+0x38 = CNoise 数组头 0x7552d4 */
/* @0x21bcc0 bl 0x226590 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE> —— bl COggAudio::Tick 0x226590（参数 = &CNoise 数组） */
/* @0x21bcc4 vmov.f32 s13, #1.000000e+00 —— 1.0f 上界 */
/* @0x21bcc8 ldr r3, [pc, #0x510] */
/* @0x21bccc add r12, sp, #64 */
/* @0x21bcd0 add lr, sp, #76 */
/* @0x21bcd4 add r3, pc, r3 —— 0x3f52b8（.data 三个指针 = 0x7552bc/0x7552c4/0x7552cc） */
/* @0x21bcd8 ldm r3, {r0, r1, r2} —— ldm 三个族头 */
/* @0x21bcdc add r3, sp, #80 */
/* @0x21bce0 stmdb r3, {r0, r1, r2} —— 存到 sp+64 起的临时数组 */
/* @0x21bce4 ldr r3, [r12, #0x4]! —— 三族循环：取族头 */
/* @0x21bce8 ldr r0, [r3] —— count */
/* @0x21bcec cmp r0, #0 */
/* @0x21bcf0 ble 0x21bd50 <_Z10Audio_Tickv+0x120> */
/* @0x21bcf4 ldr r1, [r3, #0x4] —— items */
/* @0x21bcf8 add r0, r1, r0, lsl #2 */
/* @0x21bcfc ldr r3, [r1], #4 */
/* @0x21bd00 cmp r3, #0 */
/* @0x21bd04 beq 0x21bd48 <_Z10Audio_Tickv+0x118> */
/* @0x21bd08 ldr r2, [r3, #0x20] —— s+0x20 剩余步数 */
/* @0x21bd0c cmp r2, #0 */
/* @0x21bd10 ble 0x21bd48 <_Z10Audio_Tickv+0x118> */
/* @0x21bd14 vldr s14, [r3, #4] —— s+0x04 当前增益 */
/* @0x21bd18 vldr s15, [r3, #28] —— s+0x1c 每 tick 增量 */
/* @0x21bd1c vadd.f32 s15, s14, s15 */
/* @0x21bd20 vcmpe.f32 s15, #0 */
/* @0x21bd24 vmrs APSR_nzcv, fpscr */
/* @0x21bd28 strmi r4, [r3, #0x4] —— 负则归零 */
/* @0x21bd2c bmi 0x21bd40 <_Z10Audio_Tickv+0x110> */
/* @0x21bd30 vcmpe.f32 s15, s13 */
/* @0x21bd34 vmrs APSR_nzcv, fpscr */
/* @0x21bd38 vmovgt.f32 s15, s13 —— 上界 1.0f */
/* @0x21bd3c vstr s15, [r3, #4] */
/* @0x21bd40 sub r2, r2, #1 —— 步数 -1 */
/* @0x21bd44 str r2, [r3, #0x20] */
/* @0x21bd48 cmp r1, r0 */
/* @0x21bd4c bne 0x21bcfc <_Z10Audio_Tickv+0xcc> */
/* @0x21bd50 cmp r12, lr */
/* @0x21bd54 bne 0x21bce4 <_Z10Audio_Tickv+0xb4> */
/* @0x21bd58 ldr r3, [pc, #0x484] —— CNoise 数组 */
/* @0x21bd5c add r3, pc, r3 */
/* @0x21bd60 ldr r6, [r3, #0x38] —— count = 0x7552d4 */
/* @0x21bd64 cmp r6, #0 */
/* @0x21bd68 ble 0x21be78 <_Z10Audio_Tickv+0x248> */
/* @0x21bd6c ldr r8, [pc, #0x474] —— base */
/* @0x21bd70 mov r4, #0 */
/* @0x21bd74 ldr r7, [pc, #0x470] */
/* @0x21bd78 vmov.f32 s16, #1.000000e+00 */
/* @0x21bd7c add r8, pc, r8 */
/* @0x21bd80 mov r10, r4 */
/* @0x21bd84 add r7, pc, r7 */
/* @0x21bd88 mov r3, r6 */
/* @0x21bd8c mov r11, #0 */
/* @0x21bd90 b 0x21bdbc <_Z10Audio_Tickv+0x18c> */
/* @0x21bd94 add r3, r3, #1 */
/* @0x21bd98 str r3, [r5, #0x8] */
/* @0x21bd9c cmp r3, #3 */
/* @0x21bda0 strgt r10, [r5, #0x8] */
/* @0x21bda4 bgt 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21bda8 beq 0x21c1b0 <_Z10Audio_Tickv+0x580> */
/* @0x21bdac add r4, r4, #1 */
/* @0x21bdb0 cmp r4, r6 */
/* @0x21bdb4 beq 0x21be78 <_Z10Audio_Tickv+0x248> */
/* @0x21bdb8 ldr r3, [r7, #0x38] */
/* @0x21bdbc cmp r3, r4 —— 逐条 CNoise */
/* @0x21bdc0 ldrgt r3, [r8, #0x3c] */
/* @0x21bdc4 movle r5, #0 */
/* @0x21bdc8 ldrgt r5, [r3, r4, lsl #2] —— n = items[i] */
/* @0x21bdcc ldrb r3, [r5, #0x5] —— n+0x05 启动标志 */
/* @0x21bdd0 cmp r3, #0 */
/* @0x21bdd4 beq 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21bdd8 ldr r3, [r5, #0x8] —— n+0x08 停止计数 */
/* @0x21bddc cmp r3, #0 */
/* @0x21bde0 bne 0x21bd94 <_Z10Audio_Tickv+0x164> */
/* @0x21bde4 ldr r3, [r5, #0x2c] —— n+0x2c 剩余步数 */
/* @0x21bde8 cmp r3, #0 */
/* @0x21bdec ble 0x21be24 <_Z10Audio_Tickv+0x1f4> */
/* @0x21bdf0 vldr s14, [r5, #36] —— n+0x24 当前增益 */
/* @0x21bdf4 vldr s15, [r5, #40] —— n+0x28 增量 */
/* @0x21bdf8 vadd.f32 s15, s14, s15 */
/* @0x21bdfc vcmpe.f32 s15, #0 */
/* @0x21be00 vmrs APSR_nzcv, fpscr */
/* @0x21be04 strmi r11, [r5, #0x24] */
/* @0x21be08 bmi 0x21be1c <_Z10Audio_Tickv+0x1ec> */
/* @0x21be0c vcmpe.f32 s15, s16 */
/* @0x21be10 vmrs APSR_nzcv, fpscr */
/* @0x21be14 vmovgt.f32 s15, s16 */
/* @0x21be18 vstr s15, [r5, #36] */
/* @0x21be1c sub r3, r3, #1 */
/* @0x21be20 str r3, [r5, #0x2c] */
/* @0x21be24 ldr r3, [r5, #0x10] */
/* @0x21be28 cmp r3, #0 */
/* @0x21be2c blt 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21be30 ldr r0, [r5, #0x18] —— n+0x18 sound id → 增益 */
/* @0x21be34 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi> —— bl Audio_GetGainFromSoundID 0x217060 */
/* @0x21be38 vldr s15, [r5, #36] */
/* @0x21be3c ldr r3, [r5, #0x38] —— n+0x38（挂载对象指针） */
/* @0x21be40 movw r1, #0x100a */
/* @0x21be44 cmp r3, #0 */
/* @0x21be48 vldrne s14, [r3, #40] */
/* @0x21be4c ldr r3, [pc, #0x39c] —— GOT 0x3f13d4 → 0x75531c（源数组） */
/* @0x21be50 ldr r3, [r9, r3] */
/* @0x21be54 ldr r3, [r3] */
/* @0x21be58 vmov s11, r0 */
/* @0x21be5c ldr r0, [r5, #0x10] */
/* @0x21be60 vmul.f32 s15, s11, s15 —— gain = 衰减 × 增益 */
/* @0x21be64 ldr r0, [r3, r0, lsl #2] */
/* @0x21be68 vmulne.f32 s15, s15, s14 —— 再乘对象增益 [+0x28] */
/* @0x21be6c vmov r2, s15 */
/* @0x21be70 bl 0xb6a78 <alSourcef@plt> —— bl alSourcef(AL_GAIN 0x100a) */
/* @0x21be74 b 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21be78 ldr r3, [pc, #0x374] */
/* @0x21be7c add r3, pc, r3 */
/* @0x21be80 ldr r10, [r3, #0x40] —— 0x40 组 count = 0x7552dc */
/* @0x21be84 cmp r10, #0 */
/* @0x21be88 ble 0x21bfe4 <_Z10Audio_Tickv+0x3b4> */
/* @0x21be8c ldr r2, [pc, #0x364] */
/* @0x21be90 mov r3, r10 */
/* @0x21be94 ldr lr, [pc, #0x360] */
/* @0x21be98 mov r7, #0 */
/* @0x21be9c add r2, pc, r2 */
/* @0x21bea0 str r2, [sp, #0x34] */
/* @0x21bea4 ldr r2, [pc, #0x354] */
/* @0x21bea8 add lr, pc, lr */
/* @0x21beac str lr, [sp, #0x38] */
/* @0x21beb0 add r2, pc, r2 */
/* @0x21beb4 str r2, [sp, #0x30] */
/* @0x21beb8 cmp r7, r3 */
/* @0x21bebc bge 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bec0 ldr lr, [sp, #0x34] */
/* @0x21bec4 ldr r3, [lr, #0x44] —— items = 0x7552e0 */
/* @0x21bec8 ldr r6, [r3, r7, lsl #2] */
/* @0x21becc cmp r6, #0 */
/* @0x21bed0 beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bed4 ldrb r3, [r6, #0x18] —— obj+0x18 enabled */
/* @0x21bed8 cmp r3, #0 */
/* @0x21bedc beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bee0 ldr r8, [r6, #0x34] —— obj+0x34 内层 count */
/* @0x21bee4 cmp r8, #0 */
/* @0x21bee8 ble 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21beec mov r3, r8 */
/* @0x21bef0 mov r4, #0 */
/* @0x21bef4 b 0x21bf20 <_Z10Audio_Tickv+0x2f0> */
/* @0x21bef8 ldr r3, [r6, #0x38] —— obj+0x38 内层 items */
/* @0x21befc strb r0, [r5, #0x5] —— n+0x05 = 0 */
/* @0x21bf00 str r0, [r5, #0x8] —— n+0x08 = 0 */
/* @0x21bf04 strb r0, [r5, #0xd] —— n+0x0d = 0 */
/* @0x21bf08 str r0, [r5, #0x38] —— n+0x38 = 0 */
/* @0x21bf0c str r0, [r3, r11] —— 槽位清 0（摘出数组） */
/* @0x21bf10 add r4, r4, #1 */
/* @0x21bf14 cmp r4, r8 */
/* @0x21bf18 beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bf1c ldr r3, [r6, #0x34] */
/* @0x21bf20 cmp r3, r4 */
/* @0x21bf24 lsl r11, r4, #2 */
/* @0x21bf28 ble 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bf2c ldr r3, [r6, #0x38] */
/* @0x21bf30 ldr r5, [r3, r4, lsl #2] */
/* @0x21bf34 cmp r5, #0 */
/* @0x21bf38 mov r0, r5 */
/* @0x21bf3c beq 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bf40 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> —— bl Audio_NoiseIsPlaying 0x2164bc */
/* @0x21bf44 cmp r0, #0 */
/* @0x21bf48 beq 0x21bef8 <_Z10Audio_Tickv+0x2c8> —— 0 = 已停 → 清标志并摘除 */
/* @0x21bf4c ldr r1, [pc, #0x29c] */
/* @0x21bf50 ldr r12, [r5, #0x10] */
/* @0x21bf54 ldr lr, [r6, #0x8] */
/* @0x21bf58 ldr r11, [r9, r1] */
/* @0x21bf5c movw r1, #0x1004 —— AL_POSITION = 0x1004 */
/* @0x21bf60 ldr r2, [r6] */
/* @0x21bf64 ldr r3, [r6, #0x4] */
/* @0x21bf68 ldr r0, [r11] */
/* @0x21bf6c ldr r0, [r0, r12, lsl #2] */
/* @0x21bf70 str lr, [sp] */
/* @0x21bf74 bl 0xb6b2c <alSource3f@plt> —— bl alSource3f（位置） */
/* @0x21bf78 ldr r1, [r11] */
/* @0x21bf7c ldr r0, [r5, #0x10] */
/* @0x21bf80 ldr r12, [r6, #0x14] */
/* @0x21bf84 ldr r2, [r6, #0xc] */
/* @0x21bf88 ldr r0, [r1, r0, lsl #2] */
/* @0x21bf8c movw r1, #0x1006 —— AL_VELOCITY = 0x1006 */
/* @0x21bf90 ldr r3, [r6, #0x10] */
/* @0x21bf94 str r12, [sp] */
/* @0x21bf98 bl 0xb6b2c <alSource3f@plt> —— bl alSource3f（速度） */
/* @0x21bf9c bl 0xb6a54 <alGetError@plt> —— bl alGetError */
/* @0x21bfa0 subs r2, r0, #0 */
/* @0x21bfa4 beq 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bfa8 ldr r3, [pc, #0x254] */
/* @0x21bfac add r4, r4, #1 */
/* @0x21bfb0 ldr r1, [sp, #0x38] */
/* @0x21bfb4 ldr r3, [r9, r3] —— GOT 0x3ed71c → 0x3eb70c（.data.rel.ro 的接口指针） */
/* @0x21bfb8 ldr r0, [r3] */
/* @0x21bfbc ldr r3, [r0] */
/* @0x21bfc0 ldr r3, [r3, #0xc] */
/* @0x21bfc4 blx r3 —— 虚调用 [vtable+0xc]（错误上报） */
/* @0x21bfc8 cmp r4, r8 */
/* @0x21bfcc bne 0x21bf1c <_Z10Audio_Tickv+0x2ec> */
/* @0x21bfd0 add r7, r7, #1 */
/* @0x21bfd4 cmp r7, r10 */
/* @0x21bfd8 ldrne r2, [sp, #0x30] */
/* @0x21bfdc ldrne r3, [r2, #0x40] */
/* @0x21bfe0 bne 0x21beb8 <_Z10Audio_Tickv+0x288> */
/* @0x21bfe4 ldr r10, [pc, #0x21c] —— 录音设备数组 */
/* @0x21bfe8 add r10, pc, r10 */
/* @0x21bfec ldr r3, [r10, #0x50] —— count = 0x7552ec */
/* @0x21bff0 cmp r3, #0 */
/* @0x21bff4 ble 0x21c140 <_Z10Audio_Tickv+0x510> */
/* @0x21bff8 ldr r9, [pc, #0x20c] */
/* @0x21bffc mov r6, r10 */
/* @0x21c000 ldr r8, [pc, #0x208] */
/* @0x21c004 mov r4, #0 */
/* @0x21c008 ldr r7, [pc, #0x204] */
/* @0x21c00c add r9, pc, r9 —— 0x353fcc "buffer_id" */
/* @0x21c010 add r8, pc, r8 —— 0x3541d4 "channel_index" */
/* @0x21c014 vldr s16, [pc, #420] —— 0.1f 门槛（池 0x21c1c0） */
/* @0x21c018 add r7, pc, r7 —— 0x3541e4 "data_len" */
/* @0x21c01c add r11, sp, #64 */
/* @0x21c020 b 0x21c034 <_Z10Audio_Tickv+0x404> */
/* @0x21c024 ldr r2, [r6, #0x50] */
/* @0x21c028 add r4, r4, #1 */
/* @0x21c02c cmp r2, r4 */
/* @0x21c030 ble 0x21c140 <_Z10Audio_Tickv+0x510> */
/* @0x21c034 ldr r3, [r10, #0x54] —— items = 0x7552f0 */
/* @0x21c038 ldr r5, [r3, r4, lsl #2] */
/* @0x21c03c cmp r5, #0 */
/* @0x21c040 beq 0x21c024 <_Z10Audio_Tickv+0x3f4> */
/* @0x21c044 ldrb r3, [r5, #0xc] —— dev+0x0c active */
/* @0x21c048 cmp r3, #0 */
/* @0x21c04c beq 0x21c024 <_Z10Audio_Tickv+0x3f4> */
/* @0x21c050 ldr r0, [r5, #0x10] —— dev+0x10 ALCdevice* */
/* @0x21c054 movw r1, #0x312 —— ALC_CAPTURE_SAMPLES = 0x312 */
/* @0x21c058 mov r2, #1 */
/* @0x21c05c mov r3, r11 */
/* @0x21c060 mvn r12, #0 */
/* @0x21c064 str r12, [sp, #0x40] —— 初值 -1 */
/* @0x21c068 bl 0xb6b38 <alcGetIntegerv@plt> —— bl alcGetIntegerv */
/* @0x21c06c ldr r0, [sp, #0x40] */
/* @0x21c070 vldr s12, [r5] —— dev+0x00 采样率 */
/* @0x21c074 vcvt.f32.s32 s15, s12 */
/* @0x21c078 vmov s11, r0 */
/* @0x21c07c vcvt.f32.s32 s14, s11 */
/* @0x21c080 vdiv.f32 s15, s14, s15 */
/* @0x21c084 vcmpe.f32 s15, s16 */
/* @0x21c088 vmrs APSR_nzcv, fpscr */
/* @0x21c08c ble 0x21c024 <_Z10Audio_Tickv+0x3f4> —— n/rate <= 0.1f → 跳过 */
/* @0x21c090 mov r1, #3 */
/* @0x21c094 mov r2, #0 */
/* @0x21c098 lsl r0, r0, #1 —— 2n */
/* @0x21c09c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> —— bl CreateBuffer(2n, 3, 0) 0xc6ad0 */
/* @0x21c0a0 vmov s17, r0 */
/* @0x21c0a4 bl 0xc6720 <_Z10GetIBufferi> —— bl GetIBuffer 0xc6720 */
/* @0x21c0a8 ldr r2, [sp, #0x40] */
/* @0x21c0ac mov r3, r0 */
/* @0x21c0b0 ldr r1, [r0, #0xc] */
/* @0x21c0b4 ldr r0, [r5, #0x10] */
/* @0x21c0b8 str r3, [sp, #0x2c] */
/* @0x21c0bc bl 0xb6b44 <alcCaptureSamples@plt> —— bl alcCaptureSamples */
/* @0x21c0c0 ldr lr, [sp, #0x40] */
/* @0x21c0c4 mov r2, #0 */
/* @0x21c0c8 ldr r3, [sp, #0x2c] */
/* @0x21c0cc mov r0, #3 */
/* @0x21c0d0 vmov s11, lr */
/* @0x21c0d4 lsl r12, lr, #1 */
/* @0x21c0d8 ldr r1, [r3, #0x10] */
/* @0x21c0dc vcvt.f64.s32 d7, s11 */
/* @0x21c0e0 vmov s11, r4 */
/* @0x21c0e4 add r4, r4, #1 */
/* @0x21c0e8 cmp r12, r1 */
/* @0x21c0ec strle r12, [r3, #0x20] —— 长度 = min(2n, IBuffer+0x10) */
/* @0x21c0f0 strgt r1, [r3, #0x20] */
/* @0x21c0f4 mov r1, r9 */
/* @0x21c0f8 str r2, [sp] */
/* @0x21c0fc str r2, [sp, #0x10] */
/* @0x21c100 str r2, [sp, #0x20] */
/* @0x21c104 str r8, [sp, #0x4] */
/* @0x21c108 vcvt.f64.s32 d6, s11 */
/* @0x21c10c str r7, [sp, #0x14] */
/* @0x21c110 vadd.f64 d7, d7, d7 */
/* @0x21c114 vstr d6, [sp, #8] */
/* @0x21c118 vcvt.f64.s32 d6, s17 */
/* @0x21c11c vstr d7, [sp, #24] */
/* @0x21c120 vmov r2, r3, d6 */
/* @0x21c124 bl 0x20bdc0 <_Z11CreateDsMapiz> —— bl CreateDsMap(3, ...) 0x20bdc0 */
/* @0x21c128 mov r2, #73 —— 异步事件 73 */
/* @0x21c12c vmov r1, s17 */
/* @0x21c130 bl 0x18da80 <_Z33CreateAsynEventWithDSMapAndBufferiii> —— bl CreateAsynEventWithDSMapAndBuffer 0x18da80 */
/* @0x21c134 ldr r2, [r6, #0x50] */
/* @0x21c138 cmp r2, r4 */
/* @0x21c13c bgt 0x21c034 <_Z10Audio_Tickv+0x404> */
/* @0x21c140 ldr r6, [pc, #0xd0] —— 音乐数组 C */
/* @0x21c144 add r6, pc, r6 */
/* @0x21c148 ldr r3, [r6, #0x30] —— count = 0x7552cc */
/* @0x21c14c cmp r3, #0 */
/* @0x21c150 movgt r4, #0 */
/* @0x21c154 movgt r7, r6 */
/* @0x21c158 ble 0x21c198 <_Z10Audio_Tickv+0x568> */
/* @0x21c15c ldr r3, [r6, #0x34] —— items = 0x7552d0 */
/* @0x21c160 add r5, r4, #199680 —— id = 200000 + i（199680+320） */
/* @0x21c164 add r5, r5, #320 */
/* @0x21c168 ldr r3, [r3, r4, lsl #2] */
/* @0x21c16c mov r0, r5 */
/* @0x21c170 add r4, r4, #1 */
/* @0x21c174 cmp r3, #0 */
/* @0x21c178 beq 0x21c18c <_Z10Audio_Tickv+0x55c> */
/* @0x21c17c bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi> —— bl Audio_GetNoiseFromQueuedSoundID 0x216560 */
/* @0x21c180 mov r1, r5 */
/* @0x21c184 mov r2, #0 */
/* @0x21c188 bl 0x219e68 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib> —— bl Audio_Unqueue_Processed_Buffers 0x219e68 */
/* @0x21c18c ldr r3, [r7, #0x30] */
/* @0x21c190 cmp r3, r4 */
/* @0x21c194 bgt 0x21c15c <_Z10Audio_Tickv+0x52c> */
/* @0x21c198 ldr r0, [pc, #0x7c] —— 0x3541f0 "Audio_Tick End" */
/* @0x21c19c add r0, pc, r0 */
/* @0x21c1a0 bl 0x215fd0 <_Z7checkALPKc> —— bl checkAL */
/* @0x21c1a4 add sp, sp, #84 */
/* @0x21c1a8 vpop {d8} */
/* @0x21c1ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c1b0 mov r0, r5 */
/* @0x21c1b4 mov r1, #1 */
/* @0x21c1b8 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> —— bl Audio_StopSoundNoise(n, 1) 0x21a0b0 */
/* @0x21c1bc b 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* ---- pool：23 字（0x21c1c0..0x21c218，非指令；0x21c1c0 = 0x3dcccccd = 0.1f 是唯一的浮点常量） ---- */
/* @0x21c1c0 stcllo p12, c12, [r12, #820] */
/* @0x21c1c4 andseq r6, sp, r12 */
/* @0x21c1c8 .word 0xffffd0e0 */
/* @0x21c1cc .word 0xfffff79c */
/* @0x21c1d0 .word 0xffffd400 */
/* @0x21c1d4 .word 0xfffff78c */
/* @0x21c1d8 andseq r8, r3, r12, lsl #10 */
/* @0x21c1dc ldrsbeq r9, [r3], #-92 */
/* @0x21c1e0 ldrsbeq r9, [sp], -r12 */
/* @0x21c1e4 subseq r9, r3, r8, lsr r5 */
/* @0x21c1e8 subseq r9, r3, r8, lsl r5 */
/* @0x21c1ec subseq r9, r3, r0, lsl r5 */
/* @0x21c1f0 .word 0xfffff77c */
/* @0x21c1f4 subseq r9, r3, r8, lsl r4 */
/* @0x21c1f8 ldrsheq r9, [r3], #-56 */
/* @0x21c1fc andseq r7, r3, r12, ror #26 */
/* @0x21c200 subseq r9, r3, r4, ror #7 */
/* @0x21c204 .word 0xffffbac4 */
/* @0x21c208 subseq r9, r3, r12, lsr #5 */
/* @0x21c20c ldrheq r7, [r3], -r8 */
/* @0x21c210 ldrheq r8, [r3], -r12 */
/* @0x21c214 andseq r8, r3, r4, asr #3 */
/* @0x21c218 subseq r9, r3, r0, asr r1 */
/* @0x21c21c andseq r8, r3, r12, asr #32 */

/* ══ 3/8  Audio_CreateBufferSound  0x2198a0  size 1232  308 条（0x2198a0..0x219d70）
 * @func 0x2198a0 0x219d70  size 1232  308 条
 * 符号 _Z24Audio_CreateBufferSoundiiiiii (int,int,int,int,int,int)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x219bec→0x3eb70c, 0x219c38→0x3eb70c, 0x219c64→0x3eb70c
 * 结构: 不读门字节；三处 checkAL 校验 + 两处 Error_Show 失败出口，构造两个 cAudio_Sound 并取 IBuffer
 * 调用序列（地址序，去重计数）: checkAL(char const*)×3 / operator new(unsigned int)×2 / cAudio_Sound::cAudio_Sound()×2 / MemoryManager::Free(void const*)×2 / 0xb6afc×2 / Error_Show(char const*, bool)×2 / GetIBuffer(int) / Audio_CreateBufferSound(int, int, int, int, int, int)+0x34c
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x2c×12 / 0xc×8 / 0x28×8 / 0x8×8 / 0x10×5 / 0x18×4 / 0x34×4 / 0x20×3
 * VFP 指令 13 条（浮点/三维坐标路径）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x2198a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2198a4 cmp r1, #4 */
/* @0x2198a8 cmpne r1, #1 */
/* @0x2198ac sub sp, sp, #60 */
/* @0x2198b0 ldr r4, [pc, #0x46c] */
/* @0x2198b4 mov r9, r1 */
/* @0x2198b8 mov r5, r2 */
/* @0x2198bc add r4, pc, r4 */
/* @0x2198c0 mov r10, r3 */
/* @0x2198c4 str r0, [sp, #0xc] */
/* @0x2198c8 ldr r7, [sp, #0x60] */
/* @0x2198cc bne 0x219b98 <_Z23Audio_CreateBufferSoundiiiiii+0x2f8> */
/* @0x2198d0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x2198d4 subs r6, r0, #0 */
/* @0x2198d8 beq 0x219c60 <_Z23Audio_CreateBufferSoundiiiiii+0x3c0> */
/* @0x2198dc ldr r8, [r6, #0x20] */
/* @0x2198e0 cmp r8, #0 */
/* @0x2198e4 beq 0x219c34 <_Z23Audio_CreateBufferSoundiiiiii+0x394> */
/* @0x2198e8 cmp r5, #1000 */
/* @0x2198ec movlt r5, #1000 */
/* @0x2198f0 bge 0x219b5c <_Z23Audio_CreateBufferSoundiiiiii+0x2bc> */
/* @0x2198f4 ldr r1, [sp, #0x64] */
/* @0x2198f8 cmp r1, #2 */
/* @0x2198fc bhi 0x219c1c <_Z23Audio_CreateBufferSoundiiiiii+0x37c> */
/* @0x219900 bic r10, r10, r10, asr #31 */
/* @0x219904 add r3, r10, r7 */
/* @0x219908 cmp r8, r3 */
/* @0x21990c blt 0x219bec <_Z23Audio_CreateBufferSoundiiiiii+0x34c> */
/* @0x219910 ldr r3, [pc, #0x410] */
/* @0x219914 cmp r7, #0 */
/* @0x219918 rsbeq r7, r10, r8 */
/* @0x21991c add r3, pc, r3 */
/* @0x219920 ldr r0, [r3, #0x28] */
/* @0x219924 cmp r0, #0 */
/* @0x219928 ble 0x219960 <_Z23Audio_CreateBufferSoundiiiiii+0xc0> */
/* @0x21992c ldr r2, [r3, #0x2c] */
/* @0x219930 ldr r12, [r2] */
/* @0x219934 cmp r12, #0 */
/* @0x219938 movne r3, #0 */
/* @0x21993c bne 0x219950 <_Z23Audio_CreateBufferSoundiiiiii+0xb0> */
/* @0x219940 b 0x219c74 <_Z23Audio_CreateBufferSoundiiiiii+0x3d4> */
/* @0x219944 ldr r1, [r2, #0x4]! */
/* @0x219948 cmp r1, #0 */
/* @0x21994c beq 0x219cb0 <_Z23Audio_CreateBufferSoundiiiiii+0x410> */
/* @0x219950 add r3, r3, #1 */
/* @0x219954 cmp r3, r0 */
/* @0x219958 lsl r12, r3, #2 */
/* @0x21995c bne 0x219944 <_Z23Audio_CreateBufferSoundiiiiii+0xa4> */
/* @0x219960 mov r0, #96 */
/* @0x219964 ldr r11, [pc, #0x3c0] */
/* @0x219968 bl 0x27c524 <_Znwj> */
/* @0x21996c add r11, pc, r11 */
/* @0x219970 mov r4, r0 */
/* @0x219974 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219978 ldr r12, [r11, #0x28] */
/* @0x21997c adds r2, r12, #16 */
/* @0x219980 str r2, [sp, #0x10] */
/* @0x219984 bne 0x219bb0 <_Z23Audio_CreateBufferSoundiiiiii+0x310> */
/* @0x219988 ldr r3, [r11, #0x2c] */
/* @0x21998c cmp r3, #0 */
/* @0x219990 beq 0x219b70 <_Z23Audio_CreateBufferSoundiiiiii+0x2d0> */
/* @0x219994 cmp r12, #0 */
/* @0x219998 ble 0x219a64 <_Z23Audio_CreateBufferSoundiiiiii+0x1c4> */
/* @0x21999c ldr r1, [pc, #0x38c] */
/* @0x2199a0 ldr r2, [pc, #0x38c] */
/* @0x2199a4 add r1, pc, r1 */
/* @0x2199a8 str r1, [sp, #0x14] */
/* @0x2199ac add r2, pc, r2 */
/* @0x2199b0 mov r1, r11 */
/* @0x2199b4 str r6, [sp, #0x20] */
/* @0x2199b8 ldr r11, [sp, #0x10] */
/* @0x2199bc ldr r6, [sp, #0x14] */
/* @0x2199c0 str r10, [sp, #0x1c] */
/* @0x2199c4 mov r10, r2 */
/* @0x2199c8 str r5, [sp, #0x28] */
/* @0x2199cc mov r5, r1 */
/* @0x2199d0 str r4, [sp, #0x18] */
/* @0x2199d4 str r12, [sp, #0x24] */
/* @0x2199d8 str r7, [sp, #0x2c] */
/* @0x2199dc ldr r0, [r3] */
/* @0x2199e0 movw r1, #0xfeee */
/* @0x2199e4 movt r1, #0xfeee */
/* @0x2199e8 movw r2, #0xfeee */
/* @0x2199ec cmp r0, r1 */
/* @0x2199f0 movt r2, #0xfeee */
/* @0x2199f4 lsl r7, r11, #2 */
/* @0x2199f8 beq 0x219a3c <_Z23Audio_CreateBufferSoundiiiiii+0x19c> */
/* @0x2199fc ldr r4, [r3, r11, lsl #2] */
/* @0x219a00 add lr, r3, r7 */
/* @0x219a04 cmp r4, #0 */
/* @0x219a08 mov r0, r4 */
/* @0x219a0c beq 0x219a3c <_Z23Audio_CreateBufferSoundiiiiii+0x19c> */
/* @0x219a10 ldr r3, [r4] */
/* @0x219a14 cmp r3, r2 */
/* @0x219a18 beq 0x219a30 <_Z23Audio_CreateBufferSoundiiiiii+0x190> */
/* @0x219a1c bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x219a20 mov r0, r4 */
/* @0x219a24 bl 0x27d1d0 <_ZdlPv> */
/* @0x219a28 ldr lr, [r10, #0x2c] */
/* @0x219a2c add lr, lr, r7 */
/* @0x219a30 mov r2, #0 */
/* @0x219a34 str r2, [lr] */
/* @0x219a38 ldr r3, [r6, #0x2c] */
/* @0x219a3c ldr r2, [r5, #0x28] */
/* @0x219a40 add r11, r11, #1 */
/* @0x219a44 cmp r11, r2 */
/* @0x219a48 blt 0x2199dc <_Z23Audio_CreateBufferSoundiiiiii+0x13c> */
/* @0x219a4c ldr r4, [sp, #0x18] */
/* @0x219a50 ldr r10, [sp, #0x1c] */
/* @0x219a54 ldr r6, [sp, #0x20] */
/* @0x219a58 ldr r12, [sp, #0x24] */
/* @0x219a5c ldr r5, [sp, #0x28] */
/* @0x219a60 ldr r7, [sp, #0x2c] */
/* @0x219a64 mov r0, r3 */
/* @0x219a68 str r12, [sp, #0x8] */
/* @0x219a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219a70 ldr r1, [pc, #0x2c0] */
/* @0x219a74 ldr r12, [sp, #0x8] */
/* @0x219a78 mov r2, #0 */
/* @0x219a7c add r1, pc, r1 */
/* @0x219a80 mov r3, r2 */
/* @0x219a84 str r2, [r1, #0x2c] */
/* @0x219a88 ldr r2, [pc, #0x2ac] */
/* @0x219a8c add r11, r12, #99328 */
/* @0x219a90 ldr r1, [sp, #0x10] */
/* @0x219a94 add r11, r11, #672 */
/* @0x219a98 add r2, pc, r2 */
/* @0x219a9c str r1, [r2, #0x28] */
/* @0x219aa0 str r4, [r3, r12, lsl #2] */
/* @0x219aa4 add r1, sp, #56 */
/* @0x219aa8 mov r3, #0 */
/* @0x219aac mov r0, #1 */
/* @0x219ab0 str r3, [r1, #-0x4]! */
/* @0x219ab4 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x219ab8 ldr r0, [pc, #0x280] */
/* @0x219abc add r0, pc, r0 */
/* @0x219ac0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219ac4 cmp r9, #1 */
/* @0x219ac8 beq 0x219d0c <_Z23Audio_CreateBufferSoundiiiiii+0x46c> */
/* @0x219acc ldr r1, [sp, #0x64] */
/* @0x219ad0 cmp r1, #1 */
/* @0x219ad4 movwne r9, #0x1101 */
/* @0x219ad8 beq 0x219cbc <_Z23Audio_CreateBufferSoundiiiiii+0x41c> */
/* @0x219adc ldr r2, [r6, #0xc] */
/* @0x219ae0 mov r3, r7 */
/* @0x219ae4 ldr r0, [sp, #0x34] */
/* @0x219ae8 mov r1, r9 */
/* @0x219aec add r2, r2, r10 */
/* @0x219af0 str r5, [sp] */
/* @0x219af4 bl 0xb6afc <alBufferData@plt> */
/* @0x219af8 ldr r0, [pc, #0x244] */
/* @0x219afc add r0, pc, r0 */
/* @0x219b00 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219b04 vmov s13, r8 */
/* @0x219b08 movw r2, #0x1101 */
/* @0x219b0c cmp r9, r2 */
/* @0x219b10 vcvt.f32.s32 s14, s13 */
/* @0x219b14 ldr r3, [sp, #0x34] */
/* @0x219b18 vmov s13, r5 */
/* @0x219b1c mov r2, #1 */
/* @0x219b20 str r2, [r4, #0x3c] */
/* @0x219b24 str r3, [r4, #0x18] */
/* @0x219b28 vcvt.f32.s32 s15, s13 */
/* @0x219b2c vdiv.f32 s15, s14, s15 */
/* @0x219b30 vmoveq.f32 s14, #5.000000e-01 */
/* @0x219b34 vmuleq.f32 s15, s15, s14 */
/* @0x219b38 ldr r1, [sp, #0xc] */
/* @0x219b3c mov r0, r11 */
/* @0x219b40 vstr s15, [r4, #52] */
/* @0x219b44 str r1, [r4, #0x10] */
/* @0x219b48 ldr r3, [r6, #0x28] */
/* @0x219b4c add r3, r3, #1 */
/* @0x219b50 str r3, [r6, #0x28] */
/* @0x219b54 add sp, sp, #60 */
/* @0x219b58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x219b5c movw r3, #0xbb80 */
/* @0x219b60 cmp r5, r3 */
/* @0x219b64 movge r5, r3 */
/* @0x219b68 b 0x2198f4 <_Z23Audio_CreateBufferSoundiiiiii+0x54> */
/* @0x219b6c ldr r3, [r11, #0x2c] */
/* @0x219b70 mov r0, r3 */
/* @0x219b74 str r12, [sp, #0x8] */
/* @0x219b78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219b7c ldr r1, [pc, #0x1c4] */
/* @0x219b80 mov r2, #0 */
/* @0x219b84 ldr r12, [sp, #0x8] */
/* @0x219b88 add r1, pc, r1 */
/* @0x219b8c mov r3, r2 */
/* @0x219b90 str r2, [r1, #0x2c] */
/* @0x219b94 b 0x219a88 <_Z23Audio_CreateBufferSoundiiiiii+0x1e8> */
/* @0x219b98 ldr r0, [pc, #0x1ac] */
/* @0x219b9c mov r1, #0 */
/* @0x219ba0 add r0, pc, r0 */
/* @0x219ba4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x219ba8 mvn r0, #0 */
/* @0x219bac b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219bb0 ldr r3, [sp, #0x10] */
/* @0x219bb4 lsls r1, r3, #2 */
/* @0x219bb8 beq 0x219b6c <_Z23Audio_CreateBufferSoundiiiiii+0x2cc> */
/* @0x219bbc ldr r2, [pc, #0x18c] */
/* @0x219bc0 mov r3, #0 */
/* @0x219bc4 ldr r0, [r11, #0x2c] */
/* @0x219bc8 add r2, pc, r2 */
/* @0x219bcc str r3, [sp] */
/* @0x219bd0 mov r3, #135 */
/* @0x219bd4 str r12, [sp, #0x8] */
/* @0x219bd8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x219bdc ldr r12, [sp, #0x8] */
/* @0x219be0 mov r3, r0 */
/* @0x219be4 str r0, [r11, #0x2c] */
/* @0x219be8 b 0x219a88 <_Z23Audio_CreateBufferSoundiiiiii+0x1e8> */
/* @0x219bec ldr r0, [pc, #0x160] */
/* @0x219bf0 mov r2, r10 */
/* @0x219bf4 ldr r1, [pc, #0x15c] */
/* @0x219bf8 mov r3, r7 */
/* @0x219bfc ldr r0, [r4, r0] */
/* @0x219c00 add r1, pc, r1 */
/* @0x219c04 ldr r0, [r0] */
/* @0x219c08 ldr r12, [r0] */
/* @0x219c0c ldr r12, [r12, #0xc] */
/* @0x219c10 blx r12 */
/* @0x219c14 mvn r0, #0 */
/* @0x219c18 b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c1c ldr r0, [pc, #0x138] */
/* @0x219c20 mov r1, #0 */
/* @0x219c24 add r0, pc, r0 */
/* @0x219c28 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x219c2c mvn r0, #0 */
/* @0x219c30 b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c34 ldr r1, [pc, #0x124] */
/* @0x219c38 ldr r3, [pc, #0x114] */
/* @0x219c3c ldr r2, [sp, #0xc] */
/* @0x219c40 add r1, pc, r1 */
/* @0x219c44 ldr r3, [r4, r3] */
/* @0x219c48 ldr r0, [r3] */
/* @0x219c4c ldr r3, [r0] */
/* @0x219c50 ldr r3, [r3, #0xc] */
/* @0x219c54 blx r3 */
/* @0x219c58 mvn r0, #0 */
/* @0x219c5c b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c60 ldr r1, [pc, #0xfc] */
/* @0x219c64 ldr r3, [pc, #0xe8] */
/* @0x219c68 ldr r2, [sp, #0xc] */
/* @0x219c6c add r1, pc, r1 */
/* @0x219c70 b 0x219c44 <_Z23Audio_CreateBufferSoundiiiiii+0x3a4> */
/* @0x219c74 movw r11, #0x86a0 */
/* @0x219c78 movt r11, #0x1 */
/* @0x219c7c mov r0, #96 */
/* @0x219c80 str r12, [sp, #0x8] */
/* @0x219c84 bl 0x27c524 <_Znwj> */
/* @0x219c88 mov r4, r0 */
/* @0x219c8c bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219c90 ldr r3, [pc, #0xd0] */
/* @0x219c94 cmp r4, #0 */
/* @0x219c98 ldr r12, [sp, #0x8] */
/* @0x219c9c add r3, pc, r3 */
/* @0x219ca0 ldr r3, [r3, #0x2c] */
/* @0x219ca4 str r4, [r3, r12] */
/* @0x219ca8 bne 0x219aa4 <_Z23Audio_CreateBufferSoundiiiiii+0x204> */
/* @0x219cac b 0x219960 <_Z23Audio_CreateBufferSoundiiiiii+0xc0> */
/* @0x219cb0 add r3, r3, #99328 */
/* @0x219cb4 add r11, r3, #672 */
/* @0x219cb8 b 0x219c7c <_Z23Audio_CreateBufferSoundiiiiii+0x3dc> */
/* @0x219cbc movw r1, #0x1103 */
/* @0x219cc0 ldr r2, [r6, #0xc] */
/* @0x219cc4 mov r3, r7 */
/* @0x219cc8 ldr r0, [sp, #0x34] */
/* @0x219ccc add r2, r2, r10 */
/* @0x219cd0 str r5, [sp] */
/* @0x219cd4 bl 0xb6afc <alBufferData@plt> */
/* @0x219cd8 ldr r0, [pc, #0x8c] */
/* @0x219cdc add r0, pc, r0 */
/* @0x219ce0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219ce4 vmov s13, r8 */
/* @0x219ce8 ldr r3, [sp, #0x34] */
/* @0x219cec mov r2, #2 */
/* @0x219cf0 vcvt.f32.s32 s14, s13 */
/* @0x219cf4 str r2, [r4, #0x3c] */
/* @0x219cf8 vmov s13, r5 */
/* @0x219cfc str r3, [r4, #0x18] */
/* @0x219d00 vcvt.f32.s32 s15, s13 */
/* @0x219d04 vdiv.f32 s15, s14, s15 */
/* @0x219d08 b 0x219b38 <_Z23Audio_CreateBufferSoundiiiiii+0x298> */
/* @0x219d0c ldr r2, [sp, #0x64] */
/* @0x219d10 cmp r2, #1 */
/* @0x219d14 movne r9, #4352 */
/* @0x219d18 bne 0x219adc <_Z23Audio_CreateBufferSoundiiiiii+0x23c> */
/* @0x219d1c movw r1, #0x1102 */
/* @0x219d20 b 0x219cc0 <_Z23Audio_CreateBufferSoundiiiiii+0x420> */
/* @0x219d24 mulseq sp, r4, r3 */
/* @0x219d28 subseq r11, r3, r8, ror r9 */
/* @0x219d2c subseq r11, r3, r8, lsr #18 */
/* @0x219d30 ldrsheq r11, [r3], #-128 */
/* @0x219d34 subseq r11, r3, r8, ror #17 */
/* @0x219d38 subseq r11, r3, r8, lsl r8 */
/* @0x219d3c ldrsheq r11, [r3], #-124 */
/* @0x219d40 andseq r10, r3, r4, asr #9 */
/* @0x219d44 andseq r10, r3, r0, lsr #9 */
/* @0x219d48 subseq r11, r3, r12, lsl #14 */
/* @0x219d4c andseq r10, r3, r8, ror #4 */
/* @0x219d50 andseq r3, r3, r8, lsr #14 */
/* @0x219d54 .word 0xffffbac4 */
/* @0x219d58 andseq r10, r3, r0, lsr #6 */
/* @0x219d5c andseq r10, r3, r8, lsr #5 */
/* @0x219d60 andseq r10, r3, r8, asr #4 */
/* @0x219d64 andseq r10, r3, r8, ror #3 */
/* @0x219d68 ldrsheq r11, [r3], #-88 */
/* @0x219d6c andseq r10, r3, r0, asr #5 */
/* ══ 4/8  Audio_GetSoundSourceToPlay  0x21addc  size 1216  304 条（0x21addc..0x21b29c）
 * @func 0x21addc 0x21b2b0  size 1236  309 条
 * 符号 _Z26Audio_GetSoundSourceToPlayif (int sound, float)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21adf0→0x755363, 0x21aee4→0x75531c, 0x21af34→0x3f52c4, 0x21afc8→0x75531c, 0x21b008→0x3f52c4
 * 结构: 读 0x755363（总开关）、0x75531c（OpenAL 源名数组指针）、0x3f52c4（int 全局）
 * 调用序列（地址序，去重计数）: 0xb6a9c×2 / Audio_GetSoundSourceToPlay(int, float)+0x2b0×2 / MemoryManager::Free(void const*)×2 / Audio_GetSound(int) / Audio_GetSoundSourceToPlay(int, float)+0x22c / Audio_GetSoundSourceToPlay(int, float)+0x94 / Audio_StopSoundNoise(CNoise*, bool) / Audio_SetNoiseInactive(CNoise*)
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x3c×11 / 0xc×9 / 0x38×8 / 0x10×4 / 0x8×3 / 0x1c×3 / 0x2×3 / 0x1a8×2
 * VFP 指令 13 条（浮点/三维坐标路径）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x21addc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21ade0 vpush {d8} */
/* @0x21ade4 mov r5, r0 */
/* @0x21ade8 ldr r11, [pc, #0x46c] */
/* @0x21adec sub sp, sp, #36 */
/* @0x21adf0 ldr r3, [pc, #0x468] */
/* @0x21adf4 vmov s16, r1 */
/* @0x21adf8 add r11, pc, r11 */
/* @0x21adfc ldr r3, [r11, r3] */
/* @0x21ae00 ldrb r3, [r3] */
/* @0x21ae04 cmp r3, #0 */
/* @0x21ae08 bne 0x21b01c <_Z26Audio_GetSoundSourceToPlayif+0x240> */
/* @0x21ae0c ldr r3, [pc, #0x450] */
/* @0x21ae10 add r3, pc, r3 */
/* @0x21ae14 ldr r4, [r3, #0x38] */
/* @0x21ae18 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21ae1c ldrb r3, [r0, #0x24] */
/* @0x21ae20 cmp r3, #0 */
/* @0x21ae24 ldrbeq r3, [r0, #0x25] */
/* @0x21ae28 movne r3, #1 */
/* @0x21ae2c str r3, [sp, #0xc] */
/* @0x21ae30 ldrb r3, [r0, #0x5c] */
/* @0x21ae34 cmp r3, #0 */
/* @0x21ae38 bne 0x21b030 <_Z26Audio_GetSoundSourceToPlayif+0x254> */
/* @0x21ae3c cmp r4, #0 */
/* @0x21ae40 ble 0x21b008 <_Z26Audio_GetSoundSourceToPlayif+0x22c> */
/* @0x21ae44 ldr r7, [pc, #0x41c] */
/* @0x21ae48 mov r3, r11 */
/* @0x21ae4c mov r6, #0 */
/* @0x21ae50 movw r10, #0x869f */
/* @0x21ae54 mov r11, r4 */
/* @0x21ae58 add r7, pc, r7 */
/* @0x21ae5c add r8, sp, #28 */
/* @0x21ae60 movt r10, #0x1 */
/* @0x21ae64 mov r5, r6 */
/* @0x21ae68 mov r4, r3 */
/* @0x21ae6c b 0x21aebc <_Z26Audio_GetSoundSourceToPlayif+0xe0> */
/* @0x21ae70 ldrb r3, [r9, #0x5] */
/* @0x21ae74 cmp r3, #0 */
/* @0x21ae78 beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21ae7c ldrb r3, [r9, #0xc] */
/* @0x21ae80 cmp r3, #0 */
/* @0x21ae84 beq 0x21afc8 <_Z26Audio_GetSoundSourceToPlayif+0x1ec> */
/* @0x21ae88 ldrb r3, [r9, #0xd] */
/* @0x21ae8c cmp r3, #0 */
/* @0x21ae90 beq 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21ae94 ldr r3, [sp, #0xc] */
/* @0x21ae98 cmp r3, #0 */
/* @0x21ae9c beq 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21aea0 ldr r2, [r9, #0x8] */
/* @0x21aea4 cmp r2, #0 */
/* @0x21aea8 beq 0x21b214 <_Z26Audio_GetSoundSourceToPlayif+0x438> */
/* @0x21aeac add r5, r5, #1 */
/* @0x21aeb0 add r6, r6, #4 */
/* @0x21aeb4 cmp r5, r11 */
/* @0x21aeb8 beq 0x21af28 <_Z26Audio_GetSoundSourceToPlayif+0x14c> */
/* @0x21aebc ldr r3, [r7, #0x38] */
/* @0x21aec0 cmp r3, r5 */
/* @0x21aec4 ldrgt r3, [r7, #0x3c] */
/* @0x21aec8 movle r9, #0 */
/* @0x21aecc ldrgt r9, [r3, r6] */
/* @0x21aed0 ldr r3, [r9, #0x18] */
/* @0x21aed4 sub r3, r3, #199680 */
/* @0x21aed8 sub r3, r3, #320 */
/* @0x21aedc cmp r3, r10 */
/* @0x21aee0 bhi 0x21ae70 <_Z26Audio_GetSoundSourceToPlayif+0x94> */
/* @0x21aee4 ldr r3, [pc, #0x380] */
/* @0x21aee8 mvn r2, #0 */
/* @0x21aeec str r2, [sp, #0x1c] */
/* @0x21aef0 movw r1, #0x1015 */
/* @0x21aef4 ldr r0, [r9, #0x10] */
/* @0x21aef8 mov r2, r8 */
/* @0x21aefc ldr r3, [r4, r3] */
/* @0x21af00 ldr r3, [r3] */
/* @0x21af04 ldr r0, [r3, r0, lsl #2] */
/* @0x21af08 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21af0c ldr r3, [sp, #0x1c] */
/* @0x21af10 cmp r3, #0 */
/* @0x21af14 ble 0x21ae70 <_Z26Audio_GetSoundSourceToPlayif+0x94> */
/* @0x21af18 add r5, r5, #1 */
/* @0x21af1c add r6, r6, #4 */
/* @0x21af20 cmp r5, r11 */
/* @0x21af24 bne 0x21aebc <_Z26Audio_GetSoundSourceToPlayif+0xe0> */
/* @0x21af28 mov r3, r4 */
/* @0x21af2c mov r4, r11 */
/* @0x21af30 mov r11, r3 */
/* @0x21af34 ldr r3, [pc, #0x334] */
/* @0x21af38 ldr r3, [r11, r3] */
/* @0x21af3c ldr r3, [r3] */
/* @0x21af40 cmp r4, r3 */
/* @0x21af44 blt 0x21b08c <_Z26Audio_GetSoundSourceToPlayif+0x2b0> */
/* @0x21af48 ldr r3, [pc, #0x324] */
/* @0x21af4c ldr r2, [sp, #0xc] */
/* @0x21af50 add r3, pc, r3 */
/* @0x21af54 cmp r2, #0 */
/* @0x21af58 ldr r1, [r3, #0x38] */
/* @0x21af5c ldr r0, [r3, #0x3c] */
/* @0x21af60 bne 0x21b054 <_Z26Audio_GetSoundSourceToPlayif+0x278> */
/* @0x21af64 mov r10, r2 */
/* @0x21af68 mov r9, r2 */
/* @0x21af6c cmp r10, r1 */
/* @0x21af70 mov r3, #0 */
/* @0x21af74 ldrlt r3, [r0, r10, lsl #2] */
/* @0x21af78 vldr s15, [r3, #28] */
/* @0x21af7c vcmpe.f32 s15, s16 */
/* @0x21af80 add r10, r10, #1 */
/* @0x21af84 vmrs APSR_nzcv, fpscr */
/* @0x21af88 bpl 0x21af9c <_Z26Audio_GetSoundSourceToPlayif+0x1c0> */
/* @0x21af8c ldrb r2, [r3, #0xc] */
/* @0x21af90 cmp r2, #0 */
/* @0x21af94 vmoveq.f32 s16, s15 */
/* @0x21af98 moveq r9, r3 */
/* @0x21af9c cmp r10, r4 */
/* @0x21afa0 bne 0x21af6c <_Z26Audio_GetSoundSourceToPlayif+0x190> */
/* @0x21afa4 cmp r9, #0 */
/* @0x21afa8 beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21afac mov r0, r9 */
/* @0x21afb0 mov r1, #1 */
/* @0x21afb4 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21afb8 mov r0, r9 */
/* @0x21afbc add sp, sp, #36 */
/* @0x21afc0 vpop {d8} */
/* @0x21afc4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21afc8 ldr r3, [pc, #0x29c] */
/* @0x21afcc movw r1, #0x1010 */
/* @0x21afd0 mov r2, r8 */
/* @0x21afd4 ldr r3, [r4, r3] */
/* @0x21afd8 ldr r3, [r3] */
/* @0x21afdc ldr r0, [r3, r6] */
/* @0x21afe0 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21afe4 ldr r3, [sp, #0x1c] */
/* @0x21afe8 movw r2, #0x1014 */
/* @0x21afec movw r1, #0x1011 */
/* @0x21aff0 cmp r3, r2 */
/* @0x21aff4 cmpne r3, r1 */
/* @0x21aff8 bne 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21affc mov r0, r9 */
/* @0x21b000 bl 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise> */
/* @0x21b004 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b008 ldr r3, [pc, #0x260] */
/* @0x21b00c ldr r3, [r11, r3] */
/* @0x21b010 ldr r3, [r3] */
/* @0x21b014 cmp r4, r3 */
/* @0x21b018 blt 0x21b08c <_Z26Audio_GetSoundSourceToPlayif+0x2b0> */
/* @0x21b01c mov r9, #0 */
/* @0x21b020 mov r0, r9 */
/* @0x21b024 add sp, sp, #36 */
/* @0x21b028 vpop {d8} */
/* @0x21b02c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21b030 mov r0, r5 */
/* @0x21b034 bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi> */
/* @0x21b038 cmp r0, #0 */
/* @0x21b03c movne r9, r0 */
/* @0x21b040 beq 0x21ae3c <_Z26Audio_GetSoundSourceToPlayif+0x60> */
/* @0x21b044 mov r0, r9 */
/* @0x21b048 add sp, sp, #36 */
/* @0x21b04c vpop {d8} */
/* @0x21b050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21b054 mov r3, #0 */
/* @0x21b058 mov r9, r3 */
/* @0x21b05c cmp r3, r1 */
/* @0x21b060 mov r2, #0 */
/* @0x21b064 ldrlt r2, [r0, r3, lsl #2] */
/* @0x21b068 vldr s15, [r2, #28] */
/* @0x21b06c vcmpe.f32 s15, s16 */
/* @0x21b070 add r3, r3, #1 */
/* @0x21b074 vmrs APSR_nzcv, fpscr */
/* @0x21b078 vmovmi.f32 s16, s15 */
/* @0x21b07c movmi r9, r2 */
/* @0x21b080 cmp r3, r4 */
/* @0x21b084 bne 0x21b05c <_Z26Audio_GetSoundSourceToPlayif+0x280> */
/* @0x21b088 b 0x21afa4 <_Z26Audio_GetSoundSourceToPlayif+0x1c8> */
/* @0x21b08c mov r0, #60 */
/* @0x21b090 ldr r10, [pc, #0x1e0] */
/* @0x21b094 bl 0x27c524 <_Znwj> */
/* @0x21b098 add r10, pc, r10 */
/* @0x21b09c mov r9, r0 */
/* @0x21b0a0 bl 0x21dad8 <_ZN6CNoiseC2Ev> */
/* @0x21b0a4 ldr r5, [r10, #0x38] */
/* @0x21b0a8 str r4, [r9, #0x10] */
/* @0x21b0ac adds r1, r5, #1 */
/* @0x21b0b0 str r1, [sp, #0xc] */
/* @0x21b0b4 bne 0x21b188 <_Z26Audio_GetSoundSourceToPlayif+0x3ac> */
/* @0x21b0b8 ldr r3, [r10, #0x3c] */
/* @0x21b0bc cmp r3, #0 */
/* @0x21b0c0 beq 0x21b23c <_Z26Audio_GetSoundSourceToPlayif+0x460> */
/* @0x21b0c4 cmp r5, #0 */
/* @0x21b0c8 ble 0x21b168 <_Z26Audio_GetSoundSourceToPlayif+0x38c> */
/* @0x21b0cc ldr r1, [pc, #0x1a8] */
/* @0x21b0d0 ldr r12, [pc, #0x1a8] */
/* @0x21b0d4 ldr r6, [sp, #0xc] */
/* @0x21b0d8 add r1, pc, r1 */
/* @0x21b0dc add r12, pc, r12 */
/* @0x21b0e0 str r4, [sp, #0x10] */
/* @0x21b0e4 mov r8, r1 */
/* @0x21b0e8 str r5, [sp, #0x14] */
/* @0x21b0ec mov r11, r6 */
/* @0x21b0f0 mov r4, r12 */
/* @0x21b0f4 ldr r1, [r3] */
/* @0x21b0f8 movw r2, #0xfeee */
/* @0x21b0fc movt r2, #0xfeee */
/* @0x21b100 movw lr, #0xfeee */
/* @0x21b104 cmp r1, r2 */
/* @0x21b108 movt lr, #0xfeee */
/* @0x21b10c lsl r5, r6, #2 */
/* @0x21b110 beq 0x21b150 <_Z26Audio_GetSoundSourceToPlayif+0x374> */
/* @0x21b114 ldr r7, [r3, r6, lsl #2] */
/* @0x21b118 add r1, r3, r5 */
/* @0x21b11c cmp r7, #0 */
/* @0x21b120 mov r0, r7 */
/* @0x21b124 beq 0x21b150 <_Z26Audio_GetSoundSourceToPlayif+0x374> */
/* @0x21b128 ldr r3, [r7] */
/* @0x21b12c cmp r3, lr */
/* @0x21b130 beq 0x21b148 <_Z26Audio_GetSoundSourceToPlayif+0x36c> */
/* @0x21b134 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x21b138 mov r0, r7 */
/* @0x21b13c bl 0x27d1d0 <_ZdlPv> */
/* @0x21b140 ldr r1, [r4, #0x3c] */
/* @0x21b144 add r1, r1, r5 */
/* @0x21b148 str r11, [r1] */
/* @0x21b14c ldr r3, [r8, #0x3c] */
/* @0x21b150 ldr r2, [r10, #0x38] */
/* @0x21b154 add r6, r6, #1 */
/* @0x21b158 cmp r6, r2 */
/* @0x21b15c blt 0x21b0f4 <_Z26Audio_GetSoundSourceToPlayif+0x318> */
/* @0x21b160 ldr r4, [sp, #0x10] */
/* @0x21b164 ldr r5, [sp, #0x14] */
/* @0x21b168 mov r0, r3 */
/* @0x21b16c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21b170 ldr r1, [pc, #0x10c] */
/* @0x21b174 mov r3, #0 */
/* @0x21b178 add r1, pc, r1 */
/* @0x21b17c mov r2, r3 */
/* @0x21b180 str r3, [r1, #0x3c] */
/* @0x21b184 b 0x21b1b8 <_Z26Audio_GetSoundSourceToPlayif+0x3dc> */
/* @0x21b188 ldr r2, [sp, #0xc] */
/* @0x21b18c lsls r1, r2, #2 */
/* @0x21b190 beq 0x21b238 <_Z26Audio_GetSoundSourceToPlayif+0x45c> */
/* @0x21b194 ldr r2, [pc, #0xec] */
/* @0x21b198 mov r3, #0 */
/* @0x21b19c ldr r0, [r10, #0x3c] */
/* @0x21b1a0 add r2, pc, r2 */
/* @0x21b1a4 str r3, [sp] */
/* @0x21b1a8 mov r3, #135 */
/* @0x21b1ac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21b1b0 mov r2, r0 */
/* @0x21b1b4 str r0, [r10, #0x3c] */
/* @0x21b1b8 ldr r3, [pc, #0xcc] */
/* @0x21b1bc cmp r4, r5 */
/* @0x21b1c0 ldr r1, [sp, #0xc] */
/* @0x21b1c4 add r3, pc, r3 */
/* @0x21b1c8 str r1, [r3, #0x38] */
/* @0x21b1cc bge 0x21b20c <_Z26Audio_GetSoundSourceToPlayif+0x430> */
/* @0x21b1d0 ldr r0, [pc, #0xb8] */
/* @0x21b1d4 lsl r3, r5, #2 */
/* @0x21b1d8 add r0, pc, r0 */
/* @0x21b1dc b 0x21b1e4 <_Z26Audio_GetSoundSourceToPlayif+0x408> */
/* @0x21b1e0 ldr r2, [r0, #0x3c] */
/* @0x21b1e4 add r1, r2, r3 */
/* @0x21b1e8 sub r5, r5, #1 */
/* @0x21b1ec cmp r5, r4 */
/* @0x21b1f0 ldr r1, [r1, #-0x4] */
/* @0x21b1f4 str r1, [r2, r3] */
/* @0x21b1f8 sub r3, r3, #4 */
/* @0x21b1fc bne 0x21b1e0 <_Z26Audio_GetSoundSourceToPlayif+0x404> */
/* @0x21b200 ldr r3, [pc, #0x8c] */
/* @0x21b204 add r3, pc, r3 */
/* @0x21b208 ldr r2, [r3, #0x3c] */
/* @0x21b20c str r9, [r2, r4, lsl #2] */
/* @0x21b210 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b214 ldr r0, [r9, #0x38] */
/* @0x21b218 cmp r0, #0 */
/* @0x21b21c beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b220 mov r1, r9 */
/* @0x21b224 str r2, [sp, #0x8] */
/* @0x21b228 bl 0x2158dc <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise> */
/* @0x21b22c ldr r2, [sp, #0x8] */
/* @0x21b230 str r2, [r9, #0x38] */
/* @0x21b234 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b238 ldr r3, [r10, #0x3c] */
/* @0x21b23c mov r0, r3 */
/* @0x21b240 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21b244 ldr r1, [pc, #0x4c] */
/* @0x21b248 mov r3, #0 */
/* @0x21b24c add r1, pc, r1 */
/* @0x21b250 mov r2, r3 */
/* @0x21b254 str r3, [r1, #0x3c] */
/* @0x21b258 b 0x21b1b8 <_Z26Audio_GetSoundSourceToPlayif+0x3dc> */
/* @0x21b25c andseq r6, sp, r8, asr lr */
/* @0x21b260 .word 0xffffd3fc */
/* @0x21b264 subseq r10, r3, r4, lsl #9 */
/* @0x21b268 subseq r10, r3, r12, lsr r4 */
/* @0x21b26c .word 0xfffff77c */
/* @0x21b270 .word 0xfffff784 */
/* @0x21b274 subseq r10, r3, r4, asr #6 */
/* @0x21b278 ldrsheq r10, [r3], #-28 */
/* @0x21b27c ldrheq r10, [r3], #-28 */
/* @0x21b280 ldrheq r10, [r3], #-24 */
/* @0x21b284 subseq r10, r3, r12, lsl r1 */
/* @0x21b288 andseq r2, r3, r0, asr r1 */
/* @0x21b28c ldrsbeq r10, [r3], #-0 */
/* @0x21b290 ldrheq r10, [r3], #-12 */
/* @0x21b294 .word 0x0053a090 */
/* @0x21b298 subseq r10, r3, r8, asr #32 */
/* ══ 5/8  Audio_StartRecording  0x21c700  size 1016  254 条（0x21c700..0x21caf8）
 * @func 0x21c700 0x21caf8  size 1016  254 条
 * 符号 _Z20Audio_StartRecordingi (int device)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21c718→0x7552fc, 0x21c918→0x3eb70c, 0x21c9d0→0x3eb70c, 0x21ca38→0x3eb70c, 0x21ca4c→0x3eb70c, 0x21ca80→0x3eb70c
 * 结构: 读 0x7552fc（录音侧全局）与 0x3eb70c（数据区对象）；两处 checkAL 校验
 * 调用序列（地址序，去重计数）: checkAL(char const*)×2 / operator new(unsigned int)×2 / MemoryManager::Free(void const*)×2 / Audio_StartRecording(int)+0x330 / GetRecorderFromDevice(int) / 0xb6b5c / Audio_StartRecording(int)+0x218 / Audio_StartRecording(int)+0x10c
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x54×12 / 0xc×8 / 0x4×5 / 0x10×5 / 0x50×5 / 0x8×5 / 0x2×4 / 0x1a8×2
 * VFP 指令 0 条（无浮点）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x21c700 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21c704 subs r5, r0, #0 */
/* @0x21c708 ldr r6, [pc, #0x394] */
/* @0x21c70c sub sp, sp, #20 */
/* @0x21c710 add r6, pc, r6 */
/* @0x21c714 blt 0x21ca30 <_Z20Audio_StartRecordingi+0x330> */
/* @0x21c718 ldr r3, [pc, #0x388] */
/* @0x21c71c ldr r3, [r6, r3] */
/* @0x21c720 ldr r2, [r3] */
/* @0x21c724 cmp r5, r2 */
/* @0x21c728 bgt 0x21ca30 <_Z20Audio_StartRecordingi+0x330> */
/* @0x21c72c bge 0x21c9c8 <_Z20Audio_StartRecordingi+0x2c8> */
/* @0x21c730 ldr r3, [r3, #0x4] */
/* @0x21c734 ldr r7, [r3, r5, lsl #2] */
/* @0x21c738 cmp r7, #0 */
/* @0x21c73c beq 0x21c9c8 <_Z20Audio_StartRecordingi+0x2c8> */
/* @0x21c740 bl 0x21c254 <_Z21GetRecorderFromDevicei> */
/* @0x21c744 subs r4, r0, #0 */
/* @0x21c748 beq 0x21c7c4 <_Z20Audio_StartRecordingi+0xc4> */
/* @0x21c74c ldrb r3, [r4, #0xc] */
/* @0x21c750 cmp r3, #0 */
/* @0x21c754 bne 0x21ca44 <_Z20Audio_StartRecordingi+0x344> */
/* @0x21c758 ldr r0, [r4, #0x10] */
/* @0x21c75c bl 0xb6b5c <alcCaptureStart@plt> */
/* @0x21c760 ldr r0, [pc, #0x344] */
/* @0x21c764 add r0, pc, r0 */
/* @0x21c768 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21c76c ldr r2, [pc, #0x33c] */
/* @0x21c770 mov r3, #1 */
/* @0x21c774 strb r3, [r4, #0xc] */
/* @0x21c778 add r2, pc, r2 */
/* @0x21c77c ldr r3, [r2, #0x50] */
/* @0x21c780 cmp r3, #0 */
/* @0x21c784 ble 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c788 ldr r2, [r2, #0x54] */
/* @0x21c78c mov r0, #0 */
/* @0x21c790 ldr r1, [r2] */
/* @0x21c794 cmp r4, r1 */
/* @0x21c798 beq 0x21c7bc <_Z20Audio_StartRecordingi+0xbc> */
/* @0x21c79c add r0, r0, #1 */
/* @0x21c7a0 cmp r0, r3 */
/* @0x21c7a4 beq 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c7a8 ldr r1, [r2, #0x4]! */
/* @0x21c7ac cmp r4, r1 */
/* @0x21c7b0 bne 0x21c79c <_Z20Audio_StartRecordingi+0x9c> */
/* @0x21c7b4 cmn r0, #1 */
/* @0x21c7b8 beq 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c7bc add sp, sp, #20 */
/* @0x21c7c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c7c4 ldr r3, [pc, #0x2e8] */
/* @0x21c7c8 add r3, pc, r3 */
/* @0x21c7cc ldr r1, [r3, #0x50] */
/* @0x21c7d0 cmp r1, #0 */
/* @0x21c7d4 ble 0x21c80c <_Z20Audio_StartRecordingi+0x10c> */
/* @0x21c7d8 ldr r3, [r3, #0x54] */
/* @0x21c7dc ldr r8, [r3] */
/* @0x21c7e0 cmp r8, #0 */
/* @0x21c7e4 movne r5, r4 */
/* @0x21c7e8 bne 0x21c7fc <_Z20Audio_StartRecordingi+0xfc> */
/* @0x21c7ec b 0x21c944 <_Z20Audio_StartRecordingi+0x244> */
/* @0x21c7f0 ldr r2, [r3, #0x4]! */
/* @0x21c7f4 cmp r2, #0 */
/* @0x21c7f8 beq 0x21c948 <_Z20Audio_StartRecordingi+0x248> */
/* @0x21c7fc add r5, r5, #1 */
/* @0x21c800 cmp r5, r1 */
/* @0x21c804 lsl r8, r5, #2 */
/* @0x21c808 bne 0x21c7f0 <_Z20Audio_StartRecordingi+0xf0> */
/* @0x21c80c mov r0, #20 */
/* @0x21c810 ldr r11, [pc, #0x2a0] */
/* @0x21c814 bl 0x27c524 <_Znwj> */
/* @0x21c818 mov r3, #0 */
/* @0x21c81c add r11, pc, r11 */
/* @0x21c820 ldr r5, [r11, #0x50] */
/* @0x21c824 adds r9, r5, #1 */
/* @0x21c828 mov r4, r0 */
/* @0x21c82c str r3, [r0] */
/* @0x21c830 str r3, [r0, #0x4] */
/* @0x21c834 str r3, [r0, #0x8] */
/* @0x21c838 strb r3, [r0, #0xc] */
/* @0x21c83c str r3, [r0, #0x10] */
/* @0x21c840 bne 0x21c9f4 <_Z20Audio_StartRecordingi+0x2f4> */
/* @0x21c844 ldr r3, [r11, #0x54] */
/* @0x21c848 cmp r3, #0 */
/* @0x21c84c beq 0x21ca5c <_Z20Audio_StartRecordingi+0x35c> */
/* @0x21c850 cmp r5, #0 */
/* @0x21c854 ble 0x21c8f8 <_Z20Audio_StartRecordingi+0x1f8> */
/* @0x21c858 ldr r12, [pc, #0x25c] */
/* @0x21c85c mov r8, r9 */
/* @0x21c860 ldr r2, [pc, #0x258] */
/* @0x21c864 add r12, pc, r12 */
/* @0x21c868 str r6, [sp, #0xc] */
/* @0x21c86c mov r6, r5 */
/* @0x21c870 mov r5, r4 */
/* @0x21c874 mov r4, r12 */
/* @0x21c878 add r2, pc, r2 */
/* @0x21c87c str r2, [sp, #0x8] */
/* @0x21c880 ldr r0, [r3] */
/* @0x21c884 movw r1, #0xfeee */
/* @0x21c888 movt r1, #0xfeee */
/* @0x21c88c movw r2, #0xfeee */
/* @0x21c890 cmp r0, r1 */
/* @0x21c894 movt r2, #0xfeee */
/* @0x21c898 lsl r10, r8, #2 */
/* @0x21c89c beq 0x21c8dc <_Z20Audio_StartRecordingi+0x1dc> */
/* @0x21c8a0 ldr r1, [r3, r8, lsl #2] */
/* @0x21c8a4 add lr, r3, r10 */
/* @0x21c8a8 cmp r1, #0 */
/* @0x21c8ac mov r0, r1 */
/* @0x21c8b0 beq 0x21c8dc <_Z20Audio_StartRecordingi+0x1dc> */
/* @0x21c8b4 ldr r3, [r1] */
/* @0x21c8b8 cmp r3, r2 */
/* @0x21c8bc beq 0x21c8d0 <_Z20Audio_StartRecordingi+0x1d0> */
/* @0x21c8c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21c8c4 ldr r3, [sp, #0x8] */
/* @0x21c8c8 ldr lr, [r3, #0x54] */
/* @0x21c8cc add lr, lr, r10 */
/* @0x21c8d0 mov r2, #0 */
/* @0x21c8d4 str r2, [lr] */
/* @0x21c8d8 ldr r3, [r4, #0x54] */
/* @0x21c8dc ldr r2, [r11, #0x50] */
/* @0x21c8e0 add r8, r8, #1 */
/* @0x21c8e4 cmp r8, r2 */
/* @0x21c8e8 blt 0x21c880 <_Z20Audio_StartRecordingi+0x180> */
/* @0x21c8ec mov r4, r5 */
/* @0x21c8f0 mov r5, r6 */
/* @0x21c8f4 ldr r6, [sp, #0xc] */
/* @0x21c8f8 mov r0, r3 */
/* @0x21c8fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c900 ldr r1, [pc, #0x1bc] */
/* @0x21c904 mov r2, #0 */
/* @0x21c908 add r1, pc, r1 */
/* @0x21c90c mov r3, r2 */
/* @0x21c910 str r2, [r1, #0x54] */
/* @0x21c914 b 0x21ca1c <_Z20Audio_StartRecordingi+0x31c> */
/* @0x21c918 ldr r3, [pc, #0x1a8] */
/* @0x21c91c ldr r1, [pc, #0x1a8] */
/* @0x21c920 ldr r3, [r6, r3] */
/* @0x21c924 add r1, pc, r1 */
/* @0x21c928 ldr r0, [r3] */
/* @0x21c92c ldr r3, [r0] */
/* @0x21c930 ldr r3, [r3, #0xc] */
/* @0x21c934 blx r3 */
/* @0x21c938 mvn r0, #0 */
/* @0x21c93c add sp, sp, #20 */
/* @0x21c940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c944 mov r5, r8 */
/* @0x21c948 mov r0, #20 */
/* @0x21c94c bl 0x27c524 <_Znwj> */
/* @0x21c950 ldr r2, [pc, #0x178] */
/* @0x21c954 mov r3, #0 */
/* @0x21c958 add r2, pc, r2 */
/* @0x21c95c ldr r2, [r2, #0x54] */
/* @0x21c960 mov r4, r0 */
/* @0x21c964 str r3, [r0] */
/* @0x21c968 str r3, [r0, #0x4] */
/* @0x21c96c str r3, [r0, #0x8] */
/* @0x21c970 strb r3, [r0, #0xc] */
/* @0x21c974 str r3, [r0, #0x10] */
/* @0x21c978 str r0, [r2, r8] */
/* @0x21c97c mov r3, #32000 */
/* @0x21c980 mov r1, #16000 */
/* @0x21c984 movw r2, #0x1101 */
/* @0x21c988 ldr r0, [r7] */
/* @0x21c98c bl 0xb6b68 <alcCaptureOpenDevice@plt> */
/* @0x21c990 str r0, [r4, #0x10] */
/* @0x21c994 ldr r0, [pc, #0x138] */
/* @0x21c998 add r0, pc, r0 */
/* @0x21c99c bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21c9a0 ldr r3, [r4, #0x10] */
/* @0x21c9a4 cmp r3, #0 */
/* @0x21c9a8 beq 0x21ca7c <_Z20Audio_StartRecordingi+0x37c> */
/* @0x21c9ac ldr r0, [r7] */
/* @0x21c9b0 mov r2, #16000 */
/* @0x21c9b4 movw r3, #0x1101 */
/* @0x21c9b8 stm r4, {r2, r3} */
/* @0x21c9bc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21c9c0 str r0, [r4, #0x8] */
/* @0x21c9c4 b 0x21c758 <_Z20Audio_StartRecordingi+0x58> */
/* @0x21c9c8 ldr r1, [pc, #0x108] */
/* @0x21c9cc mov r2, r5 */
/* @0x21c9d0 ldr r3, [pc, #0xf0] */
/* @0x21c9d4 add r1, pc, r1 */
/* @0x21c9d8 ldr r3, [r6, r3] */
/* @0x21c9dc ldr r0, [r3] */
/* @0x21c9e0 ldr r3, [r0] */
/* @0x21c9e4 ldr r3, [r3, #0xc] */
/* @0x21c9e8 blx r3 */
/* @0x21c9ec mvn r0, #0 */
/* @0x21c9f0 b 0x21c7bc <_Z20Audio_StartRecordingi+0xbc> */
/* @0x21c9f4 lsls r1, r9, #2 */
/* @0x21c9f8 beq 0x21ca58 <_Z20Audio_StartRecordingi+0x358> */
/* @0x21c9fc ldr r2, [pc, #0xd8] */
/* @0x21ca00 ldr r0, [r11, #0x54] */
/* @0x21ca04 add r2, pc, r2 */
/* @0x21ca08 str r3, [sp] */
/* @0x21ca0c mov r3, #135 */
/* @0x21ca10 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21ca14 mov r3, r0 */
/* @0x21ca18 str r0, [r11, #0x54] */
/* @0x21ca1c ldr r2, [pc, #0xbc] */
/* @0x21ca20 add r2, pc, r2 */
/* @0x21ca24 str r9, [r2, #0x50] */
/* @0x21ca28 str r4, [r3, r5, lsl #2] */
/* @0x21ca2c b 0x21c97c <_Z20Audio_StartRecordingi+0x27c> */
/* @0x21ca30 ldr r1, [pc, #0xac] */
/* @0x21ca34 mov r2, r5 */
/* @0x21ca38 ldr r3, [pc, #0x88] */
/* @0x21ca3c add r1, pc, r1 */
/* @0x21ca40 b 0x21c9d8 <_Z20Audio_StartRecordingi+0x2d8> */
/* @0x21ca44 ldr r1, [pc, #0x9c] */
/* @0x21ca48 mov r2, r5 */
/* @0x21ca4c ldr r3, [pc, #0x74] */
/* @0x21ca50 add r1, pc, r1 */
/* @0x21ca54 b 0x21c9d8 <_Z20Audio_StartRecordingi+0x2d8> */
/* @0x21ca58 ldr r3, [r11, #0x54] */
/* @0x21ca5c mov r0, r3 */
/* @0x21ca60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ca64 ldr r1, [pc, #0x80] */
/* @0x21ca68 mov r2, #0 */
/* @0x21ca6c add r1, pc, r1 */
/* @0x21ca70 mov r3, r2 */
/* @0x21ca74 str r2, [r1, #0x54] */
/* @0x21ca78 b 0x21ca1c <_Z20Audio_StartRecordingi+0x31c> */
/* @0x21ca7c ldr r0, [pc, #0x6c] */
/* @0x21ca80 ldr r2, [pc, #0x40] */
/* @0x21ca84 add r0, pc, r0 */
/* @0x21ca88 ldr r1, [pc, #0x64] */
/* @0x21ca8c ldr r0, [r0, #0x54] */
/* @0x21ca90 add r1, pc, r1 */
/* @0x21ca94 str r3, [r0, r5, lsl #2] */
/* @0x21ca98 ldr r3, [r6, r2] */
/* @0x21ca9c ldr r2, [r7] */
/* @0x21caa0 b 0x21c9dc <_Z20Audio_StartRecordingi+0x2dc> */
/* @0x21caa4 andseq r5, sp, r0, asr #10 */
/* @0x21caa8 .word 0xfffff7a8 */
/* @0x21caac andseq r7, r3, r0, lsl r12 */
/* @0x21cab0 subseq r8, r3, r12, lsl r11 */
/* @0x21cab4 subseq r8, r3, r12, asr #21 */
/* @0x21cab8 subseq r8, r3, r8, ror r10 */
/* @0x21cabc subseq r8, r3, r0, lsr r10 */
/* @0x21cac0 subseq r8, r3, r12, lsl r10 */
/* @0x21cac4 subseq r8, r3, r12, lsl #19 */
/* @0x21cac8 .word 0xffffbac4 */
/* @0x21cacc andseq r7, r3, r0, ror #20 */
/* @0x21cad0 subseq r8, r3, r12, lsr r9 */
/* @0x21cad4 andseq r7, r3, r0, asr r9 */
/* @0x21cad8 andseq r7, r3, r4, ror #17 */
/* @0x21cadc andseq r0, r3, r12, ror #17 */
/* @0x21cae0 subseq r8, r3, r4, ror r8 */
/* @0x21cae4 andseq r7, r3, r12, asr #16 */
/* @0x21cae8 ldrsheq r7, [r3], -r0 */
/* @0x21caec subseq r8, r3, r8, lsr #16 */
/* @0x21caf0 subseq r8, r3, r0, lsl r8 */
/* @0x21caf4 andseq r7, r3, r0, ror r8 */
/* ══ 6/8  Audio_Load  0x219048  size 908  227 条（0x219048..0x2193d4）
 * @func 0x219048 0x2193d4  size 908  227 条
 * 符号 _Z10Audio_LoadPhjPh (unsigned char* name, unsigned j, unsigned char* out)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 无标准序言（按 this/参数取值）
 * 门字节（加载点→目标全局）: 无
 * 结构: 无门字节、无标准 GOT 序言：底层装载体，按 this/参数取值
 * 调用序列（地址序，去重计数）: MemoryManager::Free(void const*)×6 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / Audio_Load(unsigned char*, unsigned int, unsigned char*)+0xf0 / cAudio_Sound::~cAudio_Sound() / operator delete(void*) / Audio_Load(unsigned char*, unsigned int, unsigned char*)+0x7c / Audio_Load(unsigned char*, unsigned int, unsigned char*)+0x1a8 / MemoryManager::IsAllocated(void const*)
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x4c×10 / 0x24×7 / 0xc×5 / 0x2×5 / 0x20×3 / 0x48×3 / 0x10×2 / 0x14×2
 * VFP 指令 0 条（无浮点）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x219048 ldr r3, [pc, #0x334] */
/* @0x21904c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x219050 ldr r3, [pc, r3] */
/* @0x219054 mov r8, r0 */
/* @0x219058 ldr r6, [pc, #0x328] */
/* @0x21905c ldr r0, [r3] */
/* @0x219060 sub sp, sp, #28 */
/* @0x219064 ldr r1, [pc, #0x320] */
/* @0x219068 add r6, pc, r6 */
/* @0x21906c str r2, [sp, #0x10] */
/* @0x219070 ldr r3, [r0] */
/* @0x219074 add r1, pc, r1 */
/* @0x219078 ldr r3, [r3, #0xc] */
/* @0x21907c blx r3 */
/* @0x219080 ldr r9, [r8] */
/* @0x219084 ldr r2, [r6, #0x20] */
/* @0x219088 cmp r9, r2 */
/* @0x21908c beq 0x21917c <_Z10Audio_LoadPhjS_+0x134> */
/* @0x219090 cmp r9, #0 */
/* @0x219094 ldr r3, [r6, #0x24] */
/* @0x219098 bne 0x219154 <_Z10Audio_LoadPhjS_+0x10c> */
/* @0x21909c cmp r3, #0 */
/* @0x2190a0 beq 0x219154 <_Z10Audio_LoadPhjS_+0x10c> */
/* @0x2190a4 cmp r2, #0 */
/* @0x2190a8 ble 0x219138 <_Z10Audio_LoadPhjS_+0xf0> */
/* @0x2190ac ldr r11, [pc, #0x2dc] */
/* @0x2190b0 mov r4, r9 */
/* @0x2190b4 ldr r12, [pc, #0x2d8] */
/* @0x2190b8 mov r7, r9 */
/* @0x2190bc add r11, pc, r11 */
/* @0x2190c0 add r12, pc, r12 */
/* @0x2190c4 ldr r0, [r3] */
/* @0x2190c8 movw r2, #0xfeee */
/* @0x2190cc movt r2, #0xfeee */
/* @0x2190d0 movw r1, #0xfeee */
/* @0x2190d4 cmp r0, r2 */
/* @0x2190d8 movt r1, #0xfeee */
/* @0x2190dc lsl r10, r4, #2 */
/* @0x2190e0 beq 0x219128 <_Z10Audio_LoadPhjS_+0xe0> */
/* @0x2190e4 ldr r5, [r3, r4, lsl #2] */
/* @0x2190e8 add lr, r3, r10 */
/* @0x2190ec cmp r5, #0 */
/* @0x2190f0 mov r0, r5 */
/* @0x2190f4 beq 0x219128 <_Z10Audio_LoadPhjS_+0xe0> */
/* @0x2190f8 ldr r3, [r5] */
/* @0x2190fc cmp r3, r1 */
/* @0x219100 beq 0x219120 <_Z10Audio_LoadPhjS_+0xd8> */
/* @0x219104 str r12, [sp, #0xc] */
/* @0x219108 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21910c mov r0, r5 */
/* @0x219110 bl 0x27d1d0 <_ZdlPv> */
/* @0x219114 ldr r12, [sp, #0xc] */
/* @0x219118 ldr lr, [r12, #0x24] */
/* @0x21911c add lr, lr, r10 */
/* @0x219120 str r7, [lr] */
/* @0x219124 ldr r3, [r11, #0x24] */
/* @0x219128 ldr r2, [r6, #0x20] */
/* @0x21912c add r4, r4, #1 */
/* @0x219130 cmp r4, r2 */
/* @0x219134 blt 0x2190c4 <_Z10Audio_LoadPhjS_+0x7c> */
/* @0x219138 mov r0, r3 */
/* @0x21913c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219140 ldr r3, [pc, #0x250] */
/* @0x219144 mov r2, #0 */
/* @0x219148 add r3, pc, r3 */
/* @0x21914c str r2, [r3, #0x24] */
/* @0x219150 b 0x219170 <_Z10Audio_LoadPhjS_+0x128> */
/* @0x219154 lsls r4, r9, #2 */
/* @0x219158 mov r0, r3 */
/* @0x21915c bne 0x219350 <_Z10Audio_LoadPhjS_+0x308> */
/* @0x219160 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219164 ldr r3, [pc, #0x230] */
/* @0x219168 add r3, pc, r3 */
/* @0x21916c str r4, [r3, #0x24] */
/* @0x219170 ldr r3, [pc, #0x228] */
/* @0x219174 add r3, pc, r3 */
/* @0x219178 str r9, [r3, #0x20] */
/* @0x21917c cmp r9, #0 */
/* @0x219180 bne 0x2192f0 <_Z10Audio_LoadPhjS_+0x2a8> */
/* @0x219184 ldr r5, [pc, #0x218] */
/* @0x219188 add r5, pc, r5 */
/* @0x21918c ldr r0, [r5, #0x4c] */
/* @0x219190 cmp r0, #0 */
/* @0x219194 beq 0x2192fc <_Z10Audio_LoadPhjS_+0x2b4> */
/* @0x219198 ldr r3, [r5, #0x48] */
/* @0x21919c cmp r3, #0 */
/* @0x2191a0 ble 0x2191f0 <_Z10Audio_LoadPhjS_+0x1a8> */
/* @0x2191a4 ldr r7, [pc, #0x1fc] */
/* @0x2191a8 mov r4, r9 */
/* @0x2191ac mov r6, r9 */
/* @0x2191b0 add r7, pc, r7 */
/* @0x2191b4 ldr r0, [r0, r4, lsl #2] */
/* @0x2191b8 lsl r11, r4, #2 */
/* @0x2191bc bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x2191c0 cmp r0, #0 */
/* @0x2191c4 beq 0x2191d4 <_Z10Audio_LoadPhjS_+0x18c> */
/* @0x2191c8 ldr r3, [r7, #0x4c] */
/* @0x2191cc ldr r0, [r3, r4, lsl #2] */
/* @0x2191d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2191d4 ldr r2, [r5, #0x48] */
/* @0x2191d8 add r4, r4, #1 */
/* @0x2191dc ldr r3, [r5, #0x4c] */
/* @0x2191e0 cmp r4, r2 */
/* @0x2191e4 str r6, [r3, r11] */
/* @0x2191e8 ldr r0, [r5, #0x4c] */
/* @0x2191ec blt 0x2191b4 <_Z10Audio_LoadPhjS_+0x16c> */
/* @0x2191f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2191f4 ldr r3, [pc, #0x1b0] */
/* @0x2191f8 mov r2, #0 */
/* @0x2191fc add r3, pc, r3 */
/* @0x219200 str r2, [r3, #0x4c] */
/* @0x219204 ldr r7, [pc, #0x1a4] */
/* @0x219208 cmp r9, #0 */
/* @0x21920c add r7, pc, r7 */
/* @0x219210 str r9, [r7, #0x48] */
/* @0x219214 beq 0x219344 <_Z10Audio_LoadPhjS_+0x2fc> */
/* @0x219218 ldr r3, [pc, #0x194] */
/* @0x21921c mov r4, #0 */
/* @0x219220 add r3, pc, r3 */
/* @0x219224 str r3, [sp, #0x14] */
/* @0x219228 b 0x2192dc <_Z10Audio_LoadPhjS_+0x294> */
/* @0x21922c ldr r10, [pc, #0x184] */
/* @0x219230 ldr r10, [pc, r10] */
/* @0x219234 ldr r11, [r10] */
/* @0x219238 adds r1, r11, r5 */
/* @0x21923c beq 0x21937c <_Z10Audio_LoadPhjS_+0x334> */
/* @0x219240 mov r0, #96 */
/* @0x219244 str r1, [sp, #0xc] */
/* @0x219248 bl 0x27c524 <_Znwj> */
/* @0x21924c mov r6, r0 */
/* @0x219250 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219254 ldr r1, [sp, #0xc] */
/* @0x219258 mov r0, r6 */
/* @0x21925c ldr r2, [sp, #0x10] */
/* @0x219260 bl 0x218d64 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh> */
/* @0x219264 ldr r12, [r11, r5] */
/* @0x219268 cmp r12, #0 */
/* @0x21926c ldrne r3, [r10] */
/* @0x219270 moveq r11, r12 */
/* @0x219274 addne r11, r3, r12 */
/* @0x219278 mov r0, r11 */
/* @0x21927c bl 0xb6538 <strlen@plt> */
/* @0x219280 ldr r1, [sp, #0x14] */
/* @0x219284 mov r3, #1 */
/* @0x219288 movw r2, #0xb42 */
/* @0x21928c add r0, r0, r3 */
/* @0x219290 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x219294 mov r1, r11 */
/* @0x219298 mov r5, r0 */
/* @0x21929c bl 0xb65a4 <strcpy@plt> */
/* @0x2192a0 ldr r3, [r7, #0x24] */
/* @0x2192a4 lsl r11, r4, #2 */
/* @0x2192a8 str r6, [r3, r4, lsl #2] */
/* @0x2192ac ldr r3, [r7, #0x4c] */
/* @0x2192b0 add r1, r3, r11 */
/* @0x2192b4 ldr r0, [r3, r4, lsl #2] */
/* @0x2192b8 cmp r0, #0 */
/* @0x2192bc beq 0x2192cc <_Z10Audio_LoadPhjS_+0x284> */
/* @0x2192c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2192c4 ldr r1, [r7, #0x4c] */
/* @0x2192c8 add r1, r1, r11 */
/* @0x2192cc add r4, r4, #1 */
/* @0x2192d0 str r5, [r1] */
/* @0x2192d4 cmp r4, r9 */
/* @0x2192d8 beq 0x219344 <_Z10Audio_LoadPhjS_+0x2fc> */
/* @0x2192dc ldr r5, [r8, #0x4]! */
/* @0x2192e0 cmp r5, #0 */
/* @0x2192e4 bne 0x21922c <_Z10Audio_LoadPhjS_+0x1e4> */
/* @0x2192e8 mov r6, r5 */
/* @0x2192ec b 0x2192a0 <_Z10Audio_LoadPhjS_+0x258> */
/* @0x2192f0 ldr r3, [pc, #0xc4] */
/* @0x2192f4 add r3, pc, r3 */
/* @0x2192f8 ldr r0, [r3, #0x4c] */
/* @0x2192fc lsls r4, r9, #2 */
/* @0x219300 beq 0x219330 <_Z10Audio_LoadPhjS_+0x2e8> */
/* @0x219304 ldr r2, [pc, #0xb4] */
/* @0x219308 mov r3, #0 */
/* @0x21930c mov r1, r4 */
/* @0x219310 str r3, [sp] */
/* @0x219314 add r2, pc, r2 */
/* @0x219318 mov r3, #92 */
/* @0x21931c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x219320 ldr r3, [pc, #0x9c] */
/* @0x219324 add r3, pc, r3 */
/* @0x219328 str r0, [r3, #0x4c] */
/* @0x21932c b 0x219204 <_Z10Audio_LoadPhjS_+0x1bc> */
/* @0x219330 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219334 ldr r3, [pc, #0x8c] */
/* @0x219338 add r3, pc, r3 */
/* @0x21933c str r4, [r3, #0x4c] */
/* @0x219340 b 0x219204 <_Z10Audio_LoadPhjS_+0x1bc> */
/* @0x219344 mov r0, #1 */
/* @0x219348 add sp, sp, #28 */
/* @0x21934c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x219350 ldr r2, [pc, #0x74] */
/* @0x219354 mov r3, #0 */
/* @0x219358 mov r1, r4 */
/* @0x21935c str r3, [sp] */
/* @0x219360 add r2, pc, r2 */
/* @0x219364 mov r3, #135 */
/* @0x219368 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21936c ldr r3, [pc, #0x5c] */
/* @0x219370 add r3, pc, r3 */
/* @0x219374 str r0, [r3, #0x24] */
/* @0x219378 b 0x219170 <_Z10Audio_LoadPhjS_+0x128> */
/* @0x21937c mov r5, r1 */
/* @0x219380 b 0x2192e8 <_Z10Audio_LoadPhjS_+0x2a0> */
/* @0x219384 andseq r6, sp, r12, asr #21 */
/* @0x219388 subseq r12, r3, r12, lsr #4 */
/* @0x21938c ldrsbeq r10, [r3], -r0 */
/* @0x219390 ldrsbeq r12, [r3], #-24 */
/* @0x219394 ldrsbeq r12, [r3], #-20 */
/* @0x219398 subseq r12, r3, r12, asr #2 */
/* @0x21939c subseq r12, r3, r12, lsr #2 */
/* @0x2193a0 subseq r12, r3, r0, lsr #2 */
/* @0x2193a4 subseq r12, r3, r12, lsl #2 */
/* @0x2193a8 subseq r12, r3, r4, ror #1 */
/* @0x2193ac .word 0x0053c098 */
/* @0x2193b0 subseq r12, r3, r8, lsl #1 */
/* @0x2193b4 andseq r10, r3, r8, ror r11 */
/* @0x2193b8 andseq r4, sp, r4, lsl r7 */
/* @0x2193bc subseq r11, r3, r0, lsr #31 */
/* @0x2193c0 andseq r10, r3, r0, asr #20 */
/* @0x2193c4 subseq r11, r3, r0, ror pc */
/* @0x2193c8 subseq r11, r3, r12, asr pc */
/* @0x2193cc mulseq r3, r0, pc */
/* @0x2193d0 subseq r11, r3, r4, lsr #30 */
/* ══ 7/8  Audio_PlaySoundOn  0x21b8c0  size 880  220 条（0x21b8c0..0x21bc30）
 * @func 0x21b8c0 0x21bc44  size 900  225 条
 * 符号 _Z17Audio_PlaySoundOnifff (int sound, float, float, float)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21b8d4→0x755363, 0x21b8f4→0x755314, 0x21b960→0x755324, 0x21b994→0x755318, 0x21b9f0→0x75531c, 0x21badc→0x3eb70c, 0x21bb0c→0x3eb70c, 0x21bb50→0x3eb70c
 * 结构: 读 0x755363（总开关）、0x755314（后端）、0x755324（CAudioGroupMan 单例）、0x755318、0x75531c（源名数组）、0x3eb70c
 * 调用序列（地址序，去重计数）: 0xb6a78×5 / 0xb6a54×3 / 0xb6b2c×2 / Audio_GetSound(int) / CAudioGroupMan::IsGroupLoaded(int) / Audio_GetSoundSourceToPlay(int, float) / CEmitter::AddNoiseToEmitter(CNoise*) / 0xb6a6c
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x2×9 / 0xc×7 / 0x14×3 / 0x40×2 / 0x18×2 / 0x4c×2 / 0x24×2 / 0x4×2
 * VFP 指令 16 条（浮点/三维坐标路径）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x21b8c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21b8c4 vpush {d8} */
/* @0x21b8c8 mov r6, r0 */
/* @0x21b8cc ldr r5, [pc, #0x324] */
/* @0x21b8d0 sub sp, sp, #8 */
/* @0x21b8d4 ldr r3, [pc, #0x320] */
/* @0x21b8d8 mov r7, r1 */
/* @0x21b8dc add r5, pc, r5 */
/* @0x21b8e0 mov r10, r2 */
/* @0x21b8e4 ldr r3, [r5, r3] */
/* @0x21b8e8 ldrb r3, [r3] */
/* @0x21b8ec cmp r3, #0 */
/* @0x21b8f0 bne 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b8f4 ldr r3, [pc, #0x304] */
/* @0x21b8f8 ldr r3, [r5, r3] */
/* @0x21b8fc ldrb r3, [r3] */
/* @0x21b900 cmp r3, #0 */
/* @0x21b904 beq 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b908 bl 0xb6a54 <alGetError@plt> */
/* @0x21b90c subs r2, r0, #0 */
/* @0x21b910 bne 0x21bb50 <_Z17Audio_PlaySoundOniiid+0x290> */
/* @0x21b914 ldr r3, [pc, #0x2e8] */
/* @0x21b918 lsr r8, r6, #31 */
/* @0x21b91c add r3, pc, r3 */
/* @0x21b920 ldr r2, [r3, #0x40] */
/* @0x21b924 cmp r2, r6 */
/* @0x21b928 orrle r8, r8, #1 */
/* @0x21b92c cmp r8, #0 */
/* @0x21b930 bne 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b934 ldr r3, [r3, #0x44] */
/* @0x21b938 ldr r4, [r3, r6, lsl #2] */
/* @0x21b93c cmp r4, #0 */
/* @0x21b940 beq 0x21bb74 <_Z17Audio_PlaySoundOniiid+0x2b4> */
/* @0x21b944 ldrb r3, [r4, #0x18] */
/* @0x21b948 cmp r3, #0 */
/* @0x21b94c beq 0x21bb74 <_Z17Audio_PlaySoundOniiid+0x2b4> */
/* @0x21b950 mov r0, r7 */
/* @0x21b954 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21b958 subs r9, r0, #0 */
/* @0x21b95c beq 0x21bbcc <_Z17Audio_PlaySoundOniiid+0x30c> */
/* @0x21b960 ldr r3, [pc, #0x2a0] */
/* @0x21b964 ldr r1, [r9, #0x4c] */
/* @0x21b968 ldr r0, [r5, r3] */
/* @0x21b96c bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21b970 subs r6, r0, #0 */
/* @0x21b974 beq 0x21bb0c <_Z17Audio_PlaySoundOniiid+0x24c> */
/* @0x21b978 vldr d7, [sp, #48] */
/* @0x21b97c vcvt.f32.f64 s16, d7 */
/* @0x21b980 mov r0, r7 */
/* @0x21b984 vmov r1, s16 */
/* @0x21b988 bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21b98c subs r6, r0, #0 */
/* @0x21b990 beq 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b994 ldr r3, [pc, #0x270] */
/* @0x21b998 cmp r10, #0 */
/* @0x21b99c vldr s17, [r9, #4] */
/* @0x21b9a0 mov lr, #1065353216 */
/* @0x21b9a4 movle r10, #0 */
/* @0x21b9a8 movgt r10, #1 */
/* @0x21b9ac ldr r2, [r5, r3] */
/* @0x21b9b0 mov r0, r4 */
/* @0x21b9b4 mov r1, r6 */
/* @0x21b9b8 str r7, [r6, #0x18] */
/* @0x21b9bc str lr, [r6, #0x24] */
/* @0x21b9c0 vstr s16, [r6, #28] */
/* @0x21b9c4 ldr r3, [r2] */
/* @0x21b9c8 strb r10, [r6, #0x4] */
/* @0x21b9cc str r8, [r6, #0x2c] */
/* @0x21b9d0 add r12, r3, #1 */
/* @0x21b9d4 str r3, [r6, #0x14] */
/* @0x21b9d8 str r12, [r2] */
/* @0x21b9dc bl 0x215944 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise> */
/* @0x21b9e0 ldr r7, [r6, #0x10] */
/* @0x21b9e4 bl 0xb6a54 <alGetError@plt> */
/* @0x21b9e8 subs r2, r0, #0 */
/* @0x21b9ec bne 0x21bba8 <_Z17Audio_PlaySoundOniiid+0x2e8> */
/* @0x21b9f0 ldr r3, [pc, #0x218] */
/* @0x21b9f4 movw r1, #0x202 */
/* @0x21b9f8 mov r2, #0 */
/* @0x21b9fc ldr r8, [r5, r3] */
/* @0x21ba00 ldr r3, [r8] */
/* @0x21ba04 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba08 bl 0xb6a6c <alSourcei@plt> */
/* @0x21ba0c ldr r3, [r8] */
/* @0x21ba10 movw r1, #0x1023 */
/* @0x21ba14 ldr r2, [r4, #0x20] */
/* @0x21ba18 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba1c bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba20 vldr s15, [r4, #40] */
/* @0x21ba24 vmul.f32 s15, s17, s15 */
/* @0x21ba28 ldr r3, [r8] */
/* @0x21ba2c movw r1, #0x100a */
/* @0x21ba30 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba34 vmov r2, s15 */
/* @0x21ba38 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba3c vldr s14, [r9, #8] */
/* @0x21ba40 vldr s15, [r4, #44] */
/* @0x21ba44 vmul.f32 s15, s15, s14 */
/* @0x21ba48 ldr r3, [r8] */
/* @0x21ba4c movw r1, #0x1003 */
/* @0x21ba50 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba54 vmov r2, s15 */
/* @0x21ba58 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba5c ldr r3, [r8] */
/* @0x21ba60 movw r1, #0x1020 */
/* @0x21ba64 ldr r2, [r4, #0x1c] */
/* @0x21ba68 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba6c bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba70 ldr r3, [r8] */
/* @0x21ba74 movw r1, #0x1021 */
/* @0x21ba78 ldr r2, [r4, #0x24] */
/* @0x21ba7c ldr r0, [r3, r7, lsl #2] */
/* @0x21ba80 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba84 ldr r1, [r8] */
/* @0x21ba88 ldr r12, [r4, #0x8] */
/* @0x21ba8c ldr r2, [r4] */
/* @0x21ba90 ldr r0, [r1, r7, lsl #2] */
/* @0x21ba94 movw r1, #0x1004 */
/* @0x21ba98 ldr r3, [r4, #0x4] */
/* @0x21ba9c str r12, [sp] */
/* @0x21baa0 bl 0xb6b2c <alSource3f@plt> */
/* @0x21baa4 ldr r1, [r8] */
/* @0x21baa8 ldr r12, [r4, #0x14] */
/* @0x21baac ldr r2, [r4, #0xc] */
/* @0x21bab0 ldr r3, [r4, #0x10] */
/* @0x21bab4 ldr r0, [r1, r7, lsl #2] */
/* @0x21bab8 movw r1, #0x1006 */
/* @0x21babc str r12, [sp] */
/* @0x21bac0 bl 0xb6b2c <alSource3f@plt> */
/* @0x21bac4 mov r1, r6 */
/* @0x21bac8 mov r0, r9 */
/* @0x21bacc bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise> */
/* @0x21bad0 bl 0xb6a54 <alGetError@plt> */
/* @0x21bad4 subs r2, r0, #0 */
/* @0x21bad8 beq 0x21bafc <_Z17Audio_PlaySoundOniiid+0x23c> */
/* @0x21badc ldr r3, [pc, #0x130] */
/* @0x21bae0 ldr r1, [pc, #0x130] */
/* @0x21bae4 ldr r3, [r5, r3] */
/* @0x21bae8 add r1, pc, r1 */
/* @0x21baec ldr r0, [r3] */
/* @0x21baf0 ldr r3, [r0] */
/* @0x21baf4 ldr r3, [r3, #0xc] */
/* @0x21baf8 blx r3 */
/* @0x21bafc ldr r0, [r6, #0x14] */
/* @0x21bb00 add sp, sp, #8 */
/* @0x21bb04 vpop {d8} */
/* @0x21bb08 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bb0c ldr r3, [pc, #0x100] */
/* @0x21bb10 mov r0, r7 */
/* @0x21bb14 ldr r3, [r5, r3] */
/* @0x21bb18 ldr r4, [r3] */
/* @0x21bb1c ldr r3, [r4] */
/* @0x21bb20 ldr r5, [r3, #0xc] */
/* @0x21bb24 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21bb28 ldr r1, [pc, #0xec] */
/* @0x21bb2c ldr r3, [r9, #0x4c] */
/* @0x21bb30 add r1, pc, r1 */
/* @0x21bb34 mov r2, r0 */
/* @0x21bb38 mov r0, r4 */
/* @0x21bb3c blx r5 */
/* @0x21bb40 mov r0, r6 */
/* @0x21bb44 add sp, sp, #8 */
/* @0x21bb48 vpop {d8} */
/* @0x21bb4c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bb50 ldr r3, [pc, #0xbc] */
/* @0x21bb54 ldr r1, [pc, #0xc4] */
/* @0x21bb58 ldr r3, [r5, r3] */
/* @0x21bb5c add r1, pc, r1 */
/* @0x21bb60 ldr r0, [r3] */
/* @0x21bb64 ldr r3, [r0] */
/* @0x21bb68 ldr r3, [r3, #0xc] */
/* @0x21bb6c blx r3 */
/* @0x21bb70 b 0x21b914 <_Z17Audio_PlaySoundOniiid+0x54> */
/* @0x21bb74 ldr r3, [pc, #0x98] */
/* @0x21bb78 mov r2, r6 */
/* @0x21bb7c ldr r1, [pc, #0xa0] */
/* @0x21bb80 ldr r3, [r5, r3] */
/* @0x21bb84 add r1, pc, r1 */
/* @0x21bb88 ldr r0, [r3] */
/* @0x21bb8c ldr r3, [r0] */
/* @0x21bb90 ldr r3, [r3, #0xc] */
/* @0x21bb94 blx r3 */
/* @0x21bb98 mvn r0, #0 */
/* @0x21bb9c add sp, sp, #8 */
/* @0x21bba0 vpop {d8} */
/* @0x21bba4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bba8 ldr r3, [pc, #0x64] */
/* @0x21bbac ldr r1, [pc, #0x74] */
/* @0x21bbb0 ldr r3, [r5, r3] */
/* @0x21bbb4 add r1, pc, r1 */
/* @0x21bbb8 ldr r0, [r3] */
/* @0x21bbbc ldr r3, [r0] */
/* @0x21bbc0 ldr r3, [r3, #0xc] */
/* @0x21bbc4 blx r3 */
/* @0x21bbc8 b 0x21b9f0 <_Z17Audio_PlaySoundOniiid+0x130> */
/* @0x21bbcc ldr r3, [pc, #0x40] */
/* @0x21bbd0 mov r2, r7 */
/* @0x21bbd4 ldr r1, [pc, #0x50] */
/* @0x21bbd8 ldr r3, [r5, r3] */
/* @0x21bbdc add r1, pc, r1 */
/* @0x21bbe0 ldr r0, [r3] */
/* @0x21bbe4 ldr r3, [r0] */
/* @0x21bbe8 ldr r3, [r3, #0xc] */
/* @0x21bbec blx r3 */
/* @0x21bbf0 mov r0, r9 */
/* @0x21bbf4 b 0x21bb00 <_Z17Audio_PlaySoundOniiid+0x240> */
/* @0x21bbf8 andseq r6, sp, r4, ror r3 */
/* @0x21bbfc .word 0xffffd3fc */
/* @0x21bc00 .word 0xffffd0e0 */
/* @0x21bc04 subseq r9, r3, r8, ror r9 */
/* @0x21bc08 .word 0xffffd400 */
/* @0x21bc0c .word 0xfffff7a0 */
/* @0x21bc10 .word 0xfffff77c */
/* @0x21bc14 .word 0xffffbac4 */
/* @0x21bc18 andseq r8, r3, r0, ror r6 */
/* @0x21bc1c andseq r8, r3, r4, lsr #10 */
/* @0x21bc20 ldrheq r8, [r3], -r4 */
/* @0x21bc24 ldrsheq r8, [r3], -r0 */
/* @0x21bc28 andseq r8, r3, r0, lsl #11 */
/* @0x21bc2c andseq r8, r3, r0, asr r4 */
/* ══ 8/8  Audio_PlaySoundAt  0x21b29c  size 828  212 条（0x21b29c..0x21b5ec）
 * @func 0x21b29c 0x21b5ec  size 848  212 条
 * 符号 _Z19Audio_PlaySoundAtiffff (int sound, float, float, float, float)
 * 级别: 骨架 —— 门字节 / 调用序列 / 字段偏移 / VFP 用量逐条落锚；每条语义未展开，见节尾 open
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21b2b0→0x755363, 0x21b2cc→0x755314, 0x21b2ec→0x755324, 0x21b320→0x755318, 0x21b374→0x75531c, 0x21b498→0x3eb70c, 0x21b4ec→0x3eb70c, 0x21b510→0x3eb70c
 * 结构: 与 PlaySoundOn 同一组门字节：0x755363 / 0x755314 / 0x755324 / 0x755318 / 0x75531c / 0x3eb70c
 * 调用序列（地址序，去重计数）: 0xb6a78×5 / 0xb6a54×4 / 0xb6b2c×2 / Audio_GetSound(int) / CAudioGroupMan::IsGroupLoaded(int) / Audio_GetSoundSourceToPlay(int, float) / 0xb6a6c / Audio_StartSoundNoise(cAudio_Sound*, CNoise*)
 * 字段偏移 top8（#imm 计数，可能混入调用实参）: 0x2×8 / 0xc×6 / 0x4c×3 / 0x4×2 / 0x14×2 / 0x2f4×1 / 0x2f0×1 / 0x2d8×1
 * VFP 指令 28 条（浮点/三维坐标路径）
 * 未主张: 字段语义、返回值写槽、失败分支的业务含义 —— open
 */
/* @0x21b29c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21b2a0 vpush {d8, d9} */
/* @0x21b2a4 vmov d8, r2, r3 */
/* @0x21b2a8 ldr r4, [pc, #0x2f4] */
/* @0x21b2ac sub sp, sp, #8 */
/* @0x21b2b0 ldr r1, [pc, #0x2f0] */
/* @0x21b2b4 mov r9, r0 */
/* @0x21b2b8 add r4, pc, r4 */
/* @0x21b2bc ldr r3, [r4, r1] */
/* @0x21b2c0 ldrb r7, [r3] */
/* @0x21b2c4 cmp r7, #0 */
/* @0x21b2c8 bne 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b2cc ldr r3, [pc, #0x2d8] */
/* @0x21b2d0 ldr r3, [r4, r3] */
/* @0x21b2d4 ldrb r3, [r3] */
/* @0x21b2d8 cmp r3, #0 */
/* @0x21b2dc beq 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b2e0 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21b2e4 subs r8, r0, #0 */
/* @0x21b2e8 beq 0x21b57c <_Z17Audio_PlaySoundAtiddddddid+0x2e0> */
/* @0x21b2ec ldr r3, [pc, #0x2bc] */
/* @0x21b2f0 ldr r1, [r8, #0x4c] */
/* @0x21b2f4 ldr r0, [r4, r3] */
/* @0x21b2f8 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21b2fc subs r5, r0, #0 */
/* @0x21b300 beq 0x21b498 <_Z17Audio_PlaySoundAtiddddddid+0x1fc> */
/* @0x21b304 vldr d6, [sp, #104] */
/* @0x21b308 vcvt.f32.f64 s18, d6 */
/* @0x21b30c mov r0, r9 */
/* @0x21b310 vmov r1, s18 */
/* @0x21b314 bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21b318 subs r5, r0, #0 */
/* @0x21b31c beq 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b320 ldr r3, [pc, #0x28c] */
/* @0x21b324 mov r0, #1065353216 */
/* @0x21b328 ldr r2, [sp, #0x60] */
/* @0x21b32c ldr r10, [r8, #0x4] */
/* @0x21b330 cmp r2, #0 */
/* @0x21b334 ldr r2, [r4, r3] */
/* @0x21b338 vstr s18, [r5, #28] */
/* @0x21b33c str r9, [r5, #0x18] */
/* @0x21b340 movle r1, #0 */
/* @0x21b344 movgt r1, #1 */
/* @0x21b348 ldr r3, [r2] */
/* @0x21b34c strb r1, [r5, #0x4] */
/* @0x21b350 str r7, [r5, #0x2c] */
/* @0x21b354 add r1, r3, #1 */
/* @0x21b358 str r3, [r5, #0x14] */
/* @0x21b35c str r0, [r5, #0x24] */
/* @0x21b360 str r1, [r2] */
/* @0x21b364 ldr r6, [r5, #0x10] */
/* @0x21b368 bl 0xb6a54 <alGetError@plt> */
/* @0x21b36c subs r2, r0, #0 */
/* @0x21b370 bne 0x21b558 <_Z17Audio_PlaySoundAtiddddddid+0x2bc> */
/* @0x21b374 ldr r3, [pc, #0x23c] */
/* @0x21b378 movw r1, #0x202 */
/* @0x21b37c mov r2, #0 */
/* @0x21b380 ldr r7, [r4, r3] */
/* @0x21b384 ldr r3, [r7] */
/* @0x21b388 ldr r0, [r3, r6, lsl #2] */
/* @0x21b38c bl 0xb6a6c <alSourcei@plt> */
/* @0x21b390 ldr r3, [r7] */
/* @0x21b394 mov r2, r10 */
/* @0x21b398 movw r1, #0x100a */
/* @0x21b39c ldr r0, [r3, r6, lsl #2] */
/* @0x21b3a0 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3a4 ldr r3, [r7] */
/* @0x21b3a8 ldr r2, [r8, #0x8] */
/* @0x21b3ac movw r1, #0x1003 */
/* @0x21b3b0 ldr r0, [r3, r6, lsl #2] */
/* @0x21b3b4 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3b8 bl 0xb6a54 <alGetError@plt> */
/* @0x21b3bc subs r2, r0, #0 */
/* @0x21b3c0 bne 0x21b534 <_Z17Audio_PlaySoundAtiddddddid+0x298> */
/* @0x21b3c4 vldr d6, [sp, #80] */
/* @0x21b3c8 vcvt.f32.f64 s13, d6 */
/* @0x21b3cc ldr r3, [r7] */
/* @0x21b3d0 movw r1, #0x1023 */
/* @0x21b3d4 ldr r0, [r3, r6, lsl #2] */
/* @0x21b3d8 vmov r2, s13 */
/* @0x21b3dc bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3e0 bl 0xb6a54 <alGetError@plt> */
/* @0x21b3e4 subs r2, r0, #0 */
/* @0x21b3e8 bne 0x21b510 <_Z17Audio_PlaySoundAtiddddddid+0x274> */
/* @0x21b3ec vldr d7, [sp, #72] */
/* @0x21b3f0 vcvt.f32.f64 s15, d7 */
/* @0x21b3f4 ldr r3, [r7] */
/* @0x21b3f8 movw r1, #0x1020 */
/* @0x21b3fc ldr r0, [r3, r6, lsl #2] */
/* @0x21b400 vmov r2, s15 */
/* @0x21b404 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b408 vldr d6, [sp, #88] */
/* @0x21b40c vcvt.f32.f64 s13, d6 */
/* @0x21b410 ldr r3, [r7] */
/* @0x21b414 movw r1, #0x1021 */
/* @0x21b418 ldr r0, [r3, r6, lsl #2] */
/* @0x21b41c vmov r2, s13 */
/* @0x21b420 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b424 vldr d6, [sp, #64] */
/* @0x21b428 vcvt.f32.f64 s15, d6 */
/* @0x21b42c ldr r3, [r7] */
/* @0x21b430 movw r1, #0x1004 */
/* @0x21b434 ldr r0, [r3, r6, lsl #2] */
/* @0x21b438 vcvt.f32.f64 s13, d8 */
/* @0x21b43c vstr s15, [sp] */
/* @0x21b440 vldr d7, [sp, #56] */
/* @0x21b444 vcvt.f32.f64 s15, d7 */
/* @0x21b448 vmov r2, s13 */
/* @0x21b44c vmov r3, s15 */
/* @0x21b450 bl 0xb6b2c <alSource3f@plt> */
/* @0x21b454 ldr r0, [r7] */
/* @0x21b458 mov r3, #0 */
/* @0x21b45c movw r1, #0x1006 */
/* @0x21b460 mov r2, r3 */
/* @0x21b464 ldr r0, [r0, r6, lsl #2] */
/* @0x21b468 str r3, [sp] */
/* @0x21b46c bl 0xb6b2c <alSource3f@plt> */
/* @0x21b470 bl 0xb6a54 <alGetError@plt> */
/* @0x21b474 subs r2, r0, #0 */
/* @0x21b478 bne 0x21b4ec <_Z17Audio_PlaySoundAtiddddddid+0x250> */
/* @0x21b47c mov r0, r8 */
/* @0x21b480 mov r1, r5 */
/* @0x21b484 bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise> */
/* @0x21b488 ldr r0, [r5, #0x14] */
/* @0x21b48c add sp, sp, #8 */
/* @0x21b490 vpop {d8, d9} */
/* @0x21b494 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b498 ldr r3, [pc, #0x11c] */
/* @0x21b49c mov r0, r9 */
/* @0x21b4a0 ldr r3, [r4, r3] */
/* @0x21b4a4 ldr r4, [r3] */
/* @0x21b4a8 ldr r3, [r4] */
/* @0x21b4ac ldr r6, [r3, #0xc] */
/* @0x21b4b0 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21b4b4 ldr r1, [pc, #0x104] */
/* @0x21b4b8 ldr r3, [r8, #0x4c] */
/* @0x21b4bc add r1, pc, r1 */
/* @0x21b4c0 mov r2, r0 */
/* @0x21b4c4 mov r0, r4 */
/* @0x21b4c8 blx r6 */
/* @0x21b4cc mov r0, r5 */
/* @0x21b4d0 add sp, sp, #8 */
/* @0x21b4d4 vpop {d8, d9} */
/* @0x21b4d8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b4dc mvn r0, #0 */
/* @0x21b4e0 add sp, sp, #8 */
/* @0x21b4e4 vpop {d8, d9} */
/* @0x21b4e8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b4ec ldr r3, [pc, #0xc8] */
/* @0x21b4f0 ldr r1, [pc, #0xcc] */
/* @0x21b4f4 ldr r3, [r4, r3] */
/* @0x21b4f8 add r1, pc, r1 */
/* @0x21b4fc ldr r0, [r3] */
/* @0x21b500 ldr r3, [r0] */
/* @0x21b504 ldr r3, [r3, #0xc] */
/* @0x21b508 blx r3 */
/* @0x21b50c b 0x21b47c <_Z17Audio_PlaySoundAtiddddddid+0x1e0> */
/* @0x21b510 ldr r3, [pc, #0xa4] */
/* @0x21b514 ldr r1, [pc, #0xac] */
/* @0x21b518 ldr r3, [r4, r3] */
/* @0x21b51c add r1, pc, r1 */
/* @0x21b520 ldr r0, [r3] */
/* @0x21b524 ldr r3, [r0] */
/* @0x21b528 ldr r3, [r3, #0xc] */
/* @0x21b52c blx r3 */
/* @0x21b530 b 0x21b3ec <_Z17Audio_PlaySoundAtiddddddid+0x150> */
/* @0x21b534 ldr r3, [pc, #0x80] */
/* @0x21b538 ldr r1, [pc, #0x8c] */
/* @0x21b53c ldr r3, [r4, r3] */
/* @0x21b540 add r1, pc, r1 */
/* @0x21b544 ldr r0, [r3] */
/* @0x21b548 ldr r3, [r0] */
/* @0x21b54c ldr r3, [r3, #0xc] */
/* @0x21b550 blx r3 */
/* @0x21b554 b 0x21b3c4 <_Z17Audio_PlaySoundAtiddddddid+0x128> */
/* @0x21b558 ldr r3, [pc, #0x5c] */
/* @0x21b55c ldr r1, [pc, #0x6c] */
/* @0x21b560 ldr r3, [r4, r3] */
/* @0x21b564 add r1, pc, r1 */
/* @0x21b568 ldr r0, [r3] */
/* @0x21b56c ldr r3, [r0] */
/* @0x21b570 ldr r3, [r3, #0xc] */
/* @0x21b574 blx r3 */
/* @0x21b578 b 0x21b374 <_Z17Audio_PlaySoundAtiddddddid+0xd8> */
/* @0x21b57c ldr r3, [pc, #0x38] */
/* @0x21b580 ldr r1, [pc, #0x4c] */
/* @0x21b584 ldr r3, [r4, r3] */
/* @0x21b588 add r1, pc, r1 */
/* @0x21b58c ldr r0, [r3] */
/* @0x21b590 ldr r3, [r0] */
/* @0x21b594 ldr r3, [r3, #0xc] */
/* @0x21b598 blx r3 */
/* @0x21b59c mov r0, r8 */
/* @0x21b5a0 b 0x21b48c <_Z17Audio_PlaySoundAtiddddddid+0x1f0> */
/* @0x21b5a4 mulseq sp, r8, r9 */
/* @0x21b5a8 .word 0xffffd3fc */
/* @0x21b5ac .word 0xffffd0e0 */
/* @0x21b5b0 .word 0xffffd400 */
/* @0x21b5b4 .word 0xfffff7a0 */
/* @0x21b5b8 .word 0xfffff77c */
/* @0x21b5bc .word 0xffffbac4 */
/* @0x21b5c0 mulseq r3, r8, r11 */
/* @0x21b5c4 ldrheq r8, [r3], -r8 */
/* @0x21b5c8 andseq r8, r3, r12, ror r11 */
/* @0x21b5cc andseq r8, r3, r0, lsl #12 */
/* @0x21b5d0 andseq r8, r3, r4, lsl r11 */
/* @0x21b5d4 andseq r8, r3, r4, lsr #21 */
/* @0x21b5d8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x21b5dc vpush {d8} */
/* @0x21b5e0 vmov d8, r2, r3 */
/* @0x21b5e4 ldr r5, [pc, #0x2a0] */
/* @0x21b5e8 sub sp, sp, #20 */
