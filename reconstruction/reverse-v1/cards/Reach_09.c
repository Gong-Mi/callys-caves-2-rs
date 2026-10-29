/* cally 逆向卡：Reach_09 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 91 个函数｜锚点 7441 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/91 bindFBO  0x180908  size 380  95 条（0x180908..0x180a84）
 * @func 0x180908 0x180a84  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18094c→0x3f28a4, 0x180970→0x3f26dc, 0x180984→0x479c00, 0x1809d4→0x4a2f4c, 0x1809fc→0x4a2f48, 0x180a08→0x3f289c, 0x180a14→0x3f2898, 0x180a40→0x479b44
 * 调用序列: bindFBO(int, int, int)+0xcc / DBG_BIND_FRAMEBUFFER(int)
 * 字段偏移 top8: 0x8×4 / 0xc×3 / 0x148×1 / 0x130×1 / 0x10c×1 / 0xec×1 / 0xdc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180908 ldr r3, [pc, #0x148]
 *   @0x18090c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x180910 add r3, pc, r3
 *   @0x180914 add r8, r3, #4
 *   @0x180918 sub sp, sp, #20
 *   @0x18091c ldr r9, [r3]
 *   @0x180920 mov r7, r0
 *   @0x180924 ldr r4, [pc, #0x130]
 *   @0x180928 str r1, [sp, #0x8]
 *   @0x18092c rsb r9, r9, r9, lsl #3
 *   @0x180930 add r4, pc, r4
 *   @0x180934 str r2, [sp, #0xc]
 *   @0x180938 lsl r9, r9, #2
 *   @0x18093c add r10, r8, r9
 *   @0x180940 ldr r3, [r8, r9]
 *   @0x180944 cmp r3, #0
 *   @0x180948 beq 0x1809d4 <_Z7bindFBOiii+0xcc>
 *   @0x18094c ldr r3, [pc, #0x10c]
 *   @0x180950 ldr r11, [r4, r3]
 *   @0x180954 ldr r3, [r11]
 *   @0x180958 cmp r3, #1
 *   @0x18095c ble 0x1809d4 <_Z7bindFBOiii+0xcc>
 *   @0x180960 mov r6, r10
 *   @0x180964 movw r5, #0x8ce1
 *   @0x180968 ldr r3, [r6, #0x8]
 *   @0x18096c add r6, r6, #4
 *   @0x180970 ldr r12, [pc, #0xec]
 *   @0x180974 cmp r3, #0
 *   @0x180978 beq 0x1809bc <_Z7bindFBOiii+0xb4>
 *   @0x18097c ldr r12, [r4, r12]
 *   @0x180980 mov r1, r5
 *   @0x180984 ldr lr, [pc, #0xdc]
 *   @0x180988 movw r0, #0x8d40
 *   @0x18098c movw r2, #0xde1
 *   @0x180990 mov r3, #0
 *   @0x180994 ldr r12, [r12]
 *   @0x180998 cmp r12, #1
 *   @0x18099c beq 0x180a40 <_Z7bindFBOiii+0x138>
 *   @0x1809a0 ldr r12, [r4, lr]
 *   @0x1809a4 mov lr, #0
 *   @0x1809a8 str lr, [sp]
 *   @0x1809ac ldr r12, [r12]
 *   @0x1809b0 blx r12
 *   @0x1809b4 mov r1, #0
 *   @0x1809b8 str r1, [r6, #0x4]
 *   @0x1809bc sub r3, r5, #35840
 *   @0x1809c0 ldr r2, [r11]
 *   @0x1809c4 sub r3, r3, #223
 *   @0x1809c8 add r5, r5, #1
 *   @0x1809cc cmp r2, r3
 *   @0x1809d0 bgt 0x180968 <_Z7bindFBOiii+0x60>
 *   @0x1809d4 ldr r3, [pc, #0x90]
 *   @0x1809d8 mov r0, r7
 *   @0x1809dc ldr r1, [pc, #0x8c]
 *   @0x1809e0 movw r2, #0x172
 *   @0x1809e4 ldr r3, [r4, r3]
 *   @0x1809e8 add r1, pc, r1
 *   @0x1809ec stm r3, {r1, r2}
 *   @0x1809f0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x1809f4 ldr r1, [sp, #0x8]
 *   @0x1809f8 str r7, [r8, r9]
 *   @0x1809fc ldr r3, [pc, #0x70]
 *   @0x180a00 str r1, [r10, #0x14]
 *   @0x180a04 ldr r1, [sp, #0xc]
 *   @0x180a08 ldr r2, [pc, #0x68]
 *   @0x180a0c str r1, [r10, #0x18]
 *   @0x180a10 ldr r1, [r4, r3]
 *   @0x180a14 ldr r3, [pc, #0x60]
 *   @0x180a18 str r7, [r1]
 *   @0x180a1c ldr r1, [sp, #0x8]
 *   @0x180a20 ldr r2, [r4, r2]
 *   @0x180a24 str r1, [r2]
 *   @0x180a28 ldr r2, [sp, #0xc]
 *   @0x180a2c ldr r3, [r4, r3]
 *   @0x180a30 str r2, [r3]
 *   @0x180a34 add sp, sp, #20
 *   @0x180a38 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x180a3c b 0x180904 <_Z24_UpdateActiveDrawBuffersv>
 *   @0x180a40 ldr r12, [pc, #0x38]
 *   @0x180a44 ldr r12, [r4, r12]
 *   @0x180a48 str r3, [sp]
 *   @0x180a4c ldr r12, [r12]
 *   @0x180a50 blx r12
 *   @0x180a54 b 0x1809b4 <_Z7bindFBOiii+0xac>
 *   @0x180a58 eorseq r1, r2, r12, ror #21
 *   @0x180a5c eoreq r1, r7, r0, lsr #6
 *   @0x180a60 .word 0xffffe8e0
 *   @0x180a64 .word 0xffffe7b8
 *   @0x180a68 .word 0xffffbc7c
 *   @0x180a6c .word 0xffffe81c
 *   @0x180a70 ldrsbeq r10, [r12], -r4
 *   @0x180a74 .word 0xffffe820
 *   @0x180a78 .word 0xffffe834
 *   @0x180a7c .word 0xffffe838
 *   @0x180a80 .word 0xffffbb6c
 *
 * ══ §2/91 RTree<CInstance*, int, float, 6, 2>::InsertRect  0x1cd700  size 380  95 条（0x1cd700..0x1cd87c）
 * @func 0x1cd700 0x1cd87c  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_1cbc10+0x50×2 / RTree<CInstance*, int, float, 6, 2>::AddBranch(RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**)×2 / RTree<CInstance*, int, float, 6, 2>::InsertRectRec(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×7 / 0xc×4 / 0x8×4 / 0x10×2 / 0x30×2 / 0x1c×2 / 0x2×2 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cd700 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1cd704 sub sp, sp, #60
 *   @0x1cd708 mov r7, r2
 *   @0x1cd70c mov r8, r0
 *   @0x1cd710 str r3, [sp]
 *   @0x1cd714 add r3, sp, #28
 *   @0x1cd718 ldr r2, [r2]
 *   @0x1cd71c bl 0x1cd4bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i>
 *   @0x1cd720 cmp r0, #0
 *   @0x1cd724 bne 0x1cd730 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x30>
 *   @0x1cd728 add sp, sp, #60
 *   @0x1cd72c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1cd730 ldr r4, [r8, #0x4]
 *   @0x1cd734 ldr r6, [r4, #0x10]
 *   @0x1cd738 cmp r6, #0
 *   @0x1cd73c beq 0x1cd7dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0xdc>
 *   @0x1cd740 ldr r3, [r6]
 *   @0x1cd744 str r3, [r4, #0x10]
 *   @0x1cd748 ldr r1, [r7]
 *   @0x1cd74c add r4, sp, #8
 *   @0x1cd750 mov r9, #0
 *   @0x1cd754 mvn r3, #0
 *   @0x1cd758 str r9, [r6]
 *   @0x1cd75c mov r0, r4
 *   @0x1cd760 str r3, [r6, #0x4]
 *   @0x1cd764 add r5, sp, #32
 *   @0x1cd768 ldr r3, [r1, #0x4]
 *   @0x1cd76c add r3, r3, #1
 *   @0x1cd770 str r3, [r6, #0x4]
 *   @0x1cd774 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cd778 ldm r4, {r0, r1, r2, r3}
 *   @0x1cd77c ldr r12, [r7]
 *   @0x1cd780 stm r5, {r0, r1, r2, r3}
 *   @0x1cd784 mov r3, r9
 *   @0x1cd788 mov r2, r6
 *   @0x1cd78c mov r1, r5
 *   @0x1cd790 mov r0, r8
 *   @0x1cd794 str r12, [sp, #0x30]
 *   @0x1cd798 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_>
 *   @0x1cd79c mov r0, r4
 *   @0x1cd7a0 ldr r1, [sp, #0x1c]
 *   @0x1cd7a4 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cd7a8 ldm r4, {r0, r1, r2, r3}
 *   @0x1cd7ac ldr r12, [sp, #0x1c]
 *   @0x1cd7b0 stm r5, {r0, r1, r2, r3}
 *   @0x1cd7b4 mov r1, r5
 *   @0x1cd7b8 mov r3, r9
 *   @0x1cd7bc mov r0, r8
 *   @0x1cd7c0 mov r2, r6
 *   @0x1cd7c4 str r12, [sp, #0x30]
 *   @0x1cd7c8 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_>
 *   @0x1cd7cc mov r0, #1
 *   @0x1cd7d0 str r6, [r7]
 *   @0x1cd7d4 add sp, sp, #60
 *   @0x1cd7d8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1cd7dc ldr r3, [r4, #0xc]
 *   @0x1cd7e0 ldr r2, [r4]
 *   @0x1cd7e4 cmp r3, r2
 *   @0x1cd7e8 bge 0x1cd810 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x110>
 *   @0x1cd7ec ldr r0, [r4, #0x8]
 *   @0x1cd7f0 mov r6, #152
 *   @0x1cd7f4 ldr r2, [r4, #0x4]
 *   @0x1cd7f8 add r1, r3, #1
 *   @0x1cd7fc sub r0, r0, #-1073741823
 *   @0x1cd800 ldr r2, [r2, r0, lsl #2]
 *   @0x1cd804 str r1, [r4, #0xc]
 *   @0x1cd808 mla r6, r6, r3, r2
 *   @0x1cd80c b 0x1cd748 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x48>
 *   @0x1cd810 ldr r1, [r4, #0x8]
 *   @0x1cd814 mov r3, #74
 *   @0x1cd818 ldr r2, [pc, #0x58]
 *   @0x1cd81c add r1, r1, #1
 *   @0x1cd820 str r6, [r4, #0xc]
 *   @0x1cd824 add r2, pc, r2
 *   @0x1cd828 str r1, [r4, #0x8]
 *   @0x1cd82c ldr r0, [r4, #0x4]
 *   @0x1cd830 lsl r1, r1, #2
 *   @0x1cd834 str r6, [sp]
 *   @0x1cd838 mov r6, r2
 *   @0x1cd83c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1cd840 ldr r3, [r4]
 *   @0x1cd844 ldr r12, [r4, #0x8]
 *   @0x1cd848 mov r1, r6
 *   @0x1cd84c mov r2, #70
 *   @0x1cd850 sub r6, r12, #-1073741823
 *   @0x1cd854 mov r5, r0
 *   @0x1cd858 mov r0, #152
 *   @0x1cd85c mul r0, r0, r3
 *   @0x1cd860 str r5, [r4, #0x4]
 *   @0x1cd864 mov r3, #1
 *   @0x1cd868 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1cd86c ldr r3, [r4, #0xc]
 *   @0x1cd870 str r0, [r5, r6, lsl #2]
 *   @0x1cd874 b 0x1cd7ec <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0xec>
 *   @0x1cd878 andseq r3, r6, r12, lsl #16
 *
 * ══ §3/91 F_JSBooleanConstruct  0x2405dc  size 380  95 条（0x2405dc..0x240758）
 * @func 0x2405dc 0x240758  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×3 / YYObjectBase::InternalGetYYVar(int)×3 / F_JSBooleanConstruct(RValue&, CInstance*, CInstance*, int, RValue*)+0x30 / JS_ToBoolean(RValue&) / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, bool, int) / YYObjectBase::Alloc(unsigned int, int, bool) / YYObjectBase::Add(char const*, YYObjectBase*, int)
 * 字段偏移 top8: 0x28×3 / 0x4×3 / 0x18×2 / 0x8×2 / 0x114×1 / 0xf8×1 / 0xf4×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2405dc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2405e0 subs r5, r3, #0
 *   @0x2405e4 sub sp, sp, #12
 *   @0x2405e8 mov r6, r0
 *   @0x2405ec mov r9, r1
 *   @0x2405f0 mov r8, r2
 *   @0x2405f4 ldr r4, [sp, #0x28]
 *   @0x2405f8 movle r7, #0
 *   @0x2405fc ble 0x24060c <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x240600 mov r0, r4
 *   @0x240604 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x240608 mov r7, r0
 *   @0x24060c mov r2, r8
 *   @0x240610 mov r3, r5
 *   @0x240614 str r4, [sp]
 *   @0x240618 mov r1, r9
 *   @0x24061c mov r0, r6
 *   @0x240620 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x240624 ldr r3, [pc, #0x114]
 *   @0x240628 ldr r4, [r6]
 *   @0x24062c ldr r3, [pc, r3]
 *   @0x240630 ldr r1, [r3]
 *   @0x240634 mov r0, r4
 *   @0x240638 str r1, [r4, #0x18]
 *   @0x24063c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240640 ldr r12, [r4, #0x28]
 *   @0x240644 ldr r3, [pc, #0xf8]
 *   @0x240648 mov r2, r7
 *   @0x24064c ldr r1, [pc, #0xf4]
 *   @0x240650 orr r12, r12, #1
 *   @0x240654 add r3, pc, r3
 *   @0x240658 str r12, [r4, #0x28]
 *   @0x24065c mov r0, r4
 *   @0x240660 add r1, pc, r1
 *   @0x240664 str r3, [r4, #0x40]
 *   @0x240668 mov r3, #0
 *   @0x24066c bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi>
 *   @0x240670 ldr r3, [pc, #0xd4]
 *   @0x240674 mvn r1, #-16777216
 *   @0x240678 mov r2, #0
 *   @0x24067c ldr r3, [pc, r3]
 *   @0x240680 ldr r0, [r3]
 *   @0x240684 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x240688 ldr r1, [pc, #0xc0]
 *   @0x24068c ldr r2, [r6]
 *   @0x240690 mov r3, #6
 *   @0x240694 add r1, pc, r1
 *   @0x240698 mov r5, r0
 *   @0x24069c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2406a0 ldr r3, [pc, #0xac]
 *   @0x2406a4 mov r0, r5
 *   @0x2406a8 ldr r3, [pc, r3]
 *   @0x2406ac ldr r1, [r3]
 *   @0x2406b0 str r1, [r5, #0x18]
 *   @0x2406b4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2406b8 ldr r1, [r4, #0x4]
 *   @0x2406bc cmp r1, #0
 *   @0x2406c0 beq 0x2406f8 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x2406c4 str r5, [r1]
 *   @0x2406c8 mov r0, r4
 *   @0x2406cc mov r1, r5
 *   @0x2406d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2406d4 ldr r1, [r4, #0x4]
 *   @0x2406d8 cmp r1, #0
 *   @0x2406dc movne r3, #6
 *   @0x2406e0 strne r3, [r1, #0xc]
 *   @0x2406e4 beq 0x240708 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x2406e8 mov r3, #6
 *   @0x2406ec str r3, [r1, #0x8]
 *   @0x2406f0 add sp, sp, #12
 *   @0x2406f4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2406f8 mov r0, r4
 *   @0x2406fc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240700 mov r1, r0
 *   @0x240704 b 0x2406c4 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x240708 mov r0, r4
 *   @0x24070c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240710 ldr r1, [r4, #0x4]
 *   @0x240714 mov r3, #6
 *   @0x240718 cmp r1, #0
 *   @0x24071c str r3, [r0, #0xc]
 *   @0x240720 bne 0x2406e8 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x240724 mov r0, r4
 *   @0x240728 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24072c mov r3, #6
 *   @0x240730 mov r1, r0
 *   @0x240734 str r3, [r1, #0x8]
 *   @0x240738 add sp, sp, #12
 *   @0x24073c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x240740 ldrsheq r0, [r11], -r8
 *   @0x240744 ldrheq r4, [r1], -r4
 *   @0x240748 ldrheq r4, [r1], -r0
 *   @0x24074c mulseq r10, r8, r6
 *   @0x240750 mulseq r1, r0, lr
 *   @0x240754 ldrsheq sp, [r10], -r8
 *
 * ══ §4/91 b2Body::b2Body  0x2c6a80  size 380  95 条（0x2c6a80..0x2c6bfc）
 * @func 0x2c6a80 0x2c6bfc  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x18×2 / 0x27×1 / 0x4×1 / 0xc×1 / 0x26×1 / 0x24×1 / 0x25×1 / 0x28×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6a80 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c6a84 mov r5, r1
 *   @0x2c6a88 ldrb r3, [r1, #0x27]
 *   @0x2c6a8c mov r1, #0
 *   @0x2c6a90 strh r1, [r0, #4]
 *   @0x2c6a94 mov r4, r0
 *   @0x2c6a98 cmp r3, r1
 *   @0x2c6a9c ldr r7, [r5, #0xc]
 *   @0x2c6aa0 add r6, r4, #12
 *   @0x2c6aa4 add r8, r4, #28
 *   @0x2c6aa8 movne r3, #8
 *   @0x2c6aac strhne r3, [r0, #4]
 *   @0x2c6ab0 ldrb r3, [r5, #0x26]
 *   @0x2c6ab4 add r11, r4, #52
 *   @0x2c6ab8 add r10, r4, #60
 *   @0x2c6abc add r9, r5, #16
 *   @0x2c6ac0 cmp r3, #0
 *   @0x2c6ac4 ldrhne r3, [r0, #4]
 *   @0x2c6ac8 orrne r3, r3, #16
 *   @0x2c6acc strhne r3, [r0, #4]
 *   @0x2c6ad0 ldrb r3, [r5, #0x24]
 *   @0x2c6ad4 cmp r3, #0
 *   @0x2c6ad8 ldrhne r3, [r0, #4]
 *   @0x2c6adc orrne r3, r3, #4
 *   @0x2c6ae0 strhne r3, [r0, #4]
 *   @0x2c6ae4 ldrb r3, [r5, #0x25]
 *   @0x2c6ae8 cmp r3, #0
 *   @0x2c6aec ldrhne r3, [r0, #4]
 *   @0x2c6af0 orrne r3, r3, #2
 *   @0x2c6af4 strhne r3, [r0, #4]
 *   @0x2c6af8 ldrb r3, [r5, #0x28]
 *   @0x2c6afc cmp r3, #0
 *   @0x2c6b00 ldrhne r3, [r0, #4]
 *   @0x2c6b04 orrne r3, r3, #32
 *   @0x2c6b08 strhne r3, [r0, #4]
 *   @0x2c6b0c ldmib r5, {r0, r1}
 *   @0x2c6b10 str r2, [r4, #0x68]
 *   @0x2c6b14 stm r6, {r0, r1}
 *   @0x2c6b18 mov r0, r7
 *   @0x2c6b1c bl 0xb6580 <sinf@plt>
 *   @0x2c6b20 str r0, [r4, #0x14]
 *   @0x2c6b24 mov r0, r7
 *   @0x2c6b28 bl 0xb658c <cosf@plt>
 *   @0x2c6b2c vldr s15, [pc, #196]
 *   @0x2c6b30 mov r12, #0
 *   @0x2c6b34 str r0, [r4, #0x18]
 *   @0x2c6b38 ldm r6, {r0, r1, r2, r3}
 *   @0x2c6b3c stm r8, {r0, r1, r2, r3}
 *   @0x2c6b40 vstr s15, [r4, #44]
 *   @0x2c6b44 vstr s15, [r4, #48]
 *   @0x2c6b48 add r3, r4, #80
 *   @0x2c6b4c ldm r6, {r0, r1}
 *   @0x2c6b50 stm r11, {r0, r1}
 *   @0x2c6b54 ldm r6, {r0, r1}
 *   @0x2c6b58 stm r10, {r0, r1}
 *   @0x2c6b5c str r7, [r4, #0x44]
 *   @0x2c6b60 ldm r9, {r0, r1}
 *   @0x2c6b64 vstr s15, [r4, #76]
 *   @0x2c6b68 ldr r2, [r5, #0x18]
 *   @0x2c6b6c str r7, [r4, #0x48]
 *   @0x2c6b70 str r12, [r4, #0x7c]
 *   @0x2c6b74 str r12, [r4, #0x80]
 *   @0x2c6b78 str r12, [r4, #0x6c]
 *   @0x2c6b7c str r12, [r4, #0x70]
 *   @0x2c6b80 stm r3, {r0, r1}
 *   @0x2c6b84 mov r0, r4
 *   @0x2c6b88 ldr r3, [r5]
 *   @0x2c6b8c ldr r1, [r5, #0x1c]
 *   @0x2c6b90 str r2, [r4, #0x58]
 *   @0x2c6b94 cmp r3, #2
 *   @0x2c6b98 ldr r2, [r5, #0x20]
 *   @0x2c6b9c str r1, [r4, #0x94]
 *   @0x2c6ba0 ldr r1, [r5, #0x2c]
 *   @0x2c6ba4 str r2, [r4, #0x98]
 *   @0x2c6ba8 ldr r2, [r5, #0x30]
 *   @0x2c6bac vstr s15, [r4, #92]
 *   @0x2c6bb0 str r3, [r4]
 *   @0x2c6bb4 vstr s15, [r4, #96]
 *   @0x2c6bb8 moveq r3, #1065353216
 *   @0x2c6bbc vstr s15, [r4, #100]
 *   @0x2c6bc0 str r2, [r4, #0x9c]
 *   @0x2c6bc4 vstr s15, [r4, #160]
 *   @0x2c6bc8 streq r3, [r4, #0x84]
 *   @0x2c6bcc mov r2, #0
 *   @0x2c6bd0 streq r3, [r4, #0x88]
 *   @0x2c6bd4 vstrne s15, [r4, #132]
 *   @0x2c6bd8 mov r3, #0
 *   @0x2c6bdc vstrne s15, [r4, #136]
 *   @0x2c6be0 str r2, [r4, #0x8c]
 *   @0x2c6be4 str r2, [r4, #0x90]
 *   @0x2c6be8 str r3, [r4, #0x74]
 *   @0x2c6bec str r1, [r4, #0xa4]
 *   @0x2c6bf0 str r3, [r4, #0x78]
 *   @0x2c6bf4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c6bf8 andeq r0, r0, r0
 *
 * ══ §5/91 CSkeletonSprite::Draw  0xc0244  size 376  94 条（0xc0244..0xc03bc）
 * @func 0xc0244 0xc03bc  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation()×2 / 0xb6574×2 / spBone_setYDown / CSkeletonInstance::GetAnimation(int) const / CSkeletonInstance::GetSkin() const / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonSprite::DrawSkeleton(spSkeleton*, unsigned int, float) / CSkeletonInstance::~CSkeletonInstance()
 * 字段偏移 top8: 0x14×3 / 0x10×2 / 0x64×1 / 0x6c×1 / 0x50×1 / 0x54×1 / 0x68×1 / 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc0244 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc0248 vpush {d8, d9}
 *   @0xc024c sub sp, sp, #28
 *   @0xc0250 vldr s16, [sp, #88]
 *   @0xc0254 mov r8, r3
 *   @0xc0258 mov r7, r0
 *   @0xc025c ldr r3, [sp, #0x64]
 *   @0xc0260 mov r0, #1
 *   @0xc0264 ldr r4, [sp, #0x6c]
 *   @0xc0268 mov r5, r1
 *   @0xc026c mov r6, r2
 *   @0xc0270 ldr r9, [sp, #0x50]
 *   @0xc0274 ldr r10, [sp, #0x54]
 *   @0xc0278 vldr s17, [sp, #92]
 *   @0xc027c vldr s18, [sp, #96]
 *   @0xc0280 str r3, [sp, #0x10]
 *   @0xc0284 ldr r11, [sp, #0x68]
 *   @0xc0288 bl 0x284ed8 <spBone_setYDown>
 *   @0xc028c cmp r4, #0
 *   @0xc0290 beq 0xc0368 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x124>
 *   @0xc0294 mov r0, r4
 *   @0xc0298 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0xc029c cmp r0, #0
 *   @0xc02a0 beq 0xc0368 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x124>
 *   @0xc02a4 mov r0, r4
 *   @0xc02a8 mov r3, #0
 *   @0xc02ac str r3, [sp, #0x14]
 *   @0xc02b0 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0xc02b4 cmp r5, #0
 *   @0xc02b8 mov r4, r0
 *   @0xc02bc beq 0xc038c <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x148>
 *   @0xc02c0 mov r1, #0
 *   @0xc02c4 mov r0, r4
 *   @0xc02c8 bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi>
 *   @0xc02cc mov r1, r5
 *   @0xc02d0 bl 0xb6574 <strcmp@plt>
 *   @0xc02d4 cmp r0, #0
 *   @0xc02d8 bne 0xc038c <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x148>
 *   @0xc02dc cmp r6, #0
 *   @0xc02e0 beq 0xc03a0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x15c>
 *   @0xc02e4 mov r0, r4
 *   @0xc02e8 bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv>
 *   @0xc02ec mov r1, r6
 *   @0xc02f0 bl 0xb6574 <strcmp@plt>
 *   @0xc02f4 cmp r0, #0
 *   @0xc02f8 bne 0xc03a0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x15c>
 *   @0xc02fc mov r1, r8
 *   @0xc0300 mov r12, #0
 *   @0xc0304 vstr s16, [sp]
 *   @0xc0308 vstr s17, [sp, #4]
 *   @0xc030c vstr s18, [sp, #8]
 *   @0xc0310 mov r2, r9
 *   @0xc0314 mov r3, r10
 *   @0xc0318 mov r0, r4
 *   @0xc031c str r12, [sp, #0xc]
 *   @0xc0320 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xc0324 ldr r1, [r4, #0x1c]
 *   @0xc0328 cmp r1, #0
 *   @0xc032c beq 0xc0340 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xfc>
 *   @0xc0330 mov r0, r7
 *   @0xc0334 ldr r2, [sp, #0x10]
 *   @0xc0338 mov r3, r11
 *   @0xc033c bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf>
 *   @0xc0340 ldr r3, [sp, #0x14]
 *   @0xc0344 cmp r3, #0
 *   @0xc0348 beq 0xc03b0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x16c>
 *   @0xc034c mov r0, r4
 *   @0xc0350 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev>
 *   @0xc0354 mov r0, r4
 *   @0xc0358 add sp, sp, #28
 *   @0xc035c vpop {d8, d9}
 *   @0xc0360 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc0364 b 0x27d1d0 <_ZdlPv>
 *   @0xc0368 mov r0, #52
 *   @0xc036c mov r3, #1
 *   @0xc0370 str r3, [sp, #0x14]
 *   @0xc0374 bl 0x27c524 <_Znwj>
 *   @0xc0378 mov r1, r7
 *   @0xc037c mov r4, r0
 *   @0xc0380 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite>
 *   @0xc0384 cmp r5, #0
 *   @0xc0388 bne 0xc02c0 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0x7c>
 *   @0xc038c mov r1, r5
 *   @0xc0390 mov r0, r4
 *   @0xc0394 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xc0398 cmp r6, #0
 *   @0xc039c bne 0xc02e4 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xa0>
 *   @0xc03a0 mov r1, r6
 *   @0xc03a4 mov r0, r4
 *   @0xc03a8 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0xc03ac b 0xc02fc <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance+0xb8>
 *   @0xc03b0 add sp, sp, #28
 *   @0xc03b4 vpop {d8, d9}
 *   @0xc03b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §6/91 ParticleSystem_Particles_Create  0x1a3b78  size 376  94 条（0x1a3b78..0x1a3cf0）
 * @func 0x1a3b78 0x1a3cf0  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a3bb8→0x542460, 0x1a3ca0→0x3eb70c, 0x1a3cc8→0x3eb70c
 * 调用序列: ParticleSystem_Particles_Create(int, float, float, int, int)+0x144×2 / ParticleSystem_Exists(int) / ParticleType_Exists(int) / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CreateParticle(float, float, int, RParticle&) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x2×3 / 0x40×2 / 0x30×1 / 0x134×1 / 0x118×1 / 0x104×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3b78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a3b7c sub sp, sp, #12
 *   @0x1a3b80 mov r8, r1
 *   @0x1a3b84 mov r6, r3
 *   @0x1a3b88 mov r9, r2
 *   @0x1a3b8c mov r5, r0
 *   @0x1a3b90 ldr r7, [sp, #0x30]
 *   @0x1a3b94 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a3b98 ldr r4, [pc, #0x134]
 *   @0x1a3b9c add r4, pc, r4
 *   @0x1a3ba0 cmp r0, #0
 *   @0x1a3ba4 beq 0x1a3c9c <_Z31ParticleSystem_Particles_Createiffii+0x124>
 *   @0x1a3ba8 mov r0, r6
 *   @0x1a3bac bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3bb0 cmp r0, #0
 *   @0x1a3bb4 beq 0x1a3cc4 <_Z31ParticleSystem_Particles_Createiffii+0x14c>
 *   @0x1a3bb8 ldr r3, [pc, #0x118]
 *   @0x1a3bbc cmp r7, #0
 *   @0x1a3bc0 ldr r3, [r4, r3]
 *   @0x1a3bc4 ldr r3, [r3, #0x4]
 *   @0x1a3bc8 ldr r4, [r3, r5, lsl #2]
 *   @0x1a3bcc ble 0x1a3cbc <_Z31ParticleSystem_Particles_Createiffii+0x144>
 *   @0x1a3bd0 ldr r3, [pc, #0x104]
 *   @0x1a3bd4 mov r5, #1
 *   @0x1a3bd8 ldr r10, [pc, #0x100]
 *   @0x1a3bdc add r3, pc, r3
 *   @0x1a3be0 str r3, [sp, #0x4]
 *   @0x1a3be4 add r10, pc, r10
 *   @0x1a3be8 add r3, r4, #4
 *   @0x1a3bec str r3, [sp]
 *   @0x1a3bf0 b 0x1a3c64 <_Z31ParticleSystem_Particles_Createiffii+0xec>
 *   @0x1a3bf4 ldr r2, [r4, #0x4]
 *   @0x1a3bf8 add r1, r3, #1073741824
 *   @0x1a3bfc add r3, r3, #1
 *   @0x1a3c00 str r3, [r4, #0x8]
 *   @0x1a3c04 add r11, r2, r1, lsl #2
 *   @0x1a3c08 ldr r0, [r2, r1, lsl #2]
 *   @0x1a3c0c cmp r0, #0
 *   @0x1a3c10 beq 0x1a3c24 <_Z31ParticleSystem_Particles_Createiffii+0xac>
 *   @0x1a3c14 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a3c18 ldmib r4, {r3, r12}
 *   @0x1a3c1c sub r12, r12, #-1073741823
 *   @0x1a3c20 add r11, r3, r12, lsl #2
 *   @0x1a3c24 mov r1, r10
 *   @0x1a3c28 movw r2, #0x586
 *   @0x1a3c2c mov r3, #1
 *   @0x1a3c30 mov r0, #64
 *   @0x1a3c34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a3c38 ldr lr, [r4, #0x8]
 *   @0x1a3c3c mov r1, r9
 *   @0x1a3c40 mov r2, r6
 *   @0x1a3c44 sub lr, lr, #-1073741823
 *   @0x1a3c48 str r0, [r11]
 *   @0x1a3c4c mov r0, r8
 *   @0x1a3c50 ldr r3, [r4, #0x4]
 *   @0x1a3c54 ldr r3, [r3, lr, lsl #2]
 *   @0x1a3c58 bl 0x1a2e5c <_Z14CreateParticleffiR9RParticle>
 *   @0x1a3c5c cmp r7, r5
 *   @0x1a3c60 blt 0x1a3cbc <_Z31ParticleSystem_Particles_Createiffii+0x144>
 *   @0x1a3c64 ldr r3, [r4, #0x8]
 *   @0x1a3c68 add r5, r5, #1
 *   @0x1a3c6c ldr r2, [r4]
 *   @0x1a3c70 cmp r2, r3
 *   @0x1a3c74 bgt 0x1a3bf4 <_Z31ParticleSystem_Particles_Createiffii+0x7c>
 *   @0x1a3c78 add r1, r3, #100
 *   @0x1a3c7c ldm sp, {r0, r2}
 *   @0x1a3c80 movw r3, #0x57e
 *   @0x1a3c84 lsl r1, r1, #2
 *   @0x1a3c88 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a3c8c ldr r3, [r4, #0x8]
 *   @0x1a3c90 add r2, r3, #100
 *   @0x1a3c94 str r2, [r4]
 *   @0x1a3c98 b 0x1a3bf4 <_Z31ParticleSystem_Particles_Createiffii+0x7c>
 *   @0x1a3c9c ldr r1, [pc, #0x40]
 *   @0x1a3ca0 ldr r3, [pc, #0x40]
 *   @0x1a3ca4 add r1, pc, r1
 *   @0x1a3ca8 ldr r3, [r4, r3]
 *   @0x1a3cac ldr r0, [r3]
 *   @0x1a3cb0 ldr r3, [r0]
 *   @0x1a3cb4 ldr r3, [r3, #0xc]
 *   @0x1a3cb8 blx r3
 *   @0x1a3cbc add sp, sp, #12
 *   @0x1a3cc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a3cc4 ldr r1, [pc, #0x20]
 *   @0x1a3cc8 ldr r3, [pc, #0x18]
 *   @0x1a3ccc add r1, pc, r1
 *   @0x1a3cd0 b 0x1a3ca8 <_Z31ParticleSystem_Particles_Createiffii+0x130>
 *   @0x1a3cd4 strhteq lr, [r4], -r4
 *   @0x1a3cd8 .word 0xffffeb68
 *   @0x1a3cdc andseq r9, r10, r4, lsr #7
 *   @0x1a3ce0 mulseq r10, r12, r3
 *   @0x1a3ce4 andseq r9, r10, r8, lsl #7
 *   @0x1a3ce8 .word 0xffffbac4
 *   @0x1a3cec mulseq r10, r12, r3
 *
 * ══ §7/91 HandleButton  0x1d5e70  size 376  94 条（0x1d5e70..0x1d5fe8）
 * @func 0x1d5e70 0x1d5fe8  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5e74→0x536f20, 0x1d5e88→0x536f70, 0x1d5eb8→0x53ab70, 0x1d5ec0→0x542374
 * 调用序列: HandleButton(int)+0x158 / HandleButton(int)+0xb8 / CInstance::Collision_Point(float, float, bool) / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0xc×3 / 0x2×3 / 0x4×3 / 0x8×3 / 0x158×2 / 0x118×2 / 0x148×1 / 0x11c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5e70 ldr r1, [pc, #0x158]
 *   @0x1d5e74 ldr r3, [pc, #0x158]
 *   @0x1d5e78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5e7c add r1, pc, r1
 *   @0x1d5e80 sub sp, sp, #20
 *   @0x1d5e84 add r7, r0, #1536
 *   @0x1d5e88 ldr r12, [pc, #0x148]
 *   @0x1d5e8c str r0, [sp, #0xc]
 *   @0x1d5e90 ldr r0, [r1, r3]
 *   @0x1d5e94 ldrd r2, r3, [r0]
 *   @0x1d5e98 strd r2, r3, [sp]
 *   @0x1d5e9c adds r2, r2, #1
 *   @0x1d5ea0 adc r3, r3, #0
 *   @0x1d5ea4 strd r2, r3, [r0]
 *   @0x1d5ea8 ldr r8, [r1, r12]
 *   @0x1d5eac ldr r3, [r8, r7, lsl #2]
 *   @0x1d5eb0 cmp r3, #0
 *   @0x1d5eb4 ble 0x1d5fc8 <_Z12HandleButtoni+0x158>
 *   @0x1d5eb8 ldr r2, [pc, #0x11c]
 *   @0x1d5ebc mov r6, #0
 *   @0x1d5ec0 ldr r3, [pc, #0x118]
 *   @0x1d5ec4 ldr r11, [pc, #0x118]
 *   @0x1d5ec8 ldr r9, [r1, r2]
 *   @0x1d5ecc ldr r10, [r1, r3]
 *   @0x1d5ed0 add r11, pc, r11
 *   @0x1d5ed4 add r9, r9, r7, lsl #3
 *   @0x1d5ed8 ldr r3, [r10]
 *   @0x1d5edc ldr r1, [r9, #0x4]
 *   @0x1d5ee0 ldr r2, [r3, #0x4]
 *   @0x1d5ee4 ldr r1, [r1, r6, lsl #2]
 *   @0x1d5ee8 ldr r3, [r3]
 *   @0x1d5eec and r2, r1, r2
 *   @0x1d5ef0 ldr r3, [r3, r2, lsl #3]
 *   @0x1d5ef4 cmp r3, #0
 *   @0x1d5ef8 bne 0x1d5f0c <_Z12HandleButtoni+0x9c>
 *   @0x1d5efc b 0x1d5fb8 <_Z12HandleButtoni+0x148>
 *   @0x1d5f00 ldr r3, [r3, #0x4]
 *   @0x1d5f04 cmp r3, #0
 *   @0x1d5f08 beq 0x1d5fb8 <_Z12HandleButtoni+0x148>
 *   @0x1d5f0c ldr r2, [r3, #0x8]
 *   @0x1d5f10 cmp r1, r2
 *   @0x1d5f14 bne 0x1d5f00 <_Z12HandleButtoni+0x90>
 *   @0x1d5f18 ldr r3, [r3, #0xc]
 *   @0x1d5f1c cmp r3, #0
 *   @0x1d5f20 ldrne r4, [r3, #0xc4]
 *   @0x1d5f24 beq 0x1d5fb8 <_Z12HandleButtoni+0x148>
 *   @0x1d5f28 cmp r4, #0
 *   @0x1d5f2c beq 0x1d5fb8 <_Z12HandleButtoni+0x148>
 *   @0x1d5f30 ldr r3, [r4, #0x8]
 *   @0x1d5f34 cmp r3, #0
 *   @0x1d5f38 beq 0x1d5fb8 <_Z12HandleButtoni+0x148>
 *   @0x1d5f3c ldr r5, [r4, #0x8]
 *   @0x1d5f40 ldr r4, [r4]
 *   @0x1d5f44 ldrb r3, [r5, #0x68]
 *   @0x1d5f48 cmp r3, #0
 *   @0x1d5f4c bne 0x1d5f28 <_Z12HandleButtoni+0xb8>
 *   @0x1d5f50 ldrb r3, [r5, #0x69]
 *   @0x1d5f54 cmp r3, #0
 *   @0x1d5f58 bne 0x1d5f28 <_Z12HandleButtoni+0xb8>
 *   @0x1d5f5c ldrd r2, r3, [r5, #112]
 *   @0x1d5f60 ldrd r0, r1, [sp]
 *   @0x1d5f64 cmp r0, r2
 *   @0x1d5f68 sbcs r1, r1, r3
 *   @0x1d5f6c blt 0x1d5f28 <_Z12HandleButtoni+0xb8>
 *   @0x1d5f70 vldr s15, [r11, #4]
 *   @0x1d5f74 vcvt.f32.s32 s15, s15
 *   @0x1d5f78 mov r3, #1
 *   @0x1d5f7c mov r0, r5
 *   @0x1d5f80 vmov r2, s15
 *   @0x1d5f84 vldr s15, [r11]
 *   @0x1d5f88 vcvt.f32.s32 s15, s15
 *   @0x1d5f8c vmov r1, s15
 *   @0x1d5f90 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x1d5f94 cmp r0, #0
 *   @0x1d5f98 beq 0x1d5f28 <_Z12HandleButtoni+0xb8>
 *   @0x1d5f9c mov r2, #6
 *   @0x1d5fa0 mov r0, r5
 *   @0x1d5fa4 ldr r3, [sp, #0xc]
 *   @0x1d5fa8 mov r1, r5
 *   @0x1d5fac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d5fb0 cmp r4, #0
 *   @0x1d5fb4 bne 0x1d5f30 <_Z12HandleButtoni+0xc0>
 *   @0x1d5fb8 ldr r3, [r8, r7, lsl #2]
 *   @0x1d5fbc add r6, r6, #1
 *   @0x1d5fc0 cmp r3, r6
 *   @0x1d5fc4 bgt 0x1d5ed8 <_Z12HandleButtoni+0x68>
 *   @0x1d5fc8 add sp, sp, #20
 *   @0x1d5fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d5fd0 .word 0x0021bdd4
 *   @0x1d5fd4 .word 0xffffdeb4
 *   @0x1d5fd8 .word 0xffffdeb8
 *   @0x1d5fdc .word 0xffffdebc
 *   @0x1d5fe0 .word 0xffffbfec
 *   @0x1d5fe4 eorseq lr, r6, r0, lsr #23
 *
 * ══ §8/91 KindName  0xce54c  size 372  93 条（0xce54c..0xce6c0）
 * @func 0xce54c 0xce6c0  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_IsCallable_Object(YYObjectBase*)
 * 字段偏移 top8: 0xc×1 / 0xd4×1 / 0xcc×1 / 0xc4×1 / 0xbc×1 / 0xb4×1 / 0xac×1 / 0x94×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce54c push {r3, lr}
 *   @0xce550 ldr r3, [r0, #0xc]
 *   @0xce554 bic r3, r3, #-16777216
 *   @0xce558 cmp r3, #14
 *   @0xce55c addls pc, pc, r3, lsl #2
 *   @0xce560 b 0xce664 <_Z8KindNamePK6RValue+0x118>
 *   @0xce564 b 0xce5a0 <_Z8KindNamePK6RValue+0x54>
 *   @0xce568 b 0xce5ac <_Z8KindNamePK6RValue+0x60>
 *   @0xce56c b 0xce5b8 <_Z8KindNamePK6RValue+0x6c>
 *   @0xce570 b 0xce5c4 <_Z8KindNamePK6RValue+0x78>
 *   @0xce574 b 0xce5d0 <_Z8KindNamePK6RValue+0x84>
 *   @0xce578 b 0xce5dc <_Z8KindNamePK6RValue+0x90>
 *   @0xce57c b 0xce5e8 <_Z8KindNamePK6RValue+0x9c>
 *   @0xce580 b 0xce604 <_Z8KindNamePK6RValue+0xb8>
 *   @0xce584 b 0xce610 <_Z8KindNamePK6RValue+0xc4>
 *   @0xce588 b 0xce61c <_Z8KindNamePK6RValue+0xd0>
 *   @0xce58c b 0xce628 <_Z8KindNamePK6RValue+0xdc>
 *   @0xce590 b 0xce634 <_Z8KindNamePK6RValue+0xe8>
 *   @0xce594 b 0xce640 <_Z8KindNamePK6RValue+0xf4>
 *   @0xce598 b 0xce64c <_Z8KindNamePK6RValue+0x100>
 *   @0xce59c b 0xce658 <_Z8KindNamePK6RValue+0x10c>
 *   @0xce5a0 ldr r0, [pc, #0xd4]
 *   @0xce5a4 add r0, pc, r0
 *   @0xce5a8 pop {r3, pc}
 *   @0xce5ac ldr r0, [pc, #0xcc]
 *   @0xce5b0 add r0, pc, r0
 *   @0xce5b4 pop {r3, pc}
 *   @0xce5b8 ldr r0, [pc, #0xc4]
 *   @0xce5bc add r0, pc, r0
 *   @0xce5c0 pop {r3, pc}
 *   @0xce5c4 ldr r0, [pc, #0xbc]
 *   @0xce5c8 add r0, pc, r0
 *   @0xce5cc pop {r3, pc}
 *   @0xce5d0 ldr r0, [pc, #0xb4]
 *   @0xce5d4 add r0, pc, r0
 *   @0xce5d8 pop {r3, pc}
 *   @0xce5dc ldr r0, [pc, #0xac]
 *   @0xce5e0 add r0, pc, r0
 *   @0xce5e4 pop {r3, pc}
 *   @0xce5e8 ldr r0, [r0]
 *   @0xce5ec bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0xce5f0 cmp r0, #0
 *   @0xce5f4 beq 0xce670 <_Z8KindNamePK6RValue+0x124>
 *   @0xce5f8 ldr r0, [pc, #0x94]
 *   @0xce5fc add r0, pc, r0
 *   @0xce600 pop {r3, pc}
 *   @0xce604 ldr r0, [pc, #0x8c]
 *   @0xce608 add r0, pc, r0
 *   @0xce60c pop {r3, pc}
 *   @0xce610 ldr r0, [pc, #0x84]
 *   @0xce614 add r0, pc, r0
 *   @0xce618 pop {r3, pc}
 *   @0xce61c ldr r0, [pc, #0x7c]
 *   @0xce620 add r0, pc, r0
 *   @0xce624 pop {r3, pc}
 *   @0xce628 ldr r0, [pc, #0x74]
 *   @0xce62c add r0, pc, r0
 *   @0xce630 pop {r3, pc}
 *   @0xce634 ldr r0, [pc, #0x6c]
 *   @0xce638 add r0, pc, r0
 *   @0xce63c pop {r3, pc}
 *   @0xce640 ldr r0, [pc, #0x64]
 *   @0xce644 add r0, pc, r0
 *   @0xce648 pop {r3, pc}
 *   @0xce64c ldr r0, [pc, #0x5c]
 *   @0xce650 add r0, pc, r0
 *   @0xce654 pop {r3, pc}
 *   @0xce658 ldr r0, [pc, #0x54]
 *   @0xce65c add r0, pc, r0
 *   @0xce660 pop {r3, pc}
 *   @0xce664 ldr r0, [pc, #0x4c]
 *   @0xce668 add r0, pc, r0
 *   @0xce66c pop {r3, pc}
 *   @0xce670 ldr r0, [pc, #0x44]
 *   @0xce674 add r0, pc, r0
 *   @0xce678 pop {r3, pc}
 *   @0xce67c eoreq r3, r6, r4, lsr #25
 *   @0xce680 eoreq r2, r6, r8, ror r2
 *   @0xce684 mlaeq r6, r4, r12, r3
 *   @0xce688 eoreq r3, r6, r4, lsr #25
 *   @0xce68c eoreq r3, r6, r12, lsr #25
 *   @0xce690 eoreq r3, r6, r0, lsl #25
 *   @0xce694 eoreq r3, r6, r4, lsr r12
 *   @0xce698 eoreq r3, r6, r0, asr r12
 *   @0xce69c eoreq r3, r6, r4, ror r12
 *   @0xce6a0 eoreq r3, r6, r0, ror r12
 *   @0xce6a4 eoreq r3, r6, r12, asr #24
 *   @0xce6a8 eoreq r3, r6, r0, ror #24
 *   @0xce6ac eoreq r3, r6, r0, ror #24
 *   @0xce6b0 eoreq r3, r6, r0, lsr #24
 *   @0xce6b4 eoreq r3, r6, r0, asr r12
 *   @0xce6b8 .word 0x00263bd8
 *   @0xce6bc eoreq r3, r6, r4, asr #23
 *
 * ══ §9/91 Graphics::SetMatrix  0x17eb1c  size 372  93 条（0x17eb1c..0x17ec90）
 * @func 0x17eb1c 0x17ec90  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17eb2c→0x4a22b1, 0x17eb48→0x4a2170, 0x17ebc0→0x3f26dc, 0x17ebd4→0x479c54, 0x17ebf0→0x479bf8, 0x17ec20→0x544c80, 0x17ec58→0x4a23f0
 * 调用序列: yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)×2 / Graphics::Flush() / GR_3D_Light_Process() / Graphics::SetRenderState(eRenderState, unsigned int)
 * 字段偏移 top8: 0x144×1 / 0x140×1 / 0x128×1 / 0x-c×1 / 0x-8×1 / 0x-4×1 / 0xb4×1 / 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17eb1c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x17eb20 mov r5, r0
 *   @0x17eb24 ldr r4, [pc, #0x144]
 *   @0x17eb28 mov r6, r1
 *   @0x17eb2c ldr r3, [pc, #0x140]
 *   @0x17eb30 add r4, pc, r4
 *   @0x17eb34 ldr r3, [r4, r3]
 *   @0x17eb38 ldrb r3, [r3]
 *   @0x17eb3c cmp r3, #0
 *   @0x17eb40 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17eb44 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17eb48 ldr r3, [pc, #0x128]
 *   @0x17eb4c mov r12, r6
 *   @0x17eb50 add r9, r6, #64
 *   @0x17eb54 ldr r6, [r4, r3]
 *   @0x17eb58 add r8, r6, r5, lsl #6
 *   @0x17eb5c mov r7, r8
 *   @0x17eb60 ldr r0, [r12]
 *   @0x17eb64 add r12, r12, #16
 *   @0x17eb68 ldr r1, [r12, #-0xc]
 *   @0x17eb6c mov lr, r7
 *   @0x17eb70 ldr r2, [r12, #-0x8]
 *   @0x17eb74 add r7, r7, #16
 *   @0x17eb78 ldr r3, [r12, #-0x4]
 *   @0x17eb7c cmp r12, r9
 *   @0x17eb80 stm lr!, {r0, r1, r2, r3}
 *   @0x17eb84 bne 0x17eb60 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x44>
 *   @0x17eb88 cmp r5, #0
 *   @0x17eb8c beq 0x17ec48 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x12c>
 *   @0x17eb90 cmp r5, #2
 *   @0x17eb94 beq 0x17ec48 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x12c>
 *   @0x17eb98 cmp r5, #1
 *   @0x17eb9c beq 0x17ebb0 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x94>
 *   @0x17eba0 add r0, r6, #192
 *   @0x17eba4 add r1, r6, #128
 *   @0x17eba8 mov r2, r6
 *   @0x17ebac bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x17ebb0 add r0, r6, #256
 *   @0x17ebb4 add r1, r6, #192
 *   @0x17ebb8 add r2, r6, #64
 *   @0x17ebbc bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x17ebc0 ldr r3, [pc, #0xb4]
 *   @0x17ebc4 ldr r7, [r4, r3]
 *   @0x17ebc8 ldr r3, [r7]
 *   @0x17ebcc cmp r3, #0
 *   @0x17ebd0 bne 0x17ec04 <_ZN8Graphics9SetMatrixE7eMatrixPf+0xe8>
 *   @0x17ebd4 ldr r3, [pc, #0xa4]
 *   @0x17ebd8 cmp r5, #1
 *   @0x17ebdc movw r0, #0x1701
 *   @0x17ebe0 movne r0, #5888
 *   @0x17ebe4 ldr r3, [r4, r3]
 *   @0x17ebe8 ldr r3, [r3]
 *   @0x17ebec blx r3
 *   @0x17ebf0 ldr r3, [pc, #0x8c]
 *   @0x17ebf4 mov r0, r8
 *   @0x17ebf8 ldr r3, [r4, r3]
 *   @0x17ebfc ldr r3, [r3]
 *   @0x17ec00 blx r3
 *   @0x17ec04 bics r3, r5, #2
 *   @0x17ec08 beq 0x17ec50 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x134>
 *   @0x17ec0c cmp r5, #1
 *   @0x17ec10 beq 0x17ec58 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x13c>
 *   @0x17ec14 ldr r3, [r7]
 *   @0x17ec18 cmp r3, #1
 *   @0x17ec1c popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17ec20 ldr r3, [pc, #0x60]
 *   @0x17ec24 ldr r3, [r4, r3]
 *   @0x17ec28 ldr r3, [r3]
 *   @0x17ec2c cmp r3, #0
 *   @0x17ec30 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17ec34 ldr r0, [r3, #0x6c]
 *   @0x17ec38 mov r2, r6
 *   @0x17ec3c mov r1, #5
 *   @0x17ec40 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x17ec44 b 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf>
 *   @0x17ec48 add r8, r6, #192
 *   @0x17ec4c b 0x17eb98 <_ZN8Graphics9SetMatrixE7eMatrixPf+0x7c>
 *   @0x17ec50 bl 0x17fa9c <_Z19GR_3D_Light_Processv>
 *   @0x17ec54 b 0x17ec0c <_ZN8Graphics9SetMatrixE7eMatrixPf+0xf0>
 *   @0x17ec58 ldr r3, [pc, #0x2c]
 *   @0x17ec5c mov r0, #8
 *   @0x17ec60 ldr r3, [r4, r3]
 *   @0x17ec64 ldr r1, [r3]
 *   @0x17ec68 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x17ec6c b 0x17ec14 <_ZN8Graphics9SetMatrixE7eMatrixPf+0xf8>
 *   @0x17ec70 eoreq r3, r7, r0, lsr #2
 *   @0x17ec74 .word 0xffffe4d0
 *   @0x17ec78 .word 0xffffe824
 *   @0x17ec7c .word 0xffffe7b8
 *   @0x17ec80 .word 0xffffbc48
 *   @0x17ec84 .word 0xffffbc88
 *   @0x17ec88 .word 0xffffe828
 *   @0x17ec8c .word 0xffffe82c
 *
 * ══ §10/91 MyRandom  0x1a27ac  size 372  93 条（0x1a27ac..0x1a2920）
 * @func 0x1a27ac 0x1a2920  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fYYRandom(double)×5 / 0xb6988×2 / MyRandom(float, float, int)+0x54 / MyRandom(float, float, int)+0x6c / MyRandom(float, float, int)+0xf8
 * 字段偏移 top8: 无
 * VFP 指令 60 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a27ac push {r3, lr}
 *   @0x1a27b0 vpush {d8, d9, d10, d11, d12}
 *   @0x1a27b4 vmov s10, r1
 *   @0x1a27b8 vmov s20, r0
 *   @0x1a27bc vsub.f32 s21, s10, s20
 *   @0x1a27c0 vcmpe.f32 s21, #0
 *   @0x1a27c4 vmrs APSR_nzcv, fpscr
 *   @0x1a27c8 bls 0x1a2800 <_Z8MyRandomffi+0x54>
 *   @0x1a27cc cmp r2, #1
 *   @0x1a27d0 beq 0x1a2898 <_Z8MyRandomffi+0xec>
 *   @0x1a27d4 cmp r2, #2
 *   @0x1a27d8 beq 0x1a280c <_Z8MyRandomffi+0x60>
 *   @0x1a27dc mov r0, #0
 *   @0x1a27e0 mov r1, #0
 *   @0x1a27e4 movt r1, #0x3ff0
 *   @0x1a27e8 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a27ec vcvt.f64.f32 d7, s20
 *   @0x1a27f0 vcvt.f64.f32 d6, s21
 *   @0x1a27f4 vmov d5, r0, r1
 *   @0x1a27f8 vmla.f64 d7, d5, d6
 *   @0x1a27fc vcvt.f32.f64 s20, d7
 *   @0x1a2800 vmov r0, s20
 *   @0x1a2804 vpop {d8, d9, d10, d11, d12}
 *   @0x1a2808 pop {r3, pc}
 *   @0x1a280c vmov.f64 d9, #5.000000e-01
 *   @0x1a2810 vmov.f64 d8, #6.000000e+00
 *   @0x1a2814 vmov.f32 s24, #5.000000e-01
 *   @0x1a2818 mov r0, #0
 *   @0x1a281c mov r1, #0
 *   @0x1a2820 movt r1, #0x3ff0
 *   @0x1a2824 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2828 vmov d6, r0, r1
 *   @0x1a282c vsub.f64 d7, d6, d9
 *   @0x1a2830 vmul.f64 d7, d7, d8
 *   @0x1a2834 vcvt.f32.f64 s22, d7
 *   @0x1a2838 vnmul.f32 s15, s22, s22
 *   @0x1a283c vmul.f32 s15, s15, s24
 *   @0x1a2840 vmov r0, s15
 *   @0x1a2844 bl 0xb6988 <expf@plt>
 *   @0x1a2848 mov r1, #0
 *   @0x1a284c movt r1, #0x3ff0
 *   @0x1a2850 vmov s23, r0
 *   @0x1a2854 mov r0, #0
 *   @0x1a2858 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a285c vcvt.f64.f32 d7, s23
 *   @0x1a2860 vmov d5, r0, r1
 *   @0x1a2864 vcmpe.f64 d7, d5
 *   @0x1a2868 vmrs APSR_nzcv, fpscr
 *   @0x1a286c ble 0x1a2818 <_Z8MyRandomffi+0x6c>
 *   @0x1a2870 vcmpe.f32 s22, #0
 *   @0x1a2874 vldr s14, [pc, #160]
 *   @0x1a2878 vmrs APSR_nzcv, fpscr
 *   @0x1a287c vmovmi.f32 s15, #6.000000e+00
 *   @0x1a2880 vaddmi.f32 s22, s22, s15
 *   @0x1a2884 vmul.f32 s22, s22, s14
 *   @0x1a2888 vmla.f32 s20, s22, s21
 *   @0x1a288c vmov r0, s20
 *   @0x1a2890 vpop {d8, d9, d10, d11, d12}
 *   @0x1a2894 pop {r3, pc}
 *   @0x1a2898 vmov.f64 d9, #5.000000e-01
 *   @0x1a289c vmov.f64 d8, #6.000000e+00
 *   @0x1a28a0 vmov.f32 s24, #5.000000e-01
 *   @0x1a28a4 mov r0, #0
 *   @0x1a28a8 mov r1, #0
 *   @0x1a28ac movt r1, #0x3ff0
 *   @0x1a28b0 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a28b4 vmov d6, r0, r1
 *   @0x1a28b8 vsub.f64 d7, d6, d9
 *   @0x1a28bc vmul.f64 d7, d7, d8
 *   @0x1a28c0 vcvt.f32.f64 s22, d7
 *   @0x1a28c4 vnmul.f32 s15, s22, s22
 *   @0x1a28c8 vmul.f32 s15, s15, s24
 *   @0x1a28cc vmov r0, s15
 *   @0x1a28d0 bl 0xb6988 <expf@plt>
 *   @0x1a28d4 mov r1, #0
 *   @0x1a28d8 movt r1, #0x3ff0
 *   @0x1a28dc vmov s23, r0
 *   @0x1a28e0 mov r0, #0
 *   @0x1a28e4 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a28e8 vcvt.f64.f32 d7, s23
 *   @0x1a28ec vmov d5, r0, r1
 *   @0x1a28f0 vcmpe.f64 d7, d5
 *   @0x1a28f4 vmrs APSR_nzcv, fpscr
 *   @0x1a28f8 ble 0x1a28a4 <_Z8MyRandomffi+0xf8>
 *   @0x1a28fc vmov.f32 s14, #3.000000e+00
 *   @0x1a2900 vldr s15, [pc, #20]
 *   @0x1a2904 vadd.f32 s22, s22, s14
 *   @0x1a2908 vmul.f32 s22, s22, s15
 *   @0x1a290c vmla.f32 s20, s22, s21
 *   @0x1a2910 vmov r0, s20
 *   @0x1a2914 vpop {d8, d9, d10, d11, d12}
 *   @0x1a2918 pop {r3, pc}
 *   @0x1a291c vmullo.f32 s20, s21, s23
 *
 * ══ §11/91 RTree<CInstance*, int, float, 6, 2>::RTree  0x1cc320  size 372  93 条（0x1cc320..0x1cc494）
 * @func 0x1cc320 0x1cc494  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / operator new(unsigned int)
 * 字段偏移 top8: 0x4×7 / 0xc×6 / 0x8×6 / 0x10×4 / 0x2×3 / 0x164×1 / 0x140×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc320 ldr r3, [pc, #0x164]
 *   @0x1cc324 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cc328 ldr r3, [pc, r3]
 *   @0x1cc32c mov r5, r0
 *   @0x1cc330 sub sp, sp, #12
 *   @0x1cc334 add r3, r3, #8
 *   @0x1cc338 mov r0, #20
 *   @0x1cc33c str r3, [r5]
 *   @0x1cc340 mov r8, r1
 *   @0x1cc344 bl 0x27c524 <_Znwj>
 *   @0x1cc348 ldr r7, [pc, #0x140]
 *   @0x1cc34c mov r6, #0
 *   @0x1cc350 mov r1, #4
 *   @0x1cc354 add r7, pc, r7
 *   @0x1cc358 mov r3, #74
 *   @0x1cc35c mov r10, #152
 *   @0x1cc360 mov r2, r7
 *   @0x1cc364 mov r4, r0
 *   @0x1cc368 str r8, [r0]
 *   @0x1cc36c str r6, [r0, #0x4]
 *   @0x1cc370 mov r8, #1
 *   @0x1cc374 str r6, [r0, #0xc]
 *   @0x1cc378 mov r0, r6
 *   @0x1cc37c str r6, [r4, #0x10]
 *   @0x1cc380 str r8, [r4, #0x8]
 *   @0x1cc384 str r6, [sp]
 *   @0x1cc388 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1cc38c mov r1, r7
 *   @0x1cc390 mov r3, r8
 *   @0x1cc394 mov r2, #70
 *   @0x1cc398 ldr r11, [r4, #0x8]
 *   @0x1cc39c sub r11, r11, #-1073741823
 *   @0x1cc3a0 mov r9, r0
 *   @0x1cc3a4 ldr r0, [r4]
 *   @0x1cc3a8 str r9, [r4, #0x4]
 *   @0x1cc3ac mul r0, r10, r0
 *   @0x1cc3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1cc3b4 str r0, [r9, r11, lsl #2]
 *   @0x1cc3b8 ldr r12, [r4, #0x10]
 *   @0x1cc3bc str r4, [r5, #0x4]
 *   @0x1cc3c0 cmp r12, r6
 *   @0x1cc3c4 str r6, [r5, #0xc]
 *   @0x1cc3c8 beq 0x1cc3fc <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xdc>
 *   @0x1cc3cc ldr r3, [r12]
 *   @0x1cc3d0 str r3, [r4, #0x10]
 *   @0x1cc3d4 mov r3, #0
 *   @0x1cc3d8 mov r0, r5
 *   @0x1cc3dc str r3, [r12]
 *   @0x1cc3e0 movw r2, #0xfdc
 *   @0x1cc3e4 str r12, [r5, #0x10]
 *   @0x1cc3e8 movt r2, #0x4049
 *   @0x1cc3ec str r3, [r12, #0x4]
 *   @0x1cc3f0 str r2, [r5, #0x14]
 *   @0x1cc3f4 add sp, sp, #12
 *   @0x1cc3f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cc3fc ldr r3, [r4, #0xc]
 *   @0x1cc400 ldr r2, [r4]
 *   @0x1cc404 cmp r3, r2
 *   @0x1cc408 bge 0x1cc430 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0x110>
 *   @0x1cc40c ldr r0, [r4, #0x8]
 *   @0x1cc410 mov r12, #152
 *   @0x1cc414 ldr r2, [r4, #0x4]
 *   @0x1cc418 add r1, r3, #1
 *   @0x1cc41c sub r0, r0, #-1073741823
 *   @0x1cc420 ldr r2, [r2, r0, lsl #2]
 *   @0x1cc424 str r1, [r4, #0xc]
 *   @0x1cc428 mla r12, r12, r3, r2
 *   @0x1cc42c b 0x1cc3d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xb4>
 *   @0x1cc430 ldr r1, [r4, #0x8]
 *   @0x1cc434 mov r2, r7
 *   @0x1cc438 str r12, [r4, #0xc]
 *   @0x1cc43c mov r3, #74
 *   @0x1cc440 add r1, r1, #1
 *   @0x1cc444 ldr r0, [r4, #0x4]
 *   @0x1cc448 str r1, [r4, #0x8]
 *   @0x1cc44c lsl r1, r1, #2
 *   @0x1cc450 str r12, [sp]
 *   @0x1cc454 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1cc458 mov r1, r7
 *   @0x1cc45c mov r3, r8
 *   @0x1cc460 mov r2, #70
 *   @0x1cc464 ldr r7, [r4, #0x8]
 *   @0x1cc468 sub r7, r7, #-1073741823
 *   @0x1cc46c mov r6, r0
 *   @0x1cc470 ldr r0, [r4]
 *   @0x1cc474 str r6, [r4, #0x4]
 *   @0x1cc478 mul r0, r10, r0
 *   @0x1cc47c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1cc480 ldr r3, [r4, #0xc]
 *   @0x1cc484 str r0, [r6, r7, lsl #2]
 *   @0x1cc488 b 0x1cc40c <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xec>
 *   @0x1cc48c eoreq r4, r2, r4, lsl #16
 *   @0x1cc490 ldrsbeq r4, [r6], -r12
 *
 * ══ §12/91 CSprite::DrawPart  0x1e5e34  size 372  93 条（0x1e5e34..0x1e5fa8）
 * @func 0x1e5e34 0x1e5fa8  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)+0xa8 / __aeabi_idivmod / GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float) / GR_Texture_Draw_Part(int, float, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x18×3 / 0x50×3 / 0x2×2 / 0x14×2 / 0x38×2 / 0xac×2 / 0x5c×2 / 0xc×2
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5e34 push {r4, r5, r6, r7, lr}
 *   @0x1e5e38 mov r4, r0
 *   @0x1e5e3c ldr r5, [r0, #0x18]
 *   @0x1e5e40 sub sp, sp, #36
 *   @0x1e5e44 mov r6, r2
 *   @0x1e5e48 mov r7, r3
 *   @0x1e5e4c cmp r5, #0
 *   @0x1e5e50 ble 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8>
 *   @0x1e5e54 mov r0, r1
 *   @0x1e5e58 mov r1, r5
 *   @0x1e5e5c bl 0x318dec <__aeabi_idivmod>
 *   @0x1e5e60 ldr r12, [r4, #0x74]
 *   @0x1e5e64 subs r0, r1, #0
 *   @0x1e5e68 addlt r0, r0, r5
 *   @0x1e5e6c cmp r12, #0
 *   @0x1e5e70 bne 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8>
 *   @0x1e5e74 ldr r3, [r4, #0x54]
 *   @0x1e5e78 cmp r3, #0
 *   @0x1e5e7c beq 0x1e5f10 <_ZN7CSprite8DrawPartEiffffffffjf+0xdc>
 *   @0x1e5e80 ldr r2, [sp, #0x50]
 *   @0x1e5e84 vldr s15, [sp, #60]
 *   @0x1e5e88 ldr r0, [r3, r0, lsl #2]
 *   @0x1e5e8c mov r1, r6
 *   @0x1e5e90 mov r3, #0
 *   @0x1e5e94 vstr s15, [sp]
 *   @0x1e5e98 str r2, [sp, #0x18]
 *   @0x1e5e9c vldr s15, [sp, #64]
 *   @0x1e5ea0 str r3, [sp, #0x14]
 *   @0x1e5ea4 vstr s15, [sp, #4]
 *   @0x1e5ea8 mov r2, r7
 *   @0x1e5eac vldr s15, [sp, #68]
 *   @0x1e5eb0 ldr r3, [sp, #0x38]
 *   @0x1e5eb4 vstr s15, [sp, #8]
 *   @0x1e5eb8 vldr s15, [sp, #72]
 *   @0x1e5ebc vstr s15, [sp, #12]
 *   @0x1e5ec0 vldr s15, [sp, #76]
 *   @0x1e5ec4 vstr s15, [sp, #16]
 *   @0x1e5ec8 vldr s15, [sp, #84]
 *   @0x1e5ecc vstr s15, [sp, #28]
 *   @0x1e5ed0 bl 0x175450 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf>
 *   @0x1e5ed4 cmp r0, #0
 *   @0x1e5ed8 beq 0x1e5ee4 <_ZN7CSprite8DrawPartEiffffffffjf+0xb0>
 *   @0x1e5edc add sp, sp, #36
 *   @0x1e5ee0 pop {r4, r5, r6, r7, pc}
 *   @0x1e5ee4 ldr r3, [pc, #0xac]
 *   @0x1e5ee8 ldr r1, [pc, #0xac]
 *   @0x1e5eec ldr r3, [pc, r3]
 *   @0x1e5ef0 ldr r2, [r4, #0x5c]
 *   @0x1e5ef4 add r1, pc, r1
 *   @0x1e5ef8 ldr r0, [r3]
 *   @0x1e5efc ldr r3, [r0]
 *   @0x1e5f00 ldr r3, [r3, #0xc]
 *   @0x1e5f04 blx r3
 *   @0x1e5f08 add sp, sp, #36
 *   @0x1e5f0c pop {r4, r5, r6, r7, pc}
 *   @0x1e5f10 ldr r3, [r4, #0x50]
 *   @0x1e5f14 vldr s15, [sp, #60]
 *   @0x1e5f18 mov r12, #0
 *   @0x1e5f1c mov r1, r6
 *   @0x1e5f20 mov r2, r7
 *   @0x1e5f24 ldr r0, [r3, r0, lsl #2]
 *   @0x1e5f28 vstr s15, [sp]
 *   @0x1e5f2c ldr r3, [sp, #0x50]
 *   @0x1e5f30 vldr s15, [sp, #64]
 *   @0x1e5f34 str r12, [sp, #0x14]
 *   @0x1e5f38 vstr s15, [sp, #4]
 *   @0x1e5f3c vldr s15, [sp, #68]
 *   @0x1e5f40 vstr s15, [sp, #8]
 *   @0x1e5f44 str r3, [sp, #0x18]
 *   @0x1e5f48 vldr s15, [sp, #72]
 *   @0x1e5f4c ldr r3, [sp, #0x38]
 *   @0x1e5f50 vstr s15, [sp, #12]
 *   @0x1e5f54 vldr s15, [sp, #76]
 *   @0x1e5f58 vstr s15, [sp, #16]
 *   @0x1e5f5c vldr s15, [sp, #84]
 *   @0x1e5f60 vstr s15, [sp, #28]
 *   @0x1e5f64 bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf>
 *   @0x1e5f68 cmp r0, #0
 *   @0x1e5f6c bne 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8>
 *   @0x1e5f70 ldr r3, [pc, #0x28]
 *   @0x1e5f74 ldr r1, [pc, #0x28]
 *   @0x1e5f78 ldr r3, [pc, r3]
 *   @0x1e5f7c ldr r2, [r4, #0x5c]
 *   @0x1e5f80 add r1, pc, r1
 *   @0x1e5f84 ldr r0, [r3]
 *   @0x1e5f88 ldr r3, [r0]
 *   @0x1e5f8c ldr r3, [r3, #0xc]
 *   @0x1e5f90 blx r3
 *   @0x1e5f94 b 0x1e5edc <_ZN7CSprite8DrawPartEiffffffffjf+0xa8>
 *   @0x1e5f98 eoreq r7, r0, r8, lsr #16
 *   @0x1e5f9c andseq r12, r6, r0, lsr #13
 *   @0x1e5fa0 mlaeq r0, r12, r7, r7
 *   @0x1e5fa4 andseq r12, r6, r4, lsl r6
 *
 * ══ §13/91 CCameraManager::CloneCamera  0x170658  size 368  92 条（0x170658..0x1707c8）
 * @func 0x170658 0x1707c8  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::GetCamera(int) / CCameraManager::CreateCamera() / CCamera::GetViewX() / CCamera::SetViewX(float) / CCamera::GetViewY() / CCamera::SetViewY(float) / CCamera::GetViewWidth() / CCamera::SetViewWidth(float)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170658 push {r4, r5, r6, lr}
 *   @0x17065c sub sp, sp, #128
 *   @0x170660 mov r4, r0
 *   @0x170664 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170668 subs r5, r0, #0
 *   @0x17066c beq 0x1707c0 <_ZN14CCameraManager11CloneCameraEi+0x168>
 *   @0x170670 mov r0, r4
 *   @0x170674 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv>
 *   @0x170678 mov r4, r0
 *   @0x17067c mov r0, r5
 *   @0x170680 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x170684 mov r1, r0
 *   @0x170688 mov r0, r4
 *   @0x17068c bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x170690 mov r0, r5
 *   @0x170694 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x170698 mov r1, r0
 *   @0x17069c mov r0, r4
 *   @0x1706a0 bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x1706a4 mov r0, r5
 *   @0x1706a8 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x1706ac mov r1, r0
 *   @0x1706b0 mov r0, r4
 *   @0x1706b4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x1706b8 mov r0, r5
 *   @0x1706bc bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x1706c0 mov r1, r0
 *   @0x1706c4 mov r0, r4
 *   @0x1706c8 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x1706cc mov r0, r5
 *   @0x1706d0 bl 0x16d2e4 <_ZN7CCamera13GetViewSpeedXEv>
 *   @0x1706d4 mov r1, r0
 *   @0x1706d8 mov r0, r4
 *   @0x1706dc bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf>
 *   @0x1706e0 mov r0, r5
 *   @0x1706e4 bl 0x16d2f4 <_ZN7CCamera13GetViewSpeedYEv>
 *   @0x1706e8 mov r1, r0
 *   @0x1706ec mov r0, r4
 *   @0x1706f0 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf>
 *   @0x1706f4 mov r0, r5
 *   @0x1706f8 bl 0x16d304 <_ZN7CCamera14GetViewBorderXEv>
 *   @0x1706fc mov r1, r0
 *   @0x170700 mov r0, r4
 *   @0x170704 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf>
 *   @0x170708 mov r0, r5
 *   @0x17070c bl 0x16d314 <_ZN7CCamera14GetViewBorderYEv>
 *   @0x170710 mov r1, r0
 *   @0x170714 mov r0, r4
 *   @0x170718 bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf>
 *   @0x17071c mov r0, r5
 *   @0x170720 bl 0x16d324 <_ZN7CCamera12GetViewAngleEv>
 *   @0x170724 mov r1, r0
 *   @0x170728 mov r0, r4
 *   @0x17072c bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x170730 mov r0, r5
 *   @0x170734 bl 0x16d334 <_ZN7CCamera17GetTargetInstanceEv>
 *   @0x170738 mov r1, r0
 *   @0x17073c mov r0, r4
 *   @0x170740 bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi>
 *   @0x170744 mov r0, r5
 *   @0x170748 bl 0x16d344 <_ZN7CCamera14GetBeginScriptEv>
 *   @0x17074c mov r1, r0
 *   @0x170750 mov r0, r4
 *   @0x170754 bl 0x16d33c <_ZN7CCamera14SetBeginScriptEi>
 *   @0x170758 mov r0, r5
 *   @0x17075c bl 0x16d354 <_ZN7CCamera12GetEndScriptEv>
 *   @0x170760 mov r1, r0
 *   @0x170764 mov r0, r4
 *   @0x170768 bl 0x16d34c <_ZN7CCamera12SetEndScriptEi>
 *   @0x17076c mov r0, r5
 *   @0x170770 bl 0x16d364 <_ZN7CCamera15GetUpdateScriptEv>
 *   @0x170774 mov r1, r0
 *   @0x170778 mov r0, r4
 *   @0x17077c bl 0x16d35c <_ZN7CCamera15SetUpdateScriptEi>
 *   @0x170780 mov r1, r5
 *   @0x170784 mov r0, sp
 *   @0x170788 bl 0x16d170 <_ZN7CCamera10GetViewMatEv>
 *   @0x17078c mov r1, r5
 *   @0x170790 add r5, sp, #64
 *   @0x170794 mov r0, r5
 *   @0x170798 bl 0x16d134 <_ZN7CCamera10GetProjMatEv>
 *   @0x17079c mov r0, r4
 *   @0x1707a0 mov r1, sp
 *   @0x1707a4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix>
 *   @0x1707a8 mov r0, r4
 *   @0x1707ac mov r1, r5
 *   @0x1707b0 bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix>
 *   @0x1707b4 mov r0, r4
 *   @0x1707b8 add sp, sp, #128
 *   @0x1707bc pop {r4, r5, r6, pc}
 *   @0x1707c0 mov r0, r5
 *   @0x1707c4 b 0x1707b8 <_ZN14CCameraManager11CloneCameraEi+0x160>
 *
 * ══ §14/91 GraphicsPerf::BeginFrame  0x17b9a0  size 368  92 条（0x17b9a0..0x17bb10）
 * @func 0x17b9a0 0x17bb10  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b9b0→0x499338, 0x17b9bc→0x49932c, 0x17b9c0→0x499334, 0x17b9c8→0x4a203c, 0x17b9cc→0x4a2100, 0x17b9d8→0x4a20fc, 0x17b9dc→0x4a20f0, 0x17b9e8→0x4a2030
 * 调用序列: Timing_Time
 * 字段偏移 top8: 0xf0×3 / 0x104×2 / 0x100×2 / 0xf8×2 / 0x4×2 / 0x110×1 / 0x10c×1 / 0xe4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b9a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17b9a4 mov r5, #0
 *   @0x17b9a8 ldr r4, [pc, #0x110]
 *   @0x17b9ac sub sp, sp, #12
 *   @0x17b9b0 ldr r1, [pc, #0x10c]
 *   @0x17b9b4 mov r2, #1
 *   @0x17b9b8 add r4, pc, r4
 *   @0x17b9bc ldr r3, [pc, #0x104]
 *   @0x17b9c0 ldr r10, [pc, #0x104]
 *   @0x17b9c4 ldr r1, [r4, r1]
 *   @0x17b9c8 ldr r9, [pc, #0x100]
 *   @0x17b9cc ldr r8, [pc, #0x100]
 *   @0x17b9d0 str r5, [r1]
 *   @0x17b9d4 ldr r3, [r4, r3]
 *   @0x17b9d8 ldr r7, [pc, #0xf8]
 *   @0x17b9dc ldr r6, [pc, #0xf8]
 *   @0x17b9e0 str r2, [r3]
 *   @0x17b9e4 bl 0x215148 <Timing_Time>
 *   @0x17b9e8 ldr r3, [pc, #0xf0]
 *   @0x17b9ec ldr r12, [pc, #0xf0]
 *   @0x17b9f0 ldr r2, [pc, #0xf0]
 *   @0x17b9f4 ldr r3, [r4, r3]
 *   @0x17b9f8 str r3, [sp, #0x4]
 *   @0x17b9fc ldr r11, [sp, #0x4]
 *   @0x17ba00 ldr r3, [pc, #0xe4]
 *   @0x17ba04 str r3, [sp]
 *   @0x17ba08 ldr r3, [pc, #0xe0]
 *   @0x17ba0c strd r0, r1, [r11]
 *   @0x17ba10 mov r0, #128
 *   @0x17ba14 ldr r1, [r4, r10]
 *   @0x17ba18 movt r0, #0xff00
 *   @0x17ba1c str r5, [r1]
 *   @0x17ba20 ldr r1, [r4, r9]
 *   @0x17ba24 str r5, [r1]
 *   @0x17ba28 ldr r1, [r4, r8]
 *   @0x17ba2c str r5, [r1]
 *   @0x17ba30 ldr r1, [r4, r7]
 *   @0x17ba34 str r5, [r1]
 *   @0x17ba38 ldr r6, [r4, r6]
 *   @0x17ba3c ldr r1, [pc, #0xb0]
 *   @0x17ba40 str r5, [r6]
 *   @0x17ba44 add r1, pc, r1
 *   @0x17ba48 ldr r6, [pc, #0xa8]
 *   @0x17ba4c ldr r6, [r4, r6]
 *   @0x17ba50 str r5, [r6]
 *   @0x17ba54 ldr r6, [pc, #0xa0]
 *   @0x17ba58 ldr r6, [r4, r6]
 *   @0x17ba5c str r5, [r6]
 *   @0x17ba60 ldr r6, [pc, #0x98]
 *   @0x17ba64 ldr r6, [r4, r6]
 *   @0x17ba68 str r5, [r6]
 *   @0x17ba6c ldr r6, [pc, #0x90]
 *   @0x17ba70 ldr r6, [r4, r6]
 *   @0x17ba74 str r5, [r6]
 *   @0x17ba78 ldr r6, [pc, #0x88]
 *   @0x17ba7c ldr r6, [r4, r6]
 *   @0x17ba80 str r5, [r6]
 *   @0x17ba84 ldr r6, [pc, #0x80]
 *   @0x17ba88 ldr r6, [r4, r6]
 *   @0x17ba8c str r5, [r6]
 *   @0x17ba90 ldr r6, [sp]
 *   @0x17ba94 ldr r6, [r4, r6]
 *   @0x17ba98 str r5, [r6]
 *   @0x17ba9c ldr r12, [r4, r12]
 *   @0x17baa0 str r5, [r12]
 *   @0x17baa4 ldr r2, [r4, r2]
 *   @0x17baa8 str r5, [r2]
 *   @0x17baac ldr r3, [r4, r3]
 *   @0x17bab0 str r5, [r3]
 *   @0x17bab4 add sp, sp, #12
 *   @0x17bab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17babc b 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc>
 *   @0x17bac0 mlaeq r7, r8, r2, r6
 *   @0x17bac4 .word 0xffffe6dc
 *   @0x17bac8 .word 0xffffe6e0
 *   @0x17bacc .word 0xffffe730
 *   @0x17bad0 .word 0xffffe73c
 *   @0x17bad4 .word 0xffffe740
 *   @0x17bad8 .word 0xffffe744
 *   @0x17badc .word 0xffffe748
 *   @0x17bae0 .word 0xffffe74c
 *   @0x17bae4 .word 0xffffe750
 *   @0x17bae8 .word 0xffffe754
 *   @0x17baec .word 0xffffe758
 *   @0x17baf0 .word 0xffffe75c
 *   @0x17baf4 ldrheq pc, [r12], -r4
 *   @0x17baf8 .word 0xffffe760
 *   @0x17bafc .word 0xffffe764
 *   @0x17bb00 .word 0xffffe768
 *   @0x17bb04 .word 0xffffe76c
 *   @0x17bb08 .word 0xffffe770
 *   @0x17bb0c .word 0xffffe774
 *
 * ══ §15/91 HandleKey  0x1d5804  size 368  92 条（0x1d5804..0x1d5974）
 * @func 0x1d5804 0x1d5974  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5808→0x536f20, 0x1d5810→0x536f70, 0x1d584c→0x53ab70, 0x1d5854→0x542374
 * 调用序列: HandleKey(int)+0x154 / HandleKey(int)+0x134 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x154×2 / 0x14×2 / 0x10×2 / 0x150×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5804 ldr r1, [pc, #0x154]
 *   @0x1d5808 ldr r3, [pc, #0x154]
 *   @0x1d580c add r1, pc, r1
 *   @0x1d5810 ldr r12, [pc, #0x150]
 *   @0x1d5814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5818 add r9, r0, #1280
 *   @0x1d581c mov r8, r0
 *   @0x1d5820 ldr r0, [r1, r3]
 *   @0x1d5824 sub sp, sp, #28
 *   @0x1d5828 ldrd r10, r11, [r0]
 *   @0x1d582c adds r2, r10, #1
 *   @0x1d5830 adc r3, r11, #0
 *   @0x1d5834 strd r10, r11, [sp, #8]
 *   @0x1d5838 strd r2, r3, [r0]
 *   @0x1d583c ldr r11, [r1, r12]
 *   @0x1d5840 ldr r3, [r11, r9, lsl #2]
 *   @0x1d5844 cmp r3, #0
 *   @0x1d5848 ble 0x1d5958 <_Z9HandleKeyi+0x154>
 *   @0x1d584c ldr r2, [pc, #0x118]
 *   @0x1d5850 mov r7, #0
 *   @0x1d5854 ldr r3, [pc, #0x114]
 *   @0x1d5858 ldr r10, [r1, r2]
 *   @0x1d585c ldr r3, [r1, r3]
 *   @0x1d5860 add r10, r10, r9, lsl #3
 *   @0x1d5864 str r3, [sp, #0x14]
 *   @0x1d5868 mov r3, r10
 *   @0x1d586c mov r10, r11
 *   @0x1d5870 mov r11, r3
 *   @0x1d5874 ldr r12, [sp, #0x14]
 *   @0x1d5878 ldr r1, [r11, #0x4]
 *   @0x1d587c ldr r3, [r12]
 *   @0x1d5880 ldr r1, [r1, r7, lsl #2]
 *   @0x1d5884 ldr r2, [r3, #0x4]
 *   @0x1d5888 ldr r3, [r3]
 *   @0x1d588c and r2, r1, r2
 *   @0x1d5890 ldr r3, [r3, r2, lsl #3]
 *   @0x1d5894 cmp r3, #0
 *   @0x1d5898 bne 0x1d58ac <_Z9HandleKeyi+0xa8>
 *   @0x1d589c b 0x1d5948 <_Z9HandleKeyi+0x144>
 *   @0x1d58a0 ldr r3, [r3, #0x4]
 *   @0x1d58a4 cmp r3, #0
 *   @0x1d58a8 beq 0x1d5948 <_Z9HandleKeyi+0x144>
 *   @0x1d58ac ldr r2, [r3, #0x8]
 *   @0x1d58b0 cmp r1, r2
 *   @0x1d58b4 bne 0x1d58a0 <_Z9HandleKeyi+0x9c>
 *   @0x1d58b8 ldr r3, [r3, #0xc]
 *   @0x1d58bc cmp r3, #0
 *   @0x1d58c0 beq 0x1d5948 <_Z9HandleKeyi+0x144>
 *   @0x1d58c4 ldr r6, [r3, #0xc4]
 *   @0x1d58c8 cmp r6, #0
 *   @0x1d58cc beq 0x1d5948 <_Z9HandleKeyi+0x144>
 *   @0x1d58d0 ldr r3, [r6, #0x8]
 *   @0x1d58d4 cmp r3, #0
 *   @0x1d58d8 beq 0x1d5948 <_Z9HandleKeyi+0x144>
 *   @0x1d58dc str r10, [sp, #0x10]
 *   @0x1d58e0 str r11, [sp, #0x4]
 *   @0x1d58e4 b 0x1d58f4 <_Z9HandleKeyi+0xf0>
 *   @0x1d58e8 ldr r3, [r6, #0x8]
 *   @0x1d58ec cmp r3, #0
 *   @0x1d58f0 beq 0x1d5940 <_Z9HandleKeyi+0x13c>
 *   @0x1d58f4 ldr r0, [r6, #0x8]
 *   @0x1d58f8 ldr r6, [r6]
 *   @0x1d58fc ldrb r3, [r0, #0x68]
 *   @0x1d5900 cmp r3, #0
 *   @0x1d5904 bne 0x1d5938 <_Z9HandleKeyi+0x134>
 *   @0x1d5908 ldrb r3, [r0, #0x69]
 *   @0x1d590c cmp r3, #0
 *   @0x1d5910 bne 0x1d5938 <_Z9HandleKeyi+0x134>
 *   @0x1d5914 ldrd r4, r5, [r0, #112]
 *   @0x1d5918 mov r1, r0
 *   @0x1d591c ldrd r10, r11, [sp, #8]
 *   @0x1d5920 mov r2, #5
 *   @0x1d5924 mov r3, r8
 *   @0x1d5928 cmp r10, r4
 *   @0x1d592c sbcs r11, r11, r5
 *   @0x1d5930 blt 0x1d5938 <_Z9HandleKeyi+0x134>
 *   @0x1d5934 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d5938 cmp r6, #0
 *   @0x1d593c bne 0x1d58e8 <_Z9HandleKeyi+0xe4>
 *   @0x1d5940 ldr r10, [sp, #0x10]
 *   @0x1d5944 ldr r11, [sp, #0x4]
 *   @0x1d5948 ldr r3, [r10, r9, lsl #2]
 *   @0x1d594c add r7, r7, #1
 *   @0x1d5950 cmp r3, r7
 *   @0x1d5954 bgt 0x1d5874 <_Z9HandleKeyi+0x70>
 *   @0x1d5958 add sp, sp, #28
 *   @0x1d595c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d5960 eoreq r12, r1, r4, asr #8
 *   @0x1d5964 .word 0xffffdeb4
 *   @0x1d5968 .word 0xffffdeb8
 *   @0x1d596c .word 0xffffdebc
 *   @0x1d5970 .word 0xffffbfec
 *
 * ══ §16/91 HandleMouseGlobal  0x1d5d00  size 368  92 条（0x1d5d00..0x1d5e70）
 * @func 0x1d5d00 0x1d5e70  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5d04→0x536f20, 0x1d5d0c→0x536f70, 0x1d5d48→0x53ab70, 0x1d5d50→0x542374
 * 调用序列: HandleMouseGlobal(int)+0x154 / HandleMouseGlobal(int)+0x134 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x154×2 / 0x14×2 / 0x10×2 / 0x150×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5d00 ldr r1, [pc, #0x154]
 *   @0x1d5d04 ldr r3, [pc, #0x154]
 *   @0x1d5d08 add r1, pc, r1
 *   @0x1d5d0c ldr r12, [pc, #0x150]
 *   @0x1d5d10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5d14 add r9, r0, #1536
 *   @0x1d5d18 mov r8, r0
 *   @0x1d5d1c ldr r0, [r1, r3]
 *   @0x1d5d20 sub sp, sp, #28
 *   @0x1d5d24 ldrd r10, r11, [r0]
 *   @0x1d5d28 adds r2, r10, #1
 *   @0x1d5d2c adc r3, r11, #0
 *   @0x1d5d30 strd r10, r11, [sp, #8]
 *   @0x1d5d34 strd r2, r3, [r0]
 *   @0x1d5d38 ldr r11, [r1, r12]
 *   @0x1d5d3c ldr r3, [r11, r9, lsl #2]
 *   @0x1d5d40 cmp r3, #0
 *   @0x1d5d44 ble 0x1d5e54 <_Z17HandleMouseGlobali+0x154>
 *   @0x1d5d48 ldr r2, [pc, #0x118]
 *   @0x1d5d4c mov r7, #0
 *   @0x1d5d50 ldr r3, [pc, #0x114]
 *   @0x1d5d54 ldr r10, [r1, r2]
 *   @0x1d5d58 ldr r3, [r1, r3]
 *   @0x1d5d5c add r10, r10, r9, lsl #3
 *   @0x1d5d60 str r3, [sp, #0x14]
 *   @0x1d5d64 mov r3, r10
 *   @0x1d5d68 mov r10, r11
 *   @0x1d5d6c mov r11, r3
 *   @0x1d5d70 ldr r12, [sp, #0x14]
 *   @0x1d5d74 ldr r1, [r11, #0x4]
 *   @0x1d5d78 ldr r3, [r12]
 *   @0x1d5d7c ldr r1, [r1, r7, lsl #2]
 *   @0x1d5d80 ldr r2, [r3, #0x4]
 *   @0x1d5d84 ldr r3, [r3]
 *   @0x1d5d88 and r2, r1, r2
 *   @0x1d5d8c ldr r3, [r3, r2, lsl #3]
 *   @0x1d5d90 cmp r3, #0
 *   @0x1d5d94 bne 0x1d5da8 <_Z17HandleMouseGlobali+0xa8>
 *   @0x1d5d98 b 0x1d5e44 <_Z17HandleMouseGlobali+0x144>
 *   @0x1d5d9c ldr r3, [r3, #0x4]
 *   @0x1d5da0 cmp r3, #0
 *   @0x1d5da4 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144>
 *   @0x1d5da8 ldr r2, [r3, #0x8]
 *   @0x1d5dac cmp r1, r2
 *   @0x1d5db0 bne 0x1d5d9c <_Z17HandleMouseGlobali+0x9c>
 *   @0x1d5db4 ldr r3, [r3, #0xc]
 *   @0x1d5db8 cmp r3, #0
 *   @0x1d5dbc beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144>
 *   @0x1d5dc0 ldr r6, [r3, #0xc4]
 *   @0x1d5dc4 cmp r6, #0
 *   @0x1d5dc8 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144>
 *   @0x1d5dcc ldr r3, [r6, #0x8]
 *   @0x1d5dd0 cmp r3, #0
 *   @0x1d5dd4 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144>
 *   @0x1d5dd8 str r10, [sp, #0x10]
 *   @0x1d5ddc str r11, [sp, #0x4]
 *   @0x1d5de0 b 0x1d5df0 <_Z17HandleMouseGlobali+0xf0>
 *   @0x1d5de4 ldr r3, [r6, #0x8]
 *   @0x1d5de8 cmp r3, #0
 *   @0x1d5dec beq 0x1d5e3c <_Z17HandleMouseGlobali+0x13c>
 *   @0x1d5df0 ldr r0, [r6, #0x8]
 *   @0x1d5df4 ldr r6, [r6]
 *   @0x1d5df8 ldrb r3, [r0, #0x68]
 *   @0x1d5dfc cmp r3, #0
 *   @0x1d5e00 bne 0x1d5e34 <_Z17HandleMouseGlobali+0x134>
 *   @0x1d5e04 ldrb r3, [r0, #0x69]
 *   @0x1d5e08 cmp r3, #0
 *   @0x1d5e0c bne 0x1d5e34 <_Z17HandleMouseGlobali+0x134>
 *   @0x1d5e10 ldrd r4, r5, [r0, #112]
 *   @0x1d5e14 mov r1, r0
 *   @0x1d5e18 ldrd r10, r11, [sp, #8]
 *   @0x1d5e1c mov r2, #6
 *   @0x1d5e20 mov r3, r8
 *   @0x1d5e24 cmp r10, r4
 *   @0x1d5e28 sbcs r11, r11, r5
 *   @0x1d5e2c blt 0x1d5e34 <_Z17HandleMouseGlobali+0x134>
 *   @0x1d5e30 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d5e34 cmp r6, #0
 *   @0x1d5e38 bne 0x1d5de4 <_Z17HandleMouseGlobali+0xe4>
 *   @0x1d5e3c ldr r10, [sp, #0x10]
 *   @0x1d5e40 ldr r11, [sp, #0x4]
 *   @0x1d5e44 ldr r3, [r10, r9, lsl #2]
 *   @0x1d5e48 add r7, r7, #1
 *   @0x1d5e4c cmp r3, r7
 *   @0x1d5e50 bgt 0x1d5d70 <_Z17HandleMouseGlobali+0x70>
 *   @0x1d5e54 add sp, sp, #28
 *   @0x1d5e58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d5e5c eoreq r11, r1, r8, asr #30
 *   @0x1d5e60 .word 0xffffdeb4
 *   @0x1d5e64 .word 0xffffdeb8
 *   @0x1d5e68 .word 0xffffdebc
 *   @0x1d5e6c .word 0xffffbfec
 *
 * ══ §17/91 CPhysicsObject::~CPhysicsObject  0x236c60  size 368  92 条（0x236c60..0x236dd0）
 * @func 0x236c60 0x236dd0  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / CPhysicsObject::~CPhysicsObject()+0x164×2 / operator delete(void*)×2 / CPhysicsJointFactory::FindJoint(b2Joint*) / CPhysicsWorld::DeleteJoint(int) / CPhysicsWorld::DestroyBody(CPhysicsObject*)
 * 字段偏移 top8: 0x4×7 / 0x8×5 / 0xc×2 / 0x1c×2 / 0x164×1 / 0xb4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236c60 ldr r3, [pc, #0x164]
 *   @0x236c64 movw r2, #0xfeee
 *   @0x236c68 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x236c6c ldr r3, [pc, r3]
 *   @0x236c70 movt r2, #0xfeee
 *   @0x236c74 mov r7, r0
 *   @0x236c78 ldr r3, [r3]
 *   @0x236c7c ldr r5, [r3, #0xb4]
 *   @0x236c80 cmp r5, r2
 *   @0x236c84 cmpne r5, #0
 *   @0x236c88 beq 0x236cd0 <_ZN14CPhysicsObjectD2Ev+0x70>
 *   @0x236c8c ldr r3, [r0]
 *   @0x236c90 ldr r4, [r3, #0x7c]
 *   @0x236c94 cmp r4, #0
 *   @0x236c98 beq 0x236cc4 <_ZN14CPhysicsObjectD2Ev+0x64>
 *   @0x236c9c ldr r0, [r4, #0x4]
 *   @0x236ca0 ldr r4, [r4, #0xc]
 *   @0x236ca4 bl 0x23b47c <_ZN20CPhysicsJointFactory9FindJointEP7b2Joint>
 *   @0x236ca8 subs r3, r0, #0
 *   @0x236cac mov r0, r5
 *   @0x236cb0 beq 0x236c94 <_ZN14CPhysicsObjectD2Ev+0x34>
 *   @0x236cb4 ldr r1, [r3, #0x8]
 *   @0x236cb8 bl 0x237f90 <_ZN13CPhysicsWorld11DeleteJointEi>
 *   @0x236cbc cmp r4, #0
 *   @0x236cc0 bne 0x236c9c <_ZN14CPhysicsObjectD2Ev+0x3c>
 *   @0x236cc4 mov r0, r5
 *   @0x236cc8 mov r1, r7
 *   @0x236ccc bl 0x238c08 <_ZN13CPhysicsWorld11DestroyBodyEP14CPhysicsObject>
 *   @0x236cd0 ldr r4, [r7, #0x1c]
 *   @0x236cd4 ldr r8, [r4, #0x4]
 *   @0x236cd8 cmp r8, #0
 *   @0x236cdc blt 0x236dc4 <_ZN14CPhysicsObjectD2Ev+0x164>
 *   @0x236ce0 lsl r6, r8, #3
 *   @0x236ce4 mov r9, #0
 *   @0x236ce8 ldr r3, [r4]
 *   @0x236cec add r2, r3, r6
 *   @0x236cf0 ldr r0, [r3, r6]
 *   @0x236cf4 str r9, [r3, r6]
 *   @0x236cf8 cmp r0, #0
 *   @0x236cfc str r9, [r2, #0x4]
 *   @0x236d00 beq 0x236d24 <_ZN14CPhysicsObjectD2Ev+0xc4>
 *   @0x236d04 ldr r5, [r0, #0x4]
 *   @0x236d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236d0c ldr r3, [r4, #0x8]
 *   @0x236d10 cmp r5, #0
 *   @0x236d14 sub r3, r3, #1
 *   @0x236d18 mov r0, r5
 *   @0x236d1c str r3, [r4, #0x8]
 *   @0x236d20 bne 0x236d04 <_ZN14CPhysicsObjectD2Ev+0xa4>
 *   @0x236d24 sub r8, r8, #1
 *   @0x236d28 sub r6, r6, #8
 *   @0x236d2c cmn r8, #1
 *   @0x236d30 bne 0x236ce8 <_ZN14CPhysicsObjectD2Ev+0x88>
 *   @0x236d34 ldr r4, [r7, #0x1c]
 *   @0x236d38 cmp r4, #0
 *   @0x236d3c beq 0x236dbc <_ZN14CPhysicsObjectD2Ev+0x15c>
 *   @0x236d40 ldr r9, [r4, #0x4]
 *   @0x236d44 cmp r9, #0
 *   @0x236d48 blt 0x236dc4 <_ZN14CPhysicsObjectD2Ev+0x164>
 *   @0x236d4c ldr r0, [r4]
 *   @0x236d50 lsl r8, r9, #3
 *   @0x236d54 mov r10, #0
 *   @0x236d58 ldr r5, [r0, r8]
 *   @0x236d5c add r3, r0, r8
 *   @0x236d60 str r10, [r0, r8]
 *   @0x236d64 cmp r5, #0
 *   @0x236d68 str r10, [r3, #0x4]
 *   @0x236d6c beq 0x236da0 <_ZN14CPhysicsObjectD2Ev+0x140>
 *   @0x236d70 ldr r6, [r5, #0x4]
 *   @0x236d74 ldr r0, [r5, #0xc]
 *   @0x236d78 bl 0x27d1d0 <_ZdlPv>
 *   @0x236d7c mov r0, r5
 *   @0x236d80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236d84 ldr r3, [r4, #0x8]
 *   @0x236d88 cmp r6, #0
 *   @0x236d8c mov r5, r6
 *   @0x236d90 sub r3, r3, #1
 *   @0x236d94 str r3, [r4, #0x8]
 *   @0x236d98 bne 0x236d70 <_ZN14CPhysicsObjectD2Ev+0x110>
 *   @0x236d9c ldr r0, [r4]
 *   @0x236da0 sub r9, r9, #1
 *   @0x236da4 sub r8, r8, #8
 *   @0x236da8 cmn r9, #1
 *   @0x236dac bne 0x236d58 <_ZN14CPhysicsObjectD2Ev+0xf8>
 *   @0x236db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236db4 mov r0, r4
 *   @0x236db8 bl 0x27d1d0 <_ZdlPv>
 *   @0x236dbc mov r0, r7
 *   @0x236dc0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x236dc4 ldr r0, [r4]
 *   @0x236dc8 b 0x236db0 <_ZN14CPhysicsObjectD2Ev+0x150>
 *   @0x236dcc ldrheq r6, [r11], -r12
 *
 * ══ §18/91 b2ParticleSystem::SolveRigid  0x2d5e54  size 364  91 条（0x2d5e54..0x2d5fc0）
 * @func 0x2d5e54 0x2d5fc0  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x18×2 / 0xa8×1 / 0xc×1 / 0x38×1 / 0x40×1
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5e54 push {r4, r5, r6, lr}
 *   @0x2d5e58 vpush {d8, d9}
 *   @0x2d5e5c mov r6, r0
 *   @0x2d5e60 ldr r4, [r0, #0xa8]
 *   @0x2d5e64 mov r5, r1
 *   @0x2d5e68 cmp r4, #0
 *   @0x2d5e6c beq 0x2d5fb8 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x164>
 *   @0x2d5e70 vmov.f32 s18, #1.000000e+00
 *   @0x2d5e74 b 0x2d5e84 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x30>
 *   @0x2d5e78 ldr r4, [r4, #0x18]
 *   @0x2d5e7c cmp r4, #0
 *   @0x2d5e80 beq 0x2d5fb8 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x164>
 *   @0x2d5e84 ldr r3, [r4, #0xc]
 *   @0x2d5e88 tst r3, #2
 *   @0x2d5e8c beq 0x2d5e78 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x24>
 *   @0x2d5e90 mov r0, r4
 *   @0x2d5e94 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d5e98 vldr s17, [r5]
 *   @0x2d5e9c vldr s19, [r4, #56]
 *   @0x2d5ea0 vmul.f32 s19, s17, s19
 *   @0x2d5ea4 vmov r0, s19
 *   @0x2d5ea8 bl 0xb6580 <sinf@plt>
 *   @0x2d5eac vmov s16, r0
 *   @0x2d5eb0 vmov r0, s19
 *   @0x2d5eb4 bl 0xb658c <cosf@plt>
 *   @0x2d5eb8 vldr s9, [r4, #44]
 *   @0x2d5ebc vmul.f32 s10, s9, s16
 *   @0x2d5ec0 vldr s7, [r4, #40]
 *   @0x2d5ec4 vldr s15, [r4, #64]
 *   @0x2d5ec8 vldr s4, [r4, #48]
 *   @0x2d5ecc vldr s3, [r4, #52]
 *   @0x2d5ed0 vldr s8, [r4, #68]
 *   @0x2d5ed4 vldr s5, [r4, #60]
 *   @0x2d5ed8 vldr s6, [r4, #72]
 *   @0x2d5edc ldmib r4, {r2, r12}
 *   @0x2d5ee0 vldr s12, [r5, #4]
 *   @0x2d5ee4 cmp r2, r12
 *   @0x2d5ee8 vmov.f32 s2, s7
 *   @0x2d5eec vmul.f32 s14, s16, s15
 *   @0x2d5ef0 vmla.f32 s2, s17, s4
 *   @0x2d5ef4 vmov s11, r0
 *   @0x2d5ef8 vmul.f32 s13, s9, s11
 *   @0x2d5efc vmul.f32 s15, s11, s15
 *   @0x2d5f00 vnmls.f32 s10, s7, s11
 *   @0x2d5f04 vmla.f32 s13, s7, s16
 *   @0x2d5f08 vmla.f32 s9, s17, s3
 *   @0x2d5f0c vmul.f32 s7, s11, s8
 *   @0x2d5f10 vmul.f32 s8, s16, s8
 *   @0x2d5f14 vnmls.f32 s14, s11, s5
 *   @0x2d5f18 vmla.f32 s15, s16, s5
 *   @0x2d5f1c vnmls.f32 s8, s11, s6
 *   @0x2d5f20 vmla.f32 s7, s16, s6
 *   @0x2d5f24 vstr s8, [r4, #72]
 *   @0x2d5f28 vsub.f32 s10, s2, s10
 *   @0x2d5f2c vstr s7, [r4, #68]
 *   @0x2d5f30 vsub.f32 s9, s9, s13
 *   @0x2d5f34 vadd.f32 s14, s10, s14
 *   @0x2d5f38 vadd.f32 s15, s9, s15
 *   @0x2d5f3c vstr s14, [r4, #60]
 *   @0x2d5f40 vsub.f32 s11, s11, s18
 *   @0x2d5f44 vstr s15, [r4, #64]
 *   @0x2d5f48 vmul.f32 s10, s12, s10
 *   @0x2d5f4c vmul.f32 s9, s12, s9
 *   @0x2d5f50 vmul.f32 s11, s12, s11
 *   @0x2d5f54 vmul.f32 s12, s12, s16
 *   @0x2d5f58 bge 0x2d5e78 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x24>
 *   @0x2d5f5c ldr r3, [r6, #0x38]
 *   @0x2d5f60 lsl r2, r2, #3
 *   @0x2d5f64 ldr r1, [r6, #0x40]
 *   @0x2d5f68 add r12, r3, r12, lsl #3
 *   @0x2d5f6c add r3, r3, r2
 *   @0x2d5f70 add r2, r1, r2
 *   @0x2d5f74 vldr s15, [r3, #4]
 *   @0x2d5f78 vldr s13, [r3]
 *   @0x2d5f7c add r3, r3, #8
 *   @0x2d5f80 add r2, r2, #8
 *   @0x2d5f84 cmp r3, r12
 *   @0x2d5f88 vmul.f32 s14, s12, s15
 *   @0x2d5f8c vmul.f32 s15, s11, s15
 *   @0x2d5f90 vnmls.f32 s14, s11, s13
 *   @0x2d5f94 vmla.f32 s15, s12, s13
 *   @0x2d5f98 vadd.f32 s14, s10, s14
 *   @0x2d5f9c vadd.f32 s15, s9, s15
 *   @0x2d5fa0 vstr s14, [r2, #-8]
 *   @0x2d5fa4 vstr s15, [r2, #-4]
 *   @0x2d5fa8 bne 0x2d5f74 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x120>
 *   @0x2d5fac ldr r4, [r4, #0x18]
 *   @0x2d5fb0 cmp r4, #0
 *   @0x2d5fb4 bne 0x2d5e84 <_ZN16b2ParticleSystem10SolveRigidERK10b2TimeStep+0x30>
 *   @0x2d5fb8 vpop {d8, d9}
 *   @0x2d5fbc pop {r4, r5, r6, pc}
 *
 * ══ §19/91 WithObjIterator::WithObjIterator  0x19d060  size 360  90 条（0x19d060..0x19d1c8）
 * @func 0x19d060 0x19d1c8  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×11 / 0x18×4 / 0x8×4 / 0xc×4 / 0x3×2 / 0x-4×1 / 0x14×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d060 str r4, [sp, #-0x4]!
 *   @0x19d064 cmn r1, #1
 *   @0x19d068 ldrb r12, [sp, #0x4]
 *   @0x19d06c mvn r4, #0
 *   @0x19d070 str r1, [r0, #0x14]
 *   @0x19d074 str r4, [r0, #0x18]
 *   @0x19d078 strb r12, [r0, #0x20]
 *   @0x19d07c mov r12, #0
 *   @0x19d080 streq r2, [r0, #0x10]
 *   @0x19d084 str r12, [r0]
 *   @0x19d088 str r12, [r0, #0x4]
 *   @0x19d08c str r12, [r0, #0x8]
 *   @0x19d090 str r12, [r0, #0x1c]
 *   @0x19d094 beq 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8>
 *   @0x19d098 cmn r1, #2
 *   @0x19d09c beq 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110>
 *   @0x19d0a0 cmn r1, #3
 *   @0x19d0a4 beq 0x19d18c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x12c>
 *   @0x19d0a8 movw r3, #0x869f
 *   @0x19d0ac movt r3, #0x1
 *   @0x19d0b0 cmp r1, r3
 *   @0x19d0b4 bgt 0x19d130 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xd0>
 *   @0x19d0b8 ldr r3, [pc, #0xfc]
 *   @0x19d0bc str r12, [r0, #0x18]
 *   @0x19d0c0 ldr r3, [pc, r3]
 *   @0x19d0c4 ldr r3, [r3]
 *   @0x19d0c8 ldr r2, [r3, #0x4]
 *   @0x19d0cc ldr r3, [r3]
 *   @0x19d0d0 and r2, r1, r2
 *   @0x19d0d4 ldr r3, [r3, r2, lsl #3]
 *   @0x19d0d8 cmp r3, #0
 *   @0x19d0dc bne 0x19d0f0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x90>
 *   @0x19d0e0 b 0x19d17c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x11c>
 *   @0x19d0e4 ldr r3, [r3, #0x4]
 *   @0x19d0e8 cmp r3, #0
 *   @0x19d0ec beq 0x19d17c <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x11c>
 *   @0x19d0f0 ldr r2, [r3, #0x8]
 *   @0x19d0f4 cmp r1, r2
 *   @0x19d0f8 bne 0x19d0e4 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x84>
 *   @0x19d0fc ldr r3, [r3, #0xc]
 *   @0x19d100 cmp r3, #0
 *   @0x19d104 str r3, [r0, #0xc]
 *   @0x19d108 beq 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8>
 *   @0x19d10c ldr r3, [r3, #0xd0]
 *   @0x19d110 cmp r3, #0
 *   @0x19d114 str r3, [r0]
 *   @0x19d118 beq 0x19d1b0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x150>
 *   @0x19d11c ldr r3, [r3, #0x8]
 *   @0x19d120 cmp r3, #0
 *   @0x19d124 beq 0x19d1b0 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x150>
 *   @0x19d128 ldr r4, [sp], #4
 *   @0x19d12c bx lr
 *   @0x19d130 ldr r3, [pc, #0x88]
 *   @0x19d134 ldr r3, [pc, r3]
 *   @0x19d138 ldr r2, [r3, #0x4]
 *   @0x19d13c ldr r3, [r3]
 *   @0x19d140 and r2, r1, r2
 *   @0x19d144 ldr r3, [r3, r2, lsl #3]
 *   @0x19d148 cmp r3, #0
 *   @0x19d14c bne 0x19d160 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x100>
 *   @0x19d150 b 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110>
 *   @0x19d154 ldr r3, [r3, #0x4]
 *   @0x19d158 cmp r3, #0
 *   @0x19d15c beq 0x19d170 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0x110>
 *   @0x19d160 ldr r2, [r3, #0x8]
 *   @0x19d164 cmp r1, r2
 *   @0x19d168 bne 0x19d154 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xf4>
 *   @0x19d16c ldr r3, [r3, #0xc]
 *   @0x19d170 str r3, [r0, #0x10]
 *   @0x19d174 ldr r4, [sp], #4
 *   @0x19d178 bx lr
 *   @0x19d17c mov r3, #0
 *   @0x19d180 str r3, [r0, #0xc]
 *   @0x19d184 ldr r4, [sp], #4
 *   @0x19d188 bx lr
 *   @0x19d18c ldr r3, [pc, #0x30]
 *   @0x19d190 mvn r2, #1
 *   @0x19d194 ldr r4, [sp], #4
 *   @0x19d198 ldr r3, [pc, r3]
 *   @0x19d19c ldr r3, [r3]
 *   @0x19d1a0 ldr r3, [r3, #0x80]
 *   @0x19d1a4 str r2, [r0, #0x18]
 *   @0x19d1a8 str r3, [r0, #0x4]
 *   @0x19d1ac bx lr
 *   @0x19d1b0 mov r3, #1
 *   @0x19d1b4 str r3, [r0, #0x18]
 *   @0x19d1b8 b 0x19d128 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b+0xc8>
 *   @0x19d1bc eoreq r0, r5, r12, ror r11
 *   @0x19d1c0 eoreq r0, r5, r0, lsl r11
 *   @0x19d1c4 mlaeq r5, r0, r7, r0
 *
 * ══ §20/91 Graphics::FlushTexture  0x1811bc  size 356  89 条（0x1811bc..0x181320）
 * @func 0x1811bc 0x181320  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1811d8→0x479bb8, 0x181204→0x3f26dc, 0x181218→0x479bfc, 0x181244→0x3f26dc, 0x181258→0x479b68, 0x181284→0x3f26dc, 0x181298→0x479b68, 0x1812bc→0x479aa4
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x18×2 / 0x1c×2 / 0x20×2 / 0x134×1 / 0x128×1 / 0x100×1 / 0xf0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1811bc push {r3, r4, r5, lr}
 *   @0x1811c0 mov r4, r0
 *   @0x1811c4 ldr r3, [r0, #0x14]
 *   @0x1811c8 ldr r5, [pc, #0x134]
 *   @0x1811cc cmn r3, #1
 *   @0x1811d0 add r5, pc, r5
 *   @0x1811d4 beq 0x1811f8 <_ZN8Graphics12FlushTextureEPv+0x3c>
 *   @0x1811d8 ldr r3, [pc, #0x128]
 *   @0x1811dc mov r0, #1
 *   @0x1811e0 add r1, r4, #20
 *   @0x1811e4 ldr r3, [r5, r3]
 *   @0x1811e8 ldr r3, [r3]
 *   @0x1811ec blx r3
 *   @0x1811f0 mvn r3, #0
 *   @0x1811f4 str r3, [r4, #0x14]
 *   @0x1811f8 ldr r3, [r4, #0x18]
 *   @0x1811fc cmn r3, #1
 *   @0x181200 beq 0x181238 <_ZN8Graphics12FlushTextureEPv+0x7c>
 *   @0x181204 ldr r3, [pc, #0x100]
 *   @0x181208 ldr r3, [r5, r3]
 *   @0x18120c ldr r0, [r3]
 *   @0x181210 cmp r0, #1
 *   @0x181214 beq 0x1812ec <_ZN8Graphics12FlushTextureEPv+0x130>
 *   @0x181218 ldr r3, [pc, #0xf0]
 *   @0x18121c mov r0, #1
 *   @0x181220 add r1, r4, #24
 *   @0x181224 ldr r3, [r5, r3]
 *   @0x181228 ldr r3, [r3]
 *   @0x18122c blx r3
 *   @0x181230 mvn r3, #0
 *   @0x181234 str r3, [r4, #0x18]
 *   @0x181238 ldr r3, [r4, #0x1c]
 *   @0x18123c cmn r3, #1
 *   @0x181240 beq 0x181278 <_ZN8Graphics12FlushTextureEPv+0xbc>
 *   @0x181244 ldr r3, [pc, #0xc0]
 *   @0x181248 ldr r3, [r5, r3]
 *   @0x18124c ldr r0, [r3]
 *   @0x181250 cmp r0, #1
 *   @0x181254 beq 0x1812d4 <_ZN8Graphics12FlushTextureEPv+0x118>
 *   @0x181258 ldr r3, [pc, #0xb4]
 *   @0x18125c mov r0, #1
 *   @0x181260 add r1, r4, #28
 *   @0x181264 ldr r3, [r5, r3]
 *   @0x181268 ldr r3, [r3]
 *   @0x18126c blx r3
 *   @0x181270 mvn r3, #0
 *   @0x181274 str r3, [r4, #0x1c]
 *   @0x181278 ldr r3, [r4, #0x20]
 *   @0x18127c cmn r3, #1
 *   @0x181280 popeq {r3, r4, r5, pc}
 *   @0x181284 ldr r3, [pc, #0x80]
 *   @0x181288 ldr r3, [r5, r3]
 *   @0x18128c ldr r0, [r3]
 *   @0x181290 cmp r0, #1
 *   @0x181294 beq 0x1812bc <_ZN8Graphics12FlushTextureEPv+0x100>
 *   @0x181298 ldr r3, [pc, #0x74]
 *   @0x18129c mov r0, #1
 *   @0x1812a0 add r1, r4, #32
 *   @0x1812a4 ldr r3, [r5, r3]
 *   @0x1812a8 ldr r3, [r3]
 *   @0x1812ac blx r3
 *   @0x1812b0 mvn r3, #0
 *   @0x1812b4 str r3, [r4, #0x20]
 *   @0x1812b8 pop {r3, r4, r5, pc}
 *   @0x1812bc ldr r3, [pc, #0x54]
 *   @0x1812c0 add r1, r4, #32
 *   @0x1812c4 ldr r3, [r5, r3]
 *   @0x1812c8 ldr r3, [r3]
 *   @0x1812cc blx r3
 *   @0x1812d0 b 0x1812b0 <_ZN8Graphics12FlushTextureEPv+0xf4>
 *   @0x1812d4 ldr r3, [pc, #0x3c]
 *   @0x1812d8 add r1, r4, #28
 *   @0x1812dc ldr r3, [r5, r3]
 *   @0x1812e0 ldr r3, [r3]
 *   @0x1812e4 blx r3
 *   @0x1812e8 b 0x181270 <_ZN8Graphics12FlushTextureEPv+0xb4>
 *   @0x1812ec ldr r3, [pc, #0x28]
 *   @0x1812f0 add r1, r4, #24
 *   @0x1812f4 ldr r3, [r5, r3]
 *   @0x1812f8 ldr r3, [r3]
 *   @0x1812fc blx r3
 *   @0x181300 b 0x181230 <_ZN8Graphics12FlushTextureEPv+0x74>
 *   @0x181304 eoreq r0, r7, r0, lsl #21
 *   @0x181308 .word 0xffffbb24
 *   @0x18130c .word 0xffffe7b8
 *   @0x181310 .word 0xffffbc80
 *   @0x181314 .word 0xffffbcbc
 *   @0x181318 .word 0xffffbc0c
 *   @0x18131c .word 0xffffbb70
 *
 * ══ §21/91 HandleKeyPress  0x1d5974  size 356  89 条（0x1d5974..0x1d5ad8）
 * @func 0x1d5974 0x1d5ad8  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5978→0x536f20, 0x1d5980→0x536f70, 0x1d59bc→0x53ab70, 0x1d59c4→0x542374
 * 调用序列: HandleKeyPress(int)+0x148 / HandleKeyPress(int)+0x128 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x148×2 / 0x14×2 / 0x10×2 / 0x144×1 / 0x10c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5974 ldr r1, [pc, #0x148]
 *   @0x1d5978 ldr r3, [pc, #0x148]
 *   @0x1d597c add r1, pc, r1
 *   @0x1d5980 ldr r12, [pc, #0x144]
 *   @0x1d5984 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5988 add r9, r0, #2304
 *   @0x1d598c mov r8, r0
 *   @0x1d5990 ldr r0, [r1, r3]
 *   @0x1d5994 sub sp, sp, #28
 *   @0x1d5998 ldrd r10, r11, [r0]
 *   @0x1d599c adds r2, r10, #1
 *   @0x1d59a0 adc r3, r11, #0
 *   @0x1d59a4 strd r10, r11, [sp, #8]
 *   @0x1d59a8 strd r2, r3, [r0]
 *   @0x1d59ac ldr r11, [r1, r12]
 *   @0x1d59b0 ldr r3, [r11, r9, lsl #2]
 *   @0x1d59b4 cmp r3, #0
 *   @0x1d59b8 ble 0x1d5abc <_Z14HandleKeyPressi+0x148>
 *   @0x1d59bc ldr r2, [pc, #0x10c]
 *   @0x1d59c0 mov r7, #0
 *   @0x1d59c4 ldr r3, [pc, #0x108]
 *   @0x1d59c8 ldr r10, [r1, r2]
 *   @0x1d59cc ldr r3, [r1, r3]
 *   @0x1d59d0 add r10, r10, r9, lsl #3
 *   @0x1d59d4 str r3, [sp, #0x14]
 *   @0x1d59d8 ldr r12, [sp, #0x14]
 *   @0x1d59dc ldr r1, [r10, #0x4]
 *   @0x1d59e0 ldr r3, [r12]
 *   @0x1d59e4 ldr r1, [r1, r7, lsl #2]
 *   @0x1d59e8 ldr r2, [r3, #0x4]
 *   @0x1d59ec ldr r3, [r3]
 *   @0x1d59f0 and r2, r1, r2
 *   @0x1d59f4 ldr r3, [r3, r2, lsl #3]
 *   @0x1d59f8 cmp r3, #0
 *   @0x1d59fc bne 0x1d5a10 <_Z14HandleKeyPressi+0x9c>
 *   @0x1d5a00 b 0x1d5aac <_Z14HandleKeyPressi+0x138>
 *   @0x1d5a04 ldr r3, [r3, #0x4]
 *   @0x1d5a08 cmp r3, #0
 *   @0x1d5a0c beq 0x1d5aac <_Z14HandleKeyPressi+0x138>
 *   @0x1d5a10 ldr r2, [r3, #0x8]
 *   @0x1d5a14 cmp r1, r2
 *   @0x1d5a18 bne 0x1d5a04 <_Z14HandleKeyPressi+0x90>
 *   @0x1d5a1c ldr r3, [r3, #0xc]
 *   @0x1d5a20 cmp r3, #0
 *   @0x1d5a24 beq 0x1d5aac <_Z14HandleKeyPressi+0x138>
 *   @0x1d5a28 ldr r6, [r3, #0xc4]
 *   @0x1d5a2c cmp r6, #0
 *   @0x1d5a30 beq 0x1d5aac <_Z14HandleKeyPressi+0x138>
 *   @0x1d5a34 ldr r3, [r6, #0x8]
 *   @0x1d5a38 cmp r3, #0
 *   @0x1d5a3c beq 0x1d5aac <_Z14HandleKeyPressi+0x138>
 *   @0x1d5a40 str r11, [sp, #0x10]
 *   @0x1d5a44 str r10, [sp, #0x4]
 *   @0x1d5a48 b 0x1d5a58 <_Z14HandleKeyPressi+0xe4>
 *   @0x1d5a4c ldr r3, [r6, #0x8]
 *   @0x1d5a50 cmp r3, #0
 *   @0x1d5a54 beq 0x1d5aa4 <_Z14HandleKeyPressi+0x130>
 *   @0x1d5a58 ldr r0, [r6, #0x8]
 *   @0x1d5a5c ldr r6, [r6]
 *   @0x1d5a60 ldrb r3, [r0, #0x68]
 *   @0x1d5a64 cmp r3, #0
 *   @0x1d5a68 bne 0x1d5a9c <_Z14HandleKeyPressi+0x128>
 *   @0x1d5a6c ldrb r3, [r0, #0x69]
 *   @0x1d5a70 cmp r3, #0
 *   @0x1d5a74 bne 0x1d5a9c <_Z14HandleKeyPressi+0x128>
 *   @0x1d5a78 ldrd r4, r5, [r0, #112]
 *   @0x1d5a7c mov r1, r0
 *   @0x1d5a80 ldrd r10, r11, [sp, #8]
 *   @0x1d5a84 mov r2, #9
 *   @0x1d5a88 mov r3, r8
 *   @0x1d5a8c cmp r10, r4
 *   @0x1d5a90 sbcs r11, r11, r5
 *   @0x1d5a94 blt 0x1d5a9c <_Z14HandleKeyPressi+0x128>
 *   @0x1d5a98 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d5a9c cmp r6, #0
 *   @0x1d5aa0 bne 0x1d5a4c <_Z14HandleKeyPressi+0xd8>
 *   @0x1d5aa4 ldr r11, [sp, #0x10]
 *   @0x1d5aa8 ldr r10, [sp, #0x4]
 *   @0x1d5aac ldr r3, [r11, r9, lsl #2]
 *   @0x1d5ab0 add r7, r7, #1
 *   @0x1d5ab4 cmp r3, r7
 *   @0x1d5ab8 bgt 0x1d59d8 <_Z14HandleKeyPressi+0x64>
 *   @0x1d5abc add sp, sp, #28
 *   @0x1d5ac0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d5ac4 .word 0x0021c2d4
 *   @0x1d5ac8 .word 0xffffdeb4
 *   @0x1d5acc .word 0xffffdeb8
 *   @0x1d5ad0 .word 0xffffdebc
 *   @0x1d5ad4 .word 0xffffbfec
 *
 * ══ §22/91 HandleKeyRelease  0x1d5ad8  size 356  89 条（0x1d5ad8..0x1d5c3c）
 * @func 0x1d5ad8 0x1d5c3c  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5adc→0x536f20, 0x1d5ae4→0x536f70, 0x1d5b20→0x53ab70, 0x1d5b28→0x542374
 * 调用序列: HandleKeyRelease(int)+0x148 / HandleKeyRelease(int)+0x128 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x148×2 / 0x14×2 / 0x10×2 / 0x144×1 / 0x10c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5ad8 ldr r1, [pc, #0x148]
 *   @0x1d5adc ldr r3, [pc, #0x148]
 *   @0x1d5ae0 add r1, pc, r1
 *   @0x1d5ae4 ldr r12, [pc, #0x144]
 *   @0x1d5ae8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5aec add r9, r0, #2560
 *   @0x1d5af0 mov r8, r0
 *   @0x1d5af4 ldr r0, [r1, r3]
 *   @0x1d5af8 sub sp, sp, #28
 *   @0x1d5afc ldrd r10, r11, [r0]
 *   @0x1d5b00 adds r2, r10, #1
 *   @0x1d5b04 adc r3, r11, #0
 *   @0x1d5b08 strd r10, r11, [sp, #8]
 *   @0x1d5b0c strd r2, r3, [r0]
 *   @0x1d5b10 ldr r11, [r1, r12]
 *   @0x1d5b14 ldr r3, [r11, r9, lsl #2]
 *   @0x1d5b18 cmp r3, #0
 *   @0x1d5b1c ble 0x1d5c20 <_Z16HandleKeyReleasei+0x148>
 *   @0x1d5b20 ldr r2, [pc, #0x10c]
 *   @0x1d5b24 mov r7, #0
 *   @0x1d5b28 ldr r3, [pc, #0x108]
 *   @0x1d5b2c ldr r10, [r1, r2]
 *   @0x1d5b30 ldr r3, [r1, r3]
 *   @0x1d5b34 add r10, r10, r9, lsl #3
 *   @0x1d5b38 str r3, [sp, #0x14]
 *   @0x1d5b3c ldr r12, [sp, #0x14]
 *   @0x1d5b40 ldr r1, [r10, #0x4]
 *   @0x1d5b44 ldr r3, [r12]
 *   @0x1d5b48 ldr r1, [r1, r7, lsl #2]
 *   @0x1d5b4c ldr r2, [r3, #0x4]
 *   @0x1d5b50 ldr r3, [r3]
 *   @0x1d5b54 and r2, r1, r2
 *   @0x1d5b58 ldr r3, [r3, r2, lsl #3]
 *   @0x1d5b5c cmp r3, #0
 *   @0x1d5b60 bne 0x1d5b74 <_Z16HandleKeyReleasei+0x9c>
 *   @0x1d5b64 b 0x1d5c10 <_Z16HandleKeyReleasei+0x138>
 *   @0x1d5b68 ldr r3, [r3, #0x4]
 *   @0x1d5b6c cmp r3, #0
 *   @0x1d5b70 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138>
 *   @0x1d5b74 ldr r2, [r3, #0x8]
 *   @0x1d5b78 cmp r1, r2
 *   @0x1d5b7c bne 0x1d5b68 <_Z16HandleKeyReleasei+0x90>
 *   @0x1d5b80 ldr r3, [r3, #0xc]
 *   @0x1d5b84 cmp r3, #0
 *   @0x1d5b88 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138>
 *   @0x1d5b8c ldr r6, [r3, #0xc4]
 *   @0x1d5b90 cmp r6, #0
 *   @0x1d5b94 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138>
 *   @0x1d5b98 ldr r3, [r6, #0x8]
 *   @0x1d5b9c cmp r3, #0
 *   @0x1d5ba0 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138>
 *   @0x1d5ba4 str r11, [sp, #0x10]
 *   @0x1d5ba8 str r10, [sp, #0x4]
 *   @0x1d5bac b 0x1d5bbc <_Z16HandleKeyReleasei+0xe4>
 *   @0x1d5bb0 ldr r3, [r6, #0x8]
 *   @0x1d5bb4 cmp r3, #0
 *   @0x1d5bb8 beq 0x1d5c08 <_Z16HandleKeyReleasei+0x130>
 *   @0x1d5bbc ldr r0, [r6, #0x8]
 *   @0x1d5bc0 ldr r6, [r6]
 *   @0x1d5bc4 ldrb r3, [r0, #0x68]
 *   @0x1d5bc8 cmp r3, #0
 *   @0x1d5bcc bne 0x1d5c00 <_Z16HandleKeyReleasei+0x128>
 *   @0x1d5bd0 ldrb r3, [r0, #0x69]
 *   @0x1d5bd4 cmp r3, #0
 *   @0x1d5bd8 bne 0x1d5c00 <_Z16HandleKeyReleasei+0x128>
 *   @0x1d5bdc ldrd r4, r5, [r0, #112]
 *   @0x1d5be0 mov r1, r0
 *   @0x1d5be4 ldrd r10, r11, [sp, #8]
 *   @0x1d5be8 mov r2, #10
 *   @0x1d5bec mov r3, r8
 *   @0x1d5bf0 cmp r10, r4
 *   @0x1d5bf4 sbcs r11, r11, r5
 *   @0x1d5bf8 blt 0x1d5c00 <_Z16HandleKeyReleasei+0x128>
 *   @0x1d5bfc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d5c00 cmp r6, #0
 *   @0x1d5c04 bne 0x1d5bb0 <_Z16HandleKeyReleasei+0xd8>
 *   @0x1d5c08 ldr r11, [sp, #0x10]
 *   @0x1d5c0c ldr r10, [sp, #0x4]
 *   @0x1d5c10 ldr r3, [r11, r9, lsl #2]
 *   @0x1d5c14 add r7, r7, #1
 *   @0x1d5c18 cmp r3, r7
 *   @0x1d5c1c bgt 0x1d5b3c <_Z16HandleKeyReleasei+0x64>
 *   @0x1d5c20 add sp, sp, #28
 *   @0x1d5c24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d5c28 eoreq r12, r1, r0, ror r1
 *   @0x1d5c2c .word 0xffffdeb4
 *   @0x1d5c30 .word 0xffffdeb8
 *   @0x1d5c34 .word 0xffffdebc
 *   @0x1d5c38 .word 0xffffbfec
 *
 * ══ §23/91 _spAnimationState_setCurrent  0x283698  size 356  89 条（0x283698..0x2837fc）
 * @func 0x283698 0x2837fc  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAnimationState_expandToIndex / spAnimationStateData_getMix / _spAnimationState_setCurrent+0x154
 * 字段偏移 top8: 0x8×5 / 0x28×2 / 0xc×2 / 0x20×2 / 0x10×2 / 0x2×2 / 0x30×1 / 0x2c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283698 push {r4, r5, r6, r7, r8, lr}
 *   @0x28369c sub sp, sp, #8
 *   @0x2836a0 mov r5, r2
 *   @0x2836a4 mov r4, r0
 *   @0x2836a8 mov r7, r1
 *   @0x2836ac bl 0x28362c <_spAnimationState_expandToIndex>
 *   @0x2836b0 subs r6, r0, #0
 *   @0x2836b4 beq 0x28376c <_spAnimationState_setCurrent+0xd4>
 *   @0x2836b8 ldr r12, [r6, #0x28]
 *   @0x2836bc mov r3, #0
 *   @0x2836c0 ldr r8, [r6, #0x8]
 *   @0x2836c4 cmp r12, r3
 *   @0x2836c8 str r3, [r6, #0x8]
 *   @0x2836cc beq 0x2836e4 <_spAnimationState_setCurrent+0x4c>
 *   @0x2836d0 str r3, [sp]
 *   @0x2836d4 mov r0, r4
 *   @0x2836d8 mov r1, r7
 *   @0x2836dc mov r2, #1
 *   @0x2836e0 blx r12
 *   @0x2836e4 ldr r12, [r4, #0x8]
 *   @0x2836e8 cmp r12, #0
 *   @0x2836ec beq 0x283708 <_spAnimationState_setCurrent+0x70>
 *   @0x2836f0 mov r3, #0
 *   @0x2836f4 mov r0, r4
 *   @0x2836f8 str r3, [sp]
 *   @0x2836fc mov r1, r7
 *   @0x283700 mov r2, #1
 *   @0x283704 blx r12
 *   @0x283708 ldr r0, [r4]
 *   @0x28370c ldr r1, [r6, #0xc]
 *   @0x283710 ldr r2, [r5, #0xc]
 *   @0x283714 bl 0x283ca8 <spAnimationStateData_getMix>
 *   @0x283718 mov r3, #0
 *   @0x28371c vmov s15, r0
 *   @0x283720 str r0, [r5, #0x30]
 *   @0x283724 vcmpe.f32 s15, #0
 *   @0x283728 vmrs APSR_nzcv, fpscr
 *   @0x28372c ble 0x2837ec <_spAnimationState_setCurrent+0x154>
 *   @0x283730 cmp r8, #0
 *   @0x283734 str r3, [r5, #0x2c]
 *   @0x283738 beq 0x2837b0 <_spAnimationState_setCurrent+0x118>
 *   @0x28373c vldr s15, [r6, #48]
 *   @0x283740 vldr s14, [r6, #44]
 *   @0x283744 vdiv.f32 s14, s14, s15
 *   @0x283748 vmov.f32 s15, #5.000000e-01
 *   @0x28374c vcmpe.f32 s14, s15
 *   @0x283750 vmrs APSR_nzcv, fpscr
 *   @0x283754 strmi r8, [r5, #0x8]
 *   @0x283758 movmi r8, r6
 *   @0x28375c bpl 0x2837b0 <_spAnimationState_setCurrent+0x118>
 *   @0x283760 mov r0, r8
 *   @0x283764 ldr r3, [r4, #0x20]
 *   @0x283768 blx r3
 *   @0x28376c ldr r3, [r4, #0x10]
 *   @0x283770 str r5, [r3, r7, lsl #2]
 *   @0x283774 ldr r12, [r5, #0x28]
 *   @0x283778 cmp r12, #0
 *   @0x28377c beq 0x2837c0 <_spAnimationState_setCurrent+0x128>
 *   @0x283780 mov r3, #0
 *   @0x283784 mov r0, r4
 *   @0x283788 mov r2, r3
 *   @0x28378c str r3, [sp]
 *   @0x283790 mov r1, r7
 *   @0x283794 blx r12
 *   @0x283798 ldr r3, [r4, #0x10]
 *   @0x28379c ldr r3, [r3, r7, lsl #2]
 *   @0x2837a0 cmp r3, r5
 *   @0x2837a4 beq 0x2837c0 <_spAnimationState_setCurrent+0x128>
 *   @0x2837a8 add sp, sp, #8
 *   @0x2837ac pop {r4, r5, r6, r7, r8, pc}
 *   @0x2837b0 str r6, [r5, #0x8]
 *   @0x2837b4 cmp r8, #0
 *   @0x2837b8 bne 0x283760 <_spAnimationState_setCurrent+0xc8>
 *   @0x2837bc b 0x28376c <_spAnimationState_setCurrent+0xd4>
 *   @0x2837c0 ldr r12, [r4, #0x8]
 *   @0x2837c4 cmp r12, #0
 *   @0x2837c8 beq 0x2837a8 <_spAnimationState_setCurrent+0x110>
 *   @0x2837cc mov r3, #0
 *   @0x2837d0 mov r0, r4
 *   @0x2837d4 mov r2, r3
 *   @0x2837d8 mov r1, r7
 *   @0x2837dc str r3, [sp]
 *   @0x2837e0 blx r12
 *   @0x2837e4 add sp, sp, #8
 *   @0x2837e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2837ec mov r0, r6
 *   @0x2837f0 ldr r3, [r4, #0x20]
 *   @0x2837f4 blx r3
 *   @0x2837f8 b 0x2837b4 <_spAnimationState_setCurrent+0x11c>
 *
 * ══ §24/91 b2World::b2World  0x2c8e10  size 356  89 条（0x2c8e10..0x2c8f74）
 * @func 0x2c8e10 0x2c8f74  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::b2BlockAllocator() / b2StackAllocator::b2StackAllocator() / b2ContactManager::b2ContactManager() / b2ParticleSystem::b2ParticleSystem() / 0xb65b0
 * 字段偏移 top8: 0x4×2 / 0x120×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c8e10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c8e14 sub sp, sp, #12
 *   @0x2c8e18 mov r4, r0
 *   @0x2c8e1c mov r6, r1
 *   @0x2c8e20 add r5, r4, #102400
 *   @0x2c8e24 bl 0x2c64d0 <_ZN16b2BlockAllocatorC2Ev>
 *   @0x2c8e28 add r0, r4, #68
 *   @0x2c8e2c movw r7, #0x9244
 *   @0x2c8e30 bl 0x2e0f04 <_ZN16b2StackAllocatorC2Ev>
 *   @0x2c8e34 add r0, r5, #472
 *   @0x2c8e38 bl 0x2c7850 <_ZN16b2ContactManagerC2Ev>
 *   @0x2c8e3c add r0, r5, #628
 *   @0x2c8e40 bl 0x2d4fbc <_ZN16b2ParticleSystemC2Ev>
 *   @0x2c8e44 ldr r2, [pc, #0x120]
 *   @0x2c8e48 ldm r6, {r0, r1}
 *   @0x2c8e4c movt r7, #0x1
 *   @0x2c8e50 ldr r2, [pc, r2]
 *   @0x2c8e54 movw r6, #0x9248
 *   @0x2c8e58 movw lr, #0x9228
 *   @0x2c8e5c movt r6, #0x1
 *   @0x2c8e60 ldr r2, [r2]
 *   @0x2c8e64 movt lr, #0x1
 *   @0x2c8e68 movw r12, #0x922c
 *   @0x2c8e6c movt r12, #0x1
 *   @0x2c8e70 mov r3, #1
 *   @0x2c8e74 movw r10, #0x9238
 *   @0x2c8e78 bfi r10, r3, #16, #16
 *   @0x2c8e7c str r2, [sp, #0x4]
 *   @0x2c8e80 add r10, r4, r10
 *   @0x2c8e84 mov r2, #0
 *   @0x2c8e88 movw r9, #0x9230
 *   @0x2c8e8c str r2, [r4, r7]
 *   @0x2c8e90 movt r9, #0x1
 *   @0x2c8e94 str r2, [r4, r6]
 *   @0x2c8e98 movw r8, #0x9234
 *   @0x2c8e9c str r2, [r4, lr]
 *   @0x2c8ea0 movt r8, #0x1
 *   @0x2c8ea4 str r2, [r4, r12]
 *   @0x2c8ea8 movw r7, #0x9250
 *   @0x2c8eac movw r6, #0x9251
 *   @0x2c8eb0 movt r7, #0x1
 *   @0x2c8eb4 bfi r6, r3, #16, #16
 *   @0x2c8eb8 movw lr, #0x9252
 *   @0x2c8ebc movw r12, #0x9253
 *   @0x2c8ec0 bfi lr, r3, #16, #16
 *   @0x2c8ec4 bfi r12, r3, #16, #16
 *   @0x2c8ec8 movw r11, #0x9240
 *   @0x2c8ecc bfi r11, r3, #16, #16
 *   @0x2c8ed0 str r2, [r4, r9]
 *   @0x2c8ed4 movw r9, #0x91d4
 *   @0x2c8ed8 str r2, [r4, r8]
 *   @0x2c8edc bfi r9, r3, #16, #16
 *   @0x2c8ee0 strb r3, [r4, r7]
 *   @0x2c8ee4 movw r8, #0x9224
 *   @0x2c8ee8 strb r3, [r4, r6]
 *   @0x2c8eec bfi r8, r3, #16, #16
 *   @0x2c8ef0 strb r2, [r4, lr]
 *   @0x2c8ef4 movw r7, #0x9348
 *   @0x2c8ef8 strb r3, [r4, r12]
 *   @0x2c8efc bfi r7, r3, #16, #16
 *   @0x2c8f00 strb r3, [r4, r11]
 *   @0x2c8f04 movw r6, #0x934c
 *   @0x2c8f08 stm r10, {r0, r1}
 *   @0x2c8f0c movw r10, #0x924c
 *   @0x2c8f10 bfi r10, r3, #16, #16
 *   @0x2c8f14 bfi r6, r3, #16, #16
 *   @0x2c8f18 add r10, r4, r10
 *   @0x2c8f1c movw lr, #0x9350
 *   @0x2c8f20 bfi lr, r3, #16, #16
 *   @0x2c8f24 mov r3, #4
 *   @0x2c8f28 str r3, [r4, r9]
 *   @0x2c8f2c mov r3, #0
 *   @0x2c8f30 str r3, [r10]
 *   @0x2c8f34 mov r1, r2
 *   @0x2c8f38 ldr r3, [sp, #0x4]
 *   @0x2c8f3c add r0, r5, #596
 *   @0x2c8f40 ldr r12, [pc, #0x28]
 *   @0x2c8f44 mov r2, #32
 *   @0x2c8f48 str r4, [r4, r8]
 *   @0x2c8f4c ldr r12, [pc, r12]
 *   @0x2c8f50 str r4, [r4, r7]
 *   @0x2c8f54 str r12, [r4, r6]
 *   @0x2c8f58 str r3, [r4, lr]
 *   @0x2c8f5c bl 0xb65b0 <memset@plt>
 *   @0x2c8f60 mov r0, r4
 *   @0x2c8f64 add sp, sp, #12
 *   @0x2c8f68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c8f6c andseq r8, r2, r8, lsr #25
 *   @0x2c8f70 ldrheq r8, [r2], -r0
 *
 * ══ §25/91 anon_154a70  0x154a70  size 352  88 条（0x154a70..0x154bd0）
 * @func 0x154a70 0x154bd0  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / operator new(unsigned int) / CDS_Map::CDS_Map() / anon_154a70+0x150 / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x68×3 / 0x2c×3 / 0x1c×2 / 0x8×2 / 0x3c×2 / 0x28×2 / 0x10×1 / 0x14×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x154a70 push {r0, r1, r2, r3}
 *   @0x154a74 mov r0, #4
 *   @0x154a78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x154a7c sub sp, sp, #68
 *   @0x154a80 bl 0x27c524 <_Znwj>
 *   @0x154a84 mov r8, r0
 *   @0x154a88 bl 0x203624 <_ZN7CDS_MapC2Ev>
 *   @0x154a8c ldr r3, [sp, #0x68]
 *   @0x154a90 add r12, sp, #108
 *   @0x154a94 str r12, [sp, #0x1c]
 *   @0x154a98 cmp r3, #0
 *   @0x154a9c ble 0x154bc0 <_Z19YYIAPEventsDispatchv+0xfd8>
 *   @0x154aa0 add r7, sp, #32
 *   @0x154aa4 mov r6, #0
 *   @0x154aa8 add r3, sp, #40
 *   @0x154aac add r11, sp, #36
 *   @0x154ab0 str r3, [sp, #0x10]
 *   @0x154ab4 add r5, sp, #48
 *   @0x154ab8 add r3, sp, #44
 *   @0x154abc mov r10, r12
 *   @0x154ac0 str r3, [sp, #0x14]
 *   @0x154ac4 mov r4, r7
 *   @0x154ac8 add r3, sp, #52
 *   @0x154acc mov r9, r6
 *   @0x154ad0 str r3, [sp, #0x4]
 *   @0x154ad4 add r3, sp, #56
 *   @0x154ad8 str r3, [sp, #0x8]
 *   @0x154adc add r3, sp, #60
 *   @0x154ae0 str r3, [sp, #0xc]
 *   @0x154ae4 b 0x154b1c <_Z19YYIAPEventsDispatchv+0xf34>
 *   @0x154ae8 ldr r2, [sp, #0x3c]
 *   @0x154aec mov r3, #5
 *   @0x154af0 str r9, [sp, #0x28]
 *   @0x154af4 sub r2, r2, #1
 *   @0x154af8 str r3, [sp, #0x2c]
 *   @0x154afc bic r2, r2, #-16777216
 *   @0x154b00 str r9, [sp, #0x20]
 *   @0x154b04 bic r2, r2, #3
 *   @0x154b08 cmp r2, #0
 *   @0x154b0c beq 0x154bac <_Z19YYIAPEventsDispatchv+0xfc4>
 *   @0x154b10 ldr r3, [sp, #0x68]
 *   @0x154b14 cmp r6, r3
 *   @0x154b18 beq 0x154bc0 <_Z19YYIAPEventsDispatchv+0xfd8>
 *   @0x154b1c ldr r1, [r10], #11
 *   @0x154b20 mov r0, r4
 *   @0x154b24 str r9, [r7]
 *   @0x154b28 add r6, r6, #1
 *   @0x154b2c str r9, [r11]
 *   @0x154b30 mov r7, r4
 *   @0x154b34 str r9, [sp, #0x28]
 *   @0x154b38 str r9, [sp, #0x2c]
 *   @0x154b3c str r9, [r5]
 *   @0x154b40 str r9, [sp, #0x34]
 *   @0x154b44 str r9, [sp, #0x38]
 *   @0x154b48 str r9, [sp, #0x3c]
 *   @0x154b4c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x154b50 bic r2, r10, #7
 *   @0x154b54 mov r0, r5
 *   @0x154b58 add r10, r2, #12
 *   @0x154b5c vldr d7, [r2]
 *   @0x154b60 ldr r1, [r2, #0x8]
 *   @0x154b64 vstr d7, [sp, #48]
 *   @0x154b68 str r10, [sp, #0x1c]
 *   @0x154b6c cmp r1, #0
 *   @0x154b70 beq 0x154b78 <_Z19YYIAPEventsDispatchv+0xf90>
 *   @0x154b74 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x154b78 mov r2, r5
 *   @0x154b7c mov r0, r8
 *   @0x154b80 mov r1, r4
 *   @0x154b84 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x154b88 ldr r2, [sp, #0x2c]
 *   @0x154b8c sub r2, r2, #1
 *   @0x154b90 bic r2, r2, #-16777216
 *   @0x154b94 bic r2, r2, #3
 *   @0x154b98 cmp r2, #0
 *   @0x154b9c bne 0x154ae8 <_Z19YYIAPEventsDispatchv+0xf00>
 *   @0x154ba0 mov r0, r4
 *   @0x154ba4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154ba8 b 0x154ae8 <_Z19YYIAPEventsDispatchv+0xf00>
 *   @0x154bac mov r0, r5
 *   @0x154bb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154bb4 ldr r3, [sp, #0x68]
 *   @0x154bb8 cmp r6, r3
 *   @0x154bbc bne 0x154b1c <_Z19YYIAPEventsDispatchv+0xf34>
 *   @0x154bc0 mov r0, r8
 *   @0x154bc4 add sp, sp, #68
 *   @0x154bc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x154bcc add sp, sp, #16
 *
 * ══ §26/91 RenderStateManager::Flush  0x168134  size 352  88 条（0x168134..0x168294）
 * @func 0x168134 0x168294  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetRenderState(eRenderState, unsigned int) / Graphics::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x1e0×1 / 0x1dc×1 / 0x8×1 / 0x270×1 / 0x26c×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168134 ldrd r2, r3, [r0]
 *   @0x168138 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16813c orrs r1, r2, r3
 *   @0x168140 sub sp, sp, #12
 *   @0x168144 mov r8, r0
 *   @0x168148 beq 0x1681d4 <_ZN18RenderStateManager5FlushEv+0xa0>
 *   @0x16814c mov r10, #1
 *   @0x168150 mov r11, #0
 *   @0x168154 mov r9, r0
 *   @0x168158 mov r12, #0
 *   @0x16815c b 0x168174 <_ZN18RenderStateManager5FlushEv+0x40>
 *   @0x168160 add r12, r12, #1
 *   @0x168164 add r9, r9, #4
 *   @0x168168 cmp r12, #36
 *   @0x16816c beq 0x1681c8 <_ZN18RenderStateManager5FlushEv+0x94>
 *   @0x168170 ldm r8, {r2, r3}
 *   @0x168174 lsr r6, r2, r12
 *   @0x168178 rsb r2, r12, #32
 *   @0x16817c orr r6, r6, r3, lsl r2
 *   @0x168180 sub r2, r12, #32
 *   @0x168184 orr r6, r6, r3, lsr r2
 *   @0x168188 lsr r7, r3, r12
 *   @0x16818c and r2, r6, r10
 *   @0x168190 and r3, r7, r11
 *   @0x168194 orrs r1, r2, r3
 *   @0x168198 beq 0x168160 <_ZN18RenderStateManager5FlushEv+0x2c>
 *   @0x16819c ldr r1, [r9, #0x1e0]
 *   @0x1681a0 mov r0, r12
 *   @0x1681a4 str r12, [sp, #0x4]
 *   @0x1681a8 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1681ac ldr r12, [sp, #0x4]
 *   @0x1681b0 add r9, r9, #4
 *   @0x1681b4 ldr r3, [r9, #0x1dc]
 *   @0x1681b8 add r12, r12, #1
 *   @0x1681bc cmp r12, #36
 *   @0x1681c0 str r3, [r9, #0xc]
 *   @0x1681c4 bne 0x168170 <_ZN18RenderStateManager5FlushEv+0x3c>
 *   @0x1681c8 mov r2, #0
 *   @0x1681cc mov r3, #0
 *   @0x1681d0 strd r2, r3, [r8]
 *   @0x1681d4 ldrd r2, r3, [r8, #8]
 *   @0x1681d8 orrs r1, r2, r3
 *   @0x1681dc beq 0x16827c <_ZN18RenderStateManager5FlushEv+0x148>
 *   @0x1681e0 movw r9, #0x6667
 *   @0x1681e4 mov r6, #1
 *   @0x1681e8 mov r7, #0
 *   @0x1681ec movt r9, #0x6666
 *   @0x1681f0 mov r10, r8
 *   @0x1681f4 mov r11, #0
 *   @0x1681f8 b 0x168214 <_ZN18RenderStateManager5FlushEv+0xe0>
 *   @0x1681fc add r11, r11, #1
 *   @0x168200 add r10, r10, #4
 *   @0x168204 cmp r11, #80
 *   @0x168208 beq 0x168270 <_ZN18RenderStateManager5FlushEv+0x13c>
 *   @0x16820c ldr r2, [r8, #0x8]
 *   @0x168210 ldr r3, [r8, #0xc]
 *   @0x168214 lsr r4, r2, r11
 *   @0x168218 rsb r2, r11, #32
 *   @0x16821c orr r4, r4, r3, lsl r2
 *   @0x168220 sub r2, r11, #32
 *   @0x168224 orr r4, r4, r3, lsr r2
 *   @0x168228 lsr r5, r3, r11
 *   @0x16822c and r2, r4, r6
 *   @0x168230 and r3, r5, r7
 *   @0x168234 orrs r1, r2, r3
 *   @0x168238 beq 0x1681fc <_ZN18RenderStateManager5FlushEv+0xc8>
 *   @0x16823c smull r3, r1, r9, r11
 *   @0x168240 asr r3, r11, #31
 *   @0x168244 ldr r2, [r10, #0x270]
 *   @0x168248 add r10, r10, #4
 *   @0x16824c rsb r0, r3, r1, asr #2
 *   @0x168250 add r1, r0, r0, lsl #2
 *   @0x168254 sub r1, r11, r1, lsl #1
 *   @0x168258 add r11, r11, #1
 *   @0x16825c bl 0x1804b0 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej>
 *   @0x168260 ldr r3, [r10, #0x26c]
 *   @0x168264 cmp r11, #80
 *   @0x168268 str r3, [r10, #0x9c]
 *   @0x16826c bne 0x16820c <_ZN18RenderStateManager5FlushEv+0xd8>
 *   @0x168270 mov r2, #0
 *   @0x168274 mov r3, #0
 *   @0x168278 strd r2, r3, [r8, #8]
 *   @0x16827c mov r1, #944
 *   @0x168280 mov r2, #0
 *   @0x168284 mov r3, #0
 *   @0x168288 strd r2, r3, [r8, r1]
 *   @0x16828c add sp, sp, #12
 *   @0x168290 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §27/91 CCamera::CCamera  0x16cfc0  size 352  88 条（0x16cfc0..0x16d120）
 * @func 0x16cfc0 0x16d120  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x38×1 / 0x34×1 / 0x30×1 / 0x28×1 / 0x24×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16cfc0 mov r2, #0
 *   @0x16cfc4 mov r1, #1065353216
 *   @0x16cfc8 mvn r12, #0
 *   @0x16cfcc str r2, [r0, #0x3c]
 *   @0x16cfd0 push {r4, r5}
 *   @0x16cfd4 mov r5, #1
 *   @0x16cfd8 mov r4, #0
 *   @0x16cfdc str r2, [r0, #0x38]
 *   @0x16cfe0 str r2, [r0, #0x34]
 *   @0x16cfe4 str r2, [r0, #0x30]
 *   @0x16cfe8 str r2, [r0, #0x28]
 *   @0x16cfec str r2, [r0, #0x24]
 *   @0x16cff0 str r2, [r0, #0x20]
 *   @0x16cff4 str r2, [r0, #0x1c]
 *   @0x16cff8 str r2, [r0, #0x14]
 *   @0x16cffc str r2, [r0, #0x10]
 *   @0x16d000 str r2, [r0, #0xc]
 *   @0x16d004 str r2, [r0, #0x8]
 *   @0x16d008 str r2, [r0, #0x7c]
 *   @0x16d00c str r2, [r0, #0x78]
 *   @0x16d010 str r2, [r0, #0x74]
 *   @0x16d014 str r2, [r0, #0x70]
 *   @0x16d018 str r1, [r0, #0x40]
 *   @0x16d01c str r1, [r0, #0x2c]
 *   @0x16d020 str r1, [r0, #0x18]
 *   @0x16d024 str r1, [r0, #0x4]
 *   @0x16d028 str r1, [r0, #0x80]
 *   @0x16d02c str r1, [r0, #0x6c]
 *   @0x16d030 str r1, [r0, #0x58]
 *   @0x16d034 str r1, [r0, #0x44]
 *   @0x16d038 str r2, [r0, #0x68]
 *   @0x16d03c str r2, [r0, #0x64]
 *   @0x16d040 str r2, [r0, #0x60]
 *   @0x16d044 str r2, [r0, #0x5c]
 *   @0x16d048 str r2, [r0, #0x54]
 *   @0x16d04c str r2, [r0, #0x50]
 *   @0x16d050 str r2, [r0, #0x4c]
 *   @0x16d054 str r2, [r0, #0x48]
 *   @0x16d058 str r12, [r0]
 *   @0x16d05c str r1, [r0, #0x100]
 *   @0x16d060 str r1, [r0, #0xec]
 *   @0x16d064 str r1, [r0, #0xd8]
 *   @0x16d068 str r1, [r0, #0xc4]
 *   @0x16d06c str r2, [r0, #0xfc]
 *   @0x16d070 str r2, [r0, #0xf8]
 *   @0x16d074 str r2, [r0, #0xf4]
 *   @0x16d078 str r2, [r0, #0xf0]
 *   @0x16d07c str r2, [r0, #0xe8]
 *   @0x16d080 str r2, [r0, #0xe4]
 *   @0x16d084 str r2, [r0, #0xe0]
 *   @0x16d088 str r2, [r0, #0xdc]
 *   @0x16d08c str r2, [r0, #0xd4]
 *   @0x16d090 str r2, [r0, #0xd0]
 *   @0x16d094 str r2, [r0, #0xcc]
 *   @0x16d098 str r2, [r0, #0xc8]
 *   @0x16d09c str r1, [r0, #0x140]
 *   @0x16d0a0 str r1, [r0, #0x12c]
 *   @0x16d0a4 str r1, [r0, #0x118]
 *   @0x16d0a8 str r1, [r0, #0x104]
 *   @0x16d0ac str r2, [r0, #0x13c]
 *   @0x16d0b0 str r2, [r0, #0x138]
 *   @0x16d0b4 str r2, [r0, #0x134]
 *   @0x16d0b8 str r2, [r0, #0x130]
 *   @0x16d0bc str r2, [r0, #0x128]
 *   @0x16d0c0 str r2, [r0, #0x124]
 *   @0x16d0c4 str r2, [r0, #0x120]
 *   @0x16d0c8 str r2, [r0, #0x11c]
 *   @0x16d0cc str r2, [r0, #0x114]
 *   @0x16d0d0 str r2, [r0, #0x110]
 *   @0x16d0d4 str r2, [r0, #0x10c]
 *   @0x16d0d8 str r2, [r0, #0x108]
 *   @0x16d0dc str r2, [r0, #0x184]
 *   @0x16d0e0 str r2, [r0, #0x188]
 *   @0x16d0e4 strb r5, [r0, #0x1b8]
 *   @0x16d0e8 strb r4, [r0, #0x1b9]
 *   @0x16d0ec str r2, [r0, #0x18c]
 *   @0x16d0f0 str r2, [r0, #0x190]
 *   @0x16d0f4 str r2, [r0, #0x194]
 *   @0x16d0f8 str r2, [r0, #0x198]
 *   @0x16d0fc str r2, [r0, #0x19c]
 *   @0x16d100 str r2, [r0, #0x1a0]
 *   @0x16d104 str r2, [r0, #0x1a4]
 *   @0x16d108 str r12, [r0, #0x1a8]
 *   @0x16d10c str r12, [r0, #0x1ac]
 *   @0x16d110 str r12, [r0, #0x1b0]
 *   @0x16d114 str r12, [r0, #0x1b4]
 *   @0x16d118 pop {r4, r5}
 *   @0x16d11c bx lr
 *
 * ══ §28/91 Variable_Scope_GetVar  0x1f3798  size 352  88 条（0x1f3798..0x1f38f8）
 * @func 0x1f3798 0x1f38f8  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GET_RValue(RValue*, RValue*, int) / YYObjectBase::InternalGetYYVar(int) / Call_Accessor_Get(YYObjectBase*, RValue*, RValue*) / Code_Function_Find(char const*, int*) / Code_Function_GET_the_function(int, char const**, void**, int*, int*) / YYSetScriptRef(RValue*)
 * 字段偏移 top8: 0xc×6 / 0x24×2 / 0x154×1 / 0x4×1 / 0x48×1 / 0x-10×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3798 ldr r3, [pc, #0x154]
 *   @0x1f379c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1f37a0 ldr r3, [pc, r3]
 *   @0x1f37a4 mvn r6, #-16777216
 *   @0x1f37a8 sub sp, sp, #40
 *   @0x1f37ac ldr r4, [r3]
 *   @0x1f37b0 mov r5, r2
 *   @0x1f37b4 mov r7, r1
 *   @0x1f37b8 str r6, [r2, #0xc]
 *   @0x1f37bc cmp r4, #0
 *   @0x1f37c0 beq 0x1f38a8 <_Z21Variable_Scope_GetVariiP6RValue+0x110>
 *   @0x1f37c4 sub r9, r0, #99328
 *   @0x1f37c8 sub r9, r9, #672
 *   @0x1f37cc lsl r8, r9, #4
 *   @0x1f37d0 b 0x1f380c <_Z21Variable_Scope_GetVariiP6RValue+0x74>
 *   @0x1f37d4 ldr r3, [r4, #0x4]
 *   @0x1f37d8 cmp r3, #0
 *   @0x1f37dc add r1, r3, r8
 *   @0x1f37e0 beq 0x1f384c <_Z21Variable_Scope_GetVariiP6RValue+0xb4>
 *   @0x1f37e4 mov r0, r5
 *   @0x1f37e8 mov r2, r7
 *   @0x1f37ec bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f37f0 ldr r3, [r5, #0xc]
 *   @0x1f37f4 cmp r3, r6
 *   @0x1f37f8 mov r10, r0
 *   @0x1f37fc bne 0x1f3824 <_Z21Variable_Scope_GetVariiP6RValue+0x8c>
 *   @0x1f3800 ldr r4, [r4, #0xc]
 *   @0x1f3804 cmp r4, #0
 *   @0x1f3808 beq 0x1f3860 <_Z21Variable_Scope_GetVariiP6RValue+0xc8>
 *   @0x1f380c ldr r3, [r4, #0x24]
 *   @0x1f3810 cmp r3, #0
 *   @0x1f3814 bne 0x1f37d4 <_Z21Variable_Scope_GetVariiP6RValue+0x3c>
 *   @0x1f3818 ldr r3, [r5, #0xc]
 *   @0x1f381c cmp r3, r6
 *   @0x1f3820 beq 0x1f3800 <_Z21Variable_Scope_GetVariiP6RValue+0x68>
 *   @0x1f3824 bic r12, r3, #-16777216
 *   @0x1f3828 mov r10, #1
 *   @0x1f382c cmp r12, #6
 *   @0x1f3830 beq 0x1f3870 <_Z21Variable_Scope_GetVariiP6RValue+0xd8>
 *   @0x1f3834 mvn r2, #-16777216
 *   @0x1f3838 cmp r3, r2
 *   @0x1f383c beq 0x1f38a8 <_Z21Variable_Scope_GetVariiP6RValue+0x110>
 *   @0x1f3840 mov r0, r10
 *   @0x1f3844 add sp, sp, #40
 *   @0x1f3848 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f384c mov r1, r9
 *   @0x1f3850 mov r0, r4
 *   @0x1f3854 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3858 mov r1, r0
 *   @0x1f385c b 0x1f37e4 <_Z21Variable_Scope_GetVariiP6RValue+0x4c>
 *   @0x1f3860 ldr r3, [r5, #0xc]
 *   @0x1f3864 bic r12, r3, #-16777216
 *   @0x1f3868 cmp r12, #6
 *   @0x1f386c bne 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c>
 *   @0x1f3870 ldr r1, [r5]
 *   @0x1f3874 cmp r1, #0
 *   @0x1f3878 beq 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c>
 *   @0x1f387c ldr r2, [r1, #0x48]
 *   @0x1f3880 cmp r2, #2
 *   @0x1f3884 bne 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c>
 *   @0x1f3888 add r2, sp, #40
 *   @0x1f388c mov r0, r4
 *   @0x1f3890 str r12, [sp, #0x24]
 *   @0x1f3894 str r1, [r2, #-0x10]!
 *   @0x1f3898 mov r1, r5
 *   @0x1f389c bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_>
 *   @0x1f38a0 ldr r3, [r5, #0xc]
 *   @0x1f38a4 b 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c>
 *   @0x1f38a8 mov r0, #0
 *   @0x1f38ac add r1, sp, #8
 *   @0x1f38b0 bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x1f38b4 cmp r0, #0
 *   @0x1f38b8 beq 0x1f3840 <_Z21Variable_Scope_GetVariiP6RValue+0xa8>
 *   @0x1f38bc add r2, sp, #16
 *   @0x1f38c0 ldr r0, [sp, #0x8]
 *   @0x1f38c4 add r1, sp, #12
 *   @0x1f38c8 add r3, sp, #24
 *   @0x1f38cc str r3, [sp]
 *   @0x1f38d0 add r3, sp, #20
 *   @0x1f38d4 bl 0xcdf0c <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_>
 *   @0x1f38d8 mov r0, r5
 *   @0x1f38dc bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue>
 *   @0x1f38e0 ldr r3, [r5]
 *   @0x1f38e4 ldr r2, [sp, #0x10]
 *   @0x1f38e8 mov r10, #1
 *   @0x1f38ec str r2, [r3, #0x68]
 *   @0x1f38f0 b 0x1f3840 <_Z21Variable_Scope_GetVariiP6RValue+0xa8>
 *   @0x1f38f4 andseq r10, pc, r8, lsl #10
 *
 * ══ §29/91 ov_read  0x232ec8  size 352  88 条（0x232ec8..0x233028）
 * @func 0x232ec8 0x233028  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_read+0x144×2 / ov_read+0x158 / anon_22fd0c+0xe5c / vorbis_synthesis_pcmout / ov_info / __divsi3 / ov_read+0x110 / ov_read+0x104
 * 字段偏移 top8: 0x4×7 / 0x58×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232ec8 ldr r12, [r0, #0x58]
 *   @0x232ecc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x232ed0 cmp r12, #1
 *   @0x232ed4 sub sp, sp, #20
 *   @0x232ed8 mov r4, r0
 *   @0x232edc mov r5, r1
 *   @0x232ee0 mov r9, r2
 *   @0x232ee4 mov r6, r3
 *   @0x232ee8 ble 0x233020 <ov_read+0x158>
 *   @0x232eec add r7, r0, #480
 *   @0x232ef0 add r10, sp, #12
 *   @0x232ef4 b 0x232f14 <ov_read+0x4c>
 *   @0x232ef8 mov r0, r4
 *   @0x232efc bl 0x230b68 <vorbis_packet_blocksize+0xeec>
 *   @0x232f00 cmn r0, #2
 *   @0x232f04 beq 0x233014 <ov_read+0x14c>
 *   @0x232f08 cmp r0, #0
 *   @0x232f0c ble 0x23300c <ov_read+0x144>
 *   @0x232f10 ldr r12, [r4, #0x58]
 *   @0x232f14 cmp r12, #4
 *   @0x232f18 bne 0x232ef8 <ov_read+0x30>
 *   @0x232f1c mov r0, r7
 *   @0x232f20 mov r1, r10
 *   @0x232f24 bl 0x227c80 <vorbis_synthesis_pcmout>
 *   @0x232f28 cmp r0, #0
 *   @0x232f2c beq 0x232ef8 <ov_read+0x30>
 *   @0x232f30 mov r8, r0
 *   @0x232f34 movle r0, r0
 *   @0x232f38 ble 0x23300c <ov_read+0x144>
 *   @0x232f3c mvn r1, #0
 *   @0x232f40 mov r0, r4
 *   @0x232f44 bl 0x232e28 <ov_info>
 *   @0x232f48 ldr r0, [r0, #0x4]
 *   @0x232f4c str r0, [sp, #0x4]
 *   @0x232f50 mov r0, r9
 *   @0x232f54 ldr r3, [sp, #0x4]
 *   @0x232f58 lsl r9, r3, #1
 *   @0x232f5c mov r1, r9
 *   @0x232f60 bl 0x318d10 <__divsi3>
 *   @0x232f64 ldr r3, [sp, #0x4]
 *   @0x232f68 cmp r8, r0
 *   @0x232f6c movge r8, r0
 *   @0x232f70 cmp r3, #0
 *   @0x232f74 ble 0x232fd8 <ov_read+0x110>
 *   @0x232f78 ldr r1, [sp, #0xc]
 *   @0x232f7c lsl r11, r8, #2
 *   @0x232f80 add r10, r5, r9
 *   @0x232f84 mov r0, r5
 *   @0x232f88 sub r1, r1, #4
 *   @0x232f8c cmp r8, #0
 *   @0x232f90 ldr r3, [r1, #0x4]!
 *   @0x232f94 mov lr, r0
 *   @0x232f98 addgt r5, r3, r11
 *   @0x232f9c ble 0x232fcc <ov_read+0x104>
 *   @0x232fa0 ldr r12, [r3], #4
 *   @0x232fa4 mov r2, #32768
 *   @0x232fa8 asr r12, r12, #9
 *   @0x232fac cmp r12, r2
 *   @0x232fb0 movwge r2, #0x7fff
 *   @0x232fb4 bge 0x232fc0 <ov_read+0xf8>
 *   @0x232fb8 cmn r12, #32768
 *   @0x232fbc uxthge r2, r12
 *   @0x232fc0 cmp r3, r5
 *   @0x232fc4 strh r2, [lr], r9
 *   @0x232fc8 bne 0x232fa0 <ov_read+0xd8>
 *   @0x232fcc add r0, r0, #2
 *   @0x232fd0 cmp r0, r10
 *   @0x232fd4 bne 0x232f8c <ov_read+0xc4>
 *   @0x232fd8 mov r0, r7
 *   @0x232fdc mov r1, r8
 *   @0x232fe0 bl 0x227cfc <vorbis_synthesis_read>
 *   @0x232fe4 ldrd r2, r3, [r4, #80]
 *   @0x232fe8 adds r2, r2, r8
 *   @0x232fec adc r3, r3, r8, asr #31
 *   @0x232ff0 cmp r6, #0
 *   @0x232ff4 strd r2, r3, [r4, #80]
 *   @0x232ff8 ldrne r3, [r4, #0x60]
 *   @0x232ffc strne r3, [r6]
 *   @0x233000 ldr r3, [sp, #0x4]
 *   @0x233004 lsl r0, r8, #1
 *   @0x233008 mul r0, r3, r0
 *   @0x23300c add sp, sp, #20
 *   @0x233010 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x233014 mov r0, #0
 *   @0x233018 add sp, sp, #20
 *   @0x23301c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x233020 mvn r0, #130
 *   @0x233024 b 0x23300c <ov_read+0x144>
 *
 * ══ §30/91 ARRAY_LVAL_RValue  0xd0d38  size 348  87 条（0xd0d38..0xd0e94）
 * @func 0xd0d38 0xd0e94  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb664c / ARRAY_RefAlloc(void*) / ARRAY_LVAL_RValue(YYRValue*, int)+0xac / ARRAY_LVAL_RValue(YYRValue*, int)+0xd4 / ARRAY_LVAL_RValue(YYRValue*, int)+0xe0 / ARRAY_LVAL_RValue(YYRValue*, int)+0x130 / CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*)
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x8×2 / 0x10×2 / 0x9c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd0d38 push {r4, r5, r6, r7, lr}
 *   @0xd0d3c sub sp, sp, #12
 *   @0xd0d40 mov r4, r0
 *   @0xd0d44 mov r2, #32000
 *   @0xd0d48 mov r0, sp
 *   @0xd0d4c bl 0xb664c <ldiv@plt>
 *   @0xd0d50 ldr r3, [r4, #0xc]
 *   @0xd0d54 ldr r5, [r4]
 *   @0xd0d58 bic r2, r3, #-16777216
 *   @0xd0d5c ldr r6, [sp]
 *   @0xd0d60 cmp r2, #2
 *   @0xd0d64 ldr r7, [sp, #0x4]
 *   @0xd0d68 beq 0xd0e24 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xec>
 *   @0xd0d6c sub r3, r3, #1
 *   @0xd0d70 bic r3, r3, #-16777216
 *   @0xd0d74 bic r3, r3, #3
 *   @0xd0d78 cmp r3, #0
 *   @0xd0d7c beq 0xd0e5c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x124>
 *   @0xd0d80 mov r3, #0
 *   @0xd0d84 mov r2, #2
 *   @0xd0d88 str r3, [r4, #0x8]
 *   @0xd0d8c mov r0, r4
 *   @0xd0d90 str r3, [r4]
 *   @0xd0d94 str r2, [r4, #0xc]
 *   @0xd0d98 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0xd0d9c mov r5, r0
 *   @0xd0da0 str r0, [r4]
 *   @0xd0da4 ldr r3, [r5, #0x10]
 *   @0xd0da8 cmp r3, r6
 *   @0xd0dac ble 0xd0de4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xac>
 *   @0xd0db0 cmp r6, #0
 *   @0xd0db4 blt 0xd0e0c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xd4>
 *   @0xd0db8 cmp r7, #0
 *   @0xd0dbc ldr r3, [r5, #0x4]
 *   @0xd0dc0 addge r6, r3, r6, lsl #3
 *   @0xd0dc4 blt 0xd0e18 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0xe0>
 *   @0xd0dc8 ldr r3, [r6]
 *   @0xd0dcc cmp r3, r7
 *   @0xd0dd0 ble 0xd0e68 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x130>
 *   @0xd0dd4 ldr r0, [r6, #0x4]
 *   @0xd0dd8 add r0, r0, r7, lsl #4
 *   @0xd0ddc add sp, sp, #12
 *   @0xd0de0 pop {r4, r5, r6, r7, pc}
 *   @0xd0de4 add r1, r6, #1
 *   @0xd0de8 ldr r2, [pc, #0x9c]
 *   @0xd0dec str r1, [r5, #0x10]
 *   @0xd0df0 add r0, r5, #4
 *   @0xd0df4 mov r3, #876
 *   @0xd0df8 lsl r1, r1, #3
 *   @0xd0dfc add r2, pc, r2
 *   @0xd0e00 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xd0e04 cmp r6, #0
 *   @0xd0e08 bge 0xd0db8 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x80>
 *   @0xd0e0c cmp r7, #0
 *   @0xd0e10 movge r6, #0
 *   @0xd0e14 bge 0xd0dc8 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x90>
 *   @0xd0e18 mov r0, #0
 *   @0xd0e1c add sp, sp, #12
 *   @0xd0e20 pop {r4, r5, r6, r7, pc}
 *   @0xd0e24 cmp r5, #0
 *   @0xd0e28 beq 0xd0d6c <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x34>
 *   @0xd0e2c ldr r3, [r5, #0x8]
 *   @0xd0e30 cmp r3, r4
 *   @0xd0e34 beq 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c>
 *   @0xd0e38 ldr r3, [r5]
 *   @0xd0e3c cmp r3, #1
 *   @0xd0e40 beq 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c>
 *   @0xd0e44 mov r0, r5
 *   @0xd0e48 mov r1, r4
 *   @0xd0e4c bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv>
 *   @0xd0e50 mov r5, r0
 *   @0xd0e54 str r0, [r4]
 *   @0xd0e58 b 0xd0da4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x6c>
 *   @0xd0e5c mov r0, r4
 *   @0xd0e60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd0e64 b 0xd0d80 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x48>
 *   @0xd0e68 add r1, r7, #1
 *   @0xd0e6c ldr r2, [pc, #0x1c]
 *   @0xd0e70 mov r0, r6
 *   @0xd0e74 movw r3, #0x379
 *   @0xd0e78 str r1, [r0], #4
 *   @0xd0e7c add r2, pc, r2
 *   @0xd0e80 lsl r1, r1, #4
 *   @0xd0e84 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xd0e88 b 0xd0dd4 <_Z17ARRAY_LVAL_RValueP8YYRValuei+0x9c>
 *   @0xd0e8c eoreq r1, r6, r0, lsl #8
 *   @0xd0e90 eoreq r1, r6, r0, lsl #7
 *
 * ══ §31/91 ParticleSystem_Clear  0x1a4180  size 348  87 条（0x1a4180..0x1a42dc）
 * @func 0x1a4180 0x1a42dc  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / ParticleSystem_Exists(int) / ParticleSystem_Clear(int)+0x70 / ParticleSystem_Clear(int)+0x3c / ParticleSystem_Clear(int)+0xc4 / operator delete(void*) / ParticleSystem_Clear(int)+0xa0 / CLayerManager::RemoveElement(CRoom*, int, bool, bool)
 * 字段偏移 top8: 0x4×11 / 0x2×9 / 0xc×3 / 0x10×3 / 0x34×2 / 0x2c×2 / 0x134×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4180 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a4184 mov r7, r0
 *   @0x1a4188 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a418c cmp r0, #0
 *   @0x1a4190 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a4194 ldr r5, [pc, #0x134]
 *   @0x1a4198 lsl r6, r7, #2
 *   @0x1a419c ldr r5, [pc, r5]
 *   @0x1a41a0 ldr r3, [r5, #0x4]
 *   @0x1a41a4 ldr r3, [r3, r7, lsl #2]
 *   @0x1a41a8 ldr r2, [r3]
 *   @0x1a41ac cmp r2, #0
 *   @0x1a41b0 ble 0x1a41f0 <_Z20ParticleSystem_Cleari+0x70>
 *   @0x1a41b4 mov r4, #0
 *   @0x1a41b8 mov r8, r4
 *   @0x1a41bc ldr r3, [r3, #0x4]
 *   @0x1a41c0 ldr r0, [r3, r4, lsl #2]
 *   @0x1a41c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a41c8 ldr r3, [r5, #0x4]
 *   @0x1a41cc ldr r3, [r3, r6]
 *   @0x1a41d0 ldr r3, [r3, #0x4]
 *   @0x1a41d4 str r8, [r3, r4, lsl #2]
 *   @0x1a41d8 add r4, r4, #1
 *   @0x1a41dc ldr r3, [r5, #0x4]
 *   @0x1a41e0 ldr r3, [r3, r6]
 *   @0x1a41e4 ldr r2, [r3]
 *   @0x1a41e8 cmp r4, r2
 *   @0x1a41ec blt 0x1a41bc <_Z20ParticleSystem_Cleari+0x3c>
 *   @0x1a41f0 ldr r0, [r3, #0x4]
 *   @0x1a41f4 mov r4, #0
 *   @0x1a41f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a41fc ldr r3, [r5, #0x4]
 *   @0x1a4200 ldr r2, [r3, r7, lsl #2]
 *   @0x1a4204 str r4, [r2, #0x4]
 *   @0x1a4208 ldr r3, [r3, r7, lsl #2]
 *   @0x1a420c ldr r2, [r3, #0xc]
 *   @0x1a4210 str r4, [r3]
 *   @0x1a4214 cmp r2, r4
 *   @0x1a4218 str r4, [r3, #0x8]
 *   @0x1a421c ble 0x1a4244 <_Z20ParticleSystem_Cleari+0xc4>
 *   @0x1a4220 ldr r3, [r3, #0x10]
 *   @0x1a4224 ldr r0, [r3, r4, lsl #2]
 *   @0x1a4228 add r4, r4, #1
 *   @0x1a422c bl 0x27d1d0 <_ZdlPv>
 *   @0x1a4230 ldr r3, [r5, #0x4]
 *   @0x1a4234 ldr r3, [r3, r6]
 *   @0x1a4238 ldr r2, [r3, #0xc]
 *   @0x1a423c cmp r4, r2
 *   @0x1a4240 blt 0x1a4220 <_Z20ParticleSystem_Cleari+0xa0>
 *   @0x1a4244 ldr r0, [r3, #0x10]
 *   @0x1a4248 mov r4, #0
 *   @0x1a424c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a4250 ldr r1, [r5, #0x4]
 *   @0x1a4254 ldr r3, [pc, #0x78]
 *   @0x1a4258 mov r2, #1
 *   @0x1a425c mov r0, #0
 *   @0x1a4260 ldr r12, [r1, r7, lsl #2]
 *   @0x1a4264 ldr r3, [pc, r3]
 *   @0x1a4268 ldrb r3, [r3]
 *   @0x1a426c str r4, [r12, #0x10]
 *   @0x1a4270 ldr r1, [r1, r7, lsl #2]
 *   @0x1a4274 cmp r3, r4
 *   @0x1a4278 str r0, [r1, #0x1c]
 *   @0x1a427c str r0, [r1, #0x20]
 *   @0x1a4280 str r0, [r1, #0x24]
 *   @0x1a4284 str r4, [r1, #0xc]
 *   @0x1a4288 str r4, [r1, #0x14]
 *   @0x1a428c strb r2, [r1, #0x18]
 *   @0x1a4290 strb r2, [r1, #0x28]
 *   @0x1a4294 strb r2, [r1, #0x29]
 *   @0x1a4298 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a429c ldr r0, [pc, #0x34]
 *   @0x1a42a0 mov r3, r4
 *   @0x1a42a4 ldr r1, [r1, #0x2c]
 *   @0x1a42a8 ldr r0, [pc, r0]
 *   @0x1a42ac ldr r0, [r0]
 *   @0x1a42b0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a42b4 ldr r3, [r5, #0x4]
 *   @0x1a42b8 mvn r2, #0
 *   @0x1a42bc ldr r3, [r3, r7, lsl #2]
 *   @0x1a42c0 strb r4, [r3, #0x34]
 *   @0x1a42c4 str r2, [r3, #0x2c]
 *   @0x1a42c8 str r2, [r3, #0x30]
 *   @0x1a42cc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a42d0 eoreq r12, r4, r12, lsl r6
 *   @0x1a42d4 eoreq r9, r4, r0, asr #13
 *   @0x1a42d8 eoreq r9, r4, r0, lsl #13
 *
 * ══ §32/91 MemoryManager::Free  0x27c2d0  size 348  87 条（0x27c2d0..0x27c42c）
 * @func 0x27c2d0 0x27c42c  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27c2e4→0x756780, 0x27c368→0x756754, 0x27c370→0x756758, 0x27c37c→0x75674c, 0x27c380→0x756748
 * 调用序列: 0xb655c×2 / Mutex::Lock() / logLocation(ELogType, void const*, void const*, unsigned int) / bucketFree(void const*) / MemoryManager::Free(void const*)+0xf8 / anon_27b918
 * 字段偏移 top8: 0xa0×2 / 0x134×1 / 0x12c×1 / 0x-c×1 / 0x-4×1 / 0x-8×1 / 0xac×1 / 0xa8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c2d0 push {r4, r5, r6, lr}
 *   @0x27c2d4 subs r4, r0, #0
 *   @0x27c2d8 ldr r5, [pc, #0x134]
 *   @0x27c2dc add r5, pc, r5
 *   @0x27c2e0 popeq {r4, r5, r6, pc}
 *   @0x27c2e4 ldr r3, [pc, #0x12c]
 *   @0x27c2e8 ldr r6, [r5, r3]
 *   @0x27c2ec ldr r0, [r6]
 *   @0x27c2f0 cmp r0, #0
 *   @0x27c2f4 beq 0x27c408 <_ZN13MemoryManager4FreeEPKv+0x138>
 *   @0x27c2f8 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27c2fc mov r2, #0
 *   @0x27c300 mov r3, r2
 *   @0x27c304 mov r0, #2
 *   @0x27c308 mov r1, r4
 *   @0x27c30c bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j>
 *   @0x27c310 mov r0, r4
 *   @0x27c314 bl 0x27c20c <_Z10bucketFreePKv>
 *   @0x27c318 cmp r0, #0
 *   @0x27c31c bne 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78>
 *   @0x27c320 ldr r2, [r4, #-0xc]
 *   @0x27c324 movw r3, #0xc0de
 *   @0x27c328 movt r3, #0xdead
 *   @0x27c32c cmp r2, r3
 *   @0x27c330 beq 0x27c354 <_ZN13MemoryManager4FreeEPKv+0x84>
 *   @0x27c334 ldr r3, [r4, #-0x4]
 *   @0x27c338 cmp r3, #0
 *   @0x27c33c blt 0x27c3c8 <_ZN13MemoryManager4FreeEPKv+0xf8>
 *   @0x27c340 mov r0, r4
 *   @0x27c344 bl 0xb655c <free@plt>
 *   @0x27c348 ldr r0, [r6]
 *   @0x27c34c pop {r4, r5, r6, lr}
 *   @0x27c350 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27c354 ldr r2, [r4, #-0x8]
 *   @0x27c358 movw r3, #0xb00b
 *   @0x27c35c movt r3, #0xbaad
 *   @0x27c360 cmp r2, r3
 *   @0x27c364 bne 0x27c334 <_ZN13MemoryManager4FreeEPKv+0x64>
 *   @0x27c368 ldr r2, [pc, #0xac]
 *   @0x27c36c mov r0, r4
 *   @0x27c370 ldr lr, [pc, #0xa8]
 *   @0x27c374 ldr r3, [r0, #-0x10]!
 *   @0x27c378 ldr r2, [r5, r2]
 *   @0x27c37c ldr r12, [pc, #0xa0]
 *   @0x27c380 ldr r1, [pc, #0xa0]
 *   @0x27c384 ldr r4, [r2]
 *   @0x27c388 rsb r4, r3, r4
 *   @0x27c38c str r4, [r2]
 *   @0x27c390 ldr r2, [r5, lr]
 *   @0x27c394 ldr lr, [r2]
 *   @0x27c398 rsb lr, r3, lr
 *   @0x27c39c str lr, [r2]
 *   @0x27c3a0 ldr r2, [r5, r12]
 *   @0x27c3a4 ldr r12, [r2]
 *   @0x27c3a8 sub r12, r12, #1
 *   @0x27c3ac str r12, [r2]
 *   @0x27c3b0 ldr r2, [r5, r1]
 *   @0x27c3b4 ldr r1, [r2]
 *   @0x27c3b8 rsb r3, r3, r1
 *   @0x27c3bc str r3, [r2]
 *   @0x27c3c0 bl 0xb655c <free@plt>
 *   @0x27c3c4 b 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78>
 *   @0x27c3c8 bic r3, r3, #-2147483648
 *   @0x27c3cc cmp r3, #8192
 *   @0x27c3d0 bhs 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70>
 *   @0x27c3d4 sub r1, r4, #16
 *   @0x27c3d8 movw r2, #0xc0de
 *   @0x27c3dc rsb r3, r3, r1
 *   @0x27c3e0 movt r2, #0xdead
 *   @0x27c3e4 ldr r1, [r3, #0x4]
 *   @0x27c3e8 cmp r1, r2
 *   @0x27c3ec bne 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70>
 *   @0x27c3f0 ldr r2, [r3, #0x8]
 *   @0x27c3f4 movw r3, #0xb00b
 *   @0x27c3f8 movt r3, #0xbaad
 *   @0x27c3fc cmp r2, r3
 *   @0x27c400 bne 0x27c340 <_ZN13MemoryManager4FreeEPKv+0x70>
 *   @0x27c404 b 0x27c348 <_ZN13MemoryManager4FreeEPKv+0x78>
 *   @0x27c408 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27c40c ldr r0, [r6]
 *   @0x27c410 b 0x27c2f8 <_ZN13MemoryManager4FreeEPKv+0x28>
 *   @0x27c414 andseq r5, r7, r4, ror r9
 *   @0x27c418 .word 0xfffffbcc
 *   @0x27c41c .word 0xffffe794
 *   @0x27c420 .word 0xffffe788
 *   @0x27c424 .word 0xfffffc04
 *   @0x27c428 .word 0xffffe790
 *
 * ══ §33/91 debug_display_buffer  0x2967e8  size 348  87 条（0x2967e8..0x296944）
 * @func 0x2967e8 0x296944  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: debug_display_buffer(tagIConsole&, unsigned char*, int)+0xac
 * 字段偏移 top8: 0xc×7 / 0x4×2 / 0x8×2 / 0x1×2 / 0x120×1 / 0x11c×1 / 0x118×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2967e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2967ec add r6, r1, r2
 *   @0x2967f0 cmp r1, r6
 *   @0x2967f4 sub sp, sp, #20
 *   @0x2967f8 mov r9, r1
 *   @0x2967fc mov r11, r0
 *   @0x296800 bhs 0x296924 <_Z20debug_display_bufferR11tagIConsolePhi+0x13c>
 *   @0x296804 ldr r3, [pc, #0x120]
 *   @0x296808 add r10, r1, #16
 *   @0x29680c ldr r7, [pc, #0x11c]
 *   @0x296810 add r3, pc, r3
 *   @0x296814 ldr r8, [pc, #0x118]
 *   @0x296818 str r3, [sp, #0x4]
 *   @0x29681c add r7, pc, r7
 *   @0x296820 ldr r3, [pc, #0x110]
 *   @0x296824 add r8, pc, r8
 *   @0x296828 mov r5, r10
 *   @0x29682c str r1, [sp]
 *   @0x296830 add r3, pc, r3
 *   @0x296834 str r3, [sp, #0x8]
 *   @0x296838 ldr r3, [pc, #0xfc]
 *   @0x29683c add r3, pc, r3
 *   @0x296840 str r3, [sp, #0xc]
 *   @0x296844 ldr r12, [r11]
 *   @0x296848 mov r0, r11
 *   @0x29684c ldr r3, [sp]
 *   @0x296850 mov r4, r9
 *   @0x296854 ldr r1, [sp, #0x4]
 *   @0x296858 rsb r2, r3, r9
 *   @0x29685c ldr r12, [r12, #0xc]
 *   @0x296860 blx r12
 *   @0x296864 cmp r6, r4
 *   @0x296868 mov r3, r4
 *   @0x29686c mov r0, r11
 *   @0x296870 mov r1, r7
 *   @0x296874 add r4, r4, #1
 *   @0x296878 bls 0x296894 <_Z20debug_display_bufferR11tagIConsolePhi+0xac>
 *   @0x29687c ldr r12, [r11]
 *   @0x296880 ldrb r2, [r3]
 *   @0x296884 ldr r3, [r12, #0xc]
 *   @0x296888 blx r3
 *   @0x29688c cmp r4, r5
 *   @0x296890 bne 0x296864 <_Z20debug_display_bufferR11tagIConsolePhi+0x7c>
 *   @0x296894 ldr r2, [r11]
 *   @0x296898 mov r0, r11
 *   @0x29689c ldr r1, [sp, #0x8]
 *   @0x2968a0 ldr r2, [r2, #0xc]
 *   @0x2968a4 blx r2
 *   @0x2968a8 cmp r9, r6
 *   @0x2968ac ldr r3, [pc, #0x8c]
 *   @0x2968b0 bhs 0x2968fc <_Z20debug_display_bufferR11tagIConsolePhi+0x114>
 *   @0x2968b4 ldr r3, [pc, r3]
 *   @0x2968b8 ldrb r12, [r9], #1
 *   @0x2968bc ldr r0, [r11]
 *   @0x2968c0 ldr r1, [r3]
 *   @0x2968c4 mov r2, r12
 *   @0x2968c8 add r1, r1, r12
 *   @0x2968cc ldr r3, [r0, #0xc]
 *   @0x2968d0 ldrb r1, [r1, #0x1]
 *   @0x2968d4 tst r1, #7
 *   @0x2968d8 bne 0x2968e8 <_Z20debug_display_bufferR11tagIConsolePhi+0x100>
 *   @0x2968dc tst r1, #4
 *   @0x2968e0 movne r2, r12
 *   @0x2968e4 moveq r2, #46
 *   @0x2968e8 mov r0, r11
 *   @0x2968ec mov r1, r8
 *   @0x2968f0 blx r3
 *   @0x2968f4 cmp r9, r5
 *   @0x2968f8 bne 0x2968a8 <_Z20debug_display_bufferR11tagIConsolePhi+0xc0>
 *   @0x2968fc ldr r2, [r11]
 *   @0x296900 mov r0, r11
 *   @0x296904 ldr r1, [sp, #0xc]
 *   @0x296908 add r5, r5, #16
 *   @0x29690c mov r9, r10
 *   @0x296910 ldr r2, [r2, #0xc]
 *   @0x296914 blx r2
 *   @0x296918 cmp r6, r10
 *   @0x29691c addhi r10, r10, #16
 *   @0x296920 bhi 0x296844 <_Z20debug_display_bufferR11tagIConsolePhi+0x5c>
 *   @0x296924 add sp, sp, #20
 *   @0x296928 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29692c andeq r2, r12, r0, ror #25
 *   @0x296930 andeq r2, r12, r0, ror #25
 *   @0x296934 andeq r2, r12, r0, ror #25
 *   @0x296938 andeq r0, r12, r12, lsr #21
 *   @0x29693c andeq r12, r9, r12, asr r4
 *   @0x296940 andseq r7, r5, r12, asr #1
 *
 * ══ §34/91 b2DynamicTree::RemoveLeaf  0x2df4e8  size 344  86 条（0x2df4e8..0x2df640）
 * @func 0x2df4e8 0x2df640  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::FreeNode(int) / b2DynamicTree::Balance(int)
 * 字段偏移 top8: 0x14×5 / 0x18×3 / 0x20×3 / 0x4×2 / 0x1c×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df4e8 ldr r3, [r0]
 *   @0x2df4ec push {r4, r5, r6, lr}
 *   @0x2df4f0 cmp r3, r1
 *   @0x2df4f4 mov r6, r0
 *   @0x2df4f8 mvneq r3, #0
 *   @0x2df4fc streq r3, [r0]
 *   @0x2df500 popeq {r4, r5, r6, pc}
 *   @0x2df504 ldr r2, [r0, #0x4]
 *   @0x2df508 add r3, r1, r1, lsl #3
 *   @0x2df50c add r3, r2, r3, lsl #2
 *   @0x2df510 ldr r12, [r3, #0x14]
 *   @0x2df514 add r0, r12, r12, lsl #3
 *   @0x2df518 add r0, r2, r0, lsl #2
 *   @0x2df51c ldr r3, [r0, #0x18]
 *   @0x2df520 ldr r5, [r0, #0x14]
 *   @0x2df524 cmp r3, r1
 *   @0x2df528 ldreq r3, [r0, #0x1c]
 *   @0x2df52c cmn r5, #1
 *   @0x2df530 beq 0x2df620 <_ZN13b2DynamicTree10RemoveLeafEi+0x138>
 *   @0x2df534 add r1, r5, r5, lsl #3
 *   @0x2df538 add r1, r2, r1, lsl #2
 *   @0x2df53c ldr r0, [r1, #0x18]
 *   @0x2df540 cmp r0, r12
 *   @0x2df544 streq r3, [r1, #0x18]
 *   @0x2df548 strne r3, [r1, #0x1c]
 *   @0x2df54c add r3, r3, r3, lsl #3
 *   @0x2df550 mov r1, r12
 *   @0x2df554 mov r0, r6
 *   @0x2df558 add r2, r2, r3, lsl #2
 *   @0x2df55c str r5, [r2, #0x14]
 *   @0x2df560 bl 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi>
 *   @0x2df564 mov r1, r5
 *   @0x2df568 mov r0, r6
 *   @0x2df56c bl 0x2deae4 <_ZN13b2DynamicTree7BalanceEi>
 *   @0x2df570 ldr r4, [r6, #0x4]
 *   @0x2df574 add r0, r0, r0, lsl #3
 *   @0x2df578 add r3, r4, r0, lsl #2
 *   @0x2df57c ldr r12, [r3, #0x18]
 *   @0x2df580 ldr r2, [r3, #0x1c]
 *   @0x2df584 ldr r5, [r3, #0x14]
 *   @0x2df588 add r12, r12, r12, lsl #3
 *   @0x2df58c add r2, r2, r2, lsl #3
 *   @0x2df590 add r12, r4, r12, lsl #2
 *   @0x2df594 vldr s12, [r12]
 *   @0x2df598 add r2, r4, r2, lsl #2
 *   @0x2df59c vldr s13, [r2]
 *   @0x2df5a0 vcmpe.f32 s12, s13
 *   @0x2df5a4 vldr s14, [r12, #4]
 *   @0x2df5a8 vldr s15, [r2, #4]
 *   @0x2df5ac ldr r1, [r12, #0x20]
 *   @0x2df5b0 ldr r0, [r2, #0x20]
 *   @0x2df5b4 vmrs APSR_nzcv, fpscr
 *   @0x2df5b8 vcmpe.f32 s14, s15
 *   @0x2df5bc vmovmi.f32 s13, s12
 *   @0x2df5c0 vmrs APSR_nzcv, fpscr
 *   @0x2df5c4 vstr s13, [r3]
 *   @0x2df5c8 vmovmi.f32 s15, s14
 *   @0x2df5cc vstr s15, [r3, #4]
 *   @0x2df5d0 vldr s13, [r2, #8]
 *   @0x2df5d4 vldr s12, [r12, #8]
 *   @0x2df5d8 vldr s15, [r2, #12]
 *   @0x2df5dc vldr s14, [r12, #12]
 *   @0x2df5e0 vcmpe.f32 s12, s13
 *   @0x2df5e4 vmrs APSR_nzcv, fpscr
 *   @0x2df5e8 vcmpe.f32 s14, s15
 *   @0x2df5ec vmovgt.f32 s13, s12
 *   @0x2df5f0 vmrs APSR_nzcv, fpscr
 *   @0x2df5f4 vstr s13, [r3, #8]
 *   @0x2df5f8 vmovgt.f32 s15, s14
 *   @0x2df5fc cmp r0, r1
 *   @0x2df600 movge r2, r0
 *   @0x2df604 movlt r2, r1
 *   @0x2df608 cmn r5, #1
 *   @0x2df60c add r2, r2, #1
 *   @0x2df610 vstr s15, [r3, #12]
 *   @0x2df614 str r2, [r3, #0x20]
 *   @0x2df618 bne 0x2df564 <_ZN13b2DynamicTree10RemoveLeafEi+0x7c>
 *   @0x2df61c pop {r4, r5, r6, pc}
 *   @0x2df620 add r4, r3, r3, lsl #3
 *   @0x2df624 str r3, [r6]
 *   @0x2df628 mov r0, r6
 *   @0x2df62c mov r1, r12
 *   @0x2df630 add r2, r2, r4, lsl #2
 *   @0x2df634 str r5, [r2, #0x14]
 *   @0x2df638 pop {r4, r5, r6, lr}
 *   @0x2df63c b 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi>
 *
 * ══ §35/91 mult_D2A  0x23d498  size 340  85 条（0x23d498..0x23d5ec）
 * @func 0x23d498 0x23d5ec  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Balloc_D2A / mult_D2A+0x140
 * 字段偏移 top8: 0x4×11 / 0x10×3 / 0x8×3 / 0x-4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d498 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23d49c mov r4, r0
 *   @0x23d4a0 ldr r7, [r0, #0x10]
 *   @0x23d4a4 sub sp, sp, #20
 *   @0x23d4a8 ldr r5, [r1, #0x10]
 *   @0x23d4ac mov r8, r1
 *   @0x23d4b0 cmp r7, r5
 *   @0x23d4b4 bge 0x23d4cc <mult_D2A+0x34>
 *   @0x23d4b8 mov r2, r7
 *   @0x23d4bc mov r4, r1
 *   @0x23d4c0 mov r7, r5
 *   @0x23d4c4 mov r8, r0
 *   @0x23d4c8 mov r5, r2
 *   @0x23d4cc ldr r3, [r4, #0x8]
 *   @0x23d4d0 add r2, r7, r5
 *   @0x23d4d4 ldr r0, [r4, #0x4]
 *   @0x23d4d8 cmp r2, r3
 *   @0x23d4dc str r2, [sp, #0x4]
 *   @0x23d4e0 addgt r0, r0, #1
 *   @0x23d4e4 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d4e8 ldr r3, [sp, #0x4]
 *   @0x23d4ec add r9, r0, #20
 *   @0x23d4f0 str r0, [sp]
 *   @0x23d4f4 add r10, r9, r3, lsl #2
 *   @0x23d4f8 cmp r9, r10
 *   @0x23d4fc movlo r3, r9
 *   @0x23d500 movlo r2, #0
 *   @0x23d504 bhs 0x23d514 <mult_D2A+0x7c>
 *   @0x23d508 str r2, [r3], #4
 *   @0x23d50c cmp r10, r3
 *   @0x23d510 bhi 0x23d508 <mult_D2A+0x70>
 *   @0x23d514 add r8, r8, #20
 *   @0x23d518 add r4, r4, #20
 *   @0x23d51c add r5, r8, r5, lsl #2
 *   @0x23d520 str r4, [sp, #0x8]
 *   @0x23d524 cmp r8, r5
 *   @0x23d528 add r7, r4, r7, lsl #2
 *   @0x23d52c strlo r10, [sp, #0xc]
 *   @0x23d530 movlo r10, r5
 *   @0x23d534 bhs 0x23d5a0 <mult_D2A+0x108>
 *   @0x23d538 ldr r6, [r8], #4
 *   @0x23d53c cmp r6, #0
 *   @0x23d540 beq 0x23d590 <mult_D2A+0xf8>
 *   @0x23d544 mov r0, #0
 *   @0x23d548 mov r1, #0
 *   @0x23d54c mov r4, r9
 *   @0x23d550 ldr r5, [sp, #0x8]
 *   @0x23d554 b 0x23d55c <mult_D2A+0xc4>
 *   @0x23d558 mov r4, r12
 *   @0x23d55c ldr r11, [r5], #4
 *   @0x23d560 mov r3, #0
 *   @0x23d564 ldr r2, [r4]
 *   @0x23d568 mov r12, r4
 *   @0x23d56c umlal r2, r3, r11, r6
 *   @0x23d570 adds r2, r2, r0
 *   @0x23d574 str r2, [r12], #4
 *   @0x23d578 adc r3, r3, r1
 *   @0x23d57c cmp r7, r5
 *   @0x23d580 mov r1, #0
 *   @0x23d584 mov r0, r3
 *   @0x23d588 bhi 0x23d558 <mult_D2A+0xc0>
 *   @0x23d58c str r3, [r4, #0x4]
 *   @0x23d590 cmp r10, r8
 *   @0x23d594 add r9, r9, #4
 *   @0x23d598 bhi 0x23d538 <mult_D2A+0xa0>
 *   @0x23d59c ldr r10, [sp, #0xc]
 *   @0x23d5a0 ldr r2, [sp, #0x4]
 *   @0x23d5a4 cmp r2, #0
 *   @0x23d5a8 ble 0x23d5d8 <mult_D2A+0x140>
 *   @0x23d5ac ldr r3, [r10, #-0x4]
 *   @0x23d5b0 cmp r3, #0
 *   @0x23d5b4 bne 0x23d5d8 <mult_D2A+0x140>
 *   @0x23d5b8 ldr r3, [sp, #0x4]
 *   @0x23d5bc sub r10, r10, #4
 *   @0x23d5c0 subs r3, r3, #1
 *   @0x23d5c4 beq 0x23d5d4 <mult_D2A+0x13c>
 *   @0x23d5c8 ldr r2, [r10, #-0x4]!
 *   @0x23d5cc cmp r2, #0
 *   @0x23d5d0 beq 0x23d5c0 <mult_D2A+0x128>
 *   @0x23d5d4 str r3, [sp, #0x4]
 *   @0x23d5d8 ldm sp, {r2, r3}
 *   @0x23d5dc mov r0, r2
 *   @0x23d5e0 str r3, [r2, #0x10]
 *   @0x23d5e4 add sp, sp, #20
 *   @0x23d5e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §36/91 b2BlockAllocator::Allocate  0x2c65c0  size 336  84 条（0x2c65c0..0x2c6710）
 * @func 0x2c65c0 0x2c6710  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int)×2 / __divsi3 / b2BlockAllocator::Allocate(int)+0xc4 / 0xb65bc / 0xb65b0 / b2Free(void*)
 * 字段偏移 top8: 0x4×7 / 0xc×3 / 0x8×2 / 0x128×1 / 0xd4×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c65c0 cmp r1, #0
 *   @0x2c65c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c65c8 mov r5, r0
 *   @0x2c65cc beq 0x2c66ac <_ZN16b2BlockAllocator8AllocateEi+0xec>
 *   @0x2c65d0 cmp r1, #640
 *   @0x2c65d4 bgt 0x2c6608 <_ZN16b2BlockAllocator8AllocateEi+0x48>
 *   @0x2c65d8 ldr r3, [pc, #0x128]
 *   @0x2c65dc ldr r3, [pc, r3]
 *   @0x2c65e0 ldrb r8, [r3, r1]
 *   @0x2c65e4 add r7, r0, r8, lsl #2
 *   @0x2c65e8 ldr r4, [r7, #0xc]
 *   @0x2c65ec cmp r4, #0
 *   @0x2c65f0 beq 0x2c6614 <_ZN16b2BlockAllocator8AllocateEi+0x54>
 *   @0x2c65f4 ldr r3, [r4]
 *   @0x2c65f8 mov r6, r4
 *   @0x2c65fc mov r0, r6
 *   @0x2c6600 str r3, [r7, #0xc]
 *   @0x2c6604 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c6608 mov r0, r1
 *   @0x2c660c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c6610 b 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c6614 ldr r10, [r0, #0x4]
 *   @0x2c6618 ldr r3, [r0, #0x8]
 *   @0x2c661c cmp r10, r3
 *   @0x2c6620 beq 0x2c66b8 <_ZN16b2BlockAllocator8AllocateEi+0xf8>
 *   @0x2c6624 mov r0, #16384
 *   @0x2c6628 ldr r9, [r5]
 *   @0x2c662c bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c6630 ldr r3, [pc, #0xd4]
 *   @0x2c6634 add r2, r9, r10, lsl #3
 *   @0x2c6638 ldr r3, [pc, r3]
 *   @0x2c663c ldr r4, [r3, r8, lsl #2]
 *   @0x2c6640 mov r1, r4
 *   @0x2c6644 mov r6, r0
 *   @0x2c6648 mov r0, #16384
 *   @0x2c664c str r6, [r2, #0x4]
 *   @0x2c6650 str r4, [r9, r10, lsl #3]
 *   @0x2c6654 bl 0x318d10 <__divsi3>
 *   @0x2c6658 sub r0, r0, #1
 *   @0x2c665c cmp r0, #0
 *   @0x2c6660 addgt r3, r6, r4
 *   @0x2c6664 movgt r2, #0
 *   @0x2c6668 ble 0x2c6684 <_ZN16b2BlockAllocator8AllocateEi+0xc4>
 *   @0x2c666c add r2, r2, #1
 *   @0x2c6670 rsb r12, r4, r3
 *   @0x2c6674 cmp r2, r0
 *   @0x2c6678 str r3, [r12]
 *   @0x2c667c add r3, r3, r4
 *   @0x2c6680 bne 0x2c666c <_ZN16b2BlockAllocator8AllocateEi+0xac>
 *   @0x2c6684 mul r4, r0, r4
 *   @0x2c6688 mov r3, #0
 *   @0x2c668c mov r0, r6
 *   @0x2c6690 str r3, [r6, r4]
 *   @0x2c6694 ldr r3, [r6]
 *   @0x2c6698 str r3, [r7, #0xc]
 *   @0x2c669c ldr r3, [r5, #0x4]
 *   @0x2c66a0 add r3, r3, #1
 *   @0x2c66a4 str r3, [r5, #0x4]
 *   @0x2c66a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c66ac mov r6, r1
 *   @0x2c66b0 mov r0, r6
 *   @0x2c66b4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c66b8 add r0, r10, #128
 *   @0x2c66bc str r0, [r5, #0x8]
 *   @0x2c66c0 ldr r6, [r5]
 *   @0x2c66c4 lsl r0, r0, #3
 *   @0x2c66c8 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c66cc ldr r2, [r5, #0x4]
 *   @0x2c66d0 mov r1, r6
 *   @0x2c66d4 lsl r2, r2, #3
 *   @0x2c66d8 str r0, [r5]
 *   @0x2c66dc bl 0xb65bc <memcpy@plt>
 *   @0x2c66e0 ldr r0, [r5, #0x4]
 *   @0x2c66e4 ldr r3, [r5]
 *   @0x2c66e8 mov r1, r4
 *   @0x2c66ec mov r2, #1024
 *   @0x2c66f0 add r0, r3, r0, lsl #3
 *   @0x2c66f4 bl 0xb65b0 <memset@plt>
 *   @0x2c66f8 mov r0, r6
 *   @0x2c66fc bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c6700 ldr r10, [r5, #0x4]
 *   @0x2c6704 b 0x2c6624 <_ZN16b2BlockAllocator8AllocateEi+0x64>
 *   @0x2c6708 andseq r11, r2, r0, lsl #10
 *   @0x2c670c andseq r11, r2, r0, lsr #9
 *
 * ══ §37/91 FlushAchievementCache  0x159640  size 332  83 条（0x159640..0x15978c）
 * @func 0x159640 0x15978c  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Achievement_PlayerID()×2 / WriteInt32(unsigned int, unsigned char*, int*)×2 / 0xb6538 / 0xb6550 / FlushAchievementCache()+0x100 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / WriteString(char const*, unsigned char*, int*) / LoadSave::WriteFile(char const*, char const*, int)
 * 字段偏移 top8: 0x124×2 / 0x104×2 / 0xc×2 / 0xd4×2 / 0xb8×1 / 0x8×1 / 0x10×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159640 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x159644 sub sp, sp, #268
 *   @0x159648 ldr r7, [pc, #0x124]
 *   @0x15964c ldr r8, [pc, #0x124]
 *   @0x159650 ldr r7, [pc, r7]
 *   @0x159654 ldr r8, [pc, r8]
 *   @0x159658 ldr r4, [r7]
 *   @0x15965c ldr r3, [r8]
 *   @0x159660 cmp r4, #0
 *   @0x159664 str r3, [sp, #0x104]
 *   @0x159668 beq 0x159768 <_Z21FlushAchievementCachev+0x128>
 *   @0x15966c mov r5, #0
 *   @0x159670 ldr r0, [r4, #0xc]
 *   @0x159674 bl 0xb6538 <strlen@plt>
 *   @0x159678 ldr r4, [r4]
 *   @0x15967c cmp r4, #0
 *   @0x159680 add r0, r0, r5
 *   @0x159684 add r5, r0, #9
 *   @0x159688 bne 0x159670 <_Z21FlushAchievementCachev+0x30>
 *   @0x15968c bl 0x161210 <_Z20Achievement_PlayerIDv>
 *   @0x159690 cmp r0, #0
 *   @0x159694 beq 0x159740 <_Z21FlushAchievementCachev+0x100>
 *   @0x159698 bl 0x161210 <_Z20Achievement_PlayerIDv>
 *   @0x15969c add r9, sp, #4
 *   @0x1596a0 ldr r1, [pc, #0xd4]
 *   @0x1596a4 ldr r3, [pc, #0xd4]
 *   @0x1596a8 add r1, pc, r1
 *   @0x1596ac add r3, pc, r3
 *   @0x1596b0 mov r2, r0
 *   @0x1596b4 mov r0, r9
 *   @0x1596b8 bl 0xb6550 <sprintf@plt>
 *   @0x1596bc cmp r5, #0
 *   @0x1596c0 ble 0x159740 <_Z21FlushAchievementCachev+0x100>
 *   @0x1596c4 ldr r1, [pc, #0xb8]
 *   @0x1596c8 mov r3, #1
 *   @0x1596cc mov r0, r5
 *   @0x1596d0 movw r2, #0x11d
 *   @0x1596d4 add r1, pc, r1
 *   @0x1596d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1596dc ldr r4, [r7]
 *   @0x1596e0 mov r3, #0
 *   @0x1596e4 str r3, [sp]
 *   @0x1596e8 cmp r4, r3
 *   @0x1596ec mov r6, r0
 *   @0x1596f0 beq 0x159730 <_Z21FlushAchievementCachev+0xf0>
 *   @0x1596f4 ldr r0, [r4, #0x8]
 *   @0x1596f8 mov r1, r6
 *   @0x1596fc mov r2, sp
 *   @0x159700 bl 0x1595b4 <_Z10WriteInt32jPhPi>
 *   @0x159704 ldr r0, [r4, #0xc]
 *   @0x159708 mov r1, r6
 *   @0x15970c mov r2, sp
 *   @0x159710 bl 0x159604 <_Z11WriteStringPKcPhPi>
 *   @0x159714 ldr r0, [r4, #0x10]
 *   @0x159718 mov r1, r6
 *   @0x15971c mov r2, sp
 *   @0x159720 bl 0x1595b4 <_Z10WriteInt32jPhPi>
 *   @0x159724 ldr r4, [r4]
 *   @0x159728 cmp r4, #0
 *   @0x15972c bne 0x1596f4 <_Z21FlushAchievementCachev+0xb4>
 *   @0x159730 mov r0, r9
 *   @0x159734 mov r1, r6
 *   @0x159738 mov r2, r5
 *   @0x15973c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i>
 *   @0x159740 ldr r0, [sp, #0x104]
 *   @0x159744 mov r2, #0
 *   @0x159748 ldr r3, [pc, #0x38]
 *   @0x15974c ldr r1, [r8]
 *   @0x159750 ldr r3, [pc, r3]
 *   @0x159754 cmp r0, r1
 *   @0x159758 strb r2, [r3]
 *   @0x15975c bne 0x159770 <_Z21FlushAchievementCachev+0x130>
 *   @0x159760 add sp, sp, #268
 *   @0x159764 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x159768 mov r5, r4
 *   @0x15976c b 0x15968c <_Z21FlushAchievementCachev+0x4c>
 *   @0x159770 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x159774 eoreq r6, r9, r4, ror r5
 *   @0x159778 .word 0x002942fc
 *   @0x15977c andseq r11, sp, r12, lsr #10
 *   @0x159780 andseq sp, lr, r12, lsl #8
 *   @0x159784 mulseq lr, r0, lr
 *   @0x159788 eoreq r6, r9, r8, ror r4
 *
 * ══ §38/91 GR_Draw_Clear  0x169f58  size 332  83 条（0x169f58..0x16a0a4）
 * @func 0x169f58 0x16a0a4  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x169f68→0x3f23dc, 0x169f8c→0x3f23b0, 0x169fa0→0x3f23ac, 0x169fb4→0x3f23a8, 0x169fe4→0x3f23a4
 * 调用序列: Graphics::Flush() / GR_Surface_Get(int) / GR_Texture_Get_Surface(int) / GR_D3D_Set_View_Port(int, int, int, int) / Graphics::Clear(unsigned int, float, int, eClearFlags)
 * 字段偏移 top8: 0x8×3 / 0x120×2 / 0xc×2 / 0x4×2 / 0x100×1 / 0xf0×1 / 0xe0×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169f58 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x169f5c mov r5, r0
 *   @0x169f60 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x169f64 ldr r4, [pc, #0x120]
 *   @0x169f68 ldr r3, [pc, #0x120]
 *   @0x169f6c add r4, pc, r4
 *   @0x169f70 ldr r3, [r4, r3]
 *   @0x169f74 ldr r0, [r3]
 *   @0x169f78 cmn r0, #1
 *   @0x169f7c beq 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x169f80 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x169f84 subs r7, r0, #0
 *   @0x169f88 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x169f8c ldr r3, [pc, #0x100]
 *   @0x169f90 ldr r6, [r4, r3]
 *   @0x169f94 ldr r3, [r6]
 *   @0x169f98 cmp r3, #0
 *   @0x169f9c bne 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x169fa0 ldr r3, [pc, #0xf0]
 *   @0x169fa4 ldr r8, [r4, r3]
 *   @0x169fa8 ldr r3, [r8]
 *   @0x169fac cmp r3, #0
 *   @0x169fb0 bne 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x169fb4 ldr r3, [pc, #0xe0]
 *   @0x169fb8 ldr r2, [r7, #0x8]
 *   @0x169fbc ldr r9, [r4, r3]
 *   @0x169fc0 ldr r3, [r9]
 *   @0x169fc4 cmp r2, r3
 *   @0x169fc8 beq 0x169fe4 <_Z13GR_Draw_Clearj+0x8c>
 *   @0x169fcc mov r0, r5
 *   @0x169fd0 mov r1, #1065353216
 *   @0x169fd4 mov r2, #0
 *   @0x169fd8 mov r3, #7
 *   @0x169fdc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x169fe0 b 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags>
 *   @0x169fe4 ldr r3, [pc, #0xb4]
 *   @0x169fe8 ldr r2, [r7, #0xc]
 *   @0x169fec ldr r4, [r4, r3]
 *   @0x169ff0 ldr r3, [r4]
 *   @0x169ff4 cmp r2, r3
 *   @0x169ff8 bne 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x169ffc ldr r0, [r7, #0x4]
 *   @0x16a000 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x16a004 cmp r0, #0
 *   @0x16a008 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x16a00c ldr r2, [r0, #0x4]
 *   @0x16a010 ldr r1, [r7, #0x8]
 *   @0x16a014 ldr r3, [r0, #0x8]
 *   @0x16a018 cmp r2, r1
 *   @0x16a01c ldr r0, [r7, #0xc]
 *   @0x16a020 bne 0x16a02c <_Z13GR_Draw_Clearj+0xd4>
 *   @0x16a024 cmp r3, r0
 *   @0x16a028 beq 0x169fcc <_Z13GR_Draw_Clearj+0x74>
 *   @0x16a02c add r12, r0, #1
 *   @0x16a030 ldr r10, [r6]
 *   @0x16a034 mov r0, #0
 *   @0x16a038 ldr r7, [r8]
 *   @0x16a03c ldr r6, [r9]
 *   @0x16a040 add r1, r1, #1
 *   @0x16a044 ldr r4, [r4]
 *   @0x16a048 cmp r2, r1
 *   @0x16a04c movge r2, r1
 *   @0x16a050 cmp r3, r12
 *   @0x16a054 movge r3, r12
 *   @0x16a058 mov r1, r0
 *   @0x16a05c bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x16a060 mov r0, r5
 *   @0x16a064 mov r1, #1065353216
 *   @0x16a068 mov r2, #0
 *   @0x16a06c mov r3, #7
 *   @0x16a070 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags>
 *   @0x16a074 mov r0, r10
 *   @0x16a078 mov r1, r7
 *   @0x16a07c mov r2, r6
 *   @0x16a080 mov r3, r4
 *   @0x16a084 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16a088 b 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x16a08c eoreq r7, r8, r4, ror #25
 *   @0x16a090 .word 0xffffe51c
 *   @0x16a094 .word 0xffffe4ec
 *   @0x16a098 .word 0xffffe4f0
 *   @0x16a09c .word 0xffffe4f4
 *   @0x16a0a0 .word 0xffffe4f8
 *
 * ══ §39/91 yySocket::ReadFrom  0x2952ec  size 332  83 条（0x2952ec..0x295438）
 * @func 0x2952ec 0x295438  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6dfc×2 / 0xb6e08 / 0xb6e14 / 0xb65d4
 * 字段偏移 top8: 0xc×4 / 0x2c×2 / 0x4×2 / 0x12×2 / 0x134×1 / 0xc4×1 / 0x48×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2952ec push {r4, r5, r6, r7, r8, lr}
 *   @0x2952f0 sub sp, sp, #48
 *   @0x2952f4 ldr r4, [pc, #0x134]
 *   @0x2952f8 ldrb r12, [r0, #0xc4]
 *   @0x2952fc ldr r4, [pc, r4]
 *   @0x295300 ldr r6, [sp, #0x48]
 *   @0x295304 cmp r12, #0
 *   @0x295308 ldr r5, [sp, #0x4c]
 *   @0x29530c ldr r12, [r4]
 *   @0x295310 str r12, [sp, #0x2c]
 *   @0x295314 beq 0x2953b4 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xc8>
 *   @0x295318 ldr r8, [r0]
 *   @0x29531c mov r12, #28
 *   @0x295320 ldr lr, [r0, #0xc]
 *   @0x295324 str r12, [sp, #0xc]
 *   @0x295328 orr r3, r3, lr
 *   @0x29532c mov r0, r8
 *   @0x295330 add lr, sp, #16
 *   @0x295334 str lr, [sp]
 *   @0x295338 add lr, sp, #12
 *   @0x29533c str lr, [sp, #0x4]
 *   @0x295340 bl 0xb6dfc <recvfrom@plt>
 *   @0x295344 ldr r7, [pc, #0xe8]
 *   @0x295348 add r1, sp, #24
 *   @0x29534c mov r3, #256
 *   @0x295350 add r7, pc, r7
 *   @0x295354 mov r2, r7
 *   @0x295358 mov r8, r0
 *   @0x29535c mov r0, #10
 *   @0x295360 bl 0xb6e08 <inet_ntop@plt>
 *   @0x295364 cmp r0, #0
 *   @0x295368 beq 0x295374 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x88>
 *   @0x29536c cmp r6, #0
 *   @0x295370 strne r7, [r6]
 *   @0x295374 cmp r5, #0
 *   @0x295378 beq 0x295398 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xac>
 *   @0x29537c ldrh r3, [sp, #16]
 *   @0x295380 mov r2, #0
 *   @0x295384 str r2, [r5]
 *   @0x295388 cmp r3, #2
 *   @0x29538c beq 0x295418 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x12c>
 *   @0x295390 cmp r3, #10
 *   @0x295394 beq 0x295418 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x12c>
 *   @0x295398 mov r0, r8
 *   @0x29539c ldr r2, [sp, #0x2c]
 *   @0x2953a0 ldr r3, [r4]
 *   @0x2953a4 cmp r2, r3
 *   @0x2953a8 bne 0x29542c <_ZN8yySocket8ReadFromEPvjjPPcPi+0x140>
 *   @0x2953ac add sp, sp, #48
 *   @0x2953b0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2953b4 ldr r7, [r0]
 *   @0x2953b8 mov r12, #16
 *   @0x2953bc ldr lr, [r0, #0xc]
 *   @0x2953c0 add r0, sp, #16
 *   @0x2953c4 str r0, [sp]
 *   @0x2953c8 orr r3, r3, lr
 *   @0x2953cc mov r0, r7
 *   @0x2953d0 add lr, sp, #12
 *   @0x2953d4 str lr, [sp, #0x4]
 *   @0x2953d8 str r12, [sp, #0xc]
 *   @0x2953dc bl 0xb6dfc <recvfrom@plt>
 *   @0x2953e0 cmp r6, #0
 *   @0x2953e4 mov r7, r0
 *   @0x2953e8 beq 0x2953f8 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x10c>
 *   @0x2953ec ldr r0, [sp, #0x14]
 *   @0x2953f0 bl 0xb6e14 <inet_ntoa@plt>
 *   @0x2953f4 str r0, [r6]
 *   @0x2953f8 cmp r5, #0
 *   @0x2953fc beq 0x295410 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x124>
 *   @0x295400 ldrh r3, [sp, #18]
 *   @0x295404 rev16 r3, r3
 *   @0x295408 uxth r3, r3
 *   @0x29540c str r3, [r5]
 *   @0x295410 mov r0, r7
 *   @0x295414 b 0x29539c <_ZN8yySocket8ReadFromEPvjjPPcPi+0xb0>
 *   @0x295418 ldrh r3, [sp, #18]
 *   @0x29541c rev16 r3, r3
 *   @0x295420 uxth r3, r3
 *   @0x295424 str r3, [r5]
 *   @0x295428 b 0x295398 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xac>
 *   @0x29542c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x295430 andseq r8, r5, r4, asr r6
 *   @0x295434 subeq r2, r12, r8, ror #8
 *
 * ══ §40/91 Get_FullScreenOffset  0x179a00  size 328  82 条（0x179a00..0x179b48）
 * @func 0x179a00 0x179b48  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x179a0c→0x499309, 0x179a2c→0x3f50f0, 0x179a40→0x3f26c0, 0x179a44→0x3f26bc, 0x179a68→0x3f510c, 0x179a6c→0x3f5108, 0x179a70→0x3f26c0, 0x179a90→0x3f26bc
 * 调用序列: 无
 * 字段偏移 top8: 0xf0×2 / 0xd0×2 / 0x124×1 / 0x11c×1 / 0x100×1 / 0xc0×1 / 0xa4×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179a00 ldr r12, [pc, #0x124]
 *   @0x179a04 push {r4, r5, r6}
 *   @0x179a08 add r12, pc, r12
 *   @0x179a0c ldr r5, [pc, #0x11c]
 *   @0x179a10 mov r4, #0
 *   @0x179a14 str r4, [r0]
 *   @0x179a18 str r4, [r1]
 *   @0x179a1c ldr r4, [r12, r5]
 *   @0x179a20 ldrb r4, [r4]
 *   @0x179a24 cmp r4, #0
 *   @0x179a28 beq 0x179a40 <_Z20Get_FullScreenOffsetRiS_S_S_+0x40>
 *   @0x179a2c ldr r4, [pc, #0x100]
 *   @0x179a30 ldr r4, [r12, r4]
 *   @0x179a34 ldrb r4, [r4]
 *   @0x179a38 cmp r4, #0
 *   @0x179a3c bne 0x179a68 <_Z20Get_FullScreenOffsetRiS_S_S_+0x68>
 *   @0x179a40 ldr r0, [pc, #0xf0]
 *   @0x179a44 ldr r1, [pc, #0xf0]
 *   @0x179a48 pop {r4, r5, r6}
 *   @0x179a4c ldr r0, [r12, r0]
 *   @0x179a50 ldr r0, [r0]
 *   @0x179a54 str r0, [r2]
 *   @0x179a58 ldr r2, [r12, r1]
 *   @0x179a5c ldr r2, [r2]
 *   @0x179a60 str r2, [r3]
 *   @0x179a64 bx lr
 *   @0x179a68 ldr r6, [pc, #0xd0]
 *   @0x179a6c ldr r5, [pc, #0xd0]
 *   @0x179a70 ldr r4, [pc, #0xc0]
 *   @0x179a74 ldr r6, [r12, r6]
 *   @0x179a78 vldr s12, [r6]
 *   @0x179a7c ldr r5, [r12, r5]
 *   @0x179a80 vcvt.f32.s32 s12, s12
 *   @0x179a84 vldr s11, [r5]
 *   @0x179a88 ldr r4, [r12, r4]
 *   @0x179a8c vldr s9, [r4]
 *   @0x179a90 ldr r5, [pc, #0xa4]
 *   @0x179a94 ldr r12, [r12, r5]
 *   @0x179a98 vcvt.f32.s32 s11, s11
 *   @0x179a9c vdiv.f32 s13, s12, s11
 *   @0x179aa0 vcvt.f32.s32 s15, s9
 *   @0x179aa4 vldr s9, [r12]
 *   @0x179aa8 vdiv.f32 s10, s15, s13
 *   @0x179aac vcvt.f32.s32 s14, s9
 *   @0x179ab0 vcmpe.f32 s10, s14
 *   @0x179ab4 vmrs APSR_nzcv, fpscr
 *   @0x179ab8 bmi 0x179afc <_Z20Get_FullScreenOffsetRiS_S_S_+0xfc>
 *   @0x179abc vmul.f32 s14, s13, s14
 *   @0x179ac0 vmov.f32 s13, #5.000000e-01
 *   @0x179ac4 vsub.f32 s15, s15, s14
 *   @0x179ac8 vmul.f32 s15, s15, s13
 *   @0x179acc vcvt.s32.f32 s15, s15
 *   @0x179ad0 vcvt.f32.s32 s13, s15
 *   @0x179ad4 vstr s15, [r0]
 *   @0x179ad8 vldr s15, [r12]
 *   @0x179adc vadd.f32 s14, s14, s13
 *   @0x179ae0 vcvt.f32.s32 s15, s15
 *   @0x179ae4 pop {r4, r5, r6}
 *   @0x179ae8 vcvt.s32.f32 s14, s14
 *   @0x179aec vcvt.s32.f32 s15, s15
 *   @0x179af0 vstr s14, [r2]
 *   @0x179af4 vstr s15, [r3]
 *   @0x179af8 bx lr
 *   @0x179afc vdiv.f32 s12, s11, s12
 *   @0x179b00 vmul.f32 s15, s15, s12
 *   @0x179b04 vmov.f32 s13, #5.000000e-01
 *   @0x179b08 vsub.f32 s14, s14, s15
 *   @0x179b0c vmul.f32 s14, s14, s13
 *   @0x179b10 vcvt.s32.f32 s14, s14
 *   @0x179b14 vcvt.f32.s32 s12, s14
 *   @0x179b18 vstr s14, [r1]
 *   @0x179b1c vldr s14, [r4]
 *   @0x179b20 vadd.f32 s15, s15, s12
 *   @0x179b24 vcvt.f32.s32 s14, s14
 *   @0x179b28 b 0x179ae4 <_Z20Get_FullScreenOffsetRiS_S_S_+0xe4>
 *   @0x179b2c eoreq r8, r7, r8, asr #4
 *   @0x179b30 .word 0xffffe6a0
 *   @0x179b34 .word 0xffffe6a4
 *   @0x179b38 .word 0xffffe24c
 *   @0x179b3c .word 0xffffe250
 *   @0x179b40 .word 0xffffdf38
 *   @0x179b44 .word 0xffffdf40
 *
 * ══ §41/91 Graphics::SetRenderTarget  0x183590  size 328  82 条（0x183590..0x1836d8）
 * @func 0x183590 0x1836d8  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1835b4→0x3f28a4, 0x1835f0→0x757748, 0x183628→0x3f26dc, 0x18362c→0x479b44, 0x18363c→0x479c00, 0x1836a0→0x3f23b4
 * 调用序列: Graphics::Flush() / Graphics::SetRenderTarget(int, void*)+0x38 / Graphics::SetRenderTarget(int, void*)+0x44 / _CreateTextureIfInvalid(Texture*, bool, eMipEnable) / _UpdateActiveDrawBuffers() / bindFBO(int, int, int)
 * 字段偏移 top8: 0xcc×2 / 0x98×2 / 0x14×2 / 0x110×1 / 0x100×1 / 0x4×1 / 0x18×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183590 push {r4, r5, r6, r7, lr}
 *   @0x183594 sub sp, sp, #12
 *   @0x183598 mov r4, r0
 *   @0x18359c mov r6, r1
 *   @0x1835a0 ldr r5, [pc, #0x110]
 *   @0x1835a4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1835a8 cmp r4, #0
 *   @0x1835ac add r5, pc, r5
 *   @0x1835b0 blt 0x1835c8 <_ZN8Graphics15SetRenderTargetEiPv+0x38>
 *   @0x1835b4 ldr r3, [pc, #0x100]
 *   @0x1835b8 ldr r3, [r5, r3]
 *   @0x1835bc ldr r3, [r3]
 *   @0x1835c0 cmp r4, r3
 *   @0x1835c4 blt 0x1835d4 <_ZN8Graphics15SetRenderTargetEiPv+0x44>
 *   @0x1835c8 mov r0, #0
 *   @0x1835cc add sp, sp, #12
 *   @0x1835d0 pop {r4, r5, r6, r7, pc}
 *   @0x1835d4 mov r0, r6
 *   @0x1835d8 mov r1, #1
 *   @0x1835dc mvn r2, #0
 *   @0x1835e0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x1835e4 cmp r4, #0
 *   @0x1835e8 beq 0x183680 <_ZN8Graphics15SetRenderTargetEiPv+0xf0>
 *   @0x1835ec ldr r3, [pc, #0xcc]
 *   @0x1835f0 ldr r1, [pc, #0xcc]
 *   @0x1835f4 add r3, pc, r3
 *   @0x1835f8 add r2, r3, #4
 *   @0x1835fc ldr r3, [r3]
 *   @0x183600 ldr r1, [r5, r1]
 *   @0x183604 rsb r3, r3, r3, lsl #3
 *   @0x183608 ldr r1, [r1]
 *   @0x18360c lsl r3, r3, #2
 *   @0x183610 add r7, r2, r3
 *   @0x183614 ldr r3, [r2, r3]
 *   @0x183618 cmp r3, r1
 *   @0x18361c beq 0x18368c <_ZN8Graphics15SetRenderTargetEiPv+0xfc>
 *   @0x183620 cmp r3, #0
 *   @0x183624 beq 0x18368c <_ZN8Graphics15SetRenderTargetEiPv+0xfc>
 *   @0x183628 ldr r3, [pc, #0x98]
 *   @0x18362c ldr r2, [pc, #0x98]
 *   @0x183630 ldr r3, [r5, r3]
 *   @0x183634 ldr r3, [r3]
 *   @0x183638 cmp r3, #1
 *   @0x18363c ldrne r2, [pc, #0x8c]
 *   @0x183640 ldr r12, [r5, r2]
 *   @0x183644 add r1, r4, #35840
 *   @0x183648 ldr r3, [r6, #0x14]
 *   @0x18364c mov lr, #0
 *   @0x183650 movw r0, #0x8d40
 *   @0x183654 str lr, [sp]
 *   @0x183658 add r1, r1, #224
 *   @0x18365c movw r2, #0xde1
 *   @0x183660 ldr r12, [r12]
 *   @0x183664 add r4, r7, r4, lsl #2
 *   @0x183668 blx r12
 *   @0x18366c ldr r3, [r6, #0x14]
 *   @0x183670 str r3, [r4, #0x4]
 *   @0x183674 bl 0x180904 <_Z24_UpdateActiveDrawBuffersv>
 *   @0x183678 mov r0, #1
 *   @0x18367c b 0x1835cc <_ZN8Graphics15SetRenderTargetEiPv+0x3c>
 *   @0x183680 ldr r0, [r6, #0x18]
 *   @0x183684 cmp r0, #0
 *   @0x183688 bne 0x183698 <_ZN8Graphics15SetRenderTargetEiPv+0x108>
 *   @0x18368c mov r0, #1
 *   @0x183690 add sp, sp, #12
 *   @0x183694 pop {r4, r5, r6, r7, pc}
 *   @0x183698 ldmib r6, {r1, r2}
 *   @0x18369c bl 0x180908 <_Z7bindFBOiii>
 *   @0x1836a0 ldr r3, [pc, #0x2c]
 *   @0x1836a4 mvn r2, #0
 *   @0x1836a8 mov r0, #1
 *   @0x1836ac ldr r3, [r5, r3]
 *   @0x1836b0 str r2, [r3]
 *   @0x1836b4 b 0x1835cc <_ZN8Graphics15SetRenderTargetEiPv+0x3c>
 *   @0x1836b8 eoreq lr, r6, r4, lsr #13
 *   @0x1836bc .word 0xffffe8e0
 *   @0x1836c0 eorseq lr, r1, r8, lsl #28
 *   @0x1836c4 .word 0xffffe908
 *   @0x1836c8 .word 0xffffe7b8
 *   @0x1836cc .word 0xffffbb6c
 *   @0x1836d0 .word 0xffffbc7c
 *   @0x1836d4 .word 0xffffe48c
 *
 * ══ §42/91 yySocket::ReadAndProcessDataStream  0x296e1c  size 328  82 条（0x296e1c..0x296f64）
 * @func 0x296e1c 0x296f64  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::HandleMessage(yyServer*)×2 / yySocket::ReadAndProcessDataStream(yyServer*)+0x7c×2 / yySocket::Peek() / yySocket::ReadAndProcessDataStream(yyServer*)+0x120 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / yySocket::ReadMessageHeader() / yySocket::Read(void*, unsigned int, unsigned int) / yySocket::ReadAndProcessDataStream(yyServer*)+0x114
 * 字段偏移 top8: 0xbc×6 / 0xc0×6 / 0x50×3 / 0x54×2 / 0x134×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296e1c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x296e20 mov r6, #0
 *   @0x296e24 ldr r8, [pc, #0x134]
 *   @0x296e28 sub sp, sp, #12
 *   @0x296e2c mov r4, r0
 *   @0x296e30 mov r9, r1
 *   @0x296e34 add r8, pc, r8
 *   @0x296e38 mov r7, r6
 *   @0x296e3c ldr r3, [r4, #0xbc]
 *   @0x296e40 cmp r3, #0
 *   @0x296e44 beq 0x296ed0 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0xb4>
 *   @0x296e48 cmp r3, #0
 *   @0x296e4c ldr r5, [r4, #0xc0]
 *   @0x296e50 mov r0, r4
 *   @0x296e54 ldr r11, [r4, #0x50]
 *   @0x296e58 ldrle r10, [r4, #0x54]
 *   @0x296e5c rsbgt r10, r5, r3
 *   @0x296e60 rsble r10, r5, r10
 *   @0x296e64 bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x296e68 cmp r0, #0
 *   @0x296e6c bgt 0x296eec <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0xd0>
 *   @0x296e70 ldr r3, [r4, #0xbc]
 *   @0x296e74 cmp r3, #0
 *   @0x296e78 ble 0x296f3c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x120>
 *   @0x296e7c ldr r2, [r4, #0xc0]
 *   @0x296e80 cmp r3, r2
 *   @0x296e84 bgt 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138>
 *   @0x296e88 mov r0, r4
 *   @0x296e8c mov r1, r9
 *   @0x296e90 bl 0x296dd8 <_ZN8yySocket13HandleMessageEP8yyServer>
 *   @0x296e94 ldr r0, [r4, #0xc0]
 *   @0x296e98 ldr r3, [r4, #0x54]
 *   @0x296e9c cmp r3, r0
 *   @0x296ea0 bgt 0x296e3c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x20>
 *   @0x296ea4 lsl r1, r3, #1
 *   @0x296ea8 ldr r0, [r4, #0x50]
 *   @0x296eac mov r3, #74
 *   @0x296eb0 str r7, [sp]
 *   @0x296eb4 mov r2, r8
 *   @0x296eb8 str r1, [r4, #0x54]
 *   @0x296ebc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x296ec0 ldr r3, [r4, #0xbc]
 *   @0x296ec4 cmp r3, #0
 *   @0x296ec8 str r0, [r4, #0x50]
 *   @0x296ecc bne 0x296e48 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x2c>
 *   @0x296ed0 mov r0, r4
 *   @0x296ed4 bl 0x296194 <_ZN8yySocket17ReadMessageHeaderEv>
 *   @0x296ed8 cmp r0, #0
 *   @0x296edc beq 0x296f30 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x114>
 *   @0x296ee0 ldr r3, [r4, #0xbc]
 *   @0x296ee4 mov r6, #1
 *   @0x296ee8 b 0x296e48 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x2c>
 *   @0x296eec add r1, r11, r5
 *   @0x296ef0 mov r2, r10
 *   @0x296ef4 mov r0, r4
 *   @0x296ef8 mov r3, #0
 *   @0x296efc bl 0x2952dc <_ZN8yySocket4ReadEPvjj>
 *   @0x296f00 cmp r0, #0
 *   @0x296f04 ble 0x296f30 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x114>
 *   @0x296f08 ldr r3, [r4, #0xbc]
 *   @0x296f0c mov r6, #1
 *   @0x296f10 ldr r2, [r4, #0xc0]
 *   @0x296f14 cmp r3, #0
 *   @0x296f18 add r0, r0, r2
 *   @0x296f1c str r0, [r4, #0xc0]
 *   @0x296f20 ble 0x296e98 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x7c>
 *   @0x296f24 cmp r0, r3
 *   @0x296f28 blt 0x296e98 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x7c>
 *   @0x296f2c b 0x296e88 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x6c>
 *   @0x296f30 ldr r3, [r4, #0xbc]
 *   @0x296f34 cmp r3, #0
 *   @0x296f38 bgt 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138>
 *   @0x296f3c ldr r3, [r4, #0xc0]
 *   @0x296f40 cmp r3, #0
 *   @0x296f44 ble 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138>
 *   @0x296f48 mov r0, r4
 *   @0x296f4c mov r1, r9
 *   @0x296f50 bl 0x296dd8 <_ZN8yySocket13HandleMessageEP8yyServer>
 *   @0x296f54 mov r0, r6
 *   @0x296f58 add sp, sp, #12
 *   @0x296f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x296f60 strdeq r10, r11, [r9], -r12
 *
 * ══ §43/91 b2Joint::Destroy  0x2cdd98  size 328  82 条（0x2cdd98..0x2cdee0）
 * @func 0x2cdd98 0x2cdee0  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdd98 push {r3, r4, r5, lr}
 *   @0x2cdd9c mov r4, r0
 *   @0x2cdda0 ldr r3, [r0]
 *   @0x2cdda4 mov r5, r1
 *   @0x2cdda8 ldr r3, [r3, #0x18]
 *   @0x2cddac blx r3
 *   @0x2cddb0 ldr r3, [r4, #0x4]
 *   @0x2cddb4 sub r3, r3, #1
 *   @0x2cddb8 cmp r3, #10
 *   @0x2cddbc addls pc, pc, r3, lsl #2
 *   @0x2cddc0 b 0x2cdeb8 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x120>
 *   @0x2cddc4 b 0x2cde04 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x6c>
 *   @0x2cddc8 b 0x2cde18 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x80>
 *   @0x2cddcc b 0x2cde2c <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x94>
 *   @0x2cddd0 b 0x2cde40 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xa8>
 *   @0x2cddd4 b 0x2cddf0 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x58>
 *   @0x2cddd8 b 0x2cde68 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xd0>
 *   @0x2cdddc b 0x2cde7c <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xe4>
 *   @0x2cdde0 b 0x2cde90 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xf8>
 *   @0x2cdde4 b 0x2cdea4 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x10c>
 *   @0x2cdde8 b 0x2cddf0 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0x58>
 *   @0x2cddec b 0x2cde54 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator+0xbc>
 *   @0x2cddf0 mov r0, r5
 *   @0x2cddf4 mov r1, r4
 *   @0x2cddf8 mov r2, #168
 *   @0x2cddfc pop {r3, r4, r5, lr}
 *   @0x2cde00 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde04 mov r0, r5
 *   @0x2cde08 mov r1, r4
 *   @0x2cde0c mov r2, #228
 *   @0x2cde10 pop {r3, r4, r5, lr}
 *   @0x2cde14 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde18 mov r0, r5
 *   @0x2cde1c mov r1, r4
 *   @0x2cde20 mov r2, #256
 *   @0x2cde24 pop {r3, r4, r5, lr}
 *   @0x2cde28 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde2c mov r0, r5
 *   @0x2cde30 mov r1, r4
 *   @0x2cde34 mov r2, #176
 *   @0x2cde38 pop {r3, r4, r5, lr}
 *   @0x2cde3c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde40 mov r0, r5
 *   @0x2cde44 mov r1, r4
 *   @0x2cde48 mov r2, #196
 *   @0x2cde4c pop {r3, r4, r5, lr}
 *   @0x2cde50 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde54 mov r0, r5
 *   @0x2cde58 mov r1, r4
 *   @0x2cde5c mov r2, #192
 *   @0x2cde60 pop {r3, r4, r5, lr}
 *   @0x2cde64 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde68 mov r0, r5
 *   @0x2cde6c mov r1, r4
 *   @0x2cde70 mov r2, #276
 *   @0x2cde74 pop {r3, r4, r5, lr}
 *   @0x2cde78 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde7c mov r0, r5
 *   @0x2cde80 mov r1, r4
 *   @0x2cde84 mov r2, #224
 *   @0x2cde88 pop {r3, r4, r5, lr}
 *   @0x2cde8c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cde90 mov r0, r5
 *   @0x2cde94 mov r1, r4
 *   @0x2cde98 mov r2, #208
 *   @0x2cde9c pop {r3, r4, r5, lr}
 *   @0x2cdea0 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cdea4 mov r0, r5
 *   @0x2cdea8 mov r1, r4
 *   @0x2cdeac mov r2, #180
 *   @0x2cdeb0 pop {r3, r4, r5, lr}
 *   @0x2cdeb4 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2cdeb8 ldr r3, [pc, #0x18]
 *   @0x2cdebc mov r0, #0
 *   @0x2cdec0 ldr r1, [pc, #0x14]
 *   @0x2cdec4 ldr r3, [pc, r3]
 *   @0x2cdec8 add r1, pc, r1
 *   @0x2cdecc ldr r3, [r3]
 *   @0x2cded0 blx r3
 *   @0x2cded4 pop {r3, r4, r5, pc}
 *   @0x2cded8 andseq r3, r2, r4, lsl #12
 *   @0x2cdedc .word 0x0008f5f8
 *
 * ══ §44/91 b2ParticleSystem::SolveCollision  0x2d5cc0  size 328  82 条（0x2d5cc0..0x2d5e08）
 * @func 0x2d5cc0 0x2d5e08  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveCollision(b2TimeStep const&)+0xf8 / b2World::QueryAABB(b2QueryCallback*, b2AABB const&) const
 * 字段偏移 top8: 0x38×2 / 0x24×1 / 0x40×1 / 0x14×1 / 0x10×1 / 0xd4×1
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5cc0 ldr r12, [r0, #0x24]
 *   @0x2d5cc4 vldr s11, [pc, #304]
 *   @0x2d5cc8 push {r4, r5, lr}
 *   @0x2d5ccc vldr s10, [pc, #300]
 *   @0x2d5cd0 cmp r12, #0
 *   @0x2d5cd4 sub sp, sp, #52
 *   @0x2d5cd8 mov r4, r0
 *   @0x2d5cdc vstr s11, [sp]
 *   @0x2d5ce0 vstr s11, [sp, #4]
 *   @0x2d5ce4 vstr s10, [sp, #8]
 *   @0x2d5ce8 vstr s10, [sp, #12]
 *   @0x2d5cec ble 0x2d5db8 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep+0xf8>
 *   @0x2d5cf0 ldr r3, [r0, #0x40]
 *   @0x2d5cf4 vmov.f32 s8, s10
 *   @0x2d5cf8 ldr r2, [r0, #0x38]
 *   @0x2d5cfc vldr s5, [r1]
 *   @0x2d5d00 add r12, r3, r12, lsl #3
 *   @0x2d5d04 vmov.f32 s9, s11
 *   @0x2d5d08 vldr s14, [r2]
 *   @0x2d5d0c vldr s15, [r3]
 *   @0x2d5d10 vldr s13, [r3, #4]
 *   @0x2d5d14 add r3, r3, #8
 *   @0x2d5d18 vmov.f32 s12, s14
 *   @0x2d5d1c add r2, r2, #8
 *   @0x2d5d20 vmla.f32 s12, s5, s15
 *   @0x2d5d24 vldr s15, [r2, #-4]
 *   @0x2d5d28 vmov.f32 s7, s15
 *   @0x2d5d2c vmla.f32 s7, s5, s13
 *   @0x2d5d30 vcmpe.f32 s12, s14
 *   @0x2d5d34 vmrs APSR_nzcv, fpscr
 *   @0x2d5d38 vcmpe.f32 s7, s15
 *   @0x2d5d3c vmovle.f32 s6, s12
 *   @0x2d5d40 vmovgt.f32 s6, s14
 *   @0x2d5d44 vmrs APSR_nzcv, fpscr
 *   @0x2d5d48 vmov.f32 s13, s7
 *   @0x2d5d4c vcmpe.f32 s6, s9
 *   @0x2d5d50 vmovgt.f32 s7, s15
 *   @0x2d5d54 vmrs APSR_nzcv, fpscr
 *   @0x2d5d58 vcmpe.f32 s7, s11
 *   @0x2d5d5c vmovle.f32 s9, s6
 *   @0x2d5d60 vmrs APSR_nzcv, fpscr
 *   @0x2d5d64 vstr s9, [sp]
 *   @0x2d5d68 vcmpe.f32 s12, s14
 *   @0x2d5d6c vmovle.f32 s11, s7
 *   @0x2d5d70 vmrs APSR_nzcv, fpscr
 *   @0x2d5d74 vstr s11, [sp, #4]
 *   @0x2d5d78 vcmpe.f32 s13, s15
 *   @0x2d5d7c vmovpl.f32 s14, s12
 *   @0x2d5d80 vmrs APSR_nzcv, fpscr
 *   @0x2d5d84 vcmpe.f32 s14, s8
 *   @0x2d5d88 vmovpl.f32 s15, s13
 *   @0x2d5d8c vmrs APSR_nzcv, fpscr
 *   @0x2d5d90 vcmpe.f32 s15, s10
 *   @0x2d5d94 vmovmi.f32 s14, s8
 *   @0x2d5d98 vmrs APSR_nzcv, fpscr
 *   @0x2d5d9c vstr s14, [sp, #8]
 *   @0x2d5da0 vmovmi.f32 s15, s10
 *   @0x2d5da4 cmp r3, r12
 *   @0x2d5da8 vstr s15, [sp, #12]
 *   @0x2d5dac vmov.f32 s8, s14
 *   @0x2d5db0 vmov.f32 s10, s15
 *   @0x2d5db4 bne 0x2d5d08 <_ZN16b2ParticleSystem14SolveCollisionERK10b2TimeStep+0x48>
 *   @0x2d5db8 mov lr, r1
 *   @0x2d5dbc add r12, sp, #24
 *   @0x2d5dc0 ldm lr!, {r0, r1, r2, r3}
 *   @0x2d5dc4 ldr r5, [pc, #0x38]
 *   @0x2d5dc8 str r4, [sp, #0x14]
 *   @0x2d5dcc add r5, pc, r5
 *   @0x2d5dd0 stm r12!, {r0, r1, r2, r3}
 *   @0x2d5dd4 mov r2, sp
 *   @0x2d5dd8 ldm lr, {r0, r1}
 *   @0x2d5ddc add r5, r5, #8
 *   @0x2d5de0 str r5, [sp, #0x10]
 *   @0x2d5de4 stm r12, {r0, r1}
 *   @0x2d5de8 add r1, sp, #16
 *   @0x2d5dec ldr r0, [r4, #0xd4]
 *   @0x2d5df0 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB>
 *   @0x2d5df4 add sp, sp, #52
 *   @0x2d5df8 pop {r4, r5, pc}
 *   @0x2d5dfc svcvc #0x7fffff
 *   @0x2d5e00 .word 0xff7fffff
 *   @0x2d5e04 ldrsbeq r6, [r1], -r12
 *
 * ══ §45/91 CSkeletonSprite::DrawSkeleton  0xbe054  size 320  80 条（0xbe054..0xbe194）
 * @func 0xbe054 0xbe194  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonSprite::DrawSkeleton(spSkeleton*, unsigned int, float)+0x134 / CSkeletonSprite::DrawMesh(spSlot*, unsigned int) / CSkeletonSprite::DrawRegion(spSlot*, unsigned int)
 * 字段偏移 top8: 0x18×2 / 0x10×1 / 0x2×1 / 0x4×1
 * VFP 指令 41 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe054 ubfx r12, r2, #0x8, #0x8
 *   @0xbe058 push {r4, r5, r6, r7, r8, lr}
 *   @0xbe05c vpush {d8, d9, d10}
 *   @0xbe060 vmov s18, r12
 *   @0xbe064 vldr s16, [pc, #292]
 *   @0xbe068 uxtb r12, r2
 *   @0xbe06c ubfx r2, r2, #0x10, #0x8
 *   @0xbe070 vcvt.f32.s32 s18, s18
 *   @0xbe074 ldr r7, [r1, #0x10]
 *   @0xbe078 vmov s17, r12
 *   @0xbe07c mov r4, r1
 *   @0xbe080 vmov s19, r2
 *   @0xbe084 cmp r7, #0
 *   @0xbe088 mov r6, r0
 *   @0xbe08c vmov s20, r3
 *   @0xbe090 vcvt.f32.s32 s17, s17
 *   @0xbe094 vcvt.f32.s32 s19, s19
 *   @0xbe098 vdiv.f32 s17, s17, s16
 *   @0xbe09c vdiv.f32 s18, s18, s16
 *   @0xbe0a0 vdiv.f32 s19, s19, s16
 *   @0xbe0a4 ble 0xbe188 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x134>
 *   @0xbe0a8 mov r5, #0
 *   @0xbe0ac b 0xbe0c8 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x74>
 *   @0xbe0b0 cmp r3, #2
 *   @0xbe0b4 bne 0xbe0bc <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x68>
 *   @0xbe0b8 bl 0xbdf54 <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj>
 *   @0xbe0bc add r5, r5, #1
 *   @0xbe0c0 cmp r5, r7
 *   @0xbe0c4 beq 0xbe188 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x134>
 *   @0xbe0c8 ldr r3, [r4, #0x18]
 *   @0xbe0cc ldr r1, [r3, r5, lsl #2]
 *   @0xbe0d0 ldr r3, [r1, #0x18]
 *   @0xbe0d4 cmp r3, #0
 *   @0xbe0d8 beq 0xbe0bc <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x68>
 *   @0xbe0dc vldr s15, [r1, #12]
 *   @0xbe0e0 vldr s12, [r4, #64]
 *   @0xbe0e4 vmul.f32 s12, s12, s15
 *   @0xbe0e8 vldr s9, [r4, #68]
 *   @0xbe0ec vldr s13, [r1, #16]
 *   @0xbe0f0 vldr s10, [r4, #60]
 *   @0xbe0f4 vldr s14, [r1, #8]
 *   @0xbe0f8 vldr s11, [r4, #72]
 *   @0xbe0fc vldr s15, [r1, #20]
 *   @0xbe100 ldr r3, [r3, #0x4]
 *   @0xbe104 cmp r3, #0
 *   @0xbe108 vmul.f32 s13, s9, s13
 *   @0xbe10c vmul.f32 s14, s10, s14
 *   @0xbe110 vmul.f32 s12, s12, s18
 *   @0xbe114 vmul.f32 s13, s13, s19
 *   @0xbe118 vmul.f32 s14, s14, s17
 *   @0xbe11c vmul.f32 s15, s11, s15
 *   @0xbe120 vmul.f32 s12, s12, s16
 *   @0xbe124 vmul.f32 s13, s13, s16
 *   @0xbe128 vmul.f32 s14, s14, s16
 *   @0xbe12c vmul.f32 s15, s15, s20
 *   @0xbe130 vcvt.u32.f32 s12, s12
 *   @0xbe134 vcvt.u32.f32 s13, s13
 *   @0xbe138 vmov r8, s12
 *   @0xbe13c vcvt.u32.f32 s14, s14
 *   @0xbe140 vmov r12, s13
 *   @0xbe144 vmov r0, s14
 *   @0xbe148 vmul.f32 s15, s15, s16
 *   @0xbe14c uxtb r8, r8
 *   @0xbe150 lsl r8, r8, #8
 *   @0xbe154 vcvt.u32.f32 s15, s15
 *   @0xbe158 uxtb r12, r12
 *   @0xbe15c orr r12, r8, r12, lsl #16
 *   @0xbe160 uxtb r0, r0
 *   @0xbe164 orr r2, r12, r0
 *   @0xbe168 vmov r0, s15
 *   @0xbe16c orr r2, r2, r0, lsl #24
 *   @0xbe170 mov r0, r6
 *   @0xbe174 bne 0xbe0b0 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x5c>
 *   @0xbe178 add r5, r5, #1
 *   @0xbe17c bl 0xbde18 <_ZN15CSkeletonSprite10DrawRegionEP6spSlotj>
 *   @0xbe180 cmp r5, r7
 *   @0xbe184 bne 0xbe0c8 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x74>
 *   @0xbe188 vpop {d8, d9, d10}
 *   @0xbe18c pop {r4, r5, r6, r7, r8, pc}
 *   @0xbe190 cmnmi pc, #0
 *
 * ══ §46/91 WebToStr  0xf40bc  size 320  80 条（0xf40bc..0xf41fc）
 * @func 0xf40bc 0xf41fc  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xac×1 / 0xa4×1 / 0x9c×1 / 0x94×1 / 0x8c×1 / 0x84×1 / 0x7c×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf40bc sub r0, r0, #60
 *   @0xf40c0 cmp r0, #15
 *   @0xf40c4 addls pc, pc, r0, lsl #2
 *   @0xf40c8 b 0xf41b4 <_Z8WebToStri+0xf8>
 *   @0xf40cc b 0xf410c <_Z8WebToStri+0x50>
 *   @0xf40d0 b 0xf4118 <_Z8WebToStri+0x5c>
 *   @0xf40d4 b 0xf4124 <_Z8WebToStri+0x68>
 *   @0xf40d8 b 0xf4130 <_Z8WebToStri+0x74>
 *   @0xf40dc b 0xf41b4 <_Z8WebToStri+0xf8>
 *   @0xf40e0 b 0xf41b4 <_Z8WebToStri+0xf8>
 *   @0xf40e4 b 0xf413c <_Z8WebToStri+0x80>
 *   @0xf40e8 b 0xf4148 <_Z8WebToStri+0x8c>
 *   @0xf40ec b 0xf4154 <_Z8WebToStri+0x98>
 *   @0xf40f0 b 0xf4160 <_Z8WebToStri+0xa4>
 *   @0xf40f4 b 0xf416c <_Z8WebToStri+0xb0>
 *   @0xf40f8 b 0xf4178 <_Z8WebToStri+0xbc>
 *   @0xf40fc b 0xf4184 <_Z8WebToStri+0xc8>
 *   @0xf4100 b 0xf4190 <_Z8WebToStri+0xd4>
 *   @0xf4104 b 0xf419c <_Z8WebToStri+0xe0>
 *   @0xf4108 b 0xf41a8 <_Z8WebToStri+0xec>
 *   @0xf410c ldr r0, [pc, #0xac]
 *   @0xf4110 add r0, pc, r0
 *   @0xf4114 bx lr
 *   @0xf4118 ldr r0, [pc, #0xa4]
 *   @0xf411c add r0, pc, r0
 *   @0xf4120 bx lr
 *   @0xf4124 ldr r0, [pc, #0x9c]
 *   @0xf4128 add r0, pc, r0
 *   @0xf412c bx lr
 *   @0xf4130 ldr r0, [pc, #0x94]
 *   @0xf4134 add r0, pc, r0
 *   @0xf4138 bx lr
 *   @0xf413c ldr r0, [pc, #0x8c]
 *   @0xf4140 add r0, pc, r0
 *   @0xf4144 bx lr
 *   @0xf4148 ldr r0, [pc, #0x84]
 *   @0xf414c add r0, pc, r0
 *   @0xf4150 bx lr
 *   @0xf4154 ldr r0, [pc, #0x7c]
 *   @0xf4158 add r0, pc, r0
 *   @0xf415c bx lr
 *   @0xf4160 ldr r0, [pc, #0x74]
 *   @0xf4164 add r0, pc, r0
 *   @0xf4168 bx lr
 *   @0xf416c ldr r0, [pc, #0x6c]
 *   @0xf4170 add r0, pc, r0
 *   @0xf4174 bx lr
 *   @0xf4178 ldr r0, [pc, #0x64]
 *   @0xf417c add r0, pc, r0
 *   @0xf4180 bx lr
 *   @0xf4184 ldr r0, [pc, #0x5c]
 *   @0xf4188 add r0, pc, r0
 *   @0xf418c bx lr
 *   @0xf4190 ldr r0, [pc, #0x54]
 *   @0xf4194 add r0, pc, r0
 *   @0xf4198 bx lr
 *   @0xf419c ldr r0, [pc, #0x4c]
 *   @0xf41a0 add r0, pc, r0
 *   @0xf41a4 bx lr
 *   @0xf41a8 ldr r0, [pc, #0x44]
 *   @0xf41ac add r0, pc, r0
 *   @0xf41b0 bx lr
 *   @0xf41b4 ldr r0, [pc, #0x3c]
 *   @0xf41b8 add r0, pc, r0
 *   @0xf41bc bx lr
 *   @0xf41c0 eoreq r3, r4, r12, lsl #12
 *   @0xf41c4 eoreq r3, r4, r0, lsl r6
 *   @0xf41c8 eoreq r3, r4, r4, lsl r6
 *   @0xf41cc eoreq r3, r4, r0, lsl r6
 *   @0xf41d0 eoreq r3, r4, r12, lsl #12
 *   @0xf41d4 eoreq r3, r4, r4, lsl #12
 *   @0xf41d8 eoreq r3, r4, r0, lsl #12
 *   @0xf41dc eoreq r3, r4, r0, lsl #12
 *   @0xf41e0 .word 0x002435fc
 *   @0xf41e4 .word 0x002435f8
 *   @0xf41e8 .word 0x002435f4
 *   @0xf41ec .word 0x002435f4
 *   @0xf41f0 .word 0x002435f8
 *   @0xf41f4 .word 0x002435fc
 *   @0xf41f8 eoreq r2, r4, r12, lsr lr
 *
 * ══ §47/91 CDS_Map::Find  0x2034e4  size 320  80 条（0x2034e4..0x203624）
 * @func 0x2034e4 0x203624  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CalcCRC(char const*, int)×2 / CalcCRC_string(char const*) / CDS_Map::Find(RValue*)+0xe0 / YYCompareVal(RValue const&, RValue const&, double) / CDS_Map::Find(RValue*)+0x11c / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x3×1 / 0x8×1 / 0x8c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2034e4 ldr r3, [r1, #0xc]
 *   @0x2034e8 push {r4, r5, r6, lr}
 *   @0x2034ec bic r3, r3, #-16777216
 *   @0x2034f0 cmp r3, #6
 *   @0x2034f4 sub sp, sp, #8
 *   @0x2034f8 mov r6, r1
 *   @0x2034fc mov r4, r0
 *   @0x203500 beq 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c>
 *   @0x203504 bgt 0x203538 <_ZN7CDS_Map4FindEP6RValue+0x54>
 *   @0x203508 cmp r3, #4
 *   @0x20350c bgt 0x203550 <_ZN7CDS_Map4FindEP6RValue+0x6c>
 *   @0x203510 cmp r3, #2
 *   @0x203514 bge 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c>
 *   @0x203518 cmp r3, #1
 *   @0x20351c bne 0x2035d0 <_ZN7CDS_Map4FindEP6RValue+0xec>
 *   @0x203520 ldr r0, [r1]
 *   @0x203524 cmp r0, #0
 *   @0x203528 ldrne r0, [r0]
 *   @0x20352c bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x203530 mov r5, r0
 *   @0x203534 b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70>
 *   @0x203538 cmp r3, #11
 *   @0x20353c beq 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c>
 *   @0x203540 ble 0x2035c4 <_ZN7CDS_Map4FindEP6RValue+0xe0>
 *   @0x203544 mvn r2, #-16777216
 *   @0x203548 cmp r3, r2
 *   @0x20354c bne 0x2035d0 <_ZN7CDS_Map4FindEP6RValue+0xec>
 *   @0x203550 mov r5, #0
 *   @0x203554 ldr r3, [r4]
 *   @0x203558 ldr r2, [r3, #0x4]
 *   @0x20355c ldr r3, [r3]
 *   @0x203560 and r2, r5, r2
 *   @0x203564 ldr r4, [r3, r2, lsl #3]
 *   @0x203568 cmp r4, #0
 *   @0x20356c bne 0x203580 <_ZN7CDS_Map4FindEP6RValue+0x9c>
 *   @0x203570 b 0x2035b8 <_ZN7CDS_Map4FindEP6RValue+0xd4>
 *   @0x203574 ldr r4, [r4, #0x4]
 *   @0x203578 cmp r4, #0
 *   @0x20357c beq 0x2035b8 <_ZN7CDS_Map4FindEP6RValue+0xd4>
 *   @0x203580 ldr r3, [r4, #0x8]
 *   @0x203584 cmp r3, r5
 *   @0x203588 bne 0x203574 <_ZN7CDS_Map4FindEP6RValue+0x90>
 *   @0x20358c ldr r3, [pc, #0x8c]
 *   @0x203590 mov r1, r6
 *   @0x203594 ldr r0, [r4, #0xc]
 *   @0x203598 ldr r3, [pc, r3]
 *   @0x20359c ldrd r2, r3, [r3]
 *   @0x2035a0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x2035a4 cmp r0, #0
 *   @0x2035a8 bne 0x203574 <_ZN7CDS_Map4FindEP6RValue+0x90>
 *   @0x2035ac ldr r0, [r4, #0xc]
 *   @0x2035b0 add sp, sp, #8
 *   @0x2035b4 pop {r4, r5, r6, pc}
 *   @0x2035b8 mov r0, #0
 *   @0x2035bc add sp, sp, #8
 *   @0x2035c0 pop {r4, r5, r6, pc}
 *   @0x2035c4 sub r2, r3, #8
 *   @0x2035c8 cmp r2, #1
 *   @0x2035cc bls 0x203600 <_ZN7CDS_Map4FindEP6RValue+0x11c>
 *   @0x2035d0 cmp r3, #0
 *   @0x2035d4 bne 0x203614 <_ZN7CDS_Map4FindEP6RValue+0x130>
 *   @0x2035d8 ldm r6, {r0, r1}
 *   @0x2035dc mov r2, r0
 *   @0x2035e0 add r0, sp, #8
 *   @0x2035e4 mov r3, r1
 *   @0x2035e8 mov r1, #8
 *   @0x2035ec strd r2, r3, [r0, #-8]!
 *   @0x2035f0 mov r0, sp
 *   @0x2035f4 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x2035f8 mov r5, r0
 *   @0x2035fc b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70>
 *   @0x203600 mov r0, r6
 *   @0x203604 mov r1, #8
 *   @0x203608 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20360c mov r5, r0
 *   @0x203610 b 0x203554 <_ZN7CDS_Map4FindEP6RValue+0x70>
 *   @0x203614 mov r0, r6
 *   @0x203618 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x20361c b 0x2035dc <_ZN7CDS_Map4FindEP6RValue+0xf8>
 *   @0x203620 andseq sp, lr, r12, ror #27
 *
 * ══ §48/91 diff_D2A  0x23d828  size 320  80 条（0x23d828..0x23d968）
 * @func 0x23d828 0x23d968  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Balloc_D2A×2 / cmp_D2A / diff_D2A+0xf8
 * 字段偏移 top8: 0x4×6 / 0x10×4 / 0xc×4 / 0x-4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d828 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23d82c sub sp, sp, #28
 *   @0x23d830 mov r5, r0
 *   @0x23d834 mov r4, r1
 *   @0x23d838 bl 0x23d7c8 <cmp_D2A>
 *   @0x23d83c subs r8, r0, #0
 *   @0x23d840 beq 0x23d94c <diff_D2A+0x124>
 *   @0x23d844 movlt r3, r5
 *   @0x23d848 movlt r5, r4
 *   @0x23d84c ldr r0, [r5, #0x4]
 *   @0x23d850 movlt r4, r3
 *   @0x23d854 movge r11, #0
 *   @0x23d858 movlt r11, #1
 *   @0x23d85c bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d860 ldr r3, [r4, #0x10]
 *   @0x23d864 ldr r8, [r5, #0x10]
 *   @0x23d868 add r1, r4, #20
 *   @0x23d86c strd r6, r7, [sp, #16]
 *   @0x23d870 mov r4, #0
 *   @0x23d874 add r3, r1, r3, lsl #2
 *   @0x23d878 mov r6, r3
 *   @0x23d87c str r0, [sp, #0xc]
 *   @0x23d880 add r0, r5, #20
 *   @0x23d884 ldr r2, [sp, #0xc]
 *   @0x23d888 add r9, r0, r8, lsl #2
 *   @0x23d88c mov r5, #0
 *   @0x23d890 add r12, r2, #20
 *   @0x23d894 str r11, [r2, #0xc]
 *   @0x23d898 ldr r3, [r1], #4
 *   @0x23d89c mov r11, #0
 *   @0x23d8a0 ldr r2, [r0], #4
 *   @0x23d8a4 subs r2, r2, r3
 *   @0x23d8a8 sbc r3, r2, r2
 *   @0x23d8ac subs r2, r2, r4
 *   @0x23d8b0 sbc r3, r3, r5
 *   @0x23d8b4 cmp r6, r1
 *   @0x23d8b8 mov r4, #1
 *   @0x23d8bc mov r5, #0
 *   @0x23d8c0 str r2, [r12], #4
 *   @0x23d8c4 and r4, r4, r3
 *   @0x23d8c8 and r5, r5, r11
 *   @0x23d8cc bhi 0x23d898 <diff_D2A+0x70>
 *   @0x23d8d0 cmp r9, r0
 *   @0x23d8d4 mov r10, r12
 *   @0x23d8d8 mov r1, r0
 *   @0x23d8dc bls 0x23d920 <diff_D2A+0xf8>
 *   @0x23d8e0 ldr r11, [r0], #4
 *   @0x23d8e4 mov r7, #0
 *   @0x23d8e8 rsbs r2, r4, r11
 *   @0x23d8ec rsc r3, r5, #0
 *   @0x23d8f0 cmp r9, r0
 *   @0x23d8f4 mov r4, #1
 *   @0x23d8f8 mov r5, #0
 *   @0x23d8fc str r2, [r12], #4
 *   @0x23d900 and r4, r4, r3
 *   @0x23d904 and r5, r5, r7
 *   @0x23d908 bhi 0x23d8e0 <diff_D2A+0xb8>
 *   @0x23d90c mvn r12, r1
 *   @0x23d910 add r12, r12, r9
 *   @0x23d914 bic r12, r12, #3
 *   @0x23d918 add r12, r12, #4
 *   @0x23d91c add r12, r10, r12
 *   @0x23d920 cmp r2, #0
 *   @0x23d924 sub r12, r12, #4
 *   @0x23d928 bne 0x23d93c <diff_D2A+0x114>
 *   @0x23d92c ldr r3, [r12, #-0x4]!
 *   @0x23d930 sub r8, r8, #1
 *   @0x23d934 cmp r3, #0
 *   @0x23d938 beq 0x23d92c <diff_D2A+0x104>
 *   @0x23d93c ldr r0, [sp, #0xc]
 *   @0x23d940 str r8, [r0, #0x10]
 *   @0x23d944 add sp, sp, #28
 *   @0x23d948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23d94c bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d950 mov r2, #1
 *   @0x23d954 mov r3, r0
 *   @0x23d958 str r8, [r0, #0x14]
 *   @0x23d95c str r2, [r3, #0x10]
 *   @0x23d960 add sp, sp, #28
 *   @0x23d964 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §49/91 JS_SetupBuiltinProperty  0x23ffac  size 320  80 条（0x23ffac..0x2400ec）
 * @func 0x23ffac 0x2400ec  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×6 / JS_SetupBuiltinAccessorFunction(bool (*)(CInstance*, int, RValue*), int)×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x4×6 / 0xc×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ffac push {r3, r4, r5, r6, r7, lr}
 *   @0x23ffb0 mov r2, #0
 *   @0x23ffb4 mov r6, r0
 *   @0x23ffb8 mov r5, r1
 *   @0x23ffbc mov r0, #2
 *   @0x23ffc0 mvn r1, #-16777216
 *   @0x23ffc4 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x23ffc8 cmp r6, #0
 *   @0x23ffcc mov r3, #2
 *   @0x23ffd0 mov r4, r0
 *   @0x23ffd4 str r3, [r0, #0x48]
 *   @0x23ffd8 beq 0x240024 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x78>
 *   @0x23ffdc ldr r7, [r0, #0x4]
 *   @0x23ffe0 cmp r7, #0
 *   @0x23ffe4 beq 0x2400bc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x110>
 *   @0x23ffe8 mov r1, #0
 *   @0x23ffec mov r0, r6
 *   @0x23fff0 bl 0x23ff10 <_Z31JS_SetupBuiltinAccessorFunctionPFbP9CInstanceiP6RValueEi>
 *   @0x23fff4 str r0, [r7]
 *   @0x23fff8 ldr r1, [r4, #0x4]
 *   @0x23fffc cmp r1, #0
 *   @0x240000 beq 0x2400cc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x120>
 *   @0x240004 ldr r1, [r1]
 *   @0x240008 mov r0, r4
 *   @0x24000c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240010 ldr r1, [r4, #0x4]
 *   @0x240014 cmp r1, #0
 *   @0x240018 beq 0x2400dc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x130>
 *   @0x24001c mov r3, #11
 *   @0x240020 str r3, [r1, #0xc]
 *   @0x240024 cmp r5, #0
 *   @0x240028 beq 0x240080 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xd4>
 *   @0x24002c ldr r0, [r4, #0x4]
 *   @0x240030 cmp r0, #0
 *   @0x240034 beq 0x240088 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xdc>
 *   @0x240038 add r6, r0, #16
 *   @0x24003c mov r0, r5
 *   @0x240040 mov r1, #1
 *   @0x240044 bl 0x23ff10 <_Z31JS_SetupBuiltinAccessorFunctionPFbP9CInstanceiP6RValueEi>
 *   @0x240048 str r0, [r6]
 *   @0x24004c ldr r0, [r4, #0x4]
 *   @0x240050 cmp r0, #0
 *   @0x240054 beq 0x24009c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xf0>
 *   @0x240058 add r0, r0, #16
 *   @0x24005c ldr r1, [r0]
 *   @0x240060 mov r0, r4
 *   @0x240064 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240068 ldr r0, [r4, #0x4]
 *   @0x24006c cmp r0, #0
 *   @0x240070 beq 0x2400ac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x100>
 *   @0x240074 add r0, r0, #16
 *   @0x240078 mov r3, #11
 *   @0x24007c str r3, [r0, #0xc]
 *   @0x240080 mov r0, r4
 *   @0x240084 pop {r3, r4, r5, r6, r7, pc}
 *   @0x240088 mov r0, r4
 *   @0x24008c mov r1, #1
 *   @0x240090 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240094 mov r6, r0
 *   @0x240098 b 0x24003c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x90>
 *   @0x24009c mov r0, r4
 *   @0x2400a0 mov r1, #1
 *   @0x2400a4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2400a8 b 0x24005c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xb0>
 *   @0x2400ac mov r0, r4
 *   @0x2400b0 mov r1, #1
 *   @0x2400b4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2400b8 b 0x240078 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xcc>
 *   @0x2400bc mov r1, r7
 *   @0x2400c0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2400c4 mov r7, r0
 *   @0x2400c8 b 0x23ffe8 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x3c>
 *   @0x2400cc mov r0, r4
 *   @0x2400d0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2400d4 mov r1, r0
 *   @0x2400d8 b 0x240004 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x58>
 *   @0x2400dc mov r0, r4
 *   @0x2400e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2400e4 mov r1, r0
 *   @0x2400e8 b 0x24001c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x70>
 *
 * ══ §50/91 CSkeletonSprite::DrawRegion  0xbde18  size 316  79 条（0xbde18..0xbdf54）
 * @func 0xbde18 0xbdf54  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spRegionAttachment_computeWorldVertices / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x4×4 / 0x18×3 / 0x1c×3 / 0x40×2 / 0x48×2 / 0x8×2 / 0xc×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbde18 push {r4, r5, lr}
 *   @0xbde1c sub sp, sp, #36
 *   @0xbde20 ldr r4, [r1, #0x18]
 *   @0xbde24 mov r5, r2
 *   @0xbde28 ldr r1, [r1, #0x4]
 *   @0xbde2c mov r2, sp
 *   @0xbde30 mov r0, r4
 *   @0xbde34 bl 0x289174 <spRegionAttachment_computeWorldVertices>
 *   @0xbde38 ldr r12, [r4, #0x40]
 *   @0xbde3c ldr r1, [pc, #0x108]
 *   @0xbde40 mov r2, #24
 *   @0xbde44 mov r3, #6
 *   @0xbde48 mov r0, #4
 *   @0xbde4c ldr r12, [r12, #0x48]
 *   @0xbde50 ldr r1, [pc, r1]
 *   @0xbde54 ldr r1, [r1, #0x4]
 *   @0xbde58 ldr r12, [r12, #0x1c]
 *   @0xbde5c ldr r1, [r1, r12, lsl #2]
 *   @0xbde60 ldr r1, [r1]
 *   @0xbde64 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xbde68 ldr r2, [sp, #0x8]
 *   @0xbde6c str r2, [r0]
 *   @0xbde70 ldr r1, [sp, #0xc]
 *   @0xbde74 str r2, [r0, #0x78]
 *   @0xbde78 str r5, [r0, #0x6c]
 *   @0xbde7c str r1, [r0, #0x4]
 *   @0xbde80 ldr r3, [sp, #0x10]
 *   @0xbde84 str r1, [r0, #0x7c]
 *   @0xbde88 str r5, [r0, #0x3c]
 *   @0xbde8c str r3, [r0, #0x18]
 *   @0xbde90 ldr r3, [sp, #0x14]
 *   @0xbde94 str r5, [r0, #0x54]
 *   @0xbde98 str r3, [r0, #0x1c]
 *   @0xbde9c ldr r2, [sp, #0x18]
 *   @0xbdea0 ldr r3, [pc, #0xa8]
 *   @0xbdea4 ldr r1, [sp, #0x4]
 *   @0xbdea8 str r2, [r0, #0x30]
 *   @0xbdeac ldr r3, [pc, r3]
 *   @0xbdeb0 str r2, [r0, #0x48]
 *   @0xbdeb4 ldr r2, [sp]
 *   @0xbdeb8 ldr r3, [r3]
 *   @0xbdebc str r1, [r0, #0x64]
 *   @0xbdec0 str r2, [r0, #0x60]
 *   @0xbdec4 ldr r2, [sp, #0x1c]
 *   @0xbdec8 str r3, [r0, #0x68]
 *   @0xbdecc str r3, [r0, #0x38]
 *   @0xbded0 str r3, [r0, #0x50]
 *   @0xbded4 str r3, [r0, #0x20]
 *   @0xbded8 str r3, [r0, #0x8]
 *   @0xbdedc str r3, [r0, #0x80]
 *   @0xbdee0 str r2, [r0, #0x4c]
 *   @0xbdee4 str r2, [r0, #0x34]
 *   @0xbdee8 str r5, [r0, #0x24]
 *   @0xbdeec str r5, [r0, #0xc]
 *   @0xbdef0 str r5, [r0, #0x84]
 *   @0xbdef4 ldr r3, [r4, #0x84]
 *   @0xbdef8 str r3, [r0, #0x88]
 *   @0xbdefc str r3, [r0, #0x10]
 *   @0xbdf00 ldr r3, [r4, #0x88]
 *   @0xbdf04 str r3, [r0, #0x8c]
 *   @0xbdf08 str r3, [r0, #0x14]
 *   @0xbdf0c ldr r3, [r4, #0x8c]
 *   @0xbdf10 str r3, [r0, #0x28]
 *   @0xbdf14 ldr r3, [r4, #0x90]
 *   @0xbdf18 str r3, [r0, #0x2c]
 *   @0xbdf1c ldr r3, [r4, #0x94]
 *   @0xbdf20 str r3, [r0, #0x58]
 *   @0xbdf24 str r3, [r0, #0x40]
 *   @0xbdf28 ldr r3, [r4, #0x98]
 *   @0xbdf2c str r3, [r0, #0x5c]
 *   @0xbdf30 str r3, [r0, #0x44]
 *   @0xbdf34 ldr r3, [r4, #0x7c]
 *   @0xbdf38 str r3, [r0, #0x70]
 *   @0xbdf3c ldr r3, [r4, #0x80]
 *   @0xbdf40 str r3, [r0, #0x74]
 *   @0xbdf44 add sp, sp, #36
 *   @0xbdf48 pop {r4, r5, pc}
 *   @0xbdf4c eorseq pc, r2, r12, asr #21
 *   @0xbdf50 eorseq pc, r2, r4, ror r10
 *
 * ══ §51/91 Achievement_PostAchievement  0x1614b4  size 316  79 条（0x1614b4..0x1615f0）
 * @func 0x1614b4 0x1615f0  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1614c8→0x3eb70c, 0x161540→0x756d44, 0x161544→0x756d34, 0x16159c→0x756d44, 0x1615a0→0x756d38
 * 调用序列: getJNIEnv×4 / Threaded_UpdateComsState(eComsState)×3 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)×2
 * 字段偏移 top8: 0x29c×2 / 0x9c×2 / 0x110×1 / 0x10c×1 / 0x104×1 / 0xc×1 / 0x40×1 / 0x44×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1614b4 push {r4, r5, r6, lr}
 *   @0x1614b8 vpush {d8}
 *   @0x1614bc mov r5, r0
 *   @0x1614c0 ldr r4, [pc, #0x110]
 *   @0x1614c4 mov r6, r1
 *   @0x1614c8 ldr r3, [pc, #0x10c]
 *   @0x1614cc sub sp, sp, #8
 *   @0x1614d0 add r4, pc, r4
 *   @0x1614d4 ldr r1, [pc, #0x104]
 *   @0x1614d8 vmov s16, r2
 *   @0x1614dc mov r2, r6
 *   @0x1614e0 ldr r3, [r4, r3]
 *   @0x1614e4 add r1, pc, r1
 *   @0x1614e8 ldr r0, [r3]
 *   @0x1614ec ldr r12, [r0]
 *   @0x1614f0 ldr r3, [r12, #0xc]
 *   @0x1614f4 blx r3
 *   @0x1614f8 cmp r5, #2
 *   @0x1614fc beq 0x16157c <_Z27Achievement_PostAchievement10eCacheTypePKcf+0xc8>
 *   @0x161500 cmp r5, #3
 *   @0x161504 beq 0x161520 <_Z27Achievement_PostAchievement10eCacheTypePKcf+0x6c>
 *   @0x161508 mov r0, #3
 *   @0x16150c bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState>
 *   @0x161510 mov r0, #0
 *   @0x161514 add sp, sp, #8
 *   @0x161518 vpop {d8}
 *   @0x16151c pop {r4, r5, r6, pc}
 *   @0x161520 bl 0x290274 <getJNIEnv>
 *   @0x161524 mov r1, r6
 *   @0x161528 ldr r3, [r0]
 *   @0x16152c ldr r3, [r3, #0x29c]
 *   @0x161530 blx r3
 *   @0x161534 mov r5, r0
 *   @0x161538 bl 0x290274 <getJNIEnv>
 *   @0x16153c vcvt.f64.f32 d7, s16
 *   @0x161540 ldr r1, [pc, #0x9c]
 *   @0x161544 ldr r2, [pc, #0x9c]
 *   @0x161548 mov r3, r5
 *   @0x16154c ldr r1, [r4, r1]
 *   @0x161550 ldr r2, [r4, r2]
 *   @0x161554 ldr r1, [r1]
 *   @0x161558 ldr r2, [r2]
 *   @0x16155c vstr d7, [sp]
 *   @0x161560 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161564 mov r0, #2
 *   @0x161568 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState>
 *   @0x16156c mov r0, #1
 *   @0x161570 add sp, sp, #8
 *   @0x161574 vpop {d8}
 *   @0x161578 pop {r4, r5, r6, pc}
 *   @0x16157c bl 0x290274 <getJNIEnv>
 *   @0x161580 mov r1, r6
 *   @0x161584 ldr r3, [r0]
 *   @0x161588 ldr r3, [r3, #0x29c]
 *   @0x16158c blx r3
 *   @0x161590 mov r6, r0
 *   @0x161594 bl 0x290274 <getJNIEnv>
 *   @0x161598 vcvt.f64.f32 d7, s16
 *   @0x16159c ldr r1, [pc, #0x40]
 *   @0x1615a0 ldr r2, [pc, #0x44]
 *   @0x1615a4 mov r3, r6
 *   @0x1615a8 ldr r1, [r4, r1]
 *   @0x1615ac ldr r2, [r4, r2]
 *   @0x1615b0 ldr r1, [r1]
 *   @0x1615b4 ldr r2, [r2]
 *   @0x1615b8 vstr d7, [sp]
 *   @0x1615bc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x1615c0 mov r0, r5
 *   @0x1615c4 bl 0x159a88 <_Z24Threaded_UpdateComsState10eComsState>
 *   @0x1615c8 mov r0, #1
 *   @0x1615cc add sp, sp, #8
 *   @0x1615d0 vpop {d8}
 *   @0x1615d4 pop {r4, r5, r6, pc}
 *   @0x1615d8 eoreq r0, r9, r0, lsl #15
 *   @0x1615dc .word 0xffffbac4
 *   @0x1615e0 andseq r8, lr, r0, lsr r6
 *   @0x1615e4 .word 0xffffbd54
 *   @0x1615e8 .word 0xffffe308
 *   @0x1615ec .word 0xffffe30c
 *
 * ══ §52/91 addPageToGlobalPageList  0x27bcf8  size 316  79 条（0x27bcf8..0x27be34）
 * @func 0x27bcf8 0x27be34  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27bcfc→0x7566a4, 0x27bd0c→0x75669c, 0x27bd30→0x7566a0, 0x27bdd8→0x7566a0
 * 调用序列: addPageToGlobalPageList(void*, void*)+0x110 / addPageToGlobalPageList(void*, void*)+0x118 / 0xb6694 / 0xb6c28
 * 字段偏移 top8: 0x124×2 / 0x118×1 / 0xf8×1 / 0x4×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27bcf8 ldr r2, [pc, #0x124]
 *   @0x27bcfc ldr r3, [pc, #0x124]
 *   @0x27bd00 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x27bd04 add r2, pc, r2
 *   @0x27bd08 mov r9, r1
 *   @0x27bd0c ldr r1, [pc, #0x118]
 *   @0x27bd10 ldr r8, [r2, r3]
 *   @0x27bd14 mov r6, r0
 *   @0x27bd18 ldr r0, [r2, r1]
 *   @0x27bd1c ldr r4, [r8]
 *   @0x27bd20 ldr r3, [r0]
 *   @0x27bd24 add r1, r4, #1
 *   @0x27bd28 cmp r1, r3
 *   @0x27bd2c bge 0x27bdd4 <_Z23addPageToGlobalPageListPvS_+0xdc>
 *   @0x27bd30 ldr r3, [pc, #0xf8]
 *   @0x27bd34 ldr r10, [r2, r3]
 *   @0x27bd38 ldr r1, [r10]
 *   @0x27bd3c cmp r4, #0
 *   @0x27bd40 ble 0x27be08 <_Z23addPageToGlobalPageListPvS_+0x110>
 *   @0x27bd44 ldr r3, [r1]
 *   @0x27bd48 cmp r6, r3
 *   @0x27bd4c blo 0x27be10 <_Z23addPageToGlobalPageListPvS_+0x118>
 *   @0x27bd50 cmp r3, #0
 *   @0x27bd54 beq 0x27be08 <_Z23addPageToGlobalPageListPvS_+0x110>
 *   @0x27bd58 add r2, r1, #8
 *   @0x27bd5c mov r3, #0
 *   @0x27bd60 b 0x27bd7c <_Z23addPageToGlobalPageListPvS_+0x84>
 *   @0x27bd64 ldr r12, [r2]
 *   @0x27bd68 add r2, r2, #8
 *   @0x27bd6c cmp r12, r6
 *   @0x27bd70 bhi 0x27bda8 <_Z23addPageToGlobalPageListPvS_+0xb0>
 *   @0x27bd74 cmp r12, #0
 *   @0x27bd78 beq 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c>
 *   @0x27bd7c add r3, r3, #1
 *   @0x27bd80 mov r5, r2
 *   @0x27bd84 cmp r3, r4
 *   @0x27bd88 lsl r7, r3, #3
 *   @0x27bd8c bne 0x27bd64 <_Z23addPageToGlobalPageListPvS_+0x6c>
 *   @0x27bd90 add r5, r1, r4, lsl #3
 *   @0x27bd94 str r6, [r5]
 *   @0x27bd98 add r4, r4, #1
 *   @0x27bd9c str r9, [r5, #0x4]
 *   @0x27bda0 str r4, [r8]
 *   @0x27bda4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x27bda8 add r0, r3, #1
 *   @0x27bdac lsl r0, r0, #3
 *   @0x27bdb0 rsb r2, r3, r4
 *   @0x27bdb4 add r0, r1, r0
 *   @0x27bdb8 mov r1, r5
 *   @0x27bdbc lsl r2, r2, #3
 *   @0x27bdc0 bl 0xb6694 <memmove@plt>
 *   @0x27bdc4 ldr r5, [r10]
 *   @0x27bdc8 ldr r4, [r8]
 *   @0x27bdcc add r5, r5, r7
 *   @0x27bdd0 b 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c>
 *   @0x27bdd4 add r3, r3, r3, lsl #1
 *   @0x27bdd8 ldr r12, [pc, #0x50]
 *   @0x27bddc add r3, r3, r3, lsr #31
 *   @0x27bde0 asr r1, r3, #1
 *   @0x27bde4 str r1, [r0]
 *   @0x27bde8 ldr r10, [r2, r12]
 *   @0x27bdec lsl r1, r1, #3
 *   @0x27bdf0 ldr r0, [r10]
 *   @0x27bdf4 bl 0xb6c28 <realloc@plt>
 *   @0x27bdf8 ldr r4, [r8]
 *   @0x27bdfc mov r1, r0
 *   @0x27be00 str r0, [r10]
 *   @0x27be04 b 0x27bd3c <_Z23addPageToGlobalPageListPvS_+0x44>
 *   @0x27be08 mov r5, r1
 *   @0x27be0c b 0x27bd94 <_Z23addPageToGlobalPageListPvS_+0x9c>
 *   @0x27be10 mov r7, #0
 *   @0x27be14 mov r5, r1
 *   @0x27be18 mov r3, r7
 *   @0x27be1c mov r0, #8
 *   @0x27be20 b 0x27bdb0 <_Z23addPageToGlobalPageListPvS_+0xb8>
 *   @0x27be24 andseq r5, r7, r12, asr #30
 *   @0x27be28 .word 0xfffffbd8
 *   @0x27be2c .word 0xfffffbdc
 *   @0x27be30 .word 0xfffffbe0
 *
 * ══ §53/91 FreeSocket  0x299244  size 312  78 条（0x299244..0x29937c）
 * @func 0x299244 0x29937c  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::DeleteSocket(yySocket*)×2 / operator delete(void*)×2 / yyServer::~yyServer() / yySocket::Close() / yySocket::~yySocket()
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x1×2 / 0x124×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299244 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x299248 lsl r8, r0, #1
 *   @0x29924c ldr r6, [pc, #0x124]
 *   @0x299250 add r3, r8, r0
 *   @0x299254 mov r7, r0
 *   @0x299258 ldr r6, [pc, r6]
 *   @0x29925c lsl r3, r3, #2
 *   @0x299260 add r9, r6, r3
 *   @0x299264 ldrb r2, [r6, r3]
 *   @0x299268 cmp r2, #0
 *   @0x29926c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x299270 ldr r11, [r9, #0x8]
 *   @0x299274 mov r4, #0
 *   @0x299278 strb r4, [r6, r3]
 *   @0x29927c cmp r11, r4
 *   @0x299280 strb r4, [r9, #0x1]
 *   @0x299284 beq 0x2992e8 <_Z10FreeSocketi+0xa4>
 *   @0x299288 mov r10, r4
 *   @0x29928c b 0x29929c <_Z10FreeSocketi+0x58>
 *   @0x299290 add r4, r4, #12
 *   @0x299294 cmp r4, #768
 *   @0x299298 beq 0x2992d0 <_Z10FreeSocketi+0x8c>
 *   @0x29929c add r5, r6, r4
 *   @0x2992a0 ldrb r3, [r5, #0x1]
 *   @0x2992a4 cmp r3, #0
 *   @0x2992a8 beq 0x299290 <_Z10FreeSocketi+0x4c>
 *   @0x2992ac mov r0, r11
 *   @0x2992b0 ldr r1, [r5, #0x4]
 *   @0x2992b4 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket>
 *   @0x2992b8 add r4, r4, #12
 *   @0x2992bc cmp r0, #0
 *   @0x2992c0 strbne r10, [r5, #0x1]
 *   @0x2992c4 cmp r4, #768
 *   @0x2992c8 ldr r11, [r9, #0x8]
 *   @0x2992cc bne 0x29929c <_Z10FreeSocketi+0x58>
 *   @0x2992d0 cmp r11, #0
 *   @0x2992d4 beq 0x2992e8 <_Z10FreeSocketi+0xa4>
 *   @0x2992d8 mov r0, r11
 *   @0x2992dc bl 0x297184 <_ZN8yyServerD2Ev>
 *   @0x2992e0 mov r0, r11
 *   @0x2992e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2992e8 add r9, r8, r7
 *   @0x2992ec add r9, r6, r9, lsl #2
 *   @0x2992f0 ldr r2, [r9, #0x4]
 *   @0x2992f4 cmp r2, #0
 *   @0x2992f8 beq 0x299360 <_Z10FreeSocketi+0x11c>
 *   @0x2992fc add r5, r6, #768
 *   @0x299300 mov r4, r6
 *   @0x299304 ldrb r3, [r4]
 *   @0x299308 cmp r3, #0
 *   @0x29930c beq 0x299328 <_Z10FreeSocketi+0xe4>
 *   @0x299310 ldr r0, [r4, #0x8]
 *   @0x299314 mov r1, r2
 *   @0x299318 cmp r0, #0
 *   @0x29931c beq 0x299328 <_Z10FreeSocketi+0xe4>
 *   @0x299320 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket>
 *   @0x299324 ldr r2, [r9, #0x4]
 *   @0x299328 add r4, r4, #12
 *   @0x29932c cmp r4, r5
 *   @0x299330 bne 0x299304 <_Z10FreeSocketi+0xc0>
 *   @0x299334 mov r0, r2
 *   @0x299338 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x29933c add r2, r8, r7
 *   @0x299340 mov r3, #3
 *   @0x299344 add r2, r6, r2, lsl #2
 *   @0x299348 ldr r4, [r2, #0x4]
 *   @0x29934c str r3, [r4, #0x28]
 *   @0x299350 mov r0, r4
 *   @0x299354 bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x299358 mov r0, r4
 *   @0x29935c bl 0x27d1d0 <_ZdlPv>
 *   @0x299360 add r7, r8, r7
 *   @0x299364 mov r3, #0
 *   @0x299368 add r6, r6, r7, lsl #2
 *   @0x29936c str r3, [r6, #0x4]
 *   @0x299370 str r3, [r6, #0x8]
 *   @0x299374 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x299378 andseq r8, r5, r12, asr #14
 *
 * ══ §54/91 RelySendReliable  0x299c68  size 312  78 条（0x299c68..0x299da0）
 * @func 0x299c68 0x299da0  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)×3 / GetIBuffer(int)×2 / CreateBuffer(int, eBuffer_Format, int) / CalcCRC(char const*, int) / RelySendData(int, char const*, int, int, int) / RelyAddPacket(int, char const*, int, unsigned int, int)
 * 字段偏移 top8: 0xc×4 / 0x48×2 / 0x18×2 / 0x14×2 / 0x1c×2 / 0x8×2 / 0x10×2 / 0x124×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299c68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x299c6c sub sp, sp, #36
 *   @0x299c70 ldr r12, [pc, #0x124]
 *   @0x299c74 mov r7, r0
 *   @0x299c78 mov r0, r3
 *   @0x299c7c ldr r3, [sp, #0x48]
 *   @0x299c80 ldr r12, [pc, r12]
 *   @0x299c84 mov r5, #1
 *   @0x299c88 add r11, r3, #12
 *   @0x299c8c mov r10, r1
 *   @0x299c90 ldr r3, [r12]
 *   @0x299c94 mov r6, #0
 *   @0x299c98 mov r9, r2
 *   @0x299c9c str r6, [sp, #0x18]
 *   @0x299ca0 add r2, r3, r5
 *   @0x299ca4 str r6, [sp, #0x14]
 *   @0x299ca8 str r3, [sp, #0x1c]
 *   @0x299cac str r2, [r12]
 *   @0x299cb0 strb r5, [sp, #0x18]
 *   @0x299cb4 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x299cb8 mov r2, r5
 *   @0x299cbc mov r1, #3
 *   @0x299cc0 str r0, [sp, #0xc]
 *   @0x299cc4 mov r0, r11
 *   @0x299cc8 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0x299ccc mov r8, r0
 *   @0x299cd0 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x299cd4 add r12, sp, #20
 *   @0x299cd8 mov r2, r5
 *   @0x299cdc mov r3, #12
 *   @0x299ce0 str r12, [sp, #0x8]
 *   @0x299ce4 mov r1, r12
 *   @0x299ce8 mov r4, r0
 *   @0x299cec bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x299cf0 ldr r3, [sp, #0xc]
 *   @0x299cf4 mov r2, r5
 *   @0x299cf8 mov r0, r4
 *   @0x299cfc ldr r1, [r3, #0xc]
 *   @0x299d00 ldr r3, [sp, #0x48]
 *   @0x299d04 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x299d08 ldr r0, [r4, #0xc]
 *   @0x299d0c ldr r1, [r4, #0x10]
 *   @0x299d10 add r0, r0, #4
 *   @0x299d14 sub r1, r1, #4
 *   @0x299d18 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x299d1c ldr r3, [r4]
 *   @0x299d20 mov r1, r6
 *   @0x299d24 mov r2, r6
 *   @0x299d28 ldr r3, [r3, #0x10]
 *   @0x299d2c str r0, [sp, #0x14]
 *   @0x299d30 mov r0, r4
 *   @0x299d34 blx r3
 *   @0x299d38 ldr r12, [sp, #0x8]
 *   @0x299d3c mov r2, r5
 *   @0x299d40 mov r0, r4
 *   @0x299d44 mov r3, #12
 *   @0x299d48 mov r1, r12
 *   @0x299d4c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x299d50 mov r1, r10
 *   @0x299d54 mov r2, r9
 *   @0x299d58 mov r3, r8
 *   @0x299d5c str r11, [sp]
 *   @0x299d60 mov r0, r7
 *   @0x299d64 bl 0x299ff8 <_Z12RelySendDataiPKciii>
 *   @0x299d68 ldr r12, [sp, #0x1c]
 *   @0x299d6c mov r1, r10
 *   @0x299d70 mov r2, r9
 *   @0x299d74 mov r3, r8
 *   @0x299d78 str r12, [sp]
 *   @0x299d7c mov r4, r0
 *   @0x299d80 mov r0, r7
 *   @0x299d84 bl 0x299afc <_Z13RelyAddPacketiPKciji>
 *   @0x299d88 cmp r4, #12
 *   @0x299d8c subhi r0, r4, #12
 *   @0x299d90 mvnls r0, #3
 *   @0x299d94 add sp, sp, #36
 *   @0x299d98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x299d9c andseq r7, r5, r12, ror sp
 *
 * ══ §55/91 DebuggerPingIP  0x29cdec  size 312  78 条（0x29cdec..0x29cf24）
 * @func 0x29cdec 0x29cf24  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29ce38→0x3eb708, 0x29ce40→0x757e6c, 0x29ce48→0x757e68, 0x29ce88→0x75790c, 0x29ced0→0x3eb70c
 * 调用序列: Timing_Time / DebuggerPingIP()+0x4c / yySocket::SendUDPPacket(char*, int, unsigned char*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x44×2 / 0xf8×1 / 0xe4×1 / 0xc0×1 / 0xbc×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cdec push {r4, r5, r6, r7, lr}
 *   @0x29cdf0 sub sp, sp, #12
 *   @0x29cdf4 bl 0x215148 <Timing_Time>
 *   @0x29cdf8 ldr r7, [pc, #0xf8]
 *   @0x29cdfc mov r12, #544
 *   @0x29ce00 movw r4, #0xa120
 *   @0x29ce04 add r7, pc, r7
 *   @0x29ce08 movt r4, #0x7
 *   @0x29ce0c mov r5, #0
 *   @0x29ce10 ldr r6, [pc, #0xe4]
 *   @0x29ce14 ldrd r2, r3, [r7, r12]
 *   @0x29ce18 add r6, pc, r6
 *   @0x29ce1c adds r2, r2, r4
 *   @0x29ce20 adc r3, r3, r5
 *   @0x29ce24 cmp r2, r0
 *   @0x29ce28 sbcs r4, r3, r1
 *   @0x29ce2c blt 0x29ce38 <_Z14DebuggerPingIPv+0x4c>
 *   @0x29ce30 add sp, sp, #12
 *   @0x29ce34 pop {r4, r5, r6, r7, pc}
 *   @0x29ce38 ldr r3, [pc, #0xc0]
 *   @0x29ce3c strd r0, r1, [r7, r12]
 *   @0x29ce40 ldr r1, [pc, #0xbc]
 *   @0x29ce44 ldr r2, [r6, r3]
 *   @0x29ce48 ldr r3, [pc, #0xb8]
 *   @0x29ce4c ldr r5, [r6, r1]
 *   @0x29ce50 ldr r0, [r2]
 *   @0x29ce54 ldr r4, [r6, r3]
 *   @0x29ce58 ldr r1, [pc, #0xac]
 *   @0x29ce5c ldr r12, [r0]
 *   @0x29ce60 ldr r3, [r4]
 *   @0x29ce64 add r1, pc, r1
 *   @0x29ce68 ldr r2, [r5]
 *   @0x29ce6c ldr r12, [r12, #0xc]
 *   @0x29ce70 blx r12
 *   @0x29ce74 ldr r3, [pc, #0x94]
 *   @0x29ce78 add r3, pc, r3
 *   @0x29ce7c ldr r3, [r3, #0x4]
 *   @0x29ce80 cmp r3, #63
 *   @0x29ce84 bhi 0x29ce30 <_Z14DebuggerPingIPv+0x44>
 *   @0x29ce88 ldr r2, [pc, #0x84]
 *   @0x29ce8c add r3, r3, r3, lsl #1
 *   @0x29ce90 lsl r3, r3, #2
 *   @0x29ce94 ldr r2, [r6, r2]
 *   @0x29ce98 ldrb r1, [r2, r3]
 *   @0x29ce9c cmp r1, #0
 *   @0x29cea0 beq 0x29ce30 <_Z14DebuggerPingIPv+0x44>
 *   @0x29cea4 add r3, r2, r3
 *   @0x29cea8 ldr r1, [r5]
 *   @0x29ceac ldr r2, [r4]
 *   @0x29ceb0 mov r12, #8
 *   @0x29ceb4 ldr r0, [r3, #0x4]
 *   @0x29ceb8 mov r3, #1
 *   @0x29cebc str r3, [sp, #0x4]
 *   @0x29cec0 ldr r3, [pc, #0x50]
 *   @0x29cec4 str r12, [sp]
 *   @0x29cec8 add r3, pc, r3
 *   @0x29cecc bl 0x296a38 <_ZN8yySocket13SendUDPPacketEPciPhib>
 *   @0x29ced0 ldr r3, [pc, #0x44]
 *   @0x29ced4 ldr r1, [pc, #0x44]
 *   @0x29ced8 ldr r3, [r6, r3]
 *   @0x29cedc add r1, pc, r1
 *   @0x29cee0 mov r2, r0
 *   @0x29cee4 ldr r0, [r3]
 *   @0x29cee8 ldr r3, [r0]
 *   @0x29ceec ldr r3, [r3, #0xc]
 *   @0x29cef0 blx r3
 *   @0x29cef4 b 0x29ce30 <_Z14DebuggerPingIPv+0x44>
 *   @0x29cef8 subeq r10, r11, r4, lsl #28
 *   @0x29cefc andseq r4, r5, r8, lsr lr
 *   @0x29cf00 .word 0xffffbcf0
 *   @0x29cf04 .word 0xfffff0a4
 *   @0x29cf08 .word 0xfffff0a8
 *   @0x29cf0c andeq r12, r11, r12, lsl #25
 *   @0x29cf10 mulseq r5, r8, r9
 *   @0x29cf14 .word 0xfffffd54
 *   @0x29cf18 andeq r12, r11, r12, lsr r12
 *   @0x29cf1c .word 0xffffbac4
 *   @0x29cf20 andeq r12, r11, r4, lsr r12
 *
 * ══ §56/91 CProfiler::Push  0x2a0738  size 312  78 条（0x2a0738..0x2a0870）
 * @func 0x2a0738 0x2a0870  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time×2 / CProfiler::FindOrCreateNode(int, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×7 / 0x4×6 / 0x70×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0738 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a073c sub sp, sp, #24
 *   @0x2a0740 mov r6, r0
 *   @0x2a0744 mov r9, r1
 *   @0x2a0748 mov r8, r2
 *   @0x2a074c bl 0x215148 <Timing_Time>
 *   @0x2a0750 mov r2, r8
 *   @0x2a0754 mov r4, r0
 *   @0x2a0758 mov r5, r1
 *   @0x2a075c mov r0, r6
 *   @0x2a0760 mov r1, r9
 *   @0x2a0764 bl 0x2a04f4 <_ZN9CProfiler16FindOrCreateNodeEii>
 *   @0x2a0768 ldr r7, [r6, #0x8]
 *   @0x2a076c str r9, [sp]
 *   @0x2a0770 str r8, [sp, #0x4]
 *   @0x2a0774 ldr r3, [r7, #0x4]
 *   @0x2a0778 ldr r2, [r7, #0x8]
 *   @0x2a077c cmp r3, r2
 *   @0x2a0780 str r0, [r6, #0x70]
 *   @0x2a0784 str r0, [sp, #0x8]
 *   @0x2a0788 beq 0x2a0818 <_ZN9CProfiler4PushEii+0xe0>
 *   @0x2a078c ldr r9, [r7]
 *   @0x2a0790 mov r12, sp
 *   @0x2a0794 add r8, r3, r3, lsl #1
 *   @0x2a0798 ldm r12!, {r0, r1, r2, r3}
 *   @0x2a079c lsl r8, r8, #3
 *   @0x2a07a0 add lr, r9, r8
 *   @0x2a07a4 str r0, [r9, r8]
 *   @0x2a07a8 str r1, [lr, #0x4]
 *   @0x2a07ac ldm r12!, {r0, r1}
 *   @0x2a07b0 str r2, [lr, #0x8]
 *   @0x2a07b4 str r3, [lr, #0xc]
 *   @0x2a07b8 str r0, [lr, #0x10]
 *   @0x2a07bc str r1, [lr, #0x14]
 *   @0x2a07c0 ldr r2, [r6, #0x8]
 *   @0x2a07c4 ldr r3, [r7, #0x4]
 *   @0x2a07c8 add r3, r3, #1
 *   @0x2a07cc str r3, [r7, #0x4]
 *   @0x2a07d0 ldm r2, {r2, r3}
 *   @0x2a07d4 cmp r3, #0
 *   @0x2a07d8 addgt r3, r3, r3, lsl #1
 *   @0x2a07dc movle r7, #0
 *   @0x2a07e0 addgt r7, r2, r3, lsl #3
 *   @0x2a07e4 subgt r7, r7, #24
 *   @0x2a07e8 bl 0x215148 <Timing_Time>
 *   @0x2a07ec ldrd r2, r3, [r6]
 *   @0x2a07f0 subs r2, r2, r4
 *   @0x2a07f4 sbc r3, r3, r5
 *   @0x2a07f8 rsbs r4, r2, #0
 *   @0x2a07fc rsc r5, r3, #0
 *   @0x2a0800 adds r0, r0, r2
 *   @0x2a0804 adc r1, r1, r3
 *   @0x2a0808 strd r0, r1, [r6]
 *   @0x2a080c strd r4, r5, [r7, #16]
 *   @0x2a0810 add sp, sp, #24
 *   @0x2a0814 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a0818 add r8, r3, #10
 *   @0x2a081c ldr r1, [pc, #0x48]
 *   @0x2a0820 mov r3, #1
 *   @0x2a0824 mov r2, #40
 *   @0x2a0828 add r0, r8, r8, lsl #1
 *   @0x2a082c add r1, pc, r1
 *   @0x2a0830 lsl r0, r0, #3
 *   @0x2a0834 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a0838 ldr r2, [r7, #0x8]
 *   @0x2a083c ldr r1, [r7]
 *   @0x2a0840 add r2, r2, r2, lsl #1
 *   @0x2a0844 lsl r2, r2, #3
 *   @0x2a0848 mov r10, r0
 *   @0x2a084c bl 0xb65bc <memcpy@plt>
 *   @0x2a0850 ldr r0, [r7]
 *   @0x2a0854 mov r9, r10
 *   @0x2a0858 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a085c ldr r3, [r7, #0x4]
 *   @0x2a0860 str r8, [r7, #0x8]
 *   @0x2a0864 str r10, [r7]
 *   @0x2a0868 b 0x2a0790 <_ZN9CProfiler4PushEii+0x58>
 *   @0x2a086c ldrdeq r4, r5, [r11], -r8
 *
 * ══ §57/91 Code_Constant_Add  0xf1a10  size 308  77 条（0xf1a10..0xf1b44）
 * @func 0xf1a10 0xf1b44  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / FREE_RValue__Pre(RValue*)×2 / Trim(char const*&, char const*) / CheckConstName(char const*) / 0xb65c8 / ShowMessage(char const*) / AddConstant(char const*, RValue*) / 0xb65d4
 * 字段偏移 top8: 0x10×4 / 0x4×2 / 0x414×2 / 0xc×2 / 0x11c×1 / 0x8×1 / 0xd0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1a10 push {r4, r5, r6, r7, lr}
 *   @0xf1a14 sub sp, sp, #1040
 *   @0xf1a18 ldr r4, [pc, #0x11c]
 *   @0xf1a1c sub sp, sp, #12
 *   @0xf1a20 mov r1, r0
 *   @0xf1a24 mov r3, #0
 *   @0xf1a28 ldr r4, [pc, r4]
 *   @0xf1a2c mov r0, sp
 *   @0xf1a30 str r3, [sp, #0x10]
 *   @0xf1a34 add r6, sp, #4
 *   @0xf1a38 ldr r12, [r4]
 *   @0xf1a3c str r3, [sp]
 *   @0xf1a40 str r3, [sp, #0x4]
 *   @0xf1a44 str r12, [sp, #0x414]
 *   @0xf1a48 str r3, [sp, #0x8]
 *   @0xf1a4c str r3, [sp, #0xc]
 *   @0xf1a50 bl 0xc4728 <_Z4TrimRPKcS0_>
 *   @0xf1a54 ldr r0, [sp]
 *   @0xf1a58 bl 0xedc04 <_Z14CheckConstNamePKc>
 *   @0xf1a5c subs r5, r0, #0
 *   @0xf1a60 bne 0xf1ad4 <_Z17Code_Constant_AddPKcS0_+0xc4>
 *   @0xf1a64 add r7, sp, #20
 *   @0xf1a68 ldr r2, [pc, #0xd0]
 *   @0xf1a6c mov r1, #1024
 *   @0xf1a70 ldr r3, [sp]
 *   @0xf1a74 add r2, pc, r2
 *   @0xf1a78 mov r0, r7
 *   @0xf1a7c bl 0xb65c8 <snprintf@plt>
 *   @0xf1a80 mov r0, r7
 *   @0xf1a84 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0xf1a88 ldr r0, [sp]
 *   @0xf1a8c cmp r0, #0
 *   @0xf1a90 beq 0xf1a9c <_Z17Code_Constant_AddPKcS0_+0x8c>
 *   @0xf1a94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1a98 str r5, [sp]
 *   @0xf1a9c ldr r3, [sp, #0x10]
 *   @0xf1aa0 sub r3, r3, #1
 *   @0xf1aa4 bic r3, r3, #-16777216
 *   @0xf1aa8 bic r3, r3, #3
 *   @0xf1aac cmp r3, #0
 *   @0xf1ab0 beq 0xf1b20 <_Z17Code_Constant_AddPKcS0_+0x110>
 *   @0xf1ab4 ldr r2, [sp, #0x414]
 *   @0xf1ab8 mov r0, r5
 *   @0xf1abc ldr r3, [r4]
 *   @0xf1ac0 cmp r2, r3
 *   @0xf1ac4 bne 0xf1b38 <_Z17Code_Constant_AddPKcS0_+0x128>
 *   @0xf1ac8 add sp, sp, #1040
 *   @0xf1acc add sp, sp, #12
 *   @0xf1ad0 pop {r4, r5, r6, r7, pc}
 *   @0xf1ad4 ldr r0, [sp]
 *   @0xf1ad8 mov r1, r6
 *   @0xf1adc bl 0xedd00 <_Z11AddConstantPKcP6RValue>
 *   @0xf1ae0 ldr r3, [sp, #0x10]
 *   @0xf1ae4 sub r3, r3, #1
 *   @0xf1ae8 bic r3, r3, #-16777216
 *   @0xf1aec bic r3, r3, #3
 *   @0xf1af0 cmp r3, #0
 *   @0xf1af4 beq 0xf1b2c <_Z17Code_Constant_AddPKcS0_+0x11c>
 *   @0xf1af8 ldr r0, [sp]
 *   @0xf1afc mov r3, #0
 *   @0xf1b00 mov r2, #5
 *   @0xf1b04 str r3, [sp, #0xc]
 *   @0xf1b08 cmp r0, r3
 *   @0xf1b0c str r3, [sp, #0x4]
 *   @0xf1b10 str r2, [sp, #0x10]
 *   @0xf1b14 beq 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4>
 *   @0xf1b18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf1b1c b 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4>
 *   @0xf1b20 mov r0, r6
 *   @0xf1b24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf1b28 b 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4>
 *   @0xf1b2c mov r0, r6
 *   @0xf1b30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xf1b34 b 0xf1af8 <_Z17Code_Constant_AddPKcS0_+0xe8>
 *   @0xf1b38 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf1b3c eoreq r11, pc, r8, lsr #30
 *   @0xf1b40 mlaeq r4, r0, r4, r5
 *
 * ══ §58/91 CLayerManager::GetNewSpriteElement  0x1c0f00  size 308  77 条（0x1c0f00..0x1c1034）
 * @func 0x1c0f00 0x1c1034  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewSpriteElement()+0xec / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewSpriteElement()+0x34
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0x120×1 / 0x104×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0f00 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c0f04 ldr r4, [pc, #0x120]
 *   @0x1c0f08 ldr r4, [pc, r4]
 *   @0x1c0f0c ldr r8, [r4, #0x8]
 *   @0x1c0f10 cmp r8, #0
 *   @0x1c0f14 bne 0x1c0ff4 <_ZN13CLayerManager19GetNewSpriteElementEv+0xf4>
 *   @0x1c0f18 ldr r3, [r4, #0x10]
 *   @0x1c0f1c cmp r3, #0
 *   @0x1c0f20 ble 0x1c0fec <_ZN13CLayerManager19GetNewSpriteElementEv+0xec>
 *   @0x1c0f24 ldr r7, [pc, #0x104]
 *   @0x1c0f28 mov r5, r8
 *   @0x1c0f2c mov r6, #0
 *   @0x1c0f30 add r7, pc, r7
 *   @0x1c0f34 mov r1, r7
 *   @0x1c0f38 mov r2, #63
 *   @0x1c0f3c mov r0, #72
 *   @0x1c0f40 mov r3, #1
 *   @0x1c0f44 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c0f48 mvn r2, #0
 *   @0x1c0f4c mov r1, #4
 *   @0x1c0f50 cmp r0, #0
 *   @0x1c0f54 beq 0x1c0fa4 <_ZN13CLayerManager19GetNewSpriteElementEv+0xa4>
 *   @0x1c0f58 mov r3, #1065353216
 *   @0x1c0f5c strb r5, [r0, #0x8]
 *   @0x1c0f60 str r5, [r0, #0xc]
 *   @0x1c0f64 str r6, [r0, #0x20]
 *   @0x1c0f68 str r5, [r0, #0x10]
 *   @0x1c0f6c str r6, [r0, #0x34]
 *   @0x1c0f70 str r5, [r0, #0x14]
 *   @0x1c0f74 str r6, [r0, #0x40]
 *   @0x1c0f78 str r5, [r0, #0x18]
 *   @0x1c0f7c str r6, [r0, #0x44]
 *   @0x1c0f80 str r2, [r0, #0x4]
 *   @0x1c0f84 str r2, [r0, #0x1c]
 *   @0x1c0f88 str r5, [r0, #0x28]
 *   @0x1c0f8c str r2, [r0, #0x38]
 *   @0x1c0f90 str r1, [r0]
 *   @0x1c0f94 str r3, [r0, #0x24]
 *   @0x1c0f98 str r3, [r0, #0x2c]
 *   @0x1c0f9c str r3, [r0, #0x30]
 *   @0x1c0fa0 str r3, [r0, #0x3c]
 *   @0x1c0fa4 ldr r3, [r4]
 *   @0x1c0fa8 add r8, r8, #1
 *   @0x1c0fac ldr r2, [r4, #0x8]
 *   @0x1c0fb0 cmp r3, #0
 *   @0x1c0fb4 streq r0, [r4, #0x4]
 *   @0x1c0fb8 strne r0, [r3, #0x18]
 *   @0x1c0fbc add r2, r2, #1
 *   @0x1c0fc0 streq r3, [r0, #0x18]
 *   @0x1c0fc4 streq r3, [r0, #0x14]
 *   @0x1c0fc8 strne r3, [r0, #0x14]
 *   @0x1c0fcc ldr r3, [r4, #0x10]
 *   @0x1c0fd0 streq r0, [r4]
 *   @0x1c0fd4 strne r0, [r4]
 *   @0x1c0fd8 strne r5, [r0, #0x18]
 *   @0x1c0fdc cmp r8, r3
 *   @0x1c0fe0 str r2, [r4, #0x8]
 *   @0x1c0fe4 blt 0x1c0f34 <_ZN13CLayerManager19GetNewSpriteElementEv+0x34>
 *   @0x1c0fe8 ldr r8, [r4, #0x8]
 *   @0x1c0fec lsl r3, r3, #1
 *   @0x1c0ff0 str r3, [r4, #0x10]
 *   @0x1c0ff4 ldr r0, [r4]
 *   @0x1c0ff8 sub r8, r8, #1
 *   @0x1c0ffc str r8, [r4, #0x8]
 *   @0x1c1000 ldr r3, [r0, #0x18]
 *   @0x1c1004 ldr r2, [r0, #0x14]
 *   @0x1c1008 cmp r3, #0
 *   @0x1c100c strne r2, [r3, #0x14]
 *   @0x1c1010 ldrne r2, [r0, #0x14]
 *   @0x1c1014 ldrne r3, [r0, #0x18]
 *   @0x1c1018 streq r2, [r4]
 *   @0x1c101c cmp r2, #0
 *   @0x1c1020 streq r3, [r4, #0x4]
 *   @0x1c1024 strne r3, [r2, #0x18]
 *   @0x1c1028 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c102c eoreq pc, r2, r4, ror #18
 *   @0x1c1030 andseq r12, r8, r4, ror #14
 *
 * ══ §59/91 spRegionAttachment_updateOffset  0x289040  size 308  77 条（0x289040..0x289174）
 * @func 0x289040 0x289174  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67e4 / 0xb67d8
 * 字段偏移 top8: 无
 * VFP 指令 72 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289040 vldr s7, [r0, #84]
 *   @0x289044 vldr s11, [r0, #88]
 *   @0x289048 vcvt.f32.s32 s14, s7
 *   @0x28904c vldr s10, [r0, #44]
 *   @0x289050 vldr s9, [r0, #40]
 *   @0x289054 vldr s12, [r0, #28]
 *   @0x289058 vldr s13, [r0, #32]
 *   @0x28905c vldr s7, [r0, #68]
 *   @0x289060 push {r4, lr}
 *   @0x289064 vpush {d8, d9, d10, d11}
 *   @0x289068 vldr s8, [pc, #256]
 *   @0x28906c vldr s16, [r0, #36]
 *   @0x289070 mov r4, r0
 *   @0x289074 vcvt.f32.s32 s15, s11
 *   @0x289078 vdiv.f32 s14, s9, s14
 *   @0x28907c vdiv.f32 s15, s10, s15
 *   @0x289080 vmul.f32 s14, s14, s12
 *   @0x289084 vmul.f32 s15, s15, s13
 *   @0x289088 vmov.f32 s11, #5.000000e-01
 *   @0x28908c vcvt.f32.s32 s19, s7
 *   @0x289090 vldr s7, [r0, #72]
 *   @0x289094 vcvt.f32.s32 s18, s7
 *   @0x289098 vmul.f32 s19, s19, s14
 *   @0x28909c vnmul.f32 s9, s9, s11
 *   @0x2890a0 vmul.f32 s18, s18, s15
 *   @0x2890a4 vnmul.f32 s11, s10, s11
 *   @0x2890a8 vmla.f32 s19, s12, s9
 *   @0x2890ac vldr s9, [r4, #80]
 *   @0x2890b0 vmla.f32 s18, s13, s11
 *   @0x2890b4 vmul.f32 s16, s16, s8
 *   @0x2890b8 vldr s8, [r0, #76]
 *   @0x2890bc vcvt.f64.f32 d8, s16
 *   @0x2890c0 vcvt.f32.s32 s12, s8
 *   @0x2890c4 vmov r0, r1, d8
 *   @0x2890c8 vcvt.f32.s32 s13, s9
 *   @0x2890cc vmov.f32 s22, s19
 *   @0x2890d0 vmov.f32 s21, s18
 *   @0x2890d4 vmla.f32 s22, s12, s14
 *   @0x2890d8 vmla.f32 s21, s13, s15
 *   @0x2890dc bl 0xb67e4 <cos@plt>
 *   @0x2890e0 vmov d7, r0, r1
 *   @0x2890e4 vmov r0, r1, d8
 *   @0x2890e8 vcvt.f32.f64 s20, d7
 *   @0x2890ec bl 0xb67d8 <sin@plt>
 *   @0x2890f0 vldr s12, [r4, #20]
 *   @0x2890f4 vldr s13, [r4, #24]
 *   @0x2890f8 vmov.f32 s11, s12
 *   @0x2890fc vmla.f32 s12, s22, s20
 *   @0x289100 vmla.f32 s11, s19, s20
 *   @0x289104 vmov d4, r0, r1
 *   @0x289108 vcvt.f32.f64 s15, d4
 *   @0x28910c vmov.f32 s14, s13
 *   @0x289110 vmul.f32 s22, s22, s15
 *   @0x289114 vmla.f32 s14, s18, s20
 *   @0x289118 vmul.f32 s19, s19, s15
 *   @0x28911c vmul.f32 s18, s18, s15
 *   @0x289120 vmul.f32 s15, s21, s15
 *   @0x289124 vmla.f32 s13, s21, s20
 *   @0x289128 vsub.f32 s10, s11, s18
 *   @0x28912c vsub.f32 s11, s11, s15
 *   @0x289130 vstr s10, [r4, #92]
 *   @0x289134 vsub.f32 s15, s12, s15
 *   @0x289138 vstr s11, [r4, #100]
 *   @0x28913c vsub.f32 s18, s12, s18
 *   @0x289140 vstr s15, [r4, #108]
 *   @0x289144 vadd.f32 s15, s14, s19
 *   @0x289148 vstr s18, [r4, #116]
 *   @0x28914c vadd.f32 s19, s13, s19
 *   @0x289150 vstr s15, [r4, #96]
 *   @0x289154 vadd.f32 s13, s13, s22
 *   @0x289158 vstr s19, [r4, #104]
 *   @0x28915c vadd.f32 s22, s14, s22
 *   @0x289160 vstr s13, [r4, #112]
 *   @0x289164 vstr s22, [r4, #120]
 *   @0x289168 vpop {d8, d9, d10, d11}
 *   @0x28916c pop {r4, pc}
 *   @0x289170 vstmialo lr, {s30, s31}
 *
 * ══ §60/91 IAP_ActivateM  0x16173c  size 304  76 条（0x16173c..0x16186c）
 * @func 0x16173c 0x16186c  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×8 / IAP_ActivateM()+0xdc / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×2 / 0x5c×2 / 0x40×2 / 0x10c×1 / 0xfc×1 / 0x18×1 / 0xe4×1 / 0x2b0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16173c push {r3, r4, r5, r6, r7, lr}
 *   @0x161740 bl 0x290274 <getJNIEnv>
 *   @0x161744 ldr r6, [pc, #0x10c]
 *   @0x161748 ldr r6, [pc, r6]
 *   @0x16174c ldr r7, [r6]
 *   @0x161750 mov r4, r0
 *   @0x161754 bl 0x290274 <getJNIEnv>
 *   @0x161758 ldr r1, [pc, #0xfc]
 *   @0x16175c add r1, pc, r1
 *   @0x161760 ldr r3, [r0]
 *   @0x161764 ldr r3, [r3, #0x18]
 *   @0x161768 blx r3
 *   @0x16176c mov r5, r0
 *   @0x161770 bl 0x290274 <getJNIEnv>
 *   @0x161774 ldr r1, [pc, #0xe4]
 *   @0x161778 add r1, pc, r1
 *   @0x16177c ldr r3, [r0]
 *   @0x161780 ldr r3, [r3, #0x29c]
 *   @0x161784 blx r3
 *   @0x161788 ldr r12, [r4]
 *   @0x16178c mov r1, r7
 *   @0x161790 mov r2, r5
 *   @0x161794 ldr r12, [r12, #0x2b0]
 *   @0x161798 mov r3, r0
 *   @0x16179c mov r0, r4
 *   @0x1617a0 blx r12
 *   @0x1617a4 ldr r3, [r6]
 *   @0x1617a8 cmp r3, #0
 *   @0x1617ac mov r7, r0
 *   @0x1617b0 ble 0x161818 <_Z13IAP_ActivateMv+0xdc>
 *   @0x1617b4 mov r4, #0
 *   @0x1617b8 bl 0x290274 <getJNIEnv>
 *   @0x1617bc ldr r3, [r6, #0x4]
 *   @0x1617c0 ldr r3, [r3, r4, lsl #2]
 *   @0x1617c4 ldr r1, [r3]
 *   @0x1617c8 ldr r3, [r0]
 *   @0x1617cc ldr r2, [r3, #0x29c]
 *   @0x1617d0 blx r2
 *   @0x1617d4 mov r5, r0
 *   @0x1617d8 bl 0x290274 <getJNIEnv>
 *   @0x1617dc mov r2, r4
 *   @0x1617e0 mov r3, r5
 *   @0x1617e4 mov r1, r7
 *   @0x1617e8 add r4, r4, #1
 *   @0x1617ec ldr r12, [r0]
 *   @0x1617f0 ldr r12, [r12, #0x2b8]
 *   @0x1617f4 blx r12
 *   @0x1617f8 bl 0x290274 <getJNIEnv>
 *   @0x1617fc mov r1, r5
 *   @0x161800 ldr r3, [r0]
 *   @0x161804 ldr r2, [r3, #0x5c]
 *   @0x161808 blx r2
 *   @0x16180c ldr r3, [r6]
 *   @0x161810 cmp r3, r4
 *   @0x161814 bgt 0x1617b8 <_Z13IAP_ActivateMv+0x7c>
 *   @0x161818 bl 0x290274 <getJNIEnv>
 *   @0x16181c ldr r1, [pc, #0x40]
 *   @0x161820 ldr r2, [pc, #0x40]
 *   @0x161824 mov r3, r7
 *   @0x161828 ldr r1, [pc, r1]
 *   @0x16182c ldr r2, [pc, r2]
 *   @0x161830 ldr r1, [r1]
 *   @0x161834 ldr r2, [r2]
 *   @0x161838 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x16183c bl 0x290274 <getJNIEnv>
 *   @0x161840 mov r1, r7
 *   @0x161844 ldr r3, [r0]
 *   @0x161848 ldr r3, [r3, #0x5c]
 *   @0x16184c blx r3
 *   @0x161850 mov r0, #1
 *   @0x161854 pop {r3, r4, r5, r6, r7, pc}
 *   @0x161858 eoreq lr, r8, r12, lsl #7
 *   @0x16185c andseq r8, lr, r4
 *   @0x161860 ldrheq sp, [r12], -lr
 *   @0x161864 eoreq r12, r8, r12, ror r1
 *   @0x161868 eoreq lr, r8, r4, lsr r7
 *
 * ══ §61/91 CPhysicsWorld::Update  0x2382b0  size 304  76 条（0x2382b0..0x2383e0）
 * @func 0x2382b0 0x2383e0  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2382c4→0x757e7c, 0x238368→0x757e80, 0x238378→0x757e80
 * 调用序列: CPhysicsWorld::Update(int, bool)+0x4c / CPhysicsWorld::StorePreviousPositions() / b2World::ClearForces() / CPhysicsWorld::TransferPhysicalPositions() / CPhysicsWorld::DispatchContactEvents() / CProfiler::Push(int, int) / b2World::Step(float, int, int) / CPhysicsWorld::UpdatePaths()
 * 字段偏移 top8: 0x10×2 / 0x5c×2 / 0x110×1 / 0x10c×1 / 0x64×1 / 0x6c×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2382b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2382b4 vpush {d8, d9}
 *   @0x2382b8 mov r4, r0
 *   @0x2382bc ldr r5, [pc, #0x110]
 *   @0x2382c0 mov r7, r1
 *   @0x2382c4 ldr r3, [pc, #0x10c]
 *   @0x2382c8 mov r8, r2
 *   @0x2382cc add r5, pc, r5
 *   @0x2382d0 ldr r6, [r5, r3]
 *   @0x2382d4 ldrb r3, [r6]
 *   @0x2382d8 cmp r3, #0
 *   @0x2382dc bne 0x238378 <_ZN13CPhysicsWorld6UpdateEib+0xc8>
 *   @0x2382e0 cmp r7, #0
 *   @0x2382e4 ble 0x2382fc <_ZN13CPhysicsWorld6UpdateEib+0x4c>
 *   @0x2382e8 cmp r8, #0
 *   @0x2382ec bne 0x2383c8 <_ZN13CPhysicsWorld6UpdateEib+0x118>
 *   @0x2382f0 ldrb r3, [r4, #0x64]
 *   @0x2382f4 cmp r3, #0
 *   @0x2382f8 beq 0x238310 <_ZN13CPhysicsWorld6UpdateEib+0x60>
 *   @0x2382fc ldrb r3, [r6]
 *   @0x238300 cmp r3, #0
 *   @0x238304 bne 0x238364 <_ZN13CPhysicsWorld6UpdateEib+0xb4>
 *   @0x238308 vpop {d8, d9}
 *   @0x23830c pop {r4, r5, r6, r7, r8, pc}
 *   @0x238310 mov r0, r4
 *   @0x238314 vmov.f32 s17, #1.000000e+00
 *   @0x238318 bl 0x238070 <_ZN13CPhysicsWorld22StorePreviousPositionsEv>
 *   @0x23831c vmov s15, r7
 *   @0x238320 vcvt.f32.s32 s16, s15
 *   @0x238324 vldr s15, [r4, #88]
 *   @0x238328 vcvt.f32.s32 s18, s15
 *   @0x23832c vdiv.f32 s16, s18, s16
 *   @0x238330 vcmpe.f32 s16, #0
 *   @0x238334 vdiv.f32 s18, s17, s18
 *   @0x238338 vmrs APSR_nzcv, fpscr
 *   @0x23833c bgt 0x238390 <_ZN13CPhysicsWorld6UpdateEib+0xe0>
 *   @0x238340 ldr r0, [r4, #0x10]
 *   @0x238344 bl 0x2ca658 <_ZN7b2World11ClearForcesEv>
 *   @0x238348 mov r0, r4
 *   @0x23834c bl 0x23812c <_ZN13CPhysicsWorld25TransferPhysicalPositionsEv>
 *   @0x238350 mov r0, r4
 *   @0x238354 bl 0x238208 <_ZN13CPhysicsWorld21DispatchContactEventsEv>
 *   @0x238358 ldrb r3, [r6]
 *   @0x23835c cmp r3, #0
 *   @0x238360 beq 0x238308 <_ZN13CPhysicsWorld6UpdateEib+0x58>
 *   @0x238364 vpop {d8, d9}
 *   @0x238368 ldr r3, [pc, #0x6c]
 *   @0x23836c ldr r0, [r5, r3]
 *   @0x238370 pop {r4, r5, r6, r7, r8, lr}
 *   @0x238374 b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x238378 ldr r3, [pc, #0x5c]
 *   @0x23837c mov r1, #6
 *   @0x238380 mov r2, r1
 *   @0x238384 ldr r0, [r5, r3]
 *   @0x238388 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x23838c b 0x2382e0 <_ZN13CPhysicsWorld6UpdateEib+0x30>
 *   @0x238390 vcmpe.f32 s16, s17
 *   @0x238394 ldr r2, [r4, #0x5c]
 *   @0x238398 ldr r0, [r4, #0x10]
 *   @0x23839c mov r3, r2
 *   @0x2383a0 vmrs APSR_nzcv, fpscr
 *   @0x2383a4 vmov.f32 s15, s18
 *   @0x2383a8 vmulle.f32 s15, s18, s16
 *   @0x2383ac vmov r1, s15
 *   @0x2383b0 bl 0x2ca68c <_ZN7b2World4StepEfii>
 *   @0x2383b4 vsub.f32 s16, s16, s17
 *   @0x2383b8 vcmpe.f32 s16, #0
 *   @0x2383bc vmrs APSR_nzcv, fpscr
 *   @0x2383c0 bgt 0x238390 <_ZN13CPhysicsWorld6UpdateEib+0xe0>
 *   @0x2383c4 b 0x238340 <_ZN13CPhysicsWorld6UpdateEib+0x90>
 *   @0x2383c8 mov r0, r4
 *   @0x2383cc bl 0x237f94 <_ZN13CPhysicsWorld11UpdatePathsEv>
 *   @0x2383d0 b 0x2382f0 <_ZN13CPhysicsWorld6UpdateEib+0x40>
 *   @0x2383d4 andseq r9, r11, r4, lsl #19
 *   @0x2383d8 .word 0xffffbf18
 *   @0x2383dc .word 0xffffbf1c
 *
 * ══ §62/91 spSkeleton_dispose  0x2894cc  size 304  76 条（0x2894cc..0x2895fc）
 * @func 0x2894cc 0x2895fc  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×8 / spSkeleton_dispose+0x3c / spBone_dispose / spSkeleton_dispose+0x70 / spSlot_dispose / spSkeleton_dispose+0xa4 / spIkConstraint_dispose / spSkeleton_dispose+0xe0
 * 字段偏移 top8: 0x2×5 / 0x4×2 / 0x8×2 / 0x10×2 / 0x14×2 / 0x1c×2 / 0x20×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2894cc push {r3, r4, r5, lr}
 *   @0x2894d0 mov r4, r0
 *   @0x2894d4 ldr r0, [r0, #0x68]
 *   @0x2894d8 bl 0x285c80 <_free>
 *   @0x2894dc ldr r3, [r4, #0x4]
 *   @0x2894e0 cmp r3, #0
 *   @0x2894e4 movgt r5, #0
 *   @0x2894e8 ble 0x289508 <spSkeleton_dispose+0x3c>
 *   @0x2894ec ldr r3, [r4, #0x8]
 *   @0x2894f0 ldr r0, [r3, r5, lsl #2]
 *   @0x2894f4 add r5, r5, #1
 *   @0x2894f8 bl 0x284efc <spBone_dispose>
 *   @0x2894fc ldr r3, [r4, #0x4]
 *   @0x289500 cmp r3, r5
 *   @0x289504 bgt 0x2894ec <spSkeleton_dispose+0x20>
 *   @0x289508 ldr r0, [r4, #0x8]
 *   @0x28950c bl 0x285c80 <_free>
 *   @0x289510 ldr r3, [r4, #0x10]
 *   @0x289514 cmp r3, #0
 *   @0x289518 movgt r5, #0
 *   @0x28951c ble 0x28953c <spSkeleton_dispose+0x70>
 *   @0x289520 ldr r3, [r4, #0x14]
 *   @0x289524 ldr r0, [r3, r5, lsl #2]
 *   @0x289528 add r5, r5, #1
 *   @0x28952c bl 0x28ee00 <spSlot_dispose>
 *   @0x289530 ldr r3, [r4, #0x10]
 *   @0x289534 cmp r3, r5
 *   @0x289538 bgt 0x289520 <spSkeleton_dispose+0x54>
 *   @0x28953c ldr r0, [r4, #0x14]
 *   @0x289540 bl 0x285c80 <_free>
 *   @0x289544 ldr r3, [r4, #0x1c]
 *   @0x289548 cmp r3, #0
 *   @0x28954c movgt r5, #0
 *   @0x289550 ble 0x289570 <spSkeleton_dispose+0xa4>
 *   @0x289554 ldr r3, [r4, #0x20]
 *   @0x289558 ldr r0, [r3, r5, lsl #2]
 *   @0x28955c add r5, r5, #1
 *   @0x289560 bl 0x285e2c <spIkConstraint_dispose>
 *   @0x289564 ldr r3, [r4, #0x1c]
 *   @0x289568 cmp r3, r5
 *   @0x28956c bgt 0x289554 <spSkeleton_dispose+0x88>
 *   @0x289570 ldr r0, [r4, #0x20]
 *   @0x289574 bl 0x285c80 <_free>
 *   @0x289578 ldr r0, [r4, #0x24]
 *   @0x28957c bl 0x285c80 <_free>
 *   @0x289580 ldr r3, [r4, #0x28]
 *   @0x289584 cmp r3, #0
 *   @0x289588 movgt r5, #0
 *   @0x28958c ble 0x2895ac <spSkeleton_dispose+0xe0>
 *   @0x289590 ldr r3, [r4, #0x2c]
 *   @0x289594 ldr r0, [r3, r5, lsl #2]
 *   @0x289598 add r5, r5, #1
 *   @0x28959c bl 0x28f0f4 <spTransformConstraint_dispose>
 *   @0x2895a0 ldr r3, [r4, #0x28]
 *   @0x2895a4 cmp r3, r5
 *   @0x2895a8 bgt 0x289590 <spSkeleton_dispose+0xc4>
 *   @0x2895ac ldr r0, [r4, #0x2c]
 *   @0x2895b0 bl 0x285c80 <_free>
 *   @0x2895b4 ldr r3, [r4, #0x30]
 *   @0x2895b8 cmp r3, #0
 *   @0x2895bc movgt r5, #0
 *   @0x2895c0 ble 0x2895e0 <spSkeleton_dispose+0x114>
 *   @0x2895c4 ldr r3, [r4, #0x34]
 *   @0x2895c8 ldr r0, [r3, r5, lsl #2]
 *   @0x2895cc add r5, r5, #1
 *   @0x2895d0 bl 0x287a70 <spPathConstraint_dispose>
 *   @0x2895d4 ldr r3, [r4, #0x30]
 *   @0x2895d8 cmp r3, r5
 *   @0x2895dc bgt 0x2895c4 <spSkeleton_dispose+0xf8>
 *   @0x2895e0 ldr r0, [r4, #0x34]
 *   @0x2895e4 bl 0x285c80 <_free>
 *   @0x2895e8 ldr r0, [r4, #0x18]
 *   @0x2895ec bl 0x285c80 <_free>
 *   @0x2895f0 mov r0, r4
 *   @0x2895f4 pop {r3, r4, r5, lr}
 *   @0x2895f8 b 0x285c80 <_free>
 *
 * ══ §63/91 b2Fixture::Synchronize  0x2c87cc  size 304  76 条（0x2c87cc..0x2c88fc）
 * @func 0x2c87cc 0x2c88fc  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Fixture::Synchronize(b2BroadPhase*, b2Transform const&, b2Transform const&)+0x128 / b2BroadPhase::MoveProxy(int, b2AABB const&, b2Vec2 const&)
 * 字段偏移 top8: 0x1c×4 / 0xc×2 / 0x18×2 / 0x14×2 / 0x4×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c87cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c87d0 mov r10, r1
 *   @0x2c87d4 ldr r1, [r0, #0x1c]
 *   @0x2c87d8 sub sp, sp, #52
 *   @0x2c87dc mov r5, r0
 *   @0x2c87e0 mov r8, r2
 *   @0x2c87e4 cmp r1, #0
 *   @0x2c87e8 mov r7, r3
 *   @0x2c87ec ble 0x2c88f4 <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_+0x128>
 *   @0x2c87f0 mov r6, #0
 *   @0x2c87f4 add r11, sp, #16
 *   @0x2c87f8 mov r9, r6
 *   @0x2c87fc add r3, sp, #32
 *   @0x2c8800 str r3, [sp]
 *   @0x2c8804 add r3, sp, #8
 *   @0x2c8808 str r3, [sp, #0x4]
 *   @0x2c880c ldr r0, [r5, #0xc]
 *   @0x2c8810 mov r1, r11
 *   @0x2c8814 ldr r4, [r5, #0x18]
 *   @0x2c8818 mov r2, r8
 *   @0x2c881c add r9, r9, #1
 *   @0x2c8820 ldr r12, [r0]
 *   @0x2c8824 add r4, r4, r6
 *   @0x2c8828 add r6, r6, #28
 *   @0x2c882c ldr r3, [r4, #0x14]
 *   @0x2c8830 ldr r12, [r12, #0x1c]
 *   @0x2c8834 blx r12
 *   @0x2c8838 ldr r0, [r5, #0xc]
 *   @0x2c883c ldr r3, [r4, #0x14]
 *   @0x2c8840 add r1, sp, #32
 *   @0x2c8844 mov r2, r7
 *   @0x2c8848 ldr r12, [r0]
 *   @0x2c884c ldr r12, [r12, #0x1c]
 *   @0x2c8850 blx r12
 *   @0x2c8854 vldr s12, [sp, #16]
 *   @0x2c8858 vldr s13, [sp, #32]
 *   @0x2c885c vcmpe.f32 s12, s13
 *   @0x2c8860 vldr s14, [sp, #20]
 *   @0x2c8864 vldr s15, [sp, #36]
 *   @0x2c8868 add r3, sp, #8
 *   @0x2c886c mov r2, r4
 *   @0x2c8870 mov r0, r10
 *   @0x2c8874 ldr r1, [r4, #0x18]
 *   @0x2c8878 vmrs APSR_nzcv, fpscr
 *   @0x2c887c vcmpe.f32 s14, s15
 *   @0x2c8880 vmovmi.f32 s13, s12
 *   @0x2c8884 vmrs APSR_nzcv, fpscr
 *   @0x2c8888 vstr s13, [r4]
 *   @0x2c888c vmovmi.f32 s15, s14
 *   @0x2c8890 vstr s15, [r4, #4]
 *   @0x2c8894 vldr s12, [sp, #24]
 *   @0x2c8898 vldr s13, [sp, #40]
 *   @0x2c889c vldr s14, [sp, #28]
 *   @0x2c88a0 vldr s15, [sp, #44]
 *   @0x2c88a4 vcmpe.f32 s12, s13
 *   @0x2c88a8 vmrs APSR_nzcv, fpscr
 *   @0x2c88ac vcmpe.f32 s14, s15
 *   @0x2c88b0 vmovgt.f32 s13, s12
 *   @0x2c88b4 vmrs APSR_nzcv, fpscr
 *   @0x2c88b8 vstr s13, [r4, #8]
 *   @0x2c88bc vmovgt.f32 s15, s14
 *   @0x2c88c0 vstr s15, [r4, #12]
 *   @0x2c88c4 vldr s12, [r7, #4]
 *   @0x2c88c8 vldr s14, [r8, #4]
 *   @0x2c88cc vldr s13, [r7]
 *   @0x2c88d0 vldr s15, [r8]
 *   @0x2c88d4 vsub.f32 s14, s12, s14
 *   @0x2c88d8 vsub.f32 s15, s13, s15
 *   @0x2c88dc vstr s14, [sp, #12]
 *   @0x2c88e0 vstr s15, [sp, #8]
 *   @0x2c88e4 bl 0x2dc8b8 <_ZN12b2BroadPhase9MoveProxyEiRK6b2AABBRK6b2Vec2>
 *   @0x2c88e8 ldr r3, [r5, #0x1c]
 *   @0x2c88ec cmp r3, r9
 *   @0x2c88f0 bgt 0x2c880c <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_+0x40>
 *   @0x2c88f4 add sp, sp, #52
 *   @0x2c88f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §64/91 REAL_RValue_Ex  0xd0e94  size 300  75 条（0xd0e94..0xd0fc0）
 * @func 0xd0e94 0xd0fc0  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2 / ARRAY_LVAL_RValue(YYRValue*, int) / __floatdidf
 * 字段偏移 top8: 0xc×2 / 0x58×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd0e94 ldr r1, [r0, #0xc]
 *   @0xd0e98 push {r3, lr}
 *   @0xd0e9c mov r3, r0
 *   @0xd0ea0 bic r1, r1, #-16777216
 *   @0xd0ea4 cmp r1, #13
 *   @0xd0ea8 addls pc, pc, r1, lsl #2
 *   @0xd0eac b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0eb0 b 0xd0f08 <_Z14REAL_RValue_ExPK6RValue+0x74>
 *   @0xd0eb4 b 0xd0f70 <_Z14REAL_RValue_ExPK6RValue+0xdc>
 *   @0xd0eb8 b 0xd0ee8 <_Z14REAL_RValue_ExPK6RValue+0x54>
 *   @0xd0ebc b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ec0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ec4 b 0xd0f18 <_Z14REAL_RValue_ExPK6RValue+0x84>
 *   @0xd0ec8 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ecc b 0xd0f38 <_Z14REAL_RValue_ExPK6RValue+0xa4>
 *   @0xd0ed0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ed4 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ed8 b 0xd0f24 <_Z14REAL_RValue_ExPK6RValue+0x90>
 *   @0xd0edc b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ee0 b 0xd0f4c <_Z14REAL_RValue_ExPK6RValue+0xb8>
 *   @0xd0ee4 b 0xd0f08 <_Z14REAL_RValue_ExPK6RValue+0x74>
 *   @0xd0ee8 mov r0, r3
 *   @0xd0eec mov r1, #0
 *   @0xd0ef0 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei>
 *   @0xd0ef4 ldr r1, [r0, #0xc]
 *   @0xd0ef8 mov r3, r0
 *   @0xd0efc bic r2, r1, #-16777216
 *   @0xd0f00 cmp r2, #0
 *   @0xd0f04 bne 0xd0ea0 <_Z14REAL_RValue_ExPK6RValue+0xc>
 *   @0xd0f08 ldm r3, {r2, r3}
 *   @0xd0f0c mov r0, r2
 *   @0xd0f10 mov r1, r3
 *   @0xd0f14 pop {r3, pc}
 *   @0xd0f18 mov r2, #0
 *   @0xd0f1c mov r3, r2
 *   @0xd0f20 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0f24 ldm r3, {r0, r1}
 *   @0xd0f28 bl 0x319164 <__floatdidf>
 *   @0xd0f2c mov r2, r0
 *   @0xd0f30 mov r3, r1
 *   @0xd0f34 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0f38 ldr r2, [r3]
 *   @0xd0f3c vmov s15, r2
 *   @0xd0f40 vcvt.f64.s32 d7, s15
 *   @0xd0f44 vmov r2, r3, d7
 *   @0xd0f48 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0f4c mvn r3, #-16777216
 *   @0xd0f50 cmp r1, r3
 *   @0xd0f54 beq 0xd0f94 <_Z14REAL_RValue_ExPK6RValue+0x100>
 *   @0xd0f58 ldr r0, [pc, #0x58]
 *   @0xd0f5c add r0, pc, r0
 *   @0xd0f60 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd0f64 mov r2, #0
 *   @0xd0f68 mov r3, r2
 *   @0xd0f6c b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0f70 ldr r2, [r3]
 *   @0xd0f74 cmp r2, #0
 *   @0xd0f78 beq 0xd0fb0 <_Z14REAL_RValue_ExPK6RValue+0x11c>
 *   @0xd0f7c ldr r0, [r2]
 *   @0xd0f80 cmp r0, #0
 *   @0xd0f84 beq 0xd0fac <_Z14REAL_RValue_ExPK6RValue+0x118>
 *   @0xd0f88 mov r1, #0
 *   @0xd0f8c pop {r3, lr}
 *   @0xd0f90 b 0xb6658 <strtod@plt>
 *   @0xd0f94 ldr r0, [pc, #0x20]
 *   @0xd0f98 add r0, pc, r0
 *   @0xd0f9c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd0fa0 mov r2, #0
 *   @0xd0fa4 mov r3, r2
 *   @0xd0fa8 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0fac mov r2, r0
 *   @0xd0fb0 mov r3, r2
 *   @0xd0fb4 b 0xd0f0c <_Z14REAL_RValue_ExPK6RValue+0x78>
 *   @0xd0fb8 eoreq r1, r6, r0, asr r6
 *   @0xd0fbc .word 0x002615fc
 *
 * ══ §65/91 New_Code_Variable_Find  0xd20c0  size 300  75 条（0xd20c0..0xd21ec）
 * @func 0xd20c0 0xd21ec  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: New_Code_Variable_Find(char const*, EVariableType)+0x18×2 / 0xb6574×2 / Variable_BuiltIn_Find(char const*) / New_Code_Variable_Find(char const*, EVariableType)+0x20 / Code_Variable_Find_Slot_From_Local_Name(char const*) / New_Code_Variable_Find(char const*, EVariableType)+0x2c / Code_Variable_Find_Slot_From_Global_Name(char const*)
 * 字段偏移 top8: 0xc4×2 / 0x4×2 / 0xe0×1 / 0x34×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd20c0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xd20c4 mov r5, r1
 *   @0xd20c8 mov r6, r0
 *   @0xd20cc bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0xd20d0 subs r4, r0, #0
 *   @0xd20d4 blt 0xd20e0 <_Z22New_Code_Variable_FindPKc13EVariableType+0x20>
 *   @0xd20d8 mov r0, r4
 *   @0xd20dc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd20e0 bic r3, r5, #2
 *   @0xd20e4 cmp r3, #1
 *   @0xd20e8 beq 0xd21b0 <_Z22New_Code_Variable_FindPKc13EVariableType+0xf0>
 *   @0xd20ec cmp r5, #3
 *   @0xd20f0 cmpne r5, #0
 *   @0xd20f4 beq 0xd21cc <_Z22New_Code_Variable_FindPKc13EVariableType+0x10c>
 *   @0xd20f8 ldr r3, [pc, #0xe0]
 *   @0xd20fc ldr r3, [pc, r3]
 *   @0xd2100 ldr r3, [r3]
 *   @0xd2104 cmp r3, #0
 *   @0xd2108 beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd210c sub r5, r5, #2
 *   @0xd2110 cmp r5, #1
 *   @0xd2114 bhi 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd2118 ldr r1, [pc, #0xc4]
 *   @0xd211c ldr r2, [pc, #0xc4]
 *   @0xd2120 ldr r1, [pc, r1]
 *   @0xd2124 ldr r2, [pc, r2]
 *   @0xd2128 ldr r8, [r1]
 *   @0xd212c ldr r5, [r2]
 *   @0xd2130 cmp r8, #0
 *   @0xd2134 ble 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd2138 ldr r9, [r3, #0x34]
 *   @0xd213c mov r7, #0
 *   @0xd2140 b 0xd2150 <_Z22New_Code_Variable_FindPKc13EVariableType+0x90>
 *   @0xd2144 cmp r7, r8
 *   @0xd2148 add r5, r5, #12
 *   @0xd214c beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd2150 ldr r0, [r5]
 *   @0xd2154 mov r1, r9
 *   @0xd2158 bl 0xb6574 <strcmp@plt>
 *   @0xd215c add r7, r7, #1
 *   @0xd2160 cmp r0, #0
 *   @0xd2164 bne 0xd2144 <_Z22New_Code_Variable_FindPKc13EVariableType+0x84>
 *   @0xd2168 ldr r8, [r5, #0x4]
 *   @0xd216c ldr r7, [r5, #0x8]
 *   @0xd2170 cmp r8, #0
 *   @0xd2174 ble 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd2178 sub r7, r7, #4
 *   @0xd217c mov r5, r0
 *   @0xd2180 b 0xd2190 <_Z22New_Code_Variable_FindPKc13EVariableType+0xd0>
 *   @0xd2184 add r5, r5, #1
 *   @0xd2188 cmp r5, r8
 *   @0xd218c beq 0xd20d8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x18>
 *   @0xd2190 ldr r0, [r7, #0x4]!
 *   @0xd2194 mov r1, r6
 *   @0xd2198 bl 0xb6574 <strcmp@plt>
 *   @0xd219c cmp r0, #0
 *   @0xd21a0 bne 0xd2184 <_Z22New_Code_Variable_FindPKc13EVariableType+0xc4>
 *   @0xd21a4 add r0, r5, #99328
 *   @0xd21a8 add r0, r0, #672
 *   @0xd21ac pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd21b0 mov r0, r6
 *   @0xd21b4 bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc>
 *   @0xd21b8 subs r4, r0, #0
 *   @0xd21bc blt 0xd20ec <_Z22New_Code_Variable_FindPKc13EVariableType+0x2c>
 *   @0xd21c0 add r4, r4, #99328
 *   @0xd21c4 add r0, r4, #672
 *   @0xd21c8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd21cc mov r0, r6
 *   @0xd21d0 bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc>
 *   @0xd21d4 subs r4, r0, #0
 *   @0xd21d8 bge 0xd21c0 <_Z22New_Code_Variable_FindPKc13EVariableType+0x100>
 *   @0xd21dc b 0xd20f8 <_Z22New_Code_Variable_FindPKc13EVariableType+0x38>
 *   @0xd21e0 eorseq r11, r1, r12, lsr #21
 *   @0xd21e4 eorseq r11, r1, r12, lsl #21
 *   @0xd21e8 eorseq r11, r1, r12, lsl #21
 *
 * ══ §66/91 Graphics::Flush  0x1852ec  size 300  75 条（0x1852ec..0x185418）
 * @func 0x1852ec 0x185418  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1852f4→0x3f2928, 0x18530c→0x4a2fa8, 0x185310→0x4a2fa0, 0x185330→0x48ffe4, 0x185334→0x4a2fb4, 0x18534c→0x4a2fac, 0x185350→0x4a2fbc, 0x18536c→0x4a2fa4
 * 调用序列: RenderStateManager::Flush()×2 / Graphics::Flush()+0xd8 / JoinToPreviousStrip() / Graphics::SetTexture(int, void*) / Graphics::DrawArrayEx(ePrimType, int, void*, int)
 * 字段偏移 top8: 0xf0×2 / 0xdc×2 / 0xc0×2 / 0xac×2 / 0x94×1 / 0x84×1 / 0x80×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1852ec push {r4, r5, r6, lr}
 *   @0x1852f0 ldr r4, [pc, #0xf0]
 *   @0x1852f4 ldr r3, [pc, #0xf0]
 *   @0x1852f8 add r4, pc, r4
 *   @0x1852fc ldr r5, [r4, r3]
 *   @0x185300 ldr r3, [r5]
 *   @0x185304 cmp r3, #0
 *   @0x185308 blt 0x1853c4 <_ZN8Graphics5FlushEv+0xd8>
 *   @0x18530c ldr r2, [pc, #0xdc]
 *   @0x185310 ldr r3, [pc, #0xdc]
 *   @0x185314 ldr r6, [r4, r2]
 *   @0x185318 ldr r3, [r4, r3]
 *   @0x18531c ldr r2, [r6]
 *   @0x185320 ldr r1, [r3]
 *   @0x185324 cmp r1, r2
 *   @0x185328 strlt r2, [r3]
 *   @0x18532c bl 0x185218 <_Z19JoinToPreviousStripv>
 *   @0x185330 ldr r2, [pc, #0xc0]
 *   @0x185334 ldr r3, [pc, #0xc0]
 *   @0x185338 ldr r2, [r4, r2]
 *   @0x18533c ldr r3, [r4, r3]
 *   @0x185340 ldr r0, [r2]
 *   @0x185344 ldr r1, [r3]
 *   @0x185348 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x18534c ldr r3, [pc, #0xac]
 *   @0x185350 ldr r2, [pc, #0xac]
 *   @0x185354 ldr r0, [r5]
 *   @0x185358 ldr r3, [r4, r3]
 *   @0x18535c ldr r2, [r4, r2]
 *   @0x185360 ldr r1, [r6]
 *   @0x185364 ldr r3, [r3]
 *   @0x185368 bl 0x185188 <_ZN8Graphics11DrawArrayExE9ePrimTypeiPvi>
 *   @0x18536c ldr r2, [pc, #0x94]
 *   @0x185370 mov r3, #0
 *   @0x185374 mvn r1, #0
 *   @0x185378 str r3, [r6]
 *   @0x18537c str r1, [r5]
 *   @0x185380 ldr r1, [pc, #0x84]
 *   @0x185384 ldr r0, [r4, r2]
 *   @0x185388 ldr r2, [pc, #0x80]
 *   @0x18538c str r3, [r0]
 *   @0x185390 ldr r3, [r4, r1]
 *   @0x185394 ldr r1, [r3]
 *   @0x185398 add r1, r1, #1
 *   @0x18539c str r1, [r3]
 *   @0x1853a0 ldr r0, [r4, r2]
 *   @0x1853a4 bl 0x168134 <_ZN18RenderStateManager5FlushEv>
 *   @0x1853a8 ldr r3, [pc, #0x64]
 *   @0x1853ac ldr r3, [r4, r3]
 *   @0x1853b0 ldr r3, [r3]
 *   @0x1853b4 cmp r3, #1
 *   @0x1853b8 popne {r4, r5, r6, pc}
 *   @0x1853bc pop {r4, r5, r6, lr}
 *   @0x1853c0 b 0x18805c <_Z13Shader_Commitv>
 *   @0x1853c4 ldr r3, [pc, #0x44]
 *   @0x1853c8 ldr r0, [r4, r3]
 *   @0x1853cc bl 0x168134 <_ZN18RenderStateManager5FlushEv>
 *   @0x1853d0 ldr r3, [pc, #0x3c]
 *   @0x1853d4 ldr r3, [r4, r3]
 *   @0x1853d8 ldr r3, [r3]
 *   @0x1853dc cmp r3, #1
 *   @0x1853e0 popne {r4, r5, r6, pc}
 *   @0x1853e4 b 0x1853bc <_ZN8Graphics5FlushEv+0xd0>
 *   @0x1853e8 eoreq r12, r6, r8, asr r9
 *   @0x1853ec .word 0xffffe948
 *   @0x1853f0 .word 0xffffe94c
 *   @0x1853f4 .word 0xffffe95c
 *   @0x1853f8 .word 0xffffe4d4
 *   @0x1853fc .word 0xffffe8f8
 *   @0x185400 .word 0xffffe960
 *   @0x185404 .word 0xffffe958
 *   @0x185408 .word 0xffffe950
 *   @0x18540c .word 0xffffe744
 *   @0x185410 .word 0xffffc0a8
 *   @0x185414 .word 0xffffe7b8
 *
 * ══ §67/91 CScriptRef::CScriptRef  0x191de0  size 300  75 条（0x191de0..0x191f0c）
 * @func 0x191de0 0x191f0c  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::YYObjectBase(int, int) / CScriptRef::CScriptRef(int, int)+0xc8 / YYRealloc(void*, int) / 0xb65b0
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0xc×2 / 0x110×1 / 0x10c×1 / 0x48×1 / 0x64×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191de0 push {r3, r4, r5, r6, r7, lr}
 *   @0x191de4 mov r4, r0
 *   @0x191de8 bl 0x19188c <_ZN12YYObjectBaseC2Eii>
 *   @0x191dec ldr r6, [pc, #0x110]
 *   @0x191df0 mov r5, #0
 *   @0x191df4 ldr r3, [pc, #0x10c]
 *   @0x191df8 mov r2, #3
 *   @0x191dfc ldr r6, [pc, r6]
 *   @0x191e00 str r2, [r4, #0x48]
 *   @0x191e04 ldr r3, [pc, r3]
 *   @0x191e08 str r5, [r4, #0x64]
 *   @0x191e0c ldr r7, [r6, #0x8]
 *   @0x191e10 add r3, r3, #8
 *   @0x191e14 ldr r0, [r6, #0x4]
 *   @0x191e18 str r5, [r4, #0x68]
 *   @0x191e1c cmp r7, r0
 *   @0x191e20 str r3, [r4]
 *   @0x191e24 str r5, [r4, #0x8c]
 *   @0x191e28 mvn r3, #-16777216
 *   @0x191e2c str r5, [r4, #0x90]
 *   @0x191e30 str r5, [r4, #0x94]
 *   @0x191e34 str r5, [r4, #0x6c]
 *   @0x191e38 str r5, [r4, #0x70]
 *   @0x191e3c str r5, [r4, #0x74]
 *   @0x191e40 str r5, [r4, #0x7c]
 *   @0x191e44 str r5, [r4, #0x80]
 *   @0x191e48 str r5, [r4, #0x84]
 *   @0x191e4c str r3, [r4, #0x78]
 *   @0x191e50 str r3, [r4, #0x88]
 *   @0x191e54 bge 0x191ec0 <_ZN10CScriptRefC2Eii+0xe0>
 *   @0x191e58 cmp r0, #0
 *   @0x191e5c ldr r3, [r6, #0xc]
 *   @0x191e60 ble 0x191ea8 <_ZN10CScriptRefC2Eii+0xc8>
 *   @0x191e64 ldr r12, [r6]
 *   @0x191e68 mov r1, r0
 *   @0x191e6c b 0x191e7c <_ZN10CScriptRefC2Eii+0x9c>
 *   @0x191e70 subs r1, r1, #1
 *   @0x191e74 add r3, r3, #1
 *   @0x191e78 beq 0x191ea8 <_ZN10CScriptRefC2Eii+0xc8>
 *   @0x191e7c cmp r3, r0
 *   @0x191e80 lsl r2, r3, #2
 *   @0x191e84 movge r3, #0
 *   @0x191e88 movge r2, r3
 *   @0x191e8c add r5, r12, r2
 *   @0x191e90 ldr r2, [r12, r2]
 *   @0x191e94 cmp r2, #0
 *   @0x191e98 bne 0x191e70 <_ZN10CScriptRefC2Eii+0x90>
 *   @0x191e9c str r4, [r5]
 *   @0x191ea0 str r3, [r6, #0xc]
 *   @0x191ea4 b 0x191eac <_ZN10CScriptRefC2Eii+0xcc>
 *   @0x191ea8 mvn r3, #0
 *   @0x191eac add r7, r7, #1
 *   @0x191eb0 str r3, [r4, #0x44]
 *   @0x191eb4 str r7, [r6, #0x8]
 *   @0x191eb8 mov r0, r4
 *   @0x191ebc pop {r3, r4, r5, r6, r7, pc}
 *   @0x191ec0 add r7, r0, r0, lsl #1
 *   @0x191ec4 ldr r0, [r6]
 *   @0x191ec8 add r7, r7, r7, lsr #31
 *   @0x191ecc asr r7, r7, #1
 *   @0x191ed0 lsl r1, r7, #2
 *   @0x191ed4 bl 0xcef64 <_Z9YYReallocPvi>
 *   @0x191ed8 ldr r3, [r6, #0x4]
 *   @0x191edc mov r1, r5
 *   @0x191ee0 rsb r2, r3, r7
 *   @0x191ee4 lsl r2, r2, #2
 *   @0x191ee8 str r0, [r6]
 *   @0x191eec add r0, r0, r3, lsl #2
 *   @0x191ef0 bl 0xb65b0 <memset@plt>
 *   @0x191ef4 str r7, [r6, #0x4]
 *   @0x191ef8 mov r0, r7
 *   @0x191efc ldr r7, [r6, #0x8]
 *   @0x191f00 b 0x191e58 <_ZN10CScriptRefC2Eii+0x78>
 *   @0x191f04 eoreq r11, r5, r8, ror #28
 *   @0x191f08 eoreq lr, r5, r8, ror r8
 *
 * ══ §68/91 Calc_GUI_Scale  0x1b3204  size 300  75 条（0x1b3204..0x1b3330）
 * @func 0x1b3204 0x1b3330  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b3218→0x542564, 0x1b3254→0x3f26c0, 0x1b3260→0x3f26bc, 0x1b329c→0x5425c0
 * 调用序列: 0xb6910×2 / 0xb6994×2 / CalcGUITransformMat(yyMatrix&, yyMatrix&, float&, float&, float&, float&) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 0x104×1 / 0x100×1 / 0x4×1 / 0xc8×1 / 0xc0×1 / 0x88×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b3204 push {r4, r5, lr}
 *   @0x1b3208 vpush {d8, d9, d10}
 *   @0x1b320c sub sp, sp, #92
 *   @0x1b3210 ldr r4, [pc, #0x104]
 *   @0x1b3214 add r5, sp, #24
 *   @0x1b3218 ldr r1, [pc, #0x100]
 *   @0x1b321c add r2, sp, #8
 *   @0x1b3220 add r4, pc, r4
 *   @0x1b3224 add r3, sp, #12
 *   @0x1b3228 mov r0, r5
 *   @0x1b322c add r12, sp, #16
 *   @0x1b3230 ldr r1, [r4, r1]
 *   @0x1b3234 str r12, [sp]
 *   @0x1b3238 add r12, sp, #20
 *   @0x1b323c str r12, [sp, #0x4]
 *   @0x1b3240 bl 0x1b2e14 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_>
 *   @0x1b3244 mov r1, r5
 *   @0x1b3248 mov r0, #0
 *   @0x1b324c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b3250 vmov.f32 s15, #5.000000e-01
 *   @0x1b3254 ldr r2, [pc, #0xc8]
 *   @0x1b3258 vldr s19, [sp, #16]
 *   @0x1b325c vldr s16, [sp, #8]
 *   @0x1b3260 ldr r3, [pc, #0xc0]
 *   @0x1b3264 ldr r2, [r4, r2]
 *   @0x1b3268 vldr s20, [r2]
 *   @0x1b326c ldr r3, [r4, r3]
 *   @0x1b3270 vldr s18, [r3]
 *   @0x1b3274 vcvt.f32.s32 s20, s20
 *   @0x1b3278 vmul.f32 s20, s20, s15
 *   @0x1b327c vneg.f32 s14, s20
 *   @0x1b3280 vsub.f32 s14, s14, s19
 *   @0x1b3284 vdiv.f32 s14, s14, s16
 *   @0x1b3288 vsub.f32 s19, s20, s19
 *   @0x1b328c vmov r0, s14
 *   @0x1b3290 vcvt.f32.s32 s18, s18
 *   @0x1b3294 vmul.f32 s18, s18, s15
 *   @0x1b3298 bl 0xb6910 <floorf@plt>
 *   @0x1b329c ldr r3, [pc, #0x88]
 *   @0x1b32a0 ldr r4, [r4, r3]
 *   @0x1b32a4 vdiv.f32 s19, s19, s16
 *   @0x1b32a8 vmov s14, r0
 *   @0x1b32ac vcvt.s32.f32 s14, s14
 *   @0x1b32b0 vmov r0, s19
 *   @0x1b32b4 vstr s14, [r4]
 *   @0x1b32b8 bl 0xb6994 <ceilf@plt>
 *   @0x1b32bc vneg.f32 s15, s18
 *   @0x1b32c0 vldr s17, [sp, #20]
 *   @0x1b32c4 vldr s16, [sp, #12]
 *   @0x1b32c8 vsub.f32 s15, s15, s17
 *   @0x1b32cc vdiv.f32 s15, s15, s16
 *   @0x1b32d0 vmov s14, r0
 *   @0x1b32d4 vsub.f32 s17, s18, s17
 *   @0x1b32d8 vmov r0, s15
 *   @0x1b32dc vcvt.s32.f32 s14, s14
 *   @0x1b32e0 vstr s14, [r4, #8]
 *   @0x1b32e4 bl 0xb6910 <floorf@plt>
 *   @0x1b32e8 vdiv.f32 s17, s17, s16
 *   @0x1b32ec vmov s15, r0
 *   @0x1b32f0 vcvt.s32.f32 s15, s15
 *   @0x1b32f4 vmov r0, s17
 *   @0x1b32f8 vstr s15, [r4, #4]
 *   @0x1b32fc bl 0xb6994 <ceilf@plt>
 *   @0x1b3300 vmov s14, r0
 *   @0x1b3304 vcvt.s32.f32 s14, s14
 *   @0x1b3308 vstr s14, [r4, #12]
 *   @0x1b330c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b3310 add sp, sp, #92
 *   @0x1b3314 vpop {d8, d9, d10}
 *   @0x1b3318 pop {r4, r5, pc}
 *   @0x1b331c eoreq lr, r3, r0, lsr r10
 *   @0x1b3320 .word 0xffffdf50
 *   @0x1b3324 .word 0xffffe24c
 *   @0x1b3328 .word 0xffffe250
 *   @0x1b332c .word 0xffffe4fc
 *
 * ══ §69/91 ExecuteLayerScript  0x1b3418  size 300  75 条（0x1b3418..0x1b3544）
 * @func 0x1b3418 0x1b3544  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b3434→0x54290c, 0x1b343c→0x542908, 0x1b3440→0x542904, 0x1b3454→0x47f295, 0x1b3480→0x542610, 0x1b34dc→0x544be0
 * 调用序列: Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*)×2 / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xec×2 / 0x4×2 / 0x14×2 / 0x104×1 / 0xf0×1 / 0x8×1 / 0xdc×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b3418 cmn r1, #1
 *   @0x1b341c ldr r12, [pc, #0x104]
 *   @0x1b3420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b3424 add r12, pc, r12
 *   @0x1b3428 sub sp, sp, #28
 *   @0x1b342c mov r7, r1
 *   @0x1b3430 beq 0x1b34d4 <_Z18ExecuteLayerScriptiiii+0xbc>
 *   @0x1b3434 ldr r6, [pc, #0xf0]
 *   @0x1b3438 mov r1, #0
 *   @0x1b343c ldr r5, [pc, #0xec]
 *   @0x1b3440 ldr r4, [pc, #0xec]
 *   @0x1b3444 str r1, [sp, #0x8]
 *   @0x1b3448 ldr r6, [r12, r6]
 *   @0x1b344c ldr r5, [r12, r5]
 *   @0x1b3450 ldr r4, [r12, r4]
 *   @0x1b3454 ldr r11, [pc, #0xdc]
 *   @0x1b3458 ldr r10, [r6]
 *   @0x1b345c ldr r9, [r5]
 *   @0x1b3460 str r0, [r6]
 *   @0x1b3464 str r2, [r5]
 *   @0x1b3468 ldr r8, [r4]
 *   @0x1b346c str r3, [r4]
 *   @0x1b3470 ldr r3, [r12, r11]
 *   @0x1b3474 ldrb r3, [r3]
 *   @0x1b3478 cmp r3, r1
 *   @0x1b347c bne 0x1b34dc <_Z18ExecuteLayerScriptiiii+0xc4>
 *   @0x1b3480 ldr r2, [pc, #0xb4]
 *   @0x1b3484 ldr r2, [r12, r2]
 *   @0x1b3488 ldr r1, [r2]
 *   @0x1b348c cmp r1, #0
 *   @0x1b3490 beq 0x1b34ac <_Z18ExecuteLayerScriptiiii+0x94>
 *   @0x1b3494 mov r0, r7
 *   @0x1b3498 str r3, [sp, #0x4]
 *   @0x1b349c add r7, sp, #8
 *   @0x1b34a0 mov r2, r1
 *   @0x1b34a4 str r7, [sp]
 *   @0x1b34a8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x1b34ac ldr r3, [sp, #0x14]
 *   @0x1b34b0 sub r3, r3, #1
 *   @0x1b34b4 bic r3, r3, #-16777216
 *   @0x1b34b8 bic r3, r3, #3
 *   @0x1b34bc cmp r3, #0
 *   @0x1b34c0 addeq r7, sp, #8
 *   @0x1b34c4 beq 0x1b351c <_Z18ExecuteLayerScriptiiii+0x104>
 *   @0x1b34c8 str r10, [r6]
 *   @0x1b34cc str r9, [r5]
 *   @0x1b34d0 str r8, [r4]
 *   @0x1b34d4 add sp, sp, #28
 *   @0x1b34d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b34dc ldr r2, [pc, #0x5c]
 *   @0x1b34e0 mov r3, r1
 *   @0x1b34e4 mov r0, r7
 *   @0x1b34e8 add r7, sp, #8
 *   @0x1b34ec ldr r2, [r12, r2]
 *   @0x1b34f0 str r1, [sp, #0x4]
 *   @0x1b34f4 str r7, [sp]
 *   @0x1b34f8 ldr r1, [r2]
 *   @0x1b34fc mov r2, r1
 *   @0x1b3500 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x1b3504 ldr r3, [sp, #0x14]
 *   @0x1b3508 sub r3, r3, #1
 *   @0x1b350c bic r3, r3, #-16777216
 *   @0x1b3510 bic r3, r3, #3
 *   @0x1b3514 cmp r3, #0
 *   @0x1b3518 bne 0x1b34c8 <_Z18ExecuteLayerScriptiiii+0xb0>
 *   @0x1b351c mov r0, r7
 *   @0x1b3520 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1b3524 b 0x1b34c8 <_Z18ExecuteLayerScriptiiii+0xb0>
 *   @0x1b3528 eoreq lr, r3, r12, lsr #16
 *   @0x1b352c .word 0xffffc168
 *   @0x1b3530 .word 0xffffc160
 *   @0x1b3534 .word 0xffffc164
 *   @0x1b3538 .word 0xffffbf68
 *   @0x1b353c .word 0xffffc020
 *   @0x1b3540 .word 0xffffbf64
 *
 * ══ §70/91 SetFogUniforms  0x184064  size 296  74 条（0x184064..0x18418c）
 * @func 0x184064 0x18418c  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x184080→0x479b2c, 0x184084→0x4a23f4, 0x1840a8→0x479b2c, 0x1840ac→0x4a23f4, 0x1840d0→0x479ab4, 0x1840d4→0x4a2394, 0x1840ec→0x3f2790, 0x184120→0x479ab4
 * 调用序列: 无
 * 字段偏移 top8: 0xe8×2 / 0xc0×2 / 0xa0×2 / 0x50×2 / 0x48×1 / 0xf4×1 / 0x54×1 / 0x4c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184064 push {r4, r5, r6, lr}
 *   @0x184068 mov r5, r0
 *   @0x18406c ldr r0, [r0, #0x48]
 *   @0x184070 ldr r4, [pc, #0xf4]
 *   @0x184074 cmn r0, #1
 *   @0x184078 add r4, pc, r4
 *   @0x18407c beq 0x18409c <_Z14SetFogUniformsP10GLSLShader+0x38>
 *   @0x184080 ldr r3, [pc, #0xe8]
 *   @0x184084 ldr r2, [pc, #0xe8]
 *   @0x184088 ldr r3, [r4, r3]
 *   @0x18408c ldr r2, [r4, r2]
 *   @0x184090 ldr r3, [r3]
 *   @0x184094 ldrb r1, [r2]
 *   @0x184098 blx r3
 *   @0x18409c ldr r0, [r5, #0x54]
 *   @0x1840a0 cmn r0, #1
 *   @0x1840a4 beq 0x1840c4 <_Z14SetFogUniformsP10GLSLShader+0x60>
 *   @0x1840a8 ldr r3, [pc, #0xc0]
 *   @0x1840ac ldr r2, [pc, #0xc0]
 *   @0x1840b0 ldr r3, [r4, r3]
 *   @0x1840b4 ldr r2, [r4, r2]
 *   @0x1840b8 ldr r3, [r3]
 *   @0x1840bc ldrb r1, [r2]
 *   @0x1840c0 blx r3
 *   @0x1840c4 ldr r0, [r5, #0x4c]
 *   @0x1840c8 cmn r0, #1
 *   @0x1840cc beq 0x184160 <_Z14SetFogUniformsP10GLSLShader+0xfc>
 *   @0x1840d0 ldr r3, [pc, #0xa0]
 *   @0x1840d4 ldr r2, [pc, #0xa0]
 *   @0x1840d8 ldr r3, [r4, r3]
 *   @0x1840dc ldr r6, [r4, r2]
 *   @0x1840e0 ldr r3, [r3]
 *   @0x1840e4 ldr r1, [r6]
 *   @0x1840e8 blx r3
 *   @0x1840ec ldr r3, [pc, #0x8c]
 *   @0x1840f0 vldr s15, [r6]
 *   @0x1840f4 ldr r0, [r5, #0x50]
 *   @0x1840f8 ldr r3, [r4, r3]
 *   @0x1840fc vldr s14, [r3]
 *   @0x184100 vsub.f32 s15, s14, s15
 *   @0x184104 vcmpe.f32 s15, #0
 *   @0x184108 vmrs APSR_nzcv, fpscr
 *   @0x18410c vmovgt.f32 s14, #1.000000e+00
 *   @0x184110 vmovle.f32 s15, #1.000000e+00
 *   @0x184114 vdivgt.f32 s15, s14, s15
 *   @0x184118 cmn r0, #1
 *   @0x18411c beq 0x184134 <_Z14SetFogUniformsP10GLSLShader+0xd0>
 *   @0x184120 ldr r3, [pc, #0x50]
 *   @0x184124 vmov r1, s15
 *   @0x184128 ldr r3, [r4, r3]
 *   @0x18412c ldr r3, [r3]
 *   @0x184130 blx r3
 *   @0x184134 ldr r0, [r5, #0x58]
 *   @0x184138 cmn r0, #1
 *   @0x18413c popeq {r4, r5, r6, pc}
 *   @0x184140 ldr r3, [pc, #0x3c]
 *   @0x184144 mov r1, #1
 *   @0x184148 ldr r2, [pc, #0x38]
 *   @0x18414c ldr r3, [r4, r3]
 *   @0x184150 ldr r2, [r4, r2]
 *   @0x184154 ldr r3, [r3]
 *   @0x184158 blx r3
 *   @0x18415c pop {r4, r5, r6, pc}
 *   @0x184160 ldr r3, [pc, #0x14]
 *   @0x184164 ldr r6, [r4, r3]
 *   @0x184168 b 0x1840ec <_Z14SetFogUniformsP10GLSLShader+0x88>
 *   @0x18416c .word 0x0026dbd8
 *   @0x184170 .word 0xffffbb84
 *   @0x184174 .word 0xffffe884
 *   @0x184178 .word 0xffffbbfc
 *   @0x18417c .word 0xffffe878
 *   @0x184180 .word 0xffffe874
 *   @0x184184 .word 0xffffbbd0
 *   @0x184188 .word 0xffffe87c
 *
 * ══ §71/91 CLayerManager::GetNewTilemapElement  0x1c1034  size 296  74 条（0x1c1034..0x1c115c）
 * @func 0x1c1034 0x1c115c  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewTilemapElement()+0xe0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewTilemapElement()+0x34
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0x114×1 / 0xf8×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c1034 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c1038 ldr r5, [pc, #0x114]
 *   @0x1c103c ldr r5, [pc, r5]
 *   @0x1c1040 ldr r6, [r5, #0x8]
 *   @0x1c1044 cmp r6, #0
 *   @0x1c1048 bne 0x1c111c <_ZN13CLayerManager20GetNewTilemapElementEv+0xe8>
 *   @0x1c104c ldr r3, [r5, #0x10]
 *   @0x1c1050 cmp r3, #0
 *   @0x1c1054 ble 0x1c1114 <_ZN13CLayerManager20GetNewTilemapElementEv+0xe0>
 *   @0x1c1058 ldr r8, [pc, #0xf8]
 *   @0x1c105c mov r4, r6
 *   @0x1c1060 mov r7, #0
 *   @0x1c1064 add r8, pc, r8
 *   @0x1c1068 mov r1, r8
 *   @0x1c106c mov r2, #63
 *   @0x1c1070 mov r3, #1
 *   @0x1c1074 mov r0, #60
 *   @0x1c1078 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c107c mvn r3, #0
 *   @0x1c1080 mvn r1, #-2147483648
 *   @0x1c1084 mov r2, #5
 *   @0x1c1088 cmp r0, #0
 *   @0x1c108c beq 0x1c10cc <_ZN13CLayerManager20GetNewTilemapElementEv+0x98>
 *   @0x1c1090 strb r4, [r0, #0x8]
 *   @0x1c1094 str r7, [r0, #0x20]
 *   @0x1c1098 str r4, [r0, #0xc]
 *   @0x1c109c str r7, [r0, #0x24]
 *   @0x1c10a0 str r4, [r0, #0x10]
 *   @0x1c10a4 str r7, [r0, #0x30]
 *   @0x1c10a8 str r4, [r0, #0x14]
 *   @0x1c10ac str r4, [r0, #0x18]
 *   @0x1c10b0 str r3, [r0, #0x4]
 *   @0x1c10b4 str r3, [r0, #0x1c]
 *   @0x1c10b8 str r4, [r0, #0x28]
 *   @0x1c10bc str r4, [r0, #0x2c]
 *   @0x1c10c0 str r4, [r0, #0x34]
 *   @0x1c10c4 str r1, [r0, #0x38]
 *   @0x1c10c8 str r2, [r0]
 *   @0x1c10cc ldr r3, [r5]
 *   @0x1c10d0 add r6, r6, #1
 *   @0x1c10d4 ldr r2, [r5, #0x8]
 *   @0x1c10d8 cmp r3, #0
 *   @0x1c10dc streq r0, [r5, #0x4]
 *   @0x1c10e0 strne r0, [r3, #0x18]
 *   @0x1c10e4 add r2, r2, #1
 *   @0x1c10e8 streq r3, [r0, #0x18]
 *   @0x1c10ec streq r3, [r0, #0x14]
 *   @0x1c10f0 strne r3, [r0, #0x14]
 *   @0x1c10f4 ldr r3, [r5, #0x10]
 *   @0x1c10f8 streq r0, [r5]
 *   @0x1c10fc strne r0, [r5]
 *   @0x1c1100 strne r4, [r0, #0x18]
 *   @0x1c1104 cmp r6, r3
 *   @0x1c1108 str r2, [r5, #0x8]
 *   @0x1c110c blt 0x1c1068 <_ZN13CLayerManager20GetNewTilemapElementEv+0x34>
 *   @0x1c1110 ldr r6, [r5, #0x8]
 *   @0x1c1114 lsl r3, r3, #1
 *   @0x1c1118 str r3, [r5, #0x10]
 *   @0x1c111c ldr r0, [r5]
 *   @0x1c1120 sub r6, r6, #1
 *   @0x1c1124 str r6, [r5, #0x8]
 *   @0x1c1128 ldr r3, [r0, #0x18]
 *   @0x1c112c ldr r2, [r0, #0x14]
 *   @0x1c1130 cmp r3, #0
 *   @0x1c1134 strne r2, [r3, #0x14]
 *   @0x1c1138 ldrne r2, [r0, #0x14]
 *   @0x1c113c ldrne r3, [r0, #0x18]
 *   @0x1c1140 streq r2, [r5]
 *   @0x1c1144 cmp r2, #0
 *   @0x1c1148 streq r3, [r5, #0x4]
 *   @0x1c114c strne r3, [r2, #0x18]
 *   @0x1c1150 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c1154 eoreq pc, r2, r4, lsr r8
 *   @0x1c1158 andseq r12, r8, r0, lsr r6
 *
 * ══ §72/91 CSkeletonInstance::SetAttachment  0xbe6cc  size 292  73 条（0xbe6cc..0xbe7f0）
 * @func 0xbe6cc 0xbe7f0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkin_getAttachment×2 / spSkeleton_findSlot / spSkeleton_findSlotIndex / 0xb6574 / CSkeletonInstance::SetAttachment(char const*, char const*, bool)+0x44
 * 字段偏移 top8: 0x1c×3 / 0x30×2 / 0x20×2 / 0x10×1 / 0x14×1 / 0x4×1 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe6cc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbe6d0 mov r4, r0
 *   @0xbe6d4 ldr r0, [r0, #0x1c]
 *   @0xbe6d8 mov r7, r2
 *   @0xbe6dc mov r5, r3
 *   @0xbe6e0 mov r6, r1
 *   @0xbe6e4 bl 0x28a18c <spSkeleton_findSlot>
 *   @0xbe6e8 subs r9, r0, #0
 *   @0xbe6ec popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xbe6f0 cmp r7, #0
 *   @0xbe6f4 beq 0xbe7e4 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x118>
 *   @0xbe6f8 mov r1, r6
 *   @0xbe6fc ldr r0, [r4, #0x1c]
 *   @0xbe700 bl 0x28a1f4 <spSkeleton_findSlotIndex>
 *   @0xbe704 cmp r5, #0
 *   @0xbe708 mov r8, r0
 *   @0xbe70c beq 0xbe764 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x98>
 *   @0xbe710 ldr r8, [r4, #0x10]
 *   @0xbe714 cmp r8, #0
 *   @0xbe718 pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xbe71c ldr r5, [r4, #0x14]
 *   @0xbe720 mov r4, #0
 *   @0xbe724 sub r5, r5, #4
 *   @0xbe728 b 0xbe734 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x68>
 *   @0xbe72c cmp r4, r8
 *   @0xbe730 beq 0xbe760 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x94>
 *   @0xbe734 ldr r6, [r5, #0x4]!
 *   @0xbe738 mov r1, r7
 *   @0xbe73c add r4, r4, #1
 *   @0xbe740 ldr r0, [r6]
 *   @0xbe744 bl 0xb6574 <strcmp@plt>
 *   @0xbe748 cmp r0, #0
 *   @0xbe74c bne 0xbe72c <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x60>
 *   @0xbe750 mov r0, r9
 *   @0xbe754 mov r1, r6
 *   @0xbe758 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbe75c b 0x28ee1c <spSlot_setAttachment>
 *   @0xbe760 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xbe764 ldr r3, [r4, #0x1c]
 *   @0xbe768 mov r1, r0
 *   @0xbe76c mov r2, r7
 *   @0xbe770 ldr r6, [r3, #0x38]
 *   @0xbe774 mov r0, r6
 *   @0xbe778 bl 0x28ed00 <spSkin_getAttachment>
 *   @0xbe77c subs r1, r0, #0
 *   @0xbe780 beq 0xbe790 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xc4>
 *   @0xbe784 mov r0, r9
 *   @0xbe788 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbe78c b 0x28ee1c <spSlot_setAttachment>
 *   @0xbe790 ldr r3, [r4, #0x30]
 *   @0xbe794 ldr r2, [r3, #0x20]
 *   @0xbe798 cmp r2, #0
 *   @0xbe79c movgt r5, r1
 *   @0xbe7a0 bgt 0xbe7bc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xf0>
 *   @0xbe7a4 b 0xbe710 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x44>
 *   @0xbe7a8 ldr r3, [r4, #0x30]
 *   @0xbe7ac ldr r2, [r3, #0x20]
 *   @0xbe7b0 add r5, r5, #1
 *   @0xbe7b4 cmp r2, r5
 *   @0xbe7b8 ble 0xbe710 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x44>
 *   @0xbe7bc ldr r12, [r3, #0x24]
 *   @0xbe7c0 mov r1, r8
 *   @0xbe7c4 mov r2, r7
 *   @0xbe7c8 ldr r0, [r12, r5, lsl #2]
 *   @0xbe7cc cmp r0, r6
 *   @0xbe7d0 beq 0xbe7ac <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xe0>
 *   @0xbe7d4 bl 0x28ed00 <spSkin_getAttachment>
 *   @0xbe7d8 subs r1, r0, #0
 *   @0xbe7dc beq 0xbe7a8 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xdc>
 *   @0xbe7e0 b 0xbe784 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xb8>
 *   @0xbe7e4 mov r1, r7
 *   @0xbe7e8 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbe7ec b 0x28ee1c <spSlot_setAttachment>
 *
 * ══ §73/91 CSkeletonInstance::SkeletonCollision  0xbefd8  size 292  73 条（0xbefd8..0xbf0fc）
 * @func 0xbefd8 0xbf0fc  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*)×2 / CSkeletonInstance::SkeletonCollision(int, float, float, float, float, float, CSkeletonInstance*, int, float, float, float, float, float)+0x11c / spSkeletonBounds_intersectsSegment
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x20×3 / 0xc×2 / 0x40×1 / 0x4c×1 / 0x50×1 / 0x44×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbefd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbefdc vpush {d8}
 *   @0xbefe0 sub sp, sp, #20
 *   @0xbefe4 vldr s16, [sp, #92]
 *   @0xbefe8 mov r9, #0
 *   @0xbefec mov r8, r0
 *   @0xbeff0 ldr r12, [sp, #0x40]
 *   @0xbeff4 ldr r10, [sp, #0x4c]
 *   @0xbeff8 ldr r6, [sp, #0x50]
 *   @0xbeffc str r12, [sp]
 *   @0xbf000 ldr r12, [sp, #0x44]
 *   @0xbf004 ldr r5, [sp, #0x54]
 *   @0xbf008 ldr r4, [sp, #0x58]
 *   @0xbf00c str r12, [sp, #0x4]
 *   @0xbf010 ldr r12, [sp, #0x48]
 *   @0xbf014 ldr r11, [sp, #0x60]
 *   @0xbf018 ldr r7, [sp, #0x64]
 *   @0xbf01c str r12, [sp, #0x8]
 *   @0xbf020 str r9, [sp, #0xc]
 *   @0xbf024 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf028 mov r2, r5
 *   @0xbf02c mov r3, r4
 *   @0xbf030 vstr s16, [sp]
 *   @0xbf034 str r11, [sp, #0x4]
 *   @0xbf038 mov r1, r6
 *   @0xbf03c str r7, [sp, #0x8]
 *   @0xbf040 mov r0, r10
 *   @0xbf044 str r9, [sp, #0xc]
 *   @0xbf048 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf04c ldr r3, [r10, #0x20]
 *   @0xbf050 ldr r2, [r3]
 *   @0xbf054 cmp r2, r9
 *   @0xbf058 ble 0xbf0f4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x11c>
 *   @0xbf05c ldr r2, [r3, #0x8]
 *   @0xbf060 ldr r6, [r2, r9, lsl #2]
 *   @0xbf064 ldr r5, [r6, #0x4]
 *   @0xbf068 asr r5, r5, #1
 *   @0xbf06c cmp r5, #0
 *   @0xbf070 subgt r7, r5, #1
 *   @0xbf074 movgt r11, #4
 *   @0xbf078 movgt r4, #0
 *   @0xbf07c bgt 0xbf08c <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xb4>
 *   @0xbf080 b 0xbf0e4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x10c>
 *   @0xbf084 cmp r4, r5
 *   @0xbf088 beq 0xbf0e0 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x108>
 *   @0xbf08c ldr r0, [r6]
 *   @0xbf090 cmp r4, r7
 *   @0xbf094 add r3, r0, r4, lsl #3
 *   @0xbf098 add r12, r0, r11
 *   @0xbf09c add r4, r4, #1
 *   @0xbf0a0 add r11, r11, #8
 *   @0xbf0a4 ldr r1, [r3]
 *   @0xbf0a8 ldrne r0, [r12, #0x8]
 *   @0xbf0ac ldreq r3, [r0]
 *   @0xbf0b0 ldreq r0, [r0, #0x4]
 *   @0xbf0b4 ldrne r3, [r12, #0x4]
 *   @0xbf0b8 ldr r2, [r12]
 *   @0xbf0bc str r0, [sp]
 *   @0xbf0c0 ldr r0, [r8, #0x20]
 *   @0xbf0c4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf0c8 cmp r0, #0
 *   @0xbf0cc beq 0xbf084 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xac>
 *   @0xbf0d0 mov r0, #1
 *   @0xbf0d4 add sp, sp, #20
 *   @0xbf0d8 vpop {d8}
 *   @0xbf0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbf0e0 ldr r3, [r10, #0x20]
 *   @0xbf0e4 ldr r2, [r3]
 *   @0xbf0e8 add r9, r9, #1
 *   @0xbf0ec cmp r2, r9
 *   @0xbf0f0 bgt 0xbf05c <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0x84>
 *   @0xbf0f4 mov r0, #0
 *   @0xbf0f8 b 0xbf0d4 <_ZN17CSkeletonInstance17SkeletonCollisionEifffffPS_ifffff+0xfc>
 *
 * ══ §74/91 SetViewExtents  0x1692e4  size 292  73 条（0x1692e4..0x169408）
 * @func 0x1692e4 0x169408  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / 0xfe22ddb8
 * 字段偏移 top8: 0xc4×1 / 0x4c×1
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1692e4 push {r3, lr}
 *   @0x1692e8 vpush {d8, d9, d10}
 *   @0x1692ec vldr s15, [sp, #32]
 *   @0x1692f0 vabs.f32 s13, s15
 *   @0x1692f4 vldr s14, [pc, #248]
 *   @0x1692f8 vmov s19, r0
 *   @0x1692fc vmov s18, r1
 *   @0x169300 vmov s17, r2
 *   @0x169304 vcmpe.f32 s13, s14
 *   @0x169308 vmov s16, r3
 *   @0x16930c vmrs APSR_nzcv, fpscr
 *   @0x169310 bmi 0x1693a8 <_Z14SetViewExtentsfffff+0xc4>
 *   @0x169314 vldr s21, [pc, #220]
 *   @0x169318 vmul.f32 s21, s15, s21
 *   @0x16931c vmov r0, s21
 *   @0x169320 bl 0xb6580 <sinf@plt>
 *   @0x169324 vmov s14, r0
 *   @0x169328 vmov r0, s21
 *   @0x16932c vabs.f32 s20, s14
 *   @0x169330 bl 0xb658c <cosf@plt>
 *   @0x169334 ldr r3, [pc, #0xc4]
 *   @0x169338 ldr r3, [pc, r3]
 *   @0x16933c vmul.f32 s13, s16, s20
 *   @0x169340 vmov.f32 s15, #5.000000e-01
 *   @0x169344 vmov s14, r0
 *   @0x169348 vabs.f32 s12, s14
 *   @0x16934c vmul.f32 s14, s16, s12
 *   @0x169350 vmla.f32 s13, s17, s12
 *   @0x169354 vmla.f32 s14, s17, s20
 *   @0x169358 vsub.f32 s12, s17, s13
 *   @0x16935c vsub.f32 s11, s16, s14
 *   @0x169360 vadd.f32 s17, s17, s13
 *   @0x169364 vadd.f32 s16, s16, s14
 *   @0x169368 vmov.f32 s13, s18
 *   @0x16936c vmov.f32 s14, s19
 *   @0x169370 vmla.f32 s18, s16, s15
 *   @0x169374 vmla.f32 s19, s17, s15
 *   @0x169378 vmla.f32 s14, s12, s15
 *   @0x16937c vmla.f32 s13, s11, s15
 *   @0x169380 vcvt.s32.f32 s19, s19
 *   @0x169384 vcvt.s32.f32 s18, s18
 *   @0x169388 vstr s19, [r3, #8]
 *   @0x16938c vcvt.s32.f32 s12, s14
 *   @0x169390 vstr s18, [r3, #12]
 *   @0x169394 vpop {d8, d9, d10}
 *   @0x169398 vcvt.s32.f32 s13, s13
 *   @0x16939c vstr s12, [r3]
 *   @0x1693a0 vstr s13, [r3, #4]
 *   @0x1693a4 pop {r3, pc}
 *   @0x1693a8 vadd.f32 s17, s19, s17
 *   @0x1693ac vldr s15, [pc, #72]
 *   @0x1693b0 ldr r3, [pc, #0x4c]
 *   @0x1693b4 ldr r3, [pc, r3]
 *   @0x1693b8 vadd.f32 s16, s18, s16
 *   @0x1693bc vadd.f32 s17, s17, s15
 *   @0x1693c0 vsub.f32 s19, s19, s15
 *   @0x1693c4 vsub.f32 s18, s18, s15
 *   @0x1693c8 vadd.f32 s15, s16, s15
 *   @0x1693cc vcvt.s32.f32 s19, s19
 *   @0x1693d0 vcvt.s32.f32 s18, s18
 *   @0x1693d4 vstr s19, [r3]
 *   @0x1693d8 vcvt.s32.f32 s17, s17
 *   @0x1693dc vstr s18, [r3, #4]
 *   @0x1693e0 vcvt.s32.f32 s15, s15
 *   @0x1693e4 vstr s17, [r3, #8]
 *   @0x1693e8 vpop {d8, d9, d10}
 *   @0x1693ec vstr s15, [r3, #12]
 *   @0x1693f0 pop {r3, pc}
 *   @0x1693f4 blo 0xfe22ddb8 <b2_toiTime+0xfffffffffdad4914>
 *   @0x1693f8 vstmialo lr, {s30, s31}
 *   @0x1693fc svclo #0x7fbe77
 *   @0x169400 eoreq r6, r8, r4, lsl lr
 *   @0x169404 mlaeq r8, r8, sp, r6
 *
 * ══ §75/91 HandleShape  0x1a4df4  size 292  73 条（0x1a4df4..0x1a4f18）
 * @func 0x1a4df4 0x1a4f18  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleShape(int)+0x110×2 / Compute_Color(RParticle&)
 * 字段偏移 top8: 0x4×4 / 0x2×3 / 0x8×3 / 0x114×1 / 0xf4×1 / 0xc×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4df4 ldr r3, [pc, #0x114]
 *   @0x1a4df8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a4dfc vpush {d8, d9}
 *   @0x1a4e00 ldr r3, [pc, r3]
 *   @0x1a4e04 ldr r3, [r3, #0x4]
 *   @0x1a4e08 ldr r7, [r3, r0, lsl #2]
 *   @0x1a4e0c ldr r3, [r7, #0x8]
 *   @0x1a4e10 cmp r3, #0
 *   @0x1a4e14 ble 0x1a4f04 <_Z11HandleShapei+0x110>
 *   @0x1a4e18 ldr r8, [pc, #0xf4]
 *   @0x1a4e1c vmov.f32 s16, #1.000000e+00
 *   @0x1a4e20 mov r6, #0
 *   @0x1a4e24 vldr s17, [pc, #224]
 *   @0x1a4e28 ldr r8, [pc, r8]
 *   @0x1a4e2c vmov.f32 s18, #2.000000e+00
 *   @0x1a4e30 b 0x1a4e84 <_Z11HandleShapei+0x90>
 *   @0x1a4e34 vmov s15, r3
 *   @0x1a4e38 vcvt.f32.s32 s13, s15
 *   @0x1a4e3c vldr s15, [r4, #8]
 *   @0x1a4e40 vcvt.f32.s32 s14, s15
 *   @0x1a4e44 vadd.f32 s14, s14, s14
 *   @0x1a4e48 vdiv.f32 s15, s14, s13
 *   @0x1a4e4c vcmpe.f32 s15, s16
 *   @0x1a4e50 vmrs APSR_nzcv, fpscr
 *   @0x1a4e54 bmi 0x1a4edc <_Z11HandleShapei+0xe8>
 *   @0x1a4e58 vsub.f32 s12, s18, s15
 *   @0x1a4e5c vsub.f32 s15, s15, s16
 *   @0x1a4e60 vldr s13, [r5, #156]
 *   @0x1a4e64 vldr s14, [r5, #152]
 *   @0x1a4e68 ldr r3, [r7, #0x8]
 *   @0x1a4e6c vmul.f32 s15, s15, s13
 *   @0x1a4e70 vmla.f32 s15, s12, s14
 *   @0x1a4e74 vstr s15, [r4, #48]
 *   @0x1a4e78 add r6, r6, #1
 *   @0x1a4e7c cmp r3, r6
 *   @0x1a4e80 ble 0x1a4f04 <_Z11HandleShapei+0x110>
 *   @0x1a4e84 ldr r1, [r7, #0x4]
 *   @0x1a4e88 ldr r2, [r8, #0x4]
 *   @0x1a4e8c ldr r4, [r1, r6, lsl #2]
 *   @0x1a4e90 ldr r1, [r4, #0x4]
 *   @0x1a4e94 mov r0, r4
 *   @0x1a4e98 ldr r5, [r2, r1, lsl #2]
 *   @0x1a4e9c cmp r5, #0
 *   @0x1a4ea0 beq 0x1a4e78 <_Z11HandleShapei+0x84>
 *   @0x1a4ea4 vldr s14, [r4, #52]
 *   @0x1a4ea8 vldr s15, [r5, #20]
 *   @0x1a4eac vadd.f32 s15, s14, s15
 *   @0x1a4eb0 vcmpe.f32 s15, #0
 *   @0x1a4eb4 vmrs APSR_nzcv, fpscr
 *   @0x1a4eb8 vmovmi.f32 s15, s17
 *   @0x1a4ebc vstr s15, [r4, #52]
 *   @0x1a4ec0 bl 0x1a2a98 <_Z13Compute_ColorR9RParticle>
 *   @0x1a4ec4 ldr r3, [r4, #0xc]
 *   @0x1a4ec8 cmp r3, #0
 *   @0x1a4ecc bgt 0x1a4e34 <_Z11HandleShapei+0x40>
 *   @0x1a4ed0 vmov.f32 s12, #1.000000e+00
 *   @0x1a4ed4 vldr s15, [pc, #48]
 *   @0x1a4ed8 b 0x1a4e60 <_Z11HandleShapei+0x6c>
 *   @0x1a4edc vldr s14, [r5, #152]
 *   @0x1a4ee0 vmul.f32 s14, s15, s14
 *   @0x1a4ee4 vldr s13, [r5, #148]
 *   @0x1a4ee8 ldr r3, [r7, #0x8]
 *   @0x1a4eec add r6, r6, #1
 *   @0x1a4ef0 cmp r3, r6
 *   @0x1a4ef4 vsub.f32 s15, s16, s15
 *   @0x1a4ef8 vmla.f32 s14, s15, s13
 *   @0x1a4efc vstr s14, [r4, #48]
 *   @0x1a4f00 bgt 0x1a4e84 <_Z11HandleShapei+0x90>
 *   @0x1a4f04 vpop {d8, d9}
 *   @0x1a4f08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a4f0c andeq r0, r0, r0
 *   @0x1a4f10 .word 0x0024b9b8
 *   @0x1a4f14 eoreq r11, r4, r4, lsl #19
 *
 * ══ §76/91 Variable_Scope_DeleteVar  0x1f34bc  size 292  73 条（0x1f34bc..0x1f35e0）
 * @func 0x1f34bc 0x1f35e0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×2 / GET_RValue(RValue*, RValue*, int) / Code_Variable_Find_Name(char const*, int, int) / PushContextStack(YYObjectBase*) / SET_RValue(RValue*, RValue*, int) / PopContextStack()
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x118×1 / 0x24×1 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f34bc ldr r3, [pc, #0x118]
 *   @0x1f34c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f34c4 ldr r3, [pc, r3]
 *   @0x1f34c8 sub sp, sp, #36
 *   @0x1f34cc mov r10, r0
 *   @0x1f34d0 ldr r6, [r3]
 *   @0x1f34d4 mov r7, r1
 *   @0x1f34d8 cmp r6, #0
 *   @0x1f34dc beq 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8>
 *   @0x1f34e0 sub r9, r0, #99328
 *   @0x1f34e4 mov r11, #0
 *   @0x1f34e8 sub r9, r9, #672
 *   @0x1f34ec mvn r4, #-16777216
 *   @0x1f34f0 lsl r8, r9, #4
 *   @0x1f34f4 b 0x1f3504 <_Z24Variable_Scope_DeleteVarii+0x48>
 *   @0x1f34f8 ldr r6, [r6, #0xc]
 *   @0x1f34fc cmp r6, #0
 *   @0x1f3500 beq 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8>
 *   @0x1f3504 ldr r3, [r6, #0x24]
 *   @0x1f3508 cmp r3, #0
 *   @0x1f350c beq 0x1f353c <_Z24Variable_Scope_DeleteVarii+0x80>
 *   @0x1f3510 ldr r1, [r6, #0x4]
 *   @0x1f3514 cmp r1, #0
 *   @0x1f3518 add r1, r1, r8
 *   @0x1f351c beq 0x1f3570 <_Z24Variable_Scope_DeleteVarii+0xb4>
 *   @0x1f3520 mov r2, r7
 *   @0x1f3524 mov r0, sp
 *   @0x1f3528 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f352c ldr r3, [sp, #0xc]
 *   @0x1f3530 mvn r2, #-16777216
 *   @0x1f3534 cmp r3, r4
 *   @0x1f3538 bne 0x1f3584 <_Z24Variable_Scope_DeleteVarii+0xc8>
 *   @0x1f353c cmp r11, #0
 *   @0x1f3540 bne 0x1f34f8 <_Z24Variable_Scope_DeleteVarii+0x3c>
 *   @0x1f3544 mov r0, r11
 *   @0x1f3548 mvn r1, #10
 *   @0x1f354c mov r2, r10
 *   @0x1f3550 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x1f3554 ldr r6, [r6, #0xc]
 *   @0x1f3558 cmp r6, #0
 *   @0x1f355c mov r11, r0
 *   @0x1f3560 bne 0x1f3504 <_Z24Variable_Scope_DeleteVarii+0x48>
 *   @0x1f3564 mov r0, #1
 *   @0x1f3568 add sp, sp, #36
 *   @0x1f356c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f3570 mov r1, r9
 *   @0x1f3574 mov r0, r6
 *   @0x1f3578 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f357c mov r1, r0
 *   @0x1f3580 b 0x1f3520 <_Z24Variable_Scope_DeleteVarii+0x64>
 *   @0x1f3584 ldr r0, [sp, #0x8]
 *   @0x1f3588 ands r0, r0, #2
 *   @0x1f358c beq 0x1f3568 <_Z24Variable_Scope_DeleteVarii+0xac>
 *   @0x1f3590 mov r0, r6
 *   @0x1f3594 str r2, [sp, #0x1c]
 *   @0x1f3598 mov r4, #0
 *   @0x1f359c mov r5, #0
 *   @0x1f35a0 strd r4, r5, [sp, #16]
 *   @0x1f35a4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x1f35a8 ldr r3, [r6, #0x4]
 *   @0x1f35ac cmp r3, #0
 *   @0x1f35b0 beq 0x1f35cc <_Z24Variable_Scope_DeleteVarii+0x110>
 *   @0x1f35b4 add r0, r3, r8
 *   @0x1f35b8 mov r2, r7
 *   @0x1f35bc add r1, sp, #16
 *   @0x1f35c0 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f35c4 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x1f35c8 b 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8>
 *   @0x1f35cc mov r0, r6
 *   @0x1f35d0 mov r1, r9
 *   @0x1f35d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f35d8 b 0x1f35b8 <_Z24Variable_Scope_DeleteVarii+0xfc>
 *   @0x1f35dc andseq r10, pc, r4, ror #15
 *
 * ══ §77/91 vorbis_dsp_clear  0x2272ac  size 292  73 条（0x2272ac..0x2273d0）
 * @func 0x2272ac 0x2273d0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×5 / vorbis_dsp_clear+0x60 / vorbis_dsp_clear+0x110
 * 字段偏移 top8: 0xc×6 / 0x4×4 / 0x8×4 / 0x2×4 / 0x48×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2272ac push {r4, r5, r6, r7, r8, lr}
 *   @0x2272b0 subs r7, r0, #0
 *   @0x2272b4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2272b8 ldr r5, [r7, #0x4]
 *   @0x2272bc ldr r3, [r7, #0x8]
 *   @0x2272c0 cmp r5, #0
 *   @0x2272c4 ldr r6, [r7, #0x48]
 *   @0x2272c8 ldrne r8, [r5, #0x1c]
 *   @0x2272cc moveq r8, r5
 *   @0x2272d0 cmp r3, #0
 *   @0x2272d4 beq 0x227324 <vorbis_dsp_clear+0x78>
 *   @0x2272d8 ldr r2, [r5, #0x4]
 *   @0x2272dc cmp r2, #0
 *   @0x2272e0 ble 0x22730c <vorbis_dsp_clear+0x60>
 *   @0x2272e4 mov r4, #0
 *   @0x2272e8 ldr r0, [r3, r4, lsl #2]
 *   @0x2272ec add r4, r4, #1
 *   @0x2272f0 cmp r0, #0
 *   @0x2272f4 beq 0x227304 <vorbis_dsp_clear+0x58>
 *   @0x2272f8 bl 0xb655c <free@plt>
 *   @0x2272fc ldr r3, [r7, #0x8]
 *   @0x227300 ldr r2, [r5, #0x4]
 *   @0x227304 cmp r2, r4
 *   @0x227308 bgt 0x2272e8 <vorbis_dsp_clear+0x3c>
 *   @0x22730c mov r0, r3
 *   @0x227310 bl 0xb655c <free@plt>
 *   @0x227314 ldr r0, [r7, #0xc]
 *   @0x227318 cmp r0, #0
 *   @0x22731c beq 0x227324 <vorbis_dsp_clear+0x78>
 *   @0x227320 bl 0xb655c <free@plt>
 *   @0x227324 cmp r8, #0
 *   @0x227328 beq 0x2273bc <vorbis_dsp_clear+0x110>
 *   @0x22732c ldr r0, [r8, #0x8]
 *   @0x227330 cmp r0, #0
 *   @0x227334 ble 0x2273bc <vorbis_dsp_clear+0x110>
 *   @0x227338 cmp r6, #0
 *   @0x22733c beq 0x2273a8 <vorbis_dsp_clear+0xfc>
 *   @0x227340 ldr r2, [r6, #0xc]
 *   @0x227344 add r5, r8, #28
 *   @0x227348 mov r4, #0
 *   @0x22734c ldr r1, [r5, #0x4]!
 *   @0x227350 cmp r2, #0
 *   @0x227354 ldr r3, [pc, #0x70]
 *   @0x227358 ldr r1, [r1, #0xc]
 *   @0x22735c add r1, r1, #72
 *   @0x227360 ldr r1, [r8, r1, lsl #2]
 *   @0x227364 beq 0x227384 <vorbis_dsp_clear+0xd8>
 *   @0x227368 ldr r3, [pc, r3]
 *   @0x22736c ldr r0, [r2, r4, lsl #2]
 *   @0x227370 ldr r3, [r3, r1, lsl #2]
 *   @0x227374 ldr r3, [r3, #0xc]
 *   @0x227378 blx r3
 *   @0x22737c ldr r0, [r8, #0x8]
 *   @0x227380 ldr r2, [r6, #0xc]
 *   @0x227384 add r4, r4, #1
 *   @0x227388 cmp r0, r4
 *   @0x22738c bgt 0x22734c <vorbis_dsp_clear+0xa0>
 *   @0x227390 cmp r2, #0
 *   @0x227394 beq 0x2273a0 <vorbis_dsp_clear+0xf4>
 *   @0x227398 mov r0, r2
 *   @0x22739c bl 0xb655c <free@plt>
 *   @0x2273a0 mov r0, r6
 *   @0x2273a4 bl 0xb655c <free@plt>
 *   @0x2273a8 mov r0, r7
 *   @0x2273ac mov r1, #0
 *   @0x2273b0 mov r2, #80
 *   @0x2273b4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2273b8 b 0xb65b0 <memset@plt>
 *   @0x2273bc cmp r6, #0
 *   @0x2273c0 beq 0x2273a8 <vorbis_dsp_clear+0xfc>
 *   @0x2273c4 ldr r2, [r6, #0xc]
 *   @0x2273c8 b 0x227390 <vorbis_dsp_clear+0xe4>
 *   @0x2273cc andseq r10, r12, r8, lsl r1
 *
 * ══ §78/91 MemoryManager::_Alloc  0x27cd54  size 292  73 条（0x27cd54..0x27ce78）
 * @func 0x27cd54 0x27ce78  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27cd64→0x756780, 0x27cddc→0x756758, 0x27ce08→0x756754, 0x27ce0c→0x75674c, 0x27ce14→0x756748
 * 调用序列: Mutex::Lock() / bucketAlloc(unsigned int, bool) / Mutex::Unlock() / 0xb6544 / anon_27b918
 * 字段偏移 top8: 0x5c×2 / 0xfc×1 / 0xf8×1 / 0x84×1 / 0xc×1 / 0x4×1 / 0x8×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27cd54 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x27cd58 mov r7, r0
 *   @0x27cd5c ldr r8, [pc, #0xfc]
 *   @0x27cd60 mov r4, r3
 *   @0x27cd64 ldr r2, [pc, #0xf8]
 *   @0x27cd68 add r8, pc, r8
 *   @0x27cd6c ldr r6, [r8, r2]
 *   @0x27cd70 ldr r0, [r6]
 *   @0x27cd74 cmp r0, #0
 *   @0x27cd78 beq 0x27ce54 <_ZN13MemoryManager6_AllocEjPKcib+0x100>
 *   @0x27cd7c bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27cd80 mov r1, r4
 *   @0x27cd84 mov r0, r7
 *   @0x27cd88 bl 0x27c53c <_Z11bucketAllocjb>
 *   @0x27cd8c subs r9, r0, #0
 *   @0x27cd90 movne r4, r9
 *   @0x27cd94 beq 0x27cda8 <_ZN13MemoryManager6_AllocEjPKcib+0x54>
 *   @0x27cd98 ldr r0, [r6]
 *   @0x27cd9c bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27cda0 mov r0, r4
 *   @0x27cda4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x27cda8 adds r0, r7, #16
 *   @0x27cdac mov r3, #0
 *   @0x27cdb0 adc r1, r3, #0
 *   @0x27cdb4 mvn r4, #1
 *   @0x27cdb8 mov r5, #0
 *   @0x27cdbc cmp r4, r0
 *   @0x27cdc0 sbcs r3, r5, r1
 *   @0x27cdc4 bge 0x27cdd0 <_ZN13MemoryManager6_AllocEjPKcib+0x7c>
 *   @0x27cdc8 mov r4, #0
 *   @0x27cdcc b 0x27cd98 <_ZN13MemoryManager6_AllocEjPKcib+0x44>
 *   @0x27cdd0 bl 0xb6544 <malloc@plt>
 *   @0x27cdd4 cmp r0, #0
 *   @0x27cdd8 beq 0x27cdc8 <_ZN13MemoryManager6_AllocEjPKcib+0x74>
 *   @0x27cddc ldr r1, [pc, #0x84]
 *   @0x27cde0 movw r2, #0xc0de
 *   @0x27cde4 str r7, [r0]
 *   @0x27cde8 movt r2, #0xdead
 *   @0x27cdec str r9, [r0, #0xc]
 *   @0x27cdf0 movw r3, #0xb00b
 *   @0x27cdf4 str r2, [r0, #0x4]
 *   @0x27cdf8 movt r3, #0xbaad
 *   @0x27cdfc str r3, [r0, #0x8]
 *   @0x27ce00 add r4, r0, #16
 *   @0x27ce04 ldr r3, [r8, r1]
 *   @0x27ce08 ldr r0, [pc, #0x5c]
 *   @0x27ce0c ldr r1, [pc, #0x5c]
 *   @0x27ce10 ldr r12, [r3]
 *   @0x27ce14 ldr r2, [pc, #0x58]
 *   @0x27ce18 add r12, r7, r12
 *   @0x27ce1c str r12, [r3]
 *   @0x27ce20 ldr r3, [r8, r0]
 *   @0x27ce24 ldr r0, [r3]
 *   @0x27ce28 add r0, r7, r0
 *   @0x27ce2c str r0, [r3]
 *   @0x27ce30 ldr r3, [r8, r1]
 *   @0x27ce34 ldr r1, [r3]
 *   @0x27ce38 add r1, r1, #1
 *   @0x27ce3c str r1, [r3]
 *   @0x27ce40 ldr r3, [r8, r2]
 *   @0x27ce44 ldr r2, [r3]
 *   @0x27ce48 add r7, r7, r2
 *   @0x27ce4c str r7, [r3]
 *   @0x27ce50 b 0x27cd98 <_ZN13MemoryManager6_AllocEjPKcib+0x44>
 *   @0x27ce54 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27ce58 ldr r0, [r6]
 *   @0x27ce5c b 0x27cd7c <_ZN13MemoryManager6_AllocEjPKcib+0x28>
 *   @0x27ce60 andseq r4, r7, r8, ror #29
 *   @0x27ce64 .word 0xfffffbcc
 *   @0x27ce68 .word 0xffffe788
 *   @0x27ce6c .word 0xffffe794
 *   @0x27ce70 .word 0xfffffc04
 *   @0x27ce74 .word 0xffffe790
 *
 * ══ §79/91 RelySendAckPacket  0x29a1a4  size 292  73 条（0x29a1a4..0x29a2c8）
 * @func 0x29a1a4 0x29a2c8  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)×3 / GetIBuffer(int)×2 / CreateBuffer(int, eBuffer_Format, int) / CalcCRC(char const*, int) / RelySendData(int, char const*, int, int, int) / RelyAddPacket(int, char const*, int, unsigned int, int)
 * 字段偏移 top8: 0x10×6 / 0xc×4 / 0x14×2 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a1a4 ldr r12, [pc, #0x118]
 *   @0x29a1a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29a1ac ldr r12, [pc, r12]
 *   @0x29a1b0 mov r7, r0
 *   @0x29a1b4 mov r0, r3
 *   @0x29a1b8 ldr r3, [r12]
 *   @0x29a1bc sub sp, sp, #28
 *   @0x29a1c0 mov r5, #0
 *   @0x29a1c4 mov r10, r1
 *   @0x29a1c8 mov r9, r2
 *   @0x29a1cc add r1, r3, #1
 *   @0x29a1d0 str r3, [sp, #0x14]
 *   @0x29a1d4 mov r2, #2
 *   @0x29a1d8 str r1, [r12]
 *   @0x29a1dc add r11, sp, #12
 *   @0x29a1e0 str r5, [sp, #0x10]
 *   @0x29a1e4 str r5, [sp, #0xc]
 *   @0x29a1e8 strb r2, [sp, #0x10]
 *   @0x29a1ec bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29a1f0 mov r1, #3
 *   @0x29a1f4 mov r2, #1
 *   @0x29a1f8 mov r6, r0
 *   @0x29a1fc ldr r0, [r0, #0x10]
 *   @0x29a200 add r0, r0, #12
 *   @0x29a204 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0x29a208 mov r8, r0
 *   @0x29a20c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29a210 mov r1, r11
 *   @0x29a214 mov r2, #1
 *   @0x29a218 mov r3, #12
 *   @0x29a21c mov r4, r0
 *   @0x29a220 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a224 ldr r3, [r6, #0x10]
 *   @0x29a228 mov r2, #1
 *   @0x29a22c ldr r1, [r6, #0xc]
 *   @0x29a230 mov r0, r4
 *   @0x29a234 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a238 ldr r0, [r4, #0xc]
 *   @0x29a23c ldr r1, [r4, #0x10]
 *   @0x29a240 add r0, r0, #4
 *   @0x29a244 sub r1, r1, #4
 *   @0x29a248 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x29a24c ldr r3, [r4]
 *   @0x29a250 mov r1, r5
 *   @0x29a254 mov r2, r5
 *   @0x29a258 ldr r3, [r3, #0x10]
 *   @0x29a25c str r0, [sp, #0xc]
 *   @0x29a260 mov r0, r4
 *   @0x29a264 blx r3
 *   @0x29a268 mov r1, r11
 *   @0x29a26c mov r0, r4
 *   @0x29a270 mov r2, #1
 *   @0x29a274 mov r3, #12
 *   @0x29a278 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a27c mov r1, r10
 *   @0x29a280 mov r2, r9
 *   @0x29a284 mov r3, r8
 *   @0x29a288 mvn r12, #0
 *   @0x29a28c mov r0, r7
 *   @0x29a290 str r12, [sp]
 *   @0x29a294 bl 0x299ff8 <_Z12RelySendDataiPKciii>
 *   @0x29a298 ldr r12, [sp, #0x14]
 *   @0x29a29c mov r1, r10
 *   @0x29a2a0 mov r2, r9
 *   @0x29a2a4 mov r3, r8
 *   @0x29a2a8 str r12, [sp]
 *   @0x29a2ac mov r4, r0
 *   @0x29a2b0 mov r0, r7
 *   @0x29a2b4 bl 0x299afc <_Z13RelyAddPacketiPKciji>
 *   @0x29a2b8 mov r0, r4
 *   @0x29a2bc add sp, sp, #28
 *   @0x29a2c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29a2c4 andseq r7, r5, r0, asr r8
 *
 * ══ §80/91 b2ParticleSystem::UpdateBodyContacts  0x2d5b9c  size 292  73 条（0x2d5b9c..0x2d5cc0）
 * @func 0x2d5b9c 0x2d5cc0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::UpdateBodyContacts()+0x104 / b2World::QueryAABB(b2QueryCallback*, b2AABB const&) const
 * 字段偏移 top8: 0x4×2 / 0x24×1 / 0x-4×1 / 0x38×1 / 0x64×1 / 0xd4×1 / 0x80×1
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5b9c ldr r2, [r0, #0x24]
 *   @0x2d5ba0 vldr s13, [pc, #268]
 *   @0x2d5ba4 str lr, [sp, #-0x4]!
 *   @0x2d5ba8 vldr s12, [pc, #264]
 *   @0x2d5bac cmp r2, #0
 *   @0x2d5bb0 sub sp, sp, #28
 *   @0x2d5bb4 mov r12, r0
 *   @0x2d5bb8 vstr s13, [sp, #8]
 *   @0x2d5bbc vstr s13, [sp, #12]
 *   @0x2d5bc0 vstr s12, [sp, #16]
 *   @0x2d5bc4 vstr s12, [sp, #20]
 *   @0x2d5bc8 ble 0x2d5ca0 <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0x104>
 *   @0x2d5bcc ldr r3, [r0, #0x38]
 *   @0x2d5bd0 vmov.f32 s8, s12
 *   @0x2d5bd4 add r2, r3, r2, lsl #3
 *   @0x2d5bd8 vmov.f32 s9, s13
 *   @0x2d5bdc vldr s14, [r3]
 *   @0x2d5be0 vldr s15, [r3, #4]
 *   @0x2d5be4 add r3, r3, #8
 *   @0x2d5be8 vcmpe.f32 s14, s9
 *   @0x2d5bec vmrs APSR_nzcv, fpscr
 *   @0x2d5bf0 vcmpe.f32 s15, s13
 *   @0x2d5bf4 vmovle.f32 s11, s14
 *   @0x2d5bf8 vmovgt.f32 s11, s9
 *   @0x2d5bfc vmrs APSR_nzcv, fpscr
 *   @0x2d5c00 vstr s11, [sp, #8]
 *   @0x2d5c04 vcmpe.f32 s14, s8
 *   @0x2d5c08 vmovle.f32 s10, s15
 *   @0x2d5c0c vmovgt.f32 s10, s13
 *   @0x2d5c10 vmrs APSR_nzcv, fpscr
 *   @0x2d5c14 vstr s10, [sp, #12]
 *   @0x2d5c18 vcmpe.f32 s15, s12
 *   @0x2d5c1c vmovmi.f32 s14, s8
 *   @0x2d5c20 vmrs APSR_nzcv, fpscr
 *   @0x2d5c24 vstr s14, [sp, #16]
 *   @0x2d5c28 vmovmi.f32 s15, s12
 *   @0x2d5c2c cmp r3, r2
 *   @0x2d5c30 vstr s15, [sp, #20]
 *   @0x2d5c34 vmov.f32 s9, s11
 *   @0x2d5c38 vmov.f32 s13, s10
 *   @0x2d5c3c vmov.f32 s8, s14
 *   @0x2d5c40 vmov.f32 s12, s15
 *   @0x2d5c44 bne 0x2d5bdc <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0x40>
 *   @0x2d5c48 vldr s9, [r12, #24]
 *   @0x2d5c4c vsub.f32 s11, s11, s9
 *   @0x2d5c50 ldr r3, [pc, #0x64]
 *   @0x2d5c54 mov r2, #0
 *   @0x2d5c58 ldr r0, [r12, #0xd4]
 *   @0x2d5c5c mov r1, sp
 *   @0x2d5c60 str r2, [r12, #0x80]
 *   @0x2d5c64 add r3, pc, r3
 *   @0x2d5c68 add r2, sp, #8
 *   @0x2d5c6c add r3, r3, #32
 *   @0x2d5c70 str r12, [sp, #0x4]
 *   @0x2d5c74 str r3, [sp]
 *   @0x2d5c78 vsub.f32 s10, s10, s9
 *   @0x2d5c7c vstr s11, [sp, #8]
 *   @0x2d5c80 vadd.f32 s14, s9, s14
 *   @0x2d5c84 vstr s10, [sp, #12]
 *   @0x2d5c88 vadd.f32 s15, s9, s15
 *   @0x2d5c8c vstr s14, [sp, #16]
 *   @0x2d5c90 vstr s15, [sp, #20]
 *   @0x2d5c94 bl 0x2cb89c <_ZNK7b2World9QueryAABBEP15b2QueryCallbackRK6b2AABB>
 *   @0x2d5c98 add sp, sp, #28
 *   @0x2d5c9c ldr pc, [sp], #4
 *   @0x2d5ca0 vmov.f32 s15, s12
 *   @0x2d5ca4 vmov.f32 s10, s13
 *   @0x2d5ca8 vmov.f32 s14, s12
 *   @0x2d5cac vmov.f32 s11, s13
 *   @0x2d5cb0 b 0x2d5c48 <_ZN16b2ParticleSystem18UpdateBodyContactsEv+0xac>
 *   @0x2d5cb4 svcvc #0x7fffff
 *   @0x2d5cb8 .word 0xff7fffff
 *   @0x2d5cbc andseq r6, r1, r4, asr #20
 *
 * ══ §81/91 b2ParticleSystem::SolveSpring  0x2d620c  size 292  73 条（0x2d620c..0x2d6330）
 * @func 0x2d620c 0x2d6330  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveSpring(b2TimeStep const&)+0x108×2 / 0xb6700
 * 字段偏移 top8: 0x8c×2 / 0x94×1 / 0x8×1 / 0x4×1 / 0x38×1 / 0x40×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d620c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d6210 vpush {d8, d9}
 *   @0x2d6214 vldr s19, [r1, #4]
 *   @0x2d6218 vldr s15, [r0, #184]
 *   @0x2d621c ldr r1, [r0, #0x8c]
 *   @0x2d6220 mov r7, r0
 *   @0x2d6224 vmul.f32 s19, s19, s15
 *   @0x2d6228 cmp r1, #0
 *   @0x2d622c ble 0x2d6314 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x108>
 *   @0x2d6230 mov r4, #0
 *   @0x2d6234 mov r5, r4
 *   @0x2d6238 b 0x2d6248 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x3c>
 *   @0x2d623c cmp r1, r5
 *   @0x2d6240 add r4, r4, #20
 *   @0x2d6244 ble 0x2d6314 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x108>
 *   @0x2d6248 ldr r3, [r7, #0x94]
 *   @0x2d624c add r5, r5, #1
 *   @0x2d6250 add r6, r3, r4
 *   @0x2d6254 ldr r2, [r6, #0x8]
 *   @0x2d6258 tst r2, #8
 *   @0x2d625c beq 0x2d623c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x30>
 *   @0x2d6260 ldr r2, [r3, r4]
 *   @0x2d6264 vldr s18, [r6, #16]
 *   @0x2d6268 ldr r8, [r6, #0x4]
 *   @0x2d626c ldr r0, [r7, #0x38]
 *   @0x2d6270 lsl r9, r2, #3
 *   @0x2d6274 lsl r8, r8, #3
 *   @0x2d6278 add r3, r0, r9
 *   @0x2d627c add r0, r0, r8
 *   @0x2d6280 vldr s15, [r3, #4]
 *   @0x2d6284 vldr s16, [r0, #4]
 *   @0x2d6288 vsub.f32 s16, s16, s15
 *   @0x2d628c vldr s17, [r0]
 *   @0x2d6290 vldr s15, [r3]
 *   @0x2d6294 vmul.f32 s14, s16, s16
 *   @0x2d6298 vsub.f32 s17, s17, s15
 *   @0x2d629c vmla.f32 s14, s17, s17
 *   @0x2d62a0 vsqrt.f32 s15, s14
 *   @0x2d62a4 vcmp.f32 s15, s15
 *   @0x2d62a8 vmrs APSR_nzcv, fpscr
 *   @0x2d62ac bne 0x2d631c <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x110>
 *   @0x2d62b0 vldr s12, [r6, #12]
 *   @0x2d62b4 vmul.f32 s12, s19, s12
 *   @0x2d62b8 ldr r3, [r7, #0x40]
 *   @0x2d62bc cmp r1, r5
 *   @0x2d62c0 add r4, r4, #20
 *   @0x2d62c4 add r2, r3, r9
 *   @0x2d62c8 vldr s13, [r2]
 *   @0x2d62cc vldr s14, [r2, #4]
 *   @0x2d62d0 add r3, r3, r8
 *   @0x2d62d4 vsub.f32 s18, s18, s15
 *   @0x2d62d8 vmul.f32 s18, s18, s12
 *   @0x2d62dc vdiv.f32 s15, s18, s15
 *   @0x2d62e0 vmul.f32 s16, s15, s16
 *   @0x2d62e4 vmul.f32 s17, s15, s17
 *   @0x2d62e8 vsub.f32 s14, s14, s16
 *   @0x2d62ec vsub.f32 s15, s13, s17
 *   @0x2d62f0 vstr s15, [r2]
 *   @0x2d62f4 vldr s15, [r3]
 *   @0x2d62f8 vstr s14, [r2, #4]
 *   @0x2d62fc vadd.f32 s17, s15, s17
 *   @0x2d6300 vldr s15, [r3, #4]
 *   @0x2d6304 vadd.f32 s16, s15, s16
 *   @0x2d6308 vstr s17, [r3]
 *   @0x2d630c vstr s16, [r3, #4]
 *   @0x2d6310 bgt 0x2d6248 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0x3c>
 *   @0x2d6314 vpop {d8, d9}
 *   @0x2d6318 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d631c vmov r0, s14
 *   @0x2d6320 bl 0xb6700 <sqrtf@plt>
 *   @0x2d6324 ldr r1, [r7, #0x8c]
 *   @0x2d6328 vmov s15, r0
 *   @0x2d632c b 0x2d62b0 <_ZN16b2ParticleSystem11SolveSpringERK10b2TimeStep+0xa4>
 *
 * ══ §82/91 b2ContactSolver::WarmStart  0x2e27d0  size 292  73 条（0x2e27d0..0x2e28f4）
 * @func 0x2e27d0 0x2e28f4  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ContactSolver::WarmStart()+0x118 / b2ContactSolver::WarmStart()+0xf0
 * 字段偏移 top8: 0x30×1 / 0x28×1 / 0x1c×1 / 0x70×1 / 0x74×1 / 0x94×1
 * VFP 指令 41 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e27d0 ldr r3, [r0, #0x30]
 *   @0x2e27d4 push {r4, r5, r6, r7, r8}
 *   @0x2e27d8 vpush {d8, d9}
 *   @0x2e27dc cmp r3, #0
 *   @0x2e27e0 ble 0x2e28e8 <_ZN15b2ContactSolver9WarmStartEv+0x118>
 *   @0x2e27e4 ldr r12, [r0, #0x28]
 *   @0x2e27e8 mov r8, #156
 *   @0x2e27ec ldr r7, [r0, #0x1c]
 *   @0x2e27f0 add r6, r12, #148
 *   @0x2e27f4 mla r8, r8, r3, r12
 *   @0x2e27f8 ldr r5, [r12, #0x70]
 *   @0x2e27fc vldr s16, [r12, #72]
 *   @0x2e2800 ldr r4, [r12, #0x74]
 *   @0x2e2804 vneg.f32 s19, s16
 *   @0x2e2808 ldr r0, [r12, #0x94]
 *   @0x2e280c vldr s4, [r6, #-28]
 *   @0x2e2810 add r5, r5, r5, lsl #1
 *   @0x2e2814 vldr s17, [r6, #-20]
 *   @0x2e2818 add r4, r4, r4, lsl #1
 *   @0x2e281c cmp r0, #0
 *   @0x2e2820 add r5, r7, r5, lsl #2
 *   @0x2e2824 vldr s3, [r6, #-24]
 *   @0x2e2828 add r4, r7, r4, lsl #2
 *   @0x2e282c vldr s5, [r5]
 *   @0x2e2830 vldr s6, [r5, #4]
 *   @0x2e2834 vldr s7, [r5, #8]
 *   @0x2e2838 vldr s18, [r6, #-16]
 *   @0x2e283c vldr s8, [r4]
 *   @0x2e2840 vldr s9, [r4, #4]
 *   @0x2e2844 vldr s10, [r4, #8]
 *   @0x2e2848 vldr s2, [r12, #76]
 *   @0x2e284c ble 0x2e28c0 <_ZN15b2ContactSolver9WarmStartEv+0xf0>
 *   @0x2e2850 add r2, r12, #8
 *   @0x2e2854 add r3, r12, #16
 *   @0x2e2858 mov r1, #0
 *   @0x2e285c vldr s15, [r3, #4]
 *   @0x2e2860 vmul.f32 s14, s15, s2
 *   @0x2e2864 vldr s11, [r3]
 *   @0x2e2868 vldr s12, [r3, #-12]
 *   @0x2e286c vldr s13, [r2, #4]
 *   @0x2e2870 vldr s0, [r3, #-16]
 *   @0x2e2874 vldr s1, [r2]
 *   @0x2e2878 add r1, r1, #1
 *   @0x2e287c cmp r1, r0
 *   @0x2e2880 add r3, r3, #36
 *   @0x2e2884 add r2, r2, #36
 *   @0x2e2888 vmla.f32 s14, s11, s16
 *   @0x2e288c vmul.f32 s15, s15, s19
 *   @0x2e2890 vmla.f32 s15, s11, s2
 *   @0x2e2894 vmul.f32 s12, s14, s12
 *   @0x2e2898 vmul.f32 s13, s14, s13
 *   @0x2e289c vnmls.f32 s12, s15, s0
 *   @0x2e28a0 vnmls.f32 s13, s15, s1
 *   @0x2e28a4 vmls.f32 s5, s4, s14
 *   @0x2e28a8 vmls.f32 s6, s4, s15
 *   @0x2e28ac vmla.f32 s8, s3, s14
 *   @0x2e28b0 vmla.f32 s9, s3, s15
 *   @0x2e28b4 vmls.f32 s7, s17, s12
 *   @0x2e28b8 vmla.f32 s10, s18, s13
 *   @0x2e28bc bne 0x2e285c <_ZN15b2ContactSolver9WarmStartEv+0x8c>
 *   @0x2e28c0 add r12, r12, #156
 *   @0x2e28c4 vstr s5, [r5]
 *   @0x2e28c8 cmp r12, r8
 *   @0x2e28cc vstr s6, [r5, #4]
 *   @0x2e28d0 vstr s7, [r5, #8]
 *   @0x2e28d4 add r6, r6, #156
 *   @0x2e28d8 vstr s8, [r4]
 *   @0x2e28dc vstr s9, [r4, #4]
 *   @0x2e28e0 vstr s10, [r4, #8]
 *   @0x2e28e4 bne 0x2e27f8 <_ZN15b2ContactSolver9WarmStartEv+0x28>
 *   @0x2e28e8 vpop {d8, d9}
 *   @0x2e28ec pop {r4, r5, r6, r7, r8}
 *   @0x2e28f0 bx lr
 *
 * ══ §83/91 CreateParticle  0x1a2e5c  size 288  72 条（0x1a2e5c..0x1a2f7c）
 * @func 0x1a2e5c 0x1a2f7c  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MyRandom(float, float, int)×5 / YYRandom(int)×2 / ParticleType_Exists(int) / Compute_Color(RParticle&)
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0x3c×2 / 0x24×2 / 0xf0×1 / 0x2×1 / 0x40×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2e5c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a2e60 mov r7, r0
 *   @0x1a2e64 mov r0, r2
 *   @0x1a2e68 mov r6, r2
 *   @0x1a2e6c mov r8, r1
 *   @0x1a2e70 mov r4, r3
 *   @0x1a2e74 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a2e78 cmp r0, #0
 *   @0x1a2e7c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a2e80 ldr r3, [pc, #0xf0]
 *   @0x1a2e84 mov r12, #1
 *   @0x1a2e88 mov r2, #0
 *   @0x1a2e8c ldr r3, [pc, r3]
 *   @0x1a2e90 mov r9, r2
 *   @0x1a2e94 ldr r3, [r3, #0x4]
 *   @0x1a2e98 ldr r5, [r3, r6, lsl #2]
 *   @0x1a2e9c str r7, [r4, #0x10]
 *   @0x1a2ea0 str r6, [r4, #0x4]
 *   @0x1a2ea4 ldr r1, [r5, #0x40]
 *   @0x1a2ea8 ldr r0, [r5, #0x3c]
 *   @0x1a2eac str r8, [r4, #0x14]
 *   @0x1a2eb0 strb r12, [r4]
 *   @0x1a2eb4 str r7, [r4, #0x18]
 *   @0x1a2eb8 str r8, [r4, #0x1c]
 *   @0x1a2ebc bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2ec0 ldr r1, [r5, #0x50]
 *   @0x1a2ec4 mov r2, r9
 *   @0x1a2ec8 str r0, [r4, #0x20]
 *   @0x1a2ecc ldr r0, [r5, #0x4c]
 *   @0x1a2ed0 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2ed4 ldr r1, [r5, #0x68]
 *   @0x1a2ed8 mov r2, r9
 *   @0x1a2edc str r0, [r4, #0x24]
 *   @0x1a2ee0 ldr r0, [r5, #0x64]
 *   @0x1a2ee4 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2ee8 vldr s15, [r5, #40]
 *   @0x1a2eec vcvt.f32.s32 s15, s15
 *   @0x1a2ef0 ldr r3, [r5, #0x24]
 *   @0x1a2ef4 mov r2, r9
 *   @0x1a2ef8 vmov r1, s15
 *   @0x1a2efc vmov s15, r3
 *   @0x1a2f00 vcvt.f32.s32 s15, s15
 *   @0x1a2f04 str r0, [r4, #0x28]
 *   @0x1a2f08 vmov r0, s15
 *   @0x1a2f0c bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2f10 str r9, [r4, #0x8]
 *   @0x1a2f14 vmov s15, r0
 *   @0x1a2f18 mov r0, r4
 *   @0x1a2f1c vcvt.s32.f32 s15, s15
 *   @0x1a2f20 vstr s15, [r4, #12]
 *   @0x1a2f24 bl 0x1a2a98 <_Z13Compute_ColorR9RParticle>
 *   @0x1a2f28 ldr r3, [r5, #0x94]
 *   @0x1a2f2c ldr r0, [r5, #0xc]
 *   @0x1a2f30 mov r2, r9
 *   @0x1a2f34 ldr r1, [r5, #0x10]
 *   @0x1a2f38 str r3, [r4, #0x30]
 *   @0x1a2f3c bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a2f40 ldrb r3, [r5, #0x6]
 *   @0x1a2f44 cmp r3, r9
 *   @0x1a2f48 streq r3, [r4, #0x38]
 *   @0x1a2f4c str r0, [r4, #0x34]
 *   @0x1a2f50 bne 0x1a2f68 <_Z14CreateParticleffiR9RParticle+0x10c>
 *   @0x1a2f54 movw r0, #0x86a0
 *   @0x1a2f58 movt r0, #0x1
 *   @0x1a2f5c bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a2f60 str r0, [r4, #0x3c]
 *   @0x1a2f64 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a2f68 movw r0, #0x2710
 *   @0x1a2f6c bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a2f70 str r0, [r4, #0x38]
 *   @0x1a2f74 b 0x1a2f54 <_Z14CreateParticleffiR9RParticle+0xf8>
 *   @0x1a2f78 eoreq sp, r4, r0, lsr #18
 *
 * ══ §84/91 spRegionAttachment_computeWorldVertices  0x289174  size 288  72 条（0x289174..0x289294）
 * @func 0x289174 0x289294  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 70 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289174 vldr s15, [r1, #56]
 *   @0x289178 vldr s13, [r0, #96]
 *   @0x28917c vmul.f32 s13, s13, s15
 *   @0x289180 vldr s10, [r1, #52]
 *   @0x289184 vldr s9, [r0, #92]
 *   @0x289188 ldr r3, [r1, #0x4]
 *   @0x28918c vldr s14, [r1, #60]
 *   @0x289190 vldr s11, [r3, #88]
 *   @0x289194 vldr s12, [r3, #92]
 *   @0x289198 vldr s15, [r1, #72]
 *   @0x28919c vmla.f32 s13, s9, s10
 *   @0x2891a0 vadd.f32 s14, s11, s14
 *   @0x2891a4 vadd.f32 s13, s13, s14
 *   @0x2891a8 vstr s13, [r2]
 *   @0x2891ac vldr s11, [r0, #96]
 *   @0x2891b0 vldr s13, [r1, #68]
 *   @0x2891b4 vmul.f32 s13, s11, s13
 *   @0x2891b8 vldr s10, [r0, #92]
 *   @0x2891bc vldr s11, [r1, #64]
 *   @0x2891c0 vmla.f32 s13, s10, s11
 *   @0x2891c4 vadd.f32 s15, s12, s15
 *   @0x2891c8 vadd.f32 s13, s13, s15
 *   @0x2891cc vstr s13, [r2, #4]
 *   @0x2891d0 vldr s12, [r0, #104]
 *   @0x2891d4 vldr s13, [r1, #56]
 *   @0x2891d8 vmul.f32 s13, s12, s13
 *   @0x2891dc vldr s11, [r0, #100]
 *   @0x2891e0 vldr s12, [r1, #52]
 *   @0x2891e4 vmla.f32 s13, s11, s12
 *   @0x2891e8 vadd.f32 s13, s13, s14
 *   @0x2891ec vstr s13, [r2, #8]
 *   @0x2891f0 vldr s12, [r0, #104]
 *   @0x2891f4 vldr s13, [r1, #68]
 *   @0x2891f8 vmul.f32 s13, s12, s13
 *   @0x2891fc vldr s11, [r0, #100]
 *   @0x289200 vldr s12, [r1, #64]
 *   @0x289204 vmla.f32 s13, s11, s12
 *   @0x289208 vadd.f32 s13, s13, s15
 *   @0x28920c vstr s13, [r2, #12]
 *   @0x289210 vldr s12, [r0, #112]
 *   @0x289214 vldr s13, [r1, #56]
 *   @0x289218 vmul.f32 s13, s12, s13
 *   @0x28921c vldr s11, [r0, #108]
 *   @0x289220 vldr s12, [r1, #52]
 *   @0x289224 vmla.f32 s13, s11, s12
 *   @0x289228 vadd.f32 s13, s13, s14
 *   @0x28922c vstr s13, [r2, #16]
 *   @0x289230 vldr s12, [r0, #112]
 *   @0x289234 vldr s13, [r1, #68]
 *   @0x289238 vmul.f32 s13, s12, s13
 *   @0x28923c vldr s11, [r0, #108]
 *   @0x289240 vldr s12, [r1, #64]
 *   @0x289244 vmla.f32 s13, s11, s12
 *   @0x289248 vadd.f32 s13, s13, s15
 *   @0x28924c vstr s13, [r2, #20]
 *   @0x289250 vldr s12, [r0, #120]
 *   @0x289254 vldr s13, [r1, #56]
 *   @0x289258 vmul.f32 s13, s12, s13
 *   @0x28925c vldr s11, [r0, #116]
 *   @0x289260 vldr s12, [r1, #52]
 *   @0x289264 vmla.f32 s13, s11, s12
 *   @0x289268 vadd.f32 s14, s13, s14
 *   @0x28926c vstr s14, [r2, #24]
 *   @0x289270 vldr s13, [r0, #120]
 *   @0x289274 vldr s14, [r1, #68]
 *   @0x289278 vmul.f32 s14, s13, s14
 *   @0x28927c vldr s12, [r0, #116]
 *   @0x289280 vldr s13, [r1, #64]
 *   @0x289284 vmla.f32 s14, s12, s13
 *   @0x289288 vadd.f32 s15, s14, s15
 *   @0x28928c vstr s15, [r2, #28]
 *   @0x289290 bx lr
 *
 * ══ §85/91 yySocket::ProcessUDP  0x296cb8  size 288  72 条（0x296cb8..0x296dd8）
 * @func 0x296cb8 0x296dd8  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::ProcessUDP()+0x114×2 / yySocket::SendDataToEvent(int, unsigned char*)×2 / yySocket::Peek() / yySocket::ReadFrom(void*, unsigned int, unsigned int, char**, int*) / 0xb65a4 / RelyFilterIncomingPacket(int, unsigned char*, int, char*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x50×6 / 0x54×3 / 0xc×2 / 0xfc×1 / 0x4×1 / 0x10×1 / 0x30×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296cb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x296cbc sub sp, sp, #28
 *   @0x296cc0 ldr r7, [r0, #0x50]
 *   @0x296cc4 add r10, r0, #108
 *   @0x296cc8 ldr r6, [r0, #0x54]
 *   @0x296ccc add r9, sp, #16
 *   @0x296cd0 ldr r3, [pc, #0xfc]
 *   @0x296cd4 add r8, sp, #20
 *   @0x296cd8 mov r4, r0
 *   @0x296cdc add r3, pc, r3
 *   @0x296ce0 str r3, [sp, #0xc]
 *   @0x296ce4 mov r0, r4
 *   @0x296ce8 bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x296cec ldr r3, [r4, #0x54]
 *   @0x296cf0 cmp r0, r3
 *   @0x296cf4 mov r5, r0
 *   @0x296cf8 bgt 0x296d90 <_ZN8yySocket10ProcessUDPEv+0xd8>
 *   @0x296cfc mov r3, #0
 *   @0x296d00 cmp r5, r3
 *   @0x296d04 mov r2, r6
 *   @0x296d08 mov r1, r7
 *   @0x296d0c mov r0, r4
 *   @0x296d10 ble 0x296dcc <_ZN8yySocket10ProcessUDPEv+0x114>
 *   @0x296d14 str r9, [sp]
 *   @0x296d18 str r8, [sp, #0x4]
 *   @0x296d1c bl 0x2952ec <_ZN8yySocket8ReadFromEPvjjPPcPi>
 *   @0x296d20 subs r5, r0, #0
 *   @0x296d24 mov r0, r10
 *   @0x296d28 ble 0x296dcc <_ZN8yySocket10ProcessUDPEv+0x114>
 *   @0x296d2c ldr r11, [sp, #0x10]
 *   @0x296d30 mov r1, r11
 *   @0x296d34 bl 0xb65a4 <strcpy@plt>
 *   @0x296d38 ldrb lr, [r4, #0x30]
 *   @0x296d3c ldr r12, [sp, #0x14]
 *   @0x296d40 mov r2, r5
 *   @0x296d44 cmp lr, #0
 *   @0x296d48 mov r3, r11
 *   @0x296d4c mov r0, r4
 *   @0x296d50 mov r1, r5
 *   @0x296d54 str r12, [r4, #0xac]
 *   @0x296d58 beq 0x296dc0 <_ZN8yySocket10ProcessUDPEv+0x108>
 *   @0x296d5c str r12, [sp]
 *   @0x296d60 ldr r0, [r4, #0x68]
 *   @0x296d64 ldr r1, [r4, #0x50]
 *   @0x296d68 bl 0x29a4ac <_Z24RelyFilterIncomingPacketiPhiPci>
 *   @0x296d6c subs r3, r0, #0
 *   @0x296d70 mov r0, r4
 *   @0x296d74 mov r2, r3
 *   @0x296d78 beq 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c>
 *   @0x296d7c ldr r1, [r4, #0x50]
 *   @0x296d80 rsb r1, r1, r3
 *   @0x296d84 rsb r1, r1, r5
 *   @0x296d88 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh>
 *   @0x296d8c b 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c>
 *   @0x296d90 add r6, r3, #32768
 *   @0x296d94 ldr r2, [sp, #0xc]
 *   @0x296d98 mov r3, #0
 *   @0x296d9c str r3, [sp]
 *   @0x296da0 mov r1, r6
 *   @0x296da4 ldr r0, [r4, #0x50]
 *   @0x296da8 str r6, [r4, #0x54]
 *   @0x296dac mov r3, #74
 *   @0x296db0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x296db4 mov r7, r0
 *   @0x296db8 str r0, [r4, #0x50]
 *   @0x296dbc b 0x296cfc <_ZN8yySocket10ProcessUDPEv+0x44>
 *   @0x296dc0 ldr r2, [r4, #0x50]
 *   @0x296dc4 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh>
 *   @0x296dc8 b 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c>
 *   @0x296dcc add sp, sp, #28
 *   @0x296dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x296dd4 andeq r10, r9, r4, asr r3
 *
 * ══ §86/91 CSkeletonSprite::Draw  0xc03bc  size 284  71 条（0xc03bc..0xc04d8）
 * @func 0xc03bc 0xc04d8  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation()×2 / spBone_setYDown / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonSprite::DrawSkeleton(spSkeleton*, unsigned int, float) / CSkeletonSprite::Draw(char const*, char const*, int, float, float, float, float, float, unsigned int, float, CInstance*)
 * 字段偏移 top8: 0x1c×3 / 0x4×2 / 0x104×1 / 0x64×1 / 0x68×1 / 0xc×1 / 0x14×1 / 0x18×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc03bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc03c0 vpush {d8, d9}
 *   @0xc03c4 mov r5, r0
 *   @0xc03c8 ldr r4, [pc, #0x104]
 *   @0xc03cc sub sp, sp, #36
 *   @0xc03d0 mov r6, r1
 *   @0xc03d4 mov r10, r2
 *   @0xc03d8 ldr r4, [pc, r4]
 *   @0xc03dc mov r9, r3
 *   @0xc03e0 vldr s18, [sp, #88]
 *   @0xc03e4 vldr s17, [sp, #92]
 *   @0xc03e8 ldr r0, [r4]
 *   @0xc03ec vldr s16, [sp, #96]
 *   @0xc03f0 ldr r8, [sp, #0x64]
 *   @0xc03f4 cmp r0, #0
 *   @0xc03f8 ldr r7, [sp, #0x68]
 *   @0xc03fc beq 0xc047c <_ZN15CSkeletonSprite4DrawEifffffjf+0xc0>
 *   @0xc0400 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0xc0404 cmp r0, #0
 *   @0xc0408 beq 0xc047c <_ZN15CSkeletonSprite4DrawEifffffjf+0xc0>
 *   @0xc040c mov r0, #1
 *   @0xc0410 bl 0x284ed8 <spBone_setYDown>
 *   @0xc0414 ldr r0, [r4]
 *   @0xc0418 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0xc041c ldr r3, [r0, #0x1c]
 *   @0xc0420 mov r11, r0
 *   @0xc0424 cmp r3, #0
 *   @0xc0428 beq 0xc0470 <_ZN15CSkeletonSprite4DrawEifffffjf+0xb4>
 *   @0xc042c vstr s18, [sp]
 *   @0xc0430 vstr s17, [sp, #4]
 *   @0xc0434 vstr s16, [sp, #8]
 *   @0xc0438 ldr r12, [r4]
 *   @0xc043c mov r1, r6
 *   @0xc0440 mov r2, r10
 *   @0xc0444 mov r3, r9
 *   @0xc0448 str r12, [sp, #0xc]
 *   @0xc044c bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xc0450 mov r3, r7
 *   @0xc0454 mov r0, r5
 *   @0xc0458 mov r2, r8
 *   @0xc045c ldr r1, [r11, #0x1c]
 *   @0xc0460 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf>
 *   @0xc0464 ldrb r3, [r11, #0x4]
 *   @0xc0468 cmp r3, #0
 *   @0xc046c bne 0xc04bc <_ZN15CSkeletonSprite4DrawEifffffjf+0x100>
 *   @0xc0470 add sp, sp, #36
 *   @0xc0474 vpop {d8, d9}
 *   @0xc0478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc047c mov r2, #0
 *   @0xc0480 str r10, [sp]
 *   @0xc0484 mov r1, r2
 *   @0xc0488 str r9, [sp, #0x4]
 *   @0xc048c vstr s18, [sp, #8]
 *   @0xc0490 vstr s17, [sp, #12]
 *   @0xc0494 vstr s16, [sp, #16]
 *   @0xc0498 str r8, [sp, #0x14]
 *   @0xc049c str r7, [sp, #0x18]
 *   @0xc04a0 mov r0, r5
 *   @0xc04a4 mov r3, r6
 *   @0xc04a8 str r2, [sp, #0x1c]
 *   @0xc04ac bl 0xc0244 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance>
 *   @0xc04b0 add sp, sp, #36
 *   @0xc04b4 vpop {d8, d9}
 *   @0xc04b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc04bc mov r0, r5
 *   @0xc04c0 ldr r1, [r11, #0x20]
 *   @0xc04c4 add sp, sp, #36
 *   @0xc04c8 vpop {d8, d9}
 *   @0xc04cc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc04d0 b 0xbdd30 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds>
 *   @0xc04d4 eorseq sp, r2, r12, asr r5
 *
 * ══ §87/91 Code_Function_Find  0xce158  size 284  71 条（0xce158..0xce274）
 * @func 0xce158 0xce274  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×2 / Script_Find(char const*) / Code_Function_Find(char const*, int*)+0x54 / Extension_Function_GetId(char const*) / Code_Function_Find(char const*, int*)+0x24
 * 字段偏移 top8: 0x8c×1 / 0x7c×1 / 0x64×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce158 push {r4, r5, r6, r7, r8, lr}
 *   @0xce15c subs r4, r0, #0
 *   @0xce160 mvn r3, #0
 *   @0xce164 mov r5, r1
 *   @0xce168 str r3, [r1]
 *   @0xce16c beq 0xce17c <_Z18Code_Function_FindPKcPi+0x24>
 *   @0xce170 ldrb r3, [r4]
 *   @0xce174 cmp r3, #0
 *   @0xce178 bne 0xce184 <_Z18Code_Function_FindPKcPi+0x2c>
 *   @0xce17c mov r0, #0
 *   @0xce180 pop {r4, r5, r6, r7, r8, pc}
 *   @0xce184 bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0xce188 movw r3, #0x869f
 *   @0xce18c movt r3, #0x1
 *   @0xce190 add r0, r0, #99328
 *   @0xce194 add r0, r0, #672
 *   @0xce198 str r0, [r5]
 *   @0xce19c cmp r0, r3
 *   @0xce1a0 ble 0xce1ac <_Z18Code_Function_FindPKcPi+0x54>
 *   @0xce1a4 mov r0, #1
 *   @0xce1a8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xce1ac mov r0, r4
 *   @0xce1b0 movw r6, #0xa11f
 *   @0xce1b4 bl 0xf61c0 <_Z24Extension_Function_GetIdPKc>
 *   @0xce1b8 movt r6, #0x7
 *   @0xce1bc add r0, r0, #499712
 *   @0xce1c0 add r3, r0, #288
 *   @0xce1c4 str r3, [r5]
 *   @0xce1c8 cmp r3, r6
 *   @0xce1cc bgt 0xce1a4 <_Z18Code_Function_FindPKcPi+0x4c>
 *   @0xce1d0 ldr r3, [pc, #0x8c]
 *   @0xce1d4 ldr r3, [pc, r3]
 *   @0xce1d8 ldrb r3, [r3]
 *   @0xce1dc cmp r3, #0
 *   @0xce1e0 beq 0xce240 <_Z18Code_Function_FindPKcPi+0xe8>
 *   @0xce1e4 ldr r3, [pc, #0x7c]
 *   @0xce1e8 mvn r2, #0
 *   @0xce1ec str r2, [r5]
 *   @0xce1f0 ldr r3, [pc, r3]
 *   @0xce1f4 ldr r8, [r3]
 *   @0xce1f8 cmp r8, #0
 *   @0xce1fc ble 0xce17c <_Z18Code_Function_FindPKcPi+0x24>
 *   @0xce200 ldr r3, [pc, #0x64]
 *   @0xce204 mov r7, #0
 *   @0xce208 ldr r3, [pc, r3]
 *   @0xce20c ldr r6, [r3]
 *   @0xce210 b 0xce220 <_Z18Code_Function_FindPKcPi+0xc8>
 *   @0xce214 add r7, r7, #1
 *   @0xce218 cmp r7, r8
 *   @0xce21c beq 0xce17c <_Z18Code_Function_FindPKcPi+0x24>
 *   @0xce220 mov r0, r6
 *   @0xce224 mov r1, r4
 *   @0xce228 bl 0xb6574 <strcmp@plt>
 *   @0xce22c add r6, r6, #80
 *   @0xce230 cmp r0, #0
 *   @0xce234 bne 0xce214 <_Z18Code_Function_FindPKcPi+0xbc>
 *   @0xce238 str r7, [r5]
 *   @0xce23c b 0xce1a4 <_Z18Code_Function_FindPKcPi+0x4c>
 *   @0xce240 ldr r0, [pc, #0x28]
 *   @0xce244 mov r1, r4
 *   @0xce248 add r0, pc, r0
 *   @0xce24c bl 0xb6574 <strcmp@plt>
 *   @0xce250 cmp r0, #0
 *   @0xce254 bne 0xce1e4 <_Z18Code_Function_FindPKcPi+0x8c>
 *   @0xce258 str r6, [r5]
 *   @0xce25c mov r0, #1
 *   @0xce260 pop {r4, r5, r6, r7, r8, pc}
 *   @0xce264 eorseq pc, r1, r8, asr #18
 *   @0xce268 eorseq pc, r1, r4, lsr #18
 *   @0xce26c eorseq pc, r1, r0, lsl r9
 *   @0xce270 eoreq r3, r6, r4, lsr #31
 *
 * ══ §88/91 JS_Global_abstractStrictEqualityComparison  0x240a08  size 284  71 条（0x240a08..0x240b24）
 * @func 0x240a08 0x240b24  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)×2 / IsNotCompatibleKind(int, int) / 0xb6574
 * 字段偏移 top8: 0xc×2
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240a08 push {r4, r5, r6, lr}
 *   @0x240a0c mov r6, r1
 *   @0x240a10 ldr r4, [r0, #0xc]
 *   @0x240a14 mov r5, r0
 *   @0x240a18 ldr r1, [r1, #0xc]
 *   @0x240a1c bic r4, r4, #-16777216
 *   @0x240a20 bic r1, r1, #-16777216
 *   @0x240a24 mov r0, r4
 *   @0x240a28 bl 0x2409a8 <_Z19IsNotCompatibleKindii>
 *   @0x240a2c cmp r0, #0
 *   @0x240a30 bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4>
 *   @0x240a34 cmp r4, #5
 *   @0x240a38 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc>
 *   @0x240a3c cmp r4, #12
 *   @0x240a40 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc>
 *   @0x240a44 cmp r4, #0
 *   @0x240a48 beq 0x240a7c <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0x74>
 *   @0x240a4c cmp r4, #13
 *   @0x240a50 beq 0x240afc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xf4>
 *   @0x240a54 cmp r4, #1
 *   @0x240a58 beq 0x240adc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xd4>
 *   @0x240a5c cmp r4, #6
 *   @0x240a60 bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4>
 *   @0x240a64 ldr r0, [r5]
 *   @0x240a68 ldr r3, [r6]
 *   @0x240a6c subs r3, r0, r3
 *   @0x240a70 rsbs r0, r3, #0
 *   @0x240a74 adcs r0, r0, r3
 *   @0x240a78 pop {r4, r5, r6, pc}
 *   @0x240a7c mov r0, r6
 *   @0x240a80 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x240a84 vldr s14, [r5]
 *   @0x240a88 vldr s15, [r5, #4]
 *   @0x240a8c vcmp.f64 d7, d7
 *   @0x240a90 vmrs APSR_nzcv, fpscr
 *   @0x240a94 vmov d6, r0, r1
 *   @0x240a98 bvs 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4>
 *   @0x240a9c vcmp.f64 d6, d6
 *   @0x240aa0 vmrs APSR_nzcv, fpscr
 *   @0x240aa4 bvs 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4>
 *   @0x240aa8 vcmp.f64 d6, d7
 *   @0x240aac vmrs APSR_nzcv, fpscr
 *   @0x240ab0 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc>
 *   @0x240ab4 vcmp.f64 d7, #0
 *   @0x240ab8 vmrs APSR_nzcv, fpscr
 *   @0x240abc bne 0x240acc <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xc4>
 *   @0x240ac0 vcmp.f64 d6, #0
 *   @0x240ac4 vmrs APSR_nzcv, fpscr
 *   @0x240ac8 beq 0x240ad4 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_+0xcc>
 *   @0x240acc mov r0, #0
 *   @0x240ad0 pop {r4, r5, r6, pc}
 *   @0x240ad4 mov r0, #1
 *   @0x240ad8 pop {r4, r5, r6, pc}
 *   @0x240adc ldr r2, [r5]
 *   @0x240ae0 ldr r3, [r6]
 *   @0x240ae4 ldr r0, [r2]
 *   @0x240ae8 ldr r1, [r3]
 *   @0x240aec bl 0xb6574 <strcmp@plt>
 *   @0x240af0 rsbs r0, r0, #1
 *   @0x240af4 movlo r0, #0
 *   @0x240af8 pop {r4, r5, r6, pc}
 *   @0x240afc mov r0, r6
 *   @0x240b00 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x240b04 ldm r5, {r2, r3}
 *   @0x240b08 vmov d7, r2, r3
 *   @0x240b0c vmov d6, r0, r1
 *   @0x240b10 vcmp.f64 d6, d7
 *   @0x240b14 vmrs APSR_nzcv, fpscr
 *   @0x240b18 movne r0, #0
 *   @0x240b1c moveq r0, #1
 *   @0x240b20 pop {r4, r5, r6, pc}
 *
 * ══ §89/91 yySocket::ReadMessageHeader  0x296194  size 284  71 条（0x296194..0x2962b0）
 * @func 0x296194 0x2962b0  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::ReadMessageHeader()+0x8c×2 / yySocket::Peek() / yySocket::Read(void*, unsigned int, unsigned int) / yySocket::ReadMessageHeader()+0x9c / yySocket::ReadMessageHeader()+0x80 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x50×3 / 0xc0×3 / 0xbc×3 / 0x8×2 / 0x54×2 / 0x4×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296194 push {r4, lr}
 *   @0x296198 sub sp, sp, #8
 *   @0x29619c mov r4, r0
 *   @0x2961a0 bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x2961a4 cmp r0, #0
 *   @0x2961a8 ble 0x296220 <_ZN8yySocket17ReadMessageHeaderEv+0x8c>
 *   @0x2961ac mov r0, r4
 *   @0x2961b0 ldr r1, [r4, #0x50]
 *   @0x2961b4 mov r2, #12
 *   @0x2961b8 mov r3, #0
 *   @0x2961bc bl 0x2952dc <_ZN8yySocket4ReadEPvjj>
 *   @0x2961c0 cmp r0, #0
 *   @0x2961c4 blt 0x296220 <_ZN8yySocket17ReadMessageHeaderEv+0x8c>
 *   @0x2961c8 cmp r0, #11
 *   @0x2961cc ble 0x296230 <_ZN8yySocket17ReadMessageHeaderEv+0x9c>
 *   @0x2961d0 ldr r1, [r4, #0xc0]
 *   @0x2961d4 movw r2, #0xc0de
 *   @0x2961d8 ldr r3, [r4, #0x50]
 *   @0x2961dc movt r2, #0xdead
 *   @0x2961e0 str r0, [r4, #0xc0]
 *   @0x2961e4 add r0, r3, r1
 *   @0x2961e8 ldr r1, [r3, r1]
 *   @0x2961ec ldr r12, [r0, #0x4]
 *   @0x2961f0 cmp r1, r2
 *   @0x2961f4 beq 0x29625c <_ZN8yySocket17ReadMessageHeaderEv+0xc8>
 *   @0x2961f8 movw r2, #0xc0de
 *   @0x2961fc movt r2, #0xbe11
 *   @0x296200 cmp r1, r2
 *   @0x296204 beq 0x29624c <_ZN8yySocket17ReadMessageHeaderEv+0xb8>
 *   @0x296208 mov r3, #1
 *   @0x29620c mvn r2, #0
 *   @0x296210 str r2, [r4, #0xbc]
 *   @0x296214 mov r0, r3
 *   @0x296218 add sp, sp, #8
 *   @0x29621c pop {r4, pc}
 *   @0x296220 mov r3, #0
 *   @0x296224 mov r0, r3
 *   @0x296228 add sp, sp, #8
 *   @0x29622c pop {r4, pc}
 *   @0x296230 mov r3, #1
 *   @0x296234 str r0, [r4, #0xc0]
 *   @0x296238 mvn r2, #0
 *   @0x29623c mov r0, r3
 *   @0x296240 str r2, [r4, #0xbc]
 *   @0x296244 add sp, sp, #8
 *   @0x296248 pop {r4, pc}
 *   @0x29624c cmp r12, #44
 *   @0x296250 bne 0x296208 <_ZN8yySocket17ReadMessageHeaderEv+0x74>
 *   @0x296254 ldr r1, [r0, #0x8]
 *   @0x296258 b 0x29626c <_ZN8yySocket17ReadMessageHeaderEv+0xd8>
 *   @0x29625c cmp r12, #12
 *   @0x296260 bne 0x296208 <_ZN8yySocket17ReadMessageHeaderEv+0x74>
 *   @0x296264 ldr r1, [r0, #0x8]
 *   @0x296268 add r1, r1, #12
 *   @0x29626c ldr r2, [r4, #0x54]
 *   @0x296270 str r1, [r4, #0xbc]
 *   @0x296274 cmp r1, r2
 *   @0x296278 movle r3, #1
 *   @0x29627c ble 0x296214 <_ZN8yySocket17ReadMessageHeaderEv+0x80>
 *   @0x296280 ldr r2, [pc, #0x24]
 *   @0x296284 mov r0, r3
 *   @0x296288 str r1, [r4, #0x54]
 *   @0x29628c mov r12, #0
 *   @0x296290 mov r3, #74
 *   @0x296294 add r2, pc, r2
 *   @0x296298 str r12, [sp]
 *   @0x29629c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2962a0 mov r3, #1
 *   @0x2962a4 str r0, [r4, #0x50]
 *   @0x2962a8 b 0x296214 <_ZN8yySocket17ReadMessageHeaderEv+0x80>
 *   @0x2962ac muleq r9, r12, sp
 *
 * ══ §90/91 RelyFilterIncomingPacket  0x29a4ac  size 284  71 条（0x29a4ac..0x29a5c8）
 * @func 0x29a4ac 0x29a5c8  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RelyAckAdd(int, char const*, int, unsigned int)×2 / CalcCRC(char const*, int) / RelyDeletePacket(int)
 * 字段偏移 top8: 0x18×5 / 0x4×2 / 0x8×2 / 0x44×1 / 0x40×1 / 0xc×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a4ac push {r3, r4, r5, r6, r7, lr}
 *   @0x29a4b0 mov r5, r1
 *   @0x29a4b4 mov r7, r0
 *   @0x29a4b8 add r0, r1, #4
 *   @0x29a4bc sub r1, r2, #4
 *   @0x29a4c0 mov r6, r2
 *   @0x29a4c4 mov r4, r3
 *   @0x29a4c8 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x29a4cc ldr r12, [r5]
 *   @0x29a4d0 cmp r0, r12
 *   @0x29a4d4 bne 0x29a59c <_Z24RelyFilterIncomingPacketiPhiPci+0xf0>
 *   @0x29a4d8 ldrb r12, [r5, #0x4]
 *   @0x29a4dc cmp r12, #0
 *   @0x29a4e0 beq 0x29a540 <_Z24RelyFilterIncomingPacketiPhiPci+0x94>
 *   @0x29a4e4 cmp r12, #1
 *   @0x29a4e8 beq 0x29a548 <_Z24RelyFilterIncomingPacketiPhiPci+0x9c>
 *   @0x29a4ec cmp r12, #2
 *   @0x29a4f0 bne 0x29a56c <_Z24RelyFilterIncomingPacketiPhiPci+0xc0>
 *   @0x29a4f4 mov r0, r7
 *   @0x29a4f8 mov r1, r4
 *   @0x29a4fc ldr r2, [sp, #0x18]
 *   @0x29a500 ldr r3, [r5, #0x8]
 *   @0x29a504 bl 0x29a318 <_Z10RelyAckAddiPKcij>
 *   @0x29a508 cmp r0, #0
 *   @0x29a50c beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c>
 *   @0x29a510 sub r6, r6, #12
 *   @0x29a514 lsrs r6, r6, #2
 *   @0x29a518 beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c>
 *   @0x29a51c add r5, r5, #8
 *   @0x29a520 mov r4, #0
 *   @0x29a524 add r4, r4, #1
 *   @0x29a528 ldr r0, [r5, #0x4]!
 *   @0x29a52c bl 0x299c10 <_Z16RelyDeletePacketi>
 *   @0x29a530 cmp r6, r4
 *   @0x29a534 bne 0x29a524 <_Z24RelyFilterIncomingPacketiPhiPci+0x78>
 *   @0x29a538 mov r0, #0
 *   @0x29a53c pop {r3, r4, r5, r6, r7, pc}
 *   @0x29a540 add r0, r5, #8
 *   @0x29a544 pop {r3, r4, r5, r6, r7, pc}
 *   @0x29a548 mov r0, r7
 *   @0x29a54c mov r1, r4
 *   @0x29a550 ldr r2, [sp, #0x18]
 *   @0x29a554 ldr r3, [r5, #0x8]
 *   @0x29a558 bl 0x29a318 <_Z10RelyAckAddiPKcij>
 *   @0x29a55c cmp r0, #0
 *   @0x29a560 beq 0x29a538 <_Z24RelyFilterIncomingPacketiPhiPci+0x8c>
 *   @0x29a564 add r0, r5, #12
 *   @0x29a568 pop {r3, r4, r5, r6, r7, pc}
 *   @0x29a56c ldr r0, [pc, #0x44]
 *   @0x29a570 mov r2, r4
 *   @0x29a574 ldr r1, [pc, #0x40]
 *   @0x29a578 ldr r3, [sp, #0x18]
 *   @0x29a57c ldr r0, [pc, r0]
 *   @0x29a580 add r1, pc, r1
 *   @0x29a584 ldr r0, [r0]
 *   @0x29a588 ldr r12, [r0]
 *   @0x29a58c ldr r12, [r12, #0xc]
 *   @0x29a590 blx r12
 *   @0x29a594 mov r0, #0
 *   @0x29a598 pop {r3, r4, r5, r6, r7, pc}
 *   @0x29a59c ldr r0, [pc, #0x1c]
 *   @0x29a5a0 mov r2, r4
 *   @0x29a5a4 ldr r1, [pc, #0x18]
 *   @0x29a5a8 ldr r3, [sp, #0x18]
 *   @0x29a5ac ldr r0, [pc, r0]
 *   @0x29a5b0 add r1, pc, r1
 *   @0x29a5b4 b 0x29a584 <_Z24RelyFilterIncomingPacketiPhiPci+0xd8>
 *   @0x29a5b8 mulseq r5, r8, r1
 *   @0x29a5bc andeq pc, r11, r4, lsl #8
 *   @0x29a5c0 andseq r3, r5, r8, ror #2
 *   @0x29a5c4 andeq pc, r11, r12, lsl #7
 *
 * ══ §91/91 Vector_To_Direction  0x1a2920  size 280  70 条（0x1a2920..0x1a2a38）
 * @func 0x1a2920 0x1a2a38  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Vector_To_Direction(float, float, float*, float*)+0x60 / 0xb6778 / 0xb6910 / 0xb6700
 * 字段偏移 top8: 无
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2920 push {r3, r4, r5, lr}
 *   @0x1a2924 vpush {d8, d9}
 *   @0x1a2928 vmov s16, r0
 *   @0x1a292c mov r4, r2
 *   @0x1a2930 mov r5, r3
 *   @0x1a2934 vcmp.f32 s16, #0
 *   @0x1a2938 vmov s17, r1
 *   @0x1a293c vmrs APSR_nzcv, fpscr
 *   @0x1a2940 bne 0x1a299c <_Z19Vector_To_DirectionffPfS_+0x7c>
 *   @0x1a2944 vcmpe.f32 s17, #0
 *   @0x1a2948 vmrs APSR_nzcv, fpscr
 *   @0x1a294c ble 0x1a2980 <_Z19Vector_To_DirectionffPfS_+0x60>
 *   @0x1a2950 vldr s15, [pc, #204]
 *   @0x1a2954 vstr s15, [r2]
 *   @0x1a2958 vmul.f32 s14, s17, s17
 *   @0x1a295c vstr s15, [r4]
 *   @0x1a2960 vmla.f32 s14, s16, s16
 *   @0x1a2964 vsqrt.f32 s15, s14
 *   @0x1a2968 vcmp.f32 s15, s15
 *   @0x1a296c vmrs APSR_nzcv, fpscr
 *   @0x1a2970 bne 0x1a2a14 <_Z19Vector_To_DirectionffPfS_+0xf4>
 *   @0x1a2974 vpop {d8, d9}
 *   @0x1a2978 vstr s15, [r5]
 *   @0x1a297c pop {r3, r4, r5, pc}
 *   @0x1a2980 bmi 0x1a2a08 <_Z19Vector_To_DirectionffPfS_+0xe8>
 *   @0x1a2984 mov r4, #0
 *   @0x1a2988 vldr s18, [pc, #152]
 *   @0x1a298c vldr s19, [r4]
 *   @0x1a2990 vdiv.f32 s14, s19, s18
 *   @0x1a2994 vmov r0, s14
 *   @0x1a2998 b 0x1a29ec <_Z19Vector_To_DirectionffPfS_+0xcc>
 *   @0x1a299c mov r0, r1
 *   @0x1a29a0 vmov r1, s16
 *   @0x1a29a4 bl 0xb6778 <atan2f@plt>
 *   @0x1a29a8 vldr s19, [pc, #124]
 *   @0x1a29ac vldr s14, [pc, #124]
 *   @0x1a29b0 vmov s15, r0
 *   @0x1a29b4 vmul.f32 s19, s15, s19
 *   @0x1a29b8 vdiv.f32 s19, s19, s14
 *   @0x1a29bc vcmpe.f32 s19, #0
 *   @0x1a29c0 vmrs APSR_nzcv, fpscr
 *   @0x1a29c4 vldrhi s18, [pc, #92]
 *   @0x1a29c8 vsubhi.f32 s19, s18, s19
 *   @0x1a29cc vldrls s18, [pc, #84]
 *   @0x1a29d0 vnegls.f32 s19, s19
 *   @0x1a29d4 vstrhi s19, [r4]
 *   @0x1a29d8 vdivls.f32 s14, s19, s18
 *   @0x1a29dc vstrls s19, [r4]
 *   @0x1a29e0 vdivhi.f32 s15, s19, s18
 *   @0x1a29e4 vmovls r0, s14
 *   @0x1a29e8 vmovhi r0, s15
 *   @0x1a29ec bl 0xb6910 <floorf@plt>
 *   @0x1a29f0 vmov s14, r0
 *   @0x1a29f4 vcvt.s32.f32 s15, s14
 *   @0x1a29f8 vcvt.f32.s32 s15, s15
 *   @0x1a29fc vmls.f32 s19, s15, s18
 *   @0x1a2a00 vmov.f32 s15, s19
 *   @0x1a2a04 b 0x1a2958 <_Z19Vector_To_DirectionffPfS_+0x38>
 *   @0x1a2a08 vldr s15, [pc, #36]
 *   @0x1a2a0c vstr s15, [r2]
 *   @0x1a2a10 b 0x1a2958 <_Z19Vector_To_DirectionffPfS_+0x38>
 *   @0x1a2a14 vmov r0, s14
 *   @0x1a2a18 bl 0xb6700 <sqrtf@plt>
 *   @0x1a2a1c vmov s15, r0
 *   @0x1a2a20 b 0x1a2974 <_Z19Vector_To_DirectionffPfS_+0x54>
 *   @0x1a2a24 orrmi r0, r7, #0
 *   @0x1a2a28 .word 0x43b40000
 *   @0x1a2a2c teqmi r4, #0
 *   @0x1a2a30 ldrdmi r0, r1, [r9], #-251
 *   @0x1a2a34 adcsmi r0, r4, #0
 */
