/* cally 逆向卡：All_26 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 20 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/20 anon_224074  0x224074  size 1784  446 条（0x224074..0x22476c）
 * @func 0x224074 0x22476c  size 1784  446 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()×5 / COggThread::Unlock()×5 / anon_224074×5 / COggThread::LogError(char const*, ...)×4 / 0xb6a9c×4 / anon_2236d4×4 / 0xb6b8c×3 / 0xb6a84×3
 * 字段偏移 top8: 0x2b4×17 / 0x2c4×8 / 0x808×7 / 0x28×6 / 0x2a8×5 / 0x2e0×4 / 0x2d5×4 / 0x4×3
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224074 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x224078 mov r5, r0
 *   @0x22407c ldr r0, [r0, #0x2a8]
 *   @0x224080 sub sp, sp, #20
 *   @0x224084 cmp r3, #0
 *   @0x224088 mov r4, #0
 *   @0x22408c add r0, r0, #168
 *   @0x224090 add r7, sp, #12
 *   @0x224094 mov r9, r1
 *   @0x224098 mov r8, r2
 *   @0x22409c str r4, [sp, #0xc]
 *   @0x2240a0 ldr r6, [r5, r0, lsl #2]
 *   @0x2240a4 bne 0x2240b4 <_Z13GetStreamInfoP12cAudio_Sound+0x204>
 *   @0x2240a8 b 0x224170 <_Z13GetStreamInfoP12cAudio_Sound+0x2c0>
 *   @0x2240ac cmp r4, #16384
 *   @0x2240b0 bge 0x224108 <_Z13GetStreamInfoP12cAudio_Sound+0x258>
 *   @0x2240b4 add r1, r6, r4
 *   @0x2240b8 rsb r2, r4, #16384
 *   @0x2240bc mov r0, r5
 *   @0x2240c0 mov r3, r7
 *   @0x2240c4 bl 0x232ec8 <ov_read>
 *   @0x2240c8 subs r12, r0, #0
 *   @0x2240cc addgt r4, r4, r12
 *   @0x2240d0 bgt 0x2240ac <_Z13GetStreamInfoP12cAudio_Sound+0x1fc>
 *   @0x2240d4 mov r0, r5
 *   @0x2240d8 mov r2, #0
 *   @0x2240dc mov r3, #0
 *   @0x2240e0 bne 0x224154 <_Z13GetStreamInfoP12cAudio_Sound+0x2a4>
 *   @0x2240e4 bl 0x231618 <ov_raw_seek>
 *   @0x2240e8 subs r2, r0, #0
 *   @0x2240ec beq 0x2240ac <_Z13GetStreamInfoP12cAudio_Sound+0x1fc>
 *   @0x2240f0 ldr r1, [pc, #0xa8]
 *   @0x2240f4 mov r0, r9
 *   @0x2240f8 add r1, pc, r1
 *   @0x2240fc bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x224100 cmp r4, #0
 *   @0x224104 beq 0x224138 <_Z13GetStreamInfoP12cAudio_Sound+0x288>
 *   @0x224108 ldr r12, [r5, #0x298]
 *   @0x22410c mov r2, r6
 *   @0x224110 movw lr, #0x1101
 *   @0x224114 movw r1, #0x1103
 *   @0x224118 mov r0, r8
 *   @0x22411c mov r3, r4
 *   @0x224120 ldr r6, [r12, #0x8]
 *   @0x224124 ldr r12, [r12, #0x4]
 *   @0x224128 cmp r12, #1
 *   @0x22412c str r6, [sp]
 *   @0x224130 moveq r1, lr
 *   @0x224134 bl 0xb6afc <alBufferData@plt>
 *   @0x224138 ldr r3, [r5, #0x2a8]
 *   @0x22413c mov r0, r4
 *   @0x224140 eor r3, r3, #1
 *   @0x224144 str r3, [r5, #0x2a8]
 *   @0x224148 add sp, sp, #20
 *   @0x22414c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x224150 beq 0x224100 <_Z13GetStreamInfoP12cAudio_Sound+0x250>
 *   @0x224154 ldr r1, [pc, #0x48]
 *   @0x224158 mov r0, r9
 *   @0x22415c mov r2, r12
 *   @0x224160 mov r4, #0
 *   @0x224164 add r1, pc, r1
 *   @0x224168 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x22416c b 0x224138 <_Z13GetStreamInfoP12cAudio_Sound+0x288>
 *   @0x224170 mov r4, r3
 *   @0x224174 mov r0, r5
 *   @0x224178 add r1, r6, r4
 *   @0x22417c rsb r2, r4, #16384
 *   @0x224180 mov r3, r7
 *   @0x224184 bl 0x232ec8 <ov_read>
 *   @0x224188 subs r12, r0, #0
 *   @0x22418c ble 0x224150 <_Z13GetStreamInfoP12cAudio_Sound+0x2a0>
 *   @0x224190 add r4, r4, r12
 *   @0x224194 cmp r4, #16384
 *   @0x224198 blt 0x224174 <_Z13GetStreamInfoP12cAudio_Sound+0x2c4>
 *   @0x22419c b 0x224108 <_Z13GetStreamInfoP12cAudio_Sound+0x258>
 *   @0x2241a0 ldrsheq r0, [r3], -r8
 *   @0x2241a4 andseq r0, r3, r8, ror r12
 *   @0x2241a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2241ac vpush {d8, d9}
 *   @0x2241b0 sub sp, sp, #52
 *   @0x2241b4 vldr s18, [pc, #812]
 *   @0x2241b8 ldr r2, [pc, #0x32c]
 *   @0x2241bc mov r11, #0
 *   @0x2241c0 ldr r10, [r0, #0xc]
 *   @0x2241c4 vldr d8, [pc, #788]
 *   @0x2241c8 ldr r2, [pc, r2]
 *   @0x2241cc ldr r3, [pc, #0x31c]
 *   @0x2241d0 str r2, [sp, #0x14]
 *   @0x2241d4 ldr r2, [pc, #0x318]
 *   @0x2241d8 add r3, pc, r3
 *   @0x2241dc str r3, [sp, #0x18]
 *   @0x2241e0 add r2, pc, r2
 *   @0x2241e4 str r2, [sp, #0x1c]
 *   @0x2241e8 bl 0x215148 <Timing_Time>
 *   @0x2241ec ldr r2, [sp, #0x14]
 *   @0x2241f0 ldrb r3, [r2]
 *   @0x2241f4 uxtb r3, r3
 *   @0x2241f8 strb r3, [r10, #0x831]
 *   @0x2241fc strd r0, r1, [sp, #8]
 *   @0x224200 ldrb r1, [r10, #0x831]
 *   @0x224204 ands r4, r1, #255
 *   @0x224208 bne 0x224388 <_Z13GetStreamInfoP12cAudio_Sound+0x4d8>
 *   @0x22420c mov r0, r10
 *   @0x224210 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x224214 ldr r3, [r10, #0x808]
 *   @0x224218 ldrb r6, [r10, #0x801]
 *   @0x22421c cmp r3, #0
 *   @0x224220 movgt r1, r4
 *   @0x224224 movgt r2, r1
 *   @0x224228 ble 0x224270 <_Z13GetStreamInfoP12cAudio_Sound+0x3c0>
 *   @0x22422c ldr r3, [r10, #0x804]
 *   @0x224230 ldr r0, [r10, #0x810]
 *   @0x224234 add r3, r3, r1
 *   @0x224238 add r1, r1, #768
 *   @0x22423c ldrb r12, [r3, #0x2d6]
 *   @0x224240 strb r12, [r0, r2, lsl #3]
 *   @0x224244 vldr s15, [r3, #744]
 *   @0x224248 vmul.f32 s15, s15, s18
 *   @0x22424c strb r11, [r3, #0x2d6]
 *   @0x224250 ldr r12, [r10, #0x808]
 *   @0x224254 add r2, r2, #1
 *   @0x224258 ldr r0, [r3, #0x2d8]
 *   @0x22425c cmp r12, r2
 *   @0x224260 str r0, [r3, #0x2bc]
 *   @0x224264 vcvt.s32.f32 s15, s15
 *   @0x224268 vstr s15, [r3, #740]
 *   @0x22426c bgt 0x22422c <_Z13GetStreamInfoP12cAudio_Sound+0x37c>
 *   @0x224270 mov r0, r10
 *   @0x224274 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x224278 cmp r6, #0
 *   @0x22427c bne 0x2246f4 <_Z13GetStreamInfoP12cAudio_Sound+0x844>
 *   @0x224280 ldr r2, [r10, #0x808]
 *   @0x224284 cmp r2, #0
 *   @0x224288 addgt r3, sp, #40
 *   @0x22428c addgt r4, sp, #44
 *   @0x224290 strgt r3, [sp, #0x10]
 *   @0x224294 movgt r5, r6
 *   @0x224298 ble 0x224388 <_Z13GetStreamInfoP12cAudio_Sound+0x4d8>
 *   @0x22429c ldr r3, [r10, #0x810]
 *   @0x2242a0 ldr r12, [r10, #0x804]
 *   @0x2242a4 ldrb r7, [r3, r5, lsl #3]
 *   @0x2242a8 add r9, r12, r6
 *   @0x2242ac cmp r7, #0
 *   @0x2242b0 ldr r3, [r9, #0x2c4]
 *   @0x2242b4 bne 0x2243c4 <_Z13GetStreamInfoP12cAudio_Sound+0x514>
 *   @0x2242b8 cmp r3, #0
 *   @0x2242bc beq 0x224378 <_Z13GetStreamInfoP12cAudio_Sound+0x4c8>
 *   @0x2242c0 subs r3, r3, #2
 *   @0x2242c4 ldr r0, [r9, #0x2b4]
 *   @0x2242c8 rsbs r7, r3, #0
 *   @0x2242cc movw r1, #0x1016
 *   @0x2242d0 add r2, sp, #40
 *   @0x2242d4 adcs r7, r7, r3
 *   @0x2242d8 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2242dc ldr r3, [sp, #0x28]
 *   @0x2242e0 cmp r3, #0
 *   @0x2242e4 sub r3, r3, #1
 *   @0x2242e8 str r3, [sp, #0x28]
 *   @0x2242ec movne r8, #3
 *   @0x2242f0 beq 0x224354 <_Z13GetStreamInfoP12cAudio_Sound+0x4a4>
 *   @0x2242f4 ldr r0, [r9, #0x2b4]
 *   @0x2242f8 mov r1, #1
 *   @0x2242fc mov r2, r4
 *   @0x224300 bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x224304 ldr r3, [r9, #0x2e0]
 *   @0x224308 mov r1, r10
 *   @0x22430c mov r0, r9
 *   @0x224310 add r3, r3, #1
 *   @0x224314 str r3, [r9, #0x2e0]
 *   @0x224318 ldr r2, [sp, #0x2c]
 *   @0x22431c mov r3, r7
 *   @0x224320 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4>
 *   @0x224324 mov r1, #1
 *   @0x224328 mov r2, r4
 *   @0x22432c cmp r0, #0
 *   @0x224330 strle r8, [r9, #0x2c4]
 *   @0x224334 ble 0x224340 <_Z13GetStreamInfoP12cAudio_Sound+0x490>
 *   @0x224338 ldr r0, [r9, #0x2b4]
 *   @0x22433c bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x224340 ldr r3, [sp, #0x28]
 *   @0x224344 cmp r3, #0
 *   @0x224348 sub r3, r3, #1
 *   @0x22434c str r3, [sp, #0x28]
 *   @0x224350 bne 0x2242f4 <_Z13GetStreamInfoP12cAudio_Sound+0x444>
 *   @0x224354 mov r2, r4
 *   @0x224358 ldr r0, [r9, #0x2b4]
 *   @0x22435c movw r1, #0x1010
 *   @0x224360 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x224364 ldr r2, [sp, #0x2c]
 *   @0x224368 movw r3, #0x1014
 *   @0x22436c cmp r2, r3
 *   @0x224370 beq 0x224698 <_Z13GetStreamInfoP12cAudio_Sound+0x7e8>
 *   @0x224374 ldr r2, [r10, #0x808]
 *   @0x224378 add r5, r5, #1
 *   @0x22437c add r6, r6, #768
 *   @0x224380 cmp r2, r5
 *   @0x224384 bgt 0x22429c <_Z13GetStreamInfoP12cAudio_Sound+0x3ec>
 *   @0x224388 bl 0x215148 <Timing_Time>
 *   @0x22438c ldrd r2, r3, [sp, #8]
 *   @0x224390 subs r0, r0, r2
 *   @0x224394 sbc r1, r1, r3
 *   @0x224398 bl 0x319164 <__floatdidf>
 *   @0x22439c vmov d6, r0, r1
 *   @0x2243a0 vmul.f64 d7, d6, d8
 *   @0x2243a4 vcvt.s32.f64 s13, d7
 *   @0x2243a8 vmov r0, s13
 *   @0x2243ac rsb r0, r0, #16
 *   @0x2243b0 bic r0, r0, r0, asr #31
 *   @0x2243b4 cmp r0, #0
 *   @0x2243b8 beq 0x2241e8 <_Z13GetStreamInfoP12cAudio_Sound+0x338>
 *   @0x2243bc bl 0x27e114 <_ZN7CThread5SleepEi>
 *   @0x2243c0 b 0x2241e8 <_Z13GetStreamInfoP12cAudio_Sound+0x338>
 *   @0x2243c4 ands r8, r7, #1
 *   @0x2243c8 bne 0x2244f8 <_Z13GetStreamInfoP12cAudio_Sound+0x648>
 *   @0x2243cc cmp r7, #8
 *   @0x2243d0 beq 0x2244f8 <_Z13GetStreamInfoP12cAudio_Sound+0x648>
 *   @0x2243d4 tst r7, #16
 *   @0x2243d8 beq 0x2244d4 <_Z13GetStreamInfoP12cAudio_Sound+0x624>
 *   @0x2243dc cmp r3, #0
 *   @0x2243e0 ldr r7, [r9, #0x2e4]
 *   @0x2243e4 beq 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4>
 *   @0x2243e8 add r2, sp, #36
 *   @0x2243ec ldr r0, [r9, #0x2b4]
 *   @0x2243f0 movw r1, #0x1010
 *   @0x2243f4 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2243f8 ldr r0, [r9, #0x2b4]
 *   @0x2243fc ldr r8, [sp, #0x24]
 *   @0x224400 bl 0xb6b14 <alSourceStop@plt>
 *   @0x224404 ldr r0, [r9, #0x2b4]
 *   @0x224408 movw r1, #0x1015
 *   @0x22440c add r2, sp, #40
 *   @0x224410 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x224414 b 0x224428 <_Z13GetStreamInfoP12cAudio_Sound+0x578>
 *   @0x224418 ldr r0, [r9, #0x2b4]
 *   @0x22441c mov r1, #1
 *   @0x224420 mov r2, r4
 *   @0x224424 bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x224428 ldr r3, [sp, #0x28]
 *   @0x22442c cmp r3, #0
 *   @0x224430 sub r3, r3, #1
 *   @0x224434 str r3, [sp, #0x28]
 *   @0x224438 bne 0x224418 <_Z13GetStreamInfoP12cAudio_Sound+0x568>
 *   @0x22443c mov r2, r7
 *   @0x224440 asr r3, r7, #31
 *   @0x224444 str r11, [r9, #0x2e0]
 *   @0x224448 mov r0, r9
 *   @0x22444c bl 0x232a44 <ov_time_seek>
 *   @0x224450 ldr r7, [r9, #0x2c4]
 *   @0x224454 str r11, [r9, #0x2a8]
 *   @0x224458 mov r0, r9
 *   @0x22445c subs r2, r7, #2
 *   @0x224460 mov r1, r10
 *   @0x224464 rsbs r7, r2, #0
 *   @0x224468 adcs r7, r7, r2
 *   @0x22446c ldr r2, [r9, #0x2ac]
 *   @0x224470 mov r3, r7
 *   @0x224474 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4>
 *   @0x224478 cmp r0, #0
 *   @0x22447c ble 0x22466c <_Z13GetStreamInfoP12cAudio_Sound+0x7bc>
 *   @0x224480 mov r1, r10
 *   @0x224484 mov r3, r7
 *   @0x224488 ldr r2, [r9, #0x2b0]
 *   @0x22448c mov r0, r9
 *   @0x224490 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4>
 *   @0x224494 add r2, r9, #684
 *   @0x224498 cmp r0, #0
 *   @0x22449c ldr r0, [r9, #0x2b4]
 *   @0x2244a0 movgt r1, #2
 *   @0x2244a4 movle r1, #1
 *   @0x2244a8 bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x2244ac ldr r0, [r9, #0x2b4]
 *   @0x2244b0 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x2244b4 ldr r0, [r9, #0x2b4]
 *   @0x2244b8 movw r1, #0x1025
 *   @0x2244bc mov r2, #0
 *   @0x2244c0 bl 0xb6a78 <alSourcef@plt>
 *   @0x2244c4 movw r3, #0x1013
 *   @0x2244c8 cmp r8, r3
 *   @0x2244cc beq 0x224764 <_Z13GetStreamInfoP12cAudio_Sound+0x8b4>
 *   @0x2244d0 ldr r3, [r9, #0x2c4]
 *   @0x2244d4 cmp r3, #0
 *   @0x2244d8 beq 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4>
 *   @0x2244dc b 0x2242c0 <_Z13GetStreamInfoP12cAudio_Sound+0x410>
 *   @0x2244e0 rscsle r10, r1, #252, #18
 *   @0x2244e4 svclo #0x50624d
 *   @0x2244e8 ldrbtmi r0, [r10], #-0
 *   @0x2244ec ldrheq sp, [r12], -r0
 *   @0x2244f0 andseq r0, r3, r0, asr r12
 *   @0x2244f4 andseq r0, r3, r8, lsr #24
 *   @0x2244f8 cmp r3, #0
 *   @0x2244fc beq 0x224524 <_Z13GetStreamInfoP12cAudio_Sound+0x674>
 *   @0x224500 mov r0, r9
 *   @0x224504 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48>
 *   @0x224508 cmp r7, #8
 *   @0x22450c bne 0x224524 <_Z13GetStreamInfoP12cAudio_Sound+0x674>
 *   @0x224510 mov r0, r10
 *   @0x224514 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x224518 strb r11, [r9, #0x2d5]
 *   @0x22451c mov r0, r10
 *   @0x224520 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x224524 cmp r8, #0
 *   @0x224528 ldreq r3, [r9, #0x2c4]
 *   @0x22452c beq 0x2243d4 <_Z13GetStreamInfoP12cAudio_Sound+0x524>
 *   @0x224530 ldr r3, [r9, #0x2bc]
 *   @0x224534 and r8, r7, #16
 *   @0x224538 ands r8, r8, #255
 *   @0x22453c ldrb r2, [r3, #0x24]
 *   @0x224540 ldrne r8, [r9, #0x2e4]
 *   @0x224544 cmp r2, #0
 *   @0x224548 bne 0x224634 <_Z13GetStreamInfoP12cAudio_Sound+0x784>
 *   @0x22454c mov r0, r9
 *   @0x224550 mov r1, r10
 *   @0x224554 bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c>
 *   @0x224558 cmp r0, #0
 *   @0x22455c beq 0x2244d0 <_Z13GetStreamInfoP12cAudio_Sound+0x620>
 *   @0x224560 ubfx r7, r7, #0x1, #0x1
 *   @0x224564 mvn r1, #0
 *   @0x224568 cmp r7, #0
 *   @0x22456c mov r0, r9
 *   @0x224570 moveq r3, #1
 *   @0x224574 movne r3, #2
 *   @0x224578 str r3, [r9, #0x2c4]
 *   @0x22457c bl 0x232e28 <ov_info>
 *   @0x224580 mov r2, #0
 *   @0x224584 movw r1, #0x1009
 *   @0x224588 str r11, [r9, #0x2e0]
 *   @0x22458c str r0, [r9, #0x298]
 *   @0x224590 ldr r0, [r9, #0x2b4]
 *   @0x224594 bl 0xb6a6c <alSourcei@plt>
 *   @0x224598 bl 0xb6a54 <alGetError@plt>
 *   @0x22459c subs r2, r0, #0
 *   @0x2245a0 bne 0x2246d8 <_Z13GetStreamInfoP12cAudio_Sound+0x828>
 *   @0x2245a4 mov r2, #0
 *   @0x2245a8 ldr r0, [r9, #0x2b4]
 *   @0x2245ac movw r1, #0x1007
 *   @0x2245b0 bl 0xb6a6c <alSourcei@plt>
 *   @0x2245b4 bl 0xb6a54 <alGetError@plt>
 *   @0x2245b8 subs r2, r0, #0
 *   @0x2245bc bne 0x2246c8 <_Z13GetStreamInfoP12cAudio_Sound+0x818>
 *   @0x2245c0 cmp r8, #0
 *   @0x2245c4 ble 0x2245d8 <_Z13GetStreamInfoP12cAudio_Sound+0x728>
 *   @0x2245c8 mov r0, r9
 *   @0x2245cc mov r2, r8
 *   @0x2245d0 asr r3, r8, #31
 *   @0x2245d4 bl 0x232a44 <ov_time_seek>
 *   @0x2245d8 str r11, [r9, #0x2a8]
 *   @0x2245dc mov r0, r9
 *   @0x2245e0 mov r1, r10
 *   @0x2245e4 ldr r2, [r9, #0x2ac]
 *   @0x2245e8 mov r3, r7
 *   @0x2245ec bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4>
 *   @0x2245f0 cmp r0, #0
 *   @0x2245f4 ble 0x22466c <_Z13GetStreamInfoP12cAudio_Sound+0x7bc>
 *   @0x2245f8 mov r1, r10
 *   @0x2245fc mov r3, r7
 *   @0x224600 ldr r2, [r9, #0x2b0]
 *   @0x224604 mov r0, r9
 *   @0x224608 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4>
 *   @0x22460c add r2, r9, #684
 *   @0x224610 cmp r0, #0
 *   @0x224614 ldr r0, [r9, #0x2b4]
 *   @0x224618 movgt r1, #2
 *   @0x22461c movle r1, #1
 *   @0x224620 bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x224624 ldr r0, [r9, #0x2b4]
 *   @0x224628 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x22462c ldr r3, [r9, #0x2c4]
 *   @0x224630 b 0x2244d4 <_Z13GetStreamInfoP12cAudio_Sound+0x624>
 *   @0x224634 ldr r3, [r3, #0x30]
 *   @0x224638 mov r1, r9
 *   @0x22463c mov r2, r10
 *   @0x224640 mov r0, r3
 *   @0x224644 str r3, [sp, #0x4]
 *   @0x224648 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110>
 *   @0x22464c ldr r3, [sp, #0x4]
 *   @0x224650 cmp r0, #0
 *   @0x224654 bne 0x224560 <_Z13GetStreamInfoP12cAudio_Sound+0x6b0>
 *   @0x224658 mov r0, r3
 *   @0x22465c mov r1, r9
 *   @0x224660 mov r2, r10
 *   @0x224664 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8>
 *   @0x224668 b 0x224558 <_Z13GetStreamInfoP12cAudio_Sound+0x6a8>
 *   @0x22466c ldr r3, [r9, #0x2c4]
 *   @0x224670 cmp r3, #0
 *   @0x224674 beq 0x224680 <_Z13GetStreamInfoP12cAudio_Sound+0x7d0>
 *   @0x224678 mov r0, r9
 *   @0x22467c bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48>
 *   @0x224680 mov r0, r10
 *   @0x224684 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x224688 strb r11, [r9, #0x2d5]
 *   @0x22468c mov r0, r10
 *   @0x224690 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x224694 b 0x2244d0 <_Z13GetStreamInfoP12cAudio_Sound+0x620>
 *   @0x224698 ldr r3, [r9, #0x2c4]
 *   @0x22469c cmp r3, #3
 *   @0x2246a0 bne 0x2246e8 <_Z13GetStreamInfoP12cAudio_Sound+0x838>
 *   @0x2246a4 mov r0, r9
 *   @0x2246a8 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48>
 *   @0x2246ac mov r0, r10
 *   @0x2246b0 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x2246b4 strb r11, [r9, #0x2d5]
 *   @0x2246b8 mov r0, r10
 *   @0x2246bc bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x2246c0 ldr r2, [r10, #0x808]
 *   @0x2246c4 b 0x224378 <_Z13GetStreamInfoP12cAudio_Sound+0x4c8>
 *   @0x2246c8 mov r0, r10
 *   @0x2246cc ldr r1, [sp, #0x18]
 *   @0x2246d0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x2246d4 b 0x2245c0 <_Z13GetStreamInfoP12cAudio_Sound+0x710>
 *   @0x2246d8 mov r0, r10
 *   @0x2246dc ldr r1, [sp, #0x1c]
 *   @0x2246e0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz>
 *   @0x2246e4 b 0x2245a4 <_Z13GetStreamInfoP12cAudio_Sound+0x6f4>
 *   @0x2246e8 ldr r0, [r9, #0x2b4]
 *   @0x2246ec bl 0xb6a84 <alSourcePlay@plt>
 *   @0x2246f0 b 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4>
 *   @0x2246f4 mov r0, r10
 *   @0x2246f8 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x2246fc ldr r2, [r10, #0x808]
 *   @0x224700 cmp r2, #0
 *   @0x224704 movgt r4, #0
 *   @0x224708 movgt r6, r4
 *   @0x22470c movgt r7, r4
 *   @0x224710 ble 0x224748 <_Z13GetStreamInfoP12cAudio_Sound+0x898>
 *   @0x224714 ldr r5, [r10, #0x804]
 *   @0x224718 add r6, r6, #1
 *   @0x22471c add r5, r5, r4
 *   @0x224720 add r4, r4, #768
 *   @0x224724 ldr r3, [r5, #0x2c4]
 *   @0x224728 mov r0, r5
 *   @0x22472c cmp r3, #0
 *   @0x224730 beq 0x224740 <_Z13GetStreamInfoP12cAudio_Sound+0x890>
 *   @0x224734 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48>
 *   @0x224738 ldr r2, [r10, #0x808]
 *   @0x22473c strb r7, [r5, #0x2d5]
 *   @0x224740 cmp r6, r2
 *   @0x224744 blt 0x224714 <_Z13GetStreamInfoP12cAudio_Sound+0x864>
 *   @0x224748 mov r0, r10
 *   @0x22474c bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x224750 mov r0, #0
 *   @0x224754 strb r0, [r10, #0x830]
 *   @0x224758 add sp, sp, #52
 *   @0x22475c vpop {d8, d9}
 *   @0x224760 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x224764 ldr r0, [r9, #0x2b4]
 *   @0x224768 bl 0xb6ab4 <alSourcePause@plt>
 *
 * ══ §2/20 CDS_Priority::Assign(CDS_Priority*)  0x209a78  size 1744  436 条（0x209a78..0x20a148）
 * @func 0x209a78 0x20a148  size 1744  436 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0x8×75 / 0x4×56 / 0xc×28 / 0x10×5 / 0x14×2 / 0x69c×1 / 0x5a0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x209a78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x209a7c subs r6, r1, #0
 *   @0x209a80 sub sp, sp, #20
 *   @0x209a84 mov r8, r0
 *   @0x209a88 beq 0x20a134 <_ZN12CDS_Priority6AssignEPS_+0x6bc>
 *   @0x209a8c ldr r1, [r6, #0x8]
 *   @0x209a90 movw r3, #0x994
 *   @0x209a94 ldr r12, [r6, #0x4]
 *   @0x209a98 add r0, r0, #12
 *   @0x209a9c ldr r2, [pc, #0x69c]
 *   @0x209aa0 lsl r1, r1, #4
 *   @0x209aa4 add r2, pc, r2
 *   @0x209aa8 str r12, [r8, #0x4]
 *   @0x209aac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x209ab0 ldr r3, [r6, #0x8]
 *   @0x209ab4 str r3, [r8, #0x8]
 *   @0x209ab8 ldr r3, [r6, #0x8]
 *   @0x209abc cmp r3, #0
 *   @0x209ac0 movgt r9, #0
 *   @0x209ac4 movgt r10, r9
 *   @0x209ac8 ble 0x209b94 <_ZN12CDS_Priority6AssignEPS_+0x11c>
 *   @0x209acc ldr r7, [r8, #0xc]
 *   @0x209ad0 lsl r4, r9, #4
 *   @0x209ad4 ldr r11, [r6, #0xc]
 *   @0x209ad8 add r5, r7, r4
 *   @0x209adc add r3, r11, r4
 *   @0x209ae0 ldr r0, [r5, #0xc]
 *   @0x209ae4 bic r1, r0, #-16777216
 *   @0x209ae8 cmp r1, #1
 *   @0x209aec beq 0x209d94 <_ZN12CDS_Priority6AssignEPS_+0x31c>
 *   @0x209af0 cmp r1, #2
 *   @0x209af4 bne 0x209b18 <_ZN12CDS_Priority6AssignEPS_+0xa0>
 *   @0x209af8 sub r0, r0, #1
 *   @0x209afc bic r0, r0, #-16777216
 *   @0x209b00 bic r0, r0, #3
 *   @0x209b04 cmp r0, #0
 *   @0x209b08 beq 0x209eec <_ZN12CDS_Priority6AssignEPS_+0x474>
 *   @0x209b0c mov r2, #5
 *   @0x209b10 str r10, [r5, #0x8]
 *   @0x209b14 str r2, [r5, #0xc]
 *   @0x209b18 ldr r1, [r3, #0xc]
 *   @0x209b1c ldr r0, [r3, #0x8]
 *   @0x209b20 str r10, [r7, r4]
 *   @0x209b24 str r1, [r5, #0xc]
 *   @0x209b28 ldr r1, [r3, #0xc]
 *   @0x209b2c str r0, [r5, #0x8]
 *   @0x209b30 bic r1, r1, #-16777216
 *   @0x209b34 cmp r1, #14
 *   @0x209b38 addls pc, pc, r1, lsl #2
 *   @0x209b3c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b40 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204>
 *   @0x209b44 b 0x209ce0 <_ZN12CDS_Priority6AssignEPS_+0x268>
 *   @0x209b48 b 0x209cb4 <_ZN12CDS_Priority6AssignEPS_+0x23c>
 *   @0x209b4c b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104>
 *   @0x209b50 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b54 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b58 b 0x209c90 <_ZN12CDS_Priority6AssignEPS_+0x218>
 *   @0x209b5c b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104>
 *   @0x209b60 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b64 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b68 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204>
 *   @0x209b6c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b70 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209b74 b 0x209c7c <_ZN12CDS_Priority6AssignEPS_+0x204>
 *   @0x209b78 b 0x209b7c <_ZN12CDS_Priority6AssignEPS_+0x104>
 *   @0x209b7c ldr r3, [r11, r4]
 *   @0x209b80 str r3, [r7, r4]
 *   @0x209b84 ldr r3, [r6, #0x8]
 *   @0x209b88 add r9, r9, #1
 *   @0x209b8c cmp r3, r9
 *   @0x209b90 bgt 0x209acc <_ZN12CDS_Priority6AssignEPS_+0x54>
 *   @0x209b94 ldr r1, [r6, #0x10]
 *   @0x209b98 movw r3, #0x99a
 *   @0x209b9c ldr r2, [pc, #0x5a0]
 *   @0x209ba0 add r0, r8, #20
 *   @0x209ba4 add r2, pc, r2
 *   @0x209ba8 lsl r1, r1, #4
 *   @0x209bac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x209bb0 ldr r3, [r6, #0x10]
 *   @0x209bb4 str r3, [r8, #0x10]
 *   @0x209bb8 ldr r3, [r6, #0x10]
 *   @0x209bbc cmp r3, #0
 *   @0x209bc0 movgt r9, #0
 *   @0x209bc4 movgt r10, r9
 *   @0x209bc8 ble 0x209d10 <_ZN12CDS_Priority6AssignEPS_+0x298>
 *   @0x209bcc ldr r7, [r8, #0x14]
 *   @0x209bd0 lsl r4, r9, #4
 *   @0x209bd4 ldr r11, [r6, #0x14]
 *   @0x209bd8 add r5, r7, r4
 *   @0x209bdc add r3, r11, r4
 *   @0x209be0 ldr r0, [r5, #0xc]
 *   @0x209be4 bic r1, r0, #-16777216
 *   @0x209be8 cmp r1, #1
 *   @0x209bec beq 0x209ddc <_ZN12CDS_Priority6AssignEPS_+0x364>
 *   @0x209bf0 cmp r1, #2
 *   @0x209bf4 bne 0x209c18 <_ZN12CDS_Priority6AssignEPS_+0x1a0>
 *   @0x209bf8 sub r0, r0, #1
 *   @0x209bfc bic r0, r0, #-16777216
 *   @0x209c00 bic r0, r0, #3
 *   @0x209c04 cmp r0, #0
 *   @0x209c08 beq 0x209f00 <_ZN12CDS_Priority6AssignEPS_+0x488>
 *   @0x209c0c mov r2, #5
 *   @0x209c10 str r10, [r5, #0x8]
 *   @0x209c14 str r2, [r5, #0xc]
 *   @0x209c18 ldr r1, [r3, #0xc]
 *   @0x209c1c ldr r0, [r3, #0x8]
 *   @0x209c20 str r10, [r7, r4]
 *   @0x209c24 str r1, [r5, #0xc]
 *   @0x209c28 ldr r1, [r3, #0xc]
 *   @0x209c2c str r0, [r5, #0x8]
 *   @0x209c30 bic r1, r1, #-16777216
 *   @0x209c34 cmp r1, #14
 *   @0x209c38 addls pc, pc, r1, lsl #2
 *   @0x209c3c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c40 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0>
 *   @0x209c44 b 0x209d7c <_ZN12CDS_Priority6AssignEPS_+0x304>
 *   @0x209c48 b 0x209d50 <_ZN12CDS_Priority6AssignEPS_+0x2d8>
 *   @0x209c4c b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280>
 *   @0x209c50 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c54 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c58 b 0x209d2c <_ZN12CDS_Priority6AssignEPS_+0x2b4>
 *   @0x209c5c b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280>
 *   @0x209c60 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c64 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c68 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0>
 *   @0x209c6c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c70 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209c74 b 0x209d18 <_ZN12CDS_Priority6AssignEPS_+0x2a0>
 *   @0x209c78 b 0x209cf8 <_ZN12CDS_Priority6AssignEPS_+0x280>
 *   @0x209c7c ldr r2, [r11, r4]
 *   @0x209c80 ldr r3, [r3, #0x4]
 *   @0x209c84 str r2, [r7, r4]
 *   @0x209c88 str r3, [r5, #0x4]
 *   @0x209c8c b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209c90 ldr r3, [r11, r4]
 *   @0x209c94 str r3, [r7, r4]
 *   @0x209c98 ldr r3, [r11, r4]
 *   @0x209c9c cmp r3, #0
 *   @0x209ca0 beq 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209ca4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x209ca8 ldr r1, [r11, r4]
 *   @0x209cac bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x209cb0 b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209cb4 ldr r3, [r11, r4]
 *   @0x209cb8 cmp r3, #0
 *   @0x209cbc str r3, [r7, r4]
 *   @0x209cc0 beq 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209cc4 ldr r1, [r3, #0x8]
 *   @0x209cc8 ldr r2, [r3]
 *   @0x209ccc cmp r1, #0
 *   @0x209cd0 streq r5, [r3, #0x8]
 *   @0x209cd4 add r2, r2, #1
 *   @0x209cd8 str r2, [r3]
 *   @0x209cdc b 0x209b84 <_ZN12CDS_Priority6AssignEPS_+0x10c>
 *   @0x209ce0 ldr r3, [r11, r4]
 *   @0x209ce4 cmp r3, #0
 *   @0x209ce8 ldrne r2, [r3, #0x4]
 *   @0x209cec addne r2, r2, #1
 *   @0x209cf0 strne r2, [r3, #0x4]
 *   @0x209cf4 b 0x209b80 <_ZN12CDS_Priority6AssignEPS_+0x108>
 *   @0x209cf8 ldr r3, [r11, r4]
 *   @0x209cfc str r3, [r7, r4]
 *   @0x209d00 ldr r3, [r6, #0x10]
 *   @0x209d04 add r9, r9, #1
 *   @0x209d08 cmp r3, r9
 *   @0x209d0c bgt 0x209bcc <_ZN12CDS_Priority6AssignEPS_+0x154>
 *   @0x209d10 add sp, sp, #20
 *   @0x209d14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x209d18 ldr r2, [r11, r4]
 *   @0x209d1c ldr r3, [r3, #0x4]
 *   @0x209d20 str r2, [r7, r4]
 *   @0x209d24 str r3, [r5, #0x4]
 *   @0x209d28 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209d2c ldr r3, [r11, r4]
 *   @0x209d30 str r3, [r7, r4]
 *   @0x209d34 ldr r3, [r11, r4]
 *   @0x209d38 cmp r3, #0
 *   @0x209d3c beq 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209d40 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x209d44 ldr r1, [r11, r4]
 *   @0x209d48 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x209d4c b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209d50 ldr r3, [r11, r4]
 *   @0x209d54 cmp r3, #0
 *   @0x209d58 str r3, [r7, r4]
 *   @0x209d5c beq 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209d60 ldr r1, [r3, #0x8]
 *   @0x209d64 ldr r2, [r3]
 *   @0x209d68 cmp r1, #0
 *   @0x209d6c streq r5, [r3, #0x8]
 *   @0x209d70 add r2, r2, #1
 *   @0x209d74 str r2, [r3]
 *   @0x209d78 b 0x209d00 <_ZN12CDS_Priority6AssignEPS_+0x288>
 *   @0x209d7c ldr r3, [r11, r4]
 *   @0x209d80 cmp r3, #0
 *   @0x209d84 ldrne r2, [r3, #0x4]
 *   @0x209d88 addne r2, r2, #1
 *   @0x209d8c strne r2, [r3, #0x4]
 *   @0x209d90 b 0x209cfc <_ZN12CDS_Priority6AssignEPS_+0x284>
 *   @0x209d94 ldr r1, [r7, r9, lsl #4]
 *   @0x209d98 cmp r1, #0
 *   @0x209d9c beq 0x209dd4 <_ZN12CDS_Priority6AssignEPS_+0x35c>
 *   @0x209da0 str r1, [sp, #0x8]
 *   @0x209da4 str r3, [sp, #0x4]
 *   @0x209da8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209dac ldr r1, [sp, #0x8]
 *   @0x209db0 ldr r3, [sp, #0x4]
 *   @0x209db4 ldr r12, [r1, #0x4]
 *   @0x209db8 sub r12, r12, #1
 *   @0x209dbc str r12, [r1, #0x4]
 *   @0x209dc0 cmp r12, #0
 *   @0x209dc4 beq 0x209e24 <_ZN12CDS_Priority6AssignEPS_+0x3ac>
 *   @0x209dc8 str r3, [sp, #0x4]
 *   @0x209dcc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209dd0 ldr r3, [sp, #0x4]
 *   @0x209dd4 str r10, [r7, r4]
 *   @0x209dd8 b 0x209b18 <_ZN12CDS_Priority6AssignEPS_+0xa0>
 *   @0x209ddc ldr r1, [r7, r9, lsl #4]
 *   @0x209de0 cmp r1, #0
 *   @0x209de4 beq 0x209e1c <_ZN12CDS_Priority6AssignEPS_+0x3a4>
 *   @0x209de8 str r1, [sp, #0x8]
 *   @0x209dec str r3, [sp, #0x4]
 *   @0x209df0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209df4 ldr r1, [sp, #0x8]
 *   @0x209df8 ldr r3, [sp, #0x4]
 *   @0x209dfc ldr r12, [r1, #0x4]
 *   @0x209e00 sub r12, r12, #1
 *   @0x209e04 str r12, [r1, #0x4]
 *   @0x209e08 cmp r12, #0
 *   @0x209e0c beq 0x209e88 <_ZN12CDS_Priority6AssignEPS_+0x410>
 *   @0x209e10 str r3, [sp, #0x4]
 *   @0x209e14 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209e18 ldr r3, [sp, #0x4]
 *   @0x209e1c str r10, [r7, r4]
 *   @0x209e20 b 0x209c18 <_ZN12CDS_Priority6AssignEPS_+0x1a0>
 *   @0x209e24 ldr r0, [r1]
 *   @0x209e28 str r1, [sp, #0x8]
 *   @0x209e2c str r12, [sp, #0xc]
 *   @0x209e30 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209e34 ldr r1, [sp, #0x8]
 *   @0x209e38 ldr r12, [sp, #0xc]
 *   @0x209e3c str r12, [r1]
 *   @0x209e40 str r12, [r1, #0x8]
 *   @0x209e44 str r1, [sp, #0x8]
 *   @0x209e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209e4c ldr r1, [sp, #0x8]
 *   @0x209e50 ldr r3, [sp, #0x4]
 *   @0x209e54 ldr r12, [r1, #0x4]
 *   @0x209e58 sub r12, r12, #1
 *   @0x209e5c str r12, [r1, #0x4]
 *   @0x209e60 cmp r12, #0
 *   @0x209e64 beq 0x209f14 <_ZN12CDS_Priority6AssignEPS_+0x49c>
 *   @0x209e68 str r3, [sp, #0x4]
 *   @0x209e6c str r1, [sp, #0x8]
 *   @0x209e70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209e74 ldr r1, [sp, #0x8]
 *   @0x209e78 mov r0, r1
 *   @0x209e7c bl 0x27d1d0 <_ZdlPv>
 *   @0x209e80 ldr r3, [sp, #0x4]
 *   @0x209e84 b 0x209dc8 <_ZN12CDS_Priority6AssignEPS_+0x350>
 *   @0x209e88 ldr r0, [r1]
 *   @0x209e8c str r1, [sp, #0x8]
 *   @0x209e90 str r12, [sp, #0xc]
 *   @0x209e94 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209e98 ldr r1, [sp, #0x8]
 *   @0x209e9c ldr r12, [sp, #0xc]
 *   @0x209ea0 str r12, [r1]
 *   @0x209ea4 str r12, [r1, #0x8]
 *   @0x209ea8 str r1, [sp, #0x8]
 *   @0x209eac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209eb0 ldr r1, [sp, #0x8]
 *   @0x209eb4 ldr r3, [sp, #0x4]
 *   @0x209eb8 ldr r12, [r1, #0x4]
 *   @0x209ebc sub r12, r12, #1
 *   @0x209ec0 str r12, [r1, #0x4]
 *   @0x209ec4 cmp r12, #0
 *   @0x209ec8 beq 0x209f7c <_ZN12CDS_Priority6AssignEPS_+0x504>
 *   @0x209ecc str r3, [sp, #0x4]
 *   @0x209ed0 str r1, [sp, #0x8]
 *   @0x209ed4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209ed8 ldr r1, [sp, #0x8]
 *   @0x209edc mov r0, r1
 *   @0x209ee0 bl 0x27d1d0 <_ZdlPv>
 *   @0x209ee4 ldr r3, [sp, #0x4]
 *   @0x209ee8 b 0x209e10 <_ZN12CDS_Priority6AssignEPS_+0x398>
 *   @0x209eec mov r0, r5
 *   @0x209ef0 str r3, [sp, #0x4]
 *   @0x209ef4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x209ef8 ldr r3, [sp, #0x4]
 *   @0x209efc b 0x209b0c <_ZN12CDS_Priority6AssignEPS_+0x94>
 *   @0x209f00 mov r0, r5
 *   @0x209f04 str r3, [sp, #0x4]
 *   @0x209f08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x209f0c ldr r3, [sp, #0x4]
 *   @0x209f10 b 0x209c0c <_ZN12CDS_Priority6AssignEPS_+0x194>
 *   @0x209f14 ldr r0, [r1]
 *   @0x209f18 str r1, [sp, #0x8]
 *   @0x209f1c str r12, [sp, #0xc]
 *   @0x209f20 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209f24 ldr r1, [sp, #0x8]
 *   @0x209f28 ldr r12, [sp, #0xc]
 *   @0x209f2c str r12, [r1]
 *   @0x209f30 str r12, [r1, #0x8]
 *   @0x209f34 str r1, [sp, #0x8]
 *   @0x209f38 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209f3c ldr r1, [sp, #0x8]
 *   @0x209f40 ldr r3, [sp, #0x4]
 *   @0x209f44 ldr r12, [r1, #0x4]
 *   @0x209f48 sub r12, r12, #1
 *   @0x209f4c str r12, [r1, #0x4]
 *   @0x209f50 cmp r12, #0
 *   @0x209f54 beq 0x20a08c <_ZN12CDS_Priority6AssignEPS_+0x614>
 *   @0x209f58 str r3, [sp, #0x4]
 *   @0x209f5c str r1, [sp, #0x8]
 *   @0x209f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209f64 ldr r1, [sp, #0x8]
 *   @0x209f68 mov r0, r1
 *   @0x209f6c bl 0x27d1d0 <_ZdlPv>
 *   @0x209f70 ldr r3, [sp, #0x4]
 *   @0x209f74 ldr r1, [sp, #0x8]
 *   @0x209f78 b 0x209e68 <_ZN12CDS_Priority6AssignEPS_+0x3f0>
 *   @0x209f7c ldr r0, [r1]
 *   @0x209f80 str r1, [sp, #0x8]
 *   @0x209f84 str r12, [sp, #0xc]
 *   @0x209f88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209f8c ldr r1, [sp, #0x8]
 *   @0x209f90 ldr r12, [sp, #0xc]
 *   @0x209f94 str r12, [r1]
 *   @0x209f98 str r12, [r1, #0x8]
 *   @0x209f9c str r1, [sp, #0x8]
 *   @0x209fa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209fa4 ldr r1, [sp, #0x8]
 *   @0x209fa8 ldr r3, [sp, #0x4]
 *   @0x209fac ldr r12, [r1, #0x4]
 *   @0x209fb0 sub r12, r12, #1
 *   @0x209fb4 str r12, [r1, #0x4]
 *   @0x209fb8 cmp r12, #0
 *   @0x209fbc beq 0x209fe4 <_ZN12CDS_Priority6AssignEPS_+0x56c>
 *   @0x209fc0 str r3, [sp, #0x4]
 *   @0x209fc4 str r1, [sp, #0x8]
 *   @0x209fc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209fcc ldr r1, [sp, #0x8]
 *   @0x209fd0 mov r0, r1
 *   @0x209fd4 bl 0x27d1d0 <_ZdlPv>
 *   @0x209fd8 ldr r3, [sp, #0x4]
 *   @0x209fdc ldr r1, [sp, #0x8]
 *   @0x209fe0 b 0x209ecc <_ZN12CDS_Priority6AssignEPS_+0x454>
 *   @0x209fe4 ldr r0, [r1]
 *   @0x209fe8 str r1, [sp, #0x8]
 *   @0x209fec str r12, [sp, #0xc]
 *   @0x209ff0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209ff4 ldr r1, [sp, #0x8]
 *   @0x209ff8 ldr r12, [sp, #0xc]
 *   @0x209ffc str r12, [r1]
 *   @0x20a000 str r12, [r1, #0x8]
 *   @0x20a004 str r1, [sp, #0x8]
 *   @0x20a008 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a00c ldr r1, [sp, #0x8]
 *   @0x20a010 ldr r3, [sp, #0x4]
 *   @0x20a014 ldr r12, [r1, #0x4]
 *   @0x20a018 sub r12, r12, #1
 *   @0x20a01c str r12, [r1, #0x4]
 *   @0x20a020 cmp r12, #0
 *   @0x20a024 bne 0x20a068 <_ZN12CDS_Priority6AssignEPS_+0x5f0>
 *   @0x20a028 ldr r0, [r1]
 *   @0x20a02c str r1, [sp, #0x8]
 *   @0x20a030 str r12, [sp, #0xc]
 *   @0x20a034 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a038 ldr r1, [sp, #0x8]
 *   @0x20a03c ldr r12, [sp, #0xc]
 *   @0x20a040 mov r0, r1
 *   @0x20a044 str r12, [r1]
 *   @0x20a048 str r12, [r1, #0x8]
 *   @0x20a04c str r1, [sp, #0x8]
 *   @0x20a050 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20a054 ldr r1, [sp, #0x8]
 *   @0x20a058 mov r0, r1
 *   @0x20a05c bl 0x27d1d0 <_ZdlPv>
 *   @0x20a060 ldr r3, [sp, #0x4]
 *   @0x20a064 ldr r1, [sp, #0x8]
 *   @0x20a068 str r3, [sp, #0x4]
 *   @0x20a06c str r1, [sp, #0x8]
 *   @0x20a070 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a074 ldr r1, [sp, #0x8]
 *   @0x20a078 mov r0, r1
 *   @0x20a07c bl 0x27d1d0 <_ZdlPv>
 *   @0x20a080 ldr r3, [sp, #0x4]
 *   @0x20a084 ldr r1, [sp, #0x8]
 *   @0x20a088 b 0x209fc0 <_ZN12CDS_Priority6AssignEPS_+0x548>
 *   @0x20a08c ldr r0, [r1]
 *   @0x20a090 str r1, [sp, #0x8]
 *   @0x20a094 str r12, [sp, #0xc]
 *   @0x20a098 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a09c ldr r1, [sp, #0x8]
 *   @0x20a0a0 ldr r12, [sp, #0xc]
 *   @0x20a0a4 str r12, [r1]
 *   @0x20a0a8 str r12, [r1, #0x8]
 *   @0x20a0ac str r1, [sp, #0x8]
 *   @0x20a0b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a0b4 ldr r1, [sp, #0x8]
 *   @0x20a0b8 ldr r3, [sp, #0x4]
 *   @0x20a0bc ldr r12, [r1, #0x4]
 *   @0x20a0c0 sub r12, r12, #1
 *   @0x20a0c4 str r12, [r1, #0x4]
 *   @0x20a0c8 cmp r12, #0
 *   @0x20a0cc bne 0x20a110 <_ZN12CDS_Priority6AssignEPS_+0x698>
 *   @0x20a0d0 ldr r0, [r1]
 *   @0x20a0d4 str r1, [sp, #0x8]
 *   @0x20a0d8 str r12, [sp, #0xc]
 *   @0x20a0dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a0e0 ldr r1, [sp, #0x8]
 *   @0x20a0e4 ldr r12, [sp, #0xc]
 *   @0x20a0e8 mov r0, r1
 *   @0x20a0ec str r12, [r1]
 *   @0x20a0f0 str r12, [r1, #0x8]
 *   @0x20a0f4 str r1, [sp, #0x8]
 *   @0x20a0f8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20a0fc ldr r1, [sp, #0x8]
 *   @0x20a100 mov r0, r1
 *   @0x20a104 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a108 ldr r3, [sp, #0x4]
 *   @0x20a10c ldr r1, [sp, #0x8]
 *   @0x20a110 str r3, [sp, #0x4]
 *   @0x20a114 str r1, [sp, #0x8]
 *   @0x20a118 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a11c ldr r1, [sp, #0x8]
 *   @0x20a120 mov r0, r1
 *   @0x20a124 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a128 ldr r3, [sp, #0x4]
 *   @0x20a12c ldr r1, [sp, #0x8]
 *   @0x20a130 b 0x209f58 <_ZN12CDS_Priority6AssignEPS_+0x4e0>
 *   @0x20a134 add sp, sp, #20
 *   @0x20a138 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20a13c b 0x209768 <_ZN12CDS_Priority5ClearEv>
 *   @0x20a140 andseq r9, r4, r8, asr #26
 *   @0x20a144 andseq r9, r4, r8, asr #24
 *
 * ══ §3/20 F_ScriptExecute(RValue&, CInstance*, CInstance*, int, RValue*)  0x132f70  size 1720  430 条（0x132f70..0x133628）
 * @func 0x132f70 0x133628  size 1720  430 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / FREE_RValue__Pre(RValue*)×4 / YYGetInt32(RValue const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2
 * 字段偏移 top8: 0x8×22 / 0xc×19 / 0x4×17 / 0x10×8 / 0x28×8 / 0x-c×6 / 0x160×5 / 0x34×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x132f70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x132f74 sub sp, sp, #316
 *   @0x132f78 add r12, sp, #56
 *   @0x132f7c ldr r10, [pc, #0x68c]
 *   @0x132f80 str r0, [sp, #0xc]
 *   @0x132f84 mov r5, r3
 *   @0x132f88 str r1, [sp, #0x14]
 *   @0x132f8c mov r0, r12
 *   @0x132f90 str r2, [sp, #0x18]
 *   @0x132f94 mov r1, #0
 *   @0x132f98 mov r2, #256
 *   @0x132f9c str r12, [sp, #0x10]
 *   @0x132fa0 bl 0xb65b0 <memset@plt>
 *   @0x132fa4 ldr r3, [pc, #0x668]
 *   @0x132fa8 add r10, pc, r10
 *   @0x132fac mov r1, #0
 *   @0x132fb0 str r1, [sp, #0x28]
 *   @0x132fb4 str r1, [sp, #0x2c]
 *   @0x132fb8 str r1, [sp, #0x30]
 *   @0x132fbc str r1, [sp, #0x34]
 *   @0x132fc0 ldr r3, [r10, r3]
 *   @0x132fc4 ldrb r3, [r3]
 *   @0x132fc8 cmp r3, r1
 *   @0x132fcc beq 0x132fe4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x132fd0 ldr r12, [sp, #0x160]
 *   @0x132fd4 ldr r3, [r12, #0xc]
 *   @0x132fd8 bic r3, r3, #-16777216
 *   @0x132fdc cmp r3, #6
 *   @0x132fe0 beq 0x133320 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3b0>
 *   @0x132fe4 mov r1, #0
 *   @0x132fe8 ldr r0, [sp, #0x160]
 *   @0x132fec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x132ff0 bl 0x1e0544 <_Z13Script_Existsi>
 *   @0x132ff4 subs r1, r0, #0
 *   @0x132ff8 beq 0x1333a0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x430>
 *   @0x132ffc cmp r5, #1
 *   @0x133000 suble r5, r5, #1
 *   @0x133004 ble 0x1330d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x133008 cmp r5, #16
 *   @0x13300c movge r5, #16
 *   @0x133010 mov r11, #0
 *   @0x133014 sub r8, r5, #1
 *   @0x133018 ldr r5, [sp, #0x160]
 *   @0x13301c add r6, sp, #68
 *   @0x133020 add r4, sp, #56
 *   @0x133024 mov r7, r11
 *   @0x133028 str r10, [sp, #0x1c]
 *   @0x13302c ldr r2, [r4, #0xc]
 *   @0x133030 add r9, r5, #16
 *   @0x133034 bic r3, r2, #-16777216
 *   @0x133038 cmp r3, #1
 *   @0x13303c beq 0x1332f0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x380>
 *   @0x133040 cmp r3, #2
 *   @0x133044 bne 0x133068 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x133048 sub r2, r2, #1
 *   @0x13304c bic r2, r2, #-16777216
 *   @0x133050 bic r2, r2, #3
 *   @0x133054 cmp r2, #0
 *   @0x133058 beq 0x133394 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x424>
 *   @0x13305c mov r0, #5
 *   @0x133060 str r7, [r4, #0x8]
 *   @0x133064 str r0, [r4, #0xc]
 *   @0x133068 str r7, [r6, #-0xc]
 *   @0x13306c ldr r3, [r5, #0x1c]
 *   @0x133070 str r3, [r4, #0xc]
 *   @0x133074 ldr r3, [r5, #0x18]
 *   @0x133078 str r3, [r4, #0x8]
 *   @0x13307c ldr r3, [r5, #0x1c]
 *   @0x133080 bic r3, r3, #-16777216
 *   @0x133084 cmp r3, #14
 *   @0x133088 addls pc, pc, r3, lsl #2
 *   @0x13308c b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x133090 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x133094 b 0x133230 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x133098 b 0x133204 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x13309c b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1330a0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330a4 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330a8 b 0x133248 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2d8>
 *   @0x1330ac b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1330b0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330b4 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330b8 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x1330bc b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330c0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x1330c4 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x1330c8 b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1330cc ldr r10, [sp, #0x1c]
 *   @0x1330d0 mov r5, r11
 *   @0x1330d4 ldr r3, [pc, #0x53c]
 *   @0x1330d8 add r2, sp, #56
 *   @0x1330dc str r5, [sp, #0x20]
 *   @0x1330e0 mov r1, #0
 *   @0x1330e4 str r2, [sp, #0x24]
 *   @0x1330e8 add r4, sp, #40
 *   @0x1330ec ldr r6, [r10, r3]
 *   @0x1330f0 ldr r0, [sp, #0x160]
 *   @0x1330f4 ldr r7, [r6]
 *   @0x1330f8 str r5, [r6]
 *   @0x1330fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133100 mov r3, r5
 *   @0x133104 add r12, sp, #32
 *   @0x133108 ldr r1, [sp, #0x14]
 *   @0x13310c ldr r2, [sp, #0x18]
 *   @0x133110 str r4, [sp]
 *   @0x133114 str r12, [sp, #0x4]
 *   @0x133118 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x13311c ldr r3, [pc, #0x4f8]
 *   @0x133120 str r7, [r6]
 *   @0x133124 ldr r3, [r10, r3]
 *   @0x133128 ldrb r3, [r3]
 *   @0x13312c cmp r3, #0
 *   @0x133130 bne 0x1333f0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x480>
 *   @0x133134 ldr r12, [sp, #0xc]
 *   @0x133138 ldr r2, [r12, #0xc]
 *   @0x13313c bic r3, r2, #-16777216
 *   @0x133140 cmp r3, #1
 *   @0x133144 beq 0x1333b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x444>
 *   @0x133148 cmp r3, #2
 *   @0x13314c bne 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x133150 sub r3, r2, #1
 *   @0x133154 bic r3, r3, #-16777216
 *   @0x133158 bic r3, r3, #3
 *   @0x13315c cmp r3, #0
 *   @0x133160 bne 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x133164 ldr r0, [sp, #0xc]
 *   @0x133168 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x13316c ldr r12, [sp, #0xc]
 *   @0x133170 mov r0, #0
 *   @0x133174 ldr r3, [sp, #0x34]
 *   @0x133178 ldr r1, [sp, #0x30]
 *   @0x13317c bic r2, r3, #-16777216
 *   @0x133180 str r0, [r12]
 *   @0x133184 str r3, [r12, #0xc]
 *   @0x133188 str r1, [r12, #0x8]
 *   @0x13318c cmp r2, #14
 *   @0x133190 addls pc, pc, r2, lsl #2
 *   @0x133194 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x133198 b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x13319c b 0x133478 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x508>
 *   @0x1331a0 b 0x133448 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x4d8>
 *   @0x1331a4 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x1331a8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331ac b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331b0 b 0x133420 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x4b0>
 *   @0x1331b4 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x1331b8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331bc b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331c0 b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x1331c4 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331c8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x1331cc b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x1331d0 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x1331d4 ldr r3, [r5, #0x10]
 *   @0x1331d8 str r3, [r6, #-0xc]
 *   @0x1331dc add r11, r11, #1
 *   @0x1331e0 add r6, r6, #16
 *   @0x1331e4 cmp r11, r8
 *   @0x1331e8 add r4, r4, #16
 *   @0x1331ec beq 0x1330cc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1331f0 mov r5, r9
 *   @0x1331f4 b 0x13302c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1331f8 ldm r9, {r2, r3}
 *   @0x1331fc stm r4, {r2, r3}
 *   @0x133200 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x133204 ldr r3, [r5, #0x10]
 *   @0x133208 cmp r3, #0
 *   @0x13320c str r3, [r6, #-0xc]
 *   @0x133210 beq 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x133214 ldr r1, [r3, #0x8]
 *   @0x133218 ldr r2, [r3]
 *   @0x13321c cmp r1, #0
 *   @0x133220 streq r4, [r3, #0x8]
 *   @0x133224 add r2, r2, #1
 *   @0x133228 str r2, [r3]
 *   @0x13322c b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x133230 ldr r3, [r5, #0x10]
 *   @0x133234 cmp r3, #0
 *   @0x133238 ldrne r2, [r3, #0x4]
 *   @0x13323c addne r2, r2, #1
 *   @0x133240 strne r2, [r3, #0x4]
 *   @0x133244 b 0x1331d8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x133248 ldr r3, [r5, #0x10]
 *   @0x13324c str r3, [r6, #-0xc]
 *   @0x133250 ldr r3, [r5, #0x10]
 *   @0x133254 cmp r3, #0
 *   @0x133258 beq 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x13325c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x133260 ldr r1, [r5, #0x10]
 *   @0x133264 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x133268 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x13326c ldr r2, [sp, #0x28]
 *   @0x133270 ldr r12, [sp, #0xc]
 *   @0x133274 str r2, [r12]
 *   @0x133278 sub r3, r3, #1
 *   @0x13327c bic r3, r3, #-16777216
 *   @0x133280 bic r3, r3, #3
 *   @0x133284 cmp r3, #0
 *   @0x133288 beq 0x133494 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x13328c cmp r5, #0
 *   @0x133290 mov r4, #0
 *   @0x133294 mov r7, #5
 *   @0x133298 str r4, [sp, #0x30]
 *   @0x13329c str r4, [sp, #0x28]
 *   @0x1332a0 str r7, [sp, #0x34]
 *   @0x1332a4 ble 0x13334c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3dc>
 *   @0x1332a8 add r11, sp, #56
 *   @0x1332ac mov r6, r4
 *   @0x1332b0 b 0x1332c8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x1332b4 cmp r4, r5
 *   @0x1332b8 str r6, [r11, #0x8]
 *   @0x1332bc str r7, [r11, #0xc]
 *   @0x1332c0 str r6, [r11], #16
 *   @0x1332c4 beq 0x13334c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3dc>
 *   @0x1332c8 ldr r3, [r11, #0xc]
 *   @0x1332cc add r4, r4, #1
 *   @0x1332d0 sub r3, r3, #1
 *   @0x1332d4 bic r3, r3, #-16777216
 *   @0x1332d8 bic r3, r3, #3
 *   @0x1332dc cmp r3, #0
 *   @0x1332e0 bne 0x1332b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x344>
 *   @0x1332e4 mov r0, r11
 *   @0x1332e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1332ec b 0x1332b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x344>
 *   @0x1332f0 ldr r10, [r6, #-0xc]
 *   @0x1332f4 cmp r10, #0
 *   @0x1332f8 beq 0x133318 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3a8>
 *   @0x1332fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x133300 ldr r2, [r10, #0x4]
 *   @0x133304 sub r2, r2, #1
 *   @0x133308 str r2, [r10, #0x4]
 *   @0x13330c cmp r2, #0
 *   @0x133310 beq 0x133354 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3e4>
 *   @0x133314 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x133318 str r7, [r6, #-0xc]
 *   @0x13331c b 0x133068 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x133320 ldr r0, [r12]
 *   @0x133324 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0x133328 cmp r0, #0
 *   @0x13332c beq 0x132fe4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x133330 ldr r2, [sp, #0x160]
 *   @0x133334 sub r3, r5, #1
 *   @0x133338 ldr r0, [sp, #0x14]
 *   @0x13333c add r12, r2, #16
 *   @0x133340 ldr r1, [sp, #0xc]
 *   @0x133344 str r12, [sp]
 *   @0x133348 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x13334c add sp, sp, #316
 *   @0x133350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x133354 ldr r0, [r10]
 *   @0x133358 str r2, [sp, #0x8]
 *   @0x13335c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x133360 ldr r2, [sp, #0x8]
 *   @0x133364 str r2, [r10]
 *   @0x133368 str r2, [r10, #0x8]
 *   @0x13336c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x133370 ldr r2, [r10, #0x4]
 *   @0x133374 sub r2, r2, #1
 *   @0x133378 str r2, [r10, #0x4]
 *   @0x13337c cmp r2, #0
 *   @0x133380 beq 0x1334a0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x530>
 *   @0x133384 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x133388 mov r0, r10
 *   @0x13338c bl 0x27d1d0 <_ZdlPv>
 *   @0x133390 b 0x133314 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3a4>
 *   @0x133394 mov r0, r4
 *   @0x133398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x13339c b 0x13305c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1333a0 ldr r0, [pc, #0x278]
 *   @0x1333a4 add r0, pc, r0
 *   @0x1333a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1333ac add sp, sp, #316
 *   @0x1333b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1333b4 ldr r12, [sp, #0xc]
 *   @0x1333b8 ldr r6, [r12]
 *   @0x1333bc cmp r6, #0
 *   @0x1333c0 beq 0x1333e0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x470>
 *   @0x1333c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1333c8 ldr r7, [r6, #0x4]
 *   @0x1333cc sub r7, r7, #1
 *   @0x1333d0 str r7, [r6, #0x4]
 *   @0x1333d4 cmp r7, #0
 *   @0x1333d8 beq 0x1334e0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x570>
 *   @0x1333dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1333e0 ldr r12, [sp, #0xc]
 *   @0x1333e4 mov r3, #0
 *   @0x1333e8 str r3, [r12]
 *   @0x1333ec b 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x1333f0 ldr r3, [pc, #0x22c]
 *   @0x1333f4 mov r1, #0
 *   @0x1333f8 ldr r3, [r10, r3]
 *   @0x1333fc ldr r3, [r3]
 *   @0x133400 ldr r0, [r3]
 *   @0x133404 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133408 b 0x133134 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x13340c ldr r1, [sp, #0x28]
 *   @0x133410 ldr r2, [sp, #0x2c]
 *   @0x133414 ldr r12, [sp, #0xc]
 *   @0x133418 stm r12, {r1, r2}
 *   @0x13341c b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x133420 ldr r2, [sp, #0x28]
 *   @0x133424 ldr r12, [sp, #0xc]
 *   @0x133428 cmp r2, #0
 *   @0x13342c str r2, [r12]
 *   @0x133430 beq 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x133434 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x133438 ldr r1, [sp, #0x28]
 *   @0x13343c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x133440 ldr r3, [sp, #0x34]
 *   @0x133444 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x133448 ldr r2, [sp, #0x28]
 *   @0x13344c ldr r12, [sp, #0xc]
 *   @0x133450 cmp r2, #0
 *   @0x133454 str r2, [r12]
 *   @0x133458 beq 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x13345c ldr r0, [r2, #0x8]
 *   @0x133460 ldr r1, [r2]
 *   @0x133464 cmp r0, #0
 *   @0x133468 streq r12, [r2, #0x8]
 *   @0x13346c add r1, r1, #1
 *   @0x133470 str r1, [r2]
 *   @0x133474 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x133478 ldr r2, [sp, #0x28]
 *   @0x13347c cmp r2, #0
 *   @0x133480 ldrne r3, [r2, #0x4]
 *   @0x133484 addne r3, r3, #1
 *   @0x133488 strne r3, [r2, #0x4]
 *   @0x13348c ldrne r3, [sp, #0x34]
 *   @0x133490 b 0x133270 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x133494 mov r0, r4
 *   @0x133498 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x13349c b 0x13328c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x31c>
 *   @0x1334a0 ldr r0, [r10]
 *   @0x1334a4 str r2, [sp, #0x8]
 *   @0x1334a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1334ac ldr r2, [sp, #0x8]
 *   @0x1334b0 str r2, [r10]
 *   @0x1334b4 str r2, [r10, #0x8]
 *   @0x1334b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1334bc ldr r2, [r10, #0x4]
 *   @0x1334c0 sub r2, r2, #1
 *   @0x1334c4 str r2, [r10, #0x4]
 *   @0x1334c8 cmp r2, #0
 *   @0x1334cc beq 0x133550 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5e0>
 *   @0x1334d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1334d4 mov r0, r10
 *   @0x1334d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1334dc b 0x133384 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x414>
 *   @0x1334e0 ldr r0, [r6]
 *   @0x1334e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1334e8 str r7, [r6]
 *   @0x1334ec str r7, [r6, #0x8]
 *   @0x1334f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1334f4 ldr r7, [r6, #0x4]
 *   @0x1334f8 sub r7, r7, #1
 *   @0x1334fc str r7, [r6, #0x4]
 *   @0x133500 cmp r7, #0
 *   @0x133504 beq 0x133518 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5a8>
 *   @0x133508 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x13350c mov r0, r6
 *   @0x133510 bl 0x27d1d0 <_ZdlPv>
 *   @0x133514 b 0x1333dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x46c>
 *   @0x133518 ldr r0, [r6]
 *   @0x13351c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x133520 str r7, [r6]
 *   @0x133524 str r7, [r6, #0x8]
 *   @0x133528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x13352c ldr r7, [r6, #0x4]
 *   @0x133530 sub r7, r7, #1
 *   @0x133534 str r7, [r6, #0x4]
 *   @0x133538 cmp r7, #0
 *   @0x13353c beq 0x1335b8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x648>
 *   @0x133540 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x133544 mov r0, r6
 *   @0x133548 bl 0x27d1d0 <_ZdlPv>
 *   @0x13354c b 0x133508 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x598>
 *   @0x133550 ldr r0, [r10]
 *   @0x133554 str r2, [sp, #0x8]
 *   @0x133558 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13355c ldr r2, [sp, #0x8]
 *   @0x133560 str r2, [r10]
 *   @0x133564 str r2, [r10, #0x8]
 *   @0x133568 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x13356c ldr r2, [r10, #0x4]
 *   @0x133570 sub r2, r2, #1
 *   @0x133574 str r2, [r10, #0x4]
 *   @0x133578 cmp r2, #0
 *   @0x13357c bne 0x1335a8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x638>
 *   @0x133580 ldr r0, [r10]
 *   @0x133584 str r2, [sp, #0x8]
 *   @0x133588 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13358c ldr r2, [sp, #0x8]
 *   @0x133590 mov r0, r10
 *   @0x133594 str r2, [r10]
 *   @0x133598 str r2, [r10, #0x8]
 *   @0x13359c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1335a0 mov r0, r10
 *   @0x1335a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1335a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1335ac mov r0, r10
 *   @0x1335b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1335b4 b 0x1334d0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x560>
 *   @0x1335b8 ldr r0, [r6]
 *   @0x1335bc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1335c0 str r7, [r6]
 *   @0x1335c4 str r7, [r6, #0x8]
 *   @0x1335c8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1335cc ldr r7, [r6, #0x4]
 *   @0x1335d0 sub r7, r7, #1
 *   @0x1335d4 str r7, [r6, #0x4]
 *   @0x1335d8 cmp r7, #0
 *   @0x1335dc bne 0x133600 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x690>
 *   @0x1335e0 ldr r0, [r6]
 *   @0x1335e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1335e8 mov r0, r6
 *   @0x1335ec str r7, [r6]
 *   @0x1335f0 str r7, [r6, #0x8]
 *   @0x1335f4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1335f8 mov r0, r6
 *   @0x1335fc bl 0x27d1d0 <_ZdlPv>
 *   @0x133600 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x133604 mov r0, r6
 *   @0x133608 bl 0x27d1d0 <_ZdlPv>
 *   @0x13360c b 0x133540 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5d0>
 *   @0x133610 eoreq lr, r11, r8, lsr #25
 *   @0x133614 .word 0xffffbf68
 *   @0x133618 .word 0xffffc0bc
 *   @0x13361c .word 0xffffbf14
 *   @0x133620 .word 0x0020bfb4
 *   @0x133624 .word 0xffffbf20
 *
 * ══ §4/20 CCameraManager::SetupGMLFunctions()  0x16ddac  size 1712  428 条（0x16ddac..0x16e45c）
 * @func 0x16ddac 0x16e45c  size 1712  428 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_Add(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×46
 * 字段偏移 top8: 0x510×2 / 0x4fc×2 / 0x4e8×2 / 0x4d4×2 / 0x4c0×2 / 0x4ac×2 / 0x498×2 / 0x484×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ddac push {r4, lr}
 *   @0x16ddb0 mov r2, #0
 *   @0x16ddb4 ldr r4, [pc, #0x524]
 *   @0x16ddb8 mov r3, #1
 *   @0x16ddbc ldr r1, [pc, #0x520]
 *   @0x16ddc0 add r4, pc, r4
 *   @0x16ddc4 ldr r0, [pc, #0x51c]
 *   @0x16ddc8 ldr r1, [r4, r1]
 *   @0x16ddcc add r0, pc, r0
 *   @0x16ddd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16ddd4 ldr r1, [pc, #0x510]
 *   @0x16ddd8 ldr r0, [pc, #0x510]
 *   @0x16dddc mov r2, #4
 *   @0x16dde0 mov r3, #1
 *   @0x16dde4 ldr r1, [r4, r1]
 *   @0x16dde8 add r0, pc, r0
 *   @0x16ddec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16ddf0 ldr r1, [pc, #0x4fc]
 *   @0x16ddf4 ldr r0, [pc, #0x4fc]
 *   @0x16ddf8 mov r2, #1
 *   @0x16ddfc mov r3, r2
 *   @0x16de00 ldr r1, [r4, r1]
 *   @0x16de04 add r0, pc, r0
 *   @0x16de08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de0c ldr r1, [pc, #0x4e8]
 *   @0x16de10 ldr r0, [pc, #0x4e8]
 *   @0x16de14 mov r2, #1
 *   @0x16de18 mov r3, r2
 *   @0x16de1c ldr r1, [r4, r1]
 *   @0x16de20 add r0, pc, r0
 *   @0x16de24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de28 ldr r1, [pc, #0x4d4]
 *   @0x16de2c ldr r0, [pc, #0x4d4]
 *   @0x16de30 mov r2, #0
 *   @0x16de34 mov r3, #1
 *   @0x16de38 ldr r1, [r4, r1]
 *   @0x16de3c add r0, pc, r0
 *   @0x16de40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de44 ldr r1, [pc, #0x4c0]
 *   @0x16de48 ldr r0, [pc, #0x4c0]
 *   @0x16de4c mov r2, #0
 *   @0x16de50 mov r3, #1
 *   @0x16de54 ldr r1, [r4, r1]
 *   @0x16de58 add r0, pc, r0
 *   @0x16de5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de60 ldr r1, [pc, #0x4ac]
 *   @0x16de64 ldr r0, [pc, #0x4ac]
 *   @0x16de68 mov r2, #1
 *   @0x16de6c mov r3, r2
 *   @0x16de70 ldr r1, [r4, r1]
 *   @0x16de74 add r0, pc, r0
 *   @0x16de78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de7c ldr r1, [pc, #0x498]
 *   @0x16de80 ldr r0, [pc, #0x498]
 *   @0x16de84 mov r2, #2
 *   @0x16de88 mov r3, #1
 *   @0x16de8c ldr r1, [r4, r1]
 *   @0x16de90 add r0, pc, r0
 *   @0x16de94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16de98 ldr r1, [pc, #0x484]
 *   @0x16de9c ldr r0, [pc, #0x484]
 *   @0x16dea0 mov r2, #2
 *   @0x16dea4 mov r3, #1
 *   @0x16dea8 ldr r1, [r4, r1]
 *   @0x16deac add r0, pc, r0
 *   @0x16deb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16deb4 ldr r1, [pc, #0x470]
 *   @0x16deb8 ldr r0, [pc, #0x470]
 *   @0x16debc mov r2, #2
 *   @0x16dec0 mov r3, #1
 *   @0x16dec4 ldr r1, [r4, r1]
 *   @0x16dec8 add r0, pc, r0
 *   @0x16decc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16ded0 ldr r1, [pc, #0x45c]
 *   @0x16ded4 ldr r0, [pc, #0x45c]
 *   @0x16ded8 mov r2, #2
 *   @0x16dedc mov r3, #1
 *   @0x16dee0 ldr r1, [r4, r1]
 *   @0x16dee4 add r0, pc, r0
 *   @0x16dee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16deec ldr r1, [pc, #0x448]
 *   @0x16def0 ldr r0, [pc, #0x448]
 *   @0x16def4 mov r2, #2
 *   @0x16def8 mov r3, #1
 *   @0x16defc ldr r1, [r4, r1]
 *   @0x16df00 add r0, pc, r0
 *   @0x16df04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df08 ldr r1, [pc, #0x434]
 *   @0x16df0c ldr r0, [pc, #0x434]
 *   @0x16df10 mov r2, #3
 *   @0x16df14 mov r3, #1
 *   @0x16df18 ldr r1, [r4, r1]
 *   @0x16df1c add r0, pc, r0
 *   @0x16df20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df24 ldr r1, [pc, #0x420]
 *   @0x16df28 ldr r0, [pc, #0x420]
 *   @0x16df2c mov r2, #3
 *   @0x16df30 mov r3, #1
 *   @0x16df34 ldr r1, [r4, r1]
 *   @0x16df38 add r0, pc, r0
 *   @0x16df3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df40 ldr r1, [pc, #0x40c]
 *   @0x16df44 ldr r0, [pc, #0x40c]
 *   @0x16df48 mov r2, #3
 *   @0x16df4c mov r3, #1
 *   @0x16df50 ldr r1, [r4, r1]
 *   @0x16df54 add r0, pc, r0
 *   @0x16df58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df5c ldr r1, [pc, #0x3f8]
 *   @0x16df60 ldr r0, [pc, #0x3f8]
 *   @0x16df64 mov r2, #3
 *   @0x16df68 mov r3, #1
 *   @0x16df6c ldr r1, [r4, r1]
 *   @0x16df70 add r0, pc, r0
 *   @0x16df74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df78 ldr r1, [pc, #0x3e4]
 *   @0x16df7c ldr r0, [pc, #0x3e4]
 *   @0x16df80 mov r2, #2
 *   @0x16df84 mov r3, #1
 *   @0x16df88 ldr r1, [r4, r1]
 *   @0x16df8c add r0, pc, r0
 *   @0x16df90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16df94 ldr r1, [pc, #0x3d0]
 *   @0x16df98 ldr r0, [pc, #0x3d0]
 *   @0x16df9c mov r2, #2
 *   @0x16dfa0 mov r3, #1
 *   @0x16dfa4 ldr r1, [r4, r1]
 *   @0x16dfa8 add r0, pc, r0
 *   @0x16dfac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16dfb0 ldr r1, [pc, #0x3bc]
 *   @0x16dfb4 ldr r0, [pc, #0x3bc]
 *   @0x16dfb8 mov r2, #1
 *   @0x16dfbc mov r3, r2
 *   @0x16dfc0 ldr r1, [r4, r1]
 *   @0x16dfc4 add r0, pc, r0
 *   @0x16dfc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16dfcc ldr r1, [pc, #0x3a8]
 *   @0x16dfd0 ldr r0, [pc, #0x3a8]
 *   @0x16dfd4 mov r2, #1
 *   @0x16dfd8 mov r3, r2
 *   @0x16dfdc ldr r1, [r4, r1]
 *   @0x16dfe0 add r0, pc, r0
 *   @0x16dfe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16dfe8 ldr r1, [pc, #0x394]
 *   @0x16dfec ldr r0, [pc, #0x394]
 *   @0x16dff0 mov r2, #1
 *   @0x16dff4 mov r3, r2
 *   @0x16dff8 ldr r1, [r4, r1]
 *   @0x16dffc add r0, pc, r0
 *   @0x16e000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e004 ldr r1, [pc, #0x380]
 *   @0x16e008 ldr r0, [pc, #0x380]
 *   @0x16e00c mov r2, #1
 *   @0x16e010 mov r3, r2
 *   @0x16e014 ldr r1, [r4, r1]
 *   @0x16e018 add r0, pc, r0
 *   @0x16e01c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e020 ldr r1, [pc, #0x36c]
 *   @0x16e024 ldr r0, [pc, #0x36c]
 *   @0x16e028 mov r2, #1
 *   @0x16e02c mov r3, r2
 *   @0x16e030 ldr r1, [r4, r1]
 *   @0x16e034 add r0, pc, r0
 *   @0x16e038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e03c ldr r1, [pc, #0x358]
 *   @0x16e040 ldr r0, [pc, #0x358]
 *   @0x16e044 mov r2, #1
 *   @0x16e048 mov r3, r2
 *   @0x16e04c ldr r1, [r4, r1]
 *   @0x16e050 add r0, pc, r0
 *   @0x16e054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e058 ldr r1, [pc, #0x344]
 *   @0x16e05c ldr r0, [pc, #0x344]
 *   @0x16e060 mov r2, #1
 *   @0x16e064 mov r3, r2
 *   @0x16e068 ldr r1, [r4, r1]
 *   @0x16e06c add r0, pc, r0
 *   @0x16e070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e074 ldr r1, [pc, #0x330]
 *   @0x16e078 ldr r0, [pc, #0x330]
 *   @0x16e07c mov r2, #1
 *   @0x16e080 mov r3, r2
 *   @0x16e084 ldr r1, [r4, r1]
 *   @0x16e088 add r0, pc, r0
 *   @0x16e08c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e090 ldr r1, [pc, #0x31c]
 *   @0x16e094 ldr r0, [pc, #0x31c]
 *   @0x16e098 mov r2, #1
 *   @0x16e09c mov r3, r2
 *   @0x16e0a0 ldr r1, [r4, r1]
 *   @0x16e0a4 add r0, pc, r0
 *   @0x16e0a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e0ac ldr r1, [pc, #0x308]
 *   @0x16e0b0 ldr r0, [pc, #0x308]
 *   @0x16e0b4 mov r2, #1
 *   @0x16e0b8 mov r3, r2
 *   @0x16e0bc ldr r1, [r4, r1]
 *   @0x16e0c0 add r0, pc, r0
 *   @0x16e0c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e0c8 ldr r1, [pc, #0x2f4]
 *   @0x16e0cc ldr r0, [pc, #0x2f4]
 *   @0x16e0d0 mov r2, #1
 *   @0x16e0d4 mov r3, r2
 *   @0x16e0d8 ldr r1, [r4, r1]
 *   @0x16e0dc add r0, pc, r0
 *   @0x16e0e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e0e4 ldr r1, [pc, #0x2e0]
 *   @0x16e0e8 ldr r0, [pc, #0x2e0]
 *   @0x16e0ec mov r2, #1
 *   @0x16e0f0 mov r3, r2
 *   @0x16e0f4 ldr r1, [r4, r1]
 *   @0x16e0f8 add r0, pc, r0
 *   @0x16e0fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e100 ldr r1, [pc, #0x2cc]
 *   @0x16e104 ldr r0, [pc, #0x2cc]
 *   @0x16e108 mov r2, #1
 *   @0x16e10c mov r3, r2
 *   @0x16e110 ldr r1, [r4, r1]
 *   @0x16e114 add r0, pc, r0
 *   @0x16e118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e11c ldr r1, [pc, #0x2b8]
 *   @0x16e120 ldr r0, [pc, #0x2b8]
 *   @0x16e124 mov r2, #1
 *   @0x16e128 mov r3, r2
 *   @0x16e12c ldr r1, [r4, r1]
 *   @0x16e130 add r0, pc, r0
 *   @0x16e134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e138 ldr r1, [pc, #0x2a4]
 *   @0x16e13c ldr r0, [pc, #0x2a4]
 *   @0x16e140 mov r2, #1
 *   @0x16e144 mov r3, r2
 *   @0x16e148 ldr r1, [r4, r1]
 *   @0x16e14c add r0, pc, r0
 *   @0x16e150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e154 ldr r1, [pc, #0x290]
 *   @0x16e158 ldr r0, [pc, #0x290]
 *   @0x16e15c mov r2, #1
 *   @0x16e160 mov r3, r2
 *   @0x16e164 ldr r1, [r4, r1]
 *   @0x16e168 add r0, pc, r0
 *   @0x16e16c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e170 ldr r1, [pc, #0x27c]
 *   @0x16e174 ldr r0, [pc, #0x27c]
 *   @0x16e178 mov r2, #1
 *   @0x16e17c mov r3, r2
 *   @0x16e180 ldr r1, [r4, r1]
 *   @0x16e184 add r0, pc, r0
 *   @0x16e188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e18c ldr r1, [pc, #0x268]
 *   @0x16e190 ldr r0, [pc, #0x268]
 *   @0x16e194 mov r2, #1
 *   @0x16e198 mov r3, r2
 *   @0x16e19c ldr r1, [r4, r1]
 *   @0x16e1a0 add r0, pc, r0
 *   @0x16e1a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e1a8 ldr r1, [pc, #0x254]
 *   @0x16e1ac ldr r0, [pc, #0x254]
 *   @0x16e1b0 mov r2, #1
 *   @0x16e1b4 mov r3, r2
 *   @0x16e1b8 ldr r1, [r4, r1]
 *   @0x16e1bc add r0, pc, r0
 *   @0x16e1c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e1c4 ldr r1, [pc, #0x240]
 *   @0x16e1c8 ldr r0, [pc, #0x240]
 *   @0x16e1cc mov r2, #1
 *   @0x16e1d0 mov r3, r2
 *   @0x16e1d4 ldr r1, [r4, r1]
 *   @0x16e1d8 add r0, pc, r0
 *   @0x16e1dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e1e0 ldr r1, [pc, #0x22c]
 *   @0x16e1e4 ldr r0, [pc, #0x22c]
 *   @0x16e1e8 mov r2, #1
 *   @0x16e1ec mov r3, r2
 *   @0x16e1f0 ldr r1, [r4, r1]
 *   @0x16e1f4 add r0, pc, r0
 *   @0x16e1f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e1fc ldr r1, [pc, #0x218]
 *   @0x16e200 ldr r0, [pc, #0x218]
 *   @0x16e204 mov r2, #1
 *   @0x16e208 mov r3, r2
 *   @0x16e20c ldr r1, [r4, r1]
 *   @0x16e210 add r0, pc, r0
 *   @0x16e214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e218 ldr r1, [pc, #0x204]
 *   @0x16e21c ldr r0, [pc, #0x204]
 *   @0x16e220 mov r2, #2
 *   @0x16e224 mov r3, #1
 *   @0x16e228 ldr r1, [r4, r1]
 *   @0x16e22c add r0, pc, r0
 *   @0x16e230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e234 ldr r1, [pc, #0x1f0]
 *   @0x16e238 ldr r0, [pc, #0x1f0]
 *   @0x16e23c mov r2, #2
 *   @0x16e240 mov r3, #1
 *   @0x16e244 ldr r1, [r4, r1]
 *   @0x16e248 add r0, pc, r0
 *   @0x16e24c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e250 ldr r1, [pc, #0x1dc]
 *   @0x16e254 ldr r0, [pc, #0x1dc]
 *   @0x16e258 mov r2, #2
 *   @0x16e25c mov r3, #1
 *   @0x16e260 ldr r1, [r4, r1]
 *   @0x16e264 add r0, pc, r0
 *   @0x16e268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e26c ldr r1, [pc, #0x1c8]
 *   @0x16e270 ldr r0, [pc, #0x1c8]
 *   @0x16e274 mov r2, #2
 *   @0x16e278 mov r3, #1
 *   @0x16e27c ldr r1, [r4, r1]
 *   @0x16e280 add r0, pc, r0
 *   @0x16e284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e288 ldr r1, [pc, #0x1b4]
 *   @0x16e28c ldr r0, [pc, #0x1b4]
 *   @0x16e290 mov r2, #2
 *   @0x16e294 mov r3, #1
 *   @0x16e298 ldr r1, [r4, r1]
 *   @0x16e29c add r0, pc, r0
 *   @0x16e2a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e2a4 ldr r1, [pc, #0x1a0]
 *   @0x16e2a8 ldr r0, [pc, #0x1a0]
 *   @0x16e2ac mov r2, #2
 *   @0x16e2b0 mov r3, #1
 *   @0x16e2b4 ldr r1, [r4, r1]
 *   @0x16e2b8 add r0, pc, r0
 *   @0x16e2bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e2c0 ldr r1, [pc, #0x18c]
 *   @0x16e2c4 ldr r0, [pc, #0x18c]
 *   @0x16e2c8 mov r2, #2
 *   @0x16e2cc mov r3, #1
 *   @0x16e2d0 ldr r1, [r4, r1]
 *   @0x16e2d4 add r0, pc, r0
 *   @0x16e2d8 pop {r4, lr}
 *   @0x16e2dc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x16e2e0 mlaeq r8, r0, lr, r3
 *   @0x16e2e4 .word 0xffffe550
 *   @0x16e2e8 andseq r12, sp, r4, lsr #22
 *   @0x16e2ec .word 0xffffe554
 *   @0x16e2f0 andseq r12, sp, r8, lsl r11
 *   @0x16e2f4 .word 0xffffe558
 *   @0x16e2f8 andseq r12, sp, r0, lsl r11
 *   @0x16e2fc .word 0xffffe55c
 *   @0x16e300 andseq r12, sp, r4, lsl #22
 *   @0x16e304 .word 0xffffe560
 *   @0x16e308 ldrsheq r12, [sp], -r8
 *   @0x16e30c .word 0xffffe564
 *   @0x16e310 ldrsheq r12, [sp], -r0
 *   @0x16e314 .word 0xffffe568
 *   @0x16e318 andseq r12, sp, r8, ror #21
 *   @0x16e31c .word 0xffffe56c
 *   @0x16e320 andseq r12, sp, r0, ror #21
 *   @0x16e324 .word 0xffffe570
 *   @0x16e328 ldrsbeq r12, [sp], -r8
 *   @0x16e32c .word 0xffffe574
 *   @0x16e330 ldrsbeq r12, [sp], -r0
 *   @0x16e334 .word 0xffffe578
 *   @0x16e338 ldrsbeq r12, [sp], -r0
 *   @0x16e33c .word 0xffffe57c
 *   @0x16e340 andseq r12, sp, r12, asr #21
 *   @0x16e344 .word 0xffffe580
 *   @0x16e348 andseq r12, sp, r8, asr #21
 *   @0x16e34c .word 0xffffe584
 *   @0x16e350 andseq r12, sp, r0, asr #21
 *   @0x16e354 .word 0xffffe588
 *   @0x16e358 ldrheq r12, [sp], -r12
 *   @0x16e35c .word 0xffffe58c
 *   @0x16e360 ldrheq r12, [sp], -r8
 *   @0x16e364 .word 0xffffe590
 *   @0x16e368 ldrheq r12, [sp], -r4
 *   @0x16e36c .word 0xffffe594
 *   @0x16e370 ldrheq r12, [sp], -r0
 *   @0x16e374 .word 0xffffe598
 *   @0x16e378 andseq r12, sp, r12, lsr #21
 *   @0x16e37c .word 0xffffe59c
 *   @0x16e380 andseq r12, sp, r4, lsr #21
 *   @0x16e384 .word 0xffffe5a0
 *   @0x16e388 mulseq sp, r12, r10
 *   @0x16e38c .word 0xffffe5a4
 *   @0x16e390 mulseq sp, r12, r10
 *   @0x16e394 .word 0xffffe5a8
 *   @0x16e398 mulseq sp, r8, r10
 *   @0x16e39c .word 0xffffe5ac
 *   @0x16e3a0 mulseq sp, r4, r10
 *   @0x16e3a4 .word 0xffffe5b0
 *   @0x16e3a8 andseq r12, sp, r12, lsl #21
 *   @0x16e3ac .word 0xffffe5b4
 *   @0x16e3b0 andseq r12, sp, r4, lsl #21
 *   @0x16e3b4 .word 0xffffe5b8
 *   @0x16e3b8 andseq r12, sp, r0, lsl #21
 *   @0x16e3bc .word 0xffffe5bc
 *   @0x16e3c0 andseq r12, sp, r12, ror r10
 *   @0x16e3c4 .word 0xffffe5c0
 *   @0x16e3c8 andseq r12, sp, r8, ror r10
 *   @0x16e3cc .word 0xffffe5c4
 *   @0x16e3d0 andseq r12, sp, r4, ror r10
 *   @0x16e3d4 .word 0xffffe5c8
 *   @0x16e3d8 andseq r12, sp, r4, ror r10
 *   @0x16e3dc .word 0xffffe5cc
 *   @0x16e3e0 andseq r12, sp, r4, ror r10
 *   @0x16e3e4 .word 0xffffe5d0
 *   @0x16e3e8 andseq r12, sp, r0, ror r10
 *   @0x16e3ec .word 0xffffe5d4
 *   @0x16e3f0 andseq r12, sp, r12, ror #20
 *   @0x16e3f4 .word 0xffffe5d8
 *   @0x16e3f8 andseq r12, sp, r0, ror #20
 *   @0x16e3fc .word 0xffffe5dc
 *   @0x16e400 andseq r12, sp, r8, asr r10
 *   @0x16e404 .word 0xffffe5e0
 *   @0x16e408 andseq r12, sp, r12, asr #20
 *   @0x16e40c .word 0xffffe5e4
 *   @0x16e410 andseq r12, sp, r0, asr #20
 *   @0x16e414 .word 0xffffe5e8
 *   @0x16e418 andseq r12, sp, r4, lsr r10
 *   @0x16e41c .word 0xffffe5ec
 *   @0x16e420 andseq r12, sp, r8, lsr #20
 *   @0x16e424 .word 0xffffe5f0
 *   @0x16e428 andseq r12, sp, r0, lsr #20
 *   @0x16e42c .word 0xffffe5f4
 *   @0x16e430 andseq r12, sp, r4, lsl r10
 *   @0x16e434 .word 0xffffe5f8
 *   @0x16e438 andseq r12, sp, r12, lsl #20
 *   @0x16e43c .word 0xffffe5fc
 *   @0x16e440 andseq r12, sp, r0, lsl #20
 *   @0x16e444 .word 0xffffe600
 *   @0x16e448 ldrsheq r12, [sp], -r4
 *   @0x16e44c .word 0xffffe604
 *   @0x16e450 andseq r12, sp, r8, ror #19
 *   @0x16e454 .word 0xffffe608
 *   @0x16e458 ldrsbeq r12, [sp], -r12
 *
 * ══ §5/20 b2ParticleSystem::CreateParticleGroup(b2ParticleGroupDef const&)  0x2dacd0  size 1696  424 条（0x2dacd0..0x2db370）
 * @func 0x2dacd0 0x2db370  size 1696  424 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6910×2 / b2BlockAllocator::Allocate(int)×2 / b2ParticleSystem::CreateParticleGroupCallback::operator()(int, int, int) const×2 / b2ParticleSystem::GetParticleStride() const / 0xb6580 / 0xb658c / b2ParticleSystem::CreateParticleGroup(b2ParticleGroupDef const&)+0x15c / b2ParticleSystem::CreateParticleGroup(b2ParticleGroupDef const&)+0x264
 * 字段偏移 top8: 0xc×14 / 0x8×12 / 0x4×9 / 0x10×8 / 0x24×4 / 0x1c×4 / 0xd4×4 / 0x14×4
 * VFP 指令 107 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dacd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2dacd4 vpush {d8, d9, d10, d11, d12}
 *   @0x2dacd8 sub sp, sp, #116
 *   @0x2dacdc vldr s20, [pc, #868]
 *   @0x2dace0 mov r7, r1
 *   @0x2dace4 mov r9, r0
 *   @0x2dace8 bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv>
 *   @0x2dacec vmov.f32 s21, #1.000000e+00
 *   @0x2dacf0 ldr r4, [r7, #0x28]
 *   @0x2dacf4 vstr s20, [sp, #36]
 *   @0x2dacf8 ldr r1, [r9, #0x24]
 *   @0x2dacfc vstr s20, [sp, #40]
 *   @0x2dad00 cmp r4, #0
 *   @0x2dad04 vstr s20, [sp, #44]
 *   @0x2dad08 str r1, [sp, #0xc]
 *   @0x2dad0c vstr s21, [sp, #48]
 *   @0x2dad10 vmov s18, r0
 *   @0x2dad14 beq 0x2db1d8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x508>
 *   @0x2dad18 ldr r3, [pc, #0x32c]
 *   @0x2dad1c add r5, sp, #88
 *   @0x2dad20 ldr r6, [r7, #0x10]
 *   @0x2dad24 vldr s23, [r7, #8]
 *   @0x2dad28 ldr r3, [pc, r3]
 *   @0x2dad2c ldr lr, [r7]
 *   @0x2dad30 ldr r12, [r7, #0x20]
 *   @0x2dad34 vldr s22, [r7, #12]
 *   @0x2dad38 ldm r3, {r0, r1}
 *   @0x2dad3c add r3, sp, #96
 *   @0x2dad40 ldr r2, [r7, #0x30]
 *   @0x2dad44 str lr, [sp, #0x54]
 *   @0x2dad48 stm r3, {r0, r1}
 *   @0x2dad4c stm r5, {r0, r1}
 *   @0x2dad50 mov r0, r6
 *   @0x2dad54 str r12, [sp, #0x68]
 *   @0x2dad58 str r2, [sp, #0x6c]
 *   @0x2dad5c bl 0xb6580 <sinf@plt>
 *   @0x2dad60 vmov s20, r0
 *   @0x2dad64 mov r0, r6
 *   @0x2dad68 bl 0xb658c <cosf@plt>
 *   @0x2dad6c ldr r3, [r4]
 *   @0x2dad70 ldr r3, [r3, #0xc]
 *   @0x2dad74 vmov s21, r0
 *   @0x2dad78 mov r0, r4
 *   @0x2dad7c blx r3
 *   @0x2dad80 subs r11, r0, #0
 *   @0x2dad84 ble 0x2dae2c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x15c>
 *   @0x2dad88 add r8, sp, #36
 *   @0x2dad8c add r10, sp, #68
 *   @0x2dad90 mov r6, #0
 *   @0x2dad94 add r1, sp, #52
 *   @0x2dad98 str r1, [sp, #0x10]
 *   @0x2dad9c cmp r6, #0
 *   @0x2dada0 mov r3, r6
 *   @0x2dada4 mov r0, r4
 *   @0x2dada8 mov r1, r10
 *   @0x2dadac mov r2, r8
 *   @0x2dadb0 ldr r12, [r4]
 *   @0x2dadb4 beq 0x2db360 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x690>
 *   @0x2dadb8 ldr r12, [r12, #0x1c]
 *   @0x2dadbc blx r12
 *   @0x2dadc0 vldr s8, [sp, #52]
 *   @0x2dadc4 vldr s9, [sp, #68]
 *   @0x2dadc8 vcmpe.f32 s8, s9
 *   @0x2dadcc vldr s10, [sp, #56]
 *   @0x2dadd0 vldr s11, [sp, #72]
 *   @0x2dadd4 vldr s12, [sp, #60]
 *   @0x2dadd8 vldr s13, [sp, #76]
 *   @0x2daddc vldr s14, [sp, #64]
 *   @0x2dade0 vldr s15, [sp, #80]
 *   @0x2dade4 vmrs APSR_nzcv, fpscr
 *   @0x2dade8 vcmpe.f32 s10, s11
 *   @0x2dadec vmovmi.f32 s9, s8
 *   @0x2dadf0 vmrs APSR_nzcv, fpscr
 *   @0x2dadf4 vstr s9, [sp, #52]
 *   @0x2dadf8 vcmpe.f32 s12, s13
 *   @0x2dadfc vmovmi.f32 s11, s10
 *   @0x2dae00 vmrs APSR_nzcv, fpscr
 *   @0x2dae04 vstr s11, [sp, #56]
 *   @0x2dae08 vcmpe.f32 s14, s15
 *   @0x2dae0c vmovgt.f32 s13, s12
 *   @0x2dae10 vmrs APSR_nzcv, fpscr
 *   @0x2dae14 vstr s13, [sp, #60]
 *   @0x2dae18 vmovgt.f32 s15, s14
 *   @0x2dae1c vstr s15, [sp, #64]
 *   @0x2dae20 add r6, r6, #1
 *   @0x2dae24 cmp r6, r11
 *   @0x2dae28 bne 0x2dad9c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0xcc>
 *   @0x2dae2c vldr s15, [sp, #56]
 *   @0x2dae30 vdiv.f32 s15, s15, s18
 *   @0x2dae34 vmov r0, s15
 *   @0x2dae38 bl 0xb6910 <floorf@plt>
 *   @0x2dae3c vldr s24, [sp, #64]
 *   @0x2dae40 vmov s15, r0
 *   @0x2dae44 vmul.f32 s19, s15, s18
 *   @0x2dae48 vcmpe.f32 s19, s24
 *   @0x2dae4c vmrs APSR_nzcv, fpscr
 *   @0x2dae50 bpl 0x2daf48 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x278>
 *   @0x2dae54 add r8, sp, #36
 *   @0x2dae58 add r6, sp, #68
 *   @0x2dae5c add r10, sp, #84
 *   @0x2dae60 vldr s17, [sp, #60]
 *   @0x2dae64 vldr s15, [sp, #52]
 *   @0x2dae68 vdiv.f32 s15, s15, s18
 *   @0x2dae6c vmov r0, s15
 *   @0x2dae70 bl 0xb6910 <floorf@plt>
 *   @0x2dae74 vmov s15, r0
 *   @0x2dae78 vmul.f32 s16, s15, s18
 *   @0x2dae7c vcmpe.f32 s16, s17
 *   @0x2dae80 vmrs APSR_nzcv, fpscr
 *   @0x2dae84 bmi 0x2daea0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1d0>
 *   @0x2dae88 b 0x2daf38 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x268>
 *   @0x2dae8c vadd.f32 s16, s16, s18
 *   @0x2dae90 vldr s17, [sp, #60]
 *   @0x2dae94 vcmpe.f32 s17, s16
 *   @0x2dae98 vmrs APSR_nzcv, fpscr
 *   @0x2dae9c ble 0x2daf34 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x264>
 *   @0x2daea0 ldr r3, [r4]
 *   @0x2daea4 mov r0, r4
 *   @0x2daea8 vstr s16, [sp, #68]
 *   @0x2daeac mov r1, r8
 *   @0x2daeb0 vstr s19, [sp, #72]
 *   @0x2daeb4 mov r2, r6
 *   @0x2daeb8 ldr r3, [r3, #0x10]
 *   @0x2daebc blx r3
 *   @0x2daec0 cmp r0, #0
 *   @0x2daec4 beq 0x2dae8c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1bc>
 *   @0x2daec8 vldr s13, [sp, #72]
 *   @0x2daecc vmul.f32 s12, s13, s20
 *   @0x2daed0 vldr s10, [sp, #68]
 *   @0x2daed4 vldr s8, [r7, #8]
 *   @0x2daed8 vldr s9, [r7, #12]
 *   @0x2daedc vldr s11, [r7, #28]
 *   @0x2daee0 vldr s14, [r7, #24]
 *   @0x2daee4 vldr s15, [r7, #20]
 *   @0x2daee8 vmul.f32 s13, s13, s21
 *   @0x2daeec vnmls.f32 s12, s10, s21
 *   @0x2daef0 vmla.f32 s13, s10, s20
 *   @0x2daef4 vadd.f32 s12, s12, s23
 *   @0x2daef8 vadd.f32 s13, s13, s22
 *   @0x2daefc vstr s12, [sp, #68]
 *   @0x2daf00 vstr s13, [sp, #72]
 *   @0x2daf04 vsub.f32 s12, s12, s8
 *   @0x2daf08 ldm r6, {r0, r1}
 *   @0x2daf0c stm r5, {r0, r1}
 *   @0x2daf10 mov r0, r9
 *   @0x2daf14 mov r1, r10
 *   @0x2daf18 vsub.f32 s13, s13, s9
 *   @0x2daf1c vmla.f32 s14, s11, s12
 *   @0x2daf20 vmls.f32 s15, s11, s13
 *   @0x2daf24 vstr s14, [sp, #100]
 *   @0x2daf28 vstr s15, [sp, #96]
 *   @0x2daf2c bl 0x2da108 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef>
 *   @0x2daf30 b 0x2dae8c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x1bc>
 *   @0x2daf34 vldr s24, [sp, #64]
 *   @0x2daf38 vadd.f32 s19, s19, s18
 *   @0x2daf3c vcmpe.f32 s24, s19
 *   @0x2daf40 vmrs APSR_nzcv, fpscr
 *   @0x2daf44 bgt 0x2dae64 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x194>
 *   @0x2daf48 ldr r10, [r9, #0x24]
 *   @0x2daf4c ldr r0, [r9, #0xd4]
 *   @0x2daf50 mov r1, #84
 *   @0x2daf54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2daf58 subs r11, r0, #0
 *   @0x2daf5c beq 0x2daf64 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x294>
 *   @0x2daf60 bl 0x2d4560 <_ZN15b2ParticleGroupC2Ev>
 *   @0x2daf64 ldr lr, [r7, #0x24]
 *   @0x2daf68 mov r1, #0
 *   @0x2daf6c ldr r4, [sp, #0xc]
 *   @0x2daf70 ldr r3, [r9, #0xa8]
 *   @0x2daf74 ldr r12, [r7, #0x4]
 *   @0x2daf78 ldr r0, [r7, #0x30]
 *   @0x2daf7c cmp r3, r1
 *   @0x2daf80 ldrb r2, [r11, #0x4c]
 *   @0x2daf84 str lr, [r11, #0x10]
 *   @0x2daf88 ldrb lr, [r7, #0x2c]
 *   @0x2daf8c vstr s23, [r11, #60]
 *   @0x2daf90 str r4, [r11, #0x4]
 *   @0x2daf94 vstr s22, [r11, #64]
 *   @0x2daf98 ldr r4, [sp, #0xc]
 *   @0x2daf9c vstr s20, [r11, #68]
 *   @0x2dafa0 str r3, [r11, #0x18]
 *   @0x2dafa4 vstr s21, [r11, #72]
 *   @0x2dafa8 str r9, [r11]
 *   @0x2dafac bfi r2, lr, #0, #1
 *   @0x2dafb0 str r10, [r11, #0x8]
 *   @0x2dafb4 str r12, [r11, #0xc]
 *   @0x2dafb8 strb r2, [r11, #0x4c]
 *   @0x2dafbc str r0, [r11, #0x50]
 *   @0x2dafc0 str r1, [r11, #0x14]
 *   @0x2dafc4 strne r11, [r3, #0x14]
 *   @0x2dafc8 cmp r4, r10
 *   @0x2dafcc ldr r3, [r9, #0xa4]
 *   @0x2dafd0 str r11, [r9, #0xa8]
 *   @0x2dafd4 add r3, r3, #1
 *   @0x2dafd8 str r3, [r9, #0xa4]
 *   @0x2dafdc bge 0x2db004 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x334>
 *   @0x2dafe0 ldr r4, [sp, #0xc]
 *   @0x2dafe4 lsl r2, r4, #2
 *   @0x2dafe8 mov r3, r4
 *   @0x2dafec add r3, r3, #1
 *   @0x2daff0 ldr r1, [r9, #0x5c]
 *   @0x2daff4 cmp r3, r10
 *   @0x2daff8 str r11, [r1, r2]
 *   @0x2daffc add r2, r2, #4
 *   @0x2db000 bne 0x2dafec <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x31c>
 *   @0x2db004 mov r0, r9
 *   @0x2db008 mov r1, #1
 *   @0x2db00c bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb>
 *   @0x2db010 ldr r3, [r7]
 *   @0x2db014 tst r3, #8
 *   @0x2db018 beq 0x2db1a8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4d8>
 *   @0x2db01c ldr r0, [r9, #0x74]
 *   @0x2db020 cmp r0, #0
 *   @0x2db024 ble 0x2db1a8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4d8>
 *   @0x2db028 mov r12, #0
 *   @0x2db02c str r11, [sp, #0x1c]
 *   @0x2db030 mov r6, r12
 *   @0x2db034 mov r5, r12
 *   @0x2db038 ldr r11, [sp, #0xc]
 *   @0x2db03c mov r12, r7
 *   @0x2db040 str r10, [sp, #0x10]
 *   @0x2db044 b 0x2db0cc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3fc>
 *   @0x2db048 andeq r0, r0, r0
 *   @0x2db04c ldrheq r6, [r1], -r0
 *   @0x2db050 ldr r3, [r9, #0x94]
 *   @0x2db054 ldr r0, [r9, #0x38]
 *   @0x2db058 add r7, r2, r2, lsl #2
 *   @0x2db05c ldr r10, [r10, #0x8]
 *   @0x2db060 add r1, r0, r4, lsl #3
 *   @0x2db064 add r0, r0, r8, lsl #3
 *   @0x2db068 vldr s14, [r1, #4]
 *   @0x2db06c vldr s15, [r0, #4]
 *   @0x2db070 vsub.f32 s14, s14, s15
 *   @0x2db074 vldr s13, [r1]
 *   @0x2db078 vldr s15, [r0]
 *   @0x2db07c str r4, [r3, r7, lsl #2]
 *   @0x2db080 add r7, r3, r7, lsl #2
 *   @0x2db084 ldr r3, [r12, #0x24]
 *   @0x2db088 stmib r7, {r8, r10}
 *   @0x2db08c str r3, [r7, #0xc]
 *   @0x2db090 vmul.f32 s14, s14, s14
 *   @0x2db094 vsub.f32 s15, s13, s15
 *   @0x2db098 vmla.f32 s14, s15, s15
 *   @0x2db09c vsqrt.f32 s15, s14
 *   @0x2db0a0 vcmp.f32 s15, s15
 *   @0x2db0a4 vmrs APSR_nzcv, fpscr
 *   @0x2db0a8 bne 0x2db344 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x674>
 *   @0x2db0ac ldr r0, [r9, #0x74]
 *   @0x2db0b0 add r2, r2, #1
 *   @0x2db0b4 vstr s15, [r7, #16]
 *   @0x2db0b8 str r2, [r9, #0x8c]
 *   @0x2db0bc add r6, r6, #1
 *   @0x2db0c0 add r5, r5, #24
 *   @0x2db0c4 cmp r0, r6
 *   @0x2db0c8 ble 0x2db198 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4c8>
 *   @0x2db0cc ldr r3, [r9, #0x7c]
 *   @0x2db0d0 add r10, r3, r5
 *   @0x2db0d4 ldr r8, [r3, r5]
 *   @0x2db0d8 ldr r4, [r10, #0x4]
 *   @0x2db0dc cmp r8, r4
 *   @0x2db0e0 movle r3, r4
 *   @0x2db0e4 movle r4, r8
 *   @0x2db0e8 movle r8, r3
 *   @0x2db0ec cmp r11, r4
 *   @0x2db0f0 bgt 0x2db0bc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3ec>
 *   @0x2db0f4 ldr r3, [sp, #0x10]
 *   @0x2db0f8 cmp r8, r3
 *   @0x2db0fc bge 0x2db0bc <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3ec>
 *   @0x2db100 ldr r2, [r9, #0x8c]
 *   @0x2db104 ldr r3, [r9, #0x90]
 *   @0x2db108 cmp r2, r3
 *   @0x2db10c blt 0x2db050 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x380>
 *   @0x2db110 cmp r2, #0
 *   @0x2db114 ldr r0, [r9, #0xd4]
 *   @0x2db118 lslne r1, r2, #1
 *   @0x2db11c strne r1, [sp, #0x18]
 *   @0x2db120 addne r2, r1, r2, lsl #3
 *   @0x2db124 moveq r2, #256
 *   @0x2db128 streq r2, [sp, #0x18]
 *   @0x2db12c moveq r1, #5120
 *   @0x2db130 lslne r1, r2, #2
 *   @0x2db134 ldr r2, [r9, #0x94]
 *   @0x2db138 str r12, [sp, #0x4]
 *   @0x2db13c str r3, [sp, #0x8]
 *   @0x2db140 str r2, [sp, #0x14]
 *   @0x2db144 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2db148 ldr r3, [sp, #0x8]
 *   @0x2db14c ldr r1, [sp, #0x14]
 *   @0x2db150 add r3, r3, r3, lsl #2
 *   @0x2db154 lsl r3, r3, #2
 *   @0x2db158 str r3, [sp, #0x8]
 *   @0x2db15c mov r2, r3
 *   @0x2db160 mov r7, r0
 *   @0x2db164 bl 0xb65bc <memcpy@plt>
 *   @0x2db168 ldr r3, [sp, #0x8]
 *   @0x2db16c ldr r1, [sp, #0x14]
 *   @0x2db170 ldr r0, [r9, #0xd4]
 *   @0x2db174 mov r2, r3
 *   @0x2db178 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2db17c ldr r1, [sp, #0x18]
 *   @0x2db180 ldr r2, [r9, #0x8c]
 *   @0x2db184 mov r3, r7
 *   @0x2db188 str r7, [r9, #0x94]
 *   @0x2db18c str r1, [r9, #0x90]
 *   @0x2db190 ldr r12, [sp, #0x4]
 *   @0x2db194 b 0x2db054 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x384>
 *   @0x2db198 ldr r11, [sp, #0x1c]
 *   @0x2db19c mov r7, r12
 *   @0x2db1a0 ldr r10, [sp, #0x10]
 *   @0x2db1a4 ldr r3, [r12]
 *   @0x2db1a8 tst r3, #16
 *   @0x2db1ac bne 0x2db1e8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x518>
 *   @0x2db1b0 ldr r3, [r7, #0x4]
 *   @0x2db1b4 tst r3, #1
 *   @0x2db1b8 beq 0x2db1c8 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4f8>
 *   @0x2db1bc mov r0, r9
 *   @0x2db1c0 mov r1, r11
 *   @0x2db1c4 bl 0x2d5920 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup>
 *   @0x2db1c8 mov r0, r11
 *   @0x2db1cc add sp, sp, #116
 *   @0x2db1d0 vpop {d8, d9, d10, d11, d12}
 *   @0x2db1d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2db1d8 ldr r10, [sp, #0xc]
 *   @0x2db1dc vmov.f32 s22, s20
 *   @0x2db1e0 vmov.f32 s23, s20
 *   @0x2db1e4 b 0x2daf4c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x27c>
 *   @0x2db1e8 add r4, sp, #84
 *   @0x2db1ec ldr r1, [r9, #0xd4]
 *   @0x2db1f0 str r4, [sp, #0x10]
 *   @0x2db1f4 add r0, sp, #84
 *   @0x2db1f8 ldr r4, [sp, #0xc]
 *   @0x2db1fc add r1, r1, #68
 *   @0x2db200 rsb r2, r4, r10
 *   @0x2db204 bl 0x2dbb2c <_ZN16b2VoronoiDiagramC2EP16b2StackAllocatori>
 *   @0x2db208 cmp r4, r10
 *   @0x2db20c bge 0x2db240 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x570>
 *   @0x2db210 ldr r4, [sp, #0xc]
 *   @0x2db214 add r6, sp, #84
 *   @0x2db218 lsl r5, r4, #3
 *   @0x2db21c ldr r1, [r9, #0x38]
 *   @0x2db220 mov r2, r4
 *   @0x2db224 mov r0, r6
 *   @0x2db228 add r4, r4, #1
 *   @0x2db22c add r1, r1, r5
 *   @0x2db230 add r5, r5, #8
 *   @0x2db234 bl 0x2dbb94 <_ZN16b2VoronoiDiagram12AddGeneratorERK6b2Vec2i>
 *   @0x2db238 cmp r4, r10
 *   @0x2db23c bne 0x2db21c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x54c>
 *   @0x2db240 vmov.f32 s15, #5.000000e-01
 *   @0x2db244 add r0, sp, #84
 *   @0x2db248 vmul.f32 s15, s18, s15
 *   @0x2db24c vmov r1, s15
 *   @0x2db250 bl 0x2dbbc4 <_ZN16b2VoronoiDiagram8GenerateEf>
 *   @0x2db254 ldr r3, [sp, #0x64]
 *   @0x2db258 ldr r4, [sp, #0xc]
 *   @0x2db25c cmp r3, #1
 *   @0x2db260 str r9, [sp, #0x44]
 *   @0x2db264 str r7, [sp, #0x48]
 *   @0x2db268 str r4, [sp, #0x4c]
 *   @0x2db26c ble 0x2db338 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x668>
 *   @0x2db270 ldr r1, [sp, #0x60]
 *   @0x2db274 add r8, sp, #68
 *   @0x2db278 mov r10, #0
 *   @0x2db27c str r7, [sp, #0xc]
 *   @0x2db280 cmp r1, #1
 *   @0x2db284 ble 0x2db324 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x654>
 *   @0x2db288 mov r6, #0
 *   @0x2db28c b 0x2db2b0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5e0>
 *   @0x2db290 cmp r4, r7
 *   @0x2db294 cmpne r5, r7
 *   @0x2db298 bne 0x2db308 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x638>
 *   @0x2db29c ldr r1, [sp, #0x60]
 *   @0x2db2a0 add r6, r6, #1
 *   @0x2db2a4 sub r3, r1, #1
 *   @0x2db2a8 cmp r6, r3
 *   @0x2db2ac bge 0x2db320 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x650>
 *   @0x2db2b0 mla r2, r1, r10, r6
 *   @0x2db2b4 ldr r3, [sp, #0x68]
 *   @0x2db2b8 add r0, r1, r2
 *   @0x2db2bc add r12, r0, #1
 *   @0x2db2c0 add lr, r3, r2, lsl #2
 *   @0x2db2c4 ldr r4, [r3, r0, lsl #2]
 *   @0x2db2c8 ldr r2, [r3, r2, lsl #2]
 *   @0x2db2cc ldr r5, [lr, #0x4]
 *   @0x2db2d0 ldr r7, [r3, r12, lsl #2]
 *   @0x2db2d4 cmp r5, r4
 *   @0x2db2d8 beq 0x2db2a0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5d0>
 *   @0x2db2dc cmp r2, r4
 *   @0x2db2e0 cmpne r2, r5
 *   @0x2db2e4 beq 0x2db290 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5c0>
 *   @0x2db2e8 ldr r1, [r2, #0x8]
 *   @0x2db2ec mov r0, r8
 *   @0x2db2f0 ldr r2, [r5, #0x8]
 *   @0x2db2f4 ldr r3, [r4, #0x8]
 *   @0x2db2f8 bl 0x2d5308 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii>
 *   @0x2db2fc cmp r4, r7
 *   @0x2db300 cmpne r5, r7
 *   @0x2db304 beq 0x2db29c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5cc>
 *   @0x2db308 ldr r1, [r5, #0x8]
 *   @0x2db30c mov r0, r8
 *   @0x2db310 ldr r2, [r7, #0x8]
 *   @0x2db314 ldr r3, [r4, #0x8]
 *   @0x2db318 bl 0x2d5308 <_ZNK16b2ParticleSystem27CreateParticleGroupCallbackclEiii>
 *   @0x2db31c b 0x2db29c <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5cc>
 *   @0x2db320 ldr r3, [sp, #0x64]
 *   @0x2db324 add r10, r10, #1
 *   @0x2db328 sub r2, r3, #1
 *   @0x2db32c cmp r10, r2
 *   @0x2db330 blt 0x2db280 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x5b0>
 *   @0x2db334 ldr r7, [sp, #0xc]
 *   @0x2db338 add r0, sp, #84
 *   @0x2db33c bl 0x2dbb68 <_ZN16b2VoronoiDiagramD2Ev>
 *   @0x2db340 b 0x2db1b0 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x4e0>
 *   @0x2db344 vmov r0, s14
 *   @0x2db348 str r12, [sp, #0x4]
 *   @0x2db34c bl 0xb6700 <sqrtf@plt>
 *   @0x2db350 ldr r2, [r9, #0x8c]
 *   @0x2db354 ldr r12, [sp, #0x4]
 *   @0x2db358 vmov s15, r0
 *   @0x2db35c b 0x2db0ac <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x3dc>
 *   @0x2db360 add r1, sp, #52
 *   @0x2db364 ldr r12, [r12, #0x1c]
 *   @0x2db368 blx r12
 *   @0x2db36c b 0x2dae20 <_ZN16b2ParticleSystem19CreateParticleGroupERK18b2ParticleGroupDef+0x150>
 *
 * ══ §6/20 yyServer::ProcessTCP()  0x297750  size 1692  423 条（0x297750..0x297dec）
 * @func 0x297750 0x297dec  size 1692  423 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2978b4→0x3eb70c, 0x297a98→0x3eb70c, 0x297b7c→0x3eb70c, 0x297ca8→0x3eb788, 0x297cd8→0x75790c, 0x297d20→0x3eb70c
 * 调用序列: yySocket::Close()×3 / yySocket::~yySocket()×3 / operator delete(void*)×3 / yySocket::ResolveIP()×3 / yySocket::Write(void*, unsigned int)×3 / 0xb65bc×2 / operator new(unsigned int)×2 / ThrowConnectingSocketNetworkEvent(int, int, int, int, char*, bool)×2
 * 字段偏移 top8: 0x28×14 / 0x8×11 / 0xc×11 / 0x10×10 / 0x14×9 / 0x4×8 / 0x2c×8 / 0x18×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297750 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x297754 sub sp, sp, #148
 *   @0x297758 ldr r12, [pc, #0x650]
 *   @0x29775c mov r2, #128
 *   @0x297760 ldr r3, [pc, #0x64c]
 *   @0x297764 mov r5, r0
 *   @0x297768 add r12, pc, r12
 *   @0x29776c str r12, [sp, #0x14]
 *   @0x297770 ldr r12, [r0, #0x4]
 *   @0x297774 ldr r10, [r0, #0x8]
 *   @0x297778 ldr r9, [r0]
 *   @0x29777c str r12, [sp, #0x10]
 *   @0x297780 add r4, r10, #8
 *   @0x297784 ldr r12, [sp, #0x14]
 *   @0x297788 mov r0, r4
 *   @0x29778c ldr r3, [r12, r3]
 *   @0x297790 ldr r12, [sp, #0x10]
 *   @0x297794 str r3, [sp, #0x2c]
 *   @0x297798 add r1, r12, #8
 *   @0x29779c ldr r3, [r3]
 *   @0x2977a0 str r3, [sp, #0x8c]
 *   @0x2977a4 bl 0xb65bc <memcpy@plt>
 *   @0x2977a8 ldr r12, [sp, #0x10]
 *   @0x2977ac mov r2, #4096
 *   @0x2977b0 add r0, r10, #136
 *   @0x2977b4 add r1, r12, #136
 *   @0x2977b8 bl 0xb65bc <memcpy@plt>
 *   @0x2977bc mov r12, #0
 *   @0x2977c0 add lr, sp, #68
 *   @0x2977c4 mov r2, r12
 *   @0x2977c8 mov r1, r4
 *   @0x2977cc mov r3, r12
 *   @0x2977d0 mov r0, #1024
 *   @0x2977d4 str lr, [sp]
 *   @0x2977d8 str r12, [sp, #0x44]
 *   @0x2977dc str r12, [sp, #0x48]
 *   @0x2977e0 bl 0xb6d84 <select@plt>
 *   @0x2977e4 cmp r0, #0
 *   @0x2977e8 beq 0x2979a4 <_ZN8yyServer10ProcessTCPEv+0x254>
 *   @0x2977ec cmn r0, #1
 *   @0x2977f0 beq 0x297d0c <_ZN8yyServer10ProcessTCPEv+0x5bc>
 *   @0x2977f4 ldr r12, [sp, #0x10]
 *   @0x2977f8 add r12, r12, #132
 *   @0x2977fc str r12, [sp, #0x18]
 *   @0x297800 ldr r12, [sp, #0x10]
 *   @0x297804 ldr r11, [sp, #0x18]
 *   @0x297808 add r6, r12, #4224
 *   @0x29780c ldr r12, [pc, #0x5a4]
 *   @0x297810 add r6, r6, #4
 *   @0x297814 add r12, pc, r12
 *   @0x297818 str r12, [sp, #0x24]
 *   @0x29781c ldr r12, [pc, #0x598]
 *   @0x297820 add r12, pc, r12
 *   @0x297824 str r12, [sp, #0x30]
 *   @0x297828 ldr r12, [pc, #0x590]
 *   @0x29782c add r12, pc, r12
 *   @0x297830 str r12, [sp, #0x34]
 *   @0x297834 ldr r12, [pc, #0x588]
 *   @0x297838 add r12, pc, r12
 *   @0x29783c str r12, [sp, #0x3c]
 *   @0x297840 ldr r12, [pc, #0x580]
 *   @0x297844 add r12, pc, r12
 *   @0x297848 str r12, [sp, #0x28]
 *   @0x29784c ldr r12, [pc, #0x578]
 *   @0x297850 add r12, pc, r12
 *   @0x297854 str r12, [sp, #0x38]
 *   @0x297858 b 0x297864 <_ZN8yyServer10ProcessTCPEv+0x114>
 *   @0x29785c cmp r11, r6
 *   @0x297860 beq 0x2979a4 <_ZN8yyServer10ProcessTCPEv+0x254>
 *   @0x297864 ldr r4, [r11, #0x4]!
 *   @0x297868 cmp r4, #0
 *   @0x29786c beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297870 ldr r3, [r4]
 *   @0x297874 mov r8, #1
 *   @0x297878 and r2, r3, #31
 *   @0x29787c asr r3, r3, #5
 *   @0x297880 add r3, r3, #2
 *   @0x297884 ldr r3, [r10, r3, lsl #2]
 *   @0x297888 ands r3, r3, r8, lsl r2
 *   @0x29788c beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297890 cmp r9, r4
 *   @0x297894 beq 0x2979c0 <_ZN8yyServer10ProcessTCPEv+0x270>
 *   @0x297898 mov r0, r4
 *   @0x29789c mov r1, r5
 *   @0x2978a0 bl 0x296e1c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer>
 *   @0x2978a4 subs r7, r0, #0
 *   @0x2978a8 bne 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x2978ac ldr r12, [r4, #0x28]
 *   @0x2978b0 add r8, r4, #108
 *   @0x2978b4 ldr r0, [pc, #0x514]
 *   @0x2978b8 mov r3, r8
 *   @0x2978bc ldr r1, [sp, #0x24]
 *   @0x2978c0 str r12, [sp, #0x1c]
 *   @0x2978c4 ldr r12, [sp, #0x14]
 *   @0x2978c8 ldr r2, [r4, #0x68]
 *   @0x2978cc ldr r0, [r12, r0]
 *   @0x2978d0 add r12, sp, #76
 *   @0x2978d4 str r12, [sp, #0xc]
 *   @0x2978d8 ldr r0, [r0]
 *   @0x2978dc ldr r12, [r0]
 *   @0x2978e0 ldr r12, [r12, #0xc]
 *   @0x2978e4 blx r12
 *   @0x2978e8 ldr r3, [r4, #0xb0]
 *   @0x2978ec mov r1, r8
 *   @0x2978f0 add r0, sp, #76
 *   @0x2978f4 mov r2, #64
 *   @0x2978f8 ldr r8, [r4, #0xac]
 *   @0x2978fc str r3, [sp, #0x20]
 *   @0x297900 bl 0xb6568 <strncpy@plt>
 *   @0x297904 ldrb r3, [r4, #0x2c]
 *   @0x297908 cmp r3, #0
 *   @0x29790c bne 0x297b58 <_ZN8yyServer10ProcessTCPEv+0x408>
 *   @0x297910 ldr r1, [r5, #0x28]
 *   @0x297914 mov r3, #0
 *   @0x297918 ldr r2, [sp, #0x18]
 *   @0x29791c sub r1, r1, #1
 *   @0x297920 str r1, [r5, #0x28]
 *   @0x297924 b 0x297934 <_ZN8yyServer10ProcessTCPEv+0x1e4>
 *   @0x297928 add r3, r3, #1
 *   @0x29792c cmp r3, #1024
 *   @0x297930 beq 0x297970 <_ZN8yyServer10ProcessTCPEv+0x220>
 *   @0x297934 ldr r1, [r2, #0x4]!
 *   @0x297938 cmp r4, r1
 *   @0x29793c bne 0x297928 <_ZN8yyServer10ProcessTCPEv+0x1d8>
 *   @0x297940 ldr r12, [sp, #0x10]
 *   @0x297944 add r3, r3, #34
 *   @0x297948 mov r2, #0
 *   @0x29794c mov r0, #1
 *   @0x297950 str r2, [r12, r3, lsl #2]
 *   @0x297954 ldr r3, [r4]
 *   @0x297958 and r2, r3, #31
 *   @0x29795c asr r3, r3, #5
 *   @0x297960 add r3, r12, r3, lsl #2
 *   @0x297964 ldr r1, [r3, #0x8]
 *   @0x297968 bic r2, r1, r0, lsl r2
 *   @0x29796c str r2, [r3, #0x8]
 *   @0x297970 mov r0, r4
 *   @0x297974 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x297978 ldrb r7, [r4, #0x2c]
 *   @0x29797c mov r3, #3
 *   @0x297980 str r3, [r4, #0x28]
 *   @0x297984 cmp r7, #0
 *   @0x297988 beq 0x297b20 <_ZN8yyServer10ProcessTCPEv+0x3d0>
 *   @0x29798c mov r0, r4
 *   @0x297990 bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x297994 mov r0, r4
 *   @0x297998 bl 0x27d1d0 <_ZdlPv>
 *   @0x29799c cmp r11, r6
 *   @0x2979a0 bne 0x297864 <_ZN8yyServer10ProcessTCPEv+0x114>
 *   @0x2979a4 ldr r12, [sp, #0x2c]
 *   @0x2979a8 ldr r2, [sp, #0x8c]
 *   @0x2979ac ldr r3, [r12]
 *   @0x2979b0 cmp r2, r3
 *   @0x2979b4 bne 0x297dac <_ZN8yyServer10ProcessTCPEv+0x65c>
 *   @0x2979b8 add sp, sp, #148
 *   @0x2979bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2979c0 mov r0, r9
 *   @0x2979c4 bl 0x29528c <_ZN8yySocket6AcceptEv>
 *   @0x2979c8 mov r7, r0
 *   @0x2979cc mov r0, #200
 *   @0x2979d0 bl 0x27c524 <_Znwj>
 *   @0x2979d4 ldr r2, [r5, #0x20]
 *   @0x2979d8 mov r3, r8
 *   @0x2979dc mov r1, r7
 *   @0x2979e0 mov r4, r0
 *   @0x2979e4 bl 0x2970c0 <_ZN8yySocketC2Ei11eSocketTypeb>
 *   @0x2979e8 mov r0, r4
 *   @0x2979ec bl 0x294ec8 <_ZN8yySocket4InitEv>
 *   @0x2979f0 ldr r3, [r5, #0x28]
 *   @0x2979f4 ldr r2, [r5, #0x24]
 *   @0x2979f8 cmp r3, r2
 *   @0x2979fc bge 0x297b70 <_ZN8yyServer10ProcessTCPEv+0x420>
 *   @0x297a00 ldrb r12, [r9, #0x2c]
 *   @0x297a04 cmp r12, #0
 *   @0x297a08 beq 0x297cc4 <_ZN8yyServer10ProcessTCPEv+0x574>
 *   @0x297a0c mvn r7, #0
 *   @0x297a10 strb r8, [r4, #0x2c]
 *   @0x297a14 add r3, r3, #1
 *   @0x297a18 str r3, [r5, #0x28]
 *   @0x297a1c ldr r12, [sp, #0x10]
 *   @0x297a20 ldr r3, [r12, #0x4]
 *   @0x297a24 cmp r3, #1024
 *   @0x297a28 bge 0x297a80 <_ZN8yyServer10ProcessTCPEv+0x330>
 *   @0x297a2c ldr r2, [sp, #0x18]
 *   @0x297a30 mov r3, #0
 *   @0x297a34 b 0x297a44 <_ZN8yyServer10ProcessTCPEv+0x2f4>
 *   @0x297a38 add r3, r3, #1
 *   @0x297a3c cmp r3, #1024
 *   @0x297a40 beq 0x297a5c <_ZN8yyServer10ProcessTCPEv+0x30c>
 *   @0x297a44 ldr r1, [r2, #0x4]!
 *   @0x297a48 cmp r1, #0
 *   @0x297a4c bne 0x297a38 <_ZN8yyServer10ProcessTCPEv+0x2e8>
 *   @0x297a50 ldr r12, [sp, #0x10]
 *   @0x297a54 add r3, r3, #34
 *   @0x297a58 str r4, [r12, r3, lsl #2]
 *   @0x297a5c ldr r3, [r4]
 *   @0x297a60 mov r0, #1
 *   @0x297a64 ldr r12, [sp, #0x10]
 *   @0x297a68 and r2, r3, #31
 *   @0x297a6c asr r3, r3, #5
 *   @0x297a70 add r3, r12, r3, lsl #2
 *   @0x297a74 ldr r1, [r3, #0x8]
 *   @0x297a78 orr r2, r1, r0, lsl r2
 *   @0x297a7c str r2, [r3, #0x8]
 *   @0x297a80 mov r0, r4
 *   @0x297a84 add r12, r4, #108
 *   @0x297a88 str r12, [sp, #0xc]
 *   @0x297a8c bl 0x296f64 <_ZN8yySocket9ResolveIPEv>
 *   @0x297a90 ldr r12, [sp, #0x14]
 *   @0x297a94 mov r2, r7
 *   @0x297a98 ldr r0, [pc, #0x330]
 *   @0x297a9c ldr r3, [sp, #0xc]
 *   @0x297aa0 ldr r1, [sp, #0x28]
 *   @0x297aa4 ldr r0, [r12, r0]
 *   @0x297aa8 ldr r8, [r0]
 *   @0x297aac ldr r12, [r8]
 *   @0x297ab0 mov r0, r8
 *   @0x297ab4 ldr r12, [r12, #0xc]
 *   @0x297ab8 blx r12
 *   @0x297abc ldrb r3, [r5, #0x1d]
 *   @0x297ac0 ldr r2, [r9, #0xac]
 *   @0x297ac4 cmp r3, #0
 *   @0x297ac8 str r2, [r4, #0xac]
 *   @0x297acc beq 0x297bf0 <_ZN8yyServer10ProcessTCPEv+0x4a0>
 *   @0x297ad0 ldrb r3, [r4, #0x2c]
 *   @0x297ad4 cmp r3, #0
 *   @0x297ad8 bne 0x297c8c <_ZN8yyServer10ProcessTCPEv+0x53c>
 *   @0x297adc ldrb r3, [r5, #0x1d]
 *   @0x297ae0 cmn r7, #1
 *   @0x297ae4 strne r7, [r4, #0x68]
 *   @0x297ae8 cmp r3, #0
 *   @0x297aec beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297af0 ldr lr, [sp, #0xc]
 *   @0x297af4 mov r3, #2
 *   @0x297af8 ldr r1, [r4, #0x68]
 *   @0x297afc mov r12, #1
 *   @0x297b00 str r3, [r4, #0x28]
 *   @0x297b04 ldr r2, [r4, #0xac]
 *   @0x297b08 ldr r0, [r5, #0x18]
 *   @0x297b0c ldr r3, [r4, #0xb0]
 *   @0x297b10 str lr, [sp]
 *   @0x297b14 str r12, [sp, #0x4]
 *   @0x297b18 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb>
 *   @0x297b1c b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297b20 mov r0, r4
 *   @0x297b24 bl 0x29955c <_Z10FreeSocketP8yySocket>
 *   @0x297b28 ldr r12, [sp, #0x1c]
 *   @0x297b2c cmp r12, #1
 *   @0x297b30 mov r1, r0
 *   @0x297b34 bls 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297b38 ldr r0, [r5, #0x18]
 *   @0x297b3c add lr, sp, #76
 *   @0x297b40 mov r2, r8
 *   @0x297b44 str lr, [sp]
 *   @0x297b48 str r7, [sp, #0x4]
 *   @0x297b4c ldr r3, [sp, #0x20]
 *   @0x297b50 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb>
 *   @0x297b54 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297b58 bl 0x29cacc <_Z26Debug_DeleteALLBreakPointsv>
 *   @0x297b5c mov r0, r7
 *   @0x297b60 bl 0x29c648 <_Z21Debug_StartStopTargetb>
 *   @0x297b64 mov r0, r7
 *   @0x297b68 bl 0x29cad0 <_Z20DebuggerSetConnectedb>
 *   @0x297b6c b 0x297910 <_ZN8yyServer10ProcessTCPEv+0x1c0>
 *   @0x297b70 mov r0, r4
 *   @0x297b74 bl 0x296f64 <_ZN8yySocket9ResolveIPEv>
 *   @0x297b78 ldr r12, [sp, #0x14]
 *   @0x297b7c ldr r3, [pc, #0x24c]
 *   @0x297b80 add r2, r4, #108
 *   @0x297b84 ldr r1, [sp, #0x30]
 *   @0x297b88 ldr r3, [r12, r3]
 *   @0x297b8c ldr r7, [r3]
 *   @0x297b90 ldr r3, [r7]
 *   @0x297b94 mov r0, r7
 *   @0x297b98 ldr r3, [r3, #0xc]
 *   @0x297b9c blx r3
 *   @0x297ba0 mov r0, r4
 *   @0x297ba4 ldr r1, [sp, #0x34]
 *   @0x297ba8 mov r2, #6
 *   @0x297bac bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x297bb0 cmp r0, #6
 *   @0x297bb4 beq 0x297bcc <_ZN8yyServer10ProcessTCPEv+0x47c>
 *   @0x297bb8 ldr r3, [r7]
 *   @0x297bbc mov r0, r7
 *   @0x297bc0 ldr r1, [sp, #0x3c]
 *   @0x297bc4 ldr r3, [r3, #0xc]
 *   @0x297bc8 blx r3
 *   @0x297bcc mov r0, r4
 *   @0x297bd0 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x297bd4 cmp r4, #0
 *   @0x297bd8 beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297bdc mov r0, r4
 *   @0x297be0 bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x297be4 mov r0, r4
 *   @0x297be8 bl 0x27d1d0 <_ZdlPv>
 *   @0x297bec b 0x29799c <_ZN8yyServer10ProcessTCPEv+0x24c>
 *   @0x297bf0 mov r2, #1
 *   @0x297bf4 mov r0, r4
 *   @0x297bf8 str r2, [r4, #0x28]
 *   @0x297bfc mov r2, #18
 *   @0x297c00 ldr r1, [sp, #0x38]
 *   @0x297c04 str r3, [sp, #0x8]
 *   @0x297c08 bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x297c0c ldr r3, [sp, #0x8]
 *   @0x297c10 cmp r0, #18
 *   @0x297c14 beq 0x297ad0 <_ZN8yyServer10ProcessTCPEv+0x380>
 *   @0x297c18 ldr r2, [sp, #0x18]
 *   @0x297c1c b 0x297c2c <_ZN8yyServer10ProcessTCPEv+0x4dc>
 *   @0x297c20 add r3, r3, #1
 *   @0x297c24 cmp r3, #1024
 *   @0x297c28 beq 0x297c68 <_ZN8yyServer10ProcessTCPEv+0x518>
 *   @0x297c2c ldr r1, [r2, #0x4]!
 *   @0x297c30 cmp r4, r1
 *   @0x297c34 bne 0x297c20 <_ZN8yyServer10ProcessTCPEv+0x4d0>
 *   @0x297c38 ldr r12, [sp, #0x10]
 *   @0x297c3c add r3, r3, #34
 *   @0x297c40 mov r2, #0
 *   @0x297c44 mov r0, #1
 *   @0x297c48 str r2, [r12, r3, lsl #2]
 *   @0x297c4c ldr r3, [r4]
 *   @0x297c50 and r2, r3, #31
 *   @0x297c54 asr r3, r3, #5
 *   @0x297c58 add r3, r12, r3, lsl #2
 *   @0x297c5c ldr r1, [r3, #0x8]
 *   @0x297c60 bic r2, r1, r0, lsl r2
 *   @0x297c64 str r2, [r3, #0x8]
 *   @0x297c68 ldr r3, [r8]
 *   @0x297c6c mov r0, r8
 *   @0x297c70 ldr r1, [pc, #0x15c]
 *   @0x297c74 ldr r3, [r3, #0xc]
 *   @0x297c78 add r1, pc, r1
 *   @0x297c7c blx r3
 *   @0x297c80 ldrb r3, [r4, #0x2c]
 *   @0x297c84 cmp r3, #0
 *   @0x297c88 beq 0x297adc <_ZN8yyServer10ProcessTCPEv+0x38c>
 *   @0x297c8c mov r0, #64
 *   @0x297c90 bl 0x27c524 <_Znwj>
 *   @0x297c94 mov r2, #1
 *   @0x297c98 mov r3, r2
 *   @0x297c9c ldr r1, [r5, #0x14]
 *   @0x297ca0 mov r8, r0
 *   @0x297ca4 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0x297ca8 ldr r3, [pc, #0x128]
 *   @0x297cac ldr r12, [sp, #0x14]
 *   @0x297cb0 ldr r3, [r12, r3]
 *   @0x297cb4 add r3, r3, #8
 *   @0x297cb8 str r3, [r8]
 *   @0x297cbc str r8, [r4, #0x4c]
 *   @0x297cc0 b 0x297adc <_ZN8yyServer10ProcessTCPEv+0x38c>
 *   @0x297cc4 str r12, [sp, #0x8]
 *   @0x297cc8 bl 0x298e28 <_Z11AllocSocketv>
 *   @0x297ccc ldr r12, [sp, #0x8]
 *   @0x297cd0 subs r7, r0, #0
 *   @0x297cd4 blt 0x297d14 <_ZN8yyServer10ProcessTCPEv+0x5c4>
 *   @0x297cd8 ldr r1, [pc, #0xfc]
 *   @0x297cdc add r3, r7, r7, lsl #1
 *   @0x297ce0 ldr r0, [sp, #0x14]
 *   @0x297ce4 cmp r4, #0
 *   @0x297ce8 ldr r2, [r5, #0x28]
 *   @0x297cec ldr r1, [r0, r1]
 *   @0x297cf0 add r2, r2, #1
 *   @0x297cf4 add r3, r1, r3, lsl #2
 *   @0x297cf8 strb r8, [r3, #0x1]
 *   @0x297cfc stmib r3, {r4, r12}
 *   @0x297d00 str r2, [r5, #0x28]
 *   @0x297d04 bne 0x297a1c <_ZN8yyServer10ProcessTCPEv+0x2cc>
 *   @0x297d08 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297d0c bl 0x294d24 <_ZN8yySocket9DumpErrorEv>
 *   @0x297d10 b 0x2977f4 <_ZN8yyServer10ProcessTCPEv+0xa4>
 *   @0x297d14 mov r0, r4
 *   @0x297d18 bl 0x296f64 <_ZN8yySocket9ResolveIPEv>
 *   @0x297d1c ldr r12, [sp, #0x14]
 *   @0x297d20 ldr r3, [pc, #0xa8]
 *   @0x297d24 add r2, r4, #108
 *   @0x297d28 ldr r1, [pc, #0xb0]
 *   @0x297d2c ldr r3, [r12, r3]
 *   @0x297d30 add r1, pc, r1
 *   @0x297d34 ldr r7, [r3]
 *   @0x297d38 ldr r3, [r7]
 *   @0x297d3c mov r0, r7
 *   @0x297d40 ldr r3, [r3, #0xc]
 *   @0x297d44 blx r3
 *   @0x297d48 ldr r1, [pc, #0x94]
 *   @0x297d4c mov r0, r4
 *   @0x297d50 mov r2, #6
 *   @0x297d54 add r1, pc, r1
 *   @0x297d58 bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x297d5c cmp r0, #6
 *   @0x297d60 beq 0x297d7c <_ZN8yyServer10ProcessTCPEv+0x62c>
 *   @0x297d64 ldr r3, [r7]
 *   @0x297d68 mov r0, r7
 *   @0x297d6c ldr r1, [pc, #0x74]
 *   @0x297d70 ldr r3, [r3, #0xc]
 *   @0x297d74 add r1, pc, r1
 *   @0x297d78 blx r3
 *   @0x297d7c mov r0, r4
 *   @0x297d80 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x297d84 cmp r4, #0
 *   @0x297d88 beq 0x297d9c <_ZN8yyServer10ProcessTCPEv+0x64c>
 *   @0x297d8c mov r0, r4
 *   @0x297d90 bl 0x294cbc <_ZN8yySocketD2Ev>
 *   @0x297d94 mov r0, r4
 *   @0x297d98 bl 0x27d1d0 <_ZdlPv>
 *   @0x297d9c ldr r3, [r5, #0x28]
 *   @0x297da0 add r3, r3, #1
 *   @0x297da4 str r3, [r5, #0x28]
 *   @0x297da8 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c>
 *   @0x297dac bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x297db0 andseq r10, r5, r8, ror #9
 *   @0x297db4 .word 0xffffbd00
 *   @0x297db8 andeq r1, r12, r0, lsl #28
 *   @0x297dbc strheq r1, [r12], -r0
 *   @0x297dc0 strheq r1, [r12], -r8
 *   @0x297dc4 strheq r1, [r12], -r4
 *   @0x297dc8 strheq r1, [r12], -r4
 *   @0x297dcc andeq r1, r12, r12, asr r12
 *   @0x297dd0 .word 0xffffbac4
 *   @0x297dd4 andeq r1, r12, r4, ror r9
 *   @0x297dd8 .word 0xffffbd60
 *   @0x297ddc .word 0xfffffd54
 *   @0x297de0 andeq r1, r12, r0, lsr #17
 *   @0x297de4 muleq r12, r0, r8
 *   @0x297de8 andeq r1, r12, r8, ror r8
 *
 * ══ §7/20 RunnerLoadGame()  0x1def08  size 1684  421 条（0x1def08..0x1df59c）
 * @func 0x1def08 0x1df59c  size 1684  421 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1def20→0x3eb6b8, 0x1def24→0x542984, 0x1def68→0x544c64, 0x1defa0→0x544c30, 0x1df064→0x544c2c, 0x1df0d4→0x544c28, 0x1df0dc→0x544b74, 0x1df130→0x544b78
 * 调用序列: 0xb6538×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb6868×3 / YYStrDup(char const*)×2 / SetWorkingDirectory()×2 / 0xb65a4×2 / LoadSave::BundleFileExists(char const*)×2 / LoadSave::ReadBundleFile(char const*, int*)×2
 * 字段偏移 top8: 0xc×17 / 0x4×6 / 0x8×4 / 0x5ec×2 / 0x414×2 / 0x10×2 / 0x3a8×2 / 0x5f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1def08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1def0c sub sp, sp, #1040
 *   @0x1def10 ldr r10, [pc, #0x5f4]
 *   @0x1def14 sub sp, sp, #12
 *   @0x1def18 ldr r1, [pc, #0x5f0]
 *   @0x1def1c add r10, pc, r10
 *   @0x1def20 ldr r2, [pc, #0x5ec]
 *   @0x1def24 ldr r3, [pc, #0x5ec]
 *   @0x1def28 ldr r1, [r10, r1]
 *   @0x1def2c str r1, [sp, #0x4]
 *   @0x1def30 ldr r12, [sp, #0x4]
 *   @0x1def34 ldr r1, [pc, #0x5e0]
 *   @0x1def38 ldr r0, [r12]
 *   @0x1def3c add r1, pc, r1
 *   @0x1def40 str r0, [sp, #0x414]
 *   @0x1def44 ldr r2, [r10, r2]
 *   @0x1def48 ldr r4, [r2]
 *   @0x1def4c str r2, [sp, #0x8]
 *   @0x1def50 ldr r7, [r10, r3]
 *   @0x1def54 ldr r3, [r4]
 *   @0x1def58 mov r0, r4
 *   @0x1def5c ldr r2, [r7]
 *   @0x1def60 ldr r3, [r3, #0xc]
 *   @0x1def64 blx r3
 *   @0x1def68 ldr r3, [pc, #0x5b0]
 *   @0x1def6c ldr r3, [r10, r3]
 *   @0x1def70 str r3, [sp]
 *   @0x1def74 ldr r3, [r3]
 *   @0x1def78 cmp r3, #0
 *   @0x1def7c beq 0x1df260 <_Z14RunnerLoadGamev+0x358>
 *   @0x1def80 ldr r3, [r3]
 *   @0x1def84 cmp r3, #0
 *   @0x1def88 beq 0x1df260 <_Z14RunnerLoadGamev+0x358>
 *   @0x1def8c ldr r0, [pc, #0x590]
 *   @0x1def90 mov r12, #1
 *   @0x1def94 str r12, [sp, #0xc]
 *   @0x1def98 add r0, pc, r0
 *   @0x1def9c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1defa0 ldr r3, [pc, #0x580]
 *   @0x1defa4 ldr r9, [r10, r3]
 *   @0x1defa8 mov r5, r0
 *   @0x1defac str r0, [r7]
 *   @0x1defb0 str r0, [r9]
 *   @0x1defb4 bl 0x1fd150 <_Z19SetWorkingDirectoryv>
 *   @0x1defb8 mov r0, r5
 *   @0x1defbc bl 0xb6538 <strlen@plt>
 *   @0x1defc0 ldr r1, [pc, #0x564]
 *   @0x1defc4 movw r2, #0x8e3
 *   @0x1defc8 mov r3, #1
 *   @0x1defcc add r1, pc, r1
 *   @0x1defd0 add r8, r0, #12
 *   @0x1defd4 mov r0, r8
 *   @0x1defd8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1defdc mov r1, r5
 *   @0x1defe0 mov r6, r0
 *   @0x1defe4 bl 0xb65a4 <strcpy@plt>
 *   @0x1defe8 mov r0, r6
 *   @0x1defec mov r1, #47
 *   @0x1deff0 bl 0xb6868 <strrchr@plt>
 *   @0x1deff4 subs r11, r0, #0
 *   @0x1deff8 beq 0x1df3d4 <_Z14RunnerLoadGamev+0x4cc>
 *   @0x1deffc ldr lr, [r4]
 *   @0x1df000 mov r0, r4
 *   @0x1df004 ldr r1, [pc, #0x524]
 *   @0x1df008 ldr r2, [r9]
 *   @0x1df00c add r1, pc, r1
 *   @0x1df010 ldr r9, [lr, #0xc]
 *   @0x1df014 blx r9
 *   @0x1df018 ldr lr, [pc, #0x514]
 *   @0x1df01c add lr, pc, lr
 *   @0x1df020 ldm lr!, {r0, r1, r2}
 *   @0x1df024 ldrb lr, [lr]
 *   @0x1df028 str r0, [r11]
 *   @0x1df02c mov r0, r4
 *   @0x1df030 str r1, [r11, #0x4]
 *   @0x1df034 strb lr, [r11, #0xc]
 *   @0x1df038 str r2, [r11, #0x8]
 *   @0x1df03c mov r2, r6
 *   @0x1df040 ldr r3, [r4]
 *   @0x1df044 ldr r1, [pc, #0x4ec]
 *   @0x1df048 ldr r3, [r3, #0xc]
 *   @0x1df04c add r1, pc, r1
 *   @0x1df050 blx r3
 *   @0x1df054 mov r0, r6
 *   @0x1df058 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x1df05c cmp r0, #0
 *   @0x1df060 bne 0x1df1d4 <_Z14RunnerLoadGamev+0x2cc>
 *   @0x1df064 ldr lr, [pc, #0x4d0]
 *   @0x1df068 movw r2, #0x917
 *   @0x1df06c ldr r1, [pc, #0x4cc]
 *   @0x1df070 mov r3, #1
 *   @0x1df074 mov r0, r8
 *   @0x1df078 ldr lr, [r10, lr]
 *   @0x1df07c add r1, pc, r1
 *   @0x1df080 str r6, [lr]
 *   @0x1df084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1df088 mov r1, r5
 *   @0x1df08c mov r6, r0
 *   @0x1df090 bl 0xb65a4 <strcpy@plt>
 *   @0x1df094 mov r0, r6
 *   @0x1df098 mov r1, #46
 *   @0x1df09c bl 0xb6868 <strrchr@plt>
 *   @0x1df0a0 subs r2, r0, #0
 *   @0x1df0a4 beq 0x1df0d4 <_Z14RunnerLoadGamev+0x1cc>
 *   @0x1df0a8 ldr r3, [pc, #0x494]
 *   @0x1df0ac add r3, pc, r3
 *   @0x1df0b0 ldm r3!, {r0, r1}
 *   @0x1df0b4 ldrb r3, [r3]
 *   @0x1df0b8 str r0, [r2]
 *   @0x1df0bc mov r0, r6
 *   @0x1df0c0 str r1, [r2, #0x4]
 *   @0x1df0c4 strb r3, [r2, #0x8]
 *   @0x1df0c8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1df0cc cmp r0, #0
 *   @0x1df0d0 bne 0x1df198 <_Z14RunnerLoadGamev+0x290>
 *   @0x1df0d4 ldr r2, [pc, #0x46c]
 *   @0x1df0d8 mov r3, #0
 *   @0x1df0dc ldr lr, [pc, #0x468]
 *   @0x1df0e0 mov r0, r4
 *   @0x1df0e4 ldr r1, [pc, #0x464]
 *   @0x1df0e8 ldr r8, [r10, r2]
 *   @0x1df0ec mov r2, r5
 *   @0x1df0f0 add r1, pc, r1
 *   @0x1df0f4 str r6, [r8]
 *   @0x1df0f8 ldr r6, [r10, lr]
 *   @0x1df0fc ldr lr, [r4]
 *   @0x1df100 str r3, [r6]
 *   @0x1df104 ldr r3, [lr, #0xc]
 *   @0x1df108 blx r3
 *   @0x1df10c ldr r12, [sp]
 *   @0x1df110 ldr r3, [r12]
 *   @0x1df114 cmp r3, #0
 *   @0x1df118 beq 0x1df30c <_Z14RunnerLoadGamev+0x404>
 *   @0x1df11c ldr r2, [r3]
 *   @0x1df120 cmp r2, #0
 *   @0x1df124 beq 0x1df30c <_Z14RunnerLoadGamev+0x404>
 *   @0x1df128 ldr r0, [r3, #0x4]
 *   @0x1df12c mov r3, r2
 *   @0x1df130 ldr r1, [pc, #0x41c]
 *   @0x1df134 str r0, [r6]
 *   @0x1df138 ldr r8, [r10, r1]
 *   @0x1df13c str r2, [r8]
 *   @0x1df140 ldr r2, [r3]
 *   @0x1df144 movw r1, #0x524d
 *   @0x1df148 movw r3, #0x4f46
 *   @0x1df14c movt r1, #0x464f
 *   @0x1df150 movt r3, #0x4d52
 *   @0x1df154 cmp r2, r3
 *   @0x1df158 cmpne r2, r1
 *   @0x1df15c beq 0x1df2e0 <_Z14RunnerLoadGamev+0x3d8>
 *   @0x1df160 ldr r3, [pc, #0x3f0]
 *   @0x1df164 ldr r4, [r10, r3]
 *   @0x1df168 ldr r3, [r4]
 *   @0x1df16c cmp r3, #0
 *   @0x1df170 beq 0x1df40c <_Z14RunnerLoadGamev+0x504>
 *   @0x1df174 ldr r12, [sp, #0x4]
 *   @0x1df178 mov r0, #0
 *   @0x1df17c ldr r2, [sp, #0x414]
 *   @0x1df180 ldr r3, [r12]
 *   @0x1df184 cmp r2, r3
 *   @0x1df188 bne 0x1df500 <_Z14RunnerLoadGamev+0x5f8>
 *   @0x1df18c add sp, sp, #1040
 *   @0x1df190 add sp, sp, #12
 *   @0x1df194 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1df198 add r1, sp, #16
 *   @0x1df19c mov r0, r6
 *   @0x1df1a0 mov r3, #0
 *   @0x1df1a4 str r3, [sp, #0x10]
 *   @0x1df1a8 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x1df1ac ldr r1, [pc, #0x3a8]
 *   @0x1df1b0 ldr r2, [pc, #0x3a8]
 *   @0x1df1b4 ldr r3, [sp, #0x10]
 *   @0x1df1b8 ldr lr, [r10, r1]
 *   @0x1df1bc mov r1, r3
 *   @0x1df1c0 str r0, [lr]
 *   @0x1df1c4 ldr r2, [r10, r2]
 *   @0x1df1c8 str r3, [r2]
 *   @0x1df1cc bl 0x1de7b0 <_Z13LoadDebugInfoPvj>
 *   @0x1df1d0 b 0x1df0d4 <_Z14RunnerLoadGamev+0x1cc>
 *   @0x1df1d4 ldr r3, [r4]
 *   @0x1df1d8 mov r2, r6
 *   @0x1df1dc ldr r1, [pc, #0x380]
 *   @0x1df1e0 mov r0, r4
 *   @0x1df1e4 add r1, pc, r1
 *   @0x1df1e8 ldr r3, [r3, #0xc]
 *   @0x1df1ec blx r3
 *   @0x1df1f0 mov r0, #28
 *   @0x1df1f4 bl 0x27c524 <_Znwj>
 *   @0x1df1f8 mov r2, #1
 *   @0x1df1fc mov r1, r6
 *   @0x1df200 mov r11, r0
 *   @0x1df204 bl 0x2362b8 <_ZN7IniFileC2EPcb>
 *   @0x1df208 ldr r2, [pc, #0x358]
 *   @0x1df20c cmp r11, #0
 *   @0x1df210 ldr r9, [r10, r2]
 *   @0x1df214 beq 0x1df238 <_Z14RunnerLoadGamev+0x330>
 *   @0x1df218 ldr r0, [r9]
 *   @0x1df21c cmp r0, #0
 *   @0x1df220 beq 0x1df238 <_Z14RunnerLoadGamev+0x330>
 *   @0x1df224 ldr r2, [pc, #0x340]
 *   @0x1df228 ldr r2, [r10, r2]
 *   @0x1df22c ldrb r2, [r2]
 *   @0x1df230 cmp r2, #0
 *   @0x1df234 bne 0x1df4c8 <_Z14RunnerLoadGamev+0x5c0>
 *   @0x1df238 mov r0, r11
 *   @0x1df23c str r11, [r9]
 *   @0x1df240 bl 0x18cd20 <_Z8IO_SetupP7IniFile>
 *   @0x1df244 ldr r0, [r9]
 *   @0x1df248 bl 0x18f6bc <_ZN8LoadSave5SetUpEP7IniFile>
 *   @0x1df24c ldr r0, [r9]
 *   @0x1df250 bl 0x221374 <_Z11Sound_SetupP7IniFile>
 *   @0x1df254 ldr r0, [r9]
 *   @0x1df258 bl 0x1de984 <_Z14Platform_SetupP7IniFile>
 *   @0x1df25c b 0x1df064 <_Z14RunnerLoadGamev+0x15c>
 *   @0x1df260 ldr r3, [r7]
 *   @0x1df264 cmp r3, #0
 *   @0x1df268 beq 0x1df278 <_Z14RunnerLoadGamev+0x370>
 *   @0x1df26c ldrb r3, [r3]
 *   @0x1df270 cmp r3, #0
 *   @0x1df274 bne 0x1df41c <_Z14RunnerLoadGamev+0x514>
 *   @0x1df278 ldr r3, [pc, #0x2f0]
 *   @0x1df27c ldr r3, [r10, r3]
 *   @0x1df280 ldrb r3, [r3]
 *   @0x1df284 cmp r3, #0
 *   @0x1df288 beq 0x1df49c <_Z14RunnerLoadGamev+0x594>
 *   @0x1df28c ldr r3, [pc, #0x2d8]
 *   @0x1df290 ldr r3, [r10, r3]
 *   @0x1df294 ldrb r3, [r3]
 *   @0x1df298 cmp r3, #0
 *   @0x1df29c beq 0x1df504 <_Z14RunnerLoadGamev+0x5fc>
 *   @0x1df2a0 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1df2a4 ldr r3, [pc, #0x27c]
 *   @0x1df2a8 mov r12, #1
 *   @0x1df2ac str r12, [sp, #0xc]
 *   @0x1df2b0 mov r5, #0
 *   @0x1df2b4 ldr r9, [r10, r3]
 *   @0x1df2b8 ldr r3, [r4]
 *   @0x1df2bc mov r0, r4
 *   @0x1df2c0 ldr r1, [pc, #0x2ac]
 *   @0x1df2c4 mov r2, r5
 *   @0x1df2c8 add r1, pc, r1
 *   @0x1df2cc ldr r3, [r3, #0xc]
 *   @0x1df2d0 blx r3
 *   @0x1df2d4 str r5, [r9]
 *   @0x1df2d8 str r5, [r7]
 *   @0x1df2dc b 0x1defb4 <_Z14RunnerLoadGamev+0xac>
 *   @0x1df2e0 ldr r12, [sp, #0x8]
 *   @0x1df2e4 ldr r1, [pc, #0x28c]
 *   @0x1df2e8 ldr r0, [r12]
 *   @0x1df2ec add r1, pc, r1
 *   @0x1df2f0 ldr r3, [r0]
 *   @0x1df2f4 ldr r3, [r3, #0xc]
 *   @0x1df2f8 blx r3
 *   @0x1df2fc ldr r0, [r8]
 *   @0x1df300 ldr r1, [r6]
 *   @0x1df304 bl 0x1dfb7c <_Z10DecryptWadPci>
 *   @0x1df308 b 0x1df160 <_Z14RunnerLoadGamev+0x258>
 *   @0x1df30c ldr r0, [pc, #0x268]
 *   @0x1df310 add r0, pc, r0
 *   @0x1df314 bl 0x27b948 <_Z17memLogPushContextPKc>
 *   @0x1df318 ldr r12, [sp, #0xc]
 *   @0x1df31c mov r0, r5
 *   @0x1df320 mov r1, r6
 *   @0x1df324 cmp r12, #0
 *   @0x1df328 bne 0x1df3cc <_Z14RunnerLoadGamev+0x4c4>
 *   @0x1df32c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x1df330 ldr r3, [pc, #0x21c]
 *   @0x1df334 ldr r8, [r10, r3]
 *   @0x1df338 str r0, [r8]
 *   @0x1df33c bl 0x27b94c <_Z16memLogPopContextv>
 *   @0x1df340 ldr r3, [r8]
 *   @0x1df344 cmp r3, #0
 *   @0x1df348 beq 0x1df4d8 <_Z14RunnerLoadGamev+0x5d0>
 *   @0x1df34c ldr lr, [r4]
 *   @0x1df350 mov r0, r4
 *   @0x1df354 ldr r1, [pc, #0x224]
 *   @0x1df358 mov r2, r5
 *   @0x1df35c ldr r3, [r6]
 *   @0x1df360 add r1, pc, r1
 *   @0x1df364 ldr r4, [lr, #0xc]
 *   @0x1df368 blx r4
 *   @0x1df36c ldr r2, [pc, #0x210]
 *   @0x1df370 ldr r3, [r8]
 *   @0x1df374 ldr r1, [r6]
 *   @0x1df378 ldr r2, [r10, r2]
 *   @0x1df37c cmp r3, #0
 *   @0x1df380 add r1, r1, #128
 *   @0x1df384 str r1, [r2]
 *   @0x1df388 bne 0x1df140 <_Z14RunnerLoadGamev+0x238>
 *   @0x1df38c add r4, sp, #20
 *   @0x1df390 ldr r2, [pc, #0x1f0]
 *   @0x1df394 ldr r3, [r7]
 *   @0x1df398 mov r1, #1024
 *   @0x1df39c add r2, pc, r2
 *   @0x1df3a0 mov r0, r4
 *   @0x1df3a4 bl 0xb65c8 <snprintf@plt>
 *   @0x1df3a8 mov r0, r4
 *   @0x1df3ac bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df3b0 ldr r3, [pc, #0x1b4]
 *   @0x1df3b4 ldr r3, [r10, r3]
 *   @0x1df3b8 ldrb r3, [r3]
 *   @0x1df3bc cmp r3, #0
 *   @0x1df3c0 beq 0x1df504 <_Z14RunnerLoadGamev+0x5fc>
 *   @0x1df3c4 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1df3c8 b 0x1df160 <_Z14RunnerLoadGamev+0x258>
 *   @0x1df3cc bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x1df3d0 b 0x1df330 <_Z14RunnerLoadGamev+0x428>
 *   @0x1df3d4 mov r1, #92
 *   @0x1df3d8 mov r0, r6
 *   @0x1df3dc bl 0xb6868 <strrchr@plt>
 *   @0x1df3e0 ldr lr, [r4]
 *   @0x1df3e4 ldr r1, [pc, #0x1a0]
 *   @0x1df3e8 ldr r2, [r9]
 *   @0x1df3ec add r1, pc, r1
 *   @0x1df3f0 ldr r9, [lr, #0xc]
 *   @0x1df3f4 mov r11, r0
 *   @0x1df3f8 mov r0, r4
 *   @0x1df3fc blx r9
 *   @0x1df400 cmp r11, #0
 *   @0x1df404 beq 0x1df064 <_Z14RunnerLoadGamev+0x15c>
 *   @0x1df408 b 0x1df018 <_Z14RunnerLoadGamev+0x110>
 *   @0x1df40c ldr r0, [r7]
 *   @0x1df410 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1df414 str r0, [r4]
 *   @0x1df418 b 0x1df174 <_Z14RunnerLoadGamev+0x26c>
 *   @0x1df41c bl 0x28fd5c <_Z14GetFilePrePendv>
 *   @0x1df420 mov r5, r0
 *   @0x1df424 ldr r0, [r7]
 *   @0x1df428 bl 0xb6538 <strlen@plt>
 *   @0x1df42c mov r6, r0
 *   @0x1df430 mov r0, r5
 *   @0x1df434 bl 0xb6538 <strlen@plt>
 *   @0x1df438 mov r3, #1
 *   @0x1df43c ldr r1, [pc, #0x14c]
 *   @0x1df440 movw r2, #0x8ab
 *   @0x1df444 add r1, pc, r1
 *   @0x1df448 add r0, r6, r0
 *   @0x1df44c add r6, r0, r3
 *   @0x1df450 mov r0, r6
 *   @0x1df454 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1df458 ldr r2, [pc, #0xc8]
 *   @0x1df45c ldr r3, [r7]
 *   @0x1df460 ldr r9, [r10, r2]
 *   @0x1df464 str r3, [r9]
 *   @0x1df468 mov r5, r0
 *   @0x1df46c bl 0x1fd150 <_Z19SetWorkingDirectoryv>
 *   @0x1df470 ldr r0, [r7]
 *   @0x1df474 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1df478 mov r1, r6
 *   @0x1df47c ldr r2, [r7]
 *   @0x1df480 subs r11, r0, #0
 *   @0x1df484 mov r0, r5
 *   @0x1df488 beq 0x1df4bc <_Z14RunnerLoadGamev+0x5b4>
 *   @0x1df48c mov r12, #1
 *   @0x1df490 str r12, [sp, #0xc]
 *   @0x1df494 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1df498 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0>
 *   @0x1df49c bl 0x1dfb80 <_Z13YYGetFileNamev>
 *   @0x1df4a0 subs r5, r0, #0
 *   @0x1df4a4 beq 0x1df28c <_Z14RunnerLoadGamev+0x384>
 *   @0x1df4a8 ldr r3, [pc, #0x78]
 *   @0x1df4ac mov r12, #1
 *   @0x1df4b0 str r12, [sp, #0xc]
 *   @0x1df4b4 ldr r9, [r10, r3]
 *   @0x1df4b8 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0>
 *   @0x1df4bc str r11, [sp, #0xc]
 *   @0x1df4c0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1df4c4 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0>
 *   @0x1df4c8 mov r1, r11
 *   @0x1df4cc bl 0x1dee84 <_Z16OverwriteGameINIP7IniFileS0_>
 *   @0x1df4d0 ldr r0, [r9]
 *   @0x1df4d4 b 0x1df240 <_Z14RunnerLoadGamev+0x338>
 *   @0x1df4d8 ldr r3, [pc, #0xb4]
 *   @0x1df4dc mov r2, r5
 *   @0x1df4e0 ldr r1, [pc, #0xb0]
 *   @0x1df4e4 ldr r3, [r10, r3]
 *   @0x1df4e8 add r1, pc, r1
 *   @0x1df4ec ldr r0, [r3]
 *   @0x1df4f0 ldr r3, [r0]
 *   @0x1df4f4 ldr r3, [r3, #0xc]
 *   @0x1df4f8 blx r3
 *   @0x1df4fc b 0x1df36c <_Z14RunnerLoadGamev+0x464>
 *   @0x1df500 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1df504 mov r0, #1
 *   @0x1df508 bl 0xb6688 <exit@plt>
 *   @0x1df50c eoreq r2, r1, r4, lsr sp
 *   @0x1df510 .word 0xffffbd00
 *   @0x1df514 .word 0xffffdecc
 *   @0x1df518 .word 0xffffeed0
 *   @0x1df51c ldrheq r2, [r7], -r8
 *   @0x1df520 .word 0xffffbef0
 *   @0x1df524 andseq r2, r7, r8, lsl #19
 *   @0x1df528 .word 0xfffff0ac
 *   @0x1df52c andseq r2, r7, r8, asr r8
 *   @0x1df530 andseq r2, r7, r8, lsr #18
 *   @0x1df534 andseq r2, r7, r12, lsr r9
 *   @0x1df538 andseq r2, r7, r12, lsl r9
 *   @0x1df53c .word 0xfffff0b0
 *   @0x1df540 andseq r2, r7, r8, lsr #15
 *   @0x1df544 andseq r2, r7, r0, lsl #18
 *   @0x1df548 .word 0xfffff0b4
 *   @0x1df54c .word 0xfffff0b8
 *   @0x1df550 andseq r2, r7, r8, asr #17
 *   @0x1df554 .word 0xfffff0bc
 *   @0x1df558 .word 0xffffdf5c
 *   @0x1df55c .word 0xfffff0c0
 *   @0x1df560 .word 0xfffff0c4
 *   @0x1df564 andseq r2, r7, r8, lsr #15
 *   @0x1df568 .word 0xfffff0c8
 *   @0x1df56c .word 0xffffbfe0
 *   @0x1df570 .word 0xfffff0cc
 *   @0x1df574 andseq r2, r7, r0, asr #12
 *   @0x1df578 andseq r2, r7, r8, lsl r7
 *   @0x1df57c ldrheq r2, [r7], -r12
 *   @0x1df580 andseq r2, r7, r8, ror r6
 *   @0x1df584 .word 0xffffe78c
 *   @0x1df588 andseq r2, r7, r8, ror r6
 *   @0x1df58c andseq r2, r7, r8, asr #10
 *   @0x1df590 andseq r2, r7, r0, ror #7
 *   @0x1df594 .word 0xffffbcf0
 *   @0x1df598 andseq r2, r7, r4, lsl #10
 *
 * ══ §8/20 InitialiseUniforms(GLSLShader*)  0x186834  size 1656  414 条（0x186834..0x186eac）
 * @func 0x186834 0x186eac  size 1656  414 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x186864→0x479b30, 0x186880→0x479afc, 0x1868b8→0x479ab8, 0x186a98→0x479ab8, 0x186b9c→0x479af0, 0x186bc0→0x479b2c, 0x186ce0→0x479ab8, 0x186dc8→0x479af0
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete[](void*)×2 / operator new[](unsigned int)×2 / InitialiseUniforms(GLSLShader*)+0x3bc×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65a4×2 / InitialiseUniforms(GLSLShader*)+0x158×2 / InitialiseUniforms(GLSLShader*)+0x620
 * 字段偏移 top8: 0x14×21 / 0x8×12 / 0x78×10 / 0x24×8 / 0x18×8 / 0x4×8 / 0x4c×7 / 0x54×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x186834 ldr r12, [pc, #0x648]
 *   @0x186838 ldr r3, [pc, #0x648]
 *   @0x18683c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x186840 add r12, pc, r12
 *   @0x186844 sub sp, sp, #228
 *   @0x186848 subs r4, r0, #0
 *   @0x18684c str r12, [sp, #0x24]
 *   @0x186850 ldr r3, [r12, r3]
 *   @0x186854 str r3, [sp, #0x38]
 *   @0x186858 ldr r3, [r3]
 *   @0x18685c str r3, [sp, #0xdc]
 *   @0x186860 beq 0x1869a4 <_Z18InitialiseUniformsP10GLSLShader+0x170>
 *   @0x186864 ldr r3, [pc, #0x620]
 *   @0x186868 ldr r0, [r4, #0x8]
 *   @0x18686c ldr r3, [r12, r3]
 *   @0x186870 str r3, [sp, #0x44]
 *   @0x186874 ldr r3, [r3]
 *   @0x186878 blx r3
 *   @0x18687c ldr r12, [sp, #0x24]
 *   @0x186880 ldr r3, [pc, #0x608]
 *   @0x186884 movw r1, #0x8b86
 *   @0x186888 ldr r0, [r4, #0x8]
 *   @0x18688c add r2, sp, #76
 *   @0x186890 ldr r3, [r12, r3]
 *   @0x186894 ldr r3, [r3]
 *   @0x186898 blx r3
 *   @0x18689c ldr r3, [sp, #0x4c]
 *   @0x1868a0 cmp r3, #0
 *   @0x1868a4 ble 0x186e54 <_Z18InitialiseUniformsP10GLSLShader+0x620>
 *   @0x1868a8 mov r12, #0
 *   @0x1868ac str r12, [sp, #0x28]
 *   @0x1868b0 ldr r12, [pc, #0x5dc]
 *   @0x1868b4 mov r8, #0
 *   @0x1868b8 ldr r3, [pc, #0x5d8]
 *   @0x1868bc mvn r9, #0
 *   @0x1868c0 add r12, pc, r12
 *   @0x1868c4 str r12, [sp, #0x18]
 *   @0x1868c8 mvn r12, #0
 *   @0x1868cc str r12, [sp, #0x30]
 *   @0x1868d0 add r12, sp, #84
 *   @0x1868d4 str r12, [sp, #0x1c]
 *   @0x1868d8 ldr r12, [sp, #0x24]
 *   @0x1868dc add r11, sp, #88
 *   @0x1868e0 add r5, sp, #92
 *   @0x1868e4 mov r6, r8
 *   @0x1868e8 movw r10, #0x8b5e
 *   @0x1868ec ldr r7, [r12, r3]
 *   @0x1868f0 str r11, [sp, #0x20]
 *   @0x1868f4 mov r11, r9
 *   @0x1868f8 str r8, [sp, #0x2c]
 *   @0x1868fc b 0x18693c <_Z18InitialiseUniformsP10GLSLShader+0x108>
 *   @0x186900 movw r0, #0x8b60
 *   @0x186904 cmp r3, r0
 *   @0x186908 ldrne r12, [sp, #0x28]
 *   @0x18690c addne r12, r12, #1
 *   @0x186910 strne r12, [sp, #0x28]
 *   @0x186914 mov r0, r5
 *   @0x186918 ldr r1, [sp, #0x18]
 *   @0x18691c bl 0xb6574 <strcmp@plt>
 *   @0x186920 ldr r3, [sp, #0x4c]
 *   @0x186924 cmp r0, #0
 *   @0x186928 moveq r11, r6
 *   @0x18692c add r6, r6, #1
 *   @0x186930 moveq r8, #1
 *   @0x186934 cmp r3, r6
 *   @0x186938 ble 0x1869c0 <_Z18InitialiseUniformsP10GLSLShader+0x18c>
 *   @0x18693c ldr r12, [sp, #0x1c]
 *   @0x186940 mov r3, #0
 *   @0x186944 ldr r0, [r4, #0x8]
 *   @0x186948 mov r1, r6
 *   @0x18694c str r5, [sp, #0x8]
 *   @0x186950 mov r2, #128
 *   @0x186954 str r12, [sp]
 *   @0x186958 ldr r12, [sp, #0x20]
 *   @0x18695c str r9, [sp, #0x54]
 *   @0x186960 str r9, [sp, #0x58]
 *   @0x186964 str r12, [sp, #0x4]
 *   @0x186968 ldr r12, [r7]
 *   @0x18696c blx r12
 *   @0x186970 ldr r3, [sp, #0x58]
 *   @0x186974 cmp r3, r10
 *   @0x186978 bne 0x186900 <_Z18InitialiseUniformsP10GLSLShader+0xcc>
 *   @0x18697c ldr r12, [sp, #0x2c]
 *   @0x186980 add r12, r12, #1
 *   @0x186984 str r12, [sp, #0x2c]
 *   @0x186988 b 0x186914 <_Z18InitialiseUniformsP10GLSLShader+0xe0>
 *   @0x18698c ldr r12, [sp, #0x28]
 *   @0x186990 mov r0, #0
 *   @0x186994 str r12, [r4, #0x7c]
 *   @0x186998 ldr r12, [sp, #0x44]
 *   @0x18699c ldr r3, [r12]
 *   @0x1869a0 blx r3
 *   @0x1869a4 ldr r12, [sp, #0x38]
 *   @0x1869a8 ldr r2, [sp, #0xdc]
 *   @0x1869ac ldr r3, [r12]
 *   @0x1869b0 cmp r2, r3
 *   @0x1869b4 bne 0x186e80 <_Z18InitialiseUniformsP10GLSLShader+0x64c>
 *   @0x1869b8 add sp, sp, #228
 *   @0x1869bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1869c0 ldr r5, [sp, #0x2c]
 *   @0x1869c4 ldr r12, [sp, #0x28]
 *   @0x1869c8 sub r6, r5, #1
 *   @0x1869cc str r11, [sp, #0x30]
 *   @0x1869d0 str r12, [sp, #0x34]
 *   @0x1869d4 sub r12, r12, #1
 *   @0x1869d8 str r12, [sp, #0x40]
 *   @0x1869dc ldr r0, [r4, #0x14]
 *   @0x1869e0 cmp r0, #0
 *   @0x1869e4 beq 0x186a20 <_Z18InitialiseUniformsP10GLSLShader+0x1ec>
 *   @0x1869e8 ldr r7, [r0, #-0x4]
 *   @0x1869ec add r7, r7, r7, lsl #1
 *   @0x1869f0 add r7, r0, r7, lsl #2
 *   @0x1869f4 cmp r0, r7
 *   @0x1869f8 beq 0x186a10 <_Z18InitialiseUniformsP10GLSLShader+0x1dc>
 *   @0x1869fc ldr r0, [r7, #-0xc]!
 *   @0x186a00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186a04 ldr r0, [r4, #0x14]
 *   @0x186a08 cmp r0, r7
 *   @0x186a0c bne 0x1869fc <_Z18InitialiseUniformsP10GLSLShader+0x1c8>
 *   @0x186a10 sub r0, r0, #8
 *   @0x186a14 bl 0x27d1d4 <_ZdaPv>
 *   @0x186a18 mov r3, #0
 *   @0x186a1c str r3, [r4, #0x14]
 *   @0x186a20 cmp r5, #178257920
 *   @0x186a24 addls r0, r5, r5, lsl #1
 *   @0x186a28 mvnhi r0, #0
 *   @0x186a2c lslls r0, r0, #2
 *   @0x186a30 addls r0, r0, #8
 *   @0x186a34 bl 0x27d14c <_Znaj>
 *   @0x186a38 cmn r6, #1
 *   @0x186a3c mov r3, #12
 *   @0x186a40 str r5, [r0, #0x4]
 *   @0x186a44 str r3, [r0]
 *   @0x186a48 beq 0x186a7c <_Z18InitialiseUniformsP10GLSLShader+0x248>
 *   @0x186a4c mov r2, #0
 *   @0x186a50 add r6, r6, #1
 *   @0x186a54 add r3, r0, #20
 *   @0x186a58 mov r1, r2
 *   @0x186a5c mvn r12, #0
 *   @0x186a60 add r2, r2, #1
 *   @0x186a64 str r1, [r3, #-0xc]
 *   @0x186a68 cmp r2, r6
 *   @0x186a6c str r12, [r3, #-0x8]
 *   @0x186a70 str r1, [r3, #-0x4]
 *   @0x186a74 add r3, r3, #12
 *   @0x186a78 bne 0x186a60 <_Z18InitialiseUniformsP10GLSLShader+0x22c>
 *   @0x186a7c ldr r3, [sp, #0x4c]
 *   @0x186a80 add r0, r0, #8
 *   @0x186a84 str r0, [r4, #0x14]
 *   @0x186a88 cmp r3, #0
 *   @0x186a8c ble 0x186bf0 <_Z18InitialiseUniformsP10GLSLShader+0x3bc>
 *   @0x186a90 ldr r12, [pc, #0x404]
 *   @0x186a94 mov r6, #0
 *   @0x186a98 ldr r3, [pc, #0x3f8]
 *   @0x186a9c add r11, sp, #88
 *   @0x186aa0 add r12, pc, r12
 *   @0x186aa4 str r12, [sp, #0x3c]
 *   @0x186aa8 add r12, sp, #84
 *   @0x186aac str r12, [sp, #0x1c]
 *   @0x186ab0 ldr r12, [sp, #0x24]
 *   @0x186ab4 add r5, sp, #92
 *   @0x186ab8 mvn r9, #0
 *   @0x186abc mov r10, r8
 *   @0x186ac0 ldr r7, [r12, r3]
 *   @0x186ac4 add r12, sp, #80
 *   @0x186ac8 str r12, [sp, #0x18]
 *   @0x186acc b 0x186ae0 <_Z18InitialiseUniformsP10GLSLShader+0x2ac>
 *   @0x186ad0 ldr r3, [sp, #0x4c]
 *   @0x186ad4 add r6, r6, #1
 *   @0x186ad8 cmp r3, r6
 *   @0x186adc ble 0x186bf0 <_Z18InitialiseUniformsP10GLSLShader+0x3bc>
 *   @0x186ae0 mov r12, #0
 *   @0x186ae4 str r12, [sp, #0x58]
 *   @0x186ae8 ldr r12, [sp, #0x18]
 *   @0x186aec mov r3, r11
 *   @0x186af0 ldr r0, [r4, #0x8]
 *   @0x186af4 mov r1, r6
 *   @0x186af8 str r5, [sp, #0x8]
 *   @0x186afc mov r2, #128
 *   @0x186b00 str r12, [sp]
 *   @0x186b04 ldr r12, [sp, #0x1c]
 *   @0x186b08 str r9, [sp, #0x50]
 *   @0x186b0c str r9, [sp, #0x54]
 *   @0x186b10 str r12, [sp, #0x4]
 *   @0x186b14 ldr r12, [r7]
 *   @0x186b18 blx r12
 *   @0x186b1c ldr r3, [sp, #0x54]
 *   @0x186b20 movw r0, #0x8b5e
 *   @0x186b24 cmp r3, r0
 *   @0x186b28 bne 0x186ad0 <_Z18InitialiseUniformsP10GLSLShader+0x29c>
 *   @0x186b2c ldr r12, [sp, #0x30]
 *   @0x186b30 mov r2, #70
 *   @0x186b34 ldr r0, [sp, #0x58]
 *   @0x186b38 mov r3, #1
 *   @0x186b3c cmp r6, r12
 *   @0x186b40 ldr r12, [r4, #0x14]
 *   @0x186b44 addne r8, r10, r10, lsl #1
 *   @0x186b48 ldr r1, [sp, #0x3c]
 *   @0x186b4c add r0, r0, r3
 *   @0x186b50 moveq r8, #0
 *   @0x186b54 lslne r8, r8, #2
 *   @0x186b58 strne r10, [sp, #0x20]
 *   @0x186b5c streq r8, [sp, #0x20]
 *   @0x186b60 addne r10, r10, #1
 *   @0x186b64 str r12, [sp, #0x14]
 *   @0x186b68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x186b6c ldr r3, [r4, #0x14]
 *   @0x186b70 mov r1, r5
 *   @0x186b74 ldr r12, [sp, #0x14]
 *   @0x186b78 add r6, r6, #1
 *   @0x186b7c str r0, [r12, r8]
 *   @0x186b80 ldr r0, [r3, r8]
 *   @0x186b84 bl 0xb65a4 <strcpy@plt>
 *   @0x186b88 ldr r3, [r4, #0x14]
 *   @0x186b8c ldr r12, [sp, #0x20]
 *   @0x186b90 mov r1, r5
 *   @0x186b94 add r3, r3, r8
 *   @0x186b98 ldr r0, [r4, #0x8]
 *   @0x186b9c ldr r2, [pc, #0x2fc]
 *   @0x186ba0 str r12, [r3, #0x8]
 *   @0x186ba4 ldr r12, [sp, #0x24]
 *   @0x186ba8 ldr r2, [r12, r2]
 *   @0x186bac ldr r2, [r2]
 *   @0x186bb0 str r3, [sp, #0x14]
 *   @0x186bb4 blx r2
 *   @0x186bb8 ldr r12, [r4, #0x14]
 *   @0x186bbc ldr r3, [sp, #0x14]
 *   @0x186bc0 ldr r2, [pc, #0x2dc]
 *   @0x186bc4 add r8, r12, r8
 *   @0x186bc8 ldr r12, [sp, #0x24]
 *   @0x186bcc ldr r1, [sp, #0x20]
 *   @0x186bd0 str r0, [r3, #0x4]
 *   @0x186bd4 ldr r3, [r12, r2]
 *   @0x186bd8 ldr r0, [r8, #0x4]
 *   @0x186bdc ldr r3, [r3]
 *   @0x186be0 blx r3
 *   @0x186be4 ldr r3, [sp, #0x4c]
 *   @0x186be8 cmp r3, r6
 *   @0x186bec bgt 0x186ae0 <_Z18InitialiseUniformsP10GLSLShader+0x2ac>
 *   @0x186bf0 ldr r0, [r4, #0x78]
 *   @0x186bf4 ldr r12, [sp, #0x2c]
 *   @0x186bf8 cmp r0, #0
 *   @0x186bfc str r12, [r4, #0x18]
 *   @0x186c00 beq 0x186c3c <_Z18InitialiseUniformsP10GLSLShader+0x408>
 *   @0x186c04 ldr r5, [r0, #-0x4]
 *   @0x186c08 rsb r5, r5, r5, lsl #3
 *   @0x186c0c add r5, r0, r5, lsl #2
 *   @0x186c10 cmp r0, r5
 *   @0x186c14 beq 0x186c2c <_Z18InitialiseUniformsP10GLSLShader+0x3f8>
 *   @0x186c18 ldr r0, [r5, #-0x1c]!
 *   @0x186c1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x186c20 ldr r0, [r4, #0x78]
 *   @0x186c24 cmp r0, r5
 *   @0x186c28 bne 0x186c18 <_Z18InitialiseUniformsP10GLSLShader+0x3e4>
 *   @0x186c2c sub r0, r0, #8
 *   @0x186c30 bl 0x27d1d4 <_ZdaPv>
 *   @0x186c34 mov r3, #0
 *   @0x186c38 str r3, [r4, #0x78]
 *   @0x186c3c ldr r12, [sp, #0x34]
 *   @0x186c40 cmp r12, #76546048
 *   @0x186c44 rsbls r0, r12, r12, lsl #3
 *   @0x186c48 mvnhi r0, #0
 *   @0x186c4c lslls r0, r0, #2
 *   @0x186c50 addls r0, r0, #8
 *   @0x186c54 bl 0x27d14c <_Znaj>
 *   @0x186c58 ldr r12, [sp, #0x40]
 *   @0x186c5c mov r3, #28
 *   @0x186c60 cmn r12, #1
 *   @0x186c64 ldr r12, [sp, #0x34]
 *   @0x186c68 str r3, [r0]
 *   @0x186c6c str r12, [r0, #0x4]
 *   @0x186c70 beq 0x186cc4 <_Z18InitialiseUniformsP10GLSLShader+0x490>
 *   @0x186c74 ldr r12, [sp, #0x40]
 *   @0x186c78 mov r2, #0
 *   @0x186c7c add r3, r0, #36
 *   @0x186c80 mov r6, r2
 *   @0x186c84 add r7, r12, #1
 *   @0x186c88 mvn r5, #0
 *   @0x186c8c movw lr, #0x8b52
 *   @0x186c90 mov r12, #4
 *   @0x186c94 mov r1, #1
 *   @0x186c98 add r2, r2, #1
 *   @0x186c9c str r6, [r3, #-0x1c]
 *   @0x186ca0 cmp r2, r7
 *   @0x186ca4 str r5, [r3, #-0x18]
 *   @0x186ca8 str lr, [r3, #-0x14]
 *   @0x186cac add r3, r3, #28
 *   @0x186cb0 str r12, [r3, #-0x2c]
 *   @0x186cb4 str r1, [r3, #-0x28]
 *   @0x186cb8 str r12, [r3, #-0x24]
 *   @0x186cbc str r1, [r3, #-0x20]
 *   @0x186cc0 bne 0x186c98 <_Z18InitialiseUniformsP10GLSLShader+0x464>
 *   @0x186cc4 ldr r3, [sp, #0x4c]
 *   @0x186cc8 add r0, r0, #8
 *   @0x186ccc str r0, [r4, #0x78]
 *   @0x186cd0 cmp r3, #0
 *   @0x186cd4 ble 0x18698c <_Z18InitialiseUniformsP10GLSLShader+0x158>
 *   @0x186cd8 ldr r12, [pc, #0x1c8]
 *   @0x186cdc mov r9, #0
 *   @0x186ce0 ldr r3, [pc, #0x1b0]
 *   @0x186ce4 add r11, sp, #88
 *   @0x186ce8 add r12, pc, r12
 *   @0x186cec str r12, [sp, #0x20]
 *   @0x186cf0 add r12, sp, #84
 *   @0x186cf4 str r12, [sp, #0x1c]
 *   @0x186cf8 ldr r12, [sp, #0x24]
 *   @0x186cfc add r5, sp, #92
 *   @0x186d00 mov r6, r9
 *   @0x186d04 ldr r10, [sp, #0x1c]
 *   @0x186d08 ldr r7, [r12, r3]
 *   @0x186d0c add r12, sp, #80
 *   @0x186d10 str r12, [sp, #0x18]
 *   @0x186d14 b 0x186d28 <_Z18InitialiseUniformsP10GLSLShader+0x4f4>
 *   @0x186d18 ldr r3, [sp, #0x4c]
 *   @0x186d1c add r6, r6, #1
 *   @0x186d20 cmp r3, r6
 *   @0x186d24 ble 0x18698c <_Z18InitialiseUniformsP10GLSLShader+0x158>
 *   @0x186d28 mov r12, #0
 *   @0x186d2c str r12, [sp, #0x58]
 *   @0x186d30 ldr r12, [sp, #0x18]
 *   @0x186d34 mvn r2, #0
 *   @0x186d38 ldr r0, [r4, #0x8]
 *   @0x186d3c movw r3, #0x8b52
 *   @0x186d40 str r2, [sp, #0x50]
 *   @0x186d44 mov r1, r6
 *   @0x186d48 mov r2, #128
 *   @0x186d4c str r3, [sp, #0x54]
 *   @0x186d50 str r12, [sp]
 *   @0x186d54 mov r3, r11
 *   @0x186d58 str r10, [sp, #0x4]
 *   @0x186d5c str r5, [sp, #0x8]
 *   @0x186d60 ldr r12, [r7]
 *   @0x186d64 blx r12
 *   @0x186d68 ldr r3, [sp, #0x54]
 *   @0x186d6c movw r2, #0x8b60
 *   @0x186d70 movw r0, #0x8b5e
 *   @0x186d74 cmp r3, r0
 *   @0x186d78 cmpne r3, r2
 *   @0x186d7c beq 0x186d18 <_Z18InitialiseUniformsP10GLSLShader+0x4e4>
 *   @0x186d80 ldr r12, [r4, #0x78]
 *   @0x186d84 mov r3, #1
 *   @0x186d88 ldr r0, [sp, #0x58]
 *   @0x186d8c mov r2, #70
 *   @0x186d90 ldr r1, [sp, #0x20]
 *   @0x186d94 add r0, r0, r3
 *   @0x186d98 str r12, [sp, #0x14]
 *   @0x186d9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x186da0 ldr r2, [r4, #0x78]
 *   @0x186da4 ldr r12, [sp, #0x14]
 *   @0x186da8 rsb r3, r9, r9, lsl #3
 *   @0x186dac mov r1, r5
 *   @0x186db0 add r9, r9, #1
 *   @0x186db4 lsl r8, r3, #2
 *   @0x186db8 str r0, [r12, r3, lsl #2]
 *   @0x186dbc ldr r0, [r2, r3, lsl #2]
 *   @0x186dc0 bl 0xb65a4 <strcpy@plt>
 *   @0x186dc4 ldr r12, [sp, #0x24]
 *   @0x186dc8 ldr r3, [pc, #0xd0]
 *   @0x186dcc mov r1, r5
 *   @0x186dd0 ldr r2, [r4, #0x78]
 *   @0x186dd4 ldr r0, [r4, #0x8]
 *   @0x186dd8 ldr r3, [r12, r3]
 *   @0x186ddc add r2, r2, r8
 *   @0x186de0 ldr r3, [r3]
 *   @0x186de4 str r2, [sp, #0x14]
 *   @0x186de8 blx r3
 *   @0x186dec ldr r2, [sp, #0x14]
 *   @0x186df0 ldr r3, [r4, #0x78]
 *   @0x186df4 add r3, r3, r8
 *   @0x186df8 str r0, [r2, #0x4]
 *   @0x186dfc ldr r0, [sp, #0x54]
 *   @0x186e00 str r0, [r3, #0x8]
 *   @0x186e04 str r3, [sp, #0x14]
 *   @0x186e08 bl 0x186760 <_Z18GetColumnsFromTypej>
 *   @0x186e0c ldr r3, [sp, #0x14]
 *   @0x186e10 ldr r2, [r4, #0x78]
 *   @0x186e14 add r2, r2, r8
 *   @0x186e18 str r0, [r3, #0xc]
 *   @0x186e1c ldr r0, [sp, #0x54]
 *   @0x186e20 str r2, [sp, #0x14]
 *   @0x186e24 bl 0x186808 <_Z15GetRowsFromTypej>
 *   @0x186e28 ldr r3, [r4, #0x78]
 *   @0x186e2c ldr r2, [sp, #0x14]
 *   @0x186e30 add r8, r3, r8
 *   @0x186e34 ldr r3, [r8, #0xc]
 *   @0x186e38 str r0, [r2, #0x10]
 *   @0x186e3c ldr r2, [r8, #0x10]
 *   @0x186e40 mul r3, r2, r3
 *   @0x186e44 str r3, [r8, #0x14]
 *   @0x186e48 ldr r3, [sp, #0x50]
 *   @0x186e4c str r3, [r8, #0x18]
 *   @0x186e50 b 0x186d18 <_Z18InitialiseUniformsP10GLSLShader+0x4e4>
 *   @0x186e54 mvn r12, #0
 *   @0x186e58 str r12, [sp, #0x40]
 *   @0x186e5c mov r12, #0
 *   @0x186e60 mvn r6, #0
 *   @0x186e64 str r12, [sp, #0x34]
 *   @0x186e68 mov r5, r12
 *   @0x186e6c str r6, [sp, #0x30]
 *   @0x186e70 mov r8, r12
 *   @0x186e74 str r12, [sp, #0x28]
 *   @0x186e78 str r12, [sp, #0x2c]
 *   @0x186e7c b 0x1869dc <_Z18InitialiseUniformsP10GLSLShader+0x1a8>
 *   @0x186e80 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x186e84 eoreq r11, r6, r0, lsl r4
 *   @0x186e88 .word 0xffffbd00
 *   @0x186e8c .word 0xffffbb80
 *   @0x186e90 .word 0xffffbbb4
 *   @0x186e94 andseq r5, r12, r4, lsl #7
 *   @0x186e98 .word 0xffffbbf8
 *   @0x186e9c mulseq r10, r0, r5
 *   @0x186ea0 .word 0xffffbbc0
 *   @0x186ea4 .word 0xffffbb84
 *   @0x186ea8 andseq r10, r10, r8, asr #6
 *
 * ══ §9/20 CDS_Map::ReadFromString(char const*, bool)  0x20de08  size 1648  412 条（0x20de08..0x20e478）
 * @func 0x20de08 0x20e478  size 1648  412 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×5 / operator new(unsigned int)×2 / CStream::ReadInteger()×2 / CStream::~CStream()×2 / operator delete(void*)×2 / 0xb65b0×2 / YYSetString(RValue*, char const*)×2 / ReadValue(RValue&, CStream&, int)×2
 * 字段偏移 top8: 0x1×10 / 0x8×6 / 0xc×6 / 0x2×5 / 0x34×5 / 0x4×5 / 0x14×4 / 0x10×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20de08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20de0c sub sp, sp, #68
 *   @0x20de10 mov r7, r1
 *   @0x20de14 str r0, [sp, #0x8]
 *   @0x20de18 bl 0x20daf8 <_ZN7CDS_Map5ClearEv>
 *   @0x20de1c cmp r7, #0
 *   @0x20de20 beq 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88>
 *   @0x20de24 mov r0, r7
 *   @0x20de28 bl 0xb6538 <strlen@plt>
 *   @0x20de2c cmp r0, #1
 *   @0x20de30 bls 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88>
 *   @0x20de34 ldrb r3, [r7, #0x1]
 *   @0x20de38 cmp r3, #58
 *   @0x20de3c beq 0x20de9c <_ZN7CDS_Map14ReadFromStringEPKcb+0x94>
 *   @0x20de40 mov r0, #32
 *   @0x20de44 bl 0x27c524 <_Znwj>
 *   @0x20de48 mov r1, #0
 *   @0x20de4c mov r5, r0
 *   @0x20de50 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20de54 mov r0, r5
 *   @0x20de58 mov r1, r7
 *   @0x20de5c bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x20de60 mov r0, r5
 *   @0x20de64 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20de68 sub r0, r0, #400
 *   @0x20de6c sub r0, r0, #1
 *   @0x20de70 cmp r0, #1
 *   @0x20de74 bls 0x20e324 <_ZN7CDS_Map14ReadFromStringEPKcb+0x51c>
 *   @0x20de78 cmp r5, #0
 *   @0x20de7c beq 0x20de90 <_ZN7CDS_Map14ReadFromStringEPKcb+0x88>
 *   @0x20de80 mov r0, r5
 *   @0x20de84 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20de88 mov r0, r5
 *   @0x20de8c bl 0x27d1d0 <_ZdlPv>
 *   @0x20de90 mov r0, #0
 *   @0x20de94 add sp, sp, #68
 *   @0x20de98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20de9c ldrb r3, [r7]
 *   @0x20dea0 cmp r3, #0
 *   @0x20dea4 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380>
 *   @0x20dea8 ldr r1, [pc, #0x5b4]
 *   @0x20deac ldr r6, [pc, #0x5b4]
 *   @0x20deb0 add r1, pc, r1
 *   @0x20deb4 ldr r2, [pc, #0x5b0]
 *   @0x20deb8 str r1, [sp, #0x14]
 *   @0x20debc add r6, pc, r6
 *   @0x20dec0 ldr r3, [pc, #0x5a8]
 *   @0x20dec4 add r2, pc, r2
 *   @0x20dec8 ldr r1, [pc, #0x5a4]
 *   @0x20decc add r3, pc, r3
 *   @0x20ded0 str r2, [sp, #0xc]
 *   @0x20ded4 add r1, pc, r1
 *   @0x20ded8 str r3, [sp, #0x18]
 *   @0x20dedc str r1, [sp, #0x10]
 *   @0x20dee0 mov r0, #32
 *   @0x20dee4 mov r8, r7
 *   @0x20dee8 bl 0x27c524 <_Znwj>
 *   @0x20deec mov r1, #0
 *   @0x20def0 mov r2, #16
 *   @0x20def4 add r5, r0, #16
 *   @0x20def8 mov r4, r0
 *   @0x20defc bl 0xb65b0 <memset@plt>
 *   @0x20df00 mov r2, #16
 *   @0x20df04 mov r0, r5
 *   @0x20df08 mov r1, #0
 *   @0x20df0c bl 0xb65b0 <memset@plt>
 *   @0x20df10 ldrb r9, [r8], #2
 *   @0x20df14 sub r9, r9, #48
 *   @0x20df18 and r3, r9, #1
 *   @0x20df1c ubfx r9, r9, #0x1, #0x1
 *   @0x20df20 ands r2, r3, #255
 *   @0x20df24 str r3, [r4, #0xc]
 *   @0x20df28 str r9, [r4, #0x1c]
 *   @0x20df2c beq 0x20e228 <_ZN7CDS_Map14ReadFromStringEPKcb+0x420>
 *   @0x20df30 ldrb r3, [r7, #0x2]
 *   @0x20df34 add r7, r7, #3
 *   @0x20df38 cmp r3, #44
 *   @0x20df3c cmpne r3, #58
 *   @0x20df40 movne r10, #0
 *   @0x20df44 moveq r10, #1
 *   @0x20df48 beq 0x20e2dc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4d4>
 *   @0x20df4c cmp r3, #0
 *   @0x20df50 beq 0x20e2dc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4d4>
 *   @0x20df54 mov r2, r7
 *   @0x20df58 b 0x20df64 <_ZN7CDS_Map14ReadFromStringEPKcb+0x15c>
 *   @0x20df5c cmp r3, #0
 *   @0x20df60 beq 0x20df78 <_ZN7CDS_Map14ReadFromStringEPKcb+0x170>
 *   @0x20df64 ldrb r3, [r2], #1
 *   @0x20df68 add r10, r10, #1
 *   @0x20df6c cmp r3, #58
 *   @0x20df70 cmpne r3, #44
 *   @0x20df74 bne 0x20df5c <_ZN7CDS_Map14ReadFromStringEPKcb+0x154>
 *   @0x20df78 asr r10, r10, #1
 *   @0x20df7c ldr r1, [sp, #0xc]
 *   @0x20df80 add r0, r10, #1
 *   @0x20df84 movw r2, #0x76a
 *   @0x20df88 mov r3, #1
 *   @0x20df8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20df90 cmp r10, #0
 *   @0x20df94 moveq r10, r8
 *   @0x20df98 mov r1, r0
 *   @0x20df9c moveq r0, r0
 *   @0x20dfa0 beq 0x20e000 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1f8>
 *   @0x20dfa4 add r0, r1, r10
 *   @0x20dfa8 mov r3, r8
 *   @0x20dfac mov r12, r1
 *   @0x20dfb0 ldrb r2, [r3]
 *   @0x20dfb4 add r3, r3, #2
 *   @0x20dfb8 sub r7, r2, #55
 *   @0x20dfbc cmp r2, #64
 *   @0x20dfc0 sub lr, r2, #48
 *   @0x20dfc4 ldrb r2, [r3, #-0x1]
 *   @0x20dfc8 lsl lr, lr, #4
 *   @0x20dfcc sub r11, r2, #55
 *   @0x20dfd0 lslhi lr, r7, #4
 *   @0x20dfd4 cmp r2, #64
 *   @0x20dfd8 sub r7, r2, #48
 *   @0x20dfdc orr r2, lr, r11
 *   @0x20dfe0 orrls r2, lr, r7
 *   @0x20dfe4 strb r2, [r12], #1
 *   @0x20dfe8 cmp r12, r0
 *   @0x20dfec bne 0x20dfb0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1a8>
 *   @0x20dff0 lsl r10, r10, #1
 *   @0x20dff4 add r7, r8, r10
 *   @0x20dff8 mov r10, r7
 *   @0x20dffc add r7, r7, #1
 *   @0x20e000 mov r8, #0
 *   @0x20e004 strb r8, [r0]
 *   @0x20e008 mov r0, r4
 *   @0x20e00c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20e010 ldr r3, [r4, #0xc]
 *   @0x20e014 bic r3, r3, #-16777216
 *   @0x20e018 cmp r3, #1
 *   @0x20e01c movne r0, r8
 *   @0x20e020 beq 0x20e2cc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4c4>
 *   @0x20e024 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x20e028 mov r8, r0
 *   @0x20e02c cmp r9, #0
 *   @0x20e030 beq 0x20e194 <_ZN7CDS_Map14ReadFromStringEPKcb+0x38c>
 *   @0x20e034 ldrb r3, [r10, #0x1]
 *   @0x20e038 add r10, r10, #2
 *   @0x20e03c cmp r3, #44
 *   @0x20e040 cmpne r3, #58
 *   @0x20e044 movne r9, #0
 *   @0x20e048 moveq r9, #1
 *   @0x20e04c beq 0x20e304 <_ZN7CDS_Map14ReadFromStringEPKcb+0x4fc>
 *   @0x20e050 cmp r3, #0
 *   @0x20e054 bne 0x20e064 <_ZN7CDS_Map14ReadFromStringEPKcb+0x25c>
 *   @0x20e058 b 0x20e304 <_ZN7CDS_Map14ReadFromStringEPKcb+0x4fc>
 *   @0x20e05c cmp r3, #0
 *   @0x20e060 beq 0x20e078 <_ZN7CDS_Map14ReadFromStringEPKcb+0x270>
 *   @0x20e064 ldrb r3, [r10], #1
 *   @0x20e068 add r9, r9, #1
 *   @0x20e06c cmp r3, #58
 *   @0x20e070 cmpne r3, #44
 *   @0x20e074 bne 0x20e05c <_ZN7CDS_Map14ReadFromStringEPKcb+0x254>
 *   @0x20e078 asr r9, r9, #1
 *   @0x20e07c ldr r1, [sp, #0x10]
 *   @0x20e080 add r0, r9, #1
 *   @0x20e084 movw r2, #0x76a
 *   @0x20e088 mov r3, #1
 *   @0x20e08c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20e090 cmp r9, #0
 *   @0x20e094 mov r1, r0
 *   @0x20e098 moveq r11, r0
 *   @0x20e09c beq 0x20e0f0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2e8>
 *   @0x20e0a0 add r11, r0, r9
 *   @0x20e0a4 mov r3, r7
 *   @0x20e0a8 mov r12, r0
 *   @0x20e0ac ldrb r2, [r3]
 *   @0x20e0b0 add r3, r3, #2
 *   @0x20e0b4 sub lr, r2, #55
 *   @0x20e0b8 cmp r2, #64
 *   @0x20e0bc sub r0, r2, #48
 *   @0x20e0c0 ldrb r2, [r3, #-0x1]
 *   @0x20e0c4 lsl r0, r0, #4
 *   @0x20e0c8 sub r10, r2, #55
 *   @0x20e0cc lslhi r0, lr, #4
 *   @0x20e0d0 cmp r2, #64
 *   @0x20e0d4 sub lr, r2, #48
 *   @0x20e0d8 orr r2, r0, r10
 *   @0x20e0dc orrls r2, r0, lr
 *   @0x20e0e0 strb r2, [r12], #1
 *   @0x20e0e4 cmp r12, r11
 *   @0x20e0e8 bne 0x20e0ac <_ZN7CDS_Map14ReadFromStringEPKcb+0x2a4>
 *   @0x20e0ec add r7, r7, r9, lsl #1
 *   @0x20e0f0 mov r3, #0
 *   @0x20e0f4 mov r0, r5
 *   @0x20e0f8 strb r3, [r11]
 *   @0x20e0fc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20e100 ldr r2, [sp, #0x8]
 *   @0x20e104 mov r1, r6
 *   @0x20e108 mov r3, #1
 *   @0x20e10c mov r0, #16
 *   @0x20e110 ldr r5, [r2]
 *   @0x20e114 movw r2, #0x132
 *   @0x20e118 ldm r5, {r9, r10}
 *   @0x20e11c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20e120 and r10, r8, r10
 *   @0x20e124 ldr r2, [r9, r10, lsl #3]
 *   @0x20e128 add r3, r9, r10, lsl #3
 *   @0x20e12c cmp r2, #0
 *   @0x20e130 ldrne r2, [r3, #0x4]
 *   @0x20e134 movne r1, #0
 *   @0x20e138 str r8, [r0, #0x8]
 *   @0x20e13c str r4, [r0, #0xc]
 *   @0x20e140 strne r2, [r0]
 *   @0x20e144 streq r0, [r3, #0x4]
 *   @0x20e148 strne r0, [r2, #0x4]
 *   @0x20e14c strne r0, [r3, #0x4]
 *   @0x20e150 ldr r3, [r5, #0x8]
 *   @0x20e154 streq r0, [r9, r10, lsl #3]
 *   @0x20e158 strne r1, [r0, #0x4]
 *   @0x20e15c add r3, r3, #1
 *   @0x20e160 streq r2, [r0, #0x4]
 *   @0x20e164 streq r2, [r0]
 *   @0x20e168 str r3, [r5, #0x8]
 *   @0x20e16c ldrb r3, [r7]
 *   @0x20e170 cmp r3, #0
 *   @0x20e174 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380>
 *   @0x20e178 ldrb r3, [r7, #0x1]
 *   @0x20e17c add r7, r7, #1
 *   @0x20e180 cmp r3, #0
 *   @0x20e184 bne 0x20dee0 <_ZN7CDS_Map14ReadFromStringEPKcb+0xd8>
 *   @0x20e188 mov r0, #1
 *   @0x20e18c add sp, sp, #68
 *   @0x20e190 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20e194 str r9, [sp, #0x34]
 *   @0x20e198 str r9, [sp, #0x30]
 *   @0x20e19c ldrb r3, [r10, #0x1]
 *   @0x20e1a0 cmp r3, #44
 *   @0x20e1a4 cmpne r3, #0
 *   @0x20e1a8 beq 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c>
 *   @0x20e1ac cmp r3, #58
 *   @0x20e1b0 addne r12, sp, #56
 *   @0x20e1b4 movne r2, r7
 *   @0x20e1b8 bne 0x20e1c8 <_ZN7CDS_Map14ReadFromStringEPKcb+0x3c0>
 *   @0x20e1bc b 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c>
 *   @0x20e1c0 cmp r3, #58
 *   @0x20e1c4 beq 0x20e214 <_ZN7CDS_Map14ReadFromStringEPKcb+0x40c>
 *   @0x20e1c8 sub r1, r3, #55
 *   @0x20e1cc cmp r3, #64
 *   @0x20e1d0 sub r0, r3, #48
 *   @0x20e1d4 ldrb r3, [r2, #0x1]
 *   @0x20e1d8 lsl r0, r0, #4
 *   @0x20e1dc sub r5, r3, #55
 *   @0x20e1e0 lslhi r0, r1, #4
 *   @0x20e1e4 sub lr, r3, #48
 *   @0x20e1e8 cmp r3, #64
 *   @0x20e1ec orr r3, r0, lr
 *   @0x20e1f0 orrhi r3, r0, r5
 *   @0x20e1f4 strb r3, [r12, #-0x1]!
 *   @0x20e1f8 ldrb r3, [r2, #0x2]
 *   @0x20e1fc add r1, r2, #2
 *   @0x20e200 cmp r3, #0
 *   @0x20e204 cmpne r3, #44
 *   @0x20e208 mov r7, r1
 *   @0x20e20c mov r2, r1
 *   @0x20e210 bne 0x20e1c0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x3b8>
 *   @0x20e214 ldr r2, [sp, #0x30]
 *   @0x20e218 ldr r3, [sp, #0x34]
 *   @0x20e21c str r2, [r4, #0x10]
 *   @0x20e220 str r3, [r4, #0x14]
 *   @0x20e224 b 0x20e100 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2f8>
 *   @0x20e228 str r2, [sp, #0x34]
 *   @0x20e22c str r2, [sp, #0x30]
 *   @0x20e230 ldrb r3, [r7, #0x2]
 *   @0x20e234 cmp r3, #44
 *   @0x20e238 cmpne r3, #0
 *   @0x20e23c beq 0x20e2fc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4f4>
 *   @0x20e240 cmp r3, #58
 *   @0x20e244 addne r0, sp, #56
 *   @0x20e248 bne 0x20e258 <_ZN7CDS_Map14ReadFromStringEPKcb+0x450>
 *   @0x20e24c b 0x20e2fc <_ZN7CDS_Map14ReadFromStringEPKcb+0x4f4>
 *   @0x20e250 cmp r3, #58
 *   @0x20e254 beq 0x20e2a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x49c>
 *   @0x20e258 sub r2, r3, #55
 *   @0x20e25c cmp r3, #64
 *   @0x20e260 sub r1, r3, #48
 *   @0x20e264 ldrb r3, [r8, #0x1]
 *   @0x20e268 lsl r1, r1, #4
 *   @0x20e26c sub lr, r3, #55
 *   @0x20e270 lslhi r1, r2, #4
 *   @0x20e274 sub r12, r3, #48
 *   @0x20e278 cmp r3, #64
 *   @0x20e27c orr r3, r1, r12
 *   @0x20e280 orrhi r3, r1, lr
 *   @0x20e284 strb r3, [r0, #-0x1]!
 *   @0x20e288 ldrb r3, [r8, #0x2]
 *   @0x20e28c add r2, r8, #2
 *   @0x20e290 cmp r3, #0
 *   @0x20e294 cmpne r3, #44
 *   @0x20e298 mov r10, r2
 *   @0x20e29c mov r8, r2
 *   @0x20e2a0 bne 0x20e250 <_ZN7CDS_Map14ReadFromStringEPKcb+0x448>
 *   @0x20e2a4 ldr r2, [sp, #0x30]
 *   @0x20e2a8 mov r0, r4
 *   @0x20e2ac ldr r3, [sp, #0x34]
 *   @0x20e2b0 mov r1, #8
 *   @0x20e2b4 add r7, r10, #1
 *   @0x20e2b8 str r2, [r4]
 *   @0x20e2bc str r3, [r4, #0x4]
 *   @0x20e2c0 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20e2c4 mov r8, r0
 *   @0x20e2c8 b 0x20e02c <_ZN7CDS_Map14ReadFromStringEPKcb+0x224>
 *   @0x20e2cc ldr r0, [r4]
 *   @0x20e2d0 cmp r0, r8
 *   @0x20e2d4 ldrne r0, [r0]
 *   @0x20e2d8 b 0x20e024 <_ZN7CDS_Map14ReadFromStringEPKcb+0x21c>
 *   @0x20e2dc mov r0, #1
 *   @0x20e2e0 ldr r1, [sp, #0x14]
 *   @0x20e2e4 mov r3, r0
 *   @0x20e2e8 movw r2, #0x76a
 *   @0x20e2ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20e2f0 mov r10, r8
 *   @0x20e2f4 mov r1, r0
 *   @0x20e2f8 b 0x20e000 <_ZN7CDS_Map14ReadFromStringEPKcb+0x1f8>
 *   @0x20e2fc mov r10, r8
 *   @0x20e300 b 0x20e2a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x49c>
 *   @0x20e304 mov r0, #1
 *   @0x20e308 ldr r1, [sp, #0x18]
 *   @0x20e30c mov r3, r0
 *   @0x20e310 movw r2, #0x76a
 *   @0x20e314 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20e318 mov r11, r0
 *   @0x20e31c mov r1, r0
 *   @0x20e320 b 0x20e0f0 <_ZN7CDS_Map14ReadFromStringEPKcb+0x2e8>
 *   @0x20e324 mov r0, r5
 *   @0x20e328 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20e32c subs r10, r0, #0
 *   @0x20e330 ble 0x20e434 <_ZN7CDS_Map14ReadFromStringEPKcb+0x62c>
 *   @0x20e334 add r8, sp, #32
 *   @0x20e338 add r3, sp, #48
 *   @0x20e33c mov r11, #0
 *   @0x20e340 add r1, sp, #36
 *   @0x20e344 add r2, sp, #40
 *   @0x20e348 str r1, [sp, #0xc]
 *   @0x20e34c str r2, [sp, #0x10]
 *   @0x20e350 add r1, sp, #44
 *   @0x20e354 add r2, sp, #52
 *   @0x20e358 str r1, [sp, #0x14]
 *   @0x20e35c add r9, sp, #56
 *   @0x20e360 add r1, sp, #60
 *   @0x20e364 str r2, [sp, #0x18]
 *   @0x20e368 mov r7, r8
 *   @0x20e36c str r1, [sp, #0x1c]
 *   @0x20e370 mov r6, r3
 *   @0x20e374 mov r4, r11
 *   @0x20e378 b 0x20e3ac <_ZN7CDS_Map14ReadFromStringEPKcb+0x5a4>
 *   @0x20e37c ldr r2, [sp, #0x3c]
 *   @0x20e380 mov r1, #5
 *   @0x20e384 str r4, [sp, #0x28]
 *   @0x20e388 sub r2, r2, #1
 *   @0x20e38c str r1, [sp, #0x2c]
 *   @0x20e390 bic r2, r2, #-16777216
 *   @0x20e394 str r4, [sp, #0x20]
 *   @0x20e398 bic r2, r2, #3
 *   @0x20e39c cmp r2, #0
 *   @0x20e3a0 beq 0x20e450 <_ZN7CDS_Map14ReadFromStringEPKcb+0x648>
 *   @0x20e3a4 cmp r11, r10
 *   @0x20e3a8 beq 0x20e434 <_ZN7CDS_Map14ReadFromStringEPKcb+0x62c>
 *   @0x20e3ac mov r0, r7
 *   @0x20e3b0 mov r1, r5
 *   @0x20e3b4 mov r2, #0
 *   @0x20e3b8 str r4, [r3]
 *   @0x20e3bc str r4, [r8]
 *   @0x20e3c0 add r11, r11, #1
 *   @0x20e3c4 str r4, [sp, #0x24]
 *   @0x20e3c8 mov r8, r7
 *   @0x20e3cc str r4, [sp, #0x28]
 *   @0x20e3d0 str r4, [sp, #0x2c]
 *   @0x20e3d4 str r4, [sp, #0x34]
 *   @0x20e3d8 str r4, [r9]
 *   @0x20e3dc str r4, [sp, #0x3c]
 *   @0x20e3e0 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20e3e4 mov r0, r6
 *   @0x20e3e8 mov r1, r5
 *   @0x20e3ec mov r2, #0
 *   @0x20e3f0 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20e3f4 mov r2, r6
 *   @0x20e3f8 ldr r0, [sp, #0x8]
 *   @0x20e3fc mov r1, r7
 *   @0x20e400 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20e404 ldr r2, [sp, #0x2c]
 *   @0x20e408 mov r3, r6
 *   @0x20e40c sub r2, r2, #1
 *   @0x20e410 bic r2, r2, #-16777216
 *   @0x20e414 bic r2, r2, #3
 *   @0x20e418 cmp r2, #0
 *   @0x20e41c bne 0x20e37c <_ZN7CDS_Map14ReadFromStringEPKcb+0x574>
 *   @0x20e420 mov r0, r7
 *   @0x20e424 str r6, [sp, #0x4]
 *   @0x20e428 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20e42c ldr r3, [sp, #0x4]
 *   @0x20e430 b 0x20e37c <_ZN7CDS_Map14ReadFromStringEPKcb+0x574>
 *   @0x20e434 cmp r5, #0
 *   @0x20e438 beq 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380>
 *   @0x20e43c mov r0, r5
 *   @0x20e440 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20e444 mov r0, r5
 *   @0x20e448 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e44c b 0x20e188 <_ZN7CDS_Map14ReadFromStringEPKcb+0x380>
 *   @0x20e450 mov r0, r6
 *   @0x20e454 str r3, [sp, #0x4]
 *   @0x20e458 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20e45c ldr r3, [sp, #0x4]
 *   @0x20e460 b 0x20e3a4 <_ZN7CDS_Map14ReadFromStringEPKcb+0x59c>
 *   @0x20e464 andseq r5, r4, r12, lsr r9
 *   @0x20e468 ldrsheq lr, [r3], -r0
 *   @0x20e46c andseq r5, r4, r8, lsr #18
 *   @0x20e470 andseq r5, r4, r0, lsr #18
 *   @0x20e474 andseq r5, r4, r8, lsl r9
 *
 * ══ §10/20 CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*)  0x1c3eb4  size 1640  410 条（0x1c3eb4..0x1c451c）
 * @func 0x1c3eb4 0x1c451c  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*)+0x70 / CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*)+0x1d0 / CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*)+0x340 / CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c3eb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1c3eb8 vpush {d8}
 *   @0x1c3ebc sub sp, sp, #60
 *   @0x1c3ec0 ldr r3, [r0, #0x4]
 *   @0x1c3ec4 mov r11, r0
 *   @0x1c3ec8 str r2, [sp, #0x24]
 *   @0x1c3ecc ldr r2, [r0, #0xc]
 *   @0x1c3ed0 str r1, [sp, #0x1c]
 *   @0x1c3ed4 cmp r3, r2
 *   @0x1c3ed8 bgt 0x1c3fe8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x134>
 *   @0x1c3edc add r3, r3, #1
 *   @0x1c3ee0 ldr r0, [sp, #0x1c]
 *   @0x1c3ee4 str r3, [r11, #0x4]
 *   @0x1c3ee8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c3eec ldr r4, [r11, #0x8]
 *   @0x1c3ef0 ldr r6, [r11, #0x10]
 *   @0x1c3ef4 bic r0, r0, #-2147483648
 *   @0x1c3ef8 and r3, r0, r4
 *   @0x1c3efc add r2, r3, r3, lsl #1
 *   @0x1c3f00 add r2, r6, r2, lsl #2
 *   @0x1c3f04 ldr r12, [r2, #0x8]
 *   @0x1c3f08 cmp r12, #0
 *   @0x1c3f0c beq 0x1c3fc8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x114>
 *   @0x1c3f10 ldr r7, [r11]
 *   @0x1c3f14 mov r1, #0
 *   @0x1c3f18 ldr r8, [sp, #0x1c]
 *   @0x1c3f1c ldr r9, [sp, #0x24]
 *   @0x1c3f20 b 0x1c3f68 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0xb4>
 *   @0x1c3f24 ldr r10, [r2]
 *   @0x1c3f28 mov r1, r5
 *   @0x1c3f2c ldr r5, [r2, #0x4]
 *   @0x1c3f30 str r0, [r2, #0x8]
 *   @0x1c3f34 mov r0, r12
 *   @0x1c3f38 str r8, [r2]
 *   @0x1c3f3c mov r8, r10
 *   @0x1c3f40 str r9, [r2, #0x4]
 *   @0x1c3f44 mov r9, r5
 *   @0x1c3f48 add r3, r3, #1
 *   @0x1c3f4c add r1, r1, #1
 *   @0x1c3f50 and r3, r3, r4
 *   @0x1c3f54 add r2, r3, r3, lsl #1
 *   @0x1c3f58 add r2, r6, r2, lsl #2
 *   @0x1c3f5c ldr r12, [r2, #0x8]
 *   @0x1c3f60 cmp r12, #0
 *   @0x1c3f64 beq 0x1c3fc0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x10c>
 *   @0x1c3f68 add r5, r7, r3
 *   @0x1c3f6c and r10, r12, r4
 *   @0x1c3f70 rsb r5, r10, r5
 *   @0x1c3f74 and r5, r5, r4
 *   @0x1c3f78 cmp r5, r1
 *   @0x1c3f7c blt 0x1c3f24 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x70>
 *   @0x1c3f80 cmp r1, r5
 *   @0x1c3f84 bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94>
 *   @0x1c3f88 cmp r0, r12
 *   @0x1c3f8c bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94>
 *   @0x1c3f90 ldr r12, [r2]
 *   @0x1c3f94 cmp r8, r12
 *   @0x1c3f98 bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94>
 *   @0x1c3f9c ldr r3, [r11, #0x4]
 *   @0x1c3fa0 str r8, [sp, #0x1c]
 *   @0x1c3fa4 str r8, [r2]
 *   @0x1c3fa8 sub r3, r3, #1
 *   @0x1c3fac str r9, [r2, #0x4]
 *   @0x1c3fb0 str r0, [r2, #0x8]
 *   @0x1c3fb4 str r9, [sp, #0x24]
 *   @0x1c3fb8 str r3, [r11, #0x4]
 *   @0x1c3fbc b 0x1c3fdc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x128>
 *   @0x1c3fc0 str r8, [sp, #0x1c]
 *   @0x1c3fc4 str r9, [sp, #0x24]
 *   @0x1c3fc8 ldr r12, [sp, #0x1c]
 *   @0x1c3fcc str r0, [r2, #0x8]
 *   @0x1c3fd0 str r12, [r2]
 *   @0x1c3fd4 ldr r12, [sp, #0x24]
 *   @0x1c3fd8 str r12, [r2, #0x4]
 *   @0x1c3fdc add sp, sp, #60
 *   @0x1c3fe0 vpop {d8}
 *   @0x1c3fe4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1c3fe8 ldr r12, [r0]
 *   @0x1c3fec mov r3, #1
 *   @0x1c3ff0 ldr r1, [pc, #0x430]
 *   @0x1c3ff4 mov r2, #70
 *   @0x1c3ff8 str r12, [sp, #0x20]
 *   @0x1c3ffc add r1, pc, r1
 *   @0x1c4000 ldr r12, [r0, #0x10]
 *   @0x1c4004 str r12, [sp, #0x30]
 *   @0x1c4008 ldr r12, [sp, #0x20]
 *   @0x1c400c lsl r0, r12, r3
 *   @0x1c4010 str r0, [r11]
 *   @0x1c4014 add r4, r0, r12, lsl #2
 *   @0x1c4018 sub r0, r0, #1
 *   @0x1c401c str r0, [r11, #0x8]
 *   @0x1c4020 lsl r4, r4, #2
 *   @0x1c4024 mov r0, r4
 *   @0x1c4028 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c402c mov r2, r4
 *   @0x1c4030 mov r1, #0
 *   @0x1c4034 str r0, [r11, #0x10]
 *   @0x1c4038 bl 0xb65b0 <memset@plt>
 *   @0x1c403c ldr r2, [r11]
 *   @0x1c4040 vldr s15, [pc, #988]
 *   @0x1c4044 mov r1, #0
 *   @0x1c4048 cmp r2, r1
 *   @0x1c404c str r1, [r11, #0x4]
 *   @0x1c4050 vmov s13, r2
 *   @0x1c4054 vcvt.f32.s32 s14, s13
 *   @0x1c4058 vmul.f32 s15, s14, s15
 *   @0x1c405c vcvt.s32.f32 s15, s15
 *   @0x1c4060 vstr s15, [r11, #12]
 *   @0x1c4064 ble 0x1c4084 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x1d0>
 *   @0x1c4068 add r2, r2, r2, lsl #1
 *   @0x1c406c ldr r3, [r11, #0x10]
 *   @0x1c4070 add r2, r3, r2, lsl #2
 *   @0x1c4074 str r1, [r3, #0x8]
 *   @0x1c4078 add r3, r3, #12
 *   @0x1c407c cmp r3, r2
 *   @0x1c4080 bne 0x1c4074 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x1c0>
 *   @0x1c4084 ldr r12, [sp, #0x20]
 *   @0x1c4088 cmp r12, #0
 *   @0x1c408c ble 0x1c41f4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x340>
 *   @0x1c4090 ldr r12, [pc, #0x394]
 *   @0x1c4094 vldr s16, [pc, #904]
 *   @0x1c4098 add r12, pc, r12
 *   @0x1c409c str r12, [sp, #0x34]
 *   @0x1c40a0 mov r12, #0
 *   @0x1c40a4 str r12, [sp, #0xc]
 *   @0x1c40a8 ldr r12, [pc, #0x380]
 *   @0x1c40ac add r12, pc, r12
 *   @0x1c40b0 str r12, [sp, #0x2c]
 *   @0x1c40b4 ldr r12, [sp, #0x30]
 *   @0x1c40b8 str r12, [sp, #0x8]
 *   @0x1c40bc ldr r12, [sp, #0x8]
 *   @0x1c40c0 ldr r3, [r12, #0x8]
 *   @0x1c40c4 cmp r3, #0
 *   @0x1c40c8 ble 0x1c41cc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x318>
 *   @0x1c40cc ldr r12, [r12]
 *   @0x1c40d0 ldr r3, [r11, #0x4]
 *   @0x1c40d4 ldr r2, [r11, #0xc]
 *   @0x1c40d8 str r12, [sp, #0x10]
 *   @0x1c40dc ldr r12, [sp, #0x8]
 *   @0x1c40e0 cmp r3, r2
 *   @0x1c40e4 ldr r12, [r12, #0x4]
 *   @0x1c40e8 str r12, [sp, #0x18]
 *   @0x1c40ec bgt 0x1c423c <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x388>
 *   @0x1c40f0 add r3, r3, #1
 *   @0x1c40f4 ldr r0, [sp, #0x10]
 *   @0x1c40f8 str r3, [r11, #0x4]
 *   @0x1c40fc bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c4100 ldr lr, [r11, #0x8]
 *   @0x1c4104 ldr r6, [r11, #0x10]
 *   @0x1c4108 bic r0, r0, #-2147483648
 *   @0x1c410c and r3, r0, lr
 *   @0x1c4110 add r2, r3, r3, lsl #1
 *   @0x1c4114 add r2, r6, r2, lsl #2
 *   @0x1c4118 ldr r1, [r2, #0x8]
 *   @0x1c411c cmp r1, #0
 *   @0x1c4120 beq 0x1c4224 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x370>
 *   @0x1c4124 ldr r7, [r11]
 *   @0x1c4128 mov r4, #0
 *   @0x1c412c ldr r8, [sp, #0x10]
 *   @0x1c4130 ldr r9, [sp, #0x18]
 *   @0x1c4134 b 0x1c4178 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2c4>
 *   @0x1c4138 ldr r5, [r2]
 *   @0x1c413c ldr r4, [r2, #0x4]
 *   @0x1c4140 str r0, [r2, #0x8]
 *   @0x1c4144 mov r0, r1
 *   @0x1c4148 str r8, [r2]
 *   @0x1c414c mov r8, r5
 *   @0x1c4150 str r9, [r2, #0x4]
 *   @0x1c4154 mov r9, r4
 *   @0x1c4158 add r3, r3, #1
 *   @0x1c415c add r4, r12, #1
 *   @0x1c4160 and r3, r3, lr
 *   @0x1c4164 add r2, r3, r3, lsl #1
 *   @0x1c4168 add r2, r6, r2, lsl #2
 *   @0x1c416c ldr r1, [r2, #0x8]
 *   @0x1c4170 cmp r1, #0
 *   @0x1c4174 beq 0x1c421c <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x368>
 *   @0x1c4178 add r12, r7, r3
 *   @0x1c417c and r5, r1, lr
 *   @0x1c4180 rsb r12, r5, r12
 *   @0x1c4184 and r12, r12, lr
 *   @0x1c4188 cmp r12, r4
 *   @0x1c418c blt 0x1c4138 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x284>
 *   @0x1c4190 movne r12, r4
 *   @0x1c4194 bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c4198 cmp r1, r0
 *   @0x1c419c bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c41a0 ldr r4, [r2]
 *   @0x1c41a4 cmp r8, r4
 *   @0x1c41a8 bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c41ac ldr r3, [r11, #0x4]
 *   @0x1c41b0 str r8, [sp, #0x10]
 *   @0x1c41b4 str r8, [r2]
 *   @0x1c41b8 sub r3, r3, #1
 *   @0x1c41bc str r9, [r2, #0x4]
 *   @0x1c41c0 str r1, [r2, #0x8]
 *   @0x1c41c4 str r9, [sp, #0x18]
 *   @0x1c41c8 str r3, [r11, #0x4]
 *   @0x1c41cc ldr r12, [sp, #0xc]
 *   @0x1c41d0 ldr r0, [sp, #0x20]
 *   @0x1c41d4 add r12, r12, #1
 *   @0x1c41d8 str r12, [sp, #0xc]
 *   @0x1c41dc ldr r12, [sp, #0x8]
 *   @0x1c41e0 add r12, r12, #12
 *   @0x1c41e4 str r12, [sp, #0x8]
 *   @0x1c41e8 ldr r12, [sp, #0xc]
 *   @0x1c41ec cmp r12, r0
 *   @0x1c41f0 bne 0x1c40bc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x208>
 *   @0x1c41f4 ldr r0, [sp, #0x30]
 *   @0x1c41f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c41fc vldr s13, [r11]
 *   @0x1c4200 vcvt.f32.s32 s14, s13
 *   @0x1c4204 vldr s15, [pc, #536]
 *   @0x1c4208 ldr r3, [r11, #0x4]
 *   @0x1c420c vmul.f32 s15, s14, s15
 *   @0x1c4210 vcvt.s32.f32 s15, s15
 *   @0x1c4214 vstr s15, [r11, #12]
 *   @0x1c4218 b 0x1c3edc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x28>
 *   @0x1c421c str r8, [sp, #0x10]
 *   @0x1c4220 str r9, [sp, #0x18]
 *   @0x1c4224 ldr r12, [sp, #0x10]
 *   @0x1c4228 str r0, [r2, #0x8]
 *   @0x1c422c str r12, [r2]
 *   @0x1c4230 ldr r12, [sp, #0x18]
 *   @0x1c4234 str r12, [r2, #0x4]
 *   @0x1c4238 b 0x1c41cc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x318>
 *   @0x1c423c ldr r12, [r11]
 *   @0x1c4240 mov r3, #1
 *   @0x1c4244 ldr r1, [sp, #0x34]
 *   @0x1c4248 mov r2, #70
 *   @0x1c424c str r12, [sp, #0x14]
 *   @0x1c4250 ldr r12, [r11, #0x10]
 *   @0x1c4254 str r12, [sp, #0x28]
 *   @0x1c4258 ldr r12, [sp, #0x14]
 *   @0x1c425c lsl r0, r12, r3
 *   @0x1c4260 str r0, [r11]
 *   @0x1c4264 add r4, r0, r12, lsl #2
 *   @0x1c4268 sub r0, r0, #1
 *   @0x1c426c str r0, [r11, #0x8]
 *   @0x1c4270 lsl r4, r4, #2
 *   @0x1c4274 mov r0, r4
 *   @0x1c4278 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c427c mov r2, r4
 *   @0x1c4280 mov r1, #0
 *   @0x1c4284 str r0, [r11, #0x10]
 *   @0x1c4288 bl 0xb65b0 <memset@plt>
 *   @0x1c428c ldr r2, [r11]
 *   @0x1c4290 mov r0, #0
 *   @0x1c4294 str r0, [r11, #0x4]
 *   @0x1c4298 cmp r2, r0
 *   @0x1c429c vmov s13, r2
 *   @0x1c42a0 vcvt.f32.s32 s15, s13
 *   @0x1c42a4 vmul.f32 s15, s15, s16
 *   @0x1c42a8 vcvt.s32.f32 s15, s15
 *   @0x1c42ac vstr s15, [r11, #12]
 *   @0x1c42b0 ble 0x1c42d4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x420>
 *   @0x1c42b4 add r2, r2, r2, lsl #1
 *   @0x1c42b8 ldr r3, [r11, #0x10]
 *   @0x1c42bc add r2, r3, r2, lsl #2
 *   @0x1c42c0 mov r0, #0
 *   @0x1c42c4 add r3, r3, #12
 *   @0x1c42c8 str r0, [r3, #-0x4]
 *   @0x1c42cc cmp r3, r2
 *   @0x1c42d0 bne 0x1c42c0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x40c>
 *   @0x1c42d4 ldr r12, [sp, #0x14]
 *   @0x1c42d8 cmp r12, #0
 *   @0x1c42dc ble 0x1c43f4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x540>
 *   @0x1c42e0 ldr r6, [sp, #0x28]
 *   @0x1c42e4 mov r12, #0
 *   @0x1c42e8 str r12, [sp, #0x4]
 *   @0x1c42ec ldr r3, [r6, #0x8]
 *   @0x1c42f0 cmp r3, #0
 *   @0x1c42f4 ble 0x1c43d8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x524>
 *   @0x1c42f8 ldr r3, [r11, #0x4]
 *   @0x1c42fc ldr r2, [r11, #0xc]
 *   @0x1c4300 ldr r4, [r6]
 *   @0x1c4304 cmp r3, r2
 *   @0x1c4308 ldr r5, [r6, #0x4]
 *   @0x1c430c bgt 0x1c4434 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x580>
 *   @0x1c4310 add r3, r3, #1
 *   @0x1c4314 mov r0, r4
 *   @0x1c4318 str r3, [r11, #0x4]
 *   @0x1c431c bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c4320 ldr lr, [r11, #0x8]
 *   @0x1c4324 ldr r9, [r11, #0x10]
 *   @0x1c4328 bic r0, r0, #-2147483648
 *   @0x1c432c and r3, r0, lr
 *   @0x1c4330 add r2, r3, r3, lsl #1
 *   @0x1c4334 add r2, r9, r2, lsl #2
 *   @0x1c4338 ldr r1, [r2, #0x8]
 *   @0x1c433c cmp r1, #0
 *   @0x1c4340 ldrne r10, [r11]
 *   @0x1c4344 movne r7, #0
 *   @0x1c4348 bne 0x1c4390 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4dc>
 *   @0x1c434c b 0x1c4418 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x564>
 *   @0x1c4350 ldr r8, [r2]
 *   @0x1c4354 ldr r7, [r2, #0x4]
 *   @0x1c4358 str r0, [r2, #0x8]
 *   @0x1c435c mov r0, r1
 *   @0x1c4360 str r4, [r2]
 *   @0x1c4364 mov r4, r8
 *   @0x1c4368 str r5, [r2, #0x4]
 *   @0x1c436c mov r5, r7
 *   @0x1c4370 add r3, r3, #1
 *   @0x1c4374 add r7, r12, #1
 *   @0x1c4378 and r3, r3, lr
 *   @0x1c437c add r2, r3, r3, lsl #1
 *   @0x1c4380 add r2, r9, r2, lsl #2
 *   @0x1c4384 ldr r1, [r2, #0x8]
 *   @0x1c4388 cmp r1, #0
 *   @0x1c438c beq 0x1c4418 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x564>
 *   @0x1c4390 add r12, r3, r10
 *   @0x1c4394 and r8, r1, lr
 *   @0x1c4398 rsb r12, r8, r12
 *   @0x1c439c and r12, r12, lr
 *   @0x1c43a0 cmp r12, r7
 *   @0x1c43a4 blt 0x1c4350 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x49c>
 *   @0x1c43a8 movne r12, r7
 *   @0x1c43ac bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c43b0 cmp r1, r0
 *   @0x1c43b4 bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c43b8 ldr r7, [r2]
 *   @0x1c43bc cmp r4, r7
 *   @0x1c43c0 bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c43c4 ldr r3, [r11, #0x4]
 *   @0x1c43c8 stm r2, {r4, r5}
 *   @0x1c43cc sub r3, r3, #1
 *   @0x1c43d0 str r1, [r2, #0x8]
 *   @0x1c43d4 str r3, [r11, #0x4]
 *   @0x1c43d8 ldr r12, [sp, #0x4]
 *   @0x1c43dc add r6, r6, #12
 *   @0x1c43e0 ldr r0, [sp, #0x14]
 *   @0x1c43e4 add r12, r12, #1
 *   @0x1c43e8 str r12, [sp, #0x4]
 *   @0x1c43ec cmp r12, r0
 *   @0x1c43f0 bne 0x1c42ec <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x438>
 *   @0x1c43f4 ldr r0, [sp, #0x28]
 *   @0x1c43f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c43fc vldr s13, [r11]
 *   @0x1c4400 vcvt.f32.s32 s15, s13
 *   @0x1c4404 ldr r3, [r11, #0x4]
 *   @0x1c4408 vmul.f32 s15, s15, s16
 *   @0x1c440c vcvt.s32.f32 s15, s15
 *   @0x1c4410 vstr s15, [r11, #12]
 *   @0x1c4414 b 0x1c40f0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x23c>
 *   @0x1c4418 stm r2, {r4, r5}
 *   @0x1c441c str r0, [r2, #0x8]
 *   @0x1c4420 b 0x1c43d8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x524>
 *   @0x1c4424 svclo #0x19999a
 *   @0x1c4428 andseq sp, r6, r4, lsr r0
 *   @0x1c442c mulseq r6, r8, pc
 *   @0x1c4430 andseq r12, r6, r4, lsl #31
 *   @0x1c4434 ldr r8, [r11]
 *   @0x1c4438 mov r3, #1
 *   @0x1c443c ldr r1, [sp, #0x2c]
 *   @0x1c4440 mov r2, #70
 *   @0x1c4444 ldr r7, [r11, #0x10]
 *   @0x1c4448 lsl r0, r8, r3
 *   @0x1c444c str r0, [r11]
 *   @0x1c4450 add r9, r0, r8, lsl #2
 *   @0x1c4454 sub r0, r0, #1
 *   @0x1c4458 str r0, [r11, #0x8]
 *   @0x1c445c lsl r9, r9, #2
 *   @0x1c4460 mov r0, r9
 *   @0x1c4464 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c4468 mov r2, r9
 *   @0x1c446c mov r1, #0
 *   @0x1c4470 str r0, [r11, #0x10]
 *   @0x1c4474 bl 0xb65b0 <memset@plt>
 *   @0x1c4478 ldr r2, [r11]
 *   @0x1c447c mov r0, #0
 *   @0x1c4480 str r0, [r11, #0x4]
 *   @0x1c4484 cmp r2, r0
 *   @0x1c4488 vmov s13, r2
 *   @0x1c448c vcvt.f32.s32 s15, s13
 *   @0x1c4490 vmul.f32 s15, s15, s16
 *   @0x1c4494 vcvt.s32.f32 s15, s15
 *   @0x1c4498 vstr s15, [r11, #12]
 *   @0x1c449c ble 0x1c44c0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x60c>
 *   @0x1c44a0 add r2, r2, r2, lsl #1
 *   @0x1c44a4 ldr r3, [r11, #0x10]
 *   @0x1c44a8 add r2, r3, r2, lsl #2
 *   @0x1c44ac mov r0, #0
 *   @0x1c44b0 add r3, r3, #12
 *   @0x1c44b4 str r0, [r3, #-0x4]
 *   @0x1c44b8 cmp r3, r2
 *   @0x1c44bc bne 0x1c44ac <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x5f8>
 *   @0x1c44c0 cmp r8, #0
 *   @0x1c44c4 movgt r9, r7
 *   @0x1c44c8 movgt r10, #0
 *   @0x1c44cc ble 0x1c44f8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x644>
 *   @0x1c44d0 ldr r3, [r9, #0x8]
 *   @0x1c44d4 mov r0, r11
 *   @0x1c44d8 add r10, r10, #1
 *   @0x1c44dc cmp r3, #0
 *   @0x1c44e0 ble 0x1c44ec <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x638>
 *   @0x1c44e4 ldm r9, {r1, r2}
 *   @0x1c44e8 bl 0x1c3eb4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_>
 *   @0x1c44ec cmp r10, r8
 *   @0x1c44f0 add r9, r9, #12
 *   @0x1c44f4 bne 0x1c44d0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x61c>
 *   @0x1c44f8 mov r0, r7
 *   @0x1c44fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c4500 vldr s13, [r11]
 *   @0x1c4504 vcvt.f32.s32 s15, s13
 *   @0x1c4508 ldr r3, [r11, #0x4]
 *   @0x1c450c vmul.f32 s15, s15, s16
 *   @0x1c4510 vcvt.s32.f32 s15, s15
 *   @0x1c4514 vstr s15, [r11, #12]
 *   @0x1c4518 b 0x1c4310 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x45c>
 *
 * ══ §11/20 CHashMap<char const*, int, 3>::Insert(char const*, int)  0x27d260  size 1640  410 条（0x27d260..0x27d8c8）
 * @func 0x27d260 0x27d8c8  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<char const*, int, 3>::Insert(char const*, int)+0x70 / CHashMap<char const*, int, 3>::Insert(char const*, int)+0x1d0 / CHashMap<char const*, int, 3>::Insert(char const*, int)+0x340 / CHashMap<char const*, int, 3>::Insert(char const*, int)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d260 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27d264 vpush {d8}
 *   @0x27d268 sub sp, sp, #60
 *   @0x27d26c ldr r3, [r0, #0x4]
 *   @0x27d270 mov r11, r0
 *   @0x27d274 str r2, [sp, #0x24]
 *   @0x27d278 ldr r2, [r0, #0xc]
 *   @0x27d27c str r1, [sp, #0x1c]
 *   @0x27d280 cmp r3, r2
 *   @0x27d284 bgt 0x27d394 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x134>
 *   @0x27d288 add r3, r3, #1
 *   @0x27d28c ldr r0, [sp, #0x1c]
 *   @0x27d290 str r3, [r11, #0x4]
 *   @0x27d294 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x27d298 ldr r4, [r11, #0x8]
 *   @0x27d29c ldr r6, [r11, #0x10]
 *   @0x27d2a0 bic r0, r0, #-2147483648
 *   @0x27d2a4 and r3, r0, r4
 *   @0x27d2a8 add r2, r3, r3, lsl #1
 *   @0x27d2ac add r2, r6, r2, lsl #2
 *   @0x27d2b0 ldr r12, [r2, #0x8]
 *   @0x27d2b4 cmp r12, #0
 *   @0x27d2b8 beq 0x27d374 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x114>
 *   @0x27d2bc ldr r7, [r11]
 *   @0x27d2c0 mov r1, #0
 *   @0x27d2c4 ldr r8, [sp, #0x1c]
 *   @0x27d2c8 ldr r9, [sp, #0x24]
 *   @0x27d2cc b 0x27d314 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0xb4>
 *   @0x27d2d0 ldr r10, [r2]
 *   @0x27d2d4 mov r1, r5
 *   @0x27d2d8 ldr r5, [r2, #0x4]
 *   @0x27d2dc str r0, [r2, #0x8]
 *   @0x27d2e0 mov r0, r12
 *   @0x27d2e4 str r8, [r2]
 *   @0x27d2e8 mov r8, r10
 *   @0x27d2ec str r9, [r2, #0x4]
 *   @0x27d2f0 mov r9, r5
 *   @0x27d2f4 add r3, r3, #1
 *   @0x27d2f8 add r1, r1, #1
 *   @0x27d2fc and r3, r3, r4
 *   @0x27d300 add r2, r3, r3, lsl #1
 *   @0x27d304 add r2, r6, r2, lsl #2
 *   @0x27d308 ldr r12, [r2, #0x8]
 *   @0x27d30c cmp r12, #0
 *   @0x27d310 beq 0x27d36c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x10c>
 *   @0x27d314 add r5, r7, r3
 *   @0x27d318 and r10, r12, r4
 *   @0x27d31c rsb r5, r10, r5
 *   @0x27d320 and r5, r5, r4
 *   @0x27d324 cmp r5, r1
 *   @0x27d328 blt 0x27d2d0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x70>
 *   @0x27d32c cmp r1, r5
 *   @0x27d330 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94>
 *   @0x27d334 cmp r0, r12
 *   @0x27d338 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94>
 *   @0x27d33c ldr r12, [r2]
 *   @0x27d340 cmp r8, r12
 *   @0x27d344 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94>
 *   @0x27d348 ldr r3, [r11, #0x4]
 *   @0x27d34c str r8, [sp, #0x1c]
 *   @0x27d350 str r8, [r2]
 *   @0x27d354 sub r3, r3, #1
 *   @0x27d358 str r9, [r2, #0x4]
 *   @0x27d35c str r0, [r2, #0x8]
 *   @0x27d360 str r9, [sp, #0x24]
 *   @0x27d364 str r3, [r11, #0x4]
 *   @0x27d368 b 0x27d388 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x128>
 *   @0x27d36c str r8, [sp, #0x1c]
 *   @0x27d370 str r9, [sp, #0x24]
 *   @0x27d374 ldr r12, [sp, #0x1c]
 *   @0x27d378 str r0, [r2, #0x8]
 *   @0x27d37c str r12, [r2]
 *   @0x27d380 ldr r12, [sp, #0x24]
 *   @0x27d384 str r12, [r2, #0x4]
 *   @0x27d388 add sp, sp, #60
 *   @0x27d38c vpop {d8}
 *   @0x27d390 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27d394 ldr r12, [r0]
 *   @0x27d398 mov r3, #1
 *   @0x27d39c ldr r1, [pc, #0x430]
 *   @0x27d3a0 mov r2, #70
 *   @0x27d3a4 str r12, [sp, #0x20]
 *   @0x27d3a8 add r1, pc, r1
 *   @0x27d3ac ldr r12, [r0, #0x10]
 *   @0x27d3b0 str r12, [sp, #0x30]
 *   @0x27d3b4 ldr r12, [sp, #0x20]
 *   @0x27d3b8 lsl r0, r12, r3
 *   @0x27d3bc str r0, [r11]
 *   @0x27d3c0 add r4, r0, r12, lsl #2
 *   @0x27d3c4 sub r0, r0, #1
 *   @0x27d3c8 str r0, [r11, #0x8]
 *   @0x27d3cc lsl r4, r4, #2
 *   @0x27d3d0 mov r0, r4
 *   @0x27d3d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d3d8 mov r2, r4
 *   @0x27d3dc mov r1, #0
 *   @0x27d3e0 str r0, [r11, #0x10]
 *   @0x27d3e4 bl 0xb65b0 <memset@plt>
 *   @0x27d3e8 ldr r2, [r11]
 *   @0x27d3ec vldr s15, [pc, #988]
 *   @0x27d3f0 mov r1, #0
 *   @0x27d3f4 cmp r2, r1
 *   @0x27d3f8 str r1, [r11, #0x4]
 *   @0x27d3fc vmov s13, r2
 *   @0x27d400 vcvt.f32.s32 s14, s13
 *   @0x27d404 vmul.f32 s15, s14, s15
 *   @0x27d408 vcvt.s32.f32 s15, s15
 *   @0x27d40c vstr s15, [r11, #12]
 *   @0x27d410 ble 0x27d430 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x1d0>
 *   @0x27d414 add r2, r2, r2, lsl #1
 *   @0x27d418 ldr r3, [r11, #0x10]
 *   @0x27d41c add r2, r3, r2, lsl #2
 *   @0x27d420 str r1, [r3, #0x8]
 *   @0x27d424 add r3, r3, #12
 *   @0x27d428 cmp r3, r2
 *   @0x27d42c bne 0x27d420 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x1c0>
 *   @0x27d430 ldr r12, [sp, #0x20]
 *   @0x27d434 cmp r12, #0
 *   @0x27d438 ble 0x27d5a0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x340>
 *   @0x27d43c ldr r12, [pc, #0x394]
 *   @0x27d440 vldr s16, [pc, #904]
 *   @0x27d444 add r12, pc, r12
 *   @0x27d448 str r12, [sp, #0x34]
 *   @0x27d44c mov r12, #0
 *   @0x27d450 str r12, [sp, #0xc]
 *   @0x27d454 ldr r12, [pc, #0x380]
 *   @0x27d458 add r12, pc, r12
 *   @0x27d45c str r12, [sp, #0x2c]
 *   @0x27d460 ldr r12, [sp, #0x30]
 *   @0x27d464 str r12, [sp, #0x8]
 *   @0x27d468 ldr r12, [sp, #0x8]
 *   @0x27d46c ldr r3, [r12, #0x8]
 *   @0x27d470 cmp r3, #0
 *   @0x27d474 ble 0x27d578 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x318>
 *   @0x27d478 ldr r12, [r12]
 *   @0x27d47c ldr r3, [r11, #0x4]
 *   @0x27d480 ldr r2, [r11, #0xc]
 *   @0x27d484 str r12, [sp, #0x10]
 *   @0x27d488 ldr r12, [sp, #0x8]
 *   @0x27d48c cmp r3, r2
 *   @0x27d490 ldr r12, [r12, #0x4]
 *   @0x27d494 str r12, [sp, #0x18]
 *   @0x27d498 bgt 0x27d5e8 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x388>
 *   @0x27d49c add r3, r3, #1
 *   @0x27d4a0 ldr r0, [sp, #0x10]
 *   @0x27d4a4 str r3, [r11, #0x4]
 *   @0x27d4a8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x27d4ac ldr lr, [r11, #0x8]
 *   @0x27d4b0 ldr r6, [r11, #0x10]
 *   @0x27d4b4 bic r0, r0, #-2147483648
 *   @0x27d4b8 and r3, r0, lr
 *   @0x27d4bc add r2, r3, r3, lsl #1
 *   @0x27d4c0 add r2, r6, r2, lsl #2
 *   @0x27d4c4 ldr r1, [r2, #0x8]
 *   @0x27d4c8 cmp r1, #0
 *   @0x27d4cc beq 0x27d5d0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x370>
 *   @0x27d4d0 ldr r7, [r11]
 *   @0x27d4d4 mov r4, #0
 *   @0x27d4d8 ldr r8, [sp, #0x10]
 *   @0x27d4dc ldr r9, [sp, #0x18]
 *   @0x27d4e0 b 0x27d524 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2c4>
 *   @0x27d4e4 ldr r5, [r2]
 *   @0x27d4e8 ldr r4, [r2, #0x4]
 *   @0x27d4ec str r0, [r2, #0x8]
 *   @0x27d4f0 mov r0, r1
 *   @0x27d4f4 str r8, [r2]
 *   @0x27d4f8 mov r8, r5
 *   @0x27d4fc str r9, [r2, #0x4]
 *   @0x27d500 mov r9, r4
 *   @0x27d504 add r3, r3, #1
 *   @0x27d508 add r4, r12, #1
 *   @0x27d50c and r3, r3, lr
 *   @0x27d510 add r2, r3, r3, lsl #1
 *   @0x27d514 add r2, r6, r2, lsl #2
 *   @0x27d518 ldr r1, [r2, #0x8]
 *   @0x27d51c cmp r1, #0
 *   @0x27d520 beq 0x27d5c8 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x368>
 *   @0x27d524 add r12, r7, r3
 *   @0x27d528 and r5, r1, lr
 *   @0x27d52c rsb r12, r5, r12
 *   @0x27d530 and r12, r12, lr
 *   @0x27d534 cmp r12, r4
 *   @0x27d538 blt 0x27d4e4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x284>
 *   @0x27d53c movne r12, r4
 *   @0x27d540 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4>
 *   @0x27d544 cmp r1, r0
 *   @0x27d548 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4>
 *   @0x27d54c ldr r4, [r2]
 *   @0x27d550 cmp r8, r4
 *   @0x27d554 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4>
 *   @0x27d558 ldr r3, [r11, #0x4]
 *   @0x27d55c str r8, [sp, #0x10]
 *   @0x27d560 str r8, [r2]
 *   @0x27d564 sub r3, r3, #1
 *   @0x27d568 str r9, [r2, #0x4]
 *   @0x27d56c str r1, [r2, #0x8]
 *   @0x27d570 str r9, [sp, #0x18]
 *   @0x27d574 str r3, [r11, #0x4]
 *   @0x27d578 ldr r12, [sp, #0xc]
 *   @0x27d57c ldr r0, [sp, #0x20]
 *   @0x27d580 add r12, r12, #1
 *   @0x27d584 str r12, [sp, #0xc]
 *   @0x27d588 ldr r12, [sp, #0x8]
 *   @0x27d58c add r12, r12, #12
 *   @0x27d590 str r12, [sp, #0x8]
 *   @0x27d594 ldr r12, [sp, #0xc]
 *   @0x27d598 cmp r12, r0
 *   @0x27d59c bne 0x27d468 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x208>
 *   @0x27d5a0 ldr r0, [sp, #0x30]
 *   @0x27d5a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27d5a8 vldr s13, [r11]
 *   @0x27d5ac vcvt.f32.s32 s14, s13
 *   @0x27d5b0 vldr s15, [pc, #536]
 *   @0x27d5b4 ldr r3, [r11, #0x4]
 *   @0x27d5b8 vmul.f32 s15, s14, s15
 *   @0x27d5bc vcvt.s32.f32 s15, s15
 *   @0x27d5c0 vstr s15, [r11, #12]
 *   @0x27d5c4 b 0x27d288 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x28>
 *   @0x27d5c8 str r8, [sp, #0x10]
 *   @0x27d5cc str r9, [sp, #0x18]
 *   @0x27d5d0 ldr r12, [sp, #0x10]
 *   @0x27d5d4 str r0, [r2, #0x8]
 *   @0x27d5d8 str r12, [r2]
 *   @0x27d5dc ldr r12, [sp, #0x18]
 *   @0x27d5e0 str r12, [r2, #0x4]
 *   @0x27d5e4 b 0x27d578 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x318>
 *   @0x27d5e8 ldr r12, [r11]
 *   @0x27d5ec mov r3, #1
 *   @0x27d5f0 ldr r1, [sp, #0x34]
 *   @0x27d5f4 mov r2, #70
 *   @0x27d5f8 str r12, [sp, #0x14]
 *   @0x27d5fc ldr r12, [r11, #0x10]
 *   @0x27d600 str r12, [sp, #0x28]
 *   @0x27d604 ldr r12, [sp, #0x14]
 *   @0x27d608 lsl r0, r12, r3
 *   @0x27d60c str r0, [r11]
 *   @0x27d610 add r4, r0, r12, lsl #2
 *   @0x27d614 sub r0, r0, #1
 *   @0x27d618 str r0, [r11, #0x8]
 *   @0x27d61c lsl r4, r4, #2
 *   @0x27d620 mov r0, r4
 *   @0x27d624 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d628 mov r2, r4
 *   @0x27d62c mov r1, #0
 *   @0x27d630 str r0, [r11, #0x10]
 *   @0x27d634 bl 0xb65b0 <memset@plt>
 *   @0x27d638 ldr r2, [r11]
 *   @0x27d63c mov r0, #0
 *   @0x27d640 str r0, [r11, #0x4]
 *   @0x27d644 cmp r2, r0
 *   @0x27d648 vmov s13, r2
 *   @0x27d64c vcvt.f32.s32 s15, s13
 *   @0x27d650 vmul.f32 s15, s15, s16
 *   @0x27d654 vcvt.s32.f32 s15, s15
 *   @0x27d658 vstr s15, [r11, #12]
 *   @0x27d65c ble 0x27d680 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x420>
 *   @0x27d660 add r2, r2, r2, lsl #1
 *   @0x27d664 ldr r3, [r11, #0x10]
 *   @0x27d668 add r2, r3, r2, lsl #2
 *   @0x27d66c mov r0, #0
 *   @0x27d670 add r3, r3, #12
 *   @0x27d674 str r0, [r3, #-0x4]
 *   @0x27d678 cmp r3, r2
 *   @0x27d67c bne 0x27d66c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x40c>
 *   @0x27d680 ldr r12, [sp, #0x14]
 *   @0x27d684 cmp r12, #0
 *   @0x27d688 ble 0x27d7a0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x540>
 *   @0x27d68c ldr r6, [sp, #0x28]
 *   @0x27d690 mov r12, #0
 *   @0x27d694 str r12, [sp, #0x4]
 *   @0x27d698 ldr r3, [r6, #0x8]
 *   @0x27d69c cmp r3, #0
 *   @0x27d6a0 ble 0x27d784 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x524>
 *   @0x27d6a4 ldr r3, [r11, #0x4]
 *   @0x27d6a8 ldr r2, [r11, #0xc]
 *   @0x27d6ac ldr r4, [r6]
 *   @0x27d6b0 cmp r3, r2
 *   @0x27d6b4 ldr r5, [r6, #0x4]
 *   @0x27d6b8 bgt 0x27d7e0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x580>
 *   @0x27d6bc add r3, r3, #1
 *   @0x27d6c0 mov r0, r4
 *   @0x27d6c4 str r3, [r11, #0x4]
 *   @0x27d6c8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x27d6cc ldr lr, [r11, #0x8]
 *   @0x27d6d0 ldr r9, [r11, #0x10]
 *   @0x27d6d4 bic r0, r0, #-2147483648
 *   @0x27d6d8 and r3, r0, lr
 *   @0x27d6dc add r2, r3, r3, lsl #1
 *   @0x27d6e0 add r2, r9, r2, lsl #2
 *   @0x27d6e4 ldr r1, [r2, #0x8]
 *   @0x27d6e8 cmp r1, #0
 *   @0x27d6ec ldrne r10, [r11]
 *   @0x27d6f0 movne r7, #0
 *   @0x27d6f4 bne 0x27d73c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4dc>
 *   @0x27d6f8 b 0x27d7c4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x564>
 *   @0x27d6fc ldr r8, [r2]
 *   @0x27d700 ldr r7, [r2, #0x4]
 *   @0x27d704 str r0, [r2, #0x8]
 *   @0x27d708 mov r0, r1
 *   @0x27d70c str r4, [r2]
 *   @0x27d710 mov r4, r8
 *   @0x27d714 str r5, [r2, #0x4]
 *   @0x27d718 mov r5, r7
 *   @0x27d71c add r3, r3, #1
 *   @0x27d720 add r7, r12, #1
 *   @0x27d724 and r3, r3, lr
 *   @0x27d728 add r2, r3, r3, lsl #1
 *   @0x27d72c add r2, r9, r2, lsl #2
 *   @0x27d730 ldr r1, [r2, #0x8]
 *   @0x27d734 cmp r1, #0
 *   @0x27d738 beq 0x27d7c4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x564>
 *   @0x27d73c add r12, r3, r10
 *   @0x27d740 and r8, r1, lr
 *   @0x27d744 rsb r12, r8, r12
 *   @0x27d748 and r12, r12, lr
 *   @0x27d74c cmp r12, r7
 *   @0x27d750 blt 0x27d6fc <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x49c>
 *   @0x27d754 movne r12, r7
 *   @0x27d758 bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc>
 *   @0x27d75c cmp r1, r0
 *   @0x27d760 bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc>
 *   @0x27d764 ldr r7, [r2]
 *   @0x27d768 cmp r4, r7
 *   @0x27d76c bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc>
 *   @0x27d770 ldr r3, [r11, #0x4]
 *   @0x27d774 stm r2, {r4, r5}
 *   @0x27d778 sub r3, r3, #1
 *   @0x27d77c str r1, [r2, #0x8]
 *   @0x27d780 str r3, [r11, #0x4]
 *   @0x27d784 ldr r12, [sp, #0x4]
 *   @0x27d788 add r6, r6, #12
 *   @0x27d78c ldr r0, [sp, #0x14]
 *   @0x27d790 add r12, r12, #1
 *   @0x27d794 str r12, [sp, #0x4]
 *   @0x27d798 cmp r12, r0
 *   @0x27d79c bne 0x27d698 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x438>
 *   @0x27d7a0 ldr r0, [sp, #0x28]
 *   @0x27d7a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27d7a8 vldr s13, [r11]
 *   @0x27d7ac vcvt.f32.s32 s15, s13
 *   @0x27d7b0 ldr r3, [r11, #0x4]
 *   @0x27d7b4 vmul.f32 s15, s15, s16
 *   @0x27d7b8 vcvt.s32.f32 s15, s15
 *   @0x27d7bc vstr s15, [r11, #12]
 *   @0x27d7c0 b 0x27d49c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x23c>
 *   @0x27d7c4 stm r2, {r4, r5}
 *   @0x27d7c8 str r0, [r2, #0x8]
 *   @0x27d7cc b 0x27d784 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x524>
 *   @0x27d7d0 svclo #0x19999a
 *   @0x27d7d4 andeq r3, r11, r8, lsl #25
 *   @0x27d7d8 andeq r3, r11, r12, ror #23
 *   @0x27d7dc ldrdeq r3, r4, [r11], -r8
 *   @0x27d7e0 ldr r8, [r11]
 *   @0x27d7e4 mov r3, #1
 *   @0x27d7e8 ldr r1, [sp, #0x2c]
 *   @0x27d7ec mov r2, #70
 *   @0x27d7f0 ldr r7, [r11, #0x10]
 *   @0x27d7f4 lsl r0, r8, r3
 *   @0x27d7f8 str r0, [r11]
 *   @0x27d7fc add r9, r0, r8, lsl #2
 *   @0x27d800 sub r0, r0, #1
 *   @0x27d804 str r0, [r11, #0x8]
 *   @0x27d808 lsl r9, r9, #2
 *   @0x27d80c mov r0, r9
 *   @0x27d810 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d814 mov r2, r9
 *   @0x27d818 mov r1, #0
 *   @0x27d81c str r0, [r11, #0x10]
 *   @0x27d820 bl 0xb65b0 <memset@plt>
 *   @0x27d824 ldr r2, [r11]
 *   @0x27d828 mov r0, #0
 *   @0x27d82c str r0, [r11, #0x4]
 *   @0x27d830 cmp r2, r0
 *   @0x27d834 vmov s13, r2
 *   @0x27d838 vcvt.f32.s32 s15, s13
 *   @0x27d83c vmul.f32 s15, s15, s16
 *   @0x27d840 vcvt.s32.f32 s15, s15
 *   @0x27d844 vstr s15, [r11, #12]
 *   @0x27d848 ble 0x27d86c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x60c>
 *   @0x27d84c add r2, r2, r2, lsl #1
 *   @0x27d850 ldr r3, [r11, #0x10]
 *   @0x27d854 add r2, r3, r2, lsl #2
 *   @0x27d858 mov r0, #0
 *   @0x27d85c add r3, r3, #12
 *   @0x27d860 str r0, [r3, #-0x4]
 *   @0x27d864 cmp r3, r2
 *   @0x27d868 bne 0x27d858 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x5f8>
 *   @0x27d86c cmp r8, #0
 *   @0x27d870 movgt r9, r7
 *   @0x27d874 movgt r10, #0
 *   @0x27d878 ble 0x27d8a4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x644>
 *   @0x27d87c ldr r3, [r9, #0x8]
 *   @0x27d880 mov r0, r11
 *   @0x27d884 add r10, r10, #1
 *   @0x27d888 cmp r3, #0
 *   @0x27d88c ble 0x27d898 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x638>
 *   @0x27d890 ldm r9, {r1, r2}
 *   @0x27d894 bl 0x27d260 <_ZN8CHashMapIPKciLi3EE6InsertES1_i>
 *   @0x27d898 cmp r10, r8
 *   @0x27d89c add r9, r9, #12
 *   @0x27d8a0 bne 0x27d87c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x61c>
 *   @0x27d8a4 mov r0, r7
 *   @0x27d8a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27d8ac vldr s13, [r11]
 *   @0x27d8b0 vcvt.f32.s32 s15, s13
 *   @0x27d8b4 ldr r3, [r11, #0x4]
 *   @0x27d8b8 vmul.f32 s15, s15, s16
 *   @0x27d8bc vcvt.s32.f32 s15, s15
 *   @0x27d8c0 vstr s15, [r11, #12]
 *   @0x27d8c4 b 0x27d6bc <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x45c>
 *
 * ══ §12/20 MainLoop_Process()  0x1d4778  size 1632  401 条（0x1d4778..0x1d4dd8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1d4778 0x1d4dd8  size 1632  401 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d4788→0x757e80, 0x1d47a8→0x542a38, 0x1d47ac→0x542a40, 0x1d47c8→0x5428e8, 0x1d47e4→0x54298c, 0x1d480c→0x3f5124, 0x1d4820→0x5429d8, 0x1d4824→0x542a20
 * 调用序列: Timing_Time×2 / __floatdisf×2 / __fixsfdi×2 / anon_319414×2 / CTimingSource::GetFPS()×2 / CProfiler::BeginFrame() / MemoryManager::Memory_Tick() / 0xb67fc
 * 字段偏移 top8: 0x8×6 / 0xc×4 / 0x4×3 / 0x518×2 / 0x4fc×2 / 0x498×2 / 0x390×2 / 0x4e4×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d477c vpush {d8}
 *   @0x1d4780 sub sp, sp, #20
 *   @0x1d4784 ldr r8, [pc, #0x518]
 *   @0x1d4788 ldr r3, [pc, #0x518]
 *   @0x1d478c add r8, pc, r8
 *   @0x1d4790 ldr r3, [r8, r3]
 *   @0x1d4794 mov r0, r3
 *   @0x1d4798 str r3, [sp, #0x8]
 *   @0x1d479c bl 0x2a03f8 <_ZN9CProfiler10BeginFrameEv>
 *   @0x1d47a0 bl 0x27d23c <_ZN13MemoryManager11Memory_TickEv>
 *   @0x1d47a4 bl 0x215148 <Timing_Time>
 *   @0x1d47a8 ldr r2, [pc, #0x4fc]
 *   @0x1d47ac ldr r3, [pc, #0x4fc]
 *   @0x1d47b0 ldr r4, [r8, r2]
 *   @0x1d47b4 strd r0, r1, [r4]
 *   @0x1d47b8 ldr r6, [r8, r3]
 *   @0x1d47bc ldrd r2, r3, [r6]
 *   @0x1d47dc cmp r3, #0
 *   @0x1d47e0 bne 0x1d4c20 <_Z16MainLoop_Processv+0x4a8>
 *   @0x1d47e4 ldr r3, [pc, #0x4cc]
 *   @0x1d47e8 ldr r3, [r8, r3]
 *   @0x1d47ec ldr r3, [r3]
 *   @0x1d47f0 cmp r3, #0
 *   @0x1d47f4 beq 0x1d4dac <_Z16MainLoop_Processv+0x634>
 *   @0x1d47f8 ldr r11, [r3, #0xc]
 *   @0x1d47fc mov r7, #1
 *   @0x1d4800 cmp r11, #0
 *   @0x1d4804 movle r11, #1
 *   @0x1d4808 strle r11, [r3, #0xc]
 *   @0x1d480c ldr r3, [pc, #0x4a8]
 *   @0x1d4810 mov r0, #0
 *   @0x1d4814 ldr r3, [r8, r3]
 *   @0x1d4818 str r11, [r3]
 *   @0x1d481c bl 0xb67fc <time@plt>
 *   @0x1d4820 ldr r3, [pc, #0x498]
 *   @0x1d4824 ldr r12, [pc, #0x498]
 *   @0x1d4828 ldrd r4, r5, [r4]
 *   @0x1d482c ldr lr, [r8, r3]
 *   @0x1d4830 ldrd r2, r3, [r6]
 *   @0x1d4834 ldr r1, [pc, #0x48c]
 *   @0x1d4838 subs r4, r4, r2
 *   @0x1d483c sbc r5, r5, r3
 *   @0x1d4840 asr r3, r0, #31
 *   @0x1d4844 mov r2, r0
 *   @0x1d4848 strd r2, r3, [lr]
 *   @0x1d484c ldr r12, [r8, r12]
 *   @0x1d4850 strd r4, r5, [r12]
 *   @0x1d4854 ldr r10, [r8, r1]
 *   @0x1d4858 ldrb r3, [r10]
 *   @0x1d485c cmp r3, #0
 *   @0x1d4860 beq 0x1d487c <_Z16MainLoop_Processv+0x104>
 *   @0x1d4864 ldr r3, [pc, #0x460]
 *   @0x1d4868 ldr r3, [r8, r3]
 *   @0x1d486c ldrd r2, r3, [r3]
 *   @0x1d4870 subs r4, r4, r2
 *   @0x1d4874 sbc r5, r5, r3
 *   @0x1d4878 strd r4, r5, [r12]
 *   @0x1d487c ldr r0, [sp, #0x4]
 *   @0x1d4880 ldrb r3, [r0]
 *   @0x1d4884 cmp r3, #0
 *   @0x1d4888 beq 0x1d48a4 <_Z16MainLoop_Processv+0x12c>
 *   @0x1d488c ldr r3, [pc, #0x480]
 *   @0x1d4890 ldr r3, [r8, r3]
 *   @0x1d4894 vldr d7, [r3, #24]
 *   @0x1d4898 vcmpe.f64 d7, #0
 *   @0x1d489c vmrs APSR_nzcv, fpscr
 *   @0x1d48a0 ble 0x1d4d2c <_Z16MainLoop_Processv+0x5b4>
 *   @0x1d48a4 vmov s14, r11
 *   @0x1d48a8 vldr s16, [pc, #1004]
 *   @0x1d48ac ldrd r0, r1, [r12]
 *   @0x1d48b0 vcvt.f32.s32 s17, s14
 *   @0x1d48b4 bl 0x319398 <__floatdisf>
 *   @0x1d48b8 vdiv.f32 s17, s16, s17
 *   @0x1d48bc vmov s14, r0
 *   @0x1d48c0 vsub.f32 s15, s17, s14
 *   @0x1d48c4 vcmpe.f32 s15, #0
 *   @0x1d48c8 vmrs APSR_nzcv, fpscr
 *   @0x1d48cc bmi 0x1d4c64 <_Z16MainLoop_Processv+0x4ec>
 *   @0x1d48d0 vmov r0, s15
 *   @0x1d48d4 bl 0x319468 <__fixsfdi>
 *   @0x1d48d8 ldr r3, [pc, #0x42c]
 *   @0x1d48dc ldr r4, [r8, r3]
 *   @0x1d48e0 strd r0, r1, [r4]
 *   @0x1d48e4 bl 0x319398 <__floatdisf>
 *   @0x1d48e8 vmov s14, r0
 *   @0x1d48ec vcmpe.f32 s14, s16
 *   @0x1d48f0 vmrs APSR_nzcv, fpscr
 *   @0x1d48f4 movwpl r0, #0x4240
 *   @0x1d48f8 movpl r1, #0
 *   @0x1d48fc movtpl r0, #0xf
 *   @0x1d4900 bmi 0x1d4dd0 <_Z16MainLoop_Processv+0x658>
 *   @0x1d4904 stm r4, {r0, r1}
 *   @0x1d4908 ldr r3, [pc, #0x3c0]
 *   @0x1d490c ldr r3, [r8, r3]
 *   @0x1d4910 ldrb r3, [r3]
 *   @0x1d4914 cmp r3, #0
 *   @0x1d4918 beq 0x1d4a1c <_Z16MainLoop_Processv+0x2a4>
 *   @0x1d491c ldr r3, [pc, #0x3b0]
 *   @0x1d4920 ldr r3, [r8, r3]
 *   @0x1d4924 ldrb r3, [r3]
 *   @0x1d4928 cmp r3, #0
 *   @0x1d492c bne 0x1d49e4 <_Z16MainLoop_Processv+0x26c>
 *   @0x1d4930 ldr r3, [pc, #0x3a0]
 *   @0x1d4934 ldr r3, [r8, r3]
 *   @0x1d4938 ldrb r3, [r3]
 *   @0x1d493c cmp r3, #0
 *   @0x1d4940 beq 0x1d49e4 <_Z16MainLoop_Processv+0x26c>
 *   @0x1d4944 ldr r3, [pc, #0x390]
 *   @0x1d4948 ldr r2, [pc, #0x390]
 *   @0x1d494c ldr r3, [r8, r3]
 *   @0x1d4950 ldr r5, [r8, r2]
 *   @0x1d4954 ldrb r3, [r3]
 *   @0x1d4958 cmp r3, #0
 *   @0x1d495c movne r3, #1
 *   @0x1d4960 cmp r7, #0
 *   @0x1d4964 str r3, [r5]
 *   @0x1d4968 beq 0x1d49e4 <_Z16MainLoop_Processv+0x26c>
 *   @0x1d496c vmov s14, r11
 *   @0x1d4970 ldr r3, [pc, #0x36c]
 *   @0x1d4974 vmov.f32 s17, #1.000000e+00
 *   @0x1d4978 ldr r3, [r8, r3]
 *   @0x1d497c vldr s16, [r3]
 *   @0x1d4980 vcvt.f32.s32 s15, s14
 *   @0x1d4984 vdiv.f32 s16, s16, s15
 *   @0x1d4988 vmov r0, s16
 *   @0x1d498c bl 0xb6910 <floorf@plt>
 *   @0x1d4990 vmov s14, r0
 *   @0x1d4994 vsub.f32 s15, s16, s14
 *   @0x1d4998 vsub.f32 s17, s17, s15
 *   @0x1d499c vcmpe.f32 s15, s17
 *   @0x1d49a0 vmrs APSR_nzcv, fpscr
 *   @0x1d49a4 ble 0x1d49b8 <_Z16MainLoop_Processv+0x240>
 *   @0x1d49a8 vmov r0, s16
 *   @0x1d49ac bl 0xb6994 <ceilf@plt>
 *   @0x1d49b0 vmov.f32 s15, s17
 *   @0x1d49b4 vmov s14, r0
 *   @0x1d49b8 vldr s13, [pc, #736]
 *   @0x1d49bc vcmpe.f32 s15, s13
 *   @0x1d49c0 vmrs APSR_nzcv, fpscr
 *   @0x1d49c4 bpl 0x1d49e4 <_Z16MainLoop_Processv+0x26c>
 *   @0x1d49c8 vcvt.s32.f32 s14, s14
 *   @0x1d49cc vmov r3, s14
 *   @0x1d49d0 cmp r3, #4
 *   @0x1d49d4 strle r3, [r5]
 *   @0x1d49d8 movle r2, #0
 *   @0x1d49dc movle r3, #0
 *   @0x1d49e0 strdle r2, r3, [r4]
 *   @0x1d49e4 ldr r1, [pc, #0x2fc]
 *   @0x1d49e8 movw r0, #0x4040
 *   @0x1d49ec movt r0, #0xff80
 *   @0x1d49f0 add r1, pc, r1
 *   @0x1d49f4 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc>
 *   @0x1d49f8 ldrb r3, [r10]
 *   @0x1d49fc cmp r3, #0
 *   @0x1d4a00 bne 0x1d4d18 <_Z16MainLoop_Processv+0x5a0>
 *   @0x1d4a04 ldrd r0, r1, [r4]
 *   @0x1d4a08 bl 0x212da4 <Timing_Wait>
 *   @0x1d4a0c ldrb r3, [r10]
 *   @0x1d4a10 cmp r3, #0
 *   @0x1d4a14 bne 0x1d4c90 <_Z16MainLoop_Processv+0x518>
 *   @0x1d4a18 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv>
 *   @0x1d4a1c bl 0x215148 <Timing_Time>
 *   @0x1d4a20 ldr r3, [pc, #0x2c4]
 *   @0x1d4a24 mov r4, r0
 *   @0x1d4a28 mov r5, r1
 *   @0x1d4a2c strd r4, r5, [r6]
 *   @0x1d4a30 ldr r3, [r8, r3]
 *   @0x1d4a34 str r3, [sp, #0xc]
 *   @0x1d4a38 ldrd r2, r3, [r3]
 *   @0x1d4a3c cmp r4, r2
 *   @0x1d4a40 sbcs r0, r5, r3
 *   @0x1d4a44 mov r0, r4
 *   @0x1d4a48 ldrlt r12, [sp, #0xc]
 *   @0x1d4a4c movge r9, r2
 *   @0x1d4a50 movge r11, r3
 *   @0x1d4a54 movw r2, #0x4240
 *   @0x1d4a58 mov r3, #0
 *   @0x1d4a5c movt r2, #0xf
 *   @0x1d4a60 strdlt r4, r5, [r12]
 *   @0x1d4a64 movlt r9, r4
 *   @0x1d4a68 movlt r11, r1
 *   @0x1d4a6c bl 0x319414 <__aeabi_ldivmod>
 *   @0x1d4a70 mov r3, #0
 *   @0x1d4a74 movw r2, #0x4240
 *   @0x1d4a78 movt r2, #0xf
 *   @0x1d4a7c mov r6, r0
 *   @0x1d4a80 mov r7, r1
 *   @0x1d4a84 mov r0, r9
 *   @0x1d4a88 mov r1, r11
 *   @0x1d4a8c bl 0x319414 <__aeabi_ldivmod>
 *   @0x1d4a90 ldr r3, [pc, #0x258]
 *   @0x1d4a94 cmp r0, r6
 *   @0x1d4a98 sbcs r2, r1, r7
 *   @0x1d4a9c blt 0x1d4bec <_Z16MainLoop_Processv+0x474>
 *   @0x1d4aa0 ldr r3, [r8, r3]
 *   @0x1d4aa4 ldr r2, [r3]
 *   @0x1d4aa8 add r2, r2, #1
 *   @0x1d4aac str r2, [r3]
 *   @0x1d4ab0 bl 0x21f17c <_Z10Sound_Tickv>
 *   @0x1d4ab4 ldr r3, [pc, #0x238]
 *   @0x1d4ab8 ldr r3, [r8, r3]
 *   @0x1d4abc ldrb r5, [r3]
 *   @0x1d4ac0 cmp r5, #0
 *   @0x1d4ac4 bne 0x1d4b94 <_Z16MainLoop_Processv+0x41c>
 *   @0x1d4ac8 ldr r3, [pc, #0x228]
 *   @0x1d4acc ldr r4, [r8, r3]
 *   @0x1d4ad0 ldr r3, [r4]
 *   @0x1d4ad4 cmp r3, #1
 *   @0x1d4ad8 ble 0x1d4c10 <_Z16MainLoop_Processv+0x498>
 *   @0x1d4adc bl 0x168c20 <_Z19GR_D3D_PartialResetv>
 *   @0x1d4ae0 ldr r3, [r4]
 *   @0x1d4ae4 sub r3, r3, #1
 *   @0x1d4ae8 str r3, [r4]
 *   @0x1d4aec bl 0x1699c0 <_Z18GR_D3D_Start_Framev>
 *   @0x1d4af0 ldrb r3, [r10]
 *   @0x1d4af4 cmp r3, #0
 *   @0x1d4af8 bne 0x1d4c84 <_Z16MainLoop_Processv+0x50c>
 *   @0x1d4afc bl 0x1d32c0 <_Z7DoAStepv>
 *   @0x1d4b00 ldrb r3, [r10]
 *   @0x1d4b04 cmp r3, #0
 *   @0x1d4b08 bne 0x1d4c78 <_Z16MainLoop_Processv+0x500>
 *   @0x1d4b0c bl 0x18d488 <_Z9IO_Renderv>
 *   @0x1d4b10 ldr r3, [pc, #0x1e4]
 *   @0x1d4b14 ldr r4, [r8, r3]
 *   @0x1d4b18 ldr r3, [r4]
 *   @0x1d4b1c cmp r3, #0
 *   @0x1d4b20 movge r0, #0
 *   @0x1d4b24 blt 0x1d4d44 <_Z16MainLoop_Processv+0x5cc>
 *   @0x1d4b28 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb>
 *   @0x1d4b2c ldr r3, [pc, #0x1cc]
 *   @0x1d4b30 ldr r3, [r8, r3]
 *   @0x1d4b34 ldr r3, [r3]
 *   @0x1d4b38 cmp r3, #0
 *   @0x1d4b3c beq 0x1d4b70 <_Z16MainLoop_Processv+0x3f8>
 *   @0x1d4b40 movw r3, #0xfe70
 *   @0x1d4b44 movt r3, #0xffff
 *   @0x1d4b48 str r3, [r4]
 *   @0x1d4b4c ldr r3, [pc, #0x1b0]
 *   @0x1d4b50 mov r2, #0
 *   @0x1d4b54 mov r0, #60
 *   @0x1d4b58 mov r1, #0
 *   @0x1d4b5c ldr r3, [r8, r3]
 *   @0x1d4b60 strb r2, [r3]
 *   @0x1d4b64 add sp, sp, #20
 *   @0x1d4b68 vpop {d8}
 *   @0x1d4b6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d4b70 ldr r0, [r4]
 *   @0x1d4b74 cmn r0, #200
 *   @0x1d4b78 beq 0x1d4d90 <_Z16MainLoop_Processv+0x618>
 *   @0x1d4b7c ble 0x1d4db8 <_Z16MainLoop_Processv+0x640>
 *   @0x1d4b80 cmn r0, #100
 *   @0x1d4b84 beq 0x1d4b4c <_Z16MainLoop_Processv+0x3d4>
 *   @0x1d4b88 cmn r0, #1
 *   @0x1d4b8c beq 0x1d4b94 <_Z16MainLoop_Processv+0x41c>
 *   @0x1d4b90 bl 0x1d4450 <_Z10SwitchRoomi>
 *   @0x1d4b94 ldr r0, [sp, #0x8]
 *   @0x1d4b98 bl 0x2a1498 <_ZN9CProfiler8EndFrameEv>
 *   @0x1d4b9c bl 0x29d770 <_Z12TickDebuggerv>
 *   @0x1d4ba0 ldr r12, [sp, #0x4]
 *   @0x1d4ba4 ldrb r3, [r12]
 *   @0x1d4ba8 cmp r3, #0
 *   @0x1d4bac bne 0x1d4d68 <_Z16MainLoop_Processv+0x5f0>
 *   @0x1d4bb0 ldr r3, [pc, #0x100]
 *   @0x1d4bb4 ldr r3, [r8, r3]
 *   @0x1d4bb8 ldr r3, [r3]
 *   @0x1d4bbc cmp r3, #0
 *   @0x1d4bc0 beq 0x1d4d54 <_Z16MainLoop_Processv+0x5dc>
 *   @0x1d4bc4 ldr r0, [r3, #0xc]
 *   @0x1d4bc8 cmp r0, #0
 *   @0x1d4bcc asrgt r1, r0, #31
 *   @0x1d4bd0 movle r2, #1
 *   @0x1d4bd4 movle r0, #1
 *   @0x1d4bd8 movle r1, #0
 *   @0x1d4bdc strle r2, [r3, #0xc]
 *   @0x1d4be0 add sp, sp, #20
 *   @0x1d4be4 vpop {d8}
 *   @0x1d4be8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d4bec ldr r3, [r8, r3]
 *   @0x1d4bf0 mov r2, #1
 *   @0x1d4bf4 ldr r1, [pc, #0x10c]
 *   @0x1d4bf8 ldr r12, [sp, #0xc]
 *   @0x1d4bfc ldr r0, [r3]
 *   @0x1d4c00 ldr r1, [r8, r1]
 *   @0x1d4c04 strd r4, r5, [r12]
 *   @0x1d4c08 str r0, [r1]
 *   @0x1d4c0c b 0x1d4aac <_Z16MainLoop_Processv+0x334>
 *   @0x1d4c10 bne 0x1d4aec <_Z16MainLoop_Processv+0x374>
 *   @0x1d4c14 bl 0x168c24 <_Z12GR_D3D_Resetv>
 *   @0x1d4c18 str r5, [r4]
 *   @0x1d4c1c b 0x1d4aec <_Z16MainLoop_Processv+0x374>
 *   @0x1d4c20 ldr r3, [pc, #0xec]
 *   @0x1d4c24 ldr r5, [r8, r3]
 *   @0x1d4c28 mov r0, r5
 *   @0x1d4c2c bl 0x214770 <_ZN13CTimingSource6UpdateEv>
 *   @0x1d4c30 vldr d7, [r5, #24]
 *   @0x1d4c34 vcmpe.f64 d7, #0
 *   @0x1d4c38 vmrs APSR_nzcv, fpscr
 *   @0x1d4c3c movle r7, #0
 *   @0x1d4c40 movle r11, #60
 *   @0x1d4c44 ble 0x1d480c <_Z16MainLoop_Processv+0x94>
 *   @0x1d4c48 mov r0, r5
 *   @0x1d4c4c mov r7, #1
 *   @0x1d4c50 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1d4c54 vmov d7, r0, r1
 *   @0x1d4c58 vcvt.s32.f64 s15, d7
 *   @0x1d4c5c vmov r11, s15
 *   @0x1d4c60 b 0x1d480c <_Z16MainLoop_Processv+0x94>
 *   @0x1d4c64 ldr r3, [pc, #0xa0]
 *   @0x1d4c68 mov r0, #0
 *   @0x1d4c6c mov r1, r0
 *   @0x1d4c70 ldr r4, [r8, r3]
 *   @0x1d4c74 b 0x1d4904 <_Z16MainLoop_Processv+0x18c>
 *   @0x1d4c78 ldr r0, [sp, #0x8]
 *   @0x1d4c7c bl 0x2a0960 <_ZN9CProfiler7EndStepEv>
 *   @0x1d4c80 b 0x1d4b0c <_Z16MainLoop_Processv+0x394>
 *   @0x1d4c84 ldr r0, [sp, #0x8]
 *   @0x1d4c88 bl 0x2a0870 <_ZN9CProfiler9BeginStepEv>
 *   @0x1d4c8c b 0x1d4afc <_Z16MainLoop_Processv+0x384>
 *   @0x1d4c90 ldr r0, [sp, #0x8]
 *   @0x1d4c94 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1d4c98 b 0x1d4a18 <_Z16MainLoop_Processv+0x2a0>
 *   @0x1d4c9c ldmdbmi r4!, {r10, sp} ^
 *   @0x1d4ca0 stcllo p12, c12, [r12, #820]
 *   @0x1d4ca4 eoreq sp, r1, r4, asr #9
 *   @0x1d4ca8 .word 0xffffbf1c
 *   @0x1d4cac .word 0xffffef40
 *   @0x1d4cb0 .word 0xffffef28
 *   @0x1d4cb4 .word 0xffffbcd4
 *   @0x1d4cb8 .word 0xffffbcd8
 *   @0x1d4cbc .word 0xffffef44
 *   @0x1d4cc0 .word 0xffffef1c
 *   @0x1d4cc4 .word 0xffffef48
 *   @0x1d4cc8 .word 0xffffbf18
 *   @0x1d4ccc .word 0xffffef4c
 *   @0x1d4cd0 .word 0xffffef50
 *   @0x1d4cd4 .word 0xffffc960
 *   @0x1d4cd8 .word 0xffffef54
 *   @0x1d4cdc .word 0xffffe7f0
 *   @0x1d4ce0 .word 0xffffef58
 *   @0x1d4ce4 .word 0xffffef5c
 *   @0x1d4ce8 andseq r12, r7, r0, asr #14
 *   @0x1d4cec .word 0xffffef30
 *   @0x1d4cf0 .word 0xffffef2c
 *   @0x1d4cf4 .word 0xffffdfa0
 *   @0x1d4cf8 .word 0xffffc97c
 *   @0x1d4cfc .word 0xffffc154
 *   @0x1d4d00 .word 0xffffdf58
 *   @0x1d4d04 .word 0xffffeebc
 *   @0x1d4d08 .word 0xffffeb1c
 *   @0x1d4d0c .word 0xffffef60
 *   @0x1d4d10 .word 0xffffc974
 *   @0x1d4d14 .word 0xffffbcdc
 *   @0x1d4d18 ldr r0, [sp, #0x8]
 *   @0x1d4d1c mov r1, #6
 *   @0x1d4d20 mov r2, #20
 *   @0x1d4d24 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1d4d28 b 0x1d4a04 <_Z16MainLoop_Processv+0x28c>
 *   @0x1d4d2c ldr r1, [pc, #-0x28]
 *   @0x1d4d30 mov r2, #0
 *   @0x1d4d34 mov r3, #0
 *   @0x1d4d38 ldr r4, [r8, r1]
 *   @0x1d4d3c strd r2, r3, [r4]
 *   @0x1d4d40 b 0x1d4908 <_Z16MainLoop_Processv+0x190>
 *   @0x1d4d44 ldr r3, [pc, #-0x3c]
 *   @0x1d4d48 ldr r3, [r8, r3]
 *   @0x1d4d4c ldrb r0, [r3]
 *   @0x1d4d50 b 0x1d4b28 <_Z16MainLoop_Processv+0x3b0>
 *   @0x1d4d54 mov r0, #60
 *   @0x1d4d58 mov r1, #0
 *   @0x1d4d5c add sp, sp, #20
 *   @0x1d4d60 vpop {d8}
 *   @0x1d4d64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d4d68 ldr r3, [pc, #-0x5c]
 *   @0x1d4d6c ldr r0, [r8, r3]
 *   @0x1d4d70 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1d4d74 vmov d7, r0, r1
 *   @0x1d4d78 vcvt.s32.f64 s15, d7
 *   @0x1d4d7c vmov r0, s15
 *   @0x1d4d80 asr r1, r0, #31
 *   @0x1d4d84 add sp, sp, #20
 *   @0x1d4d88 vpop {d8}
 *   @0x1d4d8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d4d90 bl 0x1d1b38 <_Z11Run_EndGamev>
 *   @0x1d4d94 bl 0x18e58c <_Z14GamePadRestartv>
 *   @0x1d4d98 bl 0x1d44fc <_Z9StartGamev>
 *   @0x1d4d9c movw r0, #0x12e4
 *   @0x1d4da0 movt r0, #0x20
 *   @0x1d4da4 bl 0xb69c4 <srand48@plt>
 *   @0x1d4da8 b 0x1d4b94 <_Z16MainLoop_Processv+0x41c>
 *   @0x1d4dac mov r7, #1
 *   @0x1d4db0 mov r11, #60
 *   @0x1d4db4 b 0x1d480c <_Z16MainLoop_Processv+0x94>
 *   @0x1d4db8 cmn r0, #400
 *   @0x1d4dbc beq 0x1d4b4c <_Z16MainLoop_Processv+0x3d4>
 *   @0x1d4dc0 cmn r0, #300
 *   @0x1d4dc4 bne 0x1d4b90 <_Z16MainLoop_Processv+0x418>
 *   @0x1d4dc8 bl 0x1d1cb4 <_Z8LoadGamev>
 *   @0x1d4dcc b 0x1d4b94 <_Z16MainLoop_Processv+0x41c>
 *   @0x1d4dd0 bl 0x319468 <__fixsfdi>
 *   @0x1d4dd4 b 0x1d4904 <_Z16MainLoop_Processv+0x18c>
 *
 * ══ §13/20 CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)  0x207fe8  size 1616  404 条（0x207fe8..0x208638）
 * @func 0x207fe8 0x208638  size 1616  404 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DoOperation(int, RValue*, RValue*)×4 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x1f8×3 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x2dc×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x3e4×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x534×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x25c / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x388 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)+0x364
 * 字段偏移 top8: 0x8×19 / 0x10×16 / 0x4×11 / 0x5c×11 / 0x1c×10 / 0x60×9 / 0x14×9 / 0x18×8
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x207fec sub sp, sp, #44
 *   @0x207ff0 mov r9, r2
 *   @0x207ff4 mov r4, r0
 *   @0x207ff8 ldr r12, [sp, #0x54]
 *   @0x207ffc str r1, [sp, #0x24]
 *   @0x208000 cmp r3, r12
 *   @0x208004 ldr r1, [sp, #0x50]
 *   @0x208008 ldr r2, [sp, #0x58]
 *   @0x20800c bge 0x208024 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3c>
 *   @0x208010 cmp r3, #0
 *   @0x208014 bge 0x208598 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5b0>
 *   @0x208018 mov r0, #0
 *   @0x20801c str r0, [sp, #0x10]
 *   @0x208020 b 0x20802c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x44>
 *   @0x208024 bic r0, r12, r12, asr #31
 *   @0x208028 str r0, [sp, #0x10]
 *   @0x20802c ldr r0, [r9, #0x4]
 *   @0x208030 cmp r3, r12
 *   @0x208034 movge r5, r3
 *   @0x208038 movlt r5, r12
 *   @0x20803c cmp r5, r0
 *   @0x208040 subge r12, r0, #1
 *   @0x208044 bge 0x208050 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x68>
 *   @0x208048 cmp r12, r3
 *   @0x20804c movlt r12, r3
 *   @0x208050 cmp r1, r2
 *   @0x208054 bge 0x208068 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x80>
 *   @0x208058 cmp r1, #0
 *   @0x20805c bge 0x208588 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5a0>
 *   @0x208060 mov r6, #0
 *   @0x208064 b 0x20806c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x84>
 *   @0x208068 bic r6, r2, r2, asr #31
 *   @0x20806c ldr r7, [r9, #0x8]
 *   @0x208070 cmp r1, r2
 *   @0x208074 movge r3, r1
 *   @0x208078 movlt r3, r2
 *   @0x20807c cmp r3, r7
 *   @0x208080 subge r7, r7, #1
 *   @0x208084 bge 0x208094 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0xac>
 *   @0x208088 cmp r1, r2
 *   @0x20808c movge r7, r1
 *   @0x208090 movlt r7, r2
 *   @0x208094 ldr r3, [sp, #0x5c]
 *   @0x208098 cmp r3, #0
 *   @0x20809c ldrlt r0, [sp, #0x10]
 *   @0x2080a0 rsblt r0, r3, r0
 *   @0x2080a4 movlt r3, #0
 *   @0x2080a8 strlt r3, [sp, #0x5c]
 *   @0x2080ac ldr r3, [sp, #0x60]
 *   @0x2080b0 strlt r0, [sp, #0x10]
 *   @0x2080b4 cmp r3, #0
 *   @0x2080b8 ldr r0, [sp, #0x5c]
 *   @0x2080bc rsblt r6, r3, r6
 *   @0x2080c0 movlt r3, #0
 *   @0x2080c4 strlt r3, [sp, #0x60]
 *   @0x2080c8 ldr r3, [sp, #0x10]
 *   @0x2080cc rsb r2, r3, r12
 *   @0x2080d0 ldr r3, [r4, #0x4]
 *   @0x2080d4 add r2, r2, r0
 *   @0x2080d8 cmp r3, r2
 *   @0x2080dc rsb r2, r6, r7
 *   @0x2080e0 suble r3, r3, #1
 *   @0x2080e4 ldrle r12, [sp, #0x10]
 *   @0x2080e8 addle r3, r3, r12
 *   @0x2080ec rsble r12, r0, r3
 *   @0x2080f0 ldr r0, [sp, #0x5c]
 *   @0x2080f4 ldr r3, [r4, #0x8]
 *   @0x2080f8 add r2, r2, r0
 *   @0x2080fc ldr r0, [sp, #0x5c]
 *   @0x208100 cmp r3, r2
 *   @0x208104 suble r3, r3, #1
 *   @0x208108 addle r7, r3, r6
 *   @0x20810c ldrle r3, [sp, #0x60]
 *   @0x208110 rsble r7, r3, r7
 *   @0x208114 ldr r3, [sp, #0x10]
 *   @0x208118 cmp r3, r0
 *   @0x20811c movlt r3, #0
 *   @0x208120 movge r3, #1
 *   @0x208124 str r3, [sp, #0x18]
 *   @0x208128 ldr r3, [sp, #0x60]
 *   @0x20812c ldr r0, [sp, #0x18]
 *   @0x208130 cmp r6, r3
 *   @0x208134 movlt r3, #0
 *   @0x208138 movge r3, #1
 *   @0x20813c tst r0, r3
 *   @0x208140 str r3, [sp, #0x1c]
 *   @0x208144 ldr r3, [sp, #0x10]
 *   @0x208148 beq 0x2083f8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x410>
 *   @0x20814c cmp r3, r12
 *   @0x208150 bgt 0x20843c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x454>
 *   @0x208154 ldr r10, [sp, #0x5c]
 *   @0x208158 mov r11, r3
 *   @0x20815c str r12, [sp, #0x14]
 *   @0x208160 cmp r6, r7
 *   @0x208164 bgt 0x2081f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x208>
 *   @0x208168 mvn r3, r10
 *   @0x20816c ldr r8, [sp, #0x60]
 *   @0x208170 lsr r3, r3, #31
 *   @0x208174 mvn r12, r11
 *   @0x208178 mov r5, r6
 *   @0x20817c lsr r12, r12, #31
 *   @0x208180 str r12, [sp, #0x20]
 *   @0x208184 ldr r1, [r4, #0x4]
 *   @0x208188 cmp r1, r10
 *   @0x20818c ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x208190 ldr r2, [r4, #0x8]
 *   @0x208194 cmp r8, r2
 *   @0x208198 bge 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x20819c ldr r2, [r9, #0x4]
 *   @0x2081a0 cmp r2, r11
 *   @0x2081a4 ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x2081a8 ldr r0, [r9, #0x8]
 *   @0x2081ac cmp r0, r5
 *   @0x2081b0 ble 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x2081b4 cmp r8, #0
 *   @0x2081b8 movlt r0, #0
 *   @0x2081bc andge r0, r3, #1
 *   @0x2081c0 cmp r0, #0
 *   @0x2081c4 beq 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x2081c8 ldr r0, [sp, #0x20]
 *   @0x2081cc cmp r5, #0
 *   @0x2081d0 movlt r0, #0
 *   @0x2081d4 andge r0, r0, #1
 *   @0x2081d8 cmp r0, #0
 *   @0x2081dc bne 0x2085d8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5f0>
 *   @0x2081e0 add r5, r5, #1
 *   @0x2081e4 add r8, r8, #1
 *   @0x2081e8 cmp r7, r5
 *   @0x2081ec bge 0x208184 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x19c>
 *   @0x2081f0 ldr r3, [sp, #0x14]
 *   @0x2081f4 add r11, r11, #1
 *   @0x2081f8 add r10, r10, #1
 *   @0x2081fc cmp r3, r11
 *   @0x208200 bge 0x208160 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x178>
 *   @0x208204 ldr r3, [sp, #0x10]
 *   @0x208208 ldr r0, [sp, #0x5c]
 *   @0x20820c ldr r1, [sp, #0x1c]
 *   @0x208210 cmp r3, r0
 *   @0x208214 ldr r12, [sp, #0x14]
 *   @0x208218 movge r3, #0
 *   @0x20821c movlt r3, #1
 *   @0x208220 tst r1, r3
 *   @0x208224 str r3, [sp, #0x20]
 *   @0x208228 beq 0x208454 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x46c>
 *   @0x20822c ldr r3, [sp, #0x5c]
 *   @0x208230 mov r11, r12
 *   @0x208234 str r12, [sp, #0x1c]
 *   @0x208238 add r10, r3, r12
 *   @0x20823c ldr r3, [sp, #0x10]
 *   @0x208240 rsb r10, r3, r10
 *   @0x208244 cmp r6, r7
 *   @0x208248 bgt 0x2082d4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2ec>
 *   @0x20824c mvn r3, r10
 *   @0x208250 ldr r8, [sp, #0x60]
 *   @0x208254 lsr r3, r3, #31
 *   @0x208258 mvn r12, r11
 *   @0x20825c mov r5, r6
 *   @0x208260 lsr r12, r12, #31
 *   @0x208264 str r12, [sp, #0x14]
 *   @0x208268 ldr r1, [r4, #0x4]
 *   @0x20826c cmp r10, r1
 *   @0x208270 bge 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *   @0x208274 ldr r2, [r4, #0x8]
 *   @0x208278 cmp r8, r2
 *   @0x20827c bge 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *   @0x208280 ldr r2, [r9, #0x4]
 *   @0x208284 cmp r2, r11
 *   @0x208288 ble 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *   @0x20828c ldr r0, [r9, #0x8]
 *   @0x208290 cmp r0, r5
 *   @0x208294 ble 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *   @0x208298 cmp r8, #0
 *   @0x20829c movlt r0, #0
 *   @0x2082a0 andge r0, r3, #1
 *   @0x2082a4 cmp r0, #0
 *   @0x2082a8 beq 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *   @0x2082ac ldr r0, [sp, #0x14]
 *   @0x2082b0 cmp r5, #0
 *   @0x2082b4 movlt r0, #0
 *   @0x2082b8 andge r0, r0, #1
 *   @0x2082bc cmp r0, #0
 *   @0x2082c0 bne 0x208608 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x620>
 *   @0x2082c4 add r5, r5, #1
 *   @0x2082c8 add r8, r8, #1
 *   @0x2082cc cmp r7, r5
 *   @0x2082d0 bge 0x208268 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x280>
 *   @0x2082d4 ldr r3, [sp, #0x10]
 *   @0x2082d8 sub r11, r11, #1
 *   @0x2082dc sub r10, r10, #1
 *   @0x2082e0 cmp r3, r11
 *   @0x2082e4 ble 0x208244 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x25c>
 *   @0x2082e8 ldr r3, [sp, #0x60]
 *   @0x2082ec ldr r0, [sp, #0x18]
 *   @0x2082f0 cmp r6, r3
 *   @0x2082f4 ldr r12, [sp, #0x1c]
 *   @0x2082f8 movge r3, #0
 *   @0x2082fc movlt r3, #1
 *   @0x208300 tst r0, r3
 *   @0x208304 str r3, [sp, #0x1c]
 *   @0x208308 bne 0x208480 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x498>
 *   @0x20830c ldr r3, [sp, #0x20]
 *   @0x208310 ldr r0, [sp, #0x1c]
 *   @0x208314 tst r3, r0
 *   @0x208318 beq 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408>
 *   @0x20831c ldr r3, [sp, #0x10]
 *   @0x208320 cmp r3, r12
 *   @0x208324 bgt 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408>
 *   @0x208328 ldr r3, [sp, #0x5c]
 *   @0x20832c mov r11, r12
 *   @0x208330 ldr r1, [sp, #0x10]
 *   @0x208334 add r10, r3, r12
 *   @0x208338 ldr r0, [sp, #0x60]
 *   @0x20833c rsb r10, r1, r10
 *   @0x208340 add r3, r0, r7
 *   @0x208344 rsb r3, r6, r3
 *   @0x208348 str r3, [sp, #0xc]
 *   @0x20834c cmp r6, r7
 *   @0x208350 bgt 0x2083dc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3f4>
 *   @0x208354 mvn r3, r10
 *   @0x208358 ldr r8, [sp, #0xc]
 *   @0x20835c lsr r3, r3, #31
 *   @0x208360 mvn r12, r11
 *   @0x208364 mov r5, r7
 *   @0x208368 lsr r12, r12, #31
 *   @0x20836c str r12, [sp, #0x18]
 *   @0x208370 ldr r1, [r4, #0x4]
 *   @0x208374 cmp r10, r1
 *   @0x208378 bge 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x20837c ldr r2, [r4, #0x8]
 *   @0x208380 cmp r8, r2
 *   @0x208384 bge 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x208388 ldr r2, [r9, #0x4]
 *   @0x20838c cmp r2, r11
 *   @0x208390 ble 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x208394 ldr r0, [r9, #0x8]
 *   @0x208398 cmp r0, r5
 *   @0x20839c ble 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x2083a0 cmp r8, #0
 *   @0x2083a4 movlt r0, #0
 *   @0x2083a8 andge r0, r3, #1
 *   @0x2083ac cmp r0, #0
 *   @0x2083b0 beq 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x2083b4 ldr r0, [sp, #0x18]
 *   @0x2083b8 cmp r5, #0
 *   @0x2083bc movlt r0, #0
 *   @0x2083c0 andge r0, r0, #1
 *   @0x2083c4 cmp r0, #0
 *   @0x2083c8 bne 0x208558 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x570>
 *   @0x2083cc sub r5, r5, #1
 *   @0x2083d0 sub r8, r8, #1
 *   @0x2083d4 cmp r6, r5
 *   @0x2083d8 ble 0x208370 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x388>
 *   @0x2083dc ldr r3, [sp, #0x10]
 *   @0x2083e0 sub r11, r11, #1
 *   @0x2083e4 sub r10, r10, #1
 *   @0x2083e8 cmp r3, r11
 *   @0x2083ec ble 0x20834c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x364>
 *   @0x2083f0 add sp, sp, #44
 *   @0x2083f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2083f8 ldr r0, [sp, #0x5c]
 *   @0x2083fc ldr r1, [sp, #0x1c]
 *   @0x208400 cmp r3, r0
 *   @0x208404 movge r3, #0
 *   @0x208408 movlt r3, #1
 *   @0x20840c tst r1, r3
 *   @0x208410 str r3, [sp, #0x20]
 *   @0x208414 beq 0x208454 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x46c>
 *   @0x208418 ldr r3, [sp, #0x10]
 *   @0x20841c cmp r3, r12
 *   @0x208420 ble 0x20822c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x244>
 *   @0x208424 ldr r3, [sp, #0x60]
 *   @0x208428 cmp r6, r3
 *   @0x20842c movge r3, #0
 *   @0x208430 movlt r3, #1
 *   @0x208434 str r3, [sp, #0x1c]
 *   @0x208438 b 0x20830c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x324>
 *   @0x20843c ldr r3, [sp, #0x10]
 *   @0x208440 ldr r0, [sp, #0x5c]
 *   @0x208444 cmp r3, r0
 *   @0x208448 movge r3, #0
 *   @0x20844c movlt r3, #1
 *   @0x208450 str r3, [sp, #0x20]
 *   @0x208454 ldr r3, [sp, #0x60]
 *   @0x208458 ldr r0, [sp, #0x18]
 *   @0x20845c cmp r6, r3
 *   @0x208460 movge r3, #0
 *   @0x208464 movlt r3, #1
 *   @0x208468 tst r0, r3
 *   @0x20846c str r3, [sp, #0x1c]
 *   @0x208470 beq 0x20830c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x324>
 *   @0x208474 ldr r3, [sp, #0x10]
 *   @0x208478 cmp r3, r12
 *   @0x20847c bgt 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408>
 *   @0x208480 ldr r0, [sp, #0x60]
 *   @0x208484 ldr r10, [sp, #0x5c]
 *   @0x208488 ldr r11, [sp, #0x10]
 *   @0x20848c add r3, r0, r7
 *   @0x208490 rsb r3, r6, r3
 *   @0x208494 str r12, [sp, #0x14]
 *   @0x208498 str r3, [sp, #0x18]
 *   @0x20849c cmp r6, r7
 *   @0x2084a0 bgt 0x20852c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x544>
 *   @0x2084a4 mvn r3, r10
 *   @0x2084a8 ldr r8, [sp, #0x18]
 *   @0x2084ac lsr r3, r3, #31
 *   @0x2084b0 mvn r12, r11
 *   @0x2084b4 mov r5, r7
 *   @0x2084b8 lsr r12, r12, #31
 *   @0x2084bc str r12, [sp]
 *   @0x2084c0 ldr r1, [r4, #0x4]
 *   @0x2084c4 cmp r10, r1
 *   @0x2084c8 bge 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x2084cc ldr r2, [r4, #0x8]
 *   @0x2084d0 cmp r8, r2
 *   @0x2084d4 bge 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x2084d8 ldr r2, [r9, #0x4]
 *   @0x2084dc cmp r2, r11
 *   @0x2084e0 ble 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x2084e4 ldr r0, [r9, #0x8]
 *   @0x2084e8 cmp r0, r5
 *   @0x2084ec ble 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x2084f0 cmp r8, #0
 *   @0x2084f4 movlt r0, #0
 *   @0x2084f8 andge r0, r3, #1
 *   @0x2084fc cmp r0, #0
 *   @0x208500 beq 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x208504 ldr r0, [sp]
 *   @0x208508 cmp r5, #0
 *   @0x20850c movlt r0, #0
 *   @0x208510 andge r0, r0, #1
 *   @0x208514 cmp r0, #0
 *   @0x208518 bne 0x2085a8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x5c0>
 *   @0x20851c sub r5, r5, #1
 *   @0x208520 sub r8, r8, #1
 *   @0x208524 cmp r6, r5
 *   @0x208528 ble 0x2084c0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x4d8>
 *   @0x20852c ldr r3, [sp, #0x14]
 *   @0x208530 add r11, r11, #1
 *   @0x208534 add r10, r10, #1
 *   @0x208538 cmp r3, r11
 *   @0x20853c bge 0x20849c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x4b4>
 *   @0x208540 ldr r3, [sp, #0x20]
 *   @0x208544 ldr r0, [sp, #0x1c]
 *   @0x208548 ldr r12, [sp, #0x14]
 *   @0x20854c tst r3, r0
 *   @0x208550 bne 0x208328 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x340>
 *   @0x208554 b 0x2083f0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x408>
 *   @0x208558 mla r2, r2, r5, r11
 *   @0x20855c ldr lr, [r4]
 *   @0x208560 mla r1, r1, r8, r10
 *   @0x208564 ldr r12, [r9]
 *   @0x208568 ldr r0, [sp, #0x24]
 *   @0x20856c str r3, [sp, #0x8]
 *   @0x208570 str r2, [sp, #0x14]
 *   @0x208574 add r2, r12, r2, lsl #4
 *   @0x208578 add r1, lr, r1, lsl #4
 *   @0x20857c bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x208580 ldr r3, [sp, #0x8]
 *   @0x208584 b 0x2083cc <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x3e4>
 *   @0x208588 ldr r7, [r9, #0x8]
 *   @0x20858c mov r6, r1
 *   @0x208590 mov r3, r2
 *   @0x208594 b 0x20807c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x94>
 *   @0x208598 ldr r0, [r9, #0x4]
 *   @0x20859c mov r5, r12
 *   @0x2085a0 str r3, [sp, #0x10]
 *   @0x2085a4 b 0x20803c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x54>
 *   @0x2085a8 mla r2, r2, r5, r11
 *   @0x2085ac ldr lr, [r4]
 *   @0x2085b0 mla r1, r1, r8, r10
 *   @0x2085b4 ldr r12, [r9]
 *   @0x2085b8 ldr r0, [sp, #0x24]
 *   @0x2085bc str r3, [sp, #0x8]
 *   @0x2085c0 str r2, [sp, #0xc]
 *   @0x2085c4 add r2, r12, r2, lsl #4
 *   @0x2085c8 add r1, lr, r1, lsl #4
 *   @0x2085cc bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x2085d0 ldr r3, [sp, #0x8]
 *   @0x2085d4 b 0x20851c <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x534>
 *   @0x2085d8 mla r2, r2, r5, r11
 *   @0x2085dc ldr lr, [r4]
 *   @0x2085e0 mla r1, r1, r8, r10
 *   @0x2085e4 ldr r12, [r9]
 *   @0x2085e8 ldr r0, [sp, #0x24]
 *   @0x2085ec str r3, [sp, #0x8]
 *   @0x2085f0 str r2, [sp, #0xc]
 *   @0x2085f4 add r2, r12, r2, lsl #4
 *   @0x2085f8 add r1, lr, r1, lsl #4
 *   @0x2085fc bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x208600 ldr r3, [sp, #0x8]
 *   @0x208604 b 0x2081e0 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x1f8>
 *   @0x208608 mla r2, r2, r5, r11
 *   @0x20860c ldr lr, [r4]
 *   @0x208610 mla r1, r1, r8, r10
 *   @0x208614 ldr r12, [r9]
 *   @0x208618 ldr r0, [sp, #0x24]
 *   @0x20861c str r3, [sp, #0x8]
 *   @0x208620 str r2, [sp, #0xc]
 *   @0x208624 add r2, r12, r2, lsl #4
 *   @0x208628 add r1, lr, r1, lsl #4
 *   @0x20862c bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x208630 ldr r3, [sp, #0x8]
 *   @0x208634 b 0x2082c4 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii+0x2dc>
 *
 * ══ §14/20 JS_DefineOwnProperty_Internal(YYObjectBase*, char const*, RValue*, bool)  0x247d44  size 1616  404 条（0x247d44..0x248394）
 * @func 0x247d44 0x248394  size 1616  404 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / PopContextStack()×5 / JS_IsDataDescriptor(RValue*)×4 / PushContextStack(YYObjectBase*)×3 / JS_SameValue(RValue*, RValue*)×2
 * 字段偏移 top8: 0x8×21 / 0x4×15 / 0xc×14 / 0x28×1 / 0x124×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x247d44 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x247d48 sub sp, sp, #16
 *   @0x247d4c mov r9, r3
 *   @0x247d50 mov r8, r1
 *   @0x247d54 mov r4, r0
 *   @0x247d58 mov r6, r2
 *   @0x247d5c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x247d60 mov r12, #0
 *   @0x247d64 cmp r9, r12
 *   @0x247d68 mov r0, r4
 *   @0x247d6c mov r2, r8
 *   @0x247d70 mov r1, sp
 *   @0x247d74 mvn r5, #-16777216
 *   @0x247d78 moveq r9, r12
 *   @0x247d7c str r12, [sp, #0x8]
 *   @0x247d80 movne r9, #2
 *   @0x247d84 str r12, [sp, #0x4]
 *   @0x247d88 str r12, [sp]
 *   @0x247d8c str r5, [sp, #0xc]
 *   @0x247d90 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x247d94 ldr r12, [sp, #0xc]
 *   @0x247d98 ldr r3, [r4, #0x28]
 *   @0x247d9c and r12, r12, r5
 *   @0x247da0 cmp r12, #5
 *   @0x247da4 cmpne r12, r5
 *   @0x247da8 bne 0x247dc8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x84>
 *   @0x247dac tst r3, #1
 *   @0x247db0 bne 0x247f50 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x20c>
 *   @0x247db4 mov r4, r9
 *   @0x247db8 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x247dbc mov r0, r4
 *   @0x247dc0 add sp, sp, #16
 *   @0x247dc4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x247dc8 ldr r3, [r6, #0xc]
 *   @0x247dcc bic r3, r3, #-16777216
 *   @0x247dd0 cmp r3, r5
 *   @0x247dd4 beq 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8>
 *   @0x247dd8 mov r0, sp
 *   @0x247ddc mov r1, r6
 *   @0x247de0 bl 0x24089c <_Z12JS_SameValueP6RValueS0_>
 *   @0x247de4 ldr r2, [sp, #0x8]
 *   @0x247de8 ldr r5, [r6, #0x8]
 *   @0x247dec cmp r0, #0
 *   @0x247df0 beq 0x247dfc <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xb8>
 *   @0x247df4 cmp r2, r5
 *   @0x247df8 beq 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8>
 *   @0x247dfc tst r2, #2
 *   @0x247e00 bne 0x247e14 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xd0>
 *   @0x247e04 tst r5, #2
 *   @0x247e08 bne 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70>
 *   @0x247e0c tst r5, #1
 *   @0x247e10 bne 0x248058 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x314>
 *   @0x247e14 mov r0, r6
 *   @0x247e18 bl 0x240858 <_Z22JS_IsGenericDescriptorP6RValue>
 *   @0x247e1c cmp r0, #0
 *   @0x247e20 bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114>
 *   @0x247e24 mov r0, sp
 *   @0x247e28 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x247e2c mov r10, r0
 *   @0x247e30 mov r0, r6
 *   @0x247e34 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x247e38 cmp r10, r0
 *   @0x247e3c beq 0x248254 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x510>
 *   @0x247e40 ldr r3, [sp, #0x8]
 *   @0x247e44 tst r3, #2
 *   @0x247e48 beq 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70>
 *   @0x247e4c mvn r3, r3, lsl #30
 *   @0x247e50 mvn r3, r3, lsr #30
 *   @0x247e54 and r5, r5, r3
 *   @0x247e58 mov r0, r4
 *   @0x247e5c mov r1, r8
 *   @0x247e60 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x247e64 cmp r0, #0
 *   @0x247e68 blt 0x247f28 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1e4>
 *   @0x247e6c ldr r3, [r4, #0x4]
 *   @0x247e70 cmp r3, #0
 *   @0x247e74 beq 0x248274 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x530>
 *   @0x247e78 add r7, r3, r0, lsl #4
 *   @0x247e7c mov r0, r4
 *   @0x247e80 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x247e84 ldr r2, [r7, #0xc]
 *   @0x247e88 bic r3, r2, #-16777216
 *   @0x247e8c cmp r3, #1
 *   @0x247e90 beq 0x248184 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x440>
 *   @0x247e94 cmp r3, #2
 *   @0x247e98 bne 0x247ec0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x17c>
 *   @0x247e9c sub r3, r2, #1
 *   @0x247ea0 bic r3, r3, #-16777216
 *   @0x247ea4 bic r3, r3, #3
 *   @0x247ea8 cmp r3, #0
 *   @0x247eac beq 0x248234 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4f0>
 *   @0x247eb0 mov r2, #0
 *   @0x247eb4 mov r3, #5
 *   @0x247eb8 str r2, [r7, #0x8]
 *   @0x247ebc str r3, [r7, #0xc]
 *   @0x247ec0 ldr r3, [r6, #0xc]
 *   @0x247ec4 mov r1, #0
 *   @0x247ec8 ldr r2, [r6, #0x8]
 *   @0x247ecc str r1, [r7]
 *   @0x247ed0 str r3, [r7, #0xc]
 *   @0x247ed4 ldr r3, [r6, #0xc]
 *   @0x247ed8 str r2, [r7, #0x8]
 *   @0x247edc bic r3, r3, #-16777216
 *   @0x247ee0 cmp r3, #14
 *   @0x247ee4 addls pc, pc, r3, lsl #2
 *   @0x247ee8 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247eec b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330>
 *   @0x247ef0 b 0x24810c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3c8>
 *   @0x247ef4 b 0x248124 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3e0>
 *   @0x247ef8 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc>
 *   @0x247efc b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f00 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f04 b 0x2480e8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x3a4>
 *   @0x247f08 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc>
 *   @0x247f0c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f10 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f14 b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330>
 *   @0x247f18 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f1c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x247f20 b 0x248074 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x330>
 *   @0x247f24 b 0x248040 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2fc>
 *   @0x247f28 mov r0, r4
 *   @0x247f2c mov r1, r8
 *   @0x247f30 mov r2, r6
 *   @0x247f34 mov r3, r5
 *   @0x247f38 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x247f3c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x247f40 mov r4, #1
 *   @0x247f44 mov r0, r4
 *   @0x247f48 add sp, sp, #16
 *   @0x247f4c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x247f50 mov r1, r8
 *   @0x247f54 mov r0, r4
 *   @0x247f58 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x247f5c subs r5, r0, #0
 *   @0x247f60 blt 0x247f3c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x1f8>
 *   @0x247f64 mov r0, r4
 *   @0x247f68 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x247f6c ldr r3, [r4, #0x4]
 *   @0x247f70 cmp r3, #0
 *   @0x247f74 beq 0x248240 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4fc>
 *   @0x247f78 add r4, r3, r5, lsl #4
 *   @0x247f7c ldr r2, [r4, #0xc]
 *   @0x247f80 bic r3, r2, #-16777216
 *   @0x247f84 cmp r3, #1
 *   @0x247f88 beq 0x248150 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x40c>
 *   @0x247f8c cmp r3, #2
 *   @0x247f90 bne 0x247fb8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x274>
 *   @0x247f94 sub r3, r2, #1
 *   @0x247f98 bic r3, r3, #-16777216
 *   @0x247f9c bic r3, r3, #3
 *   @0x247fa0 cmp r3, #0
 *   @0x247fa4 beq 0x2481f0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4ac>
 *   @0x247fa8 mov r2, #0
 *   @0x247fac mov r3, #5
 *   @0x247fb0 str r2, [r4, #0x8]
 *   @0x247fb4 str r3, [r4, #0xc]
 *   @0x247fb8 ldr r3, [r6, #0xc]
 *   @0x247fbc mov r1, #0
 *   @0x247fc0 ldr r2, [r6, #0x8]
 *   @0x247fc4 str r1, [r4]
 *   @0x247fc8 str r3, [r4, #0xc]
 *   @0x247fcc ldr r3, [r6, #0xc]
 *   @0x247fd0 str r2, [r4, #0x8]
 *   @0x247fd4 bic r3, r3, #-16777216
 *   @0x247fd8 cmp r3, #14
 *   @0x247fdc addls pc, pc, r3, lsl #2
 *   @0x247fe0 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x247fe4 b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324>
 *   @0x247fe8 b 0x2480ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x368>
 *   @0x247fec b 0x248080 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x33c>
 *   @0x247ff0 b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc>
 *   @0x247ff4 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x247ff8 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x247ffc b 0x2480c4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x380>
 *   @0x248000 b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc>
 *   @0x248004 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x248008 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x24800c b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324>
 *   @0x248010 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x248014 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x248018 b 0x248068 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x324>
 *   @0x24801c b 0x248020 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2dc>
 *   @0x248020 ldr r3, [r6]
 *   @0x248024 str r3, [r4]
 *   @0x248028 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x24802c mov r4, #1
 *   @0x248030 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x248034 mov r0, r4
 *   @0x248038 add sp, sp, #16
 *   @0x24803c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x248040 ldr r3, [r6]
 *   @0x248044 str r3, [r7]
 *   @0x248048 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x24804c mov r4, #1
 *   @0x248050 str r5, [r7, #0x8]
 *   @0x248054 b 0x247db8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x74>
 *   @0x248058 eor r2, r2, r5
 *   @0x24805c tst r2, #1
 *   @0x248060 beq 0x247e14 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0xd0>
 *   @0x248064 b 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70>
 *   @0x248068 ldm r6, {r2, r3}
 *   @0x24806c stm r4, {r2, r3}
 *   @0x248070 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x248074 ldm r6, {r2, r3}
 *   @0x248078 stm r7, {r2, r3}
 *   @0x24807c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x248080 ldr r3, [r6]
 *   @0x248084 cmp r3, #0
 *   @0x248088 str r3, [r4]
 *   @0x24808c beq 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x248090 ldr r1, [r3, #0x8]
 *   @0x248094 ldr r2, [r3]
 *   @0x248098 cmp r1, #0
 *   @0x24809c streq r4, [r3, #0x8]
 *   @0x2480a0 add r2, r2, #1
 *   @0x2480a4 str r2, [r3]
 *   @0x2480a8 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x2480ac ldr r3, [r6]
 *   @0x2480b0 cmp r3, #0
 *   @0x2480b4 ldrne r2, [r3, #0x4]
 *   @0x2480b8 addne r2, r2, #1
 *   @0x2480bc strne r2, [r3, #0x4]
 *   @0x2480c0 b 0x248024 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e0>
 *   @0x2480c4 ldr r3, [r6]
 *   @0x2480c8 str r3, [r4]
 *   @0x2480cc ldr r3, [r6]
 *   @0x2480d0 cmp r3, #0
 *   @0x2480d4 beq 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x2480d8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2480dc ldr r1, [r6]
 *   @0x2480e0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2480e4 b 0x248028 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x2e4>
 *   @0x2480e8 ldr r3, [r6]
 *   @0x2480ec str r3, [r7]
 *   @0x2480f0 ldr r3, [r6]
 *   @0x2480f4 cmp r3, #0
 *   @0x2480f8 beq 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x2480fc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x248100 ldr r1, [r6]
 *   @0x248104 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x248108 b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x24810c ldr r3, [r6]
 *   @0x248110 cmp r3, #0
 *   @0x248114 ldrne r2, [r3, #0x4]
 *   @0x248118 addne r2, r2, #1
 *   @0x24811c strne r2, [r3, #0x4]
 *   @0x248120 b 0x248044 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x300>
 *   @0x248124 ldr r3, [r6]
 *   @0x248128 cmp r3, #0
 *   @0x24812c str r3, [r7]
 *   @0x248130 beq 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x248134 ldr r1, [r3, #0x8]
 *   @0x248138 ldr r2, [r3]
 *   @0x24813c cmp r1, #0
 *   @0x248140 streq r7, [r3, #0x8]
 *   @0x248144 add r2, r2, #1
 *   @0x248148 str r2, [r3]
 *   @0x24814c b 0x248048 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x304>
 *   @0x248150 ldr r5, [r4]
 *   @0x248154 cmp r5, #0
 *   @0x248158 beq 0x248178 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x434>
 *   @0x24815c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248160 ldr r7, [r5, #0x4]
 *   @0x248164 sub r7, r7, #1
 *   @0x248168 str r7, [r5, #0x4]
 *   @0x24816c cmp r7, #0
 *   @0x248170 beq 0x2481b8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x474>
 *   @0x248174 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248178 mov r3, #0
 *   @0x24817c str r3, [r4]
 *   @0x248180 b 0x247fb8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x274>
 *   @0x248184 ldr r4, [r7]
 *   @0x248188 cmp r4, #0
 *   @0x24818c beq 0x2481ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x468>
 *   @0x248190 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248194 ldr r8, [r4, #0x4]
 *   @0x248198 sub r8, r8, #1
 *   @0x24819c str r8, [r4, #0x4]
 *   @0x2481a0 cmp r8, #0
 *   @0x2481a4 beq 0x2481fc <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4b8>
 *   @0x2481a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2481ac mov r3, #0
 *   @0x2481b0 str r3, [r7]
 *   @0x2481b4 b 0x247ec0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x17c>
 *   @0x2481b8 ldr r0, [r5]
 *   @0x2481bc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2481c0 str r7, [r5]
 *   @0x2481c4 str r7, [r5, #0x8]
 *   @0x2481c8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2481cc ldr r7, [r5, #0x4]
 *   @0x2481d0 sub r7, r7, #1
 *   @0x2481d4 str r7, [r5, #0x4]
 *   @0x2481d8 cmp r7, #0
 *   @0x2481dc beq 0x248288 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x544>
 *   @0x2481e0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2481e4 mov r0, r5
 *   @0x2481e8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2481ec b 0x248174 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x430>
 *   @0x2481f0 mov r0, r4
 *   @0x2481f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2481f8 b 0x247fa8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x264>
 *   @0x2481fc ldr r0, [r4]
 *   @0x248200 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248204 str r8, [r4]
 *   @0x248208 str r8, [r4, #0x8]
 *   @0x24820c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248210 ldr r8, [r4, #0x4]
 *   @0x248214 sub r8, r8, #1
 *   @0x248218 str r8, [r4, #0x4]
 *   @0x24821c cmp r8, #0
 *   @0x248220 beq 0x2482ac <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x568>
 *   @0x248224 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248228 mov r0, r4
 *   @0x24822c bl 0x27d1d0 <_ZdlPv>
 *   @0x248230 b 0x2481a8 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x464>
 *   @0x248234 mov r0, r7
 *   @0x248238 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24823c b 0x247eb0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x16c>
 *   @0x248240 mov r0, r4
 *   @0x248244 mov r1, r5
 *   @0x248248 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24824c mov r4, r0
 *   @0x248250 b 0x247f7c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x238>
 *   @0x248254 mov r0, sp
 *   @0x248258 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x24825c cmp r0, #0
 *   @0x248260 bne 0x2482e4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x5a0>
 *   @0x248264 ldr r0, [pc, #0x124]
 *   @0x248268 add r0, pc, r0
 *   @0x24826c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x248270 b 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114>
 *   @0x248274 mov r1, r0
 *   @0x248278 mov r0, r4
 *   @0x24827c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x248280 mov r7, r0
 *   @0x248284 b 0x247e7c <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x138>
 *   @0x248288 ldr r0, [r5]
 *   @0x24828c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248290 mov r0, r5
 *   @0x248294 str r7, [r5]
 *   @0x248298 str r7, [r5, #0x8]
 *   @0x24829c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2482a0 mov r0, r5
 *   @0x2482a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2482a8 b 0x2481e0 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x49c>
 *   @0x2482ac ldr r0, [r4]
 *   @0x2482b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2482b4 str r8, [r4]
 *   @0x2482b8 str r8, [r4, #0x8]
 *   @0x2482bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2482c0 ldr r8, [r4, #0x4]
 *   @0x2482c4 sub r8, r8, #1
 *   @0x2482c8 str r8, [r4, #0x4]
 *   @0x2482cc cmp r8, #0
 *   @0x2482d0 beq 0x248338 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x5f4>
 *   @0x2482d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2482d8 mov r0, r4
 *   @0x2482dc bl 0x27d1d0 <_ZdlPv>
 *   @0x2482e0 b 0x248224 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x4e0>
 *   @0x2482e4 mov r0, r6
 *   @0x2482e8 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x2482ec cmp r0, #0
 *   @0x2482f0 beq 0x248264 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x520>
 *   @0x2482f4 ldr r3, [sp, #0x8]
 *   @0x2482f8 tst r3, #6
 *   @0x2482fc bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114>
 *   @0x248300 ldr r3, [r6, #0x8]
 *   @0x248304 tst r3, #4
 *   @0x248308 bne 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70>
 *   @0x24830c ldr r2, [r6, #0xc]
 *   @0x248310 mvn r3, #-16777216
 *   @0x248314 and r2, r2, r3
 *   @0x248318 cmp r2, r3
 *   @0x24831c beq 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114>
 *   @0x248320 mov r0, sp
 *   @0x248324 mov r1, r6
 *   @0x248328 bl 0x24089c <_Z12JS_SameValueP6RValueS0_>
 *   @0x24832c cmp r0, #0
 *   @0x248330 bne 0x247e58 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x114>
 *   @0x248334 b 0x247db4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x70>
 *   @0x248338 ldr r0, [r4]
 *   @0x24833c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248340 str r8, [r4]
 *   @0x248344 str r8, [r4, #0x8]
 *   @0x248348 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24834c ldr r8, [r4, #0x4]
 *   @0x248350 sub r8, r8, #1
 *   @0x248354 str r8, [r4, #0x4]
 *   @0x248358 cmp r8, #0
 *   @0x24835c bne 0x248380 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x63c>
 *   @0x248360 ldr r0, [r4]
 *   @0x248364 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248368 mov r0, r4
 *   @0x24836c str r8, [r4]
 *   @0x248370 str r8, [r4, #0x8]
 *   @0x248374 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x248378 mov r0, r4
 *   @0x24837c bl 0x27d1d0 <_ZdlPv>
 *   @0x248380 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248384 mov r0, r4
 *   @0x248388 bl 0x27d1d0 <_ZdlPv>
 *   @0x24838c b 0x2482d4 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb+0x590>
 *   @0x248390 ldrheq sp, [r0], -r8
 *
 * ══ §15/20 C3D_Model::Draw(float, float, float, int)  0x1649ac  size 1612  403 条（0x1649ac..0x164ff8）
 * @func 0x1649ac 0x164ff8  size 1612  403 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x164a14→0x48fff4, 0x164a1c→0x3f23d0, 0x164a88→0x48ffec, 0x164b70→0x3f23d0, 0x164c28→0x48ffec
 * 调用序列: operator new(unsigned int) / C3D_Model::Draw(float, float, float, int)+0x254 / C3D_Model::Draw(float, float, float, int)+0x26c / GraphicsRecorder::ChangeColour(unsigned int) / GR_3D_Draw_Floor(float, float, float, float, float, float, int, float, float) / GR_Texture_Exists(int) / GraphicsRecorder::~GraphicsRecorder() / operator delete(void*)
 * 字段偏移 top8: 0x4×30 / 0xc×29 / 0x8×28 / 0x10×27 / 0x14×22 / 0x18×14 / 0x1c×11 / 0x20×10
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1649ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1649b0 mov r7, r1
 *   @0x1649b4 ldr r1, [r0, #0xc]
 *   @0x1649b8 sub sp, sp, #44
 *   @0x1649bc ldr r10, [pc, #0x624]
 *   @0x1649c0 mov r6, r0
 *   @0x1649c4 cmp r1, #0
 *   @0x1649c8 mov r8, r2
 *   @0x1649cc add r10, pc, r10
 *   @0x1649d0 mov r9, r3
 *   @0x1649d4 ldr r5, [sp, #0x50]
 *   @0x1649d8 beq 0x164a0c <_ZN9C3D_Model4DrawEfffi+0x60>
 *   @0x1649dc ldr r3, [r1, #0xc]
 *   @0x1649e0 ldr r4, [r1]
 *   @0x1649e4 cmp r3, r5
 *   @0x1649e8 bne 0x164a04 <_ZN9C3D_Model4DrawEfffi+0x58>
 *   @0x1649ec b 0x164b50 <_ZN9C3D_Model4DrawEfffi+0x1a4>
 *   @0x1649f0 ldr r3, [r4, #0xc]
 *   @0x1649f4 ldr r2, [r4]
 *   @0x1649f8 cmp r3, r5
 *   @0x1649fc beq 0x164b54 <_ZN9C3D_Model4DrawEfffi+0x1a8>
 *   @0x164a00 mov r4, r2
 *   @0x164a04 cmp r4, #0
 *   @0x164a08 bne 0x1649f0 <_ZN9C3D_Model4DrawEfffi+0x44>
 *   @0x164a0c mov r0, #68
 *   @0x164a10 bl 0x27c524 <_Znwj>
 *   @0x164a14 ldr r1, [pc, #0x5d0]
 *   @0x164a18 mov r3, #0
 *   @0x164a1c ldr r2, [pc, #0x5cc]
 *   @0x164a20 cmn r5, #1
 *   @0x164a24 str r3, [r0]
 *   @0x164a28 mov r4, r0
 *   @0x164a2c str r3, [r0, #0x4]
 *   @0x164a30 str r3, [r0, #0x34]
 *   @0x164a34 str r3, [r0, #0x24]
 *   @0x164a38 str r3, [r0, #0x14]
 *   @0x164a3c str r3, [r0, #0x3c]
 *   @0x164a40 str r3, [r0, #0x2c]
 *   @0x164a44 str r3, [r0, #0x1c]
 *   @0x164a48 str r3, [r0, #0x10]
 *   @0x164a4c str r3, [r0, #0x38]
 *   @0x164a50 str r3, [r0, #0x28]
 *   @0x164a54 str r3, [r0, #0x18]
 *   @0x164a58 str r3, [r0, #0x40]
 *   @0x164a5c str r3, [r0, #0x30]
 *   @0x164a60 str r3, [r0, #0x20]
 *   @0x164a64 ldr r3, [r10, r1]
 *   @0x164a68 str r0, [r3]
 *   @0x164a6c str r3, [sp, #0x24]
 *   @0x164a70 ldr r3, [r10, r2]
 *   @0x164a74 str r5, [r0, #0xc]
 *   @0x164a78 ldr r3, [r3]
 *   @0x164a7c bic r3, r3, #1
 *   @0x164a80 str r3, [r0, #0x8]
 *   @0x164a84 beq 0x164ab4 <_ZN9C3D_Model4DrawEfffi+0x108>
 *   @0x164a88 ldr r3, [pc, #0x564]
 *   @0x164a8c cmp r5, #16384
 *   @0x164a90 ldrshhi r2, [r5, #20]
 *   @0x164a94 ldrhi r3, [r10, r3]
 *   @0x164a98 ldrls r3, [r10, r3]
 *   @0x164a9c ldrhi r3, [r3, #0x4]
 *   @0x164aa0 ldrls r3, [r3, #0x4]
 *   @0x164aa4 ldrhi r3, [r3, r2, lsl #2]
 *   @0x164aa8 ldrls r3, [r3, r5, lsl #2]
 *   @0x164aac ldr r3, [r3]
 *   @0x164ab0 str r3, [r4, #0x10]
 *   @0x164ab4 ldr r3, [r6, #0x10]
 *   @0x164ab8 ldr r2, [r6, #0x14]
 *   @0x164abc cmp r3, #0
 *   @0x164ac0 add r2, r2, #1
 *   @0x164ac4 str r2, [r6, #0x14]
 *   @0x164ac8 beq 0x164fd4 <_ZN9C3D_Model4DrawEfffi+0x628>
 *   @0x164acc str r4, [r3]
 *   @0x164ad0 mov r3, #0
 *   @0x164ad4 ldr r2, [r6, #0x10]
 *   @0x164ad8 str r2, [r4, #0x4]
 *   @0x164adc str r4, [r6, #0x10]
 *   @0x164ae0 str r3, [r4]
 *   @0x164ae4 ldr r2, [r6]
 *   @0x164ae8 cmp r2, #0
 *   @0x164aec movgt r10, #0
 *   @0x164af0 movgt r11, r10
 *   @0x164af4 ble 0x164c00 <_ZN9C3D_Model4DrawEfffi+0x254>
 *   @0x164af8 ldr r3, [r6, #0x8]
 *   @0x164afc ldr r12, [r3, r11, lsl #2]
 *   @0x164b00 ldr r3, [r12]
 *   @0x164b04 cmp r3, #15
 *   @0x164b08 addls pc, pc, r3, lsl #2
 *   @0x164b0c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164b10 b 0x164fa8 <_ZN9C3D_Model4DrawEfffi+0x5fc>
 *   @0x164b14 b 0x164f9c <_ZN9C3D_Model4DrawEfffi+0x5f0>
 *   @0x164b18 b 0x164f80 <_ZN9C3D_Model4DrawEfffi+0x5d4>
 *   @0x164b1c b 0x164f5c <_ZN9C3D_Model4DrawEfffi+0x5b0>
 *   @0x164b20 b 0x164f34 <_ZN9C3D_Model4DrawEfffi+0x588>
 *   @0x164b24 b 0x164f00 <_ZN9C3D_Model4DrawEfffi+0x554>
 *   @0x164b28 b 0x164ed0 <_ZN9C3D_Model4DrawEfffi+0x524>
 *   @0x164b2c b 0x164e94 <_ZN9C3D_Model4DrawEfffi+0x4e8>
 *   @0x164b30 b 0x164e54 <_ZN9C3D_Model4DrawEfffi+0x4a8>
 *   @0x164b34 b 0x164e08 <_ZN9C3D_Model4DrawEfffi+0x45c>
 *   @0x164b38 b 0x164dc4 <_ZN9C3D_Model4DrawEfffi+0x418>
 *   @0x164b3c b 0x164d70 <_ZN9C3D_Model4DrawEfffi+0x3c4>
 *   @0x164b40 b 0x164d1c <_ZN9C3D_Model4DrawEfffi+0x370>
 *   @0x164b44 b 0x164cd0 <_ZN9C3D_Model4DrawEfffi+0x324>
 *   @0x164b48 b 0x164c8c <_ZN9C3D_Model4DrawEfffi+0x2e0>
 *   @0x164b4c b 0x164bac <_ZN9C3D_Model4DrawEfffi+0x200>
 *   @0x164b50 mov r4, r1
 *   @0x164b54 cmn r5, #1
 *   @0x164b58 beq 0x164b64 <_ZN9C3D_Model4DrawEfffi+0x1b8>
 *   @0x164b5c cmp r5, #16384
 *   @0x164b60 bls 0x164c18 <_ZN9C3D_Model4DrawEfffi+0x26c>
 *   @0x164b64 ldr r3, [r4, #0x8]
 *   @0x164b68 cmp r3, #1
 *   @0x164b6c beq 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4>
 *   @0x164b70 ldr r2, [pc, #0x478]
 *   @0x164b74 ldr r2, [r10, r2]
 *   @0x164b78 ldr r1, [r2]
 *   @0x164b7c bic r2, r1, #1
 *   @0x164b80 cmp r3, r2
 *   @0x164b84 beq 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4>
 *   @0x164b88 mov r0, r4
 *   @0x164b8c bl 0x189120 <_ZN16GraphicsRecorder12ChangeColourEj>
 *   @0x164b90 mov r0, r4
 *   @0x164b94 mov r1, r7
 *   @0x164b98 mov r2, r8
 *   @0x164b9c mov r3, r9
 *   @0x164ba0 add sp, sp, #44
 *   @0x164ba4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x164ba8 b 0x185a24 <_ZN16GraphicsRecorder4DrawEfff>
 *   @0x164bac ldr lr, [r12, #0x14]
 *   @0x164bb0 mov r10, #1
 *   @0x164bb4 ldr r2, [r12, #0xc]
 *   @0x164bb8 ldr r0, [r12, #0x4]
 *   @0x164bbc ldr r1, [r12, #0x8]
 *   @0x164bc0 ldr r3, [r12, #0x10]
 *   @0x164bc4 str lr, [sp]
 *   @0x164bc8 ldr lr, [r12, #0x18]
 *   @0x164bcc str r5, [sp, #0x8]
 *   @0x164bd0 str lr, [sp, #0x4]
 *   @0x164bd4 ldr lr, [r12, #0x1c]
 *   @0x164bd8 str lr, [sp, #0xc]
 *   @0x164bdc ldr r12, [r12, #0x20]
 *   @0x164be0 str r12, [sp, #0x10]
 *   @0x164be4 bl 0x179834 <_Z16GR_3D_Draw_Floorffffffiff>
 *   @0x164be8 ldr r2, [r6]
 *   @0x164bec add r11, r11, #1
 *   @0x164bf0 cmp r2, r11
 *   @0x164bf4 bgt 0x164af8 <_ZN9C3D_Model4DrawEfffi+0x14c>
 *   @0x164bf8 cmp r10, #0
 *   @0x164bfc bne 0x164c08 <_ZN9C3D_Model4DrawEfffi+0x25c>
 *   @0x164c00 mov r3, #0
 *   @0x164c04 str r3, [r4, #0x8]
 *   @0x164c08 ldr r2, [sp, #0x24]
 *   @0x164c0c mov r3, #0
 *   @0x164c10 str r3, [r2]
 *   @0x164c14 b 0x164b90 <_ZN9C3D_Model4DrawEfffi+0x1e4>
 *   @0x164c18 mov r0, r5
 *   @0x164c1c bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x164c20 cmp r0, #0
 *   @0x164c24 beq 0x164c48 <_ZN9C3D_Model4DrawEfffi+0x29c>
 *   @0x164c28 ldr r3, [pc, #0x3c4]
 *   @0x164c2c ldr r2, [r4, #0x10]
 *   @0x164c30 ldr r3, [r10, r3]
 *   @0x164c34 ldr r3, [r3, #0x4]
 *   @0x164c38 ldr r3, [r3, r5, lsl #2]
 *   @0x164c3c ldr r3, [r3]
 *   @0x164c40 cmp r2, r3
 *   @0x164c44 beq 0x164b64 <_ZN9C3D_Model4DrawEfffi+0x1b8>
 *   @0x164c48 ldr r3, [r4, #0x4]
 *   @0x164c4c cmp r3, #0
 *   @0x164c50 beq 0x164fc8 <_ZN9C3D_Model4DrawEfffi+0x61c>
 *   @0x164c54 ldr r2, [r4]
 *   @0x164c58 str r2, [r3]
 *   @0x164c5c ldm r4, {r2, r3}
 *   @0x164c60 cmp r2, #0
 *   @0x164c64 mov r0, r4
 *   @0x164c68 streq r3, [r6, #0x10]
 *   @0x164c6c strne r3, [r2, #0x4]
 *   @0x164c70 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev>
 *   @0x164c74 mov r0, r4
 *   @0x164c78 bl 0x27d1d0 <_ZdlPv>
 *   @0x164c7c ldr r3, [r6, #0x14]
 *   @0x164c80 sub r3, r3, #1
 *   @0x164c84 str r3, [r6, #0x14]
 *   @0x164c88 b 0x164a0c <_ZN9C3D_Model4DrawEfffi+0x60>
 *   @0x164c8c ldr lr, [r12, #0x14]
 *   @0x164c90 mov r10, #1
 *   @0x164c94 ldr r2, [r12, #0xc]
 *   @0x164c98 ldr r0, [r12, #0x4]
 *   @0x164c9c ldr r1, [r12, #0x8]
 *   @0x164ca0 ldr r3, [r12, #0x10]
 *   @0x164ca4 str lr, [sp]
 *   @0x164ca8 ldr lr, [r12, #0x18]
 *   @0x164cac str r5, [sp, #0x8]
 *   @0x164cb0 str lr, [sp, #0x4]
 *   @0x164cb4 ldr lr, [r12, #0x1c]
 *   @0x164cb8 str lr, [sp, #0xc]
 *   @0x164cbc ldr r12, [r12, #0x20]
 *   @0x164cc0 str r12, [sp, #0x10]
 *   @0x164cc4 bl 0x1796e0 <_Z15GR_3D_Draw_Wallffffffiff>
 *   @0x164cc8 ldr r2, [r6]
 *   @0x164ccc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164cd0 ldr lr, [r12, #0x14]
 *   @0x164cd4 mov r10, #1
 *   @0x164cd8 ldr r2, [r12, #0xc]
 *   @0x164cdc ldr r0, [r12, #0x4]
 *   @0x164ce0 ldr r1, [r12, #0x8]
 *   @0x164ce4 ldr r3, [r12, #0x10]
 *   @0x164ce8 str lr, [sp]
 *   @0x164cec ldr lr, [r12, #0x18]
 *   @0x164cf0 str r5, [sp, #0x8]
 *   @0x164cf4 str lr, [sp, #0x4]
 *   @0x164cf8 ldr lr, [r12, #0x1c]
 *   @0x164cfc str lr, [sp, #0xc]
 *   @0x164d00 ldr lr, [r12, #0x20]
 *   @0x164d04 str lr, [sp, #0x10]
 *   @0x164d08 ldr r12, [r12, #0x24]
 *   @0x164d0c str r12, [sp, #0x14]
 *   @0x164d10 bl 0x17934c <_Z20GR_3D_Draw_Ellipsoidffffffiffi>
 *   @0x164d14 ldr r2, [r6]
 *   @0x164d18 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164d1c ldr lr, [r12, #0x14]
 *   @0x164d20 mov r10, #1
 *   @0x164d24 ldr r2, [r12, #0xc]
 *   @0x164d28 ldr r0, [r12, #0x4]
 *   @0x164d2c ldr r1, [r12, #0x8]
 *   @0x164d30 ldr r3, [r12, #0x10]
 *   @0x164d34 str lr, [sp]
 *   @0x164d38 ldr lr, [r12, #0x18]
 *   @0x164d3c str r5, [sp, #0x8]
 *   @0x164d40 str lr, [sp, #0x4]
 *   @0x164d44 ldr lr, [r12, #0x1c]
 *   @0x164d48 str lr, [sp, #0xc]
 *   @0x164d4c ldr lr, [r12, #0x20]
 *   @0x164d50 str lr, [sp, #0x10]
 *   @0x164d54 ldrb lr, [r12, #0x24]
 *   @0x164d58 str lr, [sp, #0x14]
 *   @0x164d5c ldr r12, [r12, #0x28]
 *   @0x164d60 str r12, [sp, #0x18]
 *   @0x164d64 bl 0x179094 <_Z15GR_3D_Draw_Coneffffffiffbi>
 *   @0x164d68 ldr r2, [r6]
 *   @0x164d6c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164d70 ldr lr, [r12, #0x14]
 *   @0x164d74 mov r10, #1
 *   @0x164d78 ldr r2, [r12, #0xc]
 *   @0x164d7c ldr r0, [r12, #0x4]
 *   @0x164d80 ldr r1, [r12, #0x8]
 *   @0x164d84 ldr r3, [r12, #0x10]
 *   @0x164d88 str lr, [sp]
 *   @0x164d8c ldr lr, [r12, #0x18]
 *   @0x164d90 str r5, [sp, #0x8]
 *   @0x164d94 str lr, [sp, #0x4]
 *   @0x164d98 ldr lr, [r12, #0x1c]
 *   @0x164d9c str lr, [sp, #0xc]
 *   @0x164da0 ldr lr, [r12, #0x20]
 *   @0x164da4 str lr, [sp, #0x10]
 *   @0x164da8 ldrb lr, [r12, #0x24]
 *   @0x164dac str lr, [sp, #0x14]
 *   @0x164db0 ldr r12, [r12, #0x28]
 *   @0x164db4 str r12, [sp, #0x18]
 *   @0x164db8 bl 0x178d44 <_Z19GR_3D_Draw_Cylinderffffffiffbi>
 *   @0x164dbc ldr r2, [r6]
 *   @0x164dc0 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164dc4 ldr lr, [r12, #0x14]
 *   @0x164dc8 mov r10, #1
 *   @0x164dcc ldr r2, [r12, #0xc]
 *   @0x164dd0 ldr r0, [r12, #0x4]
 *   @0x164dd4 ldr r1, [r12, #0x8]
 *   @0x164dd8 ldr r3, [r12, #0x10]
 *   @0x164ddc str lr, [sp]
 *   @0x164de0 ldr lr, [r12, #0x18]
 *   @0x164de4 str r5, [sp, #0x8]
 *   @0x164de8 str lr, [sp, #0x4]
 *   @0x164dec ldr lr, [r12, #0x1c]
 *   @0x164df0 str lr, [sp, #0xc]
 *   @0x164df4 ldr r12, [r12, #0x20]
 *   @0x164df8 str r12, [sp, #0x10]
 *   @0x164dfc bl 0x17763c <_Z16GR_3D_Draw_Blockffffffiff>
 *   @0x164e00 ldr r2, [r6]
 *   @0x164e04 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164e08 ldr lr, [r12, #0x14]
 *   @0x164e0c ldr r2, [r12, #0xc]
 *   @0x164e10 ldr r0, [r12, #0x4]
 *   @0x164e14 ldr r1, [r12, #0x8]
 *   @0x164e18 ldr r3, [r12, #0x10]
 *   @0x164e1c str lr, [sp]
 *   @0x164e20 ldr lr, [r12, #0x18]
 *   @0x164e24 str lr, [sp, #0x4]
 *   @0x164e28 ldr lr, [r12, #0x1c]
 *   @0x164e2c str lr, [sp, #0x8]
 *   @0x164e30 ldr lr, [r12, #0x20]
 *   @0x164e34 str lr, [sp, #0xc]
 *   @0x164e38 ldr lr, [r12, #0x24]
 *   @0x164e3c str lr, [sp, #0x10]
 *   @0x164e40 ldr r12, [r12, #0x28]
 *   @0x164e44 str r12, [sp, #0x14]
 *   @0x164e48 bl 0x1774e4 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf>
 *   @0x164e4c ldr r2, [r6]
 *   @0x164e50 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164e54 ldr lr, [r12, #0x14]
 *   @0x164e58 mov r10, #1
 *   @0x164e5c ldr r2, [r12, #0xc]
 *   @0x164e60 ldr r0, [r12, #0x4]
 *   @0x164e64 ldr r1, [r12, #0x8]
 *   @0x164e68 ldr r3, [r12, #0x10]
 *   @0x164e6c str lr, [sp]
 *   @0x164e70 ldr lr, [r12, #0x18]
 *   @0x164e74 str lr, [sp, #0x4]
 *   @0x164e78 ldr lr, [r12, #0x1c]
 *   @0x164e7c str lr, [sp, #0x8]
 *   @0x164e80 ldr r12, [r12, #0x20]
 *   @0x164e84 str r12, [sp, #0xc]
 *   @0x164e88 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x164e8c ldr r2, [r6]
 *   @0x164e90 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164e94 ldr lr, [r12, #0x14]
 *   @0x164e98 ldr r2, [r12, #0xc]
 *   @0x164e9c ldr r0, [r12, #0x4]
 *   @0x164ea0 ldr r1, [r12, #0x8]
 *   @0x164ea4 ldr r3, [r12, #0x10]
 *   @0x164ea8 str lr, [sp]
 *   @0x164eac ldr lr, [r12, #0x18]
 *   @0x164eb0 str lr, [sp, #0x4]
 *   @0x164eb4 ldr lr, [r12, #0x1c]
 *   @0x164eb8 str lr, [sp, #0x8]
 *   @0x164ebc ldr r12, [r12, #0x20]
 *   @0x164ec0 str r12, [sp, #0xc]
 *   @0x164ec4 bl 0x1772d0 <_Z20GR_3D_Vertex_N_Colorffffffjf>
 *   @0x164ec8 ldr r2, [r6]
 *   @0x164ecc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164ed0 ldr lr, [r12, #0x14]
 *   @0x164ed4 mov r10, #1
 *   @0x164ed8 ldr r2, [r12, #0xc]
 *   @0x164edc ldr r0, [r12, #0x4]
 *   @0x164ee0 ldr r1, [r12, #0x8]
 *   @0x164ee4 ldr r3, [r12, #0x10]
 *   @0x164ee8 str lr, [sp]
 *   @0x164eec ldr r12, [r12, #0x18]
 *   @0x164ef0 str r12, [sp, #0x4]
 *   @0x164ef4 bl 0x177214 <_Z14GR_3D_Vertex_Nffffff>
 *   @0x164ef8 ldr r2, [r6]
 *   @0x164efc b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164f00 ldr lr, [r12, #0x14]
 *   @0x164f04 ldr r2, [r12, #0xc]
 *   @0x164f08 ldr r0, [r12, #0x4]
 *   @0x164f0c ldr r1, [r12, #0x8]
 *   @0x164f10 ldr r3, [r12, #0x10]
 *   @0x164f14 str lr, [sp]
 *   @0x164f18 ldr lr, [r12, #0x18]
 *   @0x164f1c str lr, [sp, #0x4]
 *   @0x164f20 ldr r12, [r12, #0x1c]
 *   @0x164f24 str r12, [sp, #0x8]
 *   @0x164f28 bl 0x1770c8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf>
 *   @0x164f2c ldr r2, [r6]
 *   @0x164f30 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164f34 ldr r2, [r12, #0xc]
 *   @0x164f38 mov r10, #1
 *   @0x164f3c ldr r0, [r12, #0x4]
 *   @0x164f40 ldr r1, [r12, #0x8]
 *   @0x164f44 ldr r3, [r12, #0x10]
 *   @0x164f48 ldr r12, [r12, #0x14]
 *   @0x164f4c str r12, [sp]
 *   @0x164f50 bl 0x176f7c <_Z20GR_3D_Vertex_Texturefffff>
 *   @0x164f54 ldr r2, [r6]
 *   @0x164f58 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164f5c ldr r2, [r12, #0xc]
 *   @0x164f60 ldr r3, [r12, #0x10]
 *   @0x164f64 ldr r0, [r12, #0x4]
 *   @0x164f68 ldr r1, [r12, #0x8]
 *   @0x164f6c ldr r12, [r12, #0x14]
 *   @0x164f70 str r12, [sp]
 *   @0x164f74 bl 0x176ed4 <_Z18GR_3D_Vertex_Colorfffjf>
 *   @0x164f78 ldr r2, [r6]
 *   @0x164f7c b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164f80 ldr r2, [r12, #0xc]
 *   @0x164f84 mov r10, #1
 *   @0x164f88 ldr r0, [r12, #0x4]
 *   @0x164f8c ldr r1, [r12, #0x8]
 *   @0x164f90 bl 0x176e2c <_Z12GR_3D_Vertexfff>
 *   @0x164f94 ldr r2, [r6]
 *   @0x164f98 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164f9c bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x164fa0 ldr r2, [r6]
 *   @0x164fa4 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164fa8 vldr s15, [r12, #4]
 *   @0x164fac vcvt.f64.f32 d6, s15
 *   @0x164fb0 vmov r0, r1, d6
 *   @0x164fb4 bl 0xb66e8 <lrint@plt>
 *   @0x164fb8 mov r1, r5
 *   @0x164fbc bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x164fc0 ldr r2, [r6]
 *   @0x164fc4 b 0x164bec <_ZN9C3D_Model4DrawEfffi+0x240>
 *   @0x164fc8 ldr r2, [r4]
 *   @0x164fcc str r2, [r6, #0xc]
 *   @0x164fd0 b 0x164c60 <_ZN9C3D_Model4DrawEfffi+0x2b4>
 *   @0x164fd4 str r4, [r6, #0x10]
 *   @0x164fd8 str r4, [r6, #0xc]
 *   @0x164fdc str r3, [r4, #0x4]
 *   @0x164fe0 str r3, [r4]
 *   @0x164fe4 b 0x164ae4 <_ZN9C3D_Model4DrawEfffi+0x138>
 *   @0x164fe8 eoreq sp, r8, r4, lsl #5
 *   @0x164fec .word 0xffffe49c
 *   @0x164ff0 .word 0xffffc0ac
 *   @0x164ff4 .word 0xffffbccc
 *
 * ══ §16/20 AddFunctionNames(Buffer_Standard*)  0x29f4e4  size 1612  396 条（0x29f4e4..0x29fb30）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x29f4e4 0x29fb30  size 1612  396 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29f4f4→0x47a148, 0x29f548→0x47a14c, 0x29f580→0x5428e8, 0x29f59c→0x753108, 0x29f5b4→0x75310c, 0x29f664→0x47a19c, 0x29f798→0x47a18c, 0x29f8a0→0x47a1ac
 * 调用序列: WriteString(Buffer_Standard*, char const*)×7 / AddFunctionNames(Buffer_Standard*)+0x9c / AddFunctionNames(Buffer_Standard*)+0x5f0 / AddFunctionNames(Buffer_Standard*)+0x220 / AddFunctionNames(Buffer_Standard*)+0x210 / AddFunctionNames(Buffer_Standard*)+0x354 / AddFunctionNames(Buffer_Standard*)+0x33c / AddFunctionNames(Buffer_Standard*)+0x508
 * 字段偏移 top8: 0x4×20 / 0x8×19 / 0x38×14 / 0x30×14 / 0xc×4 / 0x1c×4 / 0x2c×4 / 0x2×4
 * VFP 指令 40 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29f4e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29f4e8 sub sp, sp, #20
 *   @0x29f4ec ldr r3, [pc, #0x608]
 *   @0x29f4f0 add r7, r0, #44
 *   @0x29f4f4 ldr r12, [pc, #0x604]
 *   @0x29f4f8 mov r6, r0
 *   @0x29f4fc add r3, pc, r3
 *   @0x29f500 str r3, [sp, #0x4]
 *   @0x29f504 ldr r4, [sp, #0x4]
 *   @0x29f508 mov r9, #0
 *   @0x29f50c ldr r3, [r0]
 *   @0x29f510 mov r2, r7
 *   @0x29f514 mov r1, #5
 *   @0x29f518 ldr r8, [r4, r12]
 *   @0x29f51c vldr s15, [r8]
 *   @0x29f520 vcvt.f64.u32 d7, s15
 *   @0x29f524 str r9, [r0, #0x38]
 *   @0x29f528 vmov r4, r5, d7
 *   @0x29f52c vstr s14, [r6, #44]
 *   @0x29f530 str r5, [r6, #0x30]
 *   @0x29f534 ldr r3, [r3, #0x8]
 *   @0x29f538 blx r3
 *   @0x29f53c ldr r3, [r8]
 *   @0x29f540 cmp r3, r9
 *   @0x29f544 ble 0x29f580 <_Z16AddFunctionNamesP15Buffer_Standard+0x9c>
 *   @0x29f548 ldr r3, [pc, #0x5b4]
 *   @0x29f54c mov r4, r9
 *   @0x29f550 ldr r12, [sp, #0x4]
 *   @0x29f554 mov r5, r9
 *   @0x29f558 ldr r9, [r12, r3]
 *   @0x29f55c ldr r1, [r9]
 *   @0x29f560 mov r0, r6
 *   @0x29f564 add r5, r5, #1
 *   @0x29f568 add r1, r1, r4
 *   @0x29f56c add r4, r4, #80
 *   @0x29f570 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f574 ldr r3, [r8]
 *   @0x29f594 cmp r3, #0
 *   @0x29f598 bne 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150>
 *   @0x29f59c ldr r2, [pc, #0x568]
 *   @0x29f5a0 ldr r4, [sp, #0x4]
 *   @0x29f5a4 ldr r2, [r4, r2]
 *   @0x29f5a8 ldr r1, [r2]
 *   @0x29f5ac cmp r1, #0
 *   @0x29f5b0 ble 0x29fad4 <_Z16AddFunctionNamesP15Buffer_Standard+0x5f0>
 *   @0x29f5b4 ldr r2, [pc, #0x554]
 *   @0x29f5b8 lsl r1, r1, #4
 *   @0x29f5bc mov r9, r3
 *   @0x29f5c0 ldr r8, [r4, r2]
 *   @0x29f5c4 ldr r2, [r8, r3]
 *   @0x29f5c8 add r3, r3, #16
 *   @0x29f5cc cmp r2, #0
 *   @0x29f5d0 addne r9, r9, #1
 *   @0x29f5d4 cmp r3, r1
 *   @0x29f5d8 bne 0x29f5c4 <_Z16AddFunctionNamesP15Buffer_Standard+0xe0>
 *   @0x29f5dc vmov s15, r9
 *   @0x29f5e0 ldr r3, [r6]
 *   @0x29f5e4 mov r11, #0
 *   @0x29f5e8 mov r0, r6
 *   @0x29f5ec vcvt.f64.u32 d7, s15
 *   @0x29f5f0 str r11, [r6, #0x38]
 *   @0x29f5f4 mov r1, #5
 *   @0x29f5f8 mov r2, r7
 *   @0x29f5fc vmov r4, r5, d7
 *   @0x29f600 vstr s14, [r6, #44]
 *   @0x29f604 str r5, [r6, #0x30]
 *   @0x29f608 ldr r3, [r3, #0x8]
 *   @0x29f60c blx r3
 *   @0x29f610 cmp r9, r11
 *   @0x29f614 beq 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150>
 *   @0x29f618 mov r4, r11
 *   @0x29f61c ldr r1, [r8, r4, lsl #4]
 *   @0x29f620 mov r0, r6
 *   @0x29f624 add r4, r4, #1
 *   @0x29f628 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f62c cmp r4, r9
 *   @0x29f630 bne 0x29f61c <_Z16AddFunctionNamesP15Buffer_Standard+0x138>
 *   @0x29f634 ldr r3, [r6]
 *   @0x29f638 mov r8, #0
 *   @0x29f63c ldr r4, [r6, #0x1c]
 *   @0x29f640 mov r0, r6
 *   @0x29f644 str r8, [r6, #0x2c]
 *   @0x29f648 mov r1, #5
 *   @0x29f64c str r8, [r6, #0x30]
 *   @0x29f650 mov r2, r7
 *   @0x29f654 ldr r3, [r3, #0x8]
 *   @0x29f658 str r8, [r6, #0x38]
 *   @0x29f65c str r4, [sp, #0x8]
 *   @0x29f660 blx r3
 *   @0x29f664 ldr r3, [pc, #0x4a8]
 *   @0x29f668 ldr r12, [sp, #0x4]
 *   @0x29f66c ldr r11, [r12, r3]
 *   @0x29f670 ldr r3, [r11, #0x4]
 *   @0x29f674 cmp r3, r8
 *   @0x29f678 ble 0x29f704 <_Z16AddFunctionNamesP15Buffer_Standard+0x220>
 *   @0x29f67c mov r10, r8
 *   @0x29f680 ldr r3, [r11]
 *   @0x29f684 mov r1, #6
 *   @0x29f688 mov r2, r7
 *   @0x29f68c mov r0, r6
 *   @0x29f690 cmp r3, r10
 *   @0x29f694 lsl r9, r10, #2
 *   @0x29f698 ble 0x29f6f4 <_Z16AddFunctionNamesP15Buffer_Standard+0x210>
 *   @0x29f69c ldr r3, [r11, #0xc]
 *   @0x29f6a0 ldr r3, [r3, r10, lsl #2]
 *   @0x29f6a4 cmp r3, #0
 *   @0x29f6a8 beq 0x29f6f4 <_Z16AddFunctionNamesP15Buffer_Standard+0x210>
 *   @0x29f6ac vmov s15, r10
 *   @0x29f6b0 ldr r3, [r6]
 *   @0x29f6b4 mov lr, #0
 *   @0x29f6b8 str lr, [r6, #0x38]
 *   @0x29f6bc vcvt.f64.s32 d7, s15
 *   @0x29f6c0 add r8, r8, #1
 *   @0x29f6c4 vmov r4, r5, d7
 *   @0x29f6c8 vstr s14, [r6, #44]
 *   @0x29f6cc str r5, [r6, #0x30]
 *   @0x29f6d0 ldr r3, [r3, #0x8]
 *   @0x29f6d4 blx r3
 *   @0x29f6d8 ldr r3, [r11]
 *   @0x29f6dc mov r1, #0
 *   @0x29f6e0 mov r0, r6
 *   @0x29f6e4 cmp r3, r10
 *   @0x29f6e8 ldrgt r3, [r11, #0xc]
 *   @0x29f6ec ldrgt r1, [r3, r9]
 *   @0x29f6f0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f6f4 ldr r3, [r11, #0x4]
 *   @0x29f6f8 add r10, r10, #1
 *   @0x29f6fc cmp r3, r10
 *   @0x29f700 bgt 0x29f680 <_Z16AddFunctionNamesP15Buffer_Standard+0x19c>
 *   @0x29f704 ldr r3, [r6]
 *   @0x29f708 mov r1, #0
 *   @0x29f70c ldr r2, [sp, #0x8]
 *   @0x29f710 mov r0, r6
 *   @0x29f714 mov r4, r1
 *   @0x29f718 ldr r5, [r6, #0x1c]
 *   @0x29f71c ldr r3, [r3, #0x10]
 *   @0x29f720 blx r3
 *   @0x29f724 vmov s15, r8
 *   @0x29f728 ldr r3, [r6]
 *   @0x29f72c mov r1, #6
 *   @0x29f730 vcvt.f64.s32 d7, s15
 *   @0x29f734 mov r2, r7
 *   @0x29f738 mov r0, r6
 *   @0x29f73c str r4, [r6, #0x38]
 *   @0x29f740 vmov r8, r9, d7
 *   @0x29f744 vstr s14, [r6, #44]
 *   @0x29f748 mov r8, r4
 *   @0x29f74c str r9, [r6, #0x30]
 *   @0x29f750 ldr r3, [r3, #0x8]
 *   @0x29f754 blx r3
 *   @0x29f758 ldr r3, [r6]
 *   @0x29f75c mov r2, r5
 *   @0x29f760 mov r1, r4
 *   @0x29f764 mov r0, r6
 *   @0x29f768 ldr r3, [r3, #0x10]
 *   @0x29f76c blx r3
 *   @0x29f770 ldr r3, [r6]
 *   @0x29f774 str r4, [r6, #0x2c]
 *   @0x29f778 mov r0, r6
 *   @0x29f77c str r4, [r6, #0x30]
 *   @0x29f780 mov r1, #5
 *   @0x29f784 ldr r3, [r3, #0x8]
 *   @0x29f788 mov r2, r7
 *   @0x29f78c str r4, [r6, #0x38]
 *   @0x29f790 ldr r11, [r6, #0x1c]
 *   @0x29f794 blx r3
 *   @0x29f798 ldr r3, [pc, #0x378]
 *   @0x29f79c ldr r12, [sp, #0x4]
 *   @0x29f7a0 ldr r5, [r12, r3]
 *   @0x29f7a4 ldr r3, [r5, #0x4]
 *   @0x29f7a8 cmp r3, r4
 *   @0x29f7ac ble 0x29f838 <_Z16AddFunctionNamesP15Buffer_Standard+0x354>
 *   @0x29f7b0 mov r9, r4
 *   @0x29f7b4 str r11, [sp, #0x8]
 *   @0x29f7b8 str r7, [sp]
 *   @0x29f7bc ldr r3, [r5]
 *   @0x29f7c0 add r10, r4, #99328
 *   @0x29f7c4 ldr r2, [sp]
 *   @0x29f7c8 add r10, r10, #672
 *   @0x29f7cc cmp r3, r4
 *   @0x29f7d0 mov r0, r6
 *   @0x29f7d4 mov r1, #6
 *   @0x29f7d8 ble 0x29f820 <_Z16AddFunctionNamesP15Buffer_Standard+0x33c>
 *   @0x29f7dc ldr r3, [r5, #0xc]
 *   @0x29f7e0 ldr r7, [r3, r4, lsl #2]
 *   @0x29f7e4 cmp r7, #0
 *   @0x29f7e8 beq 0x29f820 <_Z16AddFunctionNamesP15Buffer_Standard+0x33c>
 *   @0x29f7ec vmov s15, r10
 *   @0x29f7f0 ldr lr, [r6]
 *   @0x29f7f4 str r9, [r6, #0x38]
 *   @0x29f7f8 add r8, r8, #1
 *   @0x29f7fc vcvt.f64.s32 d7, s15
 *   @0x29f800 vmov r10, r11, d7
 *   @0x29f804 vstr s14, [r6, #44]
 *   @0x29f808 str r11, [r6, #0x30]
 *   @0x29f80c ldr r10, [lr, #0x8]
 *   @0x29f810 blx r10
 *   @0x29f814 mov r0, r6
 *   @0x29f818 mov r1, r7
 *   @0x29f81c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f820 ldr r3, [r5, #0x4]
 *   @0x29f824 add r4, r4, #1
 *   @0x29f828 cmp r3, r4
 *   @0x29f82c bgt 0x29f7bc <_Z16AddFunctionNamesP15Buffer_Standard+0x2d8>
 *   @0x29f830 ldr r11, [sp, #0x8]
 *   @0x29f834 ldr r7, [sp]
 *   @0x29f838 ldr r3, [r6]
 *   @0x29f83c mov r2, r11
 *   @0x29f840 mov r1, #0
 *   @0x29f844 mov r0, r6
 *   @0x29f848 mov r5, r1
 *   @0x29f84c ldr r4, [r6, #0x1c]
 *   @0x29f850 ldr r3, [r3, #0x10]
 *   @0x29f854 blx r3
 *   @0x29f858 vmov s15, r8
 *   @0x29f85c ldr r3, [r6]
 *   @0x29f860 mov r1, #6
 *   @0x29f864 vcvt.f64.s32 d7, s15
 *   @0x29f868 mov r2, r7
 *   @0x29f86c mov r0, r6
 *   @0x29f870 str r5, [r6, #0x38]
 *   @0x29f874 vmov r8, r9, d7
 *   @0x29f878 vstr s14, [r6, #44]
 *   @0x29f87c str r9, [r6, #0x30]
 *   @0x29f880 ldr r3, [r3, #0x8]
 *   @0x29f884 blx r3
 *   @0x29f888 ldr r3, [r6]
 *   @0x29f88c mov r2, r4
 *   @0x29f890 mov r1, r5
 *   @0x29f894 mov r0, r6
 *   @0x29f898 ldr r3, [r3, #0x10]
 *   @0x29f89c blx r3
 *   @0x29f8a0 ldr r12, [pc, #0x274]
 *   @0x29f8a4 ldr r4, [sp, #0x4]
 *   @0x29f8a8 mov r0, r6
 *   @0x29f8ac ldr r3, [r6]
 *   @0x29f8b0 mov r1, #5
 *   @0x29f8b4 mov r2, r7
 *   @0x29f8b8 ldr r11, [r4, r12]
 *   @0x29f8bc vldr s15, [r11]
 *   @0x29f8c0 vcvt.f64.u32 d7, s15
 *   @0x29f8c4 str r5, [r6, #0x38]
 *   @0x29f8c8 vmov r8, r9, d7
 *   @0x29f8cc vstr s14, [r6, #44]
 *   @0x29f8d0 str r9, [r6, #0x30]
 *   @0x29f8d4 ldr r3, [r3, #0x8]
 *   @0x29f8d8 blx r3
 *   @0x29f8dc ldr r3, [r11]
 *   @0x29f8e0 cmp r3, r5
 *   @0x29f8e4 ble 0x29f9ec <_Z16AddFunctionNamesP15Buffer_Standard+0x508>
 *   @0x29f8e8 ldr r3, [pc, #0x230]
 *   @0x29f8ec mov r9, r5
 *   @0x29f8f0 ldr r4, [sp, #0x4]
 *   @0x29f8f4 mov r8, r5
 *   @0x29f8f8 ldr r10, [r4, r3]
 *   @0x29f8fc str r11, [sp]
 *   @0x29f900 ldr r3, [r10]
 *   @0x29f904 mov r0, r6
 *   @0x29f908 ldr r1, [r3, r8]
 *   @0x29f90c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f910 ldr r2, [r10]
 *   @0x29f914 ldr r3, [r6]
 *   @0x29f918 mov r12, #0
 *   @0x29f91c add r2, r2, r8
 *   @0x29f920 mov r0, r6
 *   @0x29f924 mov r1, #5
 *   @0x29f928 ldr r4, [r2, #0x4]
 *   @0x29f92c mov r2, r7
 *   @0x29f930 str r12, [r6, #0x38]
 *   @0x29f934 vmov s15, r4
 *   @0x29f938 vcvt.f64.u32 d7, s15
 *   @0x29f93c vmov r4, r5, d7
 *   @0x29f940 vstr s14, [r6, #44]
 *   @0x29f944 str r5, [r6, #0x30]
 *   @0x29f948 ldr r3, [r3, #0x8]
 *   @0x29f94c blx r3
 *   @0x29f950 ldr r3, [r10]
 *   @0x29f954 add r3, r3, r8
 *   @0x29f958 ldr r3, [r3, #0x4]
 *   @0x29f95c cmp r3, #0
 *   @0x29f960 movgt r11, #0
 *   @0x29f964 ble 0x29f9d4 <_Z16AddFunctionNamesP15Buffer_Standard+0x4f0>
 *   @0x29f968 add r4, r11, #199680
 *   @0x29f96c ldr r3, [r6]
 *   @0x29f970 add r4, r4, #320
 *   @0x29f974 mov r12, #0
 *   @0x29f978 mov r1, #6
 *   @0x29f97c str r12, [r6, #0x38]
 *   @0x29f980 vmov s15, r4
 *   @0x29f984 mov r2, r7
 *   @0x29f988 mov r0, r6
 *   @0x29f98c vcvt.f64.s32 d7, s15
 *   @0x29f990 vmov r4, r5, d7
 *   @0x29f994 vstr s14, [r6, #44]
 *   @0x29f998 str r5, [r6, #0x30]
 *   @0x29f99c ldr r3, [r3, #0x8]
 *   @0x29f9a0 blx r3
 *   @0x29f9a4 ldr r3, [r10]
 *   @0x29f9a8 mov r0, r6
 *   @0x29f9ac add r3, r3, r8
 *   @0x29f9b0 ldr r3, [r3, #0x8]
 *   @0x29f9b4 ldr r1, [r3, r11, lsl #2]
 *   @0x29f9b8 add r11, r11, #1
 *   @0x29f9bc bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f9c0 ldr r3, [r10]
 *   @0x29f9c4 add r3, r3, r8
 *   @0x29f9c8 ldr r3, [r3, #0x4]
 *   @0x29f9cc cmp r3, r11
 *   @0x29f9d0 bgt 0x29f968 <_Z16AddFunctionNamesP15Buffer_Standard+0x484>
 *   @0x29f9d4 ldr r4, [sp]
 *   @0x29f9d8 add r9, r9, #1
 *   @0x29f9dc add r8, r8, #12
 *   @0x29f9e0 ldr r3, [r4]
 *   @0x29f9e4 cmp r3, r9
 *   @0x29f9e8 bgt 0x29f900 <_Z16AddFunctionNamesP15Buffer_Standard+0x41c>
 *   @0x29f9ec ldr r3, [sp, #0xc]
 *   @0x29f9f0 ldrb r9, [r3]
 *   @0x29f9f4 cmp r9, #0
 *   @0x29f9f8 beq 0x29fa04 <_Z16AddFunctionNamesP15Buffer_Standard+0x520>
 *   @0x29f9fc add sp, sp, #20
 *   @0x29fa00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29fa04 ldr lr, [pc, #0x118]
 *   @0x29fa08 mov r3, #10
 *   @0x29fa0c ldr r4, [sp, #0x4]
 *   @0x29fa10 mov r2, r7
 *   @0x29fa14 ldr r12, [r6]
 *   @0x29fa18 mov r1, #12
 *   @0x29fa1c mov r0, r6
 *   @0x29fa20 ldr r8, [r4, lr]
 *   @0x29fa24 str r3, [r6, #0x38]
 *   @0x29fa28 ldr r3, [r8]
 *   @0x29fa2c asr r5, r3, #31
 *   @0x29fa30 str r3, [r6, #0x2c]
 *   @0x29fa34 str r5, [r6, #0x30]
 *   @0x29fa38 ldr r3, [r12, #0x8]
 *   @0x29fa3c blx r3
 *   @0x29fa40 ldr r4, [sp, #0x4]
 *   @0x29fa44 ldr r12, [pc, #0xdc]
 *   @0x29fa48 mov r2, r7
 *   @0x29fa4c ldr r3, [r6]
 *   @0x29fa50 mov r0, r6
 *   @0x29fa54 mov r1, #5
 *   @0x29fa58 ldr r7, [r4, r12]
 *   @0x29fa5c vldr s15, [r7]
 *   @0x29fa60 vcvt.f64.u32 d7, s15
 *   @0x29fa64 str r9, [r6, #0x38]
 *   @0x29fa68 vmov r4, r5, d7
 *   @0x29fa6c vstr s14, [r6, #44]
 *   @0x29fa70 str r5, [r6, #0x30]
 *   @0x29fa74 ldr r3, [r3, #0x8]
 *   @0x29fa78 blx r3
 *   @0x29fa7c ldr r3, [r7]
 *   @0x29fa80 cmp r3, #0
 *   @0x29fa84 ble 0x29f9fc <_Z16AddFunctionNamesP15Buffer_Standard+0x518>
 *   @0x29fa88 ldr r5, [sp, #0x4]
 *   @0x29fa8c mov r4, r9
 *   @0x29fa90 ldr r3, [r8]
 *   @0x29fa94 mov r0, r6
 *   @0x29fa98 ldr r2, [pc, #0x8c]
 *   @0x29fa9c ldr r3, [r3, r4, lsl #2]
 *   @0x29faa0 add r4, r4, #1
 *   @0x29faa4 cmn r3, #4
 *   @0x29faa8 ldrne r2, [r5, r2]
 *   @0x29faac moveq r1, #0
 *   @0x29fab0 ldrne r1, [r2]
 *   @0x29fab4 addne r1, r1, #4
 *   @0x29fab8 addne r1, r1, r3
 *   @0x29fabc bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29fac0 ldr r3, [r7]
 *   @0x29fac4 cmp r3, r4
 *   @0x29fac8 bgt 0x29fa90 <_Z16AddFunctionNamesP15Buffer_Standard+0x5ac>
 *   @0x29facc add sp, sp, #20
 *   @0x29fad0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29fad4 ldr r12, [r6]
 *   @0x29fad8 mov r0, r6
 *   @0x29fadc str r3, [r6, #0x2c]
 *   @0x29fae0 mov r1, #5
 *   @0x29fae4 str r3, [r6, #0x30]
 *   @0x29fae8 mov r2, r7
 *   @0x29faec str r3, [r6, #0x38]
 *   @0x29faf0 ldr r3, [r12, #0x8]
 *   @0x29faf4 blx r3
 *   @0x29faf8 b 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150>
 *   @0x29fafc andseq r2, r5, r4, asr r7
 *   @0x29fb00 .word 0xffffbec4
 *   @0x29fb04 .word 0xffffbec8
 *   @0x29fb08 .word 0xffffbcd4
 *   @0x29fb0c .word 0xffffbfe4
 *   @0x29fb10 .word 0xffffbfe8
 *   @0x29fb14 .word 0xffffbf4c
 *   @0x29fb18 .word 0xffffbf50
 *   @0x29fb1c .word 0xffffbf5c
 *   @0x29fb20 .word 0xffffbf60
 *   @0x29fb24 .word 0xffffc114
 *   @0x29fb28 .word 0xfffff070
 *   @0x29fb2c .word 0xffffbcf4
 *
 * ══ §17/20 F_JSArrayCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x253fc0  size 1608  402 条（0x253fc0..0x254608）
 * @func 0x253fc0 0x254608  size 1608  402 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*)×2 / PushContextStack(YYObjectBase*)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2
 * 字段偏移 top8: 0x4×20 / 0xc×14 / 0x8×13 / 0x-10×11 / 0x-4×5 / 0x-8×4 / 0x38×2 / 0x24×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x253fc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x253fc4 cmp r3, #1
 *   @0x253fc8 sub sp, sp, #20
 *   @0x253fcc mov r4, r3
 *   @0x253fd0 mov r9, r0
 *   @0x253fd4 mov r11, r1
 *   @0x253fd8 mov r10, r2
 *   @0x253fdc ldr r8, [sp, #0x38]
 *   @0x253fe0 beq 0x2541e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x253fe4 str r8, [sp]
 *   @0x253fe8 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x253fec ldr r0, [r9]
 *   @0x253ff0 ldr r3, [r0, #0x4]
 *   @0x253ff4 cmp r3, #0
 *   @0x253ff8 beq 0x254494 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4d4>
 *   @0x253ffc add r0, r3, #16
 *   @0x254000 ldr r5, [r0]
 *   @0x254004 mov r0, r5
 *   @0x254008 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x25400c subs r6, r4, #1
 *   @0x254010 str r4, [r5, #0x24]
 *   @0x254014 ldr r4, [r5, #0x4]
 *   @0x254018 movpl r9, #0
 *   @0x25401c addpl r5, r8, #16
 *   @0x254020 movpl r10, #6
 *   @0x254024 addpl r4, r4, #16
 *   @0x254028 bmi 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x25402c ldr r2, [r4, #-0x4]
 *   @0x254030 sub r8, r5, #16
 *   @0x254034 sub r7, r4, #16
 *   @0x254038 bic r3, r2, #-16777216
 *   @0x25403c cmp r3, #1
 *   @0x254040 beq 0x254170 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x254044 cmp r3, #2
 *   @0x254048 bne 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x25404c sub r2, r2, #1
 *   @0x254050 bic r2, r2, #-16777216
 *   @0x254054 bic r2, r2, #3
 *   @0x254058 cmp r2, #0
 *   @0x25405c beq 0x2541dc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x254060 mov r3, #5
 *   @0x254064 str r9, [r4, #-0x8]
 *   @0x254068 str r3, [r4, #-0x4]
 *   @0x25406c str r9, [r4, #-0x10]
 *   @0x254070 ldr r3, [r5, #-0x4]
 *   @0x254074 str r3, [r4, #-0x4]
 *   @0x254078 ldr r3, [r5, #-0x8]
 *   @0x25407c str r3, [r4, #-0x8]
 *   @0x254080 ldr r3, [r5, #-0x4]
 *   @0x254084 bic r3, r3, #-16777216
 *   @0x254088 cmp r3, #14
 *   @0x25408c addls pc, pc, r3, lsl #2
 *   @0x254090 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x254094 b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x254098 b 0x254158 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25409c b 0x25412c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x2540a0 b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x2540a4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540a8 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540ac b 0x254108 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x2540b0 b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x2540b4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540b8 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540bc b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x2540c0 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540c4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x2540c8 b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x2540cc b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x2540d0 ldr r3, [r5, #-0x10]
 *   @0x2540d4 str r3, [r4, #-0x10]
 *   @0x2540d8 sub r6, r6, #1
 *   @0x2540dc str r10, [r4, #-0x8]
 *   @0x2540e0 cmn r6, #1
 *   @0x2540e4 add r5, r5, #16
 *   @0x2540e8 add r4, r4, #16
 *   @0x2540ec bne 0x25402c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x2540f0 add sp, sp, #20
 *   @0x2540f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2540f8 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x2540fc ldm r8, {r2, r3}
 *   @0x254100 stm r7, {r2, r3}
 *   @0x254104 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x254108 ldr r3, [r5, #-0x10]
 *   @0x25410c str r3, [r4, #-0x10]
 *   @0x254110 ldr r3, [r5, #-0x10]
 *   @0x254114 cmp r3, #0
 *   @0x254118 beq 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x25411c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x254120 ldr r1, [r5, #-0x10]
 *   @0x254124 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x254128 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x25412c ldr r3, [r5, #-0x10]
 *   @0x254130 cmp r3, #0
 *   @0x254134 str r3, [r4, #-0x10]
 *   @0x254138 beq 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x25413c ldr r1, [r3, #0x8]
 *   @0x254140 ldr r2, [r3]
 *   @0x254144 cmp r1, #0
 *   @0x254148 streq r7, [r3, #0x8]
 *   @0x25414c add r2, r2, #1
 *   @0x254150 str r2, [r3]
 *   @0x254154 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x254158 ldr r3, [r5, #-0x10]
 *   @0x25415c cmp r3, #0
 *   @0x254160 ldrne r2, [r3, #0x4]
 *   @0x254164 addne r2, r2, #1
 *   @0x254168 strne r2, [r3, #0x4]
 *   @0x25416c b 0x2540d4 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x254170 ldr r11, [r4, #-0x10]
 *   @0x254174 cmp r11, #0
 *   @0x254178 beq 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x25417c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x254180 ldr r2, [r11, #0x4]
 *   @0x254184 sub r2, r2, #1
 *   @0x254188 str r2, [r11, #0x4]
 *   @0x25418c cmp r2, #0
 *   @0x254190 beq 0x25419c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x254194 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x254198 b 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x25419c ldr r0, [r11]
 *   @0x2541a0 str r2, [sp, #0xc]
 *   @0x2541a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2541a8 ldr r2, [sp, #0xc]
 *   @0x2541ac str r2, [r11]
 *   @0x2541b0 str r2, [r11, #0x8]
 *   @0x2541b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2541b8 ldr r2, [r11, #0x4]
 *   @0x2541bc sub r2, r2, #1
 *   @0x2541c0 str r2, [r11, #0x4]
 *   @0x2541c4 cmp r2, #0
 *   @0x2541c8 beq 0x2543b8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3f8>
 *   @0x2541cc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2541d0 mov r0, r11
 *   @0x2541d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2541d8 b 0x254194 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x2541dc mov r0, r7
 *   @0x2541e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2541e4 b 0x254060 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x2541e8 ldr r12, [r8, #0xc]
 *   @0x2541ec bic r12, r12, #-16777216
 *   @0x2541f0 cmp r12, #7
 *   @0x2541f4 beq 0x254388 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3c8>
 *   @0x2541f8 cmp r12, #10
 *   @0x2541fc beq 0x254388 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3c8>
 *   @0x254200 cmp r12, #0
 *   @0x254204 beq 0x2542d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x318>
 *   @0x254208 str r8, [sp]
 *   @0x25420c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x254210 ldr r0, [r9]
 *   @0x254214 ldr r3, [r0, #0x4]
 *   @0x254218 cmp r3, #0
 *   @0x25421c addne r0, r3, #16
 *   @0x254220 beq 0x25455c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x59c>
 *   @0x254224 ldr r4, [r0]
 *   @0x254228 mov r0, r4
 *   @0x25422c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x254230 ldr r4, [r4, #0x4]
 *   @0x254234 ldr r2, [r4, #0xc]
 *   @0x254238 bic r3, r2, #-16777216
 *   @0x25423c cmp r3, #1
 *   @0x254240 beq 0x2543f8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x438>
 *   @0x254244 cmp r3, #2
 *   @0x254248 bne 0x254270 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x25424c sub r3, r2, #1
 *   @0x254250 bic r3, r3, #-16777216
 *   @0x254254 bic r3, r3, #3
 *   @0x254258 cmp r3, #0
 *   @0x25425c beq 0x254550 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x590>
 *   @0x254260 mov r2, #0
 *   @0x254264 mov r3, #5
 *   @0x254268 str r2, [r4, #0x8]
 *   @0x25426c str r3, [r4, #0xc]
 *   @0x254270 ldr r3, [r8, #0xc]
 *   @0x254274 mov r1, #0
 *   @0x254278 ldr r2, [r8, #0x8]
 *   @0x25427c str r1, [r4]
 *   @0x254280 str r3, [r4, #0xc]
 *   @0x254284 ldr r3, [r8, #0xc]
 *   @0x254288 str r2, [r4, #0x8]
 *   @0x25428c bic r3, r3, #-16777216
 *   @0x254290 cmp r3, #14
 *   @0x254294 addls pc, pc, r3, lsl #2
 *   @0x254298 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x25429c b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388>
 *   @0x2542a0 b 0x25447c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4bc>
 *   @0x2542a4 b 0x254450 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x490>
 *   @0x2542a8 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2542ac b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542b0 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542b4 b 0x25442c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x46c>
 *   @0x2542b8 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2542bc b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542c0 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542c4 b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388>
 *   @0x2542c8 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542cc b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2542d0 b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388>
 *   @0x2542d4 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2542d8 mov r1, r12
 *   @0x2542dc mov r0, r8
 *   @0x2542e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2542e4 vmov d7, r0, r1
 *   @0x2542e8 vcmpe.f64 d7, #0
 *   @0x2542ec vmrs APSR_nzcv, fpscr
 *   @0x2542f0 bmi 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394>
 *   @0x2542f4 vldr d6, [pc, #764]
 *   @0x2542f8 vcmpe.f64 d7, d6
 *   @0x2542fc vmrs APSR_nzcv, fpscr
 *   @0x254300 bgt 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394>
 *   @0x254304 vcmp.f64 d7, d7
 *   @0x254308 vmrs APSR_nzcv, fpscr
 *   @0x25430c bvs 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394>
 *   @0x254310 vcvt.u32.f64 s11, d7
 *   @0x254314 vcvt.f64.u32 d6, s11
 *   @0x254318 vsub.f64 d6, d7, d6
 *   @0x25431c vcmp.f64 d6, #0
 *   @0x254320 vmrs APSR_nzcv, fpscr
 *   @0x254324 vmoveq r3, s11
 *   @0x254328 beq 0x25436c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3ac>
 *   @0x25432c vmov r4, s11
 *   @0x254330 b 0x25435c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x254334 ldr r3, [r8]
 *   @0x254338 str r3, [r4]
 *   @0x25433c add sp, sp, #20
 *   @0x254340 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x254344 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x254348 ldm r8, {r2, r3}
 *   @0x25434c stm r4, {r2, r3}
 *   @0x254350 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x254354 vcvt.u32.f64 s13, d7
 *   @0x254358 vmov r4, s13
 *   @0x25435c ldr r0, [pc, #0x29c]
 *   @0x254360 add r0, pc, r0
 *   @0x254364 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x254368 mov r3, r4
 *   @0x25436c str r8, [sp, #0x38]
 *   @0x254370 mov r0, r9
 *   @0x254374 mov r1, r11
 *   @0x254378 mov r2, r10
 *   @0x25437c add sp, sp, #20
 *   @0x254380 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x254384 b 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x254388 mov r0, r8
 *   @0x25438c mov r1, #0
 *   @0x254390 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0x254394 mvn r6, #0
 *   @0x254398 mov r7, #0
 *   @0x25439c mov r4, r0
 *   @0x2543a0 mov r5, r1
 *   @0x2543a4 cmp r5, r7
 *   @0x2543a8 cmpeq r4, r6
 *   @0x2543ac bhi 0x254540 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x580>
 *   @0x2543b0 mov r3, r4
 *   @0x2543b4 b 0x25436c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3ac>
 *   @0x2543b8 ldr r0, [r11]
 *   @0x2543bc str r2, [sp, #0xc]
 *   @0x2543c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2543c4 ldr r2, [sp, #0xc]
 *   @0x2543c8 str r2, [r11]
 *   @0x2543cc str r2, [r11, #0x8]
 *   @0x2543d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2543d4 ldr r2, [r11, #0x4]
 *   @0x2543d8 sub r2, r2, #1
 *   @0x2543dc str r2, [r11, #0x4]
 *   @0x2543e0 cmp r2, #0
 *   @0x2543e4 beq 0x2544d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x518>
 *   @0x2543e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2543ec mov r0, r11
 *   @0x2543f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2543f4 b 0x2541cc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x2543f8 ldr r5, [r4]
 *   @0x2543fc cmp r5, #0
 *   @0x254400 beq 0x254420 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x460>
 *   @0x254404 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x254408 ldr r6, [r5, #0x4]
 *   @0x25440c sub r6, r6, #1
 *   @0x254410 str r6, [r5, #0x4]
 *   @0x254414 cmp r6, #0
 *   @0x254418 beq 0x2544a0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4e0>
 *   @0x25441c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x254420 mov r3, #0
 *   @0x254424 str r3, [r4]
 *   @0x254428 b 0x254270 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x25442c ldr r3, [r8]
 *   @0x254430 str r3, [r4]
 *   @0x254434 ldr r3, [r8]
 *   @0x254438 cmp r3, #0
 *   @0x25443c beq 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x254440 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x254444 ldr r1, [r8]
 *   @0x254448 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x25444c b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x254450 ldr r3, [r8]
 *   @0x254454 cmp r3, #0
 *   @0x254458 str r3, [r4]
 *   @0x25445c beq 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x254460 ldr r1, [r3, #0x8]
 *   @0x254464 ldr r2, [r3]
 *   @0x254468 cmp r1, #0
 *   @0x25446c streq r4, [r3, #0x8]
 *   @0x254470 add r2, r2, #1
 *   @0x254474 str r2, [r3]
 *   @0x254478 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x25447c ldr r3, [r8]
 *   @0x254480 cmp r3, #0
 *   @0x254484 ldrne r2, [r3, #0x4]
 *   @0x254488 addne r2, r2, #1
 *   @0x25448c strne r2, [r3, #0x4]
 *   @0x254490 b 0x254338 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x378>
 *   @0x254494 mov r1, #1
 *   @0x254498 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25449c b 0x254000 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2544a0 ldr r0, [r5]
 *   @0x2544a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2544a8 str r6, [r5]
 *   @0x2544ac str r6, [r5, #0x8]
 *   @0x2544b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2544b4 ldr r6, [r5, #0x4]
 *   @0x2544b8 sub r6, r6, #1
 *   @0x2544bc str r6, [r5, #0x4]
 *   @0x2544c0 cmp r6, #0
 *   @0x2544c4 beq 0x254568 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5a8>
 *   @0x2544c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2544cc mov r0, r5
 *   @0x2544d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2544d4 b 0x25441c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x45c>
 *   @0x2544d8 ldr r0, [r11]
 *   @0x2544dc str r2, [sp, #0xc]
 *   @0x2544e0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2544e4 ldr r2, [sp, #0xc]
 *   @0x2544e8 str r2, [r11]
 *   @0x2544ec str r2, [r11, #0x8]
 *   @0x2544f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2544f4 ldr r2, [r11, #0x4]
 *   @0x2544f8 sub r2, r2, #1
 *   @0x2544fc str r2, [r11, #0x4]
 *   @0x254500 cmp r2, #0
 *   @0x254504 bne 0x254530 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x570>
 *   @0x254508 ldr r0, [r11]
 *   @0x25450c str r2, [sp, #0xc]
 *   @0x254510 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x254514 ldr r2, [sp, #0xc]
 *   @0x254518 mov r0, r11
 *   @0x25451c str r2, [r11]
 *   @0x254520 str r2, [r11, #0x8]
 *   @0x254524 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x254528 mov r0, r11
 *   @0x25452c bl 0x27d1d0 <_ZdlPv>
 *   @0x254530 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x254534 mov r0, r11
 *   @0x254538 bl 0x27d1d0 <_ZdlPv>
 *   @0x25453c b 0x2543e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x428>
 *   @0x254540 ldr r0, [pc, #0xbc]
 *   @0x254544 add r0, pc, r0
 *   @0x254548 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x25454c b 0x2543b0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3f0>
 *   @0x254550 mov r0, r4
 *   @0x254554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x254558 b 0x254260 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x25455c mov r1, r4
 *   @0x254560 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x254564 b 0x254224 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x254568 ldr r0, [r5]
 *   @0x25456c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x254570 str r6, [r5]
 *   @0x254574 str r6, [r5, #0x8]
 *   @0x254578 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25457c ldr r6, [r5, #0x4]
 *   @0x254580 sub r6, r6, #1
 *   @0x254584 str r6, [r5, #0x4]
 *   @0x254588 cmp r6, #0
 *   @0x25458c beq 0x2545a0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5e0>
 *   @0x254590 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x254594 mov r0, r5
 *   @0x254598 bl 0x27d1d0 <_ZdlPv>
 *   @0x25459c b 0x2544c8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x508>
 *   @0x2545a0 ldr r0, [r5]
 *   @0x2545a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2545a8 str r6, [r5]
 *   @0x2545ac str r6, [r5, #0x8]
 *   @0x2545b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2545b4 ldr r6, [r5, #0x4]
 *   @0x2545b8 sub r6, r6, #1
 *   @0x2545bc str r6, [r5, #0x4]
 *   @0x2545c0 cmp r6, #0
 *   @0x2545c4 bne 0x2545e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x628>
 *   @0x2545c8 ldr r0, [r5]
 *   @0x2545cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2545d0 mov r0, r5
 *   @0x2545d4 str r6, [r5]
 *   @0x2545d8 str r6, [r5, #0x8]
 *   @0x2545dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2545e0 mov r0, r5
 *   @0x2545e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2545e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2545ec mov r0, r5
 *   @0x2545f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2545f4 b 0x254590 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5d0>
 *   @0x2545f8 .word 0xffe00000
 *   @0x2545fc .word 0x41efffff
 *   @0x254600 andseq r1, r0, r8, ror #23
 *   @0x254604 andseq r1, r0, r4, lsl #20
 *
 * ══ §18/20 GetOpenGLInfo()  0x17d450  size 1604  401 条（0x17d450..0x17da94）
 * @func 0x17d450 0x17da94  size 1604  401 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17d460→0x479c28, 0x17d474→0x3eb70c, 0x17d4a0→0x4a2124, 0x17d4e0→0x479b84, 0x17d4e4→0x3f28a8, 0x17d4fc→0x3f26dc, 0x17d530→0x3f26d4, 0x17d538→0x4a2128
 * 调用序列: CheckGLVersion(int, int)×6 / HasExtension(char*, char*)×6 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb6604×2 / MemoryManager::Free(void const*) / 0xb6538 / 0xb65a4
 * 字段偏移 top8: 0xc×13 / 0x568×2 / 0x50c×2 / 0x1×2 / 0x4×2 / 0x57c×1 / 0x578×1 / 0x544×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17d450 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17d454 movw r0, #0x1f02
 *   @0x17d458 ldr r4, [pc, #0x57c]
 *   @0x17d45c sub sp, sp, #12
 *   @0x17d460 ldr r3, [pc, #0x578]
 *   @0x17d464 add r4, pc, r4
 *   @0x17d468 ldr r6, [r4, r3]
 *   @0x17d46c ldr r3, [r6]
 *   @0x17d470 blx r3
 *   @0x17d474 ldr r3, [pc, #0x568]
 *   @0x17d478 ldr r1, [pc, #0x568]
 *   @0x17d47c ldr r3, [r4, r3]
 *   @0x17d480 add r1, pc, r1
 *   @0x17d484 ldr r5, [r3]
 *   @0x17d488 ldr r3, [r5]
 *   @0x17d48c ldr r3, [r3, #0xc]
 *   @0x17d490 mov r2, r0
 *   @0x17d494 mov r7, r0
 *   @0x17d498 mov r0, r5
 *   @0x17d49c blx r3
 *   @0x17d4a0 ldr r3, [pc, #0x544]
 *   @0x17d4a4 ldr r9, [r4, r3]
 *   @0x17d4a8 ldr r0, [r9]
 *   @0x17d4ac cmp r0, #0
 *   @0x17d4b0 beq 0x17d4b8 <_Z13GetOpenGLInfov+0x68>
 *   @0x17d4b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x17d4b8 ldr r2, [r5]
 *   @0x17d4bc mov r0, #7936
 *   @0x17d4c0 ldr r3, [r6]
 *   @0x17d4c4 ldr r8, [r2, #0xc]
 *   @0x17d4c8 blx r3
 *   @0x17d4cc ldr r1, [pc, #0x51c]
 *   @0x17d4d0 add r1, pc, r1
 *   @0x17d4d4 mov r2, r0
 *   @0x17d4d8 mov r0, r5
 *   @0x17d4dc blx r8
 *   @0x17d4e0 ldr r2, [pc, #0x50c]
 *   @0x17d4e4 ldr r3, [pc, #0x50c]
 *   @0x17d4e8 movw r0, #0xd33
 *   @0x17d4ec ldr r10, [r4, r2]
 *   @0x17d4f0 ldr r1, [r4, r3]
 *   @0x17d4f4 ldr r3, [r10]
 *   @0x17d4f8 blx r3
 *   @0x17d4fc ldr r3, [pc, #0x4f8]
 *   @0x17d500 ldr r11, [r4, r3]
 *   @0x17d504 ldr r8, [r11]
 *   @0x17d508 cmp r8, #1
 *   @0x17d50c beq 0x17d884 <_Z13GetOpenGLInfov+0x434>
 *   @0x17d510 cmp r8, #0
 *   @0x17d514 beq 0x17d83c <_Z13GetOpenGLInfov+0x3ec>
 *   @0x17d518 ldr r1, [pc, #0x4e0]
 *   @0x17d51c mov r0, r7
 *   @0x17d520 add r1, pc, r1
 *   @0x17d524 bl 0xb6604 <strstr@plt>
 *   @0x17d528 cmp r0, #0
 *   @0x17d52c beq 0x17d54c <_Z13GetOpenGLInfov+0xfc>
 *   @0x17d530 ldr r1, [pc, #0x4cc]
 *   @0x17d534 mov r3, #1
 *   @0x17d538 ldr r2, [pc, #0x4c8]
 *   @0x17d53c ldr r1, [r4, r1]
 *   @0x17d540 str r3, [r1]
 *   @0x17d544 ldr r2, [r4, r2]
 *   @0x17d548 str r3, [r2]
 *   @0x17d54c ldr r1, [pc, #0x4b8]
 *   @0x17d550 mov r0, r7
 *   @0x17d554 add r1, pc, r1
 *   @0x17d558 bl 0xb6604 <strstr@plt>
 *   @0x17d55c cmp r0, #0
 *   @0x17d560 beq 0x17d584 <_Z13GetOpenGLInfov+0x134>
 *   @0x17d564 ldr r1, [pc, #0x498]
 *   @0x17d568 mov r0, #2
 *   @0x17d56c ldr r3, [pc, #0x494]
 *   @0x17d570 mov r2, #0
 *   @0x17d574 ldr r1, [r4, r1]
 *   @0x17d578 str r0, [r1]
 *   @0x17d57c ldr r3, [r4, r3]
 *   @0x17d580 str r2, [r3]
 *   @0x17d584 mov r0, #1
 *   @0x17d588 mov r1, r0
 *   @0x17d58c bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d590 cmp r0, #0
 *   @0x17d594 bne 0x17d810 <_Z13GetOpenGLInfov+0x3c0>
 *   @0x17d598 mov r0, #2
 *   @0x17d59c mov r1, #0
 *   @0x17d5a0 bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d5a4 cmp r0, #0
 *   @0x17d5a8 bne 0x17d7e4 <_Z13GetOpenGLInfov+0x394>
 *   @0x17d5ac ldr r3, [r6]
 *   @0x17d5b0 movw r0, #0x1f03
 *   @0x17d5b4 blx r3
 *   @0x17d5b8 ldr r3, [r5]
 *   @0x17d5bc ldr r1, [pc, #0x44c]
 *   @0x17d5c0 ldr r3, [r3, #0xc]
 *   @0x17d5c4 add r1, pc, r1
 *   @0x17d5c8 mov r2, r0
 *   @0x17d5cc mov r6, r0
 *   @0x17d5d0 mov r0, r5
 *   @0x17d5d4 blx r3
 *   @0x17d5d8 ldr r1, [pc, #0x434]
 *   @0x17d5dc mov r0, r6
 *   @0x17d5e0 add r1, pc, r1
 *   @0x17d5e4 bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d5e8 cmp r0, #0
 *   @0x17d5ec bne 0x17d7b8 <_Z13GetOpenGLInfov+0x368>
 *   @0x17d5f0 ldr r1, [pc, #0x420]
 *   @0x17d5f4 mov r0, r6
 *   @0x17d5f8 add r1, pc, r1
 *   @0x17d5fc bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d600 cmp r0, #0
 *   @0x17d604 bne 0x17d78c <_Z13GetOpenGLInfov+0x33c>
 *   @0x17d608 ldr r1, [pc, #0x40c]
 *   @0x17d60c mov r0, r6
 *   @0x17d610 add r1, pc, r1
 *   @0x17d614 bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d618 subs r1, r0, #0
 *   @0x17d61c beq 0x17d778 <_Z13GetOpenGLInfov+0x328>
 *   @0x17d620 ldr r2, [pc, #0x3f8]
 *   @0x17d624 mov r12, #1
 *   @0x17d628 ldr r3, [r5]
 *   @0x17d62c mov r0, r5
 *   @0x17d630 ldr r1, [pc, #0x3ec]
 *   @0x17d634 ldr r2, [r4, r2]
 *   @0x17d638 add r1, pc, r1
 *   @0x17d63c ldr r3, [r3, #0xc]
 *   @0x17d640 strb r12, [r2]
 *   @0x17d644 blx r3
 *   @0x17d648 ldr r3, [pc, #0x3d8]
 *   @0x17d64c ldr r7, [r4, r3]
 *   @0x17d650 ldrb r3, [r7]
 *   @0x17d654 cmp r3, #0
 *   @0x17d658 bne 0x17d754 <_Z13GetOpenGLInfov+0x304>
 *   @0x17d65c mov r0, #1
 *   @0x17d660 mov r1, #4
 *   @0x17d664 bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d668 cmp r0, #0
 *   @0x17d66c bne 0x17d86c <_Z13GetOpenGLInfov+0x41c>
 *   @0x17d670 ldr r1, [pc, #0x3b4]
 *   @0x17d674 mov r0, r6
 *   @0x17d678 add r1, pc, r1
 *   @0x17d67c bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d680 cmp r0, #0
 *   @0x17d684 bne 0x17d6d0 <_Z13GetOpenGLInfov+0x280>
 *   @0x17d688 ldr r1, [pc, #0x3a0]
 *   @0x17d68c mov r0, r6
 *   @0x17d690 add r1, pc, r1
 *   @0x17d694 bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d698 cmp r0, #0
 *   @0x17d69c beq 0x17d6c8 <_Z13GetOpenGLInfov+0x278>
 *   @0x17d6a0 ldr r2, [pc, #0x38c]
 *   @0x17d6a4 mov r12, #1
 *   @0x17d6a8 ldr r3, [r5]
 *   @0x17d6ac mov r0, r5
 *   @0x17d6b0 ldr r1, [pc, #0x380]
 *   @0x17d6b4 ldr r2, [r4, r2]
 *   @0x17d6b8 add r1, pc, r1
 *   @0x17d6bc ldr r3, [r3, #0xc]
 *   @0x17d6c0 strb r12, [r2]
 *   @0x17d6c4 blx r3
 *   @0x17d6c8 add sp, sp, #12
 *   @0x17d6cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17d6d0 ldr r3, [pc, #0x364]
 *   @0x17d6d4 ldr r7, [r4, r3]
 *   @0x17d6d8 ldr r3, [r7]
 *   @0x17d6dc blx r3
 *   @0x17d6e0 ldr r3, [pc, #0x358]
 *   @0x17d6e4 movw r0, #0xde1
 *   @0x17d6e8 movw r1, #0x84fe
 *   @0x17d6ec mov r2, #1065353216
 *   @0x17d6f0 ldr r3, [r4, r3]
 *   @0x17d6f4 ldr r3, [r3]
 *   @0x17d6f8 blx r3
 *   @0x17d6fc ldr r3, [r7]
 *   @0x17d700 blx r3
 *   @0x17d704 cmp r0, #0
 *   @0x17d708 bne 0x17d688 <_Z13GetOpenGLInfov+0x238>
 *   @0x17d70c ldr r1, [pc, #0x330]
 *   @0x17d710 mov r12, #1
 *   @0x17d714 ldr r2, [pc, #0x32c]
 *   @0x17d718 movw r0, #0x84ff
 *   @0x17d71c ldr r3, [r10]
 *   @0x17d720 ldr r1, [r4, r1]
 *   @0x17d724 strb r12, [r1]
 *   @0x17d728 ldr r7, [r4, r2]
 *   @0x17d72c mov r1, r7
 *   @0x17d730 blx r3
 *   @0x17d734 ldr r3, [r5]
 *   @0x17d738 ldr r1, [pc, #0x30c]
 *   @0x17d73c mov r0, r5
 *   @0x17d740 ldr r2, [r7]
 *   @0x17d744 add r1, pc, r1
 *   @0x17d748 ldr r3, [r3, #0xc]
 *   @0x17d74c blx r3
 *   @0x17d750 b 0x17d688 <_Z13GetOpenGLInfov+0x238>
 *   @0x17d754 mov r0, #1
 *   @0x17d758 mov r1, r0
 *   @0x17d75c bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d760 cmp r0, #0
 *   @0x17d764 bne 0x17d904 <_Z13GetOpenGLInfov+0x4b4>
 *   @0x17d768 ldrb r3, [r7]
 *   @0x17d76c cmp r3, #0
 *   @0x17d770 bne 0x17d670 <_Z13GetOpenGLInfov+0x220>
 *   @0x17d774 b 0x17d65c <_Z13GetOpenGLInfov+0x20c>
 *   @0x17d778 mov r0, #2
 *   @0x17d77c bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d780 cmp r0, #0
 *   @0x17d784 bne 0x17d620 <_Z13GetOpenGLInfov+0x1d0>
 *   @0x17d788 b 0x17d648 <_Z13GetOpenGLInfov+0x1f8>
 *   @0x17d78c ldr r2, [pc, #0x2bc]
 *   @0x17d790 mov r12, #1
 *   @0x17d794 ldr r3, [r5]
 *   @0x17d798 mov r0, r5
 *   @0x17d79c ldr r1, [pc, #0x2b0]
 *   @0x17d7a0 ldr r2, [r4, r2]
 *   @0x17d7a4 add r1, pc, r1
 *   @0x17d7a8 ldr r3, [r3, #0xc]
 *   @0x17d7ac strb r12, [r2]
 *   @0x17d7b0 blx r3
 *   @0x17d7b4 b 0x17d608 <_Z13GetOpenGLInfov+0x1b8>
 *   @0x17d7b8 ldr r2, [pc, #0x298]
 *   @0x17d7bc mov r12, #1
 *   @0x17d7c0 ldr r3, [r5]
 *   @0x17d7c4 mov r0, r5
 *   @0x17d7c8 ldr r1, [pc, #0x28c]
 *   @0x17d7cc ldr r2, [r4, r2]
 *   @0x17d7d0 add r1, pc, r1
 *   @0x17d7d4 ldr r3, [r3, #0xc]
 *   @0x17d7d8 strb r12, [r2]
 *   @0x17d7dc blx r3
 *   @0x17d7e0 b 0x17d5f0 <_Z13GetOpenGLInfov+0x1a0>
 *   @0x17d7e4 ldr r2, [pc, #0x248]
 *   @0x17d7e8 mov r12, #1
 *   @0x17d7ec ldr r3, [r5]
 *   @0x17d7f0 mov r0, r5
 *   @0x17d7f4 ldr r1, [pc, #0x264]
 *   @0x17d7f8 ldr r2, [r4, r2]
 *   @0x17d7fc add r1, pc, r1
 *   @0x17d800 ldr r3, [r3, #0xc]
 *   @0x17d804 strb r12, [r2]
 *   @0x17d808 blx r3
 *   @0x17d80c b 0x17d5ac <_Z13GetOpenGLInfov+0x15c>
 *   @0x17d810 ldr r2, [pc, #0x24c]
 *   @0x17d814 mov r12, #1
 *   @0x17d818 ldr r3, [r5]
 *   @0x17d81c mov r0, r5
 *   @0x17d820 ldr r1, [pc, #0x240]
 *   @0x17d824 ldr r2, [r4, r2]
 *   @0x17d828 add r1, pc, r1
 *   @0x17d82c ldr r3, [r3, #0xc]
 *   @0x17d830 strb r12, [r2]
 *   @0x17d834 blx r3
 *   @0x17d838 b 0x17d598 <_Z13GetOpenGLInfov+0x148>
 *   @0x17d83c ldr r1, [pc, #0x228]
 *   @0x17d840 mov r3, #1
 *   @0x17d844 mov r0, #2
 *   @0x17d848 mov r2, #70
 *   @0x17d84c add r1, pc, r1
 *   @0x17d850 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17d854 mov r3, #48
 *   @0x17d858 str r0, [r9]
 *   @0x17d85c strb r3, [r0]
 *   @0x17d860 ldr r3, [r9]
 *   @0x17d864 strb r8, [r3, #0x1]
 *   @0x17d868 b 0x17d518 <_Z13GetOpenGLInfov+0xc8>
 *   @0x17d86c ldr r3, [pc, #0x1fc]
 *   @0x17d870 mov r2, #0
 *   @0x17d874 movt r2, #0x4180
 *   @0x17d878 ldr r3, [r4, r3]
 *   @0x17d87c str r2, [r3]
 *   @0x17d880 b 0x17d670 <_Z13GetOpenGLInfov+0x220>
 *   @0x17d884 ldr r3, [r6]
 *   @0x17d888 movw r0, #0x8b8c
 *   @0x17d88c blx r3
 *   @0x17d890 subs r12, r0, #0
 *   @0x17d894 beq 0x17d988 <_Z13GetOpenGLInfov+0x538>
 *   @0x17d898 ldr r3, [r6]
 *   @0x17d89c movw r0, #0x8b8c
 *   @0x17d8a0 blx r3
 *   @0x17d8a4 bl 0xb6538 <strlen@plt>
 *   @0x17d8a8 ldr r1, [pc, #0x1c4]
 *   @0x17d8ac mov r2, #70
 *   @0x17d8b0 mov r3, r8
 *   @0x17d8b4 add r1, pc, r1
 *   @0x17d8b8 add r0, r0, #1
 *   @0x17d8bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17d8c0 ldr r3, [r6]
 *   @0x17d8c4 mov r8, r0
 *   @0x17d8c8 movw r0, #0x8b8c
 *   @0x17d8cc str r8, [r9]
 *   @0x17d8d0 blx r3
 *   @0x17d8d4 mov r1, r0
 *   @0x17d8d8 mov r0, r8
 *   @0x17d8dc bl 0xb65a4 <strcpy@plt>
 *   @0x17d8e0 ldr r3, [r5]
 *   @0x17d8e4 ldr r1, [pc, #0x18c]
 *   @0x17d8e8 mov r0, r5
 *   @0x17d8ec ldr r2, [r9]
 *   @0x17d8f0 add r1, pc, r1
 *   @0x17d8f4 ldr r3, [r3, #0xc]
 *   @0x17d8f8 blx r3
 *   @0x17d8fc ldr r8, [r11]
 *   @0x17d900 b 0x17d510 <_Z13GetOpenGLInfov+0xc0>
 *   @0x17d904 mov r0, #2
 *   @0x17d908 mov r1, #0
 *   @0x17d90c bl 0x17d238 <_Z14CheckGLVersionii>
 *   @0x17d910 cmp r0, #0
 *   @0x17d914 bne 0x17d768 <_Z13GetOpenGLInfov+0x318>
 *   @0x17d918 ldr r1, [pc, #0x15c]
 *   @0x17d91c mov r0, r6
 *   @0x17d920 add r1, pc, r1
 *   @0x17d924 bl 0x17d428 <_Z12HasExtensionPcS_>
 *   @0x17d928 cmp r0, #0
 *   @0x17d92c beq 0x17d768 <_Z13GetOpenGLInfov+0x318>
 *   @0x17d930 ldr r1, [pc, #0x148]
 *   @0x17d934 mov r12, #1
 *   @0x17d938 ldr r2, [pc, #0x130]
 *   @0x17d93c movw r0, #0x84fd
 *   @0x17d940 ldr r3, [pc, #0x13c]
 *   @0x17d944 ldr r1, [r4, r1]
 *   @0x17d948 strb r12, [r1]
 *   @0x17d94c ldr r8, [r4, r2]
 *   @0x17d950 ldr r3, [r4, r3]
 *   @0x17d954 mov r1, r8
 *   @0x17d958 ldr r3, [r3]
 *   @0x17d95c blx r3
 *   @0x17d960 vldr s15, [r8]
 *   @0x17d964 vcvt.f64.f32 d6, s15
 *   @0x17d968 ldr r12, [r5]
 *   @0x17d96c ldr r1, [pc, #0x114]
 *   @0x17d970 mov r0, r5
 *   @0x17d974 add r1, pc, r1
 *   @0x17d978 ldr r12, [r12, #0xc]
 *   @0x17d97c vmov r2, r3, d6
 *   @0x17d980 blx r12
 *   @0x17d984 b 0x17d768 <_Z13GetOpenGLInfov+0x318>
 *   @0x17d988 ldr r3, [r5]
 *   @0x17d98c mov r0, r5
 *   @0x17d990 ldr r1, [pc, #0xf4]
 *   @0x17d994 ldr r3, [r3, #0xc]
 *   @0x17d998 add r1, pc, r1
 *   @0x17d99c str r12, [sp, #0x4]
 *   @0x17d9a0 blx r3
 *   @0x17d9a4 ldr r1, [pc, #0xe4]
 *   @0x17d9a8 mov r3, r8
 *   @0x17d9ac mov r0, #2
 *   @0x17d9b0 add r1, pc, r1
 *   @0x17d9b4 mov r2, #70
 *   @0x17d9b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17d9bc mov r3, #48
 *   @0x17d9c0 str r0, [r9]
 *   @0x17d9c4 strb r3, [r0]
 *   @0x17d9c8 ldr r12, [sp, #0x4]
 *   @0x17d9cc ldr r3, [r9]
 *   @0x17d9d0 strb r12, [r3, #0x1]
 *   @0x17d9d4 ldr r8, [r11]
 *   @0x17d9d8 b 0x17d510 <_Z13GetOpenGLInfov+0xc0>
 *   @0x17d9dc eoreq r4, r7, r12, ror #15
 *   @0x17d9e0 .word 0xffffbae0
 *   @0x17d9e4 .word 0xffffbac4
 *   @0x17d9e8 andseq lr, r12, r8, lsl r2
 *   @0x17d9ec .word 0xffffe7bc
 *   @0x17d9f0 andseq lr, r12, r4, ror #3
 *   @0x17d9f4 .word 0xffffbb48
 *   @0x17d9f8 .word 0xffffe7c0
 *   @0x17d9fc .word 0xffffe7b8
 *   @0x17da00 ldrsheq lr, [r12], -r8
 *   @0x17da04 .word 0xffffe7b0
 *   @0x17da08 .word 0xffffe7b4
 *   @0x17da0c ldrsbeq lr, [r12], -r8
 *   @0x17da10 andseq lr, r12, r0, asr #3
 *   @0x17da14 ldrheq lr, [r12], -r4
 *   @0x17da18 andseq lr, r12, r12, asr #3
 *   @0x17da1c andseq lr, r12, r4, lsl #4
 *   @0x17da20 .word 0xffffe7c4
 *   @0x17da24 andseq lr, r12, r12, lsr #5
 *   @0x17da28 .word 0xffffe7c8
 *   @0x17da2c andseq lr, r12, r0, asr #3
 *   @0x17da30 ldrsheq lr, [r12], -r12
 *   @0x17da34 .word 0xffffe7cc
 *   @0x17da38 andseq lr, r12, r8, ror #3
 *   @0x17da3c .word 0xffffbadc
 *   @0x17da40 .word 0xffffbb1c
 *   @0x17da44 .word 0xffffe7d0
 *   @0x17da48 .word 0xffffe7d4
 *   @0x17da4c andseq lr, r12, r8, lsl r1
 *   @0x17da50 .word 0xffffe7d8
 *   @0x17da54 andseq lr, r12, r12, lsr r0
 *   @0x17da58 .word 0xffffe7dc
 *   @0x17da5c ldrsbeq sp, [r12], -r4
 *   @0x17da60 andseq sp, r12, r8, asr pc
 *   @0x17da64 .word 0xffffe7e0
 *   @0x17da68 andseq sp, r12, r4, lsl pc
 *   @0x17da6c andseq r3, r11, r4, ror #15
 *   @0x17da70 .word 0xffffe7e4
 *   @0x17da74 andseq r3, r11, r12, ror r7
 *   @0x17da78 andseq sp, r12, r0, ror #27
 *   @0x17da7c ldrsheq sp, [r12], -r0
 *   @0x17da80 .word 0xffffe7e8
 *   @0x17da84 .word 0xffffbb4c
 *   @0x17da88 ldrheq sp, [r12], -r0
 *   @0x17da8c andseq sp, r12, r8, asr sp
 *   @0x17da90 andseq r3, r11, r0, lsl #13
 *
 * ══ §19/20 anonT_317798  0x317798  size 684  27 条（0x317798..0x317a44）｜其中 144 条已由别的卡落锚，本节不再重复
 * @func 0x317798 0x317a44  size 684  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_3180e8+0x280×3 / 0xb6fac / anonT_317798+0xf4 / anonT_317798+0x244 / anonT_317798+0x1d0
 * 字段偏移 top8: 0x14×4 / 0x98×4 / 0xc×3 / 0x8×3 / 0x4×2 / 0x10×2 / 0x18×1 / 0xb0×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31779c stmdavs r1, {r0, r1, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3177a4 tstge r8, #58720256
 *   @0x3177c0 vldmdblt r8!, {s28, s29}
 *   @0x3177ec .word 0xf7ff4038
 *   @0x3177f0 stmdami r7, {r0, r1, r4, r5, r8, r9, r10, r11, r12, sp, pc}
 *   @0x3177f8 .word 0x3101f971
 *   @0x317800 .word 0xf000fed1
 *   @0x317804 svclt #0xff61
 *   @0x317824 qsublt pc, sp, r0
 *   @0x31782c svclt #0x380001
 *   @0x31784c .word 0xf0941400
 *   @0x317850 mvnsle r0, r0, lsl #30
 *   @0x31786c ldmda r0, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^
 *   @0x317870 ldrmi r2, [r10], #-3840
 *   @0x317880 .word 0x47708f5f
 *   @0x3178d8 stmvs r10!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^
 *   @0x317910 andle r0, r10, r0, lsl #30
 *   @0x317928 stmvs r10!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^
 *   @0x31793c svclt #0x380301
 *   @0x317980 stmdavs r3!, {r4, pc}
 *   @0x3179ac .word 0x6125eb00
 *   @0x3179b8 stmdbhs r0, {sp, pc}
 *   @0x3179c4 strlo r0, [r1, -r7, asr #7]
 *   @0x3179e0 strbmi r0, [r0], #-0
 *   @0x3179f4 .word 0xd3e40908
 *   @0x317a20 stmdbvs r3!, {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x317a34 .word 0xe7baff99
 *
 * ══ §20/20 Code_Variable_Find(char const*)  0xd1d60  size 32  8 条（0xd1d60..0xd1d80）
 * @func 0xd1d60 0xd1d80  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_BuiltIn_Find(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1d60 push {r4, lr}
 *   @0xd1d64 mov r4, r0
 *   @0xd1d68 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0xd1d6c cmp r0, #0
 *   @0xd1d70 popge {r4, pc}
 *   @0xd1d74 mov r0, r4
 *   @0xd1d78 pop {r4, lr}
 *   @0xd1d7c b 0xd1bc4 <_Z17Variable_FindNamePKc>
 */
