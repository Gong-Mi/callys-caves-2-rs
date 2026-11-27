/* cally 逆向卡：All_18 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 5 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/5 GLFuncImport(bool)  0xba710  size 12180  3045 条（0xba710..0xbd6a4）
 * @func 0xba710 0xbd6a4  size 12180  3045 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xba71c→0x479a94, 0xba73c→0x3eb70c, 0xba798→0x479c94, 0xba7c4→0x479c90, 0xba7f0→0x479c80, 0xba81c→0x479c78, 0xba848→0x479c74, 0xba874→0x479c68
 * 调用序列: 0xb6514×128 / 0xb6520×2
 * 字段偏移 top8: 0xc×134 / 0x6ec×4 / 0x60c×4 / 0x52c×4 / 0xf74×3 / 0xf54×3 / 0xf34×3 / 0xf14×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xba710 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xba714 mov r8, r0
 *   @0xba718 ldr r4, [pc, #0xfdc]
 *   @0xba71c ldr r3, [pc, #0xfdc]
 *   @0xba720 add r4, pc, r4
 *   @0xba724 ldr r7, [r4, r3]
 *   @0xba728 ldr r6, [r7]
 *   @0xba72c cmp r6, #0
 *   @0xba730 beq 0xba73c <_Z12GLFuncImportb+0x2c>
 *   @0xba734 mov r0, r6
 *   @0xba738 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xba73c ldr r3, [pc, #0xfc0]
 *   @0xba740 ldr r1, [pc, #0xfc0]
 *   @0xba744 ldr r3, [r4, r3]
 *   @0xba748 add r1, pc, r1
 *   @0xba74c ldr r5, [r3]
 *   @0xba750 ldr r3, [r5]
 *   @0xba754 mov r0, r5
 *   @0xba758 ldr r3, [r3, #0xc]
 *   @0xba75c blx r3
 *   @0xba760 cmp r8, #0
 *   @0xba764 bne 0xbb640 <_Z12GLFuncImportb+0xf30>
 *   @0xba768 ldr r3, [pc, #0xf9c]
 *   @0xba76c ldr r9, [pc, r3]
 *   @0xba770 cmp r9, #0
 *   @0xba774 movne r6, r8
 *   @0xba778 beq 0xbb69c <_Z12GLFuncImportb+0xf8c>
 *   @0xba77c ldr r1, [pc, #0xf8c]
 *   @0xba780 mov r0, r9
 *   @0xba784 str r6, [r7]
 *   @0xba788 add r1, pc, r1
 *   @0xba78c bl 0xb6514 <dlsym@plt>
 *   @0xba790 subs r9, r0, #0
 *   @0xba794 beq 0xbc98c <_Z12GLFuncImportb+0x227c>
 *   @0xba798 ldr r3, [pc, #0xf74]
 *   @0xba79c ldr r2, [pc, #0xf74]
 *   @0xba7a0 ldr r1, [pc, #0xf74]
 *   @0xba7a4 ldr r3, [r4, r3]
 *   @0xba7a8 add r2, pc, r2
 *   @0xba7ac add r1, pc, r1
 *   @0xba7b0 ldr r0, [r2]
 *   @0xba7b4 str r9, [r3]
 *   @0xba7b8 bl 0xb6514 <dlsym@plt>
 *   @0xba7bc subs r9, r0, #0
 *   @0xba7c0 beq 0xbc9ac <_Z12GLFuncImportb+0x229c>
 *   @0xba7c4 ldr r3, [pc, #0xf54]
 *   @0xba7c8 ldr r2, [pc, #0xf54]
 *   @0xba7cc ldr r1, [pc, #0xf54]
 *   @0xba7d0 ldr r3, [r4, r3]
 *   @0xba7d4 add r2, pc, r2
 *   @0xba7d8 add r1, pc, r1
 *   @0xba7dc ldr r0, [r2]
 *   @0xba7e0 str r9, [r3]
 *   @0xba7e4 bl 0xb6514 <dlsym@plt>
 *   @0xba7e8 subs r9, r0, #0
 *   @0xba7ec beq 0xbc8cc <_Z12GLFuncImportb+0x21bc>
 *   @0xba7f0 ldr r3, [pc, #0xf34]
 *   @0xba7f4 ldr r2, [pc, #0xf34]
 *   @0xba7f8 ldr r1, [pc, #0xf34]
 *   @0xba7fc ldr r3, [r4, r3]
 *   @0xba800 add r2, pc, r2
 *   @0xba804 add r1, pc, r1
 *   @0xba808 ldr r0, [r2]
 *   @0xba80c str r9, [r3]
 *   @0xba810 bl 0xb6514 <dlsym@plt>
 *   @0xba814 subs r9, r0, #0
 *   @0xba818 beq 0xbc8ec <_Z12GLFuncImportb+0x21dc>
 *   @0xba81c ldr r3, [pc, #0xf14]
 *   @0xba820 ldr r2, [pc, #0xf14]
 *   @0xba824 ldr r1, [pc, #0xf14]
 *   @0xba828 ldr r3, [r4, r3]
 *   @0xba82c add r2, pc, r2
 *   @0xba830 add r1, pc, r1
 *   @0xba834 ldr r0, [r2]
 *   @0xba838 str r9, [r3]
 *   @0xba83c bl 0xb6514 <dlsym@plt>
 *   @0xba840 subs r9, r0, #0
 *   @0xba844 beq 0xbc90c <_Z12GLFuncImportb+0x21fc>
 *   @0xba848 ldr r3, [pc, #0xef4]
 *   @0xba84c ldr r2, [pc, #0xef4]
 *   @0xba850 ldr r1, [pc, #0xef4]
 *   @0xba854 ldr r3, [r4, r3]
 *   @0xba858 add r2, pc, r2
 *   @0xba85c add r1, pc, r1
 *   @0xba860 ldr r0, [r2]
 *   @0xba864 str r9, [r3]
 *   @0xba868 bl 0xb6514 <dlsym@plt>
 *   @0xba86c subs r9, r0, #0
 *   @0xba870 beq 0xbc92c <_Z12GLFuncImportb+0x221c>
 *   @0xba874 ldr r3, [pc, #0xed4]
 *   @0xba878 ldr r2, [pc, #0xed4]
 *   @0xba87c ldr r1, [pc, #0xed4]
 *   @0xba880 ldr r3, [r4, r3]
 *   @0xba884 add r2, pc, r2
 *   @0xba888 add r1, pc, r1
 *   @0xba88c ldr r0, [r2]
 *   @0xba890 str r9, [r3]
 *   @0xba894 bl 0xb6514 <dlsym@plt>
 *   @0xba898 subs r9, r0, #0
 *   @0xba89c beq 0xbc7cc <_Z12GLFuncImportb+0x20bc>
 *   @0xba8a0 ldr r3, [pc, #0xeb4]
 *   @0xba8a4 ldr r2, [pc, #0xeb4]
 *   @0xba8a8 ldr r1, [pc, #0xeb4]
 *   @0xba8ac ldr r3, [r4, r3]
 *   @0xba8b0 add r2, pc, r2
 *   @0xba8b4 add r1, pc, r1
 *   @0xba8b8 ldr r0, [r2]
 *   @0xba8bc str r9, [r3]
 *   @0xba8c0 bl 0xb6514 <dlsym@plt>
 *   @0xba8c4 subs r9, r0, #0
 *   @0xba8c8 beq 0xbc7ec <_Z12GLFuncImportb+0x20dc>
 *   @0xba8cc ldr r3, [pc, #0xe94]
 *   @0xba8d0 ldr r2, [pc, #0xe94]
 *   @0xba8d4 ldr r1, [pc, #0xe94]
 *   @0xba8d8 ldr r3, [r4, r3]
 *   @0xba8dc add r2, pc, r2
 *   @0xba8e0 add r1, pc, r1
 *   @0xba8e4 ldr r0, [r2]
 *   @0xba8e8 str r9, [r3]
 *   @0xba8ec bl 0xb6514 <dlsym@plt>
 *   @0xba8f0 subs r9, r0, #0
 *   @0xba8f4 beq 0xbc80c <_Z12GLFuncImportb+0x20fc>
 *   @0xba8f8 ldr r3, [pc, #0xe74]
 *   @0xba8fc ldr r2, [pc, #0xe74]
 *   @0xba900 ldr r1, [pc, #0xe74]
 *   @0xba904 ldr r3, [r4, r3]
 *   @0xba908 add r2, pc, r2
 *   @0xba90c add r1, pc, r1
 *   @0xba910 ldr r0, [r2]
 *   @0xba914 str r9, [r3]
 *   @0xba918 bl 0xb6514 <dlsym@plt>
 *   @0xba91c subs r9, r0, #0
 *   @0xba920 beq 0xbc82c <_Z12GLFuncImportb+0x211c>
 *   @0xba924 ldr r3, [pc, #0xe54]
 *   @0xba928 ldr r2, [pc, #0xe54]
 *   @0xba92c ldr r1, [pc, #0xe54]
 *   @0xba930 ldr r3, [r4, r3]
 *   @0xba934 add r2, pc, r2
 *   @0xba938 add r1, pc, r1
 *   @0xba93c ldr r0, [r2]
 *   @0xba940 str r9, [r3]
 *   @0xba944 bl 0xb6514 <dlsym@plt>
 *   @0xba948 subs r9, r0, #0
 *   @0xba94c beq 0xbc84c <_Z12GLFuncImportb+0x213c>
 *   @0xba950 ldr r3, [pc, #0xe34]
 *   @0xba954 ldr r2, [pc, #0xe34]
 *   @0xba958 ldr r1, [pc, #0xe34]
 *   @0xba95c ldr r3, [r4, r3]
 *   @0xba960 add r2, pc, r2
 *   @0xba964 add r1, pc, r1
 *   @0xba968 ldr r0, [r2]
 *   @0xba96c str r9, [r3]
 *   @0xba970 bl 0xb6514 <dlsym@plt>
 *   @0xba974 subs r9, r0, #0
 *   @0xba978 beq 0xbc86c <_Z12GLFuncImportb+0x215c>
 *   @0xba97c ldr r3, [pc, #0xe14]
 *   @0xba980 ldr r2, [pc, #0xe14]
 *   @0xba984 ldr r1, [pc, #0xe14]
 *   @0xba988 ldr r3, [r4, r3]
 *   @0xba98c add r2, pc, r2
 *   @0xba990 add r1, pc, r1
 *   @0xba994 ldr r0, [r2]
 *   @0xba998 str r9, [r3]
 *   @0xba99c bl 0xb6514 <dlsym@plt>
 *   @0xba9a0 subs r9, r0, #0
 *   @0xba9a4 beq 0xbc88c <_Z12GLFuncImportb+0x217c>
 *   @0xba9a8 ldr r3, [pc, #0xdf4]
 *   @0xba9ac ldr r2, [pc, #0xdf4]
 *   @0xba9b0 ldr r1, [pc, #0xdf4]
 *   @0xba9b4 ldr r3, [r4, r3]
 *   @0xba9b8 add r2, pc, r2
 *   @0xba9bc add r1, pc, r1
 *   @0xba9c0 ldr r0, [r2]
 *   @0xba9c4 str r9, [r3]
 *   @0xba9c8 bl 0xb6514 <dlsym@plt>
 *   @0xba9cc subs r9, r0, #0
 *   @0xba9d0 beq 0xbc8ac <_Z12GLFuncImportb+0x219c>
 *   @0xba9d4 ldr r3, [pc, #0xdd4]
 *   @0xba9d8 ldr r2, [pc, #0xdd4]
 *   @0xba9dc ldr r1, [pc, #0xdd4]
 *   @0xba9e0 ldr r3, [r4, r3]
 *   @0xba9e4 add r2, pc, r2
 *   @0xba9e8 add r1, pc, r1
 *   @0xba9ec ldr r0, [r2]
 *   @0xba9f0 str r9, [r3]
 *   @0xba9f4 bl 0xb6514 <dlsym@plt>
 *   @0xba9f8 subs r9, r0, #0
 *   @0xba9fc beq 0xbc5cc <_Z12GLFuncImportb+0x1ebc>
 *   @0xbaa00 ldr r3, [pc, #0xdb4]
 *   @0xbaa04 ldr r2, [pc, #0xdb4]
 *   @0xbaa08 ldr r1, [pc, #0xdb4]
 *   @0xbaa0c ldr r3, [r4, r3]
 *   @0xbaa10 add r2, pc, r2
 *   @0xbaa14 add r1, pc, r1
 *   @0xbaa18 ldr r0, [r2]
 *   @0xbaa1c str r9, [r3]
 *   @0xbaa20 bl 0xb6514 <dlsym@plt>
 *   @0xbaa24 subs r9, r0, #0
 *   @0xbaa28 beq 0xbc5ec <_Z12GLFuncImportb+0x1edc>
 *   @0xbaa2c ldr r3, [pc, #0xd94]
 *   @0xbaa30 ldr r2, [pc, #0xd94]
 *   @0xbaa34 ldr r1, [pc, #0xd94]
 *   @0xbaa38 ldr r3, [r4, r3]
 *   @0xbaa3c add r2, pc, r2
 *   @0xbaa40 add r1, pc, r1
 *   @0xbaa44 ldr r0, [r2]
 *   @0xbaa48 str r9, [r3]
 *   @0xbaa4c bl 0xb6514 <dlsym@plt>
 *   @0xbaa50 subs r9, r0, #0
 *   @0xbaa54 beq 0xbc60c <_Z12GLFuncImportb+0x1efc>
 *   @0xbaa58 ldr r3, [pc, #0xd74]
 *   @0xbaa5c ldr r2, [pc, #0xd74]
 *   @0xbaa60 ldr r1, [pc, #0xd74]
 *   @0xbaa64 ldr r3, [r4, r3]
 *   @0xbaa68 add r2, pc, r2
 *   @0xbaa6c add r1, pc, r1
 *   @0xbaa70 ldr r0, [r2]
 *   @0xbaa74 str r9, [r3]
 *   @0xbaa78 bl 0xb6514 <dlsym@plt>
 *   @0xbaa7c subs r9, r0, #0
 *   @0xbaa80 beq 0xbc62c <_Z12GLFuncImportb+0x1f1c>
 *   @0xbaa84 ldr r3, [pc, #0xd54]
 *   @0xbaa88 ldr r2, [pc, #0xd54]
 *   @0xbaa8c ldr r1, [pc, #0xd54]
 *   @0xbaa90 ldr r3, [r4, r3]
 *   @0xbaa94 add r2, pc, r2
 *   @0xbaa98 add r1, pc, r1
 *   @0xbaa9c ldr r0, [r2]
 *   @0xbaaa0 str r9, [r3]
 *   @0xbaaa4 bl 0xb6514 <dlsym@plt>
 *   @0xbaaa8 subs r9, r0, #0
 *   @0xbaaac beq 0xbc64c <_Z12GLFuncImportb+0x1f3c>
 *   @0xbaab0 ldr r3, [pc, #0xd34]
 *   @0xbaab4 ldr r2, [pc, #0xd34]
 *   @0xbaab8 ldr r1, [pc, #0xd34]
 *   @0xbaabc ldr r3, [r4, r3]
 *   @0xbaac0 add r2, pc, r2
 *   @0xbaac4 add r1, pc, r1
 *   @0xbaac8 ldr r0, [r2]
 *   @0xbaacc str r9, [r3]
 *   @0xbaad0 bl 0xb6514 <dlsym@plt>
 *   @0xbaad4 subs r9, r0, #0
 *   @0xbaad8 beq 0xbc66c <_Z12GLFuncImportb+0x1f5c>
 *   @0xbaadc ldr r3, [pc, #0xd14]
 *   @0xbaae0 ldr r2, [pc, #0xd14]
 *   @0xbaae4 ldr r1, [pc, #0xd14]
 *   @0xbaae8 ldr r3, [r4, r3]
 *   @0xbaaec add r2, pc, r2
 *   @0xbaaf0 add r1, pc, r1
 *   @0xbaaf4 ldr r0, [r2]
 *   @0xbaaf8 str r9, [r3]
 *   @0xbaafc bl 0xb6514 <dlsym@plt>
 *   @0xbab00 subs r9, r0, #0
 *   @0xbab04 beq 0xbc68c <_Z12GLFuncImportb+0x1f7c>
 *   @0xbab08 ldr r3, [pc, #0xcf4]
 *   @0xbab0c ldr r2, [pc, #0xcf4]
 *   @0xbab10 ldr r1, [pc, #0xcf4]
 *   @0xbab14 ldr r3, [r4, r3]
 *   @0xbab18 add r2, pc, r2
 *   @0xbab1c add r1, pc, r1
 *   @0xbab20 ldr r0, [r2]
 *   @0xbab24 str r9, [r3]
 *   @0xbab28 bl 0xb6514 <dlsym@plt>
 *   @0xbab2c subs r9, r0, #0
 *   @0xbab30 beq 0xbc6ac <_Z12GLFuncImportb+0x1f9c>
 *   @0xbab34 ldr r3, [pc, #0xcd4]
 *   @0xbab38 ldr r2, [pc, #0xcd4]
 *   @0xbab3c ldr r1, [pc, #0xcd4]
 *   @0xbab40 ldr r3, [r4, r3]
 *   @0xbab44 add r2, pc, r2
 *   @0xbab48 add r1, pc, r1
 *   @0xbab4c ldr r0, [r2]
 *   @0xbab50 str r9, [r3]
 *   @0xbab54 bl 0xb6514 <dlsym@plt>
 *   @0xbab58 subs r9, r0, #0
 *   @0xbab5c beq 0xbc6cc <_Z12GLFuncImportb+0x1fbc>
 *   @0xbab60 ldr r3, [pc, #0xcb4]
 *   @0xbab64 ldr r2, [pc, #0xcb4]
 *   @0xbab68 ldr r1, [pc, #0xcb4]
 *   @0xbab6c ldr r3, [r4, r3]
 *   @0xbab70 add r2, pc, r2
 *   @0xbab74 add r1, pc, r1
 *   @0xbab78 ldr r0, [r2]
 *   @0xbab7c str r9, [r3]
 *   @0xbab80 bl 0xb6514 <dlsym@plt>
 *   @0xbab84 subs r9, r0, #0
 *   @0xbab88 beq 0xbc6ec <_Z12GLFuncImportb+0x1fdc>
 *   @0xbab8c ldr r3, [pc, #0xc94]
 *   @0xbab90 ldr r2, [pc, #0xc94]
 *   @0xbab94 ldr r1, [pc, #0xc94]
 *   @0xbab98 ldr r3, [r4, r3]
 *   @0xbab9c add r2, pc, r2
 *   @0xbaba0 add r1, pc, r1
 *   @0xbaba4 ldr r0, [r2]
 *   @0xbaba8 str r9, [r3]
 *   @0xbabac bl 0xb6514 <dlsym@plt>
 *   @0xbabb0 subs r9, r0, #0
 *   @0xbabb4 beq 0xbc70c <_Z12GLFuncImportb+0x1ffc>
 *   @0xbabb8 ldr r3, [pc, #0xc74]
 *   @0xbabbc ldr r2, [pc, #0xc74]
 *   @0xbabc0 ldr r1, [pc, #0xc74]
 *   @0xbabc4 ldr r3, [r4, r3]
 *   @0xbabc8 add r2, pc, r2
 *   @0xbabcc add r1, pc, r1
 *   @0xbabd0 ldr r0, [r2]
 *   @0xbabd4 str r9, [r3]
 *   @0xbabd8 bl 0xb6514 <dlsym@plt>
 *   @0xbabdc subs r9, r0, #0
 *   @0xbabe0 beq 0xbc72c <_Z12GLFuncImportb+0x201c>
 *   @0xbabe4 ldr r3, [pc, #0xc54]
 *   @0xbabe8 ldr r2, [pc, #0xc54]
 *   @0xbabec ldr r1, [pc, #0xc54]
 *   @0xbabf0 ldr r3, [r4, r3]
 *   @0xbabf4 add r2, pc, r2
 *   @0xbabf8 add r1, pc, r1
 *   @0xbabfc ldr r0, [r2]
 *   @0xbac00 str r9, [r3]
 *   @0xbac04 bl 0xb6514 <dlsym@plt>
 *   @0xbac08 subs r9, r0, #0
 *   @0xbac0c beq 0xbc74c <_Z12GLFuncImportb+0x203c>
 *   @0xbac10 ldr r3, [pc, #0xc34]
 *   @0xbac14 ldr r2, [pc, #0xc34]
 *   @0xbac18 ldr r1, [pc, #0xc34]
 *   @0xbac1c ldr r3, [r4, r3]
 *   @0xbac20 add r2, pc, r2
 *   @0xbac24 add r1, pc, r1
 *   @0xbac28 ldr r0, [r2]
 *   @0xbac2c str r9, [r3]
 *   @0xbac30 bl 0xb6514 <dlsym@plt>
 *   @0xbac34 subs r9, r0, #0
 *   @0xbac38 beq 0xbc76c <_Z12GLFuncImportb+0x205c>
 *   @0xbac3c ldr r3, [pc, #0xc14]
 *   @0xbac40 ldr r2, [pc, #0xc14]
 *   @0xbac44 ldr r1, [pc, #0xc14]
 *   @0xbac48 ldr r3, [r4, r3]
 *   @0xbac4c add r2, pc, r2
 *   @0xbac50 add r1, pc, r1
 *   @0xbac54 ldr r0, [r2]
 *   @0xbac58 str r9, [r3]
 *   @0xbac5c bl 0xb6514 <dlsym@plt>
 *   @0xbac60 subs r9, r0, #0
 *   @0xbac64 beq 0xbc78c <_Z12GLFuncImportb+0x207c>
 *   @0xbac68 ldr r3, [pc, #0xbf4]
 *   @0xbac6c ldr r2, [pc, #0xbf4]
 *   @0xbac70 ldr r1, [pc, #0xbf4]
 *   @0xbac74 ldr r3, [r4, r3]
 *   @0xbac78 add r2, pc, r2
 *   @0xbac7c add r1, pc, r1
 *   @0xbac80 ldr r0, [r2]
 *   @0xbac84 str r9, [r3]
 *   @0xbac88 bl 0xb6514 <dlsym@plt>
 *   @0xbac8c subs r9, r0, #0
 *   @0xbac90 beq 0xbc7ac <_Z12GLFuncImportb+0x209c>
 *   @0xbac94 ldr r3, [pc, #0xbd4]
 *   @0xbac98 ldr r2, [pc, #0xbd4]
 *   @0xbac9c ldr r1, [pc, #0xbd4]
 *   @0xbaca0 ldr r3, [r4, r3]
 *   @0xbaca4 add r2, pc, r2
 *   @0xbaca8 add r1, pc, r1
 *   @0xbacac ldr r0, [r2]
 *   @0xbacb0 str r9, [r3]
 *   @0xbacb4 bl 0xb6514 <dlsym@plt>
 *   @0xbacb8 subs r9, r0, #0
 *   @0xbacbc beq 0xbc9cc <_Z12GLFuncImportb+0x22bc>
 *   @0xbacc0 ldr r3, [pc, #0xbb4]
 *   @0xbacc4 ldr r2, [pc, #0xbb4]
 *   @0xbacc8 ldr r1, [pc, #0xbb4]
 *   @0xbaccc ldr r3, [r4, r3]
 *   @0xbacd0 add r2, pc, r2
 *   @0xbacd4 add r1, pc, r1
 *   @0xbacd8 ldr r0, [r2]
 *   @0xbacdc str r9, [r3]
 *   @0xbace0 bl 0xb6514 <dlsym@plt>
 *   @0xbace4 subs r9, r0, #0
 *   @0xbace8 beq 0xbc9ec <_Z12GLFuncImportb+0x22dc>
 *   @0xbacec ldr r3, [pc, #0xb94]
 *   @0xbacf0 ldr r2, [pc, #0xb94]
 *   @0xbacf4 ldr r1, [pc, #0xb94]
 *   @0xbacf8 ldr r3, [r4, r3]
 *   @0xbacfc add r2, pc, r2
 *   @0xbad00 add r1, pc, r1
 *   @0xbad04 ldr r0, [r2]
 *   @0xbad08 str r9, [r3]
 *   @0xbad0c bl 0xb6514 <dlsym@plt>
 *   @0xbad10 subs r9, r0, #0
 *   @0xbad14 beq 0xbca0c <_Z12GLFuncImportb+0x22fc>
 *   @0xbad18 ldr r3, [pc, #0xb74]
 *   @0xbad1c ldr r2, [pc, #0xb74]
 *   @0xbad20 ldr r1, [pc, #0xb74]
 *   @0xbad24 ldr r3, [r4, r3]
 *   @0xbad28 add r2, pc, r2
 *   @0xbad2c add r1, pc, r1
 *   @0xbad30 ldr r0, [r2]
 *   @0xbad34 str r9, [r3]
 *   @0xbad38 bl 0xb6514 <dlsym@plt>
 *   @0xbad3c subs r9, r0, #0
 *   @0xbad40 beq 0xbca2c <_Z12GLFuncImportb+0x231c>
 *   @0xbad44 ldr r3, [pc, #0xb54]
 *   @0xbad48 ldr r2, [pc, #0xb54]
 *   @0xbad4c ldr r1, [pc, #0xb54]
 *   @0xbad50 ldr r3, [r4, r3]
 *   @0xbad54 add r2, pc, r2
 *   @0xbad58 add r1, pc, r1
 *   @0xbad5c ldr r0, [r2]
 *   @0xbad60 str r9, [r3]
 *   @0xbad64 bl 0xb6514 <dlsym@plt>
 *   @0xbad68 subs r9, r0, #0
 *   @0xbad6c beq 0xbca4c <_Z12GLFuncImportb+0x233c>
 *   @0xbad70 ldr r3, [pc, #0xb34]
 *   @0xbad74 ldr r2, [pc, #0xb34]
 *   @0xbad78 ldr r1, [pc, #0xb34]
 *   @0xbad7c ldr r3, [r4, r3]
 *   @0xbad80 add r2, pc, r2
 *   @0xbad84 add r1, pc, r1
 *   @0xbad88 ldr r0, [r2]
 *   @0xbad8c str r9, [r3]
 *   @0xbad90 bl 0xb6514 <dlsym@plt>
 *   @0xbad94 subs r9, r0, #0
 *   @0xbad98 beq 0xbca6c <_Z12GLFuncImportb+0x235c>
 *   @0xbad9c ldr r3, [pc, #0xb14]
 *   @0xbada0 ldr r2, [pc, #0xb14]
 *   @0xbada4 ldr r1, [pc, #0xb14]
 *   @0xbada8 ldr r3, [r4, r3]
 *   @0xbadac add r2, pc, r2
 *   @0xbadb0 add r1, pc, r1
 *   @0xbadb4 ldr r0, [r2]
 *   @0xbadb8 str r9, [r3]
 *   @0xbadbc bl 0xb6514 <dlsym@plt>
 *   @0xbadc0 subs r9, r0, #0
 *   @0xbadc4 beq 0xbca8c <_Z12GLFuncImportb+0x237c>
 *   @0xbadc8 ldr r3, [pc, #0xaf4]
 *   @0xbadcc ldr r2, [pc, #0xaf4]
 *   @0xbadd0 ldr r1, [pc, #0xaf4]
 *   @0xbadd4 ldr r3, [r4, r3]
 *   @0xbadd8 add r2, pc, r2
 *   @0xbaddc add r1, pc, r1
 *   @0xbade0 ldr r0, [r2]
 *   @0xbade4 str r9, [r3]
 *   @0xbade8 bl 0xb6514 <dlsym@plt>
 *   @0xbadec subs r9, r0, #0
 *   @0xbadf0 beq 0xbcaac <_Z12GLFuncImportb+0x239c>
 *   @0xbadf4 ldr r3, [pc, #0xad4]
 *   @0xbadf8 ldr r2, [pc, #0xad4]
 *   @0xbadfc ldr r1, [pc, #0xad4]
 *   @0xbae00 ldr r3, [r4, r3]
 *   @0xbae04 add r2, pc, r2
 *   @0xbae08 add r1, pc, r1
 *   @0xbae0c ldr r0, [r2]
 *   @0xbae10 str r9, [r3]
 *   @0xbae14 bl 0xb6514 <dlsym@plt>
 *   @0xbae18 subs r9, r0, #0
 *   @0xbae1c beq 0xbc94c <_Z12GLFuncImportb+0x223c>
 *   @0xbae20 ldr r3, [pc, #0xab4]
 *   @0xbae24 ldr r2, [pc, #0xab4]
 *   @0xbae28 ldr r1, [pc, #0xab4]
 *   @0xbae2c ldr r3, [r4, r3]
 *   @0xbae30 add r2, pc, r2
 *   @0xbae34 add r1, pc, r1
 *   @0xbae38 ldr r0, [r2]
 *   @0xbae3c str r9, [r3]
 *   @0xbae40 bl 0xb6514 <dlsym@plt>
 *   @0xbae44 subs r9, r0, #0
 *   @0xbae48 beq 0xbc96c <_Z12GLFuncImportb+0x225c>
 *   @0xbae4c ldr r3, [pc, #0xa94]
 *   @0xbae50 cmp r8, #0
 *   @0xbae54 ldr r3, [r4, r3]
 *   @0xbae58 str r9, [r3]
 *   @0xbae5c beq 0xbbe44 <_Z12GLFuncImportb+0x1734>
 *   @0xbae60 ldr r3, [pc, #0xa84]
 *   @0xbae64 ldr r1, [pc, #0xa84]
 *   @0xbae68 add r3, pc, r3
 *   @0xbae6c add r1, pc, r1
 *   @0xbae70 ldr r0, [r3]
 *   @0xbae74 bl 0xb6514 <dlsym@plt>
 *   @0xbae78 subs r8, r0, #0
 *   @0xbae7c beq 0xbcc2c <_Z12GLFuncImportb+0x251c>
 *   @0xbae80 ldr r3, [pc, #0xa6c]
 *   @0xbae84 ldr r2, [pc, #0xa6c]
 *   @0xbae88 ldr r1, [pc, #0xa6c]
 *   @0xbae8c ldr r3, [r4, r3]
 *   @0xbae90 add r2, pc, r2
 *   @0xbae94 add r1, pc, r1
 *   @0xbae98 ldr r0, [r2]
 *   @0xbae9c str r8, [r3]
 *   @0xbaea0 bl 0xb6514 <dlsym@plt>
 *   @0xbaea4 subs r8, r0, #0
 *   @0xbaea8 beq 0xbc5ac <_Z12GLFuncImportb+0x1e9c>
 *   @0xbaeac ldr r3, [pc, #0xa4c]
 *   @0xbaeb0 ldr r2, [pc, #0xa4c]
 *   @0xbaeb4 ldr r1, [pc, #0xa4c]
 *   @0xbaeb8 ldr r3, [r4, r3]
 *   @0xbaebc add r2, pc, r2
 *   @0xbaec0 add r1, pc, r1
 *   @0xbaec4 ldr r0, [r2]
 *   @0xbaec8 str r8, [r3]
 *   @0xbaecc bl 0xb6514 <dlsym@plt>
 *   @0xbaed0 subs r8, r0, #0
 *   @0xbaed4 beq 0xbcc0c <_Z12GLFuncImportb+0x24fc>
 *   @0xbaed8 ldr r3, [pc, #0xa2c]
 *   @0xbaedc ldr r2, [pc, #0xa2c]
 *   @0xbaee0 ldr r1, [pc, #0xa2c]
 *   @0xbaee4 ldr r3, [r4, r3]
 *   @0xbaee8 add r2, pc, r2
 *   @0xbaeec add r1, pc, r1
 *   @0xbaef0 ldr r0, [r2]
 *   @0xbaef4 str r8, [r3]
 *   @0xbaef8 bl 0xb6514 <dlsym@plt>
 *   @0xbaefc subs r8, r0, #0
 *   @0xbaf00 beq 0xbcbec <_Z12GLFuncImportb+0x24dc>
 *   @0xbaf04 ldr r3, [pc, #0xa0c]
 *   @0xbaf08 ldr r2, [pc, #0xa0c]
 *   @0xbaf0c ldr r1, [pc, #0xa0c]
 *   @0xbaf10 ldr r3, [r4, r3]
 *   @0xbaf14 add r2, pc, r2
 *   @0xbaf18 add r1, pc, r1
 *   @0xbaf1c ldr r0, [r2]
 *   @0xbaf20 str r8, [r3]
 *   @0xbaf24 bl 0xb6514 <dlsym@plt>
 *   @0xbaf28 subs r8, r0, #0
 *   @0xbaf2c beq 0xbcbcc <_Z12GLFuncImportb+0x24bc>
 *   @0xbaf30 ldr r3, [pc, #0x9ec]
 *   @0xbaf34 ldr r2, [pc, #0x9ec]
 *   @0xbaf38 ldr r1, [pc, #0x9ec]
 *   @0xbaf3c ldr r3, [r4, r3]
 *   @0xbaf40 add r2, pc, r2
 *   @0xbaf44 add r1, pc, r1
 *   @0xbaf48 ldr r0, [r2]
 *   @0xbaf4c str r8, [r3]
 *   @0xbaf50 bl 0xb6514 <dlsym@plt>
 *   @0xbaf54 subs r8, r0, #0
 *   @0xbaf58 beq 0xbcbac <_Z12GLFuncImportb+0x249c>
 *   @0xbaf5c ldr r3, [pc, #0x9cc]
 *   @0xbaf60 ldr r2, [pc, #0x9cc]
 *   @0xbaf64 ldr r1, [pc, #0x9cc]
 *   @0xbaf68 ldr r3, [r4, r3]
 *   @0xbaf6c add r2, pc, r2
 *   @0xbaf70 add r1, pc, r1
 *   @0xbaf74 ldr r0, [r2]
 *   @0xbaf78 str r8, [r3]
 *   @0xbaf7c bl 0xb6514 <dlsym@plt>
 *   @0xbaf80 subs r8, r0, #0
 *   @0xbaf84 beq 0xbcb8c <_Z12GLFuncImportb+0x247c>
 *   @0xbaf88 ldr r3, [pc, #0x9ac]
 *   @0xbaf8c ldr r2, [pc, #0x9ac]
 *   @0xbaf90 ldr r1, [pc, #0x9ac]
 *   @0xbaf94 ldr r3, [r4, r3]
 *   @0xbaf98 add r2, pc, r2
 *   @0xbaf9c add r1, pc, r1
 *   @0xbafa0 ldr r0, [r2]
 *   @0xbafa4 str r8, [r3]
 *   @0xbafa8 bl 0xb6514 <dlsym@plt>
 *   @0xbafac subs r8, r0, #0
 *   @0xbafb0 beq 0xbcb6c <_Z12GLFuncImportb+0x245c>
 *   @0xbafb4 ldr r3, [pc, #0x98c]
 *   @0xbafb8 ldr r2, [pc, #0x98c]
 *   @0xbafbc ldr r1, [pc, #0x98c]
 *   @0xbafc0 ldr r3, [r4, r3]
 *   @0xbafc4 add r2, pc, r2
 *   @0xbafc8 add r1, pc, r1
 *   @0xbafcc ldr r0, [r2]
 *   @0xbafd0 str r8, [r3]
 *   @0xbafd4 bl 0xb6514 <dlsym@plt>
 *   @0xbafd8 subs r8, r0, #0
 *   @0xbafdc beq 0xbcb4c <_Z12GLFuncImportb+0x243c>
 *   @0xbafe0 ldr r3, [pc, #0x96c]
 *   @0xbafe4 ldr r2, [pc, #0x96c]
 *   @0xbafe8 ldr r1, [pc, #0x96c]
 *   @0xbafec ldr r3, [r4, r3]
 *   @0xbaff0 add r2, pc, r2
 *   @0xbaff4 add r1, pc, r1
 *   @0xbaff8 ldr r0, [r2]
 *   @0xbaffc str r8, [r3]
 *   @0xbb000 bl 0xb6514 <dlsym@plt>
 *   @0xbb004 subs r8, r0, #0
 *   @0xbb008 beq 0xbcb2c <_Z12GLFuncImportb+0x241c>
 *   @0xbb00c ldr r3, [pc, #0x94c]
 *   @0xbb010 ldr r2, [pc, #0x94c]
 *   @0xbb014 ldr r1, [pc, #0x94c]
 *   @0xbb018 ldr r3, [r4, r3]
 *   @0xbb01c add r2, pc, r2
 *   @0xbb020 add r1, pc, r1
 *   @0xbb024 ldr r0, [r2]
 *   @0xbb028 str r8, [r3]
 *   @0xbb02c bl 0xb6514 <dlsym@plt>
 *   @0xbb030 subs r8, r0, #0
 *   @0xbb034 beq 0xbcb0c <_Z12GLFuncImportb+0x23fc>
 *   @0xbb038 ldr r3, [pc, #0x92c]
 *   @0xbb03c ldr r2, [pc, #0x92c]
 *   @0xbb040 ldr r1, [pc, #0x92c]
 *   @0xbb044 ldr r3, [r4, r3]
 *   @0xbb048 add r2, pc, r2
 *   @0xbb04c add r1, pc, r1
 *   @0xbb050 ldr r0, [r2]
 *   @0xbb054 str r8, [r3]
 *   @0xbb058 bl 0xb6514 <dlsym@plt>
 *   @0xbb05c subs r8, r0, #0
 *   @0xbb060 beq 0xbcaec <_Z12GLFuncImportb+0x23dc>
 *   @0xbb064 ldr r3, [pc, #0x90c]
 *   @0xbb068 ldr r2, [pc, #0x90c]
 *   @0xbb06c ldr r1, [pc, #0x90c]
 *   @0xbb070 ldr r3, [r4, r3]
 *   @0xbb074 add r2, pc, r2
 *   @0xbb078 add r1, pc, r1
 *   @0xbb07c ldr r0, [r2]
 *   @0xbb080 str r8, [r3]
 *   @0xbb084 bl 0xb6514 <dlsym@plt>
 *   @0xbb088 subs r8, r0, #0
 *   @0xbb08c beq 0xbcacc <_Z12GLFuncImportb+0x23bc>
 *   @0xbb090 ldr r3, [pc, #0x8ec]
 *   @0xbb094 ldr r2, [pc, #0x8ec]
 *   @0xbb098 ldr r1, [pc, #0x8ec]
 *   @0xbb09c ldr r3, [r4, r3]
 *   @0xbb0a0 add r2, pc, r2
 *   @0xbb0a4 add r1, pc, r1
 *   @0xbb0a8 ldr r0, [r2]
 *   @0xbb0ac str r8, [r3]
 *   @0xbb0b0 bl 0xb6514 <dlsym@plt>
 *   @0xbb0b4 subs r8, r0, #0
 *   @0xbb0b8 beq 0xbd18c <_Z12GLFuncImportb+0x2a7c>
 *   @0xbb0bc ldr r3, [pc, #0x8cc]
 *   @0xbb0c0 ldr r2, [pc, #0x8cc]
 *   @0xbb0c4 ldr r1, [pc, #0x8cc]
 *   @0xbb0c8 ldr r3, [r4, r3]
 *   @0xbb0cc add r2, pc, r2
 *   @0xbb0d0 add r1, pc, r1
 *   @0xbb0d4 ldr r0, [r2]
 *   @0xbb0d8 str r8, [r3]
 *   @0xbb0dc bl 0xb6514 <dlsym@plt>
 *   @0xbb0e0 subs r8, r0, #0
 *   @0xbb0e4 beq 0xbd16c <_Z12GLFuncImportb+0x2a5c>
 *   @0xbb0e8 ldr r3, [pc, #0x8ac]
 *   @0xbb0ec ldr r2, [pc, #0x8ac]
 *   @0xbb0f0 ldr r1, [pc, #0x8ac]
 *   @0xbb0f4 ldr r3, [r4, r3]
 *   @0xbb0f8 add r2, pc, r2
 *   @0xbb0fc add r1, pc, r1
 *   @0xbb100 ldr r0, [r2]
 *   @0xbb104 str r8, [r3]
 *   @0xbb108 bl 0xb6514 <dlsym@plt>
 *   @0xbb10c subs r8, r0, #0
 *   @0xbb110 beq 0xbd14c <_Z12GLFuncImportb+0x2a3c>
 *   @0xbb114 ldr r3, [pc, #0x88c]
 *   @0xbb118 ldr r2, [pc, #0x88c]
 *   @0xbb11c ldr r1, [pc, #0x88c]
 *   @0xbb120 ldr r3, [r4, r3]
 *   @0xbb124 add r2, pc, r2
 *   @0xbb128 add r1, pc, r1
 *   @0xbb12c ldr r0, [r2]
 *   @0xbb130 str r8, [r3]
 *   @0xbb134 bl 0xb6514 <dlsym@plt>
 *   @0xbb138 subs r8, r0, #0
 *   @0xbb13c beq 0xbd12c <_Z12GLFuncImportb+0x2a1c>
 *   @0xbb140 ldr r3, [pc, #0x86c]
 *   @0xbb144 ldr r2, [pc, #0x86c]
 *   @0xbb148 ldr r1, [pc, #0x86c]
 *   @0xbb14c ldr r3, [r4, r3]
 *   @0xbb150 add r2, pc, r2
 *   @0xbb154 add r1, pc, r1
 *   @0xbb158 ldr r0, [r2]
 *   @0xbb15c str r8, [r3]
 *   @0xbb160 bl 0xb6514 <dlsym@plt>
 *   @0xbb164 subs r8, r0, #0
 *   @0xbb168 beq 0xbd10c <_Z12GLFuncImportb+0x29fc>
 *   @0xbb16c ldr r3, [pc, #0x84c]
 *   @0xbb170 ldr r2, [pc, #0x84c]
 *   @0xbb174 ldr r1, [pc, #0x84c]
 *   @0xbb178 ldr r3, [r4, r3]
 *   @0xbb17c add r2, pc, r2
 *   @0xbb180 add r1, pc, r1
 *   @0xbb184 ldr r0, [r2]
 *   @0xbb188 str r8, [r3]
 *   @0xbb18c bl 0xb6514 <dlsym@plt>
 *   @0xbb190 subs r8, r0, #0
 *   @0xbb194 beq 0xbd0ec <_Z12GLFuncImportb+0x29dc>
 *   @0xbb198 ldr r3, [pc, #0x82c]
 *   @0xbb19c ldr r2, [pc, #0x82c]
 *   @0xbb1a0 ldr r1, [pc, #0x82c]
 *   @0xbb1a4 ldr r3, [r4, r3]
 *   @0xbb1a8 add r2, pc, r2
 *   @0xbb1ac add r1, pc, r1
 *   @0xbb1b0 ldr r0, [r2]
 *   @0xbb1b4 str r8, [r3]
 *   @0xbb1b8 bl 0xb6514 <dlsym@plt>
 *   @0xbb1bc subs r8, r0, #0
 *   @0xbb1c0 beq 0xbd0cc <_Z12GLFuncImportb+0x29bc>
 *   @0xbb1c4 ldr r3, [pc, #0x80c]
 *   @0xbb1c8 ldr r2, [pc, #0x80c]
 *   @0xbb1cc ldr r1, [pc, #0x80c]
 *   @0xbb1d0 ldr r3, [r4, r3]
 *   @0xbb1d4 add r2, pc, r2
 *   @0xbb1d8 add r1, pc, r1
 *   @0xbb1dc ldr r0, [r2]
 *   @0xbb1e0 str r8, [r3]
 *   @0xbb1e4 bl 0xb6514 <dlsym@plt>
 *   @0xbb1e8 subs r8, r0, #0
 *   @0xbb1ec beq 0xbd0ac <_Z12GLFuncImportb+0x299c>
 *   @0xbb1f0 ldr r3, [pc, #0x7ec]
 *   @0xbb1f4 ldr r2, [pc, #0x7ec]
 *   @0xbb1f8 ldr r1, [pc, #0x7ec]
 *   @0xbb1fc ldr r3, [r4, r3]
 *   @0xbb200 add r2, pc, r2
 *   @0xbb204 add r1, pc, r1
 *   @0xbb208 ldr r0, [r2]
 *   @0xbb20c str r8, [r3]
 *   @0xbb210 bl 0xb6514 <dlsym@plt>
 *   @0xbb214 subs r8, r0, #0
 *   @0xbb218 beq 0xbd08c <_Z12GLFuncImportb+0x297c>
 *   @0xbb21c ldr r3, [pc, #0x7cc]
 *   @0xbb220 ldr r2, [pc, #0x7cc]
 *   @0xbb224 ldr r1, [pc, #0x7cc]
 *   @0xbb228 ldr r3, [r4, r3]
 *   @0xbb22c add r2, pc, r2
 *   @0xbb230 add r1, pc, r1
 *   @0xbb234 ldr r0, [r2]
 *   @0xbb238 str r8, [r3]
 *   @0xbb23c bl 0xb6514 <dlsym@plt>
 *   @0xbb240 subs r8, r0, #0
 *   @0xbb244 beq 0xbd06c <_Z12GLFuncImportb+0x295c>
 *   @0xbb248 ldr r3, [pc, #0x7ac]
 *   @0xbb24c ldr r2, [pc, #0x7ac]
 *   @0xbb250 ldr r1, [pc, #0x7ac]
 *   @0xbb254 ldr r3, [r4, r3]
 *   @0xbb258 add r2, pc, r2
 *   @0xbb25c add r1, pc, r1
 *   @0xbb260 ldr r0, [r2]
 *   @0xbb264 str r8, [r3]
 *   @0xbb268 bl 0xb6514 <dlsym@plt>
 *   @0xbb26c subs r8, r0, #0
 *   @0xbb270 beq 0xbd04c <_Z12GLFuncImportb+0x293c>
 *   @0xbb274 ldr r3, [pc, #0x78c]
 *   @0xbb278 ldr r2, [pc, #0x78c]
 *   @0xbb27c ldr r1, [pc, #0x78c]
 *   @0xbb280 ldr r3, [r4, r3]
 *   @0xbb284 add r2, pc, r2
 *   @0xbb288 add r1, pc, r1
 *   @0xbb28c ldr r0, [r2]
 *   @0xbb290 str r8, [r3]
 *   @0xbb294 bl 0xb6514 <dlsym@plt>
 *   @0xbb298 subs r8, r0, #0
 *   @0xbb29c beq 0xbd02c <_Z12GLFuncImportb+0x291c>
 *   @0xbb2a0 ldr r3, [pc, #0x76c]
 *   @0xbb2a4 ldr r2, [pc, #0x76c]
 *   @0xbb2a8 ldr r1, [pc, #0x76c]
 *   @0xbb2ac ldr r3, [r4, r3]
 *   @0xbb2b0 add r2, pc, r2
 *   @0xbb2b4 add r1, pc, r1
 *   @0xbb2b8 ldr r0, [r2]
 *   @0xbb2bc str r8, [r3]
 *   @0xbb2c0 bl 0xb6514 <dlsym@plt>
 *   @0xbb2c4 subs r8, r0, #0
 *   @0xbb2c8 beq 0xbd00c <_Z12GLFuncImportb+0x28fc>
 *   @0xbb2cc ldr r3, [pc, #0x74c]
 *   @0xbb2d0 ldr r2, [pc, #0x74c]
 *   @0xbb2d4 ldr r1, [pc, #0x74c]
 *   @0xbb2d8 ldr r3, [r4, r3]
 *   @0xbb2dc add r2, pc, r2
 *   @0xbb2e0 add r1, pc, r1
 *   @0xbb2e4 ldr r0, [r2]
 *   @0xbb2e8 str r8, [r3]
 *   @0xbb2ec bl 0xb6514 <dlsym@plt>
 *   @0xbb2f0 subs r8, r0, #0
 *   @0xbb2f4 beq 0xbcfec <_Z12GLFuncImportb+0x28dc>
 *   @0xbb2f8 ldr r3, [pc, #0x72c]
 *   @0xbb2fc ldr r2, [pc, #0x72c]
 *   @0xbb300 ldr r1, [pc, #0x72c]
 *   @0xbb304 ldr r3, [r4, r3]
 *   @0xbb308 add r2, pc, r2
 *   @0xbb30c add r1, pc, r1
 *   @0xbb310 ldr r0, [r2]
 *   @0xbb314 str r8, [r3]
 *   @0xbb318 bl 0xb6514 <dlsym@plt>
 *   @0xbb31c subs r8, r0, #0
 *   @0xbb320 beq 0xbcfcc <_Z12GLFuncImportb+0x28bc>
 *   @0xbb324 ldr r3, [pc, #0x70c]
 *   @0xbb328 ldr r2, [pc, #0x70c]
 *   @0xbb32c ldr r1, [pc, #0x70c]
 *   @0xbb330 ldr r3, [r4, r3]
 *   @0xbb334 add r2, pc, r2
 *   @0xbb338 add r1, pc, r1
 *   @0xbb33c ldr r0, [r2]
 *   @0xbb340 str r8, [r3]
 *   @0xbb344 bl 0xb6514 <dlsym@plt>
 *   @0xbb348 subs r8, r0, #0
 *   @0xbb34c beq 0xbcfac <_Z12GLFuncImportb+0x289c>
 *   @0xbb350 ldr r3, [pc, #0x6ec]
 *   @0xbb354 ldr r2, [pc, #0x6ec]
 *   @0xbb358 ldr r1, [pc, #0x6ec]
 *   @0xbb35c ldr r3, [r4, r3]
 *   @0xbb360 add r2, pc, r2
 *   @0xbb364 add r1, pc, r1
 *   @0xbb368 ldr r0, [r2]
 *   @0xbb36c str r8, [r3]
 *   @0xbb370 bl 0xb6514 <dlsym@plt>
 *   @0xbb374 subs r8, r0, #0
 *   @0xbb378 beq 0xbcf8c <_Z12GLFuncImportb+0x287c>
 *   @0xbb37c ldr r3, [pc, #0x6cc]
 *   @0xbb380 ldr r2, [pc, #0x6cc]
 *   @0xbb384 ldr r1, [pc, #0x6cc]
 *   @0xbb388 ldr r3, [r4, r3]
 *   @0xbb38c add r2, pc, r2
 *   @0xbb390 add r1, pc, r1
 *   @0xbb394 ldr r0, [r2]
 *   @0xbb398 str r8, [r3]
 *   @0xbb39c bl 0xb6514 <dlsym@plt>
 *   @0xbb3a0 subs r8, r0, #0
 *   @0xbb3a4 beq 0xbcf6c <_Z12GLFuncImportb+0x285c>
 *   @0xbb3a8 ldr r3, [pc, #0x6ac]
 *   @0xbb3ac ldr r2, [pc, #0x6ac]
 *   @0xbb3b0 ldr r1, [pc, #0x6ac]
 *   @0xbb3b4 ldr r3, [r4, r3]
 *   @0xbb3b8 add r2, pc, r2
 *   @0xbb3bc add r1, pc, r1
 *   @0xbb3c0 ldr r0, [r2]
 *   @0xbb3c4 str r8, [r3]
 *   @0xbb3c8 bl 0xb6514 <dlsym@plt>
 *   @0xbb3cc subs r8, r0, #0
 *   @0xbb3d0 beq 0xbcf4c <_Z12GLFuncImportb+0x283c>
 *   @0xbb3d4 ldr r3, [pc, #0x68c]
 *   @0xbb3d8 ldr r2, [pc, #0x68c]
 *   @0xbb3dc ldr r1, [pc, #0x68c]
 *   @0xbb3e0 ldr r3, [r4, r3]
 *   @0xbb3e4 add r2, pc, r2
 *   @0xbb3e8 add r1, pc, r1
 *   @0xbb3ec ldr r0, [r2]
 *   @0xbb3f0 str r8, [r3]
 *   @0xbb3f4 bl 0xb6514 <dlsym@plt>
 *   @0xbb3f8 subs r8, r0, #0
 *   @0xbb3fc beq 0xbcf2c <_Z12GLFuncImportb+0x281c>
 *   @0xbb400 ldr r3, [pc, #0x66c]
 *   @0xbb404 ldr r2, [pc, #0x66c]
 *   @0xbb408 ldr r1, [pc, #0x66c]
 *   @0xbb40c ldr r3, [r4, r3]
 *   @0xbb410 add r2, pc, r2
 *   @0xbb414 add r1, pc, r1
 *   @0xbb418 ldr r0, [r2]
 *   @0xbb41c str r8, [r3]
 *   @0xbb420 bl 0xb6514 <dlsym@plt>
 *   @0xbb424 subs r8, r0, #0
 *   @0xbb428 beq 0xbcf0c <_Z12GLFuncImportb+0x27fc>
 *   @0xbb42c ldr r3, [pc, #0x64c]
 *   @0xbb430 ldr r2, [pc, #0x64c]
 *   @0xbb434 ldr r1, [pc, #0x64c]
 *   @0xbb438 ldr r3, [r4, r3]
 *   @0xbb43c add r2, pc, r2
 *   @0xbb440 add r1, pc, r1
 *   @0xbb444 ldr r0, [r2]
 *   @0xbb448 str r8, [r3]
 *   @0xbb44c bl 0xb6514 <dlsym@plt>
 *   @0xbb450 subs r8, r0, #0
 *   @0xbb454 beq 0xbceec <_Z12GLFuncImportb+0x27dc>
 *   @0xbb458 ldr r3, [pc, #0x62c]
 *   @0xbb45c ldr r2, [pc, #0x62c]
 *   @0xbb460 ldr r1, [pc, #0x62c]
 *   @0xbb464 ldr r3, [r4, r3]
 *   @0xbb468 add r2, pc, r2
 *   @0xbb46c add r1, pc, r1
 *   @0xbb470 ldr r0, [r2]
 *   @0xbb474 str r8, [r3]
 *   @0xbb478 bl 0xb6514 <dlsym@plt>
 *   @0xbb47c subs r8, r0, #0
 *   @0xbb480 beq 0xbcecc <_Z12GLFuncImportb+0x27bc>
 *   @0xbb484 ldr r3, [pc, #0x60c]
 *   @0xbb488 ldr r2, [pc, #0x60c]
 *   @0xbb48c ldr r1, [pc, #0x60c]
 *   @0xbb490 ldr r3, [r4, r3]
 *   @0xbb494 add r2, pc, r2
 *   @0xbb498 add r1, pc, r1
 *   @0xbb49c ldr r0, [r2]
 *   @0xbb4a0 str r8, [r3]
 *   @0xbb4a4 bl 0xb6514 <dlsym@plt>
 *   @0xbb4a8 subs r8, r0, #0
 *   @0xbb4ac beq 0xbceac <_Z12GLFuncImportb+0x279c>
 *   @0xbb4b0 ldr r3, [pc, #0x5ec]
 *   @0xbb4b4 ldr r2, [pc, #0x5ec]
 *   @0xbb4b8 ldr r1, [pc, #0x5ec]
 *   @0xbb4bc ldr r3, [r4, r3]
 *   @0xbb4c0 add r2, pc, r2
 *   @0xbb4c4 add r1, pc, r1
 *   @0xbb4c8 ldr r0, [r2]
 *   @0xbb4cc str r8, [r3]
 *   @0xbb4d0 bl 0xb6514 <dlsym@plt>
 *   @0xbb4d4 subs r8, r0, #0
 *   @0xbb4d8 beq 0xbce8c <_Z12GLFuncImportb+0x277c>
 *   @0xbb4dc ldr r3, [pc, #0x5cc]
 *   @0xbb4e0 ldr r2, [pc, #0x5cc]
 *   @0xbb4e4 ldr r1, [pc, #0x5cc]
 *   @0xbb4e8 ldr r3, [r4, r3]
 *   @0xbb4ec add r2, pc, r2
 *   @0xbb4f0 add r1, pc, r1
 *   @0xbb4f4 ldr r0, [r2]
 *   @0xbb4f8 str r8, [r3]
 *   @0xbb4fc bl 0xb6514 <dlsym@plt>
 *   @0xbb500 subs r8, r0, #0
 *   @0xbb504 beq 0xbce6c <_Z12GLFuncImportb+0x275c>
 *   @0xbb508 ldr r3, [pc, #0x5ac]
 *   @0xbb50c ldr r2, [pc, #0x5ac]
 *   @0xbb510 ldr r1, [pc, #0x5ac]
 *   @0xbb514 ldr r3, [r4, r3]
 *   @0xbb518 add r2, pc, r2
 *   @0xbb51c add r1, pc, r1
 *   @0xbb520 ldr r0, [r2]
 *   @0xbb524 str r8, [r3]
 *   @0xbb528 bl 0xb6514 <dlsym@plt>
 *   @0xbb52c subs r8, r0, #0
 *   @0xbb530 beq 0xbce4c <_Z12GLFuncImportb+0x273c>
 *   @0xbb534 ldr r3, [pc, #0x58c]
 *   @0xbb538 ldr r2, [pc, #0x58c]
 *   @0xbb53c ldr r1, [pc, #0x58c]
 *   @0xbb540 ldr r3, [r4, r3]
 *   @0xbb544 add r2, pc, r2
 *   @0xbb548 add r1, pc, r1
 *   @0xbb54c ldr r0, [r2]
 *   @0xbb550 str r8, [r3]
 *   @0xbb554 bl 0xb6514 <dlsym@plt>
 *   @0xbb558 subs r8, r0, #0
 *   @0xbb55c beq 0xbce2c <_Z12GLFuncImportb+0x271c>
 *   @0xbb560 ldr r3, [pc, #0x56c]
 *   @0xbb564 ldr r2, [pc, #0x56c]
 *   @0xbb568 ldr r1, [pc, #0x56c]
 *   @0xbb56c ldr r3, [r4, r3]
 *   @0xbb570 add r2, pc, r2
 *   @0xbb574 add r1, pc, r1
 *   @0xbb578 ldr r0, [r2]
 *   @0xbb57c str r8, [r3]
 *   @0xbb580 bl 0xb6514 <dlsym@plt>
 *   @0xbb584 subs r8, r0, #0
 *   @0xbb588 beq 0xbce0c <_Z12GLFuncImportb+0x26fc>
 *   @0xbb58c ldr r3, [pc, #0x54c]
 *   @0xbb590 ldr r2, [pc, #0x54c]
 *   @0xbb594 ldr r1, [pc, #0x54c]
 *   @0xbb598 ldr r3, [r4, r3]
 *   @0xbb59c add r2, pc, r2
 *   @0xbb5a0 add r1, pc, r1
 *   @0xbb5a4 ldr r0, [r2]
 *   @0xbb5a8 str r8, [r3]
 *   @0xbb5ac bl 0xb6514 <dlsym@plt>
 *   @0xbb5b0 subs r8, r0, #0
 *   @0xbb5b4 beq 0xbcdec <_Z12GLFuncImportb+0x26dc>
 *   @0xbb5b8 ldr r3, [pc, #0x52c]
 *   @0xbb5bc ldr r2, [pc, #0x52c]
 *   @0xbb5c0 ldr r1, [pc, #0x52c]
 *   @0xbb5c4 ldr r3, [r4, r3]
 *   @0xbb5c8 add r2, pc, r2
 *   @0xbb5cc add r1, pc, r1
 *   @0xbb5d0 ldr r0, [r2]
 *   @0xbb5d4 str r8, [r3]
 *   @0xbb5d8 bl 0xb6514 <dlsym@plt>
 *   @0xbb5dc subs r8, r0, #0
 *   @0xbb5e0 beq 0xbcdcc <_Z12GLFuncImportb+0x26bc>
 *   @0xbb5e4 ldr r3, [pc, #0x50c]
 *   @0xbb5e8 ldr r2, [pc, #0x50c]
 *   @0xbb5ec ldr r1, [pc, #0x50c]
 *   @0xbb5f0 ldr r3, [r4, r3]
 *   @0xbb5f4 add r2, pc, r2
 *   @0xbb5f8 add r1, pc, r1
 *   @0xbb5fc ldr r0, [r2]
 *   @0xbb600 str r8, [r3]
 *   @0xbb604 bl 0xb6514 <dlsym@plt>
 *   @0xbb608 subs r8, r0, #0
 *   @0xbb60c beq 0xbcdac <_Z12GLFuncImportb+0x269c>
 *   @0xbb610 ldr r3, [pc, #0x4ec]
 *   @0xbb614 ldr r3, [r4, r3]
 *   @0xbb618 str r8, [r3]
 *   @0xbb61c ldr r3, [r5]
 *   @0xbb620 mov r0, r5
 *   @0xbb624 ldr r1, [pc, #0x4dc]
 *   @0xbb628 ldr r3, [r3, #0xc]
 *   @0xbb62c add r1, pc, r1
 *   @0xbb630 blx r3
 *   @0xbb634 str r6, [r7]
 *   @0xbb638 mov r0, r6
 *   @0xbb63c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xbb640 ldr r0, [pc, #0x4c4]
 *   @0xbb644 mov r1, r6
 *   @0xbb648 ldr r6, [pc, #0x4c0]
 *   @0xbb64c add r0, pc, r0
 *   @0xbb650 bl 0xb6520 <dlopen@plt>
 *   @0xbb654 ldr r3, [r5]
 *   @0xbb658 add r6, pc, r6
 *   @0xbb65c ldr r1, [pc, #0x4b0]
 *   @0xbb660 ldr r3, [r3, #0xc]
 *   @0xbb664 add r1, pc, r1
 *   @0xbb668 str r0, [r6]
 *   @0xbb66c mov r0, r5
 *   @0xbb670 blx r3
 *   @0xbb674 ldr r9, [r6]
 *   @0xbb678 cmp r9, #0
 *   @0xbb67c movne r6, #2
 *   @0xbb680 bne 0xba77c <_Z12GLFuncImportb+0x6c>
 *   @0xbb684 ldr r3, [r5]
 *   @0xbb688 mov r0, r5
 *   @0xbb68c ldr r1, [pc, #0x484]
 *   @0xbb690 ldr r3, [r3, #0xc]
 *   @0xbb694 add r1, pc, r1
 *   @0xbb698 blx r3
 *   @0xbb69c ldr r0, [pc, #0x478]
 *   @0xbb6a0 mov r1, #0
 *   @0xbb6a4 ldr r6, [pc, #0x474]
 *   @0xbb6a8 add r0, pc, r0
 *   @0xbb6ac bl 0xb6520 <dlopen@plt>
 *   @0xbb6b0 ldr r3, [r5]
 *   @0xbb6b4 add r6, pc, r6
 *   @0xbb6b8 ldr r1, [pc, #0x464]
 *   @0xbb6bc ldr r3, [r3, #0xc]
 *   @0xbb6c0 add r1, pc, r1
 *   @0xbb6c4 str r0, [r6]
 *   @0xbb6c8 mov r0, r5
 *   @0xbb6cc blx r3
 *   @0xbb6d0 ldr r9, [r6]
 *   @0xbb6d4 cmp r9, #0
 *   @0xbb6d8 bne 0xbd5ac <_Z12GLFuncImportb+0x2e9c>
 *   @0xbb6dc ldr r3, [r5]
 *   @0xbb6e0 mov r0, r5
 *   @0xbb6e4 ldr r1, [pc, #0x43c]
 *   @0xbb6e8 ldr r3, [r3, #0xc]
 *   @0xbb6ec add r1, pc, r1
 *   @0xbb6f0 blx r3
 *   @0xbb6f4 mov r0, r9
 *   @0xbb6f8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xbb6fc eorseq r7, r3, r0, lsr r5
 *   @0xbb700 .word 0xffffbac0
 *   @0xbb704 .word 0xffffbac4
 *   @0xbb708 eoreq r4, r7, r0, ror #7
 *   @0xbb70c eorseq pc, r11, r12, lsl r3
 *   @0xbb710 eoreq r4, r7, r0, asr #8
 *   @0xbb714 .word 0xffffbac8
 *   @0xbb718 eorseq pc, r11, r0, ror #5
 *   @0xbb71c eoreq r4, r7, r8, asr #8
 *   @0xbb720 .word 0xffffbacc
 *   @0xbb724 ldrhteq pc, [r11], -r4
 *   @0xbb728 eoreq r4, r7, r0, asr #8
 *   @0xbb72c .word 0xffffbad0
 *   @0xbb730 eorseq pc, r11, r8, lsl #5
 *   @0xbb734 eoreq r4, r7, r0, asr #8
 *   @0xbb738 .word 0xffffbad4
 *   @0xbb73c eorseq pc, r11, r12, asr r2
 *   @0xbb740 eoreq r4, r7, r8, asr #8
 *   @0xbb744 .word 0xffffbad8
 *   @0xbb748 eorseq pc, r11, r0, lsr r2
 *   @0xbb74c eoreq r4, r7, r8, asr #8
 *   @0xbb750 .word 0xffffbadc
 *   @0xbb754 eorseq pc, r11, r4, lsl #4
 *   @0xbb758 eoreq r4, r7, r8, asr #8
 *   @0xbb75c .word 0xffffbae0
 *   @0xbb760 ldrsbteq pc, [r11], -r8
 *   @0xbb764 eoreq r4, r7, r8, asr #8
 *   @0xbb768 .word 0xffffbae4
 *   @0xbb76c eorseq pc, r11, r12, lsr #3
 *   @0xbb770 eoreq r4, r7, r8, asr #8
 *   @0xbb774 .word 0xffffbae8
 *   @0xbb778 eorseq pc, r11, r0, lsl #3
 *   @0xbb77c eoreq r4, r7, r0, asr r4
 *   @0xbb780 .word 0xffffbaec
 *   @0xbb784 eorseq pc, r11, r4, asr r1
 *   @0xbb788 eoreq r4, r7, r0, asr r4
 *   @0xbb78c .word 0xffffbaf0
 *   @0xbb790 eorseq pc, r11, r8, lsr #2
 *   @0xbb794 eoreq r4, r7, r0, asr r4
 *   @0xbb798 .word 0xffffbaf4
 *   @0xbb79c ldrshteq pc, [r11], -r12
 *   @0xbb7a0 eoreq r4, r7, r8, asr r4
 *   @0xbb7a4 .word 0xffffbaf8
 *   @0xbb7a8 ldrsbteq pc, [r11], -r0
 *   @0xbb7ac eoreq r4, r7, r0, ror #8
 *   @0xbb7b0 .word 0xffffbafc
 *   @0xbb7b4 eorseq pc, r11, r4, lsr #1
 *   @0xbb7b8 eoreq r4, r7, r8, asr r4
 *   @0xbb7bc .word 0xffffbb00
 *   @0xbb7c0 eorseq pc, r11, r8, ror r0
 *   @0xbb7c4 eoreq r4, r7, r0, ror #8
 *   @0xbb7c8 .word 0xffffbb04
 *   @0xbb7cc eorseq pc, r11, r12, asr #32
 *   @0xbb7d0 eoreq r4, r7, r8, ror #8
 *   @0xbb7d4 .word 0xffffbb08
 *   @0xbb7d8 eorseq pc, r11, r0, lsr #32
 *   @0xbb7dc eoreq r4, r7, r0, ror r4
 *   @0xbb7e0 .word 0xffffbb0c
 *   @0xbb7e4 ldrshteq lr, [r11], -r4
 *   @0xbb7e8 eoreq r4, r7, r0, ror r4
 *   @0xbb7ec .word 0xffffbb10
 *   @0xbb7f0 eorseq lr, r11, r8, asr #31
 *   @0xbb7f4 eoreq r4, r7, r0, ror r4
 *   @0xbb7f8 .word 0xffffbb14
 *   @0xbb7fc mlaseq r11, r12, pc, lr
 *   @0xbb800 eoreq r4, r7, r8, ror #8
 *   @0xbb804 .word 0xffffbb18
 *   @0xbb808 eorseq lr, r11, r0, ror pc
 *   @0xbb80c eoreq r4, r7, r8, ror #8
 *   @0xbb810 .word 0xffffbb1c
 *   @0xbb814 eorseq lr, r11, r4, asr #30
 *   @0xbb818 eoreq r4, r7, r0, ror r4
 *   @0xbb81c .word 0xffffbb20
 *   @0xbb820 eorseq lr, r11, r8, lsl pc
 *   @0xbb824 eoreq r4, r7, r8, ror r4
 *   @0xbb828 .word 0xffffbb24
 *   @0xbb82c eorseq lr, r11, r12, ror #29
 *   @0xbb830 eoreq r4, r7, r8, lsl #9
 *   @0xbb834 .word 0xffffbb28
 *   @0xbb838 eorseq lr, r11, r0, asr #29
 *   @0xbb83c mlaeq r7, r0, r4, r4
 *   @0xbb840 .word 0xffffbb2c
 *   @0xbb844 mlaseq r11, r4, lr, lr
 *   @0xbb848 mlaeq r7, r8, r4, r4
 *   @0xbb84c .word 0xffffbb30
 *   @0xbb850 eorseq lr, r11, r8, ror #28
 *   @0xbb854 eoreq r4, r7, r0, lsr #9
 *   @0xbb858 .word 0xffffbb34
 *   @0xbb85c eorseq lr, r11, r12, lsr lr
 *   @0xbb860 eoreq r4, r7, r8, lsr #9
 *   @0xbb864 .word 0xffffbb38
 *   @0xbb868 eorseq lr, r11, r0, lsl lr
 *   @0xbb86c .word 0x002744b0
 *   @0xbb870 .word 0xffffbb3c
 *   @0xbb874 eorseq lr, r11, r4, ror #27
 *   @0xbb878 .word 0x002744b8
 *   @0xbb87c .word 0xffffbb40
 *   @0xbb880 ldrhteq lr, [r11], -r8
 *   @0xbb884 eoreq r4, r7, r0, asr #9
 *   @0xbb888 .word 0xffffbb44
 *   @0xbb88c eorseq lr, r11, r12, lsl #27
 *   @0xbb890 eoreq r4, r7, r8, asr #9
 *   @0xbb894 .word 0xffffbb48
 *   @0xbb898 eorseq lr, r11, r0, ror #26
 *   @0xbb89c .word 0x002744d0
 *   @0xbb8a0 .word 0xffffbb4c
 *   @0xbb8a4 eorseq lr, r11, r4, lsr sp
 *   @0xbb8a8 .word 0x002744d0
 *   @0xbb8ac .word 0xffffbb50
 *   @0xbb8b0 eorseq lr, r11, r8, lsl #26
 *   @0xbb8b4 .word 0x002744d0
 *   @0xbb8b8 .word 0xffffbb54
 *   @0xbb8bc ldrsbteq lr, [r11], -r12
 *   @0xbb8c0 .word 0x002744d8
 *   @0xbb8c4 .word 0xffffbb58
 *   @0xbb8c8 ldrhteq lr, [r11], -r0
 *   @0xbb8cc eoreq r4, r7, r0, ror #9
 *   @0xbb8d0 .word 0xffffbb5c
 *   @0xbb8d4 eorseq lr, r11, r4, lsl #25
 *   @0xbb8d8 eoreq r4, r7, r0, ror #9
 *   @0xbb8dc .word 0xffffbb60
 *   @0xbb8e0 eorseq lr, r11, r8, asr r12
 *   @0xbb8e4 eoreq r4, r7, r0, ror #9
 *   @0xbb8e8 .word 0xffffbb64
 *   @0xbb8ec eorseq lr, r11, r0, lsr #24
 *   @0xbb8f0 .word 0x002758b8
 *   @0xbb8f4 .word 0xffffbb68
 *   @0xbb8f8 ldrshteq lr, [r11], -r8
 *   @0xbb8fc eoreq r4, r7, r0, asr lr
 *   @0xbb900 .word 0xffffbb6c
 *   @0xbb904 eorseq lr, r11, r12, asr #23
 *   @0xbb908 eoreq r4, r7, r8, ror #28
 *   @0xbb90c .word 0xffffbb70
 *   @0xbb910 eorseq lr, r11, r0, lsr #23
 *   @0xbb914 eoreq r4, r7, r0, lsl #29
 *   @0xbb918 .word 0xffffbb74
 *   @0xbb91c eorseq lr, r11, r4, ror r11
 *   @0xbb920 mlaeq r7, r0, lr, r4
 *   @0xbb924 .word 0xffffbb78
 *   @0xbb928 eorseq lr, r11, r8, asr #22
 *   @0xbb92c mlaeq r7, r8, lr, r4
 *   @0xbb930 .word 0xffffbb7c
 *   @0xbb934 eorseq lr, r11, r12, lsl r11
 *   @0xbb938 eoreq r4, r7, r0, lsr #29
 *   @0xbb93c .word 0xffffbb80
 *   @0xbb940 ldrshteq lr, [r11], -r0
 *   @0xbb944 eoreq r4, r7, r8, lsr #29
 *   @0xbb948 .word 0xffffbb84
 *   @0xbb94c eorseq lr, r11, r4, asr #21
 *   @0xbb950 eoreq r4, r7, r8, lsr #29
 *   @0xbb954 .word 0xffffbb88
 *   @0xbb958 mlaseq r11, r8, r10, lr
 *   @0xbb95c eoreq r4, r7, r8, asr #29
 *   @0xbb960 .word 0xffffbb8c
 *   @0xbb964 eorseq lr, r11, r12, ror #20
 *   @0xbb968 eoreq r4, r7, r8, ror #29
 *   @0xbb96c .word 0xffffbb90
 *   @0xbb970 eorseq lr, r11, r0, asr #20
 *   @0xbb974 eoreq r4, r7, r0, lsl #30
 *   @0xbb978 .word 0xffffbb94
 *   @0xbb97c eorseq lr, r11, r4, lsl r10
 *   @0xbb980 eoreq r4, r7, r8, lsl #30
 *   @0xbb984 .word 0xffffbb98
 *   @0xbb988 eorseq lr, r11, r8, ror #19
 *   @0xbb98c eoreq r4, r7, r0, lsl pc
 *   @0xbb990 .word 0xffffbb9c
 *   @0xbb994 ldrhteq lr, [r11], -r12
 *   @0xbb998 eoreq r4, r7, r8, lsl pc
 *   @0xbb99c .word 0xffffbba0
 *   @0xbb9a0 mlaseq r11, r0, r9, lr
 *   @0xbb9a4 eoreq r4, r7, r0, lsr #30
 *   @0xbb9a8 .word 0xffffbba4
 *   @0xbb9ac eorseq lr, r11, r4, ror #18
 *   @0xbb9b0 eoreq r4, r7, r0, lsr pc
 *   @0xbb9b4 .word 0xffffbba8
 *   @0xbb9b8 eorseq lr, r11, r8, lsr r9
 *   @0xbb9bc eoreq r4, r7, r8, lsr pc
 *   @0xbb9c0 .word 0xffffbbac
 *   @0xbb9c4 eorseq lr, r11, r12, lsl #18
 *   @0xbb9c8 eoreq r4, r7, r0, asr #30
 *   @0xbb9cc .word 0xffffbbb0
 *   @0xbb9d0 eorseq lr, r11, r0, ror #17
 *   @0xbb9d4 eoreq r4, r7, r8, asr #30
 *   @0xbb9d8 .word 0xffffbbb4
 *   @0xbb9dc ldrhteq lr, [r11], -r4
 *   @0xbb9e0 eoreq r4, r7, r0, asr pc
 *   @0xbb9e4 .word 0xffffbbb8
 *   @0xbb9e8 eorseq lr, r11, r8, lsl #17
 *   @0xbb9ec eoreq r4, r7, r0, ror #30
 *   @0xbb9f0 .word 0xffffbbbc
 *   @0xbb9f4 eorseq lr, r11, r12, asr r8
 *   @0xbb9f8 eoreq r4, r7, r0, ror pc
 *   @0xbb9fc .word 0xffffbbc0
 *   @0xbba00 eorseq lr, r11, r0, lsr r8
 *   @0xbba04 eoreq r4, r7, r8, lsl #31
 *   @0xbba08 .word 0xffffbbc4
 *   @0xbba0c eorseq lr, r11, r4, lsl #16
 *   @0xbba10 mlaeq r7, r0, pc, r4
 *   @0xbba14 .word 0xffffbbc8
 *   @0xbba18 ldrsbteq lr, [r11], -r8
 *   @0xbba1c mlaeq r7, r8, pc, r4
 *   @0xbba20 .word 0xffffbbcc
 *   @0xbba24 eorseq lr, r11, r12, lsr #15
 *   @0xbba28 eoreq r4, r7, r0, lsr #31
 *   @0xbba2c .word 0xffffbbd0
 *   @0xbba30 eorseq lr, r11, r0, lsl #15
 *   @0xbba34 eoreq r4, r7, r8, lsr #31
 *   @0xbba38 .word 0xffffbbd4
 *   @0xbba3c eorseq lr, r11, r4, asr r7
 *   @0xbba40 .word 0x00274fb0
 *   @0xbba44 .word 0xffffbbd8
 *   @0xbba48 eorseq lr, r11, r8, lsr #14
 *   @0xbba4c .word 0x00274fb8
 *   @0xbba50 .word 0xffffbbdc
 *   @0xbba54 ldrshteq lr, [r11], -r12
 *   @0xbba58 eoreq r4, r7, r0, asr #31
 *   @0xbba5c .word 0xffffbbe0
 *   @0xbba60 ldrsbteq lr, [r11], -r0
 *   @0xbba64 eoreq r4, r7, r8, asr #31
 *   @0xbba68 .word 0xffffbbe4
 *   @0xbba6c eorseq lr, r11, r4, lsr #13
 *   @0xbba70 .word 0x00274fd8
 *   @0xbba74 .word 0xffffbbe8
 *   @0xbba78 eorseq lr, r11, r8, ror r6
 *   @0xbba7c eoreq r4, r7, r8, ror #31
 *   @0xbba80 .word 0xffffbbec
 *   @0xbba84 eorseq lr, r11, r12, asr #12
 *   @0xbba88 .word 0x00274ff8
 *   @0xbba8c .word 0xffffbbf0
 *   @0xbba90 eorseq lr, r11, r0, lsr #12
 *   @0xbba94 eoreq r5, r7, r0
 *   @0xbba98 .word 0xffffbbf4
 *   @0xbba9c ldrshteq lr, [r11], -r4
 *   @0xbbaa0 eoreq r5, r7, r0, lsr #32
 *   @0xbbaa4 .word 0xffffbbf8
 *   @0xbbaa8 eorseq lr, r11, r8, asr #11
 *   @0xbbaac eoreq r5, r7, r0, lsr r0
 *   @0xbbab0 .word 0xffffbbfc
 *   @0xbbab4 mlaseq r11, r12, r5, lr
 *   @0xbbab8 eoreq r5, r7, r0, lsr r0
 *   @0xbbabc .word 0xffffbc00
 *   @0xbbac0 eorseq lr, r11, r0, ror r5
 *   @0xbbac4 eoreq r5, r7, r0, asr #32
 *   @0xbbac8 .word 0xffffbc04
 *   @0xbbacc eorseq lr, r11, r4, asr #10
 *   @0xbbad0 eoreq r5, r7, r0, asr r0
 *   @0xbbad4 .word 0xffffbc08
 *   @0xbbad8 eorseq lr, r11, r8, lsl r5
 *   @0xbbadc eoreq r5, r7, r8, rrx
 *   @0xbbae0 .word 0xffffbc0c
 *   @0xbbae4 eorseq lr, r11, r12, ror #9
 *   @0xbbae8 eoreq r5, r7, r0, lsl #1
 *   @0xbbaec .word 0xffffbc10
 *   @0xbbaf0 eorseq lr, r11, r0, asr #9
 *   @0xbbaf4 eoreq r5, r7, r0, lsr #1
 *   @0xbbaf8 .word 0xffffbc14
 *   @0xbbafc mlaseq r11, r4, r4, lr
 *   @0xbbb00 strhteq r5, [r7], -r0
 *   @0xbbb04 .word 0xffffbc18
 *   @0xbbb08 eoreq r5, r7, r0, ror #1
 *   @0xbbb0c eoreq r3, r7, r12, ror #9
 *   @0xbbb10 eorseq lr, r11, r0, lsr r4
 *   @0xbbb14 eoreq r3, r7, r4, ror #9
 *   @0xbbb18 .word 0x002734d4
 *   @0xbbb1c .word 0x002734d8
 *   @0xbbb20 ldrsbteq lr, [r11], -r4
 *   @0xbbb24 .word 0x002734d0
 *   @0xbbb28 eoreq r3, r7, r4, asr #9
 *   @0xbbb2c eorseq sp, r11, r12, lsr r12
 *   @0xbbb30 eoreq r3, r7, r8, lsl #10
 *   @0xbbb34 .word 0xffffbc1c
 *   @0xbbb38 eorseq sp, r11, r4, lsl r12
 *   @0xbbb3c eoreq r3, r7, r12, lsl #10
 *   @0xbbb40 .word 0xffffbc20
 *   @0xbbb44 eorseq sp, r11, r8, ror #23
 *   @0xbbb48 eoreq r3, r7, r4, lsl r5
 *   @0xbbb4c .word 0xffffbc24
 *   @0xbbb50 ldrhteq sp, [r11], -r12
 *   @0xbbb54 eoreq r3, r7, r4, lsl r5
 *   @0xbbb58 .word 0xffffbc28
 *   @0xbbb5c mlaseq r11, r0, r11, sp
 *   @0xbbb60 eoreq r3, r7, r12, lsl r5
 *   @0xbbb64 .word 0xffffbc2c
 *   @0xbbb68 eorseq sp, r11, r4, ror #22
 *   @0xbbb6c eoreq r3, r7, r4, lsr r5
 *   @0xbbb70 .word 0xffffbc30
 *   @0xbbb74 eorseq sp, r11, r8, lsr r11
 *   @0xbbb78 eoreq r3, r7, r4, asr #10
 *   @0xbbb7c .word 0xffffbc34
 *   @0xbbb80 eorseq sp, r11, r12, lsl #22
 *   @0xbbb84 eoreq r3, r7, r4, asr #10
 *   @0xbbb88 .word 0xffffbc38
 *   @0xbbb8c eorseq sp, r11, r0, ror #21
 *   @0xbbb90 eoreq r3, r7, r4, asr #10
 *   @0xbbb94 .word 0xffffbc3c
 *   @0xbbb98 ldrhteq sp, [r11], -r4
 *   @0xbbb9c eoreq r3, r7, r12, asr #10
 *   @0xbbba0 .word 0xffffbc40
 *   @0xbbba4 eorseq sp, r11, r8, lsl #21
 *   @0xbbba8 eoreq r3, r7, r12, asr #10
 *   @0xbbbac .word 0xffffbc44
 *   @0xbbbb0 eorseq sp, r11, r12, asr r10
 *   @0xbbbb4 eoreq r3, r7, r4, asr r5
 *   @0xbbbb8 .word 0xffffbc48
 *   @0xbbbbc eorseq sp, r11, r0, lsr r10
 *   @0xbbbc0 eoreq r3, r7, r12, asr r5
 *   @0xbbbc4 .word 0xffffbc4c
 *   @0xbbbc8 eorseq sp, r11, r4, lsl #20
 *   @0xbbbcc eoreq r3, r7, r4, ror #10
 *   @0xbbbd0 .word 0xffffbc50
 *   @0xbbbd4 ldrsbteq sp, [r11], -r8
 *   @0xbbbd8 eoreq r3, r7, r12, ror #10
 *   @0xbbbdc .word 0xffffbc54
 *   @0xbbbe0 eorseq sp, r11, r12, lsr #19
 *   @0xbbbe4 eoreq r3, r7, r12, ror #10
 *   @0xbbbe8 .word 0xffffbc58
 *   @0xbbbec eorseq sp, r11, r0, lsl #19
 *   @0xbbbf0 eoreq r3, r7, r4, ror r5
 *   @0xbbbf4 .word 0xffffbc5c
 *   @0xbbbf8 eorseq sp, r11, r4, asr r9
 *   @0xbbbfc eoreq r3, r7, r4, ror r5
 *   @0xbbc00 .word 0xffffbc60
 *   @0xbbc04 eorseq sp, r11, r8, lsr #18
 *   @0xbbc08 eoreq r3, r7, r4, ror r5
 *   @0xbbc0c .word 0xffffbc64
 *   @0xbbc10 ldrshteq sp, [r11], -r12
 *   @0xbbc14 eoreq r3, r7, r12, ror r5
 *   @0xbbc18 .word 0xffffbc68
 *   @0xbbc1c ldrsbteq sp, [r11], -r0
 *   @0xbbc20 eoreq r3, r7, r4, lsl #11
 *   @0xbbc24 .word 0xffffbc6c
 *   @0xbbc28 eorseq sp, r11, r4, lsr #17
 *   @0xbbc2c eoreq r3, r7, r12, lsl #11
 *   @0xbbc30 .word 0xffffbc70
 *   @0xbbc34 eorseq sp, r11, r8, ror r8
 *   @0xbbc38 mlaeq r7, r4, r5, r3
 *   @0xbbc3c .word 0xffffbc74
 *   @0xbbc40 eorseq sp, r11, r12, asr #16
 *   @0xbbc44 eoreq r3, r7, r12, lsr #11
 *   @0xbbc48 .word 0xffffbc78
 *   @0xbbc4c eorseq sp, r11, r0, lsr #16
 *   @0xbbc50 eoreq r3, r7, r4, asr #11
 *   @0xbbc54 .word 0xffffbc7c
 *   @0xbbc58 ldrshteq sp, [r11], -r4
 *   @0xbbc5c eoreq r3, r7, r4, ror #11
 *   @0xbbc60 .word 0xffffbc80
 *   @0xbbc64 eorseq sp, r11, r8, asr #15
 *   @0xbbc68 .word 0x002735fc
 *   @0xbbc6c .word 0xffffbc84
 *   @0xbbc70 mlaseq r11, r12, r7, sp
 *   @0xbbc74 eoreq r3, r7, r12, lsl r6
 *   @0xbbc78 .word 0xffffbc88
 *   @0xbbc7c eorseq sp, r11, r0, ror r7
 *   @0xbbc80 eoreq r3, r7, r4, lsr #12
 *   @0xbbc84 .word 0xffffbc8c
 *   @0xbbc88 eorseq sp, r11, r4, asr #14
 *   @0xbbc8c eoreq r3, r7, r12, lsr #12
 *   @0xbbc90 .word 0xffffbc90
 *   @0xbbc94 eorseq sp, r11, r8, lsl r7
 *   @0xbbc98 eoreq r3, r7, r12, lsr #12
 *   @0xbbc9c .word 0xffffbc94
 *   @0xbbca0 eorseq sp, r11, r12, ror #13
 *   @0xbbca4 eoreq r3, r7, r12, lsr #12
 *   @0xbbca8 .word 0xffffbc98
 *   @0xbbcac eorseq sp, r11, r0, asr #13
 *   @0xbbcb0 eoreq r3, r7, r4, lsr #12
 *   @0xbbcb4 .word 0xffffbc9c
 *   @0xbbcb8 mlaseq r11, r4, r6, sp
 *   @0xbbcbc eoreq r3, r7, r12, lsl r6
 *   @0xbbcc0 .word 0xffffbca0
 *   @0xbbcc4 eorseq sp, r11, r8, ror #12
 *   @0xbbcc8 eoreq r3, r7, r12, lsl r6
 *   @0xbbccc .word 0xffffbca4
 *   @0xbbcd0 eorseq sp, r11, r12, lsr r6
 *   @0xbbcd4 eoreq r3, r7, r12, lsl r6
 *   @0xbbcd8 .word 0xffffbca8
 *   @0xbbcdc eorseq sp, r11, r0, lsl r6
 *   @0xbbce0 eoreq r3, r7, r12, lsr #12
 *   @0xbbce4 .word 0xffffbcac
 *   @0xbbce8 eorseq sp, r11, r4, ror #11
 *   @0xbbcec eoreq r3, r7, r4, lsr r6
 *   @0xbbcf0 .word 0xffffbcb0
 *   @0xbbcf4 ldrhteq sp, [r11], -r8
 *   @0xbbcf8 eoreq r3, r7, r12, asr #12
 *   @0xbbcfc .word 0xffffbcb4
 *   @0xbbd00 eorseq sp, r11, r12, lsl #11
 *   @0xbbd04 eoreq r3, r7, r4, ror #12
 *   @0xbbd08 .word 0xffffbcb8
 *   @0xbbd0c eorseq sp, r11, r0, ror #10
 *   @0xbbd10 eoreq r3, r7, r4, lsl #13
 *   @0xbbd14 .word 0xffffbcbc
 *   @0xbbd18 eorseq sp, r11, r4, lsr r5
 *   @0xbbd1c eoreq r3, r7, r4, lsr #13
 *   @0xbbd20 .word 0xffffbcc0
 *   @0xbbd24 eorseq sp, r11, r8, lsl #10
 *   @0xbbd28 eoreq r3, r7, r12, asr #13
 *   @0xbbd2c .word 0xffffbcc4
 *   @0xbbd30 eoreq r3, r7, r0, asr #14
 *   @0xbbd34 eoreq r2, r7, r4, ror r8
 *   @0xbbd38 eoreq r2, r7, r8, lsl #17
 *   @0xbbd3c mlaeq r7, r12, r8, r2
 *   @0xbbd40 eoreq r2, r7, r12, lsr #17
 *   @0xbbd44 .word 0x002728b8
 *   @0xbbd48 eoreq r2, r7, r0, asr #17
 *   @0xbbd4c eoreq r2, r7, r8, asr #17
 *   @0xbbd50 .word 0x002728d8
 *   @0xbbd54 eoreq r2, r7, r12, ror #17
 *   @0xbbd58 eoreq r2, r7, r4, lsl #18
 *   @0xbbd5c eoreq r2, r7, r12, lsl r9
 *   @0xbbd60 eoreq r2, r7, r0, lsr r9
 *   @0xbbd64 eoreq r2, r7, r4, asr #18
 *   @0xbbd68 eoreq r2, r7, r8, asr r9
 *   @0xbbd6c eoreq r2, r7, r12, ror #18
 *   @0xbbd70 eoreq r2, r7, r0, lsl #19
 *   @0xbbd74 eoreq r2, r7, r0, lsl #10
 *   @0xbbd78 eoreq r2, r7, r12, lsl #10
 *   @0xbbd7c eoreq r2, r7, r12, lsl r5
 *   @0xbbd80 eoreq r2, r7, r12, lsr #10
 *   @0xbbd84 eoreq r2, r7, r8, lsr r5
 *   @0xbbd88 eoreq r2, r7, r8, asr #10
 *   @0xbbd8c eoreq r2, r7, r12, asr r5
 *   @0xbbd90 eoreq r2, r7, r8, ror #10
 *   @0xbbd94 eoreq r2, r7, r8, asr #6
 *   @0xbbd98 eoreq r2, r7, r8, asr r3
 *   @0xbbd9c eoreq r2, r7, r8, ror #6
 *   @0xbbda0 eoreq r2, r7, r4, ror r3
 *   @0xbbda4 mlaeq r7, r8, r9, r2
 *   @0xbbda8 .word 0x002729b0
 *   @0xbbdac eoreq r2, r7, r8, lsr r2
 *   @0xbbdb0 eoreq r2, r7, r0, asr #4
 *   @0xbbdb4 mlaeq r7, r4, r7, r2
 *   @0xbbdb8 eoreq r2, r7, r8, lsr #15
 *   @0xbbdbc .word 0x002727bc
 *   @0xbbdc0 eoreq r2, r7, r12, asr #15
 *   @0xbbdc4 .word 0x002727d8
 *   @0xbbdc8 eoreq r2, r7, r8, ror #15
 *   @0xbbdcc .word 0x002727fc
 *   @0xbbdd0 eoreq r2, r7, r12, lsl #16
 *   @0xbbdd4 .word 0x002734b4
 *   @0xbbdd8 eoreq r3, r7, r0, ror #8
 *   @0xbbddc eoreq r3, r7, r4, lsl #8
 *   @0xbbde0 mlaeq r7, r12, r3, r3
 *   @0xbbde4 eoreq r3, r7, r0, lsr r3
 *   @0xbbde8 .word 0x002732d4
 *   @0xbbdec eoreq r3, r7, r4, lsl #5
 *   @0xbbdf0 eoreq r3, r7, r0, lsr r2
 *   @0xbbdf4 .word 0x002731dc
 *   @0xbbdf8 eoreq r3, r7, r4, lsl #3
 *   @0xbbdfc eoreq r3, r7, r4, lsr #2
 *   @0xbbe00 eoreq r3, r7, r0, lsl #1
 *   @0xbbe04 eoreq r3, r7, r0, lsr #32
 *   @0xbbe08 eoreq r2, r7, r0, lsr #31
 *   @0xbbe0c eoreq r2, r7, r0, lsr pc
 *   @0xbbe10 eoreq r2, r7, r4, asr #29
 *   @0xbbe14 eoreq r2, r7, r12, asr lr
 *   @0xbbe18 .word 0x00272df8
 *   @0xbbe1c mlaeq r7, r12, sp, r2
 *   @0xbbe20 eoreq r2, r7, r4, asr #26
 *   @0xbbe24 .word 0x00272cf0
 *   @0xbbe28 eoreq r2, r7, r4, lsr #25
 *   @0xbbe2c eoreq r2, r7, r12, asr r12
 *   @0xbbe30 eoreq r3, r7, r4, lsl r9
 *   @0xbbe34 eoreq r3, r7, r4, lsr #17
 *   @0xbbe38 eoreq r3, r7, r0, asr #16
 *   @0xbbe3c .word 0x002737d8
 *   @0xbbe40 eoreq r3, r7, r4, ror r7
 *   @0xbbe44 ldr r3, [pc, #-0x320]
 *   @0xbbe48 ldr r1, [pc, #-0x320]
 *   @0xbbe4c add r3, pc, r3
 *   @0xbbe50 add r1, pc, r1
 *   @0xbbe54 ldr r0, [r3]
 *   @0xbbe58 bl 0xb6514 <dlsym@plt>
 *   @0xbbe5c subs r8, r0, #0
 *   @0xbbe60 beq 0xbd58c <_Z12GLFuncImportb+0x2e7c>
 *   @0xbbe64 ldr r3, [pc, #-0x338]
 *   @0xbbe68 ldr r2, [pc, #-0x338]
 *   @0xbbe6c ldr r1, [pc, #-0x338]
 *   @0xbbe70 ldr r3, [r4, r3]
 *   @0xbbe74 add r2, pc, r2
 *   @0xbbe78 add r1, pc, r1
 *   @0xbbe7c ldr r0, [r2]
 *   @0xbbe80 str r8, [r3]
 *   @0xbbe84 bl 0xb6514 <dlsym@plt>
 *   @0xbbe88 subs r8, r0, #0
 *   @0xbbe8c beq 0xbd56c <_Z12GLFuncImportb+0x2e5c>
 *   @0xbbe90 ldr r3, [pc, #-0x358]
 *   @0xbbe94 ldr r2, [pc, #-0x358]
 *   @0xbbe98 ldr r1, [pc, #-0x358]
 *   @0xbbe9c ldr r3, [r4, r3]
 *   @0xbbea0 add r2, pc, r2
 *   @0xbbea4 add r1, pc, r1
 *   @0xbbea8 ldr r0, [r2]
 *   @0xbbeac str r8, [r3]
 *   @0xbbeb0 bl 0xb6514 <dlsym@plt>
 *   @0xbbeb4 subs r8, r0, #0
 *   @0xbbeb8 beq 0xbd54c <_Z12GLFuncImportb+0x2e3c>
 *   @0xbbebc ldr r3, [pc, #-0x378]
 *   @0xbbec0 ldr r2, [pc, #-0x378]
 *   @0xbbec4 ldr r1, [pc, #-0x378]
 *   @0xbbec8 ldr r3, [r4, r3]
 *   @0xbbecc add r2, pc, r2
 *   @0xbbed0 add r1, pc, r1
 *   @0xbbed4 ldr r0, [r2]
 *   @0xbbed8 str r8, [r3]
 *   @0xbbedc bl 0xb6514 <dlsym@plt>
 *   @0xbbee0 subs r8, r0, #0
 *   @0xbbee4 beq 0xbd52c <_Z12GLFuncImportb+0x2e1c>
 *   @0xbbee8 ldr r3, [pc, #-0x398]
 *   @0xbbeec ldr r2, [pc, #-0x398]
 *   @0xbbef0 ldr r1, [pc, #-0x398]
 *   @0xbbef4 ldr r3, [r4, r3]
 *   @0xbbef8 add r2, pc, r2
 *   @0xbbefc add r1, pc, r1
 *   @0xbbf00 ldr r0, [r2]
 *   @0xbbf04 str r8, [r3]
 *   @0xbbf08 bl 0xb6514 <dlsym@plt>
 *   @0xbbf0c subs r8, r0, #0
 *   @0xbbf10 beq 0xbd50c <_Z12GLFuncImportb+0x2dfc>
 *   @0xbbf14 ldr r3, [pc, #-0x3b8]
 *   @0xbbf18 ldr r2, [pc, #-0x3b8]
 *   @0xbbf1c ldr r1, [pc, #-0x3b8]
 *   @0xbbf20 ldr r3, [r4, r3]
 *   @0xbbf24 add r2, pc, r2
 *   @0xbbf28 add r1, pc, r1
 *   @0xbbf2c ldr r0, [r2]
 *   @0xbbf30 str r8, [r3]
 *   @0xbbf34 bl 0xb6514 <dlsym@plt>
 *   @0xbbf38 subs r8, r0, #0
 *   @0xbbf3c beq 0xbd4ec <_Z12GLFuncImportb+0x2ddc>
 *   @0xbbf40 ldr r3, [pc, #-0x3d8]
 *   @0xbbf44 ldr r2, [pc, #-0x3d8]
 *   @0xbbf48 ldr r1, [pc, #-0x3d8]
 *   @0xbbf4c ldr r3, [r4, r3]
 *   @0xbbf50 add r2, pc, r2
 *   @0xbbf54 add r1, pc, r1
 *   @0xbbf58 ldr r0, [r2]
 *   @0xbbf5c str r8, [r3]
 *   @0xbbf60 bl 0xb6514 <dlsym@plt>
 *   @0xbbf64 subs r8, r0, #0
 *   @0xbbf68 beq 0xbd4cc <_Z12GLFuncImportb+0x2dbc>
 *   @0xbbf6c ldr r3, [pc, #-0x3f8]
 *   @0xbbf70 ldr r2, [pc, #-0x3f8]
 *   @0xbbf74 ldr r1, [pc, #-0x3f8]
 *   @0xbbf78 ldr r3, [r4, r3]
 *   @0xbbf7c add r2, pc, r2
 *   @0xbbf80 add r1, pc, r1
 *   @0xbbf84 ldr r0, [r2]
 *   @0xbbf88 str r8, [r3]
 *   @0xbbf8c bl 0xb6514 <dlsym@plt>
 *   @0xbbf90 subs r8, r0, #0
 *   @0xbbf94 beq 0xbd4ac <_Z12GLFuncImportb+0x2d9c>
 *   @0xbbf98 ldr r3, [pc, #-0x418]
 *   @0xbbf9c ldr r2, [pc, #-0x418]
 *   @0xbbfa0 ldr r1, [pc, #-0x418]
 *   @0xbbfa4 ldr r3, [r4, r3]
 *   @0xbbfa8 add r2, pc, r2
 *   @0xbbfac add r1, pc, r1
 *   @0xbbfb0 ldr r0, [r2]
 *   @0xbbfb4 str r8, [r3]
 *   @0xbbfb8 bl 0xb6514 <dlsym@plt>
 *   @0xbbfbc subs r8, r0, #0
 *   @0xbbfc0 beq 0xbd48c <_Z12GLFuncImportb+0x2d7c>
 *   @0xbbfc4 ldr r3, [pc, #-0x438]
 *   @0xbbfc8 ldr r2, [pc, #-0x438]
 *   @0xbbfcc ldr r1, [pc, #-0x438]
 *   @0xbbfd0 ldr r3, [r4, r3]
 *   @0xbbfd4 add r2, pc, r2
 *   @0xbbfd8 add r1, pc, r1
 *   @0xbbfdc ldr r0, [r2]
 *   @0xbbfe0 str r8, [r3]
 *   @0xbbfe4 bl 0xb6514 <dlsym@plt>
 *   @0xbbfe8 subs r8, r0, #0
 *   @0xbbfec beq 0xbd46c <_Z12GLFuncImportb+0x2d5c>
 *   @0xbbff0 ldr r3, [pc, #-0x458]
 *   @0xbbff4 ldr r2, [pc, #-0x458]
 *   @0xbbff8 ldr r1, [pc, #-0x458]
 *   @0xbbffc ldr r3, [r4, r3]
 *   @0xbc000 add r2, pc, r2
 *   @0xbc004 add r1, pc, r1
 *   @0xbc008 ldr r0, [r2]
 *   @0xbc00c str r8, [r3]
 *   @0xbc010 bl 0xb6514 <dlsym@plt>
 *   @0xbc014 subs r8, r0, #0
 *   @0xbc018 beq 0xbd44c <_Z12GLFuncImportb+0x2d3c>
 *   @0xbc01c ldr r3, [pc, #-0x478]
 *   @0xbc020 ldr r2, [pc, #-0x478]
 *   @0xbc024 ldr r1, [pc, #-0x478]
 *   @0xbc028 ldr r3, [r4, r3]
 *   @0xbc02c add r2, pc, r2
 *   @0xbc030 add r1, pc, r1
 *   @0xbc034 ldr r0, [r2]
 *   @0xbc038 str r8, [r3]
 *   @0xbc03c bl 0xb6514 <dlsym@plt>
 *   @0xbc040 subs r8, r0, #0
 *   @0xbc044 beq 0xbd42c <_Z12GLFuncImportb+0x2d1c>
 *   @0xbc048 ldr r3, [pc, #-0x498]
 *   @0xbc04c ldr r2, [pc, #-0x498]
 *   @0xbc050 ldr r1, [pc, #-0x498]
 *   @0xbc054 ldr r3, [r4, r3]
 *   @0xbc058 add r2, pc, r2
 *   @0xbc05c add r1, pc, r1
 *   @0xbc060 ldr r0, [r2]
 *   @0xbc064 str r8, [r3]
 *   @0xbc068 bl 0xb6514 <dlsym@plt>
 *   @0xbc06c subs r8, r0, #0
 *   @0xbc070 beq 0xbd40c <_Z12GLFuncImportb+0x2cfc>
 *   @0xbc074 ldr r3, [pc, #-0x4b8]
 *   @0xbc078 ldr r2, [pc, #-0x4b8]
 *   @0xbc07c ldr r1, [pc, #-0x4b8]
 *   @0xbc080 ldr r3, [r4, r3]
 *   @0xbc084 add r2, pc, r2
 *   @0xbc088 add r1, pc, r1
 *   @0xbc08c ldr r0, [r2]
 *   @0xbc090 str r8, [r3]
 *   @0xbc094 bl 0xb6514 <dlsym@plt>
 *   @0xbc098 subs r8, r0, #0
 *   @0xbc09c beq 0xbd3ec <_Z12GLFuncImportb+0x2cdc>
 *   @0xbc0a0 ldr r3, [pc, #-0x4d8]
 *   @0xbc0a4 ldr r2, [pc, #-0x4d8]
 *   @0xbc0a8 ldr r1, [pc, #-0x4d8]
 *   @0xbc0ac ldr r3, [r4, r3]
 *   @0xbc0b0 add r2, pc, r2
 *   @0xbc0b4 add r1, pc, r1
 *   @0xbc0b8 ldr r0, [r2]
 *   @0xbc0bc str r8, [r3]
 *   @0xbc0c0 bl 0xb6514 <dlsym@plt>
 *   @0xbc0c4 subs r8, r0, #0
 *   @0xbc0c8 beq 0xbd3cc <_Z12GLFuncImportb+0x2cbc>
 *   @0xbc0cc ldr r3, [pc, #-0x4f8]
 *   @0xbc0d0 ldr r2, [pc, #-0x4f8]
 *   @0xbc0d4 ldr r1, [pc, #-0x4f8]
 *   @0xbc0d8 ldr r3, [r4, r3]
 *   @0xbc0dc add r2, pc, r2
 *   @0xbc0e0 add r1, pc, r1
 *   @0xbc0e4 ldr r0, [r2]
 *   @0xbc0e8 str r8, [r3]
 *   @0xbc0ec bl 0xb6514 <dlsym@plt>
 *   @0xbc0f0 subs r8, r0, #0
 *   @0xbc0f4 beq 0xbd3ac <_Z12GLFuncImportb+0x2c9c>
 *   @0xbc0f8 ldr r3, [pc, #-0x518]
 *   @0xbc0fc ldr r2, [pc, #-0x518]
 *   @0xbc100 ldr r1, [pc, #-0x518]
 *   @0xbc104 ldr r3, [r4, r3]
 *   @0xbc108 add r2, pc, r2
 *   @0xbc10c add r1, pc, r1
 *   @0xbc110 ldr r0, [r2]
 *   @0xbc114 str r8, [r3]
 *   @0xbc118 bl 0xb6514 <dlsym@plt>
 *   @0xbc11c subs r8, r0, #0
 *   @0xbc120 beq 0xbd38c <_Z12GLFuncImportb+0x2c7c>
 *   @0xbc124 ldr r3, [pc, #-0x538]
 *   @0xbc128 ldr r2, [pc, #-0x538]
 *   @0xbc12c ldr r1, [pc, #-0x538]
 *   @0xbc130 ldr r3, [r4, r3]
 *   @0xbc134 add r2, pc, r2
 *   @0xbc138 add r1, pc, r1
 *   @0xbc13c ldr r0, [r2]
 *   @0xbc140 str r8, [r3]
 *   @0xbc144 bl 0xb6514 <dlsym@plt>
 *   @0xbc148 subs r8, r0, #0
 *   @0xbc14c beq 0xbd36c <_Z12GLFuncImportb+0x2c5c>
 *   @0xbc150 ldr r3, [pc, #-0x558]
 *   @0xbc154 ldr r2, [pc, #-0x558]
 *   @0xbc158 ldr r1, [pc, #-0x558]
 *   @0xbc15c ldr r3, [r4, r3]
 *   @0xbc160 add r2, pc, r2
 *   @0xbc164 add r1, pc, r1
 *   @0xbc168 ldr r0, [r2]
 *   @0xbc16c str r8, [r3]
 *   @0xbc170 bl 0xb6514 <dlsym@plt>
 *   @0xbc174 subs r8, r0, #0
 *   @0xbc178 beq 0xbd34c <_Z12GLFuncImportb+0x2c3c>
 *   @0xbc17c ldr r3, [pc, #-0x578]
 *   @0xbc180 ldr r2, [pc, #-0x578]
 *   @0xbc184 ldr r1, [pc, #-0x578]
 *   @0xbc188 ldr r3, [r4, r3]
 *   @0xbc18c add r2, pc, r2
 *   @0xbc190 add r1, pc, r1
 *   @0xbc194 ldr r0, [r2]
 *   @0xbc198 str r8, [r3]
 *   @0xbc19c bl 0xb6514 <dlsym@plt>
 *   @0xbc1a0 subs r8, r0, #0
 *   @0xbc1a4 beq 0xbd32c <_Z12GLFuncImportb+0x2c1c>
 *   @0xbc1a8 ldr r3, [pc, #-0x598]
 *   @0xbc1ac ldr r2, [pc, #-0x598]
 *   @0xbc1b0 ldr r1, [pc, #-0x598]
 *   @0xbc1b4 ldr r3, [r4, r3]
 *   @0xbc1b8 add r2, pc, r2
 *   @0xbc1bc add r1, pc, r1
 *   @0xbc1c0 ldr r0, [r2]
 *   @0xbc1c4 str r8, [r3]
 *   @0xbc1c8 bl 0xb6514 <dlsym@plt>
 *   @0xbc1cc subs r8, r0, #0
 *   @0xbc1d0 beq 0xbd30c <_Z12GLFuncImportb+0x2bfc>
 *   @0xbc1d4 ldr r3, [pc, #-0x5b8]
 *   @0xbc1d8 ldr r2, [pc, #-0x5b8]
 *   @0xbc1dc ldr r1, [pc, #-0x5b8]
 *   @0xbc1e0 ldr r3, [r4, r3]
 *   @0xbc1e4 add r2, pc, r2
 *   @0xbc1e8 add r1, pc, r1
 *   @0xbc1ec ldr r0, [r2]
 *   @0xbc1f0 str r8, [r3]
 *   @0xbc1f4 bl 0xb6514 <dlsym@plt>
 *   @0xbc1f8 subs r8, r0, #0
 *   @0xbc1fc beq 0xbd2ec <_Z12GLFuncImportb+0x2bdc>
 *   @0xbc200 ldr r3, [pc, #-0x5d8]
 *   @0xbc204 ldr r2, [pc, #-0x5d8]
 *   @0xbc208 ldr r1, [pc, #-0x5d8]
 *   @0xbc20c ldr r3, [r4, r3]
 *   @0xbc210 add r2, pc, r2
 *   @0xbc214 add r1, pc, r1
 *   @0xbc218 ldr r0, [r2]
 *   @0xbc21c str r8, [r3]
 *   @0xbc220 bl 0xb6514 <dlsym@plt>
 *   @0xbc224 subs r8, r0, #0
 *   @0xbc228 beq 0xbd2cc <_Z12GLFuncImportb+0x2bbc>
 *   @0xbc22c ldr r3, [pc, #-0x5f8]
 *   @0xbc230 ldr r2, [pc, #-0x5f8]
 *   @0xbc234 ldr r1, [pc, #-0x5f8]
 *   @0xbc238 ldr r3, [r4, r3]
 *   @0xbc23c add r2, pc, r2
 *   @0xbc240 add r1, pc, r1
 *   @0xbc244 ldr r0, [r2]
 *   @0xbc248 str r8, [r3]
 *   @0xbc24c bl 0xb6514 <dlsym@plt>
 *   @0xbc250 subs r8, r0, #0
 *   @0xbc254 beq 0xbd2ac <_Z12GLFuncImportb+0x2b9c>
 *   @0xbc258 ldr r3, [pc, #-0x618]
 *   @0xbc25c ldr r2, [pc, #-0x618]
 *   @0xbc260 ldr r1, [pc, #-0x618]
 *   @0xbc264 ldr r3, [r4, r3]
 *   @0xbc268 add r2, pc, r2
 *   @0xbc26c add r1, pc, r1
 *   @0xbc270 ldr r0, [r2]
 *   @0xbc274 str r8, [r3]
 *   @0xbc278 bl 0xb6514 <dlsym@plt>
 *   @0xbc27c subs r8, r0, #0
 *   @0xbc280 beq 0xbd28c <_Z12GLFuncImportb+0x2b7c>
 *   @0xbc284 ldr r3, [pc, #-0x638]
 *   @0xbc288 ldr r2, [pc, #-0x638]
 *   @0xbc28c ldr r1, [pc, #-0x638]
 *   @0xbc290 ldr r3, [r4, r3]
 *   @0xbc294 add r2, pc, r2
 *   @0xbc298 add r1, pc, r1
 *   @0xbc29c ldr r0, [r2]
 *   @0xbc2a0 str r8, [r3]
 *   @0xbc2a4 bl 0xb6514 <dlsym@plt>
 *   @0xbc2a8 subs r8, r0, #0
 *   @0xbc2ac beq 0xbd26c <_Z12GLFuncImportb+0x2b5c>
 *   @0xbc2b0 ldr r3, [pc, #-0x658]
 *   @0xbc2b4 ldr r2, [pc, #-0x658]
 *   @0xbc2b8 ldr r1, [pc, #-0x658]
 *   @0xbc2bc ldr r3, [r4, r3]
 *   @0xbc2c0 add r2, pc, r2
 *   @0xbc2c4 add r1, pc, r1
 *   @0xbc2c8 ldr r0, [r2]
 *   @0xbc2cc str r8, [r3]
 *   @0xbc2d0 bl 0xb6514 <dlsym@plt>
 *   @0xbc2d4 subs r8, r0, #0
 *   @0xbc2d8 beq 0xbd24c <_Z12GLFuncImportb+0x2b3c>
 *   @0xbc2dc ldr r3, [pc, #-0x678]
 *   @0xbc2e0 ldr r2, [pc, #-0x678]
 *   @0xbc2e4 ldr r1, [pc, #-0x678]
 *   @0xbc2e8 ldr r3, [r4, r3]
 *   @0xbc2ec add r2, pc, r2
 *   @0xbc2f0 add r1, pc, r1
 *   @0xbc2f4 ldr r0, [r2]
 *   @0xbc2f8 str r8, [r3]
 *   @0xbc2fc bl 0xb6514 <dlsym@plt>
 *   @0xbc300 subs r8, r0, #0
 *   @0xbc304 beq 0xbd22c <_Z12GLFuncImportb+0x2b1c>
 *   @0xbc308 ldr r3, [pc, #-0x698]
 *   @0xbc30c ldr r2, [pc, #-0x698]
 *   @0xbc310 ldr r1, [pc, #-0x698]
 *   @0xbc314 ldr r3, [r4, r3]
 *   @0xbc318 add r2, pc, r2
 *   @0xbc31c add r1, pc, r1
 *   @0xbc320 ldr r0, [r2]
 *   @0xbc324 str r8, [r3]
 *   @0xbc328 bl 0xb6514 <dlsym@plt>
 *   @0xbc32c subs r8, r0, #0
 *   @0xbc330 beq 0xbd20c <_Z12GLFuncImportb+0x2afc>
 *   @0xbc334 ldr r3, [pc, #-0x6b8]
 *   @0xbc338 ldr r2, [pc, #-0x6b8]
 *   @0xbc33c ldr r1, [pc, #-0x6b8]
 *   @0xbc340 ldr r3, [r4, r3]
 *   @0xbc344 add r2, pc, r2
 *   @0xbc348 add r1, pc, r1
 *   @0xbc34c ldr r0, [r2]
 *   @0xbc350 str r8, [r3]
 *   @0xbc354 bl 0xb6514 <dlsym@plt>
 *   @0xbc358 subs r8, r0, #0
 *   @0xbc35c beq 0xbd1ec <_Z12GLFuncImportb+0x2adc>
 *   @0xbc360 ldr r3, [pc, #-0x6d8]
 *   @0xbc364 ldr r2, [pc, #-0x6d8]
 *   @0xbc368 ldr r1, [pc, #-0x6d8]
 *   @0xbc36c ldr r3, [r4, r3]
 *   @0xbc370 add r2, pc, r2
 *   @0xbc374 add r1, pc, r1
 *   @0xbc378 ldr r0, [r2]
 *   @0xbc37c str r8, [r3]
 *   @0xbc380 bl 0xb6514 <dlsym@plt>
 *   @0xbc384 subs r8, r0, #0
 *   @0xbc388 beq 0xbd1cc <_Z12GLFuncImportb+0x2abc>
 *   @0xbc38c ldr r3, [pc, #-0x6f8]
 *   @0xbc390 ldr r2, [pc, #-0x6f8]
 *   @0xbc394 ldr r1, [pc, #-0x6f8]
 *   @0xbc398 ldr r3, [r4, r3]
 *   @0xbc39c add r2, pc, r2
 *   @0xbc3a0 add r1, pc, r1
 *   @0xbc3a4 ldr r0, [r2]
 *   @0xbc3a8 str r8, [r3]
 *   @0xbc3ac bl 0xb6514 <dlsym@plt>
 *   @0xbc3b0 subs r8, r0, #0
 *   @0xbc3b4 beq 0xbd1ac <_Z12GLFuncImportb+0x2a9c>
 *   @0xbc3b8 ldr r3, [pc, #-0x718]
 *   @0xbc3bc ldr r2, [pc, #-0x718]
 *   @0xbc3c0 ldr r1, [pc, #-0x718]
 *   @0xbc3c4 ldr r3, [r4, r3]
 *   @0xbc3c8 add r2, pc, r2
 *   @0xbc3cc add r1, pc, r1
 *   @0xbc3d0 ldr r0, [r2]
 *   @0xbc3d4 str r8, [r3]
 *   @0xbc3d8 bl 0xb6514 <dlsym@plt>
 *   @0xbc3dc subs r8, r0, #0
 *   @0xbc3e0 beq 0xbcd8c <_Z12GLFuncImportb+0x267c>
 *   @0xbc3e4 ldr r3, [pc, #-0x738]
 *   @0xbc3e8 ldr r2, [pc, #-0x738]
 *   @0xbc3ec ldr r1, [pc, #-0x738]
 *   @0xbc3f0 ldr r3, [r4, r3]
 *   @0xbc3f4 add r2, pc, r2
 *   @0xbc3f8 add r1, pc, r1
 *   @0xbc3fc ldr r0, [r2]
 *   @0xbc400 str r8, [r3]
 *   @0xbc404 bl 0xb6514 <dlsym@plt>
 *   @0xbc408 subs r8, r0, #0
 *   @0xbc40c beq 0xbcd6c <_Z12GLFuncImportb+0x265c>
 *   @0xbc410 ldr r3, [pc, #-0x758]
 *   @0xbc414 ldr r2, [pc, #-0x758]
 *   @0xbc418 ldr r1, [pc, #-0x758]
 *   @0xbc41c ldr r3, [r4, r3]
 *   @0xbc420 add r2, pc, r2
 *   @0xbc424 add r1, pc, r1
 *   @0xbc428 ldr r0, [r2]
 *   @0xbc42c str r8, [r3]
 *   @0xbc430 bl 0xb6514 <dlsym@plt>
 *   @0xbc434 subs r8, r0, #0
 *   @0xbc438 beq 0xbcd4c <_Z12GLFuncImportb+0x263c>
 *   @0xbc43c ldr r3, [pc, #-0x778]
 *   @0xbc440 ldr r2, [pc, #-0x778]
 *   @0xbc444 ldr r1, [pc, #-0x778]
 *   @0xbc448 ldr r3, [r4, r3]
 *   @0xbc44c add r2, pc, r2
 *   @0xbc450 add r1, pc, r1
 *   @0xbc454 ldr r0, [r2]
 *   @0xbc458 str r8, [r3]
 *   @0xbc45c bl 0xb6514 <dlsym@plt>
 *   @0xbc460 subs r8, r0, #0
 *   @0xbc464 beq 0xbcd2c <_Z12GLFuncImportb+0x261c>
 *   @0xbc468 ldr r3, [pc, #-0x798]
 *   @0xbc46c ldr r2, [pc, #-0x798]
 *   @0xbc470 ldr r1, [pc, #-0x798]
 *   @0xbc474 ldr r3, [r4, r3]
 *   @0xbc478 add r2, pc, r2
 *   @0xbc47c add r1, pc, r1
 *   @0xbc480 ldr r0, [r2]
 *   @0xbc484 str r8, [r3]
 *   @0xbc488 bl 0xb6514 <dlsym@plt>
 *   @0xbc48c subs r8, r0, #0
 *   @0xbc490 beq 0xbcd0c <_Z12GLFuncImportb+0x25fc>
 *   @0xbc494 ldr r3, [pc, #-0x7b8]
 *   @0xbc498 ldr r2, [pc, #-0x7b8]
 *   @0xbc49c ldr r1, [pc, #-0x7b8]
 *   @0xbc4a0 ldr r3, [r4, r3]
 *   @0xbc4a4 add r2, pc, r2
 *   @0xbc4a8 add r1, pc, r1
 *   @0xbc4ac ldr r0, [r2]
 *   @0xbc4b0 str r8, [r3]
 *   @0xbc4b4 bl 0xb6514 <dlsym@plt>
 *   @0xbc4b8 subs r8, r0, #0
 *   @0xbc4bc beq 0xbccec <_Z12GLFuncImportb+0x25dc>
 *   @0xbc4c0 ldr r3, [pc, #-0x7d8]
 *   @0xbc4c4 ldr r2, [pc, #-0x7d8]
 *   @0xbc4c8 ldr r1, [pc, #-0x7d8]
 *   @0xbc4cc ldr r3, [r4, r3]
 *   @0xbc4d0 add r2, pc, r2
 *   @0xbc4d4 add r1, pc, r1
 *   @0xbc4d8 ldr r0, [r2]
 *   @0xbc4dc str r8, [r3]
 *   @0xbc4e0 bl 0xb6514 <dlsym@plt>
 *   @0xbc4e4 subs r8, r0, #0
 *   @0xbc4e8 beq 0xbcccc <_Z12GLFuncImportb+0x25bc>
 *   @0xbc4ec ldr r3, [pc, #-0x7f8]
 *   @0xbc4f0 ldr r2, [pc, #-0x7f8]
 *   @0xbc4f4 ldr r1, [pc, #-0x7f8]
 *   @0xbc4f8 ldr r3, [r4, r3]
 *   @0xbc4fc add r2, pc, r2
 *   @0xbc500 add r1, pc, r1
 *   @0xbc504 ldr r0, [r2]
 *   @0xbc508 str r8, [r3]
 *   @0xbc50c bl 0xb6514 <dlsym@plt>
 *   @0xbc510 subs r8, r0, #0
 *   @0xbc514 beq 0xbccac <_Z12GLFuncImportb+0x259c>
 *   @0xbc518 ldr r3, [pc, #-0x818]
 *   @0xbc51c ldr r2, [pc, #-0x818]
 *   @0xbc520 ldr r1, [pc, #-0x818]
 *   @0xbc524 ldr r3, [r4, r3]
 *   @0xbc528 add r2, pc, r2
 *   @0xbc52c add r1, pc, r1
 *   @0xbc530 ldr r0, [r2]
 *   @0xbc534 str r8, [r3]
 *   @0xbc538 bl 0xb6514 <dlsym@plt>
 *   @0xbc53c subs r8, r0, #0
 *   @0xbc540 beq 0xbcc8c <_Z12GLFuncImportb+0x257c>
 *   @0xbc544 ldr r3, [pc, #-0x838]
 *   @0xbc548 ldr r2, [pc, #-0x838]
 *   @0xbc54c ldr r1, [pc, #-0x838]
 *   @0xbc550 ldr r3, [r4, r3]
 *   @0xbc554 add r2, pc, r2
 *   @0xbc558 add r1, pc, r1
 *   @0xbc55c ldr r0, [r2]
 *   @0xbc560 str r8, [r3]
 *   @0xbc564 bl 0xb6514 <dlsym@plt>
 *   @0xbc568 subs r8, r0, #0
 *   @0xbc56c beq 0xbcc6c <_Z12GLFuncImportb+0x255c>
 *   @0xbc570 ldr r3, [pc, #-0x858]
 *   @0xbc574 ldr r2, [pc, #-0x858]
 *   @0xbc578 ldr r1, [pc, #-0x858]
 *   @0xbc57c ldr r3, [r4, r3]
 *   @0xbc580 add r2, pc, r2
 *   @0xbc584 add r1, pc, r1
 *   @0xbc588 ldr r0, [r2]
 *   @0xbc58c str r8, [r3]
 *   @0xbc590 bl 0xb6514 <dlsym@plt>
 *   @0xbc594 subs r8, r0, #0
 *   @0xbc598 beq 0xbcc4c <_Z12GLFuncImportb+0x253c>
 *   @0xbc59c ldr r3, [pc, #-0x878]
 *   @0xbc5a0 ldr r3, [r4, r3]
 *   @0xbc5a4 str r8, [r3]
 *   @0xbc5a8 b 0xbb61c <_Z12GLFuncImportb+0xf0c>
 *   @0xbc5ac ldr r3, [r5]
 *   @0xbc5b0 mov r0, r5
 *   @0xbc5b4 ldr r1, [pc, #-0x88c]
 *   @0xbc5b8 mov r6, #3
 *   @0xbc5bc add r1, pc, r1
 *   @0xbc5c0 ldr r3, [r3, #0xc]
 *   @0xbc5c4 blx r3
 *   @0xbc5c8 b 0xbaeac <_Z12GLFuncImportb+0x79c>
 *   @0xbc5cc ldr r3, [r5]
 *   @0xbc5d0 mov r0, r5
 *   @0xbc5d4 ldr r1, [pc, #-0x8a8]
 *   @0xbc5d8 mov r6, #3
 *   @0xbc5dc add r1, pc, r1
 *   @0xbc5e0 ldr r3, [r3, #0xc]
 *   @0xbc5e4 blx r3
 *   @0xbc5e8 b 0xbaa00 <_Z12GLFuncImportb+0x2f0>
 *   @0xbc5ec ldr r3, [r5]
 *   @0xbc5f0 mov r0, r5
 *   @0xbc5f4 ldr r1, [pc, #-0x8c4]
 *   @0xbc5f8 mov r6, #3
 *   @0xbc5fc add r1, pc, r1
 *   @0xbc600 ldr r3, [r3, #0xc]
 *   @0xbc604 blx r3
 *   @0xbc608 b 0xbaa2c <_Z12GLFuncImportb+0x31c>
 *   @0xbc60c ldr r3, [r5]
 *   @0xbc610 mov r0, r5
 *   @0xbc614 ldr r1, [pc, #-0x8e0]
 *   @0xbc618 mov r6, #3
 *   @0xbc61c add r1, pc, r1
 *   @0xbc620 ldr r3, [r3, #0xc]
 *   @0xbc624 blx r3
 *   @0xbc628 b 0xbaa58 <_Z12GLFuncImportb+0x348>
 *   @0xbc62c ldr r3, [r5]
 *   @0xbc630 mov r0, r5
 *   @0xbc634 ldr r1, [pc, #-0x8fc]
 *   @0xbc638 mov r6, #3
 *   @0xbc63c add r1, pc, r1
 *   @0xbc640 ldr r3, [r3, #0xc]
 *   @0xbc644 blx r3
 *   @0xbc648 b 0xbaa84 <_Z12GLFuncImportb+0x374>
 *   @0xbc64c ldr r3, [r5]
 *   @0xbc650 mov r0, r5
 *   @0xbc654 ldr r1, [pc, #-0x918]
 *   @0xbc658 mov r6, #3
 *   @0xbc65c add r1, pc, r1
 *   @0xbc660 ldr r3, [r3, #0xc]
 *   @0xbc664 blx r3
 *   @0xbc668 b 0xbaab0 <_Z12GLFuncImportb+0x3a0>
 *   @0xbc66c ldr r3, [r5]
 *   @0xbc670 mov r0, r5
 *   @0xbc674 ldr r1, [pc, #-0x934]
 *   @0xbc678 mov r6, #3
 *   @0xbc67c add r1, pc, r1
 *   @0xbc680 ldr r3, [r3, #0xc]
 *   @0xbc684 blx r3
 *   @0xbc688 b 0xbaadc <_Z12GLFuncImportb+0x3cc>
 *   @0xbc68c ldr r3, [r5]
 *   @0xbc690 mov r0, r5
 *   @0xbc694 ldr r1, [pc, #-0x950]
 *   @0xbc698 mov r6, #3
 *   @0xbc69c add r1, pc, r1
 *   @0xbc6a0 ldr r3, [r3, #0xc]
 *   @0xbc6a4 blx r3
 *   @0xbc6a8 b 0xbab08 <_Z12GLFuncImportb+0x3f8>
 *   @0xbc6ac ldr r3, [r5]
 *   @0xbc6b0 mov r0, r5
 *   @0xbc6b4 ldr r1, [pc, #-0x96c]
 *   @0xbc6b8 mov r6, #3
 *   @0xbc6bc add r1, pc, r1
 *   @0xbc6c0 ldr r3, [r3, #0xc]
 *   @0xbc6c4 blx r3
 *   @0xbc6c8 b 0xbab34 <_Z12GLFuncImportb+0x424>
 *   @0xbc6cc ldr r3, [r5]
 *   @0xbc6d0 mov r0, r5
 *   @0xbc6d4 ldr r1, [pc, #-0x988]
 *   @0xbc6d8 mov r6, #3
 *   @0xbc6dc add r1, pc, r1
 *   @0xbc6e0 ldr r3, [r3, #0xc]
 *   @0xbc6e4 blx r3
 *   @0xbc6e8 b 0xbab60 <_Z12GLFuncImportb+0x450>
 *   @0xbc6ec ldr r3, [r5]
 *   @0xbc6f0 mov r0, r5
 *   @0xbc6f4 ldr r1, [pc, #-0x9a4]
 *   @0xbc6f8 mov r6, #3
 *   @0xbc6fc add r1, pc, r1
 *   @0xbc700 ldr r3, [r3, #0xc]
 *   @0xbc704 blx r3
 *   @0xbc708 b 0xbab8c <_Z12GLFuncImportb+0x47c>
 *   @0xbc70c ldr r3, [r5]
 *   @0xbc710 mov r0, r5
 *   @0xbc714 ldr r1, [pc, #-0x9c0]
 *   @0xbc718 mov r6, #3
 *   @0xbc71c add r1, pc, r1
 *   @0xbc720 ldr r3, [r3, #0xc]
 *   @0xbc724 blx r3
 *   @0xbc728 b 0xbabb8 <_Z12GLFuncImportb+0x4a8>
 *   @0xbc72c ldr r3, [r5]
 *   @0xbc730 mov r0, r5
 *   @0xbc734 ldr r1, [pc, #-0x9dc]
 *   @0xbc738 mov r6, #3
 *   @0xbc73c add r1, pc, r1
 *   @0xbc740 ldr r3, [r3, #0xc]
 *   @0xbc744 blx r3
 *   @0xbc748 b 0xbabe4 <_Z12GLFuncImportb+0x4d4>
 *   @0xbc74c ldr r3, [r5]
 *   @0xbc750 mov r0, r5
 *   @0xbc754 ldr r1, [pc, #-0x9f8]
 *   @0xbc758 mov r6, #3
 *   @0xbc75c add r1, pc, r1
 *   @0xbc760 ldr r3, [r3, #0xc]
 *   @0xbc764 blx r3
 *   @0xbc768 b 0xbac10 <_Z12GLFuncImportb+0x500>
 *   @0xbc76c ldr r3, [r5]
 *   @0xbc770 mov r0, r5
 *   @0xbc774 ldr r1, [pc, #-0xa14]
 *   @0xbc778 mov r6, #3
 *   @0xbc77c add r1, pc, r1
 *   @0xbc780 ldr r3, [r3, #0xc]
 *   @0xbc784 blx r3
 *   @0xbc788 b 0xbac3c <_Z12GLFuncImportb+0x52c>
 *   @0xbc78c ldr r3, [r5]
 *   @0xbc790 mov r0, r5
 *   @0xbc794 ldr r1, [pc, #-0xa30]
 *   @0xbc798 mov r6, #3
 *   @0xbc79c add r1, pc, r1
 *   @0xbc7a0 ldr r3, [r3, #0xc]
 *   @0xbc7a4 blx r3
 *   @0xbc7a8 b 0xbac68 <_Z12GLFuncImportb+0x558>
 *   @0xbc7ac ldr r3, [r5]
 *   @0xbc7b0 mov r0, r5
 *   @0xbc7b4 ldr r1, [pc, #-0xa4c]
 *   @0xbc7b8 mov r6, #3
 *   @0xbc7bc add r1, pc, r1
 *   @0xbc7c0 ldr r3, [r3, #0xc]
 *   @0xbc7c4 blx r3
 *   @0xbc7c8 b 0xbac94 <_Z12GLFuncImportb+0x584>
 *   @0xbc7cc ldr r3, [r5]
 *   @0xbc7d0 mov r0, r5
 *   @0xbc7d4 ldr r1, [pc, #-0xa68]
 *   @0xbc7d8 mov r6, #3
 *   @0xbc7dc add r1, pc, r1
 *   @0xbc7e0 ldr r3, [r3, #0xc]
 *   @0xbc7e4 blx r3
 *   @0xbc7e8 b 0xba8a0 <_Z12GLFuncImportb+0x190>
 *   @0xbc7ec ldr r3, [r5]
 *   @0xbc7f0 mov r0, r5
 *   @0xbc7f4 ldr r1, [pc, #-0xa84]
 *   @0xbc7f8 mov r6, #3
 *   @0xbc7fc add r1, pc, r1
 *   @0xbc800 ldr r3, [r3, #0xc]
 *   @0xbc804 blx r3
 *   @0xbc808 b 0xba8cc <_Z12GLFuncImportb+0x1bc>
 *   @0xbc80c ldr r3, [r5]
 *   @0xbc810 mov r0, r5
 *   @0xbc814 ldr r1, [pc, #-0xaa0]
 *   @0xbc818 mov r6, #3
 *   @0xbc81c add r1, pc, r1
 *   @0xbc820 ldr r3, [r3, #0xc]
 *   @0xbc824 blx r3
 *   @0xbc828 b 0xba8f8 <_Z12GLFuncImportb+0x1e8>
 *   @0xbc82c ldr r3, [r5]
 *   @0xbc830 mov r0, r5
 *   @0xbc834 ldr r1, [pc, #-0xabc]
 *   @0xbc838 mov r6, #3
 *   @0xbc83c add r1, pc, r1
 *   @0xbc840 ldr r3, [r3, #0xc]
 *   @0xbc844 blx r3
 *   @0xbc848 b 0xba924 <_Z12GLFuncImportb+0x214>
 *   @0xbc84c ldr r3, [r5]
 *   @0xbc850 mov r0, r5
 *   @0xbc854 ldr r1, [pc, #-0xad8]
 *   @0xbc858 mov r6, #3
 *   @0xbc85c add r1, pc, r1
 *   @0xbc860 ldr r3, [r3, #0xc]
 *   @0xbc864 blx r3
 *   @0xbc868 b 0xba950 <_Z12GLFuncImportb+0x240>
 *   @0xbc86c ldr r3, [r5]
 *   @0xbc870 mov r0, r5
 *   @0xbc874 ldr r1, [pc, #-0xaf4]
 *   @0xbc878 mov r6, #3
 *   @0xbc87c add r1, pc, r1
 *   @0xbc880 ldr r3, [r3, #0xc]
 *   @0xbc884 blx r3
 *   @0xbc888 b 0xba97c <_Z12GLFuncImportb+0x26c>
 *   @0xbc88c ldr r3, [r5]
 *   @0xbc890 mov r0, r5
 *   @0xbc894 ldr r1, [pc, #-0xb10]
 *   @0xbc898 mov r6, #3
 *   @0xbc89c add r1, pc, r1
 *   @0xbc8a0 ldr r3, [r3, #0xc]
 *   @0xbc8a4 blx r3
 *   @0xbc8a8 b 0xba9a8 <_Z12GLFuncImportb+0x298>
 *   @0xbc8ac ldr r3, [r5]
 *   @0xbc8b0 mov r0, r5
 *   @0xbc8b4 ldr r1, [pc, #-0xb2c]
 *   @0xbc8b8 mov r6, #3
 *   @0xbc8bc add r1, pc, r1
 *   @0xbc8c0 ldr r3, [r3, #0xc]
 *   @0xbc8c4 blx r3
 *   @0xbc8c8 b 0xba9d4 <_Z12GLFuncImportb+0x2c4>
 *   @0xbc8cc ldr r3, [r5]
 *   @0xbc8d0 mov r0, r5
 *   @0xbc8d4 ldr r1, [pc, #-0xb48]
 *   @0xbc8d8 mov r6, #3
 *   @0xbc8dc add r1, pc, r1
 *   @0xbc8e0 ldr r3, [r3, #0xc]
 *   @0xbc8e4 blx r3
 *   @0xbc8e8 b 0xba7f0 <_Z12GLFuncImportb+0xe0>
 *   @0xbc8ec ldr r3, [r5]
 *   @0xbc8f0 mov r0, r5
 *   @0xbc8f4 ldr r1, [pc, #-0xb64]
 *   @0xbc8f8 mov r6, #3
 *   @0xbc8fc add r1, pc, r1
 *   @0xbc900 ldr r3, [r3, #0xc]
 *   @0xbc904 blx r3
 *   @0xbc908 b 0xba81c <_Z12GLFuncImportb+0x10c>
 *   @0xbc90c ldr r3, [r5]
 *   @0xbc910 mov r0, r5
 *   @0xbc914 ldr r1, [pc, #-0xb80]
 *   @0xbc918 mov r6, #3
 *   @0xbc91c add r1, pc, r1
 *   @0xbc920 ldr r3, [r3, #0xc]
 *   @0xbc924 blx r3
 *   @0xbc928 b 0xba848 <_Z12GLFuncImportb+0x138>
 *   @0xbc92c ldr r3, [r5]
 *   @0xbc930 mov r0, r5
 *   @0xbc934 ldr r1, [pc, #-0xb9c]
 *   @0xbc938 mov r6, #3
 *   @0xbc93c add r1, pc, r1
 *   @0xbc940 ldr r3, [r3, #0xc]
 *   @0xbc944 blx r3
 *   @0xbc948 b 0xba874 <_Z12GLFuncImportb+0x164>
 *   @0xbc94c ldr r3, [r5]
 *   @0xbc950 mov r0, r5
 *   @0xbc954 ldr r1, [pc, #-0xbb8]
 *   @0xbc958 mov r6, #3
 *   @0xbc95c add r1, pc, r1
 *   @0xbc960 ldr r3, [r3, #0xc]
 *   @0xbc964 blx r3
 *   @0xbc968 b 0xbae20 <_Z12GLFuncImportb+0x710>
 *   @0xbc96c ldr r3, [r5]
 *   @0xbc970 mov r0, r5
 *   @0xbc974 ldr r1, [pc, #-0xbd4]
 *   @0xbc978 mov r6, #3
 *   @0xbc97c add r1, pc, r1
 *   @0xbc980 ldr r3, [r3, #0xc]
 *   @0xbc984 blx r3
 *   @0xbc988 b 0xbae4c <_Z12GLFuncImportb+0x73c>
 *   @0xbc98c ldr r3, [r5]
 *   @0xbc990 mov r0, r5
 *   @0xbc994 ldr r1, [pc, #-0xbf0]
 *   @0xbc998 mov r6, #3
 *   @0xbc99c add r1, pc, r1
 *   @0xbc9a0 ldr r3, [r3, #0xc]
 *   @0xbc9a4 blx r3
 *   @0xbc9a8 b 0xba798 <_Z12GLFuncImportb+0x88>
 *   @0xbc9ac ldr r3, [r5]
 *   @0xbc9b0 mov r0, r5
 *   @0xbc9b4 ldr r1, [pc, #-0xc0c]
 *   @0xbc9b8 mov r6, #3
 *   @0xbc9bc add r1, pc, r1
 *   @0xbc9c0 ldr r3, [r3, #0xc]
 *   @0xbc9c4 blx r3
 *   @0xbc9c8 b 0xba7c4 <_Z12GLFuncImportb+0xb4>
 *   @0xbc9cc ldr r3, [r5]
 *   @0xbc9d0 mov r0, r5
 *   @0xbc9d4 ldr r1, [pc, #-0xc28]
 *   @0xbc9d8 mov r6, #3
 *   @0xbc9dc add r1, pc, r1
 *   @0xbc9e0 ldr r3, [r3, #0xc]
 *   @0xbc9e4 blx r3
 *   @0xbc9e8 b 0xbacc0 <_Z12GLFuncImportb+0x5b0>
 *   @0xbc9ec ldr r3, [r5]
 *   @0xbc9f0 mov r0, r5
 *   @0xbc9f4 ldr r1, [pc, #-0xc44]
 *   @0xbc9f8 mov r6, #3
 *   @0xbc9fc add r1, pc, r1
 *   @0xbca00 ldr r3, [r3, #0xc]
 *   @0xbca04 blx r3
 *   @0xbca08 b 0xbacec <_Z12GLFuncImportb+0x5dc>
 *   @0xbca0c ldr r3, [r5]
 *   @0xbca10 mov r0, r5
 *   @0xbca14 ldr r1, [pc, #-0xc60]
 *   @0xbca18 mov r6, #3
 *   @0xbca1c add r1, pc, r1
 *   @0xbca20 ldr r3, [r3, #0xc]
 *   @0xbca24 blx r3
 *   @0xbca28 b 0xbad18 <_Z12GLFuncImportb+0x608>
 *   @0xbca2c ldr r3, [r5]
 *   @0xbca30 mov r0, r5
 *   @0xbca34 ldr r1, [pc, #-0xc7c]
 *   @0xbca38 mov r6, #3
 *   @0xbca3c add r1, pc, r1
 *   @0xbca40 ldr r3, [r3, #0xc]
 *   @0xbca44 blx r3
 *   @0xbca48 b 0xbad44 <_Z12GLFuncImportb+0x634>
 *   @0xbca4c ldr r3, [r5]
 *   @0xbca50 mov r0, r5
 *   @0xbca54 ldr r1, [pc, #-0xc98]
 *   @0xbca58 mov r6, #3
 *   @0xbca5c add r1, pc, r1
 *   @0xbca60 ldr r3, [r3, #0xc]
 *   @0xbca64 blx r3
 *   @0xbca68 b 0xbad70 <_Z12GLFuncImportb+0x660>
 *   @0xbca6c ldr r3, [r5]
 *   @0xbca70 mov r0, r5
 *   @0xbca74 ldr r1, [pc, #-0xcb4]
 *   @0xbca78 mov r6, #3
 *   @0xbca7c add r1, pc, r1
 *   @0xbca80 ldr r3, [r3, #0xc]
 *   @0xbca84 blx r3
 *   @0xbca88 b 0xbad9c <_Z12GLFuncImportb+0x68c>
 *   @0xbca8c ldr r3, [r5]
 *   @0xbca90 mov r0, r5
 *   @0xbca94 ldr r1, [pc, #-0xcd0]
 *   @0xbca98 mov r6, #3
 *   @0xbca9c add r1, pc, r1
 *   @0xbcaa0 ldr r3, [r3, #0xc]
 *   @0xbcaa4 blx r3
 *   @0xbcaa8 b 0xbadc8 <_Z12GLFuncImportb+0x6b8>
 *   @0xbcaac ldr r3, [r5]
 *   @0xbcab0 mov r0, r5
 *   @0xbcab4 ldr r1, [pc, #-0xcec]
 *   @0xbcab8 mov r6, #3
 *   @0xbcabc add r1, pc, r1
 *   @0xbcac0 ldr r3, [r3, #0xc]
 *   @0xbcac4 blx r3
 *   @0xbcac8 b 0xbadf4 <_Z12GLFuncImportb+0x6e4>
 *   @0xbcacc ldr r3, [r5]
 *   @0xbcad0 mov r0, r5
 *   @0xbcad4 ldr r1, [pc, #-0xd08]
 *   @0xbcad8 mov r6, #3
 *   @0xbcadc add r1, pc, r1
 *   @0xbcae0 ldr r3, [r3, #0xc]
 *   @0xbcae4 blx r3
 *   @0xbcae8 b 0xbb090 <_Z12GLFuncImportb+0x980>
 *   @0xbcaec ldr r3, [r5]
 *   @0xbcaf0 mov r0, r5
 *   @0xbcaf4 ldr r1, [pc, #-0xd24]
 *   @0xbcaf8 mov r6, #3
 *   @0xbcafc add r1, pc, r1
 *   @0xbcb00 ldr r3, [r3, #0xc]
 *   @0xbcb04 blx r3
 *   @0xbcb08 b 0xbb064 <_Z12GLFuncImportb+0x954>
 *   @0xbcb0c ldr r3, [r5]
 *   @0xbcb10 mov r0, r5
 *   @0xbcb14 ldr r1, [pc, #-0xd40]
 *   @0xbcb18 mov r6, #3
 *   @0xbcb1c add r1, pc, r1
 *   @0xbcb20 ldr r3, [r3, #0xc]
 *   @0xbcb24 blx r3
 *   @0xbcb28 b 0xbb038 <_Z12GLFuncImportb+0x928>
 *   @0xbcb2c ldr r3, [r5]
 *   @0xbcb30 mov r0, r5
 *   @0xbcb34 ldr r1, [pc, #-0xd5c]
 *   @0xbcb38 mov r6, #3
 *   @0xbcb3c add r1, pc, r1
 *   @0xbcb40 ldr r3, [r3, #0xc]
 *   @0xbcb44 blx r3
 *   @0xbcb48 b 0xbb00c <_Z12GLFuncImportb+0x8fc>
 *   @0xbcb4c ldr r3, [r5]
 *   @0xbcb50 mov r0, r5
 *   @0xbcb54 ldr r1, [pc, #-0xd78]
 *   @0xbcb58 mov r6, #3
 *   @0xbcb5c add r1, pc, r1
 *   @0xbcb60 ldr r3, [r3, #0xc]
 *   @0xbcb64 blx r3
 *   @0xbcb68 b 0xbafe0 <_Z12GLFuncImportb+0x8d0>
 *   @0xbcb6c ldr r3, [r5]
 *   @0xbcb70 mov r0, r5
 *   @0xbcb74 ldr r1, [pc, #-0xd94]
 *   @0xbcb78 mov r6, #3
 *   @0xbcb7c add r1, pc, r1
 *   @0xbcb80 ldr r3, [r3, #0xc]
 *   @0xbcb84 blx r3
 *   @0xbcb88 b 0xbafb4 <_Z12GLFuncImportb+0x8a4>
 *   @0xbcb8c ldr r3, [r5]
 *   @0xbcb90 mov r0, r5
 *   @0xbcb94 ldr r1, [pc, #-0xdb0]
 *   @0xbcb98 mov r6, #3
 *   @0xbcb9c add r1, pc, r1
 *   @0xbcba0 ldr r3, [r3, #0xc]
 *   @0xbcba4 blx r3
 *   @0xbcba8 b 0xbaf88 <_Z12GLFuncImportb+0x878>
 *   @0xbcbac ldr r3, [r5]
 *   @0xbcbb0 mov r0, r5
 *   @0xbcbb4 ldr r1, [pc, #-0xdcc]
 *   @0xbcbb8 mov r6, #3
 *   @0xbcbbc add r1, pc, r1
 *   @0xbcbc0 ldr r3, [r3, #0xc]
 *   @0xbcbc4 blx r3
 *   @0xbcbc8 b 0xbaf5c <_Z12GLFuncImportb+0x84c>
 *   @0xbcbcc ldr r3, [r5]
 *   @0xbcbd0 mov r0, r5
 *   @0xbcbd4 ldr r1, [pc, #-0xde8]
 *   @0xbcbd8 mov r6, #3
 *   @0xbcbdc add r1, pc, r1
 *   @0xbcbe0 ldr r3, [r3, #0xc]
 *   @0xbcbe4 blx r3
 *   @0xbcbe8 b 0xbaf30 <_Z12GLFuncImportb+0x820>
 *   @0xbcbec ldr r3, [r5]
 *   @0xbcbf0 mov r0, r5
 *   @0xbcbf4 ldr r1, [pc, #-0xe04]
 *   @0xbcbf8 mov r6, #3
 *   @0xbcbfc add r1, pc, r1
 *   @0xbcc00 ldr r3, [r3, #0xc]
 *   @0xbcc04 blx r3
 *   @0xbcc08 b 0xbaf04 <_Z12GLFuncImportb+0x7f4>
 *   @0xbcc0c ldr r3, [r5]
 *   @0xbcc10 mov r0, r5
 *   @0xbcc14 ldr r1, [pc, #-0xe20]
 *   @0xbcc18 mov r6, #3
 *   @0xbcc1c add r1, pc, r1
 *   @0xbcc20 ldr r3, [r3, #0xc]
 *   @0xbcc24 blx r3
 *   @0xbcc28 b 0xbaed8 <_Z12GLFuncImportb+0x7c8>
 *   @0xbcc2c ldr r3, [r5]
 *   @0xbcc30 mov r0, r5
 *   @0xbcc34 ldr r1, [pc, #-0xe3c]
 *   @0xbcc38 mov r6, #3
 *   @0xbcc3c add r1, pc, r1
 *   @0xbcc40 ldr r3, [r3, #0xc]
 *   @0xbcc44 blx r3
 *   @0xbcc48 b 0xbae80 <_Z12GLFuncImportb+0x770>
 *   @0xbcc4c ldr r3, [r5]
 *   @0xbcc50 mov r0, r5
 *   @0xbcc54 ldr r1, [pc, #-0xe58]
 *   @0xbcc58 mov r6, #3
 *   @0xbcc5c add r1, pc, r1
 *   @0xbcc60 ldr r3, [r3, #0xc]
 *   @0xbcc64 blx r3
 *   @0xbcc68 b 0xbc59c <_Z12GLFuncImportb+0x1e8c>
 *   @0xbcc6c ldr r3, [r5]
 *   @0xbcc70 mov r0, r5
 *   @0xbcc74 ldr r1, [pc, #-0xe74]
 *   @0xbcc78 mov r6, #3
 *   @0xbcc7c add r1, pc, r1
 *   @0xbcc80 ldr r3, [r3, #0xc]
 *   @0xbcc84 blx r3
 *   @0xbcc88 b 0xbc570 <_Z12GLFuncImportb+0x1e60>
 *   @0xbcc8c ldr r3, [r5]
 *   @0xbcc90 mov r0, r5
 *   @0xbcc94 ldr r1, [pc, #-0xe90]
 *   @0xbcc98 mov r6, #3
 *   @0xbcc9c add r1, pc, r1
 *   @0xbcca0 ldr r3, [r3, #0xc]
 *   @0xbcca4 blx r3
 *   @0xbcca8 b 0xbc544 <_Z12GLFuncImportb+0x1e34>
 *   @0xbccac ldr r3, [r5]
 *   @0xbccb0 mov r0, r5
 *   @0xbccb4 ldr r1, [pc, #-0xeac]
 *   @0xbccb8 mov r6, #3
 *   @0xbccbc add r1, pc, r1
 *   @0xbccc0 ldr r3, [r3, #0xc]
 *   @0xbccc4 blx r3
 *   @0xbccc8 b 0xbc518 <_Z12GLFuncImportb+0x1e08>
 *   @0xbcccc ldr r3, [r5]
 *   @0xbccd0 mov r0, r5
 *   @0xbccd4 ldr r1, [pc, #-0xec8]
 *   @0xbccd8 mov r6, #3
 *   @0xbccdc add r1, pc, r1
 *   @0xbcce0 ldr r3, [r3, #0xc]
 *   @0xbcce4 blx r3
 *   @0xbcce8 b 0xbc4ec <_Z12GLFuncImportb+0x1ddc>
 *   @0xbccec ldr r3, [r5]
 *   @0xbccf0 mov r0, r5
 *   @0xbccf4 ldr r1, [pc, #-0xee4]
 *   @0xbccf8 mov r6, #3
 *   @0xbccfc add r1, pc, r1
 *   @0xbcd00 ldr r3, [r3, #0xc]
 *   @0xbcd04 blx r3
 *   @0xbcd08 b 0xbc4c0 <_Z12GLFuncImportb+0x1db0>
 *   @0xbcd0c ldr r3, [r5]
 *   @0xbcd10 mov r0, r5
 *   @0xbcd14 ldr r1, [pc, #-0xf00]
 *   @0xbcd18 mov r6, #3
 *   @0xbcd1c add r1, pc, r1
 *   @0xbcd20 ldr r3, [r3, #0xc]
 *   @0xbcd24 blx r3
 *   @0xbcd28 b 0xbc494 <_Z12GLFuncImportb+0x1d84>
 *   @0xbcd2c ldr r3, [r5]
 *   @0xbcd30 mov r0, r5
 *   @0xbcd34 ldr r1, [pc, #-0xf1c]
 *   @0xbcd38 mov r6, #3
 *   @0xbcd3c add r1, pc, r1
 *   @0xbcd40 ldr r3, [r3, #0xc]
 *   @0xbcd44 blx r3
 *   @0xbcd48 b 0xbc468 <_Z12GLFuncImportb+0x1d58>
 *   @0xbcd4c ldr r3, [r5]
 *   @0xbcd50 mov r0, r5
 *   @0xbcd54 ldr r1, [pc, #-0xf38]
 *   @0xbcd58 mov r6, #3
 *   @0xbcd5c add r1, pc, r1
 *   @0xbcd60 ldr r3, [r3, #0xc]
 *   @0xbcd64 blx r3
 *   @0xbcd68 b 0xbc43c <_Z12GLFuncImportb+0x1d2c>
 *   @0xbcd6c ldr r3, [r5]
 *   @0xbcd70 mov r0, r5
 *   @0xbcd74 ldr r1, [pc, #-0xf54]
 *   @0xbcd78 mov r6, #3
 *   @0xbcd7c add r1, pc, r1
 *   @0xbcd80 ldr r3, [r3, #0xc]
 *   @0xbcd84 blx r3
 *   @0xbcd88 b 0xbc410 <_Z12GLFuncImportb+0x1d00>
 *   @0xbcd8c ldr r3, [r5]
 *   @0xbcd90 mov r0, r5
 *   @0xbcd94 ldr r1, [pc, #-0xf70]
 *   @0xbcd98 mov r6, #3
 *   @0xbcd9c add r1, pc, r1
 *   @0xbcda0 ldr r3, [r3, #0xc]
 *   @0xbcda4 blx r3
 *   @0xbcda8 b 0xbc3e4 <_Z12GLFuncImportb+0x1cd4>
 *   @0xbcdac ldr r3, [r5]
 *   @0xbcdb0 mov r0, r5
 *   @0xbcdb4 ldr r1, [pc, #-0xf8c]
 *   @0xbcdb8 mov r6, #3
 *   @0xbcdbc add r1, pc, r1
 *   @0xbcdc0 ldr r3, [r3, #0xc]
 *   @0xbcdc4 blx r3
 *   @0xbcdc8 b 0xbb610 <_Z12GLFuncImportb+0xf00>
 *   @0xbcdcc ldr r3, [r5]
 *   @0xbcdd0 mov r0, r5
 *   @0xbcdd4 ldr r1, [pc, #-0xfa8]
 *   @0xbcdd8 mov r6, #3
 *   @0xbcddc add r1, pc, r1
 *   @0xbcde0 ldr r3, [r3, #0xc]
 *   @0xbcde4 blx r3
 *   @0xbcde8 b 0xbb5e4 <_Z12GLFuncImportb+0xed4>
 *   @0xbcdec ldr r3, [r5]
 *   @0xbcdf0 mov r0, r5
 *   @0xbcdf4 ldr r1, [pc, #-0xfc4]
 *   @0xbcdf8 mov r6, #3
 *   @0xbcdfc add r1, pc, r1
 *   @0xbce00 ldr r3, [r3, #0xc]
 *   @0xbce04 blx r3
 *   @0xbce08 b 0xbb5b8 <_Z12GLFuncImportb+0xea8>
 *   @0xbce0c ldr r3, [r5]
 *   @0xbce10 mov r0, r5
 *   @0xbce14 ldr r1, [pc, #-0xfe0]
 *   @0xbce18 mov r6, #3
 *   @0xbce1c add r1, pc, r1
 *   @0xbce20 ldr r3, [r3, #0xc]
 *   @0xbce24 blx r3
 *   @0xbce28 b 0xbb58c <_Z12GLFuncImportb+0xe7c>
 *   @0xbce2c ldr r3, [r5]
 *   @0xbce30 mov r0, r5
 *   @0xbce34 ldr r1, [pc, #-0xffc]
 *   @0xbce38 mov r6, #3
 *   @0xbce3c add r1, pc, r1
 *   @0xbce40 ldr r3, [r3, #0xc]
 *   @0xbce44 blx r3
 *   @0xbce48 b 0xbb560 <_Z12GLFuncImportb+0xe50>
 *   @0xbce4c ldr r3, [r5]
 *   @0xbce50 mov r0, r5
 *   @0xbce54 ldr r1, [pc, #0x75c]
 *   @0xbce58 mov r6, #3
 *   @0xbce5c add r1, pc, r1
 *   @0xbce60 ldr r3, [r3, #0xc]
 *   @0xbce64 blx r3
 *   @0xbce68 b 0xbb534 <_Z12GLFuncImportb+0xe24>
 *   @0xbce6c ldr r3, [r5]
 *   @0xbce70 mov r0, r5
 *   @0xbce74 ldr r1, [pc, #0x740]
 *   @0xbce78 mov r6, #3
 *   @0xbce7c add r1, pc, r1
 *   @0xbce80 ldr r3, [r3, #0xc]
 *   @0xbce84 blx r3
 *   @0xbce88 b 0xbb508 <_Z12GLFuncImportb+0xdf8>
 *   @0xbce8c ldr r3, [r5]
 *   @0xbce90 mov r0, r5
 *   @0xbce94 ldr r1, [pc, #0x724]
 *   @0xbce98 mov r6, #3
 *   @0xbce9c add r1, pc, r1
 *   @0xbcea0 ldr r3, [r3, #0xc]
 *   @0xbcea4 blx r3
 *   @0xbcea8 b 0xbb4dc <_Z12GLFuncImportb+0xdcc>
 *   @0xbceac ldr r3, [r5]
 *   @0xbceb0 mov r0, r5
 *   @0xbceb4 ldr r1, [pc, #0x708]
 *   @0xbceb8 mov r6, #3
 *   @0xbcebc add r1, pc, r1
 *   @0xbcec0 ldr r3, [r3, #0xc]
 *   @0xbcec4 blx r3
 *   @0xbcec8 b 0xbb4b0 <_Z12GLFuncImportb+0xda0>
 *   @0xbcecc ldr r3, [r5]
 *   @0xbced0 mov r0, r5
 *   @0xbced4 ldr r1, [pc, #0x6ec]
 *   @0xbced8 mov r6, #3
 *   @0xbcedc add r1, pc, r1
 *   @0xbcee0 ldr r3, [r3, #0xc]
 *   @0xbcee4 blx r3
 *   @0xbcee8 b 0xbb484 <_Z12GLFuncImportb+0xd74>
 *   @0xbceec ldr r3, [r5]
 *   @0xbcef0 mov r0, r5
 *   @0xbcef4 ldr r1, [pc, #0x6d0]
 *   @0xbcef8 mov r6, #3
 *   @0xbcefc add r1, pc, r1
 *   @0xbcf00 ldr r3, [r3, #0xc]
 *   @0xbcf04 blx r3
 *   @0xbcf08 b 0xbb458 <_Z12GLFuncImportb+0xd48>
 *   @0xbcf0c ldr r3, [r5]
 *   @0xbcf10 mov r0, r5
 *   @0xbcf14 ldr r1, [pc, #0x6b4]
 *   @0xbcf18 mov r6, #3
 *   @0xbcf1c add r1, pc, r1
 *   @0xbcf20 ldr r3, [r3, #0xc]
 *   @0xbcf24 blx r3
 *   @0xbcf28 b 0xbb42c <_Z12GLFuncImportb+0xd1c>
 *   @0xbcf2c ldr r3, [r5]
 *   @0xbcf30 mov r0, r5
 *   @0xbcf34 ldr r1, [pc, #0x698]
 *   @0xbcf38 mov r6, #3
 *   @0xbcf3c add r1, pc, r1
 *   @0xbcf40 ldr r3, [r3, #0xc]
 *   @0xbcf44 blx r3
 *   @0xbcf48 b 0xbb400 <_Z12GLFuncImportb+0xcf0>
 *   @0xbcf4c ldr r3, [r5]
 *   @0xbcf50 mov r0, r5
 *   @0xbcf54 ldr r1, [pc, #0x67c]
 *   @0xbcf58 mov r6, #3
 *   @0xbcf5c add r1, pc, r1
 *   @0xbcf60 ldr r3, [r3, #0xc]
 *   @0xbcf64 blx r3
 *   @0xbcf68 b 0xbb3d4 <_Z12GLFuncImportb+0xcc4>
 *   @0xbcf6c ldr r3, [r5]
 *   @0xbcf70 mov r0, r5
 *   @0xbcf74 ldr r1, [pc, #0x660]
 *   @0xbcf78 mov r6, #3
 *   @0xbcf7c add r1, pc, r1
 *   @0xbcf80 ldr r3, [r3, #0xc]
 *   @0xbcf84 blx r3
 *   @0xbcf88 b 0xbb3a8 <_Z12GLFuncImportb+0xc98>
 *   @0xbcf8c ldr r3, [r5]
 *   @0xbcf90 mov r0, r5
 *   @0xbcf94 ldr r1, [pc, #0x644]
 *   @0xbcf98 mov r6, #3
 *   @0xbcf9c add r1, pc, r1
 *   @0xbcfa0 ldr r3, [r3, #0xc]
 *   @0xbcfa4 blx r3
 *   @0xbcfa8 b 0xbb37c <_Z12GLFuncImportb+0xc6c>
 *   @0xbcfac ldr r3, [r5]
 *   @0xbcfb0 mov r0, r5
 *   @0xbcfb4 ldr r1, [pc, #0x628]
 *   @0xbcfb8 mov r6, #3
 *   @0xbcfbc add r1, pc, r1
 *   @0xbcfc0 ldr r3, [r3, #0xc]
 *   @0xbcfc4 blx r3
 *   @0xbcfc8 b 0xbb350 <_Z12GLFuncImportb+0xc40>
 *   @0xbcfcc ldr r3, [r5]
 *   @0xbcfd0 mov r0, r5
 *   @0xbcfd4 ldr r1, [pc, #0x60c]
 *   @0xbcfd8 mov r6, #3
 *   @0xbcfdc add r1, pc, r1
 *   @0xbcfe0 ldr r3, [r3, #0xc]
 *   @0xbcfe4 blx r3
 *   @0xbcfe8 b 0xbb324 <_Z12GLFuncImportb+0xc14>
 *   @0xbcfec ldr r3, [r5]
 *   @0xbcff0 mov r0, r5
 *   @0xbcff4 ldr r1, [pc, #0x5f0]
 *   @0xbcff8 mov r6, #3
 *   @0xbcffc add r1, pc, r1
 *   @0xbd000 ldr r3, [r3, #0xc]
 *   @0xbd004 blx r3
 *   @0xbd008 b 0xbb2f8 <_Z12GLFuncImportb+0xbe8>
 *   @0xbd00c ldr r3, [r5]
 *   @0xbd010 mov r0, r5
 *   @0xbd014 ldr r1, [pc, #0x5d4]
 *   @0xbd018 mov r6, #3
 *   @0xbd01c add r1, pc, r1
 *   @0xbd020 ldr r3, [r3, #0xc]
 *   @0xbd024 blx r3
 *   @0xbd028 b 0xbb2cc <_Z12GLFuncImportb+0xbbc>
 *   @0xbd02c ldr r3, [r5]
 *   @0xbd030 mov r0, r5
 *   @0xbd034 ldr r1, [pc, #0x5b8]
 *   @0xbd038 mov r6, #3
 *   @0xbd03c add r1, pc, r1
 *   @0xbd040 ldr r3, [r3, #0xc]
 *   @0xbd044 blx r3
 *   @0xbd048 b 0xbb2a0 <_Z12GLFuncImportb+0xb90>
 *   @0xbd04c ldr r3, [r5]
 *   @0xbd050 mov r0, r5
 *   @0xbd054 ldr r1, [pc, #0x59c]
 *   @0xbd058 mov r6, #3
 *   @0xbd05c add r1, pc, r1
 *   @0xbd060 ldr r3, [r3, #0xc]
 *   @0xbd064 blx r3
 *   @0xbd068 b 0xbb274 <_Z12GLFuncImportb+0xb64>
 *   @0xbd06c ldr r3, [r5]
 *   @0xbd070 mov r0, r5
 *   @0xbd074 ldr r1, [pc, #0x580]
 *   @0xbd078 mov r6, #3
 *   @0xbd07c add r1, pc, r1
 *   @0xbd080 ldr r3, [r3, #0xc]
 *   @0xbd084 blx r3
 *   @0xbd088 b 0xbb248 <_Z12GLFuncImportb+0xb38>
 *   @0xbd08c ldr r3, [r5]
 *   @0xbd090 mov r0, r5
 *   @0xbd094 ldr r1, [pc, #0x564]
 *   @0xbd098 mov r6, #3
 *   @0xbd09c add r1, pc, r1
 *   @0xbd0a0 ldr r3, [r3, #0xc]
 *   @0xbd0a4 blx r3
 *   @0xbd0a8 b 0xbb21c <_Z12GLFuncImportb+0xb0c>
 *   @0xbd0ac ldr r3, [r5]
 *   @0xbd0b0 mov r0, r5
 *   @0xbd0b4 ldr r1, [pc, #0x548]
 *   @0xbd0b8 mov r6, #3
 *   @0xbd0bc add r1, pc, r1
 *   @0xbd0c0 ldr r3, [r3, #0xc]
 *   @0xbd0c4 blx r3
 *   @0xbd0c8 b 0xbb1f0 <_Z12GLFuncImportb+0xae0>
 *   @0xbd0cc ldr r3, [r5]
 *   @0xbd0d0 mov r0, r5
 *   @0xbd0d4 ldr r1, [pc, #0x52c]
 *   @0xbd0d8 mov r6, #3
 *   @0xbd0dc add r1, pc, r1
 *   @0xbd0e0 ldr r3, [r3, #0xc]
 *   @0xbd0e4 blx r3
 *   @0xbd0e8 b 0xbb1c4 <_Z12GLFuncImportb+0xab4>
 *   @0xbd0ec ldr r3, [r5]
 *   @0xbd0f0 mov r0, r5
 *   @0xbd0f4 ldr r1, [pc, #0x510]
 *   @0xbd0f8 mov r6, #3
 *   @0xbd0fc add r1, pc, r1
 *   @0xbd100 ldr r3, [r3, #0xc]
 *   @0xbd104 blx r3
 *   @0xbd108 b 0xbb198 <_Z12GLFuncImportb+0xa88>
 *   @0xbd10c ldr r3, [r5]
 *   @0xbd110 mov r0, r5
 *   @0xbd114 ldr r1, [pc, #0x4f4]
 *   @0xbd118 mov r6, #3
 *   @0xbd11c add r1, pc, r1
 *   @0xbd120 ldr r3, [r3, #0xc]
 *   @0xbd124 blx r3
 *   @0xbd128 b 0xbb16c <_Z12GLFuncImportb+0xa5c>
 *   @0xbd12c ldr r3, [r5]
 *   @0xbd130 mov r0, r5
 *   @0xbd134 ldr r1, [pc, #0x4d8]
 *   @0xbd138 mov r6, #3
 *   @0xbd13c add r1, pc, r1
 *   @0xbd140 ldr r3, [r3, #0xc]
 *   @0xbd144 blx r3
 *   @0xbd148 b 0xbb140 <_Z12GLFuncImportb+0xa30>
 *   @0xbd14c ldr r3, [r5]
 *   @0xbd150 mov r0, r5
 *   @0xbd154 ldr r1, [pc, #0x4bc]
 *   @0xbd158 mov r6, #3
 *   @0xbd15c add r1, pc, r1
 *   @0xbd160 ldr r3, [r3, #0xc]
 *   @0xbd164 blx r3
 *   @0xbd168 b 0xbb114 <_Z12GLFuncImportb+0xa04>
 *   @0xbd16c ldr r3, [r5]
 *   @0xbd170 mov r0, r5
 *   @0xbd174 ldr r1, [pc, #0x4a0]
 *   @0xbd178 mov r6, #3
 *   @0xbd17c add r1, pc, r1
 *   @0xbd180 ldr r3, [r3, #0xc]
 *   @0xbd184 blx r3
 *   @0xbd188 b 0xbb0e8 <_Z12GLFuncImportb+0x9d8>
 *   @0xbd18c ldr r3, [r5]
 *   @0xbd190 mov r0, r5
 *   @0xbd194 ldr r1, [pc, #0x484]
 *   @0xbd198 mov r6, #3
 *   @0xbd19c add r1, pc, r1
 *   @0xbd1a0 ldr r3, [r3, #0xc]
 *   @0xbd1a4 blx r3
 *   @0xbd1a8 b 0xbb0bc <_Z12GLFuncImportb+0x9ac>
 *   @0xbd1ac ldr r3, [r5]
 *   @0xbd1b0 mov r0, r5
 *   @0xbd1b4 ldr r1, [pc, #0x468]
 *   @0xbd1b8 mov r6, #3
 *   @0xbd1bc add r1, pc, r1
 *   @0xbd1c0 ldr r3, [r3, #0xc]
 *   @0xbd1c4 blx r3
 *   @0xbd1c8 b 0xbc3b8 <_Z12GLFuncImportb+0x1ca8>
 *   @0xbd1cc ldr r3, [r5]
 *   @0xbd1d0 mov r0, r5
 *   @0xbd1d4 ldr r1, [pc, #0x44c]
 *   @0xbd1d8 mov r6, #3
 *   @0xbd1dc add r1, pc, r1
 *   @0xbd1e0 ldr r3, [r3, #0xc]
 *   @0xbd1e4 blx r3
 *   @0xbd1e8 b 0xbc38c <_Z12GLFuncImportb+0x1c7c>
 *   @0xbd1ec ldr r3, [r5]
 *   @0xbd1f0 mov r0, r5
 *   @0xbd1f4 ldr r1, [pc, #0x430]
 *   @0xbd1f8 mov r6, #3
 *   @0xbd1fc add r1, pc, r1
 *   @0xbd200 ldr r3, [r3, #0xc]
 *   @0xbd204 blx r3
 *   @0xbd208 b 0xbc360 <_Z12GLFuncImportb+0x1c50>
 *   @0xbd20c ldr r3, [r5]
 *   @0xbd210 mov r0, r5
 *   @0xbd214 ldr r1, [pc, #0x414]
 *   @0xbd218 mov r6, #3
 *   @0xbd21c add r1, pc, r1
 *   @0xbd220 ldr r3, [r3, #0xc]
 *   @0xbd224 blx r3
 *   @0xbd228 b 0xbc334 <_Z12GLFuncImportb+0x1c24>
 *   @0xbd22c ldr r3, [r5]
 *   @0xbd230 mov r0, r5
 *   @0xbd234 ldr r1, [pc, #0x3f8]
 *   @0xbd238 mov r6, #3
 *   @0xbd23c add r1, pc, r1
 *   @0xbd240 ldr r3, [r3, #0xc]
 *   @0xbd244 blx r3
 *   @0xbd248 b 0xbc308 <_Z12GLFuncImportb+0x1bf8>
 *   @0xbd24c ldr r3, [r5]
 *   @0xbd250 mov r0, r5
 *   @0xbd254 ldr r1, [pc, #0x3dc]
 *   @0xbd258 mov r6, #3
 *   @0xbd25c add r1, pc, r1
 *   @0xbd260 ldr r3, [r3, #0xc]
 *   @0xbd264 blx r3
 *   @0xbd268 b 0xbc2dc <_Z12GLFuncImportb+0x1bcc>
 *   @0xbd26c ldr r3, [r5]
 *   @0xbd270 mov r0, r5
 *   @0xbd274 ldr r1, [pc, #0x3c0]
 *   @0xbd278 mov r6, #3
 *   @0xbd27c add r1, pc, r1
 *   @0xbd280 ldr r3, [r3, #0xc]
 *   @0xbd284 blx r3
 *   @0xbd288 b 0xbc2b0 <_Z12GLFuncImportb+0x1ba0>
 *   @0xbd28c ldr r3, [r5]
 *   @0xbd290 mov r0, r5
 *   @0xbd294 ldr r1, [pc, #0x3a4]
 *   @0xbd298 mov r6, #3
 *   @0xbd29c add r1, pc, r1
 *   @0xbd2a0 ldr r3, [r3, #0xc]
 *   @0xbd2a4 blx r3
 *   @0xbd2a8 b 0xbc284 <_Z12GLFuncImportb+0x1b74>
 *   @0xbd2ac ldr r3, [r5]
 *   @0xbd2b0 mov r0, r5
 *   @0xbd2b4 ldr r1, [pc, #0x388]
 *   @0xbd2b8 mov r6, #3
 *   @0xbd2bc add r1, pc, r1
 *   @0xbd2c0 ldr r3, [r3, #0xc]
 *   @0xbd2c4 blx r3
 *   @0xbd2c8 b 0xbc258 <_Z12GLFuncImportb+0x1b48>
 *   @0xbd2cc ldr r3, [r5]
 *   @0xbd2d0 mov r0, r5
 *   @0xbd2d4 ldr r1, [pc, #0x36c]
 *   @0xbd2d8 mov r6, #3
 *   @0xbd2dc add r1, pc, r1
 *   @0xbd2e0 ldr r3, [r3, #0xc]
 *   @0xbd2e4 blx r3
 *   @0xbd2e8 b 0xbc22c <_Z12GLFuncImportb+0x1b1c>
 *   @0xbd2ec ldr r3, [r5]
 *   @0xbd2f0 mov r0, r5
 *   @0xbd2f4 ldr r1, [pc, #0x350]
 *   @0xbd2f8 mov r6, #3
 *   @0xbd2fc add r1, pc, r1
 *   @0xbd300 ldr r3, [r3, #0xc]
 *   @0xbd304 blx r3
 *   @0xbd308 b 0xbc200 <_Z12GLFuncImportb+0x1af0>
 *   @0xbd30c ldr r3, [r5]
 *   @0xbd310 mov r0, r5
 *   @0xbd314 ldr r1, [pc, #0x334]
 *   @0xbd318 mov r6, #3
 *   @0xbd31c add r1, pc, r1
 *   @0xbd320 ldr r3, [r3, #0xc]
 *   @0xbd324 blx r3
 *   @0xbd328 b 0xbc1d4 <_Z12GLFuncImportb+0x1ac4>
 *   @0xbd32c ldr r3, [r5]
 *   @0xbd330 mov r0, r5
 *   @0xbd334 ldr r1, [pc, #0x318]
 *   @0xbd338 mov r6, #3
 *   @0xbd33c add r1, pc, r1
 *   @0xbd340 ldr r3, [r3, #0xc]
 *   @0xbd344 blx r3
 *   @0xbd348 b 0xbc1a8 <_Z12GLFuncImportb+0x1a98>
 *   @0xbd34c ldr r3, [r5]
 *   @0xbd350 mov r0, r5
 *   @0xbd354 ldr r1, [pc, #0x2fc]
 *   @0xbd358 mov r6, #3
 *   @0xbd35c add r1, pc, r1
 *   @0xbd360 ldr r3, [r3, #0xc]
 *   @0xbd364 blx r3
 *   @0xbd368 b 0xbc17c <_Z12GLFuncImportb+0x1a6c>
 *   @0xbd36c ldr r3, [r5]
 *   @0xbd370 mov r0, r5
 *   @0xbd374 ldr r1, [pc, #0x2e0]
 *   @0xbd378 mov r6, #3
 *   @0xbd37c add r1, pc, r1
 *   @0xbd380 ldr r3, [r3, #0xc]
 *   @0xbd384 blx r3
 *   @0xbd388 b 0xbc150 <_Z12GLFuncImportb+0x1a40>
 *   @0xbd38c ldr r3, [r5]
 *   @0xbd390 mov r0, r5
 *   @0xbd394 ldr r1, [pc, #0x2c4]
 *   @0xbd398 mov r6, #3
 *   @0xbd39c add r1, pc, r1
 *   @0xbd3a0 ldr r3, [r3, #0xc]
 *   @0xbd3a4 blx r3
 *   @0xbd3a8 b 0xbc124 <_Z12GLFuncImportb+0x1a14>
 *   @0xbd3ac ldr r3, [r5]
 *   @0xbd3b0 mov r0, r5
 *   @0xbd3b4 ldr r1, [pc, #0x2a8]
 *   @0xbd3b8 mov r6, #3
 *   @0xbd3bc add r1, pc, r1
 *   @0xbd3c0 ldr r3, [r3, #0xc]
 *   @0xbd3c4 blx r3
 *   @0xbd3c8 b 0xbc0f8 <_Z12GLFuncImportb+0x19e8>
 *   @0xbd3cc ldr r3, [r5]
 *   @0xbd3d0 mov r0, r5
 *   @0xbd3d4 ldr r1, [pc, #0x28c]
 *   @0xbd3d8 mov r6, #3
 *   @0xbd3dc add r1, pc, r1
 *   @0xbd3e0 ldr r3, [r3, #0xc]
 *   @0xbd3e4 blx r3
 *   @0xbd3e8 b 0xbc0cc <_Z12GLFuncImportb+0x19bc>
 *   @0xbd3ec ldr r3, [r5]
 *   @0xbd3f0 mov r0, r5
 *   @0xbd3f4 ldr r1, [pc, #0x270]
 *   @0xbd3f8 mov r6, #3
 *   @0xbd3fc add r1, pc, r1
 *   @0xbd400 ldr r3, [r3, #0xc]
 *   @0xbd404 blx r3
 *   @0xbd408 b 0xbc0a0 <_Z12GLFuncImportb+0x1990>
 *   @0xbd40c ldr r3, [r5]
 *   @0xbd410 mov r0, r5
 *   @0xbd414 ldr r1, [pc, #0x254]
 *   @0xbd418 mov r6, #3
 *   @0xbd41c add r1, pc, r1
 *   @0xbd420 ldr r3, [r3, #0xc]
 *   @0xbd424 blx r3
 *   @0xbd428 b 0xbc074 <_Z12GLFuncImportb+0x1964>
 *   @0xbd42c ldr r3, [r5]
 *   @0xbd430 mov r0, r5
 *   @0xbd434 ldr r1, [pc, #0x238]
 *   @0xbd438 mov r6, #3
 *   @0xbd43c add r1, pc, r1
 *   @0xbd440 ldr r3, [r3, #0xc]
 *   @0xbd444 blx r3
 *   @0xbd448 b 0xbc048 <_Z12GLFuncImportb+0x1938>
 *   @0xbd44c ldr r3, [r5]
 *   @0xbd450 mov r0, r5
 *   @0xbd454 ldr r1, [pc, #0x21c]
 *   @0xbd458 mov r6, #3
 *   @0xbd45c add r1, pc, r1
 *   @0xbd460 ldr r3, [r3, #0xc]
 *   @0xbd464 blx r3
 *   @0xbd468 b 0xbc01c <_Z12GLFuncImportb+0x190c>
 *   @0xbd46c ldr r3, [r5]
 *   @0xbd470 mov r0, r5
 *   @0xbd474 ldr r1, [pc, #0x200]
 *   @0xbd478 mov r6, #3
 *   @0xbd47c add r1, pc, r1
 *   @0xbd480 ldr r3, [r3, #0xc]
 *   @0xbd484 blx r3
 *   @0xbd488 b 0xbbff0 <_Z12GLFuncImportb+0x18e0>
 *   @0xbd48c ldr r3, [r5]
 *   @0xbd490 mov r0, r5
 *   @0xbd494 ldr r1, [pc, #0x1e4]
 *   @0xbd498 mov r6, #3
 *   @0xbd49c add r1, pc, r1
 *   @0xbd4a0 ldr r3, [r3, #0xc]
 *   @0xbd4a4 blx r3
 *   @0xbd4a8 b 0xbbfc4 <_Z12GLFuncImportb+0x18b4>
 *   @0xbd4ac ldr r3, [r5]
 *   @0xbd4b0 mov r0, r5
 *   @0xbd4b4 ldr r1, [pc, #0x1c8]
 *   @0xbd4b8 mov r6, #3
 *   @0xbd4bc add r1, pc, r1
 *   @0xbd4c0 ldr r3, [r3, #0xc]
 *   @0xbd4c4 blx r3
 *   @0xbd4c8 b 0xbbf98 <_Z12GLFuncImportb+0x1888>
 *   @0xbd4cc ldr r3, [r5]
 *   @0xbd4d0 mov r0, r5
 *   @0xbd4d4 ldr r1, [pc, #0x1ac]
 *   @0xbd4d8 mov r6, #3
 *   @0xbd4dc add r1, pc, r1
 *   @0xbd4e0 ldr r3, [r3, #0xc]
 *   @0xbd4e4 blx r3
 *   @0xbd4e8 b 0xbbf6c <_Z12GLFuncImportb+0x185c>
 *   @0xbd4ec ldr r3, [r5]
 *   @0xbd4f0 mov r0, r5
 *   @0xbd4f4 ldr r1, [pc, #0x190]
 *   @0xbd4f8 mov r6, #3
 *   @0xbd4fc add r1, pc, r1
 *   @0xbd500 ldr r3, [r3, #0xc]
 *   @0xbd504 blx r3
 *   @0xbd508 b 0xbbf40 <_Z12GLFuncImportb+0x1830>
 *   @0xbd50c ldr r3, [r5]
 *   @0xbd510 mov r0, r5
 *   @0xbd514 ldr r1, [pc, #0x174]
 *   @0xbd518 mov r6, #3
 *   @0xbd51c add r1, pc, r1
 *   @0xbd520 ldr r3, [r3, #0xc]
 *   @0xbd524 blx r3
 *   @0xbd528 b 0xbbf14 <_Z12GLFuncImportb+0x1804>
 *   @0xbd52c ldr r3, [r5]
 *   @0xbd530 mov r0, r5
 *   @0xbd534 ldr r1, [pc, #0x158]
 *   @0xbd538 mov r6, #3
 *   @0xbd53c add r1, pc, r1
 *   @0xbd540 ldr r3, [r3, #0xc]
 *   @0xbd544 blx r3
 *   @0xbd548 b 0xbbee8 <_Z12GLFuncImportb+0x17d8>
 *   @0xbd54c ldr r3, [r5]
 *   @0xbd550 mov r0, r5
 *   @0xbd554 ldr r1, [pc, #0x13c]
 *   @0xbd558 mov r6, #3
 *   @0xbd55c add r1, pc, r1
 *   @0xbd560 ldr r3, [r3, #0xc]
 *   @0xbd564 blx r3
 *   @0xbd568 b 0xbbebc <_Z12GLFuncImportb+0x17ac>
 *   @0xbd56c ldr r3, [r5]
 *   @0xbd570 mov r0, r5
 *   @0xbd574 ldr r1, [pc, #0x120]
 *   @0xbd578 mov r6, #3
 *   @0xbd57c add r1, pc, r1
 *   @0xbd580 ldr r3, [r3, #0xc]
 *   @0xbd584 blx r3
 *   @0xbd588 b 0xbbe90 <_Z12GLFuncImportb+0x1780>
 *   @0xbd58c ldr r3, [r5]
 *   @0xbd590 mov r0, r5
 *   @0xbd594 ldr r1, [pc, #0x104]
 *   @0xbd598 mov r6, #3
 *   @0xbd59c add r1, pc, r1
 *   @0xbd5a0 ldr r3, [r3, #0xc]
 *   @0xbd5a4 blx r3
 *   @0xbd5a8 b 0xbbe64 <_Z12GLFuncImportb+0x1754>
 *   @0xbd5ac mov r6, #1
 *   @0xbd5b0 mov r8, #0
 *   @0xbd5b4 b 0xba77c <_Z12GLFuncImportb+0x6c>
 *   @0xbd5b8 eoreq r3, r7, r4, lsl r7
 *   @0xbd5bc .word 0x002736b8
 *   @0xbd5c0 eoreq r3, r7, r4, ror #12
 *   @0xbd5c4 eoreq r3, r7, r0, lsl r6
 *   @0xbd5c8 eoreq r3, r7, r12, lsr #11
 *   @0xbd5cc eoreq r3, r7, r12, asr #10
 *   @0xbd5d0 .word 0x002734f4
 *   @0xbd5d4 mlaeq r7, r8, r4, r3
 *   @0xbd5d8 eoreq r3, r7, r12, lsr r4
 *   @0xbd5dc eoreq r3, r7, r4, ror #7
 *   @0xbd5e0 mlaeq r7, r0, r3, r3
 *   @0xbd5e4 eoreq r3, r7, r12, lsr r3
 *   @0xbd5e8 eoreq r3, r7, r8, ror #5
 *   @0xbd5ec mlaeq r7, r4, r2, r3
 *   @0xbd5f0 eoreq r3, r7, r0, asr #4
 *   @0xbd5f4 eoreq r3, r7, r12, ror #3
 *   @0xbd5f8 mlaeq r7, r8, r1, r3
 *   @0xbd5fc eoreq r3, r7, r12, lsr r1
 *   @0xbd600 .word 0x002730dc
 *   @0xbd604 eoreq r3, r7, r0, lsl #1
 *   @0xbd608 eoreq r3, r7, r8, lsr #32
 *   @0xbd60c .word 0x00272fd4
 *   @0xbd610 eoreq r2, r7, r0, lsl #31
 *   @0xbd614 eoreq r2, r7, r12, lsr #30
 *   @0xbd618 .word 0x00272ed4
 *   @0xbd61c eoreq r2, r7, r12, ror lr
 *   @0xbd620 eoreq r2, r7, r8, lsr #28
 *   @0xbd624 eoreq r2, r7, r8, lsl r8
 *   @0xbd628 .word 0x002727d0
 *   @0xbd62c eoreq r2, r7, r4, lsl #15
 *   @0xbd630 eoreq r2, r7, r4, lsr r7
 *   @0xbd634 eoreq r2, r7, r0, ror #13
 *   @0xbd638 eoreq r2, r7, r0, lsl #13
 *   @0xbd63c eoreq r2, r7, r8, lsl r6
 *   @0xbd640 .word 0x002725b0
 *   @0xbd644 eoreq r2, r7, r8, asr #10
 *   @0xbd648 eoreq r2, r7, r4, ror #9
 *   @0xbd64c eoreq r2, r7, r8, lsl #9
 *   @0xbd650 eoreq r2, r7, r4, lsr r4
 *   @0xbd654 eoreq r2, r7, r0, ror #7
 *   @0xbd658 eoreq r2, r7, r12, lsl #7
 *   @0xbd65c eoreq r2, r7, r12, lsr r3
 *   @0xbd660 .word 0x002722f0
 *   @0xbd664 eoreq r2, r7, r0, lsr #5
 *   @0xbd668 eoreq r2, r7, r0, asr r2
 *   @0xbd66c eoreq r2, r7, r0, lsl #4
 *   @0xbd670 eoreq r2, r7, r12, lsr #3
 *   @0xbd674 eoreq r2, r7, r8, asr r1
 *   @0xbd678 eoreq r2, r7, r4, lsl #2
 *   @0xbd67c strhteq r2, [r7], -r4
 *   @0xbd680 eoreq r2, r7, r4, rrx
 *   @0xbd684 eoreq r2, r7, r4, lsl r0
 *   @0xbd688 eoreq r1, r7, r8, asr #31
 *   @0xbd68c eoreq r1, r7, r4, ror pc
 *   @0xbd690 eoreq r1, r7, r4, lsl pc
 *   @0xbd694 .word 0x00271eb8
 *   @0xbd698 eoreq r1, r7, r8, ror #28
 *   @0xbd69c eoreq r1, r7, r8, lsl lr
 *   @0xbd6a0 eoreq r1, r7, r8, asr #27
 *
 * ══ §2/5 anon_30ba26  0x30ba26  size 9448  2362 条（0x30ba26..0x30df0e）
 * @func 0x30ba26 0x30df0e  size 9448  2362 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfed0abd2 / JS_Argument_Put(YYObjectBase*, RValue*, char const*)+0xe4 / 0xffec9acc / 0xff9c9af4 / 0xff4c9b1c / 0xfee49b50 / 0xfe9c9b74 / 0x40a4c2
 * 字段偏移 top8: 0x6×5 / 0x18×3 / 0xc×2 / 0x4×2 / 0x17×1 / 0xb0a×1 / 0x5×1 / 0x1×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30ba26 push {r0, r3, r5, r6, r9, sp, lr}
 *   @0x30ba2a .word 0x460447f0
 *   @0x30ba2e .word 0xf0002800
 *   @0x30ba32 .word 0xf50080be
 *   @0x30ba36 stmdavs r1!, {r3, r7, r9, r10, sp}
 *   @0x30ba3a .word 0xf8d62700
 *   @0x30ba3e strtmi r5, [r8], -r8, lsl #1
 *   @0x30ba42 ldc2l p7, c15, [r8], #-876
 *   @0x30ba46 .word 0x0080f8d4
 *   @0x30ba4a .word 0xb1486027
 *   @0x30ba4e .word 0xf7db4629
 *   @0x30ba52 strtmi pc, [r8], -r9, lsr #25
 *   @0x30ba56 .word 0x1080f8d4
 *   @0x30ba5a stc2l p7, c15, [r12], #-876
 *   @0x30ba5e addvc pc, r0, r4, asr #17
 *   @0x30ba62 strtmi r2, [r8], -r0, lsl #14
 *   @0x30ba66 ldrtmi r6, [r9], r1, ror #26
 *   @0x30ba6a stc2l p7, c15, [r4], #-876
 *   @0x30ba6e stcvs p5, c6, [r3], #412
 *   @0x30ba72 andsle r4, r0, #-268435447
 *   @0x30ba76 b 0x16e6f0a <b2_toiTime+0xf8da66>
 *   @0x30ba7a strbmi r1, [r3], #-2055
 *   @0x30ba7e bhs 0x365bee <_ZTS12CDS_Priority+0x7c46>
 *   @0x30ba82 ldmvs r9, {r0, r1, r2, r8, r12, lr, pc} ^
 *   @0x30ba86 .word 0xf7db4628
 *   @0x30ba8a stcvs p12, c15, [r3, #-340]!
 *   @0x30ba8e .word 0xf8c34443
 *   @0x30ba92 strlo r9, [r1, -r12]
 *   @0x30ba96 strtmi lr, [r8], -r11, ror #15
 *   @0x30ba9a .word 0xf7db6d21
 *   @0x30ba9e blvs 0xfed0abd2 <b2_toiTime+0xfffffffffe5b172e>
 *   @0x30baa2 strvs r2, [r3, #-0x300]!
 *   @0x30baa6 .word 0x46994698
 *   @0x30baaa strlo r6, [r4, -r3, ror #22]!
 *   @0x30baae andsle r4, r0, #152, #10
 *   @0x30bab2 .word 0xf8574628
 *   @0x30bab6 .word 0xf7db1c24
 *   @0x30baba .word 0xf847fc3d
 *   @0x30babe strtmi r9, [r8], -r4, lsr #24
 *   @0x30bac2 .word 0x1c0cf857
 *   @0x30bac6 ldc2 p7, c15, [r6], #-876
 *   @0x30baca stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x30bace .word 0x9c0cf847
 *   @0x30bad2 stclvs p7, c14, [r7], #-936
 *   @0x30bad6 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30bada stcvs p6, c4, [r3], #-808
 *   @0x30bade strtmi r3, [r8], -r4, lsr #14
 *   @0x30bae2 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30bae6 andle r4, pc, #641728512
 *   @0x30baea stcne p8, c15, [r4], #-348
 *   @0x30baee stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30baf2 stc2 p7, c15, [r0], #-876
 *   @0x30baf6 stcge p8, c15, [r4], #-284
 *   @0x30bafa .word 0xf8574628
 *   @0x30bafe .word 0xf7db1c0c
 *   @0x30bb02 .word 0xf847fc19
 *   @0x30bb06 strb r10, [r8, r12, lsl #24]!
 *   @0x30bb0a strbmi r6, [r2], r1, lsr #23
 *   @0x30bb0e .word 0xfc12f7db
 *   @0x30bb12 eorshi pc, r8, r4, asr #17
 *   @0x30bb16 stclvs p6, c4, [r1], #-160
 *   @0x30bb1a .word 0xfc0cf7db
 *   @0x30bb1e .word 0xf8c46ea7
 *   @0x30bb22 svcvs #0x238044
 *   @0x30bb26 strtmi r3, [r8], -r4, lsr #14
 *   @0x30bb2a stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30bb2e andle r4, pc, #152, #10
 *   @0x30bb32 stcne p8, c15, [r4], #-348
 *   @0x30bb36 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x30bb3a blx 0x249ab0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xe4>
 *   @0x30bb3e stcge p8, c15, [r4], #-284
 *   @0x30bb42 .word 0xf8574628
 *   @0x30bb46 .word 0xf7db1c0c
 *   @0x30bb4a .word 0xf847fbf5
 *   @0x30bb4e strb r10, [r8, r12, lsl #24]!
 *   @0x30bb52 strbmi r6, [pc], -r1, lsr #29
 *   @0x30bb56 blx 0xffec9acc <b2_toiTime+0xffffffffff770628>
 *   @0x30bb5a rsbls pc, r8, r4, asr #17
 *   @0x30bb5e addseq pc, r4, r6, lsl #2
 *   @0x30bb62 .word 0xf7db4629
 *   @0x30bb66 .word 0xf8d6fc1f
 *   @0x30bb6a strbmi r4, [r8], r12, lsl #1
 *   @0x30bb6e .word 0xf8d63410
 *   @0x30bb72 qadd8mi r3, r8, r0
 *   @0x30bb76 andsle r4, r3, #-268435447
 *   @0x30bb7a .word 0x1c10f854
 *   @0x30bb7e blx 0xff9c9af4 <b2_toiTime+0xffffffffff270650>
 *   @0x30bb82 .word 0x3c0cf854
 *   @0x30bb86 .word 0x8c10f844
 *   @0x30bb8a .word 0xd1062b01
 *   @0x30bb8e .word 0xf8544628
 *   @0x30bb92 .word 0xf7db1c04
 *   @0x30bb96 .word 0xf844fbcf
 *   @0x30bb9a strlo r8, [r1, -r4, lsl #24]
 *   @0x30bb9e .word 0xe7e63410
 *   @0x30bba2 .word 0x108cf8d6
 *   @0x30bba6 blx 0xff4c9b1c <b2_toiTime+0xfffffffffed70678>
 *   @0x30bbaa .word 0xf8c62300
 *   @0x30bbae pop {r2, r3, r7, r12, sp}
 *   @0x30bbb2 ldrblt r8, [r0, #-0x7f0]!
 *   @0x30bbb6 orrlt r4, r0, #4, #12
 *   @0x30bbba strhs r6, [r0, #-0xe46]
 *   @0x30bbbe .word 0x008cf8d0
 *   @0x30bbc2 .word 0xff31f7ff
 *   @0x30bbc6 ldrsbne pc, [r0], r4
 *   @0x30bbca .word 0xf7db4630
 *   @0x30bbce .word 0x4630fbb3
 *   @0x30bbd2 .word 0x1084f8d4
 *   @0x30bbd6 addspl pc, r0, r4, asr #17
 *   @0x30bbda blx 0xfee49b50 <b2_toiTime+0xfffffffffe6f06ac>
 *   @0x30bbde .word 0xf8d44630
 *   @0x30bbe2 .word 0xf8c41088
 *   @0x30bbe6 .word 0xf7db5084
 *   @0x30bbea ldrtmi pc, [r0], -r5, lsr #23
 *   @0x30bbee .word 0xf8c46961
 *   @0x30bbf2 .word 0xf7db5088
 *   @0x30bbf6 shadd8mi pc, r0, pc
 *   @0x30bbfa smultbvs r5, r1, r9
 *   @0x30bbfe blx 0xfe9c9b74 <b2_toiTime+0xfffffffffe2706d0>
 *   @0x30bc02 bvs 0xb5d4ca <b2_toiTime+0x404026>
 *   @0x30bc06 .word 0xf7db61a5
 *   @0x30bc0a eorvs pc, r5, #152576
 *   @0x30bc0e .word 0xf8d44630
 *   @0x30bc12 .word 0xf7db108c
 *   @0x30bc16 .word 0xf8c4fb8f
 *   @0x30bc1a ldcllt p0, c5, [r0, #-560]!
 *   @0x30bc1e addlt r11, r5, r0, lsr r5
 *   @0x30bc22 movwhs r6, #0x842
 *   @0x30bc26 movwls r4, #0x3604
 *   @0x30bc2a ldmdble r12, {r0, r4, r7, r9, lr}
 *   @0x30bc2e strbmi pc, [r0, #-0x6f]!
 *   @0x30bc32 .word 0xf10242aa
 *   @0x30bc36 stmvs r0, {r0, r2, r8, r9} ^
 *   @0x30bc3a cmpeq r2, #3072
 *   @0x30bc3e movths sp, #0x102
 *   @0x30bc42 ands r9, r0, r3, lsl #6
 *   @0x30bc46 movwle r4, #0x2293
 *   @0x30bc4a svclt #0x3842ab
 *   @0x30bc4e stmdavs r3!, {r0, r2, r3, r4, r9, r10, lr}
 *   @0x30bc52 movwls r2, #0x104
 *   @0x30bc56 movwls r10, #0x1b03
 *   @0x30bc5a .word 0xf7dc462b
 *   @0x30bc5e blls 0x40a4c2 <g_RomDisk+0x12ca2>
 *   @0x30bc62 stmdblt r3, {r5, sp, lr}
 *   @0x30bc66 stmdals r3, {r0, r2, r5, r6, sp, lr}
 *   @0x30bc6a ldclt p0, c11, [r0, #-20]!
 *   @0x30bc6e .word 0x4604b510
 *   @0x30bc72 cmplt r0, r0, asr #17
 *   @0x30bc76 .word 0xf7db6821
 *   @0x30bc7a qaddhs pc, sp, r0
 *   @0x30bc7e eorvs r4, r1, r0, lsr #12
 *   @0x30bc82 pop {r4, r9, sp}
 *   @0x30bc86 .word 0xf00f4010
 *   @0x30bc8a ldclt p15, c11, [r0, #-128]
 *   @0x30bc8e .word 0x4604b5f0
 *   @0x30bc92 ldrmi r11, [r5], -r5, lsl #1
 *   @0x30bc96 orrhs pc, r8, #0, #10
 *   @0x30bc9a stcvs p14, c10, [r2, #16]!
 *   @0x30bc9e stclvs p6, c4, [r1, #-60]!
 *   @0x30bca2 .word 0x0088f8d3
 *   @0x30bca6 .word 0xf8462300
 *   @0x30bcaa mrrcne p13, #0x0, r3, r3, c4
 *   @0x30bcae subeq lr, r2, sp, lsl #17
 *   @0x30bcb2 .word 0x2101442b
 *   @0x30bcb6 .word 0xf9eaf7dc
 *   @0x30bcba strbvs r9, [r0, #-0xb03]!
 *   @0x30bcbe stcvs p9, c11, [r3, #396]!
 *   @0x30bcc2 ldrtmi r4, [r9], -r10, lsr #12
 *   @0x30bcc6 ldrmi r4, [r8], -r3, lsl #8
 *   @0x30bcca ldcl p5, c15, [r8], #-680
 *   @0x30bcce strbpl r2, [r2, #-0x20a]
 *   @0x30bcd2 movwlo r6, #0x1da3
 *   @0x30bcd6 strvs r4, [r5, #0x41d]!
 *   @0x30bcda andlt r9, r5, r3, lsl #16
 *   @0x30bcde stmdami r1, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x30bce2 .word 0xf7d94478
 *   @0x30bce6 ldmdb r2!, {r0, r2, r4, r5, r8, r9, r11, r12, sp, pc}
 *   @0x30bcea ldrblt r0, [r0, #-0xd]!
 *   @0x30bcee stmdavc r3, {r6, r7, r8, r12, sp, pc}
 *   @0x30bcf2 bmi 0x5f83a6 <g_SWFaavertbuff+0x252de>
 *   @0x30bcf6 strhs r1, [r10], -r1, asr #28
 *   @0x30bcfa ldrbtmi r2, [r10], #-0
 *   @0x30bcfe svclo #0x1f811
 *   @0x30bd02 ldrbeq lr, [r3], #2818
 *   @0x30bd06 umullpl pc, r0, r4, r8
 *   @0x30bd0a streq pc, [r7], #-3
 *   @0x30bd0e vst1.16 {d15, d16}, [r4], r5
 *   @0x30bd12 strle r0, [r3, #-0x7e4]
 *   @0x30bd16 blx 0x4a306c <SrcVerts+0xb0>
 *   @0x30bd1a strb r3, [pc, r0]!
 *   @0x30bd1e ssub16mi r11, r8, r0
 *   @0x30bd22 bvc 0x173b2ea <b2_toiTime+0xfe1e46>
 *   @0x30bd26 ldrblt r0, [r0, #-0x9]!
 *   @0x30bd2a stmdavc r3, {r3, r6, r7, r8, r12, sp, pc}
 *   @0x30bd2e bmi 0x638402 <g_SWFaavertbuff+0x6533a>
 *   @0x30bd32 strhs r1, [r10], -r1, asr #28
 *   @0x30bd36 ldrbtmi r2, [r10], #-0
 *   @0x30bd3a svclo #0x1f811
 *   @0x30bd3e ldrbeq lr, [r3], #2818
 *   @0x30bd42 umullpl pc, r0, r4, r8
 *   @0x30bd46 streq pc, [r7], #-3
 *   @0x30bd4a vst1.16 {d15, d16}, [r4], r5
 *   @0x30bd4e strle r0, [r4, #-0x7e4]
 *   @0x30bd52 blx 0x4a30a8 <SrcVerts+0xec>
 *   @0x30bd56 addlt r3, r0, #0
 *   @0x30bd5a ldcllt p7, c14, [r0, #-952]!
 *   @0x30bd5e ldcllt p6, c4, [r0, #-96]!
 *   @0x30bd62 bvc 0x83b96a <b2_toiTime+0xe24c6>
 *   @0x30bd66 push {r0, r3}
 *   @0x30bd6a ssub8mi r4, r6, r0
 *   @0x30bd6e ldrmi r4, [pc], -r5, ror #20
 *   @0x30bd72 strmi r11, [r4], -sp, lsl #1
 *   @0x30bd76 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x30bd7a andls r4, r1, #13631488
 *   @0x30bd7e movwls r6, #0xb813
 *   @0x30bd82 addvs r2, r3, r0, lsl #6
 *   @0x30bd86 .word 0xb1636843
 *   @0x30bd8a bmi 0x1aa5d9e <b2_toiTime+0x134c8fa>
 *   @0x30bd8e adclo r4, r0, #2046820352
 *   @0x30bd92 stmdavs r3, {r1, r3, r4, sp, lr}
 *   @0x30bd96 stmdavs r3, {r1, r3, r4, r6, sp, lr}
 *   @0x30bd9a stmdavs r3, {r1, r3, r4, r7, sp, lr}
 *   @0x30bd9e stmdavs r3, {r1, r3, r4, r6, r7, sp, lr}
 *   @0x30bda2 svchs #0x611a
 *   @0x30bda6 addshi pc, pc, r0
 *   @0x30bdaa stmdahs r0, {r4, r5, r11, r12, sp, lr}
 *   @0x30bdae addshi pc, lr, r0
 *   @0x30bdb2 .word 0xf0002d00
 *   @0x30bdb6 stmdavc r11!, {r1, r3, r4, r7, pc}
 *   @0x30bdba .word 0xf0002b00
 *   @0x30bdbe swphs r8, r6, [r0]
 *   @0x30bdc2 eorhs r10, r0, #196608
 *   @0x30bdc6 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30bdca bl 0xfffc947a <b2_toiTime+0xffffffffff86ffd6>
 *   @0x30bdce andhs r4, r1, r9, lsr #12
 *   @0x30bdd2 blhs 0x389e1e <bigtens_D2A+0x2ee>
 *   @0x30bdd6 bhs 0xdf8466 <b2_toiTime+0x69efc2>
 *   @0x30bdda stmdavc r11, {r0, r8, r12, lr, pc}
 *   @0x30bdde stcge p1, c11, [r12, #-396]
 *   @0x30bde2 bicseq lr, r2, #5120
 *   @0x30bde6 andeq pc, r7, #2
 *   @0x30bdea vpmax.s8 d15, d2, d0
 *   @0x30bdee stcpl p8, c15, [r4], #-76
 *   @0x30bdf2 .word 0xf803432a
 *   @0x30bdf6 and r2, r1, r4, lsr #24
 *   @0x30bdfa stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30bdfe mvnle r2, r0, lsl #18
 *   @0x30be02 .word 0xb108f8df
 *   @0x30be06 beq 0x506a26 <SrcVerts+0x63a6a>
 *   @0x30be0a ldrbtmi r2, [r11], #1792
 *   @0x30be0e ldrbmi r4, [r6, #-0x6b8]
 *   @0x30be12 stmvs r1!, {r0, r2, r8, r9, r12, lr, pc}
 *   @0x30be16 ldrtmi r6, [r9], #-2147
 *   @0x30be1a cmple r4, #-1879048183
 *   @0x30be1e ldmdavc r2!, {r1, r2, r3, r6, sp, lr, pc}
 *   @0x30be22 rscsle r2, r6, r0, lsl #20
 *   @0x30be26 stmdavc r10, {r0, r4, r5, r9, r10, lr}
 *   @0x30be2a .word 0x3101460d
 *   @0x30be2e stmvs r1!, {r1, r3, r5, r8, r11, r12, sp, pc}
 *   @0x30be32 stmdavs r2!, {r0, r1, r2, r3, r5, r9, r10, lr} ^
 *   @0x30be36 .word 0xd1124291
 *   @0x30be3a blge 0x643e6e <g_SWFaavertbuff+0x70da6>
 *   @0x30be3e sbcseq lr, r2, r3, lsl #22
 *   @0x30be42 andeq pc, r7, #2
 *   @0x30be46 stceq p8, c15, [r4], #-64
 *   @0x30be4a .word 0xf202fa40
 *   @0x30be4e strble r0, [r10, #0x7d2]!
 *   @0x30be52 strtmi lr, [r0], -sp, ror #15
 *   @0x30be56 .word 0xf7ff3101
 *   @0x30be5a stmdahs r0, {r0, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30be5e stmvs r2!, {r1, r2, r6, r8, r12, lr, pc}
 *   @0x30be62 stmdavs r1!, {r0, r2, r4, r5, r7, r9, lr}
 *   @0x30be66 andeq pc, r1, r2, lsl #2
 *   @0x30be6a stmdale r1, {r5, r7, sp, lr}
 *   @0x30be6e strteq pc, [r0], r11, lsl #2
 *   @0x30be72 eorvs pc, r2, r1, asr #16
 *   @0x30be76 svceq #0xf1b9
 *   @0x30be7a qadd16mi sp, r10, r2
 *   @0x30be7e .word 0xf8124615
 *   @0x30be82 orrslt r1, r1, r1, lsl #22
 *   @0x30be86 bl 0x3f6abe <g_MP3UpdateVolume+0x17e2>
 *   @0x30be8a .word 0xf00100d1
 *   @0x30be8e .word 0xf8100107
 *   @0x30be92 blx 0x130ef2a <b2_toiTime+0xbb5a86>
 *   @0x30be96 strbeq pc, [r11, r1, lsl #2]
 *   @0x30be9a .word 0xf802d507
 *   @0x30be9e strb r8, [sp, r1, lsl #24]!
 *   @0x30bea2 teqlt r2, r10, lsr #16
 *   @0x30bea6 .word 0xf8873501
 *   @0x30beaa adcsmi r9, sp, #0
 *   @0x30beae stmdavc r10!, {r0, r8, r11, r12, lr, pc}
 *   @0x30beb2 strhs r11, [r0, -r10, lsl #2]
 *   @0x30beb6 strhs lr, [r1, -r0]
 *   @0x30beba str r4, [r8, lr, lsr #12]!
 *   @0x30bebe .word 0x31014620
 *   @0x30bec2 mcr2 p7, #0x5, pc, c12, c15, #0x7
 *   @0x30bec6 swpblt r11, r0, [r7]
 *   @0x30beca stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x30bece adcvs r1, r1, r9, asr r12
 *   @0x30bed2 ldrbtmi r4, [r9], #-2319
 *   @0x30bed6 .word 0xf84231a0
 *   @0x30beda stmvs r2!, {r0, r1, r5, r12}
 *   @0x30bede stmdavs r3!, {sp}
 *   @0x30bee2 eoreq pc, r2, r3, asr #16
 *   @0x30bee6 ldrtmi lr, [r8], -r2
 *   @0x30beea andhs lr, r6, r0
 *   @0x30beee bls 0x5f32fa <g_SWFaavertbuff+0x20232>
 *   @0x30bef2 addsmi r6, r10, #2818048
 *   @0x30bef6 .word 0xf5aad001
 *   @0x30befa andlt lr, sp, r12, ror #22
 *   @0x30befe svchi #0xf0e8bd
 *   @0x30bf02 blne 0xffabbb0a <b2_toiTime+0xffffffffff362666>
 *   @0x30bf06 ldmibvc lr!, {r1, r2, r3}
 *   @0x30bf0a stmdbvc r0, {r0, r3} ^
 *   @0x30bf0e ldmdavc r8!, {r0, r3} ^
 *   @0x30bf12 ldrlt r0, [r0, #-0x9]
 *   @0x30bf16 cmnlt r8, r4, lsl #12
 *   @0x30bf1a cmnlt r8, r0, lsl #25
 *   @0x30bf1e stmdavc r8, {r0, r3, r5, r6, r8, r12, sp, pc}
 *   @0x30bf22 strmi r11, [r8], -r0, ror #2
 *   @0x30bf26 .word 0x1080f8d4
 *   @0x30bf2a blx 0x449e96 <g_RomDisk+0x52676>
 *   @0x30bf2e stmdavs r0, {r4, r5, r8, r12, sp, pc}
 *   @0x30bf32 bl 0x3e73c6 <error_g0017+0x4006a>
 *   @0x30bf36 ldclt p0, c1, [r0, #-0]
 *   @0x30bf3a .word 0x4608bd10
 *   @0x30bf3e ldrlt r11, [r0, #-0xd10]
 *   @0x30bf42 .word 0xf8d04614
 *   @0x30bf46 .word 0xf7ff008c
 *   @0x30bf4a cmplt r8, r4, ror #31
 *   @0x30bf4e blhs 0x3a6062 <_ZTSPKDn+0x89a>
 *   @0x30bf52 blhs 0x3fff66 <g_RomDisk+0x8746>
 *   @0x30bf56 blhs 0x37ff62 <_ZTS13C_UTF16String+0x1700e>
 *   @0x30bf5a eorvs sp, r3, r4, lsl #2
 *   @0x30bf5e andhs r6, r0, r3, asr #17
 *   @0x30bf62 ldclt p0, c6, [r0, #-396]
 *   @0x30bf66 ldclt p0, c2, [r0, #-24]
 *   @0x30bf6a .word 0xe92d0000
 *   @0x30bf6e ldrshlt r4, [pc], r0
 *   @0x30bf72 .word 0x2100460d
 *   @0x30bf76 andls r9, pc, #13
 *   @0x30bf7a .word 0xf8d59110
 *   @0x30bf7e .word 0xf7da8064
 *   @0x30bf82 .word 0x4606fc91
 *   @0x30bf86 stmdahs r0, {r4, r12, pc}
 *   @0x30bf8a orrhi pc, r9, #64
 *   @0x30bf8e andsls r10, r4, lr, lsl pc
 *   @0x30bf92 .word 0xf04f499c
 *   @0x30bf96 .word 0xf8470901
 *   @0x30bf9a .word 0x46400d34
 *   @0x30bf9e movwhs r4, #0x863a
 *   @0x30bfa2 .word 0xf8cd9707
 *   @0x30bfa6 .word 0xf8cd9048
 *   @0x30bfaa tstls r5, #76
 *   @0x30bfae rfeia r10!
 *   @0x30bfb2 .word 0x46049f11
 *   @0x30bfb6 .word 0xf0402f00
 *   @0x30bfba stmdbls sp, {r0, r8, pc}
 *   @0x30bfbe subvs r10, r3, #18432
 *   @0x30bfc2 .word 0x73fff647
 *   @0x30bfc6 .word 0xf5008183
 *   @0x30bfca stmdavs r11, {r3, r12, sp} ^
 *   @0x30bfce strteq pc, [r8], -r0, lsl #2
 *   @0x30bfd2 eorshi pc, r8, r0, asr #17
 *   @0x30bfd6 andshs r4, r0, #59768832
 *   @0x30bfda ldrtmi r6, [r0], -r3, asr #7
 *   @0x30bfde b 0xffd4968e <b2_toiTime+0xffffffffff5f01ea>
 *   @0x30bfe2 .word 0xf8c69a0d
 *   @0x30bfe6 blge 0xaac01e <b2_toiTime+0x352b7a>
 *   @0x30bfea ldmibvs r2, {r0, r3, r6, r9, r10, lr} ^
 *   @0x30bfee ldcvc p8, c15, [r0, #-268]
 *   @0x30bff2 andls r9, r11, #0, #14
 *   @0x30bff6 movwls r4, #0x9610
 *   @0x30bffa movwls r4, #0x163a
 *   @0x30bffe orrvs pc, r0, #1325400064
 *   @0x30c002 .word 0xf844f7dc
 *   @0x30c006 .word 0x46069b1a
 *   @0x30c00a .word 0xd1482b00
 *   @0x30c00e bmi 0x2277c8e <b2_toiTime+0x1b1e7ea>
 *   @0x30c012 .word 0x469a469c
 *   @0x30c016 movwls r4, #0xc47a
 *   @0x30c01a stchs p8, c15, [r0, #-284]!
 *   @0x30c01e blvc 0xfe349162 <b2_toiTime+0xfffffffffdbefcbe>
 *   @0x30c022 ldrmi r9, [pc], -r10, lsl #14
 *   @0x30c026 strbmi r7, [r11], -r3
 *   @0x30c02a orrvs pc, r0, pc, asr #8
 *   @0x30c02e eorls pc, r0, sp, asr #17
 *   @0x30c032 .word 0xb1639105
 *   @0x30c036 bl 0x4b2c52 <SrcVerts+0xfc96>
 *   @0x30c03a stmdals sp, {r1, r3, r8}
 *   @0x30c03e andeq lr, r3, #206848
 *   @0x30c042 stc2 p7, c15, [sp], #872
 *   @0x30c046 ldrbmi r4, [r4], #1668
 *   @0x30c04a beq 0x34818e
 *   @0x30c04e strbmi r9, [r7, #-0xc]!
 *   @0x30c052 .word 0x5df3da02
 *   @0x30c056 andle r4, r1, r11, asr r5
 *   @0x30c05a ldrh r4, [r1], -r9
 *   @0x30c05e vst1.8 {d19}, [pc], r1
 *   @0x30c062 ldrb r7, [r4, r0, lsl #23]!
 *   @0x30c066 andhs pc, r9, r6, lsl r8
 *   @0x30c06a .word 0x0109eb06
 *   @0x30c06e bhs 0x5b04ae <g_SWFlineaavertbuff+0x5d3e6>
 *   @0x30c072 .word 0xf0009206
 *   @0x30c076 bhs 0x66ccea <g_SWFlinevertbuff+0x19c22>
 *   @0x30c07a tsthi r8, #0
 *   @0x30c07e stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30c082 blle 0xffedd80e <b2_toiTime+0xffffffffff78436a>
 *   @0x30c086 cmplt r3, r12, lsl #22
 *   @0x30c08a .word 0xf0402f00
 *   @0x30c08e blls 0x46cef6 <g_RomDisk+0x756d6>
 *   @0x30c092 mvnsvc pc, pc, asr #12
 *   @0x30c096 vhsub.s8 d20, d16, d11
 *   @0x30c09a movwhs r8, #0x637e
 *   @0x30c09e stmdals r11, {r1, r3, r4, r8, r9, r12, pc}
 *   @0x30c0a2 .word 0xf7db4631
 *   @0x30c0a6 blls 0x9ca5ca <b2_toiTime+0x271126>
 *   @0x30c0aa blhs 0x330cf6
 *   @0x30c0ae addshi pc, lr, r0, asr #32
 *   @0x30c0b2 blhs 0x326946
 *   @0x30c0b6 ldmibvs r10, {r0, r2, r3, r4, r6, r12, lr, pc} ^
 *   @0x30c0ba svclt #0x1c2a08
 *   @0x30c0be ldrhi r8, [r10], #-2202
 *   @0x30c0c2 blvs 0x19a6956 <b2_toiTime+0x124d4b2>
 *   @0x30c0c6 ldrmi r6, [r1], #-3097
 *   @0x30c0ca addmi r6, r10, #6422528
 *   @0x30c0ce .word 0xf503d004
 *   @0x30c0d2 andhs r2, r1, #136, #6
 *   @0x30c0d6 addhs pc, r4, r3, lsr #17
 *   @0x30c0da ldmdavs r11, {r0, r1, r5, r6, r9, r11, sp, lr}
 *   @0x30c0de suble r2, r8, r0, lsl #22
 *   @0x30c0e2 blvs 0x19a6976 <b2_toiTime+0x124d4d2>
 *   @0x30c0e6 .word 0x6c1ab912
 *   @0x30c0ea suble r2, r2, r0, lsl #20
 *   @0x30c0ee stmibhi r2!, {r0, r5, r9, r11, pc}
 *   @0x30c0f2 andslt r11, r0, #-536870912
 *   @0x30c0f6 ldmhi r8, {r1, r2, r4, r5, r9, r11, r12}
 *   @0x30c0fa andle r4, r7, r6, lsl #5
 *   @0x30c0fe addshi r1, r10, r10, lsl #21
 *   @0x30c102 andhs r6, r1, #143360
 *   @0x30c106 orrhs pc, r8, #12582912
 *   @0x30c10a addhs pc, r4, r3, lsr #17
 *   @0x30c10e stmibhi r2!, {r0, r1, r5, r9, r11, sp, lr}
 *   @0x30c112 addmi r8, r10, #409600
 *   @0x30c116 tsthi r10, r6
 *   @0x30c11a bvs 0xbd4926 <b2_toiTime+0x47b482>
 *   @0x30c11e orrhs pc, r8, #12582912
 *   @0x30c122 addhs pc, r4, r3, lsr #17
 *   @0x30c126 bhi 0x1ba69ba <b2_toiTime+0x144d516>
 *   @0x30c12a addmi r8, r10, #2506752
 *   @0x30c12e orrshi sp, r10, r6
 *   @0x30c132 bvs 0xbd493e <b2_toiTime+0x47b49a>
 *   @0x30c136 orrhs pc, r8, #12582912
 *   @0x30c13a addhs pc, r4, r3, lsr #17
 *   @0x30c13e bhi 0xfeba69d2 <b2_toiTime+0xfffffffffe44d52e>
 *   @0x30c142 addmi r8, r10, #3555328
 *   @0x30c146 bicshi sp, r10, r10
 *   @0x30c14a bhi 0xfeba69de <b2_toiTime+0xfffffffffe44d53a>
 *   @0x30c14e cmphi r10, r2, asr r2
 *   @0x30c152 andhs r6, r1, #143360
 *   @0x30c156 orrhs pc, r8, #12582912
 *   @0x30c15a addhs pc, r4, r3, lsr #17
 *   @0x30c15e bvs 0xbeebea <b2_toiTime+0x495746>
 *   @0x30c162 andlt r8, lr, #401408
 *   @0x30c166 blx 0x4ae4ce <SrcVerts+0xb512>
 *   @0x30c16a addmi pc, r6, #136314880
 *   @0x30c16e ldmdane r2, {r2, r3, r4, r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x30c172 stmdavs r3!, {r1, r3, r4, r6, r7, pc}
 *   @0x30c176 strle r0, [r5, #-0x7de]
 *   @0x30c17a svclt #0x540698
 *   @0x30c17e .word 0x23ba23b9
 *   @0x30c182 eors r9, r3, r1, lsl r3
 *   @0x30c186 .word 0xb1ae6a26
 *   @0x30c18a orrhs pc, r8, #25165824
 *   @0x30c18e .word 0xf8d36db2
 *   @0x30c192 orrlt r0, r10, r8, lsl #1
 *   @0x30c196 .word 0x21016d73
 *   @0x30c19a movwls r9, #0xf07
 *   @0x30c19e smlsdls r1, r3, r8, r1
 *   @0x30c1a2 .word 0xff74f7db
 *   @0x30c1a6 blls 0x76576e <b2_toiTime+0xc2ca>
 *   @0x30c1aa bvs 0xbbadbe <b2_toiTime+0x46191a>
 *   @0x30c1ae ldcvs p13, c6, [r2, #324]
 *   @0x30c1b2 and r5, r1, r11, lsl #9
 *   @0x30c1b6 tstls r1, #201326592
 *   @0x30c1ba and r6, r0, r6, lsr #20
 *   @0x30c1be .word 0xf504b178
 *   @0x30c1c2 eorlo r3, r8, r8
 *   @0x30c1c6 ldc2l p7, c15, [r2, #-1020]
 *   @0x30c1ca stmibvs r1!, {r6, r9, r10, lr}
 *   @0x30c1ce rfeia r2!
 *   @0x30c1d2 strbmi r2, [r0], -r0, lsl #6
 *   @0x30c1d6 strtmi r6, [r1], -r3, lsr #3
 *   @0x30c1da .word 0xf8acf7db
 *   @0x30c1de strmi lr, [r6], -r0
 *   @0x30c1e2 sbcslt r9, r10, #17408
 *   @0x30c1e6 bhs 0xfef30e2e <b2_toiTime+0xfffffffffe7d798a>
 *   @0x30c1ea subs sp, r10, #-1073741821
 *   @0x30c1ee strhs r6, [r0], -r0, lsr #20
 *   @0x30c1f2 .word 0xfc19f7ff
 *   @0x30c1f6 bvs 0xb5dafe <b2_toiTime+0x40465a>
 *   @0x30c1fa .word 0xf89cf7db
 *   @0x30c1fe ldrb r6, [lr, r6, lsr #4]
 *   @0x30c202 subhs r11, r0, r0, lsl #30
 *   @0x30c206 ldrbne r0, [r3, #-0x2]!
 *   @0x30c20a blhs 0x30c212 <af_shaper_get_elem+0x1a80>
 *   @0x30c20e subhi pc, r7, #64
 *   @0x30c212 .word 0xf8c59f0f
 *   @0x30c216 svchs #0x608c
 *   @0x30c21a adcslt sp, r11, #384
 *   @0x30c21e strtmi r11, [r8], -r3, lsr #2
 *   @0x30c222 stc2l p7, c15, [r7], {255}
 *   @0x30c226 sbcs r2, r3, #6
 *   @0x30c22a movwhs r2, #0x101
 *   @0x30c22e andeq lr, r10, r5, lsl #17
 *   @0x30c232 stmvs r11!, {r4, r5, r9, r10, lr}
 *   @0x30c236 strne pc, [r8, #-0x8df]
 *   @0x30c23a orrseq pc, r2, #67
 *   @0x30c23e ldrbtmi r6, [r9], #-171
 *   @0x30c242 mcr2 p7, #0x3, pc, c7, c15, #0x7
 *   @0x30c246 stmdavs r3, {r3, r4, r5, r6, r8, r12, sp, pc} ^
 *   @0x30c24a .word 0xd10c2b01
 *   @0x30c24e cmplt r3, r3, asr #17
 *   @0x30c252 .word 0xf003781b
 *   @0x30c256 blhs 0x164d1da <b2_toiTime+0xef3d36>
 *   @0x30c25a blhs 0x1400266 <b2_toiTime+0xca6dc2>
 *   @0x30c25e stmvs r11!, {r0, r1, r8, r12, lr, pc}
 *   @0x30c262 movweq pc, #0x4043
 *   @0x30c266 .word 0xf8df60ab
 *   @0x30c26a .word 0x463014d8
 *   @0x30c26e .word 0xf7ff4479
 *   @0x30c272 qdaddlt pc, r0, r8
 *   @0x30c276 teqlt r9, r1, asr #17
 *   @0x30c27a bge 0x71db82 <g_SWFvertbuff+0x4aaba>
 *   @0x30c27e blx 0xb4a1f8 <b2_toiTime+0x3f0d54>
 *   @0x30c282 .word 0x61689b10
 *   @0x30c286 and r11, r10, #-1073741820
 *   @0x30c28a .word 0x616b2300
 *   @0x30c28e ldmdbeq r8, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x30c292 .word 0xf8d52700
 *   @0x30c296 ldrtmi r4, [r9], -r12, lsl #1
 *   @0x30c29a andshs r4, r0, #72, #12
 *   @0x30c29e .word 0xf8d59711
 *   @0x30c2a2 .word 0xf5aaa064
 *   @0x30c2a6 .word 0xf8dfe984
 *   @0x30c2aa qadd8mi r1, r0, r12
 *   @0x30c2ae ldrbtmi r6, [r9], #-239
 *   @0x30c2b2 mcr2 p7, #0x1, pc, c15, c15, #0x7
 *   @0x30c2b6 stmdavs r3, {r3, r5, r6, r7, r8, r12, sp, pc} ^
 *   @0x30c2ba tstle r10, r1, lsl #22
 *   @0x30c2be biclt r6, r3, r3, asr #17
 *   @0x30c2c2 .word 0xf003781b
 *   @0x30c2c6 blhs 0x16cd24a <b2_toiTime+0xf73da6>
 *   @0x30c2ca blhs 0x15802d6 <b2_toiTime+0xe26e32>
 *   @0x30c2ce stmvs r11!, {r0, r4, r8, r12, lr, pc} ^
 *   @0x30c2d2 movweq pc, #0x1043
 *   @0x30c2d6 stmvs r3, {r0, r1, r3, r5, r6, r7, sp, lr} ^
 *   @0x30c2da .word 0xf003781b
 *   @0x30c2de blhs 0x16cd262 <b2_toiTime+0xf73dbe>
 *   @0x30c2e2 .word 0xf8dfd103
 *   @0x30c2e6 ldrbtmi r3, [r11], #-1124
 *   @0x30c2ea .word 0xf8dfe002
 *   @0x30c2ee ldrbtmi r3, [r11], #-1120
 *   @0x30c2f2 .word 0xf8df9318
 *   @0x30c2f6 qsaxmi r1, r0, r12
 *   @0x30c2fa .word 0xf7ff4479
 *   @0x30c2fe orrlt pc, r8, r10, lsl #28
 *   @0x30c302 blhs 0x366416 <_ZTS12CDS_Priority+0x846e>
 *   @0x30c306 stmvs r3, {r1, r2, r3, r8, r12, lr, pc} ^
 *   @0x30c30a ldmdavc r11, {r0, r1, r5, r6, r8, r12, sp, pc}
 *   @0x30c30e bicseq pc, pc, #3
 *   @0x30c312 .word 0xd1072b42
 *   @0x30c316 .word 0xf04368eb
 *   @0x30c31a rscvs r0, r11, r2, lsl #6
 *   @0x30c31e ldrtlo pc, [r8], #-2271
 *   @0x30c322 tstls r7, #2063597568
 *   @0x30c326 ldrtne pc, [r4], #-2271
 *   @0x30c32a ldrbtmi r4, [r9], #-1568
 *   @0x30c32e ldc2l p7, c15, [r1, #1020]!
 *   @0x30c332 stmdavs r3, {r3, r4, r6, r8, r12, sp, pc} ^
 *   @0x30c336 .word 0xd1082b01
 *   @0x30c33a teqlt r3, r3, asr #17
 *   @0x30c33e .word 0xb122781a
 *   @0x30c342 sbcseq pc, pc, #2
 *   @0x30c346 svclt #0x182a4e
 *   @0x30c34a .word 0xf8df9319
 *   @0x30c34e qadd16mi r1, r0, r0
 *   @0x30c352 .word 0xf7ff4479
 *   @0x30c356 ldrsblt pc, [r8, #-222]
 *   @0x30c35a blhs 0x36646e <_ZTS12CDS_Priority+0x84c6>
 *   @0x30c35e stmvs r3, {r3, r8, r12, lr, pc} ^
 *   @0x30c362 ldmdavc r10, {r0, r1, r4, r5, r8, r12, sp, pc}
 *   @0x30c366 .word 0xf002b122
 *   @0x30c36a bhs 0x168ceee <b2_toiTime+0xf33a4a>
 *   @0x30c36e tstls r6, #24, #30
 *   @0x30c372 svcge #0x1a2400
 *   @0x30c376 strtmi r4, [r3], -r3, lsr #13
 *   @0x30c37a andeq pc, r4, r9, asr r8
 *   @0x30c37e teqlt r8, r3, ror #3
 *   @0x30c382 .word 0xf5aa9304
 *   @0x30c386 .word 0xf10be8d8
 *   @0x30c38a mvnpl r0, r1, lsl #22
 *   @0x30c38e blls 0x41d5a2 <g_RomDisk+0x25d82>
 *   @0x30c392 .word 0x2c103404
 *   @0x30c396 .word 0xf1bbd1f0
 *   @0x30c39a .word 0xd1060f00
 *   @0x30c39e .word 0xf04f4bf1
 *   @0x30c3a2 ldrbtmi r0, [r11], #-2824
 *   @0x30c3a6 movwhs r9, #0x7316
 *   @0x30c3aa uadd16mi r9, r0, r10
 *   @0x30c3ae bls 0x4ddd1a <SrcVerts+0x3ad5e>
 *   @0x30c3b2 mrc2 p7, #0x5, apsr_nzcv, c8, c10, #0x6
 *   @0x30c3b6 .word 0x46039c11
 *   @0x30c3ba bllt 0x2024a62 <b2_toiTime+0x18cb5be>
 *   @0x30c3be beq 0xe88502 <b2_toiTime+0x72f05e>
 *   @0x30c3c2 bleq 0xb48506 <b2_toiTime+0x3ef062>
 *   @0x30c3c6 eorne pc, r4, r9, asr r8
 *   @0x30c3ca eorgt pc, r4, r7, asr r8
 *   @0x30c3ce stmibvs r10!, {r0, r3, r5, r6, r7, r8, r12, sp, pc}
 *   @0x30c3d2 svclt #0x1c4293
 *   @0x30c3d6 andlt pc, r0, r3, lsl #17
 *   @0x30c3da strbtmi r3, [r2], -r1, lsl #6
 *   @0x30c3de andsgt pc, r0, sp, asr #17
 *   @0x30c3e2 .word 0xf5aa4618
 *   @0x30c3e6 .word 0xf8dde8ea
 *   @0x30c3ea .word 0x4603c010
 *   @0x30c3ee tstlt r12, r4, lsl #9
 *   @0x30c3f2 andle r2, r1, r3, lsl #24
 *   @0x30c3f6 and r4, r8, r3, ror #12
 *   @0x30c3fa rscsle r4, r11, r3, ror #10
 *   @0x30c3fe blhs 0x38a452 <bigtens_D2A+0x922>
 *   @0x30c402 svclt #0x82a20
 *   @0x30c406 .word 0xac01f803
 *   @0x30c40a strlo lr, [r1], #-2038
 *   @0x30c40e bicsle r2, r9, r4, lsl #24
 *   @0x30c412 andsvc r2, r10, r0, lsl #4
 *   @0x30c416 .word 0x9044f8dd
 *   @0x30c41a strtmi lr, [r1], r0
 *   @0x30c41e subls pc, r0, sp, asr #17
 *   @0x30c422 svceq #0xf1b9
 *   @0x30c426 teqhi r11, r0, asr #32
 *   @0x30c42a .word 0xf10d6b33
 *   @0x30c42e .word 0xf8cd0a40
 *   @0x30c432 strbmi r9, [r0], -r0
 *   @0x30c436 .word 0xf8cd3301
 *   @0x30c43a .word 0x612ba004
 *   @0x30c43e movwhs r2, #0x1110
 *   @0x30c442 mvnvs r4, r10, asr #12
 *   @0x30c446 mcr2 p7, #0x1, pc, c2, c11, #0x6
 *   @0x30c44a .word 0x46049b10
 *   @0x30c44e blhs 0x324cf6
 *   @0x30c452 .word 0x8125f040
 *   @0x30c456 andshs r4, r0, #76546048
 *   @0x30c45a stm r10!, {r1, r3, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30c45e bvs 0xfefe702e <b2_toiTime+0xfffffffffe88db8a>
 *   @0x30c462 stmibmi r0, {r4, r5, r9, r10, lr} ^
 *   @0x30c466 eorhi r4, r3, r3, lsl r4
 *   @0x30c46a .word 0xf7ff4479
 *   @0x30c46e tstlt r8, r2, asr sp
 *   @0x30c472 smlabths r10, r0, r8, r6
 *   @0x30c476 and r3, r3, r5
 *   @0x30c47a strheq pc, [r0], -r4
 *   @0x30c47e subeq r2, r0, r3, lsl #2
 *   @0x30c482 mcrr p0, #0x0, pc, r6, c12
 *   @0x30c486 ldrbtmi r4, [r9], #-2489
 *   @0x30c48a ldrtmi r8, [r0], -r0, rrx
 *   @0x30c48e stc2l p7, c15, [r1, #-1020]
 *   @0x30c492 stmvs r3, {r3, r4, r6, r8, r12, sp, pc} ^
 *   @0x30c496 rschs pc, r1, pc, asr #8
 *   @0x30c49a cmpmi r8, #2719744
 *   @0x30c49e andmi pc, sp, r0, lsl #10
 *   @0x30c4a2 .word 0xf00c3027
 *   @0x30c4a6 rsbvs lr, r0, r4, lsr r12
 *   @0x30c4aa rfeib r4!
 *   @0x30c4ae orrseq r3, r11, r2
 *   @0x30c4b2 stmibmi lr!, {r0, r1, r5, r6, sp, lr}
 *   @0x30c4b6 ldrbtmi r4, [r9], #-1584
 *   @0x30c4ba stc2 p7, c15, [r11, #-1020]!
 *   @0x30c4be rfeib r0!
 *   @0x30c4c2 orrseq r3, r11, r12
 *   @0x30c4c6 stmibmi r10!, {r0, r1, r5, r6, r7, sp, lr}
 *   @0x30c4ca ldrbtmi r4, [r9], #-1584
 *   @0x30c4ce stc2 p7, c15, [r1, #-1020]!
 *   @0x30c4d2 rfeia r0!
 *   @0x30c4d6 and r11, r0, r12
 *   @0x30c4da stmibmi r6!, {r0, r1, r7, r9, r10, lr}
 *   @0x30c4de ldrbtmi r4, [r9], #-1584
 *   @0x30c4e2 ldc2 p7, c15, [r7, #-1020]
 *   @0x30c4e6 rfeia r0!
 *   @0x30c4ea and r9, r0, r12
 *   @0x30c4ee stmvs r3!, {r0, r7, r9, r10, lr} ^
 *   @0x30c4f2 stmdavs r3!, {r0, r1, r3, r4, r5, r7, r8, r11, r12, sp, pc} ^
 *   @0x30c4f6 svceq #0xf1b9
 *   @0x30c4fa blx 0x70056a <g_SWFvertbuff+0x2d4a2>
 *   @0x30c4fe smlalbbhs pc, r8, r9, r0
 *   @0x30c502 .word 0xf00c4358
 *   @0x30c506 rscvs lr, r0, r4, lsl #24
 *   @0x30c50a svceq #0xf1bb
 *   @0x30c50e stmvs r3!, {r0, r4, r12, lr, pc} ^
 *   @0x30c512 .word 0xf08bfa0f
 *   @0x30c516 .word 0xf189fa0f
 *   @0x30c51a .word 0xf00c4358
 *   @0x30c51e .word 0x60a0ebf8
 *   @0x30c522 .word 0xf1bbe009
 *   @0x30c526 andle r0, r4, r0, lsl #30
 *   @0x30c52a svceq #0xf1b9
 *   @0x30c52e and sp, r0, pc, ror #3
 *   @0x30c532 stmvs r3!, {r0, r1, r5, r6, r7, sp, lr} ^
 *   @0x30c536 blvs 0xff0247ca <b2_toiTime+0xfffffffffe8cb326>
 *   @0x30c53a strbmi r2, [r0], -r0, lsl #4
 *   @0x30c53e streq lr, [r4], #-2189
 *   @0x30c542 blvs 0xfd496a <b2_toiTime+0x87b4c6>
 *   @0x30c546 stc2 p7, c15, [r2, #876]!
 *   @0x30c54a .word 0xf8c59b10
 *   @0x30c54e blhs 0x30c796 <af_shaper_get_elem+0x2004>
 *   @0x30c552 adchi pc, r5, r0, asr #32
 *   @0x30c556 cdpeq p0, #0x2, c15, c4, c15, #0x2
 *   @0x30c55a adclo pc, r4, r5, asr #17
 *   @0x30c55e addsmi r6, r3, #51200
 *   @0x30c562 blx 0x6c0dc0 <g_SWFlinevertbuff+0x6dcf8>
 *   @0x30c566 .word 0xf8d54203
 *   @0x30c56a ldmdavs r0, {r4, r7, r12} ^
 *   @0x30c56e eorseq pc, r3, r1, asr #16
 *   @0x30c572 ldrsbne pc, [r0], r5
 *   @0x30c576 biceq lr, r3, r1, lsl #22
 *   @0x30c57a ldmdavs r1, {r0, r1, r3, r7, pc} ^
 *   @0x30c57e addsmi r6, r1, #466944
 *   @0x30c582 mrrcne p1, #0x0, sp, r10, c3
 *   @0x30c586 .word 0xf8c5bf18
 *   @0x30c58a movwlo r3, #0x10a4
 *   @0x30c58e ldmdbmi r10!, {r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x30c592 ldrbtmi r4, [r9], #-1584
 *   @0x30c596 ldc2 p7, c15, [sp], #1020
 *   @0x30c59a ldrbtmi r4, [r9], #-2425
 *   @0x30c59e ldrtmi r4, [r0], -r4, lsl #12
 *   @0x30c5a2 ldc2 p7, c15, [r7], #1020
 *   @0x30c5a6 rsble r2, r4, r0, lsl #24
 *   @0x30c5aa rsble r2, r2, r0, lsl #16
 *   @0x30c5ae blhs 0x366742 <_ZTS12CDS_Priority+0x879a>
 *   @0x30c5b2 stmdavs r3, {r0, r1, r2, r3, r4, r6, r8, r12, lr, pc} ^
 *   @0x30c5b6 cmple r12, r1, lsl #22
 *   @0x30c5ba blhs 0x32694e
 *   @0x30c5be stmvs r1, {r0, r3, r4, r6, r12, lr, pc} ^
 *   @0x30c5c2 subsle r2, r6, r0, lsl #18
 *   @0x30c5c6 ldrbmi r4, [r2], -r0, asr #12
 *   @0x30c5ca .word 0xf97af7dc
 *   @0x30c5ce .word 0xf8c59b10
 *   @0x30c5d2 blhs 0x30c7ea <af_shaper_get_elem+0x2058>
 *   @0x30c5d6 strbmi sp, [r0], -r3, ror #2
 *   @0x30c5da ldrbmi r6, [r2], -r1, ror #17
 *   @0x30c5de .word 0xf970f7dc
 *   @0x30c5e2 .word 0xf8c59b10
 *   @0x30c5e6 blhs 0x30c80e <af_shaper_get_elem+0x207c>
 *   @0x30c5ea stmdavc r3, {r0, r3, r4, r6, r8, r12, lr, pc}
 *   @0x30c5ee bicseq pc, pc, #3
 *   @0x30c5f2 .word 0xd1232b49
 *   @0x30c5f6 .word 0xf0037843
 *   @0x30c5fa blhs 0x17cd57e <b2_toiTime+0x10740da>
 *   @0x30c5fe stmvc r3, {r1, r2, r3, r4, r8, r12, lr, pc}
 *   @0x30c602 bicseq pc, pc, #3
 *   @0x30c606 tstle r9, pc, asr #22
 *   @0x30c60a ldmdbmi sp, {r2, r6, r7, r10, r11, r12} ^
 *   @0x30c60e ldrbtmi r4, [r9], #-1568
 *   @0x30c612 svc #0xb0f5a9
 *   @0x30c616 ldmdbmi r11, {r7, r8, r12, sp, pc} ^
 *   @0x30c61a ldrbtmi r4, [r9], #-1568
 *   @0x30c61e svc #0xaaf5a9
 *   @0x30c622 ldmdbmi r9, {r5, r6, r8, r11, r12, sp, pc} ^
 *   @0x30c626 .word 0x0084f8d5
 *   @0x30c62a .word 0xf5a94479
 *   @0x30c62e .word 0xf1d0efa2
 *   @0x30c632 svclt #0x380001
 *   @0x30c636 and r2, r2, r0
 *   @0x30c63a and r2, r0, r1
 *   @0x30c63e movwhs r2, #0x0
 *   @0x30c642 tstls r11, #109051904
 *   @0x30c646 rsbslo pc, r0, sp, lsr #17
 *   @0x30c64a rsbslo pc, r2, sp, lsr #17
 *   @0x30c64e blmi 0x1178b36 <b2_toiTime+0xa1f692>
 *   @0x30c652 movwhs r9, #0x331b
 *   @0x30c656 rsbslo pc, r0, sp, lsr #17
 *   @0x30c65a .word 0xf8ad2301
 *   @0x30c65e stmdami r11, {r1, r4, r5, r6, r12, sp} ^
 *   @0x30c662 ldrtmi r2, [r10], -r0, lsl #2
 *   @0x30c666 ldrbtmi r4, [r8], #-1547
 *   @0x30c66a .word 0xf7db3018
 *   @0x30c66e andsls pc, r0, r3, lsl #29
 *   @0x30c672 blmi 0xf846ce <b2_toiTime+0x82b22a>
 *   @0x30c676 stmdami r6, {r8, sp} ^
 *   @0x30c67a ldrls r4, [r10, #-0x63a]
 *   @0x30c67e tstls r11, #120, #8
 *   @0x30c682 movwhs r3, #0x7018
 *   @0x30c686 rsbslo pc, r0, sp, lsr #17
 *   @0x30c68a .word 0xf8ad460b
 *   @0x30c68e .word 0xf7db1072
 *   @0x30c692 bvs 0x1e0c05e <b2_toiTime+0x16b2bba>
 *   @0x30c696 tstlt r3, r0, lsl r0
 *   @0x30c69a ldmdavs r11, {r0, r1, r3, r5, r7, r9, r11, sp, lr}
 *   @0x30c69e ldmdals r0, {r0, r1, r3, r5, r6, r7, r8, r10, sp, lr}
 *   @0x30c6a2 qadd8mi lr, r8, r6
 *   @0x30c6a6 blx 0xfe48a6aa <b2_toiTime+0xfffffffffdd31206>
 *   @0x30c6aa adds r2, r1, r2
 *   @0x30c6ae .word 0xf04f990e
 *   @0x30c6b2 bl 0x48ceba <prim_v+0x3506>
 *   @0x30c6b6 andvc r0, r10, r7, lsl #22
 *   @0x30c6ba blhs 0xbe3e8e <b2_toiTime+0x48a9ea>
 *   @0x30c6be blhs 0x9c06ca <b2_toiTime+0x267226>
 *   @0x30c6c2 svcls #0x8d10c
 *   @0x30c6c6 strlo r9, [r1, -r6, lsl #18]
 *   @0x30c6ca svcls #0xe9708
 *   @0x30c6ce eorsvc r2, r9, r10, lsl #18
 *   @0x30c6d2 streq pc, [r1, -r9, lsl #2]
 *   @0x30c6d6 .word 0xf04fd123
 *   @0x30c6da ldrt r0, [r8], #2829
 *   @0x30c6de ldclle p5, c4, [r0, #740]!
 *   @0x30c6e2 streq lr, [r9, -r7, asr #23]
 *   @0x30c6e6 andsgt pc, r0, sp, asr #17
 *   @0x30c6ea ldrbmi r9, [r8], -r3, lsl #14
 *   @0x30c6ee strls r4, [r0], #-1593
 *   @0x30c6f2 blls 0x5b2f1a <g_SWFlineaavertbuff+0x5fe52>
 *   @0x30c6f6 .word 0x47b89f16
 *   @0x30c6fa ldrsbgt pc, [r0], -sp
 *   @0x30c6fe andlo r9, r1, r10, lsl r0
 *   @0x30c702 strls sp, [r0], #-265
 *   @0x30c706 stmdbls r3, {r3, r4, r6, r9, r10, lr}
 *   @0x30c70a blls 0x5b2f32 <g_SWFlineaavertbuff+0x5fe6a>
 *   @0x30c70e .word 0x47b89f16
 *   @0x30c712 ldrsbgt pc, [r0], -sp
 *   @0x30c716 blls 0x9b0786 <b2_toiTime+0x2572e2>
 *   @0x30c71a sbcsle r2, r2, r0, lsl #22
 *   @0x30c71e stmdbls r6, {r0, r1, r2, r3, r4, r5, r7, r10, sp, lr, pc}
 *   @0x30c722 stmdbhs sp, {r8, r9, sp}
 *   @0x30c726 .word 0xf44fbf14
 *   @0x30c72a .word 0xf04f7b80
 *   @0x30c72e str r0, [r0], #2826
 *   @0x30c732 bne 0x16bc33a <b2_toiTime+0xf62e96>
 *   @0x30c736 stmdbvs r3!, {r0} ^
 *   @0x30c73a svcmi #0x42756e
 *   @0x30c73e svchs #0x414144
 *   @0x30c742 strhs r0, [r6, #0x8]!
 *   @0x30c746 strhs r0, [r8, #-0x8]!
 *   @0x30c74a strbths r0, [r1], #8
 *   @0x30c74e strbths r0, [r1], #8
 *   @0x30c752 strbths r0, [r4], #8
 *   @0x30c756 strbhs r0, [r8], #8
 *   @0x30c75a strbhs r0, [r3], #8
 *   @0x30c75e strths r0, [r11], #8
 *   @0x30c762 strbths r0, [r8], #-8
 *   @0x30c766 .word 0x23b60008
 *   @0x30c76a .word 0x23a60008
 *   @0x30c76e orrhs r0, r1, #8
 *   @0x30c772 cmnhs r8, #8
 *   @0x30c776 cmnhs r1, #8
 *   @0x30c77a sbchs r0, r10, #8
 *   @0x30c77e sbcshs r0, r3, #8
 *   @0x30c782 rsbshs r0, r0, #8
 *   @0x30c786 rsbhs r0, r10, #8
 *   @0x30c78a rsbhs r0, r1, #8
 *   @0x30c78e svcle #0xac0008
 *   @0x30c792 svcle #0x96000d
 *   @0x30c796 bls 0x44c7d2 <g_RomDisk+0x54fb2>
 *   @0x30c79a blls 0x554ba6 <g_SWFlineaavertbuff+0x1ade>
 *   @0x30c79e b 0x16f1fa6 <b2_toiTime+0xf98b02>
 *   @0x30c7a2 stmdals r11, {r1, r6, r8, r11}
 *   @0x30c7a6 ldrmi r9, [r2], r1, lsl #6
 *   @0x30c7aa .word 0xf7db464b
 *   @0x30c7ae blls 0x9cb972 <b2_toiTime+0x2724ce>
 *   @0x30c7b2 blhs 0x31dfd2
 *   @0x30c7b6 ldclge p4, c15, [r3], #-508
 *   @0x30c7ba andsls pc, r4, sp, asr #17
 *   @0x30c7be bl 0xff5058ae <b2_toiTime+0xfffffffffedac40a>
 *   @0x30c7c2 ldmibne r1!, {r2, r3, r9, r11} ^
 *   @0x30c7c6 smladxhs r0, r0, r6, r4
 *   @0x30c7ca .word 0xf5a94652
 *   @0x30c7ce ldrt lr, [r1], #-3938
 *   @0x30c7d2 pop {r0, r1, r2, r3, r4, r12, sp, pc}
 *   @0x30c7d6 movwhs r8, #0xff0
 *   @0x30c7da ldrblt r6, [r0, #0xb]!
 *   @0x30c7de stmvs r2, {r4, r8, r9, r12, sp, pc}
 *   @0x30c7e2 stmdavs r2, {r1, r3, r4, r5, r6, r7, r8, r12, sp, pc}
 *   @0x30c7e6 qadd16hs r4, r0, r12
 *   @0x30c7ea stmvs r5, {r1, r4, r11, sp, lr}
 *   @0x30c7ee andsle r4, r0, #172, #4
 *   @0x30c7f2 .word 0xf8556805
 *   @0x30c7f6 bne 0x2e888e <FT_Get_Sfnt_LangTag+0xa6>
 *   @0x30c7fa ldrshlt r5, [r5, -sp]
 *   @0x30c7fe movwlo r5, #0x14d5
 *   @0x30c802 stmvs r5, {r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30c806 ldrmi r3, [pc], -r1, lsl #8
 *   @0x30c80a svclt #0x3c42ac
 *   @0x30c80e movwlo r5, #0x15d6
 *   @0x30c812 stmdami r4, {r0, r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30c816 adclo r4, r0, r8, ror r4
 *   @0x30c81a svclt #0x1c4282
 *   @0x30c81e ldrbpl r2, [r0], #0
 *   @0x30c822 ldrmi r6, [r0], -r11
 *   @0x30c826 svcvs #0x36bdf0
 *   @0x30c82a push {r0, r3}
 *   @0x30c82e .word 0x46044ff0
 *   @0x30c832 .word 0xf500b089
 *   @0x30c836 strmi r2, [sp], -r8, lsl #15
 *   @0x30c83a .word 0xf8d44608
 *   @0x30c83e .word 0xf04f1080
 *   @0x30c842 ldrmi r0, [r6], -r0, lsl #18
 *   @0x30c846 .word 0x8088f8d7
 *   @0x30c84a andsls pc, r8, sp, asr #17
 *   @0x30c84e ldc2l p7, c15, [r2, #-864]!
 *   @0x30c852 stmdavs r2, {r3, r4, r5, r8, r9, r12, sp, pc}
 *   @0x30c856 bl 0x3e7cea <error_g0017+0x4098e>
 *   @0x30c85a stmdavs r3!, {r1, r10, r12} ^
 *   @0x30c85e andsle r2, r7, r2, lsl #22
 *   @0x30c862 andsle r2, r10, r3, lsl #22
 *   @0x30c866 .word 0xf0402b01
 *   @0x30c86a strbmi r8, [r0], -r4, asr #2
 *   @0x30c86e .word 0xf7da68e1
 *   @0x30c872 .word 0xf8c4fd61
 *   @0x30c876 cdphs p0, #0x0, c9, c0, c12, #0x0
 *   @0x30c87a teqhi r11, r0
 *   @0x30c87e blhs 0x32a952
 *   @0x30c882 teqhi r7, r0
 *   @0x30c886 ldrtmi r4, [r1], -r0, asr #12
 *   @0x30c88a .word 0xf7dcaa06
 *   @0x30c88e and pc, r2, r9, lsl r8
 *   @0x30c892 .word 0xf7fe4630
 *   @0x30c896 rscvs pc, r0, r6, ror pc
 *   @0x30c89a ldrtmi lr, [r0], -r11, lsr #2
 *   @0x30c89e blx 0xc8a8a2 <b2_toiTime+0x5313fe>
 *   @0x30c8a2 .word 0xf107e7f9
 *   @0x30c8a6 qadd8mi r0, r8, r4
 *   @0x30c8aa .word 0xf7d84649
 *   @0x30c8ae strmi pc, [r2], r3, asr #26
 *   @0x30c8b2 .word 0xd1672800
 *   @0x30c8b6 .word 0x2088f8d7
 *   @0x30c8ba andls r4, r7, r9, asr #12
 *   @0x30c8be andls r4, r3, #40, #12
 *   @0x30c8c2 ldc2 p7, c15, [r8, #-864]!
 *   @0x30c8c6 cmple r3, r0, lsl #16
 *   @0x30c8ca .word 0x308cf8d7
 *   @0x30c8ce bleq 0xa48d0a <b2_toiTime+0x2ef866>
 *   @0x30c8d2 ldrsbhs pc, [r0], r7
 *   @0x30c8d6 .word 0xf8cd2110
 *   @0x30c8da movwls r11, #0x4
 *   @0x30c8de stmdals r3, {r0, r1, r4, r6, r10, r11, r12}
 *   @0x30c8e2 blx 0xff84a858 <b2_toiTime+0xffffffffff0f13b4>
 *   @0x30c8e6 strmi r9, [r2], r7, lsl #22
 *   @0x30c8ea addeq pc, r12, r7, asr #17
 *   @0x30c8ee teqle pc, r0, lsl #22
 *   @0x30c8f2 ldrsbhs pc, [r0], r7
 *   @0x30c8f6 movwls r4, #0x2619
 *   @0x30c8fa andls r0, r5, #-2147483644
 *   @0x30c8fe andls r4, r4, #33554432
 *   @0x30c902 andshs r4, r0, #16, #12
 *   @0x30c906 cdp p5, #0x5, c15, c4, c9, #0x5
 *   @0x30c90a .word 0xf5a94628
 *   @0x30c90e blls 0x3c8166 <error_g0017+0x20e0a>
 *   @0x30c912 stm sp, {r0, r8, sp}
 *   @0x30c916 ldrmi r0, [r10], -r8, lsl #16
 *   @0x30c91a .word 0x0c01f100
 *   @0x30c91e .word 0xf8cd9803
 *   @0x30c922 strbtmi r12, [r3], -r8
 *   @0x30c926 blx 0xfefca89c <b2_toiTime+0xfffffffffe8713f8>
 *   @0x30c92a .word 0xf84a9b05
 *   @0x30c92e .word 0xf8dd0003
 *   @0x30c932 .word 0xf8ddb01c
 *   @0x30c936 .word 0xf1bbc008
 *   @0x30c93a tstle r9, r0, lsl #30
 *   @0x30c93e strtmi r4, [r9], -r2, ror #12
 *   @0x30c942 cdp p5, #0x3, c15, c12, c9, #0x5
 *   @0x30c946 movwhs r9, #0x1a04
 *   @0x30c94a andlt pc, r8, r2, asr #17
 *   @0x30c94e .word 0x464a6053
 *   @0x30c952 .word 0xf8d79b05
 *   @0x30c956 .word 0xf85a1090
 *   @0x30c95a cmplo r3, r3
 *   @0x30c95e .word 0xf7db9b03
 *   @0x30c962 andls pc, r7, r2, lsr #28
 *   @0x30c966 .word 0xf8d7b920
 *   @0x30c96a movwlo r3, #0x1090
 *   @0x30c96e addslo pc, r0, r7, asr #17
 *   @0x30c972 movwls r9, #0x6b07
 *   @0x30c976 .word 0xf0402b00
 *   @0x30c97a .word 0x462880bc
 *   @0x30c97e .word 0xf7d84649
 *   @0x30c982 pkhtbmi pc, r2, r9, asr #25
 *   @0x30c986 stcvs p12, c6, [r3], #904
 *   @0x30c98a .word 0xd120429a
 *   @0x30c98e ldmiblt r10!, {r1, r2, r8, r9, r11, sp, pc}
 *   @0x30c992 andeq lr, r12, sp, lsl #17
 *   @0x30c996 tsths r0, r0, asr #12
 *   @0x30c99a .word 0xf7db2301
 *   @0x30c99e blls 0x4cb782 <SrcVerts+0x287c6>
 *   @0x30c9a2 blhs 0x325e2a
 *   @0x30c9a6 adchi pc, r5, r0, asr #32
 *   @0x30c9aa smlatbhs r0, r0, r12, r6
 *   @0x30c9ae andshs r6, r0, #2240
 *   @0x30c9b2 andne lr, r0, r3, lsl #22
 *   @0x30c9b6 ldcl p5, c15, [r12, #676]!
 *   @0x30c9ba movwlo r6, #0x1ca3
 *   @0x30c9be and r6, r6, r3, lsr #9
 *   @0x30c9c2 strbmi r6, [r0], -r1, lsr #26
 *   @0x30c9c6 andeq lr, r10, sp, lsl #17
 *   @0x30c9ca mrrcne p1, #0x1, r2, r3, c0
 *   @0x30c9ce .word 0xf8dae7e5
 *   @0x30c9d2 bhs 0x17949da <b2_toiTime+0x103b536>
 *   @0x30c9d6 .word 0xf504d907
 *   @0x30c9da cps #0x8
 *   @0x30c9de blo 0x17e13e6 <b2_toiTime+0x1087f42>
 *   @0x30c9e2 .word 0x308cf8d3
 *   @0x30c9e6 blmi 0x19849f6 <b2_toiTime+0x122b552>
 *   @0x30c9ea movtlo r4, #0x47b
 *   @0x30c9ee movwne lr, #0x2b03
 *   @0x30c9f2 .word 0xf8d46ce2
 *   @0x30c9f6 b 0x16f4b3e <b2_toiTime+0xf9b69a>
 *   @0x30c9fa ldmdavs r10, {r1, r8, r11, r12}
 *   @0x30c9fe streq lr, [r9, -r10, lsl #22]
 *   @0x30ca02 andhs pc, r9, r10, asr #16
 *   @0x30ca06 rsbsvs r6, r10, r10, asr r8
 *   @0x30ca0a umlalsvs r6, r10, r10, r8
 *   @0x30ca0e blhs 0x3a6b82 <_ZTSPKDn+0x13ba>
 *   @0x30ca12 blhs 0x400a5e <g_RomDisk+0x923e>
 *   @0x30ca16 blhs 0x380a6a <_ZTS13C_UTF16String+0x17b16>
 *   @0x30ca1a movwhs sp, #0x115
 *   @0x30ca1e ldrshlt r6, [r6, r11]
 *   @0x30ca22 orrlt r7, r3, r3, lsr r8
 *   @0x30ca26 ldrtmi r4, [r1], -r0, asr #12
 *   @0x30ca2a .word 0xf7dbaa06
 *   @0x30ca2e blls 0x4cc75a <SrcVerts+0x2979e>
 *   @0x30ca32 strdlt r6, r7, [r3, #-8]
 *   @0x30ca36 shsaxmi lr, r0, sp
 *   @0x30ca3a mcr2 p7, #0x5, pc, c3, c14, #0x7
 *   @0x30ca3e ldrtmi lr, [r0], -r2
 *   @0x30ca42 .word 0xf953f7ff
 *   @0x30ca46 stmdbmi r2, {r3, r4, r5, r6, r7, sp, lr} ^
 *   @0x30ca4a andhs r4, r7, #40, #12
 *   @0x30ca4e .word 0xf5a94479
 *   @0x30ca52 stmdahs r0, {r1, r2, r6, r7, r8, r10, r11, sp, lr, pc}
 *   @0x30ca56 stmibvc r11!, {r0, r4, r6, r8, r12, lr, pc} ^
 *   @0x30ca5a svceq #0xdff013
 *   @0x30ca5e stclvs p1, c13, [r3], #40
 *   @0x30ca62 ldmdbmi r12!, {r3, r5, r9, r10, lr}
 *   @0x30ca66 movwlo r2, #0x120c
 *   @0x30ca6a ldrbtmi r6, [r9], #-1251
 *   @0x30ca6e ldc p5, c15, [r8, #676]!
 *   @0x30ca72 and r11, r5, r8, ror r9
 *   @0x30ca76 rscsle r2, r2, sp, lsl #22
 *   @0x30ca7a blhs 0x35b6a6
 *   @0x30ca7e .word 0xe7eed83d
 *   @0x30ca82 .word 0xf0137b2b
 *   @0x30ca86 ldrdle r0, r1, [r4], #-255
 *   @0x30ca8a suble r2, r2, sp, lsl #22
 *   @0x30ca8e blhs 0x35b6ba
 *   @0x30ca92 ldmdbmi r1!, {r0, r1, r2, r3, r4, r5, r8, r11, r12, lr, pc}
 *   @0x30ca96 andhs r4, r11, #40, #12
 *   @0x30ca9a .word 0xf5a94479
 *   @0x30ca9e stmdblt r0, {r5, r7, r8, r10, r11, sp, lr, pc} ^
 *   @0x30caa2 .word 0xf0137aeb
 *   @0x30caa6 ldrsbtle r0, [r7], -pc
 *   @0x30caaa eorsle r2, r5, sp, lsl #22
 *   @0x30caae blhs 0x35b6da
 *   @0x30cab2 stmdbmi r10!, {r1, r4, r5, r8, r11, r12, lr, pc}
 *   @0x30cab6 andhs r4, r12, #40, #12
 *   @0x30caba .word 0xf5a94479
 *   @0x30cabe stmdblt r0, {r4, r7, r8, r10, r11, sp, lr, pc} ^
 *   @0x30cac2 .word 0xf0137b2b
 *   @0x30cac6 .word 0xd02a0fdf
 *   @0x30caca eorle r2, r8, sp, lsl #22
 *   @0x30cace blhs 0x35b6fa
 *   @0x30cad2 stmdbmi r3!, {r0, r2, r5, r8, r11, r12, lr, pc}
 *   @0x30cad6 andhs r4, r7, #40, #12
 *   @0x30cada .word 0xf5a94479
 *   @0x30cade stmdblt r0, {r7, r8, r10, r11, sp, lr, pc} ^
 *   @0x30cae2 .word 0xf01379eb
 *   @0x30cae6 ldrsble r0, [sp], -pc
 *   @0x30caea andsle r2, r11, sp, lsl #22
 *   @0x30caee blhs 0x35b71a
 *   @0x30caf2 stmdals r6, {r3, r4, r8, r11, r12, lr, pc}
 *   @0x30caf6 pop {r0, r3, r12, sp, pc}
 *   @0x30cafa .word 0xf85a8ff0
 *   @0x30cafe strbmi r0, [r3], -r9
 *   @0x30cb02 .word 0xf8d46ce1
 *   @0x30cb06 .word 0xf7db2080
 *   @0x30cb0a andls pc, r6, lr, asr #26
 *   @0x30cb0e adcle r2, r6, r0, lsl #16
 *   @0x30cb12 ldmvs r11!, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x30cb16 strb r6, [r12, r3, ror #4]!
 *   @0x30cb1a adcvs r6, r3, #16449536
 *   @0x30cb1e ldmvs r11!, {r0, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x30cb22 strb r6, [r6, r3, ror #5]!
 *   @0x30cb26 ldmdblt r3, {r0, r1, r3, r4, r5, r6, r7, r11, sp, lr}
 *   @0x30cb2a movwls r2, #0x6303
 *   @0x30cb2e ldmdavc r11, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30cb32 bicseq pc, pc, #3
 *   @0x30cb36 qaddle r2, r0, r1
 *   @0x30cb3a and r2, r6, r8, lsl #6
 *   @0x30cb3e .word 0xd1012b4d
 *   @0x30cb42 and r2, r2, r0, lsl r3
 *   @0x30cb46 bicsle r2, r4, r3, asr #22
 *   @0x30cb4a mvnvs r2, r0, lsr #6
 *   @0x30cb4e stcle p7, c14, [r10], #-836
 *   @0x30cb52 ldrhs r0, [r11, -sp]!
 *   @0x30cb56 strhs r0, [r5, -r8]!
 *   @0x30cb5a strhs r0, [r4, -r8]
 *   @0x30cb5e ldrbths r0, [r0], r8
 *   @0x30cb62 strths r0, [r7], r8
 *   @0x30cb66 ldrlt r0, [r0, #-0x8]
 *   @0x30cb6a stmvs r3, {r4, r5, r7, r8, r12, sp, pc}
 *   @0x30cb6e blhs 0x379202 <_ZTS13C_UTF16String+0x102ae>
 *   @0x30cb72 movwhs sp, #0x1910
 *   @0x30cb76 addsmi r6, r3, #8519680
 *   @0x30cb7a stmdavs r1, {r0, r3, r9, r12, lr, pc}
 *   @0x30cb7e addmi pc, r0, #-1073741824
 *   @0x30cb82 .word 0xf8513a01
 *   @0x30cb86 movwlo r4, #0x1023
 *   @0x30cb8a eormi pc, r2, r1, asr #16
 *   @0x30cb8e blo 0x386b5e <_ZTS13C_UTF16String+0x1dc0a>
 *   @0x30cb92 ldclt p0, c6, [r0, #-520]
 *   @0x30cb96 addvs r2, r3, r0, lsl #6
 *   @0x30cb9a push {r4, r8, r10, r11, r12, sp, pc}
 *   @0x30cb9e .word 0x46884ff0
 *   @0x30cba2 ldrmi r4, [r9], r12, lsl #29
 *   @0x30cba6 adclt r4, r3, r12, lsl #19
 *   @0x30cbaa ldmdavs r6!, {r1, r2, r3, r4, r5, r6, r10, lr}
 *   @0x30cbae ldrbtmi r2, [r9], #-525
 *   @0x30cbb2 ldmdavs r3!, {r0, r2, r9, r10, lr}
 *   @0x30cbb6 stcls p6, c4, [r12], #-220
 *   @0x30cbba .word 0xf5a99321
 *   @0x30cbbe stmdblt r0, {r4, r8, r10, r11, sp, lr, pc} ^
 *   @0x30cbc2 .word 0xf0127b6a
 *   @0x30cbc6 ldrsble r0, [lr], -pc
 *   @0x30cbca andsle r2, r12, sp, lsl #20
 *   @0x30cbce bhs 0x35b3fa
 *   @0x30cbd2 stmibmi r1, {r0, r3, r4, r8, r11, r12, lr, pc}
 *   @0x30cbd6 andshs r4, r5, #40, #12
 *   @0x30cbda .word 0xf5a94479
 *   @0x30cbde stmdahs r0, {r8, r10, r11, sp, lr, pc}
 *   @0x30cbe2 stclvc p1, c13, [r10, #-372]!
 *   @0x30cbe6 bicseq pc, pc, #18
 *   @0x30cbea bhs 0x680c06 <g_SWFlinevertbuff+0x2db3e>
 *   @0x30cbee blo 0x580c06 <g_SWFlineaavertbuff+0x2db3e>
 *   @0x30cbf2 ldmdale r4, {r0, r9, r11, sp} ^
 *   @0x30cbf6 ldrmi lr, [r8], -r0
 *   @0x30cbfa ldmdavs r11!, {r0, r5, r9, r11, r12, pc}
 *   @0x30cbfe .word 0xf000429a
 *   @0x30cc02 .word 0xf5a980e4
 *   @0x30cc06 ldclmi p12, c14, [r5, #-920]!
 *   @0x30cc0a ldrbtmi r6, [sp], #-2592
 *   @0x30cc0e .word 0xf7ff4629
 *   @0x30cc12 stmiblt r8, {r7, r8, r11, r12, sp, lr, pc} ^
 *   @0x30cc16 vmlage.f32 s12, s2, s7
 *   @0x30cc1a shsub16mi r4, r0, r2
 *   @0x30cc1e strhhs pc, [r12], -r3
 *   @0x30cc22 addsvs r4, r10, #2030043136
 *   @0x30cc26 rfeib r3!
 *   @0x30cc2a .word 0xf5a9200c
 *   @0x30cc2e bvs 0xb47e76 <b2_toiTime+0x3ee9d2>
 *   @0x30cc32 ldrtmi r4, [r2], -r9, lsr #12
 *   @0x30cc36 ldc2l p7, c15, [r9, #1020]!
 *   @0x30cc3a bicsle r2, sp, r0, lsl #16
 *   @0x30cc3e andhs r6, r1, #143360
 *   @0x30cc42 orrhs pc, r8, #12582912
 *   @0x30cc46 addhs pc, r4, r3, lsr #17
 *   @0x30cc4a bvs 0xb201ee <b2_toiTime+0x3c6d4a>
 *   @0x30cc4e qsub16mi r4, r9, sp
 *   @0x30cc52 .word 0xf95ff7ff
 *   @0x30cc56 bvs 0xbfb37e <b2_toiTime+0x4a1eda>
 *   @0x30cc5a stmdbmi r3!, {r0, r9, r10, r11, sp, pc} ^
 *   @0x30cc5e rfeib r3!
 *   @0x30cc62 ldrbtmi r2, [r9], #-14
 *   @0x30cc66 bvs 0xbe57d6 <b2_toiTime+0x48c332>
 *   @0x30cc6a strhhs pc, [lr], -r3
 *   @0x30cc6e ldcl p5, c15, [r0], #-676
 *   @0x30cc72 strtmi r6, [r9], -r0, lsr #20
 *   @0x30cc76 .word 0xf7ff4632
 *   @0x30cc7a stmdahs r0, {r3, r4, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x30cc7e bvs 0xc01376 <b2_toiTime+0x4a7ed2>
 *   @0x30cc82 .word 0xf5032201
 *   @0x30cc86 .word 0xf8a32388
 *   @0x30cc8a stmdavs r3!, {r2, r7, sp}
 *   @0x30cc8e .word 0xf0232000
 *   @0x30cc92 eorvs r0, r3, r0, lsl r3
 *   @0x30cc96 ldrbtmi r4, [r11], #-2902
 *   @0x30cc9a andlo pc, r0, r9, asr #17
 *   @0x30cc9e ldmdbmi r4, {r2, r3, r5, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x30cca2 andhs r4, r7, #40, #12
 *   @0x30cca6 .word 0xf5a94479
 *   @0x30ccaa stmdblt r8!, {r1, r3, r4, r7, r10, r11, sp, lr, pc} ^
 *   @0x30ccae .word 0xf01379eb
 *   @0x30ccb2 ldrsble r0, [sp], #-255
 *   @0x30ccb6 andle r2, r2, sp, lsl #22
 *   @0x30ccba blhs 0x35b8e6
 *   @0x30ccbe movwhs sp, #0x804
 *   @0x30ccc2 andeq pc, r8, #1073741825
 *   @0x30ccc6 rsb r7, r1, r11, ror #3
 *   @0x30ccca strtmi r6, [r11], -r1, lsr #20
 *   @0x30ccce .word 0xf813461e
 *   @0x30ccd2 .word 0xb1222b01
 *   @0x30ccd6 suble r2, pc, r0, lsr #20
 *   @0x30ccda mvnsle r2, r9, lsl #20
 *   @0x30ccde ldrtmi lr, [r2], r12, asr #32
 *   @0x30cce2 ldmiblo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^
 *   @0x30cce6 movwhs r11, #0x90d
 *   @0x30ccea stmdavc r11!, {r0, r3, r4, sp, lr, pc}
 *   @0x30ccee rscsle r2, r10, r0, lsl #22
 *   @0x30ccf2 blhs 0xfe54a0fe <b2_toiTime+0xfffffffffddf0c5a>
 *   @0x30ccf6 .word 0xf10b4628
 *   @0x30ccfa .word 0xf7d80194
 *   @0x30ccfe stmdahs r0, {r0, r1, r3, r4, r8, r9, r11, r12, sp, lr, pc}
 *   @0x30cd02 stmdavs r2, {r0, r4, r5, r6, r7, r12, lr, pc}
 *   @0x30cd06 stmdble r5, {r1, r4, r6, r9, r11, sp}
 *   @0x30cd0a addpl pc, r0, #-2147483648
 *   @0x30cd0e .word 0x308cf8db
 *   @0x30cd12 and r3, r2, r3, asr r10
 *   @0x30cd16 ldrbtmi r4, [r11], #-2872
 *   @0x30cd1a bl 0x3d9a22 <error_g0017+0x326c6>
 *   @0x30cd1e .word 0xf1b91302
 *   @0x30cd22 svclt #0x183fff
 *   @0x30cd26 andls pc, r0, r6, lsl #17
 *   @0x30cd2a ldmdavs r11, {r0, r1, r4, r8, r12, sp, pc} ^
 *   @0x30cd2e teqle r2, r1, lsl #22
 *   @0x30cd32 bl 0x46ae02 <g_RomDisk+0x735e2>
 *   @0x30cd36 tstlt r10, r8, lsl #6
 *   @0x30cd3a andhs r3, r0, #1048576
 *   @0x30cd3e andhs pc, r0, r10, lsl #17
 *   @0x30cd42 .word 0xf8164632
 *   @0x30cd46 teqlt r1, r1, lsl #22
 *   @0x30cd4a rscsle r2, r9, r0, lsr #18
 *   @0x30cd4e rscsle r2, r7, r9, lsl #18
 *   @0x30cd52 svclt #0x82922
 *   @0x30cd56 andhs r4, r0, r2, lsr r6
 *   @0x30cd5a ldmdble r7, {r0, r1, r4, r7, r9, lr}
 *   @0x30cd5e .word 0x1c01f813
 *   @0x30cd62 .word 0xd1022920
 *   @0x30cd66 stceq p8, c15, [r1, #-12]
 *   @0x30cd6a stmdbhs r9, {r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30cd6e strd sp, lr, [r8], -r10
 *   @0x30cd72 .word 0xd1a42b00
 *   @0x30cd76 and r1, r9, r10, ror #27
 *   @0x30cd7a ldrmi r2, [r1], r0, lsl #6
 *   @0x30cd7e .word 0x46b27033
 *   @0x30cd82 stmdbhs r2!, {r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30cd86 .word 0x2100d102
 *   @0x30cd8a .word 0x1c01f803
 *   @0x30cd8e strtmi r6, [r9], -r0, lsr #20
 *   @0x30cd92 stc2l p7, c15, [r11, #-1020]
 *   @0x30cd96 .word 0xf504e730
 *   @0x30cd9a ldmdbmi r7, {r3, r8, r11, r12, sp}
 *   @0x30cd9e strteq pc, [r8], -r9, lsl #2
 *   @0x30cda2 ldrbtmi r4, [r9], #-1578
 *   @0x30cda6 ldrtmi r4, [r0], -r3, asr #12
 *   @0x30cdaa .word 0xffddf7fe
 *   @0x30cdae .word 0xf47f2800
 *   @0x30cdb2 .word 0xf8d9af23
 *   @0x30cdb6 ldrtmi r3, [r0], -r8, lsr #32
 *   @0x30cdba .word 0xf7ff681d
 *   @0x30cdbe .word 0x4630fed4
 *   @0x30cdc2 .word 0xf7ff4669
 *   @0x30cdc6 strmi pc, [r2], -r8, lsl #26
 *   @0x30cdca eorlt lr, r3, r0, ror #15
 *   @0x30cdce svchi #0xf0e8bd
 *   @0x30cdd2 stceq p15, c11, [r10, #0]!
 *   @0x30cdd6 strhs r0, [r7], -lr
 *   @0x30cdda strbhs r0, [pc, #0x8]!
 *   @0x30cdde ldrhs r0, [r2, #0x8]
 *   @0x30cde2 strhs r0, [r3, #0x8]!
 *   @0x30cde6 ldrbhs r0, [r12, #-0x8]
 *   @0x30cdea strbhs r0, [r1, #-0x8]!
 *   @0x30cdee .word 0x01650008
 *   @0x30cdf2 strbths r0, [r3], #0
 *   @0x30cdf6 ldmle r12!, {r3} ^
 *   @0x30cdfa ldrths r0, [r11], #-13
 *   @0x30cdfe stmdb sp!, {r3}
 *   @0x30ce02 strdlt r4, r5, [r5], r0
 *   @0x30ce06 .word 0xf8df468a
 *   @0x30ce0a .word 0x9c0e1730
 *   @0x30ce0e ldrbtmi r2, [r9], #-519
 *   @0x30ce12 strmi r2, [r7], -r0, lsl #6
 *   @0x30ce16 bvs 0xc71a2a <b2_toiTime+0x518586>
 *   @0x30ce1a blhs 0xfe54a236 <b2_toiTime+0xfffffffffddf0d92>
 *   @0x30ce1e .word 0x9088f8db
 *   @0x30ce22 bl 0xffaca4ce <b2_toiTime+0xffffffffff37102a>
 *   @0x30ce26 ldmibvc r11!, {r3, r7, r8, r11, r12, sp, pc} ^
 *   @0x30ce2a svceq #0xdff013
 *   @0x30ce2e blhs 0x680f62 <g_SWFlinevertbuff+0x2de9a>
 *   @0x30ce32 bllo 0x580e42 <g_SWFlineaavertbuff+0x2dd7a>
 *   @0x30ce36 stmdale r8, {r0, r8, r9, r11, sp}
 *   @0x30ce3a .word 0x0108f107
 *   @0x30ce3e andeq pc, r8, #-2147483606
 *   @0x30ce42 .word 0xf7fe4628
 *   @0x30ce46 andls pc, r3, r3, lsr #30
 *   @0x30ce4a .word 0xf8d4e02e
 *   @0x30ce4e .word 0xf0188000
 *   @0x30ce52 eorsle r0, lr, r0, lsr #30
 *   @0x30ce56 usatne pc, #0x8, pc, asr #17
 *   @0x30ce5a andhs r4, r7, #56, #12
 *   @0x30ce5e .word 0xf5a94479
 *   @0x30ce62 stmdahs r0, {r1, r2, r3, r4, r5, r7, r8, r9, r11, sp, lr, pc}
 *   @0x30ce66 .word 0xf8dfd047
 *   @0x30ce6a .word 0x463816d8
 *   @0x30ce6e ldrbtmi r2, [r9], #-519
 *   @0x30ce72 bl 0xff0ca51e <b2_toiTime+0xfffffffffe97107a>
 *   @0x30ce76 ldmibvc r11!, {r3, r4, r6, r8, r11, r12, sp, pc} ^
 *   @0x30ce7a svceq #0xdff013
 *   @0x30ce7e addshi pc, r2, r0
 *   @0x30ce82 .word 0xf0002b0d
 *   @0x30ce86 bllo 0x56d0ca <g_SWFlineaavertbuff+0x1a002>
 *   @0x30ce8a .word 0xf2402b01
 *   @0x30ce8e .word 0xf018808b
 *   @0x30ce92 .word 0xf0000640
 *   @0x30ce96 stmibvs r3!, {r2, r3, r7, pc} ^
 *   @0x30ce9a .word 0xf0403301
 *   @0x30ce9e bvs 0x1bed0c6 <b2_toiTime+0x1493c22>
 *   @0x30cea2 blhs 0x327016
 *   @0x30cea6 addhi pc, r3, r0, asr #32
 *   @0x30ceaa .word 0xb1439b03
 *   @0x30ceae ldrbeq r6, [lr], -r3, lsr #16
 *   @0x30ceb2 strbmi sp, [r8], -r5, lsl #10
 *   @0x30ceb6 .word 0xf7da69a1
 *   @0x30ceba movwhs pc, #0xa3d
 *   @0x30cebe stmdals r3, {r0, r1, r5, r7, r8, sp, lr}
 *   @0x30cec2 pop {r0, r2, r12, sp, pc}
 *   @0x30cec6 blhs 0x330e8e
 *   @0x30ceca .word 0xf1aad1b6
 *   @0x30cece ldclne p2, c0, [r9, #28]!
 *   @0x30ced2 .word 0xf8dfe7b6
 *   @0x30ced6 shsub16mi r1, r8, r0
 *   @0x30ceda ldrbtmi r2, [r9], #-517
 *   @0x30cede bl 0xfe34a58a <b2_toiTime+0xfffffffffdbf10e6>
 *   @0x30cee2 ldmdbvc r11!, {r3, r4, r7, r8, r11, r12, sp, pc} ^
 *   @0x30cee6 svceq #0xdff013
 *   @0x30ceea blhs 0x680f3a <g_SWFlinevertbuff+0x2de72>
 *   @0x30ceee bllo 0x580f36 <g_SWFlineaavertbuff+0x2de6e>
 *   @0x30cef2 stmdale r10, {r0, r8, r9, r11, sp}
 *   @0x30cef6 ldmibvc r11!, {r2, r3, sp, lr, pc} ^
 *   @0x30cefa svceq #0xdff013
 *   @0x30cefe blhs 0x68103a <g_SWFlinevertbuff+0x2df72>
 *   @0x30cf02 bllo 0x581036 <g_SWFlineaavertbuff+0x2df6e>
 *   @0x30cf06 stmle lr!, {r0, r8, r9, r11, sp}
 *   @0x30cf0a .word 0x23b4e047
 *   @0x30cf0e strb r9, [r11, r3, lsl #6]
 *   @0x30cf12 .word 0x1638f8df
 *   @0x30cf16 strlo pc, [r8], -r4, lsl #10
 *   @0x30cf1a eoreq pc, r8, r6, lsl #2
 *   @0x30cf1e ldrbtmi r4, [r9], #-1594
 *   @0x30cf22 .word 0xf7fe4653
 *   @0x30cf26 andls pc, r3, r0, lsr #30
 *   @0x30cf2a .word 0xd1bd2800
 *   @0x30cf2e ldmdavs r8, {r0, r1, r4, r5, r7, r9, r11, sp, lr} ^
 *   @0x30cf32 mrc2 p7, #0x6, apsr_nzcv, c11, c14, #0x7
 *   @0x30cf36 .word 0x63282114
 *   @0x30cf3a rsbvs r4, r0, r7, lsl #12
 *   @0x30cf3e .word 0xf00b6bf0
 *   @0x30cf42 addmi lr, r7, #2080
 *   @0x30cf46 .word 0x6328bf84
 *   @0x30cf4a stmdavs r3!, {r5, r6, sp, lr} ^
 *   @0x30cf4e movths r11, #0x90b
 *   @0x30cf52 stmdavs r3!, {r0, r1, r3, r5, r8, r9, sp, lr} ^
 *   @0x30cf56 svcne #0x88f5b3
 *   @0x30cf5a movwhs sp, #0x6301
 *   @0x30cf5e andhs lr, r0, #56098816
 *   @0x30cf62 andls r10, r0, #3072
 *   @0x30cf66 movwls r4, #0x1648
 *   @0x30cf6a blvs 0xdd5402 <b2_toiTime+0x67bf5e>
 *   @0x30cf6e .word 0xf88ef7db
 *   @0x30cf72 .word 0x63a89b03
 *   @0x30cf76 orrsle r2, r7, r0, lsl #22
 *   @0x30cf7a .word 0xf0436823
 *   @0x30cf7e and r0, r10, r0, lsr #6
 *   @0x30cf82 strblo pc, [r12, #0x8df]
 *   @0x30cf86 blvs 0xfed1581e <b2_toiTime+0xfffffffffe5bc37a>
 *   @0x30cf8a blvs 0x1d5e17e <b2_toiTime+0x1604cda>
 *   @0x30cf8e bl 0xfecca63a <b2_toiTime+0xfffffffffe571196>
 *   @0x30cf92 .word 0xf0236823
 *   @0x30cf96 eorvs r0, r3, r1, lsl #6
 *   @0x30cf9a .word 0xf418e786
 *   @0x30cf9e rscle r6, pc, r12, ror pc
 *   @0x30cfa2 .word 0xe7b323ba
 *   @0x30cfa6 mvnvs r2, r0, lsl #6
 *   @0x30cfaa cmnvs r12, #40, #8
 *   @0x30cfae .word 0xf8dfe7f3
 *   @0x30cfb2 ldrtmi r1, [r8], -r0, lsr #11
 *   @0x30cfb6 ldrbtmi r2, [r9], #-521
 *   @0x30cfba bl 0x7ca666 <b2_toiTime+0x711c2>
 *   @0x30cfbe bvc 0x21fb4c6 <b2_toiTime+0x1aa2022>
 *   @0x30cfc2 svceq #0xdff013
 *   @0x30cfc6 blhs 0x681032 <g_SWFlinevertbuff+0x2df6a>
 *   @0x30cfca bllo 0x58102e <g_SWFlineaavertbuff+0x2df66>
 *   @0x30cfce ldmdble r4, {r0, r8, r9, r11, sp}
 *   @0x30cfd2 strne pc, [r4, #0x8df]
 *   @0x30cfd6 andhs r4, r8, #56, #12
 *   @0x30cfda .word 0xf5a94479
 *   @0x30cfde stmdahs r0, {r8, r9, r11, sp, lr, pc}
 *   @0x30cfe2 rschi pc, r5, r0, asr #32
 *   @0x30cfe6 .word 0xf0137a3b
 *   @0x30cfea ldrdle r0, r1, [r3], #-255
 *   @0x30cfee suble r2, r1, sp, lsl #22
 *   @0x30cff2 blhs 0x35bc1e
 *   @0x30cff6 sbcshi pc, r11, r0, lsl #4
 *   @0x30cffa .word 0xf418e03c
 *   @0x30cffe andle r6, r1, r12, ror r5
 *   @0x30d002 .word 0xe78323b5
 *   @0x30d006 stmibvs r1!, {r3, r6, r9, r10, lr}
 *   @0x30d00a strlo pc, [r8], -r4, lsl #10
 *   @0x30d00e .word 0xf992f7da
 *   @0x30d012 .word 0xf8df3628
 *   @0x30d016 .word 0x61a51544
 *   @0x30d01a shasxmi r4, r0, r10
 *   @0x30d01e usub16mi r4, r3, r9
 *   @0x30d022 mcr2 p7, #0x5, pc, c1, c14, #0x7
 *   @0x30d026 andls r4, r3, r5, lsl #12
 *   @0x30d02a .word 0xf47f2800
 *   @0x30d02e shasxmi r10, r0, sp
 *   @0x30d032 ldc2 p7, c15, [r9, #1020]
 *   @0x30d036 stmdbge r2, {r4, r5, r9, r10, lr}
 *   @0x30d03a blx 0xff68b040 <b2_toiTime+0xfffffffffef31b9c>
 *   @0x30d03e stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x30d042 subhi pc, lr, #0
 *   @0x30d046 movwls r10, #0x1b03
 *   @0x30d04a .word 0x21019b02
 *   @0x30d04e strbmi r9, [r8], -r0, lsl #10
 *   @0x30d052 strtmi r4, [r10], -r11, lsl #8
 *   @0x30d056 .word 0xf81af7db
 *   @0x30d05a lslvs r9, r3, #22
 *   @0x30d05e .word 0xf47f2b00
 *   @0x30d062 bls 0x3b8cf6 <error_g0017+0x1199a>
 *   @0x30d066 andlo r4, r1, #51380224
 *   @0x30d06a b 0xfed4a716 <b2_toiTime+0xfffffffffe5f1272>
 *   @0x30d06e .word 0xf0436823
 *   @0x30d072 ldr r0, [r0, r0, asr #6]
 *   @0x30d076 sbcle r2, r3, r0, lsl #28
 *   @0x30d07a strbtne pc, [r4], #2271
 *   @0x30d07e strlo pc, [r8], -r4, lsl #10
 *   @0x30d082 eoreq pc, r8, r6, lsl #2
 *   @0x30d086 ldrbtmi r4, [r9], #-1594
 *   @0x30d08a .word 0xf7fe4653
 *   @0x30d08e andls pc, r3, r12, ror #28
 *   @0x30d092 .word 0xf47f2800
 *   @0x30d096 bvs 0xff0f8cc2 <b2_toiTime+0xfffffffffe99f81e>
 *   @0x30d09a .word 0xf7fe6878
 *   @0x30d09e .word 0x1c42fb72
 *   @0x30d0a2 mvnvs r11, lr, lsr #31
 *   @0x30d0a6 .word 0x33fff04f
 *   @0x30d0aa stmibvs r3!, {r0, r1, r5, r6, r7, r8, sp, lr} ^
 *   @0x30d0ae .word 0xd1063301
 *   @0x30d0b2 blhs 0x3a7d86 <error_g0017+0xa2a>
 *   @0x30d0b6 ldmvs r8!, {r0, r1, r8, r11, r12, lr, pc}
 *   @0x30d0ba blx 0x1c0b0bc <b2_toiTime+0x14b1c18>
 *   @0x30d0be stmibvs r3!, {r5, r6, r7, r8, sp, lr} ^
 *   @0x30d0c2 svclt #0xbc3301
 *   @0x30d0c6 .word 0x33fff04f
 *   @0x30d0ca stmibvs r3!, {r0, r1, r5, r6, r7, r8, sp, lr} ^
 *   @0x30d0ce svcne #0x88f5b3
 *   @0x30d0d2 andhi pc, r6, #128, #4
 *   @0x30d0d6 blle 0x897cde <b2_toiTime+0x13e83a>
 *   @0x30d0da .word 0xf003115a
 *   @0x30d0de bl 0x40dd62 <g_RomDisk+0x16542>
 *   @0x30d0e2 bvs 0xfe74daf2 <b2_toiTime+0xfffffffffdff464e>
 *   @0x30d0e6 .word 0xf003fa21
 *   @0x30d0ea svceq #0x1f010
 *   @0x30d0ee andeq pc, r1, pc, asr #32
 *   @0x30d0f2 .word 0xf04fd005
 *   @0x30d0f6 strdvs r3, r4, [r3, #63]!
 *   @0x30d0fa addeq pc, r4, r11, lsr #17
 *   @0x30d0fe blx 0x345112
 *   @0x30d102 tstmi r9, #201326592
 *   @0x30d106 stmibvs r3!, {r0, r4, r7, r9, sp, lr} ^
 *   @0x30d10a blle 0xb17d12 <b2_toiTime+0x3be86e>
 *   @0x30d10e blvs 0xde7ebe <b2_toiTime+0x68ea1a>
 *   @0x30d112 .word 0xd111429a
 *   @0x30d116 strbmi r6, [r8], -r11, lsr #23
 *   @0x30d11a movwls r2, #0x124
 *   @0x30d11e movwls r10, #0x1b03
 *   @0x30d122 movteq pc, #0x102
 *   @0x30d126 .word 0xffb2f7da
 *   @0x30d12a .word 0x63a89b03
 *   @0x30d12e .word 0xf47f2b00
 *   @0x30d132 blvs 0xdf8c26 <b2_toiTime+0x69f782>
 *   @0x30d136 .word 0x632b3340
 *   @0x30d13a blvs 0xfeda7eee <b2_toiTime+0xfffffffffe64ea4a>
 *   @0x30d13e .word 0x63691c59
 *   @0x30d142 movtmi r2, #0xb124
 *   @0x30d146 ldmne r0, {r0, r5, r7, r8, r11, sp, lr} ^
 *   @0x30d14a stmibvs r3!, {r0, r4, r6, r7, r12, lr} ^
 *   @0x30d14e bvs 0x1c051da <b2_toiTime+0x14abd36>
 *   @0x30d152 movwlt r6, #0x385b
 *   @0x30d156 blvs 0xffde8206 <b2_toiTime+0xffffffffff68ed62>
 *   @0x30d15a .word 0xd110429a
 *   @0x30d15e strbmi r6, [r8], -r11, ror #24
 *   @0x30d162 movwls r2, #0x124
 *   @0x30d166 movwls r10, #0x1b03
 *   @0x30d16a .word 0xf7da1d13
 *   @0x30d16e blls 0x40cfb2 <g_RomDisk+0x15792>
 *   @0x30d172 blhs 0x32631a
 *   @0x30d176 mrcge p4, #0x4, apsr_nzcv, c8, c15, #0x3
 *   @0x30d17a movwlo r6, #0x4beb
 *   @0x30d17e stcvs p3, c6, [r11], #-940
 *   @0x30d182 stmibvs r1!, {r2, r5, r9, sp}
 *   @0x30d186 stclvs p3, c4, [r10], #-332
 *   @0x30d18a ldrsbpl r1, [r1], #128
 *   @0x30d18e mrrcne p12, #0x2, r6, r10, c11
 *   @0x30d192 subvs r6, r3, r10, lsr #8
 *   @0x30d196 strbmi lr, [r8], -r3
 *   @0x30d19a .word 0xf7da69a1
 *   @0x30d19e movwhs pc, #0x8cb
 *   @0x30d1a2 stmdavs r3!, {r0, r1, r5, r7, r8, sp, lr}
 *   @0x30d1a6 movtmi pc, #0x23
 *   @0x30d1aa orreq pc, r0, #67
 *   @0x30d1ae stmibvs r3!, {r0, r1, r4, r5, r6, r7, r9, r10, sp, lr, pc} ^
 *   @0x30d1b2 .word 0xf04f3301
 *   @0x30d1b6 .word 0xd1040324
 *   @0x30d1ba stclvs p12, c6, [r10], #-184
 *   @0x30d1be mcrlo p3, #0x1, r4, c4, c14, #0x2
 *   @0x30d1c2 blvs 0x1ec51d6 <b2_toiTime+0x176bd32>
 *   @0x30d1c6 cmpmi lr, #174080
 *   @0x30d1ca .word 0xf4183e24
 *   @0x30d1ce ldrmi r6, [r6], #-3840
 *   @0x30d1d2 stmvs r0!, {r2, r3, r5, r6, r12, lr, pc}
 *   @0x30d1d6 addsmi r8, r8, #3981312
 *   @0x30d1da .word 0xf1b8d30a
 *   @0x30d1de .word 0xf6ff0f00
 *   @0x30d1e2 .word 0xf048ae63
 *   @0x30d1e6 eorvs r4, r3, r0, lsl #6
 *   @0x30d1ea .word 0xf8ab2301
 *   @0x30d1ee ldrb r3, [r11], -r4, lsl #1
 *   @0x30d1f2 ldmibvs r2!, {r0, r1, r4, r5, r6, r7, r8, r11, sp, lr}
 *   @0x30d1f6 ldrsbeq r4, [r9], #-219
 *   @0x30d1fa andhs pc, r3, #0, #22
 *   @0x30d1fe movwhs r4, #0x47d
 *   @0x30d202 addmi r4, r11, #156, #12
 *   @0x30d206 ldclpl p0, c13, [r8], #144
 *   @0x30d20a ldmeq r0, {r0, r2, r8, r9, r11, sp, lr, pc} ^
 *   @0x30d20e umlalge pc, r1, r8, r8
 *   @0x30d212 stmdaeq r7, {r12, sp, lr, pc}
 *   @0x30d216 .word 0xf808fa4a
 *   @0x30d21a svceq #0x1f018
 *   @0x30d21e .word 0xf892d00f
 *   @0x30d222 stcpl p0, c8, [r8], #-0
 *   @0x30d226 andne lr, r8, r0, lsl #22
 *   @0x30d22a mrrcne p0, #0x1, r7, r8, c0
 *   @0x30d22e andle r4, r4, #136, #4
 *   @0x30d232 svclt #0x4407db
 *   @0x30d236 andgt pc, r1, r2, lsl #17
 *   @0x30d23a strmi r3, [r3], -r1, lsl #4
 *   @0x30d23e stmdavs r0!, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30d242 strle r0, [r5], #-69
 *   @0x30d246 addmi pc, r0, r0, asr #32
 *   @0x30d24a andhs r6, r1, r0, lsr #32
 *   @0x30d24e addeq pc, r4, r11, lsr #17
 *   @0x30d252 ldmibhi r5!, {r5, r9, r11, sp, lr}
 *   @0x30d256 addhs pc, r8, r0, lsl #10
 *   @0x30d25a strheq pc, [r6], r0
 *   @0x30d25e movtmi r11, #0x5155
 *   @0x30d262 ldmdavc r6, {r0, r6, r7, r11, lr}
 *   @0x30d266 .word 0xf0054478
 *   @0x30d26a strmi r0, [r5], #-1287
 *   @0x30d26e smulleq pc, r1, r5, r8
 *   @0x30d272 andsvc r4, r0, r0, lsr r0
 *   @0x30d276 tstle r5, r11, lsl #5
 *   @0x30d27a bmi 0xff1e466e <b2_toiTime+0xfffffffffea8b1ca>
 *   @0x30d27e bl 0x39e46e <t1_expert_encoding+0x8c>
 *   @0x30d282 .word 0xf00302d3
 *   @0x30d286 .word 0xf8920307
 *   @0x30d28a blx 0x1395516 <b2_toiTime+0xc3c072>
 *   @0x30d28e ldrbeq pc, [r9, r3, lsl #6]
 *   @0x30d292 stmdavs r3!, {r3, r8, r10, r12, lr, pc}
 *   @0x30d296 strle r0, [r5], #-90
 *   @0x30d29a orrmi pc, r0, #67
 *   @0x30d29e movwhs r6, #0x1023
 *   @0x30d2a2 addlo pc, r4, r11, lsr #17
 *   @0x30d2a6 movwlo r6, #0x18a3
 *   @0x30d2aa ldrb r6, [sp, #0xa3]!
 *   @0x30d2ae .word 0x463849b0
 *   @0x30d2b2 ldrbtmi r2, [r9], #-518
 *   @0x30d2b6 ldmib r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30d2ba ldmibvc r11!, {r6, r8, r11, r12, sp, pc}
 *   @0x30d2be svceq #0xdff013
 *   @0x30d2c2 blhs 0x68131e <g_SWFlinevertbuff+0x2e256>
 *   @0x30d2c6 bllo 0x58131a <g_SWFlineaavertbuff+0x2e252>
 *   @0x30d2ca ldmdble r0, {r0, r8, r9, r11, sp}
 *   @0x30d2ce ldrtmi r4, [r8], -r9, lsr #19
 *   @0x30d2d2 ldrbtmi r2, [r9], #-518
 *   @0x30d2d6 stmib r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30d2da ldmibvc r11!, {r6, r8, r9, r11, r12, sp, pc}
 *   @0x30d2de svceq #0xdff013
 *   @0x30d2e2 blhs 0x681366 <g_SWFlinevertbuff+0x2e29e>
 *   @0x30d2e6 bllo 0x581362 <g_SWFlineaavertbuff+0x2e29a>
 *   @0x30d2ea ldmdale pc, {r0, r8, r9, r11, sp}
 *   @0x30d2ee .word 0xf018e019
 *   @0x30d2f2 andsle r0, r9, r0, lsl #31
 *   @0x30d2f6 .word 0xf50449a0
 *   @0x30d2fa .word 0xf1053508
 *   @0x30d2fe ldrtmi r0, [r10], -r8, lsr #32
 *   @0x30d302 usub16mi r4, r3, r9
 *   @0x30d306 stc2 p7, c15, [pc, #-1016]!
 *   @0x30d30a stmdahs r0, {r0, r1, r12, pc}
 *   @0x30d30e stclge p4, c15, [r12, #508]
 *   @0x30d312 ldmdavs r8, {r0, r1, r3, r5, r7, r9, r11, sp, lr} ^
 *   @0x30d316 stc2l p7, c15, [r9], #1016
 *   @0x30d31a stmdavs r3!, {r4, r5, r8, pc}
 *   @0x30d31e orrvc pc, r0, #1124073472
 *   @0x30d322 .word 0xf018e639
 *   @0x30d326 tstle r5, r0, lsl #31
 *   @0x30d32a strb r2, [pc, #0x3b6]!
 *   @0x30d32e shadd8mi r4, r8, r3
 *   @0x30d332 ldrbtmi r2, [r9], #-515
 *   @0x30d336 ldmdb r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x30d33a .word 0xf0402800
 *   @0x30d33e ldmvc r11!, {r0, r6, r7, pc} ^
 *   @0x30d342 svceq #0xdff013
 *   @0x30d346 blhs 0x6813f2 <g_SWFlinevertbuff+0x2e32a>
 *   @0x30d34a bllo 0x5813ee <g_SWFlineaavertbuff+0x2e326>
 *   @0x30d34e .word 0xf2002b01
 *   @0x30d352 strht r8, [r2], -r7
 *   @0x30d356 .word 0xf504498a
 *   @0x30d35a .word 0xf1083808
 *   @0x30d35e ldrtmi r0, [r10], -r8, lsr #32
 *   @0x30d362 usub16mi r4, r3, r9
 *   @0x30d366 ldc2l p7, c15, [pc], #1016
 *   @0x30d36a stmdahs r0, {r0, r1, r12, pc}
 *   @0x30d36e ldcge p4, c15, [r12, #508]
 *   @0x30d372 .word 0x3028f8d8
 *   @0x30d376 .word 0xf7fe6858
 *   @0x30d37a ldrhhi pc, [r0, #-200]!
 *   @0x30d37e ldrbeq r6, [r11, #0x823]
 *   @0x30d382 stmdbvs r11!, {r0, r1, r2, r10, r12, lr, pc} ^
 *   @0x30d386 stmdbvs r10!, {r7, r9, r12, sp, pc}
 *   @0x30d38a cmpmi r10, #1753088
 *   @0x30d38e ldc2l p7, c15, [r5], {215}
 *   @0x30d392 stmdavs r3!, {r4, r5, r8, pc}
 *   @0x30d396 movwvc pc, #0x443
 *   @0x30d39a .word 0xf018e5fd
 *   @0x30d39e sbcle r0, r3, r0, lsl #31
 *   @0x30d3a2 .word 0xf5044978
 *   @0x30d3a6 .word 0xf1083808
 *   @0x30d3aa ldrtmi r0, [r10], -r8, lsr #32
 *   @0x30d3ae usub16mi r4, r3, r9
 *   @0x30d3b2 ldc2l p7, c15, [r9], {254}
 *   @0x30d3b6 stmdahs r0, {r0, r1, r12, pc}
 *   @0x30d3ba ldclge p4, c15, [r6, #-508]!
 *   @0x30d3be .word 0x3028f8d8
 *   @0x30d3c2 .word 0xf7fe6858
 *   @0x30d3c6 ldrhhi pc, [r0, r0]!
 *   @0x30d3ca .word 0x3028f8d8
 *   @0x30d3ce .word 0xf7fe6898
 *   @0x30d3d2 mvnshi pc, r10, lsr #25
 *   @0x30d3d6 .word 0xf8d84607
 *   @0x30d3da ldmvs r8, {r3, r5, r12, sp} ^
 *   @0x30d3de .word 0xf9f9f7fe
 *   @0x30d3e2 .word 0xf8d88230
 *   @0x30d3e6 ldmdbvs r8, {r3, r5, r12, sp}
 *   @0x30d3ea .word 0xf9f3f7fe
 *   @0x30d3ee addlt r8, r0, #112, #4
 *   @0x30d3f2 submi r4, r0, #117440512
 *   @0x30d3f6 adcslt r8, pc, #240, #4
 *   @0x30d3fa rfeib r4!
 *   @0x30d3fe eorslt r3, pc, #18
 *   @0x30d402 svclt #0xb8429f
 *   @0x30d406 rfeib r4!
 *   @0x30d40a rsbhi r3, r7, #20
 *   @0x30d40e ldrhhs pc, [r6], -r6
 *   @0x30d412 svclt #0xa8429a
 *   @0x30d416 adchi r4, r3, #19922944
 *   @0x30d41a ldmibhi r3!, {r1, r4, r5, r9, r11, pc}
 *   @0x30d41e rfeib r4!
 *   @0x30d422 addslt r2, r11, #16
 *   @0x30d426 andslt r8, r11, #805306382
 *   @0x30d42a svclt #0xb84293
 *   @0x30d42e eorhi r4, r3, #19922944
 *   @0x30d432 strhlo pc, [r12], -r4
 *   @0x30d436 ldrhhs pc, [r0], -r6
 *   @0x30d43a svclt #0xb8429a
 *   @0x30d43e .word 0x81a34613
 *   @0x30d442 strhlo pc, [lr], -r4
 *   @0x30d446 ldrhhs pc, [r0], -r6
 *   @0x30d44a svclt #0xa8429a
 *   @0x30d44e mvnhi r4, r3, lsl r6
 *   @0x30d452 ldreq r6, [pc, #0x823]
 *   @0x30d456 ldmibhi r3!, {r2, r3, r4, r6, r8, r9, r10, r11, r12, sp, pc}
 *   @0x30d45a bvs 0x1beda2e <b2_toiTime+0x149458a>
 *   @0x30d45e cmplt r11, #1769472
 *   @0x30d462 stmdbvs r10!, {r0, r1, r3, r5, r6, r8, r11, sp, lr}
 *   @0x30d466 ldmdbmi r3!, {r4, r5, r6, r8, r11, pc}
 *   @0x30d46a .word 0xf7d7435a
 *   @0x30d46e ldmdbhi r3!, {r1, r2, r5, r6, r10, r11, r12, sp, lr, pc}
 *   @0x30d472 addmi r11, r3, #128, #4
 *   @0x30d476 teqhi r0, r0, lsr #32
 *   @0x30d47a movwlo r6, #0x19e3
 *   @0x30d47e stcvs p1, c13, [r11], #-28
 *   @0x30d482 ldmdbeq r10, {r0, r8, r9, r11, r12, sp} ^
 *   @0x30d486 streq lr, [r2, #0xb05]
 *   @0x30d48a strlo pc, [r8, #-0x505]
 *   @0x30d48e ldmdavs r3!, {r0, r1, sp, lr, pc} ^
 *   @0x30d492 bl 0x451a02 <g_RomDisk+0x5a1e2>
 *   @0x30d496 andhs r0, r1, #545259520
 *   @0x30d49a tsteq pc, #3
 *   @0x30d49e vpmax.u8 d15, d3, d2
 *   @0x30d4a2 .word 0x2084f8d5
 *   @0x30d4a6 .word 0xf8c5431a
 *   @0x30d4aa stmdavs r3!, {r2, r7, sp}
 *   @0x30d4ae orrpl pc, r0, #1124073472
 *   @0x30d4b2 movwhs r6, #0x1023
 *   @0x30d4b6 addlo pc, r4, r11, lsr #17
 *   @0x30d4ba vst2.8 {d22, d23}, [r3:128], r3
 *   @0x30d4be strb r6, [r10, #-0x380]!
 *   @0x30d4c2 shasxmi r4, r8, r1
 *   @0x30d4c6 ldrbtmi r2, [r9], #-518
 *   @0x30d4ca stm r10, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30d4ce ldmibvc r11!, {r6, r8, r11, r12, sp, pc}
 *   @0x30d4d2 svceq #0xdff013
 *   @0x30d4d6 blhs 0x6814f6 <g_SWFlinevertbuff+0x2e42e>
 *   @0x30d4da bllo 0x5814f2 <g_SWFlineaavertbuff+0x2e42a>
 *   @0x30d4de stmdble r1, {r0, r8, r9, r11, sp}
 *   @0x30d4e2 ldr r2, [r3, #-0x303]
 *   @0x30d4e6 svcvs #0x80f418
 *   @0x30d4ea .word 0x23b7d101
 *   @0x30d4ee rfeia r11!
 *   @0x30d4f2 ldmibhi r3!, {r1, r2, r7, sp}
 *   @0x30d4f6 cmpmi r3, #3948544
 *   @0x30d4fa rscsvc pc, pc, #82837504
 *   @0x30d4fe sbcsne r3, r11, r7, lsl #6
 *   @0x30d502 addsmi r6, r3, #-1073741764
 *   @0x30d506 movtmi sp, #0xb802
 *   @0x30d50a stmdble r1, {r0, r1, r4, r7, r9, lr}
 *   @0x30d50e ldrbt r2, [sp], #952
 *   @0x30d512 andhs r8, r0, #855638016
 *   @0x30d516 andls r10, r0, #49152
 *   @0x30d51a strbmi r9, [r8], -r1, lsl #2
 *   @0x30d51e .word 0xf7da2101
 *   @0x30d522 blls 0x40cbfe <g_RomDisk+0x153de>
 *   @0x30d526 blhs 0x325bee
 *   @0x30d52a ldcge p4, c15, [lr], #508
 *   @0x30d52e stmdavs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x30d532 movwvs pc, #0x443
 *   @0x30d536 stmdbne r0, {r0, r1, r2, r3, r5, r8, r10, sp, lr, pc} ^
 *   @0x30d53a cmnhs r9, #1
 *   @0x30d53e orrhs r0, r10, #8
 *   @0x30d542 orrshs r0, r1, #8
 *   @0x30d546 movwhs r0, #0x6008
 *   @0x30d54a adcshs r0, pc, #8
 *   @0x30d54e ldm pc, {r3}
 *   @0x30d552 eorshs pc, r8, #1020
 *   @0x30d556 eorhs r0, pc, #8
 *   @0x30d55a bichs r0, r1, r8
 *   @0x30d55e cmphs r7, r8
 *   @0x30d562 strbvs r0, [lr, #-0x8]
 *   @0x30d566 strbtvs r0, [r6], #9
 *   @0x30d56a strbvs r0, [lr], #9
 *   @0x30d56e svcne #0x460009
 *   @0x30d572 svcne #0x3e0008
 *   @0x30d576 cdpne p0, #0xd, c0, c13, c8, #0x0
 *   @0x30d57a cdpne p0, #0xe, c0, c5, c8, #0x0
 *   @0x30d57e cdpne p0, #0x7, c0, c13, c8, #0x0
 *   @0x30d582 cdpne p0, #0x3, c0, c1, c8, #0x0
 *   @0x30d586 ldclne p0, c0, [r5, #-32]
 *   @0x30d58a stmdb sp!, {r3}
 *   @0x30d58e .word 0x469a4ff0
 *   @0x30d592 blmi 0xff2798ce <b2_toiTime+0xfffffffffeb2042a>
 *   @0x30d596 strmi r10, [r3], r6, lsl #26
 *   @0x30d59a ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x30d59e .word 0x460f9c56
 *   @0x30d5a2 ldmdavs r10, {r0, r1, r8, r9, r12, pc}
 *   @0x30d5a6 subls r6, r11, #155648
 *   @0x30d5aa eorvs r2, r10, r0, lsl #4
 *   @0x30d5ae .word 0xf506b126
 *   @0x30d5b2 .word 0xf8d32388
 *   @0x30d5b6 and r9, r0, r8, lsl #1
 *   @0x30d5ba ldmibmi r4!, {r0, r4, r5, r7, r9, r10, lr}
 *   @0x30d5be andhs r4, r7, #88, #12
 *   @0x30d5c2 .word 0xf5a94479
 *   @0x30d5c6 ldmdblt r0, {r2, r3, r11, sp, lr, pc} ^
 *   @0x30d5ca mullo r7, r11, r8
 *   @0x30d5ce svceq #0xdff013
 *   @0x30d5d2 blhs 0x6816ae <g_SWFlinevertbuff+0x2e5e6>
 *   @0x30d5d6 .word 0xf1a3d033
 *   @0x30d5da bhs 0x34de06
 *   @0x30d5de .word 0xf8d4d92f
 *   @0x30d5e2 .word 0xf0188000
 *   @0x30d5e6 tstle r5, r1, lsl #30
 *   @0x30d5ea .word 0xf50449aa
 *   @0x30d5ee ldrbmi r3, [r8], -r8, lsl #14
 *   @0x30d5f2 ldrbtmi r2, [r9], #-521
 *   @0x30d5f6 .word 0xf5a86bbe
 *   @0x30d5fa stmdahs r0, {r1, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x30d5fe .word 0xf89bd164
 *   @0x30d602 .word 0xf0133009
 *   @0x30d606 .word 0xd02e0fdf
 *   @0x30d60a eorle r2, r12, sp, lsl #22
 *   @0x30d60e blhs 0x35c23a
 *   @0x30d612 eor sp, r8, r10, asr r8
 *   @0x30d616 ldrbmi r4, [r8], -r0, lsr #19
 *   @0x30d61a ldrbtmi r2, [r9], #-527
 *   @0x30d61e svc #0xe0f5a8
 *   @0x30d622 .word 0xf0402800
 *   @0x30d626 .word 0xf89b80ad
 *   @0x30d62a .word 0xf013300f
 *   @0x30d62e .word 0xd06e0fdf
 *   @0x30d632 rsble r2, r12, sp, lsl #22
 *   @0x30d636 blhs 0x35c262
 *   @0x30d63a adchi pc, r2, r0, lsl #4
 *   @0x30d63e bvs 0x1bc57e2 <b2_toiTime+0x146c33e>
 *   @0x30d642 bhs 0x327892
 *   @0x30d646 mcrhs p0, #0x0, sp, c0, c7, #0x1
 *   @0x30d64a ldmdblt r11, {r0, r2, r4, r5, r12, lr, pc}
 *   @0x30d64e .word 0xf10b1ffa
 *   @0x30d652 and r0, r3, r7, lsl #2
 *   @0x30d656 .word 0x0108f10b
 *   @0x30d65a andeq pc, r8, #-1073741783
 *   @0x30d65e .word 0xf7fe4630
 *   @0x30d662 eorvs pc, r8, r5, lsl r11
 *   @0x30d666 movwhs lr, #0x1027
 *   @0x30d66a eorvs r4, r3, r0, lsr r6
 *   @0x30d66e movwhs r4, #0x62a
 *   @0x30d672 eorvs r4, r3, #2179072
 *   @0x30d676 ldc2l p7, c15, [r6, #-868]
 *   @0x30d67a stmiblt r3!, {r0, r1, r3, r5, r11, sp, lr} ^
 *   @0x30d67e .word 0xf5006220
 *   @0x30d682 blvs 0xff1958aa <b2_toiTime+0xfffffffffea3c406>
 *   @0x30d686 ldmeq r4, {r8, r12, sp, lr, pc}
 *   @0x30d68a .word 0xf8c04631
 *   @0x30d68e strbmi r2, [r0], -r8, lsl #1
 *   @0x30d692 .word 0xf7da63bb
 *   @0x30d696 eorvs pc, r8, r2, lsl lr
 *   @0x30d69a .word 0xf8dfb968
 *   @0x30d69e .word 0x460791fc
 *   @0x30d6a2 bl 0x55ea8e <g_SWFlineaavertbuff+0xb9c6>
 *   @0x30d6a6 ldrtmi r1, [r9], -r7, lsl #6
 *   @0x30d6aa .word 0x6c184642
 *   @0x30d6ae .word 0xf7da4633
 *   @0x30d6b2 eorvs pc, r8, r10, ror pc
 *   @0x30d6b6 stmdbls r3, {r3, r4, r6, r8, r12, sp, pc}
 *   @0x30d6ba stmdavs r8!, {r0, r1, r3, r6, r9, r11, r12, pc}
 *   @0x30d6be addsmi r6, r10, #720896
 *   @0x30d6c2 eorhi pc, r1, #0
 *   @0x30d6c6 svc #0x86f5a8
 *   @0x30d6ca .word 0x602b23b0
 *   @0x30d6ce .word 0x3701e7f3
 *   @0x30d6d2 mvnle r2, r3, asr pc
 *   @0x30d6d6 tsths r8, r0, lsr r6
 *   @0x30d6da bvs 0xcdef8a <b2_toiTime+0x585ae6>
 *   @0x30d6de stc2 p7, c15, [r2, #-868]!
 *   @0x30d6e2 .word 0xf8c7682b
 *   @0x30d6e6 blhs 0x30d8ee <af_shaper_get_elem+0x315c>
 *   @0x30d6ea bvs 0xc01e86 <b2_toiTime+0x4a89e2>
 *   @0x30d6ee .word 0xf8d34631
 *   @0x30d6f2 .word 0xf7da0080
 *   @0x30d6f6 eorvs pc, r8, r2, ror #27
 *   @0x30d6fa bicsle r2, r12, r0, lsl #16
 *   @0x30d6fe bvs 0xbe808e <b2_toiTime+0x48ebea>
 *   @0x30d702 ldrsbvs r6, [r10, #130]
 *   @0x30d706 rscslo pc, pc, #79
 *   @0x30d70a subsvs r6, r10, #143360
 *   @0x30d70e .word 0xf018e7d3
 *   @0x30d712 rsbsle r0, lr, r8, lsl #30
 *   @0x30d716 .word 0xf5044962
 *   @0x30d71a .word 0xf1083808
 *   @0x30d71e ldrbmi r0, [r10], -r8, lsr #32
 *   @0x30d722 shsub16mi r4, r11, r9
 *   @0x30d726 blx 0xb0b728 <b2_toiTime+0x3b2284>
 *   @0x30d72a eorvs r4, r8, r6, lsl #12
 *   @0x30d72e bicle r2, r2, r0, lsl #16
 *   @0x30d732 .word 0x3028f8d8
 *   @0x30d736 ldmdavs r8, {r0, r1, r2, r5, r9, r11, sp, lr} ^
 *   @0x30d73a blx 0xff90b73a <b2_toiTime+0xffffffffff1b2296>
 *   @0x30d73e .word 0x460364b8
 *   @0x30d742 .word 0xf8d86060
 *   @0x30d746 bvs 0xcd583e <b2_toiTime+0x57c39a>
 *   @0x30d74a svceq #0x92ebb0
 *   @0x30d74e ldrtvs sp, [lr], #2306
 *   @0x30d752 ldr r2, [r10, r6, lsl #6]!
 *   @0x30d756 strbmi r9, [r8], -r0, lsl #12
 *   @0x30d75a tsths r0, r1, lsl #10
 *   @0x30d75e .word 0xf7da4632
 *   @0x30d762 stmdavs r11!, {r0, r2, r4, r7, r10, r11, r12, sp, lr, pc}
 *   @0x30d766 tstlt r3, r8, lsr r5
 *   @0x30d76a ldrvs r6, [lr], #2595
 *   @0x30d76e stmdavs r3!, {r0, r1, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30d772 tsteq r0, #67
 *   @0x30d776 blmi 0x15a580a <b2_toiTime+0xe4c366>
 *   @0x30d77a .word 0xf8ca447b
 *   @0x30d77e ldr r3, [r10, r0]
 *   @0x30d782 ldrbmi r4, [r8], -r9, asr #18
 *   @0x30d786 ldrbtmi r2, [r9], #-527
 *   @0x30d78a svc #0x2af5a8
 *   @0x30d78e .word 0xf89bb948
 *   @0x30d792 .word 0xf013300f
 *   @0x30d796 ldrsbtle r0, [lr], -pc
 *   @0x30d79a eorsle r2, r12, sp, lsl #22
 *   @0x30d79e blhs 0x35c3ca
 *   @0x30d7a2 stmdbmi r1, {r0, r3, r4, r5, r8, r11, r12, lr, pc} ^
 *   @0x30d7a6 andhs r4, r4, #88, #12
 *   @0x30d7aa .word 0xf5a84479
 *   @0x30d7ae stmdblt r8, {r3, r4, r8, r9, r10, r11, sp, lr, pc} ^
 *   @0x30d7b2 mullo r4, r11, r8
 *   @0x30d7b6 svceq #0xdff013
 *   @0x30d7ba blhs 0x6819be <g_SWFlinevertbuff+0x2e8f6>
 *   @0x30d7be bllo 0x5819ba <g_SWFlineaavertbuff+0x2e8f2>
 *   @0x30d7c2 ldmdble r10!, {r0, r8, r9, r11, sp} ^
 *   @0x30d7c6 uasxmi r4, r8, r10
 *   @0x30d7ca ldrbtmi r2, [r9], #-516
 *   @0x30d7ce svc #0x8f5a8
 *   @0x30d7d2 .word 0xf89bb960
 *   @0x30d7d6 .word 0xf0133004
 *   @0x30d7da .word 0xf0000fdf
 *   @0x30d7de blhs 0x66dc26 <g_SWFlinevertbuff+0x1ab5e>
 *   @0x30d7e2 mrshi pc, apsr
 *   @0x30d7e6 blhs 0x35c412
 *   @0x30d7ea .word 0x8109f240
 *   @0x30d7ee uasxmi r4, r8, r1
 *   @0x30d7f2 ldrbtmi r2, [r9], #-517
 *   @0x30d7f6 cdp p5, #0xf, c15, c4, c8, #0x5
 *   @0x30d7fa .word 0xf0402800
 *   @0x30d7fe .word 0xf89b8149
 *   @0x30d802 .word 0xf0133005
 *   @0x30d806 .word 0xf0400fdf
 *   @0x30d80a .word 0xf01880f3
 *   @0x30d80e .word 0xf0400f08
 *   @0x30d812 .word 0x23b38141
 *   @0x30d816 .word 0xf018e759
 *   @0x30d81a .word 0xd1010f04
 *   @0x30d81e .word 0xe75423b2
 *   @0x30d822 .word 0xf5044925
 *   @0x30d826 .word 0xf1063608
 *   @0x30d82a ldrbmi r0, [r10], -r8, lsr #32
 *   @0x30d82e shsub16mi r4, r11, r9
 *   @0x30d832 blx 0xfe98b832 <b2_toiTime+0xfffffffffe23238e>
 *   @0x30d836 stmdahs r0, {r3, r5, sp, lr}
 *   @0x30d83a svcge #0x3df47f
 *   @0x30d83e bvs 0xce8312 <b2_toiTime+0x58ee6e>
 *   @0x30d842 .word 0xf7fe6858
 *   @0x30d846 adcshi pc, r8, r0, ror r10
 *   @0x30d84a bvs 0xce831e <b2_toiTime+0x58ee7a>
 *   @0x30d84e .word 0xf7fe6898
 *   @0x30d852 rscshi pc, r8, r10, ror #20
 *   @0x30d856 bvs 0xce832a <b2_toiTime+0x58ee86>
 *   @0x30d85a .word 0xf7fd68d8
 *   @0x30d85e ldrhhi pc, [r8, -r10]!
 *   @0x30d862 bvs 0xce8336 <b2_toiTime+0x58ee92>
 *   @0x30d866 .word 0xf7fd6918
 *   @0x30d86a ldrhhi pc, [r8, #-244]!
 *   @0x30d86e ldmdbhi r9, {r0, r1, r5, r9, r11, sp, lr} ^
 *   @0x30d872 strmi r8, [r10], #-2266
 *   @0x30d876 bvs 0xbedee6 <b2_toiTime+0x494a42>
 *   @0x30d87a subsmi r8, r2, #1474560
 *   @0x30d87e stmdavs r3!, {r1, r3, r4, r6, r7, r8, pc}
 *   @0x30d882 movweq pc, #0x8043
 *   @0x30d886 adcmi lr, r12, r5, rrx
 *   @0x30d88a .word 0x03ba0004
 *   @0x30d88e blne 0xff4cd8ce <b2_toiTime+0xfffffffffed7442a>
 *   @0x30d892 ldcne p0, c0, [r0], #-32
 *   @0x30d896 .word 0x1c120008
 *   @0x30d89a svcgt #0x720008
 *   @0x30d89e bne 0xff24d8da <b2_toiTime+0xfffffffffeaf4436>
 *   @0x30d8a2 .word 0xf41f0008
 *   @0x30d8a6 bne 0xff0cd8aa <b2_toiTime+0xfffffffffe974406>
 *   @0x30d8aa bne 0xfec0d8d2 <b2_toiTime+0xfffffffffe4b442e>
 *   @0x30d8ae bne 0xfe4cd8d6 <b2_toiTime+0xfffffffffdd74432>
 *   @0x30d8b2 stmibne lr!, {r3} ^
 *   @0x30d8b6 ldmibne r1!, {r3}
 *   @0x30d8ba .word 0xf5040008
 *   @0x30d8be ldmibmi r3, {r3, r11, r12, sp}
 *   @0x30d8c2 stmdaeq r8!, {r3, r8, r12, sp, lr, pc}
 *   @0x30d8c6 ldrbtmi r4, [r9], #-1626
 *   @0x30d8ca .word 0x4640463b
 *   @0x30d8ce blx 0x160b8ce <b2_toiTime+0xeb242a>
 *   @0x30d8d2 eorvs r4, r8, r6, lsl #12
 *   @0x30d8d6 .word 0xf47f2800
 *   @0x30d8da svcge #0x5aeee
 *   @0x30d8de .word 0xf7ff4640
 *   @0x30d8e2 strbmi pc, [r0], -r2, asr #18
 *   @0x30d8e6 .word 0xf7fe4639
 *   @0x30d8ea sxtab16mi pc, r2, r6, ror #24
 *   @0x30d8ee .word 0xf0002800
 *   @0x30d8f2 bvs 0xbedc36 <b2_toiTime+0x494792>
 *   @0x30d8f6 ldmdavs r9, {r3, r6, r9, r10, lr}
 *   @0x30d8fa ldc2 p7, c15, [r12, #-868]
 *   @0x30d8fe .word 0x21016a23
 *   @0x30d902 ldrtmi r4, [r2], -r8, asr #12
 *   @0x30d906 ldmdavs r11!, {r1, r2, r3, r4, sp, lr}
 *   @0x30d90a .word 0x8020f8d4
 *   @0x30d90e strls r4, [r0], -r11, lsl #8
 *   @0x30d912 .word 0xf7da9501
 *   @0x30d916 .word 0xf8c8fbbb
 *   @0x30d91a .word 0xf8d50000
 *   @0x30d91e .word 0xf1b88000
 *   @0x30d922 .word 0xf47f0f00
 *   @0x30d926 bvs 0xbf944e <b2_toiTime+0x49ffaa>
 *   @0x30d92a ldmdavs r10!, {r0, r4, r6, r9, r10, lr}
 *   @0x30d92e andlo r6, r1, #24, #16
 *   @0x30d932 cdp p5, #0x4, c15, c4, c8, #0x5
 *   @0x30d936 .word 0xf8d46a26
 *   @0x30d93a stmdblt r6!, {r2, r5, sp, pc} ^
 *   @0x30d93e stmdaeq r6, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30d942 andhi pc, r0, r5, asr #17
 *   @0x30d946 svceq #0xf1b8
 *   @0x30d94a mrcge p4, #0x5, apsr_nzcv, c5, c15, #0x3
 *   @0x30d94e .word 0xf0436823
 *   @0x30d952 eorvs r0, r3, r2, lsl #6
 *   @0x30d956 ldmdavs r3!, {r0, r1, r2, r3, r5, r7, r9, r10, sp, lr, pc}
 *   @0x30d95a rscle r2, pc, r0, lsl #22
 *   @0x30d95e blhs 0x32b9d2
 *   @0x30d962 .word 0xf506d0ec
 *   @0x30d966 svcge #0x72388
 *   @0x30d96a andshs r4, r0, #68157440
 *   @0x30d96e .word 0x9088f8d3
 *   @0x30d972 .word 0xf5a84638
 *   @0x30d976 .word 0xf8c7ee1c
 *   @0x30d97a .word 0xf8da900c
 *   @0x30d97e .word 0xf8d6300c
 *   @0x30d982 mvnsvs r9, r0
 *   @0x30d986 .word 0xf5a84648
 *   @0x30d98a .word 0xf100edd6
 *   @0x30d98e .word 0xf1b80801
 *   @0x30d992 ldmle r3, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} ^
 *   @0x30d996 strbmi r10, [r2], -r11, lsl #22
 *   @0x30d99a ldrmi r4, [r8], -r9, asr #12
 *   @0x30d99e cdp p5, #0x0, c15, c14, c8, #0x5
 *   @0x30d9a2 ldrbtmi r4, [r9], #-2396
 *   @0x30d9a6 ldrtmi r4, [r8], -r3, lsl #12
 *   @0x30d9aa .word 0x4643461a
 *   @0x30d9ae .word 0xf9dbf7fe
 *   @0x30d9b2 stmiblt r8, {r7, r9, r10, lr} ^
 *   @0x30d9b6 blhs 0x6e7caa <g_SWFvertbuff+0x14be2>
 *   @0x30d9ba ldmdavs r11!, {r1, r2, r4, r8, r12, lr, pc}
 *   @0x30d9be ldmdavc r11, {r0, r1, r3, r4, r6, r7, r9, r11, sp, lr}
 *   @0x30d9c2 andle r2, pc, r0, asr r11
 *   @0x30d9c6 blhs 0x14039de <b2_toiTime+0xcaa53a>
 *   @0x30d9ca blhs 0x16819f2 <b2_toiTime+0xf2854e>
 *   @0x30d9ce and sp, r11, r8
 *   @0x30d9d2 andle r2, r5, sp, ror #22
 *   @0x30d9d6 andle r2, r5, r0, ror r11
 *   @0x30d9da .word 0xd1052b63
 *   @0x30d9de and r2, r2, r0, lsr #6
 *   @0x30d9e2 and r2, r0, r0, lsl r3
 *   @0x30d9e6 mvnsvs r2, r8, lsl #6
 *   @0x30d9ea .word 0xf7fe4638
 *   @0x30d9ee .word 0xe7a7f93f
 *   @0x30d9f2 .word 0xf43f2b0d
 *   @0x30d9f6 bllo 0x579626 <g_SWFlineaavertbuff+0x2655e>
 *   @0x30d9fa stmdale r9, {r0, r8, r9, r11, sp} ^
 *   @0x30d9fe .word 0xf018e705
 *   @0x30da02 .word 0xd1010f02
 *   @0x30da06 .word 0xe66023b1
 *   @0x30da0a .word 0xf5044943
 *   @0x30da0e .word 0xf1063608
 *   @0x30da12 ldrbmi r0, [r10], -r8, lsr #32
 *   @0x30da16 shsub16mi r4, r11, r9
 *   @0x30da1a .word 0xf9a5f7fe
 *   @0x30da1e stmdahs r0, {r3, r5, sp, lr}
 *   @0x30da22 mcrge p4, #0x2, pc, c9, c15, #0x3
 *   @0x30da26 bvs 0xce84fa <b2_toiTime+0x58f056>
 *   @0x30da2a .word 0xf7fe6858
 *   @0x30da2e teqvs r8, lr, asr r9
 *   @0x30da32 bvs 0xce8506 <b2_toiTime+0x58f062>
 *   @0x30da36 .word 0xf7fe6898
 *   @0x30da3a cmnvs r8, r8, asr r9
 *   @0x30da3e bvs 0xce8512 <b2_toiTime+0x58f06e>
 *   @0x30da42 .word 0xf7fe68d8
 *   @0x30da46 .word 0x61b8f952
 *   @0x30da4a bvs 0xce871e <b2_toiTime+0x58f27a>
 *   @0x30da4e tstle r6, r5, lsl #22
 *   @0x30da52 ldmdbvs r8, {r0, r1, r4, r5, r7, r9, r11, sp, lr}
 *   @0x30da56 mrc2 p7, #0x5, apsr_nzcv, c13, c13, #0x7
 *   @0x30da5a stmdahs r4, {r7, r9, r12, sp, pc}
 *   @0x30da5e .word 0xf507d903
 *   @0x30da62 movwhs r2, #0x8788
 *   @0x30da66 stmdahs r2, {r1, r2, r3, sp, lr, pc}
 *   @0x30da6a .word 0xf507d903
 *   @0x30da6e movwhs r2, #0x4788
 *   @0x30da72 .word 0xd104e008
 *   @0x30da76 strhs pc, [r8, r7, lsl #10]
 *   @0x30da7a addeq pc, r6, r7, lsr #17
 *   @0x30da7e .word 0xf507e004
 *   @0x30da82 movwhs r2, #0x1788
 *   @0x30da86 addlo pc, r6, r7, lsr #17
 *   @0x30da8a .word 0xf0436823
 *   @0x30da8e strb r0, [r0, -r4, lsl #6]!
 *   @0x30da92 ldr r2, [r10], -r3, lsl #6
 *   @0x30da96 strhlo pc, [r12], -r6
 *   @0x30da9a adcsvs r4, r3, #32, #30
 *   @0x30da9e bvs 0xbdeca2 <b2_toiTime+0x4857fe>
 *   @0x30daa2 ldrtmi r10, [r9], -r11, lsl #28
 *   @0x30daa6 rfeib r3!
 *   @0x30daaa .word 0xf5a8200c
 *   @0x30daae ldmdbmi r11, {r4, r6, r8, r10, r11, sp, lr, pc}
 *   @0x30dab2 ldrtmi r6, [r2], -r0, lsr #20
 *   @0x30dab6 .word 0xf7fe4479
 *   @0x30daba .word 0x6028feb8
 *   @0x30dabe .word 0xf47f2800
 *   @0x30dac2 bvs 0xbf92b2 <b2_toiTime+0x49fe0e>
 *   @0x30dac6 shasxmi r4, r0, r9
 *   @0x30daca strhhs pc, [lr], -r3
 *   @0x30dace bvs 0xbe663e <b2_toiTime+0x48d19a>
 *   @0x30dad2 strhhs pc, [lr], -r3
 *   @0x30dad6 ldc p5, c15, [r12, #-672]!
 *   @0x30dada bvs 0xb1ff2a <b2_toiTime+0x3c6a86>
 *   @0x30dade ldrbtmi r4, [r9], #-1586
 *   @0x30dae2 mcr2 p7, #0x5, pc, c3, c14, #0x7
 *   @0x30dae6 stmdahs r0, {r3, r5, sp, lr}
 *   @0x30daea stclge p4, c15, [r5, #508]!
 *   @0x30daee andhs r6, r1, #143360
 *   @0x30daf2 orrhs pc, r8, #12582912
 *   @0x30daf6 addhs pc, r4, r3, lsr #17
 *   @0x30dafa ldrbtmi r4, [r11], #-2827
 *   @0x30dafe andlo pc, r0, r10, asr #17
 *   @0x30db02 .word 0x33fff04f
 *   @0x30db06 sublt lr, sp, r1, ror #11
 *   @0x30db0a svchi #0xf0e8bd
 *   @0x30db0e ldmdbne r7, {r8, r9, r10, r11, r12, sp, pc}
 *   @0x30db12 strb r0, [pc], -r8
 *   @0x30db16 strbne r0, [r9, r7]
 *   @0x30db1a strne r0, [r7, -r8]!
 *   @0x30db1e strbtne r0, [r8], r8
 *   @0x30db22 strbne r0, [r10], r8
 *   @0x30db26 vhadd.u8 d0, d1, d8
 *   @0x30db2a stmdavs r3, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30db2e adclo pc, r0, #13828096
 *   @0x30db32 msrvc CPSR_sxc, #12582912
 *   @0x30db36 andhs r6, r0, r3, lsl #2
 *   @0x30db3a movwhs r4, #0x770
 *   @0x30db3e ldrbmi r6, [r0, -r3, lsl #2]!
 *   @0x30db42 svclt #0x9a29ff
 *   @0x30db46 rfeda r3!
 *   @0x30db4a andhs r0, r0, r1, lsl r0
 *   @0x30db4e stmdavs r10, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x30db52 andvs r2, r11, r0, lsl #6
 *   @0x30db56 stmdale sp, {r1, r2, r3, r4, r5, r6, r7, r9, r11, sp}
 *   @0x30db5a mrrcne p9, #0x0, r6, r3, c0
 *   @0x30db5e subeq lr, r2, #0, #22
 *   @0x30db62 svceq #0x2f832
 *   @0x30db66 andvs r11, r11, r8, lsl #2
 *   @0x30db6a movwlo r4, #0x1770
 *   @0x30db6e svcvc #0x80f5b3
 *   @0x30db72 .word 0x4770d1f6
 *   @0x30db76 .word 0x47704618
 *   @0x30db7a ldrlt r0, [r7, #-0x0]!
 *   @0x30db7e stmdavs r2, {r0, r9, r10, lr}
 *   @0x30db82 adclo pc, r0, #13762560
 *   @0x30db86 .word 0xf8d36e50
 *   @0x30db8a .word 0xf8d344a4
 *   @0x30db8e mrslt r5, spsr
 *   @0x30db92 strhs r9, [r0], #-513
 *   @0x30db96 ldmdbvs r10, {r10, r12, pc} ^
 *   @0x30db9a stmdavs r12!, {r2, r8, r9, r11, lr} ^
 *   @0x30db9e .word 0x47a0447b
 *   @0x30dba2 adchs lr, r3, r0
 *   @0x30dba6 ldclt p0, c11, [r0, #-12]!
 *   @0x30dbaa ldmhs r1!, {r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x30dbae strlt r0, [r8, #-0x0]
 *   @0x30dbb2 .word 0xf8d36803
 *   @0x30dbb6 .word 0xf8d332a0
 *   @0x30dbba ldmvs r11, {r2, r3, r10, r11, r12, sp}
 *   @0x30dbbe stclt p7, c4, [r8, #-608]
 *   @0x30dbc2 stmdavs r3, {r3, r8, r10, r12, sp, pc}
 *   @0x30dbc6 adclo pc, r0, #13828096
 *   @0x30dbca .word 0x3c0cf8d3
 *   @0x30dbce .word 0x479868db
 *   @0x30dbd2 ldrlt r11, [r8, #-0xd08]!
 *   @0x30dbd6 .word 0xf8d0461c
 *   @0x30dbda strhs r3, [r0, #-0x21c]
 *   @0x30dbde rsbvs r6, r5, r5, lsr #32
 *   @0x30dbe2 ldclvs p1, c11, [r11, #-76]
 *   @0x30dbe6 mlavs r0, r8, r7, r4
 *   @0x30dbea ldclt p0, c2, [r8, #-0]!
 *   @0x30dbee vmlal.u8 q11, d16, d0
 *   @0x30dbf2 ldrbmi r2, [r0, -r0, asr #32]!
 *   @0x30dbf6 adclo pc, r0, #208, #16
 *   @0x30dbfa andvc r2, r10, r0, lsl #4
 *   @0x30dbfe .word 0xf8d3b13b
 *   @0x30dc02 .word 0xf64f25e0
 *   @0x30dc06 addsmi r7, r10, #-67108861
 *   @0x30dc0a movwhs r11, #0x1f1c
 *   @0x30dc0e andhs r7, r0, r11
 *   @0x30dc12 ldrlt r4, [r0, #-0x770]
 *   @0x30dc16 adclo pc, r0, #208, #16
 *   @0x30dc1a .word 0xf8d3b173
 *   @0x30dc1e .word 0xf64f05e0
 *   @0x30dc22 adcmi r7, r0, #-16777216
 *   @0x30dc26 ldmdbvs r8, {r1, r3, r12, lr, pc} ^
 *   @0x30dc2a stmdale r7, {r0, r7, r9, lr}
 *   @0x30dc2e strtlo pc, [r4], #2259
 *   @0x30dc32 andslo pc, r1, r3, lsr r8
 *   @0x30dc36 andsvs r11, r3, r2, lsl #2
 *   @0x30dc3a ldclt p0, c2, [r0, #-0]
 *   @0x30dc3e ldclt p0, c2, [r0, #-24]
 *   @0x30dc42 .word 0xf8d0b508
 *   @0x30dc46 ldmvs r11, {r2, r5, r9, r12, sp}
 *   @0x30dc4a stclt p7, c4, [r8, #-608]
 *   @0x30dc4e .word 0xf8d0b508
 *   @0x30dc52 ldmvs r11, {r2, r5, r9, r12, sp} ^
 *   @0x30dc56 stclt p7, c4, [r8, #-608]
 *   @0x30dc5a .word 0xf8d0b508
 *   @0x30dc5e ldmdbvs r11, {r2, r5, r9, r12, sp}
 *   @0x30dc62 stclt p7, c4, [r8, #-608]
 *   @0x30dc66 .word 0xf8d0b508
 *   @0x30dc6a ldmdbvs r11, {r2, r5, r9, r12, sp} ^
 *   @0x30dc6e stclt p7, c4, [r8, #-608]
 *   @0x30dc72 .word 0xf8d0b508
 *   @0x30dc76 ldmibvs r11, {r2, r5, r9, r12, sp}
 *   @0x30dc7a stclt p7, c4, [r8, #-608]
 *   @0x30dc7e .word 0xf8d0b508
 *   @0x30dc82 ldmdavs r11, {r3, r5, r9, r12, sp}
 *   @0x30dc86 stclt p7, c4, [r8, #-608]
 *   @0x30dc8a .word 0xf8d0b508
 *   @0x30dc8e ldmibvs r11, {r3, r5, r9, r12, sp} ^
 *   @0x30dc92 stclt p7, c4, [r8, #-608]
 *   @0x30dc96 stmdbvs r4, {r4, r5, r6, r7, r8, r10, r12, sp, pc} ^
 *   @0x30dc9a umaaleq pc, r1, r0, r8
 *   @0x30dc9e rfeib r4!
 *   @0x30dca2 addne r0, r9, #2
 *   @0x30dca6 addsne r6, r2, #6619136
 *   @0x30dcaa blhs 0x327f4a
 *   @0x30dcae movwhs r11, #0x2f0c
 *   @0x30dcb2 bl 0x4568be <g_RomDisk+0x5f09e>
 *   @0x30dcb6 .word 0xf84507c0
 *   @0x30dcba rsbsvs r1, r10, r0, lsr r0
 *   @0x30dcbe stmdahi r3!, {r0, r1, r4, r5, r10, r12, lr} ^
 *   @0x30dcc2 rsbhi r3, r3, r1, lsl #6
 *   @0x30dcc6 stmdavc r3, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x30dcca .word 0xd1082b1c
 *   @0x30dcce addsmi r1, r9, #49920
 *   @0x30dcd2 stmdavc r2, {r4, r5, r8, r9, r12, lr, pc} ^
 *   @0x30dcd6 b 0x13ebeea <b2_toiTime+0xc92a46>
 *   @0x30dcda andlt r2, r0, #2
 *   @0x30dcde blhs 0xa5faa6 <b2_toiTime+0x306602>
 *   @0x30dce2 stclne p1, c13, [r3, #-52]
 *   @0x30dce6 .word 0xd3254299
 *   @0x30dcea stmdavc r2, {r0, r1, r7, r11, r12, sp, lr} ^
 *   @0x30dcee b 0x13ced62 <b2_toiTime+0xc758be>
 *   @0x30dcf2 stmdbvc r2, {r1, r8, r9, sp, lr}
 *   @0x30dcf6 tstmi r3, #192, #16
 *   @0x30dcfa andhs lr, r0, r3, asr #20
 *   @0x30dcfe blhs 0x9fac6
 *   @0x30dd02 .word 0xf1a3dc02
 *   @0x30dd06 ldrbmi r0, [r0, -r11, lsl #1]!
 *   @0x30dd0a .word 0xf1002bfa
 *   @0x30dd0e .word 0xdc080202
 *   @0x30dd12 movwle r4, #0xf291
 *   @0x30dd16 bl 0x32be1e
 *   @0x30dd1a .word 0xf5a02003
 *   @0x30dd1e ldmlo r4, {r1, r2, r4, r5, r6, lr}
 *   @0x30dd22 addsmi r4, r1, #112, #14
 *   @0x30dd26 .word 0xf1c3d306
 *   @0x30dd2a stmdavc r2, {r0, r1, r3, r4, r5, r6, r7, r8, r9} ^
 *   @0x30dd2e bne 0xfe90e5a2 <b2_toiTime+0xfffffffffe1b50fe>
 *   @0x30dd32 ldrbmi r3, [r0, -r12, ror #16]!
 *   @0x30dd36 ldrbmi r2, [r0, -r0]!
 *   @0x30dd3a .word 0x4603b5f0
 *   @0x30dd3e movtlt r6, #0x880
 *   @0x30dd42 tstlt r2, r10, lsl r8
 *   @0x30dd46 andle r2, r2, r3, lsl #20
 *   @0x30dd4a mcrrpl p0, #0x2, lr, r0, c2
 *   @0x30dd4e ldmdbvs r10, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x30dd52 ldmdbvs r10, {r2, r3, r7, r9, r11, r12} ^
 *   @0x30dd56 andle r4, r1, #148, #4
 *   @0x30dd5a ldcllt p14, c7, [r0, #96]!
 *   @0x30dd5e stmdavc r2, {r2, r11, r12, sp, lr} ^
 *   @0x30dd62 b 0x13a80e2 <b2_toiTime+0xc4ec3e>
 *   @0x30dd66 adcmi r2, r1, #4, #8
 *   @0x30dd6a stcne p3, c13, [r2], {18}
 *   @0x30dd6e ldmdavc r7, {r1, r2, r10, lr} ^
 *   @0x30dd72 ldmdavc r0, {r0, r2, r4, r7, r11, r12, sp, lr}
 *   @0x30dd76 strhs lr, [r7, #-0xa45]
 *   @0x30dd7a andle r4, r4, #-1879048182
 *   @0x30dd7e blne 0xe261f6 <b2_toiTime+0x6ccd52>
 *   @0x30dd82 cmpvs r12, r8, lsl r6
 *   @0x30dd86 andlo r11, r3, #240, #26
 *   @0x30dd8a andle r4, r1, #536870923
 *   @0x30dd8e strb r4, [lr, r12, lsr #12]!
 *   @0x30dd92 ldcllt p0, c2, [r0, #0]!
 *   @0x30dd96 .word 0x9c06b537
 *   @0x30dd9a eorpl pc, r4, #208, #16
 *   @0x30dd9e stmibvs r12!, {r10, r12, pc} ^
 *   @0x30dda2 andlt r4, r3, r0, lsr #15
 *   @0x30dda6 strlt r11, [r8, #-0xd30]
 *   @0x30ddaa eorlo pc, r4, #208, #16
 *   @0x30ddae .word 0x47986a1b
 *   @0x30ddb2 blx 0xfe37d1dc <b2_toiTime+0xfffffffffdc23d38>
 *   @0x30ddb6 b 0x16da5be <b2_toiTime+0xf8111a>
 *   @0x30ddba .word 0xf50070e2
 *   @0x30ddbe ldmdane r11, {lr}
 *   @0x30ddc2 andeq pc, r0, #-2147483632
 *   @0x30ddc6 andsmi lr, r3, pc, asr #20
 *   @0x30ddca andmi lr, r2, r0, asr #20
 *   @0x30ddce .word 0xf8d04770
 *   @0x30ddd2 andhs r3, r0, #156
 *   @0x30ddd6 .word 0x4770625a
 *   @0x30ddda addlt r0, r4, r0
 *   @0x30ddde blge 0x4165ea <g_RomDisk+0x1edca>
 *   @0x30dde2 .word 0xf88061c2
 *   @0x30dde6 vst4.8 {d18, d19, d20, d21}, [pc:128], r0
 *   @0x30ddea subvs r7, r2, #-1610612721
 *   @0x30ddee sbcvc pc, r8, #1325400064
 *   @0x30ddf2 vst1.32 {d22, d23, d24, d25}, [pc], r2
 *   @0x30ddf6 sbcvs r7, r2, #-1610612729
 *   @0x30ddfa andsne pc, r3, #64, #4
 *   @0x30ddfe vcgt.s8 d22, d0, d2
 *   @0x30de02 orrvs r6, r2, #-1073741792
 *   @0x30de06 andsne pc, sp, #64, #12
 *   @0x30de0a andhs r6, r0, #134217731
 *   @0x30de0e bge 0x3e6e1e <error_g0017+0x3fac2>
 *   @0x30de12 stceq p8, c15, [r12, #-268]
 *   @0x30de16 stmvs r2, {r0, r1, r4, r6, lr}
 *   @0x30de1a subsmi r6, r3, r1, asr #6
 *   @0x30de1e b 0xfe39128e <b2_toiTime+0xfffffffffdc37dea>
 *   @0x30de22 .word 0x40532293
 *   @0x30de26 ble 0x358a2e
 *   @0x30de2a and r4, r1, r11, asr r2
 *   @0x30de2e blmi 0x3bda56 <error_g0017+0x166fa>
 *   @0x30de32 andhs r6, r0, r3, asr #8
 *   @0x30de36 ldrbmi r11, [r0, -r4]!
 *   @0x30de3a ldcgt p15, c11, [r5, #-0]
 *   @0x30de3e .word 0x4770075b
 *   @0x30de42 stmdavs r3, {r4, r8, r12, sp, pc}
 *   @0x30de46 andvs r11, r1, r3, lsl #18
 *   @0x30de4a ldrlt r4, [r0, #-0x770]
 *   @0x30de4e stmdbvs r3, {r2, r9, r10, lr} ^
 *   @0x30de52 movwle r4, #0x4299
 *   @0x30de56 stmdavs r0, {r1, r7, r8, sp} ^
 *   @0x30de5a .word 0xfff2f7ff
 *   @0x30de5e stmvs r0!, {r8, sp}
 *   @0x30de62 blx 0x3285f8
 *   @0x30de66 ldclt p0, c3, [r0, #-4]
 *   @0x30de6a .word 0x4604b570
 *   @0x30de6e .word 0xb10a6942
 *   @0x30de72 stmdblt r11!, {r0, r1, r6, r8, r9, r11, r12, sp, lr}
 *   @0x30de76 stmdbvs r1!, {r3, r9, r10, lr}
 *   @0x30de7a ldrhtmi lr, [r0], #-141
 *   @0x30de7e svclt #0x99f7ff
 *   @0x30de82 blo 0x368496 <_ZTS12CDS_Priority+0xa4ee>
 *   @0x30de86 addsmi r2, r3, #20, #10
 *   @0x30de8a andshs sp, r4, r1, lsl #6
 *   @0x30de8e mrrcne p0, #0x0, lr, r8, c13
 *   @0x30de92 strmi pc, [r0], -r5, lsl #22
 *   @0x30de96 adcsmi r6, r1, #483328
 *   @0x30de9a .word 0x4603dbf7
 *   @0x30de9e blx 0x347e74
 *   @0x30dea2 bvs 0x179e6b6 <b2_toiTime+0x1045212>
 *   @0x30dea6 ble 0x39e8f2 <ft_sid_names+0x110>
 *   @0x30deaa blhs 0x31cab6
 *   @0x30deae strdvs sp, lr, [r3, r7]!
 *   @0x30deb2 bvs 0x1b3c366 <b2_toiTime+0x13e2ec2>
 *   @0x30deb6 ble 0x39e8c2 <ft_sid_names+0xe0>
 *   @0x30deba stmdbvs r1!, {r3, r9, r11, r12}
 *   @0x30debe andshs lr, r4, #5
 *   @0x30dec2 strmi pc, [r3], #-2818
 *   @0x30dec6 bne 0x52884e <SrcVerts+0x85892>
 *   @0x30deca .word 0xf7ff6ae1
 *   @0x30dece bvs 0xfec0dc9e <b2_toiTime+0xfffffffffe4b47fa>
 *   @0x30ded2 ldcllt p4, c4, [r0, #-96]!
 *   @0x30ded6 svcmi #0xf0e92d
 *   @0x30deda stmdavs r11, {r2, r9, r10, lr}
 *   @0x30dede ldrmi r11, [r7], -r5, lsl #1
 *   @0x30dee2 ldmdavs r3, {r0, r1, r3, r5, r8, r12, sp, pc}
 *   @0x30dee6 .word 0xf0402b00
 *   @0x30deea .word 0x460e80b5
 *   @0x30deee ldrmi lr, [r6], -r0
 *   @0x30def2 beq 0x34a036
 *   @0x30def6 strhs r6, [r0, #-0x961]
 *   @0x30defa addmi r2, sp, #20
 *   @0x30defe blx 0x341f2c
 *   @0x30df02 ldmvs r2!, {r0, r2, r8, r9, lr}
 *   @0x30df06 addsmi r6, r3, #372736
 *   @0x30df0a strlo sp, [r1, #-0xa01]
 *
 * ══ §3/5 mdct_backward  0x22bf7c  size 8040  2010 条（0x22bf7c..0x22dee4）
 * @func 0x22bf7c 0x22dee4  size 8040  2010 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: mdct_backward+0x160 / mdct_backward+0x2b4 / mdct_backward+0xc80 / mdct_backward+0x474 / mdct_backward+0x884 / mdct_backward+0x1500 / mdct_backward+0x1b74 / mdct_backward+0x1f14
 * 字段偏移 top8: 0x10×81 / 0x4×72 / 0x28×58 / 0x20×41 / 0x18×40 / 0x8×32 / 0x40×31 / 0xc×28
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22bf7c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x22bf80 tst r0, #64
 *   @0x22bf84 sub sp, sp, #256
 *   @0x22bf88 mov r11, r1
 *   @0x22bf8c asr r1, r0, #1
 *   @0x22bf90 str r2, [sp, #0xf4]
 *   @0x22bf94 str r1, [sp, #0x88]
 *   @0x22bf98 asr r1, r0, #2
 *   @0x22bf9c bne 0x22de9c <mdct_backward+0x1f20>
 *   @0x22bfa0 mov r3, #6
 *   @0x22bfa4 add r3, r3, #1
 *   @0x22bfa8 asr r2, r0, r3
 *   @0x22bfac tst r2, #1
 *   @0x22bfb0 beq 0x22bfa4 <mdct_backward+0x28>
 *   @0x22bfb4 rsb r2, r3, #13
 *   @0x22bfb8 str r2, [sp, #0x9c]
 *   @0x22bfbc ldr r4, [sp, #0x9c]
 *   @0x22bfc0 mov r2, #2
 *   @0x22bfc4 sub r3, r3, #6
 *   @0x22bfc8 str r3, [sp, #0x90]
 *   @0x22bfcc lsl r2, r2, r4
 *   @0x22bfd0 str r2, [sp, #0xf8]
 *   @0x22bfd4 lsl r5, r2, #2
 *   @0x22bfd8 asr r6, r2, #2
 *   @0x22bfdc rsb r7, r5, #0
 *   @0x22bfe0 str r5, [sp, #0xe4]
 *   @0x22bfe4 str r6, [sp, #0xec]
 *   @0x22bfe8 str r7, [sp, #0xcc]
 *   @0x22bfec ldr r3, [sp, #0x88]
 *   @0x22bff0 ldr r4, [sp, #0xf4]
 *   @0x22bff4 sub r2, r3, #-1073741817
 *   @0x22bff8 add r3, r1, r3
 *   @0x22bffc ldr r9, [pc, #0x7d4]
 *   @0x22c000 lsl r1, r1, #2
 *   @0x22c004 lsl r2, r2, #2
 *   @0x22c008 add r3, r4, r3, lsl #2
 *   @0x22c00c ldr r6, [sp, #0xe4]
 *   @0x22c010 add r9, pc, r9
 *   @0x22c014 ldr r10, [sp, #0xe4]
 *   @0x22c018 add r12, r11, r2
 *   @0x22c01c mov r8, r3
 *   @0x22c020 add r5, r11, r1
 *   @0x22c024 lsl r6, r6, #1
 *   @0x22c028 str r1, [sp, #0xfc]
 *   @0x22c02c str r2, [sp, #0x20]
 *   @0x22c030 str r3, [sp, #0xe8]
 *   @0x22c034 str r5, [sp, #0x10]
 *   @0x22c038 str r6, [sp, #0xc8]
 *   @0x22c03c str r11, [sp, #0x28]
 *   @0x22c040 ldm r9, {r2, r4}
 *   @0x22c044 sub r8, r8, #16
 *   @0x22c048 ldr r0, [r12, #0x10]
 *   @0x22c04c add r11, r9, r10
 *   @0x22c050 ldr r3, [r12, #0x18]
 *   @0x22c054 sub r12, r12, #32
 *   @0x22c058 smull r6, r7, r3, r4
 *   @0x22c05c smull r4, r5, r0, r4
 *   @0x22c060 smull r0, r1, r0, r2
 *   @0x22c064 lsl r0, r7, #1
 *   @0x22c068 smull r2, r3, r2, r3
 *   @0x22c06c lsl r2, r5, #1
 *   @0x22c070 ldr r7, [sp, #0x10]
 *   @0x22c074 add r0, r0, r1, lsl #1
 *   @0x22c078 str r0, [r8, #0x8]
 *   @0x22c07c rsb r3, r2, r3, lsl #1
 *   @0x22c080 str r3, [r8, #0xc]
 *   @0x22c084 ldr r4, [r11, #0x4]
 *   @0x22c088 ldr r0, [r12, #0x20]
 *   @0x22c08c ldr r3, [r12, #0x28]
 *   @0x22c090 cmp r12, r7
 *   @0x22c094 ldr r2, [r9, r10]
 *   @0x22c098 ldr r11, [sp, #0xc8]
 *   @0x22c09c smull r6, r7, r3, r4
 *   @0x22c0a0 add r9, r9, r11
 *   @0x22c0a4 smull r4, r5, r0, r4
 *   @0x22c0a8 smull r0, r1, r0, r2
 *   @0x22c0ac lsl r0, r7, #1
 *   @0x22c0b0 smull r2, r3, r2, r3
 *   @0x22c0b4 lsl r2, r5, #1
 *   @0x22c0b8 add r0, r0, r1, lsl #1
 *   @0x22c0bc str r0, [r8]
 *   @0x22c0c0 rsb r3, r2, r3, lsl #1
 *   @0x22c0c4 str r3, [r8, #0x4]
 *   @0x22c0c8 bhs 0x22c040 <mdct_backward+0xc4>
 *   @0x22c0cc ldr r0, [sp, #0xcc]
 *   @0x22c0d0 ldr r10, [sp, #0xcc]
 *   @0x22c0d4 lsl r0, r0, #1
 *   @0x22c0d8 str r0, [sp, #0xd4]
 *   @0x22c0dc mov r11, r9
 *   @0x22c0e0 ldr r3, [r12, #0x18]
 *   @0x22c0e4 ldr r0, [r12, #0x10]
 *   @0x22c0e8 sub r8, r8, #16
 *   @0x22c0ec ldr r4, [r11], r10
 *   @0x22c0f0 sub r12, r12, #32
 *   @0x22c0f4 ldr r2, [r9, #0x4]
 *   @0x22c0f8 smull r6, r7, r3, r4
 *   @0x22c0fc smull r4, r5, r0, r4
 *   @0x22c100 smull r0, r1, r0, r2
 *   @0x22c104 lsl r0, r7, #1
 *   @0x22c108 smull r2, r3, r2, r3
 *   @0x22c10c lsl r2, r5, #1
 *   @0x22c110 ldr r5, [sp, #0xd4]
 *   @0x22c114 add r0, r0, r1, lsl #1
 *   @0x22c118 str r0, [r8, #0x8]
 *   @0x22c11c ldr r1, [sp, #0x28]
 *   @0x22c120 rsb r3, r2, r3, lsl #1
 *   @0x22c124 str r3, [r8, #0xc]
 *   @0x22c128 ldr r0, [r12, #0x20]
 *   @0x22c12c ldr r3, [r12, #0x28]
 *   @0x22c130 cmp r1, r12
 *   @0x22c134 ldr r4, [r9, r10]
 *   @0x22c138 add r9, r9, r5
 *   @0x22c13c ldr r2, [r11, #0x4]
 *   @0x22c140 smull r6, r7, r3, r4
 *   @0x22c144 smull r4, r5, r0, r4
 *   @0x22c148 smull r0, r1, r0, r2
 *   @0x22c14c lsl r0, r7, #1
 *   @0x22c150 smull r2, r3, r2, r3
 *   @0x22c154 lsl r2, r5, #1
 *   @0x22c158 add r0, r0, r1, lsl #1
 *   @0x22c15c str r0, [r8]
 *   @0x22c160 rsb r3, r2, r3, lsl #1
 *   @0x22c164 str r3, [r8, #0x4]
 *   @0x22c168 bls 0x22c0dc <mdct_backward+0x160>
 *   @0x22c16c ldr r9, [pc, #0x668]
 *   @0x22c170 ldr r11, [sp, #0x28]
 *   @0x22c174 ldr r6, [sp, #0x20]
 *   @0x22c178 add r9, pc, r9
 *   @0x22c17c ldr r7, [sp, #0xe4]
 *   @0x22c180 ldr r12, [sp, #0xe8]
 *   @0x22c184 sub r6, r6, #4
 *   @0x22c188 add r9, r9, r7
 *   @0x22c18c add r8, r11, r6
 *   @0x22c190 str r11, [sp, #0x20]
 *   @0x22c194 mov r11, r7
 *   @0x22c198 str r6, [sp, #0x28]
 *   @0x22c19c ldr r2, [r8, #0x18]
 *   @0x22c1a0 add r10, r9, r11
 *   @0x22c1a4 ldr r4, [r9, #0x4]
 *   @0x22c1a8 add r12, r12, #16
 *   @0x22c1ac ldr r0, [r8, #0x10]
 *   @0x22c1b0 ldr r3, [r9]
 *   @0x22c1b4 smull r6, r7, r2, r4
 *   @0x22c1b8 smull r4, r5, r0, r4
 *   @0x22c1bc smull r0, r1, r3, r0
 *   @0x22c1c0 lsl r0, r7, #1
 *   @0x22c1c4 smull r2, r3, r2, r3
 *   @0x22c1c8 lsl r2, r5, #1
 *   @0x22c1cc ldr r5, [sp, #0x10]
 *   @0x22c1d0 add r0, r0, r1, lsl #1
 *   @0x22c1d4 str r0, [r12, #-0xc]
 *   @0x22c1d8 ldr r1, [sp, #0xc8]
 *   @0x22c1dc rsb r3, r2, r3, lsl #1
 *   @0x22c1e0 str r3, [r12, #-0x10]
 *   @0x22c1e4 ldr r2, [r8, #0x8]
 *   @0x22c1e8 ldr r4, [r10, #0x4]
 *   @0x22c1ec ldr r0, [r8], #-32
 *   @0x22c1f0 ldr r3, [r9, r11]
 *   @0x22c1f4 add r9, r9, r1
 *   @0x22c1f8 smull r6, r7, r2, r4
 *   @0x22c1fc cmp r8, r5
 *   @0x22c200 smull r4, r5, r0, r4
 *   @0x22c204 smull r0, r1, r3, r0
 *   @0x22c208 lsl r0, r7, #1
 *   @0x22c20c smull r2, r3, r2, r3
 *   @0x22c210 lsl r2, r5, #1
 *   @0x22c214 add r0, r0, r1, lsl #1
 *   @0x22c218 str r0, [r12, #-0x4]
 *   @0x22c21c rsb r3, r2, r3, lsl #1
 *   @0x22c220 str r3, [r12, #-0x8]
 *   @0x22c224 bhs 0x22c19c <mdct_backward+0x220>
 *   @0x22c228 ldr r9, [sp, #0xcc]
 *   @0x22c22c ldr r11, [sp, #0x20]
 *   @0x22c230 add r2, r10, r9
 *   @0x22c234 ldr r0, [r8, #0x18]
 *   @0x22c238 ldr r3, [r8, #0x10]
 *   @0x22c23c add r12, r12, #16
 *   @0x22c240 ldr r4, [r10, r9]
 *   @0x22c244 ldr r2, [r2, #0x4]
 *   @0x22c248 ldr r6, [sp, #0xd4]
 *   @0x22c24c add r10, r10, r6
 *   @0x22c250 smull r6, r7, r3, r4
 *   @0x22c254 smull r4, r5, r0, r4
 *   @0x22c258 smull r0, r1, r0, r2
 *   @0x22c25c lsl r0, r7, #1
 *   @0x22c260 smull r2, r3, r2, r3
 *   @0x22c264 lsl r2, r5, #1
 *   @0x22c268 rsb r0, r0, r1, lsl #1
 *   @0x22c26c str r0, [r12, #-0x10]
 *   @0x22c270 add r3, r2, r3, lsl #1
 *   @0x22c274 str r3, [r12, #-0xc]
 *   @0x22c278 ldr r2, [r8, #0x8]
 *   @0x22c27c ldr r4, [r10]
 *   @0x22c280 ldr r0, [r8], #-32
 *   @0x22c284 ldr r3, [r10, #0x4]
 *   @0x22c288 smull r6, r7, r2, r4
 *   @0x22c28c cmp r11, r8
 *   @0x22c290 smull r4, r5, r0, r4
 *   @0x22c294 smull r0, r1, r3, r0
 *   @0x22c298 lsl r0, r7, #1
 *   @0x22c29c smull r2, r3, r2, r3
 *   @0x22c2a0 lsl r2, r5, #1
 *   @0x22c2a4 add r0, r0, r1, lsl #1
 *   @0x22c2a8 str r0, [r12, #-0x4]
 *   @0x22c2ac rsb r3, r2, r3, lsl #1
 *   @0x22c2b0 str r3, [r12, #-0x8]
 *   @0x22c2b4 bls 0x22c230 <mdct_backward+0x2b4>
 *   @0x22c2b8 ldr r7, [sp, #0x90]
 *   @0x22c2bc ldr r8, [sp, #0x28]
 *   @0x22c2c0 str r9, [sp, #0xcc]
 *   @0x22c2c4 cmp r7, #0
 *   @0x22c2c8 ldr r9, [sp, #0xf4]
 *   @0x22c2cc add r3, r8, #32
 *   @0x22c2d0 add r3, r9, r3
 *   @0x22c2d4 str r3, [sp, #0xbc]
 *   @0x22c2d8 beq 0x22cc14 <mdct_backward+0xc98>
 *   @0x22c2dc ldr r2, [pc, #0x4fc]
 *   @0x22c2e0 mov r10, #0
 *   @0x22c2e4 ldr r3, [pc, #0x4f8]
 *   @0x22c2e8 ldr r11, [pc, #0x4f8]
 *   @0x22c2ec add r2, pc, r2
 *   @0x22c2f0 ldr r12, [pc, #0x4f4]
 *   @0x22c2f4 add r3, pc, r3
 *   @0x22c2f8 ldr r0, [pc, #0x4f0]
 *   @0x22c2fc add r2, r2, #4096
 *   @0x22c300 add r3, r3, #4096
 *   @0x22c304 add r11, pc, r11
 *   @0x22c308 add r12, pc, r12
 *   @0x22c30c add r0, pc, r0
 *   @0x22c310 str r10, [sp, #0x98]
 *   @0x22c314 str r2, [sp, #0x54]
 *   @0x22c318 str r3, [sp, #0x5c]
 *   @0x22c31c str r11, [sp, #0x84]
 *   @0x22c320 str r12, [sp, #0x58]
 *   @0x22c324 str r0, [sp, #0x60]
 *   @0x22c328 ldr r10, [sp, #0x98]
 *   @0x22c32c mov r9, #1
 *   @0x22c330 lsl r9, r9, r10
 *   @0x22c334 str r9, [sp, #0x70]
 *   @0x22c338 cmp r9, #0
 *   @0x22c33c ble 0x22cbfc <mdct_backward+0xc80>
 *   @0x22c340 ldr r12, [sp, #0x88]
 *   @0x22c344 mov r1, #4
 *   @0x22c348 ldr r11, [sp, #0x9c]
 *   @0x22c34c mov r4, #0
 *   @0x22c350 str r4, [sp, #0x78]
 *   @0x22c354 add r3, r10, r11
 *   @0x22c358 asr r0, r12, r10
 *   @0x22c35c lsl r3, r1, r3
 *   @0x22c360 sub r2, r0, #-1073741816
 *   @0x22c364 asr r0, r0, #1
 *   @0x22c368 ldr r12, [sp, #0xbc]
 *   @0x22c36c lsl r5, r3, #2
 *   @0x22c370 sub r0, r0, #-1073741816
 *   @0x22c374 rsb r1, r5, #0
 *   @0x22c378 lsl r2, r2, #2
 *   @0x22c37c rsb r0, r2, r0, lsl #2
 *   @0x22c380 lsl r6, r3, #3
 *   @0x22c384 lsl r7, r1, #1
 *   @0x22c388 lsl r8, r1, #2
 *   @0x22c38c sub r9, r0, #32
 *   @0x22c390 add r10, r2, #32
 *   @0x22c394 str r0, [sp, #0x68]
 *   @0x22c398 add r1, r7, r1
 *   @0x22c39c add r2, r12, r2
 *   @0x22c3a0 lsl r3, r3, #4
 *   @0x22c3a4 add r0, r6, r5
 *   @0x22c3a8 str r5, [sp, #0x20]
 *   @0x22c3ac str r6, [sp, #0x38]
 *   @0x22c3b0 str r7, [sp, #0x30]
 *   @0x22c3b4 str r8, [sp, #0x50]
 *   @0x22c3b8 str r1, [sp, #0x48]
 *   @0x22c3bc str r9, [sp, #0x80]
 *   @0x22c3c0 str r10, [sp, #0x7c]
 *   @0x22c3c4 str r2, [sp, #0x64]
 *   @0x22c3c8 str r3, [sp, #0x4c]
 *   @0x22c3cc str r0, [sp, #0x40]
 *   @0x22c3d0 ldr r2, [sp, #0x64]
 *   @0x22c3d4 ldr r1, [sp, #0x68]
 *   @0x22c3d8 ldr r3, [sp, #0x80]
 *   @0x22c3dc sub r11, r2, #32
 *   @0x22c3e0 ldr r9, [sp, #0x84]
 *   @0x22c3e4 add r8, r1, r2
 *   @0x22c3e8 add r10, r3, r2
 *   @0x22c3ec mov r12, r2
 *   @0x22c3f0 ldr r1, [r8, #0x18]
 *   @0x22c3f4 sub r11, r11, #32
 *   @0x22c3f8 ldr r0, [r12, #0x18]
 *   @0x22c3fc sub r10, r10, #32
 *   @0x22c400 ldr r4, [sp, #0x20]
 *   @0x22c404 sub r12, r12, #32
 *   @0x22c408 ldr r3, [r12, #0x3c]
 *   @0x22c40c sub r8, r8, #32
 *   @0x22c410 add r4, r9, r4
 *   @0x22c414 str r4, [sp, #0x18]
 *   @0x22c418 add r4, r0, r1
 *   @0x22c41c str r4, [r12, #0x38]
 *   @0x22c420 ldr r4, [r8, #0x3c]
 *   @0x22c424 rsb r0, r1, r0
 *   @0x22c428 ldr r5, [sp, #0x38]
 *   @0x22c42c add r1, r4, r3
 *   @0x22c430 str r1, [r12, #0x3c]
 *   @0x22c434 ldr r1, [r9, #0x4]
 *   @0x22c438 rsb r4, r3, r4
 *   @0x22c43c add r5, r5, r9
 *   @0x22c440 str r5, [sp, #0x28]
 *   @0x22c444 ldr r3, [r8, #0x30]
 *   @0x22c448 smull r6, r7, r0, r1
 *   @0x22c44c strd r6, r7, [sp, #16]
 *   @0x22c450 smull r6, r7, r4, r1
 *   @0x22c454 ldr r1, [r9]
 *   @0x22c458 ldr r2, [sp, #0x14]
 *   @0x22c45c ldr r6, [sp, #0x20]
 *   @0x22c460 smull r4, r5, r4, r1
 *   @0x22c464 lsl r4, r2, #1
 *   @0x22c468 smull r0, r1, r1, r0
 *   @0x22c46c lsl r0, r7, #1
 *   @0x22c470 add r4, r4, r5, lsl #1
 *   @0x22c474 str r4, [r8, #0x38]
 *   @0x22c478 ldr r4, [sp, #0x40]
 *   @0x22c47c ldr r5, [sp, #0x18]
 *   @0x22c480 add r4, r4, r9
 *   @0x22c484 rsb r0, r0, r1, lsl #1
 *   @0x22c488 str r4, [sp, #0x10]
 *   @0x22c48c str r0, [r8, #0x3c]
 *   @0x22c490 ldr r4, [r12, #0x30]
 *   @0x22c494 ldr r1, [r12, #0x34]
 *   @0x22c498 add r0, r4, r3
 *   @0x22c49c str r0, [r12, #0x30]
 *   @0x22c4a0 ldr r0, [r8, #0x34]
 *   @0x22c4a4 rsb r3, r3, r4
 *   @0x22c4a8 add r4, r0, r1
 *   @0x22c4ac str r4, [r12, #0x34]
 *   @0x22c4b0 ldr r4, [r5, #0x4]
 *   @0x22c4b4 rsb r0, r1, r0
 *   @0x22c4b8 ldr r2, [r9, r6]
 *   @0x22c4bc smull r6, r7, r3, r4
 *   @0x22c4c0 ldr r6, [r8, #0x28]
 *   @0x22c4c4 smull r4, r5, r0, r4
 *   @0x22c4c8 smull r0, r1, r0, r2
 *   @0x22c4cc lsl r0, r7, #1
 *   @0x22c4d0 smull r2, r3, r2, r3
 *   @0x22c4d4 lsl r2, r5, #1
 *   @0x22c4d8 add r0, r0, r1, lsl #1
 *   @0x22c4dc str r0, [r8, #0x30]
 *   @0x22c4e0 rsb r2, r2, r3, lsl #1
 *   @0x22c4e4 str r2, [r8, #0x34]
 *   @0x22c4e8 ldr r2, [r12, #0x28]
 *   @0x22c4ec ldr r3, [r12, #0x2c]
 *   @0x22c4f0 add r1, r2, r6
 *   @0x22c4f4 str r1, [r12, #0x28]
 *   @0x22c4f8 ldr r0, [r8, #0x2c]
 *   @0x22c4fc rsb r2, r6, r2
 *   @0x22c500 ldr r7, [sp, #0x28]
 *   @0x22c504 add r1, r0, r3
 *   @0x22c508 str r1, [r12, #0x2c]
 *   @0x22c50c ldr r1, [sp, #0x38]
 *   @0x22c510 rsb r0, r3, r0
 *   @0x22c514 ldr r4, [r7, #0x4]
 *   @0x22c518 ldr r3, [r1, r9]
 *   @0x22c51c smull r6, r7, r2, r4
 *   @0x22c520 ldr r6, [sp, #0x40]
 *   @0x22c524 smull r4, r5, r0, r4
 *   @0x22c528 smull r0, r1, r0, r3
 *   @0x22c52c lsl r0, r7, #1
 *   @0x22c530 smull r2, r3, r3, r2
 *   @0x22c534 lsl r2, r5, #1
 *   @0x22c538 ldr r5, [sp, #0x10]
 *   @0x22c53c add r0, r0, r1, lsl #1
 *   @0x22c540 str r0, [r8, #0x28]
 *   @0x22c544 ldr r7, [sp, #0x4c]
 *   @0x22c548 rsb r2, r2, r3, lsl #1
 *   @0x22c54c str r2, [r8, #0x2c]
 *   @0x22c550 ldr r0, [r11, #0x40]
 *   @0x22c554 ldr r3, [r10, #0x40]
 *   @0x22c558 add r2, r0, r3
 *   @0x22c55c rsb r0, r3, r0
 *   @0x22c560 str r2, [r11, #0x40]
 *   @0x22c564 ldr r3, [r12, #0x24]
 *   @0x22c568 ldr r2, [r8, #0x24]
 *   @0x22c56c add r1, r2, r3
 *   @0x22c570 str r1, [r12, #0x24]
 *   @0x22c574 ldr r4, [r5, #0x4]
 *   @0x22c578 rsb r2, r3, r2
 *   @0x22c57c ldr r3, [r6, r9]
 *   @0x22c580 add r9, r9, r7
 *   @0x22c584 ldr r1, [sp, #0x54]
 *   @0x22c588 smull r6, r7, r2, r4
 *   @0x22c58c cmp r9, r1
 *   @0x22c590 smull r4, r5, r0, r4
 *   @0x22c594 smull r0, r1, r3, r0
 *   @0x22c598 lsl r0, r7, #1
 *   @0x22c59c smull r2, r3, r2, r3
 *   @0x22c5a0 lsl r2, r5, #1
 *   @0x22c5a4 rsb r0, r0, r1, lsl #1
 *   @0x22c5a8 add r2, r2, r3, lsl #1
 *   @0x22c5ac str r2, [r10, #0x40]
 *   @0x22c5b0 str r0, [r8, #0x24]
 *   @0x22c5b4 blo 0x22c3f0 <mdct_backward+0x474>
 *   @0x22c5b8 sub r3, r8, #32
 *   @0x22c5bc sub r2, r12, #32
 *   @0x22c5c0 str r3, [sp, #0x28]
 *   @0x22c5c4 mov r11, r3
 *   @0x22c5c8 str r2, [sp, #0x10]
 *   @0x22c5cc mov r10, r11
 *   @0x22c5d0 mov r11, r2
 *   @0x22c5d4 b 0x22c5e8 <mdct_backward+0x66c>
 *   @0x22c5d8 sub r2, r12, #32
 *   @0x22c5dc sub r3, r8, #32
 *   @0x22c5e0 str r2, [sp, #0x10]
 *   @0x22c5e4 str r3, [sp, #0x28]
 *   @0x22c5e8 ldr r0, [r8, #0x18]
 *   @0x22c5ec sub r11, r11, #32
 *   @0x22c5f0 ldr r4, [r12, #0x18]
 *   @0x22c5f4 sub r10, r10, #32
 *   @0x22c5f8 ldr r2, [r12, #0x1c]
 *   @0x22c5fc add r3, r4, r0
 *   @0x22c600 ldr r5, [sp, #0x20]
 *   @0x22c604 str r3, [r12, #0x18]
 *   @0x22c608 rsb r4, r0, r4
 *   @0x22c60c ldr r3, [r8, #0x1c]
 *   @0x22c610 rsb r1, r5, r9
 *   @0x22c614 ldr r6, [sp, #0x30]
 *   @0x22c618 add r0, r2, r3
 *   @0x22c61c str r0, [r12, #0x1c]
 *   @0x22c620 ldr r5, [r9, #0x4]
 *   @0x22c624 rsb r2, r3, r2
 *   @0x22c628 add r6, r6, r9
 *   @0x22c62c str r6, [sp, #0x2c]
 *   @0x22c630 ldr r0, [r8, #0x10]
 *   @0x22c634 smull r6, r7, r2, r5
 *   @0x22c638 strd r6, r7, [sp, #24]
 *   @0x22c63c smull r6, r7, r4, r5
 *   @0x22c640 ldr r3, [sp, #0x1c]
 *   @0x22c644 lsl r5, r3, #1
 *   @0x22c648 strd r6, r7, [sp, #192]
 *   @0x22c64c ldr r7, [r9]
 *   @0x22c650 smull r6, r7, r4, r7
 *   @0x22c654 ldr r4, [r9]
 *   @0x22c658 smull r2, r3, r4, r2
 *   @0x22c65c strd r6, r7, [sp, #160]
 *   @0x22c660 ldr r6, [sp, #0xc4]
 *   @0x22c664 rsb r4, r5, r7, lsl #1
 *   @0x22c668 str r4, [r8, #0x18]
 *   @0x22c66c ldr r7, [sp, #0x48]
 *   @0x22c670 lsl r2, r6, #1
 *   @0x22c674 add r2, r2, r3, lsl #1
 *   @0x22c678 str r2, [r8, #0x1c]
 *   @0x22c67c ldr r4, [r12, #0x10]
 *   @0x22c680 add r7, r7, r9
 *   @0x22c684 ldr r2, [r12, #0x14]
 *   @0x22c688 add r3, r4, r0
 *   @0x22c68c str r3, [r12, #0x10]
 *   @0x22c690 ldr r3, [r8, #0x14]
 *   @0x22c694 rsb r0, r0, r4
 *   @0x22c698 str r7, [sp, #0x18]
 *   @0x22c69c add r4, r2, r3
 *   @0x22c6a0 str r4, [r12, #0x14]
 *   @0x22c6a4 ldr r4, [r1, #0x4]
 *   @0x22c6a8 rsb r2, r3, r2
 *   @0x22c6ac ldr r3, [r1]
 *   @0x22c6b0 smull r6, r7, r2, r4
 *   @0x22c6b4 ldr r6, [r8, #0x8]
 *   @0x22c6b8 smull r4, r5, r0, r4
 *   @0x22c6bc smull r0, r1, r0, r3
 *   @0x22c6c0 lsl r0, r7, #1
 *   @0x22c6c4 smull r2, r3, r3, r2
 *   @0x22c6c8 lsl r2, r5, #1
 *   @0x22c6cc rsb r0, r0, r1, lsl #1
 *   @0x22c6d0 str r0, [r8, #0x10]
 *   @0x22c6d4 add r2, r2, r3, lsl #1
 *   @0x22c6d8 str r2, [r8, #0x14]
 *   @0x22c6dc ldr r0, [r12, #0x8]
 *   @0x22c6e0 ldr r2, [r12, #0xc]
 *   @0x22c6e4 add r3, r0, r6
 *   @0x22c6e8 str r3, [r12, #0x8]
 *   @0x22c6ec ldr r3, [r8, #0xc]
 *   @0x22c6f0 rsb r0, r6, r0
 *   @0x22c6f4 ldr r5, [sp, #0x30]
 *   @0x22c6f8 add r1, r2, r3
 *   @0x22c6fc str r1, [r12, #0xc]
 *   @0x22c700 ldr r1, [sp, #0x2c]
 *   @0x22c704 rsb r2, r3, r2
 *   @0x22c708 ldr r3, [r5, r9]
 *   @0x22c70c ldr r4, [r1, #0x4]
 *   @0x22c710 smull r6, r7, r2, r4
 *   @0x22c714 ldr r6, [sp, #0x18]
 *   @0x22c718 smull r4, r5, r0, r4
 *   @0x22c71c smull r0, r1, r0, r3
 *   @0x22c720 lsl r0, r7, #1
 *   @0x22c724 smull r2, r3, r3, r2
 *   @0x22c728 lsl r2, r5, #1
 *   @0x22c72c ldr r7, [sp, #0x48]
 *   @0x22c730 rsb r0, r0, r1, lsl #1
 *   @0x22c734 str r0, [r8, #0x8]
 *   @0x22c738 add r2, r2, r3, lsl #1
 *   @0x22c73c str r2, [r8, #0xc]
 *   @0x22c740 ldr r0, [r11, #0x40]
 *   @0x22c744 ldr r3, [r10, #0x40]
 *   @0x22c748 add r2, r0, r3
 *   @0x22c74c rsb r0, r3, r0
 *   @0x22c750 str r2, [r11, #0x40]
 *   @0x22c754 ldr r3, [r8, #0x4]
 *   @0x22c758 ldr r2, [r12, #0x4]
 *   @0x22c75c add r1, r2, r3
 *   @0x22c760 str r1, [r12, #0x4]
 *   @0x22c764 ldr r4, [r6, #0x4]
 *   @0x22c768 rsb r2, r3, r2
 *   @0x22c76c ldr r12, [sp, #0x50]
 *   @0x22c770 ldr r3, [r7, r9]
 *   @0x22c774 ldr r1, [sp, #0x58]
 *   @0x22c778 add r9, r9, r12
 *   @0x22c77c smull r6, r7, r2, r4
 *   @0x22c780 cmp r9, r1
 *   @0x22c784 smull r4, r5, r0, r4
 *   @0x22c788 ldr r12, [sp, #0x10]
 *   @0x22c78c smull r0, r1, r0, r3
 *   @0x22c790 lsl r0, r7, #1
 *   @0x22c794 smull r2, r3, r3, r2
 *   @0x22c798 lsl r2, r5, #1
 *   @0x22c79c rsb r0, r0, r1, lsl #1
 *   @0x22c7a0 str r0, [r10, #0x40]
 *   @0x22c7a4 add r2, r2, r3, lsl #1
 *   @0x22c7a8 str r2, [r8, #0x4]
 *   @0x22c7ac ldr r8, [sp, #0x28]
 *   @0x22c7b0 bhi 0x22c5d8 <mdct_backward+0x65c>
 *   @0x22c7b4 ldr r4, [sp, #0x10]
 *   @0x22c7b8 ldr r5, [sp, #0x28]
 *   @0x22c7bc sub r4, r4, #32
 *   @0x22c7c0 str r4, [sp, #0x10]
 *   @0x22c7c4 sub r5, r5, #32
 *   @0x22c7c8 str r5, [sp, #0x28]
 *   @0x22c7cc mov r11, r4
 *   @0x22c7d0 mov r10, r5
 *   @0x22c7d4 b 0x22c810 <mdct_backward+0x894>
 *   @0x22c7d8 mulseq r3, r0, r10
 *   @0x22c7dc andseq r2, r3, r8, lsr #18
 *   @0x22c7e0 ldrheq r2, [r3], -r4
 *   @0x22c7e4 andseq r2, r3, r12, lsr #15
 *   @0x22c7e8 mulseq r3, r12, r7
 *   @0x22c7ec mulseq r3, r8, r7
 *   @0x22c7f0 mulseq r3, r4, r7
 *   @0x22c7f4 andseq r1, r3, r12, lsl #12
 *   @0x22c7f8 andseq r3, r3, r12, ror #11
 *   @0x22c7fc ldrsbeq r3, [r3], -r0
 *   @0x22c800 sub r0, r12, #32
 *   @0x22c804 sub r1, r8, #32
 *   @0x22c808 str r0, [sp, #0x10]
 *   @0x22c80c str r1, [sp, #0x28]
 *   @0x22c810 ldr r1, [r12, #0x18]
 *   @0x22c814 sub r11, r11, #32
 *   @0x22c818 ldr r4, [r8, #0x18]
 *   @0x22c81c sub r10, r10, #32
 *   @0x22c820 ldr r3, [r12, #0x1c]
 *   @0x22c824 add r2, r4, r1
 *   @0x22c828 str r2, [r12, #0x18]
 *   @0x22c82c ldr r2, [r8, #0x1c]
 *   @0x22c830 rsb r4, r1, r4
 *   @0x22c834 ldr r6, [sp, #0x20]
 *   @0x22c838 add r1, r2, r3
 *   @0x22c83c str r1, [r12, #0x1c]
 *   @0x22c840 ldr r5, [r9, #0x4]
 *   @0x22c844 rsb r2, r3, r2
 *   @0x22c848 ldr r3, [r9]
 *   @0x22c84c add r6, r9, r6
 *   @0x22c850 ldr r7, [sp, #0x38]
 *   @0x22c854 smull r0, r1, r2, r5
 *   @0x22c858 str r6, [sp, #0xa8]
 *   @0x22c85c add r7, r7, r9
 *   @0x22c860 str r7, [sp, #0x2c]
 *   @0x22c864 smull r6, r7, r4, r5
 *   @0x22c868 ldr r6, [sp, #0x20]
 *   @0x22c86c smull r4, r5, r4, r3
 *   @0x22c870 strd r0, r1, [sp, #24]
 *   @0x22c874 smull r2, r3, r3, r2
 *   @0x22c878 ldr r0, [sp, #0x1c]
 *   @0x22c87c lsl r2, r7, #1
 *   @0x22c880 ldr r1, [r8, #0x10]
 *   @0x22c884 lsl r4, r0, #1
 *   @0x22c888 add r4, r4, r5, lsl #1
 *   @0x22c88c str r4, [r8, #0x18]
 *   @0x22c890 ldr r4, [sp, #0x40]
 *   @0x22c894 rsb r2, r2, r3, lsl #1
 *   @0x22c898 str r2, [r8, #0x1c]
 *   @0x22c89c add r4, r4, r9
 *   @0x22c8a0 str r4, [sp, #0x18]
 *   @0x22c8a4 ldr r4, [r12, #0x10]
 *   @0x22c8a8 ldr r5, [sp, #0xa8]
 *   @0x22c8ac ldr r3, [r12, #0x14]
 *   @0x22c8b0 add r2, r1, r4
 *   @0x22c8b4 str r2, [r12, #0x10]
 *   @0x22c8b8 rsb r1, r4, r1
 *   @0x22c8bc ldr r2, [r8, #0x14]
 *   @0x22c8c0 add r4, r2, r3
 *   @0x22c8c4 str r4, [r12, #0x14]
 *   @0x22c8c8 ldr r4, [r5, #0x4]
 *   @0x22c8cc rsb r2, r3, r2
 *   @0x22c8d0 ldr r3, [r9, r6]
 *   @0x22c8d4 smull r6, r7, r2, r4
 *   @0x22c8d8 ldr r6, [r8, #0x8]
 *   @0x22c8dc smull r4, r5, r1, r4
 *   @0x22c8e0 smull r0, r1, r1, r3
 *   @0x22c8e4 lsl r0, r7, #1
 *   @0x22c8e8 smull r2, r3, r3, r2
 *   @0x22c8ec lsl r2, r5, #1
 *   @0x22c8f0 add r0, r0, r1, lsl #1
 *   @0x22c8f4 str r0, [r8, #0x10]
 *   @0x22c8f8 rsb r2, r2, r3, lsl #1
 *   @0x22c8fc str r2, [r8, #0x14]
 *   @0x22c900 ldr r0, [r12, #0x8]
 *   @0x22c904 ldr r3, [r12, #0xc]
 *   @0x22c908 add r2, r6, r0
 *   @0x22c90c str r2, [r12, #0x8]
 *   @0x22c910 ldr r2, [r8, #0xc]
 *   @0x22c914 rsb r0, r0, r6
 *   @0x22c918 ldr r7, [sp, #0x2c]
 *   @0x22c91c add r1, r2, r3
 *   @0x22c920 str r1, [r12, #0xc]
 *   @0x22c924 ldr r1, [sp, #0x38]
 *   @0x22c928 rsb r2, r3, r2
 *   @0x22c92c ldr r4, [r7, #0x4]
 *   @0x22c930 ldr r3, [r1, r9]
 *   @0x22c934 smull r6, r7, r2, r4
 *   @0x22c938 ldr r6, [sp, #0x40]
 *   @0x22c93c smull r4, r5, r0, r4
 *   @0x22c940 smull r0, r1, r0, r3
 *   @0x22c944 lsl r0, r7, #1
 *   @0x22c948 smull r2, r3, r3, r2
 *   @0x22c94c lsl r2, r5, #1
 *   @0x22c950 ldr r5, [sp, #0x18]
 *   @0x22c954 add r0, r0, r1, lsl #1
 *   @0x22c958 str r0, [r8, #0x8]
 *   @0x22c95c ldr r7, [sp, #0x4c]
 *   @0x22c960 rsb r2, r2, r3, lsl #1
 *   @0x22c964 str r2, [r8, #0xc]
 *   @0x22c968 ldr r3, [r11, #0x40]
 *   @0x22c96c ldr r0, [r10, #0x40]
 *   @0x22c970 add r2, r0, r3
 *   @0x22c974 rsb r0, r3, r0
 *   @0x22c978 str r2, [r11, #0x40]
 *   @0x22c97c ldr r3, [r12, #0x4]
 *   @0x22c980 ldr r2, [r8, #0x4]
 *   @0x22c984 add r1, r2, r3
 *   @0x22c988 str r1, [r12, #0x4]
 *   @0x22c98c ldr r4, [r5, #0x4]
 *   @0x22c990 rsb r2, r3, r2
 *   @0x22c994 ldr r3, [r6, r9]
 *   @0x22c998 add r9, r7, r9
 *   @0x22c99c ldr r12, [sp, #0x5c]
 *   @0x22c9a0 smull r6, r7, r2, r4
 *   @0x22c9a4 cmp r9, r12
 *   @0x22c9a8 smull r4, r5, r0, r4
 *   @0x22c9ac ldr r12, [sp, #0x10]
 *   @0x22c9b0 smull r0, r1, r0, r3
 *   @0x22c9b4 lsl r0, r7, #1
 *   @0x22c9b8 smull r2, r3, r3, r2
 *   @0x22c9bc lsl r2, r5, #1
 *   @0x22c9c0 add r0, r0, r1, lsl #1
 *   @0x22c9c4 str r0, [r10, #0x40]
 *   @0x22c9c8 rsb r2, r2, r3, lsl #1
 *   @0x22c9cc str r2, [r8, #0x4]
 *   @0x22c9d0 ldr r8, [sp, #0x28]
 *   @0x22c9d4 blo 0x22c800 <mdct_backward+0x884>
 *   @0x22c9d8 ldr r2, [sp, #0x10]
 *   @0x22c9dc ldr r3, [sp, #0x28]
 *   @0x22c9e0 sub r2, r2, #32
 *   @0x22c9e4 str r2, [sp, #0x10]
 *   @0x22c9e8 sub r3, r3, #32
 *   @0x22c9ec str r3, [sp, #0x28]
 *   @0x22c9f0 mov r11, r2
 *   @0x22c9f4 mov r10, r3
 *   @0x22c9f8 ldr r1, [r8, #0x18]
 *   @0x22c9fc sub r11, r11, #32
 *   @0x22ca00 ldr r0, [r12, #0x18]
 *   @0x22ca04 sub r10, r10, #32
 *   @0x22ca08 ldr r4, [sp, #0x20]
 *   @0x22ca0c ldr r2, [r12, #0x1c]
 *   @0x22ca10 rsb r3, r4, r9
 *   @0x22ca14 add r4, r0, r1
 *   @0x22ca18 str r4, [r12, #0x18]
 *   @0x22ca1c rsb r0, r1, r0
 *   @0x22ca20 ldr r4, [r8, #0x1c]
 *   @0x22ca24 ldr r6, [sp, #0x30]
 *   @0x22ca28 add r1, r4, r2
 *   @0x22ca2c str r1, [r12, #0x1c]
 *   @0x22ca30 ldr r1, [r9, #0x4]
 *   @0x22ca34 add r6, r6, r9
 *   @0x22ca38 str r6, [sp, #0x2c]
 *   @0x22ca3c rsb r4, r2, r4
 *   @0x22ca40 ldr r5, [r9]
 *   @0x22ca44 smull r6, r7, r0, r1
 *   @0x22ca48 ldr r2, [r8, #0x10]
 *   @0x22ca4c strd r6, r7, [sp, #24]
 *   @0x22ca50 smull r6, r7, r4, r1
 *   @0x22ca54 smull r0, r1, r5, r0
 *   @0x22ca58 strd r6, r7, [sp, #192]
 *   @0x22ca5c smull r6, r7, r4, r5
 *   @0x22ca60 ldr r4, [sp, #0xc4]
 *   @0x22ca64 lsl r0, r4, #1
 *   @0x22ca68 add r0, r0, r1, lsl #1
 *   @0x22ca6c str r0, [r8, #0x1c]
 *   @0x22ca70 strd r6, r7, [sp, #160]
 *   @0x22ca74 ldr r7, [sp, #0x1c]
 *   @0x22ca78 ldr r5, [sp, #0xa4]
 *   @0x22ca7c lsl r6, r7, #1
 *   @0x22ca80 rsb r4, r6, r5, lsl #1
 *   @0x22ca84 str r4, [r8, #0x18]
 *   @0x22ca88 ldr r4, [r12, #0x10]
 *   @0x22ca8c ldr r1, [r12, #0x14]
 *   @0x22ca90 add r0, r4, r2
 *   @0x22ca94 str r0, [r12, #0x10]
 *   @0x22ca98 ldr r0, [r8, #0x14]
 *   @0x22ca9c rsb r2, r2, r4
 *   @0x22caa0 ldr r6, [sp, #0x48]
 *   @0x22caa4 add r4, r0, r1
 *   @0x22caa8 str r4, [r12, #0x14]
 *   @0x22caac ldr r4, [r3, #0x4]
 *   @0x22cab0 rsb r0, r1, r0
 *   @0x22cab4 ldr r3, [r3]
 *   @0x22cab8 add r6, r6, r9
 *   @0x22cabc str r6, [sp, #0x18]
 *   @0x22cac0 smull r6, r7, r2, r4
 *   @0x22cac4 ldr r6, [r8, #0x8]
 *   @0x22cac8 smull r4, r5, r0, r4
 *   @0x22cacc smull r0, r1, r0, r3
 *   @0x22cad0 lsl r0, r7, #1
 *   @0x22cad4 smull r2, r3, r3, r2
 *   @0x22cad8 lsl r2, r5, #1
 *   @0x22cadc rsb r0, r0, r1, lsl #1
 *   @0x22cae0 str r0, [r8, #0x10]
 *   @0x22cae4 add r2, r2, r3, lsl #1
 *   @0x22cae8 str r2, [r8, #0x14]
 *   @0x22caec ldr r2, [r12, #0x8]
 *   @0x22caf0 ldr r3, [r12, #0xc]
 *   @0x22caf4 add r1, r2, r6
 *   @0x22caf8 str r1, [r12, #0x8]
 *   @0x22cafc ldr r0, [r8, #0xc]
 *   @0x22cb00 rsb r2, r6, r2
 *   @0x22cb04 ldr r7, [sp, #0x2c]
 *   @0x22cb08 add r1, r0, r3
 *   @0x22cb0c str r1, [r12, #0xc]
 *   @0x22cb10 ldr r1, [sp, #0x30]
 *   @0x22cb14 rsb r0, r3, r0
 *   @0x22cb18 ldr r4, [r7, #0x4]
 *   @0x22cb1c ldr r3, [r1, r9]
 *   @0x22cb20 smull r6, r7, r2, r4
 *   @0x22cb24 ldr r6, [sp, #0x48]
 *   @0x22cb28 smull r4, r5, r0, r4
 *   @0x22cb2c smull r0, r1, r0, r3
 *   @0x22cb30 lsl r0, r7, #1
 *   @0x22cb34 smull r2, r3, r3, r2
 *   @0x22cb38 lsl r2, r5, #1
 *   @0x22cb3c ldr r5, [sp, #0x18]
 *   @0x22cb40 rsb r0, r0, r1, lsl #1
 *   @0x22cb44 str r0, [r8, #0x8]
 *   @0x22cb48 ldr r7, [sp, #0x50]
 *   @0x22cb4c add r2, r2, r3, lsl #1
 *   @0x22cb50 str r2, [r8, #0xc]
 *   @0x22cb54 ldr r0, [r11, #0x40]
 *   @0x22cb58 ldr r3, [r10, #0x40]
 *   @0x22cb5c add r2, r0, r3
 *   @0x22cb60 rsb r0, r3, r0
 *   @0x22cb64 str r2, [r11, #0x40]
 *   @0x22cb68 ldr r3, [r12, #0x4]
 *   @0x22cb6c ldr r2, [r8, #0x4]
 *   @0x22cb70 add r1, r2, r3
 *   @0x22cb74 str r1, [r12, #0x4]
 *   @0x22cb78 ldr r12, [sp, #0x60]
 *   @0x22cb7c rsb r2, r3, r2
 *   @0x22cb80 ldr r4, [r5, #0x4]
 *   @0x22cb84 ldr r3, [r6, r9]
 *   @0x22cb88 add r9, r7, r9
 *   @0x22cb8c cmp r9, r12
 *   @0x22cb90 ldr r12, [sp, #0x10]
 *   @0x22cb94 smull r6, r7, r2, r4
 *   @0x22cb98 sub r1, r12, #32
 *   @0x22cb9c smull r4, r5, r0, r4
 *   @0x22cba0 str r1, [sp, #0x10]
 *   @0x22cba4 smull r0, r1, r3, r0
 *   @0x22cba8 lsl r0, r7, #1
 *   @0x22cbac smull r2, r3, r2, r3
 *   @0x22cbb0 lsl r2, r5, #1
 *   @0x22cbb4 add r0, r0, r1, lsl #1
 *   @0x22cbb8 rsb r2, r2, r3, lsl #1
 *   @0x22cbbc str r2, [r10, #0x40]
 *   @0x22cbc0 str r0, [r8, #0x4]
 *   @0x22cbc4 ldr r8, [sp, #0x28]
 *   @0x22cbc8 sub r2, r8, #32
 *   @0x22cbcc str r2, [sp, #0x28]
 *   @0x22cbd0 bhi 0x22c9f8 <mdct_backward+0xa7c>
 *   @0x22cbd4 ldr r3, [sp, #0x78]
 *   @0x22cbd8 ldr r6, [sp, #0x70]
 *   @0x22cbdc add r3, r3, #1
 *   @0x22cbe0 ldr r4, [sp, #0x64]
 *   @0x22cbe4 ldr r5, [sp, #0x7c]
 *   @0x22cbe8 cmp r3, r6
 *   @0x22cbec str r3, [sp, #0x78]
 *   @0x22cbf0 add r4, r4, r5
 *   @0x22cbf4 str r4, [sp, #0x64]
 *   @0x22cbf8 bne 0x22c3d0 <mdct_backward+0x454>
 *   @0x22cbfc ldr r7, [sp, #0x98]
 *   @0x22cc00 ldr r8, [sp, #0x90]
 *   @0x22cc04 add r7, r7, #1
 *   @0x22cc08 str r7, [sp, #0x98]
 *   @0x22cc0c cmp r7, r8
 *   @0x22cc10 bne 0x22c328 <mdct_backward+0x3ac>
 *   @0x22cc14 ldr r1, [sp, #0x88]
 *   @0x22cc18 cmp r1, #0
 *   @0x22cc1c ble 0x22d47c <mdct_backward+0x1500>
 *   @0x22cc20 ldr r4, [sp, #0x88]
 *   @0x22cc24 movw r5, #0xaf3d
 *   @0x22cc28 movw r6, #0xc54d
 *   @0x22cc2c movt r5, #0x7641
 *   @0x22cc30 sub r3, r4, #1
 *   @0x22cc34 movt r6, #0x30fb
 *   @0x22cc38 movw r7, #0x799a
 *   @0x22cc3c mov r8, #0
 *   @0x22cc40 lsr r3, r3, #5
 *   @0x22cc44 movt r7, #0x5a82
 *   @0x22cc48 add r3, r3, #1
 *   @0x22cc4c str r5, [sp, #0x28]
 *   @0x22cc50 str r6, [sp, #0x20]
 *   @0x22cc54 lsl r3, r3, #7
 *   @0x22cc58 str r7, [sp, #0x10]
 *   @0x22cc5c str r8, [sp, #0x38]
 *   @0x22cc60 str r3, [sp, #0xf0]
 *   @0x22cc64 ldr r9, [sp, #0xbc]
 *   @0x22cc68 ldr r10, [sp, #0x38]
 *   @0x22cc6c add r12, r9, r10
 *   @0x22cc70 ldr r11, [r9, r10]
 *   @0x22cc74 ldr r0, [r12, #0x70]
 *   @0x22cc78 ldr r3, [r12, #0x30]
 *   @0x22cc7c ldr r1, [r12, #0x74]
 *   @0x22cc80 rsb r4, r3, r0
 *   @0x22cc84 ldr r2, [r12, #0x34]
 *   @0x22cc88 str r4, [sp, #0x30]
 *   @0x22cc8c add r3, r0, r3
 *   @0x22cc90 ldr r4, [r12, #0x10]
 *   @0x22cc94 rsb r9, r2, r1
 *   @0x22cc98 str r3, [sp, #0x40]
 *   @0x22cc9c add r2, r1, r2
 *   @0x22cca0 ldr r3, [r12, #0x50]
 *   @0x22cca4 str r2, [sp, #0x48]
 *   @0x22cca8 rsb r7, r3, r4
 *   @0x22ccac ldr r2, [r12, #0x60]
 *   @0x22ccb0 add r3, r4, r3
 *   @0x22ccb4 str r3, [sp, #0x60]
 *   @0x22ccb8 ldr r3, [r12, #0x20]
 *   @0x22ccbc ldr r0, [r12, #0x14]
 *   @0x22ccc0 rsb r4, r3, r2
 *   @0x22ccc4 add r3, r2, r3
 *   @0x22ccc8 ldr r2, [sp, #0x20]
 *   @0x22cccc str r3, [sp, #0x54]
 *   @0x22ccd0 ldr r3, [sp, #0x30]
 *   @0x22ccd4 ldr r1, [r12, #0x54]
 *   @0x22ccd8 ldr r5, [r12, #0x64]
 *   @0x22ccdc smull r2, r3, r3, r2
 *   @0x22cce0 ldr r10, [r12, #0x24]
 *   @0x22cce4 rsb r8, r1, r0
 *   @0x22cce8 add r1, r0, r1
 *   @0x22ccec rsb r6, r10, r5
 *   @0x22ccf0 ldr r0, [r12, #0x40]
 *   @0x22ccf4 ldr r10, [r12, #0x44]
 *   @0x22ccf8 str r11, [sp, #0xc]
 *   @0x22ccfc rsb r11, r0, r11
 *   @0x22cd00 strd r2, r3, [sp, #24]
 *   @0x22cd04 ldr r3, [r12, #0x4]
 *   @0x22cd08 ldr r2, [sp, #0x20]
 *   @0x22cd0c rsb r5, r10, r3
 *   @0x22cd10 str r11, [sp, #0x78]
 *   @0x22cd14 ldr r3, [sp, #0x28]
 *   @0x22cd18 ldr r11, [sp, #0x28]
 *   @0x22cd1c str r1, [sp, #0x64]
 *   @0x22cd20 smull r0, r1, r7, r11
 *   @0x22cd24 smull r10, r11, r9, r2
 *   @0x22cd28 smull r2, r3, r8, r3
 *   @0x22cd2c strd r2, r3, [sp, #136]
 *   @0x22cd30 ldr r3, [sp, #0x28]
 *   @0x22cd34 smull r2, r3, r4, r3
 *   @0x22cd38 strd r2, r3, [sp, #104]
 *   @0x22cd3c ldr r3, [sp, #0x78]
 *   @0x22cd40 ldr r2, [sp, #0x20]
 *   @0x22cd44 smull r2, r3, r3, r2
 *   @0x22cd48 strd r2, r3, [sp, #144]
 *   @0x22cd4c ldr r3, [sp, #0x1c]
 *   @0x22cd50 lsl r10, r3, #1
 *   @0x22cd54 ldr r3, [sp, #0x28]
 *   @0x22cd58 smull r2, r3, r9, r3
 *   @0x22cd5c lsl r9, r1, #1
 *   @0x22cd60 str r9, [sp, #0x2c]
 *   @0x22cd64 ldr r9, [sp, #0x8c]
 *   @0x22cd68 strd r2, r3, [sp, #112]
 *   @0x22cd6c ldr r2, [sp, #0x28]
 *   @0x22cd70 ldr r3, [sp, #0x20]
 *   @0x22cd74 smull r0, r1, r6, r2
 *   @0x22cd78 lsl r0, r11, #1
 *   @0x22cd7c smull r2, r3, r5, r3
 *   @0x22cd80 lsl r11, r9, #1
 *   @0x22cd84 ldr r9, [sp, #0x20]
 *   @0x22cd88 lsl r1, r1, #1
 *   @0x22cd8c strd r2, r3, [sp, #160]
 *   @0x22cd90 ldr r3, [sp, #0x20]
 *   @0x22cd94 smull r2, r3, r8, r3
 *   @0x22cd98 ldr r8, [sp, #0x6c]
 *   @0x22cd9c lsl r8, r8, #1
 *   @0x22cda0 str r8, [sp, #0x18]
 *   @0x22cda4 smull r8, r9, r7, r9
 *   @0x22cda8 strd r2, r3, [sp, #136]
 *   @0x22cdac ldr r3, [sp, #0x30]
 *   @0x22cdb0 ldr r2, [sp, #0x28]
 *   @0x22cdb4 smull r2, r3, r3, r2
 *   @0x22cdb8 strd r8, r9, [sp, #104]
 *   @0x22cdbc ldr r8, [sp, #0xa4]
 *   @0x22cdc0 ldr r9, [sp, #0x28]
 *   @0x22cdc4 strd r2, r3, [sp, #48]
 *   @0x22cdc8 ldr r3, [sp, #0x94]
 *   @0x22cdcc ldr r2, [sp, #0x20]
 *   @0x22cdd0 lsl r3, r3, #1
 *   @0x22cdd4 str r3, [sp, #0x4c]
 *   @0x22cdd8 lsl r3, r8, #1
 *   @0x22cddc smull r8, r9, r5, r9
 *   @0x22cde0 smull r6, r7, r6, r2
 *   @0x22cde4 ldr r2, [sp, #0x74]
 *   @0x22cde8 strd r8, r9, [sp, #144]
 *   @0x22cdec add r10, r10, r2, lsl #1
 *   @0x22cdf0 ldr r8, [sp, #0x20]
 *   @0x22cdf4 ldr r2, [sp, #0x8c]
 *   @0x22cdf8 ldr r9, [sp, #0x2c]
 *   @0x22cdfc smull r4, r5, r4, r8
 *   @0x22ce00 rsb r9, r9, r2, lsl #1
 *   @0x22ce04 ldr r8, [sp, #0x28]
 *   @0x22ce08 str r9, [sp, #0xb0]
 *   @0x22ce0c ldr r9, [sp, #0x78]
 *   @0x22ce10 rsb r1, r1, r5, lsl #1
 *   @0x22ce14 smull r8, r9, r9, r8
 *   @0x22ce18 strd r8, r9, [sp, #160]
 *   @0x22ce1c ldr r9, [sp, #0x34]
 *   @0x22ce20 ldr r2, [sp, #0x18]
 *   @0x22ce24 ldr r8, [sp, #0xa4]
 *   @0x22ce28 rsb r0, r0, r9, lsl #1
 *   @0x22ce2c str r0, [sp, #0x88]
 *   @0x22ce30 ldr r0, [sp, #0x6c]
 *   @0x22ce34 add r2, r2, r7, lsl #1
 *   @0x22ce38 ldr r7, [sp, #0x94]
 *   @0x22ce3c add r3, r3, r8, lsl #1
 *   @0x22ce40 ldr r6, [sp, #0x4c]
 *   @0x22ce44 add r11, r11, r0, lsl #1
 *   @0x22ce48 str r1, [sp, #0x90]
 *   @0x22ce4c ldr r0, [r12, #0x68]
 *   @0x22ce50 ldr r1, [r12, #0x28]
 *   @0x22ce54 str r11, [sp, #0xa8]
 *   @0x22ce58 rsb r11, r6, r7, lsl #1
 *   @0x22ce5c rsb r9, r1, r0
 *   @0x22ce60 str r2, [sp, #0xac]
 *   @0x22ce64 str r3, [sp, #0xa0]
 *   @0x22ce68 ldr r2, [r12, #0x6c]
 *   @0x22ce6c ldr r3, [r12, #0x2c]
 *   @0x22ce70 ldr r4, [r12, #0x8]
 *   @0x22ce74 ldr r5, [r12, #0x48]
 *   @0x22ce78 rsb r8, r3, r2
 *   @0x22ce7c ldr r6, [r12, #0xc]
 *   @0x22ce80 ldr r7, [r12, #0x4c]
 *   @0x22ce84 rsb r0, r5, r4
 *   @0x22ce88 ldr r1, [sp, #0xb0]
 *   @0x22ce8c rsb r2, r7, r6
 *   @0x22ce90 ldr r3, [sp, #0x88]
 *   @0x22ce94 rsb r5, r1, r10
 *   @0x22ce98 ldr r4, [sp, #0xa8]
 *   @0x22ce9c ldr r1, [r12, #0x24]
 *   @0x22cea0 ldr r6, [r12, #0x64]
 *   @0x22cea4 rsb r7, r4, r3
 *   @0x22cea8 ldr r4, [sp, #0xac]
 *   @0x22ceac add r6, r6, r1
 *   @0x22ceb0 ldr r1, [r12, #0x40]
 *   @0x22ceb4 str r6, [sp, #0x58]
 *   @0x22ceb8 rsb r3, r4, r11
 *   @0x22cebc ldr r6, [sp, #0xc]
 *   @0x22cec0 ldr r4, [sp, #0xa0]
 *   @0x22cec4 add r6, r6, r1
 *   @0x22cec8 str r6, [sp, #0x7c]
 *   @0x22cecc ldr r6, [sp, #0x90]
 *   @0x22ced0 rsb r1, r6, r4
 *   @0x22ced4 ldr r6, [r12, #0x44]
 *   @0x22ced8 ldr r4, [r12, #0x4]
 *   @0x22cedc add r4, r4, r6
 *   @0x22cee0 add r6, r9, r8
 *   @0x22cee4 str r4, [sp, #0x80]
 *   @0x22cee8 rsb r8, r8, r9
 *   @0x22ceec str r8, [sp, #0x18]
 *   @0x22cef0 rsb r4, r0, r2
 *   @0x22cef4 ldr r8, [sp, #0x10]
 *   @0x22cef8 add r2, r0, r2
 *   @0x22cefc add r0, r7, r5
 *   @0x22cf00 rsb r5, r5, r7
 *   @0x22cf04 ldr r9, [sp, #0x7c]
 *   @0x22cf08 smull r6, r7, r6, r8
 *   @0x22cf0c str r2, [sp, #0x98]
 *   @0x22cf10 str r5, [sp, #0xb8]
 *   @0x22cf14 rsb r2, r1, r3
 *   @0x22cf18 smull r4, r5, r4, r8
 *   @0x22cf1c add r3, r1, r3
 *   @0x22cf20 ldr r8, [sp, #0x58]
 *   @0x22cf24 lsl r4, r7, #1
 *   @0x22cf28 ldr r1, [sp, #0x54]
 *   @0x22cf2c str r3, [sp, #0xb4]
 *   @0x22cf30 ldr r3, [sp, #0x80]
 *   @0x22cf34 rsb r6, r1, r9
 *   @0x22cf38 ldr r7, [sp, #0x40]
 *   @0x22cf3c rsb r9, r8, r3
 *   @0x22cf40 ldr r3, [sp, #0x10]
 *   @0x22cf44 ldr r8, [sp, #0x60]
 *   @0x22cf48 smull r0, r1, r0, r3
 *   @0x22cf4c lsl r0, r5, #1
 *   @0x22cf50 smull r2, r3, r2, r3
 *   @0x22cf54 rsb r5, r8, r7
 *   @0x22cf58 ldr r7, [sp, #0x48]
 *   @0x22cf5c ldr r8, [sp, #0x64]
 *   @0x22cf60 rsb r2, r8, r7
 *   @0x22cf64 rsb r8, r6, r9
 *   @0x22cf68 add r9, r6, r9
 *   @0x22cf6c str r8, [sp, #0xd8]
 *   @0x22cf70 str r9, [sp, #0xc0]
 *   @0x22cf74 add r9, r5, r2
 *   @0x22cf78 ldr r8, [sp, #0x18]
 *   @0x22cf7c lsl r7, r1, #1
 *   @0x22cf80 str r9, [sp, #0xe0]
 *   @0x22cf84 rsb r2, r2, r5
 *   @0x22cf88 ldr r9, [sp, #0x10]
 *   @0x22cf8c lsl r6, r3, #1
 *   @0x22cf90 ldr r5, [r12, #0x28]
 *   @0x22cf94 ldr r3, [r12, #0x2c]
 *   @0x22cf98 str r2, [sp, #0xdc]
 *   @0x22cf9c ldr r1, [r12, #0x68]
 *   @0x22cfa0 ldr r2, [r12, #0x6c]
 *   @0x22cfa4 add r1, r1, r5
 *   @0x22cfa8 str r7, [sp, #0xd0]
 *   @0x22cfac add r2, r2, r3
 *   @0x22cfb0 str r6, [sp, #0x84]
 *   @0x22cfb4 ldr r3, [r12, #0x4c]
 *   @0x22cfb8 smull r6, r7, r8, r9
 *   @0x22cfbc ldr r5, [r12, #0x8]
 *   @0x22cfc0 ldr r8, [r12, #0x48]
 *   @0x22cfc4 ldr r9, [r12, #0xc]
 *   @0x22cfc8 ldr r6, [r12, #0x38]
 *   @0x22cfcc add r5, r5, r8
 *   @0x22cfd0 add r9, r9, r3
 *   @0x22cfd4 str r1, [sp, #0x4c]
 *   @0x22cfd8 str r2, [sp, #0x50]
 *   @0x22cfdc lsl r8, r7, #1
 *   @0x22cfe0 ldr r1, [r12, #0x78]
 *   @0x22cfe4 ldr r2, [r12, #0x1c]
 *   @0x22cfe8 str r5, [sp, #0x5c]
 *   @0x22cfec str r9, [sp, #0x78]
 *   @0x22cff0 rsb r9, r4, r0
 *   @0x22cff4 ldr r5, [sp, #0xb0]
 *   @0x22cff8 add r0, r4, r0
 *   @0x22cffc ldr r3, [r12, #0x5c]
 *   @0x22d000 add r10, r10, r5
 *   @0x22d004 rsb r5, r6, r1
 *   @0x22d008 str r10, [sp, #0xb0]
 *   @0x22d00c add r6, r1, r6
 *   @0x22d010 ldr r10, [sp, #0x98]
 *   @0x22d014 rsb r1, r3, r2
 *   @0x22d018 str r6, [sp, #0x30]
 *   @0x22d01c add r3, r2, r3
 *   @0x22d020 ldr r6, [sp, #0x10]
 *   @0x22d024 str r3, [sp, #0x2c]
 *   @0x22d028 ldr r7, [sp, #0x88]
 *   @0x22d02c smull r2, r3, r10, r6
 *   @0x22d030 ldr r10, [sp, #0xac]
 *   @0x22d034 ldr r6, [sp, #0xa0]
 *   @0x22d038 add r11, r10, r11
 *   @0x22d03c str r8, [sp, #0x18]
 *   @0x22d040 str r11, [sp, #0x68]
 *   @0x22d044 ldr r8, [sp, #0xa8]
 *   @0x22d048 ldr r11, [sp, #0x90]
 *   @0x22d04c add r7, r7, r8
 *   @0x22d050 ldr r8, [sp, #0xd0]
 *   @0x22d054 add r11, r11, r6
 *   @0x22d058 str r11, [sp, #0x70]
 *   @0x22d05c ldr r11, [sp, #0x84]
 *   @0x22d060 ldr r2, [sp, #0xb4]
 *   @0x22d064 rsb r8, r11, r8
 *   @0x22d068 lsl r11, r3, #1
 *   @0x22d06c ldr r3, [sp, #0x10]
 *   @0x22d070 str r7, [sp, #0x88]
 *   @0x22d074 rsb r7, r1, r5
 *   @0x22d078 str r0, [sp, #0x98]
 *   @0x22d07c add r1, r5, r1
 *   @0x22d080 str r1, [sp, #0x90]
 *   @0x22d084 smull r0, r1, r2, r3
 *   @0x22d088 ldr r3, [sp, #0xb8]
 *   @0x22d08c ldr r2, [sp, #0x10]
 *   @0x22d090 ldr r5, [sp, #0x7c]
 *   @0x22d094 ldr r4, [sp, #0x54]
 *   @0x22d098 smull r2, r3, r3, r2
 *   @0x22d09c add r4, r4, r5
 *   @0x22d0a0 str r4, [sp, #0x7c]
 *   @0x22d0a4 ldr r4, [sp, #0x80]
 *   @0x22d0a8 ldr r10, [r12, #0x7c]
 *   @0x22d0ac ldr r6, [r12, #0x3c]
 *   @0x22d0b0 strd r2, r3, [sp, #160]
 *   @0x22d0b4 ldr r3, [sp, #0x58]
 *   @0x22d0b8 str r8, [sp, #0xac]
 *   @0x22d0bc add r3, r3, r4
 *   @0x22d0c0 ldr r8, [r12, #0x58]
 *   @0x22d0c4 str r3, [sp, #0x80]
 *   @0x22d0c8 ldr r3, [sp, #0x10]
 *   @0x22d0cc ldr r2, [sp, #0xd8]
 *   @0x22d0d0 smull r4, r5, r2, r3
 *   @0x22d0d4 lsl r2, r1, #1
 *   @0x22d0d8 ldr r1, [sp, #0xe0]
 *   @0x22d0dc str r2, [sp, #0xd8]
 *   @0x22d0e0 smull r0, r1, r1, r3
 *   @0x22d0e4 strd r0, r1, [sp]
 *   @0x22d0e8 ldr r0, [sp, #0xc0]
 *   @0x22d0ec ldr r1, [sp, #0xa4]
 *   @0x22d0f0 lsl r1, r1, #1
 *   @0x22d0f4 str r1, [sp, #0x54]
 *   @0x22d0f8 mov r1, r3
 *   @0x22d0fc smull r2, r3, r0, r3
 *   @0x22d100 lsl r0, r5, #1
 *   @0x22d104 str r0, [sp, #0xa8]
 *   @0x22d108 ldr r0, [sp, #0xdc]
 *   @0x22d10c ldr r2, [sp, #0xd0]
 *   @0x22d110 smull r4, r5, r0, r1
 *   @0x22d114 ldr r0, [sp, #0x60]
 *   @0x22d118 ldr r1, [sp, #0x40]
 *   @0x22d11c ldr r4, [sp, #0x18]
 *   @0x22d120 add r1, r1, r0
 *   @0x22d124 ldr r0, [sp, #0x64]
 *   @0x22d128 str r1, [sp, #0xa0]
 *   @0x22d12c ldr r1, [sp, #0x48]
 *   @0x22d130 add r1, r1, r0
 *   @0x22d134 str r1, [sp, #0xb4]
 *   @0x22d138 ldr r1, [sp, #0x4]
 *   @0x22d13c lsl r0, r3, #1
 *   @0x22d140 str r0, [sp, #0x64]
 *   @0x22d144 rsb r0, r9, r7
 *   @0x22d148 add r7, r9, r7
 *   @0x22d14c ldr r9, [sp, #0xbc]
 *   @0x22d150 lsl r1, r1, #1
 *   @0x22d154 str r1, [sp, #0xb8]
 *   @0x22d158 ldr r1, [sp, #0x84]
 *   @0x22d15c str r7, [sp, #0x58]
 *   @0x22d160 add r1, r1, r2
 *   @0x22d164 ldr r7, [sp, #0x38]
 *   @0x22d168 str r1, [sp, #0x48]
 *   @0x22d16c ldr r1, [sp, #0xac]
 *   @0x22d170 str r0, [sp, #0x60]
 *   @0x22d174 add r2, r1, r0
 *   @0x22d178 ldr r0, [sp, #0xf0]
 *   @0x22d17c ldr r3, [r12, #0x18]
 *   @0x22d180 lsl r1, r5, #1
 *   @0x22d184 str r2, [r9, r7]
 *   @0x22d188 add r7, r7, #128
 *   @0x22d18c ldr r5, [sp, #0x78]
 *   @0x22d190 cmp r7, r0
 *   @0x22d194 ldr r0, [sp, #0x50]
 *   @0x22d198 rsb r2, r6, r10
 *   @0x22d19c rsb r9, r3, r8
 *   @0x22d1a0 str r7, [sp, #0x38]
 *   @0x22d1a4 add r3, r8, r3
 *   @0x22d1a8 str r1, [sp, #0x84]
 *   @0x22d1ac rsb r8, r9, r2
 *   @0x22d1b0 add r1, r0, r5
 *   @0x22d1b4 add r9, r2, r9
 *   @0x22d1b8 str r1, [sp, #0x78]
 *   @0x22d1bc ldr r2, [sp, #0x30]
 *   @0x22d1c0 rsb r7, r0, r5
 *   @0x22d1c4 add r6, r10, r6
 *   @0x22d1c8 rsb r10, r11, r4
 *   @0x22d1cc rsb r5, r3, r2
 *   @0x22d1d0 add r11, r4, r11
 *   @0x22d1d4 add r3, r2, r3
 *   @0x22d1d8 ldr r4, [sp, #0x5c]
 *   @0x22d1dc str r3, [sp, #0xd0]
 *   @0x22d1e0 ldr r3, [sp, #0x4c]
 *   @0x22d1e4 rsb r0, r4, r3
 *   @0x22d1e8 add r2, r3, r4
 *   @0x22d1ec ldr r3, [sp, #0x2c]
 *   @0x22d1f0 ldr r4, [sp, #0x54]
 *   @0x22d1f4 rsb r1, r3, r6
 *   @0x22d1f8 add r6, r6, r3
 *   @0x22d1fc ldr r3, [sp, #0xd8]
 *   @0x22d200 rsb r4, r3, r4
 *   @0x22d204 str r4, [sp, #0x40]
 *   @0x22d208 ldr r4, [sp, #0x54]
 *   @0x22d20c add r4, r3, r4
 *   @0x22d210 str r4, [sp, #0x30]
 *   @0x22d214 rsb r4, r10, r8
 *   @0x22d218 add r8, r10, r8
 *   @0x22d21c ldr r10, [sp, #0x68]
 *   @0x22d220 str r8, [sp, #0xc0]
 *   @0x22d224 ldr r8, [sp, #0xb0]
 *   @0x22d228 ldr r3, [sp, #0xb0]
 *   @0x22d22c rsb r8, r10, r8
 *   @0x22d230 str r8, [sp, #0x18]
 *   @0x22d234 ldr r8, [sp, #0x90]
 *   @0x22d238 add r3, r10, r3
 *   @0x22d23c str r3, [sp, #0x50]
 *   @0x22d240 rsb r10, r11, r8
 *   @0x22d244 ldr r3, [sp, #0x70]
 *   @0x22d248 add r11, r11, r8
 *   @0x22d24c ldr r8, [sp, #0x88]
 *   @0x22d250 str r11, [sp, #0x2c]
 *   @0x22d254 ldr r11, [sp, #0x88]
 *   @0x22d258 add r8, r3, r8
 *   @0x22d25c str r8, [sp, #0x4c]
 *   @0x22d260 rsb r11, r3, r11
 *   @0x22d264 ldr r3, [sp, #0x98]
 *   @0x22d268 str r11, [sp, #0xb0]
 *   @0x22d26c ldr r11, [sp, #0x98]
 *   @0x22d270 ldr r8, [sp, #0xb8]
 *   @0x22d274 rsb r11, r11, r9
 *   @0x22d278 add r9, r3, r9
 *   @0x22d27c str r11, [sp, #0x54]
 *   @0x22d280 ldr r3, [sp, #0xb8]
 *   @0x22d284 ldr r11, [sp, #0xa8]
 *   @0x22d288 rsb r8, r11, r8
 *   @0x22d28c add r3, r11, r3
 *   @0x22d290 ldr r11, [sp, #0x84]
 *   @0x22d294 str r3, [sp, #0x70]
 *   @0x22d298 ldr r3, [sp, #0x64]
 *   @0x22d29c str r8, [sp, #0x68]
 *   @0x22d2a0 rsb r8, r7, r5
 *   @0x22d2a4 add r5, r7, r5
 *   @0x22d2a8 str r8, [sp, #0x88]
 *   @0x22d2ac add r7, r3, r11
 *   @0x22d2b0 str r5, [sp, #0x98]
 *   @0x22d2b4 str r7, [sp, #0x5c]
 *   @0x22d2b8 rsb r5, r3, r11
 *   @0x22d2bc rsb r7, r0, r1
 *   @0x22d2c0 ldr r11, [sp, #0x80]
 *   @0x22d2c4 add r1, r0, r1
 *   @0x22d2c8 ldr r8, [sp, #0xb4]
 *   @0x22d2cc ldr r0, [sp, #0xb4]
 *   @0x22d2d0 ldr r3, [sp, #0xd0]
 *   @0x22d2d4 rsb r8, r11, r8
 *   @0x22d2d8 add r0, r11, r0
 *   @0x22d2dc str r8, [sp, #0x90]
 *   @0x22d2e0 ldr r11, [sp, #0x7c]
 *   @0x22d2e4 ldr r8, [sp, #0xa0]
 *   @0x22d2e8 str r0, [sp, #0x84]
 *   @0x22d2ec rsb r0, r2, r3
 *   @0x22d2f0 rsb r8, r11, r8
 *   @0x22d2f4 add r2, r2, r3
 *   @0x22d2f8 str r8, [sp, #0x80]
 *   @0x22d2fc str r2, [sp, #0xa8]
 *   @0x22d300 ldr r8, [sp, #0x78]
 *   @0x22d304 ldr r2, [sp, #0xa0]
 *   @0x22d308 ldr r3, [sp, #0x78]
 *   @0x22d30c add r2, r11, r2
 *   @0x22d310 ldr r11, [sp, #0x60]
 *   @0x22d314 rsb r3, r3, r6
 *   @0x22d318 str r2, [sp, #0x64]
 *   @0x22d31c add r6, r8, r6
 *   @0x22d320 ldr r2, [sp, #0xac]
 *   @0x22d324 ldr r8, [sp, #0x40]
 *   @0x22d328 str r3, [sp, #0x7c]
 *   @0x22d32c rsb r3, r2, r11
 *   @0x22d330 rsb r2, r8, r4
 *   @0x22d334 ldr r11, [sp, #0x58]
 *   @0x22d338 add r4, r8, r4
 *   @0x22d33c ldr r8, [sp, #0x30]
 *   @0x22d340 str r2, [r12, #0x4]
 *   @0x22d344 str r3, [r12, #0x8]
 *   @0x22d348 rsb r2, r8, r11
 *   @0x22d34c add r3, r8, r11
 *   @0x22d350 str r4, [r12, #0xc]
 *   @0x22d354 ldr r11, [sp, #0xc0]
 *   @0x22d358 ldr r4, [sp, #0x48]
 *   @0x22d35c str r2, [r12, #0x10]
 *   @0x22d360 add r8, r4, r11
 *   @0x22d364 rsb r2, r4, r11
 *   @0x22d368 ldr r11, [sp, #0x18]
 *   @0x22d36c ldr r4, [sp, #0xb0]
 *   @0x22d370 str r2, [r12, #0x14]
 *   @0x22d374 ldr r2, [sp, #0x54]
 *   @0x22d378 str r3, [r12, #0x18]
 *   @0x22d37c add r3, r11, r10
 *   @0x22d380 str r8, [r12, #0x1c]
 *   @0x22d384 rsb r10, r11, r10
 *   @0x22d388 str r3, [r12, #0x20]
 *   @0x22d38c add r11, r4, r2
 *   @0x22d390 str r10, [r12, #0x28]
 *   @0x22d394 rsb r3, r4, r2
 *   @0x22d398 ldr r8, [sp, #0x2c]
 *   @0x22d39c ldr r10, [sp, #0x4c]
 *   @0x22d3a0 str r11, [r12, #0x2c]
 *   @0x22d3a4 ldr r11, [sp, #0x50]
 *   @0x22d3a8 add r2, r10, r8
 *   @0x22d3ac ldr r4, [sp, #0x88]
 *   @0x22d3b0 str r3, [r12, #0x24]
 *   @0x22d3b4 rsb r3, r10, r8
 *   @0x22d3b8 str r2, [r12, #0x38]
 *   @0x22d3bc ldr r10, [sp, #0x5c]
 *   @0x22d3c0 ldr r2, [sp, #0x68]
 *   @0x22d3c4 str r3, [r12, #0x30]
 *   @0x22d3c8 rsb r3, r11, r9
 *   @0x22d3cc add r9, r11, r9
 *   @0x22d3d0 str r9, [r12, #0x3c]
 *   @0x22d3d4 ldr r9, [sp, #0x98]
 *   @0x22d3d8 ldr r11, [sp, #0x70]
 *   @0x22d3dc ldr r8, [sp, #0x64]
 *   @0x22d3e0 str r3, [r12, #0x34]
 *   @0x22d3e4 add r3, r2, r4
 *   @0x22d3e8 rsb r2, r2, r4
 *   @0x22d3ec str r3, [r12, #0x40]
 *   @0x22d3f0 ldr r4, [sp, #0x7c]
 *   @0x22d3f4 rsb r3, r5, r7
 *   @0x22d3f8 str r2, [r12, #0x48]
 *   @0x22d3fc add r5, r5, r7
 *   @0x22d400 add r2, r10, r9
 *   @0x22d404 ldr r7, [sp, #0xa8]
 *   @0x22d408 str r3, [r12, #0x44]
 *   @0x22d40c rsb r3, r10, r9
 *   @0x22d410 str r5, [r12, #0x4c]
 *   @0x22d414 ldr r9, [sp, #0x84]
 *   @0x22d418 ldr r5, [sp, #0x80]
 *   @0x22d41c str r2, [r12, #0x58]
 *   @0x22d420 ldr r2, [sp, #0x90]
 *   @0x22d424 str r3, [r12, #0x50]
 *   @0x22d428 rsb r3, r11, r1
 *   @0x22d42c add r1, r11, r1
 *   @0x22d430 str r3, [r12, #0x54]
 *   @0x22d434 str r1, [r12, #0x5c]
 *   @0x22d438 add r3, r2, r0
 *   @0x22d43c rsb r0, r2, r0
 *   @0x22d440 str r3, [r12, #0x60]
 *   @0x22d444 add r2, r5, r4
 *   @0x22d448 rsb r3, r5, r4
 *   @0x22d44c str r2, [r12, #0x6c]
 *   @0x22d450 add r2, r8, r7
 *   @0x22d454 str r3, [r12, #0x64]
 *   @0x22d458 rsb r3, r8, r7
 *   @0x22d45c str r0, [r12, #0x68]
 *   @0x22d460 str r3, [r12, #0x70]
 *   @0x22d464 rsb r3, r9, r6
 *   @0x22d468 str r2, [r12, #0x78]
 *   @0x22d46c add r6, r9, r6
 *   @0x22d470 str r3, [r12, #0x74]
 *   @0x22d474 str r6, [r12, #0x7c]
 *   @0x22d478 bne 0x22cc64 <mdct_backward+0xce8>
 *   @0x22d47c ldr r2, [sp, #0xf8]
 *   @0x22d480 cmp r2, #3
 *   @0x22d484 ble 0x22daf0 <mdct_backward+0x1b74>
 *   @0x22d488 ldr r10, [sp, #0xf8]
 *   @0x22d48c ldr r3, [pc, #-0xca0]
 *   @0x22d490 asr r2, r10, #1
 *   @0x22d494 add r3, pc, r3
 *   @0x22d498 add r9, r3, r2, lsl #2
 *   @0x22d49c ldr r11, [pc, #-0xcac]
 *   @0x22d4a0 add r12, r9, #4096
 *   @0x22d4a4 ldr r10, [sp, #0xbc]
 *   @0x22d4a8 mov r0, #0
 *   @0x22d4ac add r11, pc, r11
 *   @0x22d4b0 str r11, [sp, #0x20]
 *   @0x22d4b4 ldr r11, [sp, #0xf4]
 *   @0x22d4b8 str r12, [sp, #0x48]
 *   @0x22d4bc mov r12, r10
 *   @0x22d4c0 str r0, [sp, #0x10]
 *   @0x22d4c4 str r11, [sp, #0x28]
 *   @0x22d4c8 mov r11, r10
 *   @0x22d4cc ldr r1, [sp, #0x10]
 *   @0x22d4d0 mov r7, r9
 *   @0x22d4d4 ldr r4, [sp, #0x10]
 *   @0x22d4d8 sub r11, r11, #16
 *   @0x22d4dc ldr r3, [sp, #0x20]
 *   @0x22d4e0 and r2, r1, #15
 *   @0x22d4e4 ldr r5, [sp, #0x20]
 *   @0x22d4e8 ubfx r1, r1, #0x4, #0x4
 *   @0x22d4ec add r2, r3, r2
 *   @0x22d4f0 add r3, r3, r4, asr #8
 *   @0x22d4f4 add r1, r5, r1
 *   @0x22d4f8 ldr r6, [sp, #0xe4]
 *   @0x22d4fc ldrb r2, [r2, #0x10]
 *   @0x22d500 add r0, r4, #1
 *   @0x22d504 ldrb r3, [r3, #0x10]
 *   @0x22d508 and r4, r0, #15
 *   @0x22d50c ldrb r1, [r1, #0x10]
 *   @0x22d510 add r4, r5, r4
 *   @0x22d514 orr r2, r3, r2, lsl #8
 *   @0x22d518 ldr r10, [sp, #0x9c]
 *   @0x22d51c ldr r3, [r7], r6
 *   @0x22d520 orr r2, r2, r1, lsl #4
 *   @0x22d524 ldrb r6, [r4, #0x10]
 *   @0x22d528 eor r1, r2, #4080
 *   @0x22d52c ldr r8, [sp, #0x10]
 *   @0x22d530 eor r1, r1, #15
 *   @0x22d534 asr r2, r2, r10
 *   @0x22d538 str r7, [sp, #0x38]
 *   @0x22d53c ubfx r7, r0, #0x4, #0x4
 *   @0x22d540 asr r1, r1, r10
 *   @0x22d544 add r0, r5, r0, asr #8
 *   @0x22d548 sub r1, r1, #-1073741823
 *   @0x22d54c add r7, r5, r7
 *   @0x22d550 add r4, r12, r2, lsl #2
 *   @0x22d554 ldrb r0, [r0, #0x10]
 *   @0x22d558 add r5, r12, r1, lsl #2
 *   @0x22d55c add r8, r8, #2
 *   @0x22d560 ldr r4, [r4, #0x4]
 *   @0x22d564 orr r0, r0, r6, lsl #8
 *   @0x22d568 str r8, [sp, #0x10]
 *   @0x22d56c ldrb r8, [r7, #0x10]
 *   @0x22d570 ldr r6, [r5, #0x4]
 *   @0x22d574 str r4, [sp, #0x18]
 *   @0x22d578 orr r8, r0, r8, lsl #4
 *   @0x22d57c rsb r0, r6, r4
 *   @0x22d580 ldr r4, [sp, #0x9c]
 *   @0x22d584 eor r7, r8, #4080
 *   @0x22d588 eor r7, r7, #15
 *   @0x22d58c ldr r10, [r12, r1, lsl #2]
 *   @0x22d590 asr r8, r8, r4
 *   @0x22d594 ldr r1, [r12, r2, lsl #2]
 *   @0x22d598 smull r4, r5, r0, r3
 *   @0x22d59c add r2, r10, r1
 *   @0x22d5a0 rsb r10, r1, r10
 *   @0x22d5a4 asr r10, r10, #1
 *   @0x22d5a8 strd r4, r5, [sp, #64]
 *   @0x22d5ac ldr r5, [sp, #0x9c]
 *   @0x22d5b0 asr r4, r7, r5
 *   @0x22d5b4 ldr r7, [sp, #0x18]
 *   @0x22d5b8 sub r4, r4, #-1073741823
 *   @0x22d5bc add r5, r7, r6
 *   @0x22d5c0 ldr r7, [r9, #0x4]
 *   @0x22d5c4 asr r5, r5, #1
 *   @0x22d5c8 str r5, [sp, #0x2c]
 *   @0x22d5cc smull r6, r7, r2, r7
 *   @0x22d5d0 smull r2, r3, r2, r3
 *   @0x22d5d4 add r2, r12, r8, lsl #2
 *   @0x22d5d8 strd r6, r7, [sp, #48]
 *   @0x22d5dc ldr r7, [r9, #0x4]
 *   @0x22d5e0 ldr r1, [sp, #0x34]
 *   @0x22d5e4 smull r6, r7, r7, r0
 *   @0x22d5e8 ldr r0, [sp, #0x44]
 *   @0x22d5ec rsb r3, r3, r7
 *   @0x22d5f0 add r5, r1, r0
 *   @0x22d5f4 add r0, r12, r4, lsl #2
 *   @0x22d5f8 strd r6, r7, [sp, #24]
 *   @0x22d5fc ldr r7, [sp, #0x28]
 *   @0x22d600 ldr r6, [sp, #0x2c]
 *   @0x22d604 add r1, r6, r5
 *   @0x22d608 str r1, [r7]
 *   @0x22d60c add r1, r10, r3
 *   @0x22d610 str r1, [r7, #0x4]
 *   @0x22d614 ldr r1, [sp, #0x38]
 *   @0x22d618 rsb r5, r5, r6
 *   @0x22d61c rsb r3, r10, r3
 *   @0x22d620 str r5, [r11, #0x8]
 *   @0x22d624 str r3, [r11, #0xc]
 *   @0x22d628 ldr r5, [r12, r4, lsl #2]
 *   @0x22d62c ldr r10, [r12, r8, lsl #2]
 *   @0x22d630 ldr r4, [r0, #0x4]
 *   @0x22d634 ldr r0, [r1, #0x4]
 *   @0x22d638 ldr r8, [r2, #0x4]
 *   @0x22d63c add r2, r5, r10
 *   @0x22d640 rsb r10, r10, r5
 *   @0x22d644 ldr r6, [sp, #0xe4]
 *   @0x22d648 rsb r1, r4, r8
 *   @0x22d64c add r7, r8, r4
 *   @0x22d650 smull r4, r5, r2, r0
 *   @0x22d654 ldr r3, [r9, r6]
 *   @0x22d658 asr r8, r7, #1
 *   @0x22d65c ldr r6, [sp, #0x48]
 *   @0x22d660 asr r10, r10, #1
 *   @0x22d664 strd r4, r5, [sp, #48]
 *   @0x22d668 ldr r5, [sp, #0xc8]
 *   @0x22d66c ldr r7, [sp, #0x34]
 *   @0x22d670 add r9, r9, r5
 *   @0x22d674 smull r4, r5, r1, r3
 *   @0x22d678 cmp r6, r9
 *   @0x22d67c smull r0, r1, r0, r1
 *   @0x22d680 smull r2, r3, r2, r3
 *   @0x22d684 add r2, r7, r5
 *   @0x22d688 rsb r3, r3, r1
 *   @0x22d68c add r1, r8, r2
 *   @0x22d690 rsb r2, r2, r8
 *   @0x22d694 ldr r8, [sp, #0x28]
 *   @0x22d698 add r8, r8, #16
 *   @0x22d69c str r1, [r8, #-0x8]
 *   @0x22d6a0 add r1, r10, r3
 *   @0x22d6a4 rsb r3, r10, r3
 *   @0x22d6a8 str r1, [r8, #-0x4]
 *   @0x22d6ac str r8, [sp, #0x28]
 *   @0x22d6b0 stm r11, {r2, r3}
 *   @0x22d6b4 bhi 0x22d4cc <mdct_backward+0x1550>
 *   @0x22d6b8 ldr r12, [pc, #-0xec4]
 *   @0x22d6bc mov r10, r11
 *   @0x22d6c0 mov r11, r8
 *   @0x22d6c4 str r10, [sp, #0x28]
 *   @0x22d6c8 add r12, pc, r12
 *   @0x22d6cc str r12, [sp, #0x20]
 *   @0x22d6d0 ldr r12, [sp, #0xbc]
 *   @0x22d6d4 mov r10, r9
 *   @0x22d6d8 ldr r1, [sp, #0x10]
 *   @0x22d6dc add r11, r11, #16
 *   @0x22d6e0 ldr r3, [sp, #0x10]
 *   @0x22d6e4 ldr r2, [sp, #0x20]
 *   @0x22d6e8 and r0, r1, #15
 *   @0x22d6ec ldr r4, [sp, #0x20]
 *   @0x22d6f0 ubfx r1, r1, #0x4, #0x4
 *   @0x22d6f4 add r0, r2, r0
 *   @0x22d6f8 add r2, r2, r3, asr #8
 *   @0x22d6fc add r1, r4, r1
 *   @0x22d700 ldr r5, [sp, #0xcc]
 *   @0x22d704 ldrb r4, [r0, #0x10]
 *   @0x22d708 ldrb r2, [r2, #0x10]
 *   @0x22d70c add r3, r10, r5
 *   @0x22d710 ldrb r1, [r1, #0x10]
 *   @0x22d714 ldr r7, [sp, #0x10]
 *   @0x22d718 orr r2, r2, r4, lsl #8
 *   @0x22d71c ldr r8, [r10, r5]
 *   @0x22d720 orr r1, r2, r1, lsl #4
 *   @0x22d724 add r0, r7, #1
 *   @0x22d728 eor r7, r1, #4080
 *   @0x22d72c ldr r9, [sp, #0x9c]
 *   @0x22d730 eor r7, r7, #15
 *   @0x22d734 ldr r6, [sp, #0x28]
 *   @0x22d738 ldr r5, [sp, #0x20]
 *   @0x22d73c and r2, r0, #15
 *   @0x22d740 str r8, [sp, #0x8]
 *   @0x22d744 asr r7, r7, r9
 *   @0x22d748 ldr r8, [sp, #0x20]
 *   @0x22d74c asr r1, r1, r9
 *   @0x22d750 ldr r4, [sp, #0x10]
 *   @0x22d754 sub r7, r7, #-1073741823
 *   @0x22d758 sub r6, r6, #16
 *   @0x22d75c add r2, r5, r2
 *   @0x22d760 str r6, [sp, #0x28]
 *   @0x22d764 ubfx r6, r0, #0x4, #0x4
 *   @0x22d768 add r6, r8, r6
 *   @0x22d76c add r0, r8, r0, asr #8
 *   @0x22d770 ldrb r5, [r2, #0x10]
 *   @0x22d774 add r4, r4, #2
 *   @0x22d778 add r2, r12, r7, lsl #2
 *   @0x22d77c str r4, [sp, #0x10]
 *   @0x22d780 add r4, r12, r1, lsl #2
 *   @0x22d784 ldrb r0, [r0, #0x10]
 *   @0x22d788 ldrb r6, [r6, #0x10]
 *   @0x22d78c ldr r8, [r4, #0x4]
 *   @0x22d790 orr r0, r0, r5, lsl #8
 *   @0x22d794 ldr r2, [r2, #0x4]
 *   @0x22d798 ldr r3, [r3, #0x4]
 *   @0x22d79c orr r6, r0, r6, lsl #4
 *   @0x22d7a0 rsb r0, r2, r8
 *   @0x22d7a4 ldr r9, [r12, r7, lsl #2]
 *   @0x22d7a8 ldr r7, [r12, r1, lsl #2]
 *   @0x22d7ac add r2, r8, r2
 *   @0x22d7b0 smull r4, r5, r0, r3
 *   @0x22d7b4 ldr r8, [sp, #0x8]
 *   @0x22d7b8 eor r1, r6, #4080
 *   @0x22d7bc str r2, [sp, #0x18]
 *   @0x22d7c0 eor r1, r1, #15
 *   @0x22d7c4 add r2, r9, r7
 *   @0x22d7c8 rsb r7, r7, r9
 *   @0x22d7cc str r7, [sp, #0x2c]
 *   @0x22d7d0 ldr r9, [sp, #0x18]
 *   @0x22d7d4 strd r4, r5, [sp, #48]
 *   @0x22d7d8 ldr r5, [sp, #0x9c]
 *   @0x22d7dc asr r4, r6, r5
 *   @0x22d7e0 smull r6, r7, r2, r8
 *   @0x22d7e4 asr r6, r1, r5
 *   @0x22d7e8 ldr r5, [sp, #0x2c]
 *   @0x22d7ec sub r6, r6, #-1073741823
 *   @0x22d7f0 smull r0, r1, r8, r0
 *   @0x22d7f4 asr r8, r9, #1
 *   @0x22d7f8 smull r2, r3, r2, r3
 *   @0x22d7fc asr r9, r5, #1
 *   @0x22d800 ldr r5, [sp, #0x34]
 *   @0x22d804 add r0, r12, r4, lsl #2
 *   @0x22d808 rsb r3, r3, r1
 *   @0x22d80c add r2, r7, r5
 *   @0x22d810 add r1, r8, r2
 *   @0x22d814 rsb r2, r2, r8
 *   @0x22d818 str r1, [r11, #-0x10]
 *   @0x22d81c add r1, r9, r3
 *   @0x22d820 ldr r7, [sp, #0x28]
 *   @0x22d824 rsb r3, r9, r3
 *   @0x22d828 ldr r8, [sp, #0xd4]
 *   @0x22d82c str r1, [r11, #-0xc]
 *   @0x22d830 str r2, [r7, #0x8]
 *   @0x22d834 add r2, r12, r6, lsl #2
 *   @0x22d838 str r3, [r7, #0xc]
 *   @0x22d83c ldr r1, [r10, r8]!
 *   @0x22d840 ldr r5, [r0, #0x4]
 *   @0x22d844 ldr r4, [r12, r4, lsl #2]
 *   @0x22d848 ldr r8, [r2, #0x4]
 *   @0x22d84c ldr r9, [r12, r6, lsl #2]
 *   @0x22d850 ldr r3, [r10, #0x4]
 *   @0x22d854 rsb r0, r8, r5
 *   @0x22d858 add r2, r9, r4
 *   @0x22d85c add r8, r5, r8
 *   @0x22d860 rsb r9, r4, r9
 *   @0x22d864 smull r6, r7, r2, r1
 *   @0x22d868 asr r8, r8, #1
 *   @0x22d86c smull r4, r5, r0, r3
 *   @0x22d870 asr r4, r9, #1
 *   @0x22d874 smull r0, r1, r1, r0
 *   @0x22d878 ldr r9, [sp, #0x28]
 *   @0x22d87c smull r2, r3, r2, r3
 *   @0x22d880 add r0, r7, r5
 *   @0x22d884 add r2, r8, r0
 *   @0x22d888 str r2, [r11, #-0x8]
 *   @0x22d88c rsb r3, r3, r1
 *   @0x22d890 rsb r0, r0, r8
 *   @0x22d894 add r2, r4, r3
 *   @0x22d898 str r2, [r11, #-0x4]
 *   @0x22d89c cmp r9, r11
 *   @0x22d8a0 rsb r3, r4, r3
 *   @0x22d8a4 str r0, [r9]
 *   @0x22d8a8 str r3, [r9, #0x4]
 *   @0x22d8ac bhi 0x22d6d8 <mdct_backward+0x175c>
 *   @0x22d8b0 ldr r10, [sp, #0xec]
 *   @0x22d8b4 cmp r10, #0
 *   @0x22d8b8 beq 0x22dcd0 <mdct_backward+0x1d54>
 *   @0x22d8bc cmp r10, #1
 *   @0x22d8c0 beq 0x22db00 <mdct_backward+0x1b84>
 *   @0x22d8c4 cmp r10, #3
 *   @0x22d8c8 ble 0x22de90 <mdct_backward+0x1f14>
 *   @0x22d8cc ldr r3, [pc, #0x600]
 *   @0x22d8d0 asr r10, r10, #1
 *   @0x22d8d4 add r3, pc, r3
 *   @0x22d8d8 add r10, r3, r10, lsl #2
 *   @0x22d8dc ldr r12, [sp, #0xec]
 *   @0x22d8e0 ldr r9, [sp, #0xe8]
 *   @0x22d8e4 lsl r0, r12, #3
 *   @0x22d8e8 lsl r11, r12, #2
 *   @0x22d8ec lsl r1, r12, #4
 *   @0x22d8f0 ldr r12, [sp, #0xf4]
 *   @0x22d8f4 mov r8, r9
 *   @0x22d8f8 add r2, r0, r11
 *   @0x22d8fc str r0, [sp, #0x10]
 *   @0x22d900 str r1, [sp, #0x40]
 *   @0x22d904 str r2, [sp, #0x28]
 *   @0x22d908 ldr r3, [r12, #0x4]
 *   @0x22d90c add r5, r10, r11
 *   @0x22d910 ldr r4, [r10, #0x4]
 *   @0x22d914 sub r8, r8, #16
 *   @0x22d918 ldr r0, [r12]
 *   @0x22d91c rsb r3, r3, #0
 *   @0x22d920 ldr r2, [r10]
 *   @0x22d924 add r12, r12, #32
 *   @0x22d928 smull r6, r7, r3, r4
 *   @0x22d92c str r5, [sp, #0x20]
 *   @0x22d930 smull r4, r5, r0, r4
 *   @0x22d934 ldr r6, [sp, #0x10]
 *   @0x22d938 smull r0, r1, r0, r2
 *   @0x22d93c lsl r0, r7, #1
 *   @0x22d940 smull r2, r3, r2, r3
 *   @0x22d944 lsl r2, r5, #1
 *   @0x22d948 ldr r7, [sp, #0x28]
 *   @0x22d94c add r6, r10, r6
 *   @0x22d950 add r0, r0, r1, lsl #1
 *   @0x22d954 str r0, [r8, #0xc]
 *   @0x22d958 ldr r0, [sp, #0x20]
 *   @0x22d95c add r7, r10, r7
 *   @0x22d960 str r6, [sp, #0x38]
 *   @0x22d964 add r9, r9, #16
 *   @0x22d968 rsb r2, r2, r3, lsl #1
 *   @0x22d96c str r2, [r9, #-0x10]
 *   @0x22d970 ldr r3, [r12, #-0x14]
 *   @0x22d974 ldr r4, [r0, #0x4]
 *   @0x22d978 ldr r2, [r10, r11]
 *   @0x22d97c rsb r3, r3, #0
 *   @0x22d980 ldr r0, [r12, #-0x18]
 *   @0x22d984 str r7, [sp, #0x30]
 *   @0x22d988 smull r6, r7, r3, r4
 *   @0x22d98c smull r4, r5, r0, r4
 *   @0x22d990 smull r0, r1, r0, r2
 *   @0x22d994 lsl r0, r7, #1
 *   @0x22d998 smull r2, r3, r2, r3
 *   @0x22d99c lsl r2, r5, #1
 *   @0x22d9a0 ldr r5, [sp, #0x10]
 *   @0x22d9a4 add r0, r0, r1, lsl #1
 *   @0x22d9a8 ldr r1, [sp, #0x38]
 *   @0x22d9ac str r0, [r8, #0x8]
 *   @0x22d9b0 rsb r2, r2, r3, lsl #1
 *   @0x22d9b4 str r2, [r9, #-0xc]
 *   @0x22d9b8 ldr r3, [r12, #-0xc]
 *   @0x22d9bc ldr r0, [r12, #-0x10]
 *   @0x22d9c0 ldr r4, [r1, #0x4]
 *   @0x22d9c4 rsb r3, r3, #0
 *   @0x22d9c8 ldr r2, [r10, r5]
 *   @0x22d9cc smull r6, r7, r3, r4
 *   @0x22d9d0 ldr r6, [sp, #0x30]
 *   @0x22d9d4 smull r4, r5, r0, r4
 *   @0x22d9d8 smull r0, r1, r0, r2
 *   @0x22d9dc lsl r0, r7, #1
 *   @0x22d9e0 smull r2, r3, r2, r3
 *   @0x22d9e4 ldr r7, [sp, #0x28]
 *   @0x22d9e8 lsl r2, r5, #1
 *   @0x22d9ec add r0, r0, r1, lsl #1
 *   @0x22d9f0 str r0, [r8, #0x4]
 *   @0x22d9f4 ldr r1, [sp, #0x40]
 *   @0x22d9f8 rsb r3, r2, r3, lsl #1
 *   @0x22d9fc str r3, [r9, #-0x8]
 *   @0x22da00 ldr r3, [r12, #-0x4]
 *   @0x22da04 ldr r0, [r12, #-0x8]
 *   @0x22da08 cmp r8, r12
 *   @0x22da0c ldr r4, [r6, #0x4]
 *   @0x22da10 rsb r3, r3, #0
 *   @0x22da14 ldr r2, [r10, r7]
 *   @0x22da18 add r10, r10, r1
 *   @0x22da1c smull r6, r7, r3, r4
 *   @0x22da20 smull r4, r5, r0, r4
 *   @0x22da24 smull r0, r1, r0, r2
 *   @0x22da28 lsl r0, r7, #1
 *   @0x22da2c smull r2, r3, r2, r3
 *   @0x22da30 lsl r2, r5, #1
 *   @0x22da34 add r0, r0, r1, lsl #1
 *   @0x22da38 str r0, [r8]
 *   @0x22da3c rsb r3, r2, r3, lsl #1
 *   @0x22da40 str r3, [r9, #-0x4]
 *   @0x22da44 bhi 0x22d908 <mdct_backward+0x198c>
 *   @0x22da48 ldr r2, [sp, #0xf4]
 *   @0x22da4c ldr r3, [sp, #0xfc]
 *   @0x22da50 add r1, r2, r3
 *   @0x22da54 ldr r2, [sp, #0xe8]
 *   @0x22da58 mov r3, r1
 *   @0x22da5c sub r2, r2, #16
 *   @0x22da60 ldr r0, [r2, #0xc]
 *   @0x22da64 sub r1, r1, #16
 *   @0x22da68 add r3, r3, #16
 *   @0x22da6c rsb r12, r0, #0
 *   @0x22da70 str r0, [r1, #0xc]
 *   @0x22da74 str r12, [r3, #-0x10]
 *   @0x22da78 ldr r0, [r2, #0x8]
 *   @0x22da7c rsb r12, r0, #0
 *   @0x22da80 str r0, [r1, #0x8]
 *   @0x22da84 str r12, [r3, #-0xc]
 *   @0x22da88 ldr r0, [r2, #0x4]
 *   @0x22da8c rsb r12, r0, #0
 *   @0x22da90 str r0, [r1, #0x4]
 *   @0x22da94 str r12, [r3, #-0x8]
 *   @0x22da98 ldr r0, [r2]
 *   @0x22da9c rsb r12, r0, #0
 *   @0x22daa0 str r0, [r1]
 *   @0x22daa4 str r12, [r3, #-0x4]
 *   @0x22daa8 cmp r2, r3
 *   @0x22daac bhi 0x22da5c <mdct_backward+0x1ae0>
 *   @0x22dab0 ldr r3, [sp, #0xe8]
 *   @0x22dab4 ldr r0, [sp, #0xbc]
 *   @0x22dab8 mov r2, r3
 *   @0x22dabc ldr r1, [r3, #0xc]
 *   @0x22dac0 str r1, [r2, #-0x10]!
 *   @0x22dac4 cmp r0, r2
 *   @0x22dac8 ldr r1, [r3, #0x8]
 *   @0x22dacc str r1, [r2, #0x4]
 *   @0x22dad0 ldr r1, [r3, #0x4]
 *   @0x22dad4 str r1, [r2, #0x8]
 *   @0x22dad8 ldr r1, [r3], #16
 *   @0x22dadc str r1, [r2, #0xc]
 *   @0x22dae0 blo 0x22dabc <mdct_backward+0x1b40>
 *   @0x22dae4 add sp, sp, #256
 *   @0x22dae8 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x22daec bx lr
 *   @0x22daf0 ldr r3, [pc, #0x3e0]
 *   @0x22daf4 add r3, pc, r3
 *   @0x22daf8 sub r9, r3, #4080
 *   @0x22dafc b 0x22d49c <mdct_backward+0x1520>
 *   @0x22db00 ldr r5, [sp, #0xe8]
 *   @0x22db04 mov r1, #0
 *   @0x22db08 ldr r3, [pc, #0x3cc]
 *   @0x22db0c ldr r4, [sp, #0x20]
 *   @0x22db10 add r3, pc, r3
 *   @0x22db14 ldr r12, [sp, #0xf4]
 *   @0x22db18 mov r8, r5
 *   @0x22db1c str r5, [sp, #0x28]
 *   @0x22db20 sub r10, r4, #4080
 *   @0x22db24 mvn r5, #-1073741824
 *   @0x22db28 add r11, r3, #24
 *   @0x22db2c str r8, [sp, #0x10]
 *   @0x22db30 mov r9, r5
 *   @0x22db34 mov r8, r1
 *   @0x22db38 ldr r1, [r10, #0x4]
 *   @0x22db3c add r12, r12, #32
 *   @0x22db40 ldr r3, [r12, #-0x1c]
 *   @0x22db44 add r10, r10, #16
 *   @0x22db48 ldr r6, [sp, #0x10]
 *   @0x22db4c asr r1, r1, #1
 *   @0x22db50 rsb r3, r3, #0
 *   @0x22db54 add r4, r1, r9
 *   @0x22db58 sub r6, r6, #16
 *   @0x22db5c str r6, [sp, #0x10]
 *   @0x22db60 smull r6, r7, r3, r4
 *   @0x22db64 ldr r0, [r12, #-0x20]
 *   @0x22db68 ldr r2, [r10, #-0x10]
 *   @0x22db6c ldr r5, [sp, #0x10]
 *   @0x22db70 asr r9, r2, #1
 *   @0x22db74 strd r6, r7, [sp, #48]
 *   @0x22db78 add r2, r9, r8
 *   @0x22db7c smull r6, r7, r0, r4
 *   @0x22db80 ldr r8, [sp, #0x34]
 *   @0x22db84 strd r6, r7, [sp, #24]
 *   @0x22db88 smull r6, r7, r0, r2
 *   @0x22db8c ldr r4, [sp, #0x1c]
 *   @0x22db90 smull r2, r3, r2, r3
 *   @0x22db94 ldr r6, [sp, #0x28]
 *   @0x22db98 lsl r2, r4, #1
 *   @0x22db9c lsl r0, r8, #1
 *   @0x22dba0 add r0, r0, r7, lsl #1
 *   @0x22dba4 str r0, [r5, #0xc]
 *   @0x22dba8 rsb r3, r2, r3, lsl #1
 *   @0x22dbac str r3, [r6]
 *   @0x22dbb0 ldr r8, [r11, #-0xc]
 *   @0x22dbb4 ldr r3, [r12, #-0x14]
 *   @0x22dbb8 ldr r2, [r11, #-0x10]
 *   @0x22dbbc asr r8, r8, #1
 *   @0x22dbc0 rsb r3, r3, #0
 *   @0x22dbc4 add r4, r8, r1
 *   @0x22dbc8 ldr r7, [r12, #-0x18]
 *   @0x22dbcc asr r6, r2, #1
 *   @0x22dbd0 smull r0, r1, r3, r4
 *   @0x22dbd4 add r2, r6, r9
 *   @0x22dbd8 smull r4, r5, r7, r4
 *   @0x22dbdc ldr r9, [sp, #0x10]
 *   @0x22dbe0 strd r0, r1, [sp, #32]
 *   @0x22dbe4 smull r0, r1, r7, r2
 *   @0x22dbe8 ldr r7, [sp, #0x24]
 *   @0x22dbec smull r2, r3, r2, r3
 *   @0x22dbf0 lsl r0, r7, #1
 *   @0x22dbf4 lsl r2, r5, #1
 *   @0x22dbf8 add r0, r0, r1, lsl #1
 *   @0x22dbfc str r0, [r9, #0x8]
 *   @0x22dc00 ldr r0, [sp, #0x28]
 *   @0x22dc04 rsb r3, r2, r3, lsl #1
 *   @0x22dc08 str r3, [r0, #0x4]
 *   @0x22dc0c ldr r1, [r10, #-0x4]
 *   @0x22dc10 ldr r0, [r12, #-0x10]
 *   @0x22dc14 ldr r2, [r10, #-0x8]
 *   @0x22dc18 asr r5, r1, #1
 *   @0x22dc1c ldr r3, [r12, #-0xc]
 *   @0x22dc20 add r4, r5, r8
 *   @0x22dc24 rsb r3, r3, #0
 *   @0x22dc28 asr r1, r2, #1
 *   @0x22dc2c smull r8, r9, r0, r4
 *   @0x22dc30 add r2, r1, r6
 *   @0x22dc34 smull r6, r7, r3, r4
 *   @0x22dc38 ldr r6, [sp, #0x10]
 *   @0x22dc3c strd r8, r9, [sp, #32]
 *   @0x22dc40 smull r8, r9, r0, r2
 *   @0x22dc44 ldr r4, [sp, #0x24]
 *   @0x22dc48 smull r2, r3, r2, r3
 *   @0x22dc4c lsl r0, r7, #1
 *   @0x22dc50 ldr r7, [sp, #0x28]
 *   @0x22dc54 lsl r2, r4, #1
 *   @0x22dc58 add r0, r0, r9, lsl #1
 *   @0x22dc5c str r0, [r6, #0x4]
 *   @0x22dc60 rsb r3, r2, r3, lsl #1
 *   @0x22dc64 str r3, [r7, #0x8]
 *   @0x22dc68 ldmdb r11, {r8, r9}
 *   @0x22dc6c add r11, r11, #16
 *   @0x22dc70 ldr r3, [r12, #-0x4]
 *   @0x22dc74 ldr r0, [r12, #-0x8]
 *   @0x22dc78 asr r9, r9, #1
 *   @0x22dc7c add r4, r9, r5
 *   @0x22dc80 rsb r3, r3, #0
 *   @0x22dc84 asr r8, r8, #1
 *   @0x22dc88 cmp r6, r12
 *   @0x22dc8c add r2, r8, r1
 *   @0x22dc90 smull r6, r7, r3, r4
 *   @0x22dc94 smull r4, r5, r0, r4
 *   @0x22dc98 smull r0, r1, r0, r2
 *   @0x22dc9c lsl r0, r7, #1
 *   @0x22dca0 smull r2, r3, r2, r3
 *   @0x22dca4 lsl r2, r5, #1
 *   @0x22dca8 add r0, r0, r1, lsl #1
 *   @0x22dcac ldr r1, [sp, #0x10]
 *   @0x22dcb0 rsb r3, r2, r3, lsl #1
 *   @0x22dcb4 ldr r2, [sp, #0x28]
 *   @0x22dcb8 str r0, [r1]
 *   @0x22dcbc add r2, r2, #16
 *   @0x22dcc0 str r3, [r2, #-0x4]
 *   @0x22dcc4 str r2, [sp, #0x28]
 *   @0x22dcc8 bhi 0x22db38 <mdct_backward+0x1bbc>
 *   @0x22dccc b 0x22da48 <mdct_backward+0x1acc>
 *   @0x22dcd0 ldr r11, [sp, #0xe8]
 *   @0x22dcd4 mvn r7, #-2147483648
 *   @0x22dcd8 ldr r5, [sp, #0xec]
 *   @0x22dcdc mov r12, r7
 *   @0x22dce0 ldr r3, [pc, #0x1f8]
 *   @0x22dce4 ldr r9, [sp, #0xf4]
 *   @0x22dce8 mov r10, r11
 *   @0x22dcec ldr r4, [sp, #0x20]
 *   @0x22dcf0 add r3, pc, r3
 *   @0x22dcf4 mov r8, r5
 *   @0x22dcf8 add r3, r3, #16
 *   @0x22dcfc sub r4, r4, #4080
 *   @0x22dd00 str r3, [sp, #0x28]
 *   @0x22dd04 str r4, [sp, #0x20]
 *   @0x22dd08 str r11, [sp, #0x10]
 *   @0x22dd0c ldr r5, [sp, #0x20]
 *   @0x22dd10 sub r10, r10, #16
 *   @0x22dd14 ldr r7, [sp, #0x20]
 *   @0x22dd18 add r9, r9, #32
 *   @0x22dd1c ldr r1, [r9, #-0x20]
 *   @0x22dd20 ldr r6, [r5, #0x4]
 *   @0x22dd24 add r7, r7, #8
 *   @0x22dd28 str r7, [sp, #0x20]
 *   @0x22dd2c rsb r7, r12, r6
 *   @0x22dd30 ldr r5, [r5]
 *   @0x22dd34 ldr r11, [r9, #-0x1c]
 *   @0x22dd38 asr r7, r7, #2
 *   @0x22dd3c rsb r3, r8, r5
 *   @0x22dd40 add r4, r7, r12
 *   @0x22dd44 rsb r11, r11, #0
 *   @0x22dd48 asr r12, r3, #2
 *   @0x22dd4c rsb r7, r7, r6
 *   @0x22dd50 smull r0, r1, r1, r4
 *   @0x22dd54 add r8, r12, r8
 *   @0x22dd58 smull r2, r3, r11, r4
 *   @0x22dd5c ldr r4, [r9, #-0x20]
 *   @0x22dd60 rsb r12, r12, r5
 *   @0x22dd64 strd r0, r1, [sp, #56]
 *   @0x22dd68 smull r0, r1, r4, r8
 *   @0x22dd6c lsl r0, r3, #1
 *   @0x22dd70 smull r2, r3, r8, r11
 *   @0x22dd74 ldr r8, [sp, #0x3c]
 *   @0x22dd78 ldr r11, [sp, #0x28]
 *   @0x22dd7c add r0, r0, r1, lsl #1
 *   @0x22dd80 str r0, [r10, #0xc]
 *   @0x22dd84 ldr r0, [sp, #0x10]
 *   @0x22dd88 lsl r2, r8, #1
 *   @0x22dd8c add r11, r11, #8
 *   @0x22dd90 rsb r3, r2, r3, lsl #1
 *   @0x22dd94 str r3, [r0]
 *   @0x22dd98 ldr r8, [r9, #-0x14]
 *   @0x22dd9c ldr r4, [r9, #-0x18]
 *   @0x22dda0 rsb r8, r8, #0
 *   @0x22dda4 smull r0, r1, r4, r7
 *   @0x22dda8 smull r2, r3, r8, r7
 *   @0x22ddac ldr r7, [sp, #0x10]
 *   @0x22ddb0 strd r2, r3, [sp, #56]
 *   @0x22ddb4 smull r2, r3, r4, r12
 *   @0x22ddb8 lsl r2, r1, #1
 *   @0x22ddbc smull r0, r1, r12, r8
 *   @0x22ddc0 ldr r4, [sp, #0x3c]
 *   @0x22ddc4 ldr r8, [sp, #0x28]
 *   @0x22ddc8 str r11, [sp, #0x28]
 *   @0x22ddcc lsl r0, r4, #1
 *   @0x22ddd0 add r3, r0, r3, lsl #1
 *   @0x22ddd4 str r3, [r10, #0x8]
 *   @0x22ddd8 rsb r2, r2, r1, lsl #1
 *   @0x22dddc str r2, [r7, #0x4]
 *   @0x22dde0 ldmdb r8, {r8, r12}
 *   @0x22dde4 ldr r3, [r9, #-0xc]
 *   @0x22dde8 rsb r11, r6, r12
 *   @0x22ddec rsb r1, r5, r8
 *   @0x22ddf0 ldr r0, [r9, #-0x10]
 *   @0x22ddf4 rsb r3, r3, #0
 *   @0x22ddf8 asr r11, r11, #2
 *   @0x22ddfc asr r1, r1, #2
 *   @0x22de00 add r4, r11, r6
 *   @0x22de04 add r2, r1, r5
 *   @0x22de08 rsb r1, r1, r8
 *   @0x22de0c str r1, [sp, #0x38]
 *   @0x22de10 smull r6, r7, r3, r4
 *   @0x22de14 rsb r11, r11, r12
 *   @0x22de18 smull r4, r5, r0, r4
 *   @0x22de1c smull r0, r1, r0, r2
 *   @0x22de20 lsl r0, r7, #1
 *   @0x22de24 smull r2, r3, r2, r3
 *   @0x22de28 lsl r2, r5, #1
 *   @0x22de2c add r0, r0, r1, lsl #1
 *   @0x22de30 str r0, [r10, #0x4]
 *   @0x22de34 ldr r0, [sp, #0x10]
 *   @0x22de38 rsb r3, r2, r3, lsl #1
 *   @0x22de3c str r3, [r0, #0x8]
 *   @0x22de40 ldr r2, [r9, #-0x4]
 *   @0x22de44 ldr r0, [r9, #-0x8]
 *   @0x22de48 cmp r10, r9
 *   @0x22de4c ldr r3, [sp, #0x38]
 *   @0x22de50 rsb r2, r2, #0
 *   @0x22de54 smull r6, r7, r2, r11
 *   @0x22de58 smull r4, r5, r0, r11
 *   @0x22de5c smull r0, r1, r0, r3
 *   @0x22de60 lsl r0, r7, #1
 *   @0x22de64 smull r2, r3, r3, r2
 *   @0x22de68 lsl r2, r5, #1
 *   @0x22de6c add r0, r0, r1, lsl #1
 *   @0x22de70 str r0, [r10]
 *   @0x22de74 ldr r4, [sp, #0x10]
 *   @0x22de78 rsb r3, r2, r3, lsl #1
 *   @0x22de7c add r4, r4, #16
 *   @0x22de80 str r3, [r4, #-0x4]
 *   @0x22de84 str r4, [sp, #0x10]
 *   @0x22de88 bhi 0x22dd0c <mdct_backward+0x1d90>
 *   @0x22de8c b 0x22da48 <mdct_backward+0x1acc>
 *   @0x22de90 ldr r11, [sp, #0x20]
 *   @0x22de94 sub r10, r11, #4080
 *   @0x22de98 b 0x22d8dc <mdct_backward+0x1960>
 *   @0x22de9c mov r8, #64512
 *   @0x22dea0 mov r9, #0
 *   @0x22dea4 movt r8, #0xffff
 *   @0x22dea8 mov r10, #64
 *   @0x22deac mov r12, #1024
 *   @0x22deb0 mov r0, #256
 *   @0x22deb4 mov r2, #7
 *   @0x22deb8 str r8, [sp, #0xcc]
 *   @0x22debc str r9, [sp, #0x90]
 *   @0x22dec0 str r10, [sp, #0xec]
 *   @0x22dec4 str r12, [sp, #0xe4]
 *   @0x22dec8 str r0, [sp, #0xf8]
 *   @0x22decc str r2, [sp, #0x9c]
 *   @0x22ded0 b 0x22bfec <mdct_backward+0x70>
 *   @0x22ded4 andseq r1, r3, r12, asr #3
 *   @0x22ded8 andseq r2, r3, r4, lsr #31
 *   @0x22dedc mulseq r3, r0, pc
 *   @0x22dee0 ldrheq r0, [r3], -r0
 *
 * ══ §4/5 anon_2b6a38  0x2b6a38  size 1376  70 条（0x2b6a38..0x2b6f98）｜其中 274 条已由别的卡落锚，本节不再重复
 * @func 0x2b6a38 0x2b6f98  size 1376  70 条
 * 部分覆盖: 本节 70/344 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jcopy_sample_rows
 * 字段偏移 top8: 0x2×26 / 0x4×12 / 0xc×11 / 0x8×11 / 0x18×11 / 0x24×10 / 0x14×10 / 0x10×10
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b6a38 ldr r3, [r0, #0x1a0]
 *   @0x2b6a3c mov r2, #0
 *   @0x2b6a40 strb r2, [r3, #0x24]
 *   @0x2b6a44 ldr r2, [r0, #0x60]
 *   @0x2b6a48 str r2, [r3, #0x2c]
 *   @0x2b6a4c bx lr
 *   @0x2b6e98 push {r4, r5, r6, r7, lr}
 *   @0x2b6e9c sub sp, sp, #20
 *   @0x2b6ea0 ldr r4, [r0, #0x1a0]
 *   @0x2b6ea4 mov r7, r2
 *   @0x2b6ea8 ldr r6, [sp, #0x2c]
 *   @0x2b6eac ldr r2, [sp, #0x28]
 *   @0x2b6eb0 ldrb r3, [r4, #0x24]
 *   @0x2b6eb4 cmp r3, #0
 *   @0x2b6eb8 bne 0x2b6f60 <jinit_master_decompress+0x888>
 *   @0x2b6ebc ldr r5, [r4, #0x2c]
 *   @0x2b6ec0 ldr r3, [r6]
 *   @0x2b6ec4 ldr lr, [sp, #0x30]
 *   @0x2b6ec8 cmp r5, #2
 *   @0x2b6ecc movhs r5, #2
 *   @0x2b6ed0 rsb r12, r3, lr
 *   @0x2b6ed4 cmp r5, r12
 *   @0x2b6ed8 bhi 0x2b6f40 <jinit_master_decompress+0x868>
 *   @0x2b6edc ldr r12, [r2, r3, lsl #2]
 *   @0x2b6ee0 cmp r5, #2
 *   @0x2b6ee4 lsl r3, r3, #2
 *   @0x2b6ee8 str r12, [sp, #0x8]
 *   @0x2b6eec bne 0x2b6f94 <jinit_master_decompress+0x8bc>
 *   @0x2b6ef0 add r2, r2, r3
 *   @0x2b6ef4 ldr r3, [r2, #0x4]
 *   @0x2b6ef8 str r3, [sp, #0xc]
 *   @0x2b6efc ldr r12, [r4, #0xc]
 *   @0x2b6f00 add r3, sp, #8
 *   @0x2b6f04 ldr r2, [r7]
 *   @0x2b6f08 blx r12
 *   @0x2b6f0c ldr r3, [r6]
 *   @0x2b6f10 add r3, r3, r5
 *   @0x2b6f14 str r3, [r6]
 *   @0x2b6f18 ldrb r2, [r4, #0x24]
 *   @0x2b6f1c ldr r3, [r4, #0x2c]
 *   @0x2b6f20 cmp r2, #0
 *   @0x2b6f24 rsb r5, r5, r3
 *   @0x2b6f28 str r5, [r4, #0x2c]
 *   @0x2b6f2c ldreq r3, [r7]
 *   @0x2b6f30 addeq r3, r3, #1
 *   @0x2b6f34 streq r3, [r7]
 *   @0x2b6f38 add sp, sp, #20
 *   @0x2b6f3c pop {r4, r5, r6, r7, pc}
 *   @0x2b6f40 ldr r3, [r2, r3, lsl #2]
 *   @0x2b6f44 str r3, [sp, #0x8]
 *   @0x2b6f48 ldr r3, [r4, #0x20]
 *   @0x2b6f4c mov r2, #1
 *   @0x2b6f50 mov r5, r12
 *   @0x2b6f54 strb r2, [r4, #0x24]
 *   @0x2b6f58 str r3, [sp, #0xc]
 *   @0x2b6f5c b 0x2b6efc <jinit_master_decompress+0x824>
 *   @0x2b6f60 ldr r0, [r6]
 *   @0x2b6f64 mov r5, #1
 *   @0x2b6f68 str r5, [sp]
 *   @0x2b6f6c mov r1, #0
 *   @0x2b6f70 ldr r12, [r4, #0x28]
 *   @0x2b6f74 mov r3, r1
 *   @0x2b6f78 add r2, r2, r0, lsl #2
 *   @0x2b6f7c add r0, r4, #32
 *   @0x2b6f80 str r12, [sp, #0x4]
 *   @0x2b6f84 bl 0x2bc81c <jcopy_sample_rows>
 *   @0x2b6f88 mov r3, #0
 *   @0x2b6f8c strb r3, [r4, #0x24]
 *   @0x2b6f90 b 0x2b6f0c <jinit_master_decompress+0x834>
 *   @0x2b6f94 mov r12, r5
 *
 * ══ §5/5 ReportSpineError  0xc4404  size 52  13 条（0xc4404..0xc4438）
 * @func 0xc4404 0xc4438  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4404 push {r3, lr}
 *   @0xc4408 mov r2, r0
 *   @0xc440c ldr r3, [pc, #0x1c]
 *   @0xc4410 ldr r1, [pc, #0x1c]
 *   @0xc4414 ldr r3, [pc, r3]
 *   @0xc4418 add r1, pc, r1
 *   @0xc441c ldr r0, [r3]
 *   @0xc4420 ldr r3, [r0]
 *   @0xc4424 ldr r3, [r3, #0xc]
 *   @0xc4428 blx r3
 *   @0xc442c pop {r3, pc}
 *   @0xc4430 eorseq r9, r2, r0, lsl #6
 *   @0xc4434 .word 0x0026c6dc
 */
