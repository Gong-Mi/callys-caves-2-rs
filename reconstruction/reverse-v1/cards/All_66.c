/* cally 逆向卡：All_66 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 561 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/561 F_SurfaceGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c97c  size 60  15 条（0x11c97c..0x11c9b8）
 * @func 0x11c97c 0x11c9b8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Surface_Get_Height(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c97c push {r4, lr}
 *   @0x11c980 mov r3, #0
 *   @0x11c984 mov r1, r3
 *   @0x11c988 str r3, [r0, #0xc]
 *   @0x11c98c mov r4, r0
 *   @0x11c990 ldr r0, [sp, #0x8]
 *   @0x11c994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c998 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0x11c99c vmov s15, r0
 *   @0x11c9a0 vcvt.f64.s32 d7, s15
 *   @0x11c9a4 vmov r0, r1, d7
 *   @0x11c9a8 vmov r2, s14
 *   @0x11c9ac mov r3, r1
 *   @0x11c9b0 stm r4, {r2, r3}
 *   @0x11c9b4 pop {r4, pc}
 *
 * ══ §2/561 F_SkeletonGetSkin(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d1f4  size 60  15 条（0x11d1f4..0x11d230）
 * @func 0x11d1f4 0x11d230  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SkeletonAnimation() / CSkeletonInstance::GetSkin() const
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d1f4 push {r4, lr}
 *   @0x11d1f8 mov r4, r0
 *   @0x11d1fc mov r3, #1
 *   @0x11d200 mov r0, r1
 *   @0x11d204 str r3, [r4, #0xc]
 *   @0x11d208 mov r3, #0
 *   @0x11d20c str r3, [r4]
 *   @0x11d210 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d214 cmp r0, #0
 *   @0x11d218 popeq {r4, pc}
 *   @0x11d21c bl 0xc0170 <_ZNK17CSkeletonInstance7GetSkinEv>
 *   @0x11d220 mov r1, r0
 *   @0x11d224 mov r0, r4
 *   @0x11d228 pop {r4, lr}
 *   @0x11d22c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §3/561 F_SplashSetCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f70  size 60  15 条（0x125f70..0x125fac）
 * @func 0x125f70 0x125fac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYGetString(RValue const*, int) / YYStrDup(char const*)
 * 字段偏移 top8: 0x2c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f70 push {r3, r4, r5, lr}
 *   @0x125f74 ldr r4, [pc, #0x2c]
 *   @0x125f78 ldr r5, [sp, #0x10]
 *   @0x125f7c ldr r4, [pc, r4]
 *   @0x125f80 ldr r0, [r4]
 *   @0x125f84 cmp r0, #0
 *   @0x125f88 beq 0x125f90 <_Z18F_SplashSetCaptionR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x125f8c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x125f90 mov r1, #0
 *   @0x125f94 mov r0, r5
 *   @0x125f98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x125f9c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x125fa0 str r0, [r4]
 *   @0x125fa4 pop {r3, r4, r5, pc}
 *   @0x125fa8 .word 0x002c8ab4
 *
 * ══ §4/561 F_HighscoreValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x1268f0  size 60  15 条（0x1268f0..0x12692c）
 * @func 0x1268f0 0x12692c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / HighScore_Value(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1268f0 push {r4, lr}
 *   @0x1268f4 mov r3, #0
 *   @0x1268f8 mov r1, r3
 *   @0x1268fc str r3, [r0, #0xc]
 *   @0x126900 mov r4, r0
 *   @0x126904 ldr r0, [sp, #0x8]
 *   @0x126908 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12690c bl 0x1dc310 <_Z15HighScore_Valuei>
 *   @0x126910 vmov s15, r0
 *   @0x126914 vcvt.f64.s32 d7, s15
 *   @0x126918 vmov r0, r1, d7
 *   @0x12691c vmov r2, s14
 *   @0x126920 mov r3, r1
 *   @0x126924 stm r4, {r2, r3}
 *   @0x126928 pop {r4, pc}
 *
 * ══ §5/561 F_KeyboardGetMap(RValue&, CInstance*, CInstance*, int, RValue*)  0x127380  size 60  15 条（0x127380..0x1273bc）
 * @func 0x127380 0x1273bc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / IO_Keymap_Get(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x127380 push {r4, lr}
 *   @0x127384 mov r3, #0
 *   @0x127388 mov r1, r3
 *   @0x12738c str r3, [r0, #0xc]
 *   @0x127390 mov r4, r0
 *   @0x127394 ldr r0, [sp, #0x8]
 *   @0x127398 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12739c bl 0x18c2e0 <_Z13IO_Keymap_Geti>
 *   @0x1273a0 vmov s15, r0
 *   @0x1273a4 vcvt.f64.s32 d7, s15
 *   @0x1273a8 vmov r0, r1, d7
 *   @0x1273ac vmov r2, s14
 *   @0x1273b0 mov r3, r1
 *   @0x1273b4 stm r4, {r2, r3}
 *   @0x1273b8 pop {r4, pc}
 *
 * ══ §6/561 F_PartTypeExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x128f88  size 60  15 条（0x128f88..0x128fc4）
 * @func 0x128f88 0x128fc4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParticleType_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128f88 push {r4, lr}
 *   @0x128f8c mov r3, #0
 *   @0x128f90 mov r1, r3
 *   @0x128f94 str r3, [r0, #0xc]
 *   @0x128f98 mov r4, r0
 *   @0x128f9c ldr r0, [sp, #0x8]
 *   @0x128fa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x128fa4 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x128fa8 vmov s15, r0
 *   @0x128fac vcvt.f64.u32 d7, s15
 *   @0x128fb0 vmov r0, r1, d7
 *   @0x128fb4 vmov r2, s14
 *   @0x128fb8 mov r3, r1
 *   @0x128fbc stm r4, {r2, r3}
 *   @0x128fc0 pop {r4, pc}
 *
 * ══ §7/561 F_PartSystemGetLayer(RValue&, CInstance*, CInstance*, int, RValue*)  0x129828  size 60  15 条（0x129828..0x129864）
 * @func 0x129828 0x129864  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParticleSystem_GetLayer(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129828 push {r4, lr}
 *   @0x12982c mov r3, #0
 *   @0x129830 mov r1, r3
 *   @0x129834 str r3, [r0, #0xc]
 *   @0x129838 mov r4, r0
 *   @0x12983c ldr r0, [sp, #0x8]
 *   @0x129840 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129844 bl 0x1a4628 <_Z23ParticleSystem_GetLayeri>
 *   @0x129848 vmov s15, r0
 *   @0x12984c vcvt.f64.s32 d7, s15
 *   @0x129850 vmov r0, r1, d7
 *   @0x129854 vmov r2, s14
 *   @0x129858 mov r3, r1
 *   @0x12985c stm r4, {r2, r3}
 *   @0x129860 pop {r4, pc}
 *
 * ══ §8/561 F_PartSystemExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x129910  size 60  15 条（0x129910..0x12994c）
 * @func 0x129910 0x12994c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParticleSystem_Exists(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129910 push {r4, lr}
 *   @0x129914 mov r3, #0
 *   @0x129918 mov r1, r3
 *   @0x12991c str r3, [r0, #0xc]
 *   @0x129920 mov r4, r0
 *   @0x129924 ldr r0, [sp, #0x8]
 *   @0x129928 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12992c bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x129930 vmov s15, r0
 *   @0x129934 vcvt.f64.u32 d7, s15
 *   @0x129938 vmov r0, r1, d7
 *   @0x12993c vmov r2, s14
 *   @0x129940 mov r3, r1
 *   @0x129944 stm r4, {r2, r3}
 *   @0x129948 pop {r4, pc}
 *
 * ══ §9/561 F_PartParticlesCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x129bc0  size 60  15 条（0x129bc0..0x129bfc）
 * @func 0x129bc0 0x129bfc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParticleSystem_Particles_Count(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129bc0 push {r4, lr}
 *   @0x129bc4 mov r3, #0
 *   @0x129bc8 mov r1, r3
 *   @0x129bcc str r3, [r0, #0xc]
 *   @0x129bd0 mov r4, r0
 *   @0x129bd4 ldr r0, [sp, #0x8]
 *   @0x129bd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129bdc bl 0x1a4150 <_Z30ParticleSystem_Particles_Counti>
 *   @0x129be0 vmov s15, r0
 *   @0x129be4 vcvt.f64.s32 d7, s15
 *   @0x129be8 vmov r0, r1, d7
 *   @0x129bec vmov r2, s14
 *   @0x129bf0 mov r3, r1
 *   @0x129bf4 stm r4, {r2, r3}
 *   @0x129bf8 pop {r4, pc}
 *
 * ══ §10/561 F_PartEmitterCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x129bfc  size 60  15 条（0x129bfc..0x129c38）
 * @func 0x129bfc 0x129c38  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / ParticleSystem_Emitter_Create(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129bfc push {r4, lr}
 *   @0x129c00 mov r3, #0
 *   @0x129c04 mov r1, r3
 *   @0x129c08 str r3, [r0, #0xc]
 *   @0x129c0c mov r4, r0
 *   @0x129c10 ldr r0, [sp, #0x8]
 *   @0x129c14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129c18 bl 0x1a39b4 <_Z29ParticleSystem_Emitter_Createi>
 *   @0x129c1c vmov s15, r0
 *   @0x129c20 vcvt.f64.s32 d7, s15
 *   @0x129c24 vmov r0, r1, d7
 *   @0x129c28 vmov r2, s14
 *   @0x129c2c mov r3, r1
 *   @0x129c30 stm r4, {r2, r3}
 *   @0x129c34 pop {r4, pc}
 *
 * ══ §11/561 F_PathSetKind(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d8f4  size 60  15 条（0x12d8f4..0x12d930）
 * @func 0x12d8f4 0x12d930  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d8f4 push {r3, r4, r5, lr}
 *   @0x12d8f8 mov r1, #0
 *   @0x12d8fc ldr r4, [sp, #0x10]
 *   @0x12d900 mov r0, r4
 *   @0x12d904 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d908 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d90c subs r5, r0, #0
 *   @0x12d910 popeq {r3, r4, r5, pc}
 *   @0x12d914 mov r0, r4
 *   @0x12d918 mov r1, #1
 *   @0x12d91c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d920 mov r1, r0
 *   @0x12d924 mov r0, r5
 *   @0x12d928 pop {r3, r4, r5, lr}
 *   @0x12d92c b 0x1a6e64 <_ZN5CPath7SetKindEi>
 *
 * ══ §12/561 F_PathSetClosed(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d930  size 60  15 条（0x12d930..0x12d96c）
 * @func 0x12d930 0x12d96c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d930 push {r3, r4, r5, lr}
 *   @0x12d934 mov r1, #0
 *   @0x12d938 ldr r4, [sp, #0x10]
 *   @0x12d93c mov r0, r4
 *   @0x12d940 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d944 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d948 subs r5, r0, #0
 *   @0x12d94c popeq {r3, r4, r5, pc}
 *   @0x12d950 mov r0, r4
 *   @0x12d954 mov r1, #1
 *   @0x12d958 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12d95c mov r1, r0
 *   @0x12d960 mov r0, r5
 *   @0x12d964 pop {r3, r4, r5, lr}
 *   @0x12d968 b 0x1a6e78 <_ZN5CPath9SetClosedEb>
 *
 * ══ §13/561 F_PathSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d96c  size 60  15 条（0x12d96c..0x12d9a8）
 * @func 0x12d96c 0x12d9a8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d96c push {r3, r4, r5, lr}
 *   @0x12d970 mov r1, #0
 *   @0x12d974 ldr r4, [sp, #0x10]
 *   @0x12d978 mov r0, r4
 *   @0x12d97c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d980 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12d984 subs r5, r0, #0
 *   @0x12d988 popeq {r3, r4, r5, pc}
 *   @0x12d98c mov r0, r4
 *   @0x12d990 mov r1, #1
 *   @0x12d994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d998 mov r1, r0
 *   @0x12d99c mov r0, r5
 *   @0x12d9a0 pop {r3, r4, r5, lr}
 *   @0x12d9a4 b 0x1a6e80 <_ZN5CPath12SetPrecisionEi>
 *
 * ══ §14/561 F_PathDeletePoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dc04  size 60  15 条（0x12dc04..0x12dc40）
 * @func 0x12dc04 0x12dc40  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Path_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dc04 push {r3, r4, r5, lr}
 *   @0x12dc08 mov r1, #0
 *   @0x12dc0c ldr r4, [sp, #0x10]
 *   @0x12dc10 mov r0, r4
 *   @0x12dc14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dc18 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dc1c subs r5, r0, #0
 *   @0x12dc20 popeq {r3, r4, r5, pc}
 *   @0x12dc24 mov r0, r4
 *   @0x12dc28 mov r1, #1
 *   @0x12dc2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dc30 mov r1, r0
 *   @0x12dc34 mov r0, r5
 *   @0x12dc38 pop {r3, r4, r5, lr}
 *   @0x12dc3c b 0x1a733c <_ZN5CPath11DeletePointEi>
 *
 * ══ §15/561 F_PathRotate(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dcd0  size 60  15 条（0x12dcd0..0x12dd0c）
 * @func 0x12dcd0 0x12dd0c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dcd0 push {r3, r4, r5, lr}
 *   @0x12dcd4 mov r1, #0
 *   @0x12dcd8 ldr r4, [sp, #0x10]
 *   @0x12dcdc mov r0, r4
 *   @0x12dce0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dce4 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dce8 subs r5, r0, #0
 *   @0x12dcec popeq {r3, r4, r5, pc}
 *   @0x12dcf0 mov r0, r4
 *   @0x12dcf4 mov r1, #1
 *   @0x12dcf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dcfc mov r1, r0
 *   @0x12dd00 mov r0, r5
 *   @0x12dd04 pop {r3, r4, r5, lr}
 *   @0x12dd08 b 0x1a787c <_ZN5CPath6RotateEf>
 *
 * ══ §16/561 F_ScriptExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ddac  size 60  15 条（0x12ddac..0x12dde8）
 * @func 0x12ddac 0x12dde8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Script_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ddac push {r3, r4, r5, lr}
 *   @0x12ddb0 mov r1, #0
 *   @0x12ddb4 mov r4, r0
 *   @0x12ddb8 ldr r0, [sp, #0x10]
 *   @0x12ddbc mov r5, r1
 *   @0x12ddc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ddc4 str r5, [r4, #0xc]
 *   @0x12ddc8 bl 0x1e0544 <_Z13Script_Existsi>
 *   @0x12ddcc cmp r0, #0
 *   @0x12ddd0 movne r0, r5
 *   @0x12ddd4 moveq r3, r0
 *   @0x12ddd8 movne r3, r0
 *   @0x12dddc movtne r3, #0x3ff0
 *   @0x12dde0 stm r4, {r0, r3}
 *   @0x12dde4 pop {r3, r4, r5, pc}
 *
 * ══ §17/561 F_TimeLineMomentClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12df50  size 60  15 条（0x12df50..0x12df8c）
 * @func 0x12df50 0x12df8c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / TimeLine_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12df50 push {r3, r4, r5, lr}
 *   @0x12df54 mov r1, #0
 *   @0x12df58 ldr r4, [sp, #0x10]
 *   @0x12df5c mov r0, r4
 *   @0x12df60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12df64 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x12df68 subs r5, r0, #0
 *   @0x12df6c popeq {r3, r4, r5, pc}
 *   @0x12df70 mov r0, r4
 *   @0x12df74 mov r1, #1
 *   @0x12df78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12df7c mov r1, r0
 *   @0x12df80 mov r0, r5
 *   @0x12df84 pop {r3, r4, r5, lr}
 *   @0x12df88 b 0x1f2250 <_ZN9CTimeLine12DeleteMomentEi>
 *
 * ══ §18/561 F_Audio_StopRecording(RValue&, CInstance*, CInstance*, int, RValue*)  0x13367c  size 60  15 条（0x13367c..0x1336b8）
 * @func 0x13367c 0x1336b8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_StopRecording(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13367c push {r4, lr}
 *   @0x133680 mov r3, #0
 *   @0x133684 mov r1, r3
 *   @0x133688 str r3, [r0, #0xc]
 *   @0x13368c mov r4, r0
 *   @0x133690 ldr r0, [sp, #0x8]
 *   @0x133694 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133698 bl 0x21caf8 <_Z19Audio_StopRecordingi>
 *   @0x13369c vmov s15, r0
 *   @0x1336a0 vcvt.f64.s32 d7, s15
 *   @0x1336a4 vmov r0, r1, d7
 *   @0x1336a8 vmov r2, s14
 *   @0x1336ac mov r3, r1
 *   @0x1336b0 stm r4, {r2, r3}
 *   @0x1336b4 pop {r4, pc}
 *
 * ══ §19/561 F_CDTrackLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x1337dc  size 60  15 条（0x1337dc..0x133818）
 * @func 0x1337dc 0x133818  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CD_TrackLength(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1337dc push {r4, lr}
 *   @0x1337e0 mov r3, #0
 *   @0x1337e4 mov r1, r3
 *   @0x1337e8 str r3, [r0, #0xc]
 *   @0x1337ec mov r4, r0
 *   @0x1337f0 ldr r0, [sp, #0x8]
 *   @0x1337f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1337f8 bl 0x21488c <_Z14CD_TrackLengthi>
 *   @0x1337fc vmov s15, r0
 *   @0x133800 vcvt.f64.s32 d7, s15
 *   @0x133804 vmov r0, r1, d7
 *   @0x133808 vmov r2, s14
 *   @0x13380c mov r3, r1
 *   @0x133810 stm r4, {r2, r3}
 *   @0x133814 pop {r4, pc}
 *
 * ══ §20/561 F_AudioSetMasterGain(RValue&, CInstance*, CInstance*, int, RValue*)  0x134fe8  size 60  15 条（0x134fe8..0x135024）
 * @func 0x134fe8 0x135024  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134fe8 ldr r3, [pc, #0x30]
 *   @0x134fec push {r4, lr}
 *   @0x134ff0 ldr r3, [pc, r3]
 *   @0x134ff4 ldr r0, [sp, #0x8]
 *   @0x134ff8 ldrb r4, [r3]
 *   @0x134ffc cmp r4, #0
 *   @0x135000 popne {r4, pc}
 *   @0x135004 mov r1, r4
 *   @0x135008 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13500c mov r2, r0
 *   @0x135010 mov r3, r1
 *   @0x135014 mov r0, r4
 *   @0x135018 pop {r4, lr}
 *   @0x13501c b 0x218118 <_Z19Audio_SetMasterGainid>
 *   @0x135020 eoreq r10, r11, r12, asr r0
 *
 * ══ §21/561 F_AudioGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x135698  size 60  15 条（0x135698..0x1356d4）
 * @func 0x135698 0x1356d4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Audio_GetName(int)
 * 字段偏移 top8: 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135698 ldr r3, [pc, #0x30]
 *   @0x13569c push {r4, lr}
 *   @0x1356a0 ldr r3, [pc, r3]
 *   @0x1356a4 mov r4, r0
 *   @0x1356a8 ldr r0, [sp, #0x8]
 *   @0x1356ac ldrb r1, [r3]
 *   @0x1356b0 cmp r1, #0
 *   @0x1356b4 popne {r4, pc}
 *   @0x1356b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1356bc bl 0x218348 <_Z13Audio_GetNamei>
 *   @0x1356c0 mov r1, r0
 *   @0x1356c4 mov r0, r4
 *   @0x1356c8 pop {r4, lr}
 *   @0x1356cc b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1356d0 eoreq r9, r11, r12, lsr #19
 *
 * ══ §22/561 F_ActionSetFriction(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d750  size 60  15 条（0x13d750..0x13d78c）
 * @func 0x13d750 0x13d78c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d750 push {r4, lr}
 *   @0x13d754 mov r4, r1
 *   @0x13d758 ldr r0, [sp, #0x8]
 *   @0x13d75c mov r1, #0
 *   @0x13d760 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d764 ldr r3, [pc, #0x1c]
 *   @0x13d768 ldr r3, [pc, r3]
 *   @0x13d76c ldrb r3, [r3]
 *   @0x13d770 cmp r3, #0
 *   @0x13d774 vldrne s14, [r4, #212]
 *   @0x13d778 vmov s15, r0
 *   @0x13d77c vaddne.f32 s15, s14, s15
 *   @0x13d780 vstr s15, [r4, #212]
 *   @0x13d784 pop {r4, pc}
 *   @0x13d788 .word 0x002b03d4
 *
 * ══ §23/561 F_ActionSetTimelinePosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d78c  size 60  15 条（0x13d78c..0x13d7c8）
 * @func 0x13d78c 0x13d7c8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d78c push {r4, lr}
 *   @0x13d790 mov r4, r1
 *   @0x13d794 ldr r0, [sp, #0x8]
 *   @0x13d798 mov r1, #0
 *   @0x13d79c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d7a0 ldr r3, [pc, #0x1c]
 *   @0x13d7a4 ldr r3, [pc, r3]
 *   @0x13d7a8 ldrb r3, [r3]
 *   @0x13d7ac cmp r3, #0
 *   @0x13d7b0 vldrne s14, [r4, #340]
 *   @0x13d7b4 vmov s15, r0
 *   @0x13d7b8 vaddne.f32 s15, s14, s15
 *   @0x13d7bc vstr s15, [r4, #340]
 *   @0x13d7c0 pop {r4, pc}
 *   @0x13d7c4 mlaeq r11, r8, r3, r0
 *
 * ══ §24/561 F_ActionSetTimelineSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d7c8  size 60  15 条（0x13d7c8..0x13d804）
 * @func 0x13d7c8 0x13d804  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d7c8 push {r4, lr}
 *   @0x13d7cc mov r4, r1
 *   @0x13d7d0 ldr r0, [sp, #0x8]
 *   @0x13d7d4 mov r1, #0
 *   @0x13d7d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d7dc ldr r3, [pc, #0x1c]
 *   @0x13d7e0 ldr r3, [pc, r3]
 *   @0x13d7e4 ldrb r3, [r3]
 *   @0x13d7e8 cmp r3, #0
 *   @0x13d7ec vldrne s14, [r4, #344]
 *   @0x13d7f0 vmov s15, r0
 *   @0x13d7f4 vaddne.f32 s15, s14, s15
 *   @0x13d7f8 vstr s15, [r4, #344]
 *   @0x13d7fc pop {r4, pc}
 *   @0x13d800 eoreq r0, r11, r12, asr r3
 *
 * ══ §25/561 F_ActionSetTimeline(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d804  size 60  15 条（0x13d804..0x13d840）
 * @func 0x13d804 0x13d840  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x14c×1 / 0x15c×1 / 0x154×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d804 push {r4, r5, r6, lr}
 *   @0x13d808 mov r4, r1
 *   @0x13d80c ldr r5, [sp, #0x10]
 *   @0x13d810 mov r1, #0
 *   @0x13d814 mov r0, r5
 *   @0x13d818 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d81c mov r1, #1
 *   @0x13d820 mov r6, r0
 *   @0x13d824 mov r0, r5
 *   @0x13d828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d82c mov r3, #1
 *   @0x13d830 str r6, [r4, #0x14c]
 *   @0x13d834 strb r3, [r4, #0x15c]
 *   @0x13d838 str r0, [r4, #0x154]
 *   @0x13d83c pop {r4, r5, r6, pc}
 *
 * ══ §26/561 F_ActionSnap(RValue&, CInstance*, CInstance*, int, RValue*)  0x13df24  size 60  15 条（0x13df24..0x13df60）
 * @func 0x13df24 0x13df60  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13df24 push {r4, r5, r6, lr}
 *   @0x13df28 mov r6, r1
 *   @0x13df2c ldr r4, [sp, #0x10]
 *   @0x13df30 mov r1, #0
 *   @0x13df34 mov r0, r4
 *   @0x13df38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13df3c mov r1, #1
 *   @0x13df40 mov r5, r0
 *   @0x13df44 mov r0, r4
 *   @0x13df48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13df4c mov r1, r5
 *   @0x13df50 mov r2, r0
 *   @0x13df54 mov r0, r6
 *   @0x13df58 pop {r4, r5, r6, lr}
 *   @0x13df5c b 0x1c9594 <_Z12Command_SnapP9CInstanceff>
 *
 * ══ §27/561 F_ActionWrap(RValue&, CInstance*, CInstance*, int, RValue*)  0x13df60  size 60  15 条（0x13df60..0x13df9c）
 * @func 0x13df60 0x13df9c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13df60 push {r4, lr}
 *   @0x13df64 mov r4, r1
 *   @0x13df68 ldr r0, [sp, #0x8]
 *   @0x13df6c mov r1, #0
 *   @0x13df70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13df74 bics r3, r0, #2
 *   @0x13df78 sub r2, r0, #1
 *   @0x13df7c mov r0, r4
 *   @0x13df80 movne r1, #0
 *   @0x13df84 moveq r1, #1
 *   @0x13df88 cmp r2, #1
 *   @0x13df8c pop {r4, lr}
 *   @0x13df90 movhi r2, #0
 *   @0x13df94 movls r2, #1
 *   @0x13df98 b 0x1c961c <_Z12Command_WrapP9CInstancebb>
 *
 * ══ §28/561 F_ActionChangeObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e4d4  size 60  15 条（0x13e4d4..0x13e510）
 * @func 0x13e4d4 0x13e510  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e4d4 push {r4, r5, r6, lr}
 *   @0x13e4d8 mov r6, r1
 *   @0x13e4dc ldr r4, [sp, #0x10]
 *   @0x13e4e0 mov r1, #0
 *   @0x13e4e4 mov r0, r4
 *   @0x13e4e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e4ec mov r1, #1
 *   @0x13e4f0 mov r5, r0
 *   @0x13e4f4 mov r0, r4
 *   @0x13e4f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13e4fc mov r1, r5
 *   @0x13e500 mov r2, r0
 *   @0x13e504 mov r0, r6
 *   @0x13e508 pop {r4, r5, r6, lr}
 *   @0x13e50c b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib>
 *
 * ══ §29/561 F_ActionIfPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e6f4  size 60  15 条（0x13e6f4..0x13e730）
 * @func 0x13e6f4 0x13e730  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_First()
 * 字段偏移 top8: 0xc×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e6f4 push {r3, r4, r5, lr}
 *   @0x13e6f8 mov r5, #0
 *   @0x13e6fc str r5, [r0, #0xc]
 *   @0x13e700 mov r4, r0
 *   @0x13e704 bl 0x1b5d08 <_Z10Room_Firstv>
 *   @0x13e708 ldr r3, [pc, #0x1c]
 *   @0x13e70c ldr r3, [pc, r3]
 *   @0x13e710 ldr r3, [r3]
 *   @0x13e714 str r5, [r4]
 *   @0x13e718 cmp r0, r3
 *   @0x13e71c mov r3, r5
 *   @0x13e720 movtne r3, #0x3ff0
 *   @0x13e724 str r3, [r4, #0x4]
 *   @0x13e728 pop {r3, r4, r5, pc}
 *   @0x13e72c eoreq r0, r11, r8, asr #25
 *
 * ══ §30/561 F_ActionIfNextRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e730  size 60  15 条（0x13e730..0x13e76c）
 * @func 0x13e730 0x13e76c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Last()
 * 字段偏移 top8: 0xc×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e730 push {r3, r4, r5, lr}
 *   @0x13e734 mov r5, #0
 *   @0x13e738 str r5, [r0, #0xc]
 *   @0x13e73c mov r4, r0
 *   @0x13e740 bl 0x1b5d20 <_Z9Room_Lastv>
 *   @0x13e744 ldr r3, [pc, #0x1c]
 *   @0x13e748 ldr r3, [pc, r3]
 *   @0x13e74c ldr r3, [r3]
 *   @0x13e750 str r5, [r4]
 *   @0x13e754 cmp r0, r3
 *   @0x13e758 mov r3, r5
 *   @0x13e75c movtne r3, #0x3ff0
 *   @0x13e760 str r3, [r4, #0x4]
 *   @0x13e764 pop {r3, r4, r5, pc}
 *   @0x13e768 eoreq r0, r11, r12, lsl #25
 *
 * ══ §31/561 F_ActionMove(RValue&, CInstance*, CInstance*, int, RValue*)  0x141538  size 60  15 条（0x141538..0x141574）
 * @func 0x141538 0x141574  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141538 push {r4, r5, r6, lr}
 *   @0x14153c mov r6, r1
 *   @0x141540 ldr r4, [sp, #0x10]
 *   @0x141544 mov r1, #0
 *   @0x141548 mov r0, r4
 *   @0x14154c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x141550 mov r1, #1
 *   @0x141554 mov r5, r0
 *   @0x141558 mov r0, r4
 *   @0x14155c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x141560 mov r1, r5
 *   @0x141564 mov r2, r0
 *   @0x141568 mov r0, r6
 *   @0x14156c pop {r4, r5, r6, lr}
 *   @0x141570 b 0x141394 <_Z17YYGML_action_moveP9CInstancePKcf>
 *
 * ══ §32/561 F_ActionSetGravity(RValue&, CInstance*, CInstance*, int, RValue*)  0x1415ac  size 60  15 条（0x1415ac..0x1415e8）
 * @func 0x1415ac 0x1415e8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1415ac push {r4, r5, r6, lr}
 *   @0x1415b0 mov r6, r1
 *   @0x1415b4 ldr r4, [sp, #0x10]
 *   @0x1415b8 mov r1, #0
 *   @0x1415bc mov r0, r4
 *   @0x1415c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1415c4 mov r1, #1
 *   @0x1415c8 mov r5, r0
 *   @0x1415cc mov r0, r4
 *   @0x1415d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1415d4 mov r1, r5
 *   @0x1415d8 mov r2, r0
 *   @0x1415dc mov r0, r6
 *   @0x1415e0 pop {r4, r5, r6, lr}
 *   @0x1415e4 b 0x141574 <_Z24YYGML_action_set_gravityP9CInstanceff>
 *
 * ══ §33/561 F_PhysicsFixtureSetKinematic(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bed8  size 60  15 条（0x14bed8..0x14bf14）
 * @func 0x14bed8 0x14bf14  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bed8 push {r3, lr}
 *   @0x14bedc mov r1, #0
 *   @0x14bee0 ldr r0, [sp, #0x8]
 *   @0x14bee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bee8 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14beec cmp r0, #0
 *   @0x14bef0 movne r3, #1
 *   @0x14bef4 strbne r3, [r0, #0x18]
 *   @0x14bef8 popne {r3, pc}
 *   @0x14befc mov r1, r0
 *   @0x14bf00 ldr r0, [pc, #0x8]
 *   @0x14bf04 pop {r3, lr}
 *   @0x14bf08 add r0, pc, r0
 *   @0x14bf0c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bf10 andseq r7, pc, r0, lsr #29
 *
 * ══ §34/561 F_PhysicsParticleGroupSetPoly(RValue&, CInstance*, CInstance*, int, RValue*)  0x14da6c  size 60  15 条（0x14da6c..0x14daa8）
 * @func 0x14da6c 0x14daa8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0xb4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14da6c ldr r3, [pc, #0x2c]
 *   @0x14da70 ldr r3, [pc, r3]
 *   @0x14da74 ldr r3, [r3]
 *   @0x14da78 cmp r3, #0
 *   @0x14da7c beq 0x14da90 <_Z29F_PhysicsParticleGroupSetPolyR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x14da80 ldr r0, [r3, #0xb4]
 *   @0x14da84 cmp r0, #0
 *   @0x14da88 beq 0x14da90 <_Z29F_PhysicsParticleGroupSetPolyR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x14da8c b 0x239b98 <_ZN13CPhysicsWorld17ParticleGroupPolyEv>
 *   @0x14da90 ldr r0, [pc, #0xc]
 *   @0x14da94 mov r1, #0
 *   @0x14da98 add r0, pc, r0
 *   @0x14da9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14daa0 .word 0x0029feb8
 *   @0x14daa4 mulseq pc, r12, r8
 *
 * ══ §35/561 F_GamepadAddMappingFromFile(RValue&, CInstance*, CInstance*, int, RValue*)  0x152b90  size 60  15 条（0x152b90..0x152bcc）
 * @func 0x152b90 0x152bcc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / SGamepadMapping::CreateFromFile(char const*)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152b90 push {r4, lr}
 *   @0x152b94 mov r1, #0
 *   @0x152b98 mov r4, r0
 *   @0x152b9c ldr r0, [sp, #0x8]
 *   @0x152ba0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x152ba4 bl 0x152b14 <_ZN15SGamepadMapping14CreateFromFileEPKc>
 *   @0x152ba8 mov r3, #0
 *   @0x152bac str r3, [r4, #0xc]
 *   @0x152bb0 vmov s15, r0
 *   @0x152bb4 vcvt.f64.s32 d7, s15
 *   @0x152bb8 vmov r0, r1, d7
 *   @0x152bbc vmov r2, s14
 *   @0x152bc0 mov r3, r1
 *   @0x152bc4 stm r4, {r2, r3}
 *   @0x152bc8 pop {r4, pc}
 *
 * ══ §36/561 F_GMLApplicationSurfaceDrawEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x158370  size 60  15 条（0x158370..0x1583ac）
 * @func 0x158370 0x1583ac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0x1c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158370 push {r3, lr}
 *   @0x158374 mov r1, #0
 *   @0x158378 ldr r0, [sp, #0x8]
 *   @0x15837c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x158380 vmov.f64 d7, #5.000000e-01
 *   @0x158384 ldr r3, [pc, #0x1c]
 *   @0x158388 ldr r3, [pc, r3]
 *   @0x15838c vmov d6, r0, r1
 *   @0x158390 vcmpe.f64 d6, d7
 *   @0x158394 vmrs APSR_nzcv, fpscr
 *   @0x158398 movle r2, #0
 *   @0x15839c movgt r2, #1
 *   @0x1583a0 strb r2, [r3]
 *   @0x1583a4 pop {r3, pc}
 *   @0x1583a8 .word 0x002977fc
 *
 * ══ §37/561 F_YoYo_MouseXRaw(RValue&, CInstance*, CInstance*, int, RValue*)  0x159eb0  size 60  15 条（0x159eb0..0x159eec）
 * @func 0x159eb0 0x159eec  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetRawMouseX(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159eb0 push {r4, lr}
 *   @0x159eb4 mov r3, #0
 *   @0x159eb8 mov r1, r3
 *   @0x159ebc str r3, [r0, #0xc]
 *   @0x159ec0 mov r4, r0
 *   @0x159ec4 ldr r0, [sp, #0x8]
 *   @0x159ec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159ecc bl 0x159e8c <_Z12GetRawMouseXi>
 *   @0x159ed0 vmov s15, r0
 *   @0x159ed4 vcvt.f64.s32 d7, s15
 *   @0x159ed8 vmov r0, r1, d7
 *   @0x159edc vmov r2, s14
 *   @0x159ee0 mov r3, r1
 *   @0x159ee4 stm r4, {r2, r3}
 *   @0x159ee8 pop {r4, pc}
 *
 * ══ §38/561 F_YoYo_MouseYRaw(RValue&, CInstance*, CInstance*, int, RValue*)  0x159f10  size 60  15 条（0x159f10..0x159f4c）
 * @func 0x159f10 0x159f4c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetRawMouseY(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159f10 push {r4, lr}
 *   @0x159f14 mov r3, #0
 *   @0x159f18 mov r1, r3
 *   @0x159f1c str r3, [r0, #0xc]
 *   @0x159f20 mov r4, r0
 *   @0x159f24 ldr r0, [sp, #0x8]
 *   @0x159f28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x159f2c bl 0x159eec <_Z12GetRawMouseYi>
 *   @0x159f30 vmov s15, r0
 *   @0x159f34 vcvt.f64.s32 d7, s15
 *   @0x159f38 vmov r0, r1, d7
 *   @0x159f3c vmov r2, s14
 *   @0x159f40 mov r3, r1
 *   @0x159f44 stm r4, {r2, r3}
 *   @0x159f48 pop {r4, pc}
 *
 * ══ §39/561 F_YoYo_MouseX(RValue&, CInstance*, CInstance*, int, RValue*)  0x15e774  size 60  15 条（0x15e774..0x15e7b0）
 * @func 0x15e774 0x15e7b0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Window_Views_Mouse_Get_X(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e774 push {r4, lr}
 *   @0x15e778 mov r3, #0
 *   @0x15e77c mov r1, r3
 *   @0x15e780 str r3, [r0, #0xc]
 *   @0x15e784 mov r4, r0
 *   @0x15e788 ldr r0, [sp, #0x8]
 *   @0x15e78c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e790 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi>
 *   @0x15e794 vmov s15, r0
 *   @0x15e798 vcvt.f64.s32 d7, s15
 *   @0x15e79c vmov r0, r1, d7
 *   @0x15e7a0 vmov r2, s14
 *   @0x15e7a4 mov r3, r1
 *   @0x15e7a8 stm r4, {r2, r3}
 *   @0x15e7ac pop {r4, pc}
 *
 * ══ §40/561 F_YoYo_MouseY(RValue&, CInstance*, CInstance*, int, RValue*)  0x15e7b0  size 60  15 条（0x15e7b0..0x15e7ec）
 * @func 0x15e7b0 0x15e7ec  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GR_Window_Views_Mouse_Get_Y(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e7b0 push {r4, lr}
 *   @0x15e7b4 mov r3, #0
 *   @0x15e7b8 mov r1, r3
 *   @0x15e7bc str r3, [r0, #0xc]
 *   @0x15e7c0 mov r4, r0
 *   @0x15e7c4 ldr r0, [sp, #0x8]
 *   @0x15e7c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15e7cc bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi>
 *   @0x15e7d0 vmov s15, r0
 *   @0x15e7d4 vcvt.f64.s32 d7, s15
 *   @0x15e7d8 vmov r0, r1, d7
 *   @0x15e7dc vmov r2, s14
 *   @0x15e7e0 mov r3, r1
 *   @0x15e7e4 stm r4, {r2, r3}
 *   @0x15e7e8 pop {r4, pc}
 *
 * ══ §41/561 F_CheckMouseButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x160dcc  size 60  15 条（0x160dcc..0x160e08）
 * @func 0x160dcc 0x160e08  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160dcc push {r4, r5, r6, lr}
 *   @0x160dd0 mov r5, r0
 *   @0x160dd4 mov r4, r1
 *   @0x160dd8 ldr r0, [sp, #0x10]
 *   @0x160ddc mov r1, #0
 *   @0x160de0 mov r6, r2
 *   @0x160de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x160de8 mov r1, r4
 *   @0x160dec mov r2, r6
 *   @0x160df0 mov r12, #0
 *   @0x160df4 str r12, [sp, #0x10]
 *   @0x160df8 mov r3, r0
 *   @0x160dfc mov r0, r5
 *   @0x160e00 pop {r4, r5, r6, lr}
 *   @0x160e04 b 0x160b2c <_Z25F_CheckMouseButton_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §42/561 F_CheckMouseButtonPressed(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e08  size 60  15 条（0x160e08..0x160e44）
 * @func 0x160e08 0x160e44  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e08 push {r4, r5, r6, lr}
 *   @0x160e0c mov r5, r0
 *   @0x160e10 mov r4, r1
 *   @0x160e14 ldr r0, [sp, #0x10]
 *   @0x160e18 mov r1, #0
 *   @0x160e1c mov r6, r2
 *   @0x160e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x160e24 mov r1, r4
 *   @0x160e28 mov r2, r6
 *   @0x160e2c mov r12, #0
 *   @0x160e30 str r12, [sp, #0x10]
 *   @0x160e34 mov r3, r0
 *   @0x160e38 mov r0, r5
 *   @0x160e3c pop {r4, r5, r6, lr}
 *   @0x160e40 b 0x160c0c <_Z32F_CheckMouseButtonPressed_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §43/561 F_CheckMouseButtonReleased(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e44  size 60  15 条（0x160e44..0x160e80）
 * @func 0x160e44 0x160e80  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e44 push {r4, r5, r6, lr}
 *   @0x160e48 mov r5, r0
 *   @0x160e4c mov r4, r1
 *   @0x160e50 ldr r0, [sp, #0x10]
 *   @0x160e54 mov r1, #0
 *   @0x160e58 mov r6, r2
 *   @0x160e5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x160e60 mov r1, r4
 *   @0x160e64 mov r2, r6
 *   @0x160e68 mov r12, #0
 *   @0x160e6c str r12, [sp, #0x10]
 *   @0x160e70 mov r3, r0
 *   @0x160e74 mov r0, r5
 *   @0x160e78 pop {r4, r5, r6, lr}
 *   @0x160e7c b 0x160cec <_Z33F_CheckMouseButtonReleased_CommonR6RValueP9CInstanceS2_ii>
 *
 * ══ §44/561 CCamera::GetViewProjMat()  0x16d1ac  size 60  15 条（0x16d1ac..0x16d1e8）
 * @func 0x16d1ac 0x16d1e8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d1ac push {r4, r5}
 *   @0x16d1b0 add r4, r1, #132
 *   @0x16d1b4 mov r5, r0
 *   @0x16d1b8 mov r12, r0
 *   @0x16d1bc ldm r4!, {r0, r1, r2, r3}
 *   @0x16d1c0 stm r12!, {r0, r1, r2, r3}
 *   @0x16d1c4 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d1c8 stm r12!, {r0, r1, r2, r3}
 *   @0x16d1cc ldm r4!, {r0, r1, r2, r3}
 *   @0x16d1d0 stm r12!, {r0, r1, r2, r3}
 *   @0x16d1d4 ldm r4, {r0, r1, r2, r3}
 *   @0x16d1d8 stm r12, {r0, r1, r2, r3}
 *   @0x16d1dc mov r0, r5
 *   @0x16d1e0 pop {r4, r5}
 *   @0x16d1e4 bx lr
 *
 * ══ §45/561 CCamera::GetInvProjMat()  0x16d1e8  size 60  15 条（0x16d1e8..0x16d224）
 * @func 0x16d1e8 0x16d224  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d1e8 push {r4, r5}
 *   @0x16d1ec add r4, r1, #196
 *   @0x16d1f0 mov r5, r0
 *   @0x16d1f4 mov r12, r0
 *   @0x16d1f8 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d1fc stm r12!, {r0, r1, r2, r3}
 *   @0x16d200 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d204 stm r12!, {r0, r1, r2, r3}
 *   @0x16d208 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d20c stm r12!, {r0, r1, r2, r3}
 *   @0x16d210 ldm r4, {r0, r1, r2, r3}
 *   @0x16d214 stm r12, {r0, r1, r2, r3}
 *   @0x16d218 mov r0, r5
 *   @0x16d21c pop {r4, r5}
 *   @0x16d220 bx lr
 *
 * ══ §46/561 CCamera::GetInvViewMat()  0x16d224  size 60  15 条（0x16d224..0x16d260）
 * @func 0x16d224 0x16d260  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d224 push {r4, r5}
 *   @0x16d228 add r4, r1, #260
 *   @0x16d22c mov r5, r0
 *   @0x16d230 mov r12, r0
 *   @0x16d234 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d238 stm r12!, {r0, r1, r2, r3}
 *   @0x16d23c ldm r4!, {r0, r1, r2, r3}
 *   @0x16d240 stm r12!, {r0, r1, r2, r3}
 *   @0x16d244 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d248 stm r12!, {r0, r1, r2, r3}
 *   @0x16d24c ldm r4, {r0, r1, r2, r3}
 *   @0x16d250 stm r12, {r0, r1, r2, r3}
 *   @0x16d254 mov r0, r5
 *   @0x16d258 pop {r4, r5}
 *   @0x16d25c bx lr
 *
 * ══ §47/561 GR_Texture_Set_Priority(int, int)  0x1742bc  size 60  15 条（0x1742bc..0x1742f8）
 * @func 0x1742bc 0x1742f8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1742bc push {r3, r4, r5, lr}
 *   @0x1742c0 mov r5, r1
 *   @0x1742c4 mov r4, r0
 *   @0x1742c8 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1742cc cmp r0, #0
 *   @0x1742d0 popeq {r3, r4, r5, pc}
 *   @0x1742d4 ldr r3, [pc, #0x18]
 *   @0x1742d8 mov r1, r5
 *   @0x1742dc ldr r3, [pc, r3]
 *   @0x1742e0 ldr r3, [r3, #0x4]
 *   @0x1742e4 ldr r3, [r3, r4, lsl #2]
 *   @0x1742e8 ldr r0, [r3]
 *   @0x1742ec pop {r3, r4, r5, lr}
 *   @0x1742f0 b 0x1833c8 <_ZN8Graphics18SetTexturePriorityEPvi>
 *   @0x1742f4 eoreq r9, r7, r0, asr #12
 *
 * ══ §48/561 GR_View_Undefine_All()  0x179d00  size 60  15 条（0x179d00..0x179d3c）
 * @func 0x179d00 0x179d3c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179d00 ldr r2, [pc, #0x2c]
 *   @0x179d04 mov r3, #0
 *   @0x179d08 mov r0, r3
 *   @0x179d0c ldr r2, [pc, r2]
 *   @0x179d10 strb r0, [r2, r3]
 *   @0x179d14 add r3, r3, #48
 *   @0x179d18 cmp r3, #1536
 *   @0x179d1c mov r1, #0
 *   @0x179d20 bne 0x179d10 <_Z20GR_View_Undefine_Allv+0x10>
 *   @0x179d24 ldr r3, [pc, #0xc]
 *   @0x179d28 ldr r3, [pc, r3]
 *   @0x179d2c str r1, [r3]
 *   @0x179d30 bx lr
 *   @0x179d34 .word 0x002765f4
 *   @0x179d38 .word 0x002765dc
 *
 * ══ §49/561 FreePNG(yyPNGFile*)  0x189b3c  size 60  15 条（0x189b3c..0x189b78）
 * @func 0x189b3c 0x189b78  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_destroy_read_struct / operator delete[](void*)
 * 字段偏移 top8: 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x189b3c push {r4, lr}
 *   @0x189b40 mov r4, r0
 *   @0x189b44 add r0, r0, #20
 *   @0x189b48 add r1, r4, #24
 *   @0x189b4c add r2, r4, #28
 *   @0x189b50 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189b54 ldr r0, [r4, #0x20]
 *   @0x189b58 cmp r0, #0
 *   @0x189b5c beq 0x189b64 <_Z7FreePNGP9yyPNGFile+0x28>
 *   @0x189b60 bl 0x27d1d4 <_ZdaPv>
 *   @0x189b64 ldr r0, [r4, #0x24]
 *   @0x189b68 cmp r0, #0
 *   @0x189b6c popeq {r4, pc}
 *   @0x189b70 pop {r4, lr}
 *   @0x189b74 b 0x27d1d4 <_ZdaPv>
 *
 * ══ §50/561 AddToWhiteList(YYWhitelistFilename**, char const*, bool)  0x18db0c  size 60  15 条（0x18db0c..0x18db48）
 * @func 0x18db0c 0x18db48  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18db0c push {r3, r4, r5, r6, r7, lr}
 *   @0x18db10 mov r5, r0
 *   @0x18db14 mov r0, #12
 *   @0x18db18 mov r6, r1
 *   @0x18db1c mov r7, r2
 *   @0x18db20 bl 0x27c524 <_Znwj>
 *   @0x18db24 mov r4, r0
 *   @0x18db28 mov r0, r6
 *   @0x18db2c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x18db30 strb r7, [r4, #0x8]
 *   @0x18db34 str r0, [r4, #0x4]
 *   @0x18db38 ldr r3, [r5]
 *   @0x18db3c str r3, [r4]
 *   @0x18db40 str r4, [r5]
 *   @0x18db44 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §51/561 GMGamePad::ButtonValue(int) const  0x18ed48  size 60  15 条（0x18ed48..0x18ed84）
 * @func 0x18ed48 0x18ed84  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::ButtonValue(int) const+0x2c
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ed48 subs r3, r1, #0
 *   @0x18ed4c blt 0x18ed74 <_ZNK9GMGamePad11ButtonValueEi+0x2c>
 *   @0x18ed50 tst r3, #4096
 *   @0x18ed54 bne 0x18ed7c <_ZNK9GMGamePad11ButtonValueEi+0x34>
 *   @0x18ed58 ldr r1, [r0, #0x4]
 *   @0x18ed5c cmp r3, r1
 *   @0x18ed60 bge 0x18ed74 <_ZNK9GMGamePad11ButtonValueEi+0x2c>
 *   @0x18ed64 ldr r2, [r0, #0x10]
 *   @0x18ed68 add r3, r2, r3, lsl #2
 *   @0x18ed6c ldr r0, [r3]
 *   @0x18ed70 bx lr
 *   @0x18ed74 mov r0, #0
 *   @0x18ed78 bx lr
 *   @0x18ed7c ldr r2, [r0, #0x14]
 *   @0x18ed80 b 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *
 * ══ §52/561 CREATE_RVALUE_MUTEX()  0x190ef0  size 60  15 条（0x190ef0..0x190f2c）
 * @func 0x190ef0 0x190f2c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544
 * 字段偏移 top8: 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190ef0 push {r4, lr}
 *   @0x190ef4 ldr r4, [pc, #0x28]
 *   @0x190ef8 ldr r4, [pc, r4]
 *   @0x190efc ldr r3, [r4]
 *   @0x190f00 cmp r3, #0
 *   @0x190f04 popne {r4, pc}
 *   @0x190f08 mov r0, #8
 *   @0x190f0c bl 0xb6544 <malloc@plt>
 *   @0x190f10 ldr r1, [pc, #0x10]
 *   @0x190f14 add r1, pc, r1
 *   @0x190f18 str r0, [r4]
 *   @0x190f1c pop {r4, lr}
 *   @0x190f20 b 0x27e038 <_ZN5Mutex4InitEPKc>
 *   @0x190f24 eoreq pc, r5, r12, ror r7
 *   @0x190f28 andseq r11, r11, r8, asr #13
 *
 * ══ §53/561 CGrid::~CGrid()  0x199f84  size 60  15 条（0x199f84..0x199fc0）
 * @func 0x199f84 0x199fc0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / operator delete(void*)
 * 字段偏移 top8: 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f84 push {r4, lr}
 *   @0x199f88 mov r4, r0
 *   @0x199f8c ldr r0, [r0, #0x1c]
 *   @0x199f90 ldr r3, [pc, #0x24]
 *   @0x199f94 cmp r0, #0
 *   @0x199f98 ldr r3, [pc, r3]
 *   @0x199f9c add r3, r3, #8
 *   @0x199fa0 str r3, [r4]
 *   @0x199fa4 beq 0x199fac <_ZN5CGridD0Ev+0x28>
 *   @0x199fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x199fac mov r0, r4
 *   @0x199fb0 bl 0x27d1d0 <_ZdlPv>
 *   @0x199fb4 mov r0, r4
 *   @0x199fb8 pop {r4, pc}
 *   @0x199fbc eoreq r6, r5, r0, lsl r7
 *
 * ══ §54/561 ParticleType_Shape(int, int)  0x1a31a4  size 60  15 条（0x1a31a4..0x1a31e0）
 * @func 0x1a31a4 0x1a31e0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a31a4 push {r3, r4, r5, lr}
 *   @0x1a31a8 mov r5, r1
 *   @0x1a31ac mov r4, r0
 *   @0x1a31b0 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a31b4 cmp r0, #0
 *   @0x1a31b8 popeq {r3, r4, r5, pc}
 *   @0x1a31bc ldr r3, [pc, #0x18]
 *   @0x1a31c0 mvn r2, #0
 *   @0x1a31c4 ldr r3, [pc, r3]
 *   @0x1a31c8 ldr r3, [r3, #0x4]
 *   @0x1a31cc ldr r3, [r3, r4, lsl #2]
 *   @0x1a31d0 str r5, [r3, #0x8]
 *   @0x1a31d4 str r2, [r3]
 *   @0x1a31d8 pop {r3, r4, r5, pc}
 *   @0x1a31dc eoreq sp, r4, r8, ror #11
 *
 * ══ §55/561 ParticleType_Scale(int, float, float)  0x1a3278  size 60  15 条（0x1a3278..0x1a32b4）
 * @func 0x1a3278 0x1a32b4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3278 push {r4, r5, r6, lr}
 *   @0x1a327c mov r6, r1
 *   @0x1a3280 mov r4, r0
 *   @0x1a3284 mov r5, r2
 *   @0x1a3288 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a328c cmp r0, #0
 *   @0x1a3290 popeq {r4, r5, r6, pc}
 *   @0x1a3294 ldr r3, [pc, #0x14]
 *   @0x1a3298 ldr r3, [pc, r3]
 *   @0x1a329c ldr r3, [r3, #0x4]
 *   @0x1a32a0 ldr r3, [r3, r4, lsl #2]
 *   @0x1a32a4 str r6, [r3, #0x1c]
 *   @0x1a32a8 str r5, [r3, #0x20]
 *   @0x1a32ac pop {r4, r5, r6, pc}
 *   @0x1a32b0 eoreq sp, r4, r4, lsl r5
 *
 * ══ §56/561 ParticleType_Life(int, int, int)  0x1a32b4  size 60  15 条（0x1a32b4..0x1a32f0）
 * @func 0x1a32b4 0x1a32f0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a32b4 push {r4, r5, r6, lr}
 *   @0x1a32b8 mov r6, r1
 *   @0x1a32bc mov r5, r2
 *   @0x1a32c0 mov r4, r0
 *   @0x1a32c4 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a32c8 cmp r0, #0
 *   @0x1a32cc popeq {r4, r5, r6, pc}
 *   @0x1a32d0 ldr r3, [pc, #0x14]
 *   @0x1a32d4 ldr r3, [pc, r3]
 *   @0x1a32d8 ldr r3, [r3, #0x4]
 *   @0x1a32dc ldr r3, [r3, r4, lsl #2]
 *   @0x1a32e0 str r6, [r3, #0x24]
 *   @0x1a32e4 str r5, [r3, #0x28]
 *   @0x1a32e8 pop {r4, r5, r6, pc}
 *   @0x1a32ec .word 0x0024d4d8
 *
 * ══ §57/561 ParticleType_Step(int, int, int)  0x1a32f0  size 60  15 条（0x1a32f0..0x1a332c）
 * @func 0x1a32f0 0x1a332c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x38×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a32f0 push {r4, r5, r6, lr}
 *   @0x1a32f4 mov r6, r1
 *   @0x1a32f8 mov r5, r2
 *   @0x1a32fc mov r4, r0
 *   @0x1a3300 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3304 cmp r0, #0
 *   @0x1a3308 popeq {r4, r5, r6, pc}
 *   @0x1a330c ldr r3, [pc, #0x14]
 *   @0x1a3310 ldr r3, [pc, r3]
 *   @0x1a3314 ldr r3, [r3, #0x4]
 *   @0x1a3318 ldr r3, [r3, r4, lsl #2]
 *   @0x1a331c str r6, [r3, #0x38]
 *   @0x1a3320 str r5, [r3, #0x34]
 *   @0x1a3324 pop {r4, r5, r6, pc}
 *   @0x1a3328 mlaeq r4, r12, r4, sp
 *
 * ══ §58/561 ParticleType_Death(int, int, int)  0x1a332c  size 60  15 条（0x1a332c..0x1a3368）
 * @func 0x1a332c 0x1a3368  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x30×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a332c push {r4, r5, r6, lr}
 *   @0x1a3330 mov r6, r1
 *   @0x1a3334 mov r5, r2
 *   @0x1a3338 mov r4, r0
 *   @0x1a333c bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3340 cmp r0, #0
 *   @0x1a3344 popeq {r4, r5, r6, pc}
 *   @0x1a3348 ldr r3, [pc, #0x14]
 *   @0x1a334c ldr r3, [pc, r3]
 *   @0x1a3350 ldr r3, [r3, #0x4]
 *   @0x1a3354 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3358 str r6, [r3, #0x30]
 *   @0x1a335c str r5, [r3, #0x2c]
 *   @0x1a3360 pop {r4, r5, r6, pc}
 *   @0x1a3364 eoreq sp, r4, r0, ror #8
 *
 * ══ §59/561 ParticleType_Gravity(int, float, float)  0x1a3454  size 60  15 条（0x1a3454..0x1a3490）
 * @func 0x1a3454 0x1a3490  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x5c×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3454 push {r4, r5, r6, lr}
 *   @0x1a3458 mov r6, r1
 *   @0x1a345c mov r4, r0
 *   @0x1a3460 mov r5, r2
 *   @0x1a3464 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3468 cmp r0, #0
 *   @0x1a346c popeq {r4, r5, r6, pc}
 *   @0x1a3470 ldr r3, [pc, #0x14]
 *   @0x1a3474 ldr r3, [pc, r3]
 *   @0x1a3478 ldr r3, [r3, #0x4]
 *   @0x1a347c ldr r3, [r3, r4, lsl #2]
 *   @0x1a3480 str r6, [r3, #0x5c]
 *   @0x1a3484 str r5, [r3, #0x60]
 *   @0x1a3488 pop {r4, r5, r6, pc}
 *   @0x1a348c eoreq sp, r4, r8, lsr r3
 *
 * ══ §60/561 ParticleType_Color1(int, unsigned int)  0x1a359c  size 60  15 条（0x1a359c..0x1a35d8）
 * @func 0x1a359c 0x1a35d8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1 / 0x7c×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a359c push {r3, r4, r5, lr}
 *   @0x1a35a0 mov r5, r1
 *   @0x1a35a4 mov r4, r0
 *   @0x1a35a8 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a35ac cmp r0, #0
 *   @0x1a35b0 popeq {r3, r4, r5, pc}
 *   @0x1a35b4 ldr r3, [pc, #0x18]
 *   @0x1a35b8 mov r2, #0
 *   @0x1a35bc ldr r3, [pc, r3]
 *   @0x1a35c0 ldr r3, [r3, #0x4]
 *   @0x1a35c4 ldr r3, [r3, r4, lsl #2]
 *   @0x1a35c8 str r5, [r3, #0x7c]
 *   @0x1a35cc str r2, [r3, #0x78]
 *   @0x1a35d0 pop {r3, r4, r5, pc}
 *   @0x1a35d4 .word 0x0024d1f0
 *
 * ══ §61/561 ParticleType_Alpha1(int, float)  0x1a3668  size 60  15 条（0x1a3668..0x1a36a4）
 * @func 0x1a3668 0x1a36a4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1 / 0x94×1 / 0x98×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3668 push {r3, r4, r5, lr}
 *   @0x1a366c mov r4, r1
 *   @0x1a3670 mov r5, r0
 *   @0x1a3674 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3678 cmp r0, #0
 *   @0x1a367c popeq {r3, r4, r5, pc}
 *   @0x1a3680 ldr r3, [pc, #0x18]
 *   @0x1a3684 ldr r3, [pc, r3]
 *   @0x1a3688 ldr r3, [r3, #0x4]
 *   @0x1a368c ldr r3, [r3, r5, lsl #2]
 *   @0x1a3690 str r4, [r3, #0x94]
 *   @0x1a3694 str r4, [r3, #0x98]
 *   @0x1a3698 str r4, [r3, #0x9c]
 *   @0x1a369c pop {r3, r4, r5, pc}
 *   @0x1a36a0 eoreq sp, r4, r8, lsr #2
 *
 * ══ §62/561 ParticleSystem_Position(int, float, float)  0x1a4894  size 60  15 条（0x1a4894..0x1a48d0）
 * @func 0x1a4894 0x1a48d0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4894 push {r4, r5, r6, lr}
 *   @0x1a4898 mov r6, r1
 *   @0x1a489c mov r4, r0
 *   @0x1a48a0 mov r5, r2
 *   @0x1a48a4 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a48a8 cmp r0, #0
 *   @0x1a48ac popeq {r4, r5, r6, pc}
 *   @0x1a48b0 ldr r3, [pc, #0x14]
 *   @0x1a48b4 ldr r3, [pc, r3]
 *   @0x1a48b8 ldr r3, [r3, #0x4]
 *   @0x1a48bc ldr r3, [r3, r4, lsl #2]
 *   @0x1a48c0 str r6, [r3, #0x20]
 *   @0x1a48c4 str r5, [r3, #0x24]
 *   @0x1a48c8 pop {r4, r5, r6, pc}
 *   @0x1a48cc eoreq r11, r4, r4, lsl #30
 *
 * ══ §63/561 TBitmap::~TBitmap()  0x1a8a74  size 60  15 条（0x1a8a74..0x1a8ab0）
 * @func 0x1a8a74 0x1a8ab0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TBitmap::Clear()
 * 字段偏移 top8: 0x2c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8a74 ldr r3, [pc, #0x2c]
 *   @0x1a8a78 push {r4, lr}
 *   @0x1a8a7c ldr r3, [pc, r3]
 *   @0x1a8a80 add r3, r3, #8
 *   @0x1a8a84 str r3, [r0]
 *   @0x1a8a88 mov r4, r0
 *   @0x1a8a8c bl 0x1a8a44 <_ZN7TBitmap5ClearEv>
 *   @0x1a8a90 ldr r3, [pc, #0x14]
 *   @0x1a8a94 mov r0, r4
 *   @0x1a8a98 ldr r3, [pc, r3]
 *   @0x1a8a9c add r3, r3, #8
 *   @0x1a8aa0 str r3, [r4]
 *   @0x1a8aa4 pop {r4, pc}
 *   @0x1a8aa8 eoreq r7, r4, r4, lsl #27
 *   @0x1a8aac eoreq r7, r4, r0, ror #26
 *
 * ══ §64/561 TBitmap::TBitmap()  0x1a8b50  size 60  15 条（0x1a8b50..0x1a8b8c）
 * @func 0x1a8b50 0x1a8b8c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x8×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x24×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8b50 ldr r1, [pc, #0x30]
 *   @0x1a8b54 mov r2, #0
 *   @0x1a8b58 mov r12, #7
 *   @0x1a8b5c str r2, [r0, #0x8]
 *   @0x1a8b60 ldr r1, [pc, r1]
 *   @0x1a8b64 str r12, [r0, #0x14]
 *   @0x1a8b68 add r1, r1, #8
 *   @0x1a8b6c str r2, [r0, #0x18]
 *   @0x1a8b70 stm r0, {r1, r2}
 *   @0x1a8b74 mvn r1, #0
 *   @0x1a8b78 str r2, [r0, #0x1c]
 *   @0x1a8b7c str r1, [r0, #0x24]
 *   @0x1a8b80 str r1, [r0, #0x28]
 *   @0x1a8b84 bx lr
 *   @0x1a8b88 eoreq r7, r4, r0, lsr #25
 *
 * ══ §65/561 cARRAY_STRUCTURE<int>::~cARRAY_STRUCTURE()  0x1b4a28  size 60  15 条（0x1b4a28..0x1b4a64）
 * @func 0x1b4a28 0x1b4a64  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b4a28 push {r3, r4, r5, lr}
 *   @0x1b4a2c mov r4, r0
 *   @0x1b4a30 ldr r5, [r0, #0x4]
 *   @0x1b4a34 subs r0, r5, #0
 *   @0x1b4a38 beq 0x1b4a58 <_ZN16cARRAY_STRUCTUREIiED2Ev+0x30>
 *   @0x1b4a3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4a40 mov r3, #0
 *   @0x1b4a44 str r3, [r4, #0x4]
 *   @0x1b4a48 mov r3, #0
 *   @0x1b4a4c mov r0, r4
 *   @0x1b4a50 str r3, [r4]
 *   @0x1b4a54 pop {r3, r4, r5, pc}
 *   @0x1b4a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4a5c str r5, [r4, #0x4]
 *   @0x1b4a60 b 0x1b4a48 <_ZN16cARRAY_STRUCTUREIiED2Ev+0x20>
 *
 * ══ §66/561 IsLayerListInOrder(CRoom*)  0x1b6ec0  size 60  15 条（0x1b6ec0..0x1b6efc）
 * @func 0x1b6ec0 0x1b6efc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xd4×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6ec0 ldr r3, [r0, #0xd4]
 *   @0x1b6ec4 cmp r3, #0
 *   @0x1b6ec8 beq 0x1b6ef4 <_Z18IsLayerListInOrderP5CRoom+0x34>
 *   @0x1b6ecc ldr r1, [r3, #0x4]
 *   @0x1b6ed0 ldr r3, [r3, #0x68]
 *   @0x1b6ed4 cmp r3, #0
 *   @0x1b6ed8 beq 0x1b6ef4 <_Z18IsLayerListInOrderP5CRoom+0x34>
 *   @0x1b6edc ldr r2, [r3, #0x4]
 *   @0x1b6ee0 cmp r2, r1
 *   @0x1b6ee4 mov r1, r2
 *   @0x1b6ee8 bge 0x1b6ed0 <_Z18IsLayerListInOrderP5CRoom+0x10>
 *   @0x1b6eec mov r0, #0
 *   @0x1b6ef0 bx lr
 *   @0x1b6ef4 mov r0, #1
 *   @0x1b6ef8 bx lr
 *
 * ══ §67/561 CSprite::GetBitmap24(int)  0x1e635c  size 60  15 条（0x1e635c..0x1e6398）
 * @func 0x1e635c 0x1e6398  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::GetBitmap24(int)+0x34
 * 字段偏移 top8: 0x18×1 / 0x48×1 / 0x74×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e635c cmp r1, #0
 *   @0x1e6360 blt 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34>
 *   @0x1e6364 ldr r3, [r0, #0x18]
 *   @0x1e6368 cmp r1, r3
 *   @0x1e636c bge 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34>
 *   @0x1e6370 ldr r3, [r0, #0x48]
 *   @0x1e6374 cmp r3, #0
 *   @0x1e6378 beq 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34>
 *   @0x1e637c ldr r2, [r0, #0x74]
 *   @0x1e6380 cmp r2, #0
 *   @0x1e6384 bne 0x1e6390 <_ZN7CSprite11GetBitmap24Ei+0x34>
 *   @0x1e6388 ldr r0, [r3, r1, lsl #2]
 *   @0x1e638c b 0x1675e8 <_ZN9CBitmap3214CreateBitmap24Ev>
 *   @0x1e6390 mov r0, #0
 *   @0x1e6394 bx lr
 *
 * ══ §68/561 CSprite::GetBitmap32(int)  0x1e6398  size 60  15 条（0x1e6398..0x1e63d4）
 * @func 0x1e6398 0x1e63d4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::GetBitmap32(int)+0x34
 * 字段偏移 top8: 0x18×1 / 0x48×1 / 0x74×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6398 cmp r1, #0
 *   @0x1e639c blt 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34>
 *   @0x1e63a0 ldr r3, [r0, #0x18]
 *   @0x1e63a4 cmp r1, r3
 *   @0x1e63a8 bge 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34>
 *   @0x1e63ac ldr r3, [r0, #0x48]
 *   @0x1e63b0 cmp r3, #0
 *   @0x1e63b4 beq 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34>
 *   @0x1e63b8 ldr r2, [r0, #0x74]
 *   @0x1e63bc cmp r2, #0
 *   @0x1e63c0 bne 0x1e63cc <_ZN7CSprite11GetBitmap32Ei+0x34>
 *   @0x1e63c4 ldr r0, [r3, r1, lsl #2]
 *   @0x1e63c8 b 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev>
 *   @0x1e63cc mov r0, #0
 *   @0x1e63d0 bx lr
 *
 * ══ §69/561 cARRAY_STRUCTURE<bool>::~cARRAY_STRUCTURE()  0x1f3318  size 60  15 条（0x1f3318..0x1f3354）
 * @func 0x1f3318 0x1f3354  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3318 push {r3, r4, r5, lr}
 *   @0x1f331c mov r4, r0
 *   @0x1f3320 ldr r5, [r0, #0x4]
 *   @0x1f3324 subs r0, r5, #0
 *   @0x1f3328 beq 0x1f3348 <_ZN16cARRAY_STRUCTUREIbED2Ev+0x30>
 *   @0x1f332c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3330 mov r3, #0
 *   @0x1f3334 str r3, [r4, #0x4]
 *   @0x1f3338 mov r3, #0
 *   @0x1f333c mov r0, r4
 *   @0x1f3340 str r3, [r4]
 *   @0x1f3344 pop {r3, r4, r5, pc}
 *   @0x1f3348 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f334c str r5, [r4, #0x4]
 *   @0x1f3350 b 0x1f3338 <_ZN16cARRAY_STRUCTUREIbED2Ev+0x20>
 *
 * ══ §70/561 CVariableList::Exists(int)  0x1f5360  size 60  15 条（0x1f5360..0x1f539c）
 * @func 0x1f5360 0x1f539c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5360 and r3, r1, #3
 *   @0x1f5364 add r0, r0, r3, lsl #2
 *   @0x1f5368 ldr r0, [r0, #0x4]
 *   @0x1f536c cmp r0, #0
 *   @0x1f5370 bne 0x1f5384 <_ZN13CVariableList6ExistsEi+0x24>
 *   @0x1f5374 bx lr
 *   @0x1f5378 ldr r0, [r0]
 *   @0x1f537c cmp r0, #0
 *   @0x1f5380 beq 0x1f5398 <_ZN13CVariableList6ExistsEi+0x38>
 *   @0x1f5384 ldr r3, [r0, #0x8]
 *   @0x1f5388 cmp r3, r1
 *   @0x1f538c bne 0x1f5378 <_ZN13CVariableList6ExistsEi+0x18>
 *   @0x1f5390 mov r0, #1
 *   @0x1f5394 bx lr
 *   @0x1f5398 bx lr
 *
 * ══ §71/561 GV_FpsReal(CInstance*, int, RValue*)  0x1f880c  size 60  15 条（0x1f880c..0x1f8848）
 * @func 0x1f880c 0x1f8848  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f880c ldr r3, [pc, #0x30]
 *   @0x1f8810 mov r1, #0
 *   @0x1f8814 push {r4, r5}
 *   @0x1f8818 ldr r3, [pc, r3]
 *   @0x1f881c vldr s15, [r3]
 *   @0x1f8820 vcvt.f64.f32 d6, s15
 *   @0x1f8824 str r1, [r2, #0xc]
 *   @0x1f8828 mov r0, #1
 *   @0x1f882c vmov r4, r5, d6
 *   @0x1f8830 vmov r1, s12
 *   @0x1f8834 mov r3, r5
 *   @0x1f8838 pop {r4, r5}
 *   @0x1f883c stm r2, {r1, r3}
 *   @0x1f8840 bx lr
 *   @0x1f8844 andseq r7, pc, r0, ror #23
 *
 * ══ §72/561 GV_CurrentMonth(CInstance*, int, RValue*)  0x1fa2f0  size 60  15 条（0x1fa2f0..0x1fa32c）
 * @func 0x1fa2f0 0x1fa32c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa2f0 push {r4, r5, r6, lr}
 *   @0x1fa2f4 mov r3, #0
 *   @0x1fa2f8 str r3, [r2, #0xc]
 *   @0x1fa2fc mov r6, r2
 *   @0x1fa300 bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa304 ldr r4, [r0, #0x10]
 *   @0x1fa308 mov r0, #1
 *   @0x1fa30c add r4, r4, r0
 *   @0x1fa310 vmov s15, r4
 *   @0x1fa314 vcvt.f64.s32 d7, s15
 *   @0x1fa318 vmov r4, r5, d7
 *   @0x1fa31c vmov r2, s14
 *   @0x1fa320 mov r3, r5
 *   @0x1fa324 stm r6, {r2, r3}
 *   @0x1fa328 pop {r4, r5, r6, pc}
 *
 * ══ §73/561 GV_Alarm(CInstance*, int, RValue*)  0x1fa870  size 60  15 条（0x1fa870..0x1fa8ac）
 * @func 0x1fa870 0x1fa8ac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::GetTimer(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa870 cmp r1, #11
 *   @0x1fa874 mov r3, #0
 *   @0x1fa878 push {r4, r5, r6, lr}
 *   @0x1fa87c movhi r1, #0
 *   @0x1fa880 str r3, [r2, #0xc]
 *   @0x1fa884 mov r6, r2
 *   @0x1fa888 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x1fa88c vmov s15, r0
 *   @0x1fa890 mov r0, #1
 *   @0x1fa894 vcvt.f64.s32 d7, s15
 *   @0x1fa898 vmov r4, r5, d7
 *   @0x1fa89c vmov r2, s14
 *   @0x1fa8a0 mov r3, r5
 *   @0x1fa8a4 stm r6, {r2, r3}
 *   @0x1fa8a8 pop {r4, r5, r6, pc}
 *
 * ══ §74/561 SV_ImageIndex(CInstance*, int, RValue*)  0x1fba70  size 60  15 条（0x1fba70..0x1fbaac）
 * @func 0x1fba70 0x1fbaac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fba70 ldr r3, [r2, #0xc]
 *   @0x1fba74 push {r4, lr}
 *   @0x1fba78 bic r3, r3, #-16777216
 *   @0x1fba7c cmp r3, #0
 *   @0x1fba80 mov r4, r0
 *   @0x1fba84 bne 0x1fbaa0 <_Z13SV_ImageIndexP9CInstanceiP6RValue+0x30>
 *   @0x1fba88 ldm r2, {r0, r1}
 *   @0x1fba8c vmov d6, r0, r1
 *   @0x1fba90 mov r0, #1
 *   @0x1fba94 vcvt.f32.f64 s15, d6
 *   @0x1fba98 vstr s15, [r4, #144]
 *   @0x1fba9c pop {r4, pc}
 *   @0x1fbaa0 mov r0, r2
 *   @0x1fbaa4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbaa8 b 0x1fba8c <_Z13SV_ImageIndexP9CInstanceiP6RValue+0x1c>
 *
 * ══ §75/561 SV_ImageSpeed(CInstance*, int, RValue*)  0x1fbb2c  size 60  15 条（0x1fbb2c..0x1fbb68）
 * @func 0x1fbb2c 0x1fbb68  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbb2c ldr r3, [r2, #0xc]
 *   @0x1fbb30 push {r4, lr}
 *   @0x1fbb34 bic r3, r3, #-16777216
 *   @0x1fbb38 cmp r3, #0
 *   @0x1fbb3c mov r4, r0
 *   @0x1fbb40 bne 0x1fbb5c <_Z13SV_ImageSpeedP9CInstanceiP6RValue+0x30>
 *   @0x1fbb44 ldm r2, {r0, r1}
 *   @0x1fbb48 vmov d6, r0, r1
 *   @0x1fbb4c mov r0, #1
 *   @0x1fbb50 vcvt.f32.f64 s15, d6
 *   @0x1fbb54 vstr s15, [r4, #148]
 *   @0x1fbb58 pop {r4, pc}
 *   @0x1fbb5c mov r0, r2
 *   @0x1fbb60 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbb64 b 0x1fbb48 <_Z13SV_ImageSpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §76/561 SV_ImageAlpha(CInstance*, int, RValue*)  0x1fbb68  size 60  15 条（0x1fbb68..0x1fbba4）
 * @func 0x1fbb68 0x1fbba4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbb68 ldr r3, [r2, #0xc]
 *   @0x1fbb6c push {r4, lr}
 *   @0x1fbb70 bic r3, r3, #-16777216
 *   @0x1fbb74 cmp r3, #0
 *   @0x1fbb78 mov r4, r0
 *   @0x1fbb7c bne 0x1fbb98 <_Z13SV_ImageAlphaP9CInstanceiP6RValue+0x30>
 *   @0x1fbb80 ldm r2, {r0, r1}
 *   @0x1fbb84 vmov d6, r0, r1
 *   @0x1fbb88 mov r0, #1
 *   @0x1fbb8c vcvt.f32.f64 s15, d6
 *   @0x1fbb90 vstr s15, [r4, #164]
 *   @0x1fbb94 pop {r4, pc}
 *   @0x1fbb98 mov r0, r2
 *   @0x1fbb9c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbba0 b 0x1fbb84 <_Z13SV_ImageAlphaP9CInstanceiP6RValue+0x1c>
 *
 * ══ §77/561 SV_XPrevious(CInstance*, int, RValue*)  0x1fbc48  size 60  15 条（0x1fbc48..0x1fbc84）
 * @func 0x1fbc48 0x1fbc84  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbc48 ldr r3, [r2, #0xc]
 *   @0x1fbc4c push {r4, lr}
 *   @0x1fbc50 bic r3, r3, #-16777216
 *   @0x1fbc54 cmp r3, #0
 *   @0x1fbc58 mov r4, r0
 *   @0x1fbc5c bne 0x1fbc78 <_Z12SV_XPreviousP9CInstanceiP6RValue+0x30>
 *   @0x1fbc60 ldm r2, {r0, r1}
 *   @0x1fbc64 vmov d6, r0, r1
 *   @0x1fbc68 mov r0, #1
 *   @0x1fbc6c vcvt.f32.f64 s15, d6
 *   @0x1fbc70 vstr s15, [r4, #196]
 *   @0x1fbc74 pop {r4, pc}
 *   @0x1fbc78 mov r0, r2
 *   @0x1fbc7c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbc80 b 0x1fbc64 <_Z12SV_XPreviousP9CInstanceiP6RValue+0x1c>
 *
 * ══ §78/561 SV_YPrevious(CInstance*, int, RValue*)  0x1fbc84  size 60  15 条（0x1fbc84..0x1fbcc0）
 * @func 0x1fbc84 0x1fbcc0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbc84 ldr r3, [r2, #0xc]
 *   @0x1fbc88 push {r4, lr}
 *   @0x1fbc8c bic r3, r3, #-16777216
 *   @0x1fbc90 cmp r3, #0
 *   @0x1fbc94 mov r4, r0
 *   @0x1fbc98 bne 0x1fbcb4 <_Z12SV_YPreviousP9CInstanceiP6RValue+0x30>
 *   @0x1fbc9c ldm r2, {r0, r1}
 *   @0x1fbca0 vmov d6, r0, r1
 *   @0x1fbca4 mov r0, #1
 *   @0x1fbca8 vcvt.f32.f64 s15, d6
 *   @0x1fbcac vstr s15, [r4, #200]
 *   @0x1fbcb0 pop {r4, pc}
 *   @0x1fbcb4 mov r0, r2
 *   @0x1fbcb8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbcbc b 0x1fbca0 <_Z12SV_YPreviousP9CInstanceiP6RValue+0x1c>
 *
 * ══ §79/561 SV_XStart(CInstance*, int, RValue*)  0x1fbcc0  size 60  15 条（0x1fbcc0..0x1fbcfc）
 * @func 0x1fbcc0 0x1fbcfc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbcc0 ldr r3, [r2, #0xc]
 *   @0x1fbcc4 push {r4, lr}
 *   @0x1fbcc8 bic r3, r3, #-16777216
 *   @0x1fbccc cmp r3, #0
 *   @0x1fbcd0 mov r4, r0
 *   @0x1fbcd4 bne 0x1fbcf0 <_Z9SV_XStartP9CInstanceiP6RValue+0x30>
 *   @0x1fbcd8 ldm r2, {r0, r1}
 *   @0x1fbcdc vmov d6, r0, r1
 *   @0x1fbce0 mov r0, #1
 *   @0x1fbce4 vcvt.f32.f64 s15, d6
 *   @0x1fbce8 vstr s15, [r4, #188]
 *   @0x1fbcec pop {r4, pc}
 *   @0x1fbcf0 mov r0, r2
 *   @0x1fbcf4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbcf8 b 0x1fbcdc <_Z9SV_XStartP9CInstanceiP6RValue+0x1c>
 *
 * ══ §80/561 SV_YStart(CInstance*, int, RValue*)  0x1fbcfc  size 60  15 条（0x1fbcfc..0x1fbd38）
 * @func 0x1fbcfc 0x1fbd38  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbcfc ldr r3, [r2, #0xc]
 *   @0x1fbd00 push {r4, lr}
 *   @0x1fbd04 bic r3, r3, #-16777216
 *   @0x1fbd08 cmp r3, #0
 *   @0x1fbd0c mov r4, r0
 *   @0x1fbd10 bne 0x1fbd2c <_Z9SV_YStartP9CInstanceiP6RValue+0x30>
 *   @0x1fbd14 ldm r2, {r0, r1}
 *   @0x1fbd18 vmov d6, r0, r1
 *   @0x1fbd1c mov r0, #1
 *   @0x1fbd20 vcvt.f32.f64 s15, d6
 *   @0x1fbd24 vstr s15, [r4, #192]
 *   @0x1fbd28 pop {r4, pc}
 *   @0x1fbd2c mov r0, r2
 *   @0x1fbd30 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbd34 b 0x1fbd18 <_Z9SV_YStartP9CInstanceiP6RValue+0x1c>
 *
 * ══ §81/561 SV_Friction(CInstance*, int, RValue*)  0x1fbd38  size 60  15 条（0x1fbd38..0x1fbd74）
 * @func 0x1fbd38 0x1fbd74  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbd38 ldr r3, [r2, #0xc]
 *   @0x1fbd3c push {r4, lr}
 *   @0x1fbd40 bic r3, r3, #-16777216
 *   @0x1fbd44 cmp r3, #0
 *   @0x1fbd48 mov r4, r0
 *   @0x1fbd4c bne 0x1fbd68 <_Z11SV_FrictionP9CInstanceiP6RValue+0x30>
 *   @0x1fbd50 ldm r2, {r0, r1}
 *   @0x1fbd54 vmov d6, r0, r1
 *   @0x1fbd58 mov r0, #1
 *   @0x1fbd5c vcvt.f32.f64 s15, d6
 *   @0x1fbd60 vstr s15, [r4, #212]
 *   @0x1fbd64 pop {r4, pc}
 *   @0x1fbd68 mov r0, r2
 *   @0x1fbd6c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbd70 b 0x1fbd54 <_Z11SV_FrictionP9CInstanceiP6RValue+0x1c>
 *
 * ══ §82/561 SV_Gravity(CInstance*, int, RValue*)  0x1fbd74  size 60  15 条（0x1fbd74..0x1fbdb0）
 * @func 0x1fbd74 0x1fbdb0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbd74 ldr r3, [r2, #0xc]
 *   @0x1fbd78 push {r4, lr}
 *   @0x1fbd7c bic r3, r3, #-16777216
 *   @0x1fbd80 cmp r3, #0
 *   @0x1fbd84 mov r4, r0
 *   @0x1fbd88 bne 0x1fbda4 <_Z10SV_GravityP9CInstanceiP6RValue+0x30>
 *   @0x1fbd8c ldm r2, {r0, r1}
 *   @0x1fbd90 vmov d6, r0, r1
 *   @0x1fbd94 mov r0, #1
 *   @0x1fbd98 vcvt.f32.f64 s15, d6
 *   @0x1fbd9c vstr s15, [r4, #220]
 *   @0x1fbda0 pop {r4, pc}
 *   @0x1fbda4 mov r0, r2
 *   @0x1fbda8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbdac b 0x1fbd90 <_Z10SV_GravityP9CInstanceiP6RValue+0x1c>
 *
 * ══ §83/561 SV_GravityDir(CInstance*, int, RValue*)  0x1fbdb0  size 60  15 条（0x1fbdb0..0x1fbdec）
 * @func 0x1fbdb0 0x1fbdec  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbdb0 ldr r3, [r2, #0xc]
 *   @0x1fbdb4 push {r4, lr}
 *   @0x1fbdb8 bic r3, r3, #-16777216
 *   @0x1fbdbc cmp r3, #0
 *   @0x1fbdc0 mov r4, r0
 *   @0x1fbdc4 bne 0x1fbde0 <_Z13SV_GravityDirP9CInstanceiP6RValue+0x30>
 *   @0x1fbdc8 ldm r2, {r0, r1}
 *   @0x1fbdcc vmov d6, r0, r1
 *   @0x1fbdd0 mov r0, #1
 *   @0x1fbdd4 vcvt.f32.f64 s15, d6
 *   @0x1fbdd8 vstr s15, [r4, #216]
 *   @0x1fbddc pop {r4, pc}
 *   @0x1fbde0 mov r0, r2
 *   @0x1fbde4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbde8 b 0x1fbdcc <_Z13SV_GravityDirP9CInstanceiP6RValue+0x1c>
 *
 * ══ §84/561 SV_PathScale(CInstance*, int, RValue*)  0x1fbedc  size 60  15 条（0x1fbedc..0x1fbf18）
 * @func 0x1fbedc 0x1fbf18  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbedc ldr r3, [r2, #0xc]
 *   @0x1fbee0 push {r4, lr}
 *   @0x1fbee4 bic r3, r3, #-16777216
 *   @0x1fbee8 cmp r3, #0
 *   @0x1fbeec mov r4, r0
 *   @0x1fbef0 bne 0x1fbf0c <_Z12SV_PathScaleP9CInstanceiP6RValue+0x30>
 *   @0x1fbef4 ldm r2, {r0, r1}
 *   @0x1fbef8 vmov d6, r0, r1
 *   @0x1fbefc mov r0, #1
 *   @0x1fbf00 vcvt.f32.f64 s15, d6
 *   @0x1fbf04 vstr s15, [r4, #312]
 *   @0x1fbf08 pop {r4, pc}
 *   @0x1fbf0c mov r0, r2
 *   @0x1fbf10 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbf14 b 0x1fbef8 <_Z12SV_PathScaleP9CInstanceiP6RValue+0x1c>
 *
 * ══ §85/561 SV_PathOrientation(CInstance*, int, RValue*)  0x1fbf18  size 60  15 条（0x1fbf18..0x1fbf54）
 * @func 0x1fbf18 0x1fbf54  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbf18 ldr r3, [r2, #0xc]
 *   @0x1fbf1c push {r4, lr}
 *   @0x1fbf20 bic r3, r3, #-16777216
 *   @0x1fbf24 cmp r3, #0
 *   @0x1fbf28 mov r4, r0
 *   @0x1fbf2c bne 0x1fbf48 <_Z18SV_PathOrientationP9CInstanceiP6RValue+0x30>
 *   @0x1fbf30 ldm r2, {r0, r1}
 *   @0x1fbf34 vmov d6, r0, r1
 *   @0x1fbf38 mov r0, #1
 *   @0x1fbf3c vcvt.f32.f64 s15, d6
 *   @0x1fbf40 vstr s15, [r4, #316]
 *   @0x1fbf44 pop {r4, pc}
 *   @0x1fbf48 mov r0, r2
 *   @0x1fbf4c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fbf50 b 0x1fbf34 <_Z18SV_PathOrientationP9CInstanceiP6RValue+0x1c>
 *
 * ══ §86/561 SV_TimelinePosition(CInstance*, int, RValue*)  0x1fbfe4  size 60  15 条（0x1fbfe4..0x1fc020）
 * @func 0x1fbfe4 0x1fc020  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fbfe4 ldr r3, [r2, #0xc]
 *   @0x1fbfe8 push {r4, lr}
 *   @0x1fbfec bic r3, r3, #-16777216
 *   @0x1fbff0 cmp r3, #0
 *   @0x1fbff4 mov r4, r0
 *   @0x1fbff8 bne 0x1fc014 <_Z19SV_TimelinePositionP9CInstanceiP6RValue+0x30>
 *   @0x1fbffc ldm r2, {r0, r1}
 *   @0x1fc000 vmov d6, r0, r1
 *   @0x1fc004 mov r0, #1
 *   @0x1fc008 vcvt.f32.f64 s15, d6
 *   @0x1fc00c vstr s15, [r4, #340]
 *   @0x1fc010 pop {r4, pc}
 *   @0x1fc014 mov r0, r2
 *   @0x1fc018 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc01c b 0x1fc000 <_Z19SV_TimelinePositionP9CInstanceiP6RValue+0x1c>
 *
 * ══ §87/561 SV_TimelineSpeed(CInstance*, int, RValue*)  0x1fc020  size 60  15 条（0x1fc020..0x1fc05c）
 * @func 0x1fc020 0x1fc05c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc020 ldr r3, [r2, #0xc]
 *   @0x1fc024 push {r4, lr}
 *   @0x1fc028 bic r3, r3, #-16777216
 *   @0x1fc02c cmp r3, #0
 *   @0x1fc030 mov r4, r0
 *   @0x1fc034 bne 0x1fc050 <_Z16SV_TimelineSpeedP9CInstanceiP6RValue+0x30>
 *   @0x1fc038 ldm r2, {r0, r1}
 *   @0x1fc03c vmov d6, r0, r1
 *   @0x1fc040 mov r0, #1
 *   @0x1fc044 vcvt.f32.f64 s15, d6
 *   @0x1fc048 vstr s15, [r4, #344]
 *   @0x1fc04c pop {r4, pc}
 *   @0x1fc050 mov r0, r2
 *   @0x1fc054 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc058 b 0x1fc03c <_Z16SV_TimelineSpeedP9CInstanceiP6RValue+0x1c>
 *
 * ══ §88/561 cARRAY_STRUCTURE<RSoundSample>::~cARRAY_STRUCTURE()  0x21e7b8  size 60  15 条（0x21e7b8..0x21e7f4）
 * @func 0x21e7b8 0x21e7f4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e7b8 push {r3, r4, r5, lr}
 *   @0x21e7bc mov r4, r0
 *   @0x21e7c0 ldr r5, [r0, #0x4]
 *   @0x21e7c4 subs r0, r5, #0
 *   @0x21e7c8 beq 0x21e7e8 <_ZN16cARRAY_STRUCTUREI12RSoundSampleED2Ev+0x30>
 *   @0x21e7cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e7d0 mov r3, #0
 *   @0x21e7d4 str r3, [r4, #0x4]
 *   @0x21e7d8 mov r3, #0
 *   @0x21e7dc mov r0, r4
 *   @0x21e7e0 str r3, [r4]
 *   @0x21e7e4 pop {r3, r4, r5, pc}
 *   @0x21e7e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e7ec str r5, [r4, #0x4]
 *   @0x21e7f0 b 0x21e7d8 <_ZN16cARRAY_STRUCTUREI12RSoundSampleED2Ev+0x20>
 *
 * ══ §89/561 Sound_Name(int)  0x21fc18  size 60  15 条（0x21fc18..0x21fc54）
 * @func 0x21fc18 0x21fc54  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fc18 push {r4, lr}
 *   @0x21fc1c mov r4, r0
 *   @0x21fc20 bl 0x21fbd0 <_Z12Sound_Existsi>
 *   @0x21fc24 cmp r0, #0
 *   @0x21fc28 beq 0x21fc40 <_Z10Sound_Namei+0x28>
 *   @0x21fc2c ldr r3, [pc, #0x18]
 *   @0x21fc30 add r3, pc, r3
 *   @0x21fc34 ldr r3, [r3, #0xc]
 *   @0x21fc38 ldr r0, [r3, r4, lsl #2]
 *   @0x21fc3c pop {r4, pc}
 *   @0x21fc40 ldr r0, [pc, #0x8]
 *   @0x21fc44 add r0, pc, r0
 *   @0x21fc48 pop {r4, pc}
 *   @0x21fc4c subseq r5, r3, r8, lsl #14
 *   @0x21fc50 andseq r0, r1, r12, ror lr
 *
 * ══ §90/561 alutLoadMemoryFromFile  0x222718  size 60  15 条（0x222718..0x222754）
 * @func 0x222718 0x222754  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromFile
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222718 push {r4, r5, r6, r7, r8, lr}
 *   @0x22271c mov r7, r0
 *   @0x222720 mov r6, r1
 *   @0x222724 mov r5, r2
 *   @0x222728 mov r4, r3
 *   @0x22272c bl 0x2219a8 <_alutSanityCheck>
 *   @0x222730 cmp r0, #0
 *   @0x222734 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x222738 mov r0, r7
 *   @0x22273c bl 0x221ce0 <_alutInputStreamConstructFromFile>
 *   @0x222740 mov r1, r6
 *   @0x222744 mov r2, r5
 *   @0x222748 mov r3, r4
 *   @0x22274c pop {r4, r5, r6, r7, r8, lr}
 *   @0x222750 b 0x222664 <_alutLoadMemoryFromInputStream>
 *
 * ══ §91/561 _alutOutputStreamWriteInt32BE  0x2229b4  size 60  15 条（0x2229b4..0x2229f0）
 * @func 0x2229b4 0x2229f0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_222930
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x7×1 / 0x5×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2229b4 str lr, [sp, #-0x4]!
 *   @0x2229b8 sub sp, sp, #12
 *   @0x2229bc mov r3, r1
 *   @0x2229c0 mov r2, #4
 *   @0x2229c4 add r1, sp, r2
 *   @0x2229c8 asr lr, r3, #24
 *   @0x2229cc asr r12, r3, #16
 *   @0x2229d0 strb r3, [sp, #0x7]
 *   @0x2229d4 strb lr, [sp, #0x4]
 *   @0x2229d8 asr r3, r3, #8
 *   @0x2229dc strb r12, [sp, #0x5]
 *   @0x2229e0 strb r3, [sp, #0x6]
 *   @0x2229e4 bl 0x222930 <_alutOutputStreamGetLength+0xc>
 *   @0x2229e8 add sp, sp, #12
 *   @0x2229ec ldr pc, [sp], #4
 *
 * ══ §92/561 COggThread::Quit()  0x223bdc  size 60  15 条（0x223bdc..0x223c18）
 * @func 0x223bdc 0x223c18  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock() / COggThread::Unlock() / COggThread::WaitForThreadExit()
 * 字段偏移 top8: 0x802×1 / 0x801×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223bdc ldrb r3, [r0, #0x802]
 *   @0x223be0 push {r4, lr}
 *   @0x223be4 cmp r3, #0
 *   @0x223be8 mov r4, r0
 *   @0x223bec popeq {r4, pc}
 *   @0x223bf0 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223bf4 mov r3, #1
 *   @0x223bf8 mov r0, r4
 *   @0x223bfc strb r3, [r4, #0x801]
 *   @0x223c00 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x223c04 mov r0, r4
 *   @0x223c08 bl 0x223838 <_ZN10COggThread17WaitForThreadExitEv>
 *   @0x223c0c mov r0, r4
 *   @0x223c10 pop {r4, lr}
 *   @0x223c14 b 0x223890 <_ZN10COggThread7CleanUpEv>
 *
 * ══ §93/561 COggAudio::Seek_Sound(int, float)  0x226434  size 60  15 条（0x226434..0x226470）
 * @func 0x226434 0x226470  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::GetThreadForChannel(int, int&) / COggThread::Seek_Sound(int, float)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226434 push {r4, lr}
 *   @0x226438 sub sp, sp, #8
 *   @0x22643c add r3, sp, #8
 *   @0x226440 mov r12, #0
 *   @0x226444 mov r4, r2
 *   @0x226448 str r12, [r3, #-0x4]!
 *   @0x22644c mov r2, r3
 *   @0x226450 bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi>
 *   @0x226454 cmp r0, #0
 *   @0x226458 beq 0x226468 <_ZN9COggAudio10Seek_SoundEif+0x34>
 *   @0x22645c mov r2, r4
 *   @0x226460 ldr r1, [sp, #0x4]
 *   @0x226464 bl 0x223ba4 <_ZN10COggThread10Seek_SoundEif>
 *   @0x226468 add sp, sp, #8
 *   @0x22646c pop {r4, pc}
 *
 * ══ §94/561 ogg_stream_packetin  0x2349c8  size 60  15 条（0x2349c8..0x234a04）
 * @func 0x2349c8 0x234a04  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_iovecin
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2349c8 mov r12, r1
 *   @0x2349cc ldr r3, [r1, #0xc]
 *   @0x2349d0 push {r4, r5, lr}
 *   @0x2349d4 sub sp, sp, #20
 *   @0x2349d8 ldrd r4, r5, [r12, #16]
 *   @0x2349dc mov r2, #1
 *   @0x2349e0 ldr lr, [r12]
 *   @0x2349e4 add r1, sp, #8
 *   @0x2349e8 ldr r12, [r12, #0x4]
 *   @0x2349ec strd r4, r5, [sp]
 *   @0x2349f0 str lr, [sp, #0x8]
 *   @0x2349f4 str r12, [sp, #0xc]
 *   @0x2349f8 bl 0x234778 <ogg_stream_iovecin>
 *   @0x2349fc add sp, sp, #20
 *   @0x234a00 pop {r4, r5, pc}
 *
 * ══ §95/561 CPhysicsWorld::SetTraceMsg(char*)  0x237bbc  size 60  15 条（0x237bbc..0x237bf8）
 * @func 0x237bbc 0x237bf8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237bbc ldr r3, [pc, #0x28]
 *   @0x237bc0 ldr r2, [pc, #0x28]
 *   @0x237bc4 ldr r3, [pc, r3]
 *   @0x237bc8 ldr r2, [pc, r2]
 *   @0x237bcc ldr r3, [r3]
 *   @0x237bd0 cmp r3, r2
 *   @0x237bd4 bxne lr
 *   @0x237bd8 ldr r3, [pc, #0x14]
 *   @0x237bdc mov r1, r0
 *   @0x237be0 movw r2, #0x1ff
 *   @0x237be4 ldr r0, [pc, r3]
 *   @0x237be8 b 0xb6568 <strncpy@plt>
 *   @0x237bec andseq r9, r11, r4, lsl #18
 *   @0x237bf0 andseq r9, r11, r4, lsl #18
 *   @0x237bf4 andseq r9, r11, r0, ror #17
 *
 * ══ §96/561 CPhysicsWorld::GetParticleGroupX(int)  0x23a800  size 60  15 条（0x23a800..0x23a83c）
 * @func 0x23a800 0x23a83c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetPosition() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a800 push {r4, lr}
 *   @0x23a804 mov r4, r0
 *   @0x23a808 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a80c cmp r0, #0
 *   @0x23a810 beq 0x23a82c <_ZN13CPhysicsWorld17GetParticleGroupXEi+0x2c>
 *   @0x23a814 bl 0x2d461c <_ZNK15b2ParticleGroup11GetPositionEv>
 *   @0x23a818 vldr s15, [r4, #96]
 *   @0x23a81c vldr s14, [r0]
 *   @0x23a820 vdiv.f32 s15, s14, s15
 *   @0x23a824 vmov r0, s15
 *   @0x23a828 pop {r4, pc}
 *   @0x23a82c vldr s15, [pc, #4]
 *   @0x23a830 vmov r0, s15
 *   @0x23a834 pop {r4, pc}
 *   @0x23a838 andeq r0, r0, r0
 *
 * ══ §97/561 CPhysicsWorld::GetParticleGroupY(int)  0x23a83c  size 60  15 条（0x23a83c..0x23a878）
 * @func 0x23a83c 0x23a878  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2ParticleGroup::GetPosition() const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a83c push {r4, lr}
 *   @0x23a840 mov r4, r0
 *   @0x23a844 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a848 cmp r0, #0
 *   @0x23a84c beq 0x23a868 <_ZN13CPhysicsWorld17GetParticleGroupYEi+0x2c>
 *   @0x23a850 bl 0x2d461c <_ZNK15b2ParticleGroup11GetPositionEv>
 *   @0x23a854 vldr s15, [r4, #96]
 *   @0x23a858 vldr s14, [r0, #4]
 *   @0x23a85c vdiv.f32 s15, s14, s15
 *   @0x23a860 vmov r0, s15
 *   @0x23a864 pop {r4, pc}
 *   @0x23a868 vldr s15, [pc, #4]
 *   @0x23a86c vmov r0, s15
 *   @0x23a870 pop {r4, pc}
 *   @0x23a874 andeq r0, r0, r0
 *
 * ══ §98/561 F_JSForInIteratorDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c7e0  size 60  15 条（0x23c7e0..0x23c81c）
 * @func 0x23c7e0 0x23c81c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c7e0 push {r4, lr}
 *   @0x23c7e4 ldr r4, [sp, #0x8]
 *   @0x23c7e8 ldr r3, [r4, #0xc]
 *   @0x23c7ec bic r3, r3, #-16777216
 *   @0x23c7f0 cmp r3, #5
 *   @0x23c7f4 popeq {r4, pc}
 *   @0x23c7f8 cmp r3, #14
 *   @0x23c7fc beq 0x23c80c <_Z23F_JSForInIteratorDeleteR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x23c800 ldr r0, [pc, #0x10]
 *   @0x23c804 add r0, pc, r0
 *   @0x23c808 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x23c80c ldr r0, [r4]
 *   @0x23c810 pop {r4, lr}
 *   @0x23c814 b 0x27d1d0 <_ZdlPv>
 *   @0x23c818 andseq r8, r1, r0, asr r11
 *
 * ══ §99/561 DayWithinYear(double)  0x244c28  size 60  15 条（0x244c28..0x244c64）
 * @func 0x244c28 0x244c64  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YearFromTime(double) / DayFromYear(double) / Day(double)
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244c28 push {r3, r4, r5, lr}
 *   @0x244c2c vpush {d8}
 *   @0x244c30 mov r4, r0
 *   @0x244c34 mov r5, r1
 *   @0x244c38 bl 0x244b90 <_Z12YearFromTimed>
 *   @0x244c3c bl 0x244aa8 <_Z11DayFromYeard>
 *   @0x244c40 vmov d8, r0, r1
 *   @0x244c44 mov r0, r4
 *   @0x244c48 mov r1, r5
 *   @0x244c4c bl 0x2449d8 <_Z3Dayd>
 *   @0x244c50 vmov d7, r0, r1
 *   @0x244c54 vsub.f64 d7, d7, d8
 *   @0x244c58 vpop {d8}
 *   @0x244c5c vmov r0, r1, d7
 *   @0x244c60 pop {r3, r4, r5, pc}
 *
 * ══ §100/561 pcre_get_named_substring  0x25f670  size 60  15 条（0x25f670..0x25f6ac）
 * @func 0x25f670 0x25f6ac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_25f37c
 * 字段偏移 top8: 0x18×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f670 push {r4, r5, r6, r7, r8, lr}
 *   @0x25f674 mov r6, r1
 *   @0x25f678 ldr r1, [sp, #0x18]
 *   @0x25f67c mov r4, r3
 *   @0x25f680 mov r5, r2
 *   @0x25f684 ldr r7, [sp, #0x1c]
 *   @0x25f688 bl 0x25f37c <pcre_get_stringtable_entries+0x160>
 *   @0x25f68c subs r3, r0, #0
 *   @0x25f690 pople {r4, r5, r6, r7, r8, pc}
 *   @0x25f694 str r7, [sp, #0x18]
 *   @0x25f698 mov r0, r6
 *   @0x25f69c mov r1, r5
 *   @0x25f6a0 mov r2, r4
 *   @0x25f6a4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x25f6a8 b 0x25f5e8 <pcre_get_substring>
 *
 * ══ §101/561 _spTimeline_init  0x281328  size 60  15 条（0x281328..0x281364）
 * @func 0x281328 0x281364  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281328 push {r4, r5, r6, lr}
 *   @0x28132c mov r6, r2
 *   @0x281330 ldr r2, [pc, #0x28]
 *   @0x281334 mov r4, r0
 *   @0x281338 str r1, [r0]
 *   @0x28133c mov r5, r3
 *   @0x281340 mov r0, #1
 *   @0x281344 mov r1, #8
 *   @0x281348 add r2, pc, r2
 *   @0x28134c mov r3, #93
 *   @0x281350 bl 0x285c4c <_calloc>
 *   @0x281354 str r0, [r4, #0x4]
 *   @0x281358 stm r0, {r5, r6}
 *   @0x28135c pop {r4, r5, r6, pc}
 *   @0x281360 andeq r6, sp, r8, lsl #2
 *
 * ══ §102/561 spBone_getWorldRotationX  0x285410  size 60  15 条（0x285410..0x28544c）
 * @func 0x285410 0x28544c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70
 * 字段偏移 top8: 无
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285410 vldr s14, [r0, #64]
 *   @0x285414 vcvt.f64.f32 d6, s14
 *   @0x285418 vldr s15, [r0, #52]
 *   @0x28541c push {r3, lr}
 *   @0x285420 vmov r0, r1, d6
 *   @0x285424 vcvt.f64.f32 d6, s15
 *   @0x285428 vmov r2, r3, d6
 *   @0x28542c bl 0xb6c70 <atan2@plt>
 *   @0x285430 vldr s15, [pc, #16]
 *   @0x285434 vmov d6, r0, r1
 *   @0x285438 vcvt.f32.f64 s14, d6
 *   @0x28543c vmul.f32 s15, s14, s15
 *   @0x285440 vmov r0, s15
 *   @0x285444 pop {r3, pc}
 *   @0x285448 rsbmi r2, r5, #224, #28
 *
 * ══ §103/561 spBone_getWorldRotationY  0x28544c  size 60  15 条（0x28544c..0x285488）
 * @func 0x28544c 0x285488  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70
 * 字段偏移 top8: 无
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28544c vldr s14, [r0, #68]
 *   @0x285450 vcvt.f64.f32 d6, s14
 *   @0x285454 vldr s15, [r0, #56]
 *   @0x285458 push {r3, lr}
 *   @0x28545c vmov r0, r1, d6
 *   @0x285460 vcvt.f64.f32 d6, s15
 *   @0x285464 vmov r2, r3, d6
 *   @0x285468 bl 0xb6c70 <atan2@plt>
 *   @0x28546c vldr s15, [pc, #16]
 *   @0x285470 vmov d6, r0, r1
 *   @0x285474 vcvt.f32.f64 s14, d6
 *   @0x285478 vmul.f32 s15, s14, s15
 *   @0x28547c vmov r0, s15
 *   @0x285480 pop {r3, pc}
 *   @0x285484 rsbmi r2, r5, #224, #28
 *
 * ══ §104/561 spSkin_dispose  0x28ec9c  size 60  15 条（0x28ec9c..0x28ecd8）
 * @func 0x28ec9c 0x28ecd8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Entry_dispose / _free
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ec9c push {r3, r4, r5, lr}
 *   @0x28eca0 mov r5, r0
 *   @0x28eca4 ldr r0, [r0, #0x4]
 *   @0x28eca8 cmp r0, #0
 *   @0x28ecac beq 0x28ecc4 <spSkin_dispose+0x28>
 *   @0x28ecb0 ldr r4, [r0, #0xc]
 *   @0x28ecb4 bl 0x28ec20 <_Entry_dispose>
 *   @0x28ecb8 cmp r4, #0
 *   @0x28ecbc mov r0, r4
 *   @0x28ecc0 bne 0x28ecb0 <spSkin_dispose+0x14>
 *   @0x28ecc4 ldr r0, [r5]
 *   @0x28ecc8 bl 0x285c80 <_free>
 *   @0x28eccc mov r0, r5
 *   @0x28ecd0 pop {r3, r4, r5, lr}
 *   @0x28ecd4 b 0x285c80 <_free>
 *
 * ══ §105/561 CProfiler::BeginStep()  0x2a0870  size 60  15 条（0x2a0870..0x2a08ac）
 * @func 0x2a0870 0x2a08ac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0870 push {r4, r5, r6, r7, r8, lr}
 *   @0x2a0874 mov r8, r0
 *   @0x2a0878 bl 0x215148 <Timing_Time>
 *   @0x2a087c ldrd r4, r5, [r8]
 *   @0x2a0880 mov r6, #0
 *   @0x2a0884 mov r7, #0
 *   @0x2a0888 mov r2, #21
 *   @0x2a088c strd r6, r7, [r8, #104]
 *   @0x2a0890 subs r4, r0, r4
 *   @0x2a0894 sbc r5, r1, r5
 *   @0x2a0898 mov r0, r8
 *   @0x2a089c strd r4, r5, [r8, #88]
 *   @0x2a08a0 mov r1, #6
 *   @0x2a08a4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2a08a8 b 0x2a0738 <_ZN9CProfiler4PushEii>
 *
 * ══ §106/561 b2EdgeShape::ComputeMass(b2MassData*, float) const  0x2c5204  size 60  15 条（0x2c5204..0x2c5240）
 * @func 0x2c5204 0x2c5240  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5204 vldr s11, [r0, #16]
 *   @0x2c5208 vldr s14, [r0, #24]
 *   @0x2c520c vldr s12, [r0, #12]
 *   @0x2c5210 vldr s13, [r0, #20]
 *   @0x2c5214 vmov.f32 s15, #5.000000e-01
 *   @0x2c5218 mov r3, #0
 *   @0x2c521c str r3, [r1]
 *   @0x2c5220 str r3, [r1, #0xc]
 *   @0x2c5224 vadd.f32 s14, s11, s14
 *   @0x2c5228 vadd.f32 s13, s12, s13
 *   @0x2c522c vmul.f32 s14, s14, s15
 *   @0x2c5230 vmul.f32 s15, s13, s15
 *   @0x2c5234 vstr s14, [r1, #8]
 *   @0x2c5238 vstr s15, [r1, #4]
 *   @0x2c523c bx lr
 *
 * ══ §107/561 b2PairLessThan(b2Pair const&, b2Pair const&)  0x2c77d4  size 60  15 条（0x2c77d4..0x2c7810）
 * @func 0x2c77d4 0x2c7810  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PairLessThan(b2Pair const&, b2Pair const&)+0x34
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c77d4 ldr r2, [r0]
 *   @0x2c77d8 ldr r3, [r1]
 *   @0x2c77dc cmp r2, r3
 *   @0x2c77e0 blt 0x2c7808 <_Z14b2PairLessThanRK6b2PairS1_+0x34>
 *   @0x2c77e4 beq 0x2c77f0 <_Z14b2PairLessThanRK6b2PairS1_+0x1c>
 *   @0x2c77e8 mov r0, #0
 *   @0x2c77ec bx lr
 *   @0x2c77f0 ldr r0, [r0, #0x4]
 *   @0x2c77f4 ldr r3, [r1, #0x4]
 *   @0x2c77f8 cmp r0, r3
 *   @0x2c77fc movge r0, #0
 *   @0x2c7800 movlt r0, #1
 *   @0x2c7804 bx lr
 *   @0x2c7808 mov r0, #1
 *   @0x2c780c bx lr
 *
 * ══ §108/561 b2EdgeAndCircleContact::b2EdgeAndCircleContact(b2Fixture*, b2Fixture*)  0x2cc520  size 60  15 条（0x2cc520..0x2cc55c）
 * @func 0x2cc520 0x2cc55c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc520 push {r4, lr}
 *   @0x2cc524 sub sp, sp, #8
 *   @0x2cc528 mov r3, r2
 *   @0x2cc52c mov r2, #0
 *   @0x2cc530 str r2, [sp]
 *   @0x2cc534 mov r4, r0
 *   @0x2cc538 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2cc53c ldr r3, [pc, #0x14]
 *   @0x2cc540 mov r0, r4
 *   @0x2cc544 ldr r3, [pc, r3]
 *   @0x2cc548 add r3, r3, #8
 *   @0x2cc54c str r3, [r4]
 *   @0x2cc550 add sp, sp, #8
 *   @0x2cc554 pop {r4, pc}
 *   @0x2cc558 andseq r5, r2, r0, lsl #12
 *
 * ══ §109/561 b2EdgeAndPolygonContact::b2EdgeAndPolygonContact(b2Fixture*, b2Fixture*)  0x2cc630  size 60  15 条（0x2cc630..0x2cc66c）
 * @func 0x2cc630 0x2cc66c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc630 push {r4, lr}
 *   @0x2cc634 sub sp, sp, #8
 *   @0x2cc638 mov r3, r2
 *   @0x2cc63c mov r2, #0
 *   @0x2cc640 str r2, [sp]
 *   @0x2cc644 mov r4, r0
 *   @0x2cc648 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2cc64c ldr r3, [pc, #0x14]
 *   @0x2cc650 mov r0, r4
 *   @0x2cc654 ldr r3, [pc, r3]
 *   @0x2cc658 add r3, r3, #8
 *   @0x2cc65c str r3, [r4]
 *   @0x2cc660 add sp, sp, #8
 *   @0x2cc664 pop {r4, pc}
 *   @0x2cc668 ldrsheq r5, [r2], -r4
 *
 * ══ §110/561 b2PolygonAndCircleContact::b2PolygonAndCircleContact(b2Fixture*, b2Fixture*)  0x2cc740  size 60  15 条（0x2cc740..0x2cc77c）
 * @func 0x2cc740 0x2cc77c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc740 push {r4, lr}
 *   @0x2cc744 sub sp, sp, #8
 *   @0x2cc748 mov r3, r2
 *   @0x2cc74c mov r2, #0
 *   @0x2cc750 str r2, [sp]
 *   @0x2cc754 mov r4, r0
 *   @0x2cc758 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2cc75c ldr r3, [pc, #0x14]
 *   @0x2cc760 mov r0, r4
 *   @0x2cc764 ldr r3, [pc, r3]
 *   @0x2cc768 add r3, r3, #8
 *   @0x2cc76c str r3, [r4]
 *   @0x2cc770 add sp, sp, #8
 *   @0x2cc774 pop {r4, pc}
 *   @0x2cc778 andseq r5, r2, r8, ror #7
 *
 * ══ §111/561 b2PolygonContact::b2PolygonContact(b2Fixture*, b2Fixture*)  0x2cc850  size 60  15 条（0x2cc850..0x2cc88c）
 * @func 0x2cc850 0x2cc88c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc850 push {r4, lr}
 *   @0x2cc854 sub sp, sp, #8
 *   @0x2cc858 mov r3, r2
 *   @0x2cc85c mov r2, #0
 *   @0x2cc860 str r2, [sp]
 *   @0x2cc864 mov r4, r0
 *   @0x2cc868 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2cc86c ldr r3, [pc, #0x14]
 *   @0x2cc870 mov r0, r4
 *   @0x2cc874 ldr r3, [pc, r3]
 *   @0x2cc878 add r3, r3, #8
 *   @0x2cc87c str r3, [r4]
 *   @0x2cc880 add sp, sp, #8
 *   @0x2cc884 pop {r4, pc}
 *   @0x2cc888 ldrsbeq r5, [r2], -r12
 *
 * ══ §112/561 b2ParticleSystem::SetParticleFlagsBuffer(unsigned int*, int)  0x2d992c  size 60  15 条（0x2d992c..0x2d9968）
 * @func 0x2d992c 0x2d9968  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x34×2 / 0x30×2 / 0x28×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d992c ldr r3, [r0, #0x34]
 *   @0x2d9930 push {r4, r5, r6, lr}
 *   @0x2d9934 cmp r3, #0
 *   @0x2d9938 mov r4, r0
 *   @0x2d993c mov r6, r1
 *   @0x2d9940 mov r5, r2
 *   @0x2d9944 bne 0x2d995c <_ZN16b2ParticleSystem22SetParticleFlagsBufferEPji+0x30>
 *   @0x2d9948 ldr r2, [r0, #0x28]
 *   @0x2d994c ldr r1, [r4, #0x30]
 *   @0x2d9950 ldr r0, [r0, #0xd4]
 *   @0x2d9954 lsl r2, r2, #2
 *   @0x2d9958 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d995c str r6, [r4, #0x30]
 *   @0x2d9960 str r5, [r4, #0x34]
 *   @0x2d9964 pop {r4, r5, r6, pc}
 *
 * ══ §113/561 b2ParticleSystem::SetParticlePositionBuffer(b2Vec2*, int)  0x2d9968  size 60  15 条（0x2d9968..0x2d99a4）
 * @func 0x2d9968 0x2d99a4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x3c×2 / 0x38×2 / 0x28×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9968 ldr r3, [r0, #0x3c]
 *   @0x2d996c push {r4, r5, r6, lr}
 *   @0x2d9970 cmp r3, #0
 *   @0x2d9974 mov r4, r0
 *   @0x2d9978 mov r6, r1
 *   @0x2d997c mov r5, r2
 *   @0x2d9980 bne 0x2d9998 <_ZN16b2ParticleSystem25SetParticlePositionBufferEP6b2Vec2i+0x30>
 *   @0x2d9984 ldr r2, [r0, #0x28]
 *   @0x2d9988 ldr r1, [r4, #0x38]
 *   @0x2d998c ldr r0, [r0, #0xd4]
 *   @0x2d9990 lsl r2, r2, #3
 *   @0x2d9994 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d9998 str r6, [r4, #0x38]
 *   @0x2d999c str r5, [r4, #0x3c]
 *   @0x2d99a0 pop {r4, r5, r6, pc}
 *
 * ══ §114/561 b2ParticleSystem::SetParticleVelocityBuffer(b2Vec2*, int)  0x2d99a4  size 60  15 条（0x2d99a4..0x2d99e0）
 * @func 0x2d99a4 0x2d99e0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x44×2 / 0x40×2 / 0x28×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d99a4 ldr r3, [r0, #0x44]
 *   @0x2d99a8 push {r4, r5, r6, lr}
 *   @0x2d99ac cmp r3, #0
 *   @0x2d99b0 mov r4, r0
 *   @0x2d99b4 mov r6, r1
 *   @0x2d99b8 mov r5, r2
 *   @0x2d99bc bne 0x2d99d4 <_ZN16b2ParticleSystem25SetParticleVelocityBufferEP6b2Vec2i+0x30>
 *   @0x2d99c0 ldr r2, [r0, #0x28]
 *   @0x2d99c4 ldr r1, [r4, #0x40]
 *   @0x2d99c8 ldr r0, [r0, #0xd4]
 *   @0x2d99cc lsl r2, r2, #3
 *   @0x2d99d0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d99d4 str r6, [r4, #0x40]
 *   @0x2d99d8 str r5, [r4, #0x44]
 *   @0x2d99dc pop {r4, r5, r6, pc}
 *
 * ══ §115/561 b2ParticleSystem::SetParticleColorBuffer(b2ParticleColor*, int)  0x2d99e0  size 60  15 条（0x2d99e0..0x2d9a1c）
 * @func 0x2d99e0 0x2d9a1c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x58×2 / 0x54×2 / 0x28×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d99e0 ldr r3, [r0, #0x58]
 *   @0x2d99e4 push {r4, r5, r6, lr}
 *   @0x2d99e8 cmp r3, #0
 *   @0x2d99ec mov r4, r0
 *   @0x2d99f0 mov r6, r1
 *   @0x2d99f4 mov r5, r2
 *   @0x2d99f8 bne 0x2d9a10 <_ZN16b2ParticleSystem22SetParticleColorBufferEP15b2ParticleColori+0x30>
 *   @0x2d99fc ldr r2, [r0, #0x28]
 *   @0x2d9a00 ldr r1, [r4, #0x54]
 *   @0x2d9a04 ldr r0, [r0, #0xd4]
 *   @0x2d9a08 lsl r2, r2, #2
 *   @0x2d9a0c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d9a10 str r6, [r4, #0x54]
 *   @0x2d9a14 str r5, [r4, #0x58]
 *   @0x2d9a18 pop {r4, r5, r6, pc}
 *
 * ══ §116/561 b2ParticleSystem::SetParticleUserDataBuffer(void**, int)  0x2d9a24  size 60  15 条（0x2d9a24..0x2d9a60）
 * @func 0x2d9a24 0x2d9a60  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x64×2 / 0x60×2 / 0x28×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9a24 ldr r3, [r0, #0x64]
 *   @0x2d9a28 push {r4, r5, r6, lr}
 *   @0x2d9a2c cmp r3, #0
 *   @0x2d9a30 mov r4, r0
 *   @0x2d9a34 mov r6, r1
 *   @0x2d9a38 mov r5, r2
 *   @0x2d9a3c bne 0x2d9a54 <_ZN16b2ParticleSystem25SetParticleUserDataBufferEPPvi+0x30>
 *   @0x2d9a40 ldr r2, [r0, #0x28]
 *   @0x2d9a44 ldr r1, [r4, #0x60]
 *   @0x2d9a48 ldr r0, [r0, #0xd4]
 *   @0x2d9a4c lsl r2, r2, #2
 *   @0x2d9a50 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d9a54 str r6, [r4, #0x60]
 *   @0x2d9a58 str r5, [r4, #0x64]
 *   @0x2d9a5c pop {r4, r5, r6, pc}
 *
 * ══ §117/561 b2VoronoiDiagram::b2VoronoiDiagram(b2StackAllocator*, int)  0x2dbb2c  size 60  15 条（0x2dbb2c..0x2dbb68）
 * @func 0x2dbb2c 0x2dbb68  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Allocate(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dbb2c add r2, r2, r2, lsl #1
 *   @0x2dbb30 push {r4, lr}
 *   @0x2dbb34 mov r4, r0
 *   @0x2dbb38 str r1, [r4]
 *   @0x2dbb3c mov r0, r1
 *   @0x2dbb40 lsl r1, r2, #2
 *   @0x2dbb44 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2dbb48 mov r3, #0
 *   @0x2dbb4c str r3, [r4, #0x8]
 *   @0x2dbb50 str r3, [r4, #0xc]
 *   @0x2dbb54 str r3, [r4, #0x10]
 *   @0x2dbb58 str r3, [r4, #0x14]
 *   @0x2dbb5c str r0, [r4, #0x4]
 *   @0x2dbb60 mov r0, r4
 *   @0x2dbb64 pop {r4, pc}
 *
 * ══ §118/561 b2CircleContact::b2CircleContact(b2Fixture*, b2Fixture*)  0x2e2020  size 60  15 条（0x2e2020..0x2e205c）
 * @func 0x2e2020 0x2e205c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2020 push {r4, lr}
 *   @0x2e2024 sub sp, sp, #8
 *   @0x2e2028 mov r3, r2
 *   @0x2e202c mov r2, #0
 *   @0x2e2030 str r2, [sp]
 *   @0x2e2034 mov r4, r0
 *   @0x2e2038 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2e203c ldr r3, [pc, #0x14]
 *   @0x2e2040 mov r0, r4
 *   @0x2e2044 ldr r3, [pc, r3]
 *   @0x2e2048 add r3, r3, #8
 *   @0x2e204c str r3, [r4]
 *   @0x2e2050 add sp, sp, #8
 *   @0x2e2054 pop {r4, pc}
 *   @0x2e2058 andseq pc, r0, r4, ror #22
 *
 * ══ §119/561 FT_Get_CMap_Language_ID  0x2e5c84  size 60  15 条（0x2e5c84..0x2e5cc0）
 * @func 0x2e5c84 0x2e5cc0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x20×1 / 0x12×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5c84 push {r0, r1, r4, lr}
 *   @0x2e5c88 cbnz r0, 0x2e5c8e <FT_Get_CMap_Language_ID+0xa>
 *   @0x2e5c8c b 0x2e5cb6 <FT_Get_CMap_Language_ID+0x32>
 *   @0x2e5c90 cmp r3, #0x0
 *   @0x2e5c94 ldr r0, [r3, #0x60]
 *   @0x2e5c98 ldr r3, [r3, #0x20]
 *   @0x2e5c9c beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6>
 *   @0x2e5ca0 add r1, pc
 *   @0x2e5ca4 cmp r0, #0x0
 *   @0x2e5ca8 ldr r3, [r0]
 *   @0x2e5cac mov r0, r4
 *   @0x2e5cb0 cmp r0, #0x0
 *   @0x2e5cb4 ldr r0, [sp]
 *   @0x2e5cb8 pop {r4, pc}
 *   @0x2e5cbc ldrh r7, [r6, #0x12]
 *
 * ══ §120/561 FT_Get_CMap_Format  0x2e5cc0  size 60  15 条（0x2e5cc0..0x2e5cfc）
 * @func 0x2e5cc0 0x2e5cfc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5cc0 push {r0, r1, r4, lr}
 *   @0x2e5cc4 cbnz r0, 0x2e5ccc <FT_Get_CMap_Format+0xc>
 *   @0x2e5cc8 ldrsh r3, [r3], -pc
 *   @0x2e5ccc ldr r3, [r0]
 *   @0x2e5cd0 beq 0x2e5cc6 <FT_Get_CMap_Format+0x6>
 *   @0x2e5cd4 ldr r3, [r0]
 *   @0x2e5cd8 cmp r3, #0x0
 *   @0x2e5cdc ldr r1, [pc, #0x18]
 *   @0x2e5ce0 blx r3
 *   @0x2e5ce4 beq 0x2e5cc6 <FT_Get_CMap_Format+0x6>
 *   @0x2e5ce8 mov r1, sp
 *   @0x2e5cec blx r3
 *   @0x2e5cf0 bne 0x2e5cc6 <FT_Get_CMap_Format+0x6>
 *   @0x2e5cf4 add sp, #0x8
 *   @0x2e5cf8 ldrh r1, [r7, #0x10]
 *
 * ══ §121/561 FT_Set_Charmap  0x2e5cfc  size 60  15 条（0x2e5cfc..0x2e5d38）
 * @func 0x2e5cfc 0x2e5d38  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Get_CMap_Format
 * 字段偏移 top8: 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5cfc push {r4, r5, r6, lr}
 *   @0x2e5d00 mov r4, r0
 *   @0x2e5d04 ldr r6, [r0, #0x28]
 *   @0x2e5d08 cbz r1, 0x2e5d30 <FT_Set_Charmap+0x34>
 *   @0x2e5d0c bl 0x2e5cc0 <FT_Get_CMap_Format>
 *   @0x2e5d10 cmp r0, #0xe
 *   @0x2e5d14 ldr r3, [r4, #0x24]
 *   @0x2e5d18 addsmi r0, lr, #201326594
 *   @0x2e5d1c bhs 0x2e5d34 <FT_Set_Charmap+0x38>
 *   @0x2e5d20 adcmi r2, r10, #4, #22
 *   @0x2e5d24 bne 0x2e5d1a <FT_Set_Charmap+0x1e>
 *   @0x2e5d28 movs r0, #0x0
 *   @0x2e5d2c movs r0, #0x23
 *   @0x2e5d30 movs r0, #0x26
 *   @0x2e5d34 movs r0, #0x6
 *
 * ══ §122/561 anon_2e747e  0x2e747e  size 60  15 条（0x2e747e..0x2e74ba）
 * @func 0x2e747e 0x2e74ba  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e747e movwhs r11, #0x408a
 *   @0x2e7482 .word 0x91054614
 *   @0x2e7486 andeq lr, r3, #13312
 *   @0x2e748a movwls r10, #0x2902
 *   @0x2e748e .word 0xffa5f7ff
 *   @0x2e7492 stmdals r1, {r3, r5, r6, r8, r11, r12, sp, pc}
 *   @0x2e7496 strtmi r11, [r2], -r8, lsr #2
 *   @0x2e749a .word 0xf7ff4907
 *   @0x2e749e .word 0x4604fcbe
 *   @0x2e74a2 ldrbhs lr, [r1], #-0
 *   @0x2e74a6 .word 0x21009801
 *   @0x2e74aa .word 0xffd8f7ff
 *   @0x2e74ae strmi lr, [r4], -r0
 *   @0x2e74b2 andlt r4, r10, r0, lsr #12
 *   @0x2e74b6 .word 0x1607bd10
 *
 * ══ §123/561 ft_hash_str_init  0x2e82bc  size 60  15 条（0x2e82bc..0x2e82f8）
 * @func 0x2e82bc 0x2e82f8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e82bc push {r0, r1, r2, r3, r4, lr}
 *   @0x2e82c0 movs r3, #0xf1
 *   @0x2e82c4 stm.w r0, {r2, r3}
 *   @0x2e82c8 movs r2, #0x0
 *   @0x2e82cc ldr r0, [pc, #0x20]
 *   @0x2e82d0 add r0, pc
 *   @0x2e82d4 ldr r0, [pc, #0x1c]
 *   @0x2e82d8 str r0, [r4, #0x10]
 *   @0x2e82dc str r0, [sp, #0x4]
 *   @0x2e82e0 movs r1, #0x4
 *   @0x2e82e4 .word 0x6160fed4
 *   @0x2e82e8 ldr r0, [sp, #0xc]
 *   @0x2e82ec pop {r4, pc}
 *   @0x2e82f0 stm r6!, {r0, r5, r7}
 *   @0x2e82f4 .word 0xffffc945
 *
 * ══ §124/561 ft_hash_num_init  0x2e84b4  size 60  15 条（0x2e84b4..0x2e84f0）
 * @func 0x2e84b4 0x2e84f0  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e84b4 push {r0, r1, r2, r3, r4, lr}
 *   @0x2e84b8 movs r3, #0xf1
 *   @0x2e84bc stm.w r0, {r2, r3}
 *   @0x2e84c0 movs r2, #0x0
 *   @0x2e84c4 ldr r0, [pc, #0x20]
 *   @0x2e84c8 add r0, pc
 *   @0x2e84cc ldr r0, [pc, #0x1c]
 *   @0x2e84d0 str r0, [r4, #0x10]
 *   @0x2e84d4 str r0, [sp, #0x4]
 *   @0x2e84d8 movs r1, #0x4
 *   @0x2e84dc .word 0x6160fdd8
 *   @0x2e84e0 ldr r0, [sp, #0xc]
 *   @0x2e84e4 pop {r4, pc}
 *   @0x2e84e8 stm r4!, {r0, r1, r2, r3, r4, r5, r7}
 *   @0x2e84ec .word 0xffffc4db
 *
 * ══ §125/561 __gnu_uldivmod_helper  0x3195f4  size 60  15 条（0x3195f4..0x319630）
 * @func 0x3195f4 0x319630  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivdi3
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3195f4 push {r3, r4, r5, r6, r7, lr}
 *   @0x3195f8 mov r6, r2
 *   @0x3195fc mov r4, r0
 *   @0x319600 mov r5, r1
 *   @0x319604 mov r7, r3
 *   @0x319608 bl 0x31b698 <__udivdi3>
 *   @0x31960c ldr r12, [sp, #0x18]
 *   @0x319610 mul r7, r0, r7
 *   @0x319614 umull r2, r3, r0, r6
 *   @0x319618 mla r7, r6, r1, r7
 *   @0x31961c add r3, r7, r3
 *   @0x319620 subs r2, r4, r2
 *   @0x319624 sbc r3, r5, r3
 *   @0x319628 strd r2, r3, [r12]
 *   @0x31962c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §126/561 _zip_cdir_grow(zip_cdir*, int, zip_error*)  0x2a3b4e  size 58  15 条（0x2a3b4e..0x2a3b88）
 * @func 0x2a3b4e 0x2a3b88  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c28 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3b4e push {r4, r5, r6, lr}
 *   @0x2a3b52 ldr r3, [r0, #0x4]
 *   @0x2a3b56 mov r6, r2
 *   @0x2a3b5a bge 0x2a3b64 <_Z14_zip_cdir_growP8zip_cdiriP9zip_error+0x16>
 *   @0x2a3b5e movs r1, #0x14
 *   @0x2a3b62 b 0x2a3b76 <_Z14_zip_cdir_growP8zip_cdiriP9zip_error+0x28>
 *   @0x2a3b66 ldr r0, [r0]
 *   @0x2a3b6a blx 0xb6c28 <realloc@plt>
 *   @0x2a3b6e mov r2, r0
 *   @0x2a3b72 mov r0, r6
 *   @0x2a3b76 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3b7a mov.w r0, #0xffffffff
 *   @0x2a3b7e pop {r4, r5, r6, pc}
 *   @0x2a3b82 andhs r0, r0, r4, lsr #32
 *   @0x2a3b86 pop {r4, r5, r6, pc}
 *
 * ══ §127/561 png_info_destroy  0x2a5ebe  size 58  15 条（0x2a5ebe..0x2a5ef8）
 * @func 0x2a5ebe 0x2a5ef8  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5ebe push {r0, r1, r4, lr}
 *   @0x2a5ec2 .word 0x460433ff
 *   @0x2a5ec6 movw r2, #0x7fff
 *   @0x2a5eca str r1, [sp, #0x4]
 *   @0x2a5ece .word 0xf8d4fe78
 *   @0x2a5ed2 smlalbtlt r3, r11, r12, r2
 *   @0x2a5ed6 mov r0, r4
 *   @0x2a5eda .word 0xf00012d0
 *   @0x2a5ede movwhs pc, #0xf0e
 *   @0x2a5ee2 str.w r3, [r4, #0x2d0]
 *   @0x2a5ee6 str.w r3, [r4, #0x2cc]
 *   @0x2a5eea add r0, sp, #0x4
 *   @0x2a5eee .word 0xf7ff7190
 *   @0x2a5ef2 andlt pc, r2, r2, lsr #28
 *   @0x2a5ef6 pop {r4, pc}
 *
 * ══ §128/561 png_get_oFFs  0x2a69ce  size 58  15 条（0x2a69ce..0x2a6a08）
 * @func 0x2a69ce 0x2a6a08  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a69ce push {r4, lr}
 *   @0x2a69d2 cbz r0, 0x2a6a06 <png_get_oFFs+0x38>
 *   @0x2a69d6 ldr r0, [r1, #0x8]
 *   @0x2a69da andsle r7, r3, r0, lsl #1
 *   @0x2a69de cbz r2, 0x2a69fc <png_get_oFFs+0x2e>
 *   @0x2a69e2 cbz r4, 0x2a6a04 <png_get_oFFs+0x36>
 *   @0x2a69e6 str r0, [r2]
 *   @0x2a69ea cdpvs p0, #0x8, c7, c10, c0, #0x4
 *   @0x2a69ee str r2, [r3]
 *   @0x2a69f2 eorvs r3, r3, r12, rrx
 *   @0x2a69f6 pop {r4, pc}
 *   @0x2a69fa pop {r4, pc}
 *   @0x2a69fe pop {r4, pc}
 *   @0x2a6a02 pop {r4, pc}
 *   @0x2a6a06 pop {r4, pc}
 *
 * ══ §129/561 FT_Get_First_Char  0x2e59bc  size 58  15 条（0x2e59bc..0x2e59f6）
 * @func 0x2e59bc 0x2e59f6  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Get_Char_Index / FT_Get_Next_Char
 * 字段偏移 top8: 0x4×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e59bc push {r0, r1, r2, r4, r5, lr}
 *   @0x2e59c0 mov r4, r0
 *   @0x2e59c4 str r1, [sp, #0x4]
 *   @0x2e59c8 movs r0, #0x0
 *   @0x2e59cc ldr r3, [r0, #0x5c]
 *   @0x2e59d0 beq 0x2e59c8 <FT_Get_First_Char+0xc>
 *   @0x2e59d4 cmp r3, #0x0
 *   @0x2e59d8 bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x2e59dc mov r1, r0
 *   @0x2e59e0 cmp r0, #0x0
 *   @0x2e59e4 mov r0, r4
 *   @0x2e59e8 bl 0x2e597e <FT_Get_Next_Char>
 *   @0x2e59ec cbz r5, 0x2e59f2 <FT_Get_First_Char+0x36>
 *   @0x2e59f0 str r3, [r5]
 *   @0x2e59f4 pop {r4, r5, pc}
 *
 * ══ §130/561 ft_glyphslot_alloc_bitmap  0x2e79f0  size 58  15 条（0x2e79f0..0x2e7a2a）
 * @func 0x2e79f0 0x2e7a2a  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free
 * 字段偏移 top8: 0x4×2 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e79f0 push {r0, r1, r4, r5, r6, lr}
 *   @0x2e79f4 ldr r3, [r0, #0x4]
 *   @0x2e79f8 ldr r5, [r3, #0x64]
 *   @0x2e79fc ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^
 *   @0x2e7a00 lsls r1, r2, #0x1f
 *   @0x2e7a04 mov r0, r5
 *   @0x2e7a08 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7a0c movs r3, #0x0
 *   @0x2e7a10 b 0x2e7a18 <ft_glyphslot_alloc_bitmap+0x28>
 *   @0x2e7a14 subsvs r0, r10, r1, lsl #4
 *   @0x2e7a18 mov r0, r5
 *   @0x2e7a1c add r2, sp, #0x4
 *   @0x2e7a20 strvs pc, [r0, #0xb82]!
 *   @0x2e7a24 ldr r0, [sp, #0x4]
 *   @0x2e7a28 pop {r4, r5, r6, pc}
 *
 * ══ §131/561 ft_lzwstate_done  0x316f54  size 58  15 条（0x316f54..0x316f8e）
 * @func 0x316f54 0x316f8e  size 58  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×2 / ft_lzwstate_reset
 * 字段偏移 top8: 0x58×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316f54 push {r3, r4, r5, lr}
 *   @0x316f58 ldr.w r5, [r0, #0xa8]
 *   @0x316f5c bl 0x316e42 <ft_lzwstate_reset>
 *   @0x316f60 ldr r1, [r4, #0x58]
 *   @0x316f64 addsmi r0, r9, #100, #6
 *   @0x316f68 beq 0x316f74 <ft_lzwstate_done+0x20>
 *   @0x316f6c bl 0x2e7336 <ft_mem_free>
 *   @0x316f70 movs r3, #0x0
 *   @0x316f74 mov r0, r5
 *   @0x316f78 bl 0x2e7336 <ft_mem_free>
 *   @0x316f7c movs r1, #0x0
 *   @0x316f80 str r1, [r4, #0x4c]
 *   @0x316f84 movs r2, #0xac
 *   @0x316f88 .word 0xf0044038
 *   @0x316f8c ldrblt r11, [r8, #0xd9f]!
 *
 * ══ §132/561 Pos(char const*, char const*)  0xc46f0  size 56  14 条（0xc46f0..0xc4728）
 * @func 0xc46f0 0xc4728  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6604
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc46f0 cmp r0, #0
 *   @0xc46f4 cmpne r1, #0
 *   @0xc46f8 push {r4, lr}
 *   @0xc46fc mov r4, r1
 *   @0xc4700 beq 0xc4720 <_Z3PosPKcS0_+0x30>
 *   @0xc4704 mov r1, r0
 *   @0xc4708 mov r0, r4
 *   @0xc470c bl 0xb6604 <strstr@plt>
 *   @0xc4710 cmp r0, #0
 *   @0xc4714 rsbne r0, r4, r0
 *   @0xc4718 addne r0, r0, #1
 *   @0xc471c pop {r4, pc}
 *   @0xc4720 mov r0, #0
 *   @0xc4724 pop {r4, pc}
 *
 * ══ §133/561 YYGML_WithIteratorNext(SWithIterator*, YYObjectBase**, YYObjectBase**)  0xd81f8  size 56  14 条（0xd81f8..0xd8230）
 * @func 0xd81f8 0xd8230  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd81f8 ldr r3, [r0, #0x8]
 *   @0xd81fc cmp r3, #0
 *   @0xd8200 beq 0xd8228 <_Z22YYGML_WithIteratorNextP13SWithIteratorPP12YYObjectBaseS3_+0x30>
 *   @0xd8204 ldr r3, [r0, #0xc]
 *   @0xd8208 sub r2, r3, #4
 *   @0xd820c str r2, [r0, #0xc]
 *   @0xd8210 ldr r3, [r3, #-0x4]
 *   @0xd8214 cmp r3, #0
 *   @0xd8218 beq 0xd8228 <_Z22YYGML_WithIteratorNextP13SWithIteratorPP12YYObjectBaseS3_+0x30>
 *   @0xd821c mov r0, #1
 *   @0xd8220 str r3, [r1]
 *   @0xd8224 bx lr
 *   @0xd8228 mov r0, #0
 *   @0xd822c bx lr
 *
 * ══ §134/561 CExtensionPackage::CExtensionPackage()  0xf56c8  size 56  14 条（0xf56c8..0xf5700）
 * @func 0xf56c8 0xf5700  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionPackage::Clear()
 * 字段偏移 top8: 0x2c×1 / 0x14×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf56c8 ldr r2, [pc, #0x2c]
 *   @0xf56cc mov r3, #0
 *   @0xf56d0 push {r4, lr}
 *   @0xf56d4 ldr r2, [pc, r2]
 *   @0xf56d8 mov r4, r0
 *   @0xf56dc str r3, [r0, #0x14]
 *   @0xf56e0 str r3, [r0, #0x10]
 *   @0xf56e4 add r2, r2, #8
 *   @0xf56e8 str r3, [r0, #0x18]
 *   @0xf56ec str r2, [r0]
 *   @0xf56f0 bl 0xf563c <_ZN17CExtensionPackage5ClearEv>
 *   @0xf56f4 mov r0, r4
 *   @0xf56f8 pop {r4, pc}
 *   @0xf56fc eoreq r8, pc, r12, asr r7
 *
 * ══ §135/561 dsMapCreate  0x101818  size 56  14 条（0x101818..0x101850）
 * @func 0x101818 0x101850  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsMapCreate(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x-10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101818 str lr, [sp, #-0x4]!
 *   @0x10181c sub sp, sp, #28
 *   @0x101820 add r0, sp, #24
 *   @0x101824 mov r3, #0
 *   @0x101828 mov r1, r3
 *   @0x10182c str r3, [sp]
 *   @0x101830 mov r2, r3
 *   @0x101834 str r3, [r0, #-0x10]!
 *   @0x101838 bl 0x1000f4 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_>
 *   @0x10183c vldr d7, [sp, #8]
 *   @0x101840 vcvt.s32.f64 s15, d7
 *   @0x101844 vmov r0, s15
 *   @0x101848 add sp, sp, #28
 *   @0x10184c ldr pc, [sp], #4
 *
 * ══ §136/561 dsListCreate  0x101b9c  size 56  14 条（0x101b9c..0x101bd4）
 * @func 0x101b9c 0x101bd4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListCreate(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x-10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x101b9c str lr, [sp, #-0x4]!
 *   @0x101ba0 sub sp, sp, #28
 *   @0x101ba4 add r0, sp, #24
 *   @0x101ba8 mov r3, #0
 *   @0x101bac mov r1, r3
 *   @0x101bb0 str r3, [sp]
 *   @0x101bb4 mov r2, r3
 *   @0x101bb8 str r3, [r0, #-0x10]!
 *   @0x101bbc bl 0xfffc4 <_Z14F_DsListCreateR6RValueP9CInstanceS2_iPS_>
 *   @0x101bc0 vldr d7, [sp, #8]
 *   @0x101bc4 vcvt.s32.f64 s13, d7
 *   @0x101bc8 vmov r0, s13
 *   @0x101bcc add sp, sp, #28
 *   @0x101bd0 ldr pc, [sp], #4
 *
 * ══ §137/561 F_Abs(RValue&, CInstance*, CInstance*, int, RValue*)  0x10de34  size 56  14 条（0x10de34..0x10de6c）
 * @func 0x10de34 0x10de6c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10de34 push {r4, lr}
 *   @0x10de38 mov r3, #0
 *   @0x10de3c mov r4, r0
 *   @0x10de40 str r3, [r0, #0xc]
 *   @0x10de44 mov r1, r3
 *   @0x10de48 ldr r0, [sp, #0x8]
 *   @0x10de4c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10de50 vmov d7, r0, r1
 *   @0x10de54 vabs.f64 d7, d7
 *   @0x10de58 vmov r0, r1, d7
 *   @0x10de5c vmov r2, s14
 *   @0x10de60 mov r3, r1
 *   @0x10de64 stm r4, {r2, r3}
 *   @0x10de68 pop {r4, pc}
 *
 * ══ §138/561 F_Sqr(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ded0  size 56  14 条（0x10ded0..0x10df08）
 * @func 0x10ded0 0x10df08  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ded0 push {r4, lr}
 *   @0x10ded4 mov r3, #0
 *   @0x10ded8 mov r4, r0
 *   @0x10dedc str r3, [r0, #0xc]
 *   @0x10dee0 mov r1, r3
 *   @0x10dee4 ldr r0, [sp, #0x8]
 *   @0x10dee8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10deec vmov d6, r0, r1
 *   @0x10def0 vmul.f64 d6, d6, d6
 *   @0x10def4 vmov r0, r1, d6
 *   @0x10def8 vmov r2, s12
 *   @0x10defc mov r3, r1
 *   @0x10df00 stm r4, {r2, r3}
 *   @0x10df04 pop {r4, pc}
 *
 * ══ §139/561 F_RandomUseOldVersion(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e24c  size 56  14 条（0x10e24c..0x10e284）
 * @func 0x10e24c 0x10e284  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e24c push {r3, lr}
 *   @0x10e250 mov r3, #0
 *   @0x10e254 ldr r12, [sp, #0x8]
 *   @0x10e258 mov r1, r3
 *   @0x10e25c str r3, [r0, #0xc]
 *   @0x10e260 str r3, [r0]
 *   @0x10e264 str r3, [r0, #0x4]
 *   @0x10e268 mov r0, r12
 *   @0x10e26c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10e270 pop {r3, lr}
 *   @0x10e274 cmp r0, #0
 *   @0x10e278 movle r0, #0
 *   @0x10e27c movgt r0, #1
 *   @0x10e280 b 0xc44ac <_Z15ChangeToOldPolyb>
 *
 * ══ §140/561 F_AnsiChar(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ede8  size 56  14 条（0x10ede8..0x10ee20）
 * @func 0x10ede8 0x10ee20  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x5×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ede8 push {r4, lr}
 *   @0x10edec sub sp, sp, #8
 *   @0x10edf0 mov r4, r0
 *   @0x10edf4 mov r1, #0
 *   @0x10edf8 ldr r0, [sp, #0x10]
 *   @0x10edfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10ee00 add r1, sp, #4
 *   @0x10ee04 mov r3, #0
 *   @0x10ee08 strb r3, [sp, #0x5]
 *   @0x10ee0c strb r0, [sp, #0x4]
 *   @0x10ee10 mov r0, r4
 *   @0x10ee14 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x10ee18 add sp, sp, #8
 *   @0x10ee1c pop {r4, pc}
 *
 * ══ §141/561 F_DateDateOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x114774  size 56  14 条（0x114774..0x1147ac）
 * @func 0x114774 0x1147ac  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114774 push {r4, lr}
 *   @0x114778 mov r3, #0
 *   @0x11477c mov r1, r3
 *   @0x114780 str r3, [r0, #0xc]
 *   @0x114784 mov r4, r0
 *   @0x114788 ldr r0, [sp, #0x8]
 *   @0x11478c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114790 vmov s15, r0
 *   @0x114794 vcvt.f64.s32 d7, s15
 *   @0x114798 vmov r0, r1, d7
 *   @0x11479c vmov r2, s14
 *   @0x1147a0 mov r3, r1
 *   @0x1147a4 stm r4, {r2, r3}
 *   @0x1147a8 pop {r4, pc}
 *
 * ══ §142/561 F_SurfaceCreateEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b3f8  size 56  14 条（0x11b3f8..0x11b430）
 * @func 0x11b3f8 0x11b430  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x24×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b3f8 push {r4, lr}
 *   @0x11b3fc mov r4, r0
 *   @0x11b400 ldr r0, [pc, #0x24]
 *   @0x11b404 mov r1, #0
 *   @0x11b408 add r0, pc, r0
 *   @0x11b40c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11b410 mov r2, #0
 *   @0x11b414 mov r3, r2
 *   @0x11b418 movt r2, #0xbff0
 *   @0x11b41c str r3, [r4, #0xc]
 *   @0x11b420 str r2, [r4, #0x4]
 *   @0x11b424 str r3, [r4]
 *   @0x11b428 pop {r4, pc}
 *   @0x11b42c eoreq lr, r1, r8, lsl #23
 *
 * ══ §143/561 YYGML_draw_sprite(CInstance*, int, int, float, float)  0x12313c  size 56  14 条（0x12313c..0x123174）
 * @func 0x12313c 0x123174  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Data(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12313c push {r4, r5, r6, lr}
 *   @0x123140 subs r4, r2, #0
 *   @0x123144 vldrlt s15, [r0, #144]
 *   @0x123148 ldr r5, [sp, #0x10]
 *   @0x12314c mov r6, r3
 *   @0x123150 vcvtlt.s32.f32 s15, s15
 *   @0x123154 mov r0, r1
 *   @0x123158 vmovlt r4, s15
 *   @0x12315c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x123160 mov r2, r6
 *   @0x123164 mov r3, r5
 *   @0x123168 mov r1, r4
 *   @0x12316c pop {r4, r5, r6, lr}
 *   @0x123170 b 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff>
 *
 * ══ §144/561 F_HighscoreName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12692c  size 56  14 条（0x12692c..0x126964）
 * @func 0x12692c 0x126964  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / HighScore_Name(char const*&, int) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12692c push {r4, lr}
 *   @0x126930 sub sp, sp, #8
 *   @0x126934 mov r4, r0
 *   @0x126938 mov r1, #0
 *   @0x12693c ldr r0, [sp, #0x10]
 *   @0x126940 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126944 mov r1, r0
 *   @0x126948 add r0, sp, #4
 *   @0x12694c bl 0x1dc314 <_Z14HighScore_NameRPKci>
 *   @0x126950 mov r0, r4
 *   @0x126954 ldr r1, [sp, #0x4]
 *   @0x126958 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x12695c add sp, sp, #8
 *   @0x126960 pop {r4, pc}
 *
 * ══ §145/561 F_SoundDiscard(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f6bc  size 56  14 条（0x12f6bc..0x12f6f4）
 * @func 0x12f6bc 0x12f6f4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int)
 * 字段偏移 top8: 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f6bc push {r3, lr}
 *   @0x12f6c0 ldr r3, [pc, #0x28]
 *   @0x12f6c4 ldr r0, [sp, #0x8]
 *   @0x12f6c8 ldr r3, [pc, r3]
 *   @0x12f6cc ldrb r1, [r3]
 *   @0x12f6d0 cmp r1, #0
 *   @0x12f6d4 popne {r3, pc}
 *   @0x12f6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f6dc bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12f6e0 cmp r0, #0
 *   @0x12f6e4 popeq {r3, pc}
 *   @0x12f6e8 pop {r3, lr}
 *   @0x12f6ec b 0x215724 <_ZN6CSound7DiscardEv>
 *   @0x12f6f0 eoreq pc, r11, r8, ror #12
 *
 * ══ §146/561 F_SoundRestore(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f6f4  size 56  14 条（0x12f6f4..0x12f72c）
 * @func 0x12f6f4 0x12f72c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sound_Data(int)
 * 字段偏移 top8: 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f6f4 push {r3, lr}
 *   @0x12f6f8 ldr r3, [pc, #0x28]
 *   @0x12f6fc ldr r0, [sp, #0x8]
 *   @0x12f700 ldr r3, [pc, r3]
 *   @0x12f704 ldrb r1, [r3]
 *   @0x12f708 cmp r1, #0
 *   @0x12f70c popne {r3, pc}
 *   @0x12f710 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f714 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12f718 cmp r0, #0
 *   @0x12f71c popeq {r3, pc}
 *   @0x12f720 pop {r3, lr}
 *   @0x12f724 b 0x215540 <_ZN6CSound7RestoreEv>
 *   @0x12f728 eoreq pc, r11, r0, lsr r6
 *
 * ══ §147/561 F_FileFindClose(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ac28  size 56  14 条（0x13ac28..0x13ac60）
 * @func 0x13ac28 0x13ac60  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyFindData::Reset()
 * 字段偏移 top8: 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ac28 push {r4, lr}
 *   @0x13ac2c ldr r4, [pc, #0x24]
 *   @0x13ac30 ldr r4, [pc, r4]
 *   @0x13ac34 ldrb r3, [r4]
 *   @0x13ac38 cmp r3, #0
 *   @0x13ac3c beq 0x13ac4c <_Z15F_FileFindCloseR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x13ac40 ldr r0, [pc, #0x14]
 *   @0x13ac44 ldr r0, [pc, r0]
 *   @0x13ac48 bl 0x13aac0 <_ZN10yyFindData5ResetEv>
 *   @0x13ac4c mov r3, #0
 *   @0x13ac50 strb r3, [r4]
 *   @0x13ac54 pop {r4, pc}
 *   @0x13ac58 eoreq r4, r11, r4, asr r6
 *   @0x13ac5c eoreq r4, r11, r4, asr #12
 *
 * ══ §148/561 YYGML_action_set_gravity(CInstance*, float, float)  0x141574  size 56  14 条（0x141574..0x1415ac）
 * @func 0x141574 0x1415ac  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141574 ldr r3, [pc, #0x2c]
 *   @0x141578 vmov s14, r1
 *   @0x14157c vmov s15, r2
 *   @0x141580 ldr r3, [pc, r3]
 *   @0x141584 ldrb r3, [r3]
 *   @0x141588 cmp r3, #0
 *   @0x14158c vldrne s12, [r0, #216]
 *   @0x141590 vldrne s13, [r0, #220]
 *   @0x141594 vaddne.f32 s14, s12, s14
 *   @0x141598 vaddne.f32 s15, s13, s15
 *   @0x14159c vstr s14, [r0, #216]
 *   @0x1415a0 vstr s15, [r0, #220]
 *   @0x1415a4 bx lr
 *   @0x1415a8 .word 0x002ac5bc
 *
 * ══ §149/561 F_PhysicsFixtureSetPolygonShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x14baf4  size 56  14 条（0x14baf4..0x14bb2c）
 * @func 0x14baf4 0x14bb2c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14baf4 push {r3, lr}
 *   @0x14baf8 mov r1, #0
 *   @0x14bafc ldr r0, [sp, #0x8]
 *   @0x14bb00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bb04 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14bb08 subs r1, r0, #0
 *   @0x14bb0c beq 0x14bb18 <_Z31F_PhysicsFixtureSetPolygonShapeR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x14bb10 pop {r3, lr}
 *   @0x14bb14 b 0x2368f8 <_ZN15CPhysicsFixture15SetPolygonShapeEv>
 *   @0x14bb18 ldr r0, [pc, #0x8]
 *   @0x14bb1c pop {r3, lr}
 *   @0x14bb20 add r0, pc, r0
 *   @0x14bb24 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bb28 andseq r8, pc, r8, lsl #5
 *
 * ══ §150/561 F_YoYo_EnableAds(RValue&, CInstance*, CInstance*, int, RValue*)  0x156dd8  size 56  14 条（0x156dd8..0x156e10）
 * @func 0x156dd8 0x156e10  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156dd8 push {r3, r4, r5, lr}
 *   @0x156ddc mov r1, #0
 *   @0x156de0 ldr r4, [sp, #0x10]
 *   @0x156de4 mov r0, r4
 *   @0x156de8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156dec mov r1, #1
 *   @0x156df0 mov r5, r0
 *   @0x156df4 mov r0, r4
 *   @0x156df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156dfc mov r2, #0
 *   @0x156e00 mov r1, r0
 *   @0x156e04 mov r0, r5
 *   @0x156e08 pop {r3, r4, r5, lr}
 *   @0x156e0c b 0x15e390 <_Z15EnableAdServingiii>
 *
 * ══ §151/561 F_YoYo_DisableAds(RValue&, CInstance*, CInstance*, int, RValue*)  0x15936c  size 56  14 条（0x15936c..0x1593a4）
 * @func 0x15936c 0x1593a4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_YoYo_DisableAds(RValue&, CInstance*, CInstance*, int, RValue*)+0x2c
 * 字段偏移 top8: 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15936c push {r3, lr}
 *   @0x159370 mov r1, #0
 *   @0x159374 ldr r0, [sp, #0x8]
 *   @0x159378 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15937c cmp r0, #4
 *   @0x159380 bls 0x159398 <_Z17F_YoYo_DisableAdsR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x159384 ldr r0, [pc, #0x14]
 *   @0x159388 mov r1, #0
 *   @0x15938c pop {r3, lr}
 *   @0x159390 add r0, pc, r0
 *   @0x159394 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x159398 pop {r3, lr}
 *   @0x15939c b 0x15e3e8 <_Z16DisableAdServingi>
 *   @0x1593a0 andseq sp, lr, r8, lsl #14
 *
 * ══ §152/561 Cache_ReadInt32(unsigned char*, int*)  0x159b2c  size 56  14 条（0x159b2c..0x159b64）
 * @func 0x159b2c 0x159b64  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x2×1 / 0x1×1 / 0x3×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159b2c ldr r3, [r1]
 *   @0x159b30 str r4, [sp, #-0x4]!
 *   @0x159b34 add r4, r3, #4
 *   @0x159b38 ldrb r2, [r0, r3]!
 *   @0x159b3c ldrb r3, [r0, #0x2]
 *   @0x159b40 ldrb r12, [r0, #0x1]
 *   @0x159b44 ldrb r0, [r0, #0x3]
 *   @0x159b48 lsl r3, r3, #16
 *   @0x159b4c str r4, [r1]
 *   @0x159b50 orr r3, r3, r12, lsl #8
 *   @0x159b54 ldr r4, [sp], #4
 *   @0x159b58 orr r3, r3, r2
 *   @0x159b5c orr r0, r3, r0, lsl #24
 *   @0x159b60 bx lr
 *
 * ══ §153/561 UpdateCache(eCacheType, char const*, unsigned int)  0x159c88  size 56  14 条（0x159c88..0x159cc0）
 * @func 0x159c88 0x159cc0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Achievement_PlayerID() / anon_159b90
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159c88 push {r3, lr}
 *   @0x159c8c ldr r3, [pc, #0x28]
 *   @0x159c90 ldr r3, [pc, r3]
 *   @0x159c94 ldr r3, [r3]
 *   @0x159c98 cmp r3, #0
 *   @0x159c9c beq 0x159ca8 <_Z11UpdateCache10eCacheTypePKcj+0x20>
 *   @0x159ca0 mov r0, #0
 *   @0x159ca4 pop {r3, pc}
 *   @0x159ca8 bl 0x161210 <_Z20Achievement_PlayerIDv>
 *   @0x159cac cmp r0, #0
 *   @0x159cb0 beq 0x159ca0 <_Z11UpdateCache10eCacheTypePKcj+0x18>
 *   @0x159cb4 bl 0x159b90 <_Z16Cache_ReadStringPhPi+0x2c>
 *   @0x159cb8 b 0x159ca0 <_Z11UpdateCache10eCacheTypePKcj+0x18>
 *   @0x159cbc eoreq r5, r9, r4, lsr pc
 *
 * ══ §154/561 _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...)  0x15e0b0  size 56  14 条（0x15e0b0..0x15e0e8）
 * @func 0x15e0b0 0x15e0e8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x1d8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e0b0 push {r2, r3}
 *   @0x15e0b4 str lr, [sp, #-0x4]!
 *   @0x15e0b8 sub sp, sp, #12
 *   @0x15e0bc ldr lr, [r0]
 *   @0x15e0c0 add r12, sp, #20
 *   @0x15e0c4 ldr r2, [sp, #0x10]
 *   @0x15e0c8 mov r3, r12
 *   @0x15e0cc str r12, [sp, #0x4]
 *   @0x15e0d0 ldr r12, [lr, #0x1d8]
 *   @0x15e0d4 blx r12
 *   @0x15e0d8 add sp, sp, #12
 *   @0x15e0dc ldr lr, [sp], #4
 *   @0x15e0e0 add sp, sp, #8
 *   @0x15e0e4 bx lr
 *
 * ══ §155/561 DisplaySetUIVisibility(int)  0x15e2b8  size 56  14 条（0x15e2b8..0x15e2f0）
 * @func 0x15e2b8 0x15e2f0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e2b8 push {r4, lr}
 *   @0x15e2bc mov r4, r0
 *   @0x15e2c0 bl 0x290274 <getJNIEnv>
 *   @0x15e2c4 ldr r1, [pc, #0x1c]
 *   @0x15e2c8 mov r3, r4
 *   @0x15e2cc ldr r2, [pc, #0x18]
 *   @0x15e2d0 ldr r1, [pc, r1]
 *   @0x15e2d4 ldr r2, [pc, r2]
 *   @0x15e2d8 ldr r1, [r1]
 *   @0x15e2dc ldr r2, [r2]
 *   @0x15e2e0 pop {r4, lr}
 *   @0x15e2e4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e2e8 .word 0x0028f6d4
 *   @0x15e2ec mlaeq r9, r12, r11, r1
 *
 * ══ §156/561 AdDisplayWidth(int)  0x15e4c8  size 56  14 条（0x15e4c8..0x15e500）
 * @func 0x15e4c8 0x15e500  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e4c8 push {r4, lr}
 *   @0x15e4cc mov r4, r0
 *   @0x15e4d0 bl 0x290274 <getJNIEnv>
 *   @0x15e4d4 ldr r1, [pc, #0x1c]
 *   @0x15e4d8 mov r3, r4
 *   @0x15e4dc ldr r2, [pc, #0x18]
 *   @0x15e4e0 ldr r1, [pc, r1]
 *   @0x15e4e4 ldr r2, [pc, r2]
 *   @0x15e4e8 ldr r1, [r1]
 *   @0x15e4ec ldr r2, [r2]
 *   @0x15e4f0 pop {r4, lr}
 *   @0x15e4f4 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e4f8 eoreq pc, r8, r4, asr #9
 *   @0x15e4fc eoreq r1, r9, r8, lsr #19
 *
 * ══ §157/561 AdDisplayHeight(int)  0x15e500  size 56  14 条（0x15e500..0x15e538）
 * @func 0x15e500 0x15e538  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e500 push {r4, lr}
 *   @0x15e504 mov r4, r0
 *   @0x15e508 bl 0x290274 <getJNIEnv>
 *   @0x15e50c ldr r1, [pc, #0x1c]
 *   @0x15e510 mov r3, r4
 *   @0x15e514 ldr r2, [pc, #0x18]
 *   @0x15e518 ldr r1, [pc, r1]
 *   @0x15e51c ldr r2, [pc, r2]
 *   @0x15e520 ldr r1, [r1]
 *   @0x15e524 ldr r2, [r2]
 *   @0x15e528 pop {r4, lr}
 *   @0x15e52c b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e530 eoreq pc, r8, r12, lsl #9
 *   @0x15e534 eoreq r1, r9, r4, ror r9
 *
 * ══ §158/561 GetIsNetworkConnected()  0x15f26c  size 56  14 条（0x15f26c..0x15f2a4）
 * @func 0x15f26c 0x15f2a4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f26c push {r3, lr}
 *   @0x15f270 bl 0x290274 <getJNIEnv>
 *   @0x15f274 ldr r2, [pc, #0x20]
 *   @0x15f278 ldr r3, [pc, #0x20]
 *   @0x15f27c ldr r2, [pc, r2]
 *   @0x15f280 ldr r3, [pc, r3]
 *   @0x15f284 ldr r1, [r2]
 *   @0x15f288 ldr r2, [r3]
 *   @0x15f28c bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f290 adds r0, r0, #0
 *   @0x15f294 movne r0, #1
 *   @0x15f298 pop {r3, pc}
 *   @0x15f29c eoreq lr, r8, r8, lsr #14
 *   @0x15f2a0 eoreq r0, r9, r0, ror #24
 *
 * ══ §159/561 YYPowersaveEnable(bool)  0x15f2a4  size 56  14 条（0x15f2a4..0x15f2dc）
 * @func 0x15f2a4 0x15f2dc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f2a4 push {r4, lr}
 *   @0x15f2a8 mov r4, r0
 *   @0x15f2ac bl 0x290274 <getJNIEnv>
 *   @0x15f2b0 ldr r1, [pc, #0x1c]
 *   @0x15f2b4 mov r3, r4
 *   @0x15f2b8 ldr r2, [pc, #0x18]
 *   @0x15f2bc ldr r1, [pc, r1]
 *   @0x15f2c0 ldr r2, [pc, r2]
 *   @0x15f2c4 ldr r1, [r1]
 *   @0x15f2c8 ldr r2, [r2]
 *   @0x15f2cc pop {r4, lr}
 *   @0x15f2d0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f2d4 eoreq lr, r8, r8, ror #13
 *   @0x15f2d8 eoreq r0, r9, r4, lsr #24
 *
 * ══ §160/561 Push_CancelLocalNotification(int)  0x161c48  size 56  14 条（0x161c48..0x161c80）
 * @func 0x161c48 0x161c80  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161c48 push {r4, lr}
 *   @0x161c4c mov r4, r0
 *   @0x161c50 bl 0x290274 <getJNIEnv>
 *   @0x161c54 ldr r1, [pc, #0x1c]
 *   @0x161c58 mov r3, r4
 *   @0x161c5c ldr r2, [pc, #0x18]
 *   @0x161c60 ldr r1, [pc, r1]
 *   @0x161c64 ldr r2, [pc, r2]
 *   @0x161c68 ldr r1, [r1]
 *   @0x161c6c ldr r2, [r2]
 *   @0x161c70 pop {r4, lr}
 *   @0x161c74 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x161c78 eoreq r11, r8, r4, asr #26
 *   @0x161c7c eoreq lr, r8, r8, lsl r3
 *
 * ══ §161/561 C3D_Model::C3D_Model()  0x163d84  size 56  14 条（0x163d84..0x163dbc）
 * @func 0x163d84 0x163dbc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: C3D_Model::Clear()
 * 字段偏移 top8: 0x10×1 / 0x18×1 / 0xc×1 / 0x14×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163d84 push {r4, lr}
 *   @0x163d88 mov r3, #0
 *   @0x163d8c mov r4, r0
 *   @0x163d90 mov r2, #1
 *   @0x163d94 str r3, [r0, #0x10]
 *   @0x163d98 str r2, [r0, #0x18]
 *   @0x163d9c str r3, [r0, #0xc]
 *   @0x163da0 str r3, [r0, #0x14]
 *   @0x163da4 str r3, [r0]
 *   @0x163da8 str r3, [r0, #0x8]
 *   @0x163dac str r3, [r0, #0x4]
 *   @0x163db0 bl 0x163ce0 <_ZN9C3D_Model5ClearEv>
 *   @0x163db4 mov r0, r4
 *   @0x163db8 pop {r4, pc}
 *
 * ══ §162/561 GR_D3D_Set_Shading(bool)  0x16849c  size 56  14 条（0x16849c..0x1684d4）
 * @func 0x16849c 0x1684d4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16849c cmp r0, #0
 *   @0x1684a0 bne 0x1684b8 <_Z18GR_D3D_Set_Shadingb+0x1c>
 *   @0x1684a4 ldr r0, [pc, #0x20]
 *   @0x1684a8 mov r1, #3
 *   @0x1684ac mov r2, #1
 *   @0x1684b0 ldr r0, [pc, r0]
 *   @0x1684b4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1684b8 ldr r0, [pc, #0x10]
 *   @0x1684bc mov r1, #3
 *   @0x1684c0 mov r2, #2
 *   @0x1684c4 ldr r0, [pc, r0]
 *   @0x1684c8 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1684cc eoreq r5, r8, r8, asr #16
 *   @0x1684d0 eoreq r5, r8, r4, lsr r8
 *
 * ══ §163/561 Graphics::PrefetchTexture(void*)  0x182f04  size 56  14 条（0x182f04..0x182f3c）
 * @func 0x182f04 0x182f3c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182f04 push {r4, lr}
 *   @0x182f08 subs r4, r0, #0
 *   @0x182f0c popeq {r4, pc}
 *   @0x182f10 ldr r0, [pc, #0x20]
 *   @0x182f14 mov r1, #0
 *   @0x182f18 mov r2, #9
 *   @0x182f1c ldr r0, [pc, r0]
 *   @0x182f20 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x182f24 mov r1, #1
 *   @0x182f28 mov r2, r0
 *   @0x182f2c mov r0, r4
 *   @0x182f30 pop {r4, lr}
 *   @0x182f34 b 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x182f38 .word 0x0026addc
 *
 * ══ §164/561 GMGamePad::SetDeviceId(char const*)  0x18e944  size 56  14 条（0x18e944..0x18e97c）
 * @func 0x18e944 0x18e97c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e944 push {r3, r4, r5, lr}
 *   @0x18e948 subs r5, r1, #0
 *   @0x18e94c popeq {r3, r4, r5, pc}
 *   @0x18e950 add r4, r0, #44
 *   @0x18e954 mov r2, #512
 *   @0x18e958 mov r0, r4
 *   @0x18e95c bl 0xb65e0 <strncmp@plt>
 *   @0x18e960 cmp r0, #0
 *   @0x18e964 popeq {r3, r4, r5, pc}
 *   @0x18e968 mov r0, r4
 *   @0x18e96c mov r1, r5
 *   @0x18e970 mov r2, #512
 *   @0x18e974 pop {r3, r4, r5, lr}
 *   @0x18e978 b 0xb6568 <strncpy@plt>
 *
 * ══ §165/561 IO_SetupM(IniFile*)  0x18f05c  size 56  14 条（0x18f05c..0x18f094）
 * @func 0x18f05c 0x18f094  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::ReadInt(char const*, char const*, int)
 * 字段偏移 top8: 0x24×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f05c ldr r1, [pc, #0x24]
 *   @0x18f060 ldr r2, [pc, #0x24]
 *   @0x18f064 push {r3, lr}
 *   @0x18f068 add r1, pc, r1
 *   @0x18f06c mov r3, #0
 *   @0x18f070 add r2, pc, r2
 *   @0x18f074 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i>
 *   @0x18f078 ldr r3, [pc, #0x10]
 *   @0x18f07c ldr r3, [pc, r3]
 *   @0x18f080 str r0, [r3]
 *   @0x18f084 pop {r3, pc}
 *   @0x18f088 andseq sp, r11, r12, asr #7
 *   @0x18f08c ldrsbeq sp, [r11], -r4
 *   @0x18f090 .word 0x002615d0
 *
 * ══ §166/561 RVALUE_GEN_GC(RValue const*, unsigned int**, int, YYObjectBase*)  0x1921d4  size 56  14 条（0x1921d4..0x19220c）
 * @func 0x1921d4 0x19220c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1921d4 str r4, [sp, #-0x4]!
 *   @0x1921d8 ldr r4, [r0]
 *   @0x1921dc cmp r4, #0
 *   @0x1921e0 beq 0x1921f8 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase+0x24>
 *   @0x1921e4 ldr r12, [r0, #0xc]
 *   @0x1921e8 bic r12, r12, #-16777216
 *   @0x1921ec cmp r12, #6
 *   @0x1921f0 cmpne r12, #11
 *   @0x1921f4 beq 0x192200 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase+0x2c>
 *   @0x1921f8 ldr r4, [sp], #4
 *   @0x1921fc bx lr
 *   @0x192200 mov r0, r4
 *   @0x192204 ldr r4, [sp], #4
 *   @0x192208 b 0x19206c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_>
 *
 * ══ §167/561 ParticleSystem_GetLayer(int)  0x1a4628  size 56  14 条（0x1a4628..0x1a4660）
 * @func 0x1a4628 0x1a4660  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x4×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4628 push {r4, lr}
 *   @0x1a462c mov r4, r0
 *   @0x1a4630 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a4634 cmp r0, #0
 *   @0x1a4638 beq 0x1a4654 <_Z23ParticleSystem_GetLayeri+0x2c>
 *   @0x1a463c ldr r3, [pc, #0x18]
 *   @0x1a4640 ldr r3, [pc, r3]
 *   @0x1a4644 ldr r3, [r3, #0x4]
 *   @0x1a4648 ldr r3, [r3, r4, lsl #2]
 *   @0x1a464c ldr r0, [r3, #0x30]
 *   @0x1a4650 pop {r4, pc}
 *   @0x1a4654 mvn r0, #0
 *   @0x1a4658 pop {r4, pc}
 *   @0x1a465c eoreq r12, r4, r8, ror r1
 *
 * ══ §168/561 CPath::AddPoint(float, float, float)  0x1a72c0  size 56  14 条（0x1a72c0..0x1a72f8）
 * @func 0x1a72c0 0x1a72f8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::InsertPoint(int, float, float, float)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a72c0 push {r4, lr}
 *   @0x1a72c4 sub sp, sp, #8
 *   @0x1a72c8 mov lr, r1
 *   @0x1a72cc mov r12, r2
 *   @0x1a72d0 ldr r1, [r0, #0x10]
 *   @0x1a72d4 mov r2, lr
 *   @0x1a72d8 str r3, [sp]
 *   @0x1a72dc mov r3, r12
 *   @0x1a72e0 mov r4, r0
 *   @0x1a72e4 bl 0x1a71d0 <_ZN5CPath11InsertPointEifff>
 *   @0x1a72e8 ldr r0, [r4, #0x10]
 *   @0x1a72ec sub r0, r0, #1
 *   @0x1a72f0 add sp, sp, #8
 *   @0x1a72f4 pop {r4, pc}
 *
 * ══ §169/561 LoadGame()  0x1d1cb4  size 56  14 条（0x1d1cb4..0x1d1cec）
 * @func 0x1d1cb4 0x1d1cec  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Clear()
 * 字段偏移 top8: 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1cb4 push {r3, lr}
 *   @0x1d1cb8 mvn r2, #0
 *   @0x1d1cbc ldr r3, [pc, #0x20]
 *   @0x1d1cc0 ldr r3, [pc, r3]
 *   @0x1d1cc4 str r2, [r3]
 *   @0x1d1cc8 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1d1ccc ldr r3, [pc, #0x14]
 *   @0x1d1cd0 ldr r3, [pc, r3]
 *   @0x1d1cd4 ldr r3, [r3]
 *   @0x1d1cd8 ldr r0, [r3]
 *   @0x1d1cdc pop {r3, lr}
 *   @0x1d1ce0 b 0x1d14fc <_Z16Command_LoadGamePKc>
 *   @0x1d1ce4 eoreq r12, r1, r4, ror #1
 *   @0x1d1ce8 eoreq lr, r1, r12, asr #28
 *
 * ══ §170/561 _RefFactory<char const*>::Create(char const*, int&)  0x1dbe5c  size 56  14 条（0x1dbe5c..0x1dbe94）
 * @func 0x1dbe5c 0x1dbe94  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dbe5c push {r3, r4, r5, lr}
 *   @0x1dbe60 subs r4, r0, #0
 *   @0x1dbe64 mov r5, r1
 *   @0x1dbe68 beq 0x1dbe80 <_ZN11_RefFactoryIPKcE6CreateES1_Ri+0x24>
 *   @0x1dbe6c bl 0xb6538 <strlen@plt>
 *   @0x1dbe70 str r0, [r5]
 *   @0x1dbe74 mov r0, r4
 *   @0x1dbe78 pop {r3, r4, r5, lr}
 *   @0x1dbe7c b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1dbe80 mov r0, r4
 *   @0x1dbe84 str r0, [r5]
 *   @0x1dbe88 mov r0, r4
 *   @0x1dbe8c pop {r3, r4, r5, lr}
 *   @0x1dbe90 b 0xdb8c8 <_Z8YYStrDupPKc>
 *
 * ══ §171/561 HighScore_Clear()  0x1dc2d8  size 56  14 条（0x1dc2d8..0x1dc310）
 * @func 0x1dc2d8 0x1dc310  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SetAll(int, char const*, int)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc2d8 push {r3, r4, r5, lr}
 *   @0x1dc2dc mov r4, #1
 *   @0x1dc2e0 ldr r5, [pc, #0x24]
 *   @0x1dc2e4 ldr r5, [pc, r5]
 *   @0x1dc2e8 ldr r3, [r5]
 *   @0x1dc2ec mov r0, r4
 *   @0x1dc2f0 mov r2, #0
 *   @0x1dc2f4 add r4, r4, #1
 *   @0x1dc2f8 ldr r1, [r3]
 *   @0x1dc2fc bl 0x1dc254 <_Z6SetAlliPKci>
 *   @0x1dc300 cmp r4, #11
 *   @0x1dc304 bne 0x1dc2e8 <_Z15HighScore_Clearv+0x10>
 *   @0x1dc308 pop {r3, r4, r5, pc}
 *   @0x1dc30c eoreq r2, r1, r8, ror #18
 *
 * ══ §172/561 CSprite::SetBoundingBox(tagYYRECT*)  0x1e32e8  size 56  14 条（0x1e32e8..0x1e3320）
 * @func 0x1e32e8 0x1e3320  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x8×2 / 0x-4×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e32e8 ldr r3, [r0, #0x4]
 *   @0x1e32ec str r4, [sp, #-0x4]!
 *   @0x1e32f0 cmp r3, #2
 *   @0x1e32f4 bne 0x1e3318 <_ZN7CSprite14SetBoundingBoxEP9tagYYRECT+0x30>
 *   @0x1e32f8 ldr r4, [r1, #0xc]
 *   @0x1e32fc ldr r12, [r1]
 *   @0x1e3300 ldr r2, [r1, #0x8]
 *   @0x1e3304 ldr r3, [r1, #0x4]
 *   @0x1e3308 str r4, [r0, #0x14]
 *   @0x1e330c str r12, [r0, #0x8]
 *   @0x1e3310 str r2, [r0, #0x10]
 *   @0x1e3314 str r3, [r0, #0xc]
 *   @0x1e3318 ldr r4, [sp], #4
 *   @0x1e331c bx lr
 *
 * ══ §173/561 GV_MouseX(CInstance*, int, RValue*)  0x1fa010  size 56  14 条（0x1fa010..0x1fa048）
 * @func 0x1fa010 0x1fa048  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_X(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa010 mov r3, #0
 *   @0x1fa014 push {r4, r5, r6, lr}
 *   @0x1fa018 mov r0, r3
 *   @0x1fa01c str r3, [r2, #0xc]
 *   @0x1fa020 mov r6, r2
 *   @0x1fa024 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi>
 *   @0x1fa028 vmov s15, r0
 *   @0x1fa02c mov r0, #1
 *   @0x1fa030 vcvt.f64.s32 d7, s15
 *   @0x1fa034 vmov r4, r5, d7
 *   @0x1fa038 vmov r2, s14
 *   @0x1fa03c mov r3, r5
 *   @0x1fa040 stm r6, {r2, r3}
 *   @0x1fa044 pop {r4, r5, r6, pc}
 *
 * ══ §174/561 GV_MouseY(CInstance*, int, RValue*)  0x1fa048  size 56  14 条（0x1fa048..0x1fa080）
 * @func 0x1fa048 0x1fa080  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_Y(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa048 mov r3, #0
 *   @0x1fa04c push {r4, r5, r6, lr}
 *   @0x1fa050 mov r0, r3
 *   @0x1fa054 str r3, [r2, #0xc]
 *   @0x1fa058 mov r6, r2
 *   @0x1fa05c bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi>
 *   @0x1fa060 vmov s15, r0
 *   @0x1fa064 mov r0, #1
 *   @0x1fa068 vcvt.f64.s32 d7, s15
 *   @0x1fa06c vmov r4, r5, d7
 *   @0x1fa070 vmov r2, s14
 *   @0x1fa074 mov r3, r5
 *   @0x1fa078 stm r6, {r2, r3}
 *   @0x1fa07c pop {r4, r5, r6, pc}
 *
 * ══ §175/561 GV_MouseButton(CInstance*, int, RValue*)  0x1fa080  size 56  14 条（0x1fa080..0x1fa0b8）
 * @func 0x1fa080 0x1fa0b8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Current_Get(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa080 mov r3, #0
 *   @0x1fa084 push {r4, r5, r6, lr}
 *   @0x1fa088 mov r0, r3
 *   @0x1fa08c str r3, [r2, #0xc]
 *   @0x1fa090 mov r6, r2
 *   @0x1fa094 bl 0x18c048 <_Z21IO_Button_Current_Geti>
 *   @0x1fa098 vmov s15, r0
 *   @0x1fa09c mov r0, #1
 *   @0x1fa0a0 vcvt.f64.s32 d7, s15
 *   @0x1fa0a4 vmov r4, r5, d7
 *   @0x1fa0a8 vmov r2, s14
 *   @0x1fa0ac mov r3, r5
 *   @0x1fa0b0 stm r6, {r2, r3}
 *   @0x1fa0b4 pop {r4, r5, r6, pc}
 *
 * ══ §176/561 GV_MouseLastButton(CInstance*, int, RValue*)  0x1fa0b8  size 56  14 条（0x1fa0b8..0x1fa0f0）
 * @func 0x1fa0b8 0x1fa0f0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Button_Last_Get(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa0b8 mov r3, #0
 *   @0x1fa0bc push {r4, r5, r6, lr}
 *   @0x1fa0c0 mov r0, r3
 *   @0x1fa0c4 str r3, [r2, #0xc]
 *   @0x1fa0c8 mov r6, r2
 *   @0x1fa0cc bl 0x18c024 <_Z18IO_Button_Last_Geti>
 *   @0x1fa0d0 vmov s15, r0
 *   @0x1fa0d4 mov r0, #1
 *   @0x1fa0d8 vcvt.f64.s32 d7, s15
 *   @0x1fa0dc vmov r4, r5, d7
 *   @0x1fa0e0 vmov r2, s14
 *   @0x1fa0e4 mov r3, r5
 *   @0x1fa0e8 stm r6, {r2, r3}
 *   @0x1fa0ec pop {r4, r5, r6, pc}
 *
 * ══ §177/561 GV_CurrentDay(CInstance*, int, RValue*)  0x1fa32c  size 56  14 条（0x1fa32c..0x1fa364）
 * @func 0x1fa32c 0x1fa364  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa32c push {r4, r5, r6, lr}
 *   @0x1fa330 mov r3, #0
 *   @0x1fa334 str r3, [r2, #0xc]
 *   @0x1fa338 mov r6, r2
 *   @0x1fa33c bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa340 ldr r4, [r0, #0xc]
 *   @0x1fa344 mov r0, #1
 *   @0x1fa348 vmov s15, r4
 *   @0x1fa34c vcvt.f64.s32 d7, s15
 *   @0x1fa350 vmov r4, r5, d7
 *   @0x1fa354 vmov r2, s14
 *   @0x1fa358 mov r3, r5
 *   @0x1fa35c stm r6, {r2, r3}
 *   @0x1fa360 pop {r4, r5, r6, pc}
 *
 * ══ §178/561 GV_CurrentWeekday(CInstance*, int, RValue*)  0x1fa364  size 56  14 条（0x1fa364..0x1fa39c）
 * @func 0x1fa364 0x1fa39c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa364 push {r4, r5, r6, lr}
 *   @0x1fa368 mov r3, #0
 *   @0x1fa36c str r3, [r2, #0xc]
 *   @0x1fa370 mov r6, r2
 *   @0x1fa374 bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa378 ldr r4, [r0, #0x18]
 *   @0x1fa37c mov r0, #1
 *   @0x1fa380 vmov s15, r4
 *   @0x1fa384 vcvt.f64.s32 d7, s15
 *   @0x1fa388 vmov r4, r5, d7
 *   @0x1fa38c vmov r2, s14
 *   @0x1fa390 mov r3, r5
 *   @0x1fa394 stm r6, {r2, r3}
 *   @0x1fa398 pop {r4, r5, r6, pc}
 *
 * ══ §179/561 GV_CurrentHour(CInstance*, int, RValue*)  0x1fa39c  size 56  14 条（0x1fa39c..0x1fa3d4）
 * @func 0x1fa39c 0x1fa3d4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa39c push {r4, r5, r6, lr}
 *   @0x1fa3a0 mov r3, #0
 *   @0x1fa3a4 str r3, [r2, #0xc]
 *   @0x1fa3a8 mov r6, r2
 *   @0x1fa3ac bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa3b0 ldr r4, [r0, #0x8]
 *   @0x1fa3b4 mov r0, #1
 *   @0x1fa3b8 vmov s15, r4
 *   @0x1fa3bc vcvt.f64.s32 d7, s15
 *   @0x1fa3c0 vmov r4, r5, d7
 *   @0x1fa3c4 vmov r2, s14
 *   @0x1fa3c8 mov r3, r5
 *   @0x1fa3cc stm r6, {r2, r3}
 *   @0x1fa3d0 pop {r4, r5, r6, pc}
 *
 * ══ §180/561 GV_CurrentMinute(CInstance*, int, RValue*)  0x1fa3d4  size 56  14 条（0x1fa3d4..0x1fa40c）
 * @func 0x1fa3d4 0x1fa40c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa3d4 push {r4, r5, r6, lr}
 *   @0x1fa3d8 mov r3, #0
 *   @0x1fa3dc str r3, [r2, #0xc]
 *   @0x1fa3e0 mov r6, r2
 *   @0x1fa3e4 bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa3e8 ldr r4, [r0, #0x4]
 *   @0x1fa3ec mov r0, #1
 *   @0x1fa3f0 vmov s15, r4
 *   @0x1fa3f4 vcvt.f64.s32 d7, s15
 *   @0x1fa3f8 vmov r4, r5, d7
 *   @0x1fa3fc vmov r2, s14
 *   @0x1fa400 mov r3, r5
 *   @0x1fa404 stm r6, {r2, r3}
 *   @0x1fa408 pop {r4, r5, r6, pc}
 *
 * ══ §181/561 GV_CurrentSecond(CInstance*, int, RValue*)  0x1fa40c  size 56  14 条（0x1fa40c..0x1fa444）
 * @func 0x1fa40c 0x1fa444  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CurrentTimeToTM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa40c push {r4, r5, r6, lr}
 *   @0x1fa410 mov r3, #0
 *   @0x1fa414 str r3, [r2, #0xc]
 *   @0x1fa418 mov r6, r2
 *   @0x1fa41c bl 0x117a10 <_Z15CurrentTimeToTMv>
 *   @0x1fa420 ldr r4, [r0]
 *   @0x1fa424 mov r0, #1
 *   @0x1fa428 vmov s15, r4
 *   @0x1fa42c vcvt.f64.s32 d7, s15
 *   @0x1fa430 vmov r4, r5, d7
 *   @0x1fa434 vmov r2, s14
 *   @0x1fa438 mov r3, r5
 *   @0x1fa43c stm r6, {r2, r3}
 *   @0x1fa440 pop {r4, r5, r6, pc}
 *
 * ══ §182/561 SV_Argument(CInstance*, int, RValue*)  0x1fa444  size 56  14 条（0x1fa444..0x1fa47c）
 * @func 0x1fa444 0x1fa47c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa444 push {r3, lr}
 *   @0x1fa448 cmp r1, #15
 *   @0x1fa44c ldr r3, [pc, #0x24]
 *   @0x1fa450 lslls r0, r1, #4
 *   @0x1fa454 movhi r0, #0
 *   @0x1fa458 mov r1, r2
 *   @0x1fa45c ldr r3, [pc, r3]
 *   @0x1fa460 mov r2, #-2147483648
 *   @0x1fa464 ldr r3, [r3]
 *   @0x1fa468 add r0, r3, r0
 *   @0x1fa46c bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa470 mov r0, #1
 *   @0x1fa474 pop {r3, pc}
 *   @0x1fa478 ldrheq r3, [pc], -r4
 *
 * ══ §183/561 CStream::Clear()  0x2012f0  size 56  14 条（0x2012f0..0x201328）
 * @func 0x2012f0 0x201328  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2012f0 push {r3, r4, r5, lr}
 *   @0x2012f4 mov r4, r0
 *   @0x2012f8 ldrb r5, [r0]
 *   @0x2012fc cmp r5, #0
 *   @0x201300 popne {r3, r4, r5, pc}
 *   @0x201304 ldr r0, [r0, #0x18]
 *   @0x201308 cmp r0, #0
 *   @0x20130c popeq {r3, r4, r5, pc}
 *   @0x201310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x201314 mov r2, #0
 *   @0x201318 mov r3, #0
 *   @0x20131c str r5, [r4, #0x18]
 *   @0x201320 strd r2, r3, [r4, #8]
 *   @0x201324 pop {r3, r4, r5, pc}
 *
 * ══ §184/561 CDS_Map::FindFirst()  0x203c8c  size 56  14 条（0x203c8c..0x203cc4）
 * @func 0x203c8c 0x203cc4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203c8c ldr r1, [r0]
 *   @0x203c90 mov r3, #0
 *   @0x203c94 ldr r12, [r1]
 *   @0x203c98 b 0x203ca8 <_ZN7CDS_Map9FindFirstEv+0x1c>
 *   @0x203c9c ldr r2, [r1, #0x4]
 *   @0x203ca0 cmp r3, r2
 *   @0x203ca4 bgt 0x203cc0 <_ZN7CDS_Map9FindFirstEv+0x34>
 *   @0x203ca8 ldr r0, [r12, r3, lsl #3]
 *   @0x203cac add r3, r3, #1
 *   @0x203cb0 cmp r0, #0
 *   @0x203cb4 beq 0x203c9c <_ZN7CDS_Map9FindFirstEv+0x10>
 *   @0x203cb8 ldr r0, [r0, #0xc]
 *   @0x203cbc bx lr
 *   @0x203cc0 bx lr
 *
 * ══ §185/561 CDS_List::~CDS_List()  0x20ea78  size 56  14 条（0x20ea78..0x20eab0）
 * @func 0x20ea78 0x20eab0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×2 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20ea78 ldr r3, [pc, #0x2c]
 *   @0x20ea7c push {r4, lr}
 *   @0x20ea80 ldr r3, [pc, r3]
 *   @0x20ea84 mov r4, r0
 *   @0x20ea88 add r3, r3, #8
 *   @0x20ea8c str r3, [r0]
 *   @0x20ea90 bl 0x20e478 <_ZN8CDS_List5ClearEv>
 *   @0x20ea94 ldr r0, [r4, #0xc]
 *   @0x20ea98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20ea9c mov r3, #0
 *   @0x20eaa0 mov r0, r4
 *   @0x20eaa4 str r3, [r4, #0xc]
 *   @0x20eaa8 pop {r4, pc}
 *   @0x20eaac andseq r2, lr, r4, lsl r9
 *
 * ══ §186/561 CDS_Queue::~CDS_Queue()  0x20f21c  size 56  14 条（0x20f21c..0x20f254）
 * @func 0x20f21c 0x20f254  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Queue::Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×2 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f21c ldr r3, [pc, #0x2c]
 *   @0x20f220 push {r4, lr}
 *   @0x20f224 ldr r3, [pc, r3]
 *   @0x20f228 mov r4, r0
 *   @0x20f22c add r3, r3, #8
 *   @0x20f230 str r3, [r0]
 *   @0x20f234 bl 0x20eacc <_ZN9CDS_Queue5ClearEv>
 *   @0x20f238 ldr r0, [r4, #0x10]
 *   @0x20f23c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20f240 mov r3, #0
 *   @0x20f244 mov r0, r4
 *   @0x20f248 str r3, [r4, #0x10]
 *   @0x20f24c pop {r4, pc}
 *   @0x20f250 andseq r2, lr, r0, lsl #3
 *
 * ══ §187/561 CDS_Stack::CDS_Stack()  0x20f4dc  size 56  14 条（0x20f4dc..0x20f514）
 * @func 0x20f4dc 0x20f514  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Stack::Clear()
 * 字段偏移 top8: 0x2c×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f4dc ldr r2, [pc, #0x2c]
 *   @0x20f4e0 mov r3, #0
 *   @0x20f4e4 push {r4, lr}
 *   @0x20f4e8 ldr r2, [pc, r2]
 *   @0x20f4ec mov r4, r0
 *   @0x20f4f0 str r3, [r0, #0x4]
 *   @0x20f4f4 str r3, [r0, #0x8]
 *   @0x20f4f8 add r2, r2, #8
 *   @0x20f4fc str r3, [r0, #0xc]
 *   @0x20f500 str r2, [r0]
 *   @0x20f504 bl 0x20f270 <_ZN9CDS_Stack5ClearEv>
 *   @0x20f508 mov r0, r4
 *   @0x20f50c pop {r4, pc}
 *   @0x20f510 andseq r1, lr, r0, asr #29
 *
 * ══ §188/561 _JNIEnv::CallDoubleMethod(_jobject*, _jmethodID*, ...)  0x2148c4  size 56  14 条（0x2148c4..0x2148fc）
 * @func 0x2148c4 0x2148fc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0xec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148c4 push {r2, r3}
 *   @0x2148c8 str lr, [sp, #-0x4]!
 *   @0x2148cc sub sp, sp, #12
 *   @0x2148d0 ldr lr, [r0]
 *   @0x2148d4 add r12, sp, #20
 *   @0x2148d8 ldr r2, [sp, #0x10]
 *   @0x2148dc mov r3, r12
 *   @0x2148e0 str r12, [sp, #0x4]
 *   @0x2148e4 ldr r12, [lr, #0xec]
 *   @0x2148e8 blx r12
 *   @0x2148ec add sp, sp, #12
 *   @0x2148f0 ldr lr, [sp], #4
 *   @0x2148f4 add sp, sp, #8
 *   @0x2148f8 bx lr
 *
 * ══ §189/561 Timing_Init  0x2151b8  size 56  14 条（0x2151b8..0x2151f0）
 * @func 0x2151b8 0x2151f0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2151b8 push {r4, lr}
 *   @0x2151bc mov r3, #0
 *   @0x2151c0 ldr r4, [pc, #0x20]
 *   @0x2151c4 mov r2, #0
 *   @0x2151c8 add r4, pc, r4
 *   @0x2151cc strd r2, r3, [r4]
 *   @0x2151d0 bl 0x215148 <Timing_Time>
 *   @0x2151d4 ldr r3, [pc, #0x10]
 *   @0x2151d8 ldr r3, [pc, r3]
 *   @0x2151dc strd r0, r1, [r4]
 *   @0x2151e0 strd r0, r1, [r3]
 *   @0x2151e4 pop {r4, pc}
 *   @0x2151e8 subseq r0, r4, r0, asr #1
 *   @0x2151ec andseq r9, sp, r4, ror r0
 *
 * ══ §190/561 Audio_GetSoundType(int)  0x217028  size 56  14 条（0x217028..0x217060）
 * @func 0x217028 0x217060  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int)
 * 字段偏移 top8: 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217028 push {r3, lr}
 *   @0x21702c ldr r3, [pc, #0x28]
 *   @0x217030 ldr r3, [pc, r3]
 *   @0x217034 ldrb r3, [r3]
 *   @0x217038 cmp r3, #0
 *   @0x21703c bne 0x217054 <_Z18Audio_GetSoundTypei+0x2c>
 *   @0x217040 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x217044 cmp r0, #0
 *   @0x217048 beq 0x217054 <_Z18Audio_GetSoundTypei+0x2c>
 *   @0x21704c ldrb r0, [r0, #0x24]
 *   @0x217050 pop {r3, pc}
 *   @0x217054 mvn r0, #0
 *   @0x217058 pop {r3, pc}
 *   @0x21705c andseq r8, sp, r12, lsl r0
 *
 * ══ §191/561 Audio_GetGainFromSoundID(int)  0x217060  size 56  14 条（0x217060..0x217098）
 * @func 0x217060 0x217098  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int)
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217060 push {r3, lr}
 *   @0x217064 ldr r3, [pc, #0x28]
 *   @0x217068 ldr r3, [pc, r3]
 *   @0x21706c ldrb r3, [r3]
 *   @0x217070 cmp r3, #0
 *   @0x217074 beq 0x217080 <_Z24Audio_GetGainFromSoundIDi+0x20>
 *   @0x217078 mov r0, #1065353216
 *   @0x21707c pop {r3, pc}
 *   @0x217080 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x217084 cmp r0, #0
 *   @0x217088 beq 0x217078 <_Z24Audio_GetGainFromSoundIDi+0x18>
 *   @0x21708c ldr r0, [r0, #0x4]
 *   @0x217090 pop {r3, pc}
 *   @0x217094 andseq r7, sp, r4, ror #31
 *
 * ══ §192/561 CAudioGroup::FreeBuffers()  0x21dc80  size 56  14 条（0x21dc80..0x21dcb8）
 * @func 0x21dc80 0x21dcb8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: cAudio_Sound::FreeALBuffer()
 * 字段偏移 top8: 0x8×2 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dc80 push {r3, r4, r5, lr}
 *   @0x21dc84 mov r5, r0
 *   @0x21dc88 ldr r3, [r0, #0x8]
 *   @0x21dc8c cmp r3, #0
 *   @0x21dc90 pople {r3, r4, r5, pc}
 *   @0x21dc94 mov r4, #0
 *   @0x21dc98 ldr r3, [r5, #0x24]
 *   @0x21dc9c ldr r0, [r3, r4, lsl #2]
 *   @0x21dca0 add r4, r4, #1
 *   @0x21dca4 bl 0x2193d4 <_ZN12cAudio_Sound12FreeALBufferEv>
 *   @0x21dca8 ldr r3, [r5, #0x8]
 *   @0x21dcac cmp r3, r4
 *   @0x21dcb0 bgt 0x21dc98 <_ZN11CAudioGroup11FreeBuffersEv+0x18>
 *   @0x21dcb4 pop {r3, r4, r5, pc}
 *
 * ══ §193/561 _alutGetFormat  0x2213ec  size 56  14 条（0x2213ec..0x221424）
 * @func 0x2213ec 0x221424  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutFormatConstruct / _alutSetError
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213ec mov r3, r0
 *   @0x2213f0 mov r2, r1
 *   @0x2213f4 push {r4, lr}
 *   @0x2213f8 ldr r0, [r0, #0x8]
 *   @0x2213fc ldr r1, [r3, #0xc]
 *   @0x221400 bl 0x222ac8 <_alutFormatConstruct>
 *   @0x221404 subs r4, r0, #0
 *   @0x221408 beq 0x221414 <_alutGetFormat+0x28>
 *   @0x22140c mov r0, #1
 *   @0x221410 pop {r4, pc}
 *   @0x221414 mov r0, #528
 *   @0x221418 bl 0x221940 <_alutSetError>
 *   @0x22141c mov r0, r4
 *   @0x221420 pop {r4, pc}
 *
 * ══ §194/561 _alutCodecPCM8s  0x22150c  size 56  14 条（0x22150c..0x221544）
 * @func 0x22150c 0x221544  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22150c cmp r1, #0
 *   @0x221510 push {r4, r5, r6}
 *   @0x221514 movne r12, r0
 *   @0x221518 ldr r6, [sp, #0xc]
 *   @0x22151c addne r5, r1, r0
 *   @0x221520 beq 0x221538 <_alutCodecPCM8s+0x2c>
 *   @0x221524 ldrb r4, [r12]
 *   @0x221528 sub r4, r4, #128
 *   @0x22152c strb r4, [r12], #1
 *   @0x221530 cmp r12, r5
 *   @0x221534 bne 0x221524 <_alutCodecPCM8s+0x18>
 *   @0x221538 str r6, [sp, #0xc]
 *   @0x22153c pop {r4, r5, r6}
 *   @0x221540 b 0x221378 <_alutBufferDataConstruct>
 *
 * ══ §195/561 _alutCodecPCM16  0x221544  size 56  14 条（0x221544..0x22157c）
 * @func 0x221544 0x22157c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221544 push {r4, r5, r6}
 *   @0x221548 lsrs r5, r1, #1
 *   @0x22154c ldr r6, [sp, #0xc]
 *   @0x221550 addne r5, r0, r5, lsl #1
 *   @0x221554 movne r12, r0
 *   @0x221558 beq 0x221570 <_alutCodecPCM16+0x2c>
 *   @0x22155c ldrh r4, [r12]
 *   @0x221560 rev16 r4, r4
 *   @0x221564 strh r4, [r12], #2
 *   @0x221568 cmp r12, r5
 *   @0x22156c bne 0x22155c <_alutCodecPCM16+0x18>
 *   @0x221570 str r6, [sp, #0xc]
 *   @0x221574 pop {r4, r5, r6}
 *   @0x221578 b 0x221378 <_alutBufferDataConstruct>
 *
 * ══ §196/561 _alutInputStreamReadUInt16LE  0x221f1c  size 56  14 条（0x221f1c..0x221f54）
 * @func 0x221f1c 0x221f54  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_221c48
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221f1c push {r4, lr}
 *   @0x221f20 sub sp, sp, #8
 *   @0x221f24 mov r2, #2
 *   @0x221f28 mov r4, r1
 *   @0x221f2c add r1, sp, #4
 *   @0x221f30 bl 0x221c48 <alutExit+0xd0>
 *   @0x221f34 cmp r0, #0
 *   @0x221f38 ldrbne r3, [sp, #0x4]
 *   @0x221f3c movne r0, #1
 *   @0x221f40 ldrbne r2, [sp, #0x5]
 *   @0x221f44 orrne r3, r3, r2, lsl #8
 *   @0x221f48 strhne r3, [r4]
 *   @0x221f4c add sp, sp, #8
 *   @0x221f50 pop {r4, pc}
 *
 * ══ §197/561 OpenAL_PlayingMP3()  0x2232a0  size 56  14 条（0x2232a0..0x2232d8）
 * @func 0x2232a0 0x2232d8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticBooleanMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2232a0 push {r3, lr}
 *   @0x2232a4 bl 0x290274 <getJNIEnv>
 *   @0x2232a8 ldr r2, [pc, #0x20]
 *   @0x2232ac ldr r3, [pc, #0x20]
 *   @0x2232b0 ldr r2, [pc, r2]
 *   @0x2232b4 ldr r3, [pc, r3]
 *   @0x2232b8 ldr r1, [r2]
 *   @0x2232bc ldr r2, [r3]
 *   @0x2232c0 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz>
 *   @0x2232c4 adds r0, r0, #0
 *   @0x2232c8 movne r0, #1
 *   @0x2232cc pop {r3, pc}
 *   @0x2232d0 ldrsheq r10, [r12], -r4
 *   @0x2232d4 ldrheq lr, [r12], -r12
 *
 * ══ §198/561 COggThread::Seek_Sound(int, float)  0x223ba4  size 56  14 条（0x223ba4..0x223bdc）
 * @func 0x223ba4 0x223bdc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x2d6×2 / 0x804×1 / 0x2e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223ba4 ldr r3, [r0, #0x804]
 *   @0x223ba8 add r1, r1, r1, lsl #1
 *   @0x223bac push {r4, r5, r6, lr}
 *   @0x223bb0 add r4, r3, r1, lsl #8
 *   @0x223bb4 mov r5, r0
 *   @0x223bb8 mov r6, r2
 *   @0x223bbc bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223bc0 ldrb r3, [r4, #0x2d6]
 *   @0x223bc4 str r6, [r4, #0x2e8]
 *   @0x223bc8 mov r0, r5
 *   @0x223bcc orr r3, r3, #16
 *   @0x223bd0 strb r3, [r4, #0x2d6]
 *   @0x223bd4 pop {r4, r5, r6, lr}
 *   @0x223bd8 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *
 * ══ §199/561 COggSyncThread::Seek_Sound(int, float)  0x224fa4  size 56  14 条（0x224fa4..0x224fdc）
 * @func 0x224fa4 0x224fdc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x2d6×2 / 0x804×1 / 0x2e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224fa4 ldr r3, [r0, #0x804]
 *   @0x224fa8 add r1, r1, r1, lsl #1
 *   @0x224fac push {r4, r5, r6, lr}
 *   @0x224fb0 add r4, r3, r1, lsl #8
 *   @0x224fb4 mov r5, r0
 *   @0x224fb8 mov r6, r2
 *   @0x224fbc bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224fc0 ldrb r3, [r4, #0x2d6]
 *   @0x224fc4 str r6, [r4, #0x2e8]
 *   @0x224fc8 mov r0, r5
 *   @0x224fcc orr r3, r3, #16
 *   @0x224fd0 strb r3, [r4, #0x2d6]
 *   @0x224fd4 pop {r4, r5, r6, lr}
 *   @0x224fd8 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *
 * ══ §200/561 oggpack_writeinit  0x233264  size 56  14 条（0x233264..0x23329c）
 * @func 0x233264 0x23329c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / 0xb6544
 * 字段偏移 top8: 0x10×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233264 push {r4, lr}
 *   @0x233268 mov r2, #20
 *   @0x23326c mov r1, #0
 *   @0x233270 mov r4, r0
 *   @0x233274 bl 0xb65b0 <memset@plt>
 *   @0x233278 mov r0, #256
 *   @0x23327c bl 0xb6544 <malloc@plt>
 *   @0x233280 mov r2, #256
 *   @0x233284 mov r3, #0
 *   @0x233288 str r2, [r4, #0x10]
 *   @0x23328c str r0, [r4, #0x8]
 *   @0x233290 str r0, [r4, #0xc]
 *   @0x233294 strb r3, [r0]
 *   @0x233298 pop {r4, pc}
 *
 * ══ §201/561 F_JSPrint(RValue&, CInstance*, CInstance*, int, RValue*)  0x23ca84  size 56  14 条（0x23ca84..0x23cabc）
 * @func 0x23ca84 0x23cabc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ca84 push {r3, r4, r5, lr}
 *   @0x23ca88 mov r1, #0
 *   @0x23ca8c ldr r3, [pc, #0x24]
 *   @0x23ca90 ldr r0, [sp, #0x10]
 *   @0x23ca94 ldr r3, [pc, r3]
 *   @0x23ca98 ldr r4, [r3]
 *   @0x23ca9c ldr r3, [r4]
 *   @0x23caa0 ldr r5, [r3, #0xc]
 *   @0x23caa4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x23caa8 mov r1, r0
 *   @0x23caac mov r0, r4
 *   @0x23cab0 blx r5
 *   @0x23cab4 pop {r3, r4, r5, pc}
 *   @0x23cab8 andseq r0, r11, r0, lsl #25
 *
 * ══ §202/561 JS_Math_random(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cc40  size 56  14 条（0x23cc40..0x23cc78）
 * @func 0x23cc40 0x23cc78  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c10
 * 字段偏移 top8: 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cc40 push {r4, lr}
 *   @0x23cc44 mov r3, #0
 *   @0x23cc48 str r3, [r0, #0xc]
 *   @0x23cc4c mov r4, r0
 *   @0x23cc50 bl 0xb6c10 <lrand48@plt>
 *   @0x23cc54 vldr d7, [pc, #20]
 *   @0x23cc58 vmov s10, r0
 *   @0x23cc5c vcvt.f64.s32 d6, s10
 *   @0x23cc60 vdiv.f64 d5, d6, d7
 *   @0x23cc64 vmov r2, r3, d5
 *   @0x23cc68 stm r4, {r2, r3}
 *   @0x23cc6c pop {r4, pc}
 *   @0x23cc70 .word 0xffc00000
 *   @0x23cc74 ldrshmi pc, [pc, #255]
 *
 * ══ §203/561 JS_HasProperty(YYObjectBase*, char const*)  0x241924  size 56  14 条（0x241924..0x24195c）
 * @func 0x241924 0x24195c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241924 str lr, [sp, #-0x4]!
 *   @0x241928 sub sp, sp, #20
 *   @0x24192c mov r2, r1
 *   @0x241930 mov r3, #5
 *   @0x241934 mov r1, sp
 *   @0x241938 str r3, [sp, #0xc]
 *   @0x24193c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241940 ldr r0, [sp, #0xc]
 *   @0x241944 mvn r3, #-16777216
 *   @0x241948 and r0, r0, r3
 *   @0x24194c subs r0, r0, r3
 *   @0x241950 movne r0, #1
 *   @0x241954 add sp, sp, #20
 *   @0x241958 ldr pc, [sp], #4
 *
 * ══ §204/561 HourFromTime(double)  0x245120  size 56  14 条（0x245120..0x245158）
 * @func 0x245120 0x245158  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245120 vmov d6, r0, r1
 *   @0x245124 vldr d7, [pc, #36]
 *   @0x245128 push {r4, lr}
 *   @0x24512c vdiv.f64 d6, d6, d7
 *   @0x245130 vmov r0, r1, d6
 *   @0x245134 bl 0xb6598 <floor@plt>
 *   @0x245138 mov r3, #0
 *   @0x24513c mov r2, #0
 *   @0x245140 movt r3, #0x4038
 *   @0x245144 pop {r4, lr}
 *   @0x245148 b 0xb66ac <fmod@plt>
 *   @0x24514c nop
 *   @0x245150 andeq r0, r0, r0
 *   @0x245154 .word 0x414b7740
 *
 * ══ §205/561 MinFromTime(double)  0x245158  size 56  14 条（0x245158..0x245190）
 * @func 0x245158 0x245190  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245158 vmov d6, r0, r1
 *   @0x24515c vldr d7, [pc, #36]
 *   @0x245160 push {r4, lr}
 *   @0x245164 vdiv.f64 d6, d6, d7
 *   @0x245168 vmov r0, r1, d6
 *   @0x24516c bl 0xb6598 <floor@plt>
 *   @0x245170 mov r3, #0
 *   @0x245174 mov r2, #0
 *   @0x245178 movt r3, #0x404e
 *   @0x24517c pop {r4, lr}
 *   @0x245180 b 0xb66ac <fmod@plt>
 *   @0x245184 nop
 *   @0x245188 andeq r0, r0, r0
 *   @0x24518c rscmi r4, sp, r0, lsl #24
 *
 * ══ §206/561 SecFromTime(double)  0x245190  size 56  14 条（0x245190..0x2451c8）
 * @func 0x245190 0x2451c8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245190 vmov d6, r0, r1
 *   @0x245194 vldr d7, [pc, #36]
 *   @0x245198 push {r4, lr}
 *   @0x24519c vdiv.f64 d6, d6, d7
 *   @0x2451a0 vmov r0, r1, d6
 *   @0x2451a4 bl 0xb6598 <floor@plt>
 *   @0x2451a8 mov r3, #0
 *   @0x2451ac mov r2, #0
 *   @0x2451b0 movt r3, #0x404e
 *   @0x2451b4 pop {r4, lr}
 *   @0x2451b8 b 0xb66ac <fmod@plt>
 *   @0x2451bc nop
 *   @0x2451c0 andeq r0, r0, r0
 *   @0x2451c4 addmi r4, pc, r0
 *
 * ══ §207/561 INITIALIZE_JavaScript()  0x246fa8  size 56  14 条（0x246fa8..0x246fe0）
 * @func 0x246fa8 0x246fe0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_FunctionSetup() / JS_GlobalObjectSetup() / JS_ObjectSetup() / JS_ArrayObjectSetup() / JS_StringSetup() / JS_MathObjectSetup() / JS_BooleanObjectSetup() / JS_ErrorObjectSetup()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246fa8 push {r3, lr}
 *   @0x246fac bl 0x24163c <_Z16JS_FunctionSetupv>
 *   @0x246fb0 bl 0x240ffc <_Z20JS_GlobalObjectSetupv>
 *   @0x246fb4 bl 0x241df4 <_Z14JS_ObjectSetupv>
 *   @0x246fb8 bl 0x243074 <_Z19JS_ArrayObjectSetupv>
 *   @0x246fbc bl 0x24269c <_Z14JS_StringSetupv>
 *   @0x246fc0 bl 0x243680 <_Z18JS_MathObjectSetupv>
 *   @0x246fc4 bl 0x243bf0 <_Z21JS_BooleanObjectSetupv>
 *   @0x246fc8 bl 0x244368 <_Z19JS_ErrorObjectSetupv>
 *   @0x246fcc bl 0x2445a8 <_Z20JS_NumberObjectSetupv>
 *   @0x246fd0 bl 0x246328 <_Z18JS_DateObjectSetupv>
 *   @0x246fd4 bl 0x246cc0 <_Z20JS_RegExpObjectSetupv>
 *   @0x246fd8 pop {r3, lr}
 *   @0x246fdc b 0x246ee0 <_Z18JS_JSONObjectSetupv>
 *
 * ══ §208/561 CBucket<16384u, 262144u, true>::Free(void const*)  0x27b760  size 56  14 条（0x27b760..0x27b798）
 * @func 0x27b760 0x27b798  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b760 mov r3, r0
 *   @0x27b764 str r4, [sp, #-0x4]!
 *   @0x27b768 ldr r4, [r0, #0x8]
 *   @0x27b76c mov r0, #1
 *   @0x27b770 ldr r12, [r3, #0x10]
 *   @0x27b774 ldr r2, [r3, #0xc]
 *   @0x27b778 add r12, r12, r0
 *   @0x27b77c str r4, [r1]
 *   @0x27b780 sub r2, r2, #1
 *   @0x27b784 str r1, [r3, #0x8]
 *   @0x27b788 str r12, [r3, #0x10]
 *   @0x27b78c str r2, [r3, #0xc]
 *   @0x27b790 ldr r4, [sp], #4
 *   @0x27b794 bx lr
 *
 * ══ §209/561 CBucket<256u, 1048576u, true>::Free(void const*)  0x27b7a0  size 56  14 条（0x27b7a0..0x27b7d8）
 * @func 0x27b7a0 0x27b7d8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b7a0 mov r3, r0
 *   @0x27b7a4 str r4, [sp, #-0x4]!
 *   @0x27b7a8 ldr r4, [r0, #0x8]
 *   @0x27b7ac mov r0, #1
 *   @0x27b7b0 ldr r12, [r3, #0x10]
 *   @0x27b7b4 ldr r2, [r3, #0xc]
 *   @0x27b7b8 add r12, r12, r0
 *   @0x27b7bc str r4, [r1]
 *   @0x27b7c0 sub r2, r2, #1
 *   @0x27b7c4 str r1, [r3, #0x8]
 *   @0x27b7c8 str r12, [r3, #0x10]
 *   @0x27b7cc str r2, [r3, #0xc]
 *   @0x27b7d0 ldr r4, [sp], #4
 *   @0x27b7d4 bx lr
 *
 * ══ §210/561 CBucket<128u, 524288u, true>::Free(void const*)  0x27b7e0  size 56  14 条（0x27b7e0..0x27b818）
 * @func 0x27b7e0 0x27b818  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b7e0 mov r3, r0
 *   @0x27b7e4 str r4, [sp, #-0x4]!
 *   @0x27b7e8 ldr r4, [r0, #0x8]
 *   @0x27b7ec mov r0, #1
 *   @0x27b7f0 ldr r12, [r3, #0x10]
 *   @0x27b7f4 ldr r2, [r3, #0xc]
 *   @0x27b7f8 add r12, r12, r0
 *   @0x27b7fc str r4, [r1]
 *   @0x27b800 sub r2, r2, #1
 *   @0x27b804 str r1, [r3, #0x8]
 *   @0x27b808 str r12, [r3, #0x10]
 *   @0x27b80c str r2, [r3, #0xc]
 *   @0x27b810 ldr r4, [sp], #4
 *   @0x27b814 bx lr
 *
 * ══ §211/561 CBucket<64u, 524288u, true>::Free(void const*)  0x27b820  size 56  14 条（0x27b820..0x27b858）
 * @func 0x27b820 0x27b858  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b820 mov r3, r0
 *   @0x27b824 str r4, [sp, #-0x4]!
 *   @0x27b828 ldr r4, [r0, #0x8]
 *   @0x27b82c mov r0, #1
 *   @0x27b830 ldr r12, [r3, #0x10]
 *   @0x27b834 ldr r2, [r3, #0xc]
 *   @0x27b838 add r12, r12, r0
 *   @0x27b83c str r4, [r1]
 *   @0x27b840 sub r2, r2, #1
 *   @0x27b844 str r1, [r3, #0x8]
 *   @0x27b848 str r12, [r3, #0x10]
 *   @0x27b84c str r2, [r3, #0xc]
 *   @0x27b850 ldr r4, [sp], #4
 *   @0x27b854 bx lr
 *
 * ══ §212/561 CBucket<32u, 262144u, true>::Free(void const*)  0x27b860  size 56  14 条（0x27b860..0x27b898）
 * @func 0x27b860 0x27b898  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b860 mov r3, r0
 *   @0x27b864 str r4, [sp, #-0x4]!
 *   @0x27b868 ldr r4, [r0, #0x8]
 *   @0x27b86c mov r0, #1
 *   @0x27b870 ldr r12, [r3, #0x10]
 *   @0x27b874 ldr r2, [r3, #0xc]
 *   @0x27b878 add r12, r12, r0
 *   @0x27b87c str r4, [r1]
 *   @0x27b880 sub r2, r2, #1
 *   @0x27b884 str r1, [r3, #0x8]
 *   @0x27b888 str r12, [r3, #0x10]
 *   @0x27b88c str r2, [r3, #0xc]
 *   @0x27b890 ldr r4, [sp], #4
 *   @0x27b894 bx lr
 *
 * ══ §213/561 CBucket<16u, 262144u, true>::Free(void const*)  0x27b8a0  size 56  14 条（0x27b8a0..0x27b8d8）
 * @func 0x27b8a0 0x27b8d8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b8a0 mov r3, r0
 *   @0x27b8a4 str r4, [sp, #-0x4]!
 *   @0x27b8a8 ldr r4, [r0, #0x8]
 *   @0x27b8ac mov r0, #1
 *   @0x27b8b0 ldr r12, [r3, #0x10]
 *   @0x27b8b4 ldr r2, [r3, #0xc]
 *   @0x27b8b8 add r12, r12, r0
 *   @0x27b8bc str r4, [r1]
 *   @0x27b8c0 sub r2, r2, #1
 *   @0x27b8c4 str r1, [r3, #0x8]
 *   @0x27b8c8 str r12, [r3, #0x10]
 *   @0x27b8cc str r2, [r3, #0xc]
 *   @0x27b8d0 ldr r4, [sp], #4
 *   @0x27b8d4 bx lr
 *
 * ══ §214/561 CBucket<8u, 131072u, true>::Free(void const*)  0x27b8e0  size 56  14 条（0x27b8e0..0x27b918）
 * @func 0x27b8e0 0x27b918  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b8e0 mov r3, r0
 *   @0x27b8e4 str r4, [sp, #-0x4]!
 *   @0x27b8e8 ldr r4, [r0, #0x8]
 *   @0x27b8ec mov r0, #1
 *   @0x27b8f0 ldr r12, [r3, #0x10]
 *   @0x27b8f4 ldr r2, [r3, #0xc]
 *   @0x27b8f8 add r12, r12, r0
 *   @0x27b8fc str r4, [r1]
 *   @0x27b900 sub r2, r2, #1
 *   @0x27b904 str r1, [r3, #0x8]
 *   @0x27b908 str r12, [r3, #0x10]
 *   @0x27b90c str r2, [r3, #0xc]
 *   @0x27b910 ldr r4, [sp], #4
 *   @0x27b914 bx lr
 *
 * ══ §215/561 SMemoryArray::Alloc(int)  0x27dd6c  size 56  14 条（0x27dd6c..0x27dda4）
 * @func 0x27dd6c 0x27dda4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dd6c ldr r3, [r0, #0x14]
 *   @0x27dd70 str r4, [sp, #-0x4]!
 *   @0x27dd74 cmp r3, #0
 *   @0x27dd78 lslge r1, r3, #1
 *   @0x27dd7c subge r3, r3, #1
 *   @0x27dd80 ldrge r4, [r0, #0x10]
 *   @0x27dd84 movlt r0, #0
 *   @0x27dd88 ldrge r12, [r0, #0x18]
 *   @0x27dd8c ldrge r2, [r0, #0x8]
 *   @0x27dd90 ldrshge r1, [r4, r1]
 *   @0x27dd94 strge r3, [r0, #0x14]
 *   @0x27dd98 ldr r4, [sp], #4
 *   @0x27dd9c mlage r0, r12, r1, r2
 *   @0x27dda0 bx lr
 *
 * ══ §216/561 spEventTimeline_setFrame  0x282d14  size 56  14 条（0x282d14..0x282d4c）
 * @func 0x282d14 0x282d4c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x10×2 / 0x2×2 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282d14 ldr r3, [r0, #0xc]
 *   @0x282d18 push {r4, r5, r6, lr}
 *   @0x282d1c mov r5, r1
 *   @0x282d20 mov r6, r2
 *   @0x282d24 ldr r1, [r0, #0x10]
 *   @0x282d28 ldr r2, [r2, #0x4]
 *   @0x282d2c add r3, r3, r5, lsl #2
 *   @0x282d30 mov r4, r0
 *   @0x282d34 ldr r0, [r1, r5, lsl #2]
 *   @0x282d38 str r2, [r3]
 *   @0x282d3c bl 0x285c80 <_free>
 *   @0x282d40 ldr r3, [r4, #0x10]
 *   @0x282d44 str r6, [r3, r5, lsl #2]
 *   @0x282d48 pop {r4, r5, r6, pc}
 *
 * ══ §217/561 spAnimationState_setAnimationByName  0x283964  size 56  14 条（0x283964..0x28399c）
 * @func 0x283964 0x28399c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283964 push {r4, r5, r6, lr}
 *   @0x283968 mov r4, r0
 *   @0x28396c ldr r0, [r0]
 *   @0x283970 mov r5, r1
 *   @0x283974 mov r1, r2
 *   @0x283978 mov r6, r3
 *   @0x28397c ldr r0, [r0]
 *   @0x283980 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0x283984 mov r1, r5
 *   @0x283988 mov r3, r6
 *   @0x28398c mov r2, r0
 *   @0x283990 mov r0, r4
 *   @0x283994 pop {r4, r5, r6, lr}
 *   @0x283998 b 0x283900 <spAnimationState_setAnimation>
 *
 * ══ §218/561 spSkeletonJson_dispose  0x28b74c  size 56  14 条（0x28b74c..0x28b784）
 * @func 0x28b74c 0x28b784  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / spAttachmentLoader_dispose
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b74c ldr r3, [r0, #0xc]
 *   @0x28b750 push {r4, lr}
 *   @0x28b754 cmp r3, #0
 *   @0x28b758 mov r4, r0
 *   @0x28b75c beq 0x28b768 <spSkeletonJson_dispose+0x1c>
 *   @0x28b760 ldr r0, [r0, #0x4]
 *   @0x28b764 bl 0x284d38 <spAttachmentLoader_dispose>
 *   @0x28b768 ldr r0, [r4, #0x18]
 *   @0x28b76c bl 0x285c80 <_free>
 *   @0x28b770 ldr r0, [r4, #0x8]
 *   @0x28b774 bl 0x285c80 <_free>
 *   @0x28b778 mov r0, r4
 *   @0x28b77c pop {r4, lr}
 *   @0x28b780 b 0x285c80 <_free>
 *
 * ══ §219/561 _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...)  0x28fc74  size 56  14 条（0x28fc74..0x28fcac）
 * @func 0x28fc74 0x28fcac  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x8c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fc74 push {r2, r3}
 *   @0x28fc78 str lr, [sp, #-0x4]!
 *   @0x28fc7c sub sp, sp, #12
 *   @0x28fc80 ldr lr, [r0]
 *   @0x28fc84 add r12, sp, #20
 *   @0x28fc88 ldr r2, [sp, #0x10]
 *   @0x28fc8c mov r3, r12
 *   @0x28fc90 str r12, [sp, #0x4]
 *   @0x28fc94 ldr r12, [lr, #0x8c]
 *   @0x28fc98 blx r12
 *   @0x28fc9c add sp, sp, #12
 *   @0x28fca0 ldr lr, [sp], #4
 *   @0x28fca4 add sp, sp, #8
 *   @0x28fca8 bx lr
 *
 * ══ §220/561 _JNIEnv::CallBooleanMethod(_jobject*, _jmethodID*, ...)  0x28fcac  size 56  14 条（0x28fcac..0x28fce4）
 * @func 0x28fcac 0x28fce4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x98×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fcac push {r2, r3}
 *   @0x28fcb0 str lr, [sp, #-0x4]!
 *   @0x28fcb4 sub sp, sp, #12
 *   @0x28fcb8 ldr lr, [r0]
 *   @0x28fcbc add r12, sp, #20
 *   @0x28fcc0 ldr r2, [sp, #0x10]
 *   @0x28fcc4 mov r3, r12
 *   @0x28fcc8 str r12, [sp, #0x4]
 *   @0x28fccc ldr r12, [lr, #0x98]
 *   @0x28fcd0 blx r12
 *   @0x28fcd4 add sp, sp, #12
 *   @0x28fcd8 ldr lr, [sp], #4
 *   @0x28fcdc add sp, sp, #8
 *   @0x28fce0 bx lr
 *
 * ══ §221/561 yySocket::AvoidTimeWait()  0x294f30  size 56  14 条（0x294f30..0x294f68）
 * @func 0x294f30 0x294f68  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d9c
 * 字段偏移 top8: 0x-4×1 / 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294f30 str lr, [sp, #-0x4]!
 *   @0x294f34 sub sp, sp, #20
 *   @0x294f38 ldr r0, [r0]
 *   @0x294f3c mov r3, #8
 *   @0x294f40 mov r1, #1
 *   @0x294f44 str r3, [sp]
 *   @0x294f48 mov r2, #13
 *   @0x294f4c add r3, sp, r3
 *   @0x294f50 mov r12, #0
 *   @0x294f54 str r12, [sp, #0x8]
 *   @0x294f58 str r12, [sp, #0xc]
 *   @0x294f5c bl 0xb6d9c <setsockopt@plt>
 *   @0x294f60 add sp, sp, #20
 *   @0x294f64 ldr pc, [sp], #4
 *
 * ══ §222/561 yySocket::yySocket(int, eSocketType, bool)  0x2970c0  size 56  14 条（0x2970c0..0x2970f8）
 * @func 0x2970c0 0x2970f8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::InitSocket(eSocketType) / yySocket::AllocateBuffer(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2970c0 push {r4, r5, r6, lr}
 *   @0x2970c4 mov r5, r1
 *   @0x2970c8 mov r1, r2
 *   @0x2970cc mov r6, r3
 *   @0x2970d0 mov r4, r0
 *   @0x2970d4 bl 0x297008 <_ZN8yySocket10InitSocketE11eSocketType>
 *   @0x2970d8 cmp r6, #0
 *   @0x2970dc str r5, [r4]
 *   @0x2970e0 beq 0x2970f0 <_ZN8yySocketC2Ei11eSocketTypeb+0x30>
 *   @0x2970e4 mov r0, r4
 *   @0x2970e8 mov r1, #4096
 *   @0x2970ec bl 0x296080 <_ZN8yySocket14AllocateBufferEi>
 *   @0x2970f0 mov r0, r4
 *   @0x2970f4 pop {r4, r5, r6, pc}
 *
 * ══ §223/561 yyServer::SendCommand(yySocket*, eNetworkCommand)  0x29756c  size 56  14 条（0x29756c..0x2975a4）
 * @func 0x29756c 0x2975a4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::Write(void*, unsigned int)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29756c str lr, [sp, #-0x4]!
 *   @0x297570 sub sp, sp, #52
 *   @0x297574 mov r12, #44
 *   @0x297578 mov r0, r1
 *   @0x29757c str r2, [sp, #0x10]
 *   @0x297580 add r1, sp, #4
 *   @0x297584 mov r2, r12
 *   @0x297588 str r12, [sp, #0x8]
 *   @0x29758c movw r3, #0xc0de
 *   @0x297590 movt r3, #0xbe11
 *   @0x297594 str r3, [sp, #0x4]
 *   @0x297598 bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x29759c add sp, sp, #52
 *   @0x2975a0 ldr pc, [sp], #4
 *
 * ══ §224/561 DebuggerMessageLoopTick()  0x29d6e8  size 56  14 条（0x29d6e8..0x29d720）
 * @func 0x29d6e8 0x29d720  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ProcessMessages()
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d6e8 push {r4, lr}
 *   @0x29d6ec ldr r4, [pc, #0x28]
 *   @0x29d6f0 ldr r4, [pc, r4]
 *   @0x29d6f4 ldr r3, [r4]
 *   @0x29d6f8 cmp r3, #0
 *   @0x29d6fc popeq {r4, pc}
 *   @0x29d700 ldrb r3, [r3, #0x4]
 *   @0x29d704 cmp r3, #0
 *   @0x29d708 popeq {r4, pc}
 *   @0x29d70c bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x29d710 ldr r0, [r4]
 *   @0x29d714 pop {r4, lr}
 *   @0x29d718 b 0x29d62c <_ZN9DbgServer7ProcessEv>
 *   @0x29d71c andseq r0, r5, r4, lsl #12
 *
 * ══ §225/561 png_chunk_error  0x2a64cc  size 56  14 条（0x2a64cc..0x2a6504）
 * @func 0x2a64cc 0x2a6504  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2a6398 / png_error / 0xb65d4
 * 字段偏移 top8: 0x30×1 / 0x54×1 / 0x12×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a64cc ldr r3, [pc, #0x30]
 *   @0x2a64d0 push {r4, r5, r6, lr}
 *   @0x2a64d4 ldr r3, [r3]
 *   @0x2a64d8 mov r6, r0
 *   @0x2a64dc mov r5, r3
 *   @0x2a64e0 cbz r0, 0x2a64ec <png_chunk_error+0x20>
 *   @0x2a64e4 bl 0x2a6398 <png_check_IHDR+0x1e8>
 *   @0x2a64e8 mov r0, r6
 *   @0x2a64ec bl 0x2a642c <png_error>
 *   @0x2a64f0 ldr r2, [sp, #0x54]
 *   @0x2a64f4 cmp r2, r3
 *   @0x2a64f8 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a64fc add sp, #0x58
 *   @0x2a6500 strb r2, [r0, #0x12]
 *
 * ══ §226/561 png_chunk_warning  0x2a6504  size 56  14 条（0x2a6504..0x2a653c）
 * @func 0x2a6504 0x2a653c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2a6398 / png_warning / 0xb65d4
 * 字段偏移 top8: 0x30×1 / 0x54×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6504 ldr r3, [pc, #0x30]
 *   @0x2a6508 push {r4, r5, r6, lr}
 *   @0x2a650c ldr r3, [r3]
 *   @0x2a6510 mov r6, r0
 *   @0x2a6514 mov r5, r3
 *   @0x2a6518 cbz r0, 0x2a6524 <png_chunk_warning+0x20>
 *   @0x2a651c bl 0x2a6398 <png_check_IHDR+0x1e8>
 *   @0x2a6520 mov r0, r6
 *   @0x2a6524 bl 0x2a6474 <png_warning>
 *   @0x2a6528 ldr r2, [sp, #0x54]
 *   @0x2a652c cmp r2, r3
 *   @0x2a6530 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a6534 add sp, #0x58
 *   @0x2a6538 strb r2, [r1, #0x11]
 *
 * ══ §227/561 png_malloc  0x2a6ca0  size 56  14 条（0x2a6ca0..0x2a6cd8）
 * @func 0x2a6ca0 0x2a6cd8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_malloc_default / png_error
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6ca0 push {r3, r4, r5, lr}
 *   @0x2a6ca4 cbnz r0, 0x2a6caa <png_malloc+0xa>
 *   @0x2a6ca8 pop {r3, r4, r5, pc}
 *   @0x2a6cac beq 0x2a6ca6 <png_malloc+0x6>
 *   @0x2a6cb0 smlattlt r11, r12, r2, r3
 *   @0x2a6cb4 blx r3
 *   @0x2a6cb8 bl 0x2a6c90 <png_malloc_default>
 *   @0x2a6cbc cbnz r0, 0x2a6cd2 <png_malloc+0x32>
 *   @0x2a6cc0 sbcseq r3, r11, #48, #2
 *   @0x2a6cc4 bmi 0x2a6ca6 <png_malloc+0x6>
 *   @0x2a6cc8 mov r0, r5
 *   @0x2a6ccc bl 0x2a642c <png_error>
 *   @0x2a6cd0 b 0x2a6ca6 <png_malloc+0x6>
 *   @0x2a6cd4 ldrh r3, [r4, r0]
 *
 * ══ §228/561 jcopy_sample_rows  0x2bc81c  size 56  14 条（0x2bc81c..0x2bc854）
 * @func 0x2bc81c 0x2bc854  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc81c push {r3, r4, r5, r6, r7, lr}
 *   @0x2bc820 add r5, r0, r1, lsl #2
 *   @0x2bc824 ldr r4, [sp, #0x18]
 *   @0x2bc828 add r6, r2, r3, lsl #2
 *   @0x2bc82c ldr r7, [sp, #0x1c]
 *   @0x2bc830 cmp r4, #0
 *   @0x2bc834 pople {r3, r4, r5, r6, r7, pc}
 *   @0x2bc838 ldr r0, [r6], #4
 *   @0x2bc83c mov r2, r7
 *   @0x2bc840 ldr r1, [r5], #4
 *   @0x2bc844 bl 0xb65bc <memcpy@plt>
 *   @0x2bc848 subs r4, r4, #1
 *   @0x2bc84c bne 0x2bc838 <jcopy_sample_rows+0x1c>
 *   @0x2bc850 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §229/561 b2CollideEdgeAndPolygon(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)  0x2de0bc  size 56  14 条（0x2de0bc..0x2de0f4）
 * @func 0x2de0bc 0x2de0f4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2EPCollider::Collide(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)
 * 字段偏移 top8: 0x110×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de0bc push {r4, lr}
 *   @0x2de0c0 sub sp, sp, #264
 *   @0x2de0c4 mov lr, r2
 *   @0x2de0c8 mov r4, r1
 *   @0x2de0cc ldr r12, [sp, #0x110]
 *   @0x2de0d0 mov r1, r0
 *   @0x2de0d4 str r3, [sp]
 *   @0x2de0d8 mov r2, r4
 *   @0x2de0dc add r0, sp, #12
 *   @0x2de0e0 mov r3, lr
 *   @0x2de0e4 str r12, [sp, #0x4]
 *   @0x2de0e8 bl 0x2dd360 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_>
 *   @0x2de0ec add sp, sp, #264
 *   @0x2de0f0 pop {r4, pc}
 *
 * ══ §230/561 b2ChainAndCircleContact::b2ChainAndCircleContact(b2Fixture*, int, b2Fixture*, int)  0x2e1d70  size 56  14 条（0x2e1d70..0x2e1da8）
 * @func 0x2e1d70 0x2e1da8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1d70 push {r4, lr}
 *   @0x2e1d74 sub sp, sp, #8
 *   @0x2e1d78 mov r4, r0
 *   @0x2e1d7c ldr r12, [sp, #0x10]
 *   @0x2e1d80 str r12, [sp]
 *   @0x2e1d84 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2e1d88 ldr r3, [pc, #0x14]
 *   @0x2e1d8c mov r0, r4
 *   @0x2e1d90 ldr r3, [pc, r3]
 *   @0x2e1d94 add r3, r3, #8
 *   @0x2e1d98 str r3, [r4]
 *   @0x2e1d9c add sp, sp, #8
 *   @0x2e1da0 pop {r4, pc}
 *   @0x2e1da4 andseq pc, r0, r0, lsl lr
 *
 * ══ §231/561 b2ChainAndPolygonContact::b2ChainAndPolygonContact(b2Fixture*, int, b2Fixture*, int)  0x2e1efc  size 56  14 条（0x2e1efc..0x2e1f34）
 * @func 0x2e1efc 0x2e1f34  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)
 * 字段偏移 top8: 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1efc push {r4, lr}
 *   @0x2e1f00 sub sp, sp, #8
 *   @0x2e1f04 mov r4, r0
 *   @0x2e1f08 ldr r12, [sp, #0x10]
 *   @0x2e1f0c str r12, [sp]
 *   @0x2e1f10 bl 0x2cc120 <_ZN9b2ContactC2EP9b2FixtureiS1_i>
 *   @0x2e1f14 ldr r3, [pc, #0x14]
 *   @0x2e1f18 mov r0, r4
 *   @0x2e1f1c ldr r3, [pc, r3]
 *   @0x2e1f20 add r3, r3, #8
 *   @0x2e1f24 str r3, [r4]
 *   @0x2e1f28 add sp, sp, #8
 *   @0x2e1f2c pop {r4, pc}
 *   @0x2e1f30 andseq pc, r0, r8, lsl #25
 *
 * ══ §232/561 FT_Face_GetCharVariantIndex  0x2e5d68  size 56  14 条（0x2e5d68..0x2e5da0）
 * @func 0x2e5d68 0x2e5da0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e5d38
 * 字段偏移 top8: 0x4×1 / 0x5c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5d68 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e5d6c mov r6, r2
 *   @0x2e5d70 cbnz r0, 0x2e5d76 <FT_Face_GetCharVariantIndex+0xe>
 *   @0x2e5d74 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e5d78 cmp r5, #0x0
 *   @0x2e5d7c ldr r2, [r5, #0x4]
 *   @0x2e5d80 cmp r2, r3
 *   @0x2e5d84 bl 0x2e5d38 <FT_Set_Charmap+0x3c>
 *   @0x2e5d88 ldr r1, [r4, #0x5c]
 *   @0x2e5d8c beq 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa>
 *   @0x2e5d90 mov r2, r7
 *   @0x2e5d94 mov r3, r6
 *   @0x2e5d98 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e5d9c ldr r3, [r4, #0x14]
 *
 * ══ §233/561 FT_Get_Module  0x2e5ef0  size 56  14 条（0x2e5ef0..0x2e5f28）
 * @func 0x2e5ef0 0x2e5f28  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x467754 / 0xb6574
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5ef0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e5ef4 cbz r0, 0x2e5f1e <FT_Get_Module+0x2e>
 *   @0x2e5ef8 ldr r7, [r0, #0x10]
 *   @0x2e5efc bl 0x467754 <g_RomDisk+0x6ff34>
 *   @0x2e5f00 adcsmi r0, lr, #35389440
 *   @0x2e5f04 bhs 0x2e5f1a <FT_Get_Module+0x2a>
 *   @0x2e5f08 strtmi r4, [r9], -r4, lsl #22
 *   @0x2e5f0c ldr r3, [r4]
 *   @0x2e5f10 blx 0xb6574 <strcmp@plt>
 *   @0x2e5f14 cmp r0, #0x0
 *   @0x2e5f18 b 0x2e5f24 <FT_Get_Module+0x34>
 *   @0x2e5f1c b 0x2e5f24 <FT_Get_Module+0x34>
 *   @0x2e5f20 b 0x2e5f24 <FT_Get_Module+0x34>
 *   @0x2e5f24 mov r0, r4
 *
 * ══ §234/561 FT_Vector_Transform  0x2e6548  size 56  14 条（0x2e6548..0x2e6580）
 * @func 0x2e6548 0x2e6580  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulFix×2
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6548 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e654c mov r4, r0
 *   @0x2e6550 cbz r1, 0x2e657e <FT_Vector_Transform+0x36>
 *   @0x2e6554 ldr r0, [r0]
 *   @0x2e6558 stmdavs r9!, {r0, r3, r4, r5, r6, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e655c mov r6, r0
 *   @0x2e6560 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e6564 ldr r1, [r5, #0x8]
 *   @0x2e6568 ldr r0, [r4]
 *   @0x2e656c stmvs r9!, {r0, r1, r2, r3, r5, r6, r10, r11, r12, sp, lr, pc} ^
 *   @0x2e6570 mov r7, r0
 *   @0x2e6574 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e6578 str r6, [r4]
 *   @0x2e657c str r0, [r4, #0x4]
 *
 * ══ §235/561 _zip_cdir_free(zip_cdir*)  0x2a3bf6  size 54  14 条（0x2a3bf6..0x2a3c2c）
 * @func 0x2a3bf6 0x2a3c2c  size 54  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3bf6 push {r4, r5, r6, lr}
 *   @0x2a3bfa cbz r0, 0x2a3c2a <_Z14_zip_cdir_freeP8zip_cdir+0x34>
 *   @0x2a3bfe movs r6, #0x3c
 *   @0x2a3c02 cmp r5, r3
 *   @0x2a3c06 ldr r0, [r4]
 *   @0x2a3c0a .word 0xf7ff0005
 *   @0x2a3c0e strlo pc, [r1, #-0xfe3]
 *   @0x2a3c12 b 0x2a3c00 <_Z14_zip_cdir_freeP8zip_cdir+0xa>
 *   @0x2a3c16 blx 0xb655c <free@plt>
 *   @0x2a3c1a ldr r0, [r4]
 *   @0x2a3c1e qadd8mi lr, r0, lr
 *   @0x2a3c22 pop.w {r4, r5, r6, lr}
 *   @0x2a3c26 b.w 0x31babc <__udivdi3+0x424>
 *   @0x2a3c2a pop {r4, r5, r6, pc}
 *
 * ══ §236/561 png_write_image  0x2b0510  size 54  14 条（0x2b0510..0x2b0546）
 * @func 0x2b0510 0x2b0546  size 54  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0510 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2b0514 mov r7, r1
 *   @0x2b0518 cbz r0, 0x2b0542 <png_write_image+0x32>
 *   @0x2b051c strhs pc, [r0, #-0x94a]
 *   @0x2b0520 mov r8, r0
 *   @0x2b0524 bge 0x2b0542 <png_write_image+0x32>
 *   @0x2b0528 ldr.w r3, [r6, #0x190]
 *   @0x2b052c cmp r4, r3
 *   @0x2b0530 ldr.w r1, [r7, r4, lsl #2]
 *   @0x2b0534 mov r0, r6
 *   @0x2b0538 strlo pc, [r1], #-3871
 *   @0x2b053c b 0x2b0528 <png_write_image+0x18>
 *   @0x2b0540 b 0x2b0522 <png_write_image+0x12>
 *   @0x2b0544 ldrshlt r8, [r8, -r0]
 *
 * ══ §237/561 ft_hash_str_free  0x2e73a6  size 54  14 条（0x2e73a6..0x2e73dc）
 * @func 0x2e73a6 0x2e73dc  size 54  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×3 / 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e73a6 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e73aa mov r7, r1
 *   @0x2e73ae cbz r0, 0x2e73d8 <ft_hash_str_free+0x32>
 *   @0x2e73b2 strhs r8, [r0, #-0x4]
 *   @0x2e73b6 ldr r6, [r0, #0x14]
 *   @0x2e73ba cmp r5, r8
 *   @0x2e73be beq 0x2e73ce <ft_hash_str_free+0x28>
 *   @0x2e73c2 adds r5, #0x1
 *   @0x2e73c6 .word 0xf846ffb7
 *   @0x2e73ca ldrb r9, [r5, r4, lsl #22]!
 *   @0x2e73ce ldr r1, [r4, #0x14]
 *   @0x2e73d2 movwhs pc, #0xfb1
 *   @0x2e73d6 str r3, [r4, #0x14]
 *   @0x2e73da ldrblt r8, [r7, #0x3f8]!
 *
 * ══ §238/561 FT_GlyphLoader_CreateExtra  0x2e80d0  size 54  14 条（0x2e80d0..0x2e8106）
 * @func 0x2e80d0 0x2e8106  size 54  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc / anon_2e490c+0x38
 * 字段偏移 top8: 0x4×2 / 0xc×2 / 0x10×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e80d0 push {r0, r1, r2, r3, r4, lr}
 *   @0x2e80d4 ldr r3, [r0, #0x4]
 *   @0x2e80d8 add r1, sp, #0xc
 *   @0x2e80dc str r1, [sp, #0x4]
 *   @0x2e80e0 lsls r3, r3, #0x1
 *   @0x2e80e4 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e80e8 ldr r3, [sp, #0xc]
 *   @0x2e80ec cbnz r3, 0x2e8100 <FT_GlyphLoader_CreateExtra+0x30>
 *   @0x2e80f0 strb r3, [r4, #0x10]
 *   @0x2e80f4 add.w r0, r0, r3, lsl #3
 *   @0x2e80f8 str r0, [r4, #0x2c]
 *   @0x2e80fc bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40>
 *   @0x2e8100 ldr r0, [sp, #0xc]
 *   @0x2e8104 pop {r4, pc}
 *
 * ══ §239/561 FT_List_Finalize  0x2e8b24  size 54  14 条（0x2e8b24..0x2e8b5a）
 * @func 0x2e8b24 0x2e8b5a  size 54  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8b24 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e8b28 mov r7, r1
 *   @0x2e8b2c mov r8, r3
 *   @0x2e8b30 cbz r0, 0x2e8b56 <FT_List_Finalize+0x32>
 *   @0x2e8b34 ldr r4, [r0]
 *   @0x2e8b38 ldr.w r9, [r4, #0x4]
 *   @0x2e8b3c ldr r1, [r4, #0x8]
 *   @0x2e8b40 mov r0, r6
 *   @0x2e8b44 blx r7
 *   @0x2e8b48 mov r0, r6
 *   @0x2e8b4c .word 0x464cfbf4
 *   @0x2e8b50 b 0x2e8b36 <FT_List_Finalize+0x12>
 *   @0x2e8b54 str r4, [r5, #0x4]
 *   @0x2e8b58 strdeq r8, r9, [r0], -r8
 *
 * ══ §240/561 GetBufferVertex(int)  0xc8860  size 52  13 条（0xc8860..0xc8894）
 * @func 0xc8860 0xc8894  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetBufferVertex(int)+0x28
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8860 cmp r0, #0
 *   @0xc8864 blt 0xc8888 <_Z15GetBufferVertexi+0x28>
 *   @0xc8868 ldr r3, [pc, #0x20]
 *   @0xc886c add r3, pc, r3
 *   @0xc8870 ldr r2, [r3, #0x4]
 *   @0xc8874 cmp r0, r2
 *   @0xc8878 bge 0xc8888 <_Z15GetBufferVertexi+0x28>
 *   @0xc887c ldr r3, [r3]
 *   @0xc8880 ldr r0, [r3, r0, lsl #2]
 *   @0xc8884 bx lr
 *   @0xc8888 mov r0, #0
 *   @0xc888c bx lr
 *   @0xc8890 eorseq r1, r11, r8, asr #17
 *
 * ══ §241/561 F_Vertex_Begin_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc90d4  size 52  13 条（0xc90d4..0xc9108）
 * @func 0xc90d4 0xc9108  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc90d4 push {r3, r4, r5, lr}
 *   @0xc90d8 mov r1, #0
 *   @0xc90dc ldr r4, [sp, #0x10]
 *   @0xc90e0 mov r0, r4
 *   @0xc90e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc90e8 mov r1, #1
 *   @0xc90ec mov r5, r0
 *   @0xc90f0 mov r0, r4
 *   @0xc90f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc90f8 mov r1, r0
 *   @0xc90fc mov r0, r5
 *   @0xc9100 pop {r3, r4, r5, lr}
 *   @0xc9104 b 0xc9054 <_Z18YYGML_vertex_beginii>
 *
 * ══ §242/561 CountInstances()  0xd40d8  size 52  13 条（0xd40d8..0xd410c）
 * @func 0xd40d8 0xd410c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd40d8 ldr r2, [pc, #0x28]
 *   @0xd40dc mov r0, #0
 *   @0xd40e0 add r2, pc, r2
 *   @0xd40e4 ldr r3, [r2]
 *   @0xd40e8 cmp r3, r2
 *   @0xd40ec beq 0xd4104 <_Z14CountInstancesv+0x2c>
 *   @0xd40f0 ldr r3, [r3]
 *   @0xd40f4 add r0, r0, #1
 *   @0xd40f8 cmp r3, r2
 *   @0xd40fc bne 0xd40f0 <_Z14CountInstancesv+0x18>
 *   @0xd4100 bx lr
 *   @0xd4104 bx lr
 *   @0xd4108 ldrsbteq r6, [r10], -r4
 *
 * ══ §243/561 VM::ResetBreakpoints()  0xd8374  size 52  13 条（0xd8374..0xd83a8）
 * @func 0xd8374 0xd83a8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8374 ldr r2, [pc, #0x28]
 *   @0xd8378 mov r3, #0
 *   @0xd837c mov r12, r3
 *   @0xd8380 mvn r0, #0
 *   @0xd8384 ldr r2, [pc, r2]
 *   @0xd8388 add r1, r2, r3
 *   @0xd838c str r0, [r1, #0x4]
 *   @0xd8390 str r12, [r2, r3]
 *   @0xd8394 add r3, r3, #16
 *   @0xd8398 cmp r3, #4096
 *   @0xd839c bne 0xd8388 <_ZN2VM16ResetBreakpointsEv+0x14>
 *   @0xd83a0 bx lr
 *   @0xd83a4 eorseq r5, r1, r0, ror #18
 *
 * ══ §244/561 CEvent::CEvent()  0xf2d0c  size 52  13 条（0xf2d0c..0xf2d40）
 * @func 0xf2d0c 0xf2d40  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEvent::Clear()
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2d0c ldr r3, [pc, #0x28]
 *   @0xf2d10 mov r2, #0
 *   @0xf2d14 push {r4, lr}
 *   @0xf2d18 ldr r3, [pc, r3]
 *   @0xf2d1c mov r4, r0
 *   @0xf2d20 str r2, [r0, #0x4]
 *   @0xf2d24 str r2, [r0, #0x8]
 *   @0xf2d28 add r3, r3, #8
 *   @0xf2d2c str r3, [r0]
 *   @0xf2d30 bl 0xf2d08 <_ZN6CEvent5ClearEv>
 *   @0xf2d34 mov r0, r4
 *   @0xf2d38 pop {r4, pc}
 *   @0xf2d3c eoreq r11, pc, r8, lsl #2
 *
 * ══ §245/561 CExtensionFile::Clear()  0xf5064  size 52  13 条（0xf5064..0xf5098）
 * @func 0xf5064 0xf5098  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::SetFunctionsCount(int)
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5064 push {r3, r4, r5, lr}
 *   @0xf5068 mov r4, #0
 *   @0xf506c mov r5, r0
 *   @0xf5070 mov r1, r4
 *   @0xf5074 str r4, [r0, #0x4]
 *   @0xf5078 str r4, [r0, #0x8]
 *   @0xf507c str r4, [r0, #0xc]
 *   @0xf5080 str r4, [r0, #0x10]
 *   @0xf5084 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi>
 *   @0xf5088 mov r0, r5
 *   @0xf508c mov r1, r4
 *   @0xf5090 pop {r3, r4, r5, lr}
 *   @0xf5094 b 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi>
 *
 * ══ §246/561 F_PathEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x1088cc  size 52  13 条（0x1088cc..0x108900）
 * @func 0x1088cc 0x108900  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Assign_Path(int, float, float, float, bool, int)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1088cc str lr, [sp, #-0x4]!
 *   @0x1088d0 sub sp, sp, #20
 *   @0x1088d4 mov r0, r1
 *   @0x1088d8 mov r2, #0
 *   @0x1088dc mov r3, #0
 *   @0x1088e0 str r2, [sp]
 *   @0x1088e4 str r3, [sp, #0x4]
 *   @0x1088e8 mvn r1, #0
 *   @0x1088ec str r3, [sp, #0x8]
 *   @0x1088f0 mov r3, #1065353216
 *   @0x1088f4 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi>
 *   @0x1088f8 add sp, sp, #20
 *   @0x1088fc ldr pc, [sp], #4
 *
 * ══ §247/561 F_MpGrid_to_DSGrid(RValue&, CInstance*, CInstance*, int, RValue*)  0x108f4c  size 52  13 条（0x108f4c..0x108f80）
 * @func 0x108f4c 0x108f80  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108f4c push {r3, r4, r5, lr}
 *   @0x108f50 mov r1, #0
 *   @0x108f54 ldr r4, [sp, #0x10]
 *   @0x108f58 mov r0, r4
 *   @0x108f5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108f60 mov r1, #1
 *   @0x108f64 mov r5, r0
 *   @0x108f68 mov r0, r4
 *   @0x108f6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108f70 mov r1, r0
 *   @0x108f74 mov r0, r5
 *   @0x108f78 pop {r3, r4, r5, lr}
 *   @0x108f7c b 0x19c358 <_Z21Motion_Grid_to_dsGridii>
 *
 * ══ §248/561 F_PositionDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1099c8  size 52  13 条（0x1099c8..0x1099fc）
 * @func 0x1099c8 0x1099fc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1099c8 push {r3, r4, r5, lr}
 *   @0x1099cc mov r1, #0
 *   @0x1099d0 ldr r4, [sp, #0x10]
 *   @0x1099d4 mov r0, r4
 *   @0x1099d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1099dc mov r1, #1
 *   @0x1099e0 mov r5, r0
 *   @0x1099e4 mov r0, r4
 *   @0x1099e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1099ec mov r1, r0
 *   @0x1099f0 mov r0, r5
 *   @0x1099f4 pop {r3, r4, r5, lr}
 *   @0x1099f8 b 0x1c9c88 <_Z17Command_DestroyAtff>
 *
 * ══ §249/561 FUNC_double_sort(void const*, void const*)  0x10dc3c  size 52  13 条（0x10dc3c..0x10dc70）
 * @func 0x10dc3c 0x10dc70  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dc3c vldr d6, [r0]
 *   @0x10dc40 vldr d7, [r1]
 *   @0x10dc44 vsub.f64 d7, d6, d7
 *   @0x10dc48 vcmp.f64 d7, #0
 *   @0x10dc4c vmrs APSR_nzcv, fpscr
 *   @0x10dc50 beq 0x10dc68 <_Z16FUNC_double_sortPKvS0_+0x2c>
 *   @0x10dc54 vcmpe.f64 d7, #0
 *   @0x10dc58 vmrs APSR_nzcv, fpscr
 *   @0x10dc5c mvnmi r0, #0
 *   @0x10dc60 movpl r0, #1
 *   @0x10dc64 bx lr
 *   @0x10dc68 mov r0, #0
 *   @0x10dc6c bx lr
 *
 * ══ §250/561 F_Bool(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ec64  size 52  13 条（0x10ec64..0x10ec98）
 * @func 0x10ec64 0x10ec98  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: BOOL_RValue(RValue const*)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ec64 push {r4, lr}
 *   @0x10ec68 mov r4, r0
 *   @0x10ec6c mov r3, #13
 *   @0x10ec70 ldr r0, [sp, #0x8]
 *   @0x10ec74 str r3, [r4, #0xc]
 *   @0x10ec78 bl 0xd1294 <_Z11BOOL_RValuePK6RValue>
 *   @0x10ec7c vmov s15, r0
 *   @0x10ec80 vcvt.f64.u32 d7, s15
 *   @0x10ec84 vmov r0, r1, d7
 *   @0x10ec88 vmov r2, s14
 *   @0x10ec8c mov r3, r1
 *   @0x10ec90 stm r4, {r2, r3}
 *   @0x10ec94 pop {r4, pc}
 *
 * ══ §251/561 YYGML_sign(double)  0x110fb8  size 52  13 条（0x110fb8..0x110fec）
 * @func 0x110fb8 0x110fec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_sign(double)+0x2c
 * 字段偏移 top8: 无
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110fb8 vmov d7, r0, r1
 *   @0x110fbc vcmpe.f64 d7, #0
 *   @0x110fc0 vmrs APSR_nzcv, fpscr
 *   @0x110fc4 vmovlt.f64 d7, #-1.000000e+00
 *   @0x110fc8 blt 0x110fe4 <_Z10YYGML_signd+0x2c>
 *   @0x110fcc vcmp.f64 d7, #0
 *   @0x110fd0 vmrs APSR_nzcv, fpscr
 *   @0x110fd4 moveq r3, #0
 *   @0x110fd8 movne r3, #1
 *   @0x110fdc vmov s14, r3
 *   @0x110fe0 vcvt.f64.s32 d7, s14
 *   @0x110fe4 vmov r0, r1, d7
 *   @0x110fe8 bx lr
 *
 * ══ §252/561 F_DateTimeOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x115dd4  size 52  13 条（0x115dd4..0x115e08）
 * @func 0x115dd4 0x115e08  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / 0xb6718
 * 字段偏移 top8: 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115dd4 push {r4, lr}
 *   @0x115dd8 sub sp, sp, #8
 *   @0x115ddc mov r3, #0
 *   @0x115de0 mov r4, r0
 *   @0x115de4 str r3, [r0, #0xc]
 *   @0x115de8 mov r1, r3
 *   @0x115dec ldr r0, [sp, #0x10]
 *   @0x115df0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115df4 mov r2, sp
 *   @0x115df8 bl 0xb6718 <modf@plt>
 *   @0x115dfc stm r4, {r0, r1}
 *   @0x115e00 add sp, sp, #8
 *   @0x115e04 pop {r4, pc}
 *
 * ══ §253/561 F_DisplayGetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*)  0x119a34  size 52  13 条（0x119a34..0x119a68）
 * @func 0x119a34 0x119a68  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119a34 ldr r3, [pc, #0x28]
 *   @0x119a38 mov r2, #0
 *   @0x119a3c str r2, [r0, #0xc]
 *   @0x119a40 ldr r3, [pc, r3]
 *   @0x119a44 ldrb r3, [r3]
 *   @0x119a48 cmp r3, r2
 *   @0x119a4c strne r2, [r0]
 *   @0x119a50 streq r3, [r0]
 *   @0x119a54 movne r3, #0
 *   @0x119a58 movtne r3, #0x3ff0
 *   @0x119a5c str r3, [r0, #0x4]
 *   @0x119a60 bx lr
 *   @0x119a64 eoreq r4, sp, r0, ror r11
 *
 * ══ §254/561 F_WindowGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x119ac0  size 52  13 条（0x119ac0..0x119af4）
 * @func 0x119ac0 0x119af4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119ac0 ldr r3, [pc, #0x28]
 *   @0x119ac4 mov r2, #0
 *   @0x119ac8 str r2, [r0, #0xc]
 *   @0x119acc ldr r3, [pc, r3]
 *   @0x119ad0 ldrb r3, [r3]
 *   @0x119ad4 cmp r3, r2
 *   @0x119ad8 movne r3, r2
 *   @0x119adc moveq r2, r3
 *   @0x119ae0 movtne r2, #0x3ff0
 *   @0x119ae4 str r3, [r0]
 *   @0x119ae8 str r2, [r0, #0x4]
 *   @0x119aec bx lr
 *   @0x119af0 .word 0x002d4af0
 *
 * ══ §255/561 F_SurfaceGetDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b90  size 52  13 条（0x119b90..0x119bc4）
 * @func 0x119b90 0x119bc4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b90 ldr r3, [pc, #0x28]
 *   @0x119b94 mov r1, #0
 *   @0x119b98 str r1, [r0, #0xc]
 *   @0x119b9c ldr r3, [pc, r3]
 *   @0x119ba0 ldrb r2, [r3]
 *   @0x119ba4 cmp r2, r1
 *   @0x119ba8 movne r2, r1
 *   @0x119bac moveq r3, #0
 *   @0x119bb0 movne r3, r2
 *   @0x119bb4 movteq r3, #0x3ff0
 *   @0x119bb8 stm r0, {r2, r3}
 *   @0x119bbc bx lr
 *   @0x119bc0 eoreq r4, sp, r4, lsr #20
 *
 * ══ §256/561 F_DisplayMouseSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a22c  size 52  13 条（0x11a22c..0x11a260）
 * @func 0x11a22c 0x11a260  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a22c push {r3, r4, r5, lr}
 *   @0x11a230 mov r1, #0
 *   @0x11a234 ldr r4, [sp, #0x10]
 *   @0x11a238 mov r0, r4
 *   @0x11a23c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a240 mov r1, #1
 *   @0x11a244 mov r5, r0
 *   @0x11a248 mov r0, r4
 *   @0x11a24c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a250 mov r1, r0
 *   @0x11a254 mov r0, r5
 *   @0x11a258 pop {r3, r4, r5, lr}
 *   @0x11a25c b 0x17dbb4 <_Z15DisplaySetMouseii>
 *
 * ══ §257/561 F_WindowSetPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a474  size 52  13 条（0x11a474..0x11a4a8）
 * @func 0x11a474 0x11a4a8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a474 push {r3, r4, r5, lr}
 *   @0x11a478 mov r1, #0
 *   @0x11a47c ldr r4, [sp, #0x10]
 *   @0x11a480 mov r0, r4
 *   @0x11a484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a488 mov r1, #1
 *   @0x11a48c mov r5, r0
 *   @0x11a490 mov r0, r4
 *   @0x11a494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a498 mov r1, r0
 *   @0x11a49c mov r0, r5
 *   @0x11a4a0 pop {r3, r4, r5, lr}
 *   @0x11a4a4 b 0x17af38 <_Z22GR_Window_Set_Positionii>
 *
 * ══ §258/561 F_WindowSetSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a4a8  size 52  13 条（0x11a4a8..0x11a4dc）
 * @func 0x11a4a8 0x11a4dc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a4a8 push {r3, r4, r5, lr}
 *   @0x11a4ac mov r1, #0
 *   @0x11a4b0 ldr r4, [sp, #0x10]
 *   @0x11a4b4 mov r0, r4
 *   @0x11a4b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a4bc mov r1, #1
 *   @0x11a4c0 mov r5, r0
 *   @0x11a4c4 mov r0, r4
 *   @0x11a4c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a4cc mov r1, r0
 *   @0x11a4d0 mov r0, r5
 *   @0x11a4d4 pop {r3, r4, r5, lr}
 *   @0x11a4d8 b 0x17af3c <_Z18GR_Window_Set_Sizeii>
 *
 * ══ §259/561 F_WindowMouseSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a7d8  size 52  13 条（0x11a7d8..0x11a80c）
 * @func 0x11a7d8 0x11a80c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a7d8 push {r3, r4, r5, lr}
 *   @0x11a7dc mov r1, #0
 *   @0x11a7e0 ldr r4, [sp, #0x10]
 *   @0x11a7e4 mov r0, r4
 *   @0x11a7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a7ec mov r1, #1
 *   @0x11a7f0 mov r5, r0
 *   @0x11a7f4 mov r0, r4
 *   @0x11a7f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a7fc mov r1, r0
 *   @0x11a800 mov r0, r5
 *   @0x11a804 pop {r3, r4, r5, lr}
 *   @0x11a808 b 0x17af30 <_Z19GR_Window_Mouse_Setii>
 *
 * ══ §260/561 F_WindowViewsMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a884  size 52  13 条（0x11a884..0x11a8b8）
 * @func 0x11a884 0x11a8b8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_X(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a884 mov r3, #0
 *   @0x11a888 push {r4, lr}
 *   @0x11a88c mov r4, r0
 *   @0x11a890 str r3, [r4, #0xc]
 *   @0x11a894 mov r0, r3
 *   @0x11a898 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi>
 *   @0x11a89c vmov s15, r0
 *   @0x11a8a0 vcvt.f64.s32 d7, s15
 *   @0x11a8a4 vmov r0, r1, d7
 *   @0x11a8a8 vmov r2, s14
 *   @0x11a8ac mov r3, r1
 *   @0x11a8b0 stm r4, {r2, r3}
 *   @0x11a8b4 pop {r4, pc}
 *
 * ══ §261/561 F_WindowViewsMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a8b8  size 52  13 条（0x11a8b8..0x11a8ec）
 * @func 0x11a8b8 0x11a8ec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_Y(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a8b8 mov r3, #0
 *   @0x11a8bc push {r4, lr}
 *   @0x11a8c0 mov r4, r0
 *   @0x11a8c4 str r3, [r4, #0xc]
 *   @0x11a8c8 mov r0, r3
 *   @0x11a8cc bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi>
 *   @0x11a8d0 vmov s15, r0
 *   @0x11a8d4 vcvt.f64.s32 d7, s15
 *   @0x11a8d8 vmov r0, r1, d7
 *   @0x11a8dc vmov r2, s14
 *   @0x11a8e0 mov r3, r1
 *   @0x11a8e4 stm r4, {r2, r3}
 *   @0x11a8e8 pop {r4, pc}
 *
 * ══ §262/561 F_DrawSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ac20  size 52  13 条（0x11ac20..0x11ac54）
 * @func 0x11ac20 0x11ac54  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ac20 push {r3, r4, r5, lr}
 *   @0x11ac24 mov r1, #0
 *   @0x11ac28 ldr r4, [sp, #0x10]
 *   @0x11ac2c mov r0, r4
 *   @0x11ac30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ac34 mov r1, #1
 *   @0x11ac38 mov r5, r0
 *   @0x11ac3c mov r0, r4
 *   @0x11ac40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ac44 mov r1, r0
 *   @0x11ac48 mov r0, r5
 *   @0x11ac4c pop {r3, r4, r5, lr}
 *   @0x11ac50 b 0x168304 <_Z20GR_D3D_Set_Blend_Extii>
 *
 * ══ §263/561 F_DrawClearAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ad5c  size 52  13 条（0x11ad5c..0x11ad90）
 * @func 0x11ad5c 0x11ad90  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ad5c push {r3, r4, r5, lr}
 *   @0x11ad60 mov r1, #0
 *   @0x11ad64 ldr r4, [sp, #0x10]
 *   @0x11ad68 mov r0, r4
 *   @0x11ad6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ad70 mov r1, #1
 *   @0x11ad74 mov r5, r0
 *   @0x11ad78 mov r0, r4
 *   @0x11ad7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ad80 mov r1, r0
 *   @0x11ad84 mov r0, r5
 *   @0x11ad88 pop {r3, r4, r5, lr}
 *   @0x11ad8c b 0x16a0a4 <_Z19GR_Draw_Clear_Alphajf>
 *
 * ══ §264/561 F_DrawPoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ad90  size 52  13 条（0x11ad90..0x11adc4）
 * @func 0x11ad90 0x11adc4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ad90 push {r3, r4, r5, lr}
 *   @0x11ad94 mov r1, #0
 *   @0x11ad98 ldr r4, [sp, #0x10]
 *   @0x11ad9c mov r0, r4
 *   @0x11ada0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ada4 mov r1, #1
 *   @0x11ada8 mov r5, r0
 *   @0x11adac mov r0, r4
 *   @0x11adb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11adb4 mov r1, r0
 *   @0x11adb8 mov r0, r5
 *   @0x11adbc pop {r3, r4, r5, lr}
 *   @0x11adc0 b 0x16a0c0 <_Z16YYGML_draw_pointff>
 *
 * ══ §265/561 F_DrawPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b9f4  size 52  13 条（0x11b9f4..0x11ba28）
 * @func 0x11b9f4 0x11ba28  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetPtrOrInt(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b9f4 push {r3, r4, r5, lr}
 *   @0x11b9f8 mov r1, #0
 *   @0x11b9fc ldr r4, [sp, #0x10]
 *   @0x11ba00 mov r0, r4
 *   @0x11ba04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ba08 mov r1, #1
 *   @0x11ba0c mov r5, r0
 *   @0x11ba10 mov r0, r4
 *   @0x11ba14 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11ba18 mov r1, r0
 *   @0x11ba1c mov r0, r5
 *   @0x11ba20 pop {r3, r4, r5, lr}
 *   @0x11ba24 b 0x16b964 <_Z23GR_Draw_Primitive_Beginii>
 *
 * ══ §266/561 F_DrawVertex(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ba2c  size 52  13 条（0x11ba2c..0x11ba60）
 * @func 0x11ba2c 0x11ba60  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ba2c push {r3, r4, r5, lr}
 *   @0x11ba30 mov r1, #0
 *   @0x11ba34 ldr r4, [sp, #0x10]
 *   @0x11ba38 mov r0, r4
 *   @0x11ba3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ba40 mov r1, #1
 *   @0x11ba44 mov r5, r0
 *   @0x11ba48 mov r0, r4
 *   @0x11ba4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ba50 mov r1, r0
 *   @0x11ba54 mov r0, r5
 *   @0x11ba58 pop {r3, r4, r5, lr}
 *   @0x11ba5c b 0x16ba58 <_Z14GR_Draw_Vertexff>
 *
 * ══ §267/561 F_TextureSetInterpolationExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bc74  size 52  13 条（0x11bc74..0x11bca8）
 * @func 0x11bc74 0x11bca8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bc74 push {r3, r4, r5, lr}
 *   @0x11bc78 mov r1, #0
 *   @0x11bc7c ldr r4, [sp, #0x10]
 *   @0x11bc80 mov r0, r4
 *   @0x11bc84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bc88 mov r1, #1
 *   @0x11bc8c mov r5, r0
 *   @0x11bc90 mov r0, r4
 *   @0x11bc94 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11bc98 mov r1, r0
 *   @0x11bc9c mov r0, r5
 *   @0x11bca0 pop {r3, r4, r5, lr}
 *   @0x11bca4 b 0x1687d4 <_Z36GR_D3D_Set_Texture_Interpolation_Extib>
 *
 * ══ §268/561 F_TextureSetRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bcd8  size 52  13 条（0x11bcd8..0x11bd0c）
 * @func 0x11bcd8 0x11bd0c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bcd8 push {r3, r4, r5, lr}
 *   @0x11bcdc mov r1, #0
 *   @0x11bce0 ldr r4, [sp, #0x10]
 *   @0x11bce4 mov r0, r4
 *   @0x11bce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bcec mov r1, #1
 *   @0x11bcf0 mov r5, r0
 *   @0x11bcf4 mov r0, r4
 *   @0x11bcf8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11bcfc mov r1, r0
 *   @0x11bd00 mov r0, r5
 *   @0x11bd04 pop {r3, r4, r5, lr}
 *   @0x11bd08 b 0x168934 <_Z29GR_D3D_Set_Texture_Repeat_Extib>
 *
 * ══ §269/561 F_TextureSetPriority(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bd24  size 52  13 条（0x11bd24..0x11bd58）
 * @func 0x11bd24 0x11bd58  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetPtrOrInt(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bd24 push {r3, r4, r5, lr}
 *   @0x11bd28 mov r1, #0
 *   @0x11bd2c ldr r4, [sp, #0x10]
 *   @0x11bd30 mov r0, r4
 *   @0x11bd34 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11bd38 mov r1, #1
 *   @0x11bd3c mov r5, r0
 *   @0x11bd40 mov r0, r4
 *   @0x11bd44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bd48 mov r1, r0
 *   @0x11bd4c mov r0, r5
 *   @0x11bd50 pop {r3, r4, r5, lr}
 *   @0x11bd54 b 0x1742bc <_Z23GR_Texture_Set_Priorityii>
 *
 * ══ §270/561 F_ShowInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x12631c  size 52  13 条（0x12631c..0x126350）
 * @func 0x12631c 0x126350  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12631c push {r3, lr}
 *   @0x126320 ldr r3, [pc, #0x20]
 *   @0x126324 ldr r1, [pc, #0x20]
 *   @0x126328 ldr r3, [pc, r3]
 *   @0x12632c add r1, pc, r1
 *   @0x126330 ldr r0, [r3]
 *   @0x126334 ldr r3, [r0]
 *   @0x126338 ldr r3, [r3, #0xc]
 *   @0x12633c blx r3
 *   @0x126340 pop {r3, lr}
 *   @0x126344 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126348 eoreq r7, r12, r12, ror #7
 *   @0x12634c .word 0x00215dfc
 *
 * ══ §271/561 F_HighscoreAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x126890  size 52  13 条（0x126890..0x1268c4）
 * @func 0x126890 0x1268c4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126890 push {r3, r4, r5, lr}
 *   @0x126894 mov r1, #0
 *   @0x126898 ldr r4, [sp, #0x10]
 *   @0x12689c mov r0, r4
 *   @0x1268a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1268a4 mov r1, #1
 *   @0x1268a8 mov r5, r0
 *   @0x1268ac mov r0, r4
 *   @0x1268b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1268b4 mov r1, r0
 *   @0x1268b8 mov r0, r5
 *   @0x1268bc pop {r3, r4, r5, lr}
 *   @0x1268c0 b 0x1dc318 <_Z13HighScore_AddPKci>
 *
 * ══ §272/561 F_MouseWheelUp(RValue&, CInstance*, CInstance*, int, RValue*)  0x126df8  size 52  13 条（0x126df8..0x126e2c）
 * @func 0x126df8 0x126e2c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Wheel_Up(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126df8 mov r3, #0
 *   @0x126dfc push {r4, lr}
 *   @0x126e00 mov r4, r0
 *   @0x126e04 str r3, [r4, #0xc]
 *   @0x126e08 mov r0, r3
 *   @0x126e0c bl 0x18c168 <_Z11IO_Wheel_Upi>
 *   @0x126e10 vmov s15, r0
 *   @0x126e14 vcvt.f64.u32 d7, s15
 *   @0x126e18 vmov r0, r1, d7
 *   @0x126e1c vmov r2, s14
 *   @0x126e20 mov r3, r1
 *   @0x126e24 stm r4, {r2, r3}
 *   @0x126e28 pop {r4, pc}
 *
 * ══ §273/561 F_MouseWheelDown(RValue&, CInstance*, CInstance*, int, RValue*)  0x126e2c  size 52  13 条（0x126e2c..0x126e60）
 * @func 0x126e2c 0x126e60  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Wheel_Down(int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126e2c mov r3, #0
 *   @0x126e30 push {r4, lr}
 *   @0x126e34 mov r4, r0
 *   @0x126e38 str r3, [r4, #0xc]
 *   @0x126e3c mov r0, r3
 *   @0x126e40 bl 0x18c18c <_Z13IO_Wheel_Downi>
 *   @0x126e44 vmov s15, r0
 *   @0x126e48 vcvt.f64.u32 d7, s15
 *   @0x126e4c vmov r0, r1, d7
 *   @0x126e50 vmov r2, s14
 *   @0x126e54 mov r3, r1
 *   @0x126e58 stm r4, {r2, r3}
 *   @0x126e5c pop {r4, pc}
 *
 * ══ §274/561 F_KeyboardSetMap(RValue&, CInstance*, CInstance*, int, RValue*)  0x12734c  size 52  13 条（0x12734c..0x127380）
 * @func 0x12734c 0x127380  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12734c push {r3, r4, r5, lr}
 *   @0x127350 mov r1, #0
 *   @0x127354 ldr r4, [sp, #0x10]
 *   @0x127358 mov r0, r4
 *   @0x12735c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127360 mov r1, #1
 *   @0x127364 mov r5, r0
 *   @0x127368 mov r0, r4
 *   @0x12736c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127370 mov r1, r0
 *   @0x127374 mov r0, r5
 *   @0x127378 pop {r3, r4, r5, lr}
 *   @0x12737c b 0x18c2fc <_Z13IO_Keymap_Setii>
 *
 * ══ §275/561 F_PartTypeColor1(RValue&, CInstance*, CInstance*, int, RValue*)  0x12954c  size 52  13 条（0x12954c..0x129580）
 * @func 0x12954c 0x129580  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12954c push {r3, r4, r5, lr}
 *   @0x129550 mov r1, #0
 *   @0x129554 ldr r4, [sp, #0x10]
 *   @0x129558 mov r0, r4
 *   @0x12955c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129560 mov r1, #1
 *   @0x129564 mov r5, r0
 *   @0x129568 mov r0, r4
 *   @0x12956c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129570 mov r1, r0
 *   @0x129574 mov r0, r5
 *   @0x129578 pop {r3, r4, r5, lr}
 *   @0x12957c b 0x1a359c <_Z19ParticleType_Color1ij>
 *
 * ══ §276/561 F_PartTypeBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1296fc  size 52  13 条（0x1296fc..0x129730）
 * @func 0x1296fc 0x129730  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1296fc push {r3, r4, r5, lr}
 *   @0x129700 mov r1, #0
 *   @0x129704 ldr r4, [sp, #0x10]
 *   @0x129708 mov r0, r4
 *   @0x12970c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129710 mov r1, #1
 *   @0x129714 mov r5, r0
 *   @0x129718 mov r0, r4
 *   @0x12971c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129720 mov r1, r0
 *   @0x129724 mov r0, r5
 *   @0x129728 pop {r3, r4, r5, lr}
 *   @0x12972c b 0x1a373c <_Z18ParticleType_Blendib>
 *
 * ══ §277/561 F_PartSystemDrawOrder(RValue&, CInstance*, CInstance*, int, RValue*)  0x129964  size 52  13 条（0x129964..0x129998）
 * @func 0x129964 0x129998  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129964 push {r3, r4, r5, lr}
 *   @0x129968 mov r1, #0
 *   @0x12996c ldr r4, [sp, #0x10]
 *   @0x129970 mov r0, r4
 *   @0x129974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129978 mov r1, #1
 *   @0x12997c mov r5, r0
 *   @0x129980 mov r0, r4
 *   @0x129984 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129988 mov r1, r0
 *   @0x12998c mov r0, r5
 *   @0x129990 pop {r3, r4, r5, lr}
 *   @0x129994 b 0x1a47a0 <_Z24ParticleSystem_DrawOrderib>
 *
 * ══ §278/561 F_PartSystemDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x129998  size 52  13 条（0x129998..0x1299cc）
 * @func 0x129998 0x1299cc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129998 push {r3, r4, r5, lr}
 *   @0x12999c mov r1, #0
 *   @0x1299a0 ldr r4, [sp, #0x10]
 *   @0x1299a4 mov r0, r4
 *   @0x1299a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1299ac mov r1, #1
 *   @0x1299b0 mov r5, r0
 *   @0x1299b4 mov r0, r4
 *   @0x1299b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1299bc mov r1, r0
 *   @0x1299c0 mov r0, r5
 *   @0x1299c4 pop {r3, r4, r5, lr}
 *   @0x1299c8 b 0x1a47d4 <_Z20ParticleSystem_Depthif>
 *
 * ══ §279/561 F_PartSystemAutomaticUpdate(RValue&, CInstance*, CInstance*, int, RValue*)  0x129a14  size 52  13 条（0x129a14..0x129a48）
 * @func 0x129a14 0x129a48  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129a14 push {r3, r4, r5, lr}
 *   @0x129a18 mov r1, #0
 *   @0x129a1c ldr r4, [sp, #0x10]
 *   @0x129a20 mov r0, r4
 *   @0x129a24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129a28 mov r1, #1
 *   @0x129a2c mov r5, r0
 *   @0x129a30 mov r0, r4
 *   @0x129a34 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129a38 mov r1, r0
 *   @0x129a3c mov r0, r5
 *   @0x129a40 pop {r3, r4, r5, lr}
 *   @0x129a44 b 0x1a48d0 <_Z30ParticleSystem_AutomaticUpdateib>
 *
 * ══ §280/561 F_PartSystemAutomaticDraw(RValue&, CInstance*, CInstance*, int, RValue*)  0x129a48  size 52  13 条（0x129a48..0x129a7c）
 * @func 0x129a48 0x129a7c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129a48 push {r3, r4, r5, lr}
 *   @0x129a4c mov r1, #0
 *   @0x129a50 ldr r4, [sp, #0x10]
 *   @0x129a54 mov r0, r4
 *   @0x129a58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129a5c mov r1, #1
 *   @0x129a60 mov r5, r0
 *   @0x129a64 mov r0, r4
 *   @0x129a68 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x129a6c mov r1, r0
 *   @0x129a70 mov r0, r5
 *   @0x129a74 pop {r3, r4, r5, lr}
 *   @0x129a78 b 0x1a4904 <_Z28ParticleSystem_AutomaticDrawib>
 *
 * ══ §281/561 F_PartEmitterDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x129c38  size 52  13 条（0x129c38..0x129c6c）
 * @func 0x129c38 0x129c6c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129c38 push {r3, r4, r5, lr}
 *   @0x129c3c mov r1, #0
 *   @0x129c40 ldr r4, [sp, #0x10]
 *   @0x129c44 mov r0, r4
 *   @0x129c48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129c4c mov r1, #1
 *   @0x129c50 mov r5, r0
 *   @0x129c54 mov r0, r4
 *   @0x129c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129c5c mov r1, r0
 *   @0x129c60 mov r0, r5
 *   @0x129c64 pop {r3, r4, r5, lr}
 *   @0x129c68 b 0x1a38ac <_Z30ParticleSystem_Emitter_Destroyii>
 *
 * ══ §282/561 F_PartEmitterClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x129cd8  size 52  13 条（0x129cd8..0x129d0c）
 * @func 0x129cd8 0x129d0c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129cd8 push {r3, r4, r5, lr}
 *   @0x129cdc mov r1, #0
 *   @0x129ce0 ldr r4, [sp, #0x10]
 *   @0x129ce4 mov r0, r4
 *   @0x129ce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129cec mov r1, #1
 *   @0x129cf0 mov r5, r0
 *   @0x129cf4 mov r0, r4
 *   @0x129cf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129cfc mov r1, r0
 *   @0x129d00 mov r0, r5
 *   @0x129d04 pop {r3, r4, r5, lr}
 *   @0x129d08 b 0x1a38ec <_Z28ParticleSystem_Emitter_Clearii>
 *
 * ══ §283/561 F_FontAddGetEnableAA(RValue&, CInstance*, CInstance*, int, RValue*)  0x12a9a0  size 52  13 条（0x12a9a0..0x12a9d4）
 * @func 0x12a9a0 0x12a9d4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12a9a0 ldr r3, [pc, #0x28]
 *   @0x12a9a4 mov r2, #0
 *   @0x12a9a8 str r2, [r0, #0xc]
 *   @0x12a9ac ldr r3, [pc, r3]
 *   @0x12a9b0 ldrb r3, [r3]
 *   @0x12a9b4 cmp r3, r2
 *   @0x12a9b8 movne r3, r2
 *   @0x12a9bc moveq r2, r3
 *   @0x12a9c0 movtne r2, #0x3ff0
 *   @0x12a9c4 str r3, [r0]
 *   @0x12a9c8 str r2, [r0, #0x4]
 *   @0x12a9cc bx lr
 *   @0x12a9d0 eoreq r3, r12, r12, lsr #9
 *
 * ══ §284/561 F_FontGetFontName(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cd58  size 52  13 条（0x12cd58..0x12cd8c）
 * @func 0x12cd58 0x12cd8c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Data(int) / CFontGM::GetName()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cd58 push {r4, lr}
 *   @0x12cd5c mov r1, #0
 *   @0x12cd60 mov r4, r0
 *   @0x12cd64 ldr r0, [sp, #0x8]
 *   @0x12cd68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cd6c bl 0xfa3fc <_Z9Font_Datai>
 *   @0x12cd70 subs r1, r0, #0
 *   @0x12cd74 beq 0x12cd80 <_Z17F_FontGetFontNameR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x12cd78 bl 0xf93c8 <_ZN7CFontGM7GetNameEv>
 *   @0x12cd7c mov r1, r0
 *   @0x12cd80 mov r0, r4
 *   @0x12cd84 pop {r4, lr}
 *   @0x12cd88 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §285/561 F_ScriptGetText(RValue&, CInstance*, CInstance*, int, RValue*)  0x12de10  size 52  13 条（0x12de10..0x12de44）
 * @func 0x12de10 0x12de44  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Script_Data(int) / CScript::GetText()
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12de10 push {r4, lr}
 *   @0x12de14 mov r1, #0
 *   @0x12de18 mov r4, r0
 *   @0x12de1c ldr r0, [sp, #0x8]
 *   @0x12de20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12de24 bl 0x1e069c <_Z11Script_Datai>
 *   @0x12de28 subs r1, r0, #0
 *   @0x12de2c beq 0x12de38 <_Z15F_ScriptGetTextR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x12de30 bl 0x1dfe94 <_ZN7CScript7GetTextEv>
 *   @0x12de34 mov r1, r0
 *   @0x12de38 mov r0, r4
 *   @0x12de3c pop {r4, lr}
 *   @0x12de40 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §286/561 F_RoomSetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e6a8  size 52  13 条（0x12e6a8..0x12e6dc）
 * @func 0x12e6a8 0x12e6dc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Room_Data(int)
 * 字段偏移 top8: 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e6a8 push {r3, r4, r5, lr}
 *   @0x12e6ac mov r1, #0
 *   @0x12e6b0 ldr r4, [sp, #0x10]
 *   @0x12e6b4 mov r0, r4
 *   @0x12e6b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e6bc bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e6c0 subs r5, r0, #0
 *   @0x12e6c4 popeq {r3, r4, r5, pc}
 *   @0x12e6c8 mov r0, r4
 *   @0x12e6cc mov r1, #1
 *   @0x12e6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e6d4 str r0, [r5, #0x14]
 *   @0x12e6d8 pop {r3, r4, r5, pc}
 *
 * ══ §287/561 F_RoomSetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e6dc  size 52  13 条（0x12e6dc..0x12e710）
 * @func 0x12e6dc 0x12e710  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Room_Data(int)
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e6dc push {r3, r4, r5, lr}
 *   @0x12e6e0 mov r1, #0
 *   @0x12e6e4 ldr r4, [sp, #0x10]
 *   @0x12e6e8 mov r0, r4
 *   @0x12e6ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e6f0 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e6f4 subs r5, r0, #0
 *   @0x12e6f8 popeq {r3, r4, r5, pc}
 *   @0x12e6fc mov r0, r4
 *   @0x12e700 mov r1, #1
 *   @0x12e704 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e708 str r0, [r5, #0x10]
 *   @0x12e70c pop {r3, r4, r5, pc}
 *
 * ══ §288/561 F_RoomSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e710  size 52  13 条（0x12e710..0x12e744）
 * @func 0x12e710 0x12e744  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e710 push {r3, r4, r5, lr}
 *   @0x12e714 mov r1, #0
 *   @0x12e718 ldr r4, [sp, #0x10]
 *   @0x12e71c mov r0, r4
 *   @0x12e720 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e724 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e728 subs r5, r0, #0
 *   @0x12e72c popeq {r3, r4, r5, pc}
 *   @0x12e730 mov r0, r4
 *   @0x12e734 mov r1, #1
 *   @0x12e738 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e73c strb r0, [r5, #0x18]
 *   @0x12e740 pop {r3, r4, r5, pc}
 *
 * ══ §289/561 F_RoomSetViewEnabled(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e788  size 52  13 条（0x12e788..0x12e7bc）
 * @func 0x12e788 0x12e7bc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Room_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e788 push {r3, r4, r5, lr}
 *   @0x12e78c mov r1, #0
 *   @0x12e790 ldr r4, [sp, #0x10]
 *   @0x12e794 mov r0, r4
 *   @0x12e798 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e79c bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e7a0 subs r5, r0, #0
 *   @0x12e7a4 popeq {r3, r4, r5, pc}
 *   @0x12e7a8 mov r0, r4
 *   @0x12e7ac mov r1, #1
 *   @0x12e7b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e7b4 strb r0, [r5, #0x44]
 *   @0x12e7b8 pop {r3, r4, r5, pc}
 *
 * ══ §290/561 F_CDPlay(RValue&, CInstance*, CInstance*, int, RValue*)  0x133878  size 52  13 条（0x133878..0x1338ac）
 * @func 0x133878 0x1338ac  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133878 push {r3, r4, r5, lr}
 *   @0x13387c mov r1, #0
 *   @0x133880 ldr r4, [sp, #0x10]
 *   @0x133884 mov r0, r4
 *   @0x133888 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13388c mov r1, #1
 *   @0x133890 mov r5, r0
 *   @0x133894 mov r0, r4
 *   @0x133898 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13389c mov r1, r0
 *   @0x1338a0 mov r0, r5
 *   @0x1338a4 pop {r3, r4, r5, lr}
 *   @0x1338a8 b 0x2148a4 <_Z7CD_Playii>
 *
 * ══ §291/561 F_SoundStopAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x133b14  size 52  13 条（0x133b14..0x133b48）
 * @func 0x133b14 0x133b48  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133b14 ldr r3, [pc, #0x24]
 *   @0x133b18 ldr r3, [pc, r3]
 *   @0x133b1c ldrb r3, [r3]
 *   @0x133b20 cmp r3, #0
 *   @0x133b24 bxne lr
 *   @0x133b28 ldr r3, [pc, #0x14]
 *   @0x133b2c ldr r3, [pc, r3]
 *   @0x133b30 ldrb r3, [r3]
 *   @0x133b34 cmp r3, #0
 *   @0x133b38 bxne lr
 *   @0x133b3c b 0x21ee90 <_Z11SND_StopAllv>
 *   @0x133b40 eoreq r11, r11, r8, lsl r2
 *   @0x133b44 eoreq r11, r11, r0, lsr #10
 *
 * ══ §292/561 F_AudioDestroySyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x135f74  size 52  13 条（0x135f74..0x135fa8）
 * @func 0x135f74 0x135fa8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135f74 push {r3, lr}
 *   @0x135f78 ldr r3, [pc, #0x24]
 *   @0x135f7c ldr r2, [sp, #0x8]
 *   @0x135f80 ldr r3, [pc, r3]
 *   @0x135f84 ldrb r1, [r3]
 *   @0x135f88 cmp r1, #0
 *   @0x135f8c popne {r3, pc}
 *   @0x135f90 str r1, [r0, #0xc]
 *   @0x135f94 mov r0, r2
 *   @0x135f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135f9c pop {r3, lr}
 *   @0x135fa0 b 0x21d3f8 <_Z22Audio_DestroySyncGroupi>
 *   @0x135fa4 eoreq r9, r11, r12, asr #1
 *
 * ══ §293/561 F_AudioStartSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x13600c  size 52  13 条（0x13600c..0x136040）
 * @func 0x13600c 0x136040  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13600c push {r3, lr}
 *   @0x136010 ldr r3, [pc, #0x24]
 *   @0x136014 ldr r2, [sp, #0x8]
 *   @0x136018 ldr r3, [pc, r3]
 *   @0x13601c ldrb r1, [r3]
 *   @0x136020 cmp r1, #0
 *   @0x136024 popne {r3, pc}
 *   @0x136028 str r1, [r0, #0xc]
 *   @0x13602c mov r0, r2
 *   @0x136030 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136034 pop {r3, lr}
 *   @0x136038 b 0x21d40c <_Z20Audio_StartSyncGroupi>
 *   @0x13603c eoreq r9, r11, r4, lsr r0
 *
 * ══ §294/561 F_AudioStopSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x136040  size 52  13 条（0x136040..0x136074）
 * @func 0x136040 0x136074  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136040 push {r3, lr}
 *   @0x136044 ldr r3, [pc, #0x24]
 *   @0x136048 ldr r2, [sp, #0x8]
 *   @0x13604c ldr r3, [pc, r3]
 *   @0x136050 ldrb r1, [r3]
 *   @0x136054 cmp r1, #0
 *   @0x136058 popne {r3, pc}
 *   @0x13605c str r1, [r0, #0xc]
 *   @0x136060 mov r0, r2
 *   @0x136064 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136068 pop {r3, lr}
 *   @0x13606c b 0x21d420 <_Z19Audio_StopSyncGroupi>
 *   @0x136070 eoreq r9, r11, r0
 *
 * ══ §295/561 F_AudioPauseSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x136074  size 52  13 条（0x136074..0x1360a8）
 * @func 0x136074 0x1360a8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136074 push {r3, lr}
 *   @0x136078 ldr r3, [pc, #0x24]
 *   @0x13607c ldr r2, [sp, #0x8]
 *   @0x136080 ldr r3, [pc, r3]
 *   @0x136084 ldrb r1, [r3]
 *   @0x136088 cmp r1, #0
 *   @0x13608c popne {r3, pc}
 *   @0x136090 str r1, [r0, #0xc]
 *   @0x136094 mov r0, r2
 *   @0x136098 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13609c pop {r3, lr}
 *   @0x1360a0 b 0x21d604 <_Z20Audio_PauseSyncGroupi>
 *   @0x1360a4 eoreq r8, r11, r12, asr #31
 *
 * ══ §296/561 F_AudioResumeSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x1360a8  size 52  13 条（0x1360a8..0x1360dc）
 * @func 0x1360a8 0x1360dc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1360a8 push {r3, lr}
 *   @0x1360ac ldr r3, [pc, #0x24]
 *   @0x1360b0 ldr r2, [sp, #0x8]
 *   @0x1360b4 ldr r3, [pc, r3]
 *   @0x1360b8 ldrb r1, [r3]
 *   @0x1360bc cmp r1, #0
 *   @0x1360c0 popne {r3, pc}
 *   @0x1360c4 str r1, [r0, #0xc]
 *   @0x1360c8 mov r0, r2
 *   @0x1360cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1360d0 pop {r3, lr}
 *   @0x1360d4 b 0x21d618 <_Z21Audio_ResumeSyncGroupi>
 *   @0x1360d8 mlaeq r11, r8, pc, r8
 *
 * ══ §297/561 F_AudioSyncGroupDebug(RValue&, CInstance*, CInstance*, int, RValue*)  0x136128  size 52  13 条（0x136128..0x13615c）
 * @func 0x136128 0x13615c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136128 push {r3, lr}
 *   @0x13612c ldr r3, [pc, #0x24]
 *   @0x136130 ldr r2, [sp, #0x8]
 *   @0x136134 ldr r3, [pc, r3]
 *   @0x136138 ldrb r1, [r3]
 *   @0x13613c cmp r1, #0
 *   @0x136140 popne {r3, pc}
 *   @0x136144 str r1, [r0, #0xc]
 *   @0x136148 mov r0, r2
 *   @0x13614c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136150 pop {r3, lr}
 *   @0x136154 b 0x21d68c <_Z20Audio_SyncGroupDebugi>
 *   @0x136158 eoreq r8, r11, r8, lsl pc
 *
 * ══ §298/561 F_IniOpenFromString(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ba78  size 52  13 条（0x13ba78..0x13baac）
 * @func 0x13ba78 0x13baac  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ba78 push {r3, lr}
 *   @0x13ba7c mov r1, #0
 *   @0x13ba80 ldr r0, [sp, #0x8]
 *   @0x13ba84 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13ba88 cmp r0, #0
 *   @0x13ba8c beq 0x13ba98 <_Z19F_IniOpenFromStringR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x13ba90 pop {r3, lr}
 *   @0x13ba94 b 0x13ba08 <_Z26YYGML_ini_open_from_stringPKc>
 *   @0x13ba98 ldr r0, [pc, #0x8]
 *   @0x13ba9c pop {r3, lr}
 *   @0x13baa0 add r0, pc, r0
 *   @0x13baa4 b 0x13ba08 <_Z26YYGML_ini_open_from_stringPKc>
 *   @0x13baa8 mulseq pc, r6, r0
 *
 * ══ §299/561 F_ActionPathEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e0a8  size 52  13 条（0x13e0a8..0x13e0dc）
 * @func 0x13e0a8 0x13e0dc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Assign_Path(int, float, float, float, bool, int)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e0a8 str lr, [sp, #-0x4]!
 *   @0x13e0ac sub sp, sp, #20
 *   @0x13e0b0 mov r0, r1
 *   @0x13e0b4 mov r2, #0
 *   @0x13e0b8 mov r3, #0
 *   @0x13e0bc str r2, [sp]
 *   @0x13e0c0 str r3, [sp, #0x4]
 *   @0x13e0c4 mvn r1, #0
 *   @0x13e0c8 str r3, [sp, #0x8]
 *   @0x13e0cc mov r3, #1065353216
 *   @0x13e0d0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi>
 *   @0x13e0d4 add sp, sp, #20
 *   @0x13e0d8 ldr pc, [sp], #4
 *
 * ══ §300/561 F_ActionCDPlay(RValue&, CInstance*, CInstance*, int, RValue*)  0x140104  size 52  13 条（0x140104..0x140138）
 * @func 0x140104 0x140138  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140104 push {r3, r4, r5, lr}
 *   @0x140108 mov r1, #0
 *   @0x14010c ldr r4, [sp, #0x10]
 *   @0x140110 mov r0, r4
 *   @0x140114 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140118 mov r1, #1
 *   @0x14011c mov r5, r0
 *   @0x140120 mov r0, r4
 *   @0x140124 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140128 mov r1, r0
 *   @0x14012c mov r0, r5
 *   @0x140130 pop {r3, r4, r5, lr}
 *   @0x140134 b 0x2148a4 <_Z7CD_Playii>
 *
 * ══ §301/561 F_ActionSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x141b84  size 52  13 条（0x141b84..0x141bb8）
 * @func 0x141b84 0x141bb8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141b84 push {r3, r4, r5, lr}
 *   @0x141b88 mov r1, #0
 *   @0x141b8c ldr r4, [sp, #0x10]
 *   @0x141b90 mov r0, r4
 *   @0x141b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141b98 mov r1, #1
 *   @0x141b9c mov r5, r0
 *   @0x141ba0 mov r0, r4
 *   @0x141ba4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x141ba8 mov r1, r0
 *   @0x141bac mov r0, r5
 *   @0x141bb0 pop {r3, r4, r5, lr}
 *   @0x141bb4 b 0x141b00 <_Z18YYGML_action_soundib>
 *
 * ══ §302/561 F_D3DMatrixStackPop(RValue&, CInstance*, CInstance*, int, RValue*)  0x1439b4  size 52  13 条（0x1439b4..0x1439e8）
 * @func 0x1439b4 0x1439e8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_D3DMatrixStackPop(RValue&, CInstance*, CInstance*, int, RValue*)+0x28
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1439b4 ldr r12, [pc, #0x28]
 *   @0x1439b8 push {r4, r5}
 *   @0x1439bc ldr r12, [pc, r12]
 *   @0x1439c0 ldr r4, [r12]
 *   @0x1439c4 sub r4, r4, #1
 *   @0x1439c8 str r4, [r12]
 *   @0x1439cc cmp r4, #0
 *   @0x1439d0 blt 0x1439dc <_Z19F_D3DMatrixStackPopR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1439d4 pop {r4, r5}
 *   @0x1439d8 bx lr
 *   @0x1439dc pop {r4, r5}
 *   @0x1439e0 b 0x143948 <_Z21F_D3DMatrixStackClearR6RValueP9CInstanceS2_iPS_>
 *   @0x1439e4 eoreq r11, r10, r8, asr #24
 *
 * ══ §303/561 F_D3DGetLighting(RValue&, CInstance*, CInstance*, int, RValue*)  0x143a44  size 52  13 条（0x143a44..0x143a78）
 * @func 0x143a44 0x143a78  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143a44 ldr r3, [pc, #0x28]
 *   @0x143a48 mov r2, #0
 *   @0x143a4c str r2, [r0, #0xc]
 *   @0x143a50 ldr r3, [pc, r3]
 *   @0x143a54 ldrb r3, [r3]
 *   @0x143a58 cmp r3, r2
 *   @0x143a5c movne r3, r2
 *   @0x143a60 moveq r2, r3
 *   @0x143a64 movtne r2, #0x3ff0
 *   @0x143a68 str r3, [r0]
 *   @0x143a6c str r2, [r0, #0x4]
 *   @0x143a70 bx lr
 *   @0x143a74 eoreq r11, r10, r0, asr #23
 *
 * ══ §304/561 F_D3DStart(RValue&, CInstance*, CInstance*, int, RValue*)  0x143ab8  size 52  13 条（0x143ab8..0x143aec）
 * @func 0x143ab8 0x143aec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Set_Mode(bool)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143ab8 push {r4, lr}
 *   @0x143abc mov r4, r0
 *   @0x143ac0 mov r3, #0
 *   @0x143ac4 mov r0, #1
 *   @0x143ac8 str r3, [r4, #0xc]
 *   @0x143acc bl 0x163170 <_Z14GR_3D_Set_Modeb>
 *   @0x143ad0 vmov s15, r0
 *   @0x143ad4 vcvt.f64.u32 d7, s15
 *   @0x143ad8 vmov r0, r1, d7
 *   @0x143adc vmov r2, s14
 *   @0x143ae0 mov r3, r1
 *   @0x143ae4 stm r4, {r2, r3}
 *   @0x143ae8 pop {r4, pc}
 *
 * ══ §305/561 F_D3DEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x143aec  size 52  13 条（0x143aec..0x143b20）
 * @func 0x143aec 0x143b20  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Set_Mode(bool)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143aec mov r3, #0
 *   @0x143af0 push {r4, lr}
 *   @0x143af4 mov r4, r0
 *   @0x143af8 str r3, [r4, #0xc]
 *   @0x143afc mov r0, r3
 *   @0x143b00 bl 0x163170 <_Z14GR_3D_Set_Modeb>
 *   @0x143b04 vmov s15, r0
 *   @0x143b08 vcvt.f64.u32 d7, s15
 *   @0x143b0c vmov r0, r1, d7
 *   @0x143b10 vmov r2, s14
 *   @0x143b14 mov r3, r1
 *   @0x143b18 stm r4, {r2, r3}
 *   @0x143b1c pop {r4, pc}
 *
 * ══ §306/561 F_D3DPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c54  size 52  13 条（0x143c54..0x143c88）
 * @func 0x143c54 0x143c88  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetPtrOrInt(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c54 push {r3, r4, r5, lr}
 *   @0x143c58 mov r1, #0
 *   @0x143c5c ldr r4, [sp, #0x10]
 *   @0x143c60 mov r0, r4
 *   @0x143c64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143c68 mov r1, #1
 *   @0x143c6c mov r5, r0
 *   @0x143c70 mov r0, r4
 *   @0x143c74 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x143c78 mov r1, r0
 *   @0x143c7c mov r0, r5
 *   @0x143c80 pop {r3, r4, r5, lr}
 *   @0x143c84 b 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *
 * ══ §307/561 F_D3DModelSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0x14540c  size 52  13 条（0x14540c..0x145440）
 * @func 0x14540c 0x145440  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14540c push {r3, r4, r5, lr}
 *   @0x145410 mov r1, #0
 *   @0x145414 ldr r4, [sp, #0x10]
 *   @0x145418 mov r0, r4
 *   @0x14541c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145420 mov r1, #1
 *   @0x145424 mov r5, r0
 *   @0x145428 mov r0, r4
 *   @0x14542c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145430 mov r1, r0
 *   @0x145434 mov r0, r5
 *   @0x145438 pop {r3, r4, r5, lr}
 *   @0x14543c b 0x165328 <_Z19GR_3DM_SaveToBufferii>
 *
 * ══ §308/561 F_D3DModelPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*)  0x1454b0  size 52  13 条（0x1454b0..0x1454e4）
 * @func 0x1454b0 0x1454e4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1454b0 push {r3, r4, r5, lr}
 *   @0x1454b4 mov r1, #0
 *   @0x1454b8 ldr r4, [sp, #0x10]
 *   @0x1454bc mov r0, r4
 *   @0x1454c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1454c4 mov r1, #1
 *   @0x1454c8 mov r5, r0
 *   @0x1454cc mov r0, r4
 *   @0x1454d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1454d4 mov r1, r0
 *   @0x1454d8 mov r0, r5
 *   @0x1454dc pop {r3, r4, r5, lr}
 *   @0x1454e0 b 0x1653c0 <_Z22GR_3DM_Primitive_Beginii>
 *
 * ══ §309/561 F_YoYo_AchievementsAvailable(RValue&, CInstance*, CInstance*, int, RValue*)  0x156030  size 52  13 条（0x156030..0x156064）
 * @func 0x156030 0x156064  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156030 ldr r3, [pc, #0x28]
 *   @0x156034 mov r2, #0
 *   @0x156038 str r2, [r0, #0xc]
 *   @0x15603c ldr r3, [pc, r3]
 *   @0x156040 ldrb r3, [r3]
 *   @0x156044 cmp r3, r2
 *   @0x156048 strne r2, [r0]
 *   @0x15604c streq r3, [r0]
 *   @0x156050 movne r3, r2
 *   @0x156054 movtne r3, #0x3ff0
 *   @0x156058 str r3, [r0, #0x4]
 *   @0x15605c bx lr
 *   @0x156060 .word 0x00299af4
 *
 * ══ §310/561 F_YoYo_IsKeypadOpen(RValue&, CInstance*, CInstance*, int, RValue*)  0x156150  size 52  13 条（0x156150..0x156184）
 * @func 0x156150 0x156184  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156150 ldr r3, [pc, #0x28]
 *   @0x156154 mov r2, #0
 *   @0x156158 str r2, [r0, #0xc]
 *   @0x15615c ldr r3, [pc, r3]
 *   @0x156160 ldrb r3, [r3]
 *   @0x156164 cmp r3, r2
 *   @0x156168 movne r3, r2
 *   @0x15616c moveq r2, r3
 *   @0x156170 movtne r2, #0x3ff0
 *   @0x156174 str r3, [r0]
 *   @0x156178 str r2, [r0, #0x4]
 *   @0x15617c bx lr
 *   @0x156180 eoreq r9, r9, r4, ror #19
 *
 * ══ §311/561 F_YoYo_OSPauseEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x1561c0  size 52  13 条（0x1561c0..0x1561f4）
 * @func 0x1561c0 0x1561f4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1561c0 ldr r3, [pc, #0x28]
 *   @0x1561c4 mov r2, #0
 *   @0x1561c8 str r2, [r0, #0xc]
 *   @0x1561cc ldr r3, [pc, r3]
 *   @0x1561d0 ldrb r3, [r3]
 *   @0x1561d4 cmp r3, r2
 *   @0x1561d8 movne r3, r2
 *   @0x1561dc moveq r2, r3
 *   @0x1561e0 movtne r2, #0x3ff0
 *   @0x1561e4 str r3, [r0]
 *   @0x1561e8 str r2, [r0, #0x4]
 *   @0x1561ec bx lr
 *   @0x1561f0 eoreq r9, r9, r8, ror r9
 *
 * ══ §312/561 F_AppSurfaceIsEnabled(RValue&, CInstance*, CInstance*, int, RValue*)  0x156304  size 52  13 条（0x156304..0x156338）
 * @func 0x156304 0x156338  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156304 ldr r3, [pc, #0x28]
 *   @0x156308 mov r2, #0
 *   @0x15630c str r2, [r0, #0xc]
 *   @0x156310 ldr r3, [pc, r3]
 *   @0x156314 ldrb r3, [r3]
 *   @0x156318 cmp r3, r2
 *   @0x15631c movne r3, r2
 *   @0x156320 moveq r2, r3
 *   @0x156324 movtne r2, #0x3ff0
 *   @0x156328 str r3, [r0]
 *   @0x15632c str r2, [r0, #0x4]
 *   @0x156330 bx lr
 *   @0x156334 eoreq r9, r9, r8, lsr r8
 *
 * ══ §313/561 F_PlayerRestarted(RValue&, CInstance*, CInstance*, int, RValue*)  0x156338  size 52  13 条（0x156338..0x15636c）
 * @func 0x156338 0x15636c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156338 ldr r3, [pc, #0x28]
 *   @0x15633c mov r1, #0
 *   @0x156340 str r1, [r0, #0xc]
 *   @0x156344 ldr r3, [pc, r3]
 *   @0x156348 ldrb r2, [r3]
 *   @0x15634c cmp r2, r1
 *   @0x156350 movne r2, r1
 *   @0x156354 moveq r3, #0
 *   @0x156358 movne r3, r2
 *   @0x15635c movteq r3, #0x3ff0
 *   @0x156360 stm r0, {r2, r3}
 *   @0x156364 bx lr
 *   @0x156368 eoreq r9, r9, r8, lsl #16
 *
 * ══ §314/561 GET_YoYo_GetDevice(CInstance*, int, RValue*)  0x156f2c  size 52  13 条（0x156f2c..0x156f60）
 * @func 0x156f2c 0x156f60  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDeviceM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156f2c push {r4, r5, r6, lr}
 *   @0x156f30 mov r3, #0
 *   @0x156f34 str r3, [r2, #0xc]
 *   @0x156f38 mov r6, r2
 *   @0x156f3c bl 0x15e64c <_Z10GetDeviceMv>
 *   @0x156f40 vmov s15, r0
 *   @0x156f44 mov r0, #1
 *   @0x156f48 vcvt.f64.s32 d7, s15
 *   @0x156f4c vmov r4, r5, d7
 *   @0x156f50 vmov r2, s14
 *   @0x156f54 mov r3, r5
 *   @0x156f58 stm r6, {r2, r3}
 *   @0x156f5c pop {r4, r5, r6, pc}
 *
 * ══ §315/561 F_YoYo_OF_AddAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x157098  size 52  13 条（0x157098..0x1570cc）
 * @func 0x157098 0x1570cc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157098 push {r3, r4, r5, lr}
 *   @0x15709c mov r1, #0
 *   @0x1570a0 ldr r4, [sp, #0x10]
 *   @0x1570a4 mov r0, r4
 *   @0x1570a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1570ac mov r1, #1
 *   @0x1570b0 mov r5, r0
 *   @0x1570b4 mov r0, r4
 *   @0x1570b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1570bc mov r1, r0
 *   @0x1570c0 mov r0, r5
 *   @0x1570c4 pop {r3, r4, r5, lr}
 *   @0x1570c8 b 0x1616d8 <_Z22YoYo_OF_AddAchievementPKcS0_>
 *
 * ══ §316/561 F_YoYo_OF_SendChallengeResult(RValue&, CInstance*, CInstance*, int, RValue*)  0x1571d8  size 52  13 条（0x1571d8..0x15720c）
 * @func 0x1571d8 0x15720c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1571d8 push {r3, r4, r5, lr}
 *   @0x1571dc mov r1, #0
 *   @0x1571e0 ldr r4, [sp, #0x10]
 *   @0x1571e4 mov r0, r4
 *   @0x1571e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1571ec mov r1, #1
 *   @0x1571f0 mov r5, r0
 *   @0x1571f4 mov r0, r4
 *   @0x1571f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1571fc mov r1, r0
 *   @0x157200 mov r0, r5
 *   @0x157204 pop {r3, r4, r5, lr}
 *   @0x157208 b 0x161700 <_Z27YoYo_OF_SendChallengeResult16eChallengeResultPKc>
 *
 * ══ §317/561 CacheAchievement(eCacheType, char const*, unsigned int*)  0x159cc0  size 52  13 条（0x159cc0..0x159cf4）
 * @func 0x159cc0 0x159cf4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UpdateCache(eCacheType, char const*, unsigned int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159cc0 push {r4, r5, r6, lr}
 *   @0x159cc4 mov r4, r2
 *   @0x159cc8 ldr r2, [r2]
 *   @0x159ccc mov r6, r0
 *   @0x159cd0 mov r5, r1
 *   @0x159cd4 bl 0x159c88 <_Z11UpdateCache10eCacheTypePKcj>
 *   @0x159cd8 cmp r0, #0
 *   @0x159cdc popne {r4, r5, r6, pc}
 *   @0x159ce0 mov r0, r6
 *   @0x159ce4 mov r1, r5
 *   @0x159ce8 mov r2, r4
 *   @0x159cec pop {r4, r5, r6, lr}
 *   @0x159cf0 b 0x159a9c <_Z24AddAchievementCacheBlock10eCacheTypePKcPj>
 *
 * ══ §318/561 FacebookLogoutM()  0x15ef48  size 52  13 条（0x15ef48..0x15ef7c）
 * @func 0x15ef48 0x15ef7c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15ef48 push {r3, lr}
 *   @0x15ef4c bl 0x290274 <getJNIEnv>
 *   @0x15ef50 ldr r2, [pc, #0x1c]
 *   @0x15ef54 ldr r3, [pc, #0x1c]
 *   @0x15ef58 ldr r2, [pc, r2]
 *   @0x15ef5c ldr r3, [pc, r3]
 *   @0x15ef60 ldr r1, [r2]
 *   @0x15ef64 ldr r2, [r3]
 *   @0x15ef68 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15ef6c mov r0, #1
 *   @0x15ef70 pop {r3, pc}
 *   @0x15ef74 eoreq lr, r8, r12, asr #20
 *   @0x15ef78 eoreq r0, r9, r0, ror #30
 *
 * ══ §319/561 GR_D3D_Set_Culling(bool)  0x1683e8  size 52  13 条（0x1683e8..0x16841c）
 * @func 0x1683e8 0x16841c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1683e8 subs r2, r0, #0
 *   @0x1683ec bne 0x168400 <_Z18GR_D3D_Set_Cullingb+0x18>
 *   @0x1683f0 ldr r0, [pc, #0x1c]
 *   @0x1683f4 mov r1, #8
 *   @0x1683f8 ldr r0, [pc, r0]
 *   @0x1683fc b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168400 ldr r0, [pc, #0x10]
 *   @0x168404 mov r1, #8
 *   @0x168408 mov r2, #2
 *   @0x16840c ldr r0, [pc, r0]
 *   @0x168410 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168414 eoreq r5, r8, r0, lsl #18
 *   @0x168418 eoreq r5, r8, r12, ror #17
 *
 * ══ §320/561 GR_Draw_Ellipse(float, float, float, float, bool)  0x16b278  size 52  13 条（0x16b278..0x16b2ac）
 * @func 0x16b278 0x16b2ac  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x-4×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b278 ldr r12, [pc, #0x28]
 *   @0x16b27c str lr, [sp, #-0x4]!
 *   @0x16b280 ldr r12, [pc, r12]
 *   @0x16b284 sub sp, sp, #20
 *   @0x16b288 ldr r12, [r12]
 *   @0x16b28c ldrb lr, [sp, #0x18]
 *   @0x16b290 str r12, [sp]
 *   @0x16b294 str lr, [sp, #0x8]
 *   @0x16b298 str r12, [sp, #0x4]
 *   @0x16b29c bl 0x16af3c <_Z13_Draw_Ellipseffffjjb>
 *   @0x16b2a0 add sp, sp, #20
 *   @0x16b2a4 ldr pc, [sp], #4
 *   @0x16b2a8 eoreq r2, r8, r12, ror r10
 *
 * ══ §321/561 GR_Texture_Preload(int)  0x174288  size 52  13 条（0x174288..0x1742bc）
 * @func 0x174288 0x1742bc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x14×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174288 push {r4, lr}
 *   @0x17428c mov r4, r0
 *   @0x174290 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174294 cmp r0, #0
 *   @0x174298 popeq {r4, pc}
 *   @0x17429c ldr r3, [pc, #0x14]
 *   @0x1742a0 ldr r3, [pc, r3]
 *   @0x1742a4 ldr r3, [r3, #0x4]
 *   @0x1742a8 ldr r3, [r3, r4, lsl #2]
 *   @0x1742ac pop {r4, lr}
 *   @0x1742b0 ldr r0, [r3]
 *   @0x1742b4 b 0x1833c4 <_ZN8Graphics14PreLoadTextureEPv>
 *   @0x1742b8 eoreq r9, r7, r12, ror r6
 *
 * ══ §322/561 GR_Window_Set_Rectangle(int, int, int, int)  0x17add4  size 52  13 条（0x17add4..0x17ae08）
 * @func 0x17add4 0x17ae08  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Set_Position(int, int) / GR_Window_Set_Size(int, int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17add4 push {r3, r4, r5, lr}
 *   @0x17add8 mov r4, r2
 *   @0x17addc mov r5, r3
 *   @0x17ade0 bl 0x17af38 <_Z22GR_Window_Set_Positionii>
 *   @0x17ade4 mov r0, r4
 *   @0x17ade8 mov r1, r5
 *   @0x17adec bl 0x17af3c <_Z18GR_Window_Set_Sizeii>
 *   @0x17adf0 ldr r3, [pc, #0xc]
 *   @0x17adf4 mov r2, #1
 *   @0x17adf8 ldr r3, [pc, r3]
 *   @0x17adfc strb r2, [r3]
 *   @0x17ae00 pop {r3, r4, r5, pc}
 *   @0x17ae04 eoreq r5, r7, r0, lsr #10
 *
 * ══ §323/561 FreePNGFile()  0x18a518  size 52  13 条（0x18a518..0x18a54c）
 * @func 0x18a518 0x18a54c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreePNG(yyPNGFile*) / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a518 push {r4, lr}
 *   @0x18a51c ldr r4, [pc, #0x24]
 *   @0x18a520 ldr r4, [pc, r4]
 *   @0x18a524 ldr r0, [r4]
 *   @0x18a528 cmp r0, #0
 *   @0x18a52c popeq {r4, pc}
 *   @0x18a530 bl 0x189b3c <_Z7FreePNGP9yyPNGFile>
 *   @0x18a534 ldr r0, [r4]
 *   @0x18a538 bl 0x27d1d0 <_ZdlPv>
 *   @0x18a53c mov r3, #0
 *   @0x18a540 str r3, [r4]
 *   @0x18a544 pop {r4, pc}
 *   @0x18a548 eoreq r6, r6, r0, lsr #1
 *
 * ══ §324/561 CGrid::~CGrid()  0x199f50  size 52  13 条（0x199f50..0x199f84）
 * @func 0x199f50 0x199f84  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f50 push {r4, lr}
 *   @0x199f54 mov r4, r0
 *   @0x199f58 ldr r0, [r0, #0x1c]
 *   @0x199f5c ldr r3, [pc, #0x1c]
 *   @0x199f60 cmp r0, #0
 *   @0x199f64 ldr r3, [pc, r3]
 *   @0x199f68 add r3, r3, #8
 *   @0x199f6c str r3, [r4]
 *   @0x199f70 beq 0x199f78 <_ZN5CGridD2Ev+0x28>
 *   @0x199f74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x199f78 mov r0, r4
 *   @0x199f7c pop {r4, pc}
 *   @0x199f80 eoreq r6, r5, r4, asr #14
 *
 * ══ §325/561 ParticleType_Blend(int, bool)  0x1a373c  size 52  13 条（0x1a373c..0x1a3770）
 * @func 0x1a373c 0x1a3770  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a373c push {r3, r4, r5, lr}
 *   @0x1a3740 mov r5, r1
 *   @0x1a3744 mov r4, r0
 *   @0x1a3748 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a374c cmp r0, #0
 *   @0x1a3750 popeq {r3, r4, r5, pc}
 *   @0x1a3754 ldr r3, [pc, #0x10]
 *   @0x1a3758 ldr r3, [pc, r3]
 *   @0x1a375c ldr r3, [r3, #0x4]
 *   @0x1a3760 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3764 strb r5, [r3, #0xa0]
 *   @0x1a3768 pop {r3, r4, r5, pc}
 *   @0x1a376c eoreq sp, r4, r4, asr r0
 *
 * ══ §326/561 ParticleSystem_DrawOrder(int, bool)  0x1a47a0  size 52  13 条（0x1a47a0..0x1a47d4）
 * @func 0x1a47a0 0x1a47d4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a47a0 push {r3, r4, r5, lr}
 *   @0x1a47a4 mov r5, r1
 *   @0x1a47a8 mov r4, r0
 *   @0x1a47ac bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a47b0 cmp r0, #0
 *   @0x1a47b4 popeq {r3, r4, r5, pc}
 *   @0x1a47b8 ldr r3, [pc, #0x10]
 *   @0x1a47bc ldr r3, [pc, r3]
 *   @0x1a47c0 ldr r3, [r3, #0x4]
 *   @0x1a47c4 ldr r3, [r3, r4, lsl #2]
 *   @0x1a47c8 strb r5, [r3, #0x18]
 *   @0x1a47cc pop {r3, r4, r5, pc}
 *   @0x1a47d0 .word 0x0024bffc
 *
 * ══ §327/561 ParticleSystem_AutomaticUpdate(int, bool)  0x1a48d0  size 52  13 条（0x1a48d0..0x1a4904）
 * @func 0x1a48d0 0x1a4904  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a48d0 push {r3, r4, r5, lr}
 *   @0x1a48d4 mov r5, r1
 *   @0x1a48d8 mov r4, r0
 *   @0x1a48dc bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a48e0 cmp r0, #0
 *   @0x1a48e4 popeq {r3, r4, r5, pc}
 *   @0x1a48e8 ldr r3, [pc, #0x10]
 *   @0x1a48ec ldr r3, [pc, r3]
 *   @0x1a48f0 ldr r3, [r3, #0x4]
 *   @0x1a48f4 ldr r3, [r3, r4, lsl #2]
 *   @0x1a48f8 strb r5, [r3, #0x28]
 *   @0x1a48fc pop {r3, r4, r5, pc}
 *   @0x1a4900 eoreq r11, r4, r12, asr #29
 *
 * ══ §328/561 ParticleSystem_AutomaticDraw(int, bool)  0x1a4904  size 52  13 条（0x1a4904..0x1a4938）
 * @func 0x1a4904 0x1a4938  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1 / 0x29×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4904 push {r3, r4, r5, lr}
 *   @0x1a4908 mov r5, r1
 *   @0x1a490c mov r4, r0
 *   @0x1a4910 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a4914 cmp r0, #0
 *   @0x1a4918 popeq {r3, r4, r5, pc}
 *   @0x1a491c ldr r3, [pc, #0x10]
 *   @0x1a4920 ldr r3, [pc, r3]
 *   @0x1a4924 ldr r3, [r3, #0x4]
 *   @0x1a4928 ldr r3, [r3, r4, lsl #2]
 *   @0x1a492c strb r5, [r3, #0x29]
 *   @0x1a4930 pop {r3, r4, r5, pc}
 *   @0x1a4934 mlaeq r4, r8, lr, r11
 *
 * ══ §329/561 CPath::ComputeInternal()  0x1a6e30  size 52  13 条（0x1a6e30..0x1a6e64）
 * @func 0x1a6e30 0x1a6e64  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::ComputeLinear() / CPath::ComputeCurved()
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6e30 ldr r3, [r0, #0x14]
 *   @0x1a6e34 push {r4, lr}
 *   @0x1a6e38 cmp r3, #1
 *   @0x1a6e3c mov r4, r0
 *   @0x1a6e40 beq 0x1a6e54 <_ZN5CPath15ComputeInternalEv+0x24>
 *   @0x1a6e44 bl 0x1a60dc <_ZN5CPath13ComputeLinearEv>
 *   @0x1a6e48 mov r0, r4
 *   @0x1a6e4c pop {r4, lr}
 *   @0x1a6e50 b 0x1a5f78 <_ZN5CPath13ComputeLengthEv>
 *   @0x1a6e54 bl 0x1a6bb8 <_ZN5CPath13ComputeCurvedEv>
 *   @0x1a6e58 mov r0, r4
 *   @0x1a6e5c pop {r4, lr}
 *   @0x1a6e60 b 0x1a5f78 <_ZN5CPath13ComputeLengthEv>
 *
 * ══ §330/561 CPath::CPath()  0x1a6e9c  size 52  13 条（0x1a6e9c..0x1a6ed0）
 * @func 0x1a6e9c 0x1a6ed0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x1c×1 / 0x10×1 / 0x4×1 / 0x20×1 / 0xc×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6e9c mov r1, #1
 *   @0x1a6ea0 mov r2, #4
 *   @0x1a6ea4 strb r1, [r0, #0x18]
 *   @0x1a6ea8 str r2, [r0, #0x1c]
 *   @0x1a6eac mov r2, #0
 *   @0x1a6eb0 str r2, [r0, #0x10]
 *   @0x1a6eb4 str r2, [r0, #0x4]
 *   @0x1a6eb8 str r2, [r0]
 *   @0x1a6ebc str r2, [r0, #0x20]
 *   @0x1a6ec0 str r2, [r0, #0xc]
 *   @0x1a6ec4 str r2, [r0, #0x8]
 *   @0x1a6ec8 str r2, [r0, #0x14]
 *   @0x1a6ecc bx lr
 *
 * ══ §331/561 TFont::SetName(char const*)  0x1a85b4  size 52  13 条（0x1a85b4..0x1a85e8）
 * @func 0x1a85b4 0x1a85e8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a85b4 push {r3, r4, r5, lr}
 *   @0x1a85b8 mov r4, r0
 *   @0x1a85bc ldr r0, [r0, #0x8]
 *   @0x1a85c0 mov r5, r1
 *   @0x1a85c4 cmp r0, #0
 *   @0x1a85c8 beq 0x1a85d0 <_ZN5TFont7SetNameEPKc+0x1c>
 *   @0x1a85cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1a85d0 mov r0, r5
 *   @0x1a85d4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1a85d8 str r0, [r4, #0x8]
 *   @0x1a85dc mov r0, r4
 *   @0x1a85e0 pop {r3, r4, r5, lr}
 *   @0x1a85e4 b 0x1a8850 <_ZN5TFont6CreateEv>
 *
 * ══ §332/561 IBitmapLoader::Create(void*, int, int)  0x1a928c  size 52  13 条（0x1a928c..0x1a92c0）
 * @func 0x1a928c 0x1a92c0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / BitmapLoader::BitmapLoader(void*, int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a928c push {r3, r4, r5, r6, r7, lr}
 *   @0x1a9290 mov r7, r0
 *   @0x1a9294 mov r0, #20
 *   @0x1a9298 mov r6, r1
 *   @0x1a929c mov r5, r2
 *   @0x1a92a0 bl 0x27c524 <_Znwj>
 *   @0x1a92a4 mov r1, r7
 *   @0x1a92a8 mov r2, r6
 *   @0x1a92ac mov r3, r5
 *   @0x1a92b0 mov r4, r0
 *   @0x1a92b4 bl 0x1a916c <_ZN12BitmapLoaderC2EPvii>
 *   @0x1a92b8 mov r0, r4
 *   @0x1a92bc pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §333/561 F_LayerIsDrawDepthForced(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b5ee4  size 52  13 条（0x1b5ee4..0x1b5f18）
 * @func 0x1b5ee4 0x1b5f18  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5ee4 ldr r3, [pc, #0x28]
 *   @0x1b5ee8 mov r2, #0
 *   @0x1b5eec str r2, [r0, #0xc]
 *   @0x1b5ef0 ldr r3, [pc, r3]
 *   @0x1b5ef4 ldrb r3, [r3]
 *   @0x1b5ef8 cmp r3, r2
 *   @0x1b5efc movne r3, r2
 *   @0x1b5f00 moveq r2, r3
 *   @0x1b5f04 movtne r2, #0x3ff0
 *   @0x1b5f08 str r3, [r0]
 *   @0x1b5f0c str r2, [r0, #0x4]
 *   @0x1b5f10 bx lr
 *   @0x1b5f14 eoreq r10, r3, r0, asr #18
 *
 * ══ §334/561 Run_Step()  0x1d4ea4  size 52  13 条（0x1d4ea4..0x1d4ed8）
 * @func 0x1d4ea4 0x1d4ed8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4ea4 ldr r3, [pc, #0x24]
 *   @0x1d4ea8 ldr r3, [pc, r3]
 *   @0x1d4eac ldrb r3, [r3]
 *   @0x1d4eb0 cmp r3, #0
 *   @0x1d4eb4 bxeq lr
 *   @0x1d4eb8 ldr r3, [pc, #0x14]
 *   @0x1d4ebc ldr r3, [pc, r3]
 *   @0x1d4ec0 ldrb r3, [r3]
 *   @0x1d4ec4 cmp r3, #0
 *   @0x1d4ec8 bxeq lr
 *   @0x1d4ecc b 0x1d4dd8 <_Z10SingleStepv>
 *   @0x1d4ed0 eoreq r11, r1, r4, ror #24
 *   @0x1d4ed4 eoreq r10, r1, r4, lsr sp
 *
 * ══ §335/561 F_GestureGetTapCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x1d5270  size 52  13 条（0x1d5270..0x1d52a4）
 * @func 0x1d5270 0x1d52a4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5270 ldr r3, [pc, #0x28]
 *   @0x1d5274 mov r2, #0
 *   @0x1d5278 str r2, [r0, #0xc]
 *   @0x1d527c ldr r3, [pc, r3]
 *   @0x1d5280 ldrb r3, [r3]
 *   @0x1d5284 cmp r3, r2
 *   @0x1d5288 movne r3, r2
 *   @0x1d528c moveq r2, r3
 *   @0x1d5290 movtne r2, #0x3ff0
 *   @0x1d5294 str r3, [r0]
 *   @0x1d5298 str r2, [r0, #0x4]
 *   @0x1d529c bx lr
 *   @0x1d52a0 eoreq r11, r1, r0, ror r9
 *
 * ══ §336/561 CGesture::~CGesture()  0x1d52a4  size 52  13 条（0x1d52a4..0x1d52d8）
 * @func 0x1d52a4 0x1d52d8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d52a4 push {r4, lr}
 *   @0x1d52a8 mov r4, r0
 *   @0x1d52ac ldr r0, [r0, #0xc]
 *   @0x1d52b0 ldr r3, [pc, #0x1c]
 *   @0x1d52b4 cmp r0, #0
 *   @0x1d52b8 ldr r3, [pc, r3]
 *   @0x1d52bc add r3, r3, #8
 *   @0x1d52c0 str r3, [r4]
 *   @0x1d52c4 beq 0x1d52cc <_ZN8CGestureD2Ev+0x28>
 *   @0x1d52c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d52cc mov r0, r4
 *   @0x1d52d0 pop {r4, pc}
 *   @0x1d52d4 eoreq r11, r1, r8, lsr r9
 *
 * ══ §337/561 Code_Patch(unsigned char*, void*, int)  0x1dc7cc  size 52  13 条（0x1dc7cc..0x1dc800）
 * @func 0x1dc7cc 0x1dc800  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Patch_Instruction(unsigned char*, int, void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc7cc push {r4, r5, r6, lr}
 *   @0x1dc7d0 subs r6, r2, #0
 *   @0x1dc7d4 mov r4, r0
 *   @0x1dc7d8 mov r5, r1
 *   @0x1dc7dc pople {r4, r5, r6, pc}
 *   @0x1dc7e0 mov r1, #0
 *   @0x1dc7e4 mov r0, r4
 *   @0x1dc7e8 mov r2, r5
 *   @0x1dc7ec bl 0x1dc7a4 <_Z22Code_Patch_InstructionPhiPv>
 *   @0x1dc7f0 cmp r6, r0
 *   @0x1dc7f4 mov r1, r0
 *   @0x1dc7f8 bgt 0x1dc7e4 <_Z10Code_PatchPhPvi+0x18>
 *   @0x1dc7fc pop {r4, r5, r6, pc}
 *
 * ══ §338/561 RewriteOldCode(unsigned char*, void*, int)  0x1dc890  size 52  13 条（0x1dc890..0x1dc8c4）
 * @func 0x1dc890 0x1dc8c4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RewriteOldCodeInstruction(unsigned char*, int, void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc890 push {r4, r5, r6, lr}
 *   @0x1dc894 subs r6, r2, #0
 *   @0x1dc898 mov r4, r0
 *   @0x1dc89c mov r5, r1
 *   @0x1dc8a0 pople {r4, r5, r6, pc}
 *   @0x1dc8a4 mov r1, #0
 *   @0x1dc8a8 mov r0, r4
 *   @0x1dc8ac mov r2, r5
 *   @0x1dc8b0 bl 0x1dc830 <_Z25RewriteOldCodeInstructionPhiPv>
 *   @0x1dc8b4 cmp r6, r0
 *   @0x1dc8b8 mov r1, r0
 *   @0x1dc8bc bgt 0x1dc8a8 <_Z14RewriteOldCodePhPvi+0x18>
 *   @0x1dc8c0 pop {r4, r5, r6, pc}
 *
 * ══ §339/561 F_Shaders_Are_Supported(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e0f98  size 52  13 条（0x1e0f98..0x1e0fcc）
 * @func 0x1e0f98 0x1e0fcc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::ShadersSupported()
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0f98 push {r3, r4, r5, lr}
 *   @0x1e0f9c mov r5, #0
 *   @0x1e0fa0 str r5, [r0, #0xc]
 *   @0x1e0fa4 mov r4, r0
 *   @0x1e0fa8 str r5, [r0]
 *   @0x1e0fac str r5, [r0, #0x4]
 *   @0x1e0fb0 bl 0x17df3c <_ZN8Graphics16ShadersSupportedEv>
 *   @0x1e0fb4 cmp r0, r5
 *   @0x1e0fb8 strne r5, [r4]
 *   @0x1e0fbc movne r3, r5
 *   @0x1e0fc0 movtne r3, #0x3ff0
 *   @0x1e0fc4 strne r3, [r4, #0x4]
 *   @0x1e0fc8 pop {r3, r4, r5, pc}
 *
 * ══ §340/561 GV_Id(CInstance*, int, RValue*)  0x1f8e30  size 52  13 条（0x1f8e30..0x1f8e64）
 * @func 0x1f8e30 0x1f8e64  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x78×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8e30 push {r4, r5}
 *   @0x1f8e34 mov r3, #0
 *   @0x1f8e38 ldr r4, [r0, #0x78]
 *   @0x1f8e3c mov r0, #1
 *   @0x1f8e40 str r3, [r2, #0xc]
 *   @0x1f8e44 vmov s15, r4
 *   @0x1f8e48 vcvt.f64.s32 d7, s15
 *   @0x1f8e4c vmov r4, r5, d7
 *   @0x1f8e50 vmov r1, s14
 *   @0x1f8e54 mov r3, r5
 *   @0x1f8e58 pop {r4, r5}
 *   @0x1f8e5c stm r2, {r1, r3}
 *   @0x1f8e60 bx lr
 *
 * ══ §341/561 GV_Solid(CInstance*, int, RValue*)  0x1f8e64  size 52  13 条（0x1f8e64..0x1f8e98）
 * @func 0x1f8e64 0x1f8e98  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x66×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8e64 push {r4, r5}
 *   @0x1f8e68 mov r3, #0
 *   @0x1f8e6c ldrb r4, [r0, #0x66]
 *   @0x1f8e70 mov r0, #1
 *   @0x1f8e74 str r3, [r2, #0xc]
 *   @0x1f8e78 vmov s15, r4
 *   @0x1f8e7c vcvt.f64.u32 d7, s15
 *   @0x1f8e80 vmov r4, r5, d7
 *   @0x1f8e84 vmov r1, s14
 *   @0x1f8e88 mov r3, r5
 *   @0x1f8e8c pop {r4, r5}
 *   @0x1f8e90 stm r2, {r1, r3}
 *   @0x1f8e94 bx lr
 *
 * ══ §342/561 GV_Visible(CInstance*, int, RValue*)  0x1f8e98  size 52  13 条（0x1f8e98..0x1f8ecc）
 * @func 0x1f8e98 0x1f8ecc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x65×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8e98 push {r4, r5}
 *   @0x1f8e9c mov r3, #0
 *   @0x1f8ea0 ldrb r4, [r0, #0x65]
 *   @0x1f8ea4 mov r0, #1
 *   @0x1f8ea8 str r3, [r2, #0xc]
 *   @0x1f8eac vmov s15, r4
 *   @0x1f8eb0 vcvt.f64.u32 d7, s15
 *   @0x1f8eb4 vmov r4, r5, d7
 *   @0x1f8eb8 vmov r1, s14
 *   @0x1f8ebc mov r3, r5
 *   @0x1f8ec0 pop {r4, r5}
 *   @0x1f8ec4 stm r2, {r1, r3}
 *   @0x1f8ec8 bx lr
 *
 * ══ §343/561 GV_Persistent(CInstance*, int, RValue*)  0x1f8ecc  size 52  13 条（0x1f8ecc..0x1f8f00）
 * @func 0x1f8ecc 0x1f8f00  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x67×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8ecc push {r4, r5}
 *   @0x1f8ed0 mov r3, #0
 *   @0x1f8ed4 ldrb r4, [r0, #0x67]
 *   @0x1f8ed8 mov r0, #1
 *   @0x1f8edc str r3, [r2, #0xc]
 *   @0x1f8ee0 vmov s15, r4
 *   @0x1f8ee4 vcvt.f64.u32 d7, s15
 *   @0x1f8ee8 vmov r4, r5, d7
 *   @0x1f8eec vmov r1, s14
 *   @0x1f8ef0 mov r3, r5
 *   @0x1f8ef4 pop {r4, r5}
 *   @0x1f8ef8 stm r2, {r1, r3}
 *   @0x1f8efc bx lr
 *
 * ══ §344/561 GV_ObjectIndex(CInstance*, int, RValue*)  0x1f8f00  size 52  13 条（0x1f8f00..0x1f8f34）
 * @func 0x1f8f00 0x1f8f34  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8f00 push {r4, r5}
 *   @0x1f8f04 mov r3, #0
 *   @0x1f8f08 ldr r4, [r0, #0x7c]
 *   @0x1f8f0c mov r0, #1
 *   @0x1f8f10 str r3, [r2, #0xc]
 *   @0x1f8f14 vmov s15, r4
 *   @0x1f8f18 vcvt.f64.s32 d7, s15
 *   @0x1f8f1c vmov r4, r5, d7
 *   @0x1f8f20 vmov r1, s14
 *   @0x1f8f24 mov r3, r5
 *   @0x1f8f28 pop {r4, r5}
 *   @0x1f8f2c stm r2, {r1, r3}
 *   @0x1f8f30 bx lr
 *
 * ══ §345/561 GV_SpriteIndex(CInstance*, int, RValue*)  0x1f8f64  size 52  13 条（0x1f8f64..0x1f8f98）
 * @func 0x1f8f64 0x1f8f98  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8f64 push {r4, r5}
 *   @0x1f8f68 mov r3, #0
 *   @0x1f8f6c ldr r4, [r0, #0x8c]
 *   @0x1f8f70 mov r0, #1
 *   @0x1f8f74 str r3, [r2, #0xc]
 *   @0x1f8f78 vmov s15, r4
 *   @0x1f8f7c vcvt.f64.s32 d7, s15
 *   @0x1f8f80 vmov r4, r5, d7
 *   @0x1f8f84 vmov r1, s14
 *   @0x1f8f88 mov r3, r5
 *   @0x1f8f8c pop {r4, r5}
 *   @0x1f8f90 stm r2, {r1, r3}
 *   @0x1f8f94 bx lr
 *
 * ══ §346/561 GV_ImageBlend(CInstance*, int, RValue*)  0x1f90c8  size 52  13 条（0x1f90c8..0x1f90fc）
 * @func 0x1f90c8 0x1f90fc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xa8×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f90c8 push {r4, r5}
 *   @0x1f90cc mov r3, #0
 *   @0x1f90d0 ldr r4, [r0, #0xa8]
 *   @0x1f90d4 mov r0, #1
 *   @0x1f90d8 str r3, [r2, #0xc]
 *   @0x1f90dc vmov s15, r4
 *   @0x1f90e0 vcvt.f64.u32 d7, s15
 *   @0x1f90e4 vmov r4, r5, d7
 *   @0x1f90e8 vmov r1, s14
 *   @0x1f90ec mov r3, r5
 *   @0x1f90f0 pop {r4, r5}
 *   @0x1f90f4 stm r2, {r1, r3}
 *   @0x1f90f8 bx lr
 *
 * ══ §347/561 GV_MaskIndex(CInstance*, int, RValue*)  0x1f912c  size 52  13 条（0x1f912c..0x1f9160）
 * @func 0x1f912c 0x1f9160  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xac×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f912c push {r4, r5}
 *   @0x1f9130 mov r3, #0
 *   @0x1f9134 ldr r4, [r0, #0xac]
 *   @0x1f9138 mov r0, #1
 *   @0x1f913c str r3, [r2, #0xc]
 *   @0x1f9140 vmov s15, r4
 *   @0x1f9144 vcvt.f64.s32 d7, s15
 *   @0x1f9148 vmov r4, r5, d7
 *   @0x1f914c vmov r1, s14
 *   @0x1f9150 mov r3, r5
 *   @0x1f9154 pop {r4, r5}
 *   @0x1f9158 stm r2, {r1, r3}
 *   @0x1f915c bx lr
 *
 * ══ §348/561 GV_PathIndex(CInstance*, int, RValue*)  0x1f9160  size 52  13 条（0x1f9160..0x1f9194）
 * @func 0x1f9160 0x1f9194  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x128×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9160 push {r4, r5}
 *   @0x1f9164 mov r3, #0
 *   @0x1f9168 ldr r4, [r0, #0x128]
 *   @0x1f916c mov r0, #1
 *   @0x1f9170 str r3, [r2, #0xc]
 *   @0x1f9174 vmov s15, r4
 *   @0x1f9178 vcvt.f64.s32 d7, s15
 *   @0x1f917c vmov r4, r5, d7
 *   @0x1f9180 vmov r1, s14
 *   @0x1f9184 mov r3, r5
 *   @0x1f9188 pop {r4, r5}
 *   @0x1f918c stm r2, {r1, r3}
 *   @0x1f9190 bx lr
 *
 * ══ §349/561 GV_PathEndAction(CInstance*, int, RValue*)  0x1f9284  size 52  13 条（0x1f9284..0x1f92b8）
 * @func 0x1f9284 0x1f92b8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x140×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9284 push {r4, r5}
 *   @0x1f9288 mov r3, #0
 *   @0x1f928c ldr r4, [r0, #0x140]
 *   @0x1f9290 mov r0, #1
 *   @0x1f9294 str r3, [r2, #0xc]
 *   @0x1f9298 vmov s15, r4
 *   @0x1f929c vcvt.f64.s32 d7, s15
 *   @0x1f92a0 vmov r4, r5, d7
 *   @0x1f92a4 vmov r1, s14
 *   @0x1f92a8 mov r3, r5
 *   @0x1f92ac pop {r4, r5}
 *   @0x1f92b0 stm r2, {r1, r3}
 *   @0x1f92b4 bx lr
 *
 * ══ §350/561 GV_TimelineIndex(CInstance*, int, RValue*)  0x1f92b8  size 52  13 条（0x1f92b8..0x1f92ec）
 * @func 0x1f92b8 0x1f92ec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f92b8 push {r4, r5}
 *   @0x1f92bc mov r3, #0
 *   @0x1f92c0 ldr r4, [r0, #0x14c]
 *   @0x1f92c4 mov r0, #1
 *   @0x1f92c8 str r3, [r2, #0xc]
 *   @0x1f92cc vmov s15, r4
 *   @0x1f92d0 vcvt.f64.s32 d7, s15
 *   @0x1f92d4 vmov r4, r5, d7
 *   @0x1f92d8 vmov r1, s14
 *   @0x1f92dc mov r3, r5
 *   @0x1f92e0 pop {r4, r5}
 *   @0x1f92e4 stm r2, {r1, r3}
 *   @0x1f92e8 bx lr
 *
 * ══ §351/561 GV_TimelineRunning(CInstance*, int, RValue*)  0x1f934c  size 52  13 条（0x1f934c..0x1f9380）
 * @func 0x1f934c 0x1f9380  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x15c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f934c push {r4, r5}
 *   @0x1f9350 mov r3, #0
 *   @0x1f9354 ldrb r4, [r0, #0x15c]
 *   @0x1f9358 mov r0, #1
 *   @0x1f935c str r3, [r2, #0xc]
 *   @0x1f9360 vmov s15, r4
 *   @0x1f9364 vcvt.f64.u32 d7, s15
 *   @0x1f9368 vmov r4, r5, d7
 *   @0x1f936c vmov r1, s14
 *   @0x1f9370 mov r3, r5
 *   @0x1f9374 pop {r4, r5}
 *   @0x1f9378 stm r2, {r1, r3}
 *   @0x1f937c bx lr
 *
 * ══ §352/561 GV_TimelineLoop(CInstance*, int, RValue*)  0x1f9380  size 52  13 条（0x1f9380..0x1f93b4）
 * @func 0x1f9380 0x1f93b4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x15d×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9380 push {r4, r5}
 *   @0x1f9384 mov r3, #0
 *   @0x1f9388 ldrb r4, [r0, #0x15d]
 *   @0x1f938c mov r0, #1
 *   @0x1f9390 str r3, [r2, #0xc]
 *   @0x1f9394 vmov s15, r4
 *   @0x1f9398 vcvt.f64.u32 d7, s15
 *   @0x1f939c vmov r4, r5, d7
 *   @0x1f93a0 vmov r1, s14
 *   @0x1f93a4 mov r3, r5
 *   @0x1f93a8 pop {r4, r5}
 *   @0x1f93ac stm r2, {r1, r3}
 *   @0x1f93b0 bx lr
 *
 * ══ §353/561 GV_GetDeltaTime(CInstance*, int, RValue*)  0x1f9ac8  size 52  13 条（0x1f9ac8..0x1f9afc）
 * @func 0x1f9ac8 0x1f9afc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9ac8 ldr r3, [pc, #0x28]
 *   @0x1f9acc push {r4, lr}
 *   @0x1f9ad0 ldr r3, [pc, r3]
 *   @0x1f9ad4 mov r4, r2
 *   @0x1f9ad8 mov r2, #0
 *   @0x1f9adc ldrd r0, r1, [r3]
 *   @0x1f9ae0 str r2, [r4, #0xc]
 *   @0x1f9ae4 bl 0x319164 <__floatdidf>
 *   @0x1f9ae8 str r0, [r4]
 *   @0x1f9aec mov r0, #1
 *   @0x1f9af0 str r1, [r4, #0x4]
 *   @0x1f9af4 pop {r4, pc}
 *   @0x1f9af8 andseq r7, pc, r4, lsr #1
 *
 * ══ §354/561 GV_RoomFirst(CInstance*, int, RValue*)  0x1f9bac  size 52  13 条（0x1f9bac..0x1f9be0）
 * @func 0x1f9bac 0x1f9be0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_First()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9bac push {r4, r5, r6, lr}
 *   @0x1f9bb0 mov r3, #0
 *   @0x1f9bb4 str r3, [r2, #0xc]
 *   @0x1f9bb8 mov r6, r2
 *   @0x1f9bbc bl 0x1b5d08 <_Z10Room_Firstv>
 *   @0x1f9bc0 vmov s15, r0
 *   @0x1f9bc4 mov r0, #1
 *   @0x1f9bc8 vcvt.f64.s32 d7, s15
 *   @0x1f9bcc vmov r4, r5, d7
 *   @0x1f9bd0 vmov r2, s14
 *   @0x1f9bd4 mov r3, r5
 *   @0x1f9bd8 stm r6, {r2, r3}
 *   @0x1f9bdc pop {r4, r5, r6, pc}
 *
 * ══ §355/561 GV_RoomLast(CInstance*, int, RValue*)  0x1f9be0  size 52  13 条（0x1f9be0..0x1f9c14）
 * @func 0x1f9be0 0x1f9c14  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Last()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9be0 push {r4, r5, r6, lr}
 *   @0x1f9be4 mov r3, #0
 *   @0x1f9be8 str r3, [r2, #0xc]
 *   @0x1f9bec mov r6, r2
 *   @0x1f9bf0 bl 0x1b5d20 <_Z9Room_Lastv>
 *   @0x1f9bf4 vmov s15, r0
 *   @0x1f9bf8 mov r0, #1
 *   @0x1f9bfc vcvt.f64.s32 d7, s15
 *   @0x1f9c00 vmov r4, r5, d7
 *   @0x1f9c04 vmov r2, s14
 *   @0x1f9c08 mov r3, r5
 *   @0x1f9c0c stm r6, {r2, r3}
 *   @0x1f9c10 pop {r4, r5, r6, pc}
 *
 * ══ §356/561 GV_KeyboardKey(CInstance*, int, RValue*)  0x1fa0f0  size 52  13 条（0x1fa0f0..0x1fa124）
 * @func 0x1fa0f0 0x1fa124  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Key_Current_Get()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa0f0 push {r4, r5, r6, lr}
 *   @0x1fa0f4 mov r3, #0
 *   @0x1fa0f8 str r3, [r2, #0xc]
 *   @0x1fa0fc mov r6, r2
 *   @0x1fa100 bl 0x18bea8 <_Z18IO_Key_Current_Getv>
 *   @0x1fa104 vmov s15, r0
 *   @0x1fa108 mov r0, #1
 *   @0x1fa10c vcvt.f64.s32 d7, s15
 *   @0x1fa110 vmov r4, r5, d7
 *   @0x1fa114 vmov r2, s14
 *   @0x1fa118 mov r3, r5
 *   @0x1fa11c stm r6, {r2, r3}
 *   @0x1fa120 pop {r4, r5, r6, pc}
 *
 * ══ §357/561 GV_KeyboardLastKey(CInstance*, int, RValue*)  0x1fa124  size 52  13 条（0x1fa124..0x1fa158）
 * @func 0x1fa124 0x1fa158  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Key_Last_Get()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa124 push {r4, r5, r6, lr}
 *   @0x1fa128 mov r3, #0
 *   @0x1fa12c str r3, [r2, #0xc]
 *   @0x1fa130 mov r6, r2
 *   @0x1fa134 bl 0x18be94 <_Z15IO_Key_Last_Getv>
 *   @0x1fa138 vmov s15, r0
 *   @0x1fa13c mov r0, #1
 *   @0x1fa140 vcvt.f64.s32 d7, s15
 *   @0x1fa144 vmov r4, r5, d7
 *   @0x1fa148 vmov r2, s14
 *   @0x1fa14c mov r3, r5
 *   @0x1fa150 stm r6, {r2, r3}
 *   @0x1fa154 pop {r4, r5, r6, pc}
 *
 * ══ §358/561 GV_CurrentTime(CInstance*, int, RValue*)  0x1fa27c  size 52  13 条（0x1fa27c..0x1fa2b0）
 * @func 0x1fa27c 0x1fa2b0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time / anon_319414 / __floatdidf
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa27c push {r4, lr}
 *   @0x1fa280 mov r4, r2
 *   @0x1fa284 bl 0x215148 <Timing_Time>
 *   @0x1fa288 mov r12, #0
 *   @0x1fa28c mov r2, #1000
 *   @0x1fa290 mov r3, #0
 *   @0x1fa294 str r12, [r4, #0xc]
 *   @0x1fa298 bl 0x319414 <__aeabi_ldivmod>
 *   @0x1fa29c bl 0x319164 <__floatdidf>
 *   @0x1fa2a0 str r0, [r4]
 *   @0x1fa2a4 mov r0, #1
 *   @0x1fa2a8 str r1, [r4, #0x4]
 *   @0x1fa2ac pop {r4, pc}
 *
 * ══ §359/561 GV_ImageNumber(CInstance*, int, RValue*)  0x1fa9dc  size 52  13 条（0x1fa9dc..0x1faa10）
 * @func 0x1fa9dc 0x1faa10  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::GetImageNumber()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa9dc push {r4, r5, r6, lr}
 *   @0x1fa9e0 mov r3, #0
 *   @0x1fa9e4 str r3, [r2, #0xc]
 *   @0x1fa9e8 mov r6, r2
 *   @0x1fa9ec bl 0x19357c <_ZN9CInstance14GetImageNumberEv>
 *   @0x1fa9f0 vmov s15, r0
 *   @0x1fa9f4 mov r0, #1
 *   @0x1fa9f8 vcvt.f64.s32 d7, s15
 *   @0x1fa9fc vmov r4, r5, d7
 *   @0x1faa00 vmov r2, s14
 *   @0x1faa04 mov r3, r5
 *   @0x1faa08 stm r6, {r2, r3}
 *   @0x1faa0c pop {r4, r5, r6, pc}
 *
 * ══ §360/561 SetWorkingDirectory()  0x1fd150  size 52  13 条（0x1fd150..0x1fd184）
 * @func 0x1fd150 0x1fd184  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fd150 push {r4, lr}
 *   @0x1fd154 ldr r4, [pc, #0x20]
 *   @0x1fd158 ldr r4, [pc, r4]
 *   @0x1fd15c ldr r3, [r4]
 *   @0x1fd160 cmp r3, #0
 *   @0x1fd164 popne {r4, pc}
 *   @0x1fd168 ldr r0, [pc, #0x10]
 *   @0x1fd16c add r0, pc, r0
 *   @0x1fd170 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1fd174 str r0, [r4]
 *   @0x1fd178 pop {r4, pc}
 *   @0x1fd17c andseq r3, pc, r0, lsl #10
 *   @0x1fd180 andseq r5, r5, r12, lsl #18
 *
 * ══ §361/561 ExtractFileExt(char const*)  0x215008  size 52  13 条（0x215008..0x21503c）
 * @func 0x215008 0x21503c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strrchr
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215008 mov r1, #46
 *   @0x21500c push {r3, lr}
 *   @0x215010 mov r2, r1
 *   @0x215014 bl 0x10fbbc <utf8_strrchr>
 *   @0x215018 cmp r0, #0
 *   @0x21501c beq 0x215028 <_Z14ExtractFileExtPKc+0x20>
 *   @0x215020 pop {r3, lr}
 *   @0x215024 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x215028 ldr r0, [pc, #0x8]
 *   @0x21502c pop {r3, lr}
 *   @0x215030 add r0, pc, r0
 *   @0x215034 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x215038 andseq r9, r1, r6, lsl #22
 *
 * ══ §362/561 GetRecorder(int)  0x21c220  size 52  13 条（0x21c220..0x21c254）
 * @func 0x21c220 0x21c254  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetRecorder(int)+0x28
 * 字段偏移 top8: 0x20×1 / 0x50×1 / 0x54×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c220 cmp r0, #0
 *   @0x21c224 blt 0x21c248 <_Z11GetRecorderi+0x28>
 *   @0x21c228 ldr r3, [pc, #0x20]
 *   @0x21c22c add r3, pc, r3
 *   @0x21c230 ldr r2, [r3, #0x50]
 *   @0x21c234 cmp r0, r2
 *   @0x21c238 bge 0x21c248 <_Z11GetRecorderi+0x28>
 *   @0x21c23c ldr r3, [r3, #0x54]
 *   @0x21c240 ldr r0, [r3, r0, lsl #2]
 *   @0x21c244 bx lr
 *   @0x21c248 mov r0, #0
 *   @0x21c24c bx lr
 *   @0x21c250 subseq r9, r3, r8, rrx
 *
 * ══ §363/561 Audio_CreateSyncGroup(bool)  0x21d3c4  size 52  13 条（0x21d3c4..0x21d3f8）
 * @func 0x21d3c4 0x21d3f8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::Create_SyncThread(bool) / checkAL(char const*)
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d3c4 mov r1, r0
 *   @0x21d3c8 ldr r0, [pc, #0x20]
 *   @0x21d3cc push {r4, lr}
 *   @0x21d3d0 add r0, pc, r0
 *   @0x21d3d4 bl 0x225d94 <_ZN9COggAudio17Create_SyncThreadEb>
 *   @0x21d3d8 mov r4, r0
 *   @0x21d3dc ldr r0, [pc, #0x10]
 *   @0x21d3e0 add r0, pc, r0
 *   @0x21d3e4 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x21d3e8 mov r0, r4
 *   @0x21d3ec pop {r4, pc}
 *   @0x21d3f0 subseq r7, r3, r4, asr #29
 *   @0x21d3f4 ldrsbeq r0, [r4], -r0
 *
 * ══ §364/561 CAudioGroupMan::IsGroupLoaded(int)  0x21e1e0  size 52  13 条（0x21e1e0..0x21e214）
 * @func 0x21e1e0 0x21e214  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e1e0 cmp r1, #0
 *   @0x21e1e4 push {r3, lr}
 *   @0x21e1e8 bne 0x21e1f4 <_ZN14CAudioGroupMan13IsGroupLoadedEi+0x14>
 *   @0x21e1ec mov r0, #1
 *   @0x21e1f0 pop {r3, pc}
 *   @0x21e1f4 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21e1f8 cmp r0, #0
 *   @0x21e1fc popeq {r3, pc}
 *   @0x21e200 ldr r0, [r0]
 *   @0x21e204 subs r3, r0, #2
 *   @0x21e208 rsbs r0, r3, #0
 *   @0x21e20c adcs r0, r0, r3
 *   @0x21e210 pop {r3, pc}
 *
 * ══ §365/561 SoundHardware::PauseMusic()  0x2208e8  size 52  13 条（0x2208e8..0x22091c）
 * @func 0x2208e8 0x22091c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2208e8 ldr r3, [pc, #0x24]
 *   @0x2208ec ldr r3, [pc, r3]
 *   @0x2208f0 ldrb r3, [r3]
 *   @0x2208f4 cmp r3, #0
 *   @0x2208f8 bxne lr
 *   @0x2208fc ldr r3, [pc, #0x14]
 *   @0x220900 ldr r3, [pc, r3]
 *   @0x220904 ldrb r3, [r3]
 *   @0x220908 cmp r3, #0
 *   @0x22090c bxne lr
 *   @0x220910 b 0x2231c4 <_Z15OpenAL_PauseMP3v>
 *   @0x220914 andseq lr, r12, r0, ror #14
 *   @0x220918 andseq r0, sp, r0, lsr r11
 *
 * ══ §366/561 SoundHardware::ResumeMusic()  0x22091c  size 52  13 条（0x22091c..0x220950）
 * @func 0x22091c 0x220950  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22091c ldr r3, [pc, #0x24]
 *   @0x220920 ldr r3, [pc, r3]
 *   @0x220924 ldrb r3, [r3]
 *   @0x220928 cmp r3, #0
 *   @0x22092c bxne lr
 *   @0x220930 ldr r3, [pc, #0x14]
 *   @0x220934 ldr r3, [pc, r3]
 *   @0x220938 ldrb r3, [r3]
 *   @0x22093c cmp r3, #0
 *   @0x220940 bxne lr
 *   @0x220944 b 0x2231f4 <_Z16OpenAL_ResumeMP3v>
 *   @0x220948 andseq lr, r12, r12, lsr #14
 *   @0x22094c ldrsheq r0, [sp], -r12
 *
 * ══ §367/561 oggpack_adv1  0x233af0  size 52  13 条（0x233af0..0x233b24）
 * @func 0x233af0 0x233b24  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233af0 ldr r3, [r0, #0x4]
 *   @0x233af4 add r3, r3, #1
 *   @0x233af8 cmp r3, #7
 *   @0x233afc strle r3, [r0, #0x4]
 *   @0x233b00 ldrgt r2, [r0, #0xc]
 *   @0x233b04 movgt r1, #0
 *   @0x233b08 ldrgt r3, [r0]
 *   @0x233b0c addgt r2, r2, #1
 *   @0x233b10 strgt r1, [r0, #0x4]
 *   @0x233b14 addgt r3, r3, #1
 *   @0x233b18 strgt r2, [r0, #0xc]
 *   @0x233b1c strgt r3, [r0]
 *   @0x233b20 bx lr
 *
 * ══ §368/561 IniFile::ReadFloat(char const*, char const*, float)  0x235b44  size 52  13 条（0x235b44..0x235b78）
 * @func 0x235b44 0x235b78  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*) / 0xb6658
 * 字段偏移 top8: 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235b44 push {r4, lr}
 *   @0x235b48 mov r4, r3
 *   @0x235b4c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x235b50 cmp r0, #0
 *   @0x235b54 vmoveq s15, r4
 *   @0x235b58 beq 0x235b70 <_ZN7IniFile9ReadFloatEPKcS1_f+0x2c>
 *   @0x235b5c ldr r0, [r0, #0x8]
 *   @0x235b60 mov r1, #0
 *   @0x235b64 bl 0xb6658 <strtod@plt>
 *   @0x235b68 vmov d6, r0, r1
 *   @0x235b6c vcvt.f32.f64 s15, d6
 *   @0x235b70 vmov r0, s15
 *   @0x235b74 pop {r4, pc}
 *
 * ══ §369/561 CPhysicsWorld::SetDebugMode()  0x237b88  size 52  13 条（0x237b88..0x237bbc）
 * @func 0x237b88 0x237bbc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237b88 ldr r2, [pc, #0x20]
 *   @0x237b8c mov r0, #0
 *   @0x237b90 ldr r3, [pc, #0x1c]
 *   @0x237b94 ldr r2, [pc, r2]
 *   @0x237b98 ldr r1, [pc, #0x18]
 *   @0x237b9c ldr r3, [pc, r3]
 *   @0x237ba0 ldr r1, [pc, r1]
 *   @0x237ba4 str r1, [r2]
 *   @0x237ba8 strb r0, [r3]
 *   @0x237bac bx lr
 *   @0x237bb0 andseq r9, r11, r4, lsr r9
 *   @0x237bb4 andseq r9, r11, r8, lsr #18
 *   @0x237bb8 andseq r9, r11, r12, lsr #18
 *
 * ══ §370/561 CPhysicsWorld::GetValidCollisionData(CInstance*)  0x238cb0  size 52  13 条（0x238cb0..0x238ce4）
 * @func 0x238cb0 0x238ce4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×3 / 0xa4×2 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238cb0 ldr r0, [r0, #0xc]
 *   @0x238cb4 cmp r0, #0
 *   @0x238cb8 bxeq lr
 *   @0x238cbc ldr r2, [r0, #0x8]
 *   @0x238cc0 ldr r3, [r0, #0x4]
 *   @0x238cc4 ldr r2, [r2, #0x8]
 *   @0x238cc8 ldr r3, [r3, #0x8]
 *   @0x238ccc ldr r2, [r2, #0xa4]
 *   @0x238cd0 ldr r3, [r3, #0xa4]
 *   @0x238cd4 cmp r3, r1
 *   @0x238cd8 cmpne r2, r1
 *   @0x238cdc movne r0, #0
 *   @0x238ce0 bx lr
 *
 * ══ §371/561 CPhysicsWorld::SetParticleFlags(int, unsigned int)  0x23a160  size 52  13 条（0x23a160..0x23a194）
 * @func 0x23a160 0x23a194  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleFlagsBuffer()
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a160 push {r3, r4, r5, lr}
 *   @0x23a164 subs r4, r1, #0
 *   @0x23a168 mov r5, r2
 *   @0x23a16c poplt {r3, r4, r5, pc}
 *   @0x23a170 ldr r0, [r0, #0x10]
 *   @0x23a174 movw r3, #0x9298
 *   @0x23a178 movt r3, #0x1
 *   @0x23a17c ldr r3, [r0, r3]
 *   @0x23a180 cmp r4, r3
 *   @0x23a184 popge {r3, r4, r5, pc}
 *   @0x23a188 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv>
 *   @0x23a18c str r5, [r0, r4, lsl #2]
 *   @0x23a190 pop {r3, r4, r5, pc}
 *
 * ══ §372/561 F_JSTryUnHook(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c714  size 52  13 条（0x23c714..0x23c748）
 * @func 0x23c714 0x23c748  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c714 ldr r3, [pc, #0x28]
 *   @0x23c718 ldr r3, [pc, r3]
 *   @0x23c71c ldr r3, [r3]
 *   @0x23c720 ldr r3, [r3, #0x28]
 *   @0x23c724 cmp r3, #0
 *   @0x23c728 bxeq lr
 *   @0x23c72c ldr r0, [r3, #0x28]
 *   @0x23c730 cmp r0, #0
 *   @0x23c734 bxeq lr
 *   @0x23c738 ldr r2, [r0]
 *   @0x23c73c str r2, [r3, #0x28]
 *   @0x23c740 b 0x27d1d0 <_ZdlPv>
 *   @0x23c744 mulseq r11, r0, r4
 *
 * ══ §373/561 F_JS_IsPrimitive(RValue&)  0x241dc0  size 52  13 条（0x241dc0..0x241df4）
 * @func 0x241dc0 0x241df4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241dc0 ldr r3, [r0, #0xc]
 *   @0x241dc4 bic r3, r3, #-16777216
 *   @0x241dc8 cmp r3, #13
 *   @0x241dcc bhi 0x241dec <_Z16F_JS_IsPrimitiveR6RValue+0x2c>
 *   @0x241dd0 mov r2, #1
 *   @0x241dd4 movw r0, #0x34a3
 *   @0x241dd8 lsl r3, r2, r3
 *   @0x241ddc and r0, r3, r0
 *   @0x241de0 adds r0, r0, #0
 *   @0x241de4 movne r0, #1
 *   @0x241de8 bx lr
 *   @0x241dec mov r0, #0
 *   @0x241df0 bx lr
 *
 * ══ §374/561 JS_CheckObjectCoercible(RValue&)  0x2423a4  size 52  13 条（0x2423a4..0x2423d8）
 * @func 0x2423a4 0x2423d8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2423a4 ldr r3, [r0, #0xc]
 *   @0x2423a8 bic r3, r3, #-16777216
 *   @0x2423ac cmp r3, #10
 *   @0x2423b0 bhi 0x2423d0 <_Z23JS_CheckObjectCoercibleR6RValue+0x2c>
 *   @0x2423b4 mov r2, #1
 *   @0x2423b8 movw r0, #0x4c3
 *   @0x2423bc lsl r3, r2, r3
 *   @0x2423c0 and r0, r3, r0
 *   @0x2423c4 rsbs r0, r0, #1
 *   @0x2423c8 movlo r0, #0
 *   @0x2423cc bx lr
 *   @0x2423d0 mov r0, #1
 *   @0x2423d4 bx lr
 *
 * ══ §375/561 _ToEntry_create  0x283ac4  size 52  13 条（0x283ac4..0x283af8）
 * @func 0x283ac4 0x283af8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283ac4 ldr r2, [pc, #0x28]
 *   @0x283ac8 push {r3, r4, r5, lr}
 *   @0x283acc add r2, pc, r2
 *   @0x283ad0 mov r5, r0
 *   @0x283ad4 mov r4, r1
 *   @0x283ad8 mov r3, #43
 *   @0x283adc mov r1, #12
 *   @0x283ae0 mov r0, #1
 *   @0x283ae4 bl 0x285c4c <_calloc>
 *   @0x283ae8 str r5, [r0]
 *   @0x283aec str r4, [r0, #0x4]
 *   @0x283af0 pop {r3, r4, r5, pc}
 *   @0x283af4 strdeq r3, r4, [sp], -r8
 *
 * ══ §376/561 spEvent_create  0x285b44  size 52  13 条（0x285b44..0x285b78）
 * @func 0x285b44 0x285b78  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285b44 ldr r2, [pc, #0x28]
 *   @0x285b48 push {r3, r4, r5, lr}
 *   @0x285b4c add r2, pc, r2
 *   @0x285b50 mov r4, r0
 *   @0x285b54 mov r5, r1
 *   @0x285b58 mov r3, #36
 *   @0x285b5c mov r1, #20
 *   @0x285b60 mov r0, #1
 *   @0x285b64 bl 0x285c4c <_calloc>
 *   @0x285b68 str r5, [r0]
 *   @0x285b6c str r4, [r0, #0x4]
 *   @0x285b70 pop {r3, r4, r5, pc}
 *   @0x285b74 andeq r1, sp, r12, asr #24
 *
 * ══ §377/561 spSkeletonJson_createWithLoader  0x28b700  size 52  13 条（0x28b700..0x28b734）
 * @func 0x28b700 0x28b734  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x28×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b700 ldr r2, [pc, #0x28]
 *   @0x28b704 mov r1, #28
 *   @0x28b708 push {r4, lr}
 *   @0x28b70c add r2, pc, r2
 *   @0x28b710 mov r4, r0
 *   @0x28b714 mov r3, #62
 *   @0x28b718 mov r0, #1
 *   @0x28b71c bl 0x285c4c <_calloc>
 *   @0x28b720 mov r2, #1065353216
 *   @0x28b724 str r4, [r0, #0x4]
 *   @0x28b728 str r2, [r0]
 *   @0x28b72c pop {r4, pc}
 *   @0x28b730 strdeq r12, sp, [r12], -r4
 *
 * ══ §378/561 Java_com_yoyogames_runner_RunnerJNILib_getGuiWidth  0x292a14  size 52  13 条（0x292a14..0x292a48）
 * @func 0x292a14 0x292a48  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292a14 push {r3, lr}
 *   @0x292a18 bl 0x290614 <setJNIEnv>
 *   @0x292a1c ldr r3, [pc, #0x1c]
 *   @0x292a20 ldr r3, [pc, r3]
 *   @0x292a24 ldr r0, [r3]
 *   @0x292a28 cmp r0, #0
 *   @0x292a2c popge {r3, pc}
 *   @0x292a30 ldr r3, [pc, #0xc]
 *   @0x292a34 ldr r3, [pc, r3]
 *   @0x292a38 ldr r0, [r3]
 *   @0x292a3c pop {r3, pc}
 *   @0x292a40 andseq sp, r5, r8, asr #2
 *   @0x292a44 andseq sp, r5, r8, ror #8
 *
 * ══ §379/561 Java_com_yoyogames_runner_RunnerJNILib_getGuiHeight  0x292a48  size 52  13 条（0x292a48..0x292a7c）
 * @func 0x292a48 0x292a7c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292a48 push {r3, lr}
 *   @0x292a4c bl 0x290614 <setJNIEnv>
 *   @0x292a50 ldr r3, [pc, #0x1c]
 *   @0x292a54 ldr r3, [pc, r3]
 *   @0x292a58 ldr r0, [r3]
 *   @0x292a5c cmp r0, #0
 *   @0x292a60 popge {r3, pc}
 *   @0x292a64 ldr r3, [pc, #0xc]
 *   @0x292a68 ldr r3, [pc, r3]
 *   @0x292a6c ldr r0, [r3]
 *   @0x292a70 pop {r3, pc}
 *   @0x292a74 andseq sp, r5, r0, lsr #2
 *   @0x292a78 andseq sp, r5, r8, lsr r4
 *
 * ══ §380/561 yySocket::AllocateBuffer(int)  0x296080  size 52  13 条（0x296080..0x2960b4）
 * @func 0x296080 0x2960b4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x20×1 / 0x54×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296080 push {r3, r4, r5, lr}
 *   @0x296084 mov r5, r1
 *   @0x296088 ldr r1, [pc, #0x20]
 *   @0x29608c mov r4, r0
 *   @0x296090 mov r2, #190
 *   @0x296094 mov r0, r5
 *   @0x296098 add r1, pc, r1
 *   @0x29609c mov r3, #1
 *   @0x2960a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2960a4 str r5, [r4, #0x54]
 *   @0x2960a8 str r0, [r4, #0x50]
 *   @0x2960ac pop {r3, r4, r5, pc}
 *   @0x2960b0 andeq r3, r12, r8, asr #6
 *
 * ══ §381/561 InitNetworking()  0x298df4  size 52  13 条（0x298df4..0x298e28）
 * @func 0x298df4 0x298e28  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x-8×1 / 0x-7×1 / 0x-4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298df4 ldr r1, [pc, #0x28]
 *   @0x298df8 mov r2, #0
 *   @0x298dfc ldr r1, [pc, r1]
 *   @0x298e00 add r3, r1, #8
 *   @0x298e04 add r1, r1, #776
 *   @0x298e08 strb r2, [r3, #-0x8]
 *   @0x298e0c strb r2, [r3, #-0x7]
 *   @0x298e10 str r2, [r3, #-0x4]
 *   @0x298e14 str r2, [r3], #12
 *   @0x298e18 cmp r3, r1
 *   @0x298e1c bne 0x298e08 <_Z14InitNetworkingv+0x14>
 *   @0x298e20 bx lr
 *   @0x298e24 andseq r8, r5, r8, lsr #23
 *
 * ══ §382/561 RelyClearList()  0x299c34  size 52  13 条（0x299c34..0x299c68）
 * @func 0x299c34 0x299c68  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RelyDeletePacket(SRelyEntry*)
 * 字段偏移 top8: 0x28×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299c34 ldr r3, [pc, #0x28]
 *   @0x299c38 push {r4, lr}
 *   @0x299c3c ldr r3, [pc, r3]
 *   @0x299c40 ldr r4, [r3]
 *   @0x299c44 cmp r4, #0
 *   @0x299c48 popeq {r4, pc}
 *   @0x299c4c ldr r4, [r4, #0x20]
 *   @0x299c50 mov r0, r4
 *   @0x299c54 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry>
 *   @0x299c58 cmp r4, #0
 *   @0x299c5c bne 0x299c4c <_Z13RelyClearListv+0x18>
 *   @0x299c60 pop {r4, pc}
 *   @0x299c64 ldrheq r7, [r5], -r8
 *
 * ══ §383/561 png_get_pixel_aspect_ratio  0x2a664c  size 52  13 条（0x2a664c..0x2a6680）
 * @func 0x2a664c 0x2a6680  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a664c cbz r0, 0x2a6670 <png_get_pixel_aspect_ratio+0x24>
 *   @0x2a6650 ldr r3, [r1, #0x8]
 *   @0x2a6654 bpl 0x2a6670 <png_get_pixel_aspect_ratio+0x24>
 *   @0x2a6658 cbz r3, 0x2a6670 <png_get_pixel_aspect_ratio+0x24>
 *   @0x2a665c vldr s7, [r1, #576]
 *   @0x2a6660 vmrs r7, fpexc
 *   @0x2a6664 vcvt.f32.u32 s14, s15
 *   @0x2a6668 .word 0xeec77a66
 *   @0x2a666c and r7, r1, r7, lsl #21
 *   @0x2a6670 vldr s15, [pc, #8]
 *   @0x2a6674 vmov r0, s15
 *   @0x2a6678 bx lr
 *   @0x2a667c movs r0, r0
 *
 * ══ §384/561 png_get_pHYs  0x2a6a9c  size 52  13 条（0x2a6a9c..0x2a6ad0）
 * @func 0x2a6a9c 0x2a6ad0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6a9c push {r4, lr}
 *   @0x2a6aa0 cbz r0, 0x2a6ace <png_get_pHYs+0x32>
 *   @0x2a6aa4 ldr r0, [r1, #0x8]
 *   @0x2a6aa8 andsle r0, r0, r0, lsl #1
 *   @0x2a6aac cbz r2, 0x2a6ab6 <png_get_pHYs+0x1a>
 *   @0x2a6ab0 str r0, [r2]
 *   @0x2a6ab4 b 0x2a6ab8 <png_get_pHYs+0x1c>
 *   @0x2a6ab8 cbz r3, 0x2a6ac0 <png_get_pHYs+0x24>
 *   @0x2a6abc movs r0, #0x80
 *   @0x2a6ac0 cbz r4, 0x2a6ace <png_get_pHYs+0x32>
 *   @0x2a6ac4 addhs r3, r0, r8, ror r0
 *   @0x2a6ac8 str r3, [r4]
 *   @0x2a6acc mov r0, r1
 *
 * ══ §385/561 png_write_IEND  0x2b178c  size 52  13 条（0x2b178c..0x2b17c0）
 * @func 0x2b178c 0x2b17c0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk
 * 字段偏移 top8: 0x2c×1 / 0x17×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b178c ldr r3, [pc, #0x2c]
 *   @0x2b1790 push {r0, r1, r4, lr}
 *   @0x2b1794 mov r4, r0
 *   @0x2b1798 ldr r0, [r3, #23]!
 *   @0x2b179c ldrb r3, [r3, #0x4]
 *   @0x2b17a0 mov r0, r4
 *   @0x2b17a4 ldrmi r3, [r3], -r4
 *   @0x2b17a8 bl 0x2b12bc <png_write_chunk>
 *   @0x2b17ac ldr.w r3, [r4, #0x12c]
 *   @0x2b17b0 orr r3, r3, #0x10
 *   @0x2b17b4 str.w r3, [r4, #0x12c]
 *   @0x2b17b8 add sp, #0x8
 *   @0x2b17bc b 0x2b135c <png_write_IHDR+0x78>
 *
 * ══ §386/561 png_write_gAMA_fixed  0x2b1818  size 52  13 条（0x2b1818..0x2b184c）
 * @func 0x2b1818 0x2b184c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1818 ldr r3, [pc, #0x2c]
 *   @0x2b181c add r3, pc
 *   @0x2b1820 sub sp, #0x14
 *   @0x2b1824 .word 0xac010f1c
 *   @0x2b1828 ldrb r3, [r3, #0x4]
 *   @0x2b182c mov r0, r4
 *   @0x2b1830 .word 0xf7ff300c
 *   @0x2b1834 qsub16mi pc, r8, r7
 *   @0x2b1838 add r1, sp, #0x8
 *   @0x2b183c movs r3, #0x4
 *   @0x2b1840 andlt pc, r5, sp, lsr sp
 *   @0x2b1844 pop {r4, r5, pc}
 *   @0x2b1848 b 0x2b12d4 <png_write_chunk+0x18>
 *
 * ══ §387/561 jpeg_idct_1x1  0x2c1240  size 52  13 条（0x2c1240..0x2c1274）
 * @func 0x2c1240 0x2c1274  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x50×1 / 0x120×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1240 ldr r1, [r1, #0x50]
 *   @0x2c1244 ldrsh r2, [r2]
 *   @0x2c1248 ldr r0, [r0, #0x120]
 *   @0x2c124c ldr r1, [r1]
 *   @0x2c1250 ldr r12, [r3]
 *   @0x2c1254 ldr r3, [sp]
 *   @0x2c1258 mul r2, r1, r2
 *   @0x2c125c add r2, r2, #4
 *   @0x2c1260 ubfx r2, r2, #0x3, #0xa
 *   @0x2c1264 add r0, r0, r2
 *   @0x2c1268 ldrb r2, [r0, #0x80]
 *   @0x2c126c strb r2, [r12, r3]
 *   @0x2c1270 bx lr
 *
 * ══ §388/561 b2EdgeShape::Set(b2Vec2 const&, b2Vec2 const&)  0x2c5630  size 52  13 条（0x2c5630..0x2c5664）
 * @func 0x2c5630 0x2c5664  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0x2d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5630 mov r3, r0
 *   @0x2c5634 ldm r1, {r0, r1}
 *   @0x2c5638 push {r4, r5}
 *   @0x2c563c add r5, r3, #12
 *   @0x2c5640 add r4, r3, #20
 *   @0x2c5644 mov r12, #0
 *   @0x2c5648 stm r5, {r0, r1}
 *   @0x2c564c ldm r2, {r0, r1}
 *   @0x2c5650 stm r4, {r0, r1}
 *   @0x2c5654 strb r12, [r3, #0x2c]
 *   @0x2c5658 strb r12, [r3, #0x2d]
 *   @0x2c565c pop {r4, r5}
 *   @0x2c5660 bx lr
 *
 * ══ §389/561 b2Body::SetFixedRotation(bool)  0x2c7580  size 52  13 条（0x2c7580..0x2c75b4）
 * @func 0x2c7580 0x2c75b4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7580 ldrh r2, [r0, #4]
 *   @0x2c7584 mov r3, r0
 *   @0x2c7588 ubfx r0, r2, #0x4, #0x1
 *   @0x2c758c cmp r0, r1
 *   @0x2c7590 bxeq lr
 *   @0x2c7594 cmp r1, #0
 *   @0x2c7598 mov r0, r3
 *   @0x2c759c orrne r2, r2, #16
 *   @0x2c75a0 biceq r2, r2, #16
 *   @0x2c75a4 strh r2, [r3, #4]
 *   @0x2c75a8 mov r2, #0
 *   @0x2c75ac str r2, [r3, #0x58]
 *   @0x2c75b0 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv>
 *
 * ══ §390/561 b2EdgeAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2cc4c0  size 52  13 条（0x2cc4c0..0x2cc4f4）
 * @func 0x2cc4c0 0x2cc4f4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x34×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc4c0 mov r12, r0
 *   @0x2cc4c4 mov r0, r1
 *   @0x2cc4c8 ldr r1, [r12, #0x30]
 *   @0x2cc4cc ldr r12, [r12, #0x34]
 *   @0x2cc4d0 str lr, [sp, #-0x4]!
 *   @0x2cc4d4 sub sp, sp, #12
 *   @0x2cc4d8 ldr r12, [r12, #0xc]
 *   @0x2cc4dc ldr r1, [r1, #0xc]
 *   @0x2cc4e0 str r3, [sp]
 *   @0x2cc4e4 mov r3, r12
 *   @0x2cc4e8 bl 0x2dceb0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_>
 *   @0x2cc4ec add sp, sp, #12
 *   @0x2cc4f0 ldr pc, [sp], #4
 *
 * ══ §391/561 b2EdgeAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2cc55c  size 52  13 条（0x2cc55c..0x2cc590）
 * @func 0x2cc55c 0x2cc590  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2EdgeAndCircleContact::b2EdgeAndCircleContact(b2Fixture*, b2Fixture*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc55c push {r4, r5, r6, lr}
 *   @0x2cc560 mov r1, #148
 *   @0x2cc564 mov r5, r0
 *   @0x2cc568 ldr r0, [sp, #0x10]
 *   @0x2cc56c mov r6, r2
 *   @0x2cc570 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cc574 subs r4, r0, #0
 *   @0x2cc578 beq 0x2cc588 <_ZN22b2EdgeAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2cc57c mov r1, r5
 *   @0x2cc580 mov r2, r6
 *   @0x2cc584 bl 0x2cc520 <_ZN22b2EdgeAndCircleContactC2EP9b2FixtureS1_>
 *   @0x2cc588 mov r0, r4
 *   @0x2cc58c pop {r4, r5, r6, pc}
 *
 * ══ §392/561 b2EdgeAndPolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2cc5d0  size 52  13 条（0x2cc5d0..0x2cc604）
 * @func 0x2cc5d0 0x2cc604  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollideEdgeAndPolygon(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x34×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc5d0 mov r12, r0
 *   @0x2cc5d4 mov r0, r1
 *   @0x2cc5d8 ldr r1, [r12, #0x30]
 *   @0x2cc5dc ldr r12, [r12, #0x34]
 *   @0x2cc5e0 str lr, [sp, #-0x4]!
 *   @0x2cc5e4 sub sp, sp, #12
 *   @0x2cc5e8 ldr r12, [r12, #0xc]
 *   @0x2cc5ec ldr r1, [r1, #0xc]
 *   @0x2cc5f0 str r3, [sp]
 *   @0x2cc5f4 mov r3, r12
 *   @0x2cc5f8 bl 0x2de0bc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_>
 *   @0x2cc5fc add sp, sp, #12
 *   @0x2cc600 ldr pc, [sp], #4
 *
 * ══ §393/561 b2EdgeAndPolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2cc66c  size 52  13 条（0x2cc66c..0x2cc6a0）
 * @func 0x2cc66c 0x2cc6a0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2EdgeAndPolygonContact::b2EdgeAndPolygonContact(b2Fixture*, b2Fixture*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc66c push {r4, r5, r6, lr}
 *   @0x2cc670 mov r1, #148
 *   @0x2cc674 mov r5, r0
 *   @0x2cc678 ldr r0, [sp, #0x10]
 *   @0x2cc67c mov r6, r2
 *   @0x2cc680 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cc684 subs r4, r0, #0
 *   @0x2cc688 beq 0x2cc698 <_ZN23b2EdgeAndPolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2cc68c mov r1, r5
 *   @0x2cc690 mov r2, r6
 *   @0x2cc694 bl 0x2cc630 <_ZN23b2EdgeAndPolygonContactC2EP9b2FixtureS1_>
 *   @0x2cc698 mov r0, r4
 *   @0x2cc69c pop {r4, r5, r6, pc}
 *
 * ══ §394/561 b2PolygonAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2cc6e0  size 52  13 条（0x2cc6e0..0x2cc714）
 * @func 0x2cc6e0 0x2cc714  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollidePolygonAndCircle(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x34×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc6e0 mov r12, r0
 *   @0x2cc6e4 mov r0, r1
 *   @0x2cc6e8 ldr r1, [r12, #0x30]
 *   @0x2cc6ec ldr r12, [r12, #0x34]
 *   @0x2cc6f0 str lr, [sp, #-0x4]!
 *   @0x2cc6f4 sub sp, sp, #12
 *   @0x2cc6f8 ldr r12, [r12, #0xc]
 *   @0x2cc6fc ldr r1, [r1, #0xc]
 *   @0x2cc700 str r3, [sp]
 *   @0x2cc704 mov r3, r12
 *   @0x2cc708 bl 0x2dcad0 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_>
 *   @0x2cc70c add sp, sp, #12
 *   @0x2cc710 ldr pc, [sp], #4
 *
 * ══ §395/561 b2PolygonAndCircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2cc77c  size 52  13 条（0x2cc77c..0x2cc7b0）
 * @func 0x2cc77c 0x2cc7b0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2PolygonAndCircleContact::b2PolygonAndCircleContact(b2Fixture*, b2Fixture*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc77c push {r4, r5, r6, lr}
 *   @0x2cc780 mov r1, #148
 *   @0x2cc784 mov r5, r0
 *   @0x2cc788 ldr r0, [sp, #0x10]
 *   @0x2cc78c mov r6, r2
 *   @0x2cc790 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cc794 subs r4, r0, #0
 *   @0x2cc798 beq 0x2cc7a8 <_ZN25b2PolygonAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2cc79c mov r1, r5
 *   @0x2cc7a0 mov r2, r6
 *   @0x2cc7a4 bl 0x2cc740 <_ZN25b2PolygonAndCircleContactC2EP9b2FixtureS1_>
 *   @0x2cc7a8 mov r0, r4
 *   @0x2cc7ac pop {r4, r5, r6, pc}
 *
 * ══ §396/561 b2PolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2cc7f0  size 52  13 条（0x2cc7f0..0x2cc824）
 * @func 0x2cc7f0 0x2cc824  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x34×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc7f0 mov r12, r0
 *   @0x2cc7f4 mov r0, r1
 *   @0x2cc7f8 ldr r1, [r12, #0x30]
 *   @0x2cc7fc ldr r12, [r12, #0x34]
 *   @0x2cc800 str lr, [sp, #-0x4]!
 *   @0x2cc804 sub sp, sp, #12
 *   @0x2cc808 ldr r12, [r12, #0xc]
 *   @0x2cc80c ldr r1, [r1, #0xc]
 *   @0x2cc810 str r3, [sp]
 *   @0x2cc814 mov r3, r12
 *   @0x2cc818 bl 0x2de464 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_>
 *   @0x2cc81c add sp, sp, #12
 *   @0x2cc820 ldr pc, [sp], #4
 *
 * ══ §397/561 b2PolygonContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2cc88c  size 52  13 条（0x2cc88c..0x2cc8c0）
 * @func 0x2cc88c 0x2cc8c0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2PolygonContact::b2PolygonContact(b2Fixture*, b2Fixture*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc88c push {r4, r5, r6, lr}
 *   @0x2cc890 mov r1, #148
 *   @0x2cc894 mov r5, r0
 *   @0x2cc898 ldr r0, [sp, #0x10]
 *   @0x2cc89c mov r6, r2
 *   @0x2cc8a0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cc8a4 subs r4, r0, #0
 *   @0x2cc8a8 beq 0x2cc8b8 <_ZN16b2PolygonContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2cc8ac mov r1, r5
 *   @0x2cc8b0 mov r2, r6
 *   @0x2cc8b4 bl 0x2cc850 <_ZN16b2PolygonContactC2EP9b2FixtureS1_>
 *   @0x2cc8b8 mov r0, r4
 *   @0x2cc8bc pop {r4, r5, r6, pc}
 *
 * ══ §398/561 b2CircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2e1fc0  size 52  13 条（0x2e1fc0..0x2e1ff4）
 * @func 0x2e1fc0 0x2e1ff4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollideCircles(b2Manifold*, b2CircleShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×2 / 0x30×1 / 0x34×1 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1fc0 mov r12, r0
 *   @0x2e1fc4 mov r0, r1
 *   @0x2e1fc8 ldr r1, [r12, #0x30]
 *   @0x2e1fcc ldr r12, [r12, #0x34]
 *   @0x2e1fd0 str lr, [sp, #-0x4]!
 *   @0x2e1fd4 sub sp, sp, #12
 *   @0x2e1fd8 ldr r12, [r12, #0xc]
 *   @0x2e1fdc ldr r1, [r1, #0xc]
 *   @0x2e1fe0 str r3, [sp]
 *   @0x2e1fe4 mov r3, r12
 *   @0x2e1fe8 bl 0x2dc9f0 <_Z16b2CollideCirclesP10b2ManifoldPK13b2CircleShapeRK11b2TransformS3_S6_>
 *   @0x2e1fec add sp, sp, #12
 *   @0x2e1ff0 ldr pc, [sp], #4
 *
 * ══ §399/561 b2CircleContact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2e205c  size 52  13 条（0x2e205c..0x2e2090）
 * @func 0x2e205c 0x2e2090  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2CircleContact::b2CircleContact(b2Fixture*, b2Fixture*)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e205c push {r4, r5, r6, lr}
 *   @0x2e2060 mov r1, #148
 *   @0x2e2064 mov r5, r0
 *   @0x2e2068 ldr r0, [sp, #0x10]
 *   @0x2e206c mov r6, r2
 *   @0x2e2070 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2e2074 subs r4, r0, #0
 *   @0x2e2078 beq 0x2e2088 <_ZN15b2CircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2e207c mov r1, r5
 *   @0x2e2080 mov r2, r6
 *   @0x2e2084 bl 0x2e2020 <_ZN15b2CircleContactC2EP9b2FixtureS1_>
 *   @0x2e2088 mov r0, r4
 *   @0x2e208c pop {r4, r5, r6, pc}
 *
 * ══ §400/561 anon_2e4db4  0x2e4db4  size 52  13 条（0x2e4db4..0x2e4de8）
 * @func 0x2e4db4 0x2e4de8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x16×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4db4 streq pc, [r1], #-19
 *   @0x2e4db8 tstle r5, r7, lsl r6
 *   @0x2e4dbc orrlt r6, r8, r0, lsl #16
 *   @0x2e4dc0 .word 0xf0136905
 *   @0x2e4dc4 stmdbvs r2, {r4, r8, r9, r10, r11} ^
 *   @0x2e4dc8 svclt #0x18460e
 *   @0x2e4dcc adcsmi r4, r12, #22020096
 *   @0x2e4dd0 ldmdavs r0!, {r1, r3, r12, lr, pc}
 *   @0x2e4dd4 subhs r4, r0, #42991616
 *   @0x2e4dd8 .word 0xf7ff3401
 *   @0x2e4ddc .word 0xf846ffaf
 *   @0x2e4de0 ldrb r0, [r4, r4, lsl #22]!
 *   @0x2e4de4 ldcllt p0, c2, [r8, #144]!
 *
 * ══ §401/561 FT_Get_Sfnt_Table  0x2e5bc0  size 52  13 条（0x2e5bc0..0x2e5bf4）
 * @func 0x2e5bc0 0x2e5bf4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5bc0 push {r3, r4, r5, lr}
 *   @0x2e5bc4 mov r4, r0
 *   @0x2e5bc8 movs r0, #0x0
 *   @0x2e5bcc ldr r3, [r0, #0x8]
 *   @0x2e5bd0 bpl 0x2e5bc8 <FT_Get_Sfnt_Table+0x8>
 *   @0x2e5bd4 ldr r3, [r0]
 *   @0x2e5bd8 cmp r3, #0x0
 *   @0x2e5bdc ldr r1, [pc, #0x10]
 *   @0x2e5be0 blx r3
 *   @0x2e5be4 beq 0x2e5bc8 <FT_Get_Sfnt_Table+0x8>
 *   @0x2e5be8 mov r1, r5
 *   @0x2e5bec blx r3
 *   @0x2e5bf0 ldrh r6, [r5, #0x18]
 *
 * ══ §402/561 ft_lzwstate_init  0x316e5a  size 52  13 条（0x316e5a..0x316e8e）
 * @func 0x316e5a 0x316e8e  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316e5a push {r3, r4, r5, lr}
 *   @0x316e5e mov r4, r0
 *   @0x316e62 movs r1, #0x0
 *   @0x316e66 .word 0xf8c4eba4
 *   @0x316e6a stmibvs r11!, {r2, r5, r7, r12, lr} ^
 *   @0x316e6e mov r0, r4
 *   @0x316e72 movwhs r3, #0xa8
 *   @0x316e76 str r3, [r4, #0x4c]
 *   @0x316e7a str r3, [r4, #0x54]
 *   @0x316e7e strvs r0, [r3, #0x364]!
 *   @0x316e82 movs r3, #0x40
 *   @0x316e86 pop.w {r3, r4, r5, lr}
 *   @0x316e8a b.w 0x316e42 <ft_lzwstate_reset>
 *
 * ══ §403/561 png_get_sCAL  0x2a6a6a  size 50  13 条（0x2a6a6a..0x2a6a9c）
 * @func 0x2a6a6a 0x2a6a9c  size 50  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6a6a push {r4, lr}
 *   @0x2a6a6e cbz r0, 0x2a6a9a <png_get_sCAL+0x30>
 *   @0x2a6a72 ldr r0, [r1, #0x8]
 *   @0x2a6a76 andle r4, pc, r0, lsl #1
 *   @0x2a6a7a ldrb.w r3, [r1, #0xdc]
 *   @0x2a6a7e mov.w r0, #0x4000
 *   @0x2a6a82 str r3, [r2]
 *   @0x2a6a86 stmib r4, {r3, r4, r5, r8, r9, sp} ^
 *   @0x2a6a8a ldmib r1, {r8, r9, sp} ^
 *   @0x2a6a8e stmdbls r2, {r1, r3, r4, r5, r8, r9, sp}
 *   @0x2a6a92 strd r2, r3, [r1]
 *   @0x2a6a96 pop {r4, pc}
 *   @0x2a6a9a pop {r4, pc}
 *
 * ══ §404/561 FT_Select_Size  0x2e56fa  size 50  13 条（0x2e56fa..0x2e572c）
 * @func 0x2e56fa 0x2e572c  size 50  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Select_Size+0x2e
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x5c×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e56fa push {r4, lr}
 *   @0x2e56fe ldr r4, [r0, #0x8]
 *   @0x2e5702 bpl 0x2e5724 <FT_Select_Size+0x2a>
 *   @0x2e5706 blt 0x2e5728 <FT_Select_Size+0x2e>
 *   @0x2e570a cmp r1, r4
 *   @0x2e570e ldr r2, [r0, #0x60]
 *   @0x2e5712 ldr r4, [r2, #0x5c]
 *   @0x2e5716 ldr r0, [r0, #0x58]
 *   @0x2e571a pop {r4, pc}
 *   @0x2e571e strtmi pc, [r0], -r2, lsl #30
 *   @0x2e5722 pop {r4, pc}
 *   @0x2e5726 pop {r4, pc}
 *   @0x2e572a pop {r4, pc}
 *
 * ══ §405/561 FT_Lookup_Renderer  0x2e5e36  size 50  13 条（0x2e5e36..0x2e5e68）
 * @func 0x2e5e36 0x2e5e68  size 50  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5e36 push {r4, lr}
 *   @0x2e5e3a movs r0, #0x0
 *   @0x2e5e3e ldr.w r3, [r0, #0x94]
 *   @0x2e5e42 cbz r2, 0x2e5e5a <FT_Lookup_Renderer+0x24>
 *   @0x2e5e46 cbz r0, 0x2e5e4a <FT_Lookup_Renderer+0x14>
 *   @0x2e5e4a movs r0, #0x0
 *   @0x2e5e4e b 0x2e5e5a <FT_Lookup_Renderer+0x24>
 *   @0x2e5e52 ldr r4, [r0, #0x10]
 *   @0x2e5e56 beq 0x2e5e60 <FT_Lookup_Renderer+0x2a>
 *   @0x2e5e5a cmp r3, #0x0
 *   @0x2e5e5e b 0x2e5e3a <FT_Lookup_Renderer+0x4>
 *   @0x2e5e62 str r3, [r2]
 *   @0x2e5e66 pop {r4, pc}
 *
 * ══ §406/561 ft_glyphslot_free_bitmap  0x2e7522  size 50  13 条（0x2e7522..0x2e7554）
 * @func 0x2e7522 0x2e7554  size 50  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x64×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7522 push {r4, lr}
 *   @0x2e7526 ldr.w r3, [r0, #0x9c]
 *   @0x2e752a cbz r3, 0x2e754e <ft_glyphslot_free_bitmap+0x2c>
 *   @0x2e752e lsls r3, r3, #0x1f
 *   @0x2e7532 ldr r3, [r0, #0x4]
 *   @0x2e7536 ldr r0, [r3, #0x64]
 *   @0x2e753a movwhs pc, #0xefd
 *   @0x2e753e str r3, [r4, #0x58]
 *   @0x2e7542 ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^
 *   @0x2e7546 bic r2, r2, #0x1
 *   @0x2e754a str r2, [r3, #0x4]
 *   @0x2e754e movs r3, #0x0
 *   @0x2e7552 pop {r4, pc}
 *
 * ══ §407/561 FT_Init_FreeType  0x2e9b30  size 50  13 条（0x2e9b30..0x2e9b62）
 * @func 0x2e9b30 0x2e9b62  size 50  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_New_Memory / FT_Done_Memory / FT_Add_Default_Modules
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9b30 push {r4, r5, r6, lr}
 *   @0x2e9b34 bl 0x2e9c44 <FT_New_Memory>
 *   @0x2e9b38 mov r6, r0
 *   @0x2e9b3c mov r1, r4
 *   @0x2e9b40 .word 0x4605fbdb
 *   @0x2e9b44 cbz r0, 0x2e9b4e <FT_Init_FreeType+0x1e>
 *   @0x2e9b48 bl 0x2e9c74 <FT_Done_Memory>
 *   @0x2e9b4c b 0x2e9b54 <FT_Init_FreeType+0x24>
 *   @0x2e9b50 bl 0x2e9a20 <FT_Add_Default_Modules>
 *   @0x2e9b54 ldr r0, [r4]
 *   @0x2e9b58 qsub16mi pc, r8, r3
 *   @0x2e9b5c pop {r4, r5, r6, pc}
 *   @0x2e9b60 pop {r4, r5, r6, pc}
 *
 * ══ §408/561 Buffer_Fast::~Buffer_Fast()  0xc4bf4  size 48  12 条（0xc4bf4..0xc4c24）
 * @func 0xc4bf4 0xc4c24  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4bf4 ldr r3, [pc, #0x24]
 *   @0xc4bf8 push {r4, lr}
 *   @0xc4bfc ldr r3, [pc, r3]
 *   @0xc4c00 mov r4, r0
 *   @0xc4c04 add r3, r3, #8
 *   @0xc4c08 str r3, [r0]
 *   @0xc4c0c bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xc4c10 mov r0, r4
 *   @0xc4c14 bl 0x27d1d0 <_ZdlPv>
 *   @0xc4c18 mov r0, r4
 *   @0xc4c1c pop {r4, pc}
 *   @0xc4c20 ldrhteq r8, [r2], -r0
 *
 * ══ §409/561 Buffer_Standard::~Buffer_Standard()  0xc4d30  size 48  12 条（0xc4d30..0xc4d60）
 * @func 0xc4d30 0xc4d60  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4d30 ldr r3, [pc, #0x24]
 *   @0xc4d34 push {r4, lr}
 *   @0xc4d38 ldr r3, [pc, r3]
 *   @0xc4d3c mov r4, r0
 *   @0xc4d40 add r3, r3, #8
 *   @0xc4d44 str r3, [r0]
 *   @0xc4d48 bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xc4d4c mov r0, r4
 *   @0xc4d50 bl 0x27d1d0 <_ZdlPv>
 *   @0xc4d54 mov r0, r4
 *   @0xc4d58 pop {r4, pc}
 *   @0xc4d5c eorseq r8, r2, r8, ror r12
 *
 * ══ §410/561 F_Vertex_Freeze_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xca5a8  size 48  12 条（0xca5a8..0xca5d8）
 * @func 0xca5a8 0xca5d8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetBufferVertex(int)
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca5a8 push {r3, lr}
 *   @0xca5ac mov r1, #0
 *   @0xca5b0 ldr r12, [sp, #0x8]
 *   @0xca5b4 mov r2, r1
 *   @0xca5b8 str r1, [r0, #0xc]
 *   @0xca5bc movt r2, #0xbff0
 *   @0xca5c0 stm r0, {r1, r2}
 *   @0xca5c4 mov r0, r12
 *   @0xca5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca5cc bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xca5d0 pop {r3, lr}
 *   @0xca5d4 b 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex>
 *
 * ══ §411/561 Buffer_Network::~Buffer_Network()  0xcad14  size 48  12 条（0xcad14..0xcad44）
 * @func 0xcad14 0xcad44  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::~IBuffer() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcad14 ldr r3, [pc, #0x24]
 *   @0xcad18 push {r4, lr}
 *   @0xcad1c ldr r3, [pc, r3]
 *   @0xcad20 mov r4, r0
 *   @0xcad24 add r3, r3, #8
 *   @0xcad28 str r3, [r0]
 *   @0xcad2c bl 0xcb818 <_ZN7IBufferD2Ev>
 *   @0xcad30 mov r0, r4
 *   @0xcad34 bl 0x27d1d0 <_ZdlPv>
 *   @0xcad38 mov r0, r4
 *   @0xcad3c pop {r4, pc}
 *   @0xcad40 eorseq r2, r2, r12, ror #27
 *
 * ══ §412/561 YYSetString(RValue*, _RefThing<char const*>*)  0xdc34c  size 48  12 条（0xdc34c..0xdc37c）
 * @func 0xdc34c 0xdc37c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc34c push {r3, r4, r5, lr}
 *   @0xdc350 mov r5, r0
 *   @0xdc354 mov r3, #1
 *   @0xdc358 mov r0, #12
 *   @0xdc35c str r3, [r5, #0xc]
 *   @0xdc360 mov r4, r1
 *   @0xdc364 bl 0x27c524 <_Znwj>
 *   @0xdc368 mov r3, r0
 *   @0xdc36c ldm r4, {r0, r1, r2}
 *   @0xdc370 stm r3, {r0, r1, r2}
 *   @0xdc374 str r3, [r5]
 *   @0xdc378 pop {r3, r4, r5, pc}
 *
 * ══ §413/561 F_DsStackCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0xffdb4  size 48  12 条（0xffdb4..0xffde4）
 * @func 0xffdb4 0xffde4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_ds_stack_create()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffdb4 push {r4, lr}
 *   @0xffdb8 mov r3, #0
 *   @0xffdbc str r3, [r0, #0xc]
 *   @0xffdc0 mov r4, r0
 *   @0xffdc4 bl 0xffcc4 <_Z21YYGML_ds_stack_createv>
 *   @0xffdc8 vmov s15, r0
 *   @0xffdcc vcvt.f64.s32 d7, s15
 *   @0xffdd0 vmov r0, r1, d7
 *   @0xffdd4 vmov r2, s14
 *   @0xffdd8 mov r3, r1
 *   @0xffddc stm r4, {r2, r3}
 *   @0xffde0 pop {r4, pc}
 *
 * ══ §414/561 F_IsReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x10d9f8  size 48  12 条（0x10d9f8..0x10da28）
 * @func 0x10d9f8 0x10da28  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10d9f8 ldr r2, [sp]
 *   @0x10d9fc mov r3, #0
 *   @0x10da00 str r3, [r0, #0xc]
 *   @0x10da04 ldr r2, [r2, #0xc]
 *   @0x10da08 cmp r2, r3
 *   @0x10da0c moveq r3, r2
 *   @0x10da10 movne r2, r3
 *   @0x10da14 moveq r2, #0
 *   @0x10da18 str r3, [r0]
 *   @0x10da1c movteq r2, #0x3ff0
 *   @0x10da20 str r2, [r0, #0x4]
 *   @0x10da24 bx lr
 *
 * ══ §415/561 YYGML_random(double)  0x110e80  size 48  12 条（0x110e80..0x110eb0）
 * @func 0x110e80 0x110eb0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fYYRandom(double)
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110e80 push {r3, lr}
 *   @0x110e84 vpush {d8}
 *   @0x110e88 vmov d8, r0, r1
 *   @0x110e8c mov r0, #0
 *   @0x110e90 mov r1, #0
 *   @0x110e94 movt r1, #0x3ff0
 *   @0x110e98 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x110e9c vmov d7, r0, r1
 *   @0x110ea0 vmul.f64 d7, d7, d8
 *   @0x110ea4 vpop {d8}
 *   @0x110ea8 vmov r0, r1, d7
 *   @0x110eac pop {r3, pc}
 *
 * ══ §416/561 YYGML_irandom_range(int, int)  0x110f48  size 48  12 条（0x110f48..0x110f78）
 * @func 0x110f48 0x110f78  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: iScript_Random(long long)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110f48 cmp r0, r1
 *   @0x110f4c rsblt r1, r0, r1
 *   @0x110f50 push {r4, lr}
 *   @0x110f54 mov r4, r0
 *   @0x110f58 rsbge r0, r1, r4
 *   @0x110f5c addlt r0, r1, #1
 *   @0x110f60 addge r0, r0, #1
 *   @0x110f64 movge r4, r1
 *   @0x110f68 asr r1, r0, #31
 *   @0x110f6c bl 0x110d18 <_Z14iScript_Randomx>
 *   @0x110f70 add r0, r4, r0
 *   @0x110f74 pop {r4, pc}
 *
 * ══ §417/561 YYGML_irandom(int)  0x110f78  size 48  12 条（0x110f78..0x110fa8）
 * @func 0x110f78 0x110fa8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __fixdfdi / iScript_Random(long long)
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110f78 vmov.f64 d5, #1.000000e+00
 *   @0x110f7c cmp r0, #0
 *   @0x110f80 push {r3, lr}
 *   @0x110f84 vmov s9, r0
 *   @0x110f88 vmov.f64 d6, #-1.000000e+00
 *   @0x110f8c vcvt.f64.s32 d7, s9
 *   @0x110f90 vmovge.f64 d6, d5
 *   @0x110f94 vadd.f64 d5, d6, d7
 *   @0x110f98 vmov r0, r1, d5
 *   @0x110f9c bl 0x3194a0 <__fixdfdi>
 *   @0x110fa0 bl 0x110d18 <_Z14iScript_Randomx>
 *   @0x110fa4 pop {r3, pc}
 *
 * ══ §418/561 YYGML_degtorad(double)  0x111070  size 48  12 条（0x111070..0x1110a0）
 * @func 0x111070 0x1110a0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111070 vmov d5, r0, r1
 *   @0x111074 vldr d6, [pc, #20]
 *   @0x111078 vldr d7, [pc, #24]
 *   @0x11107c vmul.f64 d6, d5, d6
 *   @0x111080 vdiv.f64 d5, d6, d7
 *   @0x111084 vmov r0, r1, d5
 *   @0x111088 bx lr
 *   @0x11108c nop
 *   @0x111090 andvs r0, r0, r0
 *   @0x111094 strdmi r2, r3, [r9], -r11
 *   @0x111098 andeq r0, r0, r0
 *   @0x11109c rsbmi r8, r6, r0
 *
 * ══ §419/561 YYGML_StringByteAt(char const*, int)  0x1112fc  size 48  12 条（0x1112fc..0x11132c）
 * @func 0x1112fc 0x11132c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1112fc push {r3, r4, r5, lr}
 *   @0x111300 sub r5, r1, #1
 *   @0x111304 mov r4, r0
 *   @0x111308 bl 0xb6538 <strlen@plt>
 *   @0x11130c bic r1, r5, r5, asr #31
 *   @0x111310 cmp r0, r1
 *   @0x111314 suble r1, r0, #1
 *   @0x111318 ldrb r0, [r4, r1]
 *   @0x11131c vmov s15, r0
 *   @0x111320 vcvt.f64.u32 d7, s15
 *   @0x111324 vmov r0, r1, d7
 *   @0x111328 pop {r3, r4, r5, pc}
 *
 * ══ §420/561 F_DateGetTimezone(RValue&, CInstance*, CInstance*, int, RValue*)  0x114624  size 48  12 条（0x114624..0x114654）
 * @func 0x114624 0x114654  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2140
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114624 ldr r2, [pc, #0x24]
 *   @0x114628 mov r3, #0
 *   @0x11462c str r3, [r0, #0xc]
 *   @0x114630 add r2, pc, r2
 *   @0x114634 ldrb r2, [r2]
 *   @0x114638 cmp r2, r3
 *   @0x11463c moveq r3, #0
 *   @0x114640 movne r2, r3
 *   @0x114644 movteq r3, #0x3ff0
 *   @0x114648 stm r0, {r2, r3}
 *   @0x11464c bx lr
 *   @0x114650 eoreq sp, sp, r8, lsl #22
 *
 * ══ §421/561 F_EventUser(RValue&, CInstance*, CInstance*, int, RValue*)  0x11482c  size 48  12 条（0x11482c..0x11485c）
 * @func 0x11482c 0x11485c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11482c push {r4, r5, r6, lr}
 *   @0x114830 mov r4, r1
 *   @0x114834 ldr r0, [sp, #0x10]
 *   @0x114838 mov r1, #0
 *   @0x11483c mov r5, r2
 *   @0x114840 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x114844 mov r1, r5
 *   @0x114848 mov r2, #7
 *   @0x11484c add r3, r0, #10
 *   @0x114850 mov r0, r4
 *   @0x114854 pop {r4, r5, r6, lr}
 *   @0x114858 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *
 * ══ §422/561 F_TileCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b60  size 48  12 条（0x119b60..0x119b90）
 * @func 0x119b60 0x119b90  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0xc×1 / 0xb8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b60 ldr r3, [pc, #0x24]
 *   @0x119b64 mov r2, #0
 *   @0x119b68 str r2, [r0, #0xc]
 *   @0x119b6c ldr r3, [pc, r3]
 *   @0x119b70 ldr r3, [r3]
 *   @0x119b74 ldr r2, [r3, #0xb8]
 *   @0x119b78 vmov s15, r2
 *   @0x119b7c vcvt.f64.s32 d7, s15
 *   @0x119b80 vmov r2, r3, d7
 *   @0x119b84 stm r0, {r2, r3}
 *   @0x119b88 bx lr
 *   @0x119b8c .word 0x002d3dbc
 *
 * ══ §423/561 F_DisplayGetColordepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x119c24  size 48  12 条（0x119c24..0x119c54）
 * @func 0x119c24 0x119c54  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DisplayColorDepth()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119c24 push {r4, lr}
 *   @0x119c28 mov r3, #0
 *   @0x119c2c str r3, [r0, #0xc]
 *   @0x119c30 mov r4, r0
 *   @0x119c34 bl 0x17db54 <_Z17DisplayColorDepthv>
 *   @0x119c38 vmov s15, r0
 *   @0x119c3c vcvt.f64.s32 d7, s15
 *   @0x119c40 vmov r0, r1, d7
 *   @0x119c44 vmov r2, s14
 *   @0x119c48 mov r3, r1
 *   @0x119c4c stm r4, {r2, r3}
 *   @0x119c50 pop {r4, pc}
 *
 * ══ §424/561 F_DisplayGetFrequency(RValue&, CInstance*, CInstance*, int, RValue*)  0x119c54  size 48  12 条（0x119c54..0x119c84）
 * @func 0x119c54 0x119c84  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DisplayFrequency()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119c54 push {r4, lr}
 *   @0x119c58 mov r3, #0
 *   @0x119c5c str r3, [r0, #0xc]
 *   @0x119c60 mov r4, r0
 *   @0x119c64 bl 0x17db4c <_Z16DisplayFrequencyv>
 *   @0x119c68 vmov s15, r0
 *   @0x119c6c vcvt.f64.s32 d7, s15
 *   @0x119c70 vmov r0, r1, d7
 *   @0x119c74 vmov r2, s14
 *   @0x119c78 mov r3, r1
 *   @0x119c7c stm r4, {r2, r3}
 *   @0x119c80 pop {r4, pc}
 *
 * ══ §425/561 F_DisplayGetOrientation(RValue&, CInstance*, CInstance*, int, RValue*)  0x119c84  size 48  12 条（0x119c84..0x119cb4）
 * @func 0x119c84 0x119cb4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetOrientation
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119c84 push {r4, lr}
 *   @0x119c88 mov r3, #0
 *   @0x119c8c str r3, [r0, #0xc]
 *   @0x119c90 mov r4, r0
 *   @0x119c94 bl 0x15e288 <GetOrientation>
 *   @0x119c98 vmov s15, r0
 *   @0x119c9c vcvt.f64.s32 d7, s15
 *   @0x119ca0 vmov r0, r1, d7
 *   @0x119ca4 vmov r2, s14
 *   @0x119ca8 mov r3, r1
 *   @0x119cac stm r4, {r2, r3}
 *   @0x119cb0 pop {r4, pc}
 *
 * ══ §426/561 F_DisplayMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a1cc  size 48  12 条（0x11a1cc..0x11a1fc）
 * @func 0x11a1cc 0x11a1fc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DisplayGetMouseX()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a1cc push {r4, lr}
 *   @0x11a1d0 mov r3, #0
 *   @0x11a1d4 str r3, [r0, #0xc]
 *   @0x11a1d8 mov r4, r0
 *   @0x11a1dc bl 0x17dba4 <_Z16DisplayGetMouseXv>
 *   @0x11a1e0 vmov s15, r0
 *   @0x11a1e4 vcvt.f64.s32 d7, s15
 *   @0x11a1e8 vmov r0, r1, d7
 *   @0x11a1ec vmov r2, s14
 *   @0x11a1f0 mov r3, r1
 *   @0x11a1f4 stm r4, {r2, r3}
 *   @0x11a1f8 pop {r4, pc}
 *
 * ══ §427/561 F_DisplayMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a1fc  size 48  12 条（0x11a1fc..0x11a22c）
 * @func 0x11a1fc 0x11a22c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DisplayGetMouseY()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a1fc push {r4, lr}
 *   @0x11a200 mov r3, #0
 *   @0x11a204 str r3, [r0, #0xc]
 *   @0x11a208 mov r4, r0
 *   @0x11a20c bl 0x17dbac <_Z16DisplayGetMouseYv>
 *   @0x11a210 vmov s15, r0
 *   @0x11a214 vcvt.f64.s32 d7, s15
 *   @0x11a218 vmov r0, r1, d7
 *   @0x11a21c vmov r2, s14
 *   @0x11a220 mov r3, r1
 *   @0x11a224 stm r4, {r2, r3}
 *   @0x11a228 pop {r4, pc}
 *
 * ══ §428/561 F_WindowGetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a31c  size 48  12 条（0x11a31c..0x11a34c）
 * @func 0x11a31c 0x11a34c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_FullScreen()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a31c push {r3, r4, r5, lr}
 *   @0x11a320 mov r5, #0
 *   @0x11a324 str r5, [r0, #0xc]
 *   @0x11a328 mov r4, r0
 *   @0x11a32c bl 0x17af24 <_Z24GR_Window_Get_FullScreenv>
 *   @0x11a330 cmp r0, #0
 *   @0x11a334 movne r0, r5
 *   @0x11a338 moveq r3, r0
 *   @0x11a33c movne r3, r0
 *   @0x11a340 movtne r3, #0x3ff0
 *   @0x11a344 stm r4, {r0, r3}
 *   @0x11a348 pop {r3, r4, r5, pc}
 *
 * ══ §429/561 F_WindowGetCursor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a3fc  size 48  12 条（0x11a3fc..0x11a42c）
 * @func 0x11a3fc 0x11a42c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Cursor()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a3fc push {r4, lr}
 *   @0x11a400 mov r3, #0
 *   @0x11a404 str r3, [r0, #0xc]
 *   @0x11a408 mov r4, r0
 *   @0x11a40c bl 0x17af84 <_Z20GR_Window_Get_Cursorv>
 *   @0x11a410 vmov s15, r0
 *   @0x11a414 vcvt.f64.s32 d7, s15
 *   @0x11a418 vmov r0, r1, d7
 *   @0x11a41c vmov r2, s14
 *   @0x11a420 mov r3, r1
 *   @0x11a424 stm r4, {r2, r3}
 *   @0x11a428 pop {r4, pc}
 *
 * ══ §430/561 F_WindowGetColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a444  size 48  12 条（0x11a444..0x11a474）
 * @func 0x11a444 0x11a474  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Color()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a444 push {r4, lr}
 *   @0x11a448 mov r3, #0
 *   @0x11a44c str r3, [r0, #0xc]
 *   @0x11a450 mov r4, r0
 *   @0x11a454 bl 0x17ae20 <_Z19GR_Window_Get_Colorv>
 *   @0x11a458 vmov s15, r0
 *   @0x11a45c vcvt.f64.u32 d7, s15
 *   @0x11a460 vmov r0, r1, d7
 *   @0x11a464 vmov r2, s14
 *   @0x11a468 mov r3, r1
 *   @0x11a46c stm r4, {r2, r3}
 *   @0x11a470 pop {r4, pc}
 *
 * ══ §431/561 F_WindowGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a53c  size 48  12 条（0x11a53c..0x11a56c）
 * @func 0x11a53c 0x11a56c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_X()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a53c push {r4, lr}
 *   @0x11a540 mov r3, #0
 *   @0x11a544 str r3, [r0, #0xc]
 *   @0x11a548 mov r4, r0
 *   @0x11a54c bl 0x17af40 <_Z15GR_Window_Get_Xv>
 *   @0x11a550 vmov s15, r0
 *   @0x11a554 vcvt.f64.s32 d7, s15
 *   @0x11a558 vmov r0, r1, d7
 *   @0x11a55c vmov r2, s14
 *   @0x11a560 mov r3, r1
 *   @0x11a564 stm r4, {r2, r3}
 *   @0x11a568 pop {r4, pc}
 *
 * ══ §432/561 F_WindowGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a56c  size 48  12 条（0x11a56c..0x11a59c）
 * @func 0x11a56c 0x11a59c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Y()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a56c push {r4, lr}
 *   @0x11a570 mov r3, #0
 *   @0x11a574 str r3, [r0, #0xc]
 *   @0x11a578 mov r4, r0
 *   @0x11a57c bl 0x17af48 <_Z15GR_Window_Get_Yv>
 *   @0x11a580 vmov s15, r0
 *   @0x11a584 vcvt.f64.s32 d7, s15
 *   @0x11a588 vmov r0, r1, d7
 *   @0x11a58c vmov r2, s14
 *   @0x11a590 mov r3, r1
 *   @0x11a594 stm r4, {r2, r3}
 *   @0x11a598 pop {r4, pc}
 *
 * ══ §433/561 F_WindowMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a778  size 48  12 条（0x11a778..0x11a7a8）
 * @func 0x11a778 0x11a7a8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Mouse_Get_X()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a778 push {r4, lr}
 *   @0x11a77c mov r3, #0
 *   @0x11a780 str r3, [r0, #0xc]
 *   @0x11a784 mov r4, r0
 *   @0x11a788 bl 0x17aab4 <_Z21GR_Window_Mouse_Get_Xv>
 *   @0x11a78c vmov s15, r0
 *   @0x11a790 vcvt.f64.s32 d7, s15
 *   @0x11a794 vmov r0, r1, d7
 *   @0x11a798 vmov r2, s14
 *   @0x11a79c mov r3, r1
 *   @0x11a7a0 stm r4, {r2, r3}
 *   @0x11a7a4 pop {r4, pc}
 *
 * ══ §434/561 F_WindowMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a7a8  size 48  12 条（0x11a7a8..0x11a7d8）
 * @func 0x11a7a8 0x11a7d8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Mouse_Get_Y()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a7a8 push {r4, lr}
 *   @0x11a7ac mov r3, #0
 *   @0x11a7b0 str r3, [r0, #0xc]
 *   @0x11a7b4 mov r4, r0
 *   @0x11a7b8 bl 0x17aac8 <_Z21GR_Window_Mouse_Get_Yv>
 *   @0x11a7bc vmov s15, r0
 *   @0x11a7c0 vcvt.f64.s32 d7, s15
 *   @0x11a7c4 vmov r0, r1, d7
 *   @0x11a7c8 vmov r2, s14
 *   @0x11a7cc mov r3, r1
 *   @0x11a7d0 stm r4, {r2, r3}
 *   @0x11a7d4 pop {r4, pc}
 *
 * ══ §435/561 F_DrawGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x11aa20  size 48  12 条（0x11aa20..0x11aa50）
 * @func 0x11aa20 0x11aa50  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Get_Alpha()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11aa20 push {r4, lr}
 *   @0x11aa24 mov r3, #0
 *   @0x11aa28 str r3, [r0, #0xc]
 *   @0x11aa2c mov r4, r0
 *   @0x11aa30 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11aa34 vmov s15, r0
 *   @0x11aa38 vcvt.f64.f32 d7, s15
 *   @0x11aa3c vmov r0, r1, d7
 *   @0x11aa40 vmov r2, s14
 *   @0x11aa44 mov r3, r1
 *   @0x11aa48 stm r4, {r2, r3}
 *   @0x11aa4c pop {r4, pc}
 *
 * ══ §436/561 F_DrawGetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*)  0x11acc8  size 48  12 条（0x11acc8..0x11acf8）
 * @func 0x11acc8 0x11acf8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_D3D_Get_Alpha_Test_Enable()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11acc8 push {r4, lr}
 *   @0x11accc mov r3, #0
 *   @0x11acd0 str r3, [r0, #0xc]
 *   @0x11acd4 mov r4, r0
 *   @0x11acd8 bl 0x168694 <_Z28GR_D3D_Get_Alpha_Test_Enablev>
 *   @0x11acdc vmov s15, r0
 *   @0x11ace0 vcvt.f64.u32 d7, s15
 *   @0x11ace4 vmov r0, r1, d7
 *   @0x11ace8 vmov r2, s14
 *   @0x11acec mov r3, r1
 *   @0x11acf0 stm r4, {r2, r3}
 *   @0x11acf4 pop {r4, pc}
 *
 * ══ §437/561 F_DrawGetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ad10  size 48  12 条（0x11ad10..0x11ad40）
 * @func 0x11ad10 0x11ad40  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_D3D_Get_Alpha_Test_Ref()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ad10 push {r4, lr}
 *   @0x11ad14 mov r3, #0
 *   @0x11ad18 str r3, [r0, #0xc]
 *   @0x11ad1c mov r4, r0
 *   @0x11ad20 bl 0x1686d0 <_Z25GR_D3D_Get_Alpha_Test_Refv>
 *   @0x11ad24 vmov s15, r0
 *   @0x11ad28 vcvt.f64.u32 d7, s15
 *   @0x11ad2c vmov r0, r1, d7
 *   @0x11ad30 vmov r2, s14
 *   @0x11ad34 mov r3, r1
 *   @0x11ad38 stm r4, {r2, r3}
 *   @0x11ad3c pop {r4, pc}
 *
 * ══ §438/561 F_TileLayerHide(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c440  size 48  12 条（0x11c440..0x11c470）
 * @func 0x11c440 0x11c470  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c440 ldr r3, [pc, #0x24]
 *   @0x11c444 mov r1, #0
 *   @0x11c448 push {r4, lr}
 *   @0x11c44c ldr r3, [pc, r3]
 *   @0x11c450 ldr r0, [sp, #0x8]
 *   @0x11c454 ldr r4, [r3]
 *   @0x11c458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c45c mov r1, r0
 *   @0x11c460 mov r0, r4
 *   @0x11c464 pop {r4, lr}
 *   @0x11c468 b 0x1af584 <_ZN5CRoom14HideTilesDepthEf>
 *   @0x11c46c .word 0x002d14dc
 *
 * ══ §439/561 F_TileLayerShow(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c470  size 48  12 条（0x11c470..0x11c4a0）
 * @func 0x11c470 0x11c4a0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c470 ldr r3, [pc, #0x24]
 *   @0x11c474 mov r1, #0
 *   @0x11c478 push {r4, lr}
 *   @0x11c47c ldr r3, [pc, r3]
 *   @0x11c480 ldr r0, [sp, #0x8]
 *   @0x11c484 ldr r4, [r3]
 *   @0x11c488 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c48c mov r1, r0
 *   @0x11c490 mov r0, r4
 *   @0x11c494 pop {r4, lr}
 *   @0x11c498 b 0x1af5c4 <_ZN5CRoom14ShowTilesDepthEf>
 *   @0x11c49c eoreq r1, sp, r12, lsr #9
 *
 * ══ §440/561 F_TileLayerDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c4a0  size 48  12 条（0x11c4a0..0x11c4d0）
 * @func 0x11c4a0 0x11c4d0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x24×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c4a0 ldr r3, [pc, #0x24]
 *   @0x11c4a4 mov r1, #0
 *   @0x11c4a8 push {r4, lr}
 *   @0x11c4ac ldr r3, [pc, r3]
 *   @0x11c4b0 ldr r0, [sp, #0x8]
 *   @0x11c4b4 ldr r4, [r3]
 *   @0x11c4b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c4bc mov r1, r0
 *   @0x11c4c0 mov r0, r4
 *   @0x11c4c4 pop {r4, lr}
 *   @0x11c4c8 b 0x1af604 <_ZN5CRoom16DeleteTilesDepthEf>
 *   @0x11c4cc eoreq r1, sp, r12, ror r4
 *
 * ══ §441/561 F_SurfaceResetTarget(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ca78  size 48  12 条（0x11ca78..0x11caa8）
 * @func 0x11ca78 0x11caa8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_surface_reset_target()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ca78 push {r3, r4, r5, lr}
 *   @0x11ca7c mov r5, #0
 *   @0x11ca80 str r5, [r0, #0xc]
 *   @0x11ca84 mov r4, r0
 *   @0x11ca88 bl 0x171808 <_Z26YYGML_surface_reset_targetv>
 *   @0x11ca8c cmp r0, #0
 *   @0x11ca90 movne r0, r5
 *   @0x11ca94 moveq r3, r0
 *   @0x11ca98 movne r3, r0
 *   @0x11ca9c movtne r3, #0x3ff0
 *   @0x11caa0 stm r4, {r0, r3}
 *   @0x11caa4 pop {r3, r4, r5, pc}
 *
 * ══ §442/561 F_MessageBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x125d48  size 48  12 条（0x125d48..0x125d78）
 * @func 0x125d48 0x125d78  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125d48 push {r3, lr}
 *   @0x125d4c ldr r3, [pc, #0x1c]
 *   @0x125d50 ldr r1, [pc, #0x1c]
 *   @0x125d54 ldr r3, [pc, r3]
 *   @0x125d58 add r1, pc, r1
 *   @0x125d5c ldr r0, [r3]
 *   @0x125d60 ldr r3, [r0]
 *   @0x125d64 ldr r3, [r3, #0xc]
 *   @0x125d68 blx r3
 *   @0x125d6c pop {r3, pc}
 *   @0x125d70 eoreq r7, r12, r0, asr #19
 *   @0x125d74 eoreq r6, r1, r8, lsr #3
 *
 * ══ §443/561 F_MessageButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x125d78  size 48  12 条（0x125d78..0x125da8）
 * @func 0x125d78 0x125da8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125d78 push {r3, lr}
 *   @0x125d7c ldr r3, [pc, #0x1c]
 *   @0x125d80 ldr r1, [pc, #0x1c]
 *   @0x125d84 ldr r3, [pc, r3]
 *   @0x125d88 add r1, pc, r1
 *   @0x125d8c ldr r0, [r3]
 *   @0x125d90 ldr r3, [r0]
 *   @0x125d94 ldr r3, [r3, #0xc]
 *   @0x125d98 blx r3
 *   @0x125d9c pop {r3, pc}
 *   @0x125da0 mlaeq r12, r0, r9, r7
 *   @0x125da4 eoreq r6, r1, r4, lsr #3
 *
 * ══ §444/561 F_MessageTextFont(RValue&, CInstance*, CInstance*, int, RValue*)  0x125da8  size 48  12 条（0x125da8..0x125dd8）
 * @func 0x125da8 0x125dd8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125da8 push {r3, lr}
 *   @0x125dac ldr r3, [pc, #0x1c]
 *   @0x125db0 ldr r1, [pc, #0x1c]
 *   @0x125db4 ldr r3, [pc, r3]
 *   @0x125db8 add r1, pc, r1
 *   @0x125dbc ldr r0, [r3]
 *   @0x125dc0 ldr r3, [r0]
 *   @0x125dc4 ldr r3, [r3, #0xc]
 *   @0x125dc8 blx r3
 *   @0x125dcc pop {r3, pc}
 *   @0x125dd0 eoreq r7, r12, r0, ror #18
 *   @0x125dd4 mlaeq r1, r8, r1, r6
 *
 * ══ §445/561 F_MessageButtonFont(RValue&, CInstance*, CInstance*, int, RValue*)  0x125dd8  size 48  12 条（0x125dd8..0x125e08）
 * @func 0x125dd8 0x125e08  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125dd8 push {r3, lr}
 *   @0x125ddc ldr r3, [pc, #0x1c]
 *   @0x125de0 ldr r1, [pc, #0x1c]
 *   @0x125de4 ldr r3, [pc, r3]
 *   @0x125de8 add r1, pc, r1
 *   @0x125dec ldr r0, [r3]
 *   @0x125df0 ldr r3, [r0]
 *   @0x125df4 ldr r3, [r3, #0xc]
 *   @0x125df8 blx r3
 *   @0x125dfc pop {r3, pc}
 *   @0x125e00 eoreq r7, r12, r0, lsr r9
 *   @0x125e04 eoreq r6, r1, r4, lsr #3
 *
 * ══ §446/561 F_MessageInputFont(RValue&, CInstance*, CInstance*, int, RValue*)  0x125e08  size 48  12 条（0x125e08..0x125e38）
 * @func 0x125e08 0x125e38  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125e08 push {r3, lr}
 *   @0x125e0c ldr r3, [pc, #0x1c]
 *   @0x125e10 ldr r1, [pc, #0x1c]
 *   @0x125e14 ldr r3, [pc, r3]
 *   @0x125e18 add r1, pc, r1
 *   @0x125e1c ldr r0, [r3]
 *   @0x125e20 ldr r3, [r0]
 *   @0x125e24 ldr r3, [r3, #0xc]
 *   @0x125e28 blx r3
 *   @0x125e2c pop {r3, pc}
 *   @0x125e30 eoreq r7, r12, r0, lsl #18
 *   @0x125e34 .word 0x002161b0
 *
 * ══ §447/561 F_MessageAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x125e38  size 48  12 条（0x125e38..0x125e68）
 * @func 0x125e38 0x125e68  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125e38 push {r3, lr}
 *   @0x125e3c ldr r3, [pc, #0x1c]
 *   @0x125e40 ldr r1, [pc, #0x1c]
 *   @0x125e44 ldr r3, [pc, r3]
 *   @0x125e48 add r1, pc, r1
 *   @0x125e4c ldr r0, [r3]
 *   @0x125e50 ldr r3, [r0]
 *   @0x125e54 ldr r3, [r3, #0xc]
 *   @0x125e58 blx r3
 *   @0x125e5c pop {r3, pc}
 *   @0x125e60 .word 0x002c78d0
 *   @0x125e64 .word 0x002161bc
 *
 * ══ §448/561 F_MessageMouseColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x125e68  size 48  12 条（0x125e68..0x125e98）
 * @func 0x125e68 0x125e98  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125e68 push {r3, lr}
 *   @0x125e6c ldr r3, [pc, #0x1c]
 *   @0x125e70 ldr r1, [pc, #0x1c]
 *   @0x125e74 ldr r3, [pc, r3]
 *   @0x125e78 add r1, pc, r1
 *   @0x125e7c ldr r0, [r3]
 *   @0x125e80 ldr r3, [r0]
 *   @0x125e84 ldr r3, [r3, #0xc]
 *   @0x125e88 blx r3
 *   @0x125e8c pop {r3, pc}
 *   @0x125e90 eoreq r7, r12, r0, lsr #17
 *   @0x125e94 .word 0x002161b4
 *
 * ══ §449/561 F_MessageInputColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x125e98  size 48  12 条（0x125e98..0x125ec8）
 * @func 0x125e98 0x125ec8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125e98 push {r3, lr}
 *   @0x125e9c ldr r3, [pc, #0x1c]
 *   @0x125ea0 ldr r1, [pc, #0x1c]
 *   @0x125ea4 ldr r3, [pc, r3]
 *   @0x125ea8 add r1, pc, r1
 *   @0x125eac ldr r0, [r3]
 *   @0x125eb0 ldr r3, [r0]
 *   @0x125eb4 ldr r3, [r3, #0xc]
 *   @0x125eb8 blx r3
 *   @0x125ebc pop {r3, pc}
 *   @0x125ec0 eoreq r7, r12, r0, ror r8
 *   @0x125ec4 .word 0x002161b0
 *
 * ══ §450/561 F_MessagePosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x125ec8  size 48  12 条（0x125ec8..0x125ef8）
 * @func 0x125ec8 0x125ef8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125ec8 push {r3, lr}
 *   @0x125ecc ldr r3, [pc, #0x1c]
 *   @0x125ed0 ldr r1, [pc, #0x1c]
 *   @0x125ed4 ldr r3, [pc, r3]
 *   @0x125ed8 add r1, pc, r1
 *   @0x125edc ldr r0, [r3]
 *   @0x125ee0 ldr r3, [r0]
 *   @0x125ee4 ldr r3, [r3, #0xc]
 *   @0x125ee8 blx r3
 *   @0x125eec pop {r3, pc}
 *   @0x125ef0 eoreq r7, r12, r0, asr #16
 *   @0x125ef4 eoreq r6, r1, r12, lsr #3
 *
 * ══ §451/561 F_MessageSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x125ef8  size 48  12 条（0x125ef8..0x125f28）
 * @func 0x125ef8 0x125f28  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125ef8 push {r3, lr}
 *   @0x125efc ldr r3, [pc, #0x1c]
 *   @0x125f00 ldr r1, [pc, #0x1c]
 *   @0x125f04 ldr r3, [pc, r3]
 *   @0x125f08 add r1, pc, r1
 *   @0x125f0c ldr r0, [r3]
 *   @0x125f10 ldr r3, [r0]
 *   @0x125f14 ldr r3, [r3, #0xc]
 *   @0x125f18 blx r3
 *   @0x125f1c pop {r3, pc}
 *   @0x125f20 eoreq r7, r12, r0, lsl r8
 *   @0x125f24 eoreq r6, r1, r4, lsr #3
 *
 * ══ §452/561 F_MessageCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f28  size 48  12 条（0x125f28..0x125f58）
 * @func 0x125f28 0x125f58  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f28 push {r3, lr}
 *   @0x125f2c ldr r3, [pc, #0x1c]
 *   @0x125f30 ldr r1, [pc, #0x1c]
 *   @0x125f34 ldr r3, [pc, r3]
 *   @0x125f38 add r1, pc, r1
 *   @0x125f3c ldr r0, [r3]
 *   @0x125f40 ldr r3, [r0]
 *   @0x125f44 ldr r3, [r3, #0xc]
 *   @0x125f48 blx r3
 *   @0x125f4c pop {r3, pc}
 *   @0x125f50 eoreq r7, r12, r0, ror #15
 *   @0x125f54 mlaeq r1, r8, r1, r6
 *
 * ══ §453/561 F_TimeLineMomentAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa00  size 48  12 条（0x12aa00..0x12aa30）
 * @func 0x12aa00 0x12aa30  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa00 push {r3, lr}
 *   @0x12aa04 ldr r3, [pc, #0x1c]
 *   @0x12aa08 ldr r1, [pc, #0x1c]
 *   @0x12aa0c ldr r3, [pc, r3]
 *   @0x12aa10 add r1, pc, r1
 *   @0x12aa14 ldr r0, [r3]
 *   @0x12aa18 ldr r3, [r0]
 *   @0x12aa1c ldr r3, [r3, #0xc]
 *   @0x12aa20 blx r3
 *   @0x12aa24 pop {r3, pc}
 *   @0x12aa28 eoreq r2, r12, r8, lsl #26
 *   @0x12aa2c eoreq r2, r1, r8, lsr r10
 *
 * ══ §454/561 F_ObjectEventAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa30  size 48  12 条（0x12aa30..0x12aa60）
 * @func 0x12aa30 0x12aa60  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa30 push {r3, lr}
 *   @0x12aa34 ldr r3, [pc, #0x1c]
 *   @0x12aa38 ldr r1, [pc, #0x1c]
 *   @0x12aa3c ldr r3, [pc, r3]
 *   @0x12aa40 add r1, pc, r1
 *   @0x12aa44 ldr r0, [r3]
 *   @0x12aa48 ldr r3, [r0]
 *   @0x12aa4c ldr r3, [r3, #0xc]
 *   @0x12aa50 blx r3
 *   @0x12aa54 pop {r3, pc}
 *   @0x12aa58 .word 0x002c2cd8
 *   @0x12aa5c eoreq r2, r1, r4, lsr r10
 *
 * ══ §455/561 F_PathAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d9a8  size 48  12 条（0x12d9a8..0x12d9d8）
 * @func 0x12d9a8 0x12d9d8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Add()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d9a8 push {r4, lr}
 *   @0x12d9ac mov r3, #0
 *   @0x12d9b0 str r3, [r0, #0xc]
 *   @0x12d9b4 mov r4, r0
 *   @0x12d9b8 bl 0x1a819c <_Z8Path_Addv>
 *   @0x12d9bc vmov s15, r0
 *   @0x12d9c0 vcvt.f64.s32 d7, s15
 *   @0x12d9c4 vmov r0, r1, d7
 *   @0x12d9c8 vmov r2, s14
 *   @0x12d9cc mov r3, r1
 *   @0x12d9d0 stm r4, {r2, r3}
 *   @0x12d9d4 pop {r4, pc}
 *
 * ══ §456/561 F_TimeLineAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12deac  size 48  12 条（0x12deac..0x12dedc）
 * @func 0x12deac 0x12dedc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Add()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12deac push {r4, lr}
 *   @0x12deb0 mov r3, #0
 *   @0x12deb4 str r3, [r0, #0xc]
 *   @0x12deb8 mov r4, r0
 *   @0x12debc bl 0x1f2cfc <_Z12TimeLine_Addv>
 *   @0x12dec0 vmov s15, r0
 *   @0x12dec4 vcvt.f64.s32 d7, s15
 *   @0x12dec8 vmov r0, r1, d7
 *   @0x12decc vmov r2, s14
 *   @0x12ded0 mov r3, r1
 *   @0x12ded4 stm r4, {r2, r3}
 *   @0x12ded8 pop {r4, pc}
 *
 * ══ §457/561 F_ObjectAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e134  size 48  12 条（0x12e134..0x12e164）
 * @func 0x12e134 0x12e164  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Object_Add()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e134 push {r4, lr}
 *   @0x12e138 mov r3, #0
 *   @0x12e13c str r3, [r0, #0xc]
 *   @0x12e140 mov r4, r0
 *   @0x12e144 bl 0x19eebc <_Z10Object_Addv>
 *   @0x12e148 vmov s15, r0
 *   @0x12e14c vcvt.f64.s32 d7, s15
 *   @0x12e150 vmov r0, r1, d7
 *   @0x12e154 vmov r2, s14
 *   @0x12e158 mov r3, r1
 *   @0x12e15c stm r4, {r2, r3}
 *   @0x12e160 pop {r4, pc}
 *
 * ══ §458/561 F_RoomAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e7bc  size 48  12 条（0x12e7bc..0x12e7ec）
 * @func 0x12e7bc 0x12e7ec  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Add()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e7bc push {r4, lr}
 *   @0x12e7c0 mov r3, #0
 *   @0x12e7c4 str r3, [r0, #0xc]
 *   @0x12e7c8 mov r4, r0
 *   @0x12e7cc bl 0x1b5348 <_Z8Room_Addv>
 *   @0x12e7d0 vmov s15, r0
 *   @0x12e7d4 vcvt.f64.s32 d7, s15
 *   @0x12e7d8 vmov r0, r1, d7
 *   @0x12e7dc vmov r2, s14
 *   @0x12e7e0 mov r3, r1
 *   @0x12e7e4 stm r4, {r2, r3}
 *   @0x12e7e8 pop {r4, pc}
 *
 * ══ §459/561 F_CDPresent(RValue&, CInstance*, CInstance*, int, RValue*)  0x1336bc  size 48  12 条（0x1336bc..0x1336ec）
 * @func 0x1336bc 0x1336ec  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Present()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1336bc push {r4, lr}
 *   @0x1336c0 mov r3, #0
 *   @0x1336c4 str r3, [r0, #0xc]
 *   @0x1336c8 mov r4, r0
 *   @0x1336cc bl 0x21485c <_Z10CD_Presentv>
 *   @0x1336d0 vmov s15, r0
 *   @0x1336d4 vcvt.f64.u32 d7, s15
 *   @0x1336d8 vmov r0, r1, d7
 *   @0x1336dc vmov r2, s14
 *   @0x1336e0 mov r3, r1
 *   @0x1336e4 stm r4, {r2, r3}
 *   @0x1336e8 pop {r4, pc}
 *
 * ══ §460/561 F_CDNumber(RValue&, CInstance*, CInstance*, int, RValue*)  0x1336ec  size 48  12 条（0x1336ec..0x13371c）
 * @func 0x1336ec 0x13371c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_NumberOfTracks()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1336ec push {r4, lr}
 *   @0x1336f0 mov r3, #0
 *   @0x1336f4 str r3, [r0, #0xc]
 *   @0x1336f8 mov r4, r0
 *   @0x1336fc bl 0x214864 <_Z17CD_NumberOfTracksv>
 *   @0x133700 vmov s15, r0
 *   @0x133704 vcvt.f64.s32 d7, s15
 *   @0x133708 vmov r0, r1, d7
 *   @0x13370c vmov r2, s14
 *   @0x133710 mov r3, r1
 *   @0x133714 stm r4, {r2, r3}
 *   @0x133718 pop {r4, pc}
 *
 * ══ §461/561 F_CDPlaying(RValue&, CInstance*, CInstance*, int, RValue*)  0x13371c  size 48  12 条（0x13371c..0x13374c）
 * @func 0x13371c 0x13374c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Playing()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13371c push {r4, lr}
 *   @0x133720 mov r3, #0
 *   @0x133724 str r3, [r0, #0xc]
 *   @0x133728 mov r4, r0
 *   @0x13372c bl 0x21486c <_Z10CD_Playingv>
 *   @0x133730 vmov s15, r0
 *   @0x133734 vcvt.f64.u32 d7, s15
 *   @0x133738 vmov r0, r1, d7
 *   @0x13373c vmov r2, s14
 *   @0x133740 mov r3, r1
 *   @0x133744 stm r4, {r2, r3}
 *   @0x133748 pop {r4, pc}
 *
 * ══ §462/561 F_CDPaused(RValue&, CInstance*, CInstance*, int, RValue*)  0x13374c  size 48  12 条（0x13374c..0x13377c）
 * @func 0x13374c 0x13377c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Paused()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13374c push {r4, lr}
 *   @0x133750 mov r3, #0
 *   @0x133754 str r3, [r0, #0xc]
 *   @0x133758 mov r4, r0
 *   @0x13375c bl 0x214874 <_Z9CD_Pausedv>
 *   @0x133760 vmov s15, r0
 *   @0x133764 vcvt.f64.u32 d7, s15
 *   @0x133768 vmov r0, r1, d7
 *   @0x13376c vmov r2, s14
 *   @0x133770 mov r3, r1
 *   @0x133774 stm r4, {r2, r3}
 *   @0x133778 pop {r4, pc}
 *
 * ══ §463/561 F_CDTrack(RValue&, CInstance*, CInstance*, int, RValue*)  0x13377c  size 48  12 条（0x13377c..0x1337ac）
 * @func 0x13377c 0x1337ac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Track()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13377c push {r4, lr}
 *   @0x133780 mov r3, #0
 *   @0x133784 str r3, [r0, #0xc]
 *   @0x133788 mov r4, r0
 *   @0x13378c bl 0x21487c <_Z8CD_Trackv>
 *   @0x133790 vmov s15, r0
 *   @0x133794 vcvt.f64.s32 d7, s15
 *   @0x133798 vmov r0, r1, d7
 *   @0x13379c vmov r2, s14
 *   @0x1337a0 mov r3, r1
 *   @0x1337a4 stm r4, {r2, r3}
 *   @0x1337a8 pop {r4, pc}
 *
 * ══ §464/561 F_CDLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x1337ac  size 48  12 条（0x1337ac..0x1337dc）
 * @func 0x1337ac 0x1337dc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Length()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1337ac push {r4, lr}
 *   @0x1337b0 mov r3, #0
 *   @0x1337b4 str r3, [r0, #0xc]
 *   @0x1337b8 mov r4, r0
 *   @0x1337bc bl 0x214884 <_Z9CD_Lengthv>
 *   @0x1337c0 vmov s15, r0
 *   @0x1337c4 vcvt.f64.s32 d7, s15
 *   @0x1337c8 vmov r0, r1, d7
 *   @0x1337cc vmov r2, s14
 *   @0x1337d0 mov r3, r1
 *   @0x1337d4 stm r4, {r2, r3}
 *   @0x1337d8 pop {r4, pc}
 *
 * ══ §465/561 F_CDPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x133818  size 48  12 条（0x133818..0x133848）
 * @func 0x133818 0x133848  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Position()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133818 push {r4, lr}
 *   @0x13381c mov r3, #0
 *   @0x133820 str r3, [r0, #0xc]
 *   @0x133824 mov r4, r0
 *   @0x133828 bl 0x214894 <_Z11CD_Positionv>
 *   @0x13382c vmov s15, r0
 *   @0x133830 vcvt.f64.s32 d7, s15
 *   @0x133834 vmov r0, r1, d7
 *   @0x133838 vmov r2, s14
 *   @0x13383c mov r3, r1
 *   @0x133840 stm r4, {r2, r3}
 *   @0x133844 pop {r4, pc}
 *
 * ══ §466/561 F_CDTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x133848  size 48  12 条（0x133848..0x133878）
 * @func 0x133848 0x133878  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_TrackPosition()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133848 push {r4, lr}
 *   @0x13384c mov r3, #0
 *   @0x133850 str r3, [r0, #0xc]
 *   @0x133854 mov r4, r0
 *   @0x133858 bl 0x21489c <_Z16CD_TrackPositionv>
 *   @0x13385c vmov s15, r0
 *   @0x133860 vcvt.f64.s32 d7, s15
 *   @0x133864 vmov r0, r1, d7
 *   @0x133868 vmov r2, s14
 *   @0x13386c mov r3, r1
 *   @0x133870 stm r4, {r2, r3}
 *   @0x133874 pop {r4, pc}
 *
 * ══ §467/561 F_FileReadString(RValue&, CInstance*, CInstance*, int, RValue*)  0x139b58  size 48  12 条（0x139b58..0x139b88）
 * @func 0x139b58 0x139b88  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139b58 ldr r3, [pc, #0x20]
 *   @0x139b5c ldr r3, [pc, r3]
 *   @0x139b60 ldr r3, [r3]
 *   @0x139b64 cmp r3, #1
 *   @0x139b68 beq 0x139b7c <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x139b6c ldr r0, [pc, #0x10]
 *   @0x139b70 mov r1, #0
 *   @0x139b74 add r0, pc, r0
 *   @0x139b78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139b7c b 0x139aa0 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x139b80 eoreq r5, r11, r4, lsl r7
 *   @0x139b84 eoreq r6, r0, r0, lsl #13
 *
 * ══ §468/561 F_FileReadLn(RValue&, CInstance*, CInstance*, int, RValue*)  0x139c40  size 48  12 条（0x139c40..0x139c70）
 * @func 0x139c40 0x139c70  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139c40 ldr r3, [pc, #0x20]
 *   @0x139c44 ldr r3, [pc, r3]
 *   @0x139c48 ldr r3, [r3]
 *   @0x139c4c cmp r3, #1
 *   @0x139c50 beq 0x139c64 <_Z12F_FileReadLnR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x139c54 ldr r0, [pc, #0x10]
 *   @0x139c58 mov r1, #0
 *   @0x139c5c add r0, pc, r0
 *   @0x139c60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139c64 b 0x139b88 <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x139c68 eoreq r5, r11, r12, lsr #12
 *   @0x139c6c mlaeq r0, r8, r5, r6
 *
 * ══ §469/561 F_ParameterCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x13c3c0  size 48  12 条（0x13c3c0..0x13c3f0）
 * @func 0x13c3c0 0x13c3f0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParamCount()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c3c0 push {r4, lr}
 *   @0x13c3c4 mov r3, #0
 *   @0x13c3c8 str r3, [r0, #0xc]
 *   @0x13c3cc mov r4, r0
 *   @0x13c3d0 bl 0x13c3ac <_Z10ParamCountv>
 *   @0x13c3d4 vmov s15, r0
 *   @0x13c3d8 vcvt.f64.s32 d7, s15
 *   @0x13c3dc vmov r0, r1, d7
 *   @0x13c3e0 vmov r2, s14
 *   @0x13c3e4 mov r3, r1
 *   @0x13c3e8 stm r4, {r2, r3}
 *   @0x13c3ec pop {r4, pc}
 *
 * ══ §470/561 F_ActionSpriteColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d8b0  size 48  12 条（0x13d8b0..0x13d8e0）
 * @func 0x13d8b0 0x13d8e0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xa8×1 / 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d8b0 push {r3, r4, r5, lr}
 *   @0x13d8b4 mov r4, r1
 *   @0x13d8b8 ldr r5, [sp, #0x10]
 *   @0x13d8bc mov r1, #0
 *   @0x13d8c0 mov r0, r5
 *   @0x13d8c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d8c8 mov r1, #1
 *   @0x13d8cc str r0, [r4, #0xa8]
 *   @0x13d8d0 mov r0, r5
 *   @0x13d8d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d8d8 str r0, [r4, #0xa4]
 *   @0x13d8dc pop {r3, r4, r5, pc}
 *
 * ══ §471/561 F_ActionCDPresent(RValue&, CInstance*, CInstance*, int, RValue*)  0x140144  size 48  12 条（0x140144..0x140174）
 * @func 0x140144 0x140174  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Present()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140144 push {r3, r4, r5, lr}
 *   @0x140148 mov r5, #0
 *   @0x14014c str r5, [r0, #0xc]
 *   @0x140150 mov r4, r0
 *   @0x140154 bl 0x21485c <_Z10CD_Presentv>
 *   @0x140158 cmp r0, #0
 *   @0x14015c movne r0, r5
 *   @0x140160 moveq r3, r0
 *   @0x140164 movne r3, r0
 *   @0x140168 movtne r3, #0x3ff0
 *   @0x14016c stm r4, {r0, r3}
 *   @0x140170 pop {r3, r4, r5, pc}
 *
 * ══ §472/561 F_ActionCDPlaying(RValue&, CInstance*, CInstance*, int, RValue*)  0x140174  size 48  12 条（0x140174..0x1401a4）
 * @func 0x140174 0x1401a4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CD_Playing()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140174 push {r3, r4, r5, lr}
 *   @0x140178 mov r5, #0
 *   @0x14017c str r5, [r0, #0xc]
 *   @0x140180 mov r4, r0
 *   @0x140184 bl 0x21486c <_Z10CD_Playingv>
 *   @0x140188 cmp r0, #0
 *   @0x14018c movne r0, r5
 *   @0x140190 moveq r3, r0
 *   @0x140194 movne r3, r0
 *   @0x140198 movtne r3, #0x3ff0
 *   @0x14019c stm r4, {r0, r3}
 *   @0x1401a0 pop {r3, r4, r5, pc}
 *
 * ══ §473/561 YYGML_action_path(CInstance*, int, float, int, bool)  0x14169c  size 48  12 条（0x14169c..0x1416cc）
 * @func 0x14169c 0x1416cc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Assign_Path(int, float, float, float, bool, int)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14169c str lr, [sp, #-0x4]!
 *   @0x1416a0 sub sp, sp, #20
 *   @0x1416a4 mov lr, #0
 *   @0x1416a8 ldrb r12, [sp, #0x18]
 *   @0x1416ac str r3, [sp, #0x8]
 *   @0x1416b0 mov r3, #1065353216
 *   @0x1416b4 eor r12, r12, #1
 *   @0x1416b8 str lr, [sp]
 *   @0x1416bc str r12, [sp, #0x4]
 *   @0x1416c0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi>
 *   @0x1416c4 add sp, sp, #20
 *   @0x1416c8 ldr pc, [sp], #4
 *
 * ══ §474/561 F_D3DMatrixStackIsEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x1439e8  size 48  12 条（0x1439e8..0x143a18）
 * @func 0x1439e8 0x143a18  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1439e8 ldr r3, [pc, #0x24]
 *   @0x1439ec mov r2, #0
 *   @0x1439f0 str r2, [r0, #0xc]
 *   @0x1439f4 ldr r3, [pc, r3]
 *   @0x1439f8 ldr r3, [r3]
 *   @0x1439fc cmp r3, r2
 *   @0x143a00 streq r3, [r0]
 *   @0x143a04 moveq r3, r2
 *   @0x143a08 movteq r3, #0x3ff0
 *   @0x143a0c streq r3, [r0, #0x4]
 *   @0x143a10 bx lr
 *   @0x143a14 eoreq r11, r10, r0, lsl r12
 *
 * ══ §475/561 F_D3DTransformStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x1450c0  size 48  12 条（0x1450c0..0x1450f0）
 * @func 0x1450c0 0x1450f0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Empty()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1450c0 push {r4, lr}
 *   @0x1450c4 mov r3, #0
 *   @0x1450c8 str r3, [r0, #0xc]
 *   @0x1450cc mov r4, r0
 *   @0x1450d0 bl 0x163b18 <_Z27GR_3D_Transform_Stack_Emptyv>
 *   @0x1450d4 vmov s15, r0
 *   @0x1450d8 vcvt.f64.u32 d7, s15
 *   @0x1450dc vmov r0, r1, d7
 *   @0x1450e0 vmov r2, s14
 *   @0x1450e4 mov r3, r1
 *   @0x1450e8 stm r4, {r2, r3}
 *   @0x1450ec pop {r4, pc}
 *
 * ══ §476/561 F_D3DTransformStackPush(RValue&, CInstance*, CInstance*, int, RValue*)  0x1450f0  size 48  12 条（0x1450f0..0x145120）
 * @func 0x1450f0 0x145120  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Push()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1450f0 push {r4, lr}
 *   @0x1450f4 mov r3, #0
 *   @0x1450f8 str r3, [r0, #0xc]
 *   @0x1450fc mov r4, r0
 *   @0x145100 bl 0x163b30 <_Z26GR_3D_Transform_Stack_Pushv>
 *   @0x145104 vmov s15, r0
 *   @0x145108 vcvt.f64.u32 d7, s15
 *   @0x14510c vmov r0, r1, d7
 *   @0x145110 vmov r2, s14
 *   @0x145114 mov r3, r1
 *   @0x145118 stm r4, {r2, r3}
 *   @0x14511c pop {r4, pc}
 *
 * ══ §477/561 F_D3DTransformStackPop(RValue&, CInstance*, CInstance*, int, RValue*)  0x145120  size 48  12 条（0x145120..0x145150）
 * @func 0x145120 0x145150  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Pop()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145120 push {r4, lr}
 *   @0x145124 mov r3, #0
 *   @0x145128 str r3, [r0, #0xc]
 *   @0x14512c mov r4, r0
 *   @0x145130 bl 0x163b7c <_Z25GR_3D_Transform_Stack_Popv>
 *   @0x145134 vmov s15, r0
 *   @0x145138 vcvt.f64.u32 d7, s15
 *   @0x14513c vmov r0, r1, d7
 *   @0x145140 vmov r2, s14
 *   @0x145144 mov r3, r1
 *   @0x145148 stm r4, {r2, r3}
 *   @0x14514c pop {r4, pc}
 *
 * ══ §478/561 F_D3DTransformStackTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x145150  size 48  12 条（0x145150..0x145180）
 * @func 0x145150 0x145180  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Top()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145150 push {r4, lr}
 *   @0x145154 mov r3, #0
 *   @0x145158 str r3, [r0, #0xc]
 *   @0x14515c mov r4, r0
 *   @0x145160 bl 0x163bd0 <_Z25GR_3D_Transform_Stack_Topv>
 *   @0x145164 vmov s15, r0
 *   @0x145168 vcvt.f64.u32 d7, s15
 *   @0x14516c vmov r0, r1, d7
 *   @0x145170 vmov r2, s14
 *   @0x145174 mov r3, r1
 *   @0x145178 stm r4, {r2, r3}
 *   @0x14517c pop {r4, pc}
 *
 * ══ §479/561 F_D3DTransformStackDiscard(RValue&, CInstance*, CInstance*, int, RValue*)  0x145180  size 48  12 条（0x145180..0x1451b0）
 * @func 0x145180 0x1451b0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Transform_Stack_Discard()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145180 push {r4, lr}
 *   @0x145184 mov r3, #0
 *   @0x145188 str r3, [r0, #0xc]
 *   @0x14518c mov r4, r0
 *   @0x145190 bl 0x163c14 <_Z29GR_3D_Transform_Stack_Discardv>
 *   @0x145194 vmov s15, r0
 *   @0x145198 vcvt.f64.u32 d7, s15
 *   @0x14519c vmov r0, r1, d7
 *   @0x1451a0 vmov r2, s14
 *   @0x1451a4 mov r3, r1
 *   @0x1451a8 stm r4, {r2, r3}
 *   @0x1451ac pop {r4, pc}
 *
 * ══ §480/561 F_D3DModelCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1451d8  size 48  12 条（0x1451d8..0x145208）
 * @func 0x1451d8 0x145208  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Create()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1451d8 push {r4, lr}
 *   @0x1451dc mov r3, #0
 *   @0x1451e0 str r3, [r0, #0xc]
 *   @0x1451e4 mov r4, r0
 *   @0x1451e8 bl 0x1650c0 <_Z13GR_3DM_Createv>
 *   @0x1451ec vmov s15, r0
 *   @0x1451f0 vcvt.f64.s32 d7, s15
 *   @0x1451f4 vmov r0, r1, d7
 *   @0x1451f8 vmov r2, s14
 *   @0x1451fc mov r3, r1
 *   @0x145200 stm r4, {r2, r3}
 *   @0x145204 pop {r4, pc}
 *
 * ══ §481/561 F_GamepadSupported(RValue&, CInstance*, CInstance*, int, RValue*)  0x15123c  size 48  12 条（0x15123c..0x15126c）
 * @func 0x15123c 0x15126c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GamepadSupportedM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15123c push {r3, r4, r5, lr}
 *   @0x151240 mov r5, #0
 *   @0x151244 str r5, [r0, #0xc]
 *   @0x151248 mov r4, r0
 *   @0x15124c bl 0x190ac4 <_Z17GamepadSupportedMv>
 *   @0x151250 cmp r0, #0
 *   @0x151254 movne r0, r5
 *   @0x151258 moveq r3, r0
 *   @0x15125c movne r3, r0
 *   @0x151260 movtne r3, #0x3ff0
 *   @0x151264 stm r4, {r0, r3}
 *   @0x151268 pop {r3, r4, r5, pc}
 *
 * ══ §482/561 SPushNotificationEvent::SPushNotificationEvent(int, ePushEventType, char const*)  0x155b50  size 48  12 条（0x155b50..0x155b80）
 * @func 0x155b50 0x155b80  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155b50 push {r4, lr}
 *   @0x155b54 mov r4, r0
 *   @0x155b58 str r1, [r0, #0x4]
 *   @0x155b5c mov r12, #0
 *   @0x155b60 mov r0, r3
 *   @0x155b64 str r2, [r4, #0x8]
 *   @0x155b68 str r12, [r4]
 *   @0x155b6c str r12, [r4, #0xc]
 *   @0x155b70 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x155b74 str r0, [r4, #0xc]
 *   @0x155b78 mov r0, r4
 *   @0x155b7c pop {r4, pc}
 *
 * ══ §483/561 F_YoYo_WinPhone_SetTile_Common_Count(RValue&, CInstance*, CInstance*, int, RValue*)  0x156264  size 48  12 条（0x156264..0x156294）
 * @func 0x156264 0x156294  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156264 push {r3, lr}
 *   @0x156268 ldr r3, [pc, #0x1c]
 *   @0x15626c ldr r1, [pc, #0x1c]
 *   @0x156270 ldr r3, [pc, r3]
 *   @0x156274 add r1, pc, r1
 *   @0x156278 ldr r0, [r3]
 *   @0x15627c ldr r3, [r0]
 *   @0x156280 ldr r3, [r3, #0xc]
 *   @0x156284 blx r3
 *   @0x156288 pop {r3, pc}
 *   @0x15628c eoreq r7, r9, r4, lsr #9
 *   @0x156290 mulseq pc, r8, r2
 *
 * ══ §484/561 F_YoYo_WinPhone_SetTile_Iconic_BackgroundColour(RValue&, CInstance*, CInstance*, int, RValue*)  0x156294  size 48  12 条（0x156294..0x1562c4）
 * @func 0x156294 0x1562c4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156294 push {r3, lr}
 *   @0x156298 ldr r3, [pc, #0x1c]
 *   @0x15629c ldr r1, [pc, #0x1c]
 *   @0x1562a0 ldr r3, [pc, r3]
 *   @0x1562a4 add r1, pc, r1
 *   @0x1562a8 ldr r0, [r3]
 *   @0x1562ac ldr r3, [r0]
 *   @0x1562b0 ldr r3, [r3, #0xc]
 *   @0x1562b4 blx r3
 *   @0x1562b8 pop {r3, pc}
 *   @0x1562bc eoreq r7, r9, r4, ror r4
 *   @0x1562c0 andseq r0, pc, r8, ror #4
 *
 * ══ §485/561 F_YoYo_GetDevice(RValue&, CInstance*, CInstance*, int, RValue*)  0x156efc  size 48  12 条（0x156efc..0x156f2c）
 * @func 0x156efc 0x156f2c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDeviceM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156efc push {r4, lr}
 *   @0x156f00 mov r3, #0
 *   @0x156f04 str r3, [r0, #0xc]
 *   @0x156f08 mov r4, r0
 *   @0x156f0c bl 0x15e64c <_Z10GetDeviceMv>
 *   @0x156f10 vmov s15, r0
 *   @0x156f14 vcvt.f64.s32 d7, s15
 *   @0x156f18 vmov r0, r1, d7
 *   @0x156f1c vmov r2, s14
 *   @0x156f20 mov r3, r1
 *   @0x156f24 stm r4, {r2, r3}
 *   @0x156f28 pop {r4, pc}
 *
 * ══ §486/561 F_YoYo_GetCPUDetails(RValue&, CInstance*, CInstance*, int, RValue*)  0x156f60  size 48  12 条（0x156f60..0x156f90）
 * @func 0x156f60 0x156f90  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetCPUDetailsM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156f60 push {r4, lr}
 *   @0x156f64 mov r3, #0
 *   @0x156f68 str r3, [r0, #0xc]
 *   @0x156f6c mov r4, r0
 *   @0x156f70 bl 0x15e66c <_Z14GetCPUDetailsMv>
 *   @0x156f74 vmov s15, r0
 *   @0x156f78 vcvt.f64.s32 d7, s15
 *   @0x156f7c vmov r0, r1, d7
 *   @0x156f80 vmov r2, s14
 *   @0x156f84 mov r3, r1
 *   @0x156f88 stm r4, {r2, r3}
 *   @0x156f8c pop {r4, pc}
 *
 * ══ §487/561 F_YoYo_Achievement_IsOnline(RValue&, CInstance*, CInstance*, int, RValue*)  0x1571a8  size 48  12 条（0x1571a8..0x1571d8）
 * @func 0x1571a8 0x1571d8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Achievement_LoginStatus()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1571a8 push {r4, lr}
 *   @0x1571ac mov r3, #0
 *   @0x1571b0 str r3, [r0, #0xc]
 *   @0x1571b4 mov r4, r0
 *   @0x1571b8 bl 0x160f4c <_Z23Achievement_LoginStatusv>
 *   @0x1571bc vmov s15, r0
 *   @0x1571c0 vcvt.f64.s32 d7, s15
 *   @0x1571c4 vmov r0, r1, d7
 *   @0x1571c8 vmov r2, s14
 *   @0x1571cc mov r3, r1
 *   @0x1571d0 stm r4, {r2, r3}
 *   @0x1571d4 pop {r4, pc}
 *
 * ══ §488/561 F_YoYo_FacebookInit(RValue&, CInstance*, CInstance*, int, RValue*)  0x15720c  size 48  12 条（0x15720c..0x15723c）
 * @func 0x15720c 0x15723c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FacebookInitM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15720c push {r4, lr}
 *   @0x157210 mov r3, #0
 *   @0x157214 str r3, [r0, #0xc]
 *   @0x157218 mov r4, r0
 *   @0x15721c bl 0x15e7ec <_Z13FacebookInitMv>
 *   @0x157220 vmov s15, r0
 *   @0x157224 vcvt.f64.s32 d7, s15
 *   @0x157228 vmov r0, r1, d7
 *   @0x15722c vmov r2, s14
 *   @0x157230 mov r3, r1
 *   @0x157234 stm r4, {r2, r3}
 *   @0x157238 pop {r4, pc}
 *
 * ══ §489/561 F_YoYo_FacebookLogout(RValue&, CInstance*, CInstance*, int, RValue*)  0x157520  size 48  12 条（0x157520..0x157550）
 * @func 0x157520 0x157550  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FacebookLogoutM()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157520 push {r4, lr}
 *   @0x157524 mov r3, #0
 *   @0x157528 str r3, [r0, #0xc]
 *   @0x15752c mov r4, r0
 *   @0x157530 bl 0x15ef48 <_Z15FacebookLogoutMv>
 *   @0x157534 vmov s15, r0
 *   @0x157538 vcvt.f64.s32 d7, s15
 *   @0x15753c vmov r0, r1, d7
 *   @0x157540 vmov r2, s14
 *   @0x157544 mov r3, r1
 *   @0x157548 stm r4, {r2, r3}
 *   @0x15754c pop {r4, pc}
 *
 * ══ §490/561 F_YoYo_GetDPIX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1576b8  size 48  12 条（0x1576b8..0x1576e8）
 * @func 0x1576b8 0x1576e8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDPIX()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1576b8 push {r4, lr}
 *   @0x1576bc mov r3, #0
 *   @0x1576c0 str r3, [r0, #0xc]
 *   @0x1576c4 mov r4, r0
 *   @0x1576c8 bl 0x15f244 <_Z7GetDPIXv>
 *   @0x1576cc vmov s15, r0
 *   @0x1576d0 vcvt.f64.f32 d7, s15
 *   @0x1576d4 vmov r0, r1, d7
 *   @0x1576d8 vmov r2, s14
 *   @0x1576dc mov r3, r1
 *   @0x1576e0 stm r4, {r2, r3}
 *   @0x1576e4 pop {r4, pc}
 *
 * ══ §491/561 F_YoYo_GetDPIY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1576e8  size 48  12 条（0x1576e8..0x157718）
 * @func 0x1576e8 0x157718  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDPIY()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1576e8 push {r4, lr}
 *   @0x1576ec mov r3, #0
 *   @0x1576f0 str r3, [r0, #0xc]
 *   @0x1576f4 mov r4, r0
 *   @0x1576f8 bl 0x15f258 <_Z7GetDPIYv>
 *   @0x1576fc vmov s15, r0
 *   @0x157700 vcvt.f64.f32 d7, s15
 *   @0x157704 vmov r0, r1, d7
 *   @0x157708 vmov r2, s14
 *   @0x15770c mov r3, r1
 *   @0x157710 stm r4, {r2, r3}
 *   @0x157714 pop {r4, pc}
 *
 * ══ §492/561 F_YoYo_IsNetworkConnected(RValue&, CInstance*, CInstance*, int, RValue*)  0x157f1c  size 48  12 条（0x157f1c..0x157f4c）
 * @func 0x157f1c 0x157f4c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetIsNetworkConnected()
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157f1c push {r3, r4, r5, lr}
 *   @0x157f20 mov r5, #0
 *   @0x157f24 str r5, [r0, #0xc]
 *   @0x157f28 mov r4, r0
 *   @0x157f2c bl 0x15f26c <_Z21GetIsNetworkConnectedv>
 *   @0x157f30 cmp r0, #0
 *   @0x157f34 movne r0, r5
 *   @0x157f38 moveq r3, r0
 *   @0x157f3c movne r3, r0
 *   @0x157f40 movtne r3, #0x3ff0
 *   @0x157f44 stm r4, {r0, r3}
 *   @0x157f48 pop {r3, r4, r5, pc}
 *
 * ══ §493/561 F_GMLReleaseMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x1586d4  size 48  12 条（0x1586d4..0x158704）
 * @func 0x1586d4 0x158704  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1586d4 push {r3, lr}
 *   @0x1586d8 mov r1, #0
 *   @0x1586dc ldr r0, [sp, #0x8]
 *   @0x1586e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1586e4 vmov.f64 d7, #5.000000e-01
 *   @0x1586e8 pop {r3, lr}
 *   @0x1586ec vmov d6, r0, r1
 *   @0x1586f0 vcmpe.f64 d6, d7
 *   @0x1586f4 vmrs APSR_nzcv, fpscr
 *   @0x1586f8 movpl r0, #0
 *   @0x1586fc movmi r0, #1
 *   @0x158700 b 0x2a28ec <_Z12SetDebugModeb>
 *
 * ══ §494/561 Achievement_LoginStatus()  0x160f4c  size 48  12 条（0x160f4c..0x160f7c）
 * @func 0x160f4c 0x160f7c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160f4c push {r3, lr}
 *   @0x160f50 bl 0x290274 <getJNIEnv>
 *   @0x160f54 ldr r2, [pc, #0x18]
 *   @0x160f58 ldr r3, [pc, #0x18]
 *   @0x160f5c ldr r2, [pc, r2]
 *   @0x160f60 ldr r3, [pc, r3]
 *   @0x160f64 ldr r1, [r2]
 *   @0x160f68 ldr r2, [r3]
 *   @0x160f6c pop {r3, lr}
 *   @0x160f70 b 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x160f74 eoreq r12, r8, r8, asr #20
 *   @0x160f78 eoreq lr, r8, r0, asr #31
 *
 * ══ §495/561 Achievement_Login()  0x160f7c  size 48  12 条（0x160f7c..0x160fac）
 * @func 0x160f7c 0x160fac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160f7c push {r3, lr}
 *   @0x160f80 bl 0x290274 <getJNIEnv>
 *   @0x160f84 ldr r2, [pc, #0x18]
 *   @0x160f88 ldr r3, [pc, #0x18]
 *   @0x160f8c ldr r2, [pc, r2]
 *   @0x160f90 ldr r3, [pc, r3]
 *   @0x160f94 ldr r1, [r2]
 *   @0x160f98 ldr r2, [r3]
 *   @0x160f9c pop {r3, lr}
 *   @0x160fa0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x160fa4 eoreq r12, r8, r8, lsl r10
 *   @0x160fa8 mlaeq r8, r4, pc, lr
 *
 * ══ §496/561 Achievement_Logout()  0x160fac  size 48  12 条（0x160fac..0x160fdc）
 * @func 0x160fac 0x160fdc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160fac push {r3, lr}
 *   @0x160fb0 bl 0x290274 <getJNIEnv>
 *   @0x160fb4 ldr r2, [pc, #0x18]
 *   @0x160fb8 ldr r3, [pc, #0x18]
 *   @0x160fbc ldr r2, [pc, r2]
 *   @0x160fc0 ldr r3, [pc, r3]
 *   @0x160fc4 ldr r1, [r2]
 *   @0x160fc8 ldr r2, [r3]
 *   @0x160fcc pop {r3, lr}
 *   @0x160fd0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x160fd4 eoreq r12, r8, r8, ror #19
 *   @0x160fd8 eoreq lr, r8, r8, ror #30
 *
 * ══ §497/561 Achievement_Show_Achievement()  0x160fdc  size 48  12 条（0x160fdc..0x16100c）
 * @func 0x160fdc 0x16100c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160fdc push {r3, lr}
 *   @0x160fe0 bl 0x290274 <getJNIEnv>
 *   @0x160fe4 ldr r2, [pc, #0x18]
 *   @0x160fe8 ldr r3, [pc, #0x18]
 *   @0x160fec ldr r2, [pc, r2]
 *   @0x160ff0 ldr r3, [pc, r3]
 *   @0x160ff4 ldr r1, [r2]
 *   @0x160ff8 ldr r2, [r3]
 *   @0x160ffc pop {r3, lr}
 *   @0x161000 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161004 .word 0x0028c9b8
 *   @0x161008 eoreq lr, r8, r12, lsr pc
 *
 * ══ §498/561 Achievement_Load_Friends()  0x161138  size 48  12 条（0x161138..0x161168）
 * @func 0x161138 0x161168  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161138 push {r3, lr}
 *   @0x16113c bl 0x290274 <getJNIEnv>
 *   @0x161140 ldr r2, [pc, #0x18]
 *   @0x161144 ldr r3, [pc, #0x18]
 *   @0x161148 ldr r2, [pc, r2]
 *   @0x16114c ldr r3, [pc, r3]
 *   @0x161150 ldr r1, [r2]
 *   @0x161154 ldr r2, [r3]
 *   @0x161158 pop {r3, lr}
 *   @0x16115c b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161160 eoreq r12, r8, r12, asr r8
 *   @0x161164 .word 0x0028edf0
 *
 * ══ §499/561 Achievement_Show_Leaderboard()  0x161280  size 48  12 条（0x161280..0x1612b0）
 * @func 0x161280 0x1612b0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161280 push {r3, lr}
 *   @0x161284 bl 0x290274 <getJNIEnv>
 *   @0x161288 ldr r2, [pc, #0x18]
 *   @0x16128c ldr r3, [pc, #0x18]
 *   @0x161290 ldr r2, [pc, r2]
 *   @0x161294 ldr r3, [pc, r3]
 *   @0x161298 ldr r1, [r2]
 *   @0x16129c ldr r2, [r3]
 *   @0x1612a0 pop {r3, lr}
 *   @0x1612a4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x1612a8 eoreq r12, r8, r4, lsl r7
 *   @0x1612ac .word 0x0028ecb4
 *
 * ══ §500/561 F_Steam_ActivateOverlay(RValue&, CInstance*, CInstance*, int, RValue*)  0x162440  size 48  12 条（0x162440..0x162470）
 * @func 0x162440 0x162470  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162440 push {r4, lr}
 *   @0x162444 mov r1, #0
 *   @0x162448 mov r4, r0
 *   @0x16244c ldr r0, [sp, #0x8]
 *   @0x162450 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x162454 mov r2, #0
 *   @0x162458 mov r3, r2
 *   @0x16245c movt r2, #0xbff0
 *   @0x162460 str r3, [r4, #0xc]
 *   @0x162464 str r2, [r4, #0x4]
 *   @0x162468 str r3, [r4]
 *   @0x16246c pop {r4, pc}
 *
 * ══ §501/561 GR_D3D_Set_Alpha_Test_Enable(bool)  0x168664  size 48  12 条（0x168664..0x168694）
 * @func 0x168664 0x168694  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168664 ldr r3, [pc, #0x20]
 *   @0x168668 ldr r3, [pc, r3]
 *   @0x16866c ldrb r3, [r3]
 *   @0x168670 cmp r3, #0
 *   @0x168674 bxeq lr
 *   @0x168678 ldr r3, [pc, #0x10]
 *   @0x16867c mov r2, r0
 *   @0x168680 mov r1, #5
 *   @0x168684 ldr r0, [pc, r3]
 *   @0x168688 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x16868c .word 0x00287ab8
 *   @0x168690 eoreq r5, r8, r4, ror r6
 *
 * ══ §502/561 Shader_Reload(int)  0x187ea4  size 48  12 条（0x187ea4..0x187ed4）
 * @func 0x187ea4 0x187ed4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Get(int) / Shader_Build(GLSLShader*, char**, bool*, int, char**)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187ea4 str lr, [sp, #-0x4]!
 *   @0x187ea8 sub sp, sp, #12
 *   @0x187eac bl 0x187e70 <_Z10Shader_Geti>
 *   @0x187eb0 cmp r0, #0
 *   @0x187eb4 beq 0x187ecc <_Z13Shader_Reloadi+0x28>
 *   @0x187eb8 mov r1, #0
 *   @0x187ebc str r1, [sp]
 *   @0x187ec0 mov r2, r1
 *   @0x187ec4 mov r3, r1
 *   @0x187ec8 bl 0x187468 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_>
 *   @0x187ecc add sp, sp, #12
 *   @0x187ed0 ldr pc, [sp], #4
 *
 * ══ §503/561 anon_1910b4  0x1910b4  size 48  12 条（0x1910b4..0x1910e4）
 * @func 0x1910b4 0x1910e4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGCGeneration::~CGCGeneration()×3
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1910b4 push {r4, lr}
 *   @0x1910b8 ldr r4, [pc, #0x24]
 *   @0x1910bc ldr r4, [pc, r4]
 *   @0x1910c0 add r0, r4, #264
 *   @0x1910c4 bl 0x191064 <_ZN13CGCGenerationD2Ev>
 *   @0x1910c8 add r0, r4, #176
 *   @0x1910cc bl 0x191064 <_ZN13CGCGenerationD2Ev>
 *   @0x1910d0 add r0, r4, #88
 *   @0x1910d4 bl 0x191064 <_ZN13CGCGenerationD2Ev>
 *   @0x1910d8 mov r0, r4
 *   @0x1910dc pop {r4, lr}
 *   @0x1910e0 b 0x191064 <_ZN13CGCGenerationD2Ev>
 *
 * ══ §504/561 CScriptRef::~CScriptRef()  0x19943c  size 48  12 条（0x19943c..0x19946c）
 * @func 0x19943c 0x19946c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::~YYObjectBase() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19943c ldr r3, [pc, #0x24]
 *   @0x199440 push {r4, lr}
 *   @0x199444 ldr r3, [pc, r3]
 *   @0x199448 mov r4, r0
 *   @0x19944c add r3, r3, #8
 *   @0x199450 str r3, [r0]
 *   @0x199454 bl 0x199110 <_ZN12YYObjectBaseD2Ev>
 *   @0x199458 mov r0, r4
 *   @0x19945c bl 0x27d1d0 <_ZdlPv>
 *   @0x199460 mov r0, r4
 *   @0x199464 pop {r4, pc}
 *   @0x199468 eoreq r7, r5, r8, lsr r2
 *
 * ══ §505/561 ParticleSystem_Particles_Count(int)  0x1a4150  size 48  12 条（0x1a4150..0x1a4180）
 * @func 0x1a4150 0x1a4180  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4150 push {r4, lr}
 *   @0x1a4154 mov r4, r0
 *   @0x1a4158 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a415c cmp r0, #0
 *   @0x1a4160 popeq {r4, pc}
 *   @0x1a4164 ldr r3, [pc, #0x10]
 *   @0x1a4168 ldr r3, [pc, r3]
 *   @0x1a416c ldr r3, [r3, #0x4]
 *   @0x1a4170 ldr r3, [r3, r4, lsl #2]
 *   @0x1a4174 ldr r0, [r3, #0x8]
 *   @0x1a4178 pop {r4, pc}
 *   @0x1a417c eoreq r12, r4, r0, asr r6
 *
 * ══ §506/561 TFont::TFont()  0x1a867c  size 48  12 条（0x1a867c..0x1a86ac）
 * @func 0x1a867c 0x1a86ac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a867c ldr r1, [pc, #0x24]
 *   @0x1a8680 mov r2, #0
 *   @0x1a8684 str r2, [r0, #0x4]
 *   @0x1a8688 ldr r1, [pc, r1]
 *   @0x1a868c str r2, [r0, #0x8]
 *   @0x1a8690 add r1, r1, #8
 *   @0x1a8694 str r2, [r0, #0xc]
 *   @0x1a8698 str r1, [r0]
 *   @0x1a869c str r2, [r0, #0x10]
 *   @0x1a86a0 str r2, [r0, #0x14]
 *   @0x1a86a4 bx lr
 *   @0x1a86a8 eoreq r8, r4, r0, asr r1
 *
 * ══ §507/561 TBitmap::Clear()  0x1a8a44  size 48  12 条（0x1a8a44..0x1a8a74）
 * @func 0x1a8a44 0x1a8a74  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8a44 push {r4, lr}
 *   @0x1a8a48 mov r4, r0
 *   @0x1a8a4c ldr r0, [r0, #0x4]
 *   @0x1a8a50 cmp r0, #0
 *   @0x1a8a54 beq 0x1a8a5c <_ZN7TBitmap5ClearEv+0x18>
 *   @0x1a8a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a8a5c ldr r3, [r4, #0x28]
 *   @0x1a8a60 mov r2, #0
 *   @0x1a8a64 str r2, [r4, #0x4]
 *   @0x1a8a68 add r3, r3, #1
 *   @0x1a8a6c str r3, [r4, #0x28]
 *   @0x1a8a70 pop {r4, pc}
 *
 * ══ §508/561 CSingleFingerGesture::~CSingleFingerGesture()  0x1d531c  size 48  12 条（0x1d531c..0x1d534c）
 * @func 0x1d531c 0x1d534c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d531c ldr r3, [pc, #0x24]
 *   @0x1d5320 push {r4, lr}
 *   @0x1d5324 ldr r3, [pc, r3]
 *   @0x1d5328 mov r4, r0
 *   @0x1d532c add r3, r3, #8
 *   @0x1d5330 str r3, [r0]
 *   @0x1d5334 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5338 mov r0, r4
 *   @0x1d533c bl 0x27d1d0 <_ZdlPv>
 *   @0x1d5340 mov r0, r4
 *   @0x1d5344 pop {r4, pc}
 *   @0x1d5348 .word 0x0021b8d0
 *
 * ══ §509/561 CGestureUnknown::~CGestureUnknown()  0x1d5374  size 48  12 条（0x1d5374..0x1d53a4）
 * @func 0x1d5374 0x1d53a4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5374 ldr r3, [pc, #0x24]
 *   @0x1d5378 push {r4, lr}
 *   @0x1d537c ldr r3, [pc, r3]
 *   @0x1d5380 mov r4, r0
 *   @0x1d5384 add r3, r3, #8
 *   @0x1d5388 str r3, [r0]
 *   @0x1d538c bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5390 mov r0, r4
 *   @0x1d5394 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d5398 mov r0, r4
 *   @0x1d539c pop {r4, pc}
 *   @0x1d53a0 eoreq r11, r1, r8, ror r8
 *
 * ══ §510/561 CGestureTap::~CGestureTap()  0x1d53cc  size 48  12 条（0x1d53cc..0x1d53fc）
 * @func 0x1d53cc 0x1d53fc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d53cc ldr r3, [pc, #0x24]
 *   @0x1d53d0 push {r4, lr}
 *   @0x1d53d4 ldr r3, [pc, r3]
 *   @0x1d53d8 mov r4, r0
 *   @0x1d53dc add r3, r3, #8
 *   @0x1d53e0 str r3, [r0]
 *   @0x1d53e4 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d53e8 mov r0, r4
 *   @0x1d53ec bl 0x27d1d0 <_ZdlPv>
 *   @0x1d53f0 mov r0, r4
 *   @0x1d53f4 pop {r4, pc}
 *   @0x1d53f8 eoreq r11, r1, r0, lsr #16
 *
 * ══ §511/561 CGestureDoubleTap::~CGestureDoubleTap()  0x1d5424  size 48  12 条（0x1d5424..0x1d5454）
 * @func 0x1d5424 0x1d5454  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5424 ldr r3, [pc, #0x24]
 *   @0x1d5428 push {r4, lr}
 *   @0x1d542c ldr r3, [pc, r3]
 *   @0x1d5430 mov r4, r0
 *   @0x1d5434 add r3, r3, #8
 *   @0x1d5438 str r3, [r0]
 *   @0x1d543c bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5440 mov r0, r4
 *   @0x1d5444 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d5448 mov r0, r4
 *   @0x1d544c pop {r4, pc}
 *   @0x1d5450 eoreq r11, r1, r8, asr #15
 *
 * ══ §512/561 CGestureDrag::~CGestureDrag()  0x1d547c  size 48  12 条（0x1d547c..0x1d54ac）
 * @func 0x1d547c 0x1d54ac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d547c ldr r3, [pc, #0x24]
 *   @0x1d5480 push {r4, lr}
 *   @0x1d5484 ldr r3, [pc, r3]
 *   @0x1d5488 mov r4, r0
 *   @0x1d548c add r3, r3, #8
 *   @0x1d5490 str r3, [r0]
 *   @0x1d5494 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5498 mov r0, r4
 *   @0x1d549c bl 0x27d1d0 <_ZdlPv>
 *   @0x1d54a0 mov r0, r4
 *   @0x1d54a4 pop {r4, pc}
 *   @0x1d54a8 eoreq r11, r1, r0, ror r7
 *
 * ══ §513/561 CGesturePinch::~CGesturePinch()  0x1d54d4  size 48  12 条（0x1d54d4..0x1d5504）
 * @func 0x1d54d4 0x1d5504  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d54d4 ldr r3, [pc, #0x24]
 *   @0x1d54d8 push {r4, lr}
 *   @0x1d54dc ldr r3, [pc, r3]
 *   @0x1d54e0 mov r4, r0
 *   @0x1d54e4 add r3, r3, #8
 *   @0x1d54e8 str r3, [r0]
 *   @0x1d54ec bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d54f0 mov r0, r4
 *   @0x1d54f4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d54f8 mov r0, r4
 *   @0x1d54fc pop {r4, pc}
 *   @0x1d5500 eoreq r11, r1, r12, lsl r7
 *
 * ══ §514/561 CGestureRotate::~CGestureRotate()  0x1d552c  size 48  12 条（0x1d552c..0x1d555c）
 * @func 0x1d552c 0x1d555c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CGesture::~CGesture() / operator delete(void*)
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d552c ldr r3, [pc, #0x24]
 *   @0x1d5530 push {r4, lr}
 *   @0x1d5534 ldr r3, [pc, r3]
 *   @0x1d5538 mov r4, r0
 *   @0x1d553c add r3, r3, #8
 *   @0x1d5540 str r3, [r0]
 *   @0x1d5544 bl 0x1d52a4 <_ZN8CGestureD2Ev>
 *   @0x1d5548 mov r0, r4
 *   @0x1d554c bl 0x27d1d0 <_ZdlPv>
 *   @0x1d5550 mov r0, r4
 *   @0x1d5554 pop {r4, pc}
 *   @0x1d5558 eoreq r11, r1, r8, asr #13
 *
 * ══ §515/561 Code_Load(unsigned char*, unsigned int, unsigned char*)  0x1dc800  size 48  12 条（0x1dc800..0x1dc830）
 * @func 0x1dc800 0x1dc830  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc800 mov r1, r0
 *   @0x1dc804 ldr r2, [pc, #0x1c]
 *   @0x1dc808 ldr r3, [pc, #0x1c]
 *   @0x1dc80c mov r0, #1
 *   @0x1dc810 ldr r12, [r1], #4
 *   @0x1dc814 ldr r2, [pc, r2]
 *   @0x1dc818 ldr r3, [pc, r3]
 *   @0x1dc81c str r1, [r2]
 *   @0x1dc820 str r12, [r3]
 *   @0x1dc824 bx lr
 *   @0x1dc828 eoreq r1, r1, r4, lsr r3
 *   @0x1dc82c eoreq r1, r1, r12, lsr #6
 *
 * ══ §516/561 GLOB_Load(unsigned char*, unsigned int, unsigned char*)  0x1dcf64  size 48  12 条（0x1dcf64..0x1dcf94）
 * @func 0x1dcf64 0x1dcf94  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dcf64 mov r1, r0
 *   @0x1dcf68 ldr r2, [pc, #0x1c]
 *   @0x1dcf6c ldr r3, [pc, #0x1c]
 *   @0x1dcf70 mov r0, #1
 *   @0x1dcf74 ldr r12, [r1], #4
 *   @0x1dcf78 ldr r2, [pc, r2]
 *   @0x1dcf7c ldr r3, [pc, r3]
 *   @0x1dcf80 str r1, [r2]
 *   @0x1dcf84 str r12, [r3]
 *   @0x1dcf88 bx lr
 *   @0x1dcf8c eoreq r3, r1, r12, lsr #26
 *   @0x1dcf90 eoreq r3, r1, r12, lsr #26
 *
 * ══ §517/561 CVariableList::Add(RVariable*)  0x1f51e8  size 48  12 条（0x1f51e8..0x1f5218）
 * @func 0x1f51e8 0x1f5218  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x4×2 / 0x18×2 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f51e8 ldr r3, [r1, #0x28]
 *   @0x1f51ec ldr r12, [r0, #0x14]
 *   @0x1f51f0 and r3, r3, #3
 *   @0x1f51f4 add r3, r0, r3, lsl #2
 *   @0x1f51f8 ldr r2, [r3, #0x4]
 *   @0x1f51fc stm r1, {r2, r12}
 *   @0x1f5200 str r1, [r3, #0x4]
 *   @0x1f5204 ldr r3, [r0, #0x18]
 *   @0x1f5208 str r1, [r0, #0x14]
 *   @0x1f520c add r3, r3, #1
 *   @0x1f5210 str r3, [r0, #0x18]
 *   @0x1f5214 bx lr
 *
 * ══ §518/561 GV_X(CInstance*, int, RValue*)  0x1f8bc0  size 48  12 条（0x1f8bc0..0x1f8bf0）
 * @func 0x1f8bc0 0x1f8bf0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8bc0 vldr s15, [r0, #180]
 *   @0x1f8bc4 vcvt.f64.f32 d6, s15
 *   @0x1f8bc8 push {r4, r5}
 *   @0x1f8bcc mov r3, #0
 *   @0x1f8bd0 mov r0, #1
 *   @0x1f8bd4 str r3, [r2, #0xc]
 *   @0x1f8bd8 vmov r4, r5, d6
 *   @0x1f8bdc vmov r1, s12
 *   @0x1f8be0 mov r3, r5
 *   @0x1f8be4 pop {r4, r5}
 *   @0x1f8be8 stm r2, {r1, r3}
 *   @0x1f8bec bx lr
 *
 * ══ §519/561 GV_Y(CInstance*, int, RValue*)  0x1f8bf0  size 48  12 条（0x1f8bf0..0x1f8c20）
 * @func 0x1f8bf0 0x1f8c20  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8bf0 vldr s15, [r0, #184]
 *   @0x1f8bf4 vcvt.f64.f32 d6, s15
 *   @0x1f8bf8 push {r4, r5}
 *   @0x1f8bfc mov r3, #0
 *   @0x1f8c00 mov r0, #1
 *   @0x1f8c04 str r3, [r2, #0xc]
 *   @0x1f8c08 vmov r4, r5, d6
 *   @0x1f8c0c vmov r1, s12
 *   @0x1f8c10 mov r3, r5
 *   @0x1f8c14 pop {r4, r5}
 *   @0x1f8c18 stm r2, {r1, r3}
 *   @0x1f8c1c bx lr
 *
 * ══ §520/561 GV_XPrevious(CInstance*, int, RValue*)  0x1f8c20  size 48  12 条（0x1f8c20..0x1f8c50）
 * @func 0x1f8c20 0x1f8c50  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8c20 vldr s15, [r0, #196]
 *   @0x1f8c24 vcvt.f64.f32 d6, s15
 *   @0x1f8c28 push {r4, r5}
 *   @0x1f8c2c mov r3, #0
 *   @0x1f8c30 mov r0, #1
 *   @0x1f8c34 str r3, [r2, #0xc]
 *   @0x1f8c38 vmov r4, r5, d6
 *   @0x1f8c3c vmov r1, s12
 *   @0x1f8c40 mov r3, r5
 *   @0x1f8c44 pop {r4, r5}
 *   @0x1f8c48 stm r2, {r1, r3}
 *   @0x1f8c4c bx lr
 *
 * ══ §521/561 GV_YPrevious(CInstance*, int, RValue*)  0x1f8c50  size 48  12 条（0x1f8c50..0x1f8c80）
 * @func 0x1f8c50 0x1f8c80  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8c50 vldr s15, [r0, #200]
 *   @0x1f8c54 vcvt.f64.f32 d6, s15
 *   @0x1f8c58 push {r4, r5}
 *   @0x1f8c5c mov r3, #0
 *   @0x1f8c60 mov r0, #1
 *   @0x1f8c64 str r3, [r2, #0xc]
 *   @0x1f8c68 vmov r4, r5, d6
 *   @0x1f8c6c vmov r1, s12
 *   @0x1f8c70 mov r3, r5
 *   @0x1f8c74 pop {r4, r5}
 *   @0x1f8c78 stm r2, {r1, r3}
 *   @0x1f8c7c bx lr
 *
 * ══ §522/561 GV_XStart(CInstance*, int, RValue*)  0x1f8c80  size 48  12 条（0x1f8c80..0x1f8cb0）
 * @func 0x1f8c80 0x1f8cb0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8c80 vldr s15, [r0, #188]
 *   @0x1f8c84 vcvt.f64.f32 d6, s15
 *   @0x1f8c88 push {r4, r5}
 *   @0x1f8c8c mov r3, #0
 *   @0x1f8c90 mov r0, #1
 *   @0x1f8c94 str r3, [r2, #0xc]
 *   @0x1f8c98 vmov r4, r5, d6
 *   @0x1f8c9c vmov r1, s12
 *   @0x1f8ca0 mov r3, r5
 *   @0x1f8ca4 pop {r4, r5}
 *   @0x1f8ca8 stm r2, {r1, r3}
 *   @0x1f8cac bx lr
 *
 * ══ §523/561 GV_YStart(CInstance*, int, RValue*)  0x1f8cb0  size 48  12 条（0x1f8cb0..0x1f8ce0）
 * @func 0x1f8cb0 0x1f8ce0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8cb0 vldr s15, [r0, #192]
 *   @0x1f8cb4 vcvt.f64.f32 d6, s15
 *   @0x1f8cb8 push {r4, r5}
 *   @0x1f8cbc mov r3, #0
 *   @0x1f8cc0 mov r0, #1
 *   @0x1f8cc4 str r3, [r2, #0xc]
 *   @0x1f8cc8 vmov r4, r5, d6
 *   @0x1f8ccc vmov r1, s12
 *   @0x1f8cd0 mov r3, r5
 *   @0x1f8cd4 pop {r4, r5}
 *   @0x1f8cd8 stm r2, {r1, r3}
 *   @0x1f8cdc bx lr
 *
 * ══ §524/561 GV_Hspeed(CInstance*, int, RValue*)  0x1f8ce0  size 48  12 条（0x1f8ce0..0x1f8d10）
 * @func 0x1f8ce0 0x1f8d10  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8ce0 vldr s15, [r0, #224]
 *   @0x1f8ce4 vcvt.f64.f32 d6, s15
 *   @0x1f8ce8 push {r4, r5}
 *   @0x1f8cec mov r3, #0
 *   @0x1f8cf0 mov r0, #1
 *   @0x1f8cf4 str r3, [r2, #0xc]
 *   @0x1f8cf8 vmov r4, r5, d6
 *   @0x1f8cfc vmov r1, s12
 *   @0x1f8d00 mov r3, r5
 *   @0x1f8d04 pop {r4, r5}
 *   @0x1f8d08 stm r2, {r1, r3}
 *   @0x1f8d0c bx lr
 *
 * ══ §525/561 GV_Vspeed(CInstance*, int, RValue*)  0x1f8d10  size 48  12 条（0x1f8d10..0x1f8d40）
 * @func 0x1f8d10 0x1f8d40  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8d10 vldr s15, [r0, #228]
 *   @0x1f8d14 vcvt.f64.f32 d6, s15
 *   @0x1f8d18 push {r4, r5}
 *   @0x1f8d1c mov r3, #0
 *   @0x1f8d20 mov r0, #1
 *   @0x1f8d24 str r3, [r2, #0xc]
 *   @0x1f8d28 vmov r4, r5, d6
 *   @0x1f8d2c vmov r1, s12
 *   @0x1f8d30 mov r3, r5
 *   @0x1f8d34 pop {r4, r5}
 *   @0x1f8d38 stm r2, {r1, r3}
 *   @0x1f8d3c bx lr
 *
 * ══ §526/561 GV_Direction(CInstance*, int, RValue*)  0x1f8d40  size 48  12 条（0x1f8d40..0x1f8d70）
 * @func 0x1f8d40 0x1f8d70  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8d40 vldr s15, [r0, #204]
 *   @0x1f8d44 vcvt.f64.f32 d6, s15
 *   @0x1f8d48 push {r4, r5}
 *   @0x1f8d4c mov r3, #0
 *   @0x1f8d50 mov r0, #1
 *   @0x1f8d54 str r3, [r2, #0xc]
 *   @0x1f8d58 vmov r4, r5, d6
 *   @0x1f8d5c vmov r1, s12
 *   @0x1f8d60 mov r3, r5
 *   @0x1f8d64 pop {r4, r5}
 *   @0x1f8d68 stm r2, {r1, r3}
 *   @0x1f8d6c bx lr
 *
 * ══ §527/561 GV_Speed(CInstance*, int, RValue*)  0x1f8d70  size 48  12 条（0x1f8d70..0x1f8da0）
 * @func 0x1f8d70 0x1f8da0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8d70 vldr s15, [r0, #208]
 *   @0x1f8d74 vcvt.f64.f32 d6, s15
 *   @0x1f8d78 push {r4, r5}
 *   @0x1f8d7c mov r3, #0
 *   @0x1f8d80 mov r0, #1
 *   @0x1f8d84 str r3, [r2, #0xc]
 *   @0x1f8d88 vmov r4, r5, d6
 *   @0x1f8d8c vmov r1, s12
 *   @0x1f8d90 mov r3, r5
 *   @0x1f8d94 pop {r4, r5}
 *   @0x1f8d98 stm r2, {r1, r3}
 *   @0x1f8d9c bx lr
 *
 * ══ §528/561 GV_Friction(CInstance*, int, RValue*)  0x1f8da0  size 48  12 条（0x1f8da0..0x1f8dd0）
 * @func 0x1f8da0 0x1f8dd0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8da0 vldr s15, [r0, #212]
 *   @0x1f8da4 vcvt.f64.f32 d6, s15
 *   @0x1f8da8 push {r4, r5}
 *   @0x1f8dac mov r3, #0
 *   @0x1f8db0 mov r0, #1
 *   @0x1f8db4 str r3, [r2, #0xc]
 *   @0x1f8db8 vmov r4, r5, d6
 *   @0x1f8dbc vmov r1, s12
 *   @0x1f8dc0 mov r3, r5
 *   @0x1f8dc4 pop {r4, r5}
 *   @0x1f8dc8 stm r2, {r1, r3}
 *   @0x1f8dcc bx lr
 *
 * ══ §529/561 GV_Gravity(CInstance*, int, RValue*)  0x1f8dd0  size 48  12 条（0x1f8dd0..0x1f8e00）
 * @func 0x1f8dd0 0x1f8e00  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8dd0 vldr s15, [r0, #220]
 *   @0x1f8dd4 vcvt.f64.f32 d6, s15
 *   @0x1f8dd8 push {r4, r5}
 *   @0x1f8ddc mov r3, #0
 *   @0x1f8de0 mov r0, #1
 *   @0x1f8de4 str r3, [r2, #0xc]
 *   @0x1f8de8 vmov r4, r5, d6
 *   @0x1f8dec vmov r1, s12
 *   @0x1f8df0 mov r3, r5
 *   @0x1f8df4 pop {r4, r5}
 *   @0x1f8df8 stm r2, {r1, r3}
 *   @0x1f8dfc bx lr
 *
 * ══ §530/561 GV_GravityDir(CInstance*, int, RValue*)  0x1f8e00  size 48  12 条（0x1f8e00..0x1f8e30）
 * @func 0x1f8e00 0x1f8e30  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8e00 vldr s15, [r0, #216]
 *   @0x1f8e04 vcvt.f64.f32 d6, s15
 *   @0x1f8e08 push {r4, r5}
 *   @0x1f8e0c mov r3, #0
 *   @0x1f8e10 mov r0, #1
 *   @0x1f8e14 str r3, [r2, #0xc]
 *   @0x1f8e18 vmov r4, r5, d6
 *   @0x1f8e1c vmov r1, s12
 *   @0x1f8e20 mov r3, r5
 *   @0x1f8e24 pop {r4, r5}
 *   @0x1f8e28 stm r2, {r1, r3}
 *   @0x1f8e2c bx lr
 *
 * ══ §531/561 GV_Depth(CInstance*, int, RValue*)  0x1f8f34  size 48  12 条（0x1f8f34..0x1f8f64）
 * @func 0x1f8f34 0x1f8f64  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8f34 vldr s15, [r0, #384]
 *   @0x1f8f38 vcvt.f64.f32 d6, s15
 *   @0x1f8f3c push {r4, r5}
 *   @0x1f8f40 mov r3, #0
 *   @0x1f8f44 mov r0, #1
 *   @0x1f8f48 str r3, [r2, #0xc]
 *   @0x1f8f4c vmov r4, r5, d6
 *   @0x1f8f50 vmov r1, s12
 *   @0x1f8f54 mov r3, r5
 *   @0x1f8f58 pop {r4, r5}
 *   @0x1f8f5c stm r2, {r1, r3}
 *   @0x1f8f60 bx lr
 *
 * ══ §532/561 GV_ImageIndex(CInstance*, int, RValue*)  0x1f8f98  size 48  12 条（0x1f8f98..0x1f8fc8）
 * @func 0x1f8f98 0x1f8fc8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8f98 vldr s15, [r0, #144]
 *   @0x1f8f9c vcvt.f64.f32 d6, s15
 *   @0x1f8fa0 push {r4, r5}
 *   @0x1f8fa4 mov r3, #0
 *   @0x1f8fa8 mov r0, #1
 *   @0x1f8fac str r3, [r2, #0xc]
 *   @0x1f8fb0 vmov r4, r5, d6
 *   @0x1f8fb4 vmov r1, s12
 *   @0x1f8fb8 mov r3, r5
 *   @0x1f8fbc pop {r4, r5}
 *   @0x1f8fc0 stm r2, {r1, r3}
 *   @0x1f8fc4 bx lr
 *
 * ══ §533/561 GV_ImageXScale(CInstance*, int, RValue*)  0x1f9008  size 48  12 条（0x1f9008..0x1f9038）
 * @func 0x1f9008 0x1f9038  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9008 vldr s15, [r0, #152]
 *   @0x1f900c vcvt.f64.f32 d6, s15
 *   @0x1f9010 push {r4, r5}
 *   @0x1f9014 mov r3, #0
 *   @0x1f9018 mov r0, #1
 *   @0x1f901c str r3, [r2, #0xc]
 *   @0x1f9020 vmov r4, r5, d6
 *   @0x1f9024 vmov r1, s12
 *   @0x1f9028 mov r3, r5
 *   @0x1f902c pop {r4, r5}
 *   @0x1f9030 stm r2, {r1, r3}
 *   @0x1f9034 bx lr
 *
 * ══ §534/561 GV_ImageYScale(CInstance*, int, RValue*)  0x1f9038  size 48  12 条（0x1f9038..0x1f9068）
 * @func 0x1f9038 0x1f9068  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9038 vldr s15, [r0, #156]
 *   @0x1f903c vcvt.f64.f32 d6, s15
 *   @0x1f9040 push {r4, r5}
 *   @0x1f9044 mov r3, #0
 *   @0x1f9048 mov r0, #1
 *   @0x1f904c str r3, [r2, #0xc]
 *   @0x1f9050 vmov r4, r5, d6
 *   @0x1f9054 vmov r1, s12
 *   @0x1f9058 mov r3, r5
 *   @0x1f905c pop {r4, r5}
 *   @0x1f9060 stm r2, {r1, r3}
 *   @0x1f9064 bx lr
 *
 * ══ §535/561 GV_ImageAngle(CInstance*, int, RValue*)  0x1f9068  size 48  12 条（0x1f9068..0x1f9098）
 * @func 0x1f9068 0x1f9098  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9068 vldr s15, [r0, #160]
 *   @0x1f906c vcvt.f64.f32 d6, s15
 *   @0x1f9070 push {r4, r5}
 *   @0x1f9074 mov r3, #0
 *   @0x1f9078 mov r0, #1
 *   @0x1f907c str r3, [r2, #0xc]
 *   @0x1f9080 vmov r4, r5, d6
 *   @0x1f9084 vmov r1, s12
 *   @0x1f9088 mov r3, r5
 *   @0x1f908c pop {r4, r5}
 *   @0x1f9090 stm r2, {r1, r3}
 *   @0x1f9094 bx lr
 *
 * ══ §536/561 GV_ImageAlpha(CInstance*, int, RValue*)  0x1f9098  size 48  12 条（0x1f9098..0x1f90c8）
 * @func 0x1f9098 0x1f90c8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9098 vldr s15, [r0, #164]
 *   @0x1f909c vcvt.f64.f32 d6, s15
 *   @0x1f90a0 push {r4, r5}
 *   @0x1f90a4 mov r3, #0
 *   @0x1f90a8 mov r0, #1
 *   @0x1f90ac str r3, [r2, #0xc]
 *   @0x1f90b0 vmov r4, r5, d6
 *   @0x1f90b4 vmov r1, s12
 *   @0x1f90b8 mov r3, r5
 *   @0x1f90bc pop {r4, r5}
 *   @0x1f90c0 stm r2, {r1, r3}
 *   @0x1f90c4 bx lr
 *
 * ══ §537/561 GV_ImageSpeed(CInstance*, int, RValue*)  0x1f90fc  size 48  12 条（0x1f90fc..0x1f912c）
 * @func 0x1f90fc 0x1f912c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f90fc vldr s15, [r0, #148]
 *   @0x1f9100 vcvt.f64.f32 d6, s15
 *   @0x1f9104 push {r4, r5}
 *   @0x1f9108 mov r3, #0
 *   @0x1f910c mov r0, #1
 *   @0x1f9110 str r3, [r2, #0xc]
 *   @0x1f9114 vmov r4, r5, d6
 *   @0x1f9118 vmov r1, s12
 *   @0x1f911c mov r3, r5
 *   @0x1f9120 pop {r4, r5}
 *   @0x1f9124 stm r2, {r1, r3}
 *   @0x1f9128 bx lr
 *
 * ══ §538/561 GV_PathPosition(CInstance*, int, RValue*)  0x1f9194  size 48  12 条（0x1f9194..0x1f91c4）
 * @func 0x1f9194 0x1f91c4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9194 vldr s15, [r0, #300]
 *   @0x1f9198 vcvt.f64.f32 d6, s15
 *   @0x1f919c push {r4, r5}
 *   @0x1f91a0 mov r3, #0
 *   @0x1f91a4 mov r0, #1
 *   @0x1f91a8 str r3, [r2, #0xc]
 *   @0x1f91ac vmov r4, r5, d6
 *   @0x1f91b0 vmov r1, s12
 *   @0x1f91b4 mov r3, r5
 *   @0x1f91b8 pop {r4, r5}
 *   @0x1f91bc stm r2, {r1, r3}
 *   @0x1f91c0 bx lr
 *
 * ══ §539/561 GV_PathPositionPrevious(CInstance*, int, RValue*)  0x1f91c4  size 48  12 条（0x1f91c4..0x1f91f4）
 * @func 0x1f91c4 0x1f91f4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f91c4 vldr s15, [r0, #304]
 *   @0x1f91c8 vcvt.f64.f32 d6, s15
 *   @0x1f91cc push {r4, r5}
 *   @0x1f91d0 mov r3, #0
 *   @0x1f91d4 mov r0, #1
 *   @0x1f91d8 str r3, [r2, #0xc]
 *   @0x1f91dc vmov r4, r5, d6
 *   @0x1f91e0 vmov r1, s12
 *   @0x1f91e4 mov r3, r5
 *   @0x1f91e8 pop {r4, r5}
 *   @0x1f91ec stm r2, {r1, r3}
 *   @0x1f91f0 bx lr
 *
 * ══ §540/561 GV_PathSpeed(CInstance*, int, RValue*)  0x1f91f4  size 48  12 条（0x1f91f4..0x1f9224）
 * @func 0x1f91f4 0x1f9224  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f91f4 vldr s15, [r0, #308]
 *   @0x1f91f8 vcvt.f64.f32 d6, s15
 *   @0x1f91fc push {r4, r5}
 *   @0x1f9200 mov r3, #0
 *   @0x1f9204 mov r0, #1
 *   @0x1f9208 str r3, [r2, #0xc]
 *   @0x1f920c vmov r4, r5, d6
 *   @0x1f9210 vmov r1, s12
 *   @0x1f9214 mov r3, r5
 *   @0x1f9218 pop {r4, r5}
 *   @0x1f921c stm r2, {r1, r3}
 *   @0x1f9220 bx lr
 *
 * ══ §541/561 GV_PathScale(CInstance*, int, RValue*)  0x1f9224  size 48  12 条（0x1f9224..0x1f9254）
 * @func 0x1f9224 0x1f9254  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9224 vldr s15, [r0, #312]
 *   @0x1f9228 vcvt.f64.f32 d6, s15
 *   @0x1f922c push {r4, r5}
 *   @0x1f9230 mov r3, #0
 *   @0x1f9234 mov r0, #1
 *   @0x1f9238 str r3, [r2, #0xc]
 *   @0x1f923c vmov r4, r5, d6
 *   @0x1f9240 vmov r1, s12
 *   @0x1f9244 mov r3, r5
 *   @0x1f9248 pop {r4, r5}
 *   @0x1f924c stm r2, {r1, r3}
 *   @0x1f9250 bx lr
 *
 * ══ §542/561 GV_PathOrientation(CInstance*, int, RValue*)  0x1f9254  size 48  12 条（0x1f9254..0x1f9284）
 * @func 0x1f9254 0x1f9284  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9254 vldr s15, [r0, #316]
 *   @0x1f9258 vcvt.f64.f32 d6, s15
 *   @0x1f925c push {r4, r5}
 *   @0x1f9260 mov r3, #0
 *   @0x1f9264 mov r0, #1
 *   @0x1f9268 str r3, [r2, #0xc]
 *   @0x1f926c vmov r4, r5, d6
 *   @0x1f9270 vmov r1, s12
 *   @0x1f9274 mov r3, r5
 *   @0x1f9278 pop {r4, r5}
 *   @0x1f927c stm r2, {r1, r3}
 *   @0x1f9280 bx lr
 *
 * ══ §543/561 GV_TimelinePosition(CInstance*, int, RValue*)  0x1f92ec  size 48  12 条（0x1f92ec..0x1f931c）
 * @func 0x1f92ec 0x1f931c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f92ec vldr s15, [r0, #340]
 *   @0x1f92f0 vcvt.f64.f32 d6, s15
 *   @0x1f92f4 push {r4, r5}
 *   @0x1f92f8 mov r3, #0
 *   @0x1f92fc mov r0, #1
 *   @0x1f9300 str r3, [r2, #0xc]
 *   @0x1f9304 vmov r4, r5, d6
 *   @0x1f9308 vmov r1, s12
 *   @0x1f930c mov r3, r5
 *   @0x1f9310 pop {r4, r5}
 *   @0x1f9314 stm r2, {r1, r3}
 *   @0x1f9318 bx lr
 *
 * ══ §544/561 GV_TimelineSpeed(CInstance*, int, RValue*)  0x1f931c  size 48  12 条（0x1f931c..0x1f934c）
 * @func 0x1f931c 0x1f934c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f931c vldr s15, [r0, #344]
 *   @0x1f9320 vcvt.f64.f32 d6, s15
 *   @0x1f9324 push {r4, r5}
 *   @0x1f9328 mov r3, #0
 *   @0x1f932c mov r0, #1
 *   @0x1f9330 str r3, [r2, #0xc]
 *   @0x1f9334 vmov r4, r5, d6
 *   @0x1f9338 vmov r1, s12
 *   @0x1f933c mov r3, r5
 *   @0x1f9340 pop {r4, r5}
 *   @0x1f9344 stm r2, {r1, r3}
 *   @0x1f9348 bx lr
 *
 * ══ §545/561 SV_Argument1(CInstance*, int, RValue*)  0x1fa4a8  size 48  12 条（0x1fa4a8..0x1fa4d8）
 * @func 0x1fa4a8 0x1fa4d8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa4a8 push {r3, lr}
 *   @0x1fa4ac mov r0, r1
 *   @0x1fa4b0 ldr r3, [pc, #0x1c]
 *   @0x1fa4b4 mov r1, r2
 *   @0x1fa4b8 mov r2, r0
 *   @0x1fa4bc ldr r3, [pc, r3]
 *   @0x1fa4c0 ldr r0, [r3]
 *   @0x1fa4c4 add r0, r0, #16
 *   @0x1fa4c8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa4cc mov r0, #1
 *   @0x1fa4d0 pop {r3, pc}
 *   @0x1fa4d4 andseq r3, pc, r4, asr r8
 *
 * ══ §546/561 SV_Argument2(CInstance*, int, RValue*)  0x1fa4d8  size 48  12 条（0x1fa4d8..0x1fa508）
 * @func 0x1fa4d8 0x1fa508  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa4d8 push {r3, lr}
 *   @0x1fa4dc mov r0, r1
 *   @0x1fa4e0 ldr r3, [pc, #0x1c]
 *   @0x1fa4e4 mov r1, r2
 *   @0x1fa4e8 mov r2, r0
 *   @0x1fa4ec ldr r3, [pc, r3]
 *   @0x1fa4f0 ldr r0, [r3]
 *   @0x1fa4f4 add r0, r0, #32
 *   @0x1fa4f8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa4fc mov r0, #1
 *   @0x1fa500 pop {r3, pc}
 *   @0x1fa504 andseq r3, pc, r4, lsr #16
 *
 * ══ §547/561 SV_Argument3(CInstance*, int, RValue*)  0x1fa508  size 48  12 条（0x1fa508..0x1fa538）
 * @func 0x1fa508 0x1fa538  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa508 push {r3, lr}
 *   @0x1fa50c mov r0, r1
 *   @0x1fa510 ldr r3, [pc, #0x1c]
 *   @0x1fa514 mov r1, r2
 *   @0x1fa518 mov r2, r0
 *   @0x1fa51c ldr r3, [pc, r3]
 *   @0x1fa520 ldr r0, [r3]
 *   @0x1fa524 add r0, r0, #48
 *   @0x1fa528 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa52c mov r0, #1
 *   @0x1fa530 pop {r3, pc}
 *   @0x1fa534 ldrsheq r3, [pc], -r4
 *
 * ══ §548/561 SV_Argument4(CInstance*, int, RValue*)  0x1fa538  size 48  12 条（0x1fa538..0x1fa568）
 * @func 0x1fa538 0x1fa568  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa538 push {r3, lr}
 *   @0x1fa53c mov r0, r1
 *   @0x1fa540 ldr r3, [pc, #0x1c]
 *   @0x1fa544 mov r1, r2
 *   @0x1fa548 mov r2, r0
 *   @0x1fa54c ldr r3, [pc, r3]
 *   @0x1fa550 ldr r0, [r3]
 *   @0x1fa554 add r0, r0, #64
 *   @0x1fa558 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa55c mov r0, #1
 *   @0x1fa560 pop {r3, pc}
 *   @0x1fa564 andseq r3, pc, r4, asr #15
 *
 * ══ §549/561 SV_Argument5(CInstance*, int, RValue*)  0x1fa568  size 48  12 条（0x1fa568..0x1fa598）
 * @func 0x1fa568 0x1fa598  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa568 push {r3, lr}
 *   @0x1fa56c mov r0, r1
 *   @0x1fa570 ldr r3, [pc, #0x1c]
 *   @0x1fa574 mov r1, r2
 *   @0x1fa578 mov r2, r0
 *   @0x1fa57c ldr r3, [pc, r3]
 *   @0x1fa580 ldr r0, [r3]
 *   @0x1fa584 add r0, r0, #80
 *   @0x1fa588 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa58c mov r0, #1
 *   @0x1fa590 pop {r3, pc}
 *   @0x1fa594 mulseq pc, r4, r7
 *
 * ══ §550/561 SV_Argument6(CInstance*, int, RValue*)  0x1fa598  size 48  12 条（0x1fa598..0x1fa5c8）
 * @func 0x1fa598 0x1fa5c8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa598 push {r3, lr}
 *   @0x1fa59c mov r0, r1
 *   @0x1fa5a0 ldr r3, [pc, #0x1c]
 *   @0x1fa5a4 mov r1, r2
 *   @0x1fa5a8 mov r2, r0
 *   @0x1fa5ac ldr r3, [pc, r3]
 *   @0x1fa5b0 ldr r0, [r3]
 *   @0x1fa5b4 add r0, r0, #96
 *   @0x1fa5b8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa5bc mov r0, #1
 *   @0x1fa5c0 pop {r3, pc}
 *   @0x1fa5c4 andseq r3, pc, r4, ror #14
 *
 * ══ §551/561 SV_Argument7(CInstance*, int, RValue*)  0x1fa5c8  size 48  12 条（0x1fa5c8..0x1fa5f8）
 * @func 0x1fa5c8 0x1fa5f8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa5c8 push {r3, lr}
 *   @0x1fa5cc mov r0, r1
 *   @0x1fa5d0 ldr r3, [pc, #0x1c]
 *   @0x1fa5d4 mov r1, r2
 *   @0x1fa5d8 mov r2, r0
 *   @0x1fa5dc ldr r3, [pc, r3]
 *   @0x1fa5e0 ldr r0, [r3]
 *   @0x1fa5e4 add r0, r0, #112
 *   @0x1fa5e8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa5ec mov r0, #1
 *   @0x1fa5f0 pop {r3, pc}
 *   @0x1fa5f4 andseq r3, pc, r4, lsr r7
 *
 * ══ §552/561 SV_Argument8(CInstance*, int, RValue*)  0x1fa5f8  size 48  12 条（0x1fa5f8..0x1fa628）
 * @func 0x1fa5f8 0x1fa628  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa5f8 push {r3, lr}
 *   @0x1fa5fc mov r0, r1
 *   @0x1fa600 ldr r3, [pc, #0x1c]
 *   @0x1fa604 mov r1, r2
 *   @0x1fa608 mov r2, r0
 *   @0x1fa60c ldr r3, [pc, r3]
 *   @0x1fa610 ldr r0, [r3]
 *   @0x1fa614 add r0, r0, #128
 *   @0x1fa618 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa61c mov r0, #1
 *   @0x1fa620 pop {r3, pc}
 *   @0x1fa624 andseq r3, pc, r4, lsl #14
 *
 * ══ §553/561 SV_Argument9(CInstance*, int, RValue*)  0x1fa628  size 48  12 条（0x1fa628..0x1fa658）
 * @func 0x1fa628 0x1fa658  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa628 push {r3, lr}
 *   @0x1fa62c mov r0, r1
 *   @0x1fa630 ldr r3, [pc, #0x1c]
 *   @0x1fa634 mov r1, r2
 *   @0x1fa638 mov r2, r0
 *   @0x1fa63c ldr r3, [pc, r3]
 *   @0x1fa640 ldr r0, [r3]
 *   @0x1fa644 add r0, r0, #144
 *   @0x1fa648 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa64c mov r0, #1
 *   @0x1fa650 pop {r3, pc}
 *   @0x1fa654 ldrsbeq r3, [pc], -r4
 *
 * ══ §554/561 SV_Argument10(CInstance*, int, RValue*)  0x1fa658  size 48  12 条（0x1fa658..0x1fa688）
 * @func 0x1fa658 0x1fa688  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa658 push {r3, lr}
 *   @0x1fa65c mov r0, r1
 *   @0x1fa660 ldr r3, [pc, #0x1c]
 *   @0x1fa664 mov r1, r2
 *   @0x1fa668 mov r2, r0
 *   @0x1fa66c ldr r3, [pc, r3]
 *   @0x1fa670 ldr r0, [r3]
 *   @0x1fa674 add r0, r0, #160
 *   @0x1fa678 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa67c mov r0, #1
 *   @0x1fa680 pop {r3, pc}
 *   @0x1fa684 andseq r3, pc, r4, lsr #13
 *
 * ══ §555/561 SV_Argument11(CInstance*, int, RValue*)  0x1fa688  size 48  12 条（0x1fa688..0x1fa6b8）
 * @func 0x1fa688 0x1fa6b8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa688 push {r3, lr}
 *   @0x1fa68c mov r0, r1
 *   @0x1fa690 ldr r3, [pc, #0x1c]
 *   @0x1fa694 mov r1, r2
 *   @0x1fa698 mov r2, r0
 *   @0x1fa69c ldr r3, [pc, r3]
 *   @0x1fa6a0 ldr r0, [r3]
 *   @0x1fa6a4 add r0, r0, #176
 *   @0x1fa6a8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa6ac mov r0, #1
 *   @0x1fa6b0 pop {r3, pc}
 *   @0x1fa6b4 andseq r3, pc, r4, ror r6
 *
 * ══ §556/561 SV_Argument12(CInstance*, int, RValue*)  0x1fa6b8  size 48  12 条（0x1fa6b8..0x1fa6e8）
 * @func 0x1fa6b8 0x1fa6e8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa6b8 push {r3, lr}
 *   @0x1fa6bc mov r0, r1
 *   @0x1fa6c0 ldr r3, [pc, #0x1c]
 *   @0x1fa6c4 mov r1, r2
 *   @0x1fa6c8 mov r2, r0
 *   @0x1fa6cc ldr r3, [pc, r3]
 *   @0x1fa6d0 ldr r0, [r3]
 *   @0x1fa6d4 add r0, r0, #192
 *   @0x1fa6d8 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa6dc mov r0, #1
 *   @0x1fa6e0 pop {r3, pc}
 *   @0x1fa6e4 andseq r3, pc, r4, asr #12
 *
 * ══ §557/561 SV_Argument13(CInstance*, int, RValue*)  0x1fa6e8  size 48  12 条（0x1fa6e8..0x1fa718）
 * @func 0x1fa6e8 0x1fa718  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa6e8 push {r3, lr}
 *   @0x1fa6ec mov r0, r1
 *   @0x1fa6f0 ldr r3, [pc, #0x1c]
 *   @0x1fa6f4 mov r1, r2
 *   @0x1fa6f8 mov r2, r0
 *   @0x1fa6fc ldr r3, [pc, r3]
 *   @0x1fa700 ldr r0, [r3]
 *   @0x1fa704 add r0, r0, #208
 *   @0x1fa708 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa70c mov r0, #1
 *   @0x1fa710 pop {r3, pc}
 *   @0x1fa714 andseq r3, pc, r4, lsl r6
 *
 * ══ §558/561 SV_Argument14(CInstance*, int, RValue*)  0x1fa718  size 48  12 条（0x1fa718..0x1fa748）
 * @func 0x1fa718 0x1fa748  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa718 push {r3, lr}
 *   @0x1fa71c mov r0, r1
 *   @0x1fa720 ldr r3, [pc, #0x1c]
 *   @0x1fa724 mov r1, r2
 *   @0x1fa728 mov r2, r0
 *   @0x1fa72c ldr r3, [pc, r3]
 *   @0x1fa730 ldr r0, [r3]
 *   @0x1fa734 add r0, r0, #224
 *   @0x1fa738 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa73c mov r0, #1
 *   @0x1fa740 pop {r3, pc}
 *   @0x1fa744 andseq r3, pc, r4, ror #11
 *
 * ══ §559/561 SV_Argument15(CInstance*, int, RValue*)  0x1fa748  size 48  12 条（0x1fa748..0x1fa778）
 * @func 0x1fa748 0x1fa778  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa748 push {r3, lr}
 *   @0x1fa74c mov r0, r1
 *   @0x1fa750 ldr r3, [pc, #0x1c]
 *   @0x1fa754 mov r1, r2
 *   @0x1fa758 mov r2, r0
 *   @0x1fa75c ldr r3, [pc, r3]
 *   @0x1fa760 ldr r0, [r3]
 *   @0x1fa764 add r0, r0, #240
 *   @0x1fa768 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1fa76c mov r0, #1
 *   @0x1fa770 pop {r3, pc}
 *   @0x1fa774 ldrheq r3, [pc], -r4
 *
 * ══ §560/561 SV_KeyboardString(CInstance*, int, RValue*)  0x1fa840  size 48  12 条（0x1fa840..0x1fa870）
 * @func 0x1fa840 0x1fa870  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_String_Set(char const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fa840 push {r3, lr}
 *   @0x1fa844 ldr r3, [r2, #0xc]
 *   @0x1fa848 bic r3, r3, #-16777216
 *   @0x1fa84c cmp r3, #1
 *   @0x1fa850 movne r0, #0
 *   @0x1fa854 bne 0x1fa864 <_Z17SV_KeyboardStringP9CInstanceiP6RValue+0x24>
 *   @0x1fa858 ldr r0, [r2]
 *   @0x1fa85c cmp r0, #0
 *   @0x1fa860 ldrne r0, [r0]
 *   @0x1fa864 bl 0x18bdb4 <_Z13IO_String_SetPKc>
 *   @0x1fa868 mov r0, #1
 *   @0x1fa86c pop {r3, pc}
 *
 * ══ §561/561 VMWriteBuffer::AddVal(bool)  0xec73c  size 12  3 条（0xec73c..0xec748）
 * @func 0xec73c 0xec748  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec73c mov r2, r1
 *   @0xec740 mov r1, #1
 *   @0xec744 b 0xec674 <_ZN13VMWriteBuffer3AddEiz>
 */
