/* cally 逆向卡：All_22 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 13 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/13 b2ParticleSystem::RotateBuffer(int, int, int)  0x2d7500  size 3440  860 条（0x2d7500..0x2d8270）
 * @func 0x2d7500 0x2d8270  size 3440  860 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×10 / __aeabi_idivmod×5 / b2ParticleSystem::RotateBuffer(int, int, int)+0xbe8×2 / anon_2d49b8+0x42c×2 / b2ParticleSystem::RotateBuffer(int, int, int)+0xc00×2 / b2ParticleSystem::RotateBuffer(int, int, int)+0xc20×2 / b2ParticleSystem::RotateBuffer(int, int, int)+0xc28×2 / b2ParticleSystem::RotateBuffer(int, int, int)+0xc18×2
 * 字段偏移 top8: 0x4×45 / 0x8×20 / 0xc×18 / 0x1c×12 / 0x18×11 / 0x14×11 / 0x10×8 / 0x20×6
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d7500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d7504 vpush {d8}
 *   @0x2d7508 cmp r2, r3
 *   @0x2d750c cmpne r1, r2
 *   @0x2d7510 sub sp, sp, #60
 *   @0x2d7514 mov r4, r1
 *   @0x2d7518 mov r11, r2
 *   @0x2d751c str r3, [sp, #0x10]
 *   @0x2d7520 str r0, [sp, #0xc]
 *   @0x2d7524 bne 0x2d7534 <_ZN16b2ParticleSystem12RotateBufferEiii+0x34>
 *   @0x2d7528 add sp, sp, #60
 *   @0x2d752c vpop {d8}
 *   @0x2d7530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d7534 lsl r3, r1, #2
 *   @0x2d7538 str r3, [sp, #0x20]
 *   @0x2d753c lsl r3, r2, #2
 *   @0x2d7540 str r3, [sp, #0x24]
 *   @0x2d7544 ldr r3, [sp, #0x10]
 *   @0x2d7548 ldr r8, [r0, #0x30]
 *   @0x2d754c ldr r1, [sp, #0x24]
 *   @0x2d7550 lsl r3, r3, #2
 *   @0x2d7554 str r3, [sp, #0x28]
 *   @0x2d7558 ldr r3, [sp, #0x20]
 *   @0x2d755c add r10, r8, r3
 *   @0x2d7560 add r3, r8, r1
 *   @0x2d7564 rsb r2, r10, r3
 *   @0x2d7568 asrs r2, r2, #2
 *   @0x2d756c str r2, [sp, #0x4]
 *   @0x2d7570 beq 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c>
 *   @0x2d7574 ldr r2, [sp, #0x28]
 *   @0x2d7578 ldr r1, [sp, #0x4]
 *   @0x2d757c add r8, r8, r2
 *   @0x2d7580 ldr r2, [sp, #0x4]
 *   @0x2d7584 rsb r0, r10, r8
 *   @0x2d7588 asr r0, r0, #2
 *   @0x2d758c rsb r2, r2, r0
 *   @0x2d7590 str r2, [sp, #0x8]
 *   @0x2d7594 cmp r1, r2
 *   @0x2d7598 ldrne r9, [sp, #0x4]
 *   @0x2d759c bne 0x2d75a8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xa8>
 *   @0x2d75a0 b 0x2d8168 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc68>
 *   @0x2d75a4 mov r9, r1
 *   @0x2d75a8 mov r1, r9
 *   @0x2d75ac bl 0x318dec <__aeabi_idivmod>
 *   @0x2d75b0 mov r0, r9
 *   @0x2d75b4 cmp r1, #0
 *   @0x2d75b8 bne 0x2d75a4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xa4>
 *   @0x2d75bc cmp r9, #0
 *   @0x2d75c0 ble 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c>
 *   @0x2d75c4 ldr r2, [sp, #0x8]
 *   @0x2d75c8 mov r5, r9
 *   @0x2d75cc mov r9, r1
 *   @0x2d75d0 str r4, [sp, #0x18]
 *   @0x2d75d4 str r11, [sp, #0x1c]
 *   @0x2d75d8 lsl r3, r2, #2
 *   @0x2d75dc ldr r2, [sp, #0x4]
 *   @0x2d75e0 rsb r7, r3, #0
 *   @0x2d75e4 sub r3, r3, #4
 *   @0x2d75e8 str r3, [sp, #0x14]
 *   @0x2d75ec lsl r6, r2, #2
 *   @0x2d75f0 rsb r8, r6, r8
 *   @0x2d75f4 ldr r3, [sp, #0x4]
 *   @0x2d75f8 mov r4, r10
 *   @0x2d75fc ldr r2, [sp, #0x8]
 *   @0x2d7600 ldr r11, [r10], #4
 *   @0x2d7604 cmp r3, r2
 *   @0x2d7608 blt 0x2d7f0c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa0c>
 *   @0x2d760c mov r1, r5
 *   @0x2d7610 mov r0, r3
 *   @0x2d7614 bl 0x318d10 <__divsi3>
 *   @0x2d7618 cmp r0, #1
 *   @0x2d761c subgt r0, r0, #1
 *   @0x2d7620 movgt r1, #0
 *   @0x2d7624 ble 0x2d80e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xbe8>
 *   @0x2d7628 cmp r4, r8
 *   @0x2d762c add r1, r1, #1
 *   @0x2d7630 ldrlo r3, [r4, r6]
 *   @0x2d7634 strlo r3, [r4]
 *   @0x2d7638 addlo r4, r4, r6
 *   @0x2d763c add r3, r4, r7
 *   @0x2d7640 cmp r1, r0
 *   @0x2d7644 ldr r2, [r4, r7]
 *   @0x2d7648 str r2, [r4]
 *   @0x2d764c mov r4, r3
 *   @0x2d7650 bne 0x2d7628 <_ZN16b2ParticleSystem12RotateBufferEiii+0x128>
 *   @0x2d7654 add r9, r9, #1
 *   @0x2d7658 str r11, [r3]
 *   @0x2d765c cmp r9, r5
 *   @0x2d7660 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4>
 *   @0x2d7664 ldr r4, [sp, #0x18]
 *   @0x2d7668 ldr r11, [sp, #0x1c]
 *   @0x2d766c ldr r3, [sp, #0xc]
 *   @0x2d7670 lsl r7, r4, #3
 *   @0x2d7674 lsl r6, r11, #3
 *   @0x2d7678 ldr r2, [r3, #0x38]
 *   @0x2d767c ldr r3, [sp, #0x10]
 *   @0x2d7680 add r1, r2, r6
 *   @0x2d7684 add r0, r2, r7
 *   @0x2d7688 lsl r5, r3, #3
 *   @0x2d768c add r2, r2, r5
 *   @0x2d7690 bl 0x2d4de4 <_ZN15b2QueryCallbackD0Ev+0x454>
 *   @0x2d7694 ldr r3, [sp, #0xc]
 *   @0x2d7698 ldr r2, [r3, #0x40]
 *   @0x2d769c add r1, r2, r6
 *   @0x2d76a0 add r0, r2, r7
 *   @0x2d76a4 add r2, r2, r5
 *   @0x2d76a8 bl 0x2d4de4 <_ZN15b2QueryCallbackD0Ev+0x454>
 *   @0x2d76ac ldr r3, [sp, #0xc]
 *   @0x2d76b0 ldr r1, [sp, #0x24]
 *   @0x2d76b4 ldr r8, [r3, #0x5c]
 *   @0x2d76b8 ldr r3, [sp, #0x20]
 *   @0x2d76bc add r10, r8, r3
 *   @0x2d76c0 add r3, r8, r1
 *   @0x2d76c4 rsb r2, r10, r3
 *   @0x2d76c8 asrs r2, r2, #2
 *   @0x2d76cc str r2, [sp, #0x4]
 *   @0x2d76d0 beq 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8>
 *   @0x2d76d4 ldr r1, [sp, #0x28]
 *   @0x2d76d8 ldr r2, [sp, #0x4]
 *   @0x2d76dc add r8, r8, r1
 *   @0x2d76e0 ldr r1, [sp, #0x4]
 *   @0x2d76e4 rsb r0, r10, r8
 *   @0x2d76e8 asr r0, r0, #2
 *   @0x2d76ec rsb r2, r2, r0
 *   @0x2d76f0 str r2, [sp, #0x8]
 *   @0x2d76f4 cmp r1, r2
 *   @0x2d76f8 ldrne r9, [sp, #0x4]
 *   @0x2d76fc bne 0x2d7708 <_ZN16b2ParticleSystem12RotateBufferEiii+0x208>
 *   @0x2d7700 b 0x2d8130 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc30>
 *   @0x2d7704 mov r9, r1
 *   @0x2d7708 mov r1, r9
 *   @0x2d770c bl 0x318dec <__aeabi_idivmod>
 *   @0x2d7710 mov r0, r9
 *   @0x2d7714 cmp r1, #0
 *   @0x2d7718 bne 0x2d7704 <_ZN16b2ParticleSystem12RotateBufferEiii+0x204>
 *   @0x2d771c cmp r9, #0
 *   @0x2d7720 ble 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8>
 *   @0x2d7724 ldr r2, [sp, #0x8]
 *   @0x2d7728 str r11, [sp, #0x1c]
 *   @0x2d772c mov r11, r1
 *   @0x2d7730 str r4, [sp, #0x18]
 *   @0x2d7734 lsl r3, r2, #2
 *   @0x2d7738 ldr r2, [sp, #0x4]
 *   @0x2d773c rsb r7, r3, #0
 *   @0x2d7740 sub r3, r3, #4
 *   @0x2d7744 str r3, [sp, #0x14]
 *   @0x2d7748 lsl r6, r2, #2
 *   @0x2d774c rsb r8, r6, r8
 *   @0x2d7750 ldr r3, [sp, #0x4]
 *   @0x2d7754 mov r4, r10
 *   @0x2d7758 ldr r2, [sp, #0x8]
 *   @0x2d775c ldr r5, [r10], #4
 *   @0x2d7760 cmp r3, r2
 *   @0x2d7764 blt 0x2d7f6c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa6c>
 *   @0x2d7768 mov r0, r3
 *   @0x2d776c mov r1, r9
 *   @0x2d7770 bl 0x318d10 <__divsi3>
 *   @0x2d7774 cmp r0, #1
 *   @0x2d7778 subgt r0, r0, #1
 *   @0x2d777c movgt r2, #0
 *   @0x2d7780 ble 0x2d8100 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc00>
 *   @0x2d7784 cmp r8, r4
 *   @0x2d7788 add r2, r2, #1
 *   @0x2d778c ldrhi r3, [r4, r6]
 *   @0x2d7790 strhi r3, [r4]
 *   @0x2d7794 addhi r4, r4, r6
 *   @0x2d7798 add r3, r4, r7
 *   @0x2d779c cmp r2, r0
 *   @0x2d77a0 ldr r1, [r4, r7]
 *   @0x2d77a4 str r1, [r4]
 *   @0x2d77a8 mov r4, r3
 *   @0x2d77ac bne 0x2d7784 <_ZN16b2ParticleSystem12RotateBufferEiii+0x284>
 *   @0x2d77b0 add r11, r11, #1
 *   @0x2d77b4 str r5, [r3]
 *   @0x2d77b8 cmp r11, r9
 *   @0x2d77bc bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250>
 *   @0x2d77c0 ldr r4, [sp, #0x18]
 *   @0x2d77c4 ldr r11, [sp, #0x1c]
 *   @0x2d77c8 ldr r3, [sp, #0xc]
 *   @0x2d77cc ldr r8, [r3, #0x50]
 *   @0x2d77d0 cmp r8, #0
 *   @0x2d77d4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4>
 *   @0x2d77d8 ldr r3, [sp, #0x20]
 *   @0x2d77dc ldr r1, [sp, #0x24]
 *   @0x2d77e0 add r10, r8, r3
 *   @0x2d77e4 add r3, r8, r1
 *   @0x2d77e8 rsb r2, r10, r3
 *   @0x2d77ec asrs r2, r2, #2
 *   @0x2d77f0 str r2, [sp, #0x4]
 *   @0x2d77f4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4>
 *   @0x2d77f8 ldr r2, [sp, #0x28]
 *   @0x2d77fc ldr r1, [sp, #0x4]
 *   @0x2d7800 add r8, r8, r2
 *   @0x2d7804 ldr r2, [sp, #0x4]
 *   @0x2d7808 rsb r0, r10, r8
 *   @0x2d780c asr r0, r0, #2
 *   @0x2d7810 rsb r2, r2, r0
 *   @0x2d7814 str r2, [sp, #0x14]
 *   @0x2d7818 cmp r1, r2
 *   @0x2d781c ldrne r9, [sp, #0x4]
 *   @0x2d7820 bne 0x2d782c <_ZN16b2ParticleSystem12RotateBufferEiii+0x32c>
 *   @0x2d7824 b 0x2d81a0 <_ZN16b2ParticleSystem12RotateBufferEiii+0xca0>
 *   @0x2d7828 mov r9, r1
 *   @0x2d782c mov r1, r9
 *   @0x2d7830 bl 0x318dec <__aeabi_idivmod>
 *   @0x2d7834 mov r0, r9
 *   @0x2d7838 cmp r1, #0
 *   @0x2d783c bne 0x2d7828 <_ZN16b2ParticleSystem12RotateBufferEiii+0x328>
 *   @0x2d7840 cmp r9, #0
 *   @0x2d7844 ble 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4>
 *   @0x2d7848 ldr r2, [sp, #0x14]
 *   @0x2d784c mov r5, r9
 *   @0x2d7850 str r11, [sp, #0x1c]
 *   @0x2d7854 mov r9, r1
 *   @0x2d7858 ldr r11, [sp, #0x14]
 *   @0x2d785c lsl r3, r2, #2
 *   @0x2d7860 ldr r2, [sp, #0x4]
 *   @0x2d7864 rsb r7, r3, #0
 *   @0x2d7868 str r4, [sp, #0x18]
 *   @0x2d786c sub r3, r3, #4
 *   @0x2d7870 str r3, [sp, #0x8]
 *   @0x2d7874 lsl r6, r2, #2
 *   @0x2d7878 rsb r8, r6, r8
 *   @0x2d787c ldr r3, [sp, #0x4]
 *   @0x2d7880 mov r4, r10
 *   @0x2d7884 vldmia r10!, {s16}
 *   @0x2d7888 cmp r3, r11
 *   @0x2d788c blt 0x2d7fcc <_ZN16b2ParticleSystem12RotateBufferEiii+0xacc>
 *   @0x2d7890 mov r0, r3
 *   @0x2d7894 mov r1, r5
 *   @0x2d7898 bl 0x318d10 <__divsi3>
 *   @0x2d789c cmp r0, #1
 *   @0x2d78a0 subgt r0, r0, #1
 *   @0x2d78a4 movgt r2, #0
 *   @0x2d78a8 ble 0x2d8120 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc20>
 *   @0x2d78ac cmp r8, r4
 *   @0x2d78b0 add r3, r4, r6
 *   @0x2d78b4 add r2, r2, #1
 *   @0x2d78b8 ldrhi r1, [r3]
 *   @0x2d78bc strhi r1, [r4]
 *   @0x2d78c0 movhi r4, r3
 *   @0x2d78c4 add r3, r4, r7
 *   @0x2d78c8 cmp r2, r0
 *   @0x2d78cc ldr r1, [r3]
 *   @0x2d78d0 str r1, [r4]
 *   @0x2d78d4 mov r4, r3
 *   @0x2d78d8 bne 0x2d78ac <_ZN16b2ParticleSystem12RotateBufferEiii+0x3ac>
 *   @0x2d78dc add r9, r9, #1
 *   @0x2d78e0 vstr s16, [r3]
 *   @0x2d78e4 cmp r9, r5
 *   @0x2d78e8 bne 0x2d787c <_ZN16b2ParticleSystem12RotateBufferEiii+0x37c>
 *   @0x2d78ec ldr r4, [sp, #0x18]
 *   @0x2d78f0 ldr r11, [sp, #0x1c]
 *   @0x2d78f4 ldr r3, [sp, #0xc]
 *   @0x2d78f8 ldr r7, [r3, #0x54]
 *   @0x2d78fc cmp r7, #0
 *   @0x2d7900 beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c>
 *   @0x2d7904 ldr r3, [sp, #0x20]
 *   @0x2d7908 add r9, r7, r3
 *   @0x2d790c ldr r3, [sp, #0x24]
 *   @0x2d7910 add r12, r7, r3
 *   @0x2d7914 rsb r3, r9, r12
 *   @0x2d7918 asrs r3, r3, #2
 *   @0x2d791c str r3, [sp, #0x4]
 *   @0x2d7920 beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c>
 *   @0x2d7924 ldr r3, [sp, #0x28]
 *   @0x2d7928 ldr r2, [sp, #0x4]
 *   @0x2d792c add r7, r7, r3
 *   @0x2d7930 ldr r3, [sp, #0x4]
 *   @0x2d7934 rsb r0, r9, r7
 *   @0x2d7938 asr r0, r0, #2
 *   @0x2d793c rsb r2, r2, r0
 *   @0x2d7940 str r2, [sp, #0x1c]
 *   @0x2d7944 cmp r3, r2
 *   @0x2d7948 ldrne r10, [sp, #0x4]
 *   @0x2d794c bne 0x2d7958 <_ZN16b2ParticleSystem12RotateBufferEiii+0x458>
 *   @0x2d7950 b 0x2d81d8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xcd8>
 *   @0x2d7954 mov r10, r1
 *   @0x2d7958 mov r1, r10
 *   @0x2d795c bl 0x318dec <__aeabi_idivmod>
 *   @0x2d7960 mov r0, r10
 *   @0x2d7964 cmp r1, #0
 *   @0x2d7968 bne 0x2d7954 <_ZN16b2ParticleSystem12RotateBufferEiii+0x454>
 *   @0x2d796c cmp r10, #0
 *   @0x2d7970 ble 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c>
 *   @0x2d7974 ldr r2, [sp, #0x1c]
 *   @0x2d7978 ldr r3, [sp, #0x4]
 *   @0x2d797c str r4, [sp, #0x30]
 *   @0x2d7980 lsl r2, r2, #2
 *   @0x2d7984 str r11, [sp, #0x34]
 *   @0x2d7988 lsl r5, r3, #2
 *   @0x2d798c rsb r6, r2, #0
 *   @0x2d7990 rsb r8, r5, r7
 *   @0x2d7994 mov r7, r1
 *   @0x2d7998 str r2, [sp, #0x2c]
 *   @0x2d799c ldr r2, [sp, #0x4]
 *   @0x2d79a0 ldr r3, [sp, #0x1c]
 *   @0x2d79a4 ldrb r11, [r9]
 *   @0x2d79a8 cmp r2, r3
 *   @0x2d79ac ldrb r2, [r9, #0x1]
 *   @0x2d79b0 ldrb r3, [r9, #0x2]
 *   @0x2d79b4 str r2, [sp, #0x8]
 *   @0x2d79b8 ldrb r2, [r9, #0x3]
 *   @0x2d79bc str r3, [sp, #0x14]
 *   @0x2d79c0 str r2, [sp, #0x18]
 *   @0x2d79c4 blt 0x2d8030 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb30>
 *   @0x2d79c8 mov r1, r10
 *   @0x2d79cc ldr r0, [sp, #0x4]
 *   @0x2d79d0 bl 0x318d10 <__divsi3>
 *   @0x2d79d4 cmp r0, #1
 *   @0x2d79d8 subgt r0, r0, #1
 *   @0x2d79dc movgt r2, r9
 *   @0x2d79e0 movgt r1, #0
 *   @0x2d79e4 ble 0x2d8128 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc28>
 *   @0x2d79e8 cmp r8, r2
 *   @0x2d79ec add r3, r2, r5
 *   @0x2d79f0 add r1, r1, #1
 *   @0x2d79f4 ldrhi r12, [r3]
 *   @0x2d79f8 strhi r12, [r2]
 *   @0x2d79fc movhi r2, r3
 *   @0x2d7a00 add r3, r2, r6
 *   @0x2d7a04 cmp r1, r0
 *   @0x2d7a08 ldr r12, [r3]
 *   @0x2d7a0c str r12, [r2]
 *   @0x2d7a10 mov r2, r3
 *   @0x2d7a14 bne 0x2d79e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x4e8>
 *   @0x2d7a18 ldr r2, [sp, #0x8]
 *   @0x2d7a1c add r7, r7, #1
 *   @0x2d7a20 cmp r7, r10
 *   @0x2d7a24 strb r11, [r3]
 *   @0x2d7a28 add r9, r9, #4
 *   @0x2d7a2c strb r2, [r3, #0x1]
 *   @0x2d7a30 ldr r2, [sp, #0x14]
 *   @0x2d7a34 strb r2, [r3, #0x2]
 *   @0x2d7a38 ldr r2, [sp, #0x18]
 *   @0x2d7a3c strb r2, [r3, #0x3]
 *   @0x2d7a40 bne 0x2d799c <_ZN16b2ParticleSystem12RotateBufferEiii+0x49c>
 *   @0x2d7a44 ldr r4, [sp, #0x30]
 *   @0x2d7a48 ldr r11, [sp, #0x34]
 *   @0x2d7a4c ldr r3, [sp, #0xc]
 *   @0x2d7a50 ldr r8, [r3, #0x60]
 *   @0x2d7a54 cmp r8, #0
 *   @0x2d7a58 beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674>
 *   @0x2d7a5c ldr r3, [sp, #0x20]
 *   @0x2d7a60 ldr r1, [sp, #0x24]
 *   @0x2d7a64 add r10, r8, r3
 *   @0x2d7a68 add r3, r8, r1
 *   @0x2d7a6c rsb r2, r10, r3
 *   @0x2d7a70 asrs r2, r2, #2
 *   @0x2d7a74 str r2, [sp, #0x4]
 *   @0x2d7a78 beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674>
 *   @0x2d7a7c ldr r2, [sp, #0x28]
 *   @0x2d7a80 ldr r1, [sp, #0x4]
 *   @0x2d7a84 add r8, r8, r2
 *   @0x2d7a88 ldr r2, [sp, #0x4]
 *   @0x2d7a8c rsb r0, r10, r8
 *   @0x2d7a90 asr r0, r0, #2
 *   @0x2d7a94 rsb r2, r2, r0
 *   @0x2d7a98 str r2, [sp, #0x8]
 *   @0x2d7a9c cmp r1, r2
 *   @0x2d7aa0 ldrne r9, [sp, #0x4]
 *   @0x2d7aa4 bne 0x2d7ab0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x5b0>
 *   @0x2d7aa8 b 0x2d8238 <_ZN16b2ParticleSystem12RotateBufferEiii+0xd38>
 *   @0x2d7aac mov r9, r1
 *   @0x2d7ab0 mov r1, r9
 *   @0x2d7ab4 bl 0x318dec <__aeabi_idivmod>
 *   @0x2d7ab8 mov r0, r9
 *   @0x2d7abc cmp r1, #0
 *   @0x2d7ac0 bne 0x2d7aac <_ZN16b2ParticleSystem12RotateBufferEiii+0x5ac>
 *   @0x2d7ac4 cmp r9, #0
 *   @0x2d7ac8 ble 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674>
 *   @0x2d7acc ldr r2, [sp, #0x8]
 *   @0x2d7ad0 mov r5, r9
 *   @0x2d7ad4 str r11, [sp, #0x1c]
 *   @0x2d7ad8 mov r11, r1
 *   @0x2d7adc str r4, [sp, #0x18]
 *   @0x2d7ae0 lsl r3, r2, #2
 *   @0x2d7ae4 ldr r2, [sp, #0x4]
 *   @0x2d7ae8 rsb r7, r3, #0
 *   @0x2d7aec sub r3, r3, #4
 *   @0x2d7af0 str r3, [sp, #0x14]
 *   @0x2d7af4 lsl r6, r2, #2
 *   @0x2d7af8 rsb r8, r6, r8
 *   @0x2d7afc ldr r3, [sp, #0x4]
 *   @0x2d7b00 mov r4, r10
 *   @0x2d7b04 ldr r2, [sp, #0x8]
 *   @0x2d7b08 ldr r9, [r10], #4
 *   @0x2d7b0c cmp r3, r2
 *   @0x2d7b10 blt 0x2d8088 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb88>
 *   @0x2d7b14 mov r0, r3
 *   @0x2d7b18 mov r1, r5
 *   @0x2d7b1c bl 0x318d10 <__divsi3>
 *   @0x2d7b20 cmp r0, #1
 *   @0x2d7b24 subgt r0, r0, #1
 *   @0x2d7b28 movgt r2, #0
 *   @0x2d7b2c ble 0x2d8118 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc18>
 *   @0x2d7b30 cmp r8, r4
 *   @0x2d7b34 add r2, r2, #1
 *   @0x2d7b38 ldrhi r3, [r4, r6]
 *   @0x2d7b3c strhi r3, [r4]
 *   @0x2d7b40 addhi r4, r4, r6
 *   @0x2d7b44 add r3, r4, r7
 *   @0x2d7b48 cmp r2, r0
 *   @0x2d7b4c ldr r1, [r4, r7]
 *   @0x2d7b50 str r1, [r4]
 *   @0x2d7b54 mov r4, r3
 *   @0x2d7b58 bne 0x2d7b30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x630>
 *   @0x2d7b5c add r11, r11, #1
 *   @0x2d7b60 str r9, [r3]
 *   @0x2d7b64 cmp r11, r5
 *   @0x2d7b68 bne 0x2d7afc <_ZN16b2ParticleSystem12RotateBufferEiii+0x5fc>
 *   @0x2d7b6c ldr r4, [sp, #0x18]
 *   @0x2d7b70 ldr r11, [sp, #0x1c]
 *   @0x2d7b74 ldr r3, [sp, #0xc]
 *   @0x2d7b78 ldr r12, [r3, #0x68]
 *   @0x2d7b7c cmp r12, #0
 *   @0x2d7b80 ble 0x2d7bd8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6d8>
 *   @0x2d7b84 ldr r3, [sp, #0xc]
 *   @0x2d7b88 lsl r12, r12, #3
 *   @0x2d7b8c ldr r5, [sp, #0x10]
 *   @0x2d7b90 ldr r0, [r3, #0x70]
 *   @0x2d7b94 mov r3, #0
 *   @0x2d7b98 ldr r2, [r0, r3]
 *   @0x2d7b9c cmp r4, r2
 *   @0x2d7ba0 mov r1, r2
 *   @0x2d7ba4 bgt 0x2d7bc8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6c8>
 *   @0x2d7ba8 cmp r11, r2
 *   @0x2d7bac add r1, r5, r2
 *   @0x2d7bb0 rsb r1, r11, r1
 *   @0x2d7bb4 bgt 0x2d7bc8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x6c8>
 *   @0x2d7bb8 cmp r5, r2
 *   @0x2d7bbc add r1, r4, r2
 *   @0x2d7bc0 rsb r1, r11, r1
 *   @0x2d7bc4 movle r1, r2
 *   @0x2d7bc8 str r1, [r0, r3]
 *   @0x2d7bcc add r3, r3, #8
 *   @0x2d7bd0 cmp r3, r12
 *   @0x2d7bd4 bne 0x2d7b98 <_ZN16b2ParticleSystem12RotateBufferEiii+0x698>
 *   @0x2d7bd8 ldr r3, [sp, #0xc]
 *   @0x2d7bdc ldr r12, [r3, #0x74]
 *   @0x2d7be0 cmp r12, #0
 *   @0x2d7be4 ble 0x2d7c8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x78c>
 *   @0x2d7be8 ldr r3, [sp, #0xc]
 *   @0x2d7bec add r12, r12, r12, lsl #1
 *   @0x2d7bf0 mov r2, #0
 *   @0x2d7bf4 ldr r5, [sp, #0x10]
 *   @0x2d7bf8 lsl r12, r12, #3
 *   @0x2d7bfc ldr r0, [r3, #0x7c]
 *   @0x2d7c00 b 0x2d7c48 <_ZN16b2ParticleSystem12RotateBufferEiii+0x748>
 *   @0x2d7c04 cmp r11, r3
 *   @0x2d7c08 ble 0x2d7c5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x75c>
 *   @0x2d7c0c add r3, r5, r3
 *   @0x2d7c10 rsb r1, r11, r3
 *   @0x2d7c14 mov r3, r0
 *   @0x2d7c18 str r1, [r3, r2]!
 *   @0x2d7c1c ldr r1, [r3, #0x4]
 *   @0x2d7c20 cmp r4, r1
 *   @0x2d7c24 bgt 0x2d7c38 <_ZN16b2ParticleSystem12RotateBufferEiii+0x738>
 *   @0x2d7c28 cmp r11, r1
 *   @0x2d7c2c ble 0x2d7c70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x770>
 *   @0x2d7c30 add r1, r5, r1
 *   @0x2d7c34 rsb r1, r11, r1
 *   @0x2d7c38 add r2, r2, #24
 *   @0x2d7c3c str r1, [r3, #0x4]
 *   @0x2d7c40 cmp r2, r12
 *   @0x2d7c44 beq 0x2d7c8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x78c>
 *   @0x2d7c48 ldr r3, [r0, r2]
 *   @0x2d7c4c cmp r4, r3
 *   @0x2d7c50 ble 0x2d7c04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x704>
 *   @0x2d7c54 mov r1, r3
 *   @0x2d7c58 b 0x2d7c14 <_ZN16b2ParticleSystem12RotateBufferEiii+0x714>
 *   @0x2d7c5c cmp r5, r3
 *   @0x2d7c60 ble 0x2d7c54 <_ZN16b2ParticleSystem12RotateBufferEiii+0x754>
 *   @0x2d7c64 add r3, r4, r3
 *   @0x2d7c68 rsb r1, r11, r3
 *   @0x2d7c6c b 0x2d7c14 <_ZN16b2ParticleSystem12RotateBufferEiii+0x714>
 *   @0x2d7c70 cmp r5, r1
 *   @0x2d7c74 add r2, r2, #24
 *   @0x2d7c78 addgt r1, r4, r1
 *   @0x2d7c7c rsbgt r1, r11, r1
 *   @0x2d7c80 cmp r2, r12
 *   @0x2d7c84 str r1, [r3, #0x4]
 *   @0x2d7c88 bne 0x2d7c48 <_ZN16b2ParticleSystem12RotateBufferEiii+0x748>
 *   @0x2d7c8c ldr r3, [sp, #0xc]
 *   @0x2d7c90 ldr r12, [r3, #0x80]
 *   @0x2d7c94 cmp r12, #0
 *   @0x2d7c98 ble 0x2d7cf4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7f4>
 *   @0x2d7c9c ldr r3, [sp, #0xc]
 *   @0x2d7ca0 add r12, r12, r12, lsl #1
 *   @0x2d7ca4 ldr r5, [sp, #0x10]
 *   @0x2d7ca8 lsl r12, r12, #3
 *   @0x2d7cac ldr r0, [r3, #0x88]
 *   @0x2d7cb0 mov r3, #0
 *   @0x2d7cb4 ldr r2, [r0, r3]
 *   @0x2d7cb8 cmp r4, r2
 *   @0x2d7cbc mov r1, r2
 *   @0x2d7cc0 bgt 0x2d7ce4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7e4>
 *   @0x2d7cc4 cmp r11, r2
 *   @0x2d7cc8 add r1, r5, r2
 *   @0x2d7ccc rsb r1, r11, r1
 *   @0x2d7cd0 bgt 0x2d7ce4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7e4>
 *   @0x2d7cd4 cmp r5, r2
 *   @0x2d7cd8 add r1, r4, r2
 *   @0x2d7cdc rsb r1, r11, r1
 *   @0x2d7ce0 movle r1, r2
 *   @0x2d7ce4 str r1, [r0, r3]
 *   @0x2d7ce8 add r3, r3, #24
 *   @0x2d7cec cmp r3, r12
 *   @0x2d7cf0 bne 0x2d7cb4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x7b4>
 *   @0x2d7cf4 ldr r3, [sp, #0xc]
 *   @0x2d7cf8 ldr r12, [r3, #0x8c]
 *   @0x2d7cfc cmp r12, #0
 *   @0x2d7d00 ble 0x2d7da8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8a8>
 *   @0x2d7d04 ldr r3, [sp, #0xc]
 *   @0x2d7d08 add r12, r12, r12, lsl #2
 *   @0x2d7d0c mov r2, #0
 *   @0x2d7d10 ldr r5, [sp, #0x10]
 *   @0x2d7d14 lsl r12, r12, #2
 *   @0x2d7d18 ldr r0, [r3, #0x94]
 *   @0x2d7d1c b 0x2d7d64 <_ZN16b2ParticleSystem12RotateBufferEiii+0x864>
 *   @0x2d7d20 cmp r11, r3
 *   @0x2d7d24 ble 0x2d7d78 <_ZN16b2ParticleSystem12RotateBufferEiii+0x878>
 *   @0x2d7d28 add r3, r5, r3
 *   @0x2d7d2c rsb r1, r11, r3
 *   @0x2d7d30 mov r3, r0
 *   @0x2d7d34 str r1, [r3, r2]!
 *   @0x2d7d38 ldr r1, [r3, #0x4]
 *   @0x2d7d3c cmp r4, r1
 *   @0x2d7d40 bgt 0x2d7d54 <_ZN16b2ParticleSystem12RotateBufferEiii+0x854>
 *   @0x2d7d44 cmp r11, r1
 *   @0x2d7d48 ble 0x2d7d8c <_ZN16b2ParticleSystem12RotateBufferEiii+0x88c>
 *   @0x2d7d4c add r1, r5, r1
 *   @0x2d7d50 rsb r1, r11, r1
 *   @0x2d7d54 add r2, r2, #20
 *   @0x2d7d58 str r1, [r3, #0x4]
 *   @0x2d7d5c cmp r2, r12
 *   @0x2d7d60 beq 0x2d7da8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8a8>
 *   @0x2d7d64 ldr r3, [r0, r2]
 *   @0x2d7d68 cmp r4, r3
 *   @0x2d7d6c ble 0x2d7d20 <_ZN16b2ParticleSystem12RotateBufferEiii+0x820>
 *   @0x2d7d70 mov r1, r3
 *   @0x2d7d74 b 0x2d7d30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x830>
 *   @0x2d7d78 cmp r5, r3
 *   @0x2d7d7c ble 0x2d7d70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x870>
 *   @0x2d7d80 add r3, r4, r3
 *   @0x2d7d84 rsb r1, r11, r3
 *   @0x2d7d88 b 0x2d7d30 <_ZN16b2ParticleSystem12RotateBufferEiii+0x830>
 *   @0x2d7d8c cmp r5, r1
 *   @0x2d7d90 add r2, r2, #20
 *   @0x2d7d94 addgt r1, r4, r1
 *   @0x2d7d98 rsbgt r1, r11, r1
 *   @0x2d7d9c cmp r2, r12
 *   @0x2d7da0 str r1, [r3, #0x4]
 *   @0x2d7da4 bne 0x2d7d64 <_ZN16b2ParticleSystem12RotateBufferEiii+0x864>
 *   @0x2d7da8 ldr r3, [sp, #0xc]
 *   @0x2d7dac ldr r12, [r3, #0x98]
 *   @0x2d7db0 cmp r12, #0
 *   @0x2d7db4 ble 0x2d7e80 <_ZN16b2ParticleSystem12RotateBufferEiii+0x980>
 *   @0x2d7db8 ldr r3, [sp, #0xc]
 *   @0x2d7dbc rsb r12, r12, r12, lsl #4
 *   @0x2d7dc0 ldr r5, [sp, #0x10]
 *   @0x2d7dc4 ldr r2, [r3, #0xa0]
 *   @0x2d7dc8 add r12, r2, r12, lsl #2
 *   @0x2d7dcc add r3, r2, #8
 *   @0x2d7dd0 b 0x2d7e38 <_ZN16b2ParticleSystem12RotateBufferEiii+0x938>
 *   @0x2d7dd4 cmp r11, r1
 *   @0x2d7dd8 ble 0x2d7e5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x95c>
 *   @0x2d7ddc add r1, r5, r1
 *   @0x2d7de0 rsb r0, r11, r1
 *   @0x2d7de4 ldr r1, [r3, #-0x4]
 *   @0x2d7de8 str r0, [r3, #-0x8]
 *   @0x2d7dec cmp r4, r1
 *   @0x2d7df0 bgt 0x2d7e04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x904>
 *   @0x2d7df4 cmp r11, r1
 *   @0x2d7df8 ble 0x2d7e70 <_ZN16b2ParticleSystem12RotateBufferEiii+0x970>
 *   @0x2d7dfc add r1, r5, r1
 *   @0x2d7e00 rsb r1, r11, r1
 *   @0x2d7e04 str r1, [r3, #-0x4]
 *   @0x2d7e08 ldr r1, [r2, #0x8]
 *   @0x2d7e0c cmp r4, r1
 *   @0x2d7e10 bgt 0x2d7e24 <_ZN16b2ParticleSystem12RotateBufferEiii+0x924>
 *   @0x2d7e14 cmp r11, r1
 *   @0x2d7e18 ble 0x2d7e4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x94c>
 *   @0x2d7e1c add r1, r5, r1
 *   @0x2d7e20 rsb r1, r11, r1
 *   @0x2d7e24 str r1, [r2, #0x8]
 *   @0x2d7e28 add r2, r2, #60
 *   @0x2d7e2c cmp r2, r12
 *   @0x2d7e30 add r3, r3, #60
 *   @0x2d7e34 beq 0x2d7e80 <_ZN16b2ParticleSystem12RotateBufferEiii+0x980>
 *   @0x2d7e38 ldr r1, [r3, #-0x8]
 *   @0x2d7e3c cmp r4, r1
 *   @0x2d7e40 ble 0x2d7dd4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8d4>
 *   @0x2d7e44 mov r0, r1
 *   @0x2d7e48 b 0x2d7de4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8e4>
 *   @0x2d7e4c cmp r5, r1
 *   @0x2d7e50 addgt r1, r4, r1
 *   @0x2d7e54 rsbgt r1, r11, r1
 *   @0x2d7e58 b 0x2d7e24 <_ZN16b2ParticleSystem12RotateBufferEiii+0x924>
 *   @0x2d7e5c cmp r5, r1
 *   @0x2d7e60 ble 0x2d7e44 <_ZN16b2ParticleSystem12RotateBufferEiii+0x944>
 *   @0x2d7e64 add r1, r4, r1
 *   @0x2d7e68 rsb r0, r11, r1
 *   @0x2d7e6c b 0x2d7de4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x8e4>
 *   @0x2d7e70 cmp r5, r1
 *   @0x2d7e74 addgt r1, r4, r1
 *   @0x2d7e78 rsbgt r1, r11, r1
 *   @0x2d7e7c b 0x2d7e04 <_ZN16b2ParticleSystem12RotateBufferEiii+0x904>
 *   @0x2d7e80 ldr r1, [sp, #0xc]
 *   @0x2d7e84 ldr r3, [r1, #0xa8]
 *   @0x2d7e88 cmp r3, #0
 *   @0x2d7e8c ldrne r0, [sp, #0x10]
 *   @0x2d7e90 bne 0x2d7ed8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9d8>
 *   @0x2d7e94 b 0x2d7528 <_ZN16b2ParticleSystem12RotateBufferEiii+0x28>
 *   @0x2d7e98 add r2, r0, r2
 *   @0x2d7e9c rsb r2, r11, r2
 *   @0x2d7ea0 ldr r1, [r3, #0x8]
 *   @0x2d7ea4 str r2, [r3, #0x4]
 *   @0x2d7ea8 sub r2, r1, #1
 *   @0x2d7eac cmp r4, r2
 *   @0x2d7eb0 bgt 0x2d7ec4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9c4>
 *   @0x2d7eb4 cmp r11, r2
 *   @0x2d7eb8 ble 0x2d7efc <_ZN16b2ParticleSystem12RotateBufferEiii+0x9fc>
 *   @0x2d7ebc add r2, r0, r2
 *   @0x2d7ec0 rsb r2, r11, r2
 *   @0x2d7ec4 add r2, r2, #1
 *   @0x2d7ec8 str r2, [r3, #0x8]
 *   @0x2d7ecc ldr r3, [r3, #0x18]
 *   @0x2d7ed0 cmp r3, #0
 *   @0x2d7ed4 beq 0x2d7528 <_ZN16b2ParticleSystem12RotateBufferEiii+0x28>
 *   @0x2d7ed8 ldr r2, [r3, #0x4]
 *   @0x2d7edc cmp r4, r2
 *   @0x2d7ee0 bgt 0x2d7ea0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9a0>
 *   @0x2d7ee4 cmp r11, r2
 *   @0x2d7ee8 bgt 0x2d7e98 <_ZN16b2ParticleSystem12RotateBufferEiii+0x998>
 *   @0x2d7eec cmp r0, r2
 *   @0x2d7ef0 addgt r2, r4, r2
 *   @0x2d7ef4 rsbgt r2, r11, r2
 *   @0x2d7ef8 b 0x2d7ea0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9a0>
 *   @0x2d7efc cmp r0, r2
 *   @0x2d7f00 addgt r2, r4, r2
 *   @0x2d7f04 rsbgt r2, r11, r2
 *   @0x2d7f08 b 0x2d7ec4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x9c4>
 *   @0x2d7f0c ldr r0, [sp, #0x8]
 *   @0x2d7f10 mov r1, r5
 *   @0x2d7f14 bl 0x318d10 <__divsi3>
 *   @0x2d7f18 cmp r0, #0
 *   @0x2d7f1c ble 0x2d80e8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xbe8>
 *   @0x2d7f20 ldr r3, [sp, #0x14]
 *   @0x2d7f24 mov r1, #0
 *   @0x2d7f28 add lr, r3, r10
 *   @0x2d7f2c cmp lr, r4
 *   @0x2d7f30 add r1, r1, #1
 *   @0x2d7f34 ldrlo r3, [r4, r7]
 *   @0x2d7f38 strlo r3, [r4]
 *   @0x2d7f3c addlo r4, r4, r7
 *   @0x2d7f40 add r3, r4, r6
 *   @0x2d7f44 cmp r1, r0
 *   @0x2d7f48 ldr r2, [r4, r6]
 *   @0x2d7f4c str r2, [r4]
 *   @0x2d7f50 mov r4, r3
 *   @0x2d7f54 bne 0x2d7f2c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa2c>
 *   @0x2d7f58 add r9, r9, #1
 *   @0x2d7f5c str r11, [r3]
 *   @0x2d7f60 cmp r9, r5
 *   @0x2d7f64 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4>
 *   @0x2d7f68 b 0x2d7664 <_ZN16b2ParticleSystem12RotateBufferEiii+0x164>
 *   @0x2d7f6c ldr r0, [sp, #0x8]
 *   @0x2d7f70 mov r1, r9
 *   @0x2d7f74 bl 0x318d10 <__divsi3>
 *   @0x2d7f78 cmp r0, #0
 *   @0x2d7f7c ble 0x2d8100 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc00>
 *   @0x2d7f80 ldr r3, [sp, #0x14]
 *   @0x2d7f84 mov r2, #0
 *   @0x2d7f88 add r1, r3, r10
 *   @0x2d7f8c cmp r1, r4
 *   @0x2d7f90 add r2, r2, #1
 *   @0x2d7f94 ldrlo r3, [r4, r7]
 *   @0x2d7f98 strlo r3, [r4]
 *   @0x2d7f9c addlo r4, r4, r7
 *   @0x2d7fa0 add r3, r4, r6
 *   @0x2d7fa4 cmp r2, r0
 *   @0x2d7fa8 ldr r12, [r4, r6]
 *   @0x2d7fac str r12, [r4]
 *   @0x2d7fb0 mov r4, r3
 *   @0x2d7fb4 bne 0x2d7f8c <_ZN16b2ParticleSystem12RotateBufferEiii+0xa8c>
 *   @0x2d7fb8 add r11, r11, #1
 *   @0x2d7fbc str r5, [r3]
 *   @0x2d7fc0 cmp r11, r9
 *   @0x2d7fc4 bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250>
 *   @0x2d7fc8 b 0x2d77c0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c0>
 *   @0x2d7fcc mov r0, r11
 *   @0x2d7fd0 mov r1, r5
 *   @0x2d7fd4 bl 0x318d10 <__divsi3>
 *   @0x2d7fd8 cmp r0, #0
 *   @0x2d7fdc ble 0x2d8120 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc20>
 *   @0x2d7fe0 ldr r2, [sp, #0x8]
 *   @0x2d7fe4 add r1, r2, r10
 *   @0x2d7fe8 mov r2, #0
 *   @0x2d7fec cmp r1, r4
 *   @0x2d7ff0 add r3, r4, r7
 *   @0x2d7ff4 add r2, r2, #1
 *   @0x2d7ff8 ldrlo r12, [r3]
 *   @0x2d7ffc strlo r12, [r4]
 *   @0x2d8000 movlo r4, r3
 *   @0x2d8004 add r3, r4, r6
 *   @0x2d8008 cmp r2, r0
 *   @0x2d800c ldr r12, [r3]
 *   @0x2d8010 str r12, [r4]
 *   @0x2d8014 mov r4, r3
 *   @0x2d8018 bne 0x2d7fec <_ZN16b2ParticleSystem12RotateBufferEiii+0xaec>
 *   @0x2d801c add r9, r9, #1
 *   @0x2d8020 vstr s16, [r3]
 *   @0x2d8024 cmp r9, r5
 *   @0x2d8028 bne 0x2d787c <_ZN16b2ParticleSystem12RotateBufferEiii+0x37c>
 *   @0x2d802c b 0x2d78ec <_ZN16b2ParticleSystem12RotateBufferEiii+0x3ec>
 *   @0x2d8030 ldr r0, [sp, #0x1c]
 *   @0x2d8034 mov r1, r10
 *   @0x2d8038 bl 0x318d10 <__divsi3>
 *   @0x2d803c cmp r0, #0
 *   @0x2d8040 ble 0x2d8128 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc28>
 *   @0x2d8044 ldr r3, [sp, #0x2c]
 *   @0x2d8048 mov r2, r9
 *   @0x2d804c mov r12, #0
 *   @0x2d8050 add r1, r9, r3
 *   @0x2d8054 cmp r1, r2
 *   @0x2d8058 add r3, r2, r6
 *   @0x2d805c add r12, r12, #1
 *   @0x2d8060 ldrlo r4, [r3]
 *   @0x2d8064 strlo r4, [r2]
 *   @0x2d8068 movlo r2, r3
 *   @0x2d806c add r3, r2, r5
 *   @0x2d8070 cmp r12, r0
 *   @0x2d8074 ldr r4, [r3]
 *   @0x2d8078 str r4, [r2]
 *   @0x2d807c mov r2, r3
 *   @0x2d8080 bne 0x2d8054 <_ZN16b2ParticleSystem12RotateBufferEiii+0xb54>
 *   @0x2d8084 b 0x2d7a18 <_ZN16b2ParticleSystem12RotateBufferEiii+0x518>
 *   @0x2d8088 ldr r0, [sp, #0x8]
 *   @0x2d808c mov r1, r5
 *   @0x2d8090 bl 0x318d10 <__divsi3>
 *   @0x2d8094 cmp r0, #0
 *   @0x2d8098 ble 0x2d8118 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc18>
 *   @0x2d809c ldr r3, [sp, #0x14]
 *   @0x2d80a0 mov r2, #0
 *   @0x2d80a4 add r1, r3, r10
 *   @0x2d80a8 cmp r1, r4
 *   @0x2d80ac add r2, r2, #1
 *   @0x2d80b0 ldrlo r3, [r4, r7]
 *   @0x2d80b4 strlo r3, [r4]
 *   @0x2d80b8 addlo r4, r4, r7
 *   @0x2d80bc add r3, r4, r6
 *   @0x2d80c0 cmp r2, r0
 *   @0x2d80c4 ldr r12, [r4, r6]
 *   @0x2d80c8 str r12, [r4]
 *   @0x2d80cc mov r4, r3
 *   @0x2d80d0 bne 0x2d80a8 <_ZN16b2ParticleSystem12RotateBufferEiii+0xba8>
 *   @0x2d80d4 add r11, r11, #1
 *   @0x2d80d8 str r9, [r3]
 *   @0x2d80dc cmp r11, r5
 *   @0x2d80e0 bne 0x2d7afc <_ZN16b2ParticleSystem12RotateBufferEiii+0x5fc>
 *   @0x2d80e4 b 0x2d7b6c <_ZN16b2ParticleSystem12RotateBufferEiii+0x66c>
 *   @0x2d80e8 add r9, r9, #1
 *   @0x2d80ec mov r3, r4
 *   @0x2d80f0 cmp r9, r5
 *   @0x2d80f4 str r11, [r3]
 *   @0x2d80f8 bne 0x2d75f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0xf4>
 *   @0x2d80fc b 0x2d7664 <_ZN16b2ParticleSystem12RotateBufferEiii+0x164>
 *   @0x2d8100 add r11, r11, #1
 *   @0x2d8104 mov r3, r4
 *   @0x2d8108 cmp r11, r9
 *   @0x2d810c str r5, [r3]
 *   @0x2d8110 bne 0x2d7750 <_ZN16b2ParticleSystem12RotateBufferEiii+0x250>
 *   @0x2d8114 b 0x2d77c0 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c0>
 *   @0x2d8118 mov r3, r4
 *   @0x2d811c b 0x2d7b5c <_ZN16b2ParticleSystem12RotateBufferEiii+0x65c>
 *   @0x2d8120 mov r3, r4
 *   @0x2d8124 b 0x2d78dc <_ZN16b2ParticleSystem12RotateBufferEiii+0x3dc>
 *   @0x2d8128 mov r3, r9
 *   @0x2d812c b 0x2d7a18 <_ZN16b2ParticleSystem12RotateBufferEiii+0x518>
 *   @0x2d8130 cmp r10, r3
 *   @0x2d8134 beq 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8>
 *   @0x2d8138 add r2, r10, #4
 *   @0x2d813c add r0, r3, #4
 *   @0x2d8140 rsb r2, r2, r3
 *   @0x2d8144 bic r2, r2, #3
 *   @0x2d8148 add r0, r0, r2
 *   @0x2d814c ldr r2, [r10]
 *   @0x2d8150 ldr r1, [r3]
 *   @0x2d8154 str r1, [r10], #4
 *   @0x2d8158 str r2, [r3], #4
 *   @0x2d815c cmp r3, r0
 *   @0x2d8160 bne 0x2d814c <_ZN16b2ParticleSystem12RotateBufferEiii+0xc4c>
 *   @0x2d8164 b 0x2d77c8 <_ZN16b2ParticleSystem12RotateBufferEiii+0x2c8>
 *   @0x2d8168 cmp r10, r3
 *   @0x2d816c beq 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c>
 *   @0x2d8170 add r2, r10, #4
 *   @0x2d8174 add r0, r3, #4
 *   @0x2d8178 rsb r2, r2, r3
 *   @0x2d817c bic r2, r2, #3
 *   @0x2d8180 add r0, r0, r2
 *   @0x2d8184 ldr r2, [r10]
 *   @0x2d8188 ldr r1, [r3]
 *   @0x2d818c str r1, [r10], #4
 *   @0x2d8190 str r2, [r3], #4
 *   @0x2d8194 cmp r3, r0
 *   @0x2d8198 bne 0x2d8184 <_ZN16b2ParticleSystem12RotateBufferEiii+0xc84>
 *   @0x2d819c b 0x2d766c <_ZN16b2ParticleSystem12RotateBufferEiii+0x16c>
 *   @0x2d81a0 cmp r10, r3
 *   @0x2d81a4 beq 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4>
 *   @0x2d81a8 add r2, r10, #4
 *   @0x2d81ac add r0, r3, #4
 *   @0x2d81b0 rsb r2, r2, r3
 *   @0x2d81b4 bic r2, r2, #3
 *   @0x2d81b8 add r0, r0, r2
 *   @0x2d81bc ldr r2, [r10]
 *   @0x2d81c0 ldr r1, [r3]
 *   @0x2d81c4 str r1, [r10], #4
 *   @0x2d81c8 str r2, [r3], #4
 *   @0x2d81cc cmp r3, r0
 *   @0x2d81d0 bne 0x2d81bc <_ZN16b2ParticleSystem12RotateBufferEiii+0xcbc>
 *   @0x2d81d4 b 0x2d78f4 <_ZN16b2ParticleSystem12RotateBufferEiii+0x3f4>
 *   @0x2d81d8 cmp r9, r12
 *   @0x2d81dc beq 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c>
 *   @0x2d81e0 add r2, r9, #4
 *   @0x2d81e4 add r0, r12, #4
 *   @0x2d81e8 mov r3, r12
 *   @0x2d81ec mov r1, r2
 *   @0x2d81f0 ldrb r8, [r1, #-0x4]
 *   @0x2d81f4 cmp r12, r2
 *   @0x2d81f8 ldrb r7, [r9, #0x1]
 *   @0x2d81fc add r1, r1, #4
 *   @0x2d8200 ldrb r6, [r9, #0x2]
 *   @0x2d8204 add r0, r0, #4
 *   @0x2d8208 ldrb r5, [r9, #0x3]
 *   @0x2d820c add r3, r3, #4
 *   @0x2d8210 ldr r10, [r0, #-0x8]
 *   @0x2d8214 mov r9, r2
 *   @0x2d8218 add r2, r2, #4
 *   @0x2d821c str r10, [r1, #-0x8]
 *   @0x2d8220 strb r8, [r0, #-0x8]
 *   @0x2d8224 strb r7, [r3, #-0x3]
 *   @0x2d8228 strb r6, [r3, #-0x2]
 *   @0x2d822c strb r5, [r3, #-0x1]
 *   @0x2d8230 bne 0x2d81f0 <_ZN16b2ParticleSystem12RotateBufferEiii+0xcf0>
 *   @0x2d8234 b 0x2d7a4c <_ZN16b2ParticleSystem12RotateBufferEiii+0x54c>
 *   @0x2d8238 cmp r10, r3
 *   @0x2d823c beq 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674>
 *   @0x2d8240 add r2, r10, #4
 *   @0x2d8244 add r0, r3, #4
 *   @0x2d8248 rsb r2, r2, r3
 *   @0x2d824c bic r2, r2, #3
 *   @0x2d8250 add r0, r0, r2
 *   @0x2d8254 ldr r2, [r10]
 *   @0x2d8258 ldr r1, [r3]
 *   @0x2d825c str r1, [r10], #4
 *   @0x2d8260 str r2, [r3], #4
 *   @0x2d8264 cmp r3, r0
 *   @0x2d8268 bne 0x2d8254 <_ZN16b2ParticleSystem12RotateBufferEiii+0xd54>
 *   @0x2d826c b 0x2d7b74 <_ZN16b2ParticleSystem12RotateBufferEiii+0x674>
 *
 * ══ §2/13 b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)  0x2dd360  size 3420  855 条（0x2dd360..0x2de0bc）
 * @func 0x2dd360 0x2de0bc  size 3420  855 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x8c8×3 / 0xb6700×3 / b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x87c×2 / b2ClipSegmentToLine(b2ClipVertex*, b2ClipVertex const*, b2Vec2 const&, float, int)×2 / b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x3f8×2 / b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0xc94×2 / b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x550 / b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x3b4
 * 字段偏移 top8: 0xf8×18 / 0x8×5 / 0x6c×4 / 0x68×4 / 0x80×3 / 0x3c×2 / 0x29×2 / 0x38×2
 * VFP 指令 399 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dd360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dd364 vpush {d8, d9, d10}
 *   @0x2dd368 sub sp, sp, #164
 *   @0x2dd36c vldr s15, [r3, #4]
 *   @0x2dd370 vldr s10, [r3, #8]
 *   @0x2dd374 vldr s11, [r3, #12]
 *   @0x2dd378 ldr r12, [sp, #0xe4]
 *   @0x2dd37c vldr s13, [r12, #4]
 *   @0x2dd380 vsub.f32 s13, s13, s15
 *   @0x2dd384 vldr s9, [r12, #12]
 *   @0x2dd388 vldr s7, [r12, #8]
 *   @0x2dd38c vldr s6, [r12]
 *   @0x2dd390 vldr s8, [r3]
 *   @0x2dd394 add r3, r2, #28
 *   @0x2dd398 mov r4, r0
 *   @0x2dd39c ldr r8, [sp, #0xe0]
 *   @0x2dd3a0 add r10, r0, #156
 *   @0x2dd3a4 mov r7, r1
 *   @0x2dd3a8 ldm r3, {r0, r1}
 *   @0x2dd3ac add r9, r2, #12
 *   @0x2dd3b0 add r5, r4, #164
 *   @0x2dd3b4 add lr, r2, #20
 *   @0x2dd3b8 add r6, r4, #172
 *   @0x2dd3bc add r12, r2, #36
 *   @0x2dd3c0 add r3, r4, #180
 *   @0x2dd3c4 vmul.f32 s12, s10, s13
 *   @0x2dd3c8 vmul.f32 s15, s10, s9
 *   @0x2dd3cc vmul.f32 s13, s11, s13
 *   @0x2dd3d0 vmul.f32 s14, s7, s10
 *   @0x2dd3d4 vsub.f32 s8, s6, s8
 *   @0x2dd3d8 vmla.f32 s14, s11, s9
 *   @0x2dd3dc vnmls.f32 s15, s11, s7
 *   @0x2dd3e0 vstr s14, [r4, #144]
 *   @0x2dd3e4 vmla.f32 s12, s11, s8
 *   @0x2dd3e8 vstr s15, [r4, #140]
 *   @0x2dd3ec vmls.f32 s13, s10, s8
 *   @0x2dd3f0 vstr s12, [r4, #132]
 *   @0x2dd3f4 vstr s13, [r4, #136]
 *   @0x2dd3f8 vldr s11, [r8, #16]
 *   @0x2dd3fc vmul.f32 s10, s11, s15
 *   @0x2dd400 vldr s9, [r8, #12]
 *   @0x2dd404 vmul.f32 s11, s11, s14
 *   @0x2dd408 vnmls.f32 s10, s9, s14
 *   @0x2dd40c vmla.f32 s11, s9, s15
 *   @0x2dd410 vadd.f32 s12, s10, s12
 *   @0x2dd414 vadd.f32 s13, s11, s13
 *   @0x2dd418 vstr s12, [r4, #148]
 *   @0x2dd41c vstr s13, [r4, #152]
 *   @0x2dd420 stm r10, {r0, r1}
 *   @0x2dd424 ldm r9, {r0, r1}
 *   @0x2dd428 stm r5, {r0, r1}
 *   @0x2dd42c ldm lr, {r0, r1}
 *   @0x2dd430 stm r6, {r0, r1}
 *   @0x2dd434 ldm r12, {r0, r1}
 *   @0x2dd438 stm r3, {r0, r1}
 *   @0x2dd43c vldr s16, [r4, #176]
 *   @0x2dd440 vldr s12, [r4, #168]
 *   @0x2dd444 vsub.f32 s16, s16, s12
 *   @0x2dd448 vldr s17, [r4, #172]
 *   @0x2dd44c vldr s13, [r4, #164]
 *   @0x2dd450 ldrb r9, [r2, #0x2c]
 *   @0x2dd454 ldrb r10, [r2, #0x2d]
 *   @0x2dd458 vmul.f32 s14, s16, s16
 *   @0x2dd45c vsub.f32 s17, s17, s13
 *   @0x2dd460 vmla.f32 s14, s17, s17
 *   @0x2dd464 vsqrt.f32 s15, s14
 *   @0x2dd468 vcmp.f32 s15, s15
 *   @0x2dd46c vmrs APSR_nzcv, fpscr
 *   @0x2dd470 bne 0x2de0a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xd44>
 *   @0x2dd474 vldr s14, [pc, #976]
 *   @0x2dd478 vcmpe.f32 s15, s14
 *   @0x2dd47c vldr s11, [r4, #152]
 *   @0x2dd480 vmrs APSR_nzcv, fpscr
 *   @0x2dd484 vmovpl.f32 s14, #1.000000e+00
 *   @0x2dd488 vdivpl.f32 s15, s14, s15
 *   @0x2dd48c vldr s14, [r4, #148]
 *   @0x2dd490 vmulpl.f32 s17, s17, s15
 *   @0x2dd494 vsub.f32 s18, s11, s12
 *   @0x2dd498 vmulpl.f32 s16, s16, s15
 *   @0x2dd49c cmp r9, #0
 *   @0x2dd4a0 vneg.f32 s15, s17
 *   @0x2dd4a4 vstr s16, [r4, #196]
 *   @0x2dd4a8 vmul.f32 s18, s15, s18
 *   @0x2dd4ac vstr s15, [r4, #200]
 *   @0x2dd4b0 vsub.f32 s15, s14, s13
 *   @0x2dd4b4 vmla.f32 s18, s15, s16
 *   @0x2dd4b8 bne 0x2dd524 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x1c4>
 *   @0x2dd4bc cmp r10, #0
 *   @0x2dd4c0 mov r11, r9
 *   @0x2dd4c4 vldr s19, [pc, #900]
 *   @0x2dd4c8 bne 0x2dd5a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x244>
 *   @0x2dd4cc cmp r9, #0
 *   @0x2dd4d0 bne 0x2dd7b4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x454>
 *   @0x2dd4d4 vcmpe.f32 s18, #0
 *   @0x2dd4d8 vmrs APSR_nzcv, fpscr
 *   @0x2dd4dc movlt r3, #0
 *   @0x2dd4e0 movge r3, #1
 *   @0x2dd4e4 cmp r3, #0
 *   @0x2dd4e8 strb r3, [r4, #0xf8]
 *   @0x2dd4ec beq 0x2ddba0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x840>
 *   @0x2dd4f0 add r2, r4, #196
 *   @0x2dd4f4 add r3, r4, #212
 *   @0x2dd4f8 ldm r2, {r0, r1}
 *   @0x2dd4fc stm r3, {r0, r1}
 *   @0x2dd500 vldr s14, [r4, #196]
 *   @0x2dd504 vldr s15, [r4, #200]
 *   @0x2dd508 vneg.f32 s14, s14
 *   @0x2dd50c vneg.f32 s15, s15
 *   @0x2dd510 vstr s14, [r4, #228]
 *   @0x2dd514 vstr s14, [r4, #236]
 *   @0x2dd518 vstr s15, [r4, #232]
 *   @0x2dd51c vstr s15, [r4, #240]
 *   @0x2dd520 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2dd524 vldr s19, [r4, #160]
 *   @0x2dd528 vsub.f32 s20, s12, s19
 *   @0x2dd52c vldr s10, [r4, #156]
 *   @0x2dd530 vmul.f32 s12, s20, s20
 *   @0x2dd534 vsub.f32 s21, s13, s10
 *   @0x2dd538 vmla.f32 s12, s21, s21
 *   @0x2dd53c vsqrt.f32 s15, s12
 *   @0x2dd540 vcmp.f32 s15, s15
 *   @0x2dd544 vmrs APSR_nzcv, fpscr
 *   @0x2dd548 bne 0x2ddf1c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbbc>
 *   @0x2dd54c vldr s13, [pc, #760]
 *   @0x2dd550 vcmpe.f32 s15, s13
 *   @0x2dd554 vmrs APSR_nzcv, fpscr
 *   @0x2dd558 vmovpl.f32 s13, #1.000000e+00
 *   @0x2dd55c vdivpl.f32 s15, s13, s15
 *   @0x2dd560 vmulpl.f32 s20, s20, s15
 *   @0x2dd564 vmulpl.f32 s21, s21, s15
 *   @0x2dd568 vstr s20, [r4, #188]
 *   @0x2dd56c vmul.f32 s15, s20, s17
 *   @0x2dd570 vnmls.f32 s15, s21, s16
 *   @0x2dd574 vsub.f32 s19, s11, s19
 *   @0x2dd578 vneg.f32 s21, s21
 *   @0x2dd57c vmul.f32 s19, s21, s19
 *   @0x2dd580 vstr s21, [r4, #192]
 *   @0x2dd584 vsub.f32 s10, s14, s10
 *   @0x2dd588 vcmpe.f32 s15, #0
 *   @0x2dd58c vmrs APSR_nzcv, fpscr
 *   @0x2dd590 movlt r11, #0
 *   @0x2dd594 movge r11, #1
 *   @0x2dd598 cmp r10, #0
 *   @0x2dd59c vmla.f32 s19, s10, s20
 *   @0x2dd5a0 beq 0x2dd4cc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x16c>
 *   @0x2dd5a4 vldr s20, [r4, #184]
 *   @0x2dd5a8 vldr s10, [r4, #176]
 *   @0x2dd5ac vldr s21, [r4, #180]
 *   @0x2dd5b0 vldr s12, [r4, #172]
 *   @0x2dd5b4 vsub.f32 s20, s20, s10
 *   @0x2dd5b8 vmul.f32 s13, s20, s20
 *   @0x2dd5bc vsub.f32 s21, s21, s12
 *   @0x2dd5c0 vmla.f32 s13, s21, s21
 *   @0x2dd5c4 vsqrt.f32 s15, s13
 *   @0x2dd5c8 vcmp.f32 s15, s15
 *   @0x2dd5cc vmrs APSR_nzcv, fpscr
 *   @0x2dd5d0 bne 0x2de084 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xd24>
 *   @0x2dd5d4 vldr s13, [pc, #624]
 *   @0x2dd5d8 vcmpe.f32 s15, s13
 *   @0x2dd5dc vmrs APSR_nzcv, fpscr
 *   @0x2dd5e0 vmovpl.f32 s13, #1.000000e+00
 *   @0x2dd5e4 vdivpl.f32 s15, s13, s15
 *   @0x2dd5e8 vmulpl.f32 s21, s21, s15
 *   @0x2dd5ec vmulpl.f32 s20, s20, s15
 *   @0x2dd5f0 vmul.f32 s16, s21, s16
 *   @0x2dd5f4 vstr s20, [r4, #204]
 *   @0x2dd5f8 vnmls.f32 s16, s20, s17
 *   @0x2dd5fc vsub.f32 s11, s11, s10
 *   @0x2dd600 vneg.f32 s15, s21
 *   @0x2dd604 vmul.f32 s11, s15, s11
 *   @0x2dd608 vstr s15, [r4, #208]
 *   @0x2dd60c vsub.f32 s14, s14, s12
 *   @0x2dd610 vcmpe.f32 s16, #0
 *   @0x2dd614 vmrs APSR_nzcv, fpscr
 *   @0x2dd618 movle r3, #0
 *   @0x2dd61c movgt r3, #1
 *   @0x2dd620 cmp r9, #0
 *   @0x2dd624 vmla.f32 s11, s14, s20
 *   @0x2dd628 beq 0x2ddf3c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbdc>
 *   @0x2dd62c tst r3, r11
 *   @0x2dd630 beq 0x2dd764 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x404>
 *   @0x2dd634 vcmpe.f32 s19, #0
 *   @0x2dd638 vmrs APSR_nzcv, fpscr
 *   @0x2dd63c blt 0x2dd8b0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x550>
 *   @0x2dd640 add r3, r4, #196
 *   @0x2dd644 add r12, r4, #212
 *   @0x2dd648 add r9, r4, #188
 *   @0x2dd64c mov lr, #1
 *   @0x2dd650 ldm r3, {r0, r1}
 *   @0x2dd654 add r2, r4, #228
 *   @0x2dd658 strb lr, [r4, #0xf8]
 *   @0x2dd65c add lr, r4, #204
 *   @0x2dd660 add r3, r4, #236
 *   @0x2dd664 stm r12, {r0, r1}
 *   @0x2dd668 ldm r9, {r0, r1}
 *   @0x2dd66c stm r2, {r0, r1}
 *   @0x2dd670 mov r2, lr
 *   @0x2dd674 ldm lr, {r0, r1}
 *   @0x2dd678 stm r3, {r0, r1}
 *   @0x2dd67c ldr r1, [r8, #0x94]
 *   @0x2dd680 cmp r1, #0
 *   @0x2dd684 str r1, [r4, #0x80]
 *   @0x2dd688 addgt r3, r8, #84
 *   @0x2dd68c addgt r12, r4, #64
 *   @0x2dd690 addgt r0, r4, #68
 *   @0x2dd694 movgt r2, #0
 *   @0x2dd698 ble 0x2dd714 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3b4>
 *   @0x2dd69c vldr s13, [r4, #140]
 *   @0x2dd6a0 vldr s15, [r3, #-60]
 *   @0x2dd6a4 vldr s11, [r4, #144]
 *   @0x2dd6a8 vmul.f32 s14, s13, s15
 *   @0x2dd6ac vldr s12, [r3, #-64]
 *   @0x2dd6b0 vldr s9, [r4, #132]
 *   @0x2dd6b4 vldr s10, [r4, #136]
 *   @0x2dd6b8 add r2, r2, #1
 *   @0x2dd6bc cmp r2, r1
 *   @0x2dd6c0 add r3, r3, #8
 *   @0x2dd6c4 vmul.f32 s15, s11, s15
 *   @0x2dd6c8 vnmls.f32 s14, s11, s12
 *   @0x2dd6cc vmla.f32 s15, s12, s13
 *   @0x2dd6d0 vadd.f32 s14, s14, s9
 *   @0x2dd6d4 vadd.f32 s15, s15, s10
 *   @0x2dd6d8 vstr s14, [r12, #-64]
 *   @0x2dd6dc vstr s15, [r0, #-64]
 *   @0x2dd6e0 vldr s15, [r3, #-4]
 *   @0x2dd6e4 vldr s13, [r4, #140]
 *   @0x2dd6e8 vmul.f32 s14, s13, s15
 *   @0x2dd6ec vldr s12, [r3, #-8]
 *   @0x2dd6f0 vldr s11, [r4, #144]
 *   @0x2dd6f4 vnmls.f32 s14, s11, s12
 *   @0x2dd6f8 vmul.f32 s15, s11, s15
 *   @0x2dd6fc vmov lr, s14
 *   @0x2dd700 vmla.f32 s15, s12, s13
 *   @0x2dd704 str lr, [r12], #8
 *   @0x2dd708 vmov lr, s15
 *   @0x2dd70c str lr, [r0], #8
 *   @0x2dd710 bne 0x2dd69c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x33c>
 *   @0x2dd714 mov r3, #0
 *   @0x2dd718 movw r2, #0xd70a
 *   @0x2dd71c add r0, sp, #8
 *   @0x2dd720 movt r2, #0x3ca3
 *   @0x2dd724 mov r1, r4
 *   @0x2dd728 str r2, [r4, #0xf4]
 *   @0x2dd72c str r3, [r7, #0x3c]
 *   @0x2dd730 bl 0x2dd1a4 <_ZN12b2EPCollider21ComputeEdgeSeparationEv>
 *   @0x2dd734 ldr r9, [sp, #0x8]
 *   @0x2dd738 ldr r10, [sp, #0xc]
 *   @0x2dd73c vldr s16, [sp, #16]
 *   @0x2dd740 cmp r9, #0
 *   @0x2dd744 beq 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8>
 *   @0x2dd748 vldr s15, [r4, #244]
 *   @0x2dd74c vcmpe.f32 s16, s15
 *   @0x2dd750 vmrs APSR_nzcv, fpscr
 *   @0x2dd754 ble 0x2dd8fc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x59c>
 *   @0x2dd758 add sp, sp, #164
 *   @0x2dd75c vpop {d8, d9, d10}
 *   @0x2dd760 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2dd764 cmp r11, #0
 *   @0x2dd768 beq 0x2dd85c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4fc>
 *   @0x2dd76c vcmpe.f32 s19, #0
 *   @0x2dd770 vmrs APSR_nzcv, fpscr
 *   @0x2dd774 blt 0x2ddccc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x96c>
 *   @0x2dd778 add r3, r4, #196
 *   @0x2dd77c add r12, r4, #212
 *   @0x2dd780 add r9, r4, #188
 *   @0x2dd784 mov lr, #1
 *   @0x2dd788 ldm r3, {r0, r1}
 *   @0x2dd78c add r2, r4, #228
 *   @0x2dd790 strb lr, [r4, #0xf8]
 *   @0x2dd794 add lr, r4, #236
 *   @0x2dd798 stm r12, {r0, r1}
 *   @0x2dd79c ldm r9, {r0, r1}
 *   @0x2dd7a0 stm r2, {r0, r1}
 *   @0x2dd7a4 ldm r3, {r0, r1}
 *   @0x2dd7a8 mov r3, lr
 *   @0x2dd7ac stm lr, {r0, r1}
 *   @0x2dd7b0 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2dd7b4 cmp r11, #0
 *   @0x2dd7b8 vcmpe.f32 s19, #0
 *   @0x2dd7bc bne 0x2dd818 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4b8>
 *   @0x2dd7c0 vmrs APSR_nzcv, fpscr
 *   @0x2dd7c4 blt 0x2ddbdc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x87c>
 *   @0x2dd7c8 vcmpe.f32 s18, #0
 *   @0x2dd7cc vmrs APSR_nzcv, fpscr
 *   @0x2dd7d0 blt 0x2ddbdc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x87c>
 *   @0x2dd7d4 add r3, r4, #196
 *   @0x2dd7d8 mov r1, #1
 *   @0x2dd7dc strb r1, [r4, #0xf8]
 *   @0x2dd7e0 add r2, r4, #212
 *   @0x2dd7e4 ldm r3, {r0, r1}
 *   @0x2dd7e8 add r12, r4, #228
 *   @0x2dd7ec stm r2, {r0, r1}
 *   @0x2dd7f0 ldm r3, {r0, r1}
 *   @0x2dd7f4 mov r3, r12
 *   @0x2dd7f8 stm r3, {r0, r1}
 *   @0x2dd7fc vldr s14, [r4, #200]
 *   @0x2dd800 vldr s15, [r4, #196]
 *   @0x2dd804 vneg.f32 s14, s14
 *   @0x2dd808 vneg.f32 s15, s15
 *   @0x2dd80c vstr s14, [r4, #240]
 *   @0x2dd810 vstr s15, [r4, #236]
 *   @0x2dd814 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2dd818 vmrs APSR_nzcv, fpscr
 *   @0x2dd81c blt 0x2ddd1c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x9bc>
 *   @0x2dd820 add r3, r4, #196
 *   @0x2dd824 add r2, r4, #212
 *   @0x2dd828 add r12, r4, #188
 *   @0x2dd82c mov lr, #1
 *   @0x2dd830 ldm r3, {r0, r1}
 *   @0x2dd834 add r3, r4, #228
 *   @0x2dd838 strb lr, [r4, #0xf8]
 *   @0x2dd83c stm r2, {r0, r1}
 *   @0x2dd840 mov r2, r12
 *   @0x2dd844 ldm r12, {r0, r1}
 *   @0x2dd848 b 0x2dd7f8 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x498>
 *   @0x2dd84c strlo r0, [r0], #-0
 *   @0x2dd850 andeq r0, r0, r0
 *   @0x2dd854 svclo #0x7ae148
 *   @0x2dd858 blo 0xfe3a221c <b2_toiTime+0xfffffffffdc48d78>
 *   @0x2dd85c cmp r3, #0
 *   @0x2dd860 beq 0x2ddb44 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7e4>
 *   @0x2dd864 vcmpe.f32 s11, #0
 *   @0x2dd868 vmrs APSR_nzcv, fpscr
 *   @0x2dd86c blt 0x2ddc70 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x910>
 *   @0x2dd870 add r3, r4, #196
 *   @0x2dd874 add r12, r4, #212
 *   @0x2dd878 mov r2, #1
 *   @0x2dd87c strb r2, [r4, #0xf8]
 *   @0x2dd880 ldm r3, {r0, r1}
 *   @0x2dd884 add r2, r4, #228
 *   @0x2dd888 add r9, r4, #204
 *   @0x2dd88c add lr, r4, #236
 *   @0x2dd890 stm r12, {r0, r1}
 *   @0x2dd894 ldm r3, {r0, r1}
 *   @0x2dd898 mov r3, lr
 *   @0x2dd89c stm r2, {r0, r1}
 *   @0x2dd8a0 mov r2, r9
 *   @0x2dd8a4 ldm r9, {r0, r1}
 *   @0x2dd8a8 stm lr, {r0, r1}
 *   @0x2dd8ac b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2dd8b0 vcmpe.f32 s18, #0
 *   @0x2dd8b4 vmrs APSR_nzcv, fpscr
 *   @0x2dd8b8 bge 0x2dd640 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x2e0>
 *   @0x2dd8bc vcmpe.f32 s11, #0
 *   @0x2dd8c0 vmrs APSR_nzcv, fpscr
 *   @0x2dd8c4 bge 0x2dd640 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x2e0>
 *   @0x2dd8c8 vldr s14, [r4, #196]
 *   @0x2dd8cc vldr s15, [r4, #200]
 *   @0x2dd8d0 vneg.f32 s14, s14
 *   @0x2dd8d4 mov r3, #0
 *   @0x2dd8d8 strb r3, [r4, #0xf8]
 *   @0x2dd8dc vneg.f32 s15, s15
 *   @0x2dd8e0 vstr s14, [r4, #212]
 *   @0x2dd8e4 vstr s14, [r4, #228]
 *   @0x2dd8e8 vstr s14, [r4, #236]
 *   @0x2dd8ec vstr s15, [r4, #216]
 *   @0x2dd8f0 vstr s15, [r4, #232]
 *   @0x2dd8f4 vstr s15, [r4, #240]
 *   @0x2dd8f8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2dd8fc add r0, sp, #20
 *   @0x2dd900 mov r1, r4
 *   @0x2dd904 bl 0x2dd224 <_ZN12b2EPCollider24ComputePolygonSeparationEv>
 *   @0x2dd908 ldr r3, [sp, #0x14]
 *   @0x2dd90c vldr s15, [sp, #28]
 *   @0x2dd910 cmp r3, #0
 *   @0x2dd914 beq 0x2dd944 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x5e4>
 *   @0x2dd918 vldr s14, [r4, #244]
 *   @0x2dd91c vcmpe.f32 s15, s14
 *   @0x2dd920 vmrs APSR_nzcv, fpscr
 *   @0x2dd924 bgt 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8>
 *   @0x2dd928 vldr s13, [pc, #-220]
 *   @0x2dd92c vldr s14, [pc, #-220]
 *   @0x2dd930 vmla.f32 s14, s16, s13
 *   @0x2dd934 vcmpe.f32 s15, s14
 *   @0x2dd938 vmrs APSR_nzcv, fpscr
 *   @0x2dd93c ldrgt r10, [sp, #0x18]
 *   @0x2dd940 movgt r9, r3
 *   @0x2dd944 cmp r9, #1
 *   @0x2dd948 beq 0x2ddd60 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa00>
 *   @0x2dd94c ldr r2, [r4, #0x80]
 *   @0x2dd950 add lr, r10, #1
 *   @0x2dd954 ldm r5, {r0, r1}
 *   @0x2dd958 add r3, sp, #32
 *   @0x2dd95c cmp lr, r2
 *   @0x2dd960 add r12, r4, r10, lsl #3
 *   @0x2dd964 add r11, sp, #112
 *   @0x2dd968 add r5, r10, #8
 *   @0x2dd96c stm r3, {r0, r1}
 *   @0x2dd970 movge lr, #0
 *   @0x2dd974 ldm r6, {r0, r1}
 *   @0x2dd978 add r2, r4, lr, lsl #3
 *   @0x2dd97c str lr, [sp, #0x6c]
 *   @0x2dd980 add lr, sp, #44
 *   @0x2dd984 add r5, r4, r5, lsl #3
 *   @0x2dd988 add r6, sp, #120
 *   @0x2dd98c stm lr, {r0, r1}
 *   @0x2dd990 mov lr, #2
 *   @0x2dd994 ldm r12, {r0, r1}
 *   @0x2dd998 mov r12, r10
 *   @0x2dd99c str r10, [sp, #0x68]
 *   @0x2dd9a0 uxtb r10, r10
 *   @0x2dd9a4 strb r10, [sp, #0x29]
 *   @0x2dd9a8 stm r11, {r0, r1}
 *   @0x2dd9ac ldm r2, {r0, r1}
 *   @0x2dd9b0 mov r2, #0
 *   @0x2dd9b4 str lr, [r7, #0x38]
 *   @0x2dd9b8 mov lr, #1
 *   @0x2dd9bc strb r10, [sp, #0x35]
 *   @0x2dd9c0 stm r6, {r0, r1}
 *   @0x2dd9c4 ldm r5, {r0, r1}
 *   @0x2dd9c8 add r5, sp, #128
 *   @0x2dd9cc strb r2, [sp, #0x28]
 *   @0x2dd9d0 strb r2, [sp, #0x2a]
 *   @0x2dd9d4 stm r5, {r0, r1}
 *   @0x2dd9d8 vldr s13, [sp, #132]
 *   @0x2dd9dc vldr s14, [sp, #128]
 *   @0x2dd9e0 strb r2, [sp, #0x34]
 *   @0x2dd9e4 strb r2, [sp, #0x36]
 *   @0x2dd9e8 strb lr, [sp, #0x2b]
 *   @0x2dd9ec strb lr, [sp, #0x37]
 *   @0x2dd9f0 vneg.f32 s12, s14
 *   @0x2dd9f4 vldr s15, [sp, #116]
 *   @0x2dd9f8 vldr s9, [sp, #124]
 *   @0x2dd9fc vstr s14, [sp, #152]
 *   @0x2dda00 vldr s10, [sp, #112]
 *   @0x2dda04 vldr s11, [sp, #120]
 *   @0x2dda08 add r5, sp, #56
 *   @0x2dda0c mov r1, r3
 *   @0x2dda10 vmul.f32 s15, s12, s15
 *   @0x2dda14 vstr s12, [sp, #140]
 *   @0x2dda18 mov r0, r5
 *   @0x2dda1c str r12, [sp]
 *   @0x2dda20 add r2, sp, #136
 *   @0x2dda24 vstr s13, [sp, #136]
 *   @0x2dda28 vmul.f32 s14, s14, s9
 *   @0x2dda2c vneg.f32 s12, s13
 *   @0x2dda30 vmla.f32 s15, s13, s10
 *   @0x2dda34 vstr s12, [sp, #148]
 *   @0x2dda38 vmla.f32 s14, s12, s11
 *   @0x2dda3c vstr s15, [sp, #144]
 *   @0x2dda40 vmov r3, s15
 *   @0x2dda44 vstr s14, [sp, #156]
 *   @0x2dda48 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi>
 *   @0x2dda4c cmp r0, #1
 *   @0x2dda50 ble 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8>
 *   @0x2dda54 ldr r12, [sp, #0x6c]
 *   @0x2dda58 add r6, sp, #80
 *   @0x2dda5c ldr r3, [sp, #0x9c]
 *   @0x2dda60 mov r1, r5
 *   @0x2dda64 mov r0, r6
 *   @0x2dda68 add r2, sp, #148
 *   @0x2dda6c str r12, [sp]
 *   @0x2dda70 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi>
 *   @0x2dda74 cmp r0, #1
 *   @0x2dda78 ble 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8>
 *   @0x2dda7c cmp r9, #1
 *   @0x2dda80 beq 0x2ddefc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb9c>
 *   @0x2dda84 ldr r2, [sp, #0x68]
 *   @0x2dda88 add r12, r7, #40
 *   @0x2dda8c add r3, r7, #48
 *   @0x2dda90 add r1, r8, r2, lsl #3
 *   @0x2dda94 mov r2, r1
 *   @0x2dda98 add r1, r1, #84
 *   @0x2dda9c add r2, r2, #20
 *   @0x2ddaa0 ldm r1, {r0, r1}
 *   @0x2ddaa4 stm r12, {r0, r1}
 *   @0x2ddaa8 ldm r2, {r0, r1}
 *   @0x2ddaac stm r3, {r0, r1}
 *   @0x2ddab0 add r5, sp, #104
 *   @0x2ddab4 mov r3, r6
 *   @0x2ddab8 mov r2, #0
 *   @0x2ddabc vldr s7, [sp, #112]
 *   @0x2ddac0 vldr s8, [sp, #116]
 *   @0x2ddac4 vldr s9, [sp, #128]
 *   @0x2ddac8 vldr s10, [sp, #132]
 *   @0x2ddacc vldr s13, [r3, #4]
 *   @0x2ddad0 vsub.f32 s15, s13, s8
 *   @0x2ddad4 vldr s14, [r3]
 *   @0x2ddad8 vldr s12, [r4, #244]
 *   @0x2ddadc add r12, r2, r2, lsl #2
 *   @0x2ddae0 add r12, r7, r12, lsl #2
 *   @0x2ddae4 vmul.f32 s15, s15, s10
 *   @0x2ddae8 vsub.f32 s11, s14, s7
 *   @0x2ddaec vmla.f32 s15, s11, s9
 *   @0x2ddaf0 vcmpe.f32 s12, s15
 *   @0x2ddaf4 vmrs APSR_nzcv, fpscr
 *   @0x2ddaf8 blt 0x2ddb30 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7d0>
 *   @0x2ddafc cmp r9, #1
 *   @0x2ddb00 beq 0x2ddec0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb60>
 *   @0x2ddb04 ldm r3, {r0, r1}
 *   @0x2ddb08 ldrb r11, [r3, #0xb]
 *   @0x2ddb0c ldrb r10, [r3, #0xa]
 *   @0x2ddb10 ldrb r8, [r3, #0x9]
 *   @0x2ddb14 ldrb r6, [r3, #0x8]
 *   @0x2ddb18 stm r12, {r0, r1}
 *   @0x2ddb1c strb r11, [r12, #0x12]
 *   @0x2ddb20 strb r10, [r12, #0x13]
 *   @0x2ddb24 strb r8, [r12, #0x10]
 *   @0x2ddb28 strb r6, [r12, #0x11]
 *   @0x2ddb2c add r2, r2, #1
 *   @0x2ddb30 add r3, r3, #12
 *   @0x2ddb34 cmp r3, r5
 *   @0x2ddb38 bne 0x2ddacc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x76c>
 *   @0x2ddb3c str r2, [r7, #0x3c]
 *   @0x2ddb40 b 0x2dd758 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x3f8>
 *   @0x2ddb44 vcmpe.f32 s19, #0
 *   @0x2ddb48 vmrs APSR_nzcv, fpscr
 *   @0x2ddb4c blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8>
 *   @0x2ddb50 vcmpe.f32 s18, #0
 *   @0x2ddb54 vmrs APSR_nzcv, fpscr
 *   @0x2ddb58 blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8>
 *   @0x2ddb5c vcmpe.f32 s11, #0
 *   @0x2ddb60 vmrs APSR_nzcv, fpscr
 *   @0x2ddb64 blt 0x2ddc28 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x8c8>
 *   @0x2ddb68 add r3, r4, #196
 *   @0x2ddb6c add r12, r4, #212
 *   @0x2ddb70 mov r2, #1
 *   @0x2ddb74 strb r2, [r4, #0xf8]
 *   @0x2ddb78 ldm r3, {r0, r1}
 *   @0x2ddb7c add r2, r4, #228
 *   @0x2ddb80 add lr, r4, #236
 *   @0x2ddb84 stm r12, {r0, r1}
 *   @0x2ddb88 ldm r3, {r0, r1}
 *   @0x2ddb8c stm r2, {r0, r1}
 *   @0x2ddb90 ldm r3, {r0, r1}
 *   @0x2ddb94 mov r3, lr
 *   @0x2ddb98 stm lr, {r0, r1}
 *   @0x2ddb9c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddba0 vldr s14, [r4, #200]
 *   @0x2ddba4 vldr s15, [r4, #196]
 *   @0x2ddba8 vneg.f32 s14, s14
 *   @0x2ddbac add r3, r4, #196
 *   @0x2ddbb0 add r2, r4, #228
 *   @0x2ddbb4 add r12, r4, #236
 *   @0x2ddbb8 vneg.f32 s15, s15
 *   @0x2ddbbc vstr s14, [r4, #216]
 *   @0x2ddbc0 vstr s15, [r4, #212]
 *   @0x2ddbc4 ldm r3, {r0, r1}
 *   @0x2ddbc8 stm r2, {r0, r1}
 *   @0x2ddbcc ldm r3, {r0, r1}
 *   @0x2ddbd0 mov r3, r12
 *   @0x2ddbd4 stm r12, {r0, r1}
 *   @0x2ddbd8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddbdc vldr s14, [r4, #200]
 *   @0x2ddbe0 vldr s15, [r4, #196]
 *   @0x2ddbe4 vneg.f32 s14, s14
 *   @0x2ddbe8 add r2, r4, #196
 *   @0x2ddbec mov r1, #0
 *   @0x2ddbf0 strb r1, [r4, #0xf8]
 *   @0x2ddbf4 add r3, r4, #228
 *   @0x2ddbf8 vneg.f32 s15, s15
 *   @0x2ddbfc vstr s14, [r4, #216]
 *   @0x2ddc00 vstr s15, [r4, #212]
 *   @0x2ddc04 ldm r2, {r0, r1}
 *   @0x2ddc08 stm r3, {r0, r1}
 *   @0x2ddc0c vldr s14, [r4, #192]
 *   @0x2ddc10 vldr s15, [r4, #188]
 *   @0x2ddc14 vneg.f32 s14, s14
 *   @0x2ddc18 vneg.f32 s15, s15
 *   @0x2ddc1c vstr s14, [r4, #240]
 *   @0x2ddc20 vstr s15, [r4, #236]
 *   @0x2ddc24 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddc28 vneg.f32 s20, s20
 *   @0x2ddc2c vldr s12, [r4, #200]
 *   @0x2ddc30 vldr s13, [r4, #196]
 *   @0x2ddc34 vldr s14, [r4, #192]
 *   @0x2ddc38 vldr s15, [r4, #188]
 *   @0x2ddc3c mov r3, #0
 *   @0x2ddc40 vstr s21, [r4, #232]
 *   @0x2ddc44 strb r3, [r4, #0xf8]
 *   @0x2ddc48 vneg.f32 s12, s12
 *   @0x2ddc4c vstr s20, [r4, #228]
 *   @0x2ddc50 vneg.f32 s13, s13
 *   @0x2ddc54 vstr s12, [r4, #216]
 *   @0x2ddc58 vneg.f32 s14, s14
 *   @0x2ddc5c vstr s13, [r4, #212]
 *   @0x2ddc60 vneg.f32 s15, s15
 *   @0x2ddc64 vstr s14, [r4, #240]
 *   @0x2ddc68 vstr s15, [r4, #236]
 *   @0x2ddc6c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddc70 vcmpe.f32 s19, #0
 *   @0x2ddc74 vmrs APSR_nzcv, fpscr
 *   @0x2ddc78 blt 0x2ddc88 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x928>
 *   @0x2ddc7c vcmpe.f32 s18, #0
 *   @0x2ddc80 vmrs APSR_nzcv, fpscr
 *   @0x2ddc84 bge 0x2dd870 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x510>
 *   @0x2ddc88 vldr s14, [r4, #196]
 *   @0x2ddc8c vldr s15, [r4, #200]
 *   @0x2ddc90 vneg.f32 s14, s14
 *   @0x2ddc94 vldr s12, [r4, #192]
 *   @0x2ddc98 vldr s13, [r4, #188]
 *   @0x2ddc9c mov r3, #0
 *   @0x2ddca0 strb r3, [r4, #0xf8]
 *   @0x2ddca4 vneg.f32 s15, s15
 *   @0x2ddca8 vstr s14, [r4, #212]
 *   @0x2ddcac vstr s14, [r4, #228]
 *   @0x2ddcb0 vstr s15, [r4, #216]
 *   @0x2ddcb4 vneg.f32 s14, s12
 *   @0x2ddcb8 vstr s15, [r4, #232]
 *   @0x2ddcbc vneg.f32 s15, s13
 *   @0x2ddcc0 vstr s14, [r4, #240]
 *   @0x2ddcc4 vstr s15, [r4, #236]
 *   @0x2ddcc8 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddccc vcmpe.f32 s18, #0
 *   @0x2ddcd0 vmrs APSR_nzcv, fpscr
 *   @0x2ddcd4 blt 0x2ddce4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x984>
 *   @0x2ddcd8 vcmpe.f32 s11, #0
 *   @0x2ddcdc vmrs APSR_nzcv, fpscr
 *   @0x2ddce0 bge 0x2dd778 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x418>
 *   @0x2ddce4 vneg.f32 s20, s20
 *   @0x2ddce8 vldr s14, [r4, #196]
 *   @0x2ddcec vldr s15, [r4, #200]
 *   @0x2ddcf0 mov r3, #0
 *   @0x2ddcf4 vstr s21, [r4, #232]
 *   @0x2ddcf8 strb r3, [r4, #0xf8]
 *   @0x2ddcfc vneg.f32 s14, s14
 *   @0x2ddd00 vstr s20, [r4, #228]
 *   @0x2ddd04 vneg.f32 s15, s15
 *   @0x2ddd08 vstr s14, [r4, #212]
 *   @0x2ddd0c vstr s14, [r4, #236]
 *   @0x2ddd10 vstr s15, [r4, #216]
 *   @0x2ddd14 vstr s15, [r4, #240]
 *   @0x2ddd18 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddd1c vcmpe.f32 s18, #0
 *   @0x2ddd20 vmrs APSR_nzcv, fpscr
 *   @0x2ddd24 bge 0x2dd820 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x4c0>
 *   @0x2ddd28 vldr s14, [r4, #196]
 *   @0x2ddd2c vldr s15, [r4, #200]
 *   @0x2ddd30 vneg.f32 s14, s14
 *   @0x2ddd34 add r2, r4, #196
 *   @0x2ddd38 add r3, r4, #228
 *   @0x2ddd3c strb r10, [r4, #0xf8]
 *   @0x2ddd40 vneg.f32 s15, s15
 *   @0x2ddd44 vstr s14, [r4, #212]
 *   @0x2ddd48 vstr s15, [r4, #216]
 *   @0x2ddd4c ldm r2, {r0, r1}
 *   @0x2ddd50 stm r3, {r0, r1}
 *   @0x2ddd54 vstr s14, [r4, #236]
 *   @0x2ddd58 vstr s15, [r4, #240]
 *   @0x2ddd5c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddd60 vldr s11, [r4, #216]
 *   @0x2ddd64 vldr s13, [r4, #68]
 *   @0x2ddd68 vmul.f32 s13, s11, s13
 *   @0x2ddd6c ldr r1, [r4, #0x80]
 *   @0x2ddd70 vldr s12, [r4, #212]
 *   @0x2ddd74 vldr s15, [r4, #64]
 *   @0x2ddd78 cmp r1, #1
 *   @0x2ddd7c str r9, [r7, #0x38]
 *   @0x2ddd80 vmla.f32 s13, s12, s15
 *   @0x2ddd84 ble 0x2dde6c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb0c>
 *   @0x2ddd88 add r3, r4, #72
 *   @0x2ddd8c mov r2, r9
 *   @0x2ddd90 mov r0, #0
 *   @0x2ddd94 vldr s15, [r3, #4]
 *   @0x2ddd98 vldr s14, [r3]
 *   @0x2ddd9c add r3, r3, #8
 *   @0x2ddda0 vmul.f32 s15, s11, s15
 *   @0x2ddda4 vmla.f32 s15, s12, s14
 *   @0x2ddda8 vcmpe.f32 s15, s13
 *   @0x2dddac vmrs APSR_nzcv, fpscr
 *   @0x2dddb0 movmi r0, r2
 *   @0x2dddb4 add r2, r2, #1
 *   @0x2dddb8 vmovmi.f32 s13, s15
 *   @0x2dddbc cmp r2, r1
 *   @0x2dddc0 bne 0x2ddd94 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa34>
 *   @0x2dddc4 add r11, r0, #1
 *   @0x2dddc8 cmp r11, r2
 *   @0x2dddcc uxtblt r2, r11
 *   @0x2dddd0 uxtblt r10, r0
 *   @0x2dddd4 uxtbge r10, r0
 *   @0x2dddd8 bge 0x2dde74 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb14>
 *   @0x2ddddc add r0, r4, r0, lsl #3
 *   @0x2ddde0 add r11, r4, r11, lsl #3
 *   @0x2ddde4 add r3, sp, #32
 *   @0x2ddde8 ldrb lr, [r4, #0xf8]
 *   @0x2dddec ldm r0, {r0, r1}
 *   @0x2dddf0 mov r12, #0
 *   @0x2dddf4 cmp lr, #0
 *   @0x2dddf8 strb r2, [sp, #0x35]
 *   @0x2dddfc strb r12, [sp, #0x34]
 *   @0x2dde00 mov r2, #1
 *   @0x2dde04 stm r3, {r0, r1}
 *   @0x2dde08 ldm r11, {r0, r1}
 *   @0x2dde0c strb r10, [sp, #0x29]
 *   @0x2dde10 add r10, sp, #44
 *   @0x2dde14 strb r12, [sp, #0x28]
 *   @0x2dde18 stm r10, {r0, r1}
 *   @0x2dde1c strb r12, [sp, #0x2b]
 *   @0x2dde20 strb r12, [sp, #0x37]
 *   @0x2dde24 strb r2, [sp, #0x2a]
 *   @0x2dde28 strb r2, [sp, #0x36]
 *   @0x2dde2c beq 0x2dde80 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xb20>
 *   @0x2dde30 ldm r5, {r0, r1}
 *   @0x2dde34 add r11, sp, #112
 *   @0x2dde38 add lr, r4, #196
 *   @0x2dde3c str r2, [sp, #0x6c]
 *   @0x2dde40 add r2, sp, #120
 *   @0x2dde44 str r12, [sp, #0x68]
 *   @0x2dde48 stm r11, {r0, r1}
 *   @0x2dde4c ldm r6, {r0, r1}
 *   @0x2dde50 stm r2, {r0, r1}
 *   @0x2dde54 add r2, sp, #128
 *   @0x2dde58 ldm lr, {r0, r1}
 *   @0x2dde5c stm r2, {r0, r1}
 *   @0x2dde60 vldr s13, [sp, #132]
 *   @0x2dde64 vldr s14, [sp, #128]
 *   @0x2dde68 b 0x2dd9f0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x690>
 *   @0x2dde6c mov r10, #0
 *   @0x2dde70 mov r0, r10
 *   @0x2dde74 mov r2, #0
 *   @0x2dde78 mov r11, r2
 *   @0x2dde7c b 0x2ddddc <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xa7c>
 *   @0x2dde80 ldm r6, {r0, r1}
 *   @0x2dde84 add r11, sp, #112
 *   @0x2dde88 vldr s14, [r4, #196]
 *   @0x2dde8c vldr s13, [r4, #200]
 *   @0x2dde90 vneg.f32 s14, s14
 *   @0x2dde94 mov r12, r2
 *   @0x2dde98 stm r11, {r0, r1}
 *   @0x2dde9c ldm r5, {r0, r1}
 *   @0x2ddea0 str r2, [sp, #0x68]
 *   @0x2ddea4 add r2, sp, #120
 *   @0x2ddea8 vneg.f32 s13, s13
 *   @0x2ddeac vstr s14, [sp, #128]
 *   @0x2ddeb0 str lr, [sp, #0x6c]
 *   @0x2ddeb4 stm r2, {r0, r1}
 *   @0x2ddeb8 vstr s13, [sp, #132]
 *   @0x2ddebc b 0x2dd9f0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x690>
 *   @0x2ddec0 vldr s15, [r4, #136]
 *   @0x2ddec4 vsub.f32 s13, s13, s15
 *   @0x2ddec8 vldr s11, [r4, #140]
 *   @0x2ddecc vldr s12, [r4, #144]
 *   @0x2dded0 vldr s6, [r4, #132]
 *   @0x2dded4 ldr r1, [r3, #0x8]
 *   @0x2dded8 str r1, [r12, #0x10]
 *   @0x2ddedc vmul.f32 s15, s13, s11
 *   @0x2ddee0 vmul.f32 s13, s13, s12
 *   @0x2ddee4 vsub.f32 s14, s14, s6
 *   @0x2ddee8 vmls.f32 s13, s11, s14
 *   @0x2ddeec vmla.f32 s15, s14, s12
 *   @0x2ddef0 vstr s13, [r12, #4]
 *   @0x2ddef4 vstr s15, [r12]
 *   @0x2ddef8 b 0x2ddb2c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x7cc>
 *   @0x2ddefc add r1, sp, #128
 *   @0x2ddf00 add r2, r7, #40
 *   @0x2ddf04 add r3, r7, #48
 *   @0x2ddf08 ldm r1, {r0, r1}
 *   @0x2ddf0c stm r2, {r0, r1}
 *   @0x2ddf10 ldm r11, {r0, r1}
 *   @0x2ddf14 stm r3, {r0, r1}
 *   @0x2ddf18 b 0x2ddab0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x750>
 *   @0x2ddf1c vmov r0, s12
 *   @0x2ddf20 bl 0xb6700 <sqrtf@plt>
 *   @0x2ddf24 vldr s14, [r4, #148]
 *   @0x2ddf28 vldr s11, [r4, #152]
 *   @0x2ddf2c vldr s10, [r4, #156]
 *   @0x2ddf30 vldr s19, [r4, #160]
 *   @0x2ddf34 vmov s15, r0
 *   @0x2ddf38 b 0x2dd54c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x1ec>
 *   @0x2ddf3c cmp r3, #0
 *   @0x2ddf40 beq 0x2ddf98 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc38>
 *   @0x2ddf44 vcmpe.f32 s18, #0
 *   @0x2ddf48 vmrs APSR_nzcv, fpscr
 *   @0x2ddf4c blt 0x2de040 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xce0>
 *   @0x2ddf50 add r3, r4, #196
 *   @0x2ddf54 mov r1, #1
 *   @0x2ddf58 strb r1, [r4, #0xf8]
 *   @0x2ddf5c add r2, r4, #212
 *   @0x2ddf60 ldm r3, {r0, r1}
 *   @0x2ddf64 add r12, r4, #204
 *   @0x2ddf68 add r3, r4, #236
 *   @0x2ddf6c stm r2, {r0, r1}
 *   @0x2ddf70 vldr s14, [r4, #200]
 *   @0x2ddf74 vldr s15, [r4, #196]
 *   @0x2ddf78 vneg.f32 s14, s14
 *   @0x2ddf7c mov r2, r12
 *   @0x2ddf80 vneg.f32 s15, s15
 *   @0x2ddf84 vstr s14, [r4, #232]
 *   @0x2ddf88 vstr s15, [r4, #228]
 *   @0x2ddf8c ldm r12, {r0, r1}
 *   @0x2ddf90 stm r3, {r0, r1}
 *   @0x2ddf94 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddf98 vcmpe.f32 s18, #0
 *   @0x2ddf9c vmrs APSR_nzcv, fpscr
 *   @0x2ddfa0 blt 0x2ddff4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc94>
 *   @0x2ddfa4 vcmpe.f32 s11, #0
 *   @0x2ddfa8 vmrs APSR_nzcv, fpscr
 *   @0x2ddfac blt 0x2ddff4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xc94>
 *   @0x2ddfb0 add r3, r4, #196
 *   @0x2ddfb4 mov r1, #1
 *   @0x2ddfb8 strb r1, [r4, #0xf8]
 *   @0x2ddfbc add r2, r4, #212
 *   @0x2ddfc0 ldm r3, {r0, r1}
 *   @0x2ddfc4 add r12, r4, #236
 *   @0x2ddfc8 stm r2, {r0, r1}
 *   @0x2ddfcc vldr s14, [r4, #200]
 *   @0x2ddfd0 vldr s15, [r4, #196]
 *   @0x2ddfd4 vneg.f32 s14, s14
 *   @0x2ddfd8 vneg.f32 s15, s15
 *   @0x2ddfdc vstr s14, [r4, #232]
 *   @0x2ddfe0 vstr s15, [r4, #228]
 *   @0x2ddfe4 ldm r3, {r0, r1}
 *   @0x2ddfe8 mov r3, r12
 *   @0x2ddfec stm r12, {r0, r1}
 *   @0x2ddff0 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2ddff4 vldr s12, [r4, #200]
 *   @0x2ddff8 vldr s13, [r4, #196]
 *   @0x2ddffc vldr s14, [r4, #208]
 *   @0x2de000 vldr s15, [r4, #204]
 *   @0x2de004 vneg.f32 s12, s12
 *   @0x2de008 add r2, r4, #196
 *   @0x2de00c mov r1, #0
 *   @0x2de010 strb r1, [r4, #0xf8]
 *   @0x2de014 add r3, r4, #236
 *   @0x2de018 vneg.f32 s13, s13
 *   @0x2de01c vstr s12, [r4, #216]
 *   @0x2de020 vneg.f32 s14, s14
 *   @0x2de024 vstr s13, [r4, #212]
 *   @0x2de028 vneg.f32 s15, s15
 *   @0x2de02c vstr s14, [r4, #232]
 *   @0x2de030 vstr s15, [r4, #228]
 *   @0x2de034 ldm r2, {r0, r1}
 *   @0x2de038 stm r3, {r0, r1}
 *   @0x2de03c b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2de040 vcmpe.f32 s11, #0
 *   @0x2de044 vmrs APSR_nzcv, fpscr
 *   @0x2de048 bge 0x2ddf50 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0xbf0>
 *   @0x2de04c vldr s14, [r4, #196]
 *   @0x2de050 vldr s15, [r4, #200]
 *   @0x2de054 vneg.f32 s14, s14
 *   @0x2de058 add r2, r4, #196
 *   @0x2de05c add r3, r4, #236
 *   @0x2de060 strb r9, [r4, #0xf8]
 *   @0x2de064 vneg.f32 s15, s15
 *   @0x2de068 vstr s14, [r4, #212]
 *   @0x2de06c vstr s14, [r4, #228]
 *   @0x2de070 vstr s15, [r4, #216]
 *   @0x2de074 vstr s15, [r4, #232]
 *   @0x2de078 ldm r2, {r0, r1}
 *   @0x2de07c stm r3, {r0, r1}
 *   @0x2de080 b 0x2dd67c <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x31c>
 *   @0x2de084 vmov r0, s13
 *   @0x2de088 bl 0xb6700 <sqrtf@plt>
 *   @0x2de08c vldr s12, [r4, #172]
 *   @0x2de090 vldr s10, [r4, #176]
 *   @0x2de094 vldr s14, [r4, #148]
 *   @0x2de098 vldr s11, [r4, #152]
 *   @0x2de09c vmov s15, r0
 *   @0x2de0a0 b 0x2dd5d4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x274>
 *   @0x2de0a4 vmov r0, s14
 *   @0x2de0a8 bl 0xb6700 <sqrtf@plt>
 *   @0x2de0ac vldr s13, [r4, #164]
 *   @0x2de0b0 vldr s12, [r4, #168]
 *   @0x2de0b4 vmov s15, r0
 *   @0x2de0b8 b 0x2dd474 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x114>
 *
 * ══ §3/13 CGesturePinch::Update(long long)  0x1d9c9c  size 3232  808 条（0x1d9c9c..0x1da93c）
 * @func 0x1d9c9c 0x1da93c  size 3232  808 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertRawPos(float, float, int, float&, float&, float&, float&)×6 / ConvertGestureEventToGMEvent(int, bool)×4 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)×4 / operator new(unsigned int)×4 / GetTouchActionFromUID(int)×2 / CalcDistInches(int, int)×2 / CreateDsMap(int, ...)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2
 * 字段偏移 top8: 0x8×24 / 0x4×20 / 0xc×10 / 0x30×8 / 0x34×8 / 0x40×8 / 0x170×7 / 0x174×7
 * VFP 指令 198 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d9c9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d9ca0 vpush {d8, d9}
 *   @0x1d9ca4 mov r4, r0
 *   @0x1d9ca8 sub sp, sp, #436
 *   @0x1d9cac ldr r0, [r0, #0x28]
 *   @0x1d9cb0 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d9cb4 mov r7, r0
 *   @0x1d9cb8 ldr r0, [r4, #0x2c]
 *   @0x1d9cbc bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1d9cc0 cmp r7, #0
 *   @0x1d9cc4 mov r6, r0
 *   @0x1d9cc8 beq 0x1da778 <_ZN13CGesturePinch6UpdateEx+0xadc>
 *   @0x1d9ccc ldr r12, [r7, #0x828]
 *   @0x1d9cd0 ldr r3, [r7, #0x82c]
 *   @0x1d9cd4 ldr r1, [r7]
 *   @0x1d9cd8 cmp r12, r3
 *   @0x1d9cdc ldrb r8, [r7, #0x830]
 *   @0x1d9ce0 addne r12, r12, #63
 *   @0x1d9ce4 andne r12, r12, #63
 *   @0x1d9ce8 moveq r12, #0
 *   @0x1d9cec moveq r11, r12
 *   @0x1d9cf0 moveq r10, r12
 *   @0x1d9cf4 addne r12, r7, r12, lsl #5
 *   @0x1d9cf8 str r1, [sp, #0x178]
 *   @0x1d9cfc addne r12, r12, #40
 *   @0x1d9d00 ldrne r10, [r12, #0x8]
 *   @0x1d9d04 ldrne r11, [r12, #0xc]
 *   @0x1d9d08 cmp r6, #0
 *   @0x1d9d0c beq 0x1da798 <_ZN13CGesturePinch6UpdateEx+0xafc>
 *   @0x1d9d10 ldr r9, [r6, #0x828]
 *   @0x1d9d14 ldr r3, [r6, #0x82c]
 *   @0x1d9d18 cmp r9, r3
 *   @0x1d9d1c beq 0x1d9d74 <_ZN13CGesturePinch6UpdateEx+0xd8>
 *   @0x1d9d20 add r9, r9, #63
 *   @0x1d9d24 and r9, r9, #63
 *   @0x1d9d28 add r9, r6, r9, lsl #5
 *   @0x1d9d2c add r9, r9, #40
 *   @0x1d9d30 ldr r3, [r9, #0x8]
 *   @0x1d9d34 ldr r1, [r9, #0xc]
 *   @0x1d9d38 str r3, [sp, #0x170]
 *   @0x1d9d3c str r1, [sp, #0x174]
 *   @0x1d9d40 ldrb r3, [r6, #0x830]
 *   @0x1d9d44 ldr r2, [r6]
 *   @0x1d9d48 cmp r3, #0
 *   @0x1d9d4c movne r8, #1
 *   @0x1d9d50 str r2, [sp, #0x17c]
 *   @0x1d9d54 ldr r5, [r4, #0x14]
 *   @0x1d9d58 cmp r5, #0
 *   @0x1d9d5c beq 0x1d9d84 <_ZN13CGesturePinch6UpdateEx+0xe8>
 *   @0x1d9d60 cmp r5, #1
 *   @0x1d9d64 beq 0x1da278 <_ZN13CGesturePinch6UpdateEx+0x5dc>
 *   @0x1d9d68 add sp, sp, #436
 *   @0x1d9d6c vpop {d8, d9}
 *   @0x1d9d70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d9d74 mov r9, #0
 *   @0x1d9d78 str r9, [sp, #0x174]
 *   @0x1d9d7c str r9, [sp, #0x170]
 *   @0x1d9d80 b 0x1d9d40 <_ZN13CGesturePinch6UpdateEx+0xa4>
 *   @0x1d9d84 ldr r1, [sp, #0x170]
 *   @0x1d9d88 vmov.f32 s15, #5.000000e-01
 *   @0x1d9d8c ldr r2, [sp, #0x174]
 *   @0x1d9d90 mov r0, #7
 *   @0x1d9d94 add r1, r10, r1
 *   @0x1d9d98 add r8, r4, #12
 *   @0x1d9d9c add r2, r11, r2
 *   @0x1d9da0 add r7, r4, #16
 *   @0x1d9da4 vmov s14, r1
 *   @0x1d9da8 mov r1, r5
 *   @0x1d9dac vmov s13, r2
 *   @0x1d9db0 mov r6, #1
 *   @0x1d9db4 ldr r9, [pc, #0xab8]
 *   @0x1d9db8 vcvt.f32.s32 s13, s13
 *   @0x1d9dbc vcvt.f32.s32 s14, s14
 *   @0x1d9dc0 vmul.f32 s14, s14, s15
 *   @0x1d9dc4 vmul.f32 s15, s13, s15
 *   @0x1d9dc8 vstr s14, [r4, #48]
 *   @0x1d9dcc vstr s15, [r4, #52]
 *   @0x1d9dd0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d9dd4 str r8, [sp]
 *   @0x1d9dd8 str r5, [sp, #0x8]
 *   @0x1d9ddc ldr r2, [r4, #0x30]
 *   @0x1d9de0 str r7, [sp, #0x4]
 *   @0x1d9de4 ldr r3, [r4, #0x34]
 *   @0x1d9de8 mov r1, r0
 *   @0x1d9dec mov r0, #13
 *   @0x1d9df0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9df4 mov r1, r5
 *   @0x1d9df8 mov r0, #8
 *   @0x1d9dfc bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d9e00 str r8, [sp]
 *   @0x1d9e04 str r7, [sp, #0x4]
 *   @0x1d9e08 ldr r2, [r4, #0x30]
 *   @0x1d9e0c ldr r3, [r4, #0x34]
 *   @0x1d9e10 str r6, [sp, #0x8]
 *   @0x1d9e14 mov r1, r0
 *   @0x1d9e18 mov r0, #13
 *   @0x1d9e1c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9e20 mov r1, r5
 *   @0x1d9e24 mov r0, #6
 *   @0x1d9e28 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d9e2c str r8, [sp]
 *   @0x1d9e30 str r7, [sp, #0x4]
 *   @0x1d9e34 ldr r2, [r4, #0x30]
 *   @0x1d9e38 str r6, [sp, #0x8]
 *   @0x1d9e3c ldr r3, [r4, #0x34]
 *   @0x1d9e40 mov r1, r0
 *   @0x1d9e44 mov r0, #13
 *   @0x1d9e48 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9e4c mov r1, r5
 *   @0x1d9e50 mov r0, #9
 *   @0x1d9e54 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d9e58 str r8, [sp]
 *   @0x1d9e5c str r7, [sp, #0x4]
 *   @0x1d9e60 ldr r2, [r4, #0x30]
 *   @0x1d9e64 str r6, [sp, #0x8]
 *   @0x1d9e68 ldr r3, [r4, #0x34]
 *   @0x1d9e6c ldr r8, [pc, #0xa04]
 *   @0x1d9e70 add r8, pc, r8
 *   @0x1d9e74 mov r1, r0
 *   @0x1d9e78 mov r0, #13
 *   @0x1d9e7c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9e80 ldr r3, [sp, #0x170]
 *   @0x1d9e84 ldr r2, [sp, #0x174]
 *   @0x1d9e88 rsb r0, r10, r3
 *   @0x1d9e8c rsb r1, r11, r2
 *   @0x1d9e90 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d9e94 vldr s15, [r4, #48]
 *   @0x1d9e98 vcvt.s32.f32 s15, s15
 *   @0x1d9e9c str r0, [r4, #0x38]
 *   @0x1d9ea0 str r0, [r4, #0x3c]
 *   @0x1d9ea4 vmov r0, s15
 *   @0x1d9ea8 vldr s15, [r4, #52]
 *   @0x1d9eac vcvt.s32.f32 s15, s15
 *   @0x1d9eb0 vmov r1, s15
 *   @0x1d9eb4 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii>
 *   @0x1d9eb8 vmov s9, r10
 *   @0x1d9ebc vmov s11, r11
 *   @0x1d9ec0 add r3, sp, #388
 *   @0x1d9ec4 vcvt.f32.s32 s9, s9
 *   @0x1d9ec8 add r1, sp, #404
 *   @0x1d9ecc vcvt.f32.s32 s11, s11
 *   @0x1d9ed0 str r0, [r4, #0x40]
 *   @0x1d9ed4 mov r2, r0
 *   @0x1d9ed8 str r3, [sp]
 *   @0x1d9edc add r3, sp, #400
 *   @0x1d9ee0 vmov r0, s9
 *   @0x1d9ee4 str r3, [sp, #0x4]
 *   @0x1d9ee8 add r3, sp, #384
 *   @0x1d9eec str r1, [sp, #0x8]
 *   @0x1d9ef0 vmov r1, s11
 *   @0x1d9ef4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d9ef8 vldr s13, [sp, #368]
 *   @0x1d9efc vldr s14, [sp, #372]
 *   @0x1d9f00 vcvt.f32.s32 s13, s13
 *   @0x1d9f04 ldr r2, [r4, #0x40]
 *   @0x1d9f08 add r3, sp, #396
 *   @0x1d9f0c str r3, [sp]
 *   @0x1d9f10 add r3, sp, #408
 *   @0x1d9f14 str r3, [sp, #0x4]
 *   @0x1d9f18 add r3, sp, #412
 *   @0x1d9f1c str r3, [sp, #0x8]
 *   @0x1d9f20 add r3, sp, #392
 *   @0x1d9f24 vcvt.f32.s32 s14, s14
 *   @0x1d9f28 vmov r0, s13
 *   @0x1d9f2c vmov r1, s14
 *   @0x1d9f30 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d9f34 ldr r2, [r4, #0x40]
 *   @0x1d9f38 ldr r1, [r4, #0x34]
 *   @0x1d9f3c add r3, sp, #420
 *   @0x1d9f40 ldr r0, [r4, #0x30]
 *   @0x1d9f44 str r3, [sp]
 *   @0x1d9f48 add r3, sp, #424
 *   @0x1d9f4c str r3, [sp, #0x4]
 *   @0x1d9f50 add r3, sp, #428
 *   @0x1d9f54 str r3, [sp, #0x8]
 *   @0x1d9f58 add r3, sp, #416
 *   @0x1d9f5c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d9f60 mov r0, #16
 *   @0x1d9f64 bl 0x27c524 <_Znwj>
 *   @0x1d9f68 vldr s8, [sp, #384]
 *   @0x1d9f6c vldr s14, [sp, #400]
 *   @0x1d9f70 vldr s15, [sp, #376]
 *   @0x1d9f74 vcvt.f64.f32 d4, s8
 *   @0x1d9f78 vldr s10, [sp, #388]
 *   @0x1d9f7c vldr s12, [sp, #404]
 *   @0x1d9f80 mvn r2, #0
 *   @0x1d9f84 mov r3, #6
 *   @0x1d9f88 ldr r12, [pc, #0x8ec]
 *   @0x1d9f8c ldr r1, [pc, #0x8ec]
 *   @0x1d9f90 add r12, pc, r12
 *   @0x1d9f94 ldr lr, [pc, #0x8e8]
 *   @0x1d9f98 add r1, pc, r1
 *   @0x1d9f9c add lr, pc, lr
 *   @0x1d9fa0 vcvt.f64.s32 d3, s15
 *   @0x1d9fa4 vcvt.f64.f32 d7, s14
 *   @0x1d9fa8 vcvt.f64.f32 d5, s10
 *   @0x1d9fac vcvt.f64.f32 d6, s12
 *   @0x1d9fb0 mov r7, r0
 *   @0x1d9fb4 mov r0, #23
 *   @0x1d9fb8 str r2, [r7, #0x4]
 *   @0x1d9fbc str r3, [r7]
 *   @0x1d9fc0 str r5, [r7, #0x8]
 *   @0x1d9fc4 str r5, [r7, #0xc]
 *   @0x1d9fc8 vstr d4, [sp, #40]
 *   @0x1d9fcc vstr d7, [sp, #104]
 *   @0x1d9fd0 vldr s9, [sp, #380]
 *   @0x1d9fd4 vcvt.f64.s32 d7, s9
 *   @0x1d9fd8 ldr r2, [pc, #0x8a8]
 *   @0x1d9fdc ldr r3, [pc, #0x8a8]
 *   @0x1d9fe0 vstr d5, [sp, #56]
 *   @0x1d9fe4 str r12, [sp, #0x4]
 *   @0x1d9fe8 vmov s11, r10
 *   @0x1d9fec str r1, [sp, #0x14]
 *   @0x1d9ff0 vmov s9, r11
 *   @0x1d9ff4 add r2, pc, r2
 *   @0x1d9ff8 add r3, pc, r3
 *   @0x1d9ffc str r2, [sp, #0x24]
 *   @0x1da000 vstr d3, [sp, #8]
 *   @0x1da004 str r3, [sp, #0x34]
 *   @0x1da008 ldr r12, [pc, #0x880]
 *   @0x1da00c ldr r1, [pc, #0x880]
 *   @0x1da010 ldr r2, [pc, #0x880]
 *   @0x1da014 add r12, pc, r12
 *   @0x1da018 ldr r3, [pc, #0x87c]
 *   @0x1da01c add r1, pc, r1
 *   @0x1da020 str r12, [sp, #0x44]
 *   @0x1da024 add r2, pc, r2
 *   @0x1da028 str r1, [sp, #0x54]
 *   @0x1da02c add r3, pc, r3
 *   @0x1da030 str r5, [sp]
 *   @0x1da034 str r3, [sp, #0x74]
 *   @0x1da038 str r5, [sp, #0x10]
 *   @0x1da03c str r5, [sp, #0x20]
 *   @0x1da040 str r5, [sp, #0x30]
 *   @0x1da044 str r5, [sp, #0x40]
 *   @0x1da048 str r5, [sp, #0x50]
 *   @0x1da04c str r5, [sp, #0x60]
 *   @0x1da050 str r5, [sp, #0x70]
 *   @0x1da054 str r2, [sp, #0x64]
 *   @0x1da058 ldr r2, [r4, #0x4]
 *   @0x1da05c vstr d6, [sp, #120]
 *   @0x1da060 vstr d7, [sp, #24]
 *   @0x1da064 vcvt.f64.s32 d6, s11
 *   @0x1da068 ldr r12, [pc, #0x830]
 *   @0x1da06c ldr r1, [pc, #0x830]
 *   @0x1da070 add r12, pc, r12
 *   @0x1da074 ldr r3, [pc, #0x82c]
 *   @0x1da078 ldr r10, [pc, #0x82c]
 *   @0x1da07c add r1, pc, r1
 *   @0x1da080 ldr r11, [pc, #0x828]
 *   @0x1da084 add r3, pc, r3
 *   @0x1da088 add r10, pc, r10
 *   @0x1da08c vcvt.f64.s32 d7, s9
 *   @0x1da090 vstr d6, [sp, #72]
 *   @0x1da094 str r5, [sp, #0x80]
 *   @0x1da098 vldr s4, [sp, #392]
 *   @0x1da09c vldr s6, [sp, #396]
 *   @0x1da0a0 vldr s8, [sp, #408]
 *   @0x1da0a4 vldr s10, [sp, #412]
 *   @0x1da0a8 vldr s12, [sp, #416]
 *   @0x1da0ac add r11, pc, r11
 *   @0x1da0b0 vstr d7, [sp, #88]
 *   @0x1da0b4 vcvt.f64.f32 d4, s8
 *   @0x1da0b8 vldr s2, [r4, #48]
 *   @0x1da0bc vldr s14, [sp, #420]
 *   @0x1da0c0 str lr, [sp, #0x84]
 *   @0x1da0c4 str r12, [sp, #0xa4]
 *   @0x1da0c8 ldr lr, [pc, #0x7e4]
 *   @0x1da0cc ldr r12, [pc, #0x7e4]
 *   @0x1da0d0 str r8, [sp, #0x94]
 *   @0x1da0d4 add lr, pc, lr
 *   @0x1da0d8 vcvt.f64.f32 d1, s2
 *   @0x1da0dc vstr d4, [sp, #200]
 *   @0x1da0e0 str r1, [sp, #0xb4]
 *   @0x1da0e4 add r12, pc, r12
 *   @0x1da0e8 str r3, [sp, #0xc4]
 *   @0x1da0ec str r10, [sp, #0xd4]
 *   @0x1da0f0 str lr, [sp, #0xf4]
 *   @0x1da0f4 str r12, [sp, #0x104]
 *   @0x1da0f8 str r5, [sp, #0x90]
 *   @0x1da0fc vcvt.f64.f32 d2, s4
 *   @0x1da100 vstr d1, [sp, #264]
 *   @0x1da104 str r5, [sp, #0xa0]
 *   @0x1da108 str r5, [sp, #0xb0]
 *   @0x1da10c str r5, [sp, #0xc0]
 *   @0x1da110 str r5, [sp, #0xd0]
 *   @0x1da114 str r5, [sp, #0xe0]
 *   @0x1da118 str r5, [sp, #0xf0]
 *   @0x1da11c vcvt.f64.f32 d3, s6
 *   @0x1da120 vstr d2, [sp, #136]
 *   @0x1da124 str r5, [sp, #0x100]
 *   @0x1da128 str r11, [sp, #0xe4]
 *   @0x1da12c ldr r10, [pc, #0x788]
 *   @0x1da130 ldr r8, [pc, #0x788]
 *   @0x1da134 ldr lr, [pc, #0x788]
 *   @0x1da138 add r10, pc, r10
 *   @0x1da13c ldr r12, [pc, #0x784]
 *   @0x1da140 add r8, pc, r8
 *   @0x1da144 vcvt.f64.f32 d5, s10
 *   @0x1da148 vstr d3, [sp, #152]
 *   @0x1da14c ldr r3, [pc, #0x778]
 *   @0x1da150 add lr, pc, lr
 *   @0x1da154 ldr r1, [pc, #0x774]
 *   @0x1da158 add r12, pc, r12
 *   @0x1da15c add r3, pc, r3
 *   @0x1da160 add r1, pc, r1
 *   @0x1da164 vcvt.f64.f32 d6, s12
 *   @0x1da168 vstr d5, [sp, #216]
 *   @0x1da16c vldr s11, [sp, #368]
 *   @0x1da170 vcvt.f64.f32 d7, s14
 *   @0x1da174 vstr d6, [sp, #232]
 *   @0x1da178 vstr d7, [sp, #248]
 *   @0x1da17c vldr s9, [sp, #372]
 *   @0x1da180 vcvt.f64.s32 d7, s9
 *   @0x1da184 str r5, [sp, #0x110]
 *   @0x1da188 vldr s10, [sp, #424]
 *   @0x1da18c vstr d7, [sp, #184]
 *   @0x1da190 vmov.f64 d7, #1.000000e+00
 *   @0x1da194 vcvt.f64.s32 d6, s11
 *   @0x1da198 vstr d6, [sp, #168]
 *   @0x1da19c vldr s9, [r4, #52]
 *   @0x1da1a0 vstr d7, [sp, #328]
 *   @0x1da1a4 vstr d7, [sp, #344]
 *   @0x1da1a8 vcvt.f64.f32 d7, s9
 *   @0x1da1ac vldr s12, [sp, #428]
 *   @0x1da1b0 str r8, [sp, #0x124]
 *   @0x1da1b4 str lr, [sp, #0x134]
 *   @0x1da1b8 str r12, [sp, #0x144]
 *   @0x1da1bc str r3, [sp, #0x154]
 *   @0x1da1c0 str r5, [sp, #0x120]
 *   @0x1da1c4 str r5, [sp, #0x130]
 *   @0x1da1c8 vstr d7, [sp, #280]
 *   @0x1da1cc vmov s15, r2
 *   @0x1da1d0 vcvt.f64.f32 d5, s10
 *   @0x1da1d4 str r5, [sp, #0x140]
 *   @0x1da1d8 str r5, [sp, #0x150]
 *   @0x1da1dc str r5, [sp, #0x160]
 *   @0x1da1e0 str r10, [sp, #0x114]
 *   @0x1da1e4 vcvt.f64.f32 d6, s12
 *   @0x1da1e8 vstr d5, [sp, #296]
 *   @0x1da1ec vcvt.f64.s32 d7, s15
 *   @0x1da1f0 vstr d6, [sp, #312]
 *   @0x1da1f4 vmov r2, r3, d7
 *   @0x1da1f8 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1da1fc ldr r9, [pc, r9]
 *   @0x1da200 ldr r8, [r4, #0xc]
 *   @0x1da204 mov r3, r6
 *   @0x1da208 ldr lr, [r4, #0x10]
 *   @0x1da20c mov r2, #143
 *   @0x1da210 ldr r1, [pc, #0x6bc]
 *   @0x1da214 ldr r12, [r9, #0x8]
 *   @0x1da218 add r1, pc, r1
 *   @0x1da21c str r8, [r7, #0x8]
 *   @0x1da220 str lr, [r7, #0xc]
 *   @0x1da224 add r12, r12, r6
 *   @0x1da228 str r0, [r7, #0x4]
 *   @0x1da22c mov r0, #12
 *   @0x1da230 str r12, [r9, #0x8]
 *   @0x1da234 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1da238 ldr r3, [r9, #0x4]
 *   @0x1da23c cmp r3, #0
 *   @0x1da240 str r7, [r0, #0x8]
 *   @0x1da244 streq r0, [r9, #0x4]
 *   @0x1da248 strne r0, [r3]
 *   @0x1da24c streq r3, [r0, #0x4]
 *   @0x1da250 strne r3, [r0, #0x4]
 *   @0x1da254 streq r0, [r9]
 *   @0x1da258 strne r0, [r9, #0x4]
 *   @0x1da25c streq r3, [r0]
 *   @0x1da260 mov r3, #1
 *   @0x1da264 strne r5, [r0]
 *   @0x1da268 str r3, [r4, #0x14]
 *   @0x1da26c add sp, sp, #436
 *   @0x1da270 vpop {d8, d9}
 *   @0x1da274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1da278 vmov s9, r10
 *   @0x1da27c ldr r2, [r4, #0x40]
 *   @0x1da280 vmov s11, r11
 *   @0x1da284 add r3, sp, #388
 *   @0x1da288 vcvt.f32.s32 s9, s9
 *   @0x1da28c str r3, [sp]
 *   @0x1da290 add r3, sp, #400
 *   @0x1da294 str r3, [sp, #0x4]
 *   @0x1da298 add r3, sp, #404
 *   @0x1da29c str r3, [sp, #0x8]
 *   @0x1da2a0 add r3, sp, #384
 *   @0x1da2a4 str r12, [sp, #0x16c]
 *   @0x1da2a8 vcvt.f32.s32 s11, s11
 *   @0x1da2ac vmov r0, s9
 *   @0x1da2b0 vmov r1, s11
 *   @0x1da2b4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1da2b8 vldr s13, [sp, #368]
 *   @0x1da2bc vldr s14, [sp, #372]
 *   @0x1da2c0 vcvt.f32.s32 s13, s13
 *   @0x1da2c4 ldr r2, [r4, #0x40]
 *   @0x1da2c8 add r3, sp, #396
 *   @0x1da2cc str r3, [sp]
 *   @0x1da2d0 add r3, sp, #408
 *   @0x1da2d4 str r3, [sp, #0x4]
 *   @0x1da2d8 add r3, sp, #412
 *   @0x1da2dc str r3, [sp, #0x8]
 *   @0x1da2e0 add r3, sp, #392
 *   @0x1da2e4 vcvt.f32.s32 s14, s14
 *   @0x1da2e8 vmov r0, s13
 *   @0x1da2ec vmov r1, s14
 *   @0x1da2f0 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1da2f4 ldr r2, [r4, #0x40]
 *   @0x1da2f8 ldr r0, [r4, #0x30]
 *   @0x1da2fc add r3, sp, #420
 *   @0x1da300 ldr r1, [r4, #0x34]
 *   @0x1da304 str r3, [sp]
 *   @0x1da308 add r3, sp, #424
 *   @0x1da30c str r3, [sp, #0x4]
 *   @0x1da310 add r3, sp, #428
 *   @0x1da314 str r3, [sp, #0x8]
 *   @0x1da318 add r3, sp, #416
 *   @0x1da31c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1da320 cmp r8, #0
 *   @0x1da324 ldr r12, [sp, #0x16c]
 *   @0x1da328 bne 0x1da800 <_ZN13CGesturePinch6UpdateEx+0xb64>
 *   @0x1da32c cmp r12, #0
 *   @0x1da330 beq 0x1da86c <_ZN13CGesturePinch6UpdateEx+0xbd0>
 *   @0x1da334 ldr r3, [r7, #0x828]
 *   @0x1da338 ldr r2, [r7, #0x82c]
 *   @0x1da33c cmp r3, r2
 *   @0x1da340 beq 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da344 add r1, r7, #40
 *   @0x1da348 rsb r12, r1, r12
 *   @0x1da34c lsr r12, r12, #5
 *   @0x1da350 cmp r12, #63
 *   @0x1da354 bhi 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da358 cmp r3, r2
 *   @0x1da35c add r12, r12, #63
 *   @0x1da360 and r12, r12, #63
 *   @0x1da364 blt 0x1da7ec <_ZN13CGesturePinch6UpdateEx+0xb50>
 *   @0x1da368 cmp r2, r12
 *   @0x1da36c bgt 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da370 cmp r3, r12
 *   @0x1da374 ble 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da378 add r8, r7, r12, lsl #5
 *   @0x1da37c add r8, r8, #40
 *   @0x1da380 cmp r9, #0
 *   @0x1da384 beq 0x1da3d0 <_ZN13CGesturePinch6UpdateEx+0x734>
 *   @0x1da388 ldr r3, [r6, #0x828]
 *   @0x1da38c ldr r2, [r6, #0x82c]
 *   @0x1da390 cmp r3, r2
 *   @0x1da394 beq 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730>
 *   @0x1da398 add r1, r6, #40
 *   @0x1da39c rsb r9, r1, r9
 *   @0x1da3a0 lsr r9, r9, #5
 *   @0x1da3a4 cmp r9, #63
 *   @0x1da3a8 bhi 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730>
 *   @0x1da3ac cmp r3, r2
 *   @0x1da3b0 add r9, r9, #63
 *   @0x1da3b4 and r9, r9, #63
 *   @0x1da3b8 bge 0x1da7d0 <_ZN13CGesturePinch6UpdateEx+0xb34>
 *   @0x1da3bc cmp r3, r9
 *   @0x1da3c0 bgt 0x1da7e0 <_ZN13CGesturePinch6UpdateEx+0xb44>
 *   @0x1da3c4 cmp r2, r9
 *   @0x1da3c8 ble 0x1da7e0 <_ZN13CGesturePinch6UpdateEx+0xb44>
 *   @0x1da3cc mov r9, #0
 *   @0x1da3d0 cmp r8, #0
 *   @0x1da3d4 beq 0x1da840 <_ZN13CGesturePinch6UpdateEx+0xba4>
 *   @0x1da3d8 ldr r3, [r8, #0x8]
 *   @0x1da3dc cmp r3, r10
 *   @0x1da3e0 beq 0x1da834 <_ZN13CGesturePinch6UpdateEx+0xb98>
 *   @0x1da3e4 ldr r3, [sp, #0x170]
 *   @0x1da3e8 ldr r1, [sp, #0x174]
 *   @0x1da3ec rsb r2, r10, r3
 *   @0x1da3f0 rsb r3, r11, r1
 *   @0x1da3f4 vmov s9, r2
 *   @0x1da3f8 vmov s11, r3
 *   @0x1da3fc vcvt.f32.s32 s14, s9
 *   @0x1da400 vcvt.f32.s32 s15, s11
 *   @0x1da404 vcvt.s32.f32 s14, s14
 *   @0x1da408 vcvt.s32.f32 s15, s15
 *   @0x1da40c vmov r0, s14
 *   @0x1da410 vmov r1, s15
 *   @0x1da414 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1da418 vldr s14, [r4, #56]
 *   @0x1da41c vcmpe.f32 s14, #0
 *   @0x1da420 vldr s16, [r4, #60]
 *   @0x1da424 vmrs APSR_nzcv, fpscr
 *   @0x1da428 vcmpe.f32 s16, #0
 *   @0x1da42c vmovle.f32 s18, #1.000000e+00
 *   @0x1da430 vmov s15, r0
 *   @0x1da434 vdivgt.f32 s18, s15, s14
 *   @0x1da438 vmrs APSR_nzcv, fpscr
 *   @0x1da43c ble 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc>
 *   @0x1da440 str r0, [r4, #0x3c]
 *   @0x1da444 vdiv.f32 s16, s15, s16
 *   @0x1da448 vmov.f32 s15, #1.000000e+00
 *   @0x1da44c vcmpe.f32 s16, s15
 *   @0x1da450 vmrs APSR_nzcv, fpscr
 *   @0x1da454 ble 0x1da7b4 <_ZN13CGesturePinch6UpdateEx+0xb18>
 *   @0x1da458 mov r0, #16
 *   @0x1da45c bl 0x27c524 <_Znwj>
 *   @0x1da460 mvn r3, #0
 *   @0x1da464 mov r2, #8
 *   @0x1da468 mov r6, r0
 *   @0x1da46c vcvt.f64.f32 d8, s16
 *   @0x1da470 str r3, [r6, #0x4]
 *   @0x1da474 str r2, [r6]
 *   @0x1da478 mov r3, #0
 *   @0x1da47c str r3, [r6, #0x8]
 *   @0x1da480 str r3, [r6, #0xc]
 *   @0x1da484 vcvt.f64.f32 d7, s18
 *   @0x1da488 vldr s13, [sp, #376]
 *   @0x1da48c vldr s4, [sp, #384]
 *   @0x1da490 vldr s6, [sp, #388]
 *   @0x1da494 vldr s8, [sp, #400]
 *   @0x1da498 vldr s12, [sp, #404]
 *   @0x1da49c ldr r3, [pc, #0x434]
 *   @0x1da4a0 ldr r12, [pc, #0x434]
 *   @0x1da4a4 vldr s10, [sp, #392]
 *   @0x1da4a8 add r3, pc, r3
 *   @0x1da4ac ldr r1, [pc, #0x42c]
 *   @0x1da4b0 vcvt.f64.s32 d1, s13
 *   @0x1da4b4 str r3, [sp, #0x4]
 *   @0x1da4b8 ldr r2, [pc, #0x424]
 *   @0x1da4bc add r12, pc, r12
 *   @0x1da4c0 ldr r3, [pc, #0x420]
 *   @0x1da4c4 add r1, pc, r1
 *   @0x1da4c8 str r12, [sp, #0x14]
 *   @0x1da4cc add r2, pc, r2
 *   @0x1da4d0 str r1, [sp, #0x24]
 *   @0x1da4d4 add r3, pc, r3
 *   @0x1da4d8 str r2, [sp, #0x34]
 *   @0x1da4dc mov r5, #0
 *   @0x1da4e0 str r3, [sp, #0x44]
 *   @0x1da4e4 mov r0, #23
 *   @0x1da4e8 vcvt.f64.f32 d2, s4
 *   @0x1da4ec ldr r12, [pc, #0x3f8]
 *   @0x1da4f0 ldr r1, [pc, #0x3f8]
 *   @0x1da4f4 vstr d1, [sp, #8]
 *   @0x1da4f8 ldr r2, [pc, #0x3f4]
 *   @0x1da4fc add r12, pc, r12
 *   @0x1da500 ldr r3, [pc, #0x3f0]
 *   @0x1da504 add r1, pc, r1
 *   @0x1da508 str r12, [sp, #0x54]
 *   @0x1da50c add r2, pc, r2
 *   @0x1da510 str r1, [sp, #0x64]
 *   @0x1da514 add r3, pc, r3
 *   @0x1da518 str r2, [sp, #0x74]
 *   @0x1da51c vcvt.f64.f32 d3, s6
 *   @0x1da520 vstr d2, [sp, #40]
 *   @0x1da524 str r3, [sp, #0x84]
 *   @0x1da528 str r5, [sp]
 *   @0x1da52c str r5, [sp, #0x10]
 *   @0x1da530 str r5, [sp, #0x20]
 *   @0x1da534 str r5, [sp, #0x30]
 *   @0x1da538 str r5, [sp, #0x40]
 *   @0x1da53c vcvt.f64.f32 d4, s8
 *   @0x1da540 vstr d3, [sp, #56]
 *   @0x1da544 str r5, [sp, #0x50]
 *   @0x1da548 str r5, [sp, #0x60]
 *   @0x1da54c str r5, [sp, #0x70]
 *   @0x1da550 str r5, [sp, #0x80]
 *   @0x1da554 ldr r12, [pc, #0x3a0]
 *   @0x1da558 ldr r3, [pc, #0x3a0]
 *   @0x1da55c vcvt.f64.f32 d6, s12
 *   @0x1da560 vstr d4, [sp, #104]
 *   @0x1da564 vldr s9, [sp, #380]
 *   @0x1da568 ldr r2, [r4, #0x4]
 *   @0x1da56c add r12, pc, r12
 *   @0x1da570 add r3, pc, r3
 *   @0x1da574 ldr lr, [pc, #0x388]
 *   @0x1da578 ldr r1, [pc, #0x388]
 *   @0x1da57c ldr r7, [pc, #0x388]
 *   @0x1da580 add lr, pc, lr
 *   @0x1da584 ldr r8, [pc, #0x384]
 *   @0x1da588 add r1, pc, r1
 *   @0x1da58c vcvt.f64.f32 d5, s10
 *   @0x1da590 vstr d6, [sp, #120]
 *   @0x1da594 ldr r9, [pc, #0x378]
 *   @0x1da598 add r7, pc, r7
 *   @0x1da59c add r8, pc, r8
 *   @0x1da5a0 add r9, pc, r9
 *   @0x1da5a4 vcvt.f64.s32 d6, s9
 *   @0x1da5a8 vstr d5, [sp, #136]
 *   @0x1da5ac vmov s9, r10
 *   @0x1da5b0 vcvt.f64.s32 d5, s9
 *   @0x1da5b4 vstr d6, [sp, #24]
 *   @0x1da5b8 vmov s9, r11
 *   @0x1da5bc vcvt.f64.s32 d6, s9
 *   @0x1da5c0 vstr d5, [sp, #72]
 *   @0x1da5c4 str r5, [sp, #0x90]
 *   @0x1da5c8 vldr s2, [sp, #396]
 *   @0x1da5cc vldr s4, [sp, #408]
 *   @0x1da5d0 vldr s6, [sp, #412]
 *   @0x1da5d4 vldr s8, [sp, #416]
 *   @0x1da5d8 vldr s10, [sp, #420]
 *   @0x1da5dc vstr d6, [sp, #88]
 *   @0x1da5e0 vcvt.f64.f32 d4, s8
 *   @0x1da5e4 vldr s0, [r4, #48]
 *   @0x1da5e8 vldr s12, [r4, #52]
 *   @0x1da5ec str r12, [sp, #0xa4]
 *   @0x1da5f0 str r3, [sp, #0xb4]
 *   @0x1da5f4 ldr r12, [pc, #0x31c]
 *   @0x1da5f8 ldr r3, [pc, #0x31c]
 *   @0x1da5fc str lr, [sp, #0x94]
 *   @0x1da600 add r12, pc, r12
 *   @0x1da604 vcvt.f64.f32 d0, s0
 *   @0x1da608 vstr d4, [sp, #232]
 *   @0x1da60c add r3, pc, r3
 *   @0x1da610 vldr s9, [sp, #368]
 *   @0x1da614 str r1, [sp, #0xc4]
 *   @0x1da618 str r7, [sp, #0xd4]
 *   @0x1da61c str r8, [sp, #0xe4]
 *   @0x1da620 str r9, [sp, #0xf4]
 *   @0x1da624 str r12, [sp, #0x104]
 *   @0x1da628 vcvt.f64.f32 d1, s2
 *   @0x1da62c vstr d0, [sp, #264]
 *   @0x1da630 str r3, [sp, #0x114]
 *   @0x1da634 str r5, [sp, #0xa0]
 *   @0x1da638 str r5, [sp, #0xb0]
 *   @0x1da63c str r5, [sp, #0xc0]
 *   @0x1da640 str r5, [sp, #0xd0]
 *   @0x1da644 str r5, [sp, #0xe0]
 *   @0x1da648 vcvt.f64.f32 d2, s4
 *   @0x1da64c vstr d1, [sp, #152]
 *   @0x1da650 str r5, [sp, #0xf0]
 *   @0x1da654 str r5, [sp, #0x100]
 *   @0x1da658 str r5, [sp, #0x110]
 *   @0x1da65c ldr r9, [pc, #0x2bc]
 *   @0x1da660 ldr r8, [pc, #0x2bc]
 *   @0x1da664 ldr lr, [pc, #0x2bc]
 *   @0x1da668 add r9, pc, r9
 *   @0x1da66c vcvt.f64.f32 d3, s6
 *   @0x1da670 vstr d2, [sp, #200]
 *   @0x1da674 ldr r12, [pc, #0x2b0]
 *   @0x1da678 add lr, pc, lr
 *   @0x1da67c ldr r1, [pc, #0x2ac]
 *   @0x1da680 add r8, pc, r8
 *   @0x1da684 add r12, pc, r12
 *   @0x1da688 ldr r7, [pc, #0x2a4]
 *   @0x1da68c add r1, pc, r1
 *   @0x1da690 vcvt.f64.f32 d5, s10
 *   @0x1da694 vstr d3, [sp, #216]
 *   @0x1da698 vcvt.f64.f32 d6, s12
 *   @0x1da69c vstr d5, [sp, #248]
 *   @0x1da6a0 vstr d6, [sp, #280]
 *   @0x1da6a4 vstr d7, [sp, #344]
 *   @0x1da6a8 vmov s15, r2
 *   @0x1da6ac str lr, [sp, #0x144]
 *   @0x1da6b0 vcvt.f64.s32 d5, s9
 *   @0x1da6b4 vldr s9, [sp, #372]
 *   @0x1da6b8 str r12, [sp, #0x154]
 *   @0x1da6bc vstr d8, [sp, #328]
 *   @0x1da6c0 str r5, [sp, #0x120]
 *   @0x1da6c4 str r5, [sp, #0x130]
 *   @0x1da6c8 str r5, [sp, #0x140]
 *   @0x1da6cc str r5, [sp, #0x150]
 *   @0x1da6d0 str r5, [sp, #0x160]
 *   @0x1da6d4 vcvt.f64.s32 d6, s9
 *   @0x1da6d8 vstr d5, [sp, #168]
 *   @0x1da6dc vldr s11, [sp, #428]
 *   @0x1da6e0 str r9, [sp, #0x124]
 *   @0x1da6e4 str r8, [sp, #0x134]
 *   @0x1da6e8 vcvt.f64.s32 d7, s15
 *   @0x1da6ec vstr d6, [sp, #184]
 *   @0x1da6f0 vldr s12, [sp, #424]
 *   @0x1da6f4 vmov r2, r3, d7
 *   @0x1da6f8 vcvt.f64.f32 d6, s12
 *   @0x1da6fc vcvt.f64.f32 d7, s11
 *   @0x1da700 vstr d6, [sp, #296]
 *   @0x1da704 vstr d7, [sp, #312]
 *   @0x1da708 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1da70c ldr r1, [r4, #0x10]
 *   @0x1da710 ldr r7, [pc, r7]
 *   @0x1da714 ldr lr, [r4, #0xc]
 *   @0x1da718 mov r3, #1
 *   @0x1da71c mov r2, #143
 *   @0x1da720 str r1, [r6, #0xc]
 *   @0x1da724 ldr r1, [pc, #0x20c]
 *   @0x1da728 ldr r12, [r7, #0x8]
 *   @0x1da72c add r1, pc, r1
 *   @0x1da730 str lr, [r6, #0x8]
 *   @0x1da734 add r12, r12, r3
 *   @0x1da738 str r0, [r6, #0x4]
 *   @0x1da73c mov r0, #12
 *   @0x1da740 str r12, [r7, #0x8]
 *   @0x1da744 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1da748 ldr r3, [r7, #0x4]
 *   @0x1da74c cmp r3, r5
 *   @0x1da750 str r6, [r0, #0x8]
 *   @0x1da754 strne r0, [r3]
 *   @0x1da758 strne r3, [r0, #0x4]
 *   @0x1da75c strne r0, [r7, #0x4]
 *   @0x1da760 strne r5, [r0]
 *   @0x1da764 streq r0, [r7, #0x4]
 *   @0x1da768 streq r0, [r7]
 *   @0x1da76c streq r3, [r0, #0x4]
 *   @0x1da770 streq r3, [r0]
 *   @0x1da774 b 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc>
 *   @0x1da778 cmp r6, #0
 *   @0x1da77c mvn r2, #0
 *   @0x1da780 mov r12, r7
 *   @0x1da784 str r2, [sp, #0x178]
 *   @0x1da788 mov r8, #1
 *   @0x1da78c mov r11, r7
 *   @0x1da790 mov r10, r7
 *   @0x1da794 bne 0x1d9d10 <_ZN13CGesturePinch6UpdateEx+0x74>
 *   @0x1da798 mvn r3, #0
 *   @0x1da79c mov r9, r6
 *   @0x1da7a0 str r3, [sp, #0x17c]
 *   @0x1da7a4 mov r8, #1
 *   @0x1da7a8 str r6, [sp, #0x174]
 *   @0x1da7ac str r6, [sp, #0x170]
 *   @0x1da7b0 b 0x1d9d54 <_ZN13CGesturePinch6UpdateEx+0xb8>
 *   @0x1da7b4 bpl 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc>
 *   @0x1da7b8 mov r0, #16
 *   @0x1da7bc bl 0x27c524 <_Znwj>
 *   @0x1da7c0 mvn r3, #0
 *   @0x1da7c4 mov r2, #7
 *   @0x1da7c8 mov r6, r0
 *   @0x1da7cc b 0x1da46c <_ZN13CGesturePinch6UpdateEx+0x7d0>
 *   @0x1da7d0 cmp r2, r9
 *   @0x1da7d4 bgt 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730>
 *   @0x1da7d8 cmp r3, r9
 *   @0x1da7dc ble 0x1da3cc <_ZN13CGesturePinch6UpdateEx+0x730>
 *   @0x1da7e0 add r9, r6, r9, lsl #5
 *   @0x1da7e4 add r9, r9, #40
 *   @0x1da7e8 b 0x1da3d0 <_ZN13CGesturePinch6UpdateEx+0x734>
 *   @0x1da7ec cmp r3, r12
 *   @0x1da7f0 bgt 0x1da378 <_ZN13CGesturePinch6UpdateEx+0x6dc>
 *   @0x1da7f4 cmp r2, r12
 *   @0x1da7f8 ble 0x1da378 <_ZN13CGesturePinch6UpdateEx+0x6dc>
 *   @0x1da7fc b 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da800 mov r0, #16
 *   @0x1da804 bl 0x27c524 <_Znwj>
 *   @0x1da808 vmov.f64 d7, #1.000000e+00
 *   @0x1da80c mov r2, #9
 *   @0x1da810 mvn r3, #0
 *   @0x1da814 vmov.f64 d8, d7
 *   @0x1da818 stm r0, {r2, r3}
 *   @0x1da81c mov r6, r0
 *   @0x1da820 mov r2, #0
 *   @0x1da824 str r2, [r0, #0x8]
 *   @0x1da828 str r2, [r0, #0xc]
 *   @0x1da82c str r3, [r4, #0x14]
 *   @0x1da830 b 0x1da488 <_ZN13CGesturePinch6UpdateEx+0x7ec>
 *   @0x1da834 ldr r3, [r8, #0xc]
 *   @0x1da838 cmp r3, r11
 *   @0x1da83c bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748>
 *   @0x1da840 cmp r9, #0
 *   @0x1da844 beq 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc>
 *   @0x1da848 ldr r3, [r9, #0x8]
 *   @0x1da84c ldr r1, [sp, #0x170]
 *   @0x1da850 cmp r3, r1
 *   @0x1da854 bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748>
 *   @0x1da858 ldr r3, [r9, #0xc]
 *   @0x1da85c ldr r2, [sp, #0x174]
 *   @0x1da860 cmp r3, r2
 *   @0x1da864 bne 0x1da3e4 <_ZN13CGesturePinch6UpdateEx+0x748>
 *   @0x1da868 b 0x1d9d68 <_ZN13CGesturePinch6UpdateEx+0xcc>
 *   @0x1da86c mov r8, r12
 *   @0x1da870 b 0x1da380 <_ZN13CGesturePinch6UpdateEx+0x6e4>
 *   @0x1da874 eoreq r6, r1, r4, lsl #20
 *   @0x1da878 andseq r7, r7, r0, asr #8
 *   @0x1da87c andseq r7, r7, r8, asr #5
 *   @0x1da880 andseq r7, r7, r8, asr #5
 *   @0x1da884 andseq r7, r7, r12, lsl #6
 *   @0x1da888 andseq r7, r7, r4, ror r2
 *   @0x1da88c andseq r7, r7, r8, ror r2
 *   @0x1da890 andseq r7, r7, r4, ror #4
 *   @0x1da894 andseq r7, r7, r8, ror #4
 *   @0x1da898 andseq r7, r7, r12, ror #4
 *   @0x1da89c andseq r7, r7, r0, ror r2
 *   @0x1da8a0 andseq r7, r7, r8, asr #4
 *   @0x1da8a4 andseq r7, r7, r8, asr #4
 *   @0x1da8a8 andseq r7, r7, r12, asr #4
 *   @0x1da8ac andseq r7, r7, r4, asr r2
 *   @0x1da8b0 andseq r7, r7, r12, lsr r2
 *   @0x1da8b4 andseq r7, r7, r0, lsr #4
 *   @0x1da8b8 andseq r7, r7, r12, lsl r2
 *   @0x1da8bc ldrsbeq r7, [r7], -r8
 *   @0x1da8c0 andseq r7, r7, r0, ror #3
 *   @0x1da8c4 andseq r7, r7, r0, ror #3
 *   @0x1da8c8 andseq r7, r7, r8, ror #3
 *   @0x1da8cc ldrsheq r7, [r7], -r4
 *   @0x1da8d0 andseq r7, r7, r8, lsl r0
 *   @0x1da8d4 andseq r2, r7, r8, lsl r12
 *   @0x1da8d8 ldrheq r6, [r7], -r0
 *   @0x1da8dc andseq r6, r7, r4, lsr #27
 *   @0x1da8e0 andseq r6, r7, r4, lsr #27
 *   @0x1da8e4 andseq r6, r7, r4, lsr #27
 *   @0x1da8e8 andseq r6, r7, r4, lsr #27
 *   @0x1da8ec andseq r6, r7, r8, lsl #27
 *   @0x1da8f0 andseq r6, r7, r12, lsl #27
 *   @0x1da8f4 mulseq r7, r0, sp
 *   @0x1da8f8 mulseq r7, r4, sp
 *   @0x1da8fc andseq r6, r7, r12, asr #26
 *   @0x1da900 andseq r6, r7, r4, asr sp
 *   @0x1da904 andseq r6, r7, r0, lsr sp
 *   @0x1da908 andseq r6, r7, r8, asr #26
 *   @0x1da90c andseq r6, r7, r4, asr #26
 *   @0x1da910 andseq r6, r7, r12, asr #26
 *   @0x1da914 andseq r6, r7, r4, asr sp
 *   @0x1da918 andseq r6, r7, r0, lsl #26
 *   @0x1da91c andseq r6, r7, r4, lsl #26
 *   @0x1da920 ldrheq r6, [r7], -r8
 *   @0x1da924 ldrheq r6, [r7], -r0
 *   @0x1da928 andseq r6, r7, r8, asr #25
 *   @0x1da92c andseq r6, r7, r12, asr #25
 *   @0x1da930 andseq r6, r7, r12, ror #21
 *   @0x1da934 .word 0x002164f0
 *   @0x1da938 andseq r2, r7, r4, lsl #14
 *
 * ══ §4/13 anon_30ad9a  0x30ad9a  size 3212  803 条（0x30ad9a..0x30ba26）
 * @func 0x30ad9a 0x30ba26  size 3212  803 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x356e16 / ft_lzwstate_io+0x5e / 0x3af2ee / 0x6faf0e / 0x6f131e / 0x70a146 / 0xff6ca952 / anon_30a7b2+0x379e
 * 字段偏移 top8: 0x4×1 / 0xe×1 / 0xc×1 / 0x44×1 / 0x1×1 / 0x10×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30ad9a push {r1, r2, r3, r5, r6, r8, r10, r12, sp, lr}
 *   @0x30ad9e .word 0xf5ad4ff0
 *   @0x30ada2 addslt r4, pc, r3, asr #27
 *   @0x30ada6 .word 0xf10d4604
 *   @0x30adaa mcrvs p8, #0x2, r0, c15, c8, #0x3
 *   @0x30adae strbeq pc, [r4, #-0x1a8]!
 *   @0x30adb2 .word 0xf640460e
 *   @0x30adb6 smlabths r0, r8, r2, r2
 *   @0x30adba .word 0xf50d4628
 *   @0x30adbe .word 0xf5ab5acf
 *   @0x30adc2 .word 0xf504ebf6
 *   @0x30adc6 .word 0xf8485310
 *   @0x30adca strhs r7, [r0, -r4, ror #24]
 *   @0x30adce ldrtmi r6, [r0], -r7, ror #6
 *   @0x30add2 .word 0xf10a61df
 *   @0x30add6 stmdavs r2!, {r2, r3, r4, r9, r11}
 *   @0x30adda ldmvs r2, {r1, r2, r4, r5, r6, r8, r9, r11, lr}
 *   @0x30adde ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x30ade2 eorlo pc, r2, r3, asr r8
 *   @0x30ade6 ldrsbls pc, [r0], -r3
 *   @0x30adea stc2l p7, c15, [r9], #-1020
 *   @0x30adee .word 0xf8994683
 *   @0x30adf2 bicslt r7, r7, r0
 *   @0x30adf6 .word 0xf1094648
 *   @0x30adfa stmdavc r3, {r0, r8, r11}
 *   @0x30adfe rscsle r2, r9, r0, lsr #22
 *   @0x30ae02 qsaxmi r4, r1, r3
 *   @0x30ae06 .word 0xf7ff465a
 *   @0x30ae0a .word 0xf8dafc67
 *   @0x30ae0e blhs 0x356e16
 *   @0x30ae12 stmle r12!, {r0, r7, r9, r10, lr} ^
 *   @0x30ae16 .word 0x21002200
 *   @0x30ae1a .word 0x91004620
 *   @0x30ae1e uadd16mi r4, r9, r3
 *   @0x30ae22 ldc2 p7, c15, [r6], #1020
 *   @0x30ae26 stmdahs r0, {r0, r1, r2, r9, r10, lr}
 *   @0x30ae2a ldrtmi sp, [r0], -r1, ror #1
 *   @0x30ae2e .word 0xf7ff4659
 *   @0x30ae32 svchs #0xfc50
 *   @0x30ae36 addshi pc, r1, r0
 *   @0x30ae3a shasxmi r4, r9, r0
 *   @0x30ae3e .word 0xf7dc2201
 *   @0x30ae42 pkhbtmi pc, r1, r0, lsl #23
 *   @0x30ae46 .word 0xf0402800
 *   @0x30ae4a .word 0xf8d68088
 *   @0x30ae4e rfeib r11!
 *   @0x30ae52 blhs 0x317012 <ft_lzwstate_io+0x5e>
 *   @0x30ae56 addhi pc, r1, r0, asr #6
 *   @0x30ae5a ldrbpl pc, [r3, sp, lsl #10]
 *   @0x30ae5e ldrlo r4, [r8, -r9, asr #12]
 *   @0x30ae62 rscsvc pc, r12, #68, #4
 *   @0x30ae66 beq 0x224750a <b2_toiTime+0x1aee066>
 *   @0x30ae6a .word 0xf5ab4650
 *   @0x30ae6e bvs 0xfec05cf6 <b2_toiTime+0xfffffffffe4ac852>
 *   @0x30ae72 ldclvs p8, c15, [r8], #-284
 *   @0x30ae76 .word 0xf8c54628
 *   @0x30ae7a .word 0xf10baabc
 *   @0x30ae7e .word 0xf847016c
 *   @0x30ae82 .word 0xf44f3c54
 *   @0x30ae86 .word 0xf8c53380
 *   @0x30ae8a .word 0xf8479ab4
 *   @0x30ae8e .word 0xf8473c74
 *   @0x30ae92 .word 0xf7fc3c70
 *   @0x30ae96 stmdahs r0, {r2, r3, r4, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x30ae9a .word 0xf104d15f
 *   @0x30ae9e .word 0xf1a80738
 *   @0x30aea2 strtmi r0, [r9], r8, ror #16
 *   @0x30aea6 .word 0xf04f4606
 *   @0x30aeaa .word 0x21000b2c
 *   @0x30aeae .word 0xf8c84628
 *   @0x30aeb2 ldrtmi r1, [r1], -r0
 *   @0x30aeb6 movweq pc, #0xc1a7
 *   @0x30aeba .word 0xf7fc9303
 *   @0x30aebe .word 0x4601fdbc
 *   @0x30aec2 mrsle r2, spsr
 *   @0x30aec6 strtmi r4, [r8], -r10, lsl #12
 *   @0x30aeca .word 0xf7fc4633
 *   @0x30aece .word 0xf8d9fa39
 *   @0x30aed2 .word 0xf8d92034
 *   @0x30aed6 andhs r1, r12, r12, lsr #32
 *   @0x30aeda .word 0x2101fb0b
 *   @0x30aede blls 0x3af2ee <error_g0017+0x7f92>
 *   @0x30aee2 eorle r4, r3, #-1610612727
 *   @0x30aee6 mvnslt r6, r3, asr r9
 *   @0x30aeea addsmi r6, r1, #1458176
 *   @0x30aeee addsmi sp, r3, #28, #2
 *   @0x30aef2 rfeia r3!
 *   @0x30aef6 .word 0xf8d8e002
 *   @0x30aefa rfeia r2!
 *   @0x30aefe blhs 0x6faf0e <g_SWFvertbuff+0x27e46>
 *   @0x30af02 mrrcne p8, #0x1, sp, r9, c2
 *   @0x30af06 andne pc, r0, r8, asr #17
 *   @0x30af0a blx 0x6f131e <g_SWFvertbuff+0x1e256>
 *   @0x30af0e blx 0x70a146 <g_SWFvertbuff+0x3707e>
 *   @0x30af12 bl 0xff6ca952 <b2_toiTime+0xfffffffffef714ae>
 *   @0x30af16 blx 0x30df50 <af_shaper_get_elem+0x37be>
 *   @0x30af1a .word 0xf1bc1303
 *   @0x30af1e svclt #0xb80f00
 *   @0x30af22 .word 0x0c00f1cc
 *   @0x30af26 andgt pc, r12, r3, asr #17
 *   @0x30af2a ldrb r3, [r8, r12, lsr #4]
 *   @0x30af2e .word 0x0028f8da
 *   @0x30af32 .word 0xf00d2164
 *   @0x30af36 ldrtmi lr, [r9], -r8, lsl #29
 *   @0x30af3a vmax.s8 d3, d9, d1
 *   @0x30af3e strmi r5, [r2], -r4, asr #18
 *   @0x30af42 .word 0xf7fc4640
 *   @0x30af46 .word 0xf8d8f8de
 *   @0x30af4a cdphs p0, #0x0, c3, c2, c0, #0x0
 *   @0x30af4e .word 0x3c04f847
 *   @0x30af52 strpl pc, [pc, -r7, lsl #10]
 *   @0x30af56 streq pc, [r8, -r7, lsl #2]!
 *   @0x30af5a .word 0xf504d1a7
 *   @0x30af5e strtmi r4, [r6], -pc, lsl #19
 *   @0x30af62 ldmdbeq r0, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x30af66 ldmdaeq r2!, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30af6a beq 0x3470ae
 *   @0x30af6e .word 0xb10b6b73
 *   @0x30af72 strh r6, [r6], -r7
 *   @0x30af76 strbmi r6, [r1], -r7, lsr #21
 *   @0x30af7a svclt #0x48434f
 *   @0x30af7e ldrbvc pc, [pc, r7, lsl #4]!
 *   @0x30af82 shsub8mi r1, r8, pc
 *   @0x30af86 .word 0xf00d2105
 *   @0x30af8a .word 0xf8c6eec2
 *   @0x30af8e .word 0xf88670fc
 *   @0x30af92 .word 0xf8c6a100
 *   @0x30af96 .word 0xf50600f8
 *   @0x30af9a strtlo r5, [r8], -pc, lsl #12
 *   @0x30af9e mvnle r4, lr, asr #10
 *   @0x30afa2 .word 0xf7fd4628
 *   @0x30afa6 .word 0xf50dfc0c
 *   @0x30afaa andslt r4, pc, r3, asr #27
 *   @0x30afae svchi #0xf0e8bd
 *   @0x30afb2 cdpvs p15, #0x0, c11, c6, c0, #0x0
 *   @0x30afb6 push {r1, r2, r3}
 *   @0x30afba .word 0xf5ad4ff0
 *   @0x30afbe stmdavs r3, {r0, r4, r8, r10, r11, r12, sp, lr}
 *   @0x30afc2 tstls r3, r11
 *   @0x30afc6 ldmvs r12, {r1, r2, r3, r8, sp} ^
 *   @0x30afca ssatlo pc, #0x19, pc, asr #17
 *   @0x30afce ldrbtmi r6, [r11], #-2688
 *   @0x30afd2 bl 0x3e5046 <error_g0017+0x3dcea>
 *   @0x30afd6 .word 0xf00d04c4
 *   @0x30afda .word 0xf104ee36
 *   @0x30afde andsls r0, r11, r8, lsl #22
 *   @0x30afe2 .word 0xf7ff9813
 *   @0x30afe6 andsls pc, r6, r12, ror #22
 *   @0x30afea .word 0x2c08f85b
 *   @0x30afee msrmi CPSR_fc, #268435460
 *   @0x30aff2 .word 0xf000429a
 *   @0x30aff6 .word 0xf8df82ea
 *   @0x30affa andhs r3, r0, r12, lsl #13
 *   @0x30affe ldrbtmi r9, [r11], #-9
 *   @0x30b002 andsls r6, r0, r11, lsl r8
 *   @0x30b006 ldrdls r1, r2, [r8], -r3
 *   @0x30b00a andls r9, sp, r4, lsl r3
 *   @0x30b00e stmdavc r11, {r2, r4, r8, r11, r12, pc}
 *   @0x30b012 .word 0xf0002b00
 *   @0x30b016 strmi r8, [r11], -r3, ror #4
 *   @0x30b01a movwlo r4, #0x1618
 *   @0x30b01e bhs 0xb2902e <b2_toiTime+0x3cfb8a>
 *   @0x30b022 stcge p0, c13, [r0], #-1000
 *   @0x30b026 bls 0x8b145a <b2_toiTime+0x157fb6>
 *   @0x30b02a .word 0xf7ff4623
 *   @0x30b02e stmdavs r3!, {r0, r2, r4, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x30b032 blhs 0x32f08a
 *   @0x30b036 rfeda r11!
 *   @0x30b03a .word 0xf04f3c04
 *   @0x30b03e .word 0xf8cd0900
 *   @0x30b042 .word 0xf0139044
 *   @0x30b046 .word 0xf8cd0f01
 *   @0x30b04a svclt #0xc9054
 *   @0x30b04e .word 0x4100f06f
 *   @0x30b052 .word 0x4100f04f
 *   @0x30b056 blls 0xb2f496 <b2_toiTime+0x3d5ff2>
 *   @0x30b05a .word 0x9044f8dd
 *   @0x30b05e .word 0xf0804599
 *   @0x30b062 ldmdbls r6, {r0, r5, r9, pc}
 *   @0x30b066 stmdals r11, {r0, r1, r2, r3, r4, r10, r11, sp, pc}
 *   @0x30b06a strls r2, [r0], #-768
 *   @0x30b06e .word 0xf7ff9a11
 *   @0x30b072 strmi pc, [r1], -pc, lsl #23
 *   @0x30b076 .word 0xf0002800
 *   @0x30b07a andhs r8, r1, #-536870912
 *   @0x30b07e .word 0xf7dc9813
 *   @0x30b082 ldmdbls r3, {r4, r5, r6, r9, r11, r12, sp, lr, pc}
 *   @0x30b086 svcvs #0x516d4a
 *   @0x30b08a strhtls pc, [r12], #-130
 *   @0x30b08e strhtlo pc, [lr], #-130
 *   @0x30b092 .word 0x910a6f15
 *   @0x30b096 ldrsbtge pc, [r8], #-130
 *   @0x30b09a .word 0xf0402800
 *   @0x30b09e andslt r8, r11, #252, #2
 *   @0x30b0a2 .word 0xf3402b02
 *   @0x30b0a6 stmdavs r4!, {r3, r4, r5, r6, r7, r8, pc}
 *   @0x30b0aa .word 0xf989fa0f
 *   @0x30b0ae .word 0xf04f4606
 *   @0x30b0b2 strdls r3, r4, [r12], -pc
 *   @0x30b0b6 andls r9, r7, r2, lsl r4
 *   @0x30b0ba blls 0x62f0da <g_SWFaavertbuff+0x5c012>
 *   @0x30b0be ble 0x1b1c5f2 <b2_toiTime+0x13c314e>
 *   @0x30b0c2 rfedb r10!
 *   @0x30b0c6 addmi r2, r2, #19
 *   @0x30b0ca rfeda r11!
 *   @0x30b0ce b 0x16ea0e6 <b2_toiTime+0xf90c42>
 *   @0x30b0d2 strtmi r0, [lr], #3776
 *   @0x30b0d6 .word 0xf0174604
 *   @0x30b0da strbmi r0, [r3], -r3, lsl #14
 *   @0x30b0de strhs sp, [r0, -pc, lsr #32]
 *   @0x30b0e2 ldcle p2, c4, [sp], #-592
 *   @0x30b0e6 blle 0x455cee <g_RomDisk+0x5e4ce>
 *   @0x30b0ea .word 0x0c07eb0e
 *   @0x30b0ee .word 0xc004f8dc
 *   @0x30b0f2 stcle p5, c4, [r11, #-720]
 *   @0x30b0f6 movweq lr, #0x7b0e
 *   @0x30b0fa ldmdavs lr, {r1, r4, r8, r11, r12, pc} ^
 *   @0x30b0fe ldrtmi r9, [r1], #-2832
 *   @0x30b102 svclt #0xb8428b
 *   @0x30b106 tstls r0, #11534336
 *   @0x30b10a and r4, r6, r3, lsr #12
 *   @0x30b10e strmi r9, [r12], #2322
 *   @0x30b112 strbmi r9, [r1, #-0x909]!
 *   @0x30b116 strbtmi r11, [r1], -r8, lsr #31
 *   @0x30b11a strlo r9, [r1], #-265
 *   @0x30b11e ldrb r3, [pc, r8, lsl #14]
 *   @0x30b122 ble 0x6d5d2a <g_SWFvertbuff+0x2c62>
 *   @0x30b126 movweq lr, #0x7b0e
 *   @0x30b12a ldmdavs lr, {r0, r3, r8, r11, r12, pc} ^
 *   @0x30b12e ldrtmi r9, [r3], #-2834
 *   @0x30b132 svclt #0xa84299
 *   @0x30b136 qadd16mi r4, r3, r9
 *   @0x30b13a strlo r9, [r1], #-265
 *   @0x30b13e addsmi r3, r4, #8, #14
 *   @0x30b142 and sp, sp, lr, ror #27
 *   @0x30b146 .word 0x0c07eb0e
 *   @0x30b14a .word 0xc004f8dc
 *   @0x30b14e blle 0xffd5c826 <b2_toiTime+0xffffffffff603382>
 *   @0x30b152 strmi r9, [r12], #2322
 *   @0x30b156 strbmi r9, [r1, #-0x910]!
 *   @0x30b15a .word 0x4661bfb8
 *   @0x30b15e .word 0xe7ec9110
 *   @0x30b162 strbmi r9, [r3, #-0x907]
 *   @0x30b166 sadd16mi r11, r1, r8
 *   @0x30b16a stmdbls r6, {r0, r1, r2, r8, r12, pc}
 *   @0x30b16e .word 0x4601bf18
 *   @0x30b172 and r9, r0, r6, lsl #2
 *   @0x30b176 mrrcne p6, #0x4, r4, r0, c3
 *   @0x30b17a ldrmi r9, [r8], r12, lsl #20
 *   @0x30b17e andls r3, r12, #268435456
 *   @0x30b182 .word 0xf1b8e79b
 *   @0x30b186 .word 0xf8cd0f00
 *   @0x30b18a vmvn.i32 d24, #0xc
 *   @0x30b18e bls 0x5ab76e <g_SWFlineaavertbuff+0x586a6>
 *   @0x30b192 .word 0xf8554647
 *   @0x30b196 andshs r9, r4, r8, lsr r0
 *   @0x30b19a andlo pc, r8, r2, lsl r8
 *   @0x30b19e movweq pc, #0x3003
 *   @0x30b1a2 svclt #0xc2b01
 *   @0x30b1a6 .word 0xf04f46c4
 *   @0x30b1aa .word 0x46e23cff
 *   @0x30b1ae addsmi r9, pc, #6144
 *   @0x30b1b2 .word 0xf107bfcc
 *   @0x30b1b6 blls 0x4d81ba <SrcVerts+0x351fe>
 *   @0x30b1ba sbceq lr, r3, #5120
 *   @0x30b1be blne 0xfe56530a <b2_toiTime+0xfffffffffde0be66>
 *   @0x30b1c2 svclt #0xb82900
 *   @0x30b1c6 stmdbhs r5, {r0, r3, r6, r9, lr}
 *   @0x30b1ca .word 0xf855dd09
 *   @0x30b1ce movtmi r2, #0x1033
 *   @0x30b1d2 andeq lr, r2, #205824
 *   @0x30b1d6 svclt #0xb82a00
 *   @0x30b1da addmi r4, r10, #536870917
 *   @0x30b1de stmdbls r10, {r0, r1, r2, r3, r8, r10, r11, r12, lr, pc}
 *   @0x30b1e2 .word 0xf0025cca
 *   @0x30b1e6 bhs 0x34b9fa
 *   @0x30b1ea .word 0xf1bad104
 *   @0x30b1ee ldrmi r0, [r12], r0, lsl #30
 *   @0x30b1f2 .word 0x469abfb8
 *   @0x30b1f6 andle r4, r1, r3, asr #10
 *   @0x30b1fa bfc r4, #12, #12
 *   @0x30b1fe strbmi r4, [r4], -r7, asr #12
 *   @0x30b202 bls 0x4d365a <SrcVerts+0x3069e>
 *   @0x30b206 svclt #0xb44294
 *   @0x30b20a blls 0x49239e <g_prim_v+0x2392>
 *   @0x30b20e sbceq lr, r3, #5120
 *   @0x30b212 ldmdavs r2, {r3, r4, r9, r12, pc} ^
 *   @0x30b216 b 0xfe392066 <b2_toiTime+0xfffffffffdc38bc2>
 *   @0x30b21a bl 0xfeb275aa <b2_toiTime+0xfffffffffe3ce106>
 *   @0x30b21e stmdahs r5, {r1, r5, r6, r7, r12, sp, lr}
 *   @0x30b222 .word 0xf855dd09
 *   @0x30b226 movtmi r2, #0x8033
 *   @0x30b22a andeq lr, r2, #205824
 *   @0x30b22e svclt #0xb82a00
 *   @0x30b232 addmi r4, r2, #536870917
 *   @0x30b236 stmdals r10, {r0, r1, r2, r3, r8, r10, r11, r12, lr, pc}
 *   @0x30b23a .word 0xf0025cc2
 *   @0x30b23e bhs 0x34ba52
 *   @0x30b242 .word 0xf1bcd104
 *   @0x30b246 ldrmi r0, [r10], r0, lsl #30
 *   @0x30b24a .word 0x469cbfb8
 *   @0x30b24e andle r4, r1, r3, asr #10
 *   @0x30b252 bfi r4, r12, #12, #11
 *   @0x30b256 rfeda r11!
 *   @0x30b25a andsls r2, r9, #4, #24
 *   @0x30b25e .word 0xf14006d2
 *   @0x30b262 blls 0x5eb5ee <g_SWFaavertbuff+0x18526>
 *   @0x30b266 bvs 0xfe9d36d2 <b2_toiTime+0xfffffffffe27a22e>
 *   @0x30b26a andsgt pc, r4, sp, asr #17
 *   @0x30b26e movwls r4, #0xc618
 *   @0x30b272 stcl p0, c15, [r10], #52
 *   @0x30b276 eorshs pc, r4, r5, asr r8
 *   @0x30b27a eorslo pc, r7, r5, asr r8
 *   @0x30b27e ldrsbgt pc, [r4], -sp
 *   @0x30b282 blhs 0x311dd6 <af_shaper_get_elem+0x7644>
 *   @0x30b286 subsmi r11, r11, #184, #30
 *   @0x30b28a andsls r4, r10, r3, lsl #5
 *   @0x30b28e sbchi pc, r10, r0, lsl #5
 *   @0x30b292 blne 0xffbb12b6 <b2_toiTime+0xffffffffff457e12>
 *   @0x30b296 andlo r9, r1, #98304
 *   @0x30b29a addsmi r1, r10, #274432
 *   @0x30b29e sbchi pc, r2, r0, lsl #5
 *   @0x30b2a2 ldrmi r9, [r0, #0xa06]
 *   @0x30b2a6 cpsie aif
 *   @0x30b2aa .word 0xf8dd38ff
 *   @0x30b2ae .word 0xf855801c
 *   @0x30b2b2 strbmi r3, [r11, #-0x38]
 *   @0x30b2b6 blls 0x6ff6ca <g_SWFvertbuff+0x2c602>
 *   @0x30b2ba .word 0xd1f14598
 *   @0x30b2be bls 0x703672 <g_SWFvertbuff+0x305aa>
 *   @0x30b2c2 .word 0xf0004590
 *   @0x30b2c6 strbmi r8, [r11, #-0xe8]
 *   @0x30b2ca andeq pc, r0, #79
 *   @0x30b2ce ldrmi r4, [r1], -r0, lsr #13
 *   @0x30b2d2 movwhs r11, #0xfac
 *   @0x30b2d6 tstls sp, #67108864
 *   @0x30b2da andls r9, r12, #12, #22
 *   @0x30b2de tstls r12, #10158080
 *   @0x30b2e2 ldmdblt r9!, {r0, r1, r5, r9, r10, lr} ^
 *   @0x30b2e6 .word 0x9028f8dd
 *   @0x30b2ea andhs pc, r3, r9, lsl r8
 *   @0x30b2ee andeq pc, r3, #2
 *   @0x30b2f2 andle r2, r4, r1, lsl #20
 *   @0x30b2f6 rscslo pc, pc, #79
 *   @0x30b2fa andls r4, r12, #152, #12
 *   @0x30b2fe ldrmi lr, [r10], -r2
 *   @0x30b302 movwls r4, #0xc698
 *   @0x30b306 sbceq lr, r8, pc, asr #20
 *   @0x30b30a ldrsbls pc, [r12], -sp
 *   @0x30b30e strmi r9, [r1], -r3
 *   @0x30b312 strbmi r4, [r11, #-0x429]
 *   @0x30b316 ldrsbtls pc, [r0], #-141
 *   @0x30b31a .word 0xe004f8d1
 *   @0x30b31e movwlo r11, #0x1fb4
 *   @0x30b322 bl 0xff6b1f42 <b2_toiTime+0xfffffffffef58a9e>
 *   @0x30b326 stmdbhs r0, {r1, r2, r8}
 *   @0x30b32a submi r11, r9, #184, #30
 *   @0x30b32e stclle p5, c4, [pc], #-292
 *   @0x30b332 ldrdls r0, r1, [pc], -r8
 *   @0x30b336 strtmi r4, [r9], #-1537
 *   @0x30b33a bl 0xff6a5466 <b2_toiTime+0xfffffffffef4bfc2>
 *   @0x30b33e .word 0xf1b90901
 *   @0x30b342 svclt #0xb80f00
 *   @0x30b346 stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc}
 *   @0x30b34a svceq #0x5f1b9
 *   @0x30b34e stmdbls r3, {r2, r3, r8, r10, r11, r12, lr, pc}
 *   @0x30b352 eorseq pc, r3, r5, asr r8
 *   @0x30b356 bne 0x1321502 <b2_toiTime+0xbc805e>
 *   @0x30b35a blx 0x3537b4
 *   @0x30b35e stmdahs r0, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30b362 submi r11, r0, #184, #30
 *   @0x30b366 ldclle p2, c4, [r3, #-544]
 *   @0x30b36a stclpl p8, c9, [r0], {10}
 *   @0x30b36e mrseq pc, apsr
 *   @0x30b372 .word 0xd1042901
 *   @0x30b376 ldrmi r9, [r10], -r12, lsl #18
 *   @0x30b37a svclt #0xb82900
 *   @0x30b37e stmdbls pc, {r2, r3, r8, r9, r12, pc}
 *   @0x30b382 stmdapl r9!, {r0, r1, r11, r12, pc} ^
 *   @0x30b386 .word 0x91045828
 *   @0x30b38a ldmdbls sp, {r3, r7, r9, lr}
 *   @0x30b38e svclt #0xac9017
 *   @0x30b392 andhs r2, r1, r0
 *   @0x30b396 teqle sp, r8, lsl #5
 *   @0x30b39a stmdals r4, {r0, r1, r2, r4, r8, r11, r12, pc}
 *   @0x30b39e ldmdbls r10, {r6, r9, r11, r12}
 *   @0x30b3a2 stmdahs r0, {r0, r1, r2, r3, r12, pc}
 *   @0x30b3a6 submi r11, r0, #184, #30
 *   @0x30b3aa blle 0xfdbdd2 <b2_toiTime+0x88292e>
 *   @0x30b3ae .word 0xf8dd2014
 *   @0x30b3b2 blx 0x33b47c
 *   @0x30b3b6 ldrmi pc, [r2], r9, lsl #18
 *   @0x30b3ba addsmi r9, r3, #28672
 *   @0x30b3be mrrcne p15, #0xb, r11, r12, c4
 *   @0x30b3c2 bl 0x4723e2 <g_RomDisk+0x7abc2>
 *   @0x30b3c6 ldmdavs r11, {r2, r6, r7, r8, r9} ^
 *   @0x30b3ca movweq lr, #0x3bce
 *   @0x30b3ce svclt #0xb82b00
 *   @0x30b3d2 blhs 0x45bd46 <g_RomDisk+0x64526>
 *   @0x30b3d6 bls 0x942812 <b2_toiTime+0x1e936e>
 *   @0x30b3da ldmdavs r3, {r0, r1, r2, r4, r11, r12, pc}
 *   @0x30b3de blhs 0x311c52 <af_shaper_get_elem+0x74c0>
 *   @0x30b3e2 subsmi r11, r11, #184, #30
 *   @0x30b3e6 .word 0xdc04454b
 *   @0x30b3ea addsmi r9, r4, #24576
 *   @0x30b3ee .word 0x3c01dd17
 *   @0x30b3f2 bls 0x5c3452 <g_SWFlineaavertbuff+0x7038a>
 *   @0x30b3f6 .word 0xf0035d13
 *   @0x30b3fa blhs 0x34c00e
 *   @0x30b3fe b 0x123f812 <b2_toiTime+0xae636e>
 *   @0x30b402 svclt #0x280c2c
 *   @0x30b406 adcsmi r4, r12, #164, #12
 *   @0x30b40a andle r4, r9, r2, lsr #13
 *   @0x30b40e ldrb r4, [r3, r3, lsr #12]
 *   @0x30b412 and r2, r0, r0, lsl #2
 *   @0x30b416 adcsmi r2, r11, #1073741824
 *   @0x30b41a svcge #0x63f47f
 *   @0x30b41e .word 0x9c07e002
 *   @0x30b422 ldrbtmi r4, [r6], -r7, asr #12
 *   @0x30b426 .word 0xf1bc9b12
 *   @0x30b42a ldrmi r0, [lr], #-3840
 *   @0x30b42e .word 0xf1badb0e
 *   @0x30b432 blle 0x5cf03a <g_SWFlineaavertbuff+0x7bf72>
 *   @0x30b436 eorshs pc, r10, r5, asr r8
 *   @0x30b43a eorslo pc, r12, r5, asr r8
 *   @0x30b43e .word 0x906cf8dd
 *   @0x30b442 blhs 0x311f96 <af_shaper_get_elem+0x7804>
 *   @0x30b446 subsmi r11, r11, #184, #30
 *   @0x30b44a .word 0xdc16454b
 *   @0x30b44e vldrpl s19, [r3, #40]
 *   @0x30b452 movweq pc, #0x3003
 *   @0x30b456 .word 0xd1072b01
 *   @0x30b45a .word 0xf0025d12
 *   @0x30b45e .word 0xf1120203
 *   @0x30b462 svclt #0x1832ff
 *   @0x30b466 and r2, r0, r1, lsl #4
 *   @0x30b46a .word 0xf0022201
 *   @0x30b46e strdlt r0, r1, [r10, -pc]!
 *   @0x30b472 smmlaeq r11, r9, r11, r9
 *   @0x30b476 movwhs sp, #0x140f
 *   @0x30b47a movwhs lr, #0x0
 *   @0x30b47e .word 0x2c04f83b
 *   @0x30b482 strle r0, [r3, #-0x7d7]
 *   @0x30b486 addmi r9, r6, #917504
 *   @0x30b48a and sp, r4, r3, lsl #24
 *   @0x30b48e addmi r9, lr, #229376
 *   @0x30b492 tstls r5, #4096
 *   @0x30b496 .word 0xf8dd960e
 *   @0x30b49a .word 0xf1099044
 *   @0x30b49e .word 0xf8cd0901
 *   @0x30b4a2 ldrb r9, [r8, #0x44]
 *   @0x30b4a6 .word 0xf100980e
 *   @0x30b4aa bllo 0x35c0b2
 *   @0x30b4ae .word 0xf63f3303
 *   @0x30b4b2 ldmdbls r5, {r0, r2, r3, r5, r7, r8, r10, r11, sp, pc}
 *   @0x30b4b6 bls 0x5379e2 <obj_numb_event+0xa72>
 *   @0x30b4ba ldmdbvc r0, {r0, r2, r3, r8, r10, r12, sp, lr, pc}
 *   @0x30b4be orreq lr, r2, #9216
 *   @0x30b4c2 andls r3, r8, #268435456
 *   @0x30b4c6 stcleq p8, c15, [r12], {67}
 *   @0x30b4ca stmdals lr, {r5, r7, r8, r10, sp, lr, pc}
 *   @0x30b4ce .word 0xf8ddab2a
 *   @0x30b4d2 .word 0xf8439034
 *   @0x30b4d6 .word 0xf1090029
 *   @0x30b4da ldr r0, [r6, #0x1]
 *   @0x30b4de ldmdblt r2, {r0, r2, r3, r9, r11, r12, pc}
 *   @0x30b4e2 blhs 0x33210a
 *   @0x30b4e6 stcge p0, c13, [r10], #-440
 *   @0x30b4ea ldmdbge sp, {r3, r11, r12, pc} ^
 *   @0x30b4ee ldc2l p7, c15, [r5, #1004]!
 *   @0x30b4f2 strtmi r9, [r1], -sp, lsl #16
 *   @0x30b4f6 ldc2l p7, c15, [r1, #1004]!
 *   @0x30b4fa eorhs r9, r4, #720896
 *   @0x30b4fe tstpl r0, r0, lsl #10
 *   @0x30b502 .word 0xf8d13114
 *   @0x30b506 blx 0x38b870 <_pcre_ucp_gbtable+0x14>
 *   @0x30b50a andlo r1, r1, r0, lsl #4
 *   @0x30b50e sbcseq pc, r8, r1, asr #17
 *   @0x30b512 sbcslo r9, r8, #212992
 *   @0x30b516 stmdblt r1, {r0, r1, r4, r8, r10, r11, r12} ^
 *   @0x30b51a .word 0xf50d9808
 *   @0x30b51e stmdaeq r1, {r4, r8, r11, r12, sp, lr} ^
 *   @0x30b522 orreq lr, r1, r9, lsl #22
 *   @0x30b526 stclne p8, c15, [r12], {81}
 *   @0x30b52a stmdals sp, {r0, r2, sp, lr, pc}
 *   @0x30b52e stmdals r8, {r0, r6, r11}
 *   @0x30b532 eorne pc, r1, r4, asr r8
 *   @0x30b536 sbcsvs r11, r9, r0, lsl r9
 *   @0x30b53a and r6, r9, r1, asr r0
 *   @0x30b53e .word 0xf50d9808
 *   @0x30b542 subsvs r7, r1, r0, lsl r9
 *   @0x30b546 bl 0x54d652 <gp_ActiveMaskObjects+0x898a>
 *   @0x30b54a .word 0xf8510181
 *   @0x30b54e sbcsvs r1, r9, r12, asr #25
 *   @0x30b552 ldmdavs r1, {r3, r4, r6, r7, r11, sp, lr} ^
 *   @0x30b556 andsle r4, r1, r8, lsl #5
 *   @0x30b55a .word 0x4c04f83b
 *   @0x30b55e streq pc, [r3], #-20
 *   @0x30b562 strhs r11, [r1], #-3864
 *   @0x30b566 svclt #0xd44288
 *   @0x30b56a strhs r2, [r1, #-0x500]
 *   @0x30b56e andle r4, r5, r12, lsr #5
 *   @0x30b572 bl 0x35c57e
 *   @0x30b576 ldrdne r7, r8, [r9], #-17
 *   @0x30b57a ldrsbvs r6, [r1], #-9
 *   @0x30b57e andhs r9, r0, #16, #16
 *   @0x30b582 andsvs r9, r10, #147456
 *   @0x30b586 .word 0x61d96198
 *   @0x30b58a .word 0x2c04f83b
 *   @0x30b58e svclt #0x4407d4
 *   @0x30b592 andsvs r2, r10, #536870912
 *   @0x30b596 .word 0x2c04f83b
 *   @0x30b59a strle r0, [r3, #-0x790]
 *   @0x30b59e .word 0xf0426a1a
 *   @0x30b5a2 andsvs r0, r10, #4, #4
 *   @0x30b5a6 .word 0x2c04f83b
 *   @0x30b5aa strle r0, [r3, #-0x751]
 *   @0x30b5ae .word 0xf0426a1a
 *   @0x30b5b2 andsvs r0, r10, #8, #4
 *   @0x30b5b6 .word 0x2c04f83b
 *   @0x30b5ba strle r0, [r3, #-0x712]
 *   @0x30b5be .word 0xf0426a1a
 *   @0x30b5c2 andsvs r0, r10, #16, #4
 *   @0x30b5c6 bleq 0x5479fa <gp_ActiveMaskObjects+0x2d32>
 *   @0x30b5ca ldmdals r3, {r1, r2, r3, r8, r10, sp, lr, pc}
 *   @0x30b5ce .word 0xf7ff9916
 *   @0x30b5d2 bls 0x6097da <g_SWFaavertbuff+0x36712>
 *   @0x30b5d6 ldrpl pc, [r0, #-0x502]
 *   @0x30b5da .word 0xf8d53514
 *   @0x30b5de mcrhs p0, #0x0, r6, c0, c8, #0x6
 *   @0x30b5e2 .word 0xf502d04a
 *   @0x30b5e6 .word 0xf10d5213
 *   @0x30b5ea eorslo r0, r0, #128, #24
 *   @0x30b5ee .word 0xf84c2300
 *   @0x30b5f2 movwlo r2, #0x1023
 *   @0x30b5f6 .word 0xf10242b3
 *   @0x30b5fa mvnsle r0, r4, lsr #4
 *   @0x30b5fe adcsmi r2, r2, #268435456
 *   @0x30b602 bge 0xaffa12 <b2_toiTime+0x3a656e>
 *   @0x30b606 ands r2, lr, r0, lsl #6
 *   @0x30b60a orreq lr, r2, #12, #22
 *   @0x30b60e biclt r4, r4, r4, lsl r6
 *   @0x30b612 .word 0x0c04f853
 *   @0x30b616 bvs 0x35a22e
 *   @0x30b61a svceq #0x6f011
 *   @0x30b61e svclt #0x186859
 *   @0x30b622 .word 0x8000f8d0
 *   @0x30b626 svclt #0x86a0f
 *   @0x30b62a .word 0x800cf8d0
 *   @0x30b62e svceq #0x6f017
 *   @0x30b632 stmdavs pc, {r2, r4, r8, r9, r10, r11, r12, sp, pc}
 *   @0x30b636 strbmi r6, [r7, #-0x8cf]
 *   @0x30b63a subsvs sp, r8, r3, lsl #20
 *   @0x30b63e andsvs r3, r9, r1, lsl #24
 *   @0x30b642 andlo lr, r1, #60030976
 *   @0x30b646 .word 0xf8d5e7db
 *   @0x30b64a stmdblo r1, {r3, r4, r6, r7, r12}
 *   @0x30b64e andsle r4, r3, #-1342177272
 *   @0x30b652 svcne #0x4f852
 *   @0x30b656 bvs 0x518262 <SrcVerts+0x752a6>
 *   @0x30b65a svceq #0x6f010
 *   @0x30b65e svclt #0x186850
 *   @0x30b662 bvs 0x417a9a <g_RomDisk+0x2027a>
 *   @0x30b666 svceq #0x6f014
 *   @0x30b66a svclt #0x18680c
 *   @0x30b66e stmdavs r0, {r2, r3, r12, sp}
 *   @0x30b672 svclt #0xc84284
 *   @0x30b676 strb r6, [r6, r8]!
 *   @0x30b67a ldcvc p5, c15, [r1, #-52]
 *   @0x30b67e svchi #0xf0e8bd
 *   @0x30b682 stcvs p15, c11, [r0], #-0
 *   @0x30b686 blvs 0xb6c6
 *   @0x30b68a push {r1, r2, r3}
 *   @0x30b68e strdlt r4, r5, [sp], r0
 *   @0x30b692 .word 0x460c4e3a
 *   @0x30b696 strmi r6, [r5], -r9, asr #27
 *   @0x30b69a ldmdavs r6!, {r1, r2, r3, r4, r5, r6, r10, lr}
 *   @0x30b69e .word 0x91026833
 *   @0x30b6a2 movwls r4, #0xb935
 *   @0x30b6a6 strhlo pc, [r4], #-132
 *   @0x30b6aa strtmi r6, [r0], -r3, lsl #5
 *   @0x30b6ae .word 0xf921f7da
 *   @0x30b6b2 strmi r9, [r7], -r3, lsl #12
 *   @0x30b6b6 mrsle r2, spsr
 *   @0x30b6ba strtmi r4, [r1], -r8, lsr #12
 *   @0x30b6be blx 0x1e896c4 <b2_toiTime+0x1730220>
 *   @0x30b6c2 strtmi r4, [r1], -r8, lsr #12
 *   @0x30b6c6 ldc2l p7, c15, [r7], #-1020
 *   @0x30b6ca bge 0x49e386 <TimingData+0x436e>
 *   @0x30b6ce ldrbtmi r9, [r11], #-1796
 *   @0x30b6d2 ldreq pc, [r0, -r3, lsl #2]
 *   @0x30b6d6 ldmdavs r8, {r4, r7, r9, r10, lr}
 *   @0x30b6da .word 0xf8533308
 *   @0x30b6de adcsmi r1, r11, #4, #24
 *   @0x30b6e2 .word 0xc6034616
 *   @0x30b6e6 mvnsle r4, r2, lsr r6
 *   @0x30b6ea .word 0xf10d6818
 *   @0x30b6ee .word 0xf10d0b14
 *   @0x30b6f2 .word 0x46c10a10
 *   @0x30b6f6 qasxmi r6, r0, r0
 *   @0x30b6fa .word 0xffe1f7fe
 *   @0x30b6fe ldrtmi r2, [r0], r0, lsl #12
 *   @0x30b702 .word 0xf8994607
 *   @0x30b706 mvnslt r3, r0
 *   @0x30b70a ldrbmi r4, [r11], -r8, asr #12
 *   @0x30b70e ldrtmi r4, [r10], -r9, lsr #12
 *   @0x30b712 .word 0xffe2f7fe
 *   @0x30b716 blhs 0x372332 <_ZTS13C_UTF16String+0x93de>
 *   @0x30b71a ldmle r2!, {r0, r7, r9, r10, lr} ^
 *   @0x30b71e strtmi r2, [r8], -r0, lsl #6
 *   @0x30b722 ldrmi r9, [r10], -r0, lsl #6
 *   @0x30b726 uasxmi r4, r3, r9
 *   @0x30b72a rfeda r2!
 *   @0x30b72e rscle r2, r8, r0, lsl #16
 *   @0x30b732 .word 0xf1b89b04
 *   @0x30b736 andle r0, r3, r0, lsl #30
 *   @0x30b73a strhle r4, [r2], -r3
 *   @0x30b73e and r2, r4, r0, lsl #12
 *   @0x30b742 .word 0xf04f461e
 *   @0x30b746 ldrb r0, [r12, r1, lsl #16]
 *   @0x30b74a strtmi r2, [r0], -r1, lsl #12
 *   @0x30b74e .word 0xf7fe4639
 *   @0x30b752 .word 0xf885ffc0
 *   @0x30b756 stmdbls r2, {r5, sp, lr}
 *   @0x30b75a .word 0xf7da4620
 *   @0x30b75e stmdbls r3, {r1, r2, r3, r6, r7, r9, r11, r12, sp, lr, pc}
 *   @0x30b762 andhs r9, r0, r11, lsl #20
 *   @0x30b766 addsmi r6, r10, #720896
 *   @0x30b76a .word 0xf5aad001
 *   @0x30b76e andlt lr, sp, r2, lsr pc
 *   @0x30b772 svchi #0xf0e8bd
 *   @0x30b776 stmdbvs r3!, {r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x30b77a adcshs r7, r10, #461373440
 *   @0x30b77e stmlo sp!, {r1, r2, r3} ^
 *   @0x30b782 ldrblt r0, [r0, #0x8]!
 *   @0x30b786 stmdavc r3, {r4, r8, r9, r12, sp, pc}
 *   @0x30b78a ldmdbmi r0, {r0, r1, r3, r4, r5, r6, r7, r8, r12, sp, pc}
 *   @0x30b78e svclt #0x82b2d
 *   @0x30b792 .word 0xf04f3001
 *   @0x30b796 ldrbtmi r0, [r9], #-1802
 *   @0x30b79a ldrbtlo pc, [pc], #256
 *   @0x30b79e andhs r11, r1, #12, #30
 *   @0x30b7a2 andhs r2, r0, r0, lsl #4
 *   @0x30b7a6 svclo #0x1f814
 *   @0x30b7aa ldrbeq lr, [r3, #0xb01]
 *   @0x30b7ae umullvs pc, r0, r5, r8
 *   @0x30b7b2 streq pc, [r7, #-0x3]
 *   @0x30b7b6 .word 0xf505fa46
 *   @0x30b7ba strle r0, [r3, #-0x7ed]
 *   @0x30b7be blx 0x4e2af4 <SrcVerts+0x3fb38>
 *   @0x30b7c2 strb r3, [pc, r0]!
 *   @0x30b7c6 submi r11, r0, #-2147483644
 *   @0x30b7ca ssub8mi r11, r8, r0
 *   @0x30b7ce svcvc #0xb4bdf0
 *   @0x30b7d2 ldrblt r0, [r0, #0x9]!
 *   @0x30b7d6 stmdavc r3, {r5, r8, r9, r12, sp, pc}
 *   @0x30b7da ldmdbmi r2, {r0, r1, r3, r8, r9, r12, sp, pc}
 *   @0x30b7de svclt #0x82b2d
 *   @0x30b7e2 .word 0xf04f3001
 *   @0x30b7e6 ldrbtmi r0, [r9], #-1802
 *   @0x30b7ea ldrbtlo pc, [pc], #256
 *   @0x30b7ee andhs r11, r1, #12, #30
 *   @0x30b7f2 andhs r2, r0, r0, lsl #4
 *   @0x30b7f6 svclo #0x1f814
 *   @0x30b7fa ldrbeq lr, [r3, #0xb01]
 *   @0x30b7fe umullvs pc, r0, r5, r8
 *   @0x30b802 streq pc, [r7, #-0x3]
 *   @0x30b806 .word 0xf505fa46
 *   @0x30b80a strle r0, [r4, #-0x7ed]
 *   @0x30b80e blx 0x4e2b44 <SrcVerts+0x3fb88>
 *   @0x30b812 addlt r3, r0, #0
 *   @0x30b816 tstlt r10, lr, ror #15
 *   @0x30b81a addlt r4, r0, #64, #4
 *   @0x30b81e ldrmi lr, [r8], -r0
 *   @0x30b822 ldcllt p2, c11, [r0, #0]!
 *   @0x30b826 svcvc #0x64bf00
 *   @0x30b82a stmdavs r3, {r0, r3} ^
 *   @0x30b82e addsmi r6, r3, #4849664
 *   @0x30b832 svclt #0xd4db03
 *   @0x30b836 andhs r2, r1, r0
 *   @0x30b83a .word 0xf04f4770
 *   @0x30b83e .word 0x477030ff
 *   @0x30b842 .word 0xf8d36803
 *   @0x30b846 blvs 0x1793a7e <b2_toiTime+0x103a5da>
 *   @0x30b84a .word 0xf8d36102
 *   @0x30b84e swpbvs r3, r0, [r3]
 *   @0x30b852 ldrbmi r2, [r0, -r0]!
 *   @0x30b856 .word 0x61432300
 *   @0x30b85a ldrbmi r6, [r0, -r3, lsl #2]!
 *   @0x30b85e stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc} ^
 *   @0x30b862 andhs r6, r0, r2, lsl #18
 *   @0x30b866 andle r4, pc, #144, #4
 *   @0x30b86a ldmdaeq r11, {r0, r1, r4, r11, r12} ^
 *   @0x30b86e eorspl pc, r3, r4, asr r8
 *   @0x30b872 strbeq lr, [r3], r4, lsl #22
 *   @0x30b876 smlatble r3, r9, r2, r4
 *   @0x30b87a strhlo r8, [r1], -r0
 *   @0x30b87e ldcllt p2, c11, [r0, #-512]!
 *   @0x30b882 sasxmi r11, r10, r4
 *   @0x30b886 ubfx r1, r8, #0x18, #0xe
 *   @0x30b88a ldcllt p0, c2, [r0, #-0]!
 *   @0x30b88e movwhs r11, #0x5f0
 *   @0x30b892 stmdbvs r6, {r1, r3, r11, sp, lr}
 *   @0x30b896 andlo r6, r1, #68, #18
 *   @0x30b89a adcmi r4, r11, #55574528
 *   @0x30b89e stmne r8!, {r1, r2, r3, r9, r12, lr, pc} ^
 *   @0x30b8a2 .word 0xf8540840
 *   @0x30b8a6 bl 0x42796e <g_RomDisk+0x3014e>
 *   @0x30b8aa adcsmi r0, r10, #192, #24
 *   @0x30b8ae rfeia r12!
 *   @0x30b8b2 and r0, r10, r4
 *   @0x30b8b6 .word 0x4605bf34
 *   @0x30b8ba strb r1, [lr, r3, asr #24]!
 *   @0x30b8be andle r4, r7, #805306379
 *   @0x30b8c2 sbceq lr, r3, r4, lsl #22
 *   @0x30b8c6 eorshs pc, r3, r4, asr r8
 *   @0x30b8ca andlo r8, r1, r0, lsl #17
 *   @0x30b8ce and r11, r1, r0, lsl #5
 *   @0x30b8d2 ldrmi r2, [r0], -r0, lsl #4
 *   @0x30b8d6 ldcllt p0, c6, [r0, #40]!
 *   @0x30b8da .word 0x3084f8d0
 *   @0x30b8de .word 0xf8d0600b
 *   @0x30b8e2 andhs r3, r0, r8, lsl #1
 *   @0x30b8e6 .word 0x47706013
 *   @0x30b8ea .word 0x4604b538
 *   @0x30b8ee .word 0xf8d06800
 *   @0x30b8f2 .word 0xf7d9508c
 *   @0x30b8f6 .word 0xf06ffe16
 *   @0x30b8fa andhs r0, r0, pc, lsr r2
 *   @0x30b8fe orrseq r6, r11, r11, lsr #21
 *   @0x30b902 bvs 0xffde3f96 <b2_toiTime+0xffffffffff68aaf2>
 *   @0x30b906 mvnvs r4, r3, asr r3
 *   @0x30b90a orrseq r8, r11, r11, lsr #17
 *   @0x30b90e ldclt p2, c6, [r8, #-396]!
 *   @0x30b912 .word 0x4605b5f8
 *   @0x30b916 strmi r6, [r12], -r3, lsl #16
 *   @0x30b91a bvs 0xae5b42 <b2_toiTime+0x38c69e>
 *   @0x30b91e .word 0x608cf8d3
 *   @0x30b922 .word 0xb123690b
 *   @0x30b926 qdaddhs r4, r8, r8
 *   @0x30b92a .word 0xf00d3024
 *   @0x30b92e .word 0x3020e9f0
 *   @0x30b932 orrne r6, r0, r3, lsr #16
 *   @0x30b936 blhs 0x377d8a <_ZTS13C_UTF16String+0xee36>
 *   @0x30b93a ands sp, r2, r6
 *   @0x30b93e .word 0x332068fb
 *   @0x30b942 svcne #0xa3ebb0
 *   @0x30b946 and sp, r6, r5, lsl #2
 *   @0x30b94a bvs 0xfffe641a <b2_toiTime+0xffffffffff88cf76>
 *   @0x30b94e addsmi r4, r8, #318767104
 *   @0x30b952 andshs sp, r7, r1
 *   @0x30b956 qsub8mi r11, r8, r8
 *   @0x30b95a pop {r8, sp}
 *   @0x30b95e .word 0xf7ff40f8
 *   @0x30b962 andhs r11, r7, r3, asr #31
 *   @0x30b966 push {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x30b96a .word 0x460443f8
 *   @0x30b96e .word 0xf8d5680d
 *   @0x30b972 stmdbvs r8!, {r2, r3, r7, r12, sp}
 *   @0x30b976 orrhs pc, r8, r3, lsl #10
 *   @0x30b97a rfeia r1!
 *   @0x30b97e suble r9, sp, #134
 *   @0x30b982 .word 0xf8d5b912
 *   @0x30b986 and r2, r0, r4, lsr #1
 *   @0x30b98a blvs 0xfe9da196 <b2_toiTime+0xfffffffffe280cf2>
 *   @0x30b98e blx 0x353e28
 *   @0x30b992 ldmibhi r0, {r1, r9, r12, sp}
 *   @0x30b996 ldmdbhi r6, {r0, r4, r7, r8, r11, sp, lr} ^
 *   @0x30b99a ldrhhi pc, [r0], -r2
 *   @0x30b99e ldmibvs r3, {r0, r1, r2, r4, r7, r9, r11, pc} ^
 *   @0x30b9a2 strvs r8, [r0, #-0x9d2]!
 *   @0x30b9a6 strbvs r4, [r3, #-0x620]!
 *   @0x30b9aa .word 0xf7db64e2
 *   @0x30b9ae .word 0xf109fdd2
 *   @0x30b9b2 stmdbhs r7, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r12, sp}
 *   @0x30b9b6 ldm pc, {r2, r4, r11, r12, lr, pc} ^
 *   @0x30b9ba streq pc, [r4], -r1
 *   @0x30b9be tstne r3, #77824
 *   @0x30b9c2 movwhs r0, #0x1c13
 *   @0x30b9c6 movwhs lr, #0x3000
 *   @0x30b9ca subslo pc, lr, r4, lsl #17
 *   @0x30b9ce movwhs lr, #0x4008
 *   @0x30b9d2 movwhs lr, #0x27fa
 *   @0x30b9d6 subslo pc, lr, r4, lsl #17
 *   @0x30b9da orrvc pc, r0, #1325400064
 *   @0x30b9de subslo pc, r12, r4, lsr #17
 *   @0x30b9e2 blx 0x6de62a <g_SWFvertbuff+0xb562>
 *   @0x30b9e6 .word 0x01b6f288
 *   @0x30b9ea adcvs r6, r6, #102760448
 *   @0x30b9ee strtvs r0, [r3], #402
 *   @0x30b9f2 .word 0x66a3b23b
 *   @0x30b9f6 andseq pc, r8, r4, lsl #2
 *   @0x30b9fa rsbvs r0, r3, #-1073741786
 *   @0x30b9fe eorvs r6, r2, #2240
 *   @0x30ba02 .word 0x61a3019b
 *   @0x30ba06 orrseq r6, r11, r3, ror #25
 *   @0x30ba0a .word 0xf8d561e3
 *   @0x30ba0e ldmhi r9, {r2, r3, r7, r12, sp} ^
 *   @0x30ba12 .word 0xf7d90189
 *   @0x30ba16 andhs pc, r0, r4, ror #26
 *   @0x30ba1a .word 0x83f8e8bd
 *   @0x30ba1e pop {r1, r2, sp}
 *   @0x30ba22 ldrbtvc r8, [r3], #-1016
 *
 * ══ §5/13 pcre_dfa_exec  0x26e568  size 3200  800 条（0x26e568..0x26f1e8）
 * @func 0x26e568 0x26f1e8  size 3200  800 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_dfa_exec+0x550×3 / _pcre_is_newline×3 / _pcre_was_newline×2 / pcre_dfa_exec+0xc54 / pcre_dfa_exec+0xb0c / pcre_dfa_exec+0xc6c / pcre_dfa_exec+0xc74 / pcre_dfa_exec+0x23c
 * 字段偏移 top8: 0xbc×11 / 0x7c×11 / 0x1×10 / 0x24×8 / 0x80×8 / 0x84×7 / 0x34×7 / 0x44×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x26e568 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x26e56c sub sp, sp, #148
 *   @0x26e570 movw r12, #0x5a6f
 *   @0x26e574 movt r12, #0xe20c
 *   @0x26e578 ldr r4, [sp, #0xbc]
 *   @0x26e57c mov r6, r0
 *   @0x26e580 str r2, [sp, #0x24]
 *   @0x26e584 and r12, r4, r12
 *   @0x26e588 cmp r12, #0
 *   @0x26e58c bne 0x26f07c <pcre_dfa_exec+0xb14>
 *   @0x26e590 cmp r2, #0
 *   @0x26e594 cmpne r0, #0
 *   @0x26e598 beq 0x26e79c <pcre_dfa_exec+0x234>
 *   @0x26e59c ldr r12, [sp, #0xc8]
 *   @0x26e5a0 cmp r12, #0
 *   @0x26e5a4 beq 0x26e79c <pcre_dfa_exec+0x234>
 *   @0x26e5a8 ldr r4, [sp, #0xc0]
 *   @0x26e5ac ldr r12, [sp, #0xc4]
 *   @0x26e5b0 rsbs r2, r4, #1
 *   @0x26e5b4 movlo r2, #0
 *   @0x26e5b8 cmp r12, #0
 *   @0x26e5bc movle r2, #0
 *   @0x26e5c0 cmp r2, #0
 *   @0x26e5c4 bne 0x26e79c <pcre_dfa_exec+0x234>
 *   @0x26e5c8 cmp r12, #0
 *   @0x26e5cc blt 0x26f1bc <pcre_dfa_exec+0xc54>
 *   @0x26e5d0 ldr r4, [sp, #0xcc]
 *   @0x26e5d4 cmp r4, #19
 *   @0x26e5d8 ble 0x26f074 <pcre_dfa_exec+0xb0c>
 *   @0x26e5dc cmp r3, #0
 *   @0x26e5e0 blt 0x26f1d4 <pcre_dfa_exec+0xc6c>
 *   @0x26e5e4 ldr r12, [sp, #0xb8]
 *   @0x26e5e8 cmp r12, r3
 *   @0x26e5ec movle r2, #0
 *   @0x26e5f0 movgt r2, #1
 *   @0x26e5f4 orrs r12, r2, r12, lsr #31
 *   @0x26e5f8 bne 0x26f084 <pcre_dfa_exec+0xb1c>
 *   @0x26e5fc ldr r0, [r0]
 *   @0x26e600 movw r2, #0x5245
 *   @0x26e604 movt r2, #0x5043
 *   @0x26e608 cmp r0, r2
 *   @0x26e60c beq 0x26e62c <pcre_dfa_exec+0xc4>
 *   @0x26e610 movw r3, #0x4350
 *   @0x26e614 movt r3, #0x4552
 *   @0x26e618 cmp r0, r3
 *   @0x26e61c mvnne r0, #3
 *   @0x26e620 mvneq r0, #28
 *   @0x26e624 add sp, sp, #148
 *   @0x26e628 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x26e62c ldr r9, [r6, #0xc]
 *   @0x26e630 tst r9, #1
 *   @0x26e634 beq 0x26f1c4 <pcre_dfa_exec+0xc5c>
 *   @0x26e638 ldr r4, [sp, #0xbc]
 *   @0x26e63c ands r4, r4, #131072
 *   @0x26e640 str r4, [sp, #0x20]
 *   @0x26e644 beq 0x26e684 <pcre_dfa_exec+0x11c>
 *   @0x26e648 ldr r12, [sp, #0xc8]
 *   @0x26e64c ldr r2, [r12]
 *   @0x26e650 bics r0, r2, #1
 *   @0x26e654 bne 0x26f1dc <pcre_dfa_exec+0xc74>
 *   @0x26e658 ldr r2, [r12, #0x4]
 *   @0x26e65c cmp r2, #0
 *   @0x26e660 ble 0x26f1dc <pcre_dfa_exec+0xc74>
 *   @0x26e664 ldr r4, [sp, #0xcc]
 *   @0x26e668 movw r12, #0x5556
 *   @0x26e66c movt r12, #0x5555
 *   @0x26e670 sub r0, r4, #2
 *   @0x26e674 smull r4, r12, r12, r0
 *   @0x26e678 sub r0, r12, r0, asr #31
 *   @0x26e67c cmp r2, r0
 *   @0x26e680 bgt 0x26f1dc <pcre_dfa_exec+0xc74>
 *   @0x26e684 ldr r2, [r6, #0x30]
 *   @0x26e688 cmp r1, #0
 *   @0x26e68c mov r0, #0
 *   @0x26e690 str r0, [sp, #0x88]
 *   @0x26e694 str r2, [sp, #0x6c]
 *   @0x26e698 beq 0x26f03c <pcre_dfa_exec+0xad4>
 *   @0x26e69c ldr r2, [r1]
 *   @0x26e6a0 ands r0, r2, #1
 *   @0x26e6a4 streq r0, [sp, #0x38]
 *   @0x26e6a8 ldrne r12, [r1, #0x4]
 *   @0x26e6ac strne r12, [sp, #0x38]
 *   @0x26e6b0 tst r2, #18
 *   @0x26e6b4 bne 0x26f1cc <pcre_dfa_exec+0xc64>
 *   @0x26e6b8 tst r2, #4
 *   @0x26e6bc ldrne r0, [r1, #0xc]
 *   @0x26e6c0 strne r0, [sp, #0x88]
 *   @0x26e6c4 tst r2, #8
 *   @0x26e6c8 ldrne r2, [r1, #0x10]
 *   @0x26e6cc strne r2, [sp, #0x6c]
 *   @0x26e6d0 ldr r4, [sp, #0xbc]
 *   @0x26e6d4 mov r2, #16
 *   @0x26e6d8 movt r2, #0x2
 *   @0x26e6dc ldr r7, [r6, #0x8]
 *   @0x26e6e0 and r2, r4, r2
 *   @0x26e6e4 ldr r12, [sp, #0x24]
 *   @0x26e6e8 ldr r4, [sp, #0xb8]
 *   @0x26e6ec cmp r2, #0
 *   @0x26e6f0 ldrh r1, [r6, #38]
 *   @0x26e6f4 add r8, r12, r4
 *   @0x26e6f8 ubfx r12, r7, #0xb, #0x1
 *   @0x26e6fc str r12, [sp, #0x1c]
 *   @0x26e700 sub r4, r8, #1
 *   @0x26e704 ldr r12, [sp, #0x24]
 *   @0x26e708 str r4, [sp, #0x54]
 *   @0x26e70c ubfxeq r4, r7, #0x4, #0x1
 *   @0x26e710 add r5, r12, r3
 *   @0x26e714 ldr r12, [sp, #0xbc]
 *   @0x26e718 movne r4, #1
 *   @0x26e71c ldrh r0, [r6, #36]
 *   @0x26e720 tst r12, #25165824
 *   @0x26e724 ldr r12, [sp, #0x24]
 *   @0x26e728 ldrh r2, [r6, #34]
 *   @0x26e72c str r5, [sp, #0x64]
 *   @0x26e730 str r12, [sp, #0x60]
 *   @0x26e734 ldr r12, [sp, #0xb8]
 *   @0x26e738 mla r2, r0, r1, r2
 *   @0x26e73c str r7, [sp, #0x78]
 *   @0x26e740 str r12, [sp, #0x70]
 *   @0x26e744 ldr r12, [sp, #0xbc]
 *   @0x26e748 add r2, r6, r2
 *   @0x26e74c str r2, [sp, #0x5c]
 *   @0x26e750 str r12, [sp, #0x74]
 *   @0x26e754 bne 0x26e764 <pcre_dfa_exec+0x1fc>
 *   @0x26e758 ands r2, r7, #25165824
 *   @0x26e75c orrne r2, r12, r2
 *   @0x26e760 strne r2, [sp, #0x74]
 *   @0x26e764 ldr r12, [sp, #0xbc]
 *   @0x26e768 ands r2, r12, #7340032
 *   @0x26e76c andeq r2, r7, #7340032
 *   @0x26e770 cmp r2, #2097152
 *   @0x26e774 beq 0x26efdc <pcre_dfa_exec+0xa74>
 *   @0x26e778 bls 0x26e7a4 <pcre_dfa_exec+0x23c>
 *   @0x26e77c cmp r2, #4194304
 *   @0x26e780 beq 0x26f104 <pcre_dfa_exec+0xb9c>
 *   @0x26e784 cmp r2, #5242880
 *   @0x26e788 beq 0x26f0f8 <pcre_dfa_exec+0xb90>
 *   @0x26e78c cmp r2, #3145728
 *   @0x26e790 beq 0x26f044 <pcre_dfa_exec+0xadc>
 *   @0x26e794 mvn r0, #22
 *   @0x26e798 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26e79c mvn r0, #1
 *   @0x26e7a0 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26e7a4 cmp r2, #0
 *   @0x26e7a8 beq 0x26efdc <pcre_dfa_exec+0xa74>
 *   @0x26e7ac cmp r2, #1048576
 *   @0x26e7b0 moveq r2, #13
 *   @0x26e7b4 bne 0x26e794 <pcre_dfa_exec+0x22c>
 *   @0x26e7b8 cmp r2, #255
 *   @0x26e7bc mov r1, #0
 *   @0x26e7c0 str r1, [sp, #0x7c]
 *   @0x26e7c4 ble 0x26efe8 <pcre_dfa_exec+0xa80>
 *   @0x26e7c8 strb r2, [sp, #0x85]
 *   @0x26e7cc asr r2, r2, #8
 *   @0x26e7d0 strb r2, [sp, #0x84]
 *   @0x26e7d4 mov r2, #2
 *   @0x26e7d8 str r2, [sp, #0x80]
 *   @0x26e7dc ldr r12, [sp, #0x1c]
 *   @0x26e7e0 cmp r12, #0
 *   @0x26e7e4 beq 0x26e7f4 <pcre_dfa_exec+0x28c>
 *   @0x26e7e8 ldr r12, [sp, #0xbc]
 *   @0x26e7ec tst r12, #8192
 *   @0x26e7f0 beq 0x26f0a0 <pcre_dfa_exec+0xb38>
 *   @0x26e7f4 mov r3, r9
 *   @0x26e7f8 ldr r2, [sp, #0x6c]
 *   @0x26e7fc cmp r2, #0
 *   @0x26e800 beq 0x26f154 <pcre_dfa_exec+0xbec>
 *   @0x26e804 cmp r4, #0
 *   @0x26e808 ubfx r12, r3, #0x8, #0x1
 *   @0x26e80c ubfx r11, r7, #0x12, #0x1
 *   @0x26e810 str r12, [sp, #0x50]
 *   @0x26e814 bne 0x26e864 <pcre_dfa_exec+0x2fc>
 *   @0x26e818 tst r3, #16
 *   @0x26e81c bne 0x26f014 <pcre_dfa_exec+0xaac>
 *   @0x26e820 ldr r12, [sp, #0x50]
 *   @0x26e824 eor r2, r12, #1
 *   @0x26e828 ldr r12, [sp, #0x38]
 *   @0x26e82c cmp r12, #0
 *   @0x26e830 moveq r2, #0
 *   @0x26e834 andne r2, r2, #1
 *   @0x26e838 cmp r2, #0
 *   @0x26e83c beq 0x26f08c <pcre_dfa_exec+0xb24>
 *   @0x26e840 ldr r2, [r12, #0x4]
 *   @0x26e844 tst r2, #1
 *   @0x26e848 beq 0x26f08c <pcre_dfa_exec+0xb24>
 *   @0x26e84c add r12, r12, #8
 *   @0x26e850 mov r10, r4
 *   @0x26e854 str r12, [sp, #0x40]
 *   @0x26e858 mov r9, r4
 *   @0x26e85c str r4, [sp, #0x34]
 *   @0x26e860 b 0x26e874 <pcre_dfa_exec+0x30c>
 *   @0x26e864 mov r10, #0
 *   @0x26e868 str r10, [sp, #0x34]
 *   @0x26e86c mov r9, r10
 *   @0x26e870 str r10, [sp, #0x40]
 *   @0x26e874 ands r2, r3, #64
 *   @0x26e878 beq 0x26e8a8 <pcre_dfa_exec+0x340>
 *   @0x26e87c ldrb r12, [r6, #0x1a]
 *   @0x26e880 tst r3, #128
 *   @0x26e884 str r12, [sp, #0x44]
 *   @0x26e888 beq 0x26f000 <pcre_dfa_exec+0xa98>
 *   @0x26e88c ldr r2, [sp, #0x6c]
 *   @0x26e890 add r3, r12, #256
 *   @0x26e894 mov r12, #1
 *   @0x26e898 str r12, [sp, #0x4c]
 *   @0x26e89c ldrb r2, [r2, r3]
 *   @0x26e8a0 str r2, [sp, #0x48]
 *   @0x26e8a4 b 0x26e8b4 <pcre_dfa_exec+0x34c>
 *   @0x26e8a8 str r2, [sp, #0x48]
 *   @0x26e8ac str r2, [sp, #0x44]
 *   @0x26e8b0 str r2, [sp, #0x4c]
 *   @0x26e8b4 and r4, r4, #1
 *   @0x26e8b8 mov r3, r6
 *   @0x26e8bc str r4, [sp, #0x2c]
 *   @0x26e8c0 mov r12, #32768
 *   @0x26e8c4 ldr r4, [sp, #0xbc]
 *   @0x26e8c8 movt r12, #0x800
 *   @0x26e8cc mov r6, r8
 *   @0x26e8d0 mov r7, #0
 *   @0x26e8d4 mov r8, r3
 *   @0x26e8d8 and r12, r4, r12
 *   @0x26e8dc add r4, sp, #92
 *   @0x26e8e0 str r12, [sp, #0x3c]
 *   @0x26e8e4 str r4, [sp, #0x28]
 *   @0x26e8e8 add r12, sp, #128
 *   @0x26e8ec str r12, [sp, #0x30]
 *   @0x26e8f0 ldr r12, [sp, #0x20]
 *   @0x26e8f4 cmp r12, #0
 *   @0x26e8f8 bne 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26e8fc cmp r11, #0
 *   @0x26e900 moveq r4, r5
 *   @0x26e904 beq 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26e908 ldr r4, [sp, #0x1c]
 *   @0x26e90c ldr r2, [sp, #0x64]
 *   @0x26e910 cmp r4, #0
 *   @0x26e914 mov r4, r6
 *   @0x26e918 bne 0x26eac8 <pcre_dfa_exec+0x560>
 *   @0x26e91c cmp r6, r2
 *   @0x26e920 blo 0x26e93c <pcre_dfa_exec+0x3d4>
 *   @0x26e924 b 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26e928 cmp r2, r4
 *   @0x26e92c bhi 0x26ec64 <pcre_dfa_exec+0x6fc>
 *   @0x26e930 add r4, r4, #1
 *   @0x26e934 cmp r2, r4
 *   @0x26e938 bls 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26e93c ldr r1, [sp, #0x7c]
 *   @0x26e940 cmp r1, #0
 *   @0x26e944 bne 0x26e928 <pcre_dfa_exec+0x3c0>
 *   @0x26e948 ldr r3, [sp, #0x80]
 *   @0x26e94c rsb r1, r3, r2
 *   @0x26e950 cmp r4, r1
 *   @0x26e954 bhi 0x26e930 <pcre_dfa_exec+0x3c8>
 *   @0x26e958 ldrb r0, [r4]
 *   @0x26e95c ldrb r1, [sp, #0x84]
 *   @0x26e960 cmp r0, r1
 *   @0x26e964 bne 0x26e930 <pcre_dfa_exec+0x3c8>
 *   @0x26e968 cmp r3, #1
 *   @0x26e96c beq 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26e970 ldrb r1, [r4, #0x1]
 *   @0x26e974 ldrb r3, [sp, #0x85]
 *   @0x26e978 cmp r1, r3
 *   @0x26e97c bne 0x26e930 <pcre_dfa_exec+0x3c8>
 *   @0x26e980 ldr r3, [r8, #0x8]
 *   @0x26e984 ldr r12, [sp, #0xbc]
 *   @0x26e988 orr r3, r12, r3
 *   @0x26e98c ands r3, r3, #67108864
 *   @0x26e990 bne 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26e994 ldr r12, [sp, #0x34]
 *   @0x26e998 cmp r12, #0
 *   @0x26e99c beq 0x26ed14 <pcre_dfa_exec+0x7ac>
 *   @0x26e9a0 cmp r9, r10
 *   @0x26e9a4 beq 0x26ee74 <pcre_dfa_exec+0x90c>
 *   @0x26e9a8 cmp r6, r4
 *   @0x26e9ac bhs 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26e9b0 ldrb r3, [r6]
 *   @0x26e9b4 cmp r3, r9
 *   @0x26e9b8 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26e9bc cmp r3, r10
 *   @0x26e9c0 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26e9c4 add r3, r6, #1
 *   @0x26e9c8 b 0x26e9e0 <pcre_dfa_exec+0x478>
 *   @0x26e9cc ldrb r2, [r3], #1
 *   @0x26e9d0 cmp r2, r9
 *   @0x26e9d4 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26e9d8 cmp r2, r10
 *   @0x26e9dc beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26e9e0 cmp r3, r4
 *   @0x26e9e4 mov r6, r3
 *   @0x26e9e8 bne 0x26e9cc <pcre_dfa_exec+0x464>
 *   @0x26e9ec ldr r4, [sp, #0x3c]
 *   @0x26e9f0 cmp r4, #0
 *   @0x26e9f4 bne 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26e9f8 ldr r12, [sp, #0x38]
 *   @0x26e9fc cmp r12, #0
 *   @0x26ea00 beq 0x26ea20 <pcre_dfa_exec+0x4b8>
 *   @0x26ea04 ldr r3, [r12, #0x4]
 *   @0x26ea08 tst r3, #2
 *   @0x26ea0c beq 0x26ea20 <pcre_dfa_exec+0x4b8>
 *   @0x26ea10 ldr r3, [r12, #0x28]
 *   @0x26ea14 rsb r2, r6, r5
 *   @0x26ea18 cmp r2, r3
 *   @0x26ea1c blo 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26ea20 ldr r4, [sp, #0x4c]
 *   @0x26ea24 cmp r4, #0
 *   @0x26ea28 beq 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26ea2c rsb r3, r6, r5
 *   @0x26ea30 cmp r3, #1000
 *   @0x26ea34 bge 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26ea38 ldr r12, [sp, #0x34]
 *   @0x26ea3c ldr r4, [sp, #0x54]
 *   @0x26ea40 add r3, r6, r12
 *   @0x26ea44 cmp r4, r3
 *   @0x26ea48 bhs 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26ea4c ldr r12, [sp, #0x44]
 *   @0x26ea50 ldr r4, [sp, #0x48]
 *   @0x26ea54 cmp r12, r4
 *   @0x26ea58 beq 0x26f110 <pcre_dfa_exec+0xba8>
 *   @0x26ea5c cmp r5, r3
 *   @0x26ea60 bls 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26ea64 ldrb r2, [r3]
 *   @0x26ea68 add r1, r3, #1
 *   @0x26ea6c ldr r12, [sp, #0x44]
 *   @0x26ea70 cmp r12, r2
 *   @0x26ea74 beq 0x26eb80 <pcre_dfa_exec+0x618>
 *   @0x26ea78 ldr r4, [sp, #0x48]
 *   @0x26ea7c cmp r4, r2
 *   @0x26ea80 beq 0x26eb80 <pcre_dfa_exec+0x618>
 *   @0x26ea84 mov r0, r12
 *   @0x26ea88 mov r3, r1
 *   @0x26ea8c mov r12, r4
 *   @0x26ea90 b 0x26eaac <pcre_dfa_exec+0x544>
 *   @0x26ea94 ldrb r1, [r2], #1
 *   @0x26ea98 cmp r0, r1
 *   @0x26ea9c beq 0x26eb80 <pcre_dfa_exec+0x618>
 *   @0x26eaa0 cmp r1, r12
 *   @0x26eaa4 beq 0x26eb80 <pcre_dfa_exec+0x618>
 *   @0x26eaa8 mov r3, r2
 *   @0x26eaac cmp r3, r5
 *   @0x26eab0 mov r2, r3
 *   @0x26eab4 bne 0x26ea94 <pcre_dfa_exec+0x52c>
 *   @0x26eab8 mvn r0, #0
 *   @0x26eabc add sp, sp, #148
 *   @0x26eac0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x26eac4 mov r4, r3
 *   @0x26eac8 cmp r4, r2
 *   @0x26eacc bhs 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26ead0 ldr r1, [sp, #0x7c]
 *   @0x26ead4 cmp r1, #0
 *   @0x26ead8 beq 0x26eb40 <pcre_dfa_exec+0x5d8>
 *   @0x26eadc mov r12, #1
 *   @0x26eae0 mov r0, r4
 *   @0x26eae4 str r12, [sp]
 *   @0x26eae8 add r3, sp, #128
 *   @0x26eaec bl 0x25f9fc <_pcre_is_newline>
 *   @0x26eaf0 cmp r0, #0
 *   @0x26eaf4 bne 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26eaf8 ldr r2, [sp, #0x64]
 *   @0x26eafc add r3, r4, #1
 *   @0x26eb00 cmp r5, r3
 *   @0x26eb04 bls 0x26eac4 <pcre_dfa_exec+0x55c>
 *   @0x26eb08 ldrb r1, [r4, #0x1]
 *   @0x26eb0c and r1, r1, #192
 *   @0x26eb10 cmp r1, #128
 *   @0x26eb14 bne 0x26eac4 <pcre_dfa_exec+0x55c>
 *   @0x26eb18 add r3, r4, #2
 *   @0x26eb1c cmp r3, r5
 *   @0x26eb20 mov r4, r3
 *   @0x26eb24 add r3, r3, #1
 *   @0x26eb28 beq 0x26eac8 <pcre_dfa_exec+0x560>
 *   @0x26eb2c ldrb r1, [r4]
 *   @0x26eb30 and r1, r1, #192
 *   @0x26eb34 cmp r1, #128
 *   @0x26eb38 beq 0x26eb1c <pcre_dfa_exec+0x5b4>
 *   @0x26eb3c b 0x26eac8 <pcre_dfa_exec+0x560>
 *   @0x26eb40 ldr r3, [sp, #0x80]
 *   @0x26eb44 rsb r1, r3, r2
 *   @0x26eb48 cmp r4, r1
 *   @0x26eb4c bhi 0x26eafc <pcre_dfa_exec+0x594>
 *   @0x26eb50 ldrb r0, [r4]
 *   @0x26eb54 ldrb r1, [sp, #0x84]
 *   @0x26eb58 cmp r0, r1
 *   @0x26eb5c bne 0x26eafc <pcre_dfa_exec+0x594>
 *   @0x26eb60 cmp r3, #1
 *   @0x26eb64 beq 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26eb68 ldrb r1, [r4, #0x1]
 *   @0x26eb6c ldrb r3, [sp, #0x85]
 *   @0x26eb70 cmp r1, r3
 *   @0x26eb74 bne 0x26eafc <pcre_dfa_exec+0x594>
 *   @0x26eb78 b 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26eb7c mov r3, r2
 *   @0x26eb80 str r3, [sp, #0x54]
 *   @0x26eb84 ldr r12, [sp, #0xc0]
 *   @0x26eb88 add r0, sp, #92
 *   @0x26eb8c ldr r4, [sp, #0xc4]
 *   @0x26eb90 mov r2, r6
 *   @0x26eb94 ldr r3, [sp, #0xb8]
 *   @0x26eb98 str r12, [sp]
 *   @0x26eb9c str r4, [sp, #0x4]
 *   @0x26eba0 ldr r12, [sp, #0xc8]
 *   @0x26eba4 ldr r4, [sp, #0xcc]
 *   @0x26eba8 ldr r1, [sp, #0x5c]
 *   @0x26ebac str r12, [sp, #0x8]
 *   @0x26ebb0 str r4, [sp, #0xc]
 *   @0x26ebb4 str r7, [sp, #0x10]
 *   @0x26ebb8 str r6, [sp, #0x68]
 *   @0x26ebbc str r7, [sp, #0x8c]
 *   @0x26ebc0 bl 0x268fb4 <pcre_compile+0x2c>
 *   @0x26ebc4 ldr r12, [sp, #0x2c]
 *   @0x26ebc8 adds r3, r0, #1
 *   @0x26ebcc movne r3, #1
 *   @0x26ebd0 orrs r12, r3, r12
 *   @0x26ebd4 bne 0x26ef84 <pcre_dfa_exec+0xa1c>
 *   @0x26ebd8 cmp r11, #0
 *   @0x26ebdc beq 0x26ebf8 <pcre_dfa_exec+0x690>
 *   @0x26ebe0 ldr r1, [sp, #0x7c]
 *   @0x26ebe4 cmp r1, #0
 *   @0x26ebe8 beq 0x26ecc8 <pcre_dfa_exec+0x760>
 *   @0x26ebec ldr r2, [sp, #0x64]
 *   @0x26ebf0 cmp r6, r2
 *   @0x26ebf4 blo 0x26ee38 <pcre_dfa_exec+0x8d0>
 *   @0x26ebf8 ldr r12, [sp, #0x1c]
 *   @0x26ebfc add r3, r6, #1
 *   @0x26ec00 cmp r12, #0
 *   @0x26ec04 beq 0x26ec48 <pcre_dfa_exec+0x6e0>
 *   @0x26ec08 cmp r5, r3
 *   @0x26ec0c bls 0x26ec48 <pcre_dfa_exec+0x6e0>
 *   @0x26ec10 ldrb r2, [r6, #0x1]
 *   @0x26ec14 and r2, r2, #192
 *   @0x26ec18 cmp r2, #128
 *   @0x26ec1c bne 0x26ec48 <pcre_dfa_exec+0x6e0>
 *   @0x26ec20 add r12, r6, #2
 *   @0x26ec24 b 0x26ec38 <pcre_dfa_exec+0x6d0>
 *   @0x26ec28 ldrb r2, [r3]
 *   @0x26ec2c and r2, r2, #192
 *   @0x26ec30 cmp r2, #128
 *   @0x26ec34 bne 0x26ec48 <pcre_dfa_exec+0x6e0>
 *   @0x26ec38 cmp r12, r5
 *   @0x26ec3c mov r3, r12
 *   @0x26ec40 add r12, r12, #1
 *   @0x26ec44 bne 0x26ec28 <pcre_dfa_exec+0x6c0>
 *   @0x26ec48 cmp r3, r5
 *   @0x26ec4c bhi 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26ec50 ldrb r2, [r3, #-0x1]
 *   @0x26ec54 cmp r2, #13
 *   @0x26ec58 beq 0x26ec84 <pcre_dfa_exec+0x71c>
 *   @0x26ec5c mov r6, r3
 *   @0x26ec60 b 0x26e8f0 <pcre_dfa_exec+0x388>
 *   @0x26ec64 str r7, [sp]
 *   @0x26ec68 mov r0, r4
 *   @0x26ec6c add r3, sp, #128
 *   @0x26ec70 bl 0x25f9fc <_pcre_is_newline>
 *   @0x26ec74 cmp r0, #0
 *   @0x26ec78 bne 0x26e980 <pcre_dfa_exec+0x418>
 *   @0x26ec7c ldr r2, [sp, #0x64]
 *   @0x26ec80 b 0x26e930 <pcre_dfa_exec+0x3c8>
 *   @0x26ec84 cmp r3, r5
 *   @0x26ec88 bhs 0x26ec5c <pcre_dfa_exec+0x6f4>
 *   @0x26ec8c ldrb r2, [r3]
 *   @0x26ec90 cmp r2, #10
 *   @0x26ec94 bne 0x26ec5c <pcre_dfa_exec+0x6f4>
 *   @0x26ec98 ldr r2, [r8, #0xc]
 *   @0x26ec9c tst r2, #2048
 *   @0x26eca0 bne 0x26ec5c <pcre_dfa_exec+0x6f4>
 *   @0x26eca4 ldr r2, [sp, #0x7c]
 *   @0x26eca8 sub r2, r2, #1
 *   @0x26ecac cmp r2, #1
 *   @0x26ecb0 bls 0x26ecc0 <pcre_dfa_exec+0x758>
 *   @0x26ecb4 ldr r2, [sp, #0x80]
 *   @0x26ecb8 cmp r2, #2
 *   @0x26ecbc bne 0x26ec5c <pcre_dfa_exec+0x6f4>
 *   @0x26ecc0 add r3, r3, #1
 *   @0x26ecc4 b 0x26ec5c <pcre_dfa_exec+0x6f4>
 *   @0x26ecc8 ldr r3, [sp, #0x80]
 *   @0x26eccc ldr r2, [sp, #0x64]
 *   @0x26ecd0 rsb r2, r3, r2
 *   @0x26ecd4 cmp r6, r2
 *   @0x26ecd8 bhi 0x26ebf8 <pcre_dfa_exec+0x690>
 *   @0x26ecdc ldrb r1, [r6]
 *   @0x26ece0 ldrb r2, [sp, #0x84]
 *   @0x26ece4 cmp r1, r2
 *   @0x26ece8 bne 0x26ebf8 <pcre_dfa_exec+0x690>
 *   @0x26ecec cmp r3, #1
 *   @0x26ecf0 beq 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26ecf4 ldrb r0, [r6, #0x1]
 *   @0x26ecf8 ldrb r3, [sp, #0x85]
 *   @0x26ecfc subs r3, r0, r3
 *   @0x26ed00 rsbs r0, r3, #0
 *   @0x26ed04 adcs r0, r0, r3
 *   @0x26ed08 cmp r0, #0
 *   @0x26ed0c beq 0x26ebf8 <pcre_dfa_exec+0x690>
 *   @0x26ed10 b 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26ed14 ldr r12, [sp, #0x50]
 *   @0x26ed18 cmp r12, #0
 *   @0x26ed1c beq 0x26edd8 <pcre_dfa_exec+0x870>
 *   @0x26ed20 ldr r2, [sp, #0x60]
 *   @0x26ed24 ldr r12, [sp, #0xb8]
 *   @0x26ed28 add r1, r2, r12
 *   @0x26ed2c cmp r6, r1
 *   @0x26ed30 bls 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ed34 ldr r12, [sp, #0x1c]
 *   @0x26ed38 cmp r12, #0
 *   @0x26ed3c bne 0x26eeb0 <pcre_dfa_exec+0x948>
 *   @0x26ed40 cmp r6, r4
 *   @0x26ed44 blo 0x26ed64 <pcre_dfa_exec+0x7fc>
 *   @0x26ed48 b 0x26edc0 <pcre_dfa_exec+0x858>
 *   @0x26ed4c cmp r6, r2
 *   @0x26ed50 bhi 0x26ee58 <pcre_dfa_exec+0x8f0>
 *   @0x26ed54 add r6, r6, #1
 *   @0x26ed58 cmp r6, r4
 *   @0x26ed5c beq 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ed60 ldr r2, [sp, #0x60]
 *   @0x26ed64 ldr r1, [sp, #0x7c]
 *   @0x26ed68 cmp r1, #0
 *   @0x26ed6c bne 0x26ed4c <pcre_dfa_exec+0x7e4>
 *   @0x26ed70 ldr r3, [sp, #0x80]
 *   @0x26ed74 add r2, r2, r3
 *   @0x26ed78 rsb r1, r3, r6
 *   @0x26ed7c cmp r6, r2
 *   @0x26ed80 blo 0x26ed54 <pcre_dfa_exec+0x7ec>
 *   @0x26ed84 ldrb r1, [r1]
 *   @0x26ed88 ldrb r2, [sp, #0x84]
 *   @0x26ed8c cmp r1, r2
 *   @0x26ed90 bne 0x26ed54 <pcre_dfa_exec+0x7ec>
 *   @0x26ed94 cmp r3, #1
 *   @0x26ed98 rsb r2, r3, #1
 *   @0x26ed9c beq 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26eda0 ldrb r2, [r6, r2]
 *   @0x26eda4 ldrb r3, [sp, #0x85]
 *   @0x26eda8 cmp r2, r3
 *   @0x26edac bne 0x26ed54 <pcre_dfa_exec+0x7ec>
 *   @0x26edb0 ldr r3, [r8, #0x8]
 *   @0x26edb4 ldr r12, [sp, #0xbc]
 *   @0x26edb8 orr r3, r12, r3
 *   @0x26edbc and r3, r3, #67108864
 *   @0x26edc0 ldrb r2, [r6, #-0x1]
 *   @0x26edc4 cmp r2, #13
 *   @0x26edc8 beq 0x26f04c <pcre_dfa_exec+0xae4>
 *   @0x26edcc cmp r3, #0
 *   @0x26edd0 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26edd4 b 0x26eb84 <pcre_dfa_exec+0x61c>
 *   @0x26edd8 ldr r12, [sp, #0x40]
 *   @0x26eddc cmp r12, #0
 *   @0x26ede0 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ede4 cmp r6, r4
 *   @0x26ede8 bhs 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26edec ldrb r3, [r6]
 *   @0x26edf0 and r2, r3, #7
 *   @0x26edf4 ldrb r3, [r12, r3, lsr #3]
 *   @0x26edf8 asr r3, r3, r2
 *   @0x26edfc tst r3, #1
 *   @0x26ee00 bne 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee04 add r3, r6, #1
 *   @0x26ee08 mov r0, r12
 *   @0x26ee0c b 0x26ee28 <pcre_dfa_exec+0x8c0>
 *   @0x26ee10 ldrb r2, [r3], #1
 *   @0x26ee14 and r1, r2, #7
 *   @0x26ee18 ldrb r2, [r0, r2, lsr #3]
 *   @0x26ee1c asr r2, r2, r1
 *   @0x26ee20 tst r2, #1
 *   @0x26ee24 bne 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee28 cmp r3, r4
 *   @0x26ee2c mov r6, r3
 *   @0x26ee30 bne 0x26ee10 <pcre_dfa_exec+0x8a8>
 *   @0x26ee34 b 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee38 ldr r4, [sp, #0x1c]
 *   @0x26ee3c mov r0, r6
 *   @0x26ee40 add r3, sp, #128
 *   @0x26ee44 str r4, [sp]
 *   @0x26ee48 bl 0x25f9fc <_pcre_is_newline>
 *   @0x26ee4c adds r0, r0, #0
 *   @0x26ee50 movne r0, #1
 *   @0x26ee54 b 0x26ed08 <pcre_dfa_exec+0x7a0>
 *   @0x26ee58 str r7, [sp]
 *   @0x26ee5c mov r0, r6
 *   @0x26ee60 add r3, sp, #128
 *   @0x26ee64 bl 0x25fbc0 <_pcre_was_newline>
 *   @0x26ee68 cmp r0, #0
 *   @0x26ee6c beq 0x26ed54 <pcre_dfa_exec+0x7ec>
 *   @0x26ee70 b 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ee74 cmp r6, r4
 *   @0x26ee78 bhs 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee7c ldrb r3, [r6]
 *   @0x26ee80 cmp r3, r9
 *   @0x26ee84 addne r3, r6, #1
 *   @0x26ee88 bne 0x26ee9c <pcre_dfa_exec+0x934>
 *   @0x26ee8c b 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee90 ldrb r2, [r6]
 *   @0x26ee94 cmp r2, r9
 *   @0x26ee98 beq 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26ee9c cmp r3, r4
 *   @0x26eea0 mov r6, r3
 *   @0x26eea4 add r3, r3, #1
 *   @0x26eea8 bne 0x26ee90 <pcre_dfa_exec+0x928>
 *   @0x26eeac b 0x26e9ec <pcre_dfa_exec+0x484>
 *   @0x26eeb0 cmp r6, r4
 *   @0x26eeb4 bhs 0x26edc0 <pcre_dfa_exec+0x858>
 *   @0x26eeb8 ldr r1, [sp, #0x7c]
 *   @0x26eebc cmp r1, #0
 *   @0x26eec0 beq 0x26ef14 <pcre_dfa_exec+0x9ac>
 *   @0x26eec4 cmp r6, r2
 *   @0x26eec8 bhi 0x26ef64 <pcre_dfa_exec+0x9fc>
 *   @0x26eecc add r3, r6, #1
 *   @0x26eed0 cmp r4, r3
 *   @0x26eed4 bls 0x26eff8 <pcre_dfa_exec+0xa90>
 *   @0x26eed8 ldrb r2, [r6, #0x1]
 *   @0x26eedc and r2, r2, #192
 *   @0x26eee0 cmp r2, #128
 *   @0x26eee4 bne 0x26ef58 <pcre_dfa_exec+0x9f0>
 *   @0x26eee8 add r3, r6, #2
 *   @0x26eeec b 0x26ef00 <pcre_dfa_exec+0x998>
 *   @0x26eef0 ldrb r2, [r6]
 *   @0x26eef4 and r2, r2, #192
 *   @0x26eef8 cmp r2, #128
 *   @0x26eefc bne 0x26ef5c <pcre_dfa_exec+0x9f4>
 *   @0x26ef00 cmp r3, r4
 *   @0x26ef04 mov r6, r3
 *   @0x26ef08 add r3, r3, #1
 *   @0x26ef0c bne 0x26eef0 <pcre_dfa_exec+0x988>
 *   @0x26ef10 b 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ef14 ldr r3, [sp, #0x80]
 *   @0x26ef18 add r2, r2, r3
 *   @0x26ef1c cmp r6, r2
 *   @0x26ef20 blo 0x26eecc <pcre_dfa_exec+0x964>
 *   @0x26ef24 rsb r1, r3, r6
 *   @0x26ef28 ldrb r2, [sp, #0x84]
 *   @0x26ef2c ldrb r1, [r1]
 *   @0x26ef30 cmp r1, r2
 *   @0x26ef34 bne 0x26eecc <pcre_dfa_exec+0x964>
 *   @0x26ef38 cmp r3, #1
 *   @0x26ef3c beq 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ef40 rsb r3, r3, #1
 *   @0x26ef44 ldrb r2, [sp, #0x85]
 *   @0x26ef48 ldrb r3, [r6, r3]
 *   @0x26ef4c cmp r3, r2
 *   @0x26ef50 bne 0x26eecc <pcre_dfa_exec+0x964>
 *   @0x26ef54 b 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ef58 mov r6, r3
 *   @0x26ef5c ldr r2, [sp, #0x60]
 *   @0x26ef60 b 0x26eeb8 <pcre_dfa_exec+0x950>
 *   @0x26ef64 mov r0, #1
 *   @0x26ef68 add r3, sp, #128
 *   @0x26ef6c str r0, [sp]
 *   @0x26ef70 mov r0, r6
 *   @0x26ef74 bl 0x25fbc0 <_pcre_was_newline>
 *   @0x26ef78 cmp r0, #0
 *   @0x26ef7c beq 0x26eecc <pcre_dfa_exec+0x964>
 *   @0x26ef80 b 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26ef84 ldr r4, [sp, #0xc4]
 *   @0x26ef88 cmp r4, #1
 *   @0x26ef8c movle r3, #0
 *   @0x26ef90 movgt r3, #1
 *   @0x26ef94 cmn r0, #12
 *   @0x26ef98 movne r3, #0
 *   @0x26ef9c cmp r3, #0
 *   @0x26efa0 beq 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26efa4 cmp r4, #2
 *   @0x26efa8 ldr r4, [sp, #0xc0]
 *   @0x26efac ldr r12, [sp, #0x24]
 *   @0x26efb0 ldr r3, [sp, #0x68]
 *   @0x26efb4 mvneq r0, #11
 *   @0x26efb8 rsb r5, r12, r5
 *   @0x26efbc str r5, [r4, #0x4]
 *   @0x26efc0 rsb r3, r12, r3
 *   @0x26efc4 str r3, [r4]
 *   @0x26efc8 ldrne r4, [sp, #0xc0]
 *   @0x26efcc rsbne r12, r12, r6
 *   @0x26efd0 mvnne r0, #11
 *   @0x26efd4 strne r12, [r4, #0x8]
 *   @0x26efd8 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26efdc mov r2, #0
 *   @0x26efe0 str r2, [sp, #0x7c]
 *   @0x26efe4 mov r2, #10
 *   @0x26efe8 strb r2, [sp, #0x84]
 *   @0x26efec mov r2, #1
 *   @0x26eff0 str r2, [sp, #0x80]
 *   @0x26eff4 b 0x26e7dc <pcre_dfa_exec+0x274>
 *   @0x26eff8 mov r6, r3
 *   @0x26effc b 0x26edb0 <pcre_dfa_exec+0x848>
 *   @0x26f000 ldr r12, [sp, #0x44]
 *   @0x26f004 str r12, [sp, #0x48]
 *   @0x26f008 mov r12, #1
 *   @0x26f00c str r12, [sp, #0x4c]
 *   @0x26f010 b 0x26e8b4 <pcre_dfa_exec+0x34c>
 *   @0x26f014 tst r3, #32
 *   @0x26f018 ldrb r9, [r6, #0x18]
 *   @0x26f01c beq 0x26f164 <pcre_dfa_exec+0xbfc>
 *   @0x26f020 ldr r1, [sp, #0x6c]
 *   @0x26f024 add r2, r9, #256
 *   @0x26f028 mov r12, #1
 *   @0x26f02c str r4, [sp, #0x40]
 *   @0x26f030 str r12, [sp, #0x34]
 *   @0x26f034 ldrb r10, [r1, r2]
 *   @0x26f038 b 0x26e874 <pcre_dfa_exec+0x30c>
 *   @0x26f03c str r1, [sp, #0x38]
 *   @0x26f040 b 0x26e6d0 <pcre_dfa_exec+0x168>
 *   @0x26f044 movw r2, #0xd0a
 *   @0x26f048 b 0x26e7b8 <pcre_dfa_exec+0x250>
 *   @0x26f04c ldr r2, [sp, #0x7c]
 *   @0x26f050 sub r2, r2, #1
 *   @0x26f054 cmp r2, #1
 *   @0x26f058 bhi 0x26edcc <pcre_dfa_exec+0x864>
 *   @0x26f05c cmp r6, r4
 *   @0x26f060 bhs 0x26edcc <pcre_dfa_exec+0x864>
 *   @0x26f064 ldrb r2, [r6]
 *   @0x26f068 cmp r2, #10
 *   @0x26f06c addeq r6, r6, #1
 *   @0x26f070 b 0x26edcc <pcre_dfa_exec+0x864>
 *   @0x26f074 mvn r0, #18
 *   @0x26f078 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f07c mvn r0, #2
 *   @0x26f080 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f084 mvn r0, #23
 *   @0x26f088 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f08c mov r10, r4
 *   @0x26f090 mov r9, r4
 *   @0x26f094 str r4, [sp, #0x34]
 *   @0x26f098 str r4, [sp, #0x40]
 *   @0x26f09c b 0x26e874 <pcre_dfa_exec+0x30c>
 *   @0x26f0a0 mov r1, r3
 *   @0x26f0a4 ldr r0, [sp, #0x24]
 *   @0x26f0a8 add r2, sp, #88
 *   @0x26f0ac str r3, [sp, #0x18]
 *   @0x26f0b0 bl 0x2668f4 <_pcre_valid_utf>
 *   @0x26f0b4 ldr r3, [sp, #0x18]
 *   @0x26f0b8 cmp r0, #0
 *   @0x26f0bc beq 0x26f178 <pcre_dfa_exec+0xc10>
 *   @0x26f0c0 ldr r4, [sp, #0xc4]
 *   @0x26f0c4 cmp r4, #1
 *   @0x26f0c8 ldrgt r12, [sp, #0xc0]
 *   @0x26f0cc ldrgt r3, [sp, #0x58]
 *   @0x26f0d0 strgt r0, [r12, #0x4]
 *   @0x26f0d4 strgt r3, [r12]
 *   @0x26f0d8 cmp r0, #5
 *   @0x26f0dc mvngt r0, #9
 *   @0x26f0e0 bgt 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f0e4 ldr r4, [sp, #0xbc]
 *   @0x26f0e8 tst r4, #134217728
 *   @0x26f0ec mvnne r0, #24
 *   @0x26f0f0 mvneq r0, #9
 *   @0x26f0f4 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f0f8 mov r2, #2
 *   @0x26f0fc str r2, [sp, #0x7c]
 *   @0x26f100 b 0x26e7dc <pcre_dfa_exec+0x274>
 *   @0x26f104 mov r2, #1
 *   @0x26f108 str r2, [sp, #0x7c]
 *   @0x26f10c b 0x26e7dc <pcre_dfa_exec+0x274>
 *   @0x26f110 cmp r5, r3
 *   @0x26f114 bls 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26f118 ldrb r1, [r3]
 *   @0x26f11c add r2, r3, #1
 *   @0x26f120 ldr r4, [sp, #0x44]
 *   @0x26f124 cmp r1, r4
 *   @0x26f128 bne 0x26f144 <pcre_dfa_exec+0xbdc>
 *   @0x26f12c b 0x26eb80 <pcre_dfa_exec+0x618>
 *   @0x26f130 ldrb r1, [r3], #1
 *   @0x26f134 ldr r12, [sp, #0x44]
 *   @0x26f138 cmp r1, r12
 *   @0x26f13c beq 0x26eb7c <pcre_dfa_exec+0x614>
 *   @0x26f140 mov r2, r3
 *   @0x26f144 cmp r2, r5
 *   @0x26f148 mov r3, r2
 *   @0x26f14c bne 0x26f130 <pcre_dfa_exec+0xbc8>
 *   @0x26f150 b 0x26eab8 <pcre_dfa_exec+0x550>
 *   @0x26f154 ldr r2, [pc, #0x88]
 *   @0x26f158 ldr r2, [pc, r2]
 *   @0x26f15c str r2, [sp, #0x6c]
 *   @0x26f160 b 0x26e804 <pcre_dfa_exec+0x29c>
 *   @0x26f164 mov r12, #1
 *   @0x26f168 mov r10, r9
 *   @0x26f16c str r12, [sp, #0x34]
 *   @0x26f170 str r4, [sp, #0x40]
 *   @0x26f174 b 0x26e874 <pcre_dfa_exec+0x30c>
 *   @0x26f178 ldr r12, [sp, #0xb8]
 *   @0x26f17c cmp r12, r3
 *   @0x26f180 movge r3, #0
 *   @0x26f184 movlt r3, #1
 *   @0x26f188 cmp r12, #0
 *   @0x26f18c movle r3, #0
 *   @0x26f190 cmp r3, #0
 *   @0x26f194 beq 0x26f1b0 <pcre_dfa_exec+0xc48>
 *   @0x26f198 ldr r0, [sp, #0x24]
 *   @0x26f19c ldrb r3, [r0, r12]
 *   @0x26f1a0 and r3, r3, #192
 *   @0x26f1a4 cmp r3, #128
 *   @0x26f1a8 mvneq r0, #10
 *   @0x26f1ac beq 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1b0 ldr r3, [r6, #0xc]
 *   @0x26f1b4 ldr r7, [r6, #0x8]
 *   @0x26f1b8 b 0x26e7f8 <pcre_dfa_exec+0x290>
 *   @0x26f1bc mvn r0, #14
 *   @0x26f1c0 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1c4 mvn r0, #27
 *   @0x26f1c8 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1cc mvn r0, #17
 *   @0x26f1d0 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1d4 mvn r0, #31
 *   @0x26f1d8 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1dc mvn r0, #29
 *   @0x26f1e0 b 0x26e624 <pcre_dfa_exec+0xbc>
 *   @0x26f1e4 mulseq r8, r0, r6
 *
 * ══ §6/13 anon_229e24  0x229e24  size 3160  790 条（0x229e24..0x22aa7c）
 * @func 0x229e24 0x22aa7c  size 3160  790 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×12 / 0xb65b0×4 / 0xb66dc×4 / anon_229e24+0x914×4 / __divsi3×2 / vorbis_book_decode×2 / anon_229e24+0x61c×2 / 0xb6c34×2
 * 字段偏移 top8: 0x4×40 / 0xc×21 / 0x2×17 / 0x1c×17 / 0x14×15 / 0x8×14 / 0x10×11 / 0x18×9
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x229e24 push {r4, lr}
 *   @0x229e28 subs r4, r2, #0
 *   @0x229e2c sub sp, sp, #24
 *   @0x229e30 mov r12, r1
 *   @0x229e34 ldr lr, [r1, #0x10]
 *   @0x229e38 beq 0x229e7c <vorbis_lsp_to_curve+0x5d0>
 *   @0x229e3c ldr r2, [r1, #0x8]
 *   @0x229e40 mov r0, r3
 *   @0x229e44 str r4, [sp]
 *   @0x229e48 ldr r1, [r1, #0xc]
 *   @0x229e4c str r2, [sp, #0x4]
 *   @0x229e50 ldr r4, [r4, r2, lsl #2]
 *   @0x229e54 ldm r12, {r2, r3}
 *   @0x229e58 str r4, [sp, #0x8]
 *   @0x229e5c ldr r4, [r12, #0x14]
 *   @0x229e60 ldr r12, [lr, #0x10]
 *   @0x229e64 str r4, [sp, #0x10]
 *   @0x229e68 str r12, [sp, #0xc]
 *   @0x229e6c bl 0x2298ac <vorbis_lsp_to_curve>
 *   @0x229e70 mov r0, #1
 *   @0x229e74 add sp, sp, #24
 *   @0x229e78 pop {r4, pc}
 *   @0x229e7c ldr r2, [r1]
 *   @0x229e80 mov r0, r3
 *   @0x229e84 mov r1, r4
 *   @0x229e88 lsl r2, r2, #2
 *   @0x229e8c bl 0xb65b0 <memset@plt>
 *   @0x229e90 mov r0, r4
 *   @0x229e94 add sp, sp, #24
 *   @0x229e98 pop {r4, pc}
 *   @0x229e9c ldr r3, [r0]
 *   @0x229ea0 ldr r2, [r1]
 *   @0x229ea4 ldr r0, [r3]
 *   @0x229ea8 ldr r3, [r2]
 *   @0x229eac rsb r0, r3, r0
 *   @0x229eb0 bx lr
 *   @0x229eb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x229eb8 sub sp, sp, #44
 *   @0x229ebc cmp r2, #0
 *   @0x229ec0 str r1, [sp, #0x18]
 *   @0x229ec4 str r3, [sp, #0x14]
 *   @0x229ec8 ldr r3, [sp, #0x18]
 *   @0x229ecc str r2, [sp, #0x8]
 *   @0x229ed0 ldr r2, [r0, #0x40]
 *   @0x229ed4 ldr r3, [r3, #0x308]
 *   @0x229ed8 ldr r1, [r0, #0x1c]
 *   @0x229edc str r3, [sp, #0x10]
 *   @0x229ee0 ldr r3, [r2, #0x4]
 *   @0x229ee4 ldr r3, [r3, #0x1c]
 *   @0x229ee8 ldr r3, [r3, r1, lsl #2]
 *   @0x229eec add r3, r3, r3, lsr #31
 *   @0x229ef0 asr r3, r3, #1
 *   @0x229ef4 str r3, [sp, #0x1c]
 *   @0x229ef8 beq 0x22a0e0 <vorbis_lsp_to_curve+0x834>
 *   @0x229efc ldr r12, [sp, #0x8]
 *   @0x229f00 ldr r2, [sp, #0x10]
 *   @0x229f04 ldr r3, [r12]
 *   @0x229f08 ldr r4, [r2, #0x340]
 *   @0x229f0c ldr r12, [sp, #0x18]
 *   @0x229f10 mul r4, r4, r3
 *   @0x229f14 ldr r1, [r12, #0x2fc]
 *   @0x229f18 cmp r1, #1
 *   @0x229f1c usat r4, #0x8, r4
 *   @0x229f20 ble 0x22a0fc <vorbis_lsp_to_curve+0x850>
 *   @0x229f24 ldr r7, [pc, #0x1dc]
 *   @0x229f28 mov r10, #0
 *   @0x229f2c ldr r2, [pc, #0x1d8]
 *   @0x229f30 mov r8, r12
 *   @0x229f34 ldr r3, [sp, #0x14]
 *   @0x229f38 add r7, pc, r7
 *   @0x229f3c add r2, pc, r2
 *   @0x229f40 str r10, [sp, #0x4]
 *   @0x229f44 sub r3, r3, #4
 *   @0x229f48 str r2, [sp, #0x24]
 *   @0x229f4c str r3, [sp, #0x20]
 *   @0x229f50 mov r6, #1
 *   @0x229f54 b 0x229f64 <vorbis_lsp_to_curve+0x6b8>
 *   @0x229f58 add r6, r6, #1
 *   @0x229f5c cmp r1, r6
 *   @0x229f60 ble 0x22a088 <vorbis_lsp_to_curve+0x7dc>
 *   @0x229f64 ldr r2, [r8, #0x4]!
 *   @0x229f68 ldr r12, [sp, #0x8]
 *   @0x229f6c ldr r3, [r12, r2, lsl #2]
 *   @0x229f70 ubfx r0, r3, #0x0, #0xf
 *   @0x229f74 cmp r3, r0
 *   @0x229f78 bne 0x229f58 <vorbis_lsp_to_curve+0x6ac>
 *   @0x229f7c ldr r12, [sp, #0x10]
 *   @0x229f80 add r2, r12, r2, lsl #2
 *   @0x229f84 ldr r1, [r12, #0x340]
 *   @0x229f88 ldr r2, [r2, #0x344]
 *   @0x229f8c mul r3, r1, r3
 *   @0x229f90 rsb r5, r10, r2
 *   @0x229f94 str r2, [sp, #0x4]
 *   @0x229f98 mov r1, r5
 *   @0x229f9c usat r3, #0x8, r3
 *   @0x229fa0 str r3, [sp, #0xc]
 *   @0x229fa4 rsb r9, r4, r3
 *   @0x229fa8 eor r3, r9, r9, asr #31
 *   @0x229fac sub r3, r3, r9, asr #31
 *   @0x229fb0 str r3, [sp]
 *   @0x229fb4 mov r0, r9
 *   @0x229fb8 bl 0x318d10 <__divsi3>
 *   @0x229fbc ldr r11, [sp, #0x4]
 *   @0x229fc0 ldr r2, [sp, #0x1c]
 *   @0x229fc4 cmp r9, #0
 *   @0x229fc8 ldr r3, [sp]
 *   @0x229fcc mul r1, r0, r5
 *   @0x229fd0 sublt r9, r0, #1
 *   @0x229fd4 addge r9, r0, #1
 *   @0x229fd8 cmp r11, r2
 *   @0x229fdc movge r11, r2
 *   @0x229fe0 cmp r1, #0
 *   @0x229fe4 rsblt r1, r1, #0
 *   @0x229fe8 cmp r11, r10
 *   @0x229fec rsb r1, r1, r3
 *   @0x229ff0 ble 0x22a018 <vorbis_lsp_to_curve+0x76c>
 *   @0x229ff4 ldr r3, [sp, #0x14]
 *   @0x229ff8 ldr r12, [sp, #0x24]
 *   @0x229ffc ldr r2, [r3, r10, lsl #2]
 *   @0x22a000 ldr r3, [r12, r4, lsl #2]
 *   @0x22a004 smull r2, r3, r2, r3
 *   @0x22a008 lsr r2, r2, #15
 *   @0x22a00c orr r2, r2, r3, lsl #17
 *   @0x22a010 ldr r3, [sp, #0x14]
 *   @0x22a014 str r2, [r3, r10, lsl #2]
 *   @0x22a018 add r3, r10, #1
 *   @0x22a01c cmp r11, r3
 *   @0x22a020 ble 0x22a0cc <vorbis_lsp_to_curve+0x820>
 *   @0x22a024 ldr r2, [sp, #0x20]
 *   @0x22a028 ldr r12, [sp, #0x14]
 *   @0x22a02c add r11, r2, r11, lsl #2
 *   @0x22a030 add r10, r12, r10, lsl #2
 *   @0x22a034 mov r12, #0
 *   @0x22a038 add r12, r12, r1
 *   @0x22a03c ldr r2, [r10, #0x4]
 *   @0x22a040 cmp r5, r12
 *   @0x22a044 addle r4, r4, r9
 *   @0x22a048 addgt r4, r4, r0
 *   @0x22a04c rsble r12, r5, r12
 *   @0x22a050 ldr r3, [r7, r4, lsl #2]
 *   @0x22a054 smull r2, r3, r2, r3
 *   @0x22a058 lsr r2, r2, #15
 *   @0x22a05c orr r3, r2, r3, lsl #17
 *   @0x22a060 str r3, [r10, #0x4]!
 *   @0x22a064 cmp r10, r11
 *   @0x22a068 bne 0x22a038 <vorbis_lsp_to_curve+0x78c>
 *   @0x22a06c ldr r2, [sp, #0x18]
 *   @0x22a070 add r6, r6, #1
 *   @0x22a074 ldr r4, [sp, #0xc]
 *   @0x22a078 ldr r10, [sp, #0x4]
 *   @0x22a07c ldr r1, [r2, #0x2fc]
 *   @0x22a080 cmp r1, r6
 *   @0x22a084 bgt 0x229f64 <vorbis_lsp_to_curve+0x6b8>
 *   @0x22a088 ldr r12, [sp, #0x1c]
 *   @0x22a08c ldr r2, [sp, #0x4]
 *   @0x22a090 cmp r12, r2
 *   @0x22a094 ble 0x22a0c0 <vorbis_lsp_to_curve+0x814>
 *   @0x22a098 ldr r2, [sp, #0x4]
 *   @0x22a09c ldr r12, [sp, #0x14]
 *   @0x22a0a0 add r3, r12, r2, lsl #2
 *   @0x22a0a4 ldr r2, [sp, #0x1c]
 *   @0x22a0a8 add r1, r12, r2, lsl #2
 *   @0x22a0ac ldr r2, [r3]
 *   @0x22a0b0 mul r2, r4, r2
 *   @0x22a0b4 str r2, [r3], #4
 *   @0x22a0b8 cmp r3, r1
 *   @0x22a0bc bne 0x22a0ac <vorbis_lsp_to_curve+0x800>
 *   @0x22a0c0 mov r0, #1
 *   @0x22a0c4 add sp, sp, #44
 *   @0x22a0c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22a0cc ldr r12, [sp, #0x18]
 *   @0x22a0d0 ldr r4, [sp, #0xc]
 *   @0x22a0d4 ldr r10, [sp, #0x4]
 *   @0x22a0d8 ldr r1, [r12, #0x2fc]
 *   @0x22a0dc b 0x229f58 <vorbis_lsp_to_curve+0x6ac>
 *   @0x22a0e0 ldr r3, [sp, #0x1c]
 *   @0x22a0e4 ldr r0, [sp, #0x14]
 *   @0x22a0e8 ldr r1, [sp, #0x8]
 *   @0x22a0ec lsl r2, r3, #2
 *   @0x22a0f0 bl 0xb65b0 <memset@plt>
 *   @0x22a0f4 ldr r0, [sp, #0x8]
 *   @0x22a0f8 b 0x22a0c4 <vorbis_lsp_to_curve+0x818>
 *   @0x22a0fc mov r3, #0
 *   @0x22a100 str r3, [sp, #0x4]
 *   @0x22a104 b 0x22a088 <vorbis_lsp_to_curve+0x7dc>
 *   @0x22a108 andseq r4, r3, r8, ror #14
 *   @0x22a10c andseq r4, r3, r4, ror #14
 *   @0x22a110 ldr r3, [r0, #0x40]
 *   @0x22a114 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22a118 sub sp, sp, #36
 *   @0x22a11c ldr r3, [r3, #0x4]
 *   @0x22a120 add r9, r0, #4
 *   @0x22a124 str r1, [sp, #0x14]
 *   @0x22a128 mov r4, r0
 *   @0x22a12c ldr r2, [sp, #0x14]
 *   @0x22a130 mov r0, r9
 *   @0x22a134 ldr r3, [r3, #0x1c]
 *   @0x22a138 mov r1, #1
 *   @0x22a13c ldr r7, [r2, #0x308]
 *   @0x22a140 ldr r10, [r3, #0xc20]
 *   @0x22a144 bl 0x233b28 <oggpack_read>
 *   @0x22a148 cmp r0, #1
 *   @0x22a14c bne 0x22a424 <vorbis_lsp_to_curve+0xb78>
 *   @0x22a150 ldr r3, [sp, #0x14]
 *   @0x22a154 mov r0, r4
 *   @0x22a158 ldr r1, [r3, #0x2fc]
 *   @0x22a15c lsl r1, r1, #2
 *   @0x22a160 bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x22a164 ldr r2, [sp, #0x14]
 *   @0x22a168 ldr r3, [r2, #0x304]
 *   @0x22a16c subs r3, r3, #1
 *   @0x22a170 str r0, [sp, #0x1c]
 *   @0x22a174 beq 0x22a430 <vorbis_lsp_to_curve+0xb84>
 *   @0x22a178 mov r1, #0
 *   @0x22a17c lsrs r3, r3, #1
 *   @0x22a180 add r1, r1, #1
 *   @0x22a184 bne 0x22a17c <vorbis_lsp_to_curve+0x8d0>
 *   @0x22a188 mov r0, r9
 *   @0x22a18c bl 0x233b28 <oggpack_read>
 *   @0x22a190 ldr r3, [sp, #0x1c]
 *   @0x22a194 ldr r2, [sp, #0x14]
 *   @0x22a198 str r0, [r3]
 *   @0x22a19c ldr r3, [r2, #0x304]
 *   @0x22a1a0 subs r3, r3, #1
 *   @0x22a1a4 beq 0x22a438 <vorbis_lsp_to_curve+0xb8c>
 *   @0x22a1a8 mov r1, #0
 *   @0x22a1ac lsrs r3, r3, #1
 *   @0x22a1b0 add r1, r1, #1
 *   @0x22a1b4 bne 0x22a1ac <vorbis_lsp_to_curve+0x900>
 *   @0x22a1b8 mov r0, r9
 *   @0x22a1bc bl 0x233b28 <oggpack_read>
 *   @0x22a1c0 ldr r3, [sp, #0x1c]
 *   @0x22a1c4 str r0, [r3, #0x4]
 *   @0x22a1c8 ldr r3, [r7]
 *   @0x22a1cc cmp r3, #0
 *   @0x22a1d0 ble 0x22a2dc <vorbis_lsp_to_curve+0xa30>
 *   @0x22a1d4 mov r3, #0
 *   @0x22a1d8 mov r2, #2
 *   @0x22a1dc str r3, [sp, #0xc]
 *   @0x22a1e0 str r7, [sp, #0x18]
 *   @0x22a1e4 str r2, [sp, #0x10]
 *   @0x22a1e8 str r10, [sp, #0x4]
 *   @0x22a1ec str r9, [sp, #0x8]
 *   @0x22a1f0 ldr r3, [sp, #0x18]
 *   @0x22a1f4 ldr r5, [r3, #0x4]!
 *   @0x22a1f8 add r2, r7, r5, lsl #2
 *   @0x22a1fc str r3, [sp, #0x18]
 *   @0x22a200 mov r3, #1
 *   @0x22a204 ldr r8, [r2, #0xc0]
 *   @0x22a208 ldr r11, [r2, #0x80]
 *   @0x22a20c cmp r8, #0
 *   @0x22a210 lsl r6, r3, r8
 *   @0x22a214 bne 0x22a400 <vorbis_lsp_to_curve+0xb54>
 *   @0x22a218 mov r4, r8
 *   @0x22a21c cmp r11, #0
 *   @0x22a220 ble 0x22a2b4 <vorbis_lsp_to_curve+0xa08>
 *   @0x22a224 ldr r3, [sp, #0x10]
 *   @0x22a228 sub r10, r6, #1
 *   @0x22a22c ldr r2, [sp, #0x1c]
 *   @0x22a230 lsl r9, r5, #3
 *   @0x22a234 mov r5, #0
 *   @0x22a238 add r6, r2, r3, lsl #2
 *   @0x22a23c mov r3, r10
 *   @0x22a240 mov r10, r8
 *   @0x22a244 mov r8, r11
 *   @0x22a248 mov r11, r3
 *   @0x22a24c b 0x22a26c <vorbis_lsp_to_curve+0x9c0>
 *   @0x22a250 bl 0x2280d0 <vorbis_book_decode>
 *   @0x22a254 cmn r0, #1
 *   @0x22a258 str r0, [r6]
 *   @0x22a25c beq 0x22a424 <vorbis_lsp_to_curve+0xb78>
 *   @0x22a260 cmp r5, r8
 *   @0x22a264 add r6, r6, #4
 *   @0x22a268 beq 0x22a2b0 <vorbis_lsp_to_curve+0xa04>
 *   @0x22a26c and r0, r4, r11
 *   @0x22a270 ldr r3, [sp, #0x4]
 *   @0x22a274 add r0, r9, r0
 *   @0x22a278 mov r2, #52
 *   @0x22a27c add r0, r0, #80
 *   @0x22a280 add r5, r5, #1
 *   @0x22a284 ldr r1, [sp, #0x8]
 *   @0x22a288 asr r4, r4, r10
 *   @0x22a28c ldr r0, [r7, r0, lsl #2]
 *   @0x22a290 cmp r0, #0
 *   @0x22a294 mla r0, r2, r0, r3
 *   @0x22a298 bge 0x22a250 <vorbis_lsp_to_curve+0x9a4>
 *   @0x22a29c cmp r5, r8
 *   @0x22a2a0 mov r2, #0
 *   @0x22a2a4 add r6, r6, #4
 *   @0x22a2a8 str r2, [r6, #-0x4]
 *   @0x22a2ac bne 0x22a26c <vorbis_lsp_to_curve+0x9c0>
 *   @0x22a2b0 mov r11, r8
 *   @0x22a2b4 ldr r3, [sp, #0xc]
 *   @0x22a2b8 ldr r2, [r7]
 *   @0x22a2bc add r3, r3, #1
 *   @0x22a2c0 str r3, [sp, #0xc]
 *   @0x22a2c4 ldr r3, [sp, #0x10]
 *   @0x22a2c8 add r3, r3, r11
 *   @0x22a2cc str r3, [sp, #0x10]
 *   @0x22a2d0 ldr r3, [sp, #0xc]
 *   @0x22a2d4 cmp r2, r3
 *   @0x22a2d8 bgt 0x22a1f0 <vorbis_lsp_to_curve+0x944>
 *   @0x22a2dc ldr r2, [sp, #0x14]
 *   @0x22a2e0 ldr r3, [r2, #0x2fc]
 *   @0x22a2e4 cmp r3, #2
 *   @0x22a2e8 ble 0x22a440 <vorbis_lsp_to_curve+0xb94>
 *   @0x22a2ec ldr r4, [sp, #0x14]
 *   @0x22a2f0 add r9, r7, #840
 *   @0x22a2f4 ldr r5, [sp, #0x1c]
 *   @0x22a2f8 mov r6, #2
 *   @0x22a2fc mov r11, r4
 *   @0x22a300 mov r8, r5
 *   @0x22a304 b 0x22a35c <vorbis_lsp_to_curve+0xab0>
 *   @0x22a308 cmp r2, r0
 *   @0x22a30c rsble r3, r2, r3
 *   @0x22a310 rsbgt r3, r0, r3
 *   @0x22a314 mvnle r3, r3
 *   @0x22a318 add r0, r3, r0
 *   @0x22a31c ubfx r0, r0, #0x0, #0xf
 *   @0x22a320 str r0, [r5, #0x8]
 *   @0x22a324 ldr r3, [r4, #0x200]
 *   @0x22a328 ldr r2, [r8, r3, lsl #2]
 *   @0x22a32c ubfx r2, r2, #0x0, #0xf
 *   @0x22a330 str r2, [r8, r3, lsl #2]
 *   @0x22a334 ldr r3, [r4, #0x104]
 *   @0x22a338 ldr r2, [r8, r3, lsl #2]
 *   @0x22a33c ubfx r2, r2, #0x0, #0xf
 *   @0x22a340 str r2, [r8, r3, lsl #2]
 *   @0x22a344 ldr r3, [r11, #0x2fc]
 *   @0x22a348 add r6, r6, #1
 *   @0x22a34c add r4, r4, #4
 *   @0x22a350 add r5, r5, #4
 *   @0x22a354 cmp r3, r6
 *   @0x22a358 ble 0x22a440 <vorbis_lsp_to_curve+0xb94>
 *   @0x22a35c ldr r3, [r4, #0x104]
 *   @0x22a360 ldr r2, [r4, #0x200]
 *   @0x22a364 ldr r0, [r9, #0x4]!
 *   @0x22a368 ldr r10, [r8, r3, lsl #2]
 *   @0x22a36c add r1, r7, r3, lsl #2
 *   @0x22a370 ldr r12, [r8, r2, lsl #2]
 *   @0x22a374 add r2, r7, r2, lsl #2
 *   @0x22a378 ubfx r10, r10, #0x0, #0xf
 *   @0x22a37c ldr r1, [r1, #0x344]
 *   @0x22a380 ldr r3, [r2, #0x344]
 *   @0x22a384 ubfx r12, r12, #0x0, #0xf
 *   @0x22a388 rsb r10, r12, r10
 *   @0x22a38c str r12, [sp]
 *   @0x22a390 eor r2, r10, r10, asr #31
 *   @0x22a394 sub r2, r2, r10, asr #31
 *   @0x22a398 rsb r0, r3, r0
 *   @0x22a39c rsb r1, r3, r1
 *   @0x22a3a0 mul r0, r0, r2
 *   @0x22a3a4 bl 0x318d10 <__divsi3>
 *   @0x22a3a8 ldr r12, [sp]
 *   @0x22a3ac ldr r3, [r5, #0x8]
 *   @0x22a3b0 cmp r10, #0
 *   @0x22a3b4 ldr r2, [r11, #0x304]
 *   @0x22a3b8 rsblt r0, r0, r12
 *   @0x22a3bc addge r0, r12, r0
 *   @0x22a3c0 cmp r3, #0
 *   @0x22a3c4 orreq r0, r0, #32768
 *   @0x22a3c8 streq r0, [r5, #0x8]
 *   @0x22a3cc beq 0x22a344 <vorbis_lsp_to_curve+0xa98>
 *   @0x22a3d0 rsb r2, r0, r2
 *   @0x22a3d4 cmp r2, r0
 *   @0x22a3d8 movlt r1, r2
 *   @0x22a3dc movge r1, r0
 *   @0x22a3e0 cmp r3, r1, lsl #1
 *   @0x22a3e4 bge 0x22a308 <vorbis_lsp_to_curve+0xa5c>
 *   @0x22a3e8 tst r3, #1
 *   @0x22a3ec addne r3, r3, #1
 *   @0x22a3f0 asreq r3, r3, #1
 *   @0x22a3f4 asrne r3, r3, #1
 *   @0x22a3f8 rsbne r3, r3, #0
 *   @0x22a3fc b 0x22a318 <vorbis_lsp_to_curve+0xa6c>
 *   @0x22a400 ldr r0, [r2, #0x100]
 *   @0x22a404 mov r2, #52
 *   @0x22a408 ldr r3, [sp, #0x4]
 *   @0x22a40c ldr r1, [sp, #0x8]
 *   @0x22a410 mla r0, r2, r0, r3
 *   @0x22a414 bl 0x2280d0 <vorbis_book_decode>
 *   @0x22a418 cmn r0, #1
 *   @0x22a41c mov r4, r0
 *   @0x22a420 bne 0x22a21c <vorbis_lsp_to_curve+0x970>
 *   @0x22a424 mov r0, #0
 *   @0x22a428 add sp, sp, #36
 *   @0x22a42c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22a430 mov r1, r3
 *   @0x22a434 b 0x22a188 <vorbis_lsp_to_curve+0x8dc>
 *   @0x22a438 mov r1, r3
 *   @0x22a43c b 0x22a1b8 <vorbis_lsp_to_curve+0x90c>
 *   @0x22a440 ldr r0, [sp, #0x1c]
 *   @0x22a444 b 0x22a428 <vorbis_lsp_to_curve+0xb7c>
 *   @0x22a448 push {r4, lr}
 *   @0x22a44c subs r4, r0, #0
 *   @0x22a450 popeq {r4, pc}
 *   @0x22a454 mov r1, #0
 *   @0x22a458 mov r2, #780
 *   @0x22a45c bl 0xb65b0 <memset@plt>
 *   @0x22a460 mov r0, r4
 *   @0x22a464 pop {r4, lr}
 *   @0x22a468 b 0xb655c <free@plt>
 *   @0x22a46c push {r4, lr}
 *   @0x22a470 subs r4, r0, #0
 *   @0x22a474 popeq {r4, pc}
 *   @0x22a478 mov r1, #0
 *   @0x22a47c movw r2, #0x448
 *   @0x22a480 bl 0xb65b0 <memset@plt>
 *   @0x22a484 mov r0, r4
 *   @0x22a488 pop {r4, lr}
 *   @0x22a48c b 0xb655c <free@plt>
 *   @0x22a490 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22a494 mov r1, #780
 *   @0x22a498 sub sp, sp, #284
 *   @0x22a49c mov r0, #1
 *   @0x22a4a0 mov r4, r2
 *   @0x22a4a4 bl 0xb6c34 <calloc@plt>
 *   @0x22a4a8 ldr r1, [r4]
 *   @0x22a4ac ldr r3, [r4, #0x348]
 *   @0x22a4b0 cmp r1, #0
 *   @0x22a4b4 str r0, [sp, #0xc]
 *   @0x22a4b8 str r4, [r0, #0x308]
 *   @0x22a4bc str r3, [r0, #0x300]
 *   @0x22a4c0 ble 0x22a69c <vorbis_lsp_to_curve+0xdf0>
 *   @0x22a4c4 add r1, r4, r1, lsl #2
 *   @0x22a4c8 mov r3, r4
 *   @0x22a4cc mov r7, #0
 *   @0x22a4d0 ldr r2, [r3, #0x4]!
 *   @0x22a4d4 add r2, r2, #32
 *   @0x22a4d8 cmp r3, r1
 *   @0x22a4dc ldr r2, [r4, r2, lsl #2]
 *   @0x22a4e0 add r7, r7, r2
 *   @0x22a4e4 bne 0x22a4d0 <vorbis_lsp_to_curve+0xc24>
 *   @0x22a4e8 add r5, r7, #2
 *   @0x22a4ec ldr r3, [sp, #0xc]
 *   @0x22a4f0 subs r1, r5, #0
 *   @0x22a4f4 str r5, [r3, #0x2fc]
 *   @0x22a4f8 ble 0x22a684 <vorbis_lsp_to_curve+0xdd8>
 *   @0x22a4fc add r6, r4, #836
 *   @0x22a500 add r2, sp, #16
 *   @0x22a504 mov r0, #0
 *   @0x22a508 mov r3, r6
 *   @0x22a50c add r0, r0, #1
 *   @0x22a510 str r3, [r2, #0x4]!
 *   @0x22a514 cmp r5, r0
 *   @0x22a518 add r3, r3, #4
 *   @0x22a51c bgt 0x22a50c <vorbis_lsp_to_curve+0xc60>
 *   @0x22a520 add r8, sp, #20
 *   @0x22a524 ldr r3, [pc, #0x18c]
 *   @0x22a528 mov r2, #4
 *   @0x22a52c add r3, pc, r3
 *   @0x22a530 mov r0, r8
 *   @0x22a534 bl 0xb66dc <qsort@plt>
 *   @0x22a538 ldr r1, [sp, #0xc]
 *   @0x22a53c mov r3, #0
 *   @0x22a540 mov r12, r3
 *   @0x22a544 ldr r2, [r8, r3]
 *   @0x22a548 add r12, r12, #1
 *   @0x22a54c cmp r5, r12
 *   @0x22a550 rsb r2, r6, r2
 *   @0x22a554 asr r2, r2, #2
 *   @0x22a558 str r2, [r1, r3]
 *   @0x22a55c add r3, r3, #4
 *   @0x22a560 bgt 0x22a544 <vorbis_lsp_to_curve+0xc98>
 *   @0x22a564 ldr r3, [r4, #0x340]
 *   @0x22a568 sub r3, r3, #1
 *   @0x22a56c cmp r3, #3
 *   @0x22a570 addls pc, pc, r3, lsl #2
 *   @0x22a574 b 0x22a594 <vorbis_lsp_to_curve+0xce8>
 *   @0x22a578 b 0x22a588 <vorbis_lsp_to_curve+0xcdc>
 *   @0x22a57c b 0x22a674 <vorbis_lsp_to_curve+0xdc8>
 *   @0x22a580 b 0x22a664 <vorbis_lsp_to_curve+0xdb8>
 *   @0x22a584 b 0x22a654 <vorbis_lsp_to_curve+0xda8>
 *   @0x22a588 ldr r2, [sp, #0xc]
 *   @0x22a58c mov r3, #256
 *   @0x22a590 str r3, [r2, #0x304]
 *   @0x22a594 cmp r7, #0
 *   @0x22a598 ble 0x22a648 <vorbis_lsp_to_curve+0xd9c>
 *   @0x22a59c ldr r3, [sp, #0xc]
 *   @0x22a5a0 mov r9, #1
 *   @0x22a5a4 ldr r2, [sp, #0xc]
 *   @0x22a5a8 add r11, r4, #840
 *   @0x22a5ac str r7, [sp, #0x8]
 *   @0x22a5b0 add r4, r4, #832
 *   @0x22a5b4 ldr r3, [r3, #0x300]
 *   @0x22a5b8 add r10, r2, #508
 *   @0x22a5bc str r4, [sp, #0x4]
 *   @0x22a5c0 str r3, [sp]
 *   @0x22a5c4 ldr r6, [r11, #0x4]!
 *   @0x22a5c8 mov r1, #0
 *   @0x22a5cc ldm sp, {r0, r5}
 *   @0x22a5d0 mov r8, r9
 *   @0x22a5d4 add r9, r9, #1
 *   @0x22a5d8 mov r4, r1
 *   @0x22a5dc mov r2, r1
 *   @0x22a5e0 mov r12, #1
 *   @0x22a5e4 ldr r3, [r5, #0x4]!
 *   @0x22a5e8 cmp r3, r1
 *   @0x22a5ec movle r7, #0
 *   @0x22a5f0 movgt r7, #1
 *   @0x22a5f4 cmp r3, r6
 *   @0x22a5f8 movge r7, #0
 *   @0x22a5fc cmp r7, #0
 *   @0x22a600 movne r4, r2
 *   @0x22a604 movne r1, r3
 *   @0x22a608 cmp r3, r0
 *   @0x22a60c movge r7, #0
 *   @0x22a610 movlt r7, #1
 *   @0x22a614 cmp r3, r6
 *   @0x22a618 movle r7, #0
 *   @0x22a61c cmp r7, #0
 *   @0x22a620 movne r12, r2
 *   @0x22a624 add r2, r2, #1
 *   @0x22a628 movne r0, r3
 *   @0x22a62c cmp r9, r2
 *   @0x22a630 bne 0x22a5e4 <vorbis_lsp_to_curve+0xd38>
 *   @0x22a634 ldr r3, [sp, #0x8]
 *   @0x22a638 str r4, [r10, #0x4]!
 *   @0x22a63c cmp r8, r3
 *   @0x22a640 str r12, [r10, #-0xfc]
 *   @0x22a644 bne 0x22a5c4 <vorbis_lsp_to_curve+0xd18>
 *   @0x22a648 ldr r0, [sp, #0xc]
 *   @0x22a64c add sp, sp, #284
 *   @0x22a650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22a654 ldr r2, [sp, #0xc]
 *   @0x22a658 mov r3, #64
 *   @0x22a65c str r3, [r2, #0x304]
 *   @0x22a660 b 0x22a594 <vorbis_lsp_to_curve+0xce8>
 *   @0x22a664 ldr r2, [sp, #0xc]
 *   @0x22a668 mov r3, #86
 *   @0x22a66c str r3, [r2, #0x304]
 *   @0x22a670 b 0x22a594 <vorbis_lsp_to_curve+0xce8>
 *   @0x22a674 ldr r2, [sp, #0xc]
 *   @0x22a678 mov r3, #128
 *   @0x22a67c str r3, [r2, #0x304]
 *   @0x22a680 b 0x22a594 <vorbis_lsp_to_curve+0xce8>
 *   @0x22a684 ldr r3, [pc, #0x30]
 *   @0x22a688 add r0, sp, #20
 *   @0x22a68c mov r2, #4
 *   @0x22a690 add r3, pc, r3
 *   @0x22a694 bl 0xb66dc <qsort@plt>
 *   @0x22a698 b 0x22a564 <vorbis_lsp_to_curve+0xcb8>
 *   @0x22a69c ldr r2, [sp, #0xc]
 *   @0x22a6a0 mov r3, #2
 *   @0x22a6a4 mov r7, #0
 *   @0x22a6a8 mov r1, r3
 *   @0x22a6ac mov r5, r3
 *   @0x22a6b0 str r3, [r2, #0x2fc]
 *   @0x22a6b4 b 0x22a4fc <vorbis_lsp_to_curve+0xc50>
 *   @0x22a6b8 .word 0xfffff968
 *   @0x22a6bc .word 0xfffff804
 *   @0x22a6c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22a6c4 mov r5, r1
 *   @0x22a6c8 sub sp, sp, #276
 *   @0x22a6cc ldr r8, [r0, #0x1c]
 *   @0x22a6d0 movw r1, #0x448
 *   @0x22a6d4 mov r0, #1
 *   @0x22a6d8 bl 0xb6c34 <calloc@plt>
 *   @0x22a6dc mov r1, #5
 *   @0x22a6e0 mov r7, r0
 *   @0x22a6e4 mov r0, r5
 *   @0x22a6e8 bl 0x233b28 <oggpack_read>
 *   @0x22a6ec cmp r0, #0
 *   @0x22a6f0 str r0, [r7]
 *   @0x22a6f4 movgt r9, r7
 *   @0x22a6f8 mvngt r6, #0
 *   @0x22a6fc movgt r4, #0
 *   @0x22a700 bgt 0x22a71c <vorbis_lsp_to_curve+0xe70>
 *   @0x22a704 b 0x22a828 <vorbis_lsp_to_curve+0xf7c>
 *   @0x22a708 ldr r2, [r7]
 *   @0x22a70c cmp r6, r0
 *   @0x22a710 movlt r6, r0
 *   @0x22a714 cmp r2, r4
 *   @0x22a718 ble 0x22a74c <vorbis_lsp_to_curve+0xea0>
 *   @0x22a71c mov r0, r5
 *   @0x22a720 mov r1, #4
 *   @0x22a724 bl 0x233b28 <oggpack_read>
 *   @0x22a728 add r4, r4, #1
 *   @0x22a72c cmp r0, #0
 *   @0x22a730 str r0, [r9, #0x4]!
 *   @0x22a734 bge 0x22a708 <vorbis_lsp_to_curve+0xe5c>
 *   @0x22a738 mov r0, r7
 *   @0x22a73c bl 0x22a46c <vorbis_lsp_to_curve+0xbc0>
 *   @0x22a740 mov r0, #0
 *   @0x22a744 add sp, sp, #276
 *   @0x22a748 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22a74c mov r10, r7
 *   @0x22a750 mov r4, #1
 *   @0x22a754 add r3, r7, #316
 *   @0x22a758 str r3, [sp]
 *   @0x22a75c mov r3, #0
 *   @0x22a760 str r3, [sp, #0x4]
 *   @0x22a764 mov r1, #3
 *   @0x22a768 mov r0, r5
 *   @0x22a76c bl 0x233b28 <oggpack_read>
 *   @0x22a770 mov r1, #2
 *   @0x22a774 add r3, r0, #1
 *   @0x22a778 mov r0, r5
 *   @0x22a77c str r3, [r10, #0x80]
 *   @0x22a780 bl 0x233b28 <oggpack_read>
 *   @0x22a784 cmp r0, #0
 *   @0x22a788 str r0, [r10, #0xc0]
 *   @0x22a78c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a790 bne 0x22a8c8 <vorbis_lsp_to_curve+0x101c>
 *   @0x22a794 ldr r3, [r10, #0x100]
 *   @0x22a798 cmp r3, #0
 *   @0x22a79c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a7a0 ldr r2, [r8, #0x1c]
 *   @0x22a7a4 cmp r2, r3
 *   @0x22a7a8 ble 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a7ac ldr r3, [r10, #0xc0]
 *   @0x22a7b0 lsl r3, r4, r3
 *   @0x22a7b4 cmp r3, #0
 *   @0x22a7b8 ldrgt r9, [sp]
 *   @0x22a7bc movgt r11, #0
 *   @0x22a7c0 bgt 0x22a7e0 <vorbis_lsp_to_curve+0xf34>
 *   @0x22a7c4 b 0x22a804 <vorbis_lsp_to_curve+0xf58>
 *   @0x22a7c8 ldr r1, [r8, #0x1c]
 *   @0x22a7cc cmp r0, r1
 *   @0x22a7d0 bge 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a7d4 ldr r3, [r10, #0xc0]
 *   @0x22a7d8 cmp r11, r4, lsl r3
 *   @0x22a7dc bge 0x22a804 <vorbis_lsp_to_curve+0xf58>
 *   @0x22a7e0 mov r0, r5
 *   @0x22a7e4 mov r1, #8
 *   @0x22a7e8 bl 0x233b28 <oggpack_read>
 *   @0x22a7ec add r11, r11, #1
 *   @0x22a7f0 sub r0, r0, #1
 *   @0x22a7f4 str r0, [r9, #0x4]!
 *   @0x22a7f8 cmn r0, #1
 *   @0x22a7fc bge 0x22a7c8 <vorbis_lsp_to_curve+0xf1c>
 *   @0x22a800 b 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a804 ldr r3, [sp, #0x4]
 *   @0x22a808 add r10, r10, #4
 *   @0x22a80c add r3, r3, #1
 *   @0x22a810 str r3, [sp, #0x4]
 *   @0x22a814 cmp r3, r6
 *   @0x22a818 ldr r3, [sp]
 *   @0x22a81c add r3, r3, #32
 *   @0x22a820 str r3, [sp]
 *   @0x22a824 ble 0x22a764 <vorbis_lsp_to_curve+0xeb8>
 *   @0x22a828 mov r1, #2
 *   @0x22a82c mov r0, r5
 *   @0x22a830 bl 0x233b28 <oggpack_read>
 *   @0x22a834 mov r1, #4
 *   @0x22a838 add r3, r0, #1
 *   @0x22a83c mov r0, r5
 *   @0x22a840 str r3, [r7, #0x340]
 *   @0x22a844 bl 0x233b28 <oggpack_read>
 *   @0x22a848 subs r6, r0, #0
 *   @0x22a84c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a850 ldr r3, [r7]
 *   @0x22a854 cmp r3, #0
 *   @0x22a858 ble 0x22a918 <vorbis_lsp_to_curve+0x106c>
 *   @0x22a85c ldr r2, [r7, #0x4]
 *   @0x22a860 add r2, r2, #32
 *   @0x22a864 ldr r4, [r7, r2, lsl #2]
 *   @0x22a868 cmp r4, #63
 *   @0x22a86c bgt 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a870 mov r8, #1
 *   @0x22a874 mov r9, #0
 *   @0x22a878 lsl r8, r8, r6
 *   @0x22a87c mov r11, r9
 *   @0x22a880 str r7, [sp]
 *   @0x22a884 cmp r11, r4
 *   @0x22a888 bge 0x22a8e4 <vorbis_lsp_to_curve+0x1038>
 *   @0x22a88c add r3, r7, r11, lsl #2
 *   @0x22a890 add r10, r3, #840
 *   @0x22a894 b 0x22a8a8 <vorbis_lsp_to_curve+0xffc>
 *   @0x22a898 cmp r0, r8
 *   @0x22a89c bge 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a8a0 cmp r11, r4
 *   @0x22a8a4 beq 0x22a8e0 <vorbis_lsp_to_curve+0x1034>
 *   @0x22a8a8 mov r0, r5
 *   @0x22a8ac mov r1, r6
 *   @0x22a8b0 bl 0x233b28 <oggpack_read>
 *   @0x22a8b4 add r11, r11, #1
 *   @0x22a8b8 cmp r0, #0
 *   @0x22a8bc str r0, [r10, #0x4]!
 *   @0x22a8c0 bge 0x22a898 <vorbis_lsp_to_curve+0xfec>
 *   @0x22a8c4 b 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a8c8 mov r0, r5
 *   @0x22a8cc mov r1, #8
 *   @0x22a8d0 bl 0x233b28 <oggpack_read>
 *   @0x22a8d4 mov r3, r0
 *   @0x22a8d8 str r0, [r10, #0x100]
 *   @0x22a8dc b 0x22a798 <vorbis_lsp_to_curve+0xeec>
 *   @0x22a8e0 ldr r3, [r7]
 *   @0x22a8e4 add r9, r9, #1
 *   @0x22a8e8 cmp r3, r9
 *   @0x22a8ec ble 0x22a9bc <vorbis_lsp_to_curve+0x1110>
 *   @0x22a8f0 ldr r1, [sp]
 *   @0x22a8f4 add r1, r1, #4
 *   @0x22a8f8 ldr r2, [r1, #0x4]
 *   @0x22a8fc str r1, [sp]
 *   @0x22a900 add r2, r2, #32
 *   @0x22a904 ldr r2, [r7, r2, lsl #2]
 *   @0x22a908 add r4, r4, r2
 *   @0x22a90c cmp r4, #63
 *   @0x22a910 ble 0x22a884 <vorbis_lsp_to_curve+0xfd8>
 *   @0x22a914 b 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a918 mov r3, #1
 *   @0x22a91c mov r1, #2
 *   @0x22a920 mov r5, r3
 *   @0x22a924 mov r2, #0
 *   @0x22a928 lsl r3, r3, r6
 *   @0x22a92c str r2, [r7, #0x344]
 *   @0x22a930 str r3, [r7, #0x348]
 *   @0x22a934 add r2, r7, #836
 *   @0x22a938 add r0, sp, #8
 *   @0x22a93c mov r3, #0
 *   @0x22a940 add r3, r3, #1
 *   @0x22a944 str r2, [r0, #0x4]!
 *   @0x22a948 cmp r3, r5
 *   @0x22a94c add r2, r2, #4
 *   @0x22a950 ble 0x22a940 <vorbis_lsp_to_curve+0x1094>
 *   @0x22a954 add r6, sp, #12
 *   @0x22a958 ldr r3, [pc, #0x90]
 *   @0x22a95c mov r2, #4
 *   @0x22a960 add r3, pc, r3
 *   @0x22a964 mov r0, r6
 *   @0x22a968 bl 0xb66dc <qsort@plt>
 *   @0x22a96c cmp r5, #0
 *   @0x22a970 ble 0x22a9e8 <vorbis_lsp_to_curve+0x113c>
 *   @0x22a974 ldr r2, [sp, #0xc]
 *   @0x22a978 ldr r3, [sp, #0x10]
 *   @0x22a97c ldr r2, [r2]
 *   @0x22a980 ldr r3, [r3]
 *   @0x22a984 cmp r2, r3
 *   @0x22a988 beq 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a98c mov r2, r6
 *   @0x22a990 mov r3, #1
 *   @0x22a994 add r3, r3, #1
 *   @0x22a998 cmp r3, r5
 *   @0x22a99c bgt 0x22a9e8 <vorbis_lsp_to_curve+0x113c>
 *   @0x22a9a0 ldr r0, [r2, #0x4]!
 *   @0x22a9a4 ldr r1, [r2, #0x4]
 *   @0x22a9a8 ldr r0, [r0]
 *   @0x22a9ac ldr r1, [r1]
 *   @0x22a9b0 cmp r0, r1
 *   @0x22a9b4 bne 0x22a994 <vorbis_lsp_to_curve+0x10e8>
 *   @0x22a9b8 b 0x22a738 <vorbis_lsp_to_curve+0xe8c>
 *   @0x22a9bc adds r5, r4, #1
 *   @0x22a9c0 mov r3, #0
 *   @0x22a9c4 add r1, r4, #2
 *   @0x22a9c8 str r8, [r7, #0x348]
 *   @0x22a9cc str r3, [r7, #0x344]
 *   @0x22a9d0 bpl 0x22a934 <vorbis_lsp_to_curve+0x1088>
 *   @0x22a9d4 ldr r3, [pc, #0x18]
 *   @0x22a9d8 add r0, sp, #12
 *   @0x22a9dc mov r2, #4
 *   @0x22a9e0 add r3, pc, r3
 *   @0x22a9e4 bl 0xb66dc <qsort@plt>
 *   @0x22a9e8 mov r0, r7
 *   @0x22a9ec b 0x22a744 <vorbis_lsp_to_curve+0xe98>
 *   @0x22a9f0 .word 0xfffff534
 *   @0x22a9f4 .word 0xfffff4b4
 *   @0x22a9f8 cmp r2, #0
 *   @0x22a9fc str r4, [sp, #-0x4]!
 *   @0x22aa00 ble 0x22aa64 <vorbis_lsp_to_curve+0x11b8>
 *   @0x22aa04 ldr r3, [pc, #0x70]
 *   @0x22aa08 ldrb r4, [r0]
 *   @0x22aa0c ldr r3, [pc, r3]
 *   @0x22aa10 ldrb r12, [r1]
 *   @0x22aa14 ldr r3, [r3]
 *   @0x22aa18 add r4, r3, r4, lsl #1
 *   @0x22aa1c add r12, r3, r12, lsl #1
 *   @0x22aa20 ldrsh r4, [r4, #2]
 *   @0x22aa24 ldrsh r12, [r12, #2]
 *   @0x22aa28 cmp r4, r12
 *   @0x22aa2c bne 0x22aa70 <vorbis_lsp_to_curve+0x11c4>
 *   @0x22aa30 sub r4, r0, #1
 *   @0x22aa34 add r4, r4, r2
 *   @0x22aa38 b 0x22aa5c <vorbis_lsp_to_curve+0x11b0>
 *   @0x22aa3c ldrb r12, [r0, #0x1]!
 *   @0x22aa40 ldrb r2, [r1, #0x1]!
 *   @0x22aa44 add r12, r3, r12, lsl #1
 *   @0x22aa48 add r2, r3, r2, lsl #1
 *   @0x22aa4c ldrsh r12, [r12, #2]
 *   @0x22aa50 ldrsh r2, [r2, #2]
 *   @0x22aa54 cmp r12, r2
 *   @0x22aa58 bne 0x22aa70 <vorbis_lsp_to_curve+0x11c4>
 *   @0x22aa5c cmp r0, r4
 *   @0x22aa60 bne 0x22aa3c <vorbis_lsp_to_curve+0x1190>
 *   @0x22aa64 mov r0, #0
 *   @0x22aa68 ldr r4, [sp], #4
 *   @0x22aa6c bx lr
 *   @0x22aa70 mov r0, #1
 *   @0x22aa74 ldr r4, [sp], #4
 *   @0x22aa78 bx lr
 *
 * ══ §7/13 b2VoronoiDiagram::Generate(float)  0x2dbbc4  size 3048  762 条（0x2dbbc4..0x2dc7ac）
 * @func 0x2dbbc4 0x2dc7ac  size 3048  762 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Allocate(int)×2 / b2VoronoiDiagram::Generate(float)+0x5f0×2 / b2VoronoiDiagram::Generate(float)+0x464×2 / b2VoronoiDiagram::Generate(float)+0x704×2 / b2VoronoiDiagram::Generate(float)+0x798×2 / b2VoronoiDiagram::Generate(float)+0xa04×2 / b2VoronoiDiagram::Generate(float)+0xa98×2 / b2VoronoiDiagram::Generate(float)+0x258×2
 * 字段偏移 top8: 0x4×30 / 0x8×23 / 0xc×23 / 0x1c×19 / 0x18×15 / 0x2c×14 / 0x14×14 / 0x10×10
 * VFP 指令 65 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dbbc4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dbbc8 vpush {d8, d9}
 *   @0x2dbbcc vmov.f32 s18, #1.000000e+00
 *   @0x2dbbd0 ldr r3, [r0, #0x8]
 *   @0x2dbbd4 sub sp, sp, #76
 *   @0x2dbbd8 vmov s10, r1
 *   @0x2dbbdc cmp r3, #0
 *   @0x2dbbe0 str r0, [sp, #0x2c]
 *   @0x2dbbe4 vdiv.f32 s18, s18, s10
 *   @0x2dbbe8 ble 0x2dc770 <_ZN16b2VoronoiDiagram8GenerateEf+0xbac>
 *   @0x2dbbec add r2, r3, r3, lsl #1
 *   @0x2dbbf0 vldr s15, [pc, #968]
 *   @0x2dbbf4 ldr r3, [r0, #0x4]
 *   @0x2dbbf8 vldr s16, [pc, #964]
 *   @0x2dbbfc add r2, r3, r2, lsl #2
 *   @0x2dbc00 vmov.f32 s12, s15
 *   @0x2dbc04 vmov.f32 s17, s16
 *   @0x2dbc08 vldr s13, [r3]
 *   @0x2dbc0c vldr s14, [r3, #4]
 *   @0x2dbc10 add r3, r3, #12
 *   @0x2dbc14 vcmpe.f32 s13, s16
 *   @0x2dbc18 vmrs APSR_nzcv, fpscr
 *   @0x2dbc1c vcmpe.f32 s14, s17
 *   @0x2dbc20 vmovle.f32 s16, s13
 *   @0x2dbc24 vmrs APSR_nzcv, fpscr
 *   @0x2dbc28 vcmpe.f32 s13, s15
 *   @0x2dbc2c vmovle.f32 s17, s14
 *   @0x2dbc30 vmrs APSR_nzcv, fpscr
 *   @0x2dbc34 vcmpe.f32 s14, s12
 *   @0x2dbc38 vmovpl.f32 s15, s13
 *   @0x2dbc3c vmrs APSR_nzcv, fpscr
 *   @0x2dbc40 vmovpl.f32 s12, s14
 *   @0x2dbc44 cmp r3, r2
 *   @0x2dbc48 bne 0x2dbc08 <_ZN16b2VoronoiDiagram8GenerateEf+0x44>
 *   @0x2dbc4c vsub.f32 s15, s15, s16
 *   @0x2dbc50 ldr r5, [sp, #0x2c]
 *   @0x2dbc54 ldr r0, [r5]
 *   @0x2dbc58 vsub.f32 s12, s12, s17
 *   @0x2dbc5c vmul.f32 s14, s15, s18
 *   @0x2dbc60 vmul.f32 s15, s12, s18
 *   @0x2dbc64 vcvt.s32.f32 s14, s14
 *   @0x2dbc68 vcvt.s32.f32 s15, s15
 *   @0x2dbc6c vmov r3, s14
 *   @0x2dbc70 vmov r2, s15
 *   @0x2dbc74 add r3, r3, #1
 *   @0x2dbc78 str r3, [r5, #0xc]
 *   @0x2dbc7c add r2, r2, #1
 *   @0x2dbc80 str r2, [r5, #0x10]
 *   @0x2dbc84 mul r1, r2, r3
 *   @0x2dbc88 lsl r1, r1, #2
 *   @0x2dbc8c bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2dbc90 ldr r12, [r5, #0xc]
 *   @0x2dbc94 ldr r1, [r5, #0x10]
 *   @0x2dbc98 mul r1, r1, r12
 *   @0x2dbc9c cmp r1, #0
 *   @0x2dbca0 str r0, [r5, #0x14]
 *   @0x2dbca4 ble 0x2dbcd0 <_ZN16b2VoronoiDiagram8GenerateEf+0x10c>
 *   @0x2dbca8 mov r3, #0
 *   @0x2dbcac mov r2, r0
 *   @0x2dbcb0 ldr lr, [sp, #0x2c]
 *   @0x2dbcb4 mov r0, r3
 *   @0x2dbcb8 b 0x2dbcc0 <_ZN16b2VoronoiDiagram8GenerateEf+0xfc>
 *   @0x2dbcbc ldr r2, [lr, #0x14]
 *   @0x2dbcc0 str r0, [r2, r3, lsl #2]
 *   @0x2dbcc4 add r3, r3, #1
 *   @0x2dbcc8 cmp r3, r1
 *   @0x2dbccc bne 0x2dbcbc <_ZN16b2VoronoiDiagram8GenerateEf+0xf8>
 *   @0x2dbcd0 mul r12, r12, r12
 *   @0x2dbcd4 ldr r5, [sp, #0x2c]
 *   @0x2dbcd8 ldr r5, [r5]
 *   @0x2dbcdc str r5, [sp, #0x44]
 *   @0x2dbce0 mov r0, r5
 *   @0x2dbce4 lsl r5, r12, #6
 *   @0x2dbce8 mov r1, r5
 *   @0x2dbcec bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2dbcf0 ldr r1, [sp, #0x2c]
 *   @0x2dbcf4 ldr r4, [r1, #0x8]
 *   @0x2dbcf8 cmp r4, #0
 *   @0x2dbcfc add r5, r0, r5
 *   @0x2dbd00 str r0, [sp, #0x1c]
 *   @0x2dbd04 str r5, [sp, #0x4]
 *   @0x2dbd08 ble 0x2dc784 <_ZN16b2VoronoiDiagram8GenerateEf+0xbc0>
 *   @0x2dbd0c ldr r5, [sp, #0x2c]
 *   @0x2dbd10 mov r0, #0
 *   @0x2dbd14 mov r12, r0
 *   @0x2dbd18 ldr r5, [r5, #0xc]
 *   @0x2dbd1c str r5, [sp, #0x18]
 *   @0x2dbd20 ldr r5, [sp, #0x1c]
 *   @0x2dbd24 add r6, r5, #16
 *   @0x2dbd28 ldr r5, [sp, #0x2c]
 *   @0x2dbd2c rsb r1, r6, #15
 *   @0x2dbd30 str r1, [sp]
 *   @0x2dbd34 ldr r5, [r5, #0x10]
 *   @0x2dbd38 str r5, [sp, #0x38]
 *   @0x2dbd3c ldr r5, [sp, #0x2c]
 *   @0x2dbd40 ldr r7, [r5, #0x4]
 *   @0x2dbd44 ldr r5, [sp, #0x18]
 *   @0x2dbd48 sub r8, r5, #1
 *   @0x2dbd4c ldr r5, [sp, #0x38]
 *   @0x2dbd50 sub r10, r5, #1
 *   @0x2dbd54 ldr r5, [sp, #0x1c]
 *   @0x2dbd58 add r11, r5, #32
 *   @0x2dbd5c mov r9, r5
 *   @0x2dbd60 add r3, r7, r0
 *   @0x2dbd64 vldr s14, [r3]
 *   @0x2dbd68 vldr s15, [r3, #4]
 *   @0x2dbd6c vsub.f32 s14, s14, s16
 *   @0x2dbd70 ldr r5, [sp, #0x4]
 *   @0x2dbd74 vsub.f32 s15, s15, s17
 *   @0x2dbd78 vmul.f32 s14, s18, s14
 *   @0x2dbd7c vmul.f32 s15, s18, s15
 *   @0x2dbd80 vstr s14, [r3]
 *   @0x2dbd84 vstr s15, [r3, #4]
 *   @0x2dbd88 vcvt.s32.f32 s14, s14
 *   @0x2dbd8c vcvt.s32.f32 s15, s15
 *   @0x2dbd90 vmov r1, s14
 *   @0x2dbd94 vmov r2, s15
 *   @0x2dbd98 cmp r1, r8
 *   @0x2dbd9c movge r1, r8
 *   @0x2dbda0 bic r1, r1, r1, asr #31
 *   @0x2dbda4 cmp r2, r10
 *   @0x2dbda8 movge r2, r10
 *   @0x2dbdac cmp r5, r9
 *   @0x2dbdb0 ldr r5, [sp, #0x18]
 *   @0x2dbdb4 bic r2, r2, r2, asr #31
 *   @0x2dbdb8 mla r5, r5, r2, r1
 *   @0x2dbdbc str r5, [sp, #0x8]
 *   @0x2dbdc0 bhi 0x2dc51c <_ZN16b2VoronoiDiagram8GenerateEf+0x958>
 *   @0x2dbdc4 ldr r5, [sp, #0x1c]
 *   @0x2dbdc8 cmp r5, r9
 *   @0x2dbdcc bhs 0x2dbdf0 <_ZN16b2VoronoiDiagram8GenerateEf+0x22c>
 *   @0x2dbdd0 ldr r1, [sp]
 *   @0x2dbdd4 mov r3, r6
 *   @0x2dbdd8 add r2, r9, r1
 *   @0x2dbddc bic r2, r2, #15
 *   @0x2dbde0 add r2, r11, r2
 *   @0x2dbde4 add r3, r3, #16
 *   @0x2dbde8 cmp r3, r2
 *   @0x2dbdec bne 0x2dbde4 <_ZN16b2VoronoiDiagram8GenerateEf+0x220>
 *   @0x2dbdf0 add r12, r12, #1
 *   @0x2dbdf4 add r0, r0, #12
 *   @0x2dbdf8 cmp r12, r4
 *   @0x2dbdfc bne 0x2dbd60 <_ZN16b2VoronoiDiagram8GenerateEf+0x19c>
 *   @0x2dbe00 ldr r5, [sp, #0x18]
 *   @0x2dbe04 ldr r11, [sp, #0x1c]
 *   @0x2dbe08 sub r5, r5, #1
 *   @0x2dbe0c str r5, [sp, #0xc]
 *   @0x2dbe10 ldr r5, [sp, #0x38]
 *   @0x2dbe14 sub r5, r5, #1
 *   @0x2dbe18 str r5, [sp, #0x10]
 *   @0x2dbe1c add r3, r11, #16
 *   @0x2dbe20 ldr r0, [sp, #0x2c]
 *   @0x2dbe24 b 0x2dbe54 <_ZN16b2VoronoiDiagram8GenerateEf+0x290>
 *   @0x2dbe28 ldr r12, [r11, #0x8]
 *   @0x2dbe2c add r3, r3, #16
 *   @0x2dbe30 ldr r2, [r0, #0x14]
 *   @0x2dbe34 add r11, r11, #16
 *   @0x2dbe38 ldr r4, [r3, #-0x20]
 *   @0x2dbe3c add r1, r2, r12, lsl #2
 *   @0x2dbe40 ldr r5, [r3, #-0x1c]
 *   @0x2dbe44 ldr r2, [r2, r12, lsl #2]
 *   @0x2dbe48 ldr r6, [r11, #-0x4]
 *   @0x2dbe4c cmp r2, #0
 *   @0x2dbe50 beq 0x2dc53c <_ZN16b2VoronoiDiagram8GenerateEf+0x978>
 *   @0x2dbe54 cmp r11, r9
 *   @0x2dbe58 blo 0x2dbe28 <_ZN16b2VoronoiDiagram8GenerateEf+0x264>
 *   @0x2dbe5c ldr r5, [sp, #0x38]
 *   @0x2dbe60 ldr r1, [sp, #0x18]
 *   @0x2dbe64 add r5, r5, r1
 *   @0x2dbe68 str r5, [sp, #0x40]
 *   @0x2dbe6c cmp r5, #0
 *   @0x2dbe70 ble 0x2dc3a4 <_ZN16b2VoronoiDiagram8GenerateEf+0x7e0>
 *   @0x2dbe74 mov r5, #0
 *   @0x2dbe78 str r5, [sp, #0x3c]
 *   @0x2dbe7c sub r5, r1, #1
 *   @0x2dbe80 str r5, [sp, #0x24]
 *   @0x2dbe84 ldr r5, [sp, #0x38]
 *   @0x2dbe88 sub r5, r5, #1
 *   @0x2dbe8c str r5, [sp, #0x34]
 *   @0x2dbe90 ldr r5, [sp, #0x38]
 *   @0x2dbe94 cmp r5, #0
 *   @0x2dbe98 ble 0x2dc1b4 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f0>
 *   @0x2dbe9c mov r5, #0
 *   @0x2dbea0 str r5, [sp, #0x14]
 *   @0x2dbea4 ldr r5, [sp, #0x18]
 *   @0x2dbea8 cmp r5, #1
 *   @0x2dbeac ble 0x2dc028 <_ZN16b2VoronoiDiagram8GenerateEf+0x464>
 *   @0x2dbeb0 ldr r1, [sp, #0x14]
 *   @0x2dbeb4 mov r7, #1
 *   @0x2dbeb8 mul r3, r1, r5
 *   @0x2dbebc ldr r5, [sp, #0x2c]
 *   @0x2dbec0 ldr r5, [r5, #0x14]
 *   @0x2dbec4 add r10, r3, r7
 *   @0x2dbec8 lsl r3, r3, #2
 *   @0x2dbecc str r5, [sp, #0x8]
 *   @0x2dbed0 ldr r5, [sp, #0x8]
 *   @0x2dbed4 add r8, r3, #4
 *   @0x2dbed8 ldr r3, [r5, r3]
 *   @0x2dbedc sub r5, r7, #1
 *   @0x2dbee0 str r5, [sp, #0x10]
 *   @0x2dbee4 sub r5, r10, #1
 *   @0x2dbee8 str r5, [sp, #0xc]
 *   @0x2dbeec ldr r5, [sp, #0x8]
 *   @0x2dbef0 str r3, [sp]
 *   @0x2dbef4 ldr r6, [r5, r8]
 *   @0x2dbef8 cmp r3, r6
 *   @0x2dbefc beq 0x2dc020 <_ZN16b2VoronoiDiagram8GenerateEf+0x45c>
 *   @0x2dbf00 ldr r5, [sp, #0x4]
 *   @0x2dbf04 cmp r5, r9
 *   @0x2dbf08 bhi 0x2dbf5c <_ZN16b2VoronoiDiagram8GenerateEf+0x398>
 *   @0x2dbf0c ldr r1, [sp, #0x1c]
 *   @0x2dbf10 cmp r11, r9
 *   @0x2dbf14 rsb r5, r1, r11
 *   @0x2dbf18 asr r5, r5, #4
 *   @0x2dbf1c lsl r5, r5, #4
 *   @0x2dbf20 rsbhs r5, r5, #0
 *   @0x2dbf24 bhs 0x2dbf48 <_ZN16b2VoronoiDiagram8GenerateEf+0x384>
 *   @0x2dbf28 rsb r5, r5, #0
 *   @0x2dbf2c mov r12, r11
 *   @0x2dbf30 ldm r12, {r0, r1, r2, r3}
 *   @0x2dbf34 add r4, r12, r5
 *   @0x2dbf38 add r12, r12, #16
 *   @0x2dbf3c cmp r12, r9
 *   @0x2dbf40 stm r4, {r0, r1, r2, r3}
 *   @0x2dbf44 blo 0x2dbf30 <_ZN16b2VoronoiDiagram8GenerateEf+0x36c>
 *   @0x2dbf48 add r9, r9, r5
 *   @0x2dbf4c add r11, r11, r5
 *   @0x2dbf50 ldr r5, [sp, #0x4]
 *   @0x2dbf54 cmp r5, r9
 *   @0x2dbf58 bls 0x2dbfc8 <_ZN16b2VoronoiDiagram8GenerateEf+0x404>
 *   @0x2dbf5c ldr r5, [sp, #0x10]
 *   @0x2dbf60 add r12, r9, #16
 *   @0x2dbf64 str r6, [r9, #0xc]
 *   @0x2dbf68 str r5, [r9]
 *   @0x2dbf6c ldr r5, [sp, #0x4]
 *   @0x2dbf70 cmp r5, r12
 *   @0x2dbf74 ldr r5, [sp, #0x14]
 *   @0x2dbf78 str r5, [r9, #0x4]
 *   @0x2dbf7c ldr r5, [sp, #0xc]
 *   @0x2dbf80 str r5, [r9, #0x8]
 *   @0x2dbf84 bls 0x2dbfcc <_ZN16b2VoronoiDiagram8GenerateEf+0x408>
 *   @0x2dbf88 ldr r5, [sp, #0x14]
 *   @0x2dbf8c add r9, r12, #16
 *   @0x2dbf90 mov r3, r7
 *   @0x2dbf94 str r7, [r12]
 *   @0x2dbf98 stmib r12, {r5, r10}
 *   @0x2dbf9c ldr r5, [sp]
 *   @0x2dbfa0 str r5, [r12, #0xc]
 *   @0x2dbfa4 ldr r5, [sp, #0x24]
 *   @0x2dbfa8 add r7, r7, #1
 *   @0x2dbfac add r10, r10, #1
 *   @0x2dbfb0 cmp r5, r3
 *   @0x2dbfb4 ble 0x2dc028 <_ZN16b2VoronoiDiagram8GenerateEf+0x464>
 *   @0x2dbfb8 mov r3, r8
 *   @0x2dbfbc b 0x2dbed0 <_ZN16b2VoronoiDiagram8GenerateEf+0x30c>
 *   @0x2dbfc0 .word 0xff7fffff
 *   @0x2dbfc4 svcvc #0x7fffff
 *   @0x2dbfc8 mov r12, r9
 *   @0x2dbfcc ldr r5, [sp, #0x1c]
 *   @0x2dbfd0 cmp r12, r11
 *   @0x2dbfd4 rsb r6, r5, r11
 *   @0x2dbfd8 asr r6, r6, #4
 *   @0x2dbfdc lsl r6, r6, #4
 *   @0x2dbfe0 rsbls r6, r6, #0
 *   @0x2dbfe4 bls 0x2dc008 <_ZN16b2VoronoiDiagram8GenerateEf+0x444>
 *   @0x2dbfe8 rsb r6, r6, #0
 *   @0x2dbfec mov r4, r11
 *   @0x2dbff0 ldm r4, {r0, r1, r2, r3}
 *   @0x2dbff4 add r5, r4, r6
 *   @0x2dbff8 add r4, r4, #16
 *   @0x2dbffc cmp r4, r12
 *   @0x2dc000 stm r5, {r0, r1, r2, r3}
 *   @0x2dc004 blo 0x2dbff0 <_ZN16b2VoronoiDiagram8GenerateEf+0x42c>
 *   @0x2dc008 ldr r5, [sp, #0x4]
 *   @0x2dc00c add r12, r12, r6
 *   @0x2dc010 add r11, r11, r6
 *   @0x2dc014 cmp r5, r12
 *   @0x2dc018 bhi 0x2dbf88 <_ZN16b2VoronoiDiagram8GenerateEf+0x3c4>
 *   @0x2dc01c mov r9, r12
 *   @0x2dc020 mov r3, r7
 *   @0x2dc024 b 0x2dbfa4 <_ZN16b2VoronoiDiagram8GenerateEf+0x3e0>
 *   @0x2dc028 ldr r5, [sp, #0x14]
 *   @0x2dc02c ldr r1, [sp, #0x38]
 *   @0x2dc030 add r5, r5, #1
 *   @0x2dc034 str r5, [sp, #0x14]
 *   @0x2dc038 cmp r5, r1
 *   @0x2dc03c blt 0x2dbea4 <_ZN16b2VoronoiDiagram8GenerateEf+0x2e0>
 *   @0x2dc040 ldr r5, [sp, #0x38]
 *   @0x2dc044 cmp r5, #1
 *   @0x2dc048 ble 0x2dc1b4 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f0>
 *   @0x2dc04c mov r5, #1
 *   @0x2dc050 str r5, [sp, #0xc]
 *   @0x2dc054 ldr r5, [sp, #0x18]
 *   @0x2dc058 cmp r5, #0
 *   @0x2dc05c ldr r5, [sp, #0xc]
 *   @0x2dc060 sub r5, r5, #1
 *   @0x2dc064 str r5, [sp, #0x28]
 *   @0x2dc068 ldrle r5, [sp, #0xc]
 *   @0x2dc06c strle r5, [sp, #0x30]
 *   @0x2dc070 ble 0x2dc198 <_ZN16b2VoronoiDiagram8GenerateEf+0x5d4>
 *   @0x2dc074 ldr r1, [sp, #0x18]
 *   @0x2dc078 mov r6, #0
 *   @0x2dc07c ldr r5, [sp, #0x28]
 *   @0x2dc080 mul r10, r5, r1
 *   @0x2dc084 ldr r5, [sp, #0xc]
 *   @0x2dc088 rsb r3, r5, #0
 *   @0x2dc08c mul r7, r5, r1
 *   @0x2dc090 str r5, [sp, #0x30]
 *   @0x2dc094 mla r3, r1, r3, r10
 *   @0x2dc098 ldr r5, [sp, #0x2c]
 *   @0x2dc09c ldr r5, [r5, #0x14]
 *   @0x2dc0a0 str r3, [sp, #0x14]
 *   @0x2dc0a4 rsb r3, r10, r7
 *   @0x2dc0a8 lsl r10, r10, #2
 *   @0x2dc0ac str r5, [sp, #0x20]
 *   @0x2dc0b0 lsl r3, r3, #2
 *   @0x2dc0b4 str r3, [sp, #0x10]
 *   @0x2dc0b8 ldr r3, [sp, #0x20]
 *   @0x2dc0bc ldr r5, [sp, #0x14]
 *   @0x2dc0c0 add r5, r7, r5
 *   @0x2dc0c4 str r5, [sp, #0x8]
 *   @0x2dc0c8 ldr r5, [r3, r10]!
 *   @0x2dc0cc str r5, [sp]
 *   @0x2dc0d0 ldr r5, [sp, #0x10]
 *   @0x2dc0d4 ldr r8, [r3, r5]
 *   @0x2dc0d8 ldr r5, [sp]
 *   @0x2dc0dc cmp r5, r8
 *   @0x2dc0e0 beq 0x2dc180 <_ZN16b2VoronoiDiagram8GenerateEf+0x5bc>
 *   @0x2dc0e4 ldr r5, [sp, #0x4]
 *   @0x2dc0e8 cmp r5, r9
 *   @0x2dc0ec bhi 0x2dc140 <_ZN16b2VoronoiDiagram8GenerateEf+0x57c>
 *   @0x2dc0f0 ldr r1, [sp, #0x1c]
 *   @0x2dc0f4 cmp r11, r9
 *   @0x2dc0f8 rsb r5, r1, r11
 *   @0x2dc0fc asr r5, r5, #4
 *   @0x2dc100 lsl r5, r5, #4
 *   @0x2dc104 rsbhs r5, r5, #0
 *   @0x2dc108 bhs 0x2dc12c <_ZN16b2VoronoiDiagram8GenerateEf+0x568>
 *   @0x2dc10c rsb r5, r5, #0
 *   @0x2dc110 mov r12, r11
 *   @0x2dc114 ldm r12, {r0, r1, r2, r3}
 *   @0x2dc118 add r4, r12, r5
 *   @0x2dc11c add r12, r12, #16
 *   @0x2dc120 cmp r12, r9
 *   @0x2dc124 stm r4, {r0, r1, r2, r3}
 *   @0x2dc128 blo 0x2dc114 <_ZN16b2VoronoiDiagram8GenerateEf+0x550>
 *   @0x2dc12c add r9, r9, r5
 *   @0x2dc130 add r11, r11, r5
 *   @0x2dc134 ldr r5, [sp, #0x4]
 *   @0x2dc138 cmp r5, r9
 *   @0x2dc13c bls 0x2dc3bc <_ZN16b2VoronoiDiagram8GenerateEf+0x7f8>
 *   @0x2dc140 ldr r5, [sp, #0x4]
 *   @0x2dc144 add r12, r9, #16
 *   @0x2dc148 str r6, [r9]
 *   @0x2dc14c cmp r5, r12
 *   @0x2dc150 ldr r5, [sp, #0x28]
 *   @0x2dc154 str r8, [r9, #0xc]
 *   @0x2dc158 str r5, [r9, #0x4]
 *   @0x2dc15c ldr r5, [sp, #0x8]
 *   @0x2dc160 str r5, [r9, #0x8]
 *   @0x2dc164 bls 0x2dc3c0 <_ZN16b2VoronoiDiagram8GenerateEf+0x7fc>
 *   @0x2dc168 ldr r5, [sp, #0xc]
 *   @0x2dc16c add r9, r12, #16
 *   @0x2dc170 str r6, [r12]
 *   @0x2dc174 stmib r12, {r5, r7}
 *   @0x2dc178 ldr r5, [sp]
 *   @0x2dc17c str r5, [r12, #0xc]
 *   @0x2dc180 ldr r5, [sp, #0x18]
 *   @0x2dc184 add r6, r6, #1
 *   @0x2dc188 add r10, r10, #4
 *   @0x2dc18c add r7, r7, #1
 *   @0x2dc190 cmp r6, r5
 *   @0x2dc194 bne 0x2dc0b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x4f4>
 *   @0x2dc198 ldr r5, [sp, #0x34]
 *   @0x2dc19c ldr r1, [sp, #0x30]
 *   @0x2dc1a0 cmp r5, r1
 *   @0x2dc1a4 ldr r5, [sp, #0xc]
 *   @0x2dc1a8 add r5, r5, #1
 *   @0x2dc1ac str r5, [sp, #0xc]
 *   @0x2dc1b0 bgt 0x2dc054 <_ZN16b2VoronoiDiagram8GenerateEf+0x490>
 *   @0x2dc1b4 mov r1, #0
 *   @0x2dc1b8 cmp r9, r11
 *   @0x2dc1bc bls 0x2dc384 <_ZN16b2VoronoiDiagram8GenerateEf+0x7c0>
 *   @0x2dc1c0 ldr r5, [sp, #0x2c]
 *   @0x2dc1c4 add r11, r11, #16
 *   @0x2dc1c8 ldr r6, [r11, #-0x8]
 *   @0x2dc1cc ldr r7, [r11, #-0x10]
 *   @0x2dc1d0 ldr r3, [r5, #0x14]
 *   @0x2dc1d4 ldr r5, [r11, #-0x4]
 *   @0x2dc1d8 add r2, r3, r6, lsl #2
 *   @0x2dc1dc ldr r8, [r11, #-0xc]
 *   @0x2dc1e0 ldr r3, [r3, r6, lsl #2]
 *   @0x2dc1e4 cmp r5, r3
 *   @0x2dc1e8 beq 0x2dc1b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f4>
 *   @0x2dc1ec vmov s10, r8
 *   @0x2dc1f0 vldr s13, [r5, #4]
 *   @0x2dc1f4 vldr s14, [r3, #4]
 *   @0x2dc1f8 vldr s12, [r3]
 *   @0x2dc1fc vcvt.f32.s32 s15, s10
 *   @0x2dc200 vldr s11, [r5]
 *   @0x2dc204 vmov s10, r7
 *   @0x2dc208 vsub.f32 s14, s14, s15
 *   @0x2dc20c vsub.f32 s15, s13, s15
 *   @0x2dc210 vcvt.f32.s32 s13, s10
 *   @0x2dc214 vmul.f32 s14, s14, s14
 *   @0x2dc218 vmul.f32 s15, s15, s15
 *   @0x2dc21c vsub.f32 s12, s12, s13
 *   @0x2dc220 vsub.f32 s13, s11, s13
 *   @0x2dc224 vmla.f32 s14, s12, s12
 *   @0x2dc228 vmla.f32 s15, s13, s13
 *   @0x2dc22c vcmpe.f32 s14, s15
 *   @0x2dc230 vmrs APSR_nzcv, fpscr
 *   @0x2dc234 ble 0x2dc1b8 <_ZN16b2VoronoiDiagram8GenerateEf+0x5f4>
 *   @0x2dc238 cmp r7, #0
 *   @0x2dc23c str r5, [r2]
 *   @0x2dc240 ble 0x2dc2c8 <_ZN16b2VoronoiDiagram8GenerateEf+0x704>
 *   @0x2dc244 ldr r1, [sp, #0x4]
 *   @0x2dc248 sub r2, r7, #1
 *   @0x2dc24c sub r3, r6, #1
 *   @0x2dc250 str r2, [sp]
 *   @0x2dc254 cmp r1, r9
 *   @0x2dc258 str r3, [sp, #0x8]
 *   @0x2dc25c bhi 0x2dc2b0 <_ZN16b2VoronoiDiagram8GenerateEf+0x6ec>
 *   @0x2dc260 ldr r1, [sp, #0x1c]
 *   @0x2dc264 cmp r11, r9
 *   @0x2dc268 rsb r3, r1, r11
 *   @0x2dc26c asr r3, r3, #4
 *   @0x2dc270 lsl r3, r3, #4
 *   @0x2dc274 rsbhs r10, r3, #0
 *   @0x2dc278 bhs 0x2dc29c <_ZN16b2VoronoiDiagram8GenerateEf+0x6d8>
 *   @0x2dc27c rsb r10, r3, #0
 *   @0x2dc280 mov r12, r11
 *   @0x2dc284 ldm r12, {r0, r1, r2, r3}
 *   @0x2dc288 add r4, r12, r10
 *   @0x2dc28c add r12, r12, #16
 *   @0x2dc290 cmp r9, r12
 *   @0x2dc294 stm r4, {r0, r1, r2, r3}
 *   @0x2dc298 bhi 0x2dc284 <_ZN16b2VoronoiDiagram8GenerateEf+0x6c0>
 *   @0x2dc29c ldr r2, [sp, #0x4]
 *   @0x2dc2a0 add r9, r9, r10
 *   @0x2dc2a4 add r11, r11, r10
 *   @0x2dc2a8 cmp r2, r9
 *   @0x2dc2ac bls 0x2dc2c8 <_ZN16b2VoronoiDiagram8GenerateEf+0x704>
 *   @0x2dc2b0 ldr r3, [sp]
 *   @0x2dc2b4 ldr r1, [sp, #0x8]
 *   @0x2dc2b8 str r5, [r9, #0xc]
 *   @0x2dc2bc stm r9, {r3, r8}
 *   @0x2dc2c0 add r9, r9, #16
 *   @0x2dc2c4 str r1, [r9, #-0x8]
 *   @0x2dc2c8 cmp r8, #0
 *   @0x2dc2cc ble 0x2dc35c <_ZN16b2VoronoiDiagram8GenerateEf+0x798>
 *   @0x2dc2d0 ldr r2, [sp, #0x4]
 *   @0x2dc2d4 sub r3, r8, #1
 *   @0x2dc2d8 ldr r1, [sp, #0x18]
 *   @0x2dc2dc cmp r2, r9
 *   @0x2dc2e0 str r3, [sp]
 *   @0x2dc2e4 rsb r1, r1, r6
 *   @0x2dc2e8 str r1, [sp, #0x8]
 *   @0x2dc2ec bhi 0x2dc340 <_ZN16b2VoronoiDiagram8GenerateEf+0x77c>
 *   @0x2dc2f0 ldr r2, [sp, #0x1c]
 *   @0x2dc2f4 cmp r9, r11
 *   @0x2dc2f8 rsb r3, r2, r11
 *   @0x2dc2fc asr r3, r3, #4
 *   @0x2dc300 lsl r3, r3, #4
 *   @0x2dc304 rsbls r10, r3, #0
 *   @0x2dc308 bls 0x2dc32c <_ZN16b2VoronoiDiagram8GenerateEf+0x768>
 *   @0x2dc30c rsb r10, r3, #0
 *   @0x2dc310 mov r12, r11
 *   @0x2dc314 ldm r12, {r0, r1, r2, r3}
 *   @0x2dc318 add r4, r12, r10
 *   @0x2dc31c add r12, r12, #16
 *   @0x2dc320 cmp r9, r12
 *   @0x2dc324 stm r4, {r0, r1, r2, r3}
 *   @0x2dc328 bhi 0x2dc314 <_ZN16b2VoronoiDiagram8GenerateEf+0x750>
 *   @0x2dc32c ldr r3, [sp, #0x4]
 *   @0x2dc330 add r9, r9, r10
 *   @0x2dc334 add r11, r11, r10
 *   @0x2dc338 cmp r3, r9
 *   @0x2dc33c bls 0x2dc35c <_ZN16b2VoronoiDiagram8GenerateEf+0x798>
 *   @0x2dc340 ldr r1, [sp]
 *   @0x2dc344 add r9, r9, #16
 *   @0x2dc348 ldr r2, [sp, #0x8]
 *   @0x2dc34c str r7, [r9, #-0x10]
 *   @0x2dc350 str r1, [r9, #-0xc]
 *   @0x2dc354 str r2, [r9, #-0x8]
 *   @0x2dc358 str r5, [r9, #-0x4]
 *   @0x2dc35c ldr r1, [sp, #0x18]
 *   @0x2dc360 sub r3, r1, #1
 *   @0x2dc364 cmp r7, r3
 *   @0x2dc368 blt 0x2dc494 <_ZN16b2VoronoiDiagram8GenerateEf+0x8d0>
 *   @0x2dc36c ldr r3, [sp, #0x34]
 *   @0x2dc370 cmp r8, r3
 *   @0x2dc374 blt 0x2dc418 <_ZN16b2VoronoiDiagram8GenerateEf+0x854>
 *   @0x2dc378 cmp r9, r11
 *   @0x2dc37c mov r1, #1
 *   @0x2dc380 bhi 0x2dc1c0 <_ZN16b2VoronoiDiagram8GenerateEf+0x5fc>
 *   @0x2dc384 cmp r1, #0
 *   @0x2dc388 beq 0x2dc3a4 <_ZN16b2VoronoiDiagram8GenerateEf+0x7e0>
 *   @0x2dc38c ldr r5, [sp, #0x3c]
 *   @0x2dc390 ldr r1, [sp, #0x40]
 *   @0x2dc394 add r5, r5, #1
 *   @0x2dc398 str r5, [sp, #0x3c]
 *   @0x2dc39c cmp r5, r1
 *   @0x2dc3a0 bne 0x2dbe90 <_ZN16b2VoronoiDiagram8GenerateEf+0x2cc>
 *   @0x2dc3a4 ldr r0, [sp, #0x44]
 *   @0x2dc3a8 ldr r1, [sp, #0x1c]
 *   @0x2dc3ac add sp, sp, #76
 *   @0x2dc3b0 vpop {d8, d9}
 *   @0x2dc3b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dc3b8 b 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2dc3bc mov r12, r9
 *   @0x2dc3c0 ldr r5, [sp, #0x1c]
 *   @0x2dc3c4 cmp r12, r11
 *   @0x2dc3c8 rsb r8, r5, r11
 *   @0x2dc3cc asr r8, r8, #4
 *   @0x2dc3d0 lsl r8, r8, #4
 *   @0x2dc3d4 rsbls r8, r8, #0
 *   @0x2dc3d8 bls 0x2dc3fc <_ZN16b2VoronoiDiagram8GenerateEf+0x838>
 *   @0x2dc3dc rsb r8, r8, #0
 *   @0x2dc3e0 mov r4, r11
 *   @0x2dc3e4 ldm r4, {r0, r1, r2, r3}
 *   @0x2dc3e8 add r5, r4, r8
 *   @0x2dc3ec add r4, r4, #16
 *   @0x2dc3f0 cmp r4, r12
 *   @0x2dc3f4 stm r5, {r0, r1, r2, r3}
 *   @0x2dc3f8 blo 0x2dc3e4 <_ZN16b2VoronoiDiagram8GenerateEf+0x820>
 *   @0x2dc3fc ldr r5, [sp, #0x4]
 *   @0x2dc400 add r12, r12, r8
 *   @0x2dc404 add r11, r11, r8
 *   @0x2dc408 cmp r5, r12
 *   @0x2dc40c movls r9, r12
 *   @0x2dc410 bhi 0x2dc168 <_ZN16b2VoronoiDiagram8GenerateEf+0x5a4>
 *   @0x2dc414 b 0x2dc180 <_ZN16b2VoronoiDiagram8GenerateEf+0x5bc>
 *   @0x2dc418 ldr r1, [sp, #0x4]
 *   @0x2dc41c add r8, r8, #1
 *   @0x2dc420 ldr r2, [sp, #0x18]
 *   @0x2dc424 cmp r1, r9
 *   @0x2dc428 add r6, r6, r2
 *   @0x2dc42c bhi 0x2dc480 <_ZN16b2VoronoiDiagram8GenerateEf+0x8bc>
 *   @0x2dc430 ldr r1, [sp, #0x1c]
 *   @0x2dc434 cmp r11, r9
 *   @0x2dc438 rsb r3, r1, r11
 *   @0x2dc43c asr r3, r3, #4
 *   @0x2dc440 lsl r3, r3, #4
 *   @0x2dc444 rsbhs r10, r3, #0
 *   @0x2dc448 bhs 0x2dc46c <_ZN16b2VoronoiDiagram8GenerateEf+0x8a8>
 *   @0x2dc44c rsb r10, r3, #0
 *   @0x2dc450 mov r12, r11
 *   @0x2dc454 ldm r12, {r0, r1, r2, r3}
 *   @0x2dc458 add r4, r12, r10
 *   @0x2dc45c add r12, r12, #16
 *   @0x2dc460 cmp r12, r9
 *   @0x2dc464 stm r4, {r0, r1, r2, r3}
 *   @0x2dc468 blo 0x2dc454 <_ZN16b2VoronoiDiagram8GenerateEf+0x890>
 *   @0x2dc46c ldr r2, [sp, #0x4]
 *   @0x2dc470 add r9, r9, r10
 *   @0x2dc474 add r11, r11, r10
 *   @0x2dc478 cmp r2, r9
 *   @0x2dc47c bls 0x2dc378 <_ZN16b2VoronoiDiagram8GenerateEf+0x7b4>
 *   @0x2dc480 stm r9, {r7, r8}
 *   @0x2dc484 add r9, r9, #16
 *   @0x2dc488 str r6, [r9, #-0x8]
 *   @0x2dc48c str r5, [r9, #-0x4]
 *   @0x2dc490 b 0x2dc378 <_ZN16b2VoronoiDiagram8GenerateEf+0x7b4>
 *   @0x2dc494 ldr r2, [sp, #0x4]
 *   @0x2dc498 add r3, r7, #1
 *   @0x2dc49c add r1, r6, #1
 *   @0x2dc4a0 str r3, [sp]
 *   @0x2dc4a4 cmp r2, r9
 *   @0x2dc4a8 str r1, [sp, #0x8]
 *   @0x2dc4ac bhi 0x2dc500 <_ZN16b2VoronoiDiagram8GenerateEf+0x93c>
 *   @0x2dc4b0 ldr r2, [sp, #0x1c]
 *   @0x2dc4b4 cmp r9, r11
 *   @0x2dc4b8 rsb r3, r2, r11
 *   @0x2dc4bc asr r3, r3, #4
 *   @0x2dc4c0 lsl r3, r3, #4
 *   @0x2dc4c4 rsbls r10, r3, #0
 *   @0x2dc4c8 bls 0x2dc4ec <_ZN16b2VoronoiDiagram8GenerateEf+0x928>
 *   @0x2dc4cc rsb r10, r3, #0
 *   @0x2dc4d0 mov r12, r11
 *   @0x2dc4d4 ldm r12, {r0, r1, r2, r3}
 *   @0x2dc4d8 add r4, r12, r10
 *   @0x2dc4dc add r12, r12, #16
 *   @0x2dc4e0 cmp r9, r12
 *   @0x2dc4e4 stm r4, {r0, r1, r2, r3}
 *   @0x2dc4e8 bhi 0x2dc4d4 <_ZN16b2VoronoiDiagram8GenerateEf+0x910>
 *   @0x2dc4ec ldr r3, [sp, #0x4]
 *   @0x2dc4f0 add r9, r9, r10
 *   @0x2dc4f4 add r11, r11, r10
 *   @0x2dc4f8 cmp r3, r9
 *   @0x2dc4fc bls 0x2dc36c <_ZN16b2VoronoiDiagram8GenerateEf+0x7a8>
 *   @0x2dc500 ldr r1, [sp]
 *   @0x2dc504 ldr r2, [sp, #0x8]
 *   @0x2dc508 str r5, [r9, #0xc]
 *   @0x2dc50c stm r9, {r1, r8}
 *   @0x2dc510 add r9, r9, #16
 *   @0x2dc514 str r2, [r9, #-0x8]
 *   @0x2dc518 b 0x2dc36c <_ZN16b2VoronoiDiagram8GenerateEf+0x7a8>
 *   @0x2dc51c add r12, r12, #1
 *   @0x2dc520 str r3, [r9, #0xc]
 *   @0x2dc524 cmp r12, r4
 *   @0x2dc528 add r0, r0, #12
 *   @0x2dc52c stm r9, {r1, r2, r5}
 *   @0x2dc530 add r9, r9, #16
 *   @0x2dc534 bne 0x2dbd60 <_ZN16b2VoronoiDiagram8GenerateEf+0x19c>
 *   @0x2dc538 b 0x2dbe00 <_ZN16b2VoronoiDiagram8GenerateEf+0x23c>
 *   @0x2dc53c cmp r4, #0
 *   @0x2dc540 str r6, [r1]
 *   @0x2dc544 mov r10, r11
 *   @0x2dc548 ble 0x2dc5c8 <_ZN16b2VoronoiDiagram8GenerateEf+0xa04>
 *   @0x2dc54c ldr r1, [sp, #0x4]
 *   @0x2dc550 sub r2, r4, #1
 *   @0x2dc554 sub r3, r12, #1
 *   @0x2dc558 str r2, [sp]
 *   @0x2dc55c cmp r1, r9
 *   @0x2dc560 str r3, [sp, #0x8]
 *   @0x2dc564 bhi 0x2dc5b0 <_ZN16b2VoronoiDiagram8GenerateEf+0x9ec>
 *   @0x2dc568 ldr r1, [sp, #0x1c]
 *   @0x2dc56c cmp r9, r11
 *   @0x2dc570 rsb r3, r1, r11
 *   @0x2dc574 asr r3, r3, #4
 *   @0x2dc578 lsl r3, r3, #4
 *   @0x2dc57c rsb r7, r3, #0
 *   @0x2dc580 bls 0x2dc59c <_ZN16b2VoronoiDiagram8GenerateEf+0x9d8>
 *   @0x2dc584 ldm r11, {r0, r1, r2, r3}
 *   @0x2dc588 add r8, r11, r7
 *   @0x2dc58c add r11, r11, #16
 *   @0x2dc590 cmp r11, r9
 *   @0x2dc594 stm r8, {r0, r1, r2, r3}
 *   @0x2dc598 blo 0x2dc584 <_ZN16b2VoronoiDiagram8GenerateEf+0x9c0>
 *   @0x2dc59c ldr r2, [sp, #0x4]
 *   @0x2dc5a0 add r9, r9, r7
 *   @0x2dc5a4 add r11, r10, r7
 *   @0x2dc5a8 cmp r2, r9
 *   @0x2dc5ac bls 0x2dc5c8 <_ZN16b2VoronoiDiagram8GenerateEf+0xa04>
 *   @0x2dc5b0 ldr r3, [sp]
 *   @0x2dc5b4 ldr r1, [sp, #0x8]
 *   @0x2dc5b8 str r6, [r9, #0xc]
 *   @0x2dc5bc stm r9, {r3, r5}
 *   @0x2dc5c0 add r9, r9, #16
 *   @0x2dc5c4 str r1, [r9, #-0x8]
 *   @0x2dc5c8 cmp r5, #0
 *   @0x2dc5cc ble 0x2dc65c <_ZN16b2VoronoiDiagram8GenerateEf+0xa98>
 *   @0x2dc5d0 ldr r2, [sp, #0x4]
 *   @0x2dc5d4 sub r3, r5, #1
 *   @0x2dc5d8 ldr r1, [sp, #0x18]
 *   @0x2dc5dc cmp r2, r9
 *   @0x2dc5e0 str r3, [sp]
 *   @0x2dc5e4 rsb r1, r1, r12
 *   @0x2dc5e8 str r1, [sp, #0x8]
 *   @0x2dc5ec bhi 0x2dc640 <_ZN16b2VoronoiDiagram8GenerateEf+0xa7c>
 *   @0x2dc5f0 ldr r2, [sp, #0x1c]
 *   @0x2dc5f4 cmp r11, r9
 *   @0x2dc5f8 rsb r3, r2, r11
 *   @0x2dc5fc asr r3, r3, #4
 *   @0x2dc600 lsl r3, r3, #4
 *   @0x2dc604 rsbhs r8, r3, #0
 *   @0x2dc608 bhs 0x2dc62c <_ZN16b2VoronoiDiagram8GenerateEf+0xa68>
 *   @0x2dc60c rsb r8, r3, #0
 *   @0x2dc610 mov r7, r11
 *   @0x2dc614 ldm r7, {r0, r1, r2, r3}
 *   @0x2dc618 add r10, r7, r8
 *   @0x2dc61c add r7, r7, #16
 *   @0x2dc620 cmp r7, r9
 *   @0x2dc624 stm r10, {r0, r1, r2, r3}
 *   @0x2dc628 blo 0x2dc614 <_ZN16b2VoronoiDiagram8GenerateEf+0xa50>
 *   @0x2dc62c ldr r3, [sp, #0x4]
 *   @0x2dc630 add r9, r9, r8
 *   @0x2dc634 add r11, r11, r8
 *   @0x2dc638 cmp r3, r9
 *   @0x2dc63c bls 0x2dc65c <_ZN16b2VoronoiDiagram8GenerateEf+0xa98>
 *   @0x2dc640 ldr r1, [sp]
 *   @0x2dc644 add r9, r9, #16
 *   @0x2dc648 ldr r2, [sp, #0x8]
 *   @0x2dc64c str r4, [r9, #-0x10]
 *   @0x2dc650 str r1, [r9, #-0xc]
 *   @0x2dc654 str r2, [r9, #-0x8]
 *   @0x2dc658 str r6, [r9, #-0x4]
 *   @0x2dc65c ldr r3, [sp, #0xc]
 *   @0x2dc660 cmp r3, r4
 *   @0x2dc664 bgt 0x2dc6e8 <_ZN16b2VoronoiDiagram8GenerateEf+0xb24>
 *   @0x2dc668 ldr r2, [sp, #0x10]
 *   @0x2dc66c cmp r2, r5
 *   @0x2dc670 ble 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258>
 *   @0x2dc674 ldr r3, [sp, #0x4]
 *   @0x2dc678 add r5, r5, #1
 *   @0x2dc67c ldr r1, [sp, #0x18]
 *   @0x2dc680 mov r8, r11
 *   @0x2dc684 cmp r3, r9
 *   @0x2dc688 add r10, r12, r1
 *   @0x2dc68c bhi 0x2dc6d8 <_ZN16b2VoronoiDiagram8GenerateEf+0xb14>
 *   @0x2dc690 ldr r2, [sp, #0x1c]
 *   @0x2dc694 cmp r11, r9
 *   @0x2dc698 rsb r3, r2, r11
 *   @0x2dc69c asr r3, r3, #4
 *   @0x2dc6a0 lsl r3, r3, #4
 *   @0x2dc6a4 rsb r12, r3, #0
 *   @0x2dc6a8 bhs 0x2dc6c4 <_ZN16b2VoronoiDiagram8GenerateEf+0xb00>
 *   @0x2dc6ac ldm r11, {r0, r1, r2, r3}
 *   @0x2dc6b0 add r7, r11, r12
 *   @0x2dc6b4 add r11, r11, #16
 *   @0x2dc6b8 cmp r11, r9
 *   @0x2dc6bc stm r7, {r0, r1, r2, r3}
 *   @0x2dc6c0 blo 0x2dc6ac <_ZN16b2VoronoiDiagram8GenerateEf+0xae8>
 *   @0x2dc6c4 ldr r3, [sp, #0x4]
 *   @0x2dc6c8 add r9, r9, r12
 *   @0x2dc6cc add r11, r8, r12
 *   @0x2dc6d0 cmp r3, r9
 *   @0x2dc6d4 bls 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258>
 *   @0x2dc6d8 stm r9, {r4, r5, r10}
 *   @0x2dc6dc add r9, r9, #16
 *   @0x2dc6e0 str r6, [r9, #-0x4]
 *   @0x2dc6e4 b 0x2dbe1c <_ZN16b2VoronoiDiagram8GenerateEf+0x258>
 *   @0x2dc6e8 ldr r1, [sp, #0x4]
 *   @0x2dc6ec add r2, r4, #1
 *   @0x2dc6f0 add r3, r12, #1
 *   @0x2dc6f4 str r2, [sp]
 *   @0x2dc6f8 cmp r1, r9
 *   @0x2dc6fc str r3, [sp, #0x8]
 *   @0x2dc700 bhi 0x2dc754 <_ZN16b2VoronoiDiagram8GenerateEf+0xb90>
 *   @0x2dc704 ldr r1, [sp, #0x1c]
 *   @0x2dc708 cmp r11, r9
 *   @0x2dc70c rsb r3, r1, r11
 *   @0x2dc710 asr r3, r3, #4
 *   @0x2dc714 lsl r3, r3, #4
 *   @0x2dc718 rsbhs r8, r3, #0
 *   @0x2dc71c bhs 0x2dc740 <_ZN16b2VoronoiDiagram8GenerateEf+0xb7c>
 *   @0x2dc720 rsb r8, r3, #0
 *   @0x2dc724 mov r7, r11
 *   @0x2dc728 ldm r7, {r0, r1, r2, r3}
 *   @0x2dc72c add r10, r7, r8
 *   @0x2dc730 add r7, r7, #16
 *   @0x2dc734 cmp r7, r9
 *   @0x2dc738 stm r10, {r0, r1, r2, r3}
 *   @0x2dc73c blo 0x2dc728 <_ZN16b2VoronoiDiagram8GenerateEf+0xb64>
 *   @0x2dc740 ldr r2, [sp, #0x4]
 *   @0x2dc744 add r9, r9, r8
 *   @0x2dc748 add r11, r11, r8
 *   @0x2dc74c cmp r2, r9
 *   @0x2dc750 bls 0x2dc668 <_ZN16b2VoronoiDiagram8GenerateEf+0xaa4>
 *   @0x2dc754 ldr r3, [sp]
 *   @0x2dc758 ldr r1, [sp, #0x8]
 *   @0x2dc75c str r6, [r9, #0xc]
 *   @0x2dc760 stm r9, {r3, r5}
 *   @0x2dc764 add r9, r9, #16
 *   @0x2dc768 str r1, [r9, #-0x8]
 *   @0x2dc76c b 0x2dc668 <_ZN16b2VoronoiDiagram8GenerateEf+0xaa4>
 *   @0x2dc770 vldr s15, [pc, #44]
 *   @0x2dc774 vldr s16, [pc, #44]
 *   @0x2dc778 vmov.f32 s12, s15
 *   @0x2dc77c vmov.f32 s17, s16
 *   @0x2dc780 b 0x2dbc4c <_ZN16b2VoronoiDiagram8GenerateEf+0x88>
 *   @0x2dc784 ldr r5, [sp, #0x2c]
 *   @0x2dc788 ldr r9, [sp, #0x1c]
 *   @0x2dc78c ldr r5, [r5, #0xc]
 *   @0x2dc790 str r5, [sp, #0x18]
 *   @0x2dc794 ldr r5, [sp, #0x2c]
 *   @0x2dc798 ldr r5, [r5, #0x10]
 *   @0x2dc79c str r5, [sp, #0x38]
 *   @0x2dc7a0 b 0x2dbe00 <_ZN16b2VoronoiDiagram8GenerateEf+0x23c>
 *   @0x2dc7a4 .word 0xff7fffff
 *   @0x2dc7a8 svcvc #0x7fffff
 *
 * ══ §8/13 F_GamepadGetDatabase(RValue&, CInstance*, CInstance*, int, RValue*)  0x151abc  size 3032  758 条（0x151abc..0x152694）
 * @func 0x151abc 0x152694  size 3032  758 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×18 / YYAlloc(int)×17 / 0xb65bc×17 / 0xb6538×3 / 0xb65a4×3 / YYStrBuilder::operator<<(int)×3 / F_GamepadGetDatabase(RValue&, CInstance*, CInstance*, int, RValue*)+0x10c / F_GamepadGetDatabase(RValue&, CInstance*, CInstance*, int, RValue*)+0x240
 * 字段偏移 top8: 0x34×54 / 0x3c×54 / 0x38×51 / 0x4×8 / 0x8×5 / 0x14×3 / 0xc×3 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151abc ldr r3, [pc, #0xb94]
 *   @0x151ac0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x151ac4 ldr r3, [pc, r3]
 *   @0x151ac8 sub sp, sp, #68
 *   @0x151acc mov r4, #0
 *   @0x151ad0 ldr r10, [r3]
 *   @0x151ad4 str r0, [sp, #0x2c]
 *   @0x151ad8 cmp r10, r4
 *   @0x151adc str r4, [sp, #0x34]
 *   @0x151ae0 str r4, [sp, #0x38]
 *   @0x151ae4 str r4, [sp, #0x3c]
 *   @0x151ae8 beq 0x152650 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb94>
 *   @0x151aec ldr r3, [pc, #0xb68]
 *   @0x151af0 mov r7, r4
 *   @0x151af4 ldr r12, [pc, #0xb64]
 *   @0x151af8 mov r8, r4
 *   @0x151afc add r3, pc, r3
 *   @0x151b00 str r3, [sp, #0x14]
 *   @0x151b04 ldr r3, [pc, #0xb58]
 *   @0x151b08 add r12, pc, r12
 *   @0x151b0c str r12, [sp, #0x1c]
 *   @0x151b10 ldr r12, [pc, #0xb50]
 *   @0x151b14 add r3, pc, r3
 *   @0x151b18 str r3, [sp, #0x24]
 *   @0x151b1c ldr r3, [sp, #0x14]
 *   @0x151b20 add r12, pc, r12
 *   @0x151b24 str r12, [sp, #0x20]
 *   @0x151b28 ldr r12, [pc, #0xb3c]
 *   @0x151b2c str r3, [sp, #0x18]
 *   @0x151b30 add r12, pc, r12
 *   @0x151b34 str r10, [sp]
 *   @0x151b38 str r12, [sp, #0x28]
 *   @0x151b3c ldr r3, [sp]
 *   @0x151b40 ldr r6, [r3, #0x4]
 *   @0x151b44 cmp r6, #0
 *   @0x151b48 beq 0x151be8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x151b4c mov r0, r6
 *   @0x151b50 bl 0xb6538 <strlen@plt>
 *   @0x151b54 mvn r2, r7
 *   @0x151b58 add r2, r2, r8
 *   @0x151b5c add r3, r0, #1
 *   @0x151b60 mov r5, r0
 *   @0x151b64 cmp r3, r2
 *   @0x151b68 ble 0x151bc8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x151b6c cmp r8, #0
 *   @0x151b70 moveq r8, r3
 *   @0x151b74 add r3, r3, r7
 *   @0x151b78 add r8, r8, r8, lsl #1
 *   @0x151b7c add r8, r8, r8, lsr #31
 *   @0x151b80 asr r7, r8, #1
 *   @0x151b84 cmp r7, r3
 *   @0x151b88 addlt r3, r3, r3, lsl #1
 *   @0x151b8c addlt r3, r3, r3, lsr #31
 *   @0x151b90 asrlt r7, r3, #1
 *   @0x151b94 mov r0, r7
 *   @0x151b98 bl 0xcef4c <_Z7YYAlloci>
 *   @0x151b9c mov r1, r4
 *   @0x151ba0 ldr r2, [sp, #0x38]
 *   @0x151ba4 str r0, [sp, #0x34]
 *   @0x151ba8 bl 0xb65bc <memcpy@plt>
 *   @0x151bac cmp r4, #0
 *   @0x151bb0 str r7, [sp, #0x38]
 *   @0x151bb4 beq 0x151bc0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x151bb8 mov r0, r4
 *   @0x151bbc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151bc0 ldr r7, [sp, #0x3c]
 *   @0x151bc4 ldr r4, [sp, #0x34]
 *   @0x151bc8 add r0, r4, r7
 *   @0x151bcc mov r1, r6
 *   @0x151bd0 bl 0xb65a4 <strcpy@plt>
 *   @0x151bd4 ldr r8, [sp, #0x38]
 *   @0x151bd8 ldr r4, [sp, #0x34]
 *   @0x151bdc ldr r7, [sp, #0x3c]
 *   @0x151be0 add r7, r5, r7
 *   @0x151be4 str r7, [sp, #0x3c]
 *   @0x151be8 mvn r3, r7
 *   @0x151bec add r3, r3, r8
 *   @0x151bf0 cmp r3, #1
 *   @0x151bf4 bgt 0x151c54 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x151bf8 cmp r8, #0
 *   @0x151bfc add r7, r7, #2
 *   @0x151c00 addne r8, r8, r8, lsl #1
 *   @0x151c04 moveq r5, #3
 *   @0x151c08 addne r8, r8, r8, lsr #31
 *   @0x151c0c asrne r5, r8, #1
 *   @0x151c10 cmp r7, r5
 *   @0x151c14 addgt r7, r7, r7, lsl #1
 *   @0x151c18 addgt r7, r7, r7, lsr #31
 *   @0x151c1c asrgt r5, r7, #1
 *   @0x151c20 mov r0, r5
 *   @0x151c24 bl 0xcef4c <_Z7YYAlloci>
 *   @0x151c28 mov r1, r4
 *   @0x151c2c ldr r2, [sp, #0x38]
 *   @0x151c30 str r0, [sp, #0x34]
 *   @0x151c34 bl 0xb65bc <memcpy@plt>
 *   @0x151c38 cmp r4, #0
 *   @0x151c3c str r5, [sp, #0x38]
 *   @0x151c40 beq 0x151c4c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x151c44 mov r0, r4
 *   @0x151c48 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151c4c ldr r7, [sp, #0x3c]
 *   @0x151c50 ldr r4, [sp, #0x34]
 *   @0x151c54 ldr r12, [sp, #0x14]
 *   @0x151c58 ldrh r3, [r12]
 *   @0x151c5c strh r3, [r4, r7]
 *   @0x151c60 ldr r3, [sp]
 *   @0x151c64 ldr r5, [sp, #0x3c]
 *   @0x151c68 ldr r6, [r3, #0x8]
 *   @0x151c6c add r5, r5, #1
 *   @0x151c70 str r5, [sp, #0x3c]
 *   @0x151c74 cmp r6, #0
 *   @0x151c78 beq 0x151d18 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x151c7c mov r0, r6
 *   @0x151c80 bl 0xb6538 <strlen@plt>
 *   @0x151c84 ldr r3, [sp, #0x38]
 *   @0x151c88 mvn r1, r5
 *   @0x151c8c add r1, r3, r1
 *   @0x151c90 add r2, r0, #1
 *   @0x151c94 mov r4, r0
 *   @0x151c98 cmp r2, r1
 *   @0x151c9c ble 0x151cfc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x240>
 *   @0x151ca0 cmp r3, #0
 *   @0x151ca4 moveq r3, r2
 *   @0x151ca8 add r2, r5, r2
 *   @0x151cac add r3, r3, r3, lsl #1
 *   @0x151cb0 ldr r5, [sp, #0x34]
 *   @0x151cb4 add r3, r3, r3, lsr #31
 *   @0x151cb8 asr r7, r3, #1
 *   @0x151cbc cmp r7, r2
 *   @0x151cc0 addlt r2, r2, r2, lsl #1
 *   @0x151cc4 addlt r2, r2, r2, lsr #31
 *   @0x151cc8 asrlt r7, r2, #1
 *   @0x151ccc mov r0, r7
 *   @0x151cd0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x151cd4 ldr r2, [sp, #0x38]
 *   @0x151cd8 mov r1, r5
 *   @0x151cdc str r0, [sp, #0x34]
 *   @0x151ce0 bl 0xb65bc <memcpy@plt>
 *   @0x151ce4 cmp r5, #0
 *   @0x151ce8 str r7, [sp, #0x38]
 *   @0x151cec beq 0x151cf8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x151cf0 mov r0, r5
 *   @0x151cf4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151cf8 ldr r5, [sp, #0x3c]
 *   @0x151cfc ldr r0, [sp, #0x34]
 *   @0x151d00 mov r1, r6
 *   @0x151d04 add r0, r0, r5
 *   @0x151d08 bl 0xb65a4 <strcpy@plt>
 *   @0x151d0c ldr r5, [sp, #0x3c]
 *   @0x151d10 add r5, r4, r5
 *   @0x151d14 str r5, [sp, #0x3c]
 *   @0x151d18 ldr r3, [sp, #0x38]
 *   @0x151d1c mvn r2, r5
 *   @0x151d20 add r2, r3, r2
 *   @0x151d24 cmp r2, #1
 *   @0x151d28 bgt 0x151d88 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x2cc>
 *   @0x151d2c cmp r3, #0
 *   @0x151d30 add r5, r5, #2
 *   @0x151d34 addne r3, r3, r3, lsl #1
 *   @0x151d38 ldr r4, [sp, #0x34]
 *   @0x151d3c moveq r6, #3
 *   @0x151d40 addne r3, r3, r3, lsr #31
 *   @0x151d44 asrne r6, r3, #1
 *   @0x151d48 cmp r5, r6
 *   @0x151d4c addgt r5, r5, r5, lsl #1
 *   @0x151d50 addgt r5, r5, r5, lsr #31
 *   @0x151d54 asrgt r6, r5, #1
 *   @0x151d58 mov r0, r6
 *   @0x151d5c bl 0xcef4c <_Z7YYAlloci>
 *   @0x151d60 ldr r2, [sp, #0x38]
 *   @0x151d64 mov r1, r4
 *   @0x151d68 str r0, [sp, #0x34]
 *   @0x151d6c bl 0xb65bc <memcpy@plt>
 *   @0x151d70 cmp r4, #0
 *   @0x151d74 str r6, [sp, #0x38]
 *   @0x151d78 beq 0x151d84 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x151d7c mov r0, r4
 *   @0x151d80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151d84 ldr r5, [sp, #0x3c]
 *   @0x151d88 ldr r12, [sp, #0x18]
 *   @0x151d8c ldr r3, [sp, #0x34]
 *   @0x151d90 ldrh r2, [r12]
 *   @0x151d94 strh r2, [r3, r5]
 *   @0x151d98 ldr r1, [sp, #0x3c]
 *   @0x151d9c ldr r3, [sp, #0x38]
 *   @0x151da0 add r2, r1, #1
 *   @0x151da4 str r2, [sp, #0x3c]
 *   @0x151da8 mvn r0, r2
 *   @0x151dac add r0, r3, r0
 *   @0x151db0 cmp r0, #9
 *   @0x151db4 bgt 0x151e14 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x151db8 cmp r3, #0
 *   @0x151dbc add r1, r1, #11
 *   @0x151dc0 addne r3, r3, r3, lsl #1
 *   @0x151dc4 ldr r4, [sp, #0x34]
 *   @0x151dc8 moveq r5, #15
 *   @0x151dcc addne r3, r3, r3, lsr #31
 *   @0x151dd0 asrne r5, r3, #1
 *   @0x151dd4 cmp r1, r5
 *   @0x151dd8 addgt r1, r1, r1, lsl #1
 *   @0x151ddc addgt r1, r1, r1, lsr #31
 *   @0x151de0 asrgt r5, r1, #1
 *   @0x151de4 mov r0, r5
 *   @0x151de8 bl 0xcef4c <_Z7YYAlloci>
 *   @0x151dec ldr r2, [sp, #0x38]
 *   @0x151df0 mov r1, r4
 *   @0x151df4 str r0, [sp, #0x34]
 *   @0x151df8 bl 0xb65bc <memcpy@plt>
 *   @0x151dfc cmp r4, #0
 *   @0x151e00 str r5, [sp, #0x38]
 *   @0x151e04 beq 0x151e10 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x354>
 *   @0x151e08 mov r0, r4
 *   @0x151e0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151e10 ldr r2, [sp, #0x3c]
 *   @0x151e14 ldr r3, [sp, #0x1c]
 *   @0x151e18 ldr lr, [sp, #0x34]
 *   @0x151e1c ldm r3!, {r0, r1}
 *   @0x151e20 add r12, lr, r2
 *   @0x151e24 ldrh r3, [r3]
 *   @0x151e28 str r0, [lr, r2]
 *   @0x151e2c str r1, [r12, #0x4]
 *   @0x151e30 strh r3, [r12, #8]
 *   @0x151e34 ldr r3, [sp]
 *   @0x151e38 ldr r1, [sp, #0x3c]
 *   @0x151e3c ldr r2, [r3, #0xc]
 *   @0x151e40 add r3, r1, #9
 *   @0x151e44 str r3, [sp, #0x3c]
 *   @0x151e48 cmp r2, #1
 *   @0x151e4c beq 0x15257c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xac0>
 *   @0x151e50 cmp r2, #6
 *   @0x151e54 ldr r2, [sp, #0x38]
 *   @0x151e58 mvn r0, r3
 *   @0x151e5c add r0, r2, r0
 *   @0x151e60 beq 0x1524ec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa30>
 *   @0x151e64 cmp r0, #7
 *   @0x151e68 bgt 0x151ec8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x40c>
 *   @0x151e6c cmp r2, #0
 *   @0x151e70 add r1, r1, #17
 *   @0x151e74 addne r2, r2, r2, lsl #1
 *   @0x151e78 ldr r4, [sp, #0x34]
 *   @0x151e7c moveq r5, #12
 *   @0x151e80 addne r2, r2, r2, lsr #31
 *   @0x151e84 asrne r5, r2, #1
 *   @0x151e88 cmp r1, r5
 *   @0x151e8c addgt r1, r1, r1, lsl #1
 *   @0x151e90 addgt r1, r1, r1, lsr #31
 *   @0x151e94 asrgt r5, r1, #1
 *   @0x151e98 mov r0, r5
 *   @0x151e9c bl 0xcef4c <_Z7YYAlloci>
 *   @0x151ea0 ldr r2, [sp, #0x38]
 *   @0x151ea4 mov r1, r4
 *   @0x151ea8 str r0, [sp, #0x34]
 *   @0x151eac bl 0xb65bc <memcpy@plt>
 *   @0x151eb0 cmp r4, #0
 *   @0x151eb4 str r5, [sp, #0x38]
 *   @0x151eb8 beq 0x151ec4 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x408>
 *   @0x151ebc mov r0, r4
 *   @0x151ec0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151ec4 ldr r3, [sp, #0x3c]
 *   @0x151ec8 ldr r2, [sp, #0x28]
 *   @0x151ecc ldr r12, [sp, #0x34]
 *   @0x151ed0 ldm r2!, {r0, r1}
 *   @0x151ed4 add r2, r12, r3
 *   @0x151ed8 str r0, [r12, r3]
 *   @0x151edc str r1, [r2, #0x4]
 *   @0x151ee0 ldr r3, [sp, #0x3c]
 *   @0x151ee4 add r3, r3, #7
 *   @0x151ee8 str r3, [sp, #0x3c]
 *   @0x151eec ldr r2, [sp, #0x38]
 *   @0x151ef0 mvn r1, r3
 *   @0x151ef4 add r1, r2, r1
 *   @0x151ef8 cmp r1, #1
 *   @0x151efc bgt 0x151f5c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x4a0>
 *   @0x151f00 cmp r2, #0
 *   @0x151f04 add r3, r3, #2
 *   @0x151f08 addne r2, r2, r2, lsl #1
 *   @0x151f0c ldr r4, [sp, #0x34]
 *   @0x151f10 moveq r5, #3
 *   @0x151f14 addne r2, r2, r2, lsr #31
 *   @0x151f18 asrne r5, r2, #1
 *   @0x151f1c cmp r3, r5
 *   @0x151f20 addgt r3, r3, r3, lsl #1
 *   @0x151f24 addgt r3, r3, r3, lsr #31
 *   @0x151f28 asrgt r5, r3, #1
 *   @0x151f2c mov r0, r5
 *   @0x151f30 bl 0xcef4c <_Z7YYAlloci>
 *   @0x151f34 ldr r2, [sp, #0x38]
 *   @0x151f38 mov r1, r4
 *   @0x151f3c str r0, [sp, #0x34]
 *   @0x151f40 bl 0xb65bc <memcpy@plt>
 *   @0x151f44 cmp r4, #0
 *   @0x151f48 str r5, [sp, #0x38]
 *   @0x151f4c beq 0x151f58 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x151f50 mov r0, r4
 *   @0x151f54 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x151f58 ldr r3, [sp, #0x3c]
 *   @0x151f5c ldr r1, [pc, #0x70c]
 *   @0x151f60 mov r5, #0
 *   @0x151f64 ldr r2, [sp, #0x34]
 *   @0x151f68 add r1, pc, r1
 *   @0x151f6c ldr r12, [sp]
 *   @0x151f70 ldr r9, [pc, #0x6fc]
 *   @0x151f74 ldrh r1, [r1]
 *   @0x151f78 add r4, r12, #28
 *   @0x151f7c ldr r12, [pc, #0x6f4]
 *   @0x151f80 add r9, pc, r9
 *   @0x151f84 ldr r8, [pc, #0x6f0]
 *   @0x151f88 strh r1, [r2, r3]
 *   @0x151f8c add r12, pc, r12
 *   @0x151f90 ldr r2, [sp, #0x3c]
 *   @0x151f94 add r8, pc, r8
 *   @0x151f98 ldr r3, [pc, #0x6e0]
 *   @0x151f9c add r11, r2, #1
 *   @0x151fa0 str r12, [sp, #0x4]
 *   @0x151fa4 add r3, pc, r3
 *   @0x151fa8 ldr r12, [pc, #0x6d4]
 *   @0x151fac str r3, [sp, #0x8]
 *   @0x151fb0 mov r10, r11
 *   @0x151fb4 ldr r3, [pc, #0x6cc]
 *   @0x151fb8 add r12, pc, r12
 *   @0x151fbc str r11, [sp, #0x3c]
 *   @0x151fc0 add r3, pc, r3
 *   @0x151fc4 str r12, [sp, #0xc]
 *   @0x151fc8 str r3, [sp, #0x10]
 *   @0x151fcc b 0x151fe0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x151fd0 add r5, r5, #8
 *   @0x151fd4 add r4, r4, #12
 *   @0x151fd8 cmp r5, #168
 *   @0x151fdc beq 0x1521d8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x71c>
 *   @0x151fe0 ldr r3, [r4, #-0xc]
 *   @0x151fe4 cmp r3, #0
 *   @0x151fe8 beq 0x151fd0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x514>
 *   @0x151fec ldr r3, [pc, #0x698]
 *   @0x151ff0 ldr r3, [pc, r3]
 *   @0x151ff4 ldr r11, [r5, r3]
 *   @0x151ff8 cmp r11, #0
 *   @0x151ffc beq 0x15209c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5e0>
 *   @0x152000 mov r0, r11
 *   @0x152004 bl 0xb6538 <strlen@plt>
 *   @0x152008 ldr r12, [sp, #0x38]
 *   @0x15200c add r1, r0, #1
 *   @0x152010 mov r6, r0
 *   @0x152014 mvn r0, r10
 *   @0x152018 add r0, r12, r0
 *   @0x15201c cmp r1, r0
 *   @0x152020 ble 0x152080 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5c4>
 *   @0x152024 cmp r12, #0
 *   @0x152028 add r2, r1, r10
 *   @0x15202c ldr r7, [sp, #0x34]
 *   @0x152030 moveq r12, r1
 *   @0x152034 add r12, r12, r12, lsl #1
 *   @0x152038 add r12, r12, r12, lsr #31
 *   @0x15203c asr r10, r12, #1
 *   @0x152040 cmp r10, r2
 *   @0x152044 addlt r2, r2, r2, lsl #1
 *   @0x152048 addlt r2, r2, r2, lsr #31
 *   @0x15204c asrlt r10, r2, #1
 *   @0x152050 mov r0, r10
 *   @0x152054 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152058 ldr r2, [sp, #0x38]
 *   @0x15205c mov r1, r7
 *   @0x152060 str r0, [sp, #0x34]
 *   @0x152064 bl 0xb65bc <memcpy@plt>
 *   @0x152068 cmp r7, #0
 *   @0x15206c str r10, [sp, #0x38]
 *   @0x152070 beq 0x15207c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5c0>
 *   @0x152074 mov r0, r7
 *   @0x152078 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15207c ldr r10, [sp, #0x3c]
 *   @0x152080 ldr r0, [sp, #0x34]
 *   @0x152084 mov r1, r11
 *   @0x152088 add r0, r0, r10
 *   @0x15208c bl 0xb65a4 <strcpy@plt>
 *   @0x152090 ldr r2, [sp, #0x3c]
 *   @0x152094 add r10, r6, r2
 *   @0x152098 str r10, [sp, #0x3c]
 *   @0x15209c ldr r7, [sp, #0x38]
 *   @0x1520a0 mvn r3, r10
 *   @0x1520a4 add r3, r7, r3
 *   @0x1520a8 cmp r3, #1
 *   @0x1520ac bgt 0x15210c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x650>
 *   @0x1520b0 cmp r7, #0
 *   @0x1520b4 add r2, r10, #2
 *   @0x1520b8 addne r7, r7, r7, lsl #1
 *   @0x1520bc ldr r6, [sp, #0x34]
 *   @0x1520c0 moveq r7, #3
 *   @0x1520c4 addne r7, r7, r7, lsr #31
 *   @0x1520c8 asrne r7, r7, #1
 *   @0x1520cc cmp r2, r7
 *   @0x1520d0 addgt r2, r2, r2, lsl #1
 *   @0x1520d4 addgt r2, r2, r2, lsr #31
 *   @0x1520d8 asrgt r7, r2, #1
 *   @0x1520dc mov r0, r7
 *   @0x1520e0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1520e4 ldr r2, [sp, #0x38]
 *   @0x1520e8 mov r1, r6
 *   @0x1520ec str r0, [sp, #0x34]
 *   @0x1520f0 bl 0xb65bc <memcpy@plt>
 *   @0x1520f4 cmp r6, #0
 *   @0x1520f8 str r7, [sp, #0x38]
 *   @0x1520fc beq 0x152108 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x64c>
 *   @0x152100 mov r0, r6
 *   @0x152104 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152108 ldr r10, [sp, #0x3c]
 *   @0x15210c ldr r3, [sp, #0x34]
 *   @0x152110 ldrh r1, [r9]
 *   @0x152114 strh r1, [r3, r10]
 *   @0x152118 ldr r0, [r4, #-0xc]
 *   @0x15211c ldr r2, [sp, #0x3c]
 *   @0x152120 cmp r0, #2
 *   @0x152124 add r3, r2, #1
 *   @0x152128 str r3, [sp, #0x3c]
 *   @0x15212c beq 0x15246c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x9b0>
 *   @0x152130 cmp r0, #3
 *   @0x152134 beq 0x15232c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x870>
 *   @0x152138 cmp r0, #1
 *   @0x15213c beq 0x15228c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x7d0>
 *   @0x152140 ldr r7, [sp, #0x38]
 *   @0x152144 mvn r2, r3
 *   @0x152148 add r2, r7, r2
 *   @0x15214c cmp r2, #1
 *   @0x152150 bgt 0x1521b0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x6f4>
 *   @0x152154 cmp r7, #0
 *   @0x152158 add r3, r3, #2
 *   @0x15215c addne r7, r7, r7, lsl #1
 *   @0x152160 ldr r6, [sp, #0x34]
 *   @0x152164 moveq r7, #3
 *   @0x152168 addne r7, r7, r7, lsr #31
 *   @0x15216c asrne r7, r7, #1
 *   @0x152170 cmp r3, r7
 *   @0x152174 addgt r3, r3, r3, lsl #1
 *   @0x152178 addgt r3, r3, r3, lsr #31
 *   @0x15217c asrgt r7, r3, #1
 *   @0x152180 mov r0, r7
 *   @0x152184 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152188 ldr r2, [sp, #0x38]
 *   @0x15218c mov r1, r6
 *   @0x152190 str r0, [sp, #0x34]
 *   @0x152194 bl 0xb65bc <memcpy@plt>
 *   @0x152198 cmp r6, #0
 *   @0x15219c str r7, [sp, #0x38]
 *   @0x1521a0 beq 0x1521ac <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x6f0>
 *   @0x1521a4 mov r0, r6
 *   @0x1521a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1521ac ldr r3, [sp, #0x3c]
 *   @0x1521b0 ldr r2, [sp, #0x34]
 *   @0x1521b4 add r5, r5, #8
 *   @0x1521b8 ldrh r1, [r8]
 *   @0x1521bc cmp r5, #168
 *   @0x1521c0 add r4, r4, #12
 *   @0x1521c4 strh r1, [r2, r3]
 *   @0x1521c8 ldr r2, [sp, #0x3c]
 *   @0x1521cc add r10, r2, #1
 *   @0x1521d0 str r10, [sp, #0x3c]
 *   @0x1521d4 bne 0x151fe0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x1521d8 ldr r3, [sp, #0x38]
 *   @0x1521dc mvn r1, r10
 *   @0x1521e0 mov r11, r10
 *   @0x1521e4 add r1, r3, r1
 *   @0x1521e8 cmp r1, #1
 *   @0x1521ec bgt 0x15224c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x790>
 *   @0x1521f0 cmp r3, #0
 *   @0x1521f4 add r2, r10, #2
 *   @0x1521f8 addne r3, r3, r3, lsl #1
 *   @0x1521fc ldr r4, [sp, #0x34]
 *   @0x152200 moveq r5, #3
 *   @0x152204 addne r3, r3, r3, lsr #31
 *   @0x152208 asrne r5, r3, #1
 *   @0x15220c cmp r2, r5
 *   @0x152210 addgt r2, r2, r2, lsl #1
 *   @0x152214 addgt r2, r2, r2, lsr #31
 *   @0x152218 asrgt r5, r2, #1
 *   @0x15221c mov r0, r5
 *   @0x152220 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152224 ldr r2, [sp, #0x38]
 *   @0x152228 mov r1, r4
 *   @0x15222c str r0, [sp, #0x34]
 *   @0x152230 bl 0xb65bc <memcpy@plt>
 *   @0x152234 cmp r4, #0
 *   @0x152238 str r5, [sp, #0x38]
 *   @0x15223c beq 0x152248 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x78c>
 *   @0x152240 mov r0, r4
 *   @0x152244 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152248 ldr r11, [sp, #0x3c]
 *   @0x15224c ldr r1, [pc, #0x43c]
 *   @0x152250 ldr r3, [sp, #0x34]
 *   @0x152254 add r1, pc, r1
 *   @0x152258 ldrh r1, [r1]
 *   @0x15225c strh r1, [r3, r11]
 *   @0x152260 ldr r3, [sp]
 *   @0x152264 ldr r7, [sp, #0x3c]
 *   @0x152268 ldr r3, [r3]
 *   @0x15226c add r7, r7, #1
 *   @0x152270 str r7, [sp, #0x3c]
 *   @0x152274 cmp r3, #0
 *   @0x152278 str r3, [sp]
 *   @0x15227c beq 0x15261c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb60>
 *   @0x152280 ldr r4, [sp, #0x34]
 *   @0x152284 ldr r8, [sp, #0x38]
 *   @0x152288 b 0x151b3c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x15228c ldr r1, [sp, #0x38]
 *   @0x152290 mvn r0, r3
 *   @0x152294 add r0, r1, r0
 *   @0x152298 cmp r0, #1
 *   @0x15229c bgt 0x1522fc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x840>
 *   @0x1522a0 cmp r1, #0
 *   @0x1522a4 add r2, r2, #3
 *   @0x1522a8 addne r1, r1, r1, lsl #1
 *   @0x1522ac ldr r6, [sp, #0x34]
 *   @0x1522b0 moveq r7, #3
 *   @0x1522b4 addne r1, r1, r1, lsr #31
 *   @0x1522b8 asrne r7, r1, #1
 *   @0x1522bc cmp r2, r7
 *   @0x1522c0 addgt r2, r2, r2, lsl #1
 *   @0x1522c4 addgt r2, r2, r2, lsr #31
 *   @0x1522c8 asrgt r7, r2, #1
 *   @0x1522cc mov r0, r7
 *   @0x1522d0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1522d4 ldr r2, [sp, #0x38]
 *   @0x1522d8 mov r1, r6
 *   @0x1522dc str r0, [sp, #0x34]
 *   @0x1522e0 bl 0xb65bc <memcpy@plt>
 *   @0x1522e4 cmp r6, #0
 *   @0x1522e8 str r7, [sp, #0x38]
 *   @0x1522ec beq 0x1522f8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x83c>
 *   @0x1522f0 mov r0, r6
 *   @0x1522f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1522f8 ldr r3, [sp, #0x3c]
 *   @0x1522fc ldr r2, [sp, #0x34]
 *   @0x152300 add r0, sp, #52
 *   @0x152304 ldr r12, [sp, #0x10]
 *   @0x152308 ldrh r1, [r12]
 *   @0x15230c strh r1, [r2, r3]
 *   @0x152310 ldr r3, [sp, #0x3c]
 *   @0x152314 ldr r1, [r4, #-0x8]
 *   @0x152318 add r3, r3, #1
 *   @0x15231c str r3, [sp, #0x3c]
 *   @0x152320 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0x152324 ldr r3, [sp, #0x3c]
 *   @0x152328 b 0x152140 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x684>
 *   @0x15232c ldr r1, [sp, #0x38]
 *   @0x152330 mvn r12, r3
 *   @0x152334 add r12, r1, r12
 *   @0x152338 cmp r12, #1
 *   @0x15233c bgt 0x15239c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x8e0>
 *   @0x152340 cmp r1, #0
 *   @0x152344 add r2, r2, #3
 *   @0x152348 addne r1, r1, r1, lsl #1
 *   @0x15234c ldr r6, [sp, #0x34]
 *   @0x152350 moveq r7, r0
 *   @0x152354 addne r1, r1, r1, lsr #31
 *   @0x152358 asrne r7, r1, #1
 *   @0x15235c cmp r2, r7
 *   @0x152360 addgt r2, r2, r2, lsl #1
 *   @0x152364 addgt r2, r2, r2, lsr #31
 *   @0x152368 asrgt r7, r2, #1
 *   @0x15236c mov r0, r7
 *   @0x152370 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152374 ldr r2, [sp, #0x38]
 *   @0x152378 mov r1, r6
 *   @0x15237c str r0, [sp, #0x34]
 *   @0x152380 bl 0xb65bc <memcpy@plt>
 *   @0x152384 cmp r6, #0
 *   @0x152388 str r7, [sp, #0x38]
 *   @0x15238c beq 0x152398 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x8dc>
 *   @0x152390 mov r0, r6
 *   @0x152394 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152398 ldr r3, [sp, #0x3c]
 *   @0x15239c ldr r12, [sp, #0x8]
 *   @0x1523a0 add r6, sp, #52
 *   @0x1523a4 ldr r2, [sp, #0x34]
 *   @0x1523a8 mov r0, r6
 *   @0x1523ac ldrh r1, [r12]
 *   @0x1523b0 strh r1, [r2, r3]
 *   @0x1523b4 ldr r3, [sp, #0x3c]
 *   @0x1523b8 ldr r1, [r4, #-0x8]
 *   @0x1523bc add r3, r3, #1
 *   @0x1523c0 str r3, [sp, #0x3c]
 *   @0x1523c4 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0x1523c8 ldr r2, [sp, #0x3c]
 *   @0x1523cc ldr r3, [sp, #0x38]
 *   @0x1523d0 mvn r1, r2
 *   @0x1523d4 add r1, r3, r1
 *   @0x1523d8 cmp r1, #1
 *   @0x1523dc bgt 0x15243c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x980>
 *   @0x1523e0 cmp r3, #0
 *   @0x1523e4 add r2, r2, #2
 *   @0x1523e8 addne r3, r3, r3, lsl #1
 *   @0x1523ec ldr r7, [sp, #0x34]
 *   @0x1523f0 moveq r10, #3
 *   @0x1523f4 addne r3, r3, r3, lsr #31
 *   @0x1523f8 asrne r10, r3, #1
 *   @0x1523fc cmp r2, r10
 *   @0x152400 addgt r2, r2, r2, lsl #1
 *   @0x152404 addgt r2, r2, r2, lsr #31
 *   @0x152408 asrgt r10, r2, #1
 *   @0x15240c mov r0, r10
 *   @0x152410 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152414 ldr r2, [sp, #0x38]
 *   @0x152418 mov r1, r7
 *   @0x15241c str r0, [sp, #0x34]
 *   @0x152420 bl 0xb65bc <memcpy@plt>
 *   @0x152424 cmp r7, #0
 *   @0x152428 str r10, [sp, #0x38]
 *   @0x15242c beq 0x152438 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x97c>
 *   @0x152430 mov r0, r7
 *   @0x152434 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152438 ldr r2, [sp, #0x3c]
 *   @0x15243c ldr r12, [sp, #0xc]
 *   @0x152440 mov r0, r6
 *   @0x152444 ldr r3, [sp, #0x34]
 *   @0x152448 ldrh r1, [r12]
 *   @0x15244c strh r1, [r3, r2]
 *   @0x152450 ldr r3, [sp, #0x3c]
 *   @0x152454 ldr r1, [r4, #-0x4]
 *   @0x152458 add r3, r3, #1
 *   @0x15245c str r3, [sp, #0x3c]
 *   @0x152460 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0x152464 ldr r3, [sp, #0x3c]
 *   @0x152468 b 0x152140 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x684>
 *   @0x15246c ldr r1, [sp, #0x38]
 *   @0x152470 mvn r0, r3
 *   @0x152474 add r0, r1, r0
 *   @0x152478 cmp r0, #1
 *   @0x15247c bgt 0x1524dc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa20>
 *   @0x152480 cmp r1, #0
 *   @0x152484 add r2, r2, #3
 *   @0x152488 addne r1, r1, r1, lsl #1
 *   @0x15248c ldr r6, [sp, #0x34]
 *   @0x152490 moveq r7, #3
 *   @0x152494 addne r1, r1, r1, lsr #31
 *   @0x152498 asrne r7, r1, #1
 *   @0x15249c cmp r2, r7
 *   @0x1524a0 addgt r2, r2, r2, lsl #1
 *   @0x1524a4 addgt r2, r2, r2, lsr #31
 *   @0x1524a8 asrgt r7, r2, #1
 *   @0x1524ac mov r0, r7
 *   @0x1524b0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1524b4 ldr r2, [sp, #0x38]
 *   @0x1524b8 mov r1, r6
 *   @0x1524bc str r0, [sp, #0x34]
 *   @0x1524c0 bl 0xb65bc <memcpy@plt>
 *   @0x1524c4 cmp r6, #0
 *   @0x1524c8 str r7, [sp, #0x38]
 *   @0x1524cc beq 0x1524d8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa1c>
 *   @0x1524d0 mov r0, r6
 *   @0x1524d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1524d8 ldr r3, [sp, #0x3c]
 *   @0x1524dc ldr r2, [sp, #0x34]
 *   @0x1524e0 add r0, sp, #52
 *   @0x1524e4 ldr r12, [sp, #0x4]
 *   @0x1524e8 b 0x152308 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x84c>
 *   @0x1524ec cmp r0, #5
 *   @0x1524f0 bgt 0x152550 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa94>
 *   @0x1524f4 cmp r2, #0
 *   @0x1524f8 add r1, r1, #15
 *   @0x1524fc addne r2, r2, r2, lsl #1
 *   @0x152500 ldr r4, [sp, #0x34]
 *   @0x152504 moveq r5, #9
 *   @0x152508 addne r2, r2, r2, lsr #31
 *   @0x15250c asrne r5, r2, #1
 *   @0x152510 cmp r1, r5
 *   @0x152514 addgt r1, r1, r1, lsl #1
 *   @0x152518 addgt r1, r1, r1, lsr #31
 *   @0x15251c asrgt r5, r1, #1
 *   @0x152520 mov r0, r5
 *   @0x152524 bl 0xcef4c <_Z7YYAlloci>
 *   @0x152528 ldr r2, [sp, #0x38]
 *   @0x15252c mov r1, r4
 *   @0x152530 str r0, [sp, #0x34]
 *   @0x152534 bl 0xb65bc <memcpy@plt>
 *   @0x152538 cmp r4, #0
 *   @0x15253c str r5, [sp, #0x38]
 *   @0x152540 beq 0x15254c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa90>
 *   @0x152544 mov r0, r4
 *   @0x152548 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15254c ldr r3, [sp, #0x3c]
 *   @0x152550 ldr r12, [sp, #0x20]
 *   @0x152554 ldr r2, [sp, #0x34]
 *   @0x152558 ldr r0, [r12]
 *   @0x15255c add r1, r2, r3
 *   @0x152560 ldrh r12, [r12, #4]
 *   @0x152564 str r0, [r2, r3]
 *   @0x152568 strh r12, [r1, #4]
 *   @0x15256c ldr r3, [sp, #0x3c]
 *   @0x152570 add r3, r3, #5
 *   @0x152574 str r3, [sp, #0x3c]
 *   @0x152578 b 0x151eec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x430>
 *   @0x15257c ldr r2, [sp, #0x38]
 *   @0x152580 mvn r0, r3
 *   @0x152584 add r0, r2, r0
 *   @0x152588 cmp r0, #8
 *   @0x15258c bgt 0x1525ec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb30>
 *   @0x152590 cmp r2, #0
 *   @0x152594 add r1, r1, #18
 *   @0x152598 addne r2, r2, r2, lsl #1
 *   @0x15259c ldr r4, [sp, #0x34]
 *   @0x1525a0 moveq r5, #13
 *   @0x1525a4 addne r2, r2, r2, lsr #31
 *   @0x1525a8 asrne r5, r2, #1
 *   @0x1525ac cmp r1, r5
 *   @0x1525b0 addgt r1, r1, r1, lsl #1
 *   @0x1525b4 addgt r1, r1, r1, lsr #31
 *   @0x1525b8 asrgt r5, r1, #1
 *   @0x1525bc mov r0, r5
 *   @0x1525c0 bl 0xcef4c <_Z7YYAlloci>
 *   @0x1525c4 ldr r2, [sp, #0x38]
 *   @0x1525c8 mov r1, r4
 *   @0x1525cc str r0, [sp, #0x34]
 *   @0x1525d0 bl 0xb65bc <memcpy@plt>
 *   @0x1525d4 cmp r4, #0
 *   @0x1525d8 str r5, [sp, #0x38]
 *   @0x1525dc beq 0x1525e8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb2c>
 *   @0x1525e0 mov r0, r4
 *   @0x1525e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1525e8 ldr r3, [sp, #0x3c]
 *   @0x1525ec ldr r2, [sp, #0x24]
 *   @0x1525f0 ldr lr, [sp, #0x34]
 *   @0x1525f4 ldm r2!, {r0, r1}
 *   @0x1525f8 add r12, lr, r3
 *   @0x1525fc ldrb r2, [r2]
 *   @0x152600 str r0, [lr, r3]
 *   @0x152604 str r1, [r12, #0x4]
 *   @0x152608 strb r2, [r12, #0x8]
 *   @0x15260c ldr r3, [sp, #0x3c]
 *   @0x152610 add r3, r3, #8
 *   @0x152614 str r3, [sp, #0x3c]
 *   @0x152618 b 0x151eec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x430>
 *   @0x15261c cmp r7, #0
 *   @0x152620 beq 0x152650 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb94>
 *   @0x152624 ldr r1, [sp, #0x34]
 *   @0x152628 ldr r0, [sp, #0x2c]
 *   @0x15262c mov r3, #0
 *   @0x152630 str r3, [sp, #0x3c]
 *   @0x152634 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x152638 ldr r0, [sp, #0x34]
 *   @0x15263c cmp r0, #0
 *   @0x152640 beq 0x152648 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb8c>
 *   @0x152644 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152648 add sp, sp, #68
 *   @0x15264c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x152650 add r1, sp, #60
 *   @0x152654 b 0x152628 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb6c>
 *   @0x152658 eoreq sp, r9, r4, lsr #31
 *   @0x15265c andseq r0, lr, r8, lsr #20
 *   @0x152660 andseq r4, pc, r8, asr #1
 *   @0x152664 ldrsbeq r4, [pc], -r0
 *   @0x152668 ldrsbeq r4, [pc], -r0
 *   @0x15266c andseq r4, pc, r12, lsr #1
 *   @0x152670 ldrheq r0, [lr], -r12
 *   @0x152674 andseq r0, lr, r4, lsl sp
 *   @0x152678 andseq r3, pc, r0, ror r12
 *   @0x15267c mulseq lr, r0, r5
 *   @0x152680 andseq r3, pc, r12, asr r12
 *   @0x152684 andseq lr, lr, r4, lsl #7
 *   @0x152688 andseq r3, pc, r8, lsr r12
 *   @0x15268c eoreq sp, r9, r12, ror r10
 *   @0x152690 andseq r0, lr, r4, asr #20
 *
 * ══ §9/13 CGestureRotate::Update(long long)  0x1da940  size 3024  754 条（0x1da940..0x1db510）
 * @func 0x1da940 0x1db510  size 3024  754 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertRawPos(float, float, int, float&, float&, float&, float&)×6 / ConvertGestureEventToGMEvent(int, bool)×3 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)×3 / operator new(unsigned int)×3 / GetTouchActionFromUID(int)×2 / 0xb6760×2 / CreateDsMap(int, ...)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2
 * 字段偏移 top8: 0x8×20 / 0x4×18 / 0x34×9 / 0x44×8 / 0x30×7 / 0xc×7 / 0x14×5 / 0x10×4
 * VFP 指令 246 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1da940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1da944 vpush {d8, d9, d10, d11}
 *   @0x1da948 mov r6, r0
 *   @0x1da94c sub sp, sp, #420
 *   @0x1da950 ldr r0, [r0, #0x28]
 *   @0x1da954 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1da958 mov r4, r0
 *   @0x1da95c ldr r0, [r6, #0x2c]
 *   @0x1da960 bl 0x1d75f4 <_Z21GetTouchActionFromUIDi>
 *   @0x1da964 cmp r4, #0
 *   @0x1da968 beq 0x1dafa0 <_ZN14CGestureRotate6UpdateEx+0x660>
 *   @0x1da96c ldr r3, [r4, #0x828]
 *   @0x1da970 ldr r2, [r4, #0x82c]
 *   @0x1da974 cmp r3, r2
 *   @0x1da978 beq 0x1daf8c <_ZN14CGestureRotate6UpdateEx+0x64c>
 *   @0x1da97c add r3, r3, #63
 *   @0x1da980 and r3, r3, #63
 *   @0x1da984 add r3, r4, r3, lsl #5
 *   @0x1da988 vldr s20, [r3, #56]
 *   @0x1da98c vldr s18, [r3, #60]
 *   @0x1da990 vldr s17, [r3, #48]
 *   @0x1da994 ldr r10, [r3, #0x34]
 *   @0x1da998 cmp r0, #0
 *   @0x1da99c ldr r5, [r4]
 *   @0x1da9a0 ldrb r8, [r4, #0x830]
 *   @0x1da9a4 beq 0x1dafc0 <_ZN14CGestureRotate6UpdateEx+0x680>
 *   @0x1da9a8 ldr r3, [r0, #0x828]
 *   @0x1da9ac ldr r2, [r0, #0x82c]
 *   @0x1da9b0 cmp r3, r2
 *   @0x1da9b4 beq 0x1daf78 <_ZN14CGestureRotate6UpdateEx+0x638>
 *   @0x1da9b8 add r3, r3, #63
 *   @0x1da9bc and r3, r3, #63
 *   @0x1da9c0 add r3, r0, r3, lsl #5
 *   @0x1da9c4 vldr s21, [r3, #56]
 *   @0x1da9c8 vldr s19, [r3, #60]
 *   @0x1da9cc vldr s16, [r3, #48]
 *   @0x1da9d0 ldr r9, [r3, #0x34]
 *   @0x1da9d4 ldrb r3, [r0, #0x830]
 *   @0x1da9d8 ldr r0, [r0]
 *   @0x1da9dc cmp r3, #0
 *   @0x1da9e0 movne r8, #1
 *   @0x1da9e4 str r0, [sp, #0x16c]
 *   @0x1da9e8 ldr r7, [r6, #0x14]
 *   @0x1da9ec cmp r7, #0
 *   @0x1da9f0 beq 0x1daa08 <_ZN14CGestureRotate6UpdateEx+0xc8>
 *   @0x1da9f4 cmp r7, #1
 *   @0x1da9f8 beq 0x1dafe0 <_ZN14CGestureRotate6UpdateEx+0x6a0>
 *   @0x1da9fc add sp, sp, #420
 *   @0x1daa00 vpop {d8, d9, d10, d11}
 *   @0x1daa04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1daa08 vmov r1, s17
 *   @0x1daa0c mov r0, #11
 *   @0x1daa10 vmov r3, s16
 *   @0x1daa14 add r4, r6, #12
 *   @0x1daa18 vmov.f32 s15, #5.000000e-01
 *   @0x1daa1c add r8, r6, #16
 *   @0x1daa20 mov r11, #1
 *   @0x1daa24 add r2, r1, r3
 *   @0x1daa28 add r3, r10, r9
 *   @0x1daa2c mov r1, r7
 *   @0x1daa30 vmov s10, r2
 *   @0x1daa34 vmov s11, r3
 *   @0x1daa38 vcvt.f32.s32 s14, s10
 *   @0x1daa3c vcvt.f32.s32 s13, s11
 *   @0x1daa40 vmul.f32 s14, s14, s15
 *   @0x1daa44 vmul.f32 s15, s13, s15
 *   @0x1daa48 vstr s14, [r6, #48]
 *   @0x1daa4c vstr s15, [r6, #52]
 *   @0x1daa50 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1daa54 str r7, [sp, #0x8]
 *   @0x1daa58 str r4, [sp]
 *   @0x1daa5c ldr r2, [r6, #0x30]
 *   @0x1daa60 str r8, [sp, #0x4]
 *   @0x1daa64 ldr r3, [r6, #0x34]
 *   @0x1daa68 mov r1, r0
 *   @0x1daa6c mov r0, #13
 *   @0x1daa70 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1daa74 mov r1, r7
 *   @0x1daa78 mov r0, #10
 *   @0x1daa7c bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1daa80 stm sp, {r4, r8}
 *   @0x1daa84 ldr r2, [r6, #0x30]
 *   @0x1daa88 ldr r3, [r6, #0x34]
 *   @0x1daa8c str r11, [sp, #0x8]
 *   @0x1daa90 mov r1, r0
 *   @0x1daa94 mov r0, #13
 *   @0x1daa98 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1daa9c mov r1, r7
 *   @0x1daaa0 mov r0, #12
 *   @0x1daaa4 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1daaa8 stm sp, {r4, r8}
 *   @0x1daaac ldr r2, [r6, #0x30]
 *   @0x1daab0 str r11, [sp, #0x8]
 *   @0x1daab4 ldr r3, [r6, #0x34]
 *   @0x1daab8 mov r1, r0
 *   @0x1daabc mov r0, #13
 *   @0x1daac0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1daac4 vsub.f32 s18, s19, s18
 *   @0x1daac8 vmul.f32 s15, s18, s18
 *   @0x1daacc vsub.f32 s21, s21, s20
 *   @0x1daad0 vmla.f32 s15, s21, s21
 *   @0x1daad4 vsqrt.f32 s20, s15
 *   @0x1daad8 vcmp.f32 s20, s20
 *   @0x1daadc vmrs APSR_nzcv, fpscr
 *   @0x1daae0 bne 0x1db474 <_ZN14CGestureRotate6UpdateEx+0xb34>
 *   @0x1daae4 vcmpe.f32 s20, #0
 *   @0x1daae8 vmrs APSR_nzcv, fpscr
 *   @0x1daaec ble 0x1dab20 <_ZN14CGestureRotate6UpdateEx+0x1e0>
 *   @0x1daaf0 vdiv.f32 s18, s18, s20
 *   @0x1daaf4 vmov r0, s18
 *   @0x1daaf8 bl 0xb6760 <acosf@plt>
 *   @0x1daafc vdiv.f32 s20, s21, s20
 *   @0x1dab00 vmov s15, r0
 *   @0x1dab04 vcmpe.f32 s20, #0
 *   @0x1dab08 vmrs APSR_nzcv, fpscr
 *   @0x1dab0c vldrmi s14, [pc, #1008]
 *   @0x1dab10 vsubmi.f32 s15, s14, s15
 *   @0x1dab14 vaddmi.f32 s15, s15, s14
 *   @0x1dab18 vstr s15, [r6, #56]
 *   @0x1dab1c vstr s15, [r6, #60]
 *   @0x1dab20 vldr s14, [r6, #48]
 *   @0x1dab24 vldr s15, [r6, #52]
 *   @0x1dab28 vcvt.s32.f32 s14, s14
 *   @0x1dab2c mov r7, #0
 *   @0x1dab30 mov r4, #0
 *   @0x1dab34 ldr r11, [pc, #0x3cc]
 *   @0x1dab38 vcvt.s32.f32 s15, s15
 *   @0x1dab3c vmov r0, s14
 *   @0x1dab40 vmov r1, s15
 *   @0x1dab44 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii>
 *   @0x1dab48 vmov s13, r10
 *   @0x1dab4c vcvt.f32.s32 s12, s17
 *   @0x1dab50 add r3, sp, #372
 *   @0x1dab54 add r1, sp, #388
 *   @0x1dab58 vcvt.f32.s32 s13, s13
 *   @0x1dab5c str r0, [r6, #0x44]
 *   @0x1dab60 mov r2, r0
 *   @0x1dab64 str r3, [sp]
 *   @0x1dab68 add r3, sp, #384
 *   @0x1dab6c vmov r0, s12
 *   @0x1dab70 str r3, [sp, #0x4]
 *   @0x1dab74 add r3, sp, #368
 *   @0x1dab78 str r1, [sp, #0x8]
 *   @0x1dab7c vmov r1, s13
 *   @0x1dab80 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1dab84 vmov s15, r9
 *   @0x1dab88 vcvt.f32.s32 s14, s16
 *   @0x1dab8c ldr r2, [r6, #0x44]
 *   @0x1dab90 add r3, sp, #380
 *   @0x1dab94 str r3, [sp]
 *   @0x1dab98 add r3, sp, #392
 *   @0x1dab9c str r3, [sp, #0x4]
 *   @0x1daba0 add r3, sp, #396
 *   @0x1daba4 str r3, [sp, #0x8]
 *   @0x1daba8 add r3, sp, #376
 *   @0x1dabac vcvt.f32.s32 s15, s15
 *   @0x1dabb0 vmov r0, s14
 *   @0x1dabb4 vmov r1, s15
 *   @0x1dabb8 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1dabbc ldr r2, [r6, #0x44]
 *   @0x1dabc0 ldr r1, [r6, #0x34]
 *   @0x1dabc4 add r3, sp, #404
 *   @0x1dabc8 ldr r0, [r6, #0x30]
 *   @0x1dabcc str r3, [sp]
 *   @0x1dabd0 add r3, sp, #408
 *   @0x1dabd4 str r3, [sp, #0x4]
 *   @0x1dabd8 add r3, sp, #412
 *   @0x1dabdc str r3, [sp, #0x8]
 *   @0x1dabe0 add r3, sp, #400
 *   @0x1dabe4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1dabe8 mov r0, #16
 *   @0x1dabec bl 0x27c524 <_Znwj>
 *   @0x1dabf0 vldr s14, [sp, #384]
 *   @0x1dabf4 vcvt.f64.f32 d7, s14
 *   @0x1dabf8 vldr s6, [sp, #368]
 *   @0x1dabfc vmov s10, r5
 *   @0x1dac00 vldr s8, [sp, #372]
 *   @0x1dac04 mvn r3, #0
 *   @0x1dac08 ldr r2, [pc, #0x2fc]
 *   @0x1dac0c vldr s12, [sp, #364]
 *   @0x1dac10 mov r1, #10
 *   @0x1dac14 add r2, pc, r2
 *   @0x1dac18 ldr r12, [pc, #0x2f0]
 *   @0x1dac1c ldr lr, [pc, #0x2f0]
 *   @0x1dac20 mov r5, #0
 *   @0x1dac24 add r12, pc, r12
 *   @0x1dac28 vcvt.f64.s32 d2, s10
 *   @0x1dac2c vldr s10, [sp, #388]
 *   @0x1dac30 add lr, pc, lr
 *   @0x1dac34 vcvt.f64.f32 d3, s6
 *   @0x1dac38 vcvt.f64.f32 d4, s8
 *   @0x1dac3c vcvt.f64.f32 d5, s10
 *   @0x1dac40 mov r8, r0
 *   @0x1dac44 mov r0, #23
 *   @0x1dac48 str r3, [r8, #0x4]
 *   @0x1dac4c ldr r3, [pc, #0x2c4]
 *   @0x1dac50 str r1, [r8]
 *   @0x1dac54 str r7, [r8, #0x8]
 *   @0x1dac58 add r3, pc, r3
 *   @0x1dac5c str r7, [r8, #0xc]
 *   @0x1dac60 vstr d7, [sp, #104]
 *   @0x1dac64 vcvt.f64.s32 d7, s12
 *   @0x1dac68 str r2, [sp, #0x4]
 *   @0x1dac6c str r3, [sp, #0x14]
 *   @0x1dac70 vstr d2, [sp, #8]
 *   @0x1dac74 ldr r1, [pc, #0x2a0]
 *   @0x1dac78 vstr d3, [sp, #40]
 *   @0x1dac7c ldr r2, [pc, #0x29c]
 *   @0x1dac80 vstr d4, [sp, #56]
 *   @0x1dac84 ldr r3, [pc, #0x298]
 *   @0x1dac88 add r1, pc, r1
 *   @0x1dac8c add r2, pc, r2
 *   @0x1dac90 str r1, [sp, #0x24]
 *   @0x1dac94 str r2, [sp, #0x34]
 *   @0x1dac98 add r3, pc, r3
 *   @0x1dac9c ldr r1, [pc, #0x284]
 *   @0x1daca0 vcvt.f64.s32 d6, s17
 *   @0x1daca4 str r3, [sp, #0x44]
 *   @0x1daca8 ldr r2, [pc, #0x27c]
 *   @0x1dacac add r1, pc, r1
 *   @0x1dacb0 ldr r3, [pc, #0x278]
 *   @0x1dacb4 str r1, [sp, #0x54]
 *   @0x1dacb8 add r2, pc, r2
 *   @0x1dacbc str r7, [sp]
 *   @0x1dacc0 add r3, pc, r3
 *   @0x1dacc4 str r7, [sp, #0x10]
 *   @0x1dacc8 str r3, [sp, #0x74]
 *   @0x1daccc str r7, [sp, #0x20]
 *   @0x1dacd0 str r7, [sp, #0x30]
 *   @0x1dacd4 str r7, [sp, #0x40]
 *   @0x1dacd8 str r7, [sp, #0x50]
 *   @0x1dacdc str r7, [sp, #0x60]
 *   @0x1dace0 str r7, [sp, #0x70]
 *   @0x1dace4 str r2, [sp, #0x64]
 *   @0x1dace8 ldr r2, [r6, #0x4]
 *   @0x1dacec vstr d5, [sp, #120]
 *   @0x1dacf0 vmov s10, r10
 *   @0x1dacf4 vstr d7, [sp, #24]
 *   @0x1dacf8 vstr d6, [sp, #72]
 *   @0x1dacfc ldr r3, [pc, #0x230]
 *   @0x1dad00 vcvt.f64.s32 d7, s10
 *   @0x1dad04 ldr r1, [pc, #0x22c]
 *   @0x1dad08 add r3, pc, r3
 *   @0x1dad0c ldr r10, [pc, #0x228]
 *   @0x1dad10 add r1, pc, r1
 *   @0x1dad14 add r10, pc, r10
 *   @0x1dad18 vstr d7, [sp, #88]
 *   @0x1dad1c vldr s10, [sp, #400]
 *   @0x1dad20 vcvt.f64.f32 d5, s10
 *   @0x1dad24 str r7, [sp, #0x80]
 *   @0x1dad28 vldr s14, [sp, #404]
 *   @0x1dad2c vldr s12, [r6, #48]
 *   @0x1dad30 vldr s2, [sp, #376]
 *   @0x1dad34 vldr s4, [sp, #380]
 *   @0x1dad38 vldr s6, [sp, #392]
 *   @0x1dad3c vldr s8, [sp, #396]
 *   @0x1dad40 str r3, [sp, #0x94]
 *   @0x1dad44 ldr r3, [pc, #0x1f4]
 *   @0x1dad48 str r1, [sp, #0x84]
 *   @0x1dad4c vcvt.f64.f32 d6, s12
 *   @0x1dad50 vstr d5, [sp, #232]
 *   @0x1dad54 vmov s11, r9
 *   @0x1dad58 str r12, [sp, #0xa4]
 *   @0x1dad5c add r3, pc, r3
 *   @0x1dad60 ldr r12, [pc, #0x1dc]
 *   @0x1dad64 str r3, [sp, #0xc4]
 *   @0x1dad68 ldr r1, [pc, #0x1d8]
 *   @0x1dad6c add r12, pc, r12
 *   @0x1dad70 ldr r3, [pc, #0x1d4]
 *   @0x1dad74 str lr, [sp, #0xb4]
 *   @0x1dad78 add r1, pc, r1
 *   @0x1dad7c vcvt.f64.f32 d7, s14
 *   @0x1dad80 vstr d6, [sp, #264]
 *   @0x1dad84 str r10, [sp, #0xd4]
 *   @0x1dad88 add r3, pc, r3
 *   @0x1dad8c str r12, [sp, #0xe4]
 *   @0x1dad90 str r1, [sp, #0xf4]
 *   @0x1dad94 str r3, [sp, #0x104]
 *   @0x1dad98 str r7, [sp, #0x90]
 *   @0x1dad9c str r7, [sp, #0xa0]
 *   @0x1dada0 vcvt.f64.f32 d1, s2
 *   @0x1dada4 vstr d7, [sp, #248]
 *   @0x1dada8 str r7, [sp, #0xb0]
 *   @0x1dadac str r7, [sp, #0xc0]
 *   @0x1dadb0 str r7, [sp, #0xd0]
 *   @0x1dadb4 str r7, [sp, #0xe0]
 *   @0x1dadb8 str r7, [sp, #0xf0]
 *   @0x1dadbc str r7, [sp, #0x100]
 *   @0x1dadc0 vcvt.f64.f32 d2, s4
 *   @0x1dadc4 vstr d1, [sp, #136]
 *   @0x1dadc8 ldr r1, [pc, #0x180]
 *   @0x1dadcc ldr r10, [pc, #0x180]
 *   @0x1dadd0 add r1, pc, r1
 *   @0x1dadd4 ldr lr, [pc, #0x17c]
 *   @0x1dadd8 ldr r12, [pc, #0x17c]
 *   @0x1daddc add r10, pc, r10
 *   @0x1dade0 ldr r3, [pc, #0x178]
 *   @0x1dade4 add lr, pc, lr
 *   @0x1dade8 add r12, pc, r12
 *   @0x1dadec vcvt.f64.f32 d3, s6
 *   @0x1dadf0 vstr d2, [sp, #152]
 *   @0x1dadf4 add r3, pc, r3
 *   @0x1dadf8 vcvt.f64.f32 d4, s8
 *   @0x1dadfc vstr d3, [sp, #200]
 *   @0x1dae00 vcvt.f64.s32 d6, s16
 *   @0x1dae04 vstr d4, [sp, #216]
 *   @0x1dae08 vcvt.f64.s32 d7, s11
 *   @0x1dae0c vstr d6, [sp, #168]
 *   @0x1dae10 vstr d7, [sp, #184]
 *   @0x1dae14 vldr s12, [sp, #408]
 *   @0x1dae18 vcvt.f64.f32 d6, s12
 *   @0x1dae1c str r7, [sp, #0x110]
 *   @0x1dae20 vldr s10, [r6, #52]
 *   @0x1dae24 vldr s14, [sp, #412]
 *   @0x1dae28 str r1, [sp, #0x144]
 *   @0x1dae2c ldr r1, [pc, #0x130]
 *   @0x1dae30 str r4, [sp, #0x148]
 *   @0x1dae34 str r5, [sp, #0x14c]
 *   @0x1dae38 str r4, [sp, #0x158]
 *   @0x1dae3c str r5, [sp, #0x15c]
 *   @0x1dae40 add r1, pc, r1
 *   @0x1dae44 str lr, [sp, #0x124]
 *   @0x1dae48 vstr d6, [sp, #296]
 *   @0x1dae4c vmov s13, r2
 *   @0x1dae50 vcvt.f64.f32 d5, s10
 *   @0x1dae54 str r12, [sp, #0x134]
 *   @0x1dae58 str r3, [sp, #0x154]
 *   @0x1dae5c str r7, [sp, #0x120]
 *   @0x1dae60 str r7, [sp, #0x130]
 *   @0x1dae64 str r7, [sp, #0x140]
 *   @0x1dae68 str r7, [sp, #0x150]
 *   @0x1dae6c str r7, [sp, #0x160]
 *   @0x1dae70 vcvt.f64.f32 d7, s14
 *   @0x1dae74 vstr d5, [sp, #280]
 *   @0x1dae78 str r10, [sp, #0x114]
 *   @0x1dae7c vcvt.f64.s32 d6, s13
 *   @0x1dae80 vstr d7, [sp, #312]
 *   @0x1dae84 vmov r2, r3, d6
 *   @0x1dae88 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1dae8c ldr r11, [pc, r11]
 *   @0x1dae90 ldr r4, [r6, #0xc]
 *   @0x1dae94 mov r3, #1
 *   @0x1dae98 ldr lr, [r6, #0x10]
 *   @0x1dae9c mov r2, #143
 *   @0x1daea0 ldr r1, [pc, #0xc0]
 *   @0x1daea4 ldr r12, [r11, #0x8]
 *   @0x1daea8 add r1, pc, r1
 *   @0x1daeac str r4, [r8, #0x8]
 *   @0x1daeb0 str lr, [r8, #0xc]
 *   @0x1daeb4 add r12, r12, r3
 *   @0x1daeb8 str r0, [r8, #0x4]
 *   @0x1daebc mov r0, #12
 *   @0x1daec0 str r12, [r11, #0x8]
 *   @0x1daec4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1daec8 ldr r3, [r11, #0x4]
 *   @0x1daecc cmp r3, r7
 *   @0x1daed0 str r8, [r0, #0x8]
 *   @0x1daed4 streq r0, [r11, #0x4]
 *   @0x1daed8 strne r0, [r3]
 *   @0x1daedc streq r3, [r0, #0x4]
 *   @0x1daee0 strne r3, [r0, #0x4]
 *   @0x1daee4 streq r0, [r11]
 *   @0x1daee8 strne r0, [r11, #0x4]
 *   @0x1daeec streq r3, [r0]
 *   @0x1daef0 mov r3, #1
 *   @0x1daef4 strne r7, [r0]
 *   @0x1daef8 str r3, [r6, #0x14]
 *   @0x1daefc add sp, sp, #420
 *   @0x1daf00 b 0x1daf70 <_ZN14CGestureRotate6UpdateEx+0x630>
 *   @0x1daf04 ldrdmi r0, r1, [r9], #-251
 *   @0x1daf08 eoreq r5, r1, r4, ror sp
 *   @0x1daf0c andseq r6, r7, r4, asr #12
 *   @0x1daf10 mulseq r7, r4, r6
 *   @0x1daf14 mulseq r7, r4, r6
 *   @0x1daf18 andseq r6, r7, r8, lsl #12
 *   @0x1daf1c andseq r6, r7, r0, ror #11
 *   @0x1daf20 andseq r6, r7, r4, ror #11
 *   @0x1daf24 andseq r6, r7, r0, ror #11
 *   @0x1daf28 ldrsbeq r6, [r7], -r8
 *   @0x1daf2c ldrsbeq r6, [r7], -r8
 *   @0x1daf30 ldrsbeq r6, [r7], -r12
 *   @0x1daf34 andseq r6, r7, r8, lsr #11
 *   @0x1daf38 mulseq r7, r8, r5
 *   @0x1daf3c andseq r6, r7, r8, asr #11
 *   @0x1daf40 andseq r6, r7, r4, ror r5
 *   @0x1daf44 ldrsheq r6, [r7], -r4
 *   @0x1daf48 ldrsheq r6, [r7], -r0
 *   @0x1daf4c andseq r6, r7, r8, ror #11
 *   @0x1daf50 ldrsbeq r6, [r7], -r0
 *   @0x1daf54 andseq r6, r7, r0, lsr #11
 *   @0x1daf58 andseq r6, r7, r4, lsr #11
 *   @0x1daf5c andseq r6, r7, r12, lsr #11
 *   @0x1daf60 ldrheq r6, [r7], -r12
 *   @0x1daf64 andseq r6, r7, r8, lsr r3
 *   @0x1daf68 andseq r1, r7, r8, lsl #31
 *   @0x1daf6c andeq r0, r0, r0
 *   @0x1daf70 vpop {d8, d9, d10, d11}
 *   @0x1daf74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1daf78 mov r9, #0
 *   @0x1daf7c vldr s19, [pc, #-24]
 *   @0x1daf80 vmov s16, r9
 *   @0x1daf84 vmov.f32 s21, s19
 *   @0x1daf88 b 0x1da9d4 <_ZN14CGestureRotate6UpdateEx+0x94>
 *   @0x1daf8c mov r10, #0
 *   @0x1daf90 vldr s18, [pc, #-44]
 *   @0x1daf94 vmov s17, r10
 *   @0x1daf98 vmov.f32 s20, s18
 *   @0x1daf9c b 0x1da998 <_ZN14CGestureRotate6UpdateEx+0x58>
 *   @0x1dafa0 cmp r0, #0
 *   @0x1dafa4 vldr s18, [pc, #-64]
 *   @0x1dafa8 mov r10, r4
 *   @0x1dafac vmov.f32 s20, s18
 *   @0x1dafb0 vmov s17, r4
 *   @0x1dafb4 mvn r5, #0
 *   @0x1dafb8 mov r8, #1
 *   @0x1dafbc bne 0x1da9a8 <_ZN14CGestureRotate6UpdateEx+0x68>
 *   @0x1dafc0 vldr s19, [pc, #-92]
 *   @0x1dafc4 mvn r1, #0
 *   @0x1dafc8 mov r9, r0
 *   @0x1dafcc vmov.f32 s21, s19
 *   @0x1dafd0 vmov s16, r0
 *   @0x1dafd4 str r1, [sp, #0x16c]
 *   @0x1dafd8 mov r8, #1
 *   @0x1dafdc b 0x1da9e8 <_ZN14CGestureRotate6UpdateEx+0xa8>
 *   @0x1dafe0 vmov s15, r10
 *   @0x1dafe4 ldr r2, [r6, #0x44]
 *   @0x1dafe8 vcvt.f32.s32 s14, s17
 *   @0x1dafec add r3, sp, #372
 *   @0x1daff0 str r3, [sp]
 *   @0x1daff4 add r3, sp, #384
 *   @0x1daff8 str r3, [sp, #0x4]
 *   @0x1daffc add r3, sp, #388
 *   @0x1db000 str r3, [sp, #0x8]
 *   @0x1db004 add r3, sp, #368
 *   @0x1db008 vcvt.f32.s32 s15, s15
 *   @0x1db00c vmov r0, s14
 *   @0x1db010 vmov r1, s15
 *   @0x1db014 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1db018 vmov s11, r9
 *   @0x1db01c vcvt.f32.s32 s10, s16
 *   @0x1db020 ldr r2, [r6, #0x44]
 *   @0x1db024 add r3, sp, #380
 *   @0x1db028 str r3, [sp]
 *   @0x1db02c add r3, sp, #392
 *   @0x1db030 str r3, [sp, #0x4]
 *   @0x1db034 add r3, sp, #396
 *   @0x1db038 str r3, [sp, #0x8]
 *   @0x1db03c add r3, sp, #376
 *   @0x1db040 vcvt.f32.s32 s11, s11
 *   @0x1db044 vmov r0, s10
 *   @0x1db048 vmov r1, s11
 *   @0x1db04c bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1db050 ldr r2, [r6, #0x44]
 *   @0x1db054 ldr r0, [r6, #0x30]
 *   @0x1db058 add r3, sp, #404
 *   @0x1db05c ldr r1, [r6, #0x34]
 *   @0x1db060 str r3, [sp]
 *   @0x1db064 add r3, sp, #408
 *   @0x1db068 str r3, [sp, #0x4]
 *   @0x1db06c add r3, sp, #412
 *   @0x1db070 str r3, [sp, #0x8]
 *   @0x1db074 add r3, sp, #400
 *   @0x1db078 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1db07c cmp r8, #0
 *   @0x1db080 beq 0x1db3ac <_ZN14CGestureRotate6UpdateEx+0xa6c>
 *   @0x1db084 mov r0, #16
 *   @0x1db088 bl 0x27c524 <_Znwj>
 *   @0x1db08c mov r2, #12
 *   @0x1db090 mvn r3, #0
 *   @0x1db094 vldr d0, [pc, #1004]
 *   @0x1db098 mov r7, r0
 *   @0x1db09c str r2, [r0]
 *   @0x1db0a0 str r3, [r0, #0x4]
 *   @0x1db0a4 mov r2, #0
 *   @0x1db0a8 str r2, [r0, #0x8]
 *   @0x1db0ac str r2, [r0, #0xc]
 *   @0x1db0b0 str r3, [r6, #0x14]
 *   @0x1db0b4 vmov s12, r5
 *   @0x1db0b8 vldr s4, [sp, #368]
 *   @0x1db0bc vldr s6, [sp, #372]
 *   @0x1db0c0 vcvt.f64.f32 d2, s4
 *   @0x1db0c4 vldr s8, [sp, #384]
 *   @0x1db0c8 vldr s14, [sp, #388]
 *   @0x1db0cc ldr r3, [pc, #0x3c8]
 *   @0x1db0d0 mov r5, #0
 *   @0x1db0d4 ldr r12, [pc, #0x3c4]
 *   @0x1db0d8 vldr s10, [sp, #364]
 *   @0x1db0dc add r3, pc, r3
 *   @0x1db0e0 ldr r1, [pc, #0x3bc]
 *   @0x1db0e4 str r3, [sp, #0x4]
 *   @0x1db0e8 add r12, pc, r12
 *   @0x1db0ec ldr r2, [pc, #0x3b4]
 *   @0x1db0f0 add r1, pc, r1
 *   @0x1db0f4 vcvt.f64.s32 d1, s12
 *   @0x1db0f8 ldr r3, [pc, #0x3ac]
 *   @0x1db0fc str r12, [sp, #0x14]
 *   @0x1db100 add r2, pc, r2
 *   @0x1db104 str r1, [sp, #0x24]
 *   @0x1db108 add r3, pc, r3
 *   @0x1db10c str r2, [sp, #0x34]
 *   @0x1db110 vstr d2, [sp, #40]
 *   @0x1db114 str r3, [sp, #0x44]
 *   @0x1db118 vldr s12, [sp, #376]
 *   @0x1db11c ldr r12, [pc, #0x38c]
 *   @0x1db120 vldr s11, [pc, #872]
 *   @0x1db124 ldr r1, [pc, #0x388]
 *   @0x1db128 mov r0, #23
 *   @0x1db12c vcvt.f64.f32 d3, s6
 *   @0x1db130 ldr r2, [pc, #0x380]
 *   @0x1db134 ldr r3, [pc, #0x380]
 *   @0x1db138 vstr d1, [sp, #8]
 *   @0x1db13c add r12, pc, r12
 *   @0x1db140 add r1, pc, r1
 *   @0x1db144 str r12, [sp, #0x54]
 *   @0x1db148 add r2, pc, r2
 *   @0x1db14c str r1, [sp, #0x64]
 *   @0x1db150 add r3, pc, r3
 *   @0x1db154 str r2, [sp, #0x74]
 *   @0x1db158 str r3, [sp, #0x84]
 *   @0x1db15c vcvt.f64.f32 d4, s8
 *   @0x1db160 vstr d3, [sp, #56]
 *   @0x1db164 str r5, [sp]
 *   @0x1db168 str r5, [sp, #0x10]
 *   @0x1db16c str r5, [sp, #0x20]
 *   @0x1db170 str r5, [sp, #0x30]
 *   @0x1db174 str r5, [sp, #0x40]
 *   @0x1db178 str r5, [sp, #0x50]
 *   @0x1db17c vcvt.f64.f32 d7, s14
 *   @0x1db180 vstr d4, [sp, #104]
 *   @0x1db184 str r5, [sp, #0x60]
 *   @0x1db188 str r5, [sp, #0x70]
 *   @0x1db18c str r5, [sp, #0x80]
 *   @0x1db190 ldr r2, [r6, #0x4]
 *   @0x1db194 ldr r12, [pc, #0x324]
 *   @0x1db198 ldr r3, [pc, #0x324]
 *   @0x1db19c vcvt.f64.f32 d6, s12
 *   @0x1db1a0 vstr d7, [sp, #120]
 *   @0x1db1a4 add r12, pc, r12
 *   @0x1db1a8 add r3, pc, r3
 *   @0x1db1ac ldr lr, [pc, #0x314]
 *   @0x1db1b0 ldr r1, [pc, #0x314]
 *   @0x1db1b4 ldr r4, [pc, #0x314]
 *   @0x1db1b8 add lr, pc, lr
 *   @0x1db1bc ldr r8, [pc, #0x310]
 *   @0x1db1c0 add r1, pc, r1
 *   @0x1db1c4 add r4, pc, r4
 *   @0x1db1c8 vcvt.f64.s32 d7, s10
 *   @0x1db1cc vstr d6, [sp, #136]
 *   @0x1db1d0 vmov s10, r10
 *   @0x1db1d4 ldr r10, [pc, #0x2fc]
 *   @0x1db1d8 add r8, pc, r8
 *   @0x1db1dc add r10, pc, r10
 *   @0x1db1e0 vcvt.f64.s32 d6, s17
 *   @0x1db1e4 vstr d7, [sp, #24]
 *   @0x1db1e8 vcvt.f64.s32 d7, s10
 *   @0x1db1ec vstr d6, [sp, #72]
 *   @0x1db1f0 vstr d7, [sp, #88]
 *   @0x1db1f4 vldr s12, [sp, #404]
 *   @0x1db1f8 vcvt.f64.f32 d6, s12
 *   @0x1db1fc str r5, [sp, #0x90]
 *   @0x1db200 vldr s14, [r6, #52]
 *   @0x1db204 vldr s18, [r6, #48]
 *   @0x1db208 vldr s2, [sp, #380]
 *   @0x1db20c vldr s4, [sp, #392]
 *   @0x1db210 vldr s6, [sp, #396]
 *   @0x1db214 vldr s8, [sp, #400]
 *   @0x1db218 str r12, [sp, #0xa4]
 *   @0x1db21c str r3, [sp, #0xb4]
 *   @0x1db220 ldr r12, [pc, #0x2b4]
 *   @0x1db224 vcvt.f64.f32 d7, s14
 *   @0x1db228 vstr d6, [sp, #248]
 *   @0x1db22c vmov s12, r9
 *   @0x1db230 ldr r3, [pc, #0x2a8]
 *   @0x1db234 str lr, [sp, #0x94]
 *   @0x1db238 add r12, pc, r12
 *   @0x1db23c add r3, pc, r3
 *   @0x1db240 str r1, [sp, #0xc4]
 *   @0x1db244 str r4, [sp, #0xd4]
 *   @0x1db248 str r8, [sp, #0xe4]
 *   @0x1db24c str r12, [sp, #0x104]
 *   @0x1db250 vcvt.f64.f32 d1, s2
 *   @0x1db254 vstr d7, [sp, #280]
 *   @0x1db258 str r3, [sp, #0x114]
 *   @0x1db25c str r5, [sp, #0xa0]
 *   @0x1db260 str r5, [sp, #0xb0]
 *   @0x1db264 str r5, [sp, #0xc0]
 *   @0x1db268 str r5, [sp, #0xd0]
 *   @0x1db26c str r5, [sp, #0xe0]
 *   @0x1db270 vcvt.f64.s32 d7, s12
 *   @0x1db274 vstr d1, [sp, #152]
 *   @0x1db278 str r5, [sp, #0xf0]
 *   @0x1db27c str r5, [sp, #0x100]
 *   @0x1db280 str r5, [sp, #0x110]
 *   @0x1db284 str r10, [sp, #0xf4]
 *   @0x1db288 ldr r8, [pc, #0x254]
 *   @0x1db28c ldr lr, [pc, #0x254]
 *   @0x1db290 vcvt.f64.f32 d2, s4
 *   @0x1db294 ldr r12, [pc, #0x250]
 *   @0x1db298 ldr r3, [pc, #0x250]
 *   @0x1db29c add lr, pc, lr
 *   @0x1db2a0 ldr r1, [pc, #0x24c]
 *   @0x1db2a4 add r12, pc, r12
 *   @0x1db2a8 add r3, pc, r3
 *   @0x1db2ac add r8, pc, r8
 *   @0x1db2b0 add r1, pc, r1
 *   @0x1db2b4 ldr r4, [pc, #0x23c]
 *   @0x1db2b8 vcvt.f64.f32 d3, s6
 *   @0x1db2bc vstr d2, [sp, #200]
 *   @0x1db2c0 vcvt.f64.f32 d4, s8
 *   @0x1db2c4 vstr d3, [sp, #216]
 *   @0x1db2c8 vcvt.f64.f32 d9, s18
 *   @0x1db2cc vstr d4, [sp, #232]
 *   @0x1db2d0 vcvt.f64.s32 d8, s16
 *   @0x1db2d4 vstr d9, [sp, #264]
 *   @0x1db2d8 vstr d8, [sp, #168]
 *   @0x1db2dc vstr d7, [sp, #184]
 *   @0x1db2e0 str r5, [sp, #0x120]
 *   @0x1db2e4 vldr s10, [r6, #64]
 *   @0x1db2e8 vmul.f32 s10, s10, s11
 *   @0x1db2ec vldr s14, [sp, #412]
 *   @0x1db2f0 vldr s12, [sp, #408]
 *   @0x1db2f4 vstr d0, [sp, #328]
 *   @0x1db2f8 str lr, [sp, #0x134]
 *   @0x1db2fc str r12, [sp, #0x144]
 *   @0x1db300 str r3, [sp, #0x154]
 *   @0x1db304 str r5, [sp, #0x130]
 *   @0x1db308 str r5, [sp, #0x140]
 *   @0x1db30c str r5, [sp, #0x150]
 *   @0x1db310 str r5, [sp, #0x160]
 *   @0x1db314 str r8, [sp, #0x124]
 *   @0x1db318 vcvt.f64.f32 d7, s14
 *   @0x1db31c vstr d7, [sp, #312]
 *   @0x1db320 vmov s15, r2
 *   @0x1db324 vcvt.f64.f32 d5, s10
 *   @0x1db328 vcvt.f64.f32 d6, s12
 *   @0x1db32c vstr d5, [sp, #344]
 *   @0x1db330 vcvt.f64.s32 d7, s15
 *   @0x1db334 vstr d6, [sp, #296]
 *   @0x1db338 vmov r2, r3, d7
 *   @0x1db33c bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1db340 ldr r1, [r6, #0x10]
 *   @0x1db344 ldr r4, [pc, r4]
 *   @0x1db348 ldr lr, [r6, #0xc]
 *   @0x1db34c mov r3, #1
 *   @0x1db350 mov r2, #143
 *   @0x1db354 str r1, [r7, #0xc]
 *   @0x1db358 ldr r1, [pc, #0x19c]
 *   @0x1db35c ldr r12, [r4, #0x8]
 *   @0x1db360 add r1, pc, r1
 *   @0x1db364 str lr, [r7, #0x8]
 *   @0x1db368 add r12, r12, r3
 *   @0x1db36c str r0, [r7, #0x4]
 *   @0x1db370 mov r0, #12
 *   @0x1db374 str r12, [r4, #0x8]
 *   @0x1db378 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1db37c ldr r3, [r4, #0x4]
 *   @0x1db380 cmp r3, r5
 *   @0x1db384 str r7, [r0, #0x8]
 *   @0x1db388 strne r0, [r3]
 *   @0x1db38c strne r3, [r0, #0x4]
 *   @0x1db390 strne r0, [r4, #0x4]
 *   @0x1db394 strne r5, [r0]
 *   @0x1db398 streq r0, [r4, #0x4]
 *   @0x1db39c streq r0, [r4]
 *   @0x1db3a0 streq r3, [r0, #0x4]
 *   @0x1db3a4 streq r3, [r0]
 *   @0x1db3a8 b 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc>
 *   @0x1db3ac vsub.f32 s18, s19, s18
 *   @0x1db3b0 vmul.f32 s15, s18, s18
 *   @0x1db3b4 vsub.f32 s20, s21, s20
 *   @0x1db3b8 vmla.f32 s15, s20, s20
 *   @0x1db3bc vsqrt.f32 s22, s15
 *   @0x1db3c0 vcmp.f32 s22, s22
 *   @0x1db3c4 vmrs APSR_nzcv, fpscr
 *   @0x1db3c8 bne 0x1db500 <_ZN14CGestureRotate6UpdateEx+0xbc0>
 *   @0x1db3cc vcmpe.f32 s22, #0
 *   @0x1db3d0 vmrs APSR_nzcv, fpscr
 *   @0x1db3d4 ble 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc>
 *   @0x1db3d8 vdiv.f32 s18, s18, s22
 *   @0x1db3dc vmov r0, s18
 *   @0x1db3e0 bl 0xb6760 <acosf@plt>
 *   @0x1db3e4 vdiv.f32 s20, s20, s22
 *   @0x1db3e8 vmov s18, r0
 *   @0x1db3ec vcmpe.f32 s20, #0
 *   @0x1db3f0 vmrs APSR_nzcv, fpscr
 *   @0x1db3f4 vldrmi s15, [pc, #152]
 *   @0x1db3f8 vsubmi.f32 s18, s15, s18
 *   @0x1db3fc vaddmi.f32 s18, s18, s15
 *   @0x1db400 vldr s15, [r6, #60]
 *   @0x1db404 vcmp.f32 s15, s18
 *   @0x1db408 vmrs APSR_nzcv, fpscr
 *   @0x1db40c beq 0x1da9fc <_ZN14CGestureRotate6UpdateEx+0xbc>
 *   @0x1db410 vsub.f32 s19, s18, s15
 *   @0x1db414 vldr s15, [pc, #120]
 *   @0x1db418 mov r0, #16
 *   @0x1db41c vcmpe.f32 s19, s15
 *   @0x1db420 vmrs APSR_nzcv, fpscr
 *   @0x1db424 vldrgt s15, [pc, #108]
 *   @0x1db428 vsubgt.f32 s19, s15, s19
 *   @0x1db42c vldr s15, [r6, #64]
 *   @0x1db430 vneggt.f32 s19, s19
 *   @0x1db434 vadd.f32 s15, s15, s19
 *   @0x1db438 vstr s15, [r6, #64]
 *   @0x1db43c bl 0x27c524 <_Znwj>
 *   @0x1db440 vldr s0, [pc, #72]
 *   @0x1db444 vmul.f32 s0, s19, s0
 *   @0x1db448 mvn r3, #0
 *   @0x1db44c mov r2, #11
 *   @0x1db450 vcvt.f64.f32 d0, s0
 *   @0x1db454 str r3, [r0, #0x4]
 *   @0x1db458 mov r7, r0
 *   @0x1db45c mov r3, #0
 *   @0x1db460 str r2, [r0]
 *   @0x1db464 str r3, [r0, #0x8]
 *   @0x1db468 str r3, [r0, #0xc]
 *   @0x1db46c vstr s18, [r6, #60]
 *   @0x1db470 b 0x1db0b4 <_ZN14CGestureRotate6UpdateEx+0x774>
 *   @0x1db474 vmov r0, s15
 *   @0x1db478 bl 0xb6700 <sqrtf@plt>
 *   @0x1db47c vmov s20, r0
 *   @0x1db480 b 0x1daae4 <_ZN14CGestureRotate6UpdateEx+0x1a4>
 *   @0x1db484 nop
 *   @0x1db490 rsbmi r2, r5, #224, #28
 *   @0x1db494 ldrdmi r0, r1, [r9], #-251
 *   @0x1db498 ldrdmi r0, r1, [r9], #251
 *   @0x1db49c andseq r6, r7, r12, ror r1
 *   @0x1db4a0 andseq r6, r7, r8, ror r1
 *   @0x1db4a4 andseq r6, r7, r8, ror r1
 *   @0x1db4a8 andseq r6, r7, r0, ror r1
 *   @0x1db4ac andseq r6, r7, r0, ror r1
 *   @0x1db4b0 andseq r6, r7, r8, asr #2
 *   @0x1db4b4 andseq r6, r7, r0, asr r1
 *   @0x1db4b8 andseq r6, r7, r4, asr r1
 *   @0x1db4bc andseq r6, r7, r8, asr r1
 *   @0x1db4c0 andseq r6, r7, r4, lsl r1
 *   @0x1db4c4 andseq r6, r7, r12, lsl r1
 *   @0x1db4c8 ldrsheq r6, [r7], -r8
 *   @0x1db4cc andseq r6, r7, r0, lsl r1
 *   @0x1db4d0 andseq r6, r7, r8, lsl r1
 *   @0x1db4d4 andseq r6, r7, r8, lsl #3
 *   @0x1db4d8 andseq r6, r7, r12, lsl #3
 *   @0x1db4dc andseq r6, r7, r8, lsr r1
 *   @0x1db4e0 andseq r6, r7, r0, asr #2
 *   @0x1db4e4 ldrsbeq r6, [r7], -r12
 *   @0x1db4e8 ldrsheq r6, [r7], -r8
 *   @0x1db4ec ldrsheq r6, [r7], -r12
 *   @0x1db4f0 andseq r6, r7, r8, lsl #2
 *   @0x1db4f4 andseq r5, r7, r8, asr #29
 *   @0x1db4f8 .word 0x002158bc
 *   @0x1db4fc ldrsbeq r1, [r7], -r0
 *   @0x1db500 vmov r0, s15
 *   @0x1db504 bl 0xb6700 <sqrtf@plt>
 *   @0x1db508 vmov s22, r0
 *   @0x1db50c b 0x1db3cc <_ZN14CGestureRotate6UpdateEx+0xa8c>
 *
 * ══ §10/13 anon_225230  0x225230  size 2540  160 条（0x225230..0x225c1c）｜其中 475 条已由别的卡落锚，本节不再重复
 * @func 0x225230 0x2254b0  size 640  160 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()×5 / COggSyncThread::Unlock()×5 / COggSyncThread::LogError(char const*, ...)×4 / 0xb6a9c×4 / ov_clear×3 / 0xb6b08×3 / 0xb6afc×3 / __divsi3×3
 * 字段偏移 top8: 0x86c×16 / 0x40×14 / 0x4×11 / 0x804×9 / 0x2c4×7 / 0x870×7 / 0x298×6 / 0x2e0×6
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225230 ldr r3, [r0, #0x2a8]
 *   @0x225234 cmp r2, #0
 *   @0x225238 push {r4, r5, r6, r7, r8, lr}
 *   @0x22523c add r3, r3, #168
 *   @0x225240 sub sp, sp, #24
 *   @0x225244 mov r4, #0
 *   @0x225248 mov r5, r0
 *   @0x22524c add r7, sp, #20
 *   @0x225250 mov r8, r1
 *   @0x225254 str r4, [sp, #0x14]
 *   @0x225258 ldr r6, [r0, r3, lsl #2]
 *   @0x22525c bne 0x22526c <_ZN14COggSyncThread7MixDataEPviiiff+0xe4>
 *   @0x225260 b 0x22534c <_ZN14COggSyncThread7MixDataEPviiiff+0x1c4>
 *   @0x225264 cmp r4, #16384
 *   @0x225268 bge 0x2252c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x13c>
 *   @0x22526c add r1, r6, r4
 *   @0x225270 rsb r2, r4, #16384
 *   @0x225274 mov r0, r5
 *   @0x225278 mov r3, r7
 *   @0x22527c bl 0x232ec8 <ov_read>
 *   @0x225280 subs r12, r0, #0
 *   @0x225284 addgt r4, r4, r12
 *   @0x225288 bgt 0x225264 <_ZN14COggSyncThread7MixDataEPviiiff+0xdc>
 *   @0x22528c mov r0, r5
 *   @0x225290 mov r2, #0
 *   @0x225294 mov r3, #0
 *   @0x225298 bne 0x225330 <_ZN14COggSyncThread7MixDataEPviiiff+0x1a8>
 *   @0x22529c bl 0x231618 <ov_raw_seek>
 *   @0x2252a0 cmp r0, #0
 *   @0x2252a4 beq 0x225264 <_ZN14COggSyncThread7MixDataEPviiiff+0xdc>
 *   @0x2252a8 ldr r1, [pc, #0xcc]
 *   @0x2252ac mov r2, r0
 *   @0x2252b0 mov r0, r8
 *   @0x2252b4 add r1, pc, r1
 *   @0x2252b8 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz>
 *   @0x2252bc cmp r4, #0
 *   @0x2252c0 beq 0x225314 <_ZN14COggSyncThread7MixDataEPviiiff+0x18c>
 *   @0x2252c4 ldr r12, [r5, #0x298]
 *   @0x2252c8 mov r0, r8
 *   @0x2252cc ldr r8, [r5, #0x2ec]
 *   @0x2252d0 mov r1, r6
 *   @0x2252d4 movw lr, #0x1101
 *   @0x2252d8 movw r2, #0x1103
 *   @0x2252dc ldr r6, [r12, #0x4]
 *   @0x2252e0 mov r3, r4
 *   @0x2252e4 ldr r7, [r12, #0x8]
 *   @0x2252e8 str r8, [sp, #0x4]
 *   @0x2252ec cmp r6, #1
 *   @0x2252f0 ldr r12, [r5, #0x2bc]
 *   @0x2252f4 str r7, [sp]
 *   @0x2252f8 moveq r2, lr
 *   @0x2252fc ldr r12, [r12, #0x4]
 *   @0x225300 str r12, [sp, #0x8]
 *   @0x225304 bl 0x225188 <_ZN14COggSyncThread7MixDataEPviiiff>
 *   @0x225308 ldr r3, [r5, #0x2bc]
 *   @0x22530c ldr r3, [r3, #0x4]
 *   @0x225310 str r3, [r5, #0x2ec]
 *   @0x225314 ldr r3, [r5, #0x2a8]
 *   @0x225318 mov r0, r4
 *   @0x22531c eor r3, r3, #1
 *   @0x225320 str r3, [r5, #0x2a8]
 *   @0x225324 add sp, sp, #24
 *   @0x225328 pop {r4, r5, r6, r7, r8, pc}
 *   @0x22532c beq 0x2252bc <_ZN14COggSyncThread7MixDataEPviiiff+0x134>
 *   @0x225330 ldr r1, [pc, #0x48]
 *   @0x225334 mov r0, r8
 *   @0x225338 mov r2, r12
 *   @0x22533c mov r4, #0
 *   @0x225340 add r1, pc, r1
 *   @0x225344 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz>
 *   @0x225348 b 0x225314 <_ZN14COggSyncThread7MixDataEPviiiff+0x18c>
 *   @0x22534c mov r4, r2
 *   @0x225350 mov r0, r5
 *   @0x225354 add r1, r6, r4
 *   @0x225358 rsb r2, r4, #16384
 *   @0x22535c mov r3, r7
 *   @0x225360 bl 0x232ec8 <ov_read>
 *   @0x225364 subs r12, r0, #0
 *   @0x225368 ble 0x22532c <_ZN14COggSyncThread7MixDataEPviiiff+0x1a4>
 *   @0x22536c add r4, r4, r12
 *   @0x225370 cmp r4, #16384
 *   @0x225374 blt 0x225350 <_ZN14COggSyncThread7MixDataEPviiiff+0x1c8>
 *   @0x225378 b 0x2252c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x13c>
 *   @0x22537c andseq pc, r2, r12, lsr r11
 *   @0x225380 mulseq r2, r12, r10
 *   @0x225384 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x225388 vpush {d8}
 *   @0x22538c subs r9, r1, #0
 *   @0x225390 sub sp, sp, #12
 *   @0x225394 mov r8, r2
 *   @0x225398 str r3, [sp, #0x4]
 *   @0x22539c ble 0x22549c <_ZN14COggSyncThread7MixDataEPviiiff+0x314>
 *   @0x2253a0 mov r11, #0
 *   @0x2253a4 add r7, r0, #752
 *   @0x2253a8 mov r6, r0
 *   @0x2253ac mov r10, #2080
 *   @0x2253b0 vldr s16, [pc, #240]
 *   @0x2253b4 b 0x2253d8 <_ZN14COggSyncThread7MixDataEPviiiff+0x250>
 *   @0x2253b8 ldr r3, [r6, #0x2c4]
 *   @0x2253bc cmp r3, #3
 *   @0x2253c0 beq 0x22546c <_ZN14COggSyncThread7MixDataEPviiiff+0x2e4>
 *   @0x2253c4 add r11, r11, #1
 *   @0x2253c8 add r7, r7, #768
 *   @0x2253cc cmp r11, r9
 *   @0x2253d0 add r6, r6, #768
 *   @0x2253d4 beq 0x22549c <_ZN14COggSyncThread7MixDataEPviiiff+0x314>
 *   @0x2253d8 vldr s15, [r7, #-4]
 *   @0x2253dc vcmpe.f32 s15, s16
 *   @0x2253e0 ldrd r0, r1, [r8, r10]
 *   @0x2253e4 ldrd r2, r3, [r7]
 *   @0x2253e8 vmrs APSR_nzcv, fpscr
 *   @0x2253ec bpl 0x225404 <_ZN14COggSyncThread7MixDataEPviiiff+0x27c>
 *   @0x2253f0 ldr r4, [r6, #0x2bc]
 *   @0x2253f4 vldr s15, [r4, #4]
 *   @0x2253f8 vcmpe.f32 s15, s16
 *   @0x2253fc vmrs APSR_nzcv, fpscr
 *   @0x225400 bmi 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c>
 *   @0x225404 ldrb r4, [r6, #0x2d5]
 *   @0x225408 cmp r4, #0
 *   @0x22540c beq 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c>
 *   @0x225410 bl 0x319414 <__aeabi_ldivmod>
 *   @0x225414 mov r0, r6
 *   @0x225418 mov r5, r3
 *   @0x22541c ldr r3, [r6, #0x2e0]
 *   @0x225420 mov r4, r2
 *   @0x225424 add r3, r3, #1
 *   @0x225428 str r3, [r6, #0x2e0]
 *   @0x22542c bl 0x232cec <ov_pcm_tell>
 *   @0x225430 mov r2, r4
 *   @0x225434 mov r3, r5
 *   @0x225438 cmp r5, r1
 *   @0x22543c cmpeq r4, r0
 *   @0x225440 mov r0, r6
 *   @0x225444 beq 0x22544c <_ZN14COggSyncThread7MixDataEPviiiff+0x2c4>
 *   @0x225448 bl 0x2326f4 <ov_pcm_seek>
 *   @0x22544c mov r0, r6
 *   @0x225450 mov r1, r8
 *   @0x225454 ldr r2, [sp, #0x4]
 *   @0x225458 bl 0x225230 <_ZN14COggSyncThread7MixDataEPviiiff+0xa8>
 *   @0x22545c cmp r0, #0
 *   @0x225460 movle r3, #3
 *   @0x225464 strle r3, [r6, #0x2c4]
 *   @0x225468 bgt 0x2253b8 <_ZN14COggSyncThread7MixDataEPviiiff+0x230>
 *   @0x22546c mov r0, r6
 *   @0x225470 bl 0x230ec4 <ov_clear>
 *   @0x225474 mov r3, #0
 *   @0x225478 mov r0, r8
 *   @0x22547c str r3, [r6, #0x2c4]
 *   @0x225480 str r3, [r6, #0x2e0]
 *   @0x225484 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225488 mov r3, #0
 *   @0x22548c mov r0, r8
 *   @0x225490 strb r3, [r6, #0x2d5]
 *   @0x225494 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225498 b 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c>
 *   @0x22549c add sp, sp, #12
 *   @0x2254a0 vpop {d8}
 *   @0x2254a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2254a8 stclo p7, c13, [r3], #-40
 *   @0x2254ac andeq r0, r0, r0
 *
 * ══ §11/13 png_read_end  0x2a787c  size 1000  72 条（0x2a787c..0x2a7c64）｜其中 178 条已由别的卡落锚，本节不再重复
 * @func 0x2a7894 0x2a7c58  size 964  72 条
 * 部分覆盖: 本节 72/444 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c40×2 / png_handle_as_unknown / png_handle_unknown
 * 字段偏移 top8: 0x4×9 / 0x50×2 / 0x10×1 / 0xa×1 / 0x20×1 / 0x14×1 / 0x30×1 / 0x1e×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7894 .word 0xf10df9ff
 *   @0x2a7898 ldrbtmi r0, [r8], #2312
 *   @0x2a78c0 .word 0xf8530000
 *   @0x2a78c4 ldmdbvc r11, {r0, r2, r8, r9, r10, r11}
 *   @0x2a78cc .word 0x46433014
 *   @0x2a78e0 ldmdbvc r11, {r0, r1, r2, r3, r8, r9, r10, r11}
 *   @0x2a78e8 strbmi r3, [r3], -r4, lsr #32
 *   @0x2a78fc ldmdbvc r11, {r0, r3, r4, r8, r9, r10, r11}
 *   @0x2a7904 .word 0x46433034
 *   @0x2a7918 ldmdbvc r11, {r0, r1, r5, r8, r9, r10, r11}
 *   @0x2a7920 strbmi r3, [r3], -r4, asr #32
 *   @0x2a7934 ldmdbvc r11, {r0, r2, r3, r5, r8, r9, r10, r11}
 *   @0x2a793c .word 0x46433054
 *   @0x2a7950 ldmdbvc r11, {r0, r1, r2, r4, r5, r8, r9, r10, r11}
 *   @0x2a7958 strbmi r3, [r3], -r4, rrx
 *   @0x2a796c ldmdbvc r11, {r0, r6, r8, r9, r10, r11}
 *   @0x2a7974 .word 0x46433074
 *   @0x2a7988 ldmdbvc r11, {r0, r1, r3, r6, r8, r9, r10, r11}
 *   @0x2a7990 strbmi r3, [r3], -r4, lsl #1
 *   @0x2a79a4 ldmdbvc r11, {r0, r2, r4, r6, r8, r9, r10, r11}
 *   @0x2a79ac .word 0x46433094
 *   @0x2a79c0 ldmdbvc r11, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11}
 *   @0x2a79c8 strbmi r3, [r3], -r4, lsr #1
 *   @0x2a79d8 .word 0xf00630ac
 *   @0x2a79dc .word 0x4649f8f3
 *   @0x2a79e8 stmdblt r8!, {r2, r3, r5, r8, r11, sp, lr, pc}
 *   @0x2a79f4 .word 0xe126fa2d
 *   @0x2a7a00 stmdblt r8!, {r5, r8, r11, sp, lr, pc}
 *   @0x2a7a0c tst r10, sp, asr r11
 *   @0x2a7a38 qsub8mi pc, r0, r9
 *   @0x2a7a4c stmdahs r0, {r1, r3, r4, r5, r6, r7, r11, sp, lr, pc}
 *   @0x2a7a80 .word 0x4620fcd5
 *   @0x2a7a88 sbcs pc, r12, r5, lsl #18
 *   @0x2a7a94 stmdblt r8!, {r1, r2, r4, r6, r7, r11, sp, lr, pc}
 *   @0x2a7aa0 sbcs pc, r0, r1, ror #20
 *   @0x2a7aac stmdblt r8!, {r1, r3, r6, r7, r11, sp, lr, pc}
 *   @0x2a7ab8 sbc pc, r4, r3, asr r9
 *   @0x2a7ac4 stmdblt r8!, {r1, r2, r3, r4, r5, r7, r11, sp, lr, pc}
 *   @0x2a7ad0 adcs pc, r8, r11, lsr #24
 *   @0x2a7adc stmdblt r8!, {r1, r4, r5, r7, r11, sp, lr, pc}
 *   @0x2a7ae8 adc pc, r12, r3, lsl r11
 *   @0x2a7af4 stmdblt r8!, {r1, r2, r5, r7, r11, sp, lr, pc}
 *   @0x2a7b00 adc pc, r0, r11, asr #19
 *   @0x2a7b0c stmdblt r8!, {r1, r3, r4, r7, r11, sp, lr, pc}
 *   @0x2a7b18 adds pc, r4, r11, lsl #21
 *   @0x2a7b24 stmdblt r8!, {r1, r2, r3, r7, r11, sp, lr, pc}
 *   @0x2a7b30 .word 0xe088fafb
 *   @0x2a7b3c stmdblt r8!, {r1, r7, r11, sp, lr, pc}
 *   @0x2a7b48 rsbs pc, r12, r3, lsl #24
 *   @0x2a7b54 stmdblt r8!, {r1, r2, r4, r5, r6, r11, sp, lr, pc}
 *   @0x2a7b60 ldrsht pc, [r0], #-155
 *   @0x2a7b6c stmdblt r8!, {r1, r3, r5, r6, r11, sp, lr, pc}
 *   @0x2a7b78 rsb pc, r4, pc, asr r11
 *   @0x2a7b84 stmdblt r8!, {r1, r2, r3, r4, r6, r11, sp, lr, pc}
 *   @0x2a7b90 subs pc, r8, r1, lsl #27
 *   @0x2a7b9c stmdblt r8!, {r1, r4, r6, r11, sp, lr, pc}
 *   @0x2a7ba8 sub pc, r12, r5, lsr lr
 *   @0x2a7bb4 stmdblt r8!, {r1, r2, r6, r11, sp, lr, pc}
 *   @0x2a7bc0 sub pc, r0, r5, lsl pc
 *   @0x2a7bcc stmdblt r8!, {r1, r3, r4, r5, r11, sp, lr, pc}
 *   @0x2a7bd8 ldrsbt pc, [r4], -r5
 *   @0x2a7be4 stmdblt r8!, {r1, r2, r3, r5, r11, sp, lr, pc}
 *   @0x2a7bf0 eor pc, r8, pc, ror #24
 *   @0x2a7bfc stmdblt r8!, {r1, r5, r11, sp, lr, pc}
 *   @0x2a7c08 ldrsh pc, [r12], -r1
 *   @0x2a7c14 stmdblt r8!, {r1, r2, r4, r11, sp, lr, pc}
 *   @0x2a7c20 ands pc, r0, r5, asr sp
 *   @0x2a7c2c stmdblt r8!, {r1, r3, r11, sp, lr, pc}
 *   @0x2a7c38 and pc, r4, r11, lsl #28
 *   @0x2a7c44 .word 0xf8d4fef7
 *   @0x2a7c48 ldrbeq r3, [r11], r12, lsr #2
 *   @0x2a7c54 svclt #0x8ff0
 *
 * ══ §12/13 anon_28b34c  0x28b34c  size 944  75 条（0x28b34c..0x28b6fc）｜其中 161 条已由别的卡落锚，本节不再重复
 * @func 0x28b34c 0x28b6fc  size 944  75 条
 * 部分覆盖: 本节 75/236 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _malloc×5 / Json_getItem×2 / 0xb6574 / spCurveTimeline_setCurve / anon_28b34c+0x2f0 / anon_28b34c+0x2d4 / 0xb6538 / 0xb697c
 * 字段偏移 top8: 0x4×8 / 0x18×8 / 0x10×7 / 0x1c×4 / 0x14×3 / 0x1×3 / 0x2×2 / 0x98×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b34c push {r4, r5, lr}
 *   @0x28b350 mov r5, r1
 *   @0x28b354 ldr r1, [pc, #0x98]
 *   @0x28b358 sub sp, sp, #12
 *   @0x28b35c mov r4, r2
 *   @0x28b360 add r1, pc, r1
 *   @0x28b364 bl 0x2873c4 <Json_getItem>
 *   @0x28b368 cmp r0, #0
 *   @0x28b36c beq 0x28b384 <spSkeletonData_findPathConstraint+0x94>
 *   @0x28b370 ldr r3, [r0, #0x8]
 *   @0x28b374 cmp r3, #4
 *   @0x28b378 beq 0x28b38c <spSkeletonData_findPathConstraint+0x9c>
 *   @0x28b37c cmp r3, #5
 *   @0x28b380 beq 0x28b3b8 <spSkeletonData_findPathConstraint+0xc8>
 *   @0x28b384 add sp, sp, #12
 *   @0x28b388 pop {r4, r5, pc}
 *   @0x28b38c ldr r1, [pc, #0x64]
 *   @0x28b390 ldr r0, [r0, #0x10]
 *   @0x28b394 add r1, pc, r1
 *   @0x28b398 bl 0xb6574 <strcmp@plt>
 *   @0x28b39c cmp r0, #0
 *   @0x28b3a0 bne 0x28b384 <spSkeletonData_findPathConstraint+0x94>
 *   @0x28b3a4 mov r0, r5
 *   @0x28b3a8 mov r1, r4
 *   @0x28b3ac add sp, sp, #12
 *   @0x28b3b0 pop {r4, r5, lr}
 *   @0x28b3b4 b 0x2817c0 <spCurveTimeline_setStepped>
 *   @0x28b3b8 ldr r3, [r0, #0x4]
 *   @0x28b3bc mov r1, r4
 *   @0x28b3c0 mov r0, r5
 *   @0x28b3c4 ldr r12, [r3]
 *   @0x28b3c8 ldr r2, [r3, #0x18]
 *   @0x28b3cc ldr r3, [r12, #0x18]
 *   @0x28b3d0 ldr r12, [r12]
 *   @0x28b3d4 ldr lr, [r12, #0x18]
 *   @0x28b3d8 str lr, [sp]
 *   @0x28b3dc ldr r12, [r12]
 *   @0x28b3e0 ldr r12, [r12, #0x18]
 *   @0x28b3e4 str r12, [sp, #0x4]
 *   @0x28b3e8 bl 0x2817d8 <spCurveTimeline_setCurve>
 *   @0x28b3ec add sp, sp, #12
 *   @0x28b3f0 pop {r4, r5, pc}
 *   @0x28b3f4 andeq r12, r12, r4, lsl #15
 *   @0x28b3f8 andeq r12, r12, r8, asr r7
 *   @0x28b680 push {r4, r5, lr}
 *   @0x28b684 sub sp, sp, #12
 *   @0x28b688 mov r5, r1
 *   @0x28b68c mov r4, r0
 *   @0x28b690 bl 0xb6538 <strlen@plt>
 *   @0x28b694 cmp r0, #8
 *   @0x28b698 beq 0x28b6a8 <spSkeletonData_findPathConstraint+0x3b8>
 *   @0x28b69c vmov.f32 s0, #-1.000000e+00
 *   @0x28b6a0 add sp, sp, #12
 *   @0x28b6a4 pop {r4, r5, pc}
 *   @0x28b6a8 add r3, r4, r5, lsl #1
 *   @0x28b6ac ldrb r12, [r4, r5, lsl #1]
 *   @0x28b6b0 mov r0, sp
 *   @0x28b6b4 add r1, sp, #4
 *   @0x28b6b8 ldrb r3, [r3, #0x1]
 *   @0x28b6bc mov r2, #16
 *   @0x28b6c0 strb r12, [sp]
 *   @0x28b6c4 mov r12, #0
 *   @0x28b6c8 strb r12, [sp, #0x2]
 *   @0x28b6cc strb r3, [sp, #0x1]
 *   @0x28b6d0 bl 0xb697c <strtoul@plt>
 *   @0x28b6d4 ldr r3, [sp, #0x4]
 *   @0x28b6d8 ldrb r3, [r3]
 *   @0x28b6dc cmp r3, #0
 *   @0x28b6e0 bne 0x28b69c <spSkeletonData_findPathConstraint+0x3ac>
 *   @0x28b6e4 vmov s15, r0
 *   @0x28b6e8 vcvt.f32.s32 s0, s15
 *   @0x28b6ec vldr s15, [pc, #8]
 *   @0x28b6f0 vdiv.f32 s0, s0, s15
 *   @0x28b6f4 add sp, sp, #12
 *   @0x28b6f8 pop {r4, r5, pc}
 *
 * ══ §13/13 DummyConsole::Output(char const*, ...)  0xc4390  size 12  3 条（0xc4390..0xc439c）
 * @func 0xc4390 0xc439c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4390 push {r1, r2, r3}
 *   @0xc4394 add sp, sp, #12
 *   @0xc4398 bx lr
 */
