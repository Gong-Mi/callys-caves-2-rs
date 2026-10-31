/* cally 逆向卡：CObjectGM::LoadFromChunk（原版 libyoyo.so，armv7）
 * @func 0x19d688 0x19d9f4  size 876  219 条
 * 级别: 骨架（§1 头部字段映射已由 oracle 钉住＝正文级；§2 版本门后的尾部仍是骨架）
 * 符号: _ZN9CObjectGM13LoadFromChunkEP8YYObjectPh → int LoadFromChunk(CObjectGM* dst, const uchar* src, ...)
 *
 * 这是**资源加载链**（game.droid → WAD 块 → OBJT 记录 → 运行时对象表）里的记录解析器。
 * 它决定「一个对象记录里的哪几个字节变成运行时的什么状态」，所以先把头部钉住，
 * 上面的资源加载分析才有依据。
 *
 * ── §1 头部：src+0x00..0x1f → dst（oracle 钉住，见 §3）────────────────────
 *   0x19d69c  bl CObjectGM::Clear()         先清 dst；清完 dst[0] 带 bit4(0x10)
 *   0x19d6a0  ldr r3,[src,#4]                sprite 索引
 *     0x19d6a8 tst r3,#0x70000000            置位 → 原样存 dst+4（0x19d6b0）
 *     否则：bit31 或进进程级累加字（0x19d6c8..0x19d6d4），dst+4 = v & 0x7FFFFFFF
 *   0x19d6d8  src+0x0c != 0 → dst[0] bit0   (solid)
 *   0x19d6f0  src+0x08 != 0 → dst[0] bit1   (visible)
 *   0x19d708  src+0x14 != 0 → dst[0] bit2   (persistent)
 *     三处都是 or/bic 到 dst[0] 的**既有值**上，不是整字覆盖 —— 写成 dst[0]=flags
 *     会把 Clear() 留下的 0x10 一起抹掉，102 例立刻分叉（mutant 5）。
 *   0x19d72c  str r3,[dst,#8]               dst+0x08 = src+0x10..0x13 (depth, int32 原样)
 *   0x19d734  dst+0x0c = src+0x18..0x1b
 *   0x19d738  dst+0x10 = src+0x1c..0x1f
 *   0x19d73c  dst[0x1c]=0 ; 0x19d740  dst+0x44=0 ; 0x19d744 dst+0x40=0
 *   返回 1（0x19d9a0 mov r0,#1）
 *
 * ── §2 版本门与尾部（骨架，未钉）──────────────────────────────────────────
 *   0x19d748..0x19d75c：从 pc 相对表取「数据版本」全局 → cmp #5
 *     ≤5 → src += 32，直接进 §3 的动作/事件链
 *     >5 → 读 src+0x20/0x24/0x28/0x2c/0x30/0x34/0x38/0x3c/0x40（sprite/掩码/包围盒一类）
 *          再 cmp #8 决定是否 src += 68 还是 80，然后 0x19d830 起解析 action 列表
 *   0x19d86c 起对每个 action 调 CEvent::LoadFromChunk（0xf2d84），长度用 MemoryManager::SetLength
 *   ⚠ 该版本字经未重定位的 pc 相对表读出，值不确定；>8 路径会通过它派生的指针写内存，
 *     在本 harness 里表现为 UC_ERR_WRITE_UNMAPPED。所以尾部没有进 oracle 输入域。
 *
 * ── §3 oracle 臂（2026-11-01）────────────────────────────────────────────
 *   harness/object_load_diff.py：原版 @0x19d688 vs c/object_load.c，104 例（单字节扫 4..0x1f、
 *   sprite 的 tag 位、三个 flag、depth 的 INT32_MIN/-1/-1000、src18/src1c、随机尾），
 *   逐例比返回值与 dst[0..0x20]。回执 receipts/object_load_diff-20261101T010319.json。
 *   104/104 identical；5 个变异体分别被 11/7/74/12/104 例抓住。
 *   输入域外的字节（src ≥ 0x20）全程保持 0，否则原件会走版本门后的路径。
 *
 * 未主张：版本门的比较对象取值域、src+0x20 起各字段的名字与语义、action 列表的布局 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d688 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19d68c sub sp, sp, #28
 *   @0x19d690 mov r4, r1
 *   @0x19d694 mov r5, r0
 *   @0x19d698 str r2, [sp, #0x4]
 *   @0x19d69c bl 0x19d3d8 <_ZN9CObjectGM5ClearEv>
 *   @0x19d6a0 ldr r3, [r4, #0x4]
 *   @0x19d6a4 ldr r11, [pc, #0x334]
 *   @0x19d6a8 tst r3, #1879048192
 *   @0x19d6ac add r11, pc, r11
 *   @0x19d6b0 strne r3, [r5, #0x4]
 *   @0x19d6b4 bne 0x19d6d8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x50>
 *   @0x19d6b8 ldr r2, [pc, #0x324]
 *   @0x19d6bc and r1, r3, #-2147483648
 *   @0x19d6c0 bic r3, r3, #-2147483648
 *   @0x19d6c4 ldr r2, [r11, r2]
 *   @0x19d6c8 str r3, [r5, #0x4]
 *   @0x19d6cc ldr r3, [r2]
 *   @0x19d6d0 orr r3, r1, r3
 *   @0x19d6d4 str r3, [r2]
 *   @0x19d6d8 ldr r3, [r4, #0xc]
 *   @0x19d6dc ldr r2, [r5]
 *   @0x19d6e0 cmp r3, #0
 *   @0x19d6e4 orrne r2, r2, #1
 *   @0x19d6e8 biceq r2, r2, #1
 *   @0x19d6ec str r2, [r5]
 *   @0x19d6f0 ldr r3, [r4, #0x8]
 *   @0x19d6f4 cmp r3, #0
 *   @0x19d6f8 orrne r2, r2, #2
 *   @0x19d6fc biceq r2, r2, #2
 *   @0x19d700 str r2, [r5]
 *   @0x19d704 mov r1, r2
 *   @0x19d708 ldr r2, [r4, #0x14]
 *   @0x19d70c ldr r3, [r4, #0x10]
 *   @0x19d710 cmp r2, #0
 *   @0x19d714 ldr r2, [pc, #0x2cc]
 *   @0x19d718 orrne r1, r1, #4
 *   @0x19d71c biceq r1, r1, #4
 *   @0x19d720 str r1, [r5]
 *   @0x19d724 ldr r0, [r4, #0x18]
 *   @0x19d728 ldr r1, [r4, #0x1c]
 *   @0x19d72c str r3, [r5, #0x8]
 *   @0x19d730 mov r3, #0
 *   @0x19d734 str r0, [r5, #0xc]
 *   @0x19d738 str r1, [r5, #0x10]
 *   @0x19d73c strb r3, [r5, #0x1c]
 *   @0x19d740 str r3, [r5, #0x44]
 *   @0x19d744 str r3, [r5, #0x40]
 *   @0x19d748 ldr r2, [r11, r2]
 *   @0x19d74c ldr r2, [r2]
 *   @0x19d750 cmp r2, #5
 *   @0x19d754 addle r4, r4, #32
 *   @0x19d758 strle r4, [sp, #0x14]
 *   @0x19d75c ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8>
 *   @0x19d760 ldr lr, [r4, #0x20]
 *   @0x19d764 ldr r12, [r4, #0x24]
 *   @0x19d768 adds lr, lr, #0
 *   @0x19d76c ldr r8, [r4, #0x2c]
 *   @0x19d770 ldr r7, [r4, #0x30]
 *   @0x19d774 movne lr, #1
 *   @0x19d778 adds r12, r12, #0
 *   @0x19d77c ldr r0, [r4, #0x28]
 *   @0x19d780 movne r12, #1
 *   @0x19d784 cmp r2, #8
 *   @0x19d788 ldr r2, [r4, #0x38]
 *   @0x19d78c ldr r1, [r4, #0x34]
 *   @0x19d790 ldr r6, [r4, #0x40]
 *   @0x19d794 str r2, [r5, #0x30]
 *   @0x19d798 ldr r2, [r4, #0x3c]
 *   @0x19d79c strb lr, [r5, #0x1c]
 *   @0x19d7a0 str r8, [r5, #0x28]
 *   @0x19d7a4 strb r12, [r5, #0x1d]
 *   @0x19d7a8 str r7, [r5, #0x2c]
 *   @0x19d7ac str r0, [r5, #0x20]
 *   @0x19d7b0 str r1, [r5, #0x24]
 *   @0x19d7b4 str r6, [r5, #0x40]
 *   @0x19d7b8 str r2, [r5, #0x34]
 *   @0x19d7bc bgt 0x19d9ac <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x324>
 *   @0x19d7c0 add r4, r4, #68
 *   @0x19d7c4 strb r3, [r5, #0x3d]
 *   @0x19d7c8 movw r2, #0xcccd
 *   @0x19d7cc mov r3, #1
 *   @0x19d7d0 movt r2, #0x3e4c
 *   @0x19d7d4 str r4, [sp, #0x14]
 *   @0x19d7d8 str r2, [r5, #0x38]
 *   @0x19d7dc strb r3, [r5, #0x3c]
 *   @0x19d7e0 lsl r4, r6, #3
 *   @0x19d7e4 mov r0, r4
 *   @0x19d7e8 bl 0xb6544 <malloc@plt>
 *   @0x19d7ec cmp r6, #0
 *   @0x19d7f0 str r0, [r5, #0x44]
 *   @0x19d7f4 ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8>
 *   @0x19d7f8 ldr r2, [sp, #0x14]
 *   @0x19d7fc mov r1, #0
 *   @0x19d800 ldr r3, [r2]
 *   @0x19d804 add r1, r1, #1
 *   @0x19d808 cmp r1, r6
 *   @0x19d80c add r2, r2, #8
 *   @0x19d810 add r0, r0, #8
 *   @0x19d814 str r3, [r0, #-0x8]
 *   @0x19d818 ldr r3, [r2, #-0x4]
 *   @0x19d81c str r3, [r0, #-0x4]
 *   @0x19d820 bne 0x19d800 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x178>
 *   @0x19d824 ldr r2, [sp, #0x14]
 *   @0x19d828 add r2, r2, r4
 *   @0x19d82c str r2, [sp, #0x14]
 *   @0x19d830 ldr r2, [sp, #0x14]
 *   @0x19d834 ldr r3, [r2]
 *   @0x19d838 cmp r3, #0
 *   @0x19d83c ble 0x19d9a0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x318>
 *   @0x19d840 ldr r2, [pc, #0x1a4]
 *   @0x19d844 add r5, r5, #80
 *   @0x19d848 mov r10, #0
 *   @0x19d84c add r2, pc, r2
 *   @0x19d850 str r2, [sp, #0xc]
 *   @0x19d854 mov r2, #0
 *   @0x19d858 str r2, [sp, #0x8]
 *   @0x19d85c ldr r2, [sp, #0x14]
 *   @0x19d860 str r2, [sp, #0x10]
 *   @0x19d864 ldr r2, [sp, #0x10]
 *   @0x19d868 ldr r8, [r2, #0x4]!
 *   @0x19d86c cmp r8, #0
 *   @0x19d870 str r2, [sp, #0x10]
 *   @0x19d874 moveq r7, #4
 *   @0x19d878 beq 0x19d890 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x208>
 *   @0x19d87c ldr r2, [pc, #0x16c]
 *   @0x19d880 ldr r2, [r11, r2]
 *   @0x19d884 ldr r2, [r2]
 *   @0x19d888 add r8, r2, r8
 *   @0x19d88c add r7, r8, #4
 *   @0x19d890 ldr r2, [r8]
 *   @0x19d894 cmp r2, #0
 *   @0x19d898 subgt r7, r7, #4
 *   @0x19d89c movgt r9, #0
 *   @0x19d8a0 bgt 0x19d8d4 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x24c>
 *   @0x19d8a4 b 0x19d988 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x300>
 *   @0x19d8a8 ldr r3, [r5]
 *   @0x19d8ac ldr r0, [r3, r1, lsl #2]
 *   @0x19d8b0 cmp r0, #0
 *   @0x19d8b4 beq 0x19d958 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2d0>
 *   @0x19d8b8 add r1, r6, #4
 *   @0x19d8bc ldr r2, [sp, #0x4]
 *   @0x19d8c0 bl 0xf2d84 <_ZN6CEvent13LoadFromChunkEP7YYEventPh>
 *   @0x19d8c4 ldr r3, [r8]
 *   @0x19d8c8 add r9, r9, #1
 *   @0x19d8cc cmp r3, r9
 *   @0x19d8d0 ble 0x19d980 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2f8>
 *   @0x19d8d4 ldr r6, [r7, #0x4]!
 *   @0x19d8d8 cmp r6, #0
 *   @0x19d8dc ldrne r3, [pc, #0x10c]
 *   @0x19d8e0 ldrne r3, [r11, r3]
 *   @0x19d8e4 ldrne r3, [r3]
 *   @0x19d8e8 addne r6, r3, r6
 *   @0x19d8ec ldr r1, [r6]
 *   @0x19d8f0 ldr r4, [r5, #-0x4]
 *   @0x19d8f4 cmp r1, r4
 *   @0x19d8f8 blt 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220>
 *   @0x19d8fc add r1, r1, #1
 *   @0x19d900 movw r3, #0x1b6
 *   @0x19d904 mov r0, r5
 *   @0x19d908 ldr r2, [sp, #0xc]
 *   @0x19d90c lsl r1, r1, #2
 *   @0x19d910 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19d914 ldr r1, [r6]
 *   @0x19d918 cmp r4, r1
 *   @0x19d91c add r3, r1, #1
 *   @0x19d920 str r3, [r5, #-0x4]
 *   @0x19d924 bge 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220>
 *   @0x19d928 lsl r3, r4, #2
 *   @0x19d92c add r4, r4, #1
 *   @0x19d930 ldr r2, [r5]
 *   @0x19d934 cmp r4, r1
 *   @0x19d938 str r10, [r2, r3]
 *   @0x19d93c add r3, r3, #4
 *   @0x19d940 bne 0x19d92c <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2a4>
 *   @0x19d944 ldr r3, [r5]
 *   @0x19d948 mov r1, r4
 *   @0x19d94c ldr r0, [r3, r1, lsl #2]
 *   @0x19d950 cmp r0, #0
 *   @0x19d954 bne 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230>
 *   @0x19d958 mov r0, #12
 *   @0x19d95c bl 0x27c524 <_Znwj>
 *   @0x19d960 mov r4, r0
 *   @0x19d964 bl 0xf2d0c <_ZN6CEventC2Ev>
 *   @0x19d968 ldr r3, [r6]
 *   @0x19d96c ldr r2, [r5]
 *   @0x19d970 str r4, [r2, r3, lsl #2]
 *   @0x19d974 ldr r2, [r5]
 *   @0x19d978 ldr r0, [r2, r3, lsl #2]
 *   @0x19d97c b 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230>
 *   @0x19d980 ldr r2, [sp, #0x14]
 *   @0x19d984 ldr r3, [r2]
 *   @0x19d988 ldr r2, [sp, #0x8]
 *   @0x19d98c add r5, r5, #8
 *   @0x19d990 add r2, r2, #1
 *   @0x19d994 str r2, [sp, #0x8]
 *   @0x19d998 cmp r3, r2
 *   @0x19d99c bgt 0x19d864 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1dc>
 *   @0x19d9a0 mov r0, #1
 *   @0x19d9a4 add sp, sp, #28
 *   @0x19d9a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19d9ac ldr r2, [r4, #0x48]
 *   @0x19d9b0 add r4, r4, #80
 *   @0x19d9b4 ldr r3, [r4, #-0x4]
 *   @0x19d9b8 adds r2, r2, #0
 *   @0x19d9bc ldr r1, [r4, #-0xc]
 *   @0x19d9c0 str r4, [sp, #0x14]
 *   @0x19d9c4 movne r2, #1
 *   @0x19d9c8 adds r3, r3, #0
 *   @0x19d9cc str r1, [r5, #0x38]
 *   @0x19d9d0 movne r3, #1
 *   @0x19d9d4 strb r2, [r5, #0x3c]
 *   @0x19d9d8 strb r3, [r5, #0x3d]
 *   @0x19d9dc b 0x19d7e0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x158>
 *   @0x19d9e0 eoreq r4, r5, r4, lsr #11
 *   @0x19d9e4 .word 0xffffe798
 *   @0x19d9e8 .word 0xffffea88
 *   @0x19d9ec mulseq r10, r4, r5
 *   @0x19d9f0 .word 0xffffbcf4
 */
