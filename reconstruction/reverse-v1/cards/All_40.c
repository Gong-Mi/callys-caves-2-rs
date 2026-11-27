/* cally 逆向卡：All_40 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 54 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/54 Audio_FreePlayQueue(int)  0x21ce90  size 592  148 条（0x21ce90..0x21d0e0）
 * @func 0x21ce90 0x21d0e0  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a84 / 0xb6b14 / 0xb6a9c / Audio_FreePlayQueue(int)+0x16c / 0xb6b08 / Audio_FreePlayQueue(int)+0x144 / Audio_GetSound(int) / Audio_FreePlayQueue(int)+0x1cc
 * 字段偏移 top8: 0x2×6 / 0x10×6 / 0x30×5 / 0x34×4 / 0x28×3 / 0x2c×2 / 0x40×2 / 0x38×2
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ce90 sub r0, r0, #199680
 *   @0x21ce94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21ce98 subs r0, r0, #320
 *   @0x21ce9c sub sp, sp, #76
 *   @0x21cea0 str r0, [sp, #0x2c]
 *   @0x21cea4 bmi 0x21d03c <_Z19Audio_FreePlayQueuei+0x1ac>
 *   @0x21cea8 ldr r10, [pc, #0x214]
 *   @0x21ceac add r10, pc, r10
 *   @0x21ceb0 ldr r3, [r10, #0x30]
 *   @0x21ceb4 cmp r0, r3
 *   @0x21ceb8 bge 0x21d03c <_Z19Audio_FreePlayQueuei+0x1ac>
 *   @0x21cebc ldr r3, [r10, #0x34]
 *   @0x21cec0 ldr r3, [r3, r0, lsl #2]
 *   @0x21cec4 cmp r3, #0
 *   @0x21cec8 str r3, [sp, #0x30]
 *   @0x21cecc beq 0x21d0bc <_Z19Audio_FreePlayQueuei+0x22c>
 *   @0x21ced0 ldr r6, [r3, #0x58]
 *   @0x21ced4 cmp r6, #0
 *   @0x21ced8 beq 0x21d008 <_Z19Audio_FreePlayQueuei+0x178>
 *   @0x21cedc ldr r7, [pc, #0x1e4]
 *   @0x21cee0 ldr r2, [r6, #0x10]
 *   @0x21cee4 ldr r7, [pc, r7]
 *   @0x21cee8 ldr r3, [r7]
 *   @0x21ceec ldr r0, [r3, r2, lsl #2]
 *   @0x21cef0 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x21cef4 ldr r3, [r7]
 *   @0x21cef8 ldr r2, [r6, #0x10]
 *   @0x21cefc ldr r0, [r3, r2, lsl #2]
 *   @0x21cf00 bl 0xb6b14 <alSourceStop@plt>
 *   @0x21cf04 ldr r3, [r7]
 *   @0x21cf08 ldr r0, [r6, #0x10]
 *   @0x21cf0c add r2, sp, #72
 *   @0x21cf10 mvn r12, #0
 *   @0x21cf14 movw r1, #0x1016
 *   @0x21cf18 str r12, [r2, #-0x8]!
 *   @0x21cf1c ldr r0, [r3, r0, lsl #2]
 *   @0x21cf20 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21cf24 ldr r3, [sp, #0x40]
 *   @0x21cf28 cmp r3, #0
 *   @0x21cf2c ble 0x21cffc <_Z19Audio_FreePlayQueuei+0x16c>
 *   @0x21cf30 ldr r4, [pc, #0x194]
 *   @0x21cf34 movw r9, #0x869f
 *   @0x21cf38 ldr r1, [pc, #0x190]
 *   @0x21cf3c movt r9, #0x1
 *   @0x21cf40 ldr r2, [pc, #0x18c]
 *   @0x21cf44 add r4, pc, r4
 *   @0x21cf48 add r1, pc, r1
 *   @0x21cf4c str r1, [sp, #0x34]
 *   @0x21cf50 ldr r1, [pc, #0x180]
 *   @0x21cf54 mov r5, #0
 *   @0x21cf58 add r2, pc, r2
 *   @0x21cf5c add r3, sp, #68
 *   @0x21cf60 add r1, pc, r1
 *   @0x21cf64 str r2, [sp, #0x38]
 *   @0x21cf68 str r3, [sp, #0x28]
 *   @0x21cf6c str r1, [sp, #0x3c]
 *   @0x21cf70 ldr r3, [r7]
 *   @0x21cf74 mov r8, #0
 *   @0x21cf78 ldr r0, [r6, #0x10]
 *   @0x21cf7c mov r1, #1
 *   @0x21cf80 str r8, [sp, #0x44]
 *   @0x21cf84 add r2, sp, #68
 *   @0x21cf88 ldr r0, [r3, r0, lsl #2]
 *   @0x21cf8c bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x21cf90 ldr r3, [r10, #0x28]
 *   @0x21cf94 cmp r3, r8
 *   @0x21cf98 ble 0x21cfd4 <_Z19Audio_FreePlayQueuei+0x144>
 *   @0x21cf9c add r11, r8, #99328
 *   @0x21cfa0 add r8, r8, #1
 *   @0x21cfa4 add r11, r11, #672
 *   @0x21cfa8 mov r0, r11
 *   @0x21cfac bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21cfb0 cmp r0, #0
 *   @0x21cfb4 beq 0x21cfc8 <_Z19Audio_FreePlayQueuei+0x138>
 *   @0x21cfb8 ldr r2, [r0, #0x18]
 *   @0x21cfbc ldr r3, [sp, #0x44]
 *   @0x21cfc0 cmp r2, r3
 *   @0x21cfc4 beq 0x21d048 <_Z19Audio_FreePlayQueuei+0x1b8>
 *   @0x21cfc8 ldr r3, [r4, #0x28]
 *   @0x21cfcc cmp r3, r8
 *   @0x21cfd0 bgt 0x21cf9c <_Z19Audio_FreePlayQueuei+0x10c>
 *   @0x21cfd4 mvn r8, #0
 *   @0x21cfd8 ldr r3, [r6, #0x18]
 *   @0x21cfdc sub r3, r3, #199680
 *   @0x21cfe0 sub r3, r3, #320
 *   @0x21cfe4 cmp r3, r9
 *   @0x21cfe8 bls 0x21d05c <_Z19Audio_FreePlayQueuei+0x1cc>
 *   @0x21cfec ldr r3, [sp, #0x40]
 *   @0x21cff0 add r5, r5, #1
 *   @0x21cff4 cmp r3, r5
 *   @0x21cff8 bgt 0x21cf70 <_Z19Audio_FreePlayQueuei+0xe0>
 *   @0x21cffc mov r0, r6
 *   @0x21d000 mov r1, #1
 *   @0x21d004 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21d008 ldr r0, [sp, #0x30]
 *   @0x21d00c bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x21d010 ldr r0, [sp, #0x30]
 *   @0x21d014 bl 0x27d1d0 <_ZdlPv>
 *   @0x21d018 ldr r3, [pc, #0xbc]
 *   @0x21d01c ldr r1, [sp, #0x2c]
 *   @0x21d020 mov r2, #0
 *   @0x21d024 add r3, pc, r3
 *   @0x21d028 mov r0, #1
 *   @0x21d02c ldr r3, [r3, #0x34]
 *   @0x21d030 str r2, [r3, r1, lsl #2]
 *   @0x21d034 add sp, sp, #76
 *   @0x21d038 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21d03c mov r0, #0
 *   @0x21d040 add sp, sp, #76
 *   @0x21d044 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21d048 mov r2, r0
 *   @0x21d04c mov r0, r11
 *   @0x21d050 ldr r8, [r2, #0x10]
 *   @0x21d054 bl 0x219d70 <_Z21Audio_FreeBufferSoundi>
 *   @0x21d058 b 0x21cfd8 <_Z19Audio_FreePlayQueuei+0x148>
 *   @0x21d05c vmov s13, r8
 *   @0x21d060 ldr r1, [sp, #0x38]
 *   @0x21d064 mov r2, #0
 *   @0x21d068 mov r3, #0
 *   @0x21d06c vcvt.f64.s32 d7, s13
 *   @0x21d070 movt r3, #0x3ff0
 *   @0x21d074 str r1, [sp, #0x4]
 *   @0x21d078 mov r0, #3
 *   @0x21d07c ldr r1, [sp, #0x3c]
 *   @0x21d080 strd r2, r3, [sp, #24]
 *   @0x21d084 str r1, [sp, #0x14]
 *   @0x21d088 mov r1, #0
 *   @0x21d08c str r1, [sp]
 *   @0x21d090 vstr d7, [sp, #8]
 *   @0x21d094 vldr s15, [sp, #44]
 *   @0x21d098 vcvt.f64.s32 d7, s15
 *   @0x21d09c str r1, [sp, #0x10]
 *   @0x21d0a0 str r1, [sp, #0x20]
 *   @0x21d0a4 ldr r1, [sp, #0x34]
 *   @0x21d0a8 vmov r2, r3, d7
 *   @0x21d0ac bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x21d0b0 mov r1, #74
 *   @0x21d0b4 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *   @0x21d0b8 b 0x21cfec <_Z19Audio_FreePlayQueuei+0x15c>
 *   @0x21d0bc ldr r0, [sp, #0x30]
 *   @0x21d0c0 b 0x21d040 <_Z19Audio_FreePlayQueuei+0x1b0>
 *   @0x21d0c4 subseq r8, r3, r8, ror #7
 *   @0x21d0c8 andseq r4, sp, r8, ror #9
 *   @0x21d0cc subseq r8, r3, r0, asr r3
 *   @0x21d0d0 andseq r7, r3, r0, ror r0
 *   @0x21d0d4 andseq r7, r3, r12, rrx
 *   @0x21d0d8 andseq r7, r3, r0, ror r0
 *   @0x21d0dc subseq r8, r3, r0, ror r2
 *
 * ══ §2/54 ogg_stream_iovecin  0x234778  size 592  148 条（0x234778..0x2349c8）
 * @func 0x234778 0x2349c8  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check / ogg_stream_iovecin+0x224 / anon_234238 / anon_234238+0x68 / ogg_stream_iovecin+0xfc / 0xb65bc / ogg_stream_iovecin+0x238 / 0xb6694
 * 字段偏移 top8: 0x4×11 / 0x8×9 / 0xc×4 / 0x1c×3 / 0x2×3 / 0x10×2 / 0x14×2 / 0x148×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23477c sub sp, sp, #20
 *   @0x234780 mov r8, r1
 *   @0x234784 mov r9, r2
 *   @0x234788 str r3, [sp, #0xc]
 *   @0x23478c mov r4, r0
 *   @0x234790 bl 0x23412c <ogg_stream_check>
 *   @0x234794 cmp r0, #0
 *   @0x234798 bne 0x23497c <ogg_stream_iovecin+0x204>
 *   @0x23479c cmp r8, #0
 *   @0x2347a0 beq 0x23496c <ogg_stream_iovecin+0x1f4>
 *   @0x2347a4 cmp r9, #0
 *   @0x2347a8 ble 0x23499c <ogg_stream_iovecin+0x224>
 *   @0x2347ac lsl r2, r9, #3
 *   @0x2347b0 mov r11, r0
 *   @0x2347b4 mov r5, r0
 *   @0x2347b8 add r3, r8, r11
 *   @0x2347bc add r11, r11, #8
 *   @0x2347c0 cmp r11, r2
 *   @0x2347c4 ldr r3, [r3, #0x4]
 *   @0x2347c8 add r5, r5, r3
 *   @0x2347cc bne 0x2347b8 <ogg_stream_iovecin+0x40>
 *   @0x2347d0 movw r3, #0x8081
 *   @0x2347d4 movt r3, #0x8080
 *   @0x2347d8 asr r11, r5, #31
 *   @0x2347dc smull r2, r3, r3, r5
 *   @0x2347e0 add r3, r3, r5
 *   @0x2347e4 rsb r11, r11, r3, asr #7
 *   @0x2347e8 str r11, [sp, #0x4]
 *   @0x2347ec add r3, r11, #1
 *   @0x2347f0 str r3, [sp, #0x8]
 *   @0x2347f4 ldr r1, [r4, #0xc]
 *   @0x2347f8 cmp r1, #0
 *   @0x2347fc bne 0x23494c <ogg_stream_iovecin+0x1d4>
 *   @0x234800 mov r0, r4
 *   @0x234804 mov r1, r5
 *   @0x234808 bl 0x234238 <ogg_stream_init+0x94>
 *   @0x23480c cmp r0, #0
 *   @0x234810 bne 0x23497c <ogg_stream_iovecin+0x204>
 *   @0x234814 mov r0, r4
 *   @0x234818 ldr r1, [sp, #0x8]
 *   @0x23481c bl 0x2342a0 <ogg_stream_init+0xfc>
 *   @0x234820 subs r6, r0, #0
 *   @0x234824 bne 0x23497c <ogg_stream_iovecin+0x204>
 *   @0x234828 cmp r9, #0
 *   @0x23482c ble 0x234874 <ogg_stream_iovecin+0xfc>
 *   @0x234830 ldr r0, [r4, #0x8]
 *   @0x234834 mov r7, r6
 *   @0x234838 mov r10, r6
 *   @0x23483c add r11, r8, r7
 *   @0x234840 ldr r3, [r4]
 *   @0x234844 ldr r1, [r8, r7]
 *   @0x234848 add r10, r10, #1
 *   @0x23484c add r0, r3, r0
 *   @0x234850 ldr r2, [r11, #0x4]
 *   @0x234854 bl 0xb65bc <memcpy@plt>
 *   @0x234858 ldr r3, [r11, #0x4]
 *   @0x23485c ldr r0, [r4, #0x8]
 *   @0x234860 cmp r10, r9
 *   @0x234864 add r7, r7, #8
 *   @0x234868 add r0, r0, r3
 *   @0x23486c str r0, [r4, #0x8]
 *   @0x234870 bne 0x23483c <ogg_stream_iovecin+0xc4>
 *   @0x234874 ldr r10, [sp, #0x4]
 *   @0x234878 cmp r10, #0
 *   @0x23487c ble 0x2349b0 <ogg_stream_iovecin+0x238>
 *   @0x234880 ldr r8, [r4, #0x1c]
 *   @0x234884 mov r10, #255
 *   @0x234888 ldr r3, [sp, #0x4]
 *   @0x23488c mov r7, #352
 *   @0x234890 ldr r9, [r4, #0x10]
 *   @0x234894 sub r0, r8, #-536870911
 *   @0x234898 ldr r2, [r4, #0x14]
 *   @0x23489c add r11, r8, r3
 *   @0x2348a0 add r1, r9, r8, lsl #2
 *   @0x2348a4 add r12, r9, r11, lsl #2
 *   @0x2348a8 add r0, r2, r0, lsl #3
 *   @0x2348ac str r2, [sp, #0x4]
 *   @0x2348b0 ldrd r2, r3, [r4, r7]
 *   @0x2348b4 str r10, [r1], #4
 *   @0x2348b8 cmp r1, r12
 *   @0x2348bc strd r2, r3, [r0, #8]!
 *   @0x2348c0 bne 0x2348b0 <ogg_stream_iovecin+0x138>
 *   @0x2348c4 movw r3, #0x8081
 *   @0x2348c8 movt r3, #0x8080
 *   @0x2348cc asr r12, r5, #31
 *   @0x2348d0 lsl r2, r11, #3
 *   @0x2348d4 smull r10, r3, r3, r5
 *   @0x2348d8 ldr r7, [sp, #0x8]
 *   @0x2348dc mov r1, #344
 *   @0x2348e0 add r3, r3, r5
 *   @0x2348e4 add r0, r7, r8
 *   @0x2348e8 ldr r7, [sp, #0xc]
 *   @0x2348ec rsb r3, r12, r3, asr #7
 *   @0x2348f0 mov r12, #352
 *   @0x2348f4 rsb r3, r3, r3, lsl #8
 *   @0x2348f8 rsb r5, r3, r5
 *   @0x2348fc ldr r3, [sp, #0x4]
 *   @0x234900 str r5, [r9, r11, lsl #2]
 *   @0x234904 ldrd r10, r11, [sp, #56]
 *   @0x234908 ldr r5, [r9, r8, lsl #2]
 *   @0x23490c strd r10, r11, [r3, r2]
 *   @0x234910 orr r5, r5, #256
 *   @0x234914 ldrd r2, r3, [r4, r1]
 *   @0x234918 strd r10, r11, [r4, r12]
 *   @0x23491c adds r2, r2, #1
 *   @0x234920 str r5, [r9, r8, lsl #2]
 *   @0x234924 adc r3, r3, #0
 *   @0x234928 cmp r7, #0
 *   @0x23492c str r0, [r4, #0x1c]
 *   @0x234930 strd r2, r3, [r4, r1]
 *   @0x234934 beq 0x23496c <ogg_stream_iovecin+0x1f4>
 *   @0x234938 mov r3, #1
 *   @0x23493c mov r0, r6
 *   @0x234940 str r3, [r4, #0x148]
 *   @0x234944 add sp, sp, #20
 *   @0x234948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23494c ldr r2, [r4, #0x8]
 *   @0x234950 rsb r2, r1, r2
 *   @0x234954 str r2, [r4, #0x8]
 *   @0x234958 cmp r2, #0
 *   @0x23495c bne 0x23498c <ogg_stream_iovecin+0x214>
 *   @0x234960 mov r3, #0
 *   @0x234964 str r3, [r4, #0xc]
 *   @0x234968 b 0x234800 <ogg_stream_iovecin+0x88>
 *   @0x23496c mov r6, #0
 *   @0x234970 mov r0, r6
 *   @0x234974 add sp, sp, #20
 *   @0x234978 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23497c mvn r6, #0
 *   @0x234980 mov r0, r6
 *   @0x234984 add sp, sp, #20
 *   @0x234988 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23498c ldr r0, [r4]
 *   @0x234990 add r1, r0, r1
 *   @0x234994 bl 0xb6694 <memmove@plt>
 *   @0x234998 b 0x234960 <ogg_stream_iovecin+0x1e8>
 *   @0x23499c mov r7, #1
 *   @0x2349a0 str r0, [sp, #0x4]
 *   @0x2349a4 str r7, [sp, #0x8]
 *   @0x2349a8 mov r5, r0
 *   @0x2349ac b 0x2347f4 <ogg_stream_iovecin+0x7c>
 *   @0x2349b0 ldr r11, [r4, #0x14]
 *   @0x2349b4 ldr r8, [r4, #0x1c]
 *   @0x2349b8 ldr r9, [r4, #0x10]
 *   @0x2349bc str r11, [sp, #0x4]
 *   @0x2349c0 mov r11, r8
 *   @0x2349c4 b 0x2348c4 <ogg_stream_iovecin+0x14c>
 *
 * ══ §3/54 F_DsMapAdd_Internal(int, char*, RValue*)  0x1053ec  size 588  147 条（0x1053ec..0x105638）
 * @func 0x1053ec 0x105638  size 588  147 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / DS_AutoMutex::DS_AutoMutex() / YYSetString(RValue*, char const*) / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x4×15 / 0x10×8 / 0x8×4 / 0x1c×2 / 0x18×2 / 0xc×2 / 0x210×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1053ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1053f0 sub sp, sp, #36
 *   @0x1053f4 add r6, sp, #12
 *   @0x1053f8 add r4, sp, #16
 *   @0x1053fc mov r5, r0
 *   @0x105400 mov r8, r1
 *   @0x105404 mov r0, r6
 *   @0x105408 mov r7, r2
 *   @0x10540c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x105410 mov r1, r8
 *   @0x105414 mov r0, r4
 *   @0x105418 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x10541c ldr r3, [pc, #0x210]
 *   @0x105420 mov r2, r7
 *   @0x105424 mov r1, r4
 *   @0x105428 ldr r3, [pc, r3]
 *   @0x10542c ldr r3, [r3, #0x4]
 *   @0x105430 ldr r0, [r3, r5, lsl #2]
 *   @0x105434 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x105438 ldr r2, [sp, #0x1c]
 *   @0x10543c sub r3, r2, #1
 *   @0x105440 bic r3, r3, #-16777216
 *   @0x105444 bics r5, r3, #3
 *   @0x105448 mov r7, r0
 *   @0x10544c beq 0x105478 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x8c>
 *   @0x105450 mov r0, r6
 *   @0x105454 mov r3, #0
 *   @0x105458 mov r2, #5
 *   @0x10545c str r3, [sp, #0x18]
 *   @0x105460 str r3, [sp, #0x10]
 *   @0x105464 str r2, [sp, #0x1c]
 *   @0x105468 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x10546c mov r0, r7
 *   @0x105470 add sp, sp, #36
 *   @0x105474 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x105478 bic r2, r2, #-16777216
 *   @0x10547c cmp r2, #2
 *   @0x105480 beq 0x1054e8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xfc>
 *   @0x105484 cmp r2, #3
 *   @0x105488 beq 0x1054c0 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xd4>
 *   @0x10548c cmp r2, #1
 *   @0x105490 bne 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x105494 ldr r4, [sp, #0x10]
 *   @0x105498 cmp r4, #0
 *   @0x10549c beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1054a4 ldr r5, [r4, #0x4]
 *   @0x1054a8 sub r5, r5, #1
 *   @0x1054ac str r5, [r4, #0x4]
 *   @0x1054b0 cmp r5, #0
 *   @0x1054b4 beq 0x10558c <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1a0>
 *   @0x1054b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1054bc b 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054c0 ldr r3, [sp, #0x18]
 *   @0x1054c4 tst r3, #8
 *   @0x1054c8 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054cc ldr r0, [sp, #0x10]
 *   @0x1054d0 cmp r0, #0
 *   @0x1054d4 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054d8 ldr r3, [r0]
 *   @0x1054dc ldr r3, [r3, #0x4]
 *   @0x1054e0 blx r3
 *   @0x1054e4 b 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054e8 ldr r9, [sp, #0x10]
 *   @0x1054ec cmp r9, #0
 *   @0x1054f0 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64>
 *   @0x1054f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1054f8 ldr r3, [r9]
 *   @0x1054fc ldr r2, [r9, #0x8]
 *   @0x105500 sub r3, r3, #1
 *   @0x105504 str r3, [r9]
 *   @0x105508 cmp r2, r4
 *   @0x10550c streq r5, [r9, #0x8]
 *   @0x105510 cmp r3, #0
 *   @0x105514 bgt 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc>
 *   @0x105518 ldr r3, [r9, #0x10]
 *   @0x10551c cmp r3, #0
 *   @0x105520 movgt r8, #0
 *   @0x105524 movgt r10, #5
 *   @0x105528 movgt r5, r8
 *   @0x10552c ble 0x1055e8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1fc>
 *   @0x105530 ldr r3, [r9, #0x4]
 *   @0x105534 add r2, r3, r8, lsl #3
 *   @0x105538 str r2, [sp, #0x4]
 *   @0x10553c ldr r11, [r3, r8, lsl #3]
 *   @0x105540 ldr r4, [r2, #0x4]
 *   @0x105544 add r11, r4, r11, lsl #4
 *   @0x105548 cmp r4, r11
 *   @0x10554c blo 0x105568 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x17c>
 *   @0x105550 b 0x105608 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x21c>
 *   @0x105554 str r5, [r4, #0x8]
 *   @0x105558 str r10, [r4, #0xc]
 *   @0x10555c str r5, [r4], #16
 *   @0x105560 cmp r11, r4
 *   @0x105564 bls 0x1055c4 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1d8>
 *   @0x105568 ldr r3, [r4, #0xc]
 *   @0x10556c sub r3, r3, #1
 *   @0x105570 bic r3, r3, #-16777216
 *   @0x105574 bic r3, r3, #3
 *   @0x105578 cmp r3, #0
 *   @0x10557c bne 0x105554 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x168>
 *   @0x105580 mov r0, r4
 *   @0x105584 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105588 b 0x105554 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x168>
 *   @0x10558c ldr r0, [r4]
 *   @0x105590 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105594 str r5, [r4]
 *   @0x105598 str r5, [r4, #0x8]
 *   @0x10559c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1055a0 ldr r5, [r4, #0x4]
 *   @0x1055a4 sub r5, r5, #1
 *   @0x1055a8 str r5, [r4, #0x4]
 *   @0x1055ac cmp r5, #0
 *   @0x1055b0 beq 0x105610 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x224>
 *   @0x1055b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1055b8 mov r0, r4
 *   @0x1055bc bl 0x27d1d0 <_ZdlPv>
 *   @0x1055c0 b 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc>
 *   @0x1055c4 ldr r3, [sp, #0x4]
 *   @0x1055c8 ldr r0, [r3, #0x4]
 *   @0x1055cc bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1055d0 ldr r3, [r9, #0x10]
 *   @0x1055d4 add r8, r8, #1
 *   @0x1055d8 ldr r2, [sp, #0x4]
 *   @0x1055dc cmp r8, r3
 *   @0x1055e0 str r5, [r2, #0x4]
 *   @0x1055e4 blt 0x105530 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x144>
 *   @0x1055e8 ldr r0, [r9, #0x4]
 *   @0x1055ec mov r4, #0
 *   @0x1055f0 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1055f4 str r4, [r9, #0x4]
 *   @0x1055f8 mov r0, r9
 *   @0x1055fc bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x105600 str r4, [sp, #0x10]
 *   @0x105604 b 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc>
 *   @0x105608 mov r0, r4
 *   @0x10560c b 0x1055cc <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1e0>
 *   @0x105610 ldr r0, [r4]
 *   @0x105614 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105618 mov r0, r4
 *   @0x10561c str r5, [r4]
 *   @0x105620 str r5, [r4, #0x8]
 *   @0x105624 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x105628 mov r0, r4
 *   @0x10562c bl 0x27d1d0 <_ZdlPv>
 *   @0x105630 b 0x1055b4 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1c8>
 *   @0x105634 eoreq r8, lr, r4, lsl r5
 *
 * ══ §4/54 IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)  0xccabc  size 584  146 条（0xccabc..0xccd04）
 * @func 0xccabc 0xccd04  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0x240×3 / 0xb65bc×2 / __aeabi_idivmod×2 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0x60 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0xa0 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0x148 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0x178 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)+0x16c
 * 字段偏移 top8: 0x10×5 / 0x34×2 / 0xc×2 / 0x20×2 / 0x4×2 / 0x28×1 / 0x2c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xccabc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xccac0 subs r8, r0, #0
 *   @0xccac4 sub sp, sp, #8
 *   @0xccac8 mov r5, r2
 *   @0xccacc mov r9, r1
 *   @0xccad0 ldr r6, [sp, #0x28]
 *   @0xccad4 ldr r4, [sp, #0x2c]
 *   @0xccad8 ldrb r2, [sp, #0x30]
 *   @0xccadc ldrb r10, [sp, #0x34]
 *   @0xccae0 ldrb r7, [sp, #0x38]
 *   @0xccae4 beq 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240>
 *   @0xccae8 cmp r1, #0
 *   @0xccaec beq 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240>
 *   @0xccaf0 cmp r5, #0
 *   @0xccaf4 ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240>
 *   @0xccaf8 cmp r6, #0
 *   @0xccafc movlt r6, r5
 *   @0xccb00 cmp r7, #0
 *   @0xccb04 bne 0xccc10 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x154>
 *   @0xccb08 cmp r3, #0
 *   @0xccb0c movlt r3, r7
 *   @0xccb10 blt 0xccb1c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x60>
 *   @0xccb14 cmp r5, r3
 *   @0xccb18 suble r3, r5, #1
 *   @0xccb1c add r1, r3, r6
 *   @0xccb20 cmp r5, r1
 *   @0xccb24 rsblt r6, r3, r5
 *   @0xccb28 cmp r2, #0
 *   @0xccb2c bne 0xccc4c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x190>
 *   @0xccb30 ldr r2, [r8, #0x10]
 *   @0xccb34 cmp r2, #0
 *   @0xccb38 ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240>
 *   @0xccb3c cmp r10, #0
 *   @0xccb40 beq 0xcccb0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1f4>
 *   @0xccb44 cmp r4, #0
 *   @0xccb48 bge 0xccb60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xa4>
 *   @0xccb4c adds r4, r4, r2
 *   @0xccb50 bmi 0xccb4c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x90>
 *   @0xccb54 cmp r2, r4
 *   @0xccb58 bgt 0xccb68 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xac>
 *   @0xccb5c rsb r4, r2, r4
 *   @0xccb60 cmp r2, r4
 *   @0xccb64 ble 0xccb5c <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xa0>
 *   @0xccb68 add r1, r6, r4
 *   @0xccb6c cmp r2, r1
 *   @0xccb70 bge 0xcccd0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x214>
 *   @0xccb74 cmp r6, #0
 *   @0xccb78 ble 0xccc04 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x148>
 *   @0xccb7c ldr r7, [r8, #0x10]
 *   @0xccb80 rsb r2, r3, r5
 *   @0xccb84 rsb r7, r4, r7
 *   @0xccb88 cmp r7, r2
 *   @0xccb8c movge r7, r2
 *   @0xccb90 ldr r0, [r8, #0xc]
 *   @0xccb94 cmp r7, r6
 *   @0xccb98 movge r7, r6
 *   @0xccb9c add r1, r9, r3
 *   @0xccba0 add r0, r0, r4
 *   @0xccba4 add r10, r3, r7
 *   @0xccba8 mov r2, r7
 *   @0xccbac rsb r6, r7, r6
 *   @0xccbb0 bl 0xb65bc <memcpy@plt>
 *   @0xccbb4 add r0, r4, r7
 *   @0xccbb8 cmn r0, #1
 *   @0xccbbc ldr r7, [r8, #0x10]
 *   @0xccbc0 ldr r2, [r8, #0x20]
 *   @0xccbc4 mov r3, r0
 *   @0xccbc8 ldreq r3, [r8, #0x1c]
 *   @0xccbcc mov r1, r7
 *   @0xccbd0 cmp r3, r2
 *   @0xccbd4 movlt r3, r2
 *   @0xccbd8 cmp r3, r7
 *   @0xccbdc strle r3, [r8, #0x20]
 *   @0xccbe0 strgt r7, [r8, #0x20]
 *   @0xccbe4 bl 0x318dec <__aeabi_idivmod>
 *   @0xccbe8 mov r0, r10
 *   @0xccbec mov r4, r1
 *   @0xccbf0 mov r1, r5
 *   @0xccbf4 bl 0x318dec <__aeabi_idivmod>
 *   @0xccbf8 cmp r6, #0
 *   @0xccbfc mov r3, r1
 *   @0xccc00 bgt 0xccb80 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xc4>
 *   @0xccc04 mov r0, r4
 *   @0xccc08 add sp, sp, #8
 *   @0xccc0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xccc10 cmp r3, #0
 *   @0xccc14 bge 0xccc20 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x164>
 *   @0xccc18 adds r3, r3, r5
 *   @0xccc1c bmi 0xccc18 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x15c>
 *   @0xccc20 cmp r3, r5
 *   @0xccc24 blt 0xccc34 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x178>
 *   @0xccc28 rsb r3, r5, r3
 *   @0xccc2c cmp r5, r3
 *   @0xccc30 ble 0xccc28 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x16c>
 *   @0xccc34 add r7, r3, r6
 *   @0xccc38 cmp r5, r7
 *   @0xccc3c movge r7, #0
 *   @0xccc40 movlt r7, #1
 *   @0xccc44 cmp r2, #0
 *   @0xccc48 beq 0xccb30 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x74>
 *   @0xccc4c bic r4, r4, r4, asr #31
 *   @0xccc50 ldr r2, [r8, #0x10]
 *   @0xccc54 add r1, r6, r4
 *   @0xccc58 cmp r1, r2
 *   @0xccc5c bgt 0xccce0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x224>
 *   @0xccc60 orrs r7, r10, r7
 *   @0xccc64 bne 0xccb74 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0xb8>
 *   @0xccc68 ldr r0, [r8, #0xc]
 *   @0xccc6c add r1, r9, r3
 *   @0xccc70 mov r2, r6
 *   @0xccc74 add r0, r0, r4
 *   @0xccc78 bl 0xb65bc <memcpy@plt>
 *   @0xccc7c add r0, r4, r6
 *   @0xccc80 cmn r0, #1
 *   @0xccc84 ldr r3, [r8, #0x10]
 *   @0xccc88 ldr r2, [r8, #0x20]
 *   @0xccc8c ldreq r1, [r8, #0x1c]
 *   @0xccc90 movne r1, r0
 *   @0xccc94 cmp r2, r1
 *   @0xccc98 movlt r2, r1
 *   @0xccc9c cmp r2, r3
 *   @0xccca0 strle r2, [r8, #0x20]
 *   @0xccca4 strgt r3, [r8, #0x20]
 *   @0xccca8 add sp, sp, #8
 *   @0xcccac pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcccb0 cmp r4, #0
 *   @0xcccb4 blt 0xcccd8 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x21c>
 *   @0xcccb8 cmp r2, r4
 *   @0xcccbc ble 0xcccfc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x240>
 *   @0xcccc0 add r1, r6, r4
 *   @0xcccc4 cmp r2, r1
 *   @0xcccc8 rsblt r6, r4, r2
 *   @0xccccc b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4>
 *   @0xcccd0 mov r10, #0
 *   @0xcccd4 b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4>
 *   @0xcccd8 mov r4, r10
 *   @0xcccdc b 0xcccc0 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x204>
 *   @0xccce0 ldr r2, [r8]
 *   @0xccce4 mov r0, r8
 *   @0xccce8 ldr r2, [r2, #0x34]
 *   @0xcccec str r3, [sp, #0x4]
 *   @0xcccf0 blx r2
 *   @0xcccf4 ldr r3, [sp, #0x4]
 *   @0xcccf8 b 0xccc60 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x1a4>
 *   @0xcccfc mvn r0, #0
 *   @0xccd00 b 0xccc08 <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb+0x14c>
 *
 * ══ §5/54 F_SkeletonGetBounds(RValue&, CInstance*, CInstance*, int, RValue*)  0x121a8c  size 584  146 条（0x121a8c..0x121cd4）
 * @func 0x121a8c 0x121cd4  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CSkeletonInstance::GetBoundingBoxAttachment(int, char const**, int*, float*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CInstance::SkeletonAnimation() / CreateArrayValOrString(RValue*, int, ...) / ARRAY_RefAlloc(void*) / YYSetString(RValue*, char const*) / F_SkeletonGetBounds(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4
 * 字段偏移 top8: 0x4×15 / 0xc×5 / 0x-2c×4 / 0x-28×2 / 0x10×2 / 0x228×1 / 0x-38×1 / 0x1bc×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121a8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x121a90 add r11, sp, #32
 *   @0x121a94 ldr r4, [pc, #0x228]
 *   @0x121a98 sub sp, sp, #52
 *   @0x121a9c mov r10, r0
 *   @0x121aa0 ldr r4, [pc, r4]
 *   @0x121aa4 mov r6, #2
 *   @0x121aa8 mov r0, r1
 *   @0x121aac str r6, [r10, #0xc]
 *   @0x121ab0 ldr r3, [r4]
 *   @0x121ab4 ldr r8, [r11, #0x4]
 *   @0x121ab8 str r3, [r11, #-0x28]
 *   @0x121abc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x121ac0 subs r7, r0, #0
 *   @0x121ac4 beq 0x121b04 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x121ac8 mov r1, #0
 *   @0x121acc mov r0, r8
 *   @0x121ad0 sub r2, r11, #48
 *   @0x121ad4 str r2, [r11, #-0x38]
 *   @0x121ad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121adc sub r9, r11, #44
 *   @0x121ae0 mov r5, #0
 *   @0x121ae4 sub r2, r11, #48
 *   @0x121ae8 mov r3, r9
 *   @0x121aec str r5, [sp]
 *   @0x121af0 mov r1, r0
 *   @0x121af4 mov r0, r7
 *   @0x121af8 bl 0xbef04 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf>
 *   @0x121afc cmp r0, r5
 *   @0x121b00 bne 0x121b48 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x121b04 ldr r1, [pc, #0x1bc]
 *   @0x121b08 mov r2, #0
 *   @0x121b0c mov r3, #0
 *   @0x121b10 mov r12, #0
 *   @0x121b14 add r1, pc, r1
 *   @0x121b18 mov r0, r10
 *   @0x121b1c str r1, [sp, #0x10]
 *   @0x121b20 mov r1, #2
 *   @0x121b24 strd r2, r3, [sp, #8]
 *   @0x121b28 str r12, [sp]
 *   @0x121b2c bl 0x121944 <_Z22CreateArrayValOrStringP6RValueiz>
 *   @0x121b30 ldr r2, [r11, #-0x28]
 *   @0x121b34 ldr r3, [r4]
 *   @0x121b38 cmp r2, r3
 *   @0x121b3c bne 0x121cc0 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x121b40 sub sp, r11, #32
 *   @0x121b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x121b48 ldr r3, [r11, #-0x2c]
 *   @0x121b4c mov r0, r8
 *   @0x121b50 mov r1, r5
 *   @0x121b54 mov r8, #1
 *   @0x121b58 lsl r3, r3, #3
 *   @0x121b5c add r3, r3, #8
 *   @0x121b60 sub sp, sp, r3
 *   @0x121b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121b68 sub r2, r11, #48
 *   @0x121b6c mov r3, r9
 *   @0x121b70 mov r1, r0
 *   @0x121b74 mov r0, r7
 *   @0x121b78 add r7, sp, #24
 *   @0x121b7c str r7, [sp]
 *   @0x121b80 bl 0xbef04 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf>
 *   @0x121b84 str r6, [r10, #0xc]
 *   @0x121b88 mov r0, r10
 *   @0x121b8c bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x121b90 ldr r1, [pc, #0x134]
 *   @0x121b94 mov r3, r8
 *   @0x121b98 mov r2, #70
 *   @0x121b9c add r1, pc, r1
 *   @0x121ba0 mov r6, r0
 *   @0x121ba4 str r0, [r10]
 *   @0x121ba8 str r8, [r6, #0x10]
 *   @0x121bac mov r0, #8
 *   @0x121bb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x121bb4 ldr lr, [r11, #-0x2c]
 *   @0x121bb8 ldr r1, [pc, #0x110]
 *   @0x121bbc mov r3, r8
 *   @0x121bc0 add lr, lr, r8
 *   @0x121bc4 movw r2, #0x1529
 *   @0x121bc8 add r1, pc, r1
 *   @0x121bcc str r0, [r6, #0x4]
 *   @0x121bd0 lsl r0, lr, #5
 *   @0x121bd4 ldr lr, [r10]
 *   @0x121bd8 ldr r6, [lr, #0x4]
 *   @0x121bdc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x121be0 ldr r3, [r11, #-0x2c]
 *   @0x121be4 add lr, r3, r8
 *   @0x121be8 vmov s13, r3
 *   @0x121bec lsl lr, lr, r8
 *   @0x121bf0 vcvt.f64.s32 d6, s13
 *   @0x121bf4 vmov r2, r3, d6
 *   @0x121bf8 str r0, [r6, #0x4]
 *   @0x121bfc mov r1, r3
 *   @0x121c00 ldr r3, [r10]
 *   @0x121c04 ldr r2, [r3, #0x4]
 *   @0x121c08 ldr r3, [r2, #0x4]
 *   @0x121c0c str lr, [r2]
 *   @0x121c10 vstr s12, [r3]
 *   @0x121c14 str r1, [r3, #0x4]
 *   @0x121c18 ldr r2, [r10]
 *   @0x121c1c str r5, [r3, #0xc]
 *   @0x121c20 ldr r1, [r11, #-0x30]
 *   @0x121c24 ldr r3, [r2, #0x4]
 *   @0x121c28 ldr r3, [r3, #0x4]
 *   @0x121c2c add r0, r3, #16
 *   @0x121c30 str r8, [r3, #0x1c]
 *   @0x121c34 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x121c38 ldr r8, [r11, #-0x2c]
 *   @0x121c3c cmp r8, r5
 *   @0x121c40 ble 0x121b30 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x121c44 add r8, r7, r8, lsl #3
 *   @0x121c48 add r0, r7, #4
 *   @0x121c4c add r8, r8, #4
 *   @0x121c50 mov r1, #32
 *   @0x121c54 vldr s15, [r0, #-4]
 *   @0x121c58 vcvt.f64.f32 d6, s15
 *   @0x121c5c ldr r6, [r10]
 *   @0x121c60 add r7, r1, #16
 *   @0x121c64 ldr r6, [r6, #0x4]
 *   @0x121c68 vmov r2, r3, d6
 *   @0x121c6c ldr r9, [r6, #0x4]
 *   @0x121c70 add r6, r9, r1
 *   @0x121c74 str r5, [r6, #0xc]
 *   @0x121c78 str r2, [r9, r1]
 *   @0x121c7c mov r2, r0
 *   @0x121c80 str r3, [r6, #0x4]
 *   @0x121c84 vldr s15, [r2]
 *   @0x121c88 vcvt.f64.f32 d6, s15
 *   @0x121c8c ldr r3, [r10]
 *   @0x121c90 add r0, r0, #8
 *   @0x121c94 add r1, r1, #32
 *   @0x121c98 cmp r0, r8
 *   @0x121c9c ldr r6, [r3, #0x4]
 *   @0x121ca0 ldr r9, [r6, #0x4]
 *   @0x121ca4 vmov r2, r3, d6
 *   @0x121ca8 add r6, r9, r7
 *   @0x121cac str r5, [r6, #0xc]
 *   @0x121cb0 str r2, [r9, r7]
 *   @0x121cb4 str r3, [r6, #0x4]
 *   @0x121cb8 bne 0x121c54 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x121cbc b 0x121b30 <_Z19F_SkeletonGetBoundsR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x121cc0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x121cc4 .word 0x002cbeb0
 *   @0x121cc8 eoreq sp, r0, r2, lsr #32
 *   @0x121ccc mlaeq r0, r4, r4, pc
 *   @0x121cd0 eoreq r8, r1, r8, lsl #7
 *
 * ══ §6/54 CVariableList::Free(RVariable*)  0x1f6354  size 584  146 条（0x1f6354..0x1f659c）
 * @func 0x1f6354 0x1f659c  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CVariableList::Free(RVariable*)+0x16c / CVariableList::Free(RVariable*)+0x1f8
 * 字段偏移 top8: 0x4×12 / 0x18×6 / 0x8×5 / 0x10×4 / 0x14×2 / 0x24×2 / 0x20×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6354 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f6358 mov r5, r0
 *   @0x1f635c ldr r3, [pc, #0x234]
 *   @0x1f6360 ldr r1, [r0, #0x14]
 *   @0x1f6364 ldr r3, [pc, r3]
 *   @0x1f6368 sub r1, r1, #1
 *   @0x1f636c bic r1, r1, #-16777216
 *   @0x1f6370 ldr r2, [r3]
 *   @0x1f6374 bic r1, r1, #3
 *   @0x1f6378 str r0, [r3]
 *   @0x1f637c cmp r1, #0
 *   @0x1f6380 str r2, [r0, #0x4]
 *   @0x1f6384 beq 0x1f6418 <_ZN13CVariableList4FreeEP9RVariable+0xc4>
 *   @0x1f6388 ldr r1, [r5, #0x24]
 *   @0x1f638c mov r2, #0
 *   @0x1f6390 mov r0, #5
 *   @0x1f6394 str r2, [r5, #0x10]
 *   @0x1f6398 sub r3, r1, #1
 *   @0x1f639c str r2, [r5, #0x8]
 *   @0x1f63a0 bic r3, r3, #-16777216
 *   @0x1f63a4 str r0, [r5, #0x14]
 *   @0x1f63a8 bics r4, r3, #3
 *   @0x1f63ac beq 0x1f63c8 <_ZN13CVariableList4FreeEP9RVariable+0x74>
 *   @0x1f63b0 mov r3, #0
 *   @0x1f63b4 mov r2, #5
 *   @0x1f63b8 str r3, [r5, #0x20]
 *   @0x1f63bc str r3, [r5, #0x18]
 *   @0x1f63c0 str r2, [r5, #0x24]
 *   @0x1f63c4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f63c8 bic r1, r1, #-16777216
 *   @0x1f63cc cmp r1, #2
 *   @0x1f63d0 beq 0x1f644c <_ZN13CVariableList4FreeEP9RVariable+0xf8>
 *   @0x1f63d4 cmp r1, #3
 *   @0x1f63d8 beq 0x1f6424 <_ZN13CVariableList4FreeEP9RVariable+0xd0>
 *   @0x1f63dc cmp r1, #1
 *   @0x1f63e0 bne 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f63e4 ldr r4, [r5, #0x18]
 *   @0x1f63e8 cmp r4, #0
 *   @0x1f63ec beq 0x1f640c <_ZN13CVariableList4FreeEP9RVariable+0xb8>
 *   @0x1f63f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f63f4 ldr r6, [r4, #0x4]
 *   @0x1f63f8 sub r6, r6, #1
 *   @0x1f63fc str r6, [r4, #0x4]
 *   @0x1f6400 cmp r6, #0
 *   @0x1f6404 beq 0x1f6488 <_ZN13CVariableList4FreeEP9RVariable+0x134>
 *   @0x1f6408 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f640c mov r3, #0
 *   @0x1f6410 str r3, [r5, #0x18]
 *   @0x1f6414 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f6418 add r0, r0, #8
 *   @0x1f641c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6420 b 0x1f6388 <_ZN13CVariableList4FreeEP9RVariable+0x34>
 *   @0x1f6424 ldr r3, [r5, #0x20]
 *   @0x1f6428 tst r3, #8
 *   @0x1f642c beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f6430 ldr r0, [r5, #0x18]
 *   @0x1f6434 cmp r0, #0
 *   @0x1f6438 beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f643c ldr r3, [r0]
 *   @0x1f6440 ldr r3, [r3, #0x4]
 *   @0x1f6444 blx r3
 *   @0x1f6448 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f644c ldr r8, [r5, #0x18]
 *   @0x1f6450 cmp r8, #0
 *   @0x1f6454 beq 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f6458 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f645c ldr r3, [r8]
 *   @0x1f6460 ldr r1, [r8, #0x8]
 *   @0x1f6464 add r2, r5, #24
 *   @0x1f6468 sub r3, r3, #1
 *   @0x1f646c str r3, [r8]
 *   @0x1f6470 cmp r1, r2
 *   @0x1f6474 streq r4, [r8, #0x8]
 *   @0x1f6478 cmp r3, #0
 *   @0x1f647c ble 0x1f64c0 <_ZN13CVariableList4FreeEP9RVariable+0x16c>
 *   @0x1f6480 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6484 b 0x1f63b0 <_ZN13CVariableList4FreeEP9RVariable+0x5c>
 *   @0x1f6488 ldr r0, [r4]
 *   @0x1f648c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6490 str r6, [r4]
 *   @0x1f6494 str r6, [r4, #0x8]
 *   @0x1f6498 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f649c ldr r6, [r4, #0x4]
 *   @0x1f64a0 sub r6, r6, #1
 *   @0x1f64a4 str r6, [r4, #0x4]
 *   @0x1f64a8 cmp r6, #0
 *   @0x1f64ac beq 0x1f6574 <_ZN13CVariableList4FreeEP9RVariable+0x220>
 *   @0x1f64b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f64b4 mov r0, r4
 *   @0x1f64b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f64bc b 0x1f6408 <_ZN13CVariableList4FreeEP9RVariable+0xb4>
 *   @0x1f64c0 ldr r3, [r8, #0x10]
 *   @0x1f64c4 cmp r3, #0
 *   @0x1f64c8 movgt r7, #0
 *   @0x1f64cc movgt r11, #5
 *   @0x1f64d0 movgt r6, r7
 *   @0x1f64d4 ble 0x1f654c <_ZN13CVariableList4FreeEP9RVariable+0x1f8>
 *   @0x1f64d8 ldr r3, [r8, #0x4]
 *   @0x1f64dc add r9, r3, r7, lsl #3
 *   @0x1f64e0 ldr r10, [r3, r7, lsl #3]
 *   @0x1f64e4 ldr r4, [r9, #0x4]
 *   @0x1f64e8 add r10, r4, r10, lsl #4
 *   @0x1f64ec cmp r4, r10
 *   @0x1f64f0 blo 0x1f650c <_ZN13CVariableList4FreeEP9RVariable+0x1b8>
 *   @0x1f64f4 b 0x1f656c <_ZN13CVariableList4FreeEP9RVariable+0x218>
 *   @0x1f64f8 str r6, [r4, #0x8]
 *   @0x1f64fc str r11, [r4, #0xc]
 *   @0x1f6500 str r6, [r4], #16
 *   @0x1f6504 cmp r10, r4
 *   @0x1f6508 bls 0x1f6530 <_ZN13CVariableList4FreeEP9RVariable+0x1dc>
 *   @0x1f650c ldr r3, [r4, #0xc]
 *   @0x1f6510 sub r3, r3, #1
 *   @0x1f6514 bic r3, r3, #-16777216
 *   @0x1f6518 bic r3, r3, #3
 *   @0x1f651c cmp r3, #0
 *   @0x1f6520 bne 0x1f64f8 <_ZN13CVariableList4FreeEP9RVariable+0x1a4>
 *   @0x1f6524 mov r0, r4
 *   @0x1f6528 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f652c b 0x1f64f8 <_ZN13CVariableList4FreeEP9RVariable+0x1a4>
 *   @0x1f6530 ldr r0, [r9, #0x4]
 *   @0x1f6534 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f6538 ldr r3, [r8, #0x10]
 *   @0x1f653c add r7, r7, #1
 *   @0x1f6540 str r6, [r9, #0x4]
 *   @0x1f6544 cmp r7, r3
 *   @0x1f6548 blt 0x1f64d8 <_ZN13CVariableList4FreeEP9RVariable+0x184>
 *   @0x1f654c ldr r0, [r8, #0x4]
 *   @0x1f6550 mov r4, #0
 *   @0x1f6554 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f6558 str r4, [r8, #0x4]
 *   @0x1f655c mov r0, r8
 *   @0x1f6560 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f6564 str r4, [r5, #0x18]
 *   @0x1f6568 b 0x1f6480 <_ZN13CVariableList4FreeEP9RVariable+0x12c>
 *   @0x1f656c mov r0, r4
 *   @0x1f6570 b 0x1f6534 <_ZN13CVariableList4FreeEP9RVariable+0x1e0>
 *   @0x1f6574 ldr r0, [r4]
 *   @0x1f6578 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f657c mov r0, r4
 *   @0x1f6580 str r6, [r4]
 *   @0x1f6584 str r6, [r4, #0x8]
 *   @0x1f6588 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f658c mov r0, r4
 *   @0x1f6590 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6594 b 0x1f64b0 <_ZN13CVariableList4FreeEP9RVariable+0x15c>
 *   @0x1f6598 ldrsbeq r10, [pc], -r0
 *
 * ══ §7/54 CVariableList::Free(RVariable*, RVariable**, RVariable**)  0x1f67ac  size 584  146 条（0x1f67ac..0x1f69f4）
 * @func 0x1f67ac 0x1f69f4  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CVariableList::Free(RVariable*, RVariable**, RVariable**)+0x170 / CVariableList::Free(RVariable*, RVariable**, RVariable**)+0x1fc
 * 字段偏移 top8: 0x4×12 / 0x18×6 / 0x8×5 / 0x10×4 / 0x14×2 / 0x24×2 / 0x20×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f67ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f67b0 mov r5, r0
 *   @0x1f67b4 ldr r3, [r2]
 *   @0x1f67b8 cmp r3, #0
 *   @0x1f67bc ldr r3, [r0, #0x14]
 *   @0x1f67c0 streq r0, [r2]
 *   @0x1f67c4 sub r3, r3, #1
 *   @0x1f67c8 ldr r2, [r1]
 *   @0x1f67cc bic r3, r3, #-16777216
 *   @0x1f67d0 bic r3, r3, #3
 *   @0x1f67d4 cmp r3, #0
 *   @0x1f67d8 str r2, [r0, #0x4]
 *   @0x1f67dc str r0, [r1]
 *   @0x1f67e0 beq 0x1f6874 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xc8>
 *   @0x1f67e4 ldr r1, [r5, #0x24]
 *   @0x1f67e8 mov r2, #0
 *   @0x1f67ec mov r0, #5
 *   @0x1f67f0 str r2, [r5, #0x10]
 *   @0x1f67f4 sub r3, r1, #1
 *   @0x1f67f8 str r2, [r5, #0x8]
 *   @0x1f67fc bic r3, r3, #-16777216
 *   @0x1f6800 str r0, [r5, #0x14]
 *   @0x1f6804 bics r4, r3, #3
 *   @0x1f6808 beq 0x1f6824 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x78>
 *   @0x1f680c mov r3, #0
 *   @0x1f6810 mov r2, #5
 *   @0x1f6814 str r3, [r5, #0x20]
 *   @0x1f6818 str r3, [r5, #0x18]
 *   @0x1f681c str r2, [r5, #0x24]
 *   @0x1f6820 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f6824 bic r1, r1, #-16777216
 *   @0x1f6828 cmp r1, #2
 *   @0x1f682c beq 0x1f68a8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xfc>
 *   @0x1f6830 cmp r1, #3
 *   @0x1f6834 beq 0x1f6880 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xd4>
 *   @0x1f6838 cmp r1, #1
 *   @0x1f683c bne 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f6840 ldr r4, [r5, #0x18]
 *   @0x1f6844 cmp r4, #0
 *   @0x1f6848 beq 0x1f6868 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xbc>
 *   @0x1f684c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6850 ldr r6, [r4, #0x4]
 *   @0x1f6854 sub r6, r6, #1
 *   @0x1f6858 str r6, [r4, #0x4]
 *   @0x1f685c cmp r6, #0
 *   @0x1f6860 beq 0x1f68e4 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x138>
 *   @0x1f6864 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6868 mov r3, #0
 *   @0x1f686c str r3, [r5, #0x18]
 *   @0x1f6870 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f6874 add r0, r0, #8
 *   @0x1f6878 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f687c b 0x1f67e4 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x38>
 *   @0x1f6880 ldr r3, [r5, #0x20]
 *   @0x1f6884 tst r3, #8
 *   @0x1f6888 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f688c ldr r0, [r5, #0x18]
 *   @0x1f6890 cmp r0, #0
 *   @0x1f6894 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f6898 ldr r3, [r0]
 *   @0x1f689c ldr r3, [r3, #0x4]
 *   @0x1f68a0 blx r3
 *   @0x1f68a4 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f68a8 ldr r8, [r5, #0x18]
 *   @0x1f68ac cmp r8, #0
 *   @0x1f68b0 beq 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f68b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f68b8 ldr r3, [r8]
 *   @0x1f68bc ldr r1, [r8, #0x8]
 *   @0x1f68c0 add r2, r5, #24
 *   @0x1f68c4 sub r3, r3, #1
 *   @0x1f68c8 str r3, [r8]
 *   @0x1f68cc cmp r1, r2
 *   @0x1f68d0 streq r4, [r8, #0x8]
 *   @0x1f68d4 cmp r3, #0
 *   @0x1f68d8 ble 0x1f691c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x170>
 *   @0x1f68dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f68e0 b 0x1f680c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x60>
 *   @0x1f68e4 ldr r0, [r4]
 *   @0x1f68e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f68ec str r6, [r4]
 *   @0x1f68f0 str r6, [r4, #0x8]
 *   @0x1f68f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f68f8 ldr r6, [r4, #0x4]
 *   @0x1f68fc sub r6, r6, #1
 *   @0x1f6900 str r6, [r4, #0x4]
 *   @0x1f6904 cmp r6, #0
 *   @0x1f6908 beq 0x1f69d0 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x224>
 *   @0x1f690c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6910 mov r0, r4
 *   @0x1f6914 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6918 b 0x1f6864 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0xb8>
 *   @0x1f691c ldr r3, [r8, #0x10]
 *   @0x1f6920 cmp r3, #0
 *   @0x1f6924 movgt r7, #0
 *   @0x1f6928 movgt r11, #5
 *   @0x1f692c movgt r6, r7
 *   @0x1f6930 ble 0x1f69a8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1fc>
 *   @0x1f6934 ldr r3, [r8, #0x4]
 *   @0x1f6938 add r9, r3, r7, lsl #3
 *   @0x1f693c ldr r10, [r3, r7, lsl #3]
 *   @0x1f6940 ldr r4, [r9, #0x4]
 *   @0x1f6944 add r10, r4, r10, lsl #4
 *   @0x1f6948 cmp r4, r10
 *   @0x1f694c blo 0x1f6968 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1bc>
 *   @0x1f6950 b 0x1f69c8 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x21c>
 *   @0x1f6954 str r6, [r4, #0x8]
 *   @0x1f6958 str r11, [r4, #0xc]
 *   @0x1f695c str r6, [r4], #16
 *   @0x1f6960 cmp r10, r4
 *   @0x1f6964 bls 0x1f698c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1e0>
 *   @0x1f6968 ldr r3, [r4, #0xc]
 *   @0x1f696c sub r3, r3, #1
 *   @0x1f6970 bic r3, r3, #-16777216
 *   @0x1f6974 bic r3, r3, #3
 *   @0x1f6978 cmp r3, #0
 *   @0x1f697c bne 0x1f6954 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1a8>
 *   @0x1f6980 mov r0, r4
 *   @0x1f6984 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6988 b 0x1f6954 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1a8>
 *   @0x1f698c ldr r0, [r9, #0x4]
 *   @0x1f6990 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f6994 ldr r3, [r8, #0x10]
 *   @0x1f6998 add r7, r7, #1
 *   @0x1f699c str r6, [r9, #0x4]
 *   @0x1f69a0 cmp r7, r3
 *   @0x1f69a4 blt 0x1f6934 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x188>
 *   @0x1f69a8 ldr r0, [r8, #0x4]
 *   @0x1f69ac mov r4, #0
 *   @0x1f69b0 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f69b4 str r4, [r8, #0x4]
 *   @0x1f69b8 mov r0, r8
 *   @0x1f69bc bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1f69c0 str r4, [r5, #0x18]
 *   @0x1f69c4 b 0x1f68dc <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x130>
 *   @0x1f69c8 mov r0, r4
 *   @0x1f69cc b 0x1f6990 <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x1e4>
 *   @0x1f69d0 ldr r0, [r4]
 *   @0x1f69d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f69d8 mov r0, r4
 *   @0x1f69dc str r6, [r4]
 *   @0x1f69e0 str r6, [r4, #0x8]
 *   @0x1f69e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f69e8 mov r0, r4
 *   @0x1f69ec bl 0x27d1d0 <_ZdlPv>
 *   @0x1f69f0 b 0x1f690c <_ZN13CVariableList4FreeEP9RVariablePS1_S2_+0x160>
 *
 * ══ §8/54 anon_23cea4  0x23cea4  size 584  146 条（0x23cea4..0x23d0ec）
 * @func 0x23cea4 0x23d0ec  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_23cea4+0x178×2 / 0xb65b0 / anon_23cea4+0xcc / anon_23cea4+0x138 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x-30×2 / 0x-28×2 / 0x2×2 / 0x1×2 / 0x22c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cea4 andeq r0, r0, r0
 *   @0x23cea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23ceac mov r5, r3
 *   @0x23ceb0 add r11, sp, #32
 *   @0x23ceb4 ldr r8, [pc, #0x22c]
 *   @0x23ceb8 sub sp, sp, #20
 *   @0x23cebc add r3, r3, r3, lsl #1
 *   @0x23cec0 str r1, [r11, #-0x30]
 *   @0x23cec4 lsl r3, r3, #1
 *   @0x23cec8 ldr r8, [pc, r8]
 *   @0x23cecc add r1, r3, #15
 *   @0x23ced0 mov r7, r0
 *   @0x23ced4 bic r1, r1, #7
 *   @0x23ced8 ldr r0, [r8]
 *   @0x23cedc sub sp, sp, r1
 *   @0x23cee0 mov r4, r2
 *   @0x23cee4 mov r1, #0
 *   @0x23cee8 add r2, r3, #1
 *   @0x23ceec str r0, [r11, #-0x28]
 *   @0x23cef0 add r5, r5, r4
 *   @0x23cef4 mov r0, sp
 *   @0x23cef8 mov r6, sp
 *   @0x23cefc bl 0xb65b0 <memset@plt>
 *   @0x23cf00 cmp r4, r5
 *   @0x23cf04 bge 0x23cfe8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x23cf08 movw r10, #0xfffe
 *   @0x23cf0c movt r10, #0x1f
 *   @0x23cf10 mov r0, #0
 *   @0x23cf14 movw r9, #0x7fe
 *   @0x23cf18 vldr d6, [pc, #432]
 *   @0x23cf1c vldr d5, [pc, #436]
 *   @0x23cf20 vldr d4, [pc, #440]
 *   @0x23cf24 sub r1, r4, #-2147483647
 *   @0x23cf28 ldr r3, [r7]
 *   @0x23cf2c mov r12, #0
 *   @0x23cf30 mov lr, #1
 *   @0x23cf34 add r1, r3, r1, lsl #1
 *   @0x23cf38 b 0x23cf40 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x23cf3c mov lr, r2
 *   @0x23cf40 ldrh r3, [r1, #2]!
 *   @0x23cf44 vmov s7, r3
 *   @0x23cf48 vcvt.f64.u32 d7, s7
 *   @0x23cf4c vcmpe.f64 d7, d6
 *   @0x23cf50 vmrs APSR_nzcv, fpscr
 *   @0x23cf54 bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf58 vcmpe.f64 d7, d5
 *   @0x23cf5c vmrs APSR_nzcv, fpscr
 *   @0x23cf60 ble 0x23cf70 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x23cf64 vcmpe.f64 d7, d4
 *   @0x23cf68 vmrs APSR_nzcv, fpscr
 *   @0x23cf6c bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf70 and r2, r3, #1024
 *   @0x23cf74 uxth r2, r2
 *   @0x23cf78 cmp r2, #0
 *   @0x23cf7c bne 0x23d00c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x23cf80 add r4, r4, #1
 *   @0x23cf84 cmp r5, r4
 *   @0x23cf88 beq 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf8c sub r12, r3, #55296
 *   @0x23cf90 lsl r12, r12, #10
 *   @0x23cf94 add r12, r12, #65536
 *   @0x23cf98 bgt 0x23cf3c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x23cf9c cmp r12, #126
 *   @0x23cfa0 strble r12, [r6, r0]
 *   @0x23cfa4 addle r0, r0, #1
 *   @0x23cfa8 ble 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23cfac cmp r12, r9
 *   @0x23cfb0 bgt 0x23d024 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x23cfb4 ubfx r3, r12, #0x6, #0x5
 *   @0x23cfb8 and r12, r12, #63
 *   @0x23cfbc add r2, r0, #1
 *   @0x23cfc0 mvn r3, r3, lsl #26
 *   @0x23cfc4 mvn r12, r12, lsl #25
 *   @0x23cfc8 mvn r3, r3, lsr #26
 *   @0x23cfcc strb r3, [r6, r0]
 *   @0x23cfd0 add r0, r0, #2
 *   @0x23cfd4 mvn r12, r12, lsr #25
 *   @0x23cfd8 strb r12, [r6, r2]
 *   @0x23cfdc add r4, r4, #1
 *   @0x23cfe0 cmp r5, r4
 *   @0x23cfe4 bgt 0x23cf24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x23cfe8 ldr r0, [r11, #-0x30]
 *   @0x23cfec mov r1, r6
 *   @0x23cff0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23cff4 ldr r2, [r11, #-0x28]
 *   @0x23cff8 ldr r3, [r8]
 *   @0x23cffc cmp r2, r3
 *   @0x23d000 bne 0x23d0cc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x23d004 sub sp, r11, #32
 *   @0x23d008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23d00c cmp lr, #0
 *   @0x23d010 subeq r3, r3, #56320
 *   @0x23d014 orreq r12, r12, r3
 *   @0x23d018 beq 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x23d01c mov r12, r3
 *   @0x23d020 b 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x23d024 movw r3, #0xfffe
 *   @0x23d028 cmp r12, r3
 *   @0x23d02c bgt 0x23d070 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x23d030 ubfx r2, r12, #0xc, #0x4
 *   @0x23d034 ubfx lr, r12, #0x6, #0x6
 *   @0x23d038 and r12, r12, #63
 *   @0x23d03c add r1, r0, #2
 *   @0x23d040 mov r3, r6
 *   @0x23d044 mvn r2, r2, lsl #27
 *   @0x23d048 mvn lr, lr, lsl #25
 *   @0x23d04c mvn r12, r12, lsl #25
 *   @0x23d050 mvn r2, r2, lsr #27
 *   @0x23d054 mvn lr, lr, lsr #25
 *   @0x23d058 strb r2, [r3, r0]!
 *   @0x23d05c mvn r12, r12, lsr #25
 *   @0x23d060 strb lr, [r3, #0x1]
 *   @0x23d064 add r0, r0, #3
 *   @0x23d068 strb r12, [r6, r1]
 *   @0x23d06c b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d070 cmp r12, r10
 *   @0x23d074 bgt 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d078 and r2, r12, #3670016
 *   @0x23d07c mov r3, r6
 *   @0x23d080 ubfx lr, r12, #0xc, #0x6
 *   @0x23d084 ubfx r1, r12, #0x6, #0x6
 *   @0x23d088 asr r2, r2, #18
 *   @0x23d08c and r12, r12, #63
 *   @0x23d090 mvn lr, lr, lsl #25
 *   @0x23d094 mvn r1, r1, lsl #25
 *   @0x23d098 mvn r2, r2, lsl #28
 *   @0x23d09c mvn r12, r12, lsl #25
 *   @0x23d0a0 mvn r2, r2, lsr #28
 *   @0x23d0a4 strb r2, [r3, r0]!
 *   @0x23d0a8 add r2, r0, #3
 *   @0x23d0ac mvn lr, lr, lsr #25
 *   @0x23d0b0 mvn r1, r1, lsr #25
 *   @0x23d0b4 strb lr, [r3, #0x1]
 *   @0x23d0b8 mvn r12, r12, lsr #25
 *   @0x23d0bc strb r1, [r3, #0x2]
 *   @0x23d0c0 add r0, r0, #4
 *   @0x23d0c4 strb r12, [r6, r2]
 *   @0x23d0c8 b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d0cc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x23d0d0 andeq r0, r0, r0
 *   @0x23d0d4 rscmi pc, r10, r0, ror #31
 *   @0x23d0d8 andeq r0, r0, r0
 *   @0x23d0dc rscmi r0, r12, r0
 *   @0x23d0e0 andeq r0, r0, r0
 *   @0x23d0e4 rscmi pc, pc, r0, ror #31
 *   @0x23d0e8 andseq r0, r11, r8, lsl #21
 *
 * ══ §9/54 Debug_WriteSurfaceIds(Buffer_Standard*, bool)  0x29c15c  size 584  146 条（0x29c15c..0x29c3a4）
 * @func 0x29c15c 0x29c3a4  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Debug_WriteSurfaceIds(Buffer_Standard*, bool)+0x204 / Debug_WriteSurfaceIds(Buffer_Standard*, bool)+0x234 / Debug_WriteSurfaceIds(Buffer_Standard*, bool)+0x17c
 * 字段偏移 top8: 0x8×7 / 0x38×6 / 0x30×6 / 0x4×5 / 0x2c×3 / 0x1c×2 / 0xc×2 / 0x10×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c15c subs r3, r1, #0
 *   @0x29c160 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29c164 mov r7, r0
 *   @0x29c168 sub sp, sp, #12
 *   @0x29c16c beq 0x29c368 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x20c>
 *   @0x29c170 ldr r9, [pc, #0x220]
 *   @0x29c174 add r6, r0, #44
 *   @0x29c178 ldr r3, [r0]
 *   @0x29c17c mov r8, #0
 *   @0x29c180 ldr r9, [pc, r9]
 *   @0x29c184 vldr s15, [r9]
 *   @0x29c188 vcvt.f64.s32 d7, s15
 *   @0x29c18c str r8, [r0, #0x38]
 *   @0x29c190 mov r2, r6
 *   @0x29c194 mov r1, #6
 *   @0x29c198 vmov r4, r5, d7
 *   @0x29c19c vstr s14, [r7, #44]
 *   @0x29c1a0 str r5, [r7, #0x30]
 *   @0x29c1a4 ldr r3, [r3, #0x8]
 *   @0x29c1a8 blx r3
 *   @0x29c1ac ldr r3, [r9]
 *   @0x29c1b0 cmp r3, r8
 *   @0x29c1b4 ble 0x29c360 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x204>
 *   @0x29c1b8 ldr r3, [pc, #0x1dc]
 *   @0x29c1bc mov r1, #6
 *   @0x29c1c0 ldr r12, [r7]
 *   @0x29c1c4 mov r2, r6
 *   @0x29c1c8 ldr r3, [pc, r3]
 *   @0x29c1cc mov r0, r7
 *   @0x29c1d0 str r8, [r7, #0x38]
 *   @0x29c1d4 ldr r4, [r3]
 *   @0x29c1d8 ldr r9, [pc, #0x1c0]
 *   @0x29c1dc vmov s15, r4
 *   @0x29c1e0 vcvt.f64.s32 d7, s15
 *   @0x29c1e4 vmov r4, r5, d7
 *   @0x29c1e8 vstr s14, [r7, #44]
 *   @0x29c1ec str r5, [r7, #0x30]
 *   @0x29c1f0 ldr r3, [r12, #0x8]
 *   @0x29c1f4 blx r3
 *   @0x29c1f8 ldr r3, [r7]
 *   @0x29c1fc ldr r12, [r7, #0x1c]
 *   @0x29c200 mov r1, #5
 *   @0x29c204 str r8, [r7, #0x2c]
 *   @0x29c208 mov r2, r6
 *   @0x29c20c str r8, [r7, #0x30]
 *   @0x29c210 mov r0, r7
 *   @0x29c214 str r8, [r7, #0x38]
 *   @0x29c218 ldr r3, [r3, #0x8]
 *   @0x29c21c str r12, [sp, #0x4]
 *   @0x29c220 blx r3
 *   @0x29c224 ldr r9, [pc, r9]
 *   @0x29c228 mov r2, r8
 *   @0x29c22c ldr r1, [r9]
 *   @0x29c230 ldr r0, [r9, #0x4]
 *   @0x29c234 b 0x29c240 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0xe4>
 *   @0x29c238 cmp r0, r2
 *   @0x29c23c blt 0x29c390 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x234>
 *   @0x29c240 ldr r11, [r1, r2, lsl #3]
 *   @0x29c244 mov r10, r2
 *   @0x29c248 add r2, r2, #1
 *   @0x29c24c cmp r11, #0
 *   @0x29c250 beq 0x29c238 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0xdc>
 *   @0x29c254 ldr r2, [r11, #0xc]
 *   @0x29c258 cmp r2, #0
 *   @0x29c25c moveq r8, r2
 *   @0x29c260 beq 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c>
 *   @0x29c264 mov r8, #0
 *   @0x29c268 b 0x29c278 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x11c>
 *   @0x29c26c ldr r2, [r11, #0xc]
 *   @0x29c270 cmp r2, #0
 *   @0x29c274 beq 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c>
 *   @0x29c278 ldr r4, [r2]
 *   @0x29c27c mov r3, #0
 *   @0x29c280 ldr lr, [r7]
 *   @0x29c284 mov r0, r7
 *   @0x29c288 str r3, [r7, #0x38]
 *   @0x29c28c mov r1, #5
 *   @0x29c290 vmov s15, r4
 *   @0x29c294 mov r2, r6
 *   @0x29c298 add r8, r8, #1
 *   @0x29c29c vcvt.f64.u32 d7, s15
 *   @0x29c2a0 vmov r4, r5, d7
 *   @0x29c2a4 vstr s14, [r7, #44]
 *   @0x29c2a8 str r5, [r7, #0x30]
 *   @0x29c2ac ldr r4, [lr, #0x8]
 *   @0x29c2b0 blx r4
 *   @0x29c2b4 ldr r11, [r11, #0x4]
 *   @0x29c2b8 cmp r11, #0
 *   @0x29c2bc bne 0x29c26c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x110>
 *   @0x29c2c0 ldr r0, [r9, #0x4]
 *   @0x29c2c4 add r2, r10, #1
 *   @0x29c2c8 cmp r2, r0
 *   @0x29c2cc bgt 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c>
 *   @0x29c2d0 ldr r1, [r9]
 *   @0x29c2d4 add r1, r1, r10, lsl #3
 *   @0x29c2d8 ldr r11, [r1, #0x8]
 *   @0x29c2dc mov r10, r2
 *   @0x29c2e0 add r1, r1, #8
 *   @0x29c2e4 add r2, r2, #1
 *   @0x29c2e8 cmp r11, #0
 *   @0x29c2ec bne 0x29c26c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x110>
 *   @0x29c2f0 cmp r2, r0
 *   @0x29c2f4 ble 0x29c2d8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x17c>
 *   @0x29c2f8 ldr r3, [r7]
 *   @0x29c2fc mov r1, #0
 *   @0x29c300 ldr r2, [sp, #0x4]
 *   @0x29c304 mov r0, r7
 *   @0x29c308 mov r9, r1
 *   @0x29c30c ldr r10, [r7, #0x1c]
 *   @0x29c310 ldr r3, [r3, #0x10]
 *   @0x29c314 blx r3
 *   @0x29c318 vmov s15, r8
 *   @0x29c31c ldr r3, [r7]
 *   @0x29c320 mov r2, r6
 *   @0x29c324 vcvt.f64.s32 d7, s15
 *   @0x29c328 mov r1, #5
 *   @0x29c32c str r9, [r7, #0x38]
 *   @0x29c330 mov r0, r7
 *   @0x29c334 vmov r4, r5, d7
 *   @0x29c338 vstr s14, [r7, #44]
 *   @0x29c33c str r5, [r7, #0x30]
 *   @0x29c340 ldr r3, [r3, #0x8]
 *   @0x29c344 blx r3
 *   @0x29c348 ldr r3, [r7]
 *   @0x29c34c mov r1, r9
 *   @0x29c350 mov r2, r10
 *   @0x29c354 mov r0, r7
 *   @0x29c358 ldr r3, [r3, #0x10]
 *   @0x29c35c blx r3
 *   @0x29c360 add sp, sp, #12
 *   @0x29c364 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29c368 mov r2, r0
 *   @0x29c36c str r3, [r0, #0x2c]
 *   @0x29c370 ldr r12, [r2], #44
 *   @0x29c374 mov r1, #5
 *   @0x29c378 str r3, [r0, #0x30]
 *   @0x29c37c str r3, [r0, #0x38]
 *   @0x29c380 ldr r3, [r12, #0x8]
 *   @0x29c384 blx r3
 *   @0x29c388 add sp, sp, #12
 *   @0x29c38c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29c390 mov r8, r11
 *   @0x29c394 b 0x29c2f8 <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb+0x19c>
 *   @0x29c398 andseq r4, r5, r0, lsr r1
 *   @0x29c39c andseq r2, r5, r0, lsl r4
 *   @0x29c3a0 andseq r1, r5, r12, ror #17
 *
 * ══ §10/54 CSkeletonSprite::LoadFromFile(char*, char*)  0xbd99c  size 580  145 条（0xbd99c..0xbdbe0）
 * @func 0xbd99c 0xbdbe0  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / 0xb6550×2 / LoadSave::SaveFileExists(char const*)×2 / LoadSave::ReadSaveFile(char const*, int*)×2 / MemoryManager::Free(void const*)×2 / LoadSave::BundleFileExists(char const*)×2 / LoadSave::ReadBundleFile(char const*, int*)×2 / 0xb6544
 * 字段偏移 top8: 0x8×7 / 0xc×5 / 0x4×3 / 0x14c×2 / 0x1e8×1 / 0x1a8×1 / 0x160×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd99c push {r4, r5, r6, r7, r8, lr}
 *   @0xbd9a0 mov r8, r0
 *   @0xbd9a4 sub sp, sp, #16
 *   @0xbd9a8 mov r0, r2
 *   @0xbd9ac mov r5, r1
 *   @0xbd9b0 mov r6, r2
 *   @0xbd9b4 bl 0xb6538 <strlen@plt>
 *   @0xbd9b8 mov r4, r0
 *   @0xbd9bc mov r0, r5
 *   @0xbd9c0 bl 0xb6538 <strlen@plt>
 *   @0xbd9c4 add r0, r4, r0
 *   @0xbd9c8 add r0, r0, #7
 *   @0xbd9cc bl 0xb6544 <malloc@plt>
 *   @0xbd9d0 ldr r1, [pc, #0x1e8]
 *   @0xbd9d4 mov r2, r6
 *   @0xbd9d8 mov r3, r5
 *   @0xbd9dc add r1, pc, r1
 *   @0xbd9e0 mov r4, r0
 *   @0xbd9e4 bl 0xb6550 <sprintf@plt>
 *   @0xbd9e8 mov r0, r4
 *   @0xbd9ec mov r3, #0
 *   @0xbd9f0 str r3, [sp, #0x8]
 *   @0xbd9f4 str r3, [sp, #0xc]
 *   @0xbd9f8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xbd9fc cmp r0, #0
 *   @0xbda00 mov r0, r4
 *   @0xbda04 beq 0xbdb74 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1d8>
 *   @0xbda08 add r1, sp, #8
 *   @0xbda0c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xbda10 mov r7, r0
 *   @0xbda14 ldr r1, [pc, #0x1a8]
 *   @0xbda18 mov r2, r6
 *   @0xbda1c mov r3, r5
 *   @0xbda20 mov r0, r4
 *   @0xbda24 add r1, pc, r1
 *   @0xbda28 bl 0xb6550 <sprintf@plt>
 *   @0xbda2c mov r0, r4
 *   @0xbda30 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xbda34 cmp r0, #0
 *   @0xbda38 mov r0, r4
 *   @0xbda3c beq 0xbdb4c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1b0>
 *   @0xbda40 add r1, sp, #12
 *   @0xbda44 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xbda48 mov r5, r0
 *   @0xbda4c cmp r5, #0
 *   @0xbda50 cmpne r7, #0
 *   @0xbda54 moveq r6, #0
 *   @0xbda58 movne r6, #1
 *   @0xbda5c beq 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c>
 *   @0xbda60 ldr r2, [pc, #0x160]
 *   @0xbda64 mov r3, #0
 *   @0xbda68 ldr r1, [sp, #0x8]
 *   @0xbda6c mov r0, r7
 *   @0xbda70 add r2, pc, r2
 *   @0xbda74 bl 0x284174 <spAtlas_create>
 *   @0xbda78 ldr r3, [pc, #0x14c]
 *   @0xbda7c ldr r1, [pc, #0x14c]
 *   @0xbda80 ldr r3, [pc, r3]
 *   @0xbda84 add r1, pc, r1
 *   @0xbda88 ldr r6, [r3]
 *   @0xbda8c ldr lr, [r6]
 *   @0xbda90 ldr r12, [r0, #0x4]
 *   @0xbda94 str r0, [r8, #0x8]
 *   @0xbda98 mov r0, r6
 *   @0xbda9c ldm r12, {r2, r3}
 *   @0xbdaa0 ldr r12, [r12, #0x8]
 *   @0xbdaa4 str r12, [sp]
 *   @0xbdaa8 ldr r12, [lr, #0xc]
 *   @0xbdaac blx r12
 *   @0xbdab0 ldr r3, [r8, #0x8]
 *   @0xbdab4 ldr lr, [r6]
 *   @0xbdab8 mov r0, r6
 *   @0xbdabc ldr r1, [pc, #0x110]
 *   @0xbdac0 ldr r12, [r3]
 *   @0xbdac4 add r1, pc, r1
 *   @0xbdac8 ldr r3, [r12, #0x20]
 *   @0xbdacc ldr r2, [r12, #0x4]
 *   @0xbdad0 ldr r12, [r12, #0x24]
 *   @0xbdad4 str r12, [sp]
 *   @0xbdad8 ldr r12, [lr, #0xc]
 *   @0xbdadc blx r12
 *   @0xbdae0 ldr r0, [r8, #0x8]
 *   @0xbdae4 bl 0x28b734 <spSkeletonJson_create>
 *   @0xbdae8 mov r1, r5
 *   @0xbdaec str r0, [r8]
 *   @0xbdaf0 bl 0x28b84c <spSkeletonJson_readSkeletonData>
 *   @0xbdaf4 cmp r0, #0
 *   @0xbdaf8 mov r3, r0
 *   @0xbdafc str r0, [r8, #0x4]
 *   @0xbdb00 beq 0xbdb98 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1fc>
 *   @0xbdb04 ldr r2, [r0, #0x28]
 *   @0xbdb08 mov r0, r6
 *   @0xbdb0c ldr r3, [r6]
 *   @0xbdb10 mov r6, #1
 *   @0xbdb14 ldr r1, [pc, #0xbc]
 *   @0xbdb18 ldr r2, [r2]
 *   @0xbdb1c add r1, pc, r1
 *   @0xbdb20 ldr r3, [r3, #0xc]
 *   @0xbdb24 blx r3
 *   @0xbdb28 mov r0, r7
 *   @0xbdb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbdb30 mov r0, r5
 *   @0xbdb34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbdb38 mov r0, r4
 *   @0xbdb3c bl 0xb655c <free@plt>
 *   @0xbdb40 mov r0, r6
 *   @0xbdb44 add sp, sp, #16
 *   @0xbdb48 pop {r4, r5, r6, r7, r8, pc}
 *   @0xbdb4c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xbdb50 cmp r0, #0
 *   @0xbdb54 moveq r5, r0
 *   @0xbdb58 moveq r6, r5
 *   @0xbdb5c beq 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c>
 *   @0xbdb60 mov r0, r4
 *   @0xbdb64 add r1, sp, #12
 *   @0xbdb68 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xbdb6c mov r5, r0
 *   @0xbdb70 b 0xbda4c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0xb0>
 *   @0xbdb74 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xbdb78 cmp r0, #0
 *   @0xbdb7c moveq r7, r0
 *   @0xbdb80 beq 0xbda14 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x78>
 *   @0xbdb84 mov r0, r4
 *   @0xbdb88 add r1, sp, #8
 *   @0xbdb8c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xbdb90 mov r7, r0
 *   @0xbdb94 b 0xbda14 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x78>
 *   @0xbdb98 ldr r12, [r6]
 *   @0xbdb9c mov r0, r6
 *   @0xbdba0 ldr r2, [r8]
 *   @0xbdba4 mov r6, r3
 *   @0xbdba8 ldr r1, [pc, #0x2c]
 *   @0xbdbac ldr r3, [r12, #0xc]
 *   @0xbdbb0 add r1, pc, r1
 *   @0xbdbb4 ldr r2, [r2, #0x8]
 *   @0xbdbb8 blx r3
 *   @0xbdbbc b 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c>
 *   @0xbdbc0 eoreq r2, r7, r12, asr sp
 *   @0xbdbc4 eoreq r2, r7, r0, lsr #26
 *   @0xbdbc8 eoreq r1, r7, r6, asr #1
 *   @0xbdbcc mlaseq r2, r4, r12, pc
 *   @0xbdbd0 eoreq r2, r7, r12, asr #25
 *   @0xbdbd4 .word 0x00272cb4
 *   @0xbdbd8 eoreq r2, r7, r12, lsl #25
 *   @0xbdbdc eoreq r2, r7, r12, ror #23
 *
 * ══ §11/54 F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6e20  size 580  145 条（0xc6e20..0xc7064）
 * @func 0xc6e20 0xc7064  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / GetBufferVertex(int) / F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x1f4 / F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b4 / GetVertexFormat(int) / CreateBuffer(int, eBuffer_Format, int) / GetIBuffer(int)
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x1c×2 / 0x28×2 / 0x14×2 / 0x40×1 / 0x20×1 / 0x1d4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6e20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc6e24 sub sp, sp, #28
 *   @0xc6e28 mov r4, #0
 *   @0xc6e2c mov r6, r0
 *   @0xc6e30 ldr r5, [sp, #0x40]
 *   @0xc6e34 mov r1, r4
 *   @0xc6e38 str r4, [r0, #0xc]
 *   @0xc6e3c mov r3, r4
 *   @0xc6e40 str r4, [r0]
 *   @0xc6e44 movt r3, #0xbff0
 *   @0xc6e48 str r3, [r0, #0x4]
 *   @0xc6e4c mov r0, r5
 *   @0xc6e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6e54 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc6e58 subs r7, r0, #0
 *   @0xc6e5c beq 0xc7004 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0xc6e60 ldrb r8, [r7, #0x20]
 *   @0xc6e64 mov r1, r4
 *   @0xc6e68 ldr r0, [pc, #0x1d4]
 *   @0xc6e6c cmp r8, #0
 *   @0xc6e70 add r0, pc, r0
 *   @0xc6e74 bne 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc6e78 ldr r3, [r7, #0x1c]
 *   @0xc6e7c cmp r3, #0
 *   @0xc6e80 beq 0xc6ed8 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc6e84 ldr r3, [r7, #0x28]
 *   @0xc6e88 cmn r3, #1
 *   @0xc6e8c beq 0xc6ed8 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc6e90 mov r0, r5
 *   @0xc6e94 mov r1, #2
 *   @0xc6e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6e9c vmov.f32 s15, #1.000000e+00
 *   @0xc6ea0 vmov s13, r0
 *   @0xc6ea4 mov r4, r0
 *   @0xc6ea8 vcvt.f32.s32 s14, s13
 *   @0xc6eac vcmpe.f32 s14, s15
 *   @0xc6eb0 vmrs APSR_nzcv, fpscr
 *   @0xc6eb4 bmi 0xc6ec0 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0xc6eb8 cmp r0, #1024
 *   @0xc6ebc ble 0xc6ef0 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0xc6ec0 ldr r0, [pc, #0x180]
 *   @0xc6ec4 mov r1, #0
 *   @0xc6ec8 add r0, pc, r0
 *   @0xc6ecc add sp, sp, #28
 *   @0xc6ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc6ed4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6ed8 ldr r0, [pc, #0x16c]
 *   @0xc6edc mov r1, #0
 *   @0xc6ee0 add r0, pc, r0
 *   @0xc6ee4 add sp, sp, #28
 *   @0xc6ee8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc6eec b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6ef0 mov r1, #3
 *   @0xc6ef4 mov r0, r5
 *   @0xc6ef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6efc mov r1, #4
 *   @0xc6f00 mov r9, r0
 *   @0xc6f04 mov r0, r5
 *   @0xc6f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6f0c subs r10, r0, #0
 *   @0xc6f10 ble 0xc7014 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0xc6f14 cmp r9, #0
 *   @0xc6f18 blt 0xc6fd4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0xc6f1c ldr r3, [r7, #0x1c]
 *   @0xc6f20 cmp r9, r3
 *   @0xc6f24 bge 0xc6fd4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0xc6f28 add r2, r9, r10
 *   @0xc6f2c ldr r0, [r7, #0x28]
 *   @0xc6f30 cmp r3, r2
 *   @0xc6f34 rsblt r10, r9, r3
 *   @0xc6f38 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc6f3c subs r8, r0, #0
 *   @0xc6f40 beq 0xc7024 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0xc6f44 mov r0, r5
 *   @0xc6f48 mov r1, #1
 *   @0xc6f4c ldr r11, [r8, #0x14]
 *   @0xc6f50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6f54 mov r2, r4
 *   @0xc6f58 mul r11, r11, r10
 *   @0xc6f5c mov r1, r0
 *   @0xc6f60 mov r0, r11
 *   @0xc6f64 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0xc6f68 vmov s15, r0
 *   @0xc6f6c vcvt.f64.s32 d7, s15
 *   @0xc6f70 vmov r4, r5, d7
 *   @0xc6f74 vmov r2, s14
 *   @0xc6f78 mov r3, r5
 *   @0xc6f7c stm r6, {r2, r3}
 *   @0xc6f80 bl 0xc6720 <_Z10GetIBufferi>
 *   @0xc6f84 subs r6, r0, #0
 *   @0xc6f88 beq 0xc7034 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0xc6f8c ldr r12, [r8, #0x14]
 *   @0xc6f90 mov r4, #0
 *   @0xc6f94 ldr r1, [r7]
 *   @0xc6f98 mov r2, r11
 *   @0xc6f9c mov r3, r4
 *   @0xc6fa0 str r4, [sp, #0x4]
 *   @0xc6fa4 str r4, [sp, #0x8]
 *   @0xc6fa8 mvn r5, #0
 *   @0xc6fac mla r1, r12, r9, r1
 *   @0xc6fb0 str r4, [sp, #0xc]
 *   @0xc6fb4 str r4, [sp, #0x10]
 *   @0xc6fb8 str r5, [sp]
 *   @0xc6fbc bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xc6fc0 bl 0x212e98 <_Z11IsBigEndianv>
 *   @0xc6fc4 cmp r0, r4
 *   @0xc6fc8 bne 0xc6fe4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0xc6fcc add sp, sp, #28
 *   @0xc6fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc6fd4 ldr r0, [pc, #0x74]
 *   @0xc6fd8 mov r1, #0
 *   @0xc6fdc add r0, pc, r0
 *   @0xc6fe0 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc6fe4 ldr r1, [r6, #0xc]
 *   @0xc6fe8 mov r0, r8
 *   @0xc6fec str r5, [sp]
 *   @0xc6ff0 mov r2, r10
 *   @0xc6ff4 str r4, [sp, #0x4]
 *   @0xc6ff8 mov r3, r4
 *   @0xc6ffc bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib>
 *   @0xc7000 b 0xc6fcc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0xc7004 ldr r0, [pc, #0x48]
 *   @0xc7008 mov r1, r7
 *   @0xc700c add r0, pc, r0
 *   @0xc7010 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc7014 ldr r0, [pc, #0x3c]
 *   @0xc7018 mov r1, r8
 *   @0xc701c add r0, pc, r0
 *   @0xc7020 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc7024 ldr r0, [pc, #0x30]
 *   @0xc7028 mov r1, r8
 *   @0xc702c add r0, pc, r0
 *   @0xc7030 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc7034 ldr r0, [pc, #0x24]
 *   @0xc7038 mov r1, r6
 *   @0xc703c add r0, pc, r0
 *   @0xc7040 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc7044 eoreq r10, r6, r8, ror r4
 *   @0xc7048 eoreq r10, r6, r12, asr #9
 *   @0xc704c eoreq r10, r6, r0, ror #8
 *   @0xc7050 eoreq r10, r6, r4, asr #8
 *   @0xc7054 eoreq r10, r6, r12, lsl #5
 *   @0xc7058 .word 0x0026a3b8
 *   @0xc705c eoreq r10, r6, r0, asr #8
 *   @0xc7060 eoreq r10, r6, r12, lsl r2
 *
 * ══ §12/54 F_DrawBackgroundPartExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11df24  size 580  145 条（0x11df24..0x11e168）
 * @func 0x11df24 0x11e168  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×18 / YYGetInt32(RValue const*, int)×4 / Sprite_Data(int) / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawPart(float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x24×4 / 0x28×4 / 0x2c×4 / 0x14×3 / 0x4×2 / 0x8×2 / 0xc×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11df24 ldr r3, [pc, #0x234]
 *   @0x11df28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11df2c ldr r3, [pc, r3]
 *   @0x11df30 sub sp, sp, #52
 *   @0x11df34 ldrb r1, [r3]
 *   @0x11df38 ldr r4, [sp, #0x58]
 *   @0x11df3c cmp r1, #0
 *   @0x11df40 mov r0, r4
 *   @0x11df44 beq 0x11e04c <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x11df48 mov r1, #0
 *   @0x11df4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11df50 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11df54 subs r5, r0, #0
 *   @0x11df58 beq 0x11e148 <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x11df5c mov r0, r4
 *   @0x11df60 mov r1, #1
 *   @0x11df64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11df68 mov r1, #2
 *   @0x11df6c mov r7, r0
 *   @0x11df70 mov r0, r4
 *   @0x11df74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11df78 mov r1, #3
 *   @0x11df7c mov r6, r0
 *   @0x11df80 mov r0, r4
 *   @0x11df84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11df88 mov r1, #4
 *   @0x11df8c mov r12, r0
 *   @0x11df90 mov r0, r4
 *   @0x11df94 str r12, [sp, #0x24]
 *   @0x11df98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11df9c mov r1, #5
 *   @0x11dfa0 mov r2, r0
 *   @0x11dfa4 mov r0, r4
 *   @0x11dfa8 str r2, [sp, #0x28]
 *   @0x11dfac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11dfb0 mov r1, #6
 *   @0x11dfb4 mov r3, r0
 *   @0x11dfb8 mov r0, r4
 *   @0x11dfbc str r3, [sp, #0x2c]
 *   @0x11dfc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11dfc4 mov r1, #7
 *   @0x11dfc8 mov r11, r0
 *   @0x11dfcc mov r0, r4
 *   @0x11dfd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11dfd4 mov r1, #8
 *   @0x11dfd8 mov r10, r0
 *   @0x11dfdc mov r0, r4
 *   @0x11dfe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11dfe4 mov r1, #9
 *   @0x11dfe8 mov r9, r0
 *   @0x11dfec mov r0, r4
 *   @0x11dff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11dff4 mov r1, #10
 *   @0x11dff8 mov r8, r0
 *   @0x11dffc mov r0, r4
 *   @0x11e000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e004 ldr r2, [sp, #0x28]
 *   @0x11e008 ldr r3, [sp, #0x2c]
 *   @0x11e00c mov r1, #0
 *   @0x11e010 ldr r12, [sp, #0x24]
 *   @0x11e014 str r2, [sp, #0x4]
 *   @0x11e018 mov r2, r7
 *   @0x11e01c str r3, [sp, #0x8]
 *   @0x11e020 mov r3, r6
 *   @0x11e024 str r12, [sp]
 *   @0x11e028 str r11, [sp, #0xc]
 *   @0x11e02c str r10, [sp, #0x10]
 *   @0x11e030 str r9, [sp, #0x14]
 *   @0x11e034 str r8, [sp, #0x18]
 *   @0x11e038 str r0, [sp, #0x1c]
 *   @0x11e03c mov r0, r5
 *   @0x11e040 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x11e044 add sp, sp, #52
 *   @0x11e048 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11e04c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e050 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11e054 subs r5, r0, #0
 *   @0x11e058 beq 0x11e148 <_Z23F_DrawBackgroundPartExtR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x11e05c mov r0, r4
 *   @0x11e060 mov r1, #1
 *   @0x11e064 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e068 mov r1, #2
 *   @0x11e06c mov r8, r0
 *   @0x11e070 mov r0, r4
 *   @0x11e074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e078 mov r1, #3
 *   @0x11e07c mov r7, r0
 *   @0x11e080 mov r0, r4
 *   @0x11e084 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e088 mov r1, #4
 *   @0x11e08c mov r6, r0
 *   @0x11e090 mov r0, r4
 *   @0x11e094 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e098 mov r1, #5
 *   @0x11e09c mov r12, r0
 *   @0x11e0a0 mov r0, r4
 *   @0x11e0a4 str r12, [sp, #0x24]
 *   @0x11e0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e0ac mov r1, #6
 *   @0x11e0b0 mov r2, r0
 *   @0x11e0b4 mov r0, r4
 *   @0x11e0b8 str r2, [sp, #0x28]
 *   @0x11e0bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e0c0 mov r1, #7
 *   @0x11e0c4 mov r3, r0
 *   @0x11e0c8 mov r0, r4
 *   @0x11e0cc str r3, [sp, #0x2c]
 *   @0x11e0d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e0d4 mov r1, #8
 *   @0x11e0d8 mov r11, r0
 *   @0x11e0dc mov r0, r4
 *   @0x11e0e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e0e4 mov r1, #9
 *   @0x11e0e8 mov r10, r0
 *   @0x11e0ec mov r0, r4
 *   @0x11e0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e0f4 mov r1, #10
 *   @0x11e0f8 mov r9, r0
 *   @0x11e0fc mov r0, r4
 *   @0x11e100 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e104 ldr r2, [sp, #0x28]
 *   @0x11e108 ldr r3, [sp, #0x2c]
 *   @0x11e10c mov r1, r8
 *   @0x11e110 ldr r12, [sp, #0x24]
 *   @0x11e114 str r2, [sp, #0x4]
 *   @0x11e118 mov r2, r7
 *   @0x11e11c str r3, [sp, #0x8]
 *   @0x11e120 mov r3, r6
 *   @0x11e124 str r12, [sp]
 *   @0x11e128 str r11, [sp, #0xc]
 *   @0x11e12c str r10, [sp, #0x10]
 *   @0x11e130 str r9, [sp, #0x14]
 *   @0x11e134 str r0, [sp, #0x18]
 *   @0x11e138 mov r0, r5
 *   @0x11e13c bl 0xc2184 <_ZN11CBackground8DrawPartEffffffffjf>
 *   @0x11e140 add sp, sp, #52
 *   @0x11e144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11e148 ldr r0, [pc, #0x14]
 *   @0x11e14c mov r1, #0
 *   @0x11e150 add r0, pc, r0
 *   @0x11e154 add sp, sp, #52
 *   @0x11e158 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11e15c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e160 .word 0x002cf9f8
 *   @0x11e164 eoreq r12, r1, r4, lsl #1
 *
 * ══ §13/54 YYGML_draw_rectangle(float, float, float, float, bool)  0x16aa1c  size 580  145 条（0x16aa1c..0x16ac60）
 * @func 0x16aa1c 0x16ac60  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16aa44→0x3f23d0, 0x16aa48→0x4859c0, 0x16aa9c→0x3f23d8, 0x16aaa0→0x3f23d4, 0x16aaa4→0x4859ac, 0x16ab4c→0x3f23d8, 0x16ab50→0x3f23d4, 0x16ab74→0x4859ac
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)×3
 * 字段偏移 top8: 0x20×4 / 0x1b0×3 / 0xc×3 / 0x38×3 / 0x50×3 / 0x8×3 / 0x24×3 / 0x3c×3
 * VFP 指令 60 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16aa1c push {r4, r5, r6, lr}
 *   @0x16aa20 vpush {d8, d9}
 *   @0x16aa24 vmov s19, r2
 *   @0x16aa28 vmov s16, r0
 *   @0x16aa2c ldr r5, [pc, #0x214]
 *   @0x16aa30 vmov s17, r1
 *   @0x16aa34 ldrb r2, [sp, #0x20]
 *   @0x16aa38 vcmpe.f32 s19, s16
 *   @0x16aa3c add r5, pc, r5
 *   @0x16aa40 vmov s18, r3
 *   @0x16aa44 ldr r3, [pc, #0x200]
 *   @0x16aa48 ldr r1, [pc, #0x200]
 *   @0x16aa4c vmrs APSR_nzcv, fpscr
 *   @0x16aa50 vcmpe.f32 s18, s17
 *   @0x16aa54 ldr r3, [r5, r3]
 *   @0x16aa58 vmovmi.f32 s15, s16
 *   @0x16aa5c ldr r4, [r3]
 *   @0x16aa60 vmovmi.f32 s16, s19
 *   @0x16aa64 vmovmi.f32 s19, s15
 *   @0x16aa68 vmrs APSR_nzcv, fpscr
 *   @0x16aa6c vmovmi.f32 s15, s17
 *   @0x16aa70 vmovmi.f32 s17, s18
 *   @0x16aa74 vmovmi.f32 s18, s15
 *   @0x16aa78 cmp r2, #0
 *   @0x16aa7c bne 0x16ab30 <_Z20YYGML_draw_rectangleffffb+0x114>
 *   @0x16aa80 ldr r1, [r5, r1]
 *   @0x16aa84 mov r2, #24
 *   @0x16aa88 mov r3, #6
 *   @0x16aa8c mov r0, #4
 *   @0x16aa90 ldr r1, [r1]
 *   @0x16aa94 ldr r1, [r1]
 *   @0x16aa98 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16aa9c ldr r1, [pc, #0x1b0]
 *   @0x16aaa0 ldr r2, [pc, #0x1b0]
 *   @0x16aaa4 ldr r3, [pc, #0x1b0]
 *   @0x16aaa8 ldr r1, [r5, r1]
 *   @0x16aaac vldr s15, [r1]
 *   @0x16aab0 ldr r2, [r5, r2]
 *   @0x16aab4 vadd.f32 s19, s19, s15
 *   @0x16aab8 vldr s15, [r2]
 *   @0x16aabc ldr r3, [r5, r3]
 *   @0x16aac0 ldr r3, [r3]
 *   @0x16aac4 vadd.f32 s18, s18, s15
 *   @0x16aac8 vstr s17, [r0, #4]
 *   @0x16aacc vstr s17, [r0, #28]
 *   @0x16aad0 vstr s16, [r0, #96]
 *   @0x16aad4 vstr s19, [r0, #24]
 *   @0x16aad8 vstr s19, [r0, #48]
 *   @0x16aadc vstr s19, [r0, #72]
 *   @0x16aae0 vstr s16, [r0, #120]
 *   @0x16aae4 vstr s17, [r0, #124]
 *   @0x16aae8 vstr s16, [r0]
 *   @0x16aaec vstr s18, [r0, #52]
 *   @0x16aaf0 vstr s18, [r0, #76]
 *   @0x16aaf4 vstr s18, [r0, #100]
 *   @0x16aaf8 vpop {d8, d9}
 *   @0x16aafc str r4, [r0, #0xc]
 *   @0x16ab00 str r4, [r0, #0x6c]
 *   @0x16ab04 str r3, [r0, #0x20]
 *   @0x16ab08 str r3, [r0, #0x38]
 *   @0x16ab0c str r3, [r0, #0x50]
 *   @0x16ab10 str r3, [r0, #0x8]
 *   @0x16ab14 str r3, [r0, #0x68]
 *   @0x16ab18 str r3, [r0, #0x80]
 *   @0x16ab1c str r4, [r0, #0x24]
 *   @0x16ab20 str r4, [r0, #0x3c]
 *   @0x16ab24 str r4, [r0, #0x54]
 *   @0x16ab28 str r4, [r0, #0x84]
 *   @0x16ab2c pop {r4, r5, r6, pc}
 *   @0x16ab30 ldr r6, [r5, r1]
 *   @0x16ab34 mov r2, #24
 *   @0x16ab38 mov r3, #5
 *   @0x16ab3c mov r0, #3
 *   @0x16ab40 ldr r1, [r6]
 *   @0x16ab44 ldr r1, [r1]
 *   @0x16ab48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16ab4c ldr lr, [pc, #0x100]
 *   @0x16ab50 ldr r1, [pc, #0x100]
 *   @0x16ab54 vldr s15, [pc, #232]
 *   @0x16ab58 ldr r3, [r6]
 *   @0x16ab5c mov r2, #24
 *   @0x16ab60 ldr lr, [r5, lr]
 *   @0x16ab64 vldr s14, [lr]
 *   @0x16ab68 ldr r1, [r5, r1]
 *   @0x16ab6c vmul.f32 s14, s14, s15
 *   @0x16ab70 vldr s13, [r1]
 *   @0x16ab74 ldr lr, [pc, #0xe0]
 *   @0x16ab78 ldr r1, [r3]
 *   @0x16ab7c mov r3, #4
 *   @0x16ab80 ldr r5, [r5, lr]
 *   @0x16ab84 ldr lr, [r5]
 *   @0x16ab88 vmul.f32 s15, s13, s15
 *   @0x16ab8c vadd.f32 s16, s14, s16
 *   @0x16ab90 mov r12, r0
 *   @0x16ab94 mov r0, #1
 *   @0x16ab98 str r4, [r12, #0xc]
 *   @0x16ab9c str lr, [r12, #0x20]
 *   @0x16aba0 str r4, [r12, #0x6c]
 *   @0x16aba4 str lr, [r12, #0x38]
 *   @0x16aba8 str r4, [r12, #0x24]
 *   @0x16abac vadd.f32 s17, s15, s17
 *   @0x16abb0 vstr s16, [r12, #96]
 *   @0x16abb4 vstr s16, [r12, #72]
 *   @0x16abb8 vstr s16, [r12]
 *   @0x16abbc str lr, [r12, #0x50]
 *   @0x16abc0 str r4, [r12, #0x3c]
 *   @0x16abc4 str lr, [r12, #0x8]
 *   @0x16abc8 str r4, [r12, #0x54]
 *   @0x16abcc str lr, [r12, #0x68]
 *   @0x16abd0 vadd.f32 s19, s19, s14
 *   @0x16abd4 vstr s17, [r12, #4]
 *   @0x16abd8 vstr s17, [r12, #100]
 *   @0x16abdc vstr s17, [r12, #28]
 *   @0x16abe0 vadd.f32 s18, s18, s15
 *   @0x16abe4 vstr s19, [r12, #24]
 *   @0x16abe8 vstr s19, [r12, #48]
 *   @0x16abec vstr s18, [r12, #52]
 *   @0x16abf0 vstr s18, [r12, #76]
 *   @0x16abf4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16abf8 ldr r3, [r5]
 *   @0x16abfc vstr s17, [r0, #4]
 *   @0x16ac00 vstr s16, [r0]
 *   @0x16ac04 vstr s19, [r0, #24]
 *   @0x16ac08 vstr s17, [r0, #28]
 *   @0x16ac0c vstr s19, [r0, #48]
 *   @0x16ac10 vstr s18, [r0, #52]
 *   @0x16ac14 vstr s16, [r0, #72]
 *   @0x16ac18 vstr s18, [r0, #76]
 *   @0x16ac1c vpop {d8, d9}
 *   @0x16ac20 str r3, [r0, #0x20]
 *   @0x16ac24 str r3, [r0, #0x38]
 *   @0x16ac28 str r3, [r0, #0x50]
 *   @0x16ac2c str r3, [r0, #0x8]
 *   @0x16ac30 str r4, [r0, #0xc]
 *   @0x16ac34 str r4, [r0, #0x24]
 *   @0x16ac38 str r4, [r0, #0x3c]
 *   @0x16ac3c str r4, [r0, #0x54]
 *   @0x16ac40 pop {r4, r5, r6, pc}
 *   @0x16ac44 stclo p7, c13, [r3], #-40
 *   @0x16ac48 eoreq r7, r8, r4, lsl r2
 *   @0x16ac4c .word 0xffffc0ac
 *   @0x16ac50 .word 0xffffe4e0
 *   @0x16ac54 .word 0xffffe524
 *   @0x16ac58 .word 0xffffe520
 *   @0x16ac5c .word 0xffffbcd0
 *
 * ══ §14/54 FINALIZE_Score()  0x1dc3bc  size 580  145 条（0x1dc3bc..0x1dc600）
 * @func 0x1dc3bc 0x1dc600  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dc3d4→0x544b18, 0x1dc41c→0x3f51d8, 0x1dc4bc→0x544ab4
 * 调用序列: 0xb68bc×9 / 0xb68e0×2 / LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / 0xb6844 / 0xb6538 / FINALIZE_Score()+0x190 / 0xb68d4
 * 字段偏移 top8: 0x20×4 / 0x424×2 / 0x4×2 / 0x1c×2 / 0xc×2 / 0x-4×2 / 0x21c×1 / 0x218×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc3bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dc3c0 sub sp, sp, #1056
 *   @0x1dc3c4 ldr r5, [pc, #0x21c]
 *   @0x1dc3c8 sub sp, sp, #12
 *   @0x1dc3cc ldr r2, [pc, #0x218]
 *   @0x1dc3d0 add r5, pc, r5
 *   @0x1dc3d4 ldr r3, [pc, #0x214]
 *   @0x1dc3d8 ldr r2, [r5, r2]
 *   @0x1dc3dc str r2, [sp]
 *   @0x1dc3e0 ldr r2, [r2]
 *   @0x1dc3e4 str r2, [sp, #0x424]
 *   @0x1dc3e8 ldr r3, [r5, r3]
 *   @0x1dc3ec str r3, [sp, #0x4]
 *   @0x1dc3f0 ldrb r3, [r3]
 *   @0x1dc3f4 cmp r3, #0
 *   @0x1dc3f8 bne 0x1dc41c <_Z14FINALIZE_Scorev+0x60>
 *   @0x1dc3fc ldr r1, [sp]
 *   @0x1dc400 ldr r2, [sp, #0x424]
 *   @0x1dc404 ldr r3, [r1]
 *   @0x1dc408 cmp r2, r3
 *   @0x1dc40c bne 0x1dc5e4 <_Z14FINALIZE_Scorev+0x228>
 *   @0x1dc410 add sp, sp, #1056
 *   @0x1dc414 add sp, sp, #12
 *   @0x1dc418 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dc41c ldr r3, [pc, #0x1d0]
 *   @0x1dc420 add r4, sp, #36
 *   @0x1dc424 mov r1, #1024
 *   @0x1dc428 add r11, sp, #40
 *   @0x1dc42c mov r0, r4
 *   @0x1dc430 ldr r3, [r5, r3]
 *   @0x1dc434 ldr r2, [r3]
 *   @0x1dc438 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1dc43c mov r0, r4
 *   @0x1dc440 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x1dc444 ldr r1, [pc, #0x1ac]
 *   @0x1dc448 mov r0, r4
 *   @0x1dc44c add r1, pc, r1
 *   @0x1dc450 bl 0xb6844 <fopen@plt>
 *   @0x1dc454 subs r4, r0, #0
 *   @0x1dc458 beq 0x1dc5a4 <_Z14FINALIZE_Scorev+0x1e8>
 *   @0x1dc45c add r0, sp, #1056
 *   @0x1dc460 mov r1, #4
 *   @0x1dc464 add r0, r0, #8
 *   @0x1dc468 mov r2, #1
 *   @0x1dc46c movw r3, #0x4948
 *   @0x1dc470 movt r3, #0x4353
 *   @0x1dc474 str r3, [r0, #-0x410]!
 *   @0x1dc478 mov r3, r4
 *   @0x1dc47c sub r11, r11, #12
 *   @0x1dc480 str r11, [sp, #0x8]
 *   @0x1dc484 bl 0xb68bc <fwrite@plt>
 *   @0x1dc488 mov r0, r4
 *   @0x1dc48c bl 0xb68e0 <ftell@plt>
 *   @0x1dc490 mov r3, r4
 *   @0x1dc494 mov r1, #4
 *   @0x1dc498 mov r2, #1
 *   @0x1dc49c mov r12, #0
 *   @0x1dc4a0 str r12, [sp, #0x1c]
 *   @0x1dc4a4 add r9, sp, #32
 *   @0x1dc4a8 add r7, sp, #23
 *   @0x1dc4ac mvn r6, #15
 *   @0x1dc4b0 str r0, [sp, #0xc]
 *   @0x1dc4b4 add r0, sp, #28
 *   @0x1dc4b8 bl 0xb68bc <fwrite@plt>
 *   @0x1dc4bc ldr r3, [pc, #0x138]
 *   @0x1dc4c0 ldr r10, [r5, r3]
 *   @0x1dc4c4 add r8, r10, #4
 *   @0x1dc4c8 add r10, r10, #84
 *   @0x1dc4cc ldr r12, [r8, #-0x4]
 *   @0x1dc4d0 cmp r12, #0
 *   @0x1dc4d4 beq 0x1dc5b4 <_Z14FINALIZE_Scorev+0x1f8>
 *   @0x1dc4d8 mov r0, r12
 *   @0x1dc4dc bl 0xb6538 <strlen@plt>
 *   @0x1dc4e0 mov r1, #1
 *   @0x1dc4e4 mov r2, #4
 *   @0x1dc4e8 mov r3, r4
 *   @0x1dc4ec str r0, [sp, #0x20]
 *   @0x1dc4f0 mov r0, r9
 *   @0x1dc4f4 bl 0xb68bc <fwrite@plt>
 *   @0x1dc4f8 mov r3, r4
 *   @0x1dc4fc ldr r0, [r8, #-0x4]
 *   @0x1dc500 mov r1, #1
 *   @0x1dc504 ldr r2, [sp, #0x20]
 *   @0x1dc508 bl 0xb68bc <fwrite@plt>
 *   @0x1dc50c ldr r3, [sp, #0x20]
 *   @0x1dc510 add r11, r3, #3
 *   @0x1dc514 bic r11, r11, #3
 *   @0x1dc518 rsb r11, r3, r11
 *   @0x1dc51c cmp r11, #0
 *   @0x1dc520 movgt r5, #0
 *   @0x1dc524 ble 0x1dc54c <_Z14FINALIZE_Scorev+0x190>
 *   @0x1dc528 mov r1, #1
 *   @0x1dc52c mov r0, r7
 *   @0x1dc530 add r5, r5, r1
 *   @0x1dc534 mov r2, r1
 *   @0x1dc538 mov r3, r4
 *   @0x1dc53c strb r6, [sp, #0x17]
 *   @0x1dc540 bl 0xb68bc <fwrite@plt>
 *   @0x1dc544 cmp r5, r11
 *   @0x1dc548 bne 0x1dc528 <_Z14FINALIZE_Scorev+0x16c>
 *   @0x1dc54c mov r0, r8
 *   @0x1dc550 mov r1, #4
 *   @0x1dc554 mov r2, #1
 *   @0x1dc558 mov r3, r4
 *   @0x1dc55c bl 0xb68bc <fwrite@plt>
 *   @0x1dc560 add r8, r8, #8
 *   @0x1dc564 cmp r8, r10
 *   @0x1dc568 bne 0x1dc4cc <_Z14FINALIZE_Scorev+0x110>
 *   @0x1dc56c mov r0, r4
 *   @0x1dc570 bl 0xb68e0 <ftell@plt>
 *   @0x1dc574 ldr r1, [sp, #0xc]
 *   @0x1dc578 mov r2, #0
 *   @0x1dc57c str r0, [sp, #0x1c]
 *   @0x1dc580 mov r0, r4
 *   @0x1dc584 bl 0xb68d4 <fseek@plt>
 *   @0x1dc588 add r0, sp, #28
 *   @0x1dc58c mov r1, #4
 *   @0x1dc590 mov r2, #1
 *   @0x1dc594 mov r3, r4
 *   @0x1dc598 bl 0xb68bc <fwrite@plt>
 *   @0x1dc59c mov r0, r4
 *   @0x1dc5a0 bl 0xb6850 <fclose@plt>
 *   @0x1dc5a4 ldr r1, [sp, #0x4]
 *   @0x1dc5a8 mov r3, #0
 *   @0x1dc5ac strb r3, [r1]
 *   @0x1dc5b0 b 0x1dc3fc <_Z14FINALIZE_Scorev+0x40>
 *   @0x1dc5b4 mov r3, r4
 *   @0x1dc5b8 mov r0, r9
 *   @0x1dc5bc mov r1, #4
 *   @0x1dc5c0 mov r2, #1
 *   @0x1dc5c4 str r12, [sp, #0x20]
 *   @0x1dc5c8 bl 0xb68bc <fwrite@plt>
 *   @0x1dc5cc mov r0, r9
 *   @0x1dc5d0 mov r1, #4
 *   @0x1dc5d4 mov r2, #1
 *   @0x1dc5d8 mov r3, r4
 *   @0x1dc5dc bl 0xb68bc <fwrite@plt>
 *   @0x1dc5e0 b 0x1dc560 <_Z14FINALIZE_Scorev+0x1a4>
 *   @0x1dc5e4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dc5e8 eoreq r5, r1, r0, lsl #17
 *   @0x1dc5ec .word 0xffffbd00
 *   @0x1dc5f0 .word 0xfffff044
 *   @0x1dc5f4 .word 0xfffff048
 *   @0x1dc5f8 ldrsheq r3, [r6], -r8
 *   @0x1dc5fc .word 0xfffff03c
 *
 * ══ §15/54 Texture_Load(unsigned char*, unsigned int, unsigned char*)  0x1dda28  size 580  138 条（0x1dda28..0x1ddc6c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1dda28 0x1ddc6c  size 580  138 条
 * 部分覆盖: 本节 138/145 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dda54→0x544bc8, 0x1dda68→0x5428e8, 0x1dda8c→0x544c44, 0x1ddab4→0x544c44, 0x1ddae4→0x48ffec, 0x1ddb54→0x544c44, 0x1ddb78→0x544c44, 0x1ddba8→0x544bc4
 * 调用序列: Texture_Load(unsigned char*, unsigned int, unsigned char*)+0x180×2 / GR_Texture_Create(unsigned char*, unsigned int, bool, bool)×2 / operator new[](unsigned int) / Texture_Load(unsigned char*, unsigned int, unsigned char*)+0x1fc
 * 字段偏移 top8: 0x4×7 / 0x2×3 / 0x10×2 / 0xc×2 / 0x208×1 / 0x1f4×1 / 0x1e4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dda28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dda2c mov r5, r0
 *   @0x1dda30 ldr r8, [r0]
 *   @0x1dda34 sub sp, sp, #12
 *   @0x1dda38 mov r11, r1
 *   @0x1dda3c ldr r7, [pc, #0x208]
 *   @0x1dda40 cmp r8, #532676608
 *   @0x1dda44 lslls r0, r8, #2
 *   @0x1dda48 add r7, pc, r7
 *   @0x1dda4c mvnhi r0, #0
 *   @0x1dda50 bl 0x27d14c <_Znaj>
 *   @0x1dda54 ldr r3, [pc, #0x1f4]
 *   @0x1dda58 cmp r8, #0
 *   @0x1dda5c ldr r9, [r7, r3]
 *   @0x1dda7c str r3, [sp, #0x4]
 *   @0x1dda80 b 0x1ddb3c <_Z12Texture_LoadPhjS_+0x114>
 *   @0x1dda84 ldr r2, [r5, #0x4]
 *   @0x1dda88 cmp r2, #0
 *   @0x1dda8c ldrne r3, [pc, #0x1c4]
 *   @0x1dda90 ldrne r3, [r7, r3]
 *   @0x1dda94 ldrne r3, [r3]
 *   @0x1dda98 addne r2, r3, r2
 *   @0x1dda9c ldr r0, [r2, #0x8]
 *   @0x1ddaa0 add r12, r12, r4
 *   @0x1ddaa4 ldr r3, [r2]
 *   @0x1ddaa8 cmp r0, #0
 *   @0x1ddaac ldr r10, [r2, #0x4]
 *   @0x1ddab0 and r3, r3, #1
 *   @0x1ddab4 ldrne r2, [pc, #0x19c]
 *   @0x1ddab8 ldrne r2, [r7, r2]
 *   @0x1ddabc ldrne r2, [r2]
 *   @0x1ddac0 addne r0, r2, r0
 *   @0x1ddac4 mov r1, r11
 *   @0x1ddac8 mov r2, #0
 *   @0x1ddacc str r12, [sp]
 *   @0x1ddad0 bl 0x173cdc <_Z17GR_Texture_CreatePhjbb>
 *   @0x1ddad4 ldr r12, [sp]
 *   @0x1ddad8 cmp r10, #0
 *   @0x1ddadc str r0, [r12]
 *   @0x1ddae0 beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178>
 *   @0x1ddae4 ldr r3, [pc, #0x170]
 *   @0x1ddae8 ldr r2, [r9]
 *   @0x1ddaec ldr r3, [r7, r3]
 *   @0x1ddaf0 ldr r2, [r2, r4]
 *   @0x1ddaf4 ldr r3, [r3, #0x4]
 *   @0x1ddaf8 ldr r3, [r3, r2, lsl #2]
 *   @0x1ddafc cmp r3, #0
 *   @0x1ddb00 beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178>
 *   @0x1ddb04 ldr r2, [r3]
 *   @0x1ddb08 cmp r2, #0
 *   @0x1ddb0c beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178>
 *   @0x1ddb10 ldr r1, [r2, #0x10]
 *   @0x1ddb14 mov r3, r6
 *   @0x1ddb18 str r10, [r2, #0xc]
 *   @0x1ddb1c orr r1, r1, #16
 *   @0x1ddb20 str r1, [r2, #0x10]
 *   @0x1ddb24 cmp r8, r3
 *   @0x1ddb28 add r6, r6, #1
 *   @0x1ddb2c add r4, r4, #4
 *   @0x1ddb30 add r5, r5, #4
 *   @0x1ddb34 ble 0x1ddba8 <_Z12Texture_LoadPhjS_+0x180>
 *   @0x1ddb38 ldr r12, [r9]
 *   @0x1ddb3c ldr r2, [sp, #0x4]
 *   @0x1ddb40 ldrb r3, [r2]
 *   @0x1ddb44 cmp r3, #0
 *   @0x1ddb48 bne 0x1dda84 <_Z12Texture_LoadPhjS_+0x5c>
 *   @0x1ddb4c ldr r3, [r5, #0x4]
 *   @0x1ddb50 cmp r3, #0
 *   @0x1ddb54 ldrne r2, [pc, #0xfc]
 *   @0x1ddb58 ldrne r2, [r7, r2]
 *   @0x1ddb5c ldrne r2, [r2]
 *   @0x1ddb60 addne r3, r2, r3
 *   @0x1ddb64 ldr r0, [r3, #0x4]
 *   @0x1ddb68 add r10, r12, r4
 *   @0x1ddb6c ldr r3, [r3]
 *   @0x1ddb70 cmp r0, #0
 *   @0x1ddb74 and r3, r3, #1
 *   @0x1ddb78 ldrne r2, [pc, #0xd8]
 *   @0x1ddb7c ldrne r2, [r7, r2]
 *   @0x1ddb80 ldrne r2, [r2]
 *   @0x1ddb84 addne r0, r2, r0
 *   @0x1ddb88 mov r1, r11
 *   @0x1ddb8c mov r2, #0
 *   @0x1ddb90 bl 0x173cdc <_Z17GR_Texture_CreatePhjbb>
 *   @0x1ddb94 mov r3, r6
 *   @0x1ddb98 str r0, [r10]
 *   @0x1ddb9c b 0x1ddb24 <_Z12Texture_LoadPhjS_+0xfc>
 *   @0x1ddba0 mov r3, r6
 *   @0x1ddba4 b 0x1ddb24 <_Z12Texture_LoadPhjS_+0xfc>
 *   @0x1ddba8 ldr r3, [pc, #0xb0]
 *   @0x1ddbac mov r4, #0
 *   @0x1ddbb0 ldr r6, [pc, #0xac]
 *   @0x1ddbb4 ldr r5, [r7, r3]
 *   @0x1ddbb8 add r6, pc, r6
 *   @0x1ddbbc ldr r3, [r5]
 *   @0x1ddbc0 ldr r10, [r3]
 *   @0x1ddbc4 cmp r10, #0
 *   @0x1ddbc8 bne 0x1ddbe8 <_Z12Texture_LoadPhjS_+0x1c0>
 *   @0x1ddbcc b 0x1ddc40 <_Z12Texture_LoadPhjS_+0x218>
 *   @0x1ddbd0 ldr r1, [r9]
 *   @0x1ddbd4 cmp r4, r10
 *   @0x1ddbd8 ldr r3, [r1, r3, lsl #2]
 *   @0x1ddbdc strh r3, [r2, #20]
 *   @0x1ddbe0 beq 0x1ddc40 <_Z12Texture_LoadPhjS_+0x218>
 *   @0x1ddbe4 ldr r3, [r5]
 *   @0x1ddbe8 add r4, r4, #1
 *   @0x1ddbec ldr r1, [pc, #0x64]
 *   @0x1ddbf0 ldr r0, [pc, #0x70]
 *   @0x1ddbf4 ldr r3, [r3, r4, lsl #2]
 *   @0x1ddbf8 cmp r3, #0
 *   @0x1ddbfc mov r2, r3
 *   @0x1ddc00 ldrne r2, [r7, r1]
 *   @0x1ddc04 mov r1, r6
 *   @0x1ddc08 ldrne r2, [r2]
 *   @0x1ddc0c addne r2, r2, r3
 *   @0x1ddc10 ldrsh r3, [r2, #20]
 *   @0x1ddc14 cmp r3, #0
 *   @0x1ddc18 blt 0x1ddc24 <_Z12Texture_LoadPhjS_+0x1fc>
 *   @0x1ddc1c cmp r8, r3
 *   @0x1ddc20 bgt 0x1ddbd0 <_Z12Texture_LoadPhjS_+0x1a8>
 *   @0x1ddc24 ldr r3, [r7, r0]
 *   @0x1ddc28 ldr r0, [r3]
 *   @0x1ddc2c ldr r3, [r0]
 *   @0x1ddc30 ldr r3, [r3, #0xc]
 *   @0x1ddc34 blx r3
 *   @0x1ddc38 cmp r4, r10
 *   @0x1ddc3c bne 0x1ddbe4 <_Z12Texture_LoadPhjS_+0x1bc>
 *   @0x1ddc40 mov r0, #1
 *   @0x1ddc44 add sp, sp, #12
 *   @0x1ddc48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ddc4c eoreq r4, r1, r8, lsl #4
 *   @0x1ddc50 .word 0xfffff090
 *   @0x1ddc54 .word 0xffffbcd4
 *   @0x1ddc58 .word 0xffffbcf4
 *   @0x1ddc5c .word 0xffffbccc
 *   @0x1ddc60 .word 0xfffff094
 *   @0x1ddc64 andseq r3, r7, r8, ror #23
 *   @0x1ddc68 .word 0xffffbac4
 *
 * ══ §16/54 anon_23cea8  0x23cea8  size 580  145 条（0x23cea8..0x23d0ec）
 * @func 0x23cea8 0x23d0ec  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_23cea4+0x178×2 / 0xb65b0 / anon_23cea4+0xcc / anon_23cea4+0x138 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x-30×2 / 0x-28×2 / 0x2×2 / 0x1×2 / 0x22c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23ceac mov r5, r3
 *   @0x23ceb0 add r11, sp, #32
 *   @0x23ceb4 ldr r8, [pc, #0x22c]
 *   @0x23ceb8 sub sp, sp, #20
 *   @0x23cebc add r3, r3, r3, lsl #1
 *   @0x23cec0 str r1, [r11, #-0x30]
 *   @0x23cec4 lsl r3, r3, #1
 *   @0x23cec8 ldr r8, [pc, r8]
 *   @0x23cecc add r1, r3, #15
 *   @0x23ced0 mov r7, r0
 *   @0x23ced4 bic r1, r1, #7
 *   @0x23ced8 ldr r0, [r8]
 *   @0x23cedc sub sp, sp, r1
 *   @0x23cee0 mov r4, r2
 *   @0x23cee4 mov r1, #0
 *   @0x23cee8 add r2, r3, #1
 *   @0x23ceec str r0, [r11, #-0x28]
 *   @0x23cef0 add r5, r5, r4
 *   @0x23cef4 mov r0, sp
 *   @0x23cef8 mov r6, sp
 *   @0x23cefc bl 0xb65b0 <memset@plt>
 *   @0x23cf00 cmp r4, r5
 *   @0x23cf04 bge 0x23cfe8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x23cf08 movw r10, #0xfffe
 *   @0x23cf0c movt r10, #0x1f
 *   @0x23cf10 mov r0, #0
 *   @0x23cf14 movw r9, #0x7fe
 *   @0x23cf18 vldr d6, [pc, #432]
 *   @0x23cf1c vldr d5, [pc, #436]
 *   @0x23cf20 vldr d4, [pc, #440]
 *   @0x23cf24 sub r1, r4, #-2147483647
 *   @0x23cf28 ldr r3, [r7]
 *   @0x23cf2c mov r12, #0
 *   @0x23cf30 mov lr, #1
 *   @0x23cf34 add r1, r3, r1, lsl #1
 *   @0x23cf38 b 0x23cf40 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x23cf3c mov lr, r2
 *   @0x23cf40 ldrh r3, [r1, #2]!
 *   @0x23cf44 vmov s7, r3
 *   @0x23cf48 vcvt.f64.u32 d7, s7
 *   @0x23cf4c vcmpe.f64 d7, d6
 *   @0x23cf50 vmrs APSR_nzcv, fpscr
 *   @0x23cf54 bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf58 vcmpe.f64 d7, d5
 *   @0x23cf5c vmrs APSR_nzcv, fpscr
 *   @0x23cf60 ble 0x23cf70 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x23cf64 vcmpe.f64 d7, d4
 *   @0x23cf68 vmrs APSR_nzcv, fpscr
 *   @0x23cf6c bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf70 and r2, r3, #1024
 *   @0x23cf74 uxth r2, r2
 *   @0x23cf78 cmp r2, #0
 *   @0x23cf7c bne 0x23d00c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x23cf80 add r4, r4, #1
 *   @0x23cf84 cmp r5, r4
 *   @0x23cf88 beq 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x23cf8c sub r12, r3, #55296
 *   @0x23cf90 lsl r12, r12, #10
 *   @0x23cf94 add r12, r12, #65536
 *   @0x23cf98 bgt 0x23cf3c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x23cf9c cmp r12, #126
 *   @0x23cfa0 strble r12, [r6, r0]
 *   @0x23cfa4 addle r0, r0, #1
 *   @0x23cfa8 ble 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23cfac cmp r12, r9
 *   @0x23cfb0 bgt 0x23d024 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x23cfb4 ubfx r3, r12, #0x6, #0x5
 *   @0x23cfb8 and r12, r12, #63
 *   @0x23cfbc add r2, r0, #1
 *   @0x23cfc0 mvn r3, r3, lsl #26
 *   @0x23cfc4 mvn r12, r12, lsl #25
 *   @0x23cfc8 mvn r3, r3, lsr #26
 *   @0x23cfcc strb r3, [r6, r0]
 *   @0x23cfd0 add r0, r0, #2
 *   @0x23cfd4 mvn r12, r12, lsr #25
 *   @0x23cfd8 strb r12, [r6, r2]
 *   @0x23cfdc add r4, r4, #1
 *   @0x23cfe0 cmp r5, r4
 *   @0x23cfe4 bgt 0x23cf24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x23cfe8 ldr r0, [r11, #-0x30]
 *   @0x23cfec mov r1, r6
 *   @0x23cff0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23cff4 ldr r2, [r11, #-0x28]
 *   @0x23cff8 ldr r3, [r8]
 *   @0x23cffc cmp r2, r3
 *   @0x23d000 bne 0x23d0cc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x23d004 sub sp, r11, #32
 *   @0x23d008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23d00c cmp lr, #0
 *   @0x23d010 subeq r3, r3, #56320
 *   @0x23d014 orreq r12, r12, r3
 *   @0x23d018 beq 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x23d01c mov r12, r3
 *   @0x23d020 b 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x23d024 movw r3, #0xfffe
 *   @0x23d028 cmp r12, r3
 *   @0x23d02c bgt 0x23d070 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x23d030 ubfx r2, r12, #0xc, #0x4
 *   @0x23d034 ubfx lr, r12, #0x6, #0x6
 *   @0x23d038 and r12, r12, #63
 *   @0x23d03c add r1, r0, #2
 *   @0x23d040 mov r3, r6
 *   @0x23d044 mvn r2, r2, lsl #27
 *   @0x23d048 mvn lr, lr, lsl #25
 *   @0x23d04c mvn r12, r12, lsl #25
 *   @0x23d050 mvn r2, r2, lsr #27
 *   @0x23d054 mvn lr, lr, lsr #25
 *   @0x23d058 strb r2, [r3, r0]!
 *   @0x23d05c mvn r12, r12, lsr #25
 *   @0x23d060 strb lr, [r3, #0x1]
 *   @0x23d064 add r0, r0, #3
 *   @0x23d068 strb r12, [r6, r1]
 *   @0x23d06c b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d070 cmp r12, r10
 *   @0x23d074 bgt 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d078 and r2, r12, #3670016
 *   @0x23d07c mov r3, r6
 *   @0x23d080 ubfx lr, r12, #0xc, #0x6
 *   @0x23d084 ubfx r1, r12, #0x6, #0x6
 *   @0x23d088 asr r2, r2, #18
 *   @0x23d08c and r12, r12, #63
 *   @0x23d090 mvn lr, lr, lsl #25
 *   @0x23d094 mvn r1, r1, lsl #25
 *   @0x23d098 mvn r2, r2, lsl #28
 *   @0x23d09c mvn r12, r12, lsl #25
 *   @0x23d0a0 mvn r2, r2, lsr #28
 *   @0x23d0a4 strb r2, [r3, r0]!
 *   @0x23d0a8 add r2, r0, #3
 *   @0x23d0ac mvn lr, lr, lsr #25
 *   @0x23d0b0 mvn r1, r1, lsr #25
 *   @0x23d0b4 strb lr, [r3, #0x1]
 *   @0x23d0b8 mvn r12, r12, lsr #25
 *   @0x23d0bc strb r1, [r3, #0x2]
 *   @0x23d0c0 add r0, r0, #4
 *   @0x23d0c4 strb r12, [r6, r2]
 *   @0x23d0c8 b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x23d0cc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x23d0d0 andeq r0, r0, r0
 *   @0x23d0d4 rscmi pc, r10, r0, ror #31
 *   @0x23d0d8 andeq r0, r0, r0
 *   @0x23d0dc rscmi r0, r12, r0
 *   @0x23d0e0 andeq r0, r0, r0
 *   @0x23d0e4 rscmi pc, pc, r0, ror #31
 *   @0x23d0e8 andseq r0, r11, r8, lsl #21
 *
 * ══ §17/54 Debug_GetStructures(Buffer_Standard*, Buffer_Standard*)  0x29bd84  size 580  145 条（0x29bd84..0x29bfc8）
 * @func 0x29bd84 0x29bfc8  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×4 / Debug_GetStructures(Buffer_Standard*, Buffer_Standard*)+0x1d4 / VM::GetDSGrid(Buffer_Standard*, int, int) / VM::GetDSMap(Buffer_Standard*, int, int) / VM::GetDSList(Buffer_Standard*, int, int) / VM::GetDSQueue(Buffer_Standard*, int, int) / VM::GetDSStack(Buffer_Standard*, int, int) / VM::GetDSPriority(Buffer_Standard*, int, int)
 * 字段偏移 top8: 0xc×4 / 0x38×4 / 0x30×4 / 0x8×4 / 0x4×3
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29bd84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29bd88 vpush {d8}
 *   @0x29bd8c add r6, r0, #44
 *   @0x29bd90 ldr lr, [r0]
 *   @0x29bd94 mov r10, r1
 *   @0x29bd98 sub sp, sp, #12
 *   @0x29bd9c mov r2, r6
 *   @0x29bda0 mov r8, #0
 *   @0x29bda4 mov r1, #5
 *   @0x29bda8 ldr r4, [lr, #0xc]
 *   @0x29bdac mov r11, r0
 *   @0x29bdb0 blx r4
 *   @0x29bdb4 mov r1, r8
 *   @0x29bdb8 mov r0, r6
 *   @0x29bdbc add r7, r10, #44
 *   @0x29bdc0 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bdc4 ldr lr, [r10]
 *   @0x29bdc8 mov r2, r7
 *   @0x29bdcc str r8, [r10, #0x38]
 *   @0x29bdd0 mov r1, #5
 *   @0x29bdd4 vmov s15, r0
 *   @0x29bdd8 str r0, [sp, #0x4]
 *   @0x29bddc mov r0, r10
 *   @0x29bde0 vcvt.f64.u32 d7, s15
 *   @0x29bde4 vmov r4, r5, d7
 *   @0x29bde8 vstr s14, [r10, #44]
 *   @0x29bdec str r5, [r10, #0x30]
 *   @0x29bdf0 ldr r4, [lr, #0x8]
 *   @0x29bdf4 blx r4
 *   @0x29bdf8 ldr r3, [sp, #0x4]
 *   @0x29bdfc cmp r3, r8
 *   @0x29be00 ble 0x29bf58 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1d4>
 *   @0x29be04 mov r9, r8
 *   @0x29be08 ldr lr, [r11]
 *   @0x29be0c mov r2, r6
 *   @0x29be10 mov r1, #5
 *   @0x29be14 mov r0, r11
 *   @0x29be18 ldr r4, [lr, #0xc]
 *   @0x29be1c blx r4
 *   @0x29be20 mov r1, #0
 *   @0x29be24 mov r0, r6
 *   @0x29be28 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29be2c ldr lr, [r11]
 *   @0x29be30 mov r2, r6
 *   @0x29be34 mov r1, #5
 *   @0x29be38 ldr r4, [lr, #0xc]
 *   @0x29be3c vmov s16, r0
 *   @0x29be40 mov r0, r11
 *   @0x29be44 blx r4
 *   @0x29be48 mov r1, #0
 *   @0x29be4c mov r0, r6
 *   @0x29be50 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29be54 ldr lr, [r11]
 *   @0x29be58 mov r2, r6
 *   @0x29be5c mov r1, #5
 *   @0x29be60 ldr r4, [lr, #0xc]
 *   @0x29be64 vmov s17, r0
 *   @0x29be68 mov r0, r11
 *   @0x29be6c blx r4
 *   @0x29be70 mov r1, #0
 *   @0x29be74 mov r0, r6
 *   @0x29be78 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29be7c vcvt.f64.u32 d7, s16
 *   @0x29be80 ldr lr, [r10]
 *   @0x29be84 mov r1, #5
 *   @0x29be88 mov r2, r7
 *   @0x29be8c str r9, [r10, #0x38]
 *   @0x29be90 vmov r4, r5, d7
 *   @0x29be94 vstr s14, [r10, #44]
 *   @0x29be98 str r5, [r10, #0x30]
 *   @0x29be9c ldr r4, [lr, #0x8]
 *   @0x29bea0 str r0, [sp]
 *   @0x29bea4 mov r0, r10
 *   @0x29bea8 blx r4
 *   @0x29beac vcvt.f64.u32 d7, s17
 *   @0x29beb0 ldr lr, [r10]
 *   @0x29beb4 mov r1, #5
 *   @0x29beb8 mov r2, r7
 *   @0x29bebc mov r0, r10
 *   @0x29bec0 str r9, [r10, #0x38]
 *   @0x29bec4 vmov r4, r5, d7
 *   @0x29bec8 vstr s14, [r10, #44]
 *   @0x29becc str r5, [r10, #0x30]
 *   @0x29bed0 ldr r4, [lr, #0x8]
 *   @0x29bed4 blx r4
 *   @0x29bed8 ldr r3, [sp]
 *   @0x29bedc ldr lr, [r10]
 *   @0x29bee0 mov r0, r10
 *   @0x29bee4 bic r4, r3, r3, asr #31
 *   @0x29bee8 str r9, [r10, #0x38]
 *   @0x29beec mov r1, #5
 *   @0x29bef0 mov r2, r7
 *   @0x29bef4 vmov s15, r4
 *   @0x29bef8 vcvt.f64.s32 d7, s15
 *   @0x29befc vmov r4, r5, d7
 *   @0x29bf00 vstr s14, [r10, #44]
 *   @0x29bf04 str r5, [r10, #0x30]
 *   @0x29bf08 ldr r4, [lr, #0x8]
 *   @0x29bf0c blx r4
 *   @0x29bf10 vmov r3, s16
 *   @0x29bf14 cmp r3, #5
 *   @0x29bf18 addls pc, pc, r3, lsl #2
 *   @0x29bf1c b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *   @0x29bf20 b 0x29bf78 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1f4>
 *   @0x29bf24 b 0x29bf64 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1e0>
 *   @0x29bf28 b 0x29bfa0 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x21c>
 *   @0x29bf2c b 0x29bf8c <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x208>
 *   @0x29bf30 b 0x29bfb4 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x230>
 *   @0x29bf34 b 0x29bf38 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1b4>
 *   @0x29bf38 vmov r1, s17
 *   @0x29bf3c mov r0, r10
 *   @0x29bf40 ldr r2, [sp]
 *   @0x29bf44 bl 0xdb70c <_ZN2VM9GetDSGridEP15Buffer_Standardii>
 *   @0x29bf48 ldr r3, [sp, #0x4]
 *   @0x29bf4c add r8, r8, #1
 *   @0x29bf50 cmp r3, r8
 *   @0x29bf54 bne 0x29be08 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x84>
 *   @0x29bf58 add sp, sp, #12
 *   @0x29bf5c vpop {d8}
 *   @0x29bf60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29bf64 vmov r1, s17
 *   @0x29bf68 mov r0, r10
 *   @0x29bf6c ldr r2, [sp]
 *   @0x29bf70 bl 0xdb4b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii>
 *   @0x29bf74 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *   @0x29bf78 vmov r1, s17
 *   @0x29bf7c mov r0, r10
 *   @0x29bf80 ldr r2, [sp]
 *   @0x29bf84 bl 0xdb130 <_ZN2VM9GetDSListEP15Buffer_Standardii>
 *   @0x29bf88 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *   @0x29bf8c vmov r1, s17
 *   @0x29bf90 mov r0, r10
 *   @0x29bf94 ldr r2, [sp]
 *   @0x29bf98 bl 0xdb2dc <_ZN2VM10GetDSQueueEP15Buffer_Standardii>
 *   @0x29bf9c b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *   @0x29bfa0 vmov r1, s17
 *   @0x29bfa4 mov r0, r10
 *   @0x29bfa8 ldr r2, [sp]
 *   @0x29bfac bl 0xdb210 <_ZN2VM10GetDSStackEP15Buffer_Standardii>
 *   @0x29bfb0 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *   @0x29bfb4 vmov r1, s17
 *   @0x29bfb8 mov r0, r10
 *   @0x29bfbc ldr r2, [sp]
 *   @0x29bfc0 bl 0xdb3b0 <_ZN2VM13GetDSPriorityEP15Buffer_Standardii>
 *   @0x29bfc4 b 0x29bf48 <_Z19Debug_GetStructuresP15Buffer_StandardS0_+0x1c4>
 *
 * ══ §18/54 Debug_SetBreakpoints(unsigned char*, int)  0x29c888  size 580  145 条（0x29c888..0x29cacc）
 * @func 0x29c888 0x29cacc  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×7 / Debug_SetBreakPoint(unsigned int*, bool, unsigned int, unsigned char*)×2 / AllocateIBuffer(void*, int, bool) / GetIBuffer(int) / Debug_SetBreakpoints(unsigned char*, int)+0x214 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×11 / 0x8×4 / 0x4×3 / 0x14×2 / 0x10×2 / 0x160×1 / 0x148×1 / 0x140×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c888 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29c88c mov r2, #0
 *   @0x29c890 sub sp, sp, #28
 *   @0x29c894 bl 0xc6a10 <_Z15AllocateIBufferPvib>
 *   @0x29c898 str r0, [sp, #0x14]
 *   @0x29c89c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29c8a0 mov r1, #5
 *   @0x29c8a4 ldr r3, [r0]
 *   @0x29c8a8 add r6, r0, #44
 *   @0x29c8ac mov r5, r0
 *   @0x29c8b0 mov r2, r6
 *   @0x29c8b4 ldr r3, [r3, #0xc]
 *   @0x29c8b8 blx r3
 *   @0x29c8bc mov r1, #0
 *   @0x29c8c0 mov r0, r6
 *   @0x29c8c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c8c8 ldr r3, [r5]
 *   @0x29c8cc mov r2, r6
 *   @0x29c8d0 mov r1, #5
 *   @0x29c8d4 mov r0, r5
 *   @0x29c8d8 ldr r3, [r3, #0xc]
 *   @0x29c8dc blx r3
 *   @0x29c8e0 mov r1, #0
 *   @0x29c8e4 mov r0, r6
 *   @0x29c8e8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c8ec ldr r3, [r5]
 *   @0x29c8f0 mov r2, r6
 *   @0x29c8f4 mov r1, #5
 *   @0x29c8f8 mov r0, r5
 *   @0x29c8fc ldr r3, [r3, #0xc]
 *   @0x29c900 blx r3
 *   @0x29c904 mov r1, #0
 *   @0x29c908 mov r0, r6
 *   @0x29c90c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c910 ldr r3, [r5]
 *   @0x29c914 mov r2, r6
 *   @0x29c918 mov r1, #5
 *   @0x29c91c mov r0, r5
 *   @0x29c920 ldr r3, [r3, #0xc]
 *   @0x29c924 blx r3
 *   @0x29c928 mov r1, #0
 *   @0x29c92c mov r0, r6
 *   @0x29c930 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c934 ldr r3, [r5]
 *   @0x29c938 mov r2, r6
 *   @0x29c93c mov r1, #5
 *   @0x29c940 mov r0, r5
 *   @0x29c944 ldr r3, [r3, #0xc]
 *   @0x29c948 blx r3
 *   @0x29c94c mov r0, r6
 *   @0x29c950 mov r1, #0
 *   @0x29c954 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c958 ldr r3, [pc, #0x160]
 *   @0x29c95c mov r2, #1
 *   @0x29c960 ldr r3, [pc, r3]
 *   @0x29c964 strb r2, [r3]
 *   @0x29c968 cmp r0, #0
 *   @0x29c96c str r0, [sp, #0xc]
 *   @0x29c970 ble 0x29ca9c <_Z20Debug_SetBreakpointsPhi+0x214>
 *   @0x29c974 ldr r3, [pc, #0x148]
 *   @0x29c978 mov r9, #0
 *   @0x29c97c str r3, [sp, #0x8]
 *   @0x29c980 ldr r3, [pc, #0x140]
 *   @0x29c984 add r3, pc, r3
 *   @0x29c988 str r3, [sp, #0x10]
 *   @0x29c98c ldr r3, [sp, #0x8]
 *   @0x29c990 ldr r3, [pc, r3]
 *   @0x29c994 str r3, [sp, #0x8]
 *   @0x29c998 ldr r3, [r5]
 *   @0x29c99c mov r1, #12
 *   @0x29c9a0 mov r2, r6
 *   @0x29c9a4 mov r0, r5
 *   @0x29c9a8 ldr r3, [r3, #0xc]
 *   @0x29c9ac blx r3
 *   @0x29c9b0 ldr r3, [r5]
 *   @0x29c9b4 mov r2, r6
 *   @0x29c9b8 mov r1, #5
 *   @0x29c9bc mov r0, r5
 *   @0x29c9c0 ldr r11, [r5, #0x2c]
 *   @0x29c9c4 ldr r3, [r3, #0xc]
 *   @0x29c9c8 blx r3
 *   @0x29c9cc mov r0, r6
 *   @0x29c9d0 mov r1, #0
 *   @0x29c9d4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29c9d8 ldr r3, [sp, #0x8]
 *   @0x29c9dc ldrb r2, [r3]
 *   @0x29c9e0 adds r0, r0, #0
 *   @0x29c9e4 movne r0, #1
 *   @0x29c9e8 cmp r2, #0
 *   @0x29c9ec str r0, [sp, #0x4]
 *   @0x29c9f0 beq 0x29caac <_Z20Debug_SetBreakpointsPhi+0x224>
 *   @0x29c9f4 ldr r3, [r5]
 *   @0x29c9f8 mov r2, r6
 *   @0x29c9fc mov r1, #5
 *   @0x29ca00 mov r0, r5
 *   @0x29ca04 ldr r3, [r3, #0xc]
 *   @0x29ca08 blx r3
 *   @0x29ca0c mov r1, #0
 *   @0x29ca10 mov r0, r6
 *   @0x29ca14 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29ca18 ldr r1, [sp, #0x10]
 *   @0x29ca1c movw r2, #0x325
 *   @0x29ca20 mov r3, #1
 *   @0x29ca24 mov r7, r0
 *   @0x29ca28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29ca2c cmp r7, #0
 *   @0x29ca30 movne r10, #0
 *   @0x29ca34 movne r4, r10
 *   @0x29ca38 mov r8, r0
 *   @0x29ca3c beq 0x29ca78 <_Z20Debug_SetBreakpointsPhi+0x1f0>
 *   @0x29ca40 ldr r3, [r5]
 *   @0x29ca44 mov r1, #1
 *   @0x29ca48 mov r2, r6
 *   @0x29ca4c mov r0, r5
 *   @0x29ca50 add r4, r4, r1
 *   @0x29ca54 ldr r3, [r3, #0xc]
 *   @0x29ca58 blx r3
 *   @0x29ca5c mov r0, r6
 *   @0x29ca60 mov r1, #0
 *   @0x29ca64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29ca68 cmp r4, r7
 *   @0x29ca6c strb r0, [r8, r10]
 *   @0x29ca70 mov r10, r4
 *   @0x29ca74 bne 0x29ca40 <_Z20Debug_SetBreakpointsPhi+0x1b8>
 *   @0x29ca78 mov r0, r11
 *   @0x29ca7c ldr r1, [sp, #0x4]
 *   @0x29ca80 mov r2, r7
 *   @0x29ca84 mov r3, r8
 *   @0x29ca88 bl 0x29c870 <_Z19Debug_SetBreakPointPjbjPh>
 *   @0x29ca8c ldr r3, [sp, #0xc]
 *   @0x29ca90 add r9, r9, #1
 *   @0x29ca94 cmp r3, r9
 *   @0x29ca98 bne 0x29c998 <_Z20Debug_SetBreakpointsPhi+0x110>
 *   @0x29ca9c ldr r0, [sp, #0x14]
 *   @0x29caa0 add sp, sp, #28
 *   @0x29caa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29caa8 b 0xc6a88 <_Z11FreeIBufferi>
 *   @0x29caac mov r0, r11
 *   @0x29cab0 ldr r1, [sp, #0x4]
 *   @0x29cab4 mov r3, r2
 *   @0x29cab8 bl 0x29c870 <_Z19Debug_SetBreakPointPjbjPh>
 *   @0x29cabc b 0x29ca8c <_Z20Debug_SetBreakpointsPhi+0x204>
 *   @0x29cac0 ldrsbeq r4, [r5], -r12
 *   @0x29cac4 mulseq r5, r4, pc
 *   @0x29cac8 andeq sp, r11, r0, asr #32
 *
 * ══ §19/54 b2ParticleSystem::SolveDamping(b2TimeStep const&)  0x2d8a44  size 580  145 条（0x2d8a44..0x2d8c88）
 * @func 0x2d8a44 0x2d8c88  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveDamping(b2TimeStep const&)+0x118 / b2ParticleSystem::GetParticleInvMass() const / b2ParticleSystem::SolveDamping(b2TimeStep const&)+0x1d4
 * 字段偏移 top8: 0x80×3 / 0x40×2 / 0x4×2 / 0x88×1 / 0x38×1 / 0x74×1 / 0x7c×1 / 0x-8×1
 * VFP 指令 84 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8a44 ldr r12, [r0, #0x80]
 *   @0x2d8a48 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d8a4c vpush {d8, d9, d10}
 *   @0x2d8a50 cmp r12, #0
 *   @0x2d8a54 vldr s18, [r0, #176]
 *   @0x2d8a58 mov r6, r0
 *   @0x2d8a5c movgt r5, #0
 *   @0x2d8a60 movgt r9, #0
 *   @0x2d8a64 movgt r8, r5
 *   @0x2d8a68 bgt 0x2d8a80 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x3c>
 *   @0x2d8a6c b 0x2d8b5c <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x118>
 *   @0x2d8a70 add r8, r8, #1
 *   @0x2d8a74 add r5, r5, #24
 *   @0x2d8a78 cmp r12, r8
 *   @0x2d8a7c ble 0x2d8b5c <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x118>
 *   @0x2d8a80 ldr r1, [r6, #0x88]
 *   @0x2d8a84 ldr r2, [r6, #0x38]
 *   @0x2d8a88 add r3, r1, r5
 *   @0x2d8a8c ldr r0, [r6, #0x40]
 *   @0x2d8a90 ldr r7, [r1, r5]
 *   @0x2d8a94 vldr s11, [r3, #16]
 *   @0x2d8a98 ldr r4, [r3, #0x4]
 *   @0x2d8a9c vldr s7, [r4, #60]
 *   @0x2d8aa0 vldr s12, [r4, #88]
 *   @0x2d8aa4 vldr s13, [r4, #84]
 *   @0x2d8aa8 lsl r7, r7, #3
 *   @0x2d8aac vldr s8, [r4, #64]
 *   @0x2d8ab0 add r2, r2, r7
 *   @0x2d8ab4 vldr s16, [r2]
 *   @0x2d8ab8 vsub.f32 s7, s16, s7
 *   @0x2d8abc vldr s17, [r2, #4]
 *   @0x2d8ac0 vldr s14, [r4, #80]
 *   @0x2d8ac4 add r7, r0, r7
 *   @0x2d8ac8 vldr s15, [r7, #4]
 *   @0x2d8acc vldr s9, [r7]
 *   @0x2d8ad0 vldr s10, [r3, #12]
 *   @0x2d8ad4 vldr s5, [r3, #8]
 *   @0x2d8ad8 vldr s6, [r3, #20]
 *   @0x2d8adc vmla.f32 s13, s12, s7
 *   @0x2d8ae0 vsub.f32 s8, s17, s8
 *   @0x2d8ae4 vmls.f32 s14, s12, s8
 *   @0x2d8ae8 vsub.f32 s15, s13, s15
 *   @0x2d8aec vmul.f32 s15, s15, s11
 *   @0x2d8af0 vsub.f32 s14, s14, s9
 *   @0x2d8af4 vmla.f32 s15, s10, s14
 *   @0x2d8af8 vcmpe.f32 s15, #0
 *   @0x2d8afc vmrs APSR_nzcv, fpscr
 *   @0x2d8b00 bpl 0x2d8a70 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x2c>
 *   @0x2d8b04 vmul.f32 s5, s18, s5
 *   @0x2d8b08 mov r0, r6
 *   @0x2d8b0c vmul.f32 s6, s5, s6
 *   @0x2d8b10 vmul.f32 s15, s6, s15
 *   @0x2d8b14 vmul.f32 s19, s15, s10
 *   @0x2d8b18 vmul.f32 s20, s15, s11
 *   @0x2d8b1c bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d8b20 vldr s13, [r7]
 *   @0x2d8b24 vldr s14, [r7, #4]
 *   @0x2d8b28 ldr r3, [r4]
 *   @0x2d8b2c cmp r3, #2
 *   @0x2d8b30 vmov s12, r0
 *   @0x2d8b34 vmla.f32 s13, s12, s19
 *   @0x2d8b38 vmla.f32 s14, s12, s20
 *   @0x2d8b3c vstr s13, [r7]
 *   @0x2d8b40 vstr s14, [r7, #4]
 *   @0x2d8b44 beq 0x2d8c20 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x1dc>
 *   @0x2d8b48 ldr r12, [r6, #0x80]
 *   @0x2d8b4c add r8, r8, #1
 *   @0x2d8b50 add r5, r5, #24
 *   @0x2d8b54 cmp r12, r8
 *   @0x2d8b58 bgt 0x2d8a80 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x3c>
 *   @0x2d8b5c ldr r4, [r6, #0x74]
 *   @0x2d8b60 cmp r4, #0
 *   @0x2d8b64 ble 0x2d8c18 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x1d4>
 *   @0x2d8b68 ldr r3, [r6, #0x7c]
 *   @0x2d8b6c add r4, r4, r4, lsl #1
 *   @0x2d8b70 ldr r12, [r6, #0x40]
 *   @0x2d8b74 add r4, r3, r4, lsl #3
 *   @0x2d8b78 add r2, r3, #12
 *   @0x2d8b7c b 0x2d8b88 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x144>
 *   @0x2d8b80 cmp r3, r4
 *   @0x2d8b84 beq 0x2d8c18 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x1d4>
 *   @0x2d8b88 ldr r1, [r2, #-0x8]
 *   @0x2d8b8c vldr s12, [r3, #20]
 *   @0x2d8b90 ldr r0, [r2, #-0xc]
 *   @0x2d8b94 vldr s11, [r3, #16]
 *   @0x2d8b98 vldr s9, [r2]
 *   @0x2d8b9c add r3, r3, #24
 *   @0x2d8ba0 add r1, r12, r1, lsl #3
 *   @0x2d8ba4 vldr s15, [r1, #4]
 *   @0x2d8ba8 add r0, r12, r0, lsl #3
 *   @0x2d8bac vldr s14, [r0, #4]
 *   @0x2d8bb0 vsub.f32 s15, s15, s14
 *   @0x2d8bb4 vldr s13, [r0]
 *   @0x2d8bb8 vldr s10, [r1]
 *   @0x2d8bbc add r2, r2, #24
 *   @0x2d8bc0 vmul.f32 s15, s15, s12
 *   @0x2d8bc4 vsub.f32 s10, s10, s13
 *   @0x2d8bc8 vmla.f32 s15, s10, s11
 *   @0x2d8bcc vcmpe.f32 s15, #0
 *   @0x2d8bd0 vmrs APSR_nzcv, fpscr
 *   @0x2d8bd4 bpl 0x2d8b80 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x13c>
 *   @0x2d8bd8 vmul.f32 s9, s18, s9
 *   @0x2d8bdc cmp r3, r4
 *   @0x2d8be0 vmul.f32 s15, s9, s15
 *   @0x2d8be4 vmul.f32 s11, s15, s11
 *   @0x2d8be8 vmul.f32 s12, s15, s12
 *   @0x2d8bec vadd.f32 s13, s13, s11
 *   @0x2d8bf0 vadd.f32 s14, s14, s12
 *   @0x2d8bf4 vstr s13, [r0]
 *   @0x2d8bf8 vldr s15, [r1]
 *   @0x2d8bfc vstr s14, [r0, #4]
 *   @0x2d8c00 vsub.f32 s11, s15, s11
 *   @0x2d8c04 vldr s15, [r1, #4]
 *   @0x2d8c08 vsub.f32 s12, s15, s12
 *   @0x2d8c0c vstr s11, [r1]
 *   @0x2d8c10 vstr s12, [r1, #4]
 *   @0x2d8c14 bne 0x2d8b88 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x144>
 *   @0x2d8c18 vpop {d8, d9, d10}
 *   @0x2d8c1c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d8c20 vldr s15, [r4, #64]
 *   @0x2d8c24 vsub.f32 s17, s17, s15
 *   @0x2d8c28 vldr s11, [r4, #60]
 *   @0x2d8c2c vldr s13, [r4, #88]
 *   @0x2d8c30 vldr s9, [r4, #136]
 *   @0x2d8c34 vldr s12, [r4, #80]
 *   @0x2d8c38 vldr s14, [r4, #84]
 *   @0x2d8c3c vldr s15, [r4, #144]
 *   @0x2d8c40 ldrh r3, [r4, #4]
 *   @0x2d8c44 ldr r12, [r6, #0x80]
 *   @0x2d8c48 tst r3, #2
 *   @0x2d8c4c orr r3, r3, #2
 *   @0x2d8c50 streq r9, [r4, #0xa0]
 *   @0x2d8c54 strheq r3, [r4, #4]
 *   @0x2d8c58 vneg.f32 s19, s19
 *   @0x2d8c5c vmul.f32 s17, s19, s17
 *   @0x2d8c60 vsub.f32 s16, s16, s11
 *   @0x2d8c64 vneg.f32 s20, s20
 *   @0x2d8c68 vnmls.f32 s17, s20, s16
 *   @0x2d8c6c vmla.f32 s12, s19, s9
 *   @0x2d8c70 vmla.f32 s13, s17, s15
 *   @0x2d8c74 vstr s12, [r4, #80]
 *   @0x2d8c78 vmla.f32 s14, s20, s9
 *   @0x2d8c7c vstr s13, [r4, #88]
 *   @0x2d8c80 vstr s14, [r4, #84]
 *   @0x2d8c84 b 0x2d8a70 <_ZN16b2ParticleSystem12SolveDampingERK10b2TimeStep+0x2c>
 *
 * ══ §20/54 CSkeletonInstance::SetBoneState(char const*, int)  0xc1480  size 576  144 条（0xc1480..0xc16c0）
 * @func 0xc1480 0xc16c0  size 576  144 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×5 / CDS_Map::Find(RValue*)×5 / FREE_RValue__Pre(RValue*)×5 / DS_AutoMutex::~DS_AutoMutex()×2 / spSkeleton_findBone / DS_AutoMutex::DS_AutoMutex()
 * 字段偏移 top8: 0x14×5 / 0x1c×1 / 0x1f4×1 / 0x4×1 / 0x2×1 / 0x1dc×1 / 0x194×1 / 0x14c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1480 push {r4, r5, r6, r7, lr}
 *   @0xc1484 sub sp, sp, #28
 *   @0xc1488 ldr r0, [r0, #0x1c]
 *   @0xc148c mov r4, r2
 *   @0xc1490 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0xc1494 subs r5, r0, #0
 *   @0xc1498 moveq r0, r5
 *   @0xc149c beq 0xc1650 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1d0>
 *   @0xc14a0 add r6, sp, #4
 *   @0xc14a4 mov r0, r6
 *   @0xc14a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xc14ac ldr r3, [pc, #0x1f4]
 *   @0xc14b0 ldr r3, [pc, r3]
 *   @0xc14b4 ldr r3, [r3, #0x4]
 *   @0xc14b8 ldr r7, [r3, r4, lsl #2]
 *   @0xc14bc cmp r7, #0
 *   @0xc14c0 beq 0xc1694 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x214>
 *   @0xc14c4 add r4, sp, #8
 *   @0xc14c8 ldr r1, [pc, #0x1dc]
 *   @0xc14cc mov r0, r4
 *   @0xc14d0 add r1, pc, r1
 *   @0xc14d4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc14d8 mov r0, r7
 *   @0xc14dc mov r1, r4
 *   @0xc14e0 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc14e4 cmp r0, #0
 *   @0xc14e8 ldrne r3, [r0, #0x14]
 *   @0xc14ec ldrne r2, [r0, #0x10]
 *   @0xc14f0 vmovne d6, r2, r3
 *   @0xc14f4 ldr r3, [sp, #0x14]
 *   @0xc14f8 vcvtne.f32.f64 s15, d6
 *   @0xc14fc sub r3, r3, #1
 *   @0xc1500 bic r3, r3, #-16777216
 *   @0xc1504 bic r3, r3, #3
 *   @0xc1508 vstrne s15, [r5, #20]
 *   @0xc150c cmp r3, #0
 *   @0xc1510 beq 0xc1688 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x208>
 *   @0xc1514 ldr r1, [pc, #0x194]
 *   @0xc1518 mov r0, r4
 *   @0xc151c add r1, pc, r1
 *   @0xc1520 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc1524 mov r0, r7
 *   @0xc1528 mov r1, r4
 *   @0xc152c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1530 cmp r0, #0
 *   @0xc1534 ldrne r3, [r0, #0x14]
 *   @0xc1538 ldrne r2, [r0, #0x10]
 *   @0xc153c vmovne d6, r2, r3
 *   @0xc1540 ldr r3, [sp, #0x14]
 *   @0xc1544 vcvtne.f32.f64 s15, d6
 *   @0xc1548 sub r3, r3, #1
 *   @0xc154c bic r3, r3, #-16777216
 *   @0xc1550 bic r3, r3, #3
 *   @0xc1554 vstrne s15, [r5, #24]
 *   @0xc1558 cmp r3, #0
 *   @0xc155c beq 0xc167c <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1fc>
 *   @0xc1560 ldr r1, [pc, #0x14c]
 *   @0xc1564 mov r0, r4
 *   @0xc1568 add r1, pc, r1
 *   @0xc156c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc1570 mov r0, r7
 *   @0xc1574 mov r1, r4
 *   @0xc1578 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc157c cmp r0, #0
 *   @0xc1580 ldrne r3, [r0, #0x14]
 *   @0xc1584 ldrne r2, [r0, #0x10]
 *   @0xc1588 vmovne d6, r2, r3
 *   @0xc158c ldr r3, [sp, #0x14]
 *   @0xc1590 vcvtne.f32.f64 s15, d6
 *   @0xc1594 sub r3, r3, #1
 *   @0xc1598 bic r3, r3, #-16777216
 *   @0xc159c bic r3, r3, #3
 *   @0xc15a0 vstrne s15, [r5, #28]
 *   @0xc15a4 cmp r3, #0
 *   @0xc15a8 beq 0xc1670 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1f0>
 *   @0xc15ac ldr r1, [pc, #0x104]
 *   @0xc15b0 mov r0, r4
 *   @0xc15b4 add r1, pc, r1
 *   @0xc15b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc15bc mov r0, r7
 *   @0xc15c0 mov r1, r4
 *   @0xc15c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc15c8 cmp r0, #0
 *   @0xc15cc ldrne r3, [r0, #0x14]
 *   @0xc15d0 ldrne r2, [r0, #0x10]
 *   @0xc15d4 vmovne d6, r2, r3
 *   @0xc15d8 ldr r3, [sp, #0x14]
 *   @0xc15dc vcvtne.f32.f64 s15, d6
 *   @0xc15e0 sub r3, r3, #1
 *   @0xc15e4 bic r3, r3, #-16777216
 *   @0xc15e8 bic r3, r3, #3
 *   @0xc15ec vstrne s15, [r5, #32]
 *   @0xc15f0 cmp r3, #0
 *   @0xc15f4 beq 0xc1664 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1e4>
 *   @0xc15f8 ldr r1, [pc, #0xbc]
 *   @0xc15fc mov r0, r4
 *   @0xc1600 add r1, pc, r1
 *   @0xc1604 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc1608 mov r0, r7
 *   @0xc160c mov r1, r4
 *   @0xc1610 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1614 cmp r0, #0
 *   @0xc1618 ldrne r3, [r0, #0x14]
 *   @0xc161c ldrne r2, [r0, #0x10]
 *   @0xc1620 vmovne d6, r2, r3
 *   @0xc1624 ldr r3, [sp, #0x14]
 *   @0xc1628 vcvtne.f32.f64 s15, d6
 *   @0xc162c sub r3, r3, #1
 *   @0xc1630 bic r3, r3, #-16777216
 *   @0xc1634 bic r3, r3, #3
 *   @0xc1638 vstrne s15, [r5, #36]
 *   @0xc163c cmp r3, #0
 *   @0xc1640 beq 0xc1658 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1d8>
 *   @0xc1644 mov r0, r6
 *   @0xc1648 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc164c mov r0, #1
 *   @0xc1650 add sp, sp, #28
 *   @0xc1654 pop {r4, r5, r6, r7, pc}
 *   @0xc1658 mov r0, r4
 *   @0xc165c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1660 b 0xc1644 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1c4>
 *   @0xc1664 mov r0, r4
 *   @0xc1668 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc166c b 0xc15f8 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x178>
 *   @0xc1670 mov r0, r4
 *   @0xc1674 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1678 b 0xc15ac <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x12c>
 *   @0xc167c mov r0, r4
 *   @0xc1680 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1684 b 0xc1560 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0xe0>
 *   @0xc1688 mov r0, r4
 *   @0xc168c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1690 b 0xc1514 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x94>
 *   @0xc1694 mov r0, r6
 *   @0xc1698 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc169c mov r0, r7
 *   @0xc16a0 add sp, sp, #28
 *   @0xc16a4 pop {r4, r5, r6, r7, pc}
 *   @0xc16a8 eorseq r12, r2, r12, lsl #9
 *   @0xc16ac eoreq pc, r6, r4, lsr #7
 *   @0xc16b0 eoreq pc, r6, r12, asr r3
 *   @0xc16b4 eoreq pc, r6, r4, lsl r3
 *   @0xc16b8 .word 0x0026f2d0
 *   @0xc16bc eoreq pc, r6, r12, lsl #5
 *
 * ══ §21/54 SoundHardware::Tick()  0x221134  size 576  137 条（0x221134..0x221374）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x221134 0x221374  size 576  137 条
 * 部分覆盖: 本节 137/144 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x221144→0x755361, 0x221160→0x755363, 0x221174→0x75530c, 0x221188→0x755360, 0x2211a0→0x755334, 0x2211b8→0x755338, 0x221280→0x755358, 0x221294→0x3f52dc
 * 调用序列: CheckALError()×2 / OpenAL_Tick() / SoundHardware::Tick()+0x14c / SoundHardware::Tick()+0x134 / 0xb6a9c / SoundHardware::Tick()+0x190 / OpenAL_MP3_SetVolume(float) / 0xb6a78
 * 字段偏移 top8: 0x4×4 / 0x64×3 / 0x1f4×2 / 0x20×2 / 0xc×2 / 0x1dc×1 / 0x1cc×1 / 0x1bc×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221134 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x221138 vpush {d8}
 *   @0x22113c sub sp, sp, #20
 *   @0x221140 ldr r6, [pc, #0x1f4]
 *   @0x221144 ldr r3, [pc, #0x1f4]
 *   @0x221148 add r6, pc, r6
 *   @0x22114c str r0, [sp]
 *   @0x221150 ldr r3, [r6, r3]
 *   @0x221154 ldrb r3, [r3]
 *   @0x221174 ldr r3, [pc, #0x1cc]
 *   @0x221178 ldr r3, [r6, r3]
 *   @0x22117c ldrb r3, [r3]
 *   @0x221180 cmp r3, #0
 *   @0x221184 bne 0x2212c4 <_ZN13SoundHardware4TickEv+0x190>
 *   @0x221188 ldr r3, [pc, #0x1bc]
 *   @0x22118c ldr r3, [r6, r3]
 *   @0x221190 ldrb r3, [r3]
 *   @0x221194 cmp r3, #0
 *   @0x221198 beq 0x221328 <_ZN13SoundHardware4TickEv+0x1f4>
 *   @0x22119c bl 0x2232d8 <_Z11OpenAL_Tickv>
 *   @0x2211a0 ldr r3, [pc, #0x1a8]
 *   @0x2211a4 ldr r10, [r6, r3]
 *   @0x2211a8 ldr r3, [r10]
 *   @0x2211ac cmp r3, #0
 *   @0x2211b0 ble 0x221280 <_ZN13SoundHardware4TickEv+0x14c>
 *   @0x2211b4 vmov.f32 s16, #1.000000e+00
 *   @0x2211b8 ldr r3, [pc, #0x194]
 *   @0x2211bc mov r5, #0
 *   @0x2211c0 add r9, sp, #12
 *   @0x2211c4 vldr s17, [pc, #364]
 *   @0x2211c8 ldr r11, [r6, r3]
 *   @0x2211cc str r6, [sp, #0x4]
 *   @0x2211d0 mov r6, r5
 *   @0x2211d4 ldr r3, [r11, #0x4]
 *   @0x2211d8 add r2, r3, r5
 *   @0x2211dc ldrb r3, [r3, r5]
 *   @0x2211e0 cmp r3, #0
 *   @0x2211e4 beq 0x221268 <_ZN13SoundHardware4TickEv+0x134>
 *   @0x2211e8 ldr r8, [r2, #0x8]
 *   @0x2211ec cmp r8, #0
 *   @0x2211f0 beq 0x221268 <_ZN13SoundHardware4TickEv+0x134>
 *   @0x2211f4 ldr r2, [r8, #0x20]
 *   @0x2211f8 cmp r2, #0
 *   @0x2211fc ble 0x221268 <_ZN13SoundHardware4TickEv+0x134>
 *   @0x221200 vldr s14, [r8, #24]
 *   @0x221204 vldr s15, [r8, #28]
 *   @0x221208 vadd.f32 s15, s14, s15
 *   @0x22120c vcmpe.f32 s15, #0
 *   @0x221210 vmrs APSR_nzcv, fpscr
 *   @0x221214 vstrmi s17, [r8, #24]
 *   @0x221218 bmi 0x22122c <_ZN13SoundHardware4TickEv+0xf8>
 *   @0x22121c vcmpe.f32 s15, s16
 *   @0x221220 vmrs APSR_nzcv, fpscr
 *   @0x221224 vmovgt.f32 s15, s16
 *   @0x221228 vstr s15, [r8, #24]
 *   @0x22122c add r7, r8, #16
 *   @0x221230 mov r4, r8
 *   @0x221234 sub r2, r2, #1
 *   @0x221238 str r2, [r8, #0x20]
 *   @0x22123c mov r2, r9
 *   @0x221240 ldr r0, [r4, #0x4]!
 *   @0x221244 movw r1, #0x1010
 *   @0x221248 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x22124c bl 0x220198 <_Z12CheckALErrorv>
 *   @0x221250 ldr r3, [sp, #0xc]
 *   @0x221254 movw r2, #0x1012
 *   @0x221258 cmp r3, r2
 *   @0x22125c beq 0x2212d0 <_ZN13SoundHardware4TickEv+0x19c>
 *   @0x221260 cmp r4, r7
 *   @0x221264 bne 0x22123c <_ZN13SoundHardware4TickEv+0x108>
 *   @0x221268 ldr r3, [r10]
 *   @0x22126c add r6, r6, #1
 *   @0x221270 add r5, r5, #20
 *   @0x221274 cmp r3, r6
 *   @0x221278 bgt 0x2211d4 <_ZN13SoundHardware4TickEv+0xa0>
 *   @0x22127c ldr r6, [sp, #0x4]
 *   @0x221280 ldr r3, [pc, #0xd0]
 *   @0x221284 ldr r3, [r6, r3]
 *   @0x221288 ldr r2, [r3]
 *   @0x22128c cmp r2, #0
 *   @0x221290 ble 0x2212c4 <_ZN13SoundHardware4TickEv+0x190>
 *   @0x221294 ldr r1, [pc, #0xc0]
 *   @0x221298 sub r2, r2, #1
 *   @0x22129c ldr r0, [pc, #0xbc]
 *   @0x2212a0 ldr r1, [r6, r1]
 *   @0x2212a4 vldr s14, [r1]
 *   @0x2212a8 ldr r0, [r6, r0]
 *   @0x2212ac vldr s15, [r0]
 *   @0x2212b0 vadd.f32 s15, s14, s15
 *   @0x2212b4 str r2, [r3]
 *   @0x2212b8 vmov r0, s15
 *   @0x2212bc vstr s15, [r1]
 *   @0x2212c0 bl 0x223254 <_Z20OpenAL_MP3_SetVolumef>
 *   @0x2212c4 add sp, sp, #20
 *   @0x2212c8 vpop {d8}
 *   @0x2212cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2212d0 vldr s14, [r8, #24]
 *   @0x2212d4 ldr r3, [sp]
 *   @0x2212d8 vldr s15, [r3]
 *   @0x2212dc vmul.f32 s15, s14, s15
 *   @0x2212e0 ldr r0, [r4]
 *   @0x2212e4 movw r1, #0x100a
 *   @0x2212e8 vmov r2, s15
 *   @0x2212ec bl 0xb6a78 <alSourcef@plt>
 *   @0x2212f0 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x2212f4 b 0x221260 <_ZN13SoundHardware4TickEv+0x12c>
 *   @0x2212f8 ldr r3, [pc, #0x64]
 *   @0x2212fc ldr r2, [pc, #0x64]
 *   @0x221300 ldr r1, [pc, #0x64]
 *   @0x221304 ldr r3, [r6, r3]
 *   @0x221308 add r2, pc, r2
 *   @0x22130c add r1, pc, r1
 *   @0x221310 add r2, r2, #172
 *   @0x221314 ldr r0, [r3]
 *   @0x221318 ldr r3, [r0]
 *   @0x22131c ldr r3, [r3, #0xc]
 *   @0x221320 blx r3
 *   @0x221324 b 0x221160 <_ZN13SoundHardware4TickEv+0x2c>
 *   @0x221328 ldr r0, [pc, #0x40]
 *   @0x22132c add r0, pc, r0
 *   @0x221330 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x221334 b 0x22119c <_ZN13SoundHardware4TickEv+0x68>
 *   @0x221338 andeq r0, r0, r0
 *   @0x22133c andseq r0, sp, r8, lsl #22
 *   @0x221340 .word 0xfffff7d8
 *   @0x221344 .word 0xffffd3fc
 *   @0x221348 .word 0xfffff79c
 *   @0x22134c .word 0xfffff7e4
 *   @0x221350 .word 0xfffff7c4
 *   @0x221354 .word 0xfffff7c8
 *   @0x221358 .word 0xfffff7f0
 *   @0x22135c .word 0xfffff7e8
 *   @0x221360 .word 0xfffff7ec
 *   @0x221364 .word 0xffffbac4
 *   @0x221368 andseq r12, r3, r0, asr #25
 *   @0x22136c andseq r3, r3, r0, lsr r5
 *   @0x221370 andseq r3, r3, r4, ror #10
 *
 * ══ §22/54 JS_ErrorObjectSetup()  0x244368  size 576  144 条（0x244368..0x2445a8）
 * @func 0x244368 0x2445a8  size 576  144 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x244374→0x756440, 0x244378→0x756450, 0x2443b0→0x75643c, 0x2443f0→0x756438, 0x244420→0x756434, 0x244448→0x756430, 0x244468→0x75642c, 0x244488→0x756428
 * 调用序列: JS_CreateNativeErrorSetup(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), YYObjectBase**, YYObjectBase*)×7 / YYObjectBase::Add(char const*, YYObjectBase*, int)×6
 * 字段偏移 top8: 0x1d0×3 / 0x1ac×3 / 0x8×2 / 0x180×2 / 0xc×2 / 0x4×2 / 0x15c×2 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244368 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24436c sub sp, sp, #36
 *   @0x244370 ldr r4, [pc, #0x1d0]
 *   @0x244374 ldr r2, [pc, #0x1d0]
 *   @0x244378 ldr r3, [pc, #0x1d0]
 *   @0x24437c add r4, pc, r4
 *   @0x244380 ldr r10, [pc, #0x1cc]
 *   @0x244384 ldr r5, [r4, r2]
 *   @0x244388 ldr r3, [r4, r3]
 *   @0x24438c add r10, pc, r10
 *   @0x244390 ldr r1, [pc, #0x1c0]
 *   @0x244394 mov r2, r5
 *   @0x244398 mov r0, r10
 *   @0x24439c ldr r3, [r3]
 *   @0x2443a0 ldr r1, [r4, r1]
 *   @0x2443a4 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x2443a8 ldr r7, [pc, #0x1ac]
 *   @0x2443ac ldr r1, [pc, #0x1ac]
 *   @0x2443b0 ldr r2, [pc, #0x1ac]
 *   @0x2443b4 add r7, pc, r7
 *   @0x2443b8 ldr r3, [r5]
 *   @0x2443bc ldr r6, [pc, #0x1a4]
 *   @0x2443c0 mov r11, r7
 *   @0x2443c4 ldr r9, [pc, #0x1a0]
 *   @0x2443c8 add r6, pc, r6
 *   @0x2443cc ldr r8, [pc, #0x19c]
 *   @0x2443d0 add r9, pc, r9
 *   @0x2443d4 add r8, pc, r8
 *   @0x2443d8 str r0, [sp, #0x8]
 *   @0x2443dc mov r0, r7
 *   @0x2443e0 ldr r1, [r4, r1]
 *   @0x2443e4 ldr r2, [r4, r2]
 *   @0x2443e8 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x2443ec ldr r1, [pc, #0x180]
 *   @0x2443f0 ldr r2, [pc, #0x180]
 *   @0x2443f4 mov r12, r6
 *   @0x2443f8 ldr r3, [r5]
 *   @0x2443fc ldr r7, [pc, #0x178]
 *   @0x244400 add r7, pc, r7
 *   @0x244404 str r0, [sp, #0xc]
 *   @0x244408 mov r0, r6
 *   @0x24440c ldr r1, [r4, r1]
 *   @0x244410 ldr r2, [r4, r2]
 *   @0x244414 str r12, [sp, #0x4]
 *   @0x244418 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x24441c ldr r1, [pc, #0x15c]
 *   @0x244420 ldr r2, [pc, #0x15c]
 *   @0x244424 ldr r3, [r5]
 *   @0x244428 ldr r6, [pc, #0x158]
 *   @0x24442c add r6, pc, r6
 *   @0x244430 str r0, [sp, #0x10]
 *   @0x244434 mov r0, r9
 *   @0x244438 ldr r1, [r4, r1]
 *   @0x24443c ldr r2, [r4, r2]
 *   @0x244440 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x244444 ldr r1, [pc, #0x140]
 *   @0x244448 ldr r2, [pc, #0x140]
 *   @0x24444c ldr r3, [r5]
 *   @0x244450 str r0, [sp, #0x14]
 *   @0x244454 mov r0, r8
 *   @0x244458 ldr r1, [r4, r1]
 *   @0x24445c ldr r2, [r4, r2]
 *   @0x244460 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x244464 ldr r1, [pc, #0x128]
 *   @0x244468 ldr r2, [pc, #0x128]
 *   @0x24446c ldr r3, [r5]
 *   @0x244470 str r0, [sp, #0x18]
 *   @0x244474 mov r0, r7
 *   @0x244478 ldr r1, [r4, r1]
 *   @0x24447c ldr r2, [r4, r2]
 *   @0x244480 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x244484 ldr r1, [pc, #0x110]
 *   @0x244488 ldr r2, [pc, #0x110]
 *   @0x24448c ldr r3, [r5]
 *   @0x244490 str r0, [sp, #0x1c]
 *   @0x244494 mov r0, r6
 *   @0x244498 ldr r1, [r4, r1]
 *   @0x24449c ldr r2, [r4, r2]
 *   @0x2444a0 bl 0x2441d4 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_>
 *   @0x2444a4 mov r1, r10
 *   @0x2444a8 ldr r2, [sp, #0x8]
 *   @0x2444ac mov r3, #0
 *   @0x2444b0 mov r5, r0
 *   @0x2444b4 ldr r0, [pc, #0xe8]
 *   @0x2444b8 ldr r4, [r4, r0]
 *   @0x2444bc ldr r0, [r4]
 *   @0x2444c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2444c4 mov r1, r11
 *   @0x2444c8 ldr r2, [sp, #0xc]
 *   @0x2444cc mov r3, #0
 *   @0x2444d0 ldr r0, [r4]
 *   @0x2444d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2444d8 ldr r12, [sp, #0x4]
 *   @0x2444dc ldr r2, [sp, #0x10]
 *   @0x2444e0 mov r3, #0
 *   @0x2444e4 ldr r0, [r4]
 *   @0x2444e8 mov r1, r12
 *   @0x2444ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2444f0 mov r1, r9
 *   @0x2444f4 ldr r2, [sp, #0x14]
 *   @0x2444f8 mov r3, #0
 *   @0x2444fc ldr r0, [r4]
 *   @0x244500 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244504 mov r1, r8
 *   @0x244508 ldr r2, [sp, #0x18]
 *   @0x24450c mov r3, #0
 *   @0x244510 ldr r0, [r4]
 *   @0x244514 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244518 mov r1, r7
 *   @0x24451c ldr r2, [sp, #0x1c]
 *   @0x244520 mov r3, #0
 *   @0x244524 ldr r0, [r4]
 *   @0x244528 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24452c ldr r0, [r4]
 *   @0x244530 mov r1, r6
 *   @0x244534 mov r2, r5
 *   @0x244538 mov r3, #0
 *   @0x24453c add sp, sp, #36
 *   @0x244540 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x244544 b 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x244548 ldrsbeq sp, [r10], -r4
 *   @0x24454c .word 0xfffffa78
 *   @0x244550 .word 0xffffc050
 *   @0x244554 mulseq r1, r8, r5
 *   @0x244558 .word 0xfffffa98
 *   @0x24455c andseq r1, r1, r4, lsl #11
 *   @0x244560 .word 0xfffffa9c
 *   @0x244564 .word 0xfffffa7c
 *   @0x244568 andseq r1, r1, r12, ror r5
 *   @0x24456c andseq r1, r1, r0, lsl #11
 *   @0x244570 andseq r1, r1, r12, lsl #11
 *   @0x244574 .word 0xfffffaa0
 *   @0x244578 .word 0xfffffa80
 *   @0x24457c andseq r1, r1, r12, ror #10
 *   @0x244580 .word 0xfffffaa4
 *   @0x244584 .word 0xfffffa84
 *   @0x244588 andseq r1, r1, r12, asr #10
 *   @0x24458c .word 0xfffffaa8
 *   @0x244590 .word 0xfffffa88
 *   @0x244594 .word 0xfffffaac
 *   @0x244598 .word 0xfffffa8c
 *   @0x24459c .word 0xfffffab0
 *   @0x2445a0 .word 0xfffffa90
 *   @0x2445a4 .word 0xffffbf64
 *
 * ══ §23/54 UnwindExceptionStack()  0x24e0b4  size 576  144 条（0x24e0b4..0x24e2f4）
 * @func 0x24e0b4 0x24e2f4  size 576  144 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x24e0c0→0x47f298, 0x24e0d8→0x756470, 0x24e0e0→0x75646c, 0x24e180→0x756458, 0x24e1b0→0x75645c, 0x24e294→0x756458, 0x24e2b8→0x756470
 * 调用序列: UnwindExceptionStack()+0x1fc / PerformReturn(unsigned char*, VMExec*) / F_JS_ToString(RValue&, RValue*) / Code_Variable_Find_Slot_From_Local_Name(char const*) / YYObjectBase::HasValue(char const*) / YYError(char const*, ...) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x28×5 / 0x4×4 / 0x44×3 / 0x20c×2 / 0x4c×2 / 0x5c×2 / 0x2×2 / 0x48×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e0b4 push {r4, r5, r6, r7, r8, lr}
 *   @0x24e0b8 sub sp, sp, #16
 *   @0x24e0bc ldr r5, [pc, #0x20c]
 *   @0x24e0c0 ldr r3, [pc, #0x20c]
 *   @0x24e0c4 add r5, pc, r5
 *   @0x24e0c8 ldr r3, [r5, r3]
 *   @0x24e0cc ldr r4, [r3]
 *   @0x24e0d0 cmp r4, #0
 *   @0x24e0d4 beq 0x24e2b8 <_Z20UnwindExceptionStackv+0x204>
 *   @0x24e0d8 ldr r2, [pc, #0x1f8]
 *   @0x24e0dc mov r8, #1
 *   @0x24e0e0 ldr r3, [pc, #0x1f4]
 *   @0x24e0e4 ldr r6, [r5, r2]
 *   @0x24e0e8 ldr r7, [r5, r3]
 *   @0x24e0ec ldr r3, [r4, #0x4c]
 *   @0x24e0f0 ldr r0, [r4, #0x28]
 *   @0x24e0f4 cmp r3, #0
 *   @0x24e0f8 ble 0x24e2b0 <_Z20UnwindExceptionStackv+0x1fc>
 *   @0x24e0fc cmp r0, #0
 *   @0x24e100 beq 0x24e19c <_Z20UnwindExceptionStackv+0xe8>
 *   @0x24e104 ldr r3, [r0, #0x28]
 *   @0x24e108 cmp r3, #0
 *   @0x24e10c beq 0x24e128 <_Z20UnwindExceptionStackv+0x74>
 *   @0x24e110 b 0x24e25c <_Z20UnwindExceptionStackv+0x1a8>
 *   @0x24e114 cmp r3, #0
 *   @0x24e118 beq 0x24e19c <_Z20UnwindExceptionStackv+0xe8>
 *   @0x24e11c ldr r3, [r3, #0x28]
 *   @0x24e120 cmp r3, #0
 *   @0x24e124 bne 0x24e25c <_Z20UnwindExceptionStackv+0x1a8>
 *   @0x24e128 mov r1, r4
 *   @0x24e12c bl 0xe42d8 <_Z13PerformReturnPhP6VMExec>
 *   @0x24e130 ldr r2, [r4, #0x4c]
 *   @0x24e134 ldr r3, [r4, #0x28]
 *   @0x24e138 cmp r2, #0
 *   @0x24e13c bgt 0x24e114 <_Z20UnwindExceptionStackv+0x60>
 *   @0x24e140 cmp r3, #0
 *   @0x24e144 str r0, [r7]
 *   @0x24e148 strb r8, [r6]
 *   @0x24e14c beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0>
 *   @0x24e150 ldr r3, [r3, #0x28]
 *   @0x24e154 cmp r3, #0
 *   @0x24e158 beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0>
 *   @0x24e15c ldr r2, [r3, #0x4]
 *   @0x24e160 cmn r2, #1
 *   @0x24e164 beq 0x24e270 <_Z20UnwindExceptionStackv+0x1bc>
 *   @0x24e168 cmp r2, #0
 *   @0x24e16c add r0, r2, #3
 *   @0x24e170 ldr r1, [r4, #0x5c]
 *   @0x24e174 movge r0, r2
 *   @0x24e178 str r2, [r4, #0x44]
 *   @0x24e17c asr r2, r0, #2
 *   @0x24e180 ldr r3, [pc, #0x158]
 *   @0x24e184 ldr r2, [r1, r2, lsl #2]
 *   @0x24e188 str r2, [r4, #0x48]
 *   @0x24e18c ldr r3, [r5, r3]
 *   @0x24e190 str r4, [r3]
 *   @0x24e194 add sp, sp, #16
 *   @0x24e198 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24e19c str r0, [r7]
 *   @0x24e1a0 strb r8, [r6]
 *   @0x24e1a4 ldr r4, [r4, #0x4]
 *   @0x24e1a8 cmp r4, #0
 *   @0x24e1ac bne 0x24e0ec <_Z20UnwindExceptionStackv+0x38>
 *   @0x24e1b0 ldr r12, [pc, #0x12c]
 *   @0x24e1b4 mov r1, #0
 *   @0x24e1b8 mov r3, #0
 *   @0x24e1bc strb r1, [r6]
 *   @0x24e1c0 str r1, [sp, #0x8]
 *   @0x24e1c4 mov r2, #0
 *   @0x24e1c8 mvn r1, #-16777216
 *   @0x24e1cc strd r2, r3, [sp]
 *   @0x24e1d0 str r1, [sp, #0xc]
 *   @0x24e1d4 mov r0, sp
 *   @0x24e1d8 ldr r4, [r5, r12]
 *   @0x24e1dc mov r1, r4
 *   @0x24e1e0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x24e1e4 ldr r3, [sp]
 *   @0x24e1e8 cmp r3, #0
 *   @0x24e1ec beq 0x24e194 <_Z20UnwindExceptionStackv+0xe0>
 *   @0x24e1f0 ldr r5, [pc, #0xf0]
 *   @0x24e1f4 add r5, pc, r5
 *   @0x24e1f8 mov r0, r5
 *   @0x24e1fc bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc>
 *   @0x24e200 ldr r3, [sp]
 *   @0x24e204 mov r1, r5
 *   @0x24e208 ldr r5, [r3]
 *   @0x24e20c mov r6, r0
 *   @0x24e210 ldr r0, [r4]
 *   @0x24e214 bl 0x192218 <_ZN12YYObjectBase8HasValueEPKc>
 *   @0x24e218 ldr r2, [pc, #0xcc]
 *   @0x24e21c add r2, pc, r2
 *   @0x24e220 cmp r0, #0
 *   @0x24e224 beq 0x24e244 <_Z20UnwindExceptionStackv+0x190>
 *   @0x24e228 ldr r0, [r4]
 *   @0x24e22c ldr r3, [r0, #0x4]
 *   @0x24e230 cmp r3, #0
 *   @0x24e234 beq 0x24e2c4 <_Z20UnwindExceptionStackv+0x210>
 *   @0x24e238 add r0, r3, r6, lsl #4
 *   @0x24e23c ldr r3, [r0]
 *   @0x24e240 ldr r2, [r3]
 *   @0x24e244 ldr r0, [pc, #0xa4]
 *   @0x24e248 mov r1, r5
 *   @0x24e24c add r0, pc, r0
 *   @0x24e250 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x24e254 add sp, sp, #16
 *   @0x24e258 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24e25c ldr r2, [r3, #0x4]
 *   @0x24e260 str r0, [r7]
 *   @0x24e264 cmn r2, #1
 *   @0x24e268 strb r8, [r6]
 *   @0x24e26c bne 0x24e168 <_Z20UnwindExceptionStackv+0xb4>
 *   @0x24e270 ldr r3, [r3, #0x8]
 *   @0x24e274 cmn r3, #1
 *   @0x24e278 beq 0x24e1a4 <_Z20UnwindExceptionStackv+0xf0>
 *   @0x24e27c cmp r3, #0
 *   @0x24e280 add r1, r3, #3
 *   @0x24e284 ldr r2, [r4, #0x5c]
 *   @0x24e288 movge r1, r3
 *   @0x24e28c str r3, [r4, #0x44]
 *   @0x24e290 asr r1, r1, #2
 *   @0x24e294 ldr r3, [pc, #0x44]
 *   @0x24e298 ldr r2, [r2, r1, lsl #2]
 *   @0x24e29c str r2, [r4, #0x48]
 *   @0x24e2a0 ldr r3, [r5, r3]
 *   @0x24e2a4 str r4, [r3]
 *   @0x24e2a8 add sp, sp, #16
 *   @0x24e2ac pop {r4, r5, r6, r7, r8, pc}
 *   @0x24e2b0 mov r3, r0
 *   @0x24e2b4 b 0x24e140 <_Z20UnwindExceptionStackv+0x8c>
 *   @0x24e2b8 ldr r3, [pc, #0x18]
 *   @0x24e2bc ldr r6, [r5, r3]
 *   @0x24e2c0 b 0x24e1b0 <_Z20UnwindExceptionStackv+0xfc>
 *   @0x24e2c4 mov r1, r6
 *   @0x24e2c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24e2cc b 0x24e23c <_Z20UnwindExceptionStackv+0x188>
 *   @0x24e2d0 andseq r3, r10, r12, lsl #23
 *   @0x24e2d4 .word 0xffffbf58
 *   @0x24e2d8 .word 0xffffc0cc
 *   @0x24e2dc .word 0xffffc0e0
 *   @0x24e2e0 .word 0xffffc0dc
 *   @0x24e2e4 .word 0xffffc0d8
 *   @0x24e2e8 andseq r7, r0, r8, lsr r7
 *   @0x24e2ec ldrheq r7, [r0], -r8
 *   @0x24e2f0 mulseq r0, r8, r12
 *
 * ══ §24/54 FacebookLoginM(int, int)  0x15f67c  size 572  143 条（0x15f67c..0x15f8b8）
 * @func 0x15f67c 0x15f8b8  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×9 / FacebookLoginM(int, int)+0x194 / F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*) / FacebookLoginM(int, int)+0x1ec / F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*) / FREE_RValue__Pre(RValue*) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x10×4 / 0x18×3 / 0x29c×3 / 0xc×3 / 0x3c×3 / 0x2b0×2 / 0x1c×2 / 0x2c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f67c cmp r0, #0
 *   @0x15f680 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15f684 sub sp, sp, #68
 *   @0x15f688 blt 0x15f810 <_Z14FacebookLoginMii+0x194>
 *   @0x15f68c vmov s13, r0
 *   @0x15f690 add r7, sp, #16
 *   @0x15f694 mov r4, #0
 *   @0x15f698 mov r3, #1
 *   @0x15f69c vcvt.f64.s32 d7, s13
 *   @0x15f6a0 mov r2, r4
 *   @0x15f6a4 mov r1, r4
 *   @0x15f6a8 mov r0, r7
 *   @0x15f6ac add r10, sp, #32
 *   @0x15f6b0 str r10, [sp]
 *   @0x15f6b4 str r4, [sp, #0x10]
 *   @0x15f6b8 str r4, [sp, #0x2c]
 *   @0x15f6bc vstr d7, [sp, #32]
 *   @0x15f6c0 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_>
 *   @0x15f6c4 vldr d7, [sp, #16]
 *   @0x15f6c8 vcvt.s32.f64 s13, d7
 *   @0x15f6cc vmov r8, s13
 *   @0x15f6d0 bl 0x290274 <getJNIEnv>
 *   @0x15f6d4 mov r5, r0
 *   @0x15f6d8 bl 0x290274 <getJNIEnv>
 *   @0x15f6dc ldr r1, [pc, #0x1b4]
 *   @0x15f6e0 add r1, pc, r1
 *   @0x15f6e4 ldr r3, [r0]
 *   @0x15f6e8 ldr r3, [r3, #0x18]
 *   @0x15f6ec blx r3
 *   @0x15f6f0 mov r6, r0
 *   @0x15f6f4 bl 0x290274 <getJNIEnv>
 *   @0x15f6f8 ldr r1, [pc, #0x19c]
 *   @0x15f6fc add r1, pc, r1
 *   @0x15f700 ldr r3, [r0]
 *   @0x15f704 ldr r3, [r3, #0x29c]
 *   @0x15f708 blx r3
 *   @0x15f70c ldr r12, [r5]
 *   @0x15f710 mov r2, r6
 *   @0x15f714 mov r1, r8
 *   @0x15f718 ldr r12, [r12, #0x2b0]
 *   @0x15f71c mov r3, r0
 *   @0x15f720 mov r0, r5
 *   @0x15f724 blx r12
 *   @0x15f728 cmp r8, r4
 *   @0x15f72c mov r9, r0
 *   @0x15f730 ble 0x15f868 <_Z14FacebookLoginMii+0x1ec>
 *   @0x15f734 ldr r3, [pc, #0x164]
 *   @0x15f738 mov r5, r4
 *   @0x15f73c ldr r2, [pc, #0x160]
 *   @0x15f740 ldr r3, [pc, r3]
 *   @0x15f744 add r2, pc, r2
 *   @0x15f748 str r2, [sp, #0xc]
 *   @0x15f74c ldr r6, [r3]
 *   @0x15f750 b 0x15f76c <_Z14FacebookLoginMii+0xf0>
 *   @0x15f754 cmp r4, r8
 *   @0x15f758 mov r2, #5
 *   @0x15f75c str r5, [sp, #0x18]
 *   @0x15f760 str r2, [sp, #0x1c]
 *   @0x15f764 str r5, [sp, #0x10]
 *   @0x15f768 beq 0x15f868 <_Z14FacebookLoginMii+0x1ec>
 *   @0x15f76c vmov s13, r4
 *   @0x15f770 mov r1, #0
 *   @0x15f774 mov r2, r1
 *   @0x15f778 mov r0, r7
 *   @0x15f77c vcvt.f64.s32 d7, s13
 *   @0x15f780 mov r3, #2
 *   @0x15f784 str r10, [sp]
 *   @0x15f788 str r5, [sp, #0x3c]
 *   @0x15f78c vstr d7, [sp, #48]
 *   @0x15f790 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x15f794 ldr r3, [r6]
 *   @0x15f798 mov r0, r6
 *   @0x15f79c ldr r2, [sp, #0x10]
 *   @0x15f7a0 ldr r1, [sp, #0xc]
 *   @0x15f7a4 ldr r3, [r3, #0xc]
 *   @0x15f7a8 ldr r2, [r2]
 *   @0x15f7ac blx r3
 *   @0x15f7b0 bl 0x290274 <getJNIEnv>
 *   @0x15f7b4 ldr r3, [sp, #0x10]
 *   @0x15f7b8 ldr r1, [r3]
 *   @0x15f7bc ldr r3, [r0]
 *   @0x15f7c0 ldr r3, [r3, #0x29c]
 *   @0x15f7c4 blx r3
 *   @0x15f7c8 mov r11, r0
 *   @0x15f7cc bl 0x290274 <getJNIEnv>
 *   @0x15f7d0 mov r3, r11
 *   @0x15f7d4 mov r2, r4
 *   @0x15f7d8 mov r1, r9
 *   @0x15f7dc add r4, r4, #1
 *   @0x15f7e0 ldr r12, [r0]
 *   @0x15f7e4 ldr r12, [r12, #0x2b8]
 *   @0x15f7e8 blx r12
 *   @0x15f7ec ldr r3, [sp, #0x1c]
 *   @0x15f7f0 sub r3, r3, #1
 *   @0x15f7f4 bic r3, r3, #-16777216
 *   @0x15f7f8 bic r3, r3, #3
 *   @0x15f7fc cmp r3, #0
 *   @0x15f800 bne 0x15f754 <_Z14FacebookLoginMii+0xd8>
 *   @0x15f804 mov r0, r7
 *   @0x15f808 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15f80c b 0x15f754 <_Z14FacebookLoginMii+0xd8>
 *   @0x15f810 bl 0x290274 <getJNIEnv>
 *   @0x15f814 mov r4, r0
 *   @0x15f818 bl 0x290274 <getJNIEnv>
 *   @0x15f81c ldr r1, [pc, #0x84]
 *   @0x15f820 add r1, pc, r1
 *   @0x15f824 ldr r3, [r0]
 *   @0x15f828 ldr r3, [r3, #0x18]
 *   @0x15f82c blx r3
 *   @0x15f830 mov r5, r0
 *   @0x15f834 bl 0x290274 <getJNIEnv>
 *   @0x15f838 ldr r1, [pc, #0x6c]
 *   @0x15f83c add r1, pc, r1
 *   @0x15f840 ldr r3, [r0]
 *   @0x15f844 ldr r3, [r3, #0x29c]
 *   @0x15f848 blx r3
 *   @0x15f84c ldr r12, [r4]
 *   @0x15f850 mov r2, r5
 *   @0x15f854 mov r1, #1
 *   @0x15f858 ldr r12, [r12, #0x2b0]
 *   @0x15f85c mov r3, r0
 *   @0x15f860 mov r0, r4
 *   @0x15f864 blx r12
 *   @0x15f868 bl 0x290274 <getJNIEnv>
 *   @0x15f86c ldr r1, [pc, #0x3c]
 *   @0x15f870 ldr r2, [pc, #0x3c]
 *   @0x15f874 mov r3, r9
 *   @0x15f878 ldr r1, [pc, r1]
 *   @0x15f87c ldr r2, [pc, r2]
 *   @0x15f880 ldr r1, [r1]
 *   @0x15f884 ldr r2, [r2]
 *   @0x15f888 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f88c mov r0, #1
 *   @0x15f890 add sp, sp, #68
 *   @0x15f894 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15f898 andseq r10, lr, r0, lsl #1
 *   @0x15f89c andseq pc, r12, r10, lsr r4
 *   @0x15f8a0 .word 0x0028dfd4
 *   @0x15f8a4 andseq r10, lr, r12, asr #1
 *   @0x15f8a8 andseq r9, lr, r0, asr #30
 *   @0x15f8ac ldrsheq pc, [r12], -r10
 *   @0x15f8b0 eoreq lr, r8, r12, lsr #2
 *   @0x15f8b4 eoreq r0, r9, r4, lsl #13
 *
 * ══ §25/54 Option_Init()  0x19f2d0  size 572  143 条（0x19f2d0..0x19f50c）
 * @func 0x19f2d0 0x19f50c  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19f2e0→0x5423c0, 0x19f2e8→0x5423bf, 0x19f2f0→0x5423be, 0x19f300→0x3f5080, 0x19f304→0x3f507c, 0x19f310→0x5423bd, 0x19f314→0x5423bc, 0x19f320→0x5423b8
 * 调用序列: 无
 * 字段偏移 top8: 0x18c×2 / 0x184×2 / 0x17c×2 / 0x164×2 / 0x14c×2 / 0x1ac×1 / 0x1a0×1 / 0x19c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f2d0 ldr r3, [pc, #0x1ac]
 *   @0x19f2d4 mov r2, #0
 *   @0x19f2d8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x19f2dc add r3, pc, r3
 *   @0x19f2e0 ldr r4, [pc, #0x1a0]
 *   @0x19f2e4 mov r1, #1
 *   @0x19f2e8 ldr r12, [pc, #0x19c]
 *   @0x19f2ec mov r7, #100
 *   @0x19f2f0 ldr r0, [pc, #0x198]
 *   @0x19f2f4 mvn r10, #-16777216
 *   @0x19f2f8 ldr r4, [r3, r4]
 *   @0x19f2fc mov r11, #255
 *   @0x19f300 ldr r8, [pc, #0x18c]
 *   @0x19f304 ldr r6, [pc, #0x18c]
 *   @0x19f308 strb r2, [r4]
 *   @0x19f30c ldr r12, [r3, r12]
 *   @0x19f310 ldr r5, [pc, #0x184]
 *   @0x19f314 ldr r4, [pc, #0x184]
 *   @0x19f318 strb r2, [r12]
 *   @0x19f31c ldr r9, [r3, r0]
 *   @0x19f320 ldr r12, [pc, #0x17c]
 *   @0x19f324 ldr r0, [pc, #0x17c]
 *   @0x19f328 strb r2, [r9]
 *   @0x19f32c ldr r8, [r3, r8]
 *   @0x19f330 ldr r9, [pc, #0x174]
 *   @0x19f334 strb r1, [r8]
 *   @0x19f338 ldr r6, [r3, r6]
 *   @0x19f33c ldr r8, [pc, #0x16c]
 *   @0x19f340 str r7, [r6]
 *   @0x19f344 ldr r5, [r3, r5]
 *   @0x19f348 ldr r7, [pc, #0x164]
 *   @0x19f34c ldr r6, [pc, #0x164]
 *   @0x19f350 strb r2, [r5]
 *   @0x19f354 ldr r4, [r3, r4]
 *   @0x19f358 ldr r5, [pc, #0x15c]
 *   @0x19f35c strb r2, [r4]
 *   @0x19f360 ldr r12, [r3, r12]
 *   @0x19f364 ldr r4, [pc, #0x154]
 *   @0x19f368 str r10, [r12]
 *   @0x19f36c ldr r10, [r3, r0]
 *   @0x19f370 ldr r12, [pc, #0x14c]
 *   @0x19f374 ldr r0, [pc, #0x14c]
 *   @0x19f378 strb r2, [r10]
 *   @0x19f37c ldr r10, [r3, r9]
 *   @0x19f380 ldr r9, [pc, #0x144]
 *   @0x19f384 str r2, [r10]
 *   @0x19f388 ldr r10, [r3, r8]
 *   @0x19f38c ldr r8, [pc, #0x13c]
 *   @0x19f390 str r2, [r10]
 *   @0x19f394 ldr r10, [r3, r7]
 *   @0x19f398 ldr r7, [pc, #0x134]
 *   @0x19f39c str r2, [r10]
 *   @0x19f3a0 ldr r10, [r3, r6]
 *   @0x19f3a4 ldr r6, [pc, #0x12c]
 *   @0x19f3a8 strb r2, [r10]
 *   @0x19f3ac ldr r10, [r3, r5]
 *   @0x19f3b0 ldr r5, [pc, #0x124]
 *   @0x19f3b4 strb r2, [r10]
 *   @0x19f3b8 ldr r10, [r3, r4]
 *   @0x19f3bc ldr r4, [pc, #0x11c]
 *   @0x19f3c0 str r2, [r10]
 *   @0x19f3c4 ldr r10, [r3, r12]
 *   @0x19f3c8 ldr r12, [pc, #0x114]
 *   @0x19f3cc strb r1, [r10]
 *   @0x19f3d0 ldr r10, [r3, r0]
 *   @0x19f3d4 ldr r0, [pc, #0x10c]
 *   @0x19f3d8 strb r1, [r10]
 *   @0x19f3dc ldr r10, [r3, r9]
 *   @0x19f3e0 ldr r9, [pc, #0x104]
 *   @0x19f3e4 strb r1, [r10]
 *   @0x19f3e8 ldr r10, [r3, r8]
 *   @0x19f3ec ldr r8, [pc, #0xfc]
 *   @0x19f3f0 strb r1, [r10]
 *   @0x19f3f4 ldr r10, [r3, r7]
 *   @0x19f3f8 ldr r7, [pc, #0xf4]
 *   @0x19f3fc strb r1, [r10]
 *   @0x19f400 ldr r10, [r3, r6]
 *   @0x19f404 ldr r6, [pc, #0xec]
 *   @0x19f408 strb r1, [r10]
 *   @0x19f40c ldr r10, [r3, r5]
 *   @0x19f410 ldr r5, [pc, #0xe4]
 *   @0x19f414 str r2, [r10]
 *   @0x19f418 ldr r10, [r3, r4]
 *   @0x19f41c ldr r4, [pc, #0xdc]
 *   @0x19f420 strb r1, [r10]
 *   @0x19f424 ldr r10, [r3, r12]
 *   @0x19f428 ldr r12, [pc, #0xd4]
 *   @0x19f42c strb r2, [r10]
 *   @0x19f430 ldr r10, [r3, r0]
 *   @0x19f434 ldr r0, [pc, #0xcc]
 *   @0x19f438 str r11, [r10]
 *   @0x19f43c ldr r9, [r3, r9]
 *   @0x19f440 strb r1, [r9]
 *   @0x19f444 ldr r8, [r3, r8]
 *   @0x19f448 strb r1, [r8]
 *   @0x19f44c ldr r1, [r3, r7]
 *   @0x19f450 strb r2, [r1]
 *   @0x19f454 ldr r1, [r3, r6]
 *   @0x19f458 strb r2, [r1]
 *   @0x19f45c ldr r1, [r3, r5]
 *   @0x19f460 strb r2, [r1]
 *   @0x19f464 ldr r1, [r3, r4]
 *   @0x19f468 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x19f46c str r2, [r1]
 *   @0x19f470 ldr r1, [r3, r12]
 *   @0x19f474 str r2, [r1]
 *   @0x19f478 ldr r3, [r3, r0]
 *   @0x19f47c str r2, [r3]
 *   @0x19f480 bx lr
 *   @0x19f484 eoreq r2, r5, r4, ror r9
 *   @0x19f488 .word 0xffffea98
 *   @0x19f48c .word 0xffffea9c
 *   @0x19f490 .word 0xffffeaa0
 *   @0x19f494 .word 0xffffd79c
 *   @0x19f498 .word 0xffffeaa4
 *   @0x19f49c .word 0xffffeaa8
 *   @0x19f4a0 .word 0xffffeaac
 *   @0x19f4a4 .word 0xffffeab0
 *   @0x19f4a8 .word 0xffffeab4
 *   @0x19f4ac .word 0xffffeab8
 *   @0x19f4b0 .word 0xffffeabc
 *   @0x19f4b4 .word 0xffffeac0
 *   @0x19f4b8 .word 0xffffeac4
 *   @0x19f4bc .word 0xffffeac8
 *   @0x19f4c0 .word 0xffffeacc
 *   @0x19f4c4 .word 0xffffead0
 *   @0x19f4c8 .word 0xffffead4
 *   @0x19f4cc .word 0xffffead8
 *   @0x19f4d0 .word 0xffffeadc
 *   @0x19f4d4 .word 0xffffeae0
 *   @0x19f4d8 .word 0xffffeae4
 *   @0x19f4dc .word 0xffffeae8
 *   @0x19f4e0 .word 0xffffeaec
 *   @0x19f4e4 .word 0xffffeaf0
 *   @0x19f4e8 .word 0xffffeaf4
 *   @0x19f4ec .word 0xffffeaf8
 *   @0x19f4f0 .word 0xffffc158
 *   @0x19f4f4 .word 0xffffeafc
 *   @0x19f4f8 .word 0xffffc144
 *   @0x19f4fc .word 0xffffeb00
 *   @0x19f500 .word 0xffffc184
 *   @0x19f504 .word 0xffffc188
 *   @0x19f508 .word 0xffffc18c
 *
 * ══ §26/54 Eff_Effect02(int, float, float, int, unsigned int)  0x1a0848  size 572  143 条（0x1a0848..0x1a0a84）
 * @func 0x1a0848 0x1a0a84  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a0874→0x54244c
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Alpha2(int, float, float)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Scale(int, float, float)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×7 / 0x8×6 / 0x208×1 / 0x204×1 / 0x30×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0848 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a084c vpush {d8}
 *   @0x1a0850 sub sp, sp, #12
 *   @0x1a0854 mov r4, r3
 *   @0x1a0858 mov r7, r1
 *   @0x1a085c mov r8, r0
 *   @0x1a0860 mov r6, r2
 *   @0x1a0864 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a0868 cmp r4, #0
 *   @0x1a086c ldr r12, [pc, #0x208]
 *   @0x1a0870 mov r1, #6
 *   @0x1a0874 ldr r3, [pc, #0x204]
 *   @0x1a0878 mov r5, #0
 *   @0x1a087c add r12, pc, r12
 *   @0x1a0880 vmov s16, r0
 *   @0x1a0884 beq 0x1a094c <_Z12Eff_Effect02iffij+0x104>
 *   @0x1a0888 cmp r4, #2
 *   @0x1a088c ldr r4, [r12, r3]
 *   @0x1a0890 beq 0x1a09e0 <_Z12Eff_Effect02iffij+0x198>
 *   @0x1a0894 ldr r0, [r4, #0x4]
 *   @0x1a0898 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a089c mov r2, r5
 *   @0x1a08a0 ldr r0, [r4, #0x4]
 *   @0x1a08a4 mov r1, #1065353216
 *   @0x1a08a8 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a08ac vldr s15, [pc, #444]
 *   @0x1a08b0 vmul.f32 s15, s16, s15
 *   @0x1a08b4 mov r1, r5
 *   @0x1a08b8 ldr r0, [r4, #0x4]
 *   @0x1a08bc mov r2, r5
 *   @0x1a08c0 str r5, [sp]
 *   @0x1a08c4 vmov r3, s15
 *   @0x1a08c8 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a08cc mov r2, #1056964608
 *   @0x1a08d0 ldr r0, [r4, #0x4]
 *   @0x1a08d4 mov r1, #1065353216
 *   @0x1a08d8 bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a08dc vmov.f32 s15, #1.300000e+01
 *   @0x1a08e0 ldr r9, [r4, #0x4]
 *   @0x1a08e4 vdiv.f32 s15, s15, s16
 *   @0x1a08e8 vcvt.f64.f32 d6, s15
 *   @0x1a08ec vmov r0, r1, d6
 *   @0x1a08f0 bl 0xb66e8 <lrint@plt>
 *   @0x1a08f4 vmov.f32 s15, #1.500000e+01
 *   @0x1a08f8 vdiv.f32 s16, s15, s16
 *   @0x1a08fc mov r5, r0
 *   @0x1a0900 vcvt.f64.f32 d7, s16
 *   @0x1a0904 vmov r0, r1, d7
 *   @0x1a0908 bl 0xb66e8 <lrint@plt>
 *   @0x1a090c mov r1, r5
 *   @0x1a0910 mov r2, r0
 *   @0x1a0914 mov r0, r9
 *   @0x1a0918 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a091c ldr r3, [r4, #0x4]
 *   @0x1a0920 ldr r2, [sp, #0x30]
 *   @0x1a0924 mov r12, #1
 *   @0x1a0928 mov r0, r8
 *   @0x1a092c mov r1, r7
 *   @0x1a0930 str r12, [sp, #0x4]
 *   @0x1a0934 str r2, [sp]
 *   @0x1a0938 mov r2, r6
 *   @0x1a093c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0940 add sp, sp, #12
 *   @0x1a0944 vpop {d8}
 *   @0x1a0948 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a094c ldr r4, [r12, r3]
 *   @0x1a0950 ldr r0, [r4]
 *   @0x1a0954 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0958 mov r2, r5
 *   @0x1a095c ldr r0, [r4]
 *   @0x1a0960 mov r1, #1065353216
 *   @0x1a0964 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0968 vldr s15, [pc, #260]
 *   @0x1a096c vmul.f32 s15, s16, s15
 *   @0x1a0970 mov r1, r5
 *   @0x1a0974 ldr r0, [r4]
 *   @0x1a0978 mov r2, r5
 *   @0x1a097c str r5, [sp]
 *   @0x1a0980 vmov r3, s15
 *   @0x1a0984 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0988 mov r2, #1056964608
 *   @0x1a098c ldr r0, [r4]
 *   @0x1a0990 mov r1, #1065353216
 *   @0x1a0994 bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a0998 vmov.f32 s15, #1.000000e+01
 *   @0x1a099c ldr r9, [r4]
 *   @0x1a09a0 vdiv.f32 s15, s15, s16
 *   @0x1a09a4 vcvt.f64.f32 d6, s15
 *   @0x1a09a8 vmov r0, r1, d6
 *   @0x1a09ac bl 0xb66e8 <lrint@plt>
 *   @0x1a09b0 vmov.f32 s15, #1.200000e+01
 *   @0x1a09b4 vdiv.f32 s16, s15, s16
 *   @0x1a09b8 mov r5, r0
 *   @0x1a09bc vcvt.f64.f32 d7, s16
 *   @0x1a09c0 vmov r0, r1, d7
 *   @0x1a09c4 bl 0xb66e8 <lrint@plt>
 *   @0x1a09c8 mov r1, r5
 *   @0x1a09cc mov r2, r0
 *   @0x1a09d0 mov r0, r9
 *   @0x1a09d4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a09d8 ldr r3, [r4]
 *   @0x1a09dc b 0x1a0920 <_Z12Eff_Effect02iffij+0xd8>
 *   @0x1a09e0 ldr r0, [r4, #0x8]
 *   @0x1a09e4 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a09e8 mov r2, r5
 *   @0x1a09ec ldr r0, [r4, #0x8]
 *   @0x1a09f0 mov r1, #1065353216
 *   @0x1a09f4 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a09f8 vldr s15, [pc, #120]
 *   @0x1a09fc vmul.f32 s15, s16, s15
 *   @0x1a0a00 mov r1, r5
 *   @0x1a0a04 ldr r0, [r4, #0x8]
 *   @0x1a0a08 mov r2, r5
 *   @0x1a0a0c str r5, [sp]
 *   @0x1a0a10 vmov r3, s15
 *   @0x1a0a14 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0a18 mov r2, #1056964608
 *   @0x1a0a1c ldr r0, [r4, #0x8]
 *   @0x1a0a20 mov r1, #1065353216
 *   @0x1a0a24 bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a0a28 vmov.f32 s15, #1.800000e+01
 *   @0x1a0a2c ldr r9, [r4, #0x8]
 *   @0x1a0a30 vdiv.f32 s15, s15, s16
 *   @0x1a0a34 vcvt.f64.f32 d6, s15
 *   @0x1a0a38 vmov r0, r1, d6
 *   @0x1a0a3c bl 0xb66e8 <lrint@plt>
 *   @0x1a0a40 vmov.f32 s15, #2.000000e+01
 *   @0x1a0a44 vdiv.f32 s16, s15, s16
 *   @0x1a0a48 mov r5, r0
 *   @0x1a0a4c vcvt.f64.f32 d7, s16
 *   @0x1a0a50 vmov r0, r1, d7
 *   @0x1a0a54 bl 0xb66e8 <lrint@plt>
 *   @0x1a0a58 mov r1, r5
 *   @0x1a0a5c mov r2, r0
 *   @0x1a0a60 mov r0, r9
 *   @0x1a0a64 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0a68 ldr r3, [r4, #0x8]
 *   @0x1a0a6c b 0x1a0920 <_Z12Eff_Effect02iffij+0xd8>
 *   @0x1a0a70 mrclo p3, #0x5, r3, c3, c3, #0x1
 *   @0x1a0a74 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x1a0a78 svclo #0x19999a
 *   @0x1a0a7c .word 0x002513d4
 *   @0x1a0a80 .word 0xffffeb28
 *
 * ══ §27/54 base64_decode(char const*, unsigned int, char*, bool)  0x1d1ff0  size 572  143 条（0x1d1ff0..0x1d222c）
 * @func 0x1d1ff0 0x1d222c  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / base64_decode(char const*, unsigned int, char*, bool)+0x228 / base64_decode(char const*, unsigned int, char*, bool)+0x220
 * 字段偏移 top8: 0x1×5 / 0x4×2 / 0xd×2 / 0xe×2 / 0xc×2 / 0xf×2 / 0x9×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1ff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d1ff4 sub sp, sp, #20
 *   @0x1d1ff8 mov r5, r1
 *   @0x1d1ffc mov r4, r2
 *   @0x1d2000 str r3, [sp, #0x4]
 *   @0x1d2004 mov r6, r0
 *   @0x1d2008 bl 0xb6538 <strlen@plt>
 *   @0x1d200c ldr r3, [pc, #0x20c]
 *   @0x1d2010 sub r12, r5, #1
 *   @0x1d2014 mov r2, #0
 *   @0x1d2018 add r12, r4, r12
 *   @0x1d201c add r5, sp, #15
 *   @0x1d2020 add r3, pc, r3
 *   @0x1d2024 mov r1, r2
 *   @0x1d2028 cmp r2, r0
 *   @0x1d202c beq 0x1d2084 <_Z13base64_decodePKcjPcb+0x94>
 *   @0x1d2030 ldrb r7, [r6, r2]
 *   @0x1d2034 cmp r7, #61
 *   @0x1d2038 beq 0x1d2084 <_Z13base64_decodePKcjPcb+0x94>
 *   @0x1d203c ldr r8, [pc, #0x1e0]
 *   @0x1d2040 ldr r8, [pc, r8]
 *   @0x1d2044 ldr r8, [r8]
 *   @0x1d2048 add r8, r8, r7
 *   @0x1d204c ldrb r8, [r8, #0x1]
 *   @0x1d2050 tst r8, #7
 *   @0x1d2054 beq 0x1d2200 <_Z13base64_decodePKcjPcb+0x210>
 *   @0x1d2058 add r8, r1, #1
 *   @0x1d205c add r9, sp, #16
 *   @0x1d2060 add r1, r9, r1
 *   @0x1d2064 cmp r8, #4
 *   @0x1d2068 add r2, r2, #1
 *   @0x1d206c addeq r9, sp, #11
 *   @0x1d2070 strb r7, [r1, #-0x4]
 *   @0x1d2074 beq 0x1d2180 <_Z13base64_decodePKcjPcb+0x190>
 *   @0x1d2078 cmp r2, r0
 *   @0x1d207c mov r1, r8
 *   @0x1d2080 bne 0x1d2030 <_Z13base64_decodePKcjPcb+0x40>
 *   @0x1d2084 subs r6, r1, #0
 *   @0x1d2088 beq 0x1d214c <_Z13base64_decodePKcjPcb+0x15c>
 *   @0x1d208c cmp r1, #3
 *   @0x1d2090 bgt 0x1d20ac <_Z13base64_decodePKcjPcb+0xbc>
 *   @0x1d2094 add r2, sp, #12
 *   @0x1d2098 mov r3, #0
 *   @0x1d209c strb r3, [r2, r1]
 *   @0x1d20a0 add r1, r1, #1
 *   @0x1d20a4 cmp r1, #4
 *   @0x1d20a8 bne 0x1d209c <_Z13base64_decodePKcjPcb+0xac>
 *   @0x1d20ac ldr r0, [pc, #0x174]
 *   @0x1d20b0 add r5, sp, #11
 *   @0x1d20b4 add r7, sp, #15
 *   @0x1d20b8 add r0, pc, r0
 *   @0x1d20bc ldrb r1, [r5, #0x1]
 *   @0x1d20c0 mov r3, #64
 *   @0x1d20c4 b 0x1d20d0 <_Z13base64_decodePKcjPcb+0xe0>
 *   @0x1d20c8 subs r3, r3, #1
 *   @0x1d20cc blo 0x1d2218 <_Z13base64_decodePKcjPcb+0x228>
 *   @0x1d20d0 ldrb r2, [r3, r0]
 *   @0x1d20d4 cmp r2, r1
 *   @0x1d20d8 bne 0x1d20c8 <_Z13base64_decodePKcjPcb+0xd8>
 *   @0x1d20dc uxtb r3, r3
 *   @0x1d20e0 strb r3, [r5, #0x1]!
 *   @0x1d20e4 cmp r5, r7
 *   @0x1d20e8 bne 0x1d20bc <_Z13base64_decodePKcjPcb+0xcc>
 *   @0x1d20ec ldrb r2, [sp, #0xd]
 *   @0x1d20f0 cmp r6, #1
 *   @0x1d20f4 ldrb r3, [sp, #0xe]
 *   @0x1d20f8 ldrb r7, [sp, #0xc]
 *   @0x1d20fc ubfx r0, r2, #0x4, #0x2
 *   @0x1d2100 ldrb r1, [sp, #0xf]
 *   @0x1d2104 ubfx r5, r3, #0x2, #0x4
 *   @0x1d2108 add r2, r5, r2, lsl #4
 *   @0x1d210c strb r2, [sp, #0x9]
 *   @0x1d2110 add r0, r0, r7, lsl #2
 *   @0x1d2114 add r3, r1, r3, lsl #6
 *   @0x1d2118 strb r0, [sp, #0x8]
 *   @0x1d211c strb r3, [sp, #0xa]
 *   @0x1d2120 beq 0x1d214c <_Z13base64_decodePKcjPcb+0x15c>
 *   @0x1d2124 sub r6, r6, #1
 *   @0x1d2128 mov r3, #0
 *   @0x1d212c cmp r12, r4
 *   @0x1d2130 add r2, sp, #8
 *   @0x1d2134 ldrbhi r2, [r3, r2]
 *   @0x1d2138 add r3, r3, #1
 *   @0x1d213c strbhi r2, [r4]
 *   @0x1d2140 addhi r4, r4, #1
 *   @0x1d2144 cmp r3, r6
 *   @0x1d2148 bne 0x1d212c <_Z13base64_decodePKcjPcb+0x13c>
 *   @0x1d214c ldr r3, [sp, #0x4]
 *   @0x1d2150 cmp r4, r12
 *   @0x1d2154 movhs r3, #0
 *   @0x1d2158 andlo r3, r3, #1
 *   @0x1d215c cmp r3, #0
 *   @0x1d2160 movne r3, #0
 *   @0x1d2164 strbne r3, [r4]
 *   @0x1d2168 add sp, sp, #20
 *   @0x1d216c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d2170 uxtb r1, r1
 *   @0x1d2174 strb r1, [r9, #0x1]!
 *   @0x1d2178 cmp r9, r5
 *   @0x1d217c beq 0x1d21a4 <_Z13base64_decodePKcjPcb+0x1b4>
 *   @0x1d2180 ldrb r8, [r9, #0x1]
 *   @0x1d2184 mov r1, #64
 *   @0x1d2188 b 0x1d2194 <_Z13base64_decodePKcjPcb+0x1a4>
 *   @0x1d218c subs r1, r1, #1
 *   @0x1d2190 blo 0x1d2210 <_Z13base64_decodePKcjPcb+0x220>
 *   @0x1d2194 ldrb r7, [r1, r3]
 *   @0x1d2198 cmp r7, r8
 *   @0x1d219c bne 0x1d218c <_Z13base64_decodePKcjPcb+0x19c>
 *   @0x1d21a0 b 0x1d2170 <_Z13base64_decodePKcjPcb+0x180>
 *   @0x1d21a4 ldrb r8, [sp, #0xd]
 *   @0x1d21a8 mov r1, #0
 *   @0x1d21ac ldrb r11, [sp, #0xc]
 *   @0x1d21b0 ldrb r7, [sp, #0xe]
 *   @0x1d21b4 ubfx r10, r8, #0x4, #0x2
 *   @0x1d21b8 ldrb r9, [sp, #0xf]
 *   @0x1d21bc add r11, r10, r11, lsl #2
 *   @0x1d21c0 ubfx r10, r7, #0x2, #0x4
 *   @0x1d21c4 add r8, r10, r8, lsl #4
 *   @0x1d21c8 add r7, r9, r7, lsl #6
 *   @0x1d21cc strb r11, [sp, #0x8]
 *   @0x1d21d0 strb r8, [sp, #0x9]
 *   @0x1d21d4 strb r7, [sp, #0xa]
 *   @0x1d21d8 cmp r12, r4
 *   @0x1d21dc add r7, sp, #8
 *   @0x1d21e0 ldrbhi r7, [r1, r7]
 *   @0x1d21e4 add r1, r1, #1
 *   @0x1d21e8 strbhi r7, [r4]
 *   @0x1d21ec addhi r4, r4, #1
 *   @0x1d21f0 cmp r1, #3
 *   @0x1d21f4 bne 0x1d21d8 <_Z13base64_decodePKcjPcb+0x1e8>
 *   @0x1d21f8 mov r1, #0
 *   @0x1d21fc b 0x1d2028 <_Z13base64_decodePKcjPcb+0x38>
 *   @0x1d2200 and r8, r7, #251
 *   @0x1d2204 cmp r8, #43
 *   @0x1d2208 beq 0x1d2058 <_Z13base64_decodePKcjPcb+0x68>
 *   @0x1d220c b 0x1d2084 <_Z13base64_decodePKcjPcb+0x94>
 *   @0x1d2210 mov r1, #255
 *   @0x1d2214 b 0x1d2174 <_Z13base64_decodePKcjPcb+0x184>
 *   @0x1d2218 mov r3, #255
 *   @0x1d221c b 0x1d20e0 <_Z13base64_decodePKcjPcb+0xf0>
 *   @0x1d2220 andseq r11, r8, r12, lsr #27
 *   @0x1d2224 eoreq r11, r1, r0, asr #18
 *   @0x1d2228 andseq r11, r8, r4, lsl sp
 *
 * ══ §28/54 VARI_Load(unsigned char*, unsigned int, unsigned char*)  0x1dca8c  size 572  143 条（0x1dca8c..0x1dccc8）
 * @func 0x1dca8c 0x1dccc8  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dca9c→0x544b50, 0x1dcaa8→0x544b48, 0x1dcaac→0x544b4c, 0x1dcab8→0x544b5c, 0x1dcb0c→0x3eb6b8, 0x1dcba8→0x544c44, 0x1dcc64→0x7590d2
 * 调用序列: Code_Variable_Find_Set(char const*, int, int)×2 / Code_Variable_Init(int, int, int) / VARI_Load(unsigned char*, unsigned int, unsigned char*)+0x1cc / VARI_Load(unsigned char*, unsigned int, unsigned char*)+0x194 / 0xb6574 / YYError(char const*, ...) / YYGML_game_end() / 0xb6688
 * 字段偏移 top8: 0xc×4 / 0x1e8×2 / 0x124×2 / 0x1f4×1 / 0x1f0×1 / 0x1e0×1 / 0x8×1 / 0x190×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dca8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dca90 mov r3, #0
 *   @0x1dca94 ldr r7, [pc, #0x1f4]
 *   @0x1dca98 mov r11, r0
 *   @0x1dca9c ldr r12, [pc, #0x1f0]
 *   @0x1dcaa0 mov r6, r1
 *   @0x1dcaa4 add r7, pc, r7
 *   @0x1dcaa8 ldr r8, [pc, #0x1e8]
 *   @0x1dcaac ldr r4, [pc, #0x1e8]
 *   @0x1dcab0 mov r10, r2
 *   @0x1dcab4 ldr r5, [r7, r12]
 *   @0x1dcab8 ldr r12, [pc, #0x1e0]
 *   @0x1dcabc str r3, [r5]
 *   @0x1dcac0 ldr r8, [r7, r8]
 *   @0x1dcac4 str r3, [r8]
 *   @0x1dcac8 ldr r4, [r7, r4]
 *   @0x1dcacc str r3, [r4]
 *   @0x1dcad0 ldr r3, [r7, r12]
 *   @0x1dcad4 ldrb r3, [r3]
 *   @0x1dcad8 cmp r3, #0
 *   @0x1dcadc beq 0x1dcc80 <_Z9VARI_LoadPhjS_+0x1f4>
 *   @0x1dcae0 ldm r0, {r0, r1}
 *   @0x1dcae4 sub r6, r6, #12
 *   @0x1dcae8 ldr r3, [r11, #0x8]
 *   @0x1dcaec add r11, r11, #12
 *   @0x1dcaf0 cmp r1, #0
 *   @0x1dcaf4 str r0, [r4]
 *   @0x1dcaf8 moveq r1, #2
 *   @0x1dcafc mov r2, r3
 *   @0x1dcb00 str r1, [r8]
 *   @0x1dcb04 str r3, [r5]
 *   @0x1dcb08 bl 0xd1d80 <_Z18Code_Variable_Initiii>
 *   @0x1dcb0c ldr r3, [pc, #0x190]
 *   @0x1dcb10 ldr r2, [r4]
 *   @0x1dcb14 ldr r1, [pc, #0x18c]
 *   @0x1dcb18 ldr r3, [r7, r3]
 *   @0x1dcb1c add r1, pc, r1
 *   @0x1dcb20 ldr r4, [r3]
 *   @0x1dcb24 ldr r3, [r4]
 *   @0x1dcb28 mov r0, r4
 *   @0x1dcb2c ldr r3, [r3, #0xc]
 *   @0x1dcb30 blx r3
 *   @0x1dcb34 ldr r3, [r4]
 *   @0x1dcb38 ldr r1, [pc, #0x16c]
 *   @0x1dcb3c mov r0, r4
 *   @0x1dcb40 ldr r2, [r8]
 *   @0x1dcb44 add r1, pc, r1
 *   @0x1dcb48 ldr r3, [r3, #0xc]
 *   @0x1dcb4c blx r3
 *   @0x1dcb50 ldr r3, [r4]
 *   @0x1dcb54 ldr r1, [pc, #0x154]
 *   @0x1dcb58 mov r0, r4
 *   @0x1dcb5c ldr r2, [r5]
 *   @0x1dcb60 add r1, pc, r1
 *   @0x1dcb64 ldr r3, [r3, #0xc]
 *   @0x1dcb68 blx r3
 *   @0x1dcb6c ldr r0, [pc, #0x140]
 *   @0x1dcb70 movw r2, #0x9680
 *   @0x1dcb74 mvn r1, #0
 *   @0x1dcb78 add r0, pc, r0
 *   @0x1dcb7c movt r2, #0x98
 *   @0x1dcb80 bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii>
 *   @0x1dcb84 cmp r6, #0
 *   @0x1dcb88 beq 0x1dcc28 <_Z9VARI_LoadPhjS_+0x19c>
 *   @0x1dcb8c ldr r8, [pc, #0x124]
 *   @0x1dcb90 ldr r9, [pc, #0x124]
 *   @0x1dcb94 add r8, pc, r8
 *   @0x1dcb98 add r9, pc, r9
 *   @0x1dcb9c ldr r0, [r11]
 *   @0x1dcba0 cmp r0, #0
 *   @0x1dcba4 moveq r5, r0
 *   @0x1dcba8 ldrne r3, [pc, #0x110]
 *   @0x1dcbac ldrne r3, [r7, r3]
 *   @0x1dcbb0 ldrne r5, [r3]
 *   @0x1dcbb4 addne r5, r5, r0
 *   @0x1dcbb8 ldmib r11, {r1, r4}
 *   @0x1dcbbc cmn r4, #6
 *   @0x1dcbc0 beq 0x1dcc30 <_Z9VARI_LoadPhjS_+0x1a4>
 *   @0x1dcbc4 mov r2, r4
 *   @0x1dcbc8 mov r0, r5
 *   @0x1dcbcc bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii>
 *   @0x1dcbd0 subs r4, r0, #0
 *   @0x1dcbd4 blt 0x1dcc58 <_Z9VARI_LoadPhjS_+0x1cc>
 *   @0x1dcbd8 ldr r1, [r11, #0xc]
 *   @0x1dcbdc sub r6, r6, #20
 *   @0x1dcbe0 ldr r3, [r11, #0x10]
 *   @0x1dcbe4 add r11, r11, #20
 *   @0x1dcbe8 cmp r1, #0
 *   @0x1dcbec bicgt r0, r4, #-268435456
 *   @0x1dcbf0 movgt r12, #0
 *   @0x1dcbf4 ble 0x1dcc20 <_Z9VARI_LoadPhjS_+0x194>
 *   @0x1dcbf8 add r4, r3, #4
 *   @0x1dcbfc add r12, r12, #1
 *   @0x1dcc00 cmp r12, r1
 *   @0x1dcc04 ldr r5, [r10, r4]
 *   @0x1dcc08 and r2, r5, #-268435456
 *   @0x1dcc0c sbfx r5, r5, #0x0, #0x1c
 *   @0x1dcc10 orr r2, r2, r0
 *   @0x1dcc14 add r3, r3, r5
 *   @0x1dcc18 str r2, [r10, r4]
 *   @0x1dcc1c bne 0x1dcbf8 <_Z9VARI_LoadPhjS_+0x16c>
 *   @0x1dcc20 cmp r6, #0
 *   @0x1dcc24 bne 0x1dcb9c <_Z9VARI_LoadPhjS_+0x110>
 *   @0x1dcc28 mov r0, #1
 *   @0x1dcc2c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dcc30 mov r1, r8
 *   @0x1dcc34 mov r0, r5
 *   @0x1dcc38 bl 0xb6574 <strcmp@plt>
 *   @0x1dcc3c movw r3, #0x9680
 *   @0x1dcc40 movt r3, #0x98
 *   @0x1dcc44 cmp r0, #0
 *   @0x1dcc48 moveq r4, r3
 *   @0x1dcc4c mvnne r1, #5
 *   @0x1dcc50 mvneq r1, #0
 *   @0x1dcc54 b 0x1dcbc4 <_Z9VARI_LoadPhjS_+0x138>
 *   @0x1dcc58 mov r1, r5
 *   @0x1dcc5c mov r0, r9
 *   @0x1dcc60 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x1dcc64 ldr r3, [pc, #0x58]
 *   @0x1dcc68 ldr r3, [r7, r3]
 *   @0x1dcc6c ldrb r3, [r3]
 *   @0x1dcc70 cmp r3, #0
 *   @0x1dcc74 beq 0x1dcc88 <_Z9VARI_LoadPhjS_+0x1fc>
 *   @0x1dcc78 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1dcc7c b 0x1dcbd8 <_Z9VARI_LoadPhjS_+0x14c>
 *   @0x1dcc80 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dcc84 b 0x1dc960 <_Z13OLD_VARI_LoadPhjS_>
 *   @0x1dcc88 mov r0, #1
 *   @0x1dcc8c bl 0xb6688 <exit@plt>
 *   @0x1dcc90 eoreq r5, r1, r12, lsr #3
 *   @0x1dcc94 .word 0xffffc104
 *   @0x1dcc98 .word 0xffffc0c4
 *   @0x1dcc9c .word 0xffffc0b8
 *   @0x1dcca0 .word 0xffffbf04
 *   @0x1dcca4 .word 0xffffdecc
 *   @0x1dcca8 andseq r4, r7, r4, lsr #23
 *   @0x1dccac mulseq r7, r8, r11
 *   @0x1dccb0 mulseq r7, r8, r11
 *   @0x1dccb4 mulseq r7, r8, r11
 *   @0x1dccb8 andseq r4, r7, r12, ror r11
 *   @0x1dccbc ldrsheq r4, [r7], -r12
 *   @0x1dccc0 .word 0xffffbcf4
 *   @0x1dccc4 .word 0xffffbfe0
 *
 * ══ §29/54 CSprite::LoadFromFile(char const*, int, bool, bool, bool, bool, int, int, bool)  0x1e7270  size 572  143 条（0x1e7270..0x1e74ac）
 * @func 0x1e7270 0x1e74ac  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / CSprite::LoadFromFile(char const*, int, bool, bool, bool, bool, int, int, bool)+0x50 / 0xb66d0 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / CSprite::LoadFromGIFData(void*, int, int, bool, bool, bool, int, int, bool) / CSprite::LoadFromPNGData(void*, int, int, bool, bool, bool, int, int, bool) / LoadSave::BundleFileExists(char const*)
 * 字段偏移 top8: 0x58×6 / 0x1c×4 / 0x54×3 / 0xc×3 / 0x4×3 / 0x8×3 / 0x10×3 / 0x14×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7270 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e7274 mov r5, r0
 *   @0x1e7278 sub sp, sp, #36
 *   @0x1e727c mov r0, r1
 *   @0x1e7280 mov r4, r1
 *   @0x1e7284 mov r6, r2
 *   @0x1e7288 mov r7, r3
 *   @0x1e728c bl 0xb6538 <strlen@plt>
 *   @0x1e7290 ldrb r8, [sp, #0x48]
 *   @0x1e7294 ldrb r9, [sp, #0x4c]
 *   @0x1e7298 ldrb r10, [sp, #0x5c]
 *   @0x1e729c cmp r0, #4
 *   @0x1e72a0 ble 0x1e72c0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x50>
 *   @0x1e72a4 sub r1, r0, #5
 *   @0x1e72a8 ldr r0, [pc, #0x1f8]
 *   @0x1e72ac add r1, r4, r1
 *   @0x1e72b0 add r0, pc, r0
 *   @0x1e72b4 bl 0xb66d0 <strcasecmp@plt>
 *   @0x1e72b8 cmp r0, #0
 *   @0x1e72bc beq 0x1e73d0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x160>
 *   @0x1e72c0 mov r0, r4
 *   @0x1e72c4 mov r3, #0
 *   @0x1e72c8 str r3, [sp, #0x1c]
 *   @0x1e72cc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1e72d0 cmp r0, #0
 *   @0x1e72d4 beq 0x1e73a4 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x134>
 *   @0x1e72d8 mov r0, r4
 *   @0x1e72dc add r1, sp, #28
 *   @0x1e72e0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x1e72e4 mov r11, r0
 *   @0x1e72e8 cmp r11, #0
 *   @0x1e72ec moveq r4, r11
 *   @0x1e72f0 beq 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c>
 *   @0x1e72f4 ldrb r3, [r11]
 *   @0x1e72f8 cmp r3, #255
 *   @0x1e72fc beq 0x1e7410 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x1a0>
 *   @0x1e7300 cmp r3, #71
 *   @0x1e7304 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e7308 ldrb r3, [r11, #0x1]
 *   @0x1e730c cmp r3, #73
 *   @0x1e7310 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e7314 ldrb r3, [r11, #0x2]
 *   @0x1e7318 cmp r3, #70
 *   @0x1e731c bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e7320 ldrb r3, [r11, #0x3]
 *   @0x1e7324 cmp r3, #56
 *   @0x1e7328 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e732c ldr r2, [sp, #0x54]
 *   @0x1e7330 mov r0, r5
 *   @0x1e7334 ldr r12, [sp, #0x58]
 *   @0x1e7338 mov r1, r11
 *   @0x1e733c str r7, [sp]
 *   @0x1e7340 mov r3, r6
 *   @0x1e7344 str r2, [sp, #0xc]
 *   @0x1e7348 str r8, [sp, #0x4]
 *   @0x1e734c str r9, [sp, #0x8]
 *   @0x1e7350 str r12, [sp, #0x10]
 *   @0x1e7354 str r10, [sp, #0x14]
 *   @0x1e7358 ldr r2, [sp, #0x1c]
 *   @0x1e735c bl 0x1e71d8 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib>
 *   @0x1e7360 subs r4, r0, #0
 *   @0x1e7364 bne 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c>
 *   @0x1e7368 ldr r12, [sp, #0x54]
 *   @0x1e736c mov r0, r5
 *   @0x1e7370 ldr r2, [sp, #0x1c]
 *   @0x1e7374 mov r3, r6
 *   @0x1e7378 str r7, [sp]
 *   @0x1e737c mov r1, r11
 *   @0x1e7380 str r12, [sp, #0xc]
 *   @0x1e7384 ldr r12, [sp, #0x58]
 *   @0x1e7388 str r8, [sp, #0x4]
 *   @0x1e738c str r9, [sp, #0x8]
 *   @0x1e7390 str r12, [sp, #0x10]
 *   @0x1e7394 str r10, [sp, #0x14]
 *   @0x1e7398 bl 0x1e70b0 <_ZN7CSprite15LoadFromPNGDataEPviibbbiib>
 *   @0x1e739c mov r4, r0
 *   @0x1e73a0 b 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c>
 *   @0x1e73a4 mov r0, r4
 *   @0x1e73a8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1e73ac cmp r0, #0
 *   @0x1e73b0 moveq r11, r0
 *   @0x1e73b4 moveq r4, r11
 *   @0x1e73b8 bne 0x1e7494 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x224>
 *   @0x1e73bc mov r0, r11
 *   @0x1e73c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e73c4 mov r0, r4
 *   @0x1e73c8 add sp, sp, #36
 *   @0x1e73cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e73d0 mov r0, #12
 *   @0x1e73d4 bl 0x27c524 <_Znwj>
 *   @0x1e73d8 mov r1, r4
 *   @0x1e73dc mov r11, r0
 *   @0x1e73e0 bl 0xbdbe0 <_ZN15CSkeletonSpriteC2EPc>
 *   @0x1e73e4 str r11, [r5, #0x58]
 *   @0x1e73e8 mov r0, r11
 *   @0x1e73ec bl 0xbd96c <_ZN15CSkeletonSprite7HasDataEv>
 *   @0x1e73f0 cmp r0, #0
 *   @0x1e73f4 beq 0x1e746c <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x1fc>
 *   @0x1e73f8 mvn r2, #-2147483648
 *   @0x1e73fc mov r3, #2
 *   @0x1e7400 str r2, [r5, #0x18]
 *   @0x1e7404 mov r4, #1
 *   @0x1e7408 str r3, [r5, #0x74]
 *   @0x1e740c b 0x1e73c4 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x154>
 *   @0x1e7410 ldrb r3, [r11, #0x1]
 *   @0x1e7414 cmp r3, #216
 *   @0x1e7418 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e741c ldrb r3, [r11, #0x2]
 *   @0x1e7420 cmp r3, #255
 *   @0x1e7424 bne 0x1e7368 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0xf8>
 *   @0x1e7428 ldr r12, [sp, #0x54]
 *   @0x1e742c mov r0, r5
 *   @0x1e7430 ldr r2, [sp, #0x1c]
 *   @0x1e7434 mov r1, r11
 *   @0x1e7438 str r7, [sp]
 *   @0x1e743c mov r3, r6
 *   @0x1e7440 str r12, [sp, #0xc]
 *   @0x1e7444 ldr r12, [sp, #0x58]
 *   @0x1e7448 str r8, [sp, #0x4]
 *   @0x1e744c str r9, [sp, #0x8]
 *   @0x1e7450 str r12, [sp, #0x10]
 *   @0x1e7454 str r10, [sp, #0x14]
 *   @0x1e7458 bl 0x1e7140 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib>
 *   @0x1e745c subs r4, r0, #0
 *   @0x1e7460 bne 0x1e73bc <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x14c>
 *   @0x1e7464 ldrb r3, [r11]
 *   @0x1e7468 b 0x1e7300 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x90>
 *   @0x1e746c ldr r11, [r5, #0x58]
 *   @0x1e7470 cmp r11, #0
 *   @0x1e7474 beq 0x1e7488 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x218>
 *   @0x1e7478 mov r0, r11
 *   @0x1e747c bl 0xbd910 <_ZN15CSkeletonSpriteD2Ev>
 *   @0x1e7480 mov r0, r11
 *   @0x1e7484 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e7488 mov r3, #0
 *   @0x1e748c str r3, [r5, #0x58]
 *   @0x1e7490 b 0x1e72c0 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x50>
 *   @0x1e7494 mov r0, r4
 *   @0x1e7498 add r1, sp, #28
 *   @0x1e749c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x1e74a0 mov r11, r0
 *   @0x1e74a4 b 0x1e72e8 <_ZN7CSprite12LoadFromFileEPKcibbbbiib+0x78>
 *   @0x1e74a8 andseq r11, r6, r12, lsr r3
 *
 * ══ §30/54 YYObject_PropertyNameIterator::Next(RValue*)  0x24a1fc  size 572  143 条（0x24a1fc..0x24a438）
 * @func 0x24a1fc 0x24a438  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetProperty(YYObjectBase*, RValue*, char const*)×2 / YYObject_PropertyNameIterator::Next(RValue*)×2 / YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*) / 0xb6538 / YYObject_PropertyNameIterator::Next(RValue*)+0x9c / FREE_RValue__Pre(RValue*) / operator new(unsigned int) / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int)
 * 字段偏移 top8: 0x14×5 / 0xc×5 / 0x18×5 / 0x10×4 / 0x4×3 / 0x24×2 / 0x34×2 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a1fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24a200 sub sp, sp, #60
 *   @0x24a204 add r4, sp, #8
 *   @0x24a208 mov r6, #0
 *   @0x24a20c mov r7, #0
 *   @0x24a210 mov r11, r0
 *   @0x24a214 mov r10, r1
 *   @0x24a218 mov r8, #0
 *   @0x24a21c mvn r9, #-16777216
 *   @0x24a220 add r3, sp, #24
 *   @0x24a224 str r3, [sp, #0x4]
 *   @0x24a228 ldr r3, [r11, #0x4]
 *   @0x24a22c cmp r3, #2
 *   @0x24a230 beq 0x24a34c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x150>
 *   @0x24a234 mov r0, r11
 *   @0x24a238 mov r1, r10
 *   @0x24a23c mov r2, r4
 *   @0x24a240 strd r6, r7, [sp, #8]
 *   @0x24a244 str r8, [sp, #0x10]
 *   @0x24a248 str r9, [sp, #0x14]
 *   @0x24a24c bl 0x240134 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_>
 *   @0x24a250 ldr r5, [r10, #0xc]
 *   @0x24a254 bic r3, r5, #-16777216
 *   @0x24a258 cmp r3, #1
 *   @0x24a25c bne 0x24a228 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x2c>
 *   @0x24a260 ldrb r2, [r11, #0x11]
 *   @0x24a264 ldr r3, [r10]
 *   @0x24a268 cmp r2, #0
 *   @0x24a26c ldr r12, [r3]
 *   @0x24a270 bne 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c>
 *   @0x24a274 mov r0, r12
 *   @0x24a278 str r12, [sp]
 *   @0x24a27c bl 0xb6538 <strlen@plt>
 *   @0x24a280 ldr r12, [sp]
 *   @0x24a284 cmp r0, #2
 *   @0x24a288 bls 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c>
 *   @0x24a28c ldrb r3, [r12]
 *   @0x24a290 cmp r3, #91
 *   @0x24a294 beq 0x24a380 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x184>
 *   @0x24a298 ldr r3, [r11, #0xc]
 *   @0x24a29c ldr r2, [sp, #0x10]
 *   @0x24a2a0 tst r3, r2
 *   @0x24a2a4 movne r3, #0
 *   @0x24a2a8 andeq r3, r3, #1
 *   @0x24a2ac cmp r3, #0
 *   @0x24a2b0 bne 0x24a38c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x190>
 *   @0x24a2b4 ldr r2, [sp, #0x14]
 *   @0x24a2b8 cmp r2, r9
 *   @0x24a2bc beq 0x24a38c <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x190>
 *   @0x24a2c0 ldr r0, [r11, #0x14]
 *   @0x24a2c4 cmp r0, #0
 *   @0x24a2c8 beq 0x24a3c0 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1c4>
 *   @0x24a2cc mov r2, r12
 *   @0x24a2d0 add r1, sp, #24
 *   @0x24a2d4 str r3, [sp, #0x20]
 *   @0x24a2d8 str r3, [sp, #0x30]
 *   @0x24a2dc str r12, [sp]
 *   @0x24a2e0 strd r6, r7, [sp, #24]
 *   @0x24a2e4 str r9, [sp, #0x24]
 *   @0x24a2e8 strd r6, r7, [sp, #40]
 *   @0x24a2ec str r9, [sp, #0x34]
 *   @0x24a2f0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24a2f4 ldr r12, [sp]
 *   @0x24a2f8 add r1, sp, #40
 *   @0x24a2fc ldr r0, [r11]
 *   @0x24a300 mov r2, r12
 *   @0x24a304 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24a308 ldr r2, [sp, #0x24]
 *   @0x24a30c ldr r3, [sp, #0x34]
 *   @0x24a310 cmp r2, r3
 *   @0x24a314 beq 0x24a3ac <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1b0>
 *   @0x24a318 ldr r3, [r10, #0xc]
 *   @0x24a31c sub r3, r3, #1
 *   @0x24a320 bic r3, r3, #-16777216
 *   @0x24a324 bic r3, r3, #3
 *   @0x24a328 cmp r3, #0
 *   @0x24a32c beq 0x24a3a0 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1a4>
 *   @0x24a330 str r8, [r10]
 *   @0x24a334 mov r3, #5
 *   @0x24a338 str r3, [r10, #0xc]
 *   @0x24a33c ldr r3, [r11, #0x4]
 *   @0x24a340 str r8, [r10, #0x8]
 *   @0x24a344 cmp r3, #2
 *   @0x24a348 bne 0x24a234 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x38>
 *   @0x24a34c ldrb r0, [r11, #0x10]
 *   @0x24a350 cmp r0, #0
 *   @0x24a354 beq 0x24a378 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x17c>
 *   @0x24a358 ldr r0, [r11, #0x18]
 *   @0x24a35c cmp r0, #0
 *   @0x24a360 beq 0x24a3cc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x1d0>
 *   @0x24a364 mov r1, r10
 *   @0x24a368 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x24a36c subs r4, r0, #0
 *   @0x24a370 beq 0x24a428 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x22c>
 *   @0x24a374 mov r0, r4
 *   @0x24a378 add sp, sp, #60
 *   @0x24a37c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24a380 ldrb r3, [r12, #0x1]
 *   @0x24a384 cmp r3, #91
 *   @0x24a388 bne 0x24a298 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x9c>
 *   @0x24a38c sub r5, r5, #1
 *   @0x24a390 bic r5, r5, #-16777216
 *   @0x24a394 bic r5, r5, #3
 *   @0x24a398 cmp r5, #0
 *   @0x24a39c bne 0x24a330 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x134>
 *   @0x24a3a0 mov r0, r10
 *   @0x24a3a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24a3a8 b 0x24a330 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x134>
 *   @0x24a3ac ldrd r0, r1, [sp, #24]
 *   @0x24a3b0 ldrd r2, r3, [sp, #40]
 *   @0x24a3b4 cmp r1, r3
 *   @0x24a3b8 cmpeq r0, r2
 *   @0x24a3bc bne 0x24a318 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x11c>
 *   @0x24a3c0 mov r0, #1
 *   @0x24a3c4 add sp, sp, #60
 *   @0x24a3c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24a3cc ldr r3, [r11]
 *   @0x24a3d0 ldr r5, [r3, #0x18]
 *   @0x24a3d4 cmp r5, #0
 *   @0x24a3d8 moveq r0, r5
 *   @0x24a3dc beq 0x24a378 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x17c>
 *   @0x24a3e0 mov r0, #28
 *   @0x24a3e4 bl 0x27c524 <_Znwj>
 *   @0x24a3e8 mov r1, r5
 *   @0x24a3ec ldr r2, [r11, #0xc]
 *   @0x24a3f0 mov r4, r0
 *   @0x24a3f4 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x24a3f8 ldr r3, [r11, #0x14]
 *   @0x24a3fc mov r2, #1
 *   @0x24a400 str r4, [r11, #0x18]
 *   @0x24a404 mov r0, r4
 *   @0x24a408 cmp r3, #0
 *   @0x24a40c strb r2, [r4, #0x10]
 *   @0x24a410 mov r1, r10
 *   @0x24a414 ldreq r3, [r11]
 *   @0x24a418 str r3, [r4, #0x14]
 *   @0x24a41c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x24a420 subs r4, r0, #0
 *   @0x24a424 bne 0x24a374 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x178>
 *   @0x24a428 ldr r0, [r11, #0x18]
 *   @0x24a42c bl 0x27d1d0 <_ZdlPv>
 *   @0x24a430 str r4, [r11, #0x18]
 *   @0x24a434 b 0x24a374 <_ZN29YYObject_PropertyNameIterator4NextEP6RValue+0x178>
 *
 * ══ §31/54 JS_String_prototype_trim(RValue&, CInstance*, CInstance*, int, RValue*)  0x255e34  size 572  143 条（0x255e34..0x256070）
 * @func 0x255e34 0x256070  size 572  143 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / 0xb6538 / 0xb65b0 / JS_isWhitespace(int) / CCodepointIterator_UTF8::GetNext() / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x-58×4 / 0x-60×2 / 0x-28×2 / 0x-38×2 / 0x1×2 / 0x224×1 / 0x-3c×1 / 0x-24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255e34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x255e38 add r11, sp, #32
 *   @0x255e3c ldr r7, [pc, #0x224]
 *   @0x255e40 sub sp, sp, #68
 *   @0x255e44 sub r4, r11, #36
 *   @0x255e48 ldr r7, [pc, r7]
 *   @0x255e4c mov r3, #6
 *   @0x255e50 str r3, [r11, #-0x3c]
 *   @0x255e54 ldr r3, [r7]
 *   @0x255e58 str r0, [r11, #-0x60]
 *   @0x255e5c str r1, [r4, #-0x24]!
 *   @0x255e60 mov r0, r4
 *   @0x255e64 str r3, [r11, #-0x28]
 *   @0x255e68 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255e6c cmp r0, #1
 *   @0x255e70 beq 0x255fcc <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x255e74 mov r1, r4
 *   @0x255e78 sub r0, r11, #56
 *   @0x255e7c mov r4, #0
 *   @0x255e80 mvn r3, #-16777216
 *   @0x255e84 str r4, [r11, #-0x38]
 *   @0x255e88 sub r5, r11, #84
 *   @0x255e8c str r3, [r11, #-0x2c]
 *   @0x255e90 movw r10, #0xfffe
 *   @0x255e94 str r4, [r11, #-0x34]
 *   @0x255e98 movt r10, #0x1f
 *   @0x255e9c str r4, [r11, #-0x30]
 *   @0x255ea0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255ea4 ldr r3, [r11, #-0x38]
 *   @0x255ea8 mov r0, r5
 *   @0x255eac mvn r2, #0
 *   @0x255eb0 str r2, [r11, #-0x58]
 *   @0x255eb4 mov r8, r4
 *   @0x255eb8 mov r6, #1
 *   @0x255ebc ldr r9, [r3]
 *   @0x255ec0 mov r1, r9
 *   @0x255ec4 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x255ec8 mov r0, r9
 *   @0x255ecc bl 0xb6538 <strlen@plt>
 *   @0x255ed0 mov r1, r4
 *   @0x255ed4 lsl r2, r0, #2
 *   @0x255ed8 add r3, r2, #14
 *   @0x255edc bic r3, r3, #7
 *   @0x255ee0 sub sp, sp, r3
 *   @0x255ee4 mov r3, sp
 *   @0x255ee8 lsr r3, r3, #3
 *   @0x255eec str r3, [r11, #-0x5c]
 *   @0x255ef0 lsl r9, r3, #3
 *   @0x255ef4 mov r0, r9
 *   @0x255ef8 bl 0xb65b0 <memset@plt>
 *   @0x255efc b 0x255f0c <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x255f00 bl 0x2425ac <_Z15JS_isWhitespacei>
 *   @0x255f04 tst r0, r6
 *   @0x255f08 beq 0x255f50 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x255f0c mov r0, r5
 *   @0x255f10 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255f14 subs r4, r0, #0
 *   @0x255f18 bne 0x255f00 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x255f1c ldr r3, [r11, #-0x58]
 *   @0x255f20 mov r1, r9
 *   @0x255f24 ldr r0, [r11, #-0x60]
 *   @0x255f28 cmp r8, r3
 *   @0x255f2c ldrgt r2, [r11, #-0x5c]
 *   @0x255f30 strbgt r4, [r3, r2, lsl #3]
 *   @0x255f34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x255f38 ldr r2, [r11, #-0x28]
 *   @0x255f3c ldr r3, [r7]
 *   @0x255f40 cmp r2, r3
 *   @0x255f44 bne 0x256064 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x255f48 sub sp, r11, #32
 *   @0x255f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255f50 cmp r4, #126
 *   @0x255f54 strble r4, [r9, r8]
 *   @0x255f58 addle r8, r8, #1
 *   @0x255f5c ble 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x255f60 movw r2, #0x7fe
 *   @0x255f64 cmp r4, r2
 *   @0x255f68 ble 0x255fdc <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x255f6c movw r3, #0xfffe
 *   @0x255f70 cmp r4, r3
 *   @0x255f74 bgt 0x256008 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x255f78 ubfx r12, r4, #0xc, #0x4
 *   @0x255f7c mov r2, r9
 *   @0x255f80 ubfx r1, r4, #0x6, #0x6
 *   @0x255f84 and r3, r4, #63
 *   @0x255f88 mvn r12, r12, lsl #27
 *   @0x255f8c add lr, r8, #2
 *   @0x255f90 mvn r12, r12, lsr #27
 *   @0x255f94 strb r12, [r2, r8]!
 *   @0x255f98 add r8, r8, #3
 *   @0x255f9c mvn r1, r1, lsl #25
 *   @0x255fa0 mvn r3, r3, lsl #25
 *   @0x255fa4 mvn r1, r1, lsr #25
 *   @0x255fa8 mvn r3, r3, lsr #25
 *   @0x255fac strb r1, [r2, #0x1]
 *   @0x255fb0 strb r3, [r9, lr]
 *   @0x255fb4 ldr r3, [r11, #-0x58]
 *   @0x255fb8 cmp r0, #0
 *   @0x255fbc mov r6, #0
 *   @0x255fc0 moveq r3, r8
 *   @0x255fc4 str r3, [r11, #-0x58]
 *   @0x255fc8 b 0x255f0c <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x255fcc ldr r0, [pc, #0x98]
 *   @0x255fd0 add r0, pc, r0
 *   @0x255fd4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255fd8 b 0x255f38 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x255fdc ubfx r2, r4, #0x6, #0x5
 *   @0x255fe0 and r3, r4, #63
 *   @0x255fe4 add r1, r8, #1
 *   @0x255fe8 mvn r2, r2, lsl #26
 *   @0x255fec mvn r3, r3, lsl #25
 *   @0x255ff0 mvn r2, r2, lsr #26
 *   @0x255ff4 mvn r3, r3, lsr #25
 *   @0x255ff8 strb r2, [r9, r8]
 *   @0x255ffc add r8, r8, #2
 *   @0x256000 strb r3, [r9, r1]
 *   @0x256004 b 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x256008 cmp r4, r10
 *   @0x25600c bgt 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x256010 and lr, r4, #3670016
 *   @0x256014 mov r3, r9
 *   @0x256018 ubfx r12, r4, #0xc, #0x6
 *   @0x25601c ubfx r1, r4, #0x6, #0x6
 *   @0x256020 asr lr, lr, #18
 *   @0x256024 and r2, r4, #63
 *   @0x256028 mvn r12, r12, lsl #25
 *   @0x25602c mvn r1, r1, lsl #25
 *   @0x256030 mvn lr, lr, lsl #28
 *   @0x256034 mvn r2, r2, lsl #25
 *   @0x256038 mvn lr, lr, lsr #28
 *   @0x25603c strb lr, [r3, r8]!
 *   @0x256040 add lr, r8, #3
 *   @0x256044 mvn r12, r12, lsr #25
 *   @0x256048 mvn r1, r1, lsr #25
 *   @0x25604c strb r12, [r3, #0x1]
 *   @0x256050 strb r1, [r3, #0x2]
 *   @0x256054 mvn r2, r2, lsr #25
 *   @0x256058 add r8, r8, #4
 *   @0x25605c strb r2, [r9, lr]
 *   @0x256060 b 0x255fb4 <_Z24JS_String_prototype_trimR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x256064 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x256068 andseq r7, r9, r8, lsl #22
 *   @0x25606c andeq pc, pc, r8, ror pc
 *
 * ══ §32/54 F_SpriteSaveStrip(RValue&, CInstance*, CInstance*, int, RValue*)  0x13090c  size 568  142 条（0x13090c..0x130b44）
 * @func 0x13090c 0x130b44  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::GetWidth()×4 / F_SpriteSaveStrip(RValue&, CInstance*, CInstance*, int, RValue*)+0x198×2 / CBitmap32::GetData()×2 / CBitmap32::GetHeight()×2 / YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / Sprite_Data(int) / F_SpriteSaveStrip(RValue&, CInstance*, CInstance*, int, RValue*)+0x178
 * 字段偏移 top8: 0x4×5 / 0x18×3 / 0x1c×2 / 0x48×2 / 0xe4×2 / 0x30×1 / 0x74×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13090c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x130910 sub sp, sp, #12
 *   @0x130914 mov r1, #0
 *   @0x130918 ldr r4, [sp, #0x30]
 *   @0x13091c mov r0, r4
 *   @0x130920 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130924 mov r1, #1
 *   @0x130928 mov r5, r0
 *   @0x13092c mov r0, r4
 *   @0x130930 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x130934 mov r11, r0
 *   @0x130938 mov r0, r5
 *   @0x13093c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130940 cmp r11, #0
 *   @0x130944 cmpne r0, #0
 *   @0x130948 mov r10, r0
 *   @0x13094c beq 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x130950 ldr r9, [r0, #0x74]
 *   @0x130954 cmp r9, #0
 *   @0x130958 bne 0x130a8c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x13095c ldr r3, [r0, #0x18]
 *   @0x130960 cmp r3, #0
 *   @0x130964 ble 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x130968 ldr r5, [r0, #0x1c]
 *   @0x13096c mov r0, #24
 *   @0x130970 ldr r4, [r10, #0x20]
 *   @0x130974 mul r5, r5, r3
 *   @0x130978 bl 0x27c524 <_Znwj>
 *   @0x13097c mov r3, #-16777216
 *   @0x130980 mov r2, r4
 *   @0x130984 mov r1, r5
 *   @0x130988 mov r8, r0
 *   @0x13098c bl 0x166140 <_ZN9CBitmap32C2Eiij>
 *   @0x130990 ldr r3, [r10, #0x18]
 *   @0x130994 cmp r3, #0
 *   @0x130998 ble 0x130aa4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x13099c ldr r3, [r10, #0x48]
 *   @0x1309a0 cmp r3, #0
 *   @0x1309a4 beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1309a8 ldr r7, [r3]
 *   @0x1309ac cmp r7, #0
 *   @0x1309b0 beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1309b4 mov r0, r8
 *   @0x1309b8 mov r4, #0
 *   @0x1309bc bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1309c0 ldr r6, [r10, #0x1c]
 *   @0x1309c4 mul r6, r6, r9
 *   @0x1309c8 ldr r3, [r0, #0x4]
 *   @0x1309cc mov r0, r7
 *   @0x1309d0 add r6, r3, r6, lsl #2
 *   @0x1309d4 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1309d8 ldr r5, [r0, #0x4]
 *   @0x1309dc b 0x130a0c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1309e0 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x1309e4 mov r1, r5
 *   @0x1309e8 lsl r2, r0, #2
 *   @0x1309ec mov r0, r6
 *   @0x1309f0 bl 0xb65bc <memcpy@plt>
 *   @0x1309f4 mov r0, r8
 *   @0x1309f8 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x1309fc add r6, r6, r0, lsl #2
 *   @0x130a00 mov r0, r7
 *   @0x130a04 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x130a08 add r5, r5, r0, lsl #2
 *   @0x130a0c mov r0, r8
 *   @0x130a10 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x130a14 cmp r4, r0
 *   @0x130a18 mov r0, r7
 *   @0x130a1c add r4, r4, #1
 *   @0x130a20 blt 0x1309e0 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x130a24 ldr r3, [r10, #0x18]
 *   @0x130a28 add r9, r9, #1
 *   @0x130a2c cmp r3, r9
 *   @0x130a30 ble 0x130aa4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x130a34 ldr r3, [r10, #0x48]
 *   @0x130a38 cmp r3, #0
 *   @0x130a3c beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x130a40 ldr r7, [r3, r9, lsl #2]
 *   @0x130a44 cmp r7, #0
 *   @0x130a48 bne 0x1309b4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x130a4c ldr r3, [pc, #0xe4]
 *   @0x130a50 ldr r1, [pc, #0xe4]
 *   @0x130a54 ldr r3, [pc, r3]
 *   @0x130a58 add r1, pc, r1
 *   @0x130a5c ldr r0, [r3]
 *   @0x130a60 ldr r3, [r0]
 *   @0x130a64 ldr r3, [r3, #0xc]
 *   @0x130a68 blx r3
 *   @0x130a6c cmp r8, #0
 *   @0x130a70 beq 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x130a74 ldr r3, [r8]
 *   @0x130a78 mov r0, r8
 *   @0x130a7c ldr r3, [r3, #0x4]
 *   @0x130a80 blx r3
 *   @0x130a84 add sp, sp, #12
 *   @0x130a88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130a8c ldr r0, [pc, #0xac]
 *   @0x130a90 mov r1, #0
 *   @0x130a94 add r0, pc, r0
 *   @0x130a98 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130a9c add sp, sp, #12
 *   @0x130aa0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130aa4 mov r0, r8
 *   @0x130aa8 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev>
 *   @0x130aac subs r4, r0, #0
 *   @0x130ab0 beq 0x130a6c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x130ab4 add r2, sp, #8
 *   @0x130ab8 mov r3, #0
 *   @0x130abc mov r1, r3
 *   @0x130ac0 str r3, [r2, #-0x4]!
 *   @0x130ac4 ldr r12, [r4]
 *   @0x130ac8 str r3, [sp]
 *   @0x130acc mov r3, sp
 *   @0x130ad0 ldr r12, [r12, #0x24]
 *   @0x130ad4 blx r12
 *   @0x130ad8 ldr r5, [sp, #0x4]
 *   @0x130adc cmp r5, #0
 *   @0x130ae0 mov r6, r0
 *   @0x130ae4 beq 0x130b10 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x130ae8 mov r0, r8
 *   @0x130aec bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x130af0 mov r7, r0
 *   @0x130af4 mov r0, r8
 *   @0x130af8 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x130afc mov r1, r5
 *   @0x130b00 mov r2, r7
 *   @0x130b04 mov r3, r0
 *   @0x130b08 mov r0, r11
 *   @0x130b0c bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x130b10 ldr r3, [r4]
 *   @0x130b14 mov r0, r4
 *   @0x130b18 mov r1, r6
 *   @0x130b1c ldr r3, [r3, #0x28]
 *   @0x130b20 blx r3
 *   @0x130b24 ldr r3, [r4]
 *   @0x130b28 mov r0, r4
 *   @0x130b2c ldr r3, [r3, #0x4]
 *   @0x130b30 blx r3
 *   @0x130b34 b 0x130a6c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x130b38 eoreq r12, r11, r0, asr #25
 *   @0x130b3c mlaeq r0, r4, r8, sp
 *   @0x130b40 eoreq sp, r0, r4, lsr #16
 *
 * ══ §33/54 F_FileTextOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*)  0x13b230  size 568  142 条（0x13b230..0x13b468）
 * @func 0x13b230 0x13b468  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13b26c→0x483724, 0x13b2b0→0x4837a4, 0x13b410→0x3eb70c
 * 调用序列: LoadSave::fopen(char const*, char const*)×3 / LoadSave::fclose(_YYFILE*)×2 / YYGetString(RValue const*, int) / MemoryManager::Free(void const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::SaveFileExists(char const*) / EnsureDirectoryIsCreated(char const*) / 0xb6538
 * 字段偏移 top8: 0xc×5 / 0x4×4 / 0x8×3 / 0x414×2 / 0x1fc×1 / 0x1f8×1 / 0x440×1 / 0x1d0×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b230 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13b234 sub sp, sp, #1040
 *   @0x13b238 ldr r7, [pc, #0x1fc]
 *   @0x13b23c sub sp, sp, #12
 *   @0x13b240 ldr r3, [pc, #0x1f8]
 *   @0x13b244 mov r6, r0
 *   @0x13b248 add r7, pc, r7
 *   @0x13b24c mov r1, #0
 *   @0x13b250 ldr r0, [sp, #0x440]
 *   @0x13b254 mov r4, #1
 *   @0x13b258 ldr r3, [r7, r3]
 *   @0x13b25c str r3, [sp, #0x8]
 *   @0x13b260 ldr r3, [r3]
 *   @0x13b264 str r3, [sp, #0x414]
 *   @0x13b268 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b26c ldr r1, [pc, #0x1d0]
 *   @0x13b270 mov r2, #0
 *   @0x13b274 mov r3, r2
 *   @0x13b278 movt r2, #0xbff0
 *   @0x13b27c str r3, [r6, #0xc]
 *   @0x13b280 str r2, [r6, #0x4]
 *   @0x13b284 str r3, [r6]
 *   @0x13b288 ldr r3, [r7, r1]
 *   @0x13b28c str r3, [sp, #0xc]
 *   @0x13b290 mov r10, r0
 *   @0x13b294 b 0x13b2a4 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x13b298 add r4, r4, #1
 *   @0x13b29c cmp r4, #32
 *   @0x13b2a0 beq 0x13b398 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x13b2a4 ldr r5, [r3, #0x4]!
 *   @0x13b2a8 cmp r5, #0
 *   @0x13b2ac bne 0x13b298 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x13b2b0 ldr r2, [pc, #0x190]
 *   @0x13b2b4 lsl r11, r4, #1
 *   @0x13b2b8 add r3, r11, r4
 *   @0x13b2bc add r9, sp, #20
 *   @0x13b2c0 ldr r8, [r7, r2]
 *   @0x13b2c4 lsl r3, r3, #2
 *   @0x13b2c8 ldr r0, [r8, r3]
 *   @0x13b2cc str r3, [sp, #0x4]
 *   @0x13b2d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13b2d4 ldr r3, [sp, #0x4]
 *   @0x13b2d8 mov r1, #1024
 *   @0x13b2dc mov r2, r10
 *   @0x13b2e0 mov r0, r9
 *   @0x13b2e4 str r5, [r8, r3]
 *   @0x13b2e8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b2ec mov r0, r10
 *   @0x13b2f0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x13b2f4 cmp r0, #0
 *   @0x13b2f8 beq 0x13b3ac <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x13b2fc mov r0, r9
 *   @0x13b300 add r11, r11, r4
 *   @0x13b304 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x13b308 mov r0, r9
 *   @0x13b30c bl 0xb6538 <strlen@plt>
 *   @0x13b310 ldr r1, [pc, #0x134]
 *   @0x13b314 mov r3, #1
 *   @0x13b318 movw r2, #0x3b2
 *   @0x13b31c add r1, pc, r1
 *   @0x13b320 lsl r11, r11, #2
 *   @0x13b324 add r0, r0, r3
 *   @0x13b328 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13b32c mov r1, r9
 *   @0x13b330 add r9, r8, r11
 *   @0x13b334 mov r5, r0
 *   @0x13b338 bl 0xb65a4 <strcpy@plt>
 *   @0x13b33c ldr r1, [pc, #0x10c]
 *   @0x13b340 mov r0, r5
 *   @0x13b344 str r5, [r8, r11]
 *   @0x13b348 add r1, pc, r1
 *   @0x13b34c bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13b350 cmp r0, #0
 *   @0x13b354 str r0, [r9, #0x8]
 *   @0x13b358 beq 0x13b410 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x13b35c vmov s15, r4
 *   @0x13b360 ldr r0, [sp, #0xc]
 *   @0x13b364 mov r1, #2
 *   @0x13b368 vcvt.f64.s32 d7, s15
 *   @0x13b36c str r1, [r0, r4, lsl #2]
 *   @0x13b370 vmov r2, r3, d7
 *   @0x13b374 stm r6, {r2, r3}
 *   @0x13b378 ldr r1, [sp, #0x8]
 *   @0x13b37c ldr r2, [sp, #0x414]
 *   @0x13b380 ldr r3, [r1]
 *   @0x13b384 cmp r2, r3
 *   @0x13b388 bne 0x13b438 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x13b38c add sp, sp, #1040
 *   @0x13b390 add sp, sp, #12
 *   @0x13b394 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13b398 ldr r0, [pc, #0xb4]
 *   @0x13b39c mov r1, #0
 *   @0x13b3a0 add r0, pc, r0
 *   @0x13b3a4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13b3a8 b 0x13b378 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x13b3ac mov r0, r10
 *   @0x13b3b0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x13b3b4 cmp r0, #0
 *   @0x13b3b8 beq 0x13b2fc <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x13b3bc ldr r1, [pc, #0x94]
 *   @0x13b3c0 mov r0, r10
 *   @0x13b3c4 add r1, pc, r1
 *   @0x13b3c8 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13b3cc ldr r1, [pc, #0x88]
 *   @0x13b3d0 add r1, pc, r1
 *   @0x13b3d4 mov r5, r0
 *   @0x13b3d8 mov r0, r9
 *   @0x13b3dc bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x13b3e0 ldr r2, [r5]
 *   @0x13b3e4 mov r1, #1
 *   @0x13b3e8 mov r3, r0
 *   @0x13b3ec mov r10, r0
 *   @0x13b3f0 ldr r0, [r2, #0xc]
 *   @0x13b3f4 ldr r2, [r2, #0x10]
 *   @0x13b3f8 bl 0x18e2b0 <_ZN8LoadSave6fwriteEPKvjjP7_YYFILE>
 *   @0x13b3fc mov r0, r5
 *   @0x13b400 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x13b404 mov r0, r10
 *   @0x13b408 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x13b40c b 0x13b2fc <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x13b410 ldr r3, [pc, #0x48]
 *   @0x13b414 mov r2, r5
 *   @0x13b418 ldr r1, [pc, #0x44]
 *   @0x13b41c ldr r3, [r7, r3]
 *   @0x13b420 add r1, pc, r1
 *   @0x13b424 ldr r0, [r3]
 *   @0x13b428 ldr r3, [r0]
 *   @0x13b42c ldr r3, [r3, #0xc]
 *   @0x13b430 blx r3
 *   @0x13b434 b 0x13b378 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x13b438 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b43c eoreq r6, r11, r8, lsl #20
 *   @0x13b440 .word 0xffffbd00
 *   @0x13b444 .word 0xffffd620
 *   @0x13b448 .word 0xffffd624
 *   @0x13b44c eoreq r4, r0, r4, lsr sp
 *   @0x13b450 eoreq r4, r0, r8, lsr #29
 *   @0x13b454 eoreq r4, r0, r0, ror #24
 *   @0x13b458 andseq r12, pc, r4, lsr r8
 *   @0x13b45c eoreq r4, r0, r4, ror pc
 *   @0x13b460 .word 0xffffbac4
 *   @0x13b464 .word 0x00204bb4
 *
 * ══ §34/54 F_PhysicsCreateGearJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14fd30  size 568  142 条（0x14fd30..0x14ff68）
 * @func 0x14fd30 0x14ff68  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14fe0c→0x54298c, 0x14fe50→0x54298c
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Error_Show_Action(char const*, bool)×5 / Object_GetInstance(int, CInstance*, CInstance*)×2 / CPhysicsJointFactory::FindJoint(unsigned int)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetFloat(RValue const*, int) / CPhysicsWorld::CreateGearJoint(CPhysicsObject*, CPhysicsObject*, CPhysicsJoint*, CPhysicsJoint*, float)
 * 字段偏移 top8: 0x84×4 / 0x4×2 / 0x10c×2 / 0xb4×2 / 0x208×1 / 0x204×1 / 0x130×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14fd30 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x14fd34 sub sp, sp, #272
 *   @0x14fd38 ldr r5, [pc, #0x208]
 *   @0x14fd3c mov r7, r2
 *   @0x14fd40 ldr lr, [pc, #0x204]
 *   @0x14fd44 mov r3, r0
 *   @0x14fd48 add r5, pc, r5
 *   @0x14fd4c ldr r4, [sp, #0x130]
 *   @0x14fd50 mov r12, #0
 *   @0x14fd54 mov r8, r1
 *   @0x14fd58 ldr r6, [r5, lr]
 *   @0x14fd5c mov r0, r12
 *   @0x14fd60 mov r1, r12
 *   @0x14fd64 movt r0, #0xbff0
 *   @0x14fd68 str r12, [r3, #0xc]
 *   @0x14fd6c ldr r2, [r6]
 *   @0x14fd70 str r0, [r3, #0x4]
 *   @0x14fd74 mov r0, r4
 *   @0x14fd78 str r12, [r3]
 *   @0x14fd7c str r2, [sp, #0x10c]
 *   @0x14fd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fd84 mov r1, r8
 *   @0x14fd88 mov r2, r7
 *   @0x14fd8c bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14fd90 subs r9, r0, #0
 *   @0x14fd94 beq 0x14fea0 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x14fd98 mov r1, #1
 *   @0x14fd9c mov r0, r4
 *   @0x14fda0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fda4 mov r1, r8
 *   @0x14fda8 mov r2, r7
 *   @0x14fdac bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14fdb0 subs r10, r0, #0
 *   @0x14fdb4 beq 0x14fefc <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x14fdb8 ldr r3, [r9, #0x84]
 *   @0x14fdbc cmp r3, #0
 *   @0x14fdc0 beq 0x14fe50 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x14fdc4 ldr r3, [r10, #0x84]
 *   @0x14fdc8 cmp r3, #0
 *   @0x14fdcc beq 0x14fe50 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x14fdd0 mov r1, #2
 *   @0x14fdd4 mov r0, r4
 *   @0x14fdd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fddc bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x14fde0 mov r1, #3
 *   @0x14fde4 mov r7, r0
 *   @0x14fde8 mov r0, r4
 *   @0x14fdec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fdf0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x14fdf4 cmp r0, #0
 *   @0x14fdf8 cmpne r7, #0
 *   @0x14fdfc mov r8, r0
 *   @0x14fe00 moveq r1, #0
 *   @0x14fe04 movne r1, #1
 *   @0x14fe08 beq 0x14fe90 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x14fe0c ldr r3, [pc, #0x13c]
 *   @0x14fe10 ldr r3, [r5, r3]
 *   @0x14fe14 ldr r3, [r3]
 *   @0x14fe18 ldr r5, [r3, #0xb4]
 *   @0x14fe1c cmp r5, #0
 *   @0x14fe20 beq 0x14fee8 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x14fe24 mov r0, r4
 *   @0x14fe28 mov r1, #4
 *   @0x14fe2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fe30 ldr r1, [r9, #0x84]
 *   @0x14fe34 ldr r2, [r10, #0x84]
 *   @0x14fe38 mov r3, r7
 *   @0x14fe3c str r8, [sp]
 *   @0x14fe40 str r0, [sp, #0x4]
 *   @0x14fe44 mov r0, r5
 *   @0x14fe48 bl 0x23974c <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f>
 *   @0x14fe4c b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x14fe50 ldr r3, [pc, #0xf8]
 *   @0x14fe54 ldr r3, [r5, r3]
 *   @0x14fe58 ldr r3, [r3]
 *   @0x14fe5c ldr r3, [r3, #0xb4]
 *   @0x14fe60 cmp r3, #0
 *   @0x14fe64 beq 0x14fee8 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x14fe68 ldr r0, [pc, #0xe4]
 *   @0x14fe6c mov r1, #0
 *   @0x14fe70 add r0, pc, r0
 *   @0x14fe74 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fe78 ldr r2, [sp, #0x10c]
 *   @0x14fe7c ldr r3, [r6]
 *   @0x14fe80 cmp r2, r3
 *   @0x14fe84 bne 0x14ff44 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x14fe88 add sp, sp, #272
 *   @0x14fe8c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14fe90 ldr r0, [pc, #0xc0]
 *   @0x14fe94 add r0, pc, r0
 *   @0x14fe98 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fe9c b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x14fea0 add r5, sp, #12
 *   @0x14fea4 mov r1, r9
 *   @0x14fea8 mov r2, #256
 *   @0x14feac mov r0, r5
 *   @0x14feb0 bl 0xb65b0 <memset@plt>
 *   @0x14feb4 mov r1, r9
 *   @0x14feb8 mov r0, r4
 *   @0x14febc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fec0 ldr r2, [pc, #0x94]
 *   @0x14fec4 mov r1, #256
 *   @0x14fec8 add r2, pc, r2
 *   @0x14fecc mov r3, r0
 *   @0x14fed0 mov r0, r5
 *   @0x14fed4 bl 0xb65c8 <snprintf@plt>
 *   @0x14fed8 mov r0, r5
 *   @0x14fedc mov r1, r9
 *   @0x14fee0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fee4 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x14fee8 ldr r0, [pc, #0x70]
 *   @0x14feec mov r1, #0
 *   @0x14fef0 add r0, pc, r0
 *   @0x14fef4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fef8 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x14fefc add r5, sp, #12
 *   @0x14ff00 mov r1, r10
 *   @0x14ff04 mov r2, #256
 *   @0x14ff08 mov r0, r5
 *   @0x14ff0c bl 0xb65b0 <memset@plt>
 *   @0x14ff10 mov r0, r4
 *   @0x14ff14 mov r1, #1
 *   @0x14ff18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ff1c ldr r2, [pc, #0x40]
 *   @0x14ff20 mov r1, #256
 *   @0x14ff24 add r2, pc, r2
 *   @0x14ff28 mov r3, r0
 *   @0x14ff2c mov r0, r5
 *   @0x14ff30 bl 0xb65c8 <snprintf@plt>
 *   @0x14ff34 mov r0, r5
 *   @0x14ff38 mov r1, r10
 *   @0x14ff3c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ff40 b 0x14fe78 <_Z24F_PhysicsCreateGearJointR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x14ff44 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14ff48 eoreq r1, r10, r8, lsl #30
 *   @0x14ff4c .word 0xffffbd00
 *   @0x14ff50 .word 0xffffbcd8
 *   @0x14ff54 andseq r5, pc, r8, lsr #2
 *   @0x14ff58 andseq r3, pc, r8, lsr pc
 *   @0x14ff5c ldrsbeq r4, [pc], -r8
 *   @0x14ff60 andseq r3, pc, r4, lsr pc
 *   @0x14ff64 andseq r4, pc, r12, ror lr
 *
 * ══ §35/54 CTimeLine::AddMoment(int)  0x1f2018  size 568  142 条（0x1f2018..0x1f2250）
 * @func 0x1f2018 0x1f2250  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / CTimeLine::AddMoment(int)+0x220 / CTimeLine::AddMoment(int)+0x1a4 / CTimeLine::AddMoment(int)+0xa8 / operator new(unsigned int) / CEvent::CEvent() / CTimeLine::AddMoment(int)+0x150
 * 字段偏移 top8: 0xc×10 / 0x14×5 / 0x-4×3 / 0x8×3 / 0x10×2 / 0x4×2 / 0x1c4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f201c mov r7, r0
 *   @0x1f2020 ldr r5, [r0, #0x10]
 *   @0x1f2024 sub sp, sp, #20
 *   @0x1f2028 mov r8, r1
 *   @0x1f202c cmp r5, #0
 *   @0x1f2030 ble 0x1f2238 <_ZN9CTimeLine9AddMomentEi+0x220>
 *   @0x1f2034 ldr r0, [r0, #0x14]
 *   @0x1f2038 ldr r3, [r0]
 *   @0x1f203c cmp r1, r3
 *   @0x1f2040 ble 0x1f21bc <_ZN9CTimeLine9AddMomentEi+0x1a4>
 *   @0x1f2044 mov r2, r0
 *   @0x1f2048 mov r4, #0
 *   @0x1f204c b 0x1f205c <_ZN9CTimeLine9AddMomentEi+0x44>
 *   @0x1f2050 ldr r3, [r2, #0x4]!
 *   @0x1f2054 cmp r3, r8
 *   @0x1f2058 bge 0x1f21c4 <_ZN9CTimeLine9AddMomentEi+0x1ac>
 *   @0x1f205c add r4, r4, #1
 *   @0x1f2060 cmp r4, r5
 *   @0x1f2064 lsl r6, r4, #2
 *   @0x1f2068 bne 0x1f2050 <_ZN9CTimeLine9AddMomentEi+0x38>
 *   @0x1f206c adds r9, r5, #1
 *   @0x1f2070 beq 0x1f21d4 <_ZN9CTimeLine9AddMomentEi+0x1bc>
 *   @0x1f2074 lsls r1, r9, #2
 *   @0x1f2078 beq 0x1f221c <_ZN9CTimeLine9AddMomentEi+0x204>
 *   @0x1f207c ldr r2, [pc, #0x1c4]
 *   @0x1f2080 mov r3, #0
 *   @0x1f2084 str r3, [sp]
 *   @0x1f2088 mov r3, #106
 *   @0x1f208c add r2, pc, r2
 *   @0x1f2090 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f2094 mov r12, r0
 *   @0x1f2098 str r0, [r7, #0x14]
 *   @0x1f209c cmp r5, r4
 *   @0x1f20a0 str r9, [r7, #0x10]
 *   @0x1f20a4 addgt r3, r12, r5, lsl #2
 *   @0x1f20a8 addgt r1, r12, r4, lsl #2
 *   @0x1f20ac ble 0x1f20c0 <_ZN9CTimeLine9AddMomentEi+0xa8>
 *   @0x1f20b0 ldr r2, [r3, #-0x4]
 *   @0x1f20b4 str r2, [r3], #-4
 *   @0x1f20b8 cmp r3, r1
 *   @0x1f20bc bne 0x1f20b0 <_ZN9CTimeLine9AddMomentEi+0x98>
 *   @0x1f20c0 str r8, [r12, r6]
 *   @0x1f20c4 mov r0, #12
 *   @0x1f20c8 bl 0x27c524 <_Znwj>
 *   @0x1f20cc str r0, [sp, #0xc]
 *   @0x1f20d0 bl 0xf2d0c <_ZN6CEventC2Ev>
 *   @0x1f20d4 ldr r5, [r7, #0x8]
 *   @0x1f20d8 adds r9, r5, #1
 *   @0x1f20dc mov lr, r5
 *   @0x1f20e0 bne 0x1f21ec <_ZN9CTimeLine9AddMomentEi+0x1d4>
 *   @0x1f20e4 ldr r3, [r7, #0xc]
 *   @0x1f20e8 cmp r3, #0
 *   @0x1f20ec beq 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150>
 *   @0x1f20f0 cmp r5, #0
 *   @0x1f20f4 ble 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150>
 *   @0x1f20f8 mov r8, r9
 *   @0x1f20fc mov r11, r9
 *   @0x1f2100 ldr r0, [r3]
 *   @0x1f2104 movw r2, #0xfeee
 *   @0x1f2108 movt r2, #0xfeee
 *   @0x1f210c movw r1, #0xfeee
 *   @0x1f2110 cmp r0, r2
 *   @0x1f2114 movt r1, #0xfeee
 *   @0x1f2118 lsl r10, r8, #2
 *   @0x1f211c beq 0x1f215c <_ZN9CTimeLine9AddMomentEi+0x144>
 *   @0x1f2120 ldr r2, [r3, r8, lsl #2]
 *   @0x1f2124 add r12, r3, r10
 *   @0x1f2128 cmp r2, #0
 *   @0x1f212c mov r0, r2
 *   @0x1f2130 beq 0x1f215c <_ZN9CTimeLine9AddMomentEi+0x144>
 *   @0x1f2134 ldr r3, [r2]
 *   @0x1f2138 cmp r3, r1
 *   @0x1f213c beq 0x1f2154 <_ZN9CTimeLine9AddMomentEi+0x13c>
 *   @0x1f2140 ldr r3, [r3, #0x4]
 *   @0x1f2144 blx r3
 *   @0x1f2148 ldr r12, [r7, #0xc]
 *   @0x1f214c ldr lr, [r7, #0x8]
 *   @0x1f2150 add r12, r12, r10
 *   @0x1f2154 str r11, [r12]
 *   @0x1f2158 ldr r3, [r7, #0xc]
 *   @0x1f215c add r8, r8, #1
 *   @0x1f2160 cmp r8, lr
 *   @0x1f2164 blt 0x1f2100 <_ZN9CTimeLine9AddMomentEi+0xe8>
 *   @0x1f2168 mov r0, r3
 *   @0x1f216c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2170 mov r3, #0
 *   @0x1f2174 mov r2, r3
 *   @0x1f2178 str r3, [r7, #0xc]
 *   @0x1f217c cmp r5, r4
 *   @0x1f2180 str r9, [r7, #0x8]
 *   @0x1f2184 ble 0x1f21ac <_ZN9CTimeLine9AddMomentEi+0x194>
 *   @0x1f2188 lsl r3, r5, #2
 *   @0x1f218c add r1, r2, r3
 *   @0x1f2190 sub r5, r5, #1
 *   @0x1f2194 cmp r5, r4
 *   @0x1f2198 ldr r1, [r1, #-0x4]
 *   @0x1f219c str r1, [r2, r3]
 *   @0x1f21a0 sub r3, r3, #4
 *   @0x1f21a4 ldr r2, [r7, #0xc]
 *   @0x1f21a8 bne 0x1f218c <_ZN9CTimeLine9AddMomentEi+0x174>
 *   @0x1f21ac ldr r3, [sp, #0xc]
 *   @0x1f21b0 str r3, [r2, r6]
 *   @0x1f21b4 add sp, sp, #20
 *   @0x1f21b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f21bc mov r6, #0
 *   @0x1f21c0 mov r4, r6
 *   @0x1f21c4 cmp r8, r3
 *   @0x1f21c8 beq 0x1f21b4 <_ZN9CTimeLine9AddMomentEi+0x19c>
 *   @0x1f21cc adds r9, r5, #1
 *   @0x1f21d0 bne 0x1f2074 <_ZN9CTimeLine9AddMomentEi+0x5c>
 *   @0x1f21d4 cmp r0, #0
 *   @0x1f21d8 beq 0x1f221c <_ZN9CTimeLine9AddMomentEi+0x204>
 *   @0x1f21dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f21e0 str r9, [r7, #0x14]
 *   @0x1f21e4 mov r12, r9
 *   @0x1f21e8 b 0x1f209c <_ZN9CTimeLine9AddMomentEi+0x84>
 *   @0x1f21ec lsls r1, r9, #2
 *   @0x1f21f0 beq 0x1f2230 <_ZN9CTimeLine9AddMomentEi+0x218>
 *   @0x1f21f4 ldr r2, [pc, #0x50]
 *   @0x1f21f8 mov r3, #0
 *   @0x1f21fc ldr r0, [r7, #0xc]
 *   @0x1f2200 add r2, pc, r2
 *   @0x1f2204 str r3, [sp]
 *   @0x1f2208 mov r3, #135
 *   @0x1f220c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f2210 mov r2, r0
 *   @0x1f2214 str r0, [r7, #0xc]
 *   @0x1f2218 b 0x1f217c <_ZN9CTimeLine9AddMomentEi+0x164>
 *   @0x1f221c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2220 mov r3, #0
 *   @0x1f2224 mov r12, r3
 *   @0x1f2228 str r3, [r7, #0x14]
 *   @0x1f222c b 0x1f209c <_ZN9CTimeLine9AddMomentEi+0x84>
 *   @0x1f2230 ldr r3, [r7, #0xc]
 *   @0x1f2234 b 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150>
 *   @0x1f2238 lsl r6, r5, #2
 *   @0x1f223c ldr r0, [r0, #0x14]
 *   @0x1f2240 mov r4, r5
 *   @0x1f2244 b 0x1f206c <_ZN9CTimeLine9AddMomentEi+0x54>
 *   @0x1f2248 andseq r0, r6, r8, asr #12
 *   @0x1f224c mulseq r6, r0, r4
 *
 * ══ §36/54 F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*)  0x242c84  size 568  142 条（0x242c84..0x242ebc）
 * @func 0x242c84 0x242ebc  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x242ca8→0x756448, 0x242d20→0x544b48, 0x242d50→0x756450
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×6 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×4 / YYObjectBase::Add(char const*, YYObjectBase*, int)×2 / YYObjectBase::Alloc(unsigned int, int, bool)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / JS_SetupProperty(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), void (*)(RValue&, CInstance*, CInstance*, int, RValue*))
 * 字段偏移 top8: 0x4×6 / 0x8×3 / 0x18×2 / 0x28×2 / 0x1b4×2 / 0xc×2 / 0x1fc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242c84 push {r4, r5, r6, r7, r8, lr}
 *   @0x242c88 sub sp, sp, #8
 *   @0x242c8c ldr r5, [pc, #0x1fc]
 *   @0x242c90 mov r7, r0
 *   @0x242c94 ldr r12, [sp, #0x20]
 *   @0x242c98 mov r8, r3
 *   @0x242c9c add r5, pc, r5
 *   @0x242ca0 str r12, [sp]
 *   @0x242ca4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x242ca8 ldr r3, [pc, #0x1e4]
 *   @0x242cac ldr r4, [r7]
 *   @0x242cb0 ldr r3, [r5, r3]
 *   @0x242cb4 mov r0, r4
 *   @0x242cb8 ldr r1, [r3]
 *   @0x242cbc str r1, [r4, #0x18]
 *   @0x242cc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242cc4 ldr r3, [pc, #0x1cc]
 *   @0x242cc8 ldr r2, [r4, #0x28]
 *   @0x242ccc ldr r1, [pc, #0x1c8]
 *   @0x242cd0 orr r2, r2, #1
 *   @0x242cd4 str r2, [r4, #0x28]
 *   @0x242cd8 add r1, pc, r1
 *   @0x242cdc str r1, [r4, #0x40]
 *   @0x242ce0 ldr r1, [pc, #0x1b8]
 *   @0x242ce4 ldr r0, [r5, r3]
 *   @0x242ce8 ldr r2, [pc, #0x1b4]
 *   @0x242cec ldr r3, [pc, #0x1b4]
 *   @0x242cf0 str r0, [r4, #0x4c]
 *   @0x242cf4 ldr r1, [r5, r1]
 *   @0x242cf8 str r1, [r4, #0x54]
 *   @0x242cfc ldr r1, [r5, r3]
 *   @0x242d00 ldr r0, [r5, r2]
 *   @0x242d04 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_>
 *   @0x242d08 ldr r1, [pc, #0x19c]
 *   @0x242d0c mov r3, #6
 *   @0x242d10 add r1, pc, r1
 *   @0x242d14 mov r2, r0
 *   @0x242d18 mov r0, r4
 *   @0x242d1c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242d20 ldr r3, [pc, #0x188]
 *   @0x242d24 mvn r1, #-16777216
 *   @0x242d28 mov r2, #0
 *   @0x242d2c ldr r3, [r5, r3]
 *   @0x242d30 ldr r0, [r3]
 *   @0x242d34 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x242d38 ldr r1, [pc, #0x174]
 *   @0x242d3c ldr r2, [r7]
 *   @0x242d40 mov r3, #6
 *   @0x242d44 add r1, pc, r1
 *   @0x242d48 mov r6, r0
 *   @0x242d4c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242d50 ldr r3, [pc, #0x160]
 *   @0x242d54 mov r0, r6
 *   @0x242d58 ldr r3, [r5, r3]
 *   @0x242d5c ldr r1, [r3]
 *   @0x242d60 str r1, [r6, #0x18]
 *   @0x242d64 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242d68 ldr r1, [r4, #0x4]
 *   @0x242d6c cmp r1, #0
 *   @0x242d70 beq 0x242e00 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x242d74 str r6, [r1]
 *   @0x242d78 mov r0, r4
 *   @0x242d7c mov r1, r6
 *   @0x242d80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242d84 ldr r2, [r4, #0x4]
 *   @0x242d88 cmp r2, #0
 *   @0x242d8c movne r3, #6
 *   @0x242d90 strne r3, [r2, #0xc]
 *   @0x242d94 beq 0x242e10 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x242d98 mov r6, #0
 *   @0x242d9c mov r0, r8
 *   @0x242da0 str r6, [r2, #0x8]
 *   @0x242da4 mvn r1, #-16777216
 *   @0x242da8 mov r2, #1
 *   @0x242dac bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x242db0 mov r5, r0
 *   @0x242db4 ldr r0, [r4, #0x4]
 *   @0x242db8 str r6, [r5, #0x24]
 *   @0x242dbc cmp r0, r6
 *   @0x242dc0 beq 0x242e44 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x242dc4 add r0, r0, #16
 *   @0x242dc8 str r5, [r0]
 *   @0x242dcc mov r1, r5
 *   @0x242dd0 mov r0, r4
 *   @0x242dd4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242dd8 ldr r3, [r4, #0x4]
 *   @0x242ddc cmp r3, #0
 *   @0x242de0 beq 0x242e54 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x242de4 mov r2, #6
 *   @0x242de8 str r2, [r3, #0x1c]
 *   @0x242dec add r0, r3, #16
 *   @0x242df0 mov r2, #0
 *   @0x242df4 str r2, [r0, #0x8]
 *   @0x242df8 add sp, sp, #8
 *   @0x242dfc pop {r4, r5, r6, r7, r8, pc}
 *   @0x242e00 mov r0, r4
 *   @0x242e04 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e08 mov r1, r0
 *   @0x242e0c b 0x242d74 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x242e10 mov r1, r2
 *   @0x242e14 mov r0, r4
 *   @0x242e18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e1c ldr r2, [r4, #0x4]
 *   @0x242e20 mov r3, #6
 *   @0x242e24 cmp r2, #0
 *   @0x242e28 str r3, [r0, #0xc]
 *   @0x242e2c bne 0x242d98 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x242e30 mov r1, r2
 *   @0x242e34 mov r0, r4
 *   @0x242e38 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e3c mov r2, r0
 *   @0x242e40 b 0x242d98 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x242e44 mov r0, r4
 *   @0x242e48 mov r1, #1
 *   @0x242e4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e50 b 0x242dc8 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x242e54 mov r0, r4
 *   @0x242e58 mov r1, #1
 *   @0x242e5c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e60 ldr r3, [r4, #0x4]
 *   @0x242e64 mov r2, #6
 *   @0x242e68 cmp r3, #0
 *   @0x242e6c str r2, [r0, #0xc]
 *   @0x242e70 bne 0x242dec <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x242e74 mov r0, r4
 *   @0x242e78 mov r1, #1
 *   @0x242e7c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242e80 mov r2, #0
 *   @0x242e84 str r2, [r0, #0x8]
 *   @0x242e88 add sp, sp, #8
 *   @0x242e8c pop {r4, r5, r6, r7, r8, pc}
 *   @0x242e90 ldrheq lr, [r10], -r4
 *   @0x242e94 .word 0xfffff9b0
 *   @0x242e98 .word 0xfffff9b4
 *   @0x242e9c andeq r1, pc, r0, asr #24
 *   @0x242ea0 .word 0xfffff9b8
 *   @0x242ea4 .word 0xfffff9bc
 *   @0x242ea8 .word 0xfffff9c0
 *   @0x242eac andeq sp, lr, r12, asr r11
 *   @0x242eb0 .word 0xffffc0c4
 *   @0x242eb4 andseq r2, r1, r0, ror #15
 *   @0x242eb8 .word 0xffffc050
 *
 * ══ §37/54 F_JSObjectConstructor_Internal(RValue&, CInstance*, CInstance*, int, RValue*)  0x24eb38  size 568  142 条（0x24eb38..0x24ed70）
 * @func 0x24eb38 0x24ed70  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / F_JSObjectConstructor_Internal(RValue&, CInstance*, CInstance*, int, RValue*)+0xe8 / F_JS_ToObject(RValue&, RValue*) / GetContextStackTop() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×7 / 0x8×6 / 0x4×4 / 0x18×2 / 0x114×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24eb38 cmp r3, #0
 *   @0x24eb3c push {r4, r5, r6, r7, r8, lr}
 *   @0x24eb40 mov r5, r0
 *   @0x24eb44 ldr r4, [sp, #0x18]
 *   @0x24eb48 ble 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x24eb4c ldr r6, [r4, #0xc]
 *   @0x24eb50 bic r12, r6, #-16777216
 *   @0x24eb54 cmp r12, #13
 *   @0x24eb58 bhi 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x24eb5c mov r8, #1
 *   @0x24eb60 movw r7, #0x2483
 *   @0x24eb64 lsl r12, r8, r12
 *   @0x24eb68 and r7, r12, r7
 *   @0x24eb6c cmp r7, #0
 *   @0x24eb70 bne 0x24ec40 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x24eb74 tst r12, #64
 *   @0x24eb78 beq 0x24ec20 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x24eb7c ldr r2, [r0, #0xc]
 *   @0x24eb80 bic r3, r2, #-16777216
 *   @0x24eb84 cmp r3, r8
 *   @0x24eb88 beq 0x24ec60 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x24eb8c cmp r3, #2
 *   @0x24eb90 bne 0x24ebbc <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x24eb94 sub r3, r2, #1
 *   @0x24eb98 bic r3, r3, #-16777216
 *   @0x24eb9c bic r3, r3, #3
 *   @0x24eba0 cmp r3, #0
 *   @0x24eba4 beq 0x24ed0c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x24eba8 mov r2, #5
 *   @0x24ebac str r2, [r5, #0xc]
 *   @0x24ebb0 ldr r6, [r4, #0xc]
 *   @0x24ebb4 mov r3, #0
 *   @0x24ebb8 str r3, [r5, #0x8]
 *   @0x24ebbc ldr r2, [r4, #0x8]
 *   @0x24ebc0 mov r1, #0
 *   @0x24ebc4 str r6, [r5, #0xc]
 *   @0x24ebc8 ldr r3, [r4, #0xc]
 *   @0x24ebcc str r1, [r5]
 *   @0x24ebd0 bic r3, r3, #-16777216
 *   @0x24ebd4 str r2, [r5, #0x8]
 *   @0x24ebd8 cmp r3, #14
 *   @0x24ebdc addls pc, pc, r3, lsl #2
 *   @0x24ebe0 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ebe4 b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24ebe8 b 0x24ecc8 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x24ebec b 0x24ece0 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x24ebf0 b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x24ebf4 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ebf8 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ebfc b 0x24eca4 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x24ec00 b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x24ec04 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ec08 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ec0c b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24ec10 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ec14 b 0x24ec3c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24ec18 b 0x24ec98 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24ec1c b 0x24ec30 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x24ec20 str r4, [sp, #0x18]
 *   @0x24ec24 mov r0, r5
 *   @0x24ec28 pop {r4, r5, r6, r7, r8, lr}
 *   @0x24ec2c b 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24ec30 ldr r3, [r4]
 *   @0x24ec34 str r3, [r5]
 *   @0x24ec38 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24ec3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x24ec40 mov r1, r4
 *   @0x24ec44 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x24ec48 cmp r0, #1
 *   @0x24ec4c popne {r4, r5, r6, r7, r8, pc}
 *   @0x24ec50 ldr r0, [pc, #0x114]
 *   @0x24ec54 pop {r4, r5, r6, r7, r8, lr}
 *   @0x24ec58 add r0, pc, r0
 *   @0x24ec5c b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24ec60 ldr r7, [r0]
 *   @0x24ec64 cmp r7, #0
 *   @0x24ec68 beq 0x24ec8c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x24ec6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ec70 ldr r6, [r7, #0x4]
 *   @0x24ec74 sub r6, r6, #1
 *   @0x24ec78 str r6, [r7, #0x4]
 *   @0x24ec7c cmp r6, #0
 *   @0x24ec80 beq 0x24ed14 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x24ec84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24ec88 ldr r6, [r4, #0xc]
 *   @0x24ec8c mov r3, #0
 *   @0x24ec90 str r3, [r5]
 *   @0x24ec94 b 0x24ebbc <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x24ec98 ldm r4, {r2, r3}
 *   @0x24ec9c stm r5, {r2, r3}
 *   @0x24eca0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24eca4 ldr r3, [r4]
 *   @0x24eca8 str r3, [r5]
 *   @0x24ecac ldr r3, [r4]
 *   @0x24ecb0 cmp r3, #0
 *   @0x24ecb4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x24ecb8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24ecbc ldr r1, [r4]
 *   @0x24ecc0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x24ecc4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24ecc8 ldr r3, [r4]
 *   @0x24eccc cmp r3, #0
 *   @0x24ecd0 ldrne r2, [r3, #0x4]
 *   @0x24ecd4 addne r2, r2, #1
 *   @0x24ecd8 strne r2, [r3, #0x4]
 *   @0x24ecdc b 0x24ec34 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x24ece0 ldr r3, [r4]
 *   @0x24ece4 cmp r3, #0
 *   @0x24ece8 str r3, [r5]
 *   @0x24ecec popeq {r4, r5, r6, r7, r8, pc}
 *   @0x24ecf0 ldr r1, [r3, #0x8]
 *   @0x24ecf4 ldr r2, [r3]
 *   @0x24ecf8 cmp r1, #0
 *   @0x24ecfc streq r5, [r3, #0x8]
 *   @0x24ed00 add r2, r2, #1
 *   @0x24ed04 str r2, [r3]
 *   @0x24ed08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24ed0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24ed10 b 0x24eba8 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x24ed14 ldr r0, [r7]
 *   @0x24ed18 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ed1c str r6, [r7]
 *   @0x24ed20 str r6, [r7, #0x8]
 *   @0x24ed24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ed28 ldr r6, [r7, #0x4]
 *   @0x24ed2c sub r6, r6, #1
 *   @0x24ed30 str r6, [r7, #0x4]
 *   @0x24ed34 cmp r6, #0
 *   @0x24ed38 bne 0x24ed5c <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x24ed3c ldr r0, [r7]
 *   @0x24ed40 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ed44 mov r0, r7
 *   @0x24ed48 str r6, [r7]
 *   @0x24ed4c str r6, [r7, #0x8]
 *   @0x24ed50 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24ed54 mov r0, r7
 *   @0x24ed58 bl 0x27d1d0 <_ZdlPv>
 *   @0x24ed5c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24ed60 mov r0, r7
 *   @0x24ed64 bl 0x27d1d0 <_ZdlPv>
 *   @0x24ed68 b 0x24ec84 <_Z30F_JSObjectConstructor_InternalR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x24ed6c ldrsbeq r7, [r0], -r4
 *
 * ══ §38/54 png_read_finish_row  0x2ae25c  size 568  142 条（0x2ae25c..0x2ae494）
 * @func 0x2ae25c 0x2ae494  size 568  142 条
 * 部分覆盖: 本节 142/242 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error×2 / png_read_finish_row+0x218 / 0xb65b0 / anon_2f1de8+0x35b0 / __udivsi3 / png_crc_finish / 0xb6c40 / png_crc_read
 * 字段偏移 top8: 0x214×1 / 0x-54×1 / 0x-70×1 / 0x-38×1 / 0x8×1 / 0x6c×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae25c push {r4, r5, r6, r7, lr}
 *   @0x2ae260 ldr r6, [pc, #0x214]
 *   @0x2ae264 add r5, sp, #0x10
 *   @0x2ae268 add.w r7, r6, #0x24
 *   @0x2ae26c ldm r7!, {r0, r1, r2, r3}
 *   @0x2ae270 ldm.w r7, {r0, r1, r2}
 *   @0x2ae274 add.w r7, r6, #0x8
 *   @0x2ae278 stm.w r5, {r0, r1, r2}
 *   @0x2ae27c add r5, sp, #0x2c
 *   @0x2ae280 stm r5!, {r0, r1, r2, r3}
 *   @0x2ae284 .word 0xf1060007
 *   @0x2ae288 ldrblo r0, [r12], -r0, asr #14
 *   @0x2ae28c stm.w r5, {r0, r1, r2}
 *   @0x2ae290 add r5, sp, #0x48
 *   @0x2ae294 stm r5!, {r0, r1, r2, r3}
 *   @0x2ae298 stm r5, {r0, r1, r2}
 *   @0x2ae29c ldcge p0, c0, [r9, #-28]
 *   @0x2ae2a0 ldm r6!, {r0, r1, r2, r3}
 *   @0x2ae2a4 ldm.w r6, {r0, r1, r2}
 *   @0x2ae2a8 ldr.w r3, [r4, #0x1a8]
 *   @0x2ae2ac adds r3, #0x1
 *   @0x2ae2b0 stm r5, {r3, r5, r7, r8, r12, sp}
 *   @0x2ae2b4 .word 0xf8d40007
 *   @0x2ae2b8 addsmi r2, r3, #148, #2
 *   @0x2ae2bc blo.w 0x2ae474 <png_read_finish_row+0x218>
 *   @0x2ae2c0 ldrb.w r3, [r4, #0x1e7]
 *   @0x2ae2c4 cmp r3, #0x0
 *   @0x2ae2c8 ldr.w r2, [r4, #0x19c]
 *   @0x2ae2cc movs r1, #0x0
 *   @0x2ae2d0 .word 0xf8c401ac
 *   @0x2ae2d4 andlo r1, r1, #168, #2
 *   @0x2ae2d8 blx 0xb65b0 <memset@plt>
 *   @0x2ae2dc ldrb.w r5, [r4, #0x1e8]
 *   @0x2ae2e0 adds r5, #0x1
 *   @0x2ae2e4 cmp r5, #0x6
 *   @0x2ae2e8 strb.w r5, [r4, #0x1e8]
 *   @0x2ae2ec b 0x2ae342 <png_read_finish_row+0xe6>
 *   @0x2ae2f0 add.w r6, r3, r5, lsl #2
 *   @0x2ae2f4 ldr.w r3, [r4, #0x18c]
 *   @0x2ae2f8 ldr r1, [r6, #-84]
 *   @0x2ae2fc subs r3, #0x1
 *   @0x2ae300 ldr r3, [r6, #-112]
 *   @0x2ae304 subs r0, r0, r3
 *   @0x2ae308 .word 0xf8d4eca0
 *   @0x2ae30c .word 0x079a3134
 *   @0x2ae310 mov r7, r0
 *   @0x2ae314 .word 0xf10001a4
 *   @0x2ae318 .word 0xf8d480ab
 *   @0x2ae31c .word 0xf8563190
 *   @0x2ae320 bllo 0x2f5398 <ps_hints_apply+0x3f98>
 *   @0x2ae324 ldr r2, [r6, #-56]
 *   @0x2ae328 adds r0, r3, r1
 *   @0x2ae32c blx 0x318c48 <__udivsi3>
 *   @0x2ae330 adds r3, r5, #0x1
 *   @0x2ae334 str.w r0, [r4, #0x194]
 *   @0x2ae338 cmp r7, #0x0
 *   @0x2ae33c sadd8mi r8, sp, r9
 *   @0x2ae340 b 0x2ae2e4 <png_read_finish_row+0x88>
 *   @0x2ae344 .word 0x069b3130
 *   @0x2ae348 bmi 0x2ae444 <png_read_finish_row+0x1e8>
 *   @0x2ae34c add r5, sp, #0x8
 *   @0x2ae350 ldr r0, [r3]
 *   @0x2ae354 str r0, [sp, #0x8]
 *   @0x2ae358 .word 0xf10d300c
 *   @0x2ae35c .word 0xf8c40307
 *   @0x2ae360 movwhs r3, #0x1144
 *   @0x2ae364 str.w r3, [r4, #0x148]
 *   @0x2ae368 ldr.w r3, [r4, #0x13c]
 *   @0x2ae36c cbnz r3, 0x2ae3d6 <png_read_finish_row+0x17a>
 *   @0x2ae370 add r7, pc
 *   @0x2ae374 .word 0xf8d476f0
 *   @0x2ae378 stmiblt r3!, {r4, r6, r7, r8, r12, sp}
 *   @0x2ae37c mov r1, r3
 *   @0x2ae380 bl 0x2abc94 <png_crc_finish>
 *   @0x2ae384 mov r0, r4
 *   @0x2ae388 qadd16mi pc, r9, sp
 *   @0x2ae38c movs r2, #0x4
 *   @0x2ae390 .word 0x463001d0
 *   @0x2ae394 blx 0xb6c40 <memcmp@plt>
 *   @0x2ae398 cmp r0, #0x0
 *   @0x2ae39c mov r0, r4
 *   @0x2ae3a0 bl 0x2a642c <png_error>
 *   @0x2ae3a4 b 0x2ae372 <png_read_finish_row+0x116>
 *   @0x2ae3a8 qsub16mi r2, r0, r4
 *   @0x2ae3ac ldr.w r1, [r4, #0x170]
 *   @0x2ae3b0 cmp r2, r3
 *   @0x2ae3b4 .word 0xf8c4213c
 *   @0x2ae3b8 svclt #0x881138
 *   @0x2ae3bc strhi.w r3, [r4, #0x13c]
 *   @0x2ae3c0 ldr.w r2, [r4, #0x13c]
 *   @0x2ae3c4 bl 0x2abc0c <png_crc_read>
 *   @0x2ae3c8 ldr.w r2, [r4, #0x1d0]
 *   @0x2ae3cc ldr.w r3, [r4, #0x13c]
 *   @0x2ae3d0 subs r3, r2, r3
 *   @0x2ae3d4 .word 0xf50431d0
 *   @0x2ae3d8 swphs r7, r12, [r1]
 *   @0x2ae3dc blx 0xb69dc <inflate@plt>
 *   @0x2ae3e0 cmp r0, #0x1
 *   @0x2ae3e4 ldr.w r3, [r4, #0x148]
 *   @0x2ae3e8 cbz r3, 0x2ae3f6 <png_read_finish_row+0x19a>
 *   @0x2ae3ec ldmdblt r3, {r2, r3, r4, r5, r8, r12, sp}
 *   @0x2ae3f0 ldr.w r3, [r4, #0x1d0]
 *   @0x2ae3f4 cbz r3, 0x2ae426 <png_read_finish_row+0x1ca>
 *   @0x2ae3f8 mov r0, r4
 *   @0x2ae3fc b 0x2ae422 <png_read_finish_row+0x1c6>
 *   @0x2ae400 ldr.w r3, [r4, #0x150]
 *   @0x2ae404 cbnz r3, 0x2ae40c <png_read_finish_row+0x1b0>
 *   @0x2ae408 add r1, pc
 *   @0x2ae40c mov r1, r3
 *   @0x2ae410 bl 0x2a642c <png_error>
 *   @0x2ae414 ldr.w r3, [r4, #0x148]
 *   @0x2ae418 cmp r3, #0x0
 *   @0x2ae41c ldr r1, [pc, #0x6c]
 *   @0x2ae420 add r1, pc
 *   @0x2ae424 .word 0xf8d4f827
 *   @0x2ae428 .word 0xf043312c
 *   @0x2ae42c .word 0xf8c40308
 *   @0x2ae430 .word 0xf8d4312c
 *   @0x2ae434 .word 0xf0433130
 *   @0x2ae438 .word 0xf8c40320
 *   @0x2ae43c movwhs r3, #0x130
 *   @0x2ae440 str.w r3, [r4, #0x148]
 *   @0x2ae444 ldr.w r3, [r4, #0x1d0]
 *   @0x2ae448 cbnz r3, 0x2ae450 <png_read_finish_row+0x1f4>
 *   @0x2ae44c .word 0xb123313c
 *   @0x2ae450 ldr r1, [pc, #0x3c]
 *   @0x2ae454 add r1, pc
 *   @0x2ae458 .word 0xf504f80d
 *   @0x2ae45c .word 0xf608709c
 *   @0x2ae460 .word 0xf8d4ed70
 *   @0x2ae464 .word 0xf043312c
 *   @0x2ae468 .word 0xf8c40308
 *   @0x2ae46c and r3, r1, r12, lsr #2
 *   @0x2ae470 strb.w r5, [r4, #0x1e8]
 *   @0x2ae474 add sp, #0x84
 *   @0x2ae478 asrs r2, r0, #0x1e
 *   @0x2ae47c asrs r2, r3, #0x1a
 *   @0x2ae480 b 0x2adeac <png_do_read_interlace+0x90>
 *   @0x2ae484 b 0x2addc8 <png_combine_row+0x198>
 *   @0x2ae488 .word 0xf616 000d
 *   @0x2ae48c b 0x2add84 <png_combine_row+0x154>
 *   @0x2ae490 rsbs.w r0, lr, #0x8d0000
 *
 * ══ §39/54 b2MotorJoint::SolveVelocityConstraints(b2SolverData const&)  0x2ce18c  size 568  142 条（0x2ce18c..0x2ce3c4）
 * @func 0x2ce18c 0x2ce3c4  size 568  142 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x68×2 / 0x6c×2 / 0x1c×2 / 0x4×2
 * VFP 指令 115 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce18c push {r4, r5, lr}
 *   @0x2ce190 vldr s10, [r0, #100]
 *   @0x2ce194 mov r4, r0
 *   @0x2ce198 vldr s15, [r1, #4]
 *   @0x2ce19c ldr r5, [r0, #0x68]
 *   @0x2ce1a0 vmul.f32 s10, s10, s15
 *   @0x2ce1a4 ldr r12, [r0, #0x6c]
 *   @0x2ce1a8 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2ce1ac ldr r0, [r1, #0x1c]
 *   @0x2ce1b0 vldr s14, [r4, #152]
 *   @0x2ce1b4 add r2, r5, r5, lsl #1
 *   @0x2ce1b8 vldr s13, [r4, #88]
 *   @0x2ce1bc add r3, r12, r12, lsl #1
 *   @0x2ce1c0 vldr s15, [r4, #188]
 *   @0x2ce1c4 add r2, r0, r2, lsl #2
 *   @0x2ce1c8 vldr s17, [r2, #8]
 *   @0x2ce1cc add r3, r0, r3, lsl #2
 *   @0x2ce1d0 vldr s16, [r3, #8]
 *   @0x2ce1d4 vldr s4, [r1]
 *   @0x2ce1d8 vldr s9, [r4, #96]
 *   @0x2ce1dc vldr s28, [r4, #148]
 *   @0x2ce1e0 vldr s24, [r4, #168]
 *   @0x2ce1e4 vldr s18, [r3, #4]
 *   @0x2ce1e8 vldr s7, [r4, #120]
 *   @0x2ce1ec vldr s25, [r4, #164]
 *   @0x2ce1f0 vldr s20, [r3]
 *   @0x2ce1f4 vldr s5, [r4, #124]
 *   @0x2ce1f8 vldr s22, [r2, #4]
 *   @0x2ce1fc vsub.f32 s8, s16, s17
 *   @0x2ce200 vldr s6, [r4, #112]
 *   @0x2ce204 vldr s23, [r2]
 *   @0x2ce208 vldr s12, [r4, #116]
 *   @0x2ce20c vldr s0, [r4, #144]
 *   @0x2ce210 vldr s11, [r4, #184]
 *   @0x2ce214 vldr s1, [r4, #180]
 *   @0x2ce218 vldr s2, [r4, #176]
 *   @0x2ce21c vldr s3, [r4, #172]
 *   @0x2ce220 vldr s26, [r4, #84]
 *   @0x2ce224 vldr s27, [r4, #80]
 *   @0x2ce228 vldr s21, [r4, #156]
 *   @0x2ce22c vldr s19, [r4, #160]
 *   @0x2ce230 sub sp, sp, #12
 *   @0x2ce234 vmla.f32 s8, s10, s14
 *   @0x2ce238 vmov.f32 s14, s13
 *   @0x2ce23c vmls.f32 s14, s15, s8
 *   @0x2ce240 vmul.f32 s9, s4, s9
 *   @0x2ce244 vcmpe.f32 s9, s14
 *   @0x2ce248 vneg.f32 s15, s9
 *   @0x2ce24c vmrs APSR_nzcv, fpscr
 *   @0x2ce250 vmovgt.f32 s9, s14
 *   @0x2ce254 vcmpe.f32 s15, s9
 *   @0x2ce258 vmrs APSR_nzcv, fpscr
 *   @0x2ce25c vmovgt.f32 s9, s15
 *   @0x2ce260 vstr s9, [r4, #88]
 *   @0x2ce264 vsub.f32 s9, s9, s13
 *   @0x2ce268 vmla.f32 s16, s24, s9
 *   @0x2ce26c vmov.f32 s14, s18
 *   @0x2ce270 vmla.f32 s14, s16, s7
 *   @0x2ce274 vmov.f32 s15, s20
 *   @0x2ce278 vmls.f32 s17, s25, s9
 *   @0x2ce27c vmls.f32 s15, s16, s5
 *   @0x2ce280 vsub.f32 s14, s14, s22
 *   @0x2ce284 vmls.f32 s14, s17, s6
 *   @0x2ce288 vsub.f32 s15, s15, s23
 *   @0x2ce28c vmla.f32 s15, s17, s12
 *   @0x2ce290 vmla.f32 s14, s10, s28
 *   @0x2ce294 vldr s28, [r4, #92]
 *   @0x2ce298 vmla.f32 s15, s10, s0
 *   @0x2ce29c vmul.f32 s11, s14, s11
 *   @0x2ce2a0 vmul.f32 s14, s14, s1
 *   @0x2ce2a4 vmla.f32 s11, s15, s2
 *   @0x2ce2a8 vmla.f32 s14, s15, s3
 *   @0x2ce2ac vsub.f32 s15, s26, s11
 *   @0x2ce2b0 vmul.f32 s13, s15, s15
 *   @0x2ce2b4 vstr s15, [r4, #84]
 *   @0x2ce2b8 vsub.f32 s14, s27, s14
 *   @0x2ce2bc vmul.f32 s28, s4, s28
 *   @0x2ce2c0 vstr s14, [r4, #80]
 *   @0x2ce2c4 vmla.f32 s13, s14, s14
 *   @0x2ce2c8 vmul.f32 s11, s28, s28
 *   @0x2ce2cc vcmpe.f32 s11, s13
 *   @0x2ce2d0 vmrs APSR_nzcv, fpscr
 *   @0x2ce2d4 bmi 0x2ce32c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x1a0>
 *   @0x2ce2d8 vsub.f32 s14, s14, s27
 *   @0x2ce2dc vmul.f32 s12, s14, s12
 *   @0x2ce2e0 vmul.f32 s13, s14, s5
 *   @0x2ce2e4 vsub.f32 s15, s15, s26
 *   @0x2ce2e8 vnmls.f32 s12, s15, s6
 *   @0x2ce2ec vnmls.f32 s13, s15, s7
 *   @0x2ce2f0 vmls.f32 s17, s25, s12
 *   @0x2ce2f4 vmla.f32 s16, s24, s13
 *   @0x2ce2f8 vstr s17, [r2, #8]
 *   @0x2ce2fc vmls.f32 s23, s21, s14
 *   @0x2ce300 vmls.f32 s22, s21, s15
 *   @0x2ce304 vstr s23, [r2]
 *   @0x2ce308 vmla.f32 s20, s19, s14
 *   @0x2ce30c vstr s22, [r2, #4]
 *   @0x2ce310 vstr s16, [r3, #8]
 *   @0x2ce314 vmla.f32 s18, s19, s15
 *   @0x2ce318 vstr s20, [r3]
 *   @0x2ce31c vstr s18, [r3, #4]
 *   @0x2ce320 add sp, sp, #12
 *   @0x2ce324 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2ce328 pop {r4, r5, pc}
 *   @0x2ce32c vsqrt.f32 s11, s13
 *   @0x2ce330 vcmp.f32 s11, s11
 *   @0x2ce334 vmrs APSR_nzcv, fpscr
 *   @0x2ce338 bne 0x2ce38c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2ce33c vldr s15, [pc, #124]
 *   @0x2ce340 vcmpe.f32 s11, s15
 *   @0x2ce344 add r5, r5, r5, lsl #1
 *   @0x2ce348 add r12, r12, r12, lsl #1
 *   @0x2ce34c add r2, r0, r5, lsl #2
 *   @0x2ce350 add r3, r0, r12, lsl #2
 *   @0x2ce354 vmrs APSR_nzcv, fpscr
 *   @0x2ce358 vmovpl.f32 s13, #1.000000e+00
 *   @0x2ce35c vldrpl s15, [r4, #84]
 *   @0x2ce360 vldrpl s14, [r4, #80]
 *   @0x2ce364 vldrmi s14, [r4, #80]
 *   @0x2ce368 vldrmi s15, [r4, #84]
 *   @0x2ce36c vdivpl.f32 s11, s13, s11
 *   @0x2ce370 vmulpl.f32 s15, s11, s15
 *   @0x2ce374 vmulpl.f32 s14, s11, s14
 *   @0x2ce378 vmul.f32 s15, s28, s15
 *   @0x2ce37c vmul.f32 s14, s28, s14
 *   @0x2ce380 vstr s15, [r4, #84]
 *   @0x2ce384 vstr s14, [r4, #80]
 *   @0x2ce388 b 0x2ce2d8 <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c>
 *   @0x2ce38c vmov r0, s13
 *   @0x2ce390 str r1, [sp, #0x4]
 *   @0x2ce394 bl 0xb6700 <sqrtf@plt>
 *   @0x2ce398 ldr r1, [sp, #0x4]
 *   @0x2ce39c vldr s5, [r4, #124]
 *   @0x2ce3a0 ldr r5, [r4, #0x68]
 *   @0x2ce3a4 vldr s7, [r4, #120]
 *   @0x2ce3a8 ldr r12, [r4, #0x6c]
 *   @0x2ce3ac vldr s12, [r4, #116]
 *   @0x2ce3b0 vldr s6, [r4, #112]
 *   @0x2ce3b4 vmov s11, r0
 *   @0x2ce3b8 ldr r0, [r1, #0x1c]
 *   @0x2ce3bc b 0x2ce33c <_ZN12b2MotorJoint24SolveVelocityConstraintsERK12b2SolverData+0x1b0>
 *   @0x2ce3c0 strlo r0, [r0], #-0
 *
 * ══ §40/54 GetActiveList(void (*)(CInstance*))  0x10b24c  size 564  141 条（0x10b24c..0x10b480）
 * @func 0x10b24c 0x10b480  size 564  141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×8 / 0x68×4 / 0x178×4 / 0x69×4 / 0x4×4 / 0x2×2 / 0x210×1 / 0x1fc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b24c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x10b250 mov r6, r0
 *   @0x10b254 ldr r7, [pc, #0x210]
 *   @0x10b258 sub sp, sp, #8
 *   @0x10b25c ldr r7, [pc, r7]
 *   @0x10b260 ldr r4, [r7]
 *   @0x10b264 cmp r4, #0
 *   @0x10b268 beq 0x10b3d0 <_Z13GetActiveListPFvP9CInstanceE+0x184>
 *   @0x10b26c ldr r8, [pc, #0x1fc]
 *   @0x10b270 mov r3, #0
 *   @0x10b274 str r3, [r4, #0x8]
 *   @0x10b278 ldr r8, [pc, r8]
 *   @0x10b27c ldr r3, [r8]
 *   @0x10b280 ldr r4, [r3, #0x80]
 *   @0x10b284 cmp r4, #0
 *   @0x10b288 beq 0x10b2c8 <_Z13GetActiveListPFvP9CInstanceE+0x7c>
 *   @0x10b28c cmp r6, #0
 *   @0x10b290 beq 0x10b318 <_Z13GetActiveListPFvP9CInstanceE+0xcc>
 *   @0x10b294 ldrb r3, [r4, #0x68]
 *   @0x10b298 ldr r5, [r4, #0x178]
 *   @0x10b29c cmp r3, #0
 *   @0x10b2a0 bne 0x10b2b8 <_Z13GetActiveListPFvP9CInstanceE+0x6c>
 *   @0x10b2a4 ldrb r3, [r4, #0x69]
 *   @0x10b2a8 mov r0, r4
 *   @0x10b2ac cmp r3, #0
 *   @0x10b2b0 bne 0x10b2b8 <_Z13GetActiveListPFvP9CInstanceE+0x6c>
 *   @0x10b2b4 blx r6
 *   @0x10b2b8 cmp r5, #0
 *   @0x10b2bc mov r4, r5
 *   @0x10b2c0 bne 0x10b294 <_Z13GetActiveListPFvP9CInstanceE+0x48>
 *   @0x10b2c4 ldr r3, [r8]
 *   @0x10b2c8 ldr r4, [r3, #0x8c]
 *   @0x10b2cc cmp r4, #0
 *   @0x10b2d0 beq 0x10b30c <_Z13GetActiveListPFvP9CInstanceE+0xc0>
 *   @0x10b2d4 cmp r6, #0
 *   @0x10b2d8 beq 0x10b370 <_Z13GetActiveListPFvP9CInstanceE+0x124>
 *   @0x10b2dc ldrb r3, [r4, #0x68]
 *   @0x10b2e0 ldr r5, [r4, #0x178]
 *   @0x10b2e4 cmp r3, #0
 *   @0x10b2e8 bne 0x10b300 <_Z13GetActiveListPFvP9CInstanceE+0xb4>
 *   @0x10b2ec ldrb r3, [r4, #0x69]
 *   @0x10b2f0 mov r0, r4
 *   @0x10b2f4 cmp r3, #0
 *   @0x10b2f8 bne 0x10b300 <_Z13GetActiveListPFvP9CInstanceE+0xb4>
 *   @0x10b2fc blx r6
 *   @0x10b300 cmp r5, #0
 *   @0x10b304 mov r4, r5
 *   @0x10b308 bne 0x10b2dc <_Z13GetActiveListPFvP9CInstanceE+0x90>
 *   @0x10b30c ldr r0, [r7]
 *   @0x10b310 add sp, sp, #8
 *   @0x10b314 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x10b318 ldr r10, [pc, #0x154]
 *   @0x10b31c add r10, pc, r10
 *   @0x10b320 ldrb r3, [r4, #0x68]
 *   @0x10b324 ldr r5, [r4, #0x178]
 *   @0x10b328 cmp r3, #0
 *   @0x10b32c bne 0x10b360 <_Z13GetActiveListPFvP9CInstanceE+0x114>
 *   @0x10b330 ldrb r12, [r4, #0x69]
 *   @0x10b334 cmp r12, #0
 *   @0x10b338 bne 0x10b360 <_Z13GetActiveListPFvP9CInstanceE+0x114>
 *   @0x10b33c ldr r9, [r7]
 *   @0x10b340 ldr r3, [r9, #0x4]
 *   @0x10b344 ldr r1, [r9, #0x8]
 *   @0x10b348 cmp r1, r3
 *   @0x10b34c ldrne r3, [r9]
 *   @0x10b350 beq 0x10b40c <_Z13GetActiveListPFvP9CInstanceE+0x1c0>
 *   @0x10b354 str r4, [r3, r1, lsl #2]
 *   @0x10b358 add r1, r1, #1
 *   @0x10b35c str r1, [r9, #0x8]
 *   @0x10b360 cmp r5, #0
 *   @0x10b364 mov r4, r5
 *   @0x10b368 bne 0x10b320 <_Z13GetActiveListPFvP9CInstanceE+0xd4>
 *   @0x10b36c b 0x10b2c4 <_Z13GetActiveListPFvP9CInstanceE+0x78>
 *   @0x10b370 ldr r8, [pc, #0x100]
 *   @0x10b374 add r8, pc, r8
 *   @0x10b378 ldrb r3, [r4, #0x68]
 *   @0x10b37c ldr r5, [r4, #0x178]
 *   @0x10b380 cmp r3, #0
 *   @0x10b384 bne 0x10b3b8 <_Z13GetActiveListPFvP9CInstanceE+0x16c>
 *   @0x10b388 ldrb r12, [r4, #0x69]
 *   @0x10b38c cmp r12, #0
 *   @0x10b390 bne 0x10b3b8 <_Z13GetActiveListPFvP9CInstanceE+0x16c>
 *   @0x10b394 ldr r6, [r7]
 *   @0x10b398 ldr r3, [r6, #0x4]
 *   @0x10b39c ldr r1, [r6, #0x8]
 *   @0x10b3a0 cmp r1, r3
 *   @0x10b3a4 ldrne r3, [r6]
 *   @0x10b3a8 beq 0x10b43c <_Z13GetActiveListPFvP9CInstanceE+0x1f0>
 *   @0x10b3ac str r4, [r3, r1, lsl #2]
 *   @0x10b3b0 add r1, r1, #1
 *   @0x10b3b4 str r1, [r6, #0x8]
 *   @0x10b3b8 cmp r5, #0
 *   @0x10b3bc mov r4, r5
 *   @0x10b3c0 bne 0x10b378 <_Z13GetActiveListPFvP9CInstanceE+0x12c>
 *   @0x10b3c4 ldr r0, [r7]
 *   @0x10b3c8 add sp, sp, #8
 *   @0x10b3cc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x10b3d0 mov r0, #12
 *   @0x10b3d4 bl 0x27c524 <_Znwj>
 *   @0x10b3d8 ldr r1, [pc, #0x9c]
 *   @0x10b3dc mov r3, #1
 *   @0x10b3e0 mov r2, #50
 *   @0x10b3e4 add r1, pc, r1
 *   @0x10b3e8 mov r5, r0
 *   @0x10b3ec mov r0, #128
 *   @0x10b3f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x10b3f4 str r4, [r5, #0x8]
 *   @0x10b3f8 mov r3, #32
 *   @0x10b3fc mov r4, r5
 *   @0x10b400 stm r5, {r0, r3}
 *   @0x10b404 str r5, [r7]
 *   @0x10b408 b 0x10b26c <_Z13GetActiveListPFvP9CInstanceE+0x20>
 *   @0x10b40c lsl r3, r1, #1
 *   @0x10b410 ldr r0, [r9]
 *   @0x10b414 str r3, [r9, #0x4]
 *   @0x10b418 lsl r1, r1, #3
 *   @0x10b41c mov r3, #74
 *   @0x10b420 mov r2, r10
 *   @0x10b424 str r12, [sp]
 *   @0x10b428 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10b42c ldr r1, [r9, #0x8]
 *   @0x10b430 mov r3, r0
 *   @0x10b434 str r0, [r9]
 *   @0x10b438 b 0x10b354 <_Z13GetActiveListPFvP9CInstanceE+0x108>
 *   @0x10b43c lsl r3, r1, #1
 *   @0x10b440 ldr r0, [r6]
 *   @0x10b444 str r3, [r6, #0x4]
 *   @0x10b448 lsl r1, r1, #3
 *   @0x10b44c mov r3, #74
 *   @0x10b450 mov r2, r8
 *   @0x10b454 str r12, [sp]
 *   @0x10b458 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10b45c ldr r1, [r6, #0x8]
 *   @0x10b460 mov r3, r0
 *   @0x10b464 str r0, [r6]
 *   @0x10b468 b 0x10b3ac <_Z13GetActiveListPFvP9CInstanceE+0x160>
 *   @0x10b46c eoreq r2, lr, r12, asr lr
 *   @0x10b470 .word 0x002e26b0
 *   @0x10b474 eoreq r5, r2, r4, lsl sp
 *   @0x10b478 .word 0x00225cbc
 *   @0x10b47c eoreq sp, r2, r4, lsl r3
 *
 * ══ §41/54 GetVariable(RValue*, RValue*)  0x1f6ac0  size 564  141 条（0x1f6ac0..0x1f6cf4）
 * @func 0x1f6ac0 0x1f6cf4  size 564  141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / GetContextStackTop() / FREE_RValue__Pre(RValue*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x8×8 / 0x4×8 / 0xc×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6ac0 ldr r2, [r0, #0xc]
 *   @0x1f6ac4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1f6ac8 bic r3, r2, #-16777216
 *   @0x1f6acc cmp r3, #1
 *   @0x1f6ad0 mov r4, r0
 *   @0x1f6ad4 mov r5, r1
 *   @0x1f6ad8 beq 0x1f6b88 <_Z11GetVariableP6RValueS0_+0xc8>
 *   @0x1f6adc cmp r3, #2
 *   @0x1f6ae0 bne 0x1f6b08 <_Z11GetVariableP6RValueS0_+0x48>
 *   @0x1f6ae4 sub r2, r2, #1
 *   @0x1f6ae8 bic r2, r2, #-16777216
 *   @0x1f6aec bic r2, r2, #3
 *   @0x1f6af0 cmp r2, #0
 *   @0x1f6af4 beq 0x1f6c5c <_Z11GetVariableP6RValueS0_+0x19c>
 *   @0x1f6af8 mov r2, #0
 *   @0x1f6afc mov r3, #5
 *   @0x1f6b00 str r2, [r4, #0x8]
 *   @0x1f6b04 str r3, [r4, #0xc]
 *   @0x1f6b08 ldr r3, [r5, #0xc]
 *   @0x1f6b0c mov r1, #0
 *   @0x1f6b10 ldr r2, [r5, #0x8]
 *   @0x1f6b14 str r1, [r4]
 *   @0x1f6b18 str r3, [r4, #0xc]
 *   @0x1f6b1c ldr r3, [r5, #0xc]
 *   @0x1f6b20 str r2, [r4, #0x8]
 *   @0x1f6b24 bic r3, r3, #-16777216
 *   @0x1f6b28 cmp r3, #14
 *   @0x1f6b2c addls pc, pc, r3, lsl #2
 *   @0x1f6b30 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b34 b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc>
 *   @0x1f6b38 b 0x1f6be0 <_Z11GetVariableP6RValueS0_+0x120>
 *   @0x1f6b3c b 0x1f6bf8 <_Z11GetVariableP6RValueS0_+0x138>
 *   @0x1f6b40 b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0>
 *   @0x1f6b44 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b48 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b4c b 0x1f6bbc <_Z11GetVariableP6RValueS0_+0xfc>
 *   @0x1f6b50 b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0>
 *   @0x1f6b54 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b58 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b5c b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc>
 *   @0x1f6b60 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b64 b 0x1f6b78 <_Z11GetVariableP6RValueS0_+0xb8>
 *   @0x1f6b68 b 0x1f6b7c <_Z11GetVariableP6RValueS0_+0xbc>
 *   @0x1f6b6c b 0x1f6b70 <_Z11GetVariableP6RValueS0_+0xb0>
 *   @0x1f6b70 ldr r3, [r5]
 *   @0x1f6b74 str r3, [r4]
 *   @0x1f6b78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1f6b7c ldm r5, {r2, r3}
 *   @0x1f6b80 stm r4, {r2, r3}
 *   @0x1f6b84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1f6b88 ldr r6, [r0]
 *   @0x1f6b8c cmp r6, #0
 *   @0x1f6b90 beq 0x1f6bb0 <_Z11GetVariableP6RValueS0_+0xf0>
 *   @0x1f6b94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6b98 ldr r7, [r6, #0x4]
 *   @0x1f6b9c sub r7, r7, #1
 *   @0x1f6ba0 str r7, [r6, #0x4]
 *   @0x1f6ba4 cmp r7, #0
 *   @0x1f6ba8 beq 0x1f6c24 <_Z11GetVariableP6RValueS0_+0x164>
 *   @0x1f6bac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6bb0 mov r3, #0
 *   @0x1f6bb4 str r3, [r4]
 *   @0x1f6bb8 b 0x1f6b08 <_Z11GetVariableP6RValueS0_+0x48>
 *   @0x1f6bbc ldr r3, [r5]
 *   @0x1f6bc0 str r3, [r4]
 *   @0x1f6bc4 ldr r3, [r5]
 *   @0x1f6bc8 cmp r3, #0
 *   @0x1f6bcc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1f6bd0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f6bd4 ldr r1, [r5]
 *   @0x1f6bd8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1f6bdc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f6be0 ldr r3, [r5]
 *   @0x1f6be4 cmp r3, #0
 *   @0x1f6be8 ldrne r2, [r3, #0x4]
 *   @0x1f6bec addne r2, r2, #1
 *   @0x1f6bf0 strne r2, [r3, #0x4]
 *   @0x1f6bf4 b 0x1f6b74 <_Z11GetVariableP6RValueS0_+0xb4>
 *   @0x1f6bf8 ldr r3, [r5]
 *   @0x1f6bfc cmp r3, #0
 *   @0x1f6c00 str r3, [r4]
 *   @0x1f6c04 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1f6c08 ldr r1, [r3, #0x8]
 *   @0x1f6c0c ldr r2, [r3]
 *   @0x1f6c10 cmp r1, #0
 *   @0x1f6c14 streq r4, [r3, #0x8]
 *   @0x1f6c18 add r2, r2, #1
 *   @0x1f6c1c str r2, [r3]
 *   @0x1f6c20 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1f6c24 ldr r0, [r6]
 *   @0x1f6c28 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6c2c str r7, [r6]
 *   @0x1f6c30 str r7, [r6, #0x8]
 *   @0x1f6c34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6c38 ldr r7, [r6, #0x4]
 *   @0x1f6c3c sub r7, r7, #1
 *   @0x1f6c40 str r7, [r6, #0x4]
 *   @0x1f6c44 cmp r7, #0
 *   @0x1f6c48 beq 0x1f6c64 <_Z11GetVariableP6RValueS0_+0x1a4>
 *   @0x1f6c4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6c50 mov r0, r6
 *   @0x1f6c54 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6c58 b 0x1f6bac <_Z11GetVariableP6RValueS0_+0xec>
 *   @0x1f6c5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6c60 b 0x1f6af8 <_Z11GetVariableP6RValueS0_+0x38>
 *   @0x1f6c64 ldr r0, [r6]
 *   @0x1f6c68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6c6c str r7, [r6]
 *   @0x1f6c70 str r7, [r6, #0x8]
 *   @0x1f6c74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6c78 ldr r7, [r6, #0x4]
 *   @0x1f6c7c sub r7, r7, #1
 *   @0x1f6c80 str r7, [r6, #0x4]
 *   @0x1f6c84 cmp r7, #0
 *   @0x1f6c88 beq 0x1f6c9c <_Z11GetVariableP6RValueS0_+0x1dc>
 *   @0x1f6c8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6c90 mov r0, r6
 *   @0x1f6c94 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6c98 b 0x1f6c4c <_Z11GetVariableP6RValueS0_+0x18c>
 *   @0x1f6c9c ldr r0, [r6]
 *   @0x1f6ca0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6ca4 str r7, [r6]
 *   @0x1f6ca8 str r7, [r6, #0x8]
 *   @0x1f6cac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6cb0 ldr r7, [r6, #0x4]
 *   @0x1f6cb4 sub r7, r7, #1
 *   @0x1f6cb8 str r7, [r6, #0x4]
 *   @0x1f6cbc cmp r7, #0
 *   @0x1f6cc0 bne 0x1f6ce4 <_Z11GetVariableP6RValueS0_+0x224>
 *   @0x1f6cc4 ldr r0, [r6]
 *   @0x1f6cc8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6ccc mov r0, r6
 *   @0x1f6cd0 str r7, [r6]
 *   @0x1f6cd4 str r7, [r6, #0x8]
 *   @0x1f6cd8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f6cdc mov r0, r6
 *   @0x1f6ce0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6ce4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6ce8 mov r0, r6
 *   @0x1f6cec bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6cf0 b 0x1f6c8c <_Z11GetVariableP6RValueS0_+0x1cc>
 *
 * ══ §42/54 res0_unpack  0x22dfa4  size 564  141 条（0x22dfa4..0x22e1d8）
 * @func 0x22dfa4 0x22e1d8  size 564  141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×9 / res0_unpack+0x12c×7 / 0xb6c34 / res0_unpack+0x220 / res0_free_info / res0_unpack+0x1d8
 * 字段偏移 top8: 0x4×6 / 0xc×6 / 0x1c×3 / 0x2×3 / 0x14×2 / 0x8×1 / 0x118×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22dfa4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x22dfa8 mov r4, r1
 *   @0x22dfac mov r5, r0
 *   @0x22dfb0 movw r1, #0x918
 *   @0x22dfb4 mov r0, #1
 *   @0x22dfb8 bl 0xb6c34 <calloc@plt>
 *   @0x22dfbc mov r1, #24
 *   @0x22dfc0 ldr r8, [r5, #0x1c]
 *   @0x22dfc4 mov r7, r0
 *   @0x22dfc8 mov r0, r4
 *   @0x22dfcc bl 0x233b28 <oggpack_read>
 *   @0x22dfd0 mov r1, #24
 *   @0x22dfd4 str r0, [r7]
 *   @0x22dfd8 mov r0, r4
 *   @0x22dfdc bl 0x233b28 <oggpack_read>
 *   @0x22dfe0 mov r1, #24
 *   @0x22dfe4 str r0, [r7, #0x4]
 *   @0x22dfe8 mov r0, r4
 *   @0x22dfec bl 0x233b28 <oggpack_read>
 *   @0x22dff0 mov r1, #6
 *   @0x22dff4 add r3, r0, #1
 *   @0x22dff8 mov r0, r4
 *   @0x22dffc str r3, [r7, #0x8]
 *   @0x22e000 bl 0x233b28 <oggpack_read>
 *   @0x22e004 mov r1, #8
 *   @0x22e008 add r3, r0, #1
 *   @0x22e00c mov r0, r4
 *   @0x22e010 str r3, [r7, #0xc]
 *   @0x22e014 bl 0x233b28 <oggpack_read>
 *   @0x22e018 cmp r0, #0
 *   @0x22e01c str r0, [r7, #0x14]
 *   @0x22e020 blt 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e024 ldr r3, [r7, #0xc]
 *   @0x22e028 cmp r3, #0
 *   @0x22e02c ble 0x22e1c4 <res0_unpack+0x220>
 *   @0x22e030 mov r5, #0
 *   @0x22e034 add r6, r7, #20
 *   @0x22e038 mov r10, r5
 *   @0x22e03c mov r1, #3
 *   @0x22e040 mov r0, r4
 *   @0x22e044 bl 0x233b28 <oggpack_read>
 *   @0x22e048 mov r1, #1
 *   @0x22e04c mov r9, r0
 *   @0x22e050 mov r0, r4
 *   @0x22e054 bl 0x233b28 <oggpack_read>
 *   @0x22e058 cmp r0, #0
 *   @0x22e05c blt 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e060 bne 0x22e0e0 <res0_unpack+0x13c>
 *   @0x22e064 subs r3, r9, #0
 *   @0x22e068 str r9, [r6, #0x4]!
 *   @0x22e06c beq 0x22e104 <res0_unpack+0x160>
 *   @0x22e070 mov r2, #0
 *   @0x22e074 and r12, r3, #1
 *   @0x22e078 lsrs r3, r3, #1
 *   @0x22e07c add r2, r12, r2
 *   @0x22e080 bne 0x22e074 <res0_unpack+0xd0>
 *   @0x22e084 ldr r3, [r7, #0xc]
 *   @0x22e088 add r10, r10, #1
 *   @0x22e08c add r5, r5, r2
 *   @0x22e090 cmp r3, r10
 *   @0x22e094 bgt 0x22e03c <res0_unpack+0x98>
 *   @0x22e098 cmp r5, #0
 *   @0x22e09c addgt r9, r7, #276
 *   @0x22e0a0 movgt r6, #0
 *   @0x22e0a4 bgt 0x22e0b8 <res0_unpack+0x114>
 *   @0x22e0a8 b 0x22e10c <res0_unpack+0x168>
 *   @0x22e0ac cmp r6, r5
 *   @0x22e0b0 str r0, [r9, #0x4]!
 *   @0x22e0b4 beq 0x22e10c <res0_unpack+0x168>
 *   @0x22e0b8 mov r0, r4
 *   @0x22e0bc mov r1, #8
 *   @0x22e0c0 bl 0x233b28 <oggpack_read>
 *   @0x22e0c4 add r6, r6, #1
 *   @0x22e0c8 cmp r0, #0
 *   @0x22e0cc bge 0x22e0ac <res0_unpack+0x108>
 *   @0x22e0d0 mov r0, r7
 *   @0x22e0d4 bl 0x22dee4 <res0_free_info>
 *   @0x22e0d8 mov r0, #0
 *   @0x22e0dc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x22e0e0 mov r0, r4
 *   @0x22e0e4 mov r1, #5
 *   @0x22e0e8 bl 0x233b28 <oggpack_read>
 *   @0x22e0ec cmp r0, #0
 *   @0x22e0f0 blt 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e0f4 orr r9, r9, r0, lsl #3
 *   @0x22e0f8 str r9, [r6, #0x4]!
 *   @0x22e0fc subs r3, r9, #0
 *   @0x22e100 bne 0x22e070 <res0_unpack+0xcc>
 *   @0x22e104 mov r2, r9
 *   @0x22e108 b 0x22e084 <res0_unpack+0xe0>
 *   @0x22e10c ldr r4, [r7, #0x14]
 *   @0x22e110 ldr r12, [r8, #0x1c]
 *   @0x22e114 cmp r12, r4
 *   @0x22e118 ble 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e11c cmp r5, #0
 *   @0x22e120 ble 0x22e17c <res0_unpack+0x1d8>
 *   @0x22e124 ldr r3, [r7, #0x118]
 *   @0x22e128 cmp r12, r3
 *   @0x22e12c ble 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e130 add r3, r3, #520
 *   @0x22e134 ldr r3, [r8, r3, lsl #2]
 *   @0x22e138 ldr r3, [r3, #0xc]
 *   @0x22e13c cmp r3, #0
 *   @0x22e140 beq 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e144 add r1, r7, #280
 *   @0x22e148 mov r3, #0
 *   @0x22e14c b 0x22e170 <res0_unpack+0x1cc>
 *   @0x22e150 ldr r2, [r1, #0x4]!
 *   @0x22e154 cmp r12, r2
 *   @0x22e158 add r0, r2, #520
 *   @0x22e15c ble 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e160 ldr r2, [r8, r0, lsl #2]
 *   @0x22e164 ldr r2, [r2, #0xc]
 *   @0x22e168 cmp r2, #0
 *   @0x22e16c beq 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e170 add r3, r3, #1
 *   @0x22e174 cmp r3, r5
 *   @0x22e178 bne 0x22e150 <res0_unpack+0x1ac>
 *   @0x22e17c add r4, r4, #520
 *   @0x22e180 ldr r3, [r8, r4, lsl #2]
 *   @0x22e184 ldr r2, [r3]
 *   @0x22e188 ldr r0, [r3, #0x4]
 *   @0x22e18c cmp r2, #0
 *   @0x22e190 ble 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e194 ldr r1, [r7, #0xc]
 *   @0x22e198 mov r3, #1
 *   @0x22e19c b 0x22e1a8 <res0_unpack+0x204>
 *   @0x22e1a0 subs r2, r2, #1
 *   @0x22e1a4 beq 0x22e1b8 <res0_unpack+0x214>
 *   @0x22e1a8 mul r3, r1, r3
 *   @0x22e1ac cmp r0, r3
 *   @0x22e1b0 bge 0x22e1a0 <res0_unpack+0x1fc>
 *   @0x22e1b4 b 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e1b8 str r3, [r7, #0x10]
 *   @0x22e1bc mov r0, r7
 *   @0x22e1c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x22e1c4 ldr r3, [r8, #0x1c]
 *   @0x22e1c8 cmp r0, r3
 *   @0x22e1cc bge 0x22e0d0 <res0_unpack+0x12c>
 *   @0x22e1d0 mov r4, r0
 *   @0x22e1d4 b 0x22e17c <res0_unpack+0x1d8>
 *
 * ══ §43/54 b2DistanceJoint::SolvePositionConstraints(b2SolverData const&)  0x2ccc30  size 564  141 条（0x2ccc30..0x2cce64）
 * @func 0x2ccc30 0x2cce64  size 564  141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2DistanceJoint::SolvePositionConstraints(b2SolverData const&)+0x30 / 0xb6700 / 0xfebc2a90
 * 字段偏移 top8: 0x6c×2 / 0x70×2 / 0x18×2 / 0x4×2
 * VFP 指令 101 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ccc30 vldr s15, [r0, #68]
 *   @0x2ccc34 vcmpe.f32 s15, #0
 *   @0x2ccc38 push {r4, r5, r6, r7, lr}
 *   @0x2ccc3c vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2ccc40 mov r4, r0
 *   @0x2ccc44 sub sp, sp, #12
 *   @0x2ccc48 vmrs APSR_nzcv, fpscr
 *   @0x2ccc4c movgt r0, #1
 *   @0x2ccc50 ble 0x2ccc60 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x30>
 *   @0x2ccc54 add sp, sp, #12
 *   @0x2ccc58 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2ccc5c pop {r4, r5, r6, r7, pc}
 *   @0x2ccc60 ldr r7, [r4, #0x6c]
 *   @0x2ccc64 ldr r6, [r4, #0x70]
 *   @0x2ccc68 ldr r5, [r1, #0x18]
 *   @0x2ccc6c add r2, r7, r7, lsl #1
 *   @0x2ccc70 add r3, r6, r6, lsl #1
 *   @0x2ccc74 add r2, r5, r2, lsl #2
 *   @0x2ccc78 vldr s23, [r2, #8]
 *   @0x2ccc7c vmov r0, s23
 *   @0x2ccc80 add r3, r5, r3, lsl #2
 *   @0x2ccc84 vldr s27, [r2]
 *   @0x2ccc88 vldr s22, [r3, #8]
 *   @0x2ccc8c vldr s26, [r2, #4]
 *   @0x2ccc90 vldr s25, [r3]
 *   @0x2ccc94 vldr s24, [r3, #4]
 *   @0x2ccc98 str r1, [sp, #0x4]
 *   @0x2ccc9c bl 0xb6580 <sinf@plt>
 *   @0x2ccca0 vmov s16, r0
 *   @0x2ccca4 vmov r0, s23
 *   @0x2ccca8 bl 0xb658c <cosf@plt>
 *   @0x2cccac vmov s17, r0
 *   @0x2cccb0 vmov r0, s22
 *   @0x2cccb4 bl 0xb6580 <sinf@plt>
 *   @0x2cccb8 vmov s21, r0
 *   @0x2cccbc vmov r0, s22
 *   @0x2cccc0 bl 0xb658c <cosf@plt>
 *   @0x2cccc4 vldr s15, [r4, #152]
 *   @0x2cccc8 vldr s18, [r4, #92]
 *   @0x2ccccc vsub.f32 s18, s18, s15
 *   @0x2cccd0 vldr s10, [r4, #88]
 *   @0x2cccd4 vldr s13, [r4, #148]
 *   @0x2cccd8 vldr s19, [r4, #84]
 *   @0x2cccdc vldr s11, [r4, #144]
 *   @0x2ccce0 vldr s12, [r4, #80]
 *   @0x2ccce4 vldr s15, [r4, #140]
 *   @0x2ccce8 vsub.f32 s13, s10, s13
 *   @0x2cccec vsub.f32 s19, s19, s11
 *   @0x2cccf0 vsub.f32 s15, s12, s15
 *   @0x2cccf4 vmov s14, r0
 *   @0x2cccf8 vmul.f32 s20, s18, s14
 *   @0x2cccfc vmul.f32 s18, s18, s21
 *   @0x2ccd00 vmla.f32 s20, s13, s21
 *   @0x2ccd04 vmul.f32 s21, s19, s17
 *   @0x2ccd08 vnmls.f32 s18, s13, s14
 *   @0x2ccd0c vmla.f32 s21, s15, s16
 *   @0x2ccd10 vmul.f32 s19, s19, s16
 *   @0x2ccd14 vadd.f32 s16, s24, s20
 *   @0x2ccd18 vsub.f32 s16, s16, s26
 *   @0x2ccd1c vnmls.f32 s19, s15, s17
 *   @0x2ccd20 vadd.f32 s17, s25, s18
 *   @0x2ccd24 vsub.f32 s16, s16, s21
 *   @0x2ccd28 vsub.f32 s17, s17, s27
 *   @0x2ccd2c vmul.f32 s14, s16, s16
 *   @0x2ccd30 vsub.f32 s17, s17, s19
 *   @0x2ccd34 vmla.f32 s14, s17, s17
 *   @0x2ccd38 vsqrt.f32 s15, s14
 *   @0x2ccd3c vcmp.f32 s15, s15
 *   @0x2ccd40 vmrs APSR_nzcv, fpscr
 *   @0x2ccd44 bne 0x2cce30 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x200>
 *   @0x2ccd48 vldr s14, [pc, #256]
 *   @0x2ccd4c vcmpe.f32 s15, s14
 *   @0x2ccd50 vmrs APSR_nzcv, fpscr
 *   @0x2ccd54 vmovpl.f32 s13, #1.000000e+00
 *   @0x2ccd58 vldrmi s14, [pc, #244]
 *   @0x2ccd5c vmovpl.f32 s14, s15
 *   @0x2ccd60 vdivpl.f32 s15, s13, s15
 *   @0x2ccd64 vmulpl.f32 s17, s17, s15
 *   @0x2ccd68 vmulpl.f32 s16, s16, s15
 *   @0x2ccd6c vldr s15, [r4, #104]
 *   @0x2ccd70 vsub.f32 s14, s14, s15
 *   @0x2ccd74 vldr s15, [pc, #220]
 *   @0x2ccd78 vcmpe.f32 s14, s15
 *   @0x2ccd7c vmrs APSR_nzcv, fpscr
 *   @0x2ccd80 bpl 0x2ccd94 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x164>
 *   @0x2ccd84 vldr s15, [pc, #208]
 *   @0x2ccd88 vcmpe.f32 s14, s15
 *   @0x2ccd8c vmrs APSR_nzcv, fpscr
 *   @0x2ccd90 vmovpl.f32 s15, s14
 *   @0x2ccd94 vldr s12, [r4, #172]
 *   @0x2ccd98 vldr s14, [r4, #160]
 *   @0x2ccd9c vldr s13, [r4, #156]
 *   @0x2ccda0 vldr s10, [r4, #164]
 *   @0x2ccda4 vnmul.f32 s12, s12, s15
 *   @0x2ccda8 vldr s11, [r4, #168]
 *   @0x2ccdac add r6, r6, r6, lsl #1
 *   @0x2ccdb0 add r7, r7, r7, lsl #1
 *   @0x2ccdb4 add r7, r5, r7, lsl #2
 *   @0x2ccdb8 add r5, r5, r6, lsl #2
 *   @0x2ccdbc vmul.f32 s17, s12, s17
 *   @0x2ccdc0 vmul.f32 s16, s12, s16
 *   @0x2ccdc4 vmul.f32 s21, s21, s17
 *   @0x2ccdc8 vmul.f32 s20, s20, s17
 *   @0x2ccdcc vnmls.f32 s21, s19, s16
 *   @0x2ccdd0 vnmls.f32 s20, s18, s16
 *   @0x2ccdd4 vmla.f32 s25, s17, s14
 *   @0x2ccdd8 vmla.f32 s24, s16, s14
 *   @0x2ccddc vldr s14, [pc, #124]
 *   @0x2ccde0 vmls.f32 s27, s17, s13
 *   @0x2ccde4 vmls.f32 s26, s16, s13
 *   @0x2ccde8 vstr s27, [r7]
 *   @0x2ccdec vmls.f32 s23, s21, s10
 *   @0x2ccdf0 vstr s26, [r7, #4]
 *   @0x2ccdf4 vmla.f32 s22, s20, s11
 *   @0x2ccdf8 vstr s23, [r7, #8]
 *   @0x2ccdfc vstr s25, [r5]
 *   @0x2cce00 vstr s24, [r5, #4]
 *   @0x2cce04 vcmpe.f32 s15, #0
 *   @0x2cce08 vstr s22, [r5, #8]
 *   @0x2cce0c vmrs APSR_nzcv, fpscr
 *   @0x2cce10 vnegle.f32 s15, s15
 *   @0x2cce14 vcmpe.f32 s15, s14
 *   @0x2cce18 vmrs APSR_nzcv, fpscr
 *   @0x2cce1c movpl r0, #0
 *   @0x2cce20 movmi r0, #1
 *   @0x2cce24 add sp, sp, #12
 *   @0x2cce28 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2cce2c pop {r4, r5, r6, r7, pc}
 *   @0x2cce30 vmov r0, s14
 *   @0x2cce34 bl 0xb6700 <sqrtf@plt>
 *   @0x2cce38 ldr r1, [sp, #0x4]
 *   @0x2cce3c ldr r7, [r4, #0x6c]
 *   @0x2cce40 ldr r6, [r4, #0x70]
 *   @0x2cce44 ldr r5, [r1, #0x18]
 *   @0x2cce48 vmov s15, r0
 *   @0x2cce4c b 0x2ccd48 <_ZN15b2DistanceJoint24SolvePositionConstraintsERK12b2SolverData+0x118>
 *   @0x2cce50 strlo r0, [r0], #-0
 *   @0x2cce54 andeq r0, r0, r0
 *   @0x2cce58 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x2cce5c cdplt p12, #0x4, c12, c12, c13, #0x6
 *   @0x2cce60 bllo 0xfebc2a90 <b2_toiTime+0xfffffffffe4695ec>
 *
 * ══ §44/54 EncodeValue(RValue*)  0x13be2c  size 560  140 条（0x13be2c..0x13c05c）
 * @func 0x13be2c 0x13c05c  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_new_string×2 / DS_AutoMutex::DS_AutoMutex() / EncodeValue(RValue*)+0xfc / EncodeDSList(CDS_List*) / DS_AutoMutex::~DS_AutoMutex() / EncodeObject(RValue*) / EncodeDSMap(CDS_Map*) / json_object_new_int
 * 字段偏移 top8: 0x4×5 / 0x24×2 / 0xc×2 / 0x2×2 / 0x210×1 / 0x1e4×1 / 0x124×1 / 0x94×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13be2c push {r4, r5, r6, lr}
 *   @0x13be30 sub sp, sp, #40
 *   @0x13be34 ldr r4, [pc, #0x210]
 *   @0x13be38 mov r6, r0
 *   @0x13be3c mov r0, sp
 *   @0x13be40 ldr r4, [pc, r4]
 *   @0x13be44 ldr r3, [r4]
 *   @0x13be48 str r3, [sp, #0x24]
 *   @0x13be4c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13be50 ldr r3, [r6, #0xc]
 *   @0x13be54 cmp r3, #0
 *   @0x13be58 blt 0x13bf28 <_Z11EncodeValueP6RValue+0xfc>
 *   @0x13be5c ands r12, r3, #1073741824
 *   @0x13be60 beq 0x13bed0 <_Z11EncodeValueP6RValue+0xa4>
 *   @0x13be64 ldr r1, [pc, #0x1e4]
 *   @0x13be68 ldr r2, [r6]
 *   @0x13be6c ldr r1, [pc, r1]
 *   @0x13be70 vldr s12, [r1]
 *   @0x13be74 vcvt.f64.s32 d7, s12
 *   @0x13be78 ldr r3, [r6, #0x4]
 *   @0x13be7c vmov d6, r2, r3
 *   @0x13be80 vcmpe.f64 d6, d7
 *   @0x13be84 vmrs APSR_nzcv, fpscr
 *   @0x13be88 bpl 0x13bf74 <_Z11EncodeValueP6RValue+0x148>
 *   @0x13be8c vcvt.s32.f64 s13, d6
 *   @0x13be90 ldr r3, [r1, #0x4]
 *   @0x13be94 vmov r2, s13
 *   @0x13be98 ldr r0, [r3, r2, lsl #2]
 *   @0x13be9c cmp r0, #0
 *   @0x13bea0 beq 0x13c024 <_Z11EncodeValueP6RValue+0x1f8>
 *   @0x13bea4 bl 0x13c0e0 <_Z12EncodeDSListP8CDS_List>
 *   @0x13bea8 mov r6, r0
 *   @0x13beac mov r0, sp
 *   @0x13beb0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13beb4 ldr r2, [sp, #0x24]
 *   @0x13beb8 ldr r3, [r4]
 *   @0x13bebc mov r0, r6
 *   @0x13bec0 cmp r2, r3
 *   @0x13bec4 bne 0x13c048 <_Z11EncodeValueP6RValue+0x21c>
 *   @0x13bec8 add sp, sp, #40
 *   @0x13becc pop {r4, r5, r6, pc}
 *   @0x13bed0 cmp r3, #7
 *   @0x13bed4 beq 0x13bf7c <_Z11EncodeValueP6RValue+0x150>
 *   @0x13bed8 cmp r3, #10
 *   @0x13bedc beq 0x13bf7c <_Z11EncodeValueP6RValue+0x150>
 *   @0x13bee0 cmp r3, #13
 *   @0x13bee4 beq 0x13c000 <_Z11EncodeValueP6RValue+0x1d4>
 *   @0x13bee8 cmp r3, #0
 *   @0x13beec beq 0x13bf8c <_Z11EncodeValueP6RValue+0x160>
 *   @0x13bef0 cmp r3, #3
 *   @0x13bef4 beq 0x13bfb4 <_Z11EncodeValueP6RValue+0x188>
 *   @0x13bef8 cmp r3, #1
 *   @0x13befc beq 0x13bf9c <_Z11EncodeValueP6RValue+0x170>
 *   @0x13bf00 cmp r3, #2
 *   @0x13bf04 beq 0x13c02c <_Z11EncodeValueP6RValue+0x200>
 *   @0x13bf08 cmp r3, #5
 *   @0x13bf0c beq 0x13c03c <_Z11EncodeValueP6RValue+0x210>
 *   @0x13bf10 cmp r3, #6
 *   @0x13bf14 bne 0x13bf74 <_Z11EncodeValueP6RValue+0x148>
 *   @0x13bf18 mov r0, r6
 *   @0x13bf1c bl 0x24a810 <_Z12EncodeObjectP6RValue>
 *   @0x13bf20 mov r6, r0
 *   @0x13bf24 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bf28 ldr r1, [pc, #0x124]
 *   @0x13bf2c ldr r2, [r6]
 *   @0x13bf30 ldr r1, [pc, r1]
 *   @0x13bf34 vldr s12, [r1]
 *   @0x13bf38 vcvt.f64.s32 d7, s12
 *   @0x13bf3c ldr r3, [r6, #0x4]
 *   @0x13bf40 vmov d6, r2, r3
 *   @0x13bf44 vcmpe.f64 d6, d7
 *   @0x13bf48 vmrs APSR_nzcv, fpscr
 *   @0x13bf4c bpl 0x13bf74 <_Z11EncodeValueP6RValue+0x148>
 *   @0x13bf50 vcvt.s32.f64 s13, d6
 *   @0x13bf54 ldr r3, [r1, #0x4]
 *   @0x13bf58 vmov r2, s13
 *   @0x13bf5c ldr r0, [r3, r2, lsl #2]
 *   @0x13bf60 cmp r0, #0
 *   @0x13bf64 beq 0x13c024 <_Z11EncodeValueP6RValue+0x1f8>
 *   @0x13bf68 bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map>
 *   @0x13bf6c mov r6, r0
 *   @0x13bf70 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bf74 mov r6, #0
 *   @0x13bf78 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bf7c ldr r0, [r6]
 *   @0x13bf80 bl 0x27eaf8 <json_object_new_int>
 *   @0x13bf84 mov r6, r0
 *   @0x13bf88 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bf8c ldm r6, {r0, r1}
 *   @0x13bf90 bl 0x27ebb8 <json_object_new_double>
 *   @0x13bf94 mov r6, r0
 *   @0x13bf98 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bf9c ldr r0, [r6]
 *   @0x13bfa0 cmp r0, #0
 *   @0x13bfa4 ldrne r0, [r0]
 *   @0x13bfa8 bl 0x27ecc0 <json_object_new_string>
 *   @0x13bfac mov r6, r0
 *   @0x13bfb0 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13bfb4 ldr r3, [r6]
 *   @0x13bfb8 add r6, sp, #4
 *   @0x13bfbc ldr r2, [pc, #0x94]
 *   @0x13bfc0 mov r1, #16
 *   @0x13bfc4 mov r0, r6
 *   @0x13bfc8 str r12, [sp, #0x4]
 *   @0x13bfcc add r2, pc, r2
 *   @0x13bfd0 str r12, [sp, #0x8]
 *   @0x13bfd4 str r12, [sp, #0xc]
 *   @0x13bfd8 str r12, [sp, #0x10]
 *   @0x13bfdc str r12, [sp, #0x14]
 *   @0x13bfe0 str r12, [sp, #0x18]
 *   @0x13bfe4 str r12, [sp, #0x1c]
 *   @0x13bfe8 str r12, [sp, #0x20]
 *   @0x13bfec bl 0xb65c8 <snprintf@plt>
 *   @0x13bff0 mov r0, r6
 *   @0x13bff4 bl 0x27ecc0 <json_object_new_string>
 *   @0x13bff8 mov r6, r0
 *   @0x13bffc b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13c000 ldm r6, {r2, r3}
 *   @0x13c004 vmov d7, r2, r3
 *   @0x13c008 vcmp.f64 d7, #0
 *   @0x13c00c vmrs APSR_nzcv, fpscr
 *   @0x13c010 moveq r0, #0
 *   @0x13c014 movne r0, #1
 *   @0x13c018 bl 0x27ea48 <json_object_new_boolean>
 *   @0x13c01c mov r6, r0
 *   @0x13c020 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13c024 mov r6, r0
 *   @0x13c028 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13c02c mov r0, r6
 *   @0x13c030 bl 0x13c05c <_Z11EncodeArrayP6RValue>
 *   @0x13c034 mov r6, r0
 *   @0x13c038 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13c03c bl 0x27ec98 <json_object_new_null>
 *   @0x13c040 mov r6, r0
 *   @0x13c044 b 0x13beac <_Z11EncodeValueP6RValue+0x80>
 *   @0x13c048 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13c04c eoreq r1, r11, r0, lsl r11
 *   @0x13c050 eoreq r1, r11, r4, lsl lr
 *   @0x13c054 eoreq r1, r11, r12, lsl #20
 *   @0x13c058 andseq r6, pc, r12, lsr r5
 *
 * ══ §45/54 Eff_Effect06(int, float, float, int, unsigned int)  0x1a1590  size 560  140 条（0x1a1590..0x1a17c0）
 * @func 0x1a1590 0x1a17c0  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a15bc→0x5423f8
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Orientation(int, float, float, float, float, bool)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×9 / 0x8×5 / 0x1fc×1 / 0x1f8×1 / 0x30×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1590 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a1594 vpush {d8}
 *   @0x1a1598 sub sp, sp, #12
 *   @0x1a159c mov r4, r3
 *   @0x1a15a0 mov r7, r1
 *   @0x1a15a4 mov r6, r2
 *   @0x1a15a8 mov r8, r0
 *   @0x1a15ac bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a15b0 cmp r4, #0
 *   @0x1a15b4 ldr r3, [pc, #0x1fc]
 *   @0x1a15b8 mov r1, #4
 *   @0x1a15bc ldr r2, [pc, #0x1f8]
 *   @0x1a15c0 add r3, pc, r3
 *   @0x1a15c4 vmov s16, r0
 *   @0x1a15c8 beq 0x1a168c <_Z12Eff_Effect06iffij+0xfc>
 *   @0x1a15cc cmp r4, #2
 *   @0x1a15d0 mov r5, #0
 *   @0x1a15d4 ldr r4, [r3, r2]
 *   @0x1a15d8 beq 0x1a1720 <_Z12Eff_Effect06iffij+0x190>
 *   @0x1a15dc ldr r0, [r4, #0x4]
 *   @0x1a15e0 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a15e4 vldr s15, [pc, #448]
 *   @0x1a15e8 vmul.f32 s15, s16, s15
 *   @0x1a15ec mov r1, #1061158912
 *   @0x1a15f0 ldr r0, [r4, #0x4]
 *   @0x1a15f4 mov r2, r1
 *   @0x1a15f8 str r5, [sp]
 *   @0x1a15fc vmov r3, s15
 *   @0x1a1600 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1604 ldr r0, [r4, #0x4]
 *   @0x1a1608 mov r1, r5
 *   @0x1a160c str r5, [sp]
 *   @0x1a1610 mov r3, #0
 *   @0x1a1614 mov r2, #0
 *   @0x1a1618 str r3, [sp, #0x4]
 *   @0x1a161c movt r2, #0x43b4
 *   @0x1a1620 mov r3, r5
 *   @0x1a1624 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1628 vmov.f32 s15, #2.500000e+01
 *   @0x1a162c ldr r9, [r4, #0x4]
 *   @0x1a1630 vdiv.f32 s16, s15, s16
 *   @0x1a1634 vcvt.f64.f32 d8, s16
 *   @0x1a1638 vmov r0, r1, d8
 *   @0x1a163c bl 0xb66e8 <lrint@plt>
 *   @0x1a1640 mov r5, r0
 *   @0x1a1644 vmov r0, r1, d8
 *   @0x1a1648 bl 0xb66e8 <lrint@plt>
 *   @0x1a164c mov r1, r5
 *   @0x1a1650 mov r2, r0
 *   @0x1a1654 mov r0, r9
 *   @0x1a1658 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a165c ldr r3, [r4, #0x4]
 *   @0x1a1660 ldr r2, [sp, #0x30]
 *   @0x1a1664 mov r12, #1
 *   @0x1a1668 mov r0, r8
 *   @0x1a166c mov r1, r7
 *   @0x1a1670 str r12, [sp, #0x4]
 *   @0x1a1674 str r2, [sp]
 *   @0x1a1678 mov r2, r6
 *   @0x1a167c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1680 add sp, sp, #12
 *   @0x1a1684 vpop {d8}
 *   @0x1a1688 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a168c ldr r5, [r3, r2]
 *   @0x1a1690 mov r9, #0
 *   @0x1a1694 ldr r0, [r5]
 *   @0x1a1698 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a169c vldr s15, [pc, #268]
 *   @0x1a16a0 vmul.f32 s15, s16, s15
 *   @0x1a16a4 ldr r0, [r5]
 *   @0x1a16a8 movw r1, #0xcccd
 *   @0x1a16ac str r9, [sp]
 *   @0x1a16b0 movt r1, #0x3ecc
 *   @0x1a16b4 movw r2, #0x999a
 *   @0x1a16b8 movt r2, #0x3e99
 *   @0x1a16bc vmov r3, s15
 *   @0x1a16c0 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a16c4 mov r3, r9
 *   @0x1a16c8 ldr r0, [r5]
 *   @0x1a16cc mov r1, r9
 *   @0x1a16d0 str r9, [sp]
 *   @0x1a16d4 mov r2, #0
 *   @0x1a16d8 str r4, [sp, #0x4]
 *   @0x1a16dc movt r2, #0x43b4
 *   @0x1a16e0 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a16e4 vmov.f32 s15, #2.000000e+01
 *   @0x1a16e8 ldr r9, [r5]
 *   @0x1a16ec vdiv.f32 s16, s15, s16
 *   @0x1a16f0 vcvt.f64.f32 d8, s16
 *   @0x1a16f4 vmov r0, r1, d8
 *   @0x1a16f8 bl 0xb66e8 <lrint@plt>
 *   @0x1a16fc mov r4, r0
 *   @0x1a1700 vmov r0, r1, d8
 *   @0x1a1704 bl 0xb66e8 <lrint@plt>
 *   @0x1a1708 mov r1, r4
 *   @0x1a170c mov r2, r0
 *   @0x1a1710 mov r0, r9
 *   @0x1a1714 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1718 ldr r3, [r5]
 *   @0x1a171c b 0x1a1660 <_Z12Eff_Effect06iffij+0xd0>
 *   @0x1a1720 ldr r0, [r4, #0x8]
 *   @0x1a1724 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1728 vldr s15, [pc, #132]
 *   @0x1a172c vmul.f32 s15, s16, s15
 *   @0x1a1730 movw r1, #0x999a
 *   @0x1a1734 movt r1, #0x3f99
 *   @0x1a1738 ldr r0, [r4, #0x8]
 *   @0x1a173c str r5, [sp]
 *   @0x1a1740 mov r2, r1
 *   @0x1a1744 vmov r3, s15
 *   @0x1a1748 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a174c ldr r0, [r4, #0x8]
 *   @0x1a1750 mov r1, r5
 *   @0x1a1754 str r5, [sp]
 *   @0x1a1758 mov r3, #0
 *   @0x1a175c mov r2, #0
 *   @0x1a1760 str r3, [sp, #0x4]
 *   @0x1a1764 movt r2, #0x43b4
 *   @0x1a1768 mov r3, r5
 *   @0x1a176c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1770 vmov.f32 s15, #3.000000e+01
 *   @0x1a1774 ldr r9, [r4, #0x8]
 *   @0x1a1778 vdiv.f32 s16, s15, s16
 *   @0x1a177c vcvt.f64.f32 d8, s16
 *   @0x1a1780 vmov r0, r1, d8
 *   @0x1a1784 bl 0xb66e8 <lrint@plt>
 *   @0x1a1788 mov r5, r0
 *   @0x1a178c vmov r0, r1, d8
 *   @0x1a1790 bl 0xb66e8 <lrint@plt>
 *   @0x1a1794 mov r1, r5
 *   @0x1a1798 mov r2, r0
 *   @0x1a179c mov r0, r9
 *   @0x1a17a0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a17a4 ldr r3, [r4, #0x8]
 *   @0x1a17a8 b 0x1a1660 <_Z12Eff_Effect06iffij+0xd0>
 *   @0x1a17ac ldcllt p2, c12, [r5], #572
 *   @0x1a17b0 stclt p7, c13, [r3], #40
 *   @0x1a17b4 stclt p7, c13, [r3, #-40]!
 *   @0x1a17b8 mlaeq r5, r0, r6, r0
 *   @0x1a17bc .word 0xffffeb38
 *
 * ══ §46/54 CDS_List::Replace(int, RValue*)  0x208964  size 560  140 条（0x208964..0x208b94）
 * @func 0x208964 0x208b94  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / GetContextStackTop() / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0xc×9 / 0x8×7 / 0x4×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x208964 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x208968 subs r6, r1, #0
 *   @0x20896c mov r8, r0
 *   @0x208970 mov r5, r2
 *   @0x208974 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208978 ldr r3, [r0, #0x4]
 *   @0x20897c cmp r6, r3
 *   @0x208980 popge {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208984 ldr r9, [r0, #0xc]
 *   @0x208988 lsl r4, r6, #4
 *   @0x20898c add r7, r9, r4
 *   @0x208990 ldr r3, [r7, #0xc]
 *   @0x208994 sub r3, r3, #1
 *   @0x208998 bic r3, r3, #-16777216
 *   @0x20899c bic r3, r3, #3
 *   @0x2089a0 cmp r3, #0
 *   @0x2089a4 movne r4, r7
 *   @0x2089a8 beq 0x208b18 <_ZN8CDS_List7ReplaceEiP6RValue+0x1b4>
 *   @0x2089ac mov r3, #5
 *   @0x2089b0 str r3, [r7, #0xc]
 *   @0x2089b4 ldr r1, [r4, #0xc]
 *   @0x2089b8 mov r3, #0
 *   @0x2089bc str r3, [r7, #0x8]
 *   @0x2089c0 bic r2, r1, #-16777216
 *   @0x2089c4 str r3, [r9, r6, lsl #4]
 *   @0x2089c8 cmp r2, #1
 *   @0x2089cc beq 0x208ae4 <_ZN8CDS_List7ReplaceEiP6RValue+0x180>
 *   @0x2089d0 cmp r2, #2
 *   @0x2089d4 bne 0x2089fc <_ZN8CDS_List7ReplaceEiP6RValue+0x98>
 *   @0x2089d8 sub r1, r1, #1
 *   @0x2089dc bic r1, r1, #-16777216
 *   @0x2089e0 bic r1, r1, #3
 *   @0x2089e4 cmp r1, #0
 *   @0x2089e8 beq 0x208b88 <_ZN8CDS_List7ReplaceEiP6RValue+0x224>
 *   @0x2089ec mov r2, #0
 *   @0x2089f0 mov r3, #5
 *   @0x2089f4 str r2, [r4, #0x8]
 *   @0x2089f8 str r3, [r4, #0xc]
 *   @0x2089fc ldr r3, [r5, #0xc]
 *   @0x208a00 mov r1, #0
 *   @0x208a04 ldr r2, [r5, #0x8]
 *   @0x208a08 str r1, [r4]
 *   @0x208a0c str r3, [r4, #0xc]
 *   @0x208a10 ldr r3, [r5, #0xc]
 *   @0x208a14 str r2, [r4, #0x8]
 *   @0x208a18 bic r3, r3, #-16777216
 *   @0x208a1c cmp r3, #14
 *   @0x208a20 addls pc, pc, r3, lsl #2
 *   @0x208a24 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a28 b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c>
 *   @0x208a2c b 0x208acc <_ZN8CDS_List7ReplaceEiP6RValue+0x168>
 *   @0x208a30 b 0x208aa0 <_ZN8CDS_List7ReplaceEiP6RValue+0x13c>
 *   @0x208a34 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100>
 *   @0x208a38 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a3c b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a40 b 0x208a7c <_ZN8CDS_List7ReplaceEiP6RValue+0x118>
 *   @0x208a44 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100>
 *   @0x208a48 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a4c b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a50 b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c>
 *   @0x208a54 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a58 b 0x208a6c <_ZN8CDS_List7ReplaceEiP6RValue+0x108>
 *   @0x208a5c b 0x208a70 <_ZN8CDS_List7ReplaceEiP6RValue+0x10c>
 *   @0x208a60 b 0x208a64 <_ZN8CDS_List7ReplaceEiP6RValue+0x100>
 *   @0x208a64 ldr r3, [r5]
 *   @0x208a68 str r3, [r4]
 *   @0x208a6c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208a70 ldm r5, {r2, r3}
 *   @0x208a74 stm r4, {r2, r3}
 *   @0x208a78 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208a7c ldr r3, [r5]
 *   @0x208a80 str r3, [r4]
 *   @0x208a84 ldr r3, [r5]
 *   @0x208a88 cmp r3, #0
 *   @0x208a8c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208a90 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x208a94 ldr r1, [r5]
 *   @0x208a98 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x208a9c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x208aa0 ldr r3, [r5]
 *   @0x208aa4 cmp r3, #0
 *   @0x208aa8 str r3, [r4]
 *   @0x208aac popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208ab0 ldr r1, [r3, #0x8]
 *   @0x208ab4 ldr r2, [r3]
 *   @0x208ab8 cmp r1, #0
 *   @0x208abc streq r4, [r3, #0x8]
 *   @0x208ac0 add r2, r2, #1
 *   @0x208ac4 str r2, [r3]
 *   @0x208ac8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x208acc ldr r3, [r5]
 *   @0x208ad0 cmp r3, #0
 *   @0x208ad4 ldrne r2, [r3, #0x4]
 *   @0x208ad8 addne r2, r2, #1
 *   @0x208adc strne r2, [r3, #0x4]
 *   @0x208ae0 b 0x208a68 <_ZN8CDS_List7ReplaceEiP6RValue+0x104>
 *   @0x208ae4 ldr r6, [r4]
 *   @0x208ae8 cmp r6, #0
 *   @0x208aec beq 0x208b0c <_ZN8CDS_List7ReplaceEiP6RValue+0x1a8>
 *   @0x208af0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x208af4 ldr r7, [r6, #0x4]
 *   @0x208af8 sub r7, r7, #1
 *   @0x208afc str r7, [r6, #0x4]
 *   @0x208b00 cmp r7, #0
 *   @0x208b04 beq 0x208b2c <_ZN8CDS_List7ReplaceEiP6RValue+0x1c8>
 *   @0x208b08 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x208b0c mov r3, #0
 *   @0x208b10 str r3, [r4]
 *   @0x208b14 b 0x2089fc <_ZN8CDS_List7ReplaceEiP6RValue+0x98>
 *   @0x208b18 mov r0, r7
 *   @0x208b1c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x208b20 ldr r3, [r8, #0xc]
 *   @0x208b24 add r4, r3, r4
 *   @0x208b28 b 0x2089ac <_ZN8CDS_List7ReplaceEiP6RValue+0x48>
 *   @0x208b2c ldr r0, [r6]
 *   @0x208b30 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x208b34 str r7, [r6]
 *   @0x208b38 str r7, [r6, #0x8]
 *   @0x208b3c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x208b40 ldr r7, [r6, #0x4]
 *   @0x208b44 sub r7, r7, #1
 *   @0x208b48 str r7, [r6, #0x4]
 *   @0x208b4c cmp r7, #0
 *   @0x208b50 beq 0x208b64 <_ZN8CDS_List7ReplaceEiP6RValue+0x200>
 *   @0x208b54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x208b58 mov r0, r6
 *   @0x208b5c bl 0x27d1d0 <_ZdlPv>
 *   @0x208b60 b 0x208b08 <_ZN8CDS_List7ReplaceEiP6RValue+0x1a4>
 *   @0x208b64 ldr r0, [r6]
 *   @0x208b68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x208b6c mov r0, r6
 *   @0x208b70 str r7, [r6]
 *   @0x208b74 str r7, [r6, #0x8]
 *   @0x208b78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x208b7c mov r0, r6
 *   @0x208b80 bl 0x27d1d0 <_ZdlPv>
 *   @0x208b84 b 0x208b54 <_ZN8CDS_List7ReplaceEiP6RValue+0x1f0>
 *   @0x208b88 mov r0, r4
 *   @0x208b8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x208b90 b 0x2089ec <_ZN8CDS_List7ReplaceEiP6RValue+0x88>
 *
 * ══ §47/54 F_JS_FromPropertyDescriptor(RValue*, RValue*)  0x2483e0  size 560  138 条（0x2483e0..0x248610）
 * @func 0x2483e0 0x248610  size 560  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool)×6 / YYObjectBase::InternalGetYYVar(int)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / JS_IsDataDescriptor(RValue*)
 * 字段偏移 top8: 0x10×7 / 0x8×6 / 0x14×4 / 0x4×3 / 0xc×2 / 0x178×1 / 0x130×1 / 0x114×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2483e0 ldr r3, [r1, #0xc]
 *   @0x2483e4 mvn r12, #-16777216
 *   @0x2483e8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2483ec vpush {d8, d9}
 *   @0x2483f0 cmp r3, #5
 *   @0x2483f4 cmpne r3, r12
 *   @0x2483f8 sub sp, sp, #24
 *   @0x2483fc mov r6, r1
 *   @0x248400 moveq r3, #5
 *   @0x248404 mov r8, r0
 *   @0x248408 movne r7, #0
 *   @0x24840c moveq r7, #1
 *   @0x248410 streq r3, [r0, #0xc]
 *   @0x248414 bne 0x248424 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x44>
 *   @0x248418 add sp, sp, #24
 *   @0x24841c vpop {d8, d9}
 *   @0x248420 pop {r4, r5, r6, r7, r8, pc}
 *   @0x248424 mov r1, r7
 *   @0x248428 mov r2, r7
 *   @0x24842c mov r3, r7
 *   @0x248430 str r7, [sp]
 *   @0x248434 mov r5, #0
 *   @0x248438 str r12, [sp, #0x14]
 *   @0x24843c str r7, [sp, #0x10]
 *   @0x248440 mov r4, #0
 *   @0x248444 strd r4, r5, [sp, #8]
 *   @0x248448 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24844c mov r0, r6
 *   @0x248450 ldr r5, [r8]
 *   @0x248454 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x248458 cmp r0, #0
 *   @0x24845c bne 0x248558 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x178>
 *   @0x248460 ldr r0, [r6]
 *   @0x248464 ldr r1, [r0, #0x4]
 *   @0x248468 cmp r1, #0
 *   @0x24846c beq 0x2485e0 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x200>
 *   @0x248470 ldr r12, [r1]
 *   @0x248474 add r4, sp, #8
 *   @0x248478 ldr r1, [pc, #0x178]
 *   @0x24847c mov r3, #0
 *   @0x248480 ldr lr, [sp, #0x10]
 *   @0x248484 mov r0, r5
 *   @0x248488 mov r2, r4
 *   @0x24848c add r1, pc, r1
 *   @0x248490 str r12, [sp, #0x8]
 *   @0x248494 orr lr, lr, #7
 *   @0x248498 mov r12, #6
 *   @0x24849c str lr, [sp, #0x10]
 *   @0x2484a0 str r12, [sp, #0x14]
 *   @0x2484a4 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x2484a8 ldr r0, [r6]
 *   @0x2484ac ldr r3, [r0, #0x4]
 *   @0x2484b0 cmp r3, #0
 *   @0x2484b4 beq 0x2485d4 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x1f4>
 *   @0x2484b8 add r0, r3, #16
 *   @0x2484bc ldr r12, [r0]
 *   @0x2484c0 mov r2, r4
 *   @0x2484c4 ldr r1, [pc, #0x130]
 *   @0x2484c8 mov r0, r5
 *   @0x2484cc mov r3, #0
 *   @0x2484d0 add r1, pc, r1
 *   @0x2484d4 str r12, [sp, #0x8]
 *   @0x2484d8 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x2484dc vmov.f64 d8, #1.000000e+00
 *   @0x2484e0 ldr r3, [r6, #0x8]
 *   @0x2484e4 ldr r1, [pc, #0x114]
 *   @0x2484e8 mov r2, r4
 *   @0x2484ec ldr lr, [sp, #0x10]
 *   @0x2484f0 tst r3, #1
 *   @0x2484f4 mov r0, r5
 *   @0x2484f8 add r1, pc, r1
 *   @0x2484fc mov r3, #0
 *   @0x248500 orr lr, lr, #7
 *   @0x248504 mov r12, #13
 *   @0x248508 vldr d9, [pc, #224]
 *   @0x24850c str lr, [sp, #0x10]
 *   @0x248510 str r12, [sp, #0x14]
 *   @0x248514 vmovne.f64 d7, d8
 *   @0x248518 vmoveq.f64 d7, d9
 *   @0x24851c vstr d7, [sp, #8]
 *   @0x248520 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x248524 ldr r3, [r6, #0x8]
 *   @0x248528 ldr r1, [pc, #0xd4]
 *   @0x24852c mov r0, r5
 *   @0x248530 tst r3, #2
 *   @0x248534 mov r2, r4
 *   @0x248538 add r1, pc, r1
 *   @0x24853c mov r3, #0
 *   @0x248540 vmoveq.f64 d8, d9
 *   @0x248544 vstr d8, [sp, #8]
 *   @0x248548 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x24854c add sp, sp, #24
 *   @0x248550 vpop {d8, d9}
 *   @0x248554 pop {r4, r5, r6, r7, r8, pc}
 *   @0x248558 add r4, sp, #8
 *   @0x24855c ldr r0, [r6]
 *   @0x248560 ldr r1, [r6, #0x4]
 *   @0x248564 ldr r2, [r6, #0x8]
 *   @0x248568 mov r12, r4
 *   @0x24856c ldr r3, [r6, #0xc]
 *   @0x248570 stm r12!, {r0, r1, r2, r3}
 *   @0x248574 mov r2, r4
 *   @0x248578 ldr r1, [pc, #0x88]
 *   @0x24857c mov r3, r7
 *   @0x248580 ldr r12, [sp, #0x10]
 *   @0x248584 mov r0, r5
 *   @0x248588 add r1, pc, r1
 *   @0x24858c orr r12, r12, #7
 *   @0x248590 str r12, [sp, #0x10]
 *   @0x248594 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x248598 vmov.f64 d7, #1.000000e+00
 *   @0x24859c ldr r1, [r6, #0x8]
 *   @0x2485a0 mov r3, r7
 *   @0x2485a4 mov r2, r4
 *   @0x2485a8 mov r0, r5
 *   @0x2485ac tst r1, #4
 *   @0x2485b0 ldr r1, [pc, #0x54]
 *   @0x2485b4 vldr d6, [pc, #52]
 *   @0x2485b8 mov r12, #13
 *   @0x2485bc add r1, pc, r1
 *   @0x2485c0 str r12, [sp, #0x14]
 *   @0x2485c4 vmoveq.f64 d7, d6
 *   @0x2485c8 vstr d7, [sp, #8]
 *   @0x2485cc bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x2485d0 b 0x2484dc <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0xfc>
 *   @0x2485d4 mov r1, #1
 *   @0x2485d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2485dc b 0x2484bc <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0xdc>
 *   @0x2485e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2485e4 mov r1, r0
 *   @0x2485e8 b 0x248470 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_+0x90>
 *   @0x2485ec nop
 *   @0x2485f8 andseq sp, r0, r8, lsr #3
 *   @0x2485fc andseq sp, r0, r8, ror #2
 *   @0x248600 andseq sp, r0, r4, lsl r1
 *   @0x248604 andseq sp, r0, r0, ror #1
 *   @0x248608 ldrdeq lr, pc, [lr], -r8
 *   @0x24860c andseq sp, r0, r12, rrx
 *
 * ══ §48/54 RunGame()  0x2a2c3c  size 560  140 条（0x2a2c3c..0x2a2e6c）
 * @func 0x2a2c3c 0x2a2e6c  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a2c48→0x484a84, 0x2a2c60→0x542988, 0x2a2c88→0x484a7c, 0x2a2cd8→0x479a31, 0x2a2d00→0x757760, 0x2a2d1c→0x54297c, 0x2a2d3c→0x757f0c, 0x2a2d50→0x47f3c5
 * 调用序列: MemoryManager::Free(void const*)×8 / 0xb65c8×3 / YYStrDup(char const*)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / SetLaunchedFromPlayer(char const*, bool)×2 / 0xb6964
 * 字段偏移 top8: 0x1e0×2 / 0x1cc×1 / 0x1c0×1 / 0x1ac×1 / 0x198×1 / 0x164×1 / 0x140×1 / 0x128×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2c3c push {r4, r5, r6, r7, r8, lr}
 *   @0x2a2c40 sub sp, sp, #8
 *   @0x2a2c44 ldr r4, [pc, #0x1e0]
 *   @0x2a2c48 ldr r3, [pc, #0x1e0]
 *   @0x2a2c4c add r4, pc, r4
 *   @0x2a2c50 ldr r5, [r4, r3]
 *   @0x2a2c54 ldr r6, [r5]
 *   @0x2a2c58 cmp r6, #0
 *   @0x2a2c5c beq 0x2a2d3c <_Z7RunGamev+0x100>
 *   @0x2a2c60 ldr r3, [pc, #0x1cc]
 *   @0x2a2c64 ldr r6, [r4, r3]
 *   @0x2a2c68 ldr r0, [r6]
 *   @0x2a2c6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2c70 ldr r1, [pc, #0x1c0]
 *   @0x2a2c74 mov r3, #1
 *   @0x2a2c78 mov r0, #4096
 *   @0x2a2c7c add r1, pc, r1
 *   @0x2a2c80 movw r2, #0x38a
 *   @0x2a2c84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a2c88 ldr r3, [pc, #0x1ac]
 *   @0x2a2c8c str r0, [r6]
 *   @0x2a2c90 ldr r6, [r4, r3]
 *   @0x2a2c94 ldr r12, [r6]
 *   @0x2a2c98 cmp r12, #0
 *   @0x2a2c9c beq 0x2a2e14 <_Z7RunGamev+0x1d8>
 *   @0x2a2ca0 ldr r7, [pc, #0x198]
 *   @0x2a2ca4 mov r1, #4096
 *   @0x2a2ca8 ldr r3, [r5]
 *   @0x2a2cac add r7, pc, r7
 *   @0x2a2cb0 str r12, [sp]
 *   @0x2a2cb4 mov r2, r7
 *   @0x2a2cb8 bl 0xb65c8 <snprintf@plt>
 *   @0x2a2cbc ldr r1, [r5]
 *   @0x2a2cc0 mov r0, r7
 *   @0x2a2cc4 ldr r2, [r6]
 *   @0x2a2cc8 bl 0xb6964 <printf@plt>
 *   @0x2a2ccc ldr r0, [r5]
 *   @0x2a2cd0 mov r1, #1
 *   @0x2a2cd4 bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb>
 *   @0x2a2cd8 ldr r3, [pc, #0x164]
 *   @0x2a2cdc mov r2, #1
 *   @0x2a2ce0 ldr r0, [r5]
 *   @0x2a2ce4 ldr r3, [r4, r3]
 *   @0x2a2ce8 strb r2, [r3]
 *   @0x2a2cec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2cf0 ldr r0, [r6]
 *   @0x2a2cf4 cmp r0, #0
 *   @0x2a2cf8 beq 0x2a2d00 <_Z7RunGamev+0xc4>
 *   @0x2a2cfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2d00 ldr r3, [pc, #0x140]
 *   @0x2a2d04 mov r7, #0
 *   @0x2a2d08 str r7, [r5]
 *   @0x2a2d0c str r7, [r6]
 *   @0x2a2d10 ldr r5, [r4, r3]
 *   @0x2a2d14 ldr r0, [r5]
 *   @0x2a2d18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2d1c ldr r3, [pc, #0x128]
 *   @0x2a2d20 str r7, [r5]
 *   @0x2a2d24 ldr r3, [r4, r3]
 *   @0x2a2d28 ldr r0, [r3]
 *   @0x2a2d2c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a2d30 str r0, [r5]
 *   @0x2a2d34 add sp, sp, #8
 *   @0x2a2d38 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2a2d3c ldr r3, [pc, #0x10c]
 *   @0x2a2d40 ldr r5, [r4, r3]
 *   @0x2a2d44 ldr r3, [r5]
 *   @0x2a2d48 cmp r3, #0
 *   @0x2a2d4c beq 0x2a2d34 <_Z7RunGamev+0xf8>
 *   @0x2a2d50 ldr r2, [pc, #0xfc]
 *   @0x2a2d54 ldr r3, [pc, #0xd8]
 *   @0x2a2d58 ldr r7, [pc, #0xf8]
 *   @0x2a2d5c ldr r2, [r4, r2]
 *   @0x2a2d60 add r7, pc, r7
 *   @0x2a2d64 strb r6, [r2]
 *   @0x2a2d68 ldr r8, [r4, r3]
 *   @0x2a2d6c ldr r0, [r8]
 *   @0x2a2d70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2d74 ldr r1, [pc, #0xe0]
 *   @0x2a2d78 mov r2, #948
 *   @0x2a2d7c mov r3, #1
 *   @0x2a2d80 add r1, pc, r1
 *   @0x2a2d84 mov r0, #4096
 *   @0x2a2d88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a2d8c ldr r2, [pc, #0xcc]
 *   @0x2a2d90 ldr r3, [r5]
 *   @0x2a2d94 mov r1, #4096
 *   @0x2a2d98 add r2, pc, r2
 *   @0x2a2d9c str r0, [r8]
 *   @0x2a2da0 bl 0xb65c8 <snprintf@plt>
 *   @0x2a2da4 mov r1, r6
 *   @0x2a2da8 mov r0, r7
 *   @0x2a2dac bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb>
 *   @0x2a2db0 ldr r3, [pc, #0x8c]
 *   @0x2a2db4 ldr r0, [r5]
 *   @0x2a2db8 mov r2, #1
 *   @0x2a2dbc ldr r3, [r4, r3]
 *   @0x2a2dc0 strb r2, [r3]
 *   @0x2a2dc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2dc8 ldr r3, [pc, #0x78]
 *   @0x2a2dcc str r6, [r5]
 *   @0x2a2dd0 ldr r5, [r4, r3]
 *   @0x2a2dd4 ldr r0, [r5]
 *   @0x2a2dd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2ddc mov r0, r7
 *   @0x2a2de0 str r6, [r5]
 *   @0x2a2de4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a2de8 ldr r3, [pc, #0x74]
 *   @0x2a2dec str r0, [r5]
 *   @0x2a2df0 ldr r4, [r4, r3]
 *   @0x2a2df4 ldr r0, [r4]
 *   @0x2a2df8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2dfc mov r0, r7
 *   @0x2a2e00 str r6, [r4]
 *   @0x2a2e04 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a2e08 str r0, [r4]
 *   @0x2a2e0c add sp, sp, #8
 *   @0x2a2e10 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2a2e14 ldr r2, [pc, #0x4c]
 *   @0x2a2e18 mov r1, #4096
 *   @0x2a2e1c ldr r3, [r5]
 *   @0x2a2e20 add r2, pc, r2
 *   @0x2a2e24 bl 0xb65c8 <snprintf@plt>
 *   @0x2a2e28 b 0x2a2cd8 <_Z7RunGamev+0x9c>
 *   @0x2a2e2c andseq pc, r4, r4
 *   @0x2a2e30 .word 0xffffdf58
 *   @0x2a2e34 .word 0xfffffd10
 *   @0x2a2e38 andeq r7, r11, r4, ror #11
 *   @0x2a2e3c .word 0xffffdf60
 *   @0x2a2e40 ldrdeq r7, r8, [r11], -r8
 *   @0x2a2e44 .word 0xfffffcf0
 *   @0x2a2e48 .word 0xfffffcc4
 *   @0x2a2e4c .word 0xffffdf54
 *   @0x2a2e50 .word 0xfffffde0
 *   @0x2a2e54 .word 0xffffc140
 *   @0x2a2e58 ldrdeq r11, r12, [r8], -r6
 *   @0x2a2e5c andeq r7, r11, r0, ror #9
 *   @0x2a2e60 andeq r7, r11, r0, ror #13
 *   @0x2a2e64 .word 0xffffef18
 *   @0x2a2e68 andeq r7, r11, r8, asr r6
 *
 * ══ §49/54 b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const  0x2c3794  size 560  140 条（0x2c3794..0x2c39c4）
 * @func 0x2c3794 0x2c39c4  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const+0x188 / b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const+0x1a8 / b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const+0x110 / b2AABB::RayCast(b2RayCastOutput*, b2RayCastInput const&) const+0x148
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x1c×1
 * VFP 指令 99 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3794 vldr s15, [r2]
 *   @0x2c3798 vldr s14, [r2, #8]
 *   @0x2c379c vsub.f32 s14, s14, s15
 *   @0x2c37a0 vldr s13, [r2, #12]
 *   @0x2c37a4 vldr s15, [r2, #4]
 *   @0x2c37a8 str r4, [sp, #-0x4]!
 *   @0x2c37ac sub sp, sp, #36
 *   @0x2c37b0 mov r3, r0
 *   @0x2c37b4 mov r4, r1
 *   @0x2c37b8 ldm r2, {r0, r1}
 *   @0x2c37bc stm sp, {r0, r1}
 *   @0x2c37c0 vsub.f32 s15, s13, s15
 *   @0x2c37c4 vstr s14, [sp, #8]
 *   @0x2c37c8 vldr s13, [pc, #488]
 *   @0x2c37cc vcmpe.f32 s14, #0
 *   @0x2c37d0 vstr s15, [sp, #12]
 *   @0x2c37d4 vmrs APSR_nzcv, fpscr
 *   @0x2c37d8 vcmpe.f32 s15, #0
 *   @0x2c37dc vnegle.f32 s14, s14
 *   @0x2c37e0 vmrs APSR_nzcv, fpscr
 *   @0x2c37e4 vcmpe.f32 s14, s13
 *   @0x2c37e8 vnegle.f32 s15, s15
 *   @0x2c37ec vmrs APSR_nzcv, fpscr
 *   @0x2c37f0 vstr s15, [sp, #20]
 *   @0x2c37f4 bmi 0x2c3878 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xe4>
 *   @0x2c37f8 vmov.f32 s11, #1.000000e+00
 *   @0x2c37fc vldr s13, [sp, #8]
 *   @0x2c3800 vldr s12, [sp]
 *   @0x2c3804 vldr s14, [r3]
 *   @0x2c3808 vldr s15, [r3, #8]
 *   @0x2c380c vdiv.f32 s13, s11, s13
 *   @0x2c3810 vsub.f32 s14, s14, s12
 *   @0x2c3814 vsub.f32 s15, s15, s12
 *   @0x2c3818 vmul.f32 s14, s14, s13
 *   @0x2c381c vmul.f32 s15, s15, s13
 *   @0x2c3820 vcmpe.f32 s14, s15
 *   @0x2c3824 vmrs APSR_nzcv, fpscr
 *   @0x2c3828 ble 0x2c391c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x188>
 *   @0x2c382c vldr s13, [pc, #392]
 *   @0x2c3830 vcmpe.f32 s15, s13
 *   @0x2c3834 vmrs APSR_nzcv, fpscr
 *   @0x2c3838 ble 0x2c393c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x1a8>
 *   @0x2c383c mov r1, #0
 *   @0x2c3840 vstr s11, [sp, #24]
 *   @0x2c3844 str r1, [sp, #0x1c]
 *   @0x2c3848 vldr s13, [pc, #368]
 *   @0x2c384c vcmp.f32 s14, s13
 *   @0x2c3850 vmrs APSR_nzcv, fpscr
 *   @0x2c3854 vmovgt.f32 s14, s13
 *   @0x2c3858 vcmpe.f32 s15, s14
 *   @0x2c385c vmrs APSR_nzcv, fpscr
 *   @0x2c3860 ble 0x2c38a4 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x110>
 *   @0x2c3864 mov r3, #0
 *   @0x2c3868 mov r0, r3
 *   @0x2c386c add sp, sp, #36
 *   @0x2c3870 ldr r4, [sp], #4
 *   @0x2c3874 bx lr
 *   @0x2c3878 vldr s15, [sp]
 *   @0x2c387c vldr s14, [r3]
 *   @0x2c3880 vcmpe.f32 s15, s14
 *   @0x2c3884 vmrs APSR_nzcv, fpscr
 *   @0x2c3888 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c388c vldr s14, [r3, #8]
 *   @0x2c3890 vcmpe.f32 s15, s14
 *   @0x2c3894 vmrs APSR_nzcv, fpscr
 *   @0x2c3898 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c389c vldr s14, [pc, #284]
 *   @0x2c38a0 vldr s15, [pc, #276]
 *   @0x2c38a4 vldr s12, [sp, #20]
 *   @0x2c38a8 vldr s13, [pc, #264]
 *   @0x2c38ac vcmpe.f32 s12, s13
 *   @0x2c38b0 vmrs APSR_nzcv, fpscr
 *   @0x2c38b4 bpl 0x2c3944 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x1b0>
 *   @0x2c38b8 vldr s14, [sp, #4]
 *   @0x2c38bc vldr s13, [r3, #4]
 *   @0x2c38c0 vcmpe.f32 s14, s13
 *   @0x2c38c4 vmrs APSR_nzcv, fpscr
 *   @0x2c38c8 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c38cc vldr s13, [r3, #12]
 *   @0x2c38d0 vcmpe.f32 s14, s13
 *   @0x2c38d4 vmrs APSR_nzcv, fpscr
 *   @0x2c38d8 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c38dc vcmpe.f32 s15, #0
 *   @0x2c38e0 vmrs APSR_nzcv, fpscr
 *   @0x2c38e4 bmi 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c38e8 vldr s14, [r2, #16]
 *   @0x2c38ec vcmpe.f32 s15, s14
 *   @0x2c38f0 vmrs APSR_nzcv, fpscr
 *   @0x2c38f4 bgt 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c38f8 add r3, sp, #32
 *   @0x2c38fc vstr s15, [r4, #8]
 *   @0x2c3900 ldmdb r3, {r0, r1}
 *   @0x2c3904 mov r3, #1
 *   @0x2c3908 stm r4, {r0, r1}
 *   @0x2c390c mov r0, r3
 *   @0x2c3910 add sp, sp, #36
 *   @0x2c3914 ldr r4, [sp], #4
 *   @0x2c3918 bx lr
 *   @0x2c391c vmov.f32 s13, s15
 *   @0x2c3920 vmov.f32 s15, s14
 *   @0x2c3924 vmov.f32 s14, s13
 *   @0x2c3928 vldr s13, [pc, #140]
 *   @0x2c392c vcmpe.f32 s15, s13
 *   @0x2c3930 vmov.f32 s11, #-1.000000e+00
 *   @0x2c3934 vmrs APSR_nzcv, fpscr
 *   @0x2c3938 bgt 0x2c383c <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xa8>
 *   @0x2c393c vmov.f32 s15, s13
 *   @0x2c3940 b 0x2c3848 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xb4>
 *   @0x2c3944 vmov.f32 s9, #1.000000e+00
 *   @0x2c3948 vldr s11, [sp, #12]
 *   @0x2c394c vldr s10, [sp, #4]
 *   @0x2c3950 vldr s13, [r3, #4]
 *   @0x2c3954 vldr s12, [r3, #12]
 *   @0x2c3958 vdiv.f32 s11, s9, s11
 *   @0x2c395c vsub.f32 s13, s13, s10
 *   @0x2c3960 vsub.f32 s12, s12, s10
 *   @0x2c3964 vmul.f32 s13, s13, s11
 *   @0x2c3968 vmul.f32 s12, s12, s11
 *   @0x2c396c vcmpe.f32 s13, s12
 *   @0x2c3970 vmrs APSR_nzcv, fpscr
 *   @0x2c3974 vmovle.f32 s11, s12
 *   @0x2c3978 vmovle.f32 s12, s13
 *   @0x2c397c vmovle.f32 s13, s11
 *   @0x2c3980 vcmpe.f32 s12, s15
 *   @0x2c3984 vmovle.f32 s9, #-1.000000e+00
 *   @0x2c3988 vmrs APSR_nzcv, fpscr
 *   @0x2c398c movgt r3, #0
 *   @0x2c3990 vstrgt s9, [sp, #28]
 *   @0x2c3994 strgt r3, [sp, #0x18]
 *   @0x2c3998 vcmp.f32 s13, s14
 *   @0x2c399c vmovgt.f32 s15, s12
 *   @0x2c39a0 vmrs APSR_nzcv, fpscr
 *   @0x2c39a4 vmovgt.f32 s13, s14
 *   @0x2c39a8 vcmpe.f32 s15, s13
 *   @0x2c39ac vmrs APSR_nzcv, fpscr
 *   @0x2c39b0 ble 0x2c38dc <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0x148>
 *   @0x2c39b4 b 0x2c3864 <_ZNK6b2AABB7RayCastEP15b2RayCastOutputRK14b2RayCastInput+0xd0>
 *   @0x2c39b8 strlo r0, [r0], #-0
 *   @0x2c39bc .word 0xff7fffff
 *   @0x2c39c0 svcvc #0x7fffff
 *
 * ══ §50/54 Shader_Load(char*, char*)  0x187c44  size 556  139 条（0x187c44..0x187e70）
 * @func 0x187c44 0x187e70  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×12 / MemoryManager::Free(void const*)×5 / LoadFile(char*, int&)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6550×2 / 0xb65bc×2 / Shader_Add(char*, char*, char**, bool*, int, char**)
 * 字段偏移 top8: 0x1d4×3 / 0xc×3 / 0x10×3 / 0x14×3 / 0x8×2 / 0x1fc×1 / 0x1bc×1 / 0x108×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187c44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x187c48 cmp r1, #0
 *   @0x187c4c cmpne r0, #0
 *   @0x187c50 ldr r10, [pc, #0x1fc]
 *   @0x187c54 sub sp, sp, #28
 *   @0x187c58 mov r8, r1
 *   @0x187c5c movne r4, #0
 *   @0x187c60 moveq r4, #1
 *   @0x187c64 add r10, pc, r10
 *   @0x187c68 beq 0x187e48 <_Z11Shader_LoadPcS_+0x204>
 *   @0x187c6c add r1, sp, #16
 *   @0x187c70 bl 0x187bf8 <_Z8LoadFilePcRi>
 *   @0x187c74 subs r9, r0, #0
 *   @0x187c78 beq 0x187e48 <_Z11Shader_LoadPcS_+0x204>
 *   @0x187c7c ldr r3, [pc, #0x1d4]
 *   @0x187c80 ldr r2, [pc, #0x1d4]
 *   @0x187c84 ldr r11, [pc, #0x1d4]
 *   @0x187c88 add r2, pc, r2
 *   @0x187c8c str r2, [sp, #0xc]
 *   @0x187c90 ldr r6, [r10, r3]
 *   @0x187c94 add r11, pc, r11
 *   @0x187c98 mov r0, r6
 *   @0x187c9c bl 0xb6538 <strlen@plt>
 *   @0x187ca0 ldr r3, [pc, #0x1bc]
 *   @0x187ca4 ldr r5, [r10, r3]
 *   @0x187ca8 mov r7, r0
 *   @0x187cac mov r0, r5
 *   @0x187cb0 bl 0xb6538 <strlen@plt>
 *   @0x187cb4 ldr lr, [sp, #0x10]
 *   @0x187cb8 mov r1, r11
 *   @0x187cbc mov r2, #70
 *   @0x187cc0 add lr, lr, #1
 *   @0x187cc4 mov r3, #1
 *   @0x187cc8 add r7, lr, r7
 *   @0x187ccc add r0, r7, r0
 *   @0x187cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x187cd4 mov r2, r6
 *   @0x187cd8 ldr r1, [sp, #0xc]
 *   @0x187cdc mov r3, r5
 *   @0x187ce0 mov r7, r0
 *   @0x187ce4 bl 0xb6550 <sprintf@plt>
 *   @0x187ce8 mov r0, r6
 *   @0x187cec bl 0xb6538 <strlen@plt>
 *   @0x187cf0 mov r3, r0
 *   @0x187cf4 mov r0, r5
 *   @0x187cf8 str r3, [sp, #0x8]
 *   @0x187cfc bl 0xb6538 <strlen@plt>
 *   @0x187d00 ldr r3, [sp, #0x8]
 *   @0x187d04 mov r1, r9
 *   @0x187d08 ldr r2, [sp, #0x10]
 *   @0x187d0c add r0, r0, r3
 *   @0x187d10 add r0, r7, r0
 *   @0x187d14 bl 0xb65bc <memcpy@plt>
 *   @0x187d18 mov r0, r6
 *   @0x187d1c bl 0xb6538 <strlen@plt>
 *   @0x187d20 mov r6, r0
 *   @0x187d24 mov r0, r5
 *   @0x187d28 bl 0xb6538 <strlen@plt>
 *   @0x187d2c add r6, r7, r6
 *   @0x187d30 ldr r3, [sp, #0x10]
 *   @0x187d34 add r6, r6, r0
 *   @0x187d38 mov r0, r9
 *   @0x187d3c strb r4, [r6, r3]
 *   @0x187d40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187d44 mov r0, r8
 *   @0x187d48 add r1, sp, #20
 *   @0x187d4c bl 0x187bf8 <_Z8LoadFilePcRi>
 *   @0x187d50 subs r8, r0, #0
 *   @0x187d54 beq 0x187e40 <_Z11Shader_LoadPcS_+0x1fc>
 *   @0x187d58 ldr r3, [pc, #0x108]
 *   @0x187d5c ldr r6, [r10, r3]
 *   @0x187d60 mov r0, r6
 *   @0x187d64 bl 0xb6538 <strlen@plt>
 *   @0x187d68 ldr r3, [pc, #0xfc]
 *   @0x187d6c ldr r9, [r10, r3]
 *   @0x187d70 mov r5, r0
 *   @0x187d74 mov r0, r9
 *   @0x187d78 bl 0xb6538 <strlen@plt>
 *   @0x187d7c ldr r12, [sp, #0x14]
 *   @0x187d80 mov r1, r11
 *   @0x187d84 mov r2, #70
 *   @0x187d88 add r12, r12, #1
 *   @0x187d8c mov r3, #1
 *   @0x187d90 add r5, r12, r5
 *   @0x187d94 add r0, r5, r0
 *   @0x187d98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x187d9c mov r3, r9
 *   @0x187da0 ldr r1, [sp, #0xc]
 *   @0x187da4 mov r2, r6
 *   @0x187da8 mov r5, r0
 *   @0x187dac bl 0xb6550 <sprintf@plt>
 *   @0x187db0 mov r0, r6
 *   @0x187db4 bl 0xb6538 <strlen@plt>
 *   @0x187db8 mov r10, r0
 *   @0x187dbc mov r0, r9
 *   @0x187dc0 bl 0xb6538 <strlen@plt>
 *   @0x187dc4 mov r1, r8
 *   @0x187dc8 ldr r2, [sp, #0x14]
 *   @0x187dcc add r0, r0, r10
 *   @0x187dd0 add r0, r5, r0
 *   @0x187dd4 bl 0xb65bc <memcpy@plt>
 *   @0x187dd8 mov r0, r6
 *   @0x187ddc bl 0xb6538 <strlen@plt>
 *   @0x187de0 mov r6, r0
 *   @0x187de4 mov r0, r9
 *   @0x187de8 bl 0xb6538 <strlen@plt>
 *   @0x187dec add r6, r5, r6
 *   @0x187df0 ldr r3, [sp, #0x14]
 *   @0x187df4 add r6, r6, r0
 *   @0x187df8 mov r0, r8
 *   @0x187dfc strb r4, [r6, r3]
 *   @0x187e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187e04 mov r2, r4
 *   @0x187e08 mov r3, r4
 *   @0x187e0c mov r1, r5
 *   @0x187e10 str r4, [sp]
 *   @0x187e14 mov r0, r7
 *   @0x187e18 str r4, [sp, #0x4]
 *   @0x187e1c bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_>
 *   @0x187e20 mov r4, r0
 *   @0x187e24 mov r0, r7
 *   @0x187e28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187e2c mov r0, r5
 *   @0x187e30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187e34 mov r0, r4
 *   @0x187e38 add sp, sp, #28
 *   @0x187e3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x187e40 mov r0, r7
 *   @0x187e44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x187e48 mvn r0, #0
 *   @0x187e4c add sp, sp, #28
 *   @0x187e50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x187e54 eoreq r9, r6, r12, ror #31
 *   @0x187e58 .word 0xffffe910
 *   @0x187e5c andseq r12, r10, r12, asr #30
 *   @0x187e60 mulseq r10, r12, r3
 *   @0x187e64 .word 0xffffe914
 *   @0x187e68 .word 0xffffe918
 *   @0x187e6c .word 0xffffe91c
 *
 * ══ §51/54 Eff_Effect07(int, float, float, int, unsigned int)  0x1a17ec  size 556  139 条（0x1a17ec..0x1a1a18）
 * @func 0x1a17ec 0x1a1a18  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a1818→0x5423d8
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Orientation(int, float, float, float, float, bool)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×9 / 0x8×5 / 0x1f8×1 / 0x1f4×1 / 0x30×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a17ec push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a17f0 vpush {d8}
 *   @0x1a17f4 sub sp, sp, #12
 *   @0x1a17f8 mov r4, r3
 *   @0x1a17fc mov r7, r1
 *   @0x1a1800 mov r6, r2
 *   @0x1a1804 mov r8, r0
 *   @0x1a1808 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a180c cmp r4, #0
 *   @0x1a1810 ldr r3, [pc, #0x1f8]
 *   @0x1a1814 mov r1, #9
 *   @0x1a1818 ldr r2, [pc, #0x1f4]
 *   @0x1a181c add r3, pc, r3
 *   @0x1a1820 vmov s16, r0
 *   @0x1a1824 beq 0x1a18e8 <_Z12Eff_Effect07iffij+0xfc>
 *   @0x1a1828 cmp r4, #2
 *   @0x1a182c mov r5, #0
 *   @0x1a1830 ldr r4, [r3, r2]
 *   @0x1a1834 beq 0x1a1978 <_Z12Eff_Effect07iffij+0x18c>
 *   @0x1a1838 ldr r0, [r4, #0x4]
 *   @0x1a183c bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1840 vldr s15, [pc, #444]
 *   @0x1a1844 vmul.f32 s15, s16, s15
 *   @0x1a1848 mov r1, #1061158912
 *   @0x1a184c ldr r0, [r4, #0x4]
 *   @0x1a1850 mov r2, r1
 *   @0x1a1854 str r5, [sp]
 *   @0x1a1858 vmov r3, s15
 *   @0x1a185c bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1860 ldr r0, [r4, #0x4]
 *   @0x1a1864 mov r1, r5
 *   @0x1a1868 str r5, [sp]
 *   @0x1a186c mov r3, #0
 *   @0x1a1870 mov r2, #0
 *   @0x1a1874 str r3, [sp, #0x4]
 *   @0x1a1878 movt r2, #0x43b4
 *   @0x1a187c mov r3, r5
 *   @0x1a1880 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1884 vmov.f32 s15, #2.500000e+01
 *   @0x1a1888 ldr r9, [r4, #0x4]
 *   @0x1a188c vdiv.f32 s16, s15, s16
 *   @0x1a1890 vcvt.f64.f32 d8, s16
 *   @0x1a1894 vmov r0, r1, d8
 *   @0x1a1898 bl 0xb66e8 <lrint@plt>
 *   @0x1a189c mov r5, r0
 *   @0x1a18a0 vmov r0, r1, d8
 *   @0x1a18a4 bl 0xb66e8 <lrint@plt>
 *   @0x1a18a8 mov r1, r5
 *   @0x1a18ac mov r2, r0
 *   @0x1a18b0 mov r0, r9
 *   @0x1a18b4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a18b8 ldr r3, [r4, #0x4]
 *   @0x1a18bc ldr r2, [sp, #0x30]
 *   @0x1a18c0 mov r12, #1
 *   @0x1a18c4 mov r0, r8
 *   @0x1a18c8 mov r1, r7
 *   @0x1a18cc str r12, [sp, #0x4]
 *   @0x1a18d0 str r2, [sp]
 *   @0x1a18d4 mov r2, r6
 *   @0x1a18d8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a18dc add sp, sp, #12
 *   @0x1a18e0 vpop {d8}
 *   @0x1a18e4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a18e8 ldr r5, [r3, r2]
 *   @0x1a18ec mov r9, #0
 *   @0x1a18f0 ldr r0, [r5]
 *   @0x1a18f4 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a18f8 vldr s15, [pc, #264]
 *   @0x1a18fc vmul.f32 s15, s16, s15
 *   @0x1a1900 movw r1, #0xcccd
 *   @0x1a1904 movt r1, #0x3ecc
 *   @0x1a1908 ldr r0, [r5]
 *   @0x1a190c str r9, [sp]
 *   @0x1a1910 mov r2, r1
 *   @0x1a1914 vmov r3, s15
 *   @0x1a1918 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a191c mov r3, r9
 *   @0x1a1920 ldr r0, [r5]
 *   @0x1a1924 mov r1, r9
 *   @0x1a1928 str r9, [sp]
 *   @0x1a192c mov r2, #0
 *   @0x1a1930 str r4, [sp, #0x4]
 *   @0x1a1934 movt r2, #0x43b4
 *   @0x1a1938 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a193c vmov.f32 s15, #2.000000e+01
 *   @0x1a1940 ldr r9, [r5]
 *   @0x1a1944 vdiv.f32 s16, s15, s16
 *   @0x1a1948 vcvt.f64.f32 d8, s16
 *   @0x1a194c vmov r0, r1, d8
 *   @0x1a1950 bl 0xb66e8 <lrint@plt>
 *   @0x1a1954 mov r4, r0
 *   @0x1a1958 vmov r0, r1, d8
 *   @0x1a195c bl 0xb66e8 <lrint@plt>
 *   @0x1a1960 mov r1, r4
 *   @0x1a1964 mov r2, r0
 *   @0x1a1968 mov r0, r9
 *   @0x1a196c bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1970 ldr r3, [r5]
 *   @0x1a1974 b 0x1a18bc <_Z12Eff_Effect07iffij+0xd0>
 *   @0x1a1978 ldr r0, [r4, #0x8]
 *   @0x1a197c bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1980 vldr s15, [pc, #132]
 *   @0x1a1984 vmul.f32 s15, s16, s15
 *   @0x1a1988 movw r1, #0x999a
 *   @0x1a198c movt r1, #0x3f99
 *   @0x1a1990 ldr r0, [r4, #0x8]
 *   @0x1a1994 str r5, [sp]
 *   @0x1a1998 mov r2, r1
 *   @0x1a199c vmov r3, s15
 *   @0x1a19a0 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a19a4 ldr r0, [r4, #0x8]
 *   @0x1a19a8 mov r1, r5
 *   @0x1a19ac str r5, [sp]
 *   @0x1a19b0 mov r3, #0
 *   @0x1a19b4 mov r2, #0
 *   @0x1a19b8 str r3, [sp, #0x4]
 *   @0x1a19bc movt r2, #0x43b4
 *   @0x1a19c0 mov r3, r5
 *   @0x1a19c4 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a19c8 vmov.f32 s15, #3.000000e+01
 *   @0x1a19cc ldr r9, [r4, #0x8]
 *   @0x1a19d0 vdiv.f32 s16, s15, s16
 *   @0x1a19d4 vcvt.f64.f32 d8, s16
 *   @0x1a19d8 vmov r0, r1, d8
 *   @0x1a19dc bl 0xb66e8 <lrint@plt>
 *   @0x1a19e0 mov r5, r0
 *   @0x1a19e4 vmov r0, r1, d8
 *   @0x1a19e8 bl 0xb66e8 <lrint@plt>
 *   @0x1a19ec mov r1, r5
 *   @0x1a19f0 mov r2, r0
 *   @0x1a19f4 mov r0, r9
 *   @0x1a19f8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a19fc ldr r3, [r4, #0x8]
 *   @0x1a1a00 b 0x1a18bc <_Z12Eff_Effect07iffij+0xd0>
 *   @0x1a1a04 ldcllt p2, c12, [r5], #572
 *   @0x1a1a08 stclt p7, c13, [r3], #40
 *   @0x1a1a0c stclt p7, c13, [r3, #-40]!
 *   @0x1a1a10 eoreq r0, r5, r4, lsr r4
 *   @0x1a1a14 .word 0xffffeb3c
 *
 * ══ §52/54 Eff_Effect08(int, float, float, int, unsigned int)  0x1a1a44  size 556  139 条（0x1a1a44..0x1a1c70）
 * @func 0x1a1a44 0x1a1c70  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a1a70→0x5423cc
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Orientation(int, float, float, float, float, bool)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×9 / 0x8×5 / 0x1f8×1 / 0x1f4×1 / 0x30×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1a44 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a1a48 vpush {d8}
 *   @0x1a1a4c sub sp, sp, #12
 *   @0x1a1a50 mov r4, r3
 *   @0x1a1a54 mov r7, r1
 *   @0x1a1a58 mov r6, r2
 *   @0x1a1a5c mov r8, r0
 *   @0x1a1a60 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a1a64 cmp r4, #0
 *   @0x1a1a68 ldr r3, [pc, #0x1f8]
 *   @0x1a1a6c mov r1, #8
 *   @0x1a1a70 ldr r2, [pc, #0x1f4]
 *   @0x1a1a74 add r3, pc, r3
 *   @0x1a1a78 vmov s16, r0
 *   @0x1a1a7c beq 0x1a1b40 <_Z12Eff_Effect08iffij+0xfc>
 *   @0x1a1a80 cmp r4, #2
 *   @0x1a1a84 mov r5, #0
 *   @0x1a1a88 ldr r4, [r3, r2]
 *   @0x1a1a8c beq 0x1a1bd0 <_Z12Eff_Effect08iffij+0x18c>
 *   @0x1a1a90 ldr r0, [r4, #0x4]
 *   @0x1a1a94 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1a98 vldr s15, [pc, #444]
 *   @0x1a1a9c vmul.f32 s15, s16, s15
 *   @0x1a1aa0 mov r1, #1061158912
 *   @0x1a1aa4 ldr r0, [r4, #0x4]
 *   @0x1a1aa8 mov r2, r1
 *   @0x1a1aac str r5, [sp]
 *   @0x1a1ab0 vmov r3, s15
 *   @0x1a1ab4 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1ab8 ldr r0, [r4, #0x4]
 *   @0x1a1abc mov r1, r5
 *   @0x1a1ac0 str r5, [sp]
 *   @0x1a1ac4 mov r3, #0
 *   @0x1a1ac8 mov r2, #0
 *   @0x1a1acc str r3, [sp, #0x4]
 *   @0x1a1ad0 movt r2, #0x43b4
 *   @0x1a1ad4 mov r3, r5
 *   @0x1a1ad8 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1adc vmov.f32 s15, #2.500000e+01
 *   @0x1a1ae0 ldr r9, [r4, #0x4]
 *   @0x1a1ae4 vdiv.f32 s16, s15, s16
 *   @0x1a1ae8 vcvt.f64.f32 d8, s16
 *   @0x1a1aec vmov r0, r1, d8
 *   @0x1a1af0 bl 0xb66e8 <lrint@plt>
 *   @0x1a1af4 mov r5, r0
 *   @0x1a1af8 vmov r0, r1, d8
 *   @0x1a1afc bl 0xb66e8 <lrint@plt>
 *   @0x1a1b00 mov r1, r5
 *   @0x1a1b04 mov r2, r0
 *   @0x1a1b08 mov r0, r9
 *   @0x1a1b0c bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1b10 ldr r3, [r4, #0x4]
 *   @0x1a1b14 ldr r2, [sp, #0x30]
 *   @0x1a1b18 mov r12, #1
 *   @0x1a1b1c mov r0, r8
 *   @0x1a1b20 mov r1, r7
 *   @0x1a1b24 str r12, [sp, #0x4]
 *   @0x1a1b28 str r2, [sp]
 *   @0x1a1b2c mov r2, r6
 *   @0x1a1b30 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1b34 add sp, sp, #12
 *   @0x1a1b38 vpop {d8}
 *   @0x1a1b3c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a1b40 ldr r5, [r3, r2]
 *   @0x1a1b44 mov r9, #0
 *   @0x1a1b48 ldr r0, [r5]
 *   @0x1a1b4c bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1b50 vldr s15, [pc, #264]
 *   @0x1a1b54 vmul.f32 s15, s16, s15
 *   @0x1a1b58 movw r1, #0xcccd
 *   @0x1a1b5c movt r1, #0x3ecc
 *   @0x1a1b60 ldr r0, [r5]
 *   @0x1a1b64 str r9, [sp]
 *   @0x1a1b68 mov r2, r1
 *   @0x1a1b6c vmov r3, s15
 *   @0x1a1b70 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1b74 mov r3, r9
 *   @0x1a1b78 ldr r0, [r5]
 *   @0x1a1b7c mov r1, r9
 *   @0x1a1b80 str r9, [sp]
 *   @0x1a1b84 mov r2, #0
 *   @0x1a1b88 str r4, [sp, #0x4]
 *   @0x1a1b8c movt r2, #0x43b4
 *   @0x1a1b90 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1b94 vmov.f32 s15, #2.000000e+01
 *   @0x1a1b98 ldr r9, [r5]
 *   @0x1a1b9c vdiv.f32 s16, s15, s16
 *   @0x1a1ba0 vcvt.f64.f32 d8, s16
 *   @0x1a1ba4 vmov r0, r1, d8
 *   @0x1a1ba8 bl 0xb66e8 <lrint@plt>
 *   @0x1a1bac mov r4, r0
 *   @0x1a1bb0 vmov r0, r1, d8
 *   @0x1a1bb4 bl 0xb66e8 <lrint@plt>
 *   @0x1a1bb8 mov r1, r4
 *   @0x1a1bbc mov r2, r0
 *   @0x1a1bc0 mov r0, r9
 *   @0x1a1bc4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1bc8 ldr r3, [r5]
 *   @0x1a1bcc b 0x1a1b14 <_Z12Eff_Effect08iffij+0xd0>
 *   @0x1a1bd0 ldr r0, [r4, #0x8]
 *   @0x1a1bd4 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1bd8 vldr s15, [pc, #132]
 *   @0x1a1bdc vmul.f32 s15, s16, s15
 *   @0x1a1be0 movw r1, #0x999a
 *   @0x1a1be4 movt r1, #0x3f99
 *   @0x1a1be8 ldr r0, [r4, #0x8]
 *   @0x1a1bec str r5, [sp]
 *   @0x1a1bf0 mov r2, r1
 *   @0x1a1bf4 vmov r3, s15
 *   @0x1a1bf8 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1bfc ldr r0, [r4, #0x8]
 *   @0x1a1c00 mov r1, r5
 *   @0x1a1c04 str r5, [sp]
 *   @0x1a1c08 mov r3, #0
 *   @0x1a1c0c mov r2, #0
 *   @0x1a1c10 str r3, [sp, #0x4]
 *   @0x1a1c14 movt r2, #0x43b4
 *   @0x1a1c18 mov r3, r5
 *   @0x1a1c1c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1c20 vmov.f32 s15, #3.000000e+01
 *   @0x1a1c24 ldr r9, [r4, #0x8]
 *   @0x1a1c28 vdiv.f32 s16, s15, s16
 *   @0x1a1c2c vcvt.f64.f32 d8, s16
 *   @0x1a1c30 vmov r0, r1, d8
 *   @0x1a1c34 bl 0xb66e8 <lrint@plt>
 *   @0x1a1c38 mov r5, r0
 *   @0x1a1c3c vmov r0, r1, d8
 *   @0x1a1c40 bl 0xb66e8 <lrint@plt>
 *   @0x1a1c44 mov r1, r5
 *   @0x1a1c48 mov r2, r0
 *   @0x1a1c4c mov r0, r9
 *   @0x1a1c50 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1c54 ldr r3, [r4, #0x8]
 *   @0x1a1c58 b 0x1a1b14 <_Z12Eff_Effect08iffij+0xd0>
 *   @0x1a1c5c ldcllt p2, c12, [r5], #572
 *   @0x1a1c60 stclt p7, c13, [r3], #40
 *   @0x1a1c64 stclt p7, c13, [r3, #-40]!
 *   @0x1a1c68 .word 0x002501dc
 *   @0x1a1c6c .word 0xffffeb40
 *
 * ══ §53/54 Audio_SetGainForNoise(CNoise*, float, int)  0x217758  size 308  63 条（0x217758..0x21788c）｜其中 14 条已由别的卡落锚，本节不再重复
 * @func 0x217758 0x21788c  size 308  63 条
 * 部分覆盖: 本节 63/77 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21776c→0x755363, 0x2177dc→0x5428e8, 0x2177f0→0x54298c, 0x217858→0x5428c0
 * 调用序列: __divsi3×2 / CTimingSource::GetFPS()
 * 字段偏移 top8: 0x2c×3 / 0x10c×1 / 0x108×1 / 0x9c×1 / 0x8c×1 / 0xc×1 / 0x28×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217758 push {r3, r4, r5, lr}
 *   @0x21775c vpush {d8}
 *   @0x217760 vmov s16, r1
 *   @0x217780 cmp r1, #0
 *   @0x217784 bne 0x217850 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xf8>
 *   @0x217788 vcmp.f32 s16, #0
 *   @0x21778c vldr s15, [pc, #224]
 *   @0x217790 vmrs APSR_nzcv, fpscr
 *   @0x217794 vmovmi.f32 s16, s15
 *   @0x217798 cmp r2, #0
 *   @0x21779c bne 0x2177dc <_Z21Audio_SetGainForNoiseP6CNoisefi+0x84>
 *   @0x2177a0 vldr s15, [r0, #36]
 *   @0x2177a4 vcmp.f32 s15, s16
 *   @0x2177a8 vmrs APSR_nzcv, fpscr
 *   @0x2177ac bne 0x2177bc <_Z21Audio_SetGainForNoiseP6CNoisefi+0x64>
 *   @0x2177b0 ldr r3, [r0, #0x2c]
 *   @0x2177b4 cmp r3, #0
 *   @0x2177b8 beq 0x217850 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xf8>
 *   @0x2177bc vstr s16, [r4, #36]
 *   @0x2177c0 vmov r1, s16
 *   @0x2177c4 vpop {d8}
 *   @0x2177c8 mov r3, #0
 *   @0x2177cc mov r0, r4
 *   @0x2177d0 str r3, [r4, #0x2c]
 *   @0x2177f0 ldr r2, [pc, #0x8c]
 *   @0x2177f4 ldr r3, [r3, r2]
 *   @0x2177f8 ldr r3, [r3]
 *   @0x2177fc cmp r3, #0
 *   @0x217800 moveq r1, #33
 *   @0x217804 beq 0x217820 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xc8>
 *   @0x217808 ldr r1, [r3, #0xc]
 *   @0x21780c mov r0, #1000
 *   @0x217810 bl 0x318d10 <__divsi3>
 *   @0x217814 cmp r0, #1
 *   @0x217818 movge r1, r0
 *   @0x21781c movlt r1, #1
 *   @0x217820 mov r0, r5
 *   @0x217824 bl 0x318d10 <__divsi3>
 *   @0x217828 cmp r0, #0
 *   @0x21782c vmovgt s15, r0
 *   @0x217830 movle r0, #1
 *   @0x217834 vmovle.f32 s14, #1.000000e+00
 *   @0x217838 str r0, [r4, #0x2c]
 *   @0x21783c vcvtgt.f32.s32 s14, s15
 *   @0x217840 vldr s15, [r4, #36]
 *   @0x217844 vsub.f32 s16, s16, s15
 *   @0x217848 vdiv.f32 s16, s16, s14
 *   @0x21784c vstr s16, [r4, #40]
 *   @0x217850 vpop {d8}
 *   @0x217854 pop {r3, r4, r5, pc}
 *   @0x217858 ldr r2, [pc, #0x28]
 *   @0x21785c ldr r0, [r3, r2]
 *   @0x217860 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x217864 vmov d7, r0, r1
 *   @0x217868 vcvt.s32.f64 s15, d7
 *   @0x21786c vmov r1, s15
 *   @0x217870 b 0x21780c <_Z21Audio_SetGainForNoiseP6CNoisefi+0xb4>
 *   @0x217874 andeq r0, r0, r0
 *   @0x217878 ldrsbeq r10, [sp], -r12
 *   @0x21787c .word 0xffffd3fc
 *   @0x217880 .word 0xffffbcd4
 *   @0x217884 .word 0xffffbcd8
 *   @0x217888 .word 0xffffbcdc
 *
 * ══ §54/54 CSkeletonInstance::ClearAnimation(int)  0xbe7f0  size 28  7 条（0xbe7f0..0xbe80c）
 * @func 0xbe7f0 0xbe80c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe7f0 subs r3, r1, #0
 *   @0xbe7f4 bxlt lr
 *   @0xbe7f8 ldr r0, [r0, #0x28]
 *   @0xbe7fc ldr r2, [r0, #0xc]
 *   @0xbe800 cmp r3, r2
 *   @0xbe804 bxge lr
 *   @0xbe808 b 0x283558 <spAnimationState_clearTrack>
 */
