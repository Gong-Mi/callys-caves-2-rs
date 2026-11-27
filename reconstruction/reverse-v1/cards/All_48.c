/* cally 逆向卡：All_48 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 94 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/94 GR_3D_Vertex_Texture_Color(float, float, float, float, float, unsigned int, float)  0x1770c8  size 332  83 条（0x1770c8..0x177214）
 * @func 0x1770c8 0x177214  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_Texture_Color(float, float, float, float, float, unsigned int, float)+0x4c / HandleOverflow() / ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x11c×1 / 0x118×1 / 0x114×1 / 0x2c×1 / 0x30×1 / 0xdc×1 / 0x14×1 / 0x10×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1770c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1770cc vpush {d8}
 *   @0x1770d0 mov r9, r0
 *   @0x1770d4 ldr r5, [pc, #0x11c]
 *   @0x1770d8 mov r8, r1
 *   @0x1770dc ldr r0, [pc, #0x118]
 *   @0x1770e0 vmov s16, r3
 *   @0x1770e4 ldr r1, [pc, #0x114]
 *   @0x1770e8 add r5, pc, r5
 *   @0x1770ec mov r7, r2
 *   @0x1770f0 ldr r10, [sp, #0x2c]
 *   @0x1770f4 ldr r6, [r5, r0]
 *   @0x1770f8 ldr r3, [r5, r1]
 *   @0x1770fc ldr r4, [sp, #0x30]
 *   @0x177100 ldr r2, [r6]
 *   @0x177104 ldr r3, [r3]
 *   @0x177108 cmp r2, r3
 *   @0x17710c blt 0x177114 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x4c>
 *   @0x177110 bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x177114 mov r0, r4
 *   @0x177118 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x17711c ldr r4, [r6]
 *   @0x177120 ldr r2, [pc, #0xdc]
 *   @0x177124 mov r3, #0
 *   @0x177128 add r4, r4, r4, lsl #3
 *   @0x17712c ldr r2, [r5, r2]
 *   @0x177130 add r4, r2, r4, lsl #2
 *   @0x177134 str r3, [r4, #0x14]
 *   @0x177138 str r3, [r4, #0x10]
 *   @0x17713c str r3, [r4, #0xc]
 *   @0x177140 str r9, [r4]
 *   @0x177144 str r8, [r4, #0x4]
 *   @0x177148 str r7, [r4, #0x8]
 *   @0x17714c mov r1, r0
 *   @0x177150 orr r0, r10, #1
 *   @0x177154 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x177158 ldr r3, [pc, #0xa8]
 *   @0x17715c str r0, [r4, #0x18]
 *   @0x177160 ldr r3, [r5, r3]
 *   @0x177164 ldr r3, [r3]
 *   @0x177168 cmp r3, #0
 *   @0x17716c beq 0x1771e8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x120>
 *   @0x177170 ldrsh r1, [r3]
 *   @0x177174 ldrsh r2, [r3, #12]
 *   @0x177178 vmov s14, r1
 *   @0x17717c ldrsh r1, [r3, #2]
 *   @0x177180 vmov s11, r2
 *   @0x177184 ldrsh r3, [r3, #14]
 *   @0x177188 vcvt.f32.s32 s14, s14
 *   @0x17718c ldr r2, [pc, #0x78]
 *   @0x177190 vmov s15, r1
 *   @0x177194 vmov s13, r3
 *   @0x177198 ldr r3, [r5, r2]
 *   @0x17719c vldr s12, [r3]
 *   @0x1771a0 ldr r3, [pc, #0x68]
 *   @0x1771a4 vcvt.f32.s32 s11, s11
 *   @0x1771a8 vmla.f32 s14, s16, s11
 *   @0x1771ac vdiv.f32 s14, s14, s12
 *   @0x1771b0 vldr s12, [sp, #40]
 *   @0x1771b4 vcvt.f32.s32 s15, s15
 *   @0x1771b8 vstr s14, [r4, #28]
 *   @0x1771bc ldr r3, [r5, r3]
 *   @0x1771c0 vldr s14, [r3]
 *   @0x1771c4 vcvt.f32.s32 s13, s13
 *   @0x1771c8 vmla.f32 s15, s12, s13
 *   @0x1771cc vdiv.f32 s15, s15, s14
 *   @0x1771d0 vstr s15, [r4, #32]
 *   @0x1771d4 vpop {d8}
 *   @0x1771d8 ldr r3, [r6]
 *   @0x1771dc add r3, r3, #1
 *   @0x1771e0 str r3, [r6]
 *   @0x1771e4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1771e8 vldr s12, [sp, #40]
 *   @0x1771ec vstr s16, [r4, #28]
 *   @0x1771f0 vstr s12, [r4, #32]
 *   @0x1771f4 b 0x1771d4 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x10c>
 *   @0x1771f8 eoreq r10, r7, r8, ror #22
 *   @0x1771fc .word 0xffffe670
 *   @0x177200 .word 0xffffe67c
 *   @0x177204 .word 0xffffe680
 *   @0x177208 .word 0xffffe540
 *   @0x17720c .word 0xffffe544
 *   @0x177210 .word 0xffffe548
 *
 * ══ §2/94 Motion_Linear_Path(CInstance*, CPath*, float, float, float, int, bool)  0x19c9cc  size 332  83 条（0x19c9cc..0x19cb18）
 * @func 0x19c9cc 0x19cb18  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::AddPoint(float, float, float)×3 / Motion_Linear_Path(CInstance*, CPath*, float, float, float, int, bool)+0x128 / CPath::Clear() / CPath::SetKind(int) / CPath::SetClosed(bool) / Motion_Linear_Step(CInstance*, float, float, float, int, bool) / CInstance::SetPosition(float, float) / CInstance::SetDirection(float)
 * 字段偏移 top8: 0xb4×2 / 0xb8×2 / 0xc×2 / 0x4c×1 / 0x50×1 / 0xcc×1 / 0x4×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c9cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19c9d0 vpush {d8, d9}
 *   @0x19c9d4 subs r4, r1, #0
 *   @0x19c9d8 sub sp, sp, #20
 *   @0x19c9dc mov r9, r0
 *   @0x19c9e0 mov r6, r2
 *   @0x19c9e4 vldr s18, [sp, #72]
 *   @0x19c9e8 mov r5, r3
 *   @0x19c9ec ldr r7, [sp, #0x4c]
 *   @0x19c9f0 ldrb r8, [sp, #0x50]
 *   @0x19c9f4 beq 0x19cb08 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x13c>
 *   @0x19c9f8 vcmpe.f32 s18, #0
 *   @0x19c9fc vmrs APSR_nzcv, fpscr
 *   @0x19ca00 movls r0, #0
 *   @0x19ca04 bls 0x19caf4 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x128>
 *   @0x19ca08 ldr r3, [r9, #0xb4]
 *   @0x19ca0c mov r0, r4
 *   @0x19ca10 ldr r10, [r9, #0xb8]
 *   @0x19ca14 ldr r11, [r9, #0xcc]
 *   @0x19ca18 str r3, [sp, #0xc]
 *   @0x19ca1c bl 0x1a6f98 <_ZN5CPath5ClearEv>
 *   @0x19ca20 mov r0, r4
 *   @0x19ca24 mov r1, #0
 *   @0x19ca28 bl 0x1a6e64 <_ZN5CPath7SetKindEi>
 *   @0x19ca2c mov r0, r4
 *   @0x19ca30 mov r1, #0
 *   @0x19ca34 bl 0x1a6e78 <_ZN5CPath9SetClosedEb>
 *   @0x19ca38 mov r0, r4
 *   @0x19ca3c ldr r1, [r9, #0xb4]
 *   @0x19ca40 mov r3, #0
 *   @0x19ca44 ldr r2, [r9, #0xb8]
 *   @0x19ca48 movt r3, #0x42c8
 *   @0x19ca4c bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19ca50 b 0x19ca80 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0xb4>
 *   @0x19ca54 vldr s15, [r9, #180]
 *   @0x19ca58 vcmp.f32 s16, s15
 *   @0x19ca5c vmov r1, s15
 *   @0x19ca60 vldr s15, [r9, #184]
 *   @0x19ca64 vmrs APSR_nzcv, fpscr
 *   @0x19ca68 bne 0x19ca78 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0xac>
 *   @0x19ca6c vcmp.f32 s17, s15
 *   @0x19ca70 vmrs APSR_nzcv, fpscr
 *   @0x19ca74 beq 0x19cb00 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x134>
 *   @0x19ca78 vmov r2, s15
 *   @0x19ca7c bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19ca80 str r7, [sp]
 *   @0x19ca84 mov r2, r5
 *   @0x19ca88 str r8, [sp, #0x4]
 *   @0x19ca8c mov r0, r9
 *   @0x19ca90 vmov r3, s18
 *   @0x19ca94 mov r1, r6
 *   @0x19ca98 vldr s16, [r9, #180]
 *   @0x19ca9c vldr s17, [r9, #184]
 *   @0x19caa0 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x19caa4 mov r3, #0
 *   @0x19caa8 movt r3, #0x42c8
 *   @0x19caac subs r2, r0, #0
 *   @0x19cab0 mov r0, r4
 *   @0x19cab4 beq 0x19ca54 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x88>
 *   @0x19cab8 mov r0, r4
 *   @0x19cabc mov r3, #0
 *   @0x19cac0 mov r1, r6
 *   @0x19cac4 mov r2, r5
 *   @0x19cac8 movt r3, #0x42c8
 *   @0x19cacc mov r4, #1
 *   @0x19cad0 bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19cad4 ldr r1, [sp, #0xc]
 *   @0x19cad8 mov r0, r9
 *   @0x19cadc mov r2, r10
 *   @0x19cae0 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x19cae4 mov r0, r9
 *   @0x19cae8 mov r1, r11
 *   @0x19caec bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19caf0 mov r0, r4
 *   @0x19caf4 add sp, sp, #20
 *   @0x19caf8 vpop {d8, d9}
 *   @0x19cafc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19cb00 mov r4, r2
 *   @0x19cb04 b 0x19cad4 <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib+0x108>
 *   @0x19cb08 mov r0, r4
 *   @0x19cb0c add sp, sp, #20
 *   @0x19cb10 vpop {d8, d9}
 *   @0x19cb14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §3/94 FINALIZE_Particle_Main()  0x1a5de8  size 332  83 条（0x1a5de8..0x1a5f34）
 * @func 0x1a5de8 0x1a5f34  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / FINALIZE_Particle_Main()+0x78 / FINALIZE_Particle_Main()+0xcc / operator delete(void*) / FINALIZE_Particle_Main()+0x20 / ParticleType_DestroyAll() / ParticleSystem_DestroyAll() / Graphics::FreeTexture(void*)
 * 字段偏移 top8: 0x4×10 / 0x2×4 / 0xc×3 / 0x10×3 / 0x14×2 / 0x130×1 / 0x8×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5de8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a5dec mov r8, #0
 *   @0x1a5df0 ldr r6, [pc, #0x130]
 *   @0x1a5df4 mov r7, r8
 *   @0x1a5df8 ldr r6, [pc, r6]
 *   @0x1a5dfc ldr r2, [r6]
 *   @0x1a5e00 cmp r8, r2
 *   @0x1a5e04 bge 0x1a5ee0 <_Z22FINALIZE_Particle_Mainv+0xf8>
 *   @0x1a5e08 ldr r3, [r6, #0x4]
 *   @0x1a5e0c lsl r5, r8, #2
 *   @0x1a5e10 ldr r3, [r3, r8, lsl #2]
 *   @0x1a5e14 cmp r3, #0
 *   @0x1a5e18 beq 0x1a5ed4 <_Z22FINALIZE_Particle_Mainv+0xec>
 *   @0x1a5e1c ldr r2, [r3]
 *   @0x1a5e20 cmp r2, #0
 *   @0x1a5e24 ble 0x1a5e60 <_Z22FINALIZE_Particle_Mainv+0x78>
 *   @0x1a5e28 mov r4, #0
 *   @0x1a5e2c ldr r3, [r3, #0x4]
 *   @0x1a5e30 ldr r0, [r3, r4, lsl #2]
 *   @0x1a5e34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a5e38 ldr r3, [r6, #0x4]
 *   @0x1a5e3c ldr r3, [r3, r5]
 *   @0x1a5e40 ldr r3, [r3, #0x4]
 *   @0x1a5e44 str r7, [r3, r4, lsl #2]
 *   @0x1a5e48 add r4, r4, #1
 *   @0x1a5e4c ldr r3, [r6, #0x4]
 *   @0x1a5e50 ldr r3, [r3, r5]
 *   @0x1a5e54 ldr r2, [r3]
 *   @0x1a5e58 cmp r2, r4
 *   @0x1a5e5c bgt 0x1a5e2c <_Z22FINALIZE_Particle_Mainv+0x44>
 *   @0x1a5e60 ldr r0, [r3, #0x4]
 *   @0x1a5e64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a5e68 ldr r3, [r6, #0x4]
 *   @0x1a5e6c ldr r2, [r3, r5]
 *   @0x1a5e70 str r7, [r2, #0x4]
 *   @0x1a5e74 ldr r3, [r3, r5]
 *   @0x1a5e78 ldr r2, [r3, #0xc]
 *   @0x1a5e7c str r7, [r3]
 *   @0x1a5e80 cmp r2, #0
 *   @0x1a5e84 str r7, [r3, #0x8]
 *   @0x1a5e88 ble 0x1a5eb4 <_Z22FINALIZE_Particle_Mainv+0xcc>
 *   @0x1a5e8c mov r4, #0
 *   @0x1a5e90 ldr r3, [r3, #0x10]
 *   @0x1a5e94 ldr r0, [r3, r4, lsl #2]
 *   @0x1a5e98 add r4, r4, #1
 *   @0x1a5e9c bl 0x27d1d0 <_ZdlPv>
 *   @0x1a5ea0 ldr r3, [r6, #0x4]
 *   @0x1a5ea4 ldr r3, [r3, r5]
 *   @0x1a5ea8 ldr r2, [r3, #0xc]
 *   @0x1a5eac cmp r2, r4
 *   @0x1a5eb0 bgt 0x1a5e90 <_Z22FINALIZE_Particle_Mainv+0xa8>
 *   @0x1a5eb4 ldr r0, [r3, #0x10]
 *   @0x1a5eb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a5ebc ldm r6, {r2, r3}
 *   @0x1a5ec0 ldr r1, [r3, r5]
 *   @0x1a5ec4 str r7, [r1, #0x10]
 *   @0x1a5ec8 ldr r3, [r3, r5]
 *   @0x1a5ecc str r7, [r3, #0xc]
 *   @0x1a5ed0 str r7, [r3, #0x14]
 *   @0x1a5ed4 add r8, r8, #1
 *   @0x1a5ed8 cmp r8, r2
 *   @0x1a5edc blt 0x1a5e08 <_Z22FINALIZE_Particle_Mainv+0x20>
 *   @0x1a5ee0 ldr r4, [pc, #0x44]
 *   @0x1a5ee4 bl 0x1a2d90 <_Z23ParticleType_DestroyAllv>
 *   @0x1a5ee8 bl 0x1a4590 <_Z25ParticleSystem_DestroyAllv>
 *   @0x1a5eec mov r6, #0
 *   @0x1a5ef0 ldr r4, [pc, r4]
 *   @0x1a5ef4 add r5, r4, #60
 *   @0x1a5ef8 ldr r0, [r4], #4
 *   @0x1a5efc cmp r0, #0
 *   @0x1a5f00 beq 0x1a5f0c <_Z22FINALIZE_Particle_Mainv+0x124>
 *   @0x1a5f04 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv>
 *   @0x1a5f08 str r6, [r4, #-0x4]
 *   @0x1a5f0c cmp r4, r5
 *   @0x1a5f10 bne 0x1a5ef8 <_Z22FINALIZE_Particle_Mainv+0x110>
 *   @0x1a5f14 ldr r3, [pc, #0x14]
 *   @0x1a5f18 mov r2, #0
 *   @0x1a5f1c ldr r3, [pc, r3]
 *   @0x1a5f20 str r2, [r3]
 *   @0x1a5f24 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a5f28 eoreq r10, r4, r0, asr #19
 *   @0x1a5f2c .word 0x0024a8d0
 *   @0x1a5f30 eoreq r10, r4, r8, lsr #17
 *
 * ══ §4/94 CSound::Restore()  0x215540  size 332  83 条（0x215540..0x21568c）
 * @func 0x215540 0x21568c  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SND_AddFromMemory(void*, int)×3 / CSound::Restore()+0xc0×2 / 0xb65e0 / CSound::Restore()+0xc8 / SND_Set_Effect(int, int) / SND_Set_Volume(int, double, int) / SND_AddFromMemory(CStream*, int)
 * 字段偏移 top8: 0x30×7 / 0x4×3 / 0x134×1 / 0xc×1 / 0x10×1 / 0x38×1 / 0xe4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215540 push {r4, r5, lr}
 *   @0x215544 mov r4, r0
 *   @0x215548 ldr r3, [pc, #0x134]
 *   @0x21554c sub sp, sp, #12
 *   @0x215550 ldr r5, [r0, #0x4]
 *   @0x215554 ldr r2, [r0, #0xc]
 *   @0x215558 ldr r3, [pc, r3]
 *   @0x21555c cmp r5, #0
 *   @0x215560 str r2, [r3]
 *   @0x215564 bne 0x21559c <_ZN6CSound7RestoreEv+0x5c>
 *   @0x215568 ldr r3, [r4, #0x10]
 *   @0x21556c ldr r0, [r4, #0x38]
 *   @0x215570 cmp r3, #0
 *   @0x215574 beq 0x215648 <_ZN6CSound7RestoreEv+0x108>
 *   @0x215578 cmp r0, #0
 *   @0x21557c beq 0x215670 <_ZN6CSound7RestoreEv+0x130>
 *   @0x215580 mov r1, r5
 *   @0x215584 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi>
 *   @0x215588 str r0, [r4, #0x30]
 *   @0x21558c cmn r0, #1
 *   @0x215590 beq 0x215654 <_ZN6CSound7RestoreEv+0x114>
 *   @0x215594 ldr r5, [r4, #0x4]
 *   @0x215598 b 0x2155d0 <_ZN6CSound7RestoreEv+0x90>
 *   @0x21559c ldr r1, [pc, #0xe4]
 *   @0x2155a0 mov r2, #4
 *   @0x2155a4 ldr r0, [r0, #0x8]
 *   @0x2155a8 add r1, pc, r1
 *   @0x2155ac bl 0xb65e0 <strncmp@plt>
 *   @0x2155b0 cmp r0, #0
 *   @0x2155b4 beq 0x215634 <_ZN6CSound7RestoreEv+0xf4>
 *   @0x2155b8 subs r3, r5, #3
 *   @0x2155bc movne r3, #1
 *   @0x2155c0 cmp r5, #0
 *   @0x2155c4 movlt r3, #0
 *   @0x2155c8 cmp r3, #0
 *   @0x2155cc bne 0x215568 <_ZN6CSound7RestoreEv+0x28>
 *   @0x2155d0 cmp r5, #3
 *   @0x2155d4 beq 0x21565c <_ZN6CSound7RestoreEv+0x11c>
 *   @0x2155d8 ldr r0, [r4, #0x30]
 *   @0x2155dc cmp r0, #0
 *   @0x2155e0 blt 0x215600 <_ZN6CSound7RestoreEv+0xc0>
 *   @0x2155e4 ldr r1, [r4, #0x18]
 *   @0x2155e8 cmp r1, #0
 *   @0x2155ec ble 0x215608 <_ZN6CSound7RestoreEv+0xc8>
 *   @0x2155f0 bl 0x21f120 <_Z14SND_Set_Effectii>
 *   @0x2155f4 ldr r0, [r4, #0x30]
 *   @0x2155f8 cmp r0, #0
 *   @0x2155fc bge 0x215608 <_ZN6CSound7RestoreEv+0xc8>
 *   @0x215600 add sp, sp, #12
 *   @0x215604 pop {r4, r5, pc}
 *   @0x215608 ldrd r2, r3, [r4, #32]
 *   @0x21560c mov r1, #0
 *   @0x215610 str r1, [sp]
 *   @0x215614 bl 0x21f07c <_Z14SND_Set_Volumeidi>
 *   @0x215618 ldr r0, [r4, #0x30]
 *   @0x21561c cmp r0, #0
 *   @0x215620 blt 0x215600 <_ZN6CSound7RestoreEv+0xc0>
 *   @0x215624 ldrd r2, r3, [r4, #40]
 *   @0x215628 add sp, sp, #12
 *   @0x21562c pop {r4, r5, lr}
 *   @0x215630 b 0x21f11c <_Z15SND_Set_Panningid>
 *   @0x215634 mov r1, r5
 *   @0x215638 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi>
 *   @0x21563c str r0, [r4, #0x30]
 *   @0x215640 add sp, sp, #12
 *   @0x215644 pop {r4, r5, pc}
 *   @0x215648 cmp r0, #0
 *   @0x21564c bne 0x215580 <_ZN6CSound7RestoreEv+0x40>
 *   @0x215650 b 0x215600 <_ZN6CSound7RestoreEv+0xc0>
 *   @0x215654 mov r3, #3
 *   @0x215658 str r3, [r4, #0x4]
 *   @0x21565c mov r0, #0
 *   @0x215660 mov r1, #3
 *   @0x215664 bl 0x21e9f8 <_Z17SND_AddFromMemoryPvi>
 *   @0x215668 str r0, [r4, #0x30]
 *   @0x21566c b 0x2155dc <_ZN6CSound7RestoreEv+0x9c>
 *   @0x215670 mov r0, r3
 *   @0x215674 mov r1, r5
 *   @0x215678 bl 0x21ea60 <_Z17SND_AddFromMemoryP7CStreami>
 *   @0x21567c str r0, [r4, #0x30]
 *   @0x215680 b 0x21558c <_ZN6CSound7RestoreEv+0x4c>
 *   @0x215684 andseq r11, sp, r12, ror #28
 *   @0x215688 ldrsheq lr, [r3], -r4
 *
 * ══ §5/94 SND_AddEmpty(int)  0x21e7f4  size 332  83 条（0x21e7f4..0x21e940）
 * @func 0x21e7f4 0x21e940  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21e7f8→0x755334, 0x21e810→0x755338
 * 调用序列: MemoryManager::Free(void const*)×2 / SND_AddEmpty(int)+0x124 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×6 / 0x134×2 / 0x120×1 / 0x14×1 / 0x94×1 / 0x1×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e7f4 ldr r3, [pc, #0x134]
 *   @0x21e7f8 ldr r2, [pc, #0x134]
 *   @0x21e7fc add r3, pc, r3
 *   @0x21e800 push {r4, r6, r7, r8, r9, r10, lr}
 *   @0x21e804 mov r6, r0
 *   @0x21e808 ldr r7, [r3, r2]
 *   @0x21e80c sub sp, sp, #12
 *   @0x21e810 ldr r2, [pc, #0x120]
 *   @0x21e814 ldr r12, [r7]
 *   @0x21e818 ldr r8, [r3, r2]
 *   @0x21e81c cmp r12, #0
 *   @0x21e820 ble 0x21e918 <_Z12SND_AddEmptyi+0x124>
 *   @0x21e824 ldr r0, [r8, #0x4]
 *   @0x21e828 ldrb r4, [r0]
 *   @0x21e82c cmp r4, #0
 *   @0x21e830 beq 0x21e928 <_Z12SND_AddEmptyi+0x134>
 *   @0x21e834 add r3, r0, #20
 *   @0x21e838 mov r4, #0
 *   @0x21e83c b 0x21e84c <_Z12SND_AddEmptyi+0x58>
 *   @0x21e840 ldrb r2, [r3], #20
 *   @0x21e844 cmp r2, #0
 *   @0x21e848 beq 0x21e8d4 <_Z12SND_AddEmptyi+0xe0>
 *   @0x21e84c add r4, r4, #1
 *   @0x21e850 mov r1, r3
 *   @0x21e854 cmp r4, r12
 *   @0x21e858 bne 0x21e840 <_Z12SND_AddEmptyi+0x4c>
 *   @0x21e85c add r12, r4, r4, lsl #2
 *   @0x21e860 adds r9, r4, #1
 *   @0x21e864 lsl r10, r12, #2
 *   @0x21e868 bne 0x21e894 <_Z12SND_AddEmptyi+0xa0>
 *   @0x21e86c cmp r0, #0
 *   @0x21e870 beq 0x21e904 <_Z12SND_AddEmptyi+0x110>
 *   @0x21e874 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e878 str r9, [r8, #0x4]
 *   @0x21e87c mov r1, r9
 *   @0x21e880 b 0x21e8c0 <_Z12SND_AddEmptyi+0xcc>
 *   @0x21e884 mov r10, r12
 *   @0x21e888 mov r0, r1
 *   @0x21e88c mov r4, r12
 *   @0x21e890 mov r9, #1
 *   @0x21e894 add r3, r9, r9, lsl #2
 *   @0x21e898 lsls r1, r3, #2
 *   @0x21e89c beq 0x21e904 <_Z12SND_AddEmptyi+0x110>
 *   @0x21e8a0 ldr r2, [pc, #0x94]
 *   @0x21e8a4 mov r3, #0
 *   @0x21e8a8 str r3, [sp]
 *   @0x21e8ac mov r3, #106
 *   @0x21e8b0 add r2, pc, r2
 *   @0x21e8b4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21e8b8 mov r1, r0
 *   @0x21e8bc str r0, [r8, #0x4]
 *   @0x21e8c0 ldr r3, [r7]
 *   @0x21e8c4 add r1, r1, r10
 *   @0x21e8c8 str r9, [r8]
 *   @0x21e8cc add r3, r3, #1
 *   @0x21e8d0 str r3, [r7]
 *   @0x21e8d4 mov r3, #0
 *   @0x21e8d8 mov r2, #1
 *   @0x21e8dc cmp r6, #3
 *   @0x21e8e0 str r6, [r1, #0x4]
 *   @0x21e8e4 mov r0, r4
 *   @0x21e8e8 strb r2, [r1]
 *   @0x21e8ec strb r3, [r1, #0x1]
 *   @0x21e8f0 str r3, [r1, #0x8]
 *   @0x21e8f4 str r3, [r1, #0xc]
 *   @0x21e8f8 streq r2, [r1, #0x4]
 *   @0x21e8fc add sp, sp, #12
 *   @0x21e900 pop {r4, r6, r7, r8, r9, r10, pc}
 *   @0x21e904 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e908 mov r3, #0
 *   @0x21e90c mov r1, r3
 *   @0x21e910 str r3, [r8, #0x4]
 *   @0x21e914 b 0x21e8c0 <_Z12SND_AddEmptyi+0xcc>
 *   @0x21e918 ldr r1, [r8, #0x4]
 *   @0x21e91c beq 0x21e884 <_Z12SND_AddEmptyi+0x90>
 *   @0x21e920 mov r4, #0
 *   @0x21e924 b 0x21e8d4 <_Z12SND_AddEmptyi+0xe0>
 *   @0x21e928 mov r1, r0
 *   @0x21e92c b 0x21e8d4 <_Z12SND_AddEmptyi+0xe0>
 *   @0x21e930 andseq r3, sp, r4, asr r4
 *   @0x21e934 .word 0xfffff7c4
 *   @0x21e938 .word 0xfffff7c8
 *   @0x21e93c andseq r5, r3, r8, lsl #29
 *
 * ══ §6/94 spCurveTimeline_getCurvePercent  0x2818e0  size 332  83 条（0x2818e0..0x281a2c）
 * @func 0x2818e0 0x281a2c  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spCurveTimeline_getCurvePercent+0xf8
 * 字段偏移 top8: 0x8×1
 * VFP 指令 43 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2818e0 vmov s15, r2
 *   @0x2818e4 add r3, r1, r1, lsl #3
 *   @0x2818e8 ldr r0, [r0, #0x8]
 *   @0x2818ec vcmpe.f32 s15, #0
 *   @0x2818f0 add r1, r1, r3, lsl #1
 *   @0x2818f4 push {r4, r5}
 *   @0x2818f8 add r3, r0, r1, lsl #2
 *   @0x2818fc vldr s14, [r3]
 *   @0x281900 vmrs APSR_nzcv, fpscr
 *   @0x281904 bmi 0x2819d0 <spCurveTimeline_getCurvePercent+0xf0>
 *   @0x281908 vmov.f32 s13, #1.000000e+00
 *   @0x28190c vcmp.f32 s15, s13
 *   @0x281910 vmrs APSR_nzcv, fpscr
 *   @0x281914 vmovgt.f32 s15, s13
 *   @0x281918 vcmp.f32 s14, #0
 *   @0x28191c vmrs APSR_nzcv, fpscr
 *   @0x281920 beq 0x2819b4 <spCurveTimeline_getCurvePercent+0xd4>
 *   @0x281924 vmov.f32 s13, #1.000000e+00
 *   @0x281928 vcmp.f32 s14, s13
 *   @0x28192c vmrs APSR_nzcv, fpscr
 *   @0x281930 beq 0x2819c0 <spCurveTimeline_getCurvePercent+0xe0>
 *   @0x281934 add r4, r1, #1
 *   @0x281938 lsl r2, r4, #2
 *   @0x28193c mov r12, r4
 *   @0x281940 add r3, r0, r2
 *   @0x281944 vldr s14, [r3]
 *   @0x281948 vcmpe.f32 s15, s14
 *   @0x28194c vmrs APSR_nzcv, fpscr
 *   @0x281950 addhi r2, r2, #8
 *   @0x281954 addhi r1, r1, #19
 *   @0x281958 addhi r2, r0, r2
 *   @0x28195c movhi r3, r4
 *   @0x281960 bhi 0x281980 <spCurveTimeline_getCurvePercent+0xa0>
 *   @0x281964 b 0x281a1c <spCurveTimeline_getCurvePercent+0x13c>
 *   @0x281968 mov r5, r2
 *   @0x28196c vldr s14, [r5]
 *   @0x281970 vcmpe.f32 s15, s14
 *   @0x281974 add r2, r2, #8
 *   @0x281978 vmrs APSR_nzcv, fpscr
 *   @0x28197c bls 0x2819d8 <spCurveTimeline_getCurvePercent+0xf8>
 *   @0x281980 add r3, r3, #2
 *   @0x281984 cmp r3, r1
 *   @0x281988 mov r12, r3
 *   @0x28198c bne 0x281968 <spCurveTimeline_getCurvePercent+0x88>
 *   @0x281990 vmov.f32 s12, #1.000000e+00
 *   @0x281994 add r3, r0, r3, lsl #2
 *   @0x281998 vldr s13, [r3, #-4]
 *   @0x28199c vsub.f32 s15, s15, s14
 *   @0x2819a0 vsub.f32 s11, s12, s13
 *   @0x2819a4 vmul.f32 s15, s11, s15
 *   @0x2819a8 vsub.f32 s14, s12, s14
 *   @0x2819ac vdiv.f32 s15, s15, s14
 *   @0x2819b0 vadd.f32 s15, s15, s13
 *   @0x2819b4 vmov r0, s15
 *   @0x2819b8 pop {r4, r5}
 *   @0x2819bc bx lr
 *   @0x2819c0 vldr s15, [pc, #96]
 *   @0x2819c4 pop {r4, r5}
 *   @0x2819c8 vmov r0, s15
 *   @0x2819cc bx lr
 *   @0x2819d0 vldr s15, [pc, #80]
 *   @0x2819d4 b 0x281918 <spCurveTimeline_getCurvePercent+0x38>
 *   @0x2819d8 cmp r4, r12
 *   @0x2819dc beq 0x281a1c <spCurveTimeline_getCurvePercent+0x13c>
 *   @0x2819e0 sub r3, r12, #-1073741822
 *   @0x2819e4 add r3, r0, r3, lsl #2
 *   @0x2819e8 vldr s12, [r3]
 *   @0x2819ec vldr s13, [r3, #4]
 *   @0x2819f0 add r0, r0, r12, lsl #2
 *   @0x2819f4 vsub.f32 s15, s15, s12
 *   @0x2819f8 vldr s11, [r0, #4]
 *   @0x2819fc pop {r4, r5}
 *   @0x281a00 vsub.f32 s11, s11, s13
 *   @0x281a04 vmul.f32 s15, s11, s15
 *   @0x281a08 vsub.f32 s14, s14, s12
 *   @0x281a0c vdiv.f32 s15, s15, s14
 *   @0x281a10 vadd.f32 s15, s15, s13
 *   @0x281a14 vmov r0, s15
 *   @0x281a18 bx lr
 *   @0x281a1c vldr s13, [pc, #4]
 *   @0x281a20 vmov.f32 s12, s13
 *   @0x281a24 b 0x2819f0 <spCurveTimeline_getCurvePercent+0x110>
 *   @0x281a28 andeq r0, r0, r0
 *
 * ══ §7/94 F_NETWORK_Send_Broadcast(RValue&, CInstance*, CInstance*, int, RValue*)  0x2985d0  size 332  83 条（0x2985d0..0x29871c）
 * @func 0x2985d0 0x29871c  size 332  83 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / GetIBuffer(int)×2 / yySocket::Broadcast(int, unsigned char*, int) / yySocket::Startup()
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x12c×1 / 0x20×1 / 0x100×1 / 0x88×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2985d0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2985d4 mov r2, #0
 *   @0x2985d8 ldr r4, [pc, #0x12c]
 *   @0x2985dc mov r3, r2
 *   @0x2985e0 str r2, [r0]
 *   @0x2985e4 movt r3, #0xbff0
 *   @0x2985e8 ldr r4, [pc, r4]
 *   @0x2985ec str r2, [r0, #0xc]
 *   @0x2985f0 mov r5, r0
 *   @0x2985f4 str r3, [r0, #0x4]
 *   @0x2985f8 ldrb r2, [r4]
 *   @0x2985fc ldr r6, [sp, #0x20]
 *   @0x298600 cmp r2, #0
 *   @0x298604 beq 0x2986ec <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x298608 ldr r3, [pc, #0x100]
 *   @0x29860c ldr r3, [pc, r3]
 *   @0x298610 ldr r3, [r3]
 *   @0x298614 sub r3, r3, #2
 *   @0x298618 cmp r3, #2
 *   @0x29861c pophi {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x298620 mov r1, #2
 *   @0x298624 mov r0, r6
 *   @0x298628 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29862c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x298630 subs r1, r0, #0
 *   @0x298634 beq 0x2986fc <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x298638 mov r0, r6
 *   @0x29863c mov r1, #0
 *   @0x298640 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298644 mov r1, #1
 *   @0x298648 mov r4, r0
 *   @0x29864c mov r0, r6
 *   @0x298650 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298654 mov r1, #2
 *   @0x298658 mov r8, r0
 *   @0x29865c mov r0, r6
 *   @0x298660 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298664 mov r1, #3
 *   @0x298668 mov r7, r0
 *   @0x29866c mov r0, r6
 *   @0x298670 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298674 cmp r4, #63
 *   @0x298678 mov r6, r0
 *   @0x29867c pophi {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x298680 add r4, r4, r4, lsl #1
 *   @0x298684 ldr r12, [pc, #0x88]
 *   @0x298688 lsl r4, r4, #2
 *   @0x29868c ldr r12, [pc, r12]
 *   @0x298690 add r9, r12, r4
 *   @0x298694 ldrb r3, [r12, r4]
 *   @0x298698 cmp r3, #0
 *   @0x29869c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2986a0 mov r0, r7
 *   @0x2986a4 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x2986a8 subs r3, r0, #0
 *   @0x2986ac popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2986b0 ldr r0, [r9, #0x4]
 *   @0x2986b4 mov r1, r8
 *   @0x2986b8 ldr r2, [r3, #0xc]
 *   @0x2986bc cmp r0, #0
 *   @0x2986c0 ldreq r3, [r9, #0x8]
 *   @0x2986c4 ldreq r0, [r3]
 *   @0x2986c8 mov r3, r6
 *   @0x2986cc bl 0x295bc8 <_ZN8yySocket9BroadcastEiPhi>
 *   @0x2986d0 cmp r0, #0
 *   @0x2986d4 vmovlt s15, r0
 *   @0x2986d8 vmovge s15, r6
 *   @0x2986dc vcvt.f64.s32 d7, s15
 *   @0x2986e0 vmov r2, r3, d7
 *   @0x2986e4 stm r5, {r2, r3}
 *   @0x2986e8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2986ec bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x2986f0 mov r3, #1
 *   @0x2986f4 strb r3, [r4]
 *   @0x2986f8 b 0x298608 <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x2986fc ldr r0, [pc, #0x14]
 *   @0x298700 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x298704 add r0, pc, r0
 *   @0x298708 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x29870c ldrheq r9, [r5], -r4
 *   @0x298710 andseq r7, r5, r4, lsl sp
 *   @0x298714 andseq r9, r5, r8, lsl r3
 *   @0x298718 andeq r0, r12, r0, ror pc
 *
 * ══ §8/94 CSkeletonInstance::CreateAttachment(char const*, CSprite*, int, float, float, float, float, float)  0xbfb44  size 328  82 条（0xbfb44..0xbfc8c）
 * @func 0xbfb44 0xbfc8c  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod / CSkeletonInstance::CreateAttachment(char const*, char const*, short, int, int, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x2×3 / 0x5c×2 / 0x28×2 / 0x54×1 / 0x18×1 / 0x108×1 / 0x4×1 / 0xc×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbfb44 push {r4, r5, r6, r7, lr}
 *   @0xbfb48 mov r4, r2
 *   @0xbfb4c ldr r5, [r2, #0x54]
 *   @0xbfb50 sub sp, sp, #52
 *   @0xbfb54 mov r7, r0
 *   @0xbfb58 mov r6, r1
 *   @0xbfb5c cmp r5, #0
 *   @0xbfb60 beq 0xbfc54 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff+0x110>
 *   @0xbfb64 ldr r1, [r2, #0x18]
 *   @0xbfb68 mov r0, r3
 *   @0xbfb6c bl 0x318dec <__aeabi_idivmod>
 *   @0xbfb70 ldr r3, [pc, #0x108]
 *   @0xbfb74 mov r0, r7
 *   @0xbfb78 ldr r2, [r4, #0x5c]
 *   @0xbfb7c ldr r3, [pc, r3]
 *   @0xbfb80 ldr r7, [r3, #0x4]
 *   @0xbfb84 ldr r12, [r5, r1, lsl #2]
 *   @0xbfb88 mov r1, r6
 *   @0xbfb8c ldrh r3, [r12]
 *   @0xbfb90 ldrsh r4, [r12, #4]
 *   @0xbfb94 ldrh r6, [r12, #2]
 *   @0xbfb98 sxth r3, r3
 *   @0xbfb9c ldrsh lr, [r12, #6]
 *   @0xbfba0 add r5, r3, r4
 *   @0xbfba4 sxth r6, r6
 *   @0xbfba8 vmov s9, r3
 *   @0xbfbac vmov s11, r5
 *   @0xbfbb0 add r5, r6, lr
 *   @0xbfbb4 vcvt.f32.s32 s10, s9
 *   @0xbfbb8 ldrsh r3, [r12, #20]
 *   @0xbfbbc vmov s9, r6
 *   @0xbfbc0 vmov s12, r5
 *   @0xbfbc4 ldr r5, [r7, r3, lsl #2]
 *   @0xbfbc8 vldr s14, [r5, #8]
 *   @0xbfbcc vldr s15, [r5, #12]
 *   @0xbfbd0 stm sp, {r4, lr}
 *   @0xbfbd4 vcvt.f32.s32 s12, s12
 *   @0xbfbd8 vcvt.f32.s32 s13, s9
 *   @0xbfbdc vldr s9, [sp, #72]
 *   @0xbfbe0 vcvt.f32.s32 s11, s11
 *   @0xbfbe4 vmul.f32 s13, s13, s15
 *   @0xbfbe8 vmul.f32 s11, s14, s11
 *   @0xbfbec vstr s13, [sp, #12]
 *   @0xbfbf0 vmul.f32 s14, s10, s14
 *   @0xbfbf4 vstr s11, [sp, #16]
 *   @0xbfbf8 vmul.f32 s15, s15, s12
 *   @0xbfbfc vstr s14, [sp, #8]
 *   @0xbfc00 vldr s14, [sp, #80]
 *   @0xbfc04 vstr s15, [sp, #20]
 *   @0xbfc08 ldrsh r5, [r12, #8]
 *   @0xbfc0c vmov s15, r5
 *   @0xbfc10 vcvt.f32.s32 s15, s15
 *   @0xbfc14 vsub.f32 s15, s9, s15
 *   @0xbfc18 vldr s9, [sp, #84]
 *   @0xbfc1c vstr s15, [sp, #24]
 *   @0xbfc20 ldrsh r12, [r12, #10]
 *   @0xbfc24 vstr s9, [sp, #36]
 *   @0xbfc28 vldr s9, [sp, #76]
 *   @0xbfc2c vstr s14, [sp, #32]
 *   @0xbfc30 vldr s14, [sp, #88]
 *   @0xbfc34 vmov s15, r12
 *   @0xbfc38 vstr s14, [sp, #40]
 *   @0xbfc3c vcvt.f32.s32 s15, s15
 *   @0xbfc40 vsub.f32 s15, s9, s15
 *   @0xbfc44 vstr s15, [sp, #28]
 *   @0xbfc48 bl 0xbf9a0 <_ZN17CSkeletonInstance16CreateAttachmentEPKcS1_siifffffffff>
 *   @0xbfc4c add sp, sp, #52
 *   @0xbfc50 pop {r4, r5, r6, r7, pc}
 *   @0xbfc54 ldr r3, [pc, #0x28]
 *   @0xbfc58 ldr r1, [pc, #0x28]
 *   @0xbfc5c ldr r3, [pc, r3]
 *   @0xbfc60 ldr r2, [r2, #0x5c]
 *   @0xbfc64 add r1, pc, r1
 *   @0xbfc68 ldr r0, [r3]
 *   @0xbfc6c ldr r3, [r0]
 *   @0xbfc70 ldr r3, [r3, #0xc]
 *   @0xbfc74 blx r3
 *   @0xbfc78 add sp, sp, #52
 *   @0xbfc7c pop {r4, r5, r6, r7, pc}
 *   @0xbfc80 eorseq sp, r2, r0, lsr #27
 *   @0xbfc84 eorseq sp, r2, r4, ror #25
 *   @0xbfc88 eoreq r0, r7, r12, asr #23
 *
 * ══ §9/94 VM::WriteRenderStates(Buffer_Standard*, bool)  0xd8664  size 328  82 条（0xd8664..0xd87ac）
 * @func 0xd8664 0xd87ac  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd86ac→0x4859c8, 0xd86bc→0x3f23d0, 0xd86f8→0x3f23cc, 0xd8734→0x4859b0
 * 调用序列: RenderStateManager::WriteStatesToBuffer(Buffer_Standard*)
 * 字段偏移 top8: 0x38×5 / 0x30×5 / 0x8×5 / 0x2c×3 / 0x124×1 / 0xe8×1 / 0xdc×1 / 0xa4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8664 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xd8668 subs r3, r1, #0
 *   @0xd866c ldr r7, [pc, #0x124]
 *   @0xd8670 mov r6, r0
 *   @0xd8674 add r7, pc, r7
 *   @0xd8678 beq 0xd8774 <_ZN2VM17WriteRenderStatesEP15Buffer_Standardb+0x110>
 *   @0xd867c ldr r12, [r0]
 *   @0xd8680 add r9, r0, #44
 *   @0xd8684 mov r3, #0
 *   @0xd8688 mov r1, #5
 *   @0xd868c mov r8, r3
 *   @0xd8690 mov r2, r9
 *   @0xd8694 str r8, [r0, #0x2c]
 *   @0xd8698 movt r3, #0x4043
 *   @0xd869c str r8, [r0, #0x38]
 *   @0xd86a0 str r3, [r0, #0x30]
 *   @0xd86a4 ldr r3, [r12, #0x8]
 *   @0xd86a8 blx r3
 *   @0xd86ac ldr r3, [pc, #0xe8]
 *   @0xd86b0 mov r1, r6
 *   @0xd86b4 ldr r0, [r7, r3]
 *   @0xd86b8 bl 0x1682cc <_ZN18RenderStateManager19WriteStatesToBufferEP15Buffer_Standard>
 *   @0xd86bc ldr r12, [pc, #0xdc]
 *   @0xd86c0 ldr r3, [r6]
 *   @0xd86c4 mov r2, r9
 *   @0xd86c8 mov r0, r6
 *   @0xd86cc mov r1, #5
 *   @0xd86d0 ldr r12, [r7, r12]
 *   @0xd86d4 str r8, [r6, #0x38]
 *   @0xd86d8 ldr r4, [r12]
 *   @0xd86dc vmov s15, r4
 *   @0xd86e0 vcvt.f64.u32 d7, s15
 *   @0xd86e4 vmov r4, r5, d7
 *   @0xd86e8 vstr s14, [r6, #44]
 *   @0xd86ec str r5, [r6, #0x30]
 *   @0xd86f0 ldr r3, [r3, #0x8]
 *   @0xd86f4 blx r3
 *   @0xd86f8 ldr r12, [pc, #0xa4]
 *   @0xd86fc ldr r3, [r6]
 *   @0xd8700 mov r2, r9
 *   @0xd8704 mov r0, r6
 *   @0xd8708 mov r1, #5
 *   @0xd870c ldr r12, [r7, r12]
 *   @0xd8710 str r8, [r6, #0x38]
 *   @0xd8714 ldr r4, [r12]
 *   @0xd8718 vmov s15, r4
 *   @0xd871c vcvt.f64.u32 d7, s15
 *   @0xd8720 vmov r4, r5, d7
 *   @0xd8724 vstr s14, [r6, #44]
 *   @0xd8728 str r5, [r6, #0x30]
 *   @0xd872c ldr r3, [r3, #0x8]
 *   @0xd8730 blx r3
 *   @0xd8734 ldr r12, [pc, #0x6c]
 *   @0xd8738 ldr r3, [r6]
 *   @0xd873c mov r2, r9
 *   @0xd8740 mov r0, r6
 *   @0xd8744 mov r1, #5
 *   @0xd8748 ldr r12, [r7, r12]
 *   @0xd874c str r8, [r6, #0x38]
 *   @0xd8750 ldrb r4, [r12]
 *   @0xd8754 vmov s15, r4
 *   @0xd8758 vcvt.f64.u32 d7, s15
 *   @0xd875c vmov r4, r5, d7
 *   @0xd8760 vstr s14, [r6, #44]
 *   @0xd8764 str r5, [r6, #0x30]
 *   @0xd8768 ldr r3, [r3, #0x8]
 *   @0xd876c blx r3
 *   @0xd8770 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd8774 mov r2, r0
 *   @0xd8778 str r3, [r0, #0x2c]
 *   @0xd877c ldr r12, [r2], #44
 *   @0xd8780 mov r1, #5
 *   @0xd8784 str r3, [r0, #0x30]
 *   @0xd8788 str r3, [r0, #0x38]
 *   @0xd878c ldr r3, [r12, #0x8]
 *   @0xd8790 blx r3
 *   @0xd8794 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd8798 ldrsbteq r9, [r1], -r12
 *   @0xd879c .word 0xffffc0a8
 *   @0xd87a0 .word 0xffffc0ac
 *   @0xd87a4 .word 0xffffc0b0
 *   @0xd87a8 .word 0xffffc0b4
 *
 * ══ §10/94 Font_ReplaceSprite(int, int, int, bool, int)  0xfa9c4  size 328  82 条（0xfa9c4..0xfab0c）
 * @func 0xfa9c4 0xfab0c  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_ReplaceSprite(int, int, int, bool, int)+0x44 / Font_ReplaceSprite(int, int, int, bool, int)+0x60 / Sprite_Data(int) / Font_ReplaceSprite(int, int, int, bool, int)+0x130 / utf8_add_char / operator new(unsigned int) / CFontGM::CFontGM(int, char const*, bool, int) / 0xb65d4
 * 字段偏移 top8: 0x4×4 / 0x-34×3 / 0x-30×2 / 0x-28×2 / 0x18×2 / 0x-2c×2 / 0x12c×1 / 0x108×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa9c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfa9c8 add r11, sp, #32
 *   @0xfa9cc ldr r4, [pc, #0x12c]
 *   @0xfa9d0 sub sp, sp, #28
 *   @0xfa9d4 str r3, [r11, #-0x30]
 *   @0xfa9d8 ldr r4, [pc, r4]
 *   @0xfa9dc subs r7, r0, #0
 *   @0xfa9e0 mov r8, r1
 *   @0xfa9e4 mov r6, r2
 *   @0xfa9e8 ldr r3, [r4]
 *   @0xfa9ec str r3, [r11, #-0x28]
 *   @0xfa9f0 blt 0xfaa08 <_Z18Font_ReplaceSpriteiiibi+0x44>
 *   @0xfa9f4 ldr r3, [pc, #0x108]
 *   @0xfa9f8 ldr r3, [pc, r3]
 *   @0xfa9fc ldr r3, [r3]
 *   @0xfaa00 cmp r7, r3
 *   @0xfaa04 blt 0xfaa24 <_Z18Font_ReplaceSpriteiiibi+0x60>
 *   @0xfaa08 mov r0, #0
 *   @0xfaa0c ldr r2, [r11, #-0x28]
 *   @0xfaa10 ldr r3, [r4]
 *   @0xfaa14 cmp r2, r3
 *   @0xfaa18 bne 0xfaafc <_Z18Font_ReplaceSpriteiiibi+0x138>
 *   @0xfaa1c sub sp, r11, #32
 *   @0xfaa20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfaa24 mov r0, r1
 *   @0xfaa28 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xfaa2c ldr r3, [r0, #0x18]
 *   @0xfaa30 mov r9, r0
 *   @0xfaa34 cmp r3, #0
 *   @0xfaa38 lsl r3, r3, #2
 *   @0xfaa3c add r3, r3, #18
 *   @0xfaa40 bic r3, r3, #7
 *   @0xfaa44 sub sp, sp, r3
 *   @0xfaa48 add r3, sp, #8
 *   @0xfaa4c str r3, [r11, #-0x34]
 *   @0xfaa50 str r3, [r11, #-0x2c]
 *   @0xfaa54 ble 0xfaaf4 <_Z18Font_ReplaceSpriteiiibi+0x130>
 *   @0xfaa58 uxth r6, r6
 *   @0xfaa5c sub r5, r11, #44
 *   @0xfaa60 mov r10, #0
 *   @0xfaa64 add r1, r6, r10
 *   @0xfaa68 mov r0, r5
 *   @0xfaa6c add r10, r10, #1
 *   @0xfaa70 uxth r1, r1
 *   @0xfaa74 bl 0x10fe28 <utf8_add_char>
 *   @0xfaa78 ldr r2, [r9, #0x18]
 *   @0xfaa7c cmp r2, r10
 *   @0xfaa80 bgt 0xfaa64 <_Z18Font_ReplaceSpriteiiibi+0xa0>
 *   @0xfaa84 ldr r2, [r11, #-0x2c]
 *   @0xfaa88 mov r3, #0
 *   @0xfaa8c mov r0, #144
 *   @0xfaa90 strb r3, [r2]
 *   @0xfaa94 lsl r5, r7, #2
 *   @0xfaa98 bl 0x27c524 <_Znwj>
 *   @0xfaa9c ldr r3, [r11, #0x4]
 *   @0xfaaa0 ldr r6, [pc, #0x60]
 *   @0xfaaa4 mov r1, r8
 *   @0xfaaa8 ldr r2, [r11, #-0x34]
 *   @0xfaaac str r3, [sp]
 *   @0xfaab0 ldr r3, [r11, #-0x30]
 *   @0xfaab4 mov r9, r0
 *   @0xfaab8 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi>
 *   @0xfaabc ldr r6, [pc, r6]
 *   @0xfaac0 ldr r3, [r6, #0x4]
 *   @0xfaac4 add r2, r3, r5
 *   @0xfaac8 ldr r0, [r3, r7, lsl #2]
 *   @0xfaacc cmp r0, #0
 *   @0xfaad0 beq 0xfaae8 <_Z18Font_ReplaceSpriteiiibi+0x124>
 *   @0xfaad4 ldr r3, [r0]
 *   @0xfaad8 ldr r3, [r3, #0x4]
 *   @0xfaadc blx r3
 *   @0xfaae0 ldr r2, [r6, #0x4]
 *   @0xfaae4 add r2, r2, r5
 *   @0xfaae8 str r9, [r2]
 *   @0xfaaec mov r0, #1
 *   @0xfaaf0 b 0xfaa0c <_Z18Font_ReplaceSpriteiiibi+0x48>
 *   @0xfaaf4 ldr r2, [r11, #-0x34]
 *   @0xfaaf8 b 0xfaa88 <_Z18Font_ReplaceSpriteiiibi+0xc4>
 *   @0xfaafc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfab00 eoreq r2, pc, r8, ror pc
 *   @0xfab04 eoreq r3, pc, r8, ror #8
 *   @0xfab08 eoreq r3, pc, r0, lsr #7
 *
 * ══ §11/94 F_SkeletonSetAttachment(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cffc  size 328  82 条（0x11cffc..0x11d144）
 * @func 0x11cffc 0x11d144  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetAttachment(char const*, char const*, bool)×3 / YYGetString(RValue const*, int)×2 / CInstance::SkeletonAnimation() / YYGetInt32(RValue const*, int) / Sprite_Exists(int) / Sprite_Data(int) / CSkeletonInstance::FindAttachment(char const*, char const*) / CSkeletonInstance::CreateAttachment(char const*, CSprite*, int, float, float, float, float, float)
 * 字段偏移 top8: 0x5c×3 / 0xc×2 / 0x4×1 / 0x30×1 / 0x1c×1 / 0x8×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cffc push {r4, r5, r6, r7, r8, lr}
 *   @0x11d000 mov r4, r0
 *   @0x11d004 sub sp, sp, #24
 *   @0x11d008 mov r5, #0
 *   @0x11d00c mov r0, r1
 *   @0x11d010 mov r3, #0
 *   @0x11d014 str r5, [r4, #0xc]
 *   @0x11d018 movt r3, #0xbff0
 *   @0x11d01c str r5, [r4]
 *   @0x11d020 str r3, [r4, #0x4]
 *   @0x11d024 ldr r6, [sp, #0x30]
 *   @0x11d028 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d02c mov r1, r5
 *   @0x11d030 mov r7, r0
 *   @0x11d034 mov r0, r6
 *   @0x11d038 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d03c cmp r7, r5
 *   @0x11d040 mov r8, r0
 *   @0x11d044 beq 0x11d0b8 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x11d048 ldr r1, [r6, #0x1c]
 *   @0x11d04c mov r0, r6
 *   @0x11d050 cmp r1, #1
 *   @0x11d054 beq 0x11d0e8 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x11d058 mov r1, #1
 *   @0x11d05c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d060 mov r5, r0
 *   @0x11d064 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x11d068 subs r2, r0, #0
 *   @0x11d06c beq 0x11d0c0 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x11d070 mov r0, r5
 *   @0x11d074 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11d078 mov r1, r8
 *   @0x11d07c mov r5, r0
 *   @0x11d080 mov r0, r7
 *   @0x11d084 ldr r2, [r5, #0x5c]
 *   @0x11d088 bl 0xc0810 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_>
 *   @0x11d08c subs r3, r0, #0
 *   @0x11d090 beq 0x11d104 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x11d094 ldr r2, [r5, #0x5c]
 *   @0x11d098 mov r3, #0
 *   @0x11d09c mov r0, r7
 *   @0x11d0a0 mov r1, r8
 *   @0x11d0a4 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b>
 *   @0x11d0a8 mov r3, #0
 *   @0x11d0ac mov r2, r3
 *   @0x11d0b0 movt r3, #0x3ff0
 *   @0x11d0b4 stm r4, {r2, r3}
 *   @0x11d0b8 add sp, sp, #24
 *   @0x11d0bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x11d0c0 mov r0, r7
 *   @0x11d0c4 mov r1, r8
 *   @0x11d0c8 mov r3, r2
 *   @0x11d0cc bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b>
 *   @0x11d0d0 mov r3, #0
 *   @0x11d0d4 mov r2, r3
 *   @0x11d0d8 movt r3, #0x3ff0
 *   @0x11d0dc stm r4, {r2, r3}
 *   @0x11d0e0 add sp, sp, #24
 *   @0x11d0e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11d0e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d0ec mov r1, r8
 *   @0x11d0f0 mov r3, r5
 *   @0x11d0f4 mov r2, r0
 *   @0x11d0f8 mov r0, r7
 *   @0x11d0fc bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b>
 *   @0x11d100 b 0x11d0d0 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x11d104 vldr s14, [r5, #36]
 *   @0x11d108 vcvt.f32.s32 s15, s14
 *   @0x11d10c ldr r1, [r5, #0x5c]
 *   @0x11d110 mov r12, #1065353216
 *   @0x11d114 mov lr, #0
 *   @0x11d118 mov r0, r7
 *   @0x11d11c mov r2, r5
 *   @0x11d120 vstr s15, [sp]
 *   @0x11d124 vldr s15, [r5, #40]
 *   @0x11d128 vcvt.f32.s32 s15, s15
 *   @0x11d12c str r12, [sp, #0x8]
 *   @0x11d130 str r12, [sp, #0xc]
 *   @0x11d134 str lr, [sp, #0x10]
 *   @0x11d138 vstr s15, [sp, #4]
 *   @0x11d13c bl 0xbfb44 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff>
 *   @0x11d140 b 0x11d094 <_Z23F_SkeletonSetAttachmentR6RValueP9CInstanceS2_iPS_+0x98>
 *
 * ══ §12/94 CreateArrayValOrString(RValue*, int, ...)  0x121944  size 328  82 条（0x121944..0x121a8c）
 * @func 0x121944 0x121a8c  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / ARRAY_RefAlloc(void*) / CreateArrayValOrString(RValue*, int, ...)+0x130 / YYSetString(RValue*, char const*)
 * 字段偏移 top8: 0x4×18 / 0xc×4 / 0x2c×1 / 0x118×1 / 0x10×1 / 0xf4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121944 push {r1, r2, r3}
 *   @0x121948 mov r3, #2
 *   @0x12194c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x121950 sub sp, sp, #8
 *   @0x121954 str r3, [r0, #0xc]
 *   @0x121958 mov r10, r0
 *   @0x12195c ldr r7, [sp, #0x2c]
 *   @0x121960 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x121964 ldr r1, [pc, #0x118]
 *   @0x121968 mov r9, #1
 *   @0x12196c mov r3, r9
 *   @0x121970 mov r2, #70
 *   @0x121974 add r1, pc, r1
 *   @0x121978 mov r4, r0
 *   @0x12197c mov r0, #8
 *   @0x121980 str r4, [r10]
 *   @0x121984 str r9, [r4, #0x10]
 *   @0x121988 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x12198c ldr r1, [pc, #0xf4]
 *   @0x121990 mov r3, r9
 *   @0x121994 movw r2, #0x724
 *   @0x121998 add r1, pc, r1
 *   @0x12199c str r0, [r4, #0x4]
 *   @0x1219a0 lsl r0, r7, #4
 *   @0x1219a4 ldr r12, [r10]
 *   @0x1219a8 ldr r4, [r12, #0x4]
 *   @0x1219ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1219b0 cmp r7, #0
 *   @0x1219b4 add r3, sp, #48
 *   @0x1219b8 str r0, [r4, #0x4]
 *   @0x1219bc ldr r2, [r10]
 *   @0x1219c0 ldr r2, [r2, #0x4]
 *   @0x1219c4 str r7, [r2]
 *   @0x1219c8 str r3, [sp, #0x4]
 *   @0x1219cc ble 0x121a74 <_Z22CreateArrayValOrStringP6RValueiz+0x130>
 *   @0x1219d0 mov r4, #0
 *   @0x1219d4 mov r8, r4
 *   @0x1219d8 b 0x121a00 <_Z22CreateArrayValOrStringP6RValueiz+0xbc>
 *   @0x1219dc ldr r2, [r10]
 *   @0x1219e0 add r4, r4, #1
 *   @0x1219e4 ldr r2, [r2, #0x4]
 *   @0x1219e8 ldr r0, [r2, #0x4]
 *   @0x1219ec add r0, r0, r3
 *   @0x1219f0 str r9, [r0, #0xc]
 *   @0x1219f4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1219f8 cmp r4, r7
 *   @0x1219fc beq 0x121a74 <_Z22CreateArrayValOrStringP6RValueiz+0x130>
 *   @0x121a00 ldr r1, [r10]
 *   @0x121a04 lsl r3, r4, #4
 *   @0x121a08 ldr r2, [sp, #0x4]
 *   @0x121a0c ldr r1, [r1, #0x4]
 *   @0x121a10 add r2, r2, #7
 *   @0x121a14 bic r2, r2, #7
 *   @0x121a18 add r11, r2, #12
 *   @0x121a1c ldr r12, [r2, #0x8]
 *   @0x121a20 ldr r6, [r1, #0x4]
 *   @0x121a24 ldr r0, [r2]
 *   @0x121a28 cmp r12, #0
 *   @0x121a2c ldr r2, [r2, #0x4]
 *   @0x121a30 add r5, r6, r3
 *   @0x121a34 str r11, [sp, #0x4]
 *   @0x121a38 mov r1, r12
 *   @0x121a3c str r8, [r5, #0xc]
 *   @0x121a40 str r0, [r6, r4, lsl #4]
 *   @0x121a44 str r2, [r5, #0x4]
 *   @0x121a48 bne 0x1219dc <_Z22CreateArrayValOrStringP6RValueiz+0x98>
 *   @0x121a4c ldr r1, [r10]
 *   @0x121a50 ldr r1, [r1, #0x4]
 *   @0x121a54 ldr r1, [r1, #0x4]
 *   @0x121a58 add r3, r1, r3
 *   @0x121a5c str r12, [r3, #0xc]
 *   @0x121a60 str r0, [r1, r4, lsl #4]
 *   @0x121a64 add r4, r4, #1
 *   @0x121a68 cmp r4, r7
 *   @0x121a6c str r2, [r3, #0x4]
 *   @0x121a70 bne 0x121a00 <_Z22CreateArrayValOrStringP6RValueiz+0xbc>
 *   @0x121a74 add sp, sp, #8
 *   @0x121a78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x121a7c add sp, sp, #12
 *   @0x121a80 bx lr
 *   @0x121a84 .word 0x0020f6bc
 *   @0x121a88 .word 0x002185b8
 *
 * ══ §13/94 F_ActionDrawLifeImages(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f5a8  size 328  82 条（0x13f5a8..0x13f6f0）
 * @func 0x13f5a8 0x13f6f0  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / F_ActionDrawLifeImages(RValue&, CInstance*, CInstance*, int, RValue*)+0x50×2 / CSprite::Draw(int, float, float, float, float, float, unsigned int, float)×2 / YYGetInt32(RValue const*, int) / Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x10×2 / 0x50×1 / 0xd8×1 / 0x1c×1 / 0xbc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f5a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13f5ac vpush {d8, d9}
 *   @0x13f5b0 sub sp, sp, #28
 *   @0x13f5b4 mov r9, r1
 *   @0x13f5b8 mov r1, #0
 *   @0x13f5bc ldr r4, [sp, #0x50]
 *   @0x13f5c0 mov r0, r4
 *   @0x13f5c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f5c8 mov r1, #1
 *   @0x13f5cc vmov s17, r0
 *   @0x13f5d0 mov r0, r4
 *   @0x13f5d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f5d8 mov r1, #2
 *   @0x13f5dc vmov s16, r0
 *   @0x13f5e0 mov r0, r4
 *   @0x13f5e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13f5e8 mov r4, r0
 *   @0x13f5ec bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x13f5f0 cmp r0, #0
 *   @0x13f5f4 bne 0x13f604 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x13f5f8 add sp, sp, #28
 *   @0x13f5fc vpop {d8, d9}
 *   @0x13f600 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13f604 mov r0, r4
 *   @0x13f608 ldr r11, [pc, #0xd8]
 *   @0x13f60c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x13f610 ldr r11, [pc, r11]
 *   @0x13f614 ldr r3, [r11]
 *   @0x13f618 cmp r3, #0
 *   @0x13f61c mov r7, r0
 *   @0x13f620 ldr r10, [r0, #0x1c]
 *   @0x13f624 ble 0x13f5f8 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x13f628 ldr r8, [pc, #0xbc]
 *   @0x13f62c mov r4, #0
 *   @0x13f630 mov r6, #1065353216
 *   @0x13f634 mov r5, r4
 *   @0x13f638 ldr r8, [pc, r8]
 *   @0x13f63c vldr s18, [pc, #160]
 *   @0x13f640 b 0x13f698 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x13f644 vldr s14, [r9, #180]
 *   @0x13f648 mvn r3, #-16777216
 *   @0x13f64c str r6, [sp]
 *   @0x13f650 vstr s18, [sp, #8]
 *   @0x13f654 str r3, [sp, #0xc]
 *   @0x13f658 vadd.f32 s14, s17, s14
 *   @0x13f65c str r6, [sp, #0x4]
 *   @0x13f660 vmov s13, r4
 *   @0x13f664 str r6, [sp, #0x10]
 *   @0x13f668 vldr s15, [r9, #184]
 *   @0x13f66c vadd.f32 s15, s16, s15
 *   @0x13f670 vmov r3, s15
 *   @0x13f674 vcvt.f32.s32 s15, s13
 *   @0x13f678 vadd.f32 s15, s14, s15
 *   @0x13f67c vmov r2, s15
 *   @0x13f680 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x13f684 ldr r3, [r11]
 *   @0x13f688 add r5, r5, #1
 *   @0x13f68c add r4, r4, r10
 *   @0x13f690 cmp r3, r5
 *   @0x13f694 ble 0x13f5f8 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x13f698 ldrb r2, [r8]
 *   @0x13f69c mov r1, #0
 *   @0x13f6a0 mov r0, r7
 *   @0x13f6a4 vmov r3, s16
 *   @0x13f6a8 cmp r2, r1
 *   @0x13f6ac bne 0x13f644 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13f6b0 vmov s13, r4
 *   @0x13f6b4 mvn r1, #-16777216
 *   @0x13f6b8 str r6, [sp]
 *   @0x13f6bc vstr s18, [sp, #8]
 *   @0x13f6c0 vcvt.f32.s32 s15, s13
 *   @0x13f6c4 str r1, [sp, #0xc]
 *   @0x13f6c8 str r6, [sp, #0x4]
 *   @0x13f6cc mov r1, r2
 *   @0x13f6d0 str r6, [sp, #0x10]
 *   @0x13f6d4 vadd.f32 s15, s15, s17
 *   @0x13f6d8 vmov r2, s15
 *   @0x13f6dc bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x13f6e0 b 0x13f684 <_Z22F_ActionDrawLifeImagesR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x13f6e4 andeq r0, r0, r0
 *   @0x13f6e8 eoreq pc, r10, r0, asr #27
 *   @0x13f6ec eoreq lr, r10, r4, lsl #10
 *
 * ══ §14/94 F_PhysicsDrawParticlesExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x14dd18  size 328  82 条（0x14dd18..0x14de60）
 * @func 0x14dd18 0x14de60  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×4 / Sprite_Data(int) / YYGetUint32(RValue const*, int) / CPhysicsWorld::DrawParticlesExt(unsigned int, int, CSprite*, int, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xb4×2 / 0x1c×2 / 0x12c×1 / 0x50×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14dd18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14dd1c vpush {d8}
 *   @0x14dd20 sub sp, sp, #36
 *   @0x14dd24 ldr r5, [pc, #0x12c]
 *   @0x14dd28 ldr r4, [sp, #0x50]
 *   @0x14dd2c ldr r5, [pc, r5]
 *   @0x14dd30 ldr r3, [r5]
 *   @0x14dd34 cmp r3, #0
 *   @0x14dd38 beq 0x14de34 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x14dd3c ldr r3, [r3, #0xb4]
 *   @0x14dd40 cmp r3, #0
 *   @0x14dd44 beq 0x14de34 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x14dd48 mov r1, #2
 *   @0x14dd4c mov r0, r4
 *   @0x14dd50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dd54 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x14dd58 subs r6, r0, #0
 *   @0x14dd5c beq 0x14de28 <_Z25F_PhysicsDrawParticlesExtR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x14dd60 ldr r3, [r5]
 *   @0x14dd64 mov r1, #0
 *   @0x14dd68 mov r0, r4
 *   @0x14dd6c ldr r5, [r3, #0xb4]
 *   @0x14dd70 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14dd74 mov r1, #1
 *   @0x14dd78 mov r8, r0
 *   @0x14dd7c mov r0, r4
 *   @0x14dd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dd84 mov r1, #3
 *   @0x14dd88 mov r7, r0
 *   @0x14dd8c mov r0, r4
 *   @0x14dd90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dd94 mov r1, #4
 *   @0x14dd98 mov r3, r0
 *   @0x14dd9c mov r0, r4
 *   @0x14dda0 str r3, [sp, #0x1c]
 *   @0x14dda4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14dda8 mov r1, #5
 *   @0x14ddac mov r11, r0
 *   @0x14ddb0 mov r0, r4
 *   @0x14ddb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ddb8 mov r1, #6
 *   @0x14ddbc mov r10, r0
 *   @0x14ddc0 mov r0, r4
 *   @0x14ddc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ddc8 mov r1, #7
 *   @0x14ddcc vmov s16, r0
 *   @0x14ddd0 mov r0, r4
 *   @0x14ddd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ddd8 mov r1, #8
 *   @0x14dddc mov r9, r0
 *   @0x14dde0 mov r0, r4
 *   @0x14dde4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14dde8 vldr s15, [pc, #96]
 *   @0x14ddec vmul.f32 s16, s16, s15
 *   @0x14ddf0 vldr s15, [pc, #92]
 *   @0x14ddf4 ldr r3, [sp, #0x1c]
 *   @0x14ddf8 mov r1, r8
 *   @0x14ddfc str r11, [sp, #0x4]
 *   @0x14de00 mov r2, r7
 *   @0x14de04 str r10, [sp, #0x8]
 *   @0x14de08 str r3, [sp]
 *   @0x14de0c mov r3, r6
 *   @0x14de10 str r9, [sp, #0x10]
 *   @0x14de14 vdiv.f32 s16, s16, s15
 *   @0x14de18 str r0, [sp, #0x14]
 *   @0x14de1c mov r0, r5
 *   @0x14de20 vstr s16, [sp, #12]
 *   @0x14de24 bl 0x23acf4 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf>
 *   @0x14de28 add sp, sp, #36
 *   @0x14de2c vpop {d8}
 *   @0x14de30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14de34 ldr r0, [pc, #0x20]
 *   @0x14de38 mov r1, #0
 *   @0x14de3c add r0, pc, r0
 *   @0x14de40 add sp, sp, #36
 *   @0x14de44 vpop {d8}
 *   @0x14de48 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14de4c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14de50 ldrdmi r0, r1, [r9], #-251
 *   @0x14de54 teqmi r4, #0
 *   @0x14de58 .word 0x0029fbfc
 *   @0x14de5c andseq r6, pc, r4, ror r6
 *
 * ══ §15/94 F_LayerGetAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x1ba98c  size 328  82 条（0x1ba98c..0x1baad4）
 * @func 0x1ba98c 0x1baad4  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CLayerManager::GetTargetRoomObj() / ARRAY_RefAlloc(void*)
 * 字段偏移 top8: 0x4×8 / 0xc×3 / 0xd4×2 / 0x19×2 / 0x68×2 / 0xcc×1 / 0x10×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba98c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1ba990 subs r4, r3, #0
 *   @0x1ba994 mov r2, #0
 *   @0x1ba998 mov r5, r0
 *   @0x1ba99c mov r1, r2
 *   @0x1ba9a0 movt r2, #0xbff0
 *   @0x1ba9a4 str r1, [r0, #0xc]
 *   @0x1ba9a8 stm r0, {r1, r2}
 *   @0x1ba9ac bne 0x1baab0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1ba9b0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1ba9b4 subs r8, r0, #0
 *   @0x1ba9b8 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1ba9bc ldr r2, [r8, #0xd4]
 *   @0x1ba9c0 cmp r2, #0
 *   @0x1ba9c4 beq 0x1baac0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1ba9c8 ldrb r1, [r2, #0x19]
 *   @0x1ba9cc ldr r2, [r2, #0x68]
 *   @0x1ba9d0 cmp r1, #0
 *   @0x1ba9d4 addeq r4, r4, #1
 *   @0x1ba9d8 cmp r2, #0
 *   @0x1ba9dc bne 0x1ba9c8 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1ba9e0 lsl r10, r4, #4
 *   @0x1ba9e4 mov r3, #2
 *   @0x1ba9e8 mov r0, r5
 *   @0x1ba9ec str r3, [r5, #0xc]
 *   @0x1ba9f0 mov r7, #1
 *   @0x1ba9f4 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x1ba9f8 ldr r9, [pc, #0xcc]
 *   @0x1ba9fc mov r3, r7
 *   @0x1baa00 movw r2, #0x1483
 *   @0x1baa04 add r9, pc, r9
 *   @0x1baa08 mov r1, r9
 *   @0x1baa0c mov r6, r0
 *   @0x1baa10 str r0, [r5]
 *   @0x1baa14 str r7, [r0, #0x10]
 *   @0x1baa18 mov r0, #8
 *   @0x1baa1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1baa20 mov r1, r9
 *   @0x1baa24 mov r3, r7
 *   @0x1baa28 movw r2, #0x1484
 *   @0x1baa2c str r0, [r6, #0x4]
 *   @0x1baa30 mov r0, r10
 *   @0x1baa34 ldr r12, [r5]
 *   @0x1baa38 ldr r6, [r12, #0x4]
 *   @0x1baa3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1baa40 ldr r1, [r8, #0xd4]
 *   @0x1baa44 cmp r1, #0
 *   @0x1baa48 str r0, [r6, #0x4]
 *   @0x1baa4c ldr r3, [r5]
 *   @0x1baa50 ldr r3, [r3, #0x4]
 *   @0x1baa54 str r4, [r3]
 *   @0x1baa58 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1baa5c mov r12, #0
 *   @0x1baa60 ldrb r4, [r1, #0x19]
 *   @0x1baa64 lsl r0, r12, #4
 *   @0x1baa68 cmp r4, #0
 *   @0x1baa6c bne 0x1baaa0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x1baa70 vldr s15, [r1]
 *   @0x1baa74 vcvt.f64.s32 d7, s15
 *   @0x1baa78 ldr r3, [r5]
 *   @0x1baa7c ldr r7, [r3, #0x4]
 *   @0x1baa80 vmov r2, r3, d7
 *   @0x1baa84 ldr r7, [r7, #0x4]
 *   @0x1baa88 mov r6, r7
 *   @0x1baa8c add r7, r7, r0
 *   @0x1baa90 str r4, [r7, #0xc]
 *   @0x1baa94 str r2, [r6, r12, lsl #4]
 *   @0x1baa98 add r12, r12, #1
 *   @0x1baa9c str r3, [r7, #0x4]
 *   @0x1baaa0 ldr r1, [r1, #0x68]
 *   @0x1baaa4 cmp r1, #0
 *   @0x1baaa8 bne 0x1baa60 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1baaac pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1baab0 ldr r0, [pc, #0x18]
 *   @0x1baab4 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1baab8 add r0, pc, r0
 *   @0x1baabc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1baac0 mov r10, r2
 *   @0x1baac4 mov r4, r2
 *   @0x1baac8 b 0x1ba9e4 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1baacc andseq r2, r9, r8, ror #26
 *   @0x1baad0 andseq r2, r9, r8, ror #25
 *
 * ══ §16/94 CSprite::SampleGradient(SWF_GradientFillStyleData*, int)  0x1e7b44  size 328  82 条（0x1e7b44..0x1e7c8c）
 * @func 0x1e7b44 0x1e7c8c  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::SampleGradient(SWF_GradientFillStyleData*, int)+0x12c / CSprite::SampleGradient(SWF_GradientFillStyleData*, int)+0x7c / CSprite::SampleGradient(SWF_GradientFillStyleData*, int)+0x8c / CSprite::SampleGradient(SWF_GradientFillStyleData*, int)+0x84 / __divsi3
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x4c×1 / 0x50×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7b44 cmp r1, #0
 *   @0x1e7b48 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e7b4c beq 0x1e7c78 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x134>
 *   @0x1e7b50 ldr r12, [r1, #0x4c]
 *   @0x1e7b54 cmp r12, #0
 *   @0x1e7b58 ble 0x1e7c70 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x12c>
 *   @0x1e7b5c ldr r5, [r1, #0x50]
 *   @0x1e7b60 usat r2, #0x8, r2
 *   @0x1e7b64 ldr r3, [r5]
 *   @0x1e7b68 cmp r2, r3
 *   @0x1e7b6c blt 0x1e7bc0 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x7c>
 *   @0x1e7b70 cmp r12, #1
 *   @0x1e7b74 beq 0x1e7bb4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x70>
 *   @0x1e7b78 ldr r1, [r5, #0x8]
 *   @0x1e7b7c cmp r2, r1
 *   @0x1e7b80 addle r4, r5, #8
 *   @0x1e7b84 movle r0, #0
 *   @0x1e7b88 ble 0x1e7bd0 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x8c>
 *   @0x1e7b8c add r3, r5, #16
 *   @0x1e7b90 mov r0, #1
 *   @0x1e7b94 b 0x1e7ba4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x60>
 *   @0x1e7b98 ldr r1, [r3], #8
 *   @0x1e7b9c cmp r2, r1
 *   @0x1e7ba0 ble 0x1e7bc8 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x84>
 *   @0x1e7ba4 add r0, r0, #1
 *   @0x1e7ba8 mov r4, r3
 *   @0x1e7bac cmp r0, r12
 *   @0x1e7bb0 bne 0x1e7b98 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x54>
 *   @0x1e7bb4 add r12, r5, r12, lsl #3
 *   @0x1e7bb8 ldr r0, [r12, #-0x4]
 *   @0x1e7bbc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e7bc0 ldr r0, [r5, #0x4]
 *   @0x1e7bc4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e7bc8 sub r0, r0, #-536870911
 *   @0x1e7bcc lsl r0, r0, #3
 *   @0x1e7bd0 ldr r3, [r5, r0]
 *   @0x1e7bd4 add r5, r5, r0
 *   @0x1e7bd8 cmp r1, r3
 *   @0x1e7bdc beq 0x1e7c80 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0x13c>
 *   @0x1e7be0 rsb r0, r3, r2
 *   @0x1e7be4 rsb r1, r3, r1
 *   @0x1e7be8 lsl r0, r0, #8
 *   @0x1e7bec bl 0x318d10 <__divsi3>
 *   @0x1e7bf0 rsb r1, r0, #256
 *   @0x1e7bf4 ldr r2, [r4, #0x4]
 *   @0x1e7bf8 ldr r3, [r5, #0x4]
 *   @0x1e7bfc ubfx r5, r2, #0x10, #0x8
 *   @0x1e7c00 ubfx r4, r2, #0x8, #0x8
 *   @0x1e7c04 ubfx r8, r3, #0x10, #0x8
 *   @0x1e7c08 ubfx r6, r3, #0x8, #0x8
 *   @0x1e7c0c mul r5, r5, r0
 *   @0x1e7c10 uxtb r9, r2
 *   @0x1e7c14 mul r8, r8, r1
 *   @0x1e7c18 lsr r12, r2, #24
 *   @0x1e7c1c mul r2, r4, r0
 *   @0x1e7c20 lsr r7, r3, #24
 *   @0x1e7c24 mul r6, r6, r1
 *   @0x1e7c28 uxtb r4, r3
 *   @0x1e7c2c mul r3, r9, r0
 *   @0x1e7c30 lsr r5, r5, #8
 *   @0x1e7c34 mul r0, r12, r0
 *   @0x1e7c38 add r5, r5, r8, lsr #8
 *   @0x1e7c3c mul r4, r4, r1
 *   @0x1e7c40 lsr r2, r2, #8
 *   @0x1e7c44 mul r1, r7, r1
 *   @0x1e7c48 add r2, r2, r6, lsr #8
 *   @0x1e7c4c lsl r5, r5, #16
 *   @0x1e7c50 lsr r12, r0, #8
 *   @0x1e7c54 lsr r3, r3, #8
 *   @0x1e7c58 orr r2, r5, r2, lsl #8
 *   @0x1e7c5c add r3, r3, r4, lsr #8
 *   @0x1e7c60 orr r2, r2, r3
 *   @0x1e7c64 add r0, r12, r1, lsr #8
 *   @0x1e7c68 orr r0, r2, r0, lsl #24
 *   @0x1e7c6c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e7c70 mov r0, #0
 *   @0x1e7c74 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e7c78 mov r0, r1
 *   @0x1e7c7c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e7c80 mov r1, #256
 *   @0x1e7c84 mov r0, #0
 *   @0x1e7c88 b 0x1e7bf4 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai+0xb0>
 *
 * ══ §17/94 ov_time_seek  0x232a44  size 328  82 条（0x232a44..0x232b8c）
 * @func 0x232a44 0x232ba0  size 348  87 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_time_seek+0x11c×2 / ov_time_seek+0x128 / ov_time_seek+0x114 / ov_time_total / anon_319414
 * 字段偏移 top8: 0x34×3 / 0x58×1 / 0x4×1 / 0x44×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232a44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x232a48 sub sp, sp, #20
 *   @0x232a4c mov r9, r0
 *   @0x232a50 strd r2, r3, [sp, #8]
 *   @0x232a54 ldr r3, [r0, #0x58]
 *   @0x232a58 cmp r3, #1
 *   @0x232a5c ble 0x232b60 <ov_time_seek+0x11c>
 *   @0x232a60 ldr r3, [r0, #0x4]
 *   @0x232a64 cmp r3, #0
 *   @0x232a68 beq 0x232b84 <ov_time_seek+0x140>
 *   @0x232a6c ldrd r2, r3, [sp, #8]
 *   @0x232a70 cmp r2, #0
 *   @0x232a74 sbcs r3, r3, #0
 *   @0x232a78 blt 0x232b60 <ov_time_seek+0x11c>
 *   @0x232a7c ldr r1, [r0, #0x34]
 *   @0x232a80 cmp r1, #0
 *   @0x232a84 ble 0x232b6c <ov_time_seek+0x128>
 *   @0x232a88 mov r4, #0
 *   @0x232a8c mov r5, #0
 *   @0x232a90 mov r6, #8
 *   @0x232a94 mov r10, r4
 *   @0x232a98 mov r11, r5
 *   @0x232a9c mov r8, #0
 *   @0x232aa0 b 0x232ad0 <ov_time_seek+0x8c>
 *   @0x232aa4 ldr r12, [r9, #0x44]
 *   @0x232aa8 add r8, r8, #1
 *   @0x232aac ldr r7, [r9, #0x34]
 *   @0x232ab0 mov r4, r2
 *   @0x232ab4 mov r5, r3
 *   @0x232ab8 ldrd r0, r1, [r12, r6]
 *   @0x232abc add r6, r6, #16
 *   @0x232ac0 adds r10, r10, r0
 *   @0x232ac4 adc r11, r11, r1
 *   @0x232ac8 cmp r7, r8
 *   @0x232acc ble 0x232b58 <ov_time_seek+0x114>
 *   @0x232ad0 mov r0, r9
 *   @0x232ad4 mov r1, r8
 *   @0x232ad8 bl 0x231424 <ov_time_total>
 *   @0x232adc adds r2, r4, r0
 *   @0x232ae0 adc r3, r5, r1
 *   @0x232ae4 ldrd r0, r1, [sp, #8]
 *   @0x232ae8 cmp r0, r2
 *   @0x232aec sbcs r1, r1, r3
 *   @0x232af0 bge 0x232aa4 <ov_time_seek+0x60>
 *   @0x232af4 ldr r1, [r9, #0x34]
 *   @0x232af8 mov r2, r4
 *   @0x232afc mov r3, r5
 *   @0x232b00 cmp r1, r8
 *   @0x232b04 beq 0x232b60 <ov_time_seek+0x11c>
 *   @0x232b08 ldr r1, [r9, #0x48]
 *   @0x232b0c ldrd r4, r5, [sp, #8]
 *   @0x232b10 add r8, r1, r8, lsl #5
 *   @0x232b14 subs r4, r4, r2
 *   @0x232b18 sbc r5, r5, r3
 *   @0x232b1c mov r2, #1000
 *   @0x232b20 ldr r12, [r8, #0x8]
 *   @0x232b24 mov r3, #0
 *   @0x232b28 asr r7, r12, #31
 *   @0x232b2c umull r0, r1, r4, r12
 *   @0x232b30 mul lr, r4, r7
 *   @0x232b34 mla r12, r12, r5, lr
 *   @0x232b38 add r1, r12, r1
 *   @0x232b3c bl 0x319414 <__aeabi_ldivmod>
 *   @0x232b40 adds r2, r0, r10
 *   @0x232b44 mov r0, r9
 *   @0x232b48 adc r3, r1, r11
 *   @0x232b4c add sp, sp, #20
 *   @0x232b50 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x232b54 b 0x2326f4 <ov_pcm_seek>
 *   @0x232b58 mov r1, r7
 *   @0x232b5c b 0x232b00 <ov_time_seek+0xbc>
 *   @0x232b60 mvn r0, #130
 *   @0x232b64 add sp, sp, #20
 *   @0x232b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x232b6c mov r2, #0
 *   @0x232b70 mov r3, #0
 *   @0x232b74 mov r8, #0
 *   @0x232b78 mov r10, r2
 *   @0x232b7c mov r11, r3
 *   @0x232b80 b 0x232b00 <ov_time_seek+0xbc>
 *   @0x232b84 mvn r0, #137
 *   @0x232b88 b 0x232b64 <ov_time_seek+0x120>
 *
 * ══ §18/94 ov_time_seek_page  0x232b8c  size 328  82 条（0x232b8c..0x232cd4）
 * @func 0x232b8c 0x232cd4  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_time_seek_page+0x11c×2 / ov_time_seek_page+0x128 / ov_time_seek_page+0x114 / ov_time_total / anon_319414
 * 字段偏移 top8: 0x34×3 / 0x58×1 / 0x4×1 / 0x44×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232b8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x232b90 sub sp, sp, #20
 *   @0x232b94 mov r9, r0
 *   @0x232b98 strd r2, r3, [sp, #8]
 *   @0x232b9c ldr r3, [r0, #0x58]
 *   @0x232ba0 cmp r3, #1
 *   @0x232ba4 ble 0x232ca8 <ov_time_seek_page+0x11c>
 *   @0x232ba8 ldr r3, [r0, #0x4]
 *   @0x232bac cmp r3, #0
 *   @0x232bb0 beq 0x232ccc <ov_time_seek_page+0x140>
 *   @0x232bb4 ldrd r2, r3, [sp, #8]
 *   @0x232bb8 cmp r2, #0
 *   @0x232bbc sbcs r3, r3, #0
 *   @0x232bc0 blt 0x232ca8 <ov_time_seek_page+0x11c>
 *   @0x232bc4 ldr r1, [r0, #0x34]
 *   @0x232bc8 cmp r1, #0
 *   @0x232bcc ble 0x232cb4 <ov_time_seek_page+0x128>
 *   @0x232bd0 mov r4, #0
 *   @0x232bd4 mov r5, #0
 *   @0x232bd8 mov r6, #8
 *   @0x232bdc mov r10, r4
 *   @0x232be0 mov r11, r5
 *   @0x232be4 mov r8, #0
 *   @0x232be8 b 0x232c18 <ov_time_seek_page+0x8c>
 *   @0x232bec ldr r12, [r9, #0x44]
 *   @0x232bf0 add r8, r8, #1
 *   @0x232bf4 ldr r7, [r9, #0x34]
 *   @0x232bf8 mov r4, r2
 *   @0x232bfc mov r5, r3
 *   @0x232c00 ldrd r0, r1, [r12, r6]
 *   @0x232c04 add r6, r6, #16
 *   @0x232c08 adds r10, r10, r0
 *   @0x232c0c adc r11, r11, r1
 *   @0x232c10 cmp r7, r8
 *   @0x232c14 ble 0x232ca0 <ov_time_seek_page+0x114>
 *   @0x232c18 mov r0, r9
 *   @0x232c1c mov r1, r8
 *   @0x232c20 bl 0x231424 <ov_time_total>
 *   @0x232c24 adds r2, r4, r0
 *   @0x232c28 adc r3, r5, r1
 *   @0x232c2c ldrd r0, r1, [sp, #8]
 *   @0x232c30 cmp r0, r2
 *   @0x232c34 sbcs r1, r1, r3
 *   @0x232c38 bge 0x232bec <ov_time_seek_page+0x60>
 *   @0x232c3c ldr r1, [r9, #0x34]
 *   @0x232c40 mov r2, r4
 *   @0x232c44 mov r3, r5
 *   @0x232c48 cmp r1, r8
 *   @0x232c4c beq 0x232ca8 <ov_time_seek_page+0x11c>
 *   @0x232c50 ldr r1, [r9, #0x48]
 *   @0x232c54 ldrd r4, r5, [sp, #8]
 *   @0x232c58 add r8, r1, r8, lsl #5
 *   @0x232c5c subs r4, r4, r2
 *   @0x232c60 sbc r5, r5, r3
 *   @0x232c64 mov r2, #1000
 *   @0x232c68 ldr r12, [r8, #0x8]
 *   @0x232c6c mov r3, #0
 *   @0x232c70 asr r7, r12, #31
 *   @0x232c74 umull r0, r1, r4, r12
 *   @0x232c78 mul lr, r4, r7
 *   @0x232c7c mla r12, r12, r5, lr
 *   @0x232c80 add r1, r12, r1
 *   @0x232c84 bl 0x319414 <__aeabi_ldivmod>
 *   @0x232c88 adds r2, r0, r10
 *   @0x232c8c mov r0, r9
 *   @0x232c90 adc r3, r1, r11
 *   @0x232c94 add sp, sp, #20
 *   @0x232c98 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x232c9c b 0x231ed4 <ov_pcm_seek_page>
 *   @0x232ca0 mov r1, r7
 *   @0x232ca4 b 0x232c48 <ov_time_seek_page+0xbc>
 *   @0x232ca8 mvn r0, #130
 *   @0x232cac add sp, sp, #20
 *   @0x232cb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x232cb4 mov r2, #0
 *   @0x232cb8 mov r3, #0
 *   @0x232cbc mov r8, #0
 *   @0x232cc0 mov r10, r2
 *   @0x232cc4 mov r11, r3
 *   @0x232cc8 b 0x232c48 <ov_time_seek_page+0xbc>
 *   @0x232ccc mvn r0, #137
 *   @0x232cd0 b 0x232cac <ov_time_seek_page+0x120>
 *
 * ══ §19/94 _vorbis_apply_window  0x23311c  size 328  82 条（0x23311c..0x233264）
 * @func 0x23311c 0x233264  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _vorbis_apply_window+0x140 / _vorbis_apply_window+0xd4 / _vorbis_apply_window+0x134
 * 字段偏移 top8: 0x4×7 / 0x2×3 / 0x-8×2 / 0x28×1 / 0x2c×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23311c push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x233120 sub sp, sp, #12
 *   @0x233124 ldr r9, [r2, r3, lsl #2]
 *   @0x233128 ldr r12, [sp, #0x28]
 *   @0x23312c cmp r9, #0
 *   @0x233130 ldr r7, [sp, #0x2c]
 *   @0x233134 ldr r5, [r2, r12, lsl #2]
 *   @0x233138 add r12, r9, #3
 *   @0x23313c movge r12, r9
 *   @0x233140 ldr r2, [r2, r7, lsl #2]
 *   @0x233144 cmp r5, #0
 *   @0x233148 add r4, r5, #3
 *   @0x23314c add r10, r2, #3
 *   @0x233150 add r6, r5, r5, lsr #31
 *   @0x233154 movge r4, r5
 *   @0x233158 cmp r2, #0
 *   @0x23315c asr r4, r4, #2
 *   @0x233160 add r8, r2, r2, lsr #31
 *   @0x233164 add r6, r4, r6, asr #1
 *   @0x233168 movlt r2, r10
 *   @0x23316c sub r12, r4, r12, asr #2
 *   @0x233170 ldr r10, [r1]
 *   @0x233174 ldr r4, [r1, #0x4]
 *   @0x233178 add r9, r9, r9, lsr #31
 *   @0x23317c cmp r12, #0
 *   @0x233180 sub r1, r6, r2, asr #2
 *   @0x233184 asr r8, r8, #1
 *   @0x233188 add r9, r12, r9, asr #1
 *   @0x23318c add r6, r8, r1
 *   @0x233190 str r10, [sp]
 *   @0x233194 str r4, [sp, #0x4]
 *   @0x233198 ble 0x23325c <_vorbis_apply_window+0x140>
 *   @0x23319c add r10, r0, r12, lsl #2
 *   @0x2331a0 mov r2, r0
 *   @0x2331a4 mov r4, #0
 *   @0x2331a8 str r4, [r2], #4
 *   @0x2331ac cmp r2, r10
 *   @0x2331b0 bne 0x2331a8 <_vorbis_apply_window+0x8c>
 *   @0x2331b4 cmp r9, r12
 *   @0x2331b8 ble 0x2331f0 <_vorbis_apply_window+0xd4>
 *   @0x2331bc add r2, sp, #8
 *   @0x2331c0 add r12, r0, r12, lsl #2
 *   @0x2331c4 add r3, r2, r3, lsl #2
 *   @0x2331c8 add r9, r0, r9, lsl #2
 *   @0x2331cc ldr r4, [r3, #-0x8]
 *   @0x2331d0 sub r4, r4, #4
 *   @0x2331d4 ldr r2, [r12]
 *   @0x2331d8 ldr r3, [r4, #0x4]!
 *   @0x2331dc smull r2, r3, r2, r3
 *   @0x2331e0 lsl r3, r3, #1
 *   @0x2331e4 str r3, [r12], #4
 *   @0x2331e8 cmp r12, r9
 *   @0x2331ec bne 0x2331d4 <_vorbis_apply_window+0xb8>
 *   @0x2331f0 cmp r1, r6
 *   @0x2331f4 bge 0x233230 <_vorbis_apply_window+0x114>
 *   @0x2331f8 add r3, sp, #8
 *   @0x2331fc add r1, r0, r1, lsl #2
 *   @0x233200 add r7, r3, r7, lsl #2
 *   @0x233204 add r4, r0, r6, lsl #2
 *   @0x233208 ldr r12, [r7, #-0x8]
 *   @0x23320c add r12, r12, r8, lsl #2
 *   @0x233210 ldr r2, [r1]
 *   @0x233214 ldr r3, [r12, #-0x4]!
 *   @0x233218 smull r2, r3, r2, r3
 *   @0x23321c lsl r3, r3, #1
 *   @0x233220 str r3, [r1], #4
 *   @0x233224 cmp r1, r4
 *   @0x233228 bne 0x233210 <_vorbis_apply_window+0xf4>
 *   @0x23322c mov r1, r6
 *   @0x233230 cmp r5, r1
 *   @0x233234 ble 0x233250 <_vorbis_apply_window+0x134>
 *   @0x233238 add r1, r0, r1, lsl #2
 *   @0x23323c add r5, r0, r5, lsl #2
 *   @0x233240 mov r3, #0
 *   @0x233244 str r3, [r1], #4
 *   @0x233248 cmp r1, r5
 *   @0x23324c bne 0x233244 <_vorbis_apply_window+0x128>
 *   @0x233250 add sp, sp, #12
 *   @0x233254 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x233258 bx lr
 *   @0x23325c mov r12, #0
 *   @0x233260 b 0x2331b4 <_vorbis_apply_window+0x98>
 *
 * ══ §20/94 yyMatrix::CreateRotationAxis(yyMatrix*, yyVector3*, float)  0x27a8b8  size 328  82 条（0x27a8b8..0x27aa00）
 * @func 0x27a8b8 0x27aa00  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb6580 / 0xb6700
 * 字段偏移 top8: 0x4×2 / 0x38×1 / 0x34×1 / 0x30×1 / 0x2c×1 / 0x1c×1 / 0xc×1
 * VFP 指令 63 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27a8b8 push {r4, lr}
 *   @0x27a8bc vpush {d8, d9, d10}
 *   @0x27a8c0 vldr s17, [r1, #4]
 *   @0x27a8c4 vmul.f32 s15, s17, s17
 *   @0x27a8c8 vldr s19, [r1]
 *   @0x27a8cc vldr s14, [r1, #8]
 *   @0x27a8d0 vmov s13, r2
 *   @0x27a8d4 vldr s21, [pc, #288]
 *   @0x27a8d8 sub sp, sp, #8
 *   @0x27a8dc mov r4, r0
 *   @0x27a8e0 vmla.f32 s15, s19, s19
 *   @0x27a8e4 vmla.f32 s15, s14, s14
 *   @0x27a8e8 vsqrt.f32 s16, s15
 *   @0x27a8ec vcmp.f32 s16, s16
 *   @0x27a8f0 vmul.f32 s21, s13, s21
 *   @0x27a8f4 vmrs APSR_nzcv, fpscr
 *   @0x27a8f8 bne 0x27a9d8 <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f+0x120>
 *   @0x27a8fc vmov r0, s21
 *   @0x27a900 vmov.f32 s20, #1.000000e+00
 *   @0x27a904 vdiv.f32 s16, s20, s16
 *   @0x27a908 vmul.f32 s17, s16, s17
 *   @0x27a90c vmul.f32 s19, s16, s19
 *   @0x27a910 vstr s17, [r1, #4]
 *   @0x27a914 vmul.f32 s16, s16, s14
 *   @0x27a918 vstr s19, [r1]
 *   @0x27a91c vstr s16, [r1, #8]
 *   @0x27a920 bl 0xb658c <cosf@plt>
 *   @0x27a924 vmov s18, r0
 *   @0x27a928 vmov r0, s21
 *   @0x27a92c bl 0xb6580 <sinf@plt>
 *   @0x27a930 vsub.f32 s13, s20, s18
 *   @0x27a934 mov r3, #0
 *   @0x27a938 vstr s20, [r4, #60]
 *   @0x27a93c str r3, [r4, #0x38]
 *   @0x27a940 str r3, [r4, #0x34]
 *   @0x27a944 str r3, [r4, #0x30]
 *   @0x27a948 str r3, [r4, #0x2c]
 *   @0x27a94c str r3, [r4, #0x1c]
 *   @0x27a950 str r3, [r4, #0xc]
 *   @0x27a954 vmul.f32 s15, s13, s19
 *   @0x27a958 vmul.f32 s7, s13, s17
 *   @0x27a95c vmov s14, r0
 *   @0x27a960 vmov.f32 s6, s18
 *   @0x27a964 vmul.f32 s8, s15, s17
 *   @0x27a968 vmul.f32 s10, s15, s16
 *   @0x27a96c vmla.f32 s6, s15, s19
 *   @0x27a970 vmov.f32 s15, s18
 *   @0x27a974 vstr s6, [r4]
 *   @0x27a978 vmla.f32 s15, s7, s17
 *   @0x27a97c vmul.f32 s9, s14, s16
 *   @0x27a980 vstr s15, [r4, #20]
 *   @0x27a984 vmul.f32 s13, s13, s16
 *   @0x27a988 vmul.f32 s12, s14, s19
 *   @0x27a98c vmul.f32 s14, s14, s17
 *   @0x27a990 vadd.f32 s15, s8, s9
 *   @0x27a994 vmul.f32 s11, s7, s16
 *   @0x27a998 vstr s15, [r4, #4]
 *   @0x27a99c vmla.f32 s18, s13, s16
 *   @0x27a9a0 vsub.f32 s15, s10, s14
 *   @0x27a9a4 vstr s18, [r4, #40]
 *   @0x27a9a8 vsub.f32 s9, s8, s9
 *   @0x27a9ac vstr s15, [r4, #8]
 *   @0x27a9b0 vadd.f32 s14, s10, s14
 *   @0x27a9b4 vstr s9, [r4, #16]
 *   @0x27a9b8 vadd.f32 s15, s11, s12
 *   @0x27a9bc vstr s14, [r4, #32]
 *   @0x27a9c0 vsub.f32 s12, s11, s12
 *   @0x27a9c4 vstr s15, [r4, #24]
 *   @0x27a9c8 vstr s12, [r4, #36]
 *   @0x27a9cc add sp, sp, #8
 *   @0x27a9d0 vpop {d8, d9, d10}
 *   @0x27a9d4 pop {r4, pc}
 *   @0x27a9d8 vmov r0, s15
 *   @0x27a9dc str r1, [sp, #0x4]
 *   @0x27a9e0 bl 0xb6700 <sqrtf@plt>
 *   @0x27a9e4 ldr r1, [sp, #0x4]
 *   @0x27a9e8 vldr s19, [r1]
 *   @0x27a9ec vldr s17, [r1, #4]
 *   @0x27a9f0 vldr s14, [r1, #8]
 *   @0x27a9f4 vmov s16, r0
 *   @0x27a9f8 b 0x27a8fc <_ZN8yyMatrix18CreateRotationAxisEPS_P9yyVector3f+0x44>
 *   @0x27a9fc vstmialo lr, {s30, s31}
 *
 * ══ §21/94 Debug_GetJSInstances(Buffer_Standard*, Buffer_Standard*)  0x29aa44  size 328  82 条（0x29aa44..0x29ab8c）
 * @func 0x29aa44 0x29ab8c  size 328  82 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / Debug_GetJSInstances(Buffer_Standard*, Buffer_Standard*)+0x140 / VM::GetObjectBaseVariables(Buffer_Standard*, YYObjectBase*, bool)
 * 字段偏移 top8: 0x38×4 / 0x4×4 / 0x8×4 / 0x2c×4 / 0x30×4 / 0xc×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29aa44 ldr r12, [r0]
 *   @0x29aa48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29aa4c add r10, r0, #44
 *   @0x29aa50 mov r4, r1
 *   @0x29aa54 sub sp, sp, #12
 *   @0x29aa58 mov r2, r10
 *   @0x29aa5c mov r6, #0
 *   @0x29aa60 ldr r12, [r12, #0xc]
 *   @0x29aa64 mov r1, #5
 *   @0x29aa68 mov r9, r0
 *   @0x29aa6c blx r12
 *   @0x29aa70 mov r1, r6
 *   @0x29aa74 mov r0, r10
 *   @0x29aa78 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29aa7c ldr r12, [r4]
 *   @0x29aa80 add r7, r4, #44
 *   @0x29aa84 str r6, [r4, #0x38]
 *   @0x29aa88 mov r1, #5
 *   @0x29aa8c mov r2, r7
 *   @0x29aa90 vmov s13, r0
 *   @0x29aa94 str r0, [sp, #0x4]
 *   @0x29aa98 mov r0, r4
 *   @0x29aa9c vcvt.f64.u32 d7, s13
 *   @0x29aaa0 vstr s14, [r4, #44]
 *   @0x29aaa4 vstr s15, [r4, #48]
 *   @0x29aaa8 ldr r12, [r12, #0x8]
 *   @0x29aaac blx r12
 *   @0x29aab0 ldr r3, [sp, #0x4]
 *   @0x29aab4 cmp r3, r6
 *   @0x29aab8 ble 0x29ab84 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x140>
 *   @0x29aabc mov r11, r6
 *   @0x29aac0 mov r8, r6
 *   @0x29aac4 movt r11, #0x3ff0
 *   @0x29aac8 b 0x29ab00 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0xbc>
 *   @0x29aacc str r8, [r4, #0x2c]
 *   @0x29aad0 add r6, r6, #1
 *   @0x29aad4 str r11, [r4, #0x30]
 *   @0x29aad8 str r8, [r4, #0x38]
 *   @0x29aadc ldr r12, [r12, #0x8]
 *   @0x29aae0 blx r12
 *   @0x29aae4 mov r0, r4
 *   @0x29aae8 mov r1, r5
 *   @0x29aaec mov r2, #1
 *   @0x29aaf0 bl 0xd8df4 <_ZN2VM22GetObjectBaseVariablesEP15Buffer_StandardP12YYObjectBaseb>
 *   @0x29aaf4 ldr r3, [sp, #0x4]
 *   @0x29aaf8 cmp r3, r6
 *   @0x29aafc beq 0x29ab84 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x140>
 *   @0x29ab00 ldr r12, [r9]
 *   @0x29ab04 mov r1, #12
 *   @0x29ab08 mov r2, r10
 *   @0x29ab0c mov r0, r9
 *   @0x29ab10 ldr r12, [r12, #0xc]
 *   @0x29ab14 blx r12
 *   @0x29ab18 ldr r5, [r9, #0x2c]
 *   @0x29ab1c ldr lr, [r9, #0x30]
 *   @0x29ab20 mov r1, #12
 *   @0x29ab24 ldr r12, [r4]
 *   @0x29ab28 mov r2, r7
 *   @0x29ab2c str r5, [r4, #0x2c]
 *   @0x29ab30 mov r3, #10
 *   @0x29ab34 str lr, [r4, #0x30]
 *   @0x29ab38 mov r0, r4
 *   @0x29ab3c ldr r12, [r12, #0x8]
 *   @0x29ab40 str r3, [r4, #0x38]
 *   @0x29ab44 blx r12
 *   @0x29ab48 cmp r5, #0
 *   @0x29ab4c mov r2, r7
 *   @0x29ab50 mov r0, r4
 *   @0x29ab54 mov r1, #5
 *   @0x29ab58 ldr r12, [r4]
 *   @0x29ab5c bne 0x29aacc <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0x88>
 *   @0x29ab60 str r5, [r4, #0x2c]
 *   @0x29ab64 add r6, r6, #1
 *   @0x29ab68 str r5, [r4, #0x30]
 *   @0x29ab6c str r5, [r4, #0x38]
 *   @0x29ab70 ldr r12, [r12, #0x8]
 *   @0x29ab74 blx r12
 *   @0x29ab78 ldr r3, [sp, #0x4]
 *   @0x29ab7c cmp r3, r6
 *   @0x29ab80 bne 0x29ab00 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_+0xbc>
 *   @0x29ab84 add sp, sp, #12
 *   @0x29ab88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §22/94 png_check_cHRM_fixed  0x2a6068  size 328  82 条（0x2a6068..0x2a61b0）
 * @func 0x2a6068 0x2a61b0  size 328  82 条
 * 部分覆盖: 本节 82/156 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_check_cHRM_fixed+0x46×5 / png_warning×2 / 0x4a9ca0 / 0x6e47d0 / 0x6f304c / 0xff4647a0 / 0xff466184 / 0x6e5f20
 * 字段偏移 top8: 0x30×4 / 0x2c×3 / 0x44×2 / 0x38×1 / 0x40×1 / 0x9c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6068 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a606c sub sp, #0x14
 *   @0x2a6070 mov r9, r2
 *   @0x2a6074 ldr r7, [sp, #0x38]
 *   @0x2a6078 .word 0x4604b03c
 *   @0x2a607c ldr.w r10, [sp, #0x48]
 *   @0x2a6080 cmp r0, #0x0
 *   @0x2a6084 stmdbhs r0, {r0, r7, pc}
 *   @0x2a6088 blt 0x2a60ae <png_check_cHRM_fixed+0x46>
 *   @0x2a608c ble 0x2a60ae <png_check_cHRM_fixed+0x46>
 *   @0x2a6090 blt 0x2a60ae <png_check_cHRM_fixed+0x46>
 *   @0x2a6094 blt 0x2a60ae <png_check_cHRM_fixed+0x46>
 *   @0x2a6098 blle 0x4a9ca0 <SrcVerts+0x6ce4>
 *   @0x2a609c ldr r2, [sp, #0x40]
 *   @0x2a60a0 blt 0x2a60ae <png_check_cHRM_fixed+0x46>
 *   @0x2a60a4 cmp r3, #0x0
 *   @0x2a60a8 cmp.w r10, #0x0
 *   @0x2a60ac bge 0x2a60bc <png_check_cHRM_fixed+0x54>
 *   @0x2a60b0 mov r0, r4
 *   @0x2a60b4 add r1, pc
 *   @0x2a60b8 .word 0xe000f9dd
 *   @0x2a60bc movs r5, #0x1
 *   @0x2a60c0 ldrmi r4, [r8, #0x300]
 *   @0x2a60c4 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60c8 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60cc beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60d0 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60d4 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60d8 cmp r2, r3
 *   @0x2a60dc ldr r2, [sp, #0x44]
 *   @0x2a60e0 beq 0x2a60e6 <png_check_cHRM_fixed+0x7e>
 *   @0x2a60e4 bne 0x2a60f2 <png_check_cHRM_fixed+0x8a>
 *   @0x2a60e8 mov r0, r4
 *   @0x2a60ec add r1, pc
 *   @0x2a60f0 .word 0xf5c9f9c1
 *   @0x2a60f4 adclo r3, r0, #805306380
 *   @0x2a60f8 cmp r2, r8
 *   @0x2a60fc ldr r1, [pc, #0x9c]
 *   @0x2a6100 movs r5, #0x0
 *   @0x2a6104 bl 0x2a6474 <png_warning>
 *   @0x2a6108 rsb.w r3, r7, #0x18600
 *   @0x2a610c adds r3, #0xa0
 *   @0x2a6110 bge 0x2a611e <png_check_cHRM_fixed+0xb6>
 *   @0x2a6114 mov r0, r4
 *   @0x2a6118 add r1, pc
 *   @0x2a611c bls 0x6e47d0 <g_SWFvertbuff+0x11708>
 *   @0x2a6120 rsb.w r3, r2, #0x18600
 *   @0x2a6124 adds r3, #0xa0
 *   @0x2a6128 bge 0x2a6136 <png_check_cHRM_fixed+0xce>
 *   @0x2a612c mov r0, r4
 *   @0x2a6130 add r1, pc
 *   @0x2a6134 .word 0xf5caf99f
 *   @0x2a6138 bls 0x6f304c <g_SWFvertbuff+0x1ff84>
 *   @0x2a613c adds r3, #0xa0
 *   @0x2a6140 bge 0x2a614e <png_check_cHRM_fixed+0xe6>
 *   @0x2a6144 mov r0, r4
 *   @0x2a6148 add r1, pc
 *   @0x2a614c bl 0xff4647a0 <b2_toiTime+0xfffffffffed0b2fc>
 *   @0x2a6150 bl 0xff466184 <b2_toiTime+0xfffffffffed0cce0>
 *   @0x2a6154 strbtmi r0, [r10], -r10, lsl #2
 *   @0x2a6158 add r3, sp, #0x4
 *   @0x2a615c blls 0x6e5f20 <g_SWFvertbuff+0x12e58>
 *   @0x2a6160 ldr r2, [sp, #0x44]
 *   @0x2a6164 add r3, sp, #0xc
 *   @0x2a6168 add r2, sp, #0x8
 *   @0x2a616c blls 0x365f10 <_ZTS12CDS_Priority+0x7f68>
 *   @0x2a6170 ldr r2, [sp]
 *   @0x2a6174 bne 0x2a618c <png_check_cHRM_fixed+0x124>
 *   @0x2a6178 ldr r2, [sp, #0x4]
 *   @0x2a617c bne 0x2a618c <png_check_cHRM_fixed+0x124>
 *   @0x2a6180 mov r0, r4
 *   @0x2a6184 bl 0x2a6474 <png_warning>
 *   @0x2a6188 movs r0, #0x0
 *   @0x2a618c mov r0, r5
 *   @0x2a6190 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a6194 str r0, [r6, #0x2c]
 *   @0x2a6198 str r4, [r5, #0x2c]
 *   @0x2a619c str r4, [r2, #0x30]
 *   @0x2a61a0 str r7, [r2, #0x30]
 *   @0x2a61a4 str r6, [r2, #0x30]
 *   @0x2a61a8 str r7, [r2, #0x30]
 *   @0x2a61ac str r5, [r6, #0x2c]
 *
 * ══ §23/94 png_decompress_chunk  0x2abd08  size 328  82 条（0x2abd08..0x2abe50）
 * @func 0x2abd08 0x2abe50  size 328  82 条
 * 部分覆盖: 本节 82/144 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2aba80×2 / png_malloc_warn×2 / 0x196c960 / png_decompress_chunk+0x6a / png_free / 0xb65c8 / png_warning / 0xb65bc
 * 字段偏移 top8: 0x3c×1 / 0x110×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abd08 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2abd0c mov r5, r3
 *   @0x2abd10 mov r6, r1
 *   @0x2abd14 cmp r5, r2
 *   @0x2abd18 ldr r3, [r3]
 *   @0x2abd1c ldr.w r8, [sp, #0x68]
 *   @0x2abd20 ldr r1, [r3]
 *   @0x2abd24 str r1, [sp, #0x3c]
 *   @0x2abd28 ldr r1, [pc, #0x110]
 *   @0x2abd2c add r1, pc
 *   @0x2abd30 subs pc, pc, r1, lsr #23
 *   @0x2abd34 cmp r6, #0x0
 *   @0x2abd38 ldr.w r1, [r0, #0x330]
 *   @0x2abd3c rsb r9, r5, r2
 *   @0x2abd40 mov r3, r6
 *   @0x2abd44 add r1, r5
 *   @0x2abd48 bl 0x2aba80 <png_do_read_intrapixel+0x88>
 *   @0x2abd4c adds r3, r5, #0x3
 *   @0x2abd50 bhi 0x2abd6a <png_decompress_chunk+0x62>
 *   @0x2abd54 blne 0x196c960 <b2_toiTime+0x12134bc>
 *   @0x2abd58 cmp r0, r3
 *   @0x2abd5c ldr.w r3, [r4, #0x1a0]
 *   @0x2abd60 cbz r3, 0x2abd72 <png_decompress_chunk+0x6a>
 *   @0x2abd64 subs r3, #0x1
 *   @0x2abd68 blo 0x2abd72 <png_decompress_chunk+0x6a>
 *   @0x2abd6c mov r0, r4
 *   @0x2abd70 b 0x2abdf0 <png_decompress_chunk+0xe8>
 *   @0x2abd74 beq 0x2abdf4 <png_decompress_chunk+0xec>
 *   @0x2abd78 strtmi r0, [r0], -r5, lsl #22
 *   @0x2abd7c add.w r1, r11, #0x1
 *   @0x2abd80 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2abd84 mov r7, r0
 *   @0x2abd88 ldr.w r1, [r4, #0x330]
 *   @0x2abd8c mov r2, r5
 *   @0x2abd90 .word 0xf8d4ec16
 *   @0x2abd94 ldmdbne r11!, {r4, r5, r8, r9, r12} ^
 *   @0x2abd98 str r6, [sp]
 *   @0x2abd9c add r1, r5
 *   @0x2abda0 bl 0x2aba80 <png_do_read_intrapixel+0x88>
 *   @0x2abda4 movs r3, #0x0
 *   @0x2abda8 adcsmi r3, r0, #11
 *   @0x2abdac mov r0, r4
 *   @0x2abdb0 ldr.w r1, [r4, #0x330]
 *   @0x2abdb4 bl 0x2a6cfc <png_free>
 *   @0x2abdb8 str.w r7, [r4, #0x330]
 *   @0x2abdbc str.w r11, [r8]
 *   @0x2abdc0 b 0x2abe22 <png_decompress_chunk+0x11a>
 *   @0x2abdc4 add r1, pc
 *   @0x2abdc8 qsaxmi pc, r0, r5
 *   @0x2abdcc mov r1, r7
 *   @0x2abdd0 mul pc, r5, pc
 *   @0x2abdd4 ldr r1, [pc, #0x70]
 *   @0x2abdd8 add r1, pc
 *   @0x2abddc add r7, sp, #0x8
 *   @0x2abde0 movs r1, #0x32
 *   @0x2abde4 mov r0, r7
 *   @0x2abde8 blx 0xb65c8 <snprintf@plt>
 *   @0x2abdec mov r0, r4
 *   @0x2abdf0 bl 0x2a6474 <png_warning>
 *   @0x2abdf4 mov r0, r4
 *   @0x2abdf8 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2abdfc mov r6, r0
 *   @0x2abe00 cbz r5, 0x2abe0c <png_decompress_chunk+0x104>
 *   @0x2abe04 qasxmi r1, r10, r0
 *   @0x2abe08 blx 0xb65bc <memcpy@plt>
 *   @0x2abe0c mov r0, r4
 *   @0x2abe10 .word 0xf7fa1330
 *   @0x2abe14 .word 0xf8c4ff73
 *   @0x2abe18 movwhs r6, #0x330
 *   @0x2abe1c strb r3, [r6, r5]
 *   @0x2abe20 bls 0x67fe28 <g_SWFlinevertbuff+0x2cd60>
 *   @0x2abe24 ldr.w r3, [r10]
 *   @0x2abe28 cmp r2, r3
 *   @0x2abe2c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2abe30 add sp, #0x44
 *   @0x2abe34 svclt #0x8ff0
 *   @0x2abe38 adds r6, r7, #0x0
 *   @0x2abe3c lsrs r5, r5, #0x1a
 *   @0x2abe40 lsrs r7, r7, #0x19
 *   @0x2abe44 lsrs r3, r2, #0x19
 *   @0x2abe48 lsrs r7, r2, #0x19
 *   @0x2abe4c lsrs r7, r5, #0x19
 *
 * ══ §24/94 png_handle_tEXt  0x2ad584  size 328  82 条（0x2ad584..0x2ad6cc）
 * @func 0x2ad584 0x2ad6cc  size 328  82 条
 * 部分覆盖: 本节 82/152 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anonT_2fa06c+0x178 / png_error / png_crc_read / png_crc_finish / png_free / 0x4ce2e8 / png_warning / 0xb6538
 * 字段偏移 top8: 0xc8×1 / 0x14×1 / 0x10×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad584 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2ad588 mov r4, r0
 *   @0x2ad58c pkhbtmi r3, r9, r0, lsl #6
 *   @0x2ad590 mov r5, r2
 *   @0x2ad594 cmp r3, #0x1
 *   @0x2ad598 subs r3, #0x1
 *   @0x2ad59c blhs 0x2fa1e4 <ps_hints_apply+0x8de4>
 *   @0x2ad5a0 bne 0x2ad5b6 <png_handle_tEXt+0x32>
 *   @0x2ad5a4 add r1, pc
 *   @0x2ad5a8 strtmi pc, [r0], -r5, ror #30
 *   @0x2ad5ac mov r1, r5
 *   @0x2ad5b0 .word 0xf7fe43f8
 *   @0x2ad5b4 .word 0xf8d4bb6f
 *   @0x2ad5b8 ldrbeq r3, [r9, r12, lsr #2]
 *   @0x2ad5bc bmi 0x2ad5c8 <png_handle_tEXt+0x44>
 *   @0x2ad5c0 mov r0, r4
 *   @0x2ad5c4 bl 0x2a642c <png_error>
 *   @0x2ad5c8 ldr.w r3, [r4, #0x12c]
 *   @0x2ad5cc mov r0, r4
 *   @0x2ad5d0 smmlareq r10, r0, r3, r1
 *   @0x2ad5d4 itt mi
 *   @0x2ad5d8 .word 0xf8c40308
 *   @0x2ad5dc .word 0xf7f9312c
 *   @0x2ad5e0 .word 0x1c69fb8d
 *   @0x2ad5e4 mov r0, r4
 *   @0x2ad5e8 .word 0x4601fb96
 *   @0x2ad5ec str.w r0, [r4, #0x330]
 *   @0x2ad5f0 mov r0, r4
 *   @0x2ad5f4 ldr r1, [pc, #0xc8]
 *   @0x2ad5f8 b 0x2ad6aa <png_handle_tEXt+0x126>
 *   @0x2ad5fc bl 0x2abc0c <png_crc_read>
 *   @0x2ad600 mov r0, r4
 *   @0x2ad604 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad608 cbz r0, 0x2ad61e <png_handle_tEXt+0x9a>
 *   @0x2ad60c ldr.w r1, [r4, #0x330]
 *   @0x2ad610 bl 0x2a6cfc <png_free>
 *   @0x2ad614 movs r3, #0x0
 *   @0x2ad618 pop {r4, r5, r8, r9, r12, sp}
 *   @0x2ad61c .word 0xf8d483f8
 *   @0x2ad620 bl 0x4ce2e8 <SrcVerts+0x2b32c>
 *   @0x2ad624 strbmi r0, [r3], -r5, lsl #4
 *   @0x2ad628 strb.w r0, [r8, r5]
 *   @0x2ad62c mov r7, r3
 *   @0x2ad630 ldrb r6, [r7]
 *   @0x2ad634 bne 0x2ad62c <png_handle_tEXt+0xa8>
 *   @0x2ad638 movs r1, #0x1c
 *   @0x2ad63c ite eq
 *   @0x2ad640 movne r7, r3
 *   @0x2ad644 strmi pc, [r5], -r8, ror #22
 *   @0x2ad648 cbnz r0, 0x2ad666 <png_handle_tEXt+0xe2>
 *   @0x2ad64c mov r0, r4
 *   @0x2ad650 bl 0x2a6474 <png_warning>
 *   @0x2ad654 mov r0, r4
 *   @0x2ad658 .word 0xf7f91330
 *   @0x2ad65c .word 0xf8c4fb4f
 *   @0x2ad660 pop {r4, r5, r8, r9, r12, lr}
 *   @0x2ad664 .word 0xf04f83f8
 *   @0x2ad668 strdvs r3, r4, [r7], pc
 *   @0x2ad66c stm.w r0, {r3, r8}
 *   @0x2ad670 str r6, [r0, #0x14]
 *   @0x2ad674 str r6, [r0, #0x10]
 *   @0x2ad678 blx 0xb6538 <strlen@plt>
 *   @0x2ad67c mov r1, r9
 *   @0x2ad680 movs r3, #0x1
 *   @0x2ad684 mov r0, r4
 *   @0x2ad688 .word 0xf8d4fc37
 *   @0x2ad68c .word 0x46071330
 *   @0x2ad690 mov r0, r4
 *   @0x2ad694 .word 0xf8c4fb33
 *   @0x2ad698 qasxmi r6, r0, r0
 *   @0x2ad69c mov r1, r5
 *   @0x2ad6a0 teqlt r7, sp, lsr #22
 *   @0x2ad6a4 ldr r1, [pc, #0x20]
 *   @0x2ad6a8 add r1, pc
 *   @0x2ad6ac .word 0xf7f843f8
 *   @0x2ad6b0 pop {r0, r5, r6, r7, r9, r10, r11, r12, sp, pc}
 *   @0x2ad6b4 svclt #0x83f8
 *   @0x2ad6b8 lsls r6, r0, #0x6
 *   @0x2ad6bc lsls r1, r1, #0x6
 *   @0x2ad6c0 lsls r6, r5, #0x5
 *   @0x2ad6c4 lsls r6, r6, #0x4
 *   @0x2ad6c8 lsls r4, r0, #0x4
 *
 * ══ §25/94 CFontGM::CFontGM(char const*, int, bool, bool, int, int)  0xf9e08  size 324  81 条（0xf9e08..0xf9f4c）
 * @func 0xf9e08 0xf9f4c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Clear() / YYStrDup(char const*) / CFontGM::CreateIt() / CFontGM::InitTexture()
 * 字段偏移 top8: 0x38×2 / 0x4×2 / 0x8×2 / 0xc×2 / 0xd×2 / 0x18×2 / 0x1c×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9e08 ldr r12, [pc, #0x134]
 *   @0xf9e0c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf9e10 ldr r12, [pc, r12]
 *   @0xf9e14 mov r5, #0
 *   @0xf9e18 mvn lr, #0
 *   @0xf9e1c mov r8, r1
 *   @0xf9e20 str lr, [r0, #0x20]
 *   @0xf9e24 str lr, [r0, #0x38]
 *   @0xf9e28 mov r6, #1056964608
 *   @0xf9e2c add r12, r12, #8
 *   @0xf9e30 str r6, [r0, #0x50]
 *   @0xf9e34 str r12, [r0]
 *   @0xf9e38 mov r12, #1065353216
 *   @0xf9e3c str r5, [r0, #0x4]
 *   @0xf9e40 mov r4, r0
 *   @0xf9e44 str r12, [r0, #0x48]
 *   @0xf9e48 mov r9, r2
 *   @0xf9e4c str r12, [r0, #0x4c]
 *   @0xf9e50 mov r11, r3
 *   @0xf9e54 str r5, [r0, #0x8]
 *   @0xf9e58 strb r5, [r0, #0xc]
 *   @0xf9e5c strb r5, [r0, #0xd]
 *   @0xf9e60 str r5, [r0, #0x18]
 *   @0xf9e64 str r5, [r0, #0x1c]
 *   @0xf9e68 str r5, [r0, #0x24]
 *   @0xf9e6c str r5, [r0, #0x28]
 *   @0xf9e70 str r5, [r0, #0x2c]
 *   @0xf9e74 str r5, [r0, #0x40]
 *   @0xf9e78 str r5, [r0, #0x44]
 *   @0xf9e7c str r5, [r0, #0x5c]
 *   @0xf9e80 str r5, [r0, #0x60]
 *   @0xf9e84 str r5, [r0, #0x64]
 *   @0xf9e88 str r5, [r0, #0x6c]
 *   @0xf9e8c str r5, [r0, #0x70]
 *   @0xf9e90 str r5, [r0, #0x74]
 *   @0xf9e94 str r5, [r0, #0x78]
 *   @0xf9e98 str r5, [r0, #0x7c]
 *   @0xf9e9c str r5, [r0, #0x80]
 *   @0xf9ea0 str r5, [r0, #0x84]
 *   @0xf9ea4 str r5, [r0, #0x88]
 *   @0xf9ea8 str r5, [r0, #0x3c]
 *   @0xf9eac ldrb r10, [sp, #0x28]
 *   @0xf9eb0 ldr r7, [sp, #0x2c]
 *   @0xf9eb4 ldr r6, [sp, #0x30]
 *   @0xf9eb8 str r5, [r0, #0x34]
 *   @0xf9ebc bic r7, r7, r7, asr #31
 *   @0xf9ec0 str r5, [r0, #0x30]
 *   @0xf9ec4 cmp r6, #255
 *   @0xf9ec8 movge r6, #255
 *   @0xf9ecc str r5, [r0, #0x54]
 *   @0xf9ed0 str r5, [r0, #0x8c]
 *   @0xf9ed4 bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf9ed8 mov r0, r8
 *   @0xf9edc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf9ee0 ldr r1, [pc, #0x60]
 *   @0xf9ee4 str r9, [r4, #0x8]
 *   @0xf9ee8 ldr r1, [pc, r1]
 *   @0xf9eec str r7, [r4, #0x18]
 *   @0xf9ef0 strb r11, [r4, #0xc]
 *   @0xf9ef4 ldrb r3, [r1]
 *   @0xf9ef8 str r6, [r4, #0x1c]
 *   @0xf9efc cmp r3, r5
 *   @0xf9f00 strb r10, [r4, #0xd]
 *   @0xf9f04 str r5, [r4, #0x10]
 *   @0xf9f08 movne r3, #3
 *   @0xf9f0c moveq r3, r5
 *   @0xf9f10 str r3, [r4, #0x14]
 *   @0xf9f14 str r0, [r4, #0x4]
 *   @0xf9f18 mov r0, r4
 *   @0xf9f1c bl 0xf9660 <_ZN7CFontGM8CreateItEv>
 *   @0xf9f20 ldr r3, [r4, #0x38]
 *   @0xf9f24 cmn r3, #1
 *   @0xf9f28 beq 0xf9f34 <_ZN7CFontGMC2EPKcibbii+0x12c>
 *   @0xf9f2c mov r0, r4
 *   @0xf9f30 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf9f34 mov r0, r4
 *   @0xf9f38 bl 0xf7db4 <_ZN7CFontGM11InitTextureEv>
 *   @0xf9f3c mov r0, r4
 *   @0xf9f40 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf9f44 eoreq r4, pc, r8, lsr r0
 *   @0xf9f48 eoreq r3, pc, r0, ror pc
 *
 * ══ §26/94 F_DsMapReplaceMap(RValue&, CInstance*, CInstance*, int, RValue*)  0xff6b0  size 324  81 条（0xff6b0..0xff7f4）
 * @func 0xff6b0 0xff7f4  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×3 / YYGetInt32(RValue const*, int)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / F_DsMapReplaceMap(RValue&, CInstance*, CInstance*, int, RValue*)+0xdc / F_DsMapReplaceMap(RValue&, CInstance*, CInstance*, int, RValue*)+0xfc / CDS_Map::Replace(RValue*, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x2×3 / 0x2c×2 / 0x28×1 / 0xc×1 / 0xe8×1 / 0xd8×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff6b0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xff6b4 sub sp, sp, #8
 *   @0xff6b8 add r7, sp, #4
 *   @0xff6bc mov r5, r0
 *   @0xff6c0 ldr r9, [sp, #0x28]
 *   @0xff6c4 mov r4, #0
 *   @0xff6c8 mov r0, r7
 *   @0xff6cc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff6d0 str r4, [r5, #0xc]
 *   @0xff6d4 str r4, [r5]
 *   @0xff6d8 mov r0, r9
 *   @0xff6dc str r4, [r5, #0x4]
 *   @0xff6e0 mov r1, r4
 *   @0xff6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff6e8 subs r8, r0, #0
 *   @0xff6ec blt 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0xff6f0 ldr r6, [pc, #0xe8]
 *   @0xff6f4 ldr r6, [pc, r6]
 *   @0xff6f8 ldr r3, [r6]
 *   @0xff6fc cmp r8, r3
 *   @0xff700 bge 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0xff704 ldr r10, [pc, #0xd8]
 *   @0xff708 ldr r10, [pc, r10]
 *   @0xff70c ldr r3, [r10, #0x4]
 *   @0xff710 ldr r3, [r3, r8, lsl #2]
 *   @0xff714 cmp r3, r4
 *   @0xff718 beq 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0xff71c mov r0, r9
 *   @0xff720 mov r1, #2
 *   @0xff724 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff728 cmp r0, r8
 *   @0xff72c beq 0xff7cc <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0xff730 cmp r0, #0
 *   @0xff734 blt 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0xff738 ldr r3, [r6]
 *   @0xff73c cmp r0, r3
 *   @0xff740 bge 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0xff744 ldr r3, [r10, #0x4]
 *   @0xff748 ldr r2, [r3, r0, lsl #2]
 *   @0xff74c cmp r2, #0
 *   @0xff750 beq 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0xff754 ldr r12, [r9, #0x2c]
 *   @0xff758 add r1, r9, #16
 *   @0xff75c ldr r0, [r3, r8, lsl #2]
 *   @0xff760 add r2, r9, #32
 *   @0xff764 bic r3, r12, #-268435456
 *   @0xff768 orr r3, r3, #-2147483648
 *   @0xff76c str r3, [r9, #0x2c]
 *   @0xff770 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_>
 *   @0xff774 cmp r0, #0
 *   @0xff778 movne r3, #0
 *   @0xff77c strne r4, [r5]
 *   @0xff780 movtne r3, #0x3ff0
 *   @0xff784 strne r3, [r5, #0x4]
 *   @0xff788 b 0xff79c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xff78c ldr r0, [pc, #0x54]
 *   @0xff790 mov r1, #0
 *   @0xff794 add r0, pc, r0
 *   @0xff798 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff79c mov r0, r7
 *   @0xff7a0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff7a4 add sp, sp, #8
 *   @0xff7a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff7ac ldr r0, [pc, #0x38]
 *   @0xff7b0 mov r1, #0
 *   @0xff7b4 add r0, pc, r0
 *   @0xff7b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff7bc mov r0, r7
 *   @0xff7c0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff7c4 add sp, sp, #8
 *   @0xff7c8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xff7cc ldr r0, [pc, #0x1c]
 *   @0xff7d0 mov r1, r4
 *   @0xff7d4 add r0, pc, r0
 *   @0xff7d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff7dc b 0xff79c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xff7e0 eoreq lr, lr, r4, lsl #11
 *   @0xff7e4 eoreq lr, lr, r4, lsr r2
 *   @0xff7e8 eoreq r8, r3, r8, ror #8
 *   @0xff7ec .word 0x002384d4
 *   @0xff7f0 .word 0x002384d0
 *
 * ══ §27/94 F_DrawShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c038  size 324  81 条（0x11c038..0x11c17c）
 * @func 0x11c038 0x11c17c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / YYGetFloat(RValue const*, int)×6 / Sprite_Exists(int) / Error_Show_Action(char const*, bool) / Sprite_Data(int) / CSprite::DrawShape(int, int, int, float, float, float, float, float, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x20×2 / 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x110×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c038 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11c03c sub sp, sp, #52
 *   @0x11c040 mov r1, #0
 *   @0x11c044 ldr r4, [sp, #0x58]
 *   @0x11c048 mov r0, r4
 *   @0x11c04c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c050 mov r5, r0
 *   @0x11c054 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x11c058 subs r1, r0, #0
 *   @0x11c05c bne 0x11c06c <_Z11F_DrawShapeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x11c060 ldr r0, [pc, #0x110]
 *   @0x11c064 add r0, pc, r0
 *   @0x11c068 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11c06c mov r0, r5
 *   @0x11c070 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11c074 mov r1, #1
 *   @0x11c078 mov r5, r0
 *   @0x11c07c mov r0, r4
 *   @0x11c080 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c084 mov r1, #2
 *   @0x11c088 mov r8, r0
 *   @0x11c08c mov r0, r4
 *   @0x11c090 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c094 mov r1, #3
 *   @0x11c098 mov r6, r0
 *   @0x11c09c mov r0, r4
 *   @0x11c0a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c0a4 mov r1, #4
 *   @0x11c0a8 mov r3, r0
 *   @0x11c0ac mov r0, r4
 *   @0x11c0b0 str r3, [sp, #0x20]
 *   @0x11c0b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c0b8 mov r1, #5
 *   @0x11c0bc mov r12, r0
 *   @0x11c0c0 mov r0, r4
 *   @0x11c0c4 str r12, [sp, #0x24]
 *   @0x11c0c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c0cc mov r1, #6
 *   @0x11c0d0 mov r2, r0
 *   @0x11c0d4 mov r0, r4
 *   @0x11c0d8 str r2, [sp, #0x28]
 *   @0x11c0dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c0e0 mov r1, #7
 *   @0x11c0e4 str r0, [sp, #0x2c]
 *   @0x11c0e8 mov r0, r4
 *   @0x11c0ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c0f0 mov r1, #8
 *   @0x11c0f4 mov r11, r0
 *   @0x11c0f8 mov r0, r4
 *   @0x11c0fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c100 mov r1, #9
 *   @0x11c104 mov r10, r0
 *   @0x11c108 mov r0, r4
 *   @0x11c10c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c110 mov r1, #10
 *   @0x11c114 mov r9, r0
 *   @0x11c118 mov r0, r4
 *   @0x11c11c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c120 mov r1, #11
 *   @0x11c124 mov r7, r0
 *   @0x11c128 mov r0, r4
 *   @0x11c12c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c130 ldr r2, [sp, #0x28]
 *   @0x11c134 ldr r12, [sp, #0x24]
 *   @0x11c138 mov r1, r8
 *   @0x11c13c str r11, [sp, #0xc]
 *   @0x11c140 str r2, [sp, #0x4]
 *   @0x11c144 ldr r2, [sp, #0x2c]
 *   @0x11c148 str r12, [sp]
 *   @0x11c14c str r10, [sp, #0x10]
 *   @0x11c150 str r2, [sp, #0x8]
 *   @0x11c154 mov r2, r6
 *   @0x11c158 str r9, [sp, #0x14]
 *   @0x11c15c str r7, [sp, #0x18]
 *   @0x11c160 ldr r3, [sp, #0x20]
 *   @0x11c164 str r0, [sp, #0x1c]
 *   @0x11c168 mov r0, r5
 *   @0x11c16c bl 0x1ed768 <_ZN7CSprite9DrawShapeEiiifffffjjf>
 *   @0x11c170 add sp, sp, #52
 *   @0x11c174 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11c178 eoreq sp, r1, r0, asr pc
 *
 * ══ §28/94 F_TileAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c2fc  size 324  81 条（0x11c2fc..0x11c440）
 * @func 0x11c2fc 0x11c440  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / YYGetFloat(RValue const*, int)×3 / Background_Exists(int) / Error_Show_Action(char const*, bool) / CRoom::AddTile(RTile*) / F_TileAdd(RValue&, CInstance*, CInstance*, int, RValue*)+0x50
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x50×1 / 0xf0×1 / 0x8×1 / 0xcc×1 / 0x10×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c2fc push {r4, r5, r6, r7, lr}
 *   @0x11c300 sub sp, sp, #60
 *   @0x11c304 mov r5, r0
 *   @0x11c308 mov r1, #0
 *   @0x11c30c ldr r4, [sp, #0x50]
 *   @0x11c310 mov r6, r1
 *   @0x11c314 mov r0, r4
 *   @0x11c318 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c31c mov r3, r6
 *   @0x11c320 str r6, [r5, #0xc]
 *   @0x11c324 movt r3, #0xbff0
 *   @0x11c328 str r6, [r5]
 *   @0x11c32c str r3, [r5, #0x4]
 *   @0x11c330 mov r7, r0
 *   @0x11c334 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x11c338 subs r1, r0, #0
 *   @0x11c33c bne 0x11c354 <_Z9F_TileAddR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x11c340 ldr r0, [pc, #0xf0]
 *   @0x11c344 add r0, pc, r0
 *   @0x11c348 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11c34c add sp, sp, #60
 *   @0x11c350 pop {r4, r5, r6, r7, pc}
 *   @0x11c354 mov r1, #1
 *   @0x11c358 mov r0, r4
 *   @0x11c35c str r7, [sp, #0x8]
 *   @0x11c360 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c364 mov r1, #2
 *   @0x11c368 ldr r7, [pc, #0xcc]
 *   @0x11c36c str r0, [sp, #0xc]
 *   @0x11c370 mov r0, r4
 *   @0x11c374 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c378 mov r1, #3
 *   @0x11c37c str r0, [sp, #0x10]
 *   @0x11c380 mov r0, r4
 *   @0x11c384 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c388 mov r1, #4
 *   @0x11c38c str r0, [sp, #0x14]
 *   @0x11c390 mov r0, r4
 *   @0x11c394 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c398 mov r1, #5
 *   @0x11c39c str r0, [sp, #0x18]
 *   @0x11c3a0 mov r0, r4
 *   @0x11c3a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c3a8 mov r1, #6
 *   @0x11c3ac str r0, [sp]
 *   @0x11c3b0 mov r0, r4
 *   @0x11c3b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c3b8 mov r1, #7
 *   @0x11c3bc str r0, [sp, #0x4]
 *   @0x11c3c0 mov r0, r4
 *   @0x11c3c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c3c8 ldr r7, [pc, r7]
 *   @0x11c3cc mov r1, sp
 *   @0x11c3d0 mov r3, #1065353216
 *   @0x11c3d4 mvn r12, #-16777216
 *   @0x11c3d8 mov r2, #1
 *   @0x11c3dc str r12, [sp, #0x2c]
 *   @0x11c3e0 strb r2, [sp, #0x34]
 *   @0x11c3e4 str r3, [sp, #0x24]
 *   @0x11c3e8 str r3, [sp, #0x28]
 *   @0x11c3ec str r3, [sp, #0x30]
 *   @0x11c3f0 str r0, [sp, #0x1c]
 *   @0x11c3f4 ldr r0, [r7]
 *   @0x11c3f8 bl 0x1ac240 <_ZN5CRoom7AddTileEP5RTile>
 *   @0x11c3fc cmp r0, #0
 *   @0x11c400 blt 0x11c34c <_Z9F_TileAddR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x11c404 ldr r3, [r7]
 *   @0x11c408 ldr r2, [r3, #0xb8]
 *   @0x11c40c cmp r0, r2
 *   @0x11c410 rsblt r0, r0, r0, lsl #3
 *   @0x11c414 ldrlt r3, [r3, #0xc0]
 *   @0x11c418 addlt r6, r3, r0, lsl #3
 *   @0x11c41c ldr r2, [r6, #0x20]
 *   @0x11c420 vmov s15, r2
 *   @0x11c424 vcvt.f64.s32 d7, s15
 *   @0x11c428 vmov r2, r3, d7
 *   @0x11c42c stm r5, {r2, r3}
 *   @0x11c430 add sp, sp, #60
 *   @0x11c434 pop {r4, r5, r6, r7, pc}
 *   @0x11c438 mlaeq r1, r4, r12, sp
 *   @0x11c43c eoreq r1, sp, r0, ror #10
 *
 * ══ §29/94 F_DrawTextExtTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1222d0  size 324  81 条（0x1222d0..0x122414）
 * @func 0x1222d0 0x122414  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×6 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x44×2 / 0x2c×2 / 0x38×2 / 0x30×2 / 0x3c×2 / 0x34×2 / 0x70×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1222d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1222d4 sub sp, sp, #76
 *   @0x1222d8 add r2, sp, #72
 *   @0x1222dc mov r5, #0
 *   @0x1222e0 ldr r4, [sp, #0x70]
 *   @0x1222e4 mov r1, #1024
 *   @0x1222e8 str r5, [r2, #-0x4]!
 *   @0x1222ec add r0, r4, #32
 *   @0x1222f0 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x1222f4 mov r1, r5
 *   @0x1222f8 mov r0, r4
 *   @0x1222fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122300 mov r1, #1
 *   @0x122304 mov r5, r0
 *   @0x122308 mov r0, r4
 *   @0x12230c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122310 ldr r2, [sp, #0x44]
 *   @0x122314 mov r1, #3
 *   @0x122318 str r2, [sp, #0x2c]
 *   @0x12231c str r0, [sp, #0x38]
 *   @0x122320 mov r0, r4
 *   @0x122324 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122328 mov r1, #4
 *   @0x12232c mov r7, r0
 *   @0x122330 mov r0, r4
 *   @0x122334 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122338 mov r1, #5
 *   @0x12233c mov r12, r0
 *   @0x122340 mov r0, r4
 *   @0x122344 str r12, [sp, #0x30]
 *   @0x122348 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12234c mov r1, #6
 *   @0x122350 str r0, [sp, #0x3c]
 *   @0x122354 mov r0, r4
 *   @0x122358 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12235c mov r1, #7
 *   @0x122360 mov r3, r0
 *   @0x122364 mov r0, r4
 *   @0x122368 str r3, [sp, #0x34]
 *   @0x12236c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122370 mov r1, #8
 *   @0x122374 mov r11, r0
 *   @0x122378 mov r0, r4
 *   @0x12237c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122380 mov r1, #9
 *   @0x122384 mov r10, r0
 *   @0x122388 mov r0, r4
 *   @0x12238c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122390 mov r1, #10
 *   @0x122394 mov r9, r0
 *   @0x122398 mov r0, r4
 *   @0x12239c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1223a0 mov r1, #11
 *   @0x1223a4 mov r8, r0
 *   @0x1223a8 mov r0, r4
 *   @0x1223ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1223b0 mov r1, #12
 *   @0x1223b4 mov r6, r0
 *   @0x1223b8 mov r0, r4
 *   @0x1223bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1223c0 ldr r12, [sp, #0x30]
 *   @0x1223c4 ldr r1, [sp, #0x3c]
 *   @0x1223c8 ldr r3, [sp, #0x34]
 *   @0x1223cc str r12, [sp]
 *   @0x1223d0 str r1, [sp, #0x4]
 *   @0x1223d4 str r3, [sp, #0x8]
 *   @0x1223d8 mov r3, r7
 *   @0x1223dc ldr r2, [sp, #0x2c]
 *   @0x1223e0 ldr r1, [sp, #0x38]
 *   @0x1223e4 str r11, [sp, #0xc]
 *   @0x1223e8 str r10, [sp, #0x10]
 *   @0x1223ec str r9, [sp, #0x14]
 *   @0x1223f0 str r8, [sp, #0x18]
 *   @0x1223f4 str r6, [sp, #0x1c]
 *   @0x1223f8 str r0, [sp, #0x20]
 *   @0x1223fc mov r0, r5
 *   @0x122400 bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf>
 *   @0x122404 ldr r0, [sp, #0x44]
 *   @0x122408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x12240c add sp, sp, #76
 *   @0x122410 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §30/94 HttpRequestCallback(HTTP_REQ_CONTEXT*, void*, int*)  0x138ba0  size 324  79 条（0x138ba0..0x138ce4）
 * @func 0x138ba0 0x138ce4  size 324  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / CreateDsMap(int, ...)
 * 字段偏移 top8: 0x3c×4 / 0x34×2 / 0xf0×2 / 0x24×2 / 0x20×2 / 0xa4×2 / 0x118×1 / 0xd0×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138ba0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x138ba4 mov r4, r0
 *   @0x138ba8 ldr r1, [pc, #0x118]
 *   @0x138bac sub sp, sp, #92
 *   @0x138bb0 ldr r0, [r0, #0x3c]
 *   @0x138bb4 mov r3, #1
 *   @0x138bb8 mov r6, r2
 *   @0x138bbc add r1, pc, r1
 *   @0x138bc0 add r0, r0, r3
 *   @0x138bc4 movw r2, #0x8e2
 *   @0x138bc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x138bcc ldr r1, [r4, #0x34]
 *   @0x138bd0 ldr r2, [r4, #0x3c]
 *   @0x138bd4 ldr r8, [pc, #0xf0]
 *   @0x138bd8 ldr r7, [pc, #0xf0]
 *   @0x138bdc add r8, pc, r8
 *   @0x138be0 add r7, pc, r7
 *   @0x138be4 mov r5, r0
 *   @0x138be8 bl 0xb65bc <memcpy@plt>
 *   @0x138bec vmov.f64 d5, #-1.000000e+00
 *   @0x138bf0 ldr r2, [r4, #0x3c]
 *   @0x138bf4 mov r3, #0
 *   @0x138bf8 vldr d7, [pc, #192]
 *   @0x138bfc ldr lr, [pc, #0xd0]
 *   @0x138c00 mov r0, #6
 *   @0x138c04 strb r3, [r5, r2]
 *   @0x138c08 vldr s8, [r4, #40]
 *   @0x138c0c vstr d7, [sp, #8]
 *   @0x138c10 vldr s12, [r4, #44]
 *   @0x138c14 vstr d7, [sp, #24]
 *   @0x138c18 ldr r1, [r4, #0x3c]
 *   @0x138c1c ldr r2, [r4, #0x24]
 *   @0x138c20 add lr, pc, lr
 *   @0x138c24 cmp r1, r3
 *   @0x138c28 ldr r9, [r4, #0x20]
 *   @0x138c2c ldr r1, [pc, #0xa4]
 *   @0x138c30 ldr r12, [pc, #0xa4]
 *   @0x138c34 vmovle.f64 d7, d5
 *   @0x138c38 vstr d7, [sp, #72]
 *   @0x138c3c vmov s15, r2
 *   @0x138c40 add r1, pc, r1
 *   @0x138c44 str r1, [sp, #0x44]
 *   @0x138c48 add r12, pc, r12
 *   @0x138c4c ldr r1, [pc, #0x8c]
 *   @0x138c50 vcvt.f64.s32 d4, s8
 *   @0x138c54 str r3, [sp]
 *   @0x138c58 str r3, [sp, #0x30]
 *   @0x138c5c add r1, pc, r1
 *   @0x138c60 str r3, [sp, #0x40]
 *   @0x138c64 str r3, [sp, #0x50]
 *   @0x138c68 str lr, [sp, #0x24]
 *   @0x138c6c str r12, [sp, #0x34]
 *   @0x138c70 str r5, [sp, #0x20]
 *   @0x138c74 vcvt.f64.s32 d6, s12
 *   @0x138c78 vstr d4, [sp, #40]
 *   @0x138c7c str r9, [sp, #0x10]
 *   @0x138c80 str r8, [sp, #0x4]
 *   @0x138c84 str r7, [sp, #0x14]
 *   @0x138c88 vcvt.f64.s32 d7, s15
 *   @0x138c8c vstr d6, [sp, #56]
 *   @0x138c90 vmov r2, r3, d7
 *   @0x138c94 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x138c98 str r0, [r6]
 *   @0x138c9c mov r0, r5
 *   @0x138ca0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138ca4 ldr r0, [r4, #0x1c]
 *   @0x138ca8 cmp r0, #0
 *   @0x138cac beq 0x138cb4 <_Z19HttpRequestCallbackP16HTTP_REQ_CONTEXTPvPi+0x114>
 *   @0x138cb0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138cb4 mov r0, #62
 *   @0x138cb8 add sp, sp, #92
 *   @0x138cbc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x138cc8 mlaeq r0, r4, r4, r7
 *   @0x138ccc .word 0x002074f0
 *   @0x138cd0 andseq lr, pc, r8, ror r3
 *   @0x138cd4 andseq r7, pc, r4, lsr #28
 *   @0x138cd8 andseq r7, pc, r0, lsl lr
 *   @0x138cdc eoreq r7, r0, r8, lsl #9
 *   @0x138ce0 andseq r7, pc, r4, ror #27
 *
 * ══ §31/94 CloudFuncAsync(HTTP_REQ_CONTEXT*, void*, int*)  0x1567a4  size 324  81 条（0x1567a4..0x1568e8）
 * @func 0x1567a4 0x1568e8  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / CloudFuncAsync(HTTP_REQ_CONTEXT*, void*, int*)+0x120 / 0xb6538 / CreateDsMap(int, ...) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x3c×4 / 0x34×2 / 0x24×2 / 0x11c×1 / 0x1×1 / 0x28×1 / 0x9c×1 / 0x30×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1567a4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1567a8 mov r4, r0
 *   @0x1567ac ldr r1, [pc, #0x11c]
 *   @0x1567b0 mov r3, #1
 *   @0x1567b4 ldr r0, [r0, #0x3c]
 *   @0x1567b8 sub sp, sp, #72
 *   @0x1567bc add r1, pc, r1
 *   @0x1567c0 mov r7, r2
 *   @0x1567c4 add r0, r0, #2
 *   @0x1567c8 movw r2, #0x38a
 *   @0x1567cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1567d0 ldr r2, [r4, #0x3c]
 *   @0x1567d4 ldr r1, [r4, #0x34]
 *   @0x1567d8 mov r6, r0
 *   @0x1567dc bl 0xb65bc <memcpy@plt>
 *   @0x1567e0 ldr r2, [r4, #0x3c]
 *   @0x1567e4 mov r3, #0
 *   @0x1567e8 strb r3, [r6, r2]
 *   @0x1567ec ldr r2, [r4, #0x3c]
 *   @0x1567f0 add r2, r6, r2
 *   @0x1567f4 strb r3, [r2, #0x1]
 *   @0x1567f8 ldr r5, [r4, #0x28]
 *   @0x1567fc cmp r5, r3
 *   @0x156800 blt 0x1568c4 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x120>
 *   @0x156804 mov r0, r6
 *   @0x156808 movne r10, r3
 *   @0x15680c bne 0x156824 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x80>
 *   @0x156810 bl 0xb6538 <strlen@plt>
 *   @0x156814 mov r10, r5
 *   @0x156818 mov r3, r6
 *   @0x15681c add r0, r0, #1
 *   @0x156820 add r0, r6, r0
 *   @0x156824 ldr r2, [r4, #0x24]
 *   @0x156828 vmov s12, r5
 *   @0x15682c mov r1, #0
 *   @0x156830 ldr r9, [pc, #0x9c]
 *   @0x156834 vcvt.f64.s32 d7, s12
 *   @0x156838 str r1, [sp]
 *   @0x15683c vmov s13, r2
 *   @0x156840 str r1, [sp, #0x30]
 *   @0x156844 ldr r8, [pc, #0x8c]
 *   @0x156848 mov r4, #0
 *   @0x15684c ldr lr, [pc, #0x88]
 *   @0x156850 mov r5, #0
 *   @0x156854 ldr r12, [pc, #0x84]
 *   @0x156858 add r9, pc, r9
 *   @0x15685c ldr r1, [pc, #0x80]
 *   @0x156860 add lr, pc, lr
 *   @0x156864 add r12, pc, r12
 *   @0x156868 str r0, [sp, #0x20]
 *   @0x15686c vcvt.f64.s32 d6, s13
 *   @0x156870 str r3, [sp, #0x40]
 *   @0x156874 vstr d7, [sp, #40]
 *   @0x156878 str lr, [sp, #0x24]
 *   @0x15687c str r12, [sp, #0x34]
 *   @0x156880 add r1, pc, r1
 *   @0x156884 add r8, pc, r8
 *   @0x156888 strd r4, r5, [sp, #8]
 *   @0x15688c strd r4, r5, [sp, #24]
 *   @0x156890 mov r0, #5
 *   @0x156894 str r10, [sp, #0x10]
 *   @0x156898 strd r4, r5, [sp, #56]
 *   @0x15689c vmov r2, r3, d6
 *   @0x1568a0 str r9, [sp, #0x4]
 *   @0x1568a4 str r8, [sp, #0x14]
 *   @0x1568a8 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1568ac str r0, [r7]
 *   @0x1568b0 mov r0, r6
 *   @0x1568b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1568b8 mov r0, #67
 *   @0x1568bc add sp, sp, #72
 *   @0x1568c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1568c4 mov r10, r6
 *   @0x1568c8 mov r0, r3
 *   @0x1568cc b 0x156824 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x80>
 *   @0x1568d0 andseq pc, lr, r8, lsr #27
 *   @0x1568d4 andseq pc, lr, r8, asr #26
 *   @0x1568d8 andseq pc, lr, r8, lsr #26
 *   @0x1568dc ldrsheq r10, [sp], -r0
 *   @0x1568e0 andseq pc, lr, r8, asr sp
 *   @0x1568e4 andseq r10, sp, r0, asr #3
 *
 * ══ §32/94 F_CameraGetViewMat(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fd84  size 324  81 条（0x16fd84..0x16fec8）
 * @func 0x16fd84 0x16fedc  size 344  86 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / Error_Show(char const*, bool) / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewMat() / ARRAY_RefAlloc(void*)
 * 字段偏移 top8: 0x4×10 / 0xc×3 / 0xfc×1 / 0x58×1 / 0xdc×1 / 0xac×1 / 0x10×1 / 0x8c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fd84 cmp r3, #1
 *   @0x16fd88 mov r2, #0
 *   @0x16fd8c push {r4, r5, r6, r7, r8, lr}
 *   @0x16fd90 mov r6, r2
 *   @0x16fd94 sub sp, sp, #64
 *   @0x16fd98 movt r2, #0xbff0
 *   @0x16fd9c mov r7, r3
 *   @0x16fda0 mov r4, r0
 *   @0x16fda4 str r6, [r0, #0xc]
 *   @0x16fda8 str r2, [r0, #0x4]
 *   @0x16fdac str r6, [r0]
 *   @0x16fdb0 beq 0x16fdcc <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x16fdb4 ldr r0, [pc, #0xfc]
 *   @0x16fdb8 mov r1, r6
 *   @0x16fdbc add r0, pc, r0
 *   @0x16fdc0 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fdc4 add sp, sp, #64
 *   @0x16fdc8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16fdcc mov r1, r6
 *   @0x16fdd0 ldr r0, [sp, #0x58]
 *   @0x16fdd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fdd8 ldr r3, [pc, #0xdc]
 *   @0x16fddc mov r1, r0
 *   @0x16fde0 ldr r0, [pc, r3]
 *   @0x16fde4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fde8 subs r1, r0, #0
 *   @0x16fdec beq 0x16fdc4 <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x16fdf0 mov r0, sp
 *   @0x16fdf4 mov r5, sp
 *   @0x16fdf8 bl 0x16d170 <_ZN7CCamera10GetViewMatEv>
 *   @0x16fdfc mov r3, #2
 *   @0x16fe00 mov r0, r4
 *   @0x16fe04 str r3, [r4, #0xc]
 *   @0x16fe08 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x16fe0c ldr r1, [pc, #0xac]
 *   @0x16fe10 mov r3, r7
 *   @0x16fe14 mov r2, #70
 *   @0x16fe18 add r1, pc, r1
 *   @0x16fe1c mov r8, r0
 *   @0x16fe20 mov r0, #8
 *   @0x16fe24 str r8, [r4]
 *   @0x16fe28 str r7, [r8, #0x10]
 *   @0x16fe2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16fe30 ldr r1, [pc, #0x8c]
 *   @0x16fe34 mov r3, r7
 *   @0x16fe38 movw r2, #0x62d
 *   @0x16fe3c add r1, pc, r1
 *   @0x16fe40 str r0, [r8, #0x4]
 *   @0x16fe44 mov r0, #256
 *   @0x16fe48 ldr r12, [r4]
 *   @0x16fe4c ldr r7, [r12, #0x4]
 *   @0x16fe50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16fe54 mov r3, #16
 *   @0x16fe58 mov r1, r6
 *   @0x16fe5c str r0, [r7, #0x4]
 *   @0x16fe60 ldr r2, [r4]
 *   @0x16fe64 ldr r0, [r2, #0x4]
 *   @0x16fe68 str r3, [r0]
 *   @0x16fe6c ldr r12, [r4]
 *   @0x16fe70 b 0x16fe7c <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x16fe74 ldr r12, [r4]
 *   @0x16fe78 ldr r0, [r12, #0x4]
 *   @0x16fe7c vldmia r5!, {s15}
 *   @0x16fe80 vcvt.f64.f32 d6, s15
 *   @0x16fe84 ldr r12, [r12, #0x4]
 *   @0x16fe88 ldr r0, [r0, #0x4]
 *   @0x16fe8c ldr r12, [r12, #0x4]
 *   @0x16fe90 add r0, r0, r1
 *   @0x16fe94 str r6, [r0, #0xc]
 *   @0x16fe98 vmov r2, r3, d6
 *   @0x16fe9c str r2, [r12, r1]!
 *   @0x16fea0 add r1, r1, #16
 *   @0x16fea4 cmp r1, #256
 *   @0x16fea8 str r3, [r12, #0x4]
 *   @0x16feac bne 0x16fe74 <_Z18F_CameraGetViewMatR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x16feb0 add sp, sp, #64
 *   @0x16feb4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16feb8 mulseq sp, r4, r2
 *   @0x16febc mlaeq r7, r4, lr, sp
 *   @0x16fec0 andseq r1, r12, r8, lsl r2
 *   @0x16fec4 andseq r10, sp, r12, lsl r10
 *
 * ══ §33/94 F_CameraGetProjMat(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fec8  size 324  81 条（0x16fec8..0x17000c）
 * @func 0x16fec8 0x17000c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / Error_Show(char const*, bool) / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetProjMat() / ARRAY_RefAlloc(void*)
 * 字段偏移 top8: 0x4×10 / 0xc×3 / 0xfc×1 / 0x58×1 / 0xdc×1 / 0xac×1 / 0x10×1 / 0x8c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fec8 cmp r3, #1
 *   @0x16fecc mov r2, #0
 *   @0x16fed0 push {r4, r5, r6, r7, r8, lr}
 *   @0x16fed4 mov r6, r2
 *   @0x16fed8 sub sp, sp, #64
 *   @0x16fedc movt r2, #0xbff0
 *   @0x16fee0 mov r7, r3
 *   @0x16fee4 mov r4, r0
 *   @0x16fee8 str r6, [r0, #0xc]
 *   @0x16feec str r2, [r0, #0x4]
 *   @0x16fef0 str r6, [r0]
 *   @0x16fef4 beq 0x16ff10 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x16fef8 ldr r0, [pc, #0xfc]
 *   @0x16fefc mov r1, r6
 *   @0x16ff00 add r0, pc, r0
 *   @0x16ff04 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16ff08 add sp, sp, #64
 *   @0x16ff0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x16ff10 mov r1, r6
 *   @0x16ff14 ldr r0, [sp, #0x58]
 *   @0x16ff18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16ff1c ldr r3, [pc, #0xdc]
 *   @0x16ff20 mov r1, r0
 *   @0x16ff24 ldr r0, [pc, r3]
 *   @0x16ff28 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16ff2c subs r1, r0, #0
 *   @0x16ff30 beq 0x16ff08 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x16ff34 mov r0, sp
 *   @0x16ff38 mov r5, sp
 *   @0x16ff3c bl 0x16d134 <_ZN7CCamera10GetProjMatEv>
 *   @0x16ff40 mov r3, #2
 *   @0x16ff44 mov r0, r4
 *   @0x16ff48 str r3, [r4, #0xc]
 *   @0x16ff4c bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x16ff50 ldr r1, [pc, #0xac]
 *   @0x16ff54 mov r3, r7
 *   @0x16ff58 mov r2, #70
 *   @0x16ff5c add r1, pc, r1
 *   @0x16ff60 mov r8, r0
 *   @0x16ff64 mov r0, #8
 *   @0x16ff68 str r8, [r4]
 *   @0x16ff6c str r7, [r8, #0x10]
 *   @0x16ff70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16ff74 ldr r1, [pc, #0x8c]
 *   @0x16ff78 mov r3, r7
 *   @0x16ff7c movw r2, #0x64c
 *   @0x16ff80 add r1, pc, r1
 *   @0x16ff84 str r0, [r8, #0x4]
 *   @0x16ff88 mov r0, #256
 *   @0x16ff8c ldr r12, [r4]
 *   @0x16ff90 ldr r7, [r12, #0x4]
 *   @0x16ff94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16ff98 mov r3, #16
 *   @0x16ff9c mov r1, r6
 *   @0x16ffa0 str r0, [r7, #0x4]
 *   @0x16ffa4 ldr r2, [r4]
 *   @0x16ffa8 ldr r0, [r2, #0x4]
 *   @0x16ffac str r3, [r0]
 *   @0x16ffb0 ldr r12, [r4]
 *   @0x16ffb4 b 0x16ffc0 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x16ffb8 ldr r12, [r4]
 *   @0x16ffbc ldr r0, [r12, #0x4]
 *   @0x16ffc0 vldmia r5!, {s15}
 *   @0x16ffc4 vcvt.f64.f32 d6, s15
 *   @0x16ffc8 ldr r12, [r12, #0x4]
 *   @0x16ffcc ldr r0, [r0, #0x4]
 *   @0x16ffd0 ldr r12, [r12, #0x4]
 *   @0x16ffd4 add r0, r0, r1
 *   @0x16ffd8 str r6, [r0, #0xc]
 *   @0x16ffdc vmov r2, r3, d6
 *   @0x16ffe0 str r2, [r12, r1]!
 *   @0x16ffe4 add r1, r1, #16
 *   @0x16ffe8 cmp r1, #256
 *   @0x16ffec str r3, [r12, #0x4]
 *   @0x16fff0 bne 0x16ffb8 <_Z18F_CameraGetProjMatR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x16fff4 add sp, sp, #64
 *   @0x16fff8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16fffc andseq r11, sp, r4, lsl #3
 *   @0x170000 eoreq sp, r7, r0, asr sp
 *   @0x170004 ldrsbeq r1, [r12], -r4
 *   @0x170008 ldrsbeq r10, [sp], -r8
 *
 * ══ §34/94 F_LayerSpriteCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c7058  size 324  81 条（0x1c7058..0x1c719c）
 * @func 0x1c7058 0x1c719c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetNewSpriteElement() / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x18×1 / 0x100×1 / 0x1c×1 / 0x40×1 / 0x80×1 / 0x44×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c7058 cmp r3, #4
 *   @0x1c705c mov r3, #0
 *   @0x1c7060 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c7064 mov r5, r3
 *   @0x1c7068 mov r4, r0
 *   @0x1c706c movt r3, #0xbff0
 *   @0x1c7070 str r5, [r0, #0xc]
 *   @0x1c7074 str r3, [r0, #0x4]
 *   @0x1c7078 str r5, [r0]
 *   @0x1c707c ldr r6, [sp, #0x18]
 *   @0x1c7080 beq 0x1c7098 <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c7084 ldr r0, [pc, #0x100]
 *   @0x1c7088 mov r1, r5
 *   @0x1c708c pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c7090 add r0, pc, r0
 *   @0x1c7094 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c7098 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c709c ldr r3, [r6, #0xc]
 *   @0x1c70a0 mov r1, r5
 *   @0x1c70a4 bic r3, r3, #-16777216
 *   @0x1c70a8 cmp r3, #1
 *   @0x1c70ac mov r8, r0
 *   @0x1c70b0 mov r0, r6
 *   @0x1c70b4 beq 0x1c714c <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1c70b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c70bc mov r1, r0
 *   @0x1c70c0 mov r0, r8
 *   @0x1c70c4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c70c8 mov r7, r0
 *   @0x1c70cc cmp r7, #0
 *   @0x1c70d0 beq 0x1c7164 <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x1c70d4 bl 0x1c0f00 <_ZN13CLayerManager19GetNewSpriteElementEv>
 *   @0x1c70d8 mov r1, #3
 *   @0x1c70dc mov r5, r0
 *   @0x1c70e0 mov r0, r6
 *   @0x1c70e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c70e8 mov r1, #1
 *   @0x1c70ec str r0, [r5, #0x1c]
 *   @0x1c70f0 mov r0, r6
 *   @0x1c70f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c70f8 mov r1, #2
 *   @0x1c70fc str r0, [r5, #0x40]
 *   @0x1c7100 mov r0, r6
 *   @0x1c7104 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c7108 ldr r3, [pc, #0x80]
 *   @0x1c710c mov r2, r5
 *   @0x1c7110 mov r1, r7
 *   @0x1c7114 ldr r3, [pc, r3]
 *   @0x1c7118 ldr r3, [r3]
 *   @0x1c711c subs r12, r3, r8
 *   @0x1c7120 rsbs r3, r12, #0
 *   @0x1c7124 adcs r3, r3, r12
 *   @0x1c7128 str r0, [r5, #0x44]
 *   @0x1c712c mov r0, r8
 *   @0x1c7130 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c7134 ldr r2, [r5, #0x4]
 *   @0x1c7138 vmov s15, r2
 *   @0x1c713c vcvt.f64.s32 d7, s15
 *   @0x1c7140 vmov r2, r3, d7
 *   @0x1c7144 stm r4, {r2, r3}
 *   @0x1c7148 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c714c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c7150 mov r1, r0
 *   @0x1c7154 mov r0, r8
 *   @0x1c7158 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c715c mov r7, r0
 *   @0x1c7160 b 0x1c70cc <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c7164 ldr r3, [pc, #0x28]
 *   @0x1c7168 mov r2, r7
 *   @0x1c716c ldr r1, [pc, #0x24]
 *   @0x1c7170 ldr r3, [pc, r3]
 *   @0x1c7174 add r1, pc, r1
 *   @0x1c7178 ldr r0, [r3]
 *   @0x1c717c ldr r3, [r0]
 *   @0x1c7180 ldr r3, [r3, #0xc]
 *   @0x1c7184 blx r3
 *   @0x1c7188 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c718c andseq r9, r8, r0, asr #18
 *   @0x1c7190 eoreq r6, r2, r4, lsl r8
 *   @0x1c7194 eoreq r6, r2, r4, lsr #11
 *   @0x1c7198 mulseq r8, r0, r8
 *
 * ══ §35/94 CStream::CopyFrom(CStream*, long long, bool)  0x2015c8  size 324  81 条（0x2015c8..0x20170c）
 * @func 0x2015c8 0x20170c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::GetPosition()×5 / CStream::GetSize()×4 / CStream::GetMemory()×3 / CStream::SetPosition(int)×3 / CStream::Write(void*, int)×2 / CStream::CopyFrom(CStream*, long long, bool)+0x128
 * 字段偏移 top8: 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2015c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2015cc mov r5, r3
 *   @0x2015d0 ldrb r3, [sp, #0x20]
 *   @0x2015d4 mov r4, r2
 *   @0x2015d8 orrs r2, r4, r5
 *   @0x2015dc mov r7, r0
 *   @0x2015e0 mov r6, r1
 *   @0x2015e4 strb r3, [r0]
 *   @0x2015e8 mov r0, r1
 *   @0x2015ec beq 0x2016a0 <_ZN7CStream8CopyFromEPS_xb+0xd8>
 *   @0x2015f0 cmp r3, #0
 *   @0x2015f4 mov r8, r4
 *   @0x2015f8 bne 0x201674 <_ZN7CStream8CopyFromEPS_xb+0xac>
 *   @0x2015fc bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x201600 mov r8, r0
 *   @0x201604 mov r0, r6
 *   @0x201608 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x20160c add r8, r8, r0
 *   @0x201610 mov r0, r6
 *   @0x201614 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x201618 mov r9, r0
 *   @0x20161c mov r0, r6
 *   @0x201620 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x201624 rsb r0, r0, r9
 *   @0x201628 asr r3, r0, #31
 *   @0x20162c mov r2, r0
 *   @0x201630 cmp r2, r4
 *   @0x201634 sbcs r1, r3, r5
 *   @0x201638 movge r9, r4
 *   @0x20163c blt 0x2016f0 <_ZN7CStream8CopyFromEPS_xb+0x128>
 *   @0x201640 mov r1, r8
 *   @0x201644 mov r0, r7
 *   @0x201648 mov r2, r9
 *   @0x20164c bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x201650 mov r8, r0
 *   @0x201654 mov r0, r6
 *   @0x201658 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x20165c add r1, r9, r0
 *   @0x201660 mov r0, r6
 *   @0x201664 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x201668 mov r0, r8
 *   @0x20166c asr r1, r8, #31
 *   @0x201670 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x201674 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x201678 mov r5, #0
 *   @0x20167c mov r9, r4
 *   @0x201680 mov r10, r0
 *   @0x201684 mov r0, r6
 *   @0x201688 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x20168c strd r4, r5, [r7, #8]
 *   @0x201690 strd r4, r5, [r7, #16]
 *   @0x201694 add r0, r10, r0
 *   @0x201698 str r0, [r7, #0x18]
 *   @0x20169c b 0x201654 <_ZN7CStream8CopyFromEPS_xb+0x8c>
 *   @0x2016a0 mov r1, #0
 *   @0x2016a4 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x2016a8 mov r0, r6
 *   @0x2016ac bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x2016b0 mov r4, r0
 *   @0x2016b4 mov r0, r6
 *   @0x2016b8 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x2016bc mov r1, r4
 *   @0x2016c0 mov r2, r0
 *   @0x2016c4 mov r0, r7
 *   @0x2016c8 bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x2016cc mov r4, r0
 *   @0x2016d0 mov r0, r6
 *   @0x2016d4 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x2016d8 mov r1, r0
 *   @0x2016dc mov r0, r6
 *   @0x2016e0 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x2016e4 mov r0, r4
 *   @0x2016e8 asr r1, r4, #31
 *   @0x2016ec pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2016f0 mov r0, r6
 *   @0x2016f4 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x2016f8 mov r9, r0
 *   @0x2016fc mov r0, r6
 *   @0x201700 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x201704 rsb r9, r0, r9
 *   @0x201708 b 0x201640 <_ZN7CStream8CopyFromEPS_xb+0x78>
 *
 * ══ §36/94 CDS_List::Sort(bool)  0x20321c  size 324  81 条（0x20321c..0x203360）
 * @func 0x20321c 0x203360  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::Sort(bool)+0x130 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0xc×10 / 0x4×8 / 0x14×4 / 0x8×4 / 0x10×2 / 0x18×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20321c ldr r2, [r0, #0x4]
 *   @0x203220 mov r3, #0
 *   @0x203224 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x203228 cmp r2, #1
 *   @0x20322c sub sp, sp, #44
 *   @0x203230 mov r11, r0
 *   @0x203234 str r1, [sp, #0x10]
 *   @0x203238 str r3, [sp, #0x18]
 *   @0x20323c str r3, [sp, #0x1c]
 *   @0x203240 str r3, [sp, #0x20]
 *   @0x203244 str r3, [sp, #0x24]
 *   @0x203248 ble 0x20334c <_ZN8CDS_List4SortEb+0x130>
 *   @0x20324c mov r8, #1
 *   @0x203250 str r8, [sp, #0x14]
 *   @0x203254 add r8, sp, #24
 *   @0x203258 ldr r4, [pc, #0xfc]
 *   @0x20325c mov r7, r8
 *   @0x203260 ldr r4, [pc, r4]
 *   @0x203264 str r4, [sp, #0xc]
 *   @0x203268 ldr r4, [sp, #0x14]
 *   @0x20326c mov r9, r7
 *   @0x203270 lsl r10, r4, #4
 *   @0x203274 str r4, [sp]
 *   @0x203278 b 0x2032f8 <_ZN8CDS_List4SortEb+0xdc>
 *   @0x20327c ldr r8, [sp]
 *   @0x203280 subs r8, r8, #1
 *   @0x203284 str r8, [sp]
 *   @0x203288 ldr r8, [r11, #0xc]
 *   @0x20328c add r6, r8, r10
 *   @0x203290 add r12, r8, r5
 *   @0x203294 ldr r8, [r6]
 *   @0x203298 ldr r1, [r12, #0x4]
 *   @0x20329c ldr r2, [r12, #0x8]
 *   @0x2032a0 ldr r3, [r12, #0xc]
 *   @0x2032a4 ldr r0, [r12]
 *   @0x2032a8 str r8, [sp, #0x4]
 *   @0x2032ac ldr r8, [r6, #0x4]
 *   @0x2032b0 stm r7!, {r0, r1, r2, r3}
 *   @0x2032b4 ldr r7, [r6, #0x8]
 *   @0x2032b8 ldr r2, [r11, #0xc]
 *   @0x2032bc ldr r6, [r6, #0xc]
 *   @0x2032c0 ldr r0, [sp, #0x4]
 *   @0x2032c4 str r0, [r2, r5]
 *   @0x2032c8 ldm r4!, {r0, r1, r2, r3}
 *   @0x2032cc str r8, [r12, #0x4]
 *   @0x2032d0 str r7, [r12, #0x8]
 *   @0x2032d4 str r6, [r12, #0xc]
 *   @0x2032d8 ldr r4, [r11, #0xc]
 *   @0x2032dc add r12, r4, r10
 *   @0x2032e0 str r0, [r4, r10]
 *   @0x2032e4 mov r10, r5
 *   @0x2032e8 str r1, [r12, #0x4]
 *   @0x2032ec str r2, [r12, #0x8]
 *   @0x2032f0 str r3, [r12, #0xc]
 *   @0x2032f4 beq 0x203354 <_ZN8CDS_List4SortEb+0x138>
 *   @0x2032f8 ldr r4, [sp, #0xc]
 *   @0x2032fc sub r5, r10, #16
 *   @0x203300 ldr r1, [r11, #0xc]
 *   @0x203304 mov r7, r9
 *   @0x203308 ldrd r2, r3, [r4]
 *   @0x20330c add r0, r1, r5
 *   @0x203310 add r1, r1, r10
 *   @0x203314 mov r4, r9
 *   @0x203318 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20331c ldr r8, [sp, #0x10]
 *   @0x203320 cmp r0, #0
 *   @0x203324 movle r0, #0
 *   @0x203328 movgt r0, #1
 *   @0x20332c cmp r0, r8
 *   @0x203330 beq 0x20327c <_ZN8CDS_List4SortEb+0x60>
 *   @0x203334 ldr r4, [sp, #0x14]
 *   @0x203338 ldr r3, [r11, #0x4]
 *   @0x20333c add r4, r4, #1
 *   @0x203340 str r4, [sp, #0x14]
 *   @0x203344 cmp r3, r4
 *   @0x203348 bgt 0x203268 <_ZN8CDS_List4SortEb+0x4c>
 *   @0x20334c add sp, sp, #44
 *   @0x203350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x203354 mov r7, r9
 *   @0x203358 b 0x203334 <_ZN8CDS_List4SortEb+0x118>
 *   @0x20335c andseq lr, lr, r4, lsr #2
 *
 * ══ §37/94 Audio_GetRecorderInfo(int)  0x21c5bc  size 324  81 条（0x21c5bc..0x21c700）
 * @func 0x21c5bc 0x21c700  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21c5d4→0x7552fc, 0x21c6a0→0x3eb70c, 0x21c6cc→0x3eb70c
 * 调用序列: Audio_GetRecorderInfo(int)+0x108 / CreateDsMap(int, ...)
 * 字段偏移 top8: 0x4×2 / 0xcc×2 / 0x30×2 / 0x24×2 / 0x110×1 / 0x100×1 / 0x2×1 / 0xd0×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c5bc subs r12, r0, #0
 *   @0x21c5c0 ldr r3, [pc, #0x110]
 *   @0x21c5c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21c5c8 add r3, pc, r3
 *   @0x21c5cc sub sp, sp, #72
 *   @0x21c5d0 blt 0x21c6c4 <_Z21Audio_GetRecorderInfoi+0x108>
 *   @0x21c5d4 ldr r2, [pc, #0x100]
 *   @0x21c5d8 ldr r2, [r3, r2]
 *   @0x21c5dc ldr r1, [r2]
 *   @0x21c5e0 cmp r12, r1
 *   @0x21c5e4 bgt 0x21c6c4 <_Z21Audio_GetRecorderInfoi+0x108>
 *   @0x21c5e8 bge 0x21c698 <_Z21Audio_GetRecorderInfoi+0xdc>
 *   @0x21c5ec ldr r2, [r2, #0x4]
 *   @0x21c5f0 ldr r2, [r2, r12, lsl #2]
 *   @0x21c5f4 cmp r2, #0
 *   @0x21c5f8 beq 0x21c698 <_Z21Audio_GetRecorderInfoi+0xdc>
 *   @0x21c5fc vmov s13, r12
 *   @0x21c600 ldr r10, [r2]
 *   @0x21c604 mov r1, #0
 *   @0x21c608 ldr r0, [pc, #0xd0]
 *   @0x21c60c vcvt.f64.s32 d7, s13
 *   @0x21c610 ldr r9, [pc, #0xcc]
 *   @0x21c614 ldr r8, [pc, #0xcc]
 *   @0x21c618 add r0, pc, r0
 *   @0x21c61c ldr lr, [pc, #0xc8]
 *   @0x21c620 mov r4, #0
 *   @0x21c624 str r1, [sp, #0x10]
 *   @0x21c628 mov r5, #0
 *   @0x21c62c str r1, [sp, #0x20]
 *   @0x21c630 movt r5, #0x4010
 *   @0x21c634 str r1, [sp, #0x30]
 *   @0x21c638 mov r2, #0
 *   @0x21c63c str r1, [sp, #0x40]
 *   @0x21c640 mov r3, #0
 *   @0x21c644 ldr r1, [pc, #0xa4]
 *   @0x21c648 add r9, pc, r9
 *   @0x21c64c add r8, pc, r8
 *   @0x21c650 add lr, pc, lr
 *   @0x21c654 mov r6, #0
 *   @0x21c658 mov r7, #16384
 *   @0x21c65c str r0, [sp, #0x4]
 *   @0x21c660 movt r7, #0x40cf
 *   @0x21c664 strd r2, r3, [sp, #56]
 *   @0x21c668 mov r0, #5
 *   @0x21c66c str r10, [sp]
 *   @0x21c670 add r1, pc, r1
 *   @0x21c674 strd r6, r7, [sp, #40]
 *   @0x21c678 vstr d7, [sp, #8]
 *   @0x21c67c str r9, [sp, #0x14]
 *   @0x21c680 str r8, [sp, #0x24]
 *   @0x21c684 str lr, [sp, #0x34]
 *   @0x21c688 strd r4, r5, [sp, #24]
 *   @0x21c68c bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x21c690 add sp, sp, #72
 *   @0x21c694 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21c698 ldr r1, [pc, #0x54]
 *   @0x21c69c mov r2, r12
 *   @0x21c6a0 ldr r0, [pc, #0x50]
 *   @0x21c6a4 add r1, pc, r1
 *   @0x21c6a8 ldr r3, [r3, r0]
 *   @0x21c6ac ldr r0, [r3]
 *   @0x21c6b0 ldr r3, [r0]
 *   @0x21c6b4 ldr r3, [r3, #0xc]
 *   @0x21c6b8 blx r3
 *   @0x21c6bc mvn r0, #0
 *   @0x21c6c0 b 0x21c690 <_Z21Audio_GetRecorderInfoi+0xd4>
 *   @0x21c6c4 ldr r1, [pc, #0x30]
 *   @0x21c6c8 mov r2, r12
 *   @0x21c6cc ldr r0, [pc, #0x24]
 *   @0x21c6d0 add r1, pc, r1
 *   @0x21c6d4 b 0x21c6a8 <_Z21Audio_GetRecorderInfoi+0xec>
 *   @0x21c6d8 andseq r5, sp, r8, lsl #13
 *   @0x21c6dc .word 0xfffff7a8
 *   @0x21c6e0 ldrsheq r9, [r2], -r0
 *   @0x21c6e4 andseq r7, r3, r12, lsl r12
 *   @0x21c6e8 andseq r7, r3, r4, lsr #24
 *   @0x21c6ec andseq r7, r3, r12, lsr #24
 *   @0x21c6f0 mulseq r1, r8, r1
 *   @0x21c6f4 andseq r7, r3, r8, lsl #23
 *   @0x21c6f8 .word 0xffffbac4
 *   @0x21c6fc andseq r7, r3, r8, lsr #22
 *
 * ══ §38/94 CPhysicsWorld::CreatePrismaticJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, bool, float, float, bool, bool)  0x239164  size 324  81 条（0x239164..0x2392a8）
 * @func 0x239164 0x2392a8  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PrismaticJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x28×2 / 0x48×2 / 0x54×2 / 0x58×2 / 0x5c×2 / 0x94×1 / 0x98×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239164 vmov s15, r3
 *   @0x239168 ldr r1, [r1]
 *   @0x23916c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x239170 vpush {d8}
 *   @0x239174 mov r4, r0
 *   @0x239178 vldr s14, [r4, #96]
 *   @0x23917c sub sp, sp, #100
 *   @0x239180 vmul.f32 s15, s14, s15
 *   @0x239184 vldr s13, [sp, #144]
 *   @0x239188 ldrh r3, [r1, #4]
 *   @0x23918c ldr r2, [r2]
 *   @0x239190 add r5, sp, #24
 *   @0x239194 tst r3, #2
 *   @0x239198 ldr lr, [sp, #0x94]
 *   @0x23919c orreq r3, r3, #2
 *   @0x2391a0 strheq r3, [r1, #4]
 *   @0x2391a4 ldrh r3, [r2, #4]
 *   @0x2391a8 moveq r0, #0
 *   @0x2391ac ldr r12, [sp, #0x98]
 *   @0x2391b0 vldr s17, [sp, #156]
 *   @0x2391b4 streq r0, [r1, #0xa0]
 *   @0x2391b8 tst r3, #2
 *   @0x2391bc orreq r3, r3, #2
 *   @0x2391c0 strheq r3, [r2, #4]
 *   @0x2391c4 moveq r0, #0
 *   @0x2391c8 add r3, sp, #16
 *   @0x2391cc streq r0, [r2, #0xa0]
 *   @0x2391d0 mov r0, r5
 *   @0x2391d4 str r3, [sp]
 *   @0x2391d8 add r3, sp, #8
 *   @0x2391dc vmul.f32 s14, s14, s13
 *   @0x2391e0 vstr s15, [sp, #8]
 *   @0x2391e4 vldr s16, [sp, #160]
 *   @0x2391e8 ldrb r8, [sp, #0xa4]
 *   @0x2391ec ldr r11, [sp, #0xa8]
 *   @0x2391f0 mov r9, #2
 *   @0x2391f4 ldr r10, [sp, #0xac]
 *   @0x2391f8 ldrb r7, [sp, #0xb0]
 *   @0x2391fc ldrb r6, [sp, #0xb4]
 *   @0x239200 str lr, [sp, #0x10]
 *   @0x239204 mov lr, #0
 *   @0x239208 str r12, [sp, #0x14]
 *   @0x23920c mov r12, #0
 *   @0x239210 str lr, [sp, #0x1c]
 *   @0x239214 str lr, [sp, #0x20]
 *   @0x239218 str lr, [sp, #0x24]
 *   @0x23921c strb lr, [sp, #0x28]
 *   @0x239220 strb lr, [sp, #0x48]
 *   @0x239224 strb lr, [sp, #0x54]
 *   @0x239228 str r12, [sp, #0x2c]
 *   @0x23922c str r9, [sp, #0x18]
 *   @0x239230 str r12, [sp, #0x30]
 *   @0x239234 vstr s14, [sp, #12]
 *   @0x239238 str r12, [sp, #0x34]
 *   @0x23923c str r12, [sp, #0x38]
 *   @0x239240 str r12, [sp, #0x40]
 *   @0x239244 str r12, [sp, #0x44]
 *   @0x239248 str r12, [sp, #0x4c]
 *   @0x23924c str r12, [sp, #0x50]
 *   @0x239250 str r12, [sp, #0x58]
 *   @0x239254 str r12, [sp, #0x5c]
 *   @0x239258 mov r12, #1065353216
 *   @0x23925c str r12, [sp, #0x3c]
 *   @0x239260 bl 0x2cff74 <_ZN19b2PrismaticJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_>
 *   @0x239264 vldr s15, [r4, #96]
 *   @0x239268 vmul.f32 s17, s15, s17
 *   @0x23926c mov r0, r4
 *   @0x239270 mov r1, r5
 *   @0x239274 strb r8, [sp, #0x48]
 *   @0x239278 str r11, [sp, #0x58]
 *   @0x23927c str r10, [sp, #0x5c]
 *   @0x239280 strb r7, [sp, #0x54]
 *   @0x239284 strb r6, [sp, #0x28]
 *   @0x239288 vmul.f32 s15, s15, s16
 *   @0x23928c vstr s17, [sp, #76]
 *   @0x239290 vstr s15, [sp, #80]
 *   @0x239294 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239298 ldr r0, [r0, #0x8]
 *   @0x23929c add sp, sp, #100
 *   @0x2392a0 vpop {d8}
 *   @0x2392a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §39/94 b2World::CreateJoint(b2JointDef const*)  0x2c90f8  size 324  81 条（0x2c90f8..0x2c923c）
 * @func 0x2c90f8 0x2c923c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::Create(b2JointDef const*, b2BlockAllocator*)
 * 字段偏移 top8: 0x7c×4 / 0xc×3 / 0x8×2 / 0x10×2 / 0x128×1 / 0x118×1 / 0x30×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c90f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2c90fc movw r6, #0x91d4
 *   @0x2c9100 movt r6, #0x1
 *   @0x2c9104 ldr r3, [pc, #0x128]
 *   @0x2c9108 mov r4, r0
 *   @0x2c910c mov r5, r1
 *   @0x2c9110 ldr r0, [r0, r6]
 *   @0x2c9114 ldr r3, [pc, r3]
 *   @0x2c9118 ldr r1, [pc, #0x118]
 *   @0x2c911c eor r0, r0, #2
 *   @0x2c9120 ldr r3, [r3]
 *   @0x2c9124 add r1, pc, r1
 *   @0x2c9128 ubfx r0, r0, #0x1, #0x1
 *   @0x2c912c blx r3
 *   @0x2c9130 ldr r3, [r4, r6]
 *   @0x2c9134 ands r6, r3, #2
 *   @0x2c9138 bne 0x2c922c <_ZN7b2World11CreateJointEPK10b2JointDef+0x134>
 *   @0x2c913c mov r1, r4
 *   @0x2c9140 mov r0, r5
 *   @0x2c9144 bl 0x2cdbc0 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator>
 *   @0x2c9148 movw r1, #0x922c
 *   @0x2c914c movt r1, #0x1
 *   @0x2c9150 mov r7, #0
 *   @0x2c9154 ldr r3, [r4, r1]
 *   @0x2c9158 cmp r3, #0
 *   @0x2c915c ldr r1, [r0, #0x30]
 *   @0x2c9160 mov r2, r0
 *   @0x2c9164 str r6, [r0, #0x8]
 *   @0x2c9168 movw r6, #0x922c
 *   @0x2c916c str r3, [r0, #0xc]
 *   @0x2c9170 movt r6, #0x1
 *   @0x2c9174 strne r0, [r3, #0x8]
 *   @0x2c9178 movw r0, #0x9234
 *   @0x2c917c movt r0, #0x1
 *   @0x2c9180 ldr r12, [r1, #0x7c]
 *   @0x2c9184 ldr r3, [r2, #0x34]
 *   @0x2c9188 ldr r8, [r4, r0]
 *   @0x2c918c cmp r12, r7
 *   @0x2c9190 str r2, [r4, r6]
 *   @0x2c9194 add r6, r8, #1
 *   @0x2c9198 str r6, [r4, r0]
 *   @0x2c919c str r12, [r2, #0x1c]
 *   @0x2c91a0 add r0, r2, #16
 *   @0x2c91a4 str r3, [r2, #0x10]
 *   @0x2c91a8 str r2, [r2, #0x14]
 *   @0x2c91ac str r7, [r2, #0x18]
 *   @0x2c91b0 strne r0, [r12, #0x8]
 *   @0x2c91b4 mov r12, #0
 *   @0x2c91b8 str r0, [r1, #0x7c]
 *   @0x2c91bc ldr r0, [r3, #0x7c]
 *   @0x2c91c0 str r1, [r2, #0x20]
 *   @0x2c91c4 add r1, r2, #32
 *   @0x2c91c8 cmp r0, r12
 *   @0x2c91cc str r12, [r2, #0x28]
 *   @0x2c91d0 str r0, [r2, #0x2c]
 *   @0x2c91d4 str r2, [r2, #0x24]
 *   @0x2c91d8 strne r1, [r0, #0x8]
 *   @0x2c91dc ldrb r0, [r5, #0x10]
 *   @0x2c91e0 ldr r12, [r5, #0x8]
 *   @0x2c91e4 cmp r0, #0
 *   @0x2c91e8 str r1, [r3, #0x7c]
 *   @0x2c91ec ldr r3, [r5, #0xc]
 *   @0x2c91f0 bne 0x2c9224 <_ZN7b2World11CreateJointEPK10b2JointDef+0x12c>
 *   @0x2c91f4 ldr r3, [r3, #0x80]
 *   @0x2c91f8 cmp r3, #0
 *   @0x2c91fc beq 0x2c9224 <_ZN7b2World11CreateJointEPK10b2JointDef+0x12c>
 *   @0x2c9200 ldr r1, [r3]
 *   @0x2c9204 cmp r1, r12
 *   @0x2c9208 ldreq r1, [r3, #0x4]
 *   @0x2c920c ldr r3, [r3, #0xc]
 *   @0x2c9210 ldreq r0, [r1, #0x4]
 *   @0x2c9214 orreq r0, r0, #8
 *   @0x2c9218 streq r0, [r1, #0x4]
 *   @0x2c921c cmp r3, #0
 *   @0x2c9220 bne 0x2c9200 <_ZN7b2World11CreateJointEPK10b2JointDef+0x108>
 *   @0x2c9224 mov r0, r2
 *   @0x2c9228 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c922c mov r0, #0
 *   @0x2c9230 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c9234 ldrheq r8, [r2], -r4
 *   @0x2c9238 strheq r4, [r9], -r0
 *
 * ══ §40/94 b2PrismaticJoint::b2PrismaticJoint(b2PrismaticJointDef const*)  0x2d0028  size 324  81 条（0x2d0028..0x2d016c）
 * @func 0x2d0028 0x2d016c  size 324  81 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*) / 0xb6700
 * 字段偏移 top8: 0x44×2 / 0x124×1 / 0x2c×1 / 0x30×1 / 0x3c×1 / 0x34×1 / 0x64×1 / 0x38×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0028 push {r4, r5, r6, lr}
 *   @0x2d002c mov r4, r0
 *   @0x2d0030 mov r5, r1
 *   @0x2d0034 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d0038 add r3, r5, #20
 *   @0x2d003c ldr r2, [pc, #0x124]
 *   @0x2d0040 add r6, r5, #28
 *   @0x2d0044 add r12, r4, #76
 *   @0x2d0048 ldm r3, {r0, r1}
 *   @0x2d004c ldr r2, [pc, r2]
 *   @0x2d0050 mov r3, r4
 *   @0x2d0054 add r2, r2, #8
 *   @0x2d0058 str r2, [r3], #68
 *   @0x2d005c add r2, r5, #36
 *   @0x2d0060 stm r3, {r0, r1}
 *   @0x2d0064 add r3, r4, #84
 *   @0x2d0068 ldm r6, {r0, r1}
 *   @0x2d006c stm r12, {r0, r1}
 *   @0x2d0070 ldm r2, {r0, r1}
 *   @0x2d0074 stm r3, {r0, r1}
 *   @0x2d0078 vldr s14, [r4, #88]
 *   @0x2d007c vmul.f32 s14, s14, s14
 *   @0x2d0080 vldr s15, [r4, #84]
 *   @0x2d0084 vmla.f32 s14, s15, s15
 *   @0x2d0088 vsqrt.f32 s15, s14
 *   @0x2d008c vcmp.f32 s15, s15
 *   @0x2d0090 vmrs APSR_nzcv, fpscr
 *   @0x2d0094 bne 0x2d0154 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x12c>
 *   @0x2d0098 vldr s14, [pc, #196]
 *   @0x2d009c vcmpe.f32 s15, s14
 *   @0x2d00a0 vmrs APSR_nzcv, fpscr
 *   @0x2d00a4 bmi 0x2d0148 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x120>
 *   @0x2d00a8 vmov.f32 s12, #1.000000e+00
 *   @0x2d00ac vldr s13, [r4, #88]
 *   @0x2d00b0 vldr s14, [r4, #84]
 *   @0x2d00b4 vdiv.f32 s15, s12, s15
 *   @0x2d00b8 vmul.f32 s13, s15, s13
 *   @0x2d00bc vmul.f32 s14, s15, s14
 *   @0x2d00c0 vstr s13, [r4, #88]
 *   @0x2d00c4 vmov.f32 s15, s13
 *   @0x2d00c8 vstr s14, [r4, #84]
 *   @0x2d00cc ldr r0, [r5, #0x2c]
 *   @0x2d00d0 ldrb r1, [r5, #0x30]
 *   @0x2d00d4 ldrb r2, [r5, #0x3c]
 *   @0x2d00d8 vneg.f32 s15, s15
 *   @0x2d00dc ldr r3, [r5, #0x34]
 *   @0x2d00e0 vstr s14, [r4, #96]
 *   @0x2d00e4 str r0, [r4, #0x64]
 *   @0x2d00e8 ldr r0, [r5, #0x38]
 *   @0x2d00ec str r3, [r4, #0x78]
 *   @0x2d00f0 vstr s15, [r4, #92]
 *   @0x2d00f4 ldr r3, [r5, #0x40]
 *   @0x2d00f8 str r0, [r4, #0x7c]
 *   @0x2d00fc ldr r0, [r5, #0x44]
 *   @0x2d0100 str r3, [r4, #0x80]
 *   @0x2d0104 mov r3, #0
 *   @0x2d0108 strb r1, [r4, #0x88]
 *   @0x2d010c str r0, [r4, #0x84]
 *   @0x2d0110 mov r0, r4
 *   @0x2d0114 str r3, [r4, #0x68]
 *   @0x2d0118 str r3, [r4, #0x6c]
 *   @0x2d011c str r3, [r4, #0x70]
 *   @0x2d0120 str r3, [r4, #0xfc]
 *   @0x2d0124 str r3, [r4, #0x74]
 *   @0x2d0128 str r3, [r4, #0xb8]
 *   @0x2d012c str r3, [r4, #0xbc]
 *   @0x2d0130 str r3, [r4, #0xc0]
 *   @0x2d0134 str r3, [r4, #0xc4]
 *   @0x2d0138 mov r3, #0
 *   @0x2d013c strb r2, [r4, #0x89]
 *   @0x2d0140 str r3, [r4, #0x8c]
 *   @0x2d0144 pop {r4, r5, r6, pc}
 *   @0x2d0148 vldr s15, [r4, #88]
 *   @0x2d014c vldr s14, [r4, #84]
 *   @0x2d0150 b 0x2d00cc <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0xa4>
 *   @0x2d0154 vmov r0, s14
 *   @0x2d0158 bl 0xb6700 <sqrtf@plt>
 *   @0x2d015c vmov s15, r0
 *   @0x2d0160 b 0x2d0098 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef+0x70>
 *   @0x2d0164 strlo r0, [r0], #-0
 *   @0x2d0168 andseq r1, r2, r12, lsl r11
 *
 * ══ §41/94 EncodeDSMap(CDS_Map*)  0x13bcec  size 320  80 条（0x13bcec..0x13be2c）
 * @func 0x13bcec 0x13be2c  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_new_object / _itoa(int, char*, int) / EncodeValue(RValue*) / json_object_object_add / EncodeDSMap(CDS_Map*)+0xe4 / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x84×2 / 0xc×2 / 0x12c×1 / 0x3×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13bcec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13bcf0 sub sp, sp, #140
 *   @0x13bcf4 ldr r10, [pc, #0x12c]
 *   @0x13bcf8 mov r4, r0
 *   @0x13bcfc mov r7, #0
 *   @0x13bd00 ldr r10, [pc, r10]
 *   @0x13bd04 ldr r3, [r10]
 *   @0x13bd08 str r3, [sp, #0x84]
 *   @0x13bd0c bl 0x27e89c <json_object_new_object>
 *   @0x13bd10 ldr r4, [r4]
 *   @0x13bd14 ldr r2, [r4]
 *   @0x13bd18 mov r8, r0
 *   @0x13bd1c b 0x13bd30 <_Z11EncodeDSMapP7CDS_Map+0x44>
 *   @0x13bd20 ldr r3, [r4, #0x4]
 *   @0x13bd24 add r7, r7, #1
 *   @0x13bd28 cmp r7, r3
 *   @0x13bd2c bgt 0x13be1c <_Z11EncodeDSMapP7CDS_Map+0x130>
 *   @0x13bd30 ldr r6, [r2, r7, lsl #3]
 *   @0x13bd34 cmp r6, #0
 *   @0x13bd38 beq 0x13bd20 <_Z11EncodeDSMapP7CDS_Map+0x34>
 *   @0x13bd3c add r9, sp, #4
 *   @0x13bd40 cmp r6, #0
 *   @0x13bd44 beq 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104>
 *   @0x13bd48 ldr r0, [r6, #0xc]
 *   @0x13bd4c cmp r0, #0
 *   @0x13bd50 beq 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104>
 *   @0x13bd54 ldr r2, [r0, #0xc]
 *   @0x13bd58 add r5, r0, #16
 *   @0x13bd5c bic r1, r2, #-16777216
 *   @0x13bd60 cmp r1, #1
 *   @0x13bd64 beq 0x13be0c <_Z11EncodeDSMapP7CDS_Map+0x120>
 *   @0x13bd68 cmp r2, #0
 *   @0x13bd6c movne r11, #0
 *   @0x13bd70 bne 0x13bd94 <_Z11EncodeDSMapP7CDS_Map+0xa8>
 *   @0x13bd74 vldr s14, [r0]
 *   @0x13bd78 vldr s15, [r0, #4]
 *   @0x13bd7c vcvt.s32.f64 s13, d7
 *   @0x13bd80 mov r1, r9
 *   @0x13bd84 mov r2, #10
 *   @0x13bd88 mov r11, r9
 *   @0x13bd8c vmov r0, s13
 *   @0x13bd90 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x13bd94 mov r0, r5
 *   @0x13bd98 bl 0x13be2c <_Z11EncodeValueP6RValue>
 *   @0x13bd9c mov r1, r11
 *   @0x13bda0 mov r2, r0
 *   @0x13bda4 mov r0, r8
 *   @0x13bda8 bl 0x27ea00 <json_object_object_add>
 *   @0x13bdac ldr r6, [r6, #0x4]
 *   @0x13bdb0 cmp r6, #0
 *   @0x13bdb4 bne 0x13bd40 <_Z11EncodeDSMapP7CDS_Map+0x54>
 *   @0x13bdb8 ldr r1, [r4, #0x4]
 *   @0x13bdbc add r3, r7, #1
 *   @0x13bdc0 cmp r3, r1
 *   @0x13bdc4 bgt 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104>
 *   @0x13bdc8 ldr r2, [r4]
 *   @0x13bdcc add r2, r2, r7, lsl #3
 *   @0x13bdd0 ldr r6, [r2, #0x8]
 *   @0x13bdd4 mov r7, r3
 *   @0x13bdd8 cmp r6, #0
 *   @0x13bddc bne 0x13bd40 <_Z11EncodeDSMapP7CDS_Map+0x54>
 *   @0x13bde0 add r3, r3, #1
 *   @0x13bde4 add r2, r2, #8
 *   @0x13bde8 cmp r3, r1
 *   @0x13bdec ble 0x13bdd0 <_Z11EncodeDSMapP7CDS_Map+0xe4>
 *   @0x13bdf0 ldr r2, [sp, #0x84]
 *   @0x13bdf4 mov r0, r8
 *   @0x13bdf8 ldr r3, [r10]
 *   @0x13bdfc cmp r2, r3
 *   @0x13be00 bne 0x13be24 <_Z11EncodeDSMapP7CDS_Map+0x138>
 *   @0x13be04 add sp, sp, #140
 *   @0x13be08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13be0c ldr r11, [r0]
 *   @0x13be10 cmp r11, #0
 *   @0x13be14 ldrne r11, [r11]
 *   @0x13be18 b 0x13bd94 <_Z11EncodeDSMapP7CDS_Map+0xa8>
 *   @0x13be1c mvn r7, #0
 *   @0x13be20 b 0x13bd3c <_Z11EncodeDSMapP7CDS_Map+0x50>
 *   @0x13be24 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13be28 eoreq r1, r11, r0, asr r12
 *
 * ══ §42/94 YYGML_action_create_object(CInstance*, int, float, float)  0x14172c  size 320  80 条（0x14172c..0x14186c）
 * @func 0x14172c 0x14186c  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x141770→0x47a174, 0x141784→0x54298c, 0x1417fc→0x54298c
 * 调用序列: CRoom::AddInstance(float, float, int)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / Object_Exists(int) / 0xb65c8 / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x118×1 / 0x114×1 / 0xe8×1 / 0xd8×1 / 0x6c×1 / 0x60×1 / 0x38×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14172c push {r4, r5, r6, r7, r8, lr}
 *   @0x141730 vpush {d8}
 *   @0x141734 mov r6, r1
 *   @0x141738 ldr r4, [pc, #0x118]
 *   @0x14173c vmov s16, r3
 *   @0x141740 ldr r1, [pc, #0x114]
 *   @0x141744 sub sp, sp, #264
 *   @0x141748 add r4, pc, r4
 *   @0x14174c mov r7, r0
 *   @0x141750 mov r0, r6
 *   @0x141754 vmov s17, r2
 *   @0x141758 ldr r5, [r4, r1]
 *   @0x14175c ldr r3, [r5]
 *   @0x141760 str r3, [sp, #0x104]
 *   @0x141764 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x141768 subs r8, r0, #0
 *   @0x14176c beq 0x141824 <_Z26YYGML_action_create_objectP9CInstanceiff+0xf8>
 *   @0x141770 ldr r3, [pc, #0xe8]
 *   @0x141774 ldr r3, [r4, r3]
 *   @0x141778 ldrb r3, [r3]
 *   @0x14177c cmp r3, #0
 *   @0x141780 bne 0x1417f0 <_Z26YYGML_action_create_objectP9CInstanceiff+0xc4>
 *   @0x141784 ldr r0, [pc, #0xd8]
 *   @0x141788 mov r3, r6
 *   @0x14178c vmov r1, s17
 *   @0x141790 vmov r2, s16
 *   @0x141794 ldr r0, [r4, r0]
 *   @0x141798 ldr r0, [r0]
 *   @0x14179c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x1417a0 mov r4, r0
 *   @0x1417a4 mov r0, r4
 *   @0x1417a8 mov r1, r4
 *   @0x1417ac mov r2, #14
 *   @0x1417b0 mov r3, #0
 *   @0x1417b4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1417b8 mov r2, #0
 *   @0x1417bc mov r3, r2
 *   @0x1417c0 mov r0, r4
 *   @0x1417c4 mov r1, r4
 *   @0x1417c8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1417cc mov r3, #1
 *   @0x1417d0 strb r3, [r4, #0x6c]
 *   @0x1417d4 ldr r2, [sp, #0x104]
 *   @0x1417d8 ldr r3, [r5]
 *   @0x1417dc cmp r2, r3
 *   @0x1417e0 bne 0x141854 <_Z26YYGML_action_create_objectP9CInstanceiff+0x128>
 *   @0x1417e4 add sp, sp, #264
 *   @0x1417e8 vpop {d8}
 *   @0x1417ec pop {r4, r5, r6, r7, r8, pc}
 *   @0x1417f0 vldr s14, [r7, #180]
 *   @0x1417f4 vldr s15, [r7, #184]
 *   @0x1417f8 vadd.f32 s14, s17, s14
 *   @0x1417fc ldr r2, [pc, #0x60]
 *   @0x141800 mov r3, r6
 *   @0x141804 ldr r2, [r4, r2]
 *   @0x141808 ldr r0, [r2]
 *   @0x14180c vadd.f32 s15, s16, s15
 *   @0x141810 vmov r1, s14
 *   @0x141814 vmov r2, s15
 *   @0x141818 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi>
 *   @0x14181c mov r4, r0
 *   @0x141820 b 0x1417a4 <_Z26YYGML_action_create_objectP9CInstanceiff+0x78>
 *   @0x141824 add r4, sp, #264
 *   @0x141828 ldr r2, [pc, #0x38]
 *   @0x14182c mov r3, r6
 *   @0x141830 mov r1, #256
 *   @0x141834 strb r8, [r4, #-0x104]!
 *   @0x141838 add r2, pc, r2
 *   @0x14183c mov r0, r4
 *   @0x141840 bl 0xb65c8 <snprintf@plt>
 *   @0x141844 mov r0, r4
 *   @0x141848 mov r1, r8
 *   @0x14184c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x141850 b 0x1417d4 <_Z26YYGML_action_create_objectP9CInstanceiff+0xa8>
 *   @0x141854 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x141858 eoreq r0, r11, r8, lsl #10
 *   @0x14185c .word 0xffffbd00
 *   @0x141860 .word 0xffffbeec
 *   @0x141864 .word 0xffffbcd8
 *   @0x141868 ldrsheq pc, [pc], -r4
 *
 * ══ §43/94 F_D3DBuildMatrixProjOrtho(RValue&, CInstance*, CInstance*, int, RValue*)  0x144c88  size 320  80 条（0x144c88..0x144dc8）
 * @func 0x144c88 0x144dc8  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x108×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144c88 push {r4, r5, r6, r7, r8, lr}
 *   @0x144c8c vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x144c90 sub sp, sp, #184
 *   @0x144c94 mov r5, r0
 *   @0x144c98 mov r1, #0
 *   @0x144c9c ldr r4, [sp, #0x108]
 *   @0x144ca0 mov r0, r4
 *   @0x144ca4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144ca8 mov r1, #1
 *   @0x144cac mov r8, r0
 *   @0x144cb0 mov r0, r4
 *   @0x144cb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144cb8 mov r1, #2
 *   @0x144cbc mov r7, r0
 *   @0x144cc0 mov r0, r4
 *   @0x144cc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144cc8 mov r1, #3
 *   @0x144ccc mov r6, r0
 *   @0x144cd0 mov r0, r4
 *   @0x144cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144cd8 mov r1, r8
 *   @0x144cdc mov r2, r7
 *   @0x144ce0 mov r3, r6
 *   @0x144ce4 str r0, [sp]
 *   @0x144ce8 add r0, sp, #120
 *   @0x144cec bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x144cf0 vldr s14, [sp, #124]
 *   @0x144cf4 vcvt.f64.f32 d7, s14
 *   @0x144cf8 vldr s26, [sp, #128]
 *   @0x144cfc vldr s24, [sp, #132]
 *   @0x144d00 vldr s22, [sp, #136]
 *   @0x144d04 vldr s20, [sp, #140]
 *   @0x144d08 vldr s18, [sp, #144]
 *   @0x144d0c vldr s16, [sp, #148]
 *   @0x144d10 vldr s0, [sp, #152]
 *   @0x144d14 vldr s2, [sp, #156]
 *   @0x144d18 vldr s4, [sp, #160]
 *   @0x144d1c vldr s6, [sp, #164]
 *   @0x144d20 vldr s8, [sp, #168]
 *   @0x144d24 vldr s10, [sp, #172]
 *   @0x144d28 vldr s12, [sp, #176]
 *   @0x144d2c vstr d7, [sp]
 *   @0x144d30 vldr s14, [sp, #180]
 *   @0x144d34 vcvt.f64.f32 d7, s14
 *   @0x144d38 vldr s28, [sp, #120]
 *   @0x144d3c mov r0, r5
 *   @0x144d40 mov r1, #16
 *   @0x144d44 vcvt.f64.f32 d0, s0
 *   @0x144d48 vstr d7, [sp, #112]
 *   @0x144d4c vcvt.f64.f32 d1, s2
 *   @0x144d50 vstr d0, [sp, #56]
 *   @0x144d54 vcvt.f64.f32 d2, s4
 *   @0x144d58 vstr d1, [sp, #64]
 *   @0x144d5c vcvt.f64.f32 d3, s6
 *   @0x144d60 vstr d2, [sp, #72]
 *   @0x144d64 vcvt.f64.f32 d4, s8
 *   @0x144d68 vstr d3, [sp, #80]
 *   @0x144d6c vcvt.f64.f32 d5, s10
 *   @0x144d70 vstr d4, [sp, #88]
 *   @0x144d74 vcvt.f64.f32 d6, s12
 *   @0x144d78 vstr d5, [sp, #96]
 *   @0x144d7c vcvt.f64.f32 d7, s28
 *   @0x144d80 vstr d6, [sp, #104]
 *   @0x144d84 vcvt.f64.f32 d13, s26
 *   @0x144d88 vmov r2, r3, d7
 *   @0x144d8c vcvt.f64.f32 d12, s24
 *   @0x144d90 vstr d13, [sp, #8]
 *   @0x144d94 vcvt.f64.f32 d11, s22
 *   @0x144d98 vstr d12, [sp, #16]
 *   @0x144d9c vcvt.f64.f32 d10, s20
 *   @0x144da0 vstr d11, [sp, #24]
 *   @0x144da4 vcvt.f64.f32 d9, s18
 *   @0x144da8 vstr d10, [sp, #32]
 *   @0x144dac vcvt.f64.f32 d8, s16
 *   @0x144db0 vstr d9, [sp, #40]
 *   @0x144db4 vstr d8, [sp, #48]
 *   @0x144db8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x144dbc add sp, sp, #184
 *   @0x144dc0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x144dc4 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §44/94 ReadLn(CStream*, char const*&)  0x163dbc  size 320  80 条（0x163dbc..0x163efc）
 * @func 0x163dbc 0x163efc  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::GetPosition()×4 / CStream::Read(void*, int)×3 / CStream::GetSize()×2 / ReadLn(CStream*, char const*&)+0x114 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CStream::SetPosition(int) / YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x7×2 / 0x-1×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163dbc push {r4, r5, r6, r7, r8, lr}
 *   @0x163dc0 sub sp, sp, #8
 *   @0x163dc4 add r8, sp, #8
 *   @0x163dc8 mov r4, r0
 *   @0x163dcc mov r7, r1
 *   @0x163dd0 mov r3, #0
 *   @0x163dd4 strb r3, [r8, #-0x1]!
 *   @0x163dd8 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x163ddc mov r1, r8
 *   @0x163de0 mov r2, #1
 *   @0x163de4 mov r6, r0
 *   @0x163de8 mov r0, r4
 *   @0x163dec bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x163df0 ldrb r3, [sp, #0x7]
 *   @0x163df4 mov r0, r4
 *   @0x163df8 cmp r3, #13
 *   @0x163dfc cmpne r3, #10
 *   @0x163e00 beq 0x163ed8 <_Z6ReadLnP7CStreamRPKc+0x11c>
 *   @0x163e04 cmp r3, #0
 *   @0x163e08 beq 0x163ed8 <_Z6ReadLnP7CStreamRPKc+0x11c>
 *   @0x163e0c mov r0, r4
 *   @0x163e10 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x163e14 mov r5, r0
 *   @0x163e18 mov r0, r4
 *   @0x163e1c bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x163e20 mov r1, r8
 *   @0x163e24 mov r2, #1
 *   @0x163e28 cmp r5, r0
 *   @0x163e2c mov r0, r4
 *   @0x163e30 bge 0x163e50 <_Z6ReadLnP7CStreamRPKc+0x94>
 *   @0x163e34 bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x163e38 ldrb r3, [sp, #0x7]
 *   @0x163e3c cmp r3, #10
 *   @0x163e40 cmpne r3, #13
 *   @0x163e44 beq 0x163e50 <_Z6ReadLnP7CStreamRPKc+0x94>
 *   @0x163e48 cmp r3, #0
 *   @0x163e4c bne 0x163e0c <_Z6ReadLnP7CStreamRPKc+0x50>
 *   @0x163e50 mov r0, r4
 *   @0x163e54 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x163e58 rsb r0, r6, r0
 *   @0x163e5c sub r5, r0, #1
 *   @0x163e60 cmp r5, #0
 *   @0x163e64 movle r3, #0
 *   @0x163e68 strle r3, [r7]
 *   @0x163e6c ble 0x163ed0 <_Z6ReadLnP7CStreamRPKc+0x114>
 *   @0x163e70 ldr r1, [pc, #0x80]
 *   @0x163e74 mov r2, #108
 *   @0x163e78 mov r3, #1
 *   @0x163e7c add r1, pc, r1
 *   @0x163e80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x163e84 mov r1, r6
 *   @0x163e88 mov r8, r0
 *   @0x163e8c mov r0, r4
 *   @0x163e90 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x163e94 mov r0, r4
 *   @0x163e98 mov r1, r8
 *   @0x163e9c mov r2, r5
 *   @0x163ea0 bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x163ea4 ldr r0, [r7]
 *   @0x163ea8 cmp r0, #0
 *   @0x163eac beq 0x163eb4 <_Z6ReadLnP7CStreamRPKc+0xf8>
 *   @0x163eb0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x163eb4 mov r0, r8
 *   @0x163eb8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x163ebc cmp r8, #0
 *   @0x163ec0 str r0, [r7]
 *   @0x163ec4 beq 0x163ed0 <_Z6ReadLnP7CStreamRPKc+0x114>
 *   @0x163ec8 mov r0, r8
 *   @0x163ecc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x163ed0 add sp, sp, #8
 *   @0x163ed4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x163ed8 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x163edc mov r5, r0
 *   @0x163ee0 mov r0, r4
 *   @0x163ee4 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x163ee8 cmp r5, r0
 *   @0x163eec mov r0, r4
 *   @0x163ef0 blt 0x163dd8 <_Z6ReadLnP7CStreamRPKc+0x1c>
 *   @0x163ef4 b 0x163e38 <_Z6ReadLnP7CStreamRPKc+0x7c>
 *   @0x163ef8 mulseq lr, r8, r6
 *
 * ══ §45/94 GR_Text_Width(char const*, int, int)  0x172bc8  size 320  80 条（0x172bc8..0x172d08）
 * @func 0x172bc8 0x172d08  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::TextWidth(unsigned short*)×2 / MemoryManager::Free(void const*)×2 / SetFont() / Split_TextBlock(char const*, int, TStringList*) / GR_Text_Width(char const*, int, int)+0x134 / GR_Text_Width(char const*, int, int)+0xcc
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0xc×2 / 0xf0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172bc8 push {r4, r5, r6, lr}
 *   @0x172bcc sub sp, sp, #16
 *   @0x172bd0 mov r5, r2
 *   @0x172bd4 mov r6, r0
 *   @0x172bd8 mov r4, #0
 *   @0x172bdc str r4, [sp, #0x4]
 *   @0x172be0 str r4, [sp]
 *   @0x172be4 str r4, [sp, #0xc]
 *   @0x172be8 str r4, [sp, #0x8]
 *   @0x172bec bl 0x1724e4 <_Z7SetFontv>
 *   @0x172bf0 mov r0, r6
 *   @0x172bf4 mov r1, r5
 *   @0x172bf8 mov r2, sp
 *   @0x172bfc bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList>
 *   @0x172c00 ldr r3, [sp, #0x8]
 *   @0x172c04 cmp r3, r4
 *   @0x172c08 ble 0x172cfc <_Z13GR_Text_WidthPKcii+0x134>
 *   @0x172c0c ldr r5, [pc, #0xf0]
 *   @0x172c10 mov r6, r4
 *   @0x172c14 ldr r5, [pc, r5]
 *   @0x172c18 ldr r1, [sp]
 *   @0x172c1c ldr r0, [r5]
 *   @0x172c20 cmp r1, #0
 *   @0x172c24 beq 0x172c4c <_Z13GR_Text_WidthPKcii+0x84>
 *   @0x172c28 cmp r4, #0
 *   @0x172c2c movne r3, r4
 *   @0x172c30 bne 0x172c40 <_Z13GR_Text_WidthPKcii+0x78>
 *   @0x172c34 b 0x172cec <_Z13GR_Text_WidthPKcii+0x124>
 *   @0x172c38 subs r3, r3, #1
 *   @0x172c3c beq 0x172cec <_Z13GR_Text_WidthPKcii+0x124>
 *   @0x172c40 ldr r1, [r1]
 *   @0x172c44 cmp r1, #0
 *   @0x172c48 bne 0x172c38 <_Z13GR_Text_WidthPKcii+0x70>
 *   @0x172c4c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x172c50 cmp r0, r6
 *   @0x172c54 blt 0x172c94 <_Z13GR_Text_WidthPKcii+0xcc>
 *   @0x172c58 ldr r1, [sp]
 *   @0x172c5c ldr r0, [r5]
 *   @0x172c60 cmp r1, #0
 *   @0x172c64 beq 0x172c8c <_Z13GR_Text_WidthPKcii+0xc4>
 *   @0x172c68 cmp r4, #0
 *   @0x172c6c movne r3, r4
 *   @0x172c70 bne 0x172c80 <_Z13GR_Text_WidthPKcii+0xb8>
 *   @0x172c74 b 0x172cf4 <_Z13GR_Text_WidthPKcii+0x12c>
 *   @0x172c78 subs r3, r3, #1
 *   @0x172c7c beq 0x172cf4 <_Z13GR_Text_WidthPKcii+0x12c>
 *   @0x172c80 ldr r1, [r1]
 *   @0x172c84 cmp r1, #0
 *   @0x172c88 bne 0x172c78 <_Z13GR_Text_WidthPKcii+0xb0>
 *   @0x172c8c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x172c90 mov r6, r0
 *   @0x172c94 ldr r3, [sp, #0x8]
 *   @0x172c98 add r4, r4, #1
 *   @0x172c9c cmp r3, r4
 *   @0x172ca0 bgt 0x172c18 <_Z13GR_Text_WidthPKcii+0x50>
 *   @0x172ca4 ldr r0, [sp]
 *   @0x172ca8 cmp r0, #0
 *   @0x172cac beq 0x172cc4 <_Z13GR_Text_WidthPKcii+0xfc>
 *   @0x172cb0 ldr r4, [r0]
 *   @0x172cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172cb8 cmp r4, #0
 *   @0x172cbc mov r0, r4
 *   @0x172cc0 bne 0x172cb0 <_Z13GR_Text_WidthPKcii+0xe8>
 *   @0x172cc4 ldr r0, [sp, #0xc]
 *   @0x172cc8 mov r3, #0
 *   @0x172ccc str r3, [sp, #0x8]
 *   @0x172cd0 cmp r0, r3
 *   @0x172cd4 str r3, [sp]
 *   @0x172cd8 beq 0x172ce0 <_Z13GR_Text_WidthPKcii+0x118>
 *   @0x172cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172ce0 mov r0, r6
 *   @0x172ce4 add sp, sp, #16
 *   @0x172ce8 pop {r4, r5, r6, pc}
 *   @0x172cec ldr r1, [r1, #0x4]
 *   @0x172cf0 b 0x172c4c <_Z13GR_Text_WidthPKcii+0x84>
 *   @0x172cf4 ldr r1, [r1, #0x4]
 *   @0x172cf8 b 0x172c8c <_Z13GR_Text_WidthPKcii+0xc4>
 *   @0x172cfc mov r6, r4
 *   @0x172d00 b 0x172ca4 <_Z13GR_Text_WidthPKcii+0xdc>
 *   @0x172d04 mlaeq r7, r0, r6, sp
 *
 * ══ §46/94 ParticleSystem_Layer(int, int)  0x1a4660  size 320  80 条（0x1a4660..0x1a47a0）
 * @func 0x1a4660 0x1a47a0  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::RemoveElement(CRoom*, int, bool, bool)×2 / ParticleSystem_Exists(int) / CLayerManager::GetNewParticleElement() / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::AddNewElementAtDepth(CRoom*, int, CLayerElementBase*, bool, bool) / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool)
 * 字段偏移 top8: 0x4×6 / 0x2×5 / 0x2c×5 / 0x110×1 / 0xf8×1 / 0xf4×1 / 0x1c×1 / 0x30×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4660 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a4664 sub sp, sp, #12
 *   @0x1a4668 mov r5, r1
 *   @0x1a466c mov r4, r0
 *   @0x1a4670 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a4674 cmp r0, #0
 *   @0x1a4678 beq 0x1a4690 <_Z20ParticleSystem_Layerii+0x30>
 *   @0x1a467c ldr r3, [pc, #0x110]
 *   @0x1a4680 ldr r3, [pc, r3]
 *   @0x1a4684 ldrb r3, [r3]
 *   @0x1a4688 cmp r3, #0
 *   @0x1a468c bne 0x1a4698 <_Z20ParticleSystem_Layerii+0x38>
 *   @0x1a4690 add sp, sp, #12
 *   @0x1a4694 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a4698 ldr r6, [pc, #0xf8]
 *   @0x1a469c mov r2, #1
 *   @0x1a46a0 ldr r7, [pc, #0xf4]
 *   @0x1a46a4 mov r3, #0
 *   @0x1a46a8 ldr r6, [pc, r6]
 *   @0x1a46ac ldr r7, [pc, r7]
 *   @0x1a46b0 ldr r1, [r6, #0x4]
 *   @0x1a46b4 ldr r0, [r7]
 *   @0x1a46b8 ldr r1, [r1, r4, lsl #2]
 *   @0x1a46bc ldr r1, [r1, #0x2c]
 *   @0x1a46c0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a46c4 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv>
 *   @0x1a46c8 ldr r3, [r6, #0x4]
 *   @0x1a46cc ldr r3, [r3, r4, lsl #2]
 *   @0x1a46d0 str r4, [r0, #0x1c]
 *   @0x1a46d4 mov r8, r0
 *   @0x1a46d8 str r5, [r3, #0x30]
 *   @0x1a46dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1a46e0 subs r9, r0, #0
 *   @0x1a46e4 beq 0x1a4690 <_Z20ParticleSystem_Layerii+0x30>
 *   @0x1a46e8 mov r1, r5
 *   @0x1a46ec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1a46f0 cmp r0, #0
 *   @0x1a46f4 beq 0x1a4704 <_Z20ParticleSystem_Layerii+0xa4>
 *   @0x1a46f8 ldr r3, [r7]
 *   @0x1a46fc cmp r9, r3
 *   @0x1a4700 beq 0x1a4744 <_Z20ParticleSystem_Layerii+0xe4>
 *   @0x1a4704 ldr r3, [r6, #0x4]
 *   @0x1a4708 ldr r4, [r3, r4, lsl #2]
 *   @0x1a470c ldr r3, [r4, #0x2c]
 *   @0x1a4710 cmn r3, #1
 *   @0x1a4714 bne 0x1a4690 <_Z20ParticleSystem_Layerii+0x30>
 *   @0x1a4718 vldr s15, [r4, #28]
 *   @0x1a471c vcvt.s32.f32 s15, s15
 *   @0x1a4720 mov r1, #1
 *   @0x1a4724 ldr r0, [r7]
 *   @0x1a4728 mov r3, r1
 *   @0x1a472c str r1, [sp]
 *   @0x1a4730 mov r2, r8
 *   @0x1a4734 vmov r1, s15
 *   @0x1a4738 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb>
 *   @0x1a473c str r0, [r4, #0x2c]
 *   @0x1a4740 b 0x1a4690 <_Z20ParticleSystem_Layerii+0x30>
 *   @0x1a4744 ldr r12, [r6, #0x4]
 *   @0x1a4748 mov r1, r0
 *   @0x1a474c mov r3, #1
 *   @0x1a4750 mov r0, r9
 *   @0x1a4754 mov r2, r8
 *   @0x1a4758 ldr r5, [r12, r4, lsl #2]
 *   @0x1a475c bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1a4760 ldr r3, [r6, #0x4]
 *   @0x1a4764 ldr r3, [r3, r4, lsl #2]
 *   @0x1a4768 str r0, [r5, #0x2c]
 *   @0x1a476c ldr r3, [r3, #0x2c]
 *   @0x1a4770 cmn r3, #1
 *   @0x1a4774 bne 0x1a4690 <_Z20ParticleSystem_Layerii+0x30>
 *   @0x1a4778 ldr r1, [r8, #0x4]
 *   @0x1a477c mov r0, r9
 *   @0x1a4780 mov r2, #1
 *   @0x1a4784 mov r3, #0
 *   @0x1a4788 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a478c mov r8, #0
 *   @0x1a4790 b 0x1a4704 <_Z20ParticleSystem_Layerii+0xa4>
 *   @0x1a4794 eoreq r9, r4, r4, lsr #5
 *   @0x1a4798 eoreq r12, r4, r0, lsl r1
 *   @0x1a479c eoreq r9, r4, r12, ror r2
 *
 * ══ §47/94 Path_Duplicate(int)  0x1a8320  size 320  80 条（0x1a8320..0x1a8460）
 * @func 0x1a8320 0x1a8460  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Path_Duplicate(int)+0x11c / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CPath::CPath() / CPath::Assign(CPath*) / 0xb65d4
 * 字段偏移 top8: 0x2×5 / 0x104×3 / 0x4×3 / 0x118×1 / 0xf4×1 / 0xe0×1 / 0xcc×1 / 0x94×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8320 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a8324 subs r8, r0, #0
 *   @0x1a8328 ldr r6, [pc, #0x118]
 *   @0x1a832c sub sp, sp, #268
 *   @0x1a8330 ldr r6, [pc, r6]
 *   @0x1a8334 ldr r3, [r6]
 *   @0x1a8338 str r3, [sp, #0x104]
 *   @0x1a833c blt 0x1a843c <_Z14Path_Duplicatei+0x11c>
 *   @0x1a8340 ldr r4, [pc, #0x104]
 *   @0x1a8344 ldr r4, [pc, r4]
 *   @0x1a8348 ldr r3, [r4]
 *   @0x1a834c cmp r8, r3
 *   @0x1a8350 bge 0x1a843c <_Z14Path_Duplicatei+0x11c>
 *   @0x1a8354 ldr r5, [pc, #0xf4]
 *   @0x1a8358 add r5, pc, r5
 *   @0x1a835c ldr r2, [r5, #0x4]
 *   @0x1a8360 ldr r2, [r2, r8, lsl #2]
 *   @0x1a8364 cmp r2, #0
 *   @0x1a8368 beq 0x1a843c <_Z14Path_Duplicatei+0x11c>
 *   @0x1a836c ldr r9, [pc, #0xe0]
 *   @0x1a8370 add r12, r3, #1
 *   @0x1a8374 add r0, r5, #4
 *   @0x1a8378 mov r3, #336
 *   @0x1a837c add r9, pc, r9
 *   @0x1a8380 lsl r1, r12, #2
 *   @0x1a8384 ldr r7, [pc, #0xcc]
 *   @0x1a8388 mov r2, r9
 *   @0x1a838c str r12, [r4]
 *   @0x1a8390 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a8394 ldr r12, [r4]
 *   @0x1a8398 ldr r7, [pc, r7]
 *   @0x1a839c mov r2, r9
 *   @0x1a83a0 movw r3, #0x152
 *   @0x1a83a4 add r9, sp, #4
 *   @0x1a83a8 lsl r1, r12, #2
 *   @0x1a83ac mov r0, r7
 *   @0x1a83b0 str r12, [r5]
 *   @0x1a83b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a83b8 ldr r3, [r4]
 *   @0x1a83bc mov r1, #256
 *   @0x1a83c0 ldr r2, [pc, #0x94]
 *   @0x1a83c4 mov r0, r9
 *   @0x1a83c8 sub r3, r3, #1
 *   @0x1a83cc add r2, pc, r2
 *   @0x1a83d0 bl 0xb65c8 <snprintf@plt>
 *   @0x1a83d4 ldr r3, [r4]
 *   @0x1a83d8 mov r0, r9
 *   @0x1a83dc ldr r7, [r7]
 *   @0x1a83e0 sub r9, r3, #-1073741823
 *   @0x1a83e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1a83e8 str r0, [r7, r9, lsl #2]
 *   @0x1a83ec mov r0, #44
 *   @0x1a83f0 bl 0x27c524 <_Znwj>
 *   @0x1a83f4 mov r7, r0
 *   @0x1a83f8 bl 0x1a6e9c <_ZN5CPathC2Ev>
 *   @0x1a83fc ldr r2, [r4]
 *   @0x1a8400 ldr r3, [r5, #0x4]
 *   @0x1a8404 sub r2, r2, #-1073741823
 *   @0x1a8408 str r7, [r3, r2, lsl #2]
 *   @0x1a840c ldr r3, [r5, #0x4]
 *   @0x1a8410 ldr r0, [r3, r2, lsl #2]
 *   @0x1a8414 ldr r1, [r3, r8, lsl #2]
 *   @0x1a8418 bl 0x1a6ed0 <_ZN5CPath6AssignEPS_>
 *   @0x1a841c ldr r0, [r4]
 *   @0x1a8420 sub r0, r0, #1
 *   @0x1a8424 ldr r2, [sp, #0x104]
 *   @0x1a8428 ldr r3, [r6]
 *   @0x1a842c cmp r2, r3
 *   @0x1a8430 bne 0x1a8444 <_Z14Path_Duplicatei+0x124>
 *   @0x1a8434 add sp, sp, #268
 *   @0x1a8438 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a843c mvn r0, #0
 *   @0x1a8440 b 0x1a8424 <_Z14Path_Duplicatei+0x104>
 *   @0x1a8444 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1a8448 eoreq r5, r4, r0, lsr #12
 *   @0x1a844c eoreq r8, r4, r8, lsl #9
 *   @0x1a8450 ldrsbteq r10, [r9], -r0
 *   @0x1a8454 mulseq r10, r0, sp
 *   @0x1a8458 eoreq r8, r4, r8, lsr r4
 *   @0x1a845c andseq r4, r10, r4, ror sp
 *
 * ══ §48/94 cAudio_Sound::LoadFromChunk(YYSound*, unsigned char*)  0x218d64  size 320  80 条（0x218d64..0x218ea4）
 * @func 0x218d64 0x218ea4  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / cAudio_Sound::LoadFromChunk(YYSound*, unsigned char*)+0xe8
 * 字段偏移 top8: 0x25×5 / 0x24×5 / 0xc×2 / 0x4×2 / 0x14×2 / 0x20×2 / 0x1c×2 / 0x26×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218d64 push {r3, r4, r5, r6, r7, lr}
 *   @0x218d68 mov r4, r0
 *   @0x218d6c ldr r0, [r1, #0xc]
 *   @0x218d70 mov r3, #0
 *   @0x218d74 mov r5, r1
 *   @0x218d78 str r3, [r4]
 *   @0x218d7c cmp r0, r3
 *   @0x218d80 ldrne r3, [pc, #0x118]
 *   @0x218d84 ldrne r3, [pc, r3]
 *   @0x218d88 ldrne r3, [r3]
 *   @0x218d8c addne r0, r3, r0
 *   @0x218d90 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x218d94 ldr r12, [r5, #0x4]
 *   @0x218d98 ldr r3, [r5, #0x14]
 *   @0x218d9c mov r1, #0
 *   @0x218da0 ldr r6, [r5, #0x20]
 *   @0x218da4 cmp r12, #99
 *   @0x218da8 ldr r2, [r5, #0x1c]
 *   @0x218dac mov r7, #1065353216
 *   @0x218db0 str r3, [r4, #0x4]
 *   @0x218db4 mov r5, #1
 *   @0x218db8 mov r3, #0
 *   @0x218dbc str r6, [r4, #0x14]
 *   @0x218dc0 str r3, [r4, #0x1c]
 *   @0x218dc4 mov r6, #0
 *   @0x218dc8 str r2, [r4, #0x4c]
 *   @0x218dcc movt r6, #0xbf80
 *   @0x218dd0 str r3, [r4, #0x48]
 *   @0x218dd4 mov r2, #0
 *   @0x218dd8 mov r3, #0
 *   @0x218ddc str r1, [r4, #0x20]
 *   @0x218de0 str r1, [r4, #0xc]
 *   @0x218de4 str r1, [r4, #0x18]
 *   @0x218de8 str r7, [r4, #0x8]
 *   @0x218dec str r1, [r4, #0x38]
 *   @0x218df0 strb r1, [r4, #0x26]
 *   @0x218df4 strd r2, r3, [r4, #64]
 *   @0x218df8 str r5, [r4, #0x3c]
 *   @0x218dfc str r6, [r4, #0x34]
 *   @0x218e00 str r0, [r4]
 *   @0x218e04 ble 0x218e4c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xe8>
 *   @0x218e08 sub r12, r12, #100
 *   @0x218e0c cmp r12, #3
 *   @0x218e10 addls pc, pc, r12, lsl #2
 *   @0x218e14 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0>
 *   @0x218e18 b 0x218e28 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xc4>
 *   @0x218e1c b 0x218e7c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x118>
 *   @0x218e20 b 0x218e8c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x128>
 *   @0x218e24 b 0x218e64 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x100>
 *   @0x218e28 mov r3, #1
 *   @0x218e2c strb r3, [r4, #0x25]
 *   @0x218e30 strb r3, [r4, #0x24]
 *   @0x218e34 mov r3, #0
 *   @0x218e38 mov r0, #1
 *   @0x218e3c str r3, [r4, #0x28]
 *   @0x218e40 str r3, [r4, #0x2c]
 *   @0x218e44 str r3, [r4, #0x30]
 *   @0x218e48 pop {r3, r4, r5, r6, r7, pc}
 *   @0x218e4c cmp r12, #0
 *   @0x218e50 movle r12, #0
 *   @0x218e54 movgt r12, #1
 *   @0x218e58 strb r12, [r4, #0x25]
 *   @0x218e5c strb r12, [r4, #0x24]
 *   @0x218e60 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0>
 *   @0x218e64 mov r3, #0
 *   @0x218e68 mov r2, #1
 *   @0x218e6c strb r3, [r4, #0x24]
 *   @0x218e70 strb r3, [r4, #0x25]
 *   @0x218e74 strb r2, [r4, #0x26]
 *   @0x218e78 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0>
 *   @0x218e7c mov r3, #0
 *   @0x218e80 strb r3, [r4, #0x25]
 *   @0x218e84 strb r3, [r4, #0x24]
 *   @0x218e88 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0>
 *   @0x218e8c mov r2, #0
 *   @0x218e90 mov r3, #1
 *   @0x218e94 strb r2, [r4, #0x24]
 *   @0x218e98 strb r3, [r4, #0x25]
 *   @0x218e9c b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0>
 *   @0x218ea0 andseq r4, sp, r0, asr #23
 *
 * ══ §49/94 Debug_GetSelectedInstance(DbgSocket*)  0x29d9bc  size 320  80 条（0x29d9bc..0x29dafc）
 * @func 0x29d9bc 0x29dafc  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DbgSocket::GetUserData()
 * 字段偏移 top8: 0x30×5 / 0x8×5 / 0x38×5 / 0x2c×4 / 0x10×2 / 0x1c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d9bc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29d9c0 mov r10, r0
 *   @0x29d9c4 bl 0x29d9b0 <_ZN9DbgSocket11GetUserDataEv>
 *   @0x29d9c8 mov r7, #0
 *   @0x29d9cc mov r2, #465567744
 *   @0x29d9d0 movw r3, #0xc238
 *   @0x29d9d4 movt r3, #0x41e7
 *   @0x29d9d8 ldr r1, [r0]
 *   @0x29d9dc add r8, r0, #44
 *   @0x29d9e0 mov r6, r0
 *   @0x29d9e4 str r2, [r0, #0x2c]
 *   @0x29d9e8 str r3, [r0, #0x30]
 *   @0x29d9ec mov r2, r8
 *   @0x29d9f0 ldr r3, [r1, #0x8]
 *   @0x29d9f4 mov r1, #5
 *   @0x29d9f8 str r7, [r0, #0x38]
 *   @0x29d9fc blx r3
 *   @0x29da00 ldr r3, [r6]
 *   @0x29da04 str r7, [r6, #0x2c]
 *   @0x29da08 mov r2, r8
 *   @0x29da0c str r7, [r6, #0x30]
 *   @0x29da10 mov r0, r6
 *   @0x29da14 str r7, [r6, #0x38]
 *   @0x29da18 mov r1, #5
 *   @0x29da1c ldr r3, [r3, #0x8]
 *   @0x29da20 blx r3
 *   @0x29da24 ldr r1, [r6]
 *   @0x29da28 str r7, [r6, #0x2c]
 *   @0x29da2c mov r2, r8
 *   @0x29da30 mov r3, r7
 *   @0x29da34 str r7, [r6, #0x38]
 *   @0x29da38 movt r3, #0x402e
 *   @0x29da3c mov r0, r6
 *   @0x29da40 str r3, [r6, #0x30]
 *   @0x29da44 ldr r3, [r1, #0x8]
 *   @0x29da48 mov r1, #5
 *   @0x29da4c blx r3
 *   @0x29da50 ldr r1, [r6]
 *   @0x29da54 str r7, [r6, #0x38]
 *   @0x29da58 mov r2, r7
 *   @0x29da5c mov r0, r6
 *   @0x29da60 movt r2, #0xffe0
 *   @0x29da64 movw r3, #0xffff
 *   @0x29da68 str r2, [r6, #0x2c]
 *   @0x29da6c movt r3, #0x41ef
 *   @0x29da70 mov r2, r8
 *   @0x29da74 str r3, [r6, #0x30]
 *   @0x29da78 ldr r3, [r1, #0x8]
 *   @0x29da7c mov r1, #5
 *   @0x29da80 blx r3
 *   @0x29da84 ldr r3, [r6]
 *   @0x29da88 ldr r9, [r6, #0x1c]
 *   @0x29da8c mov r1, r7
 *   @0x29da90 mov r0, r6
 *   @0x29da94 mov r2, #4
 *   @0x29da98 ldr r3, [r3, #0x10]
 *   @0x29da9c blx r3
 *   @0x29daa0 vmov s15, r9
 *   @0x29daa4 ldr r3, [r6]
 *   @0x29daa8 mov r2, r8
 *   @0x29daac vcvt.f64.u32 d7, s15
 *   @0x29dab0 str r7, [r6, #0x38]
 *   @0x29dab4 mov r0, r6
 *   @0x29dab8 mov r1, #5
 *   @0x29dabc vmov r4, r5, d7
 *   @0x29dac0 vstr s14, [r6, #44]
 *   @0x29dac4 str r5, [r6, #0x30]
 *   @0x29dac8 ldr r3, [r3, #0x8]
 *   @0x29dacc blx r3
 *   @0x29dad0 ldr r3, [r6]
 *   @0x29dad4 mov r1, r7
 *   @0x29dad8 mov r2, r9
 *   @0x29dadc mov r0, r6
 *   @0x29dae0 ldr r3, [r3, #0x10]
 *   @0x29dae4 blx r3
 *   @0x29dae8 mov r0, r10
 *   @0x29daec mov r2, r9
 *   @0x29daf0 ldr r1, [r6, #0xc]
 *   @0x29daf4 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29daf8 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj>
 *
 * ══ §50/94 CProfiler::ResetData()  0x2a09a0  size 320  80 条（0x2a09a0..0x2a0ae0）
 * @func 0x2a09a0 0x2a0ae0  size 320  80 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CProfiler::ResetData()+0xf8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×5 / 0x4×4 / 0xc×2 / 0x3×2 / 0x30×1 / 0x1×1 / 0x2×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a09a0 push {r4, r5, r6, lr}
 *   @0x2a09a4 mov r12, #0
 *   @0x2a09a8 ldr r1, [r0, #0x8]
 *   @0x2a09ac mov r2, #0
 *   @0x2a09b0 ldr r5, [r0, #0xc]
 *   @0x2a09b4 mov r3, #0
 *   @0x2a09b8 str r12, [r0, #0x30]
 *   @0x2a09bc sub sp, sp, #8
 *   @0x2a09c0 strd r2, r3, [r0, #72]
 *   @0x2a09c4 mov r4, r0
 *   @0x2a09c8 strd r2, r3, [r0, #96]
 *   @0x2a09cc strd r2, r3, [r0, #80]
 *   @0x2a09d0 str r12, [r1, #0x4]
 *   @0x2a09d4 ldr r1, [r5]
 *   @0x2a09d8 str r12, [r5, #0x4]
 *   @0x2a09dc cmp r1, #1
 *   @0x2a09e0 ble 0x2a0a98 <_ZN9CProfiler9ResetDataEv+0xf8>
 *   @0x2a09e4 ldr r1, [r5, #0x8]
 *   @0x2a09e8 mov r6, r12
 *   @0x2a09ec mov r2, #1
 *   @0x2a09f0 add r3, r1, r12
 *   @0x2a09f4 str r2, [r5, #0x4]
 *   @0x2a09f8 mov r2, #0
 *   @0x2a09fc strb r2, [r1, r12]
 *   @0x2a0a00 ldrb r0, [r3, #0x3]
 *   @0x2a0a04 mvn r1, #0
 *   @0x2a0a08 strb r2, [r3, #0x1]
 *   @0x2a0a0c and r0, r0, #240
 *   @0x2a0a10 strb r2, [r3, #0x2]
 *   @0x2a0a14 strb r2, [r3, #0x8]
 *   @0x2a0a18 bfi r0, r2, #4, #4
 *   @0x2a0a1c strb r2, [r3, #0x9]
 *   @0x2a0a20 strb r2, [r3, #0xa]
 *   @0x2a0a24 strb r2, [r3, #0xb]
 *   @0x2a0a28 strb r2, [r3, #0xc]
 *   @0x2a0a2c strb r2, [r3, #0xd]
 *   @0x2a0a30 strb r2, [r3, #0xe]
 *   @0x2a0a34 strb r2, [r3, #0xf]
 *   @0x2a0a38 strb r2, [r3, #0x10]
 *   @0x2a0a3c strb r2, [r3, #0x11]
 *   @0x2a0a40 strb r2, [r3, #0x12]
 *   @0x2a0a44 strb r2, [r3, #0x13]
 *   @0x2a0a48 strb r2, [r3, #0x14]
 *   @0x2a0a4c strb r2, [r3, #0x15]
 *   @0x2a0a50 strb r2, [r3, #0x16]
 *   @0x2a0a54 strb r2, [r3, #0x17]
 *   @0x2a0a58 strb r2, [r3, #0x20]
 *   @0x2a0a5c strb r2, [r3, #0x21]
 *   @0x2a0a60 strb r2, [r3, #0x22]
 *   @0x2a0a64 strb r0, [r3, #0x3]
 *   @0x2a0a68 strb r1, [r3, #0x18]
 *   @0x2a0a6c strb r1, [r3, #0x19]
 *   @0x2a0a70 strb r1, [r3, #0x1a]
 *   @0x2a0a74 strb r1, [r3, #0x1b]
 *   @0x2a0a78 strb r1, [r3, #0x1c]
 *   @0x2a0a7c strb r1, [r3, #0x1d]
 *   @0x2a0a80 strb r1, [r3, #0x1e]
 *   @0x2a0a84 strb r1, [r3, #0x1f]
 *   @0x2a0a88 strb r2, [r3, #0x23]
 *   @0x2a0a8c str r6, [r4, #0x70]
 *   @0x2a0a90 add sp, sp, #8
 *   @0x2a0a94 pop {r4, r5, r6, pc}
 *   @0x2a0a98 lsl r3, r1, #1
 *   @0x2a0a9c ldr r2, [pc, #0x38]
 *   @0x2a0aa0 add r1, r3, r1, lsl #3
 *   @0x2a0aa4 str r3, [r5]
 *   @0x2a0aa8 ldr r0, [r5, #0x8]
 *   @0x2a0aac add r2, pc, r2
 *   @0x2a0ab0 lsl r1, r1, #3
 *   @0x2a0ab4 str r12, [sp]
 *   @0x2a0ab8 mov r3, #104
 *   @0x2a0abc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2a0ac0 ldr r6, [r5, #0x4]
 *   @0x2a0ac4 add r2, r6, #1
 *   @0x2a0ac8 add r12, r6, r6, lsl #2
 *   @0x2a0acc lsl r12, r12, #3
 *   @0x2a0ad0 mov r1, r0
 *   @0x2a0ad4 str r0, [r5, #0x8]
 *   @0x2a0ad8 b 0x2a09f0 <_ZN9CProfiler9ResetDataEv+0x50>
 *   @0x2a0adc andeq r9, r11, r8, asr #3
 *
 * ══ §51/94 png_handle_unknown  0x2ada34  size 320  80 条（0x2ada34..0x2adb74）
 * @func 0x2ada34 0x2adb74  size 320  80 条
 * 部分覆盖: 本节 80/133 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_chunk_error×2 / anon_30a7b2+0x34ae / png_warning / 0xb6c40 / png_handle_as_unknown / png_crc_read / png_set_unknown_chunks
 * 字段偏移 top8: 0x108×1 / 0x4×1 / 0x60×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ada34 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2ada38 mov r4, r0
 *   @0x2ada3c .word 0x460f3310
 *   @0x2ada40 mov r5, r2
 *   @0x2ada44 cmp r3, #0x1
 *   @0x2ada48 bllo 0x30dc60 <af_shaper_get_elem+0x34ce>
 *   @0x2ada4c str.w r3, [r0, #0x310]
 *   @0x2ada50 cmp r3, #0x1
 *   @0x2ada54 ldr r1, [pc, #0x108]
 *   @0x2ada58 bl 0x2a6474 <png_warning>
 *   @0x2ada5c b 0x2adb50 <png_handle_unknown+0x11c>
 *   @0x2ada60 ldrbeq r6, [r0, -r12, lsr #2]!
 *   @0x2ada64 bpl 0x2ada8a <png_handle_unknown+0x56>
 *   @0x2ada68 mov r1, sp
 *   @0x2ada6c add r3, pc
 *   @0x2ada70 ldrb r3, [r3, #0x4]
 *   @0x2ada74 add.w r0, r4, #0x1e0
 *   @0x2ada78 strb.w r3, [sp, #0x4]
 *   @0x2ada7c blx 0xb6c40 <memcmp@plt>
 *   @0x2ada80 cbz r0, 0x2ada8a <png_handle_unknown+0x56>
 *   @0x2ada84 .word 0xf8c40608
 *   @0x2ada88 .word 0xf894612c
 *   @0x2ada8c ldreq r3, [r9], r0, ror #3
 *   @0x2ada90 bmi 0x2adab0 <png_handle_unknown+0x7c>
 *   @0x2ada94 add.w r1, r4, #0x1e0
 *   @0x2ada98 bl 0x2a5fe4 <png_handle_as_unknown>
 *   @0x2ada9c cmp r0, #0x3
 *   @0x2adaa0 ldr.w r3, [r4, #0x2c8]
 *   @0x2adaa4 cbnz r3, 0x2adab0 <png_handle_unknown+0x7c>
 *   @0x2adaa8 mov r0, r4
 *   @0x2adaac bl 0x2a64cc <png_chunk_error>
 *   @0x2adab0 ldr.w r3, [r4, #0x130]
 *   @0x2adab4 lsls r2, r3, #0x10
 *   @0x2adab8 ldr.w r3, [r4, #0x2c8]
 *   @0x2adabc cmp r3, #0x0
 *   @0x2adac0 add.w r8, r4, #0x1e0
 *   @0x2adac4 ldr.w r3, [r8]
 *   @0x2adac8 add.w r6, r4, #0x314
 *   @0x2adacc str.w r5, [r4, #0x320]
 *   @0x2adad0 str.w r3, [r4, #0x314]
 *   @0x2adad4 movs r3, #0x0
 *   @0x2adad8 ldmdblt r5, {r3, r4, r8, r9, r12, sp}
 *   @0x2adadc str.w r5, [r4, #0x31c]
 *   @0x2adae0 b 0x2adaf8 <png_handle_unknown+0xc4>
 *   @0x2adae4 mov r0, r4
 *   @0x2adae8 .word 0x462af8db
 *   @0x2adaec mov r1, r0
 *   @0x2adaf0 qadd16mi r0, r0, r12
 *   @0x2adaf4 bl 0x2abc0c <png_crc_read>
 *   @0x2adaf8 ldr.w r3, [r4, #0x2c8]
 *   @0x2adafc mov r0, r4
 *   @0x2adb00 mov r1, r6
 *   @0x2adb04 cmp r0, #0x0
 *   @0x2adb08 ldr r1, [pc, #0x60]
 *   @0x2adb0c add r1, pc
 *   @0x2adb10 ldrsb pc, [r5], -sp
 *   @0x2adb14 bne 0x2adb40 <png_handle_unknown+0x10c>
 *   @0x2adb18 ldreq r3, [r11], r0, ror #3
 *   @0x2adb1c bmi 0x2adb34 <png_handle_unknown+0x100>
 *   @0x2adb20 mov r1, r8
 *   @0x2adb24 stmdahs r3, {r0, r1, r2, r3, r4, r6, r9, r11, r12, sp, lr, pc}
 *   @0x2adb28 beq 0x2adb34 <png_handle_unknown+0x100>
 *   @0x2adb2c mov r0, r4
 *   @0x2adb30 bl 0x2a64cc <png_chunk_error>
 *   @0x2adb34 mov r0, r4
 *   @0x2adb38 mov r2, r6
 *   @0x2adb3c bl 0x2af340 <png_set_unknown_chunks>
 *   @0x2adb40 mov r0, r4
 *   @0x2adb44 .word 0xf7f9131c
 *   @0x2adb48 strhs pc, [r0, #-0x8d9]
 *   @0x2adb4c str.w r5, [r4, #0x31c]
 *   @0x2adb50 mov r0, r4
 *   @0x2adb54 add sp, #0x8
 *   @0x2adb58 .word 0xf7fe41f0
 *   @0x2adb5c svclt #0xb89b
 *   @0x2adb60 .word 0xff3e 000d
 *   @0x2adb64 subs r4, r7, #0x5
 *   @0x2adb68 vhadd.u16 d0, d4, d13
 *   @0x2adb6c cdp2 p0, #0xc, c0, c9, c13, #0x0
 *   @0x2adb70 cdp2 p0, #0x9, c0, c0, c13, #0x0
 *
 * ══ §52/94 DIALOG_REQ_CONTEXT::AddInputDialog(char const*, char const*, char const*)  0xf2214  size 316  79 条（0xf2214..0xf2350）
 * @func 0xf2214 0xf2350  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6640×3 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / loginDialogAsync / showMessage / questionDialogAsync / inputDialogAsync
 * 字段偏移 top8: 0x24×5 / 0x48×4 / 0x4c×4 / 0x10c×1 / 0x4×1 / 0x8×1 / 0xe8×1 / 0xa8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2214 push {r4, r5, r6, r7, lr}
 *   @0xf2218 mov r7, r0
 *   @0xf221c sub sp, sp, #20
 *   @0xf2220 mov r0, #88
 *   @0xf2224 mov r6, r1
 *   @0xf2228 mov r5, r2
 *   @0xf222c bl 0x27c524 <_Znwj>
 *   @0xf2230 ldr r3, [pc, #0x10c]
 *   @0xf2234 mov r12, #0
 *   @0xf2238 str r12, [sp]
 *   @0xf223c ldr r3, [pc, r3]
 *   @0xf2240 mov r1, r12
 *   @0xf2244 str r12, [sp, #0x4]
 *   @0xf2248 mov r2, r12
 *   @0xf224c str r12, [sp, #0x8]
 *   @0xf2250 mov r4, r0
 *   @0xf2254 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0xf2258 ldr r3, [pc, #0xe8]
 *   @0xf225c subs r0, r7, #0
 *   @0xf2260 ldr r3, [pc, r3]
 *   @0xf2264 add r3, r3, #8
 *   @0xf2268 str r3, [r4]
 *   @0xf226c beq 0xf2274 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x60>
 *   @0xf2270 bl 0xb6640 <strdup@plt>
 *   @0xf2274 cmp r6, #0
 *   @0xf2278 str r0, [r4, #0x48]
 *   @0xf227c mov r0, r6
 *   @0xf2280 beq 0xf2288 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x74>
 *   @0xf2284 bl 0xb6640 <strdup@plt>
 *   @0xf2288 cmp r5, #0
 *   @0xf228c str r0, [r4, #0x4c]
 *   @0xf2290 mov r0, r5
 *   @0xf2294 beq 0xf229c <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x88>
 *   @0xf2298 bl 0xb6640 <strdup@plt>
 *   @0xf229c ldr r1, [pc, #0xa8]
 *   @0xf22a0 mov r3, #1
 *   @0xf22a4 str r3, [r4, #0x30]
 *   @0xf22a8 mov r2, #0
 *   @0xf22ac ldr r1, [pc, r1]
 *   @0xf22b0 str r0, [r4, #0x50]
 *   @0xf22b4 str r2, [r4, #0x54]
 *   @0xf22b8 ldr r3, [r1]
 *   @0xf22bc str r4, [r1]
 *   @0xf22c0 cmp r3, r2
 *   @0xf22c4 str r3, [r4, #0x44]
 *   @0xf22c8 beq 0xf22d8 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xc4>
 *   @0xf22cc ldr r0, [r4, #0x24]
 *   @0xf22d0 add sp, sp, #20
 *   @0xf22d4 pop {r4, r5, r6, r7, pc}
 *   @0xf22d8 cmp r3, #3
 *   @0xf22dc addls pc, pc, r3, lsl #2
 *   @0xf22e0 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8>
 *   @0xf22e4 b 0xf2330 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x11c>
 *   @0xf22e8 b 0xf231c <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x108>
 *   @0xf22ec b 0xf2308 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xf4>
 *   @0xf22f0 b 0xf22f4 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xe0>
 *   @0xf22f4 ldr r0, [r4, #0x48]
 *   @0xf22f8 ldr r1, [r4, #0x4c]
 *   @0xf22fc ldr r2, [r4, #0x24]
 *   @0xf2300 bl 0xf2ad0 <loginDialogAsync>
 *   @0xf2304 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8>
 *   @0xf2308 ldr r0, [r4, #0x48]
 *   @0xf230c ldr r1, [r4, #0x4c]
 *   @0xf2310 ldr r2, [r4, #0x24]
 *   @0xf2314 bl 0xf2b4c <showMessage>
 *   @0xf2318 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8>
 *   @0xf231c ldr r0, [r4, #0x48]
 *   @0xf2320 ldr r1, [r4, #0x4c]
 *   @0xf2324 ldr r2, [r4, #0x24]
 *   @0xf2328 bl 0xf2a70 <questionDialogAsync>
 *   @0xf232c b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8>
 *   @0xf2330 add r0, r4, #72
 *   @0xf2334 ldr r3, [r4, #0x24]
 *   @0xf2338 ldm r0, {r0, r1, r2}
 *   @0xf233c bl 0xf29f4 <inputDialogAsync>
 *   @0xf2340 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8>
 *   @0xf2344 eoreq r11, pc, r12, lsr #23
 *   @0xf2348 eoreq r11, pc, r0, lsl #23
 *   @0xf234c eoreq r11, pc, r8, lsr r11
 *
 * ══ §53/94 F_SurfaceCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f1f8  size 316  79 条（0x11f1f8..0x11f334）
 * @func 0x11f1f8 0x11f334  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / GR_Surface_Exists(int)×2 / RenderStateManager::SetRenderState(eRenderState, unsigned int)×2 / GR_Surface_Get_Texture(int)×2 / GR_Texture_Get_Surface(int)×2 / YYGML_surface_set_target_ext(int, int) / RenderStateManager::SaveStates() / GR_Surface_Get_Width(int)
 * 字段偏移 top8: 0x30×1 / 0xe8×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f1f8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f1fc sub sp, sp, #16
 *   @0x11f200 mov r1, #0
 *   @0x11f204 ldr r4, [sp, #0x30]
 *   @0x11f208 mov r0, r4
 *   @0x11f20c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f210 mov r6, r0
 *   @0x11f214 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f218 cmp r0, #0
 *   @0x11f21c beq 0x11f314 <_Z13F_SurfaceCopyR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x11f220 mov r1, #3
 *   @0x11f224 mov r0, r4
 *   @0x11f228 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f22c mov r7, r0
 *   @0x11f230 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f234 cmp r0, #0
 *   @0x11f238 beq 0x11f314 <_Z13F_SurfaceCopyR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x11f23c ldr r5, [pc, #0xe8]
 *   @0x11f240 mov r1, r6
 *   @0x11f244 mov r0, #0
 *   @0x11f248 bl 0x171574 <_Z28YYGML_surface_set_target_extii>
 *   @0x11f24c ldr r5, [pc, r5]
 *   @0x11f250 mov r0, r5
 *   @0x11f254 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x11f258 mov r0, r4
 *   @0x11f25c mov r1, #0
 *   @0x11f260 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f264 mov r1, #12
 *   @0x11f268 mov r2, r0
 *   @0x11f26c mov r0, r5
 *   @0x11f270 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x11f274 mov r2, #0
 *   @0x11f278 mov r1, #1
 *   @0x11f27c mov r0, r5
 *   @0x11f280 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x11f284 mov r0, r7
 *   @0x11f288 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f28c bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f290 mov r8, r0
 *   @0x11f294 mov r0, r6
 *   @0x11f298 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f29c bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f2a0 mov r1, #1
 *   @0x11f2a4 mov r6, r0
 *   @0x11f2a8 mov r0, r4
 *   @0x11f2ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f2b0 mov r1, #2
 *   @0x11f2b4 mov r9, r0
 *   @0x11f2b8 mov r0, r4
 *   @0x11f2bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f2c0 mov r4, r0
 *   @0x11f2c4 mov r0, r7
 *   @0x11f2c8 bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0x11f2cc mov r10, r0
 *   @0x11f2d0 mov r0, r7
 *   @0x11f2d4 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0x11f2d8 mov r12, #0
 *   @0x11f2dc mov r1, r9
 *   @0x11f2e0 mov r2, r4
 *   @0x11f2e4 mov r3, r8
 *   @0x11f2e8 str r12, [sp]
 *   @0x11f2ec str r12, [sp, #0x4]
 *   @0x11f2f0 str r10, [sp, #0x8]
 *   @0x11f2f4 str r0, [sp, #0xc]
 *   @0x11f2f8 mov r0, r6
 *   @0x11f2fc bl 0x17e850 <_ZN8Graphics11SurfaceCopyEPviiS0_iiii>
 *   @0x11f300 mov r0, r5
 *   @0x11f304 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x11f308 add sp, sp, #16
 *   @0x11f30c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f310 b 0x171808 <_Z26YYGML_surface_reset_targetv>
 *   @0x11f314 ldr r0, [pc, #0x14]
 *   @0x11f318 mov r1, #0
 *   @0x11f31c add r0, pc, r0
 *   @0x11f320 add sp, sp, #16
 *   @0x11f324 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f328 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f32c eoreq lr, r12, r12, lsr #21
 *   @0x11f330 eoreq r10, r1, r12, asr #30
 *
 * ══ §54/94 F_SpriteFlush(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f0c4  size 316  79 条（0x12f0c4..0x12f200）
 * @func 0x12f0c4 0x12f200  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x12f11c→0x48ffec, 0x12f19c→0x3eb70c, 0x12f1c4→0x3eb70c
 * 调用序列: Graphics::FlushTexture(void*)×2 / YYGetInt32(RValue const*, int) / Sprite_Data(int) / Graphics::Flush() / F_SpriteFlush(RValue&, CInstance*, CInstance*, int, RValue*)+0xc8 / CSprite::GetTexture(int)
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x18×2 / 0x2×2 / 0x28×2 / 0xfc×1 / 0x74×1 / 0xcc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f0c4 push {r4, r5, r6, r7, r8, lr}
 *   @0x12f0c8 mov r1, #0
 *   @0x12f0cc mov r3, r1
 *   @0x12f0d0 str r1, [r0, #0xc]
 *   @0x12f0d4 movt r3, #0xbff0
 *   @0x12f0d8 mov r8, r0
 *   @0x12f0dc stm r0, {r1, r3}
 *   @0x12f0e0 ldr r0, [sp, #0x18]
 *   @0x12f0e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f0e8 ldr r5, [pc, #0xfc]
 *   @0x12f0ec add r5, pc, r5
 *   @0x12f0f0 mov r7, r0
 *   @0x12f0f4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12f0f8 subs r6, r0, #0
 *   @0x12f0fc beq 0x12f1c4 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x12f100 ldr r4, [r6, #0x74]
 *   @0x12f104 cmp r4, #0
 *   @0x12f108 bne 0x12f19c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x12f10c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x12f110 ldr r7, [r6, #0x18]
 *   @0x12f114 cmp r7, #0
 *   @0x12f118 ble 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x12f11c ldr r3, [pc, #0xcc]
 *   @0x12f120 ldr r5, [r5, r3]
 *   @0x12f124 b 0x12f150 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12f128 cmn r0, #1
 *   @0x12f12c beq 0x12f168 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x12f130 ldrsh r2, [r0, #20]
 *   @0x12f134 ldr r3, [r5, #0x4]
 *   @0x12f138 ldr r3, [r3, r2, lsl #2]
 *   @0x12f13c ldr r0, [r3]
 *   @0x12f140 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12f144 add r4, r4, #1
 *   @0x12f148 cmp r4, r7
 *   @0x12f14c beq 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x12f150 mov r0, r6
 *   @0x12f154 mov r1, r4
 *   @0x12f158 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x12f15c ldr r3, [r5]
 *   @0x12f160 cmp r0, r3
 *   @0x12f164 bhi 0x12f128 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12f168 ldr r3, [r5, #0x4]
 *   @0x12f16c ldr r3, [r3, r0, lsl #2]
 *   @0x12f170 cmp r3, #0
 *   @0x12f174 beq 0x12f144 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12f178 ldr r0, [r3]
 *   @0x12f17c add r4, r4, #1
 *   @0x12f180 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12f184 cmp r4, r7
 *   @0x12f188 bne 0x12f150 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12f18c mov r3, #0
 *   @0x12f190 str r3, [r8]
 *   @0x12f194 str r3, [r8, #0x4]
 *   @0x12f198 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12f19c ldr r3, [pc, #0x50]
 *   @0x12f1a0 mov r2, r7
 *   @0x12f1a4 ldr r1, [pc, #0x4c]
 *   @0x12f1a8 ldr r3, [r5, r3]
 *   @0x12f1ac add r1, pc, r1
 *   @0x12f1b0 ldr r0, [r3]
 *   @0x12f1b4 ldr r3, [r0]
 *   @0x12f1b8 ldr r3, [r3, #0xc]
 *   @0x12f1bc blx r3
 *   @0x12f1c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12f1c4 ldr r3, [pc, #0x28]
 *   @0x12f1c8 mov r2, r7
 *   @0x12f1cc ldr r1, [pc, #0x28]
 *   @0x12f1d0 ldr r3, [r5, r3]
 *   @0x12f1d4 add r1, pc, r1
 *   @0x12f1d8 ldr r0, [r3]
 *   @0x12f1dc ldr r3, [r0]
 *   @0x12f1e0 ldr r3, [r3, #0xc]
 *   @0x12f1e4 blx r3
 *   @0x12f1e8 b 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x12f1ec eoreq r2, r12, r4, ror #22
 *   @0x12f1f0 .word 0xffffbccc
 *   @0x12f1f4 .word 0xffffbac4
 *   @0x12f1f8 .word 0x0020e5dc
 *   @0x12f1fc eoreq lr, r0, r12, lsl #11
 *
 * ══ §55/94 F_ActionDrawSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x140e70  size 316  79 条（0x140e70..0x140fac）
 * @func 0x140e70 0x140fac  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / Sprite_Data(int)×2 / CSprite::Draw(int, float, float, float, float, float, unsigned int, float)×2 / Sprite_Exists(int)
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x4×2 / 0x10×2 / 0x30×1 / 0xc0×1 / 0x14×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140e70 push {r4, r5, r6, lr}
 *   @0x140e74 vpush {d8}
 *   @0x140e78 sub sp, sp, #24
 *   @0x140e7c mov r6, r1
 *   @0x140e80 mov r1, #0
 *   @0x140e84 ldr r4, [sp, #0x30]
 *   @0x140e88 mov r0, r4
 *   @0x140e8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140e90 mov r1, #1
 *   @0x140e94 mov r5, r0
 *   @0x140e98 mov r0, r4
 *   @0x140e9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140ea0 mov r1, #2
 *   @0x140ea4 vmov s17, r0
 *   @0x140ea8 mov r0, r4
 *   @0x140eac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140eb0 mov r1, #3
 *   @0x140eb4 vmov s16, r0
 *   @0x140eb8 mov r0, r4
 *   @0x140ebc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140ec0 mov r4, r0
 *   @0x140ec4 mov r0, r5
 *   @0x140ec8 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x140ecc subs r1, r0, #0
 *   @0x140ed0 beq 0x140f8c <_Z18F_ActionDrawSpriteR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x140ed4 cmp r4, #0
 *   @0x140ed8 vldrlt s15, [r6, #144]
 *   @0x140edc ldr r3, [pc, #0xc0]
 *   @0x140ee0 mov r0, r5
 *   @0x140ee4 vcvtlt.s32.f32 s15, s15
 *   @0x140ee8 ldr r3, [pc, r3]
 *   @0x140eec ldrb r3, [r3]
 *   @0x140ef0 vmovlt r4, s15
 *   @0x140ef4 cmp r3, #0
 *   @0x140ef8 bne 0x140f3c <_Z18F_ActionDrawSpriteR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x140efc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x140f00 mov r12, #1065353216
 *   @0x140f04 mov r1, r4
 *   @0x140f08 mov r2, #0
 *   @0x140f0c mvn r3, #-16777216
 *   @0x140f10 str r2, [sp, #0x8]
 *   @0x140f14 str r3, [sp, #0xc]
 *   @0x140f18 vmov r2, s17
 *   @0x140f1c vmov r3, s16
 *   @0x140f20 str r12, [sp]
 *   @0x140f24 str r12, [sp, #0x4]
 *   @0x140f28 str r12, [sp, #0x10]
 *   @0x140f2c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x140f30 add sp, sp, #24
 *   @0x140f34 vpop {d8}
 *   @0x140f38 pop {r4, r5, r6, pc}
 *   @0x140f3c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x140f40 vldr s14, [r6, #180]
 *   @0x140f44 vldr s15, [r6, #184]
 *   @0x140f48 vadd.f32 s14, s17, s14
 *   @0x140f4c mov r3, #1065353216
 *   @0x140f50 mov r12, #0
 *   @0x140f54 str r3, [sp]
 *   @0x140f58 mov r1, r4
 *   @0x140f5c str r3, [sp, #0x4]
 *   @0x140f60 mvn r2, #-16777216
 *   @0x140f64 str r3, [sp, #0x10]
 *   @0x140f68 str r2, [sp, #0xc]
 *   @0x140f6c str r12, [sp, #0x8]
 *   @0x140f70 vadd.f32 s15, s16, s15
 *   @0x140f74 vmov r2, s14
 *   @0x140f78 vmov r3, s15
 *   @0x140f7c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x140f80 add sp, sp, #24
 *   @0x140f84 vpop {d8}
 *   @0x140f88 pop {r4, r5, r6, pc}
 *   @0x140f8c ldr r0, [pc, #0x14]
 *   @0x140f90 add r0, pc, r0
 *   @0x140f94 add sp, sp, #24
 *   @0x140f98 vpop {d8}
 *   @0x140f9c pop {r4, r5, r6, lr}
 *   @0x140fa0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x140fa4 eoreq r12, r10, r4, asr r12
 *   @0x140fa8 andseq pc, pc, r4, lsr #20
 *
 * ══ §56/94 CBitmap32::CreateBitmap24()  0x1675e8  size 316  79 条（0x1675e8..0x167724）
 * @func 0x1675e8 0x167724  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBitmap::Create() / CBitmap32::CreateBitmap24()+0x11c / CBitmap32::CreateBitmap24()+0x108
 * 字段偏移 top8: 0x8×5 / 0xc×4 / 0x14×4 / 0x2×4 / 0x4×3 / 0x1c×1 / 0x-4×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1675e8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1675ec mov r4, r0
 *   @0x1675f0 ldrb r0, [r0, #0x4]
 *   @0x1675f4 sub sp, sp, #8
 *   @0x1675f8 cmp r0, #0
 *   @0x1675fc beq 0x16771c <_ZN9CBitmap3214CreateBitmap24Ev+0x134>
 *   @0x167600 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x167604 mov r1, #6
 *   @0x167608 mov r5, #0
 *   @0x16760c ldr r3, [r0]
 *   @0x167610 mov r7, r0
 *   @0x167614 ldr r3, [r3, #0x1c]
 *   @0x167618 blx r3
 *   @0x16761c ldr r3, [r7]
 *   @0x167620 mov r0, r7
 *   @0x167624 ldr r1, [r4, #0x8]
 *   @0x167628 ldr r3, [r3, #0xc]
 *   @0x16762c blx r3
 *   @0x167630 ldr r3, [r7]
 *   @0x167634 mov r0, r7
 *   @0x167638 ldr r1, [r4, #0xc]
 *   @0x16763c ldr r3, [r3, #0x14]
 *   @0x167640 blx r3
 *   @0x167644 add r2, sp, #8
 *   @0x167648 mov r3, sp
 *   @0x16764c mov r0, r7
 *   @0x167650 str r5, [r2, #-0x4]!
 *   @0x167654 mov r1, r5
 *   @0x167658 ldr r12, [r7]
 *   @0x16765c str r5, [sp]
 *   @0x167660 ldr r12, [r12, #0x24]
 *   @0x167664 blx r12
 *   @0x167668 ldr r3, [r4, #0xc]
 *   @0x16766c cmp r3, r5
 *   @0x167670 ble 0x167704 <_ZN9CBitmap3214CreateBitmap24Ev+0x11c>
 *   @0x167674 ldr r6, [sp, #0x4]
 *   @0x167678 mov r12, r5
 *   @0x16767c ldr r8, [sp]
 *   @0x167680 ldr lr, [r4, #0x8]
 *   @0x167684 cmp lr, #0
 *   @0x167688 movgt r2, #0
 *   @0x16768c movgt r3, r2
 *   @0x167690 ble 0x1676f0 <_ZN9CBitmap3214CreateBitmap24Ev+0x108>
 *   @0x167694 mla lr, lr, r12, r3
 *   @0x167698 ldr r1, [r4, #0x14]
 *   @0x16769c add r5, r6, r2
 *   @0x1676a0 ldr r1, [r1, lr, lsl #2]
 *   @0x1676a4 lsr r1, r1, #16
 *   @0x1676a8 strb r1, [r5, #0x2]
 *   @0x1676ac ldr lr, [r4, #0x8]
 *   @0x1676b0 ldr r1, [r4, #0x14]
 *   @0x1676b4 mla lr, lr, r12, r3
 *   @0x1676b8 ldr r1, [r1, lr, lsl #2]
 *   @0x1676bc lsr r1, r1, #8
 *   @0x1676c0 strb r1, [r5, #0x1]
 *   @0x1676c4 ldr r5, [r4, #0x8]
 *   @0x1676c8 ldr lr, [r4, #0x14]
 *   @0x1676cc mla r5, r5, r12, r3
 *   @0x1676d0 add r3, r3, #1
 *   @0x1676d4 ldr lr, [lr, r5, lsl #2]
 *   @0x1676d8 strb lr, [r6, r2]
 *   @0x1676dc add r2, r2, #3
 *   @0x1676e0 ldr lr, [r4, #0x8]
 *   @0x1676e4 cmp lr, r3
 *   @0x1676e8 bgt 0x167694 <_ZN9CBitmap3214CreateBitmap24Ev+0xac>
 *   @0x1676ec ldr r3, [r4, #0xc]
 *   @0x1676f0 add r12, r12, #1
 *   @0x1676f4 add r6, r6, r8
 *   @0x1676f8 cmp r3, r12
 *   @0x1676fc bgt 0x167684 <_ZN9CBitmap3214CreateBitmap24Ev+0x9c>
 *   @0x167700 str r6, [sp, #0x4]
 *   @0x167704 ldr r3, [r7]
 *   @0x167708 mov r1, r0
 *   @0x16770c mov r0, r7
 *   @0x167710 ldr r3, [r3, #0x28]
 *   @0x167714 blx r3
 *   @0x167718 mov r0, r7
 *   @0x16771c add sp, sp, #8
 *   @0x167720 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §57/94 GraphicsRecorder::ReAllocVerts(SVertexNormal_Float*, int&, int&, int)  0x188cec  size 316  79 条（0x188cec..0x188e28）
 * @func 0x188cec 0x188e28  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65bc×2 / MemoryManager::Free(void const*)×2 / GraphicsRecorder::ReAllocVerts(SVertexNormal_Float*, int&, int&, int)+0x5c / GraphicsRecorder::ReAllocVerts(SVertexNormal_Float*, int&, int&, int)+0x124
 * 字段偏移 top8: 0x18×1 / 0xb4×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188cec push {r3, r4, r5, r6, r7, lr}
 *   @0x188cf0 mov r7, r1
 *   @0x188cf4 ldr r4, [sp, #0x18]
 *   @0x188cf8 mov r6, r2
 *   @0x188cfc mov r5, r3
 *   @0x188d00 cmp r4, #0
 *   @0x188d04 beq 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8>
 *   @0x188d08 cmn r4, #1
 *   @0x188d0c ldr r3, [r3]
 *   @0x188d10 beq 0x188dbc <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xd0>
 *   @0x188d14 ldr r12, [r2]
 *   @0x188d18 add r3, r4, r3
 *   @0x188d1c cmp r12, r3
 *   @0x188d20 strge r3, [r5]
 *   @0x188d24 bge 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8>
 *   @0x188d28 cmp r12, #0
 *   @0x188d2c bne 0x188d48 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x5c>
 *   @0x188d30 str r4, [r2]
 *   @0x188d34 mov r12, r4
 *   @0x188d38 ldr r3, [r5]
 *   @0x188d3c add r3, r4, r3
 *   @0x188d40 cmp r4, r3
 *   @0x188d44 bge 0x188d60 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x74>
 *   @0x188d48 lsl r12, r12, #1
 *   @0x188d4c str r12, [r6]
 *   @0x188d50 ldr r3, [r5]
 *   @0x188d54 add r3, r4, r3
 *   @0x188d58 cmp r12, r3
 *   @0x188d5c blt 0x188d48 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x5c>
 *   @0x188d60 add r0, r12, r12, lsl #3
 *   @0x188d64 ldr r1, [pc, #0xb4]
 *   @0x188d68 mov r2, #91
 *   @0x188d6c mov r3, #0
 *   @0x188d70 add r1, pc, r1
 *   @0x188d74 lsl r0, r0, #2
 *   @0x188d78 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x188d7c cmp r7, #0
 *   @0x188d80 mov r6, r0
 *   @0x188d84 beq 0x188da4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xb8>
 *   @0x188d88 ldr r3, [r5]
 *   @0x188d8c mov r1, r7
 *   @0x188d90 add r2, r3, r3, lsl #3
 *   @0x188d94 lsl r2, r2, #2
 *   @0x188d98 bl 0xb65bc <memcpy@plt>
 *   @0x188d9c mov r0, r7
 *   @0x188da0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x188da4 ldr r3, [r5]
 *   @0x188da8 mov r7, r6
 *   @0x188dac add r4, r3, r4
 *   @0x188db0 str r4, [r5]
 *   @0x188db4 mov r0, r7
 *   @0x188db8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x188dbc ldr r2, [r2]
 *   @0x188dc0 cmp r2, r3
 *   @0x188dc4 beq 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8>
 *   @0x188dc8 add r0, r3, r3, lsl #3
 *   @0x188dcc ldr r1, [pc, #0x50]
 *   @0x188dd0 mov r3, #0
 *   @0x188dd4 mov r2, #71
 *   @0x188dd8 add r1, pc, r1
 *   @0x188ddc lsl r0, r0, #2
 *   @0x188de0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x188de4 ldr r3, [r5]
 *   @0x188de8 cmp r3, #0
 *   @0x188dec mov r4, r0
 *   @0x188df0 ble 0x188e10 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0x124>
 *   @0x188df4 add r2, r3, r3, lsl #3
 *   @0x188df8 mov r1, r7
 *   @0x188dfc lsl r2, r2, #2
 *   @0x188e00 bl 0xb65bc <memcpy@plt>
 *   @0x188e04 mov r0, r7
 *   @0x188e08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x188e0c ldr r3, [r5]
 *   @0x188e10 mov r7, r4
 *   @0x188e14 str r3, [r6]
 *   @0x188e18 mov r0, r7
 *   @0x188e1c pop {r3, r4, r5, r6, r7, pc}
 *   @0x188e20 andseq r3, r12, r12, ror #5
 *   @0x188e24 andseq r3, r12, r4, lsl #5
 *
 * ══ §58/94 CInstance::Assign_Path(int, float, float, float, bool, int)  0x193fe0  size 316  79 条（0x193fe0..0x19411c）
 * @func 0x193fe0 0x19411c  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::XPosition(float)×3 / CPath::YPosition(float)×2 / CInstance::Assign_Path(int, float, float, float, bool, int)+0xe4 / Path_Data(int) / CPath::GetPathLength() / CInstance::Assign_Path(int, float, float, float, bool, int)+0xec / CInstance::Assign_Path(int, float, float, float, bool, int)+0x114 / CInstance::Assign_Path(int, float, float, float, bool, int)+0x124
 * 字段偏移 top8: 0x128×2 / 0x144×2 / 0x148×2 / 0x1c×1 / 0x130×1 / 0x20×1 / 0x140×1 / 0xb4×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x193fe0 cmp r1, #0
 *   @0x193fe4 push {r4, r5, r6, lr}
 *   @0x193fe8 vpush {d8}
 *   @0x193fec mov r4, r0
 *   @0x193ff0 str r1, [r0, #0x128]
 *   @0x193ff4 vmov s16, r2
 *   @0x193ff8 vmov s17, r3
 *   @0x193ffc ldrb r5, [sp, #0x1c]
 *   @0x194000 blt 0x1940c4 <_ZN9CInstance11Assign_PathEifffbi+0xe4>
 *   @0x194004 mov r0, r1
 *   @0x194008 bl 0x1a815c <_Z9Path_Datai>
 *   @0x19400c subs r6, r0, #0
 *   @0x194010 beq 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec>
 *   @0x194014 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv>
 *   @0x194018 mov r3, #0
 *   @0x19401c vmov s15, r0
 *   @0x194020 vcmpe.f32 s15, #0
 *   @0x194024 vmrs APSR_nzcv, fpscr
 *   @0x194028 bls 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec>
 *   @0x19402c vcmpe.f32 s16, #0
 *   @0x194030 vstr s16, [r4, #308]
 *   @0x194034 vmrs APSR_nzcv, fpscr
 *   @0x194038 strge r3, [r4, #0x12c]
 *   @0x19403c blt 0x1940f4 <_ZN9CInstance11Assign_PathEifffbi+0x114>
 *   @0x194040 vcmpe.f32 s17, #0
 *   @0x194044 str r3, [r4, #0x130]
 *   @0x194048 vstr s17, [r4, #312]
 *   @0x19404c vmrs APSR_nzcv, fpscr
 *   @0x194050 bmi 0x1940cc <_ZN9CInstance11Assign_PathEifffbi+0xec>
 *   @0x194054 ldr r2, [sp, #0x20]
 *   @0x194058 cmp r5, #0
 *   @0x19405c vldr s15, [sp, #24]
 *   @0x194060 vstr s15, [r4, #316]
 *   @0x194064 str r2, [r4, #0x140]
 *   @0x194068 bne 0x1940dc <_ZN9CInstance11Assign_PathEifffbi+0xfc>
 *   @0x19406c vcmpe.f32 s16, #0
 *   @0x194070 mov r0, r6
 *   @0x194074 vmrs APSR_nzcv, fpscr
 *   @0x194078 blt 0x194104 <_ZN9CInstance11Assign_PathEifffbi+0x124>
 *   @0x19407c mov r1, #0
 *   @0x194080 bl 0x1a7598 <_ZN5CPath9XPositionEf>
 *   @0x194084 mov r1, #0
 *   @0x194088 mov r5, r0
 *   @0x19408c mov r0, r6
 *   @0x194090 bl 0x1a75c0 <_ZN5CPath9YPositionEf>
 *   @0x194094 mov r1, r5
 *   @0x194098 mov r2, r0
 *   @0x19409c mov r0, r4
 *   @0x1940a0 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1940a4 mov r1, #0
 *   @0x1940a8 mov r0, r6
 *   @0x1940ac bl 0x1a7598 <_ZN5CPath9XPositionEf>
 *   @0x1940b0 mov r1, #0
 *   @0x1940b4 str r0, [r4, #0x144]
 *   @0x1940b8 mov r0, r6
 *   @0x1940bc bl 0x1a75c0 <_ZN5CPath9YPositionEf>
 *   @0x1940c0 str r0, [r4, #0x148]
 *   @0x1940c4 vpop {d8}
 *   @0x1940c8 pop {r4, r5, r6, pc}
 *   @0x1940cc vpop {d8}
 *   @0x1940d0 mvn r3, #0
 *   @0x1940d4 str r3, [r4, #0x128]
 *   @0x1940d8 pop {r4, r5, r6, pc}
 *   @0x1940dc vpop {d8}
 *   @0x1940e0 ldr r2, [r4, #0xb4]
 *   @0x1940e4 ldr r3, [r4, #0xb8]
 *   @0x1940e8 str r2, [r4, #0x144]
 *   @0x1940ec str r3, [r4, #0x148]
 *   @0x1940f0 pop {r4, r5, r6, pc}
 *   @0x1940f4 mov r2, #1065353216
 *   @0x1940f8 str r2, [r4, #0x12c]
 *   @0x1940fc mov r3, r2
 *   @0x194100 b 0x194040 <_ZN9CInstance11Assign_PathEifffbi+0x60>
 *   @0x194104 mov r1, #1065353216
 *   @0x194108 bl 0x1a7598 <_ZN5CPath9XPositionEf>
 *   @0x19410c mov r1, #1065353216
 *   @0x194110 mov r5, r0
 *   @0x194114 mov r0, r6
 *   @0x194118 b 0x194090 <_ZN9CInstance11Assign_PathEifffbi+0xb0>
 *
 * ══ §59/94 Variable_Global_Serialise(IBuffer*)  0x1f4a28  size 316  79 条（0x1f4a28..0x1f4b64）
 * @func 0x1f4a28 0x1f4b64  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_Global_Serialise(IBuffer*)+0x88 / RValue::Serialise(IBuffer*) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x38×3 / 0x30×3 / 0x8×3 / 0x4×2 / 0x120×1 / 0xdc×1 / 0xa8×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f4a28 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1f4a2c add r7, r0, #44
 *   @0x1f4a30 ldr r8, [pc, #0x120]
 *   @0x1f4a34 mov r6, r0
 *   @0x1f4a38 ldr r3, [r0]
 *   @0x1f4a3c mov r9, #0
 *   @0x1f4a40 ldr r8, [pc, r8]
 *   @0x1f4a44 vldr s15, [r8]
 *   @0x1f4a48 vcvt.f64.s32 d7, s15
 *   @0x1f4a4c str r9, [r0, #0x38]
 *   @0x1f4a50 mov r2, r7
 *   @0x1f4a54 mov r1, #6
 *   @0x1f4a58 vmov r4, r5, d7
 *   @0x1f4a5c vstr s14, [r6, #44]
 *   @0x1f4a60 str r5, [r6, #0x30]
 *   @0x1f4a64 ldr r3, [r3, #0x8]
 *   @0x1f4a68 blx r3
 *   @0x1f4a6c ldr r3, [r8]
 *   @0x1f4a70 cmp r3, r9
 *   @0x1f4a74 ble 0x1f4ab0 <_Z25Variable_Global_SerialiseP7IBuffer+0x88>
 *   @0x1f4a78 ldr r5, [pc, #0xdc]
 *   @0x1f4a7c mov r4, r9
 *   @0x1f4a80 ldr r5, [pc, r5]
 *   @0x1f4a84 ldr r2, [r5]
 *   @0x1f4a88 ldr r3, [r2, #0x4]
 *   @0x1f4a8c cmp r3, #0
 *   @0x1f4a90 add r0, r3, r4, lsl #4
 *   @0x1f4a94 beq 0x1f4b48 <_Z25Variable_Global_SerialiseP7IBuffer+0x120>
 *   @0x1f4a98 mov r1, r6
 *   @0x1f4a9c add r4, r4, #1
 *   @0x1f4aa0 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer>
 *   @0x1f4aa4 ldr r3, [r8]
 *   @0x1f4aa8 cmp r3, r4
 *   @0x1f4aac bgt 0x1f4a84 <_Z25Variable_Global_SerialiseP7IBuffer+0x5c>
 *   @0x1f4ab0 ldr r9, [pc, #0xa8]
 *   @0x1f4ab4 mov r8, #0
 *   @0x1f4ab8 ldr r3, [r6]
 *   @0x1f4abc mov r0, r6
 *   @0x1f4ac0 ldr r9, [pc, r9]
 *   @0x1f4ac4 vldr s15, [r9]
 *   @0x1f4ac8 vcvt.f64.s32 d7, s15
 *   @0x1f4acc str r8, [r6, #0x38]
 *   @0x1f4ad0 mov r1, #6
 *   @0x1f4ad4 mov r2, r7
 *   @0x1f4ad8 vmov r4, r5, d7
 *   @0x1f4adc vstr s14, [r6, #44]
 *   @0x1f4ae0 str r5, [r6, #0x30]
 *   @0x1f4ae4 ldr r3, [r3, #0x8]
 *   @0x1f4ae8 blx r3
 *   @0x1f4aec ldr r3, [r9]
 *   @0x1f4af0 cmp r3, r8
 *   @0x1f4af4 pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f4af8 mov r10, r8
 *   @0x1f4afc ldr r12, [r9, #0x4]
 *   @0x1f4b00 mov r0, r6
 *   @0x1f4b04 ldr r3, [r6]
 *   @0x1f4b08 mov r1, #6
 *   @0x1f4b0c mov r2, r7
 *   @0x1f4b10 ldrb r4, [r12, r8]
 *   @0x1f4b14 add r8, r8, #1
 *   @0x1f4b18 str r10, [r6, #0x38]
 *   @0x1f4b1c vmov s15, r4
 *   @0x1f4b20 vcvt.f64.u32 d7, s15
 *   @0x1f4b24 vmov r4, r5, d7
 *   @0x1f4b28 vstr s14, [r6, #44]
 *   @0x1f4b2c str r5, [r6, #0x30]
 *   @0x1f4b30 ldr r3, [r3, #0x8]
 *   @0x1f4b34 blx r3
 *   @0x1f4b38 ldr r3, [r9]
 *   @0x1f4b3c cmp r3, r8
 *   @0x1f4b40 bgt 0x1f4afc <_Z25Variable_Global_SerialiseP7IBuffer+0xd4>
 *   @0x1f4b44 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f4b48 mov r0, r2
 *   @0x1f4b4c mov r1, r4
 *   @0x1f4b50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f4b54 b 0x1f4a98 <_Z25Variable_Global_SerialiseP7IBuffer+0x70>
 *   @0x1f4b58 andseq r9, pc, r8, asr #5
 *   @0x1f4b5c andseq r9, pc, r4, lsr r1
 *   @0x1f4b60 andseq r12, pc, r8, ror #6
 *
 * ══ §60/94 ov_bitrate  0x2314dc  size 316  79 条（0x2314dc..0x231618）
 * @func 0x2314dc 0x231618  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_bitrate+0x68×2 / ov_bitrate+0x48 / ov_bitrate+0xfc / ov_bitrate+0xf0 / ov_time_total / anon_319414
 * 字段偏移 top8: 0x38×2 / 0x3c×2 / 0x58×1 / 0x34×1 / 0x4×1 / 0x48×1 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2314dc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2314e0 ldr r3, [r0, #0x58]
 *   @0x2314e4 cmp r3, #1
 *   @0x2314e8 ble 0x231544 <ov_bitrate+0x68>
 *   @0x2314ec ldr r2, [r0, #0x34]
 *   @0x2314f0 cmp r2, r1
 *   @0x2314f4 ble 0x231544 <ov_bitrate+0x68>
 *   @0x2314f8 ldr r3, [r0, #0x4]
 *   @0x2314fc cmp r3, #0
 *   @0x231500 bne 0x23154c <ov_bitrate+0x70>
 *   @0x231504 cmp r1, #0
 *   @0x231508 mov r1, r3
 *   @0x23150c bne 0x2314f0 <ov_bitrate+0x14>
 *   @0x231510 ldr r3, [r0, #0x48]
 *   @0x231514 ldr r0, [r3, #0x10]
 *   @0x231518 cmp r0, #0
 *   @0x23151c ble 0x231524 <ov_bitrate+0x48>
 *   @0x231520 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x231524 ldr r0, [r3, #0xc]
 *   @0x231528 cmp r0, #0
 *   @0x23152c ble 0x2315d8 <ov_bitrate+0xfc>
 *   @0x231530 ldr r3, [r3, #0x14]
 *   @0x231534 cmp r3, #0
 *   @0x231538 addgt r0, r0, r3
 *   @0x23153c asrgt r0, r0, #1
 *   @0x231540 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x231544 mvn r0, #130
 *   @0x231548 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23154c cmp r1, #0
 *   @0x231550 bge 0x2315e0 <ov_bitrate+0x104>
 *   @0x231554 cmp r2, #0
 *   @0x231558 ble 0x2315cc <ov_bitrate+0xf0>
 *   @0x23155c ldr r1, [r0, #0x38]
 *   @0x231560 mov r6, #0
 *   @0x231564 ldr r12, [r0, #0x3c]
 *   @0x231568 mov r7, #0
 *   @0x23156c add lr, r1, r2, lsl #3
 *   @0x231570 sub r12, r12, #8
 *   @0x231574 ldrd r2, r3, [r1, #8]!
 *   @0x231578 ldrd r8, r9, [r12, #8]!
 *   @0x23157c subs r2, r2, r8
 *   @0x231580 sbc r3, r3, r9
 *   @0x231584 lsl r5, r3, #3
 *   @0x231588 lsl r4, r2, #3
 *   @0x23158c adds r6, r6, r4
 *   @0x231590 orr r5, r5, r2, lsr #29
 *   @0x231594 adc r7, r7, r5
 *   @0x231598 cmp r1, lr
 *   @0x23159c bne 0x231574 <ov_bitrate+0x98>
 *   @0x2315a0 mov r3, #1000
 *   @0x2315a4 umull r4, r5, r6, r3
 *   @0x2315a8 mla r5, r3, r7, r5
 *   @0x2315ac mvn r1, #0
 *   @0x2315b0 bl 0x231424 <ov_time_total>
 *   @0x2315b4 mov r2, r0
 *   @0x2315b8 mov r3, r1
 *   @0x2315bc mov r0, r4
 *   @0x2315c0 mov r1, r5
 *   @0x2315c4 bl 0x319414 <__aeabi_ldivmod>
 *   @0x2315c8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2315cc mov r4, #0
 *   @0x2315d0 mov r5, #0
 *   @0x2315d4 b 0x2315ac <ov_bitrate+0xd0>
 *   @0x2315d8 mvn r0, #0
 *   @0x2315dc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2315e0 add r3, r1, #1
 *   @0x2315e4 ldr lr, [r0, #0x3c]
 *   @0x2315e8 ldr r2, [r0, #0x38]
 *   @0x2315ec mov r12, #8000
 *   @0x2315f0 lsl r3, r3, #3
 *   @0x2315f4 add lr, lr, r3
 *   @0x2315f8 add r2, r2, r3
 *   @0x2315fc ldrd r4, r5, [lr, #-8]
 *   @0x231600 ldrd r2, r3, [r2]
 *   @0x231604 subs r2, r2, r4
 *   @0x231608 sbc r3, r3, r5
 *   @0x23160c umull r4, r5, r2, r12
 *   @0x231610 mla r5, r12, r3, r5
 *   @0x231614 b 0x2315b0 <ov_bitrate+0xd4>
 *
 * ══ §61/94 JS_Global_parseFloat(RValue&, CInstance*, CInstance*, int, RValue*)  0x255030  size 316  79 条（0x255030..0x25516c）
 * @func 0x255030 0x25516c  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*) / JS_isWhitespace(int) / 0xb6658 / 0xb6bf8 / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x30×1 / 0x10×1 / 0x14×1 / 0x8×1 / 0x18×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255030 cmp r3, #0
 *   @0x255034 push {r4, r5, r6, r7, lr}
 *   @0x255038 mov r7, r0
 *   @0x25503c sub sp, sp, #28
 *   @0x255040 bne 0x25505c <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x255044 str r3, [r0, #0xc]
 *   @0x255048 mvn r2, #0
 *   @0x25504c mvn r3, #-2147483648
 *   @0x255050 stm r0, {r2, r3}
 *   @0x255054 add sp, sp, #28
 *   @0x255058 pop {r4, r5, r6, r7, pc}
 *   @0x25505c add r0, sp, #8
 *   @0x255060 ldr r1, [sp, #0x30]
 *   @0x255064 mov r2, #0
 *   @0x255068 mov r3, #0
 *   @0x25506c mov r12, #0
 *   @0x255070 strd r2, r3, [sp, #8]
 *   @0x255074 str r12, [sp, #0x10]
 *   @0x255078 mvn r3, #-16777216
 *   @0x25507c str r3, [sp, #0x14]
 *   @0x255080 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255084 cmp r0, #1
 *   @0x255088 beq 0x255148 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x25508c ldr r3, [sp, #0x8]
 *   @0x255090 ldr r6, [r3]
 *   @0x255094 cmp r6, #0
 *   @0x255098 beq 0x2550c4 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x25509c mov r4, r6
 *   @0x2550a0 mov r6, r4
 *   @0x2550a4 add r4, r4, #1
 *   @0x2550a8 ldrb r0, [r6]
 *   @0x2550ac bl 0x2425ac <_Z15JS_isWhitespacei>
 *   @0x2550b0 cmp r0, #0
 *   @0x2550b4 beq 0x2550c4 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x2550b8 cmp r4, #0
 *   @0x2550bc mov r6, r4
 *   @0x2550c0 bne 0x2550a0 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x2550c4 mov r0, r6
 *   @0x2550c8 add r1, sp, #4
 *   @0x2550cc bl 0xb6658 <strtod@plt>
 *   @0x2550d0 mov r4, r0
 *   @0x2550d4 mov r5, r1
 *   @0x2550d8 bl 0xb6bf8 <__errno@plt>
 *   @0x2550dc ldr r3, [r0]
 *   @0x2550e0 cmp r3, #34
 *   @0x2550e4 beq 0x25510c <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x2550e8 ldr r3, [sp, #0x4]
 *   @0x2550ec cmp r6, r3
 *   @0x2550f0 beq 0x255130 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x2550f4 mov r3, #0
 *   @0x2550f8 str r4, [r7]
 *   @0x2550fc str r5, [r7, #0x4]
 *   @0x255100 str r3, [r7, #0xc]
 *   @0x255104 add sp, sp, #28
 *   @0x255108 pop {r4, r5, r6, r7, pc}
 *   @0x25510c vmov d6, r4, r5
 *   @0x255110 vldr d7, [pc, #64]
 *   @0x255114 vcmpe.f64 d6, d7
 *   @0x255118 vmrs APSR_nzcv, fpscr
 *   @0x25511c bgt 0x255130 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x255120 vldr d7, [pc, #56]
 *   @0x255124 vcmpe.f64 d6, d7
 *   @0x255128 vmrs APSR_nzcv, fpscr
 *   @0x25512c bpl 0x2550e8 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x255130 mov r3, #0
 *   @0x255134 mvn r2, #0
 *   @0x255138 str r3, [r7, #0xc]
 *   @0x25513c mvn r3, #-2147483648
 *   @0x255140 stm r7, {r2, r3}
 *   @0x255144 b 0x255054 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x255148 ldr r0, [pc, #0x18]
 *   @0x25514c add r0, pc, r0
 *   @0x255150 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255154 b 0x255054 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x255158 .word 0xffffffff
 *   @0x25515c svcvc #0xefffff
 *   @0x255160 .word 0xffffffff
 *   @0x255164 .word 0xffefffff
 *   @0x255168 andseq r1, r0, r8, lsl r8
 *
 * ══ §62/94 Java_com_yoyogames_runner_RunnerJNILib_CloudResultData  0x2941a4  size 316  79 条（0x2941a4..0x2942e0）
 * @func 0x2941a4 0x2942e0  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xe8 / 0xb65bc / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x34×3 / 0x20×2 / 0x24×2 / 0x38×2 / 0x2ac×1 / 0x2e0×1 / 0xd8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2941a4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2941a8 mov r6, r2
 *   @0x2941ac mov r9, r3
 *   @0x2941b0 mov r7, r0
 *   @0x2941b4 ldr r5, [sp, #0x20]
 *   @0x2941b8 bl 0x290614 <setJNIEnv>
 *   @0x2941bc cmp r6, #0
 *   @0x2941c0 beq 0x29429c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xf8>
 *   @0x2941c4 ldr r3, [r7]
 *   @0x2941c8 mov r1, r6
 *   @0x2941cc mov r0, r7
 *   @0x2941d0 ldr r3, [r3, #0x2ac]
 *   @0x2941d4 blx r3
 *   @0x2941d8 ldr r3, [r7]
 *   @0x2941dc mov r1, r6
 *   @0x2941e0 mov r2, #0
 *   @0x2941e4 ldr r3, [r3, #0x2e0]
 *   @0x2941e8 mov r8, r0
 *   @0x2941ec mov r0, r7
 *   @0x2941f0 blx r3
 *   @0x2941f4 mov r10, r0
 *   @0x2941f8 ldr r12, [pc, #0xd8]
 *   @0x2941fc ldr r12, [pc, r12]
 *   @0x294200 ldr r4, [r12]
 *   @0x294204 cmp r4, #0
 *   @0x294208 beq 0x294234 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x90>
 *   @0x29420c ldr r3, [r4, #0x24]
 *   @0x294210 cmp r3, r5
 *   @0x294214 bne 0x294228 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x84>
 *   @0x294218 b 0x29425c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xb8>
 *   @0x29421c ldr r12, [r4, #0x24]
 *   @0x294220 cmp r12, r5
 *   @0x294224 beq 0x29425c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xb8>
 *   @0x294228 ldr r4, [r4, #0x4]
 *   @0x29422c cmp r4, #0
 *   @0x294230 bne 0x29421c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x78>
 *   @0x294234 cmp r6, #0
 *   @0x294238 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29423c ldr r12, [r7]
 *   @0x294240 mov r1, r6
 *   @0x294244 mov r2, r10
 *   @0x294248 mov r0, r7
 *   @0x29424c mov r3, #0
 *   @0x294250 ldr r12, [r12, #0x300]
 *   @0x294254 blx r12
 *   @0x294258 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29425c ldr r3, [r4, #0x38]
 *   @0x294260 cmp r8, r3
 *   @0x294264 bgt 0x2942a8 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x104>
 *   @0x294268 cmp r8, #0
 *   @0x29426c mov r3, #7
 *   @0x294270 str r9, [r4, #0x28]
 *   @0x294274 str r3, [r4, #0xc]
 *   @0x294278 ble 0x29428c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xe8>
 *   @0x29427c ldr r0, [r4, #0x34]
 *   @0x294280 mov r1, r10
 *   @0x294284 mov r2, r8
 *   @0x294288 bl 0xb65bc <memcpy@plt>
 *   @0x29428c cmp r6, #0
 *   @0x294290 str r8, [r4, #0x3c]
 *   @0x294294 bne 0x29423c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x98>
 *   @0x294298 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29429c mov r10, r6
 *   @0x2942a0 mov r8, r6
 *   @0x2942a4 b 0x2941f8 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0x54>
 *   @0x2942a8 ldr r0, [r4, #0x34]
 *   @0x2942ac add r5, r8, #1
 *   @0x2942b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2942b4 ldr r1, [pc, #0x20]
 *   @0x2942b8 mov r0, r5
 *   @0x2942bc mov r2, #70
 *   @0x2942c0 add r1, pc, r1
 *   @0x2942c4 mov r3, #1
 *   @0x2942c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2942cc str r5, [r4, #0x38]
 *   @0x2942d0 str r0, [r4, #0x34]
 *   @0x2942d4 b 0x294268 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultData+0xc4>
 *   @0x2942d8 ldrsheq r9, [r5], -r12
 *   @0x2942dc andeq r12, r9, r0, ror sp
 *
 * ══ §63/94 yySocket::ConnectGMS(char*, int)  0x2966ac  size 316  79 条（0x2966ac..0x2967e8）
 * @func 0x2966ac 0x2967e8  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::WaitForData(int, int)×2 / yySocket::Connect(char*, int) / 0xb6574 / yySocket::Write(void*, unsigned int) / yySocket::Close()
 * 字段偏移 top8: 0x50×2 / 0x8×2 / 0x4×2 / 0x3c×2 / 0x108×1 / 0x2e×1 / 0xc8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2966ac push {r4, r5, lr}
 *   @0x2966b0 sub sp, sp, #20
 *   @0x2966b4 mov r4, r0
 *   @0x2966b8 bl 0x295858 <_ZN8yySocket7ConnectEPci>
 *   @0x2966bc cmp r0, #0
 *   @0x2966c0 movne r5, r0
 *   @0x2966c4 bne 0x2966e8 <_ZN8yySocket10ConnectGMSEPci+0x3c>
 *   @0x2966c8 ldr r3, [pc, #0x108]
 *   @0x2966cc ldr r3, [pc, r3]
 *   @0x2966d0 ldrb r3, [r3]
 *   @0x2966d4 cmp r3, #0
 *   @0x2966d8 beq 0x2966f4 <_ZN8yySocket10ConnectGMSEPci+0x48>
 *   @0x2966dc mov r5, r0
 *   @0x2966e0 mov r3, #1
 *   @0x2966e4 strb r3, [r4, #0x2e]
 *   @0x2966e8 mov r0, r5
 *   @0x2966ec add sp, sp, #20
 *   @0x2966f0 pop {r4, r5, pc}
 *   @0x2966f4 mov r0, r4
 *   @0x2966f8 movw r1, #0x1388
 *   @0x2966fc mov r2, #18
 *   @0x296700 bl 0x2962b0 <_ZN8yySocket11WaitForDataEii>
 *   @0x296704 cmp r0, #18
 *   @0x296708 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c>
 *   @0x29670c ldr r0, [pc, #0xc8]
 *   @0x296710 ldr r1, [r4, #0x50]
 *   @0x296714 add r0, pc, r0
 *   @0x296718 bl 0xb6574 <strcmp@plt>
 *   @0x29671c subs r5, r0, #0
 *   @0x296720 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c>
 *   @0x296724 mov r3, #16
 *   @0x296728 mov r1, sp
 *   @0x29672c mov r2, r3
 *   @0x296730 mov r0, r4
 *   @0x296734 str r3, [sp, #0x8]
 *   @0x296738 movw lr, #0xbabe
 *   @0x29673c movw r12, #0xb00b
 *   @0x296740 movt lr, #0xcafe
 *   @0x296744 movt r12, #0xdead
 *   @0x296748 str lr, [sp]
 *   @0x29674c str r12, [sp, #0x4]
 *   @0x296750 bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x296754 movw r1, #0x1388
 *   @0x296758 mov r2, #12
 *   @0x29675c mov r0, r4
 *   @0x296760 bl 0x2962b0 <_ZN8yySocket11WaitForDataEii>
 *   @0x296764 ldr r3, [r4, #0x50]
 *   @0x296768 movw r2, #0xbead
 *   @0x29676c movt r2, #0xdeaf
 *   @0x296770 ldr r1, [r3]
 *   @0x296774 cmp r1, r2
 *   @0x296778 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c>
 *   @0x29677c ldr r1, [r3, #0x4]
 *   @0x296780 movw r2, #0xbeeb
 *   @0x296784 movt r2, #0xf00d
 *   @0x296788 cmp r1, r2
 *   @0x29678c bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c>
 *   @0x296790 ldr r3, [r3, #0x8]
 *   @0x296794 cmp r3, #12
 *   @0x296798 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c>
 *   @0x29679c ldr r3, [pc, #0x3c]
 *   @0x2967a0 ldr r1, [pc, #0x3c]
 *   @0x2967a4 ldr r3, [pc, r3]
 *   @0x2967a8 add r1, pc, r1
 *   @0x2967ac ldr r0, [r3]
 *   @0x2967b0 ldr r3, [r0]
 *   @0x2967b4 ldr r3, [r3, #0xc]
 *   @0x2967b8 blx r3
 *   @0x2967bc mov r0, r5
 *   @0x2967c0 add sp, sp, #20
 *   @0x2967c4 pop {r4, r5, pc}
 *   @0x2967c8 mov r0, r4
 *   @0x2967cc mvn r5, #0
 *   @0x2967d0 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x2967d4 b 0x2966e8 <_ZN8yySocket10ConnectGMSEPci+0x3c>
 *   @0x2967d8 andseq r11, r5, r8, asr #5
 *   @0x2967dc muleq r12, r8, sp
 *   @0x2967e0 andseq r6, r5, r0, ror pc
 *   @0x2967e4 andeq r2, r12, r4, lsr sp
 *
 * ══ §64/94 F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*)  0x298e94  size 316  79 条（0x298e94..0x298fd0）
 * @func 0x298e94 0x298fd0  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocSocket()×2 / YYGetInt32(RValue const*, int) / F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*)+0xd4 / F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*)+0xf8 / operator new(unsigned int) / yySocket::yySocket(eSocketType) / yySocket::Init() / yySocket::AllocateBuffer(int)
 * 字段偏移 top8: 0x4×4 / 0x118×1 / 0xc×1 / 0x18×1 / 0xe0×1 / 0x9c×1 / 0x68×1 / 0x50×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298e94 push {r4, r5, r6, r7, r8, lr}
 *   @0x298e98 mov r2, #0
 *   @0x298e9c ldr r5, [pc, #0x118]
 *   @0x298ea0 mov r3, r2
 *   @0x298ea4 str r2, [r0]
 *   @0x298ea8 movt r3, #0xbff0
 *   @0x298eac ldr r5, [pc, r5]
 *   @0x298eb0 str r2, [r0, #0xc]
 *   @0x298eb4 mov r4, r0
 *   @0x298eb8 str r3, [r0, #0x4]
 *   @0x298ebc ldrb r2, [r5]
 *   @0x298ec0 ldr r6, [sp, #0x18]
 *   @0x298ec4 cmp r2, #0
 *   @0x298ec8 beq 0x298fa0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x298ecc mov r0, r6
 *   @0x298ed0 mov r1, #0
 *   @0x298ed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298ed8 ldr r3, [pc, #0xe0]
 *   @0x298edc ldr r3, [pc, r3]
 *   @0x298ee0 ldr r3, [r3]
 *   @0x298ee4 sub r3, r3, #2
 *   @0x298ee8 cmp r3, #2
 *   @0x298eec mov r5, r0
 *   @0x298ef0 bls 0x298f68 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x298ef4 cmp r0, #0
 *   @0x298ef8 popne {r4, r5, r6, r7, r8, pc}
 *   @0x298efc bl 0x298e28 <_Z11AllocSocketv>
 *   @0x298f00 subs r6, r0, #0
 *   @0x298f04 blt 0x298f8c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x298f08 mov r0, #200
 *   @0x298f0c add r7, r6, r6, lsl #1
 *   @0x298f10 bl 0x27c524 <_Znwj>
 *   @0x298f14 mov r1, r5
 *   @0x298f18 mov r8, r0
 *   @0x298f1c bl 0x2970ac <_ZN8yySocketC2E11eSocketType>
 *   @0x298f20 ldr r3, [pc, #0x9c]
 *   @0x298f24 mov r0, r8
 *   @0x298f28 ldr r3, [pc, r3]
 *   @0x298f2c add r7, r3, r7, lsl #2
 *   @0x298f30 str r8, [r7, #0x4]
 *   @0x298f34 bl 0x294ec8 <_ZN8yySocket4InitEv>
 *   @0x298f38 ldr r0, [r7, #0x4]
 *   @0x298f3c mov r1, #65536
 *   @0x298f40 str r6, [r0, #0x68]
 *   @0x298f44 bl 0x296080 <_ZN8yySocket14AllocateBufferEi>
 *   @0x298f48 cmp r5, #1
 *   @0x298f4c cmpne r5, #4
 *   @0x298f50 beq 0x298fb0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x298f54 vmov s15, r6
 *   @0x298f58 vcvt.f64.s32 d7, s15
 *   @0x298f5c vmov r2, r3, d7
 *   @0x298f60 stm r4, {r2, r3}
 *   @0x298f64 pop {r4, r5, r6, r7, r8, pc}
 *   @0x298f68 cmp r0, #2
 *   @0x298f6c bne 0x298efc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x298f70 ldr r0, [pc, #0x50]
 *   @0x298f74 mov r1, #0
 *   @0x298f78 add r0, pc, r0
 *   @0x298f7c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x298f80 bl 0x298e28 <_Z11AllocSocketv>
 *   @0x298f84 subs r6, r0, #0
 *   @0x298f88 bge 0x298f08 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x298f8c ldr r0, [pc, #0x38]
 *   @0x298f90 mov r1, #0
 *   @0x298f94 pop {r4, r5, r6, r7, r8, lr}
 *   @0x298f98 add r0, pc, r0
 *   @0x298f9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x298fa0 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x298fa4 mov r3, #1
 *   @0x298fa8 strb r3, [r5]
 *   @0x298fac b 0x298ecc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x298fb0 ldr r0, [r7, #0x4]
 *   @0x298fb4 bl 0x295fec <_ZN8yySocket12CreateSocketEv>
 *   @0x298fb8 b 0x298f54 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x298fbc ldrsheq r8, [r5], -r0
 *   @0x298fc0 andseq r7, r5, r4, asr #8
 *   @0x298fc4 andseq r8, r5, r12, ror r10
 *   @0x298fc8 andeq r0, r12, r12, asr #14
 *   @0x298fcc andeq r0, r12, r4, asr r7
 *
 * ══ §65/94 void std::__adjust_heap<b2Pair*, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, int, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&))  0x2c7fe0  size 316  79 条（0x2c7fe0..0x2c811c）
 * @func 0x2c7fe0 0x2c811c  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7fe0 sub sp, sp, #8
 *   @0x2c7fe4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c7fe8 add r4, r1, #1
 *   @0x2c7fec sub sp, sp, #12
 *   @0x2c7ff0 mov r9, r1
 *   @0x2c7ff4 lsl r4, r4, #1
 *   @0x2c7ff8 mov r8, r2
 *   @0x2c7ffc cmp r4, r2
 *   @0x2c8000 str r3, [sp, #0x34]
 *   @0x2c8004 mov r5, r0
 *   @0x2c8008 ldr r7, [sp, #0x3c]
 *   @0x2c800c movge r12, r4
 *   @0x2c8010 addge r3, r0, r1, lsl #3
 *   @0x2c8014 movge r4, r1
 *   @0x2c8018 bge 0x2c8074 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x94>
 *   @0x2c801c mov r10, r1
 *   @0x2c8020 b 0x2c8028 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x48>
 *   @0x2c8024 mov r4, r12
 *   @0x2c8028 lsl r0, r4, #3
 *   @0x2c802c sub r6, r0, #8
 *   @0x2c8030 add r11, r5, r0
 *   @0x2c8034 add r6, r5, r6
 *   @0x2c8038 mov r0, r11
 *   @0x2c803c mov r1, r6
 *   @0x2c8040 blx r7
 *   @0x2c8044 mov r3, r6
 *   @0x2c8048 add r6, r5, r10, lsl #3
 *   @0x2c804c cmp r0, #0
 *   @0x2c8050 subne r4, r4, #1
 *   @0x2c8054 add r12, r4, #1
 *   @0x2c8058 moveq r3, r11
 *   @0x2c805c ldm r3, {r0, r1}
 *   @0x2c8060 mov r10, r4
 *   @0x2c8064 lsl r12, r12, #1
 *   @0x2c8068 cmp r8, r12
 *   @0x2c806c stm r6, {r0, r1}
 *   @0x2c8070 bgt 0x2c8024 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x44>
 *   @0x2c8074 cmp r12, r8
 *   @0x2c8078 bne 0x2c8094 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xb4>
 *   @0x2c807c sub r2, r12, #-536870911
 *   @0x2c8080 sub r4, r12, #1
 *   @0x2c8084 add r2, r5, r2, lsl #3
 *   @0x2c8088 ldm r2, {r0, r1}
 *   @0x2c808c stm r3, {r0, r1}
 *   @0x2c8090 mov r3, r2
 *   @0x2c8094 add r2, sp, #52
 *   @0x2c8098 cmp r4, r9
 *   @0x2c809c mov r6, sp
 *   @0x2c80a0 ldm r2, {r0, r1}
 *   @0x2c80a4 stm sp, {r0, r1}
 *   @0x2c80a8 bgt 0x2c80c4 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xe4>
 *   @0x2c80ac ldm r6, {r0, r1}
 *   @0x2c80b0 stm r3, {r0, r1}
 *   @0x2c80b4 add sp, sp, #12
 *   @0x2c80b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c80bc add sp, sp, #8
 *   @0x2c80c0 bx lr
 *   @0x2c80c4 sub r10, r4, #1
 *   @0x2c80c8 add r10, r10, r10, lsr #31
 *   @0x2c80cc asr r10, r10, #1
 *   @0x2c80d0 add r8, r5, r10, lsl #3
 *   @0x2c80d4 mov r1, sp
 *   @0x2c80d8 mov r0, r8
 *   @0x2c80dc blx r7
 *   @0x2c80e0 sub r3, r10, #1
 *   @0x2c80e4 add r2, r5, r4, lsl #3
 *   @0x2c80e8 add r3, r3, r3, lsr #31
 *   @0x2c80ec asr r3, r3, #1
 *   @0x2c80f0 cmp r0, #0
 *   @0x2c80f4 moveq r3, r2
 *   @0x2c80f8 beq 0x2c80ac <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xcc>
 *   @0x2c80fc ldm r8, {r0, r1}
 *   @0x2c8100 cmp r9, r10
 *   @0x2c8104 stm r2, {r0, r1}
 *   @0x2c8108 movge r3, r8
 *   @0x2c810c bge 0x2c80ac <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xcc>
 *   @0x2c8110 mov r4, r10
 *   @0x2c8114 mov r10, r3
 *   @0x2c8118 b 0x2c80d0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xf0>
 *
 * ══ §66/94 b2EPCollider::ComputePolygonSeparation()  0x2dd224  size 316  79 条（0x2dd224..0x2dd360）
 * @func 0x2dd224 0x2dd360  size 316  79 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2EPCollider::ComputePolygonSeparation()+0x11c / b2EPCollider::ComputePolygonSeparation()+0x58
 * 字段偏移 top8: 0x4×2 / 0x80×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dd224 ldr r12, [r1, #0x80]
 *   @0x2dd228 vldr s8, [r1, #216]
 *   @0x2dd22c push {r4, r5}
 *   @0x2dd230 vldr s0, [pc, #288]
 *   @0x2dd234 mov r4, #0
 *   @0x2dd238 vstr s0, [r0, #8]
 *   @0x2dd23c cmp r12, r4
 *   @0x2dd240 mvn r5, #0
 *   @0x2dd244 vneg.f32 s2, s8
 *   @0x2dd248 str r4, [r0]
 *   @0x2dd24c str r5, [r0, #0x4]
 *   @0x2dd250 vldr s10, [r1, #212]
 *   @0x2dd254 ble 0x2dd340 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x11c>
 *   @0x2dd258 add r3, r1, #64
 *   @0x2dd25c mov r2, r4
 *   @0x2dd260 vldr s3, [r1, #244]
 *   @0x2dd264 vldr s4, [r1, #164]
 *   @0x2dd268 vldr s5, [r1, #168]
 *   @0x2dd26c vldr s6, [r1, #172]
 *   @0x2dd270 vldr s7, [r1, #176]
 *   @0x2dd274 vldr s1, [pc, #224]
 *   @0x2dd278 b 0x2dd2e0 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0xbc>
 *   @0x2dd27c vmul.f32 s11, s10, s12
 *   @0x2dd280 vmla.f32 s11, s2, s13
 *   @0x2dd284 vcmpe.f32 s11, #0
 *   @0x2dd288 vmrs APSR_nzcv, fpscr
 *   @0x2dd28c vldrge s14, [r1, #240]
 *   @0x2dd290 vldrlt s14, [r1, #232]
 *   @0x2dd294 vsubge.f32 s12, s12, s14
 *   @0x2dd298 vldrge s14, [r1, #236]
 *   @0x2dd29c vsublt.f32 s12, s12, s14
 *   @0x2dd2a0 vldrlt s14, [r1, #228]
 *   @0x2dd2a4 vmul.f32 s12, s8, s12
 *   @0x2dd2a8 vsub.f32 s13, s13, s14
 *   @0x2dd2ac vmla.f32 s12, s10, s13
 *   @0x2dd2b0 vcmpe.f32 s12, s1
 *   @0x2dd2b4 vmrs APSR_nzcv, fpscr
 *   @0x2dd2b8 bmi 0x2dd2d0 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0xac>
 *   @0x2dd2bc vcmpe.f32 s0, s15
 *   @0x2dd2c0 vmrs APSR_nzcv, fpscr
 *   @0x2dd2c4 vmovmi.f32 s0, s15
 *   @0x2dd2c8 movmi r4, #2
 *   @0x2dd2cc movmi r5, r2
 *   @0x2dd2d0 add r2, r2, #1
 *   @0x2dd2d4 add r3, r3, #8
 *   @0x2dd2d8 cmp r2, r12
 *   @0x2dd2dc beq 0x2dd348 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x124>
 *   @0x2dd2e0 vldr s15, [r3, #-60]
 *   @0x2dd2e4 vsub.f32 s14, s15, s5
 *   @0x2dd2e8 vldr s12, [r3, #4]
 *   @0x2dd2ec vldr s11, [r3, #-64]
 *   @0x2dd2f0 vldr s13, [r3]
 *   @0x2dd2f4 vsub.f32 s15, s15, s7
 *   @0x2dd2f8 vneg.f32 s12, s12
 *   @0x2dd2fc vmul.f32 s14, s12, s14
 *   @0x2dd300 vmul.f32 s15, s12, s15
 *   @0x2dd304 vsub.f32 s9, s11, s4
 *   @0x2dd308 vsub.f32 s11, s11, s6
 *   @0x2dd30c vneg.f32 s13, s13
 *   @0x2dd310 vmla.f32 s14, s13, s9
 *   @0x2dd314 vmla.f32 s15, s13, s11
 *   @0x2dd318 vcmpe.f32 s14, s15
 *   @0x2dd31c vmrs APSR_nzcv, fpscr
 *   @0x2dd320 vmovmi.f32 s15, s14
 *   @0x2dd324 vcmpe.f32 s15, s3
 *   @0x2dd328 vmrs APSR_nzcv, fpscr
 *   @0x2dd32c ble 0x2dd27c <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x58>
 *   @0x2dd330 mov r3, #2
 *   @0x2dd334 str r2, [r0, #0x4]
 *   @0x2dd338 vstr s15, [r0, #8]
 *   @0x2dd33c str r3, [r0]
 *   @0x2dd340 pop {r4, r5}
 *   @0x2dd344 bx lr
 *   @0x2dd348 stm r0, {r4, r5}
 *   @0x2dd34c vstr s0, [r0, #8]
 *   @0x2dd350 pop {r4, r5}
 *   @0x2dd354 bx lr
 *   @0x2dd358 .word 0xff7fffff
 *   @0x2dd35c vstrlt s30, [lr, #-216]
 *
 * ══ §67/94 FT_Stream_ReadFields  0x2e7ed4  size 316  79 条（0x2e7ed4..0x2e8010）
 * @func 0x2e7ed4 0x2e8010  size 316  79 条
 * 部分覆盖: 本节 79/142 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc / FT_Stream_ExitFrame
 * 字段偏移 top8: 0x20×3 / 0x14×2 / 0x-2×2 / 0x1×2 / 0x3×2 / 0x-4×1 / 0x-3×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7ed4 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e7ed8 mov r6, r0
 *   @0x2e7edc cmp r1, #0x0
 *   @0x2e7ee0 stmdahs r0, {r1, r2, r3, r7, pc}
 *   @0x2e7ee4 beq.w 0x2e8004 <FT_Stream_ReadFields+0x130>
 *   @0x2e7ee8 ldr r3, [r0, #0x20]
 *   @0x2e7eec mov.w r8, #0x0
 *   @0x2e7ef0 ldrb r0, [r5, #-4]
 *   @0x2e7ef4 subs r2, r0, #0x4
 *   @0x2e7ef8 bhi 0x2e7fc0 <FT_Stream_ReadFields+0xec>
 *   @0x2e7efc mrsvs pc, apsr
 *   @0x2e7f00 str r1, [r4, #0x14]
 *   @0x2e7f04 str r1, [r4, #0x14]
 *   @0x2e7f08 adds r0, #0x30
 *   @0x2e7f0c adcs r1, r0
 *   @0x2e7f10 ldrsb r6, [r2, r1]
 *   @0x2e7f14 mov r0, r6
 *   @0x2e7f18 .word 0xf7ff1c02
 *   @0x2e7f1c strmi pc, [r4], -r2, lsl #31
 *   @0x2e7f20 cmp r0, #0x0
 *   @0x2e7f24 ldr r4, [r6, #0x20]
 *   @0x2e7f28 strlo r0, [r4, #-0x801]
 *   @0x2e7f2c mov r3, r4
 *   @0x2e7f30 ldrb r2, [r5, #-3]
 *   @0x2e7f34 ldr r1, [r6, #0x24]
 *   @0x2e7f38 cmp r4, r1
 *   @0x2e7f3c cmp r0, #0x18
 *   @0x2e7f40 ldrh r0, [r5, #-2]
 *   @0x2e7f44 mov r1, r3
 *   @0x2e7f48 blx 0xb65bc <memcpy@plt>
 *   @0x2e7f4c b 0x2e7f2a <FT_Stream_ReadFields+0x56>
 *   @0x2e7f50 movs r1, #0x18
 *   @0x2e7f54 b 0x2e7fc6 <FT_Stream_ReadFields+0xf2>
 *   @0x2e7f58 ldrb r2, [r3]
 *   @0x2e7f5c b 0x2e7f64 <FT_Stream_ReadFields+0x90>
 *   @0x2e7f60 ldrb r2, [r3, #0x1]
 *   @0x2e7f64 orr.w r3, r3, r2, lsl #8
 *   @0x2e7f68 movs r1, #0x10
 *   @0x2e7f6c ldrb r2, [r3, #0x1]
 *   @0x2e7f70 ldrb r1, [r3]
 *   @0x2e7f74 orr.w r2, r2, r1, lsl #24
 *   @0x2e7f78 ldrb r1, [r3, #0x3]
 *   @0x2e7f7c orrs r2, r1
 *   @0x2e7f80 ldrb r2, [r3, #0x2]
 *   @0x2e7f84 ldrb r1, [r3, #0x3]
 *   @0x2e7f88 orr.w r2, r2, r1, lsl #24
 *   @0x2e7f8c ldrb r1, [r3]
 *   @0x2e7f90 orrs r2, r1
 *   @0x2e7f94 .word 0x21002303
 *   @0x2e7f98 b 0x2e7fc6 <FT_Stream_ReadFields+0xf2>
 *   @0x2e7f9c adds r4, r3, #0x3
 *   @0x2e7fa0 lsls r1, r1, #0x8
 *   @0x2e7fa4 ldmvc r10, {r1, r8, lr}
 *   @0x2e7fa8 b 0x2e7fb8 <FT_Stream_ReadFields+0xe4>
 *   @0x2e7fac adds r4, r3, #0x3
 *   @0x2e7fb0 lsls r1, r1, #0x8
 *   @0x2e7fb4 ldmdavc r10, {r1, r8, lr}
 *   @0x2e7fb8 orr.w r3, r1, r2
 *   @0x2e7fbc movs r1, #0x8
 *   @0x2e7fc0 str r3, [r6, #0x20]
 *   @0x2e7fc4 b 0x2e7ff0 <FT_Stream_ReadFields+0x11c>
 *   @0x2e7fc8 ldrh r2, [r5, #-2]
 *   @0x2e7fcc itt mi
 *   @0x2e7fd0 asrmi r3, r1
 *   @0x2e7fd4 stmdbhs r2, {r0, r1, r10, r11, r12}
 *   @0x2e7fd8 beq 0x2e7fe6 <FT_Stream_ReadFields+0x112>
 *   @0x2e7fdc beq 0x2e7fea <FT_Stream_ReadFields+0x116>
 *   @0x2e7fe0 bne 0x2e7fea <FT_Stream_ReadFields+0x116>
 *   @0x2e7fe4 b 0x2e7f2a <FT_Stream_ReadFields+0x56>
 *   @0x2e7fe8 b 0x2e7f2a <FT_Stream_ReadFields+0x56>
 *   @0x2e7fec b 0x2e7f2a <FT_Stream_ReadFields+0x56>
 *   @0x2e7ff0 cmp.w r8, #0x0
 *   @0x2e7ff4 beq 0x2e800a <FT_Stream_ReadFields+0x136>
 *   @0x2e7ff8 bl 0x2e7eb8 <FT_Stream_ExitFrame>
 *   @0x2e7ffc b 0x2e800a <FT_Stream_ReadFields+0x136>
 *   @0x2e8000 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e8004 movs r0, #0x28
 *   @0x2e8008 qsub8mi r8, r0, r0
 *   @0x2e800c pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §68/94 F_SkeletonDrawTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d57c  size 312  78 条（0x11d57c..0x11d6b4）
 * @func 0x11d57c 0x11d6b4  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int)×2 / Sprite_Data(int) / CSkeletonSprite::DrawTime(char const*, char const*, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×2 / 0x58×2 / 0x24×2 / 0x28×2 / 0x2c×2 / 0x74×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d57c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11d580 sub sp, sp, #52
 *   @0x11d584 mov r1, #0
 *   @0x11d588 str r1, [r0, #0xc]
 *   @0x11d58c ldr r4, [sp, #0x58]
 *   @0x11d590 mov r3, r1
 *   @0x11d594 movt r3, #0xbff0
 *   @0x11d598 stm r0, {r1, r3}
 *   @0x11d59c mov r0, r4
 *   @0x11d5a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d5a4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11d5a8 subs r3, r0, #0
 *   @0x11d5ac beq 0x11d5bc <_Z18F_SkeletonDrawTimeR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11d5b0 ldr r5, [r3, #0x74]
 *   @0x11d5b4 cmp r5, #2
 *   @0x11d5b8 beq 0x11d5c4 <_Z18F_SkeletonDrawTimeR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x11d5bc add sp, sp, #52
 *   @0x11d5c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d5c4 mov r0, r4
 *   @0x11d5c8 mov r1, #1
 *   @0x11d5cc ldr r6, [r3, #0x58]
 *   @0x11d5d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d5d4 mov r1, r5
 *   @0x11d5d8 mov r8, r0
 *   @0x11d5dc mov r0, r4
 *   @0x11d5e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d5e4 mov r1, #3
 *   @0x11d5e8 mov r7, r0
 *   @0x11d5ec mov r0, r4
 *   @0x11d5f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d5f4 mov r1, #4
 *   @0x11d5f8 mov r5, r0
 *   @0x11d5fc mov r0, r4
 *   @0x11d600 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d604 mov r1, #5
 *   @0x11d608 mov r12, r0
 *   @0x11d60c mov r0, r4
 *   @0x11d610 str r12, [sp, #0x24]
 *   @0x11d614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d618 mov r1, #6
 *   @0x11d61c mov r2, r0
 *   @0x11d620 mov r0, r4
 *   @0x11d624 str r2, [sp, #0x28]
 *   @0x11d628 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d62c mov r1, #7
 *   @0x11d630 mov r3, r0
 *   @0x11d634 mov r0, r4
 *   @0x11d638 str r3, [sp, #0x2c]
 *   @0x11d63c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d640 mov r1, #8
 *   @0x11d644 mov r11, r0
 *   @0x11d648 mov r0, r4
 *   @0x11d64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d650 mov r1, #9
 *   @0x11d654 mov r10, r0
 *   @0x11d658 mov r0, r4
 *   @0x11d65c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d660 mov r1, #10
 *   @0x11d664 mov r9, r0
 *   @0x11d668 mov r0, r4
 *   @0x11d66c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d670 ldr r2, [sp, #0x28]
 *   @0x11d674 ldr r3, [sp, #0x2c]
 *   @0x11d678 mov r1, r8
 *   @0x11d67c ldr r12, [sp, #0x24]
 *   @0x11d680 str r2, [sp, #0x4]
 *   @0x11d684 mov r2, r7
 *   @0x11d688 str r3, [sp, #0x8]
 *   @0x11d68c mov r3, r5
 *   @0x11d690 str r12, [sp]
 *   @0x11d694 str r11, [sp, #0xc]
 *   @0x11d698 str r10, [sp, #0x10]
 *   @0x11d69c str r9, [sp, #0x14]
 *   @0x11d6a0 str r0, [sp, #0x18]
 *   @0x11d6a4 mov r0, r6
 *   @0x11d6a8 bl 0xbeb24 <_ZN15CSkeletonSprite8DrawTimeEPKcS1_ffffffjf>
 *   @0x11d6ac add sp, sp, #52
 *   @0x11d6b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §69/94 F_SpritePrefetch(RValue&, CInstance*, CInstance*, int, RValue*)  0x12edf4  size 312  78 条（0x12edf4..0x12ef2c）
 * @func 0x12edf4 0x12ef2c  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x12ee48→0x48ffec, 0x12eec8→0x3eb70c, 0x12eef0→0x3eb70c
 * 调用序列: Graphics::PrefetchTexture(void*)×2 / YYGetInt32(RValue const*, int) / Sprite_Data(int) / F_SpritePrefetch(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4 / CSprite::GetTexture(int)
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x18×2 / 0x2×2 / 0x28×2 / 0xf0×1 / 0x74×1 / 0xcc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12edf4 push {r4, r5, r6, r7, r8, lr}
 *   @0x12edf8 mov r1, #0
 *   @0x12edfc mov r3, r1
 *   @0x12ee00 str r1, [r0, #0xc]
 *   @0x12ee04 movt r3, #0xbff0
 *   @0x12ee08 mov r8, r0
 *   @0x12ee0c stm r0, {r1, r3}
 *   @0x12ee10 ldr r0, [sp, #0x18]
 *   @0x12ee14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ee18 mov r5, r0
 *   @0x12ee1c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12ee20 ldr r3, [pc, #0xf0]
 *   @0x12ee24 add r3, pc, r3
 *   @0x12ee28 subs r6, r0, #0
 *   @0x12ee2c beq 0x12eef0 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x12ee30 ldr r4, [r6, #0x74]
 *   @0x12ee34 cmp r4, #0
 *   @0x12ee38 bne 0x12eec8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x12ee3c ldr r7, [r6, #0x18]
 *   @0x12ee40 cmp r7, #0
 *   @0x12ee44 ble 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12ee48 ldr r2, [pc, #0xcc]
 *   @0x12ee4c ldr r5, [r3, r2]
 *   @0x12ee50 b 0x12ee7c <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x12ee54 cmn r0, #1
 *   @0x12ee58 beq 0x12ee94 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x12ee5c ldrsh r2, [r0, #20]
 *   @0x12ee60 ldr r3, [r5, #0x4]
 *   @0x12ee64 ldr r3, [r3, r2, lsl #2]
 *   @0x12ee68 ldr r0, [r3]
 *   @0x12ee6c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12ee70 add r4, r4, #1
 *   @0x12ee74 cmp r4, r7
 *   @0x12ee78 beq 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12ee7c mov r0, r6
 *   @0x12ee80 mov r1, r4
 *   @0x12ee84 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x12ee88 ldr r3, [r5]
 *   @0x12ee8c cmp r0, r3
 *   @0x12ee90 bhi 0x12ee54 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x12ee94 ldr r3, [r5, #0x4]
 *   @0x12ee98 ldr r3, [r3, r0, lsl #2]
 *   @0x12ee9c cmp r3, #0
 *   @0x12eea0 beq 0x12ee70 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x12eea4 ldr r0, [r3]
 *   @0x12eea8 add r4, r4, #1
 *   @0x12eeac bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12eeb0 cmp r4, r7
 *   @0x12eeb4 bne 0x12ee7c <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x12eeb8 mov r3, #0
 *   @0x12eebc str r3, [r8]
 *   @0x12eec0 str r3, [r8, #0x4]
 *   @0x12eec4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12eec8 ldr r0, [pc, #0x50]
 *   @0x12eecc mov r2, r5
 *   @0x12eed0 ldr r1, [pc, #0x4c]
 *   @0x12eed4 ldr r3, [r3, r0]
 *   @0x12eed8 add r1, pc, r1
 *   @0x12eedc ldr r0, [r3]
 *   @0x12eee0 ldr r3, [r0]
 *   @0x12eee4 ldr r3, [r3, #0xc]
 *   @0x12eee8 blx r3
 *   @0x12eeec pop {r4, r5, r6, r7, r8, pc}
 *   @0x12eef0 ldr r0, [pc, #0x28]
 *   @0x12eef4 mov r2, r5
 *   @0x12eef8 ldr r1, [pc, #0x28]
 *   @0x12eefc ldr r3, [r3, r0]
 *   @0x12ef00 add r1, pc, r1
 *   @0x12ef04 ldr r0, [r3]
 *   @0x12ef08 ldr r3, [r0]
 *   @0x12ef0c ldr r3, [r3, #0xc]
 *   @0x12ef10 blx r3
 *   @0x12ef14 b 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x12ef18 eoreq r2, r12, r12, lsr #28
 *   @0x12ef1c .word 0xffffbccc
 *   @0x12ef20 .word 0xffffbac4
 *   @0x12ef24 eoreq lr, r0, r0, ror #15
 *   @0x12ef28 eoreq lr, r0, r12, lsl #15
 *
 * ══ §70/94 F_SoundEffectChorus(RValue&, CInstance*, CInstance*, int, RValue*)  0x133e68  size 312  78 条（0x133e68..0x133fa0）
 * @func 0x133e68 0x133fa0  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×3 / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Chorus(int, double, double, double, double, int, double, int)
 * 字段偏移 top8: 0x38×2 / 0x34×2 / 0x3c×2 / 0x124×1 / 0x70×1 / 0x108×1 / 0x18×1 / 0x28×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133e68 ldr r3, [pc, #0x124]
 *   @0x133e6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x133e70 ldr r3, [pc, r3]
 *   @0x133e74 sub sp, sp, #76
 *   @0x133e78 ldrb r3, [r3]
 *   @0x133e7c ldr r10, [sp, #0x70]
 *   @0x133e80 cmp r3, #0
 *   @0x133e84 bne 0x133e9c <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x133e88 ldr r3, [pc, #0x108]
 *   @0x133e8c ldr r3, [pc, r3]
 *   @0x133e90 ldrb r1, [r3]
 *   @0x133e94 cmp r1, #0
 *   @0x133e98 beq 0x133ea4 <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x133e9c add sp, sp, #76
 *   @0x133ea0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x133ea4 mov r0, r10
 *   @0x133ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133eac bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133eb0 subs r1, r0, #0
 *   @0x133eb4 beq 0x133f80 <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x133eb8 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133ebc mov r1, #1
 *   @0x133ec0 mov r11, r0
 *   @0x133ec4 mov r0, r10
 *   @0x133ec8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133ecc mov r2, r0
 *   @0x133ed0 mov r3, r1
 *   @0x133ed4 mov r0, r10
 *   @0x133ed8 mov r1, #2
 *   @0x133edc str r2, [sp, #0x38]
 *   @0x133ee0 str r3, [sp, #0x34]
 *   @0x133ee4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133ee8 mov r8, r0
 *   @0x133eec mov r9, r1
 *   @0x133ef0 mov r0, r10
 *   @0x133ef4 mov r1, #3
 *   @0x133ef8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133efc mov r6, r0
 *   @0x133f00 mov r7, r1
 *   @0x133f04 mov r0, r10
 *   @0x133f08 mov r1, #4
 *   @0x133f0c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133f10 mov r4, r0
 *   @0x133f14 mov r5, r1
 *   @0x133f18 mov r0, r10
 *   @0x133f1c mov r1, #5
 *   @0x133f20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133f24 mov r1, #6
 *   @0x133f28 mov r12, r0
 *   @0x133f2c mov r0, r10
 *   @0x133f30 str r12, [sp, #0x3c]
 *   @0x133f34 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133f38 strd r0, r1, [sp, #64]
 *   @0x133f3c mov r1, #7
 *   @0x133f40 mov r0, r10
 *   @0x133f44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133f48 ldr r12, [sp, #0x3c]
 *   @0x133f4c vldr d7, [sp, #64]
 *   @0x133f50 strd r8, r9, [sp]
 *   @0x133f54 strd r6, r7, [sp, #8]
 *   @0x133f58 vstr d7, [sp, #32]
 *   @0x133f5c strd r4, r5, [sp, #16]
 *   @0x133f60 str r12, [sp, #0x18]
 *   @0x133f64 ldr r2, [sp, #0x38]
 *   @0x133f68 ldr r3, [sp, #0x34]
 *   @0x133f6c str r0, [sp, #0x28]
 *   @0x133f70 mov r0, r11
 *   @0x133f74 bl 0x21f124 <_Z21SND_Set_Effect_Chorusiddddidi>
 *   @0x133f78 add sp, sp, #76
 *   @0x133f7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x133f80 ldr r0, [pc, #0x14]
 *   @0x133f84 add r0, pc, r0
 *   @0x133f88 add sp, sp, #76
 *   @0x133f8c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x133f90 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133f94 eoreq r10, r11, r0, asr #29
 *   @0x133f98 eoreq r11, r11, r0, asr #3
 *   @0x133f9c eoreq r11, r0, r8, lsl #10
 *
 * ══ §71/94 F_SoundEffectFlanger(RValue&, CInstance*, CInstance*, int, RValue*)  0x1341c0  size 312  78 条（0x1341c0..0x1342f8）
 * @func 0x1341c0 0x1342f8  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×3 / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Flanger(int, double, double, double, double, int, double, int)
 * 字段偏移 top8: 0x38×2 / 0x34×2 / 0x3c×2 / 0x124×1 / 0x70×1 / 0x108×1 / 0x18×1 / 0x28×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1341c0 ldr r3, [pc, #0x124]
 *   @0x1341c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1341c8 ldr r3, [pc, r3]
 *   @0x1341cc sub sp, sp, #76
 *   @0x1341d0 ldrb r3, [r3]
 *   @0x1341d4 ldr r10, [sp, #0x70]
 *   @0x1341d8 cmp r3, #0
 *   @0x1341dc bne 0x1341f4 <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1341e0 ldr r3, [pc, #0x108]
 *   @0x1341e4 ldr r3, [pc, r3]
 *   @0x1341e8 ldrb r1, [r3]
 *   @0x1341ec cmp r1, #0
 *   @0x1341f0 beq 0x1341fc <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1341f4 add sp, sp, #76
 *   @0x1341f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1341fc mov r0, r10
 *   @0x134200 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134204 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x134208 subs r1, r0, #0
 *   @0x13420c beq 0x1342d8 <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x134210 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x134214 mov r1, #1
 *   @0x134218 mov r11, r0
 *   @0x13421c mov r0, r10
 *   @0x134220 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134224 mov r2, r0
 *   @0x134228 mov r3, r1
 *   @0x13422c mov r0, r10
 *   @0x134230 mov r1, #2
 *   @0x134234 str r2, [sp, #0x38]
 *   @0x134238 str r3, [sp, #0x34]
 *   @0x13423c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134240 mov r8, r0
 *   @0x134244 mov r9, r1
 *   @0x134248 mov r0, r10
 *   @0x13424c mov r1, #3
 *   @0x134250 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134254 mov r6, r0
 *   @0x134258 mov r7, r1
 *   @0x13425c mov r0, r10
 *   @0x134260 mov r1, #4
 *   @0x134264 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134268 mov r4, r0
 *   @0x13426c mov r5, r1
 *   @0x134270 mov r0, r10
 *   @0x134274 mov r1, #5
 *   @0x134278 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13427c mov r1, #6
 *   @0x134280 mov r12, r0
 *   @0x134284 mov r0, r10
 *   @0x134288 str r12, [sp, #0x3c]
 *   @0x13428c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134290 strd r0, r1, [sp, #64]
 *   @0x134294 mov r1, #7
 *   @0x134298 mov r0, r10
 *   @0x13429c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1342a0 ldr r12, [sp, #0x3c]
 *   @0x1342a4 vldr d7, [sp, #64]
 *   @0x1342a8 strd r8, r9, [sp]
 *   @0x1342ac strd r6, r7, [sp, #8]
 *   @0x1342b0 vstr d7, [sp, #32]
 *   @0x1342b4 strd r4, r5, [sp, #16]
 *   @0x1342b8 str r12, [sp, #0x18]
 *   @0x1342bc ldr r2, [sp, #0x38]
 *   @0x1342c0 ldr r3, [sp, #0x34]
 *   @0x1342c4 str r0, [sp, #0x28]
 *   @0x1342c8 mov r0, r11
 *   @0x1342cc bl 0x21f13c <_Z22SND_Set_Effect_Flangeriddddidi>
 *   @0x1342d0 add sp, sp, #76
 *   @0x1342d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1342d8 ldr r0, [pc, #0x14]
 *   @0x1342dc add r0, pc, r0
 *   @0x1342e0 add sp, sp, #76
 *   @0x1342e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1342e8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1342ec eoreq r10, r11, r8, ror #22
 *   @0x1342f0 eoreq r10, r11, r8, ror #28
 *   @0x1342f4 .word 0x0020b1b0
 *
 * ══ §72/94 F_PhysicsCreateParticle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d220  size 312  78 条（0x14d220..0x14d358）
 * @func 0x14d220 0x14d358  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / YYGetUint32(RValue const*, int) / CPhysicsWorld::CreateParticle(unsigned int, float, float, float, float, unsigned int, float, int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×2 / 0x1c×2 / 0x128×1 / 0x48×1 / 0xb4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d220 ldr r3, [pc, #0x128]
 *   @0x14d224 mov r1, #0
 *   @0x14d228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d22c ldr r3, [pc, r3]
 *   @0x14d230 str r1, [r0]
 *   @0x14d234 sub sp, sp, #36
 *   @0x14d238 ldr r3, [r3]
 *   @0x14d23c mov r2, r1
 *   @0x14d240 mov r5, r0
 *   @0x14d244 movt r2, #0xbff0
 *   @0x14d248 cmp r3, r1
 *   @0x14d24c str r1, [r0, #0xc]
 *   @0x14d250 str r2, [r0, #0x4]
 *   @0x14d254 ldr r4, [sp, #0x48]
 *   @0x14d258 beq 0x14d338 <_Z23F_PhysicsCreateParticleR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x14d25c ldr r6, [r3, #0xb4]
 *   @0x14d260 cmp r6, r1
 *   @0x14d264 beq 0x14d338 <_Z23F_PhysicsCreateParticleR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x14d268 mov r0, r4
 *   @0x14d26c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d270 mov r1, #1
 *   @0x14d274 mov r9, r0
 *   @0x14d278 mov r0, r4
 *   @0x14d27c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d280 mov r1, #2
 *   @0x14d284 mov r8, r0
 *   @0x14d288 mov r0, r4
 *   @0x14d28c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d290 mov r1, #3
 *   @0x14d294 mov r7, r0
 *   @0x14d298 mov r0, r4
 *   @0x14d29c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d2a0 mov r1, #4
 *   @0x14d2a4 mov r2, r0
 *   @0x14d2a8 mov r0, r4
 *   @0x14d2ac str r2, [sp, #0x18]
 *   @0x14d2b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d2b4 mov r1, #5
 *   @0x14d2b8 mov r3, r0
 *   @0x14d2bc mov r0, r4
 *   @0x14d2c0 str r3, [sp, #0x1c]
 *   @0x14d2c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d2c8 mov r1, #6
 *   @0x14d2cc mov r11, r0
 *   @0x14d2d0 mov r0, r4
 *   @0x14d2d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d2d8 mov r1, #7
 *   @0x14d2dc mov r10, r0
 *   @0x14d2e0 mov r0, r4
 *   @0x14d2e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d2e8 ldr r2, [sp, #0x18]
 *   @0x14d2ec ldr r3, [sp, #0x1c]
 *   @0x14d2f0 mov r1, r9
 *   @0x14d2f4 str r11, [sp, #0x8]
 *   @0x14d2f8 str r2, [sp]
 *   @0x14d2fc mov r2, r8
 *   @0x14d300 str r3, [sp, #0x4]
 *   @0x14d304 mov r3, r7
 *   @0x14d308 str r10, [sp, #0xc]
 *   @0x14d30c str r0, [sp, #0x10]
 *   @0x14d310 mov r0, r6
 *   @0x14d314 bl 0x2398e4 <_ZN13CPhysicsWorld14CreateParticleEjffffjfi>
 *   @0x14d318 vmov s15, r0
 *   @0x14d31c vcvt.f64.s32 d7, s15
 *   @0x14d320 vmov r0, r1, d7
 *   @0x14d324 vmov r2, s14
 *   @0x14d328 mov r3, r1
 *   @0x14d32c stm r5, {r2, r3}
 *   @0x14d330 add sp, sp, #36
 *   @0x14d334 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14d338 ldr r0, [pc, #0x14]
 *   @0x14d33c mov r1, #0
 *   @0x14d340 add r0, pc, r0
 *   @0x14d344 add sp, sp, #36
 *   @0x14d348 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d34c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d350 .word 0x002a06fc
 *   @0x14d354 andseq r6, pc, r8, asr r12
 *
 * ══ §73/94 F_YoYo_AnalyticsEventExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x158440  size 312  78 条（0x158440..0x158578）
 * @func 0x158440 0x158578  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / F_YoYo_AnalyticsEventExt(RValue&, CInstance*, CInstance*, int, RValue*)+0x10c / F_YoYo_AnalyticsEventExt(RValue&, CInstance*, CInstance*, int, RValue*)+0xd8 / YYGetReal(RValue const*, int) / YYAnalyticsEventExt(char const*, int, SKeyValueNumber const*) / YYAnalyticsEvent(char const*) / Error_Show(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x-28×2 / 0x-34×2 / 0x-30×2 / 0x120×1 / 0x4×1 / 0x1c×1 / 0x2c×1 / 0x-10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x158444 add r11, sp, #32
 *   @0x158448 ldr r8, [pc, #0x120]
 *   @0x15844c sub sp, sp, #20
 *   @0x158450 mov r6, r3
 *   @0x158454 ldr r8, [pc, r8]
 *   @0x158458 ldr r9, [r11, #0x4]
 *   @0x15845c mov r1, #0
 *   @0x158460 ldr r3, [r8]
 *   @0x158464 mov r0, r9
 *   @0x158468 str r3, [r11, #-0x28]
 *   @0x15846c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158470 sub r2, r6, #1
 *   @0x158474 cmp r2, #1
 *   @0x158478 add r2, r2, r2, lsr #31
 *   @0x15847c asr r2, r2, #1
 *   @0x158480 lsl r2, r2, #4
 *   @0x158484 add r2, r2, #8
 *   @0x158488 sub sp, sp, r2
 *   @0x15848c mov r2, sp
 *   @0x158490 mov r3, r0
 *   @0x158494 ble 0x15854c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x158498 mov r4, r9
 *   @0x15849c mov r10, sp
 *   @0x1584a0 mov r7, #0
 *   @0x1584a4 mov r5, #1
 *   @0x1584a8 b 0x1584c0 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1584ac add r5, r5, #2
 *   @0x1584b0 add r4, r4, #32
 *   @0x1584b4 rsb r1, r5, r6
 *   @0x1584b8 cmp r1, #1
 *   @0x1584bc ble 0x158518 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1584c0 ldr r1, [r4, #0x1c]
 *   @0x1584c4 cmp r1, #1
 *   @0x1584c8 movne r7, #1
 *   @0x1584cc bne 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1584d0 ldr r0, [r4, #0x2c]
 *   @0x1584d4 cmp r0, #0
 *   @0x1584d8 movne r7, r1
 *   @0x1584dc bne 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1584e0 mov r1, r5
 *   @0x1584e4 mov r0, r9
 *   @0x1584e8 str r2, [r11, #-0x34]
 *   @0x1584ec add r10, r10, #16
 *   @0x1584f0 str r3, [r11, #-0x30]
 *   @0x1584f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1584f8 add r1, r5, #1
 *   @0x1584fc str r0, [r10, #-0x10]
 *   @0x158500 mov r0, r9
 *   @0x158504 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x158508 ldr r2, [r11, #-0x34]
 *   @0x15850c ldr r3, [r11, #-0x30]
 *   @0x158510 strd r0, r1, [r10, #-8]
 *   @0x158514 b 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x158518 cmp r7, #0
 *   @0x15851c bne 0x158558 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x158520 rsb r10, r2, r10
 *   @0x158524 asrs r1, r10, #4
 *   @0x158528 beq 0x15854c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x15852c mov r0, r3
 *   @0x158530 bl 0x15f3d0 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber>
 *   @0x158534 ldr r2, [r11, #-0x28]
 *   @0x158538 ldr r3, [r8]
 *   @0x15853c cmp r2, r3
 *   @0x158540 bne 0x15856c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x158544 sub sp, r11, #32
 *   @0x158548 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15854c mov r0, r3
 *   @0x158550 bl 0x15f380 <_Z16YYAnalyticsEventPKc>
 *   @0x158554 b 0x158534 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x158558 ldr r0, [pc, #0x14]
 *   @0x15855c mov r1, #0
 *   @0x158560 add r0, pc, r0
 *   @0x158564 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x158568 b 0x158534 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x15856c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x158570 .word 0x002954fc
 *   @0x158574 andseq lr, lr, r0, ror #2
 *
 * ══ §74/94 GR_3D_Light_Update(int)  0x17f4c4  size 312  78 条（0x17f4c4..0x17f5fc）
 * @func 0x17f4c4 0x17f5fc  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17f4d4→0x3f26dc, 0x17f4ec→0x479c54, 0x17f504→0x479c44, 0x17f520→0x479bf8, 0x17f538→0x3f2770, 0x17f540→0x4a22f4, 0x17f544→0x479be4, 0x17f574→0x479be0
 * 调用序列: Graphics::GetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x9c×2 / 0x70×2 / 0xf8×1 / 0xf4×1 / 0xe0×1 / 0xcc×1 / 0xb4×1 / 0xa0×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f4c4 push {r4, r5, r6, r7, lr}
 *   @0x17f4c8 mov r6, r0
 *   @0x17f4cc ldr r4, [pc, #0xf8]
 *   @0x17f4d0 sub sp, sp, #68
 *   @0x17f4d4 ldr r3, [pc, #0xf4]
 *   @0x17f4d8 add r4, pc, r4
 *   @0x17f4dc ldr r3, [r4, r3]
 *   @0x17f4e0 ldr r5, [r3]
 *   @0x17f4e4 cmp r5, #0
 *   @0x17f4e8 bne 0x17f5c4 <_Z18GR_3D_Light_Updatei+0x100>
 *   @0x17f4ec ldr r3, [pc, #0xe0]
 *   @0x17f4f0 mov r0, #5888
 *   @0x17f4f4 lsl r7, r6, #4
 *   @0x17f4f8 ldr r3, [r4, r3]
 *   @0x17f4fc ldr r3, [r3]
 *   @0x17f500 blx r3
 *   @0x17f504 ldr r3, [pc, #0xcc]
 *   @0x17f508 ldr r3, [r4, r3]
 *   @0x17f50c ldr r3, [r3]
 *   @0x17f510 blx r3
 *   @0x17f514 mov r0, r5
 *   @0x17f518 mov r1, sp
 *   @0x17f51c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17f520 ldr r3, [pc, #0xb4]
 *   @0x17f524 mov r0, sp
 *   @0x17f528 ldr r3, [r4, r3]
 *   @0x17f52c ldr r3, [r3]
 *   @0x17f530 blx r3
 *   @0x17f534 vmov.f32 s14, #1.000000e+00
 *   @0x17f538 ldr r0, [pc, #0xa0]
 *   @0x17f53c movw r1, #0x1208
 *   @0x17f540 ldr r2, [pc, #0x9c]
 *   @0x17f544 ldr r3, [pc, #0x9c]
 *   @0x17f548 ldr r0, [r4, r0]
 *   @0x17f54c ldr r2, [r4, r2]
 *   @0x17f550 ldr r3, [r4, r3]
 *   @0x17f554 ldr r5, [r0, r6, lsl #2]
 *   @0x17f558 add r6, r2, r6, lsl #2
 *   @0x17f55c vldr s15, [r6]
 *   @0x17f560 ldr r3, [r3]
 *   @0x17f564 vdiv.f32 s15, s14, s15
 *   @0x17f568 mov r0, r5
 *   @0x17f56c vmov r2, s15
 *   @0x17f570 blx r3
 *   @0x17f574 ldr r2, [pc, #0x70]
 *   @0x17f578 ldr r3, [pc, #0x70]
 *   @0x17f57c mov r0, r5
 *   @0x17f580 movw r1, #0x1201
 *   @0x17f584 ldr r6, [r4, r2]
 *   @0x17f588 ldr r2, [r4, r3]
 *   @0x17f58c ldr r3, [r6]
 *   @0x17f590 add r2, r2, r7
 *   @0x17f594 blx r3
 *   @0x17f598 ldr r2, [pc, #0x54]
 *   @0x17f59c ldr r3, [r6]
 *   @0x17f5a0 mov r0, r5
 *   @0x17f5a4 movw r1, #0x1203
 *   @0x17f5a8 ldr r2, [r4, r2]
 *   @0x17f5ac add r2, r2, r7
 *   @0x17f5b0 blx r3
 *   @0x17f5b4 ldr r3, [pc, #0x3c]
 *   @0x17f5b8 ldr r3, [r4, r3]
 *   @0x17f5bc ldr r3, [r3]
 *   @0x17f5c0 blx r3
 *   @0x17f5c4 add sp, sp, #68
 *   @0x17f5c8 pop {r4, r5, r6, r7, pc}
 *   @0x17f5cc eoreq r2, r7, r8, ror r7
 *   @0x17f5d0 .word 0xffffe7b8
 *   @0x17f5d4 .word 0xffffbc48
 *   @0x17f5d8 .word 0xffffbc58
 *   @0x17f5dc .word 0xffffbc88
 *   @0x17f5e0 .word 0xffffe848
 *   @0x17f5e4 .word 0xffffe84c
 *   @0x17f5e8 .word 0xffffbc90
 *   @0x17f5ec .word 0xffffbc94
 *   @0x17f5f0 .word 0xffffe850
 *   @0x17f5f4 .word 0xffffe854
 *   @0x17f5f8 .word 0xffffbc54
 *
 * ══ §75/94 GR_3D_Light_Define_Point(int, float, float, float, float, unsigned int)  0x17f7e8  size 312  78 条（0x17f7e8..0x17f920）
 * @func 0x17f7e8 0x17f920  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×2 / 0x100×1 / 0xec×1 / 0x98×1 / 0x58×1 / 0x40×1 / 0x2×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f7e8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f7ec vldr s15, [pc, #272]
 *   @0x17f7f0 and r0, r0, #7
 *   @0x17f7f4 vldr s13, [sp, #32]
 *   @0x17f7f8 ldr r4, [sp, #0x24]
 *   @0x17f7fc vcmpe.f32 s13, #0
 *   @0x17f800 ldr r12, [pc, #0x100]
 *   @0x17f804 lsl r10, r0, #4
 *   @0x17f808 ubfx r5, r4, #0x8, #0x8
 *   @0x17f80c uxtb r6, r4
 *   @0x17f810 ubfx r4, r4, #0x10, #0x8
 *   @0x17f814 vmov s14, r5
 *   @0x17f818 ldr r5, [pc, #0xec]
 *   @0x17f81c vmov s11, r6
 *   @0x17f820 add r12, pc, r12
 *   @0x17f824 vcvt.f32.s32 s14, s14
 *   @0x17f828 lsl r6, r0, #2
 *   @0x17f82c vmov s12, r4
 *   @0x17f830 add r9, r6, #1
 *   @0x17f834 ldr r5, [r12, r5]
 *   @0x17f838 add r8, r6, #2
 *   @0x17f83c lsl r9, r9, #2
 *   @0x17f840 add r7, r6, #3
 *   @0x17f844 add r11, r5, r9
 *   @0x17f848 add r4, r5, r10
 *   @0x17f84c lsl r8, r8, #2
 *   @0x17f850 lsl r7, r7, #2
 *   @0x17f854 vmrs APSR_nzcv, fpscr
 *   @0x17f858 vcvt.f32.s32 s11, s11
 *   @0x17f85c vdiv.f32 s14, s14, s15
 *   @0x17f860 vdiv.f32 s11, s11, s15
 *   @0x17f864 vcvt.f32.s32 s12, s12
 *   @0x17f868 vstr s11, [r4]
 *   @0x17f86c vstr s14, [r11]
 *   @0x17f870 ldr r4, [pc, #0x98]
 *   @0x17f874 add r11, r5, r8
 *   @0x17f878 add r5, r5, r7
 *   @0x17f87c vdiv.f32 s15, s12, s15
 *   @0x17f880 vmov.f32 s14, #1.000000e+00
 *   @0x17f884 vstr s15, [r11]
 *   @0x17f888 vstr s14, [r5]
 *   @0x17f88c ldr r4, [r12, r4]
 *   @0x17f890 add r10, r4, r10
 *   @0x17f894 add r9, r4, r9
 *   @0x17f898 add r8, r4, r8
 *   @0x17f89c add r4, r4, r7
 *   @0x17f8a0 str r1, [r10]
 *   @0x17f8a4 str r2, [r9]
 *   @0x17f8a8 movwle r2, #0x126f
 *   @0x17f8ac str r3, [r8]
 *   @0x17f8b0 vstr s14, [r4]
 *   @0x17f8b4 ldr r3, [pc, #0x58]
 *   @0x17f8b8 movtle r2, #0x3a83
 *   @0x17f8bc ldrgt r3, [r12, r3]
 *   @0x17f8c0 ldrle r3, [r12, r3]
 *   @0x17f8c4 addgt r6, r3, r6
 *   @0x17f8c8 vstrgt s13, [r6]
 *   @0x17f8cc addle r6, r3, r6
 *   @0x17f8d0 ldr r3, [pc, #0x40]
 *   @0x17f8d4 strle r2, [r6]
 *   @0x17f8d8 ldr r3, [r12, r3]
 *   @0x17f8dc ldr r3, [r3]
 *   @0x17f8e0 cmp r3, #1
 *   @0x17f8e4 beq 0x17f8f0 <_Z24GR_3D_Light_Define_Pointiffffj+0x108>
 *   @0x17f8e8 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f8ec b 0x17f4c4 <_Z18GR_3D_Light_Updatei>
 *   @0x17f8f0 ldr r2, [pc, #0x24]
 *   @0x17f8f4 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f8f8 ldr r2, [r12, r2]
 *   @0x17f8fc str r3, [r2, r0, lsl #2]
 *   @0x17f900 b 0x17f4c4 <_Z18GR_3D_Light_Updatei>
 *   @0x17f904 cmnmi pc, #0
 *   @0x17f908 eoreq r2, r7, r0, lsr r4
 *   @0x17f90c .word 0xffffe850
 *   @0x17f910 .word 0xffffe854
 *   @0x17f914 .word 0xffffe84c
 *   @0x17f918 .word 0xffffe7b8
 *   @0x17f91c .word 0xffffe858
 *
 * ══ §76/94 CLayerManager::GetNewTileElement()  0x1c1260  size 312  78 条（0x1c1260..0x1c1398）
 * @func 0x1c1260 0x1c1398  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewTileElement()+0xf0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewTileElement()+0x34
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0x124×1 / 0x108×1 / 0xc×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c1260 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c1264 ldr r5, [pc, #0x124]
 *   @0x1c1268 ldr r5, [pc, r5]
 *   @0x1c126c ldr r6, [r5, #0x8]
 *   @0x1c1270 cmp r6, #0
 *   @0x1c1274 bne 0x1c1358 <_ZN13CLayerManager17GetNewTileElementEv+0xf8>
 *   @0x1c1278 ldr r3, [r5, #0x10]
 *   @0x1c127c cmp r3, #0
 *   @0x1c1280 ble 0x1c1350 <_ZN13CLayerManager17GetNewTileElementEv+0xf0>
 *   @0x1c1284 ldr r7, [pc, #0x108]
 *   @0x1c1288 mov r4, r6
 *   @0x1c128c mov r8, #0
 *   @0x1c1290 add r7, pc, r7
 *   @0x1c1294 mov r1, r7
 *   @0x1c1298 mov r3, #1
 *   @0x1c129c mov r0, #80
 *   @0x1c12a0 mov r2, #63
 *   @0x1c12a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c12a8 mvn r3, #0
 *   @0x1c12ac mov r1, #7
 *   @0x1c12b0 cmp r0, #0
 *   @0x1c12b4 beq 0x1c1308 <_ZN13CLayerManager17GetNewTileElementEv+0xa8>
 *   @0x1c12b8 mov r2, #1065353216
 *   @0x1c12bc strb r4, [r0, #0x8]
 *   @0x1c12c0 str r4, [r0, #0xc]
 *   @0x1c12c4 str r8, [r0, #0x24]
 *   @0x1c12c8 str r4, [r0, #0x10]
 *   @0x1c12cc str r8, [r0, #0x28]
 *   @0x1c12d0 str r4, [r0, #0x14]
 *   @0x1c12d4 str r8, [r0, #0x3c]
 *   @0x1c12d8 str r4, [r0, #0x18]
 *   @0x1c12dc str r3, [r0, #0x4]
 *   @0x1c12e0 str r3, [r0, #0x20]
 *   @0x1c12e4 str r4, [r0, #0x2c]
 *   @0x1c12e8 str r4, [r0, #0x30]
 *   @0x1c12ec str r3, [r0, #0x40]
 *   @0x1c12f0 str r4, [r0, #0x48]
 *   @0x1c12f4 str r2, [r0, #0x34]
 *   @0x1c12f8 str r4, [r0, #0x4c]
 *   @0x1c12fc str r2, [r0, #0x38]
 *   @0x1c1300 str r1, [r0]
 *   @0x1c1304 str r2, [r0, #0x44]
 *   @0x1c1308 ldr r3, [r5]
 *   @0x1c130c add r6, r6, #1
 *   @0x1c1310 ldr r2, [r5, #0x8]
 *   @0x1c1314 cmp r3, #0
 *   @0x1c1318 streq r0, [r5, #0x4]
 *   @0x1c131c strne r0, [r3, #0x18]
 *   @0x1c1320 add r2, r2, #1
 *   @0x1c1324 streq r3, [r0, #0x18]
 *   @0x1c1328 streq r3, [r0, #0x14]
 *   @0x1c132c strne r3, [r0, #0x14]
 *   @0x1c1330 ldr r3, [r5, #0x10]
 *   @0x1c1334 streq r0, [r5]
 *   @0x1c1338 strne r0, [r5]
 *   @0x1c133c strne r4, [r0, #0x18]
 *   @0x1c1340 cmp r6, r3
 *   @0x1c1344 str r2, [r5, #0x8]
 *   @0x1c1348 blt 0x1c1294 <_ZN13CLayerManager17GetNewTileElementEv+0x34>
 *   @0x1c134c ldr r6, [r5, #0x8]
 *   @0x1c1350 lsl r3, r3, #1
 *   @0x1c1354 str r3, [r5, #0x10]
 *   @0x1c1358 ldr r0, [r5]
 *   @0x1c135c sub r6, r6, #1
 *   @0x1c1360 str r6, [r5, #0x8]
 *   @0x1c1364 ldr r3, [r0, #0x18]
 *   @0x1c1368 ldr r2, [r0, #0x14]
 *   @0x1c136c cmp r3, #0
 *   @0x1c1370 strne r2, [r3, #0x14]
 *   @0x1c1374 ldrne r2, [r0, #0x14]
 *   @0x1c1378 ldrne r3, [r0, #0x18]
 *   @0x1c137c streq r2, [r5]
 *   @0x1c1380 cmp r2, #0
 *   @0x1c1384 streq r3, [r5, #0x4]
 *   @0x1c1388 strne r3, [r2, #0x18]
 *   @0x1c138c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c1390 eoreq pc, r2, r0, lsl r6
 *   @0x1c1394 andseq r12, r8, r4, lsl #8
 *
 * ══ §77/94 LoadDebugInfo(void*, unsigned int)  0x1de7b0  size 312  78 条（0x1de7b0..0x1de8e8）
 * @func 0x1de7b0 0x1de8e8  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadDebugInfo(void*, unsigned int)+0x2c×2 / DebugInfo_Load(unsigned char*, unsigned int, unsigned char*) / DebugScript_Load(unsigned char*, unsigned int, unsigned char*) / DebugInstNames_Load(unsigned char*, unsigned int, unsigned char*)
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x8×2 / 0x124×1 / 0x14×1 / 0xe0×1 / 0xdc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de7b0 ldr r3, [pc, #0x124]
 *   @0x1de7b4 ldr r2, [r0, #0x4]
 *   @0x1de7b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1de7bc mov r9, r1
 *   @0x1de7c0 sub r1, r1, #8
 *   @0x1de7c4 ldr r3, [pc, r3]
 *   @0x1de7c8 cmp r1, r2
 *   @0x1de7cc sub sp, sp, #28
 *   @0x1de7d0 mov r6, r0
 *   @0x1de7d4 str r0, [r3]
 *   @0x1de7d8 beq 0x1de7e8 <_Z13LoadDebugInfoPvj+0x38>
 *   @0x1de7dc mov r0, #1
 *   @0x1de7e0 add sp, sp, #28
 *   @0x1de7e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1de7e8 cmp r9, #8
 *   @0x1de7ec mov r3, #0
 *   @0x1de7f0 strb r3, [sp, #0x14]
 *   @0x1de7f4 bls 0x1de7dc <_Z13LoadDebugInfoPvj+0x2c>
 *   @0x1de7f8 ldr r3, [pc, #0xe0]
 *   @0x1de7fc movw r2, #0x4353
 *   @0x1de800 ldr r11, [pc, #0xdc]
 *   @0x1de804 movt r2, #0x5450
 *   @0x1de808 ldr r3, [pc, r3]
 *   @0x1de80c str r2, [sp, #0x4]
 *   @0x1de810 add r11, pc, r11
 *   @0x1de814 movw r2, #0x4e49
 *   @0x1de818 ldr r8, [r3]
 *   @0x1de81c movt r2, #0x5453
 *   @0x1de820 movw r3, #0x4244
 *   @0x1de824 str r2, [sp, #0x8]
 *   @0x1de828 movt r3, #0x4947
 *   @0x1de82c add r10, sp, #16
 *   @0x1de830 str r3, [sp, #0xc]
 *   @0x1de834 mov r7, #8
 *   @0x1de838 b 0x1de870 <_Z13LoadDebugInfoPvj+0xc0>
 *   @0x1de83c ldr r3, [sp, #0x8]
 *   @0x1de840 cmp r5, r3
 *   @0x1de844 beq 0x1de8c8 <_Z13LoadDebugInfoPvj+0x118>
 *   @0x1de848 ldr r2, [sp, #0xc]
 *   @0x1de84c cmp r5, r2
 *   @0x1de850 bne 0x1de864 <_Z13LoadDebugInfoPvj+0xb4>
 *   @0x1de854 add r0, r6, r7
 *   @0x1de858 mov r1, r4
 *   @0x1de85c mov r2, r6
 *   @0x1de860 bl 0x1de76c <_Z14DebugInfo_LoadPhjS_>
 *   @0x1de864 add r7, r4, r7
 *   @0x1de868 cmp r9, r7
 *   @0x1de86c bls 0x1de7dc <_Z13LoadDebugInfoPvj+0x2c>
 *   @0x1de870 mov r3, r6
 *   @0x1de874 ldr r12, [r8]
 *   @0x1de878 ldr r5, [r3, r7]!
 *   @0x1de87c mov r0, r8
 *   @0x1de880 mov r1, r11
 *   @0x1de884 mov r2, r10
 *   @0x1de888 ldr r12, [r12, #0xc]
 *   @0x1de88c add r7, r7, #8
 *   @0x1de890 ldr r4, [r3, #0x4]
 *   @0x1de894 str r5, [sp, #0x10]
 *   @0x1de898 mov r3, r4
 *   @0x1de89c blx r12
 *   @0x1de8a0 cmp r4, #0
 *   @0x1de8a4 beq 0x1de864 <_Z13LoadDebugInfoPvj+0xb4>
 *   @0x1de8a8 ldr r2, [sp, #0x4]
 *   @0x1de8ac cmp r5, r2
 *   @0x1de8b0 bne 0x1de83c <_Z13LoadDebugInfoPvj+0x8c>
 *   @0x1de8b4 add r0, r6, r7
 *   @0x1de8b8 mov r1, r4
 *   @0x1de8bc mov r2, r6
 *   @0x1de8c0 bl 0x1de750 <_Z16DebugScript_LoadPhjS_>
 *   @0x1de8c4 b 0x1de864 <_Z13LoadDebugInfoPvj+0xb4>
 *   @0x1de8c8 add r0, r6, r7
 *   @0x1de8cc mov r1, r4
 *   @0x1de8d0 mov r2, r6
 *   @0x1de8d4 bl 0x1de788 <_Z19DebugInstNames_LoadPhjS_>
 *   @0x1de8d8 b 0x1de864 <_Z13LoadDebugInfoPvj+0xb4>
 *   @0x1de8dc eoreq pc, r0, r12, lsl #7
 *   @0x1de8e0 eoreq r1, r1, r4, lsl r3
 *   @0x1de8e4 ldrheq r2, [r7], -r4
 *
 * ══ §78/94 JS_SetupProperty(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), void (*)(RValue&, CInstance*, CInstance*, int, RValue*))  0x241504  size 312  78 条（0x241504..0x24163c）
 * @func 0x241504 0x24163c  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×6 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x4×6 / 0xc×2 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241504 push {r3, r4, r5, r6, r7, lr}
 *   @0x241508 mov r2, #0
 *   @0x24150c mov r7, r0
 *   @0x241510 mov r6, r1
 *   @0x241514 mov r0, #2
 *   @0x241518 mvn r1, #-16777216
 *   @0x24151c bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x241520 mov r3, #2
 *   @0x241524 ldr r5, [r0, #0x4]
 *   @0x241528 mov r4, r0
 *   @0x24152c str r3, [r0, #0x48]
 *   @0x241530 cmp r5, #0
 *   @0x241534 beq 0x2415dc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xd8>
 *   @0x241538 mov r1, #0
 *   @0x24153c mov r0, r7
 *   @0x241540 mov r2, r1
 *   @0x241544 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241548 str r0, [r5]
 *   @0x24154c ldr r1, [r4, #0x4]
 *   @0x241550 cmp r1, #0
 *   @0x241554 beq 0x2415ec <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xe8>
 *   @0x241558 ldr r1, [r1]
 *   @0x24155c mov r0, r4
 *   @0x241560 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x241564 ldr r1, [r4, #0x4]
 *   @0x241568 cmp r1, #0
 *   @0x24156c movne r2, #11
 *   @0x241570 strne r2, [r1, #0xc]
 *   @0x241574 beq 0x2415fc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xf8>
 *   @0x241578 add r5, r1, #16
 *   @0x24157c mov r1, #0
 *   @0x241580 mov r0, r6
 *   @0x241584 mov r2, r1
 *   @0x241588 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24158c str r0, [r5]
 *   @0x241590 ldr r0, [r4, #0x4]
 *   @0x241594 cmp r0, #0
 *   @0x241598 beq 0x24162c <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x128>
 *   @0x24159c add r0, r0, #16
 *   @0x2415a0 ldr r1, [r0]
 *   @0x2415a4 mov r0, r4
 *   @0x2415a8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2415ac ldr r0, [r4, #0x4]
 *   @0x2415b0 cmp r0, #0
 *   @0x2415b4 beq 0x2415cc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xc8>
 *   @0x2415b8 add r0, r0, #16
 *   @0x2415bc mov r3, #11
 *   @0x2415c0 str r3, [r0, #0xc]
 *   @0x2415c4 mov r0, r4
 *   @0x2415c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2415cc mov r0, r4
 *   @0x2415d0 mov r1, #1
 *   @0x2415d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2415d8 b 0x2415bc <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0xb8>
 *   @0x2415dc mov r1, r5
 *   @0x2415e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2415e4 mov r5, r0
 *   @0x2415e8 b 0x241538 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x34>
 *   @0x2415ec mov r0, r4
 *   @0x2415f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2415f4 mov r1, r0
 *   @0x2415f8 b 0x241558 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x54>
 *   @0x2415fc mov r0, r4
 *   @0x241600 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241604 ldr r1, [r4, #0x4]
 *   @0x241608 mov r2, #11
 *   @0x24160c cmp r1, #0
 *   @0x241610 str r2, [r0, #0xc]
 *   @0x241614 bne 0x241578 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x74>
 *   @0x241618 mov r0, r4
 *   @0x24161c mov r1, #1
 *   @0x241620 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241624 mov r5, r0
 *   @0x241628 b 0x24157c <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x78>
 *   @0x24162c mov r0, r4
 *   @0x241630 mov r1, #1
 *   @0x241634 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241638 b 0x2415a0 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_+0x9c>
 *
 * ══ §79/94 JS_Number_Prototype_toExponential(RValue&, CInstance*, CInstance*, int, RValue*)  0x254870  size 312  78 条（0x254870..0x2549a8）
 * @func 0x254870 0x2549a8  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)×2 / JS_Number_Prototype_toExponential(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / F_JS_ToInteger(RValue&) / JS_Number_Prototype_toExponential(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / JSThrowRangeError(char const*) / YYObjectBase::FindValue(char const*) / 0xb65b0 / 0xb6550
 * 字段偏移 top8: 0x-28×2 / 0x110×1 / 0x4×1 / 0xc×1 / 0xac×1 / 0x9c×1 / 0x5c×1 / 0x20×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254870 push {r4, r5, r6, r7, r8, r11, lr}
 *   @0x254874 vpush {d8}
 *   @0x254878 add r11, sp, #32
 *   @0x25487c ldr r6, [pc, #0x110]
 *   @0x254880 sub sp, sp, #20
 *   @0x254884 cmp r3, #0
 *   @0x254888 ldr r6, [pc, r6]
 *   @0x25488c mov r8, r0
 *   @0x254890 mov r4, r1
 *   @0x254894 ldr r0, [r11, #0x4]
 *   @0x254898 ldr r2, [r6]
 *   @0x25489c str r2, [r11, #-0x28]
 *   @0x2548a0 ble 0x2548f4 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2548a4 ldr r2, [r0, #0xc]
 *   @0x2548a8 bic r2, r2, #-16777216
 *   @0x2548ac cmp r2, #5
 *   @0x2548b0 beq 0x2548f4 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2548b4 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x2548b8 vmov d8, r0, r1
 *   @0x2548bc vcmpe.f64 d8, #0
 *   @0x2548c0 vmrs APSR_nzcv, fpscr
 *   @0x2548c4 bmi 0x2548d8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x2548c8 vmov.f64 d7, #2.000000e+01
 *   @0x2548cc vcmpe.f64 d8, d7
 *   @0x2548d0 vmrs APSR_nzcv, fpscr
 *   @0x2548d4 ble 0x2548f8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x2548d8 vcmp.f64 d8, d8
 *   @0x2548dc vmrs APSR_nzcv, fpscr
 *   @0x2548e0 bvs 0x2548f8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x2548e4 ldr r0, [pc, #0xac]
 *   @0x2548e8 add r0, pc, r0
 *   @0x2548ec bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x2548f0 b 0x254960 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x2548f4 vmov.f64 d8, #5.000000e+00
 *   @0x2548f8 ldr r1, [pc, #0x9c]
 *   @0x2548fc mov r0, r4
 *   @0x254900 add r1, pc, r1
 *   @0x254904 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x254908 ldm r0, {r4, r5}
 *   @0x25490c vmov d6, r4, r5
 *   @0x254910 vmov d7, r4, r5
 *   @0x254914 vcmp.f64 d6, d7
 *   @0x254918 vmrs APSR_nzcv, fpscr
 *   @0x25491c bvs 0x25497c <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x254920 sub sp, sp, #264
 *   @0x254924 mov r1, #0
 *   @0x254928 add r7, sp, #8
 *   @0x25492c mov r2, #256
 *   @0x254930 mov r0, r7
 *   @0x254934 bl 0xb65b0 <memset@plt>
 *   @0x254938 vcvt.s32.f64 s15, d8
 *   @0x25493c ldr r1, [pc, #0x5c]
 *   @0x254940 mov r0, r7
 *   @0x254944 strd r4, r5, [sp]
 *   @0x254948 add r1, pc, r1
 *   @0x25494c vmov r2, s15
 *   @0x254950 bl 0xb6550 <sprintf@plt>
 *   @0x254954 mov r0, r8
 *   @0x254958 mov r1, r7
 *   @0x25495c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x254960 ldr r2, [r11, #-0x28]
 *   @0x254964 ldr r3, [r6]
 *   @0x254968 cmp r2, r3
 *   @0x25496c bne 0x254990 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x254970 sub sp, r11, #32
 *   @0x254974 vpop {d8}
 *   @0x254978 pop {r4, r5, r6, r7, r8, r11, pc}
 *   @0x25497c ldr r1, [pc, #0x20]
 *   @0x254980 mov r0, r8
 *   @0x254984 add r1, pc, r1
 *   @0x254988 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x25498c b 0x254960 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x254990 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x254994 andseq r9, r9, r8, asr #1
 *   @0x254998 andseq r1, r0, r4, lsr #27
 *   @0x25499c andseq r0, r0, r0, lsl r12
 *   @0x2549a0 andseq r1, r0, r12, lsl #27
 *   @0x2549a4 andeq sp, sp, r0, ror r11
 *
 * ══ §80/94 png_handle_bKGD  0x2acd60  size 312  78 条（0x2acd60..0x2ace98）
 * @func 0x2acd60 0x2ace98  size 312  78 条
 * 部分覆盖: 本节 78/134 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / 0x379558 / png_crc_read / png_crc_finish / 0x334e3c / png_set_bKGD
 * 字段偏移 top8: 0x10c×1 / 0xf4×1 / 0x8×1 / 0x14×1 / 0x8c×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2acd60 push {r0, r1, r4, r5, r6, lr}
 *   @0x2acd64 ldr.w r3, [r0, #0x12c]
 *   @0x2acd68 mov r4, r0
 *   @0x2acd6c lsls r2, r3, #0x1f
 *   @0x2acd70 ldr r1, [pc, #0x10c]
 *   @0x2acd74 bl 0x2a642c <png_error>
 *   @0x2acd78 b 0x2acda6 <png_handle_bKGD+0x46>
 *   @0x2acd7c bpl 0x2acd84 <png_handle_bKGD+0x24>
 *   @0x2acd80 add r1, pc
 *   @0x2acd84 ldrb.w r2, [r0, #0x1ea]
 *   @0x2acd88 cmp r2, #0x3
 *   @0x2acd8c lsls r2, r3, #0x1e
 *   @0x2acd90 ldr r1, [pc, #0xf4]
 *   @0x2acd94 b 0x2acdc6 <png_handle_bKGD+0x66>
 *   @0x2acd98 ldr r3, [r6, #0x8]
 *   @0x2acd9c bpl 0x2acda6 <png_handle_bKGD+0x46>
 *   @0x2acda0 mov r0, r4
 *   @0x2acda4 b 0x2acdc6 <png_handle_bKGD+0x66>
 *   @0x2acda8 blhs 0x379558 <_ZTS13C_UTF16String+0x10604>
 *   @0x2acdac beq 0x2acdba <png_handle_bKGD+0x5a>
 *   @0x2acdb0 svclt #0xc0f02
 *   @0x2acdb4 moveq r3, #0x2
 *   @0x2acdb8 b 0x2acdbc <png_handle_bKGD+0x5c>
 *   @0x2acdbc cmp r5, r3
 *   @0x2acdc0 beq 0x2acdd4 <png_handle_bKGD+0x74>
 *   @0x2acdc4 add r1, pc
 *   @0x2acdc8 qsaxmi pc, r0, r5
 *   @0x2acdcc mov r1, r5
 *   @0x2acdd0 subs pc, r3, r1, ror #30
 *   @0x2acdd4 mov r1, sp
 *   @0x2acdd8 bl 0x2abc0c <png_crc_read>
 *   @0x2acddc mov r0, r4
 *   @0x2acde0 bl 0x2abc94 <png_crc_finish>
 *   @0x2acde4 cmp r0, #0x0
 *   @0x2acde8 ldrb.w r2, [r4, #0x1ea]
 *   @0x2acdec ldrb.w r3, [sp]
 *   @0x2acdf0 cmp r2, #0x3
 *   @0x2acdf4 strb.w r3, [r4, #0x1fc]
 *   @0x2acdf8 cmp r6, #0x0
 *   @0x2acdfc ldrh r2, [r6, #0x14]
 *   @0x2ace00 cmp r3, r2
 *   @0x2ace04 ldr r1, [pc, #0x8c]
 *   @0x2ace08 add r1, pc
 *   @0x2ace0c eors pc, r5, r3, lsr r11
 *   @0x2ace10 ldr.w r1, [r4, #0x1d8]
 *   @0x2ace14 add.w r3, r3, r3, lsl #1
 *   @0x2ace18 adds r2, r1, r3
 *   @0x2ace1c strh.w r3, [r4, #0x1fe]
 *   @0x2ace20 ldrb r3, [r2, #0x1]
 *   @0x2ace24 ldmvc r3, {r9, r12, sp}
 *   @0x2ace28 b 0x2ace6c <png_handle_bKGD+0x10c>
 *   @0x2ace2c .word 0xf89d0f02
 *   @0x2ace30 bl 0x334e3c
 *   @0x2ace34 .word 0xd1092303
 *   @0x2ace38 uxth r3, r3
 *   @0x2ace3c .word 0xf8a43204
 *   @0x2ace40 .word 0xf8a43202
 *   @0x2ace44 .word 0xf8a43200
 *   @0x2ace48 ldrsh r3, [r1], -lr
 *   @0x2ace4c ldrb.w r2, [sp, #0x2]
 *   @0x2ace50 strh.w r3, [r4, #0x1fe]
 *   @0x2ace54 ldrb.w r3, [sp, #0x3]
 *   @0x2ace58 add.w r3, r3, r2, lsl #8
 *   @0x2ace5c ldrb.w r2, [sp, #0x4]
 *   @0x2ace60 strh.w r3, [r4, #0x200]
 *   @0x2ace64 ldrb.w r3, [sp, #0x5]
 *   @0x2ace68 add.w r3, r3, r2, lsl #8
 *   @0x2ace6c strh.w r3, [r4, #0x202]
 *   @0x2ace70 mov r0, r4
 *   @0x2ace74 add.w r2, r4, #0x1fc
 *   @0x2ace78 bl 0x2ae6b4 <png_set_bKGD>
 *   @0x2ace7c add sp, #0x8
 *   @0x2ace80 lsls r4, r7, #0x16
 *   @0x2ace84 lsls r7, r0, #0x17
 *   @0x2ace88 lsls r5, r1, #0x17
 *   @0x2ace8c lsls r6, r2, #0x17
 *   @0x2ace90 lsls r1, r1, #0x17
 *   @0x2ace94 lsls r1, r4, #0x16
 *
 * ══ §81/94 png_do_unshift  0x2a8bf2  size 310  78 条（0x2a8bf2..0x2a8d28）
 * @func 0x2a8bf2 0x2a8d2a  size 312  78 条
 * 部分覆盖: 本节 78/146 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod×2 / 0x388cee / 0x14b7d1e / 0x3a6f2e / 0x14b7d56
 * 字段偏移 top8: 0x4×3 / 0x9×1 / 0x2×1 / 0x8×1 / 0x16×1 / 0x1×1 / 0x-1×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8bf2 push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2a8bf6 mov r4, r1
 *   @0x2a8bfa cmp r1, #0x3
 *   @0x2a8bfe .word 0xf0118091
 *   @0x2a8c02 stmdavs r6, {r1, r8, r9, r10, r11}
 *   @0x2a8c06 ldrb r3, [r0, #0x9]
 *   @0x2a8c0a ldrb r5, [r2]
 *   @0x2a8c0e str r5, [sp]
 *   @0x2a8c12 subs r5, r3, r5
 *   @0x2a8c16 ldrb r5, [r2, #0x2]
 *   @0x2a8c1a str r5, [sp, #0x8]
 *   @0x2a8c1e b 0x2a8c28 <png_do_unshift+0x36>
 *   @0x2a8c22 subs r5, r3, r5
 *   @0x2a8c26 movs r5, #0x1
 *   @0x2a8c2a bpl 0x2a8c3c <png_do_unshift+0x4a>
 *   @0x2a8c2e ldrb r2, [r2, #0x4]
 *   @0x2a8c32 strlo r0, [r1, #-0x185]
 *   @0x2a8c36 subs r2, r3, r2
 *   @0x2a8c3a .word 0x21002c10
 *   @0x2a8c3e mov r2, r1
 *   @0x2a8c42 cmp r2, r5
 *   @0x2a8c46 ldr.w r7, [sp, r2, lsl #2]
 *   @0x2a8c4a cmp r7, #0x0
 *   @0x2a8c4e strle.w r8, [sp, r2, lsl #2]
 *   @0x2a8c52 add.w r2, r2, #0x1
 *   @0x2a8c56 it gt
 *   @0x2a8c5a b 0x2a8c42 <png_do_unshift+0x50>
 *   @0x2a8c5e beq 0x2a8d22 <png_do_unshift+0x130>
 *   @0x2a8c62 beq 0x2a8c92 <png_do_unshift+0xa0>
 *   @0x2a8c66 cmp r3, #0x2
 *   @0x2a8c6a ldr r3, [r0, #0x4]
 *   @0x2a8c6e b 0x2a8c80 <png_do_unshift+0x8e>
 *   @0x2a8c72 beq 0x2a8cb8 <png_do_unshift+0xc6>
 *   @0x2a8c76 bne 0x2a8d22 <png_do_unshift+0x130>
 *   @0x2a8c7a strhs pc, [r0], -r5, lsl #14
 *   @0x2a8c7e b 0x2a8ce4 <png_do_unshift+0xf2>
 *   @0x2a8c82 beq 0x2a8d22 <png_do_unshift+0x130>
 *   @0x2a8c86 lsrs r2, r2, #0x1
 *   @0x2a8c8a .word 0xf8040255
 *   @0x2a8c8e ldrb r2, [r6, r1, lsl #22]!
 *   @0x2a8c92 ldr r3, [sp]
 *   @0x2a8c96 movs r2, #0xf
 *   @0x2a8c9a asrs r2, r3
 *   @0x2a8c9e tstmi r1, #-1073741821
 *   @0x2a8ca2 ldr r2, [r0, #0x4]
 *   @0x2a8ca6 add r2, r4
 *   @0x2a8caa beq 0x2a8d22 <png_do_unshift+0x130>
 *   @0x2a8cae asrs r0, r3
 *   @0x2a8cb2 strb r0, [r4], #1
 *   @0x2a8cb6 b 0x2a8ca8 <png_do_unshift+0xb6>
 *   @0x2a8cba strhs pc, [r0], -r5, lsl #14
 *   @0x2a8cbe cmp r6, r7
 *   @0x2a8cc2 mov r0, r6
 *   @0x2a8cc6 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a8cca add r3, sp, #0x10
 *   @0x2a8cce bl 0x388cee <_ZTS13C_UTF16String+0x1fd9a>
 *   @0x2a8cd2 .word 0xf8510181
 *   @0x2a8cd6 blx 0x14b7d1e <b2_toiTime+0xd5e87a>
 *   @0x2a8cda .word 0xf804f803
 *   @0x2a8cde strlo r8, [r1], -r6
 *   @0x2a8ce2 b 0x2a8cbe <png_do_unshift+0xcc>
 *   @0x2a8ce6 add.w r4, r4, #0x2
 *   @0x2a8cea beq 0x2a8d22 <png_do_unshift+0x130>
 *   @0x2a8cee ldrtmi r8, [r0], -r2, lsl #24
 *   @0x2a8cf2 ldrb r3, [r4, #-1]
 *   @0x2a8cf6 mov r1, r5
 *   @0x2a8cfa add.w r8, r3, r8, lsl #8
 *   @0x2a8cfe blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2a8d02 add r3, sp, #0x10
 *   @0x2a8d06 bl 0x3a6f2e <_ZTSPKDn+0x1766>
 *   @0x2a8d0a .word 0xf8510181
 *   @0x2a8d0e blx 0x14b7d56 <b2_toiTime+0xd5e8b2>
 *   @0x2a8d12 .word 0xf804f303
 *   @0x2a8d16 .word 0xf3c33c01
 *   @0x2a8d1a .word 0xf8042207
 *   @0x2a8d1e strb r2, [r0, r2, lsl #24]!
 *   @0x2a8d22 add sp, #0x10
 *   @0x2a8d26 bvc 0x13894ee <b2_toiTime+0xc3004a>
 *
 * ══ §82/94 CExtensionFile::LoadFromExeStream(CStream*)  0xf525c  size 308  77 条（0xf525c..0xf5390）
 * @func 0xf525c 0xf5390  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×4 / MemoryManager::Free(void const*)×3 / CStream::ReadString(char const*&)×3 / CExtensionFile::Clear() / CExtensionFile::SetFunctionsCount(int) / CExtensionFile::LoadFromExeStream(CStream*)+0xe8 / CExtensionFunction::LoadFromExeStream(CStream*) / CExtensionFile::SetConstantsCount(int)
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x10×2 / 0x1c×2 / 0x2×2 / 0x28×2 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf525c push {r4, r5, r6, lr}
 *   @0xf5260 mov r6, r1
 *   @0xf5264 mov r4, r0
 *   @0xf5268 bl 0xf5064 <_ZN14CExtensionFile5ClearEv>
 *   @0xf526c mov r0, r6
 *   @0xf5270 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf5274 cmp r0, #700
 *   @0xf5278 beq 0xf5284 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x28>
 *   @0xf527c mov r0, #0
 *   @0xf5280 pop {r4, r5, r6, pc}
 *   @0xf5284 ldr r0, [r4, #0x4]
 *   @0xf5288 cmp r0, #0
 *   @0xf528c beq 0xf529c <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x40>
 *   @0xf5290 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5294 mov r3, #0
 *   @0xf5298 str r3, [r4, #0x4]
 *   @0xf529c mov r0, r6
 *   @0xf52a0 add r1, r4, #4
 *   @0xf52a4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf52a8 mov r0, r6
 *   @0xf52ac bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf52b0 ldr r3, [r4, #0xc]
 *   @0xf52b4 cmp r3, #0
 *   @0xf52b8 str r0, [r4, #0x8]
 *   @0xf52bc beq 0xf52d0 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x74>
 *   @0xf52c0 mov r0, r3
 *   @0xf52c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf52c8 mov r3, #0
 *   @0xf52cc str r3, [r4, #0xc]
 *   @0xf52d0 mov r0, r6
 *   @0xf52d4 add r1, r4, #12
 *   @0xf52d8 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf52dc ldr r0, [r4, #0x10]
 *   @0xf52e0 cmp r0, #0
 *   @0xf52e4 beq 0xf52f4 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x98>
 *   @0xf52e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf52ec mov r3, #0
 *   @0xf52f0 str r3, [r4, #0x10]
 *   @0xf52f4 add r1, r4, #16
 *   @0xf52f8 mov r0, r6
 *   @0xf52fc bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf5300 mov r0, r6
 *   @0xf5304 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf5308 mov r1, r0
 *   @0xf530c mov r0, r4
 *   @0xf5310 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi>
 *   @0xf5314 ldr r3, [r4, #0x1c]
 *   @0xf5318 cmp r3, #0
 *   @0xf531c movgt r5, #0
 *   @0xf5320 ble 0xf5344 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0xe8>
 *   @0xf5324 ldr r3, [r4, #0x18]
 *   @0xf5328 mov r1, r6
 *   @0xf532c ldr r0, [r3, r5, lsl #2]
 *   @0xf5330 add r5, r5, #1
 *   @0xf5334 bl 0xf4ab8 <_ZN18CExtensionFunction17LoadFromExeStreamEP7CStream>
 *   @0xf5338 ldr r3, [r4, #0x1c]
 *   @0xf533c cmp r3, r5
 *   @0xf5340 bgt 0xf5324 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0xc8>
 *   @0xf5344 mov r0, r6
 *   @0xf5348 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf534c mov r1, r0
 *   @0xf5350 mov r0, r4
 *   @0xf5354 bl 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi>
 *   @0xf5358 ldr r3, [r4, #0x28]
 *   @0xf535c cmp r3, #0
 *   @0xf5360 movgt r5, #0
 *   @0xf5364 ble 0xf5388 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x12c>
 *   @0xf5368 ldr r3, [r4, #0x24]
 *   @0xf536c mov r1, r6
 *   @0xf5370 ldr r0, [r3, r5, lsl #2]
 *   @0xf5374 add r5, r5, #1
 *   @0xf5378 bl 0xf4878 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream>
 *   @0xf537c ldr r3, [r4, #0x28]
 *   @0xf5380 cmp r3, r5
 *   @0xf5384 bgt 0xf5368 <_ZN14CExtensionFile17LoadFromExeStreamEP7CStream+0x10c>
 *   @0xf5388 mov r0, #1
 *   @0xf538c pop {r4, r5, r6, pc}
 *
 * ══ §83/94 F_DateGetWeek(RValue&, CInstance*, CInstance*, int, RValue*)  0x118190  size 308  77 条（0x118190..0x1182c4）
 * @func 0x118190 0x1182c4  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / GetSecondOfYear(int, int, int, int, int, int) / 0xb6598 / 0xb682c / 0x828f6c
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×1 / 0xcc×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x118190 push {r4, lr}
 *   @0x118194 sub sp, sp, #16
 *   @0x118198 mov r1, #0
 *   @0x11819c mov r4, r0
 *   @0x1181a0 mov r3, r1
 *   @0x1181a4 str r1, [r0, #0xc]
 *   @0x1181a8 movt r3, #0xbff0
 *   @0x1181ac stm r0, {r1, r3}
 *   @0x1181b0 ldr r0, [sp, #0x18]
 *   @0x1181b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1181b8 vldr d7, [pc, #232]
 *   @0x1181bc vldr d5, [pc, #236]
 *   @0x1181c0 vmov d6, r0, r1
 *   @0x1181c4 vsub.f64 d7, d6, d7
 *   @0x1181c8 vabs.f64 d4, d7
 *   @0x1181cc vcmpe.f64 d4, d5
 *   @0x1181d0 vmrs APSR_nzcv, fpscr
 *   @0x1181d4 vldrls d7, [pc, #220]
 *   @0x1181d8 vldrhi d6, [pc, #216]
 *   @0x1181dc vmul.f64 d5, d7, d6
 *   @0x1181e0 vmov r0, r1, d5
 *   @0x1181e4 bl 0x3194a0 <__fixdfdi>
 *   @0x1181e8 mov r3, r1
 *   @0x1181ec ldr r1, [pc, #0xcc]
 *   @0x1181f0 mov r2, r0
 *   @0x1181f4 strd r2, r3, [sp, #8]
 *   @0x1181f8 add r1, pc, r1
 *   @0x1181fc add r0, sp, #8
 *   @0x118200 ldrb r3, [r1]
 *   @0x118204 cmp r3, #0
 *   @0x118208 bne 0x11829c <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x11820c bl 0xb6820 <gmtime64@plt>
 *   @0x118210 mov r12, r0
 *   @0x118214 cmp r12, #0
 *   @0x118218 beq 0x118294 <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x11821c ldr lr, [r12, #0x4]
 *   @0x118220 ldr r0, [r12, #0x14]
 *   @0x118224 ldr r1, [r12, #0x10]
 *   @0x118228 ldr r2, [r12, #0xc]
 *   @0x11822c add r0, r0, #1888
 *   @0x118230 ldr r3, [r12, #0x8]
 *   @0x118234 add r1, r1, #1
 *   @0x118238 str lr, [sp]
 *   @0x11823c add r2, r2, #1
 *   @0x118240 ldr r12, [r12]
 *   @0x118244 add r0, r0, #12
 *   @0x118248 str r12, [sp, #0x4]
 *   @0x11824c bl 0x1180c0 <_Z15GetSecondOfYeariiiiii>
 *   @0x118250 movw r3, #0x4507
 *   @0x118254 movt r3, #0xc22e
 *   @0x118258 vmov.f64 d7, #7.000000e+00
 *   @0x11825c smull r1, r3, r3, r0
 *   @0x118260 asr r2, r0, #31
 *   @0x118264 add r0, r3, r0
 *   @0x118268 rsb r0, r2, r0, asr #16
 *   @0x11826c vmov s10, r0
 *   @0x118270 vcvt.f64.s32 d6, s10
 *   @0x118274 vdiv.f64 d5, d6, d7
 *   @0x118278 vmov r0, r1, d5
 *   @0x11827c bl 0xb6598 <floor@plt>
 *   @0x118280 vmov d6, r0, r1
 *   @0x118284 vcvt.s32.f64 s15, d6
 *   @0x118288 vcvt.f64.s32 d5, s15
 *   @0x11828c vmov r2, r3, d5
 *   @0x118290 stm r4, {r2, r3}
 *   @0x118294 add sp, sp, #16
 *   @0x118298 pop {r4, pc}
 *   @0x11829c bl 0xb682c <localtime64@plt>
 *   @0x1182a0 mov r12, r0
 *   @0x1182a4 b 0x118214 <_Z13F_DateGetWeekR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1182a8 andeq r0, r0, r0
 *   @0x1182ac sbcsmi pc, r8, r0, asr #16
 *   @0x1182b0 bl 0x828f6c <b2_toiTime+0xcfac8>
 *   @0x1182b4 svclo #0x1a36e2
 *   @0x1182b8 andeq r0, r0, r0
 *   @0x1182bc rscsmi r1, r5, r0, lsl #16
 *   @0x1182c0 eoreq r9, sp, r0, asr #30
 *
 * ══ §84/94 F_RoomSetView(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e2e8  size 308  77 条（0x12e2e8..0x12e41c）
 * @func 0x12e2e8 0x12e41c  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×11 / YYGetFloat(RValue const*, int)×4 / Room_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x2×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e2e8 push {r4, r5, r6, lr}
 *   @0x12e2ec mov r1, #0
 *   @0x12e2f0 ldr r4, [sp, #0x10]
 *   @0x12e2f4 mov r0, r4
 *   @0x12e2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e2fc mov r1, #1
 *   @0x12e300 mov r6, r0
 *   @0x12e304 mov r0, r4
 *   @0x12e308 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e30c mov r5, r0
 *   @0x12e310 mov r0, r6
 *   @0x12e314 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e318 cmp r0, #0
 *   @0x12e31c popeq {r4, r5, r6, pc}
 *   @0x12e320 cmp r5, #7
 *   @0x12e324 pophi {r4, r5, r6, pc}
 *   @0x12e328 add r5, r5, #18
 *   @0x12e32c ldr r5, [r0, r5, lsl #2]
 *   @0x12e330 cmp r5, #0
 *   @0x12e334 popeq {r4, r5, r6, pc}
 *   @0x12e338 mov r1, #2
 *   @0x12e33c mov r0, r4
 *   @0x12e340 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e344 mov r1, #3
 *   @0x12e348 strb r0, [r5]
 *   @0x12e34c mov r0, r4
 *   @0x12e350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e354 mov r1, #4
 *   @0x12e358 str r0, [r5, #0x4]
 *   @0x12e35c mov r0, r4
 *   @0x12e360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e364 mov r1, #5
 *   @0x12e368 str r0, [r5, #0x8]
 *   @0x12e36c mov r0, r4
 *   @0x12e370 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e374 mov r1, #6
 *   @0x12e378 str r0, [r5, #0xc]
 *   @0x12e37c mov r0, r4
 *   @0x12e380 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12e384 mov r1, #7
 *   @0x12e388 str r0, [r5, #0x10]
 *   @0x12e38c mov r0, r4
 *   @0x12e390 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e394 mov r1, #8
 *   @0x12e398 str r0, [r5, #0x14]
 *   @0x12e39c mov r0, r4
 *   @0x12e3a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3a4 mov r1, #9
 *   @0x12e3a8 str r0, [r5, #0x18]
 *   @0x12e3ac mov r0, r4
 *   @0x12e3b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3b4 mov r1, #10
 *   @0x12e3b8 str r0, [r5, #0x1c]
 *   @0x12e3bc mov r0, r4
 *   @0x12e3c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3c4 mov r1, #11
 *   @0x12e3c8 str r0, [r5, #0x20]
 *   @0x12e3cc mov r0, r4
 *   @0x12e3d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3d4 mov r1, #12
 *   @0x12e3d8 str r0, [r5, #0x28]
 *   @0x12e3dc mov r0, r4
 *   @0x12e3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3e4 mov r1, #13
 *   @0x12e3e8 str r0, [r5, #0x2c]
 *   @0x12e3ec mov r0, r4
 *   @0x12e3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e3f4 mov r1, #14
 *   @0x12e3f8 str r0, [r5, #0x30]
 *   @0x12e3fc mov r0, r4
 *   @0x12e400 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e404 mov r1, #15
 *   @0x12e408 str r0, [r5, #0x34]
 *   @0x12e40c mov r0, r4
 *   @0x12e410 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e414 str r0, [r5, #0x38]
 *   @0x12e418 pop {r4, r5, r6, pc}
 *
 * ══ §85/94 F_BackgroundSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x12fee8  size 308  77 条（0x12fee8..0x13001c）
 * @func 0x12fee8 0x13001c  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / Background_Data(int) / CBitmap32::CreateBitmap32() / CBackground::GetWidth() / CBackground::GetHeight() / WritePNG32(char*, void*, int, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x28×2 / 0x4×2 / 0x34×2 / 0x10×1 / 0x-4×1 / 0x24×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12fee8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12feec sub sp, sp, #12
 *   @0x12fef0 mov r1, #0
 *   @0x12fef4 ldr r4, [sp, #0x28]
 *   @0x12fef8 mov r0, r4
 *   @0x12fefc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ff00 mov r1, #1
 *   @0x12ff04 mov r5, r0
 *   @0x12ff08 mov r0, r4
 *   @0x12ff0c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12ff10 mov r6, r0
 *   @0x12ff14 mov r0, r5
 *   @0x12ff18 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12ff1c cmp r6, #0
 *   @0x12ff20 cmpne r0, #0
 *   @0x12ff24 mov r4, r0
 *   @0x12ff28 moveq r1, #0
 *   @0x12ff2c movne r1, #1
 *   @0x12ff30 beq 0x12fffc <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x12ff34 ldr r0, [r0, #0x10]
 *   @0x12ff38 cmp r0, #0
 *   @0x12ff3c beq 0x12ffd4 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x12ff40 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev>
 *   @0x12ff44 subs r5, r0, #0
 *   @0x12ff48 beq 0x12ffd4 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x12ff4c add r2, sp, #8
 *   @0x12ff50 mov r3, #0
 *   @0x12ff54 mov r1, r3
 *   @0x12ff58 str r3, [r2, #-0x4]!
 *   @0x12ff5c ldr r12, [r5]
 *   @0x12ff60 str r3, [sp]
 *   @0x12ff64 mov r3, sp
 *   @0x12ff68 ldr r12, [r12, #0x24]
 *   @0x12ff6c blx r12
 *   @0x12ff70 ldr r7, [sp, #0x4]
 *   @0x12ff74 cmp r7, #0
 *   @0x12ff78 mov r8, r0
 *   @0x12ff7c beq 0x12ffa8 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12ff80 mov r0, r4
 *   @0x12ff84 bl 0xc2d78 <_ZN11CBackground8GetWidthEv>
 *   @0x12ff88 mov r9, r0
 *   @0x12ff8c mov r0, r4
 *   @0x12ff90 bl 0xc2d80 <_ZN11CBackground9GetHeightEv>
 *   @0x12ff94 mov r1, r7
 *   @0x12ff98 mov r2, r9
 *   @0x12ff9c mov r3, r0
 *   @0x12ffa0 mov r0, r6
 *   @0x12ffa4 bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x12ffa8 ldr r3, [r5]
 *   @0x12ffac mov r1, r8
 *   @0x12ffb0 mov r0, r5
 *   @0x12ffb4 ldr r3, [r3, #0x28]
 *   @0x12ffb8 blx r3
 *   @0x12ffbc ldr r3, [r5]
 *   @0x12ffc0 mov r0, r5
 *   @0x12ffc4 ldr r3, [r3, #0x4]
 *   @0x12ffc8 blx r3
 *   @0x12ffcc add sp, sp, #12
 *   @0x12ffd0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12ffd4 ldr r3, [pc, #0x34]
 *   @0x12ffd8 ldr r1, [pc, #0x34]
 *   @0x12ffdc ldr r3, [pc, r3]
 *   @0x12ffe0 add r1, pc, r1
 *   @0x12ffe4 ldr r0, [r3]
 *   @0x12ffe8 ldr r3, [r0]
 *   @0x12ffec ldr r3, [r3, #0xc]
 *   @0x12fff0 blx r3
 *   @0x12fff4 add sp, sp, #12
 *   @0x12fff8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12fffc ldr r0, [pc, #0x14]
 *   @0x130000 add r0, pc, r0
 *   @0x130004 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130008 add sp, sp, #12
 *   @0x13000c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x130010 eoreq sp, r11, r8, lsr r7
 *   @0x130014 .word 0x0020dbd0
 *   @0x130018 eoreq sp, r0, r8, ror #23
 *
 * ══ §86/94 json_parse_array_to_list(json_object*, char*, CDS_List*)  0x13d140  size 308  77 条（0x13d140..0x13d274）
 * @func 0x13d140 0x13d274  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::Add(RValue*)×2 / json_object_object_get / json_object_array_length / json_parse_array_to_list(json_object*, char*, CDS_List*)+0x108 / json_value(json_object*, RValue*) / json_object_array_get_idx / json_object_get_type / json_parse(json_object*)
 * 字段偏移 top8: 0x1c×6 / 0x18×2 / 0x4×1 / 0xc×1 / 0x8×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d140 cmp r1, #0
 *   @0x13d144 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13d148 mov r9, r2
 *   @0x13d14c sub sp, sp, #36
 *   @0x13d150 mov r7, r0
 *   @0x13d154 beq 0x13d160 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x20>
 *   @0x13d158 bl 0x27ea38 <json_object_object_get>
 *   @0x13d15c mov r7, r0
 *   @0x13d160 mov r0, r7
 *   @0x13d164 bl 0x27ede8 <json_object_array_length>
 *   @0x13d168 subs r8, r0, #0
 *   @0x13d16c ble 0x13d248 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x108>
 *   @0x13d170 mov r4, #0
 *   @0x13d174 add r3, sp, #24
 *   @0x13d178 add r6, sp, #16
 *   @0x13d17c str r3, [sp, #0x4]
 *   @0x13d180 add r11, sp, #20
 *   @0x13d184 add r3, sp, #28
 *   @0x13d188 str r6, [sp, #0xc]
 *   @0x13d18c mov r5, r4
 *   @0x13d190 str r3, [sp, #0x8]
 *   @0x13d194 b 0x13d1b4 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x74>
 *   @0x13d198 bl 0x13c274 <_Z10json_valueP11json_objectP6RValue>
 *   @0x13d19c mov r0, r9
 *   @0x13d1a0 mov r1, r6
 *   @0x13d1a4 add r4, r4, #1
 *   @0x13d1a8 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0x13d1ac cmp r4, r8
 *   @0x13d1b0 beq 0x13d248 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x108>
 *   @0x13d1b4 mov r0, r7
 *   @0x13d1b8 mov r1, r4
 *   @0x13d1bc bl 0x27ee00 <json_object_array_get_idx>
 *   @0x13d1c0 subs r10, r0, #0
 *   @0x13d1c4 beq 0x13d21c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0xdc>
 *   @0x13d1c8 bl 0x27e828 <json_object_get_type>
 *   @0x13d1cc mov r1, r6
 *   @0x13d1d0 str r5, [r6]
 *   @0x13d1d4 str r5, [r11]
 *   @0x13d1d8 str r5, [sp, #0x18]
 *   @0x13d1dc str r5, [sp, #0x1c]
 *   @0x13d1e0 mov r2, r0
 *   @0x13d1e4 cmp r2, #5
 *   @0x13d1e8 mov r0, r10
 *   @0x13d1ec beq 0x13d250 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x110>
 *   @0x13d1f0 cmp r2, #4
 *   @0x13d1f4 bne 0x13d198 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x58>
 *   @0x13d1f8 mov r0, r10
 *   @0x13d1fc bl 0x13d0dc <_Z10json_parseP11json_object>
 *   @0x13d200 ldr r3, [sp, #0x1c]
 *   @0x13d204 orr r3, r3, #-2147483648
 *   @0x13d208 str r3, [sp, #0x1c]
 *   @0x13d20c vmov s13, r0
 *   @0x13d210 vcvt.f64.s32 d7, s13
 *   @0x13d214 vstr d7, [sp, #16]
 *   @0x13d218 b 0x13d19c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x5c>
 *   @0x13d21c add r1, sp, #16
 *   @0x13d220 mov r0, r9
 *   @0x13d224 add r4, r4, #1
 *   @0x13d228 str r10, [r6]
 *   @0x13d22c str r10, [r11]
 *   @0x13d230 mov r6, r1
 *   @0x13d234 str r10, [sp, #0x18]
 *   @0x13d238 str r10, [sp, #0x1c]
 *   @0x13d23c bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0x13d240 cmp r4, r8
 *   @0x13d244 bne 0x13d1b4 <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x74>
 *   @0x13d248 add sp, sp, #36
 *   @0x13d24c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13d250 mov r1, #0
 *   @0x13d254 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc>
 *   @0x13d258 ldr r3, [sp, #0x1c]
 *   @0x13d25c orr r3, r3, #1073741824
 *   @0x13d260 str r3, [sp, #0x1c]
 *   @0x13d264 vmov s13, r0
 *   @0x13d268 vcvt.f64.s32 d7, s13
 *   @0x13d26c vstr d7, [sp, #16]
 *   @0x13d270 b 0x13d19c <_Z24json_parse_array_to_listP11json_objectPcP8CDS_List+0x5c>
 *
 * ══ §87/94 SGamepadMapping::CreateFromFileAsString(unsigned char*, int)  0x1529e0  size 308  77 条（0x1529e0..0x152b14）
 * @func 0x1529e0 0x152b14  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYAlloc(int) / 0xb65bc / SGamepadMapping::CreateFromFileAsString(unsigned char*, int)+0xbc / SGamepadMapping::CreateFromString(char const*) / YYFree(void const*)
 * 字段偏移 top8: 0x10c×1 / 0x1×1 / 0x-1×1 / 0x20×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1529e0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1529e4 subs r4, r0, #0
 *   @0x1529e8 mov r5, r1
 *   @0x1529ec moveq r6, r4
 *   @0x1529f0 beq 0x152aa4 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xc4>
 *   @0x1529f4 mov r0, r1
 *   @0x1529f8 ldr r7, [pc, #0x10c]
 *   @0x1529fc bl 0xcef4c <_Z7YYAlloci>
 *   @0x152a00 mov r1, r4
 *   @0x152a04 mov r2, r5
 *   @0x152a08 mov r6, #0
 *   @0x152a0c mov r9, r6
 *   @0x152a10 add r7, pc, r7
 *   @0x152a14 mov r8, r0
 *   @0x152a18 bl 0xb65bc <memcpy@plt>
 *   @0x152a1c mov r10, r8
 *   @0x152a20 rsb r3, r8, r10
 *   @0x152a24 cmp r5, r3
 *   @0x152a28 ble 0x152a9c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xbc>
 *   @0x152a2c ldrb r2, [r10]
 *   @0x152a30 cmp r2, #13
 *   @0x152a34 beq 0x152aac <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xcc>
 *   @0x152a38 cmp r2, #10
 *   @0x152a3c beq 0x152aac <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xcc>
 *   @0x152a40 add r3, r10, #1
 *   @0x152a44 b 0x152a5c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x7c>
 *   @0x152a48 ldrb r12, [r3], #1
 *   @0x152a4c cmp r12, #13
 *   @0x152a50 beq 0x152ab0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd0>
 *   @0x152a54 cmp r12, #10
 *   @0x152a58 beq 0x152ab0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd0>
 *   @0x152a5c rsb r12, r8, r3
 *   @0x152a60 mov r4, r3
 *   @0x152a64 cmp r5, r12
 *   @0x152a68 bgt 0x152a48 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x68>
 *   @0x152a6c mov r3, r2
 *   @0x152a70 cmp r3, #35
 *   @0x152a74 beq 0x152a8c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xac>
 *   @0x152a78 mov r0, r10
 *   @0x152a7c bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc>
 *   @0x152a80 cmp r0, #0
 *   @0x152a84 addne r6, r6, #1
 *   @0x152a88 beq 0x152ae8 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x108>
 *   @0x152a8c mov r10, r4
 *   @0x152a90 rsb r3, r8, r10
 *   @0x152a94 cmp r5, r3
 *   @0x152a98 bgt 0x152a2c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x4c>
 *   @0x152a9c mov r0, r8
 *   @0x152aa0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x152aa4 mov r0, r6
 *   @0x152aa8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x152aac mov r4, r10
 *   @0x152ab0 add r3, r4, #1
 *   @0x152ab4 rsb r2, r8, r3
 *   @0x152ab8 mov r4, r3
 *   @0x152abc cmp r5, r2
 *   @0x152ac0 strb r9, [r3, #-0x1]
 *   @0x152ac4 bgt 0x152ad0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xf0>
 *   @0x152ac8 ldrb r3, [r10]
 *   @0x152acc b 0x152a70 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x90>
 *   @0x152ad0 ldrb r2, [r3]
 *   @0x152ad4 add r3, r4, #1
 *   @0x152ad8 cmp r2, #13
 *   @0x152adc cmpne r2, #10
 *   @0x152ae0 beq 0x152ab4 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd4>
 *   @0x152ae4 b 0x152ac8 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xe8>
 *   @0x152ae8 ldr r3, [pc, #0x20]
 *   @0x152aec mov r2, r10
 *   @0x152af0 mov r1, r7
 *   @0x152af4 ldr r3, [pc, r3]
 *   @0x152af8 ldr r0, [r3]
 *   @0x152afc ldr r3, [r0]
 *   @0x152b00 ldr r3, [r3, #0xc]
 *   @0x152b04 blx r3
 *   @0x152b08 b 0x152a8c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xac>
 *   @0x152b0c andseq r3, pc, r0, asr #4
 *   @0x152b10 eoreq r10, r9, r12, asr #28
 *
 * ══ §88/94 GR_Draw_Primitive_End()  0x16bdb0  size 308  77 条（0x16bdb0..0x16bee4）
 * @func 0x16bdb0 0x16bee4  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16bdb8→0x4899ac, 0x16bdf8→0x4899b0, 0x16be08→0x3f23c8, 0x16be24→0x48ffec, 0x16be58→0x4899b4, 0x16be70→0x4899b0, 0x16be80→0x4899b0, 0x16be98→0x4899b0
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x110×2 / 0xd4×1 / 0xc8×1 / 0xb0×1 / 0x4×1 / 0x2×1 / 0x80×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bdb0 push {r4, r5, r6, r7, r8, lr}
 *   @0x16bdb4 ldr r4, [pc, #0x110]
 *   @0x16bdb8 ldr r3, [pc, #0x110]
 *   @0x16bdbc add r4, pc, r4
 *   @0x16bdc0 ldr r5, [r4, r3]
 *   @0x16bdc4 ldr r3, [r5]
 *   @0x16bdc8 sub r2, r3, #1
 *   @0x16bdcc cmp r2, #5
 *   @0x16bdd0 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x16bdd4 sub r3, r3, #2
 *   @0x16bdd8 cmp r3, #4
 *   @0x16bddc addls pc, pc, r3, lsl #2
 *   @0x16bde0 b 0x16be70 <_Z21GR_Draw_Primitive_Endv+0xc0>
 *   @0x16bde4 b 0x16be80 <_Z21GR_Draw_Primitive_Endv+0xd0>
 *   @0x16bde8 b 0x16be98 <_Z21GR_Draw_Primitive_Endv+0xe8>
 *   @0x16bdec b 0x16beac <_Z21GR_Draw_Primitive_Endv+0xfc>
 *   @0x16bdf0 b 0x16bdf8 <_Z21GR_Draw_Primitive_Endv+0x48>
 *   @0x16bdf4 b 0x16bdf8 <_Z21GR_Draw_Primitive_Endv+0x48>
 *   @0x16bdf8 ldr r3, [pc, #0xd4]
 *   @0x16bdfc ldr r6, [r4, r3]
 *   @0x16be00 ldr r8, [r6]
 *   @0x16be04 sub r8, r8, #2
 *   @0x16be08 ldr r3, [pc, #0xc8]
 *   @0x16be0c ldr r7, [r4, r3]
 *   @0x16be10 ldr r0, [r7]
 *   @0x16be14 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x16be18 cmp r0, #0
 *   @0x16be1c moveq r1, r0
 *   @0x16be20 beq 0x16be3c <_Z21GR_Draw_Primitive_Endv+0x8c>
 *   @0x16be24 ldr r3, [pc, #0xb0]
 *   @0x16be28 ldr r2, [r7]
 *   @0x16be2c ldr r3, [r4, r3]
 *   @0x16be30 ldr r3, [r3, #0x4]
 *   @0x16be34 ldr r3, [r3, r2, lsl #2]
 *   @0x16be38 ldr r1, [r3]
 *   @0x16be3c cmp r8, #0
 *   @0x16be40 pople {r4, r5, r6, r7, r8, pc}
 *   @0x16be44 ldr r3, [r6]
 *   @0x16be48 mov r2, #24
 *   @0x16be4c ldr r0, [r5]
 *   @0x16be50 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16be54 ldr r2, [r6]
 *   @0x16be58 ldr r3, [pc, #0x80]
 *   @0x16be5c add r2, r2, r2, lsl #1
 *   @0x16be60 ldr r1, [r4, r3]
 *   @0x16be64 lsl r2, r2, #3
 *   @0x16be68 pop {r4, r5, r6, r7, r8, lr}
 *   @0x16be6c b 0xb65bc <memcpy@plt>
 *   @0x16be70 ldr r3, [pc, #0x5c]
 *   @0x16be74 ldr r6, [r4, r3]
 *   @0x16be78 ldr r8, [r6]
 *   @0x16be7c b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58>
 *   @0x16be80 ldr r3, [pc, #0x4c]
 *   @0x16be84 ldr r6, [r4, r3]
 *   @0x16be88 ldr r8, [r6]
 *   @0x16be8c add r8, r8, r8, lsr #31
 *   @0x16be90 asr r8, r8, #1
 *   @0x16be94 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58>
 *   @0x16be98 ldr r3, [pc, #0x34]
 *   @0x16be9c ldr r6, [r4, r3]
 *   @0x16bea0 ldr r8, [r6]
 *   @0x16bea4 sub r8, r8, #1
 *   @0x16bea8 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58>
 *   @0x16beac ldr r3, [pc, #0x20]
 *   @0x16beb0 movw r8, #0x5556
 *   @0x16beb4 movt r8, #0x5555
 *   @0x16beb8 ldr r6, [r4, r3]
 *   @0x16bebc ldr r3, [r6]
 *   @0x16bec0 smull r2, r8, r8, r3
 *   @0x16bec4 sub r8, r8, r3, asr #31
 *   @0x16bec8 b 0x16be08 <_Z21GR_Draw_Primitive_Endv+0x58>
 *   @0x16becc mlaeq r8, r4, lr, r5
 *   @0x16bed0 .word 0xffffe538
 *   @0x16bed4 .word 0xffffe534
 *   @0x16bed8 .word 0xffffe53c
 *   @0x16bedc .word 0xffffbccc
 *   @0x16bee0 .word 0xffffe54c
 *
 * ══ §89/94 VertexBuffer::Init(int, int, int)  0x18378c  size 308  77 条（0x18378c..0x1838c0）
 * @func 0x18378c 0x1838c0  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1837cc→0x4a2121, 0x183804→0x479b98, 0x183834→0x479b94, 0x18385c→0x7577b8, 0x183878→0x3eb70c
 * 调用序列: GetVertexFormat(int) / operator delete(void*) / operator new(unsigned int)
 * 字段偏移 top8: 0xc×4 / 0x108×1 / 0x20×1 / 0xd4×1 / 0x24×1 / 0x30×1 / 0x8×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18378c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x183790 tst r1, #16777216
 *   @0x183794 ldr r7, [pc, #0x108]
 *   @0x183798 mov r6, r0
 *   @0x18379c mov r8, r2
 *   @0x1837a0 mov r4, r1
 *   @0x1837a4 add r7, pc, r7
 *   @0x1837a8 str r1, [r6, #0x20]
 *   @0x1837ac mov r9, r3
 *   @0x1837b0 moveq r2, r1
 *   @0x1837b4 beq 0x1837cc <_ZN12VertexBuffer4InitEiii+0x40>
 *   @0x1837b8 mov r0, r1
 *   @0x1837bc bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x1837c0 cmp r0, #0
 *   @0x1837c4 ldrne r2, [r0, #0x14]
 *   @0x1837c8 beq 0x183878 <_ZN12VertexBuffer4InitEiii+0xec>
 *   @0x1837cc ldr r3, [pc, #0xd4]
 *   @0x1837d0 mov r4, #0
 *   @0x1837d4 str r2, [r6, #0x24]
 *   @0x1837d8 mov r5, #0
 *   @0x1837dc str r8, [r6, #0x30]
 *   @0x1837e0 str r9, [r6, #0x8]
 *   @0x1837e4 strd r4, r5, [r6, #56]
 *   @0x1837e8 ldr r3, [r7, r3]
 *   @0x1837ec ldrb r0, [r3]
 *   @0x1837f0 cmp r0, #0
 *   @0x1837f4 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1837f8 ldr r4, [r6, #0xc]
 *   @0x1837fc cmp r4, #0
 *   @0x183800 beq 0x18382c <_ZN12VertexBuffer4InitEiii+0xa0>
 *   @0x183804 ldr r3, [pc, #0xa0]
 *   @0x183808 mov r0, #1
 *   @0x18380c mov r1, r4
 *   @0x183810 ldr r3, [r7, r3]
 *   @0x183814 ldr r3, [r3]
 *   @0x183818 blx r3
 *   @0x18381c mov r0, r4
 *   @0x183820 bl 0x27d1d0 <_ZdlPv>
 *   @0x183824 mov r3, #0
 *   @0x183828 str r3, [r6, #0xc]
 *   @0x18382c mov r0, #8
 *   @0x183830 bl 0x27c524 <_Znwj>
 *   @0x183834 ldr r3, [pc, #0x74]
 *   @0x183838 mvn r2, #0
 *   @0x18383c mov r1, #0
 *   @0x183840 stm r0, {r1, r2}
 *   @0x183844 mov r4, r0
 *   @0x183848 ldr r3, [r7, r3]
 *   @0x18384c mov r1, r0
 *   @0x183850 mov r0, #1
 *   @0x183854 ldr r3, [r3]
 *   @0x183858 blx r3
 *   @0x18385c ldr r3, [pc, #0x50]
 *   @0x183860 mov r0, #1
 *   @0x183864 ldr r3, [r7, r3]
 *   @0x183868 ldr r3, [r3]
 *   @0x18386c str r3, [r4, #0x4]
 *   @0x183870 str r4, [r6, #0xc]
 *   @0x183874 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x183878 ldr r3, [pc, #0x38]
 *   @0x18387c mov r2, r4
 *   @0x183880 ldr r1, [pc, #0x34]
 *   @0x183884 ldr r3, [r7, r3]
 *   @0x183888 add r1, pc, r1
 *   @0x18388c ldr r0, [r3]
 *   @0x183890 ldr r3, [r0]
 *   @0x183894 ldr r3, [r3, #0xc]
 *   @0x183898 blx r3
 *   @0x18389c mov r2, #1
 *   @0x1838a0 b 0x1837cc <_ZN12VertexBuffer4InitEiii+0x40>
 *   @0x1838a4 eoreq lr, r6, r12, lsr #9
 *   @0x1838a8 .word 0xffffe7e0
 *   @0x1838ac .word 0xffffbb34
 *   @0x1838b0 .word 0xffffbb38
 *   @0x1838b4 .word 0xffffe90c
 *   @0x1838b8 .word 0xffffbac4
 *   @0x1838bc ldrsheq r8, [r12], -r4
 *
 * ══ §90/94 CSprite::InitLocalTPE()  0x1e5854  size 308  77 条（0x1e5854..0x1e5988）
 * @func 0x1e5854 0x1e5988  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CSprite::InitLocalTPE()+0x4c / CSprite::InitLocalTPE()+0x120 / CBitmap32::GetWidth() / CBitmap32::GetHeight() / CSprite::InitLocalTPE()+0x98
 * 字段偏移 top8: 0x2×7 / 0x54×6 / 0x38×3 / 0x44×3 / 0x36×2 / 0x48×2 / 0x4×2 / 0xd0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5854 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e5858 mov r5, r0
 *   @0x1e585c ldr r0, [r0, #0x54]
 *   @0x1e5860 cmp r0, #0
 *   @0x1e5864 beq 0x1e58ac <_ZN7CSprite12InitLocalTPEEv+0x58>
 *   @0x1e5868 ldrb r3, [r5, #0x36]
 *   @0x1e586c cmp r3, #0
 *   @0x1e5870 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1e5874 ldr r3, [r5, #0x38]
 *   @0x1e5878 cmp r3, #0
 *   @0x1e587c ble 0x1e58a0 <_ZN7CSprite12InitLocalTPEEv+0x4c>
 *   @0x1e5880 mov r4, #0
 *   @0x1e5884 ldr r0, [r0, r4, lsl #2]
 *   @0x1e5888 add r4, r4, #1
 *   @0x1e588c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e5890 ldr r3, [r5, #0x38]
 *   @0x1e5894 ldr r0, [r5, #0x54]
 *   @0x1e5898 cmp r3, r4
 *   @0x1e589c bgt 0x1e5884 <_ZN7CSprite12InitLocalTPEEv+0x30>
 *   @0x1e58a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e58a4 mov r3, #0
 *   @0x1e58a8 str r3, [r5, #0x54]
 *   @0x1e58ac ldr r8, [pc, #0xd0]
 *   @0x1e58b0 movw r2, #0x76a
 *   @0x1e58b4 ldr r0, [r5, #0x44]
 *   @0x1e58b8 mov r3, #1
 *   @0x1e58bc add r8, pc, r8
 *   @0x1e58c0 lsl r0, r0, #2
 *   @0x1e58c4 mov r1, r8
 *   @0x1e58c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e58cc ldr r2, [r5, #0x44]
 *   @0x1e58d0 cmp r2, #0
 *   @0x1e58d4 str r0, [r5, #0x54]
 *   @0x1e58d8 ble 0x1e5974 <_ZN7CSprite12InitLocalTPEEv+0x120>
 *   @0x1e58dc mov r6, #0
 *   @0x1e58e0 mov r4, r0
 *   @0x1e58e4 mov r7, r6
 *   @0x1e58e8 b 0x1e58f0 <_ZN7CSprite12InitLocalTPEEv+0x9c>
 *   @0x1e58ec ldr r4, [r5, #0x54]
 *   @0x1e58f0 mov r1, r8
 *   @0x1e58f4 movw r2, #0x76d
 *   @0x1e58f8 mov r3, #1
 *   @0x1e58fc mov r0, #22
 *   @0x1e5900 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e5904 str r0, [r4, r6, lsl #2]
 *   @0x1e5908 ldr r2, [r5, #0x54]
 *   @0x1e590c ldr r3, [r5, #0x48]
 *   @0x1e5910 ldr r4, [r2, r6, lsl #2]
 *   @0x1e5914 ldr r0, [r3, r6, lsl #2]
 *   @0x1e5918 strh r7, [r4]
 *   @0x1e591c strh r7, [r4, #2]
 *   @0x1e5920 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x1e5924 ldr r3, [r5, #0x48]
 *   @0x1e5928 strh r0, [r4, #4]
 *   @0x1e592c ldr r0, [r3, r6, lsl #2]
 *   @0x1e5930 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x1e5934 ldr r1, [r5, #0x50]
 *   @0x1e5938 ldr r2, [r5, #0x44]
 *   @0x1e593c ldrh r3, [r4, #4]
 *   @0x1e5940 ldr r1, [r1, r6, lsl #2]
 *   @0x1e5944 add r6, r6, #1
 *   @0x1e5948 cmp r6, r2
 *   @0x1e594c strh r7, [r4, #8]
 *   @0x1e5950 strh r7, [r4, #10]
 *   @0x1e5954 strh r1, [r4, #20]
 *   @0x1e5958 strh r3, [r4, #12]
 *   @0x1e595c strh r3, [r4, #16]
 *   @0x1e5960 uxth r0, r0
 *   @0x1e5964 strh r0, [r4, #6]
 *   @0x1e5968 strh r0, [r4, #14]
 *   @0x1e596c strh r0, [r4, #18]
 *   @0x1e5970 blt 0x1e58ec <_ZN7CSprite12InitLocalTPEEv+0x98>
 *   @0x1e5974 mov r3, #1
 *   @0x1e5978 str r2, [r5, #0x38]
 *   @0x1e597c strb r3, [r5, #0x36]
 *   @0x1e5980 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e5984 andseq r12, r6, r8, ror #22
 *
 * ══ §91/94 GV_PhysicsSpeed(CInstance*, int, RValue*)  0x1faa34  size 308  77 条（0x1faa34..0x1fab68）
 * @func 0x1faa34 0x1fab68  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()×2 / 0xb6700
 * 字段偏移 top8: 0x4×4 / 0x120×1 / 0x84×1 / 0xb4×1 / 0xf0×1 / 0xc×1 / 0x74×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faa34 ldr r3, [pc, #0x120]
 *   @0x1faa38 push {r4, r5, r6, r7, lr}
 *   @0x1faa3c vpush {d8}
 *   @0x1faa40 ldr r3, [pc, r3]
 *   @0x1faa44 ldr r5, [r0, #0x84]
 *   @0x1faa48 sub sp, sp, #12
 *   @0x1faa4c ldr r1, [r3]
 *   @0x1faa50 ldr r4, [r1, #0xb4]
 *   @0x1faa54 cmp r5, #0
 *   @0x1faa58 cmpne r4, #0
 *   @0x1faa5c moveq r6, #0
 *   @0x1faa60 movne r6, #1
 *   @0x1faa64 beq 0x1faad8 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0xa4>
 *   @0x1faa68 ldr r3, [pc, #0xf0]
 *   @0x1faa6c mov r0, #0
 *   @0x1faa70 str r0, [r2, #0xc]
 *   @0x1faa74 ldr r3, [pc, r3]
 *   @0x1faa78 ldrb r3, [r3]
 *   @0x1faa7c cmp r3, r0
 *   @0x1faa80 bne 0x1faae8 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0xb4>
 *   @0x1faa84 ldr r3, [r5]
 *   @0x1faa88 vldr s13, [r4, #96]
 *   @0x1faa8c vldr s16, [r3, #80]
 *   @0x1faa90 vldr s12, [r3, #84]
 *   @0x1faa94 vdiv.f32 s16, s16, s13
 *   @0x1faa98 vldr s15, [r1, #12]
 *   @0x1faa9c vdiv.f32 s13, s12, s13
 *   @0x1faaa0 vcvt.f32.s32 s15, s15
 *   @0x1faaa4 vdiv.f32 s16, s16, s15
 *   @0x1faaa8 vdiv.f32 s14, s13, s15
 *   @0x1faaac vmul.f32 s14, s14, s14
 *   @0x1faab0 vmla.f32 s14, s16, s16
 *   @0x1faab4 vsqrt.f32 s15, s14
 *   @0x1faab8 vcmp.f32 s15, s15
 *   @0x1faabc vmrs APSR_nzcv, fpscr
 *   @0x1faac0 bne 0x1fab44 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x110>
 *   @0x1faac4 vcvt.f64.f32 d6, s15
 *   @0x1faac8 vmov r4, r5, d6
 *   @0x1faacc vmov r1, s12
 *   @0x1faad0 mov r3, r5
 *   @0x1faad4 stm r2, {r1, r3}
 *   @0x1faad8 mov r0, r6
 *   @0x1faadc add sp, sp, #12
 *   @0x1faae0 vpop {d8}
 *   @0x1faae4 pop {r4, r5, r6, r7, pc}
 *   @0x1faae8 ldr r7, [pc, #0x74]
 *   @0x1faaec vldr s15, [r4, #96]
 *   @0x1faaf0 ldr r3, [r5]
 *   @0x1faaf4 vldr s16, [r3, #80]
 *   @0x1faaf8 ldr r7, [pc, r7]
 *   @0x1faafc vdiv.f32 s16, s16, s15
 *   @0x1fab00 str r2, [sp, #0x4]
 *   @0x1fab04 mov r0, r7
 *   @0x1fab08 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1fab0c ldr r3, [r5]
 *   @0x1fab10 vldr s15, [r4, #96]
 *   @0x1fab14 vldr s17, [r3, #84]
 *   @0x1fab18 vmov d6, r0, r1
 *   @0x1fab1c mov r0, r7
 *   @0x1fab20 vcvt.f32.f64 s14, d6
 *   @0x1fab24 vdiv.f32 s17, s17, s15
 *   @0x1fab28 vdiv.f32 s16, s16, s14
 *   @0x1fab2c bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1fab30 ldr r2, [sp, #0x4]
 *   @0x1fab34 vmov d6, r0, r1
 *   @0x1fab38 vcvt.f32.f64 s14, d6
 *   @0x1fab3c vdiv.f32 s14, s17, s14
 *   @0x1fab40 b 0x1faaac <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x78>
 *   @0x1fab44 vmov r0, s14
 *   @0x1fab48 str r2, [sp, #0x4]
 *   @0x1fab4c bl 0xb6700 <sqrtf@plt>
 *   @0x1fab50 ldr r2, [sp, #0x4]
 *   @0x1fab54 vmov s15, r0
 *   @0x1fab58 b 0x1faac4 <_Z15GV_PhysicsSpeedP9CInstanceiP6RValue+0x90>
 *   @0x1fab5c andseq r2, pc, r8, ror #29
 *   @0x1fab60 ldrheq r2, [pc], -r0
 *   @0x1fab64 andseq r2, pc, r4, lsr lr
 *
 * ══ §92/94 _spPathConstraintMixTimeline_apply  0x2828dc  size 308  77 条（0x2828dc..0x282a10）
 * @func 0x2828dc 0x282a10  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spPathConstraintMixTimeline_apply+0x80 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x34×1 / 0x14×1 / 0x2×1
 * VFP 指令 47 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2828dc push {r3, r4, r5, r6, r7, lr}
 *   @0x2828e0 vpush {d8, d9}
 *   @0x2828e4 vmov s16, r3
 *   @0x2828e8 vldr s17, [sp, #48]
 *   @0x2828ec ldr r5, [r0, #0x10]
 *   @0x2828f0 vldr s15, [r5]
 *   @0x2828f4 vcmpe.f32 s15, s16
 *   @0x2828f8 mov r4, r0
 *   @0x2828fc vmrs APSR_nzcv, fpscr
 *   @0x282900 bgt 0x282954 <_spPathConstraintMixTimeline_apply+0x78>
 *   @0x282904 ldr r2, [r0, #0xc]
 *   @0x282908 ldr r1, [r1, #0x34]
 *   @0x28290c sub r3, r2, #3
 *   @0x282910 ldr r0, [r0, #0x14]
 *   @0x282914 add r3, r5, r3, lsl #2
 *   @0x282918 vldr s15, [r3]
 *   @0x28291c vcmpe.f32 s16, s15
 *   @0x282920 ldr r6, [r1, r0, lsl #2]
 *   @0x282924 vmrs APSR_nzcv, fpscr
 *   @0x282928 blt 0x28295c <_spPathConstraintMixTimeline_apply+0x80>
 *   @0x28292c vldr s14, [r6, #24]
 *   @0x282930 vldr s13, [r3, #4]
 *   @0x282934 vsub.f32 s13, s13, s14
 *   @0x282938 vldr s15, [r6, #28]
 *   @0x28293c vmla.f32 s14, s13, s17
 *   @0x282940 vstr s14, [r6, #24]
 *   @0x282944 vldr s14, [r3, #8]
 *   @0x282948 vsub.f32 s14, s14, s15
 *   @0x28294c vmla.f32 s15, s14, s17
 *   @0x282950 vstr s15, [r6, #28]
 *   @0x282954 vpop {d8, d9}
 *   @0x282958 pop {r3, r4, r5, r6, r7, pc}
 *   @0x28295c mov r1, r2
 *   @0x282960 vmov.f32 s0, s16
 *   @0x282964 mov r0, r5
 *   @0x282968 mov r2, #3
 *   @0x28296c bl 0x280ed0 <printbuf_free+0x20>
 *   @0x282970 movw r2, #0x5556
 *   @0x282974 movt r2, #0x5555
 *   @0x282978 vmov.f32 s14, #1.000000e+00
 *   @0x28297c sub r7, r0, #2
 *   @0x282980 mov r3, r0
 *   @0x282984 smull r1, r2, r2, r3
 *   @0x282988 lsl r7, r7, #2
 *   @0x28298c add r5, r5, r7
 *   @0x282990 vldr s15, [r5, #8]
 *   @0x282994 vldr s13, [r5, #-4]
 *   @0x282998 vsub.f32 s16, s16, s15
 *   @0x28299c mov r0, r4
 *   @0x2829a0 vldr s19, [r5]
 *   @0x2829a4 vldr s18, [r5, #4]
 *   @0x2829a8 sub r1, r2, r3, asr #31
 *   @0x2829ac sub r1, r1, #1
 *   @0x2829b0 vsub.f32 s15, s13, s15
 *   @0x2829b4 vdiv.f32 s15, s16, s15
 *   @0x2829b8 vsub.f32 s14, s14, s15
 *   @0x2829bc vmov r2, s14
 *   @0x2829c0 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x2829c4 ldr r3, [r4, #0x10]
 *   @0x2829c8 vldr s13, [r6, #24]
 *   @0x2829cc vldr s15, [r6, #28]
 *   @0x2829d0 add r7, r3, r7
 *   @0x2829d4 vldr s12, [r7, #12]
 *   @0x2829d8 vsub.f32 s12, s12, s19
 *   @0x2829dc vmov s14, r0
 *   @0x2829e0 vmla.f32 s19, s12, s14
 *   @0x2829e4 vsub.f32 s19, s19, s13
 *   @0x2829e8 vmla.f32 s13, s19, s17
 *   @0x2829ec vstr s13, [r6, #24]
 *   @0x2829f0 vldr s13, [r7, #16]
 *   @0x2829f4 vsub.f32 s13, s13, s18
 *   @0x2829f8 vmla.f32 s18, s13, s14
 *   @0x2829fc vsub.f32 s18, s18, s15
 *   @0x282a00 vmla.f32 s15, s18, s17
 *   @0x282a04 vpop {d8, d9}
 *   @0x282a08 vstr s15, [r6, #28]
 *   @0x282a0c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §93/94 spIkConstraint_apply1  0x285e48  size 308  77 条（0x285e48..0x285f7c）
 * @func 0x285e48 0x285f7c  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70 / spBone_updateWorldTransformWith
 * 字段偏移 top8: 0x8×1 / 0x24×1 / 0x14×1 / 0x18×1 / 0x4×1 / 0x2c×1 / 0xc×1
 * VFP 指令 56 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285e48 push {r4, lr}
 *   @0x285e4c vpush {d8}
 *   @0x285e50 mov r4, r0
 *   @0x285e54 vldr s15, [r4, #24]
 *   @0x285e58 ldr r0, [r0, #0x8]
 *   @0x285e5c vldr s12, [r0, #56]
 *   @0x285e60 vldr s13, [r0, #64]
 *   @0x285e64 vmul.f32 s11, s12, s13
 *   @0x285e68 vldr s9, [r0, #52]
 *   @0x285e6c vldr s7, [r0, #68]
 *   @0x285e70 vmov s5, r2
 *   @0x285e74 vldr s10, [r0, #72]
 *   @0x285e78 vldr s8, [r0, #60]
 *   @0x285e7c vldr s14, [r4, #20]
 *   @0x285e80 sub sp, sp, #16
 *   @0x285e84 vmov s16, r3
 *   @0x285e88 vnmls.f32 s11, s9, s7
 *   @0x285e8c vmov.f32 s6, #1.000000e+00
 *   @0x285e90 vsub.f32 s10, s5, s10
 *   @0x285e94 vmov s5, r1
 *   @0x285e98 vsub.f32 s8, s5, s8
 *   @0x285e9c vdiv.f32 s11, s6, s11
 *   @0x285ea0 vmul.f32 s12, s12, s10
 *   @0x285ea4 vmul.f32 s13, s13, s8
 *   @0x285ea8 vnmls.f32 s12, s7, s8
 *   @0x285eac vnmls.f32 s13, s9, s10
 *   @0x285eb0 vnmls.f32 s14, s12, s11
 *   @0x285eb4 vnmls.f32 s15, s13, s11
 *   @0x285eb8 vcvt.f64.f32 d4, s14
 *   @0x285ebc vcvt.f64.f32 d6, s15
 *   @0x285ec0 vmov r2, r3, d4
 *   @0x285ec4 vmov r0, r1, d6
 *   @0x285ec8 bl 0xb6c70 <atan2@plt>
 *   @0x285ecc vldr s13, [r4, #40]
 *   @0x285ed0 vldr s15, [pc, #148]
 *   @0x285ed4 vldr s14, [r4, #28]
 *   @0x285ed8 vldr s12, [r4, #32]
 *   @0x285edc vcmpe.f32 s12, #0
 *   @0x285ee0 vmrs APSR_nzcv, fpscr
 *   @0x285ee4 vmov d4, r0, r1
 *   @0x285ee8 vcvt.f32.f64 s11, d4
 *   @0x285eec vmov.f32 s9, s13
 *   @0x285ef0 vnmls.f32 s9, s11, s15
 *   @0x285ef4 vldrmi s11, [pc, #116]
 *   @0x285ef8 vsub.f32 s15, s9, s14
 *   @0x285efc vaddmi.f32 s15, s15, s11
 *   @0x285f00 vldr s11, [pc, #104]
 *   @0x285f04 vcmpe.f32 s15, s11
 *   @0x285f08 vmrs APSR_nzcv, fpscr
 *   @0x285f0c bgt 0x285f60 <spIkConstraint_apply1+0x118>
 *   @0x285f10 vldr s11, [pc, #92]
 *   @0x285f14 vcmpe.f32 s15, s11
 *   @0x285f18 vmrs APSR_nzcv, fpscr
 *   @0x285f1c vldrmi s11, [pc, #84]
 *   @0x285f20 vaddmi.f32 s15, s15, s11
 *   @0x285f24 vstr s12, [sp]
 *   @0x285f28 vstr s13, [sp, #8]
 *   @0x285f2c ldr r3, [r4, #0x24]
 *   @0x285f30 mov r0, r4
 *   @0x285f34 ldr r1, [r4, #0x14]
 *   @0x285f38 ldr r2, [r4, #0x18]
 *   @0x285f3c str r3, [sp, #0x4]
 *   @0x285f40 ldr r3, [r4, #0x2c]
 *   @0x285f44 vmla.f32 s14, s15, s16
 *   @0x285f48 str r3, [sp, #0xc]
 *   @0x285f4c vmov r3, s14
 *   @0x285f50 bl 0x284f18 <spBone_updateWorldTransformWith>
 *   @0x285f54 add sp, sp, #16
 *   @0x285f58 vpop {d8}
 *   @0x285f5c pop {r4, pc}
 *   @0x285f60 vldr s11, [pc, #16]
 *   @0x285f64 vsub.f32 s15, s15, s11
 *   @0x285f68 b 0x285f24 <spIkConstraint_apply1+0xdc>
 *   @0x285f6c rsbmi r2, r5, #224, #28
 *   @0x285f70 teqmi r4, #0
 *   @0x285f74 teqgt r4, #0
 *   @0x285f78 .word 0x43b40000
 *
 * ══ §94/94 IBuffer::Read(void const*, unsigned int, unsigned int)  0xcdc9c  size 284  71 条（0xcdc9c..0xcddb8）
 * @func 0xcdc9c 0xcddb8  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Read(void const*, unsigned int, unsigned int)+0x6c×2 / 0xb65bc×2 / IBuffer::Read(void const*, unsigned int, unsigned int)+0x108 / IBuffer::Read(void const*, unsigned int, unsigned int)+0x4c / __aeabi_idivmod
 * 字段偏移 top8: 0x1c×3 / 0x10×3 / 0xc×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcdc9c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcdca0 subs r9, r1, #0
 *   @0xcdca4 mov r8, r0
 *   @0xcdca8 beq 0xcddb0 <_ZN7IBuffer4ReadEPKvjj+0x114>
 *   @0xcdcac mul r5, r3, r2
 *   @0xcdcb0 cmp r5, #0
 *   @0xcdcb4 mov r10, r5
 *   @0xcdcb8 ble 0xcdd08 <_ZN7IBuffer4ReadEPKvjj+0x6c>
 *   @0xcdcbc ldr r2, [r0, #0x18]
 *   @0xcdcc0 ldr r3, [r0, #0x1c]
 *   @0xcdcc4 cmp r2, #2
 *   @0xcdcc8 beq 0xcdd10 <_ZN7IBuffer4ReadEPKvjj+0x74>
 *   @0xcdccc ldr r2, [r0, #0x10]
 *   @0xcdcd0 bic r3, r3, r3, asr #31
 *   @0xcdcd4 cmp r2, r3
 *   @0xcdcd8 ble 0xcdd08 <_ZN7IBuffer4ReadEPKvjj+0x6c>
 *   @0xcdcdc add r7, r5, r3
 *   @0xcdce0 cmp r2, r7
 *   @0xcdce4 blt 0xcdda4 <_ZN7IBuffer4ReadEPKvjj+0x108>
 *   @0xcdce8 ldr r1, [r8, #0xc]
 *   @0xcdcec mov r0, r9
 *   @0xcdcf0 mov r2, r5
 *   @0xcdcf4 add r1, r1, r3
 *   @0xcdcf8 bl 0xb65bc <memcpy@plt>
 *   @0xcdcfc mov r0, r5
 *   @0xcdd00 str r7, [r8, #0x1c]
 *   @0xcdd04 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcdd08 mov r0, #0
 *   @0xcdd0c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcdd10 cmp r3, #0
 *   @0xcdd14 ldr r4, [r0, #0x10]
 *   @0xcdd18 bge 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98>
 *   @0xcdd1c adds r3, r3, r4
 *   @0xcdd20 bpl 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98>
 *   @0xcdd24 adds r3, r3, r4
 *   @0xcdd28 bmi 0xcdd1c <_ZN7IBuffer4ReadEPKvjj+0x80>
 *   @0xcdd2c b 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98>
 *   @0xcdd30 rsb r3, r4, r3
 *   @0xcdd34 cmp r3, r4
 *   @0xcdd38 bge 0xcdd30 <_ZN7IBuffer4ReadEPKvjj+0x94>
 *   @0xcdd3c add r7, r3, r5
 *   @0xcdd40 cmp r7, r4
 *   @0xcdd44 ble 0xcdce8 <_ZN7IBuffer4ReadEPKvjj+0x4c>
 *   @0xcdd48 mov r7, r3
 *   @0xcdd4c mov r11, #0
 *   @0xcdd50 rsb r4, r7, r4
 *   @0xcdd54 ldr r1, [r8, #0xc]
 *   @0xcdd58 cmp r4, r5
 *   @0xcdd5c movlt r6, r4
 *   @0xcdd60 movge r6, r5
 *   @0xcdd64 add r0, r9, r11
 *   @0xcdd68 add r1, r1, r7
 *   @0xcdd6c rsb r5, r6, r5
 *   @0xcdd70 mov r2, r6
 *   @0xcdd74 add r11, r11, r6
 *   @0xcdd78 bl 0xb65bc <memcpy@plt>
 *   @0xcdd7c ldr r4, [r8, #0x10]
 *   @0xcdd80 add r0, r7, r6
 *   @0xcdd84 mov r1, r4
 *   @0xcdd88 bl 0x318dec <__aeabi_idivmod>
 *   @0xcdd8c cmp r5, #0
 *   @0xcdd90 mov r7, r1
 *   @0xcdd94 bgt 0xcdd50 <_ZN7IBuffer4ReadEPKvjj+0xb4>
 *   @0xcdd98 mov r0, r10
 *   @0xcdd9c str r7, [r8, #0x1c]
 *   @0xcdda0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcdda4 rsb r5, r3, r2
 *   @0xcdda8 mov r7, r2
 *   @0xcddac b 0xcdce8 <_ZN7IBuffer4ReadEPKvjj+0x4c>
 *   @0xcddb0 mov r0, r9
 *   @0xcddb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 */
