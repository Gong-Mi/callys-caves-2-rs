/* cally 逆向卡：All_67 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 828 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/828 isHexdigit(char)  0x202580  size 48  12 条（0x202580..0x2025b0）
 * @func 0x202580 0x2025b0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: isHexdigit(char)+0x28
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202580 sub r2, r0, #65
 *   @0x202584 sub r3, r0, #48
 *   @0x202588 cmp r3, #9
 *   @0x20258c cmphi r2, #5
 *   @0x202590 bls 0x2025a8 <_Z10isHexdigitc+0x28>
 *   @0x202594 sub r0, r0, #97
 *   @0x202598 cmp r0, #5
 *   @0x20259c movhi r0, #0
 *   @0x2025a0 movls r0, #1
 *   @0x2025a4 bx lr
 *   @0x2025a8 mov r0, #1
 *   @0x2025ac bx lr
 *
 * ══ §2/828 CSound::CSound()  0x215354  size 48  12 条（0x215354..0x215384）
 * @func 0x215354 0x215384  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / CSound::Clear()
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215354 push {r4, lr}
 *   @0x215358 mov r1, #0
 *   @0x21535c mov r4, r0
 *   @0x215360 mov r2, #64
 *   @0x215364 bl 0xb65b0 <memset@plt>
 *   @0x215368 mvn r3, #0
 *   @0x21536c mov r0, r4
 *   @0x215370 str r4, [r4]
 *   @0x215374 str r3, [r4, #0x30]
 *   @0x215378 bl 0x21529c <_ZN6CSound5ClearEv>
 *   @0x21537c mov r0, r4
 *   @0x215380 pop {r4, pc}
 *
 * ══ §3/828 cAudio_Sound::FreeALBuffer()  0x2193d4  size 48  12 条（0x2193d4..0x219404）
 * @func 0x2193d4 0x219404  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6ad8 / 0xb6ae4
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2193d4 push {r4, lr}
 *   @0x2193d8 mov r4, r0
 *   @0x2193dc ldr r0, [r0, #0x18]
 *   @0x2193e0 bl 0xb6ad8 <alIsBuffer@plt>
 *   @0x2193e4 cmp r0, #0
 *   @0x2193e8 popeq {r4, pc}
 *   @0x2193ec mov r0, #1
 *   @0x2193f0 add r1, r4, #24
 *   @0x2193f4 bl 0xb6ae4 <alDeleteBuffers@plt>
 *   @0x2193f8 mvn r3, #0
 *   @0x2193fc str r3, [r4, #0x18]
 *   @0x219400 pop {r4, pc}
 *
 * ══ §4/828 Audio_Unsuspend()  0x219870  size 48  12 条（0x219870..0x2198a0）
 * @func 0x219870 0x2198a0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219870 ldr r3, [pc, #0x20]
 *   @0x219874 ldr r3, [pc, r3]
 *   @0x219878 ldrb r2, [r3]
 *   @0x21987c cmp r2, #0
 *   @0x219880 bxeq lr
 *   @0x219884 ldr r0, [pc, #0x10]
 *   @0x219888 mov r2, #0
 *   @0x21988c strb r2, [r3]
 *   @0x219890 add r0, pc, r0
 *   @0x219894 b 0x226100 <_ZN9COggAudio9UnsuspendEv>
 *   @0x219898 andseq r7, sp, r8, ror r11
 *   @0x21989c subseq r11, r3, r4, lsl #20
 *
 * ══ §5/828 Audio_SyncGroupDebug(int)  0x21d68c  size 48  12 条（0x21d68c..0x21d6bc）
 * @func 0x21d68c 0x21d6cc  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d68c ldr r3, [pc, #0x20]
 *   @0x21d690 cmn r0, #1
 *   @0x21d694 mov r1, r0
 *   @0x21d698 ldr r0, [pc, #0x18]
 *   @0x21d69c ldr r3, [pc, r3]
 *   @0x21d6a0 movne r2, #32
 *   @0x21d6a4 moveq r2, #0
 *   @0x21d6a8 add r0, pc, r0
 *   @0x21d6ac str r2, [r3]
 *   @0x21d6b0 b 0x22627c <_ZN9COggAudio14DebugSyncGroupEi>
 *   @0x21d6b4 mulseq sp, r0, sp
 *   @0x21d6b8 subseq r7, r3, r12, ror #23
 *
 * ══ §6/828 OpenAL_PauseMP3()  0x2231c4  size 48  12 条（0x2231c4..0x2231f4）
 * @func 0x2231c4 0x223204  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2231c4 push {r3, lr}
 *   @0x2231c8 bl 0x290274 <getJNIEnv>
 *   @0x2231cc ldr r2, [pc, #0x18]
 *   @0x2231d0 ldr r3, [pc, #0x18]
 *   @0x2231d4 ldr r2, [pc, r2]
 *   @0x2231d8 ldr r3, [pc, r3]
 *   @0x2231dc ldr r1, [r2]
 *   @0x2231e0 ldr r2, [r3]
 *   @0x2231e4 pop {r3, lr}
 *   @0x2231e8 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x2231ec ldrsbeq r10, [r12], -r0
 *   @0x2231f0 andseq lr, r12, r8, lsl #5
 *
 * ══ §7/828 OpenAL_ResumeMP3()  0x2231f4  size 48  12 条（0x2231f4..0x223224）
 * @func 0x2231f4 0x223234  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2231f4 push {r3, lr}
 *   @0x2231f8 bl 0x290274 <getJNIEnv>
 *   @0x2231fc ldr r2, [pc, #0x18]
 *   @0x223200 ldr r3, [pc, #0x18]
 *   @0x223204 ldr r2, [pc, r2]
 *   @0x223208 ldr r3, [pc, r3]
 *   @0x22320c ldr r1, [r2]
 *   @0x223210 ldr r2, [r3]
 *   @0x223214 pop {r3, lr}
 *   @0x223218 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x22321c andseq r10, r12, r0, lsr #15
 *   @0x223220 andseq lr, r12, r12, asr r2
 *
 * ══ §8/828 OpenAL_StopMP3()  0x223224  size 48  12 条（0x223224..0x223254）
 * @func 0x223224 0x223254  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223224 push {r3, lr}
 *   @0x223228 bl 0x290274 <getJNIEnv>
 *   @0x22322c ldr r2, [pc, #0x18]
 *   @0x223230 ldr r3, [pc, #0x18]
 *   @0x223234 ldr r2, [pc, r2]
 *   @0x223238 ldr r3, [pc, r3]
 *   @0x22323c ldr r1, [r2]
 *   @0x223240 ldr r2, [r3]
 *   @0x223244 pop {r3, lr}
 *   @0x223248 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x22324c andseq r10, r12, r0, ror r7
 *   @0x223250 andseq lr, r12, r0, lsr r2
 *
 * ══ §9/828 COggAudio::Stop_Sound(int)  0x226404  size 48  12 条（0x226404..0x226434）
 * @func 0x226404 0x226434  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::GetThreadForChannel(int, int&) / COggThread::Stop_Sound(int)
 * 字段偏移 top8: 0x-4×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226404 str lr, [sp, #-0x4]!
 *   @0x226408 sub sp, sp, #12
 *   @0x22640c add r2, sp, #8
 *   @0x226410 mov r3, #0
 *   @0x226414 str r3, [r2, #-0x4]!
 *   @0x226418 bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi>
 *   @0x22641c cmp r0, #0
 *   @0x226420 beq 0x22642c <_ZN9COggAudio10Stop_SoundEi+0x28>
 *   @0x226424 ldr r1, [sp, #0x4]
 *   @0x226428 bl 0x223b78 <_ZN10COggThread10Stop_SoundEi>
 *   @0x22642c add sp, sp, #12
 *   @0x226430 ldr pc, [sp], #4
 *
 * ══ §10/828 ogg_stream_packetpeek  0x23535c  size 48  12 条（0x23535c..0x23538c）
 * @func 0x23535c 0x23539c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23535c push {r3, r4, r5, lr}
 *   @0x235360 mov r4, r1
 *   @0x235364 mov r5, r0
 *   @0x235368 bl 0x23412c <ogg_stream_check>
 *   @0x23536c subs r2, r0, #0
 *   @0x235370 beq 0x23537c <ogg_stream_packetpeek+0x20>
 *   @0x235374 mov r0, #0
 *   @0x235378 pop {r3, r4, r5, pc}
 *   @0x23537c mov r0, r5
 *   @0x235380 mov r1, r4
 *   @0x235384 pop {r3, r4, r5, lr}
 *   @0x235388 b 0x233e64 <oggpackB_get_buffer+0x4>
 *
 * ══ §11/828 Key::~Key()  0x2353b0  size 48  12 条（0x2353b0..0x2353e0）
 * @func 0x2353b0 0x2353e0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2353b0 push {r4, lr}
 *   @0x2353b4 mov r4, r0
 *   @0x2353b8 ldr r0, [r0, #0x4]
 *   @0x2353bc cmp r0, #0
 *   @0x2353c0 beq 0x2353c8 <_ZN3KeyD2Ev+0x18>
 *   @0x2353c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2353c8 ldr r0, [r4, #0x8]
 *   @0x2353cc cmp r0, #0
 *   @0x2353d0 beq 0x2353d8 <_ZN3KeyD2Ev+0x28>
 *   @0x2353d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2353d8 mov r0, r4
 *   @0x2353dc pop {r4, pc}
 *
 * ══ §12/828 CPhysicsObject::SetMass(float, float, float, float)  0x236dd0  size 48  12 条（0x236dd0..0x236e00）
 * @func 0x236dd0 0x236e00  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::SetMassData(b2MassData const*)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x18×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236dd0 str lr, [sp, #-0x4]!
 *   @0x236dd4 sub sp, sp, #20
 *   @0x236dd8 ldr r0, [r0]
 *   @0x236ddc ldr r12, [sp, #0x18]
 *   @0x236de0 str r1, [sp]
 *   @0x236de4 mov r1, sp
 *   @0x236de8 str r2, [sp, #0x4]
 *   @0x236dec str r3, [sp, #0x8]
 *   @0x236df0 str r12, [sp, #0xc]
 *   @0x236df4 bl 0x2c7030 <_ZN6b2Body11SetMassDataEPK10b2MassData>
 *   @0x236df8 add sp, sp, #20
 *   @0x236dfc ldr pc, [sp], #4
 *
 * ══ §13/828 DateGetNow()  0x244988  size 48  12 条（0x244988..0x2449b8）
 * @func 0x244988 0x2449c8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67fc
 * 字段偏移 top8: 无
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244988 push {r3, lr}
 *   @0x24498c mov r0, #0
 *   @0x244990 bl 0xb67fc <time@plt>
 *   @0x244994 vldr d7, [pc, #20]
 *   @0x244998 vmov s10, r0
 *   @0x24499c vcvt.f64.s32 d6, s10
 *   @0x2449a0 vmul.f64 d5, d6, d7
 *   @0x2449a4 vmov r0, r1, d5
 *   @0x2449a8 pop {r3, pc}
 *   @0x2449ac nop
 *   @0x2449b0 andeq r0, r0, r0
 *   @0x2449b4 addmi r4, pc, r0
 *
 * ══ §14/828 CThread::Sleep(int)  0x27e114  size 48  12 条（0x27e114..0x27e144）
 * @func 0x27e114 0x27e144  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c04
 * 字段偏移 top8: 0x4×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e114 movw r3, #0x4240
 *   @0x27e118 movt r3, #0xf
 *   @0x27e11c str lr, [sp, #-0x4]!
 *   @0x27e120 sub sp, sp, #12
 *   @0x27e124 mul r3, r3, r0
 *   @0x27e128 mov r1, #0
 *   @0x27e12c mov r0, sp
 *   @0x27e130 str r1, [sp]
 *   @0x27e134 str r3, [sp, #0x4]
 *   @0x27e138 bl 0xb6c04 <nanosleep@plt>
 *   @0x27e13c add sp, sp, #12
 *   @0x27e140 ldr pc, [sp], #4
 *
 * ══ §15/828 json_object_new_int  0x27eaf8  size 48  12 条（0x27eaf8..0x27eb28）
 * @func 0x27eaf8 0x27eb28  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c
 * 字段偏移 top8: 0xc×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27eaf8 push {r4, lr}
 *   @0x27eafc mov r4, r0
 *   @0x27eb00 mov r0, #3
 *   @0x27eb04 bl 0x27e724 <mc_info+0x35c>
 *   @0x27eb08 cmp r0, #0
 *   @0x27eb0c popeq {r4, pc}
 *   @0x27eb10 ldr r3, [pc, #0xc]
 *   @0x27eb14 str r4, [r0, #0x18]
 *   @0x27eb18 add r3, pc, r3
 *   @0x27eb1c str r3, [r0, #0x8]
 *   @0x27eb20 pop {r4, pc}
 *   @0x27eb24 .word 0xfffff8e8
 *
 * ══ §16/828 lh_kptr_table_new  0x28091c  size 48  12 条（0x28091c..0x28094c）
 * @func 0x28091c 0x28094c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_new
 * 字段偏移 top8: 0x18×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28091c str lr, [sp, #-0x4]!
 *   @0x280920 sub sp, sp, #12
 *   @0x280924 ldr r3, [pc, #0x18]
 *   @0x280928 ldr r12, [pc, #0x18]
 *   @0x28092c ldr r3, [pc, r3]
 *   @0x280930 ldr r12, [pc, r12]
 *   @0x280934 str r12, [sp]
 *   @0x280938 bl 0x280834 <lh_table_new>
 *   @0x28093c add sp, sp, #12
 *   @0x280940 ldr pc, [sp], #4
 *   @0x280944 andseq r0, r7, r12, ror #30
 *   @0x280948 andseq r0, r7, r12, ror #30
 *
 * ══ §17/828 spTranslateTimeline_setFrame  0x282ad4  size 48  12 条（0x282ad4..0x282b04）
 * @func 0x282ad4 0x282b04  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282ad4 add r1, r1, r1, lsl #1
 *   @0x282ad8 ldr r0, [r0, #0x10]
 *   @0x282adc str r4, [sp, #-0x4]!
 *   @0x282ae0 add r12, r1, #1
 *   @0x282ae4 ldr r4, [sp, #0x4]
 *   @0x282ae8 add r1, r0, r1, lsl #2
 *   @0x282aec add r0, r0, r12, lsl #2
 *   @0x282af0 str r2, [r1]
 *   @0x282af4 str r4, [r0, #0x4]
 *   @0x282af8 str r3, [r0]
 *   @0x282afc ldr r4, [sp], #4
 *   @0x282b00 bx lr
 *
 * ══ §18/828 spPathConstraintMixTimeline_setFrame  0x283080  size 48  12 条（0x283080..0x2830b0）
 * @func 0x283080 0x2830b0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283080 add r1, r1, r1, lsl #1
 *   @0x283084 ldr r0, [r0, #0x10]
 *   @0x283088 str r4, [sp, #-0x4]!
 *   @0x28308c add r12, r1, #1
 *   @0x283090 ldr r4, [sp, #0x4]
 *   @0x283094 add r1, r0, r1, lsl #2
 *   @0x283098 add r0, r0, r12, lsl #2
 *   @0x28309c str r2, [r1]
 *   @0x2830a0 str r4, [r0, #0x4]
 *   @0x2830a4 str r3, [r0]
 *   @0x2830a8 ldr r4, [sp], #4
 *   @0x2830ac bx lr
 *
 * ══ §19/828 _spAttachment_deinit  0x284c84  size 48  12 条（0x284c84..0x284cb4）
 * @func 0x284c84 0x284cb4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAttachmentLoader_disposeAttachment / _free
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284c84 push {r4, lr}
 *   @0x284c88 mov r4, r0
 *   @0x284c8c ldr r0, [r0, #0xc]
 *   @0x284c90 cmp r0, #0
 *   @0x284c94 beq 0x284ca0 <_spAttachment_deinit+0x1c>
 *   @0x284c98 mov r1, r4
 *   @0x284c9c bl 0x284dd4 <spAttachmentLoader_disposeAttachment>
 *   @0x284ca0 ldr r0, [r4, #0x8]
 *   @0x284ca4 bl 0x285c80 <_free>
 *   @0x284ca8 ldr r0, [r4]
 *   @0x284cac pop {r4, lr}
 *   @0x284cb0 b 0x285c80 <_free>
 *
 * ══ §20/828 spVertexAttachment_computeWorldVertices  0x28fa08  size 48  12 条（0x28fa08..0x28fa38）
 * @func 0x28fa08 0x28fa48  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spVertexAttachment_computeWorldVertices1
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fa08 str lr, [sp, #-0x4]!
 *   @0x28fa0c sub sp, sp, #12
 *   @0x28fa10 ldr lr, [r0, #0x20]
 *   @0x28fa14 mov r12, #0
 *   @0x28fa18 mov r3, r1
 *   @0x28fa1c str r2, [sp]
 *   @0x28fa20 mov r1, r12
 *   @0x28fa24 str r12, [sp, #0x4]
 *   @0x28fa28 mov r2, lr
 *   @0x28fa2c bl 0x28f64c <spVertexAttachment_computeWorldVertices1>
 *   @0x28fa30 add sp, sp, #12
 *   @0x28fa34 ldr pc, [sp], #4
 *
 * ══ §21/828 png_calculate_crc  0x2a5b08  size 48  12 条（0x2a5b08..0x2a5b38）
 * @func 0x2a5b08 0x2a5b48  size 64  16 条
 * 部分覆盖: 本节 16/28 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 15/26 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5b08 push {r4, lr}
 *   @0x2a5b0c ldrb.w r3, [r0, #0x1e0]
 *   @0x2a5b10 tst.w r3, #0x20
 *   @0x2a5b14 ldr.w r3, [r0, #0x130]
 *   @0x2a5b18 beq 0x2a5b26 <png_calculate_crc+0x1e>
 *   @0x2a5b1c .word 0xf5b37340
 *   @0x2a5b20 .word 0xd1027f40
 *   @0x2a5b24 pop {r4, pc}
 *   @0x2a5b28 bmi 0x2a5b36 <png_calculate_crc+0x2e>
 *   @0x2a5b2c .word 0xf61101d4
 *   @0x2a5b30 .word 0xf8c4e9ba
 *   @0x2a5b34 ldclt p1, c0, [r0, #-848]
 *
 * ══ §22/828 png_data_freer  0x2a5b90  size 48  12 条（0x2a5b90..0x2a5bc0）
 * @func 0x2a5b90 0x2a5bc0  size 48  12 条
 * 部分覆盖: 本节 12/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5b90 cbz r0, 0x2a5bba <png_data_freer+0x2a>
 *   @0x2a5b94 cmp r2, #0x1
 *   @0x2a5b98 ldr.w r2, [r1, #0xb8]
 *   @0x2a5b9c orrs r3, r2
 *   @0x2a5ba0 cmp r2, #0x2
 *   @0x2a5ba4 ldr.w r2, [r1, #0xb8]
 *   @0x2a5ba8 bic.w r3, r2, r3
 *   @0x2a5bac str.w r3, [r1, #0xb8]
 *   @0x2a5bb0 bx lr
 *   @0x2a5bb4 add r1, pc
 *   @0x2a5bb8 .word 0x4770bc5d
 *   @0x2a5bbc str r2, [r5, #0x68]
 *
 * ══ §23/828 png_do_chop  0x2a8d28  size 48  12 条（0x2a8d28..0x2a8d58）
 * @func 0x2a8d28 0x2a8d58  size 48  12 条
 * 部分覆盖: 本节 12/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x9×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8d28 ldrb r3, [r0, #0x9]
 *   @0x2a8d2c cmp r3, #0x10
 *   @0x2a8d30 ldr r3, [r0]
 *   @0x2a8d34 muls r2, r3, r2
 *   @0x2a8d38 cmp r3, r2
 *   @0x2a8d3c ldrb.w r4, [r1, r3, lsl #1]
 *   @0x2a8d40 strb r4, [r1, r3]
 *   @0x2a8d44 b 0x2a8d38 <png_do_chop+0x10>
 *   @0x2a8d48 strb r3, [r0, #0x9]
 *   @0x2a8d4c lsls r2, r3, #0x3
 *   @0x2a8d50 ldr r2, [r0]
 *   @0x2a8d54 str r3, [r0, #0x4]
 *
 * ══ §24/828 b2Fixture::SetSensor(bool)  0x2c89c4  size 48  12 条（0x2c89c4..0x2c89f4）
 * @func 0x2c89c4 0x2c89f4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c89c4 ldrb r3, [r0, #0x2c]
 *   @0x2c89c8 cmp r3, r1
 *   @0x2c89cc bxeq lr
 *   @0x2c89d0 ldr r3, [r0, #0x8]
 *   @0x2c89d4 ldrh r2, [r3, #4]
 *   @0x2c89d8 tst r2, #2
 *   @0x2c89dc orreq r2, r2, #2
 *   @0x2c89e0 strheq r2, [r3, #4]
 *   @0x2c89e4 moveq r12, #0
 *   @0x2c89e8 streq r12, [r3, #0xa0]
 *   @0x2c89ec strb r1, [r0, #0x2c]
 *   @0x2c89f0 bx lr
 *
 * ══ §25/828 b2MouseJoint::SetTarget(b2Vec2 const&)  0x2cf050  size 48  12 条（0x2cf050..0x2cf080）
 * @func 0x2cf050 0x2cf080  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf050 ldr r2, [r0, #0x34]
 *   @0x2cf054 mov r3, r0
 *   @0x2cf058 add r3, r3, #76
 *   @0x2cf05c ldrh r0, [r2, #4]
 *   @0x2cf060 tst r0, #2
 *   @0x2cf064 orreq r0, r0, #2
 *   @0x2cf068 strheq r0, [r2, #4]
 *   @0x2cf06c ldm r1, {r0, r1}
 *   @0x2cf070 moveq r12, #0
 *   @0x2cf074 streq r12, [r2, #0xa0]
 *   @0x2cf078 stm r3, {r0, r1}
 *   @0x2cf07c bx lr
 *
 * ══ §26/828 b2ParticleSystem::GetParticleColorBuffer()  0x2d987c  size 48  12 条（0x2d987c..0x2d98ac）
 * @func 0x2d987c 0x2d98ac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d49b8+0x78
 * 字段偏移 top8: 0x54×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d987c push {r4, lr}
 *   @0x2d9880 mov r4, r0
 *   @0x2d9884 ldr r0, [r0, #0x54]
 *   @0x2d9888 cmp r0, #0
 *   @0x2d988c beq 0x2d9898 <_ZN16b2ParticleSystem22GetParticleColorBufferEv+0x1c>
 *   @0x2d9890 str r0, [r4, #0x54]
 *   @0x2d9894 pop {r4, pc}
 *   @0x2d9898 add r0, r4, #40
 *   @0x2d989c add r1, r4, #212
 *   @0x2d98a0 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0>
 *   @0x2d98a4 str r0, [r4, #0x54]
 *   @0x2d98a8 pop {r4, pc}
 *
 * ══ §27/828 b2VoronoiDiagram::AddGenerator(b2Vec2 const&, int)  0x2dbb94  size 48  12 条（0x2dbb94..0x2dbbc4）
 * @func 0x2dbb94 0x2dbbc4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dbb94 push {r4, r5}
 *   @0x2dbb98 mov r4, r0
 *   @0x2dbb9c ldmib r4, {r5, r12}
 *   @0x2dbba0 ldm r1, {r0, r1}
 *   @0x2dbba4 add r3, r12, #1
 *   @0x2dbba8 add r12, r12, r12, lsl #1
 *   @0x2dbbac str r3, [r4, #0x8]
 *   @0x2dbbb0 add r3, r5, r12, lsl #2
 *   @0x2dbbb4 pop {r4, r5}
 *   @0x2dbbb8 stm r3, {r0, r1}
 *   @0x2dbbbc str r2, [r3, #0x8]
 *   @0x2dbbc0 bx lr
 *
 * ══ §28/828 FT_Get_TrueType_Engine_Type  0x2e5ffc  size 48  12 条（0x2e5ffc..0x2e602c）
 * @func 0x2e5ffc 0x2e602c  size 48  12 条
 * 部分覆盖: 本节 12/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Get_Module
 * 字段偏移 top8: 0x38×2 / 0x1c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5ffc push {r3, lr}
 *   @0x2e6000 movs r0, #0x0
 *   @0x2e6004 ldr r1, [pc, #0x1c]
 *   @0x2e6008 bl 0x2e5ef0 <FT_Get_Module>
 *   @0x2e600c cmp r0, #0x0
 *   @0x2e6010 ldr r1, [pc, #0x14]
 *   @0x2e6014 add r1, pc
 *   @0x2e6018 stmdahs r0, {r1, r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e601c beq 0x2e6000 <FT_Get_TrueType_Engine_Type+0x4>
 *   @0x2e6020 pop {r3, pc}
 *   @0x2e6024 strh r2, [r3, #0x38]
 *   @0x2e6028 strh r5, [r2, #0x38]
 *
 * ══ §29/828 FT_Stream_GetULong  0x2e6a5a  size 48  12 条（0x2e6a5a..0x2e6a8a）
 * @func 0x2e6a5a 0x2e6a9a  size 64  16 条
 * 部分覆盖: 本节 16/29 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 15/27 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x1×1 / 0x-4×1 / 0x-2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6a5a mov r2, r0
 *   @0x2e6a5e ldr r1, [r2, #0x24]
 *   @0x2e6a62 cmp r1, r0
 *   @0x2e6a66 ldrb r0, [r3, #0x1]
 *   @0x2e6a6a ldrb r1, [r3, #-4]
 *   @0x2e6a6e lsls r0, r0, #0x10
 *   @0x2e6a72 .word 0xf8136001
 *   @0x2e6a76 movwmi r1, #0x8c01
 *   @0x2e6a7a ldrb r1, [r3, #-2]
 *   @0x2e6a7e orr.w r0, r0, r1, lsl #8
 *   @0x2e6a82 b 0x2e6a86 <FT_Stream_GetULong+0x2c>
 *   @0x2e6a86 str r3, [r2, #0x20]
 *
 * ══ §30/828 FT_Stream_GetULongLE  0x2e6a8a  size 48  12 条（0x2e6a8a..0x2e6aba）
 * @func 0x2e6a8a 0x2e6aba  size 48  12 条
 * 部分覆盖: 本节 12/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x2×1 / 0x-1×1 / 0x-3×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6a8a mov r2, r0
 *   @0x2e6a8e ldr r1, [r2, #0x24]
 *   @0x2e6a92 cmp r1, r0
 *   @0x2e6a96 ldrb r0, [r3, #0x2]
 *   @0x2e6a9a ldrb r1, [r3, #-1]
 *   @0x2e6a9e lsls r0, r0, #0x10
 *   @0x2e6aa2 .word 0xf8136001
 *   @0x2e6aa6 movwmi r1, #0x8c04
 *   @0x2e6aaa ldrb r1, [r3, #-3]
 *   @0x2e6aae orr.w r0, r0, r1, lsl #8
 *   @0x2e6ab2 b 0x2e6ab6 <FT_Stream_GetULongLE+0x2c>
 *   @0x2e6ab6 str r3, [r2, #0x20]
 *
 * ══ §31/828 FT_New_Memory  0x2e9c44  size 48  12 条（0x2e9c44..0x2e9c74）
 * @func 0x2e9c44 0x2e9c74  size 48  12 条
 * 部分覆盖: 本节 12/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9c44 push {r3, lr}
 *   @0x2e9c48 blx 0xb6544 <malloc@plt>
 *   @0x2e9c4c cbz r0, 0x2e9c64 <FT_New_Memory+0x20>
 *   @0x2e9c50 str r3, [r0]
 *   @0x2e9c54 add r3, pc
 *   @0x2e9c58 ldr r3, [pc, #0x10]
 *   @0x2e9c5c str r3, [r0, #0xc]
 *   @0x2e9c60 add r3, pc
 *   @0x2e9c64 pop {r3, pc}
 *   @0x2e9c68 .word 0xff69 ffff
 *   @0x2e9c6c .word 0xff6f ffff
 *   @0x2e9c70 .word 0xff63 ffff
 *
 * ══ §32/828 png_set_compression_buffer_size  0x2af558  size 46  12 条（0x2af558..0x2af586）
 * @func 0x2af558 0x2af588  size 48  12 条
 * 部分覆盖: 本节 12/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free / png_malloc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af558 push {r3, r4, r5, lr}
 *   @0x2af55c mov r4, r0
 *   @0x2af560 ldr.w r1, [r0, #0x170]
 *   @0x2af564 bl 0x2a6cfc <png_free>
 *   @0x2af568 str.w r5, [r4, #0x174]
 *   @0x2af56c mov r0, r4
 *   @0x2af570 bl 0x2a6ca0 <png_malloc>
 *   @0x2af574 ldr.w r3, [r4, #0x174]
 *   @0x2af578 str.w r3, [r4, #0x148]
 *   @0x2af57c str.w r0, [r4, #0x170]
 *   @0x2af580 str.w r0, [r4, #0x144]
 *   @0x2af584 pop {r3, r4, r5, pc}
 *
 * ══ §33/828 png_do_swap  0x2af8b6  size 46  12 条（0x2af8b6..0x2af8e4）
 * @func 0x2af8b6 0x2af8e6  size 48  12 条
 * 部分覆盖: 本节 12/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xa×1 / 0x-2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af8b6 push {r4, lr}
 *   @0x2af8ba cmp r3, #0x10
 *   @0x2af8be ldrb r3, [r0, #0xa]
 *   @0x2af8c2 muls r2, r3, r2
 *   @0x2af8c6 cmp r3, r2
 *   @0x2af8ca andle r0, r9, r2, lsl #2
 *   @0x2af8ce ldrb r0, [r1, #-2]
 *   @0x2af8d2 adds r3, #0x1
 *   @0x2af8d6 .word 0xf8014c01
 *   @0x2af8da .word 0xf8010c01
 *   @0x2af8de ldrb r4, [r1, r2, lsl #24]!
 *   @0x2af8e2 pop {r4, pc}
 *
 * ══ §34/828 FT_Outline_Translate  0x2e6424  size 46  12 条（0x2e6424..0x2e6452）
 * @func 0x2e6424 0x2e6454  size 48  12 条
 * 部分覆盖: 本节 12/23 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6424 push {r4, r5, lr}
 *   @0x2e6428 ldr r3, [r0, #0x4]
 *   @0x2e642c ldrsh.w r5, [r0, #0x2]
 *   @0x2e6430 adds r3, #0x8
 *   @0x2e6434 bge 0x2e6450 <FT_Outline_Translate+0x2c>
 *   @0x2e6438 strlo r5, [r1], #-3080
 *   @0x2e643c add r5, r1
 *   @0x2e6440 .word 0xf8535c08
 *   @0x2e6444 adclt r5, r4, #4, #24
 *   @0x2e6448 add r5, r2
 *   @0x2e644c strb r5, [sp, r4, lsl #24]!
 *   @0x2e6450 pop {r4, r5, pc}
 *
 * ══ §35/828 CSkeletonSprite::SimpleDecode(unsigned char*, int)  0xbd840  size 44  11 条（0xbd840..0xbd86c）
 * @func 0xbd840 0xbd86c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd840 cmp r2, #0
 *   @0xbd844 bxle lr
 *   @0xbd848 add r0, r1, r2
 *   @0xbd84c mov r3, #42
 *   @0xbd850 ldrb r2, [r1]
 *   @0xbd854 rsb r2, r3, r2
 *   @0xbd858 strb r2, [r1], #1
 *   @0xbd85c cmp r1, r0
 *   @0xbd860 mla r3, r3, r3, r3
 *   @0xbd864 bne 0xbd850 <_ZN15CSkeletonSprite12SimpleDecodeEPhi+0x10>
 *   @0xbd868 bx lr
 *
 * ══ §36/828 CBackground::InitTexture()  0xc1e60  size 44  11 条（0xc1e60..0xc1e8c）
 * @func 0xc1e60 0xc1e8c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::FreeTexture() / GR_Texture_Create_Direct(CBitmap32*)
 * 字段偏移 top8: 0x10×1 / 0xa×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1e60 push {r4, lr}
 *   @0xc1e64 mov r4, r0
 *   @0xc1e68 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv>
 *   @0xc1e6c ldr r0, [r4, #0x10]
 *   @0xc1e70 bl 0x173e70 <_Z24GR_Texture_Create_DirectP9CBitmap32>
 *   @0xc1e74 ldrb r3, [r4, #0xa]
 *   @0xc1e78 cmp r3, #0
 *   @0xc1e7c str r0, [r4, #0xc]
 *   @0xc1e80 popeq {r4, pc}
 *   @0xc1e84 pop {r4, lr}
 *   @0xc1e88 b 0x174288 <_Z18GR_Texture_Preloadi>
 *
 * ══ §37/828 WaitForGCThread()  0xd3e94  size 44  11 条（0xd3e94..0xd3ec0）
 * @func 0xd3e94 0xd3ed0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WaitForGCThread()+0x10
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3e94 ldr r0, [pc, #0x1c]
 *   @0xd3e98 ldr r1, [pc, #0x1c]
 *   @0xd3e9c ldr r0, [pc, r0]
 *   @0xd3ea0 ldr r1, [pc, r1]
 *   @0xd3ea4 ldr r2, [r0]
 *   @0xd3ea8 ldr r3, [r1]
 *   @0xd3eac cmp r2, r3
 *   @0xd3eb0 blt 0xd3ea4 <_Z15WaitForGCThreadv+0x10>
 *   @0xd3eb4 bx lr
 *   @0xd3eb8 eorseq r9, r1, r0, lsr sp
 *   @0xd3ebc eorseq r9, r1, r0, lsr sp
 *
 * ══ §38/828 VM::GetRuntimeStateRealtime(Buffer_Standard*, int)  0xd8dc8  size 44  11 条（0xd8dc8..0xd8df4）
 * @func 0xd8dc8 0xd8df4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::GetGlobalVariables(Buffer_Standard*, bool) / VM::GetStructureCounts(Buffer_Standard*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8dc8 push {r3, r4, r5, lr}
 *   @0xd8dcc mov r4, r0
 *   @0xd8dd0 mov r5, r1
 *   @0xd8dd4 ubfx r1, r1, #0x3, #0x1
 *   @0xd8dd8 bl 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb>
 *   @0xd8ddc mov r0, r4
 *   @0xd8de0 bl 0xd890c <_ZN2VM18GetStructureCountsEP15Buffer_Standard>
 *   @0xd8de4 mov r0, r4
 *   @0xd8de8 and r1, r5, #1
 *   @0xd8dec pop {r3, r4, r5, lr}
 *   @0xd8df0 b 0xd87ac <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb>
 *
 * ══ §39/828 CExtensionConstant::Setname(char const*)  0xf4914  size 44  11 条（0xf4914..0xf4940）
 * @func 0xf4914 0xf4940  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4914 push {r3, r4, r5, lr}
 *   @0xf4918 mov r4, r0
 *   @0xf491c ldr r0, [r0, #0x4]
 *   @0xf4920 mov r5, r1
 *   @0xf4924 cmp r0, #0
 *   @0xf4928 beq 0xf4930 <_ZN18CExtensionConstant7SetnameEPKc+0x1c>
 *   @0xf492c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4930 mov r0, r5
 *   @0xf4934 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4938 str r0, [r4, #0x4]
 *   @0xf493c pop {r3, r4, r5, pc}
 *
 * ══ §40/828 CExtensionConstant::SetValue(char const*)  0xf4948  size 44  11 条（0xf4948..0xf4974）
 * @func 0xf4948 0xf4974  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4948 push {r3, r4, r5, lr}
 *   @0xf494c mov r4, r0
 *   @0xf4950 ldr r0, [r0, #0x8]
 *   @0xf4954 mov r5, r1
 *   @0xf4958 cmp r0, #0
 *   @0xf495c beq 0xf4964 <_ZN18CExtensionConstant8SetValueEPKc+0x1c>
 *   @0xf4960 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4964 mov r0, r5
 *   @0xf4968 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf496c str r0, [r4, #0x8]
 *   @0xf4970 pop {r3, r4, r5, pc}
 *
 * ══ §41/828 CExtensionFunction::SetName(char const*)  0xf4bb8  size 44  11 条（0xf4bb8..0xf4be4）
 * @func 0xf4bb8 0xf4be4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4bb8 push {r3, r4, r5, lr}
 *   @0xf4bbc mov r4, r0
 *   @0xf4bc0 ldr r0, [r0, #0x4]
 *   @0xf4bc4 mov r5, r1
 *   @0xf4bc8 cmp r0, #0
 *   @0xf4bcc beq 0xf4bd4 <_ZN18CExtensionFunction7SetNameEPKc+0x1c>
 *   @0xf4bd0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4bd4 mov r0, r5
 *   @0xf4bd8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4bdc str r0, [r4, #0x4]
 *   @0xf4be0 pop {r3, r4, r5, pc}
 *
 * ══ §42/828 CExtensionFunction::SetExternalName(char const*)  0xf4bec  size 44  11 条（0xf4bec..0xf4c18）
 * @func 0xf4bec 0xf4c18  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4bec push {r3, r4, r5, lr}
 *   @0xf4bf0 mov r4, r0
 *   @0xf4bf4 ldr r0, [r0, #0x8]
 *   @0xf4bf8 mov r5, r1
 *   @0xf4bfc cmp r0, #0
 *   @0xf4c00 beq 0xf4c08 <_ZN18CExtensionFunction15SetExternalNameEPKc+0x1c>
 *   @0xf4c04 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4c08 mov r0, r5
 *   @0xf4c0c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4c10 str r0, [r4, #0x8]
 *   @0xf4c14 pop {r3, r4, r5, pc}
 *
 * ══ §43/828 CExtensionFunction::SetScript(char const*)  0xf4c60  size 44  11 条（0xf4c60..0xf4c8c）
 * @func 0xf4c60 0xf4c9c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x5c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c60 push {r3, r4, r5, lr}
 *   @0xf4c64 mov r4, r0
 *   @0xf4c68 ldr r0, [r0, #0x5c]
 *   @0xf4c6c mov r5, r1
 *   @0xf4c70 cmp r0, #0
 *   @0xf4c74 beq 0xf4c7c <_ZN18CExtensionFunction9SetScriptEPKc+0x1c>
 *   @0xf4c78 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4c7c mov r0, r5
 *   @0xf4c80 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4c84 str r0, [r4, #0x5c]
 *   @0xf4c88 pop {r3, r4, r5, pc}
 *
 * ══ §44/828 CExtensionFile::SetFileName(char const*)  0xf4fb4  size 44  11 条（0xf4fb4..0xf4fe0）
 * @func 0xf4fb4 0xf4fe0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4fb4 push {r3, r4, r5, lr}
 *   @0xf4fb8 mov r4, r0
 *   @0xf4fbc ldr r0, [r0, #0x4]
 *   @0xf4fc0 mov r5, r1
 *   @0xf4fc4 cmp r0, #0
 *   @0xf4fc8 beq 0xf4fd0 <_ZN14CExtensionFile11SetFileNameEPKc+0x1c>
 *   @0xf4fcc bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4fd0 mov r0, r5
 *   @0xf4fd4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4fd8 str r0, [r4, #0x4]
 *   @0xf4fdc pop {r3, r4, r5, pc}
 *
 * ══ §45/828 CExtensionFile::SetFunction_Final(char const*)  0xf5018  size 44  11 条（0xf5018..0xf5044）
 * @func 0xf5018 0xf5044  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5018 push {r3, r4, r5, lr}
 *   @0xf501c mov r4, r0
 *   @0xf5020 ldr r0, [r0, #0x10]
 *   @0xf5024 mov r5, r1
 *   @0xf5028 cmp r0, #0
 *   @0xf502c beq 0xf5034 <_ZN14CExtensionFile17SetFunction_FinalEPKc+0x1c>
 *   @0xf5030 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf5034 mov r0, r5
 *   @0xf5038 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf503c str r0, [r4, #0x10]
 *   @0xf5040 pop {r3, r4, r5, pc}
 *
 * ══ §46/828 CExtensionPackage::SetName(char const*)  0xf559c  size 44  11 条（0xf559c..0xf55c8）
 * @func 0xf559c 0xf55c8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf559c push {r3, r4, r5, lr}
 *   @0xf55a0 mov r4, r0
 *   @0xf55a4 ldr r0, [r0, #0x4]
 *   @0xf55a8 mov r5, r1
 *   @0xf55ac cmp r0, #0
 *   @0xf55b0 beq 0xf55b8 <_ZN17CExtensionPackage7SetNameEPKc+0x1c>
 *   @0xf55b4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf55b8 mov r0, r5
 *   @0xf55bc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf55c0 str r0, [r4, #0x4]
 *   @0xf55c4 pop {r3, r4, r5, pc}
 *
 * ══ §47/828 CExtensionPackage::SetClassName(char const*)  0xf55d0  size 44  11 条（0xf55d0..0xf55fc）
 * @func 0xf55d0 0xf55fc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf55d0 push {r3, r4, r5, lr}
 *   @0xf55d4 mov r4, r0
 *   @0xf55d8 ldr r0, [r0, #0xc]
 *   @0xf55dc mov r5, r1
 *   @0xf55e0 cmp r0, #0
 *   @0xf55e4 beq 0xf55ec <_ZN17CExtensionPackage12SetClassNameEPKc+0x1c>
 *   @0xf55e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf55ec mov r0, r5
 *   @0xf55f0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf55f4 str r0, [r4, #0xc]
 *   @0xf55f8 pop {r3, r4, r5, pc}
 *
 * ══ §48/828 CExtensionPackage::SetFolder(char const*)  0xf5604  size 44  11 条（0xf5604..0xf5630）
 * @func 0xf5604 0xf5630  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5604 push {r3, r4, r5, lr}
 *   @0xf5608 mov r4, r0
 *   @0xf560c ldr r0, [r0, #0x8]
 *   @0xf5610 mov r5, r1
 *   @0xf5614 cmp r0, #0
 *   @0xf5618 beq 0xf5620 <_ZN17CExtensionPackage9SetFolderEPKc+0x1c>
 *   @0xf561c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf5620 mov r0, r5
 *   @0xf5624 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5628 str r0, [r4, #0x8]
 *   @0xf562c pop {r3, r4, r5, pc}
 *
 * ══ §49/828 Extension_Init()  0xf5808  size 44  11 条（0xf5808..0xf5834）
 * @func 0xf5808 0xf5834  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5808 ldr r2, [pc, #0x1c]
 *   @0xf580c mov r3, #0
 *   @0xf5810 ldr r1, [pc, #0x18]
 *   @0xf5814 ldr r2, [pc, r2]
 *   @0xf5818 add r1, pc, r1
 *   @0xf581c str r3, [r2]
 *   @0xf5820 str r3, [r1, #0x4]
 *   @0xf5824 str r3, [r1]
 *   @0xf5828 bx lr
 *   @0xf582c eoreq r8, pc, r0, lsr #12
 *   @0xf5830 eorseq sp, r8, r0, lsr lr
 *
 * ══ §50/828 anon_f6898  0xf6898  size 44  11 条（0xf6898..0xf68c4）
 * @func 0xf6898 0xf68c4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6898 ldr r3, [r0]
 *   @0xf689c ldr r2, [r1]
 *   @0xf68a0 ldrh r0, [r3]
 *   @0xf68a4 ldrh r3, [r2]
 *   @0xf68a8 rsb r0, r3, r0
 *   @0xf68ac bx lr
 *   @0xf68b0 ldr r3, [r0]
 *   @0xf68b4 ldr r2, [r1]
 *   @0xf68b8 ldrh r0, [r3]
 *   @0xf68bc ldrh r3, [r2]
 *   @0xf68c0 rsb r0, r3, r0
 *
 * ══ §51/828 CFontGM::CFont_LoadFromStream(void*, void*)  0xf94a0  size 44  11 条（0xf94a0..0xf94cc）
 * @func 0xf94a0 0xf94cc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::LoadFromStream(CStream*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf94a0 subs r2, r0, #0
 *   @0xf94a4 push {r3, lr}
 *   @0xf94a8 beq 0xf94c4 <_ZN7CFontGM20CFont_LoadFromStreamEPvS0_+0x24>
 *   @0xf94ac cmp r1, #0
 *   @0xf94b0 beq 0xf94bc <_ZN7CFontGM20CFont_LoadFromStreamEPvS0_+0x1c>
 *   @0xf94b4 bl 0xf79a0 <_ZN7CFontGM14LoadFromStreamEP7CStream>
 *   @0xf94b8 pop {r3, pc}
 *   @0xf94bc mov r0, r1
 *   @0xf94c0 pop {r3, pc}
 *   @0xf94c4 mov r0, r2
 *   @0xf94c8 pop {r3, pc}
 *
 * ══ §52/828 F_InstanceIdGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x10999c  size 44  11 条（0x10999c..0x1099c8）
 * @func 0x10999c 0x1099c8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10999c push {r3, r4, r5, lr}
 *   @0x1099a0 mov r4, r0
 *   @0x1099a4 mov r5, r1
 *   @0x1099a8 ldr r0, [sp, #0x10]
 *   @0x1099ac mov r1, #0
 *   @0x1099b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1099b4 mov r2, r4
 *   @0x1099b8 mov r1, r0
 *   @0x1099bc mov r0, r5
 *   @0x1099c0 pop {r3, r4, r5, lr}
 *   @0x1099c4 b 0x1fb0a8 <_Z13GV_InstanceIdP9CInstanceiP6RValue>
 *
 * ══ §53/828 F_RandomGetSeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dc10  size 44  11 条（0x10dc10..0x10dc3c）
 * @func 0x10dc10 0x10dc3c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dc10 ldr r3, [pc, #0x20]
 *   @0x10dc14 mov r2, #0
 *   @0x10dc18 str r2, [r0, #0xc]
 *   @0x10dc1c ldr r3, [pc, r3]
 *   @0x10dc20 ldr r2, [r3]
 *   @0x10dc24 vmov s15, r2
 *   @0x10dc28 vcvt.f64.u32 d7, s15
 *   @0x10dc2c vmov r2, r3, d7
 *   @0x10dc30 stm r0, {r2, r3}
 *   @0x10dc34 bx lr
 *   @0x10dc38 eoreq pc, sp, r12, asr #26
 *
 * ══ §54/828 F_RandomSetSeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e220  size 44  11 条（0x10e220..0x10e24c）
 * @func 0x10e220 0x10e24c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e220 push {r3, lr}
 *   @0x10e224 mov r3, #0
 *   @0x10e228 ldr r12, [sp, #0x8]
 *   @0x10e22c mov r1, r3
 *   @0x10e230 str r3, [r0, #0xc]
 *   @0x10e234 str r3, [r0]
 *   @0x10e238 str r3, [r0, #0x4]
 *   @0x10e23c mov r0, r12
 *   @0x10e240 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x10e244 pop {r3, lr}
 *   @0x10e248 b 0xc4438 <_Z10InitRandomj>
 *
 * ══ §55/828 F_ExternalCall0(RValue&, CInstance*, CInstance*, int, RValue*)  0x114a48  size 44  11 条（0x114a48..0x114a74）
 * @func 0x114a48 0x114a84  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114a48 push {r4, r5, r6, lr}
 *   @0x114a4c mov r1, #0
 *   @0x114a50 ldr r4, [sp, #0x10]
 *   @0x114a54 mov r5, r0
 *   @0x114a58 mov r0, r4
 *   @0x114a5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114a60 mov r2, r4
 *   @0x114a64 mov r3, r5
 *   @0x114a68 mov r1, #0
 *   @0x114a6c pop {r4, r5, r6, lr}
 *   @0x114a70 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §56/828 F_ExternalCall1(RValue&, CInstance*, CInstance*, int, RValue*)  0x114a74  size 44  11 条（0x114a74..0x114aa0）
 * @func 0x114a74 0x114ab0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114a74 push {r4, r5, r6, lr}
 *   @0x114a78 mov r1, #0
 *   @0x114a7c ldr r4, [sp, #0x10]
 *   @0x114a80 mov r5, r0
 *   @0x114a84 mov r0, r4
 *   @0x114a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114a8c add r2, r4, #16
 *   @0x114a90 mov r3, r5
 *   @0x114a94 mov r1, #1
 *   @0x114a98 pop {r4, r5, r6, lr}
 *   @0x114a9c b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §57/828 F_ExternalCall2(RValue&, CInstance*, CInstance*, int, RValue*)  0x114aa0  size 44  11 条（0x114aa0..0x114acc）
 * @func 0x114aa0 0x114adc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114aa0 push {r4, r5, r6, lr}
 *   @0x114aa4 mov r1, #0
 *   @0x114aa8 ldr r4, [sp, #0x10]
 *   @0x114aac mov r5, r0
 *   @0x114ab0 mov r0, r4
 *   @0x114ab4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114ab8 add r2, r4, #16
 *   @0x114abc mov r3, r5
 *   @0x114ac0 mov r1, #2
 *   @0x114ac4 pop {r4, r5, r6, lr}
 *   @0x114ac8 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §58/828 F_ExternalCall3(RValue&, CInstance*, CInstance*, int, RValue*)  0x114acc  size 44  11 条（0x114acc..0x114af8）
 * @func 0x114acc 0x114b08  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114acc push {r4, r5, r6, lr}
 *   @0x114ad0 mov r1, #0
 *   @0x114ad4 ldr r4, [sp, #0x10]
 *   @0x114ad8 mov r5, r0
 *   @0x114adc mov r0, r4
 *   @0x114ae0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114ae4 add r2, r4, #16
 *   @0x114ae8 mov r3, r5
 *   @0x114aec mov r1, #3
 *   @0x114af0 pop {r4, r5, r6, lr}
 *   @0x114af4 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §59/828 F_ExternalCall4(RValue&, CInstance*, CInstance*, int, RValue*)  0x114af8  size 44  11 条（0x114af8..0x114b24）
 * @func 0x114af8 0x114b34  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114af8 push {r4, r5, r6, lr}
 *   @0x114afc mov r1, #0
 *   @0x114b00 ldr r4, [sp, #0x10]
 *   @0x114b04 mov r5, r0
 *   @0x114b08 mov r0, r4
 *   @0x114b0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114b10 add r2, r4, #16
 *   @0x114b14 mov r3, r5
 *   @0x114b18 mov r1, #4
 *   @0x114b1c pop {r4, r5, r6, lr}
 *   @0x114b20 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §60/828 F_ExternalCall5(RValue&, CInstance*, CInstance*, int, RValue*)  0x114b24  size 44  11 条（0x114b24..0x114b50）
 * @func 0x114b24 0x114b60  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114b24 push {r4, r5, r6, lr}
 *   @0x114b28 mov r1, #0
 *   @0x114b2c ldr r4, [sp, #0x10]
 *   @0x114b30 mov r5, r0
 *   @0x114b34 mov r0, r4
 *   @0x114b38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114b3c add r2, r4, #16
 *   @0x114b40 mov r3, r5
 *   @0x114b44 mov r1, #5
 *   @0x114b48 pop {r4, r5, r6, lr}
 *   @0x114b4c b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §61/828 F_ExternalCall6(RValue&, CInstance*, CInstance*, int, RValue*)  0x114b50  size 44  11 条（0x114b50..0x114b7c）
 * @func 0x114b50 0x114b8c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114b50 push {r4, r5, r6, lr}
 *   @0x114b54 mov r1, #0
 *   @0x114b58 ldr r4, [sp, #0x10]
 *   @0x114b5c mov r5, r0
 *   @0x114b60 mov r0, r4
 *   @0x114b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114b68 add r2, r4, #16
 *   @0x114b6c mov r3, r5
 *   @0x114b70 mov r1, #6
 *   @0x114b74 pop {r4, r5, r6, lr}
 *   @0x114b78 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §62/828 F_ExternalCall7(RValue&, CInstance*, CInstance*, int, RValue*)  0x114b7c  size 44  11 条（0x114b7c..0x114ba8）
 * @func 0x114b7c 0x114bb8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114b7c push {r4, r5, r6, lr}
 *   @0x114b80 mov r1, #0
 *   @0x114b84 ldr r4, [sp, #0x10]
 *   @0x114b88 mov r5, r0
 *   @0x114b8c mov r0, r4
 *   @0x114b90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114b94 add r2, r4, #16
 *   @0x114b98 mov r3, r5
 *   @0x114b9c mov r1, #7
 *   @0x114ba0 pop {r4, r5, r6, lr}
 *   @0x114ba4 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §63/828 F_ExternalCall8(RValue&, CInstance*, CInstance*, int, RValue*)  0x114ba8  size 44  11 条（0x114ba8..0x114bd4）
 * @func 0x114ba8 0x114be4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114ba8 push {r4, r5, r6, lr}
 *   @0x114bac mov r1, #0
 *   @0x114bb0 ldr r4, [sp, #0x10]
 *   @0x114bb4 mov r5, r0
 *   @0x114bb8 mov r0, r4
 *   @0x114bbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114bc0 add r2, r4, #16
 *   @0x114bc4 mov r3, r5
 *   @0x114bc8 mov r1, #8
 *   @0x114bcc pop {r4, r5, r6, lr}
 *   @0x114bd0 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *
 * ══ §64/828 F_DisplayGetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*)  0x119a68  size 44  11 条（0x119a68..0x119a94）
 * @func 0x119a68 0x119aa4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119a68 ldr r3, [pc, #0x20]
 *   @0x119a6c mov r2, #0
 *   @0x119a70 str r2, [r0, #0xc]
 *   @0x119a74 ldr r3, [pc, r3]
 *   @0x119a78 ldr r2, [r3]
 *   @0x119a7c vmov s15, r2
 *   @0x119a80 vcvt.f64.u32 d7, s15
 *   @0x119a84 vmov r2, r3, d7
 *   @0x119a88 stm r0, {r2, r3}
 *   @0x119a8c bx lr
 *   @0x119a90 eoreq r4, sp, r0, asr #22
 *
 * ══ §65/828 F_DrawGetColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a9f4  size 44  11 条（0x11a9f4..0x11aa20）
 * @func 0x11a9f4 0x11aa20  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Get_Color()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a9f4 push {r4, lr}
 *   @0x11a9f8 mov r3, #0
 *   @0x11a9fc str r3, [r0, #0xc]
 *   @0x11aa00 mov r4, r0
 *   @0x11aa04 bl 0x169ecc <_Z17GR_Draw_Get_Colorv>
 *   @0x11aa08 bic r0, r0, #-16777216
 *   @0x11aa0c vmov s15, r0
 *   @0x11aa10 vcvt.f64.s32 d7, s15
 *   @0x11aa14 vmov r2, r3, d7
 *   @0x11aa18 stm r4, {r2, r3}
 *   @0x11aa1c pop {r4, pc}
 *
 * ══ §66/828 F_HighscoreAddCurrent(RValue&, CInstance*, CInstance*, int, RValue*)  0x1268c4  size 44  11 条（0x1268c4..0x1268f0）
 * @func 0x1268c4 0x1268f0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HighScore_Add(char const*, int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1268c4 push {r3, lr}
 *   @0x1268c8 ldr r3, [pc, #0x18]
 *   @0x1268cc ldr r0, [pc, #0x18]
 *   @0x1268d0 ldr r3, [pc, r3]
 *   @0x1268d4 add r0, pc, r0
 *   @0x1268d8 ldr r1, [r3]
 *   @0x1268dc bl 0x1dc318 <_Z13HighScore_AddPKci>
 *   @0x1268e0 pop {r3, lr}
 *   @0x1268e4 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1268e8 .word 0x002c81b4
 *   @0x1268ec .word 0x002159b8
 *
 * ══ §67/828 F_FontGetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a9d4  size 44  11 条（0x12a9d4..0x12aa00）
 * @func 0x12a9d4 0x12aa00  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a9d4 ldr r3, [pc, #0x20]
 *   @0x12a9d8 mov r2, #0
 *   @0x12a9dc str r2, [r0, #0xc]
 *   @0x12a9e0 ldr r3, [pc, r3]
 *   @0x12a9e4 ldr r2, [r3]
 *   @0x12a9e8 vmov s15, r2
 *   @0x12a9ec vcvt.f64.s32 d7, s15
 *   @0x12a9f0 vmov r2, r3, d7
 *   @0x12a9f4 stm r0, {r2, r3}
 *   @0x12a9f8 bx lr
 *   @0x12a9fc eoreq r3, r12, r4, ror r4
 *
 * ══ §68/828 F_AudioReleaseEmitter(RValue&, CInstance*, CInstance*, int, RValue*)  0x134a28  size 44  11 条（0x134a28..0x134a54）
 * @func 0x134a28 0x134a54  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134a28 push {r3, lr}
 *   @0x134a2c ldr r3, [pc, #0x1c]
 *   @0x134a30 ldr r0, [sp, #0x8]
 *   @0x134a34 ldr r3, [pc, r3]
 *   @0x134a38 ldrb r1, [r3]
 *   @0x134a3c cmp r1, #0
 *   @0x134a40 popne {r3, pc}
 *   @0x134a44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134a48 pop {r3, lr}
 *   @0x134a4c b 0x21a2f8 <_Z20Audio_ReleaseEmitteri>
 *   @0x134a50 eoreq r10, r11, r8, lsl r6
 *
 * ══ §69/828 F_Audio_SetFalloff(RValue&, CInstance*, CInstance*, int, RValue*)  0x134be8  size 44  11 条（0x134be8..0x134c14）
 * @func 0x134be8 0x134c14  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134be8 push {r3, lr}
 *   @0x134bec ldr r3, [pc, #0x1c]
 *   @0x134bf0 ldr r0, [sp, #0x8]
 *   @0x134bf4 ldr r3, [pc, r3]
 *   @0x134bf8 ldrb r1, [r3]
 *   @0x134bfc cmp r1, #0
 *   @0x134c00 popne {r3, pc}
 *   @0x134c04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134c08 pop {r3, lr}
 *   @0x134c0c b 0x217a80 <_Z16Audio_FalloffSeti>
 *   @0x134c10 eoreq r10, r11, r8, asr r4
 *
 * ══ §70/828 F_AudioPauseSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x134e04  size 44  11 条（0x134e04..0x134e30）
 * @func 0x134e04 0x134e30  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134e04 push {r3, lr}
 *   @0x134e08 ldr r3, [pc, #0x1c]
 *   @0x134e0c ldr r0, [sp, #0x8]
 *   @0x134e10 ldr r3, [pc, r3]
 *   @0x134e14 ldrb r1, [r3]
 *   @0x134e18 cmp r1, #0
 *   @0x134e1c popne {r3, pc}
 *   @0x134e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134e24 pop {r3, lr}
 *   @0x134e28 b 0x217f6c <_Z16Audio_PauseSoundi>
 *   @0x134e2c eoreq r10, r11, r12, lsr r2
 *
 * ══ §71/828 F_AudioResumeSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x134fbc  size 44  11 条（0x134fbc..0x134fe8）
 * @func 0x134fbc 0x134fe8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134fbc push {r3, lr}
 *   @0x134fc0 ldr r3, [pc, #0x1c]
 *   @0x134fc4 ldr r0, [sp, #0x8]
 *   @0x134fc8 ldr r3, [pc, r3]
 *   @0x134fcc ldrb r1, [r3]
 *   @0x134fd0 cmp r1, #0
 *   @0x134fd4 popne {r3, pc}
 *   @0x134fd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134fdc pop {r3, lr}
 *   @0x134fe0 b 0x217e9c <_Z17Audio_ResumeSoundi>
 *   @0x134fe4 eoreq r10, r11, r4, lsl #1
 *
 * ══ §72/828 F_AudioSetNumChannels(RValue&, CInstance*, CInstance*, int, RValue*)  0x13518c  size 44  11 条（0x13518c..0x1351b8）
 * @func 0x13518c 0x1351b8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13518c push {r3, lr}
 *   @0x135190 ldr r3, [pc, #0x1c]
 *   @0x135194 ldr r0, [sp, #0x8]
 *   @0x135198 ldr r3, [pc, r3]
 *   @0x13519c ldrb r1, [r3]
 *   @0x1351a0 cmp r1, #0
 *   @0x1351a4 popne {r3, pc}
 *   @0x1351a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1351ac pop {r3, lr}
 *   @0x1351b0 b 0x21a454 <_Z20Audio_SetNumChannelsi>
 *   @0x1351b4 .word 0x002b9eb4
 *
 * ══ §73/828 F_Audio_GroupStopAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x135928  size 44  11 条（0x135928..0x135954）
 * @func 0x135928 0x135954  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135928 push {r3, lr}
 *   @0x13592c ldr r3, [pc, #0x1c]
 *   @0x135930 ldr r0, [sp, #0x8]
 *   @0x135934 ldr r3, [pc, r3]
 *   @0x135938 ldrb r1, [r3]
 *   @0x13593c cmp r1, #0
 *   @0x135940 popne {r3, pc}
 *   @0x135944 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135948 pop {r3, lr}
 *   @0x13594c b 0x21ad0c <_Z18Audio_StopAllGroupi>
 *   @0x135950 eoreq r9, r11, r8, lsl r7
 *
 * ══ §74/828 F_AudioSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x135e60  size 44  11 条（0x135e60..0x135e8c）
 * @func 0x135e60 0x135e8c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135e60 push {r3, lr}
 *   @0x135e64 ldr r3, [pc, #0x1c]
 *   @0x135e68 ldr r0, [sp, #0x8]
 *   @0x135e6c ldr r3, [pc, r3]
 *   @0x135e70 ldrb r1, [r3]
 *   @0x135e74 cmp r1, #0
 *   @0x135e78 popne {r3, pc}
 *   @0x135e7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135e80 pop {r3, lr}
 *   @0x135e84 b 0x218590 <_Z21Audio_SetListenerMaskj>
 *   @0x135e88 eoreq r9, r11, r0, ror #3
 *
 * ══ §75/828 F_ActionPartSystDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f95c  size 44  11 条（0x13f95c..0x13f988）
 * @func 0x13f95c 0x13f998  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_ActionPartSystDestroy(RValue&, CInstance*, CInstance*, int, RValue*)+0x1c / ParticleSystem_Destroy(int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f95c push {r4, lr}
 *   @0x13f960 ldr r4, [pc, #0x1c]
 *   @0x13f964 ldr r4, [pc, r4]
 *   @0x13f968 ldr r0, [r4]
 *   @0x13f96c cmp r0, #0
 *   @0x13f970 blt 0x13f978 <_Z23F_ActionPartSystDestroyR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x13f974 bl 0x1a454c <_Z22ParticleSystem_Destroyi>
 *   @0x13f978 mvn r3, #0
 *   @0x13f97c str r3, [r4]
 *   @0x13f980 pop {r4, pc}
 *   @0x13f984 eoreq pc, r10, r8, ror r10
 *
 * ══ §76/828 F_ActionFont(RValue&, CInstance*, CInstance*, int, RValue*)  0x1409c8  size 44  11 条（0x1409c8..0x1409f4）
 * @func 0x1409c8 0x1409f4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GR_Text_Set_Font(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1409c8 push {r4, lr}
 *   @0x1409cc mov r1, #0
 *   @0x1409d0 ldr r4, [sp, #0x8]
 *   @0x1409d4 mov r0, r4
 *   @0x1409d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1409dc bl 0x172ac8 <_Z16GR_Text_Set_Fonti>
 *   @0x1409e0 mov r0, r4
 *   @0x1409e4 mov r1, #1
 *   @0x1409e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1409ec pop {r4, lr}
 *   @0x1409f0 b 0x172b30 <_Z18GR_Text_Set_HAligni>
 *
 * ══ §77/828 F_D3DLightGetAmbient(RValue&, CInstance*, CInstance*, int, RValue*)  0x143a18  size 44  11 条（0x143a18..0x143a44）
 * @func 0x143a18 0x143a44  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143a18 ldr r3, [pc, #0x20]
 *   @0x143a1c mov r2, #0
 *   @0x143a20 str r2, [r0, #0xc]
 *   @0x143a24 ldr r3, [pc, r3]
 *   @0x143a28 ldr r2, [r3]
 *   @0x143a2c vmov s15, r2
 *   @0x143a30 vcvt.f64.u32 d7, s15
 *   @0x143a34 vmov r2, r3, d7
 *   @0x143a38 stm r0, {r2, r3}
 *   @0x143a3c bx lr
 *   @0x143a40 eoreq r11, r10, r8, ror #23
 *
 * ══ §78/828 F_YoYo_EnableAlphaBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x143a78  size 44  11 条（0x143a78..0x143aa4）
 * @func 0x143a78 0x143aa4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143a78 push {r3, lr}
 *   @0x143a7c mov r1, #0
 *   @0x143a80 ldr r0, [sp, #0x8]
 *   @0x143a84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143a88 ldr r3, [pc, #0x10]
 *   @0x143a8c mov r1, #12
 *   @0x143a90 mov r2, r0
 *   @0x143a94 ldr r0, [pc, r3]
 *   @0x143a98 pop {r3, lr}
 *   @0x143a9c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x143aa0 eoreq r10, r10, r4, ror #4
 *
 * ══ §79/828 F_PhysicsCreateFixture(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bab0  size 44  11 条（0x14bab0..0x14badc）
 * @func 0x14bab0 0x14badc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixtureFactory::CreateFixture()
 * 字段偏移 top8: 0xc×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bab0 push {r4, lr}
 *   @0x14bab4 mov r4, r0
 *   @0x14bab8 bl 0x2364d4 <_ZN22CPhysicsFixtureFactory13CreateFixtureEv>
 *   @0x14babc mov r3, #0
 *   @0x14bac0 str r3, [r4, #0xc]
 *   @0x14bac4 ldr r2, [r0, #0x1c]
 *   @0x14bac8 vmov s15, r2
 *   @0x14bacc vcvt.f64.u32 d7, s15
 *   @0x14bad0 vmov r2, r3, d7
 *   @0x14bad4 stm r4, {r2, r3}
 *   @0x14bad8 pop {r4, pc}
 *
 * ══ §80/828 F_GamepadGetDeviceCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x151210  size 44  11 条（0x151210..0x15123c）
 * @func 0x151210 0x15123c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151210 ldr r3, [pc, #0x20]
 *   @0x151214 mov r2, #0
 *   @0x151218 str r2, [r0, #0xc]
 *   @0x15121c ldr r3, [pc, r3]
 *   @0x151220 ldr r2, [r3]
 *   @0x151224 vmov s15, r2
 *   @0x151228 vcvt.f64.s32 d7, s15
 *   @0x15122c vmov r2, r3, d7
 *   @0x151230 stm r0, {r2, r3}
 *   @0x151234 bx lr
 *   @0x151238 eoreq lr, r9, r4, asr #16
 *
 * ══ §81/828 F_IAP_StoreState(RValue&, CInstance*, CInstance*, int, RValue*)  0x152ff4  size 44  11 条（0x152ff4..0x153020）
 * @func 0x152ff4 0x153020  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152ff4 ldr r3, [pc, #0x20]
 *   @0x152ff8 mov r2, #0
 *   @0x152ffc str r2, [r0, #0xc]
 *   @0x153000 ldr r3, [pc, r3]
 *   @0x153004 ldr r2, [r3]
 *   @0x153008 vmov s15, r2
 *   @0x15300c vcvt.f64.s32 d7, s15
 *   @0x153010 vmov r2, r3, d7
 *   @0x153014 stm r0, {r2, r3}
 *   @0x153018 bx lr
 *   @0x15301c eoreq r12, r9, r4, asr #21
 *
 * ══ §82/828 F_YoYo_Achievement_GetInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x156628  size 44  11 条（0x156628..0x156654）
 * @func 0x156628 0x156654  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156628 push {r3, lr}
 *   @0x15662c mov r3, #0
 *   @0x156630 ldr r12, [sp, #0x8]
 *   @0x156634 mov r1, r3
 *   @0x156638 str r3, [r0, #0xc]
 *   @0x15663c str r3, [r0]
 *   @0x156640 str r3, [r0, #0x4]
 *   @0x156644 mov r0, r12
 *   @0x156648 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x15664c pop {r3, lr}
 *   @0x156650 b 0x1610e8 <_Z20Achievement_Get_InfoPc>
 *
 * ══ §83/828 F_YoYo_RequestPermission(RValue&, CInstance*, CInstance*, int, RValue*)  0x157648  size 44  11 条（0x157648..0x157674）
 * @func 0x157648 0x157674  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157648 push {r3, lr}
 *   @0x15764c mov r3, #0
 *   @0x157650 ldr r12, [sp, #0x8]
 *   @0x157654 mov r1, r3
 *   @0x157658 str r3, [r0, #0xc]
 *   @0x15765c str r3, [r0]
 *   @0x157660 str r3, [r0, #0x4]
 *   @0x157664 mov r0, r12
 *   @0x157668 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x15766c pop {r3, lr}
 *   @0x157670 b 0x15f32c <_Z19YYRequestPermissionPKc>
 *
 * ══ §84/828 Cache_ReadString(unsigned char*, int*)  0x159b64  size 44  11 条（0x159b64..0x159b90）
 * @func 0x159b64 0x159b90  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159b64 push {r4, r5, r6, lr}
 *   @0x159b68 mov r4, r1
 *   @0x159b6c ldr r5, [r1]
 *   @0x159b70 add r6, r0, r5
 *   @0x159b74 mov r0, r6
 *   @0x159b78 bl 0xb6538 <strlen@plt>
 *   @0x159b7c add r3, r0, #1
 *   @0x159b80 mov r0, r6
 *   @0x159b84 add r5, r5, r3
 *   @0x159b88 str r5, [r4]
 *   @0x159b8c pop {r4, r5, r6, pc}
 *
 * ══ §85/828 GR_3D_Clear_Z()  0x1631b0  size 44  11 条（0x1631b0..0x1631dc）
 * @func 0x1631b0 0x1631dc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1631b0 ldr r3, [pc, #0x20]
 *   @0x1631b4 ldr r3, [pc, r3]
 *   @0x1631b8 ldrb r3, [r3]
 *   @0x1631bc cmp r3, #0
 *   @0x1631c0 bxeq lr
 *   @0x1631c4 mov r0, #0
 *   @0x1631c8 mov r1, #1065353216
 *   @0x1631cc mov r2, r0
 *   @0x1631d0 mov r3, #6
 *   @0x1631d4 b 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags>
 *   @0x1631d8 eoreq r10, r8, r0, asr r11
 *
 * ══ §86/828 GR_3D_Transform_Set_Rotation_X(float)  0x1637d4  size 44  11 条（0x1637d4..0x163800）
 * @func 0x1637d4 0x163810  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetXRotation(yyMatrix*, float) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1637d4 push {r4, lr}
 *   @0x1637d8 sub sp, sp, #64
 *   @0x1637dc mov r1, r0
 *   @0x1637e0 mov r0, sp
 *   @0x1637e4 bl 0x27afe4 <_ZN8yyMatrix12SetXRotationEPS_f>
 *   @0x1637e8 mov r1, sp
 *   @0x1637ec mov r0, #2
 *   @0x1637f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1637f4 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1637f8 add sp, sp, #64
 *   @0x1637fc pop {r4, pc}
 *
 * ══ §87/828 GR_3D_Transform_Set_Rotation_Y(float)  0x163800  size 44  11 条（0x163800..0x16382c）
 * @func 0x163800 0x16383c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetYRotation(yyMatrix*, float) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163800 push {r4, lr}
 *   @0x163804 sub sp, sp, #64
 *   @0x163808 mov r1, r0
 *   @0x16380c mov r0, sp
 *   @0x163810 bl 0x27af60 <_ZN8yyMatrix12SetYRotationEPS_f>
 *   @0x163814 mov r1, sp
 *   @0x163818 mov r0, #2
 *   @0x16381c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163820 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163824 add sp, sp, #64
 *   @0x163828 pop {r4, pc}
 *
 * ══ §88/828 GR_3D_Transform_Set_Rotation_Z(float)  0x16382c  size 44  11 条（0x16382c..0x163858）
 * @func 0x16382c 0x163858  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::SetZRotation(yyMatrix*, float) / Graphics::SetMatrix(eMatrix, float*) / DirtyRoomExtents()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16382c push {r4, lr}
 *   @0x163830 sub sp, sp, #64
 *   @0x163834 mov r1, r0
 *   @0x163838 mov r0, sp
 *   @0x16383c bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f>
 *   @0x163840 mov r1, sp
 *   @0x163844 mov r0, #2
 *   @0x163848 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x16384c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163850 add sp, sp, #64
 *   @0x163854 pop {r4, pc}
 *
 * ══ §89/828 CBitmap32::__Free()  0x1678f0  size 44  11 条（0x1678f0..0x16791c）
 * @func 0x1678f0 0x16792c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x14×2 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1678f0 push {r4, lr}
 *   @0x1678f4 mov r4, r0
 *   @0x1678f8 ldr r0, [r0, #0x14]
 *   @0x1678fc cmp r0, #0
 *   @0x167900 popeq {r4, pc}
 *   @0x167904 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x167908 mov r3, #0
 *   @0x16790c str r3, [r4, #0x14]
 *   @0x167910 str r3, [r4, #0x10]
 *   @0x167914 strb r3, [r4, #0x4]
 *   @0x167918 pop {r4, pc}
 *
 * ══ §90/828 GR_D3D_Screenshot_Full()  0x169cd4  size 44  11 条（0x169cd4..0x169d00）
 * @func 0x169cd4 0x169d00  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169cd4 ldr r2, [pc, #0x1c]
 *   @0x169cd8 mov r0, #0
 *   @0x169cdc ldr r3, [pc, #0x18]
 *   @0x169ce0 mov r1, r0
 *   @0x169ce4 ldr r2, [pc, r2]
 *   @0x169ce8 ldr r3, [pc, r3]
 *   @0x169cec ldr r2, [r2]
 *   @0x169cf0 ldr r3, [r3]
 *   @0x169cf4 b 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii>
 *   @0x169cf8 eoreq r6, r8, r0, asr r4
 *   @0x169cfc eoreq r6, r8, r0, asr r4
 *
 * ══ §91/828 YYGML_draw_set_colour(unsigned int)  0x169d98  size 44  11 条（0x169d98..0x169dc4）
 * @func 0x169d98 0x169dc4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169d98 ldr r3, [pc, #0x1c]
 *   @0x169d9c bic r0, r0, #-16777216
 *   @0x169da0 ldr r2, [pc, #0x18]
 *   @0x169da4 ldr r3, [pc, r3]
 *   @0x169da8 ldr r2, [pc, r2]
 *   @0x169dac ldr r3, [r3]
 *   @0x169db0 orr r0, r0, r3, lsl #24
 *   @0x169db4 str r0, [r2]
 *   @0x169db8 bx lr
 *   @0x169dbc eoreq r3, r8, r12, asr pc
 *   @0x169dc0 eoreq r3, r8, r4, asr pc
 *
 * ══ §92/828 GR_Draw_Set_Color3(int, int, int)  0x169e34  size 44  11 条（0x169e34..0x169e60）
 * @func 0x169e34 0x169e60  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_RGBA_To_D3DColor(int, int, int, unsigned int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169e34 push {r3, lr}
 *   @0x169e38 ldr r3, [pc, #0x18]
 *   @0x169e3c ldr r3, [pc, r3]
 *   @0x169e40 ldr r3, [r3]
 *   @0x169e44 bl 0x16ca74 <_Z19GR_RGBA_To_D3DColoriiij>
 *   @0x169e48 ldr r3, [pc, #0xc]
 *   @0x169e4c ldr r3, [pc, r3]
 *   @0x169e50 str r0, [r3]
 *   @0x169e54 pop {r3, pc}
 *   @0x169e58 eoreq r3, r8, r4, asr #29
 *   @0x169e5c .word 0x00283eb0
 *
 * ══ §93/828 anon_16c2c8  0x16c2c8  size 44  11 条（0x16c2c8..0x16c2f4）
 * @func 0x16c2c8 0x16c2f4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_io_ptr
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c2c8 bx lr
 *   @0x16c2cc push {r4, r5, r6, lr}
 *   @0x16c2d0 mov r5, r1
 *   @0x16c2d4 mov r4, r2
 *   @0x16c2d8 blx 0x2a5f20 <png_get_io_ptr>
 *   @0x16c2dc subs r3, r0, #0
 *   @0x16c2e0 popeq {r4, r5, r6, pc}
 *   @0x16c2e4 mov r0, r5
 *   @0x16c2e8 mov r2, r4
 *   @0x16c2ec mov r1, #1
 *   @0x16c2f0 pop {r4, r5, r6, lr}
 *
 * ══ §94/828 F_ViewGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c2f8  size 44  11 条（0x16c2f8..0x16c324）
 * @func 0x16c2f8 0x16c334  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c2f8 push {r3, r4, r5, lr}
 *   @0x16c2fc mov r4, r0
 *   @0x16c300 mov r5, r1
 *   @0x16c304 ldr r0, [sp, #0x10]
 *   @0x16c308 mov r1, #0
 *   @0x16c30c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c310 mov r2, r4
 *   @0x16c314 mov r1, r0
 *   @0x16c318 mov r0, r5
 *   @0x16c31c pop {r3, r4, r5, lr}
 *   @0x16c320 b 0x1f81b4 <_Z14GV_ViewVisibleP9CInstanceiP6RValue>
 *
 * ══ §95/828 F_ViewGetXport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c324  size 44  11 条（0x16c324..0x16c350）
 * @func 0x16c324 0x16c360  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c324 push {r3, r4, r5, lr}
 *   @0x16c328 mov r4, r0
 *   @0x16c32c mov r5, r1
 *   @0x16c330 ldr r0, [sp, #0x10]
 *   @0x16c334 mov r1, #0
 *   @0x16c338 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c33c mov r2, r4
 *   @0x16c340 mov r1, r0
 *   @0x16c344 mov r0, r5
 *   @0x16c348 pop {r3, r4, r5, lr}
 *   @0x16c34c b 0x1f8348 <_Z12GV_ViewXportP9CInstanceiP6RValue>
 *
 * ══ §96/828 F_ViewGetYport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c350  size 44  11 条（0x16c350..0x16c37c）
 * @func 0x16c350 0x16c38c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c350 push {r3, r4, r5, lr}
 *   @0x16c354 mov r4, r0
 *   @0x16c358 mov r5, r1
 *   @0x16c35c ldr r0, [sp, #0x10]
 *   @0x16c360 mov r1, #0
 *   @0x16c364 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c368 mov r2, r4
 *   @0x16c36c mov r1, r0
 *   @0x16c370 mov r0, r5
 *   @0x16c374 pop {r3, r4, r5, lr}
 *   @0x16c378 b 0x1f839c <_Z12GV_ViewYportP9CInstanceiP6RValue>
 *
 * ══ §97/828 F_ViewGetWport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c37c  size 44  11 条（0x16c37c..0x16c3a8）
 * @func 0x16c37c 0x16c3b8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c37c push {r3, r4, r5, lr}
 *   @0x16c380 mov r4, r0
 *   @0x16c384 mov r5, r1
 *   @0x16c388 ldr r0, [sp, #0x10]
 *   @0x16c38c mov r1, #0
 *   @0x16c390 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c394 mov r2, r4
 *   @0x16c398 mov r1, r0
 *   @0x16c39c mov r0, r5
 *   @0x16c3a0 pop {r3, r4, r5, lr}
 *   @0x16c3a4 b 0x1f83f0 <_Z12GV_ViewWportP9CInstanceiP6RValue>
 *
 * ══ §98/828 F_ViewGetHport(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c3a8  size 44  11 条（0x16c3a8..0x16c3d4）
 * @func 0x16c3a8 0x16c3e4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c3a8 push {r3, r4, r5, lr}
 *   @0x16c3ac mov r4, r0
 *   @0x16c3b0 mov r5, r1
 *   @0x16c3b4 ldr r0, [sp, #0x10]
 *   @0x16c3b8 mov r1, #0
 *   @0x16c3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c3c0 mov r2, r4
 *   @0x16c3c4 mov r1, r0
 *   @0x16c3c8 mov r0, r5
 *   @0x16c3cc pop {r3, r4, r5, lr}
 *   @0x16c3d0 b 0x1f8444 <_Z12GV_ViewHportP9CInstanceiP6RValue>
 *
 * ══ §99/828 F_ViewGetSurfaceId(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c3d4  size 44  11 条（0x16c3d4..0x16c400）
 * @func 0x16c3d4 0x16c410  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c3d4 push {r3, r4, r5, lr}
 *   @0x16c3d8 mov r4, r0
 *   @0x16c3dc mov r5, r1
 *   @0x16c3e0 ldr r0, [sp, #0x10]
 *   @0x16c3e4 mov r1, #0
 *   @0x16c3e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c3ec mov r2, r4
 *   @0x16c3f0 mov r1, r0
 *   @0x16c3f4 mov r0, r5
 *   @0x16c3f8 pop {r3, r4, r5, lr}
 *   @0x16c3fc b 0x1f8b18 <_Z16GV_ViewSurfaceIDP9CInstanceiP6RValue>
 *
 * ══ §100/828 F_ViewGetCamera(RValue&, CInstance*, CInstance*, int, RValue*)  0x16c400  size 44  11 条（0x16c400..0x16c42c）
 * @func 0x16c400 0x16c42c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c400 push {r3, r4, r5, lr}
 *   @0x16c404 mov r4, r0
 *   @0x16c408 mov r5, r1
 *   @0x16c40c ldr r0, [sp, #0x10]
 *   @0x16c410 mov r1, #0
 *   @0x16c414 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16c418 mov r2, r4
 *   @0x16c41c mov r1, r0
 *   @0x16c420 mov r0, r5
 *   @0x16c424 pop {r3, r4, r5, lr}
 *   @0x16c428 b 0x1f8b6c <_Z13GV_ViewCameraP9CInstanceiP6RValue>
 *
 * ══ §101/828 GR_Surface_DrawSimple(int, float, float)  0x171d90  size 44  11 条（0x171d90..0x171dbc）
 * @func 0x171d90 0x171dbc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171d90 push {r3, r4, r5, lr}
 *   @0x171d94 mov r5, r1
 *   @0x171d98 mov r4, r2
 *   @0x171d9c bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171da0 cmp r0, #0
 *   @0x171da4 popeq {r3, r4, r5, pc}
 *   @0x171da8 mov r1, r5
 *   @0x171dac mov r2, r4
 *   @0x171db0 ldr r0, [r0, #0x4]
 *   @0x171db4 pop {r3, r4, r5, lr}
 *   @0x171db8 b 0x174498 <_Z22GR_Texture_Draw_Simpleiff>
 *
 * ══ §102/828 FreeTextureResources()  0x181190  size 44  11 条（0x181190..0x1811bc）
 * @func 0x181190 0x1811bc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::FreeTexture(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181190 push {r4, lr}
 *   @0x181194 ldr r4, [pc, #0x1c]
 *   @0x181198 ldr r4, [pc, r4]
 *   @0x18119c ldr r0, [r4]
 *   @0x1811a0 cmp r0, #0
 *   @0x1811a4 popeq {r4, pc}
 *   @0x1811a8 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv>
 *   @0x1811ac mov r3, #0
 *   @0x1811b0 str r3, [r4]
 *   @0x1811b4 pop {r4, pc}
 *   @0x1811b8 .word 0x0026f3b4
 *
 * ══ §103/828 GetRowsFromType(unsigned int)  0x186808  size 44  11 条（0x186808..0x186834）
 * @func 0x186808 0x186834  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x186808 sub r0, r0, #35584
 *   @0x18680c sub r0, r0, #90
 *   @0x186810 cmp r0, #2
 *   @0x186814 bhi 0x186828 <_Z15GetRowsFromTypej+0x20>
 *   @0x186818 ldr r3, [pc, #0x10]
 *   @0x18681c add r3, pc, r3
 *   @0x186820 ldr r0, [r3, r0, lsl #2]
 *   @0x186824 bx lr
 *   @0x186828 mov r0, #1
 *   @0x18682c bx lr
 *   @0x186830 andseq r7, sp, r0, asr #8
 *
 * ══ §104/828 ReadGifData(GifFileType*, unsigned char*, int)  0x18a664  size 44  11 条（0x18a664..0x18a690）
 * @func 0x18a664 0x18a690  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x44×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a664 push {r3, r4, r5, lr}
 *   @0x18a668 mov r4, r0
 *   @0x18a66c mov r0, r1
 *   @0x18a670 ldr r1, [r4, #0x44]
 *   @0x18a674 mov r5, r2
 *   @0x18a678 bl 0xb65bc <memcpy@plt>
 *   @0x18a67c ldr r3, [r4, #0x44]
 *   @0x18a680 mov r0, r5
 *   @0x18a684 add r5, r3, r5
 *   @0x18a688 str r5, [r4, #0x44]
 *   @0x18a68c pop {r3, r4, r5, pc}
 *
 * ══ §105/828 ProfileFrameRequest(unsigned int, unsigned int)  0x18efd8  size 44  11 条（0x18efd8..0x18f004）
 * @func 0x18efd8 0x18f004  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18efd8 rsbs r3, r0, #1
 *   @0x18efdc movlo r3, #0
 *   @0x18efe0 cmp r1, #0
 *   @0x18efe4 moveq r3, #0
 *   @0x18efe8 cmp r3, #0
 *   @0x18efec ldrne r3, [pc, #0xc]
 *   @0x18eff0 movne r2, #1
 *   @0x18eff4 ldrne r3, [pc, r3]
 *   @0x18eff8 strbne r2, [r3]
 *   @0x18effc bx lr
 *   @0x18f000 eoreq r1, r6, r0, asr r6
 *
 * ══ §106/828 YYSlot<YYObjectBase>::~YYSlot()  0x190d00  size 44  11 条（0x190d00..0x190d2c）
 * @func 0x190d00 0x190d2c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190d00 push {r4, lr}
 *   @0x190d04 mov r4, r0
 *   @0x190d08 ldr r0, [r0]
 *   @0x190d0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x190d10 mov r3, #0
 *   @0x190d14 mov r0, r4
 *   @0x190d18 str r3, [r4]
 *   @0x190d1c str r3, [r4, #0x4]
 *   @0x190d20 str r3, [r4, #0x8]
 *   @0x190d24 str r3, [r4, #0xc]
 *   @0x190d28 pop {r4, pc}
 *
 * ══ §107/828 Eff_Create00()  0x1a0030  size 44  11 条（0x1a0030..0x1a005c）
 * @func 0x1a0030 0x1a005c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()
 * 字段偏移 top8: 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0030 push {r3, r4, r5, lr}
 *   @0x1a0034 ldr r5, [pc, #0x1c]
 *   @0x1a0038 ldr r5, [pc, r5]
 *   @0x1a003c sub r4, r5, #4
 *   @0x1a0040 add r5, r5, #20
 *   @0x1a0044 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0048 str r0, [r4, #0x4]!
 *   @0x1a004c cmp r4, r5
 *   @0x1a0050 bne 0x1a0044 <_Z12Eff_Create00v+0x14>
 *   @0x1a0054 pop {r3, r4, r5, pc}
 *   @0x1a0058 eoreq r0, r5, r8, lsr r7
 *
 * ══ §108/828 Eff_Create01()  0x1a05e8  size 44  11 条（0x1a05e8..0x1a0614）
 * @func 0x1a05e8 0x1a0614  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a05e8 push {r4, lr}
 *   @0x1a05ec bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a05f0 ldr r4, [pc, #0x18]
 *   @0x1a05f4 ldr r4, [pc, r4]
 *   @0x1a05f8 str r0, [r4]
 *   @0x1a05fc bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0600 str r0, [r4, #0x4]
 *   @0x1a0604 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0608 str r0, [r4, #0x8]
 *   @0x1a060c pop {r4, pc}
 *   @0x1a0610 eoreq r0, r5, r0, lsl #3
 *
 * ══ §109/828 Eff_Create02()  0x1a081c  size 44  11 条（0x1a081c..0x1a0848）
 * @func 0x1a081c 0x1a0848  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a081c push {r4, lr}
 *   @0x1a0820 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0824 ldr r4, [pc, #0x18]
 *   @0x1a0828 ldr r4, [pc, r4]
 *   @0x1a082c str r0, [r4]
 *   @0x1a0830 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0834 str r0, [r4, #0x4]
 *   @0x1a0838 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a083c str r0, [r4, #0x8]
 *   @0x1a0840 pop {r4, pc}
 *   @0x1a0844 eoreq pc, r4, r0, asr pc
 *
 * ══ §110/828 Eff_Create03()  0x1a0a84  size 44  11 条（0x1a0a84..0x1a0ab0）
 * @func 0x1a0a84 0x1a0ab0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0a84 push {r4, lr}
 *   @0x1a0a88 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0a8c ldr r4, [pc, #0x18]
 *   @0x1a0a90 ldr r4, [pc, r4]
 *   @0x1a0a94 str r0, [r4]
 *   @0x1a0a98 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0a9c str r0, [r4, #0x4]
 *   @0x1a0aa0 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0aa4 str r0, [r4, #0x8]
 *   @0x1a0aa8 pop {r4, pc}
 *   @0x1a0aac eoreq pc, r4, r12, ror #25
 *
 * ══ §111/828 Eff_Create04()  0x1a0e38  size 44  11 条（0x1a0e38..0x1a0e64）
 * @func 0x1a0e38 0x1a0e64  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0e38 push {r4, lr}
 *   @0x1a0e3c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0e40 ldr r4, [pc, #0x18]
 *   @0x1a0e44 ldr r4, [pc, r4]
 *   @0x1a0e48 str r0, [r4]
 *   @0x1a0e4c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0e50 str r0, [r4, #0x4]
 *   @0x1a0e54 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a0e58 str r0, [r4, #0x8]
 *   @0x1a0e5c pop {r4, pc}
 *   @0x1a0e60 eoreq pc, r4, r12, lsr r9
 *
 * ══ §112/828 Eff_Create05()  0x1a1168  size 44  11 条（0x1a1168..0x1a1194）
 * @func 0x1a1168 0x1a1194  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1168 push {r4, lr}
 *   @0x1a116c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1170 ldr r4, [pc, #0x18]
 *   @0x1a1174 ldr r4, [pc, r4]
 *   @0x1a1178 str r0, [r4]
 *   @0x1a117c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1180 str r0, [r4, #0x4]
 *   @0x1a1184 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1188 str r0, [r4, #0x8]
 *   @0x1a118c pop {r4, pc}
 *   @0x1a1190 eoreq pc, r4, r0, lsl r6
 *
 * ══ §113/828 Eff_Create06()  0x1a1564  size 44  11 条（0x1a1564..0x1a1590）
 * @func 0x1a1564 0x1a1590  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1564 push {r4, lr}
 *   @0x1a1568 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a156c ldr r4, [pc, #0x18]
 *   @0x1a1570 ldr r4, [pc, r4]
 *   @0x1a1574 str r0, [r4]
 *   @0x1a1578 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a157c str r0, [r4, #0x4]
 *   @0x1a1580 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1584 str r0, [r4, #0x8]
 *   @0x1a1588 pop {r4, pc}
 *   @0x1a158c eoreq pc, r4, r8, lsl r2
 *
 * ══ §114/828 Eff_Create07()  0x1a17c0  size 44  11 条（0x1a17c0..0x1a17ec）
 * @func 0x1a17c0 0x1a17ec  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a17c0 push {r4, lr}
 *   @0x1a17c4 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a17c8 ldr r4, [pc, #0x18]
 *   @0x1a17cc ldr r4, [pc, r4]
 *   @0x1a17d0 str r0, [r4]
 *   @0x1a17d4 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a17d8 str r0, [r4, #0x4]
 *   @0x1a17dc bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a17e0 str r0, [r4, #0x8]
 *   @0x1a17e4 pop {r4, pc}
 *   @0x1a17e8 eoreq lr, r4, r0, asr #31
 *
 * ══ §115/828 Eff_Create08()  0x1a1a18  size 44  11 条（0x1a1a18..0x1a1a44）
 * @func 0x1a1a18 0x1a1a44  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1a18 push {r4, lr}
 *   @0x1a1a1c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1a20 ldr r4, [pc, #0x18]
 *   @0x1a1a24 ldr r4, [pc, r4]
 *   @0x1a1a28 str r0, [r4]
 *   @0x1a1a2c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1a30 str r0, [r4, #0x4]
 *   @0x1a1a34 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1a38 str r0, [r4, #0x8]
 *   @0x1a1a3c pop {r4, pc}
 *   @0x1a1a40 eoreq lr, r4, r12, ror #26
 *
 * ══ §116/828 Eff_Create09()  0x1a1c70  size 44  11 条（0x1a1c70..0x1a1c9c）
 * @func 0x1a1c70 0x1a1c9c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()×3
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1c70 push {r4, lr}
 *   @0x1a1c74 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1c78 ldr r4, [pc, #0x18]
 *   @0x1a1c7c ldr r4, [pc, r4]
 *   @0x1a1c80 str r0, [r4]
 *   @0x1a1c84 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1c88 str r0, [r4, #0x4]
 *   @0x1a1c8c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1c90 str r0, [r4, #0x8]
 *   @0x1a1c94 pop {r4, pc}
 *   @0x1a1c98 eoreq lr, r4, r8, lsl r11
 *
 * ══ §117/828 RomDisk::Load(int)  0x1a86fc  size 44  11 条（0x1a86fc..0x1a8728）
 * @func 0x1a86fc 0x1a8738  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a86fc ldr r3, [pc, #0x20]
 *   @0x1a8700 ldr r3, [pc, r3]
 *   @0x1a8704 ldr r3, [r3]
 *   @0x1a8708 ldr r2, [r3]
 *   @0x1a870c cmp r2, r0
 *   @0x1a8710 addgt r0, r3, r0, lsl #3
 *   @0x1a8714 ldrgt r0, [r0, #0x8]
 *   @0x1a8718 addgt r0, r3, r0
 *   @0x1a871c movle r0, #0
 *   @0x1a8720 bx lr
 *   @0x1a8724 eoreq r8, r4, r0, ror #1
 *
 * ══ §118/828 IBitmapLoader::Create(void*, int)  0x1a9260  size 44  11 条（0x1a9260..0x1a928c）
 * @func 0x1a9260 0x1a928c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / BitmapLoader::BitmapLoader(void*, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a9260 push {r4, r5, r6, lr}
 *   @0x1a9264 mov r6, r0
 *   @0x1a9268 mov r0, #20
 *   @0x1a926c mov r5, r1
 *   @0x1a9270 bl 0x27c524 <_Znwj>
 *   @0x1a9274 mov r1, r6
 *   @0x1a9278 mov r2, r5
 *   @0x1a927c mov r4, r0
 *   @0x1a9280 bl 0x1a9218 <_ZN12BitmapLoaderC2EPvi>
 *   @0x1a9284 mov r0, r4
 *   @0x1a9288 pop {r4, r5, r6, pc}
 *
 * ══ §119/828 CreateDefaultCamera()  0x1afef0  size 44  11 条（0x1afef0..0x1aff1c）
 * @func 0x1afef0 0x1aff1c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::CreateCamera() / CCamera::GetID()
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1afef0 ldr r0, [pc, #0x1c]
 *   @0x1afef4 push {r3, lr}
 *   @0x1afef8 ldr r0, [pc, r0]
 *   @0x1afefc bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv>
 *   @0x1aff00 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x1aff04 ldr r3, [pc, #0xc]
 *   @0x1aff08 ldr r3, [pc, r3]
 *   @0x1aff0c str r0, [r3]
 *   @0x1aff10 pop {r3, pc}
 *   @0x1aff14 eoreq sp, r3, r12, ror sp
 *   @0x1aff18 eoreq r0, r4, r4, asr r3
 *
 * ══ §120/828 F_TilemapGetGlobalMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b5e74  size 44  11 条（0x1b5e74..0x1b5ea0）
 * @func 0x1b5e74 0x1b5eb0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e74 ldr r3, [pc, #0x20]
 *   @0x1b5e78 mov r2, #0
 *   @0x1b5e7c str r2, [r0, #0xc]
 *   @0x1b5e80 ldr r3, [pc, r3]
 *   @0x1b5e84 ldr r2, [r3]
 *   @0x1b5e88 vmov s15, r2
 *   @0x1b5e8c vcvt.f64.u32 d7, s15
 *   @0x1b5e90 vmov r2, r3, d7
 *   @0x1b5e94 stm r0, {r2, r3}
 *   @0x1b5e98 bx lr
 *   @0x1b5e9c mlaeq r3, r8, r9, r10
 *
 * ══ §121/828 F_LayerGetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b5ea0  size 44  11 条（0x1b5ea0..0x1b5ecc）
 * @func 0x1b5ea0 0x1b5ecc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5ea0 ldr r3, [pc, #0x20]
 *   @0x1b5ea4 mov r2, #0
 *   @0x1b5ea8 str r2, [r0, #0xc]
 *   @0x1b5eac ldr r3, [pc, r3]
 *   @0x1b5eb0 ldr r2, [r3]
 *   @0x1b5eb4 vmov s15, r2
 *   @0x1b5eb8 vcvt.f64.s32 d7, s15
 *   @0x1b5ebc vmov r2, r3, d7
 *   @0x1b5ec0 stm r0, {r2, r3}
 *   @0x1b5ec4 bx lr
 *   @0x1b5ec8 eoreq r10, r3, r8, lsr #19
 *
 * ══ §122/828 F_LayerGetForcedDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b5f18  size 44  11 条（0x1b5f18..0x1b5f44）
 * @func 0x1b5f18 0x1b5f44  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5f18 ldr r3, [pc, #0x20]
 *   @0x1b5f1c mov r2, #0
 *   @0x1b5f20 str r2, [r0, #0xc]
 *   @0x1b5f24 ldr r3, [pc, r3]
 *   @0x1b5f28 ldr r2, [r3]
 *   @0x1b5f2c vmov s15, r2
 *   @0x1b5f30 vcvt.f64.s32 d7, s15
 *   @0x1b5f34 vmov r2, r3, d7
 *   @0x1b5f38 stm r0, {r2, r3}
 *   @0x1b5f3c bx lr
 *   @0x1b5f40 eoreq r10, r3, r0, lsl r9
 *
 * ══ §123/828 RemoveQuotes(char*)  0x1d2298  size 44  11 条（0x1d2298..0x1d22c4）
 * @func 0x1d2298 0x1d22c4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d2298 ldrb r3, [r0]
 *   @0x1d229c cmp r3, #0
 *   @0x1d22a0 bxeq lr
 *   @0x1d22a4 add r2, r0, #1
 *   @0x1d22a8 mov r1, #32
 *   @0x1d22ac cmp r3, #34
 *   @0x1d22b0 strbeq r1, [r2, #-0x1]
 *   @0x1d22b4 ldrb r3, [r2], #1
 *   @0x1d22b8 cmp r3, #0
 *   @0x1d22bc bne 0x1d22ac <_Z12RemoveQuotesPc+0x14>
 *   @0x1d22c0 bx lr
 *
 * ══ §124/828 GetName(char const*&, int)  0x1dc1fc  size 44  11 条（0x1dc1fc..0x1dc228）
 * @func 0x1dc1fc 0x1dc238  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetAll(int, char const*&, int&)
 * 字段偏移 top8: 0x-4×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc1fc str lr, [sp, #-0x4]!
 *   @0x1dc200 sub sp, sp, #12
 *   @0x1dc204 add r2, sp, #8
 *   @0x1dc208 mov r12, r0
 *   @0x1dc20c mov r3, #0
 *   @0x1dc210 mov r0, r1
 *   @0x1dc214 str r3, [r2, #-0x4]!
 *   @0x1dc218 mov r1, r12
 *   @0x1dc21c bl 0x1dc1d4 <_Z6GetAlliRPKcRi>
 *   @0x1dc220 add sp, sp, #12
 *   @0x1dc224 ldr pc, [sp], #4
 *
 * ══ §125/828 GetScore(int)  0x1dc228  size 44  11 条（0x1dc228..0x1dc254）
 * @func 0x1dc228 0x1dc254  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetAll(int, char const*&, int&)
 * 字段偏移 top8: 0x-4×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc228 str lr, [sp, #-0x4]!
 *   @0x1dc22c sub sp, sp, #12
 *   @0x1dc230 add r1, sp, #8
 *   @0x1dc234 mov r3, #0
 *   @0x1dc238 mov r2, sp
 *   @0x1dc23c str r3, [sp]
 *   @0x1dc240 str r3, [r1, #-0x4]!
 *   @0x1dc244 bl 0x1dc1d4 <_Z6GetAlliRPKcRi>
 *   @0x1dc248 ldr r0, [sp]
 *   @0x1dc24c add sp, sp, #12
 *   @0x1dc250 ldr pc, [sp], #4
 *
 * ══ §126/828 VertexFormat::GetNumElementsInType(yyVertexType)  0x1e2400  size 44  11 条（0x1e2400..0x1e242c）
 * @func 0x1e2400 0x1e242c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2400 sub r0, r0, #1
 *   @0x1e2404 cmp r0, #5
 *   @0x1e2408 bhi 0x1e2420 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType+0x20>
 *   @0x1e240c ldr r3, [pc, #0x14]
 *   @0x1e2410 add r3, pc, r3
 *   @0x1e2414 add r0, r3, r0, lsl #2
 *   @0x1e2418 ldr r0, [r0, #0x18]
 *   @0x1e241c bx lr
 *   @0x1e2420 mov r0, #0
 *   @0x1e2424 bx lr
 *   @0x1e2428 andseq r11, r7, r4, lsl #22
 *
 * ══ §127/828 CVariableList::Clear()  0x1f662c  size 44  11 条（0x1f662c..0x1f6658）
 * @func 0x1f662c 0x1f6668  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeRange(CVariableList&) / 0xb65b0
 * 字段偏移 top8: 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f662c push {r4, lr}
 *   @0x1f6630 mov r4, r0
 *   @0x1f6634 bl 0x1f659c <_Z9FreeRangeR13CVariableList>
 *   @0x1f6638 add r0, r4, #4
 *   @0x1f663c mov r1, #0
 *   @0x1f6640 mov r2, #16
 *   @0x1f6644 bl 0xb65b0 <memset@plt>
 *   @0x1f6648 mov r3, #0
 *   @0x1f664c str r3, [r4, #0x18]
 *   @0x1f6650 str r3, [r4, #0x14]
 *   @0x1f6654 pop {r4, pc}
 *
 * ══ §128/828 CVariableList::Clear(RVariable**, RVariable**)  0x1f6a94  size 44  11 条（0x1f6a94..0x1f6ac0）
 * @func 0x1f6a94 0x1f6ac0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeRange(CVariableList&, RVariable**, RVariable**) / 0xb65b0
 * 字段偏移 top8: 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6a94 push {r4, lr}
 *   @0x1f6a98 mov r4, r0
 *   @0x1f6a9c bl 0x1f69f4 <_Z9FreeRangeR13CVariableListPP9RVariableS3_>
 *   @0x1f6aa0 add r0, r4, #4
 *   @0x1f6aa4 mov r1, #0
 *   @0x1f6aa8 mov r2, #16
 *   @0x1f6aac bl 0xb65b0 <memset@plt>
 *   @0x1f6ab0 mov r3, #0
 *   @0x1f6ab4 str r3, [r4, #0x18]
 *   @0x1f6ab8 str r3, [r4, #0x14]
 *   @0x1f6abc pop {r4, pc}
 *
 * ══ §129/828 GV_Health(CInstance*, int, RValue*)  0x1f7b04  size 44  11 条（0x1f7b04..0x1f7b30）
 * @func 0x1f7b04 0x1f7b30  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7b04 ldr r3, [pc, #0x20]
 *   @0x1f7b08 mov r1, #0
 *   @0x1f7b0c str r1, [r2, #0xc]
 *   @0x1f7b10 mov r0, #1
 *   @0x1f7b14 ldr r3, [pc, r3]
 *   @0x1f7b18 ldr r1, [r3]
 *   @0x1f7b1c str r1, [r2]
 *   @0x1f7b20 ldr r3, [r3, #0x4]
 *   @0x1f7b24 str r3, [r2, #0x4]
 *   @0x1f7b28 bx lr
 *   @0x1f7b2c andseq r7, pc, r4, asr #17
 *
 * ══ §130/828 SV_CaptionScore(CInstance*, int, RValue*)  0x1f8850  size 44  11 条（0x1f8850..0x1f887c）
 * @func 0x1f8850 0x1f888c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8850 ldr r3, [r2]
 *   @0x1f8854 mov r0, #1
 *   @0x1f8858 cmp r3, #0
 *   @0x1f885c ldrne r2, [r3, #0x4]
 *   @0x1f8860 addne r2, r2, #1
 *   @0x1f8864 strne r2, [r3, #0x4]
 *   @0x1f8868 ldr r2, [pc, #0x8]
 *   @0x1f886c ldr r2, [pc, r2]
 *   @0x1f8870 str r3, [r2]
 *   @0x1f8874 bx lr
 *   @0x1f8878 andseq r6, pc, r4, lsl #27
 *
 * ══ §131/828 SV_CaptionLives(CInstance*, int, RValue*)  0x1f887c  size 44  11 条（0x1f887c..0x1f88a8）
 * @func 0x1f887c 0x1f88b8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f887c ldr r3, [r2]
 *   @0x1f8880 mov r0, #1
 *   @0x1f8884 cmp r3, #0
 *   @0x1f8888 ldrne r2, [r3, #0x4]
 *   @0x1f888c addne r2, r2, #1
 *   @0x1f8890 strne r2, [r3, #0x4]
 *   @0x1f8894 ldr r2, [pc, #0x8]
 *   @0x1f8898 ldr r2, [pc, r2]
 *   @0x1f889c str r3, [r2]
 *   @0x1f88a0 bx lr
 *   @0x1f88a4 andseq r6, pc, r0, ror #26
 *
 * ══ §132/828 SV_CaptionHealth(CInstance*, int, RValue*)  0x1f88a8  size 44  11 条（0x1f88a8..0x1f88d4）
 * @func 0x1f88a8 0x1f88d4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f88a8 ldr r3, [r2]
 *   @0x1f88ac mov r0, #1
 *   @0x1f88b0 cmp r3, #0
 *   @0x1f88b4 ldrne r2, [r3, #0x4]
 *   @0x1f88b8 addne r2, r2, #1
 *   @0x1f88bc strne r2, [r3, #0x4]
 *   @0x1f88c0 ldr r2, [pc, #0x8]
 *   @0x1f88c4 ldr r2, [pc, r2]
 *   @0x1f88c8 str r3, [r2]
 *   @0x1f88cc bx lr
 *   @0x1f88d0 andseq r6, pc, r12, lsr sp
 *
 * ══ §133/828 SV_ErrorLast(CInstance*, int, RValue*)  0x1f8a6c  size 44  11 条（0x1f8a6c..0x1f8a98）
 * @func 0x1f8a6c 0x1f8a98  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8a6c ldr r3, [r2]
 *   @0x1f8a70 mov r0, #1
 *   @0x1f8a74 cmp r3, #0
 *   @0x1f8a78 ldrne r2, [r3, #0x4]
 *   @0x1f8a7c addne r2, r2, #1
 *   @0x1f8a80 strne r2, [r3, #0x4]
 *   @0x1f8a84 ldr r2, [pc, #0x8]
 *   @0x1f8a88 ldr r2, [pc, r2]
 *   @0x1f8a8c str r3, [r2]
 *   @0x1f8a90 bx lr
 *   @0x1f8a94 andseq r5, pc, r4, lsl r3
 *
 * ══ §134/828 GV_TempDirectory(CInstance*, int, RValue*)  0x1f9d2c  size 44  11 条（0x1f9d2c..0x1f9d58）
 * @func 0x1f9d2c 0x1f9d58  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: File_TempDir() / YYCreateString(RValue*, char const*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9d2c push {r3, r4, r5, lr}
 *   @0x1f9d30 mov r5, r2
 *   @0x1f9d34 bl 0x214dfc <_Z12File_TempDirv>
 *   @0x1f9d38 mov r4, r0
 *   @0x1f9d3c mov r0, r5
 *   @0x1f9d40 mov r1, r4
 *   @0x1f9d44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9d48 mov r0, r4
 *   @0x1f9d4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f9d50 mov r0, #1
 *   @0x1f9d54 pop {r3, r4, r5, pc}
 *
 * ══ §135/828 SV_Argument0(CInstance*, int, RValue*)  0x1fa47c  size 44  11 条（0x1fa47c..0x1fa4a8）
 * @func 0x1fa47c 0x1fa4a8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa47c push {r3, lr}
 *   @0x1fa480 mov r0, r1
 *   @0x1fa484 ldr r3, [pc, #0x18]
 *   @0x1fa488 mov r1, r2
 *   @0x1fa48c mov r2, r0
 *   @0x1fa490 ldr r3, [pc, r3]
 *   @0x1fa494 ldr r0, [r3]
 *   @0x1fa498 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa49c mov r0, #1
 *   @0x1fa4a0 pop {r3, pc}
 *   @0x1fa4a4 andseq r3, pc, r0, lsl #17
 *
 * ══ §136/828 CDS_Grid::CDS_Grid(int, int)  0x20b10c  size 44  11 条（0x20b10c..0x20b138）
 * @func 0x20b10c 0x20b138  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::SetSize(int, int)
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b10c push {r4, r5, r6, lr}
 *   @0x20b110 mov r3, #0
 *   @0x20b114 mov r4, r0
 *   @0x20b118 str r3, [r0]
 *   @0x20b11c mov r6, r1
 *   @0x20b120 mov r5, r2
 *   @0x20b124 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii>
 *   @0x20b128 str r6, [r4, #0x4]
 *   @0x20b12c mov r0, r4
 *   @0x20b130 str r5, [r4, #0x8]
 *   @0x20b134 pop {r4, r5, r6, pc}
 *
 * ══ §137/828 GetCurrentDir()  0x214e1c  size 44  11 条（0x214e1c..0x214e48）
 * @func 0x214e1c 0x214e58  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e1c ldr r1, [pc, #0x20]
 *   @0x214e20 mov r2, #234
 *   @0x214e24 push {r3, lr}
 *   @0x214e28 add r1, pc, r1
 *   @0x214e2c mov r3, #0
 *   @0x214e30 mov r0, #1
 *   @0x214e34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x214e38 mov r2, #0
 *   @0x214e3c strb r2, [r0]
 *   @0x214e40 pop {r3, pc}
 *   @0x214e44 andseq lr, r3, r4, lsr #24
 *
 * ══ §138/828 CSound::GetSoundId()  0x215748  size 44  11 条（0x215748..0x215774）
 * @func 0x215748 0x215774  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::GetSoundId()+0x1c / CSound::Restore()
 * 字段偏移 top8: 0x30×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215748 ldr r3, [r0, #0x30]
 *   @0x21574c push {r4, lr}
 *   @0x215750 cmp r3, #0
 *   @0x215754 mov r4, r0
 *   @0x215758 blt 0x215764 <_ZN6CSound10GetSoundIdEv+0x1c>
 *   @0x21575c mov r0, r3
 *   @0x215760 pop {r4, pc}
 *   @0x215764 bl 0x215540 <_ZN6CSound7RestoreEv>
 *   @0x215768 ldr r3, [r4, #0x30]
 *   @0x21576c mov r0, r3
 *   @0x215770 pop {r4, pc}
 *
 * ══ §139/828 Audio_GetMasterGain(int)  0x218190  size 44  11 条（0x218190..0x2181bc）
 * @func 0x218190 0x2181bc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218190 cmp r0, #0
 *   @0x218194 bne 0x2181b0 <_Z19Audio_GetMasterGaini+0x20>
 *   @0x218198 ldr r3, [pc, #0x18]
 *   @0x21819c ldr r3, [pc, r3]
 *   @0x2181a0 ldr r0, [r3]
 *   @0x2181a4 cmp r0, #0
 *   @0x2181a8 beq 0x2181b0 <_Z19Audio_GetMasterGaini+0x20>
 *   @0x2181ac b 0x215b40 <_ZN9CListener7GetGainEv>
 *   @0x2181b0 mov r0, #0
 *   @0x2181b4 bx lr
 *   @0x2181b8 andseq r9, sp, r0, asr #4
 *
 * ══ §140/828 CAudioGroup::CAudioGroup(int)  0x21db54  size 44  11 条（0x21db54..0x21db80）
 * @func 0x21db54 0x21db80  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x18×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x24×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21db54 mov r2, #0
 *   @0x21db58 str r1, [r0, #0x4]
 *   @0x21db5c str r2, [r0, #0x18]
 *   @0x21db60 str r2, [r0]
 *   @0x21db64 str r2, [r0, #0x8]
 *   @0x21db68 str r2, [r0, #0xc]
 *   @0x21db6c str r2, [r0, #0x10]
 *   @0x21db70 str r2, [r0, #0x24]
 *   @0x21db74 str r2, [r0, #0x20]
 *   @0x21db78 str r2, [r0, #0x1c]
 *   @0x21db7c bx lr
 *
 * ══ §141/828 CAudioGroup::SetName(char const*)  0x21dbf4  size 44  11 条（0x21dbf4..0x21dc20）
 * @func 0x21dbf4 0x21dc20  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dbf4 push {r3, r4, r5, lr}
 *   @0x21dbf8 mov r4, r0
 *   @0x21dbfc ldr r0, [r0, #0x1c]
 *   @0x21dc00 mov r5, r1
 *   @0x21dc04 cmp r0, #0
 *   @0x21dc08 beq 0x21dc10 <_ZN11CAudioGroup7SetNameEPKc+0x1c>
 *   @0x21dc0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x21dc10 mov r0, r5
 *   @0x21dc14 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x21dc18 str r0, [r4, #0x1c]
 *   @0x21dc1c pop {r3, r4, r5, pc}
 *
 * ══ §142/828 _alutOutputStreamWriteInt16BE  0x222988  size 44  11 条（0x222988..0x2229b4）
 * @func 0x222988 0x2229b4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_222930
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222988 str lr, [sp, #-0x4]!
 *   @0x22298c sub sp, sp, #12
 *   @0x222990 mov r3, r1
 *   @0x222994 mov r2, #2
 *   @0x222998 add r1, sp, #4
 *   @0x22299c strb r3, [sp, #0x5]
 *   @0x2229a0 asr r3, r3, #8
 *   @0x2229a4 strb r3, [sp, #0x4]
 *   @0x2229a8 bl 0x222930 <_alutOutputStreamGetLength+0xc>
 *   @0x2229ac add sp, sp, #12
 *   @0x2229b0 ldr pc, [sp], #4
 *
 * ══ §143/828 alutCreateBufferHelloWorld  0x22306c  size 44  11 条（0x22306c..0x223098）
 * @func 0x22306c 0x223098  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromMemory
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22306c push {r3, lr}
 *   @0x223070 bl 0x2219a8 <_alutSanityCheck>
 *   @0x223074 cmp r0, #0
 *   @0x223078 popeq {r3, pc}
 *   @0x22307c ldr r0, [pc, #0x10]
 *   @0x223080 movw r1, #0x200a
 *   @0x223084 add r0, pc, r0
 *   @0x223088 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x22308c pop {r3, lr}
 *   @0x223090 b 0x2225cc <_alutCreateBufferFromInputStream>
 *   @0x223094 andseq r2, sp, r4, asr r2
 *
 * ══ §144/828 COggThread::Stop_Sound(int)  0x223b78  size 44  11 条（0x223b78..0x223ba4）
 * @func 0x223b78 0x223ba4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x804×1 / 0x2d6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223b78 push {r3, r4, r5, lr}
 *   @0x223b7c add r1, r1, r1, lsl #1
 *   @0x223b80 ldr r3, [r0, #0x804]
 *   @0x223b84 mov r4, r0
 *   @0x223b88 add r5, r3, r1, lsl #8
 *   @0x223b8c bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223b90 mov r3, #8
 *   @0x223b94 mov r0, r4
 *   @0x223b98 strb r3, [r5, #0x2d6]
 *   @0x223b9c pop {r3, r4, r5, lr}
 *   @0x223ba0 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *
 * ══ §145/828 COggSyncThread::Stop_Sound(int)  0x224f78  size 44  11 条（0x224f78..0x224fa4）
 * @func 0x224f78 0x224fa4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x804×1 / 0x2d6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224f78 push {r3, r4, r5, lr}
 *   @0x224f7c add r1, r1, r1, lsl #1
 *   @0x224f80 ldr r3, [r0, #0x804]
 *   @0x224f84 mov r4, r0
 *   @0x224f88 add r5, r3, r1, lsl #8
 *   @0x224f8c bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224f90 mov r3, #8
 *   @0x224f94 mov r0, r4
 *   @0x224f98 strb r3, [r5, #0x2d6]
 *   @0x224f9c pop {r3, r4, r5, lr}
 *   @0x224fa0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §146/828 COggSyncThread::StartSyncGroup()  0x225c20  size 44  11 条（0x225c20..0x225c4c）
 * @func 0x225c20 0x225c5c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x80c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225c20 push {r4, lr}
 *   @0x225c24 mov r4, r0
 *   @0x225c28 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225c2c ldr r3, [r4, #0x80c]
 *   @0x225c30 mov r0, r4
 *   @0x225c34 cmp r3, #0
 *   @0x225c38 movgt r3, #1
 *   @0x225c3c strbgt r3, [r4, #0x850]
 *   @0x225c40 strbgt r3, [r4, #0x854]
 *   @0x225c44 pop {r4, lr}
 *   @0x225c48 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §147/828 ov_test_callbacks  0x231188  size 44  11 条（0x231188..0x2311b4）
 * @func 0x231188 0x2311b4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231188 push {r4, r5, r6, r7}
 *   @0x23118c mov r7, r0
 *   @0x231190 mov r6, r1
 *   @0x231194 mov r5, r2
 *   @0x231198 mov r4, r3
 *   @0x23119c mov r0, r7
 *   @0x2311a0 mov r1, r6
 *   @0x2311a4 mov r2, r5
 *   @0x2311a8 mov r3, r4
 *   @0x2311ac pop {r4, r5, r6, r7}
 *   @0x2311b0 b 0x230fbc <ov_clear+0xf8>
 *
 * ══ §148/828 oggpack_writeclear  0x23339c  size 44  11 条（0x23339c..0x2333c8）
 * @func 0x23339c 0x2333c8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23339c push {r4, lr}
 *   @0x2333a0 mov r4, r0
 *   @0x2333a4 ldr r0, [r0, #0x8]
 *   @0x2333a8 cmp r0, #0
 *   @0x2333ac beq 0x2333b4 <oggpack_writeclear+0x18>
 *   @0x2333b0 bl 0xb655c <free@plt>
 *   @0x2333b4 mov r0, r4
 *   @0x2333b8 mov r1, #0
 *   @0x2333bc mov r2, #20
 *   @0x2333c0 pop {r4, lr}
 *   @0x2333c4 b 0xb65b0 <memset@plt>
 *
 * ══ §149/828 oggpackB_look1  0x233a50  size 44  11 条（0x233a50..0x233a7c）
 * @func 0x233a50 0x233a7c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233a50 ldr r3, [r0, #0x10]
 *   @0x233a54 ldr r2, [r0]
 *   @0x233a58 cmp r2, r3
 *   @0x233a5c ldrlt r3, [r0, #0xc]
 *   @0x233a60 ldrlt r0, [r0, #0x4]
 *   @0x233a64 ldrblt r3, [r3]
 *   @0x233a68 rsblt r0, r0, #7
 *   @0x233a6c asrlt r0, r3, r0
 *   @0x233a70 andlt r0, r0, #1
 *   @0x233a74 mvnge r0, #0
 *   @0x233a78 bx lr
 *
 * ══ §150/828 CPhysicsObject::DebugRender(float)  0x2376dc  size 44  11 条（0x2376dc..0x237708）
 * @func 0x2376dc 0x237708  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsObject::DebugRenderShapes(float)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2376dc push {r3, r4, r5, lr}
 *   @0x2376e0 mov r4, r0
 *   @0x2376e4 ldr r3, [r0]
 *   @0x2376e8 mov r5, r1
 *   @0x2376ec cmp r3, #0
 *   @0x2376f0 popeq {r3, r4, r5, pc}
 *   @0x2376f4 bl 0x2372ec <_ZN14CPhysicsObject17DebugRenderShapesEf>
 *   @0x2376f8 mov r0, r4
 *   @0x2376fc mov r1, r5
 *   @0x237700 pop {r3, r4, r5, lr}
 *   @0x237704 b 0x237468 <_ZN14CPhysicsObject17DebugRenderJointsEf>
 *
 * ══ §151/828 CPhysicsWorld::GetParticleData(IBuffer*, unsigned int)  0x23a57c  size 44  11 条（0x23a57c..0x23a5a8）
 * @func 0x23a57c 0x23a5b8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int)
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a57c str lr, [sp, #-0x4]!
 *   @0x23a580 movw r12, #0x9298
 *   @0x23a584 ldr lr, [r0, #0x10]
 *   @0x23a588 movt r12, #0x1
 *   @0x23a58c sub sp, sp, #12
 *   @0x23a590 mov r3, #0
 *   @0x23a594 ldr r12, [lr, r12]
 *   @0x23a598 str r12, [sp]
 *   @0x23a59c bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii>
 *   @0x23a5a0 add sp, sp, #12
 *   @0x23a5a4 ldr pc, [sp], #4
 *
 * ══ §152/828 CPhysicsWorld::GetParticleDataParticle(int, IBuffer*, unsigned int)  0x23a5a8  size 44  11 条（0x23a5a8..0x23a5d4）
 * @func 0x23a5a8 0x23a5e4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a5a8 str lr, [sp, #-0x4]!
 *   @0x23a5ac sub sp, sp, #12
 *   @0x23a5b0 mov r12, r1
 *   @0x23a5b4 mov r1, r2
 *   @0x23a5b8 add lr, r12, #1
 *   @0x23a5bc mov r2, r3
 *   @0x23a5c0 str lr, [sp]
 *   @0x23a5c4 mov r3, r12
 *   @0x23a5c8 bl 0x23a248 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii>
 *   @0x23a5cc add sp, sp, #12
 *   @0x23a5d0 ldr pc, [sp], #4
 *
 * ══ §153/828 WeekDay(double)  0x2450e8  size 44  11 条（0x2450e8..0x245114）
 * @func 0x2450e8 0x245114  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Day(double)
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2450e8 push {r4, lr}
 *   @0x2450ec bl 0x2449d8 <_Z3Dayd>
 *   @0x2450f0 vmov.f64 d7, #4.000000e+00
 *   @0x2450f4 mov r3, #0
 *   @0x2450f8 mov r2, #0
 *   @0x2450fc movt r3, #0x401c
 *   @0x245100 pop {r4, lr}
 *   @0x245104 vmov d6, r0, r1
 *   @0x245108 vadd.f64 d6, d6, d7
 *   @0x24510c vmov r0, r1, d6
 *   @0x245110 b 0xb66ac <fmod@plt>
 *
 * ══ §154/828 pcre_compile  0x268f88  size 44  11 条（0x268f88..0x268fb4）
 * @func 0x268f88 0x268fb4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_compile2
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x268f88 str lr, [sp, #-0x4]!
 *   @0x268f8c sub sp, sp, #12
 *   @0x268f90 mov lr, r2
 *   @0x268f94 mov r2, #0
 *   @0x268f98 ldr r12, [sp, #0x10]
 *   @0x268f9c str r3, [sp]
 *   @0x268fa0 mov r3, lr
 *   @0x268fa4 str r12, [sp, #0x4]
 *   @0x268fa8 bl 0x2679c0 <pcre_compile2>
 *   @0x268fac add sp, sp, #12
 *   @0x268fb0 ldr pc, [sp], #4
 *
 * ══ §155/828 spIkConstraintTimeline_setFrame  0x282f8c  size 44  11 条（0x282f8c..0x282fb8）
 * @func 0x282f8c 0x282fb8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282f8c vldr s14, [sp]
 *   @0x282f90 vcvt.f32.s32 s15, s14
 *   @0x282f94 add r1, r1, r1, lsl #1
 *   @0x282f98 ldr r12, [r0, #0x10]
 *   @0x282f9c add r0, r1, #1
 *   @0x282fa0 add r1, r12, r1, lsl #2
 *   @0x282fa4 add r0, r12, r0, lsl #2
 *   @0x282fa8 str r2, [r1]
 *   @0x282fac str r3, [r0]
 *   @0x282fb0 vstr s15, [r0, #4]
 *   @0x282fb4 bx lr
 *
 * ══ §156/828 _spTrackEntry_dispose  0x2830f8  size 44  11 条（0x2830f8..0x283124）
 * @func 0x2830f8 0x283124  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2830f8 push {r4, lr}
 *   @0x2830fc mov r4, r0
 *   @0x283100 ldr r0, [r0, #0x8]
 *   @0x283104 cmp r0, #0
 *   @0x283108 beq 0x283118 <_spTrackEntry_dispose+0x20>
 *   @0x28310c ldr r3, [r4]
 *   @0x283110 ldr r3, [r3, #0x20]
 *   @0x283114 blx r3
 *   @0x283118 mov r0, r4
 *   @0x28311c pop {r4, lr}
 *   @0x283120 b 0x285c80 <_free>
 *
 * ══ §157/828 _FromEntry_create  0x283afc  size 44  11 条（0x283afc..0x283b28）
 * @func 0x283afc 0x283b28  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283afc ldr r2, [pc, #0x20]
 *   @0x283b00 mov r1, #12
 *   @0x283b04 push {r4, lr}
 *   @0x283b08 add r2, pc, r2
 *   @0x283b0c mov r4, r0
 *   @0x283b10 mov r3, #63
 *   @0x283b14 mov r0, #1
 *   @0x283b18 bl 0x285c4c <_calloc>
 *   @0x283b1c str r4, [r0]
 *   @0x283b20 pop {r4, pc}
 *   @0x283b24 strheq r3, [sp], -r12
 *
 * ══ §158/828 Java_com_yoyogames_runner_RunnerJNILib_GetAppID  0x292614  size 44  11 条（0x292614..0x292640）
 * @func 0x292614 0x292650  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 0xc×1 / 0x29c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292614 push {r4, lr}
 *   @0x292618 mov r4, r0
 *   @0x29261c bl 0x290614 <setJNIEnv>
 *   @0x292620 ldr r3, [r4]
 *   @0x292624 mov r0, r4
 *   @0x292628 ldr r1, [pc, #0xc]
 *   @0x29262c ldr r3, [r3, #0x29c]
 *   @0x292630 add r1, pc, r1
 *   @0x292634 blx r3
 *   @0x292638 pop {r4, pc}
 *   @0x29263c andeq r6, r12, r8, lsr r9
 *
 * ══ §159/828 android_getCpuFamily  0x2a2e90  size 44  11 条（0x2a2e90..0x2a2ebc）
 * @func 0x2a2e90 0x2a2ecc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6e98
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2e90 push {r4, lr}
 *   @0x2a2e94 ldr r4, [pc, #0x18]
 *   @0x2a2e98 ldr r1, [pc, #0x18]
 *   @0x2a2e9c add r4, pc, r4
 *   @0x2a2ea0 add r1, pc, r1
 *   @0x2a2ea4 add r0, r4, #16
 *   @0x2a2ea8 bl 0xb6e98 <pthread_once@plt>
 *   @0x2a2eac ldr r0, [r4]
 *   @0x2a2eb0 pop {r4, pc}
 *   @0x2a2eb4 subeq r6, r11, r4, lsr r2
 *   @0x2a2eb8 .word 0xffffffc4
 *
 * ══ §160/828 android_getCpuFeatures  0x2a2ebc  size 44  11 条（0x2a2ebc..0x2a2ee8）
 * @func 0x2a2ebc 0x2a2ee8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6e98
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2ebc push {r4, lr}
 *   @0x2a2ec0 ldr r4, [pc, #0x18]
 *   @0x2a2ec4 ldr r1, [pc, #0x18]
 *   @0x2a2ec8 add r4, pc, r4
 *   @0x2a2ecc add r1, pc, r1
 *   @0x2a2ed0 add r0, r4, #16
 *   @0x2a2ed4 bl 0xb6e98 <pthread_once@plt>
 *   @0x2a2ed8 ldrd r0, r1, [r4, #8]
 *   @0x2a2edc pop {r4, pc}
 *   @0x2a2ee0 subeq r6, r11, r8, lsl #4
 *   @0x2a2ee4 .word 0xffffff98
 *
 * ══ §161/828 zip_source_function  0x2a59ca  size 44  11 条（0x2a59ca..0x2a59f6）
 * @func 0x2a59ca 0x2a5a06  size 60  15 条
 * 部分覆盖: 本节 12/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a59ca push {r3, r4, r5, r6, r7, lr}
 *   @0x2a59ce mov r7, r2
 *   @0x2a59d2 cbz r0, 0x2a59f4 <zip_source_function+0x2a>
 *   @0x2a59d6 blx 0xb6544 <malloc@plt>
 *   @0x2a59da mov r4, r0
 *   @0x2a59de add.w r0, r5, #0xc
 *   @0x2a59e2 movs r1, #0xe
 *   @0x2a59e6 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a59ea b 0x2a59f0 <zip_source_function+0x26>
 *   @0x2a59ee strtmi r0, [r0], -r0, asr #1
 *   @0x2a59f2 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §162/828 _zip_unchange_data(zip_entry*)  0x2a59f6  size 44  11 条（0x2a59f6..0x2a5a22）
 * @func 0x2a59f6 0x2a5a22  size 44  11 条
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a59f6 push {r3, r4, r5, lr}
 *   @0x2a59fa ldr r3, [r0, #0x4]
 *   @0x2a59fe movs r1, #0x0
 *   @0x2a5a02 ldr r0, [r3, #0x4]
 *   @0x2a5a06 movs r3, #0x5
 *   @0x2a5a0a ldr r0, [r4, #0x4]
 *   @0x2a5a0e movwhs lr, #0xda6
 *   @0x2a5a12 str r3, [r4, #0x4]
 *   @0x2a5a16 cmp r3, #0x0
 *   @0x2a5a1a movne r3, #0x4
 *   @0x2a5a1e str r3, [r4]
 *
 * ══ §163/828 png_info_init_3  0x2a5b38  size 44  11 条（0x2a5b38..0x2a5b64）
 * @func 0x2a5b38 0x2a5b74  size 60  15 条
 * 部分覆盖: 本节 13/24 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/22 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_create_struct
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5b38 push {r4, lr}
 *   @0x2a5b3c ldr r0, [r0]
 *   @0x2a5b40 cmp.w r1, #0x120
 *   @0x2a5b44 bhs 0x2a5b54 <png_info_init_3+0x1c>
 *   @0x2a5b48 mulhs r2, pc, r8
 *   @0x2a5b4c bl 0x2a6c56 <png_create_struct>
 *   @0x2a5b50 str r0, [r4]
 *   @0x2a5b54 movs r1, #0x0
 *   @0x2a5b58 pop {r4, r7, r9, r12, sp, lr}
 *   @0x2a5b5c .word 0xf0754010
 *   @0x2a5b60 ldclt p15, c11, [r0, #-724]
 *
 * ══ §164/828 png_create_info_struct  0x2a5b64  size 44  11 条（0x2a5b64..0x2a5b90）
 * @func 0x2a5b64 0x2a5ba0  size 60  15 条
 * 部分覆盖: 本节 15/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/23 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/22 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_create_struct_2
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5b64 push {r0, r1, r2, lr}
 *   @0x2a5b68 cbz r0, 0x2a5b8a <png_create_info_struct+0x26>
 *   @0x2a5b6c ldr.w r1, [r3, #0x2ec]
 *   @0x2a5b70 ldr.w r2, [r3, #0x2e8]
 *   @0x2a5b74 bl 0x2a6c02 <png_create_struct_2>
 *   @0x2a5b78 str r0, [sp, #0x4]
 *   @0x2a5b7c add r0, sp, #0x4
 *   @0x2a5b80 .word 0xf7ff7190
 *   @0x2a5b84 stmdals r1, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a5b88 b 0x2a5b8a <png_create_info_struct+0x26>
 *   @0x2a5b8c ldr pc, [sp], #4
 *
 * ══ §165/828 png_default_read_data  0x2a8004  size 44  11 条（0x2a8004..0x2a8030）
 * @func 0x2a8004 0x2a8040  size 60  15 条
 * 部分覆盖: 本节 15/28 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/26 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/24 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/22 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8
 * 字段偏移 top8: 0xc×1 / 0x348×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8004 push {r3, r4, r5, lr}
 *   @0x2a8008 mov r4, r0
 *   @0x2a800c mov r0, r1
 *   @0x2a8010 .word 0x21013118
 *   @0x2a8014 blx 0xb68c8 <fread@plt>
 *   @0x2a8018 cmp r0, r5
 *   @0x2a801c ldr r1, [pc, #0xc]
 *   @0x2a8020 pop.w {r3, r4, r5, lr}
 *   @0x2a8024 add r1, pc
 *   @0x2a8028 vldmdblt r8!, {s22}
 *   @0x2a802c ldr r0, [pc, #0x348]
 *
 * ══ §166/828 png_set_rows  0x2af52c  size 44  11 条（0x2af52c..0x2af558）
 * @func 0x2af52c 0x2af568  size 60  15 条
 * 部分覆盖: 本节 15/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/24 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free_data
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af52c push {r3, r4, r5, lr}
 *   @0x2af530 mov r5, r2
 *   @0x2af534 cbz r1, 0x2af556 <png_set_rows+0x2a>
 *   @0x2af538 strdlt r3, r4, [r11, -r8]!
 *   @0x2af53c cmp r3, r2
 *   @0x2af540 movs r2, #0x40
 *   @0x2af544 bl 0x2a5bc0 <png_free_data>
 *   @0x2af548 str.w r5, [r4, #0xf8]
 *   @0x2af54c cbz r5, 0x2af556 <png_set_rows+0x2a>
 *   @0x2af550 orr r3, r3, #0x8000
 *   @0x2af554 str r3, [r4, #0x8]
 *
 * ══ §167/828 png_default_write_data  0x2afbb8  size 44  11 条（0x2afbb8..0x2afbe4）
 * @func 0x2afbb8 0x2afbe4  size 44  11 条
 * 部分覆盖: 本节 11/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68bc
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afbb8 push {r3, r4, r5, lr}
 *   @0x2afbbc mov r4, r0
 *   @0x2afbc0 mov r0, r1
 *   @0x2afbc4 .word 0x21013118
 *   @0x2afbc8 blx 0xb68bc <fwrite@plt>
 *   @0x2afbcc cmp r0, r5
 *   @0x2afbd0 ldr r1, [pc, #0xc]
 *   @0x2afbd4 pop.w {r3, r4, r5, lr}
 *   @0x2afbd8 add r1, pc
 *   @0x2afbdc ldclt p12, c11, [r8, #-156]!
 *   @0x2afbe0 b 0x2b00cc <png_write_end+0xa0>
 *
 * ══ §168/828 png_set_compression_method  0x2b0910  size 44  11 条（0x2b0910..0x2b093c）
 * @func 0x2b0910 0x2b093c  size 44  11 条
 * 部分覆盖: 本节 11/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0910 push {r3, r4, r5, lr}
 *   @0x2b0914 mov r4, r0
 *   @0x2b0918 cmp r1, #0x8
 *   @0x2b091c ldr r1, [pc, #0x18]
 *   @0x2b0920 bl 0x2a6474 <png_warning>
 *   @0x2b0924 ldr.w r3, [r4, #0x130]
 *   @0x2b0928 str.w r5, [r4, #0x17c]
 *   @0x2b092c orr r3, r3, #0x10
 *   @0x2b0930 str.w r3, [r4, #0x130]
 *   @0x2b0934 pop {r3, r4, r5, pc}
 *   @0x2b0938 bvc 0x2b0882 <png_set_filter+0x172>
 *
 * ══ §169/828 jpeg_destroy  0x2bc8b8  size 44  11 条（0x2bc8b8..0x2bc8e4）
 * @func 0x2bc8b8 0x2bc8f4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc8b8 ldr r3, [r0, #0x4]
 *   @0x2bc8bc push {r4, lr}
 *   @0x2bc8c0 cmp r3, #0
 *   @0x2bc8c4 mov r4, r0
 *   @0x2bc8c8 beq 0x2bc8d4 <jpeg_destroy+0x1c>
 *   @0x2bc8cc ldr r3, [r3, #0x28]
 *   @0x2bc8d0 blx r3
 *   @0x2bc8d4 mov r3, #0
 *   @0x2bc8d8 str r3, [r4, #0x4]
 *   @0x2bc8dc str r3, [r4, #0x14]
 *   @0x2bc8e0 pop {r4, pc}
 *
 * ══ §170/828 b2EdgeAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2cc4f4  size 44  11 条（0x2cc4f4..0x2cc520）
 * @func 0x2cc4f4 0x2cc520  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc4f4 push {r3, r4, r5, lr}
 *   @0x2cc4f8 mov r5, r1
 *   @0x2cc4fc ldr r3, [r0]
 *   @0x2cc500 mov r4, r0
 *   @0x2cc504 ldr r3, [r3, #0x4]
 *   @0x2cc508 blx r3
 *   @0x2cc50c mov r0, r5
 *   @0x2cc510 mov r1, r4
 *   @0x2cc514 mov r2, #148
 *   @0x2cc518 pop {r3, r4, r5, lr}
 *   @0x2cc51c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §171/828 b2EdgeAndPolygonContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2cc604  size 44  11 条（0x2cc604..0x2cc630）
 * @func 0x2cc604 0x2cc630  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc604 push {r3, r4, r5, lr}
 *   @0x2cc608 mov r5, r1
 *   @0x2cc60c ldr r3, [r0]
 *   @0x2cc610 mov r4, r0
 *   @0x2cc614 ldr r3, [r3, #0x4]
 *   @0x2cc618 blx r3
 *   @0x2cc61c mov r0, r5
 *   @0x2cc620 mov r1, r4
 *   @0x2cc624 mov r2, #148
 *   @0x2cc628 pop {r3, r4, r5, lr}
 *   @0x2cc62c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §172/828 b2PolygonAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2cc714  size 44  11 条（0x2cc714..0x2cc740）
 * @func 0x2cc714 0x2cc740  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc714 push {r3, r4, r5, lr}
 *   @0x2cc718 mov r5, r1
 *   @0x2cc71c ldr r3, [r0]
 *   @0x2cc720 mov r4, r0
 *   @0x2cc724 ldr r3, [r3, #0x4]
 *   @0x2cc728 blx r3
 *   @0x2cc72c mov r0, r5
 *   @0x2cc730 mov r1, r4
 *   @0x2cc734 mov r2, #148
 *   @0x2cc738 pop {r3, r4, r5, lr}
 *   @0x2cc73c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §173/828 b2PolygonContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2cc824  size 44  11 条（0x2cc824..0x2cc850）
 * @func 0x2cc824 0x2cc850  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc824 push {r3, r4, r5, lr}
 *   @0x2cc828 mov r5, r1
 *   @0x2cc82c ldr r3, [r0]
 *   @0x2cc830 mov r4, r0
 *   @0x2cc834 ldr r3, [r3, #0x4]
 *   @0x2cc838 blx r3
 *   @0x2cc83c mov r0, r5
 *   @0x2cc840 mov r1, r4
 *   @0x2cc844 mov r2, #148
 *   @0x2cc848 pop {r3, r4, r5, lr}
 *   @0x2cc84c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §174/828 b2PulleyJoint::GetReactionForce(float) const  0x2d06a4  size 44  11 条（0x2d06a4..0x2d06d0）
 * @func 0x2d06a4 0x2d06d0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d06a4 vldr s14, [r1, #116]
 *   @0x2d06a8 vldr s13, [r1, #140]
 *   @0x2d06ac vldr s12, [r1, #136]
 *   @0x2d06b0 vmul.f32 s13, s14, s13
 *   @0x2d06b4 vmov s15, r2
 *   @0x2d06b8 vmul.f32 s14, s14, s12
 *   @0x2d06bc vmul.f32 s13, s15, s13
 *   @0x2d06c0 vmul.f32 s15, s15, s14
 *   @0x2d06c4 vstr s13, [r0, #4]
 *   @0x2d06c8 vstr s15, [r0]
 *   @0x2d06cc bx lr
 *
 * ══ §175/828 b2VoronoiDiagram::~b2VoronoiDiagram()  0x2dbb68  size 44  11 条（0x2dbb68..0x2dbb94）
 * @func 0x2dbb68 0x2dbba4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Free(void*)×2
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dbb68 ldr r1, [r0, #0x14]
 *   @0x2dbb6c push {r4, lr}
 *   @0x2dbb70 cmp r1, #0
 *   @0x2dbb74 mov r4, r0
 *   @0x2dbb78 beq 0x2dbb84 <_ZN16b2VoronoiDiagramD2Ev+0x1c>
 *   @0x2dbb7c ldr r0, [r0]
 *   @0x2dbb80 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2dbb84 ldm r4, {r0, r1}
 *   @0x2dbb88 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2dbb8c mov r0, r4
 *   @0x2dbb90 pop {r4, pc}
 *
 * ══ §176/828 b2BroadPhase::DestroyProxy(int)  0x2dc924  size 44  11 条（0x2dc924..0x2dc950）
 * @func 0x2dc924 0x2dc950  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BroadPhase::UnBufferMove(int)
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc924 push {r3, r4, r5, lr}
 *   @0x2dc928 mov r4, r0
 *   @0x2dc92c mov r5, r1
 *   @0x2dc930 bl 0x2dc8e4 <_ZN12b2BroadPhase12UnBufferMoveEi>
 *   @0x2dc934 ldr r3, [r4, #0x1c]
 *   @0x2dc938 mov r1, r5
 *   @0x2dc93c mov r0, r4
 *   @0x2dc940 sub r3, r3, #1
 *   @0x2dc944 str r3, [r4, #0x1c]
 *   @0x2dc948 pop {r3, r4, r5, lr}
 *   @0x2dc94c b 0x2df640 <_ZN13b2DynamicTree12DestroyProxyEi>
 *
 * ══ §177/828 b2ChainAndCircleContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2e1d44  size 44  11 条（0x2e1d44..0x2e1d70）
 * @func 0x2e1d44 0x2e1d70  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1d44 push {r3, r4, r5, lr}
 *   @0x2e1d48 mov r5, r1
 *   @0x2e1d4c ldr r3, [r0]
 *   @0x2e1d50 mov r4, r0
 *   @0x2e1d54 ldr r3, [r3, #0x4]
 *   @0x2e1d58 blx r3
 *   @0x2e1d5c mov r0, r5
 *   @0x2e1d60 mov r1, r4
 *   @0x2e1d64 mov r2, #148
 *   @0x2e1d68 pop {r3, r4, r5, lr}
 *   @0x2e1d6c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §178/828 b2ChainAndPolygonContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2e1ed0  size 44  11 条（0x2e1ed0..0x2e1efc）
 * @func 0x2e1ed0 0x2e1efc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1ed0 push {r3, r4, r5, lr}
 *   @0x2e1ed4 mov r5, r1
 *   @0x2e1ed8 ldr r3, [r0]
 *   @0x2e1edc mov r4, r0
 *   @0x2e1ee0 ldr r3, [r3, #0x4]
 *   @0x2e1ee4 blx r3
 *   @0x2e1ee8 mov r0, r5
 *   @0x2e1eec mov r1, r4
 *   @0x2e1ef0 mov r2, #148
 *   @0x2e1ef4 pop {r3, r4, r5, lr}
 *   @0x2e1ef8 b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §179/828 b2CircleContact::Destroy(b2Contact*, b2BlockAllocator*)  0x2e1ff4  size 44  11 条（0x2e1ff4..0x2e2020）
 * @func 0x2e1ff4 0x2e2020  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1ff4 push {r3, r4, r5, lr}
 *   @0x2e1ff8 mov r5, r1
 *   @0x2e1ffc ldr r3, [r0]
 *   @0x2e2000 mov r4, r0
 *   @0x2e2004 ldr r3, [r3, #0x4]
 *   @0x2e2008 blx r3
 *   @0x2e200c mov r0, r5
 *   @0x2e2010 mov r1, r4
 *   @0x2e2014 mov r2, #148
 *   @0x2e2018 pop {r3, r4, r5, lr}
 *   @0x2e201c b 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *
 * ══ §180/828 b2GearJoint::GetReactionForce(float) const  0x2e3aac  size 44  11 条（0x2e3aac..0x2e3ad8）
 * @func 0x2e3aac 0x2e3ae8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3aac vldr s14, [r1, #156]
 *   @0x2e3ab0 vldr s13, [r1, #244]
 *   @0x2e3ab4 vldr s12, [r1, #240]
 *   @0x2e3ab8 vmul.f32 s13, s14, s13
 *   @0x2e3abc vmov s15, r2
 *   @0x2e3ac0 vmul.f32 s14, s14, s12
 *   @0x2e3ac4 vmul.f32 s13, s15, s13
 *   @0x2e3ac8 vmul.f32 s15, s15, s14
 *   @0x2e3acc vstr s13, [r0, #4]
 *   @0x2e3ad0 vstr s15, [r0]
 *   @0x2e3ad4 bx lr
 *
 * ══ §181/828 anon_2e5d38  0x2e5d38  size 44  11 条（0x2e5d38..0x2e5d64）
 * @func 0x2e5d38 0x2e5d64  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5d38 bvs 0xfe413300 <b2_toiTime+0xfffffffffdcb9e5c>
 *   @0x2e5d3c andhs r11, r0, r12, lsl #18
 *   @0x2e5d40 bvs 0x1495308 <b2_toiTime+0xd3be64>
 *   @0x2e5d44 streq lr, [r6], r4, lsl #22
 *   @0x2e5d48 .word 0x462542b4
 *   @0x2e5d4c .word 0xf854d2f7
 *   @0x2e5d50 stmvs r3, {r2, r8, r9, r11}
 *   @0x2e5d54 svchs #0xa0f5b3
 *   @0x2e5d58 .word 0xf7ffd1f6
 *   @0x2e5d5c stmdahs lr, {r0, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e5d60 stmdavs r8!, {r1, r4, r5, r6, r7, r8, r12, lr, pc}
 *
 * ══ §182/828 FT_Outline_Get_Bitmap  0x2e651c  size 44  11 条（0x2e651c..0x2e6548）
 * @func 0x2e651c 0x2e6548  size 44  11 条
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e651c push {lr}
 *   @0x2e6520 cbz r2, 0x2e6540 <FT_Outline_Get_Bitmap+0x24>
 *   @0x2e6524 str r3, [sp, #0x8]
 *   @0x2e6528 str r2, [sp]
 *   @0x2e652c beq 0x2e6534 <FT_Outline_Get_Bitmap+0x18>
 *   @0x2e6530 cmp r3, #0x1
 *   @0x2e6534 movs r3, #0x1
 *   @0x2e6538 mov r2, sp
 *   @0x2e653c and pc, r0, r5, asr #31
 *   @0x2e6540 movs r0, #0x6
 *   @0x2e6544 ldr pc, [sp], #4
 *
 * ══ §183/828 _zip_dirent_init(zip_dirent*)  0x2a3c2c  size 42  11 条（0x2a3c2c..0x2a3c56）
 * @func 0x2a3c2c 0x2a3c58  size 44  11 条
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0x10×1 / 0x18×1 / 0x20×1 / 0x28×1 / 0x2e×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3c2c movs r3, #0x0
 *   @0x2a3c30 strh r3, [r0]
 *   @0x2a3c34 strh r3, [r0, #0x4]
 *   @0x2a3c38 str r3, [r0, #0x8]
 *   @0x2a3c3c str r3, [r0, #0x10]
 *   @0x2a3c40 str r3, [r0, #0x18]
 *   @0x2a3c44 str r3, [r0, #0x20]
 *   @0x2a3c48 str r3, [r0, #0x28]
 *   @0x2a3c4c strh r3, [r0, #0x2e]
 *   @0x2a3c50 str r3, [r0, #0x34]
 *   @0x2a3c54 bx lr
 *
 * ══ §184/828 _zip_memdup(void const*, unsigned int, zip_error*)  0x2a4978  size 42  11 条（0x2a4978..0x2a49a2）
 * @func 0x2a4978 0x2a49a4  size 44  11 条
 * 部分覆盖: 本节 11/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4978 push {r3, r4, r5, r6, r7, lr}
 *   @0x2a497c mov r0, r1
 *   @0x2a4980 mov r7, r2
 *   @0x2a4984 strmi lr, [r4], -r0, ror #27
 *   @0x2a4988 cbnz r0, 0x2a4996 <_Z11_zip_memdupPKvjP9zip_error+0x1e>
 *   @0x2a498c movs r1, #0xe
 *   @0x2a4990 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4994 b 0x2a499e <_Z11_zip_memdupPKvjP9zip_error+0x26>
 *   @0x2a4998 mov r2, r5
 *   @0x2a499c qadd16mi lr, r0, r0
 *   @0x2a49a0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §185/828 png_64bit_product  0x2a603c  size 42  11 条（0x2a603c..0x2a6066）
 * @func 0x2a603c 0x2a6068  size 44  11 条
 * 部分覆盖: 本节 11/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a603c push {r4, r5, r6, lr}
 *   @0x2a6040 lsrs r5, r1, #0x10
 *   @0x2a6044 uxth r1, r1
 *   @0x2a6048 msrmi SPSR_f, #0, #12
 *   @0x2a604c mla r0, r1, r4, r0
 *   @0x2a6050 muls r4, r5, r4
 *   @0x2a6054 adcslt r4, r6, #22
 *   @0x2a6058 add.w r4, r4, r0, lsr #16
 *   @0x2a605c orr.w r6, r6, r0, lsl #16
 *   @0x2a6060 str r4, [r2]
 *   @0x2a6064 pop {r4, r5, r6, pc}
 *
 * ══ §186/828 png_destroy_struct_2  0x2a6c5e  size 42  11 条（0x2a6c5e..0x2a6c88）
 * @func 0x2a6c5e 0x2a6c8a  size 44  11 条
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6c5e push {lr}
 *   @0x2a6c62 sub.w sp, sp, #0x33c
 *   @0x2a6c66 mov r1, r0
 *   @0x2a6c6a cbz r3, 0x2a6c74 <png_destroy_struct_2+0x16>
 *   @0x2a6c6e str r2, [sp, #0x2e8]
 *   @0x2a6c72 b 0x2a6c80 <png_destroy_struct_2+0x22>
 *   @0x2a6c76 .word 0xf85d7d4f
 *   @0x2a6c7a .word 0xf074eb04
 *   @0x2a6c7e .word 0xf50dbf1e
 *   @0x2a6c82 .word 0xf85d7d4f
 *   @0x2a6c86 .word 0x2100fb04
 *
 * ══ §187/828 ft_mem_dup  0x2e8898  size 42  11 条（0x2e8898..0x2e88c2）
 * @func 0x2e8898 0x2e88d2  size 58  15 条
 * 部分覆盖: 本节 12/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_qalloc / 0xb65bc
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8898 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e889c mov r4, r2
 *   @0x2e88a0 add r2, sp, #0x4
 *   @0x2e88a4 bl 0x2e7100 <ft_mem_qalloc>
 *   @0x2e88a8 ldr r2, [sp, #0x4]
 *   @0x2e88ac cbnz r2, 0x2e88b8 <ft_mem_dup+0x20>
 *   @0x2e88b0 mov r1, r5
 *   @0x2e88b4 blx 0xb65bc <memcpy@plt>
 *   @0x2e88b8 ldr r3, [sp, #0x4]
 *   @0x2e88bc str r3, [r6]
 *   @0x2e88c0 pop {r4, r5, r6, r7, pc}
 *
 * ══ §188/828 FT_Bitmap_Done  0x314e1c  size 42  11 条（0x314e1c..0x314e46）
 * @func 0x314e1c 0x314e48  size 44  11 条
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x314e1c push {r3, r4, r5, lr}
 *   @0x314e20 cbz r0, 0x314e3e <FT_Bitmap_Done+0x22>
 *   @0x314e24 movs r5, #0x0
 *   @0x314e28 ldr r1, [r1, #0xc]
 *   @0x314e2c rscvs pc, r5, r4, lsl #21
 *   @0x314e30 mov r0, r4
 *   @0x314e34 movs r2, #0x18
 *   @0x314e38 .word 0x4628ebbc
 *   @0x314e3c pop {r3, r4, r5, pc}
 *   @0x314e40 pop {r3, r4, r5, pc}
 *   @0x314e44 pop {r3, r4, r5, pc}
 *
 * ══ §189/828 CSkeletonInstance::GetNumBoundingBoxAttachments()  0xbeedc  size 40  10 条（0xbeedc..0xbef04）
 * @func 0xbeedc 0xbef04  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_update
 * 字段偏移 top8: 0x20×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbeedc push {r4, lr}
 *   @0xbeee0 mov r4, r0
 *   @0xbeee4 mov r2, #1
 *   @0xbeee8 ldr r0, [r0, #0x20]
 *   @0xbeeec ldr r1, [r4, #0x1c]
 *   @0xbeef0 bl 0x28a8b4 <spSkeletonBounds_update>
 *   @0xbeef4 ldr r0, [r4, #0x20]
 *   @0xbeef8 cmp r0, #0
 *   @0xbeefc ldrne r0, [r0]
 *   @0xbef00 pop {r4, pc}
 *
 * ══ §190/828 CBackground::CBackground()  0xc2b58  size 40  10 条（0xc2b58..0xc2b80）
 * @func 0xc2b58 0xc2b80  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear()
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2b58 push {r4, lr}
 *   @0xc2b5c mov r3, #0
 *   @0xc2b60 mov r4, r0
 *   @0xc2b64 mvn r2, #0
 *   @0xc2b68 str r3, [r0, #0x10]
 *   @0xc2b6c str r2, [r0, #0xc]
 *   @0xc2b70 strb r3, [r0, #0x18]
 *   @0xc2b74 bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2b78 mov r0, r4
 *   @0xc2b7c pop {r4, pc}
 *
 * ══ §191/828 tagIConsole::~tagIConsole()  0xc43b4  size 40  10 条（0xc43b4..0xc43dc）
 * @func 0xc43b4 0xc43ec  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc43b4 ldr r3, [pc, #0x1c]
 *   @0xc43b8 push {r4, lr}
 *   @0xc43bc ldr r3, [pc, r3]
 *   @0xc43c0 mov r4, r0
 *   @0xc43c4 add r3, r3, #8
 *   @0xc43c8 str r3, [r0]
 *   @0xc43cc bl 0x27d1d0 <_ZdlPv>
 *   @0xc43d0 mov r0, r4
 *   @0xc43d4 pop {r4, pc}
 *   @0xc43d8 eorseq r9, r2, r4, lsr #11
 *
 * ══ §192/828 DummyConsole::~DummyConsole()  0xc43dc  size 40  10 条（0xc43dc..0xc4404）
 * @func 0xc43dc 0xc4404  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc43dc ldr r3, [pc, #0x1c]
 *   @0xc43e0 push {r4, lr}
 *   @0xc43e4 ldr r3, [pc, r3]
 *   @0xc43e8 mov r4, r0
 *   @0xc43ec add r3, r3, #8
 *   @0xc43f0 str r3, [r0]
 *   @0xc43f4 bl 0x27d1d0 <_ZdlPv>
 *   @0xc43f8 mov r0, r4
 *   @0xc43fc pop {r4, pc}
 *   @0xc4400 eorseq r9, r2, r12, ror r5
 *
 * ══ §193/828 TConsole::~TConsole()  0xc4840  size 40  10 条（0xc4840..0xc4868）
 * @func 0xc4840 0xc4878  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4840 ldr r3, [pc, #0x1c]
 *   @0xc4844 push {r4, lr}
 *   @0xc4848 ldr r3, [pc, r3]
 *   @0xc484c mov r4, r0
 *   @0xc4850 add r3, r3, #8
 *   @0xc4854 str r3, [r0]
 *   @0xc4858 bl 0x27d1d0 <_ZdlPv>
 *   @0xc485c mov r0, r4
 *   @0xc4860 pop {r4, pc}
 *   @0xc4864 eorseq r9, r2, r8, lsl r1
 *
 * ══ §194/828 TRelConsole::~TRelConsole()  0xc4868  size 40  10 条（0xc4868..0xc4890）
 * @func 0xc4868 0xc4890  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4868 ldr r3, [pc, #0x1c]
 *   @0xc486c push {r4, lr}
 *   @0xc4870 ldr r3, [pc, r3]
 *   @0xc4874 mov r4, r0
 *   @0xc4878 add r3, r3, #8
 *   @0xc487c str r3, [r0]
 *   @0xc4880 bl 0x27d1d0 <_ZdlPv>
 *   @0xc4884 mov r0, r4
 *   @0xc4888 pop {r4, pc}
 *   @0xc488c ldrshteq r9, [r2], -r0
 *
 * ══ §195/828 Buffer_Fast::~Buffer_Fast()  0xc4bcc  size 40  10 条（0xc4bcc..0xc4bf4）
 * @func 0xc4bcc 0xc4bf4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4bcc ldr r3, [pc, #0x1c]
 *   @0xc4bd0 push {r4, lr}
 *   @0xc4bd4 ldr r3, [pc, r3]
 *   @0xc4bd8 mov r4, r0
 *   @0xc4bdc add r3, r3, #8
 *   @0xc4be0 str r3, [r0]
 *   @0xc4be4 bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xc4be8 mov r0, r4
 *   @0xc4bec pop {r4, pc}
 *   @0xc4bf0 ldrsbteq r8, [r2], -r8
 *
 * ══ §196/828 Buffer_Standard::~Buffer_Standard()  0xc4d08  size 40  10 条（0xc4d08..0xc4d30）
 * @func 0xc4d08 0xc4d30  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4d08 ldr r3, [pc, #0x1c]
 *   @0xc4d0c push {r4, lr}
 *   @0xc4d10 ldr r3, [pc, r3]
 *   @0xc4d14 mov r4, r0
 *   @0xc4d18 add r3, r3, #8
 *   @0xc4d1c str r3, [r0]
 *   @0xc4d20 bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xc4d24 mov r0, r4
 *   @0xc4d28 pop {r4, pc}
 *   @0xc4d2c eorseq r8, r2, r0, lsr #25
 *
 * ══ §197/828 Buffer_Network::~Buffer_Network()  0xcacec  size 40  10 条（0xcacec..0xcad14）
 * @func 0xcacec 0xcad14  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcacec ldr r3, [pc, #0x1c]
 *   @0xcacf0 push {r4, lr}
 *   @0xcacf4 ldr r3, [pc, r3]
 *   @0xcacf8 mov r4, r0
 *   @0xcacfc add r3, r3, #8
 *   @0xcad00 str r3, [r0]
 *   @0xcad04 bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xcad08 mov r0, r4
 *   @0xcad0c pop {r4, pc}
 *   @0xcad10 eorseq r2, r2, r4, lsl lr
 *
 * ══ §198/828 IBuffer::SizeOf(eBuffer_Type)  0xcd100  size 40  10 条（0xcd100..0xcd128）
 * @func 0xcd100 0xcd128  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd100 sub r0, r0, #1
 *   @0xcd104 cmp r0, #11
 *   @0xcd108 bhi 0xcd11c <_ZN7IBuffer6SizeOfE12eBuffer_Type+0x1c>
 *   @0xcd10c ldr r3, [pc, #0x10]
 *   @0xcd110 add r3, pc, r3
 *   @0xcd114 ldr r0, [r3, r0, lsl #2]
 *   @0xcd118 bx lr
 *   @0xcd11c mov r0, #0
 *   @0xcd120 bx lr
 *   @0xcd124 eoreq pc, r8, r12, asr #13
 *
 * ══ §199/828 ResetSlotTraversalMap()  0xd5a98  size 40  10 条（0xd5a98..0xd5ac0）
 * @func 0xd5a98 0xd5ac0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd5a98 ldr r2, [pc, #0x18]
 *   @0xd5a9c mov r1, #0
 *   @0xd5aa0 ldr r3, [pc, #0x14]
 *   @0xd5aa4 ldr r2, [pc, r2]
 *   @0xd5aa8 ldr r3, [pc, r3]
 *   @0xd5aac ldr r2, [r2]
 *   @0xd5ab0 str r1, [r3, r2, lsl #2]
 *   @0xd5ab4 bx lr
 *   @0xd5ab8 eorseq r8, r1, r12, lsr #3
 *   @0xd5abc eorseq r8, r1, r12, lsr #3
 *
 * ══ §200/828 YYstrnlen(char const*, int)  0xdc3ec  size 40  10 条（0xdc3ec..0xdc414）
 * @func 0xdc3ec 0xdc414  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66a0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc3ec push {r3, r4, r5, lr}
 *   @0xdc3f0 mov r4, r1
 *   @0xdc3f4 mov r2, r4
 *   @0xdc3f8 mov r1, #0
 *   @0xdc3fc mov r5, r0
 *   @0xdc400 bl 0xb66a0 <memchr@plt>
 *   @0xdc404 cmp r0, #0
 *   @0xdc408 rsbne r0, r5, r0
 *   @0xdc40c moveq r0, r4
 *   @0xdc410 pop {r3, r4, r5, pc}
 *
 * ══ §201/828 CHashMap<unsigned char*, void**, 3>::~CHashMap()  0xec47c  size 40  10 条（0xec47c..0xec4a4）
 * @func 0xec47c 0xec4a4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec47c push {r4, lr}
 *   @0xec480 mov r4, r0
 *   @0xec484 ldr r0, [r0, #0x10]
 *   @0xec488 cmp r0, #0
 *   @0xec48c beq 0xec49c <_ZN8CHashMapIPhPPvLi3EED2Ev+0x20>
 *   @0xec490 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xec494 mov r3, #0
 *   @0xec498 str r3, [r4, #0x10]
 *   @0xec49c mov r0, r4
 *   @0xec4a0 pop {r4, pc}
 *
 * ══ §202/828 AddRealConstant(char const*, double)  0xedff4  size 40  10 条（0xedff4..0xee01c）
 * @func 0xedff4 0xee01c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddConstant(char const*, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xedff4 str lr, [sp, #-0x4]!
 *   @0xedff8 sub sp, sp, #20
 *   @0xedffc add r1, sp, #16
 *   @0xee000 mov r12, #0
 *   @0xee004 str r12, [sp, #0xc]
 *   @0xee008 strd r2, r3, [r1, #-16]!
 *   @0xee00c mov r1, sp
 *   @0xee010 bl 0xedd00 <_Z11AddConstantPKcP6RValue>
 *   @0xee014 add sp, sp, #20
 *   @0xee018 ldr pc, [sp], #4
 *
 * ══ §203/828 AddStringConstant(char const*, char const*)  0xf1748  size 40  10 条（0xf1748..0xf1770）
 * @func 0xf1748 0xf1770  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*) / AddConstant(char const*, RValue*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1748 push {r4, r5, lr}
 *   @0xf174c sub sp, sp, #20
 *   @0xf1750 mov r5, r0
 *   @0xf1754 mov r0, sp
 *   @0xf1758 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xf175c mov r0, r5
 *   @0xf1760 mov r1, sp
 *   @0xf1764 bl 0xedd00 <_Z11AddConstantPKcP6RValue>
 *   @0xf1768 add sp, sp, #20
 *   @0xf176c pop {r4, r5, pc}
 *
 * ══ §204/828 InputQuery::InputAsync(char const*, char const*, char const*)  0xf26c4  size 40  10 条（0xf26c4..0xf26ec）
 * @func 0xf26c4 0xf26fc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExitFullScreen()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf26c4 push {r4, r5, r6, lr}
 *   @0xf26c8 mov r6, r0
 *   @0xf26cc mov r5, r1
 *   @0xf26d0 mov r4, r2
 *   @0xf26d4 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xf26d8 mov r0, r6
 *   @0xf26dc mov r1, r5
 *   @0xf26e0 mov r2, r4
 *   @0xf26e4 pop {r4, r5, r6, lr}
 *   @0xf26e8 b 0xf2214 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_>
 *
 * ══ §205/828 CEvent::~CEvent()  0xf2d40  size 40  10 条（0xf2d40..0xf2d68）
 * @func 0xf2d40 0xf2d78  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEvent::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2d40 ldr r3, [pc, #0x1c]
 *   @0xf2d44 push {r4, lr}
 *   @0xf2d48 ldr r3, [pc, r3]
 *   @0xf2d4c mov r4, r0
 *   @0xf2d50 add r3, r3, #8
 *   @0xf2d54 str r3, [r0]
 *   @0xf2d58 bl 0xf2d08 <_ZN6CEvent5ClearEv>
 *   @0xf2d5c mov r0, r4
 *   @0xf2d60 pop {r4, pc}
 *   @0xf2d64 .word 0x002fb0d8
 *
 * ══ §206/828 CExtensionConstant::CExtensionConstant()  0xf4804  size 40  10 条（0xf4804..0xf482c）
 * @func 0xf4804 0xf482c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionConstant::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4804 ldr r3, [pc, #0x1c]
 *   @0xf4808 push {r4, lr}
 *   @0xf480c ldr r3, [pc, r3]
 *   @0xf4810 mov r4, r0
 *   @0xf4814 add r3, r3, #8
 *   @0xf4818 str r3, [r0]
 *   @0xf481c bl 0xf47f4 <_ZN18CExtensionConstant5ClearEv>
 *   @0xf4820 mov r0, r4
 *   @0xf4824 pop {r4, pc}
 *   @0xf4828 eoreq r9, pc, r8, lsl r6
 *
 * ══ §207/828 CExtensionFunction::CExtensionFunction()  0xf49e4  size 40  10 条（0xf49e4..0xf4a0c）
 * @func 0xf49e4 0xf4a0c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFunction::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf49e4 ldr r3, [pc, #0x1c]
 *   @0xf49e8 push {r4, lr}
 *   @0xf49ec ldr r3, [pc, r3]
 *   @0xf49f0 mov r4, r0
 *   @0xf49f4 add r3, r3, #8
 *   @0xf49f8 str r3, [r0]
 *   @0xf49fc bl 0xf4998 <_ZN18CExtensionFunction5ClearEv>
 *   @0xf4a00 mov r0, r4
 *   @0xf4a04 pop {r4, pc}
 *   @0xf4a08 eoreq r9, pc, r12, lsr r4
 *
 * ══ §208/828 CExtensionFile::GetFunction(int)  0xf4c8c  size 40  10 条（0xf4c8c..0xf4cb4）
 * @func 0xf4c8c 0xf4cc4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::GetFunction(int)+0x20
 * 字段偏移 top8: 0x1c×1 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c8c cmp r1, #0
 *   @0xf4c90 blt 0xf4cac <_ZN14CExtensionFile11GetFunctionEi+0x20>
 *   @0xf4c94 ldr r3, [r0, #0x1c]
 *   @0xf4c98 cmp r1, r3
 *   @0xf4c9c bge 0xf4cac <_ZN14CExtensionFile11GetFunctionEi+0x20>
 *   @0xf4ca0 ldr r3, [r0, #0x18]
 *   @0xf4ca4 ldr r0, [r3, r1, lsl #2]
 *   @0xf4ca8 bx lr
 *   @0xf4cac mov r0, #0
 *   @0xf4cb0 bx lr
 *
 * ══ §209/828 CExtensionFile::GetConstant(int)  0xf4d88  size 40  10 条（0xf4d88..0xf4db0）
 * @func 0xf4d88 0xf4dc0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::GetConstant(int)+0x20
 * 字段偏移 top8: 0x28×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4d88 cmp r1, #0
 *   @0xf4d8c blt 0xf4da8 <_ZN14CExtensionFile11GetConstantEi+0x20>
 *   @0xf4d90 ldr r3, [r0, #0x28]
 *   @0xf4d94 cmp r1, r3
 *   @0xf4d98 bge 0xf4da8 <_ZN14CExtensionFile11GetConstantEi+0x20>
 *   @0xf4d9c ldr r3, [r0, #0x24]
 *   @0xf4da0 ldr r0, [r3, r1, lsl #2]
 *   @0xf4da4 bx lr
 *   @0xf4da8 mov r0, #0
 *   @0xf4dac bx lr
 *
 * ══ §210/828 CExtensionPackage::GetIncludes(int)  0xf5398  size 40  10 条（0xf5398..0xf53c0）
 * @func 0xf5398 0xf53d0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::GetIncludes(int)+0x20
 * 字段偏移 top8: 0x18×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5398 cmp r1, #0
 *   @0xf539c blt 0xf53b8 <_ZN17CExtensionPackage11GetIncludesEi+0x20>
 *   @0xf53a0 ldr r3, [r0, #0x18]
 *   @0xf53a4 cmp r1, r3
 *   @0xf53a8 bge 0xf53b8 <_ZN17CExtensionPackage11GetIncludesEi+0x20>
 *   @0xf53ac ldr r3, [r0, #0x14]
 *   @0xf53b0 ldr r0, [r3, r1, lsl #2]
 *   @0xf53b4 bx lr
 *   @0xf53b8 mov r0, #0
 *   @0xf53bc bx lr
 *
 * ══ §211/828 yywcslen(unsigned short const*)  0xf6c78  size 40  10 条（0xf6c78..0xf6ca0）
 * @func 0xf6c78 0xf6ca0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6c78 mov r2, r0
 *   @0xf6c7c b 0xf6c84 <_Z8yywcslenPKt+0xc>
 *   @0xf6c80 mov r2, r3
 *   @0xf6c84 mov r3, r2
 *   @0xf6c88 ldrh r1, [r3], #2
 *   @0xf6c8c cmp r1, #0
 *   @0xf6c90 bne 0xf6c80 <_Z8yywcslenPKt+0x8>
 *   @0xf6c94 rsb r0, r0, r2
 *   @0xf6c98 asr r0, r0, #1
 *   @0xf6c9c bx lr
 *
 * ══ §212/828 YYGML_instance_create(float, float, int)  0x10b09c  size 40  10 条（0x10b09c..0x10b0c4）
 * @func 0x10b09c 0x10b0c4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Command_Create(int, float, float)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b09c push {r3, lr}
 *   @0x10b0a0 mov r3, r0
 *   @0x10b0a4 mov r0, r2
 *   @0x10b0a8 mov r2, r1
 *   @0x10b0ac mov r1, r3
 *   @0x10b0b0 bl 0x1c983c <_Z14Command_Createiff>
 *   @0x10b0b4 cmp r0, #0
 *   @0x10b0b8 ldrne r0, [r0, #0x78]
 *   @0x10b0bc mvneq r0, #0
 *   @0x10b0c0 pop {r3, pc}
 *
 * ══ §213/828 F_IsBool(RValue&, CInstance*, CInstance*, int, RValue*)  0x10da28  size 40  10 条（0x10da28..0x10da50）
 * @func 0x10da28 0x10da60  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10da28 ldr r2, [sp]
 *   @0x10da2c mov r3, #0
 *   @0x10da30 str r3, [r0, #0xc]
 *   @0x10da34 ldr r2, [r2, #0xc]
 *   @0x10da38 str r3, [r0]
 *   @0x10da3c cmp r2, #13
 *   @0x10da40 mov r2, r3
 *   @0x10da44 movteq r2, #0x3ff0
 *   @0x10da48 str r2, [r0, #0x4]
 *   @0x10da4c bx lr
 *
 * ══ §214/828 F_IsArray(RValue&, CInstance*, CInstance*, int, RValue*)  0x10da50  size 40  10 条（0x10da50..0x10da78）
 * @func 0x10da50 0x10da88  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10da50 ldr r2, [sp]
 *   @0x10da54 mov r3, #0
 *   @0x10da58 str r3, [r0, #0xc]
 *   @0x10da5c ldr r2, [r2, #0xc]
 *   @0x10da60 str r3, [r0]
 *   @0x10da64 cmp r2, #2
 *   @0x10da68 mov r2, r3
 *   @0x10da6c movteq r2, #0x3ff0
 *   @0x10da70 str r2, [r0, #0x4]
 *   @0x10da74 bx lr
 *
 * ══ §215/828 F_IsString(RValue&, CInstance*, CInstance*, int, RValue*)  0x10da78  size 40  10 条（0x10da78..0x10daa0）
 * @func 0x10da78 0x10dab0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10da78 ldr r2, [sp]
 *   @0x10da7c mov r3, #0
 *   @0x10da80 str r3, [r0, #0xc]
 *   @0x10da84 ldr r2, [r2, #0xc]
 *   @0x10da88 str r3, [r0]
 *   @0x10da8c cmp r2, #1
 *   @0x10da90 mov r2, r3
 *   @0x10da94 movteq r2, #0x3ff0
 *   @0x10da98 str r2, [r0, #0x4]
 *   @0x10da9c bx lr
 *
 * ══ §216/828 F_IsPtr(RValue&, CInstance*, CInstance*, int, RValue*)  0x10daa0  size 40  10 条（0x10daa0..0x10dac8）
 * @func 0x10daa0 0x10dad8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10daa0 ldr r2, [sp]
 *   @0x10daa4 mov r3, #0
 *   @0x10daa8 str r3, [r0, #0xc]
 *   @0x10daac ldr r2, [r2, #0xc]
 *   @0x10dab0 str r3, [r0]
 *   @0x10dab4 cmp r2, #3
 *   @0x10dab8 mov r2, r3
 *   @0x10dabc movteq r2, #0x3ff0
 *   @0x10dac0 str r2, [r0, #0x4]
 *   @0x10dac4 bx lr
 *
 * ══ §217/828 F_IsUndefined(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dac8  size 40  10 条（0x10dac8..0x10daf0）
 * @func 0x10dac8 0x10db00  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dac8 ldr r2, [sp]
 *   @0x10dacc mov r3, #0
 *   @0x10dad0 str r3, [r0, #0xc]
 *   @0x10dad4 ldr r2, [r2, #0xc]
 *   @0x10dad8 str r3, [r0]
 *   @0x10dadc cmp r2, #5
 *   @0x10dae0 mov r2, r3
 *   @0x10dae4 movteq r2, #0x3ff0
 *   @0x10dae8 str r2, [r0, #0x4]
 *   @0x10daec bx lr
 *
 * ══ §218/828 F_IsInt32(RValue&, CInstance*, CInstance*, int, RValue*)  0x10daf0  size 40  10 条（0x10daf0..0x10db18）
 * @func 0x10daf0 0x10db28  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10daf0 ldr r2, [sp]
 *   @0x10daf4 mov r3, #0
 *   @0x10daf8 str r3, [r0, #0xc]
 *   @0x10dafc ldr r2, [r2, #0xc]
 *   @0x10db00 str r3, [r0]
 *   @0x10db04 cmp r2, #7
 *   @0x10db08 mov r2, r3
 *   @0x10db0c movteq r2, #0x3ff0
 *   @0x10db10 str r2, [r0, #0x4]
 *   @0x10db14 bx lr
 *
 * ══ §219/828 F_IsInt64(RValue&, CInstance*, CInstance*, int, RValue*)  0x10db18  size 40  10 条（0x10db18..0x10db40）
 * @func 0x10db18 0x10db50  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10db18 ldr r2, [sp]
 *   @0x10db1c mov r3, #0
 *   @0x10db20 str r3, [r0, #0xc]
 *   @0x10db24 ldr r2, [r2, #0xc]
 *   @0x10db28 str r3, [r0]
 *   @0x10db2c cmp r2, #10
 *   @0x10db30 mov r2, r3
 *   @0x10db34 movteq r2, #0x3ff0
 *   @0x10db38 str r2, [r0, #0x4]
 *   @0x10db3c bx lr
 *
 * ══ §220/828 F_IsVec3(RValue&, CInstance*, CInstance*, int, RValue*)  0x10db40  size 40  10 条（0x10db40..0x10db68）
 * @func 0x10db40 0x10db78  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10db40 ldr r2, [sp]
 *   @0x10db44 mov r3, #0
 *   @0x10db48 str r3, [r0, #0xc]
 *   @0x10db4c ldr r2, [r2, #0xc]
 *   @0x10db50 str r3, [r0]
 *   @0x10db54 cmp r2, #4
 *   @0x10db58 mov r2, r3
 *   @0x10db5c movteq r2, #0x3ff0
 *   @0x10db60 str r2, [r0, #0x4]
 *   @0x10db64 bx lr
 *
 * ══ §221/828 F_IsVec4(RValue&, CInstance*, CInstance*, int, RValue*)  0x10db68  size 40  10 条（0x10db68..0x10db90）
 * @func 0x10db68 0x10dba0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10db68 ldr r2, [sp]
 *   @0x10db6c mov r3, #0
 *   @0x10db70 str r3, [r0, #0xc]
 *   @0x10db74 ldr r2, [r2, #0xc]
 *   @0x10db78 str r3, [r0]
 *   @0x10db7c cmp r2, #8
 *   @0x10db80 mov r2, r3
 *   @0x10db84 movteq r2, #0x3ff0
 *   @0x10db88 str r2, [r0, #0x4]
 *   @0x10db8c bx lr
 *
 * ══ §222/828 F_IsMatrix(RValue&, CInstance*, CInstance*, int, RValue*)  0x10db90  size 40  10 条（0x10db90..0x10dbb8）
 * @func 0x10db90 0x10dbb8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10db90 ldr r2, [sp]
 *   @0x10db94 mov r3, #0
 *   @0x10db98 str r3, [r0, #0xc]
 *   @0x10db9c ldr r2, [r2, #0xc]
 *   @0x10dba0 str r3, [r0]
 *   @0x10dba4 cmp r2, #9
 *   @0x10dba8 mov r2, r3
 *   @0x10dbac movteq r2, #0x3ff0
 *   @0x10dbb0 str r2, [r0, #0x4]
 *   @0x10dbb4 bx lr
 *
 * ══ §223/828 F_MathGetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dc70  size 40  10 条（0x10dc70..0x10dc98）
 * @func 0x10dc70 0x10dc98  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dc70 ldr r3, [pc, #0x1c]
 *   @0x10dc74 mov r2, #0
 *   @0x10dc78 str r2, [r0, #0xc]
 *   @0x10dc7c ldr r3, [pc, r3]
 *   @0x10dc80 ldr r2, [r3]
 *   @0x10dc84 str r2, [r0]
 *   @0x10dc88 ldr r3, [r3, #0x4]
 *   @0x10dc8c str r3, [r0, #0x4]
 *   @0x10dc90 bx lr
 *   @0x10dc94 mlaeq lr, r12, r0, r0
 *
 * ══ §224/828 F_Floor(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e314  size 40  10 条（0x10e314..0x10e33c）
 * @func 0x10e314 0x10e34c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6598
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e314 push {r4, lr}
 *   @0x10e318 mov r3, #0
 *   @0x10e31c mov r4, r0
 *   @0x10e320 str r3, [r0, #0xc]
 *   @0x10e324 mov r1, r3
 *   @0x10e328 ldr r0, [sp, #0x8]
 *   @0x10e32c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e330 bl 0xb6598 <floor@plt>
 *   @0x10e334 stm r4, {r0, r1}
 *   @0x10e338 pop {r4, pc}
 *
 * ══ §225/828 F_Ceil(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e33c  size 40  10 条（0x10e33c..0x10e364）
 * @func 0x10e33c 0x10e364  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb670c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e33c push {r4, lr}
 *   @0x10e340 mov r3, #0
 *   @0x10e344 mov r4, r0
 *   @0x10e348 str r3, [r0, #0xc]
 *   @0x10e34c mov r1, r3
 *   @0x10e350 ldr r0, [sp, #0x8]
 *   @0x10e354 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e358 bl 0xb670c <ceil@plt>
 *   @0x10e35c stm r4, {r0, r1}
 *   @0x10e360 pop {r4, pc}
 *
 * ══ §226/828 F_Exp(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e3a8  size 40  10 条（0x10e3a8..0x10e3d0）
 * @func 0x10e3a8 0x10e3e0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6724
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e3a8 push {r4, lr}
 *   @0x10e3ac mov r3, #0
 *   @0x10e3b0 mov r4, r0
 *   @0x10e3b4 str r3, [r0, #0xc]
 *   @0x10e3b8 mov r1, r3
 *   @0x10e3bc ldr r0, [sp, #0x8]
 *   @0x10e3c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e3c4 bl 0xb6724 <exp@plt>
 *   @0x10e3c8 stm r4, {r0, r1}
 *   @0x10e3cc pop {r4, pc}
 *
 * ══ §227/828 F_Ln(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e3d0  size 40  10 条（0x10e3d0..0x10e3f8）
 * @func 0x10e3d0 0x10e3f8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6730
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e3d0 push {r4, lr}
 *   @0x10e3d4 mov r3, #0
 *   @0x10e3d8 mov r4, r0
 *   @0x10e3dc str r3, [r0, #0xc]
 *   @0x10e3e0 mov r1, r3
 *   @0x10e3e4 ldr r0, [sp, #0x8]
 *   @0x10e3e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e3ec bl 0xb6730 <log@plt>
 *   @0x10e3f0 stm r4, {r0, r1}
 *   @0x10e3f4 pop {r4, pc}
 *
 * ══ §228/828 F_Log10(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e49c  size 40  10 条（0x10e49c..0x10e4c4）
 * @func 0x10e49c 0x10e4c4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb673c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e49c push {r4, lr}
 *   @0x10e4a0 mov r3, #0
 *   @0x10e4a4 mov r4, r0
 *   @0x10e4a8 str r3, [r0, #0xc]
 *   @0x10e4ac mov r1, r3
 *   @0x10e4b0 ldr r0, [sp, #0x8]
 *   @0x10e4b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e4b8 bl 0xb673c <log10@plt>
 *   @0x10e4bc stm r4, {r0, r1}
 *   @0x10e4c0 pop {r4, pc}
 *
 * ══ §229/828 utf8_strcpy(char*, char const*)  0x1109cc  size 40  10 条（0x1109cc..0x1109f4）
 * @func 0x1109cc 0x1109f4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1109cc push {r3, r4, r5, lr}
 *   @0x1109d0 mov r5, r0
 *   @0x1109d4 mov r0, r1
 *   @0x1109d8 mov r4, r1
 *   @0x1109dc bl 0xb6538 <strlen@plt>
 *   @0x1109e0 mov r1, r4
 *   @0x1109e4 add r2, r0, #1
 *   @0x1109e8 mov r0, r5
 *   @0x1109ec pop {r3, r4, r5, lr}
 *   @0x1109f0 b 0xb65bc <memcpy@plt>
 *
 * ══ §230/828 YYGML_ord(char const*)  0x1111b8  size 40  10 条（0x1111b8..0x1111e0）
 * @func 0x1111b8 0x1111e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char
 * 字段偏移 top8: 0x4×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1111b8 str lr, [sp, #-0x4]!
 *   @0x1111bc subs r3, r0, #0
 *   @0x1111c0 sub sp, sp, #12
 *   @0x1111c4 str r0, [sp, #0x4]
 *   @0x1111c8 moveq r0, r3
 *   @0x1111cc beq 0x1111d8 <_Z9YYGML_ordPKc+0x20>
 *   @0x1111d0 add r0, sp, #4
 *   @0x1111d4 bl 0x10fb38 <utf8_extract_char>
 *   @0x1111d8 add sp, sp, #12
 *   @0x1111dc ldr pc, [sp], #4
 *
 * ══ §231/828 F_DrawGetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*)  0x119a94  size 40  10 条（0x119a94..0x119abc）
 * @func 0x119a94 0x119abc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119a94 ldr r3, [pc, #0x1c]
 *   @0x119a98 mov r2, #0
 *   @0x119a9c str r2, [r0, #0xc]
 *   @0x119aa0 ldr r3, [pc, r3]
 *   @0x119aa4 vldr s15, [r3]
 *   @0x119aa8 vcvt.f64.f32 d6, s15
 *   @0x119aac vmov r2, r3, d6
 *   @0x119ab0 stm r0, {r2, r3}
 *   @0x119ab4 bx lr
 *   @0x119ab8 eoreq r4, sp, r8, lsl r11
 *
 * ══ §232/828 F_SurfaceGetTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c9b8  size 40  10 条（0x11c9b8..0x11c9e0）
 * @func 0x11c9b8 0x11c9e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Surface_Get_Texture(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c9b8 push {r4, lr}
 *   @0x11c9bc mov r4, r0
 *   @0x11c9c0 mov r3, #3
 *   @0x11c9c4 mov r1, #0
 *   @0x11c9c8 str r3, [r4, #0xc]
 *   @0x11c9cc ldr r0, [sp, #0x8]
 *   @0x11c9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c9d4 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11c9d8 str r0, [r4]
 *   @0x11c9dc pop {r4, pc}
 *
 * ══ §233/828 F_SpriteGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b23c  size 40  10 条（0x12b23c..0x12b264）
 * @func 0x12b23c 0x12b264  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b23c push {r4, lr}
 *   @0x12b240 mov r1, #0
 *   @0x12b244 mov r4, r0
 *   @0x12b248 ldr r0, [sp, #0x8]
 *   @0x12b24c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b250 bl 0x1eeee0 <_Z11Sprite_Namei>
 *   @0x12b254 mov r1, r0
 *   @0x12b258 mov r0, r4
 *   @0x12b25c pop {r4, lr}
 *   @0x12b260 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §234/828 F_BackgroundGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c1e0  size 40  10 条（0x12c1e0..0x12c208）
 * @func 0x12c1e0 0x12c208  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c1e0 push {r4, lr}
 *   @0x12c1e4 mov r1, #0
 *   @0x12c1e8 mov r4, r0
 *   @0x12c1ec ldr r0, [sp, #0x8]
 *   @0x12c1f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c1f4 bl 0xc3688 <_Z15Background_Namei>
 *   @0x12c1f8 mov r1, r0
 *   @0x12c1fc mov r0, r4
 *   @0x12c200 pop {r4, lr}
 *   @0x12c204 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §235/828 F_FontGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cd30  size 40  10 条（0x12cd30..0x12cd58）
 * @func 0x12cd30 0x12cd58  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cd30 push {r4, lr}
 *   @0x12cd34 mov r1, #0
 *   @0x12cd38 mov r4, r0
 *   @0x12cd3c ldr r0, [sp, #0x8]
 *   @0x12cd40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cd44 bl 0xfa2f0 <_Z9Font_Namei>
 *   @0x12cd48 mov r1, r0
 *   @0x12cd4c mov r0, r4
 *   @0x12cd50 pop {r4, lr}
 *   @0x12cd54 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §236/828 F_PathGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d3d0  size 40  10 条（0x12d3d0..0x12d3f8）
 * @func 0x12d3d0 0x12d3f8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d3d0 push {r4, lr}
 *   @0x12d3d4 mov r1, #0
 *   @0x12d3d8 mov r4, r0
 *   @0x12d3dc ldr r0, [sp, #0x8]
 *   @0x12d3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d3e4 bl 0x1a8050 <_Z9Path_Namei>
 *   @0x12d3e8 mov r1, r0
 *   @0x12d3ec mov r0, r4
 *   @0x12d3f0 pop {r4, lr}
 *   @0x12d3f4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §237/828 F_ScriptGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dde8  size 40  10 条（0x12dde8..0x12de10）
 * @func 0x12dde8 0x12de10  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Script_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dde8 push {r4, lr}
 *   @0x12ddec mov r1, #0
 *   @0x12ddf0 mov r4, r0
 *   @0x12ddf4 ldr r0, [sp, #0x8]
 *   @0x12ddf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ddfc bl 0x1e058c <_Z11Script_Namei>
 *   @0x12de00 mov r1, r0
 *   @0x12de04 mov r0, r4
 *   @0x12de08 pop {r4, lr}
 *   @0x12de0c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §238/828 F_TimeLineGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12de84  size 40  10 条（0x12de84..0x12deac）
 * @func 0x12de84 0x12deac  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12de84 push {r4, lr}
 *   @0x12de88 mov r1, #0
 *   @0x12de8c mov r4, r0
 *   @0x12de90 ldr r0, [sp, #0x8]
 *   @0x12de94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12de98 bl 0x1f2b58 <_Z13TimeLine_Namei>
 *   @0x12de9c mov r1, r0
 *   @0x12dea0 mov r0, r4
 *   @0x12dea4 pop {r4, lr}
 *   @0x12dea8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §239/828 F_ObjectGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e10c  size 40  10 条（0x12e10c..0x12e134）
 * @func 0x12e10c 0x12e134  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Object_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e10c push {r4, lr}
 *   @0x12e110 mov r1, #0
 *   @0x12e114 mov r4, r0
 *   @0x12e118 ldr r0, [sp, #0x8]
 *   @0x12e11c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e120 bl 0x19ed54 <_Z11Object_Namei>
 *   @0x12e124 mov r1, r0
 *   @0x12e128 mov r0, r4
 *   @0x12e12c pop {r4, lr}
 *   @0x12e130 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §240/828 F_RoomGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e2c0  size 40  10 条（0x12e2c0..0x12e2e8）
 * @func 0x12e2c0 0x12e2e8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Name(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e2c0 push {r4, lr}
 *   @0x12e2c4 mov r1, #0
 *   @0x12e2c8 mov r4, r0
 *   @0x12e2cc ldr r0, [sp, #0x8]
 *   @0x12e2d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e2d4 bl 0x1b530c <_Z9Room_Namei>
 *   @0x12e2d8 mov r1, r0
 *   @0x12e2dc mov r0, r4
 *   @0x12e2e0 pop {r4, lr}
 *   @0x12e2e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §241/828 F_D3DSetLighting(RValue&, CInstance*, CInstance*, int, RValue*)  0x143b68  size 40  10 条（0x143b68..0x143b90）
 * @func 0x143b68 0x143b90  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143b68 push {r3, lr}
 *   @0x143b6c mov r1, #0
 *   @0x143b70 ldr r0, [sp, #0x8]
 *   @0x143b74 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143b78 ldr r3, [pc, #0xc]
 *   @0x143b7c ldr r3, [pc, r3]
 *   @0x143b80 strb r0, [r3]
 *   @0x143b84 pop {r3, lr}
 *   @0x143b88 b 0x168484 <_Z19GR_D3D_Set_Lightingb>
 *   @0x143b8c mlaeq r10, r4, r10, r11
 *
 * ══ §242/828 F_D3DLightSetAmbient(RValue&, CInstance*, CInstance*, int, RValue*)  0x1451b0  size 40  10 条（0x1451b0..0x1451d8）
 * @func 0x1451b0 0x1451d8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1451b0 push {r3, lr}
 *   @0x1451b4 mov r1, #0
 *   @0x1451b8 ldr r0, [sp, #0x8]
 *   @0x1451bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1451c0 ldr r3, [pc, #0xc]
 *   @0x1451c4 ldr r3, [pc, r3]
 *   @0x1451c8 str r0, [r3]
 *   @0x1451cc pop {r3, lr}
 *   @0x1451d0 b 0x17f5fc <_Z17GR_3D_Set_Ambientj>
 *   @0x1451d4 eoreq r10, r10, r8, asr #8
 *
 * ══ §243/828 F_YoYo_GetTiltX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1560d8  size 40  10 条（0x1560d8..0x156100）
 * @func 0x1560d8 0x156110  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1560d8 ldr r3, [pc, #0x1c]
 *   @0x1560dc mov r2, #0
 *   @0x1560e0 str r2, [r0, #0xc]
 *   @0x1560e4 ldr r3, [pc, r3]
 *   @0x1560e8 vldr s15, [r3]
 *   @0x1560ec vcvt.f64.f32 d6, s15
 *   @0x1560f0 vmov r2, r3, d6
 *   @0x1560f4 stm r0, {r2, r3}
 *   @0x1560f8 bx lr
 *   @0x1560fc eoreq r9, r9, r0, asr r10
 *
 * ══ §244/828 F_YoYo_GetTiltY(RValue&, CInstance*, CInstance*, int, RValue*)  0x156100  size 40  10 条（0x156100..0x156128）
 * @func 0x156100 0x156138  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156100 ldr r3, [pc, #0x1c]
 *   @0x156104 mov r2, #0
 *   @0x156108 str r2, [r0, #0xc]
 *   @0x15610c ldr r3, [pc, r3]
 *   @0x156110 vldr s15, [r3]
 *   @0x156114 vcvt.f64.f32 d6, s15
 *   @0x156118 vmov r2, r3, d6
 *   @0x15611c stm r0, {r2, r3}
 *   @0x156120 bx lr
 *   @0x156124 eoreq r9, r9, r12, lsr #20
 *
 * ══ §245/828 F_YoYo_GetTiltZ(RValue&, CInstance*, CInstance*, int, RValue*)  0x156128  size 40  10 条（0x156128..0x156150）
 * @func 0x156128 0x156150  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156128 ldr r3, [pc, #0x1c]
 *   @0x15612c mov r2, #0
 *   @0x156130 str r2, [r0, #0xc]
 *   @0x156134 ldr r3, [pc, r3]
 *   @0x156138 vldr s15, [r3]
 *   @0x15613c vcvt.f64.f32 d6, s15
 *   @0x156140 vmov r2, r3, d6
 *   @0x156144 stm r0, {r2, r3}
 *   @0x156148 bx lr
 *   @0x15614c eoreq r9, r9, r8, lsl #20
 *
 * ══ §246/828 GR_3D_Transform_Stack_Discard()  0x163c14  size 40  10 条（0x163c14..0x163c3c）
 * @func 0x163c14 0x163c3c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163c14 ldr r3, [pc, #0x1c]
 *   @0x163c18 ldr r3, [pc, r3]
 *   @0x163c1c ldr r2, [r3]
 *   @0x163c20 cmp r2, #0
 *   @0x163c24 subge r2, r2, #1
 *   @0x163c28 strge r2, [r3]
 *   @0x163c2c movge r0, #1
 *   @0x163c30 movlt r0, #0
 *   @0x163c34 bx lr
 *   @0x163c38 eoreq r12, r8, r12, asr #9
 *
 * ══ §247/828 CBitmap32::~CBitmap32()  0x16791c  size 40  10 条（0x16791c..0x167944）
 * @func 0x16791c 0x167954  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::__Free()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16791c ldr r3, [pc, #0x1c]
 *   @0x167920 push {r4, lr}
 *   @0x167924 ldr r3, [pc, r3]
 *   @0x167928 mov r4, r0
 *   @0x16792c add r3, r3, #8
 *   @0x167930 str r3, [r0]
 *   @0x167934 bl 0x1678f0 <_ZN9CBitmap326__FreeEv>
 *   @0x167938 mov r0, r4
 *   @0x16793c pop {r4, pc}
 *   @0x167940 .word 0x002887d4
 *
 * ══ §248/828 anon_16c2cc  0x16c2cc  size 40  10 条（0x16c2cc..0x16c2f4）
 * @func 0x16c2cc 0x16c2f4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_io_ptr
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c2cc push {r4, r5, r6, lr}
 *   @0x16c2d0 mov r5, r1
 *   @0x16c2d4 mov r4, r2
 *   @0x16c2d8 blx 0x2a5f20 <png_get_io_ptr>
 *   @0x16c2dc subs r3, r0, #0
 *   @0x16c2e0 popeq {r4, r5, r6, pc}
 *   @0x16c2e4 mov r0, r5
 *   @0x16c2e8 mov r2, r4
 *   @0x16c2ec mov r1, #1
 *   @0x16c2f0 pop {r4, r5, r6, lr}
 *
 * ══ §249/828 INITIALIZE_Graphics_Window()  0x179d3c  size 40  10 条（0x179d3c..0x179d64）
 * @func 0x179d3c 0x179d64  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179d3c ldr r2, [pc, #0x18]
 *   @0x179d40 mov r1, #1
 *   @0x179d44 ldr r3, [pc, #0x14]
 *   @0x179d48 ldr r2, [pc, r2]
 *   @0x179d4c ldr r3, [pc, r3]
 *   @0x179d50 strb r1, [r2]
 *   @0x179d54 strb r1, [r3]
 *   @0x179d58 b 0x179d00 <_Z20GR_View_Undefine_Allv>
 *   @0x179d5c eoreq r5, r7, r0, lsl #28
 *   @0x179d60 eoreq r6, r7, r8, lsr #11
 *
 * ══ §250/828 HasExtension(char*, char*)  0x17d428  size 40  10 条（0x17d428..0x17d450）
 * @func 0x17d428 0x17d450  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6604
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17d428 cmp r1, #0
 *   @0x17d42c cmpne r0, #0
 *   @0x17d430 push {r3, lr}
 *   @0x17d434 beq 0x17d448 <_Z12HasExtensionPcS_+0x20>
 *   @0x17d438 bl 0xb6604 <strstr@plt>
 *   @0x17d43c adds r0, r0, #0
 *   @0x17d440 movne r0, #1
 *   @0x17d444 pop {r3, pc}
 *   @0x17d448 mov r0, #0
 *   @0x17d44c pop {r3, pc}
 *
 * ══ §251/828 IO_Keymap_Clear()  0x18c314  size 40  10 条（0x18c314..0x18c33c）
 * @func 0x18c314 0x18c33c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c314 ldr r2, [pc, #0x1c]
 *   @0x18c318 mov r3, #0
 *   @0x18c31c ldr r2, [pc, r2]
 *   @0x18c320 sub r2, r2, #4
 *   @0x18c324 str r3, [r2, #0x4]!
 *   @0x18c328 add r3, r3, #1
 *   @0x18c32c cmp r3, #256
 *   @0x18c330 bne 0x18c324 <_Z15IO_Keymap_Clearv+0x10>
 *   @0x18c334 bx lr
 *   @0x18c338 .word 0x002642f4
 *
 * ══ §252/828 CInstanceBase::~CInstanceBase()  0x190cd8  size 40  10 条（0x190cd8..0x190d00）
 * @func 0x190cd8 0x190d10  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190cd8 ldr r3, [pc, #0x1c]
 *   @0x190cdc push {r4, lr}
 *   @0x190ce0 ldr r3, [pc, r3]
 *   @0x190ce4 mov r4, r0
 *   @0x190ce8 add r3, r3, #8
 *   @0x190cec str r3, [r0]
 *   @0x190cf0 bl 0x27d1d0 <_ZdlPv>
 *   @0x190cf4 mov r0, r4
 *   @0x190cf8 pop {r4, pc}
 *   @0x190cfc eoreq pc, r5, r12, lsl #19
 *
 * ══ §253/828 RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)  0x191f5c  size 40  10 条（0x191f5c..0x191f84）
 * @func 0x191f5c 0x191f84  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191f5c ldr r12, [r0]
 *   @0x191f60 cmp r12, #0
 *   @0x191f64 bxeq lr
 *   @0x191f68 ldr r3, [r0, #0xc]
 *   @0x191f6c bic r3, r3, #-16777216
 *   @0x191f70 cmp r3, #6
 *   @0x191f74 cmpne r3, #11
 *   @0x191f78 bxne lr
 *   @0x191f7c mov r0, r12
 *   @0x191f80 b 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *
 * ══ §254/828 CScriptRef::~CScriptRef()  0x199414  size 40  10 条（0x199414..0x19943c）
 * @func 0x199414 0x19943c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::~YYObjectBase()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199414 ldr r3, [pc, #0x1c]
 *   @0x199418 push {r4, lr}
 *   @0x19941c ldr r3, [pc, r3]
 *   @0x199420 mov r4, r0
 *   @0x199424 add r3, r3, #8
 *   @0x199428 str r3, [r0]
 *   @0x19942c bl 0x199110 <_ZN12YYObjectBaseD2Ev>
 *   @0x199430 mov r0, r4
 *   @0x199434 pop {r4, pc}
 *   @0x199438 eoreq r7, r5, r0, ror #4
 *
 * ══ §255/828 _RefFactory<YYObjectBase*>::Alloc(YYObjectBase*, int)  0x199ea8  size 40  10 条（0x199ea8..0x199ed0）
 * @func 0x199ea8 0x199ed0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / YYObjectBase::YYObjectBase(int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199ea8 push {r3, r4, r5, lr}
 *   @0x199eac mov r0, #100
 *   @0x199eb0 mov r5, r1
 *   @0x199eb4 bl 0x27c524 <_Znwj>
 *   @0x199eb8 mov r1, r5
 *   @0x199ebc mov r2, #5
 *   @0x199ec0 mov r4, r0
 *   @0x199ec4 bl 0x19188c <_ZN12YYObjectBaseC2Eii>
 *   @0x199ec8 mov r0, r4
 *   @0x199ecc pop {r3, r4, r5, pc}
 *
 * ══ §256/828 Option_Quit()  0x19f50c  size 40  10 条（0x19f50c..0x19f534）
 * @func 0x19f50c 0x19f534  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f50c ldr r2, [pc, #0x18]
 *   @0x19f510 mov r1, #0
 *   @0x19f514 ldr r3, [pc, #0x14]
 *   @0x19f518 ldr r2, [pc, r2]
 *   @0x19f51c ldr r3, [pc, r3]
 *   @0x19f520 str r1, [r2]
 *   @0x19f524 str r1, [r3]
 *   @0x19f528 bx lr
 *   @0x19f52c eoreq lr, r4, r0, asr #17
 *   @0x19f530 eoreq lr, r4, r0, asr #17
 *
 * ══ §257/828 CPath::Speed(float)  0x1a75e8  size 40  10 条（0x1a75e8..0x1a7610）
 * @func 0x1a75e8 0x1a7610  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPosition(float, float&, float&, float&)
 * 字段偏移 top8: 0x-4×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a75e8 str lr, [sp, #-0x4]!
 *   @0x1a75ec sub sp, sp, #28
 *   @0x1a75f0 add r3, sp, #20
 *   @0x1a75f4 add r2, sp, #12
 *   @0x1a75f8 str r3, [sp]
 *   @0x1a75fc add r3, sp, #16
 *   @0x1a7600 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_>
 *   @0x1a7604 ldr r0, [sp, #0x14]
 *   @0x1a7608 add sp, sp, #28
 *   @0x1a760c ldr pc, [sp], #4
 *
 * ══ §258/828 IYYFont::~IYYFont()  0x1a8574  size 40  10 条（0x1a8574..0x1a859c）
 * @func 0x1a8574 0x1a859c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8574 ldr r3, [pc, #0x1c]
 *   @0x1a8578 push {r4, lr}
 *   @0x1a857c ldr r3, [pc, r3]
 *   @0x1a8580 mov r4, r0
 *   @0x1a8584 add r3, r3, #8
 *   @0x1a8588 str r3, [r0]
 *   @0x1a858c bl 0x27d1d0 <_ZdlPv>
 *   @0x1a8590 mov r0, r4
 *   @0x1a8594 pop {r4, pc}
 *   @0x1a8598 eoreq r8, r4, r8, asr r2
 *
 * ══ §259/828 RomDisk::Size(int)  0x1a8728  size 40  10 条（0x1a8728..0x1a8750）
 * @func 0x1a8728 0x1a8750  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8728 ldr r3, [pc, #0x1c]
 *   @0x1a872c ldr r3, [pc, r3]
 *   @0x1a8730 ldr r3, [r3]
 *   @0x1a8734 ldr r2, [r3]
 *   @0x1a8738 cmp r2, r0
 *   @0x1a873c addgt r3, r3, r0, lsl #3
 *   @0x1a8740 ldrgt r0, [r3, #0x4]
 *   @0x1a8744 movle r0, #0
 *   @0x1a8748 bx lr
 *   @0x1a874c strhteq r8, [r4], -r4
 *
 * ══ §260/828 IBitmap::~IBitmap()  0x1a8968  size 40  10 条（0x1a8968..0x1a8990）
 * @func 0x1a8968 0x1a89a0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8968 ldr r3, [pc, #0x1c]
 *   @0x1a896c push {r4, lr}
 *   @0x1a8970 ldr r3, [pc, r3]
 *   @0x1a8974 mov r4, r0
 *   @0x1a8978 add r3, r3, #8
 *   @0x1a897c str r3, [r0]
 *   @0x1a8980 bl 0x27d1d0 <_ZdlPv>
 *   @0x1a8984 mov r0, r4
 *   @0x1a8988 pop {r4, pc}
 *   @0x1a898c eoreq r7, r4, r8, lsl #29
 *
 * ══ §261/828 IBitmapLoader::~IBitmapLoader()  0x1a8990  size 40  10 条（0x1a8990..0x1a89b8）
 * @func 0x1a8990 0x1a89b8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8990 ldr r3, [pc, #0x1c]
 *   @0x1a8994 push {r4, lr}
 *   @0x1a8998 ldr r3, [pc, r3]
 *   @0x1a899c mov r4, r0
 *   @0x1a89a0 add r3, r3, #8
 *   @0x1a89a4 str r3, [r0]
 *   @0x1a89a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1a89ac mov r0, r4
 *   @0x1a89b0 pop {r4, pc}
 *   @0x1a89b4 eoreq r7, r4, r4, ror #28
 *
 * ══ §262/828 GetTPixelFormat(int)  0x1a8b28  size 40  10 条（0x1a8b28..0x1a8b50）
 * @func 0x1a8b28 0x1a8b50  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8b28 sub r0, r0, #1
 *   @0x1a8b2c cmp r0, #23
 *   @0x1a8b30 bhi 0x1a8b44 <_Z15GetTPixelFormati+0x1c>
 *   @0x1a8b34 ldr r3, [pc, #0x10]
 *   @0x1a8b38 add r3, pc, r3
 *   @0x1a8b3c ldr r0, [r3, r0, lsl #2]
 *   @0x1a8b40 bx lr
 *   @0x1a8b44 mov r0, #7
 *   @0x1a8b48 bx lr
 *   @0x1a8b4c ldrsheq r5, [r11], -r8
 *
 * ══ §263/828 List<CInstance*>::~List()  0x1d1690  size 40  10 条（0x1d1690..0x1d16b8）
 * @func 0x1d1690 0x1d16b8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1690 push {r4, lr}
 *   @0x1d1694 mov r4, r0
 *   @0x1d1698 ldr r0, [r0]
 *   @0x1d169c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d16a0 mov r3, #0
 *   @0x1d16a4 mov r0, r4
 *   @0x1d16a8 str r3, [r4]
 *   @0x1d16ac str r3, [r4, #0x4]
 *   @0x1d16b0 str r3, [r4, #0x8]
 *   @0x1d16b4 pop {r4, pc}
 *
 * ══ §264/828 INITIALIZE_Main()  0x1d37a4  size 40  10 条（0x1d37a4..0x1d37cc）
 * @func 0x1d37a4 0x1d37cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d37a4 ldr r2, [pc, #0x18]
 *   @0x1d37a8 mov r1, #0
 *   @0x1d37ac ldr r3, [pc, #0x14]
 *   @0x1d37b0 ldr r2, [pc, r2]
 *   @0x1d37b4 ldr r3, [pc, r3]
 *   @0x1d37b8 str r1, [r2, #0x8]
 *   @0x1d37bc str r1, [r3, #0x8]
 *   @0x1d37c0 bx lr
 *   @0x1d37c4 mlaeq r1, r0, r4, r10
 *   @0x1d37c8 .word 0x0021a8f0
 *
 * ══ §265/828 CGesturePinch::IsUsingTouchUID(int)  0x1d5014  size 40  10 条（0x1d5014..0x1d503c）
 * @func 0x1d5014 0x1d504c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5014 ldr r3, [r0, #0x28]
 *   @0x1d5018 cmp r3, r1
 *   @0x1d501c beq 0x1d5034 <_ZN13CGesturePinch15IsUsingTouchUIDEi+0x20>
 *   @0x1d5020 ldr r0, [r0, #0x2c]
 *   @0x1d5024 subs r3, r1, r0
 *   @0x1d5028 rsbs r0, r3, #0
 *   @0x1d502c adcs r0, r0, r3
 *   @0x1d5030 bx lr
 *   @0x1d5034 mov r0, #1
 *   @0x1d5038 bx lr
 *
 * ══ §266/828 CGestureRotate::IsUsingTouchUID(int)  0x1d503c  size 40  10 条（0x1d503c..0x1d5064）
 * @func 0x1d503c 0x1d5064  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d503c ldr r3, [r0, #0x28]
 *   @0x1d5040 cmp r3, r1
 *   @0x1d5044 beq 0x1d505c <_ZN14CGestureRotate15IsUsingTouchUIDEi+0x20>
 *   @0x1d5048 ldr r0, [r0, #0x2c]
 *   @0x1d504c subs r3, r1, r0
 *   @0x1d5050 rsbs r0, r3, #0
 *   @0x1d5054 adcs r0, r0, r3
 *   @0x1d5058 bx lr
 *   @0x1d505c mov r0, #1
 *   @0x1d5060 bx lr
 *
 * ══ §267/828 F_GestureGetDragDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d50b8  size 40  10 条（0x1d50b8..0x1d50e0）
 * @func 0x1d50b8 0x1d50f0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d50b8 ldr r3, [pc, #0x1c]
 *   @0x1d50bc mov r2, #0
 *   @0x1d50c0 str r2, [r0, #0xc]
 *   @0x1d50c4 ldr r3, [pc, r3]
 *   @0x1d50c8 vldr s15, [r3]
 *   @0x1d50cc vcvt.f64.f32 d6, s15
 *   @0x1d50d0 vmov r2, r3, d6
 *   @0x1d50d4 stm r0, {r2, r3}
 *   @0x1d50d8 bx lr
 *   @0x1d50dc eoreq r11, r1, r4, lsl #22
 *
 * ══ §268/828 F_GestureGetFlickSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d50e0  size 40  10 条（0x1d50e0..0x1d5108）
 * @func 0x1d50e0 0x1d5108  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d50e0 ldr r3, [pc, #0x1c]
 *   @0x1d50e4 mov r2, #0
 *   @0x1d50e8 str r2, [r0, #0xc]
 *   @0x1d50ec ldr r3, [pc, r3]
 *   @0x1d50f0 vldr s15, [r3]
 *   @0x1d50f4 vcvt.f64.f32 d6, s15
 *   @0x1d50f8 vmov r2, r3, d6
 *   @0x1d50fc stm r0, {r2, r3}
 *   @0x1d5100 bx lr
 *   @0x1d5104 eoreq r11, r1, r0, ror #21
 *
 * ══ §269/828 F_GestureGetDoubleTapDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5158  size 40  10 条（0x1d5158..0x1d5180）
 * @func 0x1d5158 0x1d5190  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5158 ldr r3, [pc, #0x1c]
 *   @0x1d515c mov r2, #0
 *   @0x1d5160 str r2, [r0, #0xc]
 *   @0x1d5164 ldr r3, [pc, r3]
 *   @0x1d5168 vldr s15, [r3]
 *   @0x1d516c vcvt.f64.f32 d6, s15
 *   @0x1d5170 vmov r2, r3, d6
 *   @0x1d5174 stm r0, {r2, r3}
 *   @0x1d5178 bx lr
 *   @0x1d517c eoreq r11, r1, r0, ror r10
 *
 * ══ §270/828 F_GestureGetPinchDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5180  size 40  10 条（0x1d5180..0x1d51a8）
 * @func 0x1d5180 0x1d51b8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5180 ldr r3, [pc, #0x1c]
 *   @0x1d5184 mov r2, #0
 *   @0x1d5188 str r2, [r0, #0xc]
 *   @0x1d518c ldr r3, [pc, r3]
 *   @0x1d5190 vldr s15, [r3]
 *   @0x1d5194 vcvt.f64.f32 d6, s15
 *   @0x1d5198 vmov r2, r3, d6
 *   @0x1d519c stm r0, {r2, r3}
 *   @0x1d51a0 bx lr
 *   @0x1d51a4 eoreq r11, r1, r12, asr #20
 *
 * ══ §271/828 F_GestureGetPinchAngleTowards(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d51a8  size 40  10 条（0x1d51a8..0x1d51d0）
 * @func 0x1d51a8 0x1d51e0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d51a8 ldr r3, [pc, #0x1c]
 *   @0x1d51ac mov r2, #0
 *   @0x1d51b0 str r2, [r0, #0xc]
 *   @0x1d51b4 ldr r3, [pc, r3]
 *   @0x1d51b8 vldr s15, [r3]
 *   @0x1d51bc vcvt.f64.f32 d6, s15
 *   @0x1d51c0 vmov r2, r3, d6
 *   @0x1d51c4 stm r0, {r2, r3}
 *   @0x1d51c8 bx lr
 *   @0x1d51cc eoreq r11, r1, r8, lsr #20
 *
 * ══ §272/828 F_GestureGetPinchAngleAway(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d51d0  size 40  10 条（0x1d51d0..0x1d51f8）
 * @func 0x1d51d0 0x1d51f8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d51d0 ldr r3, [pc, #0x1c]
 *   @0x1d51d4 mov r2, #0
 *   @0x1d51d8 str r2, [r0, #0xc]
 *   @0x1d51dc ldr r3, [pc, r3]
 *   @0x1d51e0 vldr s15, [r3]
 *   @0x1d51e4 vcvt.f64.f32 d6, s15
 *   @0x1d51e8 vmov r2, r3, d6
 *   @0x1d51ec stm r0, {r2, r3}
 *   @0x1d51f0 bx lr
 *   @0x1d51f4 eoreq r11, r1, r4, lsl #20
 *
 * ══ §273/828 F_GestureGetRotateAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5248  size 40  10 条（0x1d5248..0x1d5270）
 * @func 0x1d5248 0x1d5270  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5248 ldr r3, [pc, #0x1c]
 *   @0x1d524c mov r2, #0
 *   @0x1d5250 str r2, [r0, #0xc]
 *   @0x1d5254 ldr r3, [pc, r3]
 *   @0x1d5258 vldr s15, [r3]
 *   @0x1d525c vcvt.f64.f32 d6, s15
 *   @0x1d5260 vmov r2, r3, d6
 *   @0x1d5264 stm r0, {r2, r3}
 *   @0x1d5268 bx lr
 *   @0x1d526c mlaeq r1, r4, r9, r11
 *
 * ══ §274/828 CSingleFingerGesture::~CSingleFingerGesture()  0x1d52f4  size 40  10 条（0x1d52f4..0x1d531c）
 * @func 0x1d52f4 0x1d531c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d52f4 ldr r3, [pc, #0x1c]
 *   @0x1d52f8 push {r4, lr}
 *   @0x1d52fc ldr r3, [pc, r3]
 *   @0x1d5300 mov r4, r0
 *   @0x1d5304 add r3, r3, #8
 *   @0x1d5308 str r3, [r0]
 *   @0x1d530c bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5310 mov r0, r4
 *   @0x1d5314 pop {r4, pc}
 *   @0x1d5318 .word 0x0021b8f8
 *
 * ══ §275/828 CGestureUnknown::~CGestureUnknown()  0x1d534c  size 40  10 条（0x1d534c..0x1d5374）
 * @func 0x1d534c 0x1d5374  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d534c ldr r3, [pc, #0x1c]
 *   @0x1d5350 push {r4, lr}
 *   @0x1d5354 ldr r3, [pc, r3]
 *   @0x1d5358 mov r4, r0
 *   @0x1d535c add r3, r3, #8
 *   @0x1d5360 str r3, [r0]
 *   @0x1d5364 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5368 mov r0, r4
 *   @0x1d536c pop {r4, pc}
 *   @0x1d5370 eoreq r11, r1, r0, lsr #17
 *
 * ══ §276/828 CGestureTap::~CGestureTap()  0x1d53a4  size 40  10 条（0x1d53a4..0x1d53cc）
 * @func 0x1d53a4 0x1d53cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d53a4 ldr r3, [pc, #0x1c]
 *   @0x1d53a8 push {r4, lr}
 *   @0x1d53ac ldr r3, [pc, r3]
 *   @0x1d53b0 mov r4, r0
 *   @0x1d53b4 add r3, r3, #8
 *   @0x1d53b8 str r3, [r0]
 *   @0x1d53bc bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d53c0 mov r0, r4
 *   @0x1d53c4 pop {r4, pc}
 *   @0x1d53c8 eoreq r11, r1, r8, asr #16
 *
 * ══ §277/828 CGestureDoubleTap::~CGestureDoubleTap()  0x1d53fc  size 40  10 条（0x1d53fc..0x1d5424）
 * @func 0x1d53fc 0x1d5424  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d53fc ldr r3, [pc, #0x1c]
 *   @0x1d5400 push {r4, lr}
 *   @0x1d5404 ldr r3, [pc, r3]
 *   @0x1d5408 mov r4, r0
 *   @0x1d540c add r3, r3, #8
 *   @0x1d5410 str r3, [r0]
 *   @0x1d5414 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5418 mov r0, r4
 *   @0x1d541c pop {r4, pc}
 *   @0x1d5420 .word 0x0021b7f0
 *
 * ══ §278/828 CGestureDrag::~CGestureDrag()  0x1d5454  size 40  10 条（0x1d5454..0x1d547c）
 * @func 0x1d5454 0x1d547c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5454 ldr r3, [pc, #0x1c]
 *   @0x1d5458 push {r4, lr}
 *   @0x1d545c ldr r3, [pc, r3]
 *   @0x1d5460 mov r4, r0
 *   @0x1d5464 add r3, r3, #8
 *   @0x1d5468 str r3, [r0]
 *   @0x1d546c bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5470 mov r0, r4
 *   @0x1d5474 pop {r4, pc}
 *   @0x1d5478 mlaeq r1, r8, r7, r11
 *
 * ══ §279/828 CGesturePinch::~CGesturePinch()  0x1d54ac  size 40  10 条（0x1d54ac..0x1d54d4）
 * @func 0x1d54ac 0x1d54d4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d54ac ldr r3, [pc, #0x1c]
 *   @0x1d54b0 push {r4, lr}
 *   @0x1d54b4 ldr r3, [pc, r3]
 *   @0x1d54b8 mov r4, r0
 *   @0x1d54bc add r3, r3, #8
 *   @0x1d54c0 str r3, [r0]
 *   @0x1d54c4 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d54c8 mov r0, r4
 *   @0x1d54cc pop {r4, pc}
 *   @0x1d54d0 eoreq r11, r1, r4, asr #14
 *
 * ══ §280/828 CGestureRotate::~CGestureRotate()  0x1d5504  size 40  10 条（0x1d5504..0x1d552c）
 * @func 0x1d5504 0x1d552c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5504 ldr r3, [pc, #0x1c]
 *   @0x1d5508 push {r4, lr}
 *   @0x1d550c ldr r3, [pc, r3]
 *   @0x1d5510 mov r4, r0
 *   @0x1d5514 add r3, r3, #8
 *   @0x1d5518 str r3, [r0]
 *   @0x1d551c bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5520 mov r0, r4
 *   @0x1d5524 pop {r4, pc}
 *   @0x1d5528 .word 0x0021b6f0
 *
 * ══ §281/828 GetAll(int, char const*&, int&)  0x1dc1d4  size 40  10 条（0x1dc1d4..0x1dc1fc）
 * @func 0x1dc1d4 0x1dc20c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x3×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc1d4 ldr r3, [pc, #0x1c]
 *   @0x1dc1d8 sub r0, r0, #1
 *   @0x1dc1dc ldr r3, [pc, r3]
 *   @0x1dc1e0 add r12, r3, r0, lsl #3
 *   @0x1dc1e4 ldr r0, [r3, r0, lsl #3]
 *   @0x1dc1e8 ldr r3, [r12, #0x4]
 *   @0x1dc1ec str r0, [r1]
 *   @0x1dc1f0 str r3, [r2]
 *   @0x1dc1f4 bx lr
 *   @0x1dc1f8 .word 0x00214ab0
 *
 * ══ §282/828 Code_Patch_Instruction(unsigned char*, int, void*)  0x1dc7a4  size 40  10 条（0x1dc7a4..0x1dc7cc）
 * @func 0x1dc7a4 0x1dc7cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParamSize(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc7a4 ldr r0, [r0, r1]
 *   @0x1dc7a8 push {r4, lr}
 *   @0x1dc7ac tst r0, #1073741824
 *   @0x1dc7b0 add r4, r1, #4
 *   @0x1dc7b4 beq 0x1dc7c4 <_Z22Code_Patch_InstructionPhiPv+0x20>
 *   @0x1dc7b8 ubfx r0, r0, #0x10, #0x8
 *   @0x1dc7bc bl 0xec108 <_Z9ParamSizei>
 *   @0x1dc7c0 add r4, r4, r0
 *   @0x1dc7c4 mov r0, r4
 *   @0x1dc7c8 pop {r4, pc}
 *
 * ══ §283/828 DebugInstNames_Load(unsigned char*, unsigned int, unsigned char*)  0x1de788  size 40  10 条（0x1de788..0x1de7b0）
 * @func 0x1de788 0x1de7b0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de788 ldr r2, [pc, #0x18]
 *   @0x1de78c ldr r3, [pc, #0x18]
 *   @0x1de790 ldr r1, [r0], #4
 *   @0x1de794 ldr r2, [pc, r2]
 *   @0x1de798 ldr r3, [pc, r3]
 *   @0x1de79c str r0, [r2]
 *   @0x1de7a0 str r1, [r3]
 *   @0x1de7a4 bx lr
 *   @0x1de7a8 eoreq r2, r1, r4, asr r5
 *   @0x1de7ac eoreq r2, r1, r4, asr r5
 *
 * ══ §284/828 CScript::~CScript()  0x1dfc44  size 40  10 条（0x1dfc44..0x1dfc6c）
 * @func 0x1dfc44 0x1dfc7c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CScript::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfc44 ldr r3, [pc, #0x1c]
 *   @0x1dfc48 push {r4, lr}
 *   @0x1dfc4c ldr r3, [pc, r3]
 *   @0x1dfc50 mov r4, r0
 *   @0x1dfc54 add r3, r3, #8
 *   @0x1dfc58 str r3, [r0]
 *   @0x1dfc5c bl 0x1dfbb0 <_ZN7CScript5ClearEv>
 *   @0x1dfc60 mov r0, r4
 *   @0x1dfc64 pop {r4, pc}
 *   @0x1dfc68 .word 0x002110d8
 *
 * ══ §285/828 VertexFormat::GetTypeSize(yyVertexType)  0x1e23d8  size 40  10 条（0x1e23d8..0x1e2400）
 * @func 0x1e23d8 0x1e2410  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e23d8 sub r0, r0, #1
 *   @0x1e23dc cmp r0, #5
 *   @0x1e23e0 bhi 0x1e23f4 <_ZN12VertexFormat11GetTypeSizeE12yyVertexType+0x1c>
 *   @0x1e23e4 ldr r3, [pc, #0x10]
 *   @0x1e23e8 add r3, pc, r3
 *   @0x1e23ec ldr r0, [r3, r0, lsl #2]
 *   @0x1e23f0 bx lr
 *   @0x1e23f4 mov r0, #0
 *   @0x1e23f8 bx lr
 *   @0x1e23fc andseq r11, r7, r12, lsr #22
 *
 * ══ §286/828 CSprite::~CSprite()  0x1e76a4  size 40  10 条（0x1e76a4..0x1e76cc）
 * @func 0x1e76a4 0x1e76dc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e76a4 ldr r3, [pc, #0x1c]
 *   @0x1e76a8 push {r4, lr}
 *   @0x1e76ac ldr r3, [pc, r3]
 *   @0x1e76b0 mov r4, r0
 *   @0x1e76b4 add r3, r3, #8
 *   @0x1e76b8 str r3, [r0]
 *   @0x1e76bc bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e76c0 mov r0, r4
 *   @0x1e76c4 pop {r4, pc}
 *   @0x1e76c8 eoreq r9, r0, r4, lsr #14
 *
 * ══ §287/828 CHashMap<char const*, int, 7>::~CHashMap()  0x1ee778  size 40  10 条（0x1ee778..0x1ee7a0）
 * @func 0x1ee778 0x1ee7a0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ee778 push {r4, lr}
 *   @0x1ee77c mov r4, r0
 *   @0x1ee780 ldr r0, [r0, #0x10]
 *   @0x1ee784 cmp r0, #0
 *   @0x1ee788 beq 0x1ee798 <_ZN8CHashMapIPKciLi7EED2Ev+0x20>
 *   @0x1ee78c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ee790 mov r3, #0
 *   @0x1ee794 str r3, [r4, #0x10]
 *   @0x1ee798 mov r0, r4
 *   @0x1ee79c pop {r4, pc}
 *
 * ══ §288/828 RVariable::RVariable(int)  0x1f50a4  size 40  10 条（0x1f50a4..0x1f50cc）
 * @func 0x1f50a4 0x1f50cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x14×1 / 0x4×1 / 0x18×1 / 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f50a4 mov r2, #0
 *   @0x1f50a8 mov r12, #7
 *   @0x1f50ac str r1, [r0, #0x8]
 *   @0x1f50b0 str r12, [r0, #0x14]
 *   @0x1f50b4 str r2, [r0]
 *   @0x1f50b8 str r2, [r0, #0x4]
 *   @0x1f50bc str r2, [r0, #0x18]
 *   @0x1f50c0 str r2, [r0, #0x1c]
 *   @0x1f50c4 str r2, [r0, #0x24]
 *   @0x1f50c8 bx lr
 *
 * ══ §289/828 CVariableList::~CVariableList()  0x1f6658  size 40  10 条（0x1f6658..0x1f6680）
 * @func 0x1f6658 0x1f6690  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6658 ldr r3, [pc, #0x1c]
 *   @0x1f665c push {r4, lr}
 *   @0x1f6660 ldr r3, [pc, r3]
 *   @0x1f6664 mov r4, r0
 *   @0x1f6668 add r3, r3, #8
 *   @0x1f666c str r3, [r0]
 *   @0x1f6670 bl 0x1f662c <_ZN13CVariableList5ClearEv>
 *   @0x1f6674 mov r0, r4
 *   @0x1f6678 pop {r4, pc}
 *   @0x1f667c ldrsbeq r10, [pc], -r8
 *
 * ══ §290/828 GV_RoomCaption(CInstance*, int, RValue*)  0x1f9c98  size 40  10 条（0x1f9c98..0x1f9cc0）
 * @func 0x1f9c98 0x1f9cc0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9c98 push {r3, lr}
 *   @0x1f9c9c mov r0, r2
 *   @0x1f9ca0 ldr r3, [pc, #0x14]
 *   @0x1f9ca4 ldr r3, [pc, r3]
 *   @0x1f9ca8 ldr r3, [r3]
 *   @0x1f9cac ldr r1, [r3, #0x8]
 *   @0x1f9cb0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9cb4 mov r0, #1
 *   @0x1f9cb8 pop {r3, pc}
 *   @0x1f9cbc andseq r3, pc, r4, lsl #25
 *
 * ══ §291/828 SV_FontTexturePageSize(CInstance*, int, RValue*)  0x1fa254  size 40  10 条（0x1fa254..0x1fa27c）
 * @func 0x1fa254 0x1fa27c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt64(RValue const*, int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa254 push {r3, lr}
 *   @0x1fa258 mov r0, r2
 *   @0x1fa25c mov r1, #0
 *   @0x1fa260 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0x1fa264 ldr r3, [pc, #0xc]
 *   @0x1fa268 ldr r3, [pc, r3]
 *   @0x1fa26c str r0, [r3]
 *   @0x1fa270 mov r0, #1
 *   @0x1fa274 pop {r3, pc}
 *   @0x1fa278 andseq r3, pc, r12, ror #23
 *
 * ══ §292/828 SV_Room(CInstance*, int, RValue*)  0x1fa7d4  size 40  10 条（0x1fa7d4..0x1fa7fc）
 * @func 0x1fa7d4 0x1fa7fc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / Command_GotoRoom(int, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa7d4 push {r3, lr}
 *   @0x1fa7d8 ldm r2, {r0, r1}
 *   @0x1fa7dc bl 0xb66e8 <lrint@plt>
 *   @0x1fa7e0 ldr r3, [pc, #0x10]
 *   @0x1fa7e4 ldr r3, [pc, r3]
 *   @0x1fa7e8 ldr r1, [r3]
 *   @0x1fa7ec bl 0x1c9e08 <_Z16Command_GotoRoomii>
 *   @0x1fa7f0 mov r0, #1
 *   @0x1fa7f4 pop {r3, pc}
 *   @0x1fa7f8 andseq r3, pc, r4, asr #17
 *
 * ══ §293/828 CStream::SkipCompressedStream()  0x201d88  size 40  10 条（0x201d88..0x201db0）
 * @func 0x201d88 0x201db0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger() / CStream::GetPosition()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201d88 push {r3, r4, r5, lr}
 *   @0x201d8c mov r4, r0
 *   @0x201d90 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201d94 mov r5, r0
 *   @0x201d98 mov r0, r4
 *   @0x201d9c bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x201da0 add r1, r0, r5
 *   @0x201da4 mov r0, r4
 *   @0x201da8 pop {r3, r4, r5, lr}
 *   @0x201dac b 0x201148 <_ZN7CStream11SetPositionEi>
 *
 * ══ §294/828 CDS_List::GetValue(int)  0x2031f4  size 40  10 条（0x2031f4..0x20321c）
 * @func 0x2031f4 0x20321c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::GetValue(int)+0x20
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2031f4 cmp r1, #0
 *   @0x2031f8 blt 0x203214 <_ZN8CDS_List8GetValueEi+0x20>
 *   @0x2031fc ldr r3, [r0, #0x4]
 *   @0x203200 cmp r1, r3
 *   @0x203204 bge 0x203214 <_ZN8CDS_List8GetValueEi+0x20>
 *   @0x203208 ldr r0, [r0, #0xc]
 *   @0x20320c add r0, r0, r1, lsl #4
 *   @0x203210 bx lr
 *   @0x203214 mov r0, #0
 *   @0x203218 bx lr
 *
 * ══ §295/828 CDS_Priority::~CDS_Priority()  0x209a34  size 40  10 条（0x209a34..0x209a5c）
 * @func 0x209a34 0x209a6c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x209a34 ldr r3, [pc, #0x1c]
 *   @0x209a38 push {r4, lr}
 *   @0x209a3c ldr r3, [pc, r3]
 *   @0x209a40 mov r4, r0
 *   @0x209a44 add r3, r3, #8
 *   @0x209a48 str r3, [r0]
 *   @0x209a4c bl 0x209768 <_ZN12CDS_Priority5ClearEv>
 *   @0x209a50 mov r0, r4
 *   @0x209a54 pop {r4, pc}
 *   @0x209a58 andseq r7, lr, r0, ror #18
 *
 * ══ §296/828 CDS_Stack::~CDS_Stack()  0x20f968  size 40  10 条（0x20f968..0x20f990）
 * @func 0x20f968 0x20f9a0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Stack::Clear()
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f968 ldr r3, [pc, #0x1c]
 *   @0x20f96c push {r4, lr}
 *   @0x20f970 ldr r3, [pc, r3]
 *   @0x20f974 mov r4, r0
 *   @0x20f978 add r3, r3, #8
 *   @0x20f97c str r3, [r0]
 *   @0x20f980 bl 0x20f270 <_ZN9CDS_Stack5ClearEv>
 *   @0x20f984 mov r0, r4
 *   @0x20f988 pop {r4, pc}
 *   @0x20f98c andseq r1, lr, r8, lsr r10
 *
 * ══ §297/828 FileExists(char const*)  0x214e48  size 40  10 条（0x214e48..0x214e70）
 * @func 0x214e48 0x214e70  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e48 push {r4, lr}
 *   @0x214e4c mov r4, r0
 *   @0x214e50 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x214e54 cmp r0, #0
 *   @0x214e58 beq 0x214e64 <_Z10FileExistsPKc+0x1c>
 *   @0x214e5c mov r0, #1
 *   @0x214e60 pop {r4, pc}
 *   @0x214e64 mov r0, r4
 *   @0x214e68 pop {r4, lr}
 *   @0x214e6c b 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *
 * ══ §298/828 ExtractFileName(char const*)  0x214fe0  size 40  10 条（0x214fe0..0x215008）
 * @func 0x214fe0 0x215008  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strrchr
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214fe0 push {r4, lr}
 *   @0x214fe4 mov r1, #92
 *   @0x214fe8 mov r2, #47
 *   @0x214fec mov r4, r0
 *   @0x214ff0 bl 0x10fbbc <utf8_strrchr>
 *   @0x214ff4 cmp r0, #0
 *   @0x214ff8 addne r4, r0, #1
 *   @0x214ffc mov r0, r4
 *   @0x215000 pop {r4, lr}
 *   @0x215004 b 0xdb8c8 <_Z8YYStrDupPKc>
 *
 * ══ §299/828 CAudioGroupMan::GetGroupName(int)  0x21df34  size 40  10 条（0x21df34..0x21df5c）
 * @func 0x21df34 0x21df5c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int)
 * 字段偏移 top8: 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21df34 push {r3, lr}
 *   @0x21df38 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21df3c cmp r0, #0
 *   @0x21df40 beq 0x21df4c <_ZN14CAudioGroupMan12GetGroupNameEi+0x18>
 *   @0x21df44 ldr r0, [r0, #0x1c]
 *   @0x21df48 pop {r3, pc}
 *   @0x21df4c ldr r0, [pc, #0x4]
 *   @0x21df50 add r0, pc, r0
 *   @0x21df54 pop {r3, pc}
 *   @0x21df58 andseq r2, r1, r0, ror r11
 *
 * ══ §300/828 COggSyncThread::StopSyncGroup()  0x225c4c  size 40  10 条（0x225c4c..0x225c74）
 * @func 0x225c4c 0x225c84  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x84f×1 / 0x854×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225c4c push {r4, lr}
 *   @0x225c50 mov r4, r0
 *   @0x225c54 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225c58 mov r2, #1
 *   @0x225c5c mov r3, #0
 *   @0x225c60 strb r2, [r4, #0x84f]
 *   @0x225c64 mov r0, r4
 *   @0x225c68 strb r3, [r4, #0x854]
 *   @0x225c6c pop {r4, lr}
 *   @0x225c70 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §301/828 COggAudio::IsSyncGroupPlaying(int)  0x226254  size 40  10 条（0x226254..0x22627c）
 * @func 0x226254 0x22627c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::IsSyncGroupPlaying(int)+0x20
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226254 ldr r3, [r0, #0x4]
 *   @0x226258 cmp r3, r1
 *   @0x22625c ble 0x226274 <_ZN9COggAudio18IsSyncGroupPlayingEi+0x20>
 *   @0x226260 ldr r3, [r0, #0x10]
 *   @0x226264 ldr r0, [r3, r1, lsl #2]
 *   @0x226268 cmp r0, #0
 *   @0x22626c ldrbne r0, [r0, #0x854]
 *   @0x226270 bx lr
 *   @0x226274 mov r0, #0
 *   @0x226278 bx lr
 *
 * ══ §302/828 oggpack_writecheck  0x2332a0  size 40  10 条（0x2332a0..0x2332c8）
 * @func 0x2332a0 0x2332c8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2332a0 ldr r3, [r0, #0xc]
 *   @0x2332a4 cmp r3, #0
 *   @0x2332a8 beq 0x2332c0 <oggpack_writecheck+0x20>
 *   @0x2332ac ldr r0, [r0, #0x10]
 *   @0x2332b0 cmp r0, #0
 *   @0x2332b4 movne r0, #0
 *   @0x2332b8 mvneq r0, #0
 *   @0x2332bc bx lr
 *   @0x2332c0 mvn r0, #0
 *   @0x2332c4 bx lr
 *
 * ══ §303/828 oggpack_reset  0x233370  size 40  10 条（0x233370..0x233398）
 * @func 0x233370 0x233398  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233370 ldr r3, [r0, #0xc]
 *   @0x233374 cmp r3, #0
 *   @0x233378 bxeq lr
 *   @0x23337c ldr r2, [r0, #0x8]
 *   @0x233380 mov r3, #0
 *   @0x233384 str r2, [r0, #0xc]
 *   @0x233388 strb r3, [r2]
 *   @0x23338c str r3, [r0]
 *   @0x233390 str r3, [r0, #0x4]
 *   @0x233394 bx lr
 *
 * ══ §304/828 oggpack_writecopy  0x233808  size 40  10 条（0x233808..0x233830）
 * @func 0x233808 0x233840  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2336e0
 * 字段偏移 top8: 0x-4×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233808 str lr, [sp, #-0x4]!
 *   @0x23380c sub sp, sp, #12
 *   @0x233810 ldr r3, [pc, #0x14]
 *   @0x233814 mov r12, #0
 *   @0x233818 str r12, [sp]
 *   @0x23381c ldr r3, [pc, r3]
 *   @0x233820 bl 0x2336e0 <oggpackB_writealign+0x18>
 *   @0x233824 add sp, sp, #12
 *   @0x233828 ldr pc, [sp], #4
 *   @0x23382c andseq sp, r11, r8, ror r12
 *
 * ══ §305/828 oggpackB_writecopy  0x233830  size 40  10 条（0x233830..0x233858）
 * @func 0x233830 0x233858  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2336e0
 * 字段偏移 top8: 0x-4×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233830 str lr, [sp, #-0x4]!
 *   @0x233834 sub sp, sp, #12
 *   @0x233838 ldr r3, [pc, #0x14]
 *   @0x23383c mov r12, #1
 *   @0x233840 str r12, [sp]
 *   @0x233844 ldr r3, [pc, r3]
 *   @0x233848 bl 0x2336e0 <oggpackB_writealign+0x18>
 *   @0x23384c add sp, sp, #12
 *   @0x233850 ldr pc, [sp], #4
 *   @0x233854 andseq sp, r11, r4, asr r12
 *
 * ══ §306/828 oggpack_look1  0x233a28  size 40  10 条（0x233a28..0x233a50）
 * @func 0x233a28 0x233a60  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233a28 ldr r2, [r0]
 *   @0x233a2c ldr r3, [r0, #0x10]
 *   @0x233a30 cmp r2, r3
 *   @0x233a34 ldrlt r2, [r0, #0xc]
 *   @0x233a38 ldrlt r3, [r0, #0x4]
 *   @0x233a3c ldrblt r0, [r2]
 *   @0x233a40 asrlt r0, r0, r3
 *   @0x233a44 andlt r0, r0, #1
 *   @0x233a48 mvnge r0, #0
 *   @0x233a4c bx lr
 *
 * ══ §307/828 IniFile::ReadInt(char const*, char const*, int)  0x235b1c  size 40  10 条（0x235b1c..0x235b44）
 * @func 0x235b1c 0x235b44  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235b1c push {r4, lr}
 *   @0x235b20 mov r4, r3
 *   @0x235b24 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x235b28 cmp r0, #0
 *   @0x235b2c beq 0x235b3c <_ZN7IniFile7ReadIntEPKcS1_i+0x20>
 *   @0x235b30 ldr r0, [r0, #0x8]
 *   @0x235b34 pop {r4, lr}
 *   @0x235b38 b 0xb66b8 <atoi@plt>
 *   @0x235b3c mov r0, r4
 *   @0x235b40 pop {r4, pc}
 *
 * ══ §308/828 b2Shape::~b2Shape()  0x2363dc  size 40  10 条（0x2363dc..0x236404）
 * @func 0x2363dc 0x236404  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2363dc ldr r3, [pc, #0x1c]
 *   @0x2363e0 push {r4, lr}
 *   @0x2363e4 ldr r3, [pc, r3]
 *   @0x2363e8 mov r4, r0
 *   @0x2363ec add r3, r3, #8
 *   @0x2363f0 str r3, [r0]
 *   @0x2363f4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2363f8 mov r0, r4
 *   @0x2363fc pop {r4, pc}
 *   @0x236400 ldrheq r11, [r11], -r12
 *
 * ══ §309/828 b2ContactListener::~b2ContactListener()  0x237adc  size 40  10 条（0x237adc..0x237b04）
 * @func 0x237adc 0x237b04  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237adc ldr r3, [pc, #0x1c]
 *   @0x237ae0 push {r4, lr}
 *   @0x237ae4 ldr r3, [pc, r3]
 *   @0x237ae8 mov r4, r0
 *   @0x237aec add r3, r3, #8
 *   @0x237af0 str r3, [r0]
 *   @0x237af4 bl 0x27d1d0 <_ZdlPv>
 *   @0x237af8 mov r0, r4
 *   @0x237afc pop {r4, pc}
 *   @0x237b00 ldrsbeq r9, [r11], -r12
 *
 * ══ §310/828 CRunnerContactListener::~CRunnerContactListener()  0x23be6c  size 40  10 条（0x23be6c..0x23be94）
 * @func 0x23be6c 0x23be94  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be6c ldr r3, [pc, #0x1c]
 *   @0x23be70 push {r4, lr}
 *   @0x23be74 ldr r3, [pc, r3]
 *   @0x23be78 mov r4, r0
 *   @0x23be7c add r3, r3, #8
 *   @0x23be80 str r3, [r0]
 *   @0x23be84 bl 0x27d1d0 <_ZdlPv>
 *   @0x23be88 mov r0, r4
 *   @0x23be8c pop {r4, pc}
 *   @0x23be90 andseq r5, r11, r12, asr #12
 *
 * ══ §311/828 CRunnerContactListener::BeginContact(b2Contact*)  0x23be9c  size 40  10 条（0x23be9c..0x23bec4）
 * @func 0x23be9c 0x23bec4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×2 / 0x30×1 / 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be9c ldr r3, [r1, #0x30]
 *   @0x23bea0 ldrb r3, [r3, #0x2c]
 *   @0x23bea4 cmp r3, #0
 *   @0x23bea8 bne 0x23bebc <_ZN22CRunnerContactListener12BeginContactEP9b2Contact+0x20>
 *   @0x23beac ldr r3, [r1, #0x34]
 *   @0x23beb0 ldrb r3, [r3, #0x2c]
 *   @0x23beb4 cmp r3, #0
 *   @0x23beb8 bxeq lr
 *   @0x23bebc ldr r0, [r0, #0x4]
 *   @0x23bec0 b 0x238204 <_ZN13CPhysicsWorld21RegisterContactResultEP9b2Contact>
 *
 * ══ §312/828 b2Draw::~b2Draw()  0x23c178  size 40  10 条（0x23c178..0x23c1a0）
 * @func 0x23c178 0x23c1b0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c178 ldr r3, [pc, #0x1c]
 *   @0x23c17c push {r4, lr}
 *   @0x23c180 ldr r3, [pc, r3]
 *   @0x23c184 mov r4, r0
 *   @0x23c188 add r3, r3, #8
 *   @0x23c18c str r3, [r0]
 *   @0x23c190 bl 0x27d1d0 <_ZdlPv>
 *   @0x23c194 mov r0, r4
 *   @0x23c198 pop {r4, pc}
 *   @0x23c19c andseq r5, r11, r12, ror #6
 *
 * ══ §313/828 CPhysicsDebugRender::~CPhysicsDebugRender()  0x23c1a0  size 40  10 条（0x23c1a0..0x23c1c8）
 * @func 0x23c1a0 0x23c1c8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c1a0 ldr r3, [pc, #0x1c]
 *   @0x23c1a4 push {r4, lr}
 *   @0x23c1a8 ldr r3, [pc, r3]
 *   @0x23c1ac mov r4, r0
 *   @0x23c1b0 add r3, r3, #8
 *   @0x23c1b4 str r3, [r0]
 *   @0x23c1b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x23c1bc mov r0, r4
 *   @0x23c1c0 pop {r4, pc}
 *   @0x23c1c4 andseq r5, r11, r4, asr #6
 *
 * ══ §314/828 F_JSFinishCatch(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c6a4  size 40  10 条（0x23c6a4..0x23c6cc）
 * @func 0x23c6a4 0x23c6cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c6a4 ldr r2, [pc, #0x18]
 *   @0x23c6a8 mov r1, #0
 *   @0x23c6ac ldr r3, [pc, #0x14]
 *   @0x23c6b0 ldr r2, [pc, r2]
 *   @0x23c6b4 ldr r3, [pc, r3]
 *   @0x23c6b8 strb r1, [r2]
 *   @0x23c6bc str r1, [r3]
 *   @0x23c6c0 bx lr
 *   @0x23c6c4 andseq r4, r11, r4, asr #28
 *   @0x23c6c8 andseq r1, r11, r8, ror r6
 *
 * ══ §315/828 COwnedObject::~COwnedObject()  0x23c6ec  size 40  10 条（0x23c6ec..0x23c714）
 * @func 0x23c6ec 0x23c714  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c6ec ldr r3, [pc, #0x1c]
 *   @0x23c6f0 push {r4, lr}
 *   @0x23c6f4 ldr r3, [pc, r3]
 *   @0x23c6f8 mov r4, r0
 *   @0x23c6fc add r3, r3, #8
 *   @0x23c700 str r3, [r0]
 *   @0x23c704 bl 0x27d1d0 <_ZdlPv>
 *   @0x23c708 mov r0, r4
 *   @0x23c70c pop {r4, pc}
 *   @0x23c710 ldrsheq r4, [r11], -r12
 *
 * ══ §316/828 myisinf(double)  0x24364c  size 40  10 条（0x24364c..0x243674）
 * @func 0x24364c 0x243674  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24364c mov r3, #0
 *   @0x243650 movt r3, #0x7ff0
 *   @0x243654 mov r2, #0
 *   @0x243658 and r1, r1, r3
 *   @0x24365c and r0, r0, r2
 *   @0x243660 cmp r1, r3
 *   @0x243664 cmpeq r0, r2
 *   @0x243668 movne r0, #0
 *   @0x24366c moveq r0, #1
 *   @0x243670 bx lr
 *
 * ══ §317/828 TimeFromYear(double)  0x244b68  size 40  10 条（0x244b68..0x244b90）
 * @func 0x244b68 0x244b90  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DayFromYear(double)
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244b68 push {r3, lr}
 *   @0x244b6c bl 0x244aa8 <_Z11DayFromYeard>
 *   @0x244b70 vldr d7, [pc, #16]
 *   @0x244b74 vmov d6, r0, r1
 *   @0x244b78 vmul.f64 d6, d6, d7
 *   @0x244b7c vmov r0, r1, d6
 *   @0x244b80 pop {r3, pc}
 *   @0x244b84 nop
 *   @0x244b88 andeq r0, r0, r0
 *   @0x244b8c orrsmi r9, r4, r0, ror r9
 *
 * ══ §318/828 CHashMap<char const*, int, 3>::~CHashMap()  0x27c42c  size 40  10 条（0x27c42c..0x27c454）
 * @func 0x27c42c 0x27c454  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c42c push {r4, lr}
 *   @0x27c430 mov r4, r0
 *   @0x27c434 ldr r0, [r0, #0x10]
 *   @0x27c438 cmp r0, #0
 *   @0x27c43c beq 0x27c44c <_ZN8CHashMapIPKciLi3EED2Ev+0x20>
 *   @0x27c440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27c444 mov r3, #0
 *   @0x27c448 str r3, [r4, #0x10]
 *   @0x27c44c mov r0, r4
 *   @0x27c450 pop {r4, pc}
 *
 * ══ §319/828 json_object_new_null  0x27ec98  size 40  10 条（0x27ec98..0x27ecc0）
 * @func 0x27ec98 0x27ecc0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ec98 push {r3, lr}
 *   @0x27ec9c mov r0, #0
 *   @0x27eca0 bl 0x27e724 <mc_info+0x35c>
 *   @0x27eca4 cmp r0, #0
 *   @0x27eca8 popeq {r3, pc}
 *   @0x27ecac ldr r3, [pc, #0x8]
 *   @0x27ecb0 add r3, pc, r3
 *   @0x27ecb4 str r3, [r0, #0x8]
 *   @0x27ecb8 pop {r3, pc}
 *   @0x27ecbc .word 0xfffff780
 *
 * ══ §320/828 spSkeleton_getAttachmentForSlotName  0x28a370  size 40  10 条（0x28a370..0x28a398）
 * @func 0x28a370 0x28a398  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findSlotIndex
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a370 push {r3, r4, r5, lr}
 *   @0x28a374 mov r4, r0
 *   @0x28a378 ldr r0, [r0]
 *   @0x28a37c mov r5, r2
 *   @0x28a380 bl 0x28b0cc <spSkeletonData_findSlotIndex>
 *   @0x28a384 mov r2, r5
 *   @0x28a388 mov r1, r0
 *   @0x28a38c mov r0, r4
 *   @0x28a390 pop {r3, r4, r5, lr}
 *   @0x28a394 b 0x28a314 <spSkeleton_getAttachmentForSlotIndex>
 *
 * ══ §321/828 spSkin_addAttachment  0x28ecd8  size 40  10 条（0x28ecd8..0x28ed00）
 * @func 0x28ecd8 0x28ed00  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Entry_create
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ecd8 push {r4, lr}
 *   @0x28ecdc mov r4, r0
 *   @0x28ece0 mov r0, r1
 *   @0x28ece4 mov r1, r2
 *   @0x28ece8 mov r2, r3
 *   @0x28ecec bl 0x28ebb8 <_Entry_create>
 *   @0x28ecf0 ldr r3, [r4, #0x4]
 *   @0x28ecf4 str r3, [r0, #0xc]
 *   @0x28ecf8 str r0, [r4, #0x4]
 *   @0x28ecfc pop {r4, pc}
 *
 * ══ §322/828 Java_com_yoyogames_runner_RunnerJNILib_BackKeyLongPressEvent  0x292f5c  size 40  10 条（0x292f5c..0x292f84）
 * @func 0x292f5c 0x292f84  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292f5c push {r3, lr}
 *   @0x292f60 bl 0x290614 <setJNIEnv>
 *   @0x292f64 ldr r3, [pc, #0x14]
 *   @0x292f68 ldr r3, [pc, r3]
 *   @0x292f6c ldrb r3, [r3]
 *   @0x292f70 cmp r3, #0
 *   @0x292f74 popeq {r3, pc}
 *   @0x292f78 pop {r3, lr}
 *   @0x292f7c b 0x10c320 <_Z14YYGML_game_endv>
 *   @0x292f80 andseq r10, r5, r8, asr #25
 *
 * ══ §323/828 cmpDumpNode(void const*, void const*)  0x29ffc4  size 40  10 条（0x29ffc4..0x29ffec）
 * @func 0x29ffc4 0x29ffec  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: cmpDumpNode(void const*, void const*)+0x20
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ffc4 ldrd r2, r3, [r0, #16]
 *   @0x29ffc8 ldrd r0, r1, [r1, #16]
 *   @0x29ffcc cmp r3, r1
 *   @0x29ffd0 cmpeq r2, r0
 *   @0x29ffd4 blo 0x29ffe4 <_Z11cmpDumpNodePKvS0_+0x20>
 *   @0x29ffd8 movls r0, #0
 *   @0x29ffdc mvnhi r0, #0
 *   @0x29ffe0 bx lr
 *   @0x29ffe4 mov r0, #1
 *   @0x29ffe8 bx lr
 *
 * ══ §324/828 CProfiler::ProfileDump()  0x2a1470  size 40  10 条（0x2a1470..0x2a1498）
 * @func 0x2a1470 0x2a1498  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x15×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a1470 ldrb r2, [r0, #0x10]
 *   @0x2a1474 cmp r2, #0
 *   @0x2a1478 bxeq lr
 *   @0x2a147c ldrb r2, [r0, #0x15]
 *   @0x2a1480 cmp r2, #0
 *   @0x2a1484 bxeq lr
 *   @0x2a1488 ldr r3, [r0, #0x18]
 *   @0x2a148c cmp r3, #0
 *   @0x2a1490 bxeq lr
 *   @0x2a1494 b 0x2a0ea0 <_ZN9CProfiler15DumpProfileDataEv>
 *
 * ══ §325/828 SetDebugMode(bool)  0x2a28ec  size 40  10 条（0x2a28ec..0x2a2914）
 * @func 0x2a28ec 0x2a2914  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Setup_SetupDataStructureFunctions(bool)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a28ec ldr r3, [pc, #0x1c]
 *   @0x2a28f0 push {r4, lr}
 *   @0x2a28f4 ldr r3, [pc, r3]
 *   @0x2a28f8 mov r4, r0
 *   @0x2a28fc strb r0, [r3]
 *   @0x2a2900 bl 0x1004ec <_Z33Setup_SetupDataStructureFunctionsb>
 *   @0x2a2904 mov r0, r4
 *   @0x2a2908 pop {r4, lr}
 *   @0x2a290c b 0xca678 <_Z27Setup_VertexBufferFunctionsb>
 *   @0x2a2910 mulseq r4, r12, r5
 *
 * ══ §326/828 zip_error_get_sys_type  0x2a4360  size 40  10 条（0x2a4360..0x2a4388）
 * @func 0x2a4360 0x2a4388  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4360 cmp r0, #0x0
 *   @0x2a4364 ldr r3, [pc, #0x18]
 *   @0x2a4368 ldr r3, [r3]
 *   @0x2a436c cmp r0, r3
 *   @0x2a4370 ldr r3, [pc, #0x10]
 *   @0x2a4374 ldr r3, [r3]
 *   @0x2a4378 ldrbmi r0, [r0, -r0, lsr #32]!
 *   @0x2a437c movs r0, #0x0
 *   @0x2a4380 bvc 0x2a43c0 <zip_fclose+0x38>
 *   @0x2a4384 bvc 0x2a43b4 <zip_fclose+0x2c>
 *
 * ══ §327/828 png_set_sig_bytes  0x2a5a24  size 40  10 条（0x2a5a24..0x2a5a4c）
 * @func 0x2a5a24 0x2a5a4c  size 40  10 条
 * 部分覆盖: 本节 10/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_sig_bytes+0x1a / png_error
 * 字段偏移 top8: 0x10×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5a24 push {r3, r4, r5, lr}
 *   @0x2a5a28 cbz r0, 0x2a5a44 <png_set_sig_bytes+0x20>
 *   @0x2a5a2c blt 0x2a5a3e <png_set_sig_bytes+0x1a>
 *   @0x2a5a30 mov r4, r1
 *   @0x2a5a34 ldr r1, [pc, #0x10]
 *   @0x2a5a38 bl 0x2a642c <png_error>
 *   @0x2a5a3c b 0x2a5a40 <png_set_sig_bytes+0x1c>
 *   @0x2a5a40 strb.w r4, [r5, #0x1f0]
 *   @0x2a5a44 pop {r3, r4, r5, pc}
 *   @0x2a5a48 str r4, [r4, #0x7c]
 *
 * ══ §328/828 png_destroy_info_struct  0x2a5ef8  size 40  10 条（0x2a5ef8..0x2a5f20）
 * @func 0x2a5ef8 0x2a5f20  size 40  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_info_destroy
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5ef8 push {r4, r5, r6, lr}
 *   @0x2a5efc mov r6, r0
 *   @0x2a5f00 cbz r1, 0x2a5f1e <png_destroy_info_struct+0x26>
 *   @0x2a5f04 cbz r5, 0x2a5f1e <png_destroy_info_struct+0x26>
 *   @0x2a5f08 bl 0x2a5ebe <png_info_destroy>
 *   @0x2a5f0c mov r0, r5
 *   @0x2a5f10 .word 0xf8d612f0
 *   @0x2a5f14 .word 0xf00022e8
 *   @0x2a5f18 movwhs pc, #0xea2
 *   @0x2a5f1c str r3, [r4]
 *
 * ══ §329/828 png_get_pixels_per_meter  0x2a6622  size 40  10 条（0x2a6622..0x2a664a）
 * @func 0x2a6622 0x2a664a  size 40  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6622 cbz r0, 0x2a6648 <png_get_pixels_per_meter+0x26>
 *   @0x2a6626 ldr r0, [r1, #0x8]
 *   @0x2a662a andle r0, r12, r0, lsl #1
 *   @0x2a662e ldrb.w r3, [r1, #0x78]
 *   @0x2a6632 cmp r3, #0x1
 *   @0x2a6636 ldr r3, [r1, #0x70]
 *   @0x2a663a cmp r3, r0
 *   @0x2a663e movne r0, #0x0
 *   @0x2a6642 mov r0, r1
 *   @0x2a6646 movs r0, #0x0
 *
 * ══ §330/828 png_get_uint_31  0x2abb6c  size 40  10 条（0x2abb6c..0x2abb94）
 * @func 0x2abb6c 0x2abb94  size 40  10 条
 * 部分覆盖: 本节 10/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error
 * 字段偏移 top8: 0x3×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abb6c push {r4, lr}
 *   @0x2abb70 ldrb r2, [r1]
 *   @0x2abb74 add.w r3, r3, r2, lsl #24
 *   @0x2abb78 ldrb r2, [r1, #0x3]
 *   @0x2abb7c ldrb r2, [r1, #0x2]
 *   @0x2abb80 strle r2, [r3, #-0x402]
 *   @0x2abb84 ldr r1, [pc, #0x8]
 *   @0x2abb88 bl 0x2a642c <png_error>
 *   @0x2abb8c mov r0, r4
 *   @0x2abb90 lsrs r3, r7, #0x1f
 *
 * ══ §331/828 b2CircleShape::~b2CircleShape()  0x2c4e74  size 40  10 条（0x2c4e74..0x2c4e9c）
 * @func 0x2c4e74 0x2c4e9c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4e74 ldr r3, [pc, #0x1c]
 *   @0x2c4e78 push {r4, lr}
 *   @0x2c4e7c ldr r3, [pc, r3]
 *   @0x2c4e80 mov r4, r0
 *   @0x2c4e84 add r3, r3, #8
 *   @0x2c4e88 str r3, [r0]
 *   @0x2c4e8c bl 0x27d1d0 <_ZdlPv>
 *   @0x2c4e90 mov r0, r4
 *   @0x2c4e94 pop {r4, pc}
 *   @0x2c4e98 andseq r12, r2, r4, lsr #12
 *
 * ══ §332/828 b2EdgeShape::~b2EdgeShape()  0x2c5258  size 40  10 条（0x2c5258..0x2c5280）
 * @func 0x2c5258 0x2c5280  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5258 ldr r3, [pc, #0x1c]
 *   @0x2c525c push {r4, lr}
 *   @0x2c5260 ldr r3, [pc, r3]
 *   @0x2c5264 mov r4, r0
 *   @0x2c5268 add r3, r3, #8
 *   @0x2c526c str r3, [r0]
 *   @0x2c5270 bl 0x27d1d0 <_ZdlPv>
 *   @0x2c5274 mov r0, r4
 *   @0x2c5278 pop {r4, pc}
 *   @0x2c527c andseq r12, r2, r0, asr #4
 *
 * ══ §333/828 b2PolygonShape::~b2PolygonShape()  0x2c5ba8  size 40  10 条（0x2c5ba8..0x2c5bd0）
 * @func 0x2c5ba8 0x2c5bd0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5ba8 ldr r3, [pc, #0x1c]
 *   @0x2c5bac push {r4, lr}
 *   @0x2c5bb0 ldr r3, [pc, r3]
 *   @0x2c5bb4 mov r4, r0
 *   @0x2c5bb8 add r3, r3, #8
 *   @0x2c5bbc str r3, [r0]
 *   @0x2c5bc0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2c5bc4 mov r0, r4
 *   @0x2c5bc8 pop {r4, pc}
 *   @0x2c5bcc ldrsheq r11, [r2], -r0
 *
 * ══ §334/828 b2ContactFilter::~b2ContactFilter()  0x2c7828  size 40  10 条（0x2c7828..0x2c7850）
 * @func 0x2c7828 0x2c7850  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7828 ldr r3, [pc, #0x1c]
 *   @0x2c782c push {r4, lr}
 *   @0x2c7830 ldr r3, [pc, r3]
 *   @0x2c7834 mov r4, r0
 *   @0x2c7838 add r3, r3, #8
 *   @0x2c783c str r3, [r0]
 *   @0x2c7840 bl 0x27d1d0 <_ZdlPv>
 *   @0x2c7844 mov r0, r4
 *   @0x2c7848 pop {r4, pc}
 *   @0x2c784c ldrheq r10, [r2], -r0
 *
 * ══ §335/828 b2World::CreateParticle(b2ParticleDef const&)  0x2cb4a4  size 40  10 条（0x2cb4a4..0x2cb4cc）
 * @func 0x2cb4a4 0x2cb4cc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb4a4 movw r3, #0x91d4
 *   @0x2cb4a8 movt r3, #0x1
 *   @0x2cb4ac ldr r3, [r0, r3]
 *   @0x2cb4b0 tst r3, #2
 *   @0x2cb4b4 beq 0x2cb4c0 <_ZN7b2World14CreateParticleERK13b2ParticleDef+0x1c>
 *   @0x2cb4b8 mov r0, #0
 *   @0x2cb4bc bx lr
 *   @0x2cb4c0 add r0, r0, #102400
 *   @0x2cb4c4 add r0, r0, #628
 *   @0x2cb4c8 b 0x2da108 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef>
 *
 * ══ §336/828 b2World::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool)  0x2cb4d8  size 40  10 条（0x2cb4d8..0x2cb500）
 * @func 0x2cb4d8 0x2cb510  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb4d8 movw r12, #0x91d4
 *   @0x2cb4dc movt r12, #0x1
 *   @0x2cb4e0 ldr r12, [r0, r12]
 *   @0x2cb4e4 tst r12, #2
 *   @0x2cb4e8 beq 0x2cb4f4 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb+0x1c>
 *   @0x2cb4ec mov r0, #0
 *   @0x2cb4f0 bx lr
 *   @0x2cb4f4 add r0, r0, #102400
 *   @0x2cb4f8 add r0, r0, #628
 *   @0x2cb4fc b 0x2d523c <_ZN16b2ParticleSystem23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb>
 *
 * ══ §337/828 b2World::CreateParticleGroup(b2ParticleGroupDef const&)  0x2cb500  size 40  10 条（0x2cb500..0x2cb528）
 * @func 0x2cb500 0x2cb538  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb500 movw r3, #0x91d4
 *   @0x2cb504 movt r3, #0x1
 *   @0x2cb508 ldr r3, [r0, r3]
 *   @0x2cb50c tst r3, #2
 *   @0x2cb510 bne 0x2cb520 <_ZN7b2World19CreateParticleGroupERK18b2ParticleGroupDef+0x20>
 *   @0x2cb514 add r0, r0, #102400
 *   @0x2cb518 add r0, r0, #628
 *   @0x2cb51c b 0x2dacd0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef>
 *   @0x2cb520 mov r0, #0
 *   @0x2cb524 bx lr
 *
 * ══ §338/828 b2Contact::~b2Contact()  0x2cbe24  size 40  10 条（0x2cbe24..0x2cbe4c）
 * @func 0x2cbe24 0x2cbe4c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbe24 ldr r3, [pc, #0x1c]
 *   @0x2cbe28 push {r4, lr}
 *   @0x2cbe2c ldr r3, [pc, r3]
 *   @0x2cbe30 mov r4, r0
 *   @0x2cbe34 add r3, r3, #8
 *   @0x2cbe38 str r3, [r0]
 *   @0x2cbe3c bl 0x27d1d0 <_ZdlPv>
 *   @0x2cbe40 mov r0, r4
 *   @0x2cbe44 pop {r4, pc}
 *   @0x2cbe48 ldrsbeq r5, [r2], -r4
 *
 * ══ §339/828 b2EdgeAndCircleContact::~b2EdgeAndCircleContact()  0x2cc498  size 40  10 条（0x2cc498..0x2cc4c0）
 * @func 0x2cc498 0x2cc4c0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc498 ldr r3, [pc, #0x1c]
 *   @0x2cc49c push {r4, lr}
 *   @0x2cc4a0 ldr r3, [pc, r3]
 *   @0x2cc4a4 mov r4, r0
 *   @0x2cc4a8 add r3, r3, #8
 *   @0x2cc4ac str r3, [r0]
 *   @0x2cc4b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cc4b4 mov r0, r4
 *   @0x2cc4b8 pop {r4, pc}
 *   @0x2cc4bc andseq r5, r2, r0, ror #12
 *
 * ══ §340/828 b2EdgeAndPolygonContact::~b2EdgeAndPolygonContact()  0x2cc5a8  size 40  10 条（0x2cc5a8..0x2cc5d0）
 * @func 0x2cc5a8 0x2cc5d0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc5a8 ldr r3, [pc, #0x1c]
 *   @0x2cc5ac push {r4, lr}
 *   @0x2cc5b0 ldr r3, [pc, r3]
 *   @0x2cc5b4 mov r4, r0
 *   @0x2cc5b8 add r3, r3, #8
 *   @0x2cc5bc str r3, [r0]
 *   @0x2cc5c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cc5c4 mov r0, r4
 *   @0x2cc5c8 pop {r4, pc}
 *   @0x2cc5cc andseq r5, r2, r0, asr r5
 *
 * ══ §341/828 b2PolygonAndCircleContact::~b2PolygonAndCircleContact()  0x2cc6b8  size 40  10 条（0x2cc6b8..0x2cc6e0）
 * @func 0x2cc6b8 0x2cc6e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc6b8 ldr r3, [pc, #0x1c]
 *   @0x2cc6bc push {r4, lr}
 *   @0x2cc6c0 ldr r3, [pc, r3]
 *   @0x2cc6c4 mov r4, r0
 *   @0x2cc6c8 add r3, r3, #8
 *   @0x2cc6cc str r3, [r0]
 *   @0x2cc6d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cc6d4 mov r0, r4
 *   @0x2cc6d8 pop {r4, pc}
 *   @0x2cc6dc andseq r5, r2, r0, asr #8
 *
 * ══ §342/828 b2PolygonContact::~b2PolygonContact()  0x2cc7c8  size 40  10 条（0x2cc7c8..0x2cc7f0）
 * @func 0x2cc7c8 0x2cc7f0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc7c8 ldr r3, [pc, #0x1c]
 *   @0x2cc7cc push {r4, lr}
 *   @0x2cc7d0 ldr r3, [pc, r3]
 *   @0x2cc7d4 mov r4, r0
 *   @0x2cc7d8 add r3, r3, #8
 *   @0x2cc7dc str r3, [r0]
 *   @0x2cc7e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cc7e4 mov r0, r4
 *   @0x2cc7e8 pop {r4, pc}
 *   @0x2cc7ec andseq r5, r2, r0, lsr r3
 *
 * ══ §343/828 b2DistanceJoint::GetReactionForce(float) const  0x2cca60  size 40  10 条（0x2cca60..0x2cca88）
 * @func 0x2cca60 0x2cca88  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cca60 vmov s14, r2
 *   @0x2cca64 vldr s15, [r1, #100]
 *   @0x2cca68 vldr s13, [r1, #116]
 *   @0x2cca6c vmul.f32 s15, s14, s15
 *   @0x2cca70 vldr s14, [r1, #120]
 *   @0x2cca74 vmul.f32 s14, s15, s14
 *   @0x2cca78 vmul.f32 s15, s15, s13
 *   @0x2cca7c vstr s14, [r0, #4]
 *   @0x2cca80 vstr s15, [r0]
 *   @0x2cca84 bx lr
 *
 * ══ §344/828 b2Joint::~b2Joint()  0x2ccbe0  size 40  10 条（0x2ccbe0..0x2ccc08）
 * @func 0x2ccbe0 0x2ccc18  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ccbe0 ldr r3, [pc, #0x1c]
 *   @0x2ccbe4 push {r4, lr}
 *   @0x2ccbe8 ldr r3, [pc, r3]
 *   @0x2ccbec mov r4, r0
 *   @0x2ccbf0 add r3, r3, #8
 *   @0x2ccbf4 str r3, [r0]
 *   @0x2ccbf8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2ccbfc mov r0, r4
 *   @0x2ccc00 pop {r4, pc}
 *   @0x2ccc04 andseq r4, r2, r12, ror #30
 *
 * ══ §345/828 b2DistanceJoint::~b2DistanceJoint()  0x2ccc08  size 40  10 条（0x2ccc08..0x2ccc30）
 * @func 0x2ccc08 0x2ccc30  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ccc08 ldr r3, [pc, #0x1c]
 *   @0x2ccc0c push {r4, lr}
 *   @0x2ccc10 ldr r3, [pc, r3]
 *   @0x2ccc14 mov r4, r0
 *   @0x2ccc18 add r3, r3, #8
 *   @0x2ccc1c str r3, [r0]
 *   @0x2ccc20 bl 0x27d1d0 <_ZdlPv>
 *   @0x2ccc24 mov r0, r4
 *   @0x2ccc28 pop {r4, pc}
 *   @0x2ccc2c andseq r4, r2, r4, asr #30
 *
 * ══ §346/828 b2FrictionJoint::~b2FrictionJoint()  0x2cd500  size 40  10 条（0x2cd500..0x2cd528）
 * @func 0x2cd500 0x2cd528  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd500 ldr r3, [pc, #0x1c]
 *   @0x2cd504 push {r4, lr}
 *   @0x2cd508 ldr r3, [pc, r3]
 *   @0x2cd50c mov r4, r0
 *   @0x2cd510 add r3, r3, #8
 *   @0x2cd514 str r3, [r0]
 *   @0x2cd518 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cd51c mov r0, r4
 *   @0x2cd520 pop {r4, pc}
 *   @0x2cd524 andseq r4, r2, r12, asr #12
 *
 * ══ §347/828 b2Joint::IsActive() const  0x2cdf94  size 40  10 条（0x2cdf94..0x2cdfbc）
 * @func 0x2cdf94 0x2cdfbc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdf94 ldr r3, [r0, #0x30]
 *   @0x2cdf98 ldrh r3, [r3, #4]
 *   @0x2cdf9c and r3, r3, #32
 *   @0x2cdfa0 uxth r3, r3
 *   @0x2cdfa4 cmp r3, #0
 *   @0x2cdfa8 ldrne r3, [r0, #0x34]
 *   @0x2cdfac ldrhne r0, [r3, #4]
 *   @0x2cdfb0 ubfxne r0, r0, #0x5, #0x1
 *   @0x2cdfb4 moveq r0, r3
 *   @0x2cdfb8 bx lr
 *
 * ══ §348/828 b2MotorJoint::~b2MotorJoint()  0x2ce164  size 40  10 条（0x2ce164..0x2ce18c）
 * @func 0x2ce164 0x2ce18c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce164 ldr r3, [pc, #0x1c]
 *   @0x2ce168 push {r4, lr}
 *   @0x2ce16c ldr r3, [pc, r3]
 *   @0x2ce170 mov r4, r0
 *   @0x2ce174 add r3, r3, #8
 *   @0x2ce178 str r3, [r0]
 *   @0x2ce17c bl 0x27d1d0 <_ZdlPv>
 *   @0x2ce180 mov r0, r4
 *   @0x2ce184 pop {r4, pc}
 *   @0x2ce188 andseq r3, r2, r8, ror #19
 *
 * ══ §349/828 b2MouseJoint::~b2MouseJoint()  0x2cea2c  size 40  10 条（0x2cea2c..0x2cea54）
 * @func 0x2cea2c 0x2cea54  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cea2c ldr r3, [pc, #0x1c]
 *   @0x2cea30 push {r4, lr}
 *   @0x2cea34 ldr r3, [pc, r3]
 *   @0x2cea38 mov r4, r0
 *   @0x2cea3c add r3, r3, #8
 *   @0x2cea40 str r3, [r0]
 *   @0x2cea44 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cea48 mov r0, r4
 *   @0x2cea4c pop {r4, pc}
 *   @0x2cea50 andseq r3, r2, r0, lsr #2
 *
 * ══ §350/828 b2PrismaticJoint::~b2PrismaticJoint()  0x2cf35c  size 40  10 条（0x2cf35c..0x2cf384）
 * @func 0x2cf35c 0x2cf384  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf35c ldr r3, [pc, #0x1c]
 *   @0x2cf360 push {r4, lr}
 *   @0x2cf364 ldr r3, [pc, r3]
 *   @0x2cf368 mov r4, r0
 *   @0x2cf36c add r3, r3, #8
 *   @0x2cf370 str r3, [r0]
 *   @0x2cf374 bl 0x27d1d0 <_ZdlPv>
 *   @0x2cf378 mov r0, r4
 *   @0x2cf37c pop {r4, pc}
 *   @0x2cf380 ldrsheq r2, [r2], -r0
 *
 * ══ §351/828 b2PulleyJoint::~b2PulleyJoint()  0x2d08ac  size 40  10 条（0x2d08ac..0x2d08d4）
 * @func 0x2d08ac 0x2d08d4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d08ac ldr r3, [pc, #0x1c]
 *   @0x2d08b0 push {r4, lr}
 *   @0x2d08b4 ldr r3, [pc, r3]
 *   @0x2d08b8 mov r4, r0
 *   @0x2d08bc add r3, r3, #8
 *   @0x2d08c0 str r3, [r0]
 *   @0x2d08c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2d08c8 mov r0, r4
 *   @0x2d08cc pop {r4, pc}
 *   @0x2d08d0 andseq r1, r2, r0, lsr #5
 *
 * ══ §352/828 b2RevoluteJoint::~b2RevoluteJoint()  0x2d14e0  size 40  10 条（0x2d14e0..0x2d1508）
 * @func 0x2d14e0 0x2d1508  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d14e0 ldr r3, [pc, #0x1c]
 *   @0x2d14e4 push {r4, lr}
 *   @0x2d14e8 ldr r3, [pc, r3]
 *   @0x2d14ec mov r4, r0
 *   @0x2d14f0 add r3, r3, #8
 *   @0x2d14f4 str r3, [r0]
 *   @0x2d14f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2d14fc mov r0, r4
 *   @0x2d1500 pop {r4, pc}
 *   @0x2d1504 andseq r0, r2, r12, ror #12
 *
 * ══ §353/828 b2RopeJoint::GetReactionForce(float) const  0x2d24ec  size 40  10 条（0x2d24ec..0x2d2514）
 * @func 0x2d24ec 0x2d2514  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d24ec vmov s14, r2
 *   @0x2d24f0 vldr s15, [r1, #92]
 *   @0x2d24f4 vldr s13, [r1, #104]
 *   @0x2d24f8 vmul.f32 s15, s14, s15
 *   @0x2d24fc vldr s14, [r1, #108]
 *   @0x2d2500 vmul.f32 s14, s15, s14
 *   @0x2d2504 vmul.f32 s15, s15, s13
 *   @0x2d2508 vstr s14, [r0, #4]
 *   @0x2d250c vstr s15, [r0]
 *   @0x2d2510 bx lr
 *
 * ══ §354/828 b2RopeJoint::~b2RopeJoint()  0x2d2624  size 40  10 条（0x2d2624..0x2d264c）
 * @func 0x2d2624 0x2d264c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2624 ldr r3, [pc, #0x1c]
 *   @0x2d2628 push {r4, lr}
 *   @0x2d262c ldr r3, [pc, r3]
 *   @0x2d2630 mov r4, r0
 *   @0x2d2634 add r3, r3, #8
 *   @0x2d2638 str r3, [r0]
 *   @0x2d263c bl 0x27d1d0 <_ZdlPv>
 *   @0x2d2640 mov r0, r4
 *   @0x2d2644 pop {r4, pc}
 *   @0x2d2648 andseq pc, r1, r8, lsr #10
 *
 * ══ §355/828 b2WeldJoint::~b2WeldJoint()  0x2d2fd4  size 40  10 条（0x2d2fd4..0x2d2ffc）
 * @func 0x2d2fd4 0x2d2ffc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2fd4 ldr r3, [pc, #0x1c]
 *   @0x2d2fd8 push {r4, lr}
 *   @0x2d2fdc ldr r3, [pc, r3]
 *   @0x2d2fe0 mov r4, r0
 *   @0x2d2fe4 add r3, r3, #8
 *   @0x2d2fe8 str r3, [r0]
 *   @0x2d2fec bl 0x27d1d0 <_ZdlPv>
 *   @0x2d2ff0 mov r0, r4
 *   @0x2d2ff4 pop {r4, pc}
 *   @0x2d2ff8 andseq lr, r1, r8, ror r11
 *
 * ══ §356/828 b2WheelJoint::~b2WheelJoint()  0x2d3b98  size 40  10 条（0x2d3b98..0x2d3bc0）
 * @func 0x2d3b98 0x2d3bc0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3b98 ldr r3, [pc, #0x1c]
 *   @0x2d3b9c push {r4, lr}
 *   @0x2d3ba0 ldr r3, [pc, r3]
 *   @0x2d3ba4 mov r4, r0
 *   @0x2d3ba8 add r3, r3, #8
 *   @0x2d3bac str r3, [r0]
 *   @0x2d3bb0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2d3bb4 mov r0, r4
 *   @0x2d3bb8 pop {r4, pc}
 *   @0x2d3bbc ldrheq sp, [r1], -r4
 *
 * ══ §357/828 b2ParticleGroup::GetCenter() const  0x2d483c  size 40  10 条（0x2d483c..0x2d4864）
 * @func 0x2d483c 0x2d4874  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d483c push {r3, r4, r5, lr}
 *   @0x2d4840 mov r5, r1
 *   @0x2d4844 add r5, r5, #40
 *   @0x2d4848 mov r4, r0
 *   @0x2d484c mov r0, r1
 *   @0x2d4850 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d4854 ldm r5, {r0, r1}
 *   @0x2d4858 stm r4, {r0, r1}
 *   @0x2d485c mov r0, r4
 *   @0x2d4860 pop {r3, r4, r5, pc}
 *
 * ══ §358/828 b2ParticleGroup::GetLinearVelocity() const  0x2d4864  size 40  10 条（0x2d4864..0x2d488c）
 * @func 0x2d4864 0x2d488c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4864 push {r3, r4, r5, lr}
 *   @0x2d4868 mov r5, r1
 *   @0x2d486c add r5, r5, #48
 *   @0x2d4870 mov r4, r0
 *   @0x2d4874 mov r0, r1
 *   @0x2d4878 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d487c ldm r5, {r0, r1}
 *   @0x2d4880 stm r4, {r0, r1}
 *   @0x2d4884 mov r0, r4
 *   @0x2d4888 pop {r3, r4, r5, pc}
 *
 * ══ §359/828 b2QueryCallback::~b2QueryCallback()  0x2d4990  size 40  10 条（0x2d4990..0x2d49b8）
 * @func 0x2d4990 0x2d49b8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4990 ldr r3, [pc, #0x1c]
 *   @0x2d4994 push {r4, lr}
 *   @0x2d4998 ldr r3, [pc, r3]
 *   @0x2d499c mov r4, r0
 *   @0x2d49a0 add r3, r3, #8
 *   @0x2d49a4 str r3, [r0]
 *   @0x2d49a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2d49ac mov r0, r4
 *   @0x2d49b0 pop {r4, pc}
 *   @0x2d49b4 andseq sp, r1, r8, ror #3
 *
 * ══ §360/828 b2ChainAndCircleContact::~b2ChainAndCircleContact()  0x2e1c80  size 40  10 条（0x2e1c80..0x2e1ca8）
 * @func 0x2e1c80 0x2e1ca8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1c80 ldr r3, [pc, #0x1c]
 *   @0x2e1c84 push {r4, lr}
 *   @0x2e1c88 ldr r3, [pc, r3]
 *   @0x2e1c8c mov r4, r0
 *   @0x2e1c90 add r3, r3, #8
 *   @0x2e1c94 str r3, [r0]
 *   @0x2e1c98 bl 0x27d1d0 <_ZdlPv>
 *   @0x2e1c9c mov r0, r4
 *   @0x2e1ca0 pop {r4, pc}
 *   @0x2e1ca4 andseq pc, r0, r8, ror lr
 *
 * ══ §361/828 b2ChainAndPolygonContact::~b2ChainAndPolygonContact()  0x2e1e0c  size 40  10 条（0x2e1e0c..0x2e1e34）
 * @func 0x2e1e0c 0x2e1e34  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1e0c ldr r3, [pc, #0x1c]
 *   @0x2e1e10 push {r4, lr}
 *   @0x2e1e14 ldr r3, [pc, r3]
 *   @0x2e1e18 mov r4, r0
 *   @0x2e1e1c add r3, r3, #8
 *   @0x2e1e20 str r3, [r0]
 *   @0x2e1e24 bl 0x27d1d0 <_ZdlPv>
 *   @0x2e1e28 mov r0, r4
 *   @0x2e1e2c pop {r4, pc}
 *   @0x2e1e30 andseq pc, r0, r12, ror #25
 *
 * ══ §362/828 b2CircleContact::~b2CircleContact()  0x2e1f98  size 40  10 条（0x2e1f98..0x2e1fc0）
 * @func 0x2e1f98 0x2e1fc0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1f98 ldr r3, [pc, #0x1c]
 *   @0x2e1f9c push {r4, lr}
 *   @0x2e1fa0 ldr r3, [pc, r3]
 *   @0x2e1fa4 mov r4, r0
 *   @0x2e1fa8 add r3, r3, #8
 *   @0x2e1fac str r3, [r0]
 *   @0x2e1fb0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2e1fb4 mov r0, r4
 *   @0x2e1fb8 pop {r4, pc}
 *   @0x2e1fbc andseq pc, r0, r0, ror #22
 *
 * ══ §363/828 b2GearJoint::~b2GearJoint()  0x2e3bdc  size 40  10 条（0x2e3bdc..0x2e3c04）
 * @func 0x2e3bdc 0x2e3c04  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3bdc ldr r3, [pc, #0x1c]
 *   @0x2e3be0 push {r4, lr}
 *   @0x2e3be4 ldr r3, [pc, r3]
 *   @0x2e3be8 mov r4, r0
 *   @0x2e3bec add r3, r3, #8
 *   @0x2e3bf0 str r3, [r0]
 *   @0x2e3bf4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2e3bf8 mov r0, r4
 *   @0x2e3bfc pop {r4, pc}
 *   @0x2e3c00 andseq sp, r0, r0, ror pc
 *
 * ══ §364/828 FT_Get_Charmap_Index  0x2e5938  size 40  10 条（0x2e5938..0x2e5960）
 * @func 0x2e5938 0x2e5970  size 56  14 条
 * 部分覆盖: 本节 14/28 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/26 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/24 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5938 push {r4, lr}
 *   @0x2e593c ldr r2, [r0]
 *   @0x2e5940 ldr r4, [r2, #0x24]
 *   @0x2e5944 cmp r3, r4
 *   @0x2e5948 ldr r1, [r2, #0x28]
 *   @0x2e594c addmi r1, r1, #35
 *   @0x2e5950 beq 0x2e595c <FT_Get_Charmap_Index+0x24>
 *   @0x2e5954 b 0x2e5944 <FT_Get_Charmap_Index+0xc>
 *   @0x2e5958 ldclt p0, c3, [r0, #-1020]
 *   @0x2e595c mov r0, r3
 *
 * ══ §365/828 FT_Stream_GetUOffset  0x2e6a32  size 40  10 条（0x2e6a32..0x2e6a5a）
 * @func 0x2e6a32 0x2e6a6a  size 56  14 条
 * 部分覆盖: 本节 14/27 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x1×1 / 0x-3×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6a32 mov r2, r0
 *   @0x2e6a36 ldr r1, [r2, #0x24]
 *   @0x2e6a3a cmp r1, r0
 *   @0x2e6a3e ldrb r0, [r3, #0x1]
 *   @0x2e6a42 ldrb r1, [r3, #-3]
 *   @0x2e6a46 lsls r0, r0, #0x8
 *   @0x2e6a4a .word 0xf8134001
 *   @0x2e6a4e movwmi r1, #0x8c01
 *   @0x2e6a52 b 0x2e6a56 <FT_Stream_GetUOffset+0x24>
 *   @0x2e6a56 str r3, [r2, #0x20]
 *
 * ══ §366/828 FT_Vector_Unit  0x2e6f60  size 40  10 条（0x2e6f60..0x2e6f88）
 * @func 0x2e6f60 0x2e6f88  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Vector_Length+0x16
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6f60 push {r4, lr}
 *   @0x2e6f64 cbz r0, 0x2e6f82 <FT_Vector_Unit+0x22>
 *   @0x2e6f68 movs r3, #0x0
 *   @0x2e6f6c .word 0xf7fd000c
 *   @0x2e6f70 stmdavs r3!, {r0, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e6f74 adds r3, #0x80
 *   @0x2e6f78 str r3, [r4]
 *   @0x2e6f7c adds r3, #0x80
 *   @0x2e6f80 str r3, [r4, #0x4]
 *   @0x2e6f84 bls 0x2e703e <FT_Vector_Length+0x16>
 *
 * ══ §367/828 ft_mem_strcpyn  0x2e88e6  size 40  10 条（0x2e88e6..0x2e890e）
 * @func 0x2e88e6 0x2e890e  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2f1de8+0x5726
 * 字段偏移 top8: 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e88e6 add r2, r0
 *   @0x2e88ea subs r3, r2, r0
 *   @0x2e88ee cmp r3, #0x1
 *   @0x2e88f2 movs r3, #0x0
 *   @0x2e88f6 ldrb r0, [r4]
 *   @0x2e88fa it ne
 *   @0x2e88fe pop {r4, pc}
 *   @0x2e8902 blhs 0x2f750e <ps_hints_apply+0x610e>
 *   @0x2e8906 beq 0x2e88f2 <ft_mem_strcpyn+0xc>
 *   @0x2e890a strb r3, [sp, r1, lsl #22]!
 *
 * ══ §368/828 __floatsidf  0x3190e8  size 40  10 条（0x3190e8..0x319110）
 * @func 0x3190e8 0x319110  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3190e8 teq r0, #0
 *   @0x3190ec moveq r1, #0
 *   @0x3190f0 bxeq lr
 *   @0x3190f4 push {r4, r5, lr}
 *   @0x3190f8 mov r4, #1024
 *   @0x3190fc add r4, r4, #50
 *   @0x319100 ands r5, r0, #-2147483648
 *   @0x319104 rsbmi r0, r0, #0
 *   @0x319108 mov r1, #0
 *   @0x31910c b 0x318f60 <__aeabi_dadd+0x148>
 *
 * ══ §369/828 __floatunsisf  0x319360  size 40  10 条（0x319360..0x319388）
 * @func 0x319360 0x319388  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319360 mov r3, #0
 *   @0x319364 b 0x319370 <__floatsisf+0x8>
 *   @0x319368 ands r3, r0, #-2147483648
 *   @0x31936c rsbmi r0, r0, #0
 *   @0x319370 movs r12, r0
 *   @0x319374 bxeq lr
 *   @0x319378 orr r3, r3, #1258291200
 *   @0x31937c mov r1, r0
 *   @0x319380 mov r0, #0
 *   @0x319384 b 0x3193c8 <__floatdisf+0x30>
 *
 * ══ §370/828 anon_319cc4  0x319cc4  size 40  10 条（0x319cc4..0x319cec）
 * @func 0x319cc4 0x319cec  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Unwind_VRS_Set
 * 字段偏移 top8: 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319cc4 push {r0, r1, r2, r3, r4, lr}
 *   @0x319cc8 add r3, sp, #16
 *   @0x319ccc mov r12, r1
 *   @0x319cd0 mov r1, #0
 *   @0x319cd4 str r2, [r3, #-0x4]!
 *   @0x319cd8 mov r2, r12
 *   @0x319cdc str r3, [sp]
 *   @0x319ce0 mov r3, r1
 *   @0x319ce4 bl 0x319c68 <_Unwind_VRS_Set>
 *   @0x319ce8 add sp, sp, #20
 *
 * ══ §371/828 _zip_entry_free(zip_entry*)  0x2a576a  size 38  10 条（0x2a576a..0x2a5790）
 * @func 0x2a576a 0x2a5792  size 40  10 条
 * 部分覆盖: 本节 10/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a576a push {r3, r4, r5, lr}
 *   @0x2a576e ldr r0, [r0, #0x8]
 *   @0x2a5772 blx 0xb655c <free@plt>
 *   @0x2a5776 ldr r0, [r4, #0xc]
 *   @0x2a577a blx 0xb655c <free@plt>
 *   @0x2a577e mov.w r3, #0xffffffff
 *   @0x2a5782 str r5, [r4, #0xc]
 *   @0x2a5786 str r3, [r4, #0x10]
 *   @0x2a578a .word 0xf0004038
 *   @0x2a578e ldrlt r11, [r8, #-0x933]!
 *
 * ══ §372/828 png_get_gAMA  0x2a6858  size 38  10 条（0x2a6858..0x2a687e）
 * @func 0x2a6858 0x2a688e  size 54  14 条
 * 部分覆盖: 本节 11/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6858 cbz r0, 0x2a687c <png_get_gAMA+0x24>
 *   @0x2a685c ldr r0, [r1, #0x8]
 *   @0x2a6860 andle r0, r11, r1
 *   @0x2a6864 cbz r2, 0x2a687a <png_get_gAMA+0x22>
 *   @0x2a6868 vmov.f32 s14, #1.625000e+00
 *   @0x2a686c andhs r7, r1, r7, asr #21
 *   @0x2a6870 vstr d7, [r2]
 *   @0x2a6874 bx lr
 *   @0x2a6878 bx lr
 *   @0x2a687c bx lr
 *
 * ══ §373/828 png_get_text  0x2a6b10  size 38  10 条（0x2a6b10..0x2a6b36）
 * @func 0x2a6b10 0x2a6b46  size 54  14 条
 * 部分覆盖: 本节 14/27 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_text+0x1a
 * 字段偏移 top8: 0x30×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6b10 cbz r0, 0x2a6b2a <png_get_text+0x1a>
 *   @0x2a6b14 ldr r0, [r1, #0x30]
 *   @0x2a6b18 ble 0x2a6b2a <png_get_text+0x1a>
 *   @0x2a6b1c ldr r0, [r1, #0x38]
 *   @0x2a6b20 cbz r3, 0x2a6b26 <png_get_text+0x16>
 *   @0x2a6b24 str r2, [r3]
 *   @0x2a6b28 bx lr
 *   @0x2a6b2c cbz r3, 0x2a6b32 <png_get_text+0x22>
 *   @0x2a6b30 bx lr
 *   @0x2a6b34 bx lr
 *
 * ══ §374/828 png_write_chunk_end  0x2b1296  size 38  10 条（0x2b1296..0x2b12bc）
 * @func 0x2b1296 0x2b12cc  size 54  14 条
 * 部分覆盖: 本节 11/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_32
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1296 push {r0, r1, r2, r4, r5, lr}
 *   @0x2b129a cbz r0, 0x2b12b8 <png_write_chunk_end+0x22>
 *   @0x2b129e movs r3, #0x82
 *   @0x2b12a2 qasxmi r3, r8, r4
 *   @0x2b12a6 ldr.w r1, [r4, #0x1d4]
 *   @0x2b12aa bl 0x2b1124 <png_save_uint_32>
 *   @0x2b12ae mov r0, r4
 *   @0x2b12b2 movs r2, #0x4
 *   @0x2b12b6 mullt r3, r12, r12
 *   @0x2b12ba pop {r4, r5, pc}
 *
 * ══ §375/828 png_write_chunk  0x2b12bc  size 38  10 条（0x2b12bc..0x2b12e2）
 * @func 0x2b12bc 0x2b12e4  size 40  10 条
 * 部分覆盖: 本节 10/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk_start
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b12bc push {r4, r5, r6, lr}
 *   @0x2b12c0 mov r5, r3
 *   @0x2b12c4 cbz r0, 0x2b12e0 <png_write_chunk+0x24>
 *   @0x2b12c8 bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b12cc mov r0, r4
 *   @0x2b12d0 mov r2, r5
 *   @0x2b12d4 qadd8mi pc, r0, r7
 *   @0x2b12d8 pop.w {r4, r5, r6, lr}
 *   @0x2b12dc b.w 0x2b1296 <png_write_chunk_end>
 *   @0x2b12e0 pop {r4, r5, r6, pc}
 *
 * ══ §376/828 ft_service_list_lookup  0x2e5352  size 38  10 条（0x2e5352..0x2e5378）
 * @func 0x2e5352 0x2e537a  size 40  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5352 push {r3, r4, r5, lr}
 *   @0x2e5356 mov r4, r0
 *   @0x2e535a cbz r1, 0x2e5374 <ft_service_list_lookup+0x22>
 *   @0x2e535e cbz r0, 0x2e5370 <ft_service_list_lookup+0x1e>
 *   @0x2e5362 blx 0xb6574 <strcmp@plt>
 *   @0x2e5366 cbnz r0, 0x2e536c <ft_service_list_lookup+0x1a>
 *   @0x2e536a pop {r3, r4, r5, pc}
 *   @0x2e536e b 0x2e535c <ft_service_list_lookup+0xa>
 *   @0x2e5372 pop {r3, r4, r5, pc}
 *   @0x2e5376 pop {r3, r4, r5, pc}
 *
 * ══ §377/828 ft_mem_qalloc  0x2e7100  size 38  10 条（0x2e7100..0x2e7126）
 * @func 0x2e7100 0x2e7136  size 54  14 条
 * 部分覆盖: 本节 11/21 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_qalloc+0x18
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7100 push {r4, lr}
 *   @0x2e7104 subs r2, r1, #0x0
 *   @0x2e7108 ble 0x2e7118 <ft_mem_qalloc+0x18>
 *   @0x2e710c blx r3
 *   @0x2e7110 ite eq
 *   @0x2e7114 movne r3, #0x0
 *   @0x2e7118 itete eq
 *   @0x2e711c movne r0, #0x0
 *   @0x2e7120 movne r3, #0x6
 *   @0x2e7124 pop {r4, pc}
 *
 * ══ §378/828 ft_mem_alloc  0x2e7126  size 38  10 条（0x2e7126..0x2e714c）
 * @func 0x2e7126 0x2e715c  size 54  14 条
 * 部分覆盖: 本节 11/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_qalloc / ft_mem_alloc+0x1c / 0xb65b0
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7126 push {r0, r1, r4, r5, r6, lr}
 *   @0x2e712a add r2, sp, #0x4
 *   @0x2e712e bl 0x2e7100 <ft_mem_qalloc>
 *   @0x2e7132 ldr r1, [sp, #0x4]
 *   @0x2e7136 cbnz r1, 0x2e7142 <ft_mem_alloc+0x1c>
 *   @0x2e713a ble 0x2e7142 <ft_mem_alloc+0x1c>
 *   @0x2e713e blx 0xb65b0 <memset@plt>
 *   @0x2e7142 ldr r3, [sp, #0x4]
 *   @0x2e7146 str r3, [r5]
 *   @0x2e714a pop {r4, r5, r6, pc}
 *
 * ══ §379/828 FT_Load_Char  0x2e79ca  size 38  10 条（0x2e79ca..0x2e79f0）
 * @func 0x2e79ca 0x2e79f2  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e79ca push {r4, r5, r6, lr}
 *   @0x2e79ce mov r6, r2
 *   @0x2e79d2 cbz r0, 0x2e79ec <FT_Load_Char+0x22>
 *   @0x2e79d6 cbz r5, 0x2e79de <FT_Load_Char+0x14>
 *   @0x2e79da strmi pc, [r3], -r2, asr #31
 *   @0x2e79de mov r0, r4
 *   @0x2e79e2 mov r1, r3
 *   @0x2e79e6 .word 0xf7ff4070
 *   @0x2e79ea .word 0x2023bdbc
 *   @0x2e79ee pop {r4, r5, r6, pc}
 *
 * ══ §380/828 FT_New_Memory_Face  0x2e96f0  size 38  10 条（0x2e96f0..0x2e9716）
 * @func 0x2e96f0 0x2e9718  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e96f0 push {r4, lr}
 *   @0x2e96f4 cbz r1, 0x2e9710 <FT_New_Memory_Face+0x20>
 *   @0x2e96f8 str r1, [sp, #0xc]
 *   @0x2e96fc add r1, sp, #0x8
 *   @0x2e9700 str r4, [sp]
 *   @0x2e9704 mov r2, r3
 *   @0x2e9708 str r4, [sp, #0x8]
 *   @0x2e970c mul r0, r5, r10
 *   @0x2e9710 movs r0, #0x6
 *   @0x2e9714 pop {r4, pc}
 *
 * ══ §381/828 CBackground::FreeTexture()  0xc1e3c  size 36  9 条（0xc1e3c..0xc1e60）
 * @func 0xc1e3c 0xc1e70  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::FreeTexture()+0x18 / GR_Texture_Free(int)
 * 字段偏移 top8: 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1e3c push {r4, lr}
 *   @0xc1e40 mov r4, r0
 *   @0xc1e44 ldr r0, [r0, #0xc]
 *   @0xc1e48 cmp r0, #0
 *   @0xc1e4c blt 0xc1e54 <_ZN11CBackground11FreeTextureEv+0x18>
 *   @0xc1e50 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0xc1e54 mvn r3, #0
 *   @0xc1e58 str r3, [r4, #0xc]
 *   @0xc1e5c pop {r4, pc}
 *
 * ══ §382/828 VM::Init()  0xd83a8  size 36  9 条（0xd83a8..0xd83cc）
 * @func 0xd83a8 0xd83cc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::ResetBreakpoints()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd83a8 push {r3, lr}
 *   @0xd83ac bl 0xd8374 <_ZN2VM16ResetBreakpointsEv>
 *   @0xd83b0 mov r2, #0
 *   @0xd83b4 ldr r3, [pc, #0xc]
 *   @0xd83b8 ldr r3, [pc, r3]
 *   @0xd83bc str r2, [r3]
 *   @0xd83c0 pop {r3, lr}
 *   @0xd83c4 b 0xd3edc <_Z26InitialiseHandledContainerv>
 *   @0xd83c8 eorseq r5, r1, r0, lsr r9
 *
 * ══ §383/828 CExtensionFile::SetFunction(int, CExtensionFunction*)  0xf4cb4  size 36  9 条（0xf4cb4..0xf4cd8）
 * @func 0xf4cb4 0xf4cd8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4cb4 subs r3, r1, #0
 *   @0xf4cb8 bxlt lr
 *   @0xf4cbc ldr r12, [r0, #0x1c]
 *   @0xf4cc0 cmp r3, r12
 *   @0xf4cc4 bxge lr
 *   @0xf4cc8 ldr r0, [r0, #0x18]
 *   @0xf4ccc mov r1, r2
 *   @0xf4cd0 ldr r0, [r0, r3, lsl #2]
 *   @0xf4cd4 b 0xf4a0c <_ZN18CExtensionFunction6AssignEPS_>
 *
 * ══ §384/828 CExtensionFile::SetConstant(int, CExtensionConstant*)  0xf4db0  size 36  9 条（0xf4db0..0xf4dd4）
 * @func 0xf4db0 0xf4dd4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4db0 subs r3, r1, #0
 *   @0xf4db4 bxlt lr
 *   @0xf4db8 ldr r12, [r0, #0x28]
 *   @0xf4dbc cmp r3, r12
 *   @0xf4dc0 bxge lr
 *   @0xf4dc4 ldr r0, [r0, #0x24]
 *   @0xf4dc8 mov r1, r2
 *   @0xf4dcc ldr r0, [r0, r3, lsl #2]
 *   @0xf4dd0 b 0xf482c <_ZN18CExtensionConstant6AssignEPS_>
 *
 * ══ §385/828 CExtensionPackage::SetIncludes(int, CExtensionFile*)  0xf53c0  size 36  9 条（0xf53c0..0xf53e4）
 * @func 0xf53c0 0xf53e4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf53c0 subs r3, r1, #0
 *   @0xf53c4 bxlt lr
 *   @0xf53c8 ldr r12, [r0, #0x18]
 *   @0xf53cc cmp r3, r12
 *   @0xf53d0 bxge lr
 *   @0xf53d4 ldr r0, [r0, #0x14]
 *   @0xf53d8 mov r1, r2
 *   @0xf53dc ldr r0, [r0, r3, lsl #2]
 *   @0xf53e0 b 0xf516c <_ZN14CExtensionFile6AssignEPS_>
 *
 * ══ §386/828 CFontGM::FreeTexture()  0xf707c  size 36  9 条（0xf707c..0xf70a0）
 * @func 0xf707c 0xf70a0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::FreeTexture()+0x18 / GR_Texture_Free(int)
 * 字段偏移 top8: 0x38×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf707c push {r4, lr}
 *   @0xf7080 mov r4, r0
 *   @0xf7084 ldr r0, [r0, #0x38]
 *   @0xf7088 cmp r0, #0
 *   @0xf708c blt 0xf7094 <_ZN7CFontGM11FreeTextureEv+0x18>
 *   @0xf7090 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0xf7094 mvn r3, #0
 *   @0xf7098 str r3, [r4, #0x38]
 *   @0xf709c pop {r4, pc}
 *
 * ══ §387/828 F_InstanceSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x109978  size 36  9 条（0x109978..0x10999c）
 * @func 0x109978 0x1099ac  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109978 push {r4, lr}
 *   @0x10997c mov r4, r1
 *   @0x109980 ldr r0, [sp, #0x8]
 *   @0x109984 mov r1, #0
 *   @0x109988 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10998c mov r1, r0
 *   @0x109990 mov r0, r4
 *   @0x109994 pop {r4, lr}
 *   @0x109998 b 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei>
 *
 * ══ §388/828 F_Sleep(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c64  size 36  9 条（0x109c64..0x109c88）
 * @func 0x109c64 0x109c88  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c64 push {r3, lr}
 *   @0x109c68 mov r1, #0
 *   @0x109c6c ldr r0, [sp, #0x8]
 *   @0x109c70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109c74 mov r3, #1000
 *   @0x109c78 mul r0, r3, r0
 *   @0x109c7c pop {r3, lr}
 *   @0x109c80 asr r1, r0, #31
 *   @0x109c84 b 0x2151f0 <Timing_Sleep>
 *
 * ══ §389/828 F_DisplaySetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*)  0x119d00  size 36  9 条（0x119d00..0x119d24）
 * @func 0x119d00 0x119d24  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119d00 push {r3, lr}
 *   @0x119d04 mov r1, #0
 *   @0x119d08 ldr r0, [sp, #0x8]
 *   @0x119d0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119d10 ldr r3, [pc, #0x8]
 *   @0x119d14 ldr r3, [pc, r3]
 *   @0x119d18 str r0, [r3]
 *   @0x119d1c pop {r3, pc}
 *   @0x119d20 eoreq r4, sp, r0, lsr #17
 *
 * ══ §390/828 F_DrawEnableDrawEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a0d4  size 36  9 条（0x11a0d4..0x11a0f8）
 * @func 0x11a0d4 0x11a108  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a0d4 push {r3, lr}
 *   @0x11a0d8 mov r1, #0
 *   @0x11a0dc ldr r0, [sp, #0x8]
 *   @0x11a0e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a0e4 ldr r3, [pc, #0x8]
 *   @0x11a0e8 ldr r3, [pc, r3]
 *   @0x11a0ec strb r0, [r3]
 *   @0x11a0f0 pop {r3, pc}
 *   @0x11a0f4 .word 0x002d44dc
 *
 * ══ §391/828 F_DrawEnableSWFAA(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a0f8  size 36  9 条（0x11a0f8..0x11a11c）
 * @func 0x11a0f8 0x11a11c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a0f8 push {r3, lr}
 *   @0x11a0fc mov r1, #0
 *   @0x11a100 ldr r0, [sp, #0x8]
 *   @0x11a104 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a108 ldr r3, [pc, #0x8]
 *   @0x11a10c ldr r3, [pc, r3]
 *   @0x11a110 strb r0, [r3]
 *   @0x11a114 pop {r3, pc}
 *   @0x11a118 .word 0x002d44bc
 *
 * ══ §392/828 F_DrawEnableCornerID(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a164  size 36  9 条（0x11a164..0x11a188）
 * @func 0x11a164 0x11a188  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a164 push {r3, lr}
 *   @0x11a168 mov r1, #0
 *   @0x11a16c ldr r0, [sp, #0x8]
 *   @0x11a170 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a174 ldr r3, [pc, #0x8]
 *   @0x11a178 ldr r3, [pc, r3]
 *   @0x11a17c strb r0, [r3]
 *   @0x11a180 pop {r3, pc}
 *   @0x11a184 .word 0x002d3cd4
 *
 * ══ §393/828 F_SplashSetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x125fac  size 36  9 条（0x125fac..0x125fd0）
 * @func 0x125fac 0x125fe0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125fac push {r3, lr}
 *   @0x125fb0 mov r1, #0
 *   @0x125fb4 ldr r0, [sp, #0x8]
 *   @0x125fb8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x125fbc ldr r3, [pc, #0x8]
 *   @0x125fc0 ldr r3, [pc, r3]
 *   @0x125fc4 strb r0, [r3]
 *   @0x125fc8 pop {r3, pc}
 *   @0x125fcc eoreq r8, r12, r4, ror r10
 *
 * ══ §394/828 F_SplashSetAdapt(RValue&, CInstance*, CInstance*, int, RValue*)  0x125fd0  size 36  9 条（0x125fd0..0x125ff4）
 * @func 0x125fd0 0x126004  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125fd0 push {r3, lr}
 *   @0x125fd4 mov r1, #0
 *   @0x125fd8 ldr r0, [sp, #0x8]
 *   @0x125fdc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x125fe0 ldr r3, [pc, #0x8]
 *   @0x125fe4 ldr r3, [pc, r3]
 *   @0x125fe8 strb r0, [r3]
 *   @0x125fec pop {r3, pc}
 *   @0x125ff0 eoreq r8, r12, r4, asr r10
 *
 * ══ §395/828 F_SplashSetBorder(RValue&, CInstance*, CInstance*, int, RValue*)  0x125ff4  size 36  9 条（0x125ff4..0x126018）
 * @func 0x125ff4 0x126028  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125ff4 push {r3, lr}
 *   @0x125ff8 mov r1, #0
 *   @0x125ffc ldr r0, [sp, #0x8]
 *   @0x126000 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126004 ldr r3, [pc, #0x8]
 *   @0x126008 ldr r3, [pc, r3]
 *   @0x12600c strb r0, [r3]
 *   @0x126010 pop {r3, pc}
 *   @0x126014 eoreq r8, r12, r4, lsr r10
 *
 * ══ §396/828 F_SplashSetTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x126018  size 36  9 条（0x126018..0x12603c）
 * @func 0x126018 0x12604c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126018 push {r3, lr}
 *   @0x12601c mov r1, #0
 *   @0x126020 ldr r0, [sp, #0x8]
 *   @0x126024 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126028 ldr r3, [pc, #0x8]
 *   @0x12602c ldr r3, [pc, r3]
 *   @0x126030 strb r0, [r3]
 *   @0x126034 pop {r3, pc}
 *   @0x126038 eoreq r8, r12, r4, lsl r10
 *
 * ══ §397/828 F_SplashSetMain(RValue&, CInstance*, CInstance*, int, RValue*)  0x12603c  size 36  9 条（0x12603c..0x126060）
 * @func 0x12603c 0x126070  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12603c push {r3, lr}
 *   @0x126040 mov r1, #0
 *   @0x126044 ldr r0, [sp, #0x8]
 *   @0x126048 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12604c ldr r3, [pc, #0x8]
 *   @0x126050 ldr r3, [pc, r3]
 *   @0x126054 strb r0, [r3]
 *   @0x126058 pop {r3, pc}
 *   @0x12605c .word 0x002c89f4
 *
 * ══ §398/828 F_SplashSetCursor(RValue&, CInstance*, CInstance*, int, RValue*)  0x126060  size 36  9 条（0x126060..0x126084）
 * @func 0x126060 0x126094  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126060 push {r3, lr}
 *   @0x126064 mov r1, #0
 *   @0x126068 ldr r0, [sp, #0x8]
 *   @0x12606c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126070 ldr r3, [pc, #0x8]
 *   @0x126074 ldr r3, [pc, r3]
 *   @0x126078 strb r0, [r3]
 *   @0x12607c pop {r3, pc}
 *   @0x126080 .word 0x002c89d4
 *
 * ══ §399/828 F_SplashSetInterrupt(RValue&, CInstance*, CInstance*, int, RValue*)  0x126084  size 36  9 条（0x126084..0x1260a8）
 * @func 0x126084 0x1260b8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126084 push {r3, lr}
 *   @0x126088 mov r1, #0
 *   @0x12608c ldr r0, [sp, #0x8]
 *   @0x126090 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126094 ldr r3, [pc, #0x8]
 *   @0x126098 ldr r3, [pc, r3]
 *   @0x12609c strb r0, [r3]
 *   @0x1260a0 pop {r3, pc}
 *   @0x1260a4 .word 0x002c89b4
 *
 * ══ §400/828 F_SplashSetStopKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x1260a8  size 36  9 条（0x1260a8..0x1260cc）
 * @func 0x1260a8 0x1260dc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1260a8 push {r3, lr}
 *   @0x1260ac mov r1, #0
 *   @0x1260b0 ldr r0, [sp, #0x8]
 *   @0x1260b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1260b8 ldr r3, [pc, #0x8]
 *   @0x1260bc ldr r3, [pc, r3]
 *   @0x1260c0 strb r0, [r3]
 *   @0x1260c4 pop {r3, pc}
 *   @0x1260c8 mlaeq r12, r4, r9, r8
 *
 * ══ §401/828 F_SplashSetStopMouse(RValue&, CInstance*, CInstance*, int, RValue*)  0x1260cc  size 36  9 条（0x1260cc..0x1260f0）
 * @func 0x1260cc 0x126100  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1260cc push {r3, lr}
 *   @0x1260d0 mov r1, #0
 *   @0x1260d4 ldr r0, [sp, #0x8]
 *   @0x1260d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1260dc ldr r3, [pc, #0x8]
 *   @0x1260e0 ldr r3, [pc, r3]
 *   @0x1260e4 strb r0, [r3]
 *   @0x1260e8 pop {r3, pc}
 *   @0x1260ec eoreq r8, r12, r4, ror r9
 *
 * ══ §402/828 F_HighscoreSetBorder(RValue&, CInstance*, CInstance*, int, RValue*)  0x1260f0  size 36  9 条（0x1260f0..0x126114）
 * @func 0x1260f0 0x126124  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1260f0 push {r3, lr}
 *   @0x1260f4 mov r1, #0
 *   @0x1260f8 ldr r0, [sp, #0x8]
 *   @0x1260fc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126100 ldr r3, [pc, #0x8]
 *   @0x126104 ldr r3, [pc, r3]
 *   @0x126108 strb r0, [r3]
 *   @0x12610c pop {r3, pc}
 *   @0x126110 eoreq r8, r12, r4, asr r9
 *
 * ══ §403/828 F_IoEnableDbClickAsMbRight(RValue&, CInstance*, CInstance*, int, RValue*)  0x126114  size 36  9 条（0x126114..0x126138）
 * @func 0x126114 0x126138  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126114 push {r3, lr}
 *   @0x126118 mov r1, #0
 *   @0x12611c ldr r0, [sp, #0x8]
 *   @0x126120 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x126124 ldr r3, [pc, #0x8]
 *   @0x126128 ldr r3, [pc, r3]
 *   @0x12612c strb r0, [r3]
 *   @0x126130 pop {r3, pc}
 *   @0x126134 eoreq r8, r12, r4, lsr r9
 *
 * ══ §404/828 F_SplashSetColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x12617c  size 36  9 条（0x12617c..0x1261a0）
 * @func 0x12617c 0x1261a0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12617c push {r3, lr}
 *   @0x126180 mov r1, #0
 *   @0x126184 ldr r0, [sp, #0x8]
 *   @0x126188 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12618c ldr r3, [pc, #0x8]
 *   @0x126190 ldr r3, [pc, r3]
 *   @0x126194 str r0, [r3]
 *   @0x126198 pop {r3, pc}
 *   @0x12619c .word 0x002c88d8
 *
 * ══ §405/828 F_HighscoreSetBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x126200  size 36  9 条（0x126200..0x126224）
 * @func 0x126200 0x126234  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126200 push {r3, lr}
 *   @0x126204 mov r1, #0
 *   @0x126208 ldr r0, [sp, #0x8]
 *   @0x12620c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126210 ldr r3, [pc, #0x8]
 *   @0x126214 ldr r3, [pc, r3]
 *   @0x126218 str r0, [r3]
 *   @0x12621c pop {r3, pc}
 *   @0x126220 eoreq r8, r12, r4, ror #16
 *
 * ══ §406/828 F_SplashSetScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x126224  size 36  9 条（0x126224..0x126248）
 * @func 0x126224 0x126248  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126224 push {r3, lr}
 *   @0x126228 mov r1, #0
 *   @0x12622c ldr r0, [sp, #0x8]
 *   @0x126230 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x126234 ldr r3, [pc, #0x8]
 *   @0x126238 ldr r3, [pc, r3]
 *   @0x12623c strd r0, r1, [r3]
 *   @0x126240 pop {r3, pc}
 *   @0x126244 eoreq r8, r12, r4, asr #16
 *
 * ══ §407/828 F_FontSetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aab0  size 36  9 条（0x12aab0..0x12aad4）
 * @func 0x12aab0 0x12aad4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aab0 push {r3, lr}
 *   @0x12aab4 mov r1, #0
 *   @0x12aab8 ldr r0, [sp, #0x8]
 *   @0x12aabc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12aac0 ldr r3, [pc, #0x8]
 *   @0x12aac4 ldr r3, [pc, r3]
 *   @0x12aac8 str r0, [r3]
 *   @0x12aacc pop {r3, pc}
 *   @0x12aad0 mlaeq r12, r0, r3, r3
 *
 * ══ §408/828 F_FontAddEnableAA(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bd64  size 36  9 条（0x12bd64..0x12bd88）
 * @func 0x12bd64 0x12bd88  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bd64 push {r3, lr}
 *   @0x12bd68 mov r1, #0
 *   @0x12bd6c ldr r0, [sp, #0x8]
 *   @0x12bd70 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12bd74 ldr r3, [pc, #0x8]
 *   @0x12bd78 ldr r3, [pc, r3]
 *   @0x12bd7c strb r0, [r3]
 *   @0x12bd80 pop {r3, pc}
 *   @0x12bd84 eoreq r2, r12, r0, ror #1
 *
 * ══ §409/828 F_PathClearPoints(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dc40  size 36  9 条（0x12dc40..0x12dc64）
 * @func 0x12dc40 0x12dc74  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dc40 push {r3, lr}
 *   @0x12dc44 mov r1, #0
 *   @0x12dc48 ldr r0, [sp, #0x8]
 *   @0x12dc4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dc50 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dc54 cmp r0, #0
 *   @0x12dc58 popeq {r3, pc}
 *   @0x12dc5c pop {r3, lr}
 *   @0x12dc60 b 0x1a6f98 <_ZN5CPath5ClearEv>
 *
 * ══ §410/828 F_PathReverse(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dc64  size 36  9 条（0x12dc64..0x12dc88）
 * @func 0x12dc64 0x12dc98  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dc64 push {r3, lr}
 *   @0x12dc68 mov r1, #0
 *   @0x12dc6c ldr r0, [sp, #0x8]
 *   @0x12dc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dc74 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dc78 cmp r0, #0
 *   @0x12dc7c popeq {r3, pc}
 *   @0x12dc80 pop {r3, lr}
 *   @0x12dc84 b 0x1a76b4 <_ZN5CPath7ReverseEv>
 *
 * ══ §411/828 F_PathMirror(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dc88  size 36  9 条（0x12dc88..0x12dcac）
 * @func 0x12dc88 0x12dcbc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dc88 push {r3, lr}
 *   @0x12dc8c mov r1, #0
 *   @0x12dc90 ldr r0, [sp, #0x8]
 *   @0x12dc94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dc98 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dc9c cmp r0, #0
 *   @0x12dca0 popeq {r3, pc}
 *   @0x12dca4 pop {r3, lr}
 *   @0x12dca8 b 0x1a777c <_ZN5CPath6MirrorEv>
 *
 * ══ §412/828 F_PathFlip(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dcac  size 36  9 条（0x12dcac..0x12dcd0）
 * @func 0x12dcac 0x12dcd0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dcac push {r3, lr}
 *   @0x12dcb0 mov r1, #0
 *   @0x12dcb4 ldr r0, [sp, #0x8]
 *   @0x12dcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dcbc bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dcc0 cmp r0, #0
 *   @0x12dcc4 popeq {r3, pc}
 *   @0x12dcc8 pop {r3, lr}
 *   @0x12dccc b 0x1a77fc <_ZN5CPath4FlipEv>
 *
 * ══ §413/828 F_TimeLineClearAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x12df8c  size 36  9 条（0x12df8c..0x12dfb0）
 * @func 0x12df8c 0x12dfb0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12df8c push {r3, lr}
 *   @0x12df90 mov r1, #0
 *   @0x12df94 ldr r0, [sp, #0x8]
 *   @0x12df98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12df9c bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x12dfa0 cmp r0, #0
 *   @0x12dfa4 popeq {r3, pc}
 *   @0x12dfa8 pop {r3, lr}
 *   @0x12dfac b 0x1f1768 <_ZN9CTimeLine5ClearEv>
 *
 * ══ §414/828 F_RoomInstanceClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e8d4  size 36  9 条（0x12e8d4..0x12e8f8）
 * @func 0x12e8d4 0x12e8f8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e8d4 push {r3, lr}
 *   @0x12e8d8 mov r1, #0
 *   @0x12e8dc ldr r0, [sp, #0x8]
 *   @0x12e8e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e8e4 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e8e8 cmp r0, #0
 *   @0x12e8ec popeq {r3, pc}
 *   @0x12e8f0 pop {r3, lr}
 *   @0x12e8f4 b 0x1ab140 <_ZN5CRoom21ClearStorageInstancesEv>
 *
 * ══ §415/828 F_RoomTileClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ec1c  size 36  9 条（0x12ec1c..0x12ec40）
 * @func 0x12ec1c 0x12ec50  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ec1c push {r3, lr}
 *   @0x12ec20 mov r1, #0
 *   @0x12ec24 ldr r0, [sp, #0x8]
 *   @0x12ec28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ec2c bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12ec30 cmp r0, #0
 *   @0x12ec34 popeq {r3, pc}
 *   @0x12ec38 pop {r3, lr}
 *   @0x12ec3c b 0x1ab104 <_ZN5CRoom17ClearStorageTilesEv>
 *
 * ══ §416/828 GET_YoYo_GetBrowserWidth(CInstance*, int, RValue*)  0x157958  size 36  9 条（0x157958..0x15797c）
 * @func 0x157958 0x15797c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBrowserWidthM()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157958 push {r4, lr}
 *   @0x15795c mov r3, #0
 *   @0x157960 str r3, [r2, #0xc]
 *   @0x157964 mov r4, r2
 *   @0x157968 bl 0x15e60c <_Z16GetBrowserWidthMv>
 *   @0x15796c str r0, [r4]
 *   @0x157970 mov r0, #1
 *   @0x157974 str r1, [r4, #0x4]
 *   @0x157978 pop {r4, pc}
 *
 * ══ §417/828 GET_YoYo_GetBrowserHeight(CInstance*, int, RValue*)  0x1579cc  size 36  9 条（0x1579cc..0x1579f0）
 * @func 0x1579cc 0x1579f0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBrowserHeightM()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1579cc push {r4, lr}
 *   @0x1579d0 mov r3, #0
 *   @0x1579d4 str r3, [r2, #0xc]
 *   @0x1579d8 mov r4, r2
 *   @0x1579dc bl 0x15e62c <_Z17GetBrowserHeightMv>
 *   @0x1579e0 str r0, [r4]
 *   @0x1579e4 mov r0, #1
 *   @0x1579e8 str r1, [r4, #0x4]
 *   @0x1579ec pop {r4, pc}
 *
 * ══ §418/828 GET_YoYo_GetOSVersion(CInstance*, int, RValue*)  0x1589e4  size 36  9 条（0x1589e4..0x158a08）
 * @func 0x1589e4 0x158a08  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetVersionM()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1589e4 push {r4, lr}
 *   @0x1589e8 mov r3, #0
 *   @0x1589ec str r3, [r2, #0xc]
 *   @0x1589f0 mov r4, r2
 *   @0x1589f4 bl 0x15e5f8 <_Z11GetVersionMv>
 *   @0x1589f8 str r0, [r4]
 *   @0x1589fc mov r0, #1
 *   @0x158a00 str r1, [r4, #0x4]
 *   @0x158a04 pop {r4, pc}
 *
 * ══ §419/828 GET_YoYo_GetPlatform(CInstance*, int, RValue*)  0x159d20  size 36  9 条（0x159d20..0x159d44）
 * @func 0x159d20 0x159d44  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YoYo_GetPlatform_DoWork()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159d20 push {r4, lr}
 *   @0x159d24 mov r3, #0
 *   @0x159d28 str r3, [r2, #0xc]
 *   @0x159d2c mov r4, r2
 *   @0x159d30 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x159d34 str r0, [r4]
 *   @0x159d38 mov r0, #1
 *   @0x159d3c str r1, [r4, #0x4]
 *   @0x159d40 pop {r4, pc}
 *
 * ══ §420/828 GetCPUDetailsM()  0x15e66c  size 36  9 条（0x15e66c..0x15e690）
 * @func 0x15e66c 0x15e690  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: android_getCpuFamily / android_getCpuFeatures
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e66c push {r4, lr}
 *   @0x15e670 bl 0x2a2e90 <android_getCpuFamily>
 *   @0x15e674 mov r4, r0
 *   @0x15e678 bl 0x2a2ebc <android_getCpuFeatures>
 *   @0x15e67c uxtb r4, r4
 *   @0x15e680 lsl r0, r0, #8
 *   @0x15e684 uxth r0, r0
 *   @0x15e688 orr r0, r0, r4
 *   @0x15e68c pop {r4, pc}
 *
 * ══ §421/828 RenderStateManager::WriteStatesToBuffer(Buffer_Standard*)  0x1682cc  size 36  9 条（0x1682cc..0x1682f0）
 * @func 0x1682cc 0x1682f0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1682cc add r12, r0, #484
 *   @0x1682d0 mov r2, #4
 *   @0x1682d4 push {r3, lr}
 *   @0x1682d8 mov r0, r1
 *   @0x1682dc mov r3, #35
 *   @0x1682e0 mov r1, r12
 *   @0x1682e4 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x1682e8 mov r0, #35
 *   @0x1682ec pop {r3, pc}
 *
 * ══ §422/828 GR_D3D_Get_Alpha_Test_Enable()  0x168694  size 36  9 条（0x168694..0x1686b8）
 * @func 0x168694 0x1686b8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168694 ldr r0, [pc, #0x18]
 *   @0x168698 mov r1, #5
 *   @0x16869c push {r3, lr}
 *   @0x1686a0 ldr r0, [pc, r0]
 *   @0x1686a4 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1686a8 adds r0, r0, #0
 *   @0x1686ac movne r0, #1
 *   @0x1686b0 pop {r3, pc}
 *   @0x1686b4 eoreq r5, r8, r8, asr r6
 *
 * ══ §423/828 GR_D3D_Get_Texture_Repeat_Ext(int)  0x168a08  size 36  9 条（0x168a08..0x168a2c）
 * @func 0x168a08 0x168a3c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168a08 cmp r0, #7
 *   @0x168a0c bhi 0x168a20 <_Z29GR_D3D_Get_Texture_Repeat_Exti+0x18>
 *   @0x168a10 ldr r3, [pc, #0x10]
 *   @0x168a14 ldr r3, [pc, r3]
 *   @0x168a18 ldrb r0, [r3, r0]
 *   @0x168a1c bx lr
 *   @0x168a20 mov r0, #0
 *   @0x168a24 bx lr
 *   @0x168a28 .word 0x002876f8
 *
 * ══ §424/828 GR_D3D_Get_Texture_Interpolation_Ext(int)  0x168a2c  size 36  9 条（0x168a2c..0x168a50）
 * @func 0x168a2c 0x168a50  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168a2c cmp r0, #7
 *   @0x168a30 bhi 0x168a44 <_Z36GR_D3D_Get_Texture_Interpolation_Exti+0x18>
 *   @0x168a34 ldr r3, [pc, #0x10]
 *   @0x168a38 ldr r3, [pc, r3]
 *   @0x168a3c ldrb r0, [r3, r0]
 *   @0x168a40 bx lr
 *   @0x168a44 mov r0, #1
 *   @0x168a48 bx lr
 *   @0x168a4c .word 0x002876d0
 *
 * ══ §425/828 GraphicsPerf::SetDebugFont()  0x17b3c0  size 36  9 条（0x17b3c0..0x17b3e4）
 * @func 0x17b3c0 0x17b3e4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b3c0 ldr r2, [pc, #0x14]
 *   @0x17b3c4 ldr r3, [pc, #0x14]
 *   @0x17b3c8 ldr r2, [pc, r2]
 *   @0x17b3cc ldr r3, [pc, r3]
 *   @0x17b3d0 ldr r0, [r2]
 *   @0x17b3d4 ldr r1, [r3]
 *   @0x17b3d8 b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x17b3dc eoreq r4, r7, r12, asr sp
 *   @0x17b3e0 eoreq r4, r7, r12, asr #29
 *
 * ══ §426/828 IO_Key_Down(int)  0x18bee8  size 36  9 条（0x18bee8..0x18bf0c）
 * @func 0x18bee8 0x18bf1c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bee8 cmp r0, #255
 *   @0x18beec bhi 0x18bf00 <_Z11IO_Key_Downi+0x18>
 *   @0x18bef0 ldr r3, [pc, #0x10]
 *   @0x18bef4 ldr r3, [pc, r3]
 *   @0x18bef8 ldrb r0, [r3, r0]
 *   @0x18befc bx lr
 *   @0x18bf00 mov r0, #0
 *   @0x18bf04 bx lr
 *   @0x18bf08 eoreq r4, r6, r12, ror #13
 *
 * ══ §427/828 IO_Key_Pressed(int)  0x18bf0c  size 36  9 条（0x18bf0c..0x18bf30）
 * @func 0x18bf0c 0x18bf40  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bf0c cmp r0, #255
 *   @0x18bf10 bhi 0x18bf24 <_Z14IO_Key_Pressedi+0x18>
 *   @0x18bf14 ldr r3, [pc, #0x10]
 *   @0x18bf18 ldr r3, [pc, r3]
 *   @0x18bf1c ldrb r0, [r3, r0]
 *   @0x18bf20 bx lr
 *   @0x18bf24 mov r0, #0
 *   @0x18bf28 bx lr
 *   @0x18bf2c .word 0x002646d0
 *
 * ══ §428/828 IO_Key_Released(int)  0x18bf30  size 36  9 条（0x18bf30..0x18bf54）
 * @func 0x18bf30 0x18bf54  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bf30 cmp r0, #255
 *   @0x18bf34 bhi 0x18bf48 <_Z15IO_Key_Releasedi+0x18>
 *   @0x18bf38 ldr r3, [pc, #0x10]
 *   @0x18bf3c ldr r3, [pc, r3]
 *   @0x18bf40 ldrb r0, [r3, r0]
 *   @0x18bf44 bx lr
 *   @0x18bf48 mov r0, #0
 *   @0x18bf4c bx lr
 *   @0x18bf50 eoreq r4, r6, r8, lsr #13
 *
 * ══ §429/828 IO_Button_Last_Get(int)  0x18c024  size 36  9 条（0x18c024..0x18c048）
 * @func 0x18c024 0x18c058  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c024 cmp r0, #9
 *   @0x18c028 bhi 0x18c03c <_Z18IO_Button_Last_Geti+0x18>
 *   @0x18c02c ldr r3, [pc, #0x10]
 *   @0x18c030 ldr r3, [pc, r3]
 *   @0x18c034 ldr r0, [r3, r0, lsl #2]
 *   @0x18c038 bx lr
 *   @0x18c03c mov r0, #0
 *   @0x18c040 bx lr
 *   @0x18c044 .word 0x002645bc
 *
 * ══ §430/828 IO_Button_Current_Get(int)  0x18c048  size 36  9 条（0x18c048..0x18c06c）
 * @func 0x18c048 0x18c07c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c048 cmp r0, #9
 *   @0x18c04c bhi 0x18c060 <_Z21IO_Button_Current_Geti+0x18>
 *   @0x18c050 ldr r3, [pc, #0x10]
 *   @0x18c054 ldr r3, [pc, r3]
 *   @0x18c058 ldr r0, [r3, r0, lsl #2]
 *   @0x18c05c bx lr
 *   @0x18c060 mov r0, #0
 *   @0x18c064 bx lr
 *   @0x18c068 mlaeq r6, r12, r5, r4
 *
 * ══ §431/828 IO_Button_Last_Set(int, int)  0x18c06c  size 36  9 条（0x18c06c..0x18c090）
 * @func 0x18c06c 0x18c0a0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c06c sub r3, r0, #1
 *   @0x18c070 cmp r3, #2
 *   @0x18c074 bxhi lr
 *   @0x18c078 cmp r1, #9
 *   @0x18c07c ldrls r3, [pc, #0x8]
 *   @0x18c080 ldrls r3, [pc, r3]
 *   @0x18c084 strls r0, [r3, r1, lsl #2]
 *   @0x18c088 bx lr
 *   @0x18c08c eoreq r4, r6, r12, ror #10
 *
 * ══ §432/828 IO_Button_Current_Set(int, int)  0x18c090  size 36  9 条（0x18c090..0x18c0b4）
 * @func 0x18c090 0x18c0b4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c090 sub r3, r0, #1
 *   @0x18c094 cmp r3, #2
 *   @0x18c098 bxhi lr
 *   @0x18c09c cmp r1, #9
 *   @0x18c0a0 ldrls r3, [pc, #0x8]
 *   @0x18c0a4 ldrls r3, [pc, r3]
 *   @0x18c0a8 strls r0, [r3, r1, lsl #2]
 *   @0x18c0ac bx lr
 *   @0x18c0b0 eoreq r4, r6, r12, asr #10
 *
 * ══ §433/828 LoadSave::fread(void const*, unsigned int, unsigned int, _YYFILE*)  0x18e070  size 36  9 条（0x18e070..0x18e094）
 * @func 0x18e070 0x18e094  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e070 str r4, [sp, #-0x4]!
 *   @0x18e074 mov r12, r2
 *   @0x18e078 mov r4, r1
 *   @0x18e07c mov r1, r0
 *   @0x18e080 mov r2, r4
 *   @0x18e084 ldr r0, [r3]
 *   @0x18e088 ldr r4, [sp], #4
 *   @0x18e08c mov r3, r12
 *   @0x18e090 b 0xcdc9c <_ZN7IBuffer4ReadEPKvjj>
 *
 * ══ §434/828 LoadSave::fwrite(void const*, unsigned int, unsigned int, _YYFILE*)  0x18e2b0  size 36  9 条（0x18e2b0..0x18e2d4）
 * @func 0x18e2b0 0x18e2d4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e2b0 str r4, [sp, #-0x4]!
 *   @0x18e2b4 mov r12, r2
 *   @0x18e2b8 mov r4, r1
 *   @0x18e2bc mov r1, r0
 *   @0x18e2c0 mov r2, r4
 *   @0x18e2c4 ldr r0, [r3]
 *   @0x18e2c8 ldr r4, [sp], #4
 *   @0x18e2cc mov r3, r12
 *   @0x18e2d0 b 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *
 * ══ §435/828 LoadSave::_ExpandCompressedFile(char const*, char const*, char*, int, int)  0x18fc44  size 36  9 条（0x18fc44..0x18fc68）
 * @func 0x18fc44 0x18fc68  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fc44 str r4, [sp, #-0x4]!
 *   @0x18fc48 mov r4, r0
 *   @0x18fc4c ldr r12, [sp, #0x4]
 *   @0x18fc50 mov r0, r1
 *   @0x18fc54 str r2, [sp, #0x4]
 *   @0x18fc58 mov r1, r4
 *   @0x18fc5c ldr r4, [sp], #4
 *   @0x18fc60 mov r2, r12
 *   @0x18fc64 b 0x1ca040 <_Z13Command_UnzipPKcS0_iiPc>
 *
 * ══ §436/828 CObjectGM::SetNameRef(char*)  0x19d348  size 36  9 条（0x19d348..0x19d36c）
 * @func 0x19d348 0x19d36c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d348 push {r3, r4, r5, lr}
 *   @0x19d34c mov r4, r0
 *   @0x19d350 ldr r0, [r0, #0x14]
 *   @0x19d354 mov r5, r1
 *   @0x19d358 cmp r0, #0
 *   @0x19d35c beq 0x19d364 <_ZN9CObjectGM10SetNameRefEPc+0x1c>
 *   @0x19d360 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d364 str r5, [r4, #0x14]
 *   @0x19d368 pop {r3, r4, r5, pc}
 *
 * ══ §437/828 TBitmap::TBitmap(Gdiplus::Bitmap*)  0x1a8c18  size 36  9 条（0x1a8c18..0x1a8c3c）
 * @func 0x1a8c18 0x1a8c3c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8c18 ldr r2, [pc, #0x18]
 *   @0x1a8c1c mvn r1, #0
 *   @0x1a8c20 str r1, [r0, #0x24]
 *   @0x1a8c24 ldr r2, [pc, r2]
 *   @0x1a8c28 str r1, [r0, #0x28]
 *   @0x1a8c2c add r2, r2, #8
 *   @0x1a8c30 str r2, [r0]
 *   @0x1a8c34 bx lr
 *   @0x1a8c38 .word 0x00247bdc
 *
 * ══ §438/828 BitmapLoader::BitmapLoader(char const*)  0x1a9148  size 36  9 条（0x1a9148..0x1a916c）
 * @func 0x1a9148 0x1a916c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a9148 ldr r2, [pc, #0x18]
 *   @0x1a914c mov r1, #0
 *   @0x1a9150 str r1, [r0, #0x8]
 *   @0x1a9154 ldr r2, [pc, r2]
 *   @0x1a9158 str r1, [r0, #0xc]
 *   @0x1a915c add r2, r2, #8
 *   @0x1a9160 str r2, [r0]
 *   @0x1a9164 bx lr
 *   @0x1a9168 .word 0x002476b0
 *
 * ══ §439/828 BitmapLoader::BitmapLoader(void*, int)  0x1a9218  size 36  9 条（0x1a9218..0x1a923c）
 * @func 0x1a9218 0x1a924c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a9218 ldr r2, [pc, #0x18]
 *   @0x1a921c mov r1, #0
 *   @0x1a9220 str r1, [r0, #0x8]
 *   @0x1a9224 ldr r2, [pc, r2]
 *   @0x1a9228 str r1, [r0, #0xc]
 *   @0x1a922c add r2, r2, #8
 *   @0x1a9230 str r2, [r0]
 *   @0x1a9234 bx lr
 *   @0x1a9238 eoreq r7, r4, r0, ror #11
 *
 * ══ §440/828 IBitmapLoader::Create(char const*)  0x1a923c  size 36  9 条（0x1a923c..0x1a9260）
 * @func 0x1a923c 0x1a9270  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / BitmapLoader::BitmapLoader(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a923c push {r3, r4, r5, lr}
 *   @0x1a9240 mov r5, r0
 *   @0x1a9244 mov r0, #20
 *   @0x1a9248 bl 0x27c524 <_Znwj>
 *   @0x1a924c mov r1, r5
 *   @0x1a9250 mov r4, r0
 *   @0x1a9254 bl 0x1a9148 <_ZN12BitmapLoaderC2EPKc>
 *   @0x1a9258 mov r0, r4
 *   @0x1a925c pop {r3, r4, r5, pc}
 *
 * ══ §441/828 F_LayerSetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6334  size 36  9 条（0x1b6334..0x1b6358）
 * @func 0x1b6334 0x1b6358  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6334 push {r3, lr}
 *   @0x1b6338 mov r1, #0
 *   @0x1b633c ldr r0, [sp, #0x8]
 *   @0x1b6340 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6344 ldr r3, [pc, #0x8]
 *   @0x1b6348 ldr r3, [pc, r3]
 *   @0x1b634c str r0, [r3]
 *   @0x1b6350 pop {r3, pc}
 *   @0x1b6354 eoreq r10, r3, r12, lsl #10
 *
 * ══ §442/828 F_GestureDragDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5638  size 36  9 条（0x1d5638..0x1d565c）
 * @func 0x1d5638 0x1d566c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5638 push {r3, lr}
 *   @0x1d563c mov r1, #0
 *   @0x1d5640 ldr r0, [sp, #0x8]
 *   @0x1d5644 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d5648 ldr r3, [pc, #0x8]
 *   @0x1d564c ldr r3, [pc, r3]
 *   @0x1d5650 str r0, [r3]
 *   @0x1d5654 pop {r3, pc}
 *   @0x1d5658 eoreq r11, r1, r12, ror r5
 *
 * ══ §443/828 F_GestureFlickSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d565c  size 36  9 条（0x1d565c..0x1d5680）
 * @func 0x1d565c 0x1d5690  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d565c push {r3, lr}
 *   @0x1d5660 mov r1, #0
 *   @0x1d5664 ldr r0, [sp, #0x8]
 *   @0x1d5668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d566c ldr r3, [pc, #0x8]
 *   @0x1d5670 ldr r3, [pc, r3]
 *   @0x1d5674 str r0, [r3]
 *   @0x1d5678 pop {r3, pc}
 *   @0x1d567c eoreq r11, r1, r12, asr r5
 *
 * ══ §444/828 F_GestureDoubleTapDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5680  size 36  9 条（0x1d5680..0x1d56a4）
 * @func 0x1d5680 0x1d56b4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5680 push {r3, lr}
 *   @0x1d5684 mov r1, #0
 *   @0x1d5688 ldr r0, [sp, #0x8]
 *   @0x1d568c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d5690 ldr r3, [pc, #0x8]
 *   @0x1d5694 ldr r3, [pc, r3]
 *   @0x1d5698 str r0, [r3]
 *   @0x1d569c pop {r3, pc}
 *   @0x1d56a0 eoreq r11, r1, r0, asr #10
 *
 * ══ §445/828 F_GesturePinchDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d56a4  size 36  9 条（0x1d56a4..0x1d56c8）
 * @func 0x1d56a4 0x1d56d8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d56a4 push {r3, lr}
 *   @0x1d56a8 mov r1, #0
 *   @0x1d56ac ldr r0, [sp, #0x8]
 *   @0x1d56b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d56b4 ldr r3, [pc, #0x8]
 *   @0x1d56b8 ldr r3, [pc, r3]
 *   @0x1d56bc str r0, [r3]
 *   @0x1d56c0 pop {r3, pc}
 *   @0x1d56c4 eoreq r11, r1, r0, lsr #10
 *
 * ══ §446/828 F_GesturePinchAngleTowards(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d56c8  size 36  9 条（0x1d56c8..0x1d56ec）
 * @func 0x1d56c8 0x1d56fc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d56c8 push {r3, lr}
 *   @0x1d56cc mov r1, #0
 *   @0x1d56d0 ldr r0, [sp, #0x8]
 *   @0x1d56d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d56d8 ldr r3, [pc, #0x8]
 *   @0x1d56dc ldr r3, [pc, r3]
 *   @0x1d56e0 str r0, [r3]
 *   @0x1d56e4 pop {r3, pc}
 *   @0x1d56e8 eoreq r11, r1, r0, lsl #10
 *
 * ══ §447/828 F_GesturePinchAngleAway(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d56ec  size 36  9 条（0x1d56ec..0x1d5710）
 * @func 0x1d56ec 0x1d5720  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d56ec push {r3, lr}
 *   @0x1d56f0 mov r1, #0
 *   @0x1d56f4 ldr r0, [sp, #0x8]
 *   @0x1d56f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d56fc ldr r3, [pc, #0x8]
 *   @0x1d5700 ldr r3, [pc, r3]
 *   @0x1d5704 str r0, [r3]
 *   @0x1d5708 pop {r3, pc}
 *   @0x1d570c eoreq r11, r1, r0, ror #9
 *
 * ══ §448/828 F_GestureRotateAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5710  size 36  9 条（0x1d5710..0x1d5734）
 * @func 0x1d5710 0x1d5744  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5710 push {r3, lr}
 *   @0x1d5714 mov r1, #0
 *   @0x1d5718 ldr r0, [sp, #0x8]
 *   @0x1d571c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1d5720 ldr r3, [pc, #0x8]
 *   @0x1d5724 ldr r3, [pc, r3]
 *   @0x1d5728 str r0, [r3]
 *   @0x1d572c pop {r3, pc}
 *   @0x1d5730 eoreq r11, r1, r4, asr #9
 *
 * ══ §449/828 F_GestureTapCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5734  size 36  9 条（0x1d5734..0x1d5758）
 * @func 0x1d5734 0x1d5758  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5734 push {r3, lr}
 *   @0x1d5738 mov r1, #0
 *   @0x1d573c ldr r0, [sp, #0x8]
 *   @0x1d5740 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d5744 ldr r3, [pc, #0x8]
 *   @0x1d5748 ldr r3, [pc, r3]
 *   @0x1d574c strb r0, [r3]
 *   @0x1d5750 pop {r3, pc}
 *   @0x1d5754 eoreq r11, r1, r4, lsr #9
 *
 * ══ §450/828 F_Function_Not_Supported(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2160  size 36  9 条（0x1e2160..0x1e2184）
 * @func 0x1e2160 0x1e2184  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2160 mov r1, #0
 *   @0x1e2164 str r1, [r0, #0xc]
 *   @0x1e2168 mov r3, r1
 *   @0x1e216c movt r3, #0xbff0
 *   @0x1e2170 stm r0, {r1, r3}
 *   @0x1e2174 ldr r0, [pc, #0x4]
 *   @0x1e2178 add r0, pc, r0
 *   @0x1e217c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2180 andseq pc, r6, r8, lsr #25
 *
 * ══ §451/828 GV_GameDisplayName(CInstance*, int, RValue*)  0x1f9c14  size 36  9 条（0x1f9c14..0x1f9c38）
 * @func 0x1f9c14 0x1f9c48  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9c14 push {r3, lr}
 *   @0x1f9c18 mov r0, r2
 *   @0x1f9c1c ldr r3, [pc, #0x10]
 *   @0x1f9c20 ldr r3, [pc, r3]
 *   @0x1f9c24 ldr r1, [r3]
 *   @0x1f9c28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9c2c mov r0, #1
 *   @0x1f9c30 pop {r3, pc}
 *   @0x1f9c34 andseq r4, pc, r4, ror lr
 *
 * ══ §452/828 GV_GameProjectName(CInstance*, int, RValue*)  0x1f9c38  size 36  9 条（0x1f9c38..0x1f9c5c）
 * @func 0x1f9c38 0x1f9c5c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9c38 push {r3, lr}
 *   @0x1f9c3c mov r0, r2
 *   @0x1f9c40 ldr r3, [pc, #0x10]
 *   @0x1f9c44 ldr r3, [pc, r3]
 *   @0x1f9c48 ldr r1, [r3]
 *   @0x1f9c4c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9c50 mov r0, #1
 *   @0x1f9c54 pop {r3, pc}
 *   @0x1f9c58 andseq r6, pc, r4, lsr #30
 *
 * ══ §453/828 GV_WorkingDirectory(CInstance*, int, RValue*)  0x1f9c74  size 36  9 条（0x1f9c74..0x1f9c98）
 * @func 0x1f9c74 0x1f9ca8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9c74 push {r3, lr}
 *   @0x1f9c78 mov r0, r2
 *   @0x1f9c7c ldr r3, [pc, #0x10]
 *   @0x1f9c80 ldr r3, [pc, r3]
 *   @0x1f9c84 ldr r1, [r3]
 *   @0x1f9c88 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9c8c mov r0, #1
 *   @0x1f9c90 pop {r3, pc}
 *   @0x1f9c94 ldrsbeq r6, [pc], -r8
 *
 * ══ §454/828 GV_CaptionScore(CInstance*, int, RValue*)  0x1fa1c4  size 36  9 条（0x1fa1c4..0x1fa1e8）
 * @func 0x1fa1c4 0x1fa1f8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, _RefThing<char const*>*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa1c4 push {r3, lr}
 *   @0x1fa1c8 mov r0, r2
 *   @0x1fa1cc ldr r3, [pc, #0x10]
 *   @0x1fa1d0 ldr r3, [pc, r3]
 *   @0x1fa1d4 ldr r1, [r3]
 *   @0x1fa1d8 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE>
 *   @0x1fa1dc mov r0, #1
 *   @0x1fa1e0 pop {r3, pc}
 *   @0x1fa1e4 andseq r5, pc, r0, lsr #8
 *
 * ══ §455/828 GV_CaptionLives(CInstance*, int, RValue*)  0x1fa1e8  size 36  9 条（0x1fa1e8..0x1fa20c）
 * @func 0x1fa1e8 0x1fa21c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, _RefThing<char const*>*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa1e8 push {r3, lr}
 *   @0x1fa1ec mov r0, r2
 *   @0x1fa1f0 ldr r3, [pc, #0x10]
 *   @0x1fa1f4 ldr r3, [pc, r3]
 *   @0x1fa1f8 ldr r1, [r3]
 *   @0x1fa1fc bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE>
 *   @0x1fa200 mov r0, #1
 *   @0x1fa204 pop {r3, pc}
 *   @0x1fa208 andseq r5, pc, r4, lsl #8
 *
 * ══ §456/828 GV_CaptionHealth(CInstance*, int, RValue*)  0x1fa20c  size 36  9 条（0x1fa20c..0x1fa230）
 * @func 0x1fa20c 0x1fa240  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, _RefThing<char const*>*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa20c push {r3, lr}
 *   @0x1fa210 mov r0, r2
 *   @0x1fa214 ldr r3, [pc, #0x10]
 *   @0x1fa218 ldr r3, [pc, r3]
 *   @0x1fa21c ldr r1, [r3]
 *   @0x1fa220 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE>
 *   @0x1fa224 mov r0, #1
 *   @0x1fa228 pop {r3, pc}
 *   @0x1fa22c andseq r5, pc, r8, ror #7
 *
 * ══ §457/828 GV_ErrorLast(CInstance*, int, RValue*)  0x1fa230  size 36  9 条（0x1fa230..0x1fa254）
 * @func 0x1fa230 0x1fa264  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, _RefThing<char const*>*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa230 push {r3, lr}
 *   @0x1fa234 mov r0, r2
 *   @0x1fa238 ldr r3, [pc, #0x10]
 *   @0x1fa23c ldr r3, [pc, r3]
 *   @0x1fa240 ldr r1, [r3]
 *   @0x1fa244 bl 0xe7dac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE>
 *   @0x1fa248 mov r0, #1
 *   @0x1fa24c pop {r3, pc}
 *   @0x1fa250 andseq r3, pc, r0, ror #22
 *
 * ══ §458/828 SV_SpriteIndex(CInstance*, int, RValue*)  0x1faa10  size 36  9 条（0x1faa10..0x1faa34）
 * @func 0x1faa10 0x1faa34  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: INT32_RValue(RValue const*) / CInstance::SetSpriteIndex(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faa10 push {r4, lr}
 *   @0x1faa14 mov r4, r0
 *   @0x1faa18 mov r0, r2
 *   @0x1faa1c bl 0xd11b0 <_Z12INT32_RValuePK6RValue>
 *   @0x1faa20 mov r1, r0
 *   @0x1faa24 mov r0, r4
 *   @0x1faa28 bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi>
 *   @0x1faa2c mov r0, #1
 *   @0x1faa30 pop {r4, pc}
 *
 * ══ §459/828 CStream::LoadFromMemory(void*, long long)  0x201170  size 36  9 条（0x201170..0x201194）
 * @func 0x201170 0x201194  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201170 push {r4, r5}
 *   @0x201174 mov r3, #0
 *   @0x201178 mov r4, #0
 *   @0x20117c mov r5, #0
 *   @0x201180 str r1, [r0, #0x18]
 *   @0x201184 strd r4, r5, [r0, #16]
 *   @0x201188 strd r2, r3, [r0, #8]
 *   @0x20118c pop {r4, r5}
 *   @0x201190 bx lr
 *
 * ══ §460/828 CDS_Stack::Pop()  0x202d00  size 36  9 条（0x202d00..0x202d24）
 * @func 0x202d00 0x202d34  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202d00 ldr r3, [r0, #0x4]
 *   @0x202d04 cmp r3, #0
 *   @0x202d08 subne r1, r3, #-268435455
 *   @0x202d0c subne r3, r3, #1
 *   @0x202d10 ldrne r2, [r0, #0xc]
 *   @0x202d14 strne r3, [r0, #0x4]
 *   @0x202d18 addne r0, r2, r1, lsl #4
 *   @0x202d1c moveq r0, r3
 *   @0x202d20 bx lr
 *
 * ══ §461/828 CDS_List::CDS_List()  0x202ff8  size 36  9 条（0x202ff8..0x20301c）
 * @func 0x202ff8 0x20301c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202ff8 ldr r1, [pc, #0x18]
 *   @0x202ffc mov r2, #0
 *   @0x203000 str r2, [r0, #0x8]
 *   @0x203004 ldr r1, [pc, r1]
 *   @0x203008 str r2, [r0, #0xc]
 *   @0x20300c add r1, r1, #8
 *   @0x203010 stm r0, {r1, r2}
 *   @0x203014 bx lr
 *   @0x203018 mulseq lr, r0, r3
 *
 * ══ §462/828 CSound::Discard()  0x215724  size 36  9 条（0x215724..0x215748）
 * @func 0x215724 0x215758  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::Discard()+0x18 / SND_Delete(int)
 * 字段偏移 top8: 0x30×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215724 push {r4, lr}
 *   @0x215728 mov r4, r0
 *   @0x21572c ldr r0, [r0, #0x30]
 *   @0x215730 cmp r0, #0
 *   @0x215734 blt 0x21573c <_ZN6CSound7DiscardEv+0x18>
 *   @0x215738 bl 0x21eadc <_Z10SND_Deletei>
 *   @0x21573c mvn r3, #0
 *   @0x215740 str r3, [r4, #0x30]
 *   @0x215744 pop {r4, pc}
 *
 * ══ §463/828 Audio_StartSoundNoise(cAudio_Sound*, CNoise*)  0x2173d8  size 36  9 条（0x2173d8..0x2173fc）
 * @func 0x2173d8 0x2173fc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2173d8 ldr r3, [pc, #0x18]
 *   @0x2173dc ldr r3, [pc, r3]
 *   @0x2173e0 ldrb r3, [r3]
 *   @0x2173e4 cmp r3, #0
 *   @0x2173e8 bne 0x2173f0 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise+0x18>
 *   @0x2173ec b 0x216048 <_Z7checkALPKc+0x78>
 *   @0x2173f0 mov r0, #0
 *   @0x2173f4 bx lr
 *   @0x2173f8 andseq r7, sp, r0, ror r12
 *
 * ══ §464/828 ReadU32(void*)  0x220164  size 36  9 条（0x220164..0x220188）
 * @func 0x220164 0x220188  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220164 ldrb r3, [r0, #0x2]
 *   @0x220168 ldrb r1, [r0, #0x1]
 *   @0x22016c ldrb r2, [r0]
 *   @0x220170 lsl r3, r3, #16
 *   @0x220174 ldrb r0, [r0, #0x3]
 *   @0x220178 orr r3, r3, r1, lsl #8
 *   @0x22017c orr r3, r3, r2
 *   @0x220180 orr r0, r3, r0, lsl #24
 *   @0x220184 bx lr
 *
 * ══ §465/828 alutCreateBufferFromFile  0x222614  size 36  9 条（0x222614..0x222638）
 * @func 0x222614 0x222638  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromFile
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222614 push {r4, lr}
 *   @0x222618 mov r4, r0
 *   @0x22261c bl 0x2219a8 <_alutSanityCheck>
 *   @0x222620 cmp r0, #0
 *   @0x222624 popeq {r4, pc}
 *   @0x222628 mov r0, r4
 *   @0x22262c bl 0x221ce0 <_alutInputStreamConstructFromFile>
 *   @0x222630 pop {r4, lr}
 *   @0x222634 b 0x2225cc <_alutCreateBufferFromInputStream>
 *
 * ══ §466/828 res0_free_info  0x22dee4  size 36  9 条（0x22dee4..0x22df08）
 * @func 0x22dee4 0x22df08  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22dee4 push {r4, lr}
 *   @0x22dee8 subs r4, r0, #0
 *   @0x22deec popeq {r4, pc}
 *   @0x22def0 mov r1, #0
 *   @0x22def4 movw r2, #0x918
 *   @0x22def8 bl 0xb65b0 <memset@plt>
 *   @0x22defc mov r0, r4
 *   @0x22df00 pop {r4, lr}
 *   @0x22df04 b 0xb655c <free@plt>
 *
 * ══ §467/828 ogg_packet_clear  0x23538c  size 36  9 条（0x23538c..0x2353b0）
 * @func 0x23538c 0x2353c0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23538c push {r4, lr}
 *   @0x235390 mov r4, r0
 *   @0x235394 ldr r0, [r0]
 *   @0x235398 bl 0xb655c <free@plt>
 *   @0x23539c mov r0, r4
 *   @0x2353a0 mov r1, #0
 *   @0x2353a4 mov r2, #32
 *   @0x2353a8 pop {r4, lr}
 *   @0x2353ac b 0xb65b0 <memset@plt>
 *
 * ══ §468/828 JS_JSON_stringify(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cc78  size 36  9 条（0x23cc78..0x23cc9c）
 * @func 0x23cc78 0x23cc9c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: EncodeValue(RValue*) / json_object_to_json_string
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cc78 push {r4, lr}
 *   @0x23cc7c mov r4, r0
 *   @0x23cc80 ldr r0, [sp, #0x8]
 *   @0x23cc84 bl 0x13be2c <_Z11EncodeValueP6RValue>
 *   @0x23cc88 bl 0x27e830 <json_object_to_json_string>
 *   @0x23cc8c mov r1, r0
 *   @0x23cc90 mov r0, r4
 *   @0x23cc94 pop {r4, lr}
 *   @0x23cc98 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §469/828 pcre_free_study  0x2668d0  size 36  9 条（0x2668d0..0x2668f4）
 * @func 0x2668d0 0x2668f4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2668d0 cmp r0, #0
 *   @0x2668d4 push {r3, lr}
 *   @0x2668d8 popeq {r3, pc}
 *   @0x2668dc ldr r3, [pc, #0xc]
 *   @0x2668e0 ldr r3, [pc, r3]
 *   @0x2668e4 ldr r3, [r3]
 *   @0x2668e8 blx r3
 *   @0x2668ec pop {r3, pc}
 *   @0x2668f0 andseq r9, r8, r8, lsr #27
 *
 * ══ §470/828 mc_abort  0x27e320  size 36  9 条（0x27e320..0x27e344）
 * @func 0x27e320 0x27e344  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6cf4 / 0xb6688
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e320 push {r0, r1, r2, r3}
 *   @0x27e324 str lr, [sp, #-0x4]!
 *   @0x27e328 sub sp, sp, #12
 *   @0x27e32c add r1, sp, #20
 *   @0x27e330 ldr r0, [sp, #0x10]
 *   @0x27e334 str r1, [sp, #0x4]
 *   @0x27e338 bl 0xb6cf4 <vprintf@plt>
 *   @0x27e33c mov r0, #1
 *   @0x27e340 bl 0xb6688 <exit@plt>
 *
 * ══ §471/828 _spAttachmentLoader_deinit  0x284d14  size 36  9 条（0x284d14..0x284d38）
 * @func 0x284d14 0x284d38  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284d14 push {r4, lr}
 *   @0x284d18 mov r4, r0
 *   @0x284d1c ldr r0, [r0, #0x8]
 *   @0x284d20 bl 0x285c80 <_free>
 *   @0x284d24 ldr r0, [r4]
 *   @0x284d28 bl 0x285c80 <_free>
 *   @0x284d2c ldr r0, [r4, #0x4]
 *   @0x284d30 pop {r4, lr}
 *   @0x284d34 b 0x285c80 <_free>
 *
 * ══ §472/828 spEventData_dispose  0x285bec  size 36  9 条（0x285bec..0x285c10）
 * @func 0x285bec 0x285c10  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285bec push {r4, lr}
 *   @0x285bf0 mov r4, r0
 *   @0x285bf4 ldr r0, [r0, #0xc]
 *   @0x285bf8 bl 0x285c80 <_free>
 *   @0x285bfc ldr r0, [r4]
 *   @0x285c00 bl 0x285c80 <_free>
 *   @0x285c04 mov r0, r4
 *   @0x285c08 pop {r4, lr}
 *   @0x285c0c b 0x285c80 <_free>
 *
 * ══ §473/828 spIkConstraintData_dispose  0x286758  size 36  9 条（0x286758..0x28677c）
 * @func 0x286758 0x28677c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x286758 push {r4, lr}
 *   @0x28675c mov r4, r0
 *   @0x286760 ldr r0, [r0]
 *   @0x286764 bl 0x285c80 <_free>
 *   @0x286768 ldr r0, [r4, #0x8]
 *   @0x28676c bl 0x285c80 <_free>
 *   @0x286770 mov r0, r4
 *   @0x286774 pop {r4, lr}
 *   @0x286778 b 0x285c80 <_free>
 *
 * ══ §474/828 spPathConstraintData_dispose  0x288f34  size 36  9 条（0x288f34..0x288f58）
 * @func 0x288f34 0x288f68  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288f34 push {r4, lr}
 *   @0x288f38 mov r4, r0
 *   @0x288f3c ldr r0, [r0]
 *   @0x288f40 bl 0x285c80 <_free>
 *   @0x288f44 ldr r0, [r4, #0x8]
 *   @0x288f48 bl 0x285c80 <_free>
 *   @0x288f4c mov r0, r4
 *   @0x288f50 pop {r4, lr}
 *   @0x288f54 b 0x285c80 <_free>
 *
 * ══ §475/828 _Entry_dispose  0x28ec20  size 36  9 条（0x28ec20..0x28ec44）
 * @func 0x28ec20 0x28ec44  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAttachment_dispose / _free
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ec20 push {r4, lr}
 *   @0x28ec24 mov r4, r0
 *   @0x28ec28 ldr r0, [r0, #0x8]
 *   @0x28ec2c bl 0x284cb4 <spAttachment_dispose>
 *   @0x28ec30 ldr r0, [r4, #0x4]
 *   @0x28ec34 bl 0x285c80 <_free>
 *   @0x28ec38 mov r0, r4
 *   @0x28ec3c pop {r4, lr}
 *   @0x28ec40 b 0x285c80 <_free>
 *
 * ══ §476/828 spSlotData_dispose  0x28efa8  size 36  9 条（0x28efa8..0x28efcc）
 * @func 0x28efa8 0x28efcc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28efa8 push {r4, lr}
 *   @0x28efac mov r4, r0
 *   @0x28efb0 ldr r0, [r0, #0x4]
 *   @0x28efb4 bl 0x285c80 <_free>
 *   @0x28efb8 ldr r0, [r4, #0xc]
 *   @0x28efbc bl 0x285c80 <_free>
 *   @0x28efc0 mov r0, r4
 *   @0x28efc4 pop {r4, lr}
 *   @0x28efc8 b 0x285c80 <_free>
 *
 * ══ §477/828 spTransformConstraintData_dispose  0x28f608  size 36  9 条（0x28f608..0x28f62c）
 * @func 0x28f608 0x28f63c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f608 push {r4, lr}
 *   @0x28f60c mov r4, r0
 *   @0x28f610 ldr r0, [r0]
 *   @0x28f614 bl 0x285c80 <_free>
 *   @0x28f618 ldr r0, [r4, #0x8]
 *   @0x28f61c bl 0x285c80 <_free>
 *   @0x28f620 mov r0, r4
 *   @0x28f624 pop {r4, lr}
 *   @0x28f628 b 0x285c80 <_free>
 *
 * ══ §478/828 zip_stat  0x2a5670  size 36  9 条（0x2a5670..0x2a5694）
 * @func 0x2a5670 0x2a5694  size 36  9 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: zip_name_locate
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5670 push {r4, r5, r6, lr}
 *   @0x2a5674 mov r4, r2
 *   @0x2a5678 bl 0x2a4a58 <zip_name_locate>
 *   @0x2a567c subs r1, r0, #0x0
 *   @0x2a5680 mov r0, r5
 *   @0x2a5684 mov r3, r6
 *   @0x2a5688 .word 0xf0004070
 *   @0x2a568c .word 0xf04fb803
 *   @0x2a5690 ldcllt p0, c3, [r0, #-1020]!
 *
 * ══ §479/828 jpeg_alloc_quant_table  0x2bc8e4  size 36  9 条（0x2bc8e4..0x2bc908）
 * @func 0x2bc8e4 0x2bc918  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc8e4 push {r3, lr}
 *   @0x2bc8e8 mov r1, #0
 *   @0x2bc8ec ldr r3, [r0, #0x4]
 *   @0x2bc8f0 mov r2, #130
 *   @0x2bc8f4 ldr r3, [r3]
 *   @0x2bc8f8 blx r3
 *   @0x2bc8fc mov r2, #0
 *   @0x2bc900 strb r2, [r0, #0x80]
 *   @0x2bc904 pop {r3, pc}
 *
 * ══ §480/828 jpeg_alloc_huff_table  0x2bc908  size 36  9 条（0x2bc908..0x2bc92c）
 * @func 0x2bc908 0x2bc92c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x111×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc908 push {r3, lr}
 *   @0x2bc90c mov r1, #0
 *   @0x2bc910 ldr r3, [r0, #0x4]
 *   @0x2bc914 movw r2, #0x112
 *   @0x2bc918 ldr r3, [r3]
 *   @0x2bc91c blx r3
 *   @0x2bc920 mov r2, #0
 *   @0x2bc924 strb r2, [r0, #0x111]
 *   @0x2bc928 pop {r3, pc}
 *
 * ══ §481/828 GifBitSize(int)  0x2c2b8c  size 36  9 条（0x2c2b8c..0x2c2bb0）
 * @func 0x2c2b8c 0x2c2bb0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifBitSize(int)+0x1c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2b8c mov r3, #1
 *   @0x2c2b90 mov r2, r3
 *   @0x2c2b94 cmp r0, r2, lsl r3
 *   @0x2c2b98 ble 0x2c2ba8 <_Z10GifBitSizei+0x1c>
 *   @0x2c2b9c add r3, r3, #1
 *   @0x2c2ba0 cmp r3, #9
 *   @0x2c2ba4 bne 0x2c2b94 <_Z10GifBitSizei+0x8>
 *   @0x2c2ba8 mov r0, r3
 *   @0x2c2bac bx lr
 *
 * ══ §482/828 b2MouseJoint::ShiftOrigin(b2Vec2 const&)  0x2ce9e0  size 36  9 条（0x2ce9e0..0x2cea04）
 * @func 0x2ce9e0 0x2cea04  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce9e0 vldr s15, [r1]
 *   @0x2ce9e4 vldr s14, [r0, #76]
 *   @0x2ce9e8 vldr s13, [r0, #80]
 *   @0x2ce9ec vsub.f32 s14, s14, s15
 *   @0x2ce9f0 vldr s15, [r1, #4]
 *   @0x2ce9f4 vsub.f32 s15, s13, s15
 *   @0x2ce9f8 vstr s14, [r0, #76]
 *   @0x2ce9fc vstr s15, [r0, #80]
 *   @0x2cea00 bx lr
 *
 * ══ §483/828 b2RevoluteJoint::GetJointAngle() const  0x2d2104  size 36  9 条（0x2d2104..0x2d2128）
 * @func 0x2d2104 0x2d2138  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2104 ldr r3, [r0, #0x34]
 *   @0x2d2108 vldr s13, [r3, #72]
 *   @0x2d210c ldr r3, [r0, #0x30]
 *   @0x2d2110 vldr s14, [r3, #72]
 *   @0x2d2114 vsub.f32 s14, s13, s14
 *   @0x2d2118 vldr s15, [r0, #116]
 *   @0x2d211c vsub.f32 s15, s14, s15
 *   @0x2d2120 vmov r0, s15
 *   @0x2d2124 bx lr
 *
 * ══ §484/828 b2ParticleSystem::DestroyParticle(int, bool)  0x2d51c0  size 36  9 条（0x2d51c0..0x2d51e4）
 * @func 0x2d51c0 0x2d51e4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d51c0 ldr r3, [r0, #0x30]
 *   @0x2d51c4 cmp r2, #0
 *   @0x2d51c8 movw r0, #0x202
 *   @0x2d51cc movne r2, r0
 *   @0x2d51d0 moveq r2, #2
 *   @0x2d51d4 ldr r0, [r3, r1, lsl #2]
 *   @0x2d51d8 orr r0, r0, r2
 *   @0x2d51dc str r0, [r3, r1, lsl #2]
 *   @0x2d51e0 bx lr
 *
 * ══ §485/828 b2ParticleSystem::SetParticleRadius(float)  0x2d8270  size 36  9 条（0x2d8270..0x2d8294）
 * @func 0x2d8270 0x2d8294  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8270 vmov s13, r1
 *   @0x2d8274 vmov.f32 s14, #1.000000e+00
 *   @0x2d8278 vadd.f32 s15, s13, s13
 *   @0x2d827c vdiv.f32 s14, s14, s15
 *   @0x2d8280 vstr s15, [r0, #24]
 *   @0x2d8284 vmul.f32 s15, s15, s15
 *   @0x2d8288 vstr s14, [r0, #28]
 *   @0x2d828c vstr s15, [r0, #32]
 *   @0x2d8290 bx lr
 *
 * ══ §486/828 FT_Outline_Transform  0x2e6580  size 36  9 条（0x2e6580..0x2e65a4）
 * @func 0x2e6580 0x2e65a4  size 36  9 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6580 push {r4, r5, r6, lr}
 *   @0x2e6584 cbz r0, 0x2e65a2 <FT_Outline_Transform+0x22>
 *   @0x2e6588 ldrsh.w r6, [r0, #0x2]
 *   @0x2e658c ldr r4, [r0, #0x4]
 *   @0x2e6590 adcsmi r0, r4, #207618048
 *   @0x2e6594 bhs 0x2e65a2 <FT_Outline_Transform+0x22>
 *   @0x2e6598 mov r1, r5
 *   @0x2e659c strlo pc, [r8], #-4053
 *   @0x2e65a0 b 0x2e6592 <FT_Outline_Transform+0x12>
 *
 * ══ §487/828 FT_Stream_Seek  0x2e68a6  size 36  9 条（0x2e68a6..0x2e68ca）
 * @func 0x2e68a6 0x2e68ca  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e68a6 push {r4, r5, r6, lr}
 *   @0x2e68aa ldr r6, [r0, #0x14]
 *   @0x2e68ae cbz r6, 0x2e68ba <FT_Stream_Seek+0x14>
 *   @0x2e68b2 mov r3, r2
 *   @0x2e68b6 cbnz r0, 0x2e68c6 <FT_Stream_Seek+0x20>
 *   @0x2e68ba ldr r3, [r0, #0x4]
 *   @0x2e68be bhi 0x2e68c6 <FT_Stream_Seek+0x20>
 *   @0x2e68c2 movs r0, #0x0
 *   @0x2e68c6 movs r0, #0x55
 *
 * ══ §488/828 ft_mem_strdup  0x2e88c2  size 36  9 条（0x2e88c2..0x2e88e6）
 * @func 0x2e88c2 0x2e88f6  size 52  13 条
 * 部分覆盖: 本节 10/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e88c2 push {r4, r5, r6, lr}
 *   @0x2e88c6 mov r5, r2
 *   @0x2e88ca cbz r1, 0x2e88d6 <ft_mem_strdup+0x14>
 *   @0x2e88ce blx 0xb6538 <strlen@plt>
 *   @0x2e88d2 adds r2, r0, #0x1
 *   @0x2e88d6 mov r2, r1
 *   @0x2e88da mov r1, r4
 *   @0x2e88de pop.w {r4, r5, r6, lr}
 *   @0x2e88e2 b.w 0x2e8898 <ft_mem_dup>
 *
 * ══ §489/828 FT_List_Up  0x2e8a76  size 36  9 条（0x2e8a76..0x2e8a9a）
 * @func 0x2e8a76 0x2e8a9a  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8a76 cbz r0, 0x2e8a98 <FT_List_Up+0x22>
 *   @0x2e8a7a ldr r3, [r1]
 *   @0x2e8a7e cbz r3, 0x2e8a98 <FT_List_Up+0x22>
 *   @0x2e8a82 cbz r2, 0x2e8a88 <FT_List_Up+0x12>
 *   @0x2e8a86 b 0x2e8a8a <FT_List_Up+0x14>
 *   @0x2e8a8a movs r3, #0x0
 *   @0x2e8a8e ldr r3, [r0]
 *   @0x2e8a92 ldr r3, [r0]
 *   @0x2e8a96 str r1, [r0]
 *
 * ══ §490/828 anon_319c40  0x319c40  size 36  9 条（0x319c40..0x319c64）
 * @func 0x319c40 0x319c64  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Unwind_VRS_Get
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319c40 push {r0, r1, r2, r3, r4, lr}
 *   @0x319c44 mov r2, r1
 *   @0x319c48 mov r1, #0
 *   @0x319c4c add r3, sp, #12
 *   @0x319c50 str r3, [sp]
 *   @0x319c54 mov r3, r1
 *   @0x319c58 bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x319c5c ldr r0, [sp, #0xc]
 *   @0x319c60 add sp, sp, #20
 *
 * ══ §491/828 ___Unwind_RaiseException  0x31a5fc  size 36  9 条（0x31a5fc..0x31a620）
 * @func 0x31a5fc 0x31a630  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_Unwind_RaiseException
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a5fc push {sp, lr, pc}
 *   @0x31a600 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
 *   @0x31a604 mov r3, #0
 *   @0x31a608 push {r2, r3}
 *   @0x31a60c add r1, sp, #4
 *   @0x31a610 bl 0x319a6c <__gnu_Unwind_RaiseException>
 *   @0x31a614 ldr lr, [sp, #0x40]
 *   @0x31a618 add sp, sp, #72
 *   @0x31a61c bx lr
 *
 * ══ §492/828 ___Unwind_Resume  0x31a620  size 36  9 条（0x31a620..0x31a644）
 * @func 0x31a620 0x31a654  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_Unwind_Resume
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a620 push {sp, lr, pc}
 *   @0x31a624 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
 *   @0x31a628 mov r3, #0
 *   @0x31a62c push {r2, r3}
 *   @0x31a630 add r1, sp, #4
 *   @0x31a634 bl 0x319b2c <__gnu_Unwind_Resume>
 *   @0x31a638 ldr lr, [sp, #0x40]
 *   @0x31a63c add sp, sp, #72
 *   @0x31a640 bx lr
 *
 * ══ §493/828 ___Unwind_Resume_or_Rethrow  0x31a644  size 36  9 条（0x31a644..0x31a668）
 * @func 0x31a644 0x31a678  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_Unwind_Resume_or_Rethrow
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a644 push {sp, lr, pc}
 *   @0x31a648 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
 *   @0x31a64c mov r3, #0
 *   @0x31a650 push {r2, r3}
 *   @0x31a654 add r1, sp, #4
 *   @0x31a658 bl 0x319ba0 <__gnu_Unwind_Resume_or_Rethrow>
 *   @0x31a65c ldr lr, [sp, #0x40]
 *   @0x31a660 add sp, sp, #72
 *   @0x31a664 bx lr
 *
 * ══ §494/828 ___Unwind_ForcedUnwind  0x31a668  size 36  9 条（0x31a668..0x31a68c）
 * @func 0x31a668 0x31a69c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_Unwind_ForcedUnwind
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a668 push {sp, lr, pc}
 *   @0x31a66c push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
 *   @0x31a670 mov r3, #0
 *   @0x31a674 push {r2, r3}
 *   @0x31a678 add r3, sp, #4
 *   @0x31a67c bl 0x319b10 <__gnu_Unwind_ForcedUnwind>
 *   @0x31a680 ldr lr, [sp, #0x40]
 *   @0x31a684 add sp, sp, #72
 *   @0x31a688 bx lr
 *
 * ══ §495/828 ___Unwind_Backtrace  0x31a68c  size 36  9 条（0x31a68c..0x31a6b0）
 * @func 0x31a68c 0x31a6b0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __gnu_Unwind_Backtrace
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a68c push {sp, lr, pc}
 *   @0x31a690 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
 *   @0x31a694 mov r3, #0
 *   @0x31a698 push {r2, r3}
 *   @0x31a69c add r2, sp, #4
 *   @0x31a6a0 bl 0x319cf0 <__gnu_Unwind_Backtrace>
 *   @0x31a6a4 ldr lr, [sp, #0x40]
 *   @0x31a6a8 add sp, sp, #72
 *   @0x31a6ac bx lr
 *
 * ══ §496/828 png_get_sRGB  0x2a689e  size 34  9 条（0x2a689e..0x2a68c0）
 * @func 0x2a689e 0x2a68c2  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a689e cbz r0, 0x2a68be <png_get_sRGB+0x20>
 *   @0x2a68a2 ldr r0, [r1, #0x8]
 *   @0x2a68a6 andle r6, r9, r0
 *   @0x2a68aa cbz r2, 0x2a68bc <png_get_sRGB+0x1e>
 *   @0x2a68ae vst4.8 {d19, d20, d21, d22}, [pc:128], r12
 *   @0x2a68b2 andsvs r6, r3, r0
 *   @0x2a68b6 bx lr
 *   @0x2a68ba bx lr
 *   @0x2a68be bx lr
 *
 * ══ §497/828 png_get_PLTE  0x2a6ad0  size 34  9 条（0x2a6ad0..0x2a6af2）
 * @func 0x2a6ad0 0x2a6b02  size 50  13 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6ad0 cbz r0, 0x2a6af0 <png_get_PLTE+0x20>
 *   @0x2a6ad4 ldr r0, [r1, #0x8]
 *   @0x2a6ad8 andle r0, r9, r8
 *   @0x2a6adc cbz r2, 0x2a6aee <png_get_PLTE+0x1e>
 *   @0x2a6ae0 str r0, [r2]
 *   @0x2a6ae4 ldrh r2, [r1, #0x14]
 *   @0x2a6ae8 bx lr
 *   @0x2a6aec bx lr
 *   @0x2a6af0 bx lr
 *
 * ══ §498/828 png_set_sCAL  0x2aec48  size 34  9 条（0x2aec48..0x2aec6a）
 * @func 0x2aec48 0x2aec6c  size 36  9 条
 * 部分覆盖: 本节 9/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aec48 cbz r0, 0x2aec68 <png_set_sCAL+0x20>
 *   @0x2aec4c strb.w r2, [r1, #0xdc]
 *   @0x2aec50 ldrd r2, r3, [sp]
 *   @0x2aec54 strd r2, r3, [r1, #224]
 *   @0x2aec58 ldrd r2, r3, [sp, #8]
 *   @0x2aec5c strd r2, r3, [r1, #232]
 *   @0x2aec60 ldr r3, [r1, #0x8]
 *   @0x2aec64 addvs r4, r11, r0, lsl #7
 *   @0x2aec68 bx lr
 *
 * ══ §499/828 png_write_chunk_data  0x2b1204  size 34  9 条（0x2b1204..0x2b1226）
 * @func 0x2b1204 0x2b1228  size 36  9 条
 * 部分覆盖: 本节 9/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1204 push {r4, r5, r6, lr}
 *   @0x2b1208 mov r4, r2
 *   @0x2b120c cbz r0, 0x2b1224 <png_write_chunk_data+0x20>
 *   @0x2b1210 cbz r2, 0x2b1224 <png_write_chunk_data+0x20>
 *   @0x2b1214 ldrtmi pc, [r0], -sp, ror #25
 *   @0x2b1218 mov r1, r5
 *   @0x2b121c pop.w {r4, r5, r6, lr}
 *   @0x2b1220 b.w 0x2a5b08 <png_calculate_crc>
 *   @0x2b1224 pop {r4, r5, r6, pc}
 *
 * ══ §500/828 FT_Face_GetCharVariantIsDefault  0x2e5da0  size 34  9 条（0x2e5da0..0x2e5dc2）
 * @func 0x2e5da0 0x2e5dd2  size 50  13 条
 * 部分覆盖: 本节 10/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5da0 push {r3, r4, r5, lr}
 *   @0x2e5da4 mov r4, r2
 *   @0x2e5da8 mov.w r0, #0xffffffff
 *   @0x2e5dac pop {r3, r4, r5, pc}
 *   @0x2e5db0 stmdahs r0, {r0, r1, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e5db4 beq 0x2e5da8 <FT_Face_GetCharVariantIsDefault+0x8>
 *   @0x2e5db8 mov r1, r5
 *   @0x2e5dbc ldr r3, [r3, #0x18]
 *   @0x2e5dc0 pop {r3, r4, r5, pc}
 *
 * ══ §501/828 FT_New_Face  0x2e90d8  size 34  9 条（0x2e90d8..0x2e90fa）
 * @func 0x2e90d8 0x2e90fc  size 36  9 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e90d8 push {r4, lr}
 *   @0x2e90dc cbz r1, 0x2e90f4 <FT_New_Face+0x1c>
 *   @0x2e90e0 movs r1, #0x0
 *   @0x2e90e4 movs r1, #0x1
 *   @0x2e90e8 add r1, sp, #0x8
 *   @0x2e90ec str r4, [sp, #0x8]
 *   @0x2e90f0 and pc, r0, r3, lsr #27
 *   @0x2e90f4 movs r0, #0x6
 *   @0x2e90f8 pop {r4, pc}
 *
 * ══ §502/828 VMWriteBuffer::AddVal(double)  0xec6dc  size 32  8 条（0xec6dc..0xec6fc）
 * @func 0xec6dc 0xec6fc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VMWriteBuffer::Add(int, ...)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec6dc str lr, [sp, #-0x4]!
 *   @0xec6e0 sub sp, sp, #12
 *   @0xec6e4 mov r1, #2
 *   @0xec6e8 strd r2, r3, [sp]
 *   @0xec6ec ldm sp, {r2, r3}
 *   @0xec6f0 bl 0xec674 <_ZN13VMWriteBuffer3AddEiz>
 *   @0xec6f4 add sp, sp, #12
 *   @0xec6f8 ldr pc, [sp], #4
 *
 * ══ §503/828 VMWriteBuffer::AddVal(long long)  0xec71c  size 32  8 条（0xec71c..0xec73c）
 * @func 0xec71c 0xec73c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VMWriteBuffer::Add(int, ...)
 * 字段偏移 top8: 0x4×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec71c str lr, [sp, #-0x4]!
 *   @0xec720 sub sp, sp, #12
 *   @0xec724 mov r1, #2
 *   @0xec728 strd r2, r3, [sp]
 *   @0xec72c ldr r3, [sp, #0x4]
 *   @0xec730 bl 0xec674 <_ZN13VMWriteBuffer3AddEiz>
 *   @0xec734 add sp, sp, #12
 *   @0xec738 ldr pc, [sp], #4
 *
 * ══ §504/828 InputQuery::QuestionAsync(char const*, char const*)  0xf26ec  size 32  8 条（0xf26ec..0xf270c）
 * @func 0xf26ec 0xf271c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExitFullScreen()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf26ec push {r3, r4, r5, lr}
 *   @0xf26f0 mov r5, r0
 *   @0xf26f4 mov r4, r1
 *   @0xf26f8 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xf26fc mov r0, r5
 *   @0xf2700 mov r1, r4
 *   @0xf2704 pop {r3, r4, r5, lr}
 *   @0xf2708 b 0xf2350 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_>
 *
 * ══ §505/828 InputQuery::ShowMessageASync(char const*, char const*)  0xf270c  size 32  8 条（0xf270c..0xf272c）
 * @func 0xf270c 0xf273c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExitFullScreen()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf270c push {r3, r4, r5, lr}
 *   @0xf2710 mov r5, r0
 *   @0xf2714 mov r4, r1
 *   @0xf2718 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xf271c mov r0, r5
 *   @0xf2720 mov r1, r4
 *   @0xf2724 pop {r3, r4, r5, lr}
 *   @0xf2728 b 0xf259c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_>
 *
 * ══ §506/828 InputQuery::LoginASync(char const*, char const*)  0xf272c  size 32  8 条（0xf272c..0xf274c）
 * @func 0xf272c 0xf274c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExitFullScreen()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf272c push {r3, r4, r5, lr}
 *   @0xf2730 mov r5, r0
 *   @0xf2734 mov r4, r1
 *   @0xf2738 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xf273c mov r0, r5
 *   @0xf2740 mov r1, r4
 *   @0xf2744 pop {r3, r4, r5, lr}
 *   @0xf2748 b 0xf2474 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_>
 *
 * ══ §507/828 YYGML_motion_set(CInstance*, float, float)  0x10ac7c  size 32  8 条（0x10ac7c..0x10ac9c）
 * @func 0x10ac7c 0x10ac9c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetDirection(float)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ac7c push {r3, r4, r5, lr}
 *   @0x10ac80 mov r4, r2
 *   @0x10ac84 mov r5, r0
 *   @0x10ac88 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x10ac8c mov r0, r5
 *   @0x10ac90 mov r1, r4
 *   @0x10ac94 pop {r3, r4, r5, lr}
 *   @0x10ac98 b 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *
 * ══ §508/828 F_Int64(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ee20  size 32  8 条（0x10ee20..0x10ee40）
 * @func 0x10ee20 0x10ee50  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: INT64_RValue(RValue const*)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ee20 push {r4, lr}
 *   @0x10ee24 mov r4, r0
 *   @0x10ee28 mov r3, #10
 *   @0x10ee2c ldr r0, [sp, #0x8]
 *   @0x10ee30 str r3, [r4, #0xc]
 *   @0x10ee34 bl 0xd10a4 <_Z12INT64_RValuePK6RValue>
 *   @0x10ee38 stm r4, {r0, r1}
 *   @0x10ee3c pop {r4, pc}
 *
 * ══ §509/828 F_Ptr(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ee40  size 32  8 条（0x10ee40..0x10ee60）
 * @func 0x10ee40 0x10ee60  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: PTR_RValue(RValue const*)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ee40 push {r4, lr}
 *   @0x10ee44 mov r4, r0
 *   @0x10ee48 mov r3, #3
 *   @0x10ee4c ldr r0, [sp, #0x8]
 *   @0x10ee50 str r3, [r4, #0xc]
 *   @0x10ee54 bl 0xd0fc0 <_Z10PTR_RValuePK6RValue>
 *   @0x10ee58 str r0, [r4]
 *   @0x10ee5c pop {r4, pc}
 *
 * ══ §510/828 F_Typeof(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f3a0  size 32  8 条（0x10f3a0..0x10f3c0）
 * @func 0x10f3a0 0x10f3c0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: KindName(RValue const*)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f3a0 push {r4, lr}
 *   @0x10f3a4 mov r4, r0
 *   @0x10f3a8 ldr r0, [sp, #0x8]
 *   @0x10f3ac bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0x10f3b0 mov r1, r0
 *   @0x10f3b4 mov r0, r4
 *   @0x10f3b8 pop {r4, lr}
 *   @0x10f3bc b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §511/828 utf8_char_size  0x110390  size 32  8 条（0x110390..0x1103b0）
 * @func 0x110390 0x1103b0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_char_size+0x18
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110390 cmp r0, #127
 *   @0x110394 bls 0x1103a8 <utf8_char_size+0x18>
 *   @0x110398 cmp r0, #2048
 *   @0x11039c movlo r0, #2
 *   @0x1103a0 movhs r0, #3
 *   @0x1103a4 bx lr
 *   @0x1103a8 mov r0, #1
 *   @0x1103ac bx lr
 *
 * ══ §512/828 F_ExternalFree(RValue&, CInstance*, CInstance*, int, RValue*)  0x114bd4  size 32  8 条（0x114bd4..0x114bf4）
 * @func 0x114bd4 0x114bf4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114bd4 push {r3, lr}
 *   @0x114bd8 mov r1, #0
 *   @0x114bdc ldr r0, [sp, #0x8]
 *   @0x114be0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x114be4 cmp r0, #0
 *   @0x114be8 popeq {r3, pc}
 *   @0x114bec pop {r3, lr}
 *   @0x114bf0 b 0x214904 <_Z8DLL_FreePKc>
 *
 * ══ §513/828 F_KeyboardClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1273d4  size 32  8 条（0x1273d4..0x1273f4）
 * @func 0x1273d4 0x1273f4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ProcessMessages() / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1273d4 push {r4, lr}
 *   @0x1273d8 ldr r4, [sp, #0x8]
 *   @0x1273dc bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1273e0 mov r1, #0
 *   @0x1273e4 mov r0, r4
 *   @0x1273e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1273ec pop {r4, lr}
 *   @0x1273f0 b 0x18bf54 <_Z12IO_Key_Cleari>
 *
 * ══ §514/828 F_ResourceGetIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ec40  size 32  8 条（0x12ec40..0x12ec60）
 * @func 0x12ec40 0x12ec60  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ec40 push {r4, lr}
 *   @0x12ec44 mov r1, #0
 *   @0x12ec48 mov r4, r0
 *   @0x12ec4c ldr r0, [sp, #0x8]
 *   @0x12ec50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12ec54 mov r1, r4
 *   @0x12ec58 pop {r4, lr}
 *   @0x12ec5c b 0xf1770 <_Z18Code_Constant_FindPKcP6RValue>
 *
 * ══ §515/828 GET_YoYo_GetOSBrowser(CInstance*, int, RValue*)  0x156380  size 32  8 条（0x156380..0x1563a0）
 * @func 0x156380 0x1563b0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156380 mov r1, #0
 *   @0x156384 mov r0, #1
 *   @0x156388 mov r3, r1
 *   @0x15638c movt r1, #0xbff0
 *   @0x156390 str r3, [r2, #0xc]
 *   @0x156394 str r1, [r2, #0x4]
 *   @0x156398 str r3, [r2]
 *   @0x15639c bx lr
 *
 * ══ §516/828 F_YoYo_GetTimer(RValue&, CInstance*, CInstance*, int, RValue*)  0x156f90  size 32  8 条（0x156f90..0x156fb0）
 * @func 0x156f90 0x156fb0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time / __floatdidf
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156f90 push {r4, lr}
 *   @0x156f94 mov r3, #0
 *   @0x156f98 str r3, [r0, #0xc]
 *   @0x156f9c mov r4, r0
 *   @0x156fa0 bl 0x215148 <Timing_Time>
 *   @0x156fa4 bl 0x319164 <__floatdidf>
 *   @0x156fa8 stm r4, {r0, r1}
 *   @0x156fac pop {r4, pc}
 *
 * ══ §517/828 GetDeviceM()  0x15e64c  size 32  8 条（0x15e64c..0x15e66c）
 * @func 0x15e64c 0x15e67c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e64c ldr r3, [pc, #0x14]
 *   @0x15e650 ldr r3, [pc, r3]
 *   @0x15e654 ldrb r0, [r3]
 *   @0x15e658 cmp r0, #0
 *   @0x15e65c movne r0, #2
 *   @0x15e660 moveq r0, #0
 *   @0x15e664 bx lr
 *   @0x15e668 eoreq r1, r9, r4, asr r8
 *
 * ══ §518/828 F_KeyboardKeyPress(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ae8  size 32  8 条（0x160ae8..0x160b08）
 * @func 0x160ae8 0x160b18  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ae8 push {r3, lr}
 *   @0x160aec mov r1, #0
 *   @0x160af0 ldr r0, [sp, #0x8]
 *   @0x160af4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x160af8 pop {r3, lr}
 *   @0x160afc mov r1, r0
 *   @0x160b00 mov r0, #0
 *   @0x160b04 b 0x18ef50 <_Z23RegisterAndroidKeyEventii>
 *
 * ══ §519/828 F_KeyboardKeyRelease(RValue&, CInstance*, CInstance*, int, RValue*)  0x160b08  size 32  8 条（0x160b08..0x160b28）
 * @func 0x160b08 0x160b28  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160b08 push {r3, lr}
 *   @0x160b0c mov r1, #0
 *   @0x160b10 ldr r0, [sp, #0x8]
 *   @0x160b14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x160b18 pop {r3, lr}
 *   @0x160b1c mov r1, r0
 *   @0x160b20 mov r0, #1
 *   @0x160b24 b 0x18ef50 <_Z23RegisterAndroidKeyEventii>
 *
 * ══ §520/828 GR_RGBA_To_D3DColor(int, int, int, unsigned int)  0x16ca74  size 32  8 条（0x16ca74..0x16ca94）
 * @func 0x16ca74 0x16ca94  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ca74 lsl r1, r1, #8
 *   @0x16ca78 uxtb r2, r2
 *   @0x16ca7c uxtb r0, r0
 *   @0x16ca80 uxth r1, r1
 *   @0x16ca84 orr r3, r1, r3, lsl #24
 *   @0x16ca88 orr r2, r3, r2
 *   @0x16ca8c orr r0, r2, r0, lsl #16
 *   @0x16ca90 bx lr
 *
 * ══ §521/828 Graphics::ShadersSupported()  0x17df3c  size 32  8 条（0x17df3c..0x17df5c）
 * @func 0x17df3c 0x17df5c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17df3c ldr r3, [pc, #0x14]
 *   @0x17df40 ldr r3, [pc, r3]
 *   @0x17df44 ldr r0, [r3]
 *   @0x17df48 subs r3, r0, #1
 *   @0x17df4c rsbs r0, r3, #0
 *   @0x17df50 adcs r0, r0, r3
 *   @0x17df54 bx lr
 *   @0x17df58 eoreq r2, r7, r8, asr #9
 *
 * ══ §522/828 InitShaderManagerResources()  0x188144  size 32  8 条（0x188144..0x188164）
 * @func 0x188144 0x188164  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Reload_All()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188144 push {r3, lr}
 *   @0x188148 bl 0x187fac <_Z17Shader_Reload_Allv>
 *   @0x18814c ldr r3, [pc, #0xc]
 *   @0x188150 ldr r3, [pc, r3]
 *   @0x188154 ldr r0, [r3]
 *   @0x188158 pop {r3, lr}
 *   @0x18815c b 0x1880ec <_Z11Shader_SetMi>
 *   @0x188160 eoreq r8, r6, r0, asr #8
 *
 * ══ §523/828 _RefFactory<YYObjectBase*>::Destroy(YYObjectBase*)  0x199f10  size 32  8 条（0x199f10..0x199f30）
 * @func 0x199f10 0x199f30  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f10 push {r3, lr}
 *   @0x199f14 subs r3, r0, #0
 *   @0x199f18 beq 0x199f28 <_ZN11_RefFactoryIP12YYObjectBaseE7DestroyES1_+0x18>
 *   @0x199f1c ldr r3, [r3]
 *   @0x199f20 ldr r3, [r3, #0x4]
 *   @0x199f24 blx r3
 *   @0x199f28 mov r0, #0
 *   @0x199f2c pop {r3, pc}
 *
 * ══ §524/828 Room_Last()  0x1b5d20  size 32  8 条（0x1b5d20..0x1b5d40）
 * @func 0x1b5d20 0x1b5d40  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5d20 ldr r3, [pc, #0x14]
 *   @0x1b5d24 add r3, pc, r3
 *   @0x1b5d28 ldr r2, [r3, #0x10]
 *   @0x1b5d2c ldr r3, [r3, #0x14]
 *   @0x1b5d30 sub r2, r2, #1
 *   @0x1b5d34 ldr r0, [r3, r2, lsl #2]
 *   @0x1b5d38 bx lr
 *   @0x1b5d3c eorseq r12, r8, r4, lsr #17
 *
 * ══ §525/828 FINALIZE_Room_Main()  0x1b5e54  size 32  8 条（0x1b5e54..0x1b5e74）
 * @func 0x1b5e54 0x1b5e84  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Free()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e54 push {r3, lr}
 *   @0x1b5e58 bl 0x1b5044 <_Z9Room_Freev>
 *   @0x1b5e5c mov r2, #0
 *   @0x1b5e60 ldr r3, [pc, #0x8]
 *   @0x1b5e64 ldr r3, [pc, r3]
 *   @0x1b5e68 str r2, [r3]
 *   @0x1b5e6c pop {r3, pc}
 *   @0x1b5e70 .word 0x0023a9dc
 *
 * ══ §526/828 AddMultiFingerGestures(long long)  0x1d87bc  size 32  8 条（0x1d87bc..0x1d87dc）
 * @func 0x1d87bc 0x1d87dc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TestForNewPinches(long long)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d87bc push {r3, r4, r5, lr}
 *   @0x1d87c0 mov r4, r0
 *   @0x1d87c4 mov r5, r1
 *   @0x1d87c8 bl 0x1d7c70 <_Z17TestForNewPinchesx>
 *   @0x1d87cc mov r0, r4
 *   @0x1d87d0 mov r1, r5
 *   @0x1d87d4 pop {r3, r4, r5, lr}
 *   @0x1d87d8 b 0x1d81dc <_Z17TestForNewRotatesx>
 *
 * ══ §527/828 CSprite::SetCollisionChecking(bool)  0x1e3d68  size 32  8 条（0x1e3d68..0x1e3d88）
 * @func 0x1e3d68 0x1e3d88  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3d68 ldrb r2, [r0, #0x30]
 *   @0x1e3d6c cmp r2, r1
 *   @0x1e3d70 bxeq lr
 *   @0x1e3d74 ldr r2, [r0, #0x74]
 *   @0x1e3d78 strb r1, [r0, #0x30]
 *   @0x1e3d7c cmp r2, #0
 *   @0x1e3d80 bxne lr
 *   @0x1e3d84 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *
 * ══ §528/828 GV_GetWebGLEnabled(CInstance*, int, RValue*)  0x1f9afc  size 32  8 条（0x1f9afc..0x1f9b1c）
 * @func 0x1f9afc 0x1f9b1c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9afc mov r1, #0
 *   @0x1f9b00 mov r0, #1
 *   @0x1f9b04 mov r3, r1
 *   @0x1f9b08 movt r1, #0x3ff0
 *   @0x1f9b0c str r3, [r2, #0xc]
 *   @0x1f9b10 str r1, [r2, #0x4]
 *   @0x1f9b14 str r3, [r2]
 *   @0x1f9b18 bx lr
 *
 * ══ §529/828 GV_SaveDirectory(CInstance*, int, RValue*)  0x1f9d0c  size 32  8 条（0x1f9d0c..0x1f9d2c）
 * @func 0x1f9d0c 0x1f9d3c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetSavePrePend() / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9d0c push {r4, lr}
 *   @0x1f9d10 mov r4, r2
 *   @0x1f9d14 bl 0x28fd6c <_Z14GetSavePrePendv>
 *   @0x1f9d18 mov r1, r0
 *   @0x1f9d1c mov r0, r4
 *   @0x1f9d20 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9d24 mov r0, #1
 *   @0x1f9d28 pop {r4, pc}
 *
 * ══ §530/828 GV_KeyboardString(CInstance*, int, RValue*)  0x1fa1a4  size 32  8 条（0x1fa1a4..0x1fa1c4）
 * @func 0x1fa1a4 0x1fa1d4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_String_Get() / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa1a4 push {r4, lr}
 *   @0x1fa1a8 mov r4, r2
 *   @0x1fa1ac bl 0x18bd34 <_Z13IO_String_Getv>
 *   @0x1fa1b0 mov r1, r0
 *   @0x1fa1b4 mov r0, r4
 *   @0x1fa1b8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1fa1bc mov r0, #1
 *   @0x1fa1c0 pop {r4, pc}
 *
 * ══ §531/828 CDS_Queue::Tail()  0x202fc0  size 32  8 条（0x202fc0..0x202fe0）
 * @func 0x202fc0 0x202fe0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202fc0 ldr r3, [r0, #0x4]
 *   @0x202fc4 ldr r2, [r0, #0x8]
 *   @0x202fc8 cmp r2, r3
 *   @0x202fcc subne r3, r3, #-268435455
 *   @0x202fd0 ldrne r2, [r0, #0x10]
 *   @0x202fd4 addne r0, r2, r3, lsl #4
 *   @0x202fd8 moveq r0, #0
 *   @0x202fdc bx lr
 *
 * ══ §532/828 Audio_Debug(bool)  0x21d6bc  size 32  8 条（0x21d6bc..0x21d6dc）
 * @func 0x21d6bc 0x21d6dc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d6bc ldr r3, [pc, #0x14]
 *   @0x21d6c0 cmp r0, #0
 *   @0x21d6c4 ldr r3, [pc, r3]
 *   @0x21d6c8 movne r0, #16
 *   @0x21d6cc moveq r0, #0
 *   @0x21d6d0 str r0, [r3]
 *   @0x21d6d4 bx lr
 *   @0x21d6d8 andseq r0, sp, r8, ror #26
 *
 * ══ §533/828 _alutOutputStreamDestroy  0x2228fc  size 32  8 条（0x2228fc..0x22291c）
 * @func 0x2228fc 0x22291c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2228fc push {r4, lr}
 *   @0x222900 mov r4, r0
 *   @0x222904 ldr r0, [r0]
 *   @0x222908 bl 0xb655c <free@plt>
 *   @0x22290c mov r0, r4
 *   @0x222910 bl 0xb655c <free@plt>
 *   @0x222914 mov r0, #1
 *   @0x222918 pop {r4, pc}
 *
 * ══ §534/828 COggSyncThread::PauseSyncGroup()  0x225c74  size 32  8 条（0x225c74..0x225c94）
 * @func 0x225c74 0x225ca4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x851×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225c74 push {r4, lr}
 *   @0x225c78 mov r4, r0
 *   @0x225c7c bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225c80 mov r3, #1
 *   @0x225c84 mov r0, r4
 *   @0x225c88 strb r3, [r4, #0x851]
 *   @0x225c8c pop {r4, lr}
 *   @0x225c90 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §535/828 COggSyncThread::ResumeSyncGroup()  0x225c94  size 32  8 条（0x225c94..0x225cb4）
 * @func 0x225c94 0x225cb4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x852×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225c94 push {r4, lr}
 *   @0x225c98 mov r4, r0
 *   @0x225c9c bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225ca0 mov r3, #1
 *   @0x225ca4 mov r0, r4
 *   @0x225ca8 strb r3, [r4, #0x852]
 *   @0x225cac pop {r4, lr}
 *   @0x225cb0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §536/828 COggAudio::StartSyncGroup(int)  0x2261d4  size 32  8 条（0x2261d4..0x2261f4）
 * @func 0x2261d4 0x226204  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2261d4 ldr r3, [r0, #0x4]
 *   @0x2261d8 cmp r3, r1
 *   @0x2261dc bxle lr
 *   @0x2261e0 ldr r3, [r0, #0x10]
 *   @0x2261e4 ldr r0, [r3, r1, lsl #2]
 *   @0x2261e8 cmp r0, #0
 *   @0x2261ec bxeq lr
 *   @0x2261f0 b 0x225c20 <_ZN14COggSyncThread14StartSyncGroupEv>
 *
 * ══ §537/828 COggAudio::StopSyncGroup(int)  0x2261f4  size 32  8 条（0x2261f4..0x226214）
 * @func 0x2261f4 0x226224  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2261f4 ldr r3, [r0, #0x4]
 *   @0x2261f8 cmp r3, r1
 *   @0x2261fc bxle lr
 *   @0x226200 ldr r3, [r0, #0x10]
 *   @0x226204 ldr r0, [r3, r1, lsl #2]
 *   @0x226208 cmp r0, #0
 *   @0x22620c bxeq lr
 *   @0x226210 b 0x225c4c <_ZN14COggSyncThread13StopSyncGroupEv>
 *
 * ══ §538/828 COggAudio::PauseSyncGroup(int)  0x226214  size 32  8 条（0x226214..0x226234）
 * @func 0x226214 0x226244  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226214 ldr r3, [r0, #0x4]
 *   @0x226218 cmp r3, r1
 *   @0x22621c bxle lr
 *   @0x226220 ldr r3, [r0, #0x10]
 *   @0x226224 ldr r0, [r3, r1, lsl #2]
 *   @0x226228 cmp r0, #0
 *   @0x22622c bxeq lr
 *   @0x226230 b 0x225c74 <_ZN14COggSyncThread14PauseSyncGroupEv>
 *
 * ══ §539/828 COggAudio::ResumeSyncGroup(int)  0x226234  size 32  8 条（0x226234..0x226254）
 * @func 0x226234 0x226264  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226234 ldr r3, [r0, #0x4]
 *   @0x226238 cmp r3, r1
 *   @0x22623c bxle lr
 *   @0x226240 ldr r3, [r0, #0x10]
 *   @0x226244 ldr r0, [r3, r1, lsl #2]
 *   @0x226248 cmp r0, #0
 *   @0x22624c bxeq lr
 *   @0x226250 b 0x225c94 <_ZN14COggSyncThread15ResumeSyncGroupEv>
 *
 * ══ §540/828 ogg_stream_destroy  0x234334  size 32  8 条（0x234334..0x234354）
 * @func 0x234334 0x234354  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_clear / 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234334 push {r4, lr}
 *   @0x234338 subs r4, r0, #0
 *   @0x23433c beq 0x23434c <ogg_stream_destroy+0x18>
 *   @0x234340 bl 0x234150 <ogg_stream_clear>
 *   @0x234344 mov r0, r4
 *   @0x234348 bl 0xb655c <free@plt>
 *   @0x23434c mov r0, #0
 *   @0x234350 pop {r4, pc}
 *
 * ══ §541/828 ogg_sync_destroy  0x234b60  size 32  8 条（0x234b60..0x234b80）
 * @func 0x234b60 0x234b80  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_clear / 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234b60 push {r4, lr}
 *   @0x234b64 subs r4, r0, #0
 *   @0x234b68 beq 0x234b78 <ogg_sync_destroy+0x18>
 *   @0x234b6c bl 0x234b2c <ogg_sync_clear>
 *   @0x234b70 mov r0, r4
 *   @0x234b74 bl 0xb655c <free@plt>
 *   @0x234b78 mov r0, #0
 *   @0x234b7c pop {r4, pc}
 *
 * ══ §542/828 IniFile::IniFile()  0x235488  size 32  8 条（0x235488..0x2354a8）
 * @func 0x235488 0x2354a8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235488 mov r2, #0
 *   @0x23548c str r2, [r0]
 *   @0x235490 str r2, [r0, #0x4]
 *   @0x235494 str r2, [r0, #0x8]
 *   @0x235498 str r2, [r0, #0x10]
 *   @0x23549c str r2, [r0, #0x14]
 *   @0x2354a0 strb r2, [r0, #0x18]
 *   @0x2354a4 bx lr
 *
 * ══ §543/828 CPhysicsWorld::SetParticleGroupFlags(int, unsigned int)  0x23a210  size 32  8 条（0x23a210..0x23a230）
 * @func 0x23a210 0x23a230  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a210 push {r4, lr}
 *   @0x23a214 mov r4, r2
 *   @0x23a218 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a21c cmp r0, #0
 *   @0x23a220 popeq {r4, pc}
 *   @0x23a224 mov r1, r4
 *   @0x23a228 pop {r4, lr}
 *   @0x23a22c b 0x2d460c <_ZN15b2ParticleGroup13SetGroupFlagsEi>
 *
 * ══ §544/828 CPhysicsWorld::GetParticleGroupMass(int)  0x23a648  size 32  8 条（0x23a648..0x23a668）
 * @func 0x23a648 0x23a678  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a648 push {r3, lr}
 *   @0x23a64c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a650 cmp r0, #0
 *   @0x23a654 beq 0x23a660 <_ZN13CPhysicsWorld20GetParticleGroupMassEi+0x18>
 *   @0x23a658 pop {r3, lr}
 *   @0x23a65c b 0x2d4814 <_ZNK15b2ParticleGroup7GetMassEv>
 *   @0x23a660 mov r0, #0
 *   @0x23a664 pop {r3, pc}
 *
 * ══ §545/828 CPhysicsWorld::GetParticleGroupInertia(int)  0x23a668  size 32  8 条（0x23a668..0x23a688）
 * @func 0x23a668 0x23a688  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a668 push {r3, lr}
 *   @0x23a66c bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a670 cmp r0, #0
 *   @0x23a674 beq 0x23a680 <_ZN13CPhysicsWorld23GetParticleGroupInertiaEi+0x18>
 *   @0x23a678 pop {r3, lr}
 *   @0x23a67c b 0x2d4828 <_ZNK15b2ParticleGroup10GetInertiaEv>
 *   @0x23a680 mov r0, #0
 *   @0x23a684 pop {r3, pc}
 *
 * ══ §546/828 F_JSGlobalScope(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c684  size 32  8 条（0x23c684..0x23c6a4）
 * @func 0x23c684 0x23c6b4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c684 ldr r3, [pc, #0x14]
 *   @0x23c688 mov r2, #6
 *   @0x23c68c str r2, [r0, #0xc]
 *   @0x23c690 ldr r3, [pc, r3]
 *   @0x23c694 ldr r3, [r3]
 *   @0x23c698 str r3, [r0]
 *   @0x23c69c bx lr
 *   @0x23c6a0 andseq r1, r11, r8, lsl r6
 *
 * ══ §547/828 translate(EJSRetVal)  0x242ebc  size 32  8 条（0x242ebc..0x242edc）
 * @func 0x242ebc 0x242edc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242ebc cmp r0, #1
 *   @0x242ec0 beq 0x242ed4 <_Z9translate9EJSRetVal+0x18>
 *   @0x242ec4 cmp r0, #2
 *   @0x242ec8 mvneq r0, #3
 *   @0x242ecc movne r0, #0
 *   @0x242ed0 bx lr
 *   @0x242ed4 mvn r0, #4
 *   @0x242ed8 bx lr
 *
 * ══ §548/828 Day(double)  0x2449d8  size 32  8 条（0x2449d8..0x2449f8）
 * @func 0x2449d8 0x2449f8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2449d8 vmov d6, r0, r1
 *   @0x2449dc vldr d7, [pc, #12]
 *   @0x2449e0 vdiv.f64 d6, d6, d7
 *   @0x2449e4 vmov r0, r1, d6
 *   @0x2449e8 b 0xb6598 <floor@plt>
 *   @0x2449ec nop
 *   @0x2449f0 andeq r0, r0, r0
 *   @0x2449f4 orrsmi r9, r4, r0, ror r9
 *
 * ══ §549/828 _spBaseTimeline_dispose  0x281734  size 32  8 条（0x281734..0x281754）
 * @func 0x281734 0x281754  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spCurveTimeline_deinit / _free
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281734 push {r4, lr}
 *   @0x281738 mov r4, r0
 *   @0x28173c bl 0x28171c <_spCurveTimeline_deinit>
 *   @0x281740 ldr r0, [r4, #0x10]
 *   @0x281744 bl 0x285c80 <_free>
 *   @0x281748 mov r0, r4
 *   @0x28174c pop {r4, lr}
 *   @0x281750 b 0x285c80 <_free>
 *
 * ══ §550/828 _spPathAttachment_dispose  0x2876d4  size 32  8 条（0x2876d4..0x2876f4）
 * @func 0x2876d4 0x2876f4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spVertexAttachment_deinit / _free
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2876d4 push {r4, lr}
 *   @0x2876d8 mov r4, r0
 *   @0x2876dc bl 0x28f62c <_spVertexAttachment_deinit>
 *   @0x2876e0 ldr r0, [r4, #0x28]
 *   @0x2876e4 bl 0x285c80 <_free>
 *   @0x2876e8 mov r0, r4
 *   @0x2876ec pop {r4, lr}
 *   @0x2876f0 b 0x285c80 <_free>
 *
 * ══ §551/828 _spRegionAttachment_dispose  0x288f58  size 32  8 条（0x288f58..0x288f78）
 * @func 0x288f58 0x288f78  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAttachment_deinit / _free
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288f58 push {r4, lr}
 *   @0x288f5c mov r4, r0
 *   @0x288f60 bl 0x284c84 <_spAttachment_deinit>
 *   @0x288f64 ldr r0, [r4, #0x10]
 *   @0x288f68 bl 0x285c80 <_free>
 *   @0x288f6c mov r0, r4
 *   @0x288f70 pop {r4, lr}
 *   @0x288f74 b 0x285c80 <_free>
 *
 * ══ §552/828 _spVertexAttachment_deinit  0x28f62c  size 32  8 条（0x28f62c..0x28f64c）
 * @func 0x28f62c 0x28f64c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAttachment_deinit / _free
 * 字段偏移 top8: 0x14×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f62c push {r4, lr}
 *   @0x28f630 mov r4, r0
 *   @0x28f634 bl 0x284c84 <_spAttachment_deinit>
 *   @0x28f638 ldr r0, [r4, #0x14]
 *   @0x28f63c bl 0x285c80 <_free>
 *   @0x28f640 ldr r0, [r4, #0x1c]
 *   @0x28f644 pop {r4, lr}
 *   @0x28f648 b 0x285c80 <_free>
 *
 * ══ §553/828 textureReadFn(png_struct_def*, unsigned char*, unsigned int)  0x28fa38  size 32  8 条（0x28fa38..0x28fa58）
 * @func 0x28fa38 0x28fa58  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_get_io_ptr
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fa38 push {r3, r4, r5, lr}
 *   @0x28fa3c mov r5, r1
 *   @0x28fa40 mov r4, r2
 *   @0x28fa44 blx 0x2a5f20 <png_get_io_ptr>
 *   @0x28fa48 mov r1, r5
 *   @0x28fa4c mov r2, r4
 *   @0x28fa50 pop {r3, r4, r5, lr}
 *   @0x28fa54 b 0x31ba7c <__udivdi3+0x3e4>
 *
 * ══ §554/828 Java_com_yoyogames_runner_RunnerJNILib_KeyEvent  0x292640  size 32  8 条（0x292640..0x292660）
 * @func 0x292640 0x292660  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292640 push {r3, r4, r5, lr}
 *   @0x292644 mov r4, r2
 *   @0x292648 mov r5, r3
 *   @0x29264c bl 0x290614 <setJNIEnv>
 *   @0x292650 mov r0, r4
 *   @0x292654 mov r1, r5
 *   @0x292658 pop {r3, r4, r5, lr}
 *   @0x29265c b 0x18ef50 <_Z23RegisterAndroidKeyEventii>
 *
 * ══ §555/828 Java_com_yoyogames_runner_RunnerJNILib_dsListAddInt  0x292c38  size 32  8 条（0x292c38..0x292c58）
 * @func 0x292c38 0x292c58  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292c38 push {r3, r4, r5, lr}
 *   @0x292c3c mov r4, r2
 *   @0x292c40 mov r5, r3
 *   @0x292c44 bl 0x290614 <setJNIEnv>
 *   @0x292c48 mov r0, r4
 *   @0x292c4c mov r1, r5
 *   @0x292c50 pop {r3, r4, r5, lr}
 *   @0x292c54 b 0x101c18 <dsListAddInt>
 *
 * ══ §556/828 Java_com_yoyogames_runner_RunnerJNILib_CreateAsynEventWithDSMap  0x293d40  size 32  8 条（0x293d40..0x293d60）
 * @func 0x293d40 0x293d60  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293d40 push {r3, r4, r5, lr}
 *   @0x293d44 mov r4, r2
 *   @0x293d48 mov r5, r3
 *   @0x293d4c bl 0x290614 <setJNIEnv>
 *   @0x293d50 mov r0, r4
 *   @0x293d54 mov r1, r5
 *   @0x293d58 pop {r3, r4, r5, lr}
 *   @0x293d5c b 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *
 * ══ §557/828 Java_com_yoyogames_runner_RunnerJNILib_initGLFuncs  0x294c18  size 32  8 条（0x294c18..0x294c38）
 * @func 0x294c18 0x294c38  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ImportGLLibrary()
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294c18 push {r4, lr}
 *   @0x294c1c ldr r4, [pc, #0x10]
 *   @0x294c20 ldr r4, [pc, r4]
 *   @0x294c24 str r2, [r4]
 *   @0x294c28 bl 0x28fce4 <_Z15ImportGLLibraryv>
 *   @0x294c2c ldr r0, [r4]
 *   @0x294c30 pop {r4, pc}
 *   @0x294c34 andseq r11, r5, r8, ror #15
 *
 * ══ §558/828 QuitNetworkingFunctions()  0x2998b8  size 32  8 条（0x2998b8..0x2998d8）
 * @func 0x2998b8 0x2998d8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeSocket(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2998b8 push {r4, lr}
 *   @0x2998bc mov r4, #0
 *   @0x2998c0 mov r0, r4
 *   @0x2998c4 add r4, r4, #1
 *   @0x2998c8 bl 0x299244 <_Z10FreeSocketi>
 *   @0x2998cc cmp r4, #64
 *   @0x2998d0 bne 0x2998c0 <_Z23QuitNetworkingFunctionsv+0x8>
 *   @0x2998d4 pop {r4, pc}
 *
 * ══ §559/828 EndOfGame()  0x2a16bc  size 32  8 条（0x2a16bc..0x2a16dc）
 * @func 0x2a16bc 0x2a16dc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Quit() / SND_End()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a16bc push {r3, lr}
 *   @0x2a16c0 bl 0x18b8a0 <_Z7IO_Quitv>
 *   @0x2a16c4 bl 0x21e9d0 <_Z7SND_Endv>
 *   @0x2a16c8 ldr r0, [pc, #0x8]
 *   @0x2a16cc pop {r3, lr}
 *   @0x2a16d0 ldr r0, [pc, r0]
 *   @0x2a16d4 b 0x2a1470 <_ZN9CProfiler11ProfileDumpEv>
 *   @0x2a16d8 mulseq r4, r12, r4
 *
 * ══ §560/828 anon_2a2e6c  0x2a2e6c  size 32  8 条（0x2a2e6c..0x2a2e8c）
 * @func 0x2a2e6c 0x2a2e8c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2e6c ldr r1, [pc, #0x18]
 *   @0x2a2e70 mov r0, #0
 *   @0x2a2e74 mov r2, #0
 *   @0x2a2e78 mov r3, #0
 *   @0x2a2e7c add r1, pc, r1
 *   @0x2a2e80 str r0, [r1]
 *   @0x2a2e84 strd r2, r3, [r1, #8]
 *   @0x2a2e88 bx lr
 *
 * ══ §561/828 _zip_dirent_finalize(zip_dirent*)  0x2a3bd6  size 32  8 条（0x2a3bd6..0x2a3bf6）
 * @func 0x2a3bd6 0x2a3bf6  size 32  8 条
 * 部分覆盖: 本节 8/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×3
 * 字段偏移 top8: 0x20×2 / 0x18×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3bd6 push {r3, r4, r5, lr}
 *   @0x2a3bda ldr r0, [r0, #0x18]
 *   @0x2a3bde blx 0xb655c <free@plt>
 *   @0x2a3be2 ldr r0, [r4, #0x20]
 *   @0x2a3be6 blx 0xb655c <free@plt>
 *   @0x2a3bea str r5, [r4, #0x20]
 *   @0x2a3bee blx 0xb655c <free@plt>
 *   @0x2a3bf2 str r5, [r4, #0x28]
 *
 * ══ §562/828 _zip_error_get(zip_error*, int*, int*)  0x2a432e  size 32  8 条（0x2a432e..0x2a434e）
 * @func 0x2a432e 0x2a434e  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: zip_error_get_sys_type
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a432e push {r3, r4, r5, lr}
 *   @0x2a4332 mov r5, r2
 *   @0x2a4336 ldr r3, [r0]
 *   @0x2a433a cbz r5, 0x2a434c <_Z14_zip_error_getP9zip_errorPiS1_+0x1e>
 *   @0x2a433e bl 0x2a4360 <zip_error_get_sys_type>
 *   @0x2a4342 cbz r0, 0x2a434a <_Z14_zip_error_getP9zip_errorPiS1_+0x1c>
 *   @0x2a4346 str r3, [r5]
 *   @0x2a434a str r0, [r5]
 *
 * ══ §563/828 png_get_x_pixels_per_meter  0x2a65e2  size 32  8 条（0x2a65e2..0x2a6602）
 * @func 0x2a65e2 0x2a6612  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65e2 cbz r0, 0x2a6600 <png_get_x_pixels_per_meter+0x1e>
 *   @0x2a65e6 ldr r0, [r1, #0x8]
 *   @0x2a65ea andle r0, r8, r0, lsl #1
 *   @0x2a65ee ldrb.w r3, [r1, #0x78]
 *   @0x2a65f2 cmp r3, #0x1
 *   @0x2a65f6 ldr r0, [r1, #0x70]
 *   @0x2a65fa mov r0, r1
 *   @0x2a65fe movs r0, #0x0
 *
 * ══ §564/828 png_get_y_pixels_per_meter  0x2a6602  size 32  8 条（0x2a6602..0x2a6622）
 * @func 0x2a6602 0x2a6632  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6602 cbz r0, 0x2a6620 <png_get_y_pixels_per_meter+0x1e>
 *   @0x2a6606 ldr r0, [r1, #0x8]
 *   @0x2a660a andle r0, r8, r0, lsl #1
 *   @0x2a660e ldrb.w r3, [r1, #0x78]
 *   @0x2a6612 cmp r3, #0x1
 *   @0x2a6616 ldr r0, [r1, #0x74]
 *   @0x2a661a mov r0, r1
 *   @0x2a661e movs r0, #0x0
 *
 * ══ §565/828 png_get_x_offset_microns  0x2a6680  size 32  8 条（0x2a6680..0x2a66a0）
 * @func 0x2a6680 0x2a66b0  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6680 cbz r0, 0x2a669e <png_get_x_offset_microns+0x1e>
 *   @0x2a6684 ldr r0, [r1, #0x8]
 *   @0x2a6688 andle r7, r8, r0, lsl #1
 *   @0x2a668c ldrb.w r3, [r1, #0x6c]
 *   @0x2a6690 cmp r3, #0x1
 *   @0x2a6694 ldr r0, [r1, #0x64]
 *   @0x2a6698 mov r0, r1
 *   @0x2a669c movs r0, #0x0
 *
 * ══ §566/828 png_get_y_offset_microns  0x2a66a0  size 32  8 条（0x2a66a0..0x2a66c0）
 * @func 0x2a66a0 0x2a66d0  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a66a0 cbz r0, 0x2a66be <png_get_y_offset_microns+0x1e>
 *   @0x2a66a4 ldr r0, [r1, #0x8]
 *   @0x2a66a8 andle r7, r8, r0, lsl #1
 *   @0x2a66ac ldrb.w r3, [r1, #0x6c]
 *   @0x2a66b0 cmp r3, #0x1
 *   @0x2a66b4 ldr r0, [r1, #0x68]
 *   @0x2a66b8 mov r0, r1
 *   @0x2a66bc movs r0, #0x0
 *
 * ══ §567/828 png_get_gAMA_fixed  0x2a687e  size 32  8 条（0x2a687e..0x2a689e）
 * @func 0x2a687e 0x2a68ae  size 48  12 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a687e cbz r0, 0x2a689c <png_get_gAMA_fixed+0x1e>
 *   @0x2a6882 ldr r0, [r1, #0x8]
 *   @0x2a6886 andle r0, r8, r1
 *   @0x2a688a cbz r2, 0x2a689a <png_get_gAMA_fixed+0x1c>
 *   @0x2a688e strdhs r3, r4, [r1], -r12
 *   @0x2a6892 str r3, [r2]
 *   @0x2a6896 mov r0, r1
 *   @0x2a689a mov r0, r2
 *
 * ══ §568/828 png_get_tIME  0x2a6b36  size 32  8 条（0x2a6b36..0x2a6b56）
 * @func 0x2a6b36 0x2a6b56  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6b36 cbz r0, 0x2a6b54 <png_get_tIME+0x1e>
 *   @0x2a6b3a ldr r0, [r1, #0x8]
 *   @0x2a6b3e andle r7, r8, r0
 *   @0x2a6b42 cbz r2, 0x2a6b52 <png_get_tIME+0x1c>
 *   @0x2a6b46 mov.w r0, #0x200
 *   @0x2a6b4a str r1, [r2]
 *   @0x2a6b4e mov r0, r1
 *   @0x2a6b52 mov r0, r2
 *
 * ══ §569/828 png_set_expand  0x2a8790  size 32  8 条（0x2a8790..0x2a87b0）
 * @func 0x2a8790 0x2a87c0  size 48  12 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8790 cbz r0, 0x2a87ae <png_set_expand+0x1e>
 *   @0x2a8794 .word 0xf0433134
 *   @0x2a8798 vst2.8 {d23, d24, d25, d26}, [r3], r0
 *   @0x2a879c .word 0xf8c05380
 *   @0x2a87a0 .word 0xf8d03134
 *   @0x2a87a4 .word 0xf0233130
 *   @0x2a87a8 .word 0xf8c00340
 *   @0x2a87ac .word 0x47703130
 *
 * ══ §570/828 png_set_palette_to_rgb  0x2a87b0  size 32  8 条（0x2a87b0..0x2a87d0）
 * @func 0x2a87b0 0x2a87e0  size 48  12 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a87b0 cbz r0, 0x2a87ce <png_set_palette_to_rgb+0x1e>
 *   @0x2a87b4 .word 0xf0433134
 *   @0x2a87b8 vst2.8 {d23, d24, d25, d26}, [r3], r0
 *   @0x2a87bc .word 0xf8c05380
 *   @0x2a87c0 .word 0xf8d03134
 *   @0x2a87c4 .word 0xf0233130
 *   @0x2a87c8 .word 0xf8c00340
 *   @0x2a87cc .word 0x47703130
 *
 * ══ §571/828 png_set_bKGD  0x2ae6b4  size 32  8 条（0x2ae6b4..0x2ae6d4）
 * @func 0x2ae6b4 0x2ae6d4  size 32  8 条
 * 部分覆盖: 本节 8/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae6b4 cbz r0, 0x2ae6d2 <png_set_bKGD+0x1e>
 *   @0x2ae6b8 ldr r3, [r2]
 *   @0x2ae6bc ldmdavs r3, {r1, r3, r4, r6, r12, sp} ^
 *   @0x2ae6c0 str.w r3, [r1, #0x5e]
 *   @0x2ae6c4 ldrh r3, [r2, #0x8]
 *   @0x2ae6c8 stmvs r11, {r1, r5, r6, r12, sp}
 *   @0x2ae6cc orr r3, r3, #0x20
 *   @0x2ae6d0 str r3, [r1, #0x8]
 *
 * ══ §572/828 png_set_text  0x2af0e0  size 32  8 条（0x2af0e0..0x2af100）
 * @func 0x2af0e0 0x2af100  size 32  8 条
 * 部分覆盖: 本节 8/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_text_2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af0e0 push {r4, lr}
 *   @0x2af0e4 bl 0x2aeef8 <png_set_text_2>
 *   @0x2af0e8 cbz r0, 0x2af0f8 <png_set_text+0x18>
 *   @0x2af0ec mov r0, r4
 *   @0x2af0f0 ldrbtmi r4, [r9], #-16
 *   @0x2af0f4 b.w 0x2a642c <png_error>
 *   @0x2af0f8 pop {r4, pc}
 *   @0x2af0fc adc.w r0, r10, sp
 *
 * ══ §573/828 png_convert_from_struct_tm  0x2b0148  size 32  8 条（0x2b0148..0x2b0168）
 * @func 0x2b0148 0x2b0178  size 48  12 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x10×1 / 0x2×1 / 0x3×1 / 0x4×1 / 0x5×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0148 ldr r3, [r1, #0x14]
 *   @0x2b014c andhi r7, r3, r12, ror #6
 *   @0x2b0150 ldr r3, [r1, #0x10]
 *   @0x2b0154 strb r3, [r0, #0x2]
 *   @0x2b0158 strb r3, [r0, #0x3]
 *   @0x2b015c strb r3, [r0, #0x4]
 *   @0x2b0160 strb r3, [r0, #0x5]
 *   @0x2b0164 strb r3, [r0, #0x6]
 *
 * ══ §574/828 png_write_rows  0x2b04f0  size 32  8 条（0x2b04f0..0x2b0510）
 * @func 0x2b04f0 0x2b0510  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b04f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2b04f4 mov r7, r2
 *   @0x2b04f8 cbz r0, 0x2b050e <png_write_rows+0x1e>
 *   @0x2b04fc cmp r4, r7
 *   @0x2b0500 ldr.w r1, [r6, r4, lsl #2]
 *   @0x2b0504 mov r0, r5
 *   @0x2b0508 strlo pc, [r1], #-3895
 *   @0x2b050c b 0x2b04fc <png_write_rows+0xc>
 *
 * ══ §575/828 GifFreeMapObject(ColorMapObject*)  0x2c2c48  size 32  8 条（0x2c2c48..0x2c2c68）
 * @func 0x2c2c48 0x2c2c68  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2c48 push {r4, lr}
 *   @0x2c2c4c subs r4, r0, #0
 *   @0x2c2c50 popeq {r4, pc}
 *   @0x2c2c54 ldr r0, [r4, #0xc]
 *   @0x2c2c58 bl 0xb655c <free@plt>
 *   @0x2c2c5c mov r0, r4
 *   @0x2c2c60 pop {r4, lr}
 *   @0x2c2c64 b 0xb655c <free@plt>
 *
 * ══ §576/828 b2World::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)  0x2cb528  size 32  8 条（0x2cb528..0x2cb548）
 * @func 0x2cb528 0x2cb548  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb528 movw r3, #0x91d4
 *   @0x2cb52c movt r3, #0x1
 *   @0x2cb530 ldr r3, [r0, r3]
 *   @0x2cb534 tst r3, #2
 *   @0x2cb538 bxne lr
 *   @0x2cb53c add r0, r0, #102400
 *   @0x2cb540 add r0, r0, #628
 *   @0x2cb544 b 0x2db6a0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_>
 *
 * ══ §577/828 b2FrictionJoint::GetReactionForce(float) const  0x2cd3a8  size 32  8 条（0x2cd3a8..0x2cd3c8）
 * @func 0x2cd3a8 0x2cd3c8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd3a8 vmov s15, r2
 *   @0x2cd3ac vldr s14, [r1, #88]
 *   @0x2cd3b0 vldr s13, [r1, #84]
 *   @0x2cd3b4 vmul.f32 s14, s15, s14
 *   @0x2cd3b8 vmul.f32 s15, s15, s13
 *   @0x2cd3bc vstr s14, [r0, #4]
 *   @0x2cd3c0 vstr s15, [r0]
 *   @0x2cd3c4 bx lr
 *
 * ══ §578/828 b2MotorJoint::GetReactionForce(float) const  0x2cdffc  size 32  8 条（0x2cdffc..0x2ce01c）
 * @func 0x2cdffc 0x2ce01c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdffc vmov s15, r2
 *   @0x2ce000 vldr s14, [r1, #84]
 *   @0x2ce004 vldr s13, [r1, #80]
 *   @0x2ce008 vmul.f32 s14, s15, s14
 *   @0x2ce00c vmul.f32 s15, s15, s13
 *   @0x2ce010 vstr s14, [r0, #4]
 *   @0x2ce014 vstr s15, [r0]
 *   @0x2ce018 bx lr
 *
 * ══ §579/828 b2MouseJoint::GetReactionForce(float) const  0x2ce9a8  size 32  8 条（0x2ce9a8..0x2ce9c8）
 * @func 0x2ce9a8 0x2ce9c8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce9a8 vmov s15, r2
 *   @0x2ce9ac vldr s14, [r1, #100]
 *   @0x2ce9b0 vldr s13, [r1, #96]
 *   @0x2ce9b4 vmul.f32 s14, s15, s14
 *   @0x2ce9b8 vmul.f32 s15, s15, s13
 *   @0x2ce9bc vstr s14, [r0, #4]
 *   @0x2ce9c0 vstr s15, [r0]
 *   @0x2ce9c4 bx lr
 *
 * ══ §580/828 b2RevoluteJoint::GetReactionForce(float) const  0x2d130c  size 32  8 条（0x2d130c..0x2d132c）
 * @func 0x2d130c 0x2d132c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d130c vmov s15, r2
 *   @0x2d1310 vldr s14, [r1, #88]
 *   @0x2d1314 vldr s13, [r1, #84]
 *   @0x2d1318 vmul.f32 s14, s15, s14
 *   @0x2d131c vmul.f32 s15, s13, s15
 *   @0x2d1320 vstr s14, [r0, #4]
 *   @0x2d1324 vstr s15, [r0]
 *   @0x2d1328 bx lr
 *
 * ══ §581/828 b2WeldJoint::GetReactionForce(float) const  0x2d2e60  size 32  8 条（0x2d2e60..0x2d2e80）
 * @func 0x2d2e60 0x2d2e80  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2e60 vmov s15, r2
 *   @0x2d2e64 vldr s14, [r1, #108]
 *   @0x2d2e68 vldr s13, [r1, #104]
 *   @0x2d2e6c vmul.f32 s14, s15, s14
 *   @0x2d2e70 vmul.f32 s15, s13, s15
 *   @0x2d2e74 vstr s14, [r0, #4]
 *   @0x2d2e78 vstr s15, [r0]
 *   @0x2d2e7c bx lr
 *
 * ══ §582/828 b2DynamicTree::DestroyProxy(int)  0x2df640  size 32  8 条（0x2df640..0x2df660）
 * @func 0x2df640 0x2df660  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::RemoveLeaf(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df640 push {r3, r4, r5, lr}
 *   @0x2df644 mov r5, r0
 *   @0x2df648 mov r4, r1
 *   @0x2df64c bl 0x2df4e8 <_ZN13b2DynamicTree10RemoveLeafEi>
 *   @0x2df650 mov r0, r5
 *   @0x2df654 mov r1, r4
 *   @0x2df658 pop {r3, r4, r5, lr}
 *   @0x2df65c b 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi>
 *
 * ══ §583/828 b2DynamicTree::GetHeight() const  0x2df778  size 32  8 条（0x2df778..0x2df798）
 * @func 0x2df778 0x2df798  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df778 ldr r3, [r0]
 *   @0x2df77c cmn r3, #1
 *   @0x2df780 addne r3, r3, r3, lsl #3
 *   @0x2df784 ldrne r2, [r0, #0x4]
 *   @0x2df788 addne r3, r2, r3, lsl #2
 *   @0x2df78c ldrne r0, [r3, #0x20]
 *   @0x2df790 moveq r0, #0
 *   @0x2df794 bx lr
 *
 * ══ §584/828 b2DynamicTree::Validate() const  0x2df960  size 32  8 条（0x2df960..0x2df980）
 * @func 0x2df960 0x2df980  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::ValidateStructure(int) const
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df960 push {r4, lr}
 *   @0x2df964 mov r4, r0
 *   @0x2df968 ldr r1, [r0]
 *   @0x2df96c bl 0x2df8a0 <_ZNK13b2DynamicTree17ValidateStructureEi>
 *   @0x2df970 mov r0, r4
 *   @0x2df974 ldr r1, [r4]
 *   @0x2df978 pop {r4, lr}
 *   @0x2df97c b 0x2df900 <_ZNK13b2DynamicTree15ValidateMetricsEi>
 *
 * ══ §585/828 FT_GlyphLoader_Rewind  0x2e52bc  size 32  8 条（0x2e52bc..0x2e52dc）
 * @func 0x2e52bc 0x2e52ec  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x16×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e52bc push {r4, r5, lr}
 *   @0x2e52c0 movwhs r0, #0x514
 *   @0x2e52c4 add.w r4, r0, #0x38
 *   @0x2e52c8 strh r3, [r0, #0x16]
 *   @0x2e52cc str r3, [r0, #0x30]
 *   @0x2e52d0 stm r4!, {r0, r1, r2, r3}
 *   @0x2e52d4 stm r4!, {r0, r1, r2, r3}
 *   @0x2e52d8 str r3, [r4]
 *
 * ══ §586/828 FT_Face_GetVariantsOfChar  0x2e5dde  size 32  8 条（0x2e5dde..0x2e5dfe）
 * @func 0x2e5dde 0x2e5e0e  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e5d38
 * 字段偏移 top8: 0xc×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5dde push {r3, r4, r5, lr}
 *   @0x2e5de2 mov r5, r0
 *   @0x2e5de6 movs r0, #0x0
 *   @0x2e5dea bl 0x2e5d38 <FT_Set_Charmap+0x3c>
 *   @0x2e5dee cmp r0, #0x0
 *   @0x2e5df2 ldr r3, [r0, #0xc]
 *   @0x2e5df6 ldr r1, [r5, #0x64]
 *   @0x2e5dfa blx r3
 *
 * ══ §587/828 FT_Face_GetCharsOfVariant  0x2e5dfe  size 32  8 条（0x2e5dfe..0x2e5e1e）
 * @func 0x2e5dfe 0x2e5e1e  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e5d38
 * 字段偏移 top8: 0xc×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5dfe push {r3, r4, r5, lr}
 *   @0x2e5e02 mov r5, r0
 *   @0x2e5e06 movs r0, #0x0
 *   @0x2e5e0a bl 0x2e5d38 <FT_Set_Charmap+0x3c>
 *   @0x2e5e0e cmp r0, #0x0
 *   @0x2e5e12 ldr r3, [r0, #0xc]
 *   @0x2e5e16 ldr r1, [r5, #0x64]
 *   @0x2e5e1a blx r3
 *
 * ══ §588/828 FT_Stream_GetUShort  0x2e69f2  size 32  8 条（0x2e69f2..0x2e6a12）
 * @func 0x2e69f2 0x2e6a22  size 48  12 条
 * 部分覆盖: 本节 9/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x-1×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e69f2 mov r2, r0
 *   @0x2e69f6 ldr r1, [r2, #0x24]
 *   @0x2e69fa cmp r1, r0
 *   @0x2e69fe ldrb r0, [r3]
 *   @0x2e6a02 ldrb r1, [r3, #-1]
 *   @0x2e6a06 orr.w r0, r1, r0, lsl #8
 *   @0x2e6a0a b 0x2e6a0e <FT_Stream_GetUShort+0x1c>
 *   @0x2e6a0e str r3, [r2, #0x20]
 *
 * ══ §589/828 FT_Stream_GetUShortLE  0x2e6a12  size 32  8 条（0x2e6a12..0x2e6a32）
 * @func 0x2e6a12 0x2e6a42  size 48  12 条
 * 部分覆盖: 本节 9/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x1×1 / 0x-2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6a12 mov r2, r0
 *   @0x2e6a16 ldr r1, [r2, #0x24]
 *   @0x2e6a1a cmp r1, r0
 *   @0x2e6a1e ldrb r0, [r3, #0x1]
 *   @0x2e6a22 ldrb r1, [r3, #-2]
 *   @0x2e6a26 orr.w r0, r1, r0, lsl #8
 *   @0x2e6a2a b 0x2e6a2e <FT_Stream_GetUShortLE+0x1c>
 *   @0x2e6a2e str r3, [r2, #0x20]
 *
 * ══ §590/828 FT_Atan2  0x2e6f40  size 32  8 条（0x2e6f40..0x2e6f60）
 * @func 0x2e6f40 0x2e6f70  size 48  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x2d0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6f40 push {r0, r1, r4, lr}
 *   @0x2e6f44 cbz r1, 0x2e6f5a <FT_Atan2+0x1a>
 *   @0x2e6f48 strbtmi r0, [r8], -r3
 *   @0x2e6f4c bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8>
 *   @0x2e6f50 mov r0, sp
 *   @0x2e6f54 stmdals r1, {r0, r4, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e6f58 b 0x2e6f5c <FT_Atan2+0x1c>
 *   @0x2e6f5c add sp, #0x8
 *
 * ══ §591/828 FT_Angle_Diff  0x2e70e0  size 32  8 条（0x2e70e0..0x2e7100）
 * @func 0x2e70e0 0x2e7110  size 48  12 条
 * 部分覆盖: 本节 9/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e70e0 ldr r3, [pc, #0x18]
 *   @0x2e70e4 cmp r0, r3
 *   @0x2e70e8 add.w r0, r0, #0x1680000
 *   @0x2e70ec b 0x2e70e4 <FT_Angle_Diff+0x4>
 *   @0x2e70f0 stcle p15, c0, [r2, #-208]
 *   @0x2e70f4 sub.w r0, r0, #0x1680000
 *   @0x2e70f8 b 0x2e70ee <FT_Angle_Diff+0xe>
 *   @0x2e70fc movs r1, r0
 *
 * ══ §592/828 FT_Attach_File  0x2e7502  size 32  8 条（0x2e7502..0x2e7522）
 * @func 0x2e7502 0x2e7522  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7502 push {lr}
 *   @0x2e7506 cbz r1, 0x2e751a <FT_Attach_File+0x18>
 *   @0x2e750a mov r1, sp
 *   @0x2e750e str r3, [sp, #0x10]
 *   @0x2e7512 str r3, [sp]
 *   @0x2e7516 .word 0xe000ffd2
 *   @0x2e751a movs r0, #0x6
 *   @0x2e751e ldr pc, [sp], #4
 *
 * ══ §593/828 FT_List_Iterate  0x2e8b04  size 32  8 条（0x2e8b04..0x2e8b24）
 * @func 0x2e8b04 0x2e8b24  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8b04 push {r4, r5, r6, lr}
 *   @0x2e8b08 mov r6, r2
 *   @0x2e8b0c cbz r1, 0x2e8b20 <FT_List_Iterate+0x1c>
 *   @0x2e8b10 cbz r0, 0x2e8b1e <FT_List_Iterate+0x1a>
 *   @0x2e8b14 ldr r5, [r0, #0x4]
 *   @0x2e8b18 cbnz r0, 0x2e8b22 <FT_List_Iterate+0x1e>
 *   @0x2e8b1c b 0x2e8b10 <FT_List_Iterate+0xc>
 *   @0x2e8b20 movs r0, #0x6
 *
 * ══ §594/828 FT_Add_Default_Modules  0x2e9a20  size 32  8 条（0x2e9a20..0x2e9a40）
 * @func 0x2e9a20 0x2e9a40  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x1d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9a20 push {r3, r4, r5, lr}
 *   @0x2e9a24 ldr r4, [pc, #0x14]
 *   @0x2e9a28 subs r4, #0x4
 *   @0x2e9a2c tstlt r9, r4, lsl #30
 *   @0x2e9a30 mov r0, r5
 *   @0x2e9a34 ldrb pc, [r8, sp, ror #29]!
 *   @0x2e9a38 pop {r3, r4, r5, pc}
 *   @0x2e9a3c cmp r5, #0x9e
 *
 * ══ §595/828 af_shaper_get_elem  0x30a792  size 32  8 条（0x30a792..0x30a7b2）
 * @func 0x30a792 0x30a7b2  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30a792 push {r3, r4, r5, lr}
 *   @0x30a796 ldr r4, [sp, #0x10]
 *   @0x30a79a ldr r0, [r2]
 *   @0x30a79e mov r1, r5
 *   @0x30a7a2 .word 0xf7dd0203
 *   @0x30a7a6 .word 0xb10cf8d4
 *   @0x30a7aa movs r3, #0x0
 *   @0x30a7ae mov r0, r5
 *
 * ══ §596/828 anon_316f90  0x316f90  size 32  8 条（0x316f90..0x316fb0）
 * @func 0x316f90 0x316fb0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316f90 stmvs r4, {r1, r2, r9, r10, lr} ^
 *   @0x316f94 smulbtlt r4, r7, r9
 *   @0x316f98 andeq pc, r12, r4, lsl #2
 *   @0x316f9c .word 0xf7ff2500
 *   @0x316fa0 .word 0x60a5ffd9
 *   @0x316fa4 ldrtmi r6, [r8], -r5, lsr #32
 *   @0x316fa8 strtmi r6, [r1], -r5, rrx
 *   @0x316fac .word 0xf9c3f7d0
 *
 * ══ §597/828 __floatsisf  0x319368  size 32  8 条（0x319368..0x319388）
 * @func 0x319368 0x319388  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319368 ands r3, r0, #-2147483648
 *   @0x31936c rsbmi r0, r0, #0
 *   @0x319370 movs r12, r0
 *   @0x319374 bxeq lr
 *   @0x319378 orr r3, r3, #1258291200
 *   @0x31937c mov r1, r0
 *   @0x319380 mov r0, #0
 *   @0x319384 b 0x3193c8 <__floatdisf+0x30>
 *
 * ══ §598/828 __gnu_Unwind_Resume_or_Rethrow  0x319ba0  size 32  8 条（0x319ba0..0x319bc0）
 * @func 0x319ba0 0x319bc0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x3c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319ba0 ldr r2, [r0, #0xc]
 *   @0x319ba4 cmp r2, #0
 *   @0x319ba8 bne 0x319bb0 <__gnu_Unwind_Resume_or_Rethrow+0x10>
 *   @0x319bac b 0x319a6c <__gnu_Unwind_RaiseException>
 *   @0x319bb0 ldr r2, [r1, #0x3c]
 *   @0x319bb4 str r2, [r1, #0x40]
 *   @0x319bb8 mov r2, #0
 *   @0x319bbc b 0x319940 <__gnu_uldivmod_helper+0x34c>
 *
 * ══ §599/828 _Unwind_DeleteException  0x319bc4  size 32  8 条（0x319bc4..0x319be4）
 * @func 0x319bc4 0x319be4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319bc4 push {r3, lr}
 *   @0x319bc8 mov r1, r0
 *   @0x319bcc ldr r3, [r0, #0x8]
 *   @0x319bd0 cmp r3, #0
 *   @0x319bd4 popeq {r3, pc}
 *   @0x319bd8 mov r0, #1
 *   @0x319bdc blx r3
 *   @0x319be0 pop {r3, pc}
 *
 * ══ §600/828 zip_fopen  0x2a44b8  size 30  8 条（0x2a44b8..0x2a44d6）
 * @func 0x2a44b8 0x2a44d8  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: zip_fopen+0x1a
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a44b8 push {r3, r4, r5, lr}
 *   @0x2a44bc mov r4, r2
 *   @0x2a44c0 vmlsne.f32 s30, s3, s22
 *   @0x2a44c4 blt 0x2a44d2 <zip_fopen+0x1a>
 *   @0x2a44c8 mov r2, r4
 *   @0x2a44cc .word 0xf0004038
 *   @0x2a44d0 andhs r11, r0, r9, asr r8
 *   @0x2a44d4 pop {r3, r4, r5, pc}
 *
 * ══ §601/828 png_get_x_offset_pixels  0x2a66c0  size 30  8 条（0x2a66c0..0x2a66de）
 * @func 0x2a66c0 0x2a66ee  size 46  12 条
 * 部分覆盖: 本节 9/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a66c0 cbz r0, 0x2a66dc <png_get_x_offset_pixels+0x1c>
 *   @0x2a66c4 ldr r0, [r1, #0x8]
 *   @0x2a66c8 andle r7, r7, r0, lsl #1
 *   @0x2a66cc ldrb.w r3, [r1, #0x6c]
 *   @0x2a66d0 cbnz r3, 0x2a66da <png_get_x_offset_pixels+0x1a>
 *   @0x2a66d4 bx lr
 *   @0x2a66d8 bx lr
 *   @0x2a66dc bx lr
 *
 * ══ §602/828 png_get_y_offset_pixels  0x2a66de  size 30  8 条（0x2a66de..0x2a66fc）
 * @func 0x2a66de 0x2a66fe  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a66de cbz r0, 0x2a66fa <png_get_y_offset_pixels+0x1c>
 *   @0x2a66e2 ldr r0, [r1, #0x8]
 *   @0x2a66e6 andle r7, r7, r0, lsl #1
 *   @0x2a66ea ldrb.w r3, [r1, #0x6c]
 *   @0x2a66ee cbnz r3, 0x2a66f8 <png_get_y_offset_pixels+0x1a>
 *   @0x2a66f2 bx lr
 *   @0x2a66f6 bx lr
 *   @0x2a66fa bx lr
 *
 * ══ §603/828 png_get_bKGD  0x2a6716  size 30  8 条（0x2a6716..0x2a6734）
 * @func 0x2a6716 0x2a6736  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6716 cbz r0, 0x2a6732 <png_get_bKGD+0x1c>
 *   @0x2a671a ldr r0, [r1, #0x8]
 *   @0x2a671e andle r0, r7, r0, lsr #32
 *   @0x2a6722 cbz r2, 0x2a6730 <png_get_bKGD+0x1a>
 *   @0x2a6726 movs r0, #0x20
 *   @0x2a672a bx lr
 *   @0x2a672e bx lr
 *   @0x2a6732 bx lr
 *
 * ══ §604/828 png_get_hIST  0x2a6920  size 30  8 条（0x2a6920..0x2a693e）
 * @func 0x2a6920 0x2a6940  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6920 cbz r0, 0x2a693c <png_get_hIST+0x1c>
 *   @0x2a6924 ldr r0, [r1, #0x8]
 *   @0x2a6928 andle r0, r7, r0, asr #32
 *   @0x2a692c cbz r2, 0x2a693a <png_get_hIST+0x1a>
 *   @0x2a6930 movs r0, #0x40
 *   @0x2a6934 bx lr
 *   @0x2a6938 bx lr
 *   @0x2a693c bx lr
 *
 * ══ §605/828 png_get_sBIT  0x2a6af2  size 30  8 条（0x2a6af2..0x2a6b10）
 * @func 0x2a6af2 0x2a6b20  size 46  12 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6af2 cbz r0, 0x2a6b0e <png_get_sBIT+0x1c>
 *   @0x2a6af6 ldr r0, [r1, #0x8]
 *   @0x2a6afa andle r0, r7, r2
 *   @0x2a6afe cbz r2, 0x2a6b0c <png_get_sBIT+0x1a>
 *   @0x2a6b02 movs r0, #0x2
 *   @0x2a6b06 bx lr
 *   @0x2a6b0a bx lr
 *   @0x2a6b0e bx lr
 *
 * ══ §606/828 png_malloc_warn  0x2a6d16  size 30  8 条（0x2a6d16..0x2a6d34）
 * @func 0x2a6d16 0x2a6d36  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6d16 push {r3, r4, r5, lr}
 *   @0x2a6d1a cbz r0, 0x2a6d32 <png_malloc_warn+0x1c>
 *   @0x2a6d1e vst4.8 {d21, d23, d25, d27}, [r5:256], r0
 *   @0x2a6d22 .word 0xf8c01380
 *   @0x2a6d26 .word 0xf7ff3130
 *   @0x2a6d2a .word 0xf8c4ffba
 *   @0x2a6d2e ldclt p1, c5, [r8, #-192]!
 *   @0x2a6d32 pop {r3, r4, r5, pc}
 *
 * ══ §607/828 png_set_tRNS_to_alpha  0x2a87ec  size 30  8 条（0x2a87ec..0x2a880a）
 * @func 0x2a87ec 0x2a881a  size 46  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a87ec ldr.w r3, [r0, #0x134]
 *   @0x2a87f0 orr r3, r3, #0x2000000
 *   @0x2a87f4 orr r3, r3, #0x1000
 *   @0x2a87f8 str.w r3, [r0, #0x134]
 *   @0x2a87fc ldr.w r3, [r0, #0x130]
 *   @0x2a8800 bic r3, r3, #0x40
 *   @0x2a8804 str.w r3, [r0, #0x130]
 *   @0x2a8808 bx lr
 *
 * ══ §608/828 png_crc_read  0x2abc0c  size 30  8 条（0x2abc0c..0x2abc2a）
 * @func 0x2abc0c 0x2abc2c  size 32  8 条
 * 部分覆盖: 本节 8/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abc0c push {r4, r5, r6, lr}
 *   @0x2abc10 mov r4, r2
 *   @0x2abc14 cbz r0, 0x2abc28 <png_crc_read+0x1c>
 *   @0x2abc18 ldrtmi pc, [r0], -r11, lsl #20
 *   @0x2abc1c mov r1, r5
 *   @0x2abc20 pop.w {r4, r5, r6, lr}
 *   @0x2abc24 b.w 0x2a5b08 <png_calculate_crc>
 *   @0x2abc28 pop {r4, r5, r6, pc}
 *
 * ══ §609/828 png_set_unknown_chunk_location  0x2af434  size 30  8 条（0x2af434..0x2af452）
 * @func 0x2af434 0x2af454  size 32  8 条
 * 部分覆盖: 本节 8/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af434 cbz r0, 0x2af450 <png_set_unknown_chunk_location+0x1c>
 *   @0x2af438 cmp r2, #0x0
 *   @0x2af43c ldr.w r0, [r1, #0xc0]
 *   @0x2af440 cmp r2, r0
 *   @0x2af444 ldr.w r1, [r1, #0xbc]
 *   @0x2af448 movs r0, #0x14
 *   @0x2af44c ldrvc r1, [r3], #-514
 *   @0x2af450 bx lr
 *
 * ══ §610/828 png_set_packing  0x2af760  size 30  8 条（0x2af760..0x2af77e）
 * @func 0x2af760 0x2af780  size 32  8 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x47bf18
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af760 cbz r0, 0x2af77c <png_set_packing+0x1c>
 *   @0x2af764 blhs 0x47bf18 <targetStr+0xcd8>
 *   @0x2af768 bhi 0x2af77c <png_set_packing+0x1c>
 *   @0x2af76c .word 0xf0433134
 *   @0x2af770 .word 0xf8c00304
 *   @0x2af774 movwhs r3, #0x8134
 *   @0x2af778 strb.w r3, [r0, #0x1ec]
 *   @0x2af77c bx lr
 *
 * ══ §611/828 FT_Get_Char_Index  0x2e5960  size 30  8 条（0x2e5960..0x2e597e）
 * @func 0x2e5960 0x2e5980  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5960 push {r4, lr}
 *   @0x2e5964 cbnz r0, 0x2e596a <FT_Get_Char_Index+0xa>
 *   @0x2e5968 pop {r4, pc}
 *   @0x2e596c cmp r0, #0x0
 *   @0x2e5970 ldr r3, [r0, #0xc]
 *   @0x2e5974 blx r3
 *   @0x2e5978 cmp r0, r3
 *   @0x2e597c pop {r4, pc}
 *
 * ══ §612/828 FT_Library_Version  0x2e5fca  size 30  8 条（0x2e5fca..0x2e5fe8）
 * @func 0x2e5fca 0x2e5fea  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5fca push {r4, r5, lr}
 *   @0x2e5fce ldr r5, [r0, #0x4]
 *   @0x2e5fd2 ldr r0, [r0, #0xc]
 *   @0x2e5fd6 mov r4, r0
 *   @0x2e5fda cbz r1, 0x2e5fde <FT_Library_Version+0x14>
 *   @0x2e5fde cbz r2, 0x2e5fe2 <FT_Library_Version+0x18>
 *   @0x2e5fe2 cbz r3, 0x2e5fe6 <FT_Library_Version+0x1c>
 *   @0x2e5fe6 pop {r4, r5, pc}
 *
 * ══ §613/828 FT_Stream_Free  0x2e745e  size 30  8 条（0x2e745e..0x2e747c）
 * @func 0x2e745e 0x2e747e  size 32  8 条
 * 部分覆盖: 本节 8/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e745e push {r4, r5, r6, lr}
 *   @0x2e7462 mov r4, r0
 *   @0x2e7466 ldr r5, [r0, #0x1c]
 *   @0x2e746a stmdblt lr!, {r0, r1, r2, r4, r9, r11, r12, sp, lr, pc}
 *   @0x2e746e mov r0, r5
 *   @0x2e7472 pop.w {r4, r5, r6, lr}
 *   @0x2e7476 b.w 0x2e7336 <ft_mem_free>
 *   @0x2e747a pop {r4, r5, r6, pc}
 *
 * ══ §614/828 CBackground::Free()  0xc2d5c  size 28  7 条（0xc2d5c..0xc2d78）
 * @func 0xc2d5c 0xc2d78  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::~CBackground()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d5c push {r4, lr}
 *   @0xc2d60 subs r4, r0, #0
 *   @0xc2d64 popeq {r4, pc}
 *   @0xc2d68 bl 0xc2d48 <_ZN11CBackgroundD2Ev>
 *   @0xc2d6c mov r0, r4
 *   @0xc2d70 pop {r4, lr}
 *   @0xc2d74 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §615/828 IBuffer::~IBuffer()  0xcb85c  size 28  7 条（0xcb85c..0xcb878）
 * @func 0xcb85c 0xcb878  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb85c push {r4, lr}
 *   @0xcb860 mov r4, r0
 *   @0xcb864 bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xcb868 mov r0, r4
 *   @0xcb86c bl 0x27d1d0 <_ZdlPv>
 *   @0xcb870 mov r0, r4
 *   @0xcb874 pop {r4, pc}
 *
 * ══ §616/828 CCode::~CCode()  0xce36c  size 28  7 条（0xce36c..0xce388）
 * @func 0xce36c 0xce388  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCode::~CCode() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce36c push {r4, lr}
 *   @0xce370 mov r4, r0
 *   @0xce374 bl 0xce2b8 <_ZN5CCodeD2Ev>
 *   @0xce378 mov r0, r4
 *   @0xce37c bl 0x27d1d0 <_ZdlPv>
 *   @0xce380 mov r0, r4
 *   @0xce384 pop {r4, pc}
 *
 * ══ §617/828 KickOffGCThread()  0xd3ec0  size 28  7 条（0xd3ec0..0xd3edc）
 * @func 0xd3ec0 0xd3edc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3ec0 ldr r3, [pc, #0x10]
 *   @0xd3ec4 ldr r3, [pc, r3]
 *   @0xd3ec8 ldr r2, [r3]
 *   @0xd3ecc add r2, r2, #1
 *   @0xd3ed0 str r2, [r3]
 *   @0xd3ed4 bx lr
 *   @0xd3ed8 eorseq r9, r1, r12, lsl #26
 *
 * ══ §618/828 MarkObjectAsCurrent(void*)  0xd59b8  size 28  7 条（0xd59b8..0xd59d4）
 * @func 0xd59b8 0xd59d4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd59b8 cmp r0, #0
 *   @0xd59bc ldrne r3, [pc, #0xc]
 *   @0xd59c0 ldrne r3, [pc, r3]
 *   @0xd59c4 ldrne r3, [r3]
 *   @0xd59c8 strne r3, [r0, #0x34]
 *   @0xd59cc bx lr
 *   @0xd59d0 eorseq r8, r1, r12, lsl #5
 *
 * ══ §619/828 CEvent::~CEvent()  0xf2d68  size 28  7 条（0xf2d68..0xf2d84）
 * @func 0xf2d68 0xf2d84  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEvent::~CEvent() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2d68 push {r4, lr}
 *   @0xf2d6c mov r4, r0
 *   @0xf2d70 bl 0xf2d40 <_ZN6CEventD2Ev>
 *   @0xf2d74 mov r0, r4
 *   @0xf2d78 bl 0x27d1d0 <_ZdlPv>
 *   @0xf2d7c mov r0, r4
 *   @0xf2d80 pop {r4, pc}
 *
 * ══ §620/828 CEvent::Free()  0xf2e18  size 28  7 条（0xf2e18..0xf2e34）
 * @func 0xf2e18 0xf2e34  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2e18 push {r3, lr}
 *   @0xf2e1c subs r3, r0, #0
 *   @0xf2e20 popeq {r3, pc}
 *   @0xf2e24 ldr r3, [r3]
 *   @0xf2e28 ldr r3, [r3, #0x4]
 *   @0xf2e2c blx r3
 *   @0xf2e30 pop {r3, pc}
 *
 * ══ §621/828 CExtensionConstant::~CExtensionConstant()  0xf4750  size 28  7 条（0xf4750..0xf476c）
 * @func 0xf4750 0xf476c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionConstant::~CExtensionConstant() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4750 push {r4, lr}
 *   @0xf4754 mov r4, r0
 *   @0xf4758 bl 0xf46fc <_ZN18CExtensionConstantD2Ev>
 *   @0xf475c mov r0, r4
 *   @0xf4760 bl 0x27d1d0 <_ZdlPv>
 *   @0xf4764 mov r0, r4
 *   @0xf4768 pop {r4, pc}
 *
 * ══ §622/828 CExtensionFunction::~CExtensionFunction()  0xf47d8  size 28  7 条（0xf47d8..0xf47f4）
 * @func 0xf47d8 0xf47f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFunction::~CExtensionFunction() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf47d8 push {r4, lr}
 *   @0xf47dc mov r4, r0
 *   @0xf47e0 bl 0xf476c <_ZN18CExtensionFunctionD2Ev>
 *   @0xf47e4 mov r0, r4
 *   @0xf47e8 bl 0x27d1d0 <_ZdlPv>
 *   @0xf47ec mov r0, r4
 *   @0xf47f0 pop {r4, pc}
 *
 * ══ §623/828 CExtensionConstant::Free()  0xf48f0  size 28  7 条（0xf48f0..0xf490c）
 * @func 0xf48f0 0xf490c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf48f0 push {r3, lr}
 *   @0xf48f4 subs r3, r0, #0
 *   @0xf48f8 popeq {r3, pc}
 *   @0xf48fc ldr r3, [r3]
 *   @0xf4900 ldr r3, [r3, #0x4]
 *   @0xf4904 blx r3
 *   @0xf4908 pop {r3, pc}
 *
 * ══ §624/828 CExtensionFunction::Free()  0xf4b94  size 28  7 条（0xf4b94..0xf4bb0）
 * @func 0xf4b94 0xf4bb0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4b94 push {r3, lr}
 *   @0xf4b98 subs r3, r0, #0
 *   @0xf4b9c popeq {r3, pc}
 *   @0xf4ba0 ldr r3, [r3]
 *   @0xf4ba4 ldr r3, [r3, #0x4]
 *   @0xf4ba8 blx r3
 *   @0xf4bac pop {r3, pc}
 *
 * ══ §625/828 CExtensionFile::Free()  0xf4f90  size 28  7 条（0xf4f90..0xf4fac）
 * @func 0xf4f90 0xf4fac  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4f90 push {r3, lr}
 *   @0xf4f94 subs r3, r0, #0
 *   @0xf4f98 popeq {r3, pc}
 *   @0xf4f9c ldr r3, [r3]
 *   @0xf4fa0 ldr r3, [r3, #0x4]
 *   @0xf4fa4 blx r3
 *   @0xf4fa8 pop {r3, pc}
 *
 * ══ §626/828 CExtensionFile::~CExtensionFile()  0xf5150  size 28  7 条（0xf5150..0xf516c）
 * @func 0xf5150 0xf516c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::~CExtensionFile() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5150 push {r4, lr}
 *   @0xf5154 mov r4, r0
 *   @0xf5158 bl 0xf50e4 <_ZN14CExtensionFileD2Ev>
 *   @0xf515c mov r0, r4
 *   @0xf5160 bl 0x27d1d0 <_ZdlPv>
 *   @0xf5164 mov r0, r4
 *   @0xf5168 pop {r4, pc}
 *
 * ══ §627/828 CExtensionPackage::Free()  0xf5578  size 28  7 条（0xf5578..0xf5594）
 * @func 0xf5578 0xf5594  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5578 push {r3, lr}
 *   @0xf557c subs r3, r0, #0
 *   @0xf5580 popeq {r3, pc}
 *   @0xf5584 ldr r3, [r3]
 *   @0xf5588 ldr r3, [r3, #0x4]
 *   @0xf558c blx r3
 *   @0xf5590 pop {r3, pc}
 *
 * ══ §628/828 CExtensionPackage::~CExtensionPackage()  0xf5754  size 28  7 条（0xf5754..0xf5770）
 * @func 0xf5754 0xf5770  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::~CExtensionPackage() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5754 push {r4, lr}
 *   @0xf5758 mov r4, r0
 *   @0xf575c bl 0xf5700 <_ZN17CExtensionPackageD2Ev>
 *   @0xf5760 mov r0, r4
 *   @0xf5764 bl 0x27d1d0 <_ZdlPv>
 *   @0xf5768 mov r0, r4
 *   @0xf576c pop {r4, pc}
 *
 * ══ §629/828 CFontGM::~CFontGM()  0xf7d98  size 28  7 条（0xf7d98..0xf7db4）
 * @func 0xf7d98 0xf7db4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::~CFontGM() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7d98 push {r4, lr}
 *   @0xf7d9c mov r4, r0
 *   @0xf7da0 bl 0xf7d34 <_ZN7CFontGMD2Ev>
 *   @0xf7da4 mov r0, r4
 *   @0xf7da8 bl 0x27d1d0 <_ZdlPv>
 *   @0xf7dac mov r0, r4
 *   @0xf7db0 pop {r4, pc}
 *
 * ══ §630/828 CFontGM::Free()  0xf93ac  size 28  7 条（0xf93ac..0xf93c8）
 * @func 0xf93ac 0xf93c8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93ac push {r3, lr}
 *   @0xf93b0 subs r3, r0, #0
 *   @0xf93b4 popeq {r3, pc}
 *   @0xf93b8 ldr r3, [r3]
 *   @0xf93bc ldr r3, [r3, #0x4]
 *   @0xf93c0 blx r3
 *   @0xf93c4 pop {r3, pc}
 *
 * ══ §631/828 CFontGM::CFont_Create()  0xf93f8  size 28  7 条（0xf93f8..0xf9414）
 * @func 0xf93f8 0xf9414  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CFontGM::CFontGM()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93f8 push {r4, lr}
 *   @0xf93fc mov r0, #144
 *   @0xf9400 bl 0x27c524 <_Znwj>
 *   @0xf9404 mov r4, r0
 *   @0xf9408 bl 0xf71c8 <_ZN7CFontGMC2Ev>
 *   @0xf940c mov r0, r4
 *   @0xf9410 pop {r4, pc}
 *
 * ══ §632/828 CFontGM::CFont_GetBold(void*)  0xf9438  size 28  7 条（0xf9438..0xf9454）
 * @func 0xf9438 0xf9464  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::GetBold()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9438 push {r3, lr}
 *   @0xf943c subs r3, r0, #0
 *   @0xf9440 beq 0xf944c <_ZN7CFontGM13CFont_GetBoldEPv+0x14>
 *   @0xf9444 bl 0xf93d8 <_ZN7CFontGM7GetBoldEv>
 *   @0xf9448 pop {r3, pc}
 *   @0xf944c mov r0, r3
 *   @0xf9450 pop {r3, pc}
 *
 * ══ §633/828 CFontGM::CFont_GetItalic(void*)  0xf9454  size 28  7 条（0xf9454..0xf9470）
 * @func 0xf9454 0xf9470  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::GetItalic()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9454 push {r3, lr}
 *   @0xf9458 subs r3, r0, #0
 *   @0xf945c beq 0xf9468 <_ZN7CFontGM15CFont_GetItalicEPv+0x14>
 *   @0xf9460 bl 0xf93e0 <_ZN7CFontGM9GetItalicEv>
 *   @0xf9464 pop {r3, pc}
 *   @0xf9468 mov r0, r3
 *   @0xf946c pop {r3, pc}
 *
 * ══ §634/828 CFontGM::CFont_Draw_String(void*, float, float, unsigned short*, unsigned int, float)  0xf94f8  size 28  7 条（0xf94f8..0xf9514）
 * @func 0xf94f8 0xf9524  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf94f8 cmp r0, #0
 *   @0xf94fc str r4, [sp, #-0x4]!
 *   @0xf9500 beq 0xf950c <_ZN7CFontGM17CFont_Draw_StringEPvffPtjf+0x14>
 *   @0xf9504 ldr r4, [sp], #4
 *   @0xf9508 b 0xf7eec <_ZN7CFontGM11Draw_StringEffPtjf>
 *   @0xf950c ldr r4, [sp], #4
 *   @0xf9510 bx lr
 *
 * ══ §635/828 CFontGM::CFont_Draw_String_Transformed(void*, float, float, unsigned short*, float, float, float, unsigned int, float)  0xf9514  size 28  7 条（0xf9514..0xf9530）
 * @func 0xf9514 0xf9540  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9514 cmp r0, #0
 *   @0xf9518 push {r4, r5, r6, r7}
 *   @0xf951c beq 0xf9528 <_ZN7CFontGM29CFont_Draw_String_TransformedEPvffPtfffjf+0x14>
 *   @0xf9520 pop {r4, r5, r6, r7}
 *   @0xf9524 b 0xf830c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf>
 *   @0xf9528 pop {r4, r5, r6, r7}
 *   @0xf952c bx lr
 *
 * ══ §636/828 CFontGM::CFont_Draw_String_Color(void*, float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float)  0xf9530  size 28  7 条（0xf9530..0xf954c）
 * @func 0xf9530 0xf955c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9530 cmp r0, #0
 *   @0xf9534 push {r4, r5, r6, r7}
 *   @0xf9538 beq 0xf9544 <_ZN7CFontGM23CFont_Draw_String_ColorEPvffPtjjjjf+0x14>
 *   @0xf953c pop {r4, r5, r6, r7}
 *   @0xf9540 b 0xf8b58 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf>
 *   @0xf9544 pop {r4, r5, r6, r7}
 *   @0xf9548 bx lr
 *
 * ══ §637/828 CFontGM::CFont_Draw_String_Transformed_Color(void*, float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0xf954c  size 28  7 条（0xf954c..0xf9568）
 * @func 0xf954c 0xf9568  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf954c cmp r0, #0
 *   @0xf9550 push {r4, r5, r6, r7, r8, r9, r10}
 *   @0xf9554 beq 0xf9560 <_ZN7CFontGM35CFont_Draw_String_Transformed_ColorEPvffPtfffjjjjf+0x14>
 *   @0xf9558 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0xf955c b 0xf8f58 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf>
 *   @0xf9560 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0xf9564 bx lr
 *
 * ══ §638/828 F_TransitionDefine(RValue&, CInstance*, CInstance*, int, RValue*)  0x1074d0  size 28  7 条（0x1074d0..0x1074ec）
 * @func 0x1074d0 0x1074fc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1074d0 mov r2, #0
 *   @0x1074d4 mov r3, r2
 *   @0x1074d8 movt r2, #0xbff0
 *   @0x1074dc str r3, [r0, #0xc]
 *   @0x1074e0 str r2, [r0, #0x4]
 *   @0x1074e4 str r3, [r0]
 *   @0x1074e8 bx lr
 *
 * ══ §639/828 F_TransitionExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1074ec  size 28  7 条（0x1074ec..0x107508）
 * @func 0x1074ec 0x107508  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1074ec mov r2, #0
 *   @0x1074f0 mov r3, r2
 *   @0x1074f4 movt r2, #0xbff0
 *   @0x1074f8 str r3, [r0, #0xc]
 *   @0x1074fc str r2, [r0, #0x4]
 *   @0x107500 str r3, [r0]
 *   @0x107504 bx lr
 *
 * ══ §640/828 F_WindowSetCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a34c  size 28  7 条（0x11a34c..0x11a368）
 * @func 0x11a34c 0x11a368  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a34c push {r3, lr}
 *   @0x11a350 mov r1, #0
 *   @0x11a354 ldr r0, [sp, #0x8]
 *   @0x11a358 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11a35c mov r1, #0
 *   @0x11a360 pop {r3, lr}
 *   @0x11a364 b 0x17ae38 <_Z21GR_Window_Set_CaptionPKcb>
 *
 * ══ §641/828 F_WindowGetCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a3c8  size 28  7 条（0x11a3c8..0x11a3e4）
 * @func 0x11a3c8 0x11a3e4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Caption()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a3c8 push {r4, lr}
 *   @0x11a3cc mov r4, r0
 *   @0x11a3d0 bl 0x17aefc <_Z21GR_Window_Get_Captionv>
 *   @0x11a3d4 mov r1, r0
 *   @0x11a3d8 mov r0, r4
 *   @0x11a3dc pop {r4, lr}
 *   @0x11a3e0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §642/828 F_DrawClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ad40  size 28  7 条（0x11ad40..0x11ad5c）
 * @func 0x11ad40 0x11ad5c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ad40 push {r3, lr}
 *   @0x11ad44 mov r1, #0
 *   @0x11ad48 ldr r0, [sp, #0x8]
 *   @0x11ad4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ad50 pop {r3, lr}
 *   @0x11ad54 orr r0, r0, #-16777216
 *   @0x11ad58 b 0x169f58 <_Z13GR_Draw_Clearj>
 *
 * ══ §643/828 F_DrawPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b9d8  size 28  7 条（0x11b9d8..0x11b9f4）
 * @func 0x11b9d8 0x11b9f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b9d8 push {r3, lr}
 *   @0x11b9dc mov r1, #0
 *   @0x11b9e0 ldr r0, [sp, #0x8]
 *   @0x11b9e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b9e8 mvn r1, #0
 *   @0x11b9ec pop {r3, lr}
 *   @0x11b9f0 b 0x16b964 <_Z23GR_Draw_Primitive_Beginii>
 *
 * ══ §644/828 F_HighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*)  0x126870  size 28  7 条（0x126870..0x12688c）
 * @func 0x126870 0x12688c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / HighScore_Show(int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126870 push {r3, lr}
 *   @0x126874 mov r1, #0
 *   @0x126878 ldr r0, [sp, #0x8]
 *   @0x12687c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126880 bl 0x1dc2d4 <_Z14HighScore_Showi>
 *   @0x126884 pop {r3, lr}
 *   @0x126888 b 0x18c2c8 <_Z8IO_Clearv>
 *
 * ══ §645/828 F_ActionAnotherRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e6d8  size 28  7 条（0x13e6d8..0x13e6f4）
 * @func 0x13e6d8 0x13e6f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e6d8 push {r3, lr}
 *   @0x13e6dc mov r1, #0
 *   @0x13e6e0 ldr r0, [sp, #0x8]
 *   @0x13e6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e6e8 mov r1, #0
 *   @0x13e6ec pop {r3, lr}
 *   @0x13e6f0 b 0x1c9e08 <_Z16Command_GotoRoomii>
 *
 * ══ §646/828 F_ActionPartSystClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f988  size 28  7 条（0x13f988..0x13f9a4）
 * @func 0x13f988 0x13f9a4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f988 ldr r3, [pc, #0x10]
 *   @0x13f98c ldr r3, [pc, r3]
 *   @0x13f990 ldr r0, [r3]
 *   @0x13f994 cmp r0, #0
 *   @0x13f998 bxlt lr
 *   @0x13f99c b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari>
 *   @0x13f9a0 eoreq pc, r10, r0, asr r10
 *
 * ══ §647/828 F_D3DPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c38  size 28  7 条（0x143c38..0x143c54）
 * @func 0x143c38 0x143c54  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c38 push {r3, lr}
 *   @0x143c3c mov r1, #0
 *   @0x143c40 ldr r0, [sp, #0x8]
 *   @0x143c44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143c48 mvn r1, #0
 *   @0x143c4c pop {r3, lr}
 *   @0x143c50 b 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *
 * ══ §648/828 F_YoYo_OSHasFocus(RValue&, CInstance*, CInstance*, int, RValue*)  0x1561f4  size 28  7 条（0x1561f4..0x156210）
 * @func 0x1561f4 0x156210  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1561f4 mov r2, #0
 *   @0x1561f8 mov r3, r2
 *   @0x1561fc movt r2, #0x3ff0
 *   @0x156200 str r3, [r0, #0xc]
 *   @0x156204 str r2, [r0, #0x4]
 *   @0x156208 str r3, [r0]
 *   @0x15620c bx lr
 *
 * ══ §649/828 F_Platform_Function_Not_Supported(RValue&, CInstance*, CInstance*, int, RValue*)  0x1563a0  size 28  7 条（0x1563a0..0x1563bc）
 * @func 0x1563a0 0x1563bc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1563a0 mov r2, #0
 *   @0x1563a4 mov r3, r2
 *   @0x1563a8 movt r2, #0xbff0
 *   @0x1563ac str r3, [r0, #0xc]
 *   @0x1563b0 str r2, [r0, #0x4]
 *   @0x1563b4 str r3, [r0]
 *   @0x1563b8 bx lr
 *
 * ══ §650/828 F_YoYo_OF_AcceptChallenge(RValue&, CInstance*, CInstance*, int, RValue*)  0x15718c  size 28  7 条（0x15718c..0x1571a8）
 * @func 0x15718c 0x1571a8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YoYo_OF_AcceptChallenge()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15718c push {r4, lr}
 *   @0x157190 mov r4, r0
 *   @0x157194 bl 0x1616f0 <_Z23YoYo_OF_AcceptChallengev>
 *   @0x157198 mov r1, r0
 *   @0x15719c mov r0, r4
 *   @0x1571a0 pop {r4, lr}
 *   @0x1571a4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §651/828 F_YoYo_FacebookLoginStatus(RValue&, CInstance*, CInstance*, int, RValue*)  0x157290  size 28  7 条（0x157290..0x1572ac）
 * @func 0x157290 0x1572ac  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FacebookLoginStatusM()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157290 push {r4, lr}
 *   @0x157294 mov r4, r0
 *   @0x157298 bl 0x15f0dc <_Z20FacebookLoginStatusMv>
 *   @0x15729c mov r1, r0
 *   @0x1572a0 mov r0, r4
 *   @0x1572a4 pop {r4, lr}
 *   @0x1572a8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §652/828 F_YoYo_FacebookUserId(RValue&, CInstance*, CInstance*, int, RValue*)  0x1574e8  size 28  7 条（0x1574e8..0x157504）
 * @func 0x1574e8 0x157514  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FacebookUserIdM()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1574e8 push {r4, lr}
 *   @0x1574ec mov r4, r0
 *   @0x1574f0 bl 0x15ef7c <_Z15FacebookUserIdMv>
 *   @0x1574f4 mov r1, r0
 *   @0x1574f8 mov r0, r4
 *   @0x1574fc pop {r4, lr}
 *   @0x157500 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §653/828 F_YoYo_FacebookAccessToken(RValue&, CInstance*, CInstance*, int, RValue*)  0x157504  size 28  7 条（0x157504..0x157520）
 * @func 0x157504 0x157520  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FacebookAccessTokenM()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157504 push {r4, lr}
 *   @0x157508 mov r4, r0
 *   @0x15750c bl 0x15f028 <_Z20FacebookAccessTokenMv>
 *   @0x157510 mov r1, r0
 *   @0x157514 mov r0, r4
 *   @0x157518 pop {r4, lr}
 *   @0x15751c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §654/828 F_YoYo_GetLanguage(RValue&, CInstance*, CInstance*, int, RValue*)  0x157610  size 28  7 条（0x157610..0x15762c）
 * @func 0x157610 0x15763c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetLanguageString()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157610 push {r4, lr}
 *   @0x157614 mov r4, r0
 *   @0x157618 bl 0x15f21c <_Z17GetLanguageStringv>
 *   @0x15761c mov r1, r0
 *   @0x157620 mov r0, r4
 *   @0x157624 pop {r4, lr}
 *   @0x157628 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §655/828 F_YoYo_GetRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x15762c  size 28  7 条（0x15762c..0x157648）
 * @func 0x15762c 0x157658  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetRegionString()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15762c push {r4, lr}
 *   @0x157630 mov r4, r0
 *   @0x157634 bl 0x15f230 <_Z15GetRegionStringv>
 *   @0x157638 mov r1, r0
 *   @0x15763c mov r0, r4
 *   @0x157640 pop {r4, lr}
 *   @0x157644 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §656/828 F_YoYo_GetPlatform(RValue&, CInstance*, CInstance*, int, RValue*)  0x159d04  size 28  7 条（0x159d04..0x159d20）
 * @func 0x159d04 0x159d30  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YoYo_GetPlatform_DoWork()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159d04 push {r4, lr}
 *   @0x159d08 mov r3, #0
 *   @0x159d0c str r3, [r0, #0xc]
 *   @0x159d10 mov r4, r0
 *   @0x159d14 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x159d18 stm r4, {r0, r1}
 *   @0x159d1c pop {r4, pc}
 *
 * ══ §657/828 F_Steam_OverlayEnabled(RValue&, CInstance*, CInstance*, int, RValue*)  0x161c80  size 28  7 条（0x161c80..0x161c9c）
 * @func 0x161c80 0x161cac  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161c80 mov r2, #0
 *   @0x161c84 mov r3, r2
 *   @0x161c88 movt r2, #0xbff0
 *   @0x161c8c str r3, [r0, #0xc]
 *   @0x161c90 str r2, [r0, #0x4]
 *   @0x161c94 str r3, [r0]
 *   @0x161c98 bx lr
 *
 * ══ §658/828 F_Steam_OverlayActive(RValue&, CInstance*, CInstance*, int, RValue*)  0x161c9c  size 28  7 条（0x161c9c..0x161cb8）
 * @func 0x161c9c 0x161cb8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161c9c mov r2, #0
 *   @0x161ca0 mov r3, r2
 *   @0x161ca4 movt r2, #0xbff0
 *   @0x161ca8 str r3, [r0, #0xc]
 *   @0x161cac str r2, [r0, #0x4]
 *   @0x161cb0 str r3, [r0]
 *   @0x161cb4 bx lr
 *
 * ══ §659/828 F_Steam_IsCloudEnabledForApp(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d1c  size 28  7 条（0x161d1c..0x161d38）
 * @func 0x161d1c 0x161d48  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d1c mov r2, #0
 *   @0x161d20 mov r3, r2
 *   @0x161d24 movt r2, #0xbff0
 *   @0x161d28 str r3, [r0, #0xc]
 *   @0x161d2c str r2, [r0, #0x4]
 *   @0x161d30 str r3, [r0]
 *   @0x161d34 bx lr
 *
 * ══ §660/828 F_Steam_IsCloudEnabledForAccount(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d38  size 28  7 条（0x161d38..0x161d54）
 * @func 0x161d38 0x161d64  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d38 mov r2, #0
 *   @0x161d3c mov r3, r2
 *   @0x161d40 movt r2, #0xbff0
 *   @0x161d44 str r3, [r0, #0xc]
 *   @0x161d48 str r2, [r0, #0x4]
 *   @0x161d4c str r3, [r0]
 *   @0x161d50 bx lr
 *
 * ══ §661/828 F_Steam_FilePersisted(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d54  size 28  7 条（0x161d54..0x161d70）
 * @func 0x161d54 0x161d80  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d54 mov r2, #0
 *   @0x161d58 mov r3, r2
 *   @0x161d5c movt r2, #0xbff0
 *   @0x161d60 str r3, [r0, #0xc]
 *   @0x161d64 str r2, [r0, #0x4]
 *   @0x161d68 str r3, [r0]
 *   @0x161d6c bx lr
 *
 * ══ §662/828 F_Steam_GetQuotaTotal(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d70  size 28  7 条（0x161d70..0x161d8c）
 * @func 0x161d70 0x161d9c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d70 mov r2, #0
 *   @0x161d74 mov r3, r2
 *   @0x161d78 movt r2, #0xbff0
 *   @0x161d7c str r3, [r0, #0xc]
 *   @0x161d80 str r2, [r0, #0x4]
 *   @0x161d84 str r3, [r0]
 *   @0x161d88 bx lr
 *
 * ══ §663/828 F_Steam_GetQuotaFree(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d8c  size 28  7 条（0x161d8c..0x161da8）
 * @func 0x161d8c 0x161db8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d8c mov r2, #0
 *   @0x161d90 mov r3, r2
 *   @0x161d94 movt r2, #0xbff0
 *   @0x161d98 str r3, [r0, #0xc]
 *   @0x161d9c str r2, [r0, #0x4]
 *   @0x161da0 str r3, [r0]
 *   @0x161da4 bx lr
 *
 * ══ §664/828 F_Steam_FileWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0x161da8  size 28  7 条（0x161da8..0x161dc4）
 * @func 0x161da8 0x161dd4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161da8 mov r2, #0
 *   @0x161dac mov r3, r2
 *   @0x161db0 movt r2, #0xbff0
 *   @0x161db4 str r3, [r0, #0xc]
 *   @0x161db8 str r2, [r0, #0x4]
 *   @0x161dbc str r3, [r0]
 *   @0x161dc0 bx lr
 *
 * ══ §665/828 F_Steam_FileWriteFile(RValue&, CInstance*, CInstance*, int, RValue*)  0x161dc4  size 28  7 条（0x161dc4..0x161de0）
 * @func 0x161dc4 0x161df0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161dc4 mov r2, #0
 *   @0x161dc8 mov r3, r2
 *   @0x161dcc movt r2, #0xbff0
 *   @0x161dd0 str r3, [r0, #0xc]
 *   @0x161dd4 str r2, [r0, #0x4]
 *   @0x161dd8 str r3, [r0]
 *   @0x161ddc bx lr
 *
 * ══ §666/828 F_Steam_FileDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x161de0  size 28  7 条（0x161de0..0x161dfc）
 * @func 0x161de0 0x161e0c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161de0 mov r2, #0
 *   @0x161de4 mov r3, r2
 *   @0x161de8 movt r2, #0xbff0
 *   @0x161dec str r3, [r0, #0xc]
 *   @0x161df0 str r2, [r0, #0x4]
 *   @0x161df4 str r3, [r0]
 *   @0x161df8 bx lr
 *
 * ══ §667/828 F_Steam_FileExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x161dfc  size 28  7 条（0x161dfc..0x161e18）
 * @func 0x161dfc 0x161e28  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161dfc mov r2, #0
 *   @0x161e00 mov r3, r2
 *   @0x161e04 movt r2, #0xbff0
 *   @0x161e08 str r3, [r0, #0xc]
 *   @0x161e0c str r2, [r0, #0x4]
 *   @0x161e10 str r3, [r0]
 *   @0x161e14 bx lr
 *
 * ══ §668/828 F_Steam_FileSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x161e18  size 28  7 条（0x161e18..0x161e34）
 * @func 0x161e18 0x161e44  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161e18 mov r2, #0
 *   @0x161e1c mov r3, r2
 *   @0x161e20 movt r2, #0xbff0
 *   @0x161e24 str r3, [r0, #0xc]
 *   @0x161e28 str r2, [r0, #0x4]
 *   @0x161e2c str r3, [r0]
 *   @0x161e30 bx lr
 *
 * ══ §669/828 F_Steam_FileShare(RValue&, CInstance*, CInstance*, int, RValue*)  0x161e34  size 28  7 条（0x161e34..0x161e50）
 * @func 0x161e34 0x161e60  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161e34 mov r2, #0
 *   @0x161e38 mov r3, r2
 *   @0x161e3c movt r2, #0xbff0
 *   @0x161e40 str r3, [r0, #0xc]
 *   @0x161e44 str r2, [r0, #0x4]
 *   @0x161e48 str r3, [r0]
 *   @0x161e4c bx lr
 *
 * ══ §670/828 F_Steam_PublishWorkshopFile(RValue&, CInstance*, CInstance*, int, RValue*)  0x161e50  size 28  7 条（0x161e50..0x161e6c）
 * @func 0x161e50 0x161e7c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161e50 mov r2, #0
 *   @0x161e54 mov r3, r2
 *   @0x161e58 movt r2, #0xbff0
 *   @0x161e5c str r3, [r0, #0xc]
 *   @0x161e60 str r2, [r0, #0x4]
 *   @0x161e64 str r3, [r0]
 *   @0x161e68 bx lr
 *
 * ══ §671/828 F_Steam_IsScreenshotRequested(RValue&, CInstance*, CInstance*, int, RValue*)  0x161e6c  size 28  7 条（0x161e6c..0x161e88）
 * @func 0x161e6c 0x161e98  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161e6c mov r2, #0
 *   @0x161e70 mov r3, r2
 *   @0x161e74 movt r2, #0xbff0
 *   @0x161e78 str r3, [r0, #0xc]
 *   @0x161e7c str r2, [r0, #0x4]
 *   @0x161e80 str r3, [r0]
 *   @0x161e84 bx lr
 *
 * ══ §672/828 F_Steam_SendScreenshotToSteam(RValue&, CInstance*, CInstance*, int, RValue*)  0x161e88  size 28  7 条（0x161e88..0x161ea4）
 * @func 0x161e88 0x161eb4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161e88 mov r2, #0
 *   @0x161e8c mov r3, r2
 *   @0x161e90 movt r2, #0xbff0
 *   @0x161e94 str r3, [r0, #0xc]
 *   @0x161e98 str r2, [r0, #0x4]
 *   @0x161e9c str r3, [r0]
 *   @0x161ea0 bx lr
 *
 * ══ §673/828 F_Steam_IsLoggedOn(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ea4  size 28  7 条（0x161ea4..0x161ec0）
 * @func 0x161ea4 0x161ec0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ea4 mov r2, #0
 *   @0x161ea8 mov r3, r2
 *   @0x161eac movt r2, #0xbff0
 *   @0x161eb0 str r3, [r0, #0xc]
 *   @0x161eb4 str r2, [r0, #0x4]
 *   @0x161eb8 str r3, [r0]
 *   @0x161ebc bx lr
 *
 * ══ §674/828 F_Steam_DoesUserOwnDLC(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ed8  size 28  7 条（0x161ed8..0x161ef4）
 * @func 0x161ed8 0x161f04  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ed8 mov r2, #0
 *   @0x161edc mov r3, r2
 *   @0x161ee0 movt r2, #0xbff0
 *   @0x161ee4 str r3, [r0, #0xc]
 *   @0x161ee8 str r2, [r0, #0x4]
 *   @0x161eec str r3, [r0]
 *   @0x161ef0 bx lr
 *
 * ══ §675/828 F_Steam_HasUserInstalledDLC(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ef4  size 28  7 条（0x161ef4..0x161f10）
 * @func 0x161ef4 0x161f20  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ef4 mov r2, #0
 *   @0x161ef8 mov r3, r2
 *   @0x161efc movt r2, #0xbff0
 *   @0x161f00 str r3, [r0, #0xc]
 *   @0x161f04 str r2, [r0, #0x4]
 *   @0x161f08 str r3, [r0]
 *   @0x161f0c bx lr
 *
 * ══ §676/828 F_Steam_SetAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f10  size 28  7 条（0x161f10..0x161f2c）
 * @func 0x161f10 0x161f3c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f10 mov r2, #0
 *   @0x161f14 mov r3, r2
 *   @0x161f18 movt r2, #0xbff0
 *   @0x161f1c str r3, [r0, #0xc]
 *   @0x161f20 str r2, [r0, #0x4]
 *   @0x161f24 str r3, [r0]
 *   @0x161f28 bx lr
 *
 * ══ §677/828 F_Steam_GetAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f2c  size 28  7 条（0x161f2c..0x161f48）
 * @func 0x161f2c 0x161f58  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f2c mov r2, #0
 *   @0x161f30 mov r3, r2
 *   @0x161f34 movt r2, #0xbff0
 *   @0x161f38 str r3, [r0, #0xc]
 *   @0x161f3c str r2, [r0, #0x4]
 *   @0x161f40 str r3, [r0]
 *   @0x161f44 bx lr
 *
 * ══ §678/828 F_Steam_ClearAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f48  size 28  7 条（0x161f48..0x161f64）
 * @func 0x161f48 0x161f74  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f48 mov r2, #0
 *   @0x161f4c mov r3, r2
 *   @0x161f50 movt r2, #0xbff0
 *   @0x161f54 str r3, [r0, #0xc]
 *   @0x161f58 str r2, [r0, #0x4]
 *   @0x161f5c str r3, [r0]
 *   @0x161f60 bx lr
 *
 * ══ §679/828 F_Steam_SetStatInt(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f64  size 28  7 条（0x161f64..0x161f80）
 * @func 0x161f64 0x161f90  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f64 mov r2, #0
 *   @0x161f68 mov r3, r2
 *   @0x161f6c movt r2, #0xbff0
 *   @0x161f70 str r3, [r0, #0xc]
 *   @0x161f74 str r2, [r0, #0x4]
 *   @0x161f78 str r3, [r0]
 *   @0x161f7c bx lr
 *
 * ══ §680/828 F_Steam_SetStatFloat(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f80  size 28  7 条（0x161f80..0x161f9c）
 * @func 0x161f80 0x161fac  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f80 mov r2, #0
 *   @0x161f84 mov r3, r2
 *   @0x161f88 movt r2, #0xbff0
 *   @0x161f8c str r3, [r0, #0xc]
 *   @0x161f90 str r2, [r0, #0x4]
 *   @0x161f94 str r3, [r0]
 *   @0x161f98 bx lr
 *
 * ══ §681/828 F_Steam_SetStatAvgRate(RValue&, CInstance*, CInstance*, int, RValue*)  0x161f9c  size 28  7 条（0x161f9c..0x161fb8）
 * @func 0x161f9c 0x161fc8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161f9c mov r2, #0
 *   @0x161fa0 mov r3, r2
 *   @0x161fa4 movt r2, #0xbff0
 *   @0x161fa8 str r3, [r0, #0xc]
 *   @0x161fac str r2, [r0, #0x4]
 *   @0x161fb0 str r3, [r0]
 *   @0x161fb4 bx lr
 *
 * ══ §682/828 F_Steam_GetStatInt(RValue&, CInstance*, CInstance*, int, RValue*)  0x161fb8  size 28  7 条（0x161fb8..0x161fd4）
 * @func 0x161fb8 0x161fe4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161fb8 mov r2, #0
 *   @0x161fbc mov r3, r2
 *   @0x161fc0 movt r2, #0xbff0
 *   @0x161fc4 str r3, [r0, #0xc]
 *   @0x161fc8 str r2, [r0, #0x4]
 *   @0x161fcc str r3, [r0]
 *   @0x161fd0 bx lr
 *
 * ══ §683/828 F_Steam_GetStatFloat(RValue&, CInstance*, CInstance*, int, RValue*)  0x161fd4  size 28  7 条（0x161fd4..0x161ff0）
 * @func 0x161fd4 0x162000  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161fd4 mov r2, #0
 *   @0x161fd8 mov r3, r2
 *   @0x161fdc movt r2, #0xbff0
 *   @0x161fe0 str r3, [r0, #0xc]
 *   @0x161fe4 str r2, [r0, #0x4]
 *   @0x161fe8 str r3, [r0]
 *   @0x161fec bx lr
 *
 * ══ §684/828 F_Steam_GetStatAvgRate(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ff0  size 28  7 条（0x161ff0..0x16200c）
 * @func 0x161ff0 0x16200c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ff0 mov r2, #0
 *   @0x161ff4 mov r3, r2
 *   @0x161ff8 movt r2, #0xbff0
 *   @0x161ffc str r3, [r0, #0xc]
 *   @0x162000 str r2, [r0, #0x4]
 *   @0x162004 str r3, [r0]
 *   @0x162008 bx lr
 *
 * ══ §685/828 F_Steam_CreateLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*)  0x162014  size 28  7 条（0x162014..0x162030）
 * @func 0x162014 0x162040  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162014 mov r2, #0
 *   @0x162018 mov r3, r2
 *   @0x16201c movt r2, #0xbff0
 *   @0x162020 str r3, [r0, #0xc]
 *   @0x162024 str r2, [r0, #0x4]
 *   @0x162028 str r3, [r0]
 *   @0x16202c bx lr
 *
 * ══ §686/828 F_Steam_UploadScore(RValue&, CInstance*, CInstance*, int, RValue*)  0x162030  size 28  7 条（0x162030..0x16204c）
 * @func 0x162030 0x16205c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162030 mov r2, #0
 *   @0x162034 mov r3, r2
 *   @0x162038 movt r2, #0xbff0
 *   @0x16203c str r3, [r0, #0xc]
 *   @0x162040 str r2, [r0, #0x4]
 *   @0x162044 str r3, [r0]
 *   @0x162048 bx lr
 *
 * ══ §687/828 F_Steam_UploadScoreExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x16204c  size 28  7 条（0x16204c..0x162068）
 * @func 0x16204c 0x162078  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16204c mov r2, #0
 *   @0x162050 mov r3, r2
 *   @0x162054 movt r2, #0xbff0
 *   @0x162058 str r3, [r0, #0xc]
 *   @0x16205c str r2, [r0, #0x4]
 *   @0x162060 str r3, [r0]
 *   @0x162064 bx lr
 *
 * ══ §688/828 F_Steam_UploadScoreBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0x162068  size 28  7 条（0x162068..0x162084）
 * @func 0x162068 0x162094  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162068 mov r2, #0
 *   @0x16206c mov r3, r2
 *   @0x162070 movt r2, #0xbff0
 *   @0x162074 str r3, [r0, #0xc]
 *   @0x162078 str r2, [r0, #0x4]
 *   @0x16207c str r3, [r0]
 *   @0x162080 bx lr
 *
 * ══ §689/828 F_Steam_UploadScoreBufferExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x162084  size 28  7 条（0x162084..0x1620a0）
 * @func 0x162084 0x1620b0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162084 mov r2, #0
 *   @0x162088 mov r3, r2
 *   @0x16208c movt r2, #0xbff0
 *   @0x162090 str r3, [r0, #0xc]
 *   @0x162094 str r2, [r0, #0x4]
 *   @0x162098 str r3, [r0]
 *   @0x16209c bx lr
 *
 * ══ §690/828 F_Steam_DownloadScoresUserRange(RValue&, CInstance*, CInstance*, int, RValue*)  0x1620a0  size 28  7 条（0x1620a0..0x1620bc）
 * @func 0x1620a0 0x1620cc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1620a0 mov r2, #0
 *   @0x1620a4 mov r3, r2
 *   @0x1620a8 movt r2, #0xbff0
 *   @0x1620ac str r3, [r0, #0xc]
 *   @0x1620b0 str r2, [r0, #0x4]
 *   @0x1620b4 str r3, [r0]
 *   @0x1620b8 bx lr
 *
 * ══ §691/828 F_Steam_DownloadScores(RValue&, CInstance*, CInstance*, int, RValue*)  0x1620bc  size 28  7 条（0x1620bc..0x1620d8）
 * @func 0x1620bc 0x1620e8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1620bc mov r2, #0
 *   @0x1620c0 mov r3, r2
 *   @0x1620c4 movt r2, #0xbff0
 *   @0x1620c8 str r3, [r0, #0xc]
 *   @0x1620cc str r2, [r0, #0x4]
 *   @0x1620d0 str r3, [r0]
 *   @0x1620d4 bx lr
 *
 * ══ §692/828 F_Steam_DownloadFriendsScores(RValue&, CInstance*, CInstance*, int, RValue*)  0x1620d8  size 28  7 条（0x1620d8..0x1620f4）
 * @func 0x1620d8 0x162104  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1620d8 mov r2, #0
 *   @0x1620dc mov r3, r2
 *   @0x1620e0 movt r2, #0xbff0
 *   @0x1620e4 str r3, [r0, #0xc]
 *   @0x1620e8 str r2, [r0, #0x4]
 *   @0x1620ec str r3, [r0]
 *   @0x1620f0 bx lr
 *
 * ══ §693/828 F_Steam_StatsReady(RValue&, CInstance*, CInstance*, int, RValue*)  0x1620f4  size 28  7 条（0x1620f4..0x162110）
 * @func 0x1620f4 0x162120  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1620f4 mov r2, #0
 *   @0x1620f8 mov r3, r2
 *   @0x1620fc movt r2, #0xbff0
 *   @0x162100 str r3, [r0, #0xc]
 *   @0x162104 str r2, [r0, #0x4]
 *   @0x162108 str r3, [r0]
 *   @0x16210c bx lr
 *
 * ══ §694/828 F_Steam_GetAppId(RValue&, CInstance*, CInstance*, int, RValue*)  0x162110  size 28  7 条（0x162110..0x16212c）
 * @func 0x162110 0x16213c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162110 mov r2, #0
 *   @0x162114 mov r3, r2
 *   @0x162118 movt r2, #0xbff0
 *   @0x16211c str r3, [r0, #0xc]
 *   @0x162120 str r2, [r0, #0x4]
 *   @0x162124 str r3, [r0]
 *   @0x162128 bx lr
 *
 * ══ §695/828 F_Steam_GetUserAccountId(RValue&, CInstance*, CInstance*, int, RValue*)  0x16212c  size 28  7 条（0x16212c..0x162148）
 * @func 0x16212c 0x162158  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16212c mov r2, #0
 *   @0x162130 mov r3, r2
 *   @0x162134 movt r2, #0xbff0
 *   @0x162138 str r3, [r0, #0xc]
 *   @0x16213c str r2, [r0, #0x4]
 *   @0x162140 str r3, [r0]
 *   @0x162144 bx lr
 *
 * ══ §696/828 F_Steam_UGCDownload(RValue&, CInstance*, CInstance*, int, RValue*)  0x162148  size 28  7 条（0x162148..0x162164）
 * @func 0x162148 0x162174  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162148 mov r2, #0
 *   @0x16214c mov r3, r2
 *   @0x162150 movt r2, #0xbff0
 *   @0x162154 str r3, [r0, #0xc]
 *   @0x162158 str r2, [r0, #0x4]
 *   @0x16215c str r3, [r0]
 *   @0x162160 bx lr
 *
 * ══ §697/828 F_SteamUGC_CreateItem(RValue&, CInstance*, CInstance*, int, RValue*)  0x162164  size 28  7 条（0x162164..0x162180）
 * @func 0x162164 0x162180  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162164 mov r2, #0
 *   @0x162168 mov r3, r2
 *   @0x16216c movt r2, #0xbff0
 *   @0x162170 str r3, [r0, #0xc]
 *   @0x162174 str r2, [r0, #0x4]
 *   @0x162178 str r3, [r0]
 *   @0x16217c bx lr
 *
 * ══ §698/828 F_SteamUGC_SetItemTitle(RValue&, CInstance*, CInstance*, int, RValue*)  0x162184  size 28  7 条（0x162184..0x1621a0）
 * @func 0x162184 0x1621b0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162184 mov r2, #0
 *   @0x162188 mov r3, r2
 *   @0x16218c movt r2, #0xbff0
 *   @0x162190 str r3, [r0, #0xc]
 *   @0x162194 str r2, [r0, #0x4]
 *   @0x162198 str r3, [r0]
 *   @0x16219c bx lr
 *
 * ══ §699/828 F_SteamUGC_SetItemDesc(RValue&, CInstance*, CInstance*, int, RValue*)  0x1621a0  size 28  7 条（0x1621a0..0x1621bc）
 * @func 0x1621a0 0x1621cc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1621a0 mov r2, #0
 *   @0x1621a4 mov r3, r2
 *   @0x1621a8 movt r2, #0xbff0
 *   @0x1621ac str r3, [r0, #0xc]
 *   @0x1621b0 str r2, [r0, #0x4]
 *   @0x1621b4 str r3, [r0]
 *   @0x1621b8 bx lr
 *
 * ══ §700/828 F_SteamUGC_SetItemVis(RValue&, CInstance*, CInstance*, int, RValue*)  0x1621bc  size 28  7 条（0x1621bc..0x1621d8）
 * @func 0x1621bc 0x1621e8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1621bc mov r2, #0
 *   @0x1621c0 mov r3, r2
 *   @0x1621c4 movt r2, #0xbff0
 *   @0x1621c8 str r3, [r0, #0xc]
 *   @0x1621cc str r2, [r0, #0x4]
 *   @0x1621d0 str r3, [r0]
 *   @0x1621d4 bx lr
 *
 * ══ §701/828 F_SteamUGC_SetItemTags(RValue&, CInstance*, CInstance*, int, RValue*)  0x1621d8  size 28  7 条（0x1621d8..0x1621f4）
 * @func 0x1621d8 0x162204  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1621d8 mov r2, #0
 *   @0x1621dc mov r3, r2
 *   @0x1621e0 movt r2, #0xbff0
 *   @0x1621e4 str r3, [r0, #0xc]
 *   @0x1621e8 str r2, [r0, #0x4]
 *   @0x1621ec str r3, [r0]
 *   @0x1621f0 bx lr
 *
 * ══ §702/828 F_SteamUGC_SetItemContent(RValue&, CInstance*, CInstance*, int, RValue*)  0x1621f4  size 28  7 条（0x1621f4..0x162210）
 * @func 0x1621f4 0x162220  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1621f4 mov r2, #0
 *   @0x1621f8 mov r3, r2
 *   @0x1621fc movt r2, #0xbff0
 *   @0x162200 str r3, [r0, #0xc]
 *   @0x162204 str r2, [r0, #0x4]
 *   @0x162208 str r3, [r0]
 *   @0x16220c bx lr
 *
 * ══ §703/828 F_SteamUGC_SetItemPreview(RValue&, CInstance*, CInstance*, int, RValue*)  0x162210  size 28  7 条（0x162210..0x16222c）
 * @func 0x162210 0x16223c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162210 mov r2, #0
 *   @0x162214 mov r3, r2
 *   @0x162218 movt r2, #0xbff0
 *   @0x16221c str r3, [r0, #0xc]
 *   @0x162220 str r2, [r0, #0x4]
 *   @0x162224 str r3, [r0]
 *   @0x162228 bx lr
 *
 * ══ §704/828 F_SteamUGC_SubmitItemUpdate(RValue&, CInstance*, CInstance*, int, RValue*)  0x16222c  size 28  7 条（0x16222c..0x162248）
 * @func 0x16222c 0x162258  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16222c mov r2, #0
 *   @0x162230 mov r3, r2
 *   @0x162234 movt r2, #0xbff0
 *   @0x162238 str r3, [r0, #0xc]
 *   @0x16223c str r2, [r0, #0x4]
 *   @0x162240 str r3, [r0]
 *   @0x162244 bx lr
 *
 * ══ §705/828 F_SteamUGC_GetItemUpdateProgress(RValue&, CInstance*, CInstance*, int, RValue*)  0x162248  size 28  7 条（0x162248..0x162264）
 * @func 0x162248 0x162274  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162248 mov r2, #0
 *   @0x16224c mov r3, r2
 *   @0x162250 movt r2, #0xbff0
 *   @0x162254 str r3, [r0, #0xc]
 *   @0x162258 str r2, [r0, #0x4]
 *   @0x16225c str r3, [r0]
 *   @0x162260 bx lr
 *
 * ══ §706/828 F_SteamUGC_SubscribeItem(RValue&, CInstance*, CInstance*, int, RValue*)  0x162264  size 28  7 条（0x162264..0x162280）
 * @func 0x162264 0x162290  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162264 mov r2, #0
 *   @0x162268 mov r3, r2
 *   @0x16226c movt r2, #0xbff0
 *   @0x162270 str r3, [r0, #0xc]
 *   @0x162274 str r2, [r0, #0x4]
 *   @0x162278 str r3, [r0]
 *   @0x16227c bx lr
 *
 * ══ §707/828 F_SteamUGC_UnsubscribeItem(RValue&, CInstance*, CInstance*, int, RValue*)  0x162280  size 28  7 条（0x162280..0x16229c）
 * @func 0x162280 0x1622ac  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162280 mov r2, #0
 *   @0x162284 mov r3, r2
 *   @0x162288 movt r2, #0xbff0
 *   @0x16228c str r3, [r0, #0xc]
 *   @0x162290 str r2, [r0, #0x4]
 *   @0x162294 str r3, [r0]
 *   @0x162298 bx lr
 *
 * ══ §708/828 F_SteamUGC_GetNumSubscribedItems(RValue&, CInstance*, CInstance*, int, RValue*)  0x16229c  size 28  7 条（0x16229c..0x1622b8）
 * @func 0x16229c 0x1622c8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16229c mov r2, #0
 *   @0x1622a0 mov r3, r2
 *   @0x1622a4 movt r2, #0xbff0
 *   @0x1622a8 str r3, [r0, #0xc]
 *   @0x1622ac str r2, [r0, #0x4]
 *   @0x1622b0 str r3, [r0]
 *   @0x1622b4 bx lr
 *
 * ══ §709/828 F_SteamUGC_GetSubscribedItems(RValue&, CInstance*, CInstance*, int, RValue*)  0x1622b8  size 28  7 条（0x1622b8..0x1622d4）
 * @func 0x1622b8 0x1622e4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1622b8 mov r2, #0
 *   @0x1622bc mov r3, r2
 *   @0x1622c0 movt r2, #0xbff0
 *   @0x1622c4 str r3, [r0, #0xc]
 *   @0x1622c8 str r2, [r0, #0x4]
 *   @0x1622cc str r3, [r0]
 *   @0x1622d0 bx lr
 *
 * ══ §710/828 F_SteamUGC_GetItemInstallInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x1622d4  size 28  7 条（0x1622d4..0x1622f0）
 * @func 0x1622d4 0x162300  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1622d4 mov r2, #0
 *   @0x1622d8 mov r3, r2
 *   @0x1622dc movt r2, #0xbff0
 *   @0x1622e0 str r3, [r0, #0xc]
 *   @0x1622e4 str r2, [r0, #0x4]
 *   @0x1622e8 str r3, [r0]
 *   @0x1622ec bx lr
 *
 * ══ §711/828 F_SteamUGC_GetItemUpdateInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x1622f0  size 28  7 条（0x1622f0..0x16230c）
 * @func 0x1622f0 0x16231c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1622f0 mov r2, #0
 *   @0x1622f4 mov r3, r2
 *   @0x1622f8 movt r2, #0xbff0
 *   @0x1622fc str r3, [r0, #0xc]
 *   @0x162300 str r2, [r0, #0x4]
 *   @0x162304 str r3, [r0]
 *   @0x162308 bx lr
 *
 * ══ §712/828 F_SteamUGC_RequestItemDetails(RValue&, CInstance*, CInstance*, int, RValue*)  0x16230c  size 28  7 条（0x16230c..0x162328）
 * @func 0x16230c 0x162338  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16230c mov r2, #0
 *   @0x162310 mov r3, r2
 *   @0x162314 movt r2, #0xbff0
 *   @0x162318 str r3, [r0, #0xc]
 *   @0x16231c str r2, [r0, #0x4]
 *   @0x162320 str r3, [r0]
 *   @0x162324 bx lr
 *
 * ══ §713/828 F_SteamUGC_QuerySetCloudFilenameFilter(RValue&, CInstance*, CInstance*, int, RValue*)  0x162328  size 28  7 条（0x162328..0x162344）
 * @func 0x162328 0x162354  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162328 mov r2, #0
 *   @0x16232c mov r3, r2
 *   @0x162330 movt r2, #0xbff0
 *   @0x162334 str r3, [r0, #0xc]
 *   @0x162338 str r2, [r0, #0x4]
 *   @0x16233c str r3, [r0]
 *   @0x162340 bx lr
 *
 * ══ §714/828 F_SteamUGC_QuerySetMatchAnyTag(RValue&, CInstance*, CInstance*, int, RValue*)  0x162344  size 28  7 条（0x162344..0x162360）
 * @func 0x162344 0x162370  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162344 mov r2, #0
 *   @0x162348 mov r3, r2
 *   @0x16234c movt r2, #0xbff0
 *   @0x162350 str r3, [r0, #0xc]
 *   @0x162354 str r2, [r0, #0x4]
 *   @0x162358 str r3, [r0]
 *   @0x16235c bx lr
 *
 * ══ §715/828 F_SteamUGC_QuerySetSearchText(RValue&, CInstance*, CInstance*, int, RValue*)  0x162360  size 28  7 条（0x162360..0x16237c）
 * @func 0x162360 0x16238c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162360 mov r2, #0
 *   @0x162364 mov r3, r2
 *   @0x162368 movt r2, #0xbff0
 *   @0x16236c str r3, [r0, #0xc]
 *   @0x162370 str r2, [r0, #0x4]
 *   @0x162374 str r3, [r0]
 *   @0x162378 bx lr
 *
 * ══ §716/828 F_SteamUGC_QuerySetRankedByTrendDays(RValue&, CInstance*, CInstance*, int, RValue*)  0x16237c  size 28  7 条（0x16237c..0x162398）
 * @func 0x16237c 0x1623a8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16237c mov r2, #0
 *   @0x162380 mov r3, r2
 *   @0x162384 movt r2, #0xbff0
 *   @0x162388 str r3, [r0, #0xc]
 *   @0x16238c str r2, [r0, #0x4]
 *   @0x162390 str r3, [r0]
 *   @0x162394 bx lr
 *
 * ══ §717/828 F_SteamUGC_QueryAddRequiredTag(RValue&, CInstance*, CInstance*, int, RValue*)  0x162398  size 28  7 条（0x162398..0x1623b4）
 * @func 0x162398 0x1623c4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162398 mov r2, #0
 *   @0x16239c mov r3, r2
 *   @0x1623a0 movt r2, #0xbff0
 *   @0x1623a4 str r3, [r0, #0xc]
 *   @0x1623a8 str r2, [r0, #0x4]
 *   @0x1623ac str r3, [r0]
 *   @0x1623b0 bx lr
 *
 * ══ §718/828 F_SteamUGC_QueryAddExcludedTag(RValue&, CInstance*, CInstance*, int, RValue*)  0x1623b4  size 28  7 条（0x1623b4..0x1623d0）
 * @func 0x1623b4 0x1623e0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1623b4 mov r2, #0
 *   @0x1623b8 mov r3, r2
 *   @0x1623bc movt r2, #0xbff0
 *   @0x1623c0 str r3, [r0, #0xc]
 *   @0x1623c4 str r2, [r0, #0x4]
 *   @0x1623c8 str r3, [r0]
 *   @0x1623cc bx lr
 *
 * ══ §719/828 F_SteamUGC_SetReturnLongDesc(RValue&, CInstance*, CInstance*, int, RValue*)  0x1623d0  size 28  7 条（0x1623d0..0x1623ec）
 * @func 0x1623d0 0x1623fc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1623d0 mov r2, #0
 *   @0x1623d4 mov r3, r2
 *   @0x1623d8 movt r2, #0xbff0
 *   @0x1623dc str r3, [r0, #0xc]
 *   @0x1623e0 str r2, [r0, #0x4]
 *   @0x1623e4 str r3, [r0]
 *   @0x1623e8 bx lr
 *
 * ══ §720/828 F_SteamUGC_QuerySetReturnTotalOnly(RValue&, CInstance*, CInstance*, int, RValue*)  0x1623ec  size 28  7 条（0x1623ec..0x162408）
 * @func 0x1623ec 0x162418  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1623ec mov r2, #0
 *   @0x1623f0 mov r3, r2
 *   @0x1623f4 movt r2, #0xbff0
 *   @0x1623f8 str r3, [r0, #0xc]
 *   @0x1623fc str r2, [r0, #0x4]
 *   @0x162400 str r3, [r0]
 *   @0x162404 bx lr
 *
 * ══ §721/828 F_SteamUGC_QuerySetAllowCachedResponse(RValue&, CInstance*, CInstance*, int, RValue*)  0x162408  size 28  7 条（0x162408..0x162424）
 * @func 0x162408 0x162434  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162408 mov r2, #0
 *   @0x16240c mov r3, r2
 *   @0x162410 movt r2, #0xbff0
 *   @0x162414 str r3, [r0, #0xc]
 *   @0x162418 str r2, [r0, #0x4]
 *   @0x16241c str r3, [r0]
 *   @0x162420 bx lr
 *
 * ══ §722/828 F_SteamUGC_SendQuery(RValue&, CInstance*, CInstance*, int, RValue*)  0x162424  size 28  7 条（0x162424..0x162440）
 * @func 0x162424 0x162440  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162424 mov r2, #0
 *   @0x162428 mov r3, r2
 *   @0x16242c movt r2, #0xbff0
 *   @0x162430 str r3, [r0, #0xc]
 *   @0x162434 str r2, [r0, #0x4]
 *   @0x162438 str r3, [r0]
 *   @0x16243c bx lr
 *
 * ══ §723/828 CBitmap32::~CBitmap32()  0x167944  size 28  7 条（0x167944..0x167960）
 * @func 0x167944 0x167960  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::~CBitmap32() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167944 push {r4, lr}
 *   @0x167948 mov r4, r0
 *   @0x16794c bl 0x16791c <_ZN9CBitmap32D2Ev>
 *   @0x167950 mov r0, r4
 *   @0x167954 bl 0x27d1d0 <_ZdlPv>
 *   @0x167958 mov r0, r4
 *   @0x16795c pop {r4, pc}
 *
 * ══ §724/828 GR_D3D_End()  0x168c90  size 28  7 条（0x168c90..0x168cac）
 * @func 0x168c90 0x168cac  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _DestroyBlankTexture() / GR_Surface_FreeAll() / InvalidateFrozenVBs() / FreeAllVertexData()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168c90 push {r3, lr}
 *   @0x168c94 bl 0x168be0 <_Z20_DestroyBlankTexturev>
 *   @0x168c98 bl 0x171c64 <_Z18GR_Surface_FreeAllv>
 *   @0x168c9c bl 0xc8fe8 <_Z19InvalidateFrozenVBsv>
 *   @0x168ca0 bl 0x1857d4 <_Z17FreeAllVertexDatav>
 *   @0x168ca4 pop {r3, lr}
 *   @0x168ca8 b 0x17dd54 <_ZN8Graphics4QuitEv>
 *
 * ══ §725/828 GR_Draw_Clear_Alpha(unsigned int, float)  0x16a0a4  size 28  7 条（0x16a0a4..0x16a0c0）
 * @func 0x16a0a4 0x16a0c0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertAlpha(float)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a0a4 push {r4, lr}
 *   @0x16a0a8 mov r4, r0
 *   @0x16a0ac mov r0, r1
 *   @0x16a0b0 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x16a0b4 orr r0, r4, r0, lsl #24
 *   @0x16a0b8 pop {r4, lr}
 *   @0x16a0bc b 0x169f58 <_Z13GR_Draw_Clearj>
 *
 * ══ §726/828 CCameraManager::~CCameraManager()  0x16dd90  size 28  7 条（0x16dd90..0x16ddac）
 * @func 0x16dd90 0x16ddac  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::Clean() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16dd90 push {r4, lr}
 *   @0x16dd94 mov r4, r0
 *   @0x16dd98 bl 0x16dd34 <_ZN14CCameraManager5CleanEv>
 *   @0x16dd9c ldr r0, [r4, #0xc]
 *   @0x16dda0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x16dda4 mov r0, r4
 *   @0x16dda8 pop {r4, pc}
 *
 * ══ §727/828 Graphics::Flip()  0x17df14  size 28  7 条（0x17df14..0x17df30）
 * @func 0x17df14 0x17df30  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17df14 ldr r3, [pc, #0x10]
 *   @0x17df18 mov r2, #1
 *   @0x17df1c mov r0, r2
 *   @0x17df20 ldr r3, [pc, r3]
 *   @0x17df24 strb r2, [r3]
 *   @0x17df28 bx lr
 *   @0x17df2c eoreq r2, r7, r4, lsr r5
 *
 * ══ §728/828 FreeVertexFormat(VertexFormat*)  0x185640  size 28  7 条（0x185640..0x18565c）
 * @func 0x185640 0x18565c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185640 push {r4, lr}
 *   @0x185644 mov r4, r0
 *   @0x185648 ldr r0, [r0, #0xc]
 *   @0x18564c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x185650 mov r3, #0
 *   @0x185654 str r3, [r4, #0xc]
 *   @0x185658 pop {r4, pc}
 *
 * ══ §729/828 F_Dummy_Shader_Func(RValue&, CInstance*, CInstance*, int, RValue*)  0x18839c  size 28  7 条（0x18839c..0x1883b8）
 * @func 0x18839c 0x1883b8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18839c mov r2, #0
 *   @0x1883a0 mov r3, r2
 *   @0x1883a4 movt r2, #0xbff0
 *   @0x1883a8 str r3, [r0, #0xc]
 *   @0x1883ac str r2, [r0, #0x4]
 *   @0x1883b0 str r3, [r0]
 *   @0x1883b4 bx lr
 *
 * ══ §730/828 IO_Keymap_Get(int)  0x18c2e0  size 28  7 条（0x18c2e0..0x18c2fc）
 * @func 0x18c2e0 0x18c2fc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c2e0 cmp r0, #255
 *   @0x18c2e4 bxhi lr
 *   @0x18c2e8 ldr r3, [pc, #0x8]
 *   @0x18c2ec ldr r3, [pc, r3]
 *   @0x18c2f0 ldr r0, [r3, r0, lsl #2]
 *   @0x18c2f4 bx lr
 *   @0x18c2f8 eoreq r4, r6, r4, lsr #6
 *
 * ══ §731/828 HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT()  0x18d7d8  size 28  7 条（0x18d7d8..0x18d7f4）
 * @func 0x18d7d8 0x18d7f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d7d8 push {r4, lr}
 *   @0x18d7dc mov r4, r0
 *   @0x18d7e0 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev>
 *   @0x18d7e4 mov r0, r4
 *   @0x18d7e8 bl 0x27d1d0 <_ZdlPv>
 *   @0x18d7ec mov r0, r4
 *   @0x18d7f0 pop {r4, pc}
 *
 * ══ §732/828 LoadSave::yyfeof(_YYFILE*)  0x18de7c  size 28  7 条（0x18de7c..0x18de98）
 * @func 0x18de7c 0x18de98  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18de7c ldr r3, [r0]
 *   @0x18de80 ldr r0, [r3, #0x1c]
 *   @0x18de84 ldr r3, [r3, #0x10]
 *   @0x18de88 cmp r0, r3
 *   @0x18de8c movlt r0, #0
 *   @0x18de90 movge r0, #1
 *   @0x18de94 bx lr
 *
 * ══ §733/828 YYObjectBase::~YYObjectBase()  0x199304  size 28  7 条（0x199304..0x199320）
 * @func 0x199304 0x199320  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::~YYObjectBase() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199304 push {r4, lr}
 *   @0x199308 mov r4, r0
 *   @0x19930c bl 0x199110 <_ZN12YYObjectBaseD2Ev>
 *   @0x199310 mov r0, r4
 *   @0x199314 bl 0x27d1d0 <_ZdlPv>
 *   @0x199318 mov r0, r4
 *   @0x19931c pop {r4, pc}
 *
 * ══ §734/828 CInstance::~CInstance()  0x1993f8  size 28  7 条（0x1993f8..0x199414）
 * @func 0x1993f8 0x199424  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::~CInstance() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1993f8 push {r4, lr}
 *   @0x1993fc mov r4, r0
 *   @0x199400 bl 0x199320 <_ZN9CInstanceD2Ev>
 *   @0x199404 mov r0, r4
 *   @0x199408 bl 0x27d1d0 <_ZdlPv>
 *   @0x19940c mov r0, r4
 *   @0x199410 pop {r4, pc}
 *
 * ══ §735/828 Eff_Create10()  0x1a1eb0  size 28  7 条（0x1a1eb0..0x1a1ecc）
 * @func 0x1a1eb0 0x1a1ecc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1eb0 push {r3, lr}
 *   @0x1a1eb4 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a1eb8 ldr r3, [pc, #0x8]
 *   @0x1a1ebc ldr r3, [pc, r3]
 *   @0x1a1ec0 str r0, [r3]
 *   @0x1a1ec4 pop {r3, pc}
 *   @0x1a1ec8 .word 0x0024e8dc
 *
 * ══ §736/828 Eff_Create11()  0x1a2198  size 28  7 条（0x1a2198..0x1a21b4）
 * @func 0x1a2198 0x1a21b4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Create()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2198 push {r3, lr}
 *   @0x1a219c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x1a21a0 ldr r3, [pc, #0x8]
 *   @0x1a21a4 ldr r3, [pc, r3]
 *   @0x1a21a8 str r0, [r3]
 *   @0x1a21ac pop {r3, pc}
 *   @0x1a21b0 .word 0x0024e5f8
 *
 * ══ §737/828 CPath::SetPrecision(int)  0x1a6e80  size 28  7 条（0x1a6e80..0x1a6e9c）
 * @func 0x1a6e80 0x1a6e9c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::SetPrecision(int)+0x14
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6e80 cmp r1, #0
 *   @0x1a6e84 movlt r1, #0
 *   @0x1a6e88 blt 0x1a6e94 <_ZN5CPath12SetPrecisionEi+0x14>
 *   @0x1a6e8c cmp r1, #8
 *   @0x1a6e90 movge r1, #8
 *   @0x1a6e94 str r1, [r0, #0x1c]
 *   @0x1a6e98 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §738/828 CPath::Free()  0x1a6ffc  size 28  7 条（0x1a6ffc..0x1a7018）
 * @func 0x1a6ffc 0x1a7018  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::~CPath()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6ffc push {r4, lr}
 *   @0x1a7000 subs r4, r0, #0
 *   @0x1a7004 popeq {r4, pc}
 *   @0x1a7008 bl 0x1a6fe8 <_ZN5CPathD2Ev>
 *   @0x1a700c mov r0, r4
 *   @0x1a7010 pop {r4, lr}
 *   @0x1a7014 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §739/828 INITIALIZE_Path()  0x1a8518  size 28  7 条（0x1a8518..0x1a8534）
 * @func 0x1a8518 0x1a8534  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8518 ldr r3, [pc, #0x10]
 *   @0x1a851c mov r2, #0
 *   @0x1a8520 add r3, pc, r3
 *   @0x1a8524 str r2, [r3, #0x4]
 *   @0x1a8528 str r2, [r3]
 *   @0x1a852c bx lr
 *   @0x1a8530 eorseq r10, r9, r8
 *
 * ══ §740/828 TFont::~TFont()  0x1a8834  size 28  7 条（0x1a8834..0x1a8850）
 * @func 0x1a8834 0x1a8850  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TFont::~TFont() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8834 push {r4, lr}
 *   @0x1a8838 mov r4, r0
 *   @0x1a883c bl 0x1a87ec <_ZN5TFontD2Ev>
 *   @0x1a8840 mov r0, r4
 *   @0x1a8844 bl 0x27d1d0 <_ZdlPv>
 *   @0x1a8848 mov r0, r4
 *   @0x1a884c pop {r4, pc}
 *
 * ══ §741/828 TBitmap::~TBitmap()  0x1a8ab0  size 28  7 条（0x1a8ab0..0x1a8acc）
 * @func 0x1a8ab0 0x1a8acc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TBitmap::~TBitmap() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8ab0 push {r4, lr}
 *   @0x1a8ab4 mov r4, r0
 *   @0x1a8ab8 bl 0x1a8a74 <_ZN7TBitmapD2Ev>
 *   @0x1a8abc mov r0, r4
 *   @0x1a8ac0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1a8ac4 mov r0, r4
 *   @0x1a8ac8 pop {r4, pc}
 *
 * ══ §742/828 BitmapLoader::~BitmapLoader()  0x1a8b0c  size 28  7 条（0x1a8b0c..0x1a8b28）
 * @func 0x1a8b0c 0x1a8b38  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: BitmapLoader::~BitmapLoader() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8b0c push {r4, lr}
 *   @0x1a8b10 mov r4, r0
 *   @0x1a8b14 bl 0x1a8acc <_ZN12BitmapLoaderD2Ev>
 *   @0x1a8b18 mov r0, r4
 *   @0x1a8b1c bl 0x27d1d0 <_ZdlPv>
 *   @0x1a8b20 mov r0, r4
 *   @0x1a8b24 pop {r4, pc}
 *
 * ══ §743/828 IBitmap::Create()  0x1a912c  size 28  7 条（0x1a912c..0x1a9148）
 * @func 0x1a912c 0x1a9158  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / TBitmap::TBitmap()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a912c push {r4, lr}
 *   @0x1a9130 mov r0, #44
 *   @0x1a9134 bl 0x27c524 <_Znwj>
 *   @0x1a9138 mov r4, r0
 *   @0x1a913c bl 0x1a8b50 <_ZN7TBitmapC2Ev>
 *   @0x1a9140 mov r0, r4
 *   @0x1a9144 pop {r4, pc}
 *
 * ══ §744/828 RTree<CInstance*, int, float, 6, 2>::~RTree()  0x1cbe58  size 28  7 条（0x1cbe58..0x1cbe74）
 * @func 0x1cbe58 0x1cbe74  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::~RTree() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbe58 push {r4, lr}
 *   @0x1cbe5c mov r4, r0
 *   @0x1cbe60 bl 0x1cbdec <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev>
 *   @0x1cbe64 mov r0, r4
 *   @0x1cbe68 bl 0x27d1d0 <_ZdlPv>
 *   @0x1cbe6c mov r0, r4
 *   @0x1cbe70 pop {r4, pc}
 *
 * ══ §745/828 CGesture::~CGesture()  0x1d52d8  size 28  7 条（0x1d52d8..0x1d52f4）
 * @func 0x1d52d8 0x1d5304  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d52d8 push {r4, lr}
 *   @0x1d52dc mov r4, r0
 *   @0x1d52e0 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d52e4 mov r0, r4
 *   @0x1d52e8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d52ec mov r0, r4
 *   @0x1d52f0 pop {r4, pc}
 *
 * ══ §746/828 DebugScript_Load(unsigned char*, unsigned int, unsigned char*)  0x1de750  size 28  7 条（0x1de750..0x1de76c）
 * @func 0x1de750 0x1de77c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de750 ldr r3, [pc, #0x10]
 *   @0x1de754 add r2, r0, #4
 *   @0x1de758 mov r0, #1
 *   @0x1de75c ldr r3, [pc, r3]
 *   @0x1de760 str r2, [r3]
 *   @0x1de764 bx lr
 *   @0x1de768 .word 0x0020f3f0
 *
 * ══ §747/828 DebugInfo_Load(unsigned char*, unsigned int, unsigned char*)  0x1de76c  size 28  7 条（0x1de76c..0x1de788）
 * @func 0x1de76c 0x1de798  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de76c ldr r3, [pc, #0x10]
 *   @0x1de770 add r2, r0, #4
 *   @0x1de774 mov r0, #1
 *   @0x1de778 ldr r3, [pc, r3]
 *   @0x1de77c str r2, [r3]
 *   @0x1de780 bx lr
 *   @0x1de784 eoreq pc, r0, r0, ror #7
 *
 * ══ §748/828 CScript::Free()  0x1dfb8c  size 28  7 条（0x1dfb8c..0x1dfba8）
 * @func 0x1dfb8c 0x1dfba8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfb8c push {r3, lr}
 *   @0x1dfb90 subs r3, r0, #0
 *   @0x1dfb94 popeq {r3, pc}
 *   @0x1dfb98 ldr r3, [r3]
 *   @0x1dfb9c ldr r3, [r3, #0x4]
 *   @0x1dfba0 blx r3
 *   @0x1dfba4 pop {r3, pc}
 *
 * ══ §749/828 CScript::~CScript()  0x1dfc6c  size 28  7 条（0x1dfc6c..0x1dfc88）
 * @func 0x1dfc6c 0x1dfc88  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CScript::~CScript() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfc6c push {r4, lr}
 *   @0x1dfc70 mov r4, r0
 *   @0x1dfc74 bl 0x1dfc44 <_ZN7CScriptD2Ev>
 *   @0x1dfc78 mov r0, r4
 *   @0x1dfc7c bl 0x27d1d0 <_ZdlPv>
 *   @0x1dfc80 mov r0, r4
 *   @0x1dfc84 pop {r4, pc}
 *
 * ══ §750/828 CSprite::SetBoundingBoxMode(int)  0x1e35c8  size 28  7 条（0x1e35c8..0x1e35e4）
 * @func 0x1e35c8 0x1e35e4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e35c8 cmp r1, #2
 *   @0x1e35cc bxhi lr
 *   @0x1e35d0 ldr r2, [r0, #0x4]
 *   @0x1e35d4 cmp r2, r1
 *   @0x1e35d8 bxeq lr
 *   @0x1e35dc str r1, [r0, #0x4]
 *   @0x1e35e0 b 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *
 * ══ §751/828 CSprite::Free()  0x1e6340  size 28  7 条（0x1e6340..0x1e635c）
 * @func 0x1e6340 0x1e635c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6340 push {r3, lr}
 *   @0x1e6344 subs r3, r0, #0
 *   @0x1e6348 popeq {r3, pc}
 *   @0x1e634c ldr r3, [r3]
 *   @0x1e6350 ldr r3, [r3, #0x4]
 *   @0x1e6354 blx r3
 *   @0x1e6358 pop {r3, pc}
 *
 * ══ §752/828 CSprite::~CSprite()  0x1e76cc  size 28  7 条（0x1e76cc..0x1e76e8）
 * @func 0x1e76cc 0x1e76e8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::~CSprite() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e76cc push {r4, lr}
 *   @0x1e76d0 mov r4, r0
 *   @0x1e76d4 bl 0x1e76a4 <_ZN7CSpriteD2Ev>
 *   @0x1e76d8 mov r0, r4
 *   @0x1e76dc bl 0x27d1d0 <_ZdlPv>
 *   @0x1e76e0 mov r0, r4
 *   @0x1e76e4 pop {r4, pc}
 *
 * ══ §753/828 CTimeLine::Free()  0x1f16f4  size 28  7 条（0x1f16f4..0x1f1710）
 * @func 0x1f16f4 0x1f1710  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f16f4 push {r3, lr}
 *   @0x1f16f8 subs r3, r0, #0
 *   @0x1f16fc popeq {r3, pc}
 *   @0x1f1700 ldr r3, [r3]
 *   @0x1f1704 ldr r3, [r3, #0x4]
 *   @0x1f1708 blx r3
 *   @0x1f170c pop {r3, pc}
 *
 * ══ §754/828 CTimeLine::~CTimeLine()  0x1f1998  size 28  7 条（0x1f1998..0x1f19b4）
 * @func 0x1f1998 0x1f19b4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::~CTimeLine() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1998 push {r4, lr}
 *   @0x1f199c mov r4, r0
 *   @0x1f19a0 bl 0x1f1890 <_ZN9CTimeLineD2Ev>
 *   @0x1f19a4 mov r0, r4
 *   @0x1f19a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f19ac mov r0, r4
 *   @0x1f19b0 pop {r4, pc}
 *
 * ══ §755/828 CVariableList::~CVariableList()  0x1f6680  size 28  7 条（0x1f6680..0x1f669c）
 * @func 0x1f6680 0x1f669c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::~CVariableList() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6680 push {r4, lr}
 *   @0x1f6684 mov r4, r0
 *   @0x1f6688 bl 0x1f6658 <_ZN13CVariableListD2Ev>
 *   @0x1f668c mov r0, r4
 *   @0x1f6690 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6694 mov r0, r4
 *   @0x1f6698 pop {r4, pc}
 *
 * ══ §756/828 MyZAlloc(void*, unsigned int, unsigned int)  0x2010c8  size 28  7 条（0x2010c8..0x2010e4）
 * @func 0x2010c8 0x2010e4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2010c8 mul r0, r2, r1
 *   @0x2010cc ldr r1, [pc, #0xc]
 *   @0x2010d0 mov r3, #1
 *   @0x2010d4 mov r2, #796
 *   @0x2010d8 add r1, pc, r1
 *   @0x2010dc b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2010e0 andseq r2, r5, r0, asr r6
 *
 * ══ §757/828 CStream::Free()  0x20133c  size 28  7 条（0x20133c..0x201358）
 * @func 0x20133c 0x201358  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::~CStream()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20133c push {r4, lr}
 *   @0x201340 subs r4, r0, #0
 *   @0x201344 popeq {r4, pc}
 *   @0x201348 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20134c mov r0, r4
 *   @0x201350 pop {r4, lr}
 *   @0x201354 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §758/828 CStream::CopyFrom(CStream*, long long)  0x20170c  size 28  7 条（0x20170c..0x201728）
 * @func 0x20170c 0x201728  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::CopyFrom(CStream*, long long, bool)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20170c str lr, [sp, #-0x4]!
 *   @0x201710 sub sp, sp, #12
 *   @0x201714 mov r12, #0
 *   @0x201718 str r12, [sp]
 *   @0x20171c bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb>
 *   @0x201720 add sp, sp, #12
 *   @0x201724 ldr pc, [sp], #4
 *
 * ══ §759/828 DS_SetPrecision(double)  0x2026a8  size 28  7 条（0x2026a8..0x2026c4）
 * @func 0x2026a8 0x2026c4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2026a8 vmov d6, r0, r1
 *   @0x2026ac ldr r3, [pc, #0xc]
 *   @0x2026b0 vabs.f64 d7, d6
 *   @0x2026b4 ldr r3, [pc, r3]
 *   @0x2026b8 vstr d7, [r3]
 *   @0x2026bc bx lr
 *   @0x2026c0 ldrsbeq lr, [lr], -r0
 *
 * ══ §760/828 CDS_Stack::Top()  0x202d24  size 28  7 条（0x202d24..0x202d40）
 * @func 0x202d24 0x202d40  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202d24 ldr r3, [r0, #0x4]
 *   @0x202d28 cmp r3, #0
 *   @0x202d2c subne r3, r3, #-268435455
 *   @0x202d30 ldrne r2, [r0, #0xc]
 *   @0x202d34 addne r0, r2, r3, lsl #4
 *   @0x202d38 moveq r0, r3
 *   @0x202d3c bx lr
 *
 * ══ §761/828 CDS_Priority::~CDS_Priority()  0x209a5c  size 28  7 条（0x209a5c..0x209a78）
 * @func 0x209a5c 0x209a78  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::~CDS_Priority() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x209a5c push {r4, lr}
 *   @0x209a60 mov r4, r0
 *   @0x209a64 bl 0x209a34 <_ZN12CDS_PriorityD2Ev>
 *   @0x209a68 mov r0, r4
 *   @0x209a6c bl 0x27d1d0 <_ZdlPv>
 *   @0x209a70 mov r0, r4
 *   @0x209a74 pop {r4, pc}
 *
 * ══ §762/828 CDS_Grid::~CDS_Grid()  0x20b260  size 28  7 条（0x20b260..0x20b27c）
 * @func 0x20b260 0x20b27c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::SetSize(int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b260 mov r1, #0
 *   @0x20b264 push {r4, lr}
 *   @0x20b268 mov r2, r1
 *   @0x20b26c mov r4, r0
 *   @0x20b270 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii>
 *   @0x20b274 mov r0, r4
 *   @0x20b278 pop {r4, pc}
 *
 * ══ §763/828 CDS_List::~CDS_List()  0x20eab0  size 28  7 条（0x20eab0..0x20eacc）
 * @func 0x20eab0 0x20eacc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::~CDS_List() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20eab0 push {r4, lr}
 *   @0x20eab4 mov r4, r0
 *   @0x20eab8 bl 0x20ea78 <_ZN8CDS_ListD2Ev>
 *   @0x20eabc mov r0, r4
 *   @0x20eac0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20eac4 mov r0, r4
 *   @0x20eac8 pop {r4, pc}
 *
 * ══ §764/828 CDS_Queue::~CDS_Queue()  0x20f254  size 28  7 条（0x20f254..0x20f270）
 * @func 0x20f254 0x20f270  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Queue::~CDS_Queue() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f254 push {r4, lr}
 *   @0x20f258 mov r4, r0
 *   @0x20f25c bl 0x20f21c <_ZN9CDS_QueueD2Ev>
 *   @0x20f260 mov r0, r4
 *   @0x20f264 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f268 mov r0, r4
 *   @0x20f26c pop {r4, pc}
 *
 * ══ §765/828 CDS_Stack::~CDS_Stack()  0x20f990  size 28  7 条（0x20f990..0x20f9ac）
 * @func 0x20f990 0x20f9ac  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Stack::~CDS_Stack() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f990 push {r4, lr}
 *   @0x20f994 mov r4, r0
 *   @0x20f998 bl 0x20f968 <_ZN9CDS_StackD2Ev>
 *   @0x20f99c mov r0, r4
 *   @0x20f9a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f9a4 mov r0, r4
 *   @0x20f9a8 pop {r4, pc}
 *
 * ══ §766/828 SND_End()  0x21e9d0  size 28  7 条（0x21e9d0..0x21e9ec）
 * @func 0x21e9d0 0x21e9ec  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SoundHardware::Quit()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e9d0 push {r3, lr}
 *   @0x21e9d4 ldr r3, [pc, #0xc]
 *   @0x21e9d8 ldr r0, [pc, r3]
 *   @0x21e9dc bl 0x220324 <_ZN13SoundHardware4QuitEv>
 *   @0x21e9e0 mov r0, #1
 *   @0x21e9e4 pop {r3, pc}
 *   @0x21e9e8 subseq r6, r3, r12, asr #18
 *
 * ══ §767/828 ogg_stream_eos  0x234ae8  size 28  7 条（0x234ae8..0x234b04）
 * @func 0x234ae8 0x234b04  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234ae8 push {r4, lr}
 *   @0x234aec mov r4, r0
 *   @0x234af0 bl 0x23412c <ogg_stream_check>
 *   @0x234af4 cmp r0, #0
 *   @0x234af8 ldreq r0, [r4, #0x148]
 *   @0x234afc movne r0, #1
 *   @0x234b00 pop {r4, pc}
 *
 * ══ §768/828 IniFile::ReadString(char const*, char const*, char const*)  0x235b78  size 28  7 条（0x235b78..0x235b94）
 * @func 0x235b78 0x235b94  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235b78 push {r4, lr}
 *   @0x235b7c mov r4, r3
 *   @0x235b80 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x235b84 cmp r0, #0
 *   @0x235b88 ldrne r0, [r0, #0x8]
 *   @0x235b8c moveq r0, r4
 *   @0x235b90 pop {r4, pc}
 *
 * ══ §769/828 CPhysicsWorld::GetParticleGroupCount(int)  0x23a5d4  size 28  7 条（0x23a5d4..0x23a5f0）
 * @func 0x23a5d4 0x23a5f0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a5d4 push {r3, lr}
 *   @0x23a5d8 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a5dc cmp r0, #0
 *   @0x23a5e0 ldrne r2, [r0, #0x8]
 *   @0x23a5e4 ldrne r3, [r0, #0x4]
 *   @0x23a5e8 rsbne r0, r3, r2
 *   @0x23a5ec pop {r3, pc}
 *
 * ══ §770/828 utf8_tolower(int)  0x23f8b8  size 28  7 条（0x23f8b8..0x23f8d4）
 * @func 0x23f8b8 0x23f8e4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8proc_get_property(int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f8b8 push {r4, lr}
 *   @0x23f8bc mov r4, r0
 *   @0x23f8c0 bl 0x23f854 <_Z21utf8proc_get_propertyi>
 *   @0x23f8c4 ldr r0, [r0, #0x14]
 *   @0x23f8c8 cmp r0, #0
 *   @0x23f8cc movlt r0, r4
 *   @0x23f8d0 pop {r4, pc}
 *
 * ══ §771/828 utf8_toupper(int)  0x23f8d4  size 28  7 条（0x23f8d4..0x23f8f0）
 * @func 0x23f8d4 0x23f8f0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8proc_get_property(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f8d4 push {r4, lr}
 *   @0x23f8d8 mov r4, r0
 *   @0x23f8dc bl 0x23f854 <_Z21utf8proc_get_propertyi>
 *   @0x23f8e0 ldr r0, [r0, #0x10]
 *   @0x23f8e4 cmp r0, #0
 *   @0x23f8e8 movlt r0, r4
 *   @0x23f8ec pop {r4, pc}
 *
 * ══ §772/828 JS_Date_now(RValue&, CInstance*, CInstance*, int, RValue*)  0x2449b8  size 28  7 条（0x2449b8..0x2449d4）
 * @func 0x2449b8 0x2449d4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DateGetNow()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2449b8 push {r4, lr}
 *   @0x2449bc mov r3, #0
 *   @0x2449c0 str r3, [r0, #0xc]
 *   @0x2449c4 mov r4, r0
 *   @0x2449c8 bl 0x244988 <_Z10DateGetNowv>
 *   @0x2449cc stm r4, {r0, r1}
 *   @0x2449d0 pop {r4, pc}
 *
 * ══ §773/828 pcre_free_substring_list  0x25f5cc  size 28  7 条（0x25f5cc..0x25f5e8）
 * @func 0x25f5cc 0x25f5e8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f5cc push {r3, lr}
 *   @0x25f5d0 ldr r3, [pc, #0xc]
 *   @0x25f5d4 ldr r3, [pc, r3]
 *   @0x25f5d8 ldr r3, [r3]
 *   @0x25f5dc blx r3
 *   @0x25f5e0 pop {r3, pc}
 *   @0x25f5e4 ldrheq r1, [r9], -r4
 *
 * ══ §774/828 MemoryManager::Memory_Tick()  0x27d23c  size 28  7 条（0x27d23c..0x27d258）
 * @func 0x27d23c 0x27d258  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d23c ldr r3, [pc, #0x10]
 *   @0x27d240 ldr r3, [pc, r3]
 *   @0x27d244 ldr r2, [r3]
 *   @0x27d248 add r2, r2, #1
 *   @0x27d24c str r2, [r3]
 *   @0x27d250 bx lr
 *   @0x27d254 andseq r4, r7, r12, lsl r6
 *
 * ══ §775/828 anon_27e7f4  0x27e7f4  size 28  7 条（0x27e7f4..0x27e810）
 * @func 0x27e7f4 0x27e810  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e7f4 push {r4, lr}
 *   @0x27e7f8 mov r4, r0
 *   @0x27e7fc ldr r0, [r0]
 *   @0x27e800 bl 0xb655c <free@plt>
 *   @0x27e804 ldr r0, [r4, #0x4]
 *   @0x27e808 pop {r4, lr}
 *   @0x27e80c b 0x27e7c8 <json_object_put>
 *
 * ══ §776/828 json_object_get_array  0x27edcc  size 28  7 条（0x27edcc..0x27ede8）
 * @func 0x27edcc 0x27ede8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27edcc cmp r0, #0
 *   @0x27edd0 bxeq lr
 *   @0x27edd4 ldr r3, [r0]
 *   @0x27edd8 cmp r3, #5
 *   @0x27eddc ldreq r0, [r0, #0x18]
 *   @0x27ede0 movne r0, #0
 *   @0x27ede4 bx lr
 *
 * ══ §777/828 spAttachmentLoader_configureAttachment  0x284db8  size 28  7 条（0x284db8..0x284dd4）
 * @func 0x284db8 0x284de4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284db8 push {r3, lr}
 *   @0x284dbc ldr r3, [r0, #0x8]
 *   @0x284dc0 ldr r3, [r3, #0x4]
 *   @0x284dc4 cmp r3, #0
 *   @0x284dc8 popeq {r3, pc}
 *   @0x284dcc blx r3
 *   @0x284dd0 pop {r3, pc}
 *
 * ══ §778/828 spAttachmentLoader_disposeAttachment  0x284dd4  size 28  7 条（0x284dd4..0x284df0）
 * @func 0x284dd4 0x284df0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284dd4 push {r3, lr}
 *   @0x284dd8 ldr r3, [r0, #0x8]
 *   @0x284ddc ldr r3, [r3, #0x8]
 *   @0x284de0 cmp r3, #0
 *   @0x284de4 popeq {r3, pc}
 *   @0x284de8 blx r3
 *   @0x284dec pop {r3, pc}
 *
 * ══ §779/828 spBoneData_dispose  0x285ac4  size 28  7 条（0x285ac4..0x285ae0）
 * @func 0x285ac4 0x285ae0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285ac4 push {r4, lr}
 *   @0x285ac8 mov r4, r0
 *   @0x285acc ldr r0, [r0, #0x4]
 *   @0x285ad0 bl 0x285c80 <_free>
 *   @0x285ad4 mov r0, r4
 *   @0x285ad8 pop {r4, lr}
 *   @0x285adc b 0x285c80 <_free>
 *
 * ══ §780/828 spEvent_dispose  0x285b78  size 28  7 条（0x285b78..0x285b94）
 * @func 0x285b78 0x285b94  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285b78 push {r4, lr}
 *   @0x285b7c mov r4, r0
 *   @0x285b80 ldr r0, [r0, #0x10]
 *   @0x285b84 bl 0x285c80 <_free>
 *   @0x285b88 mov r0, r4
 *   @0x285b8c pop {r4, lr}
 *   @0x285b90 b 0x285c80 <_free>
 *
 * ══ §781/828 Json_getString  0x287428  size 28  7 条（0x287428..0x287444）
 * @func 0x287428 0x287454  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Json_getItem
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287428 push {r4, lr}
 *   @0x28742c mov r4, r2
 *   @0x287430 bl 0x2873c4 <Json_getItem>
 *   @0x287434 cmp r0, #0
 *   @0x287438 ldrne r0, [r0, #0x10]
 *   @0x28743c moveq r0, r4
 *   @0x287440 pop {r4, pc}
 *
 * ══ §782/828 Json_getFloat  0x287444  size 28  7 条（0x287444..0x287460）
 * @func 0x287444 0x287470  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Json_getItem
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287444 push {r4, lr}
 *   @0x287448 mov r4, r2
 *   @0x28744c bl 0x2873c4 <Json_getItem>
 *   @0x287450 cmp r0, #0
 *   @0x287454 ldrne r0, [r0, #0x18]
 *   @0x287458 moveq r0, r4
 *   @0x28745c pop {r4, pc}
 *
 * ══ §783/828 Json_getInt  0x287460  size 28  7 条（0x287460..0x28747c）
 * @func 0x287460 0x28747c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Json_getItem
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287460 push {r4, lr}
 *   @0x287464 mov r4, r2
 *   @0x287468 bl 0x2873c4 <Json_getItem>
 *   @0x28746c cmp r0, #0
 *   @0x287470 ldrne r0, [r0, #0x14]
 *   @0x287474 moveq r0, r4
 *   @0x287478 pop {r4, pc}
 *
 * ══ §784/828 spSkeletonData_create  0x28addc  size 28  7 条（0x28addc..0x28adf8）
 * @func 0x28addc 0x28adf8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28addc ldr r2, [pc, #0x10]
 *   @0x28ade0 mov r0, #1
 *   @0x28ade4 mov r1, #84
 *   @0x28ade8 mov r3, #37
 *   @0x28adec add r2, pc, r2
 *   @0x28adf0 b 0x285c4c <_calloc>
 *   @0x28adf4 strheq r12, [r12], -r12
 *
 * ══ §785/828 spSlot_setAttachmentTime  0x28ee48  size 28  7 条（0x28ee48..0x28ee64）
 * @func 0x28ee48 0x28ee74  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ee48 ldr r3, [r0, #0x4]
 *   @0x28ee4c vmov s14, r1
 *   @0x28ee50 ldr r3, [r3, #0x4]
 *   @0x28ee54 vldr s15, [r3, #76]
 *   @0x28ee58 vsub.f32 s15, s15, s14
 *   @0x28ee5c vstr s15, [r0, #40]
 *   @0x28ee60 bx lr
 *
 * ══ §786/828 spSlot_getAttachmentTime  0x28ee64  size 28  7 条（0x28ee64..0x28ee80）
 * @func 0x28ee64 0x28ee80  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ee64 ldr r3, [r0, #0x4]
 *   @0x28ee68 vldr s15, [r0, #40]
 *   @0x28ee6c ldr r3, [r3, #0x4]
 *   @0x28ee70 vldr s14, [r3, #76]
 *   @0x28ee74 vsub.f32 s15, s14, s15
 *   @0x28ee78 vmov r0, s15
 *   @0x28ee7c bx lr
 *
 * ══ §787/828 Java_com_yoyogames_runner_RunnerJNILib_SetAchievementsAvailable  0x292a7c  size 28  7 条（0x292a7c..0x292a98）
 * @func 0x292a7c 0x292a98  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292a7c push {r4, lr}
 *   @0x292a80 mov r4, r2
 *   @0x292a84 bl 0x290614 <setJNIEnv>
 *   @0x292a88 adds r0, r4, #0
 *   @0x292a8c pop {r4, lr}
 *   @0x292a90 movne r0, #1
 *   @0x292a94 b 0x159a60 <_Z21Set_AchievementSystemb>
 *
 * ══ §788/828 Debug_SetRoomSpeedWait(int)  0x29c6c0  size 28  7 条（0x29c6c0..0x29c6dc）
 * @func 0x29c6c0 0x29c6dc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c6c0 ldr r3, [pc, #0x10]
 *   @0x29c6c4 adds r0, r0, #0
 *   @0x29c6c8 ldr r3, [pc, r3]
 *   @0x29c6cc movne r0, #1
 *   @0x29c6d0 strb r0, [r3]
 *   @0x29c6d4 bx lr
 *   @0x29c6d8 ldrsbeq r4, [r5], -r8
 *
 * ══ §789/828 CProfiler::Enable(bool)  0x2a04d8  size 28  7 条（0x2a04d8..0x2a04f4）
 * @func 0x2a04d8 0x2a04f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a04d8 cmp r1, #0
 *   @0x2a04dc strb r1, [r0, #0x11]
 *   @0x2a04e0 ldreq r3, [pc, #0x8]
 *   @0x2a04e4 ldreq r3, [pc, r3]
 *   @0x2a04e8 strbeq r1, [r3]
 *   @0x2a04ec bx lr
 *   @0x2a04f0 andseq sp, r4, r4, lsl #13
 *
 * ══ §790/828 _zip_read4(unsigned char**)  0x2a3ed2  size 28  7 条（0x2a3ed2..0x2a3eee）
 * @func 0x2a3ed2 0x2a3eee  size 28  7 条
 * 部分覆盖: 本节 7/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3ed2 ldr r3, [r0]
 *   @0x2a3ed6 ldrb r2, [r3, #0x2]
 *   @0x2a3eda ldmdavc r10, {r0, r8, sp} ^
 *   @0x2a3ede add.w r1, r2, r1, lsl #8
 *   @0x2a3ee2 ldrb r2, [r3], #4
 *   @0x2a3ee6 str r3, [r0]
 *   @0x2a3eea ldrbmi r2, [r0, -r1]!
 *
 * ══ §791/828 png_read_data  0x2a8030  size 28  7 条（0x2a8030..0x2a804c）
 * @func 0x2a8030 0x2a804c  size 28  7 条
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x2fc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8030 push {r3, lr}
 *   @0x2a8034 .word 0xb10b3114
 *   @0x2a8038 blx r3
 *   @0x2a803c ldr r1, [pc, #0x8]
 *   @0x2a8040 ldrbtmi r4, [r9], #-8
 *   @0x2a8044 b.w 0x2a642c <png_error>
 *   @0x2a8048 ldr r0, [pc, #0x2fc]
 *
 * ══ §792/828 png_set_expand_gray_1_2_4_to_8  0x2a87d0  size 28  7 条（0x2a87d0..0x2a87ec）
 * @func 0x2a87d0 0x2a87fc  size 44  11 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a87d0 cbz r0, 0x2a87ea <png_set_expand_gray_1_2_4_to_8+0x1a>
 *   @0x2a87d4 vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2a87d8 .word 0xf8c05380
 *   @0x2a87dc .word 0xf8d03134
 *   @0x2a87e0 .word 0xf0233130
 *   @0x2a87e4 .word 0xf8c00340
 *   @0x2a87e8 .word 0x47703130
 *
 * ══ §793/828 png_set_shift  0x2af796  size 28  7 条（0x2af796..0x2af7b2）
 * @func 0x2af796 0x2af7c2  size 44  11 条
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af796 cbz r0, 0x2af7b0 <png_set_shift+0x1a>
 *   @0x2af79a .word 0xf0433134
 *   @0x2af79e .word 0xf8c00308
 *   @0x2af7a2 stmdavs r11, {r2, r4, r5, r8, r12, sp}
 *   @0x2af7a6 str.w r3, [r0, #0x245]
 *   @0x2af7aa ldrb r3, [r1, #0x4]
 *   @0x2af7ae ldrbmi r3, [r0, -r9, asr #4]!
 *
 * ══ §794/828 png_set_interlace_handling  0x2af7b2  size 28  7 条（0x2af7b2..0x2af7ce）
 * @func 0x2af7b2 0x2af7ce  size 28  7 条
 * 部分覆盖: 本节 7/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af7b2 cbz r0, 0x2af7ca <png_set_interlace_handling+0x18>
 *   @0x2af7b6 teqlt r11, r7, ror #3
 *   @0x2af7ba ldr.w r3, [r0, #0x134]
 *   @0x2af7be orr r3, r3, #0x2
 *   @0x2af7c2 str.w r3, [r0, #0x134]
 *   @0x2af7c6 movs r0, #0x7
 *   @0x2af7ca movs r0, #0x1
 *
 * ══ §795/828 png_write_data  0x2afbf0  size 28  7 条（0x2afbf0..0x2afc0c）
 * @func 0x2afbf0 0x2afc0c  size 28  7 条
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afbf0 push {r3, lr}
 *   @0x2afbf4 .word 0xb10b3110
 *   @0x2afbf8 blx r3
 *   @0x2afbfc ldr r1, [pc, #0x8]
 *   @0x2afc00 ldrbtmi r4, [r9], #-8
 *   @0x2afc04 b.w 0x2a642c <png_error>
 *   @0x2afc08 b 0x2b00b8 <png_write_end+0x8c>
 *
 * ══ §796/828 jround_up  0x2bc800  size 28  7 条（0x2bc800..0x2bc81c）
 * @func 0x2bc800 0x2bc81c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc800 push {r4, lr}
 *   @0x2bc804 sub r4, r1, #1
 *   @0x2bc808 add r4, r4, r0
 *   @0x2bc80c mov r0, r4
 *   @0x2bc810 bl 0x318dec <__aeabi_idivmod>
 *   @0x2bc814 rsb r0, r1, r4
 *   @0x2bc818 pop {r4, pc}
 *
 * ══ §797/828 b2ChainShape::~b2ChainShape()  0x2c49a4  size 28  7 条（0x2c49a4..0x2c49c0）
 * @func 0x2c49a4 0x2c49c0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ChainShape::~b2ChainShape() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c49a4 push {r4, lr}
 *   @0x2c49a8 mov r4, r0
 *   @0x2c49ac bl 0x2c4958 <_ZN12b2ChainShapeD2Ev>
 *   @0x2c49b0 mov r0, r4
 *   @0x2c49b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2c49b8 mov r0, r4
 *   @0x2c49bc pop {r4, pc}
 *
 * ══ §798/828 b2ChainShape::SetPrevVertex(b2Vec2 const&)  0x2c4bbc  size 28  7 条（0x2c4bbc..0x2c4bd8）
 * @func 0x2c4bbc 0x2c4be8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4bbc mov r3, r0
 *   @0x2c4bc0 ldm r1, {r0, r1}
 *   @0x2c4bc4 add r2, r3, #20
 *   @0x2c4bc8 mov r12, #1
 *   @0x2c4bcc stm r2, {r0, r1}
 *   @0x2c4bd0 strb r12, [r3, #0x24]
 *   @0x2c4bd4 bx lr
 *
 * ══ §799/828 b2ChainShape::SetNextVertex(b2Vec2 const&)  0x2c4bd8  size 28  7 条（0x2c4bd8..0x2c4bf4）
 * @func 0x2c4bd8 0x2c4bf4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4bd8 mov r3, r0
 *   @0x2c4bdc ldm r1, {r0, r1}
 *   @0x2c4be0 add r2, r3, #28
 *   @0x2c4be4 mov r12, #1
 *   @0x2c4be8 stm r2, {r0, r1}
 *   @0x2c4bec strb r12, [r3, #0x25]
 *   @0x2c4bf0 bx lr
 *
 * ══ §800/828 b2MotorJoint::GetAnchorA() const  0x2cdfc4  size 28  7 条（0x2cdfc4..0x2cdfe0）
 * @func 0x2cdfc4 0x2cdff0  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdfc4 ldr r2, [r1, #0x30]
 *   @0x2cdfc8 mov r3, r0
 *   @0x2cdfcc add r2, r2, #12
 *   @0x2cdfd0 ldm r2, {r0, r1}
 *   @0x2cdfd4 stm r3, {r0, r1}
 *   @0x2cdfd8 mov r0, r3
 *   @0x2cdfdc bx lr
 *
 * ══ §801/828 b2MotorJoint::GetAnchorB() const  0x2cdfe0  size 28  7 条（0x2cdfe0..0x2cdffc）
 * @func 0x2cdfe0 0x2ce00c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdfe0 ldr r2, [r1, #0x34]
 *   @0x2cdfe4 mov r3, r0
 *   @0x2cdfe8 add r2, r2, #12
 *   @0x2cdfec ldm r2, {r0, r1}
 *   @0x2cdff0 stm r3, {r0, r1}
 *   @0x2cdff4 mov r0, r3
 *   @0x2cdff8 bx lr
 *
 * ══ §802/828 b2RevoluteJoint::GetJointSpeed() const  0x2d2128  size 28  7 条（0x2d2128..0x2d2144）
 * @func 0x2d2128 0x2d2144  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2128 ldr r3, [r0, #0x34]
 *   @0x2d212c vldr s14, [r3, #88]
 *   @0x2d2130 ldr r3, [r0, #0x30]
 *   @0x2d2134 vldr s15, [r3, #88]
 *   @0x2d2138 vsub.f32 s15, s14, s15
 *   @0x2d213c vmov r0, s15
 *   @0x2d2140 bx lr
 *
 * ══ §803/828 b2WheelJoint::GetJointSpeed() const  0x2d4380  size 28  7 条（0x2d4380..0x2d439c）
 * @func 0x2d4380 0x2d439c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x30×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4380 ldr r3, [r0, #0x34]
 *   @0x2d4384 vldr s14, [r3, #88]
 *   @0x2d4388 ldr r3, [r0, #0x30]
 *   @0x2d438c vldr s15, [r3, #88]
 *   @0x2d4390 vsub.f32 s15, s14, s15
 *   @0x2d4394 vmov r0, s15
 *   @0x2d4398 bx lr
 *
 * ══ §804/828 b2GearJoint::GetReactionTorque(float) const  0x2e3ad8  size 28  7 条（0x2e3ad8..0x2e3af4）
 * @func 0x2e3ad8 0x2e3af4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3ad8 vldr s14, [r0, #156]
 *   @0x2e3adc vldr s15, [r0, #256]
 *   @0x2e3ae0 vmul.f32 s15, s14, s15
 *   @0x2e3ae4 vmov s14, r1
 *   @0x2e3ae8 vmul.f32 s14, s14, s15
 *   @0x2e3aec vmov r0, s14
 *   @0x2e3af0 bx lr
 *
 * ══ §805/828 FT_MulFix  0x2e4e4c  size 28  7 条（0x2e4e4c..0x2e4e68）
 * @func 0x2e4e4c 0x2e4e68  size 28  7 条
 * 部分覆盖: 本节 7/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4e4c smull r3, r2, r1, r0
 *   @0x2e4e50 asr.w r0, r2, #0x1f
 *   @0x2e4e54 add.w r0, r0, #0x8000
 *   @0x2e4e58 adds r3, r3, r0
 *   @0x2e4e5c b 0x16a5664 <b2_toiTime+0xf4c1c0>
 *   @0x2e4e60 b 0x12f4eb4 <b2_toiTime+0xb9ba10>
 *   @0x2e4e64 ldrbmi r4, [r0, -r2]!
 *
 * ══ §806/828 FT_GlyphLoader_Prepare  0x2e52dc  size 28  7 条（0x2e52dc..0x2e52f8）
 * @func 0x2e52dc 0x2e52f8  size 28  7 条
 * 部分覆盖: 本节 7/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x38
 * 字段偏移 top8: 0x38×1 / 0x30×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e52dc movs r3, #0x0
 *   @0x2e52e0 push {r4, lr}
 *   @0x2e52e4 strh r3, [r0, #0x38]
 *   @0x2e52e8 bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40>
 *   @0x2e52ec ldr r2, [r4, #0x30]
 *   @0x2e52f0 add.w r3, r3, r2, lsl #5
 *   @0x2e52f4 str r3, [r4, #0x58]
 *
 * ══ §807/828 FT_Face_GetVariantSelectors  0x2e5dc2  size 28  7 条（0x2e5dc2..0x2e5dde）
 * @func 0x2e5dc2 0x2e5dee  size 44  11 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5dc2 push {r4, lr}
 *   @0x2e5dc6 cbnz r0, 0x2e5dcc <FT_Face_GetVariantSelectors+0xa>
 *   @0x2e5dca pop {r4, pc}
 *   @0x2e5dce stmdahs r0, {r2, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e5dd2 beq 0x2e5dc8 <FT_Face_GetVariantSelectors+0x6>
 *   @0x2e5dd6 ldr r1, [r4, #0x64]
 *   @0x2e5dda blx r3
 *
 * ══ §808/828 FT_GlyphLoader_New  0x2e714c  size 28  7 条（0x2e714c..0x2e7168）
 * @func 0x2e714c 0x2e7168  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3670f8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e714c push {r0, r1, r2, r4, r5, lr}
 *   @0x2e7150 add r2, sp, #0x4
 *   @0x2e7154 mov r5, r0
 *   @0x2e7158 blls 0x3670f8 <_ZTS12CDS_Priority+0x9150>
 *   @0x2e715c cbnz r3, 0x2e7162 <FT_GlyphLoader_New+0x16>
 *   @0x2e7160 str r0, [r4]
 *   @0x2e7164 add sp, #0xc
 *
 * ══ §809/828 FT_Stream_ExitFrame  0x2e7eb8  size 28  7 条（0x2e7eb8..0x2e7ed4）
 * @func 0x2e7eb8 0x2e7ed4  size 28  7 条
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free
 * 字段偏移 top8: 0x14×1 / 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7eb8 push {r4, lr}
 *   @0x2e7ebc ldr r3, [r0, #0x14]
 *   @0x2e7ec0 ldr r0, [r0, #0x1c]
 *   @0x2e7ec4 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7ec8 movs r3, #0x0
 *   @0x2e7ecc movs r3, #0x0
 *   @0x2e7ed0 str r3, [r4, #0x24]
 *
 * ══ §810/828 __gnu_Unwind_ForcedUnwind  0x319b10  size 28  7 条（0x319b10..0x319b2c）
 * @func 0x319b10 0x319b2c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x3c×1 / 0xc×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319b10 str r2, [r0, #0x18]
 *   @0x319b14 ldr r2, [r3, #0x3c]
 *   @0x319b18 str r1, [r0, #0xc]
 *   @0x319b1c mov r1, r3
 *   @0x319b20 str r2, [r3, #0x40]
 *   @0x319b24 mov r2, #0
 *   @0x319b28 b 0x319940 <__gnu_uldivmod_helper+0x34c>
 *
 * ══ §811/828 _Unwind_GetLanguageSpecificData  0x31ab08  size 28  7 条（0x31ab08..0x31ab24）
 * @func 0x31ab08 0x31ab24  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x31a738
 * 字段偏移 top8: 0x4c×1 / 0x7×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ab08 push {r3, lr}
 *   @0x31ab0c bl 0x31a738 <___Unwind_Backtrace+0xac>
 *   @0x31ab10 ldr r3, [r0, #0x4c]
 *   @0x31ab14 ldrb r2, [r3, #0x7]
 *   @0x31ab18 add r0, r3, r2, lsl #2
 *   @0x31ab1c add r0, r0, #8
 *   @0x31ab20 pop {r3, pc}
 *
 * ══ §812/828 png_get_sPLT  0x2a6906  size 26  7 条（0x2a6906..0x2a6920）
 * @func 0x2a6906 0x2a6930  size 42  11 条
 * 部分覆盖: 本节 8/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6906 cbz r0, 0x2a691e <png_get_sPLT+0x18>
 *   @0x2a690a cbz r2, 0x2a691c <png_get_sPLT+0x16>
 *   @0x2a690e ldrsbvs r3, [r3], -r4
 *   @0x2a6912 ldr.w r0, [r1, #0xd8]
 *   @0x2a6916 bx lr
 *   @0x2a691a bx lr
 *   @0x2a691e bx lr
 *
 * ══ §813/828 png_get_unknown_chunks  0x2a6ba4  size 26  7 条（0x2a6ba4..0x2a6bbe）
 * @func 0x2a6ba4 0x2a6bc0  size 28  7 条
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6ba4 cbz r0, 0x2a6bbc <png_get_unknown_chunks+0x18>
 *   @0x2a6ba8 cbz r2, 0x2a6bba <png_get_unknown_chunks+0x16>
 *   @0x2a6bac ldrhvs r3, [r3], -r12
 *   @0x2a6bb0 ldr.w r0, [r1, #0xc0]
 *   @0x2a6bb4 bx lr
 *   @0x2a6bb8 bx lr
 *   @0x2a6bbc bx lr
 *
 * ══ §814/828 png_free  0x2a6cfc  size 26  7 条（0x2a6cfc..0x2a6d16）
 * @func 0x2a6cfc 0x2a6d26  size 42  11 条
 * 部分覆盖: 本节 8/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6cfc push {r3, lr}
 *   @0x2a6d00 cbz r1, 0x2a6d14 <png_free+0x18>
 *   @0x2a6d04 strdlt r3, r4, [r11, -r0]
 *   @0x2a6d08 blx r3
 *   @0x2a6d0c pop.w {r3, lr}
 *   @0x2a6d10 b.w 0x2a6cf0 <png_free_default>
 *   @0x2a6d14 pop {r3, pc}
 *
 * ══ §815/828 png_set_gray_to_rgb  0x2a880a  size 26  7 条（0x2a880a..0x2a8824）
 * @func 0x2a880a 0x2a8826  size 28  7 条
 * 部分覆盖: 本节 7/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a880a ldr.w r3, [r0, #0x134]
 *   @0x2a880e orr r3, r3, #0x4000
 *   @0x2a8812 str.w r3, [r0, #0x134]
 *   @0x2a8816 ldr.w r3, [r0, #0x130]
 *   @0x2a881a bic r3, r3, #0x40
 *   @0x2a881e str.w r3, [r0, #0x130]
 *   @0x2a8822 bx lr
 *
 * ══ §816/828 png_convert_from_time_t  0x2b0168  size 26  7 条（0x2b0168..0x2b0182）
 * @func 0x2b0168 0x2b0184  size 28  7 条
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0168 push {r0, r1, r4, lr}
 *   @0x2b016c add r0, sp, #0x8
 *   @0x2b0170 .word 0xf6061d04
 *   @0x2b0174 strmi lr, [r1], -r12, ror #29
 *   @0x2b0178 mov r0, r4
 *   @0x2b017c andlt pc, r2, r5, ror #31
 *   @0x2b0180 pop {r4, pc}
 *
 * ══ §817/828 FT_GlyphLoader_Done  0x2e738c  size 26  7 条（0x2e738c..0x2e73a6）
 * @func 0x2e738c 0x2e73a8  size 28  7 条
 * 部分覆盖: 本节 7/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_GlyphLoader_Reset
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e738c push {r3, r4, r5, lr}
 *   @0x2e7390 cbz r0, 0x2e73a4 <FT_GlyphLoader_Done+0x18>
 *   @0x2e7394 bl 0x2e7340 <FT_GlyphLoader_Reset>
 *   @0x2e7398 mov r1, r4
 *   @0x2e739c pop.w {r3, r4, r5, lr}
 *   @0x2e73a0 b.w 0x2e7336 <ft_mem_free>
 *   @0x2e73a4 pop {r3, r4, r5, pc}
 *
 * ══ §818/828 FT_List_Remove  0x2e89f2  size 26  7 条（0x2e89f2..0x2e8a0c）
 * @func 0x2e89f2 0x2e8a0e  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e89f2 cbz r0, 0x2e8a0a <FT_List_Remove+0x18>
 *   @0x2e89f6 ldr r3, [r1]
 *   @0x2e89fa cbz r3, 0x2e8a00 <FT_List_Remove+0xe>
 *   @0x2e89fe b 0x2e8a02 <FT_List_Remove+0x10>
 *   @0x2e8a02 cbz r2, 0x2e8a08 <FT_List_Remove+0x16>
 *   @0x2e8a06 bx lr
 *   @0x2e8a0a bx lr
 *
 * ══ §819/828 DummyConsole::~DummyConsole()  0xc439c  size 24  6 条（0xc439c..0xc43b4）
 * @func 0xc439c 0xc43c4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc439c ldr r3, [pc, #0xc]
 *   @0xc43a0 ldr r3, [pc, r3]
 *   @0xc43a4 add r3, r3, #8
 *   @0xc43a8 str r3, [r0]
 *   @0xc43ac bx lr
 *   @0xc43b0 eorseq r9, r2, r0, asr #11
 *
 * ══ §820/828 TConsole::~TConsole()  0xc47fc  size 24  6 条（0xc47fc..0xc4814）
 * @func 0xc47fc 0xc4814  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc47fc ldr r3, [pc, #0xc]
 *   @0xc4800 ldr r3, [pc, r3]
 *   @0xc4804 add r3, r3, #8
 *   @0xc4808 str r3, [r0]
 *   @0xc480c bx lr
 *   @0xc4810 eorseq r9, r2, r0, ror #2
 *
 * ══ §821/828 TRelConsole::~TRelConsole()  0xc4828  size 24  6 条（0xc4828..0xc4840）
 * @func 0xc4828 0xc4850  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4828 ldr r3, [pc, #0xc]
 *   @0xc482c ldr r3, [pc, r3]
 *   @0xc4830 add r3, r3, #8
 *   @0xc4834 str r3, [r0]
 *   @0xc4838 bx lr
 *   @0xc483c eorseq r9, r2, r4, lsr r1
 *
 * ══ §822/828 F_Vertex_End_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9170  size 24  6 条（0xc9170..0xc9188）
 * @func 0xc9170 0xc9188  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9170 push {r3, lr}
 *   @0xc9174 mov r1, #0
 *   @0xc9178 ldr r0, [sp, #0x8]
 *   @0xc917c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc9180 pop {r3, lr}
 *   @0xc9184 b 0xc9108 <_Z16YYGML_vertex_endi>
 *
 * ══ §823/828 CExtensionFile::SetFunction_Init(char const*)  0xf4ff8  size 24  6 条（0xf4ff8..0xf5010）
 * @func 0xf4ff8 0xf5010  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4ff8 push {r4, lr}
 *   @0xf4ffc mov r4, r0
 *   @0xf5000 mov r0, r1
 *   @0xf5004 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5008 str r0, [r4, #0xc]
 *   @0xf500c pop {r4, pc}
 *
 * ══ §824/828 Extension_Function_GetKind(int)  0xf63c0  size 24  6 条（0xf63c0..0xf63d8）
 * @func 0xf63c0 0xf63e8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf63c0 ldr r3, [pc, #0xc]
 *   @0xf63c4 ldr r3, [pc, r3]
 *   @0xf63c8 ldr r3, [r3]
 *   @0xf63cc ldr r0, [r3, r0, lsl #2]
 *   @0xf63d0 bx lr
 *   @0xf63d4 mlaeq pc, r4, r9, r7
 *
 * ══ §825/828 Extension_Function_GetCode(int)  0xf63d8  size 24  6 条（0xf63d8..0xf63f0）
 * @func 0xf63d8 0xf63f0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf63d8 ldr r3, [pc, #0xc]
 *   @0xf63dc ldr r3, [pc, r3]
 *   @0xf63e0 ldr r3, [r3, #0x4]
 *   @0xf63e4 ldr r0, [r3, r0, lsl #2]
 *   @0xf63e8 bx lr
 *   @0xf63ec eoreq r7, pc, r0, ror #20
 *
 * ══ §826/828 F_DsSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*)  0xfacf8  size 24  6 条（0xfacf8..0xfad10）
 * @func 0xfacf8 0xfad10  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfacf8 push {r3, lr}
 *   @0xfacfc mov r1, #0
 *   @0xfad00 ldr r0, [sp, #0x8]
 *   @0xfad04 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfad08 pop {r3, lr}
 *   @0xfad0c b 0x2026a8 <_Z15DS_SetPrecisiond>
 *
 * ══ §827/828 F_MpGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x108c70  size 24  6 条（0x108c70..0x108c88）
 * @func 0x108c70 0x108c88  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108c70 push {r3, lr}
 *   @0x108c74 mov r1, #0
 *   @0x108c78 ldr r0, [sp, #0x8]
 *   @0x108c7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c80 pop {r3, lr}
 *   @0x108c84 b 0x19a178 <_Z19Motion_Grid_Destroyi>
 *
 * ══ §828/828 Trunc(double)  0xc46e0  size 16  4 条（0xc46e0..0xc46f0）
 * @func 0xc46e0 0xc46f0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc46e0 vmov d7, r0, r1
 *   @0xc46e4 vcvt.s32.f64 s15, d7
 *   @0xc46e8 vmov r0, s15
 *   @0xc46ec bx lr
 */
