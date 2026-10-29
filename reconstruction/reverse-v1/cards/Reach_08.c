/* cally 逆向卡：Reach_08 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 69 个函数｜锚点 7492 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/69 b2ParticleSystem::QueryAABB  0x2d9a60  size 492  123 条（0x2d9a60..0x2d9c4c）
 * @func 0x2d9a60 0x2d9c4c  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0xa0 / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0x90 / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0x120 / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0x110 / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0x184 / b2ParticleSystem::QueryAABB(b2QueryCallback*, b2AABB const&) const+0x130
 * 字段偏移 top8: 0x4×4 / 0x68×1 / 0x70×1 / 0x-8×1 / 0x38×1 / 0xc×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9a60 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d9a64 mov r7, r0
 *   @0x2d9a68 ldr r3, [r0, #0x68]
 *   @0x2d9a6c mov r8, r1
 *   @0x2d9a70 mov r9, r2
 *   @0x2d9a74 cmp r3, #0
 *   @0x2d9a78 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9a7c vldr s15, [r0, #28]
 *   @0x2d9a80 vldr s14, [r2]
 *   @0x2d9a84 vmul.f32 s10, s15, s14
 *   @0x2d9a88 vldr s9, [r2, #4]
 *   @0x2d9a8c vldr s12, [pc, #428]
 *   @0x2d9a90 vldr s11, [pc, #428]
 *   @0x2d9a94 vldr s13, [pc, #428]
 *   @0x2d9a98 ldr r5, [r0, #0x70]
 *   @0x2d9a9c sbfx r1, r3, #0x0, #0x1d
 *   @0x2d9aa0 add r6, r5, r3, lsl #3
 *   @0x2d9aa4 vmla.f32 s12, s15, s9
 *   @0x2d9aa8 vmla.f32 s13, s10, s11
 *   @0x2d9aac vcvt.u32.f32 s12, s12
 *   @0x2d9ab0 vcvt.u32.f32 s13, s13
 *   @0x2d9ab4 vmov r0, s12
 *   @0x2d9ab8 vmov r3, s13
 *   @0x2d9abc add r0, r3, r0, lsl #20
 *   @0x2d9ac0 cmp r1, #0
 *   @0x2d9ac4 ble 0x2d9b00 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0xa0>
 *   @0x2d9ac8 asr r3, r1, #1
 *   @0x2d9acc add r2, r5, r3, lsl #3
 *   @0x2d9ad0 ldr r12, [r2, #0x4]
 *   @0x2d9ad4 cmp r0, r12
 *   @0x2d9ad8 bls 0x2d9af0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x90>
 *   @0x2d9adc b 0x2d9bf4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x194>
 *   @0x2d9ae0 ldr r1, [r2, #0x4]
 *   @0x2d9ae4 cmp r0, r1
 *   @0x2d9ae8 bhi 0x2d9bfc <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x19c>
 *   @0x2d9aec mov r3, r12
 *   @0x2d9af0 asr r12, r3, #1
 *   @0x2d9af4 cmp r3, #0
 *   @0x2d9af8 add r2, r5, r12, lsl #3
 *   @0x2d9afc bne 0x2d9ae0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x80>
 *   @0x2d9b00 vldr s9, [r9, #8]
 *   @0x2d9b04 vmul.f32 s9, s15, s9
 *   @0x2d9b08 vldr s10, [pc, #308]
 *   @0x2d9b0c vldr s12, [pc, #308]
 *   @0x2d9b10 vldr s11, [r9, #12]
 *   @0x2d9b14 vldr s13, [pc, #292]
 *   @0x2d9b18 rsb r2, r5, r6
 *   @0x2d9b1c mov r4, r5
 *   @0x2d9b20 asr r2, r2, #3
 *   @0x2d9b24 vmla.f32 s12, s9, s10
 *   @0x2d9b28 vmla.f32 s13, s15, s11
 *   @0x2d9b2c vcvt.u32.f32 s12, s12
 *   @0x2d9b30 vcvt.u32.f32 s13, s13
 *   @0x2d9b34 vmov r3, s12
 *   @0x2d9b38 vmov r1, s13
 *   @0x2d9b3c add r1, r3, r1, lsl #20
 *   @0x2d9b40 cmp r2, #0
 *   @0x2d9b44 ble 0x2d9b80 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x120>
 *   @0x2d9b48 asr r3, r2, #1
 *   @0x2d9b4c add r6, r5, r3, lsl #3
 *   @0x2d9b50 ldr r0, [r6, #0x4]
 *   @0x2d9b54 cmp r1, r0
 *   @0x2d9b58 blo 0x2d9b70 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x110>
 *   @0x2d9b5c b 0x2d9c0c <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1ac>
 *   @0x2d9b60 ldr r2, [r6, #0x4]
 *   @0x2d9b64 cmp r1, r2
 *   @0x2d9b68 bhs 0x2d9c14 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1b4>
 *   @0x2d9b6c mov r3, r12
 *   @0x2d9b70 asr r12, r3, #1
 *   @0x2d9b74 cmp r3, #0
 *   @0x2d9b78 add r6, r5, r12, lsl #3
 *   @0x2d9b7c bne 0x2d9b60 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x100>
 *   @0x2d9b80 cmp r4, r5
 *   @0x2d9b84 pophs {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9b88 add r4, r4, #8
 *   @0x2d9b8c b 0x2d9b94 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x134>
 *   @0x2d9b90 vldr s14, [r9]
 *   @0x2d9b94 ldr r1, [r4, #-0x8]
 *   @0x2d9b98 ldr r3, [r7, #0x38]
 *   @0x2d9b9c add r3, r3, r1, lsl #3
 *   @0x2d9ba0 vldr s15, [r3]
 *   @0x2d9ba4 vcmpe.f32 s15, s14
 *   @0x2d9ba8 vmrs APSR_nzcv, fpscr
 *   @0x2d9bac ble 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184>
 *   @0x2d9bb0 vldr s14, [r9, #8]
 *   @0x2d9bb4 vcmpe.f32 s15, s14
 *   @0x2d9bb8 vmrs APSR_nzcv, fpscr
 *   @0x2d9bbc bpl 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184>
 *   @0x2d9bc0 vldr s15, [r3, #4]
 *   @0x2d9bc4 vldr s14, [r9, #4]
 *   @0x2d9bc8 vcmpe.f32 s14, s15
 *   @0x2d9bcc vmrs APSR_nzcv, fpscr
 *   @0x2d9bd0 bpl 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184>
 *   @0x2d9bd4 vldr s14, [r9, #12]
 *   @0x2d9bd8 vcmpe.f32 s15, s14
 *   @0x2d9bdc vmrs APSR_nzcv, fpscr
 *   @0x2d9be0 bmi 0x2d9c24 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x1c4>
 *   @0x2d9be4 cmp r4, r5
 *   @0x2d9be8 add r4, r4, #8
 *   @0x2d9bec blo 0x2d9b90 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x130>
 *   @0x2d9bf0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9bf4 mov r12, r3
 *   @0x2d9bf8 mov r3, r1
 *   @0x2d9bfc rsb r3, r12, r3
 *   @0x2d9c00 add r5, r2, #8
 *   @0x2d9c04 sub r1, r3, #1
 *   @0x2d9c08 b 0x2d9ac0 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x60>
 *   @0x2d9c0c mov r12, r3
 *   @0x2d9c10 mov r3, r2
 *   @0x2d9c14 rsb r3, r12, r3
 *   @0x2d9c18 add r5, r6, #8
 *   @0x2d9c1c sub r2, r3, #1
 *   @0x2d9c20 b 0x2d9b40 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0xe0>
 *   @0x2d9c24 ldr r3, [r8]
 *   @0x2d9c28 mov r0, r8
 *   @0x2d9c2c ldr r3, [r3, #0xc]
 *   @0x2d9c30 blx r3
 *   @0x2d9c34 cmp r0, #0
 *   @0x2d9c38 bne 0x2d9be4 <_ZNK16b2ParticleSystem9QueryAABBEP15b2QueryCallbackRK6b2AABB+0x184>
 *   @0x2d9c3c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9c40 strmi r0, [r0, #-0x0]
 *   @0x2d9c44 orrmi r0, r0, #0
 *   @0x2d9c48 .word 0x49000000
 *
 * ══ §2/69 Graphics::AllocVerts  0x185418  size 488  122 条（0x185418..0x185600）
 * @func 0x185418 0x185600  size 488  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x185428→0x3f2928, 0x185444→0x4a2fb4, 0x18544c→0x4a2fac, 0x185450→0x4a2fa8, 0x185480→0x4a2fb0, 0x1854a0→0x4a2fbc, 0x1854c8→0x4a2fa4, 0x1854f0→0x4a2fac
 * 调用序列: Graphics::Flush() / JoinToPreviousStrip() / Graphics::AllocVerts(ePrimType, void*, int, int)+0x88 / GetVertexFormat(int)
 * 字段偏移 top8: 0x188×2 / 0x4×2 / 0x1a8×1 / 0x1a4×1 / 0x18c×1 / 0x15c×1 / 0x140×1 / 0x11c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185418 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18541c mov r11, r0
 *   @0x185420 ldr r6, [pc, #0x1a8]
 *   @0x185424 mov r9, r3
 *   @0x185428 ldr r0, [pc, #0x1a4]
 *   @0x18542c sub sp, sp, #12
 *   @0x185430 add r6, pc, r6
 *   @0x185434 mov r10, r2
 *   @0x185438 ldr r7, [r6, r0]
 *   @0x18543c ldr r3, [r7]
 *   @0x185440 cmp r11, r3
 *   @0x185444 ldr r3, [pc, #0x18c]
 *   @0x185448 beq 0x1854e4 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xcc>
 *   @0x18544c ldr r2, [pc, #0x188]
 *   @0x185450 ldr r0, [pc, #0x188]
 *   @0x185454 ldr r5, [r6, r3]
 *   @0x185458 ldr r4, [r6, r2]
 *   @0x18545c ldr r8, [r6, r0]
 *   @0x185460 str r1, [sp, #0x4]
 *   @0x185464 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x185468 ldr r1, [sp, #0x4]
 *   @0x18546c tst r10, #16777216
 *   @0x185470 str r11, [r7]
 *   @0x185474 str r10, [r4]
 *   @0x185478 str r1, [r5]
 *   @0x18547c bne 0x185508 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xf0>
 *   @0x185480 ldr r3, [pc, #0x15c]
 *   @0x185484 ldr r4, [r6, r3]
 *   @0x185488 str r10, [r4]
 *   @0x18548c bl 0x185218 <_Z19JoinToPreviousStripv>
 *   @0x185490 ldr r3, [r7]
 *   @0x185494 cmp r3, #5
 *   @0x185498 ldr r3, [r8]
 *   @0x18549c beq 0x1854c0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0xa8>
 *   @0x1854a0 ldr r2, [pc, #0x140]
 *   @0x1854a4 add r9, r9, r3
 *   @0x1854a8 ldr r0, [r4]
 *   @0x1854ac ldr r2, [r6, r2]
 *   @0x1854b0 str r9, [r8]
 *   @0x1854b4 mla r0, r0, r3, r2
 *   @0x1854b8 add sp, sp, #12
 *   @0x1854bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1854c0 cmp r3, #0
 *   @0x1854c4 ble 0x1854a0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x88>
 *   @0x1854c8 ldr r2, [pc, #0x11c]
 *   @0x1854cc tst r3, #1
 *   @0x1854d0 ldr r2, [r6, r2]
 *   @0x1854d4 str r3, [r2]
 *   @0x1854d8 addne r3, r3, #3
 *   @0x1854dc addeq r3, r3, #2
 *   @0x1854e0 b 0x1854a0 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x88>
 *   @0x1854e4 ldr r5, [r6, r3]
 *   @0x1854e8 ldr r2, [r5]
 *   @0x1854ec cmp r1, r2
 *   @0x1854f0 ldr r2, [pc, #0xe4]
 *   @0x1854f4 beq 0x185548 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x130>
 *   @0x1854f8 ldr r0, [pc, #0xe0]
 *   @0x1854fc ldr r4, [r6, r2]
 *   @0x185500 ldr r8, [r6, r0]
 *   @0x185504 b 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x185508 mov r0, r10
 *   @0x18550c bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x185510 cmp r0, #0
 *   @0x185514 ldrne r10, [r0, #0x14]
 *   @0x185518 bne 0x185480 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x68>
 *   @0x18551c ldr r3, [pc, #0xcc]
 *   @0x185520 mov r2, r10
 *   @0x185524 ldr r1, [pc, #0xc8]
 *   @0x185528 mov r10, #1
 *   @0x18552c ldr r3, [r6, r3]
 *   @0x185530 add r1, pc, r1
 *   @0x185534 ldr r0, [r3]
 *   @0x185538 ldr r3, [r0]
 *   @0x18553c ldr r3, [r3, #0xc]
 *   @0x185540 blx r3
 *   @0x185544 b 0x185480 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x68>
 *   @0x185548 ldr r4, [r6, r2]
 *   @0x18554c ldr r0, [r4]
 *   @0x185550 cmp r10, r0
 *   @0x185554 beq 0x185564 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x14c>
 *   @0x185558 ldr r0, [pc, #0x80]
 *   @0x18555c ldr r8, [r6, r0]
 *   @0x185560 b 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x185564 cmp r11, #6
 *   @0x185568 beq 0x185558 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x140>
 *   @0x18556c cmp r11, #3
 *   @0x185570 beq 0x185558 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x140>
 *   @0x185574 ldr r12, [pc, #0x64]
 *   @0x185578 movw r0, #0x3ffd
 *   @0x18557c ldr r8, [r6, r12]
 *   @0x185580 ldr r12, [r8]
 *   @0x185584 add r12, r9, r12
 *   @0x185588 cmp r12, r0
 *   @0x18558c bgt 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x185590 ldr r0, [pc, #0x60]
 *   @0x185594 ldr r0, [r6, r0]
 *   @0x185598 ldrd r2, r3, [r0]
 *   @0x18559c orrs r12, r2, r3
 *   @0x1855a0 bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x1855a4 ldrd r2, r3, [r0, #8]
 *   @0x1855a8 orrs r0, r2, r3
 *   @0x1855ac bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x1855b0 ldr r0, [pc, #0x44]
 *   @0x1855b4 ldr r0, [r6, r0]
 *   @0x1855b8 ldrb r0, [r0]
 *   @0x1855bc cmp r0, #0
 *   @0x1855c0 bne 0x185460 <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x48>
 *   @0x1855c4 ldr r3, [pc, #0x18]
 *   @0x1855c8 ldr r4, [r6, r3]
 *   @0x1855cc b 0x18548c <_ZN8Graphics10AllocVertsE9ePrimTypePvii+0x74>
 *   @0x1855d0 eoreq r12, r6, r0, lsr #16
 *   @0x1855d4 .word 0xffffe948
 *   @0x1855d8 .word 0xffffe8f8
 *   @0x1855dc .word 0xffffe960
 *   @0x1855e0 .word 0xffffe94c
 *   @0x1855e4 .word 0xffffe954
 *   @0x1855e8 .word 0xffffe958
 *   @0x1855ec .word 0xffffe950
 *   @0x1855f0 .word 0xffffbac4
 *   @0x1855f4 andseq r6, r12, r12, asr #12
 *   @0x1855f8 .word 0xffffc0a8
 *   @0x1855fc .word 0xffffe964
 *
 * ══ §3/69 CObjectGM::GetEventRecursive  0x19daf4  size 488  122 条（0x19daf4..0x19dcdc）
 * @func 0x19daf4 0x19dcdc  size 488  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Object_Exists(int)×4 / CObjectGM::GetEventDirect(int, int)×2 / CObjectGM::GetEventRecursive(int, int)+0x48 / CObjectGM::GetEventRecursive(int, int)+0x50 / CObjectGM::GetEventRecursive(int, int)+0x1a8
 * 字段偏移 top8: 0xc×8 / 0x4×6 / 0x8×5 / 0x3×4 / 0x180×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19daf4 push {r3, r4, r5, r6, r7, lr}
 *   @0x19daf8 subs r5, r0, #0
 *   @0x19dafc mov r7, r1
 *   @0x19db00 mov r6, r2
 *   @0x19db04 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48>
 *   @0x19db08 mov r4, r5
 *   @0x19db0c mov r0, r4
 *   @0x19db10 mov r1, r7
 *   @0x19db14 mov r2, r6
 *   @0x19db18 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii>
 *   @0x19db1c cmp r0, #0
 *   @0x19db20 popne {r3, r4, r5, r6, r7, pc}
 *   @0x19db24 ldr r0, [r4, #0xc]
 *   @0x19db28 cmp r0, #0
 *   @0x19db2c blt 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48>
 *   @0x19db30 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19db34 cmp r0, #0
 *   @0x19db38 bne 0x19db4c <_ZN9CObjectGM17GetEventRecursiveEii+0x58>
 *   @0x19db3c cmp r7, #4
 *   @0x19db40 beq 0x19dba8 <_ZN9CObjectGM17GetEventRecursiveEii+0xb4>
 *   @0x19db44 mov r0, #0
 *   @0x19db48 pop {r3, r4, r5, r6, r7, pc}
 *   @0x19db4c ldr r3, [pc, #0x180]
 *   @0x19db50 ldr r4, [r4, #0xc]
 *   @0x19db54 ldr r3, [pc, r3]
 *   @0x19db58 ldr r3, [r3]
 *   @0x19db5c ldr r2, [r3, #0x4]
 *   @0x19db60 ldr r3, [r3]
 *   @0x19db64 and r2, r4, r2
 *   @0x19db68 ldr r3, [r3, r2, lsl #3]
 *   @0x19db6c cmp r3, #0
 *   @0x19db70 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48>
 *   @0x19db74 ldr r2, [r3, #0x8]
 *   @0x19db78 cmp r4, r2
 *   @0x19db7c beq 0x19db98 <_ZN9CObjectGM17GetEventRecursiveEii+0xa4>
 *   @0x19db80 ldr r3, [r3, #0x4]
 *   @0x19db84 cmp r3, #0
 *   @0x19db88 beq 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48>
 *   @0x19db8c ldr r12, [r3, #0x8]
 *   @0x19db90 cmp r4, r12
 *   @0x19db94 bne 0x19db80 <_ZN9CObjectGM17GetEventRecursiveEii+0x8c>
 *   @0x19db98 ldr r4, [r3, #0xc]
 *   @0x19db9c cmp r4, #0
 *   @0x19dba0 bne 0x19db0c <_ZN9CObjectGM17GetEventRecursiveEii+0x18>
 *   @0x19dba4 b 0x19db3c <_ZN9CObjectGM17GetEventRecursiveEii+0x48>
 *   @0x19dba8 mov r0, r6
 *   @0x19dbac bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19dbb0 cmp r0, #0
 *   @0x19dbb4 beq 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50>
 *   @0x19dbb8 ldr r7, [pc, #0x118]
 *   @0x19dbbc ldr r7, [pc, r7]
 *   @0x19dbc0 ldr r3, [r7]
 *   @0x19dbc4 ldr r2, [r3, #0x4]
 *   @0x19dbc8 ldr r3, [r3]
 *   @0x19dbcc and r2, r6, r2
 *   @0x19dbd0 ldr r3, [r3, r2, lsl #3]
 *   @0x19dbd4 cmp r3, #0
 *   @0x19dbd8 bne 0x19dbec <_ZN9CObjectGM17GetEventRecursiveEii+0xf8>
 *   @0x19dbdc b 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108>
 *   @0x19dbe0 ldr r3, [r3, #0x4]
 *   @0x19dbe4 cmp r3, #0
 *   @0x19dbe8 beq 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108>
 *   @0x19dbec ldr r2, [r3, #0x8]
 *   @0x19dbf0 cmp r6, r2
 *   @0x19dbf4 bne 0x19dbe0 <_ZN9CObjectGM17GetEventRecursiveEii+0xec>
 *   @0x19dbf8 ldr r3, [r3, #0xc]
 *   @0x19dbfc ldr r6, [r3, #0xc]
 *   @0x19dc00 cmp r6, #0
 *   @0x19dc04 blt 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50>
 *   @0x19dc08 mov r0, r6
 *   @0x19dc0c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19dc10 cmp r0, #0
 *   @0x19dc14 beq 0x19db44 <_ZN9CObjectGM17GetEventRecursiveEii+0x50>
 *   @0x19dc18 cmp r5, #0
 *   @0x19dc1c movne r4, r5
 *   @0x19dc20 beq 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8>
 *   @0x19dc24 mov r0, r4
 *   @0x19dc28 mov r1, #4
 *   @0x19dc2c mov r2, r6
 *   @0x19dc30 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii>
 *   @0x19dc34 cmp r0, #0
 *   @0x19dc38 popne {r3, r4, r5, r6, r7, pc}
 *   @0x19dc3c ldr r0, [r4, #0xc]
 *   @0x19dc40 cmp r0, #0
 *   @0x19dc44 blt 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8>
 *   @0x19dc48 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19dc4c cmp r0, #0
 *   @0x19dc50 beq 0x19dc9c <_ZN9CObjectGM17GetEventRecursiveEii+0x1a8>
 *   @0x19dc54 ldr r3, [r7]
 *   @0x19dc58 ldr r12, [r4, #0xc]
 *   @0x19dc5c ldm r3, {r0, r2}
 *   @0x19dc60 and r3, r2, r12
 *   @0x19dc64 ldr r3, [r0, r3, lsl #3]
 *   @0x19dc68 cmp r3, #0
 *   @0x19dc6c bne 0x19dc80 <_ZN9CObjectGM17GetEventRecursiveEii+0x18c>
 *   @0x19dc70 b 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0>
 *   @0x19dc74 ldr r3, [r3, #0x4]
 *   @0x19dc78 cmp r3, #0
 *   @0x19dc7c beq 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0>
 *   @0x19dc80 ldr r1, [r3, #0x8]
 *   @0x19dc84 cmp r12, r1
 *   @0x19dc88 bne 0x19dc74 <_ZN9CObjectGM17GetEventRecursiveEii+0x180>
 *   @0x19dc8c ldr r4, [r3, #0xc]
 *   @0x19dc90 cmp r4, #0
 *   @0x19dc94 bne 0x19dc24 <_ZN9CObjectGM17GetEventRecursiveEii+0x130>
 *   @0x19dc98 b 0x19dca4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1b0>
 *   @0x19dc9c ldr r3, [r7]
 *   @0x19dca0 ldm r3, {r0, r2}
 *   @0x19dca4 and r2, r2, r6
 *   @0x19dca8 ldr r3, [r0, r2, lsl #3]
 *   @0x19dcac cmp r3, #0
 *   @0x19dcb0 bne 0x19dcc4 <_ZN9CObjectGM17GetEventRecursiveEii+0x1d0>
 *   @0x19dcb4 b 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108>
 *   @0x19dcb8 ldr r3, [r3, #0x4]
 *   @0x19dcbc cmp r3, #0
 *   @0x19dcc0 beq 0x19dbfc <_ZN9CObjectGM17GetEventRecursiveEii+0x108>
 *   @0x19dcc4 ldr r2, [r3, #0x8]
 *   @0x19dcc8 cmp r6, r2
 *   @0x19dccc bne 0x19dcb8 <_ZN9CObjectGM17GetEventRecursiveEii+0x1c4>
 *   @0x19dcd0 b 0x19dbf8 <_ZN9CObjectGM17GetEventRecursiveEii+0x104>
 *   @0x19dcd4 eoreq r0, r5, r8, ror #1
 *   @0x19dcd8 eoreq r0, r5, r0, lsl #1
 *
 * ══ §4/69 GR_Texture_Draw_Simple  0x174498  size 484  121 条（0x174498..0x17467c）
 * @func 0x174498 0x17467c  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / GR_Draw_Get_Alpha() / GR_Texture_Draw_Simple(int, float, float)+0x1b8
 * 字段偏移 top8: 0x1a4×1 / 0x4×1 / 0x2×1 / 0x108×1 / 0x70×1 / 0x10×1 / 0x88×1 / 0x2c×1
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174498 push {r3, r4, r5, r6, r7, lr}
 *   @0x17449c vpush {d8}
 *   @0x1744a0 mov r4, r0
 *   @0x1744a4 vmov s17, r1
 *   @0x1744a8 vmov s16, r2
 *   @0x1744ac bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1744b0 subs r6, r0, #0
 *   @0x1744b4 bne 0x1744c4 <_Z22GR_Texture_Draw_Simpleiff+0x2c>
 *   @0x1744b8 vpop {d8}
 *   @0x1744bc mov r0, r6
 *   @0x1744c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1744c4 ldr r1, [pc, #0x1a4]
 *   @0x1744c8 mov r2, #24
 *   @0x1744cc mov r3, #6
 *   @0x1744d0 mov r0, #4
 *   @0x1744d4 ldr r1, [pc, r1]
 *   @0x1744d8 ldr r1, [r1, #0x4]
 *   @0x1744dc ldr r5, [r1, r4, lsl #2]
 *   @0x1744e0 ldr r1, [r5]
 *   @0x1744e4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1744e8 ldrsh r3, [r5, #4]
 *   @0x1744ec vmov s14, r3
 *   @0x1744f0 ldrsh r3, [r5, #6]
 *   @0x1744f4 vcvt.f32.s32 s14, s14
 *   @0x1744f8 vmov s15, r3
 *   @0x1744fc vcvt.f32.s32 s15, s15
 *   @0x174500 vstr s17, [r0]
 *   @0x174504 vstr s17, [r0, #120]
 *   @0x174508 vstr s17, [r0, #96]
 *   @0x17450c vstr s16, [r0, #28]
 *   @0x174510 vadd.f32 s17, s14, s17
 *   @0x174514 vstr s16, [r0, #4]
 *   @0x174518 vstr s16, [r0, #124]
 *   @0x17451c mov r4, r0
 *   @0x174520 vadd.f32 s16, s15, s16
 *   @0x174524 vstr s17, [r0, #48]
 *   @0x174528 vstr s17, [r0, #72]
 *   @0x17452c vstr s17, [r0, #24]
 *   @0x174530 vstr s16, [r0, #100]
 *   @0x174534 vstr s16, [r0, #52]
 *   @0x174538 vstr s16, [r0, #76]
 *   @0x17453c bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x174540 vldr s15, [pc, #292]
 *   @0x174544 vmov s14, r0
 *   @0x174548 vmul.f32 s15, s14, s15
 *   @0x17454c vcvt.s32.f32 s15, s15
 *   @0x174550 vmov r3, s15
 *   @0x174554 cmp r3, #255
 *   @0x174558 mvngt r0, #0
 *   @0x17455c movgt r7, #-16777216
 *   @0x174560 ble 0x174650 <_Z22GR_Texture_Draw_Simpleiff+0x1b8>
 *   @0x174564 ldr r3, [pc, #0x108]
 *   @0x174568 ldr r3, [pc, r3]
 *   @0x17456c ldrb r2, [r3]
 *   @0x174570 cmp r2, #0
 *   @0x174574 bne 0x174628 <_Z22GR_Texture_Draw_Simpleiff+0x190>
 *   @0x174578 mov r2, r0
 *   @0x17457c mov r12, r0
 *   @0x174580 mov r1, r0
 *   @0x174584 mov r3, #0
 *   @0x174588 str r3, [r4, #0x70]
 *   @0x17458c str r3, [r4, #0x10]
 *   @0x174590 str r3, [r4, #0x88]
 *   @0x174594 str r3, [r4, #0x2c]
 *   @0x174598 str r3, [r4, #0x14]
 *   @0x17459c str r3, [r4, #0x8c]
 *   @0x1745a0 vldr s14, [r5, #8]
 *   @0x1745a4 ldrsh r3, [r5, #4]
 *   @0x1745a8 str r0, [r4, #0x6c]
 *   @0x1745ac mov r0, r6
 *   @0x1745b0 str r1, [r4, #0xc]
 *   @0x1745b4 vmov s15, r3
 *   @0x1745b8 ldr r3, [pc, #0xb8]
 *   @0x1745bc str r1, [r4, #0x84]
 *   @0x1745c0 vcvt.f32.s32 s15, s15
 *   @0x1745c4 ldr r3, [pc, r3]
 *   @0x1745c8 str r12, [r4, #0x24]
 *   @0x1745cc ldr r3, [r3]
 *   @0x1745d0 str r2, [r4, #0x3c]
 *   @0x1745d4 str r2, [r4, #0x54]
 *   @0x1745d8 str r3, [r4, #0x80]
 *   @0x1745dc str r3, [r4, #0x68]
 *   @0x1745e0 vmul.f32 s15, s15, s14
 *   @0x1745e4 str r3, [r4, #0x50]
 *   @0x1745e8 str r3, [r4, #0x38]
 *   @0x1745ec str r3, [r4, #0x20]
 *   @0x1745f0 str r3, [r4, #0x8]
 *   @0x1745f4 vstr s15, [r4, #64]
 *   @0x1745f8 vstr s15, [r4, #88]
 *   @0x1745fc vstr s15, [r4, #40]
 *   @0x174600 ldrsh r3, [r5, #6]
 *   @0x174604 vldr s14, [r5, #12]
 *   @0x174608 vmov s15, r3
 *   @0x17460c vcvt.f32.s32 s15, s15
 *   @0x174610 vmul.f32 s15, s15, s14
 *   @0x174614 vstr s15, [r4, #116]
 *   @0x174618 vstr s15, [r4, #68]
 *   @0x17461c vstr s15, [r4, #92]
 *   @0x174620 vpop {d8}
 *   @0x174624 pop {r3, r4, r5, r6, r7, pc}
 *   @0x174628 movw r1, #0xfffe
 *   @0x17462c movw r12, #0xffff
 *   @0x174630 movt r1, #0xfe
 *   @0x174634 movt r12, #0xfe
 *   @0x174638 movw r2, #0xfffe
 *   @0x17463c movt r2, #0xff
 *   @0x174640 orr r1, r7, r1
 *   @0x174644 orr r12, r7, r12
 *   @0x174648 orr r2, r7, r2
 *   @0x17464c b 0x174584 <_Z22GR_Texture_Draw_Simpleiff+0xec>
 *   @0x174650 cmp r3, #0
 *   @0x174654 lslge r7, r3, #24
 *   @0x174658 mvnlt r0, #-16777216
 *   @0x17465c movlt r7, #0
 *   @0x174660 mvnge r0, r7, lsr #24
 *   @0x174664 mvnge r0, r0, lsl #24
 *   @0x174668 b 0x174564 <_Z22GR_Texture_Draw_Simpleiff+0xcc>
 *   @0x17466c cmnmi pc, #0
 *   @0x174670 eoreq r9, r7, r8, asr #8
 *   @0x174674 eoreq r9, r7, r4, ror #17
 *   @0x174678 eoreq r9, r7, r12, asr r3
 *
 * ══ §5/69 IBuffer::Write  0xcdabc  size 480  120 条（0xcdabc..0xcdc9c）
 * @func 0xcdabc 0xcdc9c  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×3 / IBuffer::Write(void const*, unsigned int, unsigned int)+0x58×2 / IBuffer::Write(void const*, unsigned int, unsigned int)+0xb8 / IBuffer::Write(void const*, unsigned int, unsigned int)+0xc0 / IBuffer::Write(void const*, unsigned int, unsigned int)+0x124 / IBuffer::Write(void const*, unsigned int, unsigned int)+0x158 / __aeabi_idivmod
 * 字段偏移 top8: 0x10×4 / 0x1c×3 / 0xc×3 / 0x20×2 / 0x18×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcdabc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcdac0 subs r10, r1, #0
 *   @0xcdac4 mov r6, r0
 *   @0xcdac8 beq 0xcdc04 <_ZN7IBuffer5WriteEPKvjj+0x148>
 *   @0xcdacc mul r9, r3, r2
 *   @0xcdad0 cmp r9, #0
 *   @0xcdad4 mov r2, r9
 *   @0xcdad8 ble 0xcdb14 <_ZN7IBuffer5WriteEPKvjj+0x58>
 *   @0xcdadc ldr r3, [r0, #0x18]
 *   @0xcdae0 ldr r4, [r0, #0x1c]
 *   @0xcdae4 cmp r3, #1
 *   @0xcdae8 beq 0xcdb1c <_ZN7IBuffer5WriteEPKvjj+0x60>
 *   @0xcdaec ldr r5, [r0, #0x10]
 *   @0xcdaf0 cmp r5, #0
 *   @0xcdaf4 ble 0xcdb14 <_ZN7IBuffer5WriteEPKvjj+0x58>
 *   @0xcdaf8 cmp r3, #2
 *   @0xcdafc beq 0xcdbc8 <_ZN7IBuffer5WriteEPKvjj+0x10c>
 *   @0xcdb00 cmp r4, #0
 *   @0xcdb04 blt 0xcdb74 <_ZN7IBuffer5WriteEPKvjj+0xb8>
 *   @0xcdb08 cmp r4, r5
 *   @0xcdb0c movlt r3, r4
 *   @0xcdb10 blt 0xcdb7c <_ZN7IBuffer5WriteEPKvjj+0xc0>
 *   @0xcdb14 mov r0, #0
 *   @0xcdb18 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcdb1c bic r4, r4, r4, asr #31
 *   @0xcdb20 ldr r3, [r0, #0x10]
 *   @0xcdb24 add r5, r9, r4
 *   @0xcdb28 cmp r5, r3
 *   @0xcdb2c bgt 0xcdbb4 <_ZN7IBuffer5WriteEPKvjj+0xf8>
 *   @0xcdb30 mov r3, r4
 *   @0xcdb34 ldr r0, [r6, #0xc]
 *   @0xcdb38 mov r1, r10
 *   @0xcdb3c mov r2, r9
 *   @0xcdb40 mov r4, r5
 *   @0xcdb44 add r0, r0, r3
 *   @0xcdb48 bl 0xb65bc <memcpy@plt>
 *   @0xcdb4c ldr r3, [r6, #0x10]
 *   @0xcdb50 mov r0, r9
 *   @0xcdb54 ldr r2, [r6, #0x20]
 *   @0xcdb58 str r4, [r6, #0x1c]
 *   @0xcdb5c cmp r5, r2
 *   @0xcdb60 movlt r5, r2
 *   @0xcdb64 cmp r5, r3
 *   @0xcdb68 strle r5, [r6, #0x20]
 *   @0xcdb6c strgt r3, [r6, #0x20]
 *   @0xcdb70 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcdb74 mov r3, #0
 *   @0xcdb78 mov r4, r3
 *   @0xcdb7c add r2, r4, r9
 *   @0xcdb80 cmp r5, r2
 *   @0xcdb84 bge 0xcdc0c <_ZN7IBuffer5WriteEPKvjj+0x150>
 *   @0xcdb88 rsb r2, r4, r5
 *   @0xcdb8c mov r4, r5
 *   @0xcdb90 ldr r0, [r6, #0xc]
 *   @0xcdb94 mov r1, r10
 *   @0xcdb98 mov r9, r2
 *   @0xcdb9c add r0, r0, r3
 *   @0xcdba0 bl 0xb65bc <memcpy@plt>
 *   @0xcdba4 cmn r4, #1
 *   @0xcdba8 movne r5, r4
 *   @0xcdbac ldreq r5, [r6, #0x1c]
 *   @0xcdbb0 b 0xcdb4c <_ZN7IBuffer5WriteEPKvjj+0x90>
 *   @0xcdbb4 ldr r3, [r0]
 *   @0xcdbb8 mov r1, r5
 *   @0xcdbbc ldr r3, [r3, #0x34]
 *   @0xcdbc0 blx r3
 *   @0xcdbc4 b 0xcdb30 <_ZN7IBuffer5WriteEPKvjj+0x74>
 *   @0xcdbc8 cmp r4, #0
 *   @0xcdbcc bge 0xcdbe4 <_ZN7IBuffer5WriteEPKvjj+0x128>
 *   @0xcdbd0 adds r4, r4, r5
 *   @0xcdbd4 bmi 0xcdbd0 <_ZN7IBuffer5WriteEPKvjj+0x114>
 *   @0xcdbd8 cmp r5, r4
 *   @0xcdbdc bgt 0xcdbec <_ZN7IBuffer5WriteEPKvjj+0x130>
 *   @0xcdbe0 rsb r4, r5, r4
 *   @0xcdbe4 cmp r5, r4
 *   @0xcdbe8 ble 0xcdbe0 <_ZN7IBuffer5WriteEPKvjj+0x124>
 *   @0xcdbec add r1, r4, r9
 *   @0xcdbf0 cmp r5, r1
 *   @0xcdbf4 blt 0xcdc14 <_ZN7IBuffer5WriteEPKvjj+0x158>
 *   @0xcdbf8 mov r3, r4
 *   @0xcdbfc mov r4, r1
 *   @0xcdc00 b 0xcdb90 <_ZN7IBuffer5WriteEPKvjj+0xd4>
 *   @0xcdc04 mov r0, r10
 *   @0xcdc08 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcdc0c mov r5, r2
 *   @0xcdc10 b 0xcdb34 <_ZN7IBuffer5WriteEPKvjj+0x78>
 *   @0xcdc14 mov r8, r9
 *   @0xcdc18 mov r7, #0
 *   @0xcdc1c rsb r3, r7, r9
 *   @0xcdc20 rsb r5, r4, r5
 *   @0xcdc24 cmp r5, r3
 *   @0xcdc28 movge r5, r3
 *   @0xcdc2c ldr r0, [r6, #0xc]
 *   @0xcdc30 cmp r5, r8
 *   @0xcdc34 movge r5, r8
 *   @0xcdc38 add r1, r10, r7
 *   @0xcdc3c add r0, r0, r4
 *   @0xcdc40 rsb r8, r5, r8
 *   @0xcdc44 mov r2, r5
 *   @0xcdc48 add r7, r7, r5
 *   @0xcdc4c bl 0xb65bc <memcpy@plt>
 *   @0xcdc50 add r0, r4, r5
 *   @0xcdc54 cmn r0, #1
 *   @0xcdc58 ldr r5, [r6, #0x10]
 *   @0xcdc5c mov r3, r0
 *   @0xcdc60 ldr r2, [r6, #0x20]
 *   @0xcdc64 ldreq r3, [r6, #0x1c]
 *   @0xcdc68 mov r1, r5
 *   @0xcdc6c cmp r3, r2
 *   @0xcdc70 movlt r3, r2
 *   @0xcdc74 cmp r3, r5
 *   @0xcdc78 strle r3, [r6, #0x20]
 *   @0xcdc7c strgt r5, [r6, #0x20]
 *   @0xcdc80 bl 0x318dec <__aeabi_idivmod>
 *   @0xcdc84 cmp r8, #0
 *   @0xcdc88 mov r4, r1
 *   @0xcdc8c bgt 0xcdc1c <_ZN7IBuffer5WriteEPKvjj+0x160>
 *   @0xcdc90 mov r0, r9
 *   @0xcdc94 str r4, [r6, #0x1c]
 *   @0xcdc98 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §6/69 WithObjIterator::operator*  0x19de4c  size 480  120 条（0x19de4c..0x19e02c）
 * @func 0x19de4c 0x19e02c  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WithObjIterator::operator*()+0x184 / CObjectGM::IsDecendentOf(int)
 * 字段偏移 top8: 0x1c×7 / 0x8×6 / 0x18×3 / 0x14×3 / 0x7c×3 / 0x4×1 / 0x10×1 / 0x13c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19de4c push {r3, r4, r5, lr}
 *   @0x19de50 mov r4, r0
 *   @0x19de54 ldr r3, [r0, #0x18]
 *   @0x19de58 add r3, r3, #2
 *   @0x19de5c cmp r3, #5
 *   @0x19de60 addls pc, pc, r3, lsl #2
 *   @0x19de64 b 0x19ded0 <_ZN15WithObjIteratordeEv+0x84>
 *   @0x19de68 b 0x19dea8 <_ZN15WithObjIteratordeEv+0x5c>
 *   @0x19de6c b 0x19deb4 <_ZN15WithObjIteratordeEv+0x68>
 *   @0x19de70 b 0x19dec0 <_ZN15WithObjIteratordeEv+0x74>
 *   @0x19de74 b 0x19dedc <_ZN15WithObjIteratordeEv+0x90>
 *   @0x19de78 b 0x19df58 <_ZN15WithObjIteratordeEv+0x10c>
 *   @0x19de7c b 0x19de80 <_ZN15WithObjIteratordeEv+0x34>
 *   @0x19de80 ldr r5, [r0, #0x8]
 *   @0x19de84 cmp r5, #0
 *   @0x19de88 beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84>
 *   @0x19de8c ldr r3, [r4, #0x14]
 *   @0x19de90 ldr r2, [r5, #0x7c]
 *   @0x19de94 cmp r2, r3
 *   @0x19de98 mov r1, r3
 *   @0x19de9c bne 0x19dff4 <_ZN15WithObjIteratordeEv+0x1a8>
 *   @0x19dea0 mov r0, r5
 *   @0x19dea4 pop {r3, r4, r5, pc}
 *   @0x19dea8 ldr r5, [r0, #0x4]
 *   @0x19deac mov r0, r5
 *   @0x19deb0 pop {r3, r4, r5, pc}
 *   @0x19deb4 ldr r5, [r0, #0x10]
 *   @0x19deb8 mov r0, r5
 *   @0x19debc pop {r3, r4, r5, pc}
 *   @0x19dec0 ldr r3, [r0]
 *   @0x19dec4 cmp r3, #0
 *   @0x19dec8 ldrne r5, [r3, #0x8]
 *   @0x19decc bne 0x19dea0 <_ZN15WithObjIteratordeEv+0x54>
 *   @0x19ded0 mov r5, #0
 *   @0x19ded4 mov r0, r5
 *   @0x19ded8 pop {r3, r4, r5, pc}
 *   @0x19dedc ldr r2, [pc, #0x13c]
 *   @0x19dee0 ldr r0, [r0, #0x1c]
 *   @0x19dee4 ldr r2, [pc, r2]
 *   @0x19dee8 ldr r1, [r2, #0x8]
 *   @0x19deec mov r3, r0
 *   @0x19def0 cmp r0, r1
 *   @0x19def4 movge r3, #2
 *   @0x19def8 strge r3, [r4, #0x18]
 *   @0x19defc bge 0x19df5c <_ZN15WithObjIteratordeEv+0x110>
 *   @0x19df00 cmp r3, #0
 *   @0x19df04 ldr r12, [r2]
 *   @0x19df08 ldrge r0, [r2]
 *   @0x19df0c movlt r5, #0
 *   @0x19df10 ldrge r5, [r0, r3, lsl #2]
 *   @0x19df14 ldr r0, [r4, #0x14]
 *   @0x19df18 b 0x19df28 <_ZN15WithObjIteratordeEv+0xdc>
 *   @0x19df1c cmp r3, #0
 *   @0x19df20 ldrge r5, [r12, r3, lsl #2]
 *   @0x19df24 movlt r5, #0
 *   @0x19df28 ldr r2, [r5, #0x7c]
 *   @0x19df2c add r3, r3, #1
 *   @0x19df30 cmp r0, r2
 *   @0x19df34 beq 0x19dea0 <_ZN15WithObjIteratordeEv+0x54>
 *   @0x19df38 cmp r1, r3
 *   @0x19df3c str r3, [r4, #0x1c]
 *   @0x19df40 bgt 0x19df1c <_ZN15WithObjIteratordeEv+0xd0>
 *   @0x19df44 mov r0, #0
 *   @0x19df48 mov r3, #2
 *   @0x19df4c str r0, [r4, #0x1c]
 *   @0x19df50 str r3, [r4, #0x18]
 *   @0x19df54 b 0x19df5c <_ZN15WithObjIteratordeEv+0x110>
 *   @0x19df58 ldr r0, [r0, #0x1c]
 *   @0x19df5c ldr r3, [pc, #0xc0]
 *   @0x19df60 ldr r3, [pc, r3]
 *   @0x19df64 ldr r2, [r3, #0x8]
 *   @0x19df68 cmp r2, r0
 *   @0x19df6c movle r3, #3
 *   @0x19df70 strle r3, [r4, #0x18]
 *   @0x19df74 ble 0x19dfd0 <_ZN15WithObjIteratordeEv+0x184>
 *   @0x19df78 cmp r0, #0
 *   @0x19df7c ldrge r1, [r3]
 *   @0x19df80 movlt r5, #0
 *   @0x19df84 ldrge r5, [r1, r0, lsl #2]
 *   @0x19df88 ldr r0, [r3]
 *   @0x19df8c ldr r1, [r4, #0x14]
 *   @0x19df90 b 0x19dfa0 <_ZN15WithObjIteratordeEv+0x154>
 *   @0x19df94 cmp r3, #0
 *   @0x19df98 ldrge r5, [r0, r3, lsl #2]
 *   @0x19df9c movlt r5, #0
 *   @0x19dfa0 ldr r3, [r5, #0x7c]
 *   @0x19dfa4 cmp r3, r1
 *   @0x19dfa8 beq 0x19dea0 <_ZN15WithObjIteratordeEv+0x54>
 *   @0x19dfac ldr r3, [r4, #0x1c]
 *   @0x19dfb0 add r3, r3, #1
 *   @0x19dfb4 str r3, [r4, #0x1c]
 *   @0x19dfb8 cmp r2, r3
 *   @0x19dfbc bgt 0x19df94 <_ZN15WithObjIteratordeEv+0x148>
 *   @0x19dfc0 mov r2, #3
 *   @0x19dfc4 mov r3, #0
 *   @0x19dfc8 str r2, [r4, #0x18]
 *   @0x19dfcc str r3, [r4, #0x1c]
 *   @0x19dfd0 ldrb r3, [r4, #0x20]
 *   @0x19dfd4 cmp r3, #0
 *   @0x19dfd8 beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84>
 *   @0x19dfdc ldr r3, [pc, #0x44]
 *   @0x19dfe0 ldr r3, [pc, r3]
 *   @0x19dfe4 ldr r3, [r3]
 *   @0x19dfe8 ldr r5, [r3, #0x8c]
 *   @0x19dfec str r5, [r4, #0x8]
 *   @0x19dff0 b 0x19de84 <_ZN15WithObjIteratordeEv+0x38>
 *   @0x19dff4 ldr r0, [r4, #0xc]
 *   @0x19dff8 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x19dffc cmp r0, #0
 *   @0x19e000 bne 0x19dea0 <_ZN15WithObjIteratordeEv+0x54>
 *   @0x19e004 ldr r3, [r4, #0x8]
 *   @0x19e008 cmp r3, #0
 *   @0x19e00c beq 0x19ded0 <_ZN15WithObjIteratordeEv+0x84>
 *   @0x19e010 ldr r3, [r3, #0x178]
 *   @0x19e014 mov r5, r3
 *   @0x19e018 str r3, [r4, #0x8]
 *   @0x19e01c b 0x19de84 <_ZN15WithObjIteratordeEv+0x38>
 *   @0x19e020 eoreq pc, r4, r12, asr sp
 *   @0x19e024 eoreq pc, r4, r8, ror #25
 *   @0x19e028 eoreq pc, r4, r8, asr #18
 *
 * ══ §7/69 ThrowConnectingSocketNetworkEvent  0x2987cc  size 480  120 条（0x2987cc..0x2989ac）
 * @func 0x2987cc 0x2989ac  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2987f4→0x3f7814, 0x2988a8→0x3f5254, 0x2988ac→0x536f70, 0x2988cc→0x542374, 0x2988d4→0x53ab70
 * 调用序列: F_DsMapAdd_Internal(int, char*, double)×5 / InitNetworkEvent() / F_DsMapAdd_Internal(int, char*, char*) / ThrowConnectingSocketNetworkEvent(int, int, int, int, char*, bool)+0x1a4 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x184×2 / 0xec×2 / 0x4×2 / 0x8×2 / 0x2c×1 / 0x28×1 / 0x17c×1 / 0x160×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2987cc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2987d0 mov r10, r0
 *   @0x2987d4 mov r9, r1
 *   @0x2987d8 mov r8, r2
 *   @0x2987dc mov r7, r3
 *   @0x2987e0 ldrb r4, [sp, #0x2c]
 *   @0x2987e4 ldr r6, [sp, #0x28]
 *   @0x2987e8 bl 0x29871c <_Z16InitNetworkEventv>
 *   @0x2987ec vmov.f64 d6, #2.000000e+00
 *   @0x2987f0 ldr r5, [pc, #0x184]
 *   @0x2987f4 ldr r12, [pc, #0x184]
 *   @0x2987f8 cmp r4, #0
 *   @0x2987fc add r5, pc, r5
 *   @0x298800 ldr r1, [pc, #0x17c]
 *   @0x298804 ldr r4, [r5, r12]
 *   @0x298808 add r1, pc, r1
 *   @0x29880c ldr r0, [r4]
 *   @0x298810 vmov.f64 d7, #1.000000e+00
 *   @0x298814 vmovne r2, r3, d7
 *   @0x298818 vmoveq r2, r3, d6
 *   @0x29881c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298820 ldr r1, [pc, #0x160]
 *   @0x298824 vmov s15, r10
 *   @0x298828 ldr r0, [r4]
 *   @0x29882c add r1, pc, r1
 *   @0x298830 movw r10, #0x1d10
 *   @0x298834 vcvt.f64.s32 d7, s15
 *   @0x298838 vmov r2, r3, d7
 *   @0x29883c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298840 ldr r1, [pc, #0x144]
 *   @0x298844 vmov s15, r9
 *   @0x298848 ldr r0, [r4]
 *   @0x29884c add r1, pc, r1
 *   @0x298850 vcvt.f64.s32 d7, s15
 *   @0x298854 vmov r2, r3, d7
 *   @0x298858 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x29885c ldr r1, [pc, #0x12c]
 *   @0x298860 vmov s15, r8
 *   @0x298864 ldr r0, [r4]
 *   @0x298868 add r1, pc, r1
 *   @0x29886c vcvt.f64.s32 d7, s15
 *   @0x298870 vmov r2, r3, d7
 *   @0x298874 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298878 ldr r1, [pc, #0x114]
 *   @0x29887c vmov s15, r7
 *   @0x298880 ldr r0, [r4]
 *   @0x298884 add r1, pc, r1
 *   @0x298888 vcvt.f64.s32 d7, s15
 *   @0x29888c vmov r2, r3, d7
 *   @0x298890 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298894 ldr r1, [pc, #0xfc]
 *   @0x298898 mov r2, r6
 *   @0x29889c ldr r0, [r4]
 *   @0x2988a0 add r1, pc, r1
 *   @0x2988a4 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_>
 *   @0x2988a8 ldr r1, [pc, #0xec]
 *   @0x2988ac ldr r3, [pc, #0xec]
 *   @0x2988b0 ldr r2, [r4]
 *   @0x2988b4 ldr r8, [r5, r1]
 *   @0x2988b8 str r2, [r8]
 *   @0x2988bc ldr r9, [r5, r3]
 *   @0x2988c0 ldr r3, [r9, r10]
 *   @0x2988c4 cmp r3, #0
 *   @0x2988c8 ble 0x298970 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x1a4>
 *   @0x2988cc ldr r2, [pc, #0xd0]
 *   @0x2988d0 mov r4, #0
 *   @0x2988d4 ldr r3, [pc, #0xcc]
 *   @0x2988d8 movw r7, #0x3a24
 *   @0x2988dc ldr r6, [r5, r2]
 *   @0x2988e0 ldr r5, [r5, r3]
 *   @0x2988e4 ldr r3, [r6]
 *   @0x2988e8 ldr r1, [r5, r7]
 *   @0x2988ec ldr r2, [r3, #0x4]
 *   @0x2988f0 ldr r1, [r1, r4, lsl #2]
 *   @0x2988f4 ldr r3, [r3]
 *   @0x2988f8 and r2, r1, r2
 *   @0x2988fc ldr r3, [r3, r2, lsl #3]
 *   @0x298900 cmp r3, #0
 *   @0x298904 bne 0x298918 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x14c>
 *   @0x298908 b 0x298928 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x15c>
 *   @0x29890c ldr r3, [r3, #0x4]
 *   @0x298910 cmp r3, #0
 *   @0x298914 beq 0x298928 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x15c>
 *   @0x298918 ldr r2, [r3, #0x8]
 *   @0x29891c cmp r1, r2
 *   @0x298920 bne 0x29890c <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x140>
 *   @0x298924 ldr r3, [r3, #0xc]
 *   @0x298928 ldr r11, [r3, #0xc4]
 *   @0x29892c cmp r11, #0
 *   @0x298930 bne 0x298954 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x188>
 *   @0x298934 b 0x298960 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x194>
 *   @0x298938 ldr r11, [r11]
 *   @0x29893c mov r1, r0
 *   @0x298940 mov r2, #7
 *   @0x298944 mov r3, #68
 *   @0x298948 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x29894c cmp r11, #0
 *   @0x298950 beq 0x298960 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x194>
 *   @0x298954 ldr r0, [r11, #0x8]
 *   @0x298958 cmp r0, #0
 *   @0x29895c bne 0x298938 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x16c>
 *   @0x298960 ldr r3, [r9, r10]
 *   @0x298964 add r4, r4, #1
 *   @0x298968 cmp r3, r4
 *   @0x29896c bgt 0x2988e4 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x118>
 *   @0x298970 mvn r3, #0
 *   @0x298974 str r3, [r8]
 *   @0x298978 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29897c andseq r9, r5, r4, asr r4
 *   @0x298980 .word 0xfffff750
 *   @0x298984 andeq sp, r10, r0, lsr #18
 *   @0x298988 andeq r8, r9, r4, lsl r2
 *   @0x29898c andeq r0, r12, r12, lsr lr
 *   @0x298990 andeq r0, r12, r8, lsr #28
 *   @0x298994 andeq r0, r12, r4, lsl lr
 *   @0x298998 andeq r0, r12, r4, lsl #28
 *   @0x29899c .word 0xffffdec8
 *   @0x2989a0 .word 0xffffdeb8
 *   @0x2989a4 .word 0xffffbfec
 *   @0x2989a8 .word 0xffffdebc
 *
 * ══ §8/69 CIAPProduct::SetFromJSON  0x18b168  size 476  119 条（0x18b168..0x18b344）
 * @func 0x18b168 0x18b344  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0×5 / json_object_get_string×5 / YYFree(void const*)×5 / YYStrDup(char const*)×5 / json_object_get_object / json_object_get_type
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x1a0×3 / 0x10×2 / 0xc×2 / 0x20×1 / 0x19c×1 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b168 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18b16c mov r6, r0
 *   @0x18b170 sub sp, sp, #12
 *   @0x18b174 mov r0, r1
 *   @0x18b178 bl 0x27e8f4 <json_object_get_object>
 *   @0x18b17c ldr r4, [r0, #0x20]
 *   @0x18b180 cmp r4, #0
 *   @0x18b184 beq 0x18b278 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x110>
 *   @0x18b188 ldr r7, [pc, #0x1a0]
 *   @0x18b18c ldr r8, [pc, #0x1a0]
 *   @0x18b190 ldr r9, [pc, #0x1a0]
 *   @0x18b194 add r7, pc, r7
 *   @0x18b198 ldr r10, [pc, #0x19c]
 *   @0x18b19c add r8, pc, r8
 *   @0x18b1a0 ldr r3, [pc, #0x198]
 *   @0x18b1a4 add r9, pc, r9
 *   @0x18b1a8 add r10, pc, r10
 *   @0x18b1ac add r3, pc, r3
 *   @0x18b1b0 str r3, [sp, #0x4]
 *   @0x18b1b4 b 0x18b1c4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x5c>
 *   @0x18b1b8 ldr r4, [r4, #0x8]
 *   @0x18b1bc cmp r4, #0
 *   @0x18b1c0 beq 0x18b278 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x110>
 *   @0x18b1c4 ldm r4, {r5, r11}
 *   @0x18b1c8 cmp r11, #0
 *   @0x18b1cc beq 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b1d0 mov r0, r11
 *   @0x18b1d4 bl 0x27e828 <json_object_get_type>
 *   @0x18b1d8 cmp r0, #6
 *   @0x18b1dc bne 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b1e0 mov r0, r5
 *   @0x18b1e4 mov r1, r7
 *   @0x18b1e8 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b1ec cmp r0, #0
 *   @0x18b1f0 beq 0x18b280 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x118>
 *   @0x18b1f4 mov r0, r5
 *   @0x18b1f8 mov r1, r8
 *   @0x18b1fc bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b200 cmp r0, #0
 *   @0x18b204 beq 0x18b2ac <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x144>
 *   @0x18b208 mov r0, r5
 *   @0x18b20c mov r1, r9
 *   @0x18b210 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b214 cmp r0, #0
 *   @0x18b218 beq 0x18b2d8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x170>
 *   @0x18b21c mov r0, r5
 *   @0x18b220 mov r1, r10
 *   @0x18b224 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b228 cmp r0, #0
 *   @0x18b22c beq 0x18b304 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x19c>
 *   @0x18b230 mov r0, r5
 *   @0x18b234 ldr r1, [sp, #0x4]
 *   @0x18b238 bl 0xb66d0 <strcasecmp@plt>
 *   @0x18b23c cmp r0, #0
 *   @0x18b240 bne 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b244 mov r0, r11
 *   @0x18b248 bl 0x27ed58 <json_object_get_string>
 *   @0x18b24c mov r5, r0
 *   @0x18b250 ldr r0, [r6, #0x10]
 *   @0x18b254 cmp r0, #0
 *   @0x18b258 beq 0x18b260 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0xf8>
 *   @0x18b25c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b260 mov r0, r5
 *   @0x18b264 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b268 str r0, [r6, #0x10]
 *   @0x18b26c ldr r4, [r4, #0x8]
 *   @0x18b270 cmp r4, #0
 *   @0x18b274 bne 0x18b1c4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x5c>
 *   @0x18b278 add sp, sp, #12
 *   @0x18b27c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18b280 mov r0, r11
 *   @0x18b284 bl 0x27ed58 <json_object_get_string>
 *   @0x18b288 mov r5, r0
 *   @0x18b28c ldr r0, [r6]
 *   @0x18b290 cmp r0, #0
 *   @0x18b294 beq 0x18b29c <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x134>
 *   @0x18b298 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b29c mov r0, r5
 *   @0x18b2a0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b2a4 str r0, [r6]
 *   @0x18b2a8 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b2ac mov r0, r11
 *   @0x18b2b0 bl 0x27ed58 <json_object_get_string>
 *   @0x18b2b4 mov r5, r0
 *   @0x18b2b8 ldr r0, [r6, #0x4]
 *   @0x18b2bc cmp r0, #0
 *   @0x18b2c0 beq 0x18b2c8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x160>
 *   @0x18b2c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b2c8 mov r0, r5
 *   @0x18b2cc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b2d0 str r0, [r6, #0x4]
 *   @0x18b2d4 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b2d8 mov r0, r11
 *   @0x18b2dc bl 0x27ed58 <json_object_get_string>
 *   @0x18b2e0 mov r5, r0
 *   @0x18b2e4 ldr r0, [r6, #0xc]
 *   @0x18b2e8 cmp r0, #0
 *   @0x18b2ec beq 0x18b2f4 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x18c>
 *   @0x18b2f0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b2f4 mov r0, r5
 *   @0x18b2f8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b2fc str r0, [r6, #0xc]
 *   @0x18b300 b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b304 mov r0, r11
 *   @0x18b308 bl 0x27ed58 <json_object_get_string>
 *   @0x18b30c mov r5, r0
 *   @0x18b310 ldr r0, [r6, #0x8]
 *   @0x18b314 cmp r0, #0
 *   @0x18b318 beq 0x18b320 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x1b8>
 *   @0x18b31c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x18b320 mov r0, r5
 *   @0x18b324 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18b328 str r0, [r6, #0x8]
 *   @0x18b32c b 0x18b1b8 <_ZN11CIAPProduct11SetFromJSONEP11json_object+0x50>
 *   @0x18b330 mulseq r11, r12, r0
 *   @0x18b334 andseq lr, r11, r0, lsr r6
 *   @0x18b338 andseq r1, r12, r12, asr #32
 *   @0x18b33c andseq r11, r11, r4, lsl r4
 *   @0x18b340 andseq r10, r11, r12, ror pc
 *
 * ══ §9/69 YYObjectBase::Mark4GC  0x191bdc  size 476  119 条（0x191bdc..0x191db8）
 * @func 0x191bdc 0x191db8  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x191bec→0x3f5044, 0x191c08→0x3f5048, 0x191c20→0x536f08, 0x191c40→0x47a21c
 * 调用序列: RVALUE_GC(RValue const*, unsigned int*, int)×4 / YYObjectBase::Mark4GC(unsigned int*, int)+0xa8 / YYObjectBase::Mark4GC(unsigned int*, int) / YYObjectBase::Mark4GC(unsigned int*, int)+0x13c
 * 字段偏移 top8: 0x4×3 / 0x34×2 / 0x28×2 / 0x60×2 / 0x24×2 / 0x2×2 / 0x1b8×1 / 0x1b4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191bdc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x191be0 mov r8, r0
 *   @0x191be4 ldr r3, [pc, #0x1b8]
 *   @0x191be8 mov r6, r2
 *   @0x191bec ldr r0, [pc, #0x1b4]
 *   @0x191bf0 mov r7, r1
 *   @0x191bf4 add r3, pc, r3
 *   @0x191bf8 ldr r2, [r3, r0]
 *   @0x191bfc ldrb r1, [r2]
 *   @0x191c00 cmp r1, #0
 *   @0x191c04 bne 0x191c20 <_ZN12YYObjectBase7Mark4GCEPji+0x44>
 *   @0x191c08 ldr r1, [pc, #0x19c]
 *   @0x191c0c ldr r0, [r8, #0x38]
 *   @0x191c10 ldr r1, [r3, r1]
 *   @0x191c14 ldr r1, [r1]
 *   @0x191c18 cmp r0, r1
 *   @0x191c1c popgt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x191c20 ldr r0, [pc, #0x188]
 *   @0x191c24 mov r1, #0
 *   @0x191c28 strb r1, [r2]
 *   @0x191c2c ldr r1, [r8, #0x34]
 *   @0x191c30 ldr r2, [r3, r0]
 *   @0x191c34 ldr r2, [r2]
 *   @0x191c38 cmp r1, r2
 *   @0x191c3c pophs {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x191c40 ldr r1, [pc, #0x16c]
 *   @0x191c44 str r2, [r8, #0x34]
 *   @0x191c48 ldr r2, [r8, #0x48]
 *   @0x191c4c ldr r3, [r3, r1]
 *   @0x191c50 cmp r2, #3
 *   @0x191c54 ldr r1, [r8, #0x28]
 *   @0x191c58 ldr r2, [r3]
 *   @0x191c5c bic r1, r1, #2
 *   @0x191c60 str r1, [r8, #0x28]
 *   @0x191c64 add r2, r2, #1
 *   @0x191c68 str r2, [r3]
 *   @0x191c6c beq 0x191d80 <_ZN12YYObjectBase7Mark4GCEPji+0x1a4>
 *   @0x191c70 ldr r3, [r8, #0x44]
 *   @0x191c74 cmp r3, #0
 *   @0x191c78 blt 0x191c84 <_ZN12YYObjectBase7Mark4GCEPji+0xa8>
 *   @0x191c7c cmp r6, r3
 *   @0x191c80 bgt 0x191d64 <_ZN12YYObjectBase7Mark4GCEPji+0x188>
 *   @0x191c84 ldr r0, [r8, #0x18]
 *   @0x191c88 cmp r0, #0
 *   @0x191c8c beq 0x191c9c <_ZN12YYObjectBase7Mark4GCEPji+0xc0>
 *   @0x191c90 mov r1, r7
 *   @0x191c94 mov r2, r6
 *   @0x191c98 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0x191c9c ldr r12, [r8, #0x60]
 *   @0x191ca0 cmp r12, #0
 *   @0x191ca4 beq 0x191d18 <_ZN12YYObjectBase7Mark4GCEPji+0x13c>
 *   @0x191ca8 ldr r3, [r12, #0x4]
 *   @0x191cac cmp r3, #0
 *   @0x191cb0 ble 0x191d18 <_ZN12YYObjectBase7Mark4GCEPji+0x13c>
 *   @0x191cb4 mov r4, #0
 *   @0x191cb8 mov r9, r4
 *   @0x191cbc add r3, r4, r4, lsl #1
 *   @0x191cc0 ldr r2, [r12, #0x10]
 *   @0x191cc4 ldr r5, [r12]
 *   @0x191cc8 add r3, r2, r3, lsl #2
 *   @0x191ccc b 0x191cdc <_ZN12YYObjectBase7Mark4GCEPji+0x100>
 *   @0x191cd0 ldr lr, [r12, #0x8]
 *   @0x191cd4 cmp lr, #0
 *   @0x191cd8 bgt 0x191d5c <_ZN12YYObjectBase7Mark4GCEPji+0x180>
 *   @0x191cdc add r4, r4, #1
 *   @0x191ce0 mov r12, r3
 *   @0x191ce4 cmp r5, r4
 *   @0x191ce8 add r3, r3, #12
 *   @0x191cec bge 0x191cd0 <_ZN12YYObjectBase7Mark4GCEPji+0xf4>
 *   @0x191cf0 mov r12, #0
 *   @0x191cf4 ldr r0, [r12]
 *   @0x191cf8 mov r1, r7
 *   @0x191cfc mov r2, r6
 *   @0x191d00 add r9, r9, #1
 *   @0x191d04 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x191d08 ldr r12, [r8, #0x60]
 *   @0x191d0c ldr r3, [r12, #0x4]
 *   @0x191d10 cmp r3, r9
 *   @0x191d14 bgt 0x191cbc <_ZN12YYObjectBase7Mark4GCEPji+0xe0>
 *   @0x191d18 ldr r4, [r8, #0x4]
 *   @0x191d1c cmp r4, #0
 *   @0x191d20 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x191d24 ldr r3, [r8, #0x24]
 *   @0x191d28 cmp r3, #0
 *   @0x191d2c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x191d30 mov r5, #0
 *   @0x191d34 mov r0, r4
 *   @0x191d38 mov r1, r7
 *   @0x191d3c mov r2, r6
 *   @0x191d40 add r5, r5, #1
 *   @0x191d44 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x191d48 ldr r3, [r8, #0x24]
 *   @0x191d4c add r4, r4, #16
 *   @0x191d50 cmp r3, r5
 *   @0x191d54 bhi 0x191d34 <_ZN12YYObjectBase7Mark4GCEPji+0x158>
 *   @0x191d58 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x191d5c add r12, r12, #4
 *   @0x191d60 b 0x191cf4 <_ZN12YYObjectBase7Mark4GCEPji+0x118>
 *   @0x191d64 asr r2, r3, #5
 *   @0x191d68 mov r0, #1
 *   @0x191d6c and r3, r3, #31
 *   @0x191d70 ldr r1, [r7, r2, lsl #2]
 *   @0x191d74 orr r3, r1, r0, lsl r3
 *   @0x191d78 str r3, [r7, r2, lsl #2]
 *   @0x191d7c b 0x191c84 <_ZN12YYObjectBase7Mark4GCEPji+0xa8>
 *   @0x191d80 add r0, r8, #108
 *   @0x191d84 mov r1, r7
 *   @0x191d88 mov r2, r6
 *   @0x191d8c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x191d90 add r0, r8, #124
 *   @0x191d94 mov r1, r7
 *   @0x191d98 mov r2, r6
 *   @0x191d9c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji>
 *   @0x191da0 b 0x191c70 <_ZN12YYObjectBase7Mark4GCEPji+0x94>
 *   @0x191da4 eoreq r0, r6, r12, asr r0
 *   @0x191da8 .word 0xffffc03c
 *   @0x191dac .word 0xffffc038
 *   @0x191db0 .word 0xffffbffc
 *   @0x191db4 .word 0xffffc034
 *
 * ══ §10/69 YYObjectBase::FreeVars  0x198dac  size 476  119 条（0x198dac..0x198f88）
 * @func 0x198dac 0x198f98  size 492  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / MemoryManager::Free(void const*)×2 / YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**)+0x1c4 / YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**)+0x1cc / YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**)+0xc0 / operator delete(void*) / FreeRValue(RValue*, RValue**, RValue**)
 * 字段偏移 top8: 0x4×10 / 0x10×5 / 0xc×4 / 0x8×3 / 0x60×3 / 0x24×2 / 0x1c×2 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x198dac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x198db0 mov r8, r0
 *   @0x198db4 ldr r4, [r0, #0x4]
 *   @0x198db8 sub sp, sp, #12
 *   @0x198dbc mov r10, r1
 *   @0x198dc0 mov r11, r2
 *   @0x198dc4 cmp r4, #0
 *   @0x198dc8 beq 0x198e34 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x88>
 *   @0x198dcc ldr r5, [r0, #0x24]
 *   @0x198dd0 cmp r5, #0
 *   @0x198dd4 ble 0x198f70 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x1c4>
 *   @0x198dd8 mov r6, #0
 *   @0x198ddc mov r7, #5
 *   @0x198de0 b 0x198df8 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x4c>
 *   @0x198de4 subs r5, r5, #1
 *   @0x198de8 str r6, [r4, #0x8]
 *   @0x198dec str r7, [r4, #0xc]
 *   @0x198df0 str r6, [r4], #16
 *   @0x198df4 beq 0x198e1c <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x70>
 *   @0x198df8 ldr r3, [r4, #0xc]
 *   @0x198dfc sub r3, r3, #1
 *   @0x198e00 bic r3, r3, #-16777216
 *   @0x198e04 bic r3, r3, #3
 *   @0x198e08 cmp r3, #0
 *   @0x198e0c bne 0x198de4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x38>
 *   @0x198e10 mov r0, r4
 *   @0x198e14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x198e18 b 0x198de4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x38>
 *   @0x198e1c ldr r0, [r8, #0x4]
 *   @0x198e20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x198e24 mov r3, #0
 *   @0x198e28 str r3, [r8, #0x4]
 *   @0x198e2c str r3, [r8, #0x2c]
 *   @0x198e30 str r3, [r8, #0x24]
 *   @0x198e34 ldr r12, [r8, #0x60]
 *   @0x198e38 cmp r12, #0
 *   @0x198e3c beq 0x198ec0 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x114>
 *   @0x198e40 ldr r7, [r12, #0x4]
 *   @0x198e44 cmp r7, #0
 *   @0x198e48 blt 0x198f78 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x1cc>
 *   @0x198e4c ldr r1, [r12]
 *   @0x198e50 mov r4, #0
 *   @0x198e54 ldr r0, [r12, #0x10]
 *   @0x198e58 mov r6, r4
 *   @0x198e5c mov r9, #5
 *   @0x198e60 add r3, r4, r4, lsl #1
 *   @0x198e64 add r3, r0, r3, lsl #2
 *   @0x198e68 b 0x198e78 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xcc>
 *   @0x198e6c ldr r2, [r5, #0x8]
 *   @0x198e70 cmp r2, #0
 *   @0x198e74 bgt 0x198f18 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x16c>
 *   @0x198e78 add r4, r4, #1
 *   @0x198e7c mov r5, r3
 *   @0x198e80 cmp r4, r1
 *   @0x198e84 add r3, r3, #12
 *   @0x198e88 ble 0x198e6c <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xc0>
 *   @0x198e8c subs r7, r7, #1
 *   @0x198e90 bhs 0x198e60 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xb4>
 *   @0x198e94 cmp r0, #0
 *   @0x198e98 beq 0x198eb0 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x104>
 *   @0x198e9c str r12, [sp, #0x4]
 *   @0x198ea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x198ea4 ldr r12, [sp, #0x4]
 *   @0x198ea8 mov r3, #0
 *   @0x198eac str r3, [r12, #0x10]
 *   @0x198eb0 mov r0, r12
 *   @0x198eb4 bl 0x27d1d0 <_ZdlPv>
 *   @0x198eb8 mov r3, #0
 *   @0x198ebc str r3, [r8, #0x60]
 *   @0x198ec0 ldr r0, [r8, #0x1c]
 *   @0x198ec4 cmp r0, #0
 *   @0x198ec8 beq 0x198ee4 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x138>
 *   @0x198ecc ldr r3, [pc, #0xac]
 *   @0x198ed0 ldr r3, [pc, r3]
 *   @0x198ed4 ldr r3, [r3]
 *   @0x198ed8 blx r3
 *   @0x198edc mov r3, #0
 *   @0x198ee0 str r3, [r8, #0x1c]
 *   @0x198ee4 ldr r0, [r8, #0x20]
 *   @0x198ee8 cmp r0, #0
 *   @0x198eec beq 0x198f08 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x15c>
 *   @0x198ef0 ldr r3, [pc, #0x8c]
 *   @0x198ef4 ldr r3, [pc, r3]
 *   @0x198ef8 ldr r3, [r3]
 *   @0x198efc blx r3
 *   @0x198f00 mov r3, #0
 *   @0x198f04 str r3, [r8, #0x20]
 *   @0x198f08 mov r3, #0
 *   @0x198f0c str r3, [r8, #0x18]
 *   @0x198f10 add sp, sp, #12
 *   @0x198f14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x198f18 ldr r3, [r5, #0x4]
 *   @0x198f1c ldr r2, [r3, #0xc]
 *   @0x198f20 sub r2, r2, #1
 *   @0x198f24 bic r2, r2, #-16777216
 *   @0x198f28 bic r2, r2, #3
 *   @0x198f2c cmp r2, #0
 *   @0x198f30 bne 0x198f44 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x198>
 *   @0x198f34 mov r0, r3
 *   @0x198f38 str r3, [sp, #0x4]
 *   @0x198f3c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x198f40 ldr r3, [sp, #0x4]
 *   @0x198f44 str r6, [r3]
 *   @0x198f48 mov r1, r10
 *   @0x198f4c ldr r0, [r5, #0x4]
 *   @0x198f50 mov r2, r11
 *   @0x198f54 str r6, [r3, #0x8]
 *   @0x198f58 str r9, [r3, #0xc]
 *   @0x198f5c bl 0x190e84 <_Z10FreeRValueP6RValuePS0_S1_>
 *   @0x198f60 ldr r12, [r8, #0x60]
 *   @0x198f64 ldr r1, [r12]
 *   @0x198f68 ldr r0, [r12, #0x10]
 *   @0x198f6c b 0x198e60 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xb4>
 *   @0x198f70 mov r0, r4
 *   @0x198f74 b 0x198e20 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0x74>
 *   @0x198f78 ldr r0, [r12, #0x10]
 *   @0x198f7c b 0x198e94 <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_+0xe8>
 *   @0x198f80 .word 0x002577b8
 *   @0x198f84 mlaeq r5, r4, r7, r7
 *
 * ══ §11/69 CPath::GetPosition  0x1a73bc  size 476  119 条（0x1a73bc..0x1a7598）
 * @func 0x1a73bc 0x1a7598  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPosition(float, float&, float&, float&)+0xa8 / CPath::GetPosition(float, float&, float&, float&)+0xb0 / CPath::GetPosition(float, float&, float&, float&)+0x138 / CPath::GetPosition(float, float&, float&, float&)+0x1d4
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x8×3 / 0x20×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a73bc push {r4, r5, r6}
 *   @0x1a73c0 vmov s15, r1
 *   @0x1a73c4 ldr r12, [r0, #0x20]
 *   @0x1a73c8 mov r4, #0
 *   @0x1a73cc ldr r5, [sp, #0xc]
 *   @0x1a73d0 mov r6, #0
 *   @0x1a73d4 cmp r12, #0
 *   @0x1a73d8 str r4, [r2]
 *   @0x1a73dc movt r6, #0x42c8
 *   @0x1a73e0 str r4, [r3]
 *   @0x1a73e4 str r6, [r5]
 *   @0x1a73e8 ble 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8>
 *   @0x1a73ec cmp r12, #1
 *   @0x1a73f0 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c>
 *   @0x1a73f4 vldr s14, [r0, #36]
 *   @0x1a73f8 vcmp.f32 s14, #0
 *   @0x1a73fc vmrs APSR_nzcv, fpscr
 *   @0x1a7400 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c>
 *   @0x1a7404 vcmpe.f32 s15, #0
 *   @0x1a7408 vmrs APSR_nzcv, fpscr
 *   @0x1a740c bmi 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c>
 *   @0x1a7410 vmov.f32 s13, #1.000000e+00
 *   @0x1a7414 vcmpe.f32 s15, s13
 *   @0x1a7418 vmrs APSR_nzcv, fpscr
 *   @0x1a741c ble 0x1a746c <_ZN5CPath11GetPositionEfRfS0_S0_+0xb0>
 *   @0x1a7420 ldr r1, [r0, #0xc]
 *   @0x1a7424 sub r12, r12, #-268435455
 *   @0x1a7428 add r12, r1, r12, lsl #4
 *   @0x1a742c ldr r1, [r12]
 *   @0x1a7430 str r1, [r2]
 *   @0x1a7434 ldr r2, [r12, #0x4]
 *   @0x1a7438 str r2, [r3]
 *   @0x1a743c ldr r3, [r12, #0x8]
 *   @0x1a7440 str r3, [r5]
 *   @0x1a7444 b 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8>
 *   @0x1a7448 ldr r1, [r0, #0xc]
 *   @0x1a744c ldr r0, [r1]
 *   @0x1a7450 str r0, [r2]
 *   @0x1a7454 ldr r2, [r1, #0x4]
 *   @0x1a7458 str r2, [r3]
 *   @0x1a745c ldr r3, [r1, #0x8]
 *   @0x1a7460 str r3, [r5]
 *   @0x1a7464 pop {r4, r5, r6}
 *   @0x1a7468 bx lr
 *   @0x1a746c vcmp.f32 s15, #0
 *   @0x1a7470 vmrs APSR_nzcv, fpscr
 *   @0x1a7474 beq 0x1a7448 <_ZN5CPath11GetPositionEfRfS0_S0_+0x8c>
 *   @0x1a7478 vcmp.f32 s15, s13
 *   @0x1a747c vmrs APSR_nzcv, fpscr
 *   @0x1a7480 beq 0x1a7420 <_ZN5CPath11GetPositionEfRfS0_S0_+0x64>
 *   @0x1a7484 cmp r12, #2
 *   @0x1a7488 ldr r6, [r0, #0xc]
 *   @0x1a748c vmul.f32 s14, s14, s15
 *   @0x1a7490 moveq r1, #0
 *   @0x1a7494 addeq r12, r6, #16
 *   @0x1a7498 beq 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138>
 *   @0x1a749c vldr s15, [r6, #28]
 *   @0x1a74a0 vcmpe.f32 s14, s15
 *   @0x1a74a4 vmrs APSR_nzcv, fpscr
 *   @0x1a74a8 addlt r12, r6, #16
 *   @0x1a74ac movlt r1, #0
 *   @0x1a74b0 blt 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138>
 *   @0x1a74b4 sub r4, r12, #2
 *   @0x1a74b8 add r0, r6, #32
 *   @0x1a74bc mov r1, #0
 *   @0x1a74c0 b 0x1a74d4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x118>
 *   @0x1a74c4 vldr s15, [r0, #-4]
 *   @0x1a74c8 vcmpe.f32 s14, s15
 *   @0x1a74cc vmrs APSR_nzcv, fpscr
 *   @0x1a74d0 blt 0x1a7590 <_ZN5CPath11GetPositionEfRfS0_S0_+0x1d4>
 *   @0x1a74d4 add r1, r1, #1
 *   @0x1a74d8 mov r12, r0
 *   @0x1a74dc cmp r1, r4
 *   @0x1a74e0 add r0, r0, #16
 *   @0x1a74e4 bne 0x1a74c4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x108>
 *   @0x1a74e8 lsl r1, r1, #4
 *   @0x1a74ec add r12, r1, #16
 *   @0x1a74f0 add r12, r6, r12
 *   @0x1a74f4 add r1, r6, r1
 *   @0x1a74f8 ldr r0, [r1]
 *   @0x1a74fc str r0, [r2]
 *   @0x1a7500 ldr r0, [r1, #0x4]
 *   @0x1a7504 str r0, [r3]
 *   @0x1a7508 ldr r0, [r1, #0x8]
 *   @0x1a750c str r0, [r5]
 *   @0x1a7510 vldr s15, [r1, #12]
 *   @0x1a7514 vldr s13, [r12, #12]
 *   @0x1a7518 vsub.f32 s13, s13, s15
 *   @0x1a751c vcmp.f32 s13, #0
 *   @0x1a7520 vmrs APSR_nzcv, fpscr
 *   @0x1a7524 beq 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8>
 *   @0x1a7528 vsub.f32 s15, s14, s15
 *   @0x1a752c vldr s11, [r12]
 *   @0x1a7530 vldr s14, [r1]
 *   @0x1a7534 vldr s12, [r2]
 *   @0x1a7538 vsub.f32 s14, s11, s14
 *   @0x1a753c vmul.f32 s14, s14, s15
 *   @0x1a7540 vdiv.f32 s14, s14, s13
 *   @0x1a7544 vadd.f32 s14, s12, s14
 *   @0x1a7548 vstr s14, [r2]
 *   @0x1a754c vldr s12, [r12, #4]
 *   @0x1a7550 vldr s14, [r1, #4]
 *   @0x1a7554 vsub.f32 s14, s12, s14
 *   @0x1a7558 vldr s12, [r3]
 *   @0x1a755c vmul.f32 s14, s14, s15
 *   @0x1a7560 vdiv.f32 s14, s14, s13
 *   @0x1a7564 vadd.f32 s14, s12, s14
 *   @0x1a7568 vstr s14, [r3]
 *   @0x1a756c vldr s12, [r12, #8]
 *   @0x1a7570 vldr s14, [r1, #8]
 *   @0x1a7574 vsub.f32 s14, s12, s14
 *   @0x1a7578 vldr s12, [r5]
 *   @0x1a757c vmul.f32 s15, s14, s15
 *   @0x1a7580 vdiv.f32 s13, s15, s13
 *   @0x1a7584 vadd.f32 s13, s12, s13
 *   @0x1a7588 vstr s13, [r5]
 *   @0x1a758c b 0x1a7464 <_ZN5CPath11GetPositionEfRfS0_S0_+0xa8>
 *   @0x1a7590 lsl r1, r1, #4
 *   @0x1a7594 b 0x1a74f4 <_ZN5CPath11GetPositionEfRfS0_S0_+0x138>
 *
 * ══ §12/69 Debug_AddTag  0x29c3ec  size 476  119 条（0x29c3ec..0x29c5c8）
 * @func 0x29c3ec 0x29c5c8  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / Debug_AddTag(eTagNameType, char const*, ...)+0x40 / Debug_AddTag(eTagNameType, char const*, ...)+0xac / 0xb65bc / MemoryManager::Free(void const*) / 0xb6610 / 0xb6538 / 0xb65a4
 * 字段偏移 top8: 0xc×6 / 0x8×4 / 0xa×2 / 0x4×2 / 0x1a4×1 / 0x168×1 / 0x150×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c3ec push {r1, r2, r3}
 *   @0x29c3f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x29c3f4 mov r6, r0
 *   @0x29c3f8 ldr r4, [pc, #0x1a4]
 *   @0x29c3fc sub sp, sp, #12
 *   @0x29c400 add r4, pc, r4
 *   @0x29c404 ldrh r3, [r4, #8]
 *   @0x29c408 cmp r3, #4096
 *   @0x29c40c blo 0x29c42c <_Z12Debug_AddTag12eTagNameTypePKcz+0x40>
 *   @0x29c410 ldrb r3, [r4, #0xa]
 *   @0x29c414 cmp r3, #0
 *   @0x29c418 beq 0x29c53c <_Z12Debug_AddTag12eTagNameTypePKcz+0x150>
 *   @0x29c41c add sp, sp, #12
 *   @0x29c420 pop {r4, r5, r6, r7, r8, lr}
 *   @0x29c424 add sp, sp, #12
 *   @0x29c428 bx lr
 *   @0x29c42c ldr r2, [r4, #0xc]
 *   @0x29c430 cmp r2, #0
 *   @0x29c434 beq 0x29c578 <_Z12Debug_AddTag12eTagNameTypePKcz+0x18c>
 *   @0x29c438 ldr r12, [pc, #0x168]
 *   @0x29c43c add r3, r3, #1
 *   @0x29c440 add r12, pc, r12
 *   @0x29c444 ldrh r2, [r12]
 *   @0x29c448 cmp r3, r2
 *   @0x29c44c blt 0x29c498 <_Z12Debug_AddTag12eTagNameTypePKcz+0xac>
 *   @0x29c450 lsl r0, r2, #1
 *   @0x29c454 ldr r1, [pc, #0x150]
 *   @0x29c458 mov r3, #1
 *   @0x29c45c movw r2, #0x4c1
 *   @0x29c460 uxth r0, r0
 *   @0x29c464 add r1, pc, r1
 *   @0x29c468 strh r0, [r12]
 *   @0x29c46c lsl r0, r0, #2
 *   @0x29c470 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29c474 ldr r5, [r4, #0xc]
 *   @0x29c478 ldrh r2, [r4, #8]
 *   @0x29c47c mov r1, r5
 *   @0x29c480 lsl r2, r2, #2
 *   @0x29c484 mov r7, r0
 *   @0x29c488 bl 0xb65bc <memcpy@plt>
 *   @0x29c48c mov r0, r5
 *   @0x29c490 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29c494 str r7, [r4, #0xc]
 *   @0x29c498 ldr r4, [pc, #0x110]
 *   @0x29c49c add r0, sp, #40
 *   @0x29c4a0 ldr r2, [sp, #0x24]
 *   @0x29c4a4 mov r1, #512
 *   @0x29c4a8 add r4, pc, r4
 *   @0x29c4ac mov r3, r0
 *   @0x29c4b0 add r5, r4, #16
 *   @0x29c4b4 str r0, [sp, #0x4]
 *   @0x29c4b8 ldr r7, [pc, #0xf4]
 *   @0x29c4bc mov r0, r5
 *   @0x29c4c0 bl 0xb6610 <vsnprintf@plt>
 *   @0x29c4c4 mov r0, r5
 *   @0x29c4c8 mov r3, #0
 *   @0x29c4cc strb r3, [r4, #0x20f]
 *   @0x29c4d0 bl 0xb6538 <strlen@plt>
 *   @0x29c4d4 add r7, pc, r7
 *   @0x29c4d8 mov r3, #1
 *   @0x29c4dc movw r2, #0x4cd
 *   @0x29c4e0 mov r1, r7
 *   @0x29c4e4 add r0, r0, r3
 *   @0x29c4e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29c4ec mov r1, r5
 *   @0x29c4f0 mov r8, r0
 *   @0x29c4f4 bl 0xb65a4 <strcpy@plt>
 *   @0x29c4f8 mov r1, r7
 *   @0x29c4fc mov r2, #1232
 *   @0x29c500 mov r3, #1
 *   @0x29c504 mov r0, #8
 *   @0x29c508 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29c50c ldrh r2, [r4, #8]
 *   @0x29c510 ldr r1, [r4, #0xc]
 *   @0x29c514 mov r3, r0
 *   @0x29c518 str r6, [r0]
 *   @0x29c51c add r0, r2, #1
 *   @0x29c520 str r8, [r3, #0x4]
 *   @0x29c524 strh r0, [r4, #8]
 *   @0x29c528 str r3, [r1, r2, lsl #2]
 *   @0x29c52c add sp, sp, #12
 *   @0x29c530 pop {r4, r5, r6, r7, r8, lr}
 *   @0x29c534 add sp, sp, #12
 *   @0x29c538 bx lr
 *   @0x29c53c ldr r3, [pc, #0x74]
 *   @0x29c540 mov r2, #4096
 *   @0x29c544 ldr r1, [pc, #0x70]
 *   @0x29c548 ldr r3, [pc, r3]
 *   @0x29c54c add r1, pc, r1
 *   @0x29c550 ldr r0, [r3]
 *   @0x29c554 ldr r3, [r0]
 *   @0x29c558 ldr r3, [r3, #0xc]
 *   @0x29c55c blx r3
 *   @0x29c560 mov r3, #1
 *   @0x29c564 strb r3, [r4, #0xa]
 *   @0x29c568 add sp, sp, #12
 *   @0x29c56c pop {r4, r5, r6, r7, r8, lr}
 *   @0x29c570 add sp, sp, #12
 *   @0x29c574 bx lr
 *   @0x29c578 ldr r0, [pc, #0x40]
 *   @0x29c57c movw r2, #0x4bd
 *   @0x29c580 ldr r1, [pc, #0x3c]
 *   @0x29c584 mov r3, #1
 *   @0x29c588 add r0, pc, r0
 *   @0x29c58c add r1, pc, r1
 *   @0x29c590 ldrh r0, [r0]
 *   @0x29c594 lsl r0, r0, #2
 *   @0x29c598 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29c59c str r0, [r4, #0xc]
 *   @0x29c5a0 b 0x29c498 <_Z12Debug_AddTag12eTagNameTypePKcz+0xac>
 *   @0x29c5a4 subeq r11, r11, r8, lsl #16
 *   @0x29c5a8 ldrsbeq r11, [r5], -r0
 *   @0x29c5ac andeq sp, r11, r0, ror #10
 *   @0x29c5b0 subeq r11, r11, r0, ror #14
 *   @0x29c5b4 strdeq sp, lr, [r11], -r0
 *   @0x29c5b8 ldrsheq r1, [r5], -r8
 *   @0x29c5bc ldrdeq sp, lr, [r11], -r4
 *   @0x29c5c0 andseq r11, r5, r8, lsl #5
 *   @0x29c5c4 andeq sp, r11, r8, lsr r4
 *
 * ══ §13/69 CProfiler::FindOrCreateNode  0x2a04f4  size 476  119 条（0x2a04f4..0x2a06d0）
 * @func 0x2a04f4 0x2a06d0  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CProfiler::FindOrCreateNode(int, int)+0x84 / CProfiler::FindOrCreateNode(int, int)+0xf4 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×4 / 0x3×4 / 0xc×3 / 0x18×3 / 0x4×3 / 0x70×2 / 0x1c×2 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a04f4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a04f8 mov r6, r0
 *   @0x2a04fc ldr r8, [r0, #0x70]
 *   @0x2a0500 sub sp, sp, #8
 *   @0x2a0504 ldr r7, [r0, #0xc]
 *   @0x2a0508 add r8, r8, r8, lsl #2
 *   @0x2a050c ldr r12, [r7, #0x8]
 *   @0x2a0510 lsl r8, r8, #3
 *   @0x2a0514 add r3, r12, r8
 *   @0x2a0518 ldr r4, [r3, #0x18]
 *   @0x2a051c cmn r4, #1
 *   @0x2a0520 beq 0x2a057c <_ZN9CProfiler16FindOrCreateNodeEii+0x88>
 *   @0x2a0524 mov r0, r4
 *   @0x2a0528 b 0x2a0540 <_ZN9CProfiler16FindOrCreateNodeEii+0x4c>
 *   @0x2a052c ldr r3, [r3, #0x1c]
 *   @0x2a0530 mov r0, r4
 *   @0x2a0534 cmn r3, #1
 *   @0x2a0538 beq 0x2a057c <_ZN9CProfiler16FindOrCreateNodeEii+0x88>
 *   @0x2a053c mov r4, r3
 *   @0x2a0540 add r3, r4, r4, lsl #2
 *   @0x2a0544 ldr r5, [r12, r3, lsl #3]
 *   @0x2a0548 add r3, r12, r3, lsl #3
 *   @0x2a054c ubfx r5, r5, #0x0, #0x1c
 *   @0x2a0550 cmp r5, r2
 *   @0x2a0554 bne 0x2a052c <_ZN9CProfiler16FindOrCreateNodeEii+0x38>
 *   @0x2a0558 ldrb r5, [r3, #0x3]
 *   @0x2a055c cmp r1, r5, lsr #4
 *   @0x2a0560 bne 0x2a052c <_ZN9CProfiler16FindOrCreateNodeEii+0x38>
 *   @0x2a0564 cmp r4, #0
 *   @0x2a0568 blt 0x2a0578 <_ZN9CProfiler16FindOrCreateNodeEii+0x84>
 *   @0x2a056c mov r0, r4
 *   @0x2a0570 add sp, sp, #8
 *   @0x2a0574 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a0578 mov r4, r0
 *   @0x2a057c ldr r3, [r7]
 *   @0x2a0580 bic r5, r2, #-268435456
 *   @0x2a0584 ldr r2, [r7, #0x4]
 *   @0x2a0588 and r9, r1, #15
 *   @0x2a058c sub r1, r3, #1
 *   @0x2a0590 cmp r2, r1
 *   @0x2a0594 movlt r1, r2
 *   @0x2a0598 movlt r6, r7
 *   @0x2a059c blt 0x2a05e8 <_ZN9CProfiler16FindOrCreateNodeEii+0xf4>
 *   @0x2a05a0 lsl r2, r3, #1
 *   @0x2a05a4 str r2, [r7]
 *   @0x2a05a8 add r1, r2, r3, lsl #3
 *   @0x2a05ac ldr r2, [pc, #0x118]
 *   @0x2a05b0 mov r0, r12
 *   @0x2a05b4 mov r3, #104
 *   @0x2a05b8 mov r12, #0
 *   @0x2a05bc lsl r1, r1, #3
 *   @0x2a05c0 str r12, [sp]
 *   @0x2a05c4 add r2, pc, r2
 *   @0x2a05c8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2a05cc ldr r8, [r6, #0x70]
 *   @0x2a05d0 ldr r1, [r7, #0x4]
 *   @0x2a05d4 ldr r6, [r6, #0xc]
 *   @0x2a05d8 add r8, r8, r8, lsl #2
 *   @0x2a05dc lsl r8, r8, #3
 *   @0x2a05e0 mov r12, r0
 *   @0x2a05e4 str r0, [r7, #0x8]
 *   @0x2a05e8 add r2, r1, r1, lsl #2
 *   @0x2a05ec add r3, r1, #1
 *   @0x2a05f0 str r3, [r7, #0x4]
 *   @0x2a05f4 ubfx r10, r5, #0x8, #0x8
 *   @0x2a05f8 lsl r2, r2, #3
 *   @0x2a05fc ubfx r7, r5, #0x10, #0x8
 *   @0x2a0600 add r3, r12, r2
 *   @0x2a0604 mov r0, #0
 *   @0x2a0608 strb r5, [r12, r2]
 *   @0x2a060c mvn r2, #0
 *   @0x2a0610 ldrb r12, [r3, #0x3]
 *   @0x2a0614 strb r10, [r3, #0x1]
 *   @0x2a0618 bic r12, r12, #15
 *   @0x2a061c strb r7, [r3, #0x2]
 *   @0x2a0620 orr r5, r12, r5, lsr #24
 *   @0x2a0624 strb r0, [r3, #0x8]
 *   @0x2a0628 strb r0, [r3, #0x9]
 *   @0x2a062c bfi r5, r9, #4, #4
 *   @0x2a0630 strb r0, [r3, #0xa]
 *   @0x2a0634 strb r5, [r3, #0x3]
 *   @0x2a0638 strb r0, [r3, #0xb]
 *   @0x2a063c strb r0, [r3, #0xc]
 *   @0x2a0640 strb r0, [r3, #0xd]
 *   @0x2a0644 strb r0, [r3, #0xe]
 *   @0x2a0648 strb r0, [r3, #0xf]
 *   @0x2a064c strb r0, [r3, #0x10]
 *   @0x2a0650 strb r0, [r3, #0x11]
 *   @0x2a0654 strb r0, [r3, #0x12]
 *   @0x2a0658 strb r0, [r3, #0x13]
 *   @0x2a065c strb r0, [r3, #0x14]
 *   @0x2a0660 strb r0, [r3, #0x15]
 *   @0x2a0664 strb r0, [r3, #0x16]
 *   @0x2a0668 strb r0, [r3, #0x17]
 *   @0x2a066c strb r0, [r3, #0x20]
 *   @0x2a0670 strb r0, [r3, #0x21]
 *   @0x2a0674 strb r0, [r3, #0x22]
 *   @0x2a0678 strb r2, [r3, #0x18]
 *   @0x2a067c strb r2, [r3, #0x19]
 *   @0x2a0680 strb r2, [r3, #0x1a]
 *   @0x2a0684 strb r2, [r3, #0x1b]
 *   @0x2a0688 strb r2, [r3, #0x1c]
 *   @0x2a068c strb r2, [r3, #0x1d]
 *   @0x2a0690 strb r2, [r3, #0x1e]
 *   @0x2a0694 strb r2, [r3, #0x1f]
 *   @0x2a0698 strb r0, [r3, #0x23]
 *   @0x2a069c ldr r3, [r6, #0x8]
 *   @0x2a06a0 add r8, r3, r8
 *   @0x2a06a4 ldr r2, [r8, #0x18]
 *   @0x2a06a8 cmp r2, r0
 *   @0x2a06ac strlt r1, [r8, #0x18]
 *   @0x2a06b0 addge r4, r4, r4, lsl #2
 *   @0x2a06b4 addge r3, r3, r4, lsl #3
 *   @0x2a06b8 mov r4, r1
 *   @0x2a06bc mov r0, r4
 *   @0x2a06c0 strge r1, [r3, #0x1c]
 *   @0x2a06c4 add sp, sp, #8
 *   @0x2a06c8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a06cc strheq r9, [r11], -r0
 *
 * ══ §14/69 anon_1cbc10  0x1cbc10  size 472  118 条（0x1cbc10..0x1cbde8）
 * @func 0x1cbc10 0x1cbde8  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_1cbc10+0xd8
 * 字段偏移 top8: 0x4×4 / 0xc×4 / 0x8×3 / 0x24×3 / 0x34×2 / 0x2c×2 / 0x38×2 / 0x30×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbc10 ldr r2, [r0]
 *   @0x1cbc14 ldr r3, [r1, #0x8]
 *   @0x1cbc18 cmp r2, r3
 *   @0x1cbc1c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec>
 *   @0x1cbc20 ldr r2, [r1]
 *   @0x1cbc24 ldr r3, [r0, #0x8]
 *   @0x1cbc28 cmp r2, r3
 *   @0x1cbc2c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec>
 *   @0x1cbc30 ldr r2, [r0, #0x4]
 *   @0x1cbc34 ldr r3, [r1, #0xc]
 *   @0x1cbc38 cmp r2, r3
 *   @0x1cbc3c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec>
 *   @0x1cbc40 ldr r3, [r0, #0xc]
 *   @0x1cbc44 ldr r2, [r1, #0x4]
 *   @0x1cbc48 cmp r2, r3
 *   @0x1cbc4c movgt r0, #0
 *   @0x1cbc50 movle r0, #1
 *   @0x1cbc54 bx lr
 *   @0x1cbc58 mov r0, #0
 *   @0x1cbc5c bx lr
 *   @0x1cbc60 add r3, r1, #8
 *   @0x1cbc64 mov r12, r1
 *   @0x1cbc68 push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x1cbc6c mov r9, r0
 *   @0x1cbc70 ldr r8, [r1]
 *   @0x1cbc74 ldm r3, {r0, r1, r2, r3}
 *   @0x1cbc78 cmp r8, #1
 *   @0x1cbc7c stm r9, {r0, r1, r2, r3}
 *   @0x1cbc80 ble 0x1cbce8 <_Z19FINALIZE_Run_Globalv+0x27c>
 *   @0x1cbc84 add r12, r12, #32
 *   @0x1cbc88 mov r5, r0
 *   @0x1cbc8c mov r4, #1
 *   @0x1cbc90 ldmib r12, {r0, r7}
 *   @0x1cbc94 add r4, r4, #1
 *   @0x1cbc98 ldr r10, [r12]
 *   @0x1cbc9c add r12, r12, #24
 *   @0x1cbca0 ldr r6, [r12, #-0xc]
 *   @0x1cbca4 cmp r7, r2
 *   @0x1cbca8 movlt r7, r2
 *   @0x1cbcac cmp r10, r5
 *   @0x1cbcb0 movge r10, r5
 *   @0x1cbcb4 cmp r0, r1
 *   @0x1cbcb8 movge r0, r1
 *   @0x1cbcbc cmp r6, r3
 *   @0x1cbcc0 movlt r6, r3
 *   @0x1cbcc4 cmp r4, r8
 *   @0x1cbcc8 mov r5, r10
 *   @0x1cbccc mov r1, r0
 *   @0x1cbcd0 mov r2, r7
 *   @0x1cbcd4 mov r3, r6
 *   @0x1cbcd8 bne 0x1cbc90 <_Z19FINALIZE_Run_Globalv+0x224>
 *   @0x1cbcdc str r10, [r9]
 *   @0x1cbce0 stmib r9, {r0, r7}
 *   @0x1cbce4 str r6, [r9, #0xc]
 *   @0x1cbce8 mov r0, r9
 *   @0x1cbcec pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x1cbcf0 bx lr
 *   @0x1cbcf4 add r12, r2, r1, lsl #2
 *   @0x1cbcf8 push {r4, r5, r6, r7}
 *   @0x1cbcfc str r1, [r2, r0, lsl #2]
 *   @0x1cbd00 add r0, r0, r0, lsl #1
 *   @0x1cbd04 ldr r3, [r12, #0x24]
 *   @0x1cbd08 cmp r3, #0
 *   @0x1cbd0c beq 0x1cbdb4 <_Z19FINALIZE_Run_Globalv+0x348>
 *   @0x1cbd10 add r1, r2, r1, lsl #4
 *   @0x1cbd14 add r2, r2, r0, lsl #3
 *   @0x1cbd18 add r4, r2, #84
 *   @0x1cbd1c add r2, r2, #80
 *   @0x1cbd20 ldr r0, [r4, #0x8]
 *   @0x1cbd24 ldr r2, [r2, #0x4]
 *   @0x1cbd28 ldr r6, [r1, #0x34]
 *   @0x1cbd2c ldr r5, [r1, #0x2c]
 *   @0x1cbd30 ldr r7, [r4, #0x4]
 *   @0x1cbd34 cmp r0, r6
 *   @0x1cbd38 movlt r0, r6
 *   @0x1cbd3c cmp r5, r2
 *   @0x1cbd40 movge r5, r2
 *   @0x1cbd44 ldr r6, [r1, #0x38]
 *   @0x1cbd48 ldr r2, [r4, #0xc]
 *   @0x1cbd4c vmov s11, r0
 *   @0x1cbd50 ldr r4, [r1, #0x30]
 *   @0x1cbd54 vmov s14, r5
 *   @0x1cbd58 cmp r2, r6
 *   @0x1cbd5c movlt r2, r6
 *   @0x1cbd60 str r5, [r1, #0x2c]
 *   @0x1cbd64 cmp r4, r7
 *   @0x1cbd68 movge r4, r7
 *   @0x1cbd6c str r0, [r1, #0x34]
 *   @0x1cbd70 vmov s12, r2
 *   @0x1cbd74 str r4, [r1, #0x30]
 *   @0x1cbd78 vmov s13, r4
 *   @0x1cbd7c str r2, [r1, #0x38]
 *   @0x1cbd80 vcvt.f32.s32 s11, s11
 *   @0x1cbd84 ldr r3, [r12, #0x24]
 *   @0x1cbd88 pop {r4, r5, r6, r7}
 *   @0x1cbd8c add r3, r3, #1
 *   @0x1cbd90 str r3, [r12, #0x24]
 *   @0x1cbd94 vcvt.f32.s32 s14, s14
 *   @0x1cbd98 vcvt.f32.s32 s12, s12
 *   @0x1cbd9c vcvt.f32.s32 s13, s13
 *   @0x1cbda0 vsub.f32 s14, s11, s14
 *   @0x1cbda4 vsub.f32 s15, s12, s13
 *   @0x1cbda8 vmul.f32 s15, s14, s15
 *   @0x1cbdac vstr s15, [r12, #76]
 *   @0x1cbdb0 bx lr
 *   @0x1cbdb4 add r0, r2, r0, lsl #3
 *   @0x1cbdb8 lsl r1, r1, #4
 *   @0x1cbdbc add r0, r0, #84
 *   @0x1cbdc0 add r6, r1, #40
 *   @0x1cbdc4 add r1, r2, r1
 *   @0x1cbdc8 add r6, r2, r6
 *   @0x1cbdcc add r4, r1, #44
 *   @0x1cbdd0 ldm r0, {r0, r1, r2, r3}
 *   @0x1cbdd4 stm r4, {r0, r1, r2, r3}
 *   @0x1cbdd8 vldr s14, [r6, #4]
 *   @0x1cbddc vldr s11, [r6, #12]
 *   @0x1cbde0 vldr s12, [r6, #16]
 *   @0x1cbde4 vldr s13, [r6, #8]
 *
 * ══ §15/69 _pcre_was_newline  0x25fbc0  size 472  118 条（0x25fbc0..0x25fd98）
 * @func 0x25fbc0 0x25fd98  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _pcre_was_newline+0x88 / _pcre_was_newline+0x7c / _pcre_was_newline+0xac
 * 字段偏移 top8: 0x1×5 / 0x2×4 / 0x-1×3 / 0x3×3 / 0x4×2 / 0x14×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25fbc0 push {r4, r5, r6, r7, r8}
 *   @0x25fbc4 sub r5, r0, #1
 *   @0x25fbc8 ldr r6, [sp, #0x14]
 *   @0x25fbcc ldrb r12, [r0, #-0x1]
 *   @0x25fbd0 cmp r6, #0
 *   @0x25fbd4 beq 0x25fc04 <_pcre_was_newline+0x44>
 *   @0x25fbd8 and r4, r12, #192
 *   @0x25fbdc cmp r4, #128
 *   @0x25fbe0 bne 0x25fbfc <_pcre_was_newline+0x3c>
 *   @0x25fbe4 sub r0, r0, #2
 *   @0x25fbe8 mov r5, r0
 *   @0x25fbec ldrb r12, [r0], #-1
 *   @0x25fbf0 and r4, r12, #192
 *   @0x25fbf4 cmp r4, #128
 *   @0x25fbf8 beq 0x25fbe8 <_pcre_was_newline+0x28>
 *   @0x25fbfc cmp r12, #191
 *   @0x25fc00 bhi 0x25fc74 <_pcre_was_newline+0xb4>
 *   @0x25fc04 cmp r1, #2
 *   @0x25fc08 beq 0x25fca8 <_pcre_was_newline+0xe8>
 *   @0x25fc0c cmp r12, #13
 *   @0x25fc10 bls 0x25fc48 <_pcre_was_newline+0x88>
 *   @0x25fc14 cmp r12, #133
 *   @0x25fc18 beq 0x25fcf0 <_pcre_was_newline+0x130>
 *   @0x25fc1c blo 0x25fc3c <_pcre_was_newline+0x7c>
 *   @0x25fc20 sub r12, r12, #8192
 *   @0x25fc24 sub r12, r12, #40
 *   @0x25fc28 cmp r12, #1
 *   @0x25fc2c movls r2, #3
 *   @0x25fc30 movls r0, #1
 *   @0x25fc34 strls r2, [r3]
 *   @0x25fc38 bls 0x25fc6c <_pcre_was_newline+0xac>
 *   @0x25fc3c mov r0, #0
 *   @0x25fc40 pop {r4, r5, r6, r7, r8}
 *   @0x25fc44 bx lr
 *   @0x25fc48 cmp r12, #11
 *   @0x25fc4c bhs 0x25fcb8 <_pcre_was_newline+0xf8>
 *   @0x25fc50 cmp r12, #10
 *   @0x25fc54 bne 0x25fc3c <_pcre_was_newline+0x7c>
 *   @0x25fc58 cmp r5, r2
 *   @0x25fc5c movls r2, #1
 *   @0x25fc60 bhi 0x25fcdc <_pcre_was_newline+0x11c>
 *   @0x25fc64 mov r0, #1
 *   @0x25fc68 str r2, [r3]
 *   @0x25fc6c pop {r4, r5, r6, r7, r8}
 *   @0x25fc70 bx lr
 *   @0x25fc74 tst r12, #32
 *   @0x25fc78 beq 0x25fcc8 <_pcre_was_newline+0x108>
 *   @0x25fc7c tst r12, #16
 *   @0x25fc80 bne 0x25fd0c <_pcre_was_newline+0x14c>
 *   @0x25fc84 lsl r0, r12, #12
 *   @0x25fc88 ldrb r4, [r5, #0x2]
 *   @0x25fc8c ldrb r12, [r5, #0x1]
 *   @0x25fc90 uxth r0, r0
 *   @0x25fc94 and r4, r4, #63
 *   @0x25fc98 and r12, r12, #63
 *   @0x25fc9c orr r0, r4, r0
 *   @0x25fca0 orr r12, r0, r12, lsl #6
 *   @0x25fca4 b 0x25fc04 <_pcre_was_newline+0x44>
 *   @0x25fca8 cmp r12, #10
 *   @0x25fcac beq 0x25fc58 <_pcre_was_newline+0x98>
 *   @0x25fcb0 cmp r12, #13
 *   @0x25fcb4 bne 0x25fc3c <_pcre_was_newline+0x7c>
 *   @0x25fcb8 mov r0, #1
 *   @0x25fcbc str r0, [r3]
 *   @0x25fcc0 pop {r4, r5, r6, r7, r8}
 *   @0x25fcc4 bx lr
 *   @0x25fcc8 ldrb r0, [r5, #0x1]
 *   @0x25fccc and r12, r12, #31
 *   @0x25fcd0 and r0, r0, #63
 *   @0x25fcd4 orr r12, r0, r12, lsl #6
 *   @0x25fcd8 b 0x25fc04 <_pcre_was_newline+0x44>
 *   @0x25fcdc ldrb r2, [r5, #-0x1]
 *   @0x25fce0 cmp r2, #13
 *   @0x25fce4 moveq r2, #2
 *   @0x25fce8 movne r2, #1
 *   @0x25fcec b 0x25fc64 <_pcre_was_newline+0xa4>
 *   @0x25fcf0 cmp r6, #0
 *   @0x25fcf4 mov r0, #1
 *   @0x25fcf8 moveq r6, #1
 *   @0x25fcfc movne r6, #2
 *   @0x25fd00 str r6, [r3]
 *   @0x25fd04 pop {r4, r5, r6, r7, r8}
 *   @0x25fd08 bx lr
 *   @0x25fd0c tst r12, #8
 *   @0x25fd10 beq 0x25fd54 <_pcre_was_newline+0x194>
 *   @0x25fd14 tst r12, #4
 *   @0x25fd18 bne 0x25fd6c <_pcre_was_newline+0x1ac>
 *   @0x25fd1c ldrb r0, [r5, #0x4]
 *   @0x25fd20 and r8, r12, #3
 *   @0x25fd24 ldrb r7, [r5, #0x1]
 *   @0x25fd28 ldrb r4, [r5, #0x2]
 *   @0x25fd2c and r0, r0, #63
 *   @0x25fd30 ldrb r12, [r5, #0x3]
 *   @0x25fd34 and r7, r7, #63
 *   @0x25fd38 orr r0, r0, r8, lsl #24
 *   @0x25fd3c and r4, r4, #63
 *   @0x25fd40 orr r0, r0, r7, lsl #18
 *   @0x25fd44 and r12, r12, #63
 *   @0x25fd48 orr r0, r0, r4, lsl #12
 *   @0x25fd4c orr r12, r0, r12, lsl #6
 *   @0x25fd50 b 0x25fc04 <_pcre_was_newline+0x44>
 *   @0x25fd54 ldrb r0, [r5, #0x3]
 *   @0x25fd58 and r7, r12, #7
 *   @0x25fd5c ldrb r4, [r5, #0x1]
 *   @0x25fd60 ldrb r12, [r5, #0x2]
 *   @0x25fd64 and r0, r0, #63
 *   @0x25fd68 b 0x25fd3c <_pcre_was_newline+0x17c>
 *   @0x25fd6c ldrb r0, [r5, #0x5]
 *   @0x25fd70 and r12, r12, #1
 *   @0x25fd74 ldrb r8, [r5, #0x1]
 *   @0x25fd78 ldrb r7, [r5, #0x2]
 *   @0x25fd7c and r0, r0, #63
 *   @0x25fd80 orr r0, r0, r12, lsl #30
 *   @0x25fd84 and r8, r8, #63
 *   @0x25fd88 ldrb r4, [r5, #0x3]
 *   @0x25fd8c and r7, r7, #63
 *   @0x25fd90 ldrb r12, [r5, #0x4]
 *   @0x25fd94 b 0x25fd38 <_pcre_was_newline+0x178>
 *
 * ══ §16/69 b2World::Step  0x2ca68c  size 472  118 条（0x2ca68c..0x2ca864）
 * @func 0x2ca68c 0x2ca864  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Timer::b2Timer()×4 / b2Timer::GetMilliseconds() const×4 / b2ContactManager::Collide() / b2World::Step(float, int, int)+0x11c / b2ParticleSystem::Solve(b2TimeStep const&) / b2World::Solve(b2TimeStep const&) / b2World::Step(float, int, int)+0x164 / b2World::SolveTOI(b2TimeStep const&)
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0x24×1 / 0x258×1 / 0x25c×1 / 0x270×1 / 0x254×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ca68c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2ca690 vpush {d8}
 *   @0x2ca694 sub sp, sp, #40
 *   @0x2ca698 movw r5, #0x91d4
 *   @0x2ca69c movt r5, #0x1
 *   @0x2ca6a0 mov r4, r0
 *   @0x2ca6a4 mov r0, sp
 *   @0x2ca6a8 mov r6, r3
 *   @0x2ca6ac mov r10, r2
 *   @0x2ca6b0 vmov s16, r1
 *   @0x2ca6b4 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2ca6b8 ldr r3, [r4, r5]
 *   @0x2ca6bc add r8, r4, #102400
 *   @0x2ca6c0 add r9, r8, #472
 *   @0x2ca6c4 tst r3, #1
 *   @0x2ca6c8 bne 0x2ca850 <_ZN7b2World4StepEfii+0x1c4>
 *   @0x2ca6cc vcmpe.f32 s16, #0
 *   @0x2ca6d0 add r5, r4, #102400
 *   @0x2ca6d4 vstr s16, [sp, #16]
 *   @0x2ca6d8 add r5, r5, #588
 *   @0x2ca6dc movw r1, #0x91d4
 *   @0x2ca6e0 movt r1, #0x1
 *   @0x2ca6e4 orr r3, r3, #2
 *   @0x2ca6e8 str r6, [sp, #0x20]
 *   @0x2ca6ec vmrs APSR_nzcv, fpscr
 *   @0x2ca6f0 vmovgt.f32 s15, #1.000000e+00
 *   @0x2ca6f4 str r3, [r4, r1]
 *   @0x2ca6f8 movw r3, #0x9250
 *   @0x2ca6fc movt r3, #0x1
 *   @0x2ca700 add r6, sp, #8
 *   @0x2ca704 mov r2, #0
 *   @0x2ca708 str r10, [sp, #0x1c]
 *   @0x2ca70c ldrb r3, [r4, r3]
 *   @0x2ca710 mov r0, r6
 *   @0x2ca714 strle r2, [sp, #0x14]
 *   @0x2ca718 strb r3, [sp, #0x24]
 *   @0x2ca71c vdivgt.f32 s15, s15, s16
 *   @0x2ca720 vstrgt s15, [sp, #20]
 *   @0x2ca724 vldr s15, [r5]
 *   @0x2ca728 vmul.f32 s16, s15, s16
 *   @0x2ca72c vstr s16, [sp, #24]
 *   @0x2ca730 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2ca734 mov r0, r9
 *   @0x2ca738 bl 0x2c7970 <_ZN16b2ContactManager7CollideEv>
 *   @0x2ca73c mov r0, r6
 *   @0x2ca740 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2ca744 movw r2, #0x9253
 *   @0x2ca748 movt r2, #0x1
 *   @0x2ca74c add r3, r4, #102400
 *   @0x2ca750 vldr s15, [sp, #16]
 *   @0x2ca754 ldrb r2, [r4, r2]
 *   @0x2ca758 cmp r2, #0
 *   @0x2ca75c str r0, [r3, #0x258]
 *   @0x2ca760 beq 0x2ca7a8 <_ZN7b2World4StepEfii+0x11c>
 *   @0x2ca764 vcmpe.f32 s15, #0
 *   @0x2ca768 vmrs APSR_nzcv, fpscr
 *   @0x2ca76c ble 0x2ca7a8 <_ZN7b2World4StepEfii+0x11c>
 *   @0x2ca770 mov r0, r6
 *   @0x2ca774 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2ca778 add r0, r8, #628
 *   @0x2ca77c add r8, sp, #16
 *   @0x2ca780 mov r1, r8
 *   @0x2ca784 bl 0x2db370 <_ZN16b2ParticleSystem5SolveERK10b2TimeStep>
 *   @0x2ca788 mov r0, r4
 *   @0x2ca78c mov r1, r8
 *   @0x2ca790 bl 0x2c963c <_ZN7b2World5SolveERK10b2TimeStep>
 *   @0x2ca794 mov r0, r6
 *   @0x2ca798 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2ca79c add r3, r4, #102400
 *   @0x2ca7a0 vldr s15, [sp, #16]
 *   @0x2ca7a4 str r0, [r3, #0x25c]
 *   @0x2ca7a8 movw r3, #0x9251
 *   @0x2ca7ac movt r3, #0x1
 *   @0x2ca7b0 ldrb r3, [r4, r3]
 *   @0x2ca7b4 cmp r3, #0
 *   @0x2ca7b8 beq 0x2ca7f0 <_ZN7b2World4StepEfii+0x164>
 *   @0x2ca7bc vcmpe.f32 s15, #0
 *   @0x2ca7c0 vmrs APSR_nzcv, fpscr
 *   @0x2ca7c4 ble 0x2ca7f0 <_ZN7b2World4StepEfii+0x164>
 *   @0x2ca7c8 mov r0, r6
 *   @0x2ca7cc bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2ca7d0 mov r0, r4
 *   @0x2ca7d4 add r1, sp, #16
 *   @0x2ca7d8 bl 0x2c9ab4 <_ZN7b2World8SolveTOIERK10b2TimeStep>
 *   @0x2ca7dc mov r0, r6
 *   @0x2ca7e0 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2ca7e4 add r3, r4, #102400
 *   @0x2ca7e8 vldr s15, [sp, #16]
 *   @0x2ca7ec str r0, [r3, #0x270]
 *   @0x2ca7f0 vcmpe.f32 s15, #0
 *   @0x2ca7f4 vmrs APSR_nzcv, fpscr
 *   @0x2ca7f8 ldrgt r3, [sp, #0x14]
 *   @0x2ca7fc strgt r3, [r5]
 *   @0x2ca800 movw r5, #0x91d4
 *   @0x2ca804 movt r5, #0x1
 *   @0x2ca808 ldr r3, [r4, r5]
 *   @0x2ca80c tst r3, #4
 *   @0x2ca810 moveq r2, r3
 *   @0x2ca814 beq 0x2ca824 <_ZN7b2World4StepEfii+0x198>
 *   @0x2ca818 mov r0, r4
 *   @0x2ca81c bl 0x2ca658 <_ZN7b2World11ClearForcesEv>
 *   @0x2ca820 ldr r2, [r4, r5]
 *   @0x2ca824 movw r3, #0x91d4
 *   @0x2ca828 movt r3, #0x1
 *   @0x2ca82c bic r2, r2, #2
 *   @0x2ca830 mov r0, sp
 *   @0x2ca834 str r2, [r4, r3]
 *   @0x2ca838 add r4, r4, #102400
 *   @0x2ca83c bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2ca840 str r0, [r4, #0x254]
 *   @0x2ca844 add sp, sp, #40
 *   @0x2ca848 vpop {d8}
 *   @0x2ca84c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2ca850 mov r0, r9
 *   @0x2ca854 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv>
 *   @0x2ca858 ldr r3, [r4, r5]
 *   @0x2ca85c bic r3, r3, #1
 *   @0x2ca860 b 0x2ca6cc <_ZN7b2World4StepEfii+0x40>
 *
 * ══ §17/69 ExecuteDrawEvent  0x1b3544  size 468  117 条（0x1b3544..0x1b3718）
 * @func 0x1b3544 0x1b3718  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExecuteLayerScript(int, int, int, int)×2 / CObjectGM::HasEventRecursive(int, int)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / DirtyRoomExtents() / ExecuteDrawEvent(tagYYRECT*, int, int)+0x148 / SetLayerShader(int) / ResetLayerShader(int)
 * 字段偏移 top8: 0x6c×2 / 0x28×2 / 0x20×2 / 0x14×2 / 0x69×2 / 0x68×2 / 0x65×2 / 0x80×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b3544 push {r4, r5, r6, r7, r8, lr}
 *   @0x1b3548 mov r7, r1
 *   @0x1b354c mov r8, r2
 *   @0x1b3550 ldr r12, [pc, #0x1b8]
 *   @0x1b3554 ldm r0, {r0, r1, r2, r3}
 *   @0x1b3558 ldr r12, [pc, r12]
 *   @0x1b355c stm r12, {r0, r1, r2, r3}
 *   @0x1b3560 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b3564 ldr r3, [pc, #0x1a8]
 *   @0x1b3568 ldr r3, [pc, r3]
 *   @0x1b356c ldr r3, [r3]
 *   @0x1b3570 cmp r3, #0
 *   @0x1b3574 beq 0x1b368c <_Z16ExecuteDrawEventP9tagYYRECTii+0x148>
 *   @0x1b3578 ldr r2, [r3, #0xdc]
 *   @0x1b357c cmp r2, #0
 *   @0x1b3580 ble 0x1b368c <_Z16ExecuteDrawEventP9tagYYRECTii+0x148>
 *   @0x1b3584 ldr r5, [r3, #0xd8]
 *   @0x1b3588 cmp r5, #0
 *   @0x1b358c bne 0x1b35a0 <_Z16ExecuteDrawEventP9tagYYRECTii+0x5c>
 *   @0x1b3590 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1b3594 ldr r5, [r5, #0x6c]
 *   @0x1b3598 cmp r5, #0
 *   @0x1b359c beq 0x1b3688 <_Z16ExecuteDrawEventP9tagYYRECTii+0x144>
 *   @0x1b35a0 ldrb r3, [r5, #0x18]
 *   @0x1b35a4 cmp r3, #0
 *   @0x1b35a8 beq 0x1b3594 <_Z16ExecuteDrawEventP9tagYYRECTii+0x50>
 *   @0x1b35ac ldr r0, [r5, #0x28]
 *   @0x1b35b0 bl 0x1b1128 <_Z14SetLayerShaderi>
 *   @0x1b35b4 ldr r0, [r5]
 *   @0x1b35b8 ldr r1, [r5, #0x20]
 *   @0x1b35bc mov r2, r7
 *   @0x1b35c0 mov r3, r8
 *   @0x1b35c4 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii>
 *   @0x1b35c8 ldr r4, [r5, #0x58]
 *   @0x1b35cc cmp r4, #0
 *   @0x1b35d0 bne 0x1b35e4 <_Z16ExecuteDrawEventP9tagYYRECTii+0xa0>
 *   @0x1b35d4 b 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c>
 *   @0x1b35d8 ldr r4, [r4, #0x14]
 *   @0x1b35dc cmp r4, #0
 *   @0x1b35e0 beq 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c>
 *   @0x1b35e4 ldr r0, [r4]
 *   @0x1b35e8 cmp r0, #2
 *   @0x1b35ec bne 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b35f0 ldr r6, [r4, #0x20]
 *   @0x1b35f4 cmp r6, #0
 *   @0x1b35f8 beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b35fc ldrb r0, [r6, #0x69]
 *   @0x1b3600 cmp r0, #0
 *   @0x1b3604 bne 0x1b3660 <_Z16ExecuteDrawEventP9tagYYRECTii+0x11c>
 *   @0x1b3608 ldrb r3, [r6, #0x68]
 *   @0x1b360c cmp r3, #0
 *   @0x1b3610 bne 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b3614 ldrb r3, [r6, #0x65]
 *   @0x1b3618 cmp r3, #0
 *   @0x1b361c beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b3620 ldr r0, [r6, #0x80]
 *   @0x1b3624 cmp r0, #0
 *   @0x1b3628 beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b362c mov r1, r7
 *   @0x1b3630 mov r2, r8
 *   @0x1b3634 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1b3638 cmp r0, #0
 *   @0x1b363c beq 0x1b35d8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x94>
 *   @0x1b3640 mov r0, r6
 *   @0x1b3644 mov r2, r7
 *   @0x1b3648 mov r1, r6
 *   @0x1b364c mov r3, r8
 *   @0x1b3650 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1b3654 ldr r4, [r4, #0x14]
 *   @0x1b3658 cmp r4, #0
 *   @0x1b365c bne 0x1b35e4 <_Z16ExecuteDrawEventP9tagYYRECTii+0xa0>
 *   @0x1b3660 ldr r0, [r5]
 *   @0x1b3664 mov r2, r7
 *   @0x1b3668 ldr r1, [r5, #0x24]
 *   @0x1b366c mov r3, r8
 *   @0x1b3670 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii>
 *   @0x1b3674 ldr r0, [r5, #0x28]
 *   @0x1b3678 bl 0x1b1170 <_Z16ResetLayerShaderi>
 *   @0x1b367c ldr r5, [r5, #0x6c]
 *   @0x1b3680 cmp r5, #0
 *   @0x1b3684 bne 0x1b35a0 <_Z16ExecuteDrawEventP9tagYYRECTii+0x5c>
 *   @0x1b3688 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1b368c ldr r4, [r3, #0x84]
 *   @0x1b3690 cmp r4, #0
 *   @0x1b3694 bne 0x1b36a8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x164>
 *   @0x1b3698 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1b369c ldr r4, [r4, #0x17c]
 *   @0x1b36a0 cmp r4, #0
 *   @0x1b36a4 beq 0x1b370c <_Z16ExecuteDrawEventP9tagYYRECTii+0x1c8>
 *   @0x1b36a8 ldrb r3, [r4, #0x68]
 *   @0x1b36ac cmp r3, #0
 *   @0x1b36b0 bne 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158>
 *   @0x1b36b4 ldrb r3, [r4, #0x69]
 *   @0x1b36b8 cmp r3, #0
 *   @0x1b36bc bne 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158>
 *   @0x1b36c0 ldrb r3, [r4, #0x65]
 *   @0x1b36c4 cmp r3, #0
 *   @0x1b36c8 beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158>
 *   @0x1b36cc ldr r0, [r4, #0x80]
 *   @0x1b36d0 mov r1, r7
 *   @0x1b36d4 mov r2, r8
 *   @0x1b36d8 cmp r0, #0
 *   @0x1b36dc beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158>
 *   @0x1b36e0 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1b36e4 cmp r0, #0
 *   @0x1b36e8 beq 0x1b369c <_Z16ExecuteDrawEventP9tagYYRECTii+0x158>
 *   @0x1b36ec mov r0, r4
 *   @0x1b36f0 mov r1, r4
 *   @0x1b36f4 mov r2, r7
 *   @0x1b36f8 mov r3, r8
 *   @0x1b36fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1b3700 ldr r4, [r4, #0x17c]
 *   @0x1b3704 cmp r4, #0
 *   @0x1b3708 bne 0x1b36a8 <_Z16ExecuteDrawEventP9tagYYRECTii+0x164>
 *   @0x1b370c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1b3710 .word 0x0023cbf4
 *   @0x1b3714 eoreq r10, r3, r0, asr #7
 *
 * ══ §18/69 anon_15327c  0x15327c  size 464  116 条（0x15327c..0x15344c）
 * @func 0x15327c 0x15344c  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x153294→0x484a58, 0x1532a8→0x484a5c, 0x153310→0x484a58
 * 调用序列: 0xb6574×4 / anon_15327c+0x7c×2 / YYGetInt32(RValue const*, int) / anon_15327c+0x140
 * 字段偏移 top8: 0x4×6 / 0xc×2 / 0x104×1 / 0xfc×1 / 0xec×1 / 0x80×1 / 0x60×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15327c ldr r1, [r0, #0xc]
 *   @0x153280 push {r3, r4, r5, r6, r7, lr}
 *   @0x153284 cmp r1, #0
 *   @0x153288 ldr r5, [pc, #0x104]
 *   @0x15328c add r5, pc, r5
 *   @0x153290 beq 0x153304 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x153294 ldr r2, [pc, #0xfc]
 *   @0x153298 ldr r2, [r5, r2]
 *   @0x15329c ldr r6, [r2]
 *   @0x1532a0 cmp r6, #0
 *   @0x1532a4 ble 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1532a8 ldr r2, [pc, #0xec]
 *   @0x1532ac bic r1, r1, #-16777216
 *   @0x1532b0 cmp r1, #1
 *   @0x1532b4 ldr r2, [r5, r2]
 *   @0x1532b8 ldr r5, [r2, #0x4]
 *   @0x1532bc beq 0x15332c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1532c0 sub r5, r5, #4
 *   @0x1532c4 mov r4, #0
 *   @0x1532c8 b 0x1532d8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1532cc add r4, r4, #1
 *   @0x1532d0 cmp r4, r6
 *   @0x1532d4 beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1532d8 ldr r3, [r5, #0x4]!
 *   @0x1532dc mov r1, #0
 *   @0x1532e0 ldr r0, [r3]
 *   @0x1532e4 bl 0xb6574 <strcmp@plt>
 *   @0x1532e8 cmp r0, #0
 *   @0x1532ec bne 0x1532cc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1532f0 mov r0, r4
 *   @0x1532f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1532f8 mvn r4, #0
 *   @0x1532fc mov r0, r4
 *   @0x153300 pop {r3, r4, r5, r6, r7, pc}
 *   @0x153304 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x153308 subs r4, r0, #0
 *   @0x15330c blt 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x153310 ldr r3, [pc, #0x80]
 *   @0x153314 ldr r3, [r5, r3]
 *   @0x153318 ldr r3, [r3]
 *   @0x15331c cmp r4, r3
 *   @0x153320 mvnge r4, #0
 *   @0x153324 mov r0, r4
 *   @0x153328 pop {r3, r4, r5, r6, r7, pc}
 *   @0x15332c ldr r7, [r0]
 *   @0x153330 mov r4, #0
 *   @0x153334 sub r5, r5, #4
 *   @0x153338 cmp r7, r4
 *   @0x15333c bne 0x153350 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x153340 b 0x153378 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x153344 add r4, r4, #1
 *   @0x153348 cmp r4, r6
 *   @0x15334c beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x153350 ldr r3, [r5, #0x4]!
 *   @0x153354 ldr r1, [r7]
 *   @0x153358 ldr r0, [r3]
 *   @0x15335c bl 0xb6574 <strcmp@plt>
 *   @0x153360 cmp r0, #0
 *   @0x153364 bne 0x153344 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x153368 b 0x1532f0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x15336c add r4, r4, #1
 *   @0x153370 cmp r4, r6
 *   @0x153374 beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x153378 ldr r3, [r5, #0x4]!
 *   @0x15337c mov r1, #0
 *   @0x153380 ldr r0, [r3]
 *   @0x153384 bl 0xb6574 <strcmp@plt>
 *   @0x153388 cmp r0, #0
 *   @0x15338c bne 0x15336c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x153390 b 0x1532f0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x153394 eoreq lr, r9, r4, asr #19
 *   @0x153398 .word 0xffffde80
 *   @0x15339c .word 0xffffde84
 *   @0x1533a0 ldr r1, [r0, #0xc]
 *   @0x1533a4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1533a8 cmp r1, #0
 *   @0x1533ac beq 0x153440 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x1533b0 bic r1, r1, #-16777216
 *   @0x1533b4 cmp r1, #1
 *   @0x1533b8 beq 0x1533c8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x1533bc mvn r4, #0
 *   @0x1533c0 mov r0, r4
 *   @0x1533c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1533c8 ldr r3, [r0]
 *   @0x1533cc cmp r3, #0
 *   @0x1533d0 beq 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x1533d4 ldr r7, [r3]
 *   @0x1533d8 cmp r7, #0
 *   @0x1533dc beq 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x1533e0 ldr r3, [pc, #0x60]
 *   @0x1533e4 ldr r3, [pc, r3]
 *   @0x1533e8 ldr r6, [r3]
 *   @0x1533ec cmp r6, #0
 *   @0x1533f0 ble 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x1533f4 ldr r3, [pc, #0x50]
 *   @0x1533f8 mov r4, #0
 *   @0x1533fc ldr r3, [pc, r3]
 *   @0x153400 ldr r5, [r3, #0x4]
 *   @0x153404 sub r5, r5, #4
 *   @0x153408 ldr r3, [r5, #0x4]!
 *   @0x15340c mov r1, r7
 *   @0x153410 cmp r3, #0
 *   @0x153414 beq 0x153430 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x153418 ldr r0, [r3]
 *   @0x15341c cmp r0, #0
 *   @0x153420 beq 0x153430 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x153424 bl 0xb6574 <strcmp@plt>
 *   @0x153428 cmp r0, #0
 *   @0x15342c beq 0x1533c0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x153430 add r4, r4, #1
 *   @0x153434 cmp r4, r6
 *   @0x153438 bne 0x153408 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x15343c b 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x153440 pop {r3, r4, r5, r6, r7, lr}
 *   @0x153444 b 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x153448 eoreq r12, r9, r4, ror #13
 *
 * ══ §19/69 b2ParticleGroup::UpdateStatistics  0x2d4644  size 464  116 条（0x2d4644..0x2d4814）
 * @func 0x2d4644 0x2d4814  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetParticleMass() const / b2ParticleGroup::UpdateStatistics() const+0x10c
 * 字段偏移 top8: 0x1c×2 / 0x38×2 / 0x40×2 / 0x4×1 / 0x8×1
 * VFP 指令 73 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4644 push {r4, r5, r6, lr}
 *   @0x2d4648 mov r4, r0
 *   @0x2d464c ldr r0, [r0]
 *   @0x2d4650 ldr r2, [r4, #0x1c]
 *   @0x2d4654 ldr r3, [r0]
 *   @0x2d4658 cmp r2, r3
 *   @0x2d465c popeq {r4, r5, r6, pc}
 *   @0x2d4660 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv>
 *   @0x2d4664 ldr r6, [r4, #0x4]
 *   @0x2d4668 ldr r5, [r4, #0x8]
 *   @0x2d466c vldr s10, [pc, #412]
 *   @0x2d4670 ldr r12, [r4]
 *   @0x2d4674 vstr s10, [r4, #32]
 *   @0x2d4678 cmp r6, r5
 *   @0x2d467c vstr s10, [r4, #40]
 *   @0x2d4680 vstr s10, [r4, #44]
 *   @0x2d4684 vstr s10, [r4, #48]
 *   @0x2d4688 vstr s10, [r4, #52]
 *   @0x2d468c vmov s15, r0
 *   @0x2d4690 bge 0x2d4750 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x10c>
 *   @0x2d4694 ldr r0, [r12, #0x38]
 *   @0x2d4698 vmov.f32 s6, s10
 *   @0x2d469c ldr r2, [r12, #0x40]
 *   @0x2d46a0 lsl r1, r6, #3
 *   @0x2d46a4 add r3, r0, r1
 *   @0x2d46a8 add r0, r0, r5, lsl #3
 *   @0x2d46ac add r1, r2, r1
 *   @0x2d46b0 vmov.f32 s7, s10
 *   @0x2d46b4 vmov.f32 s8, s10
 *   @0x2d46b8 vmov.f32 s9, s10
 *   @0x2d46bc vldr s12, [r3, #4]
 *   @0x2d46c0 mov r2, r3
 *   @0x2d46c4 vldr s13, [r2]
 *   @0x2d46c8 mov r2, r1
 *   @0x2d46cc vmov.f32 s11, s8
 *   @0x2d46d0 add r3, r3, #8
 *   @0x2d46d4 cmp r3, r0
 *   @0x2d46d8 add r1, r1, #8
 *   @0x2d46dc vmla.f32 s11, s15, s13
 *   @0x2d46e0 vmla.f32 s7, s15, s12
 *   @0x2d46e4 vstr s11, [r4, #40]
 *   @0x2d46e8 vmov.f32 s14, s10
 *   @0x2d46ec vstr s7, [r4, #44]
 *   @0x2d46f0 vldr s8, [r1, #-4]
 *   @0x2d46f4 vldr s13, [r2]
 *   @0x2d46f8 vmla.f32 s14, s15, s8
 *   @0x2d46fc vmla.f32 s6, s15, s13
 *   @0x2d4700 vstr s14, [r4, #52]
 *   @0x2d4704 vmov.f32 s8, s11
 *   @0x2d4708 vstr s6, [r4, #48]
 *   @0x2d470c vmov.f32 s10, s14
 *   @0x2d4710 vadd.f32 s9, s15, s9
 *   @0x2d4714 bne 0x2d46bc <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x78>
 *   @0x2d4718 vcmpe.f32 s9, #0
 *   @0x2d471c vstr s9, [r4, #32]
 *   @0x2d4720 vmrs APSR_nzcv, fpscr
 *   @0x2d4724 ble 0x2d4750 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x10c>
 *   @0x2d4728 vmov.f32 s10, #1.000000e+00
 *   @0x2d472c vdiv.f32 s9, s10, s9
 *   @0x2d4730 vmul.f32 s11, s11, s9
 *   @0x2d4734 vmul.f32 s12, s7, s9
 *   @0x2d4738 vstr s11, [r4, #40]
 *   @0x2d473c vmul.f32 s13, s6, s9
 *   @0x2d4740 vstr s12, [r4, #44]
 *   @0x2d4744 vmul.f32 s9, s14, s9
 *   @0x2d4748 vstr s13, [r4, #48]
 *   @0x2d474c vstr s9, [r4, #52]
 *   @0x2d4750 cmp r6, r5
 *   @0x2d4754 vldr s10, [pc, #180]
 *   @0x2d4758 vstr s10, [r4, #36]
 *   @0x2d475c vstr s10, [r4, #56]
 *   @0x2d4760 bge 0x2d4804 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x1c0>
 *   @0x2d4764 ldr r3, [r12, #0x38]
 *   @0x2d4768 vmov.f32 s8, s10
 *   @0x2d476c ldr r2, [r12, #0x40]
 *   @0x2d4770 lsl r6, r6, #3
 *   @0x2d4774 add r1, r3, r5, lsl #3
 *   @0x2d4778 add r3, r3, r6
 *   @0x2d477c add r2, r2, r6
 *   @0x2d4780 vldr s4, [r4, #40]
 *   @0x2d4784 vldr s5, [r4, #44]
 *   @0x2d4788 vldr s6, [r4, #48]
 *   @0x2d478c vldr s7, [r4, #52]
 *   @0x2d4790 vldr s11, [r3, #4]
 *   @0x2d4794 mov r0, r2
 *   @0x2d4798 vsub.f32 s11, s11, s5
 *   @0x2d479c vldr s13, [r0]
 *   @0x2d47a0 vldr s12, [r3]
 *   @0x2d47a4 vldr s9, [r2, #4]
 *   @0x2d47a8 add r3, r3, #8
 *   @0x2d47ac add r2, r2, #8
 *   @0x2d47b0 cmp r3, r1
 *   @0x2d47b4 vsub.f32 s13, s13, s6
 *   @0x2d47b8 vmul.f32 s14, s11, s11
 *   @0x2d47bc vmul.f32 s13, s11, s13
 *   @0x2d47c0 vsub.f32 s12, s12, s4
 *   @0x2d47c4 vsub.f32 s11, s9, s7
 *   @0x2d47c8 vmla.f32 s14, s12, s12
 *   @0x2d47cc vnmls.f32 s13, s12, s11
 *   @0x2d47d0 vmla.f32 s8, s15, s14
 *   @0x2d47d4 vmla.f32 s10, s15, s13
 *   @0x2d47d8 vmov.f32 s14, s8
 *   @0x2d47dc vmov.f32 s13, s10
 *   @0x2d47e0 bne 0x2d4790 <_ZNK15b2ParticleGroup16UpdateStatisticsEv+0x14c>
 *   @0x2d47e4 vcmpe.f32 s8, #0
 *   @0x2d47e8 vstr s10, [r4, #56]
 *   @0x2d47ec vstr s8, [r4, #36]
 *   @0x2d47f0 vmrs APSR_nzcv, fpscr
 *   @0x2d47f4 vmovgt.f32 s15, #1.000000e+00
 *   @0x2d47f8 vdivgt.f32 s14, s15, s8
 *   @0x2d47fc vmulgt.f32 s13, s10, s14
 *   @0x2d4800 vstrgt s13, [r4, #56]
 *   @0x2d4804 ldr r3, [r12]
 *   @0x2d4808 str r3, [r4, #0x1c]
 *   @0x2d480c pop {r4, r5, r6, pc}
 *   @0x2d4810 andeq r0, r0, r0
 *
 * ══ §20/69 RTree<CInstance*, int, float, 6, 2>::RemoveRectRec  0x1ccb94  size 460  115 条（0x1ccb94..0x1ccd60）
 * @func 0x1ccb94 0x1ccd60  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**)+0x98×3 / RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**)+0xa8 / anon_1cbc10 / RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**) / RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**)+0x17c / anon_1cbc10+0x50 / operator new(unsigned int)
 * 字段偏移 top8: 0x4×2 / 0x1c×2 / 0x40×1 / 0x10×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ccb94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ccb98 mov r8, r3
 *   @0x1ccb9c ldr r3, [r3, #0x4]
 *   @0x1ccba0 sub sp, sp, #28
 *   @0x1ccba4 mov r11, r0
 *   @0x1ccba8 mov r7, r1
 *   @0x1ccbac cmp r3, #0
 *   @0x1ccbb0 mov r9, r2
 *   @0x1ccbb4 ldr r10, [sp, #0x40]
 *   @0x1ccbb8 ble 0x1ccc3c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xa8>
 *   @0x1ccbbc ldr r6, [r8]
 *   @0x1ccbc0 cmp r6, #0
 *   @0x1ccbc4 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98>
 *   @0x1ccbc8 add r4, r8, #8
 *   @0x1ccbcc mov r5, #0
 *   @0x1ccbd0 b 0x1ccbe4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x50>
 *   @0x1ccbd4 add r5, r5, #1
 *   @0x1ccbd8 add r4, r4, #24
 *   @0x1ccbdc cmp r6, r5
 *   @0x1ccbe0 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98>
 *   @0x1ccbe4 mov r0, r7
 *   @0x1ccbe8 mov r1, r4
 *   @0x1ccbec bl 0x1cbc10 <_Z19FINALIZE_Run_Globalv+0x1a4>
 *   @0x1ccbf0 cmp r0, #0
 *   @0x1ccbf4 beq 0x1ccbd4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x40>
 *   @0x1ccbf8 ldr r3, [r4, #0x10]
 *   @0x1ccbfc mov r0, r11
 *   @0x1ccc00 str r10, [sp]
 *   @0x1ccc04 mov r1, r7
 *   @0x1ccc08 mov r2, r9
 *   @0x1ccc0c bl 0x1ccb94 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE>
 *   @0x1ccc10 subs r6, r0, #0
 *   @0x1ccc14 beq 0x1ccc84 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xf0>
 *   @0x1ccc18 ldr r6, [r8]
 *   @0x1ccc1c add r5, r5, #1
 *   @0x1ccc20 add r4, r4, #24
 *   @0x1ccc24 cmp r6, r5
 *   @0x1ccc28 bgt 0x1ccbe4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x50>
 *   @0x1ccc2c mov r6, #1
 *   @0x1ccc30 mov r0, r6
 *   @0x1ccc34 add sp, sp, #28
 *   @0x1ccc38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ccc3c ldr r0, [r8]
 *   @0x1ccc40 cmp r0, #0
 *   @0x1ccc44 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98>
 *   @0x1ccc48 ldr r12, [r2]
 *   @0x1ccc4c ldr r3, [r8, #0x1c]
 *   @0x1ccc50 cmp r3, r12
 *   @0x1ccc54 movne r1, r8
 *   @0x1ccc58 movne r2, #0
 *   @0x1ccc5c bne 0x1ccc70 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xdc>
 *   @0x1ccc60 b 0x1ccccc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x138>
 *   @0x1ccc64 ldr r3, [r1, #0x1c]
 *   @0x1ccc68 cmp r3, r12
 *   @0x1ccc6c beq 0x1cccd0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x13c>
 *   @0x1ccc70 add r2, r2, #1
 *   @0x1ccc74 add r1, r1, #24
 *   @0x1ccc78 cmp r2, r0
 *   @0x1ccc7c bne 0x1ccc64 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xd0>
 *   @0x1ccc80 b 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98>
 *   @0x1ccc84 add r3, r5, #1
 *   @0x1ccc88 add r3, r3, r3, lsl #1
 *   @0x1ccc8c ldr r4, [r8, r3, lsl #3]
 *   @0x1ccc90 ldr r3, [r4]
 *   @0x1ccc94 cmp r3, #1
 *   @0x1ccc98 ble 0x1ccd10 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x17c>
 *   @0x1ccc9c mov r1, r4
 *   @0x1ccca0 add r4, sp, #8
 *   @0x1ccca4 add r5, r5, r5, lsl #1
 *   @0x1ccca8 mov r0, r4
 *   @0x1cccac bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cccb0 ldm r4, {r0, r1, r2, r3}
 *   @0x1cccb4 add r5, r8, r5, lsl #3
 *   @0x1cccb8 add r5, r5, #8
 *   @0x1cccbc stm r5, {r0, r1, r2, r3}
 *   @0x1cccc0 mov r0, r6
 *   @0x1cccc4 add sp, sp, #28
 *   @0x1cccc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ccccc mov r2, #0
 *   @0x1cccd0 sub r5, r0, #1
 *   @0x1cccd4 add r2, r2, r2, lsl #1
 *   @0x1cccd8 mov r6, #0
 *   @0x1cccdc add r4, r5, r5, lsl #1
 *   @0x1ccce0 add r12, r8, r2, lsl #3
 *   @0x1ccce4 add r12, r12, #8
 *   @0x1ccce8 add r4, r8, r4, lsl #3
 *   @0x1cccec add r4, r4, #8
 *   @0x1cccf0 ldm r4!, {r0, r1, r2, r3}
 *   @0x1cccf4 stm r12!, {r0, r1, r2, r3}
 *   @0x1cccf8 ldm r4, {r0, r1}
 *   @0x1cccfc stm r12, {r0, r1}
 *   @0x1ccd00 mov r0, r6
 *   @0x1ccd04 str r5, [r8]
 *   @0x1ccd08 add sp, sp, #28
 *   @0x1ccd0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ccd10 mov r0, #8
 *   @0x1ccd14 add r5, r5, r5, lsl #1
 *   @0x1ccd18 bl 0x27c524 <_Znwj>
 *   @0x1ccd1c ldr r7, [r8]
 *   @0x1ccd20 add r12, r8, r5, lsl #3
 *   @0x1ccd24 sub r7, r7, #1
 *   @0x1ccd28 add r12, r12, #8
 *   @0x1ccd2c str r4, [r0, #0x4]
 *   @0x1ccd30 add r4, r7, r7, lsl #1
 *   @0x1ccd34 ldr r3, [r10]
 *   @0x1ccd38 add r4, r8, r4, lsl #3
 *   @0x1ccd3c add r4, r4, #8
 *   @0x1ccd40 str r3, [r0]
 *   @0x1ccd44 str r0, [r10]
 *   @0x1ccd48 ldm r4!, {r0, r1, r2, r3}
 *   @0x1ccd4c stm r12!, {r0, r1, r2, r3}
 *   @0x1ccd50 ldm r4, {r0, r1}
 *   @0x1ccd54 stm r12, {r0, r1}
 *   @0x1ccd58 str r7, [r8]
 *   @0x1ccd5c b 0x1ccc30 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x9c>
 *
 * ══ §21/69 b2ParticleSystem::SolveColorMixing  0x2d6440  size 460  115 条（0x2d6440..0x2d660c）
 * @func 0x2d6440 0x2d660c  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveColorMixing(b2TimeStep const&)+0x1b0 / anon_2d49b8+0x78
 * 字段偏移 top8: 0x2×12 / 0x4×7 / 0x1×5 / 0x10×5 / 0x3×5 / 0x1c×5 / 0xc×4 / 0x8×4
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d6440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d6444 mov r11, r0
 *   @0x2d6448 ldr r0, [r0, #0x54]
 *   @0x2d644c sub sp, sp, #36
 *   @0x2d6450 cmp r0, #0
 *   @0x2d6454 beq 0x2d65f8 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1b8>
 *   @0x2d6458 vldr s14, [r11, #208]
 *   @0x2d645c vldr s15, [pc, #420]
 *   @0x2d6460 vmul.f32 s15, s14, s15
 *   @0x2d6464 ldr r4, [r11, #0x74]
 *   @0x2d6468 str r0, [r11, #0x54]
 *   @0x2d646c cmp r4, #0
 *   @0x2d6470 vcvt.s32.f32 s15, s15
 *   @0x2d6474 vstr s15, [sp, #20]
 *   @0x2d6478 ble 0x2d65f0 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1b0>
 *   @0x2d647c mov r10, #0
 *   @0x2d6480 mov r8, r10
 *   @0x2d6484 ldr r2, [r11, #0x7c]
 *   @0x2d6488 add r8, r8, #1
 *   @0x2d648c ldr r3, [r11, #0x30]
 *   @0x2d6490 add r1, r2, r10
 *   @0x2d6494 ldr r0, [r2, r10]
 *   @0x2d6498 add r10, r10, #24
 *   @0x2d649c ldr r2, [r1, #0x4]
 *   @0x2d64a0 ldr r5, [r3, r0, lsl #2]
 *   @0x2d64a4 lsl r12, r0, #2
 *   @0x2d64a8 ldr r1, [r3, r2, lsl #2]
 *   @0x2d64ac lsl r3, r2, #2
 *   @0x2d64b0 and r1, r5, r1
 *   @0x2d64b4 tst r1, #256
 *   @0x2d64b8 beq 0x2d65e8 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x1a8>
 *   @0x2d64bc ldr r1, [r11, #0x54]
 *   @0x2d64c0 add r12, r1, r12
 *   @0x2d64c4 add r3, r1, r3
 *   @0x2d64c8 ldrb r4, [r1, r0, lsl #2]
 *   @0x2d64cc ldrb r6, [r12, #0x2]
 *   @0x2d64d0 ldrb r5, [r12, #0x1]
 *   @0x2d64d4 ldrb r7, [r3, #0x1]
 *   @0x2d64d8 str r6, [sp, #0x10]
 *   @0x2d64dc ldrb r9, [r12, #0x3]
 *   @0x2d64e0 rsb r7, r5, r7
 *   @0x2d64e4 str r4, [sp, #0x18]
 *   @0x2d64e8 ldrb r4, [r3, #0x3]
 *   @0x2d64ec str r7, [sp, #0x1c]
 *   @0x2d64f0 ldrb r6, [r3, #0x2]
 *   @0x2d64f4 rsb r4, r9, r4
 *   @0x2d64f8 ldr r7, [sp, #0x10]
 *   @0x2d64fc str r5, [sp, #0xc]
 *   @0x2d6500 str r4, [sp]
 *   @0x2d6504 rsb r6, r7, r6
 *   @0x2d6508 ldr r4, [sp, #0x18]
 *   @0x2d650c ldrb r5, [r1, r2, lsl #2]
 *   @0x2d6510 str r6, [sp, #0x4]
 *   @0x2d6514 rsb r5, r4, r5
 *   @0x2d6518 ldr r6, [sp, #0x1c]
 *   @0x2d651c str r5, [sp, #0x8]
 *   @0x2d6520 ldr r4, [sp, #0x4]
 *   @0x2d6524 ldr r5, [sp, #0x14]
 *   @0x2d6528 mul r7, r5, r6
 *   @0x2d652c mul r6, r5, r4
 *   @0x2d6530 ldr r4, [sp]
 *   @0x2d6534 ubfx r7, r7, #0x8, #0x8
 *   @0x2d6538 mul r5, r5, r4
 *   @0x2d653c ldr r4, [sp, #0x8]
 *   @0x2d6540 ubfx r6, r6, #0x8, #0x8
 *   @0x2d6544 str r6, [sp, #0x1c]
 *   @0x2d6548 ldr r6, [sp, #0xc]
 *   @0x2d654c add r6, r7, r6
 *   @0x2d6550 str r6, [sp, #0xc]
 *   @0x2d6554 str r5, [sp, #0x4]
 *   @0x2d6558 ldr r5, [sp, #0x14]
 *   @0x2d655c ldr r6, [sp, #0x10]
 *   @0x2d6560 mul r5, r5, r4
 *   @0x2d6564 str r5, [sp, #0x8]
 *   @0x2d6568 ldr r5, [sp, #0x4]
 *   @0x2d656c ubfx r4, r5, #0x8, #0x8
 *   @0x2d6570 ldr r5, [sp, #0x1c]
 *   @0x2d6574 add r9, r4, r9
 *   @0x2d6578 add r5, r5, r6
 *   @0x2d657c str r5, [sp, #0x10]
 *   @0x2d6580 str r9, [sp, #0x4]
 *   @0x2d6584 ldr r6, [sp, #0x8]
 *   @0x2d6588 ubfx r5, r6, #0x8, #0x8
 *   @0x2d658c ldr r6, [sp, #0x18]
 *   @0x2d6590 add r9, r5, r6
 *   @0x2d6594 strb r9, [r1, r0, lsl #2]
 *   @0x2d6598 ldr r0, [sp, #0xc]
 *   @0x2d659c ldr r6, [sp, #0x10]
 *   @0x2d65a0 strb r0, [r12, #0x1]
 *   @0x2d65a4 ldr r0, [sp, #0x4]
 *   @0x2d65a8 strb r6, [r12, #0x2]
 *   @0x2d65ac ldrb r6, [r1, r2, lsl #2]
 *   @0x2d65b0 strb r0, [r12, #0x3]
 *   @0x2d65b4 ldrb r0, [r3, #0x1]
 *   @0x2d65b8 rsb r5, r5, r6
 *   @0x2d65bc ldrb r12, [r3, #0x2]
 *   @0x2d65c0 rsb r0, r7, r0
 *   @0x2d65c4 ldr r6, [sp, #0x1c]
 *   @0x2d65c8 ldrb r7, [r3, #0x3]
 *   @0x2d65cc rsb r12, r6, r12
 *   @0x2d65d0 strb r5, [r1, r2, lsl #2]
 *   @0x2d65d4 rsb r4, r4, r7
 *   @0x2d65d8 strb r0, [r3, #0x1]
 *   @0x2d65dc strb r12, [r3, #0x2]
 *   @0x2d65e0 strb r4, [r3, #0x3]
 *   @0x2d65e4 ldr r4, [r11, #0x74]
 *   @0x2d65e8 cmp r4, r8
 *   @0x2d65ec bgt 0x2d6484 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x44>
 *   @0x2d65f0 add sp, sp, #36
 *   @0x2d65f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d65f8 add r0, r11, #40
 *   @0x2d65fc add r1, r11, #212
 *   @0x2d6600 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0>
 *   @0x2d6604 b 0x2d6458 <_ZN16b2ParticleSystem16SolveColorMixingERK10b2TimeStep+0x18>
 *   @0x2d6608 orrmi r0, r0, #0
 *
 * ══ §22/69 RTree<CInstance*, int, float, 6, 2>::Search  0x10d558  size 456  114 条（0x10d558..0x10d720）
 * @func 0x10d558 0x10d720  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*)+0xbc×2 / RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*)+0x1b8×2 / RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*)+0xc8 / RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*) / RTree<CInstance*, int, float, 6, 2>::Search(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Rect*, int&, bool (*)(CInstance*, void*), void*)+0x168
 * 字段偏移 top8: 0xc×8 / 0x8×6 / 0x4×4 / 0x10×3 / 0x14×3 / 0x38×1 / 0x3c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10d558 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10d55c mov r8, r1
 *   @0x10d560 ldr r1, [r1, #0x4]
 *   @0x10d564 sub sp, sp, #20
 *   @0x10d568 mov r10, r0
 *   @0x10d56c mov r5, r2
 *   @0x10d570 cmp r1, #0
 *   @0x10d574 mov r7, r3
 *   @0x10d578 ldr r9, [sp, #0x38]
 *   @0x10d57c ldr r12, [r8]
 *   @0x10d580 ldr r11, [sp, #0x3c]
 *   @0x10d584 ble 0x10d620 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xc8>
 *   @0x10d588 cmp r12, #0
 *   @0x10d58c ble 0x10d614 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xbc>
 *   @0x10d590 mov r4, r8
 *   @0x10d594 mov r6, #0
 *   @0x10d598 str r8, [sp, #0xc]
 *   @0x10d59c ldr r2, [r5]
 *   @0x10d5a0 ldr r3, [r4, #0x10]
 *   @0x10d5a4 cmp r2, r3
 *   @0x10d5a8 bgt 0x10d604 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xac>
 *   @0x10d5ac ldr r2, [r4, #0x8]
 *   @0x10d5b0 ldr r3, [r5, #0x8]
 *   @0x10d5b4 cmp r2, r3
 *   @0x10d5b8 bgt 0x10d604 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xac>
 *   @0x10d5bc ldr r1, [r5, #0x4]
 *   @0x10d5c0 mov r0, r10
 *   @0x10d5c4 ldr r8, [r4, #0x14]
 *   @0x10d5c8 mov r2, r5
 *   @0x10d5cc mov r3, r7
 *   @0x10d5d0 cmp r1, r8
 *   @0x10d5d4 bgt 0x10d604 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xac>
 *   @0x10d5d8 ldr r1, [r4, #0xc]
 *   @0x10d5dc ldr r8, [r5, #0xc]
 *   @0x10d5e0 cmp r1, r8
 *   @0x10d5e4 bgt 0x10d604 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xac>
 *   @0x10d5e8 ldr r1, [r4, #0x18]
 *   @0x10d5ec stm sp, {r9, r11}
 *   @0x10d5f0 bl 0x10d558 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_>
 *   @0x10d5f4 cmp r0, #0
 *   @0x10d5f8 beq 0x10d6b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x158>
 *   @0x10d5fc ldr r8, [sp, #0xc]
 *   @0x10d600 ldr r12, [r8]
 *   @0x10d604 add r6, r6, #1
 *   @0x10d608 add r4, r4, #24
 *   @0x10d60c cmp r12, r6
 *   @0x10d610 bgt 0x10d59c <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x44>
 *   @0x10d614 mov r0, #1
 *   @0x10d618 add sp, sp, #20
 *   @0x10d61c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10d620 cmp r12, #0
 *   @0x10d624 ble 0x10d614 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xbc>
 *   @0x10d628 cmp r9, #0
 *   @0x10d62c movne r4, r8
 *   @0x10d630 movne r6, #0
 *   @0x10d634 beq 0x10d6bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x164>
 *   @0x10d638 ldr r2, [r5]
 *   @0x10d63c ldr r3, [r4, #0x10]
 *   @0x10d640 cmp r2, r3
 *   @0x10d644 bgt 0x10d69c <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x144>
 *   @0x10d648 ldr r2, [r4, #0x8]
 *   @0x10d64c ldr r3, [r5, #0x8]
 *   @0x10d650 cmp r2, r3
 *   @0x10d654 bgt 0x10d69c <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x144>
 *   @0x10d658 ldr r2, [r5, #0x4]
 *   @0x10d65c mov r1, r11
 *   @0x10d660 ldr r3, [r4, #0x14]
 *   @0x10d664 cmp r2, r3
 *   @0x10d668 bgt 0x10d69c <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x144>
 *   @0x10d66c ldr r2, [r4, #0xc]
 *   @0x10d670 ldr r3, [r5, #0xc]
 *   @0x10d674 cmp r2, r3
 *   @0x10d678 bgt 0x10d69c <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x144>
 *   @0x10d67c ldr r3, [r7]
 *   @0x10d680 ldr r0, [r4, #0x1c]
 *   @0x10d684 add r3, r3, #1
 *   @0x10d688 str r3, [r7]
 *   @0x10d68c blx r9
 *   @0x10d690 cmp r0, #0
 *   @0x10d694 beq 0x10d6b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x158>
 *   @0x10d698 ldr r12, [r8]
 *   @0x10d69c add r6, r6, #1
 *   @0x10d6a0 add r4, r4, #24
 *   @0x10d6a4 cmp r12, r6
 *   @0x10d6a8 bgt 0x10d638 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xe0>
 *   @0x10d6ac b 0x10d614 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xbc>
 *   @0x10d6b0 mov r0, #0
 *   @0x10d6b4 add sp, sp, #20
 *   @0x10d6b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10d6bc mov r3, r8
 *   @0x10d6c0 ldr r1, [r5]
 *   @0x10d6c4 add r9, r9, #1
 *   @0x10d6c8 ldr r2, [r3, #0x10]
 *   @0x10d6cc cmp r1, r2
 *   @0x10d6d0 bgt 0x10d710 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x1b8>
 *   @0x10d6d4 ldr r1, [r5, #0x8]
 *   @0x10d6d8 ldr r2, [r3, #0x8]
 *   @0x10d6dc cmp r1, r2
 *   @0x10d6e0 blt 0x10d710 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x1b8>
 *   @0x10d6e4 ldr r1, [r3, #0x14]
 *   @0x10d6e8 ldr r2, [r5, #0x4]
 *   @0x10d6ec cmp r1, r2
 *   @0x10d6f0 blt 0x10d710 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x1b8>
 *   @0x10d6f4 ldr r2, [r5, #0xc]
 *   @0x10d6f8 ldr r1, [r3, #0xc]
 *   @0x10d6fc cmp r1, r2
 *   @0x10d700 ldrle r2, [r7]
 *   @0x10d704 addle r2, r2, #1
 *   @0x10d708 strle r2, [r7]
 *   @0x10d70c ldrle r12, [r8]
 *   @0x10d710 cmp r9, r12
 *   @0x10d714 add r3, r3, #24
 *   @0x10d718 blt 0x10d6c0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0x168>
 *   @0x10d71c b 0x10d614 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_+0xbc>
 *
 * ══ §23/69 HandleStep  0x1cdf6c  size 456  114 条（0x1cdf6c..0x1ce134）
 * @func 0x1cdf6c 0x1ce144  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1cdf7c→0x757e7c, 0x1cdf9c→0x536f20, 0x1cdfa8→0x536f70, 0x1cdfe0→0x53ab70, 0x1cdfe4→0x542374, 0x1ce0e8→0x757e80, 0x1ce100→0x757e80
 * 调用序列: HandleStep(int)+0x164 / HandleStep(int)+0x148 / Perform_Event(CInstance*, CInstance*, int, int) / CProfiler::Push(int, int)
 * 字段偏移 top8: 0x10×5 / 0x4×5 / 0x8×4 / 0x14×2 / 0x2×2 / 0x140×2 / 0x19c×1 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cdf6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cdf70 sub sp, sp, #28
 *   @0x1cdf74 ldr r8, [pc, #0x19c]
 *   @0x1cdf78 mov r11, r0
 *   @0x1cdf7c ldr r3, [pc, #0x198]
 *   @0x1cdf80 add r8, pc, r8
 *   @0x1cdf84 str r8, [sp, #0x10]
 *   @0x1cdf88 ldr r3, [r8, r3]
 *   @0x1cdf8c str r3, [sp, #0x14]
 *   @0x1cdf90 ldrb r3, [r3]
 *   @0x1cdf94 cmp r3, #0
 *   @0x1cdf98 bne 0x1ce100 <_Z10HandleStepi+0x194>
 *   @0x1cdf9c ldr r3, [pc, #0x17c]
 *   @0x1cdfa0 add r0, r11, #768
 *   @0x1cdfa4 ldr r9, [sp, #0x10]
 *   @0x1cdfa8 ldr r4, [pc, #0x174]
 *   @0x1cdfac ldr r1, [r9, r3]
 *   @0x1cdfb0 ldrd r8, r9, [r1]
 *   @0x1cdfb4 adds r2, r8, #1
 *   @0x1cdfb8 adc r3, r9, #0
 *   @0x1cdfbc strd r8, r9, [sp, #8]
 *   @0x1cdfc0 ldr r9, [sp, #0x10]
 *   @0x1cdfc4 strd r2, r3, [r1]
 *   @0x1cdfc8 ldr r3, [r9, r4]
 *   @0x1cdfcc ldr r8, [r3, r0, lsl #2]
 *   @0x1cdfd0 cmp r8, #0
 *   @0x1cdfd4 ble 0x1ce0d0 <_Z10HandleStepi+0x164>
 *   @0x1cdfd8 ldr r12, [sp, #0x10]
 *   @0x1cdfdc mov r7, #0
 *   @0x1cdfe0 ldr r2, [pc, #0x140]
 *   @0x1cdfe4 ldr r3, [pc, #0x140]
 *   @0x1cdfe8 ldr r9, [r12, r2]
 *   @0x1cdfec ldr r10, [r12, r3]
 *   @0x1cdff0 add r9, r9, r0, lsl #3
 *   @0x1cdff4 ldr r3, [r10]
 *   @0x1cdff8 ldr r1, [r9, #0x4]
 *   @0x1cdffc ldr r2, [r3, #0x4]
 *   @0x1ce000 ldr r1, [r1, r7, lsl #2]
 *   @0x1ce004 ldr r3, [r3]
 *   @0x1ce008 and r2, r1, r2
 *   @0x1ce00c ldr r3, [r3, r2, lsl #3]
 *   @0x1ce010 cmp r3, #0
 *   @0x1ce014 bne 0x1ce028 <_Z10HandleStepi+0xbc>
 *   @0x1ce018 b 0x1ce0c4 <_Z10HandleStepi+0x158>
 *   @0x1ce01c ldr r3, [r3, #0x4]
 *   @0x1ce020 cmp r3, #0
 *   @0x1ce024 beq 0x1ce0c4 <_Z10HandleStepi+0x158>
 *   @0x1ce028 ldr r2, [r3, #0x8]
 *   @0x1ce02c cmp r1, r2
 *   @0x1ce030 bne 0x1ce01c <_Z10HandleStepi+0xb0>
 *   @0x1ce034 ldr r3, [r3, #0xc]
 *   @0x1ce038 cmp r3, #0
 *   @0x1ce03c beq 0x1ce0c4 <_Z10HandleStepi+0x158>
 *   @0x1ce040 ldr r6, [r3, #0xc4]
 *   @0x1ce044 cmp r6, #0
 *   @0x1ce048 beq 0x1ce0c4 <_Z10HandleStepi+0x158>
 *   @0x1ce04c ldr r3, [r6, #0x8]
 *   @0x1ce050 cmp r3, #0
 *   @0x1ce054 beq 0x1ce0c4 <_Z10HandleStepi+0x158>
 *   @0x1ce058 str r8, [sp, #0x4]
 *   @0x1ce05c str r9, [sp]
 *   @0x1ce060 b 0x1ce070 <_Z10HandleStepi+0x104>
 *   @0x1ce064 ldr r3, [r6, #0x8]
 *   @0x1ce068 cmp r3, #0
 *   @0x1ce06c beq 0x1ce0bc <_Z10HandleStepi+0x150>
 *   @0x1ce070 ldr r0, [r6, #0x8]
 *   @0x1ce074 ldr r6, [r6]
 *   @0x1ce078 ldrb r3, [r0, #0x68]
 *   @0x1ce07c cmp r3, #0
 *   @0x1ce080 bne 0x1ce0b4 <_Z10HandleStepi+0x148>
 *   @0x1ce084 ldrb r3, [r0, #0x69]
 *   @0x1ce088 cmp r3, #0
 *   @0x1ce08c bne 0x1ce0b4 <_Z10HandleStepi+0x148>
 *   @0x1ce090 ldrd r4, r5, [r0, #112]
 *   @0x1ce094 mov r1, r0
 *   @0x1ce098 ldrd r8, r9, [sp, #8]
 *   @0x1ce09c mov r2, #3
 *   @0x1ce0a0 mov r3, r11
 *   @0x1ce0a4 cmp r8, r4
 *   @0x1ce0a8 sbcs r9, r9, r5
 *   @0x1ce0ac blt 0x1ce0b4 <_Z10HandleStepi+0x148>
 *   @0x1ce0b0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1ce0b4 cmp r6, #0
 *   @0x1ce0b8 bne 0x1ce064 <_Z10HandleStepi+0xf8>
 *   @0x1ce0bc ldr r8, [sp, #0x4]
 *   @0x1ce0c0 ldr r9, [sp]
 *   @0x1ce0c4 add r7, r7, #1
 *   @0x1ce0c8 cmp r7, r8
 *   @0x1ce0cc bne 0x1cdff4 <_Z10HandleStepi+0x88>
 *   @0x1ce0d0 ldr r12, [sp, #0x14]
 *   @0x1ce0d4 ldrb r3, [r12]
 *   @0x1ce0d8 cmp r3, #0
 *   @0x1ce0dc bne 0x1ce0e8 <_Z10HandleStepi+0x17c>
 *   @0x1ce0e0 add sp, sp, #28
 *   @0x1ce0e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ce0e8 ldr r3, [pc, #0x40]
 *   @0x1ce0ec ldr r12, [sp, #0x10]
 *   @0x1ce0f0 ldr r0, [r12, r3]
 *   @0x1ce0f4 add sp, sp, #28
 *   @0x1ce0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ce0fc b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1ce100 ldr r3, [pc, #0x28]
 *   @0x1ce104 mov r1, #6
 *   @0x1ce108 mov r2, #4
 *   @0x1ce10c ldr r0, [r8, r3]
 *   @0x1ce110 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1ce114 b 0x1cdf9c <_Z10HandleStepi+0x30>
 *   @0x1ce118 .word 0x00223cd0
 *   @0x1ce11c .word 0xffffbf18
 *   @0x1ce120 .word 0xffffdeb4
 *   @0x1ce124 .word 0xffffdeb8
 *   @0x1ce128 .word 0xffffdebc
 *   @0x1ce12c .word 0xffffbfec
 *   @0x1ce130 .word 0xffffbf1c
 *
 * ══ §24/69 anon_230fbc  0x230fbc  size 456  114 条（0x230fbc..0x231184）
 * @func 0x230fbc 0x231184  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×5 / 0xb65bc×2 / 0xb65b0 / ogg_sync_init / ogg_sync_buffer / ogg_sync_wrote / ogg_stream_init / anon_22fd0c+0x628
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x34×2 / 0x48×2 / 0x4c×2 / 0x4×2 / 0x288×1 / 0x1c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x230fbc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x230fc0 subs r8, r0, #0
 *   @0x230fc4 sub sp, sp, #20
 *   @0x230fc8 mov r6, r1
 *   @0x230fcc mov r7, r2
 *   @0x230fd0 mov r5, r3
 *   @0x230fd4 ldr r1, [sp, #0x34]
 *   @0x230fd8 beq 0x23116c <ov_clear+0x2a8>
 *   @0x230fdc cmp r1, #0
 *   @0x230fe0 beq 0x23116c <ov_clear+0x2a8>
 *   @0x230fe4 mov r12, #1
 *   @0x230fe8 mov r2, #0
 *   @0x230fec mov r3, #0
 *   @0x230ff0 str r12, [sp]
 *   @0x230ff4 blx r1
 *   @0x230ff8 mov r9, r0
 *   @0x230ffc mov r12, #0
 *   @0x231000 mov r2, #664
 *   @0x231004 mov r1, r12
 *   @0x231008 mov r0, r6
 *   @0x23100c str r12, [sp, #0x8]
 *   @0x231010 add r4, r6, #24
 *   @0x231014 str r12, [sp, #0xc]
 *   @0x231018 bl 0xb65b0 <memset@plt>
 *   @0x23101c add r12, sp, #44
 *   @0x231020 ldmib r12, {r0, r1, r2, r3}
 *   @0x231024 mov r12, r6
 *   @0x231028 str r8, [r12], #648
 *   @0x23102c stm r12, {r0, r1, r2, r3}
 *   @0x231030 mov r0, r4
 *   @0x231034 bl 0x234b04 <ogg_sync_init>
 *   @0x231038 cmp r7, #0
 *   @0x23103c beq 0x231064 <ov_clear+0x1a0>
 *   @0x231040 mov r1, r5
 *   @0x231044 mov r0, r4
 *   @0x231048 bl 0x234b8c <ogg_sync_buffer>
 *   @0x23104c mov r1, r7
 *   @0x231050 mov r2, r5
 *   @0x231054 bl 0xb65bc <memcpy@plt>
 *   @0x231058 mov r0, r4
 *   @0x23105c mov r1, r5
 *   @0x231060 bl 0x234c54 <ogg_sync_wrote>
 *   @0x231064 cmn r9, #1
 *   @0x231068 mov r7, #1
 *   @0x23106c mov r1, #32
 *   @0x231070 str r7, [r6, #0x34]
 *   @0x231074 movne r3, #1
 *   @0x231078 mov r0, r7
 *   @0x23107c strne r3, [r6, #0x4]
 *   @0x231080 mov r4, #0
 *   @0x231084 bl 0xb6c34 <calloc@plt>
 *   @0x231088 mov r1, #16
 *   @0x23108c str r0, [r6, #0x48]
 *   @0x231090 mov r0, r7
 *   @0x231094 bl 0xb6c34 <calloc@plt>
 *   @0x231098 mvn r1, #0
 *   @0x23109c str r0, [r6, #0x4c]
 *   @0x2310a0 add r0, r6, #120
 *   @0x2310a4 bl 0x2341a4 <ogg_stream_init>
 *   @0x2310a8 ldr r1, [r6, #0x48]
 *   @0x2310ac ldr r2, [r6, #0x4c]
 *   @0x2310b0 add r3, sp, #12
 *   @0x2310b4 str r4, [sp, #0x4]
 *   @0x2310b8 mov r0, r6
 *   @0x2310bc str r3, [sp]
 *   @0x2310c0 add r3, sp, #8
 *   @0x2310c4 bl 0x230334 <vorbis_packet_blocksize+0x6b8>
 *   @0x2310c8 subs r8, r0, #0
 *   @0x2310cc blt 0x231174 <ov_clear+0x2b0>
 *   @0x2310d0 ldr r0, [sp, #0xc]
 *   @0x2310d4 mov r1, #4
 *   @0x2310d8 mov r5, #0
 *   @0x2310dc add r0, r0, #2
 *   @0x2310e0 bl 0xb6c34 <calloc@plt>
 *   @0x2310e4 ldr lr, [r6, #0x1c8]
 *   @0x2310e8 ldr r12, [sp, #0xc]
 *   @0x2310ec ldr r4, [sp, #0x8]
 *   @0x2310f0 str lr, [r6, #0x5c]
 *   @0x2310f4 lsl r2, r12, #2
 *   @0x2310f8 mov r1, r4
 *   @0x2310fc mov r3, r0
 *   @0x231100 add r0, r0, #8
 *   @0x231104 str r3, [r6, #0x40]
 *   @0x231108 str lr, [r3]
 *   @0x23110c str r12, [r3, #0x4]
 *   @0x231110 bl 0xb65bc <memcpy@plt>
 *   @0x231114 mov r1, #8
 *   @0x231118 mov r0, r7
 *   @0x23111c bl 0xb6c34 <calloc@plt>
 *   @0x231120 mov r1, #8
 *   @0x231124 mov r9, r0
 *   @0x231128 str r0, [r6, #0x38]
 *   @0x23112c mov r0, r7
 *   @0x231130 bl 0xb6c34 <calloc@plt>
 *   @0x231134 ldrd r2, r3, [r6, #8]
 *   @0x231138 str r7, [r6, #0x58]
 *   @0x23113c mov r1, r4
 *   @0x231140 mov r4, #0
 *   @0x231144 str r0, [r6, #0x3c]
 *   @0x231148 strd r4, r5, [r9]
 *   @0x23114c strd r2, r3, [r0]
 *   @0x231150 cmp r1, #0
 *   @0x231154 beq 0x231160 <ov_clear+0x29c>
 *   @0x231158 mov r0, r1
 *   @0x23115c bl 0xb655c <free@plt>
 *   @0x231160 mov r0, r8
 *   @0x231164 add sp, sp, #20
 *   @0x231168 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x23116c mvn r9, #0
 *   @0x231170 b 0x230ffc <ov_clear+0x138>
 *   @0x231174 str r4, [r6]
 *   @0x231178 mov r0, r6
 *   @0x23117c bl 0x230ec4 <ov_clear>
 *   @0x231180 ldr r1, [sp, #0x8]
 *
 * ══ §25/69 CSkeletonInstance::CSkeletonInstance  0xc04d8  size 452  113 条（0xc04d8..0xc069c）
 * @func 0xc04d8 0xc069c  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetupSkeletonData(spSkeletonData*) / CSkeletonInstance::CSkeletonInstance(CSkeletonInstance*)+0x58 / CSkeletonInstance::GetAnimation(int) const / CSkeletonInstance::SelectAnimation(char const*) / CSkeletonInstance::GetSkin() const / CSkeletonInstance::SelectSkin(char const*) / CSkeletonInstance::CSkeletonInstance(CSkeletonInstance*)+0xb0 / CSkeletonInstance::CloneAttachment(spAttachment*, spAtlas*)
 * 字段偏移 top8: 0x4×7 / 0x18×5 / 0x1c×5 / 0x30×4 / 0xc×4 / 0x8×4 / 0x10×3 / 0x2×3
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc04d8 push {r4, r5, r6, r7, lr}
 *   @0xc04dc mov r7, r1
 *   @0xc04e0 sub sp, sp, #20
 *   @0xc04e4 ldr r1, [r1, #0x30]
 *   @0xc04e8 mov r5, r0
 *   @0xc04ec bl 0xbe5dc <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData>
 *   @0xc04f0 ldr r3, [r7, #0x28]
 *   @0xc04f4 ldr r3, [r3, #0xc]
 *   @0xc04f8 cmp r3, #0
 *   @0xc04fc movgt r4, #0
 *   @0xc0500 ble 0xc0530 <_ZN17CSkeletonInstanceC2EPS_+0x58>
 *   @0xc0504 mov r1, #0
 *   @0xc0508 mov r0, r7
 *   @0xc050c bl 0xc01b0 <_ZNK17CSkeletonInstance12GetAnimationEi>
 *   @0xc0510 add r4, r4, #1
 *   @0xc0514 mov r1, r0
 *   @0xc0518 mov r0, r5
 *   @0xc051c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xc0520 ldr r3, [r7, #0x28]
 *   @0xc0524 ldr r3, [r3, #0xc]
 *   @0xc0528 cmp r3, r4
 *   @0xc052c bgt 0xc0504 <_ZN17CSkeletonInstanceC2EPS_+0x2c>
 *   @0xc0530 mov r0, r7
 *   @0xc0534 mov r4, #0
 *   @0xc0538 bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv>
 *   @0xc053c mov r1, r0
 *   @0xc0540 mov r0, r5
 *   @0xc0544 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0xc0548 str r4, [r5, #0x10]
 *   @0xc054c ldr r3, [r7, #0x10]
 *   @0xc0550 str r4, [r5, #0x14]
 *   @0xc0554 cmp r3, r4
 *   @0xc0558 str r4, [r5, #0x18]
 *   @0xc055c ble 0xc0588 <_ZN17CSkeletonInstanceC2EPS_+0xb0>
 *   @0xc0560 ldr r2, [r7, #0x14]
 *   @0xc0564 mov r0, r5
 *   @0xc0568 ldr r3, [r7, #0x18]
 *   @0xc056c ldr r1, [r2, r4, lsl #2]
 *   @0xc0570 ldr r2, [r3, r4, lsl #2]
 *   @0xc0574 add r4, r4, #1
 *   @0xc0578 bl 0xbfc8c <_ZN17CSkeletonInstance15CloneAttachmentEP12spAttachmentP7spAtlas>
 *   @0xc057c ldr r3, [r7, #0x10]
 *   @0xc0580 cmp r3, r4
 *   @0xc0584 bgt 0xc0560 <_ZN17CSkeletonInstanceC2EPS_+0x88>
 *   @0xc0588 ldr r3, [r5, #0x30]
 *   @0xc058c ldr r3, [r3, #0x18]
 *   @0xc0590 cmp r3, #0
 *   @0xc0594 movgt r4, #0
 *   @0xc0598 ble 0xc05e8 <_ZN17CSkeletonInstanceC2EPS_+0x110>
 *   @0xc059c ldr r3, [r7, #0x30]
 *   @0xc05a0 ldr r0, [r7, #0x1c]
 *   @0xc05a4 ldr r3, [r3, #0x1c]
 *   @0xc05a8 ldr r6, [r3, r4, lsl #2]
 *   @0xc05ac add r4, r4, #1
 *   @0xc05b0 ldr r1, [r6, #0x4]
 *   @0xc05b4 bl 0x28a18c <spSkeleton_findSlot>
 *   @0xc05b8 mov r3, #0
 *   @0xc05bc ldr r2, [r0, #0x18]
 *   @0xc05c0 mov r0, r5
 *   @0xc05c4 cmp r2, r3
 *   @0xc05c8 beq 0xc05d8 <_ZN17CSkeletonInstanceC2EPS_+0x100>
 *   @0xc05cc ldr r1, [r6, #0x4]
 *   @0xc05d0 ldr r2, [r2]
 *   @0xc05d4 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b>
 *   @0xc05d8 ldr r3, [r5, #0x30]
 *   @0xc05dc ldr r3, [r3, #0x18]
 *   @0xc05e0 cmp r3, r4
 *   @0xc05e4 bgt 0xc059c <_ZN17CSkeletonInstanceC2EPS_+0xc4>
 *   @0xc05e8 ldr r3, [r5, #0x2c]
 *   @0xc05ec ldr r6, [r3, #0x8]
 *   @0xc05f0 cmp r6, #0
 *   @0xc05f4 beq 0xc0638 <_ZN17CSkeletonInstanceC2EPS_+0x160>
 *   @0xc05f8 ldr r4, [r6, #0x4]
 *   @0xc05fc cmp r4, #0
 *   @0xc0600 beq 0xc062c <_ZN17CSkeletonInstanceC2EPS_+0x154>
 *   @0xc0604 ldr r2, [r4]
 *   @0xc0608 mov r0, r5
 *   @0xc060c ldr r12, [r6]
 *   @0xc0610 ldr r3, [r4, #0x4]
 *   @0xc0614 ldr r2, [r2]
 *   @0xc0618 ldr r1, [r12]
 *   @0xc061c bl 0xbe580 <_ZN17CSkeletonInstance15SetAnimationMixEPKcS1_f>
 *   @0xc0620 ldr r4, [r4, #0x8]
 *   @0xc0624 cmp r4, #0
 *   @0xc0628 bne 0xc0604 <_ZN17CSkeletonInstanceC2EPS_+0x12c>
 *   @0xc062c ldr r6, [r6, #0x8]
 *   @0xc0630 cmp r6, #0
 *   @0xc0634 bne 0xc05f8 <_ZN17CSkeletonInstanceC2EPS_+0x120>
 *   @0xc0638 ldr r2, [r7, #0x1c]
 *   @0xc063c vldr s15, [r2, #88]
 *   @0xc0640 vneg.f32 s15, s15
 *   @0xc0644 ldrb r0, [r7, #0x4]
 *   @0xc0648 ldr r1, [r7]
 *   @0xc064c mov r4, #0
 *   @0xc0650 ldr r3, [r2, #0x5c]
 *   @0xc0654 ldr r12, [r5, #0x1c]
 *   @0xc0658 strb r0, [r5, #0x4]
 *   @0xc065c vstr s15, [r12, #88]
 *   @0xc0660 ldr r12, [r2, #0xc]
 *   @0xc0664 mov r0, r5
 *   @0xc0668 ldr r2, [r2, #0x58]
 *   @0xc066c ldr lr, [r12, #0x20]
 *   @0xc0670 str lr, [sp]
 *   @0xc0674 ldr lr, [r12, #0x24]
 *   @0xc0678 str lr, [sp, #0x4]
 *   @0xc067c ldr r12, [r12, #0x1c]
 *   @0xc0680 str r4, [sp, #0xc]
 *   @0xc0684 str r12, [sp, #0x8]
 *   @0xc0688 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xc068c mov r0, r5
 *   @0xc0690 strb r4, [r5, #0x5]
 *   @0xc0694 add sp, sp, #20
 *   @0xc0698 pop {r4, r5, r6, r7, pc}
 *
 * ══ §26/69 VM::DebugLineNumber  0xec2b8  size 452  113 条（0xec2b8..0xec47c）
 * @func 0xec2b8 0xec47c  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / VM::DebugLineNumber(VMDebugInfo*, char const*, char**)+0x1b4 / utf8_extract_char / 0xb65e0 / 0xb66b8 / 0xb6544 / 0xb65bc
 * 字段偏移 top8: 0x-1×3 / 0x1×3 / 0x4×2 / 0x174×1 / 0xc0×1 / 0x7×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec2b8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xec2bc subs r4, r0, #0
 *   @0xec2c0 sub sp, sp, #8
 *   @0xec2c4 mov r5, r1
 *   @0xec2c8 mov r9, r2
 *   @0xec2cc beq 0xec46c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1b4>
 *   @0xec2d0 mov r0, r1
 *   @0xec2d4 bl 0xb6538 <strlen@plt>
 *   @0xec2d8 ldr r10, [r4, #0x4]
 *   @0xec2dc cmp r0, r10
 *   @0xec2e0 sublt r10, r0, #1
 *   @0xec2e4 cmp r10, #0
 *   @0xec2e8 blt 0xec46c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1b4>
 *   @0xec2ec add r10, r5, r10
 *   @0xec2f0 cmp r5, r10
 *   @0xec2f4 beq 0xec45c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1a4>
 *   @0xec2f8 ldr r8, [pc, #0x174]
 *   @0xec2fc add r6, sp, #4
 *   @0xec300 mov r7, #0
 *   @0xec304 add r8, pc, r8
 *   @0xec308 mov r0, r6
 *   @0xec30c str r10, [sp, #0x4]
 *   @0xec310 bl 0x10fb38 <utf8_extract_char>
 *   @0xec314 cmp r0, #10
 *   @0xec318 beq 0xec374 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xbc>
 *   @0xec31c ldrb r3, [r10, #-0x1]
 *   @0xec320 sub r2, r10, #1
 *   @0xec324 tst r3, #128
 *   @0xec328 beq 0xec3a0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xe8>
 *   @0xec32c and r3, r3, #192
 *   @0xec330 cmp r3, #192
 *   @0xec334 beq 0xec3a0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xe8>
 *   @0xec338 sub r3, r10, #2
 *   @0xec33c b 0xec348 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x90>
 *   @0xec340 cmp r4, #192
 *   @0xec344 beq 0xec35c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xa4>
 *   @0xec348 mov r10, r3
 *   @0xec34c ldrb r12, [r3], #-1
 *   @0xec350 tst r12, #128
 *   @0xec354 and r4, r12, #192
 *   @0xec358 bne 0xec340 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x88>
 *   @0xec35c cmp r5, r10
 *   @0xec360 bne 0xec308 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x50>
 *   @0xec364 add r7, r7, #1
 *   @0xec368 mov r0, r7
 *   @0xec36c add sp, sp, #8
 *   @0xec370 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xec374 add r0, r10, #1
 *   @0xec378 mov r1, r8
 *   @0xec37c mov r2, #6
 *   @0xec380 bl 0xb65e0 <strncmp@plt>
 *   @0xec384 cmp r0, #0
 *   @0xec388 beq 0xec3b0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xf8>
 *   @0xec38c ldrb r3, [r10, #-0x1]
 *   @0xec390 add r7, r7, #1
 *   @0xec394 sub r2, r10, #1
 *   @0xec398 tst r3, #128
 *   @0xec39c bne 0xec32c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x74>
 *   @0xec3a0 mov r10, r2
 *   @0xec3a4 cmp r5, r10
 *   @0xec3a8 bne 0xec308 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x50>
 *   @0xec3ac b 0xec364 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xac>
 *   @0xec3b0 ldr r3, [pc, #0xc0]
 *   @0xec3b4 add r5, r10, #7
 *   @0xec3b8 ldrb r2, [r10, #0x7]
 *   @0xec3bc ldr r3, [pc, r3]
 *   @0xec3c0 ldr r12, [r3]
 *   @0xec3c4 add r3, r12, r2
 *   @0xec3c8 ldrb r3, [r3, #0x1]
 *   @0xec3cc tst r3, #8
 *   @0xec3d0 bne 0xec464 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1ac>
 *   @0xec3d4 add r10, r10, #8
 *   @0xec3d8 mov r4, r10
 *   @0xec3dc add r10, r10, #1
 *   @0xec3e0 ldrb r3, [r4]
 *   @0xec3e4 add r3, r12, r3
 *   @0xec3e8 ldrb r3, [r3, #0x1]
 *   @0xec3ec tst r3, #8
 *   @0xec3f0 beq 0xec3d8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x120>
 *   @0xec3f4 add r3, r4, #1
 *   @0xec3f8 mov r0, r3
 *   @0xec3fc add r3, r3, #1
 *   @0xec400 ldrb r2, [r0]
 *   @0xec404 add r2, r12, r2
 *   @0xec408 ldrb r2, [r2, #0x1]
 *   @0xec40c and r2, r2, #8
 *   @0xec410 ands r6, r2, #255
 *   @0xec414 bne 0xec3f8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x140>
 *   @0xec418 bl 0xb66b8 <atoi@plt>
 *   @0xec41c cmp r9, #0
 *   @0xec420 add r0, r0, r7
 *   @0xec424 sub r7, r0, #1
 *   @0xec428 beq 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0>
 *   @0xec42c rsb r4, r5, r4
 *   @0xec430 add r0, r4, #1
 *   @0xec434 bl 0xb6544 <malloc@plt>
 *   @0xec438 mov r1, r5
 *   @0xec43c mov r2, r4
 *   @0xec440 str r0, [r9]
 *   @0xec444 bl 0xb65bc <memcpy@plt>
 *   @0xec448 ldr r3, [r9]
 *   @0xec44c mov r0, r7
 *   @0xec450 strb r6, [r3, r4]
 *   @0xec454 add sp, sp, #8
 *   @0xec458 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xec45c mov r7, #1
 *   @0xec460 b 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0>
 *   @0xec464 mov r4, r5
 *   @0xec468 b 0xec3f4 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x13c>
 *   @0xec46c mvn r7, #0
 *   @0xec470 b 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0>
 *   @0xec474 eoreq r8, r4, r4, asr #16
 *   @0xec478 eorseq r1, r0, r4, asr #11
 *
 * ══ §27/69 CSprite::UnpackWADMask  0x1e3994  size 452  113 条（0x1e3994..0x1e3b58）
 * @func 0x1e3994 0x1e3b58  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / CSprite::UnpackWADMask(int)+0x1a0 / CSprite::UnpackWADMask(int)+0x1b4 / CSprite::UnpackWADMask(int)+0x168 / CSprite::UnpackWADMask(int)+0xac
 * 字段偏移 top8: 0x4×7 / 0x8×5 / 0x64×3 / 0xc×3 / 0x10×3 / 0x31×2 / 0x14×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3994 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e3998 sub sp, sp, #28
 *   @0x1e399c ldrb r5, [r0, #0x31]
 *   @0x1e39a0 str r0, [sp, #0x4]
 *   @0x1e39a4 cmp r5, #0
 *   @0x1e39a8 bne 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac>
 *   @0x1e39ac ldr r6, [r0, #0x64]
 *   @0x1e39b0 cmp r6, #0
 *   @0x1e39b4 beq 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac>
 *   @0x1e39b8 ldr r4, [r0, #0x68]
 *   @0x1e39bc cmp r4, #0
 *   @0x1e39c0 beq 0x1e3b40 <_ZN7CSprite13UnpackWADMaskEi+0x1ac>
 *   @0x1e39c4 ldr r8, [sp, #0x4]
 *   @0x1e39c8 lsl r1, r6, #3
 *   @0x1e39cc ldr r12, [pc, #0x17c]
 *   @0x1e39d0 movw r3, #0x22d
 *   @0x1e39d4 ldr r7, [pc, #0x178]
 *   @0x1e39d8 add r0, r0, #64
 *   @0x1e39dc ldr r2, [r8, #0x18]
 *   @0x1e39e0 ldr r12, [pc, r12]
 *   @0x1e39e4 add r7, pc, r7
 *   @0x1e39e8 subs r2, r6, r2
 *   @0x1e39ec ldr lr, [r12]
 *   @0x1e39f0 rsbs r6, r2, #0
 *   @0x1e39f4 adcs r6, r6, r2
 *   @0x1e39f8 mov r2, r7
 *   @0x1e39fc strb r6, [r8, #0x35]
 *   @0x1e3a00 add lr, lr, #1
 *   @0x1e3a04 str lr, [r12]
 *   @0x1e3a08 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e3a0c ldr r3, [r8, #0x64]
 *   @0x1e3a10 cmp r3, #0
 *   @0x1e3a14 str r3, [r8, #0x3c]
 *   @0x1e3a18 ble 0x1e3b34 <_ZN7CSprite13UnpackWADMaskEi+0x1a0>
 *   @0x1e3a1c ldr r8, [sp, #0x4]
 *   @0x1e3a20 str r5, [sp, #0x8]
 *   @0x1e3a24 str r7, [sp, #0x14]
 *   @0x1e3a28 ldr r3, [r8, #0x1c]
 *   @0x1e3a2c ldr r2, [r8, #0x20]
 *   @0x1e3a30 ldr r8, [r8, #0x40]
 *   @0x1e3a34 mul r2, r2, r3
 *   @0x1e3a38 str r8, [sp, #0xc]
 *   @0x1e3a3c str r2, [sp, #0x10]
 *   @0x1e3a40 ldr r8, [sp, #0x8]
 *   @0x1e3a44 movw r3, #0x233
 *   @0x1e3a48 ldr r2, [sp, #0xc]
 *   @0x1e3a4c ldr r1, [sp, #0x10]
 *   @0x1e3a50 lsl r11, r8, #3
 *   @0x1e3a54 add r0, r2, r11
 *   @0x1e3a58 ldr r2, [sp, #0x14]
 *   @0x1e3a5c add r0, r0, #4
 *   @0x1e3a60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e3a64 ldr r8, [sp, #0x4]
 *   @0x1e3a68 ldr r6, [r8, #0x1c]
 *   @0x1e3a6c ldr r9, [r8, #0x20]
 *   @0x1e3a70 ldr r2, [r8, #0x40]
 *   @0x1e3a74 adds r10, r6, #7
 *   @0x1e3a78 ldr r8, [sp, #0x8]
 *   @0x1e3a7c addmi r10, r6, #14
 *   @0x1e3a80 mul r3, r9, r6
 *   @0x1e3a84 cmp r9, #0
 *   @0x1e3a88 str r2, [sp, #0xc]
 *   @0x1e3a8c asr r10, r10, #3
 *   @0x1e3a90 add r11, r2, r11
 *   @0x1e3a94 str r3, [sp, #0x10]
 *   @0x1e3a98 str r3, [r2, r8, lsl #3]
 *   @0x1e3a9c ble 0x1e3b48 <_ZN7CSprite13UnpackWADMaskEi+0x1b4>
 *   @0x1e3aa0 mov r5, #0
 *   @0x1e3aa4 mov r7, r5
 *   @0x1e3aa8 mov r8, r5
 *   @0x1e3aac cmp r6, #0
 *   @0x1e3ab0 ble 0x1e3afc <_ZN7CSprite13UnpackWADMaskEi+0x168>
 *   @0x1e3ab4 ldr r2, [r11, #0x4]
 *   @0x1e3ab8 mov r1, r8
 *   @0x1e3abc mov r3, #128
 *   @0x1e3ac0 add r12, r2, r6
 *   @0x1e3ac4 add r2, r2, r5
 *   @0x1e3ac8 add r12, r12, r5
 *   @0x1e3acc b 0x1e3adc <_ZN7CSprite13UnpackWADMaskEi+0x148>
 *   @0x1e3ad0 cmp r3, #0
 *   @0x1e3ad4 addeq r1, r1, #1
 *   @0x1e3ad8 moveq r3, #128
 *   @0x1e3adc ldrb r0, [r4, r1]
 *   @0x1e3ae0 tst r3, r0
 *   @0x1e3ae4 lsr r3, r3, #1
 *   @0x1e3ae8 moveq r0, #0
 *   @0x1e3aec movne r0, #1
 *   @0x1e3af0 strb r0, [r2], #1
 *   @0x1e3af4 cmp r2, r12
 *   @0x1e3af8 bne 0x1e3ad0 <_ZN7CSprite13UnpackWADMaskEi+0x13c>
 *   @0x1e3afc add r7, r7, #1
 *   @0x1e3b00 add r8, r8, r10
 *   @0x1e3b04 cmp r7, r9
 *   @0x1e3b08 add r5, r5, r6
 *   @0x1e3b0c bne 0x1e3aac <_ZN7CSprite13UnpackWADMaskEi+0x118>
 *   @0x1e3b10 mul r7, r10, r7
 *   @0x1e3b14 ldr r8, [sp, #0x4]
 *   @0x1e3b18 add r4, r4, r7
 *   @0x1e3b1c ldr r3, [r8, #0x64]
 *   @0x1e3b20 ldr r8, [sp, #0x8]
 *   @0x1e3b24 add r8, r8, #1
 *   @0x1e3b28 str r8, [sp, #0x8]
 *   @0x1e3b2c cmp r8, r3
 *   @0x1e3b30 blt 0x1e3a40 <_ZN7CSprite13UnpackWADMaskEi+0xac>
 *   @0x1e3b34 ldr r8, [sp, #0x4]
 *   @0x1e3b38 mov r3, #1
 *   @0x1e3b3c strb r3, [r8, #0x31]
 *   @0x1e3b40 add sp, sp, #28
 *   @0x1e3b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3b48 mov r7, #0
 *   @0x1e3b4c b 0x1e3b14 <_ZN7CSprite13UnpackWADMaskEi+0x180>
 *   @0x1e3b50 eoreq sp, r0, r12, ror #7
 *   @0x1e3b54 andseq lr, r6, r0, asr #20
 *
 * ══ §28/69 NativeErrorCall  0x243de0  size 452  113 条（0x243de0..0x243fa4）
 * @func 0x243de0 0x243fa4  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×3 / YYObjectBase::Add(char const*, char const*, int)×3 / YYObjectBase::InternalGetYYVar(int)×3 / NativeErrorCall(char const*, YYObjectBase*, RValue&, CInstance*, CInstance*, int, RValue*)+0x44 / YYGetString(RValue const*, int) / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / vmGetCallStack() / YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x4×3 / 0x18×2 / 0x28×2 / 0x8×2 / 0x194×1 / 0x34×1 / 0x30×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243de0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x243de4 sub sp, sp, #12
 *   @0x243de8 ldr r10, [pc, #0x194]
 *   @0x243dec mov r8, r0
 *   @0x243df0 ldr r4, [sp, #0x34]
 *   @0x243df4 mov r5, r1
 *   @0x243df8 mov r6, r2
 *   @0x243dfc add r10, pc, r10
 *   @0x243e00 cmp r4, #0
 *   @0x243e04 mov r11, r3
 *   @0x243e08 ldr r9, [sp, #0x30]
 *   @0x243e0c ldr r7, [sp, #0x38]
 *   @0x243e10 ble 0x243e24 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x44>
 *   @0x243e14 mov r0, r7
 *   @0x243e18 mov r1, #0
 *   @0x243e1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x243e20 mov r10, r0
 *   @0x243e24 mov r3, r4
 *   @0x243e28 mov r2, r9
 *   @0x243e2c mov r1, r11
 *   @0x243e30 mov r0, r6
 *   @0x243e34 str r7, [sp]
 *   @0x243e38 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x243e3c ldr r4, [r6]
 *   @0x243e40 mov r1, r5
 *   @0x243e44 str r5, [r4, #0x18]
 *   @0x243e48 mov r0, r4
 *   @0x243e4c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x243e50 ldr r12, [r4, #0x28]
 *   @0x243e54 ldr r3, [pc, #0x12c]
 *   @0x243e58 mov r2, r10
 *   @0x243e5c ldr r1, [pc, #0x128]
 *   @0x243e60 orr r12, r12, #1
 *   @0x243e64 add r3, pc, r3
 *   @0x243e68 str r12, [r4, #0x28]
 *   @0x243e6c mov r0, r4
 *   @0x243e70 add r1, pc, r1
 *   @0x243e74 str r3, [r4, #0x40]
 *   @0x243e78 mov r3, #0
 *   @0x243e7c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x243e80 ldr r1, [pc, #0x108]
 *   @0x243e84 mov r2, r8
 *   @0x243e88 mov r3, #0
 *   @0x243e8c add r1, pc, r1
 *   @0x243e90 mov r0, r4
 *   @0x243e94 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x243e98 bl 0xdb934 <_Z14vmGetCallStackv>
 *   @0x243e9c ldr r1, [pc, #0xf0]
 *   @0x243ea0 mov r3, #0
 *   @0x243ea4 add r1, pc, r1
 *   @0x243ea8 mov r2, r0
 *   @0x243eac mov r0, r4
 *   @0x243eb0 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x243eb4 ldr r3, [pc, #0xdc]
 *   @0x243eb8 mvn r1, #-16777216
 *   @0x243ebc mov r2, #0
 *   @0x243ec0 ldr r3, [pc, r3]
 *   @0x243ec4 ldr r0, [r3]
 *   @0x243ec8 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x243ecc ldr r1, [pc, #0xc8]
 *   @0x243ed0 ldr r2, [r6]
 *   @0x243ed4 mov r3, #6
 *   @0x243ed8 add r1, pc, r1
 *   @0x243edc mov r5, r0
 *   @0x243ee0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243ee4 ldr r3, [pc, #0xb4]
 *   @0x243ee8 mov r0, r5
 *   @0x243eec ldr r3, [pc, r3]
 *   @0x243ef0 ldr r1, [r3]
 *   @0x243ef4 str r1, [r5, #0x18]
 *   @0x243ef8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x243efc ldr r1, [r4, #0x4]
 *   @0x243f00 cmp r1, #0
 *   @0x243f04 beq 0x243f3c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x15c>
 *   @0x243f08 str r5, [r1]
 *   @0x243f0c mov r0, r4
 *   @0x243f10 mov r1, r5
 *   @0x243f14 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x243f18 ldr r1, [r4, #0x4]
 *   @0x243f1c cmp r1, #0
 *   @0x243f20 movne r3, #6
 *   @0x243f24 strne r3, [r1, #0xc]
 *   @0x243f28 beq 0x243f4c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x16c>
 *   @0x243f2c mov r3, #6
 *   @0x243f30 str r3, [r1, #0x8]
 *   @0x243f34 add sp, sp, #12
 *   @0x243f38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x243f3c mov r0, r4
 *   @0x243f40 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243f44 mov r1, r0
 *   @0x243f48 b 0x243f08 <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x128>
 *   @0x243f4c mov r0, r4
 *   @0x243f50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243f54 ldr r1, [r4, #0x4]
 *   @0x243f58 mov r3, #6
 *   @0x243f5c cmp r1, #0
 *   @0x243f60 str r3, [r0, #0xc]
 *   @0x243f64 bne 0x243f2c <_Z15NativeErrorCallPKcP12YYObjectBaseR6RValueP9CInstanceS6_iPS3_+0x14c>
 *   @0x243f68 mov r0, r4
 *   @0x243f6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243f70 mov r3, #6
 *   @0x243f74 mov r1, r0
 *   @0x243f78 str r3, [r1, #0x8]
 *   @0x243f7c add sp, sp, #12
 *   @0x243f80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x243f84 andeq r10, lr, r10, lsr sp
 *   @0x243f88 andseq r1, r1, r0, asr #21
 *   @0x243f8c andseq r5, r0, r4, lsl r9
 *   @0x243f90 andeq r12, lr, r12, ror r9
 *   @0x243f94 andseq r1, r1, r8, lsl #21
 *   @0x243f98 andseq r9, r10, r4, asr lr
 *   @0x243f9c andseq r1, r1, r12, asr #12
 *   @0x243fa0 ldrheq r9, [r10], -r4
 *
 * ══ §29/69 _pcre_is_newline  0x25f9fc  size 452  113 条（0x25f9fc..0x25fbc0）
 * @func 0x25f9fc 0x25fbd0  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _pcre_is_newline+0x58×2 / _pcre_is_newline+0x98 / _pcre_is_newline+0xa8
 * 字段偏移 top8: 0x1×6 / 0x2×4 / 0x3×3 / 0x4×2 / 0x14×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f9fc push {r4, r5, r6, r7, r8}
 *   @0x25fa00 ldr r4, [sp, #0x14]
 *   @0x25fa04 ldrb r12, [r0]
 *   @0x25fa08 cmp r4, #0
 *   @0x25fa0c beq 0x25fa18 <_pcre_is_newline+0x1c>
 *   @0x25fa10 cmp r12, #191
 *   @0x25fa14 bhi 0x25fa60 <_pcre_is_newline+0x64>
 *   @0x25fa18 cmp r1, #2
 *   @0x25fa1c beq 0x25faac <_pcre_is_newline+0xb0>
 *   @0x25fa20 cmp r12, #13
 *   @0x25fa24 beq 0x25fabc <_pcre_is_newline+0xc0>
 *   @0x25fa28 bls 0x25fa94 <_pcre_is_newline+0x98>
 *   @0x25fa2c cmp r12, #133
 *   @0x25fa30 beq 0x25fb00 <_pcre_is_newline+0x104>
 *   @0x25fa34 blo 0x25fa54 <_pcre_is_newline+0x58>
 *   @0x25fa38 sub r12, r12, #8192
 *   @0x25fa3c sub r12, r12, #40
 *   @0x25fa40 cmp r12, #1
 *   @0x25fa44 movls r2, #3
 *   @0x25fa48 movls r0, #1
 *   @0x25fa4c strls r2, [r3]
 *   @0x25fa50 bls 0x25faa4 <_pcre_is_newline+0xa8>
 *   @0x25fa54 mov r0, #0
 *   @0x25fa58 pop {r4, r5, r6, r7, r8}
 *   @0x25fa5c bx lr
 *   @0x25fa60 tst r12, #32
 *   @0x25fa64 beq 0x25faec <_pcre_is_newline+0xf0>
 *   @0x25fa68 tst r12, #16
 *   @0x25fa6c bne 0x25fb1c <_pcre_is_newline+0x120>
 *   @0x25fa70 lsl r12, r12, #12
 *   @0x25fa74 ldrb r6, [r0, #0x2]
 *   @0x25fa78 ldrb r5, [r0, #0x1]
 *   @0x25fa7c uxth r12, r12
 *   @0x25fa80 and r6, r6, #63
 *   @0x25fa84 and r5, r5, #63
 *   @0x25fa88 orr r12, r12, r6
 *   @0x25fa8c orr r12, r12, r5, lsl #6
 *   @0x25fa90 b 0x25fa18 <_pcre_is_newline+0x1c>
 *   @0x25fa94 cmp r12, #10
 *   @0x25fa98 blo 0x25fa54 <_pcre_is_newline+0x58>
 *   @0x25fa9c mov r0, #1
 *   @0x25faa0 str r0, [r3]
 *   @0x25faa4 pop {r4, r5, r6, r7, r8}
 *   @0x25faa8 bx lr
 *   @0x25faac cmp r12, #10
 *   @0x25fab0 beq 0x25fa9c <_pcre_is_newline+0xa0>
 *   @0x25fab4 cmp r12, #13
 *   @0x25fab8 bne 0x25fa54 <_pcre_is_newline+0x58>
 *   @0x25fabc sub r2, r2, #1
 *   @0x25fac0 cmp r0, r2
 *   @0x25fac4 movhs r2, #1
 *   @0x25fac8 bhs 0x25fadc <_pcre_is_newline+0xe0>
 *   @0x25facc ldrb r2, [r0, #0x1]
 *   @0x25fad0 cmp r2, #10
 *   @0x25fad4 moveq r2, #2
 *   @0x25fad8 movne r2, #1
 *   @0x25fadc mov r0, #1
 *   @0x25fae0 str r2, [r3]
 *   @0x25fae4 pop {r4, r5, r6, r7, r8}
 *   @0x25fae8 bx lr
 *   @0x25faec ldrb r5, [r0, #0x1]
 *   @0x25faf0 and r12, r12, #31
 *   @0x25faf4 and r5, r5, #63
 *   @0x25faf8 orr r12, r5, r12, lsl #6
 *   @0x25fafc b 0x25fa18 <_pcre_is_newline+0x1c>
 *   @0x25fb00 cmp r4, #0
 *   @0x25fb04 mov r0, #1
 *   @0x25fb08 moveq r4, #1
 *   @0x25fb0c movne r4, #2
 *   @0x25fb10 str r4, [r3]
 *   @0x25fb14 pop {r4, r5, r6, r7, r8}
 *   @0x25fb18 bx lr
 *   @0x25fb1c tst r12, #8
 *   @0x25fb20 beq 0x25fb64 <_pcre_is_newline+0x168>
 *   @0x25fb24 tst r12, #4
 *   @0x25fb28 bne 0x25fb90 <_pcre_is_newline+0x194>
 *   @0x25fb2c ldrb r8, [r0, #0x4]
 *   @0x25fb30 and r12, r12, #3
 *   @0x25fb34 ldrb r7, [r0, #0x1]
 *   @0x25fb38 and r8, r8, #63
 *   @0x25fb3c ldrb r6, [r0, #0x2]
 *   @0x25fb40 ldrb r5, [r0, #0x3]
 *   @0x25fb44 and r7, r7, #63
 *   @0x25fb48 orr r12, r8, r12, lsl #24
 *   @0x25fb4c and r6, r6, #63
 *   @0x25fb50 orr r12, r12, r7, lsl #18
 *   @0x25fb54 and r5, r5, #63
 *   @0x25fb58 orr r12, r12, r6, lsl #12
 *   @0x25fb5c orr r12, r12, r5, lsl #6
 *   @0x25fb60 b 0x25fa18 <_pcre_is_newline+0x1c>
 *   @0x25fb64 ldrb r7, [r0, #0x3]
 *   @0x25fb68 and r12, r12, #7
 *   @0x25fb6c ldrb r6, [r0, #0x1]
 *   @0x25fb70 ldrb r5, [r0, #0x2]
 *   @0x25fb74 and r7, r7, #63
 *   @0x25fb78 and r6, r6, #63
 *   @0x25fb7c orr r12, r7, r12, lsl #18
 *   @0x25fb80 and r5, r5, #63
 *   @0x25fb84 orr r12, r12, r6, lsl #12
 *   @0x25fb88 orr r12, r12, r5, lsl #6
 *   @0x25fb8c b 0x25fa18 <_pcre_is_newline+0x1c>
 *   @0x25fb90 ldrb r5, [r0, #0x5]
 *   @0x25fb94 and r12, r12, #1
 *   @0x25fb98 ldrb r8, [r0, #0x1]
 *   @0x25fb9c and r5, r5, #63
 *   @0x25fba0 ldrb r7, [r0, #0x2]
 *   @0x25fba4 and r8, r8, #63
 *   @0x25fba8 orr r12, r5, r12, lsl #30
 *   @0x25fbac ldrb r6, [r0, #0x3]
 *   @0x25fbb0 and r7, r7, #63
 *   @0x25fbb4 ldrb r5, [r0, #0x4]
 *   @0x25fbb8 orr r12, r12, r8, lsl #24
 *   @0x25fbbc b 0x25fb4c <_pcre_is_newline+0x150>
 *
 * ══ §30/69 ogg_sync_pageseek  0x234c90  size 444  111 条（0x234c90..0x234e4c）
 * @func 0x234c90 0x234e4c  size 444  111 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_pageseek+0x4c×2 / 0xb6c40×2 / ogg_sync_check / ogg_page_checksum_set / 0xb66a0
 * 字段偏移 top8: 0x18×8 / 0x14×7 / 0xc×5 / 0x8×2 / 0x1a×2 / 0x16×2 / 0x10×2 / 0x150×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234c90 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x234c94 sub sp, sp, #28
 *   @0x234c98 mov r4, r0
 *   @0x234c9c mov r8, r1
 *   @0x234ca0 ldr r5, [r0]
 *   @0x234ca4 ldr r6, [r0, #0xc]
 *   @0x234ca8 ldr r7, [r0, #0x8]
 *   @0x234cac bl 0x234b80 <ogg_sync_check>
 *   @0x234cb0 cmp r0, #0
 *   @0x234cb4 bne 0x234cdc <ogg_sync_pageseek+0x4c>
 *   @0x234cb8 ldr r0, [r4, #0x14]
 *   @0x234cbc add r5, r5, r6
 *   @0x234cc0 rsb r6, r6, r7
 *   @0x234cc4 cmp r0, #0
 *   @0x234cc8 beq 0x234ce8 <ogg_sync_pageseek+0x58>
 *   @0x234ccc ldr r3, [r4, #0x18]
 *   @0x234cd0 add r3, r0, r3
 *   @0x234cd4 cmp r6, r3
 *   @0x234cd8 bge 0x234d54 <ogg_sync_pageseek+0xc4>
 *   @0x234cdc mov r0, #0
 *   @0x234ce0 add sp, sp, #28
 *   @0x234ce4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x234ce8 cmp r6, #26
 *   @0x234cec ble 0x234cdc <ogg_sync_pageseek+0x4c>
 *   @0x234cf0 ldr r1, [pc, #0x150]
 *   @0x234cf4 mov r0, r5
 *   @0x234cf8 mov r2, #4
 *   @0x234cfc add r1, pc, r1
 *   @0x234d00 bl 0xb6c40 <memcmp@plt>
 *   @0x234d04 cmp r0, #0
 *   @0x234d08 bne 0x234e08 <ogg_sync_pageseek+0x178>
 *   @0x234d0c ldrb r3, [r5, #0x1a]
 *   @0x234d10 add r12, r3, #27
 *   @0x234d14 cmp r6, r12
 *   @0x234d18 blt 0x234cdc <ogg_sync_pageseek+0x4c>
 *   @0x234d1c cmp r3, #0
 *   @0x234d20 ldr r3, [r4, #0x18]
 *   @0x234d24 addne r2, r5, #26
 *   @0x234d28 beq 0x234d48 <ogg_sync_pageseek+0xb8>
 *   @0x234d2c ldrb r1, [r2, #0x1]!
 *   @0x234d30 add r0, r0, #1
 *   @0x234d34 add r3, r3, r1
 *   @0x234d38 str r3, [r4, #0x18]
 *   @0x234d3c ldrb r1, [r5, #0x1a]
 *   @0x234d40 cmp r1, r0
 *   @0x234d44 bgt 0x234d2c <ogg_sync_pageseek+0x9c>
 *   @0x234d48 mov r0, r12
 *   @0x234d4c str r12, [r4, #0x14]
 *   @0x234d50 b 0x234cd0 <ogg_sync_pageseek+0x40>
 *   @0x234d54 mov r7, r5
 *   @0x234d58 mov r3, #0
 *   @0x234d5c ldr r0, [r7, #0x16]!
 *   @0x234d60 add r9, sp, #4
 *   @0x234d64 strb r3, [r5, #0x16]
 *   @0x234d68 strb r3, [r5, #0x17]
 *   @0x234d6c strb r3, [r5, #0x18]
 *   @0x234d70 strb r3, [r5, #0x19]
 *   @0x234d74 ldr r3, [r4, #0x14]
 *   @0x234d78 ldr r2, [r4, #0x18]
 *   @0x234d7c str r0, [sp, #0x4]
 *   @0x234d80 add r0, sp, #8
 *   @0x234d84 add r1, r5, r3
 *   @0x234d88 str r3, [sp, #0xc]
 *   @0x234d8c str r1, [sp, #0x10]
 *   @0x234d90 str r2, [sp, #0x14]
 *   @0x234d94 str r5, [sp, #0x8]
 *   @0x234d98 bl 0x234354 <ogg_page_checksum_set>
 *   @0x234d9c mov r0, r9
 *   @0x234da0 mov r1, r7
 *   @0x234da4 mov r2, #4
 *   @0x234da8 bl 0xb6c40 <memcmp@plt>
 *   @0x234dac cmp r0, #0
 *   @0x234db0 ldrne r0, [r9]
 *   @0x234db4 strne r0, [r5, #0x16]
 *   @0x234db8 bne 0x234e08 <ogg_sync_pageseek+0x178>
 *   @0x234dbc ldr r0, [r4, #0x18]
 *   @0x234dc0 cmp r8, #0
 *   @0x234dc4 ldr r3, [r4, #0x14]
 *   @0x234dc8 ldr r2, [r4, #0xc]
 *   @0x234dcc ldr r1, [r4]
 *   @0x234dd0 strne r0, [r8, #0xc]
 *   @0x234dd4 add r0, r3, r0
 *   @0x234dd8 add r1, r1, r2
 *   @0x234ddc strne r3, [r8, #0x4]
 *   @0x234de0 strne r1, [r8]
 *   @0x234de4 add r2, r2, r0
 *   @0x234de8 addne r1, r1, r3
 *   @0x234dec mov r3, #0
 *   @0x234df0 strne r1, [r8, #0x8]
 *   @0x234df4 str r3, [r4, #0x10]
 *   @0x234df8 str r2, [r4, #0xc]
 *   @0x234dfc str r3, [r4, #0x14]
 *   @0x234e00 str r3, [r4, #0x18]
 *   @0x234e04 b 0x234ce0 <ogg_sync_pageseek+0x50>
 *   @0x234e08 mov r3, #0
 *   @0x234e0c sub r2, r6, #1
 *   @0x234e10 str r3, [r4, #0x14]
 *   @0x234e14 add r0, r5, #1
 *   @0x234e18 str r3, [r4, #0x18]
 *   @0x234e1c mov r1, #79
 *   @0x234e20 bl 0xb66a0 <memchr@plt>
 *   @0x234e24 ldr r2, [r4]
 *   @0x234e28 subs r3, r0, #0
 *   @0x234e2c ldreq r3, [r4, #0x8]
 *   @0x234e30 addeq r3, r2, r3
 *   @0x234e34 rsb r0, r3, r5
 *   @0x234e38 rsb r3, r2, r3
 *   @0x234e3c str r3, [r4, #0xc]
 *   @0x234e40 add sp, sp, #28
 *   @0x234e44 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x234e48 andseq r0, r2, r0, ror #7
 *
 * ══ §31/69 DrawLayerOldTilemapElement  0x1b1784  size 440  110 条（0x1b1784..0x1b193c）
 * @func 0x1b1784 0x1b193c  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DrawLayerOldTilemapElement(tagYYRECT*, CLayer*, CLayerOldTilemapElement*)+0x190×2 / DrawLayerOldTilemapElement(tagYYRECT*, CLayer*, CLayerOldTilemapElement*)+0x1a0 / Sprite_Exists(int) / Sprite_Data(int) / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x-2c×2 / 0x24×1 / 0x700×1 / 0x-28×1 / 0x-24×1 / 0x-10×1 / 0x10×1 / 0x-c×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b1784 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b1788 vpush {d8, d9}
 *   @0x1b178c mov r8, r0
 *   @0x1b1790 ldr r7, [r2, #0x24]
 *   @0x1b1794 sub sp, sp, #36
 *   @0x1b1798 mov r9, r1
 *   @0x1b179c cmp r7, #0
 *   @0x1b17a0 beq 0x1b1930 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x1ac>
 *   @0x1b17a4 ldr r6, [r7, #0x700]
 *   @0x1b17a8 cmp r6, #0
 *   @0x1b17ac addgt r4, r7, #52
 *   @0x1b17b0 movgt r5, #0
 *   @0x1b17b4 ble 0x1b1924 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x1a0>
 *   @0x1b17b8 ldrb r3, [r4]
 *   @0x1b17bc cmp r3, #0
 *   @0x1b17c0 beq 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b17c4 vldr s10, [r4, #-32]
 *   @0x1b17c8 vcvt.f32.s32 s11, s10
 *   @0x1b17cc vldr s14, [r4, #-52]
 *   @0x1b17d0 vldr s12, [r4, #-16]
 *   @0x1b17d4 vldr s15, [r4, #-48]
 *   @0x1b17d8 vldr s13, [r4, #-12]
 *   @0x1b17dc ldr r0, [r4, #-0x2c]
 *   @0x1b17e0 vmov.f32 s16, s14
 *   @0x1b17e4 vmla.f32 s16, s11, s12
 *   @0x1b17e8 vldr s11, [r4, #-28]
 *   @0x1b17ec vcvt.f32.s32 s12, s11
 *   @0x1b17f0 vmov.f32 s17, s15
 *   @0x1b17f4 vmla.f32 s17, s12, s13
 *   @0x1b17f8 vcmpe.f32 s14, s16
 *   @0x1b17fc vmrs APSR_nzcv, fpscr
 *   @0x1b1800 vcmp.f32 s14, s16
 *   @0x1b1804 vmovpl.f32 s18, s16
 *   @0x1b1808 vmovmi.f32 s18, s14
 *   @0x1b180c vmrs APSR_nzcv, fpscr
 *   @0x1b1810 vcmpe.f32 s15, s17
 *   @0x1b1814 vmovgt.f32 s16, s14
 *   @0x1b1818 vmrs APSR_nzcv, fpscr
 *   @0x1b181c vcmp.f32 s15, s17
 *   @0x1b1820 vmovpl.f32 s19, s17
 *   @0x1b1824 vmovmi.f32 s19, s15
 *   @0x1b1828 vmrs APSR_nzcv, fpscr
 *   @0x1b182c vmovgt.f32 s17, s15
 *   @0x1b1830 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1b1834 cmp r0, #0
 *   @0x1b1838 beq 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b183c vldr s12, [r8, #8]
 *   @0x1b1840 vcvt.f32.s32 s15, s12
 *   @0x1b1844 vcmpe.f32 s18, s15
 *   @0x1b1848 vmrs APSR_nzcv, fpscr
 *   @0x1b184c bhi 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b1850 vldr s13, [r8, #12]
 *   @0x1b1854 vcvt.f32.s32 s15, s13
 *   @0x1b1858 vcmpe.f32 s19, s15
 *   @0x1b185c vmrs APSR_nzcv, fpscr
 *   @0x1b1860 bhi 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b1864 vldr s14, [r8]
 *   @0x1b1868 vcvt.f32.s32 s15, s14
 *   @0x1b186c vcmpe.f32 s16, s15
 *   @0x1b1870 vmrs APSR_nzcv, fpscr
 *   @0x1b1874 blt 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b1878 vldr s10, [r8, #4]
 *   @0x1b187c vcvt.f32.s32 s15, s10
 *   @0x1b1880 vcmpe.f32 s17, s15
 *   @0x1b1884 vmrs APSR_nzcv, fpscr
 *   @0x1b1888 blt 0x1b1914 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x190>
 *   @0x1b188c ldr r0, [r4, #-0x2c]
 *   @0x1b1890 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b1894 vldr s11, [r4, #-32]
 *   @0x1b1898 vcvt.f32.s32 s13, s11
 *   @0x1b189c ldr r2, [r4, #-0x28]
 *   @0x1b18a0 ldr r3, [r4, #-0x24]
 *   @0x1b18a4 vldr s14, [r9, #8]
 *   @0x1b18a8 vldr s15, [r9, #12]
 *   @0x1b18ac mov r1, #0
 *   @0x1b18b0 vmov s12, r2
 *   @0x1b18b4 vmov s11, r3
 *   @0x1b18b8 vstr s13, [sp]
 *   @0x1b18bc vldr s10, [r4, #-28]
 *   @0x1b18c0 vcvt.f32.s32 s13, s10
 *   @0x1b18c4 vstr s13, [sp, #4]
 *   @0x1b18c8 vldr s13, [r4, #-52]
 *   @0x1b18cc vadd.f32 s14, s13, s14
 *   @0x1b18d0 vstr s14, [sp, #8]
 *   @0x1b18d4 vldr s14, [r4, #-48]
 *   @0x1b18d8 vadd.f32 s15, s14, s15
 *   @0x1b18dc vstr s15, [sp, #12]
 *   @0x1b18e0 ldr r12, [r4, #-0x10]
 *   @0x1b18e4 vcvt.f32.s32 s12, s12
 *   @0x1b18e8 str r12, [sp, #0x10]
 *   @0x1b18ec ldr r12, [r4, #-0xc]
 *   @0x1b18f0 str r12, [sp, #0x14]
 *   @0x1b18f4 vcvt.f32.s32 s11, s11
 *   @0x1b18f8 ldr r12, [r4, #-0x8]
 *   @0x1b18fc vmov r2, s12
 *   @0x1b1900 str r12, [sp, #0x18]
 *   @0x1b1904 ldr r12, [r4, #-0x4]
 *   @0x1b1908 vmov r3, s11
 *   @0x1b190c str r12, [sp, #0x1c]
 *   @0x1b1910 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x1b1914 add r5, r5, #1
 *   @0x1b1918 add r4, r4, #56
 *   @0x1b191c cmp r5, r6
 *   @0x1b1920 bne 0x1b17b8 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x34>
 *   @0x1b1924 ldr r7, [r7, #0x704]
 *   @0x1b1928 cmp r7, #0
 *   @0x1b192c bne 0x1b17a4 <_Z26DrawLayerOldTilemapElementP9tagYYRECTP6CLayerP23CLayerOldTilemapElement+0x20>
 *   @0x1b1930 add sp, sp, #36
 *   @0x1b1934 vpop {d8, d9}
 *   @0x1b1938 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §32/69 Variable_Scope_SetVar  0x1f35e0  size 440  110 条（0x1f35e0..0x1f3798）
 * @func 0x1f35e0 0x1f3798  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / Code_Variable_Find_Name(char const*, int, int) / PushContextStack(YYObjectBase*) / SET_RValue(RValue*, RValue*, int) / PopContextStack()
 * 字段偏移 top8: 0xc×5 / 0x4×5 / 0x24×2 / 0x1a4×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f35e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f35e4 mov r11, r0
 *   @0x1f35e8 ldr r10, [pc, #0x1a4]
 *   @0x1f35ec sub sp, sp, #12
 *   @0x1f35f0 mov r9, r1
 *   @0x1f35f4 mov r8, r2
 *   @0x1f35f8 ldr r10, [pc, r10]
 *   @0x1f35fc ldr r4, [r10]
 *   @0x1f3600 cmp r4, #0
 *   @0x1f3604 beq 0x1f3754 <_Z21Variable_Scope_SetVariiP6RValue+0x174>
 *   @0x1f3608 sub r7, r0, #99328
 *   @0x1f360c mov r2, #0
 *   @0x1f3610 sub r7, r7, #672
 *   @0x1f3614 mvn r6, #-16777216
 *   @0x1f3618 lsl r5, r7, #4
 *   @0x1f361c b 0x1f362c <_Z21Variable_Scope_SetVariiP6RValue+0x4c>
 *   @0x1f3620 ldr r4, [r4, #0xc]
 *   @0x1f3624 cmp r4, #0
 *   @0x1f3628 beq 0x1f3680 <_Z21Variable_Scope_SetVariiP6RValue+0xa0>
 *   @0x1f362c ldr r3, [r4, #0x24]
 *   @0x1f3630 cmp r3, #0
 *   @0x1f3634 beq 0x1f3658 <_Z21Variable_Scope_SetVariiP6RValue+0x78>
 *   @0x1f3638 ldr r3, [r4, #0x4]
 *   @0x1f363c cmp r3, #0
 *   @0x1f3640 add r0, r3, r5
 *   @0x1f3644 beq 0x1f36bc <_Z21Variable_Scope_SetVariiP6RValue+0xdc>
 *   @0x1f3648 ldr r3, [r0, #0xc]
 *   @0x1f364c bic r3, r3, #-16777216
 *   @0x1f3650 cmp r3, r6
 *   @0x1f3654 bne 0x1f36e0 <_Z21Variable_Scope_SetVariiP6RValue+0x100>
 *   @0x1f3658 cmp r2, #0
 *   @0x1f365c bne 0x1f3620 <_Z21Variable_Scope_SetVariiP6RValue+0x40>
 *   @0x1f3660 mov r0, r2
 *   @0x1f3664 mvn r1, #10
 *   @0x1f3668 mov r2, r11
 *   @0x1f366c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x1f3670 ldr r4, [r4, #0xc]
 *   @0x1f3674 cmp r4, #0
 *   @0x1f3678 mov r2, r0
 *   @0x1f367c bne 0x1f362c <_Z21Variable_Scope_SetVariiP6RValue+0x4c>
 *   @0x1f3680 ldr r0, [r10]
 *   @0x1f3684 ldr r3, [r0, #0x24]
 *   @0x1f3688 cmp r3, #0
 *   @0x1f368c beq 0x1f36b4 <_Z21Variable_Scope_SetVariiP6RValue+0xd4>
 *   @0x1f3690 ldr r3, [r0, #0x4]
 *   @0x1f3694 sub r1, r11, #99328
 *   @0x1f3698 sub r1, r1, #672
 *   @0x1f369c cmp r3, #0
 *   @0x1f36a0 beq 0x1f3784 <_Z21Variable_Scope_SetVariiP6RValue+0x1a4>
 *   @0x1f36a4 add r5, r3, r1, lsl #4
 *   @0x1f36a8 mov r4, r0
 *   @0x1f36ac cmp r5, #0
 *   @0x1f36b0 bne 0x1f36f8 <_Z21Variable_Scope_SetVariiP6RValue+0x118>
 *   @0x1f36b4 add sp, sp, #12
 *   @0x1f36b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f36bc mov r0, r4
 *   @0x1f36c0 mov r1, r7
 *   @0x1f36c4 str r2, [sp, #0x4]
 *   @0x1f36c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f36cc ldr r2, [sp, #0x4]
 *   @0x1f36d0 ldr r3, [r0, #0xc]
 *   @0x1f36d4 bic r3, r3, #-16777216
 *   @0x1f36d8 cmp r3, r6
 *   @0x1f36dc beq 0x1f3658 <_Z21Variable_Scope_SetVariiP6RValue+0x78>
 *   @0x1f36e0 ldr r3, [r4, #0x4]
 *   @0x1f36e4 cmp r3, #0
 *   @0x1f36e8 beq 0x1f3770 <_Z21Variable_Scope_SetVariiP6RValue+0x190>
 *   @0x1f36ec add r5, r3, r5
 *   @0x1f36f0 cmp r5, #0
 *   @0x1f36f4 beq 0x1f3680 <_Z21Variable_Scope_SetVariiP6RValue+0xa0>
 *   @0x1f36f8 ldr r6, [r5, #0xc]
 *   @0x1f36fc mov r0, r4
 *   @0x1f3700 bic r3, r6, #-16777216
 *   @0x1f3704 cmp r3, #6
 *   @0x1f3708 bne 0x1f371c <_Z21Variable_Scope_SetVariiP6RValue+0x13c>
 *   @0x1f370c ldr r3, [r5]
 *   @0x1f3710 ldr r3, [r3, #0x48]
 *   @0x1f3714 cmp r3, #2
 *   @0x1f3718 beq 0x1f375c <_Z21Variable_Scope_SetVariiP6RValue+0x17c>
 *   @0x1f371c ldr r4, [r5, #0x8]
 *   @0x1f3720 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x1f3724 mov r0, r5
 *   @0x1f3728 mov r1, r8
 *   @0x1f372c mov r2, r9
 *   @0x1f3730 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f3734 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x1f3738 mvn r3, #-16777216
 *   @0x1f373c cmp r6, r3
 *   @0x1f3740 strne r4, [r5, #0x8]
 *   @0x1f3744 moveq r3, #7
 *   @0x1f3748 streq r3, [r5, #0x8]
 *   @0x1f374c add sp, sp, #12
 *   @0x1f3750 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f3754 mov r0, r4
 *   @0x1f3758 b 0x1f3684 <_Z21Variable_Scope_SetVariiP6RValue+0xa4>
 *   @0x1f375c mov r1, r8
 *   @0x1f3760 mov r2, r5
 *   @0x1f3764 add sp, sp, #12
 *   @0x1f3768 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f376c b 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_>
 *   @0x1f3770 mov r1, r7
 *   @0x1f3774 mov r0, r4
 *   @0x1f3778 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f377c mov r5, r0
 *   @0x1f3780 b 0x1f36f0 <_Z21Variable_Scope_SetVariiP6RValue+0x110>
 *   @0x1f3784 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f3788 ldr r4, [r10]
 *   @0x1f378c mov r5, r0
 *   @0x1f3790 b 0x1f36ac <_Z21Variable_Scope_SetVariiP6RValue+0xcc>
 *   @0x1f3794 ldrheq r10, [pc], -r0
 *
 * ══ §33/69 CDS_Map::Delete  0x20b6cc  size 440  110 条（0x20b6cc..0x20b884）
 * @func 0x20b6cc 0x20b884  size 440  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / CalcCRC(char const*, int)×2 / CalcCRC_string(char const*) / operator delete(void*) / MemoryManager::Free(void const*) / CDS_Map::Delete(RValue*)+0x158 / CDS_Map::Delete(RValue*)+0x190 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×4 / 0x8×4 / 0x4×2 / 0x1c×2 / 0x3×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b6cc ldr r3, [r1, #0xc]
 *   @0x20b6d0 push {r4, r5, r6, lr}
 *   @0x20b6d4 bic r3, r3, #-16777216
 *   @0x20b6d8 cmp r3, #6
 *   @0x20b6dc sub sp, sp, #8
 *   @0x20b6e0 ldr r5, [r0]
 *   @0x20b6e4 beq 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190>
 *   @0x20b6e8 bgt 0x20b804 <_ZN7CDS_Map6DeleteEP6RValue+0x138>
 *   @0x20b6ec cmp r3, #4
 *   @0x20b6f0 bgt 0x20b81c <_ZN7CDS_Map6DeleteEP6RValue+0x150>
 *   @0x20b6f4 cmp r3, #2
 *   @0x20b6f8 bge 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190>
 *   @0x20b6fc cmp r3, #1
 *   @0x20b700 bne 0x20b830 <_ZN7CDS_Map6DeleteEP6RValue+0x164>
 *   @0x20b704 ldr r0, [r1]
 *   @0x20b708 cmp r0, #0
 *   @0x20b70c ldrne r0, [r0]
 *   @0x20b710 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x20b714 ldr r1, [r5, #0x4]
 *   @0x20b718 ldr r2, [r5]
 *   @0x20b71c and r1, r0, r1
 *   @0x20b720 ldr r4, [r2, r1, lsl #3]
 *   @0x20b724 add r12, r2, r1, lsl #3
 *   @0x20b728 cmp r4, #0
 *   @0x20b72c bne 0x20b740 <_ZN7CDS_Map6DeleteEP6RValue+0x74>
 *   @0x20b730 b 0x20b7fc <_ZN7CDS_Map6DeleteEP6RValue+0x130>
 *   @0x20b734 ldr r4, [r4, #0x4]
 *   @0x20b738 cmp r4, #0
 *   @0x20b73c beq 0x20b7fc <_ZN7CDS_Map6DeleteEP6RValue+0x130>
 *   @0x20b740 ldr r3, [r4, #0x8]
 *   @0x20b744 cmp r0, r3
 *   @0x20b748 bne 0x20b734 <_ZN7CDS_Map6DeleteEP6RValue+0x68>
 *   @0x20b74c ldr r3, [r4]
 *   @0x20b750 ldr r6, [r4, #0xc]
 *   @0x20b754 cmp r3, #0
 *   @0x20b758 ldrne r2, [r4, #0x4]
 *   @0x20b75c ldreq r0, [r4, #0x4]
 *   @0x20b760 strne r2, [r3, #0x4]
 *   @0x20b764 ldrne r0, [r4, #0x4]
 *   @0x20b768 streq r0, [r2, r1, lsl #3]
 *   @0x20b76c cmp r0, #0
 *   @0x20b770 streq r3, [r12, #0x4]
 *   @0x20b774 strne r3, [r0]
 *   @0x20b778 cmp r6, #0
 *   @0x20b77c beq 0x20b7e8 <_ZN7CDS_Map6DeleteEP6RValue+0x11c>
 *   @0x20b780 ldr r3, [r6, #0xc]
 *   @0x20b784 sub r3, r3, #1
 *   @0x20b788 bic r3, r3, #-16777216
 *   @0x20b78c bic r3, r3, #3
 *   @0x20b790 cmp r3, #0
 *   @0x20b794 beq 0x20b878 <_ZN7CDS_Map6DeleteEP6RValue+0x1ac>
 *   @0x20b798 ldr r1, [r6, #0x1c]
 *   @0x20b79c mov r3, #0
 *   @0x20b7a0 str r3, [r6, #0x8]
 *   @0x20b7a4 mov r2, #5
 *   @0x20b7a8 sub r1, r1, #1
 *   @0x20b7ac str r3, [r6]
 *   @0x20b7b0 bic r3, r1, #-16777216
 *   @0x20b7b4 str r2, [r6, #0xc]
 *   @0x20b7b8 bic r3, r3, #3
 *   @0x20b7bc cmp r3, #0
 *   @0x20b7c0 bne 0x20b7cc <_ZN7CDS_Map6DeleteEP6RValue+0x100>
 *   @0x20b7c4 add r0, r6, #16
 *   @0x20b7c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20b7cc mov r3, #0
 *   @0x20b7d0 mov r2, #5
 *   @0x20b7d4 str r3, [r6, #0x18]
 *   @0x20b7d8 mov r0, r6
 *   @0x20b7dc str r3, [r6, #0x10]
 *   @0x20b7e0 str r2, [r6, #0x1c]
 *   @0x20b7e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20b7e8 mov r0, r4
 *   @0x20b7ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20b7f0 ldr r3, [r5, #0x8]
 *   @0x20b7f4 sub r3, r3, #1
 *   @0x20b7f8 str r3, [r5, #0x8]
 *   @0x20b7fc add sp, sp, #8
 *   @0x20b800 pop {r4, r5, r6, pc}
 *   @0x20b804 cmp r3, #11
 *   @0x20b808 beq 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190>
 *   @0x20b80c ble 0x20b824 <_ZN7CDS_Map6DeleteEP6RValue+0x158>
 *   @0x20b810 mvn r2, #-16777216
 *   @0x20b814 cmp r3, r2
 *   @0x20b818 bne 0x20b830 <_ZN7CDS_Map6DeleteEP6RValue+0x164>
 *   @0x20b81c mov r0, #0
 *   @0x20b820 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48>
 *   @0x20b824 sub r2, r3, #8
 *   @0x20b828 cmp r2, #1
 *   @0x20b82c bls 0x20b85c <_ZN7CDS_Map6DeleteEP6RValue+0x190>
 *   @0x20b830 cmp r3, #0
 *   @0x20b834 bne 0x20b86c <_ZN7CDS_Map6DeleteEP6RValue+0x1a0>
 *   @0x20b838 ldm r1, {r0, r1}
 *   @0x20b83c mov r2, r0
 *   @0x20b840 add r0, sp, #8
 *   @0x20b844 mov r3, r1
 *   @0x20b848 mov r1, #8
 *   @0x20b84c strd r2, r3, [r0, #-8]!
 *   @0x20b850 mov r0, sp
 *   @0x20b854 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20b858 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48>
 *   @0x20b85c mov r0, r1
 *   @0x20b860 mov r1, #8
 *   @0x20b864 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20b868 b 0x20b714 <_ZN7CDS_Map6DeleteEP6RValue+0x48>
 *   @0x20b86c mov r0, r1
 *   @0x20b870 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x20b874 b 0x20b83c <_ZN7CDS_Map6DeleteEP6RValue+0x170>
 *   @0x20b878 mov r0, r6
 *   @0x20b87c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20b880 b 0x20b798 <_ZN7CDS_Map6DeleteEP6RValue+0xcc>
 *
 * ══ §34/69 vorbis_info_clear  0x22ad10  size 436  109 条（0x22ad10..0x22aec4）
 * @func 0x22ad10 0x22aec4  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×3 / vorbis_info_clear+0x48 / vorbis_info_clear+0x90 / vorbis_info_clear+0xdc / vorbis_info_clear+0x128 / vorbis_info_clear+0x17c / vorbis_staticbook_destroy / vorbis_book_clear
 * 字段偏移 top8: 0x8×5 / 0x4×5 / 0x1c×3 / 0x-100×3 / 0x2×3 / 0xc×2 / 0x14×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ad10 push {r4, r5, r6, r7, r8, lr}
 *   @0x22ad14 mov r8, r0
 *   @0x22ad18 ldr r4, [r0, #0x1c]
 *   @0x22ad1c cmp r4, #0
 *   @0x22ad20 beq 0x22aea4 <vorbis_info_clear+0x194>
 *   @0x22ad24 ldr r3, [r4, #0x8]
 *   @0x22ad28 cmp r3, #0
 *   @0x22ad2c addgt r6, r4, #28
 *   @0x22ad30 movgt r5, #0
 *   @0x22ad34 ble 0x22ad58 <vorbis_info_clear+0x48>
 *   @0x22ad38 ldr r0, [r6, #0x4]!
 *   @0x22ad3c add r5, r5, #1
 *   @0x22ad40 cmp r0, #0
 *   @0x22ad44 beq 0x22ad50 <vorbis_info_clear+0x40>
 *   @0x22ad48 bl 0xb655c <free@plt>
 *   @0x22ad4c ldr r3, [r4, #0x8]
 *   @0x22ad50 cmp r3, r5
 *   @0x22ad54 bgt 0x22ad38 <vorbis_info_clear+0x28>
 *   @0x22ad58 ldr r2, [r4, #0xc]
 *   @0x22ad5c cmp r2, #0
 *   @0x22ad60 addgt r6, r4, #540
 *   @0x22ad64 movgt r5, #0
 *   @0x22ad68 ble 0x22ada0 <vorbis_info_clear+0x90>
 *   @0x22ad6c ldr r0, [r6, #0x4]!
 *   @0x22ad70 add r5, r5, #1
 *   @0x22ad74 ldr r3, [pc, #0x13c]
 *   @0x22ad78 cmp r0, #0
 *   @0x22ad7c beq 0x22ad98 <vorbis_info_clear+0x88>
 *   @0x22ad80 ldr r2, [r6, #-0x100]
 *   @0x22ad84 ldr r3, [pc, r3]
 *   @0x22ad88 ldr r3, [r3, r2, lsl #2]
 *   @0x22ad8c ldr r3, [r3, #0x8]
 *   @0x22ad90 blx r3
 *   @0x22ad94 ldr r2, [r4, #0xc]
 *   @0x22ad98 cmp r2, r5
 *   @0x22ad9c bgt 0x22ad6c <vorbis_info_clear+0x5c>
 *   @0x22ada0 ldr r2, [r4, #0x14]
 *   @0x22ada4 cmp r2, #0
 *   @0x22ada8 addgt r6, r4, #1296
 *   @0x22adac movgt r5, #0
 *   @0x22adb0 addgt r6, r6, #12
 *   @0x22adb4 ble 0x22adec <vorbis_info_clear+0xdc>
 *   @0x22adb8 ldr r0, [r6, #0x4]!
 *   @0x22adbc add r5, r5, #1
 *   @0x22adc0 ldr r3, [pc, #0xf4]
 *   @0x22adc4 cmp r0, #0
 *   @0x22adc8 beq 0x22ade4 <vorbis_info_clear+0xd4>
 *   @0x22adcc ldr r2, [r6, #-0x100]
 *   @0x22add0 ldr r3, [pc, r3]
 *   @0x22add4 ldr r3, [r3, r2, lsl #2]
 *   @0x22add8 ldr r3, [r3, #0x8]
 *   @0x22addc blx r3
 *   @0x22ade0 ldr r2, [r4, #0x14]
 *   @0x22ade4 cmp r2, r5
 *   @0x22ade8 bgt 0x22adb8 <vorbis_info_clear+0xa8>
 *   @0x22adec ldr r2, [r4, #0x18]
 *   @0x22adf0 cmp r2, #0
 *   @0x22adf4 addgt r6, r4, #1808
 *   @0x22adf8 movgt r5, #0
 *   @0x22adfc addgt r6, r6, #12
 *   @0x22ae00 ble 0x22ae38 <vorbis_info_clear+0x128>
 *   @0x22ae04 ldr r0, [r6, #0x4]!
 *   @0x22ae08 add r5, r5, #1
 *   @0x22ae0c ldr r3, [pc, #0xac]
 *   @0x22ae10 cmp r0, #0
 *   @0x22ae14 beq 0x22ae30 <vorbis_info_clear+0x120>
 *   @0x22ae18 ldr r2, [r6, #-0x100]
 *   @0x22ae1c ldr r3, [pc, r3]
 *   @0x22ae20 ldr r3, [r3, r2, lsl #2]
 *   @0x22ae24 ldr r3, [r3, #0x8]
 *   @0x22ae28 blx r3
 *   @0x22ae2c ldr r2, [r4, #0x18]
 *   @0x22ae30 cmp r2, r5
 *   @0x22ae34 bgt 0x22ae04 <vorbis_info_clear+0xf4>
 *   @0x22ae38 ldr r3, [r4, #0x1c]
 *   @0x22ae3c cmp r3, #0
 *   @0x22ae40 addgt r7, r4, #2064
 *   @0x22ae44 movgt r5, #0
 *   @0x22ae48 addgt r7, r7, #12
 *   @0x22ae4c movgt r6, r5
 *   @0x22ae50 ble 0x22ae8c <vorbis_info_clear+0x17c>
 *   @0x22ae54 ldr r0, [r7, #0x4]!
 *   @0x22ae58 add r6, r6, #1
 *   @0x22ae5c cmp r0, #0
 *   @0x22ae60 beq 0x22ae68 <vorbis_info_clear+0x158>
 *   @0x22ae64 bl 0x22f554 <vorbis_staticbook_destroy>
 *   @0x22ae68 ldr r3, [r4, #0xc20]
 *   @0x22ae6c cmp r3, #0
 *   @0x22ae70 add r0, r3, r5
 *   @0x22ae74 add r5, r5, #52
 *   @0x22ae78 beq 0x22ae80 <vorbis_info_clear+0x170>
 *   @0x22ae7c bl 0x22f598 <vorbis_book_clear>
 *   @0x22ae80 ldr r3, [r4, #0x1c]
 *   @0x22ae84 cmp r3, r6
 *   @0x22ae88 bgt 0x22ae54 <vorbis_info_clear+0x144>
 *   @0x22ae8c ldr r0, [r4, #0xc20]
 *   @0x22ae90 cmp r0, #0
 *   @0x22ae94 beq 0x22ae9c <vorbis_info_clear+0x18c>
 *   @0x22ae98 bl 0xb655c <free@plt>
 *   @0x22ae9c mov r0, r4
 *   @0x22aea0 bl 0xb655c <free@plt>
 *   @0x22aea4 mov r0, r8
 *   @0x22aea8 mov r1, #0
 *   @0x22aeac mov r2, #32
 *   @0x22aeb0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x22aeb4 b 0xb65b0 <memset@plt>
 *   @0x22aeb8 ldrsheq r6, [r12], -r12
 *   @0x22aebc ldrheq r6, [r12], -r4
 *   @0x22aec0 andseq r6, r12, r12, ror #12
 *
 * ══ §35/69 yySocket::SendDataToEvent  0x296b08  size 432  108 条（0x296b08..0x296cb8）
 * @func 0x296b08 0x296cb8  size 432  108 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / F_BUFFER_Create(RValue&, CInstance*, CInstance*, int, RValue*) / GetIBuffer(int) / ThrowNetworkEvent(int, int, int) / F_BUFFER_Delete(RValue&, CInstance*, CInstance*, int, RValue*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / debug_display_buffer(tagIConsole&, unsigned char*, int)
 * 字段偏移 top8: 0x60×4 / 0x64×2 / 0xc×2 / 0x38×2 / 0x24×1 / 0x34×1 / 0x44×1 / 0x16c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296b08 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x296b0c vpush {d8}
 *   @0x296b10 sub sp, sp, #72
 *   @0x296b14 vmov s13, r1
 *   @0x296b18 mov r3, #0
 *   @0x296b1c str r3, [sp, #0x24]
 *   @0x296b20 subs r10, r2, #0
 *   @0x296b24 str r3, [sp, #0x34]
 *   @0x296b28 vcvt.f64.s32 d8, s13
 *   @0x296b2c str r3, [sp, #0x44]
 *   @0x296b30 mov r4, #0
 *   @0x296b34 ldr r3, [pc, #0x16c]
 *   @0x296b38 mov r5, #0
 *   @0x296b3c ldreq r10, [r0, #0x50]
 *   @0x296b40 movt r5, #0x3ff0
 *   @0x296b44 ldr r3, [pc, r3]
 *   @0x296b48 mov r6, #0
 *   @0x296b4c mov r7, #0
 *   @0x296b50 mov r8, r1
 *   @0x296b54 ldrb r3, [r3]
 *   @0x296b58 mov r9, r0
 *   @0x296b5c strd r6, r7, [sp, #40]
 *   @0x296b60 vstr d8, [sp, #24]
 *   @0x296b64 cmp r3, #0
 *   @0x296b68 strd r4, r5, [sp, #56]
 *   @0x296b6c bne 0x296c70 <_ZN8yySocket15SendDataToEventEiPh+0x168>
 *   @0x296b70 ldr r3, [r9, #0x64]
 *   @0x296b74 ldr r0, [r9, #0x60]
 *   @0x296b78 cmp r8, r3
 *   @0x296b7c bgt 0x296c44 <_ZN8yySocket15SendDataToEventEiPh+0x13c>
 *   @0x296b80 mov r2, r8
 *   @0x296b84 mov r1, r10
 *   @0x296b88 bl 0xb65bc <memcpy@plt>
 *   @0x296b8c ldr r5, [r9, #0x60]
 *   @0x296b90 movw r3, #0xc0de
 *   @0x296b94 movt r3, #0xdead
 *   @0x296b98 ldr r2, [r5]
 *   @0x296b9c cmp r2, r3
 *   @0x296ba0 bne 0x296bbc <_ZN8yySocket15SendDataToEventEiPh+0xb4>
 *   @0x296ba4 ldr r3, [r5, #0x4]
 *   @0x296ba8 cmp r3, #12
 *   @0x296bac ldreq r8, [r5, #0x8]
 *   @0x296bb0 addeq r5, r5, #12
 *   @0x296bb4 vmoveq s15, r8
 *   @0x296bb8 vcvteq.f64.s32 d8, s15
 *   @0x296bbc add r6, sp, #8
 *   @0x296bc0 mov r1, #0
 *   @0x296bc4 mov r3, #3
 *   @0x296bc8 mov r2, r1
 *   @0x296bcc mov r0, r6
 *   @0x296bd0 add r7, sp, #24
 *   @0x296bd4 str r7, [sp]
 *   @0x296bd8 vstr d8, [sp, #24]
 *   @0x296bdc bl 0xc6bb8 <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_>
 *   @0x296be0 vldr d7, [sp, #8]
 *   @0x296be4 vcvt.s32.f64 s13, d7
 *   @0x296be8 vmov r0, s13
 *   @0x296bec vmov r4, s13
 *   @0x296bf0 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x296bf4 mov r1, r5
 *   @0x296bf8 mov r2, r8
 *   @0x296bfc ldr r0, [r0, #0xc]
 *   @0x296c00 bl 0xb65bc <memcpy@plt>
 *   @0x296c04 ldr r0, [r9, #0x68]
 *   @0x296c08 mov r2, r8
 *   @0x296c0c mov r1, r4
 *   @0x296c10 bl 0x298b9c <_Z17ThrowNetworkEventiii>
 *   @0x296c14 vmov s13, r4
 *   @0x296c18 mov r1, #0
 *   @0x296c1c str r7, [sp]
 *   @0x296c20 vcvt.f64.s32 d7, s13
 *   @0x296c24 mov r0, r6
 *   @0x296c28 mov r2, r1
 *   @0x296c2c mov r3, #1
 *   @0x296c30 vstr d7, [sp, #24]
 *   @0x296c34 bl 0xc52a4 <_Z15F_BUFFER_DeleteR6RValueP9CInstanceS2_iPS_>
 *   @0x296c38 add sp, sp, #72
 *   @0x296c3c vpop {d8}
 *   @0x296c40 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x296c44 ldr r2, [pc, #0x60]
 *   @0x296c48 mov r3, #0
 *   @0x296c4c str r8, [r9, #0x64]
 *   @0x296c50 mov r1, r8
 *   @0x296c54 str r3, [sp]
 *   @0x296c58 add r2, pc, r2
 *   @0x296c5c mov r3, #74
 *   @0x296c60 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x296c64 mov r3, r0
 *   @0x296c68 str r3, [r9, #0x60]
 *   @0x296c6c b 0x296b80 <_ZN8yySocket15SendDataToEventEiPh+0x78>
 *   @0x296c70 ldr r3, [pc, #0x38]
 *   @0x296c74 ldr r1, [pc, #0x38]
 *   @0x296c78 ldr r3, [pc, r3]
 *   @0x296c7c add r1, pc, r1
 *   @0x296c80 ldr r4, [r3]
 *   @0x296c84 ldr r3, [r4]
 *   @0x296c88 mov r0, r4
 *   @0x296c8c ldr r3, [r3, #0xc]
 *   @0x296c90 blx r3
 *   @0x296c94 mov r0, r4
 *   @0x296c98 mov r1, r10
 *   @0x296c9c mov r2, r8
 *   @0x296ca0 bl 0x2967e8 <_Z20debug_display_bufferR11tagIConsolePhi>
 *   @0x296ca4 b 0x296b70 <_ZN8yySocket15SendDataToEventEiPh+0x68>
 *   @0x296ca8 andseq r10, r5, r4, asr lr
 *   @0x296cac ldrdeq r10, r11, [r9], -r8
 *   @0x296cb0 mulseq r5, r12, r10
 *   @0x296cb4 muleq r12, r4, r8
 *
 * ══ §36/69 Variable_Global_DeSerialise  0x1f4b64  size 428  107 条（0x1f4b64..0x1f4d10）
 * @func 0x1f4b64 0x1f4d10  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f4b98→0x544b4c, 0x1f4bc8→0x544be0, 0x1f4c2c→0x753100, 0x1f4cb8→0x753100
 * 调用序列: YYGetInt32(RValue const*, int)×2 / MemoryManager::Free(void const*)×2 / YYError(char const*, ...) / Variable_Global_DeSerialise(IBuffer*)+0x9c / RValue::DeSerialise(IBuffer*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / Variable_Global_DeSerialise(IBuffer*)+0x138 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x4×7 / 0xc×3 / 0x160×1 / 0x15c×1 / 0x148×1 / 0x134×1 / 0xd4×1 / 0xd0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f4b64 ldr r3, [r0]
 *   @0x1f4b68 mov r1, #6
 *   @0x1f4b6c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1f4b70 add r6, r0, #44
 *   @0x1f4b74 ldr r3, [r3, #0xc]
 *   @0x1f4b78 sub sp, sp, #12
 *   @0x1f4b7c mov r2, r6
 *   @0x1f4b80 mov r5, r0
 *   @0x1f4b84 blx r3
 *   @0x1f4b88 mov r0, r6
 *   @0x1f4b8c mov r1, #0
 *   @0x1f4b90 ldr r9, [pc, #0x160]
 *   @0x1f4b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1f4b98 ldr r3, [pc, #0x15c]
 *   @0x1f4b9c add r9, pc, r9
 *   @0x1f4ba0 ldr r7, [r9, r3]
 *   @0x1f4ba4 ldr r3, [r7]
 *   @0x1f4ba8 cmp r3, r0
 *   @0x1f4bac beq 0x1f4bc0 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x5c>
 *   @0x1f4bb0 ldr r0, [pc, #0x148]
 *   @0x1f4bb4 add r0, pc, r0
 *   @0x1f4bb8 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x1f4bbc ldr r3, [r7]
 *   @0x1f4bc0 cmp r3, #0
 *   @0x1f4bc4 ble 0x1f4c00 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x9c>
 *   @0x1f4bc8 ldr r3, [pc, #0x134]
 *   @0x1f4bcc mov r4, #0
 *   @0x1f4bd0 ldr r8, [r9, r3]
 *   @0x1f4bd4 ldr r2, [r8]
 *   @0x1f4bd8 ldr r3, [r2, #0x4]
 *   @0x1f4bdc cmp r3, #0
 *   @0x1f4be0 add r0, r3, r4, lsl #4
 *   @0x1f4be4 beq 0x1f4ca8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x144>
 *   @0x1f4be8 mov r1, r5
 *   @0x1f4bec add r4, r4, #1
 *   @0x1f4bf0 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer>
 *   @0x1f4bf4 ldr r3, [r7]
 *   @0x1f4bf8 cmp r3, r4
 *   @0x1f4bfc bgt 0x1f4bd4 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x70>
 *   @0x1f4c00 ldr r3, [r5]
 *   @0x1f4c04 mov r1, #6
 *   @0x1f4c08 mov r2, r6
 *   @0x1f4c0c mov r0, r5
 *   @0x1f4c10 ldr r3, [r3, #0xc]
 *   @0x1f4c14 blx r3
 *   @0x1f4c18 mov r0, r6
 *   @0x1f4c1c mov r1, #0
 *   @0x1f4c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1f4c24 subs r7, r0, #0
 *   @0x1f4c28 beq 0x1f4cb8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x154>
 *   @0x1f4c2c ldr r0, [pc, #0xd4]
 *   @0x1f4c30 mov r4, #0
 *   @0x1f4c34 ldr r2, [pc, #0xd0]
 *   @0x1f4c38 mov r1, r7
 *   @0x1f4c3c mov r3, #106
 *   @0x1f4c40 ldr r8, [r9, r0]
 *   @0x1f4c44 add r2, pc, r2
 *   @0x1f4c48 ldr r0, [r8, #0x4]
 *   @0x1f4c4c str r4, [sp]
 *   @0x1f4c50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f4c54 cmp r7, r4
 *   @0x1f4c58 str r7, [r8]
 *   @0x1f4c5c str r0, [r8, #0x4]
 *   @0x1f4c60 ble 0x1f4c9c <_Z27Variable_Global_DeSerialiseP7IBuffer+0x138>
 *   @0x1f4c64 ldr r3, [r5]
 *   @0x1f4c68 mov r1, #6
 *   @0x1f4c6c mov r2, r6
 *   @0x1f4c70 mov r0, r5
 *   @0x1f4c74 ldr r3, [r3, #0xc]
 *   @0x1f4c78 blx r3
 *   @0x1f4c7c mov r0, r6
 *   @0x1f4c80 mov r1, #0
 *   @0x1f4c84 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1f4c88 ldr r3, [r8, #0x4]
 *   @0x1f4c8c strb r0, [r3, r4]
 *   @0x1f4c90 add r4, r4, #1
 *   @0x1f4c94 cmp r4, r7
 *   @0x1f4c98 bne 0x1f4c64 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x100>
 *   @0x1f4c9c mov r0, #1
 *   @0x1f4ca0 add sp, sp, #12
 *   @0x1f4ca4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f4ca8 mov r0, r2
 *   @0x1f4cac mov r1, r4
 *   @0x1f4cb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f4cb4 b 0x1f4be8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x84>
 *   @0x1f4cb8 ldr r3, [pc, #0x48]
 *   @0x1f4cbc ldr r8, [r9, r3]
 *   @0x1f4cc0 ldr r4, [r8, #0x4]
 *   @0x1f4cc4 cmp r4, #0
 *   @0x1f4cc8 beq 0x1f4cec <_Z27Variable_Global_DeSerialiseP7IBuffer+0x188>
 *   @0x1f4ccc mov r0, r4
 *   @0x1f4cd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f4cd4 str r7, [r8, #0x4]
 *   @0x1f4cd8 mov r3, #0
 *   @0x1f4cdc mov r0, #1
 *   @0x1f4ce0 str r3, [r8]
 *   @0x1f4ce4 add sp, sp, #12
 *   @0x1f4ce8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f4cec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f4cf0 str r4, [r8, #0x4]
 *   @0x1f4cf4 b 0x1f4cd8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x174>
 *   @0x1f4cf8 ldrheq sp, [pc], -r4
 *   @0x1f4cfc .word 0xffffc0b8
 *   @0x1f4d00 andseq sp, r5, r8, ror r12
 *   @0x1f4d04 .word 0xffffbf64
 *   @0x1f4d08 .word 0xfffff1d8
 *   @0x1f4d0c ldrsheq r8, [r5], -r0
 *
 * ══ §37/69 yyServer::ProcessDataPacket  0x2975a4  size 428  107 条（0x2975a4..0x297750）
 * @func 0x2975a4 0x297750  size 428  107 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::SendDataToEvent(int, unsigned char*) / yyServer::DeleteSocket(yySocket*) / FreeSocket(yySocket*) / ProcessDebugPacket(DbgSocket*, Buffer_Standard*, SNetwork_Packet*, int) / yySocket::Write(void*, unsigned int) / ThrowConnectingSocketNetworkEvent(int, int, int, int, char*, bool) / DebuggerDestroyIPSocket() / DebuggerSetConnected(bool)
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x18×3 / 0x28×2 / 0x104×2 / 0x2c×2 / 0x14×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2975a4 push {r4, r5, r6, r7, lr}
 *   @0x2975a8 mov r4, r1
 *   @0x2975ac ldr r5, [r1, #0x28]
 *   @0x2975b0 sub sp, sp, #36
 *   @0x2975b4 mov r7, r0
 *   @0x2975b8 mov r6, r2
 *   @0x2975bc cmp r5, #1
 *   @0x2975c0 beq 0x297608 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x64>
 *   @0x2975c4 cmp r5, #2
 *   @0x2975c8 beq 0x2975dc <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x38>
 *   @0x2975cc ldr r2, [r0, #0x20]
 *   @0x2975d0 cmp r2, #1
 *   @0x2975d4 cmpne r2, #4
 *   @0x2975d8 bne 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c>
 *   @0x2975dc ldr r1, [r6]
 *   @0x2975e0 movw r2, #0xc0de
 *   @0x2975e4 movt r2, #0xbe11
 *   @0x2975e8 cmp r1, r2
 *   @0x2975ec beq 0x297678 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0xd4>
 *   @0x2975f0 mov r0, r4
 *   @0x2975f4 mov r1, r3
 *   @0x2975f8 mov r2, r6
 *   @0x2975fc bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh>
 *   @0x297600 add sp, sp, #36
 *   @0x297604 pop {r4, r5, r6, r7, pc}
 *   @0x297608 ldr r2, [r2]
 *   @0x29760c movw r3, #0xbabe
 *   @0x297610 movt r3, #0xcafe
 *   @0x297614 cmp r2, r3
 *   @0x297618 bne 0x29763c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x98>
 *   @0x29761c ldr r2, [r6, #0x4]
 *   @0x297620 movw r3, #0xb00b
 *   @0x297624 movt r3, #0xdead
 *   @0x297628 cmp r2, r3
 *   @0x29762c bne 0x29763c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x98>
 *   @0x297630 ldr r3, [r6, #0x8]
 *   @0x297634 cmp r3, #16
 *   @0x297638 beq 0x2976d0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x12c>
 *   @0x29763c ldr r3, [pc, #0x104]
 *   @0x297640 ldr r1, [pc, #0x104]
 *   @0x297644 ldr r3, [pc, r3]
 *   @0x297648 add r1, pc, r1
 *   @0x29764c ldr r0, [r3]
 *   @0x297650 ldr r3, [r0]
 *   @0x297654 ldr r3, [r3, #0xc]
 *   @0x297658 blx r3
 *   @0x29765c mov r1, r4
 *   @0x297660 mov r0, r7
 *   @0x297664 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket>
 *   @0x297668 mov r0, r4
 *   @0x29766c bl 0x29955c <_Z10FreeSocketP8yySocket>
 *   @0x297670 add sp, sp, #36
 *   @0x297674 pop {r4, r5, r6, r7, pc}
 *   @0x297678 ldr r2, [r6, #0x4]
 *   @0x29767c cmp r2, #44
 *   @0x297680 bne 0x2975f0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x4c>
 *   @0x297684 ldrb r2, [r4, #0x2c]
 *   @0x297688 cmp r2, #0
 *   @0x29768c beq 0x2975f0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x4c>
 *   @0x297690 ldr r5, [r4, #0x4c]
 *   @0x297694 mov r2, #0
 *   @0x297698 str r4, [sp, #0x14]
 *   @0x29769c mov r1, r2
 *   @0x2976a0 strb r2, [sp, #0x18]
 *   @0x2976a4 ldr r12, [r5]
 *   @0x2976a8 mov r0, r5
 *   @0x2976ac ldr r12, [r12, #0x10]
 *   @0x2976b0 str r3, [sp, #0xc]
 *   @0x2976b4 blx r12
 *   @0x2976b8 mov r1, r5
 *   @0x2976bc mov r2, r6
 *   @0x2976c0 ldr r3, [sp, #0xc]
 *   @0x2976c4 add r0, sp, #20
 *   @0x2976c8 bl 0x29e50c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti>
 *   @0x2976cc b 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c>
 *   @0x2976d0 mov r3, #12
 *   @0x2976d4 mov r0, r1
 *   @0x2976d8 mov r2, r3
 *   @0x2976dc add r1, sp, #20
 *   @0x2976e0 str r3, [sp, #0x1c]
 *   @0x2976e4 movw lr, #0xbead
 *   @0x2976e8 movw r12, #0xbeeb
 *   @0x2976ec movt lr, #0xdeaf
 *   @0x2976f0 movt r12, #0xf00d
 *   @0x2976f4 str lr, [sp, #0x14]
 *   @0x2976f8 str r12, [sp, #0x18]
 *   @0x2976fc bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x297700 ldrb r3, [r4, #0x2c]
 *   @0x297704 cmp r3, #0
 *   @0x297708 bne 0x297738 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x194>
 *   @0x29770c ldr r0, [r7, #0x18]
 *   @0x297710 add r12, r4, #108
 *   @0x297714 ldr r1, [r4, #0x68]
 *   @0x297718 ldr r2, [r4, #0xac]
 *   @0x29771c ldr r3, [r4, #0xb0]
 *   @0x297720 str r5, [sp, #0x4]
 *   @0x297724 str r12, [sp]
 *   @0x297728 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb>
 *   @0x29772c mov r3, #2
 *   @0x297730 str r3, [r4, #0x28]
 *   @0x297734 b 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c>
 *   @0x297738 bl 0x29cd80 <_Z23DebuggerDestroyIPSocketv>
 *   @0x29773c mov r0, r5
 *   @0x297740 bl 0x29cad0 <_Z20DebuggerSetConnectedb>
 *   @0x297744 b 0x29772c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x188>
 *   @0x297748 ldrsbeq r6, [r5], -r0
 *   @0x29774c andeq r1, r12, r0, ror pc
 *
 * ══ §38/69 IAP_ConsumeM  0x161940  size 424  106 条（0x161940..0x161ae8）
 * @func 0x161940 0x161ae8  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x161958→0x484a4c, 0x161978→0x484a50, 0x1619d4→0x3eb708, 0x161a70→0x756d44, 0x161a78→0x756ccc
 * 调用序列: getJNIEnv×5 / IAP_ConsumeM(char const*)+0x94 / 0xb6574 / 0xb6550 / YYIAPConsumeEvent(char const*) / _JNIEnv::CallStaticLongMethod(_jclass*, _jmethodID*, ...) / 0xb65d4
 * 字段偏移 top8: 0xc×5 / 0x4×3 / 0x214×2 / 0x29c×2 / 0x5c×2 / 0x174×1 / 0x170×1 / 0x16c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x161944 sub sp, sp, #540
 *   @0x161948 ldr r9, [pc, #0x174]
 *   @0x16194c mov r8, r0
 *   @0x161950 ldr r2, [pc, #0x170]
 *   @0x161954 add r9, pc, r9
 *   @0x161958 ldr r3, [pc, #0x16c]
 *   @0x16195c ldr r10, [r9, r2]
 *   @0x161960 ldr r2, [r10]
 *   @0x161964 str r2, [sp, #0x214]
 *   @0x161968 ldr r3, [r9, r3]
 *   @0x16196c ldr r6, [r3]
 *   @0x161970 cmp r6, #0
 *   @0x161974 ble 0x1619d4 <_Z12IAP_ConsumeMPKc+0x94>
 *   @0x161978 ldr r2, [pc, #0x150]
 *   @0x16197c mov r5, #0
 *   @0x161980 mov r11, r5
 *   @0x161984 ldr r2, [r9, r2]
 *   @0x161988 ldr r7, [r2, #0x4]
 *   @0x16198c str r2, [sp, #0xc]
 *   @0x161990 ldr r4, [r7, r5]
 *   @0x161994 cmp r4, #0
 *   @0x161998 beq 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84>
 *   @0x16199c ldr r0, [r4, #0x4]
 *   @0x1619a0 cmp r0, #0
 *   @0x1619a4 beq 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84>
 *   @0x1619a8 mov r1, r8
 *   @0x1619ac bl 0xb6574 <strcmp@plt>
 *   @0x1619b0 cmp r0, #0
 *   @0x1619b4 bne 0x1619c4 <_Z12IAP_ConsumeMPKc+0x84>
 *   @0x1619b8 ldr r2, [r4, #0xc]
 *   @0x1619bc cmp r2, #0
 *   @0x1619c0 bne 0x161a30 <_Z12IAP_ConsumeMPKc+0xf0>
 *   @0x1619c4 add r11, r11, #1
 *   @0x1619c8 add r5, r5, #4
 *   @0x1619cc cmp r11, r6
 *   @0x1619d0 bne 0x161990 <_Z12IAP_ConsumeMPKc+0x50>
 *   @0x1619d4 ldr r3, [pc, #0xf8]
 *   @0x1619d8 add r4, sp, #20
 *   @0x1619dc ldr r1, [pc, #0xf4]
 *   @0x1619e0 ldr r3, [r9, r3]
 *   @0x1619e4 add r1, pc, r1
 *   @0x1619e8 ldr r0, [r3]
 *   @0x1619ec ldr r3, [r0]
 *   @0x1619f0 ldr r3, [r3, #0xc]
 *   @0x1619f4 blx r3
 *   @0x1619f8 ldr r1, [pc, #0xdc]
 *   @0x1619fc mov r2, r8
 *   @0x161a00 mov r0, r4
 *   @0x161a04 add r1, pc, r1
 *   @0x161a08 mov r3, #6
 *   @0x161a0c bl 0xb6550 <sprintf@plt>
 *   @0x161a10 mov r0, r4
 *   @0x161a14 bl 0x15556c <_Z17YYIAPConsumeEventPKc>
 *   @0x161a18 ldr r2, [sp, #0x214]
 *   @0x161a1c ldr r3, [r10]
 *   @0x161a20 cmp r2, r3
 *   @0x161a24 bne 0x161ac0 <_Z12IAP_ConsumeMPKc+0x180>
 *   @0x161a28 add sp, sp, #540
 *   @0x161a2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x161a30 bl 0x290274 <getJNIEnv>
 *   @0x161a34 mov r1, r8
 *   @0x161a38 ldr r3, [r0]
 *   @0x161a3c ldr r3, [r3, #0x29c]
 *   @0x161a40 blx r3
 *   @0x161a44 mov r4, r0
 *   @0x161a48 bl 0x290274 <getJNIEnv>
 *   @0x161a4c ldr r2, [sp, #0xc]
 *   @0x161a50 ldr r3, [r2, #0x4]
 *   @0x161a54 ldr r3, [r3, r5]
 *   @0x161a58 ldr r1, [r3, #0xc]
 *   @0x161a5c ldr r3, [r0]
 *   @0x161a60 ldr r3, [r3, #0x29c]
 *   @0x161a64 blx r3
 *   @0x161a68 mov r5, r0
 *   @0x161a6c bl 0x290274 <getJNIEnv>
 *   @0x161a70 ldr r1, [pc, #0x68]
 *   @0x161a74 mov r3, r4
 *   @0x161a78 ldr r2, [pc, #0x64]
 *   @0x161a7c ldr r1, [r9, r1]
 *   @0x161a80 ldr r2, [r9, r2]
 *   @0x161a84 str r5, [sp]
 *   @0x161a88 ldr r1, [r1]
 *   @0x161a8c ldr r2, [r2]
 *   @0x161a90 bl 0x161704 <_ZN7_JNIEnv20CallStaticLongMethodEP7_jclassP10_jmethodIDz>
 *   @0x161a94 bl 0x290274 <getJNIEnv>
 *   @0x161a98 mov r1, r5
 *   @0x161a9c ldr r3, [r0]
 *   @0x161aa0 ldr r3, [r3, #0x5c]
 *   @0x161aa4 blx r3
 *   @0x161aa8 bl 0x290274 <getJNIEnv>
 *   @0x161aac mov r1, r4
 *   @0x161ab0 ldr r3, [r0]
 *   @0x161ab4 ldr r3, [r3, #0x5c]
 *   @0x161ab8 blx r3
 *   @0x161abc b 0x161a18 <_Z12IAP_ConsumeMPKc+0xd8>
 *   @0x161ac0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x161ac4 .word 0x002902fc
 *   @0x161ac8 .word 0xffffbd00
 *   @0x161acc .word 0xffffde78
 *   @0x161ad0 .word 0xffffde7c
 *   @0x161ad4 .word 0xffffbcf0
 *   @0x161ad8 mulseq lr, r8, r1
 *   @0x161adc ldrheq r8, [lr], -r0
 *   @0x161ae0 .word 0xffffbd54
 *   @0x161ae4 .word 0xffffe31c
 *
 * ══ §39/69 Color_HSVToRGB  0x20fd04  size 424  106 条（0x20fd04..0x20feac）
 * @func 0x20fd04 0x20feac  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x2×1
 * VFP 指令 67 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fd04 ldrb r3, [r0]
 *   @0x20fd08 vldr s11, [pc, #396]
 *   @0x20fd0c vldr s13, [pc, #396]
 *   @0x20fd10 vldr s10, [pc, #396]
 *   @0x20fd14 sub sp, sp, #8
 *   @0x20fd18 vmov s14, r3
 *   @0x20fd1c ldrb r3, [r0, #0x1]
 *   @0x20fd20 ldrb r0, [r0, #0x2]
 *   @0x20fd24 vcvt.f32.s32 s14, s14
 *   @0x20fd28 vmov s12, r3
 *   @0x20fd2c vmov s15, r0
 *   @0x20fd30 vmul.f32 s14, s14, s11
 *   @0x20fd34 vcvt.f32.u32 s12, s12
 *   @0x20fd38 vdiv.f32 s14, s14, s13
 *   @0x20fd3c vcvt.f32.u32 s15, s15
 *   @0x20fd40 vdiv.f32 s12, s12, s13
 *   @0x20fd44 vdiv.f32 s15, s15, s13
 *   @0x20fd48 vcmp.f32 s14, s11
 *   @0x20fd4c vmrs APSR_nzcv, fpscr
 *   @0x20fd50 vcmp.f32 s12, s10
 *   @0x20fd54 vmoveq.f32 s14, s10
 *   @0x20fd58 vmrs APSR_nzcv, fpscr
 *   @0x20fd5c vmoveq.f32 s12, s15
 *   @0x20fd60 vmoveq.f32 s13, s15
 *   @0x20fd64 beq 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fd68 vldr s13, [pc, #312]
 *   @0x20fd6c vdiv.f32 s14, s14, s13
 *   @0x20fd70 vcvt.s32.f32 s10, s14
 *   @0x20fd74 vcvt.f32.s32 s13, s10
 *   @0x20fd78 vmov r3, s10
 *   @0x20fd7c vmov.f32 s11, #1.000000e+00
 *   @0x20fd80 vsub.f32 s14, s14, s13
 *   @0x20fd84 vsub.f32 s9, s11, s14
 *   @0x20fd88 vmov.f32 s13, s11
 *   @0x20fd8c vmls.f32 s13, s12, s14
 *   @0x20fd90 vmov.f32 s14, s11
 *   @0x20fd94 vmls.f32 s14, s9, s12
 *   @0x20fd98 vsub.f32 s12, s11, s12
 *   @0x20fd9c vmul.f32 s14, s14, s15
 *   @0x20fda0 vmul.f32 s13, s13, s15
 *   @0x20fda4 vmul.f32 s12, s12, s15
 *   @0x20fda8 cmp r3, #4
 *   @0x20fdac addls pc, pc, r3, lsl #2
 *   @0x20fdb0 b 0x20fe88 <_Z14Color_HSVToRGBR4THSV+0x184>
 *   @0x20fdb4 b 0x20fe5c <_Z14Color_HSVToRGBR4THSV+0x158>
 *   @0x20fdb8 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fdbc b 0x20fe68 <_Z14Color_HSVToRGBR4THSV+0x164>
 *   @0x20fdc0 b 0x20fe74 <_Z14Color_HSVToRGBR4THSV+0x170>
 *   @0x20fdc4 b 0x20fdc8 <_Z14Color_HSVToRGBR4THSV+0xc4>
 *   @0x20fdc8 vmov.f32 s11, s15
 *   @0x20fdcc vmov.f32 s13, s14
 *   @0x20fdd0 vmov.f32 s15, s12
 *   @0x20fdd4 vmov.f32 s12, s11
 *   @0x20fdd8 vldr s11, [pc, #192]
 *   @0x20fddc mov r0, #0
 *   @0x20fde0 vmov.f32 s14, #5.000000e-01
 *   @0x20fde4 vmla.f32 s14, s13, s11
 *   @0x20fde8 vldr s13, [pc, #176]
 *   @0x20fdec vcvt.s32.f32 s14, s14
 *   @0x20fdf0 vmov r3, s14
 *   @0x20fdf4 vmov.f32 s14, #5.000000e-01
 *   @0x20fdf8 vmla.f32 s14, s15, s13
 *   @0x20fdfc cmp r3, #254
 *   @0x20fe00 bicle r3, r3, r3, asr #31
 *   @0x20fe04 movgt r2, #255
 *   @0x20fe08 uxtble r2, r3
 *   @0x20fe0c vmov.f32 s15, #5.000000e-01
 *   @0x20fe10 vcvt.s32.f32 s14, s14
 *   @0x20fe14 vmov r3, s14
 *   @0x20fe18 vldr s14, [pc, #128]
 *   @0x20fe1c vmla.f32 s15, s12, s14
 *   @0x20fe20 cmp r3, #254
 *   @0x20fe24 bicle r3, r3, r3, asr #31
 *   @0x20fe28 vcvt.s32.f32 s15, s15
 *   @0x20fe2c movgt r1, #255
 *   @0x20fe30 uxtble r1, r3
 *   @0x20fe34 vmov r3, s15
 *   @0x20fe38 cmp r3, #254
 *   @0x20fe3c bicle r3, r3, r3, asr #31
 *   @0x20fe40 movgt r3, #255
 *   @0x20fe44 uxtble r3, r3
 *   @0x20fe48 bfi r0, r3, #0, #8
 *   @0x20fe4c bfi r0, r1, #8, #8
 *   @0x20fe50 bfi r0, r2, #16, #8
 *   @0x20fe54 add sp, sp, #8
 *   @0x20fe58 bx lr
 *   @0x20fe5c vmov.f32 s13, s15
 *   @0x20fe60 vmov.f32 s15, s14
 *   @0x20fe64 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fe68 vmov.f32 s13, s12
 *   @0x20fe6c vmov.f32 s12, s14
 *   @0x20fe70 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fe74 vmov.f32 s14, s13
 *   @0x20fe78 vmov.f32 s13, s12
 *   @0x20fe7c vmov.f32 s12, s15
 *   @0x20fe80 vmov.f32 s15, s14
 *   @0x20fe84 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fe88 vmov.f32 s14, s13
 *   @0x20fe8c vmov.f32 s13, s15
 *   @0x20fe90 vmov.f32 s15, s12
 *   @0x20fe94 vmov.f32 s12, s14
 *   @0x20fe98 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4>
 *   @0x20fe9c .word 0x43b40000
 *   @0x20fea0 cmnmi pc, #0
 *   @0x20fea4 andeq r0, r0, r0
 *   @0x20fea8 rsbsmi r0, r0, #0
 *
 * ══ §40/69 b2World::DestroyJoint  0x2c923c  size 424  106 条（0x2c923c..0x2c93e4）
 * @func 0x2c923c 0x2c93e4  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::Destroy(b2Joint*, b2BlockAllocator*)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x7c×2 / 0x18×2 / 0x1c×2 / 0x28×2 / 0x2c×2 / 0x188×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c923c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c9240 movw r5, #0x91d4
 *   @0x2c9244 movt r5, #0x1
 *   @0x2c9248 ldr r7, [pc, #0x188]
 *   @0x2c924c mov r6, r0
 *   @0x2c9250 mov r4, r1
 *   @0x2c9254 ldr r0, [r0, r5]
 *   @0x2c9258 ldr r7, [pc, r7]
 *   @0x2c925c ldr r1, [pc, #0x178]
 *   @0x2c9260 eor r0, r0, #2
 *   @0x2c9264 ldr r3, [r7]
 *   @0x2c9268 add r1, pc, r1
 *   @0x2c926c ubfx r0, r0, #0x1, #0x1
 *   @0x2c9270 blx r3
 *   @0x2c9274 ldr r3, [r6, r5]
 *   @0x2c9278 tst r3, #2
 *   @0x2c927c popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c9280 ldr r3, [r4, #0x8]
 *   @0x2c9284 movw r8, #0x9234
 *   @0x2c9288 ldrb r10, [r4, #0x3d]
 *   @0x2c928c movt r8, #0x1
 *   @0x2c9290 cmp r3, #0
 *   @0x2c9294 ldr r5, [r4, #0x30]
 *   @0x2c9298 ldr r9, [r4, #0x34]
 *   @0x2c929c mov r0, r4
 *   @0x2c92a0 ldrne r2, [r4, #0xc]
 *   @0x2c92a4 strne r2, [r3, #0xc]
 *   @0x2c92a8 ldr r2, [r4, #0xc]
 *   @0x2c92ac cmp r2, #0
 *   @0x2c92b0 strne r3, [r2, #0x8]
 *   @0x2c92b4 movw r3, #0x922c
 *   @0x2c92b8 movt r3, #0x1
 *   @0x2c92bc ldr r1, [r6, r3]
 *   @0x2c92c0 cmp r1, r4
 *   @0x2c92c4 streq r2, [r6, r3]
 *   @0x2c92c8 ldrh r3, [r5, #4]
 *   @0x2c92cc ldr r1, [r5, #0x7c]
 *   @0x2c92d0 tst r3, #2
 *   @0x2c92d4 orreq r3, r3, #2
 *   @0x2c92d8 strheq r3, [r5, #4]
 *   @0x2c92dc ldrh r3, [r9, #4]
 *   @0x2c92e0 moveq r2, #0
 *   @0x2c92e4 streq r2, [r5, #0xa0]
 *   @0x2c92e8 tst r3, #2
 *   @0x2c92ec orreq r3, r3, #2
 *   @0x2c92f0 strheq r3, [r9, #4]
 *   @0x2c92f4 ldr r3, [r4, #0x18]
 *   @0x2c92f8 moveq r2, #0
 *   @0x2c92fc streq r2, [r9, #0xa0]
 *   @0x2c9300 cmp r3, #0
 *   @0x2c9304 ldrne r2, [r4, #0x1c]
 *   @0x2c9308 strne r2, [r3, #0xc]
 *   @0x2c930c ldr r2, [r4, #0x1c]
 *   @0x2c9310 cmp r2, #0
 *   @0x2c9314 strne r3, [r2, #0x8]
 *   @0x2c9318 add r3, r4, #16
 *   @0x2c931c cmp r1, r3
 *   @0x2c9320 ldr r3, [r4, #0x28]
 *   @0x2c9324 streq r2, [r5, #0x7c]
 *   @0x2c9328 mov r2, #0
 *   @0x2c932c cmp r3, r2
 *   @0x2c9330 str r2, [r4, #0x18]
 *   @0x2c9334 str r2, [r4, #0x1c]
 *   @0x2c9338 ldrne r2, [r4, #0x2c]
 *   @0x2c933c ldr r1, [r9, #0x7c]
 *   @0x2c9340 strne r2, [r3, #0xc]
 *   @0x2c9344 ldr r2, [r4, #0x2c]
 *   @0x2c9348 cmp r2, #0
 *   @0x2c934c strne r3, [r2, #0x8]
 *   @0x2c9350 add r3, r4, #32
 *   @0x2c9354 cmp r1, r3
 *   @0x2c9358 mov r1, r6
 *   @0x2c935c streq r2, [r9, #0x7c]
 *   @0x2c9360 mov r3, #0
 *   @0x2c9364 str r3, [r4, #0x28]
 *   @0x2c9368 str r3, [r4, #0x2c]
 *   @0x2c936c bl 0x2cdd98 <_ZN7b2Joint7DestroyEPS_P16b2BlockAllocator>
 *   @0x2c9370 ldr r0, [r6, r8]
 *   @0x2c9374 ldr r1, [pc, #0x64]
 *   @0x2c9378 cmp r0, #0
 *   @0x2c937c ldr r3, [r7]
 *   @0x2c9380 add r1, pc, r1
 *   @0x2c9384 movle r0, #0
 *   @0x2c9388 movgt r0, #1
 *   @0x2c938c blx r3
 *   @0x2c9390 ldr r3, [r6, r8]
 *   @0x2c9394 cmp r10, #0
 *   @0x2c9398 sub r3, r3, #1
 *   @0x2c939c str r3, [r6, r8]
 *   @0x2c93a0 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c93a4 ldr r3, [r9, #0x80]
 *   @0x2c93a8 cmp r3, #0
 *   @0x2c93ac popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c93b0 ldr r2, [r3]
 *   @0x2c93b4 cmp r2, r5
 *   @0x2c93b8 ldreq r2, [r3, #0x4]
 *   @0x2c93bc ldr r3, [r3, #0xc]
 *   @0x2c93c0 ldreq r1, [r2, #0x4]
 *   @0x2c93c4 orreq r1, r1, #8
 *   @0x2c93c8 streq r1, [r2, #0x4]
 *   @0x2c93cc cmp r3, #0
 *   @0x2c93d0 bne 0x2c93b0 <_ZN7b2World12DestroyJointEP7b2Joint+0x174>
 *   @0x2c93d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c93d8 andseq r8, r2, r0, ror r2
 *   @0x2c93dc andeq r4, r9, r12, rrx
 *   @0x2c93e0 andeq r3, r9, r4, lsr #31
 *
 * ══ §41/69 CSkeletonInstance::CreateAttachment  0xbf9a0  size 420  105 条（0xbf9a0..0xbfb44）
 * @func 0xbf9a0 0xbfb44  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAtlasPage_create / spAtlasRegion_create / 0xb6538 / _malloc / 0xb65a4 / _calloc / spAtlasAttachmentLoader_create / spAttachmentLoader_createAttachment
 * 字段偏移 top8: 0x4×3 / 0x24×3 / 0x28×2 / 0x30×2 / 0x194×1 / 0x6c×1 / 0x2×1 / 0x68×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf9a0 ldr r12, [pc, #0x194]
 *   @0xbf9a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbf9a8 vpush {d8, d9, d10, d11, d12}
 *   @0xbf9ac ldr r12, [pc, r12]
 *   @0xbf9b0 mov r4, r3
 *   @0xbf9b4 sub sp, sp, #28
 *   @0xbf9b8 ldr r3, [r12, #0x4]
 *   @0xbf9bc mov r7, r1
 *   @0xbf9c0 mov r9, r0
 *   @0xbf9c4 mov r1, r2
 *   @0xbf9c8 add r0, sp, #12
 *   @0xbf9cc ldr r8, [sp, #0x6c]
 *   @0xbf9d0 ldr r11, [r3, r4, lsl #2]
 *   @0xbf9d4 vldr s24, [sp, #112]
 *   @0xbf9d8 ldr r10, [sp, #0x68]
 *   @0xbf9dc vldr s23, [sp, #116]
 *   @0xbf9e0 vldr s22, [sp, #120]
 *   @0xbf9e4 vldr s21, [sp, #124]
 *   @0xbf9e8 vldr s18, [sp, #128]
 *   @0xbf9ec vldr s17, [sp, #132]
 *   @0xbf9f0 vldr s20, [sp, #136]
 *   @0xbf9f4 vldr s19, [sp, #140]
 *   @0xbf9f8 vldr s16, [sp, #144]
 *   @0xbf9fc bl 0x284058 <spAtlasPage_create>
 *   @0xbfa00 ldrsh r3, [r11, #6]
 *   @0xbfa04 mov r5, #0
 *   @0xbfa08 ldrsh r2, [r11, #4]
 *   @0xbfa0c ldr r11, [pc, #0x12c]
 *   @0xbfa10 add r11, pc, r11
 *   @0xbfa14 str r3, [r0, #0x24]
 *   @0xbfa18 mov r6, r0
 *   @0xbfa1c str r2, [r0, #0x20]
 *   @0xbfa20 str r4, [r0, #0x1c]
 *   @0xbfa24 str r5, [r0, #0x28]
 *   @0xbfa28 bl 0x2840d8 <spAtlasRegion_create>
 *   @0xbfa2c mov r4, r0
 *   @0xbfa30 mov r0, r7
 *   @0xbfa34 bl 0xb6538 <strlen@plt>
 *   @0xbfa38 movw r2, #0x494
 *   @0xbfa3c mov r1, r11
 *   @0xbfa40 add r0, r0, #1
 *   @0xbfa44 bl 0x285c10 <_malloc>
 *   @0xbfa48 mov r1, r7
 *   @0xbfa4c str r0, [r4]
 *   @0xbfa50 bl 0xb65a4 <strcpy@plt>
 *   @0xbfa54 mov r2, r11
 *   @0xbfa58 str r5, [r4, #0x4]
 *   @0xbfa5c mov r1, #12
 *   @0xbfa60 str r5, [r4, #0x8]
 *   @0xbfa64 movw r3, #0x4a9
 *   @0xbfa68 str r8, [r4, #0x10]
 *   @0xbfa6c vstr s24, [r4, #20]
 *   @0xbfa70 str r5, [r4, #0x24]
 *   @0xbfa74 vstr s23, [r4, #24]
 *   @0xbfa78 str r5, [r4, #0x28]
 *   @0xbfa7c vstr s22, [r4, #28]
 *   @0xbfa80 str r8, [r4, #0x30]
 *   @0xbfa84 vstr s21, [r4, #32]
 *   @0xbfa88 str r5, [r4, #0x34]
 *   @0xbfa8c mov r0, #1
 *   @0xbfa90 str r5, [r4, #0x38]
 *   @0xbfa94 str r5, [r4, #0x3c]
 *   @0xbfa98 str r5, [r4, #0x40]
 *   @0xbfa9c str r5, [r4, #0x44]
 *   @0xbfaa0 str r6, [r4, #0x48]
 *   @0xbfaa4 str r5, [r4, #0x4c]
 *   @0xbfaa8 str r10, [r4, #0xc]
 *   @0xbfaac str r10, [r4, #0x2c]
 *   @0xbfab0 bl 0x285c4c <_calloc>
 *   @0xbfab4 str r6, [r0]
 *   @0xbfab8 mov r8, r0
 *   @0xbfabc str r4, [r0, #0x4]
 *   @0xbfac0 bl 0x284bb4 <spAtlasAttachmentLoader_create>
 *   @0xbfac4 ldr r1, [r9, #0x30]
 *   @0xbfac8 mov r3, r7
 *   @0xbfacc mov r2, r5
 *   @0xbfad0 ldr r1, [r1, #0x24]
 *   @0xbfad4 ldr r1, [r1]
 *   @0xbfad8 str r7, [sp]
 *   @0xbfadc mov r6, r0
 *   @0xbfae0 bl 0x284d58 <spAttachmentLoader_createAttachment>
 *   @0xbfae4 vldr s14, [r4, #12]
 *   @0xbfae8 vldr s15, [r4, #16]
 *   @0xbfaec vcvt.f32.s32 s14, s14
 *   @0xbfaf0 vcvt.f32.s32 s15, s15
 *   @0xbfaf4 vstr s14, [r0, #40]
 *   @0xbfaf8 vstr s15, [r0, #44]
 *   @0xbfafc mov r5, r0
 *   @0xbfb00 vstr s20, [r0, #28]
 *   @0xbfb04 vstr s19, [r0, #32]
 *   @0xbfb08 vstr s18, [r0, #20]
 *   @0xbfb0c vstr s17, [r0, #24]
 *   @0xbfb10 vstr s16, [r0, #36]
 *   @0xbfb14 bl 0x289040 <spRegionAttachment_updateOffset>
 *   @0xbfb18 mov r0, r9
 *   @0xbfb1c mov r1, r5
 *   @0xbfb20 mov r2, r8
 *   @0xbfb24 bl 0xbf92c <_ZN17CSkeletonInstance15StoreAttachmentEP12spAttachmentP7spAtlas>
 *   @0xbfb28 mov r0, r6
 *   @0xbfb2c bl 0x284d38 <spAttachmentLoader_dispose>
 *   @0xbfb30 add sp, sp, #28
 *   @0xbfb34 vpop {d8, d9, d10, d11, d12}
 *   @0xbfb38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbfb3c eorseq sp, r2, r0, ror pc
 *   @0xbfb40 .word 0x00270db0
 *
 * ══ §42/69 AddGraphicsInfo  0x17d284  size 420  105 条（0x17d284..0x17d428）
 * @func 0x17d284 0x17d428  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::Add(char const*, double, char const*)×7
 * 字段偏移 top8: 0x160×1 / 0x15c×1 / 0x150×1 / 0x12c×1 / 0x108×1 / 0xe4×1 / 0xb4×1 / 0x-4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17d284 push {r4, r5, r6, lr}
 *   @0x17d288 subs r5, r0, #0
 *   @0x17d28c sub sp, sp, #16
 *   @0x17d290 beq 0x17d39c <_Z15AddGraphicsInfoP7CDS_Map+0x118>
 *   @0x17d294 ldr r4, [pc, #0x160]
 *   @0x17d298 movw r0, #0x1f02
 *   @0x17d29c ldr r6, [pc, #0x15c]
 *   @0x17d2a0 ldr r4, [pc, r4]
 *   @0x17d2a4 ldr r3, [r4]
 *   @0x17d2a8 blx r3
 *   @0x17d2ac ldr r1, [pc, #0x150]
 *   @0x17d2b0 mov r2, #0
 *   @0x17d2b4 mov r3, #0
 *   @0x17d2b8 add r1, pc, r1
 *   @0x17d2bc str r0, [sp]
 *   @0x17d2c0 mov r0, r5
 *   @0x17d2c4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d2c8 ldr r3, [r4]
 *   @0x17d2cc mov r0, #7936
 *   @0x17d2d0 blx r3
 *   @0x17d2d4 ldr r1, [pc, #0x12c]
 *   @0x17d2d8 mov r2, #0
 *   @0x17d2dc mov r3, #0
 *   @0x17d2e0 add r1, pc, r1
 *   @0x17d2e4 str r0, [sp]
 *   @0x17d2e8 mov r0, r5
 *   @0x17d2ec bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d2f0 ldr r3, [r4]
 *   @0x17d2f4 movw r0, #0x1f01
 *   @0x17d2f8 blx r3
 *   @0x17d2fc ldr r1, [pc, #0x108]
 *   @0x17d300 mov r2, #0
 *   @0x17d304 mov r3, #0
 *   @0x17d308 add r1, pc, r1
 *   @0x17d30c str r0, [sp]
 *   @0x17d310 mov r0, r5
 *   @0x17d314 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d318 ldr r3, [r4]
 *   @0x17d31c movw r0, #0x1f03
 *   @0x17d320 blx r3
 *   @0x17d324 ldr r1, [pc, #0xe4]
 *   @0x17d328 mov r3, #0
 *   @0x17d32c mov r2, #0
 *   @0x17d330 add r1, pc, r1
 *   @0x17d334 str r0, [sp]
 *   @0x17d338 mov r0, r5
 *   @0x17d33c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d340 ldr r6, [pc, r6]
 *   @0x17d344 ldr r3, [r6]
 *   @0x17d348 cmp r3, #1
 *   @0x17d34c beq 0x17d3cc <_Z15AddGraphicsInfoP7CDS_Map+0x148>
 *   @0x17d350 cmp r3, #0
 *   @0x17d354 beq 0x17d3a4 <_Z15AddGraphicsInfoP7CDS_Map+0x120>
 *   @0x17d358 ldr r3, [pc, #0xb4]
 *   @0x17d35c add r1, sp, #16
 *   @0x17d360 mov r2, #1024
 *   @0x17d364 movw r0, #0xd33
 *   @0x17d368 ldr r3, [pc, r3]
 *   @0x17d36c str r2, [r1, #-0x4]!
 *   @0x17d370 ldr r3, [r3]
 *   @0x17d374 blx r3
 *   @0x17d378 vldr s15, [sp, #12]
 *   @0x17d37c vcvt.f64.s32 d7, s15
 *   @0x17d380 ldr r1, [pc, #0x90]
 *   @0x17d384 mov r12, #0
 *   @0x17d388 mov r0, r5
 *   @0x17d38c add r1, pc, r1
 *   @0x17d390 str r12, [sp]
 *   @0x17d394 vmov r2, r3, d7
 *   @0x17d398 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d39c add sp, sp, #16
 *   @0x17d3a0 pop {r4, r5, r6, pc}
 *   @0x17d3a4 ldr r12, [pc, #0x70]
 *   @0x17d3a8 mov r0, r5
 *   @0x17d3ac ldr r1, [pc, #0x6c]
 *   @0x17d3b0 mov r2, #0
 *   @0x17d3b4 add r12, pc, r12
 *   @0x17d3b8 mov r3, #0
 *   @0x17d3bc add r1, pc, r1
 *   @0x17d3c0 str r12, [sp]
 *   @0x17d3c4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d3c8 b 0x17d358 <_Z15AddGraphicsInfoP7CDS_Map+0xd4>
 *   @0x17d3cc ldr r3, [r4]
 *   @0x17d3d0 movw r0, #0x8b8c
 *   @0x17d3d4 blx r3
 *   @0x17d3d8 ldr r1, [pc, #0x44]
 *   @0x17d3dc mov r3, #0
 *   @0x17d3e0 mov r2, #0
 *   @0x17d3e4 add r1, pc, r1
 *   @0x17d3e8 str r0, [sp]
 *   @0x17d3ec mov r0, r5
 *   @0x17d3f0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x17d3f4 ldr r3, [r6]
 *   @0x17d3f8 b 0x17d350 <_Z15AddGraphicsInfoP7CDS_Map+0xcc>
 *   @0x17d3fc mlaeq r7, r0, r4, r0
 *   @0x17d400 eoreq r3, r7, r8, asr #1
 *   @0x17d404 andseq r12, r12, r8, asr r7
 *   @0x17d408 andseq r12, r12, r4, ror #14
 *   @0x17d40c andseq r12, r12, r4, lsr #14
 *   @0x17d410 andseq lr, r12, r8, asr r3
 *   @0x17d414 eoreq r0, r7, r0, lsr r4
 *   @0x17d418 ldrsheq r12, [r12], -r12
 *   @0x17d41c andseq r5, r11, r8, lsr r1
 *   @0x17d420 andseq r12, r12, r0, lsr #13
 *   @0x17d424 andseq r12, r12, r8, ror r6
 *
 * ══ §43/69 CTouchAction::AddRecord  0x1d7764  size 420  105 条（0x1d7764..0x1d7908）
 * @func 0x1d7764 0x1d7908  size 420  105 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertXDPI(float) / ConvertYDPI(float) / CTouchAction::AddRecord(long long, int, int)+0x148 / CTouchAction::AddRecord(long long, int, int)+0x158 / __floatdisf / CalcVelocity(float, float, float, float, float, float&, float&) / CTouchAction::AddRecord(long long, int, int)+0xc8
 * 字段偏移 top8: 0x828×3 / 0x14×3 / 0x10×3 / 0x40×2 / 0x44×2 / 0x38×2 / 0x82c×2 / 0x30×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d7764 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d7768 sub sp, sp, #28
 *   @0x1d776c vldr s14, [sp, #64]
 *   @0x1d7770 vcvt.f32.s32 s14, s14
 *   @0x1d7774 ldr r9, [r0, #0x828]
 *   @0x1d7778 ldr r1, [sp, #0x40]
 *   @0x1d777c mov r5, r3
 *   @0x1d7780 ldr r3, [sp, #0x44]
 *   @0x1d7784 mov r8, r0
 *   @0x1d7788 lsl r7, r9, #5
 *   @0x1d778c mov r4, r2
 *   @0x1d7790 add r6, r8, r7
 *   @0x1d7794 str r1, [r6, #0x30]
 *   @0x1d7798 str r3, [r6, #0x34]
 *   @0x1d779c vmov r0, s14
 *   @0x1d77a0 strd r4, r5, [r6, #40]
 *   @0x1d77a4 bl 0x1d66c0 <_Z11ConvertXDPIf>
 *   @0x1d77a8 vldr s14, [sp, #68]
 *   @0x1d77ac vcvt.f32.s32 s14, s14
 *   @0x1d77b0 str r0, [r6, #0x38]
 *   @0x1d77b4 vmov r0, s14
 *   @0x1d77b8 bl 0x1d66e4 <_Z11ConvertYDPIf>
 *   @0x1d77bc ldr r1, [r8, #0x82c]
 *   @0x1d77c0 mov r10, r0
 *   @0x1d77c4 ldr r0, [r8, #0x828]
 *   @0x1d77c8 str r10, [r6, #0x3c]
 *   @0x1d77cc add r0, r0, #1
 *   @0x1d77d0 asr r3, r0, #31
 *   @0x1d77d4 lsr r3, r3, #26
 *   @0x1d77d8 add r2, r0, r3
 *   @0x1d77dc and r2, r2, #63
 *   @0x1d77e0 rsb r2, r3, r2
 *   @0x1d77e4 str r2, [r8, #0x828]
 *   @0x1d77e8 cmp r2, r1
 *   @0x1d77ec addne r3, r7, #40
 *   @0x1d77f0 addne r3, r8, r3
 *   @0x1d77f4 beq 0x1d78d4 <_ZN12CTouchAction9AddRecordExii+0x170>
 *   @0x1d77f8 add r0, r8, #40
 *   @0x1d77fc rsb r3, r0, r3
 *   @0x1d7800 lsr r3, r3, #5
 *   @0x1d7804 cmp r3, #63
 *   @0x1d7808 bhi 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158>
 *   @0x1d780c cmp r2, r1
 *   @0x1d7810 add r3, r3, #63
 *   @0x1d7814 and r3, r3, #63
 *   @0x1d7818 blt 0x1d78ac <_ZN12CTouchAction9AddRecordExii+0x148>
 *   @0x1d781c cmp r1, r3
 *   @0x1d7820 bgt 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158>
 *   @0x1d7824 cmp r2, r3
 *   @0x1d7828 ble 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158>
 *   @0x1d782c lsl r3, r3, #5
 *   @0x1d7830 add r7, r8, r7
 *   @0x1d7834 add r3, r3, #40
 *   @0x1d7838 mov r0, r4
 *   @0x1d783c add r1, r8, r3
 *   @0x1d7840 ldr r2, [r7, #0x38]
 *   @0x1d7844 ldrd r6, r7, [r8, r3]
 *   @0x1d7848 add r9, r9, #2
 *   @0x1d784c ldr r3, [r1, #0x14]
 *   @0x1d7850 ldr r11, [r1, #0x10]
 *   @0x1d7854 mov r1, r5
 *   @0x1d7858 subs r0, r0, r6
 *   @0x1d785c sbc r1, r1, r7
 *   @0x1d7860 str r2, [sp, #0x10]
 *   @0x1d7864 str r3, [sp, #0x14]
 *   @0x1d7868 bl 0x319398 <__floatdisf>
 *   @0x1d786c vldr s15, [pc, #144]
 *   @0x1d7870 ldr r3, [sp, #0x14]
 *   @0x1d7874 add r8, r8, r9, lsl #5
 *   @0x1d7878 ldr r2, [sp, #0x10]
 *   @0x1d787c str r8, [sp, #0x4]
 *   @0x1d7880 add r8, r8, #4
 *   @0x1d7884 mov r1, r3
 *   @0x1d7888 str r8, [sp, #0x8]
 *   @0x1d788c mov r3, r10
 *   @0x1d7890 vmov s14, r0
 *   @0x1d7894 mov r0, r11
 *   @0x1d7898 vdiv.f32 s15, s14, s15
 *   @0x1d789c vstr s15, [sp]
 *   @0x1d78a0 bl 0x1d6854 <_Z12CalcVelocityfffffRfS_>
 *   @0x1d78a4 add sp, sp, #28
 *   @0x1d78a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d78ac cmp r2, r3
 *   @0x1d78b0 bgt 0x1d782c <_ZN12CTouchAction9AddRecordExii+0xc8>
 *   @0x1d78b4 cmp r1, r3
 *   @0x1d78b8 ble 0x1d782c <_ZN12CTouchAction9AddRecordExii+0xc8>
 *   @0x1d78bc add r8, r8, r7
 *   @0x1d78c0 mov r3, #0
 *   @0x1d78c4 str r3, [r8, #0x40]
 *   @0x1d78c8 str r3, [r8, #0x44]
 *   @0x1d78cc add sp, sp, #28
 *   @0x1d78d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d78d4 add r12, r2, #1
 *   @0x1d78d8 add r3, r7, #40
 *   @0x1d78dc add r3, r8, r3
 *   @0x1d78e0 asr r0, r12, #31
 *   @0x1d78e4 lsr r0, r0, #26
 *   @0x1d78e8 add r1, r12, r0
 *   @0x1d78ec and r1, r1, #63
 *   @0x1d78f0 rsb r1, r0, r1
 *   @0x1d78f4 str r1, [r8, #0x82c]
 *   @0x1d78f8 cmp r2, r1
 *   @0x1d78fc bne 0x1d77f8 <_ZN12CTouchAction9AddRecordExii+0x94>
 *   @0x1d7900 b 0x1d78bc <_ZN12CTouchAction9AddRecordExii+0x158>
 *   @0x1d7904 ldmdbmi r4!, {r10, sp} ^
 *
 * ══ §44/69 YYStrBuilderYY::AddFormat  0x15e0e8  size 416  104 条（0x15e0e8..0x15e288）
 * @func 0x15e0e8 0x15e288  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×2 / 0xb65bc×2 / 0xb655c×2 / 0xb6538 / 0xb6610
 * 字段偏移 top8: 0x8×6 / 0x4×6 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e0e8 push {r1, r2, r3}
 *   @0x15e0ec push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x15e0f0 sub sp, sp, #12
 *   @0x15e0f4 mov r4, r0
 *   @0x15e0f8 add r6, sp, #48
 *   @0x15e0fc ldr r7, [sp, #0x2c]
 *   @0x15e100 str r6, [sp]
 *   @0x15e104 mov r0, r7
 *   @0x15e108 bl 0xb6538 <strlen@plt>
 *   @0x15e10c ldr r3, [r4, #0x8]
 *   @0x15e110 ldr r5, [r4, #0x4]
 *   @0x15e114 mvn r1, r3
 *   @0x15e118 add r1, r5, r1
 *   @0x15e11c cmp r0, #16
 *   @0x15e120 movhs r2, r0
 *   @0x15e124 movlo r2, #16
 *   @0x15e128 mov r8, r0
 *   @0x15e12c cmp r2, r1
 *   @0x15e130 bgt 0x15e224 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x13c>
 *   @0x15e134 cmp r8, #32
 *   @0x15e138 movlo r8, #32
 *   @0x15e13c ldr r2, [r4]
 *   @0x15e140 mov r1, #0
 *   @0x15e144 add r8, r8, r8, lsl #1
 *   @0x15e148 strb r1, [r2, r3]
 *   @0x15e14c add r8, r8, r8, lsr #31
 *   @0x15e150 asr r8, r8, #1
 *   @0x15e154 ldr r1, [r4, #0x8]
 *   @0x15e158 mov r3, r6
 *   @0x15e15c ldr r12, [r4, #0x4]
 *   @0x15e160 mov r2, r7
 *   @0x15e164 ldr r0, [r4]
 *   @0x15e168 mvn r5, r1
 *   @0x15e16c add r5, r5, r12
 *   @0x15e170 add r0, r0, r1
 *   @0x15e174 str r6, [sp, #0x4]
 *   @0x15e178 mov r1, r5
 *   @0x15e17c bl 0xb6610 <vsnprintf@plt>
 *   @0x15e180 lsr r3, r0, #31
 *   @0x15e184 cmp r5, r0
 *   @0x15e188 movge r5, r3
 *   @0x15e18c orrlt r5, r3, #1
 *   @0x15e190 cmp r5, #0
 *   @0x15e194 bne 0x15e1bc <_ZN14YYStrBuilderYY9AddFormatEPKcz+0xd4>
 *   @0x15e198 ldr r2, [r4, #0x8]
 *   @0x15e19c ldr r3, [r4]
 *   @0x15e1a0 add r0, r0, r2
 *   @0x15e1a4 str r0, [r4, #0x8]
 *   @0x15e1a8 strb r5, [r3, r0]
 *   @0x15e1ac add sp, sp, #12
 *   @0x15e1b0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x15e1b4 add sp, sp, #12
 *   @0x15e1b8 bx lr
 *   @0x15e1bc ldr r5, [r4, #0x4]
 *   @0x15e1c0 ldr r2, [r4, #0x8]
 *   @0x15e1c4 cmp r5, #0
 *   @0x15e1c8 add r3, r8, r5
 *   @0x15e1cc ldr r10, [r4]
 *   @0x15e1d0 moveq r9, r3
 *   @0x15e1d4 movne r9, r5
 *   @0x15e1d8 add r3, r3, r2
 *   @0x15e1dc add r9, r9, r9, lsl #1
 *   @0x15e1e0 add r2, r3, r3, lsl #1
 *   @0x15e1e4 add r9, r9, r9, lsr #31
 *   @0x15e1e8 add r2, r2, r2, lsr #31
 *   @0x15e1ec asr r9, r9, #1
 *   @0x15e1f0 cmp r9, r3
 *   @0x15e1f4 asrlt r9, r2, #1
 *   @0x15e1f8 mov r0, r9
 *   @0x15e1fc bl 0xb6544 <malloc@plt>
 *   @0x15e200 mov r2, r5
 *   @0x15e204 mov r1, r10
 *   @0x15e208 str r0, [r4]
 *   @0x15e20c bl 0xb65bc <memcpy@plt>
 *   @0x15e210 subs r0, r10, #0
 *   @0x15e214 str r9, [r4, #0x4]
 *   @0x15e218 beq 0x15e154 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x6c>
 *   @0x15e21c bl 0xb655c <free@plt>
 *   @0x15e220 b 0x15e154 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x6c>
 *   @0x15e224 cmp r5, #0
 *   @0x15e228 add r3, r2, r3
 *   @0x15e22c ldr r10, [r4]
 *   @0x15e230 moveq r9, r2
 *   @0x15e234 movne r9, r5
 *   @0x15e238 add r9, r9, r9, lsl #1
 *   @0x15e23c add r9, r9, r9, lsr #31
 *   @0x15e240 asr r9, r9, #1
 *   @0x15e244 cmp r9, r3
 *   @0x15e248 addlt r3, r3, r3, lsl #1
 *   @0x15e24c addlt r3, r3, r3, lsr #31
 *   @0x15e250 asrlt r9, r3, #1
 *   @0x15e254 mov r0, r9
 *   @0x15e258 bl 0xb6544 <malloc@plt>
 *   @0x15e25c mov r2, r5
 *   @0x15e260 mov r1, r10
 *   @0x15e264 str r0, [r4]
 *   @0x15e268 bl 0xb65bc <memcpy@plt>
 *   @0x15e26c cmp r10, #0
 *   @0x15e270 str r9, [r4, #0x4]
 *   @0x15e274 beq 0x15e280 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x198>
 *   @0x15e278 mov r0, r10
 *   @0x15e27c bl 0xb655c <free@plt>
 *   @0x15e280 ldr r3, [r4, #0x8]
 *   @0x15e284 b 0x15e134 <_ZN14YYStrBuilderYY9AddFormatEPKcz+0x4c>
 *
 * ══ §45/69 yySocket::Process  0x294d28  size 416  104 条（0x294d28..0x294ec8）
 * @func 0x294d28 0x294ec8  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ThrowNonBlockingConnectSocketNetworkEvent(int, bool)×4 / yySocket::ProcessGMSHandshake() / 0xb65b0 / 0xb6d84 / Timing_Time / yySocket::Process()+0x18 / 0xb6d78 / 0xb6d90
 * 字段偏移 top8: 0x2f×4 / 0x68×4 / 0x2d×3 / 0x-80×1 / 0x10×1 / 0x14×1 / 0xcc×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294d28 ldrb r3, [r0, #0x2d]
 *   @0x294d2c push {r4, r5, r6, r7, lr}
 *   @0x294d30 cmp r3, #0
 *   @0x294d34 sub sp, sp, #156
 *   @0x294d38 mov r6, r0
 *   @0x294d3c bne 0x294d84 <_ZN8yySocket7ProcessEv+0x5c>
 *   @0x294d40 ldrb r12, [r6, #0x2f]
 *   @0x294d44 cmp r12, #0
 *   @0x294d48 bne 0x294d54 <_ZN8yySocket7ProcessEv+0x2c>
 *   @0x294d4c add sp, sp, #156
 *   @0x294d50 pop {r4, r5, r6, r7, pc}
 *   @0x294d54 mov r0, r6
 *   @0x294d58 bl 0x296320 <_ZN8yySocket19ProcessGMSHandshakeEv>
 *   @0x294d5c subs r1, r0, #0
 *   @0x294d60 beq 0x294ea4 <_ZN8yySocket7ProcessEv+0x17c>
 *   @0x294d64 cmp r1, #2
 *   @0x294d68 bne 0x294d4c <_ZN8yySocket7ProcessEv+0x24>
 *   @0x294d6c ldr r0, [r6, #0x68]
 *   @0x294d70 mov r1, #1
 *   @0x294d74 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib>
 *   @0x294d78 mov r3, #0
 *   @0x294d7c strb r3, [r6, #0x2f]
 *   @0x294d80 b 0x294d4c <_ZN8yySocket7ProcessEv+0x24>
 *   @0x294d84 add r4, sp, #24
 *   @0x294d88 mov r1, #0
 *   @0x294d8c mov r2, #128
 *   @0x294d90 mov r7, r1
 *   @0x294d94 mov r0, r4
 *   @0x294d98 add r5, sp, #152
 *   @0x294d9c bl 0xb65b0 <memset@plt>
 *   @0x294da0 ldr r3, [r6]
 *   @0x294da4 mov r2, r4
 *   @0x294da8 mov r4, #1
 *   @0x294dac and lr, r3, #31
 *   @0x294db0 add r0, r3, r4
 *   @0x294db4 asr r12, r3, #5
 *   @0x294db8 lsl lr, r4, lr
 *   @0x294dbc mov r1, r7
 *   @0x294dc0 mov r3, r7
 *   @0x294dc4 add r12, r5, r12, lsl #2
 *   @0x294dc8 add r5, sp, #16
 *   @0x294dcc str r5, [sp]
 *   @0x294dd0 str lr, [r12, #-0x80]
 *   @0x294dd4 str r7, [sp, #0x10]
 *   @0x294dd8 str r7, [sp, #0x14]
 *   @0x294ddc bl 0xb6d84 <select@plt>
 *   @0x294de0 cmp r0, #1
 *   @0x294de4 mov r4, r0
 *   @0x294de8 beq 0x294e50 <_ZN8yySocket7ProcessEv+0x128>
 *   @0x294dec bl 0x215148 <Timing_Time>
 *   @0x294df0 ldr r12, [pc, #0xcc]
 *   @0x294df4 mov r4, #1000
 *   @0x294df8 ldrd r2, r3, [r6, #64]
 *   @0x294dfc ldr r12, [pc, r12]
 *   @0x294e00 ldr r12, [r12]
 *   @0x294e04 mul r4, r4, r12
 *   @0x294e08 asr r5, r4, #31
 *   @0x294e0c subs r0, r0, r2
 *   @0x294e10 sbc r1, r1, r3
 *   @0x294e14 cmp r1, r5
 *   @0x294e18 cmpeq r0, r4
 *   @0x294e1c bls 0x294d40 <_ZN8yySocket7ProcessEv+0x18>
 *   @0x294e20 mov r2, #0
 *   @0x294e24 mov r3, #0
 *   @0x294e28 strb r7, [r6, #0x2d]
 *   @0x294e2c strd r2, r3, [r6, #64]
 *   @0x294e30 ldr r0, [r6]
 *   @0x294e34 bl 0xb6d78 <close@plt>
 *   @0x294e38 mvn r3, #0
 *   @0x294e3c mov r1, r7
 *   @0x294e40 ldr r0, [r6, #0x68]
 *   @0x294e44 str r3, [r6]
 *   @0x294e48 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib>
 *   @0x294e4c b 0x294d40 <_ZN8yySocket7ProcessEv+0x18>
 *   @0x294e50 ldr r0, [r6]
 *   @0x294e54 mov r1, r4
 *   @0x294e58 add r3, sp, #12
 *   @0x294e5c mov r2, #4
 *   @0x294e60 str r3, [sp]
 *   @0x294e64 add r3, sp, #11
 *   @0x294e68 str r4, [sp, #0xc]
 *   @0x294e6c bl 0xb6d90 <getsockopt@plt>
 *   @0x294e70 ldrb r1, [sp, #0xb]
 *   @0x294e74 cmp r1, r7
 *   @0x294e78 bne 0x294d40 <_ZN8yySocket7ProcessEv+0x18>
 *   @0x294e7c ldrb r12, [r6, #0x2e]
 *   @0x294e80 mov r2, #0
 *   @0x294e84 mov r3, #0
 *   @0x294e88 strb r1, [r6, #0x2d]
 *   @0x294e8c cmp r12, #0
 *   @0x294e90 strd r2, r3, [r6, #64]
 *   @0x294e94 beq 0x294eb0 <_ZN8yySocket7ProcessEv+0x188>
 *   @0x294e98 str r1, [r6, #0x34]
 *   @0x294e9c strb r4, [r6, #0x2f]
 *   @0x294ea0 b 0x294d44 <_ZN8yySocket7ProcessEv+0x1c>
 *   @0x294ea4 ldr r0, [r6, #0x68]
 *   @0x294ea8 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib>
 *   @0x294eac b 0x294d4c <_ZN8yySocket7ProcessEv+0x24>
 *   @0x294eb0 mov r1, r4
 *   @0x294eb4 ldr r0, [r6, #0x68]
 *   @0x294eb8 bl 0x2989ac <_Z41ThrowNonBlockingConnectSocketNetworkEventib>
 *   @0x294ebc ldrb r12, [r6, #0x2f]
 *   @0x294ec0 b 0x294d44 <_ZN8yySocket7ProcessEv+0x1c>
 *   @0x294ec4 mulseq r5, r0, r11
 *
 * ══ §46/69 UpdateAchievementCache  0x1598c4  size 412  103 条（0x1598c4..0x159a60）
 * @func 0x1598c4 0x159a60  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1598cc→0x484a9d, 0x1598e4→0x484a98, 0x1598f8→0x484a94, 0x159908→0x484a90, 0x159934→0x484aa4, 0x159948→0x484a8c, 0x15998c→0x484a88, 0x159994→0x484a8c
 * 调用序列: DeleteCachedAchievement(SAchivementCache*)×2 / Mutex::Lock() / UpdateAchievementCache()+0x148 / Achievement_PostAchievement(eCacheType, char const*, float) / UnLinkCacheAchievement(SAchivementCache*) / LinkCacheAchievementToEnd(SAchivementCache*) / FlushAchievementCache() / Achievement_PostHiScore(eCacheType, char const*, int)
 * 字段偏移 top8: 0x170×2 / 0xc×2 / 0x10×2 / 0x15c×1 / 0x14c×1 / 0x140×1 / 0x118×1 / 0x108×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1598c4 push {r4, r5, r6, lr}
 *   @0x1598c8 ldr r4, [pc, #0x170]
 *   @0x1598cc ldr r3, [pc, #0x170]
 *   @0x1598d0 add r4, pc, r4
 *   @0x1598d4 ldr r3, [r4, r3]
 *   @0x1598d8 ldrb r3, [r3]
 *   @0x1598dc cmp r3, #0
 *   @0x1598e0 popeq {r4, r5, r6, pc}
 *   @0x1598e4 ldr r3, [pc, #0x15c]
 *   @0x1598e8 ldr r3, [r4, r3]
 *   @0x1598ec ldr r3, [r3]
 *   @0x1598f0 cmp r3, #0
 *   @0x1598f4 popeq {r4, r5, r6, pc}
 *   @0x1598f8 ldr r3, [pc, #0x14c]
 *   @0x1598fc ldr r5, [r4, r3]
 *   @0x159900 ldr r0, [r5]
 *   @0x159904 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x159908 ldr r3, [pc, #0x140]
 *   @0x15990c ldr r6, [r4, r3]
 *   @0x159910 ldr r3, [r6]
 *   @0x159914 cmp r3, #4
 *   @0x159918 addls pc, pc, r3, lsl #2
 *   @0x15991c b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159920 b 0x159934 <_Z22UpdateAchievementCachev+0x70>
 *   @0x159924 b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159928 b 0x1599cc <_Z22UpdateAchievementCachev+0x108>
 *   @0x15992c b 0x15998c <_Z22UpdateAchievementCachev+0xc8>
 *   @0x159930 b 0x1599e8 <_Z22UpdateAchievementCachev+0x124>
 *   @0x159934 ldr r3, [pc, #0x118]
 *   @0x159938 ldr r3, [r4, r3]
 *   @0x15993c ldr r3, [r3]
 *   @0x159940 cmp r3, #0
 *   @0x159944 beq 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159948 ldr r2, [pc, #0x108]
 *   @0x15994c mov r1, #1
 *   @0x159950 ldr r0, [r3, #0x8]
 *   @0x159954 ldr r2, [r4, r2]
 *   @0x159958 cmp r0, r1
 *   @0x15995c str r1, [r6]
 *   @0x159960 str r3, [r2]
 *   @0x159964 beq 0x159a30 <_Z22UpdateAchievementCachev+0x16c>
 *   @0x159968 blt 0x159a0c <_Z22UpdateAchievementCachev+0x148>
 *   @0x15996c cmp r0, #3
 *   @0x159970 bgt 0x159a0c <_Z22UpdateAchievementCachev+0x148>
 *   @0x159974 ldr r1, [r3, #0xc]
 *   @0x159978 ldr r2, [r3, #0x10]
 *   @0x15997c bl 0x1614b4 <_Z27Achievement_PostAchievement10eCacheTypePKcf>
 *   @0x159980 ldr r0, [r5]
 *   @0x159984 pop {r4, r5, r6, lr}
 *   @0x159988 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15998c ldr r2, [pc, #0xc8]
 *   @0x159990 mov r1, #600
 *   @0x159994 ldr r3, [pc, #0xbc]
 *   @0x159998 mov r0, #4
 *   @0x15999c ldr r2, [r4, r2]
 *   @0x1599a0 str r0, [r6]
 *   @0x1599a4 str r1, [r2]
 *   @0x1599a8 ldr r4, [r4, r3]
 *   @0x1599ac ldr r0, [r4]
 *   @0x1599b0 bl 0x15978c <_Z22UnLinkCacheAchievementP16SAchivementCache>
 *   @0x1599b4 ldr r0, [r4]
 *   @0x1599b8 bl 0x159824 <_Z25LinkCacheAchievementToEndP16SAchivementCache>
 *   @0x1599bc bl 0x159640 <_Z21FlushAchievementCachev>
 *   @0x1599c0 mov r3, #0
 *   @0x1599c4 str r3, [r4]
 *   @0x1599c8 b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x1599cc ldr r3, [pc, #0x84]
 *   @0x1599d0 ldr r3, [r4, r3]
 *   @0x1599d4 ldr r0, [r3]
 *   @0x1599d8 bl 0x1598a8 <_Z23DeleteCachedAchievementP16SAchivementCache>
 *   @0x1599dc mov r3, #0
 *   @0x1599e0 str r3, [r6]
 *   @0x1599e4 b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x1599e8 ldr r3, [pc, #0x6c]
 *   @0x1599ec ldr r3, [r4, r3]
 *   @0x1599f0 ldr r2, [r3]
 *   @0x1599f4 cmp r2, #0
 *   @0x1599f8 subgt r2, r2, #1
 *   @0x1599fc strgt r2, [r3]
 *   @0x159a00 movle r3, #0
 *   @0x159a04 strle r3, [r6]
 *   @0x159a08 b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159a0c mov r0, r3
 *   @0x159a10 bl 0x1598a8 <_Z23DeleteCachedAchievementP16SAchivementCache>
 *   @0x159a14 ldr r3, [pc, #0x40]
 *   @0x159a18 mov r2, #600
 *   @0x159a1c mov r1, #4
 *   @0x159a20 ldr r3, [r4, r3]
 *   @0x159a24 str r1, [r6]
 *   @0x159a28 str r2, [r3]
 *   @0x159a2c b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159a30 ldr r1, [r3, #0xc]
 *   @0x159a34 ldr r2, [r3, #0x10]
 *   @0x159a38 bl 0x1613fc <_Z23Achievement_PostHiScore10eCacheTypePKci>
 *   @0x159a3c b 0x159980 <_Z22UpdateAchievementCachev+0xbc>
 *   @0x159a40 eoreq r8, r9, r0, lsl #7
 *   @0x159a44 .word 0xffffdee0
 *   @0x159a48 .word 0xffffdf7c
 *   @0x159a4c .word 0xffffdf84
 *   @0x159a50 .word 0xffffdf88
 *   @0x159a54 .word 0xffffdf74
 *   @0x159a58 .word 0xffffdf8c
 *   @0x159a5c .word 0xffffdf90
 *
 * ══ §47/69 processCollision  0x1cc034  size 412  103 条（0x1cc034..0x1cc1d0）
 * @func 0x1cc034 0x1cc1d0  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetPosition(float, float)×6 / CInstance::SetPathPosition(float)×3 / CInstance::Collision_Instance(CInstance*, bool)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / CInstance::Adapt_Path()×2 / CollisionMarkTest(CInstance*)
 * 字段偏移 top8: 0x66×4 / 0xc8×4 / 0xc4×4 / 0x130×4 / 0x69×2 / 0x7c×2 / 0x158×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc034 push {r3, r4, r5, lr}
 *   @0x1cc038 mov r2, #1
 *   @0x1cc03c ldm r0, {r4, r5}
 *   @0x1cc040 mov r0, r4
 *   @0x1cc044 mov r1, r5
 *   @0x1cc048 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1cc04c cmp r0, #0
 *   @0x1cc050 popeq {r3, r4, r5, pc}
 *   @0x1cc054 ldrb r3, [r4, #0x69]
 *   @0x1cc058 cmp r3, #0
 *   @0x1cc05c popne {r3, r4, r5, pc}
 *   @0x1cc060 ldrb r3, [r5, #0x69]
 *   @0x1cc064 cmp r3, #0
 *   @0x1cc068 popne {r3, r4, r5, pc}
 *   @0x1cc06c ldr r3, [pc, #0x158]
 *   @0x1cc070 mov r0, r5
 *   @0x1cc074 ldr r3, [pc, r3]
 *   @0x1cc078 ldr r2, [r3]
 *   @0x1cc07c add r2, r2, #1
 *   @0x1cc080 str r2, [r3]
 *   @0x1cc084 bl 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance>
 *   @0x1cc088 ldrb r3, [r4, #0x66]
 *   @0x1cc08c cmp r3, #0
 *   @0x1cc090 bne 0x1cc0a0 <_Z16processCollisionP10SCollision+0x6c>
 *   @0x1cc094 ldrb r3, [r5, #0x66]
 *   @0x1cc098 cmp r3, #0
 *   @0x1cc09c beq 0x1cc0d8 <_Z16processCollisionP10SCollision+0xa4>
 *   @0x1cc0a0 ldr r2, [r4, #0xc8]
 *   @0x1cc0a4 mov r0, r4
 *   @0x1cc0a8 ldr r1, [r4, #0xc4]
 *   @0x1cc0ac bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc0b0 mov r0, r4
 *   @0x1cc0b4 ldr r1, [r4, #0x130]
 *   @0x1cc0b8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc0bc mov r0, r5
 *   @0x1cc0c0 ldr r1, [r5, #0xc4]
 *   @0x1cc0c4 ldr r2, [r5, #0xc8]
 *   @0x1cc0c8 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc0cc mov r0, r5
 *   @0x1cc0d0 ldr r1, [r5, #0x130]
 *   @0x1cc0d4 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc0d8 mov r0, r4
 *   @0x1cc0dc mov r1, r5
 *   @0x1cc0e0 mov r2, #4
 *   @0x1cc0e4 ldr r3, [r5, #0x7c]
 *   @0x1cc0e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1cc0ec ldr r3, [r4, #0x7c]
 *   @0x1cc0f0 mov r0, r5
 *   @0x1cc0f4 mov r1, r4
 *   @0x1cc0f8 mov r2, #4
 *   @0x1cc0fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1cc100 ldrb r3, [r4, #0x66]
 *   @0x1cc104 cmp r3, #0
 *   @0x1cc108 bne 0x1cc118 <_Z16processCollisionP10SCollision+0xe4>
 *   @0x1cc10c ldrb r3, [r5, #0x66]
 *   @0x1cc110 cmp r3, #0
 *   @0x1cc114 popeq {r3, r4, r5, pc}
 *   @0x1cc118 mov r0, r4
 *   @0x1cc11c bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x1cc120 mov r0, r5
 *   @0x1cc124 bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x1cc128 vldr s13, [r4, #180]
 *   @0x1cc12c vldr s15, [r4, #224]
 *   @0x1cc130 vadd.f32 s15, s13, s15
 *   @0x1cc134 vldr s14, [r4, #184]
 *   @0x1cc138 mov r0, r4
 *   @0x1cc13c vmov r1, s15
 *   @0x1cc140 vldr s15, [r4, #228]
 *   @0x1cc144 vadd.f32 s15, s14, s15
 *   @0x1cc148 vmov r2, s15
 *   @0x1cc14c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc150 vldr s12, [r5, #180]
 *   @0x1cc154 vldr s14, [r5, #184]
 *   @0x1cc158 vldr s13, [r5, #224]
 *   @0x1cc15c vldr s15, [r5, #228]
 *   @0x1cc160 vadd.f32 s13, s12, s13
 *   @0x1cc164 mov r0, r5
 *   @0x1cc168 vadd.f32 s15, s14, s15
 *   @0x1cc16c vmov r1, s13
 *   @0x1cc170 vmov r2, s15
 *   @0x1cc174 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc178 mov r0, r4
 *   @0x1cc17c mov r1, r5
 *   @0x1cc180 mov r2, #1
 *   @0x1cc184 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1cc188 cmp r0, #0
 *   @0x1cc18c popeq {r3, r4, r5, pc}
 *   @0x1cc190 ldr r2, [r4, #0xc8]
 *   @0x1cc194 mov r0, r4
 *   @0x1cc198 ldr r1, [r4, #0xc4]
 *   @0x1cc19c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc1a0 mov r0, r4
 *   @0x1cc1a4 ldr r1, [r4, #0x130]
 *   @0x1cc1a8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc1ac mov r0, r5
 *   @0x1cc1b0 ldr r1, [r5, #0xc4]
 *   @0x1cc1b4 ldr r2, [r5, #0xc8]
 *   @0x1cc1b8 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc1bc mov r0, r5
 *   @0x1cc1c0 ldr r1, [r5, #0x130]
 *   @0x1cc1c4 pop {r3, r4, r5, lr}
 *   @0x1cc1c8 b 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc1cc eoreq r4, r2, r4, asr #21
 *
 * ══ §48/69 JS_Object_Put  0x24f118  size 408  102 条（0x24f118..0x24f2b0）
 * @func 0x24f118 0x24f2b0  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×2 / JS_DefineOwnProperty(YYObjectBase*, char const*, RValue*, bool)×2 / JS_CanPut(YYObjectBase*, char const*) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JS_IsDataDescriptor(RValue*) / JS_Argument_Put(YYObjectBase*, RValue*, char const*) / JSThrowTypeError(char const*) / JS_GetProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0x8×4 / 0xc×3 / 0x4×2 / 0x18×2 / 0x40×1 / 0xe8×1 / 0xd4×1 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24f118 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x24f11c mov r7, r1
 *   @0x24f120 sub sp, sp, #32
 *   @0x24f124 mov r1, r2
 *   @0x24f128 mov r6, r2
 *   @0x24f12c mov r9, r3
 *   @0x24f130 mov r8, r0
 *   @0x24f134 bl 0x241cac <_Z9JS_CanPutP12YYObjectBasePKc>
 *   @0x24f138 cmp r0, #0
 *   @0x24f13c bne 0x24f150 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x38>
 *   @0x24f140 cmp r9, #0
 *   @0x24f144 bne 0x24f1f8 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0xe0>
 *   @0x24f148 add sp, sp, #32
 *   @0x24f14c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x24f150 mov r0, r8
 *   @0x24f154 mov r2, r6
 *   @0x24f158 mov r1, sp
 *   @0x24f15c mov r12, #0
 *   @0x24f160 mvn r3, #-16777216
 *   @0x24f164 str r12, [sp, #0x8]
 *   @0x24f168 str r3, [sp, #0xc]
 *   @0x24f16c mov r4, #0
 *   @0x24f170 mov r5, #0
 *   @0x24f174 strd r4, r5, [sp]
 *   @0x24f178 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24f17c mov r0, sp
 *   @0x24f180 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue>
 *   @0x24f184 cmp r0, #0
 *   @0x24f188 beq 0x24f20c <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0xf4>
 *   @0x24f18c ldr r0, [r7]
 *   @0x24f190 add r4, sp, #16
 *   @0x24f194 ldr r1, [r7, #0x4]
 *   @0x24f198 ldr r2, [r7, #0x8]
 *   @0x24f19c mov r12, r4
 *   @0x24f1a0 ldr r3, [r7, #0xc]
 *   @0x24f1a4 ldr r5, [r8, #0x40]
 *   @0x24f1a8 ldr lr, [sp, #0x8]
 *   @0x24f1ac stm r12!, {r0, r1, r2, r3}
 *   @0x24f1b0 mov r0, r5
 *   @0x24f1b4 ldr r1, [pc, #0xe8]
 *   @0x24f1b8 str lr, [sp, #0x18]
 *   @0x24f1bc add r1, pc, r1
 *   @0x24f1c0 bl 0xb6574 <strcmp@plt>
 *   @0x24f1c4 cmp r0, #0
 *   @0x24f1c8 beq 0x24f290 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x178>
 *   @0x24f1cc ldr r1, [pc, #0xd4]
 *   @0x24f1d0 mov r0, r5
 *   @0x24f1d4 add r1, pc, r1
 *   @0x24f1d8 bl 0xb6574 <strcmp@plt>
 *   @0x24f1dc cmp r0, #0
 *   @0x24f1e0 mov r0, r8
 *   @0x24f1e4 bne 0x24f27c <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x164>
 *   @0x24f1e8 mov r1, r4
 *   @0x24f1ec mov r2, r6
 *   @0x24f1f0 bl 0x2499cc <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc>
 *   @0x24f1f4 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30>
 *   @0x24f1f8 ldr r0, [pc, #0xac]
 *   @0x24f1fc add r0, pc, r0
 *   @0x24f200 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24f204 add sp, sp, #32
 *   @0x24f208 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x24f20c mov r0, r8
 *   @0x24f210 mov r1, sp
 *   @0x24f214 mov r2, r6
 *   @0x24f218 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24f21c mov r0, sp
 *   @0x24f220 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue>
 *   @0x24f224 cmp r0, #0
 *   @0x24f228 beq 0x24f240 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x128>
 *   @0x24f22c mov r0, r8
 *   @0x24f230 mov r1, r7
 *   @0x24f234 mov r2, sp
 *   @0x24f238 bl 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_>
 *   @0x24f23c b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30>
 *   @0x24f240 ldr r0, [r7]
 *   @0x24f244 add lr, sp, #16
 *   @0x24f248 ldr r1, [r7, #0x4]
 *   @0x24f24c mov r4, #7
 *   @0x24f250 ldr r2, [r7, #0x8]
 *   @0x24f254 mov r12, lr
 *   @0x24f258 ldr r3, [r7, #0xc]
 *   @0x24f25c stm r12!, {r0, r1, r2, r3}
 *   @0x24f260 mov r2, lr
 *   @0x24f264 mov r0, r8
 *   @0x24f268 mov r1, r6
 *   @0x24f26c mov r3, r9
 *   @0x24f270 str r4, [sp, #0x18]
 *   @0x24f274 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x24f278 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30>
 *   @0x24f27c mov r1, r6
 *   @0x24f280 mov r2, r4
 *   @0x24f284 mov r3, r9
 *   @0x24f288 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x24f28c b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30>
 *   @0x24f290 mov r0, r8
 *   @0x24f294 mov r1, r4
 *   @0x24f298 mov r2, r6
 *   @0x24f29c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x24f2a0 b 0x24f148 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb+0x30>
 *   @0x24f2a4 andeq r5, lr, r12, asr r7
 *   @0x24f2a8 andseq r6, r0, r0, ror r12
 *   @0x24f2ac andseq r6, r0, r12, asr #26
 *
 * ══ §49/69 b2ContactManager::Collide  0x2c7970  size 408  102 条（0x2c7970..0x2c7b08）
 * @func 0x2c7970 0x2c7b08  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ContactManager::Collide()+0x158 / b2ContactManager::Destroy(b2Contact*) / b2Body::ShouldCollide(b2Body const*) const / b2Contact::Update(b2ContactListener*)
 * 字段偏移 top8: 0x4×6 / 0x18×4 / 0x8×3 / 0x3c×2 / 0xc×2 / 0x30×1 / 0x34×1 / 0x38×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7970 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c7974 mov r9, r0
 *   @0x2c7978 ldr r4, [r0, #0x3c]
 *   @0x2c797c cmp r4, #0
 *   @0x2c7980 bne 0x2c7a14 <_ZN16b2ContactManager7CollideEv+0xa4>
 *   @0x2c7984 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c7988 ldr r2, [r6]
 *   @0x2c798c cmp r2, #0
 *   @0x2c7990 beq 0x2c7a64 <_ZN16b2ContactManager7CollideEv+0xf4>
 *   @0x2c7994 ldr r2, [r7, #0x18]
 *   @0x2c7998 rsb r10, r10, r10, lsl #3
 *   @0x2c799c ldr r3, [r8, #0x18]
 *   @0x2c79a0 rsb r11, r11, r11, lsl #3
 *   @0x2c79a4 add r10, r2, r10, lsl #2
 *   @0x2c79a8 ldr r1, [r9, #0x4]
 *   @0x2c79ac add r11, r3, r11, lsl #2
 *   @0x2c79b0 ldr r2, [r10, #0x18]
 *   @0x2c79b4 ldr r3, [r11, #0x18]
 *   @0x2c79b8 add r2, r2, r2, lsl #3
 *   @0x2c79bc add r3, r3, r3, lsl #3
 *   @0x2c79c0 add r2, r1, r2, lsl #2
 *   @0x2c79c4 vldr s15, [r2, #8]
 *   @0x2c79c8 add r3, r1, r3, lsl #2
 *   @0x2c79cc vldr s14, [r3]
 *   @0x2c79d0 vsub.f32 s15, s14, s15
 *   @0x2c79d4 vldr s13, [r3, #4]
 *   @0x2c79d8 vldr s14, [r2, #12]
 *   @0x2c79dc vldr s11, [r2]
 *   @0x2c79e0 vldr s12, [r3, #8]
 *   @0x2c79e4 vldr s9, [r2, #4]
 *   @0x2c79e8 vldr s10, [r3, #12]
 *   @0x2c79ec vcmpe.f32 s15, #0
 *   @0x2c79f0 vmrs APSR_nzcv, fpscr
 *   @0x2c79f4 ble 0x2c7ac8 <_ZN16b2ContactManager7CollideEv+0x158>
 *   @0x2c79f8 ldr r5, [r4, #0xc]
 *   @0x2c79fc mov r1, r4
 *   @0x2c7a00 mov r0, r9
 *   @0x2c7a04 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact>
 *   @0x2c7a08 mov r4, r5
 *   @0x2c7a0c cmp r4, #0
 *   @0x2c7a10 beq 0x2c7a78 <_ZN16b2ContactManager7CollideEv+0x108>
 *   @0x2c7a14 ldr r3, [r4, #0x4]
 *   @0x2c7a18 ldr r7, [r4, #0x30]
 *   @0x2c7a1c ldr r8, [r4, #0x34]
 *   @0x2c7a20 tst r3, #8
 *   @0x2c7a24 ldr r10, [r4, #0x38]
 *   @0x2c7a28 ldr r5, [r7, #0x8]
 *   @0x2c7a2c ldr r6, [r8, #0x8]
 *   @0x2c7a30 ldr r11, [r4, #0x3c]
 *   @0x2c7a34 bne 0x2c7a7c <_ZN16b2ContactManager7CollideEv+0x10c>
 *   @0x2c7a38 ldrh r3, [r5, #4]
 *   @0x2c7a3c and r3, r3, #2
 *   @0x2c7a40 uxth r3, r3
 *   @0x2c7a44 cmp r3, #0
 *   @0x2c7a48 beq 0x2c7a58 <_ZN16b2ContactManager7CollideEv+0xe8>
 *   @0x2c7a4c ldr r3, [r5]
 *   @0x2c7a50 adds r3, r3, #0
 *   @0x2c7a54 movne r3, #1
 *   @0x2c7a58 ldrh r2, [r6, #4]
 *   @0x2c7a5c tst r2, #2
 *   @0x2c7a60 bne 0x2c7988 <_ZN16b2ContactManager7CollideEv+0x18>
 *   @0x2c7a64 cmp r3, #0
 *   @0x2c7a68 bne 0x2c7994 <_ZN16b2ContactManager7CollideEv+0x24>
 *   @0x2c7a6c ldr r4, [r4, #0xc]
 *   @0x2c7a70 cmp r4, #0
 *   @0x2c7a74 bne 0x2c7a14 <_ZN16b2ContactManager7CollideEv+0xa4>
 *   @0x2c7a78 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c7a7c mov r0, r6
 *   @0x2c7a80 mov r1, r5
 *   @0x2c7a84 bl 0x2c7158 <_ZNK6b2Body13ShouldCollideEPKS_>
 *   @0x2c7a88 cmp r0, #0
 *   @0x2c7a8c beq 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88>
 *   @0x2c7a90 ldr r0, [r9, #0x44]
 *   @0x2c7a94 cmp r0, #0
 *   @0x2c7a98 beq 0x2c7ab8 <_ZN16b2ContactManager7CollideEv+0x148>
 *   @0x2c7a9c ldr r3, [r0]
 *   @0x2c7aa0 mov r1, r7
 *   @0x2c7aa4 mov r2, r8
 *   @0x2c7aa8 ldr r3, [r3, #0x8]
 *   @0x2c7aac blx r3
 *   @0x2c7ab0 cmp r0, #0
 *   @0x2c7ab4 beq 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88>
 *   @0x2c7ab8 ldr r3, [r4, #0x4]
 *   @0x2c7abc bic r3, r3, #8
 *   @0x2c7ac0 str r3, [r4, #0x4]
 *   @0x2c7ac4 b 0x2c7a38 <_ZN16b2ContactManager7CollideEv+0xc8>
 *   @0x2c7ac8 vsub.f32 s14, s13, s14
 *   @0x2c7acc vcmpe.f32 s14, #0
 *   @0x2c7ad0 vmrs APSR_nzcv, fpscr
 *   @0x2c7ad4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88>
 *   @0x2c7ad8 vsub.f32 s12, s11, s12
 *   @0x2c7adc vcmpe.f32 s12, #0
 *   @0x2c7ae0 vmrs APSR_nzcv, fpscr
 *   @0x2c7ae4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88>
 *   @0x2c7ae8 vsub.f32 s10, s9, s10
 *   @0x2c7aec vcmpe.f32 s10, #0
 *   @0x2c7af0 vmrs APSR_nzcv, fpscr
 *   @0x2c7af4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88>
 *   @0x2c7af8 mov r0, r4
 *   @0x2c7afc ldr r1, [r9, #0x48]
 *   @0x2c7b00 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener>
 *   @0x2c7b04 b 0x2c7a6c <_ZN16b2ContactManager7CollideEv+0xfc>
 *
 * ══ §50/69 CGCGeneration::RemoveRoot  0x1911c8  size 404  101 条（0x1911c8..0x19135c）
 * @func 0x1911c8 0x19135c  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<YYObjectBase*>(YYObjectBase*) / CGCGeneration::RemoveRoot(YYObjectBase*)+0x184 / bool CHashMapCompareKeys<YYObjectBase*>(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×8 / 0x4×5 / 0x10×3 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1911c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1911cc subs r9, r1, #0
 *   @0x1911d0 sub sp, sp, #12
 *   @0x1911d4 mov r3, r0
 *   @0x1911d8 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184>
 *   @0x1911dc mov r0, r9
 *   @0x1911e0 ldr r6, [r3]
 *   @0x1911e4 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x1911e8 ldr r3, [r6, #0x8]
 *   @0x1911ec ldr r2, [r6, #0x10]
 *   @0x1911f0 bic r10, r0, #-2147483648
 *   @0x1911f4 and r4, r10, r3
 *   @0x1911f8 lsl r5, r4, #1
 *   @0x1911fc add r1, r5, r4
 *   @0x191200 add r2, r2, r1, lsl #2
 *   @0x191204 ldr r7, [r2, #0x8]
 *   @0x191208 cmp r7, #0
 *   @0x19120c beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184>
 *   @0x191210 mov r8, #0
 *   @0x191214 b 0x19125c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x94>
 *   @0x191218 ldr r2, [r6]
 *   @0x19121c and r7, r7, r3
 *   @0x191220 add r1, r4, #1
 *   @0x191224 add r2, r4, r2
 *   @0x191228 and r4, r1, r3
 *   @0x19122c rsb r7, r7, r2
 *   @0x191230 and r7, r7, r3
 *   @0x191234 lsl r5, r4, #1
 *   @0x191238 cmp r7, r8
 *   @0x19123c add r2, r5, r4
 *   @0x191240 add r8, r8, #1
 *   @0x191244 blt 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184>
 *   @0x191248 ldr r1, [r6, #0x10]
 *   @0x19124c add r2, r1, r2, lsl #2
 *   @0x191250 ldr r7, [r2, #0x8]
 *   @0x191254 cmp r7, #0
 *   @0x191258 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184>
 *   @0x19125c cmp r10, r7
 *   @0x191260 bne 0x191218 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x50>
 *   @0x191264 ldr r0, [r2]
 *   @0x191268 mov r1, r9
 *   @0x19126c bl 0x190f48 <_Z19CHashMapCompareKeysIP12YYObjectBaseEbT_S2_>
 *   @0x191270 cmp r0, #0
 *   @0x191274 ldreq r3, [r6, #0x8]
 *   @0x191278 beq 0x191218 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x50>
 *   @0x19127c cmn r4, #1
 *   @0x191280 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184>
 *   @0x191284 ldr r12, [r6, #0x8]
 *   @0x191288 add r0, r4, #1
 *   @0x19128c ldr r10, [r6, #0x10]
 *   @0x191290 and r0, r0, r12
 *   @0x191294 add r1, r0, r0, lsl #1
 *   @0x191298 add r1, r10, r1, lsl #2
 *   @0x19129c ldr r2, [r1, #0x8]
 *   @0x1912a0 cmp r2, #0
 *   @0x1912a4 beq 0x191354 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x18c>
 *   @0x1912a8 ldr r3, [r6]
 *   @0x1912ac str r3, [sp]
 *   @0x1912b0 and r3, r12, r2
 *   @0x1912b4 ldr r8, [sp]
 *   @0x1912b8 add r7, r0, r8
 *   @0x1912bc rsb r3, r3, r7
 *   @0x1912c0 tst r3, r12
 *   @0x1912c4 strne r6, [sp, #0x4]
 *   @0x1912c8 bne 0x1912dc <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x114>
 *   @0x1912cc b 0x191354 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x18c>
 *   @0x1912d0 tst r8, r12
 *   @0x1912d4 beq 0x19132c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x164>
 *   @0x1912d8 mov r0, r3
 *   @0x1912dc add r3, r0, #1
 *   @0x1912e0 add r7, r5, r4
 *   @0x1912e4 and r3, r3, r12
 *   @0x1912e8 ldr r11, [r1]
 *   @0x1912ec add r6, r10, r7, lsl #2
 *   @0x1912f0 ldr r4, [sp]
 *   @0x1912f4 add r9, r3, r3, lsl #1
 *   @0x1912f8 lsl r5, r0, #1
 *   @0x1912fc str r2, [r6, #0x8]
 *   @0x191300 add r8, r4, r3
 *   @0x191304 str r11, [r10, r7, lsl #2]
 *   @0x191308 mov r4, r0
 *   @0x19130c ldr r7, [r1, #0x4]
 *   @0x191310 add r1, r10, r9, lsl #2
 *   @0x191314 ldr r2, [r1, #0x8]
 *   @0x191318 str r7, [r6, #0x4]
 *   @0x19131c cmp r2, #0
 *   @0x191320 and r6, r12, r2
 *   @0x191324 rsb r8, r6, r8
 *   @0x191328 bne 0x1912d0 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x108>
 *   @0x19132c ldr r6, [sp, #0x4]
 *   @0x191330 add r0, r0, r0, lsl #1
 *   @0x191334 ldr r3, [r6, #0x4]
 *   @0x191338 mov r2, #0
 *   @0x19133c add r0, r10, r0, lsl #2
 *   @0x191340 sub r3, r3, #1
 *   @0x191344 str r2, [r0, #0x8]
 *   @0x191348 str r3, [r6, #0x4]
 *   @0x19134c add sp, sp, #12
 *   @0x191350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x191354 mov r0, r4
 *   @0x191358 b 0x191330 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x168>
 *
 * ══ §51/69 RelyAckAdd  0x29a318  size 404  101 条（0x29a318..0x29a4ac）
 * @func 0x29a318 0x29a4ac  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29a374→0x3eb70c, 0x29a424→0x7578e4, 0x29a44c→0x7578e0, 0x29a474→0x7578e0
 * 调用序列: RelyAckFindClient(char const*, int, int) / RelyAckNumPackets(SRelyAck*) / RelyAckSendToClient(SRelyAck*) / 0xb6c34 / YYStrDup(char const*) / Timing_Time
 * 字段偏移 top8: 0x409×3 / 0x40c×3 / 0x4×2 / 0xc×2 / 0x410×2 / 0x150×1 / 0x120×1 / 0x11c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a318 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x29a31c mov r4, r0
 *   @0x29a320 sub sp, sp, #12
 *   @0x29a324 mov r0, r1
 *   @0x29a328 mov r9, r1
 *   @0x29a32c mov r8, r2
 *   @0x29a330 mov r1, r2
 *   @0x29a334 mov r2, r4
 *   @0x29a338 mov r5, r3
 *   @0x29a33c bl 0x2998d8 <_Z17RelyAckFindClientPKcii>
 *   @0x29a340 ldr r7, [pc, #0x150]
 *   @0x29a344 add r7, pc, r7
 *   @0x29a348 subs r6, r0, #0
 *   @0x29a34c addne lr, r6, #8
 *   @0x29a350 movne r12, #0
 *   @0x29a354 bne 0x29a364 <_Z10RelyAckAddiPKcij+0x4c>
 *   @0x29a358 b 0x29a3fc <_Z10RelyAckAddiPKcij+0xe4>
 *   @0x29a35c cmp r12, #255
 *   @0x29a360 beq 0x29a3ac <_Z10RelyAckAddiPKcij+0x94>
 *   @0x29a364 ldr r4, [lr, #0x4]!
 *   @0x29a368 add r12, r12, #1
 *   @0x29a36c cmp r4, r5
 *   @0x29a370 bne 0x29a35c <_Z10RelyAckAddiPKcij+0x44>
 *   @0x29a374 ldr r0, [pc, #0x120]
 *   @0x29a378 mov r2, r5
 *   @0x29a37c ldr r1, [pc, #0x11c]
 *   @0x29a380 mov r3, r9
 *   @0x29a384 ldr r0, [r7, r0]
 *   @0x29a388 add r1, pc, r1
 *   @0x29a38c ldr r0, [r0]
 *   @0x29a390 ldr r12, [r0]
 *   @0x29a394 str r8, [sp]
 *   @0x29a398 ldr r12, [r12, #0xc]
 *   @0x29a39c blx r12
 *   @0x29a3a0 mov r0, #0
 *   @0x29a3a4 add sp, sp, #12
 *   @0x29a3a8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x29a3ac ldrb r2, [r6, #0x409]
 *   @0x29a3b0 movw r1, #0x8081
 *   @0x29a3b4 movt r1, #0x8080
 *   @0x29a3b8 add r3, r2, #1
 *   @0x29a3bc smull r0, r1, r1, r3
 *   @0x29a3c0 add r1, r1, r3
 *   @0x29a3c4 add r3, r3, r1, asr #7
 *   @0x29a3c8 and r3, r3, #255
 *   @0x29a3cc add r2, r6, r2, lsl #2
 *   @0x29a3d0 mov r0, r6
 *   @0x29a3d4 str r5, [r2, #0xc]
 *   @0x29a3d8 strb r3, [r6, #0x409]
 *   @0x29a3dc bl 0x299944 <_Z17RelyAckNumPacketsP8SRelyAck>
 *   @0x29a3e0 cmp r0, #255
 *   @0x29a3e4 movne r0, #1
 *   @0x29a3e8 bne 0x29a3a4 <_Z10RelyAckAddiPKcij+0x8c>
 *   @0x29a3ec mov r0, r6
 *   @0x29a3f0 bl 0x29a2c8 <_Z19RelyAckSendToClientP8SRelyAck>
 *   @0x29a3f4 mov r0, #1
 *   @0x29a3f8 b 0x29a3a4 <_Z10RelyAckAddiPKcij+0x8c>
 *   @0x29a3fc mov r1, #1056
 *   @0x29a400 mov r0, #1
 *   @0x29a404 bl 0xb6c34 <calloc@plt>
 *   @0x29a408 mov r6, r0
 *   @0x29a40c mov r0, r9
 *   @0x29a410 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x29a414 str r8, [r6, #0x4]
 *   @0x29a418 str r4, [r6, #0x8]
 *   @0x29a41c str r0, [r6]
 *   @0x29a420 bl 0x215148 <Timing_Time>
 *   @0x29a424 ldr r2, [pc, #0x78]
 *   @0x29a428 movw r12, #0x418
 *   @0x29a42c mov r3, #0
 *   @0x29a430 strb r3, [r6, #0x408]
 *   @0x29a434 strb r3, [r6, #0x409]
 *   @0x29a438 strd r0, r1, [r6, r12]
 *   @0x29a43c ldr r0, [r7, r2]
 *   @0x29a440 ldr r1, [r0]
 *   @0x29a444 cmp r1, r3
 *   @0x29a448 beq 0x29a474 <_Z10RelyAckAddiPKcij+0x15c>
 *   @0x29a44c ldr r1, [pc, #0x54]
 *   @0x29a450 mov r2, r3
 *   @0x29a454 str r3, [r6, #0x40c]
 *   @0x29a458 mov r3, #1
 *   @0x29a45c ldr r0, [r7, r1]
 *   @0x29a460 ldr r1, [r0]
 *   @0x29a464 str r6, [r0]
 *   @0x29a468 str r1, [r6, #0x410]
 *   @0x29a46c str r6, [r1, #0x40c]
 *   @0x29a470 b 0x29a3cc <_Z10RelyAckAddiPKcij+0xb4>
 *   @0x29a474 ldr r12, [pc, #0x2c]
 *   @0x29a478 mov r2, r1
 *   @0x29a47c str r1, [r6, #0x40c]
 *   @0x29a480 mov r3, #1
 *   @0x29a484 str r1, [r6, #0x410]
 *   @0x29a488 ldr r1, [r7, r12]
 *   @0x29a48c str r6, [r0]
 *   @0x29a490 str r6, [r1]
 *   @0x29a494 b 0x29a3cc <_Z10RelyAckAddiPKcij+0xb4>
 *   @0x29a498 andseq r7, r5, r12, lsl #18
 *   @0x29a49c .word 0xffffbac4
 *   @0x29a4a0 andeq pc, r11, r12, lsl #11
 *   @0x29a4a4 .word 0xfffffd98
 *   @0x29a4a8 .word 0xfffffdb0
 *
 * ══ §52/69 base64_encode  0x1d1e60  size 400  100 条（0x1d1e60..0x1d1ff0）
 * @func 0x1d1e60 0x1d1ff0  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×4 / 0x2×2 / 0x4×2 / 0x5×2 / 0x6×2 / 0x7×2 / 0x178×1 / 0x-8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1e60 push {r4, r5, r6, r7, r8, r9}
 *   @0x1d1e64 add r1, r0, r1
 *   @0x1d1e68 ldr r5, [pc, #0x178]
 *   @0x1d1e6c sub sp, sp, #8
 *   @0x1d1e70 mov r3, #0
 *   @0x1d1e74 add r5, pc, r5
 *   @0x1d1e78 b 0x1d1e80 <_Z13base64_encodePKcjPc+0x20>
 *   @0x1d1e7c mov r3, r12
 *   @0x1d1e80 cmp r0, r1
 *   @0x1d1e84 beq 0x1d1f0c <_Z13base64_encodePKcjPc+0xac>
 *   @0x1d1e88 add r12, r3, #1
 *   @0x1d1e8c ldrb r4, [r0], #1
 *   @0x1d1e90 add r6, sp, #8
 *   @0x1d1e94 cmp r12, #3
 *   @0x1d1e98 add r3, r6, r3
 *   @0x1d1e9c strb r4, [r3, #-0x8]
 *   @0x1d1ea0 bne 0x1d1e7c <_Z13base64_encodePKcjPc+0x1c>
 *   @0x1d1ea4 ldrb r12, [sp]
 *   @0x1d1ea8 mov r3, #0
 *   @0x1d1eac ldrb r6, [sp, #0x1]
 *   @0x1d1eb0 ldrb r4, [sp, #0x2]
 *   @0x1d1eb4 and r9, r12, #3
 *   @0x1d1eb8 and r8, r6, #15
 *   @0x1d1ebc lsr r12, r12, #2
 *   @0x1d1ec0 lsr r6, r6, #4
 *   @0x1d1ec4 strb r12, [sp, #0x4]
 *   @0x1d1ec8 lsr r7, r4, #6
 *   @0x1d1ecc add r6, r6, r9, lsl #4
 *   @0x1d1ed0 add r7, r7, r8, lsl #2
 *   @0x1d1ed4 and r4, r4, #63
 *   @0x1d1ed8 strb r6, [sp, #0x5]
 *   @0x1d1edc strb r7, [sp, #0x6]
 *   @0x1d1ee0 strb r4, [sp, #0x7]
 *   @0x1d1ee4 ldrb r12, [r5, r12]
 *   @0x1d1ee8 add r4, sp, #4
 *   @0x1d1eec strb r12, [r2, r3]
 *   @0x1d1ef0 add r3, r3, #1
 *   @0x1d1ef4 cmp r3, #4
 *   @0x1d1ef8 ldrbne r12, [r3, r4]
 *   @0x1d1efc bne 0x1d1ee4 <_Z13base64_encodePKcjPc+0x84>
 *   @0x1d1f00 add r2, r2, #4
 *   @0x1d1f04 mov r12, #0
 *   @0x1d1f08 b 0x1d1e7c <_Z13base64_encodePKcjPc+0x1c>
 *   @0x1d1f0c cmp r3, #0
 *   @0x1d1f10 mov r0, r3
 *   @0x1d1f14 beq 0x1d1fa4 <_Z13base64_encodePKcjPc+0x144>
 *   @0x1d1f18 cmp r3, #2
 *   @0x1d1f1c movle r12, sp
 *   @0x1d1f20 movle r1, #0
 *   @0x1d1f24 bgt 0x1d1f38 <_Z13base64_encodePKcjPc+0xd8>
 *   @0x1d1f28 strb r1, [r12, r3]
 *   @0x1d1f2c add r3, r3, #1
 *   @0x1d1f30 cmp r3, #3
 *   @0x1d1f34 bne 0x1d1f28 <_Z13base64_encodePKcjPc+0xc8>
 *   @0x1d1f38 ldrb r1, [sp]
 *   @0x1d1f3c mov r3, #0
 *   @0x1d1f40 ldrb r4, [sp, #0x1]
 *   @0x1d1f44 and r7, r1, #3
 *   @0x1d1f48 ldrb r12, [sp, #0x2]
 *   @0x1d1f4c and r6, r4, #15
 *   @0x1d1f50 lsr r1, r1, #2
 *   @0x1d1f54 lsr r4, r4, #4
 *   @0x1d1f58 strb r1, [sp, #0x4]
 *   @0x1d1f5c add r4, r4, r7, lsl #4
 *   @0x1d1f60 strb r4, [sp, #0x5]
 *   @0x1d1f64 ldr r4, [pc, #0x80]
 *   @0x1d1f68 lsr r5, r12, #6
 *   @0x1d1f6c add r5, r5, r6, lsl #2
 *   @0x1d1f70 and r12, r12, #63
 *   @0x1d1f74 add r4, pc, r4
 *   @0x1d1f78 strb r5, [sp, #0x6]
 *   @0x1d1f7c strb r12, [sp, #0x7]
 *   @0x1d1f80 ldrb r1, [r4, r1]
 *   @0x1d1f84 add r12, sp, #4
 *   @0x1d1f88 strb r1, [r2, r3]
 *   @0x1d1f8c add r3, r3, #1
 *   @0x1d1f90 cmp r3, r0
 *   @0x1d1f94 bgt 0x1d1fb8 <_Z13base64_encodePKcjPc+0x158>
 *   @0x1d1f98 ldrb r1, [r3, r12]
 *   @0x1d1f9c b 0x1d1f80 <_Z13base64_encodePKcjPc+0x120>
 *   @0x1d1fa0 mov r2, r3
 *   @0x1d1fa4 mov r3, #0
 *   @0x1d1fa8 strb r3, [r2]
 *   @0x1d1fac add sp, sp, #8
 *   @0x1d1fb0 pop {r4, r5, r6, r7, r8, r9}
 *   @0x1d1fb4 bx lr
 *   @0x1d1fb8 bic r3, r0, r0, asr #31
 *   @0x1d1fbc cmp r0, #3
 *   @0x1d1fc0 add r3, r3, #1
 *   @0x1d1fc4 add r3, r2, r3
 *   @0x1d1fc8 beq 0x1d1fa0 <_Z13base64_encodePKcjPc+0x140>
 *   @0x1d1fcc rsb r2, r0, #3
 *   @0x1d1fd0 mov r1, #61
 *   @0x1d1fd4 add r2, r3, r2
 *   @0x1d1fd8 strb r1, [r3], #1
 *   @0x1d1fdc cmp r3, r2
 *   @0x1d1fe0 bne 0x1d1fd8 <_Z13base64_encodePKcjPc+0x178>
 *   @0x1d1fe4 b 0x1d1fa4 <_Z13base64_encodePKcjPc+0x144>
 *   @0x1d1fe8 andseq r11, r8, r8, asr pc
 *   @0x1d1fec andseq r11, r8, r8, asr lr
 *
 * ══ §53/69 AddSingleFingerGestures  0x1d8e1c  size 400  100 条（0x1d8e1c..0x1d8fac）
 * @func 0x1d8e1c 0x1d8fac  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Down(int, int) / operator new(unsigned int) / CGesture::CGesture() / GetRawMouseX(int) / GetRawMouseY(int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×6 / 0x40×3 / 0x4×3 / 0x30×2 / 0x34×2 / 0x44×2 / 0x16c×1 / 0x144×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d8e1c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d8e20 vpush {d8}
 *   @0x1d8e24 mov r7, #0
 *   @0x1d8e28 vldr s16, [pc, #364]
 *   @0x1d8e2c ldr r11, [pc, #0x16c]
 *   @0x1d8e30 mov r4, r0
 *   @0x1d8e34 mov r5, r1
 *   @0x1d8e38 mvn r10, #0
 *   @0x1d8e3c add r11, pc, r11
 *   @0x1d8e40 mov r9, r7
 *   @0x1d8e44 mov r0, #1
 *   @0x1d8e48 mov r1, r7
 *   @0x1d8e4c bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d8e50 cmp r0, #0
 *   @0x1d8e54 beq 0x1d8ea4 <_Z23AddSingleFingerGesturesx+0x88>
 *   @0x1d8e58 ldr r8, [pc, #0x144]
 *   @0x1d8e5c ldr r8, [pc, r8]
 *   @0x1d8e60 ldr r6, [r8]
 *   @0x1d8e64 cmp r6, #0
 *   @0x1d8e68 bne 0x1d8e7c <_Z23AddSingleFingerGesturesx+0x60>
 *   @0x1d8e6c b 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c>
 *   @0x1d8e70 ldr r6, [r6]
 *   @0x1d8e74 cmp r6, #0
 *   @0x1d8e78 beq 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c>
 *   @0x1d8e7c ldr r3, [r6, #0x8]
 *   @0x1d8e80 cmp r3, #0
 *   @0x1d8e84 beq 0x1d8eb8 <_Z23AddSingleFingerGesturesx+0x9c>
 *   @0x1d8e88 ldr r0, [r6, #0x8]
 *   @0x1d8e8c mov r1, r7
 *   @0x1d8e90 ldr r3, [r0]
 *   @0x1d8e94 ldr r3, [r3, #0xc]
 *   @0x1d8e98 blx r3
 *   @0x1d8e9c cmp r0, #0
 *   @0x1d8ea0 beq 0x1d8e70 <_Z23AddSingleFingerGesturesx+0x54>
 *   @0x1d8ea4 add r7, r7, #1
 *   @0x1d8ea8 cmp r7, #10
 *   @0x1d8eac bne 0x1d8e44 <_Z23AddSingleFingerGesturesx+0x28>
 *   @0x1d8eb0 vpop {d8}
 *   @0x1d8eb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d8eb8 mov r0, #96
 *   @0x1d8ebc bl 0x27c524 <_Znwj>
 *   @0x1d8ec0 mov r6, r0
 *   @0x1d8ec4 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8ec8 ldr r3, [pc, #0xd8]
 *   @0x1d8ecc vstr s16, [r6, #88]
 *   @0x1d8ed0 str r10, [r6, #0x2c]
 *   @0x1d8ed4 mov r0, r7
 *   @0x1d8ed8 ldr r3, [pc, r3]
 *   @0x1d8edc str r9, [r6, #0x30]
 *   @0x1d8ee0 add r3, r3, #8
 *   @0x1d8ee4 str r9, [r6, #0x34]
 *   @0x1d8ee8 str r3, [r6]
 *   @0x1d8eec str r9, [r6, #0x38]
 *   @0x1d8ef0 str r9, [r6, #0x3c]
 *   @0x1d8ef4 str r9, [r6, #0x48]
 *   @0x1d8ef8 str r9, [r6, #0x4c]
 *   @0x1d8efc str r9, [r6, #0x40]
 *   @0x1d8f00 str r9, [r6, #0x44]
 *   @0x1d8f04 str r9, [r6, #0x8]
 *   @0x1d8f08 str r7, [r6, #0x28]
 *   @0x1d8f0c str r9, [r6, #0x14]
 *   @0x1d8f10 strd r4, r5, [r6, #24]
 *   @0x1d8f14 strd r4, r5, [r6, #32]
 *   @0x1d8f18 bl 0x159e8c <_Z12GetRawMouseXi>
 *   @0x1d8f1c str r0, [r6, #0x40]
 *   @0x1d8f20 mov r0, r7
 *   @0x1d8f24 bl 0x159eec <_Z12GetRawMouseYi>
 *   @0x1d8f28 ldr r3, [r6, #0x40]
 *   @0x1d8f2c ldr r12, [r8, #0x8]
 *   @0x1d8f30 mov r1, r11
 *   @0x1d8f34 str r3, [r6, #0x30]
 *   @0x1d8f38 mov r3, #1
 *   @0x1d8f3c add r12, r12, r3
 *   @0x1d8f40 str r12, [r8, #0x8]
 *   @0x1d8f44 mov r2, r0
 *   @0x1d8f48 mov r0, #12
 *   @0x1d8f4c str r2, [r6, #0x44]
 *   @0x1d8f50 str r2, [r6, #0x34]
 *   @0x1d8f54 mov r2, #143
 *   @0x1d8f58 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d8f5c ldr r3, [r8, #0x4]
 *   @0x1d8f60 cmp r3, #0
 *   @0x1d8f64 str r6, [r0, #0x8]
 *   @0x1d8f68 strne r0, [r3]
 *   @0x1d8f6c strne r3, [r0, #0x4]
 *   @0x1d8f70 strne r0, [r8, #0x4]
 *   @0x1d8f74 strne r9, [r0]
 *   @0x1d8f78 bne 0x1d8ea4 <_Z23AddSingleFingerGesturesx+0x88>
 *   @0x1d8f7c add r7, r7, #1
 *   @0x1d8f80 str r0, [r8, #0x4]
 *   @0x1d8f84 cmp r7, #10
 *   @0x1d8f88 str r0, [r8]
 *   @0x1d8f8c str r3, [r0, #0x4]
 *   @0x1d8f90 str r3, [r0]
 *   @0x1d8f94 bne 0x1d8e44 <_Z23AddSingleFingerGesturesx+0x28>
 *   @0x1d8f98 b 0x1d8eb0 <_Z23AddSingleFingerGesturesx+0x94>
 *   @0x1d8f9c andeq r0, r0, r0
 *   @0x1d8fa0 ldrsheq r3, [r7], -r4
 *   @0x1d8fa4 .word 0x00217db8
 *   @0x1d8fa8 eoreq r7, r1, r8, asr #26
 *
 * ══ §54/69 g_dfmt  0x23f6c4  size 400  100 条（0x23f6c4..0x23f854）
 * @func 0x23f6c4 0x23f854  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: strcp_D2A×2 / gdtoa(FPI*, int, unsigned int*, int*, int, int, int*, char**) / g__fmt_D2A / g_dfmt(char*, double*, int, unsigned int)+0x178
 * 字段偏移 top8: 0x4×3 / 0x20×1 / 0x8×1 / 0x1c×1 / 0xcc×1 / 0xc×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f6c4 bic r2, r2, r2, asr #31
 *   @0x23f6c8 push {r4, r5, r6, r7, lr}
 *   @0x23f6cc mov r5, r3
 *   @0x23f6d0 add r3, r2, #9
 *   @0x23f6d4 sub sp, sp, #44
 *   @0x23f6d8 cmp r3, r5
 *   @0x23f6dc mov r7, r0
 *   @0x23f6e0 bge 0x23f83c <_Z6g_dfmtPcPdij+0x178>
 *   @0x23f6e4 ldr r4, [r1, #0x4]
 *   @0x23f6e8 mov r12, #0
 *   @0x23f6ec movt r12, #0x7ff0
 *   @0x23f6f0 mov r3, #0
 *   @0x23f6f4 and r12, r4, r12
 *   @0x23f6f8 movt r3, #0x7ff0
 *   @0x23f6fc cmp r12, r3
 *   @0x23f700 and r6, r4, #-2147483648
 *   @0x23f704 beq 0x23f7dc <_Z6g_dfmtPcPdij+0x118>
 *   @0x23f708 ldr r3, [r1]
 *   @0x23f70c cmp r3, #0
 *   @0x23f710 beq 0x23f7ac <_Z6g_dfmtPcPdij+0xe8>
 *   @0x23f714 ubfx r1, r4, #0x14, #0xb
 *   @0x23f718 ubfx r4, r4, #0x0, #0x14
 *   @0x23f71c cmp r1, #0
 *   @0x23f720 streq r4, [sp, #0x24]
 *   @0x23f724 subne r1, r1, #1072
 *   @0x23f728 orrne r4, r4, #1048576
 *   @0x23f72c movweq r1, #0xfbce
 *   @0x23f730 subne r1, r1, #3
 *   @0x23f734 movteq r1, #0xffff
 *   @0x23f738 strne r4, [sp, #0x24]
 *   @0x23f73c cmp r2, #0
 *   @0x23f740 str r3, [sp, #0x20]
 *   @0x23f744 str r2, [sp, #0x4]
 *   @0x23f748 add r2, sp, #32
 *   @0x23f74c movne r3, #2
 *   @0x23f750 moveq r3, #0
 *   @0x23f754 cmp r6, #0
 *   @0x23f758 str r3, [sp]
 *   @0x23f75c add r3, sp, #24
 *   @0x23f760 str r3, [sp, #0x8]
 *   @0x23f764 moveq r0, #1
 *   @0x23f768 movne r0, #9
 *   @0x23f76c str r0, [sp, #0x1c]
 *   @0x23f770 add r3, sp, #20
 *   @0x23f774 ldr r0, [pc, #0xcc]
 *   @0x23f778 str r3, [sp, #0xc]
 *   @0x23f77c add r3, sp, #28
 *   @0x23f780 add r0, pc, r0
 *   @0x23f784 bl 0x23dfd0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc>
 *   @0x23f788 ldr r2, [sp, #0x14]
 *   @0x23f78c ldr r3, [sp, #0x18]
 *   @0x23f790 str r6, [sp]
 *   @0x23f794 str r5, [sp, #0x4]
 *   @0x23f798 mov r1, r0
 *   @0x23f79c mov r0, r7
 *   @0x23f7a0 bl 0x23f368 <g__fmt_D2A>
 *   @0x23f7a4 add sp, sp, #44
 *   @0x23f7a8 pop {r4, r5, r6, r7, pc}
 *   @0x23f7ac cmp r4, r6
 *   @0x23f7b0 bne 0x23f714 <_Z6g_dfmtPcPdij+0x50>
 *   @0x23f7b4 cmp r4, #0
 *   @0x23f7b8 mov r2, #48
 *   @0x23f7bc addlt r7, r0, #1
 *   @0x23f7c0 movlt r3, #45
 *   @0x23f7c4 strblt r3, [r0]
 *   @0x23f7c8 mov r3, #0
 *   @0x23f7cc strb r2, [r7]
 *   @0x23f7d0 add r0, r7, #1
 *   @0x23f7d4 strb r3, [r7, #0x1]
 *   @0x23f7d8 b 0x23f7a4 <_Z6g_dfmtPcPdij+0xe0>
 *   @0x23f7dc cmp r5, #9
 *   @0x23f7e0 bls 0x23f83c <_Z6g_dfmtPcPdij+0x178>
 *   @0x23f7e4 ubfx r4, r4, #0x0, #0x14
 *   @0x23f7e8 cmp r4, #0
 *   @0x23f7ec bne 0x23f824 <_Z6g_dfmtPcPdij+0x160>
 *   @0x23f7f0 ldr r3, [r1]
 *   @0x23f7f4 cmp r3, #0
 *   @0x23f7f8 bne 0x23f824 <_Z6g_dfmtPcPdij+0x160>
 *   @0x23f7fc cmp r6, #0
 *   @0x23f800 ldr r1, [pc, #0x44]
 *   @0x23f804 addne r7, r0, #1
 *   @0x23f808 movne r3, #45
 *   @0x23f80c add r1, pc, r1
 *   @0x23f810 strbne r3, [r0]
 *   @0x23f814 mov r0, r7
 *   @0x23f818 bl 0x23db24 <strcp_D2A>
 *   @0x23f81c add sp, sp, #44
 *   @0x23f820 pop {r4, r5, r6, r7, pc}
 *   @0x23f824 ldr r1, [pc, #0x24]
 *   @0x23f828 mov r0, r7
 *   @0x23f82c add r1, pc, r1
 *   @0x23f830 bl 0x23db24 <strcp_D2A>
 *   @0x23f834 add sp, sp, #44
 *   @0x23f838 pop {r4, r5, r6, r7, pc}
 *   @0x23f83c mov r0, #0
 *   @0x23f840 add sp, sp, #44
 *   @0x23f844 pop {r4, r5, r6, r7, pc}
 *   @0x23f848 andseq r7, r11, r0, lsr #24
 *   @0x23f84c andseq r5, r1, r0, ror #23
 *   @0x23f850 andeq r2, pc, r8, asr #25
 *
 * ══ §55/69 Graphics::RestoreRenderTarget  0x183404  size 396  99 条（0x183404..0x183590）
 * @func 0x183404 0x183590  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x183424→0x3f28a4, 0x183460→0x3f26dc, 0x183474→0x479c00, 0x1834c0→0x4a2f4c, 0x1834e4→0x4a2f48, 0x1834e8→0x3f289c, 0x1834f4→0x3f2898, 0x18352c→0x3f23b4
 * 调用序列: countRenderBufferStack()×2 / Graphics::Flush() / Graphics::RestoreRenderTarget()+0xb4 / topRenderBufferStack() / DBG_BIND_FRAMEBUFFER(int) / popRenderBufferStack() / Graphics::RestoreRenderTarget()+0x128
 * 字段偏移 top8: 0x138×2 / 0x90×2 / 0x148×1 / 0x8×1 / 0x104×1 / 0xf4×1 / 0xac×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183404 push {r4, r5, r6, r7, r8, lr}
 *   @0x183408 sub sp, sp, #40
 *   @0x18340c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x183410 ldr r5, [pc, #0x148]
 *   @0x183414 bl 0x1806fc <_Z22countRenderBufferStackv>
 *   @0x183418 add r5, pc, r5
 *   @0x18341c cmp r0, #0
 *   @0x183420 beq 0x183524 <_ZN8Graphics19RestoreRenderTargetEv+0x120>
 *   @0x183424 ldr r3, [pc, #0x138]
 *   @0x183428 ldr r2, [pc, #0x138]
 *   @0x18342c ldr r8, [r5, r3]
 *   @0x183430 add r2, pc, r2
 *   @0x183434 add r1, r2, #4
 *   @0x183438 ldr r3, [r2]
 *   @0x18343c ldr r2, [r8]
 *   @0x183440 rsb r3, r3, r3, lsl #3
 *   @0x183444 cmp r2, #1
 *   @0x183448 add r6, r1, r3, lsl #2
 *   @0x18344c movwgt r4, #0x8ce1
 *   @0x183450 movgt r7, #0
 *   @0x183454 ble 0x1834b8 <_ZN8Graphics19RestoreRenderTargetEv+0xb4>
 *   @0x183458 ldr r3, [r6, #0x8]
 *   @0x18345c add r6, r6, #4
 *   @0x183460 ldr r12, [pc, #0x104]
 *   @0x183464 cmp r3, #0
 *   @0x183468 beq 0x1834a0 <_ZN8Graphics19RestoreRenderTargetEv+0x9c>
 *   @0x18346c ldr r12, [r5, r12]
 *   @0x183470 mov r1, r4
 *   @0x183474 ldr lr, [pc, #0xf4]
 *   @0x183478 movw r0, #0x8d40
 *   @0x18347c movw r2, #0xde1
 *   @0x183480 mov r3, #0
 *   @0x183484 ldr r12, [r12]
 *   @0x183488 cmp r12, #1
 *   @0x18348c beq 0x183548 <_ZN8Graphics19RestoreRenderTargetEv+0x144>
 *   @0x183490 ldr r12, [r5, lr]
 *   @0x183494 str r7, [sp]
 *   @0x183498 ldr r12, [r12]
 *   @0x18349c blx r12
 *   @0x1834a0 sub r3, r4, #35840
 *   @0x1834a4 ldr r2, [r8]
 *   @0x1834a8 sub r3, r3, #223
 *   @0x1834ac add r4, r4, #1
 *   @0x1834b0 cmp r2, r3
 *   @0x1834b4 bgt 0x183458 <_ZN8Graphics19RestoreRenderTargetEv+0x54>
 *   @0x1834b8 add r0, sp, #12
 *   @0x1834bc bl 0x1807ec <_Z20topRenderBufferStackv>
 *   @0x1834c0 ldr r3, [pc, #0xac]
 *   @0x1834c4 ldr r4, [sp, #0xc]
 *   @0x1834c8 movw r2, #0x87f
 *   @0x1834cc ldr r1, [pc, #0xa4]
 *   @0x1834d0 ldr r3, [r5, r3]
 *   @0x1834d4 mov r0, r4
 *   @0x1834d8 add r1, pc, r1
 *   @0x1834dc stm r3, {r1, r2}
 *   @0x1834e0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x1834e4 ldr r3, [pc, #0x90]
 *   @0x1834e8 ldr r1, [pc, #0x90]
 *   @0x1834ec ldr r0, [sp, #0x20]
 *   @0x1834f0 ldr r12, [r5, r3]
 *   @0x1834f4 ldr r3, [pc, #0x88]
 *   @0x1834f8 ldr r2, [sp, #0x24]
 *   @0x1834fc str r4, [r12]
 *   @0x183500 ldr r1, [r5, r1]
 *   @0x183504 str r0, [r1]
 *   @0x183508 ldr r3, [r5, r3]
 *   @0x18350c str r2, [r3]
 *   @0x183510 bl 0x1807a8 <_Z20popRenderBufferStackv>
 *   @0x183514 bl 0x1806fc <_Z22countRenderBufferStackv>
 *   @0x183518 cmp r0, #0
 *   @0x18351c movgt r0, #1
 *   @0x183520 ble 0x18352c <_ZN8Graphics19RestoreRenderTargetEv+0x128>
 *   @0x183524 add sp, sp, #40
 *   @0x183528 pop {r4, r5, r6, r7, r8, pc}
 *   @0x18352c ldr r2, [pc, #0x54]
 *   @0x183530 mov r3, #1
 *   @0x183534 mov r0, r3
 *   @0x183538 ldr r2, [r5, r2]
 *   @0x18353c str r3, [r2]
 *   @0x183540 add sp, sp, #40
 *   @0x183544 pop {r4, r5, r6, r7, r8, pc}
 *   @0x183548 ldr r12, [pc, #0x3c]
 *   @0x18354c ldr r12, [r5, r12]
 *   @0x183550 str r7, [sp]
 *   @0x183554 ldr r12, [r12]
 *   @0x183558 blx r12
 *   @0x18355c b 0x1834a0 <_ZN8Graphics19RestoreRenderTargetEv+0x9c>
 *   @0x183560 eoreq lr, r6, r8, lsr r8
 *   @0x183564 .word 0xffffe8e0
 *   @0x183568 eorseq lr, r1, r12, asr #31
 *   @0x18356c .word 0xffffe7b8
 *   @0x183570 .word 0xffffbc7c
 *   @0x183574 .word 0xffffe81c
 *   @0x183578 andseq r8, r12, r4, ror #9
 *   @0x18357c .word 0xffffe820
 *   @0x183580 .word 0xffffe834
 *   @0x183584 .word 0xffffe838
 *   @0x183588 .word 0xffffe48c
 *   @0x18358c .word 0xffffbb6c
 *
 * ══ §56/69 CreateList  0x19e650  size 396  99 条（0x19e650..0x19e7dc）
 * @func 0x19e650 0x19e7dc  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19e658→0x536f70, 0x19e6a8→0x53ab70, 0x19e6bc→0x542370, 0x19e6d8→0x542374
 * 调用序列: CreateList(int, int)+0x140 / CreateList(int, int)+0x128 / CObjectGM::GetEventRecursive(int, int) / CreateList(int, int)+0x9c / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0xc×4 / 0x16c×1 / 0x168×1 / 0x124×1 / 0x120×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e650 ldr r12, [pc, #0x16c]
 *   @0x19e654 mov r3, #0
 *   @0x19e658 ldr r2, [pc, #0x168]
 *   @0x19e65c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19e660 add r12, pc, r12
 *   @0x19e664 sub sp, sp, #20
 *   @0x19e668 mov r9, r0
 *   @0x19e66c lsl r0, r0, #10
 *   @0x19e670 str r12, [sp, #0x8]
 *   @0x19e674 str r1, [sp, #0xc]
 *   @0x19e678 mov r1, r3
 *   @0x19e67c ldr r5, [r12, r2]
 *   @0x19e680 add r2, r5, r0
 *   @0x19e684 str r1, [r2, r3]
 *   @0x19e688 add r3, r3, #4
 *   @0x19e68c cmp r3, #1024
 *   @0x19e690 bne 0x19e684 <_Z10CreateListii+0x34>
 *   @0x19e694 ldr r12, [sp, #0xc]
 *   @0x19e698 cmp r12, #0
 *   @0x19e69c blt 0x19e790 <_Z10CreateListii+0x140>
 *   @0x19e6a0 ldr r12, [pc, #0x124]
 *   @0x19e6a4 add r5, r5, r0
 *   @0x19e6a8 ldr r2, [pc, #0x120]
 *   @0x19e6ac mov r8, #0
 *   @0x19e6b0 add r12, pc, r12
 *   @0x19e6b4 str r12, [sp, #0x4]
 *   @0x19e6b8 ldr r12, [sp, #0x8]
 *   @0x19e6bc ldr r3, [pc, #0x110]
 *   @0x19e6c0 ldr r6, [r12, r2]
 *   @0x19e6c4 ldr r7, [r12, r3]
 *   @0x19e6c8 add r6, r6, r9, lsl #11
 *   @0x19e6cc ldr r3, [r7]
 *   @0x19e6d0 cmp r3, #0
 *   @0x19e6d4 ble 0x19e778 <_Z10CreateListii+0x128>
 *   @0x19e6d8 ldr r3, [pc, #0xf8]
 *   @0x19e6dc add r10, r6, #4
 *   @0x19e6e0 ldr r12, [sp, #0x8]
 *   @0x19e6e4 mov r4, #0
 *   @0x19e6e8 ldr r11, [r12, r3]
 *   @0x19e6ec ldr r3, [r11]
 *   @0x19e6f0 ldr r2, [r3, #0x4]
 *   @0x19e6f4 ldr r3, [r3]
 *   @0x19e6f8 and r2, r4, r2
 *   @0x19e6fc ldr r3, [r3, r2, lsl #3]
 *   @0x19e700 cmp r3, #0
 *   @0x19e704 bne 0x19e718 <_Z10CreateListii+0xc8>
 *   @0x19e708 b 0x19e768 <_Z10CreateListii+0x118>
 *   @0x19e70c ldr r3, [r3, #0x4]
 *   @0x19e710 cmp r3, #0
 *   @0x19e714 beq 0x19e768 <_Z10CreateListii+0x118>
 *   @0x19e718 ldr r2, [r3, #0x8]
 *   @0x19e71c cmp r4, r2
 *   @0x19e720 bne 0x19e70c <_Z10CreateListii+0xbc>
 *   @0x19e724 ldr r0, [r3, #0xc]
 *   @0x19e728 cmp r0, #0
 *   @0x19e72c beq 0x19e768 <_Z10CreateListii+0x118>
 *   @0x19e730 mov r1, r9
 *   @0x19e734 mov r2, r8
 *   @0x19e738 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii>
 *   @0x19e73c cmp r0, #0
 *   @0x19e740 beq 0x19e768 <_Z10CreateListii+0x118>
 *   @0x19e744 ldr r3, [r5]
 *   @0x19e748 ldr r2, [r6]
 *   @0x19e74c cmp r3, r2
 *   @0x19e750 bge 0x19e798 <_Z10CreateListii+0x148>
 *   @0x19e754 ldr r2, [r6, #0x4]
 *   @0x19e758 str r4, [r2, r3, lsl #2]
 *   @0x19e75c ldr r3, [r5]
 *   @0x19e760 add r3, r3, #1
 *   @0x19e764 str r3, [r5]
 *   @0x19e768 ldr r3, [r7]
 *   @0x19e76c add r4, r4, #1
 *   @0x19e770 cmp r4, r3
 *   @0x19e774 blt 0x19e6ec <_Z10CreateListii+0x9c>
 *   @0x19e778 ldr r12, [sp, #0xc]
 *   @0x19e77c add r8, r8, #1
 *   @0x19e780 add r5, r5, #4
 *   @0x19e784 add r6, r6, #8
 *   @0x19e788 cmp r12, r8
 *   @0x19e78c bge 0x19e6cc <_Z10CreateListii+0x7c>
 *   @0x19e790 add sp, sp, #20
 *   @0x19e794 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19e798 add r1, r3, #5
 *   @0x19e79c ldr r2, [sp, #0x4]
 *   @0x19e7a0 mov r3, #156
 *   @0x19e7a4 mov r0, r10
 *   @0x19e7a8 lsl r1, r1, #2
 *   @0x19e7ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19e7b0 ldr r2, [r6]
 *   @0x19e7b4 ldr r3, [r5]
 *   @0x19e7b8 add r2, r2, #5
 *   @0x19e7bc str r2, [r6]
 *   @0x19e7c0 b 0x19e754 <_Z10CreateListii+0x104>
 *   @0x19e7c4 .word 0x002535f0
 *   @0x19e7c8 .word 0xffffdeb8
 *   @0x19e7cc ldrheq lr, [r10], -r0
 *   @0x19e7d0 .word 0xffffdebc
 *   @0x19e7d4 .word 0xffffea94
 *   @0x19e7d8 .word 0xffffbfec
 *
 * ══ §57/69 ChangeInstanceDepths  0x1d2ee8  size 396  99 条（0x1d2ee8..0x1d3074）
 * @func 0x1d2ee8 0x1d3074  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ChangeInstanceDepths()+0x124×2
 * 字段偏移 top8: 0x178×6 / 0x17c×6 / 0x88×4 / 0x8×3 / 0x80×3 / 0x2×2 / 0x69×2 / 0x84×2
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d2ee8 push {r4, r5, r6, r7, r8}
 *   @0x1d2eec ldr r5, [pc, #0x178]
 *   @0x1d2ef0 ldr r5, [pc, r5]
 *   @0x1d2ef4 ldr r0, [r5, #0x8]
 *   @0x1d2ef8 cmp r0, #0
 *   @0x1d2efc ble 0x1d300c <_Z20ChangeInstanceDepthsv+0x124>
 *   @0x1d2f00 ldr r8, [pc, #0x168]
 *   @0x1d2f04 mov r3, #0
 *   @0x1d2f08 ldr r12, [r5]
 *   @0x1d2f0c mov r7, r3
 *   @0x1d2f10 ldr r8, [pc, r8]
 *   @0x1d2f14 ldr r6, [r8]
 *   @0x1d2f18 b 0x1d2f28 <_Z20ChangeInstanceDepthsv+0x40>
 *   @0x1d2f1c add r3, r3, #1
 *   @0x1d2f20 cmp r3, r0
 *   @0x1d2f24 beq 0x1d2f80 <_Z20ChangeInstanceDepthsv+0x98>
 *   @0x1d2f28 ldr r2, [r12, r3, lsl #2]
 *   @0x1d2f2c ldrb r1, [r2, #0x69]
 *   @0x1d2f30 cmp r1, #0
 *   @0x1d2f34 bne 0x1d2f1c <_Z20ChangeInstanceDepthsv+0x34>
 *   @0x1d2f38 ldr r1, [r2, #0x17c]
 *   @0x1d2f3c add r3, r3, #1
 *   @0x1d2f40 ldr r4, [r2, #0x178]
 *   @0x1d2f44 cmp r1, #0
 *   @0x1d2f48 strne r4, [r1, #0x178]
 *   @0x1d2f4c ldrne r1, [r2, #0x17c]
 *   @0x1d2f50 ldrne r4, [r2, #0x178]
 *   @0x1d2f54 streq r4, [r6, #0x80]
 *   @0x1d2f58 cmp r4, #0
 *   @0x1d2f5c streq r1, [r6, #0x84]
 *   @0x1d2f60 strne r1, [r4, #0x17c]
 *   @0x1d2f64 cmp r3, r0
 *   @0x1d2f68 ldr r1, [r6, #0x88]
 *   @0x1d2f6c str r7, [r2, #0x178]
 *   @0x1d2f70 str r7, [r2, #0x17c]
 *   @0x1d2f74 sub r2, r1, #1
 *   @0x1d2f78 str r2, [r6, #0x88]
 *   @0x1d2f7c bne 0x1d2f28 <_Z20ChangeInstanceDepthsv+0x40>
 *   @0x1d2f80 ldr r0, [r8]
 *   @0x1d2f84 mov r2, #0
 *   @0x1d2f88 ldr r4, [r5]
 *   @0x1d2f8c ldr r12, [r5, #0x8]
 *   @0x1d2f90 b 0x1d2fa0 <_Z20ChangeInstanceDepthsv+0xb8>
 *   @0x1d2f94 add r2, r2, #1
 *   @0x1d2f98 cmp r12, r2
 *   @0x1d2f9c ble 0x1d300c <_Z20ChangeInstanceDepthsv+0x124>
 *   @0x1d2fa0 ldr r1, [r4, r2, lsl #2]
 *   @0x1d2fa4 ldrb r3, [r1, #0x69]
 *   @0x1d2fa8 cmp r3, #0
 *   @0x1d2fac bne 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac>
 *   @0x1d2fb0 ldr r3, [r0, #0x84]
 *   @0x1d2fb4 ldr r6, [r0, #0x88]
 *   @0x1d2fb8 cmp r3, #0
 *   @0x1d2fbc vldrne s14, [r1, #384]
 *   @0x1d2fc0 add r6, r6, #1
 *   @0x1d2fc4 str r6, [r0, #0x88]
 *   @0x1d2fc8 beq 0x1d3050 <_Z20ChangeInstanceDepthsv+0x168>
 *   @0x1d2fcc vldr s15, [r3, #388]
 *   @0x1d2fd0 vcmpe.f32 s14, s15
 *   @0x1d2fd4 vmrs APSR_nzcv, fpscr
 *   @0x1d2fd8 bge 0x1d301c <_Z20ChangeInstanceDepthsv+0x134>
 *   @0x1d2fdc ldr r3, [r3, #0x17c]
 *   @0x1d2fe0 cmp r3, #0
 *   @0x1d2fe4 bne 0x1d2fcc <_Z20ChangeInstanceDepthsv+0xe4>
 *   @0x1d2fe8 ldr r6, [r0, #0x80]
 *   @0x1d2fec add r2, r2, #1
 *   @0x1d2ff0 cmp r12, r2
 *   @0x1d2ff4 vstr s14, [r1, #388]
 *   @0x1d2ff8 str r1, [r6, #0x17c]
 *   @0x1d2ffc str r6, [r1, #0x178]
 *   @0x1d3000 str r1, [r0, #0x80]
 *   @0x1d3004 str r3, [r1, #0x17c]
 *   @0x1d3008 bgt 0x1d2fa0 <_Z20ChangeInstanceDepthsv+0xb8>
 *   @0x1d300c mov r3, #0
 *   @0x1d3010 str r3, [r5, #0x8]
 *   @0x1d3014 pop {r4, r5, r6, r7, r8}
 *   @0x1d3018 bx lr
 *   @0x1d301c ldr r6, [r3, #0x178]
 *   @0x1d3020 cmp r6, #0
 *   @0x1d3024 streq r3, [r1, #0x17c]
 *   @0x1d3028 strne r6, [r1, #0x178]
 *   @0x1d302c ldrne r6, [r3, #0x178]
 *   @0x1d3030 streq r1, [r3, #0x178]
 *   @0x1d3034 strne r3, [r1, #0x17c]
 *   @0x1d3038 streq r1, [r0, #0x84]
 *   @0x1d303c strne r1, [r6, #0x17c]
 *   @0x1d3040 streq r6, [r1, #0x178]
 *   @0x1d3044 strne r1, [r3, #0x178]
 *   @0x1d3048 vstr s14, [r1, #388]
 *   @0x1d304c b 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac>
 *   @0x1d3050 ldr r6, [r1, #0x180]
 *   @0x1d3054 str r1, [r0, #0x84]
 *   @0x1d3058 str r1, [r0, #0x80]
 *   @0x1d305c str r6, [r1, #0x184]
 *   @0x1d3060 str r3, [r1, #0x17c]
 *   @0x1d3064 str r3, [r1, #0x178]
 *   @0x1d3068 b 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac>
 *   @0x1d306c .word 0x0021b1b4
 *   @0x1d3070 eoreq r10, r1, r8, lsl r10
 *
 * ══ §58/69 CPhysicsWorld::BuildCollisionBits  0x238718  size 396  99 条（0x238718..0x2388a4）
 * @func 0x238718 0x2388a4  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::BuildCollisionBits(int)+0x174 / CPhysicsWorld::FindBaseObjectForCollisions(int, int) / CPhysicsWorld::AssignCollisionCategory(int) / CPhysicsWorld::BuildCollisionBits(int)+0xe8 / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x-30×2 / 0x-28×2 / 0x6c×2 / 0x70×2 / 0x64×2 / 0x170×1 / 0x16c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238718 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23871c add r11, sp, #32
 *   @0x238720 ldr r3, [pc, #0x170]
 *   @0x238724 sub sp, sp, #20
 *   @0x238728 ldr r5, [pc, #0x16c]
 *   @0x23872c ldr r3, [pc, r3]
 *   @0x238730 mov r8, r0
 *   @0x238734 ldr r5, [pc, r5]
 *   @0x238738 str r5, [r11, #-0x30]
 *   @0x23873c ldr r2, [r3]
 *   @0x238740 ldr r12, [r5]
 *   @0x238744 cmp r2, #0
 *   @0x238748 lsl r0, r2, #2
 *   @0x23874c add r3, r0, #14
 *   @0x238750 str r12, [r11, #-0x28]
 *   @0x238754 bic r3, r3, #7
 *   @0x238758 sub sp, sp, r3
 *   @0x23875c mov r10, sp
 *   @0x238760 ble 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174>
 *   @0x238764 ldr r3, [pc, #0x134]
 *   @0x238768 add r0, r0, r2
 *   @0x23876c mov r2, #0
 *   @0x238770 ldr r3, [pc, r3]
 *   @0x238774 lsl r4, r0, #2
 *   @0x238778 mov r7, r2
 *   @0x23877c ldr r12, [r3, #0x4]
 *   @0x238780 b 0x238798 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x80>
 *   @0x238784 cmp r3, r1
 *   @0x238788 beq 0x238878 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x160>
 *   @0x23878c add r2, r2, #20
 *   @0x238790 cmp r2, r4
 *   @0x238794 beq 0x2387c4 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xac>
 *   @0x238798 mov r3, r12
 *   @0x23879c ldr r0, [r3, r2]!
 *   @0x2387a0 cmp r0, r1
 *   @0x2387a4 ldr r3, [r3, #0x4]
 *   @0x2387a8 bne 0x238784 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x6c>
 *   @0x2387ac cmn r3, #1
 *   @0x2387b0 strne r3, [r10, r7, lsl #2]
 *   @0x2387b4 addne r7, r7, #1
 *   @0x2387b8 add r2, r2, #20
 *   @0x2387bc cmp r2, r4
 *   @0x2387c0 bne 0x238798 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x80>
 *   @0x2387c4 cmp r7, #0
 *   @0x2387c8 beq 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174>
 *   @0x2387cc mov r2, r7
 *   @0x2387d0 mov r0, r8
 *   @0x2387d4 bl 0x238598 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii>
 *   @0x2387d8 mov r1, r0
 *   @0x2387dc mov r0, r8
 *   @0x2387e0 bl 0x2384bc <_ZN13CPhysicsWorld23AssignCollisionCategoryEi>
 *   @0x2387e4 cmn r0, #1
 *   @0x2387e8 beq 0x23888c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x174>
 *   @0x2387ec add r4, r0, r0, lsl #1
 *   @0x2387f0 sub r10, r10, #4
 *   @0x2387f4 add r12, r8, #384
 *   @0x2387f8 mov r2, #0
 *   @0x2387fc add r4, r8, r4, lsl #2
 *   @0x238800 ldr r1, [r10, #0x4]!
 *   @0x238804 mov r3, r8
 *   @0x238808 b 0x238818 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x100>
 *   @0x23880c add r3, r3, #12
 *   @0x238810 cmp r3, r12
 *   @0x238814 beq 0x238850 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x138>
 *   @0x238818 ldr r5, [r3, #0x68]
 *   @0x23881c cmp r5, r1
 *   @0x238820 bne 0x23880c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xf4>
 *   @0x238824 ldr r6, [r3, #0x6c]
 *   @0x238828 add r3, r3, #12
 *   @0x23882c ldr r9, [r4, #0x70]
 *   @0x238830 orr r5, r6, r9
 *   @0x238834 ldr r6, [r4, #0x6c]
 *   @0x238838 str r5, [r4, #0x70]
 *   @0x23883c ldr r5, [r3, #0x64]
 *   @0x238840 orr r5, r5, r6
 *   @0x238844 str r5, [r3, #0x64]
 *   @0x238848 cmp r3, r12
 *   @0x23884c bne 0x238818 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x100>
 *   @0x238850 add r2, r2, #1
 *   @0x238854 cmp r2, r7
 *   @0x238858 blt 0x238800 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xe8>
 *   @0x23885c ldr r9, [r11, #-0x30]
 *   @0x238860 ldr r2, [r11, #-0x28]
 *   @0x238864 ldr r3, [r9]
 *   @0x238868 cmp r2, r3
 *   @0x23886c bne 0x238894 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x17c>
 *   @0x238870 sub sp, r11, #32
 *   @0x238874 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x238878 mov r3, r0
 *   @0x23887c cmn r3, #1
 *   @0x238880 strne r3, [r10, r7, lsl #2]
 *   @0x238884 addne r7, r7, #1
 *   @0x238888 b 0x2387b8 <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0xa0>
 *   @0x23888c mvn r0, #0
 *   @0x238890 b 0x23885c <_ZN13CPhysicsWorld18BuildCollisionBitsEi+0x144>
 *   @0x238894 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x238898 ldrheq r7, [r11], -r0
 *   @0x23889c andseq r5, r11, r12, lsl r2
 *   @0x2388a0 andseq r7, r11, r0, ror pc
 *
 * ══ §59/69 MemoryManager::ReAlloc  0x27cedc  size 396  99 条（0x27cedc..0x27d068）
 * @func 0x27cedc 0x27d068  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Mutex::Lock() / bucketSize(void const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)+0x88 / 0xb6c88 / Mutex::Unlock() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x118×2 / 0x160×1 / 0x-c×1 / 0x-10×1 / 0x-4×1 / 0xc×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27cedc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x27cee0 subs r5, r0, #0
 *   @0x27cee4 mov r7, r1
 *   @0x27cee8 mov r9, r2
 *   @0x27ceec mov r8, r3
 *   @0x27cef0 beq 0x27d038 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x15c>
 *   @0x27cef4 ldr r4, [pc, #0x160]
 *   @0x27cef8 ldr r4, [pc, r4]
 *   @0x27cefc ldr r0, [r4]
 *   @0x27cf00 cmp r0, #0
 *   @0x27cf04 beq 0x27d050 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x174>
 *   @0x27cf08 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27cf0c mov r0, r5
 *   @0x27cf10 bl 0x27c1e4 <_Z10bucketSizePKv>
 *   @0x27cf14 subs r6, r0, #0
 *   @0x27cf18 bne 0x27cfa0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xc4>
 *   @0x27cf1c ldr r2, [r5, #-0xc]
 *   @0x27cf20 movw r3, #0xc0de
 *   @0x27cf24 movt r3, #0xdead
 *   @0x27cf28 ldr r6, [r5, #-0x10]
 *   @0x27cf2c cmp r2, r3
 *   @0x27cf30 beq 0x27d020 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x144>
 *   @0x27cf34 ldr r6, [r5, #-0x4]
 *   @0x27cf38 cmp r6, #0
 *   @0x27cf3c blt 0x27cf64 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x88>
 *   @0x27cf40 ldr r3, [pc, #0x118]
 *   @0x27cf44 ldr r1, [pc, #0x118]
 *   @0x27cf48 ldr r3, [pc, r3]
 *   @0x27cf4c add r1, pc, r1
 *   @0x27cf50 ldr r0, [r3]
 *   @0x27cf54 ldr r3, [r0]
 *   @0x27cf58 ldr r3, [r3, #0xc]
 *   @0x27cf5c blx r3
 *   @0x27cf60 bl 0xb6c88 <abort@plt>
 *   @0x27cf64 bic r3, r6, #-2147483648
 *   @0x27cf68 cmp r3, #8192
 *   @0x27cf6c bhs 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64>
 *   @0x27cf70 sub r1, r5, #16
 *   @0x27cf74 movw r2, #0xc0de
 *   @0x27cf78 rsb r3, r3, r1
 *   @0x27cf7c movt r2, #0xdead
 *   @0x27cf80 ldr r1, [r3, #0x4]
 *   @0x27cf84 cmp r1, r2
 *   @0x27cf88 bne 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64>
 *   @0x27cf8c ldr r2, [r3, #0x8]
 *   @0x27cf90 movw r3, #0xb00b
 *   @0x27cf94 movt r3, #0xbaad
 *   @0x27cf98 cmp r2, r3
 *   @0x27cf9c bne 0x27cf40 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x64>
 *   @0x27cfa0 cmp r6, r7
 *   @0x27cfa4 movhs r8, r5
 *   @0x27cfa8 bhs 0x27cfc0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xe4>
 *   @0x27cfac cmp r7, #0
 *   @0x27cfb0 bne 0x27cfd0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xf4>
 *   @0x27cfb4 mov r0, r5
 *   @0x27cfb8 mov r8, r7
 *   @0x27cfbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27cfc0 ldr r0, [r4]
 *   @0x27cfc4 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27cfc8 mov r0, r8
 *   @0x27cfcc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x27cfd0 mov r3, #1
 *   @0x27cfd4 mov r1, r9
 *   @0x27cfd8 mov r2, r8
 *   @0x27cfdc mov r0, r7
 *   @0x27cfe0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27cfe4 rsb r2, r6, r7
 *   @0x27cfe8 mov r1, #0
 *   @0x27cfec mov r9, r0
 *   @0x27cff0 add r0, r0, r6
 *   @0x27cff4 bl 0xb65b0 <memset@plt>
 *   @0x27cff8 mov r0, r9
 *   @0x27cffc mov r1, r5
 *   @0x27d000 cmp r6, r7
 *   @0x27d004 movlo r2, r6
 *   @0x27d008 movhs r2, r7
 *   @0x27d00c bl 0xb65bc <memcpy@plt>
 *   @0x27d010 mov r0, r5
 *   @0x27d014 mov r8, r9
 *   @0x27d018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x27d01c b 0x27cfc0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xe4>
 *   @0x27d020 ldr r2, [r5, #-0x8]
 *   @0x27d024 movw r3, #0xb00b
 *   @0x27d028 movt r3, #0xbaad
 *   @0x27d02c cmp r2, r3
 *   @0x27d030 bne 0x27cf34 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x58>
 *   @0x27d034 b 0x27cfa0 <_ZN13MemoryManager7ReAllocEPvjPKcib+0xc4>
 *   @0x27d038 mov r0, r1
 *   @0x27d03c mov r1, r2
 *   @0x27d040 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x27d044 mov r2, r3
 *   @0x27d048 mov r3, #1
 *   @0x27d04c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d050 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27d054 ldr r0, [r4]
 *   @0x27d058 b 0x27cf08 <_ZN13MemoryManager7ReAllocEPvjPKcib+0x2c>
 *   @0x27d05c andseq r4, r7, r4, lsr #18
 *   @0x27d060 andseq r0, r7, r12, asr #15
 *   @0x27d064 strdeq r10, r11, [sp], -r0
 *
 * ══ §60/69 spPolygon_intersectsSegment  0x28a6a8  size 396  99 条（0x28a6a8..0x28a834）
 * @func 0x28a6a8 0x28a834  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spPolygon_intersectsSegment+0x17c×2 / spPolygon_intersectsSegment+0x154×2 / spPolygon_intersectsSegment+0x114 / spPolygon_intersectsSegment+0x138 / spPolygon_intersectsSegment+0x64 / spPolygon_intersectsSegment+0xc4 / spPolygon_intersectsSegment+0x94
 * 字段偏移 top8: 0x4×1
 * VFP 指令 60 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a6a8 vmov s1, r2
 *   @0x28a6ac ldr r12, [r0, #0x4]
 *   @0x28a6b0 vmov s2, r3
 *   @0x28a6b4 ldr r3, [r0]
 *   @0x28a6b8 vmov s3, r1
 *   @0x28a6bc sub r2, r12, #-1073741822
 *   @0x28a6c0 vmul.f32 s5, s1, s2
 *   @0x28a6c4 cmp r12, #0
 *   @0x28a6c8 vldr s0, [sp]
 *   @0x28a6cc add r2, r3, r2, lsl #2
 *   @0x28a6d0 vldr s13, [r2]
 *   @0x28a6d4 vldr s9, [r2, #4]
 *   @0x28a6d8 vnmls.f32 s5, s3, s0
 *   @0x28a6dc vsub.f32 s6, s3, s2
 *   @0x28a6e0 vsub.f32 s4, s1, s0
 *   @0x28a6e4 ble 0x28a824 <spPolygon_intersectsSegment+0x17c>
 *   @0x28a6e8 add r3, r3, #4
 *   @0x28a6ec mov r2, #0
 *   @0x28a6f0 b 0x28a784 <spPolygon_intersectsSegment+0xdc>
 *   @0x28a6f4 vcmpe.f32 s15, s14
 *   @0x28a6f8 vmrs APSR_nzcv, fpscr
 *   @0x28a6fc blt 0x28a7bc <spPolygon_intersectsSegment+0x114>
 *   @0x28a700 vcmpe.f32 s3, s14
 *   @0x28a704 vmrs APSR_nzcv, fpscr
 *   @0x28a708 bhi 0x28a7e0 <spPolygon_intersectsSegment+0x138>
 *   @0x28a70c vcmpe.f32 s2, s14
 *   @0x28a710 vmrs APSR_nzcv, fpscr
 *   @0x28a714 blt 0x28a7e0 <spPolygon_intersectsSegment+0x138>
 *   @0x28a718 vmul.f32 s10, s4, s10
 *   @0x28a71c vnmls.f32 s10, s5, s7
 *   @0x28a720 vdiv.f32 s11, s10, s11
 *   @0x28a724 vcmpe.f32 s11, s9
 *   @0x28a728 vmrs APSR_nzcv, fpscr
 *   @0x28a72c blt 0x28a7fc <spPolygon_intersectsSegment+0x154>
 *   @0x28a730 vcmpe.f32 s12, s11
 *   @0x28a734 vmrs APSR_nzcv, fpscr
 *   @0x28a738 blt 0x28a7fc <spPolygon_intersectsSegment+0x154>
 *   @0x28a73c vcmpe.f32 s1, s11
 *   @0x28a740 vmrs APSR_nzcv, fpscr
 *   @0x28a744 bhi 0x28a754 <spPolygon_intersectsSegment+0xac>
 *   @0x28a748 vcmpe.f32 s0, s11
 *   @0x28a74c vmrs APSR_nzcv, fpscr
 *   @0x28a750 bge 0x28a82c <spPolygon_intersectsSegment+0x184>
 *   @0x28a754 vcmpe.f32 s0, s11
 *   @0x28a758 vmrs APSR_nzcv, fpscr
 *   @0x28a75c bhi 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a760 vcmpe.f32 s1, s11
 *   @0x28a764 vmrs APSR_nzcv, fpscr
 *   @0x28a768 bge 0x28a82c <spPolygon_intersectsSegment+0x184>
 *   @0x28a76c add r2, r2, #2
 *   @0x28a770 add r3, r3, #8
 *   @0x28a774 cmp r12, r2
 *   @0x28a778 ble 0x28a824 <spPolygon_intersectsSegment+0x17c>
 *   @0x28a77c vmov.f32 s9, s12
 *   @0x28a780 vmov.f32 s13, s15
 *   @0x28a784 vldr s15, [r3, #-4]
 *   @0x28a788 vldr s12, [r3]
 *   @0x28a78c vmul.f32 s10, s9, s15
 *   @0x28a790 vnmls.f32 s10, s13, s12
 *   @0x28a794 vsub.f32 s8, s13, s15
 *   @0x28a798 vmul.f32 s14, s6, s10
 *   @0x28a79c vmul.f32 s11, s4, s8
 *   @0x28a7a0 vsub.f32 s7, s9, s12
 *   @0x28a7a4 vnmls.f32 s14, s5, s8
 *   @0x28a7a8 vnmls.f32 s11, s6, s7
 *   @0x28a7ac vdiv.f32 s14, s14, s11
 *   @0x28a7b0 vcmpe.f32 s14, s13
 *   @0x28a7b4 vmrs APSR_nzcv, fpscr
 *   @0x28a7b8 bge 0x28a6f4 <spPolygon_intersectsSegment+0x4c>
 *   @0x28a7bc vcmpe.f32 s15, s14
 *   @0x28a7c0 vmrs APSR_nzcv, fpscr
 *   @0x28a7c4 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a7c8 vcmpe.f32 s14, s13
 *   @0x28a7cc vmrs APSR_nzcv, fpscr
 *   @0x28a7d0 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a7d4 vcmpe.f32 s3, s14
 *   @0x28a7d8 vmrs APSR_nzcv, fpscr
 *   @0x28a7dc bls 0x28a70c <spPolygon_intersectsSegment+0x64>
 *   @0x28a7e0 vcmpe.f32 s2, s14
 *   @0x28a7e4 vmrs APSR_nzcv, fpscr
 *   @0x28a7e8 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a7ec vcmpe.f32 s3, s14
 *   @0x28a7f0 vmrs APSR_nzcv, fpscr
 *   @0x28a7f4 blt 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a7f8 b 0x28a718 <spPolygon_intersectsSegment+0x70>
 *   @0x28a7fc vcmpe.f32 s12, s11
 *   @0x28a800 vmrs APSR_nzcv, fpscr
 *   @0x28a804 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4>
 *   @0x28a808 vcmpe.f32 s11, s9
 *   @0x28a80c vmrs APSR_nzcv, fpscr
 *   @0x28a810 bls 0x28a73c <spPolygon_intersectsSegment+0x94>
 *   @0x28a814 add r2, r2, #2
 *   @0x28a818 add r3, r3, #8
 *   @0x28a81c cmp r12, r2
 *   @0x28a820 bgt 0x28a77c <spPolygon_intersectsSegment+0xd4>
 *   @0x28a824 mov r0, #0
 *   @0x28a828 bx lr
 *   @0x28a82c mov r0, #1
 *   @0x28a830 bx lr
 *
 * ══ §61/69 YYObjectBase::Free  0x198f88  size 392  98 条（0x198f88..0x199110）
 * @func 0x198f88 0x199110  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x198fa0→0x536f0c, 0x199014→0x536f1c, 0x199040→0x3f5050
 * 调用序列: YYObjectBase::FreeVars(YYObjectBase*, RValue**, RValue**, RVariable**, RVariable**) / JS_GetProperty(YYObjectBase*, RValue*, char const*) / JS_IsCallable(RValue&) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 * 字段偏移 top8: 0x8×5 / 0x44×3 / 0xc×3 / 0x2×2 / 0x4×2 / 0x14×2 / 0x48×1 / 0x160×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x198f88 ldr r2, [r0, #0x48]
 *   @0x198f8c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x198f90 cmp r2, #3
 *   @0x198f94 ldr r7, [pc, #0x160]
 *   @0x198f98 sub sp, sp, #28
 *   @0x198f9c mov r6, r0
 *   @0x198fa0 ldr r3, [pc, #0x158]
 *   @0x198fa4 add r7, pc, r7
 *   @0x198fa8 beq 0x1990b8 <_ZN12YYObjectBase4FreeEPS_+0x130>
 *   @0x198fac ldr r3, [r7, r3]
 *   @0x198fb0 mov r1, #0
 *   @0x198fb4 ldr r12, [r0, #0x44]
 *   @0x198fb8 mvn lr, #0
 *   @0x198fbc ldr r5, [r3, #0xc]
 *   @0x198fc0 ldr r8, [r3]
 *   @0x198fc4 ldr r4, [r3, #0x8]
 *   @0x198fc8 str r1, [r8, r12, lsl #2]
 *   @0x198fcc cmp r5, r12
 *   @0x198fd0 strle r5, [r3, #0xc]
 *   @0x198fd4 strgt r12, [r3, #0xc]
 *   @0x198fd8 cmp r2, r1
 *   @0x198fdc str r1, [r0, #0x38]
 *   @0x198fe0 add r2, r4, lr
 *   @0x198fe4 str lr, [r0, #0x44]
 *   @0x198fe8 str r2, [r3, #0x8]
 *   @0x198fec beq 0x199034 <_ZN12YYObjectBase4FreeEPS_+0xac>
 *   @0x198ff0 mov r4, #0
 *   @0x198ff4 mov r0, r6
 *   @0x198ff8 str r4, [r6, #0x40]
 *   @0x198ffc mov r2, r4
 *   @0x199000 str r4, [r6, #0x18]
 *   @0x199004 mov r3, r4
 *   @0x199008 mov r1, r4
 *   @0x19900c str r4, [sp]
 *   @0x199010 bl 0x198dac <_ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_>
 *   @0x199014 ldr r3, [pc, #0xe8]
 *   @0x199018 ldr r3, [r7, r3]
 *   @0x19901c str r4, [r6, #0xc]
 *   @0x199020 ldr r2, [r3]
 *   @0x199024 str r6, [r3]
 *   @0x199028 str r2, [r6, #0x8]
 *   @0x19902c add sp, sp, #28
 *   @0x199030 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x199034 ldr r8, [r0, #0x4]
 *   @0x199038 cmp r8, r1
 *   @0x19903c bne 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68>
 *   @0x199040 ldr r3, [pc, #0xc0]
 *   @0x199044 ldr r3, [r7, r3]
 *   @0x199048 ldrb r3, [r3]
 *   @0x19904c cmp r3, r1
 *   @0x199050 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68>
 *   @0x199054 add r9, sp, #8
 *   @0x199058 ldr r2, [pc, #0xac]
 *   @0x19905c mov r4, #0
 *   @0x199060 str r8, [sp, #0x10]
 *   @0x199064 add r2, pc, r2
 *   @0x199068 mov r1, r9
 *   @0x19906c mov r5, #0
 *   @0x199070 strd r4, r5, [sp, #8]
 *   @0x199074 mvn r4, #-16777216
 *   @0x199078 str r4, [sp, #0x14]
 *   @0x19907c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x199080 ldr r3, [sp, #0x14]
 *   @0x199084 cmp r3, r4
 *   @0x199088 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68>
 *   @0x19908c mov r0, r9
 *   @0x199090 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x199094 cmp r0, #0
 *   @0x199098 beq 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68>
 *   @0x19909c mov r1, r8
 *   @0x1990a0 str r8, [sp]
 *   @0x1990a4 mov r2, r9
 *   @0x1990a8 mov r3, r8
 *   @0x1990ac mov r0, r6
 *   @0x1990b0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x1990b4 b 0x198ff0 <_ZN12YYObjectBase4FreeEPS_+0x68>
 *   @0x1990b8 ldr r3, [r7, r3]
 *   @0x1990bc mov r4, #0
 *   @0x1990c0 ldr r2, [r0, #0x44]
 *   @0x1990c4 ldr r1, [r3]
 *   @0x1990c8 ldr lr, [r3, #0xc]
 *   @0x1990cc ldr r12, [r3, #0x8]
 *   @0x1990d0 str r4, [r1, r2, lsl #2]
 *   @0x1990d4 ldr r1, [r0]
 *   @0x1990d8 sub r12, r12, #1
 *   @0x1990dc cmp lr, r2
 *   @0x1990e0 strle lr, [r3, #0xc]
 *   @0x1990e4 strgt r2, [r3, #0xc]
 *   @0x1990e8 str r12, [r3, #0x8]
 *   @0x1990ec ldr r3, [r1, #0x4]
 *   @0x1990f0 blx r3
 *   @0x1990f4 add sp, sp, #28
 *   @0x1990f8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1990fc eoreq r8, r5, r12, lsr #25
 *   @0x199100 .word 0xffffc014
 *   @0x199104 .word 0xffffbfc0
 *   @0x199108 .word 0xffffc04c
 *   @0x19910c andseq r9, r9, r8, asr #14
 *
 * ══ §62/69 HandleWebEvent  0x1ce134  size 392  98 条（0x1ce134..0x1ce2bc）
 * @func 0x1ce134 0x1ce2bc  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleWebEvent(int)+0x38×2 / HandleWebEvent(int)+0x30 / HandleWebEvent(int)+0x14c / Perform_Event_Object_ASync(CInstance*, CInstance*, int, int, int)
 * 字段偏移 top8: 0x8×4 / 0x14×3 / 0x2×3 / 0x4×3 / 0xc×3 / 0x138×2 / 0x10×2 / 0x168×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ce134 sub r3, r0, #60
 *   @0x1ce138 ldr r1, [pc, #0x168]
 *   @0x1ce13c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ce140 cmp r0, #67
 *   @0x1ce144 cmpne r3, #4
 *   @0x1ce148 sub sp, sp, #28
 *   @0x1ce14c add r1, pc, r1
 *   @0x1ce150 str r0, [sp, #0x14]
 *   @0x1ce154 bls 0x1ce16c <_Z14HandleWebEventi+0x38>
 *   @0x1ce158 sub r3, r0, #69
 *   @0x1ce15c cmp r3, #6
 *   @0x1ce160 bls 0x1ce16c <_Z14HandleWebEventi+0x38>
 *   @0x1ce164 add sp, sp, #28
 *   @0x1ce168 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ce16c ldr r3, [pc, #0x138]
 *   @0x1ce170 ldr r12, [pc, #0x138]
 *   @0x1ce174 ldr r9, [sp, #0x14]
 *   @0x1ce178 ldr r0, [r1, r3]
 *   @0x1ce17c add r8, r9, #1792
 *   @0x1ce180 ldrd r4, r5, [r0]
 *   @0x1ce184 adds r2, r4, #1
 *   @0x1ce188 adc r3, r5, #0
 *   @0x1ce18c strd r2, r3, [r0]
 *   @0x1ce190 ldr r9, [r1, r12]
 *   @0x1ce194 ldr r3, [r9, r8, lsl #2]
 *   @0x1ce198 cmp r3, #0
 *   @0x1ce19c ble 0x1ce164 <_Z14HandleWebEventi+0x30>
 *   @0x1ce1a0 ldr r2, [pc, #0x10c]
 *   @0x1ce1a4 mov r7, #0
 *   @0x1ce1a8 ldr r3, [pc, #0x108]
 *   @0x1ce1ac ldr r10, [r1, r2]
 *   @0x1ce1b0 ldr r11, [r1, r3]
 *   @0x1ce1b4 add r10, r10, r8, lsl #3
 *   @0x1ce1b8 ldr r3, [r11]
 *   @0x1ce1bc ldr r1, [r10, #0x4]
 *   @0x1ce1c0 ldr r2, [r3, #0x4]
 *   @0x1ce1c4 ldr r1, [r1, r7, lsl #2]
 *   @0x1ce1c8 ldr r3, [r3]
 *   @0x1ce1cc and r2, r1, r2
 *   @0x1ce1d0 ldr r3, [r3, r2, lsl #3]
 *   @0x1ce1d4 cmp r3, #0
 *   @0x1ce1d8 bne 0x1ce1ec <_Z14HandleWebEventi+0xb8>
 *   @0x1ce1dc b 0x1ce290 <_Z14HandleWebEventi+0x15c>
 *   @0x1ce1e0 ldr r3, [r3, #0x4]
 *   @0x1ce1e4 cmp r3, #0
 *   @0x1ce1e8 beq 0x1ce290 <_Z14HandleWebEventi+0x15c>
 *   @0x1ce1ec ldr r2, [r3, #0x8]
 *   @0x1ce1f0 cmp r1, r2
 *   @0x1ce1f4 bne 0x1ce1e0 <_Z14HandleWebEventi+0xac>
 *   @0x1ce1f8 ldr r3, [r3, #0xc]
 *   @0x1ce1fc cmp r3, #0
 *   @0x1ce200 beq 0x1ce290 <_Z14HandleWebEventi+0x15c>
 *   @0x1ce204 ldr r6, [r3, #0xc4]
 *   @0x1ce208 cmp r6, #0
 *   @0x1ce20c beq 0x1ce290 <_Z14HandleWebEventi+0x15c>
 *   @0x1ce210 ldr r3, [r6, #0x8]
 *   @0x1ce214 cmp r3, #0
 *   @0x1ce218 beq 0x1ce290 <_Z14HandleWebEventi+0x15c>
 *   @0x1ce21c str r8, [sp, #0x10]
 *   @0x1ce220 str r9, [sp, #0xc]
 *   @0x1ce224 b 0x1ce234 <_Z14HandleWebEventi+0x100>
 *   @0x1ce228 ldr r3, [r6, #0x8]
 *   @0x1ce22c cmp r3, #0
 *   @0x1ce230 beq 0x1ce288 <_Z14HandleWebEventi+0x154>
 *   @0x1ce234 ldr r2, [r6, #0x8]
 *   @0x1ce238 ldr r6, [r6]
 *   @0x1ce23c ldrb r3, [r2, #0x68]
 *   @0x1ce240 cmp r3, #0
 *   @0x1ce244 bne 0x1ce280 <_Z14HandleWebEventi+0x14c>
 *   @0x1ce248 ldrb r3, [r2, #0x69]
 *   @0x1ce24c cmp r3, #0
 *   @0x1ce250 bne 0x1ce280 <_Z14HandleWebEventi+0x14c>
 *   @0x1ce254 ldrd r8, r9, [r2, #112]
 *   @0x1ce258 mov r0, r2
 *   @0x1ce25c mov r1, r2
 *   @0x1ce260 mov r3, #7
 *   @0x1ce264 cmp r4, r8
 *   @0x1ce268 sbcs r9, r5, r9
 *   @0x1ce26c blt 0x1ce280 <_Z14HandleWebEventi+0x14c>
 *   @0x1ce270 ldr r12, [sp, #0x14]
 *   @0x1ce274 ldr r2, [r2, #0x7c]
 *   @0x1ce278 str r12, [sp]
 *   @0x1ce27c bl 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii>
 *   @0x1ce280 cmp r6, #0
 *   @0x1ce284 bne 0x1ce228 <_Z14HandleWebEventi+0xf4>
 *   @0x1ce288 ldr r8, [sp, #0x10]
 *   @0x1ce28c ldr r9, [sp, #0xc]
 *   @0x1ce290 ldr r3, [r9, r8, lsl #2]
 *   @0x1ce294 add r7, r7, #1
 *   @0x1ce298 cmp r3, r7
 *   @0x1ce29c bgt 0x1ce1b8 <_Z14HandleWebEventi+0x84>
 *   @0x1ce2a0 add sp, sp, #28
 *   @0x1ce2a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ce2a8 eoreq r3, r2, r4, lsl #22
 *   @0x1ce2ac .word 0xffffdeb4
 *   @0x1ce2b0 .word 0xffffdeb8
 *   @0x1ce2b4 .word 0xffffdebc
 *   @0x1ce2b8 .word 0xffffbfec
 *
 * ══ §63/69 HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT  0x18d834  size 388  97 条（0x18d834..0x18d9b8）
 * @func 0x18d834 0x18d9b8  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18d844→0x3eba38, 0x18d8cc→0x5356b0, 0x18d918→0x5356b4, 0x18d958→0x4836b0
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)+0x80 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / YYStrDup(char const*) / operator new(unsigned int) / CDS_Map::CDS_Map() / FindFreeDsMapIndex()
 * 字段偏移 top8: 0x4×5 / 0x34×3 / 0x30×2 / 0x38×2 / 0x2c×2 / 0x15c×1 / 0x158×1 / 0x114×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d834 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18d838 sub sp, sp, #12
 *   @0x18d83c ldr r7, [pc, #0x15c]
 *   @0x18d840 add r6, sp, #4
 *   @0x18d844 ldr lr, [pc, #0x158]
 *   @0x18d848 mov r10, r3
 *   @0x18d84c add r7, pc, r7
 *   @0x18d850 mov r4, r0
 *   @0x18d854 mov r0, r6
 *   @0x18d858 mov r5, r2
 *   @0x18d85c ldr r3, [r7, lr]
 *   @0x18d860 mov r9, r1
 *   @0x18d864 ldr r8, [sp, #0x30]
 *   @0x18d868 add r3, r3, #8
 *   @0x18d86c str r3, [r4]
 *   @0x18d870 ldrb r11, [sp, #0x38]
 *   @0x18d874 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x18d878 cmp r5, #0
 *   @0x18d87c mov r3, #0
 *   @0x18d880 str r3, [r4, #0x30]
 *   @0x18d884 str r3, [r4, #0x34]
 *   @0x18d888 ble 0x18d8b4 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x80>
 *   @0x18d88c ldr r1, [pc, #0x114]
 *   @0x18d890 mov r2, #46
 *   @0x18d894 mov r0, r5
 *   @0x18d898 mov r3, #1
 *   @0x18d89c add r1, pc, r1
 *   @0x18d8a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18d8a4 mov r1, #255
 *   @0x18d8a8 mov r2, r5
 *   @0x18d8ac str r0, [r4, #0x34]
 *   @0x18d8b0 bl 0xb65b0 <memset@plt>
 *   @0x18d8b4 mov r3, #0
 *   @0x18d8b8 str r3, [r4, #0x3c]
 *   @0x18d8bc mov r3, #1
 *   @0x18d8c0 str r3, [r4, #0xc]
 *   @0x18d8c4 strb r3, [r4, #0x8]
 *   @0x18d8c8 mvn r2, #0
 *   @0x18d8cc ldr r3, [pc, #0xd8]
 *   @0x18d8d0 cmp r11, #0
 *   @0x18d8d4 str r2, [r4, #0x40]
 *   @0x18d8d8 str r5, [r4, #0x38]
 *   @0x18d8dc ldr r3, [r7, r3]
 *   @0x18d8e0 ldr r2, [r3]
 *   @0x18d8e4 beq 0x18d8f0 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0xbc>
 *   @0x18d8e8 cmp r2, #0
 *   @0x18d8ec bne 0x18d988 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x154>
 *   @0x18d8f0 str r2, [r4, #0x4]
 *   @0x18d8f4 str r4, [r3]
 *   @0x18d8f8 ldr r2, [sp, #0x34]
 *   @0x18d8fc mov r3, #0
 *   @0x18d900 str r10, [r4, #0x10]
 *   @0x18d904 mov r0, r9
 *   @0x18d908 str r3, [r4, #0x18]
 *   @0x18d90c str r2, [r4, #0x1c]
 *   @0x18d910 str r8, [r4, #0x14]
 *   @0x18d914 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18d918 ldr r2, [pc, #0x90]
 *   @0x18d91c mvn r3, #0
 *   @0x18d920 str r3, [r4, #0x2c]
 *   @0x18d924 mov r3, #200
 *   @0x18d928 str r0, [r4, #0x20]
 *   @0x18d92c mov r0, #4
 *   @0x18d930 ldr r2, [r7, r2]
 *   @0x18d934 str r3, [r4, #0x28]
 *   @0x18d938 ldr r3, [r2]
 *   @0x18d93c add r1, r3, #1
 *   @0x18d940 str r1, [r2]
 *   @0x18d944 str r3, [r4, #0x24]
 *   @0x18d948 bl 0x27c524 <_Znwj>
 *   @0x18d94c mov r5, r0
 *   @0x18d950 bl 0x203624 <_ZN7CDS_MapC2Ev>
 *   @0x18d954 bl 0x100014 <_Z18FindFreeDsMapIndexv>
 *   @0x18d958 ldr r2, [pc, #0x54]
 *   @0x18d95c mov r3, r0
 *   @0x18d960 str r3, [r4, #0x2c]
 *   @0x18d964 ldr r2, [r7, r2]
 *   @0x18d968 mov r0, r6
 *   @0x18d96c ldr r2, [r2, #0x4]
 *   @0x18d970 str r5, [r2, r3, lsl #2]
 *   @0x18d974 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x18d978 mov r0, r4
 *   @0x18d97c add sp, sp, #12
 *   @0x18d980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18d984 mov r2, r3
 *   @0x18d988 ldr r3, [r2, #0x4]
 *   @0x18d98c cmp r3, #0
 *   @0x18d990 bne 0x18d984 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x150>
 *   @0x18d994 str r4, [r2, #0x4]
 *   @0x18d998 str r3, [r4, #0x4]
 *   @0x18d99c b 0x18d8f8 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0xc4>
 *   @0x18d9a0 eoreq r4, r6, r4, lsl #8
 *   @0x18d9a4 .word 0xffffe9e8
 *   @0x18d9a8 andseq lr, r11, r12, lsr r10
 *   @0x18d9ac .word 0xffffc1a8
 *   @0x18d9b0 .word 0xffffd628
 *   @0x18d9b4 .word 0xffffbcec
 *
 * ══ §64/69 DrawLayerInstanceElement  0x1b1600  size 388  97 条（0x1b1600..0x1b1784）
 * @func 0x1b1600 0x1b1794  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::HasEventRecursive(int, int) / Sprite_Data(int) / CSprite::Draw(int, float, float, float, float, float, unsigned int, float) / Perform_Event(CInstance*, CInstance*, int, int) / 0xb6910 / CSprite::DrawSimple(int, float, float)
 * 字段偏移 top8: 0xa8×3 / 0xb4×2 / 0xb8×2 / 0x20×1 / 0x68×1 / 0x69×1 / 0x65×1 / 0x80×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b1600 push {r4, r5, r6, lr}
 *   @0x1b1604 sub sp, sp, #24
 *   @0x1b1608 ldr r4, [r2, #0x20]
 *   @0x1b160c cmp r4, #0
 *   @0x1b1610 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b1614 ldrb r3, [r4, #0x68]
 *   @0x1b1618 cmp r3, #0
 *   @0x1b161c bne 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b1620 ldrb r5, [r4, #0x69]
 *   @0x1b1624 cmp r5, #0
 *   @0x1b1628 bne 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b162c ldrb r3, [r4, #0x65]
 *   @0x1b1630 cmp r3, #0
 *   @0x1b1634 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b1638 ldr r0, [r4, #0x80]
 *   @0x1b163c cmp r0, #0
 *   @0x1b1640 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b1644 mov r1, #8
 *   @0x1b1648 mov r2, r5
 *   @0x1b164c bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1b1650 cmp r0, #0
 *   @0x1b1654 bne 0x1b16e4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xe4>
 *   @0x1b1658 ldr r0, [r4, #0x8c]
 *   @0x1b165c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b1660 subs r6, r0, #0
 *   @0x1b1664 beq 0x1b16dc <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xdc>
 *   @0x1b1668 vmov.f32 s14, #1.000000e+00
 *   @0x1b166c vldr s15, [r4, #152]
 *   @0x1b1670 ldr r5, [pc, #0x104]
 *   @0x1b1674 ldr r5, [pc, r5]
 *   @0x1b1678 str r4, [r5]
 *   @0x1b167c vcmp.f32 s15, s14
 *   @0x1b1680 vmrs APSR_nzcv, fpscr
 *   @0x1b1684 bne 0x1b1710 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x110>
 *   @0x1b1688 vldr s13, [r4, #156]
 *   @0x1b168c vcmp.f32 s13, s14
 *   @0x1b1690 vldr s14, [r4, #160]
 *   @0x1b1694 vmrs APSR_nzcv, fpscr
 *   @0x1b1698 beq 0x1b1724 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x124>
 *   @0x1b169c ldr r12, [r4, #0xa8]
 *   @0x1b16a0 vldr s12, [r4, #164]
 *   @0x1b16a4 vldr s11, [r4, #144]
 *   @0x1b16a8 vcvt.s32.f32 s11, s11
 *   @0x1b16ac ldr r2, [r4, #0xb4]
 *   @0x1b16b0 mov r0, r6
 *   @0x1b16b4 ldr r3, [r4, #0xb8]
 *   @0x1b16b8 vstr s15, [sp]
 *   @0x1b16bc vstr s13, [sp, #4]
 *   @0x1b16c0 vstr s14, [sp, #8]
 *   @0x1b16c4 str r12, [sp, #0xc]
 *   @0x1b16c8 vstr s12, [sp, #16]
 *   @0x1b16cc vmov r1, s11
 *   @0x1b16d0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x1b16d4 mov r3, #0
 *   @0x1b16d8 str r3, [r5]
 *   @0x1b16dc add sp, sp, #24
 *   @0x1b16e0 pop {r4, r5, r6, pc}
 *   @0x1b16e4 ldr r6, [pc, #0x94]
 *   @0x1b16e8 mov r0, r4
 *   @0x1b16ec mov r1, r4
 *   @0x1b16f0 mov r2, #8
 *   @0x1b16f4 ldr r6, [pc, r6]
 *   @0x1b16f8 mov r3, r5
 *   @0x1b16fc str r4, [r6]
 *   @0x1b1700 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1b1704 str r5, [r6]
 *   @0x1b1708 add sp, sp, #24
 *   @0x1b170c pop {r4, r5, r6, pc}
 *   @0x1b1710 ldr r12, [r4, #0xa8]
 *   @0x1b1714 vldr s13, [r4, #156]
 *   @0x1b1718 vldr s14, [r4, #160]
 *   @0x1b171c vldr s12, [r4, #164]
 *   @0x1b1720 b 0x1b16a4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xa4>
 *   @0x1b1724 vcmp.f32 s14, #0
 *   @0x1b1728 ldr r12, [r4, #0xa8]
 *   @0x1b172c vmrs APSR_nzcv, fpscr
 *   @0x1b1730 bne 0x1b171c <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x11c>
 *   @0x1b1734 mvn r3, #-16777216
 *   @0x1b1738 cmp r12, r3
 *   @0x1b173c bne 0x1b171c <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0x11c>
 *   @0x1b1740 vmov.f32 s11, #1.000000e+00
 *   @0x1b1744 vldr s12, [r4, #164]
 *   @0x1b1748 vcmp.f32 s12, s11
 *   @0x1b174c vmrs APSR_nzcv, fpscr
 *   @0x1b1750 bne 0x1b16a4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xa4>
 *   @0x1b1754 ldr r0, [r4, #0x90]
 *   @0x1b1758 bl 0xb6910 <floorf@plt>
 *   @0x1b175c ldr r2, [r4, #0xb4]
 *   @0x1b1760 ldr r3, [r4, #0xb8]
 *   @0x1b1764 vmov s15, r0
 *   @0x1b1768 mov r0, r6
 *   @0x1b176c vcvt.s32.f32 s15, s15
 *   @0x1b1770 vmov r1, s15
 *   @0x1b1774 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff>
 *   @0x1b1778 b 0x1b16d4 <_Z24DrawLayerInstanceElementP9tagYYRECTP6CLayerP21CLayerInstanceElement+0xd4>
 *   @0x1b177c eoreq r12, r3, r0, asr #5
 *   @0x1b1780 eoreq r12, r3, r0, asr #4
 *
 * ══ §65/69 CLayerManager::BuildRoomLayerRuntimeData  0x1c5dbc  size 388  97 条（0x1c5dbc..0x1c5f40）
 * @func 0x1c5dbc 0x1c5f40  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::Reset() / CLayerManager::BuildElementRuntimeData(CRoom*, CLayer*, CLayerElementBase*) / CLayerManager::BuildRoomLayerRuntimeData(CRoom*)+0x140 / CLayerManager::AddInstance(CRoom*, CInstance*) / CLayerManager::SortDeactivatedInstances(CLayer*) / operator new(unsigned int) / CInstance::CInstance(float, float, int, int, bool)
 * 字段偏移 top8: 0x4×4 / 0xd4×2 / 0x68×2 / 0x170×1 / 0x58×1 / 0x14×1 / 0x10c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c5dbc ldr r3, [pc, #0x170]
 *   @0x1c5dc0 push {r4, r5, r6, r7, lr}
 *   @0x1c5dc4 ldr r3, [pc, r3]
 *   @0x1c5dc8 sub sp, sp, #12
 *   @0x1c5dcc mov r6, r0
 *   @0x1c5dd0 ldrb r3, [r3]
 *   @0x1c5dd4 cmp r3, #0
 *   @0x1c5dd8 beq 0x1c5ef4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x138>
 *   @0x1c5ddc ldr r5, [r0, #0xd4]
 *   @0x1c5de0 cmp r5, #0
 *   @0x1c5de4 beq 0x1c5e24 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x68>
 *   @0x1c5de8 add r0, r5, #48
 *   @0x1c5dec bl 0x214728 <_ZN13CTimingSource5ResetEv>
 *   @0x1c5df0 ldr r4, [r5, #0x58]
 *   @0x1c5df4 cmp r4, #0
 *   @0x1c5df8 beq 0x1c5e18 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x5c>
 *   @0x1c5dfc mov r2, r4
 *   @0x1c5e00 mov r0, r6
 *   @0x1c5e04 mov r1, r5
 *   @0x1c5e08 bl 0x1ba6bc <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase>
 *   @0x1c5e0c ldr r4, [r4, #0x14]
 *   @0x1c5e10 cmp r4, #0
 *   @0x1c5e14 bne 0x1c5dfc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x40>
 *   @0x1c5e18 ldr r5, [r5, #0x68]
 *   @0x1c5e1c cmp r5, #0
 *   @0x1c5e20 bne 0x1c5de8 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x2c>
 *   @0x1c5e24 ldr r7, [pc, #0x10c]
 *   @0x1c5e28 mov r3, #0
 *   @0x1c5e2c ldr r7, [pc, r7]
 *   @0x1c5e30 ldr r2, [r7]
 *   @0x1c5e34 ldr r1, [r7, #0x4]
 *   @0x1c5e38 b 0x1c5e44 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x88>
 *   @0x1c5e3c cmp r1, r3
 *   @0x1c5e40 blt 0x1c5efc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x140>
 *   @0x1c5e44 mov r5, r3
 *   @0x1c5e48 add r3, r3, #1
 *   @0x1c5e4c ldr r4, [r2, r5, lsl #3]
 *   @0x1c5e50 cmp r4, #0
 *   @0x1c5e54 beq 0x1c5e3c <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x80>
 *   @0x1c5e58 cmp r4, #0
 *   @0x1c5e5c beq 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104>
 *   @0x1c5e60 ldr r1, [r4, #0xc]
 *   @0x1c5e64 cmp r1, #0
 *   @0x1c5e68 beq 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104>
 *   @0x1c5e6c mov r0, r6
 *   @0x1c5e70 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance>
 *   @0x1c5e74 ldr r4, [r4, #0x4]
 *   @0x1c5e78 cmp r4, #0
 *   @0x1c5e7c bne 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c>
 *   @0x1c5e80 ldr r1, [r7, #0x4]
 *   @0x1c5e84 add r3, r5, #1
 *   @0x1c5e88 cmp r3, r1
 *   @0x1c5e8c bgt 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104>
 *   @0x1c5e90 ldr r2, [r7]
 *   @0x1c5e94 add r2, r2, r5, lsl #3
 *   @0x1c5e98 b 0x1c5ea4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0xe8>
 *   @0x1c5e9c cmp r3, r1
 *   @0x1c5ea0 bgt 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104>
 *   @0x1c5ea4 ldr r4, [r2, #0x8]
 *   @0x1c5ea8 mov r5, r3
 *   @0x1c5eac add r2, r2, #8
 *   @0x1c5eb0 add r3, r3, #1
 *   @0x1c5eb4 cmp r4, #0
 *   @0x1c5eb8 beq 0x1c5e9c <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0xe0>
 *   @0x1c5ebc b 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c>
 *   @0x1c5ec0 ldr r4, [pc, #0x74]
 *   @0x1c5ec4 ldr r4, [pc, r4]
 *   @0x1c5ec8 ldr r5, [r4]
 *   @0x1c5ecc cmp r5, #0
 *   @0x1c5ed0 beq 0x1c5f04 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x148>
 *   @0x1c5ed4 ldr r4, [r6, #0xd4]
 *   @0x1c5ed8 cmp r4, #0
 *   @0x1c5edc beq 0x1c5ef4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x138>
 *   @0x1c5ee0 mov r0, r4
 *   @0x1c5ee4 bl 0x1b8bfc <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer>
 *   @0x1c5ee8 ldr r4, [r4, #0x68]
 *   @0x1c5eec cmp r4, #0
 *   @0x1c5ef0 bne 0x1c5ee0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x124>
 *   @0x1c5ef4 add sp, sp, #12
 *   @0x1c5ef8 pop {r4, r5, r6, r7, pc}
 *   @0x1c5efc mvn r5, #0
 *   @0x1c5f00 b 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c>
 *   @0x1c5f04 mov r0, #432
 *   @0x1c5f08 bl 0x27c524 <_Znwj>
 *   @0x1c5f0c mov r1, #0
 *   @0x1c5f10 mvn r2, #0
 *   @0x1c5f14 mov r3, r5
 *   @0x1c5f18 str r2, [sp]
 *   @0x1c5f1c mov r2, r1
 *   @0x1c5f20 str r5, [sp, #0x4]
 *   @0x1c5f24 mov r7, r0
 *   @0x1c5f28 bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0x1c5f2c str r7, [r4]
 *   @0x1c5f30 b 0x1c5ed4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x118>
 *   @0x1c5f34 eoreq r7, r2, r0, ror #22
 *   @0x1c5f38 eoreq r7, r2, r8, lsl lr
 *   @0x1c5f3c eoreq r7, r2, r12, lsr #27
 *
 * ══ §66/69 DrawLayerTileElement  0x1b283c  size 384  96 条（0x1b283c..0x1b29bc）
 * @func 0x1b283c 0x1b29bc  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DrawLayerTileElement(tagYYRECT*, CLayer*, CLayerTileElement*)+0x174×2 / Sprite_Exists(int) / Sprite_Data(int) / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x1c×2 / 0x20×2 / 0x48×1 / 0x4c×1 / 0x34×1 / 0x10×1 / 0x44×1 / 0x40×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b283c ldrb r3, [r2, #0x1c]
 *   @0x1b2840 push {r4, r5, r6, lr}
 *   @0x1b2844 vpush {d8, d9}
 *   @0x1b2848 cmp r3, #0
 *   @0x1b284c sub sp, sp, #32
 *   @0x1b2850 mov r4, r2
 *   @0x1b2854 mov r5, r0
 *   @0x1b2858 mov r6, r1
 *   @0x1b285c beq 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b2860 vldr s10, [r2, #44]
 *   @0x1b2864 vcvt.f32.s32 s11, s10
 *   @0x1b2868 vldr s14, [r2, #36]
 *   @0x1b286c vldr s12, [r2, #52]
 *   @0x1b2870 vldr s15, [r2, #40]
 *   @0x1b2874 vldr s13, [r2, #56]
 *   @0x1b2878 ldr r0, [r2, #0x20]
 *   @0x1b287c vmov.f32 s16, s14
 *   @0x1b2880 vmla.f32 s16, s11, s12
 *   @0x1b2884 vldr s11, [r2, #48]
 *   @0x1b2888 vcvt.f32.s32 s12, s11
 *   @0x1b288c vmov.f32 s17, s15
 *   @0x1b2890 vmla.f32 s17, s12, s13
 *   @0x1b2894 vcmpe.f32 s14, s16
 *   @0x1b2898 vmrs APSR_nzcv, fpscr
 *   @0x1b289c vcmp.f32 s14, s16
 *   @0x1b28a0 vmovpl.f32 s18, s16
 *   @0x1b28a4 vmovmi.f32 s18, s14
 *   @0x1b28a8 vmrs APSR_nzcv, fpscr
 *   @0x1b28ac vcmpe.f32 s15, s17
 *   @0x1b28b0 vmovgt.f32 s16, s14
 *   @0x1b28b4 vmrs APSR_nzcv, fpscr
 *   @0x1b28b8 vcmp.f32 s15, s17
 *   @0x1b28bc vmovpl.f32 s19, s17
 *   @0x1b28c0 vmovmi.f32 s19, s15
 *   @0x1b28c4 vmrs APSR_nzcv, fpscr
 *   @0x1b28c8 vmovgt.f32 s17, s15
 *   @0x1b28cc bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1b28d0 cmp r0, #0
 *   @0x1b28d4 beq 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b28d8 vldr s14, [r5, #8]
 *   @0x1b28dc vcvt.f32.s32 s15, s14
 *   @0x1b28e0 vcmpe.f32 s18, s15
 *   @0x1b28e4 vmrs APSR_nzcv, fpscr
 *   @0x1b28e8 bhi 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b28ec vldr s10, [r5, #12]
 *   @0x1b28f0 vcvt.f32.s32 s15, s10
 *   @0x1b28f4 vcmpe.f32 s19, s15
 *   @0x1b28f8 vmrs APSR_nzcv, fpscr
 *   @0x1b28fc bhi 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b2900 vldr s11, [r5]
 *   @0x1b2904 vcvt.f32.s32 s15, s11
 *   @0x1b2908 vcmpe.f32 s16, s15
 *   @0x1b290c vmrs APSR_nzcv, fpscr
 *   @0x1b2910 blt 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b2914 vldr s15, [r5, #4]
 *   @0x1b2918 vcvt.f32.s32 s15, s15
 *   @0x1b291c vcmpe.f32 s17, s15
 *   @0x1b2920 vmrs APSR_nzcv, fpscr
 *   @0x1b2924 blt 0x1b29b0 <_Z20DrawLayerTileElementP9tagYYRECTP6CLayerP17CLayerTileElement+0x174>
 *   @0x1b2928 ldr r0, [r4, #0x20]
 *   @0x1b292c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b2930 vldr s14, [r4, #44]
 *   @0x1b2934 vldr s15, [r4, #48]
 *   @0x1b2938 vcvt.f32.s32 s14, s14
 *   @0x1b293c ldr r2, [r4, #0x48]
 *   @0x1b2940 vldr s13, [r6, #8]
 *   @0x1b2944 ldr r3, [r4, #0x4c]
 *   @0x1b2948 vldr s12, [r4, #36]
 *   @0x1b294c ldr r1, [r4, #0x34]
 *   @0x1b2950 vldr s11, [r4, #40]
 *   @0x1b2954 vcvt.f32.s32 s15, s15
 *   @0x1b2958 vadd.f32 s12, s12, s13
 *   @0x1b295c vldr s13, [r6, #12]
 *   @0x1b2960 str r1, [sp, #0x10]
 *   @0x1b2964 ldr r1, [r4, #0x44]
 *   @0x1b2968 ldr r12, [r4, #0x40]
 *   @0x1b296c ldr lr, [r4, #0x38]
 *   @0x1b2970 vstr s14, [sp]
 *   @0x1b2974 vstr s15, [sp, #4]
 *   @0x1b2978 vmov s14, r2
 *   @0x1b297c vmov s15, r3
 *   @0x1b2980 str r1, [sp, #0x1c]
 *   @0x1b2984 str lr, [sp, #0x14]
 *   @0x1b2988 mov r1, #0
 *   @0x1b298c str r12, [sp, #0x18]
 *   @0x1b2990 vadd.f32 s13, s11, s13
 *   @0x1b2994 vstr s12, [sp, #8]
 *   @0x1b2998 vcvt.f32.s32 s14, s14
 *   @0x1b299c vstr s13, [sp, #12]
 *   @0x1b29a0 vcvt.f32.s32 s15, s15
 *   @0x1b29a4 vmov r2, s14
 *   @0x1b29a8 vmov r3, s15
 *   @0x1b29ac bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x1b29b0 add sp, sp, #32
 *   @0x1b29b4 vpop {d8, d9}
 *   @0x1b29b8 pop {r4, r5, r6, pc}
 *
 * ══ §67/69 CreateDsMap  0x20bdc0  size 384  96 条（0x20bdc0..0x20bf40）
 * @func 0x20bdc0 0x20bf40  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / operator new(unsigned int) / CDS_Map::CDS_Map() / CreateDsMap(int, ...)+0x14c / CDS_Map::Add(RValue*, RValue*) / FindFreeDsMapIndex()
 * 字段偏移 top8: 0x24×4 / 0x60×3 / 0x14×3 / 0x34×3 / 0x4×2 / 0x8×2 / 0x20×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20bdc0 push {r0, r1, r2, r3}
 *   @0x20bdc4 mov r0, #4
 *   @0x20bdc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20bdcc sub sp, sp, #60
 *   @0x20bdd0 bl 0x27c524 <_Znwj>
 *   @0x20bdd4 mov r8, r0
 *   @0x20bdd8 bl 0x203624 <_ZN7CDS_MapC2Ev>
 *   @0x20bddc ldr r3, [sp, #0x60]
 *   @0x20bde0 cmp r3, #0
 *   @0x20bde4 add r3, sp, #100
 *   @0x20bde8 str r3, [sp, #0x14]
 *   @0x20bdec ble 0x20bf0c <_Z11CreateDsMapiz+0x14c>
 *   @0x20bdf0 add r7, sp, #24
 *   @0x20bdf4 mov r6, #0
 *   @0x20bdf8 add r3, sp, #32
 *   @0x20bdfc add r11, sp, #28
 *   @0x20be00 str r3, [sp, #0xc]
 *   @0x20be04 add r5, sp, #40
 *   @0x20be08 add r3, sp, #44
 *   @0x20be0c mov r4, r7
 *   @0x20be10 str r3, [sp]
 *   @0x20be14 mov r9, r6
 *   @0x20be18 add r3, sp, #48
 *   @0x20be1c str r3, [sp, #0x4]
 *   @0x20be20 add r3, sp, #52
 *   @0x20be24 str r3, [sp, #0x8]
 *   @0x20be28 b 0x20be90 <_Z11CreateDsMapiz+0xd0>
 *   @0x20be2c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20be30 mov r0, r8
 *   @0x20be34 mov r1, r4
 *   @0x20be38 mov r2, r5
 *   @0x20be3c add r6, r6, #1
 *   @0x20be40 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20be44 ldr r3, [sp, #0x24]
 *   @0x20be48 sub r3, r3, #1
 *   @0x20be4c bic r3, r3, #-16777216
 *   @0x20be50 bic r3, r3, #3
 *   @0x20be54 cmp r3, #0
 *   @0x20be58 beq 0x20bf30 <_Z11CreateDsMapiz+0x170>
 *   @0x20be5c ldr r3, [sp, #0x34]
 *   @0x20be60 mov r2, #5
 *   @0x20be64 str r9, [sp, #0x20]
 *   @0x20be68 sub r3, r3, #1
 *   @0x20be6c str r2, [sp, #0x24]
 *   @0x20be70 bic r3, r3, #-16777216
 *   @0x20be74 str r9, [sp, #0x18]
 *   @0x20be78 bic r3, r3, #3
 *   @0x20be7c cmp r3, #0
 *   @0x20be80 beq 0x20bef8 <_Z11CreateDsMapiz+0x138>
 *   @0x20be84 ldr r3, [sp, #0x60]
 *   @0x20be88 cmp r6, r3
 *   @0x20be8c beq 0x20bf0c <_Z11CreateDsMapiz+0x14c>
 *   @0x20be90 ldr r10, [sp, #0x14]
 *   @0x20be94 mov r0, r4
 *   @0x20be98 mov r2, #1
 *   @0x20be9c str r9, [r7]
 *   @0x20bea0 str r2, [sp, #0x24]
 *   @0x20bea4 mov r7, r4
 *   @0x20bea8 ldr r1, [r10], #11
 *   @0x20beac str r9, [r11]
 *   @0x20beb0 str r9, [sp, #0x20]
 *   @0x20beb4 str r9, [r5]
 *   @0x20beb8 str r9, [sp, #0x2c]
 *   @0x20bebc str r9, [sp, #0x30]
 *   @0x20bec0 str r9, [sp, #0x34]
 *   @0x20bec4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20bec8 bic r3, r10, #7
 *   @0x20becc mov r0, r5
 *   @0x20bed0 ldr lr, [r3, #0x8]
 *   @0x20bed4 mov r12, r3
 *   @0x20bed8 ldrd r2, r3, [r12], #12
 *   @0x20bedc cmp lr, #0
 *   @0x20bee0 mov r1, lr
 *   @0x20bee4 str r12, [sp, #0x14]
 *   @0x20bee8 bne 0x20be2c <_Z11CreateDsMapiz+0x6c>
 *   @0x20beec strd r2, r3, [sp, #40]
 *   @0x20bef0 str lr, [sp, #0x34]
 *   @0x20bef4 b 0x20be30 <_Z11CreateDsMapiz+0x70>
 *   @0x20bef8 mov r0, r5
 *   @0x20befc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20bf00 ldr r3, [sp, #0x60]
 *   @0x20bf04 cmp r6, r3
 *   @0x20bf08 bne 0x20be90 <_Z11CreateDsMapiz+0xd0>
 *   @0x20bf0c bl 0x100014 <_Z18FindFreeDsMapIndexv>
 *   @0x20bf10 ldr r3, [pc, #0x24]
 *   @0x20bf14 ldr r3, [pc, r3]
 *   @0x20bf18 ldr r3, [r3, #0x4]
 *   @0x20bf1c str r8, [r3, r0, lsl #2]
 *   @0x20bf20 add sp, sp, #60
 *   @0x20bf24 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20bf28 add sp, sp, #16
 *   @0x20bf2c bx lr
 *   @0x20bf30 mov r0, r4
 *   @0x20bf34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20bf38 b 0x20be5c <_Z11CreateDsMapiz+0x9c>
 *   @0x20bf3c andseq r1, lr, r8, lsr #20
 *
 * ══ §68/69 anon_231ac4  0x231ac4  size 384  96 条（0x231ac4..0x231c44）
 * @func 0x231ac4 0x231c44  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_22fd0c+0x1c8 / anon_22fd0c+0x33c / anon_231ac4+0x150 / anon_22fd0c+0x968 / anon_231ac4+0x174 / ov_raw_seek
 * 字段偏移 top8: 0x40×3 / 0x3c×2 / 0x2c×2 / 0x294×2 / 0x4×2 / 0x1c8×1 / 0x48×1 / 0x28c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231ac4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x231ac8 sub sp, sp, #60
 *   @0x231acc ldr r3, [r0, #0x3c]
 *   @0x231ad0 mov r10, r0
 *   @0x231ad4 ldr r11, [r0, #0x1c8]
 *   @0x231ad8 mvn r6, #0
 *   @0x231adc ldr r1, [r0, #0x48]
 *   @0x231ae0 mvn r7, #0
 *   @0x231ae4 ldrd r4, r5, [r3]
 *   @0x231ae8 str r11, [sp, #0x2c]
 *   @0x231aec strd r6, r7, [sp, #48]
 *   @0x231af0 bl 0x22fed4 <vorbis_packet_blocksize+0x258>
 *   @0x231af4 mov r9, r1
 *   @0x231af8 ldr r1, [r10, #0x28c]
 *   @0x231afc mov r8, r0
 *   @0x231b00 cmp r1, #0
 *   @0x231b04 beq 0x231c1c <ov_raw_seek+0x604>
 *   @0x231b08 ldr r3, [r10, #0x294]
 *   @0x231b0c cmp r3, #0
 *   @0x231b10 beq 0x231c1c <ov_raw_seek+0x604>
 *   @0x231b14 mov r12, #2
 *   @0x231b18 ldr r0, [r10]
 *   @0x231b1c mov r2, #0
 *   @0x231b20 mov r3, #0
 *   @0x231b24 str r12, [sp]
 *   @0x231b28 blx r1
 *   @0x231b2c ldr r3, [r10, #0x294]
 *   @0x231b30 ldr r0, [r10]
 *   @0x231b34 blx r3
 *   @0x231b38 asr r1, r0, #31
 *   @0x231b3c strd r0, r1, [r10, #16]
 *   @0x231b40 cmp r1, r7
 *   @0x231b44 cmpeq r0, r6
 *   @0x231b48 strd r0, r1, [r10, #8]
 *   @0x231b4c beq 0x231c40 <ov_raw_seek+0x628>
 *   @0x231b50 ldr r2, [r10, #0x40]
 *   @0x231b54 add r3, sp, #44
 *   @0x231b58 add r12, sp, #48
 *   @0x231b5c mov r0, r10
 *   @0x231b60 add r1, r2, #8
 *   @0x231b64 ldr r2, [r2, #0x4]
 *   @0x231b68 str r12, [sp]
 *   @0x231b6c bl 0x230048 <vorbis_packet_blocksize+0x3cc>
 *   @0x231b70 cmp r0, #0
 *   @0x231b74 sbcs r3, r1, #0
 *   @0x231b78 blt 0x231c14 <ov_raw_seek+0x5fc>
 *   @0x231b7c ldr r1, [r10, #0x40]
 *   @0x231b80 mov r12, #0
 *   @0x231b84 ldrd r2, r3, [r10, #8]
 *   @0x231b88 mov r0, r10
 *   @0x231b8c add lr, r1, #8
 *   @0x231b90 ldrd r6, r7, [sp, #48]
 *   @0x231b94 str lr, [sp, #0x1c]
 *   @0x231b98 ldr lr, [sp, #0x2c]
 *   @0x231b9c strd r2, r3, [sp, #8]
 *   @0x231ba0 mov r2, #0
 *   @0x231ba4 strd r4, r5, [sp]
 *   @0x231ba8 mov r3, #0
 *   @0x231bac strd r6, r7, [sp, #16]
 *   @0x231bb0 str lr, [sp, #0x18]
 *   @0x231bb4 ldr r1, [r1, #0x4]
 *   @0x231bb8 str r12, [sp, #0x24]
 *   @0x231bbc str r1, [sp, #0x20]
 *   @0x231bc0 bl 0x230674 <vorbis_packet_blocksize+0x9f8>
 *   @0x231bc4 cmp r0, #0
 *   @0x231bc8 blt 0x231c38 <ov_raw_seek+0x620>
 *   @0x231bcc ldr lr, [r10, #0x38]
 *   @0x231bd0 mov r0, r10
 *   @0x231bd4 ldr r12, [r10, #0x40]
 *   @0x231bd8 mov r6, #0
 *   @0x231bdc ldr r1, [r10, #0x3c]
 *   @0x231be0 mov r7, #0
 *   @0x231be4 ldr r10, [r10, #0x44]
 *   @0x231be8 mov r2, r4
 *   @0x231bec strd r6, r7, [lr]
 *   @0x231bf0 mov r3, r5
 *   @0x231bf4 str r11, [r12]
 *   @0x231bf8 strd r4, r5, [r1]
 *   @0x231bfc ldrd r4, r5, [r10, #8]
 *   @0x231c00 strd r8, r9, [r10]
 *   @0x231c04 subs r4, r4, r8
 *   @0x231c08 sbc r5, r5, r9
 *   @0x231c0c strd r4, r5, [r10, #8]
 *   @0x231c10 bl 0x231618 <ov_raw_seek>
 *   @0x231c14 add sp, sp, #60
 *   @0x231c18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x231c1c mvn r2, #0
 *   @0x231c20 mvn r3, #0
 *   @0x231c24 mvn r0, #130
 *   @0x231c28 strd r2, r3, [r10, #16]
 *   @0x231c2c strd r2, r3, [r10, #8]
 *   @0x231c30 add sp, sp, #60
 *   @0x231c34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x231c38 mvn r0, #127
 *   @0x231c3c b 0x231c14 <ov_raw_seek+0x5fc>
 *   @0x231c40 mvn r0, #130
 *
 * ══ §69/69 CPhysicsWorld::FindBaseObjectForCollisions  0x238598  size 384  96 条（0x238598..0x238718）
 * @func 0x238598 0x238728  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Object_Exists(int) / CPhysicsWorld::FindBaseObjectForCollisions(int, int)+0x164
 * 字段偏移 top8: 0x4×8 / 0xc×4 / 0x8×3 / 0x3×2 / 0x16c×1 / 0x158×1 / 0x98×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238598 ldr r3, [pc, #0x16c]
 *   @0x23859c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2385a0 sub sp, sp, #12
 *   @0x2385a4 mov r11, r1
 *   @0x2385a8 str r3, [sp, #0x4]
 *   @0x2385ac ldr r0, [sp, #0x4]
 *   @0x2385b0 ldr r3, [pc, #0x158]
 *   @0x2385b4 ldr r0, [pc, r0]
 *   @0x2385b8 str r0, [sp, #0x4]
 *   @0x2385bc ldr r3, [pc, r3]
 *   @0x2385c0 ldr r1, [r0]
 *   @0x2385c4 ldr r10, [r3]
 *   @0x2385c8 ldr r0, [r1, #0x4]
 *   @0x2385cc ldr r3, [r1]
 *   @0x2385d0 and r1, r11, r0
 *   @0x2385d4 ldr r3, [r3, r1, lsl #3]
 *   @0x2385d8 cmp r3, #0
 *   @0x2385dc bne 0x2385f0 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x58>
 *   @0x2385e0 b 0x238704 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x16c>
 *   @0x2385e4 ldr r3, [r3, #0x4]
 *   @0x2385e8 cmp r3, #0
 *   @0x2385ec beq 0x238704 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x16c>
 *   @0x2385f0 ldr r1, [r3, #0x8]
 *   @0x2385f4 cmp r11, r1
 *   @0x2385f8 bne 0x2385e4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x4c>
 *   @0x2385fc ldr r8, [r3, #0xc]
 *   @0x238600 ldr r0, [r8, #0xc]
 *   @0x238604 cmp r0, #0
 *   @0x238608 bge 0x238618 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x80>
 *   @0x23860c mov r0, r11
 *   @0x238610 add sp, sp, #12
 *   @0x238614 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x238618 str r2, [sp]
 *   @0x23861c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x238620 ldr r2, [sp]
 *   @0x238624 cmp r0, #0
 *   @0x238628 beq 0x23860c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x74>
 *   @0x23862c ldr r3, [sp, #0x4]
 *   @0x238630 ldr r1, [r8, #0xc]
 *   @0x238634 ldr r0, [r3]
 *   @0x238638 ldm r0, {r3, r12}
 *   @0x23863c and r0, r1, r12
 *   @0x238640 ldr r3, [r3, r0, lsl #3]
 *   @0x238644 cmp r3, #0
 *   @0x238648 beq 0x2386f4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x15c>
 *   @0x23864c ldr r0, [r3, #0x8]
 *   @0x238650 cmp r1, r0
 *   @0x238654 beq 0x238670 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xd8>
 *   @0x238658 ldr r3, [r3, #0x4]
 *   @0x23865c cmp r3, #0
 *   @0x238660 beq 0x2386f4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x15c>
 *   @0x238664 ldr r12, [r3, #0x8]
 *   @0x238668 cmp r1, r12
 *   @0x23866c bne 0x238658 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xc0>
 *   @0x238670 ldr r8, [r3, #0xc]
 *   @0x238674 ldr r1, [pc, #0x98]
 *   @0x238678 cmp r10, #0
 *   @0x23867c ldr r7, [r8, #0x18]
 *   @0x238680 ldr r1, [pc, r1]
 *   @0x238684 ldr r12, [r1, #0x4]
 *   @0x238688 ble 0x2386fc <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x164>
 *   @0x23868c mov r4, #0
 *   @0x238690 add r12, r12, #20
 *   @0x238694 mov r9, r4
 *   @0x238698 b 0x2386ac <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x114>
 *   @0x23869c cmp r7, r5
 *   @0x2386a0 beq 0x2386e4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x14c>
 *   @0x2386a4 cmp r4, r10
 *   @0x2386a8 beq 0x2386d4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x13c>
 *   @0x2386ac ldr r6, [r12, #-0x14]
 *   @0x2386b0 add r4, r4, #1
 *   @0x2386b4 ldr r5, [r12, #-0x10]
 *   @0x2386b8 add r12, r12, #20
 *   @0x2386bc cmp r7, r6
 *   @0x2386c0 bne 0x23869c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x104>
 *   @0x2386c4 cmn r5, #1
 *   @0x2386c8 addne r9, r9, #1
 *   @0x2386cc cmp r4, r10
 *   @0x2386d0 bne 0x2386ac <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x114>
 *   @0x2386d4 cmp r9, r2
 *   @0x2386d8 bne 0x23860c <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x74>
 *   @0x2386dc mov r11, r7
 *   @0x2386e0 b 0x238600 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x68>
 *   @0x2386e4 mov r5, r6
 *   @0x2386e8 cmn r5, #1
 *   @0x2386ec addne r9, r9, #1
 *   @0x2386f0 b 0x2386cc <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x134>
 *   @0x2386f4 mov r8, r3
 *   @0x2386f8 b 0x238674 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0xdc>
 *   @0x2386fc mov r9, #0
 *   @0x238700 b 0x2386d4 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x13c>
 *   @0x238704 mov r8, r3
 *   @0x238708 b 0x238600 <_ZN13CPhysicsWorld27FindBaseObjectForCollisionsEii+0x68>
 *   @0x23870c andseq r5, r11, r8, lsl #13
 *   @0x238710 andseq r8, r11, r0, lsr #2
 *   @0x238714 andseq r8, r11, r0, rrx
 */
