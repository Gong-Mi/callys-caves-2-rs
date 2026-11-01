/* cally 逆向卡：All_47 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 87 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/87 F_SurfaceCopyPart(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f334  size 356  89 条（0x11f334..0x11f498）
 * @func 0x11f334 0x11f498  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / GR_Surface_Exists(int)×2 / RenderStateManager::SetRenderState(eRenderState, unsigned int)×2 / GR_Surface_Get_Texture(int)×2 / GR_Texture_Get_Surface(int)×2 / YYGML_surface_set_target_ext(int, int) / RenderStateManager::SaveStates() / Graphics::SurfaceCopy(void*, int, int, void*, int, int, int, int)
 * 字段偏移 top8: 0x14×3 / 0x40×1 / 0x110×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11f338 sub sp, sp, #28
 *   @0x11f33c mov r1, #0
 *   @0x11f340 ldr r4, [sp, #0x40]
 *   @0x11f344 mov r0, r4
 *   @0x11f348 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f34c mov r6, r0
 *   @0x11f350 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f354 cmp r0, #0
 *   @0x11f358 beq 0x11f478 <_Z17F_SurfaceCopyPartR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x11f35c mov r1, #3
 *   @0x11f360 mov r0, r4
 *   @0x11f364 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f368 mov r7, r0
 *   @0x11f36c bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f370 cmp r0, #0
 *   @0x11f374 beq 0x11f478 <_Z17F_SurfaceCopyPartR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x11f378 ldr r5, [pc, #0x110]
 *   @0x11f37c mov r1, r6
 *   @0x11f380 mov r0, #0
 *   @0x11f384 bl 0x171574 <_Z28YYGML_surface_set_target_extii>
 *   @0x11f388 ldr r5, [pc, r5]
 *   @0x11f38c mov r0, r5
 *   @0x11f390 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x11f394 mov r0, r4
 *   @0x11f398 mov r1, #0
 *   @0x11f39c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f3a0 mov r1, #12
 *   @0x11f3a4 mov r2, r0
 *   @0x11f3a8 mov r0, r5
 *   @0x11f3ac bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x11f3b0 mov r2, #0
 *   @0x11f3b4 mov r1, #1
 *   @0x11f3b8 mov r0, r5
 *   @0x11f3bc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x11f3c0 mov r0, r7
 *   @0x11f3c4 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f3c8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f3cc mov r7, r0
 *   @0x11f3d0 mov r0, r6
 *   @0x11f3d4 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f3d8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f3dc mov r1, #1
 *   @0x11f3e0 mov r6, r0
 *   @0x11f3e4 mov r0, r4
 *   @0x11f3e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f3ec mov r1, #2
 *   @0x11f3f0 mov r10, r0
 *   @0x11f3f4 mov r0, r4
 *   @0x11f3f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f3fc mov r1, #4
 *   @0x11f400 mov r8, r0
 *   @0x11f404 mov r0, r4
 *   @0x11f408 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f40c mov r1, #5
 *   @0x11f410 mov r3, r0
 *   @0x11f414 mov r0, r4
 *   @0x11f418 str r3, [sp, #0x14]
 *   @0x11f41c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f420 mov r1, #6
 *   @0x11f424 mov r11, r0
 *   @0x11f428 mov r0, r4
 *   @0x11f42c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f430 mov r1, #7
 *   @0x11f434 mov r9, r0
 *   @0x11f438 mov r0, r4
 *   @0x11f43c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f440 ldr r3, [sp, #0x14]
 *   @0x11f444 mov r1, r10
 *   @0x11f448 mov r2, r8
 *   @0x11f44c str r9, [sp, #0x8]
 *   @0x11f450 stm sp, {r3, r11}
 *   @0x11f454 mov r3, r7
 *   @0x11f458 str r0, [sp, #0xc]
 *   @0x11f45c mov r0, r6
 *   @0x11f460 bl 0x17e850 <_ZN8Graphics11SurfaceCopyEPviiS0_iiii>
 *   @0x11f464 mov r0, r5
 *   @0x11f468 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x11f46c add sp, sp, #28
 *   @0x11f470 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11f474 b 0x171808 <_Z26YYGML_surface_reset_targetv>
 *   @0x11f478 ldr r0, [pc, #0x14]
 *   @0x11f47c mov r1, #0
 *   @0x11f480 add r0, pc, r0
 *   @0x11f484 add sp, sp, #28
 *   @0x11f488 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11f48c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f490 eoreq lr, r12, r0, ror r9
 *   @0x11f494 eoreq r10, r1, r8, ror #27
 *
 * ══ §2/87 ReadPNGFile(void*, int, int*, int*, bool)  0x18a24c  size 356  89 条（0x18a24c..0x18a3b0）
 * @func 0x18a24c 0x18a3b0  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool)+0x12c×3 / __divsi3×2 / operator new(unsigned int) / ReadPNG(yyPNGFile*) / ReadPNGFile(void*, int, int*, int*, bool)+0x154 / HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*) / operator delete(void*)
 * 字段偏移 top8: 0xc×6 / 0x10×4 / 0x20×3 / 0x4×2 / 0x14c×1 / 0x148×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a24c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18a250 sub sp, sp, #20
 *   @0x18a254 ldr r5, [pc, #0x14c]
 *   @0x18a258 mov r9, r0
 *   @0x18a25c ldr r12, [pc, #0x148]
 *   @0x18a260 mov r7, r2
 *   @0x18a264 ldrb lr, [sp, #0x30]
 *   @0x18a268 ldr r5, [pc, r5]
 *   @0x18a26c ldr r12, [pc, r12]
 *   @0x18a270 mov r8, r3
 *   @0x18a274 cmp lr, #0
 *   @0x18a278 ldr r6, [r5]
 *   @0x18a27c ldr r4, [r12]
 *   @0x18a280 moveq r4, #1
 *   @0x18a284 cmp r6, #0
 *   @0x18a288 beq 0x18a2c0 <_Z11ReadPNGFilePviPiS0_b+0x74>
 *   @0x18a28c ldr r3, [r6, #0xc]
 *   @0x18a290 mov r0, r3
 *   @0x18a294 mov r1, r4
 *   @0x18a298 bl 0x318d10 <__divsi3>
 *   @0x18a29c mov r1, r4
 *   @0x18a2a0 str r0, [r7]
 *   @0x18a2a4 ldr r0, [r6, #0x10]
 *   @0x18a2a8 bl 0x318d10 <__divsi3>
 *   @0x18a2ac ldr r3, [r6, #0x20]
 *   @0x18a2b0 str r0, [r8]
 *   @0x18a2b4 mov r0, r3
 *   @0x18a2b8 add sp, sp, #20
 *   @0x18a2bc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18a2c0 mov r0, #40
 *   @0x18a2c4 str r1, [sp, #0xc]
 *   @0x18a2c8 bl 0x27c524 <_Znwj>
 *   @0x18a2cc ldr r1, [sp, #0xc]
 *   @0x18a2d0 strb r6, [r0]
 *   @0x18a2d4 str r6, [r0, #0x20]
 *   @0x18a2d8 str r6, [r0, #0x24]
 *   @0x18a2dc str r9, [r0, #0x4]
 *   @0x18a2e0 str r1, [r0, #0x8]
 *   @0x18a2e4 str r0, [r5]
 *   @0x18a2e8 bl 0x189e80 <_Z7ReadPNGP9yyPNGFile>
 *   @0x18a2ec subs r6, r0, #0
 *   @0x18a2f0 beq 0x18a380 <_Z11ReadPNGFilePviPiS0_b+0x134>
 *   @0x18a2f4 cmp r4, #1
 *   @0x18a2f8 ble 0x18a3a0 <_Z11ReadPNGFilePviPiS0_b+0x154>
 *   @0x18a2fc ldr r1, [r5]
 *   @0x18a300 ldr r3, [r1, #0xc]
 *   @0x18a304 cmp r3, #1
 *   @0x18a308 ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c>
 *   @0x18a30c ldr r0, [r1, #0x10]
 *   @0x18a310 cmp r0, #1
 *   @0x18a314 movgt r6, r4
 *   @0x18a318 bgt 0x18a330 <_Z11ReadPNGFilePviPiS0_b+0xe4>
 *   @0x18a31c b 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c>
 *   @0x18a320 cmp r3, #1
 *   @0x18a324 ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c>
 *   @0x18a328 cmp r0, #1
 *   @0x18a32c ble 0x18a378 <_Z11ReadPNGFilePviPiS0_b+0x12c>
 *   @0x18a330 ldr r2, [r1, #0x20]
 *   @0x18a334 asr r1, r0, #1
 *   @0x18a338 str r0, [sp]
 *   @0x18a33c asr r0, r3, #1
 *   @0x18a340 asr r6, r6, #1
 *   @0x18a344 str r2, [sp, #0x4]
 *   @0x18a348 bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_>
 *   @0x18a34c ldr r1, [r5]
 *   @0x18a350 cmp r6, #1
 *   @0x18a354 ldr r12, [r1, #0xc]
 *   @0x18a358 ldr r0, [r1, #0x10]
 *   @0x18a35c add r12, r12, r12, lsr #31
 *   @0x18a360 add r0, r0, r0, lsr #31
 *   @0x18a364 asr r3, r12, #1
 *   @0x18a368 str r3, [r1, #0xc]
 *   @0x18a36c asr r0, r0, #1
 *   @0x18a370 str r0, [r1, #0x10]
 *   @0x18a374 bgt 0x18a320 <_Z11ReadPNGFilePviPiS0_b+0xd4>
 *   @0x18a378 mov r6, r1
 *   @0x18a37c b 0x18a290 <_Z11ReadPNGFilePviPiS0_b+0x44>
 *   @0x18a380 ldr r0, [r5]
 *   @0x18a384 bl 0x27d1d0 <_ZdlPv>
 *   @0x18a388 str r6, [r5]
 *   @0x18a38c mvn r2, #0
 *   @0x18a390 mov r3, r6
 *   @0x18a394 str r2, [r7]
 *   @0x18a398 str r2, [r8]
 *   @0x18a39c b 0x18a2b4 <_Z11ReadPNGFilePviPiS0_b+0x68>
 *   @0x18a3a0 ldr r6, [r5]
 *   @0x18a3a4 b 0x18a28c <_Z11ReadPNGFilePviPiS0_b+0x40>
 *   @0x18a3a8 eoreq r6, r6, r8, asr r3
 *   @0x18a3ac eoreq r4, r6, r8, ror #6
 *
 * ══ §3/87 IO_Init()  0x18c33c  size 356  89 条（0x18c33c..0x18c4a0）
 * @func 0x18c33c 0x18c4a0  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18c34c→0x533c58, 0x18c364→0x5346cd, 0x18c378→0x5346cc, 0x18c38c→0x534660, 0x18c3b4→0x534658, 0x18c3f0→0x5346d0, 0x18c404→0x5346cc, 0x18c42c→0x5346c8
 * 调用序列: 0xb65b0 / IO_Clear() / IO_Keymap_Clear() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6850 / 0xb6844 / 0xb6928
 * 字段偏移 top8: 0x128×1 / 0x124×1 / 0x110×1 / 0x100×1 / 0xf0×1 / 0xec×1 / 0xd0×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c33c push {r3, r4, r5, r6, r7, lr}
 *   @0x18c340 mov r2, #2560
 *   @0x18c344 ldr r4, [pc, #0x128]
 *   @0x18c348 mov r1, #0
 *   @0x18c34c ldr r3, [pc, #0x124]
 *   @0x18c350 add r4, pc, r4
 *   @0x18c354 ldr r0, [r4, r3]
 *   @0x18c358 bl 0xb65b0 <memset@plt>
 *   @0x18c35c bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x18c360 bl 0x18c314 <_Z15IO_Keymap_Clearv>
 *   @0x18c364 ldr r3, [pc, #0x110]
 *   @0x18c368 ldr r3, [r4, r3]
 *   @0x18c36c ldrb r2, [r3]
 *   @0x18c370 cmp r2, #0
 *   @0x18c374 bne 0x18c3f0 <_Z7IO_Initv+0xb4>
 *   @0x18c378 ldr r2, [pc, #0x100]
 *   @0x18c37c ldr r2, [r4, r2]
 *   @0x18c380 ldrb r2, [r2]
 *   @0x18c384 cmp r2, #0
 *   @0x18c388 bne 0x18c3f0 <_Z7IO_Initv+0xb4>
 *   @0x18c38c ldr lr, [pc, #0xf0]
 *   @0x18c390 mov r3, #1
 *   @0x18c394 ldr r1, [pc, #0xec]
 *   @0x18c398 mov r0, #5632
 *   @0x18c39c mov r2, #171
 *   @0x18c3a0 mov r12, #128
 *   @0x18c3a4 ldr r5, [r4, lr]
 *   @0x18c3a8 add r1, pc, r1
 *   @0x18c3ac str r12, [r5]
 *   @0x18c3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18c3b4 ldr r3, [pc, #0xd0]
 *   @0x18c3b8 ldr r12, [r5]
 *   @0x18c3bc ldr r3, [r4, r3]
 *   @0x18c3c0 cmp r12, #0
 *   @0x18c3c4 str r0, [r3]
 *   @0x18c3c8 pople {r3, r4, r5, r6, r7, pc}
 *   @0x18c3cc mov r2, #0
 *   @0x18c3d0 mov r3, r2
 *   @0x18c3d4 add r1, r0, r2
 *   @0x18c3d8 add r2, r2, #44
 *   @0x18c3dc strh r3, [r1, #2]
 *   @0x18c3e0 add r3, r3, #1
 *   @0x18c3e4 cmp r3, r12
 *   @0x18c3e8 bne 0x18c3d4 <_Z7IO_Initv+0x98>
 *   @0x18c3ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x18c3f0 ldr r2, [pc, #0x98]
 *   @0x18c3f4 ldr r5, [r4, r2]
 *   @0x18c3f8 ldr r2, [r5]
 *   @0x18c3fc cmp r2, #0
 *   @0x18c400 beq 0x18c38c <_Z7IO_Initv+0x50>
 *   @0x18c404 ldr r1, [pc, #0x74]
 *   @0x18c408 ldr r7, [pc, #0x84]
 *   @0x18c40c ldr r1, [r4, r1]
 *   @0x18c410 add r7, pc, r7
 *   @0x18c414 ldrb r1, [r1]
 *   @0x18c418 cmp r1, #0
 *   @0x18c41c ldrne r7, [pc, #0x74]
 *   @0x18c420 movne r1, #0
 *   @0x18c424 strbne r1, [r3]
 *   @0x18c428 addne r7, pc, r7
 *   @0x18c42c ldr r3, [pc, #0x68]
 *   @0x18c430 ldr r6, [r4, r3]
 *   @0x18c434 ldr r0, [r6]
 *   @0x18c438 cmp r0, #0
 *   @0x18c43c moveq r0, r2
 *   @0x18c440 beq 0x18c44c <_Z7IO_Initv+0x110>
 *   @0x18c444 bl 0xb6850 <fclose@plt>
 *   @0x18c448 ldr r0, [r5]
 *   @0x18c44c mov r1, r7
 *   @0x18c450 bl 0xb6844 <fopen@plt>
 *   @0x18c454 cmp r0, #0
 *   @0x18c458 str r0, [r6]
 *   @0x18c45c beq 0x18c38c <_Z7IO_Initv+0x50>
 *   @0x18c460 mov r1, #0
 *   @0x18c464 mov r2, #2
 *   @0x18c468 mov r3, r1
 *   @0x18c46c bl 0xb6928 <setvbuf@plt>
 *   @0x18c470 b 0x18c38c <_Z7IO_Initv+0x50>
 *   @0x18c474 eoreq r5, r6, r0, lsl #18
 *   @0x18c478 .word 0xffffe9c4
 *   @0x18c47c .word 0xffffe9c8
 *   @0x18c480 .word 0xffffe9cc
 *   @0x18c484 .word 0xffffdf00
 *   @0x18c488 andseq pc, r11, r4, lsr #29
 *   @0x18c48c .word 0xffffdf04
 *   @0x18c490 .word 0xffffe9d0
 *   @0x18c494 andseq pc, r11, r8, lsr lr
 *   @0x18c498 ldrsbeq r11, [r10], -r0
 *   @0x18c49c .word 0xffffe97c
 *
 * ══ §4/87 Part_SetupEmbeddedImages()  0x1a58d8  size 356  89 条（0x1a58d8..0x1a5a3c）
 * @func 0x1a58d8 0x1a5a50  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: EmbeddedImage_Find(char*, bool)×14
 * 字段偏移 top8: 0x120×1 / 0x110×1 / 0x104×1 / 0x4×1 / 0xf4×1 / 0x8×1 / 0xe4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a58d8 ldr r0, [pc, #0x120]
 *   @0x1a58dc mov r1, #1
 *   @0x1a58e0 push {r4, lr}
 *   @0x1a58e4 add r0, pc, r0
 *   @0x1a58e8 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a58ec ldr r4, [pc, #0x110]
 *   @0x1a58f0 mov r1, #1
 *   @0x1a58f4 ldr r4, [pc, r4]
 *   @0x1a58f8 str r0, [r4]
 *   @0x1a58fc ldr r0, [pc, #0x104]
 *   @0x1a5900 add r0, pc, r0
 *   @0x1a5904 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5908 mov r1, #1
 *   @0x1a590c str r0, [r4, #0x4]
 *   @0x1a5910 ldr r0, [pc, #0xf4]
 *   @0x1a5914 add r0, pc, r0
 *   @0x1a5918 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a591c mov r1, #1
 *   @0x1a5920 str r0, [r4, #0x8]
 *   @0x1a5924 ldr r0, [pc, #0xe4]
 *   @0x1a5928 add r0, pc, r0
 *   @0x1a592c bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5930 mov r1, #1
 *   @0x1a5934 str r0, [r4, #0xc]
 *   @0x1a5938 ldr r0, [pc, #0xd4]
 *   @0x1a593c add r0, pc, r0
 *   @0x1a5940 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5944 mov r1, #1
 *   @0x1a5948 str r0, [r4, #0x10]
 *   @0x1a594c ldr r0, [pc, #0xc4]
 *   @0x1a5950 add r0, pc, r0
 *   @0x1a5954 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5958 mov r1, #1
 *   @0x1a595c str r0, [r4, #0x14]
 *   @0x1a5960 ldr r0, [pc, #0xb4]
 *   @0x1a5964 add r0, pc, r0
 *   @0x1a5968 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a596c mov r1, #1
 *   @0x1a5970 str r0, [r4, #0x18]
 *   @0x1a5974 ldr r0, [pc, #0xa4]
 *   @0x1a5978 add r0, pc, r0
 *   @0x1a597c bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5980 mov r1, #1
 *   @0x1a5984 str r0, [r4, #0x1c]
 *   @0x1a5988 ldr r0, [pc, #0x94]
 *   @0x1a598c add r0, pc, r0
 *   @0x1a5990 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a5994 mov r1, #1
 *   @0x1a5998 str r0, [r4, #0x20]
 *   @0x1a599c ldr r0, [pc, #0x84]
 *   @0x1a59a0 add r0, pc, r0
 *   @0x1a59a4 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a59a8 mov r1, #1
 *   @0x1a59ac str r0, [r4, #0x24]
 *   @0x1a59b0 ldr r0, [pc, #0x74]
 *   @0x1a59b4 add r0, pc, r0
 *   @0x1a59b8 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a59bc mov r1, #1
 *   @0x1a59c0 str r0, [r4, #0x28]
 *   @0x1a59c4 ldr r0, [pc, #0x64]
 *   @0x1a59c8 add r0, pc, r0
 *   @0x1a59cc bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a59d0 mov r1, #1
 *   @0x1a59d4 str r0, [r4, #0x2c]
 *   @0x1a59d8 ldr r0, [pc, #0x54]
 *   @0x1a59dc add r0, pc, r0
 *   @0x1a59e0 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a59e4 mov r1, #1
 *   @0x1a59e8 str r0, [r4, #0x30]
 *   @0x1a59ec ldr r0, [pc, #0x44]
 *   @0x1a59f0 add r0, pc, r0
 *   @0x1a59f4 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb>
 *   @0x1a59f8 str r0, [r4, #0x34]
 *   @0x1a59fc pop {r4, pc}
 *   @0x1a5a00 mulseq r9, r12, r8
 *   @0x1a5a04 eoreq r10, r4, r8, asr #29
 *   @0x1a5a08 mulseq r9, r0, r8
 *   @0x1a5a0c andseq r0, r9, r12, lsl #17
 *   @0x1a5a10 andseq r0, r9, r8, lsl #17
 *   @0x1a5a14 andseq r0, r9, r4, lsl #17
 *   @0x1a5a18 andseq r0, r9, r0, lsl #17
 *   @0x1a5a1c andseq r0, r9, r12, ror r8
 *   @0x1a5a20 andseq r0, r9, r8, ror r8
 *   @0x1a5a24 andseq r0, r9, r4, ror r8
 *   @0x1a5a28 andseq r0, r9, r0, ror r8
 *   @0x1a5a2c andseq r0, r9, r12, ror #16
 *   @0x1a5a30 andseq r0, r9, r12, ror #16
 *   @0x1a5a34 andseq r0, r9, r8, ror #16
 *   @0x1a5a38 andseq r0, r9, r4, ror #16
 *
 * ══ §5/87 CSprite::AddFromSprite(CSprite*)  0x1e5b2c  size 356  89 条（0x1e5b2c..0x1e5c90）
 * @func 0x1e5b2c 0x1e5c90  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::AddFromSprite(CSprite*)+0x110 / operator new(unsigned int) / CBitmap32::CBitmap32(CBitmap32*) / CBitmap32::Stretch(int, int) / CSprite::InitTexture() / CSprite::InitLocalTPE()
 * 字段偏移 top8: 0x18×11 / 0x48×7 / 0x2×5 / 0x1c×2 / 0x104×1 / 0x44×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5b2c ldr r3, [r0, #0x18]
 *   @0x1e5b30 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e5b34 cmp r3, #0
 *   @0x1e5b38 mov r6, r1
 *   @0x1e5b3c mov r4, r0
 *   @0x1e5b40 ldreq r2, [r1, #0x1c]
 *   @0x1e5b44 ldreq r3, [r1, #0x20]
 *   @0x1e5b48 ldr r1, [r0, #0x48]
 *   @0x1e5b4c streq r2, [r0, #0x1c]
 *   @0x1e5b50 streq r3, [r0, #0x20]
 *   @0x1e5b54 cmp r1, #0
 *   @0x1e5b58 beq 0x1e5c64 <_ZN7CSprite13AddFromSpriteEPS_+0x138>
 *   @0x1e5b5c ldr r1, [r6, #0x48]
 *   @0x1e5b60 cmp r1, #0
 *   @0x1e5b64 beq 0x1e5c74 <_ZN7CSprite13AddFromSpriteEPS_+0x148>
 *   @0x1e5b68 ldr r12, [r4, #0x18]
 *   @0x1e5b6c movw r3, #0x6ae
 *   @0x1e5b70 ldr r1, [r6, #0x18]
 *   @0x1e5b74 add r0, r4, #72
 *   @0x1e5b78 ldr r2, [pc, #0x104]
 *   @0x1e5b7c add r1, r12, r1
 *   @0x1e5b80 add r2, pc, r2
 *   @0x1e5b84 lsl r1, r1, #2
 *   @0x1e5b88 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e5b8c ldr r2, [r6, #0x18]
 *   @0x1e5b90 ldr r3, [r4, #0x18]
 *   @0x1e5b94 cmp r2, #0
 *   @0x1e5b98 add r2, r3, r2
 *   @0x1e5b9c str r2, [r4, #0x44]
 *   @0x1e5ba0 ble 0x1e5c3c <_ZN7CSprite13AddFromSpriteEPS_+0x110>
 *   @0x1e5ba4 mov r5, #0
 *   @0x1e5ba8 mov r7, r5
 *   @0x1e5bac b 0x1e5bb4 <_ZN7CSprite13AddFromSpriteEPS_+0x88>
 *   @0x1e5bb0 ldr r3, [r4, #0x18]
 *   @0x1e5bb4 ldr r2, [r4, #0x48]
 *   @0x1e5bb8 add r3, r5, r3
 *   @0x1e5bbc ldr r3, [r2, r3, lsl #2]
 *   @0x1e5bc0 cmp r3, #0
 *   @0x1e5bc4 mov r0, r3
 *   @0x1e5bc8 beq 0x1e5be8 <_ZN7CSprite13AddFromSpriteEPS_+0xbc>
 *   @0x1e5bcc ldr r3, [r3]
 *   @0x1e5bd0 ldr r3, [r3, #0x4]
 *   @0x1e5bd4 blx r3
 *   @0x1e5bd8 ldr r2, [r4, #0x18]
 *   @0x1e5bdc ldr r3, [r4, #0x48]
 *   @0x1e5be0 add r2, r5, r2
 *   @0x1e5be4 str r7, [r3, r2, lsl #2]
 *   @0x1e5be8 mov r0, #24
 *   @0x1e5bec bl 0x27c524 <_Znwj>
 *   @0x1e5bf0 ldr r3, [r6, #0x48]
 *   @0x1e5bf4 ldr r1, [r3, r5, lsl #2]
 *   @0x1e5bf8 mov r8, r0
 *   @0x1e5bfc bl 0x165f98 <_ZN9CBitmap32C2EPS_>
 *   @0x1e5c00 ldr r3, [r4, #0x18]
 *   @0x1e5c04 ldr r0, [r4, #0x48]
 *   @0x1e5c08 add r3, r5, r3
 *   @0x1e5c0c ldr r1, [r4, #0x1c]
 *   @0x1e5c10 ldr r2, [r4, #0x20]
 *   @0x1e5c14 add r5, r5, #1
 *   @0x1e5c18 str r8, [r0, r3, lsl #2]
 *   @0x1e5c1c ldr r0, [r4, #0x48]
 *   @0x1e5c20 ldr r0, [r0, r3, lsl #2]
 *   @0x1e5c24 bl 0x1673ac <_ZN9CBitmap327StretchEii>
 *   @0x1e5c28 ldr r3, [r6, #0x18]
 *   @0x1e5c2c cmp r3, r5
 *   @0x1e5c30 bgt 0x1e5bb0 <_ZN7CSprite13AddFromSpriteEPS_+0x84>
 *   @0x1e5c34 ldr r2, [r4, #0x18]
 *   @0x1e5c38 add r2, r3, r2
 *   @0x1e5c3c str r2, [r4, #0x18]
 *   @0x1e5c40 mov r0, r4
 *   @0x1e5c44 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e5c48 mov r0, r4
 *   @0x1e5c4c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e5c50 mov r0, r4
 *   @0x1e5c54 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *   @0x1e5c58 mov r0, r4
 *   @0x1e5c5c pop {r4, r5, r6, r7, r8, lr}
 *   @0x1e5c60 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e5c64 ldr r0, [pc, #0x1c]
 *   @0x1e5c68 add r0, pc, r0
 *   @0x1e5c6c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e5c70 b 0x1e5b5c <_ZN7CSprite13AddFromSpriteEPS_+0x30>
 *   @0x1e5c74 ldr r0, [pc, #0x10]
 *   @0x1e5c78 add r0, pc, r0
 *   @0x1e5c7c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e5c80 b 0x1e5b68 <_ZN7CSprite13AddFromSpriteEPS_+0x3c>
 *   @0x1e5c84 andseq r12, r6, r4, lsr #17
 *   @0x1e5c88 ldrsheq r12, [r6], -r4
 *   @0x1e5c8c andseq r12, r6, r12, lsr #16
 *
 * ══ §6/87 CSprite::Clear()  0x1e6b4c  size 356  89 条（0x1e6b4c..0x1e6cb0）
 * @func 0x1e6b4c 0x1e6cb0  size 356  89 条
 * 级别: 骨架（逐指令锚点；下方 C 译文尚待原版差分）
 * 边界校正：.dynsym size=356、.ARM.exidx 下一函数及下一个 .dynsym 入口均为 0x1e6cb0；
 * 旧 @func 的 0x1e6cc4/376/94 多包了 LoadFromAnimation 的前 5 条，锚点本身未移动。
 * 静态译文：reconstruction/reverse-v1/c/csprite_clear/src/csprite_clear.c；未声称等价。
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / CSkeletonSprite::~CSkeletonSprite() / operator delete(void*) / CSprite::Clear()+0x9c / CSprite::FreeTexture() / 0xb65b0 / CSprite::FreeMask() / CSprite::Clear()+0x14c
 * 字段偏移 top8: 0x44×5 / 0x48×4 / 0x54×3 / 0x2×3 / 0x74×2 / 0x58×2 / 0x36×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6b4c ldr r3, [r0, #0x74]
 *   @0x1e6b50 push {r4, r5, r6, lr}
 *   @0x1e6b54 cmp r3, #1
 *   @0x1e6b58 mov r4, r0
 *   @0x1e6b5c beq 0x1e6ca8 <_ZN7CSprite5ClearEv+0x15c>
 *   @0x1e6b60 ldr r5, [r4, #0x58]
 *   @0x1e6b64 cmp r5, #0
 *   @0x1e6b68 beq 0x1e6b84 <_ZN7CSprite5ClearEv+0x38>
 *   @0x1e6b6c mov r0, r5
 *   @0x1e6b70 bl 0xbd910 <_ZN15CSkeletonSpriteD2Ev>
 *   @0x1e6b74 mov r0, r5
 *   @0x1e6b78 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e6b7c mov r3, #0
 *   @0x1e6b80 str r3, [r4, #0x58]
 *   @0x1e6b84 ldr r0, [r4, #0x54]
 *   @0x1e6b88 cmp r0, #0
 *   @0x1e6b8c beq 0x1e6b9c <_ZN7CSprite5ClearEv+0x50>
 *   @0x1e6b90 ldrb r3, [r4, #0x36]
 *   @0x1e6b94 cmp r3, #0
 *   @0x1e6b98 bne 0x1e6c6c <_ZN7CSprite5ClearEv+0x120>
 *   @0x1e6b9c ldr r2, [r4, #0x44]
 *   @0x1e6ba0 cmp r2, #0
 *   @0x1e6ba4 movgt r5, #0
 *   @0x1e6ba8 movgt r6, r5
 *   @0x1e6bac ble 0x1e6be8 <_ZN7CSprite5ClearEv+0x9c>
 *   @0x1e6bb0 ldr r3, [r4, #0x48]
 *   @0x1e6bb4 ldr r3, [r3, r5, lsl #2]
 *   @0x1e6bb8 cmp r3, #0
 *   @0x1e6bbc mov r0, r3
 *   @0x1e6bc0 beq 0x1e6bdc <_ZN7CSprite5ClearEv+0x90>
 *   @0x1e6bc4 ldr r3, [r3]
 *   @0x1e6bc8 ldr r3, [r3, #0x4]
 *   @0x1e6bcc blx r3
 *   @0x1e6bd0 ldr r3, [r4, #0x48]
 *   @0x1e6bd4 ldr r2, [r4, #0x44]
 *   @0x1e6bd8 str r6, [r3, r5, lsl #2]
 *   @0x1e6bdc add r5, r5, #1
 *   @0x1e6be0 cmp r2, r5
 *   @0x1e6be4 bgt 0x1e6bb0 <_ZN7CSprite5ClearEv+0x64>
 *   @0x1e6be8 mov r0, r4
 *   @0x1e6bec mov r5, #0
 *   @0x1e6bf0 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv>
 *   @0x1e6bf4 ldr r0, [r4, #0x48]
 *   @0x1e6bf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6bfc ldr r0, [r4, #0x50]
 *   @0x1e6c00 str r5, [r4, #0x48]
 *   @0x1e6c04 str r5, [r4, #0x44]
 *   @0x1e6c08 str r5, [r4, #0x18]
 *   @0x1e6c0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6c10 mov r1, r5
 *   @0x1e6c14 mov r2, #16
 *   @0x1e6c18 str r5, [r4, #0x50]
 *   @0x1e6c1c str r5, [r4, #0x4c]
 *   @0x1e6c20 add r0, r4, #8
 *   @0x1e6c24 bl 0xb65b0 <memset@plt>
 *   @0x1e6c28 mov r3, #1
 *   @0x1e6c2c strb r5, [r4, #0x33]
 *   @0x1e6c30 mov r0, r4
 *   @0x1e6c34 str r5, [r4, #0x4]
 *   @0x1e6c38 str r5, [r4, #0x24]
 *   @0x1e6c3c str r5, [r4, #0x28]
 *   @0x1e6c40 str r5, [r4, #0x54]
 *   @0x1e6c44 str r3, [r4, #0x1c]
 *   @0x1e6c48 str r3, [r4, #0x20]
 *   @0x1e6c4c strb r3, [r4, #0x32]
 *   @0x1e6c50 strb r3, [r4, #0x34]
 *   @0x1e6c54 strb r3, [r4, #0x30]
 *   @0x1e6c58 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv>
 *   @0x1e6c5c str r5, [r4, #0x5c]
 *   @0x1e6c60 str r5, [r4, #0x60]
 *   @0x1e6c64 str r5, [r4, #0x74]
 *   @0x1e6c68 pop {r4, r5, r6, pc}
 *   @0x1e6c6c ldr r3, [r4, #0x44]
 *   @0x1e6c70 cmp r3, #0
 *   @0x1e6c74 ble 0x1e6c98 <_ZN7CSprite5ClearEv+0x14c>
 *   @0x1e6c78 mov r5, #0
 *   @0x1e6c7c ldr r0, [r0, r5, lsl #2]
 *   @0x1e6c80 add r5, r5, #1
 *   @0x1e6c84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6c88 ldr r3, [r4, #0x44]
 *   @0x1e6c8c ldr r0, [r4, #0x54]
 *   @0x1e6c90 cmp r3, r5
 *   @0x1e6c94 bgt 0x1e6c7c <_ZN7CSprite5ClearEv+0x130>
 *   @0x1e6c98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6c9c mov r3, #0
 *   @0x1e6ca0 strb r3, [r4, #0x36]
 *   @0x1e6ca4 b 0x1e6b9c <_ZN7CSprite5ClearEv+0x50>
 *   @0x1e6ca8 bl 0x1e68b0 <_ZN7CSprite12ClearSWFDataEv>
 *   @0x1e6cac b 0x1e6b60 <_ZN7CSprite5ClearEv+0x14>
 *
 * ══ §7/87 CDS_Priority::ReadFromString(char const*, bool)  0x2098d0  size 356  89 条（0x2098d0..0x209a34）
 * @func 0x2098d0 0x209a34  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×2 / CStream::~CStream()×2 / operator delete(void*)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / ReadValue(RValue&, CStream&, int)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertFromString(char const*)
 * 字段偏移 top8: 0x4×5 / 0xd4×1 / 0x10×1 / 0x14×1 / 0x84×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2098d0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2098d4 mov r4, r0
 *   @0x2098d8 mov r0, #32
 *   @0x2098dc mov r7, r2
 *   @0x2098e0 mov r6, r1
 *   @0x2098e4 bl 0x27c524 <_Znwj>
 *   @0x2098e8 mov r1, #0
 *   @0x2098ec mov r5, r0
 *   @0x2098f0 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x2098f4 mov r0, r5
 *   @0x2098f8 mov r1, r6
 *   @0x2098fc bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x209900 mov r0, r5
 *   @0x209904 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x209908 sub r3, r0, #500
 *   @0x20990c sub r3, r3, #1
 *   @0x209910 cmp r3, #1
 *   @0x209914 bls 0x209934 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x64>
 *   @0x209918 subs r0, r5, #0
 *   @0x20991c beq 0x209a14 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x144>
 *   @0x209920 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x209924 mov r0, r5
 *   @0x209928 bl 0x27d1d0 <_ZdlPv>
 *   @0x20992c mov r0, #0
 *   @0x209930 pop {r3, r4, r5, r6, r7, pc}
 *   @0x209934 cmp r7, #0
 *   @0x209938 movne r7, #1
 *   @0x20993c beq 0x209a18 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x148>
 *   @0x209940 mov r0, r4
 *   @0x209944 bl 0x209768 <_ZN12CDS_Priority5ClearEv>
 *   @0x209948 mov r0, r5
 *   @0x20994c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x209950 ldr r2, [pc, #0xd4]
 *   @0x209954 mov r3, #2544
 *   @0x209958 add r2, pc, r2
 *   @0x20995c lsl r1, r0, #4
 *   @0x209960 str r0, [r4, #0x4]
 *   @0x209964 add r0, r4, #20
 *   @0x209968 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20996c ldr r1, [r4, #0x4]
 *   @0x209970 cmp r1, #0
 *   @0x209974 str r1, [r4, #0x10]
 *   @0x209978 ble 0x2099a4 <_ZN12CDS_Priority14ReadFromStringEPKcb+0xd4>
 *   @0x20997c mov r6, #0
 *   @0x209980 ldr r0, [r4, #0x14]
 *   @0x209984 mov r1, r5
 *   @0x209988 mov r2, r7
 *   @0x20998c add r0, r0, r6, lsl #4
 *   @0x209990 add r6, r6, #1
 *   @0x209994 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x209998 ldr r1, [r4, #0x4]
 *   @0x20999c cmp r1, r6
 *   @0x2099a0 bgt 0x209980 <_ZN12CDS_Priority14ReadFromStringEPKcb+0xb0>
 *   @0x2099a4 ldr r2, [pc, #0x84]
 *   @0x2099a8 movw r3, #0x9f7
 *   @0x2099ac lsl r1, r1, #4
 *   @0x2099b0 add r0, r4, #12
 *   @0x2099b4 add r2, pc, r2
 *   @0x2099b8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2099bc ldr r3, [r4, #0x4]
 *   @0x2099c0 cmp r3, #0
 *   @0x2099c4 str r3, [r4, #0x8]
 *   @0x2099c8 movgt r6, #0
 *   @0x2099cc ble 0x2099f4 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x124>
 *   @0x2099d0 ldr r0, [r4, #0xc]
 *   @0x2099d4 mov r1, r5
 *   @0x2099d8 mov r2, r7
 *   @0x2099dc add r0, r0, r6, lsl #4
 *   @0x2099e0 add r6, r6, #1
 *   @0x2099e4 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x2099e8 ldr r3, [r4, #0x4]
 *   @0x2099ec cmp r3, r6
 *   @0x2099f0 bgt 0x2099d0 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x100>
 *   @0x2099f4 cmp r5, #0
 *   @0x2099f8 beq 0x209a0c <_ZN12CDS_Priority14ReadFromStringEPKcb+0x13c>
 *   @0x2099fc mov r0, r5
 *   @0x209a00 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x209a04 mov r0, r5
 *   @0x209a08 bl 0x27d1d0 <_ZdlPv>
 *   @0x209a0c mov r0, #1
 *   @0x209a10 pop {r3, r4, r5, r6, r7, pc}
 *   @0x209a14 pop {r3, r4, r5, r6, r7, pc}
 *   @0x209a18 movw r7, #0x1f5
 *   @0x209a1c cmp r0, r7
 *   @0x209a20 moveq r7, #2
 *   @0x209a24 movne r7, #0
 *   @0x209a28 b 0x209940 <_ZN12CDS_Priority14ReadFromStringEPKcb+0x70>
 *   @0x209a2c mulseq r4, r4, lr
 *   @0x209a30 andseq r9, r4, r8, lsr lr
 *
 * ══ §8/87 Audio_SetEmitterFalloff(int, double, double, double)  0x216c94  size 356  89 条（0x216c94..0x216df8）
 * @func 0x216c94 0x216df8  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a78×3 / Audio_SetEmitterFalloff(int, double, double, double)+0x148 / Audio_SetEmitterFalloff(int, double, double, double)+0x8c / Audio_NoiseIsPlaying(CNoise*) / 0xb6a54
 * 字段偏移 top8: 0x2×5 / 0x10×3 / 0x34×2 / 0x38×2 / 0x148×1 / 0x12c×1 / 0x40×1 / 0x44×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216c94 ldr r1, [pc, #0x148]
 *   @0x216c98 vmov d7, r2, r3
 *   @0x216c9c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x216ca0 vpush {d8, d9}
 *   @0x216ca4 ldr r1, [pc, r1]
 *   @0x216ca8 ldrb r3, [r1]
 *   @0x216cac cmp r3, #0
 *   @0x216cb0 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148>
 *   @0x216cb4 ldr r3, [pc, #0x12c]
 *   @0x216cb8 add r3, pc, r3
 *   @0x216cbc ldr r4, [r3, #0x40]
 *   @0x216cc0 cmp r4, r0
 *   @0x216cc4 movgt r4, #0
 *   @0x216cc8 movle r4, #1
 *   @0x216ccc orrs r4, r4, r0, lsr #31
 *   @0x216cd0 bne 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148>
 *   @0x216cd4 ldr r3, [r3, #0x44]
 *   @0x216cd8 ldr r6, [r3, r0, lsl #2]
 *   @0x216cdc cmp r6, #0
 *   @0x216ce0 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148>
 *   @0x216ce4 vcvt.f32.f64 s16, d7
 *   @0x216ce8 vldr d6, [sp, #48]
 *   @0x216cec vldr d7, [sp, #56]
 *   @0x216cf0 ldr r7, [r6, #0x34]
 *   @0x216cf4 cmp r7, #0
 *   @0x216cf8 vcvt.f32.f64 s17, d6
 *   @0x216cfc vstr s16, [r6, #28]
 *   @0x216d00 vcvt.f32.f64 s18, d7
 *   @0x216d04 vstr s17, [r6, #32]
 *   @0x216d08 vstr s18, [r6, #36]
 *   @0x216d0c ble 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148>
 *   @0x216d10 ldr r9, [pc, #0xd4]
 *   @0x216d14 mov r3, r7
 *   @0x216d18 add r9, pc, r9
 *   @0x216d1c b 0x216d30 <_Z23Audio_SetEmitterFalloffiddd+0x9c>
 *   @0x216d20 add r4, r4, #1
 *   @0x216d24 cmp r4, r7
 *   @0x216d28 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148>
 *   @0x216d2c ldr r3, [r6, #0x34]
 *   @0x216d30 cmp r3, r4
 *   @0x216d34 ble 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c>
 *   @0x216d38 ldr r3, [r6, #0x38]
 *   @0x216d3c ldr r5, [r3, r4, lsl #2]
 *   @0x216d40 cmp r5, #0
 *   @0x216d44 mov r0, r5
 *   @0x216d48 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c>
 *   @0x216d4c bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise>
 *   @0x216d50 cmp r0, #0
 *   @0x216d54 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c>
 *   @0x216d58 ldr r8, [pc, #0x90]
 *   @0x216d5c movw r1, #0x1023
 *   @0x216d60 ldr r0, [r5, #0x10]
 *   @0x216d64 ldr r8, [pc, r8]
 *   @0x216d68 vmov r2, s17
 *   @0x216d6c ldr r3, [r8]
 *   @0x216d70 ldr r0, [r3, r0, lsl #2]
 *   @0x216d74 bl 0xb6a78 <alSourcef@plt>
 *   @0x216d78 ldr r3, [r8]
 *   @0x216d7c ldr r0, [r5, #0x10]
 *   @0x216d80 movw r1, #0x1020
 *   @0x216d84 vmov r2, s16
 *   @0x216d88 ldr r0, [r3, r0, lsl #2]
 *   @0x216d8c bl 0xb6a78 <alSourcef@plt>
 *   @0x216d90 ldr r3, [r8]
 *   @0x216d94 ldr r0, [r5, #0x10]
 *   @0x216d98 movw r1, #0x1021
 *   @0x216d9c vmov r2, s18
 *   @0x216da0 ldr r0, [r3, r0, lsl #2]
 *   @0x216da4 bl 0xb6a78 <alSourcef@plt>
 *   @0x216da8 bl 0xb6a54 <alGetError@plt>
 *   @0x216dac subs r2, r0, #0
 *   @0x216db0 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c>
 *   @0x216db4 ldr r3, [pc, #0x38]
 *   @0x216db8 mov r1, r9
 *   @0x216dbc add r4, r4, #1
 *   @0x216dc0 ldr r3, [pc, r3]
 *   @0x216dc4 ldr r0, [r3]
 *   @0x216dc8 ldr r3, [r0]
 *   @0x216dcc ldr r3, [r3, #0xc]
 *   @0x216dd0 blx r3
 *   @0x216dd4 cmp r4, r7
 *   @0x216dd8 bne 0x216d2c <_Z23Audio_SetEmitterFalloffiddd+0x98>
 *   @0x216ddc vpop {d8, d9}
 *   @0x216de0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x216de4 andseq r8, sp, r12, lsl #1
 *   @0x216de8 ldrsbeq lr, [r3], #-92
 *   @0x216dec ldrsheq r12, [r3], -r12
 *   @0x216df0 andseq r10, sp, r8, ror #12
 *   @0x216df4 andseq r6, sp, r4, asr r9
 *
 * ══ §9/87 AddVMCodeBuffers(Buffer_Standard*)  0x29f380  size 356  89 条（0x29f380..0x29f4e4）
 * @func 0x29f380 0x29f4e4  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WriteData(Buffer_Standard*, unsigned char const*, int) / WriteString(Buffer_Standard*, char const*)
 * 字段偏移 top8: 0x4×5 / 0x38×4 / 0x30×3 / 0x8×3 / 0x14c×1 / 0x104×1 / 0x50×1 / 0x5c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29f380 ldr r3, [pc, #0x14c]
 *   @0x29f384 mov r1, #5
 *   @0x29f388 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29f38c ldr r3, [pc, r3]
 *   @0x29f390 ldr r12, [r0]
 *   @0x29f394 add r9, r0, #44
 *   @0x29f398 ldr r4, [r3]
 *   @0x29f39c mov r6, r0
 *   @0x29f3a0 mov r8, #0
 *   @0x29f3a4 sub sp, sp, #12
 *   @0x29f3a8 str r8, [r0, #0x38]
 *   @0x29f3ac mov r2, r9
 *   @0x29f3b0 vmov s15, r4
 *   @0x29f3b4 vcvt.f64.u32 d7, s15
 *   @0x29f3b8 vmov r4, r5, d7
 *   @0x29f3bc vstr s14, [r6, #44]
 *   @0x29f3c0 str r5, [r6, #0x30]
 *   @0x29f3c4 ldr r3, [r12, #0x8]
 *   @0x29f3c8 blx r3
 *   @0x29f3cc ldr r3, [pc, #0x104]
 *   @0x29f3d0 ldr r3, [pc, r3]
 *   @0x29f3d4 ldr r10, [r3]
 *   @0x29f3d8 cmp r10, r8
 *   @0x29f3dc beq 0x29f4cc <_Z16AddVMCodeBuffersP15Buffer_Standard+0x14c>
 *   @0x29f3e0 mov r7, r8
 *   @0x29f3e4 b 0x29f404 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x84>
 *   @0x29f3e8 mov r1, r11
 *   @0x29f3ec ldr r2, [sp, #0x4]
 *   @0x29f3f0 bl 0x29e730 <_Z9WriteDataP15Buffer_StandardPKhi>
 *   @0x29f3f4 ldr r10, [r10, #0x4]
 *   @0x29f3f8 add r8, r8, #1
 *   @0x29f3fc cmp r10, #0
 *   @0x29f400 beq 0x29f49c <_Z16AddVMCodeBuffersP15Buffer_Standard+0x11c>
 *   @0x29f404 vldr s15, [r10, #96]
 *   @0x29f408 vcvt.f64.u32 d7, s15
 *   @0x29f40c ldr r11, [r10, #0x50]
 *   @0x29f410 mov r2, r9
 *   @0x29f414 ldr r12, [r10, #0x5c]
 *   @0x29f418 mov r1, #5
 *   @0x29f41c ldr lr, [r6]
 *   @0x29f420 mov r0, r6
 *   @0x29f424 ldr r3, [r11, #0x4]
 *   @0x29f428 ldr r11, [r11, #0x10]
 *   @0x29f42c str r7, [r6, #0x38]
 *   @0x29f430 vmov r4, r5, d7
 *   @0x29f434 vstr s14, [r6, #44]
 *   @0x29f438 str r3, [sp, #0x4]
 *   @0x29f43c str r5, [r6, #0x30]
 *   @0x29f440 ldr r4, [lr, #0x8]
 *   @0x29f444 str r12, [sp]
 *   @0x29f448 blx r4
 *   @0x29f44c ldr r12, [sp]
 *   @0x29f450 mov r0, r6
 *   @0x29f454 mov r1, r12
 *   @0x29f458 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f45c ldr r12, [r10, #0x6c]
 *   @0x29f460 mov r0, r6
 *   @0x29f464 mov r1, #5
 *   @0x29f468 cmp r12, #0
 *   @0x29f46c mov r2, r9
 *   @0x29f470 beq 0x29f3e8 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x68>
 *   @0x29f474 ldr r12, [r6]
 *   @0x29f478 add r8, r8, #1
 *   @0x29f47c str r7, [r6, #0x2c]
 *   @0x29f480 str r7, [r6, #0x30]
 *   @0x29f484 str r7, [r6, #0x38]
 *   @0x29f488 ldr r12, [r12, #0x8]
 *   @0x29f48c blx r12
 *   @0x29f490 ldr r10, [r10, #0x4]
 *   @0x29f494 cmp r10, #0
 *   @0x29f498 bne 0x29f404 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x84>
 *   @0x29f49c ldr r0, [pc, #0x38]
 *   @0x29f4a0 mov r2, r8
 *   @0x29f4a4 ldr r1, [pc, #0x34]
 *   @0x29f4a8 ldr r0, [pc, r0]
 *   @0x29f4ac ldr r3, [r6, #0x20]
 *   @0x29f4b0 add r1, pc, r1
 *   @0x29f4b4 ldr r0, [r0]
 *   @0x29f4b8 ldr r12, [r0]
 *   @0x29f4bc ldr r12, [r12, #0xc]
 *   @0x29f4c0 blx r12
 *   @0x29f4c4 add sp, sp, #12
 *   @0x29f4c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29f4cc mov r8, r10
 *   @0x29f4d0 b 0x29f49c <_Z16AddVMCodeBuffersP15Buffer_Standard+0x11c>
 *   @0x29f4d4 mulseq r4, r12, r7
 *   @0x29f4d8 andseq lr, r4, r0, asr r7
 *   @0x29f4dc andseq lr, r4, r12, ror #4
 *   @0x29f4e0 andeq r10, r11, r8, asr r7
 *
 * ══ §10/87 png_handle_PLTE  0x2abf64  size 356  89 条（0x2abf64..0x2ac0c8）
 * @func 0x2abf64 0x2ac0c8  size 356  89 条
 * 部分覆盖: 本节 89/163 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_crc_finish×2 / png_warning / __aeabi_uidivmod / 0x36e40c / 0x4ca214 / png_set_PLTE
 * 字段偏移 top8: 0x124×1 / 0xe0×1 / 0x18×1 / 0x40×1 / 0x30×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abf64 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2abf68 mov r5, r2
 *   @0x2abf6c .word 0xf5ad312c
 *   @0x2abf70 strmi r7, [r4], -r3, asr #26
 *   @0x2abf74 mov r6, r1
 *   @0x2abf78 bmi 0x2abf80 <png_handle_PLTE+0x1c>
 *   @0x2abf7c add r1, pc
 *   @0x2abf80 lsls r7, r3, #0x1d
 *   @0x2abf84 ldr r1, [pc, #0x124]
 *   @0x2abf88 b 0x2abfb0 <png_handle_PLTE+0x4c>
 *   @0x2abf8c bpl 0x2abf96 <png_handle_PLTE+0x32>
 *   @0x2abf90 add r1, pc
 *   @0x2abf94 .word 0xf894fa4b
 *   @0x2abf98 .word 0xf8d471ea
 *   @0x2abf9c ldreq r3, [r10, r12, lsr #2]!
 *   @0x2abfa0 orr r3, r3, #0x2
 *   @0x2abfa4 str.w r3, [r4, #0x12c]
 *   @0x2abfa8 bmi 0x2abfbe <png_handle_PLTE+0x5a>
 *   @0x2abfac mov r0, r4
 *   @0x2abfb0 bl 0x2a6474 <png_warning>
 *   @0x2abfb4 mov r0, r4
 *   @0x2abfb8 bl 0x2abc94 <png_crc_finish>
 *   @0x2abfbc b 0x2ac09e <png_handle_PLTE+0x13a>
 *   @0x2abfc0 stmdale r4, {r6, r8, r9, r10, r11, r12, sp, lr}
 *   @0x2abfc4 mov r0, r5
 *   @0x2abfc8 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2abfcc cbz r1, 0x2abfe2 <png_handle_PLTE+0x7e>
 *   @0x2abfd0 mov r0, r4
 *   @0x2abfd4 ldr r1, [pc, #0xe0]
 *   @0x2abfd8 b 0x2abfb0 <png_handle_PLTE+0x4c>
 *   @0x2abfdc add r1, pc
 *   @0x2abfe0 strtmi pc, [r8], -r5, lsr #20
 *   @0x2abfe4 movs r1, #0x3
 *   @0x2abfe8 .word 0xf894ee94
 *   @0x2abfec .word 0xf10d31ea
 *   @0x2abff0 .word 0xf10d0b08
 *   @0x2abff4 blhs 0x36e40c <_ZTS13C_UTF16String+0x54b8>
 *   @0x2abff8 add.w r7, r11, #0x3
 *   @0x2abffc mov.w r10, #0x0
 *   @0x2ac000 ittet eq
 *   @0x2ac004 .word 0xf04f31eb
 *   @0x2ac008 vst2.8 {d16, d17}, [pc], r1
 *   @0x2ac00c blx 0x4ca214 <SrcVerts+0x27258>
 *   @0x2ac010 strmi pc, [r0, #0x803]
 *   @0x2ac014 it ge
 *   @0x2ac018 cmp r10, r8
 *   @0x2ac01c strtmi r0, [r0], -r3, lsl #14
 *   @0x2ac020 bge 0x2ac048 <png_handle_PLTE+0xe4>
 *   @0x2ac024 movs r2, #0x3
 *   @0x2ac028 .word 0xf899fdf1
 *   @0x2ac02c .word 0xf10a3000
 *   @0x2ac030 .word 0xf8070a01
 *   @0x2ac034 .word 0xf8993c06
 *   @0x2ac038 .word 0xf8073001
 *   @0x2ac03c .word 0xf8993c05
 *   @0x2ac040 .word 0xf8073002
 *   @0x2ac044 strb r3, [r7, r4, lsl #24]!
 *   @0x2ac048 mvn r1, #0x2
 *   @0x2ac04c mla r1, r1, r8, r5
 *   @0x2ac050 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac054 mov r3, r8
 *   @0x2ac058 mov r1, r6
 *   @0x2ac05c bl 0x2aec84 <png_set_PLTE>
 *   @0x2ac060 ldrb.w r3, [r4, #0x1ea]
 *   @0x2ac064 cmp r3, #0x3
 *   @0x2ac068 cbz r6, 0x2ac09e <png_handle_PLTE+0x13a>
 *   @0x2ac06c lsls r3, r3, #0x1b
 *   @0x2ac070 ldrh.w r3, [r4, #0x1de]
 *   @0x2ac074 uxth.w r8, r8
 *   @0x2ac078 cmp r3, r8
 *   @0x2ac07c ldr r1, [pc, #0x40]
 *   @0x2ac080 add r1, pc
 *   @0x2ac084 .word 0xf8a4f9f7
 *   @0x2ac088 bhi 0xfff8c808 <b2_toiTime+0xffffffffff833364>
 *   @0x2ac08c cmp r3, r8
 *   @0x2ac090 ldr r1, [pc, #0x30]
 *   @0x2ac094 add r1, pc
 *   @0x2ac098 .word 0xf8a6f9ed
 *   @0x2ac09c .word 0xf50d8016
 *   @0x2ac0a0 pop {r0, r1, r6, r8, r10, r11, r12, sp, lr}
 *   @0x2ac0a4 svclt #0x8ff0
 *   @0x2ac0a8 lsrs r7, r3, #0x14
 *   @0x2ac0ac lsrs r6, r5, #0x14
 *   @0x2ac0b0 lsrs r4, r7, #0x14
 *   @0x2ac0b4 lsrs r3, r6, #0x14
 *   @0x2ac0b8 lsrs r0, r6, #0x14
 *   @0x2ac0bc lsrs r2, r5, #0x14
 *   @0x2ac0c0 lsrs r4, r3, #0x12
 *   @0x2ac0c4 lsrs r7, r5, #0x12
 *
 * ══ §11/87 GifMakeSavedImage(GifFileType*, SavedImage const*)  0x2c30d0  size 356  89 条（0x2c30d0..0x2c3234）
 * @func 0x2c30d0 0x2c3234  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×3 / 0xb65bc×2 / 0xb6c28 / 0xb65b0 / GifMakeMapObject(int, GifColorType const*) / FreeLastSavedImage(GifFileType*)
 * 字段偏移 top8: 0x18×5 / 0x34×3 / 0x14×3 / 0x20×3 / 0x-c×2 / 0x-8×2 / 0x-4×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c30d0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c30d4 mov r6, r0
 *   @0x2c30d8 ldr r0, [r0, #0x34]
 *   @0x2c30dc mov r4, r1
 *   @0x2c30e0 cmp r0, #0
 *   @0x2c30e4 beq 0x2c3210 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x140>
 *   @0x2c30e8 ldr r1, [r6, #0x18]
 *   @0x2c30ec add r1, r1, #1
 *   @0x2c30f0 add r1, r1, r1, lsl #3
 *   @0x2c30f4 lsl r1, r1, #2
 *   @0x2c30f8 bl 0xb6c28 <realloc@plt>
 *   @0x2c30fc mov r5, r0
 *   @0x2c3100 str r0, [r6, #0x34]
 *   @0x2c3104 cmp r5, #0
 *   @0x2c3108 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138>
 *   @0x2c310c ldr r3, [r6, #0x18]
 *   @0x2c3110 mov r1, #0
 *   @0x2c3114 mov r2, #36
 *   @0x2c3118 add r0, r3, #1
 *   @0x2c311c str r0, [r6, #0x18]
 *   @0x2c3120 add r3, r3, r3, lsl #3
 *   @0x2c3124 add r5, r5, r3, lsl #2
 *   @0x2c3128 mov r0, r5
 *   @0x2c312c bl 0xb65b0 <memset@plt>
 *   @0x2c3130 cmp r4, #0
 *   @0x2c3134 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138>
 *   @0x2c3138 add r1, r4, #32
 *   @0x2c313c mov r3, r4
 *   @0x2c3140 mov r2, r5
 *   @0x2c3144 ldr r7, [r3]
 *   @0x2c3148 add r3, r3, #16
 *   @0x2c314c ldr lr, [r3, #-0xc]
 *   @0x2c3150 add r2, r2, #16
 *   @0x2c3154 ldr r12, [r3, #-0x8]
 *   @0x2c3158 ldr r0, [r3, #-0x4]
 *   @0x2c315c cmp r3, r1
 *   @0x2c3160 str r7, [r2, #-0x10]
 *   @0x2c3164 str lr, [r2, #-0xc]
 *   @0x2c3168 str r12, [r2, #-0x8]
 *   @0x2c316c str r0, [r2, #-0x4]
 *   @0x2c3170 bne 0x2c3144 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x74>
 *   @0x2c3174 ldr r3, [r3]
 *   @0x2c3178 str r3, [r2]
 *   @0x2c317c ldr r3, [r5, #0x14]
 *   @0x2c3180 cmp r3, #0
 *   @0x2c3184 beq 0x2c31a4 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0xd4>
 *   @0x2c3188 ldr r3, [r4, #0x14]
 *   @0x2c318c ldr r0, [r3]
 *   @0x2c3190 ldr r1, [r3, #0xc]
 *   @0x2c3194 bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType>
 *   @0x2c3198 cmp r0, #0
 *   @0x2c319c str r0, [r5, #0x14]
 *   @0x2c31a0 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154>
 *   @0x2c31a4 ldr r3, [r4, #0x8]
 *   @0x2c31a8 ldr r7, [r4, #0xc]
 *   @0x2c31ac mul r7, r7, r3
 *   @0x2c31b0 mov r0, r7
 *   @0x2c31b4 bl 0xb6544 <malloc@plt>
 *   @0x2c31b8 cmp r0, #0
 *   @0x2c31bc str r0, [r5, #0x18]
 *   @0x2c31c0 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154>
 *   @0x2c31c4 mov r2, r7
 *   @0x2c31c8 ldr r1, [r4, #0x18]
 *   @0x2c31cc bl 0xb65bc <memcpy@plt>
 *   @0x2c31d0 ldr r3, [r5, #0x20]
 *   @0x2c31d4 cmp r3, #0
 *   @0x2c31d8 beq 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138>
 *   @0x2c31dc ldr r2, [r4, #0x1c]
 *   @0x2c31e0 add r2, r2, r2, lsl #1
 *   @0x2c31e4 lsl r7, r2, #2
 *   @0x2c31e8 mov r0, r7
 *   @0x2c31ec bl 0xb6544 <malloc@plt>
 *   @0x2c31f0 cmp r0, #0
 *   @0x2c31f4 str r0, [r5, #0x20]
 *   @0x2c31f8 beq 0x2c3224 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x154>
 *   @0x2c31fc ldr r1, [r4, #0x20]
 *   @0x2c3200 mov r2, r7
 *   @0x2c3204 bl 0xb65bc <memcpy@plt>
 *   @0x2c3208 mov r0, r5
 *   @0x2c320c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c3210 mov r0, #36
 *   @0x2c3214 bl 0xb6544 <malloc@plt>
 *   @0x2c3218 mov r5, r0
 *   @0x2c321c str r0, [r6, #0x34]
 *   @0x2c3220 b 0x2c3104 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x34>
 *   @0x2c3224 mov r0, r6
 *   @0x2c3228 mov r5, #0
 *   @0x2c322c bl 0x2c306c <_Z18FreeLastSavedImageP11GifFileType>
 *   @0x2c3230 b 0x2c3208 <_Z17GifMakeSavedImageP11GifFileTypePK10SavedImage+0x138>
 *
 * ══ §12/87 anon_316cdc  0x316cdc  size 356  89 条（0x316cdc..0x316e40）
 * @func 0x316cdc 0x316e40  size 356  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfe331c74 / 0x1bcb23c / 0x13221a8 / 0x3661bc / 0x466e28
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316cdc .word 0x4604b570
 *   @0x316ce0 mlahs r0, r0, r8, pc
 *   @0x316ce4 stmibvs r3, {r0, r2, r6, r8, r9, r11, sp, lr}
 *   @0x316ce8 blvs 0xfe331c74 <b2_toiTime+0xfffffffffdbd87d0>
 *   @0x316cec stmibvs r6!, {r1, r5, r8, r11, r12, sp, pc} ^
 *   @0x316cf0 andle r4, r1, #805306379
 *   @0x316cf4 teqle r8, #136, #4
 *   @0x316cf8 movwle r4, #0xe288
 *   @0x316cfc .word 0x63653501
 *   @0x316d00 ldmdale r8, {r4, r8, r10, r11, sp} ^
 *   @0x316d04 addsmi r6, sp, #667648
 *   @0x316d08 movwhs sp, #0x1204
 *   @0x316d0c .word 0xf5a340ab
 *   @0x316d10 and r7, r1, r0, lsl #7
 *   @0x316d14 movwlo r6, #0x1b23
 *   @0x316d18 teqlt r10, r3, ror #7
 *   @0x316d1c orrvc pc, r0, #1325400064
 *   @0x316d20 .word 0x63e32509
 *   @0x316d24 .word 0x63652300
 *   @0x316d28 eorlo pc, r0, r4, lsl #17
 *   @0x316d2c cdphs p8, #0x0, c6, c0, c6, #0x3
 *   @0x316d30 blvs 0x1bcb23c <b2_toiTime+0x1471d98>
 *   @0x316d34 .word 0x0108f104
 *   @0x316d38 .word 0x00a4f8d4
 *   @0x316d3c cdp2 p7, #0x3, c15, c0, c15, #0x6
 *   @0x316d40 bvs 0x1bf1ad0 <b2_toiTime+0x149862c>
 *   @0x316d44 addsmi r6, r0, #-2147483607
 *   @0x316d48 rsbvs r4, r3, #50331648
 *   @0x316d4c movwhs r11, #0xf2c
 *   @0x316d50 rsbvs r2, r3, r1, lsl #6
 *   @0x316d54 addsmi r0, r3, #195
 *   @0x316d58 strexhvs r11, r8, [r3]
 *   @0x316d5c .word 0xf1c2d92b
 *   @0x316d60 ldrmi r0, [r3], #-513
 *   @0x316d64 teqlt r0, #-1073741768
 *   @0x316d68 ldmdbne r10, {r0, r1, r4, r5, r9, r10, lr} ^
 *   @0x316d6c ldmeq r10, {r1, r5, r7, r8, sp, lr} ^
 *   @0x316d70 movweq pc, #0x7003
 *   @0x316d74 .word 0x0108f102
 *   @0x316d78 ldrmi r4, [r4], #-1057
 *   @0x316d7c andeq pc, r8, #-1073741776
 *   @0x316d80 bne 0xfee75608 <b2_toiTime+0xfffffffffe71c164>
 *   @0x316d84 blx 0x13221a8 <b2_toiTime+0xbc8d04>
 *   @0x316d88 stmdale r1, {r0, r1, r12, sp, lr, pc}
 *   @0x316d8c and r1, r7, r12, asr #24
 *   @0x316d90 stmdavc r9, {r2, r3, r7, r10, r11, r12} ^
 *   @0x316d94 blx 0x3661bc <_ZTS12CDS_Priority+0x8214>
 *   @0x316d98 tstmi r0, #536870912
 *   @0x316d9c andseq pc, r0, #-1073741776
 *   @0x316da0 movwhs r11, #0x115d
 *   @0x316da4 .word 0xf505fa03
 *   @0x316da8 stclo p8, c7, [r1, #-140]
 *   @0x316dac blx 0x466e28 <g_RomDisk+0x6f608>
 *   @0x316db0 tstmi r0, #536870912
 *   @0x316db4 .word 0xf04fbd70
 *   @0x316db8 ldcllt p0, c3, [r0, #-1020]!
 *   @0x316dbc .word 0x4604b530
 *   @0x316dc0 addlt r6, r5, r2, lsl #28
 *   @0x316dc4 addsmi r6, r3, #12480
 *   @0x316dc8 stcvs p3, c13, [r3, #140]!
 *   @0x316dcc .word 0x0164f104
 *   @0x316dd0 .word 0xf8d01d15
 *   @0x316dd4 addmi r0, r11, #168
 *   @0x316dd8 ldrbeq lr, [r2, #-0xb05]
 *   @0x316ddc andhs r11, r0, #4, #30
 *   @0x316de0 .word 0xf5b565a2
 *   @0x316de4 stmdble r4, {r7, r8, r9, r10, r11, r12, sp}
 *   @0x316de8 svclo #0x80f5b2
 *   @0x316dec vst4.8 {d29, d30, d31, d0}, [pc], lr
 *   @0x316df0 stcvs p5, c3, [r3, #512]!
 *   @0x316df4 movwls r2, #0x101
 *   @0x316df8 movwls r10, #0x1b03
 *   @0x316dfc .word 0xf7d1462b
 *   @0x316e00 strvs pc, [r0, #0x946]!
 *   @0x316e04 stmdblt r8, {r0, r1, r11, r12, pc}
 *   @0x316e08 and r6, r3, r5, lsr #12
 *   @0x316e0c rscslo pc, pc, pc, asr #32
 *   @0x316e10 andhs lr, r0, r0
 *   @0x316e14 ldclt p0, c11, [r0, #-20]!
 *   @0x316e18 andhs r11, r2, #29360128
 *   @0x316e1c .word 0xf7cfa901
 *   @0x316e20 ldmdblt r8, {r1, r2, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x316e24 mullo r4, sp, r8
 *   @0x316e28 .word 0xd1062b1f
 *   @0x316e2c muleq r5, sp, r8
 *   @0x316e30 svclt #0x14289d
 *   @0x316e34 andhs r2, r0, r3
 *   @0x316e38 andhs lr, r3, r0
 *   @0x316e3c .word 0xf85db003
 *
 * ══ §13/87 F_BUFFER_Save_Async(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7294  size 352  88 条（0xc7294..0xc73f4）
 * @func 0xc7294 0xc7408  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int) / YYError(char const*, ...) / operator new(unsigned int) / YYStrDup(char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / KickAsyncBuffer(bool, SAsyncBuffer*, char const*, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0x20×1 / 0xdc×1 / 0xc8×1 / 0xbc×1 / 0xa0×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7294 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc7298 mov r3, #0
 *   @0xc729c ldr r4, [sp, #0x20]
 *   @0xc72a0 mov r6, r0
 *   @0xc72a4 mov r5, r3
 *   @0xc72a8 mov r1, #1
 *   @0xc72ac movt r3, #0xbff0
 *   @0xc72b0 str r5, [r0]
 *   @0xc72b4 str r3, [r0, #0x4]
 *   @0xc72b8 mov r0, r4
 *   @0xc72bc str r5, [r6, #0xc]
 *   @0xc72c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc72c4 mov r1, r5
 *   @0xc72c8 mov r9, r0
 *   @0xc72cc mov r0, r4
 *   @0xc72d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc72d4 mov r1, #2
 *   @0xc72d8 mov r10, r0
 *   @0xc72dc mov r0, r4
 *   @0xc72e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc72e4 mov r1, #3
 *   @0xc72e8 mov r8, r0
 *   @0xc72ec mov r0, r4
 *   @0xc72f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc72f4 ldr r3, [pc, #0xdc]
 *   @0xc72f8 ldr r3, [pc, r3]
 *   @0xc72fc ldr r3, [r3]
 *   @0xc7300 cmp r3, r5
 *   @0xc7304 mov r7, r0
 *   @0xc7308 beq 0xc7318 <_Z19F_BUFFER_Save_AsyncR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xc730c ldr r0, [pc, #0xc8]
 *   @0xc7310 add r0, pc, r0
 *   @0xc7314 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xc7318 mov r0, #24
 *   @0xc731c ldr r5, [pc, #0xbc]
 *   @0xc7320 bl 0x27c524 <_Znwj>
 *   @0xc7324 ldr r5, [pc, r5]
 *   @0xc7328 ldr r3, [r5]
 *   @0xc732c mov r4, r0
 *   @0xc7330 mov r0, r9
 *   @0xc7334 str r3, [r4]
 *   @0xc7338 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc733c ldr r1, [pc, #0xa0]
 *   @0xc7340 movw r2, #0x241
 *   @0xc7344 mov r3, #1
 *   @0xc7348 add r1, pc, r1
 *   @0xc734c str r0, [r4, #0x8]
 *   @0xc7350 mov r0, r7
 *   @0xc7354 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc7358 ldr r3, [pc, #0x88]
 *   @0xc735c str r7, [r4, #0x10]
 *   @0xc7360 mov r2, r7
 *   @0xc7364 add r3, pc, r3
 *   @0xc7368 str r8, [r4, #0x14]
 *   @0xc736c ldr r3, [r3, #0x4]
 *   @0xc7370 str r0, [r4, #0xc]
 *   @0xc7374 ldr r3, [r3, r10, lsl #2]
 *   @0xc7378 ldr r1, [r3, #0xc]
 *   @0xc737c add r1, r1, r8
 *   @0xc7380 bl 0xb65bc <memcpy@plt>
 *   @0xc7384 ldr r3, [pc, #0x60]
 *   @0xc7388 str r4, [r5]
 *   @0xc738c ldr r3, [pc, r3]
 *   @0xc7390 ldr r7, [r3]
 *   @0xc7394 cmp r7, #0
 *   @0xc7398 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc739c ldr r2, [pc, #0x4c]
 *   @0xc73a0 mov r1, r4
 *   @0xc73a4 mov r3, r7
 *   @0xc73a8 str r7, [r6, #0xc]
 *   @0xc73ac add r2, pc, r2
 *   @0xc73b0 mov r0, #1
 *   @0xc73b4 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb>
 *   @0xc73b8 vmov s15, r0
 *   @0xc73bc vcvt.f64.s32 d7, s15
 *   @0xc73c0 vmov r0, r1, d7
 *   @0xc73c4 vmov r2, s14
 *   @0xc73c8 mov r3, r1
 *   @0xc73cc stm r6, {r2, r3}
 *   @0xc73d0 str r7, [r5]
 *   @0xc73d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc73d8 eorseq r6, r2, r4, ror #13
 *   @0xc73dc eoreq r10, r6, r12, lsl r2
 *   @0xc73e0 ldrhteq r6, [r2], -r4
 *   @0xc73e4 eoreq r10, r6, r4, lsl r2
 *   @0xc73e8 ldrhteq r2, [r11], -r0
 *   @0xc73ec eorseq r6, r2, r12, lsr #12
 *   @0xc73f0 eoreq r10, r6, r12, ror #3
 *
 * ══ §14/87 YYGML_NewWithIteratorEx(SWithIterator*, YYObjectBase**, YYObjectBase**, int)  0xd7df8  size 352  88 条（0xd7df8..0xd7f58）
 * @func 0xd7df8 0xd7f58  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ClearHandledContainer()×2 / InitialiseHandledContainer() / AddActiveInstances(CObjectGM*) / AddChangingInstances(CObjectGM*) / AddDeactivatingInstances(CObjectGM*) / CountInstances() / YYGML_NewWithIteratorEx(SWithIterator*, YYObjectBase**, YYObjectBase**, int)+0x60 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0xc×2 / 0x1ac×2 / 0x14c×1 / 0x3×1 / 0xb0×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7df8 ldr r12, [pc, #0x14c]
 *   @0xd7dfc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd7e00 ldr r12, [pc, r12]
 *   @0xd7e04 mov r10, r2
 *   @0xd7e08 mov r6, r1
 *   @0xd7e0c ldr r2, [r12]
 *   @0xd7e10 mov r5, r0
 *   @0xd7e14 ldr r1, [r2, #0x4]
 *   @0xd7e18 ldr r2, [r2]
 *   @0xd7e1c and r1, r3, r1
 *   @0xd7e20 ldr r12, [r2, r1, lsl #3]
 *   @0xd7e24 cmp r12, #0
 *   @0xd7e28 beq 0xd7e54 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd7e2c ldr r2, [r12, #0x8]
 *   @0xd7e30 cmp r3, r2
 *   @0xd7e34 bne 0xd7e48 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x50>
 *   @0xd7e38 b 0xd7e60 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x68>
 *   @0xd7e3c ldr r4, [r12, #0x8]
 *   @0xd7e40 cmp r3, r4
 *   @0xd7e44 beq 0xd7e60 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x68>
 *   @0xd7e48 ldr r12, [r12, #0x4]
 *   @0xd7e4c cmp r12, #0
 *   @0xd7e50 bne 0xd7e3c <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x44>
 *   @0xd7e54 mov r8, r12
 *   @0xd7e58 mov r0, r8
 *   @0xd7e5c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd7e60 ldr r8, [r12, #0xc]
 *   @0xd7e64 cmp r8, #0
 *   @0xd7e68 beq 0xd7e58 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x60>
 *   @0xd7e6c bl 0xd3edc <_Z26InitialiseHandledContainerv>
 *   @0xd7e70 bl 0xd3ee0 <_Z21ClearHandledContainerv>
 *   @0xd7e74 mov r0, r8
 *   @0xd7e78 bl 0xd7ca0 <_Z18AddActiveInstancesP9CObjectGM>
 *   @0xd7e7c mov r0, r8
 *   @0xd7e80 bl 0xd7d00 <_Z20AddChangingInstancesP9CObjectGM>
 *   @0xd7e84 mov r0, r8
 *   @0xd7e88 bl 0xd7d7c <_Z24AddDeactivatingInstancesP9CObjectGM>
 *   @0xd7e8c bl 0xd40d8 <_Z14CountInstancesv>
 *   @0xd7e90 subs r8, r0, #0
 *   @0xd7e94 ble 0xd7e58 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x60>
 *   @0xd7e98 ldr r1, [pc, #0xb0]
 *   @0xd7e9c mov r3, #1
 *   @0xd7ea0 lsl r0, r8, #2
 *   @0xd7ea4 movw r2, #0x20db
 *   @0xd7ea8 add r1, pc, r1
 *   @0xd7eac ldr r7, [pc, #0xa0]
 *   @0xd7eb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd7eb4 ldr r3, [r5]
 *   @0xd7eb8 add r7, pc, r7
 *   @0xd7ebc str r0, [r5, #0x8]
 *   @0xd7ec0 mov r9, r0
 *   @0xd7ec4 str r3, [r10]
 *   @0xd7ec8 ldr r3, [r7]
 *   @0xd7ecc cmp r3, r7
 *   @0xd7ed0 beq 0xd7f44 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x14c>
 *   @0xd7ed4 mov r1, #0
 *   @0xd7ed8 mov r2, r0
 *   @0xd7edc mov r10, r7
 *   @0xd7ee0 mov r0, r1
 *   @0xd7ee4 ldr r4, [r7, #0x8]
 *   @0xd7ee8 str r1, [r2], #4
 *   @0xd7eec mov r9, r2
 *   @0xd7ef0 rsb r4, r4, r3
 *   @0xd7ef4 ldr r3, [r3]
 *   @0xd7ef8 add lr, r4, #420
 *   @0xd7efc ldr r12, [r4, #0x1ac]
 *   @0xd7f00 mov r1, r4
 *   @0xd7f04 cmp r12, r7
 *   @0xd7f08 ldreq r11, [r4, #0x1a8]
 *   @0xd7f0c ldreq r12, [r4, #0x1a4]
 *   @0xd7f10 streq r11, [r12, #0x4]
 *   @0xd7f14 ldreq r11, [r4, #0x1a8]
 *   @0xd7f18 streq r12, [r11]
 *   @0xd7f1c cmp r3, r10
 *   @0xd7f20 str lr, [r4, #0x1a4]
 *   @0xd7f24 str lr, [r4, #0x1a8]
 *   @0xd7f28 str r0, [r4, #0x1ac]
 *   @0xd7f2c bne 0xd7ee4 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0xec>
 *   @0xd7f30 bl 0xd3ee0 <_Z21ClearHandledContainerv>
 *   @0xd7f34 str r4, [r6]
 *   @0xd7f38 mov r0, r8
 *   @0xd7f3c str r9, [r5, #0xc]
 *   @0xd7f40 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd7f44 mov r4, #0
 *   @0xd7f48 b 0xd7f30 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x138>
 *   @0xd7f4c eorseq r5, r1, r12, lsr lr
 *   @0xd7f50 .word 0x0025a8d4
 *   @0xd7f54 ldrshteq r2, [r10], -r12
 *
 * ══ §15/87 VM::GetAllInstanceIDs(Buffer_Standard*, bool)  0xd87ac  size 352  88 条（0xd87ac..0xd890c）
 * @func 0xd87ac 0xd890c  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×4 / 0x38×4 / 0x8×4 / 0x1c×2 / 0x10×2 / 0x2c×1 / 0x110×1 / 0x80×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd87ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd87b0 vpush {d8}
 *   @0xd87b4 add r7, r0, #44
 *   @0xd87b8 ldr r3, [r0]
 *   @0xd87bc mov r11, #0
 *   @0xd87c0 mov r4, r1
 *   @0xd87c4 str r11, [r0, #0x2c]
 *   @0xd87c8 str r11, [r0, #0x30]
 *   @0xd87cc mov r2, r7
 *   @0xd87d0 mov r1, #5
 *   @0xd87d4 str r11, [r0, #0x38]
 *   @0xd87d8 ldr r3, [r3, #0x8]
 *   @0xd87dc mov r6, r0
 *   @0xd87e0 ldr r9, [r0, #0x1c]
 *   @0xd87e4 blx r3
 *   @0xd87e8 cmp r4, r11
 *   @0xd87ec beq 0xd88f8 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x14c>
 *   @0xd87f0 ldr r3, [pc, #0x110]
 *   @0xd87f4 ldr r3, [pc, r3]
 *   @0xd87f8 ldr r3, [r3]
 *   @0xd87fc cmp r3, r11
 *   @0xd8800 vmoveq s16, r3
 *   @0xd8804 beq 0xd8894 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0xe8>
 *   @0xd8808 ldr r10, [r3, #0x80]
 *   @0xd880c cmp r10, r11
 *   @0xd8810 beq 0xd8900 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x154>
 *   @0xd8814 mov r8, r11
 *   @0xd8818 ldr r4, [r10, #0x78]
 *   @0xd881c mov r1, #5
 *   @0xd8820 ldr r3, [r6]
 *   @0xd8824 mov r2, r7
 *   @0xd8828 mov r0, r6
 *   @0xd882c str r8, [r6, #0x38]
 *   @0xd8830 vmov s15, r4
 *   @0xd8834 add r11, r11, #1
 *   @0xd8838 vcvt.f64.u32 d7, s15
 *   @0xd883c vmov r4, r5, d7
 *   @0xd8840 vstr s14, [r6, #44]
 *   @0xd8844 str r5, [r6, #0x30]
 *   @0xd8848 ldr r3, [r3, #0x8]
 *   @0xd884c blx r3
 *   @0xd8850 ldr r4, [r10, #0x7c]
 *   @0xd8854 ldr r3, [r6]
 *   @0xd8858 mov r0, r6
 *   @0xd885c str r8, [r6, #0x38]
 *   @0xd8860 mov r1, #5
 *   @0xd8864 vmov s15, r4
 *   @0xd8868 mov r2, r7
 *   @0xd886c vcvt.f64.u32 d7, s15
 *   @0xd8870 vmov r4, r5, d7
 *   @0xd8874 vstr s14, [r6, #44]
 *   @0xd8878 str r5, [r6, #0x30]
 *   @0xd887c ldr r3, [r3, #0x8]
 *   @0xd8880 blx r3
 *   @0xd8884 ldr r10, [r10, #0x178]
 *   @0xd8888 cmp r10, #0
 *   @0xd888c bne 0xd8818 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0x6c>
 *   @0xd8890 vmov s16, r11
 *   @0xd8894 ldr r3, [r6]
 *   @0xd8898 mov r2, r9
 *   @0xd889c mov r1, #0
 *   @0xd88a0 mov r0, r6
 *   @0xd88a4 mov r8, r1
 *   @0xd88a8 ldr r9, [r6, #0x1c]
 *   @0xd88ac ldr r3, [r3, #0x10]
 *   @0xd88b0 blx r3
 *   @0xd88b4 vcvt.f64.u32 d7, s16
 *   @0xd88b8 ldr r3, [r6]
 *   @0xd88bc mov r2, r7
 *   @0xd88c0 mov r1, #5
 *   @0xd88c4 str r8, [r6, #0x38]
 *   @0xd88c8 mov r0, r6
 *   @0xd88cc vmov r4, r5, d7
 *   @0xd88d0 vstr s14, [r6, #44]
 *   @0xd88d4 str r5, [r6, #0x30]
 *   @0xd88d8 ldr r3, [r3, #0x8]
 *   @0xd88dc blx r3
 *   @0xd88e0 ldr r3, [r6]
 *   @0xd88e4 mov r1, r8
 *   @0xd88e8 mov r2, r9
 *   @0xd88ec mov r0, r6
 *   @0xd88f0 ldr r3, [r3, #0x10]
 *   @0xd88f4 blx r3
 *   @0xd88f8 vpop {d8}
 *   @0xd88fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd8900 vmov s16, r10
 *   @0xd8904 b 0xd8894 <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb+0xe8>
 *   @0xd8908 eorseq r5, r1, r4, lsr r1
 *
 * ══ §16/87 VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int)  0xd8f48  size 352  88 条（0xd8f48..0xd90a8）
 * @func 0xd8f48 0xd90a8  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int)+0xf0 / VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int)+0x80 / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x30×3 / 0x38×3 / 0x10×3 / 0x1c×2 / 0x60×2 / 0x2c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8f48 ldr r3, [r0]
 *   @0xd8f4c ldr r12, [r0, #0x1c]
 *   @0xd8f50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd8f54 add r9, r0, #44
 *   @0xd8f58 sub sp, sp, #12
 *   @0xd8f5c mov r4, #0
 *   @0xd8f60 mov r8, r1
 *   @0xd8f64 str r4, [r0, #0x2c]
 *   @0xd8f68 str r4, [r0, #0x30]
 *   @0xd8f6c mov r5, r2
 *   @0xd8f70 ldr r3, [r3, #0x8]
 *   @0xd8f74 mov r2, r9
 *   @0xd8f78 mov r1, #5
 *   @0xd8f7c str r4, [r0, #0x38]
 *   @0xd8f80 str r12, [sp, #0x4]
 *   @0xd8f84 mov r7, r0
 *   @0xd8f88 blx r3
 *   @0xd8f8c cmp r8, r4
 *   @0xd8f90 beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158>
 *   @0xd8f94 ldr r3, [r8, #0x60]
 *   @0xd8f98 cmp r3, r4
 *   @0xd8f9c beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158>
 *   @0xd8fa0 cmp r5, r4
 *   @0xd8fa4 beq 0xd90a0 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x158>
 *   @0xd8fa8 ldr r2, [r3, #0x4]
 *   @0xd8fac mov r11, r4
 *   @0xd8fb0 cmp r2, r4
 *   @0xd8fb4 ble 0xd9038 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0xf0>
 *   @0xd8fb8 mov r10, r4
 *   @0xd8fbc ldr r6, [r3, #0x10]
 *   @0xd8fc0 mov r3, #0
 *   @0xd8fc4 b 0xd8fcc <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x84>
 *   @0xd8fc8 add r6, r6, #12
 *   @0xd8fcc ldr r2, [r6, #0x8]
 *   @0xd8fd0 cmp r2, #0
 *   @0xd8fd4 ble 0xd8fc8 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x80>
 *   @0xd8fd8 cmp r3, r11
 *   @0xd8fdc add r3, r3, #1
 *   @0xd8fe0 bne 0xd8fc8 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x80>
 *   @0xd8fe4 ldr r4, [r6]
 *   @0xd8fe8 mov r2, r9
 *   @0xd8fec ldr r3, [r7]
 *   @0xd8ff0 mov r1, #6
 *   @0xd8ff4 mov r0, r7
 *   @0xd8ff8 str r10, [r7, #0x38]
 *   @0xd8ffc vmov s15, r4
 *   @0xd9000 add r11, r11, #1
 *   @0xd9004 vcvt.f64.s32 d7, s15
 *   @0xd9008 vmov r4, r5, d7
 *   @0xd900c vstr s14, [r7, #44]
 *   @0xd9010 str r5, [r7, #0x30]
 *   @0xd9014 ldr r3, [r3, #0x8]
 *   @0xd9018 blx r3
 *   @0xd901c ldr r0, [r6, #0x4]
 *   @0xd9020 mov r1, r7
 *   @0xd9024 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd9028 ldr r3, [r8, #0x60]
 *   @0xd902c ldr r2, [r3, #0x4]
 *   @0xd9030 cmp r2, r11
 *   @0xd9034 bgt 0xd8fbc <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi+0x74>
 *   @0xd9038 ldr r3, [r7]
 *   @0xd903c mov r1, #0
 *   @0xd9040 ldr r2, [sp, #0x4]
 *   @0xd9044 mov r0, r7
 *   @0xd9048 mov r6, r1
 *   @0xd904c ldr r8, [r7, #0x1c]
 *   @0xd9050 ldr r3, [r3, #0x10]
 *   @0xd9054 blx r3
 *   @0xd9058 vmov s15, r11
 *   @0xd905c ldr r3, [r7]
 *   @0xd9060 mov r2, r9
 *   @0xd9064 vcvt.f64.s32 d7, s15
 *   @0xd9068 mov r1, #5
 *   @0xd906c str r6, [r7, #0x38]
 *   @0xd9070 mov r0, r7
 *   @0xd9074 vmov r4, r5, d7
 *   @0xd9078 vstr s14, [r7, #44]
 *   @0xd907c str r5, [r7, #0x30]
 *   @0xd9080 ldr r3, [r3, #0x8]
 *   @0xd9084 blx r3
 *   @0xd9088 ldr r3, [r7]
 *   @0xd908c mov r1, r6
 *   @0xd9090 mov r2, r8
 *   @0xd9094 mov r0, r7
 *   @0xd9098 ldr r3, [r3, #0x10]
 *   @0xd909c blx r3
 *   @0xd90a0 add sp, sp, #12
 *   @0xd90a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §17/87 Font_AddSpriteExt(int, char const*, bool, int)  0xfa7a8  size 352  88 条（0xfa7a8..0xfa908）
 * @func 0xfa7a8 0xfa908  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfa7c4→0x483688, 0xfa7c8→0x483680, 0xfa7fc→0x483684, 0xfa8b8→0x483684
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int) / CFontGM::CFontGM(int, char const*, bool, int) / 0xb65c8 / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x128×2 / 0xc×2 / 0x114×2 / 0x2×2 / 0x134×1 / 0x130×1 / 0xf8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa7a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfa7ac mov r10, r0
 *   @0xfa7b0 ldr r5, [pc, #0x134]
 *   @0xfa7b4 mov r9, r1
 *   @0xfa7b8 ldr r0, [pc, #0x130]
 *   @0xfa7bc mov r8, r2
 *   @0xfa7c0 add r5, pc, r5
 *   @0xfa7c4 ldr r1, [pc, #0x128]
 *   @0xfa7c8 ldr r2, [pc, #0x128]
 *   @0xfa7cc mov r11, r3
 *   @0xfa7d0 ldr r0, [r5, r0]
 *   @0xfa7d4 sub sp, sp, #284
 *   @0xfa7d8 ldr r3, [r0]
 *   @0xfa7dc str r0, [sp, #0xc]
 *   @0xfa7e0 str r3, [sp, #0x114]
 *   @0xfa7e4 ldr r6, [r5, r1]
 *   @0xfa7e8 ldr r4, [r5, r2]
 *   @0xfa7ec ldr r1, [r6]
 *   @0xfa7f0 ldr r3, [r4]
 *   @0xfa7f4 cmp r1, r3
 *   @0xfa7f8 beq 0xfa894 <_Z17Font_AddSpriteExtiPKcbi+0xec>
 *   @0xfa7fc ldr r2, [pc, #0xf8]
 *   @0xfa800 ldr r5, [r5, r2]
 *   @0xfa804 mov r0, #144
 *   @0xfa808 add r3, r3, #1
 *   @0xfa80c str r3, [r4]
 *   @0xfa810 bl 0x27c524 <_Znwj>
 *   @0xfa814 mov r1, r10
 *   @0xfa818 mov r2, r9
 *   @0xfa81c mov r3, r8
 *   @0xfa820 str r11, [sp]
 *   @0xfa824 mov r7, r0
 *   @0xfa828 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi>
 *   @0xfa82c ldr r3, [r4]
 *   @0xfa830 mov r1, #256
 *   @0xfa834 ldr r2, [r6, #0x4]
 *   @0xfa838 add r6, sp, #20
 *   @0xfa83c sub lr, r3, #-1073741823
 *   @0xfa840 sub r3, r3, #1
 *   @0xfa844 mov r0, r6
 *   @0xfa848 str r7, [r2, lr, lsl #2]
 *   @0xfa84c ldr r2, [pc, #0xac]
 *   @0xfa850 add r2, pc, r2
 *   @0xfa854 bl 0xb65c8 <snprintf@plt>
 *   @0xfa858 ldr r3, [r4]
 *   @0xfa85c mov r0, r6
 *   @0xfa860 ldr r5, [r5]
 *   @0xfa864 sub r6, r3, #-1073741823
 *   @0xfa868 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xfa86c ldr r1, [sp, #0xc]
 *   @0xfa870 ldr r3, [r4]
 *   @0xfa874 ldr r2, [sp, #0x114]
 *   @0xfa878 str r0, [r5, r6, lsl #2]
 *   @0xfa87c sub r0, r3, #1
 *   @0xfa880 ldr r3, [r1]
 *   @0xfa884 cmp r2, r3
 *   @0xfa888 bne 0xfa8e8 <_Z17Font_AddSpriteExtiPKcbi+0x140>
 *   @0xfa88c add sp, sp, #284
 *   @0xfa890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfa894 ldr r12, [pc, #0x68]
 *   @0xfa898 add r1, r1, #5
 *   @0xfa89c add r0, r6, #4
 *   @0xfa8a0 movw r3, #0x14f
 *   @0xfa8a4 add r12, pc, r12
 *   @0xfa8a8 lsl r1, r1, #2
 *   @0xfa8ac mov r2, r12
 *   @0xfa8b0 mov r7, r12
 *   @0xfa8b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa8b8 ldr r0, [pc, #0x3c]
 *   @0xfa8bc ldr r1, [r4]
 *   @0xfa8c0 movw r3, #0x151
 *   @0xfa8c4 mov r2, r7
 *   @0xfa8c8 add r1, r1, #5
 *   @0xfa8cc str r1, [r6]
 *   @0xfa8d0 ldr r5, [r5, r0]
 *   @0xfa8d4 lsl r1, r1, #2
 *   @0xfa8d8 mov r0, r5
 *   @0xfa8dc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa8e0 ldr r3, [r4]
 *   @0xfa8e4 b 0xfa804 <_Z17Font_AddSpriteExtiPKcbi+0x5c>
 *   @0xfa8e8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfa8ec mlaeq pc, r0, r4, r7
 *   @0xfa8f0 .word 0xffffbd00
 *   @0xfa8f4 .word 0xffffc20c
 *   @0xfa8f8 .word 0xffffc210
 *   @0xfa8fc .word 0xffffc214
 *   @0xfa900 eoreq sp, r3, r0, asr #6
 *   @0xfa904 .word 0x0023d2b8
 *
 * ══ §18/87 F_Circle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x10c678  size 352  88 条（0x10c678..0x10c7d8）
 * @func 0x10c678 0x10c7d8  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / F_Circle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x14c
 * 字段偏移 top8: 0x4×2 / 0x28×1
 * VFP 指令 47 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c678 push {r3, r4, r5, lr}
 *   @0x10c67c vpush {d8, d9, d10}
 *   @0x10c680 mov r1, #0
 *   @0x10c684 ldr r4, [sp, #0x28]
 *   @0x10c688 mov r5, r0
 *   @0x10c68c mov r0, r4
 *   @0x10c690 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c694 mov r1, #1
 *   @0x10c698 vmov s18, r0
 *   @0x10c69c mov r0, r4
 *   @0x10c6a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6a4 mov r1, #2
 *   @0x10c6a8 vmov s20, r0
 *   @0x10c6ac mov r0, r4
 *   @0x10c6b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6b4 mov r1, #3
 *   @0x10c6b8 vmov s19, r0
 *   @0x10c6bc mov r0, r4
 *   @0x10c6c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6c4 mov r1, #4
 *   @0x10c6c8 vmov s21, r0
 *   @0x10c6cc mov r0, r4
 *   @0x10c6d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6d4 mov r1, #5
 *   @0x10c6d8 vmov s16, r0
 *   @0x10c6dc mov r0, r4
 *   @0x10c6e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6e4 mov r1, #6
 *   @0x10c6e8 vmov s17, r0
 *   @0x10c6ec mov r0, r4
 *   @0x10c6f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10c6f4 vcmpe.f32 s18, s16
 *   @0x10c6f8 vmrs APSR_nzcv, fpscr
 *   @0x10c6fc vmovle.f32 s15, s16
 *   @0x10c700 vmovgt.f32 s15, s18
 *   @0x10c704 vcmp.f32 s15, s19
 *   @0x10c708 vmrs APSR_nzcv, fpscr
 *   @0x10c70c vcmpe.f32 s20, s17
 *   @0x10c710 vmovgt.f32 s15, s19
 *   @0x10c714 vmrs APSR_nzcv, fpscr
 *   @0x10c718 vmovle.f32 s14, s17
 *   @0x10c71c vmovgt.f32 s14, s20
 *   @0x10c720 vcmp.f32 s14, s21
 *   @0x10c724 vmrs APSR_nzcv, fpscr
 *   @0x10c728 vmovgt.f32 s14, s21
 *   @0x10c72c vsub.f32 s14, s14, s17
 *   @0x10c730 vmov s13, r0
 *   @0x10c734 vmul.f32 s14, s14, s14
 *   @0x10c738 vsub.f32 s15, s15, s16
 *   @0x10c73c vmla.f32 s14, s15, s15
 *   @0x10c740 vmul.f32 s15, s13, s13
 *   @0x10c744 vcmpe.f32 s15, s14
 *   @0x10c748 vmrs APSR_nzcv, fpscr
 *   @0x10c74c blt 0x10c7c4 <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x10c750 vsub.f32 s18, s16, s18
 *   @0x10c754 mov r3, #0
 *   @0x10c758 mov r2, #1073741824
 *   @0x10c75c str r3, [r5]
 *   @0x10c760 str r2, [r5, #0x4]
 *   @0x10c764 vabs.f32 s18, s18
 *   @0x10c768 vcmpe.f32 s13, s18
 *   @0x10c76c vmrs APSR_nzcv, fpscr
 *   @0x10c770 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10c774 vsub.f32 s16, s16, s19
 *   @0x10c778 vabs.f32 s16, s16
 *   @0x10c77c vcmpe.f32 s13, s16
 *   @0x10c780 vmrs APSR_nzcv, fpscr
 *   @0x10c784 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10c788 vsub.f32 s20, s17, s20
 *   @0x10c78c vabs.f32 s20, s20
 *   @0x10c790 vcmpe.f32 s13, s20
 *   @0x10c794 vmrs APSR_nzcv, fpscr
 *   @0x10c798 bpl 0x10c7bc <_Z21F_Circle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10c79c vsub.f32 s17, s17, s21
 *   @0x10c7a0 vabs.f32 s17, s17
 *   @0x10c7a4 vcmpe.f32 s13, s17
 *   @0x10c7a8 vmrs APSR_nzcv, fpscr
 *   @0x10c7ac strmi r3, [r5]
 *   @0x10c7b0 movmi r3, #0
 *   @0x10c7b4 movtmi r3, #0x3ff0
 *   @0x10c7b8 strmi r3, [r5, #0x4]
 *   @0x10c7bc vpop {d8, d9, d10}
 *   @0x10c7c0 pop {r3, r4, r5, pc}
 *   @0x10c7c4 mov r3, #0
 *   @0x10c7c8 str r3, [r5]
 *   @0x10c7cc str r3, [r5, #0x4]
 *   @0x10c7d0 vpop {d8, d9, d10}
 *   @0x10c7d4 pop {r3, r4, r5, pc}
 *
 * ══ §19/87 F_VariableInstanceGetNames(RValue&, CInstance*, CInstance*, int, RValue*)  0x119884  size 352  88 条（0x119884..0x1199e4）
 * @func 0x119884 0x1199e4  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ARRAY_RefAlloc(void*)×2 / YYGetInt32(RValue const*, int) / F_VariableInstanceGetNames(RValue&, CInstance*, CInstance*, int, RValue*)+0x134 / F_VariableInstanceGetNames(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / Code_Variable_Find_Name(char const*, int, int) / YYCreateString(RValue*, char const*) / SET_RValue_Array(RValue*, RValue*, int) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×5 / 0x4×2 / 0x8×2 / 0x60×2 / 0x10×2 / 0x30×1 / 0x134×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119884 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x119888 sub sp, sp, #20
 *   @0x11988c mov r7, r0
 *   @0x119890 mov r1, #0
 *   @0x119894 ldr r0, [sp, #0x30]
 *   @0x119898 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11989c cmp r0, #0
 *   @0x1198a0 blt 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1198a4 ldr r3, [pc, #0x134]
 *   @0x1198a8 ldr r3, [pc, r3]
 *   @0x1198ac ldr r2, [r3, #0x4]
 *   @0x1198b0 ldr r3, [r3]
 *   @0x1198b4 and r2, r0, r2
 *   @0x1198b8 ldr r3, [r3, r2, lsl #3]
 *   @0x1198bc cmp r3, #0
 *   @0x1198c0 bne 0x1198d4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1198c4 b 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1198c8 ldr r3, [r3, #0x4]
 *   @0x1198cc cmp r3, #0
 *   @0x1198d0 beq 0x1199b8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1198d4 ldr r2, [r3, #0x8]
 *   @0x1198d8 cmp r0, r2
 *   @0x1198dc bne 0x1198c8 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1198e0 ldr r8, [r3, #0xc]
 *   @0x1198e4 mov r0, r7
 *   @0x1198e8 mov r3, #2
 *   @0x1198ec str r3, [r7, #0xc]
 *   @0x1198f0 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x1198f4 cmp r8, #0
 *   @0x1198f8 str r0, [r7]
 *   @0x1198fc beq 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x119900 ldr r3, [r8, #0x60]
 *   @0x119904 cmp r3, #0
 *   @0x119908 beq 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x11990c ldr r1, [r3]
 *   @0x119910 mov r4, #0
 *   @0x119914 ldr r0, [r3, #0x10]
 *   @0x119918 mov r5, r4
 *   @0x11991c mvn r9, #-16777216
 *   @0x119920 add r3, r4, r4, lsl #1
 *   @0x119924 add r3, r0, r3, lsl #2
 *   @0x119928 add r4, r4, #1
 *   @0x11992c mov r12, r3
 *   @0x119930 cmp r4, r1
 *   @0x119934 add r3, r3, #12
 *   @0x119938 bgt 0x1199cc <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x11993c ldr r2, [r12, #0x8]
 *   @0x119940 cmp r2, #0
 *   @0x119944 ble 0x119928 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x119948 ldm r12, {r2, r3}
 *   @0x11994c ldr r3, [r3, #0xc]
 *   @0x119950 bic r3, r3, #-16777216
 *   @0x119954 cmp r3, r9
 *   @0x119958 beq 0x119920 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11995c add r2, r2, #99328
 *   @0x119960 mvn r1, #0
 *   @0x119964 add r2, r2, #672
 *   @0x119968 mov r0, #0
 *   @0x11996c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x119970 mov r1, r0
 *   @0x119974 mov r0, sp
 *   @0x119978 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x11997c mov r0, r7
 *   @0x119980 mov r1, sp
 *   @0x119984 mov r2, r5
 *   @0x119988 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x11998c ldr r3, [sp, #0xc]
 *   @0x119990 sub r3, r3, #1
 *   @0x119994 bic r3, r3, #-16777216
 *   @0x119998 bic r3, r3, #3
 *   @0x11999c cmp r3, #0
 *   @0x1199a0 beq 0x1199d4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x1199a4 ldr r3, [r8, #0x60]
 *   @0x1199a8 add r5, r5, #1
 *   @0x1199ac ldr r1, [r3]
 *   @0x1199b0 ldr r0, [r3, #0x10]
 *   @0x1199b4 b 0x119920 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1199b8 mov r3, #2
 *   @0x1199bc mov r0, r7
 *   @0x1199c0 str r3, [r7, #0xc]
 *   @0x1199c4 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x1199c8 str r0, [r7]
 *   @0x1199cc add sp, sp, #20
 *   @0x1199d0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1199d4 mov r0, sp
 *   @0x1199d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1199dc b 0x1199a4 <_Z26F_VariableInstanceGetNamesR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x1199e0 mlaeq sp, r12, r3, r4
 *
 * ══ §20/87 F_PhysicsBeginParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d83c  size 352  88 条（0x14d83c..0x14d99c）
 * @func 0x14d83c 0x14d99c  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetUint32(RValue const*, int)×2 / YYGetInt32(RValue const*, int)×2 / CPhysicsWorld::BeginParticleGroup(unsigned int, unsigned int, float, float, float, float, float, float, unsigned int, float, float, int)
 * 字段偏移 top8: 0x2c×2 / 0x30×2 / 0x34×2 / 0x38×2 / 0x3c×2 / 0x14×2 / 0x150×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d83c ldr r3, [pc, #0x150]
 *   @0x14d840 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d844 ldr r3, [pc, r3]
 *   @0x14d848 sub sp, sp, #68
 *   @0x14d84c ldr r3, [r3]
 *   @0x14d850 ldr r4, [sp, #0x68]
 *   @0x14d854 cmp r3, #0
 *   @0x14d858 beq 0x14d97c <_Z27F_PhysicsBeginParticleGroupR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x14d85c ldr r5, [r3, #0xb4]
 *   @0x14d860 cmp r5, #0
 *   @0x14d864 beq 0x14d97c <_Z27F_PhysicsBeginParticleGroupR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x14d868 mov r0, r4
 *   @0x14d86c mov r1, #0
 *   @0x14d870 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d874 mov r1, #1
 *   @0x14d878 mov r6, r0
 *   @0x14d87c mov r0, r4
 *   @0x14d880 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d884 mov r1, #2
 *   @0x14d888 mov r2, r0
 *   @0x14d88c mov r0, r4
 *   @0x14d890 str r2, [sp, #0x2c]
 *   @0x14d894 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d898 mov r1, #3
 *   @0x14d89c mov r3, r0
 *   @0x14d8a0 mov r0, r4
 *   @0x14d8a4 str r3, [sp, #0x30]
 *   @0x14d8a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d8ac mov r1, #4
 *   @0x14d8b0 mov r12, r0
 *   @0x14d8b4 mov r0, r4
 *   @0x14d8b8 str r12, [sp, #0x34]
 *   @0x14d8bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d8c0 mov r1, #5
 *   @0x14d8c4 str r0, [sp, #0x38]
 *   @0x14d8c8 mov r0, r4
 *   @0x14d8cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d8d0 mov r1, #6
 *   @0x14d8d4 str r0, [sp, #0x3c]
 *   @0x14d8d8 mov r0, r4
 *   @0x14d8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d8e0 mov r1, #7
 *   @0x14d8e4 mov r11, r0
 *   @0x14d8e8 mov r0, r4
 *   @0x14d8ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d8f0 mov r1, #8
 *   @0x14d8f4 mov r10, r0
 *   @0x14d8f8 mov r0, r4
 *   @0x14d8fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d900 mov r1, #9
 *   @0x14d904 mov r9, r0
 *   @0x14d908 mov r0, r4
 *   @0x14d90c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d910 mov r1, #10
 *   @0x14d914 mov r8, r0
 *   @0x14d918 mov r0, r4
 *   @0x14d91c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d920 mov r1, #11
 *   @0x14d924 mov r7, r0
 *   @0x14d928 mov r0, r4
 *   @0x14d92c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d930 ldr r1, [sp, #0x38]
 *   @0x14d934 ldr r12, [sp, #0x34]
 *   @0x14d938 str r11, [sp, #0xc]
 *   @0x14d93c str r1, [sp, #0x4]
 *   @0x14d940 ldr r1, [sp, #0x3c]
 *   @0x14d944 str r12, [sp]
 *   @0x14d948 str r10, [sp, #0x10]
 *   @0x14d94c str r1, [sp, #0x8]
 *   @0x14d950 mov r1, r6
 *   @0x14d954 str r9, [sp, #0x14]
 *   @0x14d958 str r8, [sp, #0x18]
 *   @0x14d95c str r7, [sp, #0x1c]
 *   @0x14d960 ldr r2, [sp, #0x2c]
 *   @0x14d964 ldr r3, [sp, #0x30]
 *   @0x14d968 str r0, [sp, #0x20]
 *   @0x14d96c mov r0, r5
 *   @0x14d970 bl 0x2399a8 <_ZN13CPhysicsWorld18BeginParticleGroupEjjffffffjffi>
 *   @0x14d974 add sp, sp, #68
 *   @0x14d978 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14d97c ldr r0, [pc, #0x14]
 *   @0x14d980 mov r1, #0
 *   @0x14d984 add r0, pc, r0
 *   @0x14d988 add sp, sp, #68
 *   @0x14d98c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d990 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d994 eoreq r0, r10, r4, ror #1
 *   @0x14d998 mulseq pc, r4, r8
 *
 * ══ §21/87 GR_3D_Projection_Ortho(float, float, float, float, float)  0x1633e8  size 352  88 条（0x1633e8..0x163548）
 * @func 0x1633e8 0x16355c  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetMatrix(eMatrix, float*)×2 / DirtyRoomExtents()×2 / 0xb6580 / 0xb658c / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float)
 * 字段偏移 top8: 0x2c×2 / 0x84×2 / 0x20×1 / 0x14×1 / 0xfc×1 / 0x24×1 / 0xa4×1 / 0x28×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1633e8 vmov.f32 s15, #5.000000e-01
 *   @0x1633ec push {r4, r5, r6, r7, r8, lr}
 *   @0x1633f0 vpush {d8, d9, d10}
 *   @0x1633f4 vmov s14, r0
 *   @0x1633f8 vldr s19, [pc, #296]
 *   @0x1633fc vmov s17, r2
 *   @0x163400 sub sp, sp, #176
 *   @0x163404 vldr s20, [sp, #224]
 *   @0x163408 vldr s18, [pc, #284]
 *   @0x16340c vmov s16, r3
 *   @0x163410 mov r6, #0
 *   @0x163414 vmov s13, r1
 *   @0x163418 str r6, [sp, #0x20]
 *   @0x16341c mov r3, #0
 *   @0x163420 movt r3, #0xc67a
 *   @0x163424 str r3, [sp, #0x14]
 *   @0x163428 mov r5, #1
 *   @0x16342c ldr r4, [pc, #0xfc]
 *   @0x163430 vmla.f32 s14, s17, s15
 *   @0x163434 add r4, pc, r4
 *   @0x163438 vstr s14, [sp, #12]
 *   @0x16343c vstr s14, [sp, #24]
 *   @0x163440 vnmul.f32 s14, s20, s19
 *   @0x163444 vdiv.f32 s14, s14, s18
 *   @0x163448 vmla.f32 s13, s16, s15
 *   @0x16344c vmov r0, s14
 *   @0x163450 vmul.f32 s19, s20, s19
 *   @0x163454 vstr s13, [sp, #16]
 *   @0x163458 vstr s13, [sp, #28]
 *   @0x16345c bl 0xb6580 <sinf@plt>
 *   @0x163460 vdiv.f32 s19, s19, s18
 *   @0x163464 mov r7, r0
 *   @0x163468 vmov r0, s19
 *   @0x16346c bl 0xb658c <cosf@plt>
 *   @0x163470 str r6, [sp, #0x2c]
 *   @0x163474 add r6, sp, #48
 *   @0x163478 add r2, sp, #24
 *   @0x16347c add r3, sp, #36
 *   @0x163480 add r1, sp, #12
 *   @0x163484 str r7, [sp, #0x24]
 *   @0x163488 ldr r7, [pc, #0xa4]
 *   @0x16348c str r0, [sp, #0x28]
 *   @0x163490 mov r0, r6
 *   @0x163494 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x163498 mov r1, r6
 *   @0x16349c mov r0, #0
 *   @0x1634a0 add r6, sp, #112
 *   @0x1634a4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1634a8 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1634ac ldr r1, [pc, #0x84]
 *   @0x1634b0 ldr lr, [pc, #0x84]
 *   @0x1634b4 mov r3, #1065353216
 *   @0x1634b8 ldr r12, [pc, #0x80]
 *   @0x1634bc mov r2, #0
 *   @0x1634c0 ldr r8, [r4, r1]
 *   @0x1634c4 movt r2, #0x46fa
 *   @0x1634c8 mov r0, r6
 *   @0x1634cc vmov r1, s17
 *   @0x1634d0 strb r5, [r8]
 *   @0x1634d4 ldr r7, [r4, r7]
 *   @0x1634d8 str r3, [r7]
 *   @0x1634dc ldr lr, [r4, lr]
 *   @0x1634e0 str r2, [lr]
 *   @0x1634e4 ldr r12, [r4, r12]
 *   @0x1634e8 str r2, [sp]
 *   @0x1634ec vldr s15, [r12]
 *   @0x1634f0 vcvt.f32.s32 s15, s15
 *   @0x1634f4 vnmul.f32 s15, s16, s15
 *   @0x1634f8 vmov r2, s15
 *   @0x1634fc bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x163500 mov r0, r5
 *   @0x163504 mov r1, r6
 *   @0x163508 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x16350c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163510 ldr r3, [pc, #0x2c]
 *   @0x163514 ldr r3, [r4, r3]
 *   @0x163518 strb r5, [r3]
 *   @0x16351c add sp, sp, #176
 *   @0x163520 vpop {d8, d9, d10}
 *   @0x163524 pop {r4, r5, r6, r7, r8, pc}
 *   @0x163528 ldrdmi r0, r1, [r9], #-251
 *   @0x16352c teqmi r4, #0
 *   @0x163530 eoreq lr, r8, r12, lsl r8
 *   @0x163534 .word 0xffffe484
 *   @0x163538 .word 0xffffe480
 *   @0x16353c .word 0xffffe488
 *   @0x163540 .word 0xffffe48c
 *   @0x163544 .word 0xffffe490
 *
 * ══ §22/87 CBitmap32::CBitmap32(IBitmap*, bool, bool)  0x166e70  size 352  88 条（0x166e70..0x166fd0）
 * @func 0x166e70 0x166fd0  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×3 / CBitmap32::CBitmap32(int, IBitmap*, bool, bool)×3 / CBitmap32::Assign(CBitmap32*)×3 / IBitmap::Create()
 * 字段偏移 top8: 0x4×3 / 0x20×2 / 0x154×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166e70 ldr r12, [pc, #0x154]
 *   @0x166e74 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x166e78 subs r6, r1, #0
 *   @0x166e7c ldr r12, [pc, r12]
 *   @0x166e80 mov r5, #0
 *   @0x166e84 add r12, r12, #8
 *   @0x166e88 sub sp, sp, #12
 *   @0x166e8c mov r4, r0
 *   @0x166e90 mov r8, r2
 *   @0x166e94 mov r9, r3
 *   @0x166e98 str r12, [r0]
 *   @0x166e9c strb r5, [r0, #0x4]
 *   @0x166ea0 str r5, [r0, #0x8]
 *   @0x166ea4 str r5, [r0, #0xc]
 *   @0x166ea8 str r5, [r0, #0x10]
 *   @0x166eac str r5, [r0, #0x14]
 *   @0x166eb0 beq 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0>
 *   @0x166eb4 ldr r3, [r6]
 *   @0x166eb8 mov r0, r6
 *   @0x166ebc ldr r3, [r3, #0x20]
 *   @0x166ec0 blx r3
 *   @0x166ec4 cmp r0, #6
 *   @0x166ec8 beq 0x166f5c <_ZN9CBitmap32C2EP7IBitmapbb+0xec>
 *   @0x166ecc ldr r3, [r6]
 *   @0x166ed0 mov r0, r6
 *   @0x166ed4 ldr r3, [r3, #0x20]
 *   @0x166ed8 blx r3
 *   @0x166edc cmp r0, #7
 *   @0x166ee0 beq 0x166f94 <_ZN9CBitmap32C2EP7IBitmapbb+0x124>
 *   @0x166ee4 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x166ee8 mov r1, r6
 *   @0x166eec ldr r3, [r0]
 *   @0x166ef0 mov r7, r0
 *   @0x166ef4 ldr r3, [r3, #0x2c]
 *   @0x166ef8 blx r3
 *   @0x166efc mov r0, #24
 *   @0x166f00 bl 0x27c524 <_Znwj>
 *   @0x166f04 mov r1, r5
 *   @0x166f08 mov r3, r8
 *   @0x166f0c mov r2, r7
 *   @0x166f10 str r9, [sp]
 *   @0x166f14 mov r6, r0
 *   @0x166f18 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb>
 *   @0x166f1c mov r0, r4
 *   @0x166f20 mov r1, r6
 *   @0x166f24 bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x166f28 cmp r6, #0
 *   @0x166f2c beq 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0>
 *   @0x166f30 ldr r3, [r6]
 *   @0x166f34 mov r0, r6
 *   @0x166f38 ldr r3, [r3, #0x4]
 *   @0x166f3c blx r3
 *   @0x166f40 ldr r3, [r7]
 *   @0x166f44 mov r0, r7
 *   @0x166f48 ldr r3, [r3, #0x4]
 *   @0x166f4c blx r3
 *   @0x166f50 mov r0, r4
 *   @0x166f54 add sp, sp, #12
 *   @0x166f58 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x166f5c mov r0, #24
 *   @0x166f60 bl 0x27c524 <_Znwj>
 *   @0x166f64 mov r1, r5
 *   @0x166f68 mov r2, r6
 *   @0x166f6c mov r3, r8
 *   @0x166f70 str r9, [sp]
 *   @0x166f74 mov r7, r0
 *   @0x166f78 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb>
 *   @0x166f7c mov r0, r4
 *   @0x166f80 mov r1, r7
 *   @0x166f84 bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x166f88 cmp r7, r5
 *   @0x166f8c bne 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0>
 *   @0x166f90 b 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0>
 *   @0x166f94 mov r0, #24
 *   @0x166f98 bl 0x27c524 <_Znwj>
 *   @0x166f9c mov r1, r5
 *   @0x166fa0 mov r2, r6
 *   @0x166fa4 mov r3, r8
 *   @0x166fa8 str r9, [sp]
 *   @0x166fac mov r7, r0
 *   @0x166fb0 bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb>
 *   @0x166fb4 mov r0, r4
 *   @0x166fb8 mov r1, r7
 *   @0x166fbc bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x166fc0 cmp r7, #0
 *   @0x166fc4 bne 0x166f40 <_ZN9CBitmap32C2EP7IBitmapbb+0xd0>
 *   @0x166fc8 b 0x166f50 <_ZN9CBitmap32C2EP7IBitmapbb+0xe0>
 *   @0x166fcc eoreq r9, r8, r12, ror r2
 *
 * ══ §23/87 Part_CreateTextures()  0x1a5a3c  size 352  88 条（0x1a5a3c..0x1a5b9c）
 * @func 0x1a5a3c 0x1a5b9c  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RomDisk::LoadTexture(int)×14 / 0xb65b0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xc×2 / 0x18×2 / 0x144×1 / 0x10×1 / 0x14×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5a3c push {r4, lr}
 *   @0x1a5a40 mov r1, #0
 *   @0x1a5a44 ldr r4, [pc, #0x144]
 *   @0x1a5a48 sub sp, sp, #40
 *   @0x1a5a4c mov r2, #64
 *   @0x1a5a50 ldr r4, [pc, r4]
 *   @0x1a5a54 mov r0, r4
 *   @0x1a5a58 bl 0xb65b0 <memset@plt>
 *   @0x1a5a5c mov r0, #1
 *   @0x1a5a60 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5a64 str r0, [r4]
 *   @0x1a5a68 mov r0, #2
 *   @0x1a5a6c bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5a70 str r0, [r4, #0x4]
 *   @0x1a5a74 mov r0, #3
 *   @0x1a5a78 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5a7c str r0, [r4, #0x8]
 *   @0x1a5a80 mov r0, #4
 *   @0x1a5a84 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5a88 str r0, [r4, #0xc]
 *   @0x1a5a8c mov r0, #5
 *   @0x1a5a90 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5a94 str r0, [r4, #0x10]
 *   @0x1a5a98 mov r0, #6
 *   @0x1a5a9c bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5aa0 str r0, [r4, #0x14]
 *   @0x1a5aa4 mov r0, #7
 *   @0x1a5aa8 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5aac str r0, [r4, #0x18]
 *   @0x1a5ab0 mov r0, #8
 *   @0x1a5ab4 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5ab8 str r0, [r4, #0x1c]
 *   @0x1a5abc mov r0, #9
 *   @0x1a5ac0 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5ac4 str r0, [r4, #0x20]
 *   @0x1a5ac8 mov r0, #10
 *   @0x1a5acc bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5ad0 str r0, [r4, #0x24]
 *   @0x1a5ad4 mov r0, #11
 *   @0x1a5ad8 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5adc str r0, [r4, #0x28]
 *   @0x1a5ae0 mov r0, #12
 *   @0x1a5ae4 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5ae8 str r0, [r4, #0x2c]
 *   @0x1a5aec mov r0, #13
 *   @0x1a5af0 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5af4 str r0, [r4, #0x30]
 *   @0x1a5af8 mov r0, #14
 *   @0x1a5afc bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x1a5b00 ldr r1, [pc, #0x8c]
 *   @0x1a5b04 movw r2, #0xa1f
 *   @0x1a5b08 mov r3, #1
 *   @0x1a5b0c add r1, pc, r1
 *   @0x1a5b10 str r0, [r4, #0x34]
 *   @0x1a5b14 movw r0, #0x4010
 *   @0x1a5b18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a5b1c mov r3, #4
 *   @0x1a5b20 mvn r12, #0
 *   @0x1a5b24 movw r1, #0x1004
 *   @0x1a5b28 add r2, r0, #12
 *   @0x1a5b2c mov lr, r0
 *   @0x1a5b30 add r3, r3, #1
 *   @0x1a5b34 str r12, [r2, #0x4]!
 *   @0x1a5b38 cmp r3, r1
 *   @0x1a5b3c bne 0x1a5b30 <_Z19Part_CreateTexturesv+0xf4>
 *   @0x1a5b40 mov r3, #0
 *   @0x1a5b44 mov r12, #1
 *   @0x1a5b48 str r3, [lr, #0xc]
 *   @0x1a5b4c mov r0, lr
 *   @0x1a5b50 movw r1, #0x4010
 *   @0x1a5b54 movw r2, #0x4152
 *   @0x1a5b58 movt r2, #0x2057
 *   @0x1a5b5c str r2, [lr]
 *   @0x1a5b60 mov r2, #64
 *   @0x1a5b64 str r2, [lr, #0x4]
 *   @0x1a5b68 str r2, [lr, #0x8]
 *   @0x1a5b6c add r2, sp, #12
 *   @0x1a5b70 str r12, [sp]
 *   @0x1a5b74 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb>
 *   @0x1a5b78 ldr r3, [pc, #0x18]
 *   @0x1a5b7c ldr r3, [pc, r3]
 *   @0x1a5b80 str r0, [r4, #0x38]
 *   @0x1a5b84 str r0, [r3]
 *   @0x1a5b88 add sp, sp, #40
 *   @0x1a5b8c pop {r4, pc}
 *   @0x1a5b90 eoreq r10, r4, r0, ror sp
 *   @0x1a5b94 andseq r7, r10, r4, ror r4
 *   @0x1a5b98 eoreq r10, r4, r8, asr #24
 *
 * ══ §24/87 F_LayerActivate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb998  size 352  88 条（0x1bb998..0x1bbaf8）
 * @func 0x1bb998 0x1bbb0c  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CInstance::SetDeactivated(bool) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0x20×3 / 0x4×3 / 0x8×3 / 0xc×2 / 0x128×1 / 0x5c×1 / 0xd0×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb998 push {r4, r5, r6, r7, r8, lr}
 *   @0x1bb99c cmp r3, #1
 *   @0x1bb9a0 sub sp, sp, #8
 *   @0x1bb9a4 mov r4, #0
 *   @0x1bb9a8 str r4, [r0, #0xc]
 *   @0x1bb9ac ldr r5, [sp, #0x20]
 *   @0x1bb9b0 str r4, [r0]
 *   @0x1bb9b4 str r4, [r0, #0x4]
 *   @0x1bb9b8 beq 0x1bb9d4 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb9bc ldr r0, [pc, #0x128]
 *   @0x1bb9c0 mov r1, r4
 *   @0x1bb9c4 add r0, pc, r0
 *   @0x1bb9c8 add sp, sp, #8
 *   @0x1bb9cc pop {r4, r5, r6, r7, r8, lr}
 *   @0x1bb9d0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb9d4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb9d8 ldr r3, [r5, #0xc]
 *   @0x1bb9dc mov r1, r4
 *   @0x1bb9e0 bic r3, r3, #-16777216
 *   @0x1bb9e4 cmp r3, #1
 *   @0x1bb9e8 mov r6, r0
 *   @0x1bb9ec mov r0, r5
 *   @0x1bb9f0 beq 0x1bbad8 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1bb9f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb9f8 mov r1, r0
 *   @0x1bb9fc mov r0, r6
 *   @0x1bba00 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bba04 cmp r0, #0
 *   @0x1bba08 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1bba0c ldr r4, [r0, #0x5c]
 *   @0x1bba10 cmp r4, #0
 *   @0x1bba14 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1bba18 ldr r8, [pc, #0xd0]
 *   @0x1bba1c mov r7, #0
 *   @0x1bba20 add r8, pc, r8
 *   @0x1bba24 b 0x1bba34 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1bba28 cmp r5, #0
 *   @0x1bba2c mov r4, r5
 *   @0x1bba30 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1bba34 ldr r3, [r4]
 *   @0x1bba38 ldr r5, [r4, #0x18]
 *   @0x1bba3c cmp r3, #2
 *   @0x1bba40 bne 0x1bba28 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bba44 ldr r3, [r4, #0x20]
 *   @0x1bba48 mov r1, #0
 *   @0x1bba4c ldr r6, [pc, #0xa0]
 *   @0x1bba50 cmp r3, r1
 *   @0x1bba54 mov r0, r3
 *   @0x1bba58 beq 0x1bba28 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bba5c ldrb r3, [r3, #0x69]
 *   @0x1bba60 cmp r3, r1
 *   @0x1bba64 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1bba68 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x1bba6c ldr r6, [pc, r6]
 *   @0x1bba70 ldr r4, [r4, #0x20]
 *   @0x1bba74 ldr r1, [r6, #0x8]
 *   @0x1bba78 ldr r3, [r6, #0x4]
 *   @0x1bba7c cmp r1, r3
 *   @0x1bba80 beq 0x1bbaa8 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x1bba84 ldr r2, [r6]
 *   @0x1bba88 cmp r5, #0
 *   @0x1bba8c str r4, [r2, r1, lsl #2]
 *   @0x1bba90 add r3, r1, #1
 *   @0x1bba94 mov r4, r5
 *   @0x1bba98 str r3, [r6, #0x8]
 *   @0x1bba9c bne 0x1bba34 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1bbaa0 add sp, sp, #8
 *   @0x1bbaa4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bbaa8 lsl r3, r1, #1
 *   @0x1bbaac ldr r0, [r6]
 *   @0x1bbab0 str r3, [r6, #0x4]
 *   @0x1bbab4 lsl r1, r1, #3
 *   @0x1bbab8 mov r2, r8
 *   @0x1bbabc str r7, [sp]
 *   @0x1bbac0 mov r3, #74
 *   @0x1bbac4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1bbac8 ldr r1, [r6, #0x8]
 *   @0x1bbacc mov r2, r0
 *   @0x1bbad0 str r0, [r6]
 *   @0x1bbad4 b 0x1bba88 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x1bbad8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bbadc mov r1, r0
 *   @0x1bbae0 mov r0, r6
 *   @0x1bbae4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bbae8 b 0x1bba04 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1bbaec ldrsbeq r2, [r9], -r4
 *   @0x1bbaf0 andseq r5, r7, r0, lsl r6
 *   @0x1bbaf4 .word 0x002321dc
 *
 * ══ §25/87 CheckFileCRC(char const*)  0x1df9d4  size 352  88 条（0x1df9d4..0x1dfb34）
 * @func 0x1df9d4 0x1dfb34  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844×2 / 0xb68d4×2 / 0xb68c8×2 / 0xb6850×2 / InitFastCRC() / 0xb6958 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x144×1 / 0xb4×1 / 0x68×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1df9d4 push {r4, r5, r6, r7, lr}
 *   @0x1df9d8 mov r7, r0
 *   @0x1df9dc ldr r6, [pc, #0x144]
 *   @0x1df9e0 sub sp, sp, #12
 *   @0x1df9e4 bl 0x27de00 <_Z11InitFastCRCv>
 *   @0x1df9e8 mov r0, r7
 *   @0x1df9ec add r6, pc, r6
 *   @0x1df9f0 mov r1, r6
 *   @0x1df9f4 bl 0xb6844 <fopen@plt>
 *   @0x1df9f8 subs r5, r0, #0
 *   @0x1df9fc beq 0x1dfa4c <_Z12CheckFileCRCPKc+0x78>
 *   @0x1dfa00 mov r2, #2
 *   @0x1dfa04 mov r1, #0
 *   @0x1dfa08 bl 0xb68d4 <fseek@plt>
 *   @0x1dfa0c mov r0, r5
 *   @0x1dfa10 mov r1, sp
 *   @0x1dfa14 bl 0xb6958 <fgetpos@plt>
 *   @0x1dfa18 mov r0, r5
 *   @0x1dfa1c mvn r1, #3
 *   @0x1dfa20 mov r2, #2
 *   @0x1dfa24 bl 0xb68d4 <fseek@plt>
 *   @0x1dfa28 mov r3, r5
 *   @0x1dfa2c add r0, sp, #4
 *   @0x1dfa30 mov r1, #1
 *   @0x1dfa34 mov r2, #4
 *   @0x1dfa38 bl 0xb68c8 <fread@plt>
 *   @0x1dfa3c ldr r0, [sp]
 *   @0x1dfa40 cmp r0, #0
 *   @0x1dfa44 moveq r5, r0
 *   @0x1dfa48 bne 0x1dfa58 <_Z12CheckFileCRCPKc+0x84>
 *   @0x1dfa4c mov r0, r5
 *   @0x1dfa50 add sp, sp, #12
 *   @0x1dfa54 pop {r4, r5, r6, r7, pc}
 *   @0x1dfa58 mov r0, r5
 *   @0x1dfa5c mvn r4, #0
 *   @0x1dfa60 bl 0xb6850 <fclose@plt>
 *   @0x1dfa64 mov r1, r6
 *   @0x1dfa68 mov r0, r7
 *   @0x1dfa6c bl 0xb6844 <fopen@plt>
 *   @0x1dfa70 ldr r1, [pc, #0xb4]
 *   @0x1dfa74 mov r2, #78
 *   @0x1dfa78 mov r3, #1
 *   @0x1dfa7c add r1, pc, r1
 *   @0x1dfa80 mov r6, r0
 *   @0x1dfa84 mov r0, #32768
 *   @0x1dfa88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dfa8c ldr r7, [sp]
 *   @0x1dfa90 subs r7, r7, #4
 *   @0x1dfa94 mov r5, r0
 *   @0x1dfa98 beq 0x1dfafc <_Z12CheckFileCRCPKc+0x128>
 *   @0x1dfa9c cmp r7, #32768
 *   @0x1dfaa0 movlo r2, r7
 *   @0x1dfaa4 movhs r2, #32768
 *   @0x1dfaa8 mov r0, r5
 *   @0x1dfaac mov r1, #1
 *   @0x1dfab0 mov r3, r6
 *   @0x1dfab4 bl 0xb68c8 <fread@plt>
 *   @0x1dfab8 cmp r0, #0
 *   @0x1dfabc beq 0x1dfaf4 <_Z12CheckFileCRCPKc+0x120>
 *   @0x1dfac0 ldr r3, [pc, #0x68]
 *   @0x1dfac4 mov r1, #0
 *   @0x1dfac8 mov r2, r1
 *   @0x1dfacc ldr r3, [pc, r3]
 *   @0x1dfad0 ldrb r12, [r5, r1]
 *   @0x1dfad4 add r2, r2, #1
 *   @0x1dfad8 cmp r2, r0
 *   @0x1dfadc eor r12, r4, r12
 *   @0x1dfae0 mov r1, r2
 *   @0x1dfae4 uxtb r12, r12
 *   @0x1dfae8 ldr r12, [r3, r12, lsl #2]
 *   @0x1dfaec eor r4, r12, r4, lsr #8
 *   @0x1dfaf0 bne 0x1dfad0 <_Z12CheckFileCRCPKc+0xfc>
 *   @0x1dfaf4 subs r7, r7, r0
 *   @0x1dfaf8 bne 0x1dfa9c <_Z12CheckFileCRCPKc+0xc8>
 *   @0x1dfafc mov r0, r5
 *   @0x1dfb00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dfb04 ldr r5, [sp, #0x4]
 *   @0x1dfb08 mov r0, r6
 *   @0x1dfb0c subs r3, r4, r5
 *   @0x1dfb10 rsbs r5, r3, #0
 *   @0x1dfb14 adcs r5, r5, r3
 *   @0x1dfb18 bl 0xb6850 <fclose@plt>
 *   @0x1dfb1c mov r0, r5
 *   @0x1dfb20 add sp, sp, #12
 *   @0x1dfb24 pop {r4, r5, r6, r7, pc}
 *   @0x1dfb28 andseq r8, r5, r12, lsl #4
 *   @0x1dfb2c ldrsheq r2, [r7], -r4
 *   @0x1dfb30 eoreq r1, r1, r4, asr r2
 *
 * ══ §26/87 pcre_get_stringtable_entries  0x25f21c  size 352  88 条（0x25f21c..0x25f37c）
 * @func 0x25f21c 0x25f37c  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_fullinfo×3 / 0xb6574×3 / pcre_get_stringtable_entries+0xcc / pcre_get_stringtable_entries+0x94 / pcre_get_stringtable_entries+0x144
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f21c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25f220 sub sp, sp, #28
 *   @0x25f224 mov r6, r1
 *   @0x25f228 mov r10, r2
 *   @0x25f22c str r3, [sp]
 *   @0x25f230 mov r1, #0
 *   @0x25f234 mov r2, #8
 *   @0x25f238 add r3, sp, #16
 *   @0x25f23c mov r4, r0
 *   @0x25f240 bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f244 subs r1, r0, #0
 *   @0x25f248 bne 0x25f270 <pcre_get_stringtable_entries+0x54>
 *   @0x25f24c ldr r3, [sp, #0x10]
 *   @0x25f250 cmp r3, #0
 *   @0x25f254 ble 0x25f2e8 <pcre_get_stringtable_entries+0xcc>
 *   @0x25f258 mov r0, r4
 *   @0x25f25c mov r2, #7
 *   @0x25f260 add r3, sp, #12
 *   @0x25f264 bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f268 subs r1, r0, #0
 *   @0x25f26c beq 0x25f27c <pcre_get_stringtable_entries+0x60>
 *   @0x25f270 mov r0, r1
 *   @0x25f274 add sp, sp, #28
 *   @0x25f278 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25f27c mov r0, r4
 *   @0x25f280 mov r2, #9
 *   @0x25f284 add r3, sp, #20
 *   @0x25f288 bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f28c cmp r0, #0
 *   @0x25f290 bne 0x25f274 <pcre_get_stringtable_entries+0x58>
 *   @0x25f294 ldr r2, [sp, #0x10]
 *   @0x25f298 mov r9, r0
 *   @0x25f29c ldr r8, [sp, #0x14]
 *   @0x25f2a0 ldr r7, [sp, #0xc]
 *   @0x25f2a4 str r2, [sp, #0x4]
 *   @0x25f2a8 mov r11, r2
 *   @0x25f2ac b 0x25f2d4 <pcre_get_stringtable_entries+0xb8>
 *   @0x25f2b0 asr r5, r5, #1
 *   @0x25f2b4 mla r4, r5, r7, r8
 *   @0x25f2b8 add r1, r4, #2
 *   @0x25f2bc bl 0xb6574 <strcmp@plt>
 *   @0x25f2c0 cmp r0, #0
 *   @0x25f2c4 beq 0x25f2f0 <pcre_get_stringtable_entries+0xd4>
 *   @0x25f2c8 addgt r9, r5, #1
 *   @0x25f2cc movle r11, r5
 *   @0x25f2d0 strle r5, [sp, #0x10]
 *   @0x25f2d4 add r5, r9, r11
 *   @0x25f2d8 cmp r9, r11
 *   @0x25f2dc mov r0, r6
 *   @0x25f2e0 add r5, r5, r5, lsr #31
 *   @0x25f2e4 blt 0x25f2b0 <pcre_get_stringtable_entries+0x94>
 *   @0x25f2e8 mvn r0, #6
 *   @0x25f2ec b 0x25f274 <pcre_get_stringtable_entries+0x58>
 *   @0x25f2f0 cmp r8, r4
 *   @0x25f2f4 bhs 0x25f374 <pcre_get_stringtable_entries+0x158>
 *   @0x25f2f8 rsb r5, r7, #2
 *   @0x25f2fc mov r11, r4
 *   @0x25f300 b 0x25f310 <pcre_get_stringtable_entries+0xf4>
 *   @0x25f304 rsb r11, r7, r11
 *   @0x25f308 cmp r8, r11
 *   @0x25f30c bhs 0x25f324 <pcre_get_stringtable_entries+0x108>
 *   @0x25f310 mov r0, r6
 *   @0x25f314 add r1, r11, r5
 *   @0x25f318 bl 0xb6574 <strcmp@plt>
 *   @0x25f31c cmp r0, #0
 *   @0x25f320 beq 0x25f304 <pcre_get_stringtable_entries+0xe8>
 *   @0x25f324 ldr r2, [sp, #0x4]
 *   @0x25f328 sub r3, r2, #1
 *   @0x25f32c mla r8, r7, r3, r8
 *   @0x25f330 cmp r8, r4
 *   @0x25f334 addhi r5, r7, #2
 *   @0x25f338 bhi 0x25f34c <pcre_get_stringtable_entries+0x130>
 *   @0x25f33c b 0x25f360 <pcre_get_stringtable_entries+0x144>
 *   @0x25f340 add r4, r4, r7
 *   @0x25f344 cmp r8, r4
 *   @0x25f348 bls 0x25f360 <pcre_get_stringtable_entries+0x144>
 *   @0x25f34c mov r0, r6
 *   @0x25f350 add r1, r4, r5
 *   @0x25f354 bl 0xb6574 <strcmp@plt>
 *   @0x25f358 cmp r0, #0
 *   @0x25f35c beq 0x25f340 <pcre_get_stringtable_entries+0x124>
 *   @0x25f360 ldr r3, [sp]
 *   @0x25f364 mov r0, r7
 *   @0x25f368 str r11, [r10]
 *   @0x25f36c str r4, [r3]
 *   @0x25f370 b 0x25f274 <pcre_get_stringtable_entries+0x58>
 *   @0x25f374 mov r11, r4
 *   @0x25f378 b 0x25f324 <pcre_get_stringtable_entries+0x108>
 *
 * ══ §27/87 jpeg_fill_bit_buffer  0x2bea2c  size 352  88 条（0x2bea2c..0x2beb8c）
 * @func 0x2bea2c 0x2beb8c  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_fill_bit_buffer+0x94
 * 字段偏移 top8: 0x4×6 / 0x18×4 / 0x17c×2 / 0xc×2 / 0x198×2 / 0x8×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bea2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bea30 sub sp, sp, #12
 *   @0x2bea34 ldr r7, [r0, #0x10]
 *   @0x2bea38 mov r9, r0
 *   @0x2bea3c str r3, [sp, #0x4]
 *   @0x2bea40 mov r8, r1
 *   @0x2bea44 mov r11, r2
 *   @0x2bea48 ldr r5, [r0]
 *   @0x2bea4c ldr r3, [r7, #0x17c]
 *   @0x2bea50 ldr r4, [r0, #0x4]
 *   @0x2bea54 cmp r3, #0
 *   @0x2bea58 bne 0x2beb28 <jpeg_fill_bit_buffer+0xfc>
 *   @0x2bea5c cmp r2, #24
 *   @0x2bea60 ble 0x2beac0 <jpeg_fill_bit_buffer+0x94>
 *   @0x2bea64 mov r0, #1
 *   @0x2bea68 str r5, [r9]
 *   @0x2bea6c stmib r9, {r4, r8, r11}
 *   @0x2bea70 add sp, sp, #12
 *   @0x2bea74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bea78 ldr r3, [r7, #0x18]
 *   @0x2bea7c mov r0, r7
 *   @0x2bea80 ldr r3, [r3, #0xc]
 *   @0x2bea84 blx r3
 *   @0x2bea88 cmp r0, #0
 *   @0x2bea8c beq 0x2beb54 <jpeg_fill_bit_buffer+0x128>
 *   @0x2bea90 ldr r3, [r7, #0x18]
 *   @0x2bea94 ldr r5, [r3]
 *   @0x2bea98 ldr r4, [r3, #0x4]
 *   @0x2bea9c ldrb r10, [r5]
 *   @0x2beaa0 sub r4, r4, #1
 *   @0x2beaa4 add r5, r5, #1
 *   @0x2beaa8 cmp r10, #255
 *   @0x2beaac beq 0x2beacc <jpeg_fill_bit_buffer+0xa0>
 *   @0x2beab0 add r11, r11, #8
 *   @0x2beab4 orr r8, r10, r8, lsl #8
 *   @0x2beab8 cmp r11, #24
 *   @0x2beabc bgt 0x2bea64 <jpeg_fill_bit_buffer+0x38>
 *   @0x2beac0 cmp r4, #0
 *   @0x2beac4 bne 0x2bea9c <jpeg_fill_bit_buffer+0x70>
 *   @0x2beac8 b 0x2bea78 <jpeg_fill_bit_buffer+0x4c>
 *   @0x2beacc mov r12, r5
 *   @0x2bead0 b 0x2beaec <jpeg_fill_bit_buffer+0xc0>
 *   @0x2bead4 ldrb r6, [r12]
 *   @0x2bead8 add r5, r12, #1
 *   @0x2beadc sub r4, r4, #1
 *   @0x2beae0 cmp r6, #255
 *   @0x2beae4 mov r12, r5
 *   @0x2beae8 bne 0x2beb1c <jpeg_fill_bit_buffer+0xf0>
 *   @0x2beaec cmp r4, #0
 *   @0x2beaf0 bne 0x2bead4 <jpeg_fill_bit_buffer+0xa8>
 *   @0x2beaf4 ldr r3, [r7, #0x18]
 *   @0x2beaf8 mov r0, r7
 *   @0x2beafc ldr r3, [r3, #0xc]
 *   @0x2beb00 blx r3
 *   @0x2beb04 cmp r0, #0
 *   @0x2beb08 beq 0x2beb54 <jpeg_fill_bit_buffer+0x128>
 *   @0x2beb0c ldr r3, [r7, #0x18]
 *   @0x2beb10 ldr r12, [r3]
 *   @0x2beb14 ldr r4, [r3, #0x4]
 *   @0x2beb18 b 0x2bead4 <jpeg_fill_bit_buffer+0xa8>
 *   @0x2beb1c cmp r6, #0
 *   @0x2beb20 beq 0x2beab0 <jpeg_fill_bit_buffer+0x84>
 *   @0x2beb24 str r6, [r7, #0x17c]
 *   @0x2beb28 ldr r3, [sp, #0x4]
 *   @0x2beb2c cmp r11, r3
 *   @0x2beb30 bge 0x2bea64 <jpeg_fill_bit_buffer+0x38>
 *   @0x2beb34 ldr r3, [r7, #0x198]
 *   @0x2beb38 ldrb r3, [r3, #0x8]
 *   @0x2beb3c cmp r3, #0
 *   @0x2beb40 beq 0x2beb60 <jpeg_fill_bit_buffer+0x134>
 *   @0x2beb44 rsb r3, r11, #25
 *   @0x2beb48 mov r11, #25
 *   @0x2beb4c lsl r8, r8, r3
 *   @0x2beb50 b 0x2bea64 <jpeg_fill_bit_buffer+0x38>
 *   @0x2beb54 mov r0, #0
 *   @0x2beb58 add sp, sp, #12
 *   @0x2beb5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2beb60 ldr r3, [r7]
 *   @0x2beb64 mov r2, #117
 *   @0x2beb68 mov r0, r7
 *   @0x2beb6c mvn r1, #0
 *   @0x2beb70 str r2, [r3, #0x14]
 *   @0x2beb74 ldr r3, [r3, #0x4]
 *   @0x2beb78 blx r3
 *   @0x2beb7c ldr r3, [r7, #0x198]
 *   @0x2beb80 mov r2, #1
 *   @0x2beb84 strb r2, [r3, #0x8]
 *   @0x2beb88 b 0x2beb44 <jpeg_fill_bit_buffer+0x118>
 *
 * ══ §28/87 b2MouseJoint::SolveVelocityConstraints(b2SolverData const&)  0x2cea54  size 352  88 条（0x2cea54..0x2cebb4）
 * @func 0x2cea54 0x2cebb4  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x74×2 / 0x1c×2 / 0x4×2
 * VFP 指令 68 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cea54 ldr r2, [r0, #0x74]
 *   @0x2cea58 vldr s10, [r0, #120]
 *   @0x2cea5c push {r4, lr}
 *   @0x2cea60 vpush {d8, d9, d10}
 *   @0x2cea64 mov r4, r0
 *   @0x2cea68 vldr s9, [r4, #124]
 *   @0x2cea6c ldr r0, [r1, #0x1c]
 *   @0x2cea70 add r3, r2, r2, lsl #1
 *   @0x2cea74 vldr s11, [r4, #164]
 *   @0x2cea78 vldr s13, [r4, #108]
 *   @0x2cea7c add r3, r0, r3, lsl #2
 *   @0x2cea80 vldr s20, [r3, #4]
 *   @0x2cea84 vmov.f32 s4, s20
 *   @0x2cea88 vldr s16, [r3, #8]
 *   @0x2cea8c vldr s21, [r3]
 *   @0x2cea90 vldr s17, [r4, #100]
 *   @0x2cea94 vldr s12, [r4, #160]
 *   @0x2cea98 vldr s18, [r4, #96]
 *   @0x2cea9c vldr s14, [r4, #156]
 *   @0x2ceaa0 vldr s6, [r4, #148]
 *   @0x2ceaa4 vmla.f32 s4, s16, s10
 *   @0x2ceaa8 vldr s15, [r4, #152]
 *   @0x2ceaac vldr s7, [r4, #144]
 *   @0x2ceab0 vldr s19, [r1]
 *   @0x2ceab4 vldr s8, [r4, #104]
 *   @0x2ceab8 sub sp, sp, #8
 *   @0x2ceabc vmov.f32 s5, s21
 *   @0x2ceac0 vmls.f32 s5, s16, s9
 *   @0x2ceac4 vadd.f32 s11, s4, s11
 *   @0x2ceac8 vmla.f32 s11, s13, s17
 *   @0x2ceacc vadd.f32 s12, s5, s12
 *   @0x2cead0 vmla.f32 s12, s13, s18
 *   @0x2cead4 vneg.f32 s11, s11
 *   @0x2cead8 vmul.f32 s14, s11, s14
 *   @0x2ceadc vneg.f32 s12, s12
 *   @0x2ceae0 vmul.f32 s15, s11, s15
 *   @0x2ceae4 vmla.f32 s14, s12, s6
 *   @0x2ceae8 vmla.f32 s15, s12, s7
 *   @0x2ceaec vadd.f32 s14, s17, s14
 *   @0x2ceaf0 vmul.f32 s13, s14, s14
 *   @0x2ceaf4 vstr s14, [r4, #100]
 *   @0x2ceaf8 vadd.f32 s15, s18, s15
 *   @0x2ceafc vmul.f32 s19, s19, s8
 *   @0x2ceb00 vstr s15, [r4, #96]
 *   @0x2ceb04 vmla.f32 s13, s15, s15
 *   @0x2ceb08 vmul.f32 s12, s19, s19
 *   @0x2ceb0c vcmpe.f32 s12, s13
 *   @0x2ceb10 vmrs APSR_nzcv, fpscr
 *   @0x2ceb14 bmi 0x2ceb54 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x100>
 *   @0x2ceb18 vsub.f32 s18, s15, s18
 *   @0x2ceb1c vldr s12, [r4, #136]
 *   @0x2ceb20 vldr s15, [r4, #140]
 *   @0x2ceb24 vmul.f32 s13, s18, s9
 *   @0x2ceb28 vsub.f32 s17, s14, s17
 *   @0x2ceb2c vnmls.f32 s13, s17, s10
 *   @0x2ceb30 vmla.f32 s21, s12, s18
 *   @0x2ceb34 vmla.f32 s16, s13, s15
 *   @0x2ceb38 vstr s21, [r3]
 *   @0x2ceb3c vmla.f32 s20, s12, s17
 *   @0x2ceb40 vstr s16, [r3, #8]
 *   @0x2ceb44 vstr s20, [r3, #4]
 *   @0x2ceb48 add sp, sp, #8
 *   @0x2ceb4c vpop {d8, d9, d10}
 *   @0x2ceb50 pop {r4, pc}
 *   @0x2ceb54 vsqrt.f32 s14, s13
 *   @0x2ceb58 vcmp.f32 s14, s14
 *   @0x2ceb5c vmrs APSR_nzcv, fpscr
 *   @0x2ceb60 bne 0x2ceb8c <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x138>
 *   @0x2ceb64 vdiv.f32 s19, s19, s14
 *   @0x2ceb68 vldr s15, [r4, #96]
 *   @0x2ceb6c vldr s14, [r4, #100]
 *   @0x2ceb70 add r2, r2, r2, lsl #1
 *   @0x2ceb74 add r3, r0, r2, lsl #2
 *   @0x2ceb78 vmul.f32 s15, s19, s15
 *   @0x2ceb7c vmul.f32 s14, s19, s14
 *   @0x2ceb80 vstr s15, [r4, #96]
 *   @0x2ceb84 vstr s14, [r4, #100]
 *   @0x2ceb88 b 0x2ceb18 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0xc4>
 *   @0x2ceb8c vmov r0, s13
 *   @0x2ceb90 str r1, [sp, #0x4]
 *   @0x2ceb94 bl 0xb6700 <sqrtf@plt>
 *   @0x2ceb98 ldr r1, [sp, #0x4]
 *   @0x2ceb9c vldr s9, [r4, #124]
 *   @0x2ceba0 ldr r2, [r4, #0x74]
 *   @0x2ceba4 vldr s10, [r4, #120]
 *   @0x2ceba8 vmov s14, r0
 *   @0x2cebac ldr r0, [r1, #0x1c]
 *   @0x2cebb0 b 0x2ceb64 <_ZN12b2MouseJoint24SolveVelocityConstraintsERK12b2SolverData+0x110>
 *
 * ══ §29/87 anon_317a44  0x317a44  size 352  88 条（0x317a44..0x317ba4）
 * @func 0x317a44 0x317ba4  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xff49ec28 / 0x3c3d80
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x317a44 ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x317a48 stmdavs r0, {r2, r9, r10, lr}
 *   @0x317a4c ldrmi r4, [r7], -r10, lsl #13
 *   @0x317a50 ldrmi r11, [lr], -r6, lsl #1
 *   @0x317a54 .word 0xf8502200
 *   @0x317a58 ldrtmi r1, [r11], -r8, lsl #24
 *   @0x317a5c stmdaeq r1, {r2, r8, r9, r11, sp, lr, pc}
 *   @0x317a60 strbmi r5, [r0], -r1, ror #16
 *   @0x317a64 .word 0x9c04f851
 *   @0x317a68 .word 0xf7ff4649
 *   @0x317a6c strmi pc, [r5], -pc, lsl #30
 *   @0x317a70 eorle r2, r9, r0, lsl #26
 *   @0x317a74 ldrhle r1, [r10], -r1
 *   @0x317a78 bl 0xff49ec28 <b2_toiTime+0xfffffffffed45784>
 *   @0x317a7c svclt #0x180004
 *   @0x317a80 cdphs p2, #0x0, c2, c0, c1, #0x0
 *   @0x317a84 movwhs r11, #0xfb4
 *   @0x317a88 movweq pc, #0x1002
 *   @0x317a8c stm sp, {r0, r1, r5, r6, r7, r8, r11, r12, sp, pc}
 *   @0x317a90 smladls r2, r0, r4, r0
 *   @0x317a94 movwls r9, #0x4603
 *   @0x317a98 biclt r9, r2, r5, lsl #6
 *   @0x317a9c ldrtmi r4, [r9], -r8, lsr #12
 *   @0x317aa0 .word 0xf7ff466a
 *   @0x317aa4 stmdals r5, {r0, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x317aa8 movwlo r1, #0x3e43
 *   @0x317aac andhs sp, r0, r12, lsl #18
 *   @0x317ab0 andle r1, r9, r10, ror #24
 *   @0x317ab4 strbmi r4, [r9], -r0, asr #12
 *   @0x317ab8 ldrbmi r4, [r3], -r2, lsr #12
 *   @0x317abc mcr2 p7, #0x7, pc, c6, c15, #0x7
 *   @0x317ac0 svclt #0xc4284
 *   @0x317ac4 andhs r4, r0, r8, lsr #12
 *   @0x317ac8 pop {r1, r2, r12, sp, pc}
 *   @0x317acc .word 0x464087f0
 *   @0x317ad0 strbtmi r4, [r10], -r9, asr #12
 *   @0x317ad4 .word 0xff48f7ff
 *   @0x317ad8 svclt #0xe7e5
 *   @0x317adc .word 0x4602b538
 *   @0x317ae0 .word 0x46054b10
 *   @0x317ae4 ldrbtmi r4, [r11], #-2320
 *   @0x317ae8 .word 0xf103681b
 *   @0x317aec ldrbtmi r0, [r9], #-168
 *   @0x317af0 mrc p5, #0x6, apsr_nzcv, c8, c14, #0x4
 *   @0x317af4 .word 0x2100480d
 *   @0x317af8 .word 0xf59e4478
 *   @0x317afc .word 0x4604ed12
 *   @0x317b00 stmdbmi r11, {r3, r5, r6, r8, r12, sp, pc}
 *   @0x317b04 .word 0xf59e4479
 *   @0x317b08 strmi lr, [r3], -r6, lsl #26
 *   @0x317b0c stmdbmi r9, {r5, r8, r12, sp, pc}
 *   @0x317b10 strtmi r2, [r10], -r7
 *   @0x317b14 .word 0x47984479
 *   @0x317b18 .word 0xf59e4620
 *   @0x317b1c .word 0xf000ed08
 *   @0x317b20 svclt #0xfb97
 *   @0x317b24 andeq r9, sp, r2, ror #18
 *   @0x317b28 ldrdeq r4, r5, [r4], -r10
 *   @0x317b2c andeq r4, r4, r4, ror #21
 *   @0x317b30 andeq r4, r4, r4, ror #21
 *   @0x317b34 andeq r4, r4, r8, ror #21
 *   @0x317b38 .word 0xf7ffb508
 *   @0x317b3c .word 0xf000fdf1
 *   @0x317b40 svclt #0xfb87
 *   @0x317b44 mrslt r6, apsr
 *   @0x317b48 sadd16mi r5, r8, r11
 *   @0x317b4c svclt #0x4770
 *   @0x317b50 teqlt r10, r8, lsl #10
 *   @0x317b54 addeq lr, r0, r2, lsr #23
 *   @0x317b58 mrslt r6, apsr
 *   @0x317b5c stclt p8, c5, [r8, #-768]
 *   @0x317b60 stclt p6, c4, [r8, #-96]
 *   @0x317b64 .word 0xf7ff9802
 *   @0x317b68 svclt #0xffe7
 *   @0x317b6c ldrblt r4, [r0, #-0x3c0]!
 *   @0x317b70 bl 0x3c3d80 <error_g0017+0x1ca24>
 *   @0x317b74 stcls p0, c0, [r6, #-512]
 *   @0x317b78 .word 0x9c071f06
 *   @0x317b7c ands r11, r0, r2, asr #18
 *   @0x317b80 qadd8mi r5, r9, r8
 *   @0x317b84 bge 0x37cb90 <_ZTS13C_UTF16String+0x13c3c>
 *   @0x317b88 ldmvs r11, {r0, r1, r11, sp, lr}
 *   @0x317b8c ldmdblt r0!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x317b90 svclo #0x4f856
 *   @0x317b94 mvnsle r2, r0, lsl #22
 *   @0x317b98 andlt r2, r2, r1
 *   @0x317b9c andhs r11, r0, r0, ror sp
 *   @0x317ba0 stmdals r8, {r0, r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *
 * ══ §30/87 F_InstanceDeactivateRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x10b5f4  size 348  87 条（0x10b5f4..0x10b750）
 * @func 0x10b5f4 0x10b750  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)×2 / GetActiveList(void (*)(CInstance*)) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x20×1 / 0x12c×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0xb4×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b5f4 push {r4, r5, r6, lr}
 *   @0x10b5f8 vpush {d8}
 *   @0x10b5fc sub sp, sp, #8
 *   @0x10b600 mov r6, r1
 *   @0x10b604 mov r1, #4
 *   @0x10b608 ldr r5, [sp, #0x20]
 *   @0x10b60c ldr r4, [pc, #0x12c]
 *   @0x10b610 mov r0, r5
 *   @0x10b614 add r4, pc, r4
 *   @0x10b618 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x10b61c mov r1, #0
 *   @0x10b620 strb r0, [r4, #0xc]
 *   @0x10b624 mov r0, r5
 *   @0x10b628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b62c mov r1, #1
 *   @0x10b630 str r0, [r4, #0x10]
 *   @0x10b634 mov r0, r5
 *   @0x10b638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b63c mov r1, #2
 *   @0x10b640 vldr s17, [r4, #16]
 *   @0x10b644 str r0, [r4, #0x14]
 *   @0x10b648 mov r0, r5
 *   @0x10b64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b650 mov r1, #3
 *   @0x10b654 vldr s16, [r4, #20]
 *   @0x10b658 vmov s15, r0
 *   @0x10b65c mov r0, r5
 *   @0x10b660 vadd.f32 s17, s17, s15
 *   @0x10b664 vstr s17, [r4, #24]
 *   @0x10b668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10b66c mov r1, #5
 *   @0x10b670 vmov s15, r0
 *   @0x10b674 mov r0, r5
 *   @0x10b678 vadd.f32 s16, s16, s15
 *   @0x10b67c vstr s16, [r4, #28]
 *   @0x10b680 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x10b684 mov r4, r0
 *   @0x10b688 ldr r0, [pc, #0xb4]
 *   @0x10b68c cmp r6, #0
 *   @0x10b690 moveq r4, #0
 *   @0x10b694 andne r4, r4, #1
 *   @0x10b698 ldr r0, [pc, r0]
 *   @0x10b69c bl 0x10b24c <_Z13GetActiveListPFvP9CInstanceE>
 *   @0x10b6a0 cmp r4, #0
 *   @0x10b6a4 beq 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x10b6a8 ldrb r12, [r6, #0x68]
 *   @0x10b6ac cmp r12, #0
 *   @0x10b6b0 bne 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x10b6b4 ldrb r3, [r6, #0x69]
 *   @0x10b6b8 cmp r3, #0
 *   @0x10b6bc beq 0x10b700 <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x10b6c0 ldr r4, [pc, #0x80]
 *   @0x10b6c4 ldr r4, [pc, r4]
 *   @0x10b6c8 ldr r1, [r4, #0x8]
 *   @0x10b6cc ldr r3, [r4, #0x4]
 *   @0x10b6d0 cmp r1, r3
 *   @0x10b6d4 beq 0x10b70c <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x10b6d8 ldr r3, [r4]
 *   @0x10b6dc str r6, [r3, r1, lsl #2]
 *   @0x10b6e0 mov r0, r6
 *   @0x10b6e4 add r3, r1, #1
 *   @0x10b6e8 mov r1, #0
 *   @0x10b6ec str r3, [r4, #0x8]
 *   @0x10b6f0 add sp, sp, #8
 *   @0x10b6f4 vpop {d8}
 *   @0x10b6f8 pop {r4, r5, r6, lr}
 *   @0x10b6fc b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10b700 add sp, sp, #8
 *   @0x10b704 vpop {d8}
 *   @0x10b708 pop {r4, r5, r6, pc}
 *   @0x10b70c ldr r2, [pc, #0x38]
 *   @0x10b710 lsl r3, r1, #1
 *   @0x10b714 ldr r0, [r4]
 *   @0x10b718 lsl r1, r1, #3
 *   @0x10b71c str r3, [r4, #0x4]
 *   @0x10b720 add r2, pc, r2
 *   @0x10b724 mov r3, #74
 *   @0x10b728 str r12, [sp]
 *   @0x10b72c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10b730 ldr r1, [r4, #0x8]
 *   @0x10b734 mov r3, r0
 *   @0x10b738 str r0, [r4]
 *   @0x10b73c b 0x10b6dc <_Z26F_InstanceDeactivateRegionR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x10b740 eorseq r8, r7, r4, asr #1
 *   @0x10b744 eoreq r2, lr, r4, lsr #20
 *   @0x10b748 eoreq r2, lr, r4, lsl #11
 *   @0x10b74c eoreq r5, r2, r0, lsl r9
 *
 * ══ §31/87 F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1217e8  size 348  87 条（0x1217e8..0x121944）
 * @func 0x1217e8 0x121944  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0x14c / CreateArray(RValue*, int, ...) / F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0x124 / F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0x24 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0xb8×3 / 0x4×3 / 0x20×2 / 0x140×1 / 0xc×1 / 0x2c×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1217e8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1217ec vpush {d8}
 *   @0x1217f0 mov r7, r0
 *   @0x1217f4 ldr r6, [pc, #0x140]
 *   @0x1217f8 ldr r6, [pc, r6]
 *   @0x1217fc ldr r3, [r6]
 *   @0x121800 ldr r4, [r3, #0xb8]
 *   @0x121804 cmp r4, #0
 *   @0x121808 bne 0x121814 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x12180c vpop {d8}
 *   @0x121810 pop {r3, r4, r5, r6, r7, pc}
 *   @0x121814 ldr r0, [sp, #0x20]
 *   @0x121818 mov r1, #0
 *   @0x12181c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121820 cmp r4, #0
 *   @0x121824 vmov s16, r0
 *   @0x121828 ble 0x121934 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x12182c ldr r0, [r6]
 *   @0x121830 mov r2, #0
 *   @0x121834 mov r3, r2
 *   @0x121838 mov r5, r2
 *   @0x12183c ldr r12, [r0, #0xb8]
 *   @0x121840 cmp r12, r3
 *   @0x121844 mov r1, #0
 *   @0x121848 add r3, r3, #1
 *   @0x12184c ldrgt r1, [r0, #0xc0]
 *   @0x121850 addgt r1, r1, r2
 *   @0x121854 vldr s15, [r1, #28]
 *   @0x121858 vcmp.f32 s15, s16
 *   @0x12185c add r2, r2, #56
 *   @0x121860 vmrs APSR_nzcv, fpscr
 *   @0x121864 addeq r5, r5, #1
 *   @0x121868 cmp r3, r4
 *   @0x12186c bne 0x121840 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x121870 mov r0, r7
 *   @0x121874 mov r3, #0
 *   @0x121878 mov r1, #1
 *   @0x12187c mov r2, #0
 *   @0x121880 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121884 ldr r3, [r7]
 *   @0x121888 ldr r0, [r3, #0x4]
 *   @0x12188c ldr r3, [r0]
 *   @0x121890 cmp r3, r5
 *   @0x121894 ble 0x12190c <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x121898 cmp r4, #0
 *   @0x12189c ldr r12, [r0, #0x4]
 *   @0x1218a0 ble 0x12180c <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x1218a4 mov r0, #0
 *   @0x1218a8 ldr r5, [r6]
 *   @0x1218ac mov r1, r0
 *   @0x1218b0 mov r6, r0
 *   @0x1218b4 ldr r2, [r5, #0xb8]
 *   @0x1218b8 mov r3, #0
 *   @0x1218bc cmp r2, r1
 *   @0x1218c0 add r1, r1, #1
 *   @0x1218c4 ldrgt r3, [r5, #0xc0]
 *   @0x1218c8 addgt r3, r3, r0
 *   @0x1218cc vldr s15, [r3, #28]
 *   @0x1218d0 vcmp.f32 s15, s16
 *   @0x1218d4 add r0, r0, #56
 *   @0x1218d8 vmrs APSR_nzcv, fpscr
 *   @0x1218dc bne 0x1218fc <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x1218e0 ldr r2, [r3, #0x20]
 *   @0x1218e4 str r6, [r12, #0xc]
 *   @0x1218e8 vmov s15, r2
 *   @0x1218ec vcvt.f64.s32 d7, s15
 *   @0x1218f0 vmov r2, r3, d7
 *   @0x1218f4 stm r12, {r2, r3}
 *   @0x1218f8 add r12, r12, #16
 *   @0x1218fc cmp r1, r4
 *   @0x121900 bne 0x1218b4 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x121904 vpop {d8}
 *   @0x121908 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12190c ldr r2, [pc, #0x2c]
 *   @0x121910 add r0, r0, #4
 *   @0x121914 movw r3, #0x118e
 *   @0x121918 lsl r1, r5, #4
 *   @0x12191c add r2, pc, r2
 *   @0x121920 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x121924 ldr r3, [r7]
 *   @0x121928 ldr r0, [r3, #0x4]
 *   @0x12192c str r5, [r0]
 *   @0x121930 b 0x121898 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x121934 mov r5, #0
 *   @0x121938 b 0x121870 <_Z19F_TileGetIDsAtDepthR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x12193c eoreq r12, r12, r0, lsr r1
 *   @0x121940 eoreq r8, r1, r4, lsr r6
 *
 * ══ §32/87 F_Push_LocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)  0x155988  size 348  85 条（0x155988..0x155ae4）
 * @func 0x155988 0x155ae4  size 348  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x15599c→0x544be4, 0x1559fc→0x3eb70c, 0x155a94→0x3eb70c
 * 调用序列: YYGetString(RValue const*, int)×3 / YYGetReal(RValue const*, int) / F_DateCurrentDateTime(RValue&, CInstance*, CInstance*, int, RValue*) / Push_SendLocalNotification(double, char const*, char const*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x40×2 / 0xd4×2 / 0x134×1 / 0x130×1 / 0x4×1 / 0x3c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155988 push {r4, r5, r6, r7, lr}
 *   @0x15598c vpush {d8, d9}
 *   @0x155990 mov r4, #0
 *   @0x155994 ldr r6, [pc, #0x134]
 *   @0x155998 sub sp, sp, #28
 *   @0x15599c ldr r3, [pc, #0x130]
 *   @0x1559a0 mov r5, r0
 *   @0x1559a4 add r6, pc, r6
 *   @0x1559a8 str r4, [r0]
 *   @0x1559ac str r4, [r0, #0xc]
 *   @0x1559b0 str r4, [r0, #0x4]
 *   @0x1559b4 ldr r3, [r6, r3]
 *   @0x1559b8 ldr r7, [sp, #0x40]
 *   @0x1559bc ldrb r3, [r3]
 *   @0x1559c0 cmp r3, r4
 *   @0x1559c4 beq 0x155a94 <_Z24F_Push_LocalNotificationR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x1559c8 mov r0, r7
 *   @0x1559cc mov r1, r4
 *   @0x1559d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1559d4 mov r2, r4
 *   @0x1559d8 str r4, [sp]
 *   @0x1559dc mov r3, r4
 *   @0x1559e0 vmov d9, r0, r1
 *   @0x1559e4 add r0, sp, #8
 *   @0x1559e8 mov r1, r4
 *   @0x1559ec bl 0x114ed8 <_Z21F_DateCurrentDateTimeR6RValueP9CInstanceS2_iPS_>
 *   @0x1559f0 vldr d7, [sp, #8]
 *   @0x1559f4 vsub.f64 d8, d9, d7
 *   @0x1559f8 vldr d6, [pc, #192]
 *   @0x1559fc ldr r3, [pc, #0xd4]
 *   @0x155a00 ldr r1, [pc, #0xd4]
 *   @0x155a04 ldr r3, [r6, r3]
 *   @0x155a08 add r1, pc, r1
 *   @0x155a0c ldr r0, [r3]
 *   @0x155a10 vmul.f64 d8, d8, d6
 *   @0x155a14 ldr r3, [r0]
 *   @0x155a18 ldr r3, [r3, #0xc]
 *   @0x155a1c vcmpe.f64 d8, #0
 *   @0x155a20 vmrs APSR_nzcv, fpscr
 *   @0x155a24 vcvtpl.s32.f64 s15, d8
 *   @0x155a28 movmi r2, r4
 *   @0x155a2c vldrmi d8, [pc, #148]
 *   @0x155a30 vmovpl r2, s15
 *   @0x155a34 blx r3
 *   @0x155a38 mov r0, r7
 *   @0x155a3c mov r1, #1
 *   @0x155a40 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x155a44 mov r1, #2
 *   @0x155a48 mov r6, r0
 *   @0x155a4c mov r0, r7
 *   @0x155a50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x155a54 mov r1, #3
 *   @0x155a58 mov r4, r0
 *   @0x155a5c mov r0, r7
 *   @0x155a60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x155a64 mov r2, r6
 *   @0x155a68 mov r3, r4
 *   @0x155a6c str r0, [sp]
 *   @0x155a70 vmov r0, r1, d8
 *   @0x155a74 bl 0x161b4c <_Z26Push_SendLocalNotificationdPKcS0_S0_>
 *   @0x155a78 mov r3, #0
 *   @0x155a7c mov r2, r3
 *   @0x155a80 movt r3, #0x3ff0
 *   @0x155a84 stm r5, {r2, r3}
 *   @0x155a88 add sp, sp, #28
 *   @0x155a8c vpop {d8, d9}
 *   @0x155a90 pop {r4, r5, r6, r7, pc}
 *   @0x155a94 ldr r3, [pc, #0x3c]
 *   @0x155a98 ldr r1, [pc, #0x40]
 *   @0x155a9c ldr r3, [r6, r3]
 *   @0x155aa0 add r1, pc, r1
 *   @0x155aa4 ldr r0, [r3]
 *   @0x155aa8 ldr r3, [r0]
 *   @0x155aac ldr r3, [r3, #0xc]
 *   @0x155ab0 blx r3
 *   @0x155ab4 add sp, sp, #28
 *   @0x155ab8 vpop {d8, d9}
 *   @0x155abc pop {r4, r5, r6, r7, pc}
 *   @0x155ac0 andeq r0, r0, r0
 *   @0x155ac4 rscsmi r1, r5, r0, lsl #16
 *   @0x155ad0 eoreq r12, r9, r12, lsr #5
 *   @0x155ad4 .word 0xffffdec0
 *   @0x155ad8 .word 0xffffbac4
 *   @0x155adc andseq r0, pc, r12, lsr #19
 *   @0x155ae0 andseq r0, pc, r0, asr #18
 *
 * ══ §33/87 F_YoYo_WinPhone_SetTile_Cycle_CycleImages(RValue&, CInstance*, CInstance*, int, RValue*)  0x158578  size 348  87 条（0x158578..0x1586d4）
 * @func 0x158578 0x1586d4  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1585c8→0x3eb70c, 0x158694→0x3eb70c
 * 调用序列: Error_Show_Action(char const*, bool) / YYGetString(RValue const*, int) / 0xb6538 / 0xb65bc / 0xb65d4
 * 字段偏移 top8: 0xc×5 / 0x4×2 / 0x-28×2 / 0xf4×2 / 0x-34×2 / 0x-30×2 / 0x134×1 / 0x130×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158578 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15857c add r11, sp, #32
 *   @0x158580 ldr r4, [pc, #0x134]
 *   @0x158584 sub sp, sp, #20
 *   @0x158588 ldr r2, [pc, #0x130]
 *   @0x15858c add r4, pc, r4
 *   @0x158590 sub r1, r3, #1
 *   @0x158594 cmp r1, #8
 *   @0x158598 mov r1, #0
 *   @0x15859c ldr r6, [r4, r2]
 *   @0x1585a0 ldr r7, [r11, #0x4]
 *   @0x1585a4 str r1, [r0, #0xc]
 *   @0x1585a8 ldr r2, [r6]
 *   @0x1585ac str r1, [r0, #0x4]
 *   @0x1585b0 str r1, [r0]
 *   @0x1585b4 str r2, [r11, #-0x28]
 *   @0x1585b8 bhi 0x1585c8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1585bc ldr r2, [r7, #0xc]
 *   @0x1585c0 cmp r2, #1
 *   @0x1585c4 beq 0x158610 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1585c8 ldr r3, [pc, #0xf4]
 *   @0x1585cc ldr r1, [pc, #0xf4]
 *   @0x1585d0 ldr r3, [r4, r3]
 *   @0x1585d4 add r1, pc, r1
 *   @0x1585d8 ldr r0, [r3]
 *   @0x1585dc ldr r3, [r0]
 *   @0x1585e0 ldr r3, [r3, #0xc]
 *   @0x1585e4 blx r3
 *   @0x1585e8 ldr r0, [pc, #0xdc]
 *   @0x1585ec mov r1, #0
 *   @0x1585f0 add r0, pc, r0
 *   @0x1585f4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1585f8 ldr r2, [r11, #-0x28]
 *   @0x1585fc ldr r3, [r6]
 *   @0x158600 cmp r2, r3
 *   @0x158604 bne 0x1586b8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x158608 sub sp, r11, #32
 *   @0x15860c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x158610 lsl r2, r3, #2
 *   @0x158614 mov r5, r1
 *   @0x158618 add r2, r2, #14
 *   @0x15861c mov r8, r1
 *   @0x158620 bic r2, r2, #7
 *   @0x158624 mov r10, r7
 *   @0x158628 sub sp, sp, r2
 *   @0x15862c mov r9, sp
 *   @0x158630 b 0x158644 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x158634 add r5, r5, #1
 *   @0x158638 add r10, r10, #16
 *   @0x15863c cmp r5, r3
 *   @0x158640 beq 0x158694 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x158644 ldr r2, [r10, #0xc]
 *   @0x158648 cmp r2, #1
 *   @0x15864c bne 0x158634 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x158650 mov r1, r5
 *   @0x158654 mov r0, r7
 *   @0x158658 str r3, [r11, #-0x34]
 *   @0x15865c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158660 str r0, [r11, #-0x30]
 *   @0x158664 bl 0xb6538 <strlen@plt>
 *   @0x158668 ldr r1, [r11, #-0x30]
 *   @0x15866c add r12, r0, #15
 *   @0x158670 add r2, r0, #1
 *   @0x158674 bic r12, r12, #7
 *   @0x158678 sub sp, sp, r12
 *   @0x15867c str sp, [r9, r8, lsl #2]
 *   @0x158680 add r8, r8, #1
 *   @0x158684 mov r0, sp
 *   @0x158688 bl 0xb65bc <memcpy@plt>
 *   @0x15868c ldr r3, [r11, #-0x34]
 *   @0x158690 b 0x158634 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x158694 ldr r3, [pc, #0x28]
 *   @0x158698 ldr r1, [pc, #0x30]
 *   @0x15869c ldr r3, [r4, r3]
 *   @0x1586a0 add r1, pc, r1
 *   @0x1586a4 ldr r0, [r3]
 *   @0x1586a8 ldr r3, [r0]
 *   @0x1586ac ldr r3, [r3, #0xc]
 *   @0x1586b0 blx r3
 *   @0x1586b4 b 0x1585f8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1586b8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1586bc eoreq r9, r9, r4, asr #13
 *   @0x1586c0 .word 0xffffbd00
 *   @0x1586c4 .word 0xffffbac4
 *   @0x1586c8 andseq lr, lr, r8, lsr #2
 *   @0x1586cc ldrsbeq sp, [lr], -r8
 *   @0x1586d0 andseq sp, lr, r12, ror #28
 *
 * ══ §34/87 F_PlayerRun(RValue&, CInstance*, CInstance*, int, RValue*)  0x158824  size 348  87 条（0x158824..0x158980）
 * @func 0x158824 0x158980  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1588c4→0x54297c, 0x1588d8→0x484a84, 0x1588dc→0x484a74, 0x1588f4→0x484a7c, 0x1588f8→0x3eb70c
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*)×3 / YYStrDup(char const*)×3 / YYGetString(RValue const*, int)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x78×3 / 0x804×2 / 0x8c×2 / 0x12c×1 / 0x128×1 / 0x820×1 / 0x9c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158824 push {r4, r5, r6, r7, r8, lr}
 *   @0x158828 sub sp, sp, #2048
 *   @0x15882c ldr r4, [pc, #0x12c]
 *   @0x158830 sub sp, sp, #8
 *   @0x158834 ldr r3, [pc, #0x128]
 *   @0x158838 mov r1, #0
 *   @0x15883c add r4, pc, r4
 *   @0x158840 ldr r7, [sp, #0x820]
 *   @0x158844 ldr r6, [r4, r3]
 *   @0x158848 mov r0, r7
 *   @0x15884c ldr r3, [r6]
 *   @0x158850 str r3, [sp, #0x804]
 *   @0x158854 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158858 mov r1, #1
 *   @0x15885c mov r5, r0
 *   @0x158860 mov r0, r7
 *   @0x158864 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158868 mov r8, r0
 *   @0x15886c mov r0, r5
 *   @0x158870 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x158874 cmp r0, #0
 *   @0x158878 bne 0x158944 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x15887c mov r0, r5
 *   @0x158880 add r7, sp, #4
 *   @0x158884 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x158888 mov r2, r5
 *   @0x15888c mov r1, #1024
 *   @0x158890 cmp r0, #0
 *   @0x158894 mov r0, r7
 *   @0x158898 bne 0x15893c <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x15889c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1588a0 add r5, sp, #1024
 *   @0x1588a4 mov r1, #1024
 *   @0x1588a8 add r5, r5, #8
 *   @0x1588ac mov r2, r8
 *   @0x1588b0 sub r5, r5, #4
 *   @0x1588b4 mov r0, r5
 *   @0x1588b8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1588bc mov r0, r5
 *   @0x1588c0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1588c4 ldr r3, [pc, #0x9c]
 *   @0x1588c8 ldr r3, [r4, r3]
 *   @0x1588cc str r0, [r3]
 *   @0x1588d0 mov r0, r7
 *   @0x1588d4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1588d8 ldr r2, [pc, #0x8c]
 *   @0x1588dc ldr r3, [pc, #0x8c]
 *   @0x1588e0 ldr r2, [r4, r2]
 *   @0x1588e4 str r0, [r2]
 *   @0x1588e8 ldr r3, [r4, r3]
 *   @0x1588ec ldr r0, [r3]
 *   @0x1588f0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1588f4 ldr r2, [pc, #0x78]
 *   @0x1588f8 ldr r3, [pc, #0x78]
 *   @0x1588fc ldr r1, [pc, #0x78]
 *   @0x158900 ldr r2, [r4, r2]
 *   @0x158904 add r1, pc, r1
 *   @0x158908 str r0, [r2]
 *   @0x15890c ldr r3, [r4, r3]
 *   @0x158910 ldr r0, [r3]
 *   @0x158914 ldr r3, [r0]
 *   @0x158918 ldr r3, [r3, #0xc]
 *   @0x15891c blx r3
 *   @0x158920 ldr r2, [sp, #0x804]
 *   @0x158924 ldr r3, [r6]
 *   @0x158928 cmp r2, r3
 *   @0x15892c bne 0x15895c <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x158930 add sp, sp, #2048
 *   @0x158934 add sp, sp, #8
 *   @0x158938 pop {r4, r5, r6, r7, r8, pc}
 *   @0x15893c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x158940 b 0x1588a0 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x158944 add r7, sp, #4
 *   @0x158948 mov r2, r5
 *   @0x15894c mov r1, #1024
 *   @0x158950 mov r0, r7
 *   @0x158954 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x158958 b 0x1588a0 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x15895c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x158960 eoreq r9, r9, r4, lsl r4
 *   @0x158964 .word 0xffffbd00
 *   @0x158968 .word 0xffffdf54
 *   @0x15896c .word 0xffffdf58
 *   @0x158970 .word 0xffffdf5c
 *   @0x158974 .word 0xffffdf60
 *   @0x158978 .word 0xffffbac4
 *   @0x15897c andseq sp, lr, r8, asr lr
 *
 * ══ §35/87 CBitmap32::Stretch(int, int)  0x1673ac  size 348  87 条（0x1673ac..0x167508）
 * @func 0x1673ac 0x167508  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / 0xb6598×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CBitmap32::Stretch(int, int)+0x120 / CBitmap32::Stretch(int, int)+0x104 / CBitmap32::Stretch(int, int)+0xf4 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×5 / 0xc×5 / 0x4×3 / 0x14×2 / 0x120×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1673ac ldrb r3, [r0, #0x4]
 *   @0x1673b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1673b4 cmp r3, #0
 *   @0x1673b8 sub sp, sp, #20
 *   @0x1673bc mov r5, r0
 *   @0x1673c0 mov r11, r1
 *   @0x1673c4 mov r7, r2
 *   @0x1673c8 beq 0x1674ec <_ZN9CBitmap327StretchEii+0x140>
 *   @0x1673cc ldr r3, [r0, #0x8]
 *   @0x1673d0 cmp r3, r1
 *   @0x1673d4 beq 0x1674f4 <_ZN9CBitmap327StretchEii+0x148>
 *   @0x1673d8 mul r0, r7, r11
 *   @0x1673dc ldr r1, [pc, #0x120]
 *   @0x1673e0 movw r2, #0x447
 *   @0x1673e4 mov r3, #1
 *   @0x1673e8 add r1, pc, r1
 *   @0x1673ec lsl r0, r0, #2
 *   @0x1673f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1673f4 ldr r2, [r5, #0x14]
 *   @0x1673f8 cmp r7, #0
 *   @0x1673fc str r2, [sp, #0x4]
 *   @0x167400 str r0, [sp, #0xc]
 *   @0x167404 ble 0x1674cc <_ZN9CBitmap327StretchEii+0x120>
 *   @0x167408 mov r6, #0
 *   @0x16740c lsl r3, r11, #2
 *   @0x167410 str r0, [sp]
 *   @0x167414 str r3, [sp, #0x8]
 *   @0x167418 cmp r11, #0
 *   @0x16741c ble 0x1674b0 <_ZN9CBitmap327StretchEii+0x104>
 *   @0x167420 mov r4, #0
 *   @0x167424 mov r10, r11
 *   @0x167428 ldr r8, [r5, #0x8]
 *   @0x16742c mov r1, r10
 *   @0x167430 mul r0, r4, r8
 *   @0x167434 bl 0x318d10 <__divsi3>
 *   @0x167438 vmov s15, r0
 *   @0x16743c vcvt.f64.s32 d7, s15
 *   @0x167440 vmov r0, r1, d7
 *   @0x167444 bl 0xb6598 <floor@plt>
 *   @0x167448 ldr r9, [r5, #0xc]
 *   @0x16744c vmov d7, r0, r1
 *   @0x167450 mov r1, r7
 *   @0x167454 mul r0, r6, r9
 *   @0x167458 vcvt.s32.f64 s15, d7
 *   @0x16745c vmov r11, s15
 *   @0x167460 bl 0x318d10 <__divsi3>
 *   @0x167464 vmov s15, r0
 *   @0x167468 vcvt.f64.s32 d7, s15
 *   @0x16746c vmov r0, r1, d7
 *   @0x167470 bl 0xb6598 <floor@plt>
 *   @0x167474 cmp r8, r11
 *   @0x167478 vmov d7, r0, r1
 *   @0x16747c ble 0x1674a0 <_ZN9CBitmap327StretchEii+0xf4>
 *   @0x167480 vcvt.s32.f64 s13, d7
 *   @0x167484 vmov r2, s13
 *   @0x167488 mla r8, r2, r8, r11
 *   @0x16748c cmp r9, r2
 *   @0x167490 ldrgt r3, [sp, #0x4]
 *   @0x167494 ldrgt r2, [r3, r8, lsl #2]
 *   @0x167498 ldrgt r3, [sp]
 *   @0x16749c strgt r2, [r3, r4, lsl #2]
 *   @0x1674a0 add r4, r4, #1
 *   @0x1674a4 cmp r4, r10
 *   @0x1674a8 bne 0x167428 <_ZN9CBitmap327StretchEii+0x7c>
 *   @0x1674ac mov r11, r10
 *   @0x1674b0 add r6, r6, #1
 *   @0x1674b4 ldr r2, [sp]
 *   @0x1674b8 ldr r3, [sp, #0x8]
 *   @0x1674bc cmp r6, r7
 *   @0x1674c0 add r2, r2, r3
 *   @0x1674c4 str r2, [sp]
 *   @0x1674c8 bne 0x167418 <_ZN9CBitmap327StretchEii+0x6c>
 *   @0x1674cc ldr r0, [sp, #0x4]
 *   @0x1674d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1674d4 ldr r3, [sp, #0xc]
 *   @0x1674d8 str r11, [r5, #0x8]
 *   @0x1674dc str r7, [r5, #0xc]
 *   @0x1674e0 str r3, [r5, #0x14]
 *   @0x1674e4 mov r3, #0
 *   @0x1674e8 str r3, [r5, #0x10]
 *   @0x1674ec add sp, sp, #20
 *   @0x1674f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1674f4 ldr r3, [r0, #0xc]
 *   @0x1674f8 cmp r3, r2
 *   @0x1674fc bne 0x1673d8 <_ZN9CBitmap327StretchEii+0x2c>
 *   @0x167500 b 0x1674ec <_ZN9CBitmap327StretchEii+0x140>
 *   @0x167504 ldrsbeq r3, [lr], -r8
 *
 * ══ §36/87 Shader_Load(Shader*)  0x1884f4  size 348  87 条（0x1884f4..0x188650）
 * @func 0x1884f4 0x188650  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Get_Uniform_Handle(Shader*, char const*)×6 / Shader_Add(char*, char*, char**, bool*, int, char**) / Shader_Get_Sampler_Index(Shader*, char const*)
 * 字段偏移 top8: 0xf8×2 / 0xc×2 / 0x60×2 / 0x80×2 / 0x70×2 / 0x12c×1 / 0x5c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1884f4 ldr r3, [pc, #0x12c]
 *   @0x1884f8 push {r4, r5, lr}
 *   @0x1884fc ldr r3, [pc, r3]
 *   @0x188500 sub sp, sp, #12
 *   @0x188504 mov r4, r0
 *   @0x188508 ldr r5, [r3]
 *   @0x18850c cmp r5, #1
 *   @0x188510 beq 0x188558 <_Z11Shader_LoadP6Shader+0x64>
 *   @0x188514 cmp r5, #0
 *   @0x188518 beq 0x18852c <_Z11Shader_LoadP6Shader+0x38>
 *   @0x18851c mov r5, #0
 *   @0x188520 mov r0, r5
 *   @0x188524 add sp, sp, #12
 *   @0x188528 pop {r4, r5, pc}
 *   @0x18852c ldr r3, [pc, #0xf8]
 *   @0x188530 ldr r1, [pc, #0xf8]
 *   @0x188534 ldr r3, [pc, r3]
 *   @0x188538 add r1, pc, r1
 *   @0x18853c ldr r0, [r3]
 *   @0x188540 ldr r3, [r0]
 *   @0x188544 ldr r3, [r3, #0xc]
 *   @0x188548 blx r3
 *   @0x18854c mov r0, r5
 *   @0x188550 add sp, sp, #12
 *   @0x188554 pop {r4, r5, pc}
 *   @0x188558 cmp r0, #0
 *   @0x18855c beq 0x18851c <_Z11Shader_LoadP6Shader+0x28>
 *   @0x188560 ldr lr, [r4, #0x5c]
 *   @0x188564 add r2, r4, #84
 *   @0x188568 ldr r12, [r4, #0x60]
 *   @0x18856c add r3, r4, #88
 *   @0x188570 ldr r0, [r0, #0xc]
 *   @0x188574 ldr r1, [r4, #0x10]
 *   @0x188578 str lr, [sp]
 *   @0x18857c str r12, [sp, #0x4]
 *   @0x188580 bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_>
 *   @0x188584 cmn r0, #1
 *   @0x188588 str r0, [r4, #0x64]
 *   @0x18858c beq 0x18851c <_Z11Shader_LoadP6Shader+0x28>
 *   @0x188590 ldr r1, [pc, #0x9c]
 *   @0x188594 mov r0, r4
 *   @0x188598 add r1, pc, r1
 *   @0x18859c bl 0x188468 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc>
 *   @0x1885a0 ldr r1, [pc, #0x90]
 *   @0x1885a4 add r1, pc, r1
 *   @0x1885a8 str r0, [r4, #0x68]
 *   @0x1885ac mov r0, r4
 *   @0x1885b0 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x1885b4 ldr r1, [pc, #0x80]
 *   @0x1885b8 add r1, pc, r1
 *   @0x1885bc str r0, [r4, #0x6c]
 *   @0x1885c0 mov r0, r4
 *   @0x1885c4 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x1885c8 ldr r1, [pc, #0x70]
 *   @0x1885cc add r1, pc, r1
 *   @0x1885d0 str r0, [r4, #0x70]
 *   @0x1885d4 mov r0, r4
 *   @0x1885d8 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x1885dc ldr r1, [pc, #0x60]
 *   @0x1885e0 add r1, pc, r1
 *   @0x1885e4 str r0, [r4, #0x74]
 *   @0x1885e8 mov r0, r4
 *   @0x1885ec bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x1885f0 ldr r1, [pc, #0x50]
 *   @0x1885f4 add r1, pc, r1
 *   @0x1885f8 str r0, [r4, #0x78]
 *   @0x1885fc mov r0, r4
 *   @0x188600 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x188604 ldr r1, [pc, #0x40]
 *   @0x188608 add r1, pc, r1
 *   @0x18860c str r0, [r4, #0x7c]
 *   @0x188610 mov r0, r4
 *   @0x188614 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x188618 str r0, [r4, #0x80]
 *   @0x18861c mov r0, r5
 *   @0x188620 add sp, sp, #12
 *   @0x188624 pop {r4, r5, pc}
 *   @0x188628 eoreq r7, r6, r12, lsl #30
 *   @0x18862c eoreq r5, r6, r0, ror #3
 *   @0x188630 andseq r3, r12, r12, lsl #22
 *   @0x188634 andseq r3, r12, r12, lsr #13
 *   @0x188638 andseq r3, r12, r12, lsr #17
 *   @0x18863c andseq r3, r12, r12, lsr r10
 *   @0x188640 andseq r3, r12, r12, lsr r10
 *   @0x188644 andseq r3, r12, r12, lsr r10
 *   @0x188648 andseq r3, r12, r12, lsr r10
 *   @0x18864c andseq r3, r12, r4, asr r8
 *
 * ══ §37/87 Shader_Set_Uniform_IA(int, int, int*)  0x188794  size 348  87 条（0x188794..0x1888f0）
 * @func 0x188794 0x1888f0  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / Shader_Set_Uniform_IA(int, int, int*)+0x3c / Shader_Get(int) / Shader_Set_Uniform_IA(int, int, int*)+0x11c / Shader_Set_Uniform_IA(int, int, int*)+0x108 / Shader_Set_Uniform_Matrix(int, int, int, float*) / Shader_Set_Uniform_I(int, int, int, int*) / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x-20×2 / 0x140×1 / 0x13c×1 / 0xf0×1 / 0x64×1 / 0x7c×1 / 0x78×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188794 push {r4, r5, r6, r7, r8, r9, r11, lr}
 *   @0x188798 add r11, sp, #28
 *   @0x18879c ldr r12, [pc, #0x140]
 *   @0x1887a0 sub sp, sp, #8
 *   @0x1887a4 ldr r4, [pc, #0x13c]
 *   @0x1887a8 ldr r12, [pc, r12]
 *   @0x1887ac mov r6, r0
 *   @0x1887b0 ldr r4, [pc, r4]
 *   @0x1887b4 mov r7, r1
 *   @0x1887b8 ldr r5, [r12]
 *   @0x1887bc mov r8, r2
 *   @0x1887c0 ldr r12, [r4]
 *   @0x1887c4 cmp r5, #1
 *   @0x1887c8 str r12, [r11, #-0x20]
 *   @0x1887cc beq 0x1887ec <_Z21Shader_Set_Uniform_IAiiPi+0x58>
 *   @0x1887d0 mov r0, #0
 *   @0x1887d4 ldr r2, [r11, #-0x20]
 *   @0x1887d8 ldr r3, [r4]
 *   @0x1887dc cmp r2, r3
 *   @0x1887e0 bne 0x1888e0 <_Z21Shader_Set_Uniform_IAiiPi+0x14c>
 *   @0x1887e4 sub sp, r11, #28
 *   @0x1887e8 pop {r4, r5, r6, r7, r8, r9, r11, pc}
 *   @0x1887ec cmp r0, #0
 *   @0x1887f0 blt 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c>
 *   @0x1887f4 ldr r12, [pc, #0xf0]
 *   @0x1887f8 ldr r12, [pc, r12]
 *   @0x1887fc ldr r3, [r12]
 *   @0x188800 cmp r3, #0
 *   @0x188804 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c>
 *   @0x188808 ldr r0, [r3, #0x64]
 *   @0x18880c bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188810 cmp r0, #0
 *   @0x188814 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c>
 *   @0x188818 ldr r3, [r0, #0x7c]
 *   @0x18881c cmp r6, r3
 *   @0x188820 bge 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c>
 *   @0x188824 ldr r3, [r0, #0x78]
 *   @0x188828 rsb r6, r6, r6, lsl #3
 *   @0x18882c adds r6, r3, r6, lsl #2
 *   @0x188830 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c>
 *   @0x188834 ldr r9, [r6, #0x10]
 *   @0x188838 cmp r9, #1
 *   @0x18883c ble 0x1888b0 <_Z21Shader_Set_Uniform_IAiiPi+0x11c>
 *   @0x188840 ldr r1, [r6, #0x14]
 *   @0x188844 cmp r1, #0
 *   @0x188848 beq 0x1888a8 <_Z21Shader_Set_Uniform_IAiiPi+0x114>
 *   @0x18884c mov r0, r7
 *   @0x188850 bl 0x318d10 <__divsi3>
 *   @0x188854 subs r2, r0, #0
 *   @0x188858 moveq r0, r5
 *   @0x18885c beq 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40>
 *   @0x188860 lsl lr, r2, #2
 *   @0x188864 subgt r8, r8, #4
 *   @0x188868 add r3, lr, #14
 *   @0x18886c bic r3, r3, #7
 *   @0x188870 sub sp, sp, r3
 *   @0x188874 mov r3, sp
 *   @0x188878 movgt r12, sp
 *   @0x18887c addgt lr, lr, r3
 *   @0x188880 ble 0x18889c <_Z21Shader_Set_Uniform_IAiiPi+0x108>
 *   @0x188884 ldr r1, [r8, #0x4]!
 *   @0x188888 vmov s15, r1
 *   @0x18888c vcvt.f32.s32 s15, s15
 *   @0x188890 vstmia r12!, {s15}
 *   @0x188894 cmp r12, lr
 *   @0x188898 bne 0x188884 <_Z21Shader_Set_Uniform_IAiiPi+0xf0>
 *   @0x18889c ldr r0, [r6, #0x4]
 *   @0x1888a0 mov r1, r9
 *   @0x1888a4 bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf>
 *   @0x1888a8 mov r0, #1
 *   @0x1888ac b 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40>
 *   @0x1888b0 ldr r9, [r6, #0xc]
 *   @0x1888b4 mov r0, r7
 *   @0x1888b8 ldr r6, [r6, #0x4]
 *   @0x1888bc mov r1, r9
 *   @0x1888c0 bl 0x318d10 <__divsi3>
 *   @0x1888c4 mov r1, r9
 *   @0x1888c8 mov r3, r8
 *   @0x1888cc mov r2, r0
 *   @0x1888d0 mov r0, r6
 *   @0x1888d4 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi>
 *   @0x1888d8 mov r0, r5
 *   @0x1888dc b 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40>
 *   @0x1888e0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1888e4 eoreq r7, r6, r0, ror #24
 *   @0x1888e8 eoreq r5, r6, r0, lsr #3
 *   @0x1888ec eoreq r7, r6, r0, lsl #25
 *
 * ══ §38/87 FINALIZE_Object_Main()  0x19f0c0  size 348  87 条（0x19f0c0..0x19f21c）
 * @func 0x19f0c0 0x19f21c  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×3 / MemoryManager::Free(void const*)×3 / FINALIZE_Object_Main()+0x14c×2 / CObjectGM::~CObjectGM()×2
 * 字段偏移 top8: 0x4×6 / 0x8×4 / 0x144×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f0c0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19f0c4 mov r11, #0
 *   @0x19f0c8 ldr r8, [pc, #0x144]
 *   @0x19f0cc ldr r3, [pc, #0x144]
 *   @0x19f0d0 ldr r8, [pc, r8]
 *   @0x19f0d4 ldr r3, [pc, r3]
 *   @0x19f0d8 ldr r7, [r8]
 *   @0x19f0dc str r11, [r3]
 *   @0x19f0e0 cmp r7, r11
 *   @0x19f0e4 beq 0x19f200 <_Z20FINALIZE_Object_Mainv+0x140>
 *   @0x19f0e8 ldr r10, [r7, #0x4]
 *   @0x19f0ec cmp r10, r11
 *   @0x19f0f0 blt 0x19f20c <_Z20FINALIZE_Object_Mainv+0x14c>
 *   @0x19f0f4 lsl r9, r10, #3
 *   @0x19f0f8 ldr r3, [r7]
 *   @0x19f0fc add r2, r3, r9
 *   @0x19f100 ldr r4, [r3, r9]
 *   @0x19f104 str r11, [r3, r9]
 *   @0x19f108 cmp r4, #0
 *   @0x19f10c str r11, [r2, #0x4]
 *   @0x19f110 beq 0x19f154 <_Z20FINALIZE_Object_Mainv+0x94>
 *   @0x19f114 ldr r5, [r4, #0xc]
 *   @0x19f118 ldr r6, [r4, #0x4]
 *   @0x19f11c cmp r5, #0
 *   @0x19f120 mov r0, r5
 *   @0x19f124 beq 0x19f134 <_Z20FINALIZE_Object_Mainv+0x74>
 *   @0x19f128 bl 0x19d558 <_ZN9CObjectGMD2Ev>
 *   @0x19f12c mov r0, r5
 *   @0x19f130 bl 0x27d1d0 <_ZdlPv>
 *   @0x19f134 mov r0, r4
 *   @0x19f138 mov r4, r6
 *   @0x19f13c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19f140 ldr r3, [r7, #0x8]
 *   @0x19f144 cmp r6, #0
 *   @0x19f148 sub r3, r3, #1
 *   @0x19f14c str r3, [r7, #0x8]
 *   @0x19f150 bne 0x19f114 <_Z20FINALIZE_Object_Mainv+0x54>
 *   @0x19f154 sub r10, r10, #1
 *   @0x19f158 sub r9, r9, #8
 *   @0x19f15c cmn r10, #1
 *   @0x19f160 bne 0x19f0f8 <_Z20FINALIZE_Object_Mainv+0x38>
 *   @0x19f164 ldr r7, [r8]
 *   @0x19f168 cmp r7, #0
 *   @0x19f16c beq 0x19f200 <_Z20FINALIZE_Object_Mainv+0x140>
 *   @0x19f170 ldr r10, [r7, #0x4]
 *   @0x19f174 cmp r10, #0
 *   @0x19f178 blt 0x19f20c <_Z20FINALIZE_Object_Mainv+0x14c>
 *   @0x19f17c ldr r0, [r7]
 *   @0x19f180 lsl r9, r10, #3
 *   @0x19f184 mov r11, #0
 *   @0x19f188 ldr r4, [r0, r9]
 *   @0x19f18c add r3, r0, r9
 *   @0x19f190 str r11, [r0, r9]
 *   @0x19f194 cmp r4, #0
 *   @0x19f198 str r11, [r3, #0x4]
 *   @0x19f19c beq 0x19f1e4 <_Z20FINALIZE_Object_Mainv+0x124>
 *   @0x19f1a0 ldr r5, [r4, #0xc]
 *   @0x19f1a4 ldr r6, [r4, #0x4]
 *   @0x19f1a8 cmp r5, #0
 *   @0x19f1ac mov r0, r5
 *   @0x19f1b0 beq 0x19f1c0 <_Z20FINALIZE_Object_Mainv+0x100>
 *   @0x19f1b4 bl 0x19d558 <_ZN9CObjectGMD2Ev>
 *   @0x19f1b8 mov r0, r5
 *   @0x19f1bc bl 0x27d1d0 <_ZdlPv>
 *   @0x19f1c0 mov r0, r4
 *   @0x19f1c4 mov r4, r6
 *   @0x19f1c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19f1cc ldr r3, [r7, #0x8]
 *   @0x19f1d0 cmp r6, #0
 *   @0x19f1d4 sub r3, r3, #1
 *   @0x19f1d8 str r3, [r7, #0x8]
 *   @0x19f1dc bne 0x19f1a0 <_Z20FINALIZE_Object_Mainv+0xe0>
 *   @0x19f1e0 ldr r0, [r7]
 *   @0x19f1e4 sub r10, r10, #1
 *   @0x19f1e8 sub r9, r9, #8
 *   @0x19f1ec cmn r10, #1
 *   @0x19f1f0 bne 0x19f188 <_Z20FINALIZE_Object_Mainv+0xc8>
 *   @0x19f1f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19f1f8 mov r0, r7
 *   @0x19f1fc bl 0x27d1d0 <_ZdlPv>
 *   @0x19f200 mov r3, #0
 *   @0x19f204 str r3, [r8]
 *   @0x19f208 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19f20c ldr r0, [r7]
 *   @0x19f210 b 0x19f1f4 <_Z20FINALIZE_Object_Mainv+0x134>
 *   @0x19f214 eoreq lr, r4, r12, ror #22
 *   @0x19f218 eoreq r1, r5, r0, lsl r6
 *
 * ══ §39/87 CLayerManager::GetTilesFromPool(int)  0x1ba3b8  size 348  87 条（0x1ba3b8..0x1ba514）
 * @func 0x1ba3b8 0x1ba514  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTilesFromPool(int)+0x14c / CLayerManager::GetTilesFromPool(int)+0xcc / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetTilesFromPool(int)+0x60
 * 字段偏移 top8: 0x8×8 / 0x10×3 / 0x4×2 / 0xc×1 / 0x118×1 / 0x114×1 / 0x708×1 / 0x704×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba3b8 adds r3, r1, #31
 *   @0x1ba3bc addmi r1, r1, #62
 *   @0x1ba3c0 movpl r1, r3
 *   @0x1ba3c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1ba3c8 asr r9, r1, #5
 *   @0x1ba3cc mov r8, #0
 *   @0x1ba3d0 cmp r9, r8
 *   @0x1ba3d4 mov r7, r0
 *   @0x1ba3d8 str r8, [r0, #0x4]
 *   @0x1ba3dc str r8, [r0]
 *   @0x1ba3e0 str r8, [r0, #0x8]
 *   @0x1ba3e4 str r8, [r0, #0xc]
 *   @0x1ba3e8 ble 0x1ba504 <_ZN13CLayerManager16GetTilesFromPoolEi+0x14c>
 *   @0x1ba3ec ldr r4, [pc, #0x118]
 *   @0x1ba3f0 mov r5, r8
 *   @0x1ba3f4 ldr r6, [pc, #0x114]
 *   @0x1ba3f8 ldr r4, [pc, r4]
 *   @0x1ba3fc add r6, pc, r6
 *   @0x1ba400 ldr r10, [r4, #0x8]
 *   @0x1ba404 cmp r10, #0
 *   @0x1ba408 bne 0x1ba48c <_ZN13CLayerManager16GetTilesFromPoolEi+0xd4>
 *   @0x1ba40c ldr r3, [r4, #0x10]
 *   @0x1ba410 cmp r3, #0
 *   @0x1ba414 ble 0x1ba484 <_ZN13CLayerManager16GetTilesFromPoolEi+0xcc>
 *   @0x1ba418 mov r2, #63
 *   @0x1ba41c mov r3, #1
 *   @0x1ba420 movw r0, #0x70c
 *   @0x1ba424 mov r1, r6
 *   @0x1ba428 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1ba42c ldr r3, [r4]
 *   @0x1ba430 add r10, r10, #1
 *   @0x1ba434 ldr r2, [r4, #0x8]
 *   @0x1ba438 add r2, r2, #1
 *   @0x1ba43c str r2, [r4, #0x8]
 *   @0x1ba440 cmp r0, #0
 *   @0x1ba444 strne r5, [r0, #0x704]
 *   @0x1ba448 strne r5, [r0, #0x708]
 *   @0x1ba44c strne r5, [r0, #0x700]
 *   @0x1ba450 cmp r3, #0
 *   @0x1ba454 strne r0, [r3, #0x708]
 *   @0x1ba458 streq r3, [r0, #0x708]
 *   @0x1ba45c streq r3, [r0, #0x704]
 *   @0x1ba460 strne r3, [r0, #0x704]
 *   @0x1ba464 ldr r3, [r4, #0x10]
 *   @0x1ba468 streq r0, [r4, #0x4]
 *   @0x1ba46c streq r0, [r4]
 *   @0x1ba470 strne r0, [r4]
 *   @0x1ba474 strne r5, [r0, #0x708]
 *   @0x1ba478 cmp r10, r3
 *   @0x1ba47c blt 0x1ba418 <_ZN13CLayerManager16GetTilesFromPoolEi+0x60>
 *   @0x1ba480 ldr r10, [r4, #0x8]
 *   @0x1ba484 lsl r3, r3, #1
 *   @0x1ba488 str r3, [r4, #0x10]
 *   @0x1ba48c ldr r3, [r4]
 *   @0x1ba490 sub r10, r10, #1
 *   @0x1ba494 add r8, r8, #1
 *   @0x1ba498 ldr r2, [r3, #0x708]
 *   @0x1ba49c ldr r1, [r3, #0x704]
 *   @0x1ba4a0 cmp r2, #0
 *   @0x1ba4a4 strne r1, [r2, #0x704]
 *   @0x1ba4a8 ldrne r1, [r3, #0x704]
 *   @0x1ba4ac ldrne r2, [r3, #0x708]
 *   @0x1ba4b0 streq r1, [r4]
 *   @0x1ba4b4 cmp r1, #0
 *   @0x1ba4b8 streq r2, [r4, #0x4]
 *   @0x1ba4bc strne r2, [r1, #0x708]
 *   @0x1ba4c0 ldr r2, [r7, #0x4]
 *   @0x1ba4c4 str r10, [r4, #0x8]
 *   @0x1ba4c8 cmp r2, #0
 *   @0x1ba4cc ldr r1, [r7, #0x8]
 *   @0x1ba4d0 streq r3, [r7, #0x4]
 *   @0x1ba4d4 add r1, r1, #1
 *   @0x1ba4d8 str r1, [r7, #0x8]
 *   @0x1ba4dc strne r3, [r2, #0x704]
 *   @0x1ba4e0 ldrne r2, [r7, #0x4]
 *   @0x1ba4e4 streq r3, [r7]
 *   @0x1ba4e8 streq r2, [r3, #0x708]
 *   @0x1ba4ec strne r2, [r3, #0x708]
 *   @0x1ba4f0 streq r2, [r3, #0x704]
 *   @0x1ba4f4 strne r3, [r7, #0x4]
 *   @0x1ba4f8 strne r5, [r3, #0x704]
 *   @0x1ba4fc cmp r8, r9
 *   @0x1ba500 bne 0x1ba400 <_ZN13CLayerManager16GetTilesFromPoolEi+0x48>
 *   @0x1ba504 mov r0, r7
 *   @0x1ba508 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1ba50c eoreq r6, r3, r4, lsl #9
 *   @0x1ba510 mulseq r9, r8, r2
 *
 * ══ §40/87 RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*)  0x1cb234  size 348  87 条（0x1cb234..0x1cb390）
 * @func 0x1cb234 0x1cb390  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*)+0xa0×3 / anon_1c8380+0x4f0×3 / RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*)+0xac / RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*) / RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*)+0x128
 * 字段偏移 top8: 0x30×3 / 0x4×2 / 0x34×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cb234 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cb238 mov r7, r1
 *   @0x1cb23c ldr r1, [r1, #0x4]
 *   @0x1cb240 sub sp, sp, #12
 *   @0x1cb244 mov r11, r0
 *   @0x1cb248 mov r6, r2
 *   @0x1cb24c cmp r1, #0
 *   @0x1cb250 mov r8, r3
 *   @0x1cb254 ldr r5, [r7]
 *   @0x1cb258 ldr r9, [sp, #0x34]
 *   @0x1cb25c ble 0x1cb2e0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xac>
 *   @0x1cb260 cmp r5, #0
 *   @0x1cb264 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0>
 *   @0x1cb268 add r4, r7, #8
 *   @0x1cb26c mov r10, #0
 *   @0x1cb270 b 0x1cb284 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x50>
 *   @0x1cb274 add r10, r10, #1
 *   @0x1cb278 add r4, r4, #24
 *   @0x1cb27c cmp r5, r10
 *   @0x1cb280 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0>
 *   @0x1cb284 mov r0, r6
 *   @0x1cb288 mov r1, r4
 *   @0x1cb28c bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0>
 *   @0x1cb290 cmp r0, #0
 *   @0x1cb294 beq 0x1cb274 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x40>
 *   @0x1cb298 ldr r3, [sp, #0x30]
 *   @0x1cb29c mov r0, r11
 *   @0x1cb2a0 ldr r1, [r4, #0x10]
 *   @0x1cb2a4 mov r2, r6
 *   @0x1cb2a8 str r9, [sp, #0x4]
 *   @0x1cb2ac str r3, [sp]
 *   @0x1cb2b0 mov r3, r8
 *   @0x1cb2b4 bl 0x1cb234 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_>
 *   @0x1cb2b8 cmp r0, #0
 *   @0x1cb2bc beq 0x1cb34c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x118>
 *   @0x1cb2c0 ldr r5, [r7]
 *   @0x1cb2c4 add r10, r10, #1
 *   @0x1cb2c8 add r4, r4, #24
 *   @0x1cb2cc cmp r5, r10
 *   @0x1cb2d0 bgt 0x1cb284 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x50>
 *   @0x1cb2d4 mov r0, #1
 *   @0x1cb2d8 add sp, sp, #12
 *   @0x1cb2dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cb2e0 cmp r5, #0
 *   @0x1cb2e4 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0>
 *   @0x1cb2e8 ldr r3, [sp, #0x30]
 *   @0x1cb2ec add r4, r7, #8
 *   @0x1cb2f0 cmp r3, #0
 *   @0x1cb2f4 movne r11, #0
 *   @0x1cb2f8 beq 0x1cb358 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x124>
 *   @0x1cb2fc mov r1, r4
 *   @0x1cb300 mov r0, r6
 *   @0x1cb304 bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0>
 *   @0x1cb308 mov r1, r9
 *   @0x1cb30c cmp r0, #0
 *   @0x1cb310 beq 0x1cb338 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x104>
 *   @0x1cb314 ldr r3, [r8]
 *   @0x1cb318 ldr r0, [r4, #0x14]
 *   @0x1cb31c add r3, r3, #1
 *   @0x1cb320 str r3, [r8]
 *   @0x1cb324 ldr r3, [sp, #0x30]
 *   @0x1cb328 blx r3
 *   @0x1cb32c cmp r0, #0
 *   @0x1cb330 beq 0x1cb34c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x118>
 *   @0x1cb334 ldr r5, [r7]
 *   @0x1cb338 add r11, r11, #1
 *   @0x1cb33c add r4, r4, #24
 *   @0x1cb340 cmp r5, r11
 *   @0x1cb344 bgt 0x1cb2fc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xc8>
 *   @0x1cb348 b 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0>
 *   @0x1cb34c mov r0, #0
 *   @0x1cb350 add sp, sp, #12
 *   @0x1cb354 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cb358 mov r10, r3
 *   @0x1cb35c mov r1, r4
 *   @0x1cb360 mov r0, r6
 *   @0x1cb364 bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0>
 *   @0x1cb368 add r10, r10, #1
 *   @0x1cb36c add r4, r4, #24
 *   @0x1cb370 cmp r0, #0
 *   @0x1cb374 ldrne r3, [r8]
 *   @0x1cb378 addne r3, r3, #1
 *   @0x1cb37c strne r3, [r8]
 *   @0x1cb380 ldrne r5, [r7]
 *   @0x1cb384 cmp r10, r5
 *   @0x1cb388 blt 0x1cb35c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x128>
 *   @0x1cb38c b 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0>
 *
 * ══ §41/87 HighScore_InitLoad()  0x1dc600  size 348  87 条（0x1dc600..0x1dc75c）
 * @func 0x1dc600 0x1dc75c  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dc61c→0x3f51d8, 0x1dc674→0x544b18, 0x1dc6b0→0x544ab4
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::ReadSaveFile(char const*, int*) / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x-8×3 / 0x404×2 / 0x134×1 / 0x130×1 / 0x128×1 / 0xd4×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc600 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dc604 sub sp, sp, #1024
 *   @0x1dc608 ldr r11, [pc, #0x134]
 *   @0x1dc60c sub sp, sp, #12
 *   @0x1dc610 ldr r2, [pc, #0x130]
 *   @0x1dc614 add r5, sp, #4
 *   @0x1dc618 add r11, pc, r11
 *   @0x1dc61c ldr r3, [pc, #0x128]
 *   @0x1dc620 mov r1, #1024
 *   @0x1dc624 mov r0, r5
 *   @0x1dc628 ldr r7, [r11, r2]
 *   @0x1dc62c add r4, sp, #8
 *   @0x1dc630 mov r9, #0
 *   @0x1dc634 ldr r2, [r7]
 *   @0x1dc638 str r2, [sp, #0x404]
 *   @0x1dc63c ldr r3, [r11, r3]
 *   @0x1dc640 ldr r2, [r3]
 *   @0x1dc644 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1dc648 mov r0, r5
 *   @0x1dc64c sub r1, r4, #8
 *   @0x1dc650 str r9, [sp]
 *   @0x1dc654 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x1dc658 cmp r0, #0
 *   @0x1dc65c beq 0x1dc674 <_Z18HighScore_InitLoadv+0x74>
 *   @0x1dc660 ldr r2, [r0]
 *   @0x1dc664 movw r3, #0x4948
 *   @0x1dc668 movt r3, #0x4353
 *   @0x1dc66c cmp r2, r3
 *   @0x1dc670 beq 0x1dc6a0 <_Z18HighScore_InitLoadv+0xa0>
 *   @0x1dc674 ldr r3, [pc, #0xd4]
 *   @0x1dc678 mov r2, #0
 *   @0x1dc67c ldr r0, [sp, #0x404]
 *   @0x1dc680 ldr r1, [r7]
 *   @0x1dc684 ldr r3, [r11, r3]
 *   @0x1dc688 cmp r0, r1
 *   @0x1dc68c strb r2, [r3]
 *   @0x1dc690 bne 0x1dc740 <_Z18HighScore_InitLoadv+0x140>
 *   @0x1dc694 add sp, sp, #1024
 *   @0x1dc698 add sp, sp, #12
 *   @0x1dc69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dc6a0 ldr r2, [r0, #0x4]
 *   @0x1dc6a4 ldr r3, [sp]
 *   @0x1dc6a8 cmp r2, r3
 *   @0x1dc6ac bgt 0x1dc674 <_Z18HighScore_InitLoadv+0x74>
 *   @0x1dc6b0 ldr r3, [pc, #0x9c]
 *   @0x1dc6b4 add r5, r0, #8
 *   @0x1dc6b8 ldr r10, [pc, #0x98]
 *   @0x1dc6bc ldr r8, [r11, r3]
 *   @0x1dc6c0 add r10, pc, r10
 *   @0x1dc6c4 add r4, r8, #8
 *   @0x1dc6c8 add r8, r8, #88
 *   @0x1dc6cc b 0x1dc6e4 <_Z18HighScore_InitLoadv+0xe4>
 *   @0x1dc6d0 ldr r3, [r5], #4
 *   @0x1dc6d4 add r4, r4, #8
 *   @0x1dc6d8 str r3, [r4, #-0xc]
 *   @0x1dc6dc cmp r4, r8
 *   @0x1dc6e0 beq 0x1dc674 <_Z18HighScore_InitLoadv+0x74>
 *   @0x1dc6e4 ldr r0, [r4, #-0x8]
 *   @0x1dc6e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dc6ec ldr r6, [r5], #4
 *   @0x1dc6f0 cmp r6, #256
 *   @0x1dc6f4 bgt 0x1dc674 <_Z18HighScore_InitLoadv+0x74>
 *   @0x1dc6f8 cmp r6, #0
 *   @0x1dc6fc streq r6, [r4, #-0x8]
 *   @0x1dc700 beq 0x1dc6d0 <_Z18HighScore_InitLoadv+0xd0>
 *   @0x1dc704 mov r3, #1
 *   @0x1dc708 mov r1, r10
 *   @0x1dc70c movw r2, #0x24e
 *   @0x1dc710 add r0, r6, #1
 *   @0x1dc714 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dc718 mov r1, r5
 *   @0x1dc71c mov r2, r6
 *   @0x1dc720 str r0, [r4, #-0x8]
 *   @0x1dc724 bl 0xb65bc <memcpy@plt>
 *   @0x1dc728 ldr r3, [r4, #-0x8]
 *   @0x1dc72c add r2, r6, #3
 *   @0x1dc730 bic r2, r2, #3
 *   @0x1dc734 add r5, r5, r2
 *   @0x1dc738 strb r9, [r3, r6]
 *   @0x1dc73c b 0x1dc6d0 <_Z18HighScore_InitLoadv+0xd0>
 *   @0x1dc740 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dc744 eoreq r5, r1, r8, lsr r6
 *   @0x1dc748 .word 0xffffbd00
 *   @0x1dc74c .word 0xfffff048
 *   @0x1dc750 .word 0xfffff044
 *   @0x1dc754 .word 0xfffff03c
 *   @0x1dc758 andseq r4, r7, r4, lsr pc
 *
 * ══ §42/87 CDS_Grid::Disk_Operation(int, double, double, double, RValue*)  0x207e8c  size 348  87 条（0x207e8c..0x207fe8）
 * @func 0x207e8c 0x207fe8  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2 / CDS_Grid::Disk_Operation(int, double, double, double, RValue*)+0x148 / DoOperation(int, RValue*, RValue*)
 * 字段偏移 top8: 0x4×2 / 0x60×1 / 0x8×1
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207e8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x207e90 vpush {d8, d9, d10, d11, d12}
 *   @0x207e94 vmov d12, r2, r3
 *   @0x207e98 vldr d11, [sp, #88]
 *   @0x207e9c mov r7, r0
 *   @0x207ea0 mov r8, r1
 *   @0x207ea4 vsub.f64 d6, d12, d11
 *   @0x207ea8 vldr d10, [sp, #80]
 *   @0x207eac ldr r9, [sp, #0x60]
 *   @0x207eb0 vmov r0, r1, d6
 *   @0x207eb4 bl 0xb6598 <floor@plt>
 *   @0x207eb8 ldr r11, [r7, #0x4]
 *   @0x207ebc sub r11, r11, #1
 *   @0x207ec0 vmov d7, r0, r1
 *   @0x207ec4 vcmpe.f64 d7, #0
 *   @0x207ec8 vmrs APSR_nzcv, fpscr
 *   @0x207ecc vcvtpl.s32.f64 s13, d7
 *   @0x207ed0 movmi r6, #0
 *   @0x207ed4 vadd.f64 d7, d12, d11
 *   @0x207ed8 vmovpl r6, s13
 *   @0x207edc vmov r0, r1, d7
 *   @0x207ee0 bl 0xb670c <ceil@plt>
 *   @0x207ee4 vmov s11, r11
 *   @0x207ee8 vcvt.f64.s32 d6, s11
 *   @0x207eec vmov d7, r0, r1
 *   @0x207ef0 vcmpe.f64 d6, d7
 *   @0x207ef4 vmrs APSR_nzcv, fpscr
 *   @0x207ef8 vcvtpl.s32.f64 s12, d7
 *   @0x207efc vsub.f64 d7, d10, d11
 *   @0x207f00 vmovpl r11, s12
 *   @0x207f04 vmov r0, r1, d7
 *   @0x207f08 bl 0xb6598 <floor@plt>
 *   @0x207f0c ldr r5, [r7, #0x8]
 *   @0x207f10 vadd.f64 d6, d10, d11
 *   @0x207f14 sub r5, r5, #1
 *   @0x207f18 vmov d7, r0, r1
 *   @0x207f1c vcmpe.f64 d7, #0
 *   @0x207f20 vmov r0, r1, d6
 *   @0x207f24 vmrs APSR_nzcv, fpscr
 *   @0x207f28 vcvtpl.s32.f64 s11, d7
 *   @0x207f2c movmi r10, #0
 *   @0x207f30 vmovpl r10, s11
 *   @0x207f34 bl 0xb670c <ceil@plt>
 *   @0x207f38 vmov s11, r5
 *   @0x207f3c vcvt.f64.s32 d6, s11
 *   @0x207f40 vmov d7, r0, r1
 *   @0x207f44 vcmpe.f64 d6, d7
 *   @0x207f48 vmrs APSR_nzcv, fpscr
 *   @0x207f4c vcvtpl.s32.f64 s12, d7
 *   @0x207f50 vmovpl r5, s12
 *   @0x207f54 cmp r6, r11
 *   @0x207f58 bgt 0x207fe0 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x154>
 *   @0x207f5c cmp r10, r5
 *   @0x207f60 bgt 0x207fd4 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x148>
 *   @0x207f64 vmov s13, r6
 *   @0x207f68 mov r4, r10
 *   @0x207f6c vmul.f64 d9, d11, d11
 *   @0x207f70 vcvt.f64.s32 d8, s13
 *   @0x207f74 vsub.f64 d8, d8, d12
 *   @0x207f78 vmul.f64 d8, d8, d8
 *   @0x207f7c b 0x207f8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x100>
 *   @0x207f80 add r4, r4, #1
 *   @0x207f84 cmp r5, r4
 *   @0x207f88 blt 0x207fd4 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x148>
 *   @0x207f8c vmov s13, r4
 *   @0x207f90 vcvt.f64.s32 d7, s13
 *   @0x207f94 vsub.f64 d7, d7, d10
 *   @0x207f98 vmov.f64 d6, d8
 *   @0x207f9c vmla.f64 d6, d7, d7
 *   @0x207fa0 vcmpe.f64 d6, d9
 *   @0x207fa4 vmrs APSR_nzcv, fpscr
 *   @0x207fa8 bhi 0x207f80 <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0xf4>
 *   @0x207fac ldr r1, [r7, #0x4]
 *   @0x207fb0 mov r0, r8
 *   @0x207fb4 ldr r3, [r7]
 *   @0x207fb8 mov r2, r9
 *   @0x207fbc mla r1, r1, r4, r6
 *   @0x207fc0 add r4, r4, #1
 *   @0x207fc4 add r1, r3, r1, lsl #4
 *   @0x207fc8 bl 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x207fcc cmp r5, r4
 *   @0x207fd0 bge 0x207f8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0x100>
 *   @0x207fd4 add r6, r6, #1
 *   @0x207fd8 cmp r11, r6
 *   @0x207fdc bge 0x207f5c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue+0xd0>
 *   @0x207fe0 vpop {d8, d9, d10, d11, d12}
 *   @0x207fe4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §43/87 Audio_SetTrackPos(int, float)  0x2187ac  size 348  87 条（0x2187ac..0x218908）
 * @func 0x2187ac 0x218908  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SetTrackPos(int, float)+0x84×2 / Audio_GetSound(int)×2 / Audio_SetTrackPos(int, float)+0x8c / Audio_SetTrackPos(int, float)+0x118 / Audio_SoundLength(int) / Audio_GetNoiseFromID(int) / Audio_NoiseIsPlaying(CNoise*) / 0xb6a78
 * 字段偏移 top8: 0x10×2 / 0x34×2 / 0x12c×1 / 0x18×1 / 0x24×1 / 0x25×1 / 0x78×1 / 0x2×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2187ac push {r3, r4, r5, lr}
 *   @0x2187b0 vpush {d8}
 *   @0x2187b4 vmov s16, r1
 *   @0x2187b8 vldr s15, [pc, #300]
 *   @0x2187bc ldr r3, [pc, #0x12c]
 *   @0x2187c0 mov r4, r0
 *   @0x2187c4 vcmp.f32 s16, s15
 *   @0x2187c8 ldr r3, [pc, r3]
 *   @0x2187cc ldr r3, [r3]
 *   @0x2187d0 vmrs APSR_nzcv, fpscr
 *   @0x2187d4 vmovmi.f32 s16, s15
 *   @0x2187d8 cmp r3, r0
 *   @0x2187dc ble 0x218838 <_Z17Audio_SetTrackPosif+0x8c>
 *   @0x2187e0 sub r2, r0, #199680
 *   @0x2187e4 movw r3, #0x869f
 *   @0x2187e8 sub r2, r2, #320
 *   @0x2187ec movt r3, #0x1
 *   @0x2187f0 cmp r2, r3
 *   @0x2187f4 bls 0x2188c4 <_Z17Audio_SetTrackPosif+0x118>
 *   @0x2187f8 cmp r0, #0
 *   @0x2187fc blt 0x218830 <_Z17Audio_SetTrackPosif+0x84>
 *   @0x218800 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218804 subs r5, r0, #0
 *   @0x218808 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84>
 *   @0x21880c mov r0, r4
 *   @0x218810 bl 0x218640 <_Z17Audio_SoundLengthi>
 *   @0x218814 vcmpe.f32 s16, #0
 *   @0x218818 vmrs APSR_nzcv, fpscr
 *   @0x21881c vmov s15, r0
 *   @0x218820 blt 0x218830 <_Z17Audio_SetTrackPosif+0x84>
 *   @0x218824 vcmpe.f32 s16, s15
 *   @0x218828 vmrs APSR_nzcv, fpscr
 *   @0x21882c vstrmi s16, [r5, #72]
 *   @0x218830 vpop {d8}
 *   @0x218834 pop {r3, r4, r5, pc}
 *   @0x218838 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21883c subs r4, r0, #0
 *   @0x218840 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84>
 *   @0x218844 ldr r0, [r4, #0x18]
 *   @0x218848 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21884c ldrb r3, [r0, #0x24]
 *   @0x218850 cmp r3, #0
 *   @0x218854 bne 0x2188a8 <_Z17Audio_SetTrackPosif+0xfc>
 *   @0x218858 ldrb r3, [r0, #0x25]
 *   @0x21885c cmp r3, #0
 *   @0x218860 bne 0x2188a8 <_Z17Audio_SetTrackPosif+0xfc>
 *   @0x218864 mov r0, r4
 *   @0x218868 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise>
 *   @0x21886c cmp r0, #0
 *   @0x218870 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84>
 *   @0x218874 ldr r3, [pc, #0x78]
 *   @0x218878 movw r1, #0x1024
 *   @0x21887c ldr r0, [r4, #0x10]
 *   @0x218880 ldr r3, [pc, r3]
 *   @0x218884 vmov r2, s16
 *   @0x218888 ldr r3, [r3]
 *   @0x21888c ldr r0, [r3, r0, lsl #2]
 *   @0x218890 bl 0xb6a78 <alSourcef@plt>
 *   @0x218894 vpop {d8}
 *   @0x218898 ldr r0, [pc, #0x58]
 *   @0x21889c add r0, pc, r0
 *   @0x2188a0 pop {r3, r4, r5, lr}
 *   @0x2188a4 b 0x215fd0 <_Z7checkALPKc>
 *   @0x2188a8 vmov r2, s16
 *   @0x2188ac vpop {d8}
 *   @0x2188b0 ldr r0, [pc, #0x44]
 *   @0x2188b4 ldr r1, [r4, #0x10]
 *   @0x2188b8 add r0, pc, r0
 *   @0x2188bc pop {r3, r4, r5, lr}
 *   @0x2188c0 b 0x226434 <_ZN9COggAudio10Seek_SoundEif>
 *   @0x2188c4 ldr r3, [pc, #0x34]
 *   @0x2188c8 ldr r1, [pc, #0x34]
 *   @0x2188cc ldr r3, [pc, r3]
 *   @0x2188d0 add r1, pc, r1
 *   @0x2188d4 ldr r0, [r3]
 *   @0x2188d8 ldr r3, [r0]
 *   @0x2188dc ldr r3, [r3, #0xc]
 *   @0x2188e0 blx r3
 *   @0x2188e4 vpop {d8}
 *   @0x2188e8 pop {r3, r4, r5, pc}
 *   @0x2188ec andeq r0, r0, r0
 *   @0x2188f0 andseq r8, sp, r12, lsl r12
 *   @0x2188f4 andseq r8, sp, r12, asr #22
 *   @0x2188f8 andseq r11, r3, r12, lsl r4
 *   @0x2188fc ldrsbeq r12, [r3], #-156
 *   @0x218900 andseq r4, sp, r8, asr #28
 *   @0x218904 andseq r11, r3, r4, lsl #8
 *
 * ══ §44/87 JS_Date_toISOString(RValue&, CInstance*, CInstance*, int, RValue*)  0x2549a8  size 348  87 条（0x2549a8..0x254b04）
 * @func 0x2549a8 0x254b04  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::FindValue(char const*) / YearFromTime(double) / MonthFromTime(double) / DateFromTime(double) / HourFromTime(double) / MinFromTime(double) / SecFromTime(double) / msFromTime(double)
 * 字段偏移 top8: 0x41c×2 / 0x138×1 / 0x130×1 / 0x4×1 / 0x94×1 / 0x18×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2549a8 push {r4, r5, r6, r7, lr}
 *   @0x2549ac vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2549b0 mov r7, r0
 *   @0x2549b4 ldr r6, [pc, #0x138]
 *   @0x2549b8 mov r0, r1
 *   @0x2549bc sub sp, sp, #1056
 *   @0x2549c0 ldr r1, [pc, #0x130]
 *   @0x2549c4 ldr r6, [pc, r6]
 *   @0x2549c8 sub sp, sp, #4
 *   @0x2549cc add r1, pc, r1
 *   @0x2549d0 ldr r3, [r6]
 *   @0x2549d4 str r3, [sp, #0x41c]
 *   @0x2549d8 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x2549dc cmp r0, #0
 *   @0x2549e0 beq 0x254ae0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x2549e4 ldr r4, [r0, #0x4]
 *   @0x2549e8 ldr r5, [r0]
 *   @0x2549ec mov r1, r4
 *   @0x2549f0 mov r0, r5
 *   @0x2549f4 bl 0x244b90 <_Z12YearFromTimed>
 *   @0x2549f8 vmov d13, r0, r1
 *   @0x2549fc mov r1, r4
 *   @0x254a00 mov r0, r5
 *   @0x254a04 bl 0x244c68 <_Z13MonthFromTimed>
 *   @0x254a08 vmov d12, r0, r1
 *   @0x254a0c mov r1, r4
 *   @0x254a10 mov r0, r5
 *   @0x254a14 bl 0x244f60 <_Z12DateFromTimed>
 *   @0x254a18 vmov d11, r0, r1
 *   @0x254a1c mov r1, r4
 *   @0x254a20 mov r0, r5
 *   @0x254a24 bl 0x245120 <_Z12HourFromTimed>
 *   @0x254a28 vmov d10, r0, r1
 *   @0x254a2c mov r1, r4
 *   @0x254a30 mov r0, r5
 *   @0x254a34 bl 0x245158 <_Z11MinFromTimed>
 *   @0x254a38 vmov d9, r0, r1
 *   @0x254a3c mov r1, r4
 *   @0x254a40 mov r0, r5
 *   @0x254a44 bl 0x245190 <_Z11SecFromTimed>
 *   @0x254a48 vmov d8, r0, r1
 *   @0x254a4c mov r1, r4
 *   @0x254a50 mov r0, r5
 *   @0x254a54 add r4, sp, #28
 *   @0x254a58 bl 0x2451c8 <_Z10msFromTimed>
 *   @0x254a5c vcvt.s32.f64 s14, d12
 *   @0x254a60 ldr r2, [pc, #0x94]
 *   @0x254a64 add r2, pc, r2
 *   @0x254a68 vmov r3, s14
 *   @0x254a6c vcvt.s32.f64 s22, d11
 *   @0x254a70 vcvt.s32.f64 s20, d10
 *   @0x254a74 vstr s22, [sp, #4]
 *   @0x254a78 vcvt.s32.f64 s18, d9
 *   @0x254a7c vstr s20, [sp, #8]
 *   @0x254a80 add r3, r3, #1
 *   @0x254a84 str r3, [sp]
 *   @0x254a88 vcvt.s32.f64 s16, d8
 *   @0x254a8c vstr s18, [sp, #12]
 *   @0x254a90 vmov d7, r0, r1
 *   @0x254a94 mov r1, #1024
 *   @0x254a98 mov r0, r4
 *   @0x254a9c vcvt.s32.f64 s15, d7
 *   @0x254aa0 vstr s16, [sp, #16]
 *   @0x254aa4 vcvt.s32.f64 s14, d13
 *   @0x254aa8 vstr s15, [sp, #20]
 *   @0x254aac vmov r3, s14
 *   @0x254ab0 bl 0xb65c8 <snprintf@plt>
 *   @0x254ab4 mov r0, r7
 *   @0x254ab8 mov r1, r4
 *   @0x254abc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x254ac0 ldr r2, [sp, #0x41c]
 *   @0x254ac4 ldr r3, [r6]
 *   @0x254ac8 cmp r2, r3
 *   @0x254acc bne 0x254af0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x254ad0 add sp, sp, #1056
 *   @0x254ad4 add sp, sp, #4
 *   @0x254ad8 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x254adc pop {r4, r5, r6, r7, pc}
 *   @0x254ae0 ldr r0, [pc, #0x18]
 *   @0x254ae4 add r0, pc, r0
 *   @0x254ae8 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x254aec b 0x254ac0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x254af0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x254af4 andseq r8, r9, r12, lsl #31
 *   @0x254af8 andseq r0, r0, r4, asr #22
 *   @0x254afc andseq r1, r0, r8, ror r12
 *   @0x254b00 andseq r1, r0, r4, ror #8
 *
 * ══ §45/87 _spTranslateTimeline_apply  0x281c18  size 348  87 条（0x281c18..0x281d74）
 * @func 0x281c18 0x281d88  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spTranslateTimeline_apply+0x94 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281c18 push {r3, r4, r5, r6, r7, lr}
 *   @0x281c1c vpush {d8, d9}
 *   @0x281c20 vmov s16, r3
 *   @0x281c24 vldr s17, [sp, #48]
 *   @0x281c28 ldr r6, [r0, #0x10]
 *   @0x281c2c vldr s15, [r6]
 *   @0x281c30 vcmpe.f32 s15, s16
 *   @0x281c34 mov r4, r0
 *   @0x281c38 vmrs APSR_nzcv, fpscr
 *   @0x281c3c bgt 0x281ca4 <_spTranslateTimeline_apply+0x8c>
 *   @0x281c40 ldr r2, [r0, #0xc]
 *   @0x281c44 ldr r1, [r1, #0x8]
 *   @0x281c48 sub r3, r2, #3
 *   @0x281c4c ldr r0, [r0, #0x14]
 *   @0x281c50 add r3, r6, r3, lsl #2
 *   @0x281c54 vldr s15, [r3]
 *   @0x281c58 vcmpe.f32 s16, s15
 *   @0x281c5c ldr r5, [r1, r0, lsl #2]
 *   @0x281c60 vmrs APSR_nzcv, fpscr
 *   @0x281c64 blt 0x281cac <_spTranslateTimeline_apply+0x94>
 *   @0x281c68 vldr s15, [r3, #4]
 *   @0x281c6c ldr r2, [r5]
 *   @0x281c70 vldr s12, [r2, #16]
 *   @0x281c74 vadd.f32 s12, s12, s15
 *   @0x281c78 vldr s14, [r5, #20]
 *   @0x281c7c vldr s13, [r2, #20]
 *   @0x281c80 vldr s15, [r5, #24]
 *   @0x281c84 vsub.f32 s12, s12, s14
 *   @0x281c88 vmla.f32 s14, s12, s17
 *   @0x281c8c vstr s14, [r5, #20]
 *   @0x281c90 vldr s14, [r3, #8]
 *   @0x281c94 vadd.f32 s14, s13, s14
 *   @0x281c98 vsub.f32 s14, s14, s15
 *   @0x281c9c vmla.f32 s15, s14, s17
 *   @0x281ca0 vstr s15, [r5, #24]
 *   @0x281ca4 vpop {d8, d9}
 *   @0x281ca8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x281cac mov r1, r2
 *   @0x281cb0 vmov.f32 s0, s16
 *   @0x281cb4 mov r0, r6
 *   @0x281cb8 mov r2, #3
 *   @0x281cbc bl 0x280ed0 <printbuf_free+0x20>
 *   @0x281cc0 movw r2, #0x5556
 *   @0x281cc4 movt r2, #0x5555
 *   @0x281cc8 vmov.f32 s14, #1.000000e+00
 *   @0x281ccc sub r7, r0, #2
 *   @0x281cd0 mov r3, r0
 *   @0x281cd4 smull r1, r2, r2, r3
 *   @0x281cd8 lsl r7, r7, #2
 *   @0x281cdc add r6, r6, r7
 *   @0x281ce0 vldr s15, [r6, #8]
 *   @0x281ce4 vldr s13, [r6, #-4]
 *   @0x281ce8 vsub.f32 s16, s16, s15
 *   @0x281cec mov r0, r4
 *   @0x281cf0 vldr s19, [r6]
 *   @0x281cf4 vldr s18, [r6, #4]
 *   @0x281cf8 sub r1, r2, r3, asr #31
 *   @0x281cfc sub r1, r1, #1
 *   @0x281d00 vsub.f32 s15, s13, s15
 *   @0x281d04 vdiv.f32 s15, s16, s15
 *   @0x281d08 vsub.f32 s14, s14, s15
 *   @0x281d0c vmov r2, s14
 *   @0x281d10 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x281d14 ldr r2, [r4, #0x10]
 *   @0x281d18 ldr r3, [r5]
 *   @0x281d1c vldr s14, [r3, #16]
 *   @0x281d20 add r7, r2, r7
 *   @0x281d24 vadd.f32 s14, s19, s14
 *   @0x281d28 vldr s10, [r7, #12]
 *   @0x281d2c vldr s11, [r5, #20]
 *   @0x281d30 vldr s15, [r3, #20]
 *   @0x281d34 vldr s13, [r5, #24]
 *   @0x281d38 vsub.f32 s19, s10, s19
 *   @0x281d3c vadd.f32 s15, s18, s15
 *   @0x281d40 vmov s12, r0
 *   @0x281d44 vmla.f32 s14, s19, s12
 *   @0x281d48 vsub.f32 s14, s14, s11
 *   @0x281d4c vmla.f32 s11, s14, s17
 *   @0x281d50 vstr s11, [r5, #20]
 *   @0x281d54 vldr s14, [r7, #16]
 *   @0x281d58 vsub.f32 s18, s14, s18
 *   @0x281d5c vmla.f32 s15, s18, s12
 *   @0x281d60 vsub.f32 s15, s15, s13
 *   @0x281d64 vmla.f32 s13, s15, s17
 *   @0x281d68 vpop {d8, d9}
 *   @0x281d6c vstr s13, [r5, #24]
 *   @0x281d70 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §46/87 _spScaleTimeline_apply  0x281d74  size 348  87 条（0x281d74..0x281ed0）
 * @func 0x281d74 0x281ee4  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spScaleTimeline_apply+0x94 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281d74 push {r3, r4, r5, r6, r7, lr}
 *   @0x281d78 vpush {d8, d9}
 *   @0x281d7c vmov s16, r3
 *   @0x281d80 vldr s17, [sp, #48]
 *   @0x281d84 ldr r6, [r0, #0x10]
 *   @0x281d88 vldr s15, [r6]
 *   @0x281d8c vcmpe.f32 s15, s16
 *   @0x281d90 mov r4, r0
 *   @0x281d94 vmrs APSR_nzcv, fpscr
 *   @0x281d98 bgt 0x281e00 <_spScaleTimeline_apply+0x8c>
 *   @0x281d9c ldr r2, [r0, #0xc]
 *   @0x281da0 ldr r1, [r1, #0x8]
 *   @0x281da4 sub r3, r2, #3
 *   @0x281da8 ldr r0, [r0, #0x14]
 *   @0x281dac add r3, r6, r3, lsl #2
 *   @0x281db0 vldr s15, [r3]
 *   @0x281db4 vcmpe.f32 s16, s15
 *   @0x281db8 ldr r5, [r1, r0, lsl #2]
 *   @0x281dbc vmrs APSR_nzcv, fpscr
 *   @0x281dc0 blt 0x281e08 <_spScaleTimeline_apply+0x94>
 *   @0x281dc4 vldr s14, [r5, #32]
 *   @0x281dc8 vmov.f32 s12, s14
 *   @0x281dcc vldr s15, [r3, #4]
 *   @0x281dd0 ldr r2, [r5]
 *   @0x281dd4 vldr s13, [r2, #28]
 *   @0x281dd8 vnmls.f32 s12, s13, s15
 *   @0x281ddc vldr s15, [r5, #36]
 *   @0x281de0 vldr s13, [r2, #32]
 *   @0x281de4 vmla.f32 s14, s12, s17
 *   @0x281de8 vmov.f32 s10, s15
 *   @0x281dec vstr s14, [r5, #32]
 *   @0x281df0 vldr s14, [r3, #8]
 *   @0x281df4 vnmls.f32 s10, s13, s14
 *   @0x281df8 vmla.f32 s15, s10, s17
 *   @0x281dfc vstr s15, [r5, #36]
 *   @0x281e00 vpop {d8, d9}
 *   @0x281e04 pop {r3, r4, r5, r6, r7, pc}
 *   @0x281e08 mov r1, r2
 *   @0x281e0c vmov.f32 s0, s16
 *   @0x281e10 mov r0, r6
 *   @0x281e14 mov r2, #3
 *   @0x281e18 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x281e1c movw r2, #0x5556
 *   @0x281e20 movt r2, #0x5555
 *   @0x281e24 vmov.f32 s14, #1.000000e+00
 *   @0x281e28 sub r7, r0, #2
 *   @0x281e2c mov r3, r0
 *   @0x281e30 smull r1, r2, r2, r3
 *   @0x281e34 lsl r7, r7, #2
 *   @0x281e38 add r6, r6, r7
 *   @0x281e3c vldr s15, [r6, #8]
 *   @0x281e40 vldr s13, [r6, #-4]
 *   @0x281e44 vsub.f32 s16, s16, s15
 *   @0x281e48 mov r0, r4
 *   @0x281e4c vldr s19, [r6]
 *   @0x281e50 vldr s18, [r6, #4]
 *   @0x281e54 sub r1, r2, r3, asr #31
 *   @0x281e58 sub r1, r1, #1
 *   @0x281e5c vsub.f32 s15, s13, s15
 *   @0x281e60 vdiv.f32 s15, s16, s15
 *   @0x281e64 vsub.f32 s14, s14, s15
 *   @0x281e68 vmov r2, s14
 *   @0x281e6c bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x281e70 ldr r2, [r4, #0x10]
 *   @0x281e74 vldr s13, [r5, #32]
 *   @0x281e78 ldr r3, [r5]
 *   @0x281e7c add r7, r2, r7
 *   @0x281e80 vldr s10, [r7, #12]
 *   @0x281e84 vsub.f32 s10, s10, s19
 *   @0x281e88 vldr s11, [r3, #28]
 *   @0x281e8c vldr s12, [r3, #32]
 *   @0x281e90 vldr s15, [r5, #36]
 *   @0x281e94 vmov s14, r0
 *   @0x281e98 vmla.f32 s19, s10, s14
 *   @0x281e9c vmov.f32 s10, s13
 *   @0x281ea0 vnmls.f32 s10, s19, s11
 *   @0x281ea4 vmla.f32 s13, s10, s17
 *   @0x281ea8 vstr s13, [r5, #32]
 *   @0x281eac vldr s13, [r7, #16]
 *   @0x281eb0 vsub.f32 s13, s13, s18
 *   @0x281eb4 vmla.f32 s18, s13, s14
 *   @0x281eb8 vmov.f32 s14, s15
 *   @0x281ebc vnmls.f32 s14, s18, s12
 *   @0x281ec0 vmla.f32 s15, s14, s17
 *   @0x281ec4 vpop {d8, d9}
 *   @0x281ec8 vstr s15, [r5, #36]
 *   @0x281ecc pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §47/87 _spShearTimeline_apply  0x281ed0  size 348  87 条（0x281ed0..0x28202c）
 * @func 0x281ed0 0x28202c  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spShearTimeline_apply+0x94 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281ed0 push {r3, r4, r5, r6, r7, lr}
 *   @0x281ed4 vpush {d8, d9}
 *   @0x281ed8 vmov s16, r3
 *   @0x281edc vldr s17, [sp, #48]
 *   @0x281ee0 ldr r6, [r0, #0x10]
 *   @0x281ee4 vldr s15, [r6]
 *   @0x281ee8 vcmpe.f32 s15, s16
 *   @0x281eec mov r4, r0
 *   @0x281ef0 vmrs APSR_nzcv, fpscr
 *   @0x281ef4 bgt 0x281f5c <_spShearTimeline_apply+0x8c>
 *   @0x281ef8 ldr r2, [r0, #0xc]
 *   @0x281efc ldr r1, [r1, #0x8]
 *   @0x281f00 sub r3, r2, #3
 *   @0x281f04 ldr r0, [r0, #0x14]
 *   @0x281f08 add r3, r6, r3, lsl #2
 *   @0x281f0c vldr s15, [r3]
 *   @0x281f10 vcmpe.f32 s16, s15
 *   @0x281f14 ldr r5, [r1, r0, lsl #2]
 *   @0x281f18 vmrs APSR_nzcv, fpscr
 *   @0x281f1c blt 0x281f64 <_spShearTimeline_apply+0x94>
 *   @0x281f20 vldr s15, [r3, #4]
 *   @0x281f24 ldr r2, [r5]
 *   @0x281f28 vldr s12, [r2, #36]
 *   @0x281f2c vadd.f32 s12, s12, s15
 *   @0x281f30 vldr s14, [r5, #40]
 *   @0x281f34 vldr s13, [r2, #40]
 *   @0x281f38 vldr s15, [r5, #44]
 *   @0x281f3c vsub.f32 s12, s12, s14
 *   @0x281f40 vmla.f32 s14, s12, s17
 *   @0x281f44 vstr s14, [r5, #40]
 *   @0x281f48 vldr s14, [r3, #8]
 *   @0x281f4c vadd.f32 s14, s13, s14
 *   @0x281f50 vsub.f32 s14, s14, s15
 *   @0x281f54 vmla.f32 s15, s14, s17
 *   @0x281f58 vstr s15, [r5, #44]
 *   @0x281f5c vpop {d8, d9}
 *   @0x281f60 pop {r3, r4, r5, r6, r7, pc}
 *   @0x281f64 mov r1, r2
 *   @0x281f68 vmov.f32 s0, s16
 *   @0x281f6c mov r0, r6
 *   @0x281f70 mov r2, #3
 *   @0x281f74 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x281f78 movw r2, #0x5556
 *   @0x281f7c movt r2, #0x5555
 *   @0x281f80 vmov.f32 s14, #1.000000e+00
 *   @0x281f84 sub r7, r0, #2
 *   @0x281f88 mov r3, r0
 *   @0x281f8c smull r1, r2, r2, r3
 *   @0x281f90 lsl r7, r7, #2
 *   @0x281f94 add r6, r6, r7
 *   @0x281f98 vldr s15, [r6, #8]
 *   @0x281f9c vldr s13, [r6, #-4]
 *   @0x281fa0 vsub.f32 s16, s16, s15
 *   @0x281fa4 mov r0, r4
 *   @0x281fa8 vldr s19, [r6]
 *   @0x281fac vldr s18, [r6, #4]
 *   @0x281fb0 sub r1, r2, r3, asr #31
 *   @0x281fb4 sub r1, r1, #1
 *   @0x281fb8 vsub.f32 s15, s13, s15
 *   @0x281fbc vdiv.f32 s15, s16, s15
 *   @0x281fc0 vsub.f32 s14, s14, s15
 *   @0x281fc4 vmov r2, s14
 *   @0x281fc8 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x281fcc ldr r2, [r4, #0x10]
 *   @0x281fd0 ldr r3, [r5]
 *   @0x281fd4 vldr s14, [r3, #36]
 *   @0x281fd8 add r7, r2, r7
 *   @0x281fdc vadd.f32 s14, s19, s14
 *   @0x281fe0 vldr s10, [r7, #12]
 *   @0x281fe4 vldr s11, [r5, #40]
 *   @0x281fe8 vldr s15, [r3, #40]
 *   @0x281fec vldr s13, [r5, #44]
 *   @0x281ff0 vsub.f32 s19, s10, s19
 *   @0x281ff4 vadd.f32 s15, s18, s15
 *   @0x281ff8 vmov s12, r0
 *   @0x281ffc vmla.f32 s14, s19, s12
 *   @0x282000 vsub.f32 s14, s14, s11
 *   @0x282004 vmla.f32 s11, s14, s17
 *   @0x282008 vstr s11, [r5, #40]
 *   @0x28200c vldr s14, [r7, #16]
 *   @0x282010 vsub.f32 s18, s14, s18
 *   @0x282014 vmla.f32 s15, s18, s12
 *   @0x282018 vsub.f32 s15, s15, s13
 *   @0x28201c vmla.f32 s13, s15, s17
 *   @0x282020 vpop {d8, d9}
 *   @0x282024 vstr s13, [r5, #44]
 *   @0x282028 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §48/87 jpeg_resync_to_restart  0x2b5da0  size 348  87 条（0x2b5da0..0x2b5efc）
 * @func 0x2b5da0 0x2b5efc  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_resync_to_restart+0x114 / anon_2b3f58+0x788
 * 字段偏移 top8: 0x18×4 / 0x14×4 / 0x1c×4 / 0x4×4 / 0x17c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b5da0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2b5da4 mov r12, #121
 *   @0x2b5da8 ldr r3, [r0]
 *   @0x2b5dac mov r6, r1
 *   @0x2b5db0 ldr r5, [r0, #0x17c]
 *   @0x2b5db4 mvn r1, #0
 *   @0x2b5db8 mov r4, r0
 *   @0x2b5dbc add r7, r6, #1
 *   @0x2b5dc0 add r8, r6, #2
 *   @0x2b5dc4 and r7, r7, #7
 *   @0x2b5dc8 str r5, [r3, #0x18]
 *   @0x2b5dcc and r8, r8, #7
 *   @0x2b5dd0 ldr r2, [r0]
 *   @0x2b5dd4 add r7, r7, #208
 *   @0x2b5dd8 str r12, [r3, #0x14]
 *   @0x2b5ddc add r8, r8, #208
 *   @0x2b5de0 str r6, [r2, #0x1c]
 *   @0x2b5de4 ldr r3, [r0]
 *   @0x2b5de8 ldr r3, [r3, #0x4]
 *   @0x2b5dec blx r3
 *   @0x2b5df0 cmp r5, #191
 *   @0x2b5df4 sub r3, r5, #208
 *   @0x2b5df8 ble 0x2b5eb4 <jpeg_resync_to_restart+0x114>
 *   @0x2b5dfc cmp r3, #7
 *   @0x2b5e00 bhi 0x2b5e7c <jpeg_resync_to_restart+0xdc>
 *   @0x2b5e04 sub r3, r6, #1
 *   @0x2b5e08 cmp r7, r5
 *   @0x2b5e0c and r3, r3, #7
 *   @0x2b5e10 add r3, r3, #208
 *   @0x2b5e14 beq 0x2b5e7c <jpeg_resync_to_restart+0xdc>
 *   @0x2b5e18 sub r2, r6, #2
 *   @0x2b5e1c cmp r8, r5
 *   @0x2b5e20 and r2, r2, #7
 *   @0x2b5e24 add r2, r2, #208
 *   @0x2b5e28 beq 0x2b5e7c <jpeg_resync_to_restart+0xdc>
 *   @0x2b5e2c cmp r3, r5
 *   @0x2b5e30 beq 0x2b5eb4 <jpeg_resync_to_restart+0x114>
 *   @0x2b5e34 cmp r2, r5
 *   @0x2b5e38 beq 0x2b5eb4 <jpeg_resync_to_restart+0x114>
 *   @0x2b5e3c ldr r3, [r4]
 *   @0x2b5e40 mov r12, #97
 *   @0x2b5e44 mov r6, #1
 *   @0x2b5e48 mov r0, r4
 *   @0x2b5e4c mov r1, #4
 *   @0x2b5e50 str r5, [r3, #0x18]
 *   @0x2b5e54 ldr r2, [r4]
 *   @0x2b5e58 str r12, [r3, #0x14]
 *   @0x2b5e5c str r6, [r2, #0x1c]
 *   @0x2b5e60 ldr r3, [r4]
 *   @0x2b5e64 ldr r3, [r3, #0x4]
 *   @0x2b5e68 blx r3
 *   @0x2b5e6c mov r3, #0
 *   @0x2b5e70 mov r0, r6
 *   @0x2b5e74 str r3, [r4, #0x17c]
 *   @0x2b5e78 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b5e7c ldr r3, [r4]
 *   @0x2b5e80 mov lr, #97
 *   @0x2b5e84 mov r12, #3
 *   @0x2b5e88 mov r0, r4
 *   @0x2b5e8c mov r1, #4
 *   @0x2b5e90 str r5, [r3, #0x18]
 *   @0x2b5e94 ldr r2, [r4]
 *   @0x2b5e98 str lr, [r3, #0x14]
 *   @0x2b5e9c str r12, [r2, #0x1c]
 *   @0x2b5ea0 ldr r3, [r4]
 *   @0x2b5ea4 ldr r3, [r3, #0x4]
 *   @0x2b5ea8 blx r3
 *   @0x2b5eac mov r0, #1
 *   @0x2b5eb0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b5eb4 ldr r3, [r4]
 *   @0x2b5eb8 mov lr, #97
 *   @0x2b5ebc mov r12, #2
 *   @0x2b5ec0 mov r0, r4
 *   @0x2b5ec4 mov r1, #4
 *   @0x2b5ec8 str r5, [r3, #0x18]
 *   @0x2b5ecc ldr r2, [r4]
 *   @0x2b5ed0 str lr, [r3, #0x14]
 *   @0x2b5ed4 str r12, [r2, #0x1c]
 *   @0x2b5ed8 ldr r3, [r4]
 *   @0x2b5edc ldr r3, [r3, #0x4]
 *   @0x2b5ee0 blx r3
 *   @0x2b5ee4 mov r0, r4
 *   @0x2b5ee8 bl 0x2b46e0 <jinit_input_controller+0x800>
 *   @0x2b5eec cmp r0, #0
 *   @0x2b5ef0 ldrne r5, [r4, #0x17c]
 *   @0x2b5ef4 bne 0x2b5df0 <jpeg_resync_to_restart+0x50>
 *   @0x2b5ef8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §49/87 F_FilenamePath(RValue&, CInstance*, CInstance*, int, RValue*)  0x139f00  size 344  86 条（0x139f00..0x13a058）
 * @func 0x139f00 0x13a058  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExtractFilePath(char const*)×2 / 0xb6538×2 / YYGetString(RValue const*, int) / F_FilenamePath(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6568 / MemoryManager::Free(void const*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x404×2 / 0x13c×1 / 0x420×1 / 0xc×1 / 0xe8×1 / 0x1×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139f00 push {r4, r5, r6, r7, r8, lr}
 *   @0x139f04 sub sp, sp, #1024
 *   @0x139f08 ldr r4, [pc, #0x13c]
 *   @0x139f0c sub sp, sp, #8
 *   @0x139f10 mov r5, r0
 *   @0x139f14 mov r1, #0
 *   @0x139f18 ldr r4, [pc, r4]
 *   @0x139f1c ldr r0, [sp, #0x420]
 *   @0x139f20 ldr r3, [r4]
 *   @0x139f24 str r3, [sp, #0x404]
 *   @0x139f28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139f2c mov r3, #0
 *   @0x139f30 mov r1, #1
 *   @0x139f34 str r3, [r5]
 *   @0x139f38 str r1, [r5, #0xc]
 *   @0x139f3c subs r8, r0, #0
 *   @0x139f40 beq 0x13a038 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x139f44 bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x139f48 mov r7, r0
 *   @0x139f4c bl 0xb6538 <strlen@plt>
 *   @0x139f50 subs r6, r0, #0
 *   @0x139f54 beq 0x139fcc <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x139f58 cmp r6, #0
 *   @0x139f5c ble 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x139f60 ldr r1, [pc, #0xe8]
 *   @0x139f64 mov r3, #1
 *   @0x139f68 movw r2, #0x64e
 *   @0x139f6c add r0, r6, #2
 *   @0x139f70 add r1, pc, r1
 *   @0x139f74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x139f78 mov r1, r7
 *   @0x139f7c mov r2, r6
 *   @0x139f80 mov r8, r0
 *   @0x139f84 bl 0xb6568 <strncpy@plt>
 *   @0x139f88 mov r3, r8
 *   @0x139f8c mov r1, #47
 *   @0x139f90 mov r0, r7
 *   @0x139f94 strb r1, [r3, r6]!
 *   @0x139f98 mov r2, #0
 *   @0x139f9c strb r2, [r3, #0x1]
 *   @0x139fa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x139fa4 mov r0, r5
 *   @0x139fa8 mov r1, r8
 *   @0x139fac bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x139fb0 ldr r2, [sp, #0x404]
 *   @0x139fb4 ldr r3, [r4]
 *   @0x139fb8 cmp r2, r3
 *   @0x139fbc bne 0x13a048 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x139fc0 add sp, sp, #1024
 *   @0x139fc4 add sp, sp, #8
 *   @0x139fc8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x139fcc mov r0, r7
 *   @0x139fd0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x139fd4 mov r0, r8
 *   @0x139fd8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x139fdc cmp r0, #0
 *   @0x139fe0 beq 0x13a010 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x139fe4 add r6, sp, #4
 *   @0x139fe8 mov r2, r8
 *   @0x139fec mov r1, #1024
 *   @0x139ff0 mov r0, r6
 *   @0x139ff4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x139ff8 mov r0, r6
 *   @0x139ffc bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x13a000 mov r7, r0
 *   @0x13a004 bl 0xb6538 <strlen@plt>
 *   @0x13a008 mov r6, r0
 *   @0x13a00c b 0x139f58 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13a010 mov r0, r8
 *   @0x13a014 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x13a018 cmp r0, #0
 *   @0x13a01c beq 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x13a020 add r6, sp, #4
 *   @0x13a024 mov r2, r8
 *   @0x13a028 mov r1, #1024
 *   @0x13a02c mov r0, r6
 *   @0x13a030 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x13a034 b 0x139ff8 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x13a038 ldr r0, [pc, #0x14]
 *   @0x13a03c add r0, pc, r0
 *   @0x13a040 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a044 b 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x13a048 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13a04c eoreq r3, r11, r8, lsr r10
 *   @0x13a050 eoreq r6, r0, r0, ror #1
 *   @0x13a054 eoreq r6, r0, r8, lsl #4
 *
 * ══ §50/87 YYGML_action_create_object_motion(CInstance*, int, float, float, float, float)  0x1418bc  size 344  86 条（0x1418bc..0x141a14）
 * @func 0x1418bc 0x141a14  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x141900→0x47a174, 0x141914→0x54298c, 0x1419a4→0x54298c
 * 调用序列: CRoom::AddInstance(float, float, int)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / Object_Exists(int) / CInstance::SetSpeed(float) / CInstance::SetDirection(float) / 0xb65c8 / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x12c×2 / 0x104×2 / 0x130×1 / 0x100×1 / 0xf0×1 / 0x128×1 / 0x6c×1 / 0x60×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1418bc push {r4, r5, r6, r7, r8, lr}
 *   @0x1418c0 vpush {d8}
 *   @0x1418c4 mov r6, r1
 *   @0x1418c8 ldr r4, [pc, #0x130]
 *   @0x1418cc vmov s16, r3
 *   @0x1418d0 ldr r1, [pc, #0x12c]
 *   @0x1418d4 sub sp, sp, #264
 *   @0x1418d8 add r4, pc, r4
 *   @0x1418dc mov r7, r0
 *   @0x1418e0 mov r0, r6
 *   @0x1418e4 vmov s17, r2
 *   @0x1418e8 ldr r5, [r4, r1]
 *   @0x1418ec ldr r3, [r5]
 *   @0x1418f0 str r3, [sp, #0x104]
 *   @0x1418f4 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x1418f8 subs r8, r0, #0
 *   @0x1418fc beq 0x1419cc <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x110>
 *   @0x141900 ldr r3, [pc, #0x100]
 *   @0x141904 ldr r3, [r4, r3]
 *   @0x141908 ldrb r3, [r3]
 *   @0x14190c cmp r3, #0
 *   @0x141910 bne 0x141998 <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0xdc>
 *   @0x141914 ldr r0, [pc, #0xf0]
 *   @0x141918 mov r3, r6
 *   @0x14191c vmov r1, s17
 *   @0x141920 vmov r2, s16
 *   @0x141924 ldr r0, [r4, r0]
 *   @0x141928 ldr r0, [r0]
 *   @0x14192c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x141930 mov r4, r0
 *   @0x141934 mov r0, r4
 *   @0x141938 ldr r1, [sp, #0x128]
 *   @0x14193c bl 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x141940 mov r0, r4
 *   @0x141944 ldr r1, [sp, #0x12c]
 *   @0x141948 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x14194c mov r0, r4
 *   @0x141950 mov r1, r4
 *   @0x141954 mov r2, #14
 *   @0x141958 mov r3, #0
 *   @0x14195c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x141960 mov r2, #0
 *   @0x141964 mov r3, r2
 *   @0x141968 mov r0, r4
 *   @0x14196c mov r1, r4
 *   @0x141970 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x141974 mov r3, #1
 *   @0x141978 strb r3, [r4, #0x6c]
 *   @0x14197c ldr r2, [sp, #0x104]
 *   @0x141980 ldr r3, [r5]
 *   @0x141984 cmp r2, r3
 *   @0x141988 bne 0x1419fc <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x140>
 *   @0x14198c add sp, sp, #264
 *   @0x141990 vpop {d8}
 *   @0x141994 pop {r4, r5, r6, r7, r8, pc}
 *   @0x141998 vldr s14, [r7, #180]
 *   @0x14199c vldr s15, [r7, #184]
 *   @0x1419a0 vadd.f32 s14, s17, s14
 *   @0x1419a4 ldr r2, [pc, #0x60]
 *   @0x1419a8 mov r3, r6
 *   @0x1419ac ldr r2, [r4, r2]
 *   @0x1419b0 ldr r0, [r2]
 *   @0x1419b4 vadd.f32 s15, s16, s15
 *   @0x1419b8 vmov r1, s14
 *   @0x1419bc vmov r2, s15
 *   @0x1419c0 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x1419c4 mov r4, r0
 *   @0x1419c8 b 0x141934 <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x78>
 *   @0x1419cc add r4, sp, #264
 *   @0x1419d0 ldr r2, [pc, #0x38]
 *   @0x1419d4 mov r3, r6
 *   @0x1419d8 mov r1, #256
 *   @0x1419dc strb r8, [r4, #-0x104]!
 *   @0x1419e0 add r2, pc, r2
 *   @0x1419e4 mov r0, r4
 *   @0x1419e8 bl 0xb65c8 <snprintf@plt>
 *   @0x1419ec mov r0, r4
 *   @0x1419f0 mov r1, r8
 *   @0x1419f4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1419f8 b 0x14197c <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0xc0>
 *   @0x1419fc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x141a00 eoreq r0, r11, r8, ror r3
 *   @0x141a04 .word 0xffffbd00
 *   @0x141a08 .word 0xffffbeec
 *   @0x141a0c .word 0xffffbcd8
 *   @0x141a10 andseq pc, pc, r12, asr #32
 *
 * ══ §51/87 F_CameraSetView(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f95c  size 344  86 条（0x16f95c..0x16fab4）
 * @func 0x16f95c 0x16fab4  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int)×2 / CCameraManager::GetCamera(int) / CCamera::SetViewX(float) / CCamera::SetViewY(float) / CCamera::SetViewWidth(float) / CCamera::SetViewHeight(float) / CCamera::SetViewSpeedX(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x124×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f95c cmp r3, #11
 *   @0x16f960 push {r3, r4, r5, lr}
 *   @0x16f964 mov r3, #0
 *   @0x16f968 mov r1, r3
 *   @0x16f96c ldr r4, [sp, #0x10]
 *   @0x16f970 movt r3, #0xbff0
 *   @0x16f974 str r1, [r0, #0xc]
 *   @0x16f978 stm r0, {r1, r3}
 *   @0x16f97c beq 0x16f990 <_Z15F_CameraSetViewR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f980 ldr r0, [pc, #0x124]
 *   @0x16f984 pop {r3, r4, r5, lr}
 *   @0x16f988 add r0, pc, r0
 *   @0x16f98c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f990 mov r0, r4
 *   @0x16f994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f998 ldr r3, [pc, #0x110]
 *   @0x16f99c mov r1, r0
 *   @0x16f9a0 ldr r0, [pc, r3]
 *   @0x16f9a4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f9a8 subs r5, r0, #0
 *   @0x16f9ac popeq {r3, r4, r5, pc}
 *   @0x16f9b0 mov r0, r4
 *   @0x16f9b4 mov r1, #1
 *   @0x16f9b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f9bc mov r1, r0
 *   @0x16f9c0 mov r0, r5
 *   @0x16f9c4 bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x16f9c8 mov r0, r4
 *   @0x16f9cc mov r1, #2
 *   @0x16f9d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f9d4 mov r1, r0
 *   @0x16f9d8 mov r0, r5
 *   @0x16f9dc bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x16f9e0 mov r0, r4
 *   @0x16f9e4 mov r1, #3
 *   @0x16f9e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16f9ec mov r1, r0
 *   @0x16f9f0 mov r0, r5
 *   @0x16f9f4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x16f9f8 mov r0, r4
 *   @0x16f9fc mov r1, #4
 *   @0x16fa00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa04 mov r1, r0
 *   @0x16fa08 mov r0, r5
 *   @0x16fa0c bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x16fa10 mov r0, r4
 *   @0x16fa14 mov r1, #5
 *   @0x16fa18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa1c mov r1, r0
 *   @0x16fa20 mov r0, r5
 *   @0x16fa24 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf>
 *   @0x16fa28 mov r0, r4
 *   @0x16fa2c mov r1, #6
 *   @0x16fa30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa34 mov r1, r0
 *   @0x16fa38 mov r0, r5
 *   @0x16fa3c bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf>
 *   @0x16fa40 mov r0, r4
 *   @0x16fa44 mov r1, #7
 *   @0x16fa48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa4c mov r1, r0
 *   @0x16fa50 mov r0, r5
 *   @0x16fa54 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf>
 *   @0x16fa58 mov r0, r4
 *   @0x16fa5c mov r1, #8
 *   @0x16fa60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa64 mov r1, r0
 *   @0x16fa68 mov r0, r5
 *   @0x16fa6c bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf>
 *   @0x16fa70 mov r0, r4
 *   @0x16fa74 mov r1, #9
 *   @0x16fa78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fa7c mov r1, r0
 *   @0x16fa80 mov r0, r5
 *   @0x16fa84 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x16fa88 mov r0, r4
 *   @0x16fa8c mov r1, #10
 *   @0x16fa90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fa94 mov r1, r0
 *   @0x16fa98 mov r0, r5
 *   @0x16fa9c bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi>
 *   @0x16faa0 mov r0, r5
 *   @0x16faa4 pop {r3, r4, r5, lr}
 *   @0x16faa8 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv>
 *   @0x16faac mulseq sp, r0, r5
 *   @0x16fab0 .word 0x0027e2d4
 *
 * ══ §52/87 GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)  0x17738c  size 344  86 条（0x17738c..0x1774e4）
 * @func 0x17738c 0x1774f8  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)+0x50 / HandleOverflow()
 * 字段偏移 top8: 0xe8×2 / 0x120×1 / 0x11c×1 / 0x118×1 / 0x34×1 / 0xec×1 / 0x4×1 / 0x8×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17738c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x177390 vpush {d8}
 *   @0x177394 mov r7, r0
 *   @0x177398 vldr s16, [sp, #48]
 *   @0x17739c ldr r4, [pc, #0x120]
 *   @0x1773a0 mov r8, r1
 *   @0x1773a4 ldr r0, [pc, #0x11c]
 *   @0x1773a8 mov r10, r3
 *   @0x1773ac ldr r1, [pc, #0x118]
 *   @0x1773b0 add r4, pc, r4
 *   @0x1773b4 mov r9, r2
 *   @0x1773b8 ldr r11, [sp, #0x34]
 *   @0x1773bc ldr r6, [r4, r0]
 *   @0x1773c0 ldr r3, [r4, r1]
 *   @0x1773c4 ldr r5, [r6]
 *   @0x1773c8 ldr r3, [r3]
 *   @0x1773cc cmp r5, r3
 *   @0x1773d0 blt 0x1773dc <_Z22GR_3D_Vertex_N_Textureffffffff+0x50>
 *   @0x1773d4 bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x1773d8 ldr r5, [r6]
 *   @0x1773dc ldr r1, [pc, #0xec]
 *   @0x1773e0 add r12, r5, r5, lsl #3
 *   @0x1773e4 ldr r2, [pc, #0xe8]
 *   @0x1773e8 ldr r3, [pc, #0xe8]
 *   @0x1773ec ldr r1, [r4, r1]
 *   @0x1773f0 add r12, r1, r12, lsl #2
 *   @0x1773f4 vstr s16, [r12, #16]
 *   @0x1773f8 str r7, [r12]
 *   @0x1773fc str r8, [r12, #0x4]
 *   @0x177400 str r9, [r12, #0x8]
 *   @0x177404 str r10, [r12, #0xc]
 *   @0x177408 str r11, [r12, #0x14]
 *   @0x17740c ldr r2, [r4, r2]
 *   @0x177410 ldr r2, [r2]
 *   @0x177414 bic r2, r2, #1
 *   @0x177418 str r2, [r12, #0x18]
 *   @0x17741c ldr r3, [r4, r3]
 *   @0x177420 ldr r3, [r3]
 *   @0x177424 cmp r3, #0
 *   @0x177428 beq 0x1774a4 <_Z22GR_3D_Vertex_N_Textureffffffff+0x118>
 *   @0x17742c ldrsh r1, [r3]
 *   @0x177430 vldr s10, [sp, #56]
 *   @0x177434 ldrsh r2, [r3, #12]
 *   @0x177438 add r5, r5, #1
 *   @0x17743c vmov s14, r1
 *   @0x177440 ldrsh r1, [r3, #2]
 *   @0x177444 vmov s11, r2
 *   @0x177448 ldrsh r3, [r3, #14]
 *   @0x17744c vcvt.f32.s32 s14, s14
 *   @0x177450 ldr r2, [pc, #0x84]
 *   @0x177454 vmov s15, r1
 *   @0x177458 vmov s13, r3
 *   @0x17745c ldr r3, [r4, r2]
 *   @0x177460 vldr s12, [r3]
 *   @0x177464 ldr r3, [pc, #0x74]
 *   @0x177468 vcvt.f32.s32 s11, s11
 *   @0x17746c vmla.f32 s14, s10, s11
 *   @0x177470 vdiv.f32 s14, s14, s12
 *   @0x177474 vldr s12, [sp, #60]
 *   @0x177478 vpop {d8}
 *   @0x17747c vcvt.f32.s32 s15, s15
 *   @0x177480 vstr s14, [r12, #28]
 *   @0x177484 ldr r3, [r4, r3]
 *   @0x177488 vldr s14, [r3]
 *   @0x17748c str r5, [r6]
 *   @0x177490 vcvt.f32.s32 s13, s13
 *   @0x177494 vmla.f32 s15, s12, s13
 *   @0x177498 vdiv.f32 s15, s15, s14
 *   @0x17749c vstr s15, [r12, #32]
 *   @0x1774a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1774a4 vldr s10, [sp, #56]
 *   @0x1774a8 vldr s12, [sp, #60]
 *   @0x1774ac vpop {d8}
 *   @0x1774b0 vstr s10, [r12, #28]
 *   @0x1774b4 add r5, r5, #1
 *   @0x1774b8 vstr s12, [r12, #32]
 *   @0x1774bc str r5, [r6]
 *   @0x1774c0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1774c4 eoreq r10, r7, r0, lsr #17
 *   @0x1774c8 .word 0xffffe670
 *   @0x1774cc .word 0xffffe67c
 *   @0x1774d0 .word 0xffffe680
 *   @0x1774d4 .word 0xffffc0ac
 *   @0x1774d8 .word 0xffffe540
 *   @0x1774dc .word 0xffffe544
 *   @0x1774e0 .word 0xffffe548
 *
 * ══ §53/87 GR_3D_Vertex_N_Texture_Color(float, float, float, float, float, float, float, float, unsigned int, float)  0x1774e4  size 344  86 条（0x1774e4..0x17763c）
 * @func 0x1774e4 0x17763c  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture_Color(float, float, float, float, float, float, float, float, unsigned int, float)+0x54 / HandleOverflow() / ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x124×1 / 0x120×1 / 0x11c×1 / 0x40×1 / 0x44×1 / 0xe0×1 / 0x4×1 / 0x8×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1774e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1774e8 vpush {d8}
 *   @0x1774ec mov r10, r0
 *   @0x1774f0 vldr s17, [sp, #48]
 *   @0x1774f4 ldr r5, [pc, #0x124]
 *   @0x1774f8 mov r9, r1
 *   @0x1774fc ldr r0, [pc, #0x120]
 *   @0x177500 mov r7, r3
 *   @0x177504 ldr r1, [pc, #0x11c]
 *   @0x177508 add r5, pc, r5
 *   @0x17750c mov r8, r2
 *   @0x177510 vldr s16, [sp, #52]
 *   @0x177514 ldr r6, [r5, r0]
 *   @0x177518 ldr r3, [r5, r1]
 *   @0x17751c ldr r11, [sp, #0x40]
 *   @0x177520 ldr r2, [r6]
 *   @0x177524 ldr r3, [r3]
 *   @0x177528 ldr r4, [sp, #0x44]
 *   @0x17752c cmp r2, r3
 *   @0x177530 blt 0x177538 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x54>
 *   @0x177534 bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x177538 mov r0, r4
 *   @0x17753c bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x177540 ldr r4, [r6]
 *   @0x177544 ldr r3, [pc, #0xe0]
 *   @0x177548 add r4, r4, r4, lsl #3
 *   @0x17754c ldr r3, [r5, r3]
 *   @0x177550 add r4, r3, r4, lsl #2
 *   @0x177554 vstr s17, [r4, #16]
 *   @0x177558 vstr s16, [r4, #20]
 *   @0x17755c str r10, [r4]
 *   @0x177560 str r9, [r4, #0x4]
 *   @0x177564 str r8, [r4, #0x8]
 *   @0x177568 str r7, [r4, #0xc]
 *   @0x17756c mov r1, r0
 *   @0x177570 orr r0, r11, #1
 *   @0x177574 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x177578 ldr r3, [pc, #0xb0]
 *   @0x17757c str r0, [r4, #0x18]
 *   @0x177580 ldr r3, [r5, r3]
 *   @0x177584 ldr r3, [r3]
 *   @0x177588 cmp r3, #0
 *   @0x17758c beq 0x17760c <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x128>
 *   @0x177590 ldrsh r1, [r3]
 *   @0x177594 vldr s10, [sp, #56]
 *   @0x177598 ldrsh r2, [r3, #12]
 *   @0x17759c vmov s14, r1
 *   @0x1775a0 ldrsh r1, [r3, #2]
 *   @0x1775a4 vmov s11, r2
 *   @0x1775a8 ldrsh r3, [r3, #14]
 *   @0x1775ac vcvt.f32.s32 s14, s14
 *   @0x1775b0 ldr r2, [pc, #0x7c]
 *   @0x1775b4 vmov s15, r1
 *   @0x1775b8 vmov s13, r3
 *   @0x1775bc ldr r3, [r5, r2]
 *   @0x1775c0 vldr s12, [r3]
 *   @0x1775c4 ldr r3, [pc, #0x6c]
 *   @0x1775c8 vcvt.f32.s32 s11, s11
 *   @0x1775cc vmla.f32 s14, s10, s11
 *   @0x1775d0 vdiv.f32 s14, s14, s12
 *   @0x1775d4 vldr s12, [sp, #60]
 *   @0x1775d8 vcvt.f32.s32 s15, s15
 *   @0x1775dc vstr s14, [r4, #28]
 *   @0x1775e0 ldr r3, [r5, r3]
 *   @0x1775e4 vldr s14, [r3]
 *   @0x1775e8 vcvt.f32.s32 s13, s13
 *   @0x1775ec vmla.f32 s15, s12, s13
 *   @0x1775f0 vdiv.f32 s15, s15, s14
 *   @0x1775f4 vstr s15, [r4, #32]
 *   @0x1775f8 vpop {d8}
 *   @0x1775fc ldr r3, [r6]
 *   @0x177600 add r3, r3, #1
 *   @0x177604 str r3, [r6]
 *   @0x177608 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17760c vldr s10, [sp, #56]
 *   @0x177610 vldr s12, [sp, #60]
 *   @0x177614 vstr s10, [r4, #28]
 *   @0x177618 vstr s12, [r4, #32]
 *   @0x17761c b 0x1775f8 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf+0x114>
 *   @0x177620 eoreq r10, r7, r8, asr #14
 *   @0x177624 .word 0xffffe670
 *   @0x177628 .word 0xffffe67c
 *   @0x17762c .word 0xffffe680
 *   @0x177630 .word 0xffffe540
 *   @0x177634 .word 0xffffe544
 *   @0x177638 .word 0xffffe548
 *
 * ══ §54/87 Debug_GetUpdate(Buffer_Standard*, Buffer_Standard*)  0x29d4d4  size 344  86 条（0x29d4d4..0x29d62c）
 * @func 0x29d4d4 0x29d62c  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / VM::GetRuntimeStateRealtime(Buffer_Standard*, int) / Debug_QueryHeapMem(unsigned int&, unsigned long long&) / DbgServer::GetBufferSize() / VM::GetRuntimeState(Buffer_Standard*, int)
 * 字段偏移 top8: 0x8×4 / 0x38×3 / 0x30×3 / 0xc×2 / 0x4×2 / 0x120×1 / 0xa4×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d4d4 ldr r3, [r0]
 *   @0x29d4d8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29d4dc add r4, r0, #44
 *   @0x29d4e0 mov r6, r1
 *   @0x29d4e4 sub sp, sp, #16
 *   @0x29d4e8 mov r2, r4
 *   @0x29d4ec ldr r3, [r3, #0xc]
 *   @0x29d4f0 mov r10, #0
 *   @0x29d4f4 mov r1, #6
 *   @0x29d4f8 ldr r7, [pc, #0x120]
 *   @0x29d4fc blx r3
 *   @0x29d500 mov r0, r4
 *   @0x29d504 mov r1, r10
 *   @0x29d508 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29d50c ldr r7, [pc, r7]
 *   @0x29d510 ldr r3, [r6]
 *   @0x29d514 add r8, r6, #44
 *   @0x29d518 ldrb r4, [r7]
 *   @0x29d51c mov r1, #5
 *   @0x29d520 mov r2, r8
 *   @0x29d524 str r10, [r6, #0x38]
 *   @0x29d528 vmov s15, r4
 *   @0x29d52c vcvt.f64.u32 d7, s15
 *   @0x29d530 vmov r4, r5, d7
 *   @0x29d534 vstr s14, [r6, #44]
 *   @0x29d538 mov r9, r0
 *   @0x29d53c mov r0, r6
 *   @0x29d540 str r5, [r6, #0x30]
 *   @0x29d544 ldr r3, [r3, #0x8]
 *   @0x29d548 blx r3
 *   @0x29d54c ldrb r3, [r7]
 *   @0x29d550 cmp r3, r10
 *   @0x29d554 bne 0x29d56c <_Z15Debug_GetUpdateP15Buffer_StandardS0_+0x98>
 *   @0x29d558 mov r0, r6
 *   @0x29d55c mov r1, r9
 *   @0x29d560 bl 0xd8dc8 <_ZN2VM23GetRuntimeStateRealtimeEP15Buffer_Standardi>
 *   @0x29d564 add sp, sp, #16
 *   @0x29d568 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29d56c add r1, sp, #8
 *   @0x29d570 add r0, sp, #4
 *   @0x29d574 bl 0x29c3a8 <_Z18Debug_QueryHeapMemRjRy>
 *   @0x29d578 ldr r3, [pc, #0xa4]
 *   @0x29d57c ldr r5, [r6, #0x10]
 *   @0x29d580 ldr r3, [pc, r3]
 *   @0x29d584 ldr r0, [r3]
 *   @0x29d588 bl 0x29d06c <_ZN9DbgServer13GetBufferSizeEv>
 *   @0x29d58c ldr r3, [pc, #0x94]
 *   @0x29d590 ldr r4, [sp, #0x4]
 *   @0x29d594 mov r2, r8
 *   @0x29d598 ldr r3, [pc, r3]
 *   @0x29d59c ldr r12, [r6]
 *   @0x29d5a0 mov r1, #5
 *   @0x29d5a4 str r10, [r6, #0x38]
 *   @0x29d5a8 ldr r3, [r3]
 *   @0x29d5ac add r5, r5, r0
 *   @0x29d5b0 mov r0, r6
 *   @0x29d5b4 add r5, r5, r3
 *   @0x29d5b8 rsb r4, r5, r4
 *   @0x29d5bc str r4, [sp, #0x4]
 *   @0x29d5c0 vmov s15, r4
 *   @0x29d5c4 vcvt.f64.u32 d7, s15
 *   @0x29d5c8 vmov r4, r5, d7
 *   @0x29d5cc vstr s14, [r6, #44]
 *   @0x29d5d0 str r5, [r6, #0x30]
 *   @0x29d5d4 ldr r3, [r12, #0x8]
 *   @0x29d5d8 blx r3
 *   @0x29d5dc ldr r0, [sp, #0x8]
 *   @0x29d5e0 ldr r1, [sp, #0xc]
 *   @0x29d5e4 mov r12, #10
 *   @0x29d5e8 ldr r3, [r6]
 *   @0x29d5ec mov r2, r8
 *   @0x29d5f0 str r0, [r6, #0x2c]
 *   @0x29d5f4 mov r0, r6
 *   @0x29d5f8 str r1, [r6, #0x30]
 *   @0x29d5fc mov r1, #12
 *   @0x29d600 ldr r3, [r3, #0x8]
 *   @0x29d604 str r12, [r6, #0x38]
 *   @0x29d608 blx r3
 *   @0x29d60c mov r0, r6
 *   @0x29d610 mov r1, r9
 *   @0x29d614 bl 0xdadc8 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi>
 *   @0x29d618 add sp, sp, #16
 *   @0x29d61c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29d620 andseq r2, r5, r4, ror #13
 *   @0x29d624 andseq r0, r5, r4, ror r7
 *   @0x29d628 andseq r4, r5, r0, ror r4
 *
 * ══ §55/87 anon_2f9f10  0x2f9f10  size 344  86 条（0x2f9f10..0x2fa068）
 * @func 0x2f9f10 0x2fa068  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x5ba354 / 0xd39e08 / anon_300274+0x6284 / 0x3546b8 / 0x3cb8d0 / 0x34652c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f9f10 .word 0x469a4ff0
 *   @0x2f9f14 .word 0x3174f890
 *   @0x2f9f18 svcge #0x1b08b
 *   @0x2f9f1c .word 0xf0134604
 *   @0x2f9f20 strmi r0, [r9], r1, lsl #30
 *   @0x2f9f24 .word 0xf8dd4690
 *   @0x2f9f28 shsaxmi r12, sp, r0
 *   @0x2f9f2c .word 0xf100d00e
 *   @0x2f9f30 .word 0xf8d40624
 *   @0x2f9f34 mcrgt p0, #0x0, r11, c15, c4, #0x1
 *   @0x2f9f38 cdpgt p5, #0x0, c12, c15, c15, #0x0
 *   @0x2f9f3c ldmdavs r3!, {r0, r1, r2, r3, r8, r10, lr, pc}
 *   @0x2f9f40 eorvs r6, r11, r6, lsr #22
 *   @0x2f9f44 rfeia r4!
 *   @0x2f9f48 and r5, lr, r2, lsr #2
 *   @0x2f9f4c strbeq pc, [r8], -r0, lsl #2
 *   @0x2f9f50 ldrsblt pc, [r8], #-132
 *   @0x2f9f54 strgt r12, [pc, #-0xe0f]
 *   @0x2f9f58 strgt r12, [pc, #-0xe0f]
 *   @0x2f9f5c stclvs p8, c6, [r6, #-204]!
 *   @0x2f9f60 rfeia r4!
 *   @0x2f9f64 rfeia r4!
 *   @0x2f9f68 addsmi r5, sp, #36, #2
 *   @0x2f9f6c .word 0xf894d309
 *   @0x2f9f70 .word 0xb10b3235
 *   @0x2f9f74 rscvs r2, r3, r6, lsl #7
 *   @0x2f9f78 andhs r2, r1, r0, lsl #6
 *   @0x2f9f7c andlo pc, r0, r12, lsr #17
 *   @0x2f9f80 .word 0xf8cde032
 *   @0x2f9f84 .word 0xf8adb014
 *   @0x2f9f88 strls r3, [r4], -r12
 *   @0x2f9f8c stm r10!, {r0, r1, r2, r3, r8, r9, r10, r11, lr, pc}
 *   @0x2f9f90 svcgt #0xf000f
 *   @0x2f9f94 andeq lr, pc, r10, lsr #17
 *   @0x2f9f98 ldmdavs r11!, {r5, r9, r10, lr}
 *   @0x2f9f9c andlo pc, r0, r10, asr #17
 *   @0x2f9fa0 bl 0x5ba354 <g_SWFlineaavertbuff+0x6728c>
 *   @0x2f9fa4 ldrtmi r0, [r3], #-515
 *   @0x2f9fa8 andpl pc, r0, r12, lsr #17
 *   @0x2f9fac eorsvc pc, r5, r11, asr r8
 *   @0x2f9fb0 eorsne pc, r5, r6, asr r8
 *   @0x2f9fb4 ldmdavs r10, {r0, r2, r4, r6, r11, sp, lr} ^
 *   @0x2f9fb8 .word 0xf8d41a79
 *   @0x2f9fbc bne 0xfed868c4 <b2_toiTime+0xfffffffffe62d420>
 *   @0x2f9fc0 rfeib r4!
 *   @0x2f9fc4 .word 0xf8d4112e
 *   @0x2f9fc8 .word 0x46052238
 *   @0x2f9fcc cdp2 p7, #0xb, c15, c6, c10, #0x7
 *   @0x2f9fd0 andeq pc, r0, r9, asr #17
 *   @0x2f9fd4 rfeib r4!
 *   @0x2f9fd8 .word 0xf8d41130
 *   @0x2f9fdc .word 0xf7ea2238
 *   @0x2f9fe0 .word 0xf8c8fead
 *   @0x2f9fe4 andhs r0, r0, r0
 *   @0x2f9fe8 pop {r0, r1, r3, r12, sp, pc}
 *   @0x2f9fec ldrlt r8, [r0, #-0xff0]!
 *   @0x2f9ff0 stmdbvs r2, {r2, r9, r10, lr}
 *   @0x2f9ff4 .word 0xf8d0b08f
 *   @0x2f9ff8 addsmi r3, r10, #52, #2
 *   @0x2f9ffc .word 0xf890da05
 *   @0x2fa000 .word 0xb3633235
 *   @0x2fa004 sbcvs r2, r3, r6, lsl #7
 *   @0x2fa008 .word 0xf10de029
 *   @0x2fa00c stmdbge r3, {r1, r3, r8, r9}
 *   @0x2fa010 bge 0x41ec18 <g_RomDisk+0x273f8>
 *   @0x2fa014 .word 0xf7ffab05
 *   @0x2fa018 bllt 0xd39e08 <b2_toiTime+0x5e0964>
 *   @0x2fa01c .word 0xf8d42501
 *   @0x2fa020 blhs 0x3064f8 <TT_New_Context+0x62f0>
 *   @0x2fa024 stmibvs r3!, {r0, r1, r3, r4, r8, r10, r11, r12, lr, pc} ^
 *   @0x2fa028 bllo 0x3546b8
 *   @0x2fa02c rfeda r2!
 *   @0x2fa030 rfeia r4!
 *   @0x2fa034 addmi r3, r11, #116
 *   @0x2fa038 .word 0xf894d805
 *   @0x2fa03c .word 0xb1433235
 *   @0x2fa040 rscvs r2, r3, r6, lsl #7
 *   @0x2fa044 strls lr, [r0, #-0x10]
 *   @0x2fa048 bls 0x3cb8d0 <error_g0017+0x24574>
 *   @0x2fa04c .word 0xf7ff9b04
 *   @0x2fa050 .word 0xf8d4fc86
 *   @0x2fa054 bllo 0x34652c
 *   @0x2fa058 teqlo r4, r4, asr #17
 *   @0x2fa05c movwhs lr, #0x17df
 *   @0x2fa060 teqlo r4, r4, asr #17
 *   @0x2fa064 eorvs r6, r3, #3719168
 *
 * ══ §56/87 Background_Duplicate(int)  0xc3ff4  size 340  85 条（0xc3ff4..0xc4148）
 * @func 0xc3ff4 0xc4148  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Background_Duplicate(int)+0x130 / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CBackground::CBackground() / CBackground::Assign(CBackground*) / CBackground::GenerateBitmapData()
 * 字段偏移 top8: 0x2×6 / 0x4×4 / 0x104×2 / 0x12c×1 / 0x118×1 / 0x108×1 / 0xf4×1 / 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3ff4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc3ff8 subs r8, r0, #0
 *   @0xc3ffc ldr r6, [pc, #0x12c]
 *   @0xc4000 sub sp, sp, #268
 *   @0xc4004 ldr r6, [pc, r6]
 *   @0xc4008 ldr r3, [r6]
 *   @0xc400c str r3, [sp, #0x104]
 *   @0xc4010 blt 0xc4124 <_Z20Background_Duplicatei+0x130>
 *   @0xc4014 ldr r4, [pc, #0x118]
 *   @0xc4018 ldr r4, [pc, r4]
 *   @0xc401c ldr r3, [r4]
 *   @0xc4020 cmp r8, r3
 *   @0xc4024 bge 0xc4124 <_Z20Background_Duplicatei+0x130>
 *   @0xc4028 ldr r5, [pc, #0x108]
 *   @0xc402c add r5, pc, r5
 *   @0xc4030 ldr r2, [r5, #0x4]
 *   @0xc4034 ldr r2, [r2, r8, lsl #2]
 *   @0xc4038 cmp r2, #0
 *   @0xc403c beq 0xc4124 <_Z20Background_Duplicatei+0x130>
 *   @0xc4040 ldr r9, [pc, #0xf4]
 *   @0xc4044 add r12, r3, #1
 *   @0xc4048 add r0, r5, #4
 *   @0xc404c movw r3, #0x27b
 *   @0xc4050 add r9, pc, r9
 *   @0xc4054 lsl r1, r12, #2
 *   @0xc4058 ldr r7, [pc, #0xe0]
 *   @0xc405c mov r2, r9
 *   @0xc4060 str r12, [r4]
 *   @0xc4064 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc4068 ldr r12, [r4]
 *   @0xc406c ldr r7, [pc, r7]
 *   @0xc4070 mov r2, r9
 *   @0xc4074 movw r3, #0x27d
 *   @0xc4078 add r9, sp, #4
 *   @0xc407c lsl r1, r12, #2
 *   @0xc4080 mov r0, r7
 *   @0xc4084 str r12, [r5]
 *   @0xc4088 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc408c ldr r3, [r4]
 *   @0xc4090 mov r1, #256
 *   @0xc4094 ldr r2, [pc, #0xa8]
 *   @0xc4098 mov r0, r9
 *   @0xc409c sub r3, r3, #1
 *   @0xc40a0 add r2, pc, r2
 *   @0xc40a4 bl 0xb65c8 <snprintf@plt>
 *   @0xc40a8 ldr r3, [r4]
 *   @0xc40ac mov r0, r9
 *   @0xc40b0 ldr r7, [r7]
 *   @0xc40b4 sub r9, r3, #-1073741823
 *   @0xc40b8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc40bc str r0, [r7, r9, lsl #2]
 *   @0xc40c0 mov r0, #72
 *   @0xc40c4 bl 0x27c524 <_Znwj>
 *   @0xc40c8 mov r7, r0
 *   @0xc40cc bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc40d0 ldr r2, [r4]
 *   @0xc40d4 ldr r3, [r5, #0x4]
 *   @0xc40d8 sub r2, r2, #-1073741823
 *   @0xc40dc str r7, [r3, r2, lsl #2]
 *   @0xc40e0 ldr r3, [r5, #0x4]
 *   @0xc40e4 ldr r0, [r3, r2, lsl #2]
 *   @0xc40e8 ldr r1, [r3, r8, lsl #2]
 *   @0xc40ec bl 0xc2b80 <_ZN11CBackground6AssignEPS_>
 *   @0xc40f0 ldr r2, [r4]
 *   @0xc40f4 ldr r3, [r5, #0x4]
 *   @0xc40f8 sub r2, r2, #-1073741823
 *   @0xc40fc ldr r0, [r3, r2, lsl #2]
 *   @0xc4100 bl 0xc2da0 <_ZN11CBackground18GenerateBitmapDataEv>
 *   @0xc4104 ldr r0, [r4]
 *   @0xc4108 sub r0, r0, #1
 *   @0xc410c ldr r2, [sp, #0x104]
 *   @0xc4110 ldr r3, [r6]
 *   @0xc4114 cmp r2, r3
 *   @0xc4118 bne 0xc412c <_Z20Background_Duplicatei+0x138>
 *   @0xc411c add sp, sp, #268
 *   @0xc4120 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc4124 mvn r0, #0
 *   @0xc4128 b 0xc410c <_Z20Background_Duplicatei+0x118>
 *   @0xc412c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc4130 eorseq r9, r2, r12, asr #18
 *   @0xc4134 eorseq r9, r2, r0, lsr r9
 *   @0xc4138 eorseq r5, r11, r12, ror r12
 *   @0xc413c eoreq r12, r6, r0, lsr r10
 *   @0xc4140 eorseq r9, r2, r0, ror #17
 *   @0xc4144 eoreq r12, r6, r12, lsr #20
 *
 * ══ §57/87 VM::GetObjectBaseVariables(Buffer_Standard*, YYObjectBase*, bool)  0xd8df4  size 340  85 条（0xd8df4..0xd8f48）
 * @func 0xd8df4 0xd8f5c  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / WriteString(Buffer_Standard*, char const*) / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*) / YYObject_PropertyNameIterator::Next(RValue*)
 * 字段偏移 top8: 0x30×2 / 0x8×2 / 0x38×2 / 0x1c×2 / 0x4×2 / 0xc×2 / 0x10×2 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8df4 ldr r12, [r0]
 *   @0xd8df8 mov r3, #0
 *   @0xd8dfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd8e00 add r11, r0, #44
 *   @0xd8e04 str r3, [r0, #0x2c]
 *   @0xd8e08 sub sp, sp, #76
 *   @0xd8e0c str r3, [r0, #0x30]
 *   @0xd8e10 mov r5, r2
 *   @0xd8e14 ldr r12, [r12, #0x8]
 *   @0xd8e18 eor r5, r5, #1
 *   @0xd8e1c str r3, [r0, #0x38]
 *   @0xd8e20 mov r7, r1
 *   @0xd8e24 ldr r3, [r0, #0x1c]
 *   @0xd8e28 mov r2, r11
 *   @0xd8e2c mov r1, #5
 *   @0xd8e30 cmp r7, #0
 *   @0xd8e34 orreq r5, r5, #1
 *   @0xd8e38 mov r4, r0
 *   @0xd8e3c str r3, [sp, #0x4]
 *   @0xd8e40 blx r12
 *   @0xd8e44 cmp r5, #0
 *   @0xd8e48 beq 0xd8e54 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0x60>
 *   @0xd8e4c add sp, sp, #76
 *   @0xd8e50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd8e54 add r8, sp, #44
 *   @0xd8e58 mov r1, r7
 *   @0xd8e5c mov r2, r5
 *   @0xd8e60 add r9, sp, #12
 *   @0xd8e64 mov r0, r8
 *   @0xd8e68 mov r10, #5
 *   @0xd8e6c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0xd8e70 add r6, sp, #28
 *   @0xd8e74 mov r3, #1
 *   @0xd8e78 strb r3, [sp, #0x3d]
 *   @0xd8e7c b 0xd8eb0 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0xbc>
 *   @0xd8e80 ldr r3, [sp, #0xc]
 *   @0xd8e84 add r5, r5, #1
 *   @0xd8e88 str r10, [sp, #0x28]
 *   @0xd8e8c ldr r2, [r3]
 *   @0xd8e90 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0xd8e94 ldr r3, [sp, #0xc]
 *   @0xd8e98 mov r0, r4
 *   @0xd8e9c ldr r1, [r3]
 *   @0xd8ea0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0xd8ea4 mov r0, r6
 *   @0xd8ea8 mov r1, r4
 *   @0xd8eac bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd8eb0 mov r1, r9
 *   @0xd8eb4 mov r0, r8
 *   @0xd8eb8 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0xd8ebc mov r1, r6
 *   @0xd8ec0 subs r3, r0, #0
 *   @0xd8ec4 mov r0, r7
 *   @0xd8ec8 bne 0xd8e80 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb+0x8c>
 *   @0xd8ecc ldr r12, [r4]
 *   @0xd8ed0 mov r1, r3
 *   @0xd8ed4 ldr r8, [r4, #0x1c]
 *   @0xd8ed8 mov r0, r4
 *   @0xd8edc ldr r2, [sp, #0x4]
 *   @0xd8ee0 ldr r12, [r12, #0x10]
 *   @0xd8ee4 str r3, [sp]
 *   @0xd8ee8 blx r12
 *   @0xd8eec vmov s15, r5
 *   @0xd8ef0 ldr r3, [sp]
 *   @0xd8ef4 mov r2, r11
 *   @0xd8ef8 vcvt.f64.s32 d7, s15
 *   @0xd8efc ldr r12, [r4]
 *   @0xd8f00 mov r0, r4
 *   @0xd8f04 mov r1, #5
 *   @0xd8f08 str r3, [r4, #0x38]
 *   @0xd8f0c vmov r6, r7, d7
 *   @0xd8f10 vstr s14, [r4, #44]
 *   @0xd8f14 str r7, [r4, #0x30]
 *   @0xd8f18 ldr r12, [r12, #0x8]
 *   @0xd8f1c str r3, [sp]
 *   @0xd8f20 blx r12
 *   @0xd8f24 ldr r3, [sp]
 *   @0xd8f28 ldr r12, [r4]
 *   @0xd8f2c mov r2, r8
 *   @0xd8f30 mov r0, r4
 *   @0xd8f34 mov r1, r3
 *   @0xd8f38 ldr r3, [r12, #0x10]
 *   @0xd8f3c blx r3
 *   @0xd8f40 add sp, sp, #76
 *   @0xd8f44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §58/87 F_DsMapSecureLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb588  size 340  85 条（0xfb588..0xfb6dc）
 * @func 0xfb588 0xfb6dc  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / IBuffer::Read(void const*, unsigned int, unsigned int)×2 / MemoryManager::Free(void const*)×2 / YYGetInt32(RValue const*, int) / GetIBuffer(int) / anon_fb34c / base64_decode(char const*, unsigned int, char*, bool) / JSONToDSMap(char*, int)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x4×1 / 0x10c×1 / 0x10×1 / 0x50×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb588 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfb58c mov r4, #0
 *   @0xfb590 ldr r2, [sp, #0x20]
 *   @0xfb594 mov r1, r4
 *   @0xfb598 str r4, [r0, #0xc]
 *   @0xfb59c mov r6, r0
 *   @0xfb5a0 str r4, [r0]
 *   @0xfb5a4 mov r3, r4
 *   @0xfb5a8 movt r3, #0xbff0
 *   @0xfb5ac str r3, [r0, #0x4]
 *   @0xfb5b0 mov r0, r2
 *   @0xfb5b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfb5b8 bl 0xc6720 <_Z10GetIBufferi>
 *   @0xfb5bc subs r5, r0, #0
 *   @0xfb5c0 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfb5c4 ldr r8, [pc, #0x10c]
 *   @0xfb5c8 movw r2, #0x784
 *   @0xfb5cc mov r3, #1
 *   @0xfb5d0 mov r0, #81
 *   @0xfb5d4 add r8, pc, r8
 *   @0xfb5d8 ldr r9, [r5, #0x10]
 *   @0xfb5dc mov r1, r8
 *   @0xfb5e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb5e4 mov r2, #1
 *   @0xfb5e8 mov r3, #80
 *   @0xfb5ec mov r7, r0
 *   @0xfb5f0 mov r0, r5
 *   @0xfb5f4 mov r1, r7
 *   @0xfb5f8 bl 0xcdc9c <_ZN7IBuffer4ReadEPKvjj>
 *   @0xfb5fc strb r4, [r7, #0x50]
 *   @0xfb600 mov r0, r7
 *   @0xfb604 bl 0xfb34c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0xfb608 cmp r0, r4
 *   @0xfb60c bne 0xfb61c <_Z23F_DsMapSecureLoadBufferR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xfb610 mov r0, r7
 *   @0xfb614 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfb618 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb61c mov r1, r8
 *   @0xfb620 sub r0, r9, #78
 *   @0xfb624 movw r2, #0x78d
 *   @0xfb628 mov r3, #1
 *   @0xfb62c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb630 sub r10, r9, #79
 *   @0xfb634 mov r2, #1
 *   @0xfb638 mov r3, r10
 *   @0xfb63c mov r9, r0
 *   @0xfb640 mov r0, r5
 *   @0xfb644 mov r1, r9
 *   @0xfb648 bl 0xcdc9c <_ZN7IBuffer4ReadEPKvjj>
 *   @0xfb64c add r3, r10, r10, lsl #1
 *   @0xfb650 cmp r3, r4
 *   @0xfb654 add r2, r3, #3
 *   @0xfb658 strb r4, [r9, r10]
 *   @0xfb65c mov r1, r8
 *   @0xfb660 movge r4, r3
 *   @0xfb664 movlt r4, r2
 *   @0xfb668 asr r4, r4, #2
 *   @0xfb66c movw r2, #0x792
 *   @0xfb670 add r4, r4, #4
 *   @0xfb674 mov r3, #1
 *   @0xfb678 mov r0, r4
 *   @0xfb67c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb680 mov r1, r4
 *   @0xfb684 mov r3, #1
 *   @0xfb688 mov r8, r0
 *   @0xfb68c mov r0, r9
 *   @0xfb690 mov r2, r8
 *   @0xfb694 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb>
 *   @0xfb698 mvn r1, #0
 *   @0xfb69c mov r0, r8
 *   @0xfb6a0 bl 0x13d5ac <_Z11JSONToDSMapPci>
 *   @0xfb6a4 vmov s15, r0
 *   @0xfb6a8 mov r0, r8
 *   @0xfb6ac vcvt.f64.s32 d7, s15
 *   @0xfb6b0 vmov r4, r5, d7
 *   @0xfb6b4 vmov r2, s14
 *   @0xfb6b8 mov r3, r5
 *   @0xfb6bc stm r6, {r2, r3}
 *   @0xfb6c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb6c4 mov r0, r9
 *   @0xfb6c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb6cc mov r0, r7
 *   @0xfb6d0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfb6d4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb6d8 eoreq r12, r3, r8, asr #11
 *
 * ══ §59/87 _yytimegm(tm*)  0x117d98  size 340  85 条（0x117d98..0x117eec）
 * @func 0x117d98 0x117eec  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: is_leap_year(int)×2 / _yytimegm(tm*)+0xe4×2 / _yytimegm(tm*)+0x84
 * 字段偏移 top8: 0x14×3 / 0x10×3 / 0x4×2 / 0x140×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117d98 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x117d9c mov r7, r0
 *   @0x117da0 ldr r4, [pc, #0x140]
 *   @0x117da4 sub sp, sp, #48
 *   @0x117da8 ldr r3, [r0, #0x14]
 *   @0x117dac mov r5, #0
 *   @0x117db0 add r4, pc, r4
 *   @0x117db4 mov r12, sp
 *   @0x117db8 add r4, r4, #52
 *   @0x117dbc cmp r3, #70
 *   @0x117dc0 ldm r4!, {r0, r1, r2, r3}
 *   @0x117dc4 stm r12!, {r0, r1, r2, r3}
 *   @0x117dc8 ldm r4!, {r0, r1, r2, r3}
 *   @0x117dcc stm r12!, {r0, r1, r2, r3}
 *   @0x117dd0 ldm r4, {r0, r1, r2, r3}
 *   @0x117dd4 mov r4, #0
 *   @0x117dd8 stm r12, {r0, r1, r2, r3}
 *   @0x117ddc ble 0x117e1c <_Z9_yytimegmP2tm+0x84>
 *   @0x117de0 mov r6, #70
 *   @0x117de4 add r0, r6, #1888
 *   @0x117de8 add r6, r6, #1
 *   @0x117dec add r0, r0, #12
 *   @0x117df0 bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117df4 mov r3, #0
 *   @0x117df8 movw r2, #0x16e
 *   @0x117dfc cmp r0, #0
 *   @0x117e00 moveq r3, #0
 *   @0x117e04 movweq r2, #0x16d
 *   @0x117e08 adds r4, r4, r2
 *   @0x117e0c adc r5, r5, r3
 *   @0x117e10 ldr r3, [r7, #0x14]
 *   @0x117e14 cmp r3, r6
 *   @0x117e18 bgt 0x117de4 <_Z9_yytimegmP2tm+0x4c>
 *   @0x117e1c ldr r2, [r7, #0x10]
 *   @0x117e20 cmp r2, #0
 *   @0x117e24 ble 0x117e7c <_Z9_yytimegmP2tm+0xe4>
 *   @0x117e28 sub r8, sp, #4
 *   @0x117e2c mov r6, #0
 *   @0x117e30 b 0x117e40 <_Z9_yytimegmP2tm+0xa8>
 *   @0x117e34 add r6, r6, #1
 *   @0x117e38 cmp r2, r6
 *   @0x117e3c ble 0x117e7c <_Z9_yytimegmP2tm+0xe4>
 *   @0x117e40 ldr r3, [r8, #0x4]!
 *   @0x117e44 adds r4, r4, r3
 *   @0x117e48 adc r5, r5, r3, asr #31
 *   @0x117e4c cmp r6, #1
 *   @0x117e50 bne 0x117e34 <_Z9_yytimegmP2tm+0x9c>
 *   @0x117e54 ldr r0, [r7, #0x14]
 *   @0x117e58 add r0, r0, #1888
 *   @0x117e5c add r0, r0, #12
 *   @0x117e60 bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117e64 cmp r0, #0
 *   @0x117e68 bne 0x117ed8 <_Z9_yytimegmP2tm+0x140>
 *   @0x117e6c ldr r2, [r7, #0x10]
 *   @0x117e70 add r6, r6, #1
 *   @0x117e74 cmp r2, r6
 *   @0x117e78 bgt 0x117e40 <_Z9_yytimegmP2tm+0xa8>
 *   @0x117e7c ldr r3, [r7, #0xc]
 *   @0x117e80 mov r1, #24
 *   @0x117e84 ldr r10, [r7, #0x8]
 *   @0x117e88 mov r12, #60
 *   @0x117e8c sub r3, r3, #1
 *   @0x117e90 ldr r6, [r7, #0x4]
 *   @0x117e94 adds r8, r4, r3
 *   @0x117e98 adc r9, r5, r3, asr #31
 *   @0x117e9c ldr r5, [r7]
 *   @0x117ea0 umull r2, r3, r8, r1
 *   @0x117ea4 adds r0, r2, r10
 *   @0x117ea8 mla r3, r1, r9, r3
 *   @0x117eac adc r1, r3, r10, asr #31
 *   @0x117eb0 umull r2, r3, r0, r12
 *   @0x117eb4 adds r2, r2, r6
 *   @0x117eb8 mla r3, r12, r1, r3
 *   @0x117ebc umull r0, r1, r2, r12
 *   @0x117ec0 adc r3, r3, r6, asr #31
 *   @0x117ec4 adds r0, r0, r5
 *   @0x117ec8 mla r1, r12, r3, r1
 *   @0x117ecc adc r1, r1, r5, asr #31
 *   @0x117ed0 add sp, sp, #48
 *   @0x117ed4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x117ed8 adds r4, r4, #1
 *   @0x117edc ldr r2, [r7, #0x10]
 *   @0x117ee0 adc r5, r5, #0
 *   @0x117ee4 b 0x117e34 <_Z9_yytimegmP2tm+0x9c>
 *   @0x117ee8 mlaeq r4, r0, r11, r4
 *
 * ══ §60/87 GR_3D_Projection_Perspective(float, float, float, float, float)  0x163548  size 340  85 条（0x163548..0x16369c）
 * @func 0x163548 0x16369c  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1635fc→0x3f237c, 0x163604→0x3f2378, 0x16360c→0x3f2374, 0x163618→0x3f23b4, 0x163668→0x7530c9
 * 调用序列: Graphics::SetMatrix(eMatrix, float*)×2 / DirtyRoomExtents()×2 / 0xb6580 / 0xb658c / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / yyMatrix::PerspectiveLH(yyMatrix*, float, float, float, float)
 * 字段偏移 top8: 0x28×2 / 0x20×1 / 0x100×1 / 0x2c×1 / 0x24×1 / 0x84×1 / 0x80×1 / 0x7c×1
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163548 vmov.f32 s15, #5.000000e-01
 *   @0x16354c push {r4, r5, r6, r7, lr}
 *   @0x163550 vpush {d8, d9}
 *   @0x163554 vmov s14, r0
 *   @0x163558 vldr s18, [pc, #288]
 *   @0x16355c vmov s16, r2
 *   @0x163560 sub sp, sp, #180
 *   @0x163564 vmov s17, r3
 *   @0x163568 vldr s19, [sp, #216]
 *   @0x16356c vmov s13, r1
 *   @0x163570 mov r6, #0
 *   @0x163574 str r6, [sp, #0x20]
 *   @0x163578 mov r5, #0
 *   @0x16357c ldr r4, [pc, #0x100]
 *   @0x163580 add r4, pc, r4
 *   @0x163584 vmla.f32 s14, s16, s15
 *   @0x163588 vmla.f32 s13, s17, s15
 *   @0x16358c vstr s14, [sp, #12]
 *   @0x163590 vstr s14, [sp, #24]
 *   @0x163594 vnmul.f32 s15, s19, s18
 *   @0x163598 vstr s13, [sp, #16]
 *   @0x16359c vstr s13, [sp, #28]
 *   @0x1635a0 vneg.f32 s14, s16
 *   @0x1635a4 vmov r0, s15
 *   @0x1635a8 vstr s14, [sp, #20]
 *   @0x1635ac bl 0xb6580 <sinf@plt>
 *   @0x1635b0 vmul.f32 s18, s19, s18
 *   @0x1635b4 mov r7, r0
 *   @0x1635b8 vmov r0, s18
 *   @0x1635bc bl 0xb658c <cosf@plt>
 *   @0x1635c0 str r6, [sp, #0x2c]
 *   @0x1635c4 add r6, sp, #48
 *   @0x1635c8 add r2, sp, #24
 *   @0x1635cc add r3, sp, #36
 *   @0x1635d0 add r1, sp, #12
 *   @0x1635d4 str r7, [sp, #0x24]
 *   @0x1635d8 str r0, [sp, #0x28]
 *   @0x1635dc mov r0, r6
 *   @0x1635e0 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x1635e4 mov r1, r6
 *   @0x1635e8 mov r0, r5
 *   @0x1635ec add r6, sp, #112
 *   @0x1635f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1635f4 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1635f8 vdiv.f32 s17, s17, s16
 *   @0x1635fc ldr r1, [pc, #0x84]
 *   @0x163600 mov r2, #0
 *   @0x163604 ldr r3, [pc, #0x80]
 *   @0x163608 movt r2, #0x46fa
 *   @0x16360c ldr r12, [pc, #0x7c]
 *   @0x163610 mov r0, r6
 *   @0x163614 ldr lr, [r4, r1]
 *   @0x163618 ldr r1, [pc, #0x74]
 *   @0x16361c strb r5, [lr]
 *   @0x163620 ldr lr, [r4, r3]
 *   @0x163624 mov r3, #1065353216
 *   @0x163628 str r3, [lr]
 *   @0x16362c ldr r12, [r4, r12]
 *   @0x163630 str r2, [r12]
 *   @0x163634 ldr r12, [r4, r1]
 *   @0x163638 str r2, [sp]
 *   @0x16363c vldr s15, [r12]
 *   @0x163640 vdiv.f32 s16, s16, s16
 *   @0x163644 vcvt.f32.s32 s15, s15
 *   @0x163648 vmov r1, s16
 *   @0x16364c vmul.f32 s15, s17, s15
 *   @0x163650 vmov r2, s15
 *   @0x163654 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff>
 *   @0x163658 mov r1, r6
 *   @0x16365c mov r0, #1
 *   @0x163660 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x163664 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x163668 ldr r3, [pc, #0x28]
 *   @0x16366c ldr r3, [r4, r3]
 *   @0x163670 strb r5, [r3]
 *   @0x163674 add sp, sp, #180
 *   @0x163678 vpop {d8, d9}
 *   @0x16367c pop {r4, r5, r6, r7, pc}
 *   @0x163680 vstmialo lr, {s30, s31}
 *   @0x163684 .word 0x0028e6d0
 *   @0x163688 .word 0xffffe480
 *   @0x16368c .word 0xffffe484
 *   @0x163690 .word 0xffffe488
 *   @0x163694 .word 0xffffe48c
 *   @0x163698 .word 0xffffe490
 *
 * ══ §61/87 GR_3D_Draw_Wall(float, float, float, float, float, float, int, float, float)  0x1796e0  size 340  85 条（0x1796e0..0x179834）
 * @func 0x1796e0 0x179848  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)×4 / Graphics::Flush()×2 / GR_D3D_Get_Texture_Repeat() / GR_D3D_Set_Texture_Repeat(bool) / GR_3D_Primitive_Begin(int, int) / GR_3D_Primitive_End() / 0xb6700
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0xc×4 / 0x4c×1 / 0x50×1 / 0x54×1 / 0x58×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1796e0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1796e4 vpush {d8, d9, d10}
 *   @0x1796e8 sub sp, sp, #16
 *   @0x1796ec vldr s20, [sp, #72]
 *   @0x1796f0 vmov s18, r1
 *   @0x1796f4 mov r6, r2
 *   @0x1796f8 vmov s21, r3
 *   @0x1796fc ldr r5, [sp, #0x4c]
 *   @0x179700 vmov s19, r0
 *   @0x179704 ldr r10, [sp, #0x50]
 *   @0x179708 ldr r8, [sp, #0x54]
 *   @0x17970c ldr r7, [sp, #0x58]
 *   @0x179710 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x179714 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x179718 mov r9, r0
 *   @0x17971c mov r0, #1
 *   @0x179720 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179724 vsub.f32 s16, s20, s18
 *   @0x179728 vmul.f32 s14, s16, s16
 *   @0x17972c vsub.f32 s17, s21, s19
 *   @0x179730 vmla.f32 s14, s17, s17
 *   @0x179734 vsqrt.f32 s15, s14
 *   @0x179738 vcmp.f32 s15, s15
 *   @0x17973c vmrs APSR_nzcv, fpscr
 *   @0x179740 bne 0x179824 <_Z15GR_3D_Draw_Wallffffffiff+0x144>
 *   @0x179744 vcmp.f32 s15, #0
 *   @0x179748 mov r4, #0
 *   @0x17974c vmrs APSR_nzcv, fpscr
 *   @0x179750 bne 0x179760 <_Z15GR_3D_Draw_Wallffffffiff+0x80>
 *   @0x179754 add sp, sp, #16
 *   @0x179758 vpop {d8, d9, d10}
 *   @0x17975c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x179760 vneg.f32 s17, s17
 *   @0x179764 mov r1, r10
 *   @0x179768 mov r0, #6
 *   @0x17976c vdiv.f32 s17, s17, s15
 *   @0x179770 vdiv.f32 s16, s16, s15
 *   @0x179774 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x179778 vmov r0, s19
 *   @0x17977c mov r2, r6
 *   @0x179780 vmov r1, s18
 *   @0x179784 vstr s17, [sp]
 *   @0x179788 str r4, [sp, #0x4]
 *   @0x17978c str r4, [sp, #0x8]
 *   @0x179790 str r4, [sp, #0xc]
 *   @0x179794 vmov r3, s16
 *   @0x179798 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x17979c mov r2, r6
 *   @0x1797a0 vmov r3, s16
 *   @0x1797a4 vstr s17, [sp]
 *   @0x1797a8 vmov r0, s21
 *   @0x1797ac vmov r1, s20
 *   @0x1797b0 str r4, [sp, #0x4]
 *   @0x1797b4 str r8, [sp, #0x8]
 *   @0x1797b8 str r4, [sp, #0xc]
 *   @0x1797bc bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1797c0 vmov r3, s16
 *   @0x1797c4 vmov r0, s21
 *   @0x1797c8 mov r2, r5
 *   @0x1797cc vmov r1, s20
 *   @0x1797d0 vstr s17, [sp]
 *   @0x1797d4 str r4, [sp, #0x4]
 *   @0x1797d8 str r8, [sp, #0x8]
 *   @0x1797dc str r7, [sp, #0xc]
 *   @0x1797e0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1797e4 vmov r0, s19
 *   @0x1797e8 mov r2, r5
 *   @0x1797ec vmov r3, s16
 *   @0x1797f0 vmov r1, s18
 *   @0x1797f4 vstr s17, [sp]
 *   @0x1797f8 str r4, [sp, #0x4]
 *   @0x1797fc str r4, [sp, #0x8]
 *   @0x179800 str r7, [sp, #0xc]
 *   @0x179804 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179808 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x17980c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x179810 mov r0, r9
 *   @0x179814 add sp, sp, #16
 *   @0x179818 vpop {d8, d9, d10}
 *   @0x17981c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x179820 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179824 vmov r0, s14
 *   @0x179828 bl 0xb6700 <sqrtf@plt>
 *   @0x17982c vmov s15, r0
 *   @0x179830 b 0x179744 <_Z15GR_3D_Draw_Wallffffffiff+0x64>
 *
 * ══ §62/87 GR_3D_Draw_Floor(float, float, float, float, float, float, int, float, float)  0x179834  size 340  85 条（0x179834..0x179988）
 * @func 0x179834 0x179988  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)×4 / Graphics::Flush()×2 / GR_D3D_Get_Texture_Repeat() / GR_D3D_Set_Texture_Repeat(bool) / GR_3D_Primitive_Begin(int, int) / GR_3D_Primitive_End() / 0xb6700
 * 字段偏移 top8: 0x8×4 / 0xc×4 / 0x48×1 / 0x50×1 / 0x54×1 / 0x58×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179834 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x179838 vpush {d8, d9, d10}
 *   @0x17983c sub sp, sp, #16
 *   @0x179840 vldr s18, [sp, #76]
 *   @0x179844 vmov s20, r2
 *   @0x179848 mov r5, r1
 *   @0x17984c vmov s19, r3
 *   @0x179850 ldr r6, [sp, #0x48]
 *   @0x179854 vmov s21, r0
 *   @0x179858 ldr r10, [sp, #0x50]
 *   @0x17985c ldr r7, [sp, #0x54]
 *   @0x179860 ldr r8, [sp, #0x58]
 *   @0x179864 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x179868 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x17986c mov r9, r0
 *   @0x179870 mov r0, #1
 *   @0x179874 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179878 vsub.f32 s17, s18, s20
 *   @0x17987c vmul.f32 s14, s17, s17
 *   @0x179880 vsub.f32 s16, s19, s21
 *   @0x179884 vmla.f32 s14, s16, s16
 *   @0x179888 vsqrt.f32 s15, s14
 *   @0x17988c vcmp.f32 s15, s15
 *   @0x179890 vmrs APSR_nzcv, fpscr
 *   @0x179894 bne 0x179978 <_Z16GR_3D_Draw_Floorffffffiff+0x144>
 *   @0x179898 vcmp.f32 s15, #0
 *   @0x17989c mov r4, #0
 *   @0x1798a0 vmrs APSR_nzcv, fpscr
 *   @0x1798a4 bne 0x1798b4 <_Z16GR_3D_Draw_Floorffffffiff+0x80>
 *   @0x1798a8 add sp, sp, #16
 *   @0x1798ac vpop {d8, d9, d10}
 *   @0x1798b0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1798b4 vneg.f32 s17, s17
 *   @0x1798b8 mov r1, r10
 *   @0x1798bc mov r0, #6
 *   @0x1798c0 vdiv.f32 s17, s17, s15
 *   @0x1798c4 vdiv.f32 s16, s16, s15
 *   @0x1798c8 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x1798cc vmov r3, s17
 *   @0x1798d0 mov r1, r5
 *   @0x1798d4 vmov r0, s21
 *   @0x1798d8 vmov r2, s20
 *   @0x1798dc str r4, [sp]
 *   @0x1798e0 str r4, [sp, #0x8]
 *   @0x1798e4 str r4, [sp, #0xc]
 *   @0x1798e8 vstr s16, [sp, #4]
 *   @0x1798ec bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1798f0 vmov r3, s17
 *   @0x1798f4 vmov r0, s21
 *   @0x1798f8 mov r1, r6
 *   @0x1798fc vmov r2, s20
 *   @0x179900 vstr s16, [sp, #4]
 *   @0x179904 str r4, [sp]
 *   @0x179908 str r4, [sp, #0x8]
 *   @0x17990c str r8, [sp, #0xc]
 *   @0x179910 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179914 mov r1, r6
 *   @0x179918 vmov r3, s17
 *   @0x17991c vstr s16, [sp, #4]
 *   @0x179920 vmov r0, s19
 *   @0x179924 vmov r2, s18
 *   @0x179928 str r4, [sp]
 *   @0x17992c str r7, [sp, #0x8]
 *   @0x179930 str r8, [sp, #0xc]
 *   @0x179934 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179938 vmov r0, s19
 *   @0x17993c mov r1, r5
 *   @0x179940 vmov r3, s17
 *   @0x179944 vmov r2, s18
 *   @0x179948 vstr s16, [sp, #4]
 *   @0x17994c str r4, [sp]
 *   @0x179950 str r7, [sp, #0x8]
 *   @0x179954 str r4, [sp, #0xc]
 *   @0x179958 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x17995c bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x179960 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x179964 mov r0, r9
 *   @0x179968 add sp, sp, #16
 *   @0x17996c vpop {d8, d9, d10}
 *   @0x179970 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x179974 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179978 vmov r0, s14
 *   @0x17997c bl 0xb6700 <sqrtf@plt>
 *   @0x179980 vmov s15, r0
 *   @0x179984 b 0x179898 <_Z16GR_3D_Draw_Floorffffffiff+0x64>
 *
 * ══ §63/87 ReadGIFFile(void*, int, int*, int*, bool)  0x18a918  size 340  85 条（0x18a918..0x18aa6c）
 * @func 0x18a918 0x18aa6c  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DGifOpen(void*, int (*)(GifFileType*, unsigned char*, int), int*) / DGifSlurp(GifFileType*) / ReadGIFFile(void*, int, int*, int*, bool)+0x144 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / ReadGIFFile(void*, int, int*, int*, bool)+0x124 / DGifCloseFile(GifFileType*)
 * 字段偏移 top8: 0x4×2 / 0x1×2 / 0x144×1 / 0x34×1 / 0x1c×1 / 0x20×1 / 0x8×1 / 0xa8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a918 ldr r1, [pc, #0x144]
 *   @0x18a91c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18a920 sub sp, sp, #12
 *   @0x18a924 mov r9, r2
 *   @0x18a928 ldr r1, [pc, r1]
 *   @0x18a92c add r2, sp, #4
 *   @0x18a930 mov r6, r3
 *   @0x18a934 bl 0x2c1c50 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi>
 *   @0x18a938 subs r5, r0, #0
 *   @0x18a93c beq 0x18aa50 <_Z11ReadGIFFilePviPiS0_b+0x138>
 *   @0x18a940 bl 0x2c2918 <_Z9DGifSlurpP11GifFileType>
 *   @0x18a944 cmp r0, #1
 *   @0x18a948 bne 0x18aa50 <_Z11ReadGIFFilePviPiS0_b+0x138>
 *   @0x18a94c ldr r8, [r5, #0x34]
 *   @0x18a950 ldr r12, [r8, #0x1c]
 *   @0x18a954 cmp r12, #0
 *   @0x18a958 ble 0x18aa5c <_Z11ReadGIFFilePviPiS0_b+0x144>
 *   @0x18a95c add r12, r12, r12, lsl #1
 *   @0x18a960 ldr r1, [r8, #0x20]
 *   @0x18a964 mvn r4, #0
 *   @0x18a968 add r12, r1, r12, lsl #2
 *   @0x18a96c b 0x18a97c <_Z11ReadGIFFilePviPiS0_b+0x64>
 *   @0x18a970 add r1, r1, #12
 *   @0x18a974 cmp r1, r12
 *   @0x18a978 beq 0x18a9b0 <_Z11ReadGIFFilePviPiS0_b+0x98>
 *   @0x18a97c ldr r0, [r1, #0x8]
 *   @0x18a980 cmp r0, #249
 *   @0x18a984 bne 0x18a970 <_Z11ReadGIFFilePviPiS0_b+0x58>
 *   @0x18a988 ldr r3, [r1]
 *   @0x18a98c cmp r3, #4
 *   @0x18a990 bne 0x18a970 <_Z11ReadGIFFilePviPiS0_b+0x58>
 *   @0x18a994 ldr r3, [r1, #0x4]
 *   @0x18a998 add r1, r1, #12
 *   @0x18a99c ldrb r2, [r3]
 *   @0x18a9a0 tst r2, #1
 *   @0x18a9a4 ldrbne r4, [r3, #0x3]
 *   @0x18a9a8 cmp r1, r12
 *   @0x18a9ac bne 0x18a97c <_Z11ReadGIFFilePviPiS0_b+0x64>
 *   @0x18a9b0 ldr r7, [r5]
 *   @0x18a9b4 mov r2, #200
 *   @0x18a9b8 ldr r1, [pc, #0xa8]
 *   @0x18a9bc mov r3, #1
 *   @0x18a9c0 str r7, [r9]
 *   @0x18a9c4 add r1, pc, r1
 *   @0x18a9c8 ldr r0, [r5, #0x4]
 *   @0x18a9cc mul r7, r0, r7
 *   @0x18a9d0 str r0, [r6]
 *   @0x18a9d4 lsl r0, r7, #2
 *   @0x18a9d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18a9dc cmp r7, #0
 *   @0x18a9e0 ldr r2, [r8, #0x18]
 *   @0x18a9e4 addgt r7, r2, r7
 *   @0x18a9e8 mov r6, r0
 *   @0x18a9ec ldr r0, [r5, #0x14]
 *   @0x18a9f0 movgt r3, r6
 *   @0x18a9f4 ble 0x18aa3c <_Z11ReadGIFFilePviPiS0_b+0x124>
 *   @0x18a9f8 ldrb r12, [r2]
 *   @0x18a9fc add r3, r3, #4
 *   @0x18aa00 ldr lr, [r0, #0xc]
 *   @0x18aa04 add r12, r12, r12, lsl #1
 *   @0x18aa08 add r1, lr, r12
 *   @0x18aa0c ldrb r12, [lr, r12]
 *   @0x18aa10 strb r12, [r3, #-0x4]
 *   @0x18aa14 ldrb r12, [r1, #0x1]
 *   @0x18aa18 strb r12, [r3, #-0x3]
 *   @0x18aa1c ldrb r1, [r1, #0x2]
 *   @0x18aa20 strb r1, [r3, #-0x2]
 *   @0x18aa24 ldrb r1, [r2], #1
 *   @0x18aa28 subs r1, r1, r4
 *   @0x18aa2c mvnne r1, #0
 *   @0x18aa30 cmp r2, r7
 *   @0x18aa34 strb r1, [r3, #-0x1]
 *   @0x18aa38 bne 0x18a9f8 <_Z11ReadGIFFilePviPiS0_b+0xe0>
 *   @0x18aa3c mov r0, r5
 *   @0x18aa40 bl 0x2c24e4 <_Z13DGifCloseFileP11GifFileType>
 *   @0x18aa44 mov r0, r6
 *   @0x18aa48 add sp, sp, #12
 *   @0x18aa4c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18aa50 mov r0, #0
 *   @0x18aa54 add sp, sp, #12
 *   @0x18aa58 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18aa5c mvn r4, #0
 *   @0x18aa60 b 0x18a9b0 <_Z11ReadGIFFilePviPiS0_b+0x98>
 *   @0x18aa64 eoreq r5, r6, r0, lsr #25
 *   @0x18aa68 andseq r1, r12, r0, ror r7
 *
 * ══ §64/87 F_LayerDeactivate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bbaf8  size 340  85 条（0x1bbaf8..0x1bbc4c）
 * @func 0x1bbaf8 0x1bbc4c  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CInstance::SetDeactivated(bool) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0x20×3 / 0x4×3 / 0x8×3 / 0xc×2 / 0x11c×1 / 0x58×1 / 0xc4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bbaf8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1bbafc cmp r3, #1
 *   @0x1bbb00 sub sp, sp, #8
 *   @0x1bbb04 mov r4, #0
 *   @0x1bbb08 str r4, [r0, #0xc]
 *   @0x1bbb0c ldr r5, [sp, #0x20]
 *   @0x1bbb10 str r4, [r0]
 *   @0x1bbb14 str r4, [r0, #0x4]
 *   @0x1bbb18 beq 0x1bbb34 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bbb1c ldr r0, [pc, #0x11c]
 *   @0x1bbb20 mov r1, r4
 *   @0x1bbb24 add r0, pc, r0
 *   @0x1bbb28 add sp, sp, #8
 *   @0x1bbb2c pop {r4, r5, r6, r7, r8, lr}
 *   @0x1bbb30 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bbb34 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bbb38 ldr r3, [r5, #0xc]
 *   @0x1bbb3c mov r1, r4
 *   @0x1bbb40 bic r3, r3, #-16777216
 *   @0x1bbb44 cmp r3, #1
 *   @0x1bbb48 mov r6, r0
 *   @0x1bbb4c mov r0, r5
 *   @0x1bbb50 beq 0x1bbc2c <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1bbb54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bbb58 mov r1, r0
 *   @0x1bbb5c mov r0, r6
 *   @0x1bbb60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bbb64 cmp r0, #0
 *   @0x1bbb68 beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1bbb6c ldr r4, [r0, #0x58]
 *   @0x1bbb70 cmp r4, #0
 *   @0x1bbb74 beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1bbb78 ldr r8, [pc, #0xc4]
 *   @0x1bbb7c add r8, pc, r8
 *   @0x1bbb80 b 0x1bbb90 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1bbb84 cmp r5, #0
 *   @0x1bbb88 mov r4, r5
 *   @0x1bbb8c beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1bbb90 ldr r3, [r4]
 *   @0x1bbb94 ldr r5, [r4, #0x14]
 *   @0x1bbb98 cmp r3, #2
 *   @0x1bbb9c bne 0x1bbb84 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bbba0 ldr r3, [r4, #0x20]
 *   @0x1bbba4 mov r1, #1
 *   @0x1bbba8 ldr r6, [pc, #0x98]
 *   @0x1bbbac ldrb r7, [r3, #0x69]
 *   @0x1bbbb0 mov r0, r3
 *   @0x1bbbb4 cmp r7, #0
 *   @0x1bbbb8 bne 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1bbbbc bl 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x1bbbc0 ldr r6, [pc, r6]
 *   @0x1bbbc4 ldr r4, [r4, #0x20]
 *   @0x1bbbc8 ldr r1, [r6, #0x8]
 *   @0x1bbbcc ldr r3, [r6, #0x4]
 *   @0x1bbbd0 cmp r1, r3
 *   @0x1bbbd4 beq 0x1bbbfc <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1bbbd8 ldr r2, [r6]
 *   @0x1bbbdc cmp r5, #0
 *   @0x1bbbe0 str r4, [r2, r1, lsl #2]
 *   @0x1bbbe4 add r3, r1, #1
 *   @0x1bbbe8 mov r4, r5
 *   @0x1bbbec str r3, [r6, #0x8]
 *   @0x1bbbf0 bne 0x1bbb90 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1bbbf4 add sp, sp, #8
 *   @0x1bbbf8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bbbfc lsl r3, r1, #1
 *   @0x1bbc00 ldr r0, [r6]
 *   @0x1bbc04 str r3, [r6, #0x4]
 *   @0x1bbc08 lsl r1, r1, #3
 *   @0x1bbc0c mov r2, r8
 *   @0x1bbc10 str r7, [sp]
 *   @0x1bbc14 mov r3, #74
 *   @0x1bbc18 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1bbc1c ldr r1, [r6, #0x8]
 *   @0x1bbc20 mov r2, r0
 *   @0x1bbc24 str r0, [r6]
 *   @0x1bbc28 b 0x1bbbdc <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1bbc2c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bbc30 mov r1, r0
 *   @0x1bbc34 mov r0, r6
 *   @0x1bbc38 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bbc3c b 0x1bbb64 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1bbc40 andseq r2, r9, r12, lsr #3
 *   @0x1bbc44 ldrheq r5, [r7], -r4
 *   @0x1bbc48 eoreq r2, r3, r8, lsl #1
 *
 * ══ §65/87 CSprite::LoadFromAnimation(IBitmapLoader*, bool, bool)  0x1e6cb0  size 340  85 条（0x1e6cb0..0x1e6e04）
 * @func 0x1e6cb0 0x1e6e04  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CBitmap32::CBitmap32(IBitmap*, bool, bool)×2 / CSprite::Clear() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::LoadFromAnimation(IBitmapLoader*, bool, bool)+0x14c
 * 字段偏移 top8: 0x18×4 / 0x48×4 / 0x32×3 / 0x33×3 / 0x4×2 / 0x2×2 / 0x10×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6cb0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e6cb4 mov r7, r1
 *   @0x1e6cb8 mov r5, r0
 *   @0x1e6cbc mov r4, r2
 *   @0x1e6cc0 mov r6, r3
 *   @0x1e6cc4 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e6cc8 ldr r3, [r7]
 *   @0x1e6ccc mov r0, r7
 *   @0x1e6cd0 strb r4, [r5, #0x32]
 *   @0x1e6cd4 strb r6, [r5, #0x33]
 *   @0x1e6cd8 ldr r3, [r3, #0xc]
 *   @0x1e6cdc blx r3
 *   @0x1e6ce0 ldr r2, [pc, #0x118]
 *   @0x1e6ce4 movw r3, #0x4c6
 *   @0x1e6ce8 add r2, pc, r2
 *   @0x1e6cec lsl r1, r0, #2
 *   @0x1e6cf0 str r0, [r5, #0x18]
 *   @0x1e6cf4 add r0, r5, #72
 *   @0x1e6cf8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e6cfc ldr r3, [r5, #0x18]
 *   @0x1e6d00 cmp r3, #0
 *   @0x1e6d04 str r3, [r5, #0x44]
 *   @0x1e6d08 pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e6d0c mov r4, #0
 *   @0x1e6d10 mov r9, r4
 *   @0x1e6d14 b 0x1e6d64 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xb4>
 *   @0x1e6d18 mov r0, #24
 *   @0x1e6d1c bl 0x27c524 <_Znwj>
 *   @0x1e6d20 ldrb r3, [r5, #0x33]
 *   @0x1e6d24 mov r1, r6
 *   @0x1e6d28 ldrb r2, [r5, #0x32]
 *   @0x1e6d2c mov r10, r0
 *   @0x1e6d30 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x1e6d34 ldr r3, [r5, #0x48]
 *   @0x1e6d38 cmp r6, #0
 *   @0x1e6d3c str r10, [r3, r8]
 *   @0x1e6d40 beq 0x1e6d54 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xa4>
 *   @0x1e6d44 ldr r3, [r6]
 *   @0x1e6d48 mov r0, r6
 *   @0x1e6d4c ldr r3, [r3, #0x4]
 *   @0x1e6d50 blx r3
 *   @0x1e6d54 ldr r3, [r5, #0x18]
 *   @0x1e6d58 add r4, r4, #1
 *   @0x1e6d5c cmp r3, r4
 *   @0x1e6d60 ble 0x1e6dfc <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x14c>
 *   @0x1e6d64 ldr r3, [r5, #0x48]
 *   @0x1e6d68 lsl r8, r4, #2
 *   @0x1e6d6c ldr r3, [r3, r4, lsl #2]
 *   @0x1e6d70 cmp r3, #0
 *   @0x1e6d74 mov r0, r3
 *   @0x1e6d78 beq 0x1e6d90 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0xe0>
 *   @0x1e6d7c ldr r3, [r3]
 *   @0x1e6d80 ldr r3, [r3, #0x4]
 *   @0x1e6d84 blx r3
 *   @0x1e6d88 ldr r3, [r5, #0x48]
 *   @0x1e6d8c str r9, [r3, r4, lsl #2]
 *   @0x1e6d90 ldr r3, [r7]
 *   @0x1e6d94 mov r0, r7
 *   @0x1e6d98 mov r1, r4
 *   @0x1e6d9c ldr r3, [r3, #0x10]
 *   @0x1e6da0 blx r3
 *   @0x1e6da4 cmp r4, #0
 *   @0x1e6da8 mov r6, r0
 *   @0x1e6dac bne 0x1e6d18 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x68>
 *   @0x1e6db0 ldr r3, [r0]
 *   @0x1e6db4 ldr r3, [r3, #0x10]
 *   @0x1e6db8 blx r3
 *   @0x1e6dbc ldr r3, [r6]
 *   @0x1e6dc0 ldr r3, [r3, #0x18]
 *   @0x1e6dc4 str r0, [r5, #0x1c]
 *   @0x1e6dc8 mov r0, r6
 *   @0x1e6dcc blx r3
 *   @0x1e6dd0 str r0, [r5, #0x20]
 *   @0x1e6dd4 mov r0, #24
 *   @0x1e6dd8 bl 0x27c524 <_Znwj>
 *   @0x1e6ddc ldrb r3, [r5, #0x33]
 *   @0x1e6de0 mov r1, r6
 *   @0x1e6de4 ldrb r2, [r5, #0x32]
 *   @0x1e6de8 mov r10, r0
 *   @0x1e6dec bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x1e6df0 ldr r3, [r5, #0x48]
 *   @0x1e6df4 str r10, [r3, r8]
 *   @0x1e6df8 b 0x1e6d44 <_ZN7CSprite17LoadFromAnimationEP13IBitmapLoaderbb+0x94>
 *   @0x1e6dfc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e6e00 andseq r11, r6, r12, lsr r7
 *
 * ══ §66/87 CDS_Grid::Get_Mean(RValue&, int, int, int, int)  0x2042c8  size 340  85 条（0x2042c8..0x20441c）
 * @func 0x2042c8 0x20441c  size 340  85 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::Get_Mean(RValue&, int, int, int, int)+0xc4 / CDS_Grid::Get_Mean(RValue&, int, int, int, int)+0xa4
 * 字段偏移 top8: 0x4×5 / 0xc×5 / 0x8×3 / 0x30×1 / 0x34×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2042c8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2042cc sub sp, sp, #16
 *   @0x2042d0 mov r5, #0
 *   @0x2042d4 str r5, [r1]
 *   @0x2042d8 ldr r4, [sp, #0x30]
 *   @0x2042dc mov r7, #0
 *   @0x2042e0 str r5, [r1, #0x4]
 *   @0x2042e4 cmp r2, r4
 *   @0x2042e8 str r5, [r1, #0xc]
 *   @0x2042ec lsrlt r5, r2, #31
 *   @0x2042f0 lsrge r5, r4, #31
 *   @0x2042f4 ldr r12, [sp, #0x34]
 *   @0x2042f8 cmp r2, r4
 *   @0x2042fc movlt r9, r2
 *   @0x204300 movge r9, r4
 *   @0x204304 cmp r5, #0
 *   @0x204308 ldr r8, [r0, #0x4]
 *   @0x20430c movne r9, #0
 *   @0x204310 cmp r3, r12
 *   @0x204314 movlt r5, r3
 *   @0x204318 movge r5, r12
 *   @0x20431c cmp r3, r12
 *   @0x204320 lsrlt r6, r3, #31
 *   @0x204324 lsrge r6, r12, #31
 *   @0x204328 cmp r6, #0
 *   @0x20432c movne r5, #0
 *   @0x204330 cmp r2, r4
 *   @0x204334 movlt r2, r4
 *   @0x204338 cmp r3, r12
 *   @0x20433c movlt r3, r12
 *   @0x204340 cmp r8, r2
 *   @0x204344 mla r10, r5, r8, r9
 *   @0x204348 suble r2, r8, #1
 *   @0x20434c str r2, [sp, #0xc]
 *   @0x204350 lsl r8, r8, #4
 *   @0x204354 str r3, [sp, #0x4]
 *   @0x204358 ldr r3, [sp, #0xc]
 *   @0x20435c str r5, [sp, #0x8]
 *   @0x204360 cmp r9, r3
 *   @0x204364 lsl r11, r10, #4
 *   @0x204368 bgt 0x2043ec <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x124>
 *   @0x20436c ldr r6, [r0, #0x8]
 *   @0x204370 mov r3, r11
 *   @0x204374 ldr r4, [sp, #0x4]
 *   @0x204378 ldr r2, [sp, #0x8]
 *   @0x20437c cmp r6, r4
 *   @0x204380 suble r4, r6, #1
 *   @0x204384 mov r6, r4
 *   @0x204388 b 0x2043cc <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x104>
 *   @0x20438c ldr r10, [r0]
 *   @0x204390 add r12, r10, r3
 *   @0x204394 ldr r4, [r12, #0xc]
 *   @0x204398 cmp r4, #0
 *   @0x20439c bne 0x2043c8 <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x100>
 *   @0x2043a0 ldr r5, [r12, #0x4]
 *   @0x2043a4 vldr s14, [r1]
 *   @0x2043a8 ldr r4, [r10, r3]
 *   @0x2043ac vldr s15, [r1, #4]
 *   @0x2043b0 add r7, r7, #1
 *   @0x2043b4 vmov d6, r4, r5
 *   @0x2043b8 vadd.f64 d6, d7, d6
 *   @0x2043bc vmov r4, r5, d6
 *   @0x2043c0 mov r12, r5
 *   @0x2043c4 stm r1, {r4, r12}
 *   @0x2043c8 add r3, r3, r8
 *   @0x2043cc cmp r2, r6
 *   @0x2043d0 add r2, r2, #1
 *   @0x2043d4 ble 0x20438c <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0xc4>
 *   @0x2043d8 ldr r3, [sp, #0xc]
 *   @0x2043dc add r9, r9, #1
 *   @0x2043e0 add r11, r11, #16
 *   @0x2043e4 cmp r9, r3
 *   @0x2043e8 ble 0x20436c <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0xa4>
 *   @0x2043ec cmp r7, #0
 *   @0x2043f0 beq 0x204410 <_ZN8CDS_Grid8Get_MeanER6RValueiiii+0x148>
 *   @0x2043f4 vmov s12, r7
 *   @0x2043f8 ldm r1, {r2, r3}
 *   @0x2043fc vcvt.f64.s32 d7, s12
 *   @0x204400 vmov d6, r2, r3
 *   @0x204404 vdiv.f64 d6, d6, d7
 *   @0x204408 vmov r2, r3, d6
 *   @0x20440c stm r1, {r2, r3}
 *   @0x204410 add sp, sp, #16
 *   @0x204414 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x204418 bx lr
 *
 * ══ §67/87 CSkeletonSprite::CSkeletonSprite(char*)  0xbdbe0  size 336  84 条（0xbdbe0..0xbdd30）
 * @func 0xbdbe0 0xbdd30  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×3 / 0xb6568×3 / 0xb655c×3 / 0xb6538 / CSkeletonSprite::CSkeletonSprite(char*)+0x140 / CSkeletonSprite::LoadFromFile(char*, char*)
 * 字段偏移 top8: 0x-1×3 / 0x4×1 / 0x8×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbdbe0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbdbe4 mov r9, r0
 *   @0xbdbe8 mov r7, #0
 *   @0xbdbec mov r0, r1
 *   @0xbdbf0 str r7, [r9]
 *   @0xbdbf4 mov r10, r1
 *   @0xbdbf8 str r7, [r9, #0x4]
 *   @0xbdbfc str r7, [r9, #0x8]
 *   @0xbdc00 bl 0xb6538 <strlen@plt>
 *   @0xbdc04 subs r6, r0, #0
 *   @0xbdc08 blt 0xbdd20 <_ZN15CSkeletonSpriteC2EPc+0x140>
 *   @0xbdc0c add r5, r6, #1
 *   @0xbdc10 mov r11, r7
 *   @0xbdc14 add r5, r10, r5
 *   @0xbdc18 mov r4, r6
 *   @0xbdc1c b 0xbdc3c <_ZN15CSkeletonSpriteC2EPc+0x5c>
 *   @0xbdc20 cmp r3, #92
 *   @0xbdc24 cmpne r3, #47
 *   @0xbdc28 beq 0xbdc94 <_ZN15CSkeletonSpriteC2EPc+0xb4>
 *   @0xbdc2c sub r4, r4, #1
 *   @0xbdc30 sub r5, r5, #1
 *   @0xbdc34 cmn r4, #1
 *   @0xbdc38 beq 0xbdc88 <_ZN15CSkeletonSpriteC2EPc+0xa8>
 *   @0xbdc3c cmp r7, #0
 *   @0xbdc40 ldrb r3, [r5, #-0x1]
 *   @0xbdc44 rsb r8, r4, r6
 *   @0xbdc48 bne 0xbdc20 <_ZN15CSkeletonSpriteC2EPc+0x40>
 *   @0xbdc4c cmp r3, #46
 *   @0xbdc50 bne 0xbdc20 <_ZN15CSkeletonSpriteC2EPc+0x40>
 *   @0xbdc54 mov r0, r8
 *   @0xbdc58 mov r6, r4
 *   @0xbdc5c bl 0xb6544 <malloc@plt>
 *   @0xbdc60 sub r4, r4, #1
 *   @0xbdc64 mov r1, r5
 *   @0xbdc68 sub r2, r8, #1
 *   @0xbdc6c sub r5, r5, #1
 *   @0xbdc70 mov r7, r0
 *   @0xbdc74 bl 0xb6568 <strncpy@plt>
 *   @0xbdc78 add r8, r7, r8
 *   @0xbdc7c cmn r4, #1
 *   @0xbdc80 strb r11, [r8, #-0x1]
 *   @0xbdc84 bne 0xbdc3c <_ZN15CSkeletonSpriteC2EPc+0x5c>
 *   @0xbdc88 mov r4, #0
 *   @0xbdc8c mov r5, r4
 *   @0xbdc90 b 0xbdce0 <_ZN15CSkeletonSpriteC2EPc+0x100>
 *   @0xbdc94 mov r0, r8
 *   @0xbdc98 mov r11, #0
 *   @0xbdc9c bl 0xb6544 <malloc@plt>
 *   @0xbdca0 add r1, r4, #1
 *   @0xbdca4 mov r2, r8
 *   @0xbdca8 add r1, r10, r1
 *   @0xbdcac mov r5, r0
 *   @0xbdcb0 bl 0xb6568 <strncpy@plt>
 *   @0xbdcb4 add r3, r5, r8
 *   @0xbdcb8 rsb r8, r8, #1
 *   @0xbdcbc add r6, r6, r8
 *   @0xbdcc0 strb r11, [r3, #-0x1]
 *   @0xbdcc4 add r0, r6, #1
 *   @0xbdcc8 bl 0xb6544 <malloc@plt>
 *   @0xbdccc mov r1, r10
 *   @0xbdcd0 mov r2, r6
 *   @0xbdcd4 mov r4, r0
 *   @0xbdcd8 bl 0xb6568 <strncpy@plt>
 *   @0xbdcdc strb r11, [r4, r6]
 *   @0xbdce0 ldr r3, [pc, #0x44]
 *   @0xbdce4 mov r1, r5
 *   @0xbdce8 mov r2, r4
 *   @0xbdcec mov r0, r9
 *   @0xbdcf0 add r3, pc, r3
 *   @0xbdcf4 mov r12, #0
 *   @0xbdcf8 str r12, [r3]
 *   @0xbdcfc bl 0xbd99c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_>
 *   @0xbdd00 mov r0, r5
 *   @0xbdd04 bl 0xb655c <free@plt>
 *   @0xbdd08 mov r0, r7
 *   @0xbdd0c bl 0xb655c <free@plt>
 *   @0xbdd10 mov r0, r4
 *   @0xbdd14 bl 0xb655c <free@plt>
 *   @0xbdd18 mov r0, r9
 *   @0xbdd1c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbdd20 mov r4, r7
 *   @0xbdd24 mov r5, r4
 *   @0xbdd28 b 0xbdce0 <_ZN15CSkeletonSpriteC2EPc+0x100>
 *   @0xbdd2c eorseq r11, r11, r0, lsr #31
 *
 * ══ §68/87 F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*)  0xff228  size 336  84 条（0xff228..0xff378）
 * @func 0xff228 0xff378  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*)+0xf4 / F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*)+0x114 / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x2c×2 / 0x28×1 / 0x114×1 / 0xc×1 / 0xe8×1 / 0xd8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff228 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xff22c sub sp, sp, #8
 *   @0xff230 add r9, sp, #4
 *   @0xff234 mov r6, r0
 *   @0xff238 ldr r8, [sp, #0x28]
 *   @0xff23c mov r0, r9
 *   @0xff240 ldr r7, [pc, #0x114]
 *   @0xff244 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff248 mov r3, #0
 *   @0xff24c mov r1, r3
 *   @0xff250 str r3, [r6, #0xc]
 *   @0xff254 str r3, [r6]
 *   @0xff258 mov r0, r8
 *   @0xff25c str r3, [r6, #0x4]
 *   @0xff260 add r7, pc, r7
 *   @0xff264 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff268 cmp r0, #0
 *   @0xff26c blt 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff270 ldr r3, [pc, #0xe8]
 *   @0xff274 ldr r3, [r7, r3]
 *   @0xff278 ldr r3, [r3]
 *   @0xff27c cmp r0, r3
 *   @0xff280 bge 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff284 ldr r3, [pc, #0xd8]
 *   @0xff288 ldr r3, [r7, r3]
 *   @0xff28c ldr r3, [r3, #0x4]
 *   @0xff290 ldr r0, [r3, r0, lsl #2]
 *   @0xff294 cmp r0, #0
 *   @0xff298 beq 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff29c ldr r10, [r8, #0x2c]
 *   @0xff2a0 ldr r4, [r8, #0x20]
 *   @0xff2a4 cmp r10, #0
 *   @0xff2a8 ldr r5, [r8, #0x24]
 *   @0xff2ac bne 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0xff2b0 vmov d7, r4, r5
 *   @0xff2b4 vcvt.s32.f64 s15, d7
 *   @0xff2b8 vmov r4, s15
 *   @0xff2bc cmp r4, #0
 *   @0xff2c0 blt 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0xff2c4 ldr r3, [pc, #0x9c]
 *   @0xff2c8 ldr r3, [r7, r3]
 *   @0xff2cc ldr r3, [r3]
 *   @0xff2d0 cmp r4, r3
 *   @0xff2d4 bge 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0xff2d8 ldr r3, [pc, #0x8c]
 *   @0xff2dc ldr r3, [r7, r3]
 *   @0xff2e0 ldr r3, [r3, #0x4]
 *   @0xff2e4 ldr r3, [r3, r4, lsl #2]
 *   @0xff2e8 cmp r3, #0
 *   @0xff2ec beq 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0xff2f0 mov r3, #1073741824
 *   @0xff2f4 add r1, r8, #16
 *   @0xff2f8 str r3, [r8, #0x2c]
 *   @0xff2fc add r2, r8, #32
 *   @0xff300 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0xff304 cmp r0, #0
 *   @0xff308 movne r3, #0
 *   @0xff30c strne r10, [r6]
 *   @0xff310 movtne r3, #0x3ff0
 *   @0xff314 strne r3, [r6, #0x4]
 *   @0xff318 b 0xff32c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xff31c ldr r0, [pc, #0x4c]
 *   @0xff320 mov r1, #0
 *   @0xff324 add r0, pc, r0
 *   @0xff328 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff32c mov r0, r9
 *   @0xff330 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff334 add sp, sp, #8
 *   @0xff338 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff33c ldr r0, [pc, #0x30]
 *   @0xff340 mov r1, #0
 *   @0xff344 add r0, pc, r0
 *   @0xff348 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff34c mov r0, r9
 *   @0xff350 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff354 add sp, sp, #8
 *   @0xff358 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff35c .word 0x002f29f0
 *   @0xff360 .word 0xffffc028
 *   @0xff364 .word 0xffffbcec
 *   @0xff368 .word 0xffffc02c
 *   @0xff36c .word 0xffffc030
 *   @0xff370 .word 0x002388d8
 *   @0xff374 eoreq r8, r3, r4, lsr #18
 *
 * ══ §69/87 F_InstanceCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1097ec  size 336  84 条（0x1097ec..0x10993c）
 * @func 0x1097ec 0x10993c  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Perform_Event(CInstance*, CInstance*, int, int)×2 / CRoom::AddInstance(float, float, int) / CInstance::Assign(CInstance*, bool) / F_InstanceCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c / YYGetBool(RValue const*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0x78×2 / 0x13c×1 / 0x7c×1 / 0xb4×1 / 0xb8×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1097ec ldr r12, [pc, #0x13c]
 *   @0x1097f0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1097f4 ldr r12, [pc, r12]
 *   @0x1097f8 mov r8, r1
 *   @0x1097fc sub sp, sp, #12
 *   @0x109800 ldr r3, [r8, #0x7c]
 *   @0x109804 mov r5, r0
 *   @0x109808 ldr r1, [r1, #0xb4]
 *   @0x10980c ldr r2, [r8, #0xb8]
 *   @0x109810 ldr r0, [r12]
 *   @0x109814 ldr r7, [sp, #0x28]
 *   @0x109818 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x10981c ldr r6, [pc, #0x110]
 *   @0x109820 mov r1, r8
 *   @0x109824 mov r2, #1
 *   @0x109828 mov r4, r0
 *   @0x10982c ldr r9, [r0, #0x78]
 *   @0x109830 bl 0x1986ec <_ZN9CInstance6AssignEPS_b>
 *   @0x109834 ldr r6, [pc, r6]
 *   @0x109838 ldr r1, [r6, #0x8]
 *   @0x10983c ldr r3, [r6, #0x4]
 *   @0x109840 str r9, [r4, #0x78]
 *   @0x109844 cmp r1, r3
 *   @0x109848 beq 0x1098f8 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x10984c ldr r8, [r6]
 *   @0x109850 cmp r1, #0
 *   @0x109854 ble 0x109888 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x109858 ldr r3, [r8]
 *   @0x10985c cmp r4, r3
 *   @0x109860 beq 0x109894 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x109864 mov r12, r8
 *   @0x109868 mov r3, #0
 *   @0x10986c b 0x10987c <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x109870 ldr lr, [r12, #0x4]!
 *   @0x109874 cmp r4, lr
 *   @0x109878 beq 0x109894 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x10987c add r3, r3, #1
 *   @0x109880 cmp r3, r1
 *   @0x109884 bne 0x109870 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x109888 str r4, [r8, r1, lsl #2]
 *   @0x10988c add r1, r1, #1
 *   @0x109890 str r1, [r6, #0x8]
 *   @0x109894 mov r0, r7
 *   @0x109898 mov r1, #0
 *   @0x10989c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1098a0 cmp r0, #0
 *   @0x1098a4 beq 0x1098d8 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1098a8 mov r0, r4
 *   @0x1098ac mov r1, r4
 *   @0x1098b0 mov r2, #14
 *   @0x1098b4 mov r3, #0
 *   @0x1098b8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1098bc mov r2, #0
 *   @0x1098c0 mov r3, r2
 *   @0x1098c4 mov r0, r4
 *   @0x1098c8 mov r1, r4
 *   @0x1098cc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1098d0 mov r3, #1
 *   @0x1098d4 strb r3, [r4, #0x6c]
 *   @0x1098d8 vmov s15, r9
 *   @0x1098dc mov r1, #0
 *   @0x1098e0 str r1, [r5, #0xc]
 *   @0x1098e4 vcvt.f64.s32 d7, s15
 *   @0x1098e8 vmov r2, r3, d7
 *   @0x1098ec stm r5, {r2, r3}
 *   @0x1098f0 add sp, sp, #12
 *   @0x1098f4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1098f8 ldr r2, [pc, #0x38]
 *   @0x1098fc lsl r3, r1, #1
 *   @0x109900 ldr r0, [r6]
 *   @0x109904 lsl r1, r1, #3
 *   @0x109908 str r3, [r6, #0x4]
 *   @0x10990c add r2, pc, r2
 *   @0x109910 mov r3, #0
 *   @0x109914 str r3, [sp]
 *   @0x109918 mov r3, #74
 *   @0x10991c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x109920 ldr r1, [r6, #0x8]
 *   @0x109924 mov r8, r0
 *   @0x109928 str r0, [r6]
 *   @0x10992c b 0x109850 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x109930 eoreq r4, lr, r4, lsr r1
 *   @0x109934 eoreq r4, lr, r0, ror r8
 *   @0x109938 eoreq r7, r2, r4, lsr #14
 *
 * ══ §70/87 InstanceRegionDeactivate(CInstance*)  0x10a240  size 336  84 条（0x10a240..0x10a390）
 * @func 0x10a240 0x10a390  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x68×1 / 0x69×1 / 0x64×1 / 0x100×1 / 0xf0×1 / 0xbc×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10a240 ldrb r3, [r0, #0x68]
 *   @0x10a244 push {r4, r5, lr}
 *   @0x10a248 cmp r3, #0
 *   @0x10a24c sub sp, sp, #12
 *   @0x10a250 mov r4, r0
 *   @0x10a254 bne 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4>
 *   @0x10a258 ldrb r3, [r0, #0x69]
 *   @0x10a25c cmp r3, #0
 *   @0x10a260 bne 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4>
 *   @0x10a264 ldrb r3, [r0, #0x64]
 *   @0x10a268 cmp r3, #0
 *   @0x10a26c bne 0x10a33c <_Z24InstanceRegionDeactivateP9CInstance+0xfc>
 *   @0x10a270 vldr s11, [r4, #232]
 *   @0x10a274 vcvt.f32.s32 s14, s11
 *   @0x10a278 ldr r3, [pc, #0x100]
 *   @0x10a27c add r3, pc, r3
 *   @0x10a280 vldr s15, [r3, #24]
 *   @0x10a284 vldr s13, [r3, #16]
 *   @0x10a288 ldr r3, [r4, #0xf0]
 *   @0x10a28c vcmpe.f32 s14, s15
 *   @0x10a290 vmrs APSR_nzcv, fpscr
 *   @0x10a294 movgt r3, #1
 *   @0x10a298 bgt 0x10a2b4 <_Z24InstanceRegionDeactivateP9CInstance+0x74>
 *   @0x10a29c vmov s12, r3
 *   @0x10a2a0 vcvt.f32.s32 s15, s12
 *   @0x10a2a4 vcmpe.f32 s15, s13
 *   @0x10a2a8 vmrs APSR_nzcv, fpscr
 *   @0x10a2ac movpl r3, #0
 *   @0x10a2b0 movmi r3, #1
 *   @0x10a2b4 vldr s14, [r4, #244]
 *   @0x10a2b8 vcvt.f32.s32 s12, s14
 *   @0x10a2bc vldr s11, [r4, #236]
 *   @0x10a2c0 ldr r2, [pc, #0xbc]
 *   @0x10a2c4 add r2, pc, r2
 *   @0x10a2c8 vldr s13, [r2, #20]
 *   @0x10a2cc vldr s15, [r2, #28]
 *   @0x10a2d0 ldrb r2, [r2, #0xc]
 *   @0x10a2d4 vcvt.f32.s32 s14, s11
 *   @0x10a2d8 vcmp.f32 s12, s13
 *   @0x10a2dc vmrs APSR_nzcv, fpscr
 *   @0x10a2e0 vcmp.f32 s14, s15
 *   @0x10a2e4 movmi r3, #1
 *   @0x10a2e8 vmrs APSR_nzcv, fpscr
 *   @0x10a2ec movgt r3, #1
 *   @0x10a2f0 cmp r2, r3
 *   @0x10a2f4 beq 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4>
 *   @0x10a2f8 ldr r5, [pc, #0x88]
 *   @0x10a2fc ldr r5, [pc, r5]
 *   @0x10a300 ldr r1, [r5, #0x8]
 *   @0x10a304 ldr r3, [r5, #0x4]
 *   @0x10a308 cmp r1, r3
 *   @0x10a30c beq 0x10a348 <_Z24InstanceRegionDeactivateP9CInstance+0x108>
 *   @0x10a310 ldr r3, [r5]
 *   @0x10a314 str r4, [r3, r1, lsl #2]
 *   @0x10a318 mov r0, r4
 *   @0x10a31c add r3, r1, #1
 *   @0x10a320 mov r1, #1
 *   @0x10a324 str r3, [r5, #0x8]
 *   @0x10a328 add sp, sp, #12
 *   @0x10a32c pop {r4, r5, lr}
 *   @0x10a330 b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10a334 add sp, sp, #12
 *   @0x10a338 pop {r4, r5, pc}
 *   @0x10a33c mov r1, #1
 *   @0x10a340 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x10a344 b 0x10a270 <_Z24InstanceRegionDeactivateP9CInstance+0x30>
 *   @0x10a348 ldr r2, [pc, #0x3c]
 *   @0x10a34c lsl r3, r1, #1
 *   @0x10a350 ldr r0, [r5]
 *   @0x10a354 lsl r1, r1, #3
 *   @0x10a358 str r3, [r5, #0x4]
 *   @0x10a35c add r2, pc, r2
 *   @0x10a360 mov r3, #0
 *   @0x10a364 str r3, [sp]
 *   @0x10a368 mov r3, #74
 *   @0x10a36c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10a370 ldr r1, [r5, #0x8]
 *   @0x10a374 mov r3, r0
 *   @0x10a378 str r0, [r5]
 *   @0x10a37c b 0x10a314 <_Z24InstanceRegionDeactivateP9CInstance+0xd4>
 *   @0x10a380 eorseq r9, r7, r12, asr r4
 *   @0x10a384 eorseq r9, r7, r4, lsl r4
 *   @0x10a388 eoreq r3, lr, r12, asr #18
 *   @0x10a38c .word 0x00226cd4
 *
 * ══ §71/87 F_ArrayEquals(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f8b8  size 336  84 条（0x10f8b8..0x10fa08）
 * @func 0x10f8b8 0x10fa08  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_ArrayEquals(RValue&, CInstance*, CInstance*, int, RValue*)+0x128 / YYCompareVal(RValue const&, RValue const&, double) / F_ArrayEquals(RValue&, CInstance*, CInstance*, int, RValue*)+0x90
 * 字段偏移 top8: 0x4×5 / 0x10×4 / 0xc×3 / 0x3×2 / 0x28×1 / 0x124×1 / 0x100×1 / 0xf4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f8b8 cmp r3, #2
 *   @0x10f8bc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10f8c0 mov r10, r0
 *   @0x10f8c4 ldr r3, [sp, #0x28]
 *   @0x10f8c8 beq 0x10f8dc <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x10f8cc ldr r0, [pc, #0x124]
 *   @0x10f8d0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10f8d4 add r0, pc, r0
 *   @0x10f8d8 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f8dc ldr r2, [r3, #0xc]
 *   @0x10f8e0 bic r1, r2, #-16777216
 *   @0x10f8e4 cmp r1, #2
 *   @0x10f8e8 beq 0x10f914 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x10f8ec cmp r2, #2
 *   @0x10f8f0 beq 0x10f904 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x10f8f4 ldr r0, [pc, #0x100]
 *   @0x10f8f8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10f8fc add r0, pc, r0
 *   @0x10f900 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f904 ldr r0, [pc, #0xf4]
 *   @0x10f908 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10f90c add r0, pc, r0
 *   @0x10f910 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f914 ldr r1, [r3, #0x1c]
 *   @0x10f918 bic r1, r1, #-16777216
 *   @0x10f91c cmp r1, #2
 *   @0x10f920 bne 0x10f8ec <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x10f924 ldr r8, [r3]
 *   @0x10f928 ldr r9, [r3, #0x10]
 *   @0x10f92c ldr r2, [r8, #0x10]
 *   @0x10f930 ldr r3, [r9, #0x10]
 *   @0x10f934 cmp r3, r2
 *   @0x10f938 bne 0x10f96c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x10f93c cmp r3, #0
 *   @0x10f940 movgt r7, #0
 *   @0x10f944 ble 0x10f9e0 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x10f948 ldr r1, [r8, #0x4]
 *   @0x10f94c lsl r2, r7, #3
 *   @0x10f950 ldr r3, [r9, #0x4]
 *   @0x10f954 add r6, r1, r2
 *   @0x10f958 add r0, r3, r2
 *   @0x10f95c ldr r1, [r1, r7, lsl #3]
 *   @0x10f960 ldr r2, [r3, r7, lsl #3]
 *   @0x10f964 cmp r2, r1
 *   @0x10f968 beq 0x10f988 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x10f96c mov r3, #0
 *   @0x10f970 mov r1, #13
 *   @0x10f974 mov r2, r3
 *   @0x10f978 str r1, [r10, #0xc]
 *   @0x10f97c str r3, [r10]
 *   @0x10f980 str r2, [r10, #0x4]
 *   @0x10f984 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10f988 ldr r5, [r0, #0x4]
 *   @0x10f98c mov r4, #0
 *   @0x10f990 ldr r11, [r6, #0x4]
 *   @0x10f994 b 0x10f9b4 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x10f998 ldr r3, [pc, r3]
 *   @0x10f99c add r11, r11, #16
 *   @0x10f9a0 ldrd r2, r3, [r3]
 *   @0x10f9a4 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x10f9a8 cmp r0, #0
 *   @0x10f9ac bne 0x10f96c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x10f9b0 ldr r2, [r6]
 *   @0x10f9b4 cmp r2, r4
 *   @0x10f9b8 mov r0, r5
 *   @0x10f9bc ldr r3, [pc, #0x40]
 *   @0x10f9c0 mov r1, r11
 *   @0x10f9c4 add r5, r5, #16
 *   @0x10f9c8 add r4, r4, #1
 *   @0x10f9cc bgt 0x10f998 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x10f9d0 ldr r3, [r8, #0x10]
 *   @0x10f9d4 add r7, r7, #1
 *   @0x10f9d8 cmp r7, r3
 *   @0x10f9dc blt 0x10f948 <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x10f9e0 mov r3, #13
 *   @0x10f9e4 mov r2, #0
 *   @0x10f9e8 str r3, [r10, #0xc]
 *   @0x10f9ec movt r2, #0x3ff0
 *   @0x10f9f0 mov r3, #0
 *   @0x10f9f4 b 0x10f97c <_Z13F_ArrayEqualsR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x10f9f8 .word 0x002296d8
 *   @0x10f9fc .word 0x002296d4
 *   @0x10fa00 .word 0x002296f0
 *   @0x10fa04 eoreq lr, sp, r0, lsl #7
 *
 * ══ §72/87 F_DateCreateDateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x114fe0  size 336  84 条（0x114fe0..0x115130）
 * @func 0x114fe0 0x115130  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / 0xb6808 / 0xb6814 / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x8×2 / 0x10×2 / 0x14×2 / 0x18×2 / 0x20×2 / 0x24×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114fe0 push {r4, r5, lr}
 *   @0x114fe4 sub sp, sp, #52
 *   @0x114fe8 mov r3, #0
 *   @0x114fec mov r5, r0
 *   @0x114ff0 ldr r4, [sp, #0x40]
 *   @0x114ff4 mov r1, r3
 *   @0x114ff8 str r3, [r0, #0xc]
 *   @0x114ffc str r3, [sp, #0x4]
 *   @0x115000 mov r0, r4
 *   @0x115004 str r3, [sp, #0x8]
 *   @0x115008 str r3, [sp, #0xc]
 *   @0x11500c str r3, [sp, #0x10]
 *   @0x115010 str r3, [sp, #0x14]
 *   @0x115014 str r3, [sp, #0x18]
 *   @0x115018 str r3, [sp, #0x1c]
 *   @0x11501c str r3, [sp, #0x20]
 *   @0x115020 str r3, [sp, #0x24]
 *   @0x115024 str r3, [sp, #0x28]
 *   @0x115028 str r3, [sp, #0x2c]
 *   @0x11502c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115030 mov r1, #1
 *   @0x115034 sub r3, r0, #1888
 *   @0x115038 mov r0, r4
 *   @0x11503c subs r3, r3, #12
 *   @0x115040 movmi r3, #0
 *   @0x115044 str r3, [sp, #0x18]
 *   @0x115048 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11504c mov r1, #2
 *   @0x115050 sub r3, r0, #1
 *   @0x115054 mov r0, r4
 *   @0x115058 str r3, [sp, #0x14]
 *   @0x11505c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115060 mov r1, #3
 *   @0x115064 str r0, [sp, #0x10]
 *   @0x115068 mov r0, r4
 *   @0x11506c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115070 mov r1, #4
 *   @0x115074 str r0, [sp, #0xc]
 *   @0x115078 mov r0, r4
 *   @0x11507c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115080 mov r1, #5
 *   @0x115084 str r0, [sp, #0x8]
 *   @0x115088 mov r0, r4
 *   @0x11508c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115090 ldr r3, [pc, #0x90]
 *   @0x115094 mvn r2, #0
 *   @0x115098 str r2, [sp, #0x24]
 *   @0x11509c add r3, pc, r3
 *   @0x1150a0 ldrb r3, [r3]
 *   @0x1150a4 cmp r3, #0
 *   @0x1150a8 str r0, [sp, #0x4]
 *   @0x1150ac add r0, sp, #4
 *   @0x1150b0 beq 0x1150f4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x1150b4 bl 0xb6808 <mktime64@plt>
 *   @0x1150b8 mov r4, r0
 *   @0x1150bc cmn r4, #1
 *   @0x1150c0 beq 0x115104 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1150c4 vmov.f64 d4, #5.000000e-01
 *   @0x1150c8 vldr d5, [pc, #72]
 *   @0x1150cc vmov s7, r4
 *   @0x1150d0 vldr d7, [pc, #72]
 *   @0x1150d4 vcvt.f64.s32 d6, s7
 *   @0x1150d8 vadd.f64 d6, d6, d4
 *   @0x1150dc vdiv.f64 d6, d6, d5
 *   @0x1150e0 vadd.f64 d5, d6, d7
 *   @0x1150e4 vmov r2, r3, d5
 *   @0x1150e8 stm r5, {r2, r3}
 *   @0x1150ec add sp, sp, #52
 *   @0x1150f0 pop {r4, r5, pc}
 *   @0x1150f4 bl 0xb6814 <timegm64@plt>
 *   @0x1150f8 mov r4, r0
 *   @0x1150fc cmn r4, #1
 *   @0x115100 bne 0x1150c4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x115104 ldr r0, [pc, #0x20]
 *   @0x115108 add r0, pc, r0
 *   @0x11510c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x115110 b 0x1150c4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x115114 nop
 *   @0x115118 andeq r0, r0, r0
 *   @0x11511c rscsmi r1, r5, r0, lsl #16
 *   @0x115120 andeq r0, r0, r0
 *   @0x115124 sbcsmi pc, r8, r0, asr #16
 *   @0x115128 mlaeq sp, r12, r0, sp
 *   @0x11512c eoreq r4, r2, r4, asr r6
 *
 * ══ §73/87 F_DateIsToday(RValue&, CInstance*, CInstance*, int, RValue*)  0x117108  size 336  84 条（0x117108..0x117258）
 * @func 0x117108 0x117258  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6820×2 / 0xb682c×2 / YYGetReal(RValue const*, int) / __fixdfdi / 0xb67fc / 0x827efc
 * 字段偏移 top8: 0x14×3 / 0x4×2 / 0x10×2 / 0x1c×2 / 0xc×1 / 0x28×1 / 0xe4×1 / 0xa4×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117108 push {r4, r5, r6, r7, lr}
 *   @0x11710c sub sp, sp, #20
 *   @0x117110 mov r3, #0
 *   @0x117114 mov r4, r0
 *   @0x117118 str r3, [r0, #0xc]
 *   @0x11711c mov r1, r3
 *   @0x117120 str r3, [r0]
 *   @0x117124 str r3, [r0, #0x4]
 *   @0x117128 ldr r0, [sp, #0x28]
 *   @0x11712c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x117130 vldr d7, [pc, #256]
 *   @0x117134 vldr d5, [pc, #260]
 *   @0x117138 vmov d6, r0, r1
 *   @0x11713c vsub.f64 d7, d6, d7
 *   @0x117140 vabs.f64 d4, d7
 *   @0x117144 vcmpe.f64 d4, d5
 *   @0x117148 vmrs APSR_nzcv, fpscr
 *   @0x11714c vldrls d7, [pc, #244]
 *   @0x117150 vldrhi d6, [pc, #240]
 *   @0x117154 vmul.f64 d5, d7, d6
 *   @0x117158 vmov r0, r1, d5
 *   @0x11715c bl 0x3194a0 <__fixdfdi>
 *   @0x117160 mov r3, r1
 *   @0x117164 ldr r1, [pc, #0xe4]
 *   @0x117168 mov r2, r0
 *   @0x11716c strd r2, r3, [sp]
 *   @0x117170 add r1, pc, r1
 *   @0x117174 mov r0, sp
 *   @0x117178 ldrb r3, [r1]
 *   @0x11717c cmp r3, #0
 *   @0x117180 bne 0x117228 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x117184 bl 0xb6820 <gmtime64@plt>
 *   @0x117188 mov r3, r0
 *   @0x11718c cmp r3, #0
 *   @0x117190 beq 0x1171e8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x117194 mov r0, #0
 *   @0x117198 ldr r6, [r3, #0x10]
 *   @0x11719c ldr r5, [r3, #0x14]
 *   @0x1171a0 ldr r7, [r3, #0x1c]
 *   @0x1171a4 bl 0xb67fc <time@plt>
 *   @0x1171a8 ldr r3, [pc, #0xa4]
 *   @0x1171ac add r3, pc, r3
 *   @0x1171b0 ldrb r3, [r3]
 *   @0x1171b4 cmp r3, #0
 *   @0x1171b8 asr r1, r0, #31
 *   @0x1171bc strd r0, r1, [sp, #8]
 *   @0x1171c0 add r0, sp, #8
 *   @0x1171c4 bne 0x1171f0 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x1171c8 bl 0xb6820 <gmtime64@plt>
 *   @0x1171cc ldr r3, [r0, #0x14]
 *   @0x1171d0 cmp r3, r5
 *   @0x1171d4 beq 0x117200 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1171d8 mov r3, #0
 *   @0x1171dc mov r2, r3
 *   @0x1171e0 str r3, [r4]
 *   @0x1171e4 str r2, [r4, #0x4]
 *   @0x1171e8 add sp, sp, #20
 *   @0x1171ec pop {r4, r5, r6, r7, pc}
 *   @0x1171f0 bl 0xb682c <localtime64@plt>
 *   @0x1171f4 ldr r3, [r0, #0x14]
 *   @0x1171f8 cmp r3, r5
 *   @0x1171fc bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x117200 ldr r3, [r0, #0x10]
 *   @0x117204 cmp r3, r6
 *   @0x117208 bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x11720c ldr r3, [r0, #0x1c]
 *   @0x117210 cmp r3, r7
 *   @0x117214 bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x117218 mov r2, #0
 *   @0x11721c mov r3, #0
 *   @0x117220 movt r2, #0x3ff0
 *   @0x117224 b 0x1171e0 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x117228 bl 0xb682c <localtime64@plt>
 *   @0x11722c mov r3, r0
 *   @0x117230 b 0x11718c <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x117234 nop
 *   @0x117238 andeq r0, r0, r0
 *   @0x11723c sbcsmi pc, r8, r0, asr #16
 *   @0x117240 bl 0x827efc <b2_toiTime+0xcea58>
 *   @0x117244 svclo #0x1a36e2
 *   @0x117248 andeq r0, r0, r0
 *   @0x11724c rscsmi r1, r5, r0, lsl #16
 *   @0x117250 eoreq r10, sp, r8, asr #31
 *   @0x117254 eoreq r10, sp, r12, lsl #31
 *
 * ══ §74/87 F_FontGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)  0x12136c  size 336  84 条（0x12136c..0x1214bc）
 * @func 0x12136c 0x1214bc  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)×2 / YYGetInt32(RValue const*, int) / Font_Exists(int) / Font_Data(int) / CFontGM::GetTexture() / F_FontGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)+0x58
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0xfc×1 / 0xb8×1 / 0x4×1 / 0x2×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12136c push {r4, r5, r6, lr}
 *   @0x121370 sub sp, sp, #24
 *   @0x121374 mov r1, #0
 *   @0x121378 mov r6, r0
 *   @0x12137c ldr r0, [sp, #0x28]
 *   @0x121380 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121384 mov r4, r0
 *   @0x121388 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x12138c subs r1, r0, #0
 *   @0x121390 beq 0x1213f8 <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x121394 mov r3, #0
 *   @0x121398 mov r0, r4
 *   @0x12139c str r3, [r6, #0xc]
 *   @0x1213a0 bl 0xfa3fc <_Z9Font_Datai>
 *   @0x1213a4 bl 0xf94e4 <_ZN7CFontGM10GetTextureEv>
 *   @0x1213a8 subs r2, r0, #0
 *   @0x1213ac blt 0x1213c4 <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1213b0 ldr r3, [pc, #0xfc]
 *   @0x1213b4 ldr r3, [pc, r3]
 *   @0x1213b8 ldr r1, [r3]
 *   @0x1213bc cmp r2, r1
 *   @0x1213c0 bgt 0x12140c <_Z15F_FontGetBaseUVR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1213c4 mov r4, #0
 *   @0x1213c8 mov r2, #0
 *   @0x1213cc mov r3, #0
 *   @0x1213d0 mov r0, r6
 *   @0x1213d4 mov r1, #4
 *   @0x1213d8 strd r2, r3, [sp]
 *   @0x1213dc mov r5, #0
 *   @0x1213e0 movt r5, #0x3ff0
 *   @0x1213e4 strd r4, r5, [sp, #8]
 *   @0x1213e8 strd r4, r5, [sp, #16]
 *   @0x1213ec bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1213f0 add sp, sp, #24
 *   @0x1213f4 pop {r4, r5, r6, pc}
 *   @0x1213f8 ldr r0, [pc, #0xb8]
 *   @0x1213fc add r0, pc, r0
 *   @0x121400 add sp, sp, #24
 *   @0x121404 pop {r4, r5, r6, lr}
 *   @0x121408 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12140c ldrsh r4, [r2, #20]
 *   @0x121410 vmov.f32 s13, #1.000000e+00
 *   @0x121414 ldr r3, [r3, #0x4]
 *   @0x121418 mov r0, r6
 *   @0x12141c ldrsh r12, [r2, #2]
 *   @0x121420 mov r1, #4
 *   @0x121424 ldrsh lr, [r2]
 *   @0x121428 ldr r3, [r3, r4, lsl #2]
 *   @0x12142c vmov s12, r12
 *   @0x121430 ldr r3, [r3]
 *   @0x121434 vldr s15, [r3, #8]
 *   @0x121438 vldr s9, [r3, #4]
 *   @0x12143c vcvt.f32.s32 s15, s15
 *   @0x121440 vdiv.f32 s15, s13, s15
 *   @0x121444 vcvt.f32.s32 s9, s9
 *   @0x121448 vcvt.f32.s32 s10, s12
 *   @0x12144c vdiv.f32 s9, s13, s9
 *   @0x121450 vmov s13, lr
 *   @0x121454 vmul.f32 s10, s10, s15
 *   @0x121458 vcvt.f64.f32 d5, s10
 *   @0x12145c vstr d5, [sp]
 *   @0x121460 ldrsh r3, [r2, #12]
 *   @0x121464 vcvt.f32.s32 s14, s13
 *   @0x121468 add r3, lr, r3
 *   @0x12146c vmov s12, r3
 *   @0x121470 vcvt.f32.s32 s12, s12
 *   @0x121474 vmul.f32 s12, s12, s9
 *   @0x121478 vcvt.f64.f32 d6, s12
 *   @0x12147c vstr d6, [sp, #8]
 *   @0x121480 ldrsh r3, [r2, #14]
 *   @0x121484 vmul.f32 s9, s14, s9
 *   @0x121488 add r3, r12, r3
 *   @0x12148c vmov s14, r3
 *   @0x121490 vcvt.f32.s32 s14, s14
 *   @0x121494 vmul.f32 s14, s14, s15
 *   @0x121498 vcvt.f64.f32 d6, s9
 *   @0x12149c vcvt.f64.f32 d7, s14
 *   @0x1214a0 vmov r2, r3, d6
 *   @0x1214a4 vstr d7, [sp, #16]
 *   @0x1214a8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1214ac add sp, sp, #24
 *   @0x1214b0 pop {r4, r5, r6, pc}
 *   @0x1214b4 eoreq r12, r12, r8, ror #10
 *   @0x1214b8 eoreq r8, r1, r8, lsr #27
 *
 * ══ §75/87 F_RoomTileAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e8f8  size 336  84 条（0x12e8f8..0x12ea48）
 * @func 0x12e8f8 0x12ea48  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / Background_Exists(int) / Room_Data(int) / CRoom::AddTileToStorage(int, int, int, int, int, int, int, int, float, float, unsigned int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x20×2 / 0x24×2 / 0xc×2 / 0x50×1 / 0x4×1 / 0x8×1 / 0x1c×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e8f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12e8fc sub sp, sp, #44
 *   @0x12e900 mov r1, #0
 *   @0x12e904 mov r5, r0
 *   @0x12e908 ldr r4, [sp, #0x50]
 *   @0x12e90c mov r0, r4
 *   @0x12e910 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e914 mov r1, #1
 *   @0x12e918 mov r6, r0
 *   @0x12e91c mov r0, r4
 *   @0x12e920 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e924 mov r7, r0
 *   @0x12e928 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x12e92c subs r1, r0, #0
 *   @0x12e930 beq 0x12ea08 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x12e934 mov r0, r6
 *   @0x12e938 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e93c subs r6, r0, #0
 *   @0x12e940 beq 0x12ea34 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x12e944 mov r1, #2
 *   @0x12e948 mov r0, r4
 *   @0x12e94c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e950 mov r1, #3
 *   @0x12e954 mov r2, r0
 *   @0x12e958 mov r0, r4
 *   @0x12e95c str r2, [sp, #0x20]
 *   @0x12e960 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e964 mov r1, #4
 *   @0x12e968 mov r10, r0
 *   @0x12e96c mov r0, r4
 *   @0x12e970 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e974 mov r1, #5
 *   @0x12e978 mov r3, r0
 *   @0x12e97c mov r0, r4
 *   @0x12e980 str r3, [sp, #0x24]
 *   @0x12e984 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e988 mov r1, #6
 *   @0x12e98c mov r11, r0
 *   @0x12e990 mov r0, r4
 *   @0x12e994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e998 mov r1, #7
 *   @0x12e99c mov r9, r0
 *   @0x12e9a0 mov r0, r4
 *   @0x12e9a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e9a8 mov r1, #8
 *   @0x12e9ac mov r8, r0
 *   @0x12e9b0 mov r0, r4
 *   @0x12e9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e9b8 ldr r3, [sp, #0x24]
 *   @0x12e9bc mov r12, #1065353216
 *   @0x12e9c0 ldr r2, [sp, #0x20]
 *   @0x12e9c4 mvn lr, #0
 *   @0x12e9c8 str r11, [sp, #0x4]
 *   @0x12e9cc str r3, [sp]
 *   @0x12e9d0 mov r1, r7
 *   @0x12e9d4 mov r3, r10
 *   @0x12e9d8 str r9, [sp, #0x8]
 *   @0x12e9dc str r8, [sp, #0xc]
 *   @0x12e9e0 str lr, [sp, #0x1c]
 *   @0x12e9e4 str r12, [sp, #0x14]
 *   @0x12e9e8 str r12, [sp, #0x18]
 *   @0x12e9ec str r0, [sp, #0x10]
 *   @0x12e9f0 mov r0, r6
 *   @0x12e9f4 bl 0x1aaf78 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj>
 *   @0x12e9f8 vmov s15, r0
 *   @0x12e9fc vcvt.f64.s32 d7, s15
 *   @0x12ea00 vmov r2, r3, d7
 *   @0x12ea04 b 0x12ea20 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x12ea08 ldr r0, [pc, #0x34]
 *   @0x12ea0c add r0, pc, r0
 *   @0x12ea10 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12ea14 mov r3, #0
 *   @0x12ea18 movt r3, #0xbff0
 *   @0x12ea1c mov r2, #0
 *   @0x12ea20 mov r1, #0
 *   @0x12ea24 stm r5, {r2, r3}
 *   @0x12ea28 str r1, [r5, #0xc]
 *   @0x12ea2c add sp, sp, #44
 *   @0x12ea30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12ea34 mov r3, #0
 *   @0x12ea38 mov r2, #0
 *   @0x12ea3c movt r3, #0xbff0
 *   @0x12ea40 b 0x12ea20 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x12ea44 eoreq r11, r0, r12, asr #11
 *
 * ══ §76/87 F_D3DMatrixTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1498e4  size 336  84 条（0x1498e4..0x149a34）
 * @func 0x1498e4 0x149a34  size 336  84 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Error_Show_Action(char const*, bool) / REAL_RValue_Ex(RValue const*) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x78×1 / 0x124×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1498e4 push {r4, r5, r6, r7, lr}
 *   @0x1498e8 vpush {d8, d9}
 *   @0x1498ec sub sp, sp, #84
 *   @0x1498f0 mov r7, r0
 *   @0x1498f4 ldr r4, [sp, #0x78]
 *   @0x1498f8 ldr r5, [r4, #0xc]
 *   @0x1498fc cmp r5, #2
 *   @0x149900 beq 0x149920 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x149904 ldr r0, [pc, #0x124]
 *   @0x149908 mov r1, #1
 *   @0x14990c add r0, pc, r0
 *   @0x149910 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149914 add sp, sp, #84
 *   @0x149918 vpop {d8, d9}
 *   @0x14991c pop {r4, r5, r6, r7, pc}
 *   @0x149920 mov r0, r4
 *   @0x149924 mov r1, #1
 *   @0x149928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14992c mov r1, r5
 *   @0x149930 add r6, sp, #80
 *   @0x149934 add r5, sp, #16
 *   @0x149938 vmov s17, r0
 *   @0x14993c mov r0, r4
 *   @0x149940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149944 mov r1, #3
 *   @0x149948 vmov s18, r0
 *   @0x14994c mov r0, r4
 *   @0x149950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149954 ldr r3, [r4]
 *   @0x149958 ldr r3, [r3, #0x4]
 *   @0x14995c ldr r4, [r3, #0x4]
 *   @0x149960 vmov s16, r0
 *   @0x149964 b 0x149984 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x149968 ldm r4, {r0, r1}
 *   @0x14996c vmov d6, r0, r1
 *   @0x149970 add r4, r4, #16
 *   @0x149974 vcvt.f32.f64 s15, d6
 *   @0x149978 vstmia r5!, {s15}
 *   @0x14997c cmp r5, r6
 *   @0x149980 beq 0x1499a0 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x149984 ldr r3, [r4, #0xc]
 *   @0x149988 bic r3, r3, #-16777216
 *   @0x14998c cmp r3, #0
 *   @0x149990 beq 0x149968 <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x149994 mov r0, r4
 *   @0x149998 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x14999c b 0x14996c <_Z26F_D3DMatrixTransformVertexR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1499a0 vldr s14, [sp, #40]
 *   @0x1499a4 vmul.f32 s14, s18, s14
 *   @0x1499a8 vldr s13, [sp, #36]
 *   @0x1499ac vldr s15, [sp, #32]
 *   @0x1499b0 vldr s5, [sp, #24]
 *   @0x1499b4 vldr s4, [sp, #20]
 *   @0x1499b8 vldr s6, [sp, #16]
 *   @0x1499bc vldr s8, [sp, #56]
 *   @0x1499c0 vldr s7, [sp, #52]
 *   @0x1499c4 vldr s9, [sp, #48]
 *   @0x1499c8 vldr s10, [sp, #72]
 *   @0x1499cc vldr s12, [sp, #68]
 *   @0x1499d0 vldr s11, [sp, #64]
 *   @0x1499d4 mov r0, r7
 *   @0x1499d8 mov r1, #3
 *   @0x1499dc vmul.f32 s13, s18, s13
 *   @0x1499e0 vmul.f32 s15, s18, s15
 *   @0x1499e4 vmla.f32 s14, s17, s5
 *   @0x1499e8 vmla.f32 s13, s17, s4
 *   @0x1499ec vmla.f32 s15, s17, s6
 *   @0x1499f0 vmla.f32 s14, s16, s8
 *   @0x1499f4 vmla.f32 s15, s16, s9
 *   @0x1499f8 vmla.f32 s13, s16, s7
 *   @0x1499fc vadd.f32 s14, s14, s10
 *   @0x149a00 vadd.f32 s11, s15, s11
 *   @0x149a04 vadd.f32 s13, s13, s12
 *   @0x149a08 vcvt.f64.f32 d7, s14
 *   @0x149a0c vcvt.f64.f32 d6, s13
 *   @0x149a10 vstr d7, [sp, #8]
 *   @0x149a14 vcvt.f64.f32 d7, s11
 *   @0x149a18 vstr d6, [sp]
 *   @0x149a1c vmov r2, r3, d7
 *   @0x149a20 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x149a24 add sp, sp, #84
 *   @0x149a28 vpop {d8, d9}
 *   @0x149a2c pop {r4, r5, r6, r7, pc}
 *   @0x149a30 andseq r9, pc, r0, lsr #1
 *
 * ══ §77/87 IBuffer::SaveToFileInMemory(char**, int*, int, int, int)  0xcd660  size 332  83 条（0xcd660..0xcd7ac）
 * @func 0xcd660 0xcd7ac  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65bc×2 / IBuffer::SaveToFileInMemory(char**, int*, int, int, int)+0xa8 / IBuffer::SaveToFileInMemory(char**, int*, int, int, int)+0x12c / IBuffer::SaveToFileInMemory(char**, int*, int, int, int)+0x80
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x28×1 / 0x2c×1 / 0xe8×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd660 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcd664 subs r10, r1, #0
 *   @0xcd668 mov r11, r0
 *   @0xcd66c mov r9, r2
 *   @0xcd670 mov r4, r3
 *   @0xcd674 ldr r8, [sp, #0x28]
 *   @0xcd678 beq 0xcd794 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x134>
 *   @0xcd67c cmp r2, #0
 *   @0xcd680 beq 0xcd79c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x13c>
 *   @0xcd684 ldr r3, [sp, #0x2c]
 *   @0xcd688 cmp r3, #0
 *   @0xcd68c ldr r3, [r0, #0x10]
 *   @0xcd690 bne 0xcd6f0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x90>
 *   @0xcd694 bic r4, r4, r4, asr #31
 *   @0xcd698 cmp r3, r4
 *   @0xcd69c suble r4, r3, #1
 *   @0xcd6a0 cmp r8, #0
 *   @0xcd6a4 movlt r8, r3
 *   @0xcd6a8 add r2, r4, r8
 *   @0xcd6ac cmp r3, r2
 *   @0xcd6b0 rsblt r8, r4, r3
 *   @0xcd6b4 ldr r1, [pc, #0xe8]
 *   @0xcd6b8 mov r2, #1808
 *   @0xcd6bc mov r0, r8
 *   @0xcd6c0 mov r3, #1
 *   @0xcd6c4 add r1, pc, r1
 *   @0xcd6c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcd6cc ldr r1, [r11, #0xc]
 *   @0xcd6d0 mov r2, r8
 *   @0xcd6d4 add r1, r1, r4
 *   @0xcd6d8 mov r7, r0
 *   @0xcd6dc bl 0xb65bc <memcpy@plt>
 *   @0xcd6e0 str r7, [r10]
 *   @0xcd6e4 mov r0, #1
 *   @0xcd6e8 str r8, [r9]
 *   @0xcd6ec pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd6f0 cmp r4, #0
 *   @0xcd6f4 bge 0xcd70c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xac>
 *   @0xcd6f8 adds r4, r4, r3
 *   @0xcd6fc bmi 0xcd6f8 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x98>
 *   @0xcd700 cmp r3, r4
 *   @0xcd704 bgt 0xcd714 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xb4>
 *   @0xcd708 rsb r4, r3, r4
 *   @0xcd70c cmp r3, r4
 *   @0xcd710 ble 0xcd708 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xa8>
 *   @0xcd714 cmp r8, #0
 *   @0xcd718 blt 0xcd78c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x12c>
 *   @0xcd71c cmp r3, r8
 *   @0xcd720 bgt 0xcd6b4 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x54>
 *   @0xcd724 ldr r1, [pc, #0x7c]
 *   @0xcd728 mov r0, r8
 *   @0xcd72c mov r2, #1808
 *   @0xcd730 mov r3, #1
 *   @0xcd734 add r1, pc, r1
 *   @0xcd738 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcd73c cmp r8, #0
 *   @0xcd740 mov r7, r0
 *   @0xcd744 ble 0xcd6e0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x80>
 *   @0xcd748 mov r5, r8
 *   @0xcd74c mov r6, #0
 *   @0xcd750 ldr r3, [r11, #0x10]
 *   @0xcd754 add r0, r7, r6
 *   @0xcd758 ldr r1, [r11, #0xc]
 *   @0xcd75c rsb r3, r4, r3
 *   @0xcd760 cmp r3, r5
 *   @0xcd764 movge r3, r5
 *   @0xcd768 add r1, r1, r4
 *   @0xcd76c rsb r5, r3, r5
 *   @0xcd770 mov r4, #0
 *   @0xcd774 mov r2, r3
 *   @0xcd778 add r6, r6, r3
 *   @0xcd77c bl 0xb65bc <memcpy@plt>
 *   @0xcd780 cmp r5, r4
 *   @0xcd784 bgt 0xcd750 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xf0>
 *   @0xcd788 b 0xcd6e0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x80>
 *   @0xcd78c mov r8, r3
 *   @0xcd790 b 0xcd724 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xc4>
 *   @0xcd794 mov r0, r10
 *   @0xcd798 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd79c mov r0, r2
 *   @0xcd7a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd7a4 eoreq r4, r6, r12, lsr #21
 *   @0xcd7a8 eoreq r4, r6, r12, lsr r10
 *
 * ══ §78/87 Code_CreateEntry(unsigned int, bool)  0xcf324  size 332  83 条（0xcf324..0xcf470）
 * @func 0xcf324 0xcf470  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CCode::CCode(int, bool) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x11c×1 / 0x118×1 / 0x114×1 / 0xf8×1 / 0xe8×1 / 0x2×1 / 0x70×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcf324 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcf328 mov r8, r0
 *   @0xcf32c ldr r4, [pc, #0x11c]
 *   @0xcf330 sub sp, sp, #8
 *   @0xcf334 ldr r3, [pc, #0x118]
 *   @0xcf338 mov r9, r1
 *   @0xcf33c ldr r2, [pc, #0x114]
 *   @0xcf340 add r4, pc, r4
 *   @0xcf344 ldr r7, [r4, r3]
 *   @0xcf348 ldr r5, [r4, r2]
 *   @0xcf34c ldr r3, [r7]
 *   @0xcf350 ldr r2, [r5]
 *   @0xcf354 cmp r2, r3
 *   @0xcf358 bge 0xcf3c8 <_Z16Code_CreateEntryjb+0xa4>
 *   @0xcf35c ldr r3, [pc, #0xf8]
 *   @0xcf360 ldr r6, [r4, r3]
 *   @0xcf364 ldr r12, [r6]
 *   @0xcf368 cmp r12, #0
 *   @0xcf36c beq 0xcf420 <_Z16Code_CreateEntryjb+0xfc>
 *   @0xcf370 ldr r3, [pc, #0xe8]
 *   @0xcf374 ldr r3, [r4, r3]
 *   @0xcf378 ldrb r3, [r3]
 *   @0xcf37c cmp r3, #0
 *   @0xcf380 beq 0xcf42c <_Z16Code_CreateEntryjb+0x108>
 *   @0xcf384 cmn r8, #1
 *   @0xcf388 moveq r4, #0
 *   @0xcf38c beq 0xcf3ac <_Z16Code_CreateEntryjb+0x88>
 *   @0xcf390 mov r0, #124
 *   @0xcf394 bl 0x27c524 <_Znwj>
 *   @0xcf398 mov r1, r8
 *   @0xcf39c mov r2, r9
 *   @0xcf3a0 mov r4, r0
 *   @0xcf3a4 bl 0xcefc8 <_ZN5CCodeC2Eib>
 *   @0xcf3a8 ldr r12, [r6]
 *   @0xcf3ac ldr r3, [r5]
 *   @0xcf3b0 add r2, r3, #1
 *   @0xcf3b4 str r4, [r12, r3, lsl #2]
 *   @0xcf3b8 mov r0, r3
 *   @0xcf3bc str r2, [r5]
 *   @0xcf3c0 add sp, sp, #8
 *   @0xcf3c4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf3c8 add r3, r3, r3, lsl #1
 *   @0xcf3cc add r10, r3, #1
 *   @0xcf3d0 add r10, r10, r10, lsr #31
 *   @0xcf3d4 asrs r10, r10, #1
 *   @0xcf3d8 ldreq r3, [pc, #0x84]
 *   @0xcf3dc ldreq r3, [r4, r3]
 *   @0xcf3e0 ldreq r10, [r3]
 *   @0xcf3e4 ldr r0, [pc, #0x70]
 *   @0xcf3e8 mov r12, #0
 *   @0xcf3ec ldr r2, [pc, #0x74]
 *   @0xcf3f0 lsl r1, r10, #2
 *   @0xcf3f4 mov r3, #74
 *   @0xcf3f8 ldr r6, [r4, r0]
 *   @0xcf3fc add r2, pc, r2
 *   @0xcf400 ldr r0, [r6]
 *   @0xcf404 str r12, [sp]
 *   @0xcf408 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xcf40c str r10, [r7]
 *   @0xcf410 mov r12, r0
 *   @0xcf414 cmp r12, #0
 *   @0xcf418 str r0, [r6]
 *   @0xcf41c bne 0xcf370 <_Z16Code_CreateEntryjb+0x4c>
 *   @0xcf420 mov r0, r12
 *   @0xcf424 add sp, sp, #8
 *   @0xcf428 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf42c ldr r3, [pc, #0x38]
 *   @0xcf430 ldr r3, [r4, r3]
 *   @0xcf434 ldrb r4, [r3]
 *   @0xcf438 cmp r4, #0
 *   @0xcf43c beq 0xcf3ac <_Z16Code_CreateEntryjb+0x88>
 *   @0xcf440 cmn r8, #1
 *   @0xcf444 moveq r4, #0
 *   @0xcf448 bne 0xcf390 <_Z16Code_CreateEntryjb+0x6c>
 *   @0xcf44c b 0xcf3ac <_Z16Code_CreateEntryjb+0x88>
 *   @0xcf450 eorseq r2, r2, r0, lsl r9
 *   @0xcf454 .word 0xffffbf0c
 *   @0xcf458 .word 0xffffbee4
 *   @0xcf45c .word 0xffffbee8
 *   @0xcf460 .word 0xffffbf10
 *   @0xcf464 .word 0xffffbef4
 *   @0xcf468 eoreq r1, r6, r4, lsr r12
 *   @0xcf46c .word 0xffffbecc
 *
 * ══ §79/87 F_DsMapReplaceList(RValue&, CInstance*, CInstance*, int, RValue*)  0xff564  size 332  83 条（0xff564..0xff6b0）
 * @func 0xff564 0xff6b0  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Error_Show_Action(char const*, bool)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / F_DsMapReplaceList(RValue&, CInstance*, CInstance*, int, RValue*)+0xf0 / F_DsMapReplaceList(RValue&, CInstance*, CInstance*, int, RValue*)+0x110 / CDS_Map::Replace(RValue*, RValue*)
 * 字段偏移 top8: 0x4×4 / 0x2×3 / 0x2c×2 / 0x28×1 / 0x10c×1 / 0xc×1 / 0xe4×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff564 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xff568 sub sp, sp, #8
 *   @0xff56c add r7, sp, #4
 *   @0xff570 mov r5, r0
 *   @0xff574 ldr r8, [sp, #0x28]
 *   @0xff578 mov r4, #0
 *   @0xff57c mov r0, r7
 *   @0xff580 ldr r6, [pc, #0x10c]
 *   @0xff584 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff588 str r4, [r5, #0xc]
 *   @0xff58c str r4, [r5]
 *   @0xff590 mov r0, r8
 *   @0xff594 str r4, [r5, #0x4]
 *   @0xff598 mov r1, r4
 *   @0xff59c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff5a0 add r6, pc, r6
 *   @0xff5a4 subs r9, r0, #0
 *   @0xff5a8 blt 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0xff5ac ldr r3, [pc, #0xe4]
 *   @0xff5b0 ldr r3, [r6, r3]
 *   @0xff5b4 ldr r3, [r3]
 *   @0xff5b8 cmp r9, r3
 *   @0xff5bc bge 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0xff5c0 ldr r3, [pc, #0xd4]
 *   @0xff5c4 ldr r10, [r6, r3]
 *   @0xff5c8 ldr r3, [r10, #0x4]
 *   @0xff5cc ldr r3, [r3, r9, lsl #2]
 *   @0xff5d0 cmp r3, r4
 *   @0xff5d4 beq 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0xff5d8 mov r0, r8
 *   @0xff5dc mov r1, #2
 *   @0xff5e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff5e4 cmp r0, #0
 *   @0xff5e8 blt 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0xff5ec ldr r3, [pc, #0xac]
 *   @0xff5f0 ldr r3, [r6, r3]
 *   @0xff5f4 ldr r3, [r3]
 *   @0xff5f8 cmp r0, r3
 *   @0xff5fc bge 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0xff600 ldr r3, [pc, #0x9c]
 *   @0xff604 ldr r3, [r6, r3]
 *   @0xff608 ldr r3, [r3, #0x4]
 *   @0xff60c ldr r3, [r3, r0, lsl #2]
 *   @0xff610 cmp r3, #0
 *   @0xff614 beq 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0xff618 ldr r3, [r8, #0x2c]
 *   @0xff61c add r1, r8, #16
 *   @0xff620 ldr r0, [r10, #0x4]
 *   @0xff624 add r2, r8, #32
 *   @0xff628 bic r3, r3, #-268435456
 *   @0xff62c orr r3, r3, #1073741824
 *   @0xff630 ldr r0, [r0, r9, lsl #2]
 *   @0xff634 str r3, [r8, #0x2c]
 *   @0xff638 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_>
 *   @0xff63c cmp r0, #0
 *   @0xff640 movne r3, #0
 *   @0xff644 strne r4, [r5]
 *   @0xff648 movtne r3, #0x3ff0
 *   @0xff64c strne r3, [r5, #0x4]
 *   @0xff650 b 0xff664 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0xff654 ldr r0, [pc, #0x4c]
 *   @0xff658 mov r1, #0
 *   @0xff65c add r0, pc, r0
 *   @0xff660 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff664 mov r0, r7
 *   @0xff668 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff66c add sp, sp, #8
 *   @0xff670 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff674 ldr r0, [pc, #0x30]
 *   @0xff678 mov r1, #0
 *   @0xff67c add r0, pc, r0
 *   @0xff680 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff684 mov r0, r7
 *   @0xff688 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff68c add sp, sp, #8
 *   @0xff690 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff694 .word 0x002f26b0
 *   @0xff698 .word 0xffffc028
 *   @0xff69c .word 0xffffbcec
 *   @0xff6a0 .word 0xffffc02c
 *   @0xff6a4 .word 0xffffc030
 *   @0xff6a8 eoreq r8, r3, r0, lsr #11
 *   @0xff6ac eoreq r8, r3, r12, ror #11
 *
 * ══ §80/87 F_StringLower(RValue&, CInstance*, CInstance*, int, RValue*)  0x1103b0  size 332  83 条（0x1103b0..0x1104fc）
 * @func 0x1103b0 0x110510  size 352  88 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb679c×2 / utf8_extract_char×2 / 0xb67a8×2 / 0xb67b4×2 / YYGetString(RValue const*, int) / utf8_char_size / MemoryManager::Alloc(unsigned int, char const*, int, bool) / utf8_add_char
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x120×1 / 0xb4×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1103b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1103b4 sub sp, sp, #8
 *   @0x1103b8 mov r1, #0
 *   @0x1103bc mov r7, r0
 *   @0x1103c0 ldr r0, [sp, #0x20]
 *   @0x1103c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1103c8 ldr r1, [pc, #0x120]
 *   @0x1103cc add r1, pc, r1
 *   @0x1103d0 mov r8, r0
 *   @0x1103d4 mov r0, #6
 *   @0x1103d8 bl 0xb679c <setlocale@plt>
 *   @0x1103dc str r8, [sp]
 *   @0x1103e0 ldrb r3, [r8]
 *   @0x1103e4 cmp r3, #0
 *   @0x1103e8 beq 0x1104e0 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1103ec mov r6, #0
 *   @0x1103f0 mov r0, sp
 *   @0x1103f4 bl 0x10fb38 <utf8_extract_char>
 *   @0x1103f8 mov r4, r0
 *   @0x1103fc bl 0xb67a8 <iswupper@plt>
 *   @0x110400 mov r3, r4
 *   @0x110404 cmp r0, #0
 *   @0x110408 mov r0, r4
 *   @0x11040c beq 0x110418 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x110410 bl 0xb67b4 <towlower@plt>
 *   @0x110414 uxth r3, r0
 *   @0x110418 mov r0, r3
 *   @0x11041c bl 0x110390 <utf8_char_size>
 *   @0x110420 ldr r3, [sp]
 *   @0x110424 ldrb r3, [r3]
 *   @0x110428 cmp r3, #0
 *   @0x11042c add r6, r6, r0
 *   @0x110430 bne 0x1103f0 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x110434 add r0, r6, #1
 *   @0x110438 ldr r1, [pc, #0xb4]
 *   @0x11043c mov r3, #1
 *   @0x110440 movw r2, #0x7ec
 *   @0x110444 add r1, pc, r1
 *   @0x110448 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x11044c str r8, [sp]
 *   @0x110450 str r0, [sp, #0x4]
 *   @0x110454 mov r6, r0
 *   @0x110458 ldrb r3, [r8]
 *   @0x11045c cmp r3, #0
 *   @0x110460 beq 0x1104e8 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x110464 add r8, sp, #4
 *   @0x110468 mov r0, sp
 *   @0x11046c bl 0x10fb38 <utf8_extract_char>
 *   @0x110470 mov r4, r0
 *   @0x110474 bl 0xb67a8 <iswupper@plt>
 *   @0x110478 mov r1, r4
 *   @0x11047c cmp r0, #0
 *   @0x110480 mov r0, r4
 *   @0x110484 beq 0x110490 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x110488 bl 0xb67b4 <towlower@plt>
 *   @0x11048c uxth r1, r0
 *   @0x110490 mov r0, r8
 *   @0x110494 bl 0x10fe28 <utf8_add_char>
 *   @0x110498 ldr r3, [sp]
 *   @0x11049c ldrb r3, [r3]
 *   @0x1104a0 cmp r3, #0
 *   @0x1104a4 bne 0x110468 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1104a8 ldr r2, [sp, #0x4]
 *   @0x1104ac ldr r1, [pc, #0x44]
 *   @0x1104b0 mov r3, #0
 *   @0x1104b4 mov r0, #6
 *   @0x1104b8 strb r3, [r2]
 *   @0x1104bc add r1, pc, r1
 *   @0x1104c0 bl 0xb679c <setlocale@plt>
 *   @0x1104c4 mov r0, r7
 *   @0x1104c8 mov r1, r6
 *   @0x1104cc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1104d0 mov r0, r6
 *   @0x1104d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1104d8 add sp, sp, #8
 *   @0x1104dc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1104e0 mov r0, #1
 *   @0x1104e4 b 0x110438 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1104e8 mov r2, r0
 *   @0x1104ec b 0x1104ac <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1104f0 eoreq lr, r1, r10, ror #14
 *   @0x1104f4 eoreq r8, r2, r0, lsl #20
 *   @0x1104f8 eoreq r8, r2, r4, ror #23
 *
 * ══ §81/87 F_StringUpper(RValue&, CInstance*, CInstance*, int, RValue*)  0x1104fc  size 332  83 条（0x1104fc..0x110648）
 * @func 0x1104fc 0x110648  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb679c×2 / utf8_extract_char×2 / 0xb67c0×2 / 0xb67cc×2 / YYGetString(RValue const*, int) / utf8_char_size / MemoryManager::Alloc(unsigned int, char const*, int, bool) / utf8_add_char
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x120×1 / 0xb4×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1104fc push {r4, r5, r6, r7, r8, lr}
 *   @0x110500 sub sp, sp, #8
 *   @0x110504 mov r1, #0
 *   @0x110508 mov r7, r0
 *   @0x11050c ldr r0, [sp, #0x20]
 *   @0x110510 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110514 ldr r1, [pc, #0x120]
 *   @0x110518 add r1, pc, r1
 *   @0x11051c mov r8, r0
 *   @0x110520 mov r0, #6
 *   @0x110524 bl 0xb679c <setlocale@plt>
 *   @0x110528 str r8, [sp]
 *   @0x11052c ldrb r3, [r8]
 *   @0x110530 cmp r3, #0
 *   @0x110534 beq 0x11062c <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x110538 mov r6, #0
 *   @0x11053c mov r0, sp
 *   @0x110540 bl 0x10fb38 <utf8_extract_char>
 *   @0x110544 mov r4, r0
 *   @0x110548 bl 0xb67c0 <iswlower@plt>
 *   @0x11054c mov r3, r4
 *   @0x110550 cmp r0, #0
 *   @0x110554 mov r0, r4
 *   @0x110558 beq 0x110564 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x11055c bl 0xb67cc <towupper@plt>
 *   @0x110560 uxth r3, r0
 *   @0x110564 mov r0, r3
 *   @0x110568 bl 0x110390 <utf8_char_size>
 *   @0x11056c ldr r3, [sp]
 *   @0x110570 ldrb r3, [r3]
 *   @0x110574 cmp r3, #0
 *   @0x110578 add r6, r6, r0
 *   @0x11057c bne 0x11053c <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x110580 add r0, r6, #1
 *   @0x110584 ldr r1, [pc, #0xb4]
 *   @0x110588 mov r3, #1
 *   @0x11058c movw r2, #0x80b
 *   @0x110590 add r1, pc, r1
 *   @0x110594 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x110598 str r8, [sp]
 *   @0x11059c str r0, [sp, #0x4]
 *   @0x1105a0 mov r6, r0
 *   @0x1105a4 ldrb r3, [r8]
 *   @0x1105a8 cmp r3, #0
 *   @0x1105ac beq 0x110634 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1105b0 add r8, sp, #4
 *   @0x1105b4 mov r0, sp
 *   @0x1105b8 bl 0x10fb38 <utf8_extract_char>
 *   @0x1105bc mov r4, r0
 *   @0x1105c0 bl 0xb67c0 <iswlower@plt>
 *   @0x1105c4 mov r1, r4
 *   @0x1105c8 cmp r0, #0
 *   @0x1105cc mov r0, r4
 *   @0x1105d0 beq 0x1105dc <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x1105d4 bl 0xb67cc <towupper@plt>
 *   @0x1105d8 uxth r1, r0
 *   @0x1105dc mov r0, r8
 *   @0x1105e0 bl 0x10fe28 <utf8_add_char>
 *   @0x1105e4 ldr r3, [sp]
 *   @0x1105e8 ldrb r3, [r3]
 *   @0x1105ec cmp r3, #0
 *   @0x1105f0 bne 0x1105b4 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1105f4 ldr r2, [sp, #0x4]
 *   @0x1105f8 ldr r1, [pc, #0x44]
 *   @0x1105fc mov r3, #0
 *   @0x110600 mov r0, #6
 *   @0x110604 strb r3, [r2]
 *   @0x110608 add r1, pc, r1
 *   @0x11060c bl 0xb679c <setlocale@plt>
 *   @0x110610 mov r0, r7
 *   @0x110614 mov r1, r6
 *   @0x110618 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x11061c mov r0, r6
 *   @0x110620 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x110624 add sp, sp, #8
 *   @0x110628 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11062c mov r0, #1
 *   @0x110630 b 0x110584 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x110634 mov r2, r0
 *   @0x110638 b 0x1105f8 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x11063c eoreq lr, r1, lr, lsl r6
 *   @0x110640 .word 0x002288b4
 *   @0x110644 mlaeq r2, r8, r10, r8
 *
 * ══ §82/87 F_ExternalDefine4(RValue&, CInstance*, CInstance*, int, RValue*)  0x11625c  size 332  83 条（0x11625c..0x1163a8）
 * @func 0x11625c 0x1163a8  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / YYGetString(RValue const*, int)×2 / 0xb65b0 / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xc×3 / 0x80×1 / 0x4×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11625c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x116260 sub sp, sp, #92
 *   @0x116264 add r5, sp, #20
 *   @0x116268 mov r2, #68
 *   @0x11626c ldr r4, [sp, #0x80]
 *   @0x116270 mov r6, r0
 *   @0x116274 mov r1, #0
 *   @0x116278 mov r0, r5
 *   @0x11627c bl 0xb65b0 <memset@plt>
 *   @0x116280 mov r1, #0
 *   @0x116284 mov r0, r4
 *   @0x116288 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11628c mov r1, #1
 *   @0x116290 mov r3, r0
 *   @0x116294 mov r0, r4
 *   @0x116298 str r3, [sp, #0xc]
 *   @0x11629c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1162a0 mov r1, #2
 *   @0x1162a4 mov r11, r0
 *   @0x1162a8 mov r0, r4
 *   @0x1162ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1162b0 mov r1, #3
 *   @0x1162b4 mov r10, r0
 *   @0x1162b8 mov r0, r4
 *   @0x1162bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1162c0 mov r1, #4
 *   @0x1162c4 mov r9, r0
 *   @0x1162c8 mov r0, r4
 *   @0x1162cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1162d0 mov r1, #5
 *   @0x1162d4 mov r8, r0
 *   @0x1162d8 mov r0, r4
 *   @0x1162dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1162e0 mov r1, #6
 *   @0x1162e4 mov r7, r0
 *   @0x1162e8 mov r0, r4
 *   @0x1162ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1162f0 cmp r10, #1
 *   @0x1162f4 streq r10, [sp, #0x14]
 *   @0x1162f8 movne r2, #0
 *   @0x1162fc ldr r3, [sp, #0xc]
 *   @0x116300 str r5, [sp]
 *   @0x116304 strne r2, [sp, #0x14]
 *   @0x116308 cmp r9, #1
 *   @0x11630c streq r9, [sp, #0x18]
 *   @0x116310 movne r2, #0
 *   @0x116314 strne r2, [sp, #0x18]
 *   @0x116318 cmp r8, #1
 *   @0x11631c streq r8, [sp, #0x1c]
 *   @0x116320 movne r2, #0
 *   @0x116324 strne r2, [sp, #0x1c]
 *   @0x116328 cmp r7, #1
 *   @0x11632c streq r7, [sp, #0x20]
 *   @0x116330 mov r7, #0
 *   @0x116334 movne r2, #0
 *   @0x116338 strne r2, [sp, #0x20]
 *   @0x11633c subs r1, r0, #1
 *   @0x116340 mov r0, r3
 *   @0x116344 rsbs r2, r1, #0
 *   @0x116348 mov r3, #4
 *   @0x11634c adcs r2, r2, r1
 *   @0x116350 mov r1, r11
 *   @0x116354 str r2, [sp, #0x4]
 *   @0x116358 mov r2, r7
 *   @0x11635c str r7, [r6, #0xc]
 *   @0x116360 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x116364 vmov.f64 d7, #-1.000000e+00
 *   @0x116368 vmov s13, r0
 *   @0x11636c vcvt.f64.s32 d6, s13
 *   @0x116370 vmov r0, r1, d6
 *   @0x116374 vmov r2, s12
 *   @0x116378 vcmp.f64 d6, d7
 *   @0x11637c vmrs APSR_nzcv, fpscr
 *   @0x116380 mov r3, r1
 *   @0x116384 stm r6, {r2, r3}
 *   @0x116388 bne 0x11639c <_Z17F_ExternalDefine4R6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x11638c ldr r0, [pc, #0x10]
 *   @0x116390 mov r1, r7
 *   @0x116394 add r0, pc, r0
 *   @0x116398 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11639c add sp, sp, #92
 *   @0x1163a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1163a4 eoreq r3, r2, r12, lsl #6
 *
 * ══ §83/87 F_SkeletonDraw(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d430  size 332  83 条（0x11d430..0x11d57c）
 * @func 0x11d430 0x11d57c  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int)×2 / Sprite_Data(int) / CSkeletonSprite::Draw(char const*, char const*, int, float, float, float, float, float, unsigned int, float, CInstance*)
 * 字段偏移 top8: 0x58×2 / 0xc×2 / 0x4×2 / 0x2c×2 / 0x20×2 / 0x24×2 / 0x28×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d430 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11d434 sub sp, sp, #52
 *   @0x11d438 mov r3, #0
 *   @0x11d43c mov r5, r1
 *   @0x11d440 ldr r4, [sp, #0x58]
 *   @0x11d444 mov r2, r3
 *   @0x11d448 str r3, [r0, #0xc]
 *   @0x11d44c movt r2, #0xbff0
 *   @0x11d450 str r3, [r0]
 *   @0x11d454 mov r1, r3
 *   @0x11d458 str r2, [r0, #0x4]
 *   @0x11d45c mov r0, r4
 *   @0x11d460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d464 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11d468 subs r3, r0, #0
 *   @0x11d46c beq 0x11d47c <_Z14F_SkeletonDrawR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x11d470 ldr r6, [r3, #0x74]
 *   @0x11d474 cmp r6, #2
 *   @0x11d478 beq 0x11d484 <_Z14F_SkeletonDrawR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x11d47c add sp, sp, #52
 *   @0x11d480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d484 ldr r3, [r3, #0x58]
 *   @0x11d488 mov r0, r4
 *   @0x11d48c mov r1, #1
 *   @0x11d490 str r3, [sp, #0x2c]
 *   @0x11d494 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d498 mov r1, r6
 *   @0x11d49c mov r8, r0
 *   @0x11d4a0 mov r0, r4
 *   @0x11d4a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d4a8 mov r1, #3
 *   @0x11d4ac mov r7, r0
 *   @0x11d4b0 mov r0, r4
 *   @0x11d4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d4b8 mov r1, #4
 *   @0x11d4bc mov r6, r0
 *   @0x11d4c0 mov r0, r4
 *   @0x11d4c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d4c8 mov r1, #5
 *   @0x11d4cc mov r12, r0
 *   @0x11d4d0 mov r0, r4
 *   @0x11d4d4 str r12, [sp, #0x20]
 *   @0x11d4d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d4dc mov r1, #6
 *   @0x11d4e0 mov r2, r0
 *   @0x11d4e4 mov r0, r4
 *   @0x11d4e8 str r2, [sp, #0x24]
 *   @0x11d4ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d4f0 mov r1, #7
 *   @0x11d4f4 mov r3, r0
 *   @0x11d4f8 mov r0, r4
 *   @0x11d4fc str r3, [sp, #0x28]
 *   @0x11d500 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d504 mov r1, #8
 *   @0x11d508 mov r11, r0
 *   @0x11d50c mov r0, r4
 *   @0x11d510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d514 mov r1, #9
 *   @0x11d518 mov r10, r0
 *   @0x11d51c mov r0, r4
 *   @0x11d520 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d524 mov r1, #10
 *   @0x11d528 mov r9, r0
 *   @0x11d52c mov r0, r4
 *   @0x11d530 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d534 ldr r2, [sp, #0x24]
 *   @0x11d538 ldr r3, [sp, #0x28]
 *   @0x11d53c mov r1, r8
 *   @0x11d540 ldr r12, [sp, #0x20]
 *   @0x11d544 str r2, [sp, #0x4]
 *   @0x11d548 mov r2, r7
 *   @0x11d54c str r3, [sp, #0x8]
 *   @0x11d550 mov r3, r6
 *   @0x11d554 str r12, [sp]
 *   @0x11d558 str r11, [sp, #0xc]
 *   @0x11d55c str r10, [sp, #0x10]
 *   @0x11d560 str r9, [sp, #0x14]
 *   @0x11d564 str r5, [sp, #0x1c]
 *   @0x11d568 str r0, [sp, #0x18]
 *   @0x11d56c ldr r0, [sp, #0x2c]
 *   @0x11d570 bl 0xc0244 <_ZN15CSkeletonSprite4DrawEPKcS1_ifffffjfP9CInstance>
 *   @0x11d574 add sp, sp, #52
 *   @0x11d578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §84/87 F_DrawBackgroundStretched(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e458  size 332  83 条（0x11e458..0x11e5a4）
 * @func 0x11e458 0x11e5a4  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Get_Alpha()×2 / Sprite_Data(int) / CSprite::DrawStretched(int, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawStretched(float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x13c×1 / 0x28×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e458 ldr r3, [pc, #0x13c]
 *   @0x11e45c push {r4, r5, r6, r7, r8, lr}
 *   @0x11e460 ldr r3, [pc, r3]
 *   @0x11e464 sub sp, sp, #16
 *   @0x11e468 ldrb r1, [r3]
 *   @0x11e46c ldr r4, [sp, #0x28]
 *   @0x11e470 cmp r1, #0
 *   @0x11e474 mov r0, r4
 *   @0x11e478 beq 0x11e504 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x11e47c mov r1, #0
 *   @0x11e480 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e484 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11e488 subs r5, r0, #0
 *   @0x11e48c beq 0x11e584 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x11e490 mov r0, r4
 *   @0x11e494 mov r1, #1
 *   @0x11e498 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e49c mov r1, #2
 *   @0x11e4a0 mov r7, r0
 *   @0x11e4a4 mov r0, r4
 *   @0x11e4a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e4ac mov r1, #3
 *   @0x11e4b0 mov r6, r0
 *   @0x11e4b4 mov r0, r4
 *   @0x11e4b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e4bc mov r1, #4
 *   @0x11e4c0 mov r8, r0
 *   @0x11e4c4 mov r0, r4
 *   @0x11e4c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e4cc mov r4, r0
 *   @0x11e4d0 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11e4d4 mvn r12, #-16777216
 *   @0x11e4d8 str r8, [sp]
 *   @0x11e4dc str r4, [sp, #0x4]
 *   @0x11e4e0 mov r2, r7
 *   @0x11e4e4 mov r3, r6
 *   @0x11e4e8 mov r1, #0
 *   @0x11e4ec str r12, [sp, #0x8]
 *   @0x11e4f0 str r0, [sp, #0xc]
 *   @0x11e4f4 mov r0, r5
 *   @0x11e4f8 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf>
 *   @0x11e4fc add sp, sp, #16
 *   @0x11e500 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11e504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e508 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11e50c subs r5, r0, #0
 *   @0x11e510 beq 0x11e584 <_Z25F_DrawBackgroundStretchedR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x11e514 mov r0, r4
 *   @0x11e518 mov r1, #1
 *   @0x11e51c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e520 mov r1, #2
 *   @0x11e524 mov r8, r0
 *   @0x11e528 mov r0, r4
 *   @0x11e52c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e530 mov r1, #3
 *   @0x11e534 mov r7, r0
 *   @0x11e538 mov r0, r4
 *   @0x11e53c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e540 mov r1, #4
 *   @0x11e544 mov r6, r0
 *   @0x11e548 mov r0, r4
 *   @0x11e54c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e550 mov r4, r0
 *   @0x11e554 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11e558 mvn r12, #-16777216
 *   @0x11e55c str r4, [sp]
 *   @0x11e560 mov r1, r8
 *   @0x11e564 mov r2, r7
 *   @0x11e568 mov r3, r6
 *   @0x11e56c str r12, [sp, #0x4]
 *   @0x11e570 str r0, [sp, #0x8]
 *   @0x11e574 mov r0, r5
 *   @0x11e578 bl 0xc2094 <_ZN11CBackground13DrawStretchedEffffjf>
 *   @0x11e57c add sp, sp, #16
 *   @0x11e580 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11e584 ldr r0, [pc, #0x14]
 *   @0x11e588 mov r1, #0
 *   @0x11e58c add r0, pc, r0
 *   @0x11e590 add sp, sp, #16
 *   @0x11e594 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11e598 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e59c eoreq pc, r12, r4, asr #9
 *   @0x11e5a0 eoreq r11, r1, r8, asr #24
 *
 * ══ §85/87 F_FileTextReadLn(RValue&, CInstance*, CInstance*, int, RValue*)  0x138074  size 332  83 条（0x138074..0x1381c0）
 * @func 0x138074 0x1381c0  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / LoadSave::fgetc(_YYFILE*)×2 / YYGetInt32(RValue const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / LoadSave::yyfeof(_YYFILE*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x8×3 / 0xc×2 / 0x38×1 / 0x108×1 / 0x2×1 / 0xf8×1 / 0xe4×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138074 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x138078 sub sp, sp, #20
 *   @0x13807c mov r9, r0
 *   @0x138080 mov r1, #0
 *   @0x138084 ldr r0, [sp, #0x38]
 *   @0x138088 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13808c sub r3, r0, #1
 *   @0x138090 mov r4, r0
 *   @0x138094 cmp r3, #30
 *   @0x138098 bhi 0x1380b0 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x13809c ldr r3, [pc, #0x108]
 *   @0x1380a0 ldr r3, [pc, r3]
 *   @0x1380a4 ldr r3, [r3, r0, lsl #2]
 *   @0x1380a8 cmp r3, #1
 *   @0x1380ac beq 0x1380c8 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1380b0 ldr r0, [pc, #0xf8]
 *   @0x1380b4 mov r1, #0
 *   @0x1380b8 add r0, pc, r0
 *   @0x1380bc add sp, sp, #20
 *   @0x1380c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1380c4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1380c8 ldr r1, [pc, #0xe4]
 *   @0x1380cc movw r2, #0x441
 *   @0x1380d0 mov r0, #1024
 *   @0x1380d4 add r7, r4, r4, lsl #1
 *   @0x1380d8 add r1, pc, r1
 *   @0x1380dc mov r4, #0
 *   @0x1380e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1380e4 mov r1, #0
 *   @0x1380e8 mov r2, #1024
 *   @0x1380ec mov r8, #1024
 *   @0x1380f0 mov r5, r0
 *   @0x1380f4 bl 0xb65b0 <memset@plt>
 *   @0x1380f8 ldr r3, [pc, #0xb8]
 *   @0x1380fc ldr r3, [pc, r3]
 *   @0x138100 add r7, r3, r7, lsl #2
 *   @0x138104 ldr r3, [pc, #0xb0]
 *   @0x138108 ldr r0, [r7, #0x8]
 *   @0x13810c add r3, pc, r3
 *   @0x138110 str r3, [sp, #0xc]
 *   @0x138114 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE>
 *   @0x138118 mov r6, r0
 *   @0x13811c add r4, r4, #1
 *   @0x138120 add r3, r5, r4
 *   @0x138124 strb r6, [r3, #-0x1]
 *   @0x138128 ldr r0, [r7, #0x8]
 *   @0x13812c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x138130 subs r11, r0, #0
 *   @0x138134 bne 0x138190 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x138138 cmp r6, #10
 *   @0x13813c beq 0x138190 <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x138140 ldr r0, [r7, #0x8]
 *   @0x138144 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE>
 *   @0x138148 sub r3, r8, #1
 *   @0x13814c cmp r3, r4
 *   @0x138150 mov r6, r0
 *   @0x138154 bgt 0x13811c <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x138158 add r10, r8, #1024
 *   @0x13815c ldr r2, [sp, #0xc]
 *   @0x138160 str r11, [sp]
 *   @0x138164 mov r0, r5
 *   @0x138168 mov r1, r10
 *   @0x13816c movw r3, #0x44a
 *   @0x138170 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x138174 mov r1, r11
 *   @0x138178 mov r2, #1024
 *   @0x13817c mov r5, r0
 *   @0x138180 add r0, r0, r8
 *   @0x138184 mov r8, r10
 *   @0x138188 bl 0xb65b0 <memset@plt>
 *   @0x13818c b 0x13811c <_Z16F_FileTextReadLnR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x138190 mov r0, r9
 *   @0x138194 mov r1, r5
 *   @0x138198 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13819c mov r0, r5
 *   @0x1381a0 add sp, sp, #20
 *   @0x1381a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1381a8 b 0xcef90 <_Z6YYFreePKv>
 *   @0x1381ac .word 0x002b71d0
 *   @0x1381b0 eoreq r7, r0, r8, ror pc
 *   @0x1381b4 eoreq r7, r0, r8, ror pc
 *   @0x1381b8 eoreq r7, r11, r8, ror r1
 *   @0x1381bc eoreq r7, r0, r4, asr #30
 *
 * ══ §86/87 GR_3D_Vertex_Texture(float, float, float, float, float)  0x176f7c  size 332  83 条（0x176f7c..0x1770c8）
 * @func 0x176f7c 0x1770c8  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_Texture(float, float, float, float, float)+0x48 / HandleOverflow()
 * 字段偏移 top8: 0x118×1 / 0x114×1 / 0x110×1 / 0xe8×1 / 0xe4×1 / 0xe0×1 / 0x4×1 / 0x8×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176f7c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x176f80 vpush {d8}
 *   @0x176f84 mov r7, r0
 *   @0x176f88 ldr r4, [pc, #0x118]
 *   @0x176f8c mov r8, r1
 *   @0x176f90 ldr r0, [pc, #0x114]
 *   @0x176f94 vmov s16, r3
 *   @0x176f98 ldr r1, [pc, #0x110]
 *   @0x176f9c add r4, pc, r4
 *   @0x176fa0 mov r9, r2
 *   @0x176fa4 ldr r6, [r4, r0]
 *   @0x176fa8 ldr r3, [r4, r1]
 *   @0x176fac ldr r5, [r6]
 *   @0x176fb0 ldr r3, [r3]
 *   @0x176fb4 cmp r5, r3
 *   @0x176fb8 blt 0x176fc4 <_Z20GR_3D_Vertex_Texturefffff+0x48>
 *   @0x176fbc bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x176fc0 ldr r5, [r6]
 *   @0x176fc4 ldr r0, [pc, #0xe8]
 *   @0x176fc8 add r3, r5, r5, lsl #3
 *   @0x176fcc ldr r1, [pc, #0xe4]
 *   @0x176fd0 mov r12, #0
 *   @0x176fd4 ldr r2, [pc, #0xe0]
 *   @0x176fd8 ldr r0, [r4, r0]
 *   @0x176fdc add r3, r0, r3, lsl #2
 *   @0x176fe0 str r7, [r3]
 *   @0x176fe4 str r8, [r3, #0x4]
 *   @0x176fe8 str r9, [r3, #0x8]
 *   @0x176fec str r12, [r3, #0x14]
 *   @0x176ff0 str r12, [r3, #0x10]
 *   @0x176ff4 str r12, [r3, #0xc]
 *   @0x176ff8 ldr r1, [r4, r1]
 *   @0x176ffc ldr r1, [r1]
 *   @0x177000 bic r1, r1, #1
 *   @0x177004 str r1, [r3, #0x18]
 *   @0x177008 ldr r2, [r4, r2]
 *   @0x17700c ldr r2, [r2]
 *   @0x177010 cmp r2, #0
 *   @0x177014 beq 0x17708c <_Z20GR_3D_Vertex_Texturefffff+0x110>
 *   @0x177018 ldrsh r0, [r2]
 *   @0x17701c add r5, r5, #1
 *   @0x177020 ldrsh r1, [r2, #12]
 *   @0x177024 vmov s14, r0
 *   @0x177028 ldrsh r0, [r2, #2]
 *   @0x17702c vmov s11, r1
 *   @0x177030 ldrsh r2, [r2, #14]
 *   @0x177034 vcvt.f32.s32 s14, s14
 *   @0x177038 ldr r1, [pc, #0x80]
 *   @0x17703c vmov s15, r0
 *   @0x177040 vmov s13, r2
 *   @0x177044 ldr r2, [r4, r1]
 *   @0x177048 vldr s12, [r2]
 *   @0x17704c ldr r2, [pc, #0x70]
 *   @0x177050 vcvt.f32.s32 s11, s11
 *   @0x177054 vmla.f32 s14, s16, s11
 *   @0x177058 vdiv.f32 s14, s14, s12
 *   @0x17705c vldr s12, [sp, #40]
 *   @0x177060 vpop {d8}
 *   @0x177064 vcvt.f32.s32 s15, s15
 *   @0x177068 vstr s14, [r3, #28]
 *   @0x17706c ldr r2, [r4, r2]
 *   @0x177070 vldr s14, [r2]
 *   @0x177074 str r5, [r6]
 *   @0x177078 vcvt.f32.s32 s13, s13
 *   @0x17707c vmla.f32 s15, s12, s13
 *   @0x177080 vdiv.f32 s15, s15, s14
 *   @0x177084 vstr s15, [r3, #32]
 *   @0x177088 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17708c vldr s12, [sp, #40]
 *   @0x177090 vstr s16, [r3, #28]
 *   @0x177094 vpop {d8}
 *   @0x177098 vstr s12, [r3, #32]
 *   @0x17709c add r5, r5, #1
 *   @0x1770a0 str r5, [r6]
 *   @0x1770a4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1770a8 .word 0x0027acb4
 *   @0x1770ac .word 0xffffe670
 *   @0x1770b0 .word 0xffffe67c
 *   @0x1770b4 .word 0xffffe680
 *   @0x1770b8 .word 0xffffc0ac
 *   @0x1770bc .word 0xffffe540
 *   @0x1770c0 .word 0xffffe544
 *   @0x1770c4 .word 0xffffe548
 *
 * ══ §87/87 F_BUFFER_Load_Async(RValue&, CInstance*, CInstance*, int, RValue*)  0xc73f4  size 312  78 条（0xc73f4..0xc752c）
 * @func 0xc73f4 0xc752c  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetString(RValue const*, int) / operator new(unsigned int) / YYStrDup(char const*) / KickAsyncBuffer(bool, SAsyncBuffer*, char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x78×2 / 0x28×1 / 0xb8×1 / 0xa4×1 / 0x94×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc73f4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc73f8 mov r5, r0
 *   @0xc73fc ldr r4, [sp, #0x28]
 *   @0xc7400 mov r3, #0
 *   @0xc7404 mov r6, r3
 *   @0xc7408 mov r1, #1
 *   @0xc740c movt r3, #0xbff0
 *   @0xc7410 str r6, [r0]
 *   @0xc7414 str r3, [r0, #0x4]
 *   @0xc7418 mov r0, r4
 *   @0xc741c str r6, [r5, #0xc]
 *   @0xc7420 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc7424 mov r1, r6
 *   @0xc7428 mov r8, r0
 *   @0xc742c mov r0, r4
 *   @0xc7430 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7434 mov r1, #2
 *   @0xc7438 mov r9, r0
 *   @0xc743c mov r0, r4
 *   @0xc7440 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7444 mov r1, #3
 *   @0xc7448 mov r7, r0
 *   @0xc744c mov r0, r4
 *   @0xc7450 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7454 ldr r3, [pc, #0xb8]
 *   @0xc7458 ldr r3, [pc, r3]
 *   @0xc745c ldr r4, [r3]
 *   @0xc7460 cmp r4, r6
 *   @0xc7464 mov r11, r0
 *   @0xc7468 beq 0xc747c <_Z19F_BUFFER_Load_AsyncR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xc746c ldr r0, [pc, #0xa4]
 *   @0xc7470 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc7474 add r0, pc, r0
 *   @0xc7478 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc747c mov r0, #24
 *   @0xc7480 ldr r10, [pc, #0x94]
 *   @0xc7484 bl 0x27c524 <_Znwj>
 *   @0xc7488 ldr r10, [pc, r10]
 *   @0xc748c ldr r3, [r10]
 *   @0xc7490 mov r6, r0
 *   @0xc7494 mov r0, r8
 *   @0xc7498 str r3, [r6]
 *   @0xc749c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc74a0 ldr r2, [pc, #0x78]
 *   @0xc74a4 ldr r3, [pc, #0x78]
 *   @0xc74a8 add r2, pc, r2
 *   @0xc74ac ldr r3, [pc, r3]
 *   @0xc74b0 ldr r2, [r2, #0x4]
 *   @0xc74b4 ldr r8, [r3]
 *   @0xc74b8 cmp r8, #0
 *   @0xc74bc str r0, [r6, #0x8]
 *   @0xc74c0 ldr r3, [r2, r9, lsl #2]
 *   @0xc74c4 str r6, [r10]
 *   @0xc74c8 str r4, [r6, #0xc]
 *   @0xc74cc str r3, [r6, #0x4]
 *   @0xc74d0 str r11, [r6, #0x10]
 *   @0xc74d4 str r7, [r6, #0x14]
 *   @0xc74d8 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc74dc ldr r2, [pc, #0x44]
 *   @0xc74e0 mov r1, r6
 *   @0xc74e4 mov r3, r8
 *   @0xc74e8 mov r0, r8
 *   @0xc74ec add r2, pc, r2
 *   @0xc74f0 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb>
 *   @0xc74f4 vmov s15, r0
 *   @0xc74f8 vcvt.f64.s32 d7, s15
 *   @0xc74fc vmov r0, r1, d7
 *   @0xc7500 vmov r2, s14
 *   @0xc7504 mov r3, r1
 *   @0xc7508 stm r5, {r2, r3}
 *   @0xc750c str r8, [r10]
 *   @0xc7510 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc7514 eorseq r6, r2, r0, lsl #11
 *   @0xc7518 strhteq r10, [r6], -r8
 *   @0xc751c eorseq r6, r2, r4, asr r5
 *   @0xc7520 eorseq r2, r11, r12, ror #24
 *   @0xc7524 eorseq r6, r2, r12, lsl #10
 *   @0xc7528 eoreq r10, r6, r12, lsr #1
 */
